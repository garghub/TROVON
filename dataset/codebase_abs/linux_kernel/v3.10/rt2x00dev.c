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
if ( F_3 ( V_16 , & V_2 -> V_17 ) )
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_10 , & V_2 -> V_11 ) )
return;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
if ( F_3 ( V_16 , & V_2 -> V_17 ) )
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 , true ) ;
V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_18 ) ;
V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_19 ) ;
F_6 ( V_2 , false ) ;
F_5 ( V_2 , false ) ;
}
static void F_21 ( void * V_20 , T_2 * V_21 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_20 ;
struct V_22 * V_23 = F_22 ( V_4 ) ;
if ( ! F_3 ( V_10 , & V_2 -> V_11 ) )
return;
if ( F_14 ( V_24 , & V_23 -> V_25 ) )
F_23 ( V_2 , V_4 ) ;
}
static void F_24 ( struct V_26 * V_27 )
{
struct V_1 * V_2 =
F_25 ( V_27 , struct V_1 , V_28 ) ;
F_26 ( V_2 -> V_29 ,
V_30 ,
F_21 ,
V_2 ) ;
}
static void F_27 ( struct V_26 * V_27 )
{
struct V_1 * V_2 =
F_25 ( V_27 , struct V_1 , V_31 . V_27 ) ;
if ( ! F_3 ( V_32 , & V_2 -> V_11 ) )
return;
if ( V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_33 ) )
F_28 ( V_2 , L_1 ) ;
F_29 ( V_34 , & V_2 -> V_11 ) ;
}
static void F_30 ( void * V_20 , T_2 * V_21 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_20 ;
struct V_35 * V_36 ;
if ( V_4 -> type != V_37 )
return;
V_36 = F_31 ( V_2 -> V_29 , V_4 ) ;
while ( V_36 ) {
F_32 ( V_2 -> V_29 , NULL , V_36 ) ;
V_36 = F_31 ( V_2 -> V_29 , V_4 ) ;
}
}
static void F_33 ( void * V_20 , T_2 * V_21 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_20 ;
if ( V_4 -> type != V_37 &&
V_4 -> type != V_38 &&
V_4 -> type != V_39 &&
V_4 -> type != V_40 )
return;
F_34 ( F_35 ( V_2 ) ) ;
F_36 ( V_2 , V_4 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_10 , & V_2 -> V_11 ) )
return;
F_38 (
V_2 -> V_29 , V_30 ,
F_30 , V_2 ) ;
if ( F_3 ( V_41 , & V_2 -> V_17 ) )
return;
F_38 (
V_2 -> V_29 , V_30 ,
F_33 , V_2 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_10 , & V_2 -> V_11 ) )
return;
F_38 (
V_2 -> V_29 , V_30 ,
F_33 , V_2 ) ;
}
void F_40 ( struct V_42 * V_43 )
{
F_7 ( V_44 , & V_43 -> V_11 ) ;
F_41 ( V_43 , V_45 ) ;
}
void F_42 ( struct V_42 * V_43 )
{
F_7 ( V_46 , & V_43 -> V_11 ) ;
F_29 ( V_44 , & V_43 -> V_11 ) ;
F_41 ( V_43 , V_47 ) ;
}
static inline int F_43 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_48 -> V_2 ;
struct V_49 * V_50 = ( void * ) V_43 -> V_36 -> V_20 ;
struct V_51 * V_52 ;
int V_53 ;
if ( F_44 ( ! F_45 ( V_50 -> V_54 ) ) )
return 0 ;
V_53 = 0 ;
F_46 () ;
F_47 (bar_entry, &rt2x00dev->bar_list, list) {
if ( V_52 -> V_43 != V_43 )
continue;
F_48 ( & V_2 -> V_55 ) ;
V_53 = V_52 -> V_56 ;
F_49 ( & V_52 -> V_57 ) ;
F_50 ( & V_2 -> V_55 ) ;
F_51 ( V_52 , V_58 ) ;
break;
}
F_52 () ;
return V_53 ;
}
void F_53 ( struct V_42 * V_43 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = V_43 -> V_48 -> V_2 ;
struct V_61 * V_62 = F_54 ( V_43 -> V_36 ) ;
struct V_63 * V_64 = F_55 ( V_43 -> V_36 ) ;
unsigned int V_65 , V_66 ;
T_2 V_67 , V_68 , V_69 ;
T_2 V_70 = V_64 -> V_11 ;
bool V_71 ;
F_56 ( V_43 ) ;
F_57 ( V_43 -> V_36 , V_2 -> V_7 -> V_72 ) ;
V_64 -> V_11 &= ~ V_73 ;
V_65 = F_58 ( V_43 -> V_36 ) ;
if ( F_3 ( V_74 , & V_2 -> V_17 ) )
F_59 ( V_43 -> V_36 , V_65 ) ;
if ( F_3 ( V_75 , & V_2 -> V_17 ) )
F_60 ( V_43 -> V_36 , V_65 ) ;
F_61 ( V_2 , V_76 , V_43 -> V_36 ) ;
V_71 =
F_43 ( V_43 ) ||
F_3 ( V_77 , & V_60 -> V_11 ) ||
F_3 ( V_78 , & V_60 -> V_11 ) ;
V_2 -> V_79 . V_80 . V_81 += V_71 ;
V_2 -> V_79 . V_80 . V_82 += ! V_71 ;
V_67 = V_64 -> V_83 ;
V_68 = V_64 -> V_84 ;
V_69 = F_3 ( V_85 , & V_60 -> V_11 ) ?
( V_60 -> V_86 + 1 ) : 1 ;
memset ( & V_62 -> V_9 , 0 , sizeof( V_62 -> V_9 ) ) ;
V_62 -> V_9 . V_87 = 0 ;
for ( V_66 = 0 ; V_66 < V_69 && V_66 < V_88 ; V_66 ++ ) {
V_62 -> V_9 . V_89 [ V_66 ] . V_90 = V_67 - V_66 ;
V_62 -> V_9 . V_89 [ V_66 ] . V_11 = V_68 ;
if ( V_67 - V_66 == 0 ) {
V_62 -> V_9 . V_89 [ V_66 ] . V_91 = V_69 - V_66 ;
V_66 ++ ;
break;
}
V_62 -> V_9 . V_89 [ V_66 ] . V_91 = 1 ;
}
if ( V_66 < ( V_88 - 1 ) )
V_62 -> V_9 . V_89 [ V_66 ] . V_90 = - 1 ;
if ( ! ( V_62 -> V_11 & V_92 ) ) {
if ( V_71 )
V_62 -> V_11 |= V_93 ;
else
V_2 -> V_94 . V_95 ++ ;
}
if ( F_3 ( V_96 , & V_60 -> V_11 ) ||
V_62 -> V_11 & V_97 ) {
V_62 -> V_11 |= V_98 ;
V_62 -> V_9 . V_99 = 1 ;
V_62 -> V_9 . V_100 = V_71 ? 1 : 0 ;
if ( ! V_71 )
V_62 -> V_11 |= V_101 ;
}
if ( V_68 & V_102 ) {
if ( V_71 )
V_2 -> V_94 . V_103 ++ ;
else
V_2 -> V_94 . V_104 ++ ;
}
if ( ! ( V_70 & V_105 ) ) {
if ( F_3 ( V_106 , & V_2 -> V_17 ) )
F_62 ( V_2 -> V_29 , V_43 -> V_36 ) ;
else
F_63 ( V_2 -> V_29 , V_43 -> V_36 ) ;
} else
F_64 ( V_43 -> V_36 ) ;
V_43 -> V_36 = NULL ;
V_43 -> V_11 = 0 ;
V_2 -> V_7 -> V_12 -> V_107 ( V_43 ) ;
F_41 ( V_43 , V_108 ) ;
F_48 ( & V_43 -> V_48 -> V_109 ) ;
if ( ! F_65 ( V_43 -> V_48 ) )
F_66 ( V_43 -> V_48 ) ;
F_50 ( & V_43 -> V_48 -> V_109 ) ;
}
void F_67 ( struct V_42 * V_43 , T_1 V_9 )
{
struct V_59 V_60 ;
V_60 . V_11 = 0 ;
F_68 ( V_9 , & V_60 . V_11 ) ;
V_60 . V_86 = 0 ;
F_53 ( V_43 , & V_60 ) ;
}
static T_2 * F_69 ( T_2 * V_20 , unsigned int V_110 , T_2 V_111 )
{
struct V_112 * V_113 = ( void * ) V_20 ;
T_2 * V_114 , * V_115 ;
V_114 = ( T_2 * ) V_113 -> V_116 . V_117 . V_118 ;
V_115 = V_20 + V_110 ;
while ( V_114 < V_115 ) {
if ( V_114 + 2 + V_114 [ 1 ] > V_115 )
return NULL ;
if ( V_114 [ 0 ] == V_111 )
return V_114 ;
V_114 += 2 + V_114 [ 1 ] ;
}
return NULL ;
}
static void F_70 ( struct V_26 * V_27 )
{
struct V_1 * V_2 =
F_25 ( V_27 , struct V_1 , V_119 ) ;
if ( ! F_3 ( V_32 , & V_2 -> V_11 ) )
return;
if ( ! F_3 ( V_34 , & V_2 -> V_11 ) )
F_71 ( V_2 , & V_2 -> V_29 -> V_120 ,
V_121 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_122 * V_123 )
{
struct V_51 * V_43 ;
struct V_49 * V_124 = ( void * ) V_36 -> V_20 ;
if ( F_44 ( ! F_73 ( V_124 -> V_54 ) ) )
return;
if ( V_123 -> V_125 < sizeof( * V_124 ) + V_126 )
return;
F_46 () ;
F_47 (entry, &rt2x00dev->bar_list, list) {
if ( V_124 -> V_127 != V_43 -> V_127 )
continue;
#define F_74 ( T_3 , T_4 ) ( \
((a) & cpu_to_le16(IEEE80211_BAR_CTRL_TID_INFO_MASK)) == \
((b) & cpu_to_le16(IEEE80211_BAR_CTRL_TID_INFO_MASK))) \
if (!TID_CHECK(ba->control, entry->control))
continue;
#undef F_74
if ( F_75 ( V_124 -> V_128 , V_43 -> V_129 ) )
continue;
if ( F_75 ( V_124 -> V_129 , V_43 -> V_128 ) )
continue;
F_48 ( & V_2 -> V_55 ) ;
V_43 -> V_56 = 1 ;
F_50 ( & V_2 -> V_55 ) ;
break;
}
F_52 () ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_122 * V_123 )
{
struct V_130 * V_131 = ( void * ) V_36 -> V_20 ;
struct V_132 * V_133 ;
T_2 * V_134 ;
T_2 V_135 ;
bool V_136 ;
if ( F_44 ( ! F_77 ( V_131 -> V_54 ) ||
! ( V_2 -> V_29 -> V_120 . V_11 & V_137 ) ) )
return;
if ( V_36 -> V_110 <= 40 + V_126 )
return;
if ( ! ( V_123 -> V_138 & V_139 ) ||
! V_2 -> V_140 )
return;
V_2 -> V_141 = V_142 ;
V_134 = F_69 ( V_36 -> V_20 , V_36 -> V_110 - V_126 , V_143 ) ;
if ( ! V_134 )
return;
if ( V_134 [ 1 ] < sizeof( * V_133 ) )
return;
V_135 = V_134 [ 1 ] ;
V_133 = (struct V_132 * ) & V_134 [ 2 ] ;
V_136 = F_78 ( V_133 , V_135 , V_2 -> V_140 ) ;
V_136 |= ( V_133 -> V_144 & 0x01 ) ;
if ( ! V_136 && ! F_3 ( V_34 , & V_2 -> V_11 ) )
F_79 ( V_2 -> V_145 , & V_2 -> V_119 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_122 * V_123 )
{
struct V_146 * V_147 ;
const struct V_148 * V_149 ;
unsigned int V_66 ;
int signal = V_123 -> signal ;
int type = ( V_123 -> V_138 & V_150 ) ;
switch ( V_123 -> V_151 ) {
case V_152 :
case V_153 :
if ( V_123 -> V_138 & V_154 )
signal = F_81 ( V_123 -> V_151 , signal ) ;
V_147 = & V_2 -> V_155 [ V_2 -> V_156 ] ;
for ( V_66 = 0 ; V_66 < V_147 -> V_157 ; V_66 ++ ) {
V_149 = F_82 ( V_147 -> V_158 [ V_66 ] . V_159 ) ;
if ( ( ( type == V_160 ) &&
( V_149 -> V_161 == signal ) ) ||
( ( type == V_162 ) &&
( V_149 -> V_163 == signal ) ) ||
( ( type == V_154 ) &&
( V_149 -> V_164 == signal ) ) ) {
return V_66 ;
}
}
break;
case V_165 :
case V_166 :
if ( signal >= 0 && signal <= 76 )
return signal ;
break;
default:
break;
}
F_83 ( V_2 , L_2 ,
V_123 -> V_151 , signal , type ) ;
return 0 ;
}
void F_84 ( struct V_42 * V_43 , T_5 V_167 )
{
struct V_1 * V_2 = V_43 -> V_48 -> V_2 ;
struct V_122 V_123 ;
struct V_35 * V_36 ;
struct V_168 * V_169 ;
unsigned int V_65 ;
int V_67 ;
if ( ! F_3 ( V_32 , & V_2 -> V_11 ) ||
! F_3 ( V_10 , & V_2 -> V_11 ) )
goto V_170;
if ( F_3 ( V_171 , & V_43 -> V_11 ) )
goto V_170;
V_36 = F_85 ( V_43 , V_167 ) ;
if ( ! V_36 )
goto V_170;
F_56 ( V_43 ) ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_2 -> V_7 -> V_12 -> V_172 ( V_43 , & V_123 ) ;
if ( F_86 ( V_123 . V_125 == 0 ||
V_123 . V_125 > V_43 -> V_48 -> V_173 ) ) {
F_28 ( V_2 , L_3 ,
V_123 . V_125 , V_43 -> V_48 -> V_173 ) ;
F_87 ( V_43 -> V_36 ) ;
goto V_174;
}
V_65 = F_58 ( V_43 -> V_36 ) ;
if ( ( V_123 . V_138 & V_175 ) &&
( V_123 . V_11 & V_176 ) )
F_88 ( V_43 -> V_36 , V_65 ,
& V_123 ) ;
else if ( V_65 &&
( V_123 . V_125 > V_65 ) &&
( V_123 . V_138 & V_177 ) )
F_59 ( V_43 -> V_36 , V_65 ) ;
F_89 ( V_43 -> V_36 , V_123 . V_125 ) ;
V_67 = F_80 ( V_2 , & V_123 ) ;
if ( V_123 . V_151 == V_165 ||
V_123 . V_151 == V_166 )
V_123 . V_11 |= V_178 ;
F_76 ( V_2 , V_43 -> V_36 , & V_123 ) ;
F_72 ( V_2 , V_43 -> V_36 , & V_123 ) ;
F_90 ( V_2 , V_43 -> V_36 , & V_123 ) ;
F_91 ( V_2 , & V_123 ) ;
F_61 ( V_2 , V_179 , V_43 -> V_36 ) ;
V_169 = F_92 ( V_43 -> V_36 ) ;
memset ( V_169 , 0 , sizeof( * V_169 ) ) ;
V_169 -> V_180 = V_123 . V_181 ;
V_169 -> V_182 = V_2 -> V_156 ;
V_169 -> V_183 = V_2 -> V_184 ;
V_169 -> V_67 = V_67 ;
V_169 -> signal = V_123 . V_185 ;
V_169 -> V_186 = V_123 . V_11 ;
V_169 -> V_187 = V_2 -> V_79 . V_188 . V_189 . V_190 ;
F_93 ( V_2 -> V_29 , V_43 -> V_36 ) ;
V_174:
V_43 -> V_36 = V_36 ;
V_170:
V_43 -> V_11 = 0 ;
F_41 ( V_43 , V_108 ) ;
if ( F_3 ( V_32 , & V_2 -> V_11 ) &&
F_3 ( V_10 , & V_2 -> V_11 ) )
V_2 -> V_7 -> V_12 -> V_107 ( V_43 ) ;
}
static void F_94 ( struct V_191 * V_43 ,
const int V_192 , const int V_193 ,
const int V_194 )
{
V_43 -> V_182 = V_192 <= 14 ? V_195 : V_196 ;
V_43 -> V_197 = F_95 ( V_192 ,
V_43 -> V_182 ) ;
V_43 -> V_159 = V_194 ;
V_43 -> V_198 = V_193 ;
V_43 -> V_199 = 0xff ;
}
static void F_96 ( struct V_200 * V_43 ,
const T_6 V_201 , const struct V_148 * V_149 )
{
V_43 -> V_11 = 0 ;
V_43 -> V_163 = V_149 -> V_163 ;
V_43 -> V_159 = V_201 ;
V_43 -> V_202 = V_201 ;
if ( V_149 -> V_11 & V_203 )
V_43 -> V_11 |= V_204 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_205 * V_206 )
{
struct V_207 * V_29 = V_2 -> V_29 ;
struct V_191 * V_208 ;
struct V_200 * V_89 ;
unsigned int V_209 ;
unsigned int V_66 ;
V_209 = 0 ;
if ( V_206 -> V_210 & V_211 )
V_209 += 4 ;
if ( V_206 -> V_210 & V_212 )
V_209 += 8 ;
V_208 = F_98 ( V_206 -> V_213 , sizeof( * V_208 ) , V_214 ) ;
if ( ! V_208 )
return - V_215 ;
V_89 = F_98 ( V_209 , sizeof( * V_89 ) , V_214 ) ;
if ( ! V_89 )
goto V_216;
for ( V_66 = 0 ; V_66 < V_209 ; V_66 ++ )
F_96 ( & V_89 [ V_66 ] , V_66 , F_82 ( V_66 ) ) ;
for ( V_66 = 0 ; V_66 < V_206 -> V_213 ; V_66 ++ ) {
F_94 ( & V_208 [ V_66 ] ,
V_206 -> V_208 [ V_66 ] . V_192 ,
V_206 -> V_217 [ V_66 ] . V_198 , V_66 ) ;
}
if ( V_206 -> V_218 & V_219 ) {
V_2 -> V_155 [ V_195 ] . V_220 = 14 ;
V_2 -> V_155 [ V_195 ] . V_157 = V_209 ;
V_2 -> V_155 [ V_195 ] . V_208 = V_208 ;
V_2 -> V_155 [ V_195 ] . V_158 = V_89 ;
V_29 -> V_221 -> V_155 [ V_195 ] =
& V_2 -> V_155 [ V_195 ] ;
memcpy ( & V_2 -> V_155 [ V_195 ] . V_222 ,
& V_206 -> V_223 , sizeof( V_206 -> V_223 ) ) ;
}
if ( V_206 -> V_218 & V_224 ) {
V_2 -> V_155 [ V_196 ] . V_220 =
V_206 -> V_213 - 14 ;
V_2 -> V_155 [ V_196 ] . V_157 =
V_209 - 4 ;
V_2 -> V_155 [ V_196 ] . V_208 = & V_208 [ 14 ] ;
V_2 -> V_155 [ V_196 ] . V_158 = & V_89 [ 4 ] ;
V_29 -> V_221 -> V_155 [ V_196 ] =
& V_2 -> V_155 [ V_196 ] ;
memcpy ( & V_2 -> V_155 [ V_196 ] . V_222 ,
& V_206 -> V_223 , sizeof( V_206 -> V_223 ) ) ;
}
return 0 ;
V_216:
F_99 ( V_208 ) ;
F_28 ( V_2 , L_4 ) ;
return - V_215 ;
}
static void F_100 ( struct V_1 * V_2 )
{
if ( F_3 ( V_225 , & V_2 -> V_11 ) )
F_101 ( V_2 -> V_29 ) ;
if ( F_44 ( V_2 -> V_29 -> V_221 -> V_155 [ V_195 ] ) ) {
F_99 ( V_2 -> V_29 -> V_221 -> V_155 [ V_195 ] -> V_208 ) ;
F_99 ( V_2 -> V_29 -> V_221 -> V_155 [ V_195 ] -> V_158 ) ;
V_2 -> V_29 -> V_221 -> V_155 [ V_195 ] = NULL ;
V_2 -> V_29 -> V_221 -> V_155 [ V_196 ] = NULL ;
}
F_99 ( V_2 -> V_206 . V_217 ) ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_205 * V_206 = & V_2 -> V_206 ;
int V_9 ;
if ( F_3 ( V_225 , & V_2 -> V_11 ) )
return 0 ;
V_9 = F_97 ( V_2 , V_206 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_29 -> V_226 = V_2 -> V_7 -> V_227 ;
V_2 -> V_29 -> V_72 =
F_103 (unsigned int, IEEE80211_TX_STATUS_HEADROOM,
rt2x00dev->ops->extra_tx_headroom) ;
if ( F_3 ( V_74 , & V_2 -> V_17 ) )
V_2 -> V_29 -> V_72 += V_228 ;
else if ( F_3 ( V_229 , & V_2 -> V_17 ) )
V_2 -> V_29 -> V_72 += V_230 ;
V_2 -> V_29 -> V_231 = sizeof( struct V_232 ) ;
if ( F_3 ( V_233 , & V_2 -> V_17 ) ) {
int V_234 =
F_104 ( V_2 -> V_7 -> V_227 *
V_2 -> V_7 -> V_235 -> V_236 *
sizeof( T_1 ) ) ;
V_9 = F_105 ( & V_2 -> V_237 , V_234 ,
V_214 ) ;
if ( V_9 )
return V_9 ;
}
#define F_106 ( T_7 ) \
if (rt2x00dev->ops->lib->taskletname) { \
tasklet_init(&rt2x00dev->taskletname, \
rt2x00dev->ops->lib->taskletname, \
(unsigned long)rt2x00dev); \
}
F_106 ( V_238 ) ;
F_106 ( V_239 ) ;
F_106 ( V_240 ) ;
F_106 ( V_241 ) ;
F_106 ( V_242 ) ;
#undef F_106
V_9 = F_107 ( V_2 -> V_29 ) ;
if ( V_9 )
return V_9 ;
F_7 ( V_225 , & V_2 -> V_11 ) ;
return 0 ;
}
static void F_108 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_243 , & V_2 -> V_11 ) )
return;
F_109 ( V_2 ) ;
V_2 -> V_7 -> V_12 -> V_244 ( V_2 ) ;
F_110 ( V_2 ) ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_9 ;
if ( F_3 ( V_243 , & V_2 -> V_11 ) )
return 0 ;
V_9 = F_112 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_9 = V_2 -> V_7 -> V_12 -> V_245 ( V_2 ) ;
if ( V_9 ) {
F_110 ( V_2 ) ;
return V_9 ;
}
F_7 ( V_243 , & V_2 -> V_11 ) ;
return 0 ;
}
int F_113 ( struct V_1 * V_2 )
{
int V_246 ;
if ( F_3 ( V_247 , & V_2 -> V_11 ) )
return 0 ;
V_246 = F_114 ( V_2 ) ;
if ( V_246 )
return V_246 ;
V_246 = F_111 ( V_2 ) ;
if ( V_246 )
return V_246 ;
V_2 -> V_248 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_249 = 0 ;
V_246 = F_2 ( V_2 ) ;
if ( V_246 )
return V_246 ;
F_7 ( V_247 , & V_2 -> V_11 ) ;
return 0 ;
}
void F_115 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_247 , & V_2 -> V_11 ) )
return;
F_13 ( V_2 ) ;
V_2 -> V_248 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_249 = 0 ;
}
static inline void F_116 ( struct V_1 * V_2 )
{
struct V_250 * V_251 ;
struct V_252 * V_253 ;
if ( V_2 -> V_7 -> V_8 < 2 )
return;
V_251 = & V_2 -> V_254 ;
V_251 -> V_255 = V_2 -> V_7 -> V_8 ;
V_251 -> V_256 = F_117 ( V_37 ) ;
#ifdef F_118
V_251 -> V_256 |= F_117 ( V_39 ) ;
#endif
V_253 = & V_2 -> V_257 [ V_258 ] ;
V_253 -> V_259 = V_251 ;
V_253 -> V_260 = 1 ;
V_253 -> V_261 = V_251 -> V_255 ;
V_253 -> V_262 = 1 ;
V_2 -> V_29 -> V_221 -> V_263 = V_2 -> V_257 ;
V_2 -> V_29 -> V_221 -> V_264 = 1 ;
}
int F_119 ( struct V_1 * V_2 )
{
int V_246 = - V_215 ;
F_116 ( V_2 ) ;
if ( V_2 -> V_7 -> V_265 > 0 ) {
V_2 -> V_266 = F_120 ( V_2 -> V_7 -> V_265 ,
V_214 ) ;
if ( ! V_2 -> V_266 ) {
V_246 = - V_215 ;
goto exit;
}
}
F_121 ( & V_2 -> V_267 ) ;
F_122 ( & V_2 -> V_268 ) ;
F_123 ( & V_2 -> V_269 ) ;
F_121 ( & V_2 -> V_55 ) ;
F_7 ( V_32 , & V_2 -> V_11 ) ;
V_2 -> V_29 -> V_270 = sizeof( struct V_22 ) ;
V_2 -> V_29 -> V_221 -> V_271 [ V_272 - 1 ] =
( V_2 -> V_7 -> V_8 - 1 ) ;
V_2 -> V_29 -> V_221 -> V_273 = F_117 ( V_274 ) ;
if ( V_2 -> V_7 -> V_275 -> V_236 > 0 )
V_2 -> V_29 -> V_221 -> V_273 |=
F_117 ( V_38 ) |
F_117 ( V_37 ) |
#ifdef F_118
F_117 ( V_39 ) |
#endif
F_117 ( V_40 ) ;
V_2 -> V_29 -> V_221 -> V_11 |= V_276 ;
V_2 -> V_145 =
F_124 ( F_125 ( V_2 -> V_29 -> V_221 ) , 0 ) ;
if ( ! V_2 -> V_145 ) {
V_246 = - V_215 ;
goto exit;
}
F_126 ( & V_2 -> V_28 , F_24 ) ;
F_127 ( & V_2 -> V_31 , F_27 ) ;
F_126 ( & V_2 -> V_119 , F_70 ) ;
V_246 = V_2 -> V_7 -> V_12 -> V_277 ( V_2 ) ;
if ( V_246 ) {
F_28 ( V_2 , L_5 ) ;
goto exit;
}
V_246 = F_128 ( V_2 ) ;
if ( V_246 )
goto exit;
V_246 = F_102 ( V_2 ) ;
if ( V_246 ) {
F_28 ( V_2 , L_6 ) ;
goto exit;
}
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
return 0 ;
exit:
F_133 ( V_2 ) ;
return V_246 ;
}
void F_133 ( struct V_1 * V_2 )
{
F_29 ( V_32 , & V_2 -> V_11 ) ;
F_13 ( V_2 ) ;
F_134 ( & V_2 -> V_28 ) ;
F_135 ( & V_2 -> V_31 ) ;
F_134 ( & V_2 -> V_119 ) ;
if ( F_35 ( V_2 ) ) {
F_136 ( & V_2 -> V_278 ) ;
F_134 ( & V_2 -> V_279 ) ;
F_134 ( & V_2 -> V_280 ) ;
}
if ( V_2 -> V_145 )
F_137 ( V_2 -> V_145 ) ;
F_138 ( & V_2 -> V_237 ) ;
F_139 ( & V_2 -> V_238 ) ;
F_139 ( & V_2 -> V_239 ) ;
F_139 ( & V_2 -> V_240 ) ;
F_139 ( & V_2 -> V_241 ) ;
F_139 ( & V_2 -> V_242 ) ;
F_108 ( V_2 ) ;
F_140 ( V_2 ) ;
F_141 ( V_2 ) ;
F_100 ( V_2 ) ;
F_142 ( V_2 ) ;
F_143 ( V_2 ) ;
if ( V_2 -> V_266 )
F_99 ( V_2 -> V_266 ) ;
}
int F_144 ( struct V_1 * V_2 , T_8 V_281 )
{
F_145 ( V_2 , L_7 ) ;
if ( ! F_14 ( V_32 , & V_2 -> V_11 ) )
return 0 ;
F_108 ( V_2 ) ;
F_146 ( V_2 ) ;
F_140 ( V_2 ) ;
if ( V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_282 ) )
F_83 ( V_2 , L_8 ) ;
return 0 ;
}
int F_147 ( struct V_1 * V_2 )
{
F_145 ( V_2 , L_9 ) ;
F_131 ( V_2 ) ;
F_148 ( V_2 ) ;
F_7 ( V_32 , & V_2 -> V_11 ) ;
return 0 ;
}
