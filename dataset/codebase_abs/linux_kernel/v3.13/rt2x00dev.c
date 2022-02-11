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
if ( F_15 ( V_22 , & V_21 -> V_23 ) )
F_24 ( V_2 , V_4 ) ;
}
static void F_25 ( struct V_24 * V_25 )
{
struct V_1 * V_2 =
F_26 ( V_25 , struct V_1 , V_26 ) ;
F_27 ( V_2 -> V_27 ,
V_28 ,
F_22 ,
V_2 ) ;
}
static void F_28 ( struct V_24 * V_25 )
{
struct V_1 * V_2 =
F_26 ( V_25 , struct V_1 , V_29 . V_25 ) ;
if ( ! F_3 ( V_30 , & V_2 -> V_11 ) )
return;
if ( V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_31 ) )
F_29 ( V_2 , L_1 ) ;
F_30 ( V_32 , & V_2 -> V_11 ) ;
}
static void F_31 ( void * V_18 , T_2 * V_19 ,
struct V_3 * V_4 )
{
struct V_33 V_34 = {} ;
struct V_1 * V_2 = V_18 ;
struct V_35 * V_36 ;
if ( V_4 -> type != V_37 )
return;
V_36 = F_32 ( V_2 -> V_27 , V_4 ) ;
while ( V_36 ) {
F_33 ( V_2 -> V_27 , & V_34 , V_36 ) ;
V_36 = F_32 ( V_2 -> V_27 , V_4 ) ;
}
}
static void F_34 ( void * V_18 , T_2 * V_19 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_18 ;
if ( V_4 -> type != V_37 &&
V_4 -> type != V_38 &&
V_4 -> type != V_39 &&
V_4 -> type != V_40 )
return;
F_35 ( F_36 ( V_2 ) ) ;
F_37 ( V_2 , V_4 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_10 , & V_2 -> V_11 ) )
return;
F_39 (
V_2 -> V_27 , V_28 ,
F_31 , V_2 ) ;
if ( F_40 ( V_2 ) )
return;
F_39 (
V_2 -> V_27 , V_28 ,
F_34 , V_2 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_10 , & V_2 -> V_11 ) )
return;
F_39 (
V_2 -> V_27 , V_28 ,
F_34 , V_2 ) ;
}
void F_42 ( struct V_41 * V_42 )
{
F_7 ( V_43 , & V_42 -> V_11 ) ;
F_43 ( V_42 , V_44 ) ;
}
void F_44 ( struct V_41 * V_42 )
{
F_7 ( V_45 , & V_42 -> V_11 ) ;
F_30 ( V_43 , & V_42 -> V_11 ) ;
F_43 ( V_42 , V_46 ) ;
}
static inline int F_45 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_47 -> V_2 ;
struct V_48 * V_49 = ( void * ) V_42 -> V_36 -> V_18 ;
struct V_50 * V_51 ;
int V_52 ;
if ( F_46 ( ! F_47 ( V_49 -> V_53 ) ) )
return 0 ;
V_52 = 0 ;
F_48 () ;
F_49 (bar_entry, &rt2x00dev->bar_list, list) {
if ( V_51 -> V_42 != V_42 )
continue;
F_50 ( & V_2 -> V_54 ) ;
V_52 = V_51 -> V_55 ;
F_51 ( & V_51 -> V_56 ) ;
F_52 ( & V_2 -> V_54 ) ;
F_53 ( V_51 , V_57 ) ;
break;
}
F_54 () ;
return V_52 ;
}
void F_55 ( struct V_41 * V_42 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = V_42 -> V_47 -> V_2 ;
struct V_60 * V_61 = F_56 ( V_42 -> V_36 ) ;
struct V_62 * V_63 = F_57 ( V_42 -> V_36 ) ;
unsigned int V_64 , V_65 ;
T_2 V_66 , V_67 , V_68 ;
T_2 V_69 = V_63 -> V_11 ;
bool V_70 ;
F_58 ( V_42 ) ;
F_59 ( V_42 -> V_36 , V_2 -> V_71 ) ;
V_63 -> V_11 &= ~ V_72 ;
V_64 = F_60 ( V_42 -> V_36 ) ;
if ( F_3 ( V_73 , & V_2 -> V_74 ) )
F_61 ( V_42 -> V_36 , V_64 ) ;
if ( F_62 ( V_2 ) )
F_63 ( V_42 -> V_36 , V_64 ) ;
F_64 ( V_2 , V_75 , V_42 -> V_36 ) ;
V_70 =
F_45 ( V_42 ) ||
F_3 ( V_76 , & V_59 -> V_11 ) ||
F_3 ( V_77 , & V_59 -> V_11 ) ;
V_2 -> V_78 . V_79 . V_80 += V_70 ;
V_2 -> V_78 . V_79 . V_81 += ! V_70 ;
V_66 = V_63 -> V_82 ;
V_67 = V_63 -> V_83 ;
V_68 = F_3 ( V_84 , & V_59 -> V_11 ) ?
( V_59 -> V_85 + 1 ) : 1 ;
memset ( & V_61 -> V_9 , 0 , sizeof( V_61 -> V_9 ) ) ;
V_61 -> V_9 . V_86 = 0 ;
for ( V_65 = 0 ; V_65 < V_68 && V_65 < V_87 ; V_65 ++ ) {
V_61 -> V_9 . V_88 [ V_65 ] . V_89 = V_66 - V_65 ;
V_61 -> V_9 . V_88 [ V_65 ] . V_11 = V_67 ;
if ( V_66 - V_65 == 0 ) {
V_61 -> V_9 . V_88 [ V_65 ] . V_90 = V_68 - V_65 ;
V_65 ++ ;
break;
}
V_61 -> V_9 . V_88 [ V_65 ] . V_90 = 1 ;
}
if ( V_65 < ( V_87 - 1 ) )
V_61 -> V_9 . V_88 [ V_65 ] . V_89 = - 1 ;
if ( ! ( V_61 -> V_11 & V_91 ) ) {
if ( V_70 )
V_61 -> V_11 |= V_92 ;
else
V_2 -> V_93 . V_94 ++ ;
}
if ( F_3 ( V_95 , & V_59 -> V_11 ) ||
V_61 -> V_11 & V_96 ) {
V_61 -> V_11 |= V_97 ;
V_61 -> V_9 . V_98 = 1 ;
V_61 -> V_9 . V_99 = V_70 ? 1 : 0 ;
if ( ! V_70 )
V_61 -> V_11 |= V_100 ;
}
if ( V_67 & V_101 ) {
if ( V_70 )
V_2 -> V_93 . V_102 ++ ;
else
V_2 -> V_93 . V_103 ++ ;
}
if ( ! ( V_69 & V_104 ) ) {
if ( F_3 ( V_105 , & V_2 -> V_74 ) )
F_65 ( V_2 -> V_27 , V_42 -> V_36 ) ;
else
F_66 ( V_2 -> V_27 , V_42 -> V_36 ) ;
} else
F_67 ( V_42 -> V_36 ) ;
V_42 -> V_36 = NULL ;
V_42 -> V_11 = 0 ;
V_2 -> V_7 -> V_12 -> V_106 ( V_42 ) ;
F_43 ( V_42 , V_107 ) ;
F_50 ( & V_42 -> V_47 -> V_108 ) ;
if ( ! F_68 ( V_42 -> V_47 ) )
F_69 ( V_42 -> V_47 ) ;
F_52 ( & V_42 -> V_47 -> V_108 ) ;
}
void F_70 ( struct V_41 * V_42 , T_1 V_9 )
{
struct V_58 V_59 ;
V_59 . V_11 = 0 ;
F_71 ( V_9 , & V_59 . V_11 ) ;
V_59 . V_85 = 0 ;
F_55 ( V_42 , & V_59 ) ;
}
static T_2 * F_72 ( T_2 * V_18 , unsigned int V_109 , T_2 V_110 )
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
static void F_73 ( struct V_24 * V_25 )
{
struct V_1 * V_2 =
F_26 ( V_25 , struct V_1 , V_118 ) ;
if ( ! F_3 ( V_30 , & V_2 -> V_11 ) )
return;
if ( ! F_3 ( V_32 , & V_2 -> V_11 ) )
F_74 ( V_2 , & V_2 -> V_27 -> V_119 ,
V_120 ) ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_121 * V_122 )
{
struct V_50 * V_42 ;
struct V_48 * V_123 = ( void * ) V_36 -> V_18 ;
if ( F_46 ( ! F_76 ( V_123 -> V_53 ) ) )
return;
if ( V_122 -> V_124 < sizeof( * V_123 ) + V_125 )
return;
F_48 () ;
F_49 (entry, &rt2x00dev->bar_list, list) {
if ( V_123 -> V_126 != V_42 -> V_126 )
continue;
#define F_77 ( T_3 , T_4 ) ( \
((a) & cpu_to_le16(IEEE80211_BAR_CTRL_TID_INFO_MASK)) == \
((b) & cpu_to_le16(IEEE80211_BAR_CTRL_TID_INFO_MASK))) \
if (!TID_CHECK(ba->control, entry->control))
continue;
#undef F_77
if ( ! F_78 ( V_123 -> V_127 , V_42 -> V_128 ) )
continue;
if ( ! F_78 ( V_123 -> V_128 , V_42 -> V_127 ) )
continue;
F_50 ( & V_2 -> V_54 ) ;
V_42 -> V_55 = 1 ;
F_52 ( & V_2 -> V_54 ) ;
break;
}
F_54 () ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_121 * V_122 )
{
struct V_129 * V_130 = ( void * ) V_36 -> V_18 ;
struct V_131 * V_132 ;
T_2 * V_133 ;
T_2 V_134 ;
bool V_135 ;
if ( F_46 ( ! F_80 ( V_130 -> V_53 ) ||
! ( V_2 -> V_27 -> V_119 . V_11 & V_136 ) ) )
return;
if ( V_36 -> V_109 <= 40 + V_125 )
return;
if ( ! ( V_122 -> V_137 & V_138 ) ||
! V_2 -> V_139 )
return;
V_2 -> V_140 = V_141 ;
V_133 = F_72 ( V_36 -> V_18 , V_36 -> V_109 - V_125 , V_142 ) ;
if ( ! V_133 )
return;
if ( V_133 [ 1 ] < sizeof( * V_132 ) )
return;
V_134 = V_133 [ 1 ] ;
V_132 = (struct V_131 * ) & V_133 [ 2 ] ;
V_135 = F_81 ( V_132 , V_134 , V_2 -> V_139 ) ;
V_135 |= ( V_132 -> V_143 & 0x01 ) ;
if ( ! V_135 && ! F_3 ( V_32 , & V_2 -> V_11 ) )
F_82 ( V_2 -> V_144 , & V_2 -> V_118 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_145 * V_146 ;
const struct V_147 * V_148 ;
unsigned int V_65 ;
int signal = V_122 -> signal ;
int type = ( V_122 -> V_137 & V_149 ) ;
switch ( V_122 -> V_150 ) {
case V_151 :
case V_152 :
if ( V_122 -> V_137 & V_153 )
signal = F_84 ( V_122 -> V_150 , signal ) ;
V_146 = & V_2 -> V_154 [ V_2 -> V_155 ] ;
for ( V_65 = 0 ; V_65 < V_146 -> V_156 ; V_65 ++ ) {
V_148 = F_85 ( V_146 -> V_157 [ V_65 ] . V_158 ) ;
if ( ( ( type == V_159 ) &&
( V_148 -> V_160 == signal ) ) ||
( ( type == V_161 ) &&
( V_148 -> V_162 == signal ) ) ||
( ( type == V_153 ) &&
( V_148 -> V_163 == signal ) ) ) {
return V_65 ;
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
F_86 ( V_2 , L_2 ,
V_122 -> V_150 , signal , type ) ;
return 0 ;
}
void F_87 ( struct V_41 * V_42 , T_5 V_166 )
{
struct V_1 * V_2 = V_42 -> V_47 -> V_2 ;
struct V_121 V_122 ;
struct V_35 * V_36 ;
struct V_167 * V_168 ;
unsigned int V_64 ;
int V_66 ;
if ( ! F_3 ( V_30 , & V_2 -> V_11 ) ||
! F_3 ( V_10 , & V_2 -> V_11 ) )
goto V_169;
if ( F_3 ( V_170 , & V_42 -> V_11 ) )
goto V_169;
V_36 = F_88 ( V_42 , V_166 ) ;
if ( ! V_36 )
goto V_169;
F_58 ( V_42 ) ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
V_2 -> V_7 -> V_12 -> V_171 ( V_42 , & V_122 ) ;
if ( F_89 ( V_122 . V_124 == 0 ||
V_122 . V_124 > V_42 -> V_47 -> V_172 ) ) {
F_29 ( V_2 , L_3 ,
V_122 . V_124 , V_42 -> V_47 -> V_172 ) ;
F_90 ( V_42 -> V_36 ) ;
goto V_173;
}
V_64 = F_60 ( V_42 -> V_36 ) ;
if ( ( V_122 . V_137 & V_174 ) &&
( V_122 . V_11 & V_175 ) )
F_91 ( V_42 -> V_36 , V_64 ,
& V_122 ) ;
else if ( V_64 &&
( V_122 . V_124 > V_64 ) &&
( V_122 . V_137 & V_176 ) )
F_61 ( V_42 -> V_36 , V_64 ) ;
F_92 ( V_42 -> V_36 , V_122 . V_124 ) ;
V_66 = F_83 ( V_2 , & V_122 ) ;
if ( V_122 . V_150 == V_164 ||
V_122 . V_150 == V_165 )
V_122 . V_11 |= V_177 ;
F_79 ( V_2 , V_42 -> V_36 , & V_122 ) ;
F_75 ( V_2 , V_42 -> V_36 , & V_122 ) ;
F_93 ( V_2 , V_42 -> V_36 , & V_122 ) ;
F_94 ( V_2 , & V_122 ) ;
F_64 ( V_2 , V_178 , V_42 -> V_36 ) ;
V_168 = F_95 ( V_42 -> V_36 ) ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
V_168 -> V_179 = V_122 . V_180 ;
V_168 -> V_181 = V_2 -> V_155 ;
V_168 -> V_182 = V_2 -> V_183 ;
V_168 -> V_66 = V_66 ;
V_168 -> signal = V_122 . V_184 ;
V_168 -> V_185 = V_122 . V_11 ;
V_168 -> V_186 = V_2 -> V_78 . V_187 . V_188 . V_189 ;
F_96 ( V_2 -> V_27 , V_42 -> V_36 ) ;
V_173:
V_42 -> V_36 = V_36 ;
V_169:
V_42 -> V_11 = 0 ;
F_43 ( V_42 , V_107 ) ;
if ( F_3 ( V_30 , & V_2 -> V_11 ) &&
F_3 ( V_10 , & V_2 -> V_11 ) )
V_2 -> V_7 -> V_12 -> V_106 ( V_42 ) ;
}
static void F_97 ( struct V_190 * V_42 ,
const int V_191 , const int V_192 ,
const int V_193 )
{
V_42 -> V_181 = V_191 <= 14 ? V_194 : V_195 ;
V_42 -> V_196 = F_98 ( V_191 ,
V_42 -> V_181 ) ;
V_42 -> V_158 = V_193 ;
V_42 -> V_197 = V_192 ;
V_42 -> V_198 = 0xff ;
}
static void F_99 ( struct V_199 * V_42 ,
const T_6 V_200 , const struct V_147 * V_148 )
{
V_42 -> V_11 = 0 ;
V_42 -> V_162 = V_148 -> V_162 ;
V_42 -> V_158 = V_200 ;
V_42 -> V_201 = V_200 ;
if ( V_148 -> V_11 & V_202 )
V_42 -> V_11 |= V_203 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_204 * V_205 )
{
struct V_206 * V_27 = V_2 -> V_27 ;
struct V_190 * V_207 ;
struct V_199 * V_88 ;
unsigned int V_208 ;
unsigned int V_65 ;
V_208 = 0 ;
if ( V_205 -> V_209 & V_210 )
V_208 += 4 ;
if ( V_205 -> V_209 & V_211 )
V_208 += 8 ;
V_207 = F_101 ( V_205 -> V_212 , sizeof( * V_207 ) , V_213 ) ;
if ( ! V_207 )
return - V_214 ;
V_88 = F_101 ( V_208 , sizeof( * V_88 ) , V_213 ) ;
if ( ! V_88 )
goto V_215;
for ( V_65 = 0 ; V_65 < V_208 ; V_65 ++ )
F_99 ( & V_88 [ V_65 ] , V_65 , F_85 ( V_65 ) ) ;
for ( V_65 = 0 ; V_65 < V_205 -> V_212 ; V_65 ++ ) {
F_97 ( & V_207 [ V_65 ] ,
V_205 -> V_207 [ V_65 ] . V_191 ,
V_205 -> V_216 [ V_65 ] . V_197 , V_65 ) ;
}
if ( V_205 -> V_217 & V_218 ) {
V_2 -> V_154 [ V_194 ] . V_219 = 14 ;
V_2 -> V_154 [ V_194 ] . V_156 = V_208 ;
V_2 -> V_154 [ V_194 ] . V_207 = V_207 ;
V_2 -> V_154 [ V_194 ] . V_157 = V_88 ;
V_27 -> V_220 -> V_154 [ V_194 ] =
& V_2 -> V_154 [ V_194 ] ;
memcpy ( & V_2 -> V_154 [ V_194 ] . V_221 ,
& V_205 -> V_222 , sizeof( V_205 -> V_222 ) ) ;
}
if ( V_205 -> V_217 & V_223 ) {
V_2 -> V_154 [ V_195 ] . V_219 =
V_205 -> V_212 - 14 ;
V_2 -> V_154 [ V_195 ] . V_156 =
V_208 - 4 ;
V_2 -> V_154 [ V_195 ] . V_207 = & V_207 [ 14 ] ;
V_2 -> V_154 [ V_195 ] . V_157 = & V_88 [ 4 ] ;
V_27 -> V_220 -> V_154 [ V_195 ] =
& V_2 -> V_154 [ V_195 ] ;
memcpy ( & V_2 -> V_154 [ V_195 ] . V_221 ,
& V_205 -> V_222 , sizeof( V_205 -> V_222 ) ) ;
}
return 0 ;
V_215:
F_102 ( V_207 ) ;
F_29 ( V_2 , L_4 ) ;
return - V_214 ;
}
static void F_103 ( struct V_1 * V_2 )
{
if ( F_3 ( V_224 , & V_2 -> V_11 ) )
F_104 ( V_2 -> V_27 ) ;
if ( F_46 ( V_2 -> V_27 -> V_220 -> V_154 [ V_194 ] ) ) {
F_102 ( V_2 -> V_27 -> V_220 -> V_154 [ V_194 ] -> V_207 ) ;
F_102 ( V_2 -> V_27 -> V_220 -> V_154 [ V_194 ] -> V_157 ) ;
V_2 -> V_27 -> V_220 -> V_154 [ V_194 ] = NULL ;
V_2 -> V_27 -> V_220 -> V_154 [ V_195 ] = NULL ;
}
F_102 ( V_2 -> V_205 . V_216 ) ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_204 * V_205 = & V_2 -> V_205 ;
int V_9 ;
if ( F_3 ( V_224 , & V_2 -> V_11 ) )
return 0 ;
V_9 = F_100 ( V_2 , V_205 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_27 -> V_225 = V_2 -> V_7 -> V_226 ;
V_2 -> V_27 -> V_71 =
F_106 (unsigned int, IEEE80211_TX_STATUS_HEADROOM,
rt2x00dev->extra_tx_headroom) ;
if ( F_3 ( V_73 , & V_2 -> V_74 ) )
V_2 -> V_27 -> V_71 += V_227 ;
else if ( F_3 ( V_228 , & V_2 -> V_74 ) )
V_2 -> V_27 -> V_71 += V_229 ;
V_2 -> V_27 -> V_230 = sizeof( struct V_231 ) ;
if ( F_3 ( V_232 , & V_2 -> V_74 ) ) {
int V_233 =
F_107 ( V_2 -> V_7 -> V_226 *
V_2 -> V_234 -> V_235 *
sizeof( T_1 ) ) ;
V_9 = F_108 ( & V_2 -> V_236 , V_233 ,
V_213 ) ;
if ( V_9 )
return V_9 ;
}
#define F_109 ( T_7 ) \
if (rt2x00dev->ops->lib->taskletname) { \
tasklet_init(&rt2x00dev->taskletname, \
rt2x00dev->ops->lib->taskletname, \
(unsigned long)rt2x00dev); \
}
F_109 ( V_237 ) ;
F_109 ( V_238 ) ;
F_109 ( V_239 ) ;
F_109 ( V_240 ) ;
F_109 ( V_241 ) ;
#undef F_109
V_9 = F_110 ( V_2 -> V_27 ) ;
if ( V_9 )
return V_9 ;
F_7 ( V_224 , & V_2 -> V_11 ) ;
return 0 ;
}
static void F_111 ( struct V_1 * V_2 )
{
if ( ! F_15 ( V_242 , & V_2 -> V_11 ) )
return;
F_112 ( V_2 ) ;
V_2 -> V_7 -> V_12 -> V_243 ( V_2 ) ;
F_113 ( V_2 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
int V_9 ;
if ( F_3 ( V_242 , & V_2 -> V_11 ) )
return 0 ;
V_9 = F_115 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_9 = V_2 -> V_7 -> V_12 -> V_244 ( V_2 ) ;
if ( V_9 ) {
F_113 ( V_2 ) ;
return V_9 ;
}
F_7 ( V_242 , & V_2 -> V_11 ) ;
return 0 ;
}
int F_116 ( struct V_1 * V_2 )
{
int V_245 ;
if ( F_3 ( V_246 , & V_2 -> V_11 ) )
return 0 ;
V_245 = F_117 ( V_2 ) ;
if ( V_245 )
return V_245 ;
V_245 = F_114 ( V_2 ) ;
if ( V_245 )
return V_245 ;
V_2 -> V_247 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_248 = 0 ;
V_245 = F_2 ( V_2 ) ;
if ( V_245 )
return V_245 ;
F_7 ( V_246 , & V_2 -> V_11 ) ;
return 0 ;
}
void F_118 ( struct V_1 * V_2 )
{
if ( ! F_15 ( V_246 , & V_2 -> V_11 ) )
return;
F_14 ( V_2 ) ;
V_2 -> V_247 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_248 = 0 ;
}
static inline void F_119 ( struct V_1 * V_2 )
{
struct V_249 * V_250 ;
struct V_251 * V_252 ;
if ( V_2 -> V_7 -> V_8 < 2 )
return;
V_250 = & V_2 -> V_253 ;
V_250 -> V_254 = V_2 -> V_7 -> V_8 ;
V_250 -> V_255 = F_120 ( V_37 ) ;
#ifdef F_121
V_250 -> V_255 |= F_120 ( V_39 ) ;
#endif
V_252 = & V_2 -> V_256 [ V_257 ] ;
V_252 -> V_258 = V_250 ;
V_252 -> V_259 = 1 ;
V_252 -> V_260 = V_250 -> V_254 ;
V_252 -> V_261 = 1 ;
V_2 -> V_27 -> V_220 -> V_262 = V_2 -> V_256 ;
V_2 -> V_27 -> V_220 -> V_263 = 1 ;
}
static unsigned int F_122 ( struct V_1 * V_2 )
{
if ( F_35 ( ! V_2 -> V_234 ) )
return 0 ;
if ( F_36 ( V_2 ) )
return V_2 -> V_234 [ 0 ] . V_264 + V_2 -> V_234 [ 0 ] . V_265 ;
return V_2 -> V_234 [ 0 ] . V_264 ;
}
int F_123 ( struct V_1 * V_2 )
{
int V_245 = - V_214 ;
F_119 ( V_2 ) ;
if ( V_2 -> V_7 -> V_266 > 0 ) {
V_2 -> V_267 = F_124 ( V_2 -> V_7 -> V_266 ,
V_213 ) ;
if ( ! V_2 -> V_267 ) {
V_245 = - V_214 ;
goto exit;
}
}
F_125 ( & V_2 -> V_268 ) ;
F_126 ( & V_2 -> V_269 ) ;
F_127 ( & V_2 -> V_270 ) ;
F_125 ( & V_2 -> V_54 ) ;
F_7 ( V_30 , & V_2 -> V_11 ) ;
V_2 -> V_27 -> V_271 = sizeof( struct V_20 ) ;
V_2 -> V_27 -> V_220 -> V_272 [ V_273 - 1 ] =
( V_2 -> V_7 -> V_8 - 1 ) ;
V_2 -> V_144 =
F_128 ( L_5 , 0 , F_129 ( V_2 -> V_27 -> V_220 ) ) ;
if ( ! V_2 -> V_144 ) {
V_245 = - V_214 ;
goto exit;
}
F_130 ( & V_2 -> V_26 , F_25 ) ;
F_131 ( & V_2 -> V_29 , F_28 ) ;
F_130 ( & V_2 -> V_118 , F_73 ) ;
V_245 = V_2 -> V_7 -> V_12 -> V_274 ( V_2 ) ;
if ( V_245 ) {
F_29 ( V_2 , L_6 ) ;
goto exit;
}
V_245 = F_132 ( V_2 ) ;
if ( V_245 )
goto exit;
V_2 -> V_71 = F_122 ( V_2 ) ;
V_2 -> V_27 -> V_220 -> V_275 = F_120 ( V_276 ) ;
if ( V_2 -> V_277 -> V_235 > 0 )
V_2 -> V_27 -> V_220 -> V_275 |=
F_120 ( V_38 ) |
F_120 ( V_37 ) |
#ifdef F_121
F_120 ( V_39 ) |
#endif
F_120 ( V_40 ) ;
V_2 -> V_27 -> V_220 -> V_11 |= V_278 ;
V_245 = F_105 ( V_2 ) ;
if ( V_245 ) {
F_29 ( V_2 , L_7 ) ;
goto exit;
}
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
F_135 ( V_2 ) ;
F_136 ( V_2 ) ;
return 0 ;
exit:
F_137 ( V_2 ) ;
return V_245 ;
}
void F_137 ( struct V_1 * V_2 )
{
F_30 ( V_30 , & V_2 -> V_11 ) ;
F_14 ( V_2 ) ;
F_138 ( & V_2 -> V_26 ) ;
F_139 ( & V_2 -> V_29 ) ;
F_138 ( & V_2 -> V_118 ) ;
if ( F_36 ( V_2 ) ) {
F_140 ( & V_2 -> V_279 ) ;
F_138 ( & V_2 -> V_280 ) ;
F_138 ( & V_2 -> V_281 ) ;
}
if ( V_2 -> V_144 )
F_141 ( V_2 -> V_144 ) ;
F_142 ( & V_2 -> V_236 ) ;
F_143 ( & V_2 -> V_237 ) ;
F_143 ( & V_2 -> V_238 ) ;
F_143 ( & V_2 -> V_239 ) ;
F_143 ( & V_2 -> V_240 ) ;
F_143 ( & V_2 -> V_241 ) ;
F_111 ( V_2 ) ;
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
F_103 ( V_2 ) ;
F_146 ( V_2 ) ;
F_147 ( V_2 ) ;
if ( V_2 -> V_267 )
F_102 ( V_2 -> V_267 ) ;
}
int F_148 ( struct V_1 * V_2 , T_8 V_282 )
{
F_149 ( V_2 , L_8 ) ;
if ( ! F_15 ( V_30 , & V_2 -> V_11 ) )
return 0 ;
F_111 ( V_2 ) ;
F_150 ( V_2 ) ;
F_144 ( V_2 ) ;
if ( V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_283 ) )
F_86 ( V_2 , L_9 ) ;
return 0 ;
}
int F_151 ( struct V_1 * V_2 )
{
F_149 ( V_2 , L_10 ) ;
F_135 ( V_2 ) ;
F_152 ( V_2 ) ;
F_7 ( V_30 , & V_2 -> V_11 ) ;
return 0 ;
}
