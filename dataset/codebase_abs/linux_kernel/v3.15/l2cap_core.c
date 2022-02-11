static inline T_1 F_1 ( struct V_1 * V_2 , T_1 type )
{
if ( V_2 -> type == V_3 ) {
if ( type == V_4 )
return V_5 ;
else
return V_6 ;
}
return V_7 ;
}
static struct V_8 * F_2 ( struct V_9 * V_10 ,
T_2 V_11 )
{
struct V_8 * V_12 ;
F_3 (c, &conn->chan_l, list) {
if ( V_12 -> V_13 == V_11 )
return V_12 ;
}
return NULL ;
}
static struct V_8 * F_4 ( struct V_9 * V_10 ,
T_2 V_11 )
{
struct V_8 * V_12 ;
F_3 (c, &conn->chan_l, list) {
if ( V_12 -> V_14 == V_11 )
return V_12 ;
}
return NULL ;
}
static struct V_8 * F_5 ( struct V_9 * V_10 ,
T_2 V_11 )
{
struct V_8 * V_12 ;
F_6 ( & V_10 -> V_15 ) ;
V_12 = F_4 ( V_10 , V_11 ) ;
if ( V_12 )
F_7 ( V_12 ) ;
F_8 ( & V_10 -> V_15 ) ;
return V_12 ;
}
static struct V_8 * F_9 ( struct V_9 * V_10 ,
T_2 V_11 )
{
struct V_8 * V_12 ;
F_6 ( & V_10 -> V_15 ) ;
V_12 = F_2 ( V_10 , V_11 ) ;
if ( V_12 )
F_7 ( V_12 ) ;
F_8 ( & V_10 -> V_15 ) ;
return V_12 ;
}
static struct V_8 * F_10 ( struct V_9 * V_10 ,
T_3 V_16 )
{
struct V_8 * V_12 ;
F_3 (c, &conn->chan_l, list) {
if ( V_12 -> V_16 == V_16 )
return V_12 ;
}
return NULL ;
}
static struct V_8 * F_11 ( struct V_9 * V_10 ,
T_3 V_16 )
{
struct V_8 * V_12 ;
F_6 ( & V_10 -> V_15 ) ;
V_12 = F_10 ( V_10 , V_16 ) ;
if ( V_12 )
F_7 ( V_12 ) ;
F_8 ( & V_10 -> V_15 ) ;
return V_12 ;
}
static struct V_8 * F_12 ( T_4 V_17 , T_5 * V_18 )
{
struct V_8 * V_12 ;
F_3 (c, &chan_list, global_l) {
if ( V_12 -> V_19 == V_17 && ! F_13 ( & V_12 -> V_18 , V_18 ) )
return V_12 ;
}
return NULL ;
}
int F_14 ( struct V_8 * V_20 , T_5 * V_18 , T_4 V_17 )
{
int V_21 ;
F_15 ( & V_22 ) ;
if ( V_17 && F_12 ( V_17 , V_18 ) ) {
V_21 = - V_23 ;
goto V_24;
}
if ( V_17 ) {
V_20 -> V_17 = V_17 ;
V_20 -> V_19 = V_17 ;
V_21 = 0 ;
} else {
T_2 V_25 ;
V_21 = - V_26 ;
for ( V_25 = 0x1001 ; V_25 < 0x1100 ; V_25 += 2 )
if ( ! F_12 ( F_16 ( V_25 ) , V_18 ) ) {
V_20 -> V_17 = F_16 ( V_25 ) ;
V_20 -> V_19 = F_16 ( V_25 ) ;
V_21 = 0 ;
break;
}
}
V_24:
F_17 ( & V_22 ) ;
return V_21 ;
}
int F_18 ( struct V_8 * V_20 , T_6 V_14 )
{
F_15 ( & V_22 ) ;
V_20 -> V_14 = V_14 ;
F_17 ( & V_22 ) ;
return 0 ;
}
static T_2 F_19 ( struct V_9 * V_10 )
{
T_2 V_11 , V_27 ;
if ( V_10 -> V_2 -> type == V_3 )
V_27 = V_28 ;
else
V_27 = V_29 ;
for ( V_11 = V_30 ; V_11 < V_27 ; V_11 ++ ) {
if ( ! F_4 ( V_10 , V_11 ) )
return V_11 ;
}
return 0 ;
}
static void F_20 ( struct V_8 * V_20 , int V_31 )
{
F_21 ( L_1 , V_20 , F_22 ( V_20 -> V_31 ) ,
F_22 ( V_31 ) ) ;
V_20 -> V_31 = V_31 ;
V_20 -> V_32 -> V_33 ( V_20 , V_31 , 0 ) ;
}
static inline void F_23 ( struct V_8 * V_20 ,
int V_31 , int V_21 )
{
V_20 -> V_31 = V_31 ;
V_20 -> V_32 -> V_33 ( V_20 , V_20 -> V_31 , V_21 ) ;
}
static inline void F_24 ( struct V_8 * V_20 , int V_21 )
{
V_20 -> V_32 -> V_33 ( V_20 , V_20 -> V_31 , V_21 ) ;
}
static void F_25 ( struct V_8 * V_20 )
{
if ( ! F_26 ( & V_20 -> V_34 ) &&
V_20 -> V_35 ) {
F_27 ( V_20 , & V_20 -> V_36 ,
F_28 ( V_20 -> V_35 ) ) ;
}
}
static void F_29 ( struct V_8 * V_20 )
{
F_30 ( V_20 ) ;
if ( V_20 -> V_37 ) {
F_27 ( V_20 , & V_20 -> V_34 ,
F_28 ( V_20 -> V_37 ) ) ;
}
}
static struct V_38 * F_31 ( struct V_39 * V_40 ,
T_2 V_41 )
{
struct V_38 * V_42 ;
F_32 (head, skb) {
if ( F_33 ( V_42 ) -> V_43 . V_44 == V_41 )
return V_42 ;
}
return NULL ;
}
static int F_34 ( struct V_45 * V_46 , T_2 V_47 )
{
T_7 V_48 , V_49 ;
V_48 = F_35 ( V_47 ) ;
V_46 -> V_50 = F_36 ( sizeof( T_2 ) * V_48 , V_51 ) ;
if ( ! V_46 -> V_50 )
return - V_52 ;
V_46 -> V_53 = V_48 - 1 ;
V_46 -> V_40 = V_54 ;
V_46 -> V_55 = V_54 ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ )
V_46 -> V_50 [ V_49 ] = V_54 ;
return 0 ;
}
static inline void F_37 ( struct V_45 * V_46 )
{
F_38 ( V_46 -> V_50 ) ;
}
static inline bool F_39 ( struct V_45 * V_46 ,
T_2 V_41 )
{
return V_46 -> V_50 [ V_41 & V_46 -> V_53 ] != V_54 ;
}
static inline T_2 F_40 ( struct V_45 * V_46 )
{
T_2 V_41 = V_46 -> V_40 ;
T_2 V_53 = V_46 -> V_53 ;
V_46 -> V_40 = V_46 -> V_50 [ V_41 & V_53 ] ;
V_46 -> V_50 [ V_41 & V_53 ] = V_54 ;
if ( V_46 -> V_40 == V_56 ) {
V_46 -> V_40 = V_54 ;
V_46 -> V_55 = V_54 ;
}
return V_41 ;
}
static void F_41 ( struct V_45 * V_46 )
{
T_2 V_49 ;
if ( V_46 -> V_40 == V_54 )
return;
for ( V_49 = 0 ; V_49 <= V_46 -> V_53 ; V_49 ++ )
V_46 -> V_50 [ V_49 ] = V_54 ;
V_46 -> V_40 = V_54 ;
V_46 -> V_55 = V_54 ;
}
static void F_42 ( struct V_45 * V_46 , T_2 V_41 )
{
T_2 V_53 = V_46 -> V_53 ;
if ( V_46 -> V_50 [ V_41 & V_53 ] != V_54 )
return;
if ( V_46 -> V_55 == V_54 )
V_46 -> V_40 = V_41 ;
else
V_46 -> V_50 [ V_46 -> V_55 & V_53 ] = V_41 ;
V_46 -> V_55 = V_41 ;
V_46 -> V_50 [ V_41 & V_53 ] = V_56 ;
}
static void F_43 ( struct V_57 * V_58 )
{
struct V_8 * V_20 = F_44 ( V_58 , struct V_8 ,
V_59 . V_58 ) ;
struct V_9 * V_10 = V_20 -> V_10 ;
int V_60 ;
F_21 ( L_2 , V_20 , F_22 ( V_20 -> V_31 ) ) ;
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_20 ) ;
if ( V_20 -> V_31 == V_61 || V_20 -> V_31 == V_62 )
V_60 = V_63 ;
else if ( V_20 -> V_31 == V_64 &&
V_20 -> V_65 != V_66 )
V_60 = V_63 ;
else
V_60 = V_67 ;
F_45 ( V_20 , V_60 ) ;
F_46 ( V_20 ) ;
V_20 -> V_32 -> V_68 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
F_47 ( V_20 ) ;
}
struct V_8 * F_48 ( void )
{
struct V_8 * V_20 ;
V_20 = F_49 ( sizeof( * V_20 ) , V_69 ) ;
if ( ! V_20 )
return NULL ;
F_50 ( & V_20 -> V_70 ) ;
F_15 ( & V_22 ) ;
F_51 ( & V_20 -> V_71 , & V_72 ) ;
F_17 ( & V_22 ) ;
F_52 ( & V_20 -> V_59 , F_43 ) ;
V_20 -> V_31 = V_73 ;
F_53 ( & V_20 -> V_74 ) ;
F_54 ( V_75 , & V_20 -> V_76 ) ;
F_21 ( L_3 , V_20 ) ;
return V_20 ;
}
static void F_55 ( struct V_74 * V_74 )
{
struct V_8 * V_20 = F_44 ( V_74 , struct V_8 , V_74 ) ;
F_21 ( L_3 , V_20 ) ;
F_15 ( & V_22 ) ;
F_56 ( & V_20 -> V_71 ) ;
F_17 ( & V_22 ) ;
F_38 ( V_20 ) ;
}
void F_57 ( struct V_8 * V_12 )
{
F_21 ( L_4 , V_12 , F_58 ( & V_12 -> V_74 . V_77 ) ) ;
F_59 ( & V_12 -> V_74 ) ;
}
void F_47 ( struct V_8 * V_12 )
{
F_21 ( L_4 , V_12 , F_58 ( & V_12 -> V_74 . V_77 ) ) ;
F_60 ( & V_12 -> V_74 , F_55 ) ;
}
void F_61 ( struct V_8 * V_20 )
{
V_20 -> V_78 = V_79 ;
V_20 -> V_80 = V_81 ;
V_20 -> V_82 = V_83 ;
V_20 -> V_84 = V_83 ;
V_20 -> V_85 = V_83 ;
V_20 -> V_65 = V_86 ;
F_54 ( V_87 , & V_20 -> V_88 ) ;
}
static void F_62 ( struct V_8 * V_20 )
{
V_20 -> V_89 = NULL ;
V_20 -> V_90 = NULL ;
V_20 -> V_91 = 0 ;
V_20 -> V_92 = 0 ;
V_20 -> V_93 = V_94 ;
V_20 -> V_95 = F_63 ( T_2 , V_20 -> V_96 , V_97 ) ;
F_64 ( & V_20 -> V_98 ) ;
}
void F_65 ( struct V_9 * V_10 , struct V_8 * V_20 )
{
F_21 ( L_5 , V_10 ,
F_66 ( V_20 -> V_17 ) , V_20 -> V_13 ) ;
V_10 -> V_99 = V_100 ;
V_20 -> V_10 = V_10 ;
switch ( V_20 -> V_101 ) {
case V_102 :
V_20 -> V_14 = F_19 ( V_10 ) ;
if ( V_10 -> V_2 -> type == V_103 )
V_20 -> V_104 = V_105 ;
break;
case V_106 :
V_20 -> V_14 = V_107 ;
V_20 -> V_13 = V_107 ;
V_20 -> V_104 = V_105 ;
break;
case V_108 :
break;
default:
V_20 -> V_14 = V_109 ;
V_20 -> V_13 = V_109 ;
V_20 -> V_104 = V_105 ;
}
V_20 -> V_110 = V_111 ;
V_20 -> V_112 = V_113 ;
V_20 -> V_114 = V_115 ;
V_20 -> V_116 = V_117 ;
V_20 -> V_118 = V_119 ;
V_20 -> V_120 = V_121 ;
F_57 ( V_20 ) ;
F_67 ( V_10 -> V_2 ) ;
F_51 ( & V_20 -> V_50 , & V_10 -> V_122 ) ;
}
void F_68 ( struct V_9 * V_10 , struct V_8 * V_20 )
{
F_6 ( & V_10 -> V_15 ) ;
F_65 ( V_10 , V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
}
void F_69 ( struct V_8 * V_20 , int V_21 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_70 ( V_20 ) ;
F_21 ( L_6 , V_20 , V_10 , V_21 ) ;
if ( V_10 ) {
struct V_123 * V_124 = V_10 -> V_2 -> V_123 ;
F_56 ( & V_20 -> V_50 ) ;
F_47 ( V_20 ) ;
V_20 -> V_10 = NULL ;
if ( V_20 -> V_14 != V_125 )
F_71 ( V_10 -> V_2 ) ;
if ( V_124 && V_124 -> V_126 == V_20 )
V_124 -> V_126 = NULL ;
}
if ( V_20 -> V_127 ) {
struct V_128 * V_127 = V_20 -> V_127 ;
F_21 ( L_7 , V_20 , V_127 ) ;
F_72 ( V_127 ) ;
}
V_20 -> V_32 -> V_129 ( V_20 , V_21 ) ;
if ( F_73 ( V_75 , & V_20 -> V_76 ) )
return;
switch( V_20 -> V_130 ) {
case V_131 :
break;
case V_132 :
F_74 ( & V_20 -> V_98 ) ;
break;
case V_133 :
F_30 ( V_20 ) ;
F_75 ( V_20 ) ;
F_76 ( V_20 ) ;
F_74 ( & V_20 -> V_134 ) ;
F_37 ( & V_20 -> V_135 ) ;
F_37 ( & V_20 -> V_136 ) ;
case V_137 :
F_74 ( & V_20 -> V_98 ) ;
break;
}
return;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_138 ;
struct V_8 * V_20 ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
F_78 ( & V_20 -> V_139 , & V_2 -> V_139 ) ;
V_20 -> V_140 = F_1 ( V_2 , V_2 -> V_140 ) ;
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_79 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_141 V_142 ;
T_2 V_143 ;
if ( F_73 ( V_144 , & V_20 -> V_88 ) )
V_143 = V_145 ;
else
V_143 = V_146 ;
F_20 ( V_20 , V_147 ) ;
V_142 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_142 . V_148 = F_16 ( V_20 -> V_96 ) ;
V_142 . V_95 = F_16 ( V_20 -> V_95 ) ;
V_142 . V_149 = F_16 ( V_20 -> V_93 ) ;
V_142 . V_143 = F_16 ( V_143 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_150 , sizeof( V_142 ) ,
& V_142 ) ;
}
static void F_81 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_151 V_142 ;
T_2 V_143 ;
if ( F_73 ( V_144 , & V_20 -> V_88 ) )
V_143 = V_152 ;
else
V_143 = V_146 ;
F_20 ( V_20 , V_147 ) ;
V_142 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_142 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_142 . V_143 = F_16 ( V_143 ) ;
V_142 . V_153 = F_16 ( V_154 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_155 , sizeof( V_142 ) , & V_142 ) ;
}
void F_45 ( struct V_8 * V_20 , int V_60 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_2 , V_20 , F_22 ( V_20 -> V_31 ) ) ;
switch ( V_20 -> V_31 ) {
case V_156 :
V_20 -> V_32 -> V_129 ( V_20 , 0 ) ;
break;
case V_61 :
case V_62 :
if ( V_20 -> V_101 == V_102 ) {
F_82 ( V_20 , V_20 -> V_32 -> V_157 ( V_20 ) ) ;
F_83 ( V_20 , V_60 ) ;
} else
F_69 ( V_20 , V_60 ) ;
break;
case V_158 :
if ( V_20 -> V_101 == V_102 ) {
if ( V_10 -> V_2 -> type == V_103 )
F_81 ( V_20 ) ;
else if ( V_10 -> V_2 -> type == V_3 )
F_79 ( V_20 ) ;
}
F_69 ( V_20 , V_60 ) ;
break;
case V_64 :
case V_147 :
F_69 ( V_20 , V_60 ) ;
break;
default:
V_20 -> V_32 -> V_129 ( V_20 , 0 ) ;
break;
}
}
static inline T_3 F_84 ( struct V_8 * V_20 )
{
switch ( V_20 -> V_101 ) {
case V_159 :
switch ( V_20 -> V_65 ) {
case V_160 :
case V_161 :
return V_162 ;
case V_163 :
return V_164 ;
default:
return V_165 ;
}
break;
case V_106 :
if ( V_20 -> V_17 == F_16 ( V_166 ) ) {
if ( V_20 -> V_65 == V_86 )
V_20 -> V_65 = V_66 ;
}
if ( V_20 -> V_65 == V_160 ||
V_20 -> V_65 == V_161 )
return V_167 ;
else
return V_165 ;
break;
case V_102 :
if ( V_20 -> V_17 == F_16 ( V_168 ) ) {
if ( V_20 -> V_65 == V_86 )
V_20 -> V_65 = V_66 ;
if ( V_20 -> V_65 == V_160 ||
V_20 -> V_65 == V_161 )
return V_167 ;
else
return V_165 ;
}
default:
switch ( V_20 -> V_65 ) {
case V_160 :
case V_161 :
return V_169 ;
case V_163 :
return V_170 ;
default:
return V_165 ;
}
break;
}
}
int F_85 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
T_1 V_171 ;
if ( V_10 -> V_2 -> type == V_3 )
return F_86 ( V_10 -> V_2 , V_20 -> V_65 ) ;
V_171 = F_84 ( V_20 ) ;
return F_87 ( V_10 -> V_2 , V_20 -> V_65 , V_171 ) ;
}
static T_3 F_88 ( struct V_9 * V_10 )
{
T_3 V_172 ;
F_89 ( & V_10 -> V_70 ) ;
if ( ++ V_10 -> V_173 > 128 )
V_10 -> V_173 = 1 ;
V_172 = V_10 -> V_173 ;
F_90 ( & V_10 -> V_70 ) ;
return V_172 ;
}
static void F_80 ( struct V_9 * V_10 , T_3 V_16 , T_3 V_174 , T_2 V_175 ,
void * V_176 )
{
struct V_38 * V_42 = F_91 ( V_10 , V_174 , V_16 , V_175 , V_176 ) ;
T_3 V_88 ;
F_21 ( L_8 , V_174 ) ;
if ( ! V_42 )
return;
if ( F_92 ( V_10 -> V_2 -> V_177 ) )
V_88 = V_178 ;
else
V_88 = V_179 ;
F_33 ( V_42 ) -> V_180 = V_181 ;
V_42 -> V_182 = V_183 ;
F_93 ( V_10 -> V_184 , V_42 , V_88 ) ;
}
static bool F_94 ( struct V_8 * V_20 )
{
return V_20 -> V_185 != V_186 &&
V_20 -> V_185 != V_187 ;
}
static void F_95 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
struct V_1 * V_2 = V_20 -> V_10 -> V_2 ;
T_2 V_88 ;
F_21 ( L_9 , V_20 , V_42 , V_42 -> V_175 ,
V_42 -> V_182 ) ;
if ( V_20 -> V_188 && ! F_94 ( V_20 ) ) {
if ( V_20 -> V_127 )
F_93 ( V_20 -> V_127 , V_42 , V_189 ) ;
else
F_96 ( V_42 ) ;
return;
}
if ( ! F_73 ( V_190 , & V_20 -> V_88 ) &&
F_92 ( V_2 -> V_177 ) )
V_88 = V_178 ;
else
V_88 = V_179 ;
F_33 ( V_42 ) -> V_180 = F_73 ( V_87 , & V_20 -> V_88 ) ;
F_93 ( V_20 -> V_10 -> V_184 , V_42 , V_88 ) ;
}
static void F_97 ( T_2 V_191 , struct V_192 * V_43 )
{
V_43 -> V_193 = ( V_191 & V_194 ) >> V_195 ;
V_43 -> V_196 = ( V_191 & V_197 ) >> V_198 ;
if ( V_191 & V_199 ) {
V_43 -> V_200 = 1 ;
V_43 -> V_201 = ( V_191 & V_202 ) >> V_203 ;
V_43 -> V_204 = ( V_191 & V_205 ) >> V_206 ;
V_43 -> V_207 = 0 ;
V_43 -> V_44 = 0 ;
} else {
V_43 -> V_200 = 0 ;
V_43 -> V_207 = ( V_191 & V_208 ) >> V_209 ;
V_43 -> V_44 = ( V_191 & V_210 ) >> V_211 ;
V_43 -> V_201 = 0 ;
V_43 -> V_204 = 0 ;
}
}
static void F_98 ( T_8 V_212 , struct V_192 * V_43 )
{
V_43 -> V_193 = ( V_212 & V_213 ) >> V_214 ;
V_43 -> V_196 = ( V_212 & V_215 ) >> V_216 ;
if ( V_212 & V_217 ) {
V_43 -> V_200 = 1 ;
V_43 -> V_201 = ( V_212 & V_218 ) >> V_219 ;
V_43 -> V_204 = ( V_212 & V_220 ) >> V_221 ;
V_43 -> V_207 = 0 ;
V_43 -> V_44 = 0 ;
} else {
V_43 -> V_200 = 0 ;
V_43 -> V_207 = ( V_212 & V_222 ) >> V_223 ;
V_43 -> V_44 = ( V_212 & V_224 ) >> V_225 ;
V_43 -> V_201 = 0 ;
V_43 -> V_204 = 0 ;
}
}
static inline void F_99 ( struct V_8 * V_20 ,
struct V_38 * V_42 )
{
if ( F_73 ( V_226 , & V_20 -> V_88 ) ) {
F_98 ( F_100 ( V_42 -> V_176 ) ,
& F_33 ( V_42 ) -> V_43 ) ;
F_101 ( V_42 , V_227 ) ;
} else {
F_97 ( F_102 ( V_42 -> V_176 ) ,
& F_33 ( V_42 ) -> V_43 ) ;
F_101 ( V_42 , V_228 ) ;
}
}
static T_8 F_103 ( struct V_192 * V_43 )
{
T_8 V_229 ;
V_229 = V_43 -> V_193 << V_214 ;
V_229 |= V_43 -> V_196 << V_216 ;
if ( V_43 -> V_200 ) {
V_229 |= V_43 -> V_201 << V_219 ;
V_229 |= V_43 -> V_204 << V_221 ;
V_229 |= V_217 ;
} else {
V_229 |= V_43 -> V_207 << V_223 ;
V_229 |= V_43 -> V_44 << V_225 ;
}
return V_229 ;
}
static T_2 F_104 ( struct V_192 * V_43 )
{
T_2 V_229 ;
V_229 = V_43 -> V_193 << V_195 ;
V_229 |= V_43 -> V_196 << V_198 ;
if ( V_43 -> V_200 ) {
V_229 |= V_43 -> V_201 << V_203 ;
V_229 |= V_43 -> V_204 << V_206 ;
V_229 |= V_199 ;
} else {
V_229 |= V_43 -> V_207 << V_209 ;
V_229 |= V_43 -> V_44 << V_211 ;
}
return V_229 ;
}
static inline void F_105 ( struct V_8 * V_20 ,
struct V_192 * V_43 ,
struct V_38 * V_42 )
{
if ( F_73 ( V_226 , & V_20 -> V_88 ) ) {
F_106 ( F_103 ( V_43 ) ,
V_42 -> V_176 + V_230 ) ;
} else {
F_107 ( F_104 ( V_43 ) ,
V_42 -> V_176 + V_230 ) ;
}
}
static inline unsigned int F_108 ( struct V_8 * V_20 )
{
if ( F_73 ( V_226 , & V_20 -> V_88 ) )
return V_231 ;
else
return V_232 ;
}
static struct V_38 * F_109 ( struct V_8 * V_20 ,
T_8 V_43 )
{
struct V_38 * V_42 ;
struct V_233 * V_234 ;
int V_235 = F_108 ( V_20 ) ;
if ( V_20 -> V_78 == V_79 )
V_235 += V_236 ;
V_42 = F_110 ( V_235 , V_51 ) ;
if ( ! V_42 )
return F_111 ( - V_52 ) ;
V_234 = (struct V_233 * ) F_112 ( V_42 , V_230 ) ;
V_234 -> V_175 = F_16 ( V_235 - V_230 ) ;
V_234 -> V_11 = F_16 ( V_20 -> V_13 ) ;
if ( F_73 ( V_226 , & V_20 -> V_88 ) )
F_106 ( V_43 , F_112 ( V_42 , V_227 ) ) ;
else
F_107 ( V_43 , F_112 ( V_42 , V_228 ) ) ;
if ( V_20 -> V_78 == V_79 ) {
T_2 V_78 = F_113 ( 0 , ( T_3 * ) V_42 -> V_176 , V_42 -> V_175 ) ;
F_107 ( V_78 , F_112 ( V_42 , V_236 ) ) ;
}
V_42 -> V_182 = V_183 ;
return V_42 ;
}
static void F_114 ( struct V_8 * V_20 ,
struct V_192 * V_43 )
{
struct V_38 * V_42 ;
T_8 V_237 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( ! V_43 -> V_200 )
return;
if ( F_94 ( V_20 ) )
return;
if ( F_115 ( V_238 , & V_20 -> V_239 ) &&
! V_43 -> V_201 )
V_43 -> V_196 = 1 ;
if ( V_43 -> V_204 == V_240 )
F_116 ( V_241 , & V_20 -> V_239 ) ;
else if ( V_43 -> V_204 == V_242 )
F_54 ( V_241 , & V_20 -> V_239 ) ;
if ( V_43 -> V_204 != V_243 ) {
V_20 -> V_244 = V_43 -> V_193 ;
F_76 ( V_20 ) ;
}
F_21 ( L_11 , V_43 -> V_193 ,
V_43 -> V_196 , V_43 -> V_201 , V_43 -> V_204 ) ;
if ( F_73 ( V_226 , & V_20 -> V_88 ) )
V_237 = F_103 ( V_43 ) ;
else
V_237 = F_104 ( V_43 ) ;
V_42 = F_109 ( V_20 , V_237 ) ;
if ( ! F_117 ( V_42 ) )
F_95 ( V_20 , V_42 ) ;
}
static void F_118 ( struct V_8 * V_20 , bool V_201 )
{
struct V_192 V_43 ;
F_21 ( L_12 , V_20 , V_201 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_200 = 1 ;
V_43 . V_201 = V_201 ;
if ( F_73 ( V_245 , & V_20 -> V_239 ) )
V_43 . V_204 = V_242 ;
else
V_43 . V_204 = V_240 ;
V_43 . V_193 = V_20 -> V_246 ;
F_114 ( V_20 , & V_43 ) ;
}
static inline int F_119 ( struct V_8 * V_20 )
{
return ! F_73 ( V_247 , & V_20 -> V_76 ) ;
}
static bool F_120 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_248 * V_177 ;
bool V_249 = false ;
if ( ! V_10 -> V_250 )
return false ;
if ( ! ( V_10 -> V_251 & V_252 ) )
return false ;
F_121 ( & V_253 ) ;
F_3 (hdev, &hci_dev_list, list) {
if ( V_177 -> V_254 != V_255 &&
F_73 ( V_256 , & V_177 -> V_88 ) ) {
V_249 = true ;
break;
}
}
F_122 ( & V_253 ) ;
if ( V_20 -> V_257 == V_258 )
return V_249 ;
return false ;
}
static bool F_123 ( struct V_8 * V_20 )
{
return true ;
}
void F_124 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_259 V_260 ;
V_260 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_260 . V_17 = V_20 -> V_17 ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_54 ( V_247 , & V_20 -> V_76 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_261 , sizeof( V_260 ) , & V_260 ) ;
}
static void F_125 ( struct V_8 * V_20 , T_3 V_262 )
{
struct V_263 V_260 ;
V_260 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_260 . V_17 = V_20 -> V_17 ;
V_260 . V_262 = V_262 ;
V_20 -> V_16 = F_88 ( V_20 -> V_10 ) ;
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_264 ,
sizeof( V_260 ) , & V_260 ) ;
}
static void F_126 ( struct V_8 * V_20 )
{
struct V_38 * V_42 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_130 != V_133 )
return;
F_30 ( V_20 ) ;
F_75 ( V_20 ) ;
F_76 ( V_20 ) ;
V_20 -> V_265 = 0 ;
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_42 ) -> V_43 . V_266 )
F_33 ( V_42 ) -> V_43 . V_266 = 1 ;
else
break;
}
V_20 -> V_267 = V_20 -> V_246 ;
F_116 ( V_268 , & V_20 -> V_239 ) ;
F_116 ( V_269 , & V_20 -> V_239 ) ;
F_41 ( & V_20 -> V_136 ) ;
F_41 ( & V_20 -> V_135 ) ;
F_74 ( & V_20 -> V_134 ) ;
V_20 -> V_270 = V_271 ;
V_20 -> V_272 = V_273 ;
F_54 ( V_274 , & V_20 -> V_239 ) ;
}
static void F_127 ( struct V_8 * V_20 )
{
T_3 V_275 = V_20 -> V_275 ;
F_21 ( L_3 , V_20 ) ;
V_20 -> V_185 = V_186 ;
V_20 -> V_275 = V_276 ;
if ( V_20 -> V_130 != V_133 )
return;
switch ( V_275 ) {
case V_277 :
F_128 ( V_20 , NULL , NULL , V_278 ) ;
V_20 -> V_272 = V_279 ;
break;
case V_280 :
V_20 -> V_272 = V_281 ;
break;
}
}
static void F_129 ( struct V_8 * V_20 )
{
V_20 -> V_76 = 0 ;
F_70 ( V_20 ) ;
if ( V_20 -> V_130 == V_132 && ! V_20 -> V_92 )
V_20 -> V_32 -> V_282 ( V_20 ) ;
V_20 -> V_31 = V_61 ;
V_20 -> V_32 -> V_283 ( V_20 ) ;
}
static void F_130 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_284 V_260 ;
if ( F_131 ( V_285 , & V_20 -> V_88 ) )
return;
V_260 . V_17 = V_20 -> V_17 ;
V_260 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_260 . V_148 = F_16 ( V_20 -> V_96 ) ;
V_260 . V_95 = F_16 ( V_20 -> V_95 ) ;
V_260 . V_149 = F_16 ( V_20 -> V_93 ) ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_286 ,
sizeof( V_260 ) , & V_260 ) ;
}
static void F_132 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
if ( ! F_86 ( V_10 -> V_2 , V_20 -> V_65 ) )
return;
if ( ! V_20 -> V_17 ) {
F_129 ( V_20 ) ;
return;
}
if ( V_20 -> V_31 == V_64 )
F_130 ( V_20 ) ;
}
static void F_133 ( struct V_8 * V_20 )
{
if ( F_120 ( V_20 ) ) {
F_21 ( L_13 , V_20 ) ;
F_134 ( V_20 ) ;
} else if ( V_20 -> V_10 -> V_2 -> type == V_3 ) {
F_132 ( V_20 ) ;
} else {
F_124 ( V_20 ) ;
}
}
static void F_135 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
if ( V_10 -> V_2 -> type == V_3 ) {
F_132 ( V_20 ) ;
return;
}
if ( V_10 -> V_287 & V_288 ) {
if ( ! ( V_10 -> V_287 & V_289 ) )
return;
if ( F_85 ( V_20 ) &&
F_119 ( V_20 ) ) {
F_133 ( V_20 ) ;
}
} else {
struct V_290 V_260 ;
V_260 . type = F_16 ( V_291 ) ;
V_10 -> V_287 |= V_288 ;
V_10 -> V_292 = F_88 ( V_10 ) ;
F_136 ( & V_10 -> V_293 , V_294 ) ;
F_80 ( V_10 , V_10 -> V_292 , V_295 ,
sizeof( V_260 ) , & V_260 ) ;
}
}
static inline int F_137 ( T_1 V_130 , T_9 V_296 )
{
T_8 V_297 = V_298 ;
if ( ! V_299 )
V_297 |= V_300 | V_301 ;
switch ( V_130 ) {
case V_133 :
return V_300 & V_296 & V_297 ;
case V_137 :
return V_301 & V_296 & V_297 ;
default:
return 0x00 ;
}
}
static void F_83 ( struct V_8 * V_20 , int V_21 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_302 V_260 ;
if ( ! V_10 )
return;
if ( V_20 -> V_130 == V_133 && V_20 -> V_31 == V_61 ) {
F_30 ( V_20 ) ;
F_75 ( V_20 ) ;
F_76 ( V_20 ) ;
}
if ( V_20 -> V_14 == V_125 ) {
F_20 ( V_20 , V_147 ) ;
return;
}
V_260 . V_13 = F_16 ( V_20 -> V_13 ) ;
V_260 . V_14 = F_16 ( V_20 -> V_14 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_303 ,
sizeof( V_260 ) , & V_260 ) ;
F_23 ( V_20 , V_147 , V_21 ) ;
}
static void F_138 ( struct V_9 * V_10 )
{
struct V_8 * V_20 , * V_304 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_139 (chan, tmp, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_101 != V_102 ) {
F_46 ( V_20 ) ;
continue;
}
if ( V_20 -> V_31 == V_64 ) {
if ( ! F_85 ( V_20 ) ||
! F_119 ( V_20 ) ) {
F_46 ( V_20 ) ;
continue;
}
if ( ! F_137 ( V_20 -> V_130 , V_10 -> V_296 )
&& F_73 ( V_305 ,
& V_20 -> V_76 ) ) {
F_45 ( V_20 , V_306 ) ;
F_46 ( V_20 ) ;
continue;
}
F_133 ( V_20 ) ;
} else if ( V_20 -> V_31 == V_158 ) {
struct V_151 V_142 ;
char V_307 [ 128 ] ;
V_142 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_142 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( F_85 ( V_20 ) ) {
if ( F_73 ( V_144 , & V_20 -> V_88 ) ) {
V_142 . V_143 = F_16 ( V_308 ) ;
V_142 . V_153 = F_16 ( V_309 ) ;
V_20 -> V_32 -> V_310 ( V_20 ) ;
} else {
F_20 ( V_20 , V_62 ) ;
V_142 . V_143 = F_16 ( V_311 ) ;
V_142 . V_153 = F_16 ( V_154 ) ;
}
} else {
V_142 . V_143 = F_16 ( V_308 ) ;
V_142 . V_153 = F_16 ( V_312 ) ;
}
F_80 ( V_10 , V_20 -> V_16 , V_155 ,
sizeof( V_142 ) , & V_142 ) ;
if ( F_73 ( V_313 , & V_20 -> V_76 ) ||
V_142 . V_143 != V_311 ) {
F_46 ( V_20 ) ;
continue;
}
F_54 ( V_313 , & V_20 -> V_76 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_314 ,
F_140 ( V_20 , V_307 ) , V_307 ) ;
V_20 -> V_315 ++ ;
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static struct V_8 * F_141 ( int V_31 , T_2 V_11 ,
T_5 * V_18 ,
T_5 * V_139 )
{
struct V_8 * V_12 , * V_316 = NULL ;
F_121 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_31 && V_12 -> V_31 != V_31 )
continue;
if ( V_12 -> V_14 == V_11 ) {
int V_317 , V_318 ;
int V_319 , V_320 ;
V_317 = ! F_13 ( & V_12 -> V_18 , V_18 ) ;
V_318 = ! F_13 ( & V_12 -> V_139 , V_139 ) ;
if ( V_317 && V_318 ) {
F_122 ( & V_22 ) ;
return V_12 ;
}
V_319 = ! F_13 ( & V_12 -> V_18 , V_321 ) ;
V_320 = ! F_13 ( & V_12 -> V_139 , V_321 ) ;
if ( ( V_317 && V_320 ) || ( V_319 && V_318 ) ||
( V_319 && V_320 ) )
V_316 = V_12 ;
}
}
F_122 ( & V_22 ) ;
return V_316 ;
}
static void F_142 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 , * V_322 ;
T_3 V_140 ;
F_21 ( L_15 ) ;
F_143 ( V_10 ) ;
V_322 = F_141 ( V_156 , V_323 ,
& V_2 -> V_18 , & V_2 -> V_139 ) ;
if ( ! V_322 )
return;
if ( F_2 ( V_10 , V_323 ) )
return;
V_140 = F_1 ( V_2 , V_2 -> V_140 ) ;
if ( F_144 ( V_2 -> V_177 , & V_2 -> V_139 , V_140 ) )
return;
F_7 ( V_322 ) ;
V_20 = V_322 -> V_32 -> V_324 ( V_322 ) ;
if ( ! V_20 )
goto V_325;
F_78 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
F_78 ( & V_20 -> V_139 , & V_2 -> V_139 ) ;
V_20 -> V_326 = F_1 ( V_2 , V_2 -> V_326 ) ;
V_20 -> V_140 = V_140 ;
F_65 ( V_10 , V_20 ) ;
V_325:
F_46 ( V_322 ) ;
}
static void F_145 ( struct V_9 * V_10 )
{
struct V_8 * V_20 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_21 ( L_14 , V_10 ) ;
if ( V_2 -> V_327 && V_2 -> type == V_3 )
F_86 ( V_2 , V_2 -> V_328 ) ;
F_6 ( & V_10 -> V_15 ) ;
if ( V_2 -> type == V_3 )
F_142 ( V_10 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_14 == V_125 ) {
F_46 ( V_20 ) ;
continue;
}
if ( V_2 -> type == V_3 ) {
F_132 ( V_20 ) ;
} else if ( V_20 -> V_101 != V_102 ) {
F_129 ( V_20 ) ;
} else if ( V_20 -> V_31 == V_64 ) {
F_135 ( V_20 ) ;
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
F_146 ( V_2 -> V_177 -> V_329 , & V_10 -> V_330 ) ;
}
static void F_147 ( struct V_9 * V_10 , int V_21 )
{
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( F_73 ( V_331 , & V_20 -> V_88 ) )
F_24 ( V_20 , V_21 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_148 ( struct V_57 * V_58 )
{
struct V_9 * V_10 = F_44 ( V_58 , struct V_9 ,
V_293 . V_58 ) ;
V_10 -> V_287 |= V_289 ;
V_10 -> V_292 = 0 ;
F_138 ( V_10 ) ;
}
int F_149 ( struct V_9 * V_10 , struct V_332 * V_333 )
{
struct V_248 * V_177 = V_10 -> V_2 -> V_177 ;
int V_334 ;
F_150 ( V_177 ) ;
if ( V_333 -> V_50 . V_335 || V_333 -> V_50 . V_336 ) {
V_334 = - V_26 ;
goto V_337;
}
if ( ! V_10 -> V_184 ) {
V_334 = - V_338 ;
goto V_337;
}
V_334 = V_333 -> V_339 ( V_10 , V_333 ) ;
if ( V_334 )
goto V_337;
F_51 ( & V_333 -> V_50 , & V_10 -> V_340 ) ;
V_334 = 0 ;
V_337:
F_151 ( V_177 ) ;
return V_334 ;
}
void F_152 ( struct V_9 * V_10 , struct V_332 * V_333 )
{
struct V_248 * V_177 = V_10 -> V_2 -> V_177 ;
F_150 ( V_177 ) ;
if ( ! V_333 -> V_50 . V_335 || ! V_333 -> V_50 . V_336 )
goto V_337;
F_56 ( & V_333 -> V_50 ) ;
V_333 -> V_50 . V_335 = NULL ;
V_333 -> V_50 . V_336 = NULL ;
V_333 -> remove ( V_10 , V_333 ) ;
V_337:
F_151 ( V_177 ) ;
}
static void F_153 ( struct V_9 * V_10 )
{
struct V_332 * V_333 ;
while ( ! F_154 ( & V_10 -> V_340 ) ) {
V_333 = F_155 ( & V_10 -> V_340 , struct V_332 , V_50 ) ;
F_56 ( & V_333 -> V_50 ) ;
V_333 -> V_50 . V_335 = NULL ;
V_333 -> V_50 . V_336 = NULL ;
V_333 -> remove ( V_10 , V_333 ) ;
}
}
static void F_156 ( struct V_1 * V_2 , int V_21 )
{
struct V_9 * V_10 = V_2 -> V_138 ;
struct V_8 * V_20 , * V_341 ;
if ( ! V_10 )
return;
F_21 ( L_16 , V_2 , V_10 , V_21 ) ;
F_96 ( V_10 -> V_342 ) ;
F_74 ( & V_10 -> V_343 ) ;
F_157 ( & V_10 -> V_330 ) ;
F_153 ( V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_139 (chan, l, &conn->chan_l, list) {
F_57 ( V_20 ) ;
F_7 ( V_20 ) ;
F_69 ( V_20 , V_21 ) ;
F_46 ( V_20 ) ;
V_20 -> V_32 -> V_68 ( V_20 ) ;
F_47 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
F_158 ( V_10 -> V_184 ) ;
if ( V_10 -> V_287 & V_288 )
F_159 ( & V_10 -> V_293 ) ;
if ( F_115 ( V_344 , & V_2 -> V_88 ) ) {
F_159 ( & V_10 -> V_345 ) ;
F_160 ( V_10 ) ;
}
V_2 -> V_138 = NULL ;
V_10 -> V_184 = NULL ;
F_161 ( V_10 ) ;
}
static void F_162 ( struct V_57 * V_58 )
{
struct V_9 * V_10 = F_44 ( V_58 , struct V_9 ,
V_345 . V_58 ) ;
F_21 ( L_14 , V_10 ) ;
if ( F_115 ( V_344 , & V_10 -> V_2 -> V_88 ) ) {
F_160 ( V_10 ) ;
F_156 ( V_10 -> V_2 , V_67 ) ;
}
}
static void F_163 ( struct V_74 * V_346 )
{
struct V_9 * V_10 = F_44 ( V_346 , struct V_9 , V_346 ) ;
F_164 ( V_10 -> V_2 ) ;
F_38 ( V_10 ) ;
}
void F_165 ( struct V_9 * V_10 )
{
F_59 ( & V_10 -> V_346 ) ;
}
void F_161 ( struct V_9 * V_10 )
{
F_60 ( & V_10 -> V_346 , F_163 ) ;
}
static struct V_8 * F_166 ( int V_31 , T_4 V_17 ,
T_5 * V_18 ,
T_5 * V_139 ,
T_3 V_347 )
{
struct V_8 * V_12 , * V_316 = NULL ;
F_121 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_31 && V_12 -> V_31 != V_31 )
continue;
if ( V_347 == V_103 && V_12 -> V_326 != V_7 )
continue;
if ( V_347 == V_3 && V_12 -> V_326 == V_7 )
continue;
if ( V_12 -> V_17 == V_17 ) {
int V_317 , V_318 ;
int V_319 , V_320 ;
V_317 = ! F_13 ( & V_12 -> V_18 , V_18 ) ;
V_318 = ! F_13 ( & V_12 -> V_139 , V_139 ) ;
if ( V_317 && V_318 ) {
F_122 ( & V_22 ) ;
return V_12 ;
}
V_319 = ! F_13 ( & V_12 -> V_18 , V_321 ) ;
V_320 = ! F_13 ( & V_12 -> V_139 , V_321 ) ;
if ( ( V_317 && V_320 ) || ( V_319 && V_318 ) ||
( V_319 && V_320 ) )
V_316 = V_12 ;
}
}
F_122 ( & V_22 ) ;
return V_316 ;
}
static void F_167 ( struct V_57 * V_58 )
{
struct V_8 * V_20 = F_44 ( V_58 , struct V_8 ,
V_34 . V_58 ) ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
if ( ! V_20 -> V_10 ) {
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
return;
}
F_128 ( V_20 , NULL , NULL , V_348 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
static void F_168 ( struct V_57 * V_58 )
{
struct V_8 * V_20 = F_44 ( V_58 , struct V_8 ,
V_36 . V_58 ) ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
if ( ! V_20 -> V_10 ) {
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
return;
}
F_128 ( V_20 , NULL , NULL , V_349 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
static void F_169 ( struct V_8 * V_20 ,
struct V_39 * V_350 )
{
struct V_38 * V_42 ;
struct V_192 * V_43 ;
F_21 ( L_17 , V_20 , V_350 ) ;
if ( F_94 ( V_20 ) )
return;
F_170 ( V_350 , & V_20 -> V_98 ) ;
while ( ! F_171 ( & V_20 -> V_98 ) ) {
V_42 = F_172 ( & V_20 -> V_98 ) ;
F_33 ( V_42 ) -> V_43 . V_266 = 1 ;
V_43 = & F_33 ( V_42 ) -> V_43 ;
V_43 -> V_193 = 0 ;
V_43 -> V_44 = V_20 -> V_351 ;
F_105 ( V_20 , V_43 , V_42 ) ;
if ( V_20 -> V_78 == V_79 ) {
T_2 V_78 = F_113 ( 0 , ( T_3 * ) V_42 -> V_176 , V_42 -> V_175 ) ;
F_107 ( V_78 , F_112 ( V_42 , V_236 ) ) ;
}
F_95 ( V_20 , V_42 ) ;
F_21 ( L_18 , V_43 -> V_44 ) ;
V_20 -> V_351 = F_173 ( V_20 , V_20 -> V_351 ) ;
V_20 -> V_352 ++ ;
}
}
static int F_174 ( struct V_8 * V_20 )
{
struct V_38 * V_42 , * V_353 ;
struct V_192 * V_43 ;
int V_354 = 0 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_31 != V_61 )
return - V_355 ;
if ( F_73 ( V_274 , & V_20 -> V_239 ) )
return 0 ;
if ( F_94 ( V_20 ) )
return 0 ;
while ( V_20 -> V_356 &&
V_20 -> V_357 < V_20 -> V_358 &&
V_20 -> V_270 == V_271 ) {
V_42 = V_20 -> V_356 ;
F_33 ( V_42 ) -> V_43 . V_266 = 1 ;
V_43 = & F_33 ( V_42 ) -> V_43 ;
if ( F_115 ( V_238 , & V_20 -> V_239 ) )
V_43 -> V_196 = 1 ;
V_43 -> V_193 = V_20 -> V_246 ;
V_20 -> V_244 = V_20 -> V_246 ;
V_43 -> V_44 = V_20 -> V_351 ;
F_105 ( V_20 , V_43 , V_42 ) ;
if ( V_20 -> V_78 == V_79 ) {
T_2 V_78 = F_113 ( 0 , ( T_3 * ) V_42 -> V_176 , V_42 -> V_175 ) ;
F_107 ( V_78 , F_112 ( V_42 , V_236 ) ) ;
}
V_353 = F_175 ( V_42 , V_51 ) ;
if ( ! V_353 )
break;
F_25 ( V_20 ) ;
V_20 -> V_351 = F_173 ( V_20 , V_20 -> V_351 ) ;
V_20 -> V_357 ++ ;
V_20 -> V_352 ++ ;
V_354 ++ ;
if ( F_176 ( & V_20 -> V_98 , V_42 ) )
V_20 -> V_356 = NULL ;
else
V_20 -> V_356 = F_177 ( & V_20 -> V_98 , V_42 ) ;
F_95 ( V_20 , V_353 ) ;
F_21 ( L_18 , V_43 -> V_44 ) ;
}
F_21 ( L_19 , V_354 ,
V_20 -> V_357 , F_178 ( & V_20 -> V_98 ) ) ;
return V_354 ;
}
static void F_179 ( struct V_8 * V_20 )
{
struct V_192 V_43 ;
struct V_38 * V_42 ;
struct V_38 * V_353 ;
T_2 V_41 ;
F_21 ( L_3 , V_20 ) ;
if ( F_73 ( V_274 , & V_20 -> V_239 ) )
return;
if ( F_94 ( V_20 ) )
return;
while ( V_20 -> V_136 . V_40 != V_54 ) {
V_41 = F_40 ( & V_20 -> V_136 ) ;
V_42 = F_31 ( & V_20 -> V_98 , V_41 ) ;
if ( ! V_42 ) {
F_21 ( L_20 ,
V_41 ) ;
continue;
}
F_33 ( V_42 ) -> V_43 . V_266 ++ ;
V_43 = F_33 ( V_42 ) -> V_43 ;
if ( V_20 -> V_80 != 0 &&
F_33 ( V_42 ) -> V_43 . V_266 > V_20 -> V_80 ) {
F_21 ( L_21 , V_20 -> V_80 ) ;
F_83 ( V_20 , V_306 ) ;
F_41 ( & V_20 -> V_136 ) ;
break;
}
V_43 . V_193 = V_20 -> V_246 ;
if ( F_115 ( V_238 , & V_20 -> V_239 ) )
V_43 . V_196 = 1 ;
else
V_43 . V_196 = 0 ;
if ( F_180 ( V_42 ) ) {
V_353 = F_181 ( V_42 , V_51 ) ;
} else {
V_353 = F_175 ( V_42 , V_51 ) ;
}
if ( ! V_353 ) {
F_41 ( & V_20 -> V_136 ) ;
break;
}
if ( F_73 ( V_226 , & V_20 -> V_88 ) ) {
F_106 ( F_103 ( & V_43 ) ,
V_353 -> V_176 + V_230 ) ;
} else {
F_107 ( F_104 ( & V_43 ) ,
V_353 -> V_176 + V_230 ) ;
}
if ( V_20 -> V_78 == V_79 ) {
T_2 V_78 = F_113 ( 0 , ( T_3 * ) V_353 -> V_176 , V_353 -> V_175 ) ;
F_107 ( V_78 , F_112 ( V_353 ,
V_236 ) ) ;
}
F_95 ( V_20 , V_353 ) ;
F_21 ( L_22 , V_43 . V_44 ) ;
V_20 -> V_244 = V_20 -> V_246 ;
}
}
static void F_182 ( struct V_8 * V_20 ,
struct V_192 * V_43 )
{
F_21 ( L_10 , V_20 , V_43 ) ;
F_42 ( & V_20 -> V_136 , V_43 -> V_193 ) ;
F_179 ( V_20 ) ;
}
static void F_183 ( struct V_8 * V_20 ,
struct V_192 * V_43 )
{
struct V_38 * V_42 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( V_43 -> V_201 )
F_54 ( V_238 , & V_20 -> V_239 ) ;
F_41 ( & V_20 -> V_136 ) ;
if ( F_73 ( V_274 , & V_20 -> V_239 ) )
return;
if ( V_20 -> V_357 ) {
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_42 ) -> V_43 . V_44 == V_43 -> V_193 ||
V_42 == V_20 -> V_356 )
break;
}
F_184 (&chan->tx_q, skb) {
if ( V_42 == V_20 -> V_356 )
break;
F_42 ( & V_20 -> V_136 ,
F_33 ( V_42 ) -> V_43 . V_44 ) ;
}
F_179 ( V_20 ) ;
}
}
static void F_185 ( struct V_8 * V_20 )
{
struct V_192 V_43 ;
T_2 V_359 = F_186 ( V_20 , V_20 -> V_246 ,
V_20 -> V_244 ) ;
int V_360 ;
F_21 ( L_23 ,
V_20 , V_20 -> V_244 , V_20 -> V_246 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_200 = 1 ;
if ( F_73 ( V_245 , & V_20 -> V_239 ) &&
V_20 -> V_272 == V_361 ) {
F_76 ( V_20 ) ;
V_43 . V_204 = V_242 ;
V_43 . V_193 = V_20 -> V_246 ;
F_114 ( V_20 , & V_43 ) ;
} else {
if ( ! F_73 ( V_274 , & V_20 -> V_239 ) ) {
F_174 ( V_20 ) ;
if ( V_20 -> V_246 == V_20 -> V_244 )
V_359 = 0 ;
}
V_360 = V_20 -> V_85 ;
V_360 += V_360 << 1 ;
V_360 >>= 2 ;
F_21 ( L_24 , V_359 ,
V_360 ) ;
if ( V_359 >= V_360 ) {
F_76 ( V_20 ) ;
V_43 . V_204 = V_240 ;
V_43 . V_193 = V_20 -> V_246 ;
F_114 ( V_20 , & V_43 ) ;
V_359 = 0 ;
}
if ( V_359 )
F_187 ( V_20 ) ;
}
}
static inline int F_188 ( struct V_8 * V_20 ,
struct V_362 * V_363 , int V_175 ,
int V_364 , struct V_38 * V_42 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * * V_365 ;
int V_354 = 0 ;
if ( F_189 ( F_112 ( V_42 , V_364 ) , V_363 -> V_366 , V_364 ) )
return - V_367 ;
V_354 += V_364 ;
V_175 -= V_364 ;
V_365 = & F_190 ( V_42 ) -> V_368 ;
while ( V_175 ) {
struct V_38 * V_304 ;
V_364 = F_63 (unsigned int, conn->mtu, len) ;
V_304 = V_20 -> V_32 -> V_369 ( V_20 , V_364 ,
V_363 -> V_370 & V_371 ) ;
if ( F_117 ( V_304 ) )
return F_191 ( V_304 ) ;
* V_365 = V_304 ;
if ( F_189 ( F_112 ( * V_365 , V_364 ) , V_363 -> V_366 , V_364 ) )
return - V_367 ;
( * V_365 ) -> V_182 = V_42 -> V_182 ;
V_354 += V_364 ;
V_175 -= V_364 ;
V_42 -> V_175 += ( * V_365 ) -> V_175 ;
V_42 -> V_372 += ( * V_365 ) -> V_175 ;
V_365 = & ( * V_365 ) -> V_335 ;
}
return V_354 ;
}
static struct V_38 * F_192 ( struct V_8 * V_20 ,
struct V_362 * V_363 , T_7 V_175 ,
T_8 V_182 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_364 , V_235 = V_230 + V_373 ;
struct V_233 * V_234 ;
F_21 ( L_25 , V_20 ,
F_66 ( V_20 -> V_17 ) , V_175 , V_182 ) ;
V_364 = F_63 (unsigned int, (conn->mtu - hlen), len) ;
V_42 = V_20 -> V_32 -> V_369 ( V_20 , V_364 + V_235 ,
V_363 -> V_370 & V_371 ) ;
if ( F_117 ( V_42 ) )
return V_42 ;
V_42 -> V_182 = V_182 ;
V_234 = (struct V_233 * ) F_112 ( V_42 , V_230 ) ;
V_234 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_234 -> V_175 = F_16 ( V_175 + V_373 ) ;
F_193 ( V_20 -> V_17 , ( T_4 * ) F_112 ( V_42 , V_373 ) ) ;
V_21 = F_188 ( V_20 , V_363 , V_175 , V_364 , V_42 ) ;
if ( F_194 ( V_21 < 0 ) ) {
F_96 ( V_42 ) ;
return F_111 ( V_21 ) ;
}
return V_42 ;
}
static struct V_38 * F_195 ( struct V_8 * V_20 ,
struct V_362 * V_363 , T_7 V_175 ,
T_8 V_182 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_364 ;
struct V_233 * V_234 ;
F_21 ( L_26 , V_20 , V_175 ) ;
V_364 = F_63 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_42 = V_20 -> V_32 -> V_369 ( V_20 , V_364 + V_230 ,
V_363 -> V_370 & V_371 ) ;
if ( F_117 ( V_42 ) )
return V_42 ;
V_42 -> V_182 = V_182 ;
V_234 = (struct V_233 * ) F_112 ( V_42 , V_230 ) ;
V_234 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_234 -> V_175 = F_16 ( V_175 ) ;
V_21 = F_188 ( V_20 , V_363 , V_175 , V_364 , V_42 ) ;
if ( F_194 ( V_21 < 0 ) ) {
F_96 ( V_42 ) ;
return F_111 ( V_21 ) ;
}
return V_42 ;
}
static struct V_38 * F_196 ( struct V_8 * V_20 ,
struct V_362 * V_363 , T_7 V_175 ,
T_2 V_374 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_364 , V_235 ;
struct V_233 * V_234 ;
F_21 ( L_26 , V_20 , V_175 ) ;
if ( ! V_10 )
return F_111 ( - V_355 ) ;
V_235 = F_108 ( V_20 ) ;
if ( V_374 )
V_235 += V_375 ;
if ( V_20 -> V_78 == V_79 )
V_235 += V_236 ;
V_364 = F_63 (unsigned int, (conn->mtu - hlen), len) ;
V_42 = V_20 -> V_32 -> V_369 ( V_20 , V_364 + V_235 ,
V_363 -> V_370 & V_371 ) ;
if ( F_117 ( V_42 ) )
return V_42 ;
V_234 = (struct V_233 * ) F_112 ( V_42 , V_230 ) ;
V_234 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_234 -> V_175 = F_16 ( V_175 + ( V_235 - V_230 ) ) ;
if ( F_73 ( V_226 , & V_20 -> V_88 ) )
F_106 ( 0 , F_112 ( V_42 , V_227 ) ) ;
else
F_107 ( 0 , F_112 ( V_42 , V_228 ) ) ;
if ( V_374 )
F_107 ( V_374 , F_112 ( V_42 , V_375 ) ) ;
V_21 = F_188 ( V_20 , V_363 , V_175 , V_364 , V_42 ) ;
if ( F_194 ( V_21 < 0 ) ) {
F_96 ( V_42 ) ;
return F_111 ( V_21 ) ;
}
F_33 ( V_42 ) -> V_43 . V_78 = V_20 -> V_78 ;
F_33 ( V_42 ) -> V_43 . V_266 = 0 ;
return V_42 ;
}
static int F_197 ( struct V_8 * V_20 ,
struct V_39 * V_376 ,
struct V_362 * V_363 , T_7 V_175 )
{
struct V_38 * V_42 ;
T_2 V_91 ;
T_7 V_377 ;
T_3 V_207 ;
F_21 ( L_27 , V_20 , V_363 , V_175 ) ;
V_377 = V_20 -> V_10 -> V_148 ;
if ( ! V_20 -> V_188 )
V_377 = F_63 ( T_7 , V_377 , V_378 ) ;
if ( V_20 -> V_78 )
V_377 -= V_236 ;
V_377 -= F_108 ( V_20 ) ;
V_377 = F_63 ( T_7 , V_377 , V_20 -> V_379 ) ;
if ( V_175 <= V_377 ) {
V_207 = V_380 ;
V_91 = 0 ;
V_377 = V_175 ;
} else {
V_207 = V_381 ;
V_91 = V_175 ;
V_377 -= V_375 ;
}
while ( V_175 > 0 ) {
V_42 = F_196 ( V_20 , V_363 , V_377 , V_91 ) ;
if ( F_117 ( V_42 ) ) {
F_198 ( V_376 ) ;
return F_191 ( V_42 ) ;
}
F_33 ( V_42 ) -> V_43 . V_207 = V_207 ;
F_199 ( V_376 , V_42 ) ;
V_175 -= V_377 ;
if ( V_91 ) {
V_91 = 0 ;
V_377 += V_375 ;
}
if ( V_175 <= V_377 ) {
V_207 = V_382 ;
V_377 = V_175 ;
} else {
V_207 = V_383 ;
}
}
return 0 ;
}
static struct V_38 * F_200 ( struct V_8 * V_20 ,
struct V_362 * V_363 ,
T_7 V_175 , T_2 V_374 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_364 , V_235 ;
struct V_233 * V_234 ;
F_21 ( L_26 , V_20 , V_175 ) ;
if ( ! V_10 )
return F_111 ( - V_355 ) ;
V_235 = V_230 ;
if ( V_374 )
V_235 += V_375 ;
V_364 = F_63 (unsigned int, (conn->mtu - hlen), len) ;
V_42 = V_20 -> V_32 -> V_369 ( V_20 , V_364 + V_235 ,
V_363 -> V_370 & V_371 ) ;
if ( F_117 ( V_42 ) )
return V_42 ;
V_234 = (struct V_233 * ) F_112 ( V_42 , V_230 ) ;
V_234 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_234 -> V_175 = F_16 ( V_175 + ( V_235 - V_230 ) ) ;
if ( V_374 )
F_107 ( V_374 , F_112 ( V_42 , V_375 ) ) ;
V_21 = F_188 ( V_20 , V_363 , V_175 , V_364 , V_42 ) ;
if ( F_194 ( V_21 < 0 ) ) {
F_96 ( V_42 ) ;
return F_111 ( V_21 ) ;
}
return V_42 ;
}
static int F_201 ( struct V_8 * V_20 ,
struct V_39 * V_376 ,
struct V_362 * V_363 , T_7 V_175 )
{
struct V_38 * V_42 ;
T_7 V_377 ;
T_2 V_91 ;
F_21 ( L_27 , V_20 , V_363 , V_175 ) ;
V_377 = V_20 -> V_10 -> V_148 - V_230 ;
V_377 = F_63 ( T_7 , V_377 , V_20 -> V_379 ) ;
V_91 = V_175 ;
V_377 -= V_375 ;
while ( V_175 > 0 ) {
if ( V_175 <= V_377 )
V_377 = V_175 ;
V_42 = F_200 ( V_20 , V_363 , V_377 , V_91 ) ;
if ( F_117 ( V_42 ) ) {
F_198 ( V_376 ) ;
return F_191 ( V_42 ) ;
}
F_199 ( V_376 , V_42 ) ;
V_175 -= V_377 ;
if ( V_91 ) {
V_91 = 0 ;
V_377 += V_375 ;
}
}
return 0 ;
}
int F_202 ( struct V_8 * V_20 , struct V_362 * V_363 , T_7 V_175 ,
T_8 V_182 )
{
struct V_38 * V_42 ;
int V_21 ;
struct V_39 V_376 ;
if ( ! V_20 -> V_10 )
return - V_355 ;
if ( V_20 -> V_101 == V_106 ) {
V_42 = F_192 ( V_20 , V_363 , V_175 , V_182 ) ;
if ( F_117 ( V_42 ) )
return F_191 ( V_42 ) ;
if ( V_20 -> V_31 != V_61 ) {
F_96 ( V_42 ) ;
return - V_355 ;
}
F_95 ( V_20 , V_42 ) ;
return V_175 ;
}
switch ( V_20 -> V_130 ) {
case V_132 :
if ( V_175 > V_20 -> V_104 )
return - V_384 ;
if ( ! V_20 -> V_92 )
return - V_385 ;
F_203 ( & V_376 ) ;
V_21 = F_201 ( V_20 , & V_376 , V_363 , V_175 ) ;
if ( V_20 -> V_31 != V_61 ) {
F_198 ( & V_376 ) ;
V_21 = - V_355 ;
}
if ( V_21 )
return V_21 ;
F_170 ( & V_376 , & V_20 -> V_98 ) ;
while ( V_20 -> V_92 && ! F_171 ( & V_20 -> V_98 ) ) {
F_95 ( V_20 , F_172 ( & V_20 -> V_98 ) ) ;
V_20 -> V_92 -- ;
}
if ( ! V_20 -> V_92 )
V_20 -> V_32 -> V_282 ( V_20 ) ;
V_21 = V_175 ;
break;
case V_131 :
if ( V_175 > V_20 -> V_104 )
return - V_384 ;
V_42 = F_195 ( V_20 , V_363 , V_175 , V_182 ) ;
if ( F_117 ( V_42 ) )
return F_191 ( V_42 ) ;
if ( V_20 -> V_31 != V_61 ) {
F_96 ( V_42 ) ;
return - V_355 ;
}
F_95 ( V_20 , V_42 ) ;
V_21 = V_175 ;
break;
case V_133 :
case V_137 :
if ( V_175 > V_20 -> V_104 ) {
V_21 = - V_384 ;
break;
}
F_203 ( & V_376 ) ;
V_21 = F_197 ( V_20 , & V_376 , V_363 , V_175 ) ;
if ( V_20 -> V_31 != V_61 ) {
F_198 ( & V_376 ) ;
V_21 = - V_355 ;
}
if ( V_21 )
break;
if ( V_20 -> V_130 == V_133 )
F_128 ( V_20 , NULL , & V_376 , V_386 ) ;
else
F_169 ( V_20 , & V_376 ) ;
V_21 = V_175 ;
F_198 ( & V_376 ) ;
break;
default:
F_21 ( L_28 , V_20 -> V_130 ) ;
V_21 = - V_387 ;
}
return V_21 ;
}
static void F_204 ( struct V_8 * V_20 , T_2 V_44 )
{
struct V_192 V_43 ;
T_2 V_41 ;
F_21 ( L_29 , V_20 , V_44 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_200 = 1 ;
V_43 . V_204 = V_243 ;
for ( V_41 = V_20 -> V_267 ; V_41 != V_44 ;
V_41 = F_173 ( V_20 , V_41 ) ) {
if ( ! F_31 ( & V_20 -> V_134 , V_41 ) ) {
V_43 . V_193 = V_41 ;
F_114 ( V_20 , & V_43 ) ;
F_42 ( & V_20 -> V_135 , V_41 ) ;
}
}
V_20 -> V_267 = F_173 ( V_20 , V_44 ) ;
}
static void F_205 ( struct V_8 * V_20 )
{
struct V_192 V_43 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_135 . V_55 == V_54 )
return;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_200 = 1 ;
V_43 . V_204 = V_243 ;
V_43 . V_193 = V_20 -> V_135 . V_55 ;
F_114 ( V_20 , & V_43 ) ;
}
static void F_206 ( struct V_8 * V_20 , T_2 V_44 )
{
struct V_192 V_43 ;
T_2 V_388 ;
T_2 V_41 ;
F_21 ( L_29 , V_20 , V_44 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_200 = 1 ;
V_43 . V_204 = V_243 ;
V_388 = V_20 -> V_135 . V_40 ;
do {
V_41 = F_40 ( & V_20 -> V_135 ) ;
if ( V_41 == V_44 || V_41 == V_54 )
break;
V_43 . V_193 = V_41 ;
F_114 ( V_20 , & V_43 ) ;
F_42 ( & V_20 -> V_135 , V_41 ) ;
} while ( V_20 -> V_135 . V_40 != V_388 );
}
static void F_207 ( struct V_8 * V_20 , T_2 V_193 )
{
struct V_38 * V_389 ;
T_2 V_390 ;
F_21 ( L_30 , V_20 , V_193 ) ;
if ( V_20 -> V_357 == 0 || V_193 == V_20 -> V_391 )
return;
F_21 ( L_31 ,
V_20 -> V_391 , V_20 -> V_357 ) ;
for ( V_390 = V_20 -> V_391 ; V_390 != V_193 ;
V_390 = F_173 ( V_20 , V_390 ) ) {
V_389 = F_31 ( & V_20 -> V_98 , V_390 ) ;
if ( V_389 ) {
F_208 ( V_389 , & V_20 -> V_98 ) ;
F_96 ( V_389 ) ;
V_20 -> V_357 -- ;
}
}
V_20 -> V_391 = V_193 ;
if ( V_20 -> V_357 == 0 )
F_30 ( V_20 ) ;
F_21 ( L_32 , V_20 -> V_357 ) ;
}
static void F_209 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_267 = V_20 -> V_246 ;
F_41 ( & V_20 -> V_135 ) ;
F_74 ( & V_20 -> V_134 ) ;
V_20 -> V_272 = V_361 ;
}
static void F_210 ( struct V_8 * V_20 ,
struct V_192 * V_43 ,
struct V_39 * V_350 , T_3 V_392 )
{
F_21 ( L_33 , V_20 , V_43 , V_350 ,
V_392 ) ;
switch ( V_392 ) {
case V_386 :
if ( V_20 -> V_356 == NULL )
V_20 -> V_356 = F_211 ( V_350 ) ;
F_170 ( V_350 , & V_20 -> V_98 ) ;
F_174 ( V_20 ) ;
break;
case V_393 :
F_21 ( L_34 ) ;
F_54 ( V_245 , & V_20 -> V_239 ) ;
if ( V_20 -> V_272 == V_394 ) {
F_209 ( V_20 ) ;
}
F_185 ( V_20 ) ;
break;
case V_395 :
F_21 ( L_35 ) ;
F_116 ( V_245 , & V_20 -> V_239 ) ;
if ( F_73 ( V_241 , & V_20 -> V_239 ) ) {
struct V_192 V_396 ;
memset ( & V_396 , 0 , sizeof( V_396 ) ) ;
V_396 . V_200 = 1 ;
V_396 . V_204 = V_240 ;
V_396 . V_201 = 1 ;
V_396 . V_193 = V_20 -> V_246 ;
F_114 ( V_20 , & V_396 ) ;
V_20 -> V_265 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_270 = V_397 ;
}
break;
case V_398 :
F_207 ( V_20 , V_43 -> V_193 ) ;
break;
case V_278 :
F_118 ( V_20 , 1 ) ;
V_20 -> V_265 = 1 ;
F_29 ( V_20 ) ;
F_76 ( V_20 ) ;
V_20 -> V_270 = V_397 ;
break;
case V_349 :
F_118 ( V_20 , 1 ) ;
V_20 -> V_265 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_270 = V_397 ;
break;
case V_399 :
break;
default:
break;
}
}
static void F_212 ( struct V_8 * V_20 ,
struct V_192 * V_43 ,
struct V_39 * V_350 , T_3 V_392 )
{
F_21 ( L_33 , V_20 , V_43 , V_350 ,
V_392 ) ;
switch ( V_392 ) {
case V_386 :
if ( V_20 -> V_356 == NULL )
V_20 -> V_356 = F_211 ( V_350 ) ;
F_170 ( V_350 , & V_20 -> V_98 ) ;
break;
case V_393 :
F_21 ( L_34 ) ;
F_54 ( V_245 , & V_20 -> V_239 ) ;
if ( V_20 -> V_272 == V_394 ) {
F_209 ( V_20 ) ;
}
F_185 ( V_20 ) ;
break;
case V_395 :
F_21 ( L_35 ) ;
F_116 ( V_245 , & V_20 -> V_239 ) ;
if ( F_73 ( V_241 , & V_20 -> V_239 ) ) {
struct V_192 V_396 ;
memset ( & V_396 , 0 , sizeof( V_396 ) ) ;
V_396 . V_200 = 1 ;
V_396 . V_204 = V_240 ;
V_396 . V_201 = 1 ;
V_396 . V_193 = V_20 -> V_246 ;
F_114 ( V_20 , & V_396 ) ;
V_20 -> V_265 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_270 = V_397 ;
}
break;
case V_398 :
F_207 ( V_20 , V_43 -> V_193 ) ;
case V_399 :
if ( V_43 && V_43 -> V_196 ) {
F_75 ( V_20 ) ;
if ( V_20 -> V_357 > 0 )
F_25 ( V_20 ) ;
V_20 -> V_265 = 0 ;
V_20 -> V_270 = V_271 ;
F_21 ( L_36 , V_20 -> V_270 ) ;
}
break;
case V_278 :
break;
case V_348 :
if ( V_20 -> V_80 == 0 || V_20 -> V_265 < V_20 -> V_80 ) {
F_118 ( V_20 , 1 ) ;
F_29 ( V_20 ) ;
V_20 -> V_265 ++ ;
} else {
F_83 ( V_20 , V_400 ) ;
}
break;
default:
break;
}
}
static void F_128 ( struct V_8 * V_20 , struct V_192 * V_43 ,
struct V_39 * V_350 , T_3 V_392 )
{
F_21 ( L_37 ,
V_20 , V_43 , V_350 , V_392 , V_20 -> V_270 ) ;
switch ( V_20 -> V_270 ) {
case V_271 :
F_210 ( V_20 , V_43 , V_350 , V_392 ) ;
break;
case V_397 :
F_212 ( V_20 , V_43 , V_350 , V_392 ) ;
break;
default:
break;
}
}
static void F_213 ( struct V_8 * V_20 ,
struct V_192 * V_43 )
{
F_21 ( L_10 , V_20 , V_43 ) ;
F_128 ( V_20 , V_43 , NULL , V_398 ) ;
}
static void F_214 ( struct V_8 * V_20 ,
struct V_192 * V_43 )
{
F_21 ( L_10 , V_20 , V_43 ) ;
F_128 ( V_20 , V_43 , NULL , V_399 ) ;
}
static void F_215 ( struct V_9 * V_10 , struct V_38 * V_42 )
{
struct V_38 * V_401 ;
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( V_20 -> V_101 != V_159 )
continue;
if ( F_33 ( V_42 ) -> V_20 == V_20 )
continue;
V_401 = F_175 ( V_42 , V_51 ) ;
if ( ! V_401 )
continue;
if ( V_20 -> V_32 -> V_402 ( V_20 , V_401 ) )
F_96 ( V_401 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static struct V_38 * F_91 ( struct V_9 * V_10 , T_3 V_174 ,
T_3 V_16 , T_2 V_403 , void * V_176 )
{
struct V_38 * V_42 , * * V_365 ;
struct V_404 * V_405 ;
struct V_233 * V_234 ;
int V_175 , V_364 ;
F_21 ( L_38 ,
V_10 , V_174 , V_16 , V_403 ) ;
if ( V_10 -> V_148 < V_230 + V_406 )
return NULL ;
V_175 = V_230 + V_406 + V_403 ;
V_364 = F_63 (unsigned int, conn->mtu, len) ;
V_42 = F_110 ( V_364 , V_51 ) ;
if ( ! V_42 )
return NULL ;
V_234 = (struct V_233 * ) F_112 ( V_42 , V_230 ) ;
V_234 -> V_175 = F_16 ( V_406 + V_403 ) ;
if ( V_10 -> V_2 -> type == V_3 )
V_234 -> V_11 = F_16 ( V_407 ) ;
else
V_234 -> V_11 = F_16 ( V_109 ) ;
V_405 = (struct V_404 * ) F_112 ( V_42 , V_406 ) ;
V_405 -> V_174 = V_174 ;
V_405 -> V_16 = V_16 ;
V_405 -> V_175 = F_16 ( V_403 ) ;
if ( V_403 ) {
V_364 -= V_230 + V_406 ;
memcpy ( F_112 ( V_42 , V_364 ) , V_176 , V_364 ) ;
V_176 += V_364 ;
}
V_175 -= V_42 -> V_175 ;
V_365 = & F_190 ( V_42 ) -> V_368 ;
while ( V_175 ) {
V_364 = F_63 (unsigned int, conn->mtu, len) ;
* V_365 = F_110 ( V_364 , V_51 ) ;
if ( ! * V_365 )
goto V_408;
memcpy ( F_112 ( * V_365 , V_364 ) , V_176 , V_364 ) ;
V_175 -= V_364 ;
V_176 += V_364 ;
V_365 = & ( * V_365 ) -> V_335 ;
}
return V_42 ;
V_408:
F_96 ( V_42 ) ;
return NULL ;
}
static inline int F_216 ( void * * V_409 , int * type , int * V_410 ,
unsigned long * V_411 )
{
struct V_412 * V_413 = * V_409 ;
int V_175 ;
V_175 = V_414 + V_413 -> V_175 ;
* V_409 += V_175 ;
* type = V_413 -> type ;
* V_410 = V_413 -> V_175 ;
switch ( V_413 -> V_175 ) {
case 1 :
* V_411 = * ( ( T_3 * ) V_413 -> V_411 ) ;
break;
case 2 :
* V_411 = F_102 ( V_413 -> V_411 ) ;
break;
case 4 :
* V_411 = F_100 ( V_413 -> V_411 ) ;
break;
default:
* V_411 = ( unsigned long ) V_413 -> V_411 ;
break;
}
F_21 ( L_39 , * type , V_413 -> V_175 , * V_411 ) ;
return V_175 ;
}
static void F_217 ( void * * V_409 , T_3 type , T_3 V_175 , unsigned long V_411 )
{
struct V_412 * V_413 = * V_409 ;
F_21 ( L_39 , type , V_175 , V_411 ) ;
V_413 -> type = type ;
V_413 -> V_175 = V_175 ;
switch ( V_175 ) {
case 1 :
* ( ( T_3 * ) V_413 -> V_411 ) = V_411 ;
break;
case 2 :
F_107 ( V_411 , V_413 -> V_411 ) ;
break;
case 4 :
F_106 ( V_411 , V_413 -> V_411 ) ;
break;
default:
memcpy ( V_413 -> V_411 , ( void * ) V_411 , V_175 ) ;
break;
}
* V_409 += V_414 + V_175 ;
}
static void F_218 ( void * * V_409 , struct V_8 * V_20 )
{
struct V_415 V_416 ;
switch ( V_20 -> V_130 ) {
case V_133 :
V_416 . V_172 = V_20 -> V_110 ;
V_416 . V_417 = V_20 -> V_112 ;
V_416 . V_418 = F_16 ( V_20 -> V_114 ) ;
V_416 . V_419 = F_219 ( V_20 -> V_116 ) ;
V_416 . V_420 = F_219 ( V_119 ) ;
V_416 . V_421 = F_219 ( V_121 ) ;
break;
case V_137 :
V_416 . V_172 = 1 ;
V_416 . V_417 = V_113 ;
V_416 . V_418 = F_16 ( V_20 -> V_114 ) ;
V_416 . V_419 = F_219 ( V_20 -> V_116 ) ;
V_416 . V_420 = 0 ;
V_416 . V_421 = 0 ;
break;
default:
return;
}
F_217 ( V_409 , V_422 , sizeof( V_416 ) ,
( unsigned long ) & V_416 ) ;
}
static void F_220 ( struct V_57 * V_58 )
{
struct V_8 * V_20 = F_44 ( V_58 , struct V_8 ,
V_423 . V_58 ) ;
T_2 V_359 ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
V_359 = F_186 ( V_20 , V_20 -> V_246 ,
V_20 -> V_244 ) ;
if ( V_359 )
F_118 ( V_20 , 0 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
int F_221 ( struct V_8 * V_20 )
{
int V_21 ;
V_20 -> V_351 = 0 ;
V_20 -> V_267 = 0 ;
V_20 -> V_391 = 0 ;
V_20 -> V_357 = 0 ;
V_20 -> V_246 = 0 ;
V_20 -> V_352 = 0 ;
V_20 -> V_244 = 0 ;
V_20 -> V_89 = NULL ;
V_20 -> V_90 = NULL ;
V_20 -> V_91 = 0 ;
F_64 ( & V_20 -> V_98 ) ;
V_20 -> V_424 = V_425 ;
V_20 -> V_426 = V_425 ;
V_20 -> V_185 = V_186 ;
V_20 -> V_275 = V_276 ;
if ( V_20 -> V_130 != V_133 )
return 0 ;
V_20 -> V_272 = V_361 ;
V_20 -> V_270 = V_271 ;
F_52 ( & V_20 -> V_36 , F_168 ) ;
F_52 ( & V_20 -> V_34 , F_167 ) ;
F_52 ( & V_20 -> V_423 , F_220 ) ;
F_64 ( & V_20 -> V_134 ) ;
V_21 = F_34 ( & V_20 -> V_135 , V_20 -> V_82 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_34 ( & V_20 -> V_136 , V_20 -> V_358 ) ;
if ( V_21 < 0 )
F_37 ( & V_20 -> V_135 ) ;
return V_21 ;
}
static inline T_1 F_222 ( T_1 V_130 , T_6 V_427 )
{
switch ( V_130 ) {
case V_137 :
case V_133 :
if ( F_137 ( V_130 , V_427 ) )
return V_130 ;
default:
return V_131 ;
}
}
static inline bool F_223 ( struct V_9 * V_10 )
{
return V_10 -> V_250 && V_10 -> V_296 & V_428 ;
}
static inline bool F_224 ( struct V_9 * V_10 )
{
return V_10 -> V_250 && V_10 -> V_296 & V_429 ;
}
static void F_225 ( struct V_8 * V_20 ,
struct V_430 * V_431 )
{
if ( V_20 -> V_424 != V_425 && V_20 -> V_188 ) {
T_10 V_432 = V_20 -> V_188 -> V_177 -> V_433 ;
V_432 = F_226 ( V_432 , 1000 ) ;
V_432 = 3 * V_432 + 500 ;
if ( V_432 > 0xffff )
V_432 = 0xffff ;
V_431 -> V_35 = F_16 ( ( T_2 ) V_432 ) ;
V_431 -> V_37 = V_431 -> V_35 ;
} else {
V_431 -> V_35 = F_16 ( V_434 ) ;
V_431 -> V_37 = F_16 ( V_435 ) ;
}
}
static inline void F_227 ( struct V_8 * V_20 )
{
if ( V_20 -> V_82 > V_83 &&
F_223 ( V_20 -> V_10 ) ) {
F_54 ( V_226 , & V_20 -> V_88 ) ;
V_20 -> V_84 = V_436 ;
} else {
V_20 -> V_82 = F_63 ( T_2 , V_20 -> V_82 ,
V_83 ) ;
V_20 -> V_84 = V_83 ;
}
V_20 -> V_85 = V_20 -> V_82 ;
}
static int F_140 ( struct V_8 * V_20 , void * V_176 )
{
struct V_437 * V_260 = V_176 ;
struct V_430 V_431 = { . V_130 = V_20 -> V_130 } ;
void * V_409 = V_260 -> V_176 ;
T_2 V_47 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_315 || V_20 -> V_438 )
goto V_24;
switch ( V_20 -> V_130 ) {
case V_137 :
case V_133 :
if ( F_73 ( V_305 , & V_20 -> V_76 ) )
break;
if ( F_224 ( V_20 -> V_10 ) )
F_54 ( V_439 , & V_20 -> V_88 ) ;
default:
V_20 -> V_130 = F_222 ( V_431 . V_130 , V_20 -> V_10 -> V_296 ) ;
break;
}
V_24:
if ( V_20 -> V_96 != V_105 )
F_217 ( & V_409 , V_440 , 2 , V_20 -> V_96 ) ;
switch ( V_20 -> V_130 ) {
case V_131 :
if ( ! ( V_20 -> V_10 -> V_296 & V_300 ) &&
! ( V_20 -> V_10 -> V_296 & V_301 ) )
break;
V_431 . V_130 = V_131 ;
V_431 . V_441 = 0 ;
V_431 . V_442 = 0 ;
V_431 . V_35 = 0 ;
V_431 . V_37 = 0 ;
V_431 . V_443 = 0 ;
F_217 ( & V_409 , V_444 , sizeof( V_431 ) ,
( unsigned long ) & V_431 ) ;
break;
case V_133 :
V_431 . V_130 = V_133 ;
V_431 . V_442 = V_20 -> V_80 ;
F_225 ( V_20 , & V_431 ) ;
V_47 = F_63 ( T_2 , V_445 , V_20 -> V_10 -> V_148 -
V_231 - V_375 -
V_236 ) ;
V_431 . V_443 = F_16 ( V_47 ) ;
F_227 ( V_20 ) ;
V_431 . V_441 = F_63 ( T_2 , V_20 -> V_82 ,
V_83 ) ;
F_217 ( & V_409 , V_444 , sizeof( V_431 ) ,
( unsigned long ) & V_431 ) ;
if ( F_73 ( V_439 , & V_20 -> V_88 ) )
F_218 ( & V_409 , V_20 ) ;
if ( F_73 ( V_226 , & V_20 -> V_88 ) )
F_217 ( & V_409 , V_446 , 2 ,
V_20 -> V_82 ) ;
if ( V_20 -> V_10 -> V_296 & V_447 )
if ( V_20 -> V_78 == V_448 ||
F_73 ( V_449 , & V_20 -> V_76 ) ) {
V_20 -> V_78 = V_448 ;
F_217 ( & V_409 , V_450 , 1 ,
V_20 -> V_78 ) ;
}
break;
case V_137 :
F_227 ( V_20 ) ;
V_431 . V_130 = V_137 ;
V_431 . V_441 = 0 ;
V_431 . V_442 = 0 ;
V_431 . V_35 = 0 ;
V_431 . V_37 = 0 ;
V_47 = F_63 ( T_2 , V_445 , V_20 -> V_10 -> V_148 -
V_231 - V_375 -
V_236 ) ;
V_431 . V_443 = F_16 ( V_47 ) ;
F_217 ( & V_409 , V_444 , sizeof( V_431 ) ,
( unsigned long ) & V_431 ) ;
if ( F_73 ( V_439 , & V_20 -> V_88 ) )
F_218 ( & V_409 , V_20 ) ;
if ( V_20 -> V_10 -> V_296 & V_447 )
if ( V_20 -> V_78 == V_448 ||
F_73 ( V_449 , & V_20 -> V_76 ) ) {
V_20 -> V_78 = V_448 ;
F_217 ( & V_409 , V_450 , 1 ,
V_20 -> V_78 ) ;
}
break;
}
V_260 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_260 -> V_88 = F_16 ( 0 ) ;
return V_409 - V_176 ;
}
static int F_228 ( struct V_8 * V_20 , void * V_176 )
{
struct V_451 * V_142 = V_176 ;
void * V_409 = V_142 -> V_176 ;
void * V_260 = V_20 -> V_452 ;
int V_175 = V_20 -> V_453 ;
int type , V_454 , V_410 ;
unsigned long V_411 ;
struct V_430 V_431 = { . V_130 = V_131 } ;
struct V_415 V_416 ;
T_3 V_455 = 0 ;
T_2 V_148 = V_105 ;
T_2 V_143 = V_456 ;
T_2 V_47 ;
F_21 ( L_3 , V_20 ) ;
while ( V_175 >= V_414 ) {
V_175 -= F_216 ( & V_260 , & type , & V_410 , & V_411 ) ;
V_454 = type & V_457 ;
type &= V_458 ;
switch ( type ) {
case V_440 :
V_148 = V_411 ;
break;
case V_459 :
V_20 -> V_421 = V_411 ;
break;
case V_460 :
break;
case V_444 :
if ( V_410 == sizeof( V_431 ) )
memcpy ( & V_431 , ( void * ) V_411 , V_410 ) ;
break;
case V_450 :
if ( V_411 == V_448 )
F_54 ( V_449 , & V_20 -> V_76 ) ;
break;
case V_422 :
V_455 = 1 ;
if ( V_410 == sizeof( V_416 ) )
memcpy ( & V_416 , ( void * ) V_411 , V_410 ) ;
break;
case V_446 :
if ( ! V_20 -> V_10 -> V_250 )
return - V_63 ;
F_54 ( V_226 , & V_20 -> V_88 ) ;
F_54 ( V_461 , & V_20 -> V_76 ) ;
V_20 -> V_84 = V_436 ;
V_20 -> V_358 = V_411 ;
break;
default:
if ( V_454 )
break;
V_143 = V_462 ;
* ( ( T_3 * ) V_409 ++ ) = type ;
break;
}
}
if ( V_20 -> V_438 || V_20 -> V_315 > 1 )
goto V_24;
switch ( V_20 -> V_130 ) {
case V_137 :
case V_133 :
if ( ! F_73 ( V_305 , & V_20 -> V_76 ) ) {
V_20 -> V_130 = F_222 ( V_431 . V_130 ,
V_20 -> V_10 -> V_296 ) ;
break;
}
if ( V_455 ) {
if ( F_224 ( V_20 -> V_10 ) )
F_54 ( V_439 , & V_20 -> V_88 ) ;
else
return - V_63 ;
}
if ( V_20 -> V_130 != V_431 . V_130 )
return - V_63 ;
break;
}
V_24:
if ( V_20 -> V_130 != V_431 . V_130 ) {
V_143 = V_463 ;
V_431 . V_130 = V_20 -> V_130 ;
if ( V_20 -> V_438 == 1 )
return - V_63 ;
F_217 ( & V_409 , V_444 , sizeof( V_431 ) ,
( unsigned long ) & V_431 ) ;
}
if ( V_143 == V_456 ) {
if ( V_148 < V_464 )
V_143 = V_463 ;
else {
V_20 -> V_104 = V_148 ;
F_54 ( V_465 , & V_20 -> V_76 ) ;
}
F_217 ( & V_409 , V_440 , 2 , V_20 -> V_104 ) ;
if ( V_455 ) {
if ( V_20 -> V_112 != V_466 &&
V_416 . V_417 != V_466 &&
V_416 . V_417 != V_20 -> V_112 ) {
V_143 = V_463 ;
if ( V_20 -> V_315 >= 1 )
return - V_63 ;
F_217 ( & V_409 , V_422 ,
sizeof( V_416 ) ,
( unsigned long ) & V_416 ) ;
} else {
V_143 = V_467 ;
F_54 ( V_468 , & V_20 -> V_76 ) ;
}
}
switch ( V_431 . V_130 ) {
case V_131 :
V_20 -> V_78 = V_448 ;
F_54 ( V_469 , & V_20 -> V_76 ) ;
break;
case V_133 :
if ( ! F_73 ( V_461 , & V_20 -> V_76 ) )
V_20 -> V_358 = V_431 . V_441 ;
else
V_431 . V_441 = V_83 ;
V_20 -> V_470 = V_431 . V_442 ;
V_47 = F_63 ( T_2 , F_229 ( V_431 . V_443 ) ,
V_20 -> V_10 -> V_148 - V_231 -
V_375 - V_236 ) ;
V_431 . V_443 = F_16 ( V_47 ) ;
V_20 -> V_379 = V_47 ;
F_225 ( V_20 , & V_431 ) ;
F_54 ( V_469 , & V_20 -> V_76 ) ;
F_217 ( & V_409 , V_444 ,
sizeof( V_431 ) , ( unsigned long ) & V_431 ) ;
if ( F_73 ( V_439 , & V_20 -> V_88 ) ) {
V_20 -> V_471 = V_416 . V_172 ;
V_20 -> V_472 = V_416 . V_417 ;
V_20 -> V_473 = F_229 ( V_416 . V_418 ) ;
V_20 -> V_474 =
F_230 ( V_416 . V_421 ) ;
V_20 -> V_475 =
F_230 ( V_416 . V_420 ) ;
V_20 -> V_476 =
F_230 ( V_416 . V_419 ) ;
F_217 ( & V_409 , V_422 ,
sizeof( V_416 ) ,
( unsigned long ) & V_416 ) ;
}
break;
case V_137 :
V_47 = F_63 ( T_2 , F_229 ( V_431 . V_443 ) ,
V_20 -> V_10 -> V_148 - V_231 -
V_375 - V_236 ) ;
V_431 . V_443 = F_16 ( V_47 ) ;
V_20 -> V_379 = V_47 ;
F_54 ( V_469 , & V_20 -> V_76 ) ;
F_217 ( & V_409 , V_444 , sizeof( V_431 ) ,
( unsigned long ) & V_431 ) ;
break;
default:
V_143 = V_463 ;
memset ( & V_431 , 0 , sizeof( V_431 ) ) ;
V_431 . V_130 = V_20 -> V_130 ;
}
if ( V_143 == V_456 )
F_54 ( V_477 , & V_20 -> V_76 ) ;
}
V_142 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_142 -> V_143 = F_16 ( V_143 ) ;
V_142 -> V_88 = F_16 ( 0 ) ;
return V_409 - V_176 ;
}
static int F_231 ( struct V_8 * V_20 , void * V_142 , int V_175 ,
void * V_176 , T_2 * V_143 )
{
struct V_437 * V_260 = V_176 ;
void * V_409 = V_260 -> V_176 ;
int type , V_410 ;
unsigned long V_411 ;
struct V_430 V_431 = { . V_130 = V_131 } ;
struct V_415 V_416 ;
F_21 ( L_40 , V_20 , V_142 , V_175 , V_176 ) ;
while ( V_175 >= V_414 ) {
V_175 -= F_216 ( & V_142 , & type , & V_410 , & V_411 ) ;
switch ( type ) {
case V_440 :
if ( V_411 < V_464 ) {
* V_143 = V_463 ;
V_20 -> V_96 = V_464 ;
} else
V_20 -> V_96 = V_411 ;
F_217 ( & V_409 , V_440 , 2 , V_20 -> V_96 ) ;
break;
case V_459 :
V_20 -> V_421 = V_411 ;
F_217 ( & V_409 , V_459 ,
2 , V_20 -> V_421 ) ;
break;
case V_444 :
if ( V_410 == sizeof( V_431 ) )
memcpy ( & V_431 , ( void * ) V_411 , V_410 ) ;
if ( F_73 ( V_305 , & V_20 -> V_76 ) &&
V_431 . V_130 != V_20 -> V_130 )
return - V_63 ;
V_20 -> V_78 = 0 ;
F_217 ( & V_409 , V_444 ,
sizeof( V_431 ) , ( unsigned long ) & V_431 ) ;
break;
case V_446 :
V_20 -> V_85 = F_63 ( T_2 , V_411 , V_20 -> V_85 ) ;
F_217 ( & V_409 , V_446 , 2 ,
V_20 -> V_82 ) ;
break;
case V_422 :
if ( V_410 == sizeof( V_416 ) )
memcpy ( & V_416 , ( void * ) V_411 , V_410 ) ;
if ( V_20 -> V_112 != V_466 &&
V_416 . V_417 != V_466 &&
V_416 . V_417 != V_20 -> V_112 )
return - V_63 ;
F_217 ( & V_409 , V_422 , sizeof( V_416 ) ,
( unsigned long ) & V_416 ) ;
break;
case V_450 :
if ( * V_143 == V_467 )
if ( V_411 == V_448 )
F_54 ( V_449 ,
& V_20 -> V_76 ) ;
break;
}
}
if ( V_20 -> V_130 == V_131 && V_20 -> V_130 != V_431 . V_130 )
return - V_63 ;
V_20 -> V_130 = V_431 . V_130 ;
if ( * V_143 == V_456 || * V_143 == V_467 ) {
switch ( V_431 . V_130 ) {
case V_133 :
V_20 -> V_35 = F_229 ( V_431 . V_35 ) ;
V_20 -> V_37 = F_229 ( V_431 . V_37 ) ;
V_20 -> V_95 = F_229 ( V_431 . V_443 ) ;
if ( ! F_73 ( V_226 , & V_20 -> V_88 ) )
V_20 -> V_85 = F_63 ( T_2 , V_20 -> V_85 ,
V_431 . V_441 ) ;
if ( F_73 ( V_439 , & V_20 -> V_88 ) ) {
V_20 -> V_114 = F_229 ( V_416 . V_418 ) ;
V_20 -> V_116 =
F_230 ( V_416 . V_419 ) ;
V_20 -> V_118 = F_230 ( V_416 . V_420 ) ;
V_20 -> V_120 =
F_230 ( V_416 . V_421 ) ;
}
break;
case V_137 :
V_20 -> V_95 = F_229 ( V_431 . V_443 ) ;
}
}
V_260 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_260 -> V_88 = F_16 ( 0 ) ;
return V_409 - V_176 ;
}
static int F_232 ( struct V_8 * V_20 , void * V_176 ,
T_2 V_143 , T_2 V_88 )
{
struct V_451 * V_142 = V_176 ;
void * V_409 = V_142 -> V_176 ;
F_21 ( L_3 , V_20 ) ;
V_142 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_142 -> V_143 = F_16 ( V_143 ) ;
V_142 -> V_88 = F_16 ( V_88 ) ;
return V_409 - V_176 ;
}
void F_233 ( struct V_8 * V_20 )
{
struct V_141 V_142 ;
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_3 , V_20 ) ;
V_142 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_142 . V_148 = F_16 ( V_20 -> V_96 ) ;
V_142 . V_95 = F_16 ( V_20 -> V_95 ) ;
V_142 . V_149 = F_16 ( V_20 -> V_93 ) ;
V_142 . V_143 = F_16 ( V_311 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_150 , sizeof( V_142 ) ,
& V_142 ) ;
}
void F_234 ( struct V_8 * V_20 )
{
struct V_151 V_142 ;
struct V_9 * V_10 = V_20 -> V_10 ;
T_3 V_307 [ 128 ] ;
T_3 V_478 ;
V_142 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_142 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_142 . V_143 = F_16 ( V_311 ) ;
V_142 . V_153 = F_16 ( V_154 ) ;
if ( V_20 -> V_188 )
V_478 = V_479 ;
else
V_478 = V_155 ;
F_21 ( L_41 , V_20 , V_478 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_478 , sizeof( V_142 ) , & V_142 ) ;
if ( F_131 ( V_313 , & V_20 -> V_76 ) )
return;
F_80 ( V_10 , F_88 ( V_10 ) , V_314 ,
F_140 ( V_20 , V_307 ) , V_307 ) ;
V_20 -> V_315 ++ ;
}
static void F_235 ( struct V_8 * V_20 , void * V_142 , int V_175 )
{
int type , V_410 ;
unsigned long V_411 ;
T_2 V_480 = V_20 -> V_85 ;
struct V_430 V_431 = {
. V_130 = V_20 -> V_130 ,
. V_35 = F_16 ( V_434 ) ,
. V_37 = F_16 ( V_435 ) ,
. V_443 = F_16 ( V_20 -> V_96 ) ,
. V_441 = F_63 ( T_2 , V_20 -> V_85 , V_83 ) ,
} ;
F_21 ( L_42 , V_20 , V_142 , V_175 ) ;
if ( ( V_20 -> V_130 != V_133 ) && ( V_20 -> V_130 != V_137 ) )
return;
while ( V_175 >= V_414 ) {
V_175 -= F_216 ( & V_142 , & type , & V_410 , & V_411 ) ;
switch ( type ) {
case V_444 :
if ( V_410 == sizeof( V_431 ) )
memcpy ( & V_431 , ( void * ) V_411 , V_410 ) ;
break;
case V_446 :
V_480 = V_411 ;
break;
}
}
switch ( V_431 . V_130 ) {
case V_133 :
V_20 -> V_35 = F_229 ( V_431 . V_35 ) ;
V_20 -> V_37 = F_229 ( V_431 . V_37 ) ;
V_20 -> V_95 = F_229 ( V_431 . V_443 ) ;
if ( F_73 ( V_226 , & V_20 -> V_88 ) )
V_20 -> V_85 = F_63 ( T_2 , V_20 -> V_85 , V_480 ) ;
else
V_20 -> V_85 = F_63 ( T_2 , V_20 -> V_85 ,
V_431 . V_441 ) ;
break;
case V_137 :
V_20 -> V_95 = F_229 ( V_431 . V_443 ) ;
}
}
static inline int F_236 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
struct V_482 * V_483 = (struct V_482 * ) V_176 ;
if ( V_481 < sizeof( * V_483 ) )
return - V_484 ;
if ( V_483 -> V_60 != V_485 )
return 0 ;
if ( ( V_10 -> V_287 & V_288 ) &&
V_405 -> V_16 == V_10 -> V_292 ) {
F_237 ( & V_10 -> V_293 ) ;
V_10 -> V_287 |= V_289 ;
V_10 -> V_292 = 0 ;
F_138 ( V_10 ) ;
}
return 0 ;
}
static struct V_8 * F_238 ( struct V_9 * V_10 ,
struct V_404 * V_405 ,
T_3 * V_176 , T_3 V_478 , T_3 V_262 )
{
struct V_259 * V_260 = (struct V_259 * ) V_176 ;
struct V_151 V_142 ;
struct V_8 * V_20 = NULL , * V_322 ;
int V_143 , V_153 = V_154 ;
T_2 V_13 = 0 , V_14 = F_66 ( V_260 -> V_14 ) ;
T_4 V_17 = V_260 -> V_17 ;
F_21 ( L_43 , F_66 ( V_17 ) , V_14 ) ;
V_322 = F_166 ( V_156 , V_17 , & V_10 -> V_2 -> V_18 ,
& V_10 -> V_2 -> V_139 , V_103 ) ;
if ( ! V_322 ) {
V_143 = V_146 ;
goto V_486;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_322 ) ;
if ( V_17 != F_16 ( V_168 ) &&
! F_239 ( V_10 -> V_2 ) ) {
V_10 -> V_99 = V_487 ;
V_143 = V_152 ;
goto V_488;
}
V_143 = V_489 ;
if ( F_2 ( V_10 , V_14 ) )
goto V_488;
V_20 = V_322 -> V_32 -> V_324 ( V_322 ) ;
if ( ! V_20 )
goto V_488;
V_10 -> V_2 -> V_490 = V_491 ;
F_78 ( & V_20 -> V_18 , & V_10 -> V_2 -> V_18 ) ;
F_78 ( & V_20 -> V_139 , & V_10 -> V_2 -> V_139 ) ;
V_20 -> V_326 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_326 ) ;
V_20 -> V_140 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_140 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_14 ;
V_20 -> V_424 = V_262 ;
F_65 ( V_10 , V_20 ) ;
V_13 = V_20 -> V_14 ;
F_82 ( V_20 , V_20 -> V_32 -> V_157 ( V_20 ) ) ;
V_20 -> V_16 = V_405 -> V_16 ;
if ( V_10 -> V_287 & V_289 ) {
if ( F_85 ( V_20 ) ) {
if ( F_73 ( V_144 , & V_20 -> V_88 ) ) {
F_20 ( V_20 , V_158 ) ;
V_143 = V_308 ;
V_153 = V_309 ;
V_20 -> V_32 -> V_310 ( V_20 ) ;
} else {
if ( V_262 == V_425 ) {
F_20 ( V_20 , V_62 ) ;
V_143 = V_311 ;
} else {
F_20 ( V_20 , V_158 ) ;
V_143 = V_308 ;
}
V_153 = V_154 ;
}
} else {
F_20 ( V_20 , V_158 ) ;
V_143 = V_308 ;
V_153 = V_312 ;
}
} else {
F_20 ( V_20 , V_158 ) ;
V_143 = V_308 ;
V_153 = V_154 ;
}
V_488:
F_46 ( V_322 ) ;
F_8 ( & V_10 -> V_15 ) ;
V_486:
V_142 . V_14 = F_16 ( V_14 ) ;
V_142 . V_13 = F_16 ( V_13 ) ;
V_142 . V_143 = F_16 ( V_143 ) ;
V_142 . V_153 = F_16 ( V_153 ) ;
F_80 ( V_10 , V_405 -> V_16 , V_478 , sizeof( V_142 ) , & V_142 ) ;
if ( V_143 == V_308 && V_153 == V_154 ) {
struct V_290 V_492 ;
V_492 . type = F_16 ( V_291 ) ;
V_10 -> V_287 |= V_288 ;
V_10 -> V_292 = F_88 ( V_10 ) ;
F_136 ( & V_10 -> V_293 , V_294 ) ;
F_80 ( V_10 , V_10 -> V_292 , V_295 ,
sizeof( V_492 ) , & V_492 ) ;
}
if ( V_20 && ! F_73 ( V_313 , & V_20 -> V_76 ) &&
V_143 == V_311 ) {
T_3 V_307 [ 128 ] ;
F_54 ( V_313 , & V_20 -> V_76 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_314 ,
F_140 ( V_20 , V_307 ) , V_307 ) ;
V_20 -> V_315 ++ ;
}
return V_20 ;
}
static int F_240 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 , T_3 * V_176 )
{
struct V_248 * V_177 = V_10 -> V_2 -> V_177 ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_481 < sizeof( struct V_259 ) )
return - V_484 ;
F_150 ( V_177 ) ;
if ( F_73 ( V_493 , & V_177 -> V_494 ) &&
! F_131 ( V_495 , & V_2 -> V_88 ) )
F_241 ( V_177 , & V_2 -> V_139 , V_2 -> type ,
V_2 -> V_140 , 0 , NULL , 0 ,
V_2 -> V_496 ) ;
F_151 ( V_177 ) ;
F_238 ( V_10 , V_405 , V_176 , V_155 , 0 ) ;
return 0 ;
}
static int F_242 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
struct V_151 * V_142 = (struct V_151 * ) V_176 ;
T_2 V_14 , V_13 , V_143 , V_153 ;
struct V_8 * V_20 ;
T_3 V_260 [ 128 ] ;
int V_21 ;
if ( V_481 < sizeof( * V_142 ) )
return - V_484 ;
V_14 = F_66 ( V_142 -> V_14 ) ;
V_13 = F_66 ( V_142 -> V_13 ) ;
V_143 = F_66 ( V_142 -> V_143 ) ;
V_153 = F_66 ( V_142 -> V_153 ) ;
F_21 ( L_44 ,
V_13 , V_14 , V_143 , V_153 ) ;
F_6 ( & V_10 -> V_15 ) ;
if ( V_14 ) {
V_20 = F_4 ( V_10 , V_14 ) ;
if ( ! V_20 ) {
V_21 = - V_497 ;
goto V_498;
}
} else {
V_20 = F_10 ( V_10 , V_405 -> V_16 ) ;
if ( ! V_20 ) {
V_21 = - V_497 ;
goto V_498;
}
}
V_21 = 0 ;
F_7 ( V_20 ) ;
switch ( V_143 ) {
case V_311 :
F_20 ( V_20 , V_62 ) ;
V_20 -> V_16 = 0 ;
V_20 -> V_13 = V_13 ;
F_116 ( V_247 , & V_20 -> V_76 ) ;
if ( F_131 ( V_313 , & V_20 -> V_76 ) )
break;
F_80 ( V_10 , F_88 ( V_10 ) , V_314 ,
F_140 ( V_20 , V_260 ) , V_260 ) ;
V_20 -> V_315 ++ ;
break;
case V_308 :
F_54 ( V_247 , & V_20 -> V_76 ) ;
break;
default:
F_69 ( V_20 , V_63 ) ;
break;
}
F_46 ( V_20 ) ;
V_498:
F_8 ( & V_10 -> V_15 ) ;
return V_21 ;
}
static inline void F_243 ( struct V_8 * V_20 )
{
if ( V_20 -> V_130 != V_133 && V_20 -> V_130 != V_137 )
V_20 -> V_78 = V_448 ;
else if ( ! F_73 ( V_449 , & V_20 -> V_76 ) )
V_20 -> V_78 = V_79 ;
}
static void F_244 ( struct V_8 * V_20 , void * V_176 ,
T_3 V_16 , T_2 V_88 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_45 , V_10 , V_20 , V_16 ,
V_88 ) ;
F_116 ( V_468 , & V_20 -> V_76 ) ;
F_54 ( V_477 , & V_20 -> V_76 ) ;
F_80 ( V_10 , V_16 , V_499 ,
F_232 ( V_20 , V_176 ,
V_456 , V_88 ) , V_176 ) ;
}
static void F_245 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_14 , T_2 V_13 )
{
struct V_500 V_483 ;
V_483 . V_60 = F_16 ( V_501 ) ;
V_483 . V_14 = F_246 ( V_14 ) ;
V_483 . V_13 = F_246 ( V_13 ) ;
F_80 ( V_10 , V_16 , V_502 , sizeof( V_483 ) , & V_483 ) ;
}
static inline int F_247 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
struct V_437 * V_260 = (struct V_437 * ) V_176 ;
T_2 V_13 , V_88 ;
T_3 V_142 [ 64 ] ;
struct V_8 * V_20 ;
int V_175 , V_21 = 0 ;
if ( V_481 < sizeof( * V_260 ) )
return - V_484 ;
V_13 = F_66 ( V_260 -> V_13 ) ;
V_88 = F_66 ( V_260 -> V_88 ) ;
F_21 ( L_46 , V_13 , V_88 ) ;
V_20 = F_5 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_245 ( V_10 , V_405 -> V_16 , V_13 , 0 ) ;
return 0 ;
}
if ( V_20 -> V_31 != V_62 && V_20 -> V_31 != V_158 ) {
F_245 ( V_10 , V_405 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
goto V_498;
}
V_175 = V_481 - sizeof( * V_260 ) ;
if ( V_20 -> V_453 + V_175 > sizeof( V_20 -> V_452 ) ) {
F_80 ( V_10 , V_405 -> V_16 , V_499 ,
F_232 ( V_20 , V_142 ,
V_503 , V_88 ) , V_142 ) ;
goto V_498;
}
memcpy ( V_20 -> V_452 + V_20 -> V_453 , V_260 -> V_176 , V_175 ) ;
V_20 -> V_453 += V_175 ;
if ( V_88 & V_504 ) {
F_80 ( V_10 , V_405 -> V_16 , V_499 ,
F_232 ( V_20 , V_142 ,
V_456 , V_88 ) , V_142 ) ;
goto V_498;
}
V_175 = F_228 ( V_20 , V_142 ) ;
if ( V_175 < 0 ) {
F_83 ( V_20 , V_306 ) ;
goto V_498;
}
V_20 -> V_16 = V_405 -> V_16 ;
F_80 ( V_10 , V_405 -> V_16 , V_499 , V_175 , V_142 ) ;
V_20 -> V_438 ++ ;
V_20 -> V_453 = 0 ;
if ( ! F_73 ( V_477 , & V_20 -> V_76 ) )
goto V_498;
if ( F_73 ( V_505 , & V_20 -> V_76 ) ) {
F_243 ( V_20 ) ;
if ( V_20 -> V_130 == V_133 ||
V_20 -> V_130 == V_137 )
V_21 = F_221 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_129 ( V_20 ) ;
goto V_498;
}
if ( ! F_131 ( V_313 , & V_20 -> V_76 ) ) {
T_3 V_307 [ 64 ] ;
F_80 ( V_10 , F_88 ( V_10 ) , V_314 ,
F_140 ( V_20 , V_307 ) , V_307 ) ;
V_20 -> V_315 ++ ;
}
if ( F_73 ( V_506 , & V_20 -> V_76 ) &&
F_73 ( V_468 , & V_20 -> V_76 ) ) {
if ( ! V_20 -> V_188 )
F_244 ( V_20 , V_142 , V_405 -> V_16 , V_88 ) ;
else
V_20 -> V_16 = V_405 -> V_16 ;
}
V_498:
F_46 ( V_20 ) ;
return V_21 ;
}
static inline int F_248 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
struct V_451 * V_142 = (struct V_451 * ) V_176 ;
T_2 V_14 , V_88 , V_143 ;
struct V_8 * V_20 ;
int V_175 = V_481 - sizeof( * V_142 ) ;
int V_21 = 0 ;
if ( V_481 < sizeof( * V_142 ) )
return - V_484 ;
V_14 = F_66 ( V_142 -> V_14 ) ;
V_88 = F_66 ( V_142 -> V_88 ) ;
V_143 = F_66 ( V_142 -> V_143 ) ;
F_21 ( L_47 , V_14 , V_88 ,
V_143 , V_175 ) ;
V_20 = F_5 ( V_10 , V_14 ) ;
if ( ! V_20 )
return 0 ;
switch ( V_143 ) {
case V_456 :
F_235 ( V_20 , V_142 -> V_176 , V_175 ) ;
F_116 ( V_506 , & V_20 -> V_76 ) ;
break;
case V_467 :
F_54 ( V_506 , & V_20 -> V_76 ) ;
if ( F_73 ( V_468 , & V_20 -> V_76 ) ) {
char V_307 [ 64 ] ;
V_175 = F_231 ( V_20 , V_142 -> V_176 , V_175 ,
V_307 , & V_143 ) ;
if ( V_175 < 0 ) {
F_83 ( V_20 , V_306 ) ;
goto V_24;
}
if ( ! V_20 -> V_188 ) {
F_244 ( V_20 , V_307 , V_405 -> V_16 ,
0 ) ;
} else {
if ( F_123 ( V_20 ) ) {
F_249 ( V_20 ) ;
V_20 -> V_16 = V_405 -> V_16 ;
}
}
}
goto V_24;
case V_463 :
if ( V_20 -> V_438 <= V_507 ) {
char V_260 [ 64 ] ;
if ( V_175 > sizeof( V_260 ) - sizeof( struct V_437 ) ) {
F_83 ( V_20 , V_306 ) ;
goto V_24;
}
V_143 = V_456 ;
V_175 = F_231 ( V_20 , V_142 -> V_176 , V_175 ,
V_260 , & V_143 ) ;
if ( V_175 < 0 ) {
F_83 ( V_20 , V_306 ) ;
goto V_24;
}
F_80 ( V_10 , F_88 ( V_10 ) ,
V_314 , V_175 , V_260 ) ;
V_20 -> V_315 ++ ;
if ( V_143 != V_456 )
goto V_24;
break;
}
default:
F_24 ( V_20 , V_306 ) ;
F_82 ( V_20 , V_508 ) ;
F_83 ( V_20 , V_306 ) ;
goto V_24;
}
if ( V_88 & V_504 )
goto V_24;
F_54 ( V_505 , & V_20 -> V_76 ) ;
if ( F_73 ( V_477 , & V_20 -> V_76 ) ) {
F_243 ( V_20 ) ;
if ( V_20 -> V_130 == V_133 ||
V_20 -> V_130 == V_137 )
V_21 = F_221 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_129 ( V_20 ) ;
}
V_24:
F_46 ( V_20 ) ;
return V_21 ;
}
static inline int F_250 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
struct V_302 * V_260 = (struct V_302 * ) V_176 ;
struct V_509 V_142 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_481 != sizeof( * V_260 ) )
return - V_484 ;
V_14 = F_66 ( V_260 -> V_14 ) ;
V_13 = F_66 ( V_260 -> V_13 ) ;
F_21 ( L_48 , V_14 , V_13 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_4 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_8 ( & V_10 -> V_15 ) ;
F_245 ( V_10 , V_405 -> V_16 , V_13 , V_14 ) ;
return 0 ;
}
F_7 ( V_20 ) ;
V_142 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_142 . V_14 = F_16 ( V_20 -> V_13 ) ;
F_80 ( V_10 , V_405 -> V_16 , V_510 , sizeof( V_142 ) , & V_142 ) ;
V_20 -> V_32 -> V_511 ( V_20 ) ;
F_57 ( V_20 ) ;
F_69 ( V_20 , V_306 ) ;
F_46 ( V_20 ) ;
V_20 -> V_32 -> V_68 ( V_20 ) ;
F_47 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_251 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
struct V_509 * V_142 = (struct V_509 * ) V_176 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_481 != sizeof( * V_142 ) )
return - V_484 ;
V_14 = F_66 ( V_142 -> V_14 ) ;
V_13 = F_66 ( V_142 -> V_13 ) ;
F_21 ( L_49 , V_13 , V_14 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_4 ( V_10 , V_14 ) ;
if ( ! V_20 ) {
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
F_7 ( V_20 ) ;
F_57 ( V_20 ) ;
F_69 ( V_20 , 0 ) ;
F_46 ( V_20 ) ;
V_20 -> V_32 -> V_68 ( V_20 ) ;
F_47 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_252 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
struct V_290 * V_260 = (struct V_290 * ) V_176 ;
T_2 type ;
if ( V_481 != sizeof( * V_260 ) )
return - V_484 ;
type = F_66 ( V_260 -> type ) ;
F_21 ( L_50 , type ) ;
if ( type == V_291 ) {
T_3 V_307 [ 8 ] ;
T_8 V_296 = V_298 ;
struct V_512 * V_142 = (struct V_512 * ) V_307 ;
V_142 -> type = F_16 ( V_291 ) ;
V_142 -> V_143 = F_16 ( V_513 ) ;
if ( ! V_299 )
V_296 |= V_300 | V_301
| V_447 ;
if ( V_10 -> V_250 )
V_296 |= V_429
| V_428 ;
F_106 ( V_296 , V_142 -> V_176 ) ;
F_80 ( V_10 , V_405 -> V_16 , V_514 , sizeof( V_307 ) ,
V_307 ) ;
} else if ( type == V_515 ) {
T_3 V_307 [ 12 ] ;
struct V_512 * V_142 = (struct V_512 * ) V_307 ;
if ( V_10 -> V_250 )
V_516 [ 0 ] |= V_252 ;
else
V_516 [ 0 ] &= ~ V_252 ;
V_142 -> type = F_16 ( V_515 ) ;
V_142 -> V_143 = F_16 ( V_513 ) ;
memcpy ( V_142 -> V_176 , V_516 , sizeof( V_516 ) ) ;
F_80 ( V_10 , V_405 -> V_16 , V_514 , sizeof( V_307 ) ,
V_307 ) ;
} else {
struct V_512 V_142 ;
V_142 . type = F_16 ( type ) ;
V_142 . V_143 = F_16 ( V_517 ) ;
F_80 ( V_10 , V_405 -> V_16 , V_514 , sizeof( V_142 ) ,
& V_142 ) ;
}
return 0 ;
}
static inline int F_253 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
struct V_512 * V_142 = (struct V_512 * ) V_176 ;
T_2 type , V_143 ;
if ( V_481 < sizeof( * V_142 ) )
return - V_484 ;
type = F_66 ( V_142 -> type ) ;
V_143 = F_66 ( V_142 -> V_143 ) ;
F_21 ( L_51 , type , V_143 ) ;
if ( V_405 -> V_16 != V_10 -> V_292 ||
V_10 -> V_287 & V_289 )
return 0 ;
F_237 ( & V_10 -> V_293 ) ;
if ( V_143 != V_513 ) {
V_10 -> V_287 |= V_289 ;
V_10 -> V_292 = 0 ;
F_138 ( V_10 ) ;
return 0 ;
}
switch ( type ) {
case V_291 :
V_10 -> V_296 = F_100 ( V_142 -> V_176 ) ;
if ( V_10 -> V_296 & V_518 ) {
struct V_290 V_260 ;
V_260 . type = F_16 ( V_515 ) ;
V_10 -> V_292 = F_88 ( V_10 ) ;
F_80 ( V_10 , V_10 -> V_292 ,
V_295 , sizeof( V_260 ) , & V_260 ) ;
} else {
V_10 -> V_287 |= V_289 ;
V_10 -> V_292 = 0 ;
F_138 ( V_10 ) ;
}
break;
case V_515 :
V_10 -> V_251 = V_142 -> V_176 [ 0 ] ;
V_10 -> V_287 |= V_289 ;
V_10 -> V_292 = 0 ;
F_138 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_254 ( struct V_9 * V_10 ,
struct V_404 * V_405 ,
T_2 V_481 , void * V_176 )
{
struct V_263 * V_260 = V_176 ;
struct V_519 V_142 ;
struct V_8 * V_20 ;
struct V_248 * V_177 ;
T_2 V_17 , V_14 ;
if ( V_481 != sizeof( * V_260 ) )
return - V_484 ;
if ( ! V_10 -> V_250 )
return - V_26 ;
V_17 = F_229 ( V_260 -> V_17 ) ;
V_14 = F_229 ( V_260 -> V_14 ) ;
F_21 ( L_52 , V_17 , V_14 , V_260 -> V_262 ) ;
if ( V_260 -> V_262 == V_425 ) {
F_238 ( V_10 , V_405 , V_176 , V_479 ,
V_260 -> V_262 ) ;
return 0 ;
}
V_177 = F_255 ( V_260 -> V_262 ) ;
if ( ! V_177 )
goto error;
if ( V_177 -> V_520 != V_521 || ! F_73 ( V_256 , & V_177 -> V_88 ) ) {
F_256 ( V_177 ) ;
goto error;
}
V_20 = F_238 ( V_10 , V_405 , V_176 , V_479 ,
V_260 -> V_262 ) ;
if ( V_20 ) {
struct V_123 * V_124 = V_10 -> V_2 -> V_123 ;
struct V_1 * V_188 ;
V_188 = F_257 ( V_177 , V_522 ,
& V_10 -> V_2 -> V_139 ) ;
if ( ! V_188 ) {
F_256 ( V_177 ) ;
F_245 ( V_10 , V_405 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
return 0 ;
}
F_21 ( L_53 , V_124 , V_20 , V_188 ) ;
V_124 -> V_126 = V_20 ;
V_20 -> V_188 = V_188 ;
V_20 -> V_78 = V_448 ;
V_10 -> V_148 = V_177 -> V_523 ;
}
F_256 ( V_177 ) ;
return 0 ;
error:
V_142 . V_13 = 0 ;
V_142 . V_14 = F_16 ( V_14 ) ;
V_142 . V_143 = F_16 ( V_524 ) ;
V_142 . V_153 = F_16 ( V_154 ) ;
F_80 ( V_10 , V_405 -> V_16 , V_479 ,
sizeof( V_142 ) , & V_142 ) ;
return 0 ;
}
static void F_258 ( struct V_8 * V_20 , T_3 V_525 )
{
struct V_526 V_260 ;
T_3 V_16 ;
F_21 ( L_54 , V_20 , V_525 ) ;
V_16 = F_88 ( V_20 -> V_10 ) ;
V_20 -> V_16 = V_16 ;
V_260 . V_527 = F_16 ( V_20 -> V_14 ) ;
V_260 . V_525 = V_525 ;
F_80 ( V_20 -> V_10 , V_16 , V_528 , sizeof( V_260 ) ,
& V_260 ) ;
F_82 ( V_20 , V_529 ) ;
}
static void F_259 ( struct V_8 * V_20 , T_2 V_143 )
{
struct V_530 V_142 ;
F_21 ( L_55 , V_20 , V_143 ) ;
V_142 . V_527 = F_16 ( V_20 -> V_13 ) ;
V_142 . V_143 = F_16 ( V_143 ) ;
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_531 ,
sizeof( V_142 ) , & V_142 ) ;
}
static void F_260 ( struct V_8 * V_20 , T_2 V_143 )
{
struct V_532 V_533 ;
F_21 ( L_55 , V_20 , V_143 ) ;
V_20 -> V_16 = F_88 ( V_20 -> V_10 ) ;
V_533 . V_527 = F_16 ( V_20 -> V_14 ) ;
V_533 . V_143 = F_16 ( V_143 ) ;
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_534 ,
sizeof( V_533 ) , & V_533 ) ;
F_82 ( V_20 , V_529 ) ;
}
static void F_261 ( struct V_9 * V_10 , T_2 V_527 )
{
struct V_532 V_533 ;
F_21 ( L_56 , V_10 , V_527 ) ;
V_533 . V_527 = F_16 ( V_527 ) ;
V_533 . V_143 = F_16 ( V_535 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_534 ,
sizeof( V_533 ) , & V_533 ) ;
}
static void F_262 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_527 )
{
struct V_536 V_142 ;
F_21 ( L_57 , V_527 ) ;
V_142 . V_527 = F_16 ( V_527 ) ;
F_80 ( V_10 , V_16 , V_537 , sizeof( V_142 ) , & V_142 ) ;
}
static void F_263 ( struct V_8 * V_20 )
{
V_20 -> V_127 = NULL ;
V_20 -> V_188 = NULL ;
}
static void F_264 ( struct V_8 * V_20 )
{
if ( V_20 -> V_31 != V_61 ) {
F_83 ( V_20 , V_306 ) ;
return;
}
switch ( V_20 -> V_275 ) {
case V_280 :
F_127 ( V_20 ) ;
F_259 ( V_20 , V_538 ) ;
break;
case V_277 :
if ( V_20 -> V_185 == V_539 ||
V_20 -> V_185 == V_540 ) {
F_127 ( V_20 ) ;
}
F_260 ( V_20 , V_535 ) ;
break;
}
}
static void F_265 ( struct V_8 * V_20 ,
struct V_128 * V_184 )
{
struct V_451 V_142 ;
V_20 -> V_127 = V_184 ;
V_20 -> V_188 -> V_138 = V_20 -> V_10 ;
F_244 ( V_20 , & V_142 , V_20 -> V_16 , 0 ) ;
if ( F_73 ( V_505 , & V_20 -> V_76 ) ) {
int V_21 ;
F_243 ( V_20 ) ;
V_21 = F_221 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_129 ( V_20 ) ;
}
}
static void F_266 ( struct V_8 * V_20 ,
struct V_128 * V_184 )
{
V_20 -> V_188 = V_184 -> V_10 ;
V_20 -> V_188 -> V_138 = V_20 -> V_10 ;
F_21 ( L_58 , V_20 -> V_185 ) ;
switch ( V_20 -> V_185 ) {
case V_539 :
V_20 -> V_185 = V_541 ;
break;
case V_540 :
if ( F_73 ( V_245 , & V_20 -> V_239 ) ) {
V_20 -> V_185 = V_542 ;
} else if ( V_20 -> V_275 == V_277 ) {
V_20 -> V_185 = V_543 ;
F_260 ( V_20 , V_544 ) ;
} else if ( V_20 -> V_275 == V_280 ) {
V_20 -> V_185 = V_545 ;
F_259 ( V_20 , V_546 ) ;
}
break;
default:
F_263 ( V_20 ) ;
V_20 -> V_185 = V_186 ;
}
}
void F_267 ( struct V_8 * V_20 , struct V_128 * V_184 ,
T_3 V_153 )
{
F_21 ( L_59 , V_20 , V_184 , V_153 ) ;
if ( V_153 ) {
F_264 ( V_20 ) ;
F_263 ( V_20 ) ;
return;
}
if ( V_20 -> V_31 != V_61 ) {
if ( V_20 -> V_424 != V_425 )
F_265 ( V_20 , V_184 ) ;
} else {
F_266 ( V_20 , V_184 ) ;
}
}
void F_268 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_424 == V_425 ) {
if ( V_20 -> V_257 != V_258 )
return;
V_20 -> V_275 = V_277 ;
V_20 -> V_185 = V_187 ;
} else {
V_20 -> V_275 = V_277 ;
V_20 -> V_185 = V_541 ;
V_20 -> V_426 = 0 ;
F_126 ( V_20 ) ;
F_258 ( V_20 , 0 ) ;
}
}
static void F_269 ( struct V_8 * V_20 , int V_143 ,
T_3 V_424 , T_3 V_547 )
{
F_21 ( L_60 , V_20 , F_22 ( V_20 -> V_31 ) ,
V_424 , V_547 ) ;
V_20 -> V_78 = V_448 ;
if ( V_20 -> V_31 == V_64 ) {
if ( V_143 == V_311 ) {
V_20 -> V_424 = V_424 ;
F_125 ( V_20 , V_547 ) ;
} else {
F_124 ( V_20 ) ;
}
return;
}
if ( F_119 ( V_20 ) ) {
struct V_151 V_142 ;
char V_307 [ 128 ] ;
V_142 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_142 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( V_143 == V_311 ) {
V_142 . V_143 = F_16 ( V_311 ) ;
V_142 . V_153 = F_16 ( V_154 ) ;
} else {
V_142 . V_143 = F_16 ( V_489 ) ;
V_142 . V_153 = F_16 ( V_154 ) ;
}
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_479 ,
sizeof( V_142 ) , & V_142 ) ;
if ( V_143 == V_311 ) {
F_20 ( V_20 , V_62 ) ;
F_54 ( V_313 , & V_20 -> V_76 ) ;
F_80 ( V_20 -> V_10 , F_88 ( V_20 -> V_10 ) ,
V_314 ,
F_140 ( V_20 , V_307 ) , V_307 ) ;
V_20 -> V_315 ++ ;
}
}
}
static void F_270 ( struct V_8 * V_20 , T_3 V_424 ,
T_3 V_547 )
{
F_126 ( V_20 ) ;
V_20 -> V_426 = V_424 ;
V_20 -> V_185 = V_548 ;
F_258 ( V_20 , V_547 ) ;
}
static void F_271 ( struct V_8 * V_20 , int V_143 )
{
struct V_128 * V_184 = NULL ;
if ( V_184 ) {
if ( V_184 -> V_31 == V_61 ) {
V_20 -> V_188 = V_184 -> V_10 ;
V_20 -> V_188 -> V_138 = V_20 -> V_10 ;
V_20 -> V_185 = V_545 ;
F_259 ( V_20 , V_546 ) ;
F_267 ( V_20 , V_184 , V_546 ) ;
} else {
V_20 -> V_185 = V_540 ;
}
} else {
F_259 ( V_20 , V_549 ) ;
}
}
static void F_272 ( struct V_8 * V_20 , int V_143 )
{
if ( V_20 -> V_275 == V_280 ) {
T_3 V_550 ;
if ( V_143 == - V_26 )
V_550 = V_551 ;
else
V_550 = V_549 ;
F_259 ( V_20 , V_550 ) ;
}
V_20 -> V_275 = V_276 ;
V_20 -> V_185 = V_186 ;
F_174 ( V_20 ) ;
}
void F_273 ( struct V_8 * V_20 , int V_143 )
{
T_3 V_424 = V_20 -> V_424 ;
T_3 V_547 = V_20 -> V_547 ;
F_21 ( L_61 ,
V_20 , V_143 , V_424 , V_547 ) ;
if ( V_20 -> V_31 == V_147 || V_20 -> V_31 == V_552 ) {
F_46 ( V_20 ) ;
return;
}
if ( V_20 -> V_31 != V_61 ) {
F_269 ( V_20 , V_143 , V_424 , V_547 ) ;
} else if ( V_143 != V_546 ) {
F_272 ( V_20 , V_143 ) ;
} else {
switch ( V_20 -> V_275 ) {
case V_277 :
F_270 ( V_20 , V_424 ,
V_547 ) ;
break;
case V_280 :
F_271 ( V_20 , V_143 ) ;
break;
default:
F_272 ( V_20 , V_143 ) ;
break;
}
}
}
static inline int F_274 ( struct V_9 * V_10 ,
struct V_404 * V_405 ,
T_2 V_481 , void * V_176 )
{
struct V_526 * V_260 = V_176 ;
struct V_530 V_142 ;
struct V_8 * V_20 ;
T_2 V_527 = 0 ;
T_2 V_143 = V_549 ;
if ( V_481 != sizeof( * V_260 ) )
return - V_484 ;
V_527 = F_229 ( V_260 -> V_527 ) ;
F_21 ( L_62 , V_527 , V_260 -> V_525 ) ;
if ( ! V_10 -> V_250 )
return - V_26 ;
V_20 = F_9 ( V_10 , V_527 ) ;
if ( ! V_20 ) {
V_142 . V_527 = F_16 ( V_527 ) ;
V_142 . V_143 = F_16 ( V_549 ) ;
F_80 ( V_10 , V_405 -> V_16 , V_531 ,
sizeof( V_142 ) , & V_142 ) ;
return 0 ;
}
V_20 -> V_16 = V_405 -> V_16 ;
if ( V_20 -> V_14 < V_30 ||
V_20 -> V_257 == V_553 ||
( V_20 -> V_130 != V_133 &&
V_20 -> V_130 != V_137 ) ) {
V_143 = V_549 ;
goto V_554;
}
if ( V_20 -> V_424 == V_260 -> V_525 ) {
V_143 = V_555 ;
goto V_554;
}
if ( V_260 -> V_525 != V_425 ) {
struct V_248 * V_177 ;
V_177 = F_255 ( V_260 -> V_525 ) ;
if ( ! V_177 || V_177 -> V_520 != V_521 ||
! F_73 ( V_256 , & V_177 -> V_88 ) ) {
if ( V_177 )
F_256 ( V_177 ) ;
V_143 = V_551 ;
goto V_554;
}
F_256 ( V_177 ) ;
}
if ( ( F_94 ( V_20 ) ||
V_20 -> V_275 != V_276 ) &&
F_13 ( & V_10 -> V_2 -> V_18 , & V_10 -> V_2 -> V_139 ) > 0 ) {
V_143 = V_556 ;
goto V_554;
}
V_20 -> V_275 = V_280 ;
F_126 ( V_20 ) ;
V_20 -> V_426 = V_260 -> V_525 ;
V_527 = V_20 -> V_13 ;
if ( V_260 -> V_525 == V_425 ) {
if ( F_73 ( V_245 , & V_20 -> V_239 ) ) {
V_20 -> V_185 = V_542 ;
V_143 = V_557 ;
} else {
V_20 -> V_185 = V_545 ;
V_143 = V_546 ;
}
} else {
V_20 -> V_185 = V_187 ;
V_143 = V_557 ;
}
V_554:
F_259 ( V_20 , V_143 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static void F_275 ( struct V_9 * V_10 , T_2 V_527 , T_2 V_143 )
{
struct V_8 * V_20 ;
struct V_128 * V_184 = NULL ;
V_20 = F_5 ( V_10 , V_527 ) ;
if ( ! V_20 ) {
F_261 ( V_10 , V_527 ) ;
return;
}
F_70 ( V_20 ) ;
if ( V_143 == V_557 )
F_82 ( V_20 , V_558 ) ;
switch ( V_20 -> V_185 ) {
case V_539 :
V_20 -> V_185 = V_540 ;
break;
case V_541 :
if ( V_143 == V_557 ) {
break;
} else if ( F_73 ( V_245 ,
& V_20 -> V_239 ) ) {
V_20 -> V_185 = V_542 ;
} else {
V_20 -> V_185 = V_543 ;
F_260 ( V_20 , V_544 ) ;
}
break;
case V_548 :
if ( V_143 == V_546 ) {
V_20 -> V_185 = V_540 ;
} else {
V_20 -> V_185 = V_539 ;
}
if ( ! V_184 ) {
F_260 ( V_20 , V_535 ) ;
break;
}
if ( V_184 -> V_31 != V_61 )
break;
V_20 -> V_188 = V_184 -> V_10 ;
V_20 -> V_188 -> V_138 = V_20 -> V_10 ;
if ( V_143 == V_546 ) {
F_260 ( V_20 , V_544 ) ;
} else {
V_20 -> V_185 = V_541 ;
}
F_267 ( V_20 , V_184 , V_546 ) ;
break;
default:
V_20 -> V_426 = V_20 -> V_424 ;
F_127 ( V_20 ) ;
F_260 ( V_20 , V_535 ) ;
}
F_46 ( V_20 ) ;
}
static void F_276 ( struct V_9 * V_10 , T_3 V_16 , T_2 V_527 ,
T_2 V_143 )
{
struct V_8 * V_20 ;
V_20 = F_11 ( V_10 , V_16 ) ;
if ( ! V_20 ) {
F_261 ( V_10 , V_527 ) ;
return;
}
F_70 ( V_20 ) ;
if ( V_20 -> V_275 == V_277 ) {
if ( V_143 == V_556 ) {
V_20 -> V_275 = V_280 ;
} else {
V_20 -> V_426 = V_20 -> V_424 ;
F_127 ( V_20 ) ;
}
}
F_260 ( V_20 , V_535 ) ;
F_46 ( V_20 ) ;
}
static int F_277 ( struct V_9 * V_10 ,
struct V_404 * V_405 ,
T_2 V_481 , void * V_176 )
{
struct V_530 * V_142 = V_176 ;
T_2 V_527 , V_143 ;
if ( V_481 != sizeof( * V_142 ) )
return - V_484 ;
V_527 = F_229 ( V_142 -> V_527 ) ;
V_143 = F_229 ( V_142 -> V_143 ) ;
F_21 ( L_63 , V_527 , V_143 ) ;
if ( V_143 == V_546 || V_143 == V_557 )
F_275 ( V_10 , V_527 , V_143 ) ;
else
F_276 ( V_10 , V_405 -> V_16 , V_527 , V_143 ) ;
return 0 ;
}
static int F_278 ( struct V_9 * V_10 ,
struct V_404 * V_405 ,
T_2 V_481 , void * V_176 )
{
struct V_532 * V_533 = V_176 ;
struct V_8 * V_20 ;
T_2 V_527 , V_143 ;
if ( V_481 != sizeof( * V_533 ) )
return - V_484 ;
V_527 = F_229 ( V_533 -> V_527 ) ;
V_143 = F_229 ( V_533 -> V_143 ) ;
F_21 ( L_63 , V_527 , V_143 ) ;
V_20 = F_9 ( V_10 , V_527 ) ;
if ( ! V_20 ) {
F_262 ( V_10 , V_405 -> V_16 , V_527 ) ;
return 0 ;
}
if ( V_20 -> V_185 == V_545 ) {
if ( V_143 == V_544 ) {
V_20 -> V_424 = V_20 -> V_426 ;
if ( V_20 -> V_424 == V_425 )
F_263 ( V_20 ) ;
} else {
V_20 -> V_426 = V_20 -> V_424 ;
}
F_127 ( V_20 ) ;
}
F_262 ( V_10 , V_405 -> V_16 , V_527 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static inline int F_279 ( struct V_9 * V_10 ,
struct V_404 * V_405 ,
T_2 V_481 , void * V_176 )
{
struct V_536 * V_142 = V_176 ;
struct V_8 * V_20 ;
T_2 V_527 ;
if ( V_481 != sizeof( * V_142 ) )
return - V_484 ;
V_527 = F_229 ( V_142 -> V_527 ) ;
F_21 ( L_57 , V_527 ) ;
V_20 = F_5 ( V_10 , V_527 ) ;
if ( ! V_20 )
return 0 ;
F_70 ( V_20 ) ;
if ( V_20 -> V_185 == V_543 ) {
V_20 -> V_424 = V_20 -> V_426 ;
if ( V_20 -> V_424 == V_425 && V_20 -> V_127 )
F_263 ( V_20 ) ;
F_127 ( V_20 ) ;
}
F_46 ( V_20 ) ;
return 0 ;
}
static inline int F_280 ( T_2 V_559 , T_2 V_560 , T_2 V_561 ,
T_2 V_562 )
{
T_2 V_563 ;
if ( V_559 > V_560 || V_559 < 6 || V_560 > 3200 )
return - V_26 ;
if ( V_562 < 10 || V_562 > 3200 )
return - V_26 ;
if ( V_560 >= V_562 * 8 )
return - V_26 ;
V_563 = ( V_562 * 8 / V_560 ) - 1 ;
if ( V_561 > 499 || V_561 > V_563 )
return - V_26 ;
return 0 ;
}
static inline int F_281 ( struct V_9 * V_10 ,
struct V_404 * V_405 ,
T_2 V_481 , T_3 * V_176 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct F_281 * V_260 ;
struct V_564 V_142 ;
T_2 V_559 , V_560 , V_561 , V_562 ;
int V_21 ;
if ( ! ( V_2 -> V_565 & V_566 ) )
return - V_26 ;
if ( V_481 != sizeof( struct F_281 ) )
return - V_484 ;
V_260 = (struct F_281 * ) V_176 ;
V_559 = F_66 ( V_260 -> V_559 ) ;
V_560 = F_66 ( V_260 -> V_560 ) ;
V_561 = F_66 ( V_260 -> V_561 ) ;
V_562 = F_66 ( V_260 -> V_562 ) ;
F_21 ( L_64 ,
V_559 , V_560 , V_561 , V_562 ) ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_21 = F_280 ( V_559 , V_560 , V_561 , V_562 ) ;
if ( V_21 )
V_142 . V_143 = F_16 ( V_567 ) ;
else
V_142 . V_143 = F_16 ( V_568 ) ;
F_80 ( V_10 , V_405 -> V_16 , V_569 ,
sizeof( V_142 ) , & V_142 ) ;
if ( ! V_21 )
F_282 ( V_2 , V_559 , V_560 , V_561 , V_562 ) ;
return 0 ;
}
static int F_283 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
struct V_141 * V_142 = (struct V_141 * ) V_176 ;
T_2 V_13 , V_148 , V_95 , V_149 , V_143 ;
struct V_8 * V_20 ;
int V_21 ;
if ( V_481 < sizeof( * V_142 ) )
return - V_484 ;
V_13 = F_66 ( V_142 -> V_13 ) ;
V_148 = F_66 ( V_142 -> V_148 ) ;
V_95 = F_66 ( V_142 -> V_95 ) ;
V_149 = F_66 ( V_142 -> V_149 ) ;
V_143 = F_66 ( V_142 -> V_143 ) ;
if ( V_143 == V_311 && ( V_148 < 23 || V_95 < 23 ) )
return - V_484 ;
F_21 ( L_65 ,
V_13 , V_148 , V_95 , V_149 , V_143 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_10 ( V_10 , V_405 -> V_16 ) ;
if ( ! V_20 ) {
V_21 = - V_497 ;
goto V_498;
}
V_21 = 0 ;
F_7 ( V_20 ) ;
switch ( V_143 ) {
case V_311 :
V_20 -> V_16 = 0 ;
V_20 -> V_13 = V_13 ;
V_20 -> V_104 = V_148 ;
V_20 -> V_379 = V_95 ;
V_20 -> V_92 = V_149 ;
F_129 ( V_20 ) ;
break;
default:
F_69 ( V_20 , V_63 ) ;
break;
}
F_46 ( V_20 ) ;
V_498:
F_8 ( & V_10 -> V_15 ) ;
return V_21 ;
}
static inline int F_284 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
int V_21 = 0 ;
switch ( V_405 -> V_174 ) {
case V_502 :
F_236 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_261 :
V_21 = F_240 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_155 :
case V_479 :
F_242 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_314 :
V_21 = F_247 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_499 :
F_248 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_303 :
V_21 = F_250 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_510 :
F_251 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_570 :
F_80 ( V_10 , V_405 -> V_16 , V_571 , V_481 , V_176 ) ;
break;
case V_571 :
break;
case V_295 :
V_21 = F_252 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_514 :
F_253 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_264 :
V_21 = F_254 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_528 :
V_21 = F_274 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_531 :
F_277 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_534 :
V_21 = F_278 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_537 :
F_279 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
default:
F_285 ( L_66 , V_405 -> V_174 ) ;
V_21 = - V_26 ;
break;
}
return V_21 ;
}
static int F_286 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
struct V_284 * V_260 = (struct V_284 * ) V_176 ;
struct V_141 V_142 ;
struct V_8 * V_20 , * V_322 ;
T_2 V_13 , V_14 , V_149 , V_148 , V_95 ;
T_4 V_17 ;
T_3 V_143 ;
if ( V_481 != sizeof( * V_260 ) )
return - V_484 ;
V_14 = F_66 ( V_260 -> V_14 ) ;
V_148 = F_66 ( V_260 -> V_148 ) ;
V_95 = F_66 ( V_260 -> V_95 ) ;
V_17 = V_260 -> V_17 ;
V_13 = 0 ;
V_149 = 0 ;
if ( V_148 < 23 || V_95 < 23 )
return - V_484 ;
F_21 ( L_67 , F_66 ( V_17 ) ,
V_14 , V_148 , V_95 ) ;
V_322 = F_166 ( V_156 , V_17 , & V_10 -> V_2 -> V_18 ,
& V_10 -> V_2 -> V_139 , V_3 ) ;
if ( ! V_322 ) {
V_143 = V_146 ;
V_20 = NULL ;
goto V_488;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_322 ) ;
if ( ! F_287 ( V_10 -> V_2 , V_322 -> V_65 ) ) {
V_143 = V_572 ;
V_20 = NULL ;
goto V_573;
}
if ( F_2 ( V_10 , V_14 ) ) {
V_143 = V_489 ;
V_20 = NULL ;
goto V_573;
}
V_20 = V_322 -> V_32 -> V_324 ( V_322 ) ;
if ( ! V_20 ) {
V_143 = V_489 ;
goto V_573;
}
F_62 ( V_20 ) ;
F_78 ( & V_20 -> V_18 , & V_10 -> V_2 -> V_18 ) ;
F_78 ( & V_20 -> V_139 , & V_10 -> V_2 -> V_139 ) ;
V_20 -> V_326 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_326 ) ;
V_20 -> V_140 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_140 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_14 ;
V_20 -> V_104 = V_148 ;
V_20 -> V_379 = V_95 ;
V_20 -> V_92 = F_66 ( V_260 -> V_149 ) ;
F_65 ( V_10 , V_20 ) ;
V_13 = V_20 -> V_14 ;
V_149 = V_20 -> V_93 ;
F_82 ( V_20 , V_20 -> V_32 -> V_157 ( V_20 ) ) ;
V_20 -> V_16 = V_405 -> V_16 ;
if ( F_73 ( V_144 , & V_20 -> V_88 ) ) {
F_20 ( V_20 , V_158 ) ;
V_143 = V_308 ;
V_20 -> V_32 -> V_310 ( V_20 ) ;
} else {
F_129 ( V_20 ) ;
V_143 = V_311 ;
}
V_573:
F_46 ( V_322 ) ;
F_8 ( & V_10 -> V_15 ) ;
if ( V_143 == V_308 )
return 0 ;
V_488:
if ( V_20 ) {
V_142 . V_148 = F_16 ( V_20 -> V_96 ) ;
V_142 . V_95 = F_16 ( V_20 -> V_95 ) ;
} else {
V_142 . V_148 = 0 ;
V_142 . V_95 = 0 ;
}
V_142 . V_13 = F_16 ( V_13 ) ;
V_142 . V_149 = F_16 ( V_149 ) ;
V_142 . V_143 = F_16 ( V_143 ) ;
F_80 ( V_10 , V_405 -> V_16 , V_150 , sizeof( V_142 ) , & V_142 ) ;
return 0 ;
}
static inline int F_288 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
struct F_288 * V_574 ;
struct V_8 * V_20 ;
T_2 V_11 , V_149 , V_575 ;
if ( V_481 != sizeof( * V_574 ) )
return - V_484 ;
V_574 = (struct F_288 * ) V_176 ;
V_11 = F_66 ( V_574 -> V_11 ) ;
V_149 = F_66 ( V_574 -> V_149 ) ;
F_21 ( L_68 , V_11 , V_149 ) ;
V_20 = F_9 ( V_10 , V_11 ) ;
if ( ! V_20 )
return - V_497 ;
V_575 = V_576 - V_20 -> V_92 ;
if ( V_149 > V_575 ) {
F_285 ( L_69 ) ;
F_83 ( V_20 , V_306 ) ;
return 0 ;
}
V_20 -> V_92 += V_149 ;
while ( V_20 -> V_92 && ! F_171 ( & V_20 -> V_98 ) ) {
F_95 ( V_20 , F_172 ( & V_20 -> V_98 ) ) ;
V_20 -> V_92 -- ;
}
if ( V_20 -> V_92 )
V_20 -> V_32 -> V_577 ( V_20 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static inline int F_289 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
struct V_482 * V_483 = (struct V_482 * ) V_176 ;
struct V_8 * V_20 ;
if ( V_481 < sizeof( * V_483 ) )
return - V_484 ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_10 ( V_10 , V_405 -> V_16 ) ;
if ( ! V_20 )
goto V_24;
F_7 ( V_20 ) ;
F_69 ( V_20 , V_63 ) ;
F_46 ( V_20 ) ;
V_24:
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_290 ( struct V_9 * V_10 ,
struct V_404 * V_405 , T_2 V_481 ,
T_3 * V_176 )
{
int V_21 = 0 ;
switch ( V_405 -> V_174 ) {
case V_502 :
F_289 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_578 :
V_21 = F_281 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_569 :
break;
case V_150 :
F_283 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_286 :
V_21 = F_286 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_579 :
V_21 = F_288 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_303 :
V_21 = F_250 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
case V_510 :
F_251 ( V_10 , V_405 , V_481 , V_176 ) ;
break;
default:
F_285 ( L_70 , V_405 -> V_174 ) ;
V_21 = - V_26 ;
break;
}
return V_21 ;
}
static inline void F_291 ( struct V_9 * V_10 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_404 * V_405 ;
T_2 V_175 ;
int V_21 ;
if ( V_2 -> type != V_3 )
goto V_580;
if ( V_42 -> V_175 < V_406 )
goto V_580;
V_405 = ( void * ) V_42 -> V_176 ;
F_101 ( V_42 , V_406 ) ;
V_175 = F_229 ( V_405 -> V_175 ) ;
F_21 ( L_71 , V_405 -> V_174 , V_175 , V_405 -> V_16 ) ;
if ( V_175 != V_42 -> V_175 || ! V_405 -> V_16 ) {
F_21 ( L_72 ) ;
goto V_580;
}
V_21 = F_290 ( V_10 , V_405 , V_175 , V_42 -> V_176 ) ;
if ( V_21 ) {
struct V_482 V_483 ;
F_285 ( L_73 , V_21 ) ;
V_483 . V_60 = F_16 ( V_485 ) ;
F_80 ( V_10 , V_405 -> V_16 , V_502 ,
sizeof( V_483 ) , & V_483 ) ;
}
V_580:
F_96 ( V_42 ) ;
}
static inline void F_292 ( struct V_9 * V_10 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 * V_176 = V_42 -> V_176 ;
int V_175 = V_42 -> V_175 ;
struct V_404 V_405 ;
int V_21 ;
F_215 ( V_10 , V_42 ) ;
if ( V_2 -> type != V_103 )
goto V_580;
while ( V_175 >= V_406 ) {
T_2 V_481 ;
memcpy ( & V_405 , V_176 , V_406 ) ;
V_176 += V_406 ;
V_175 -= V_406 ;
V_481 = F_229 ( V_405 . V_175 ) ;
F_21 ( L_71 , V_405 . V_174 , V_481 ,
V_405 . V_16 ) ;
if ( V_481 > V_175 || ! V_405 . V_16 ) {
F_21 ( L_72 ) ;
break;
}
V_21 = F_284 ( V_10 , & V_405 , V_481 , V_176 ) ;
if ( V_21 ) {
struct V_482 V_483 ;
F_285 ( L_73 , V_21 ) ;
V_483 . V_60 = F_16 ( V_485 ) ;
F_80 ( V_10 , V_405 . V_16 , V_502 ,
sizeof( V_483 ) , & V_483 ) ;
}
V_176 += V_481 ;
V_175 -= V_481 ;
}
V_580:
F_96 ( V_42 ) ;
}
static int F_293 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
T_2 V_581 , V_582 ;
int V_583 ;
if ( F_73 ( V_226 , & V_20 -> V_88 ) )
V_583 = V_231 ;
else
V_583 = V_232 ;
if ( V_20 -> V_78 == V_79 ) {
F_294 ( V_42 , V_42 -> V_175 - V_236 ) ;
V_582 = F_102 ( V_42 -> V_176 + V_42 -> V_175 ) ;
V_581 = F_113 ( 0 , V_42 -> V_176 - V_583 , V_42 -> V_175 + V_583 ) ;
if ( V_581 != V_582 )
return - V_584 ;
}
return 0 ;
}
static void F_295 ( struct V_8 * V_20 )
{
struct V_192 V_43 ;
F_21 ( L_3 , V_20 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_200 = 1 ;
V_43 . V_196 = 1 ;
V_43 . V_193 = V_20 -> V_246 ;
F_54 ( V_238 , & V_20 -> V_239 ) ;
if ( F_73 ( V_245 , & V_20 -> V_239 ) ) {
V_43 . V_204 = V_242 ;
F_114 ( V_20 , & V_43 ) ;
}
if ( F_115 ( V_274 , & V_20 -> V_239 ) &&
V_20 -> V_357 > 0 )
F_25 ( V_20 ) ;
F_174 ( V_20 ) ;
if ( ! F_73 ( V_245 , & V_20 -> V_239 ) &&
F_73 ( V_238 , & V_20 -> V_239 ) ) {
V_43 . V_204 = V_240 ;
F_114 ( V_20 , & V_43 ) ;
}
}
static void F_296 ( struct V_38 * V_42 , struct V_38 * V_585 ,
struct V_38 * * V_586 )
{
if ( ! F_297 ( V_42 ) )
F_190 ( V_42 ) -> V_368 = V_585 ;
V_585 -> V_335 = NULL ;
( * V_586 ) -> V_335 = V_585 ;
* V_586 = V_585 ;
V_42 -> V_175 += V_585 -> V_175 ;
V_42 -> V_372 += V_585 -> V_175 ;
V_42 -> V_587 += V_585 -> V_587 ;
}
static int F_298 ( struct V_8 * V_20 , struct V_38 * V_42 ,
struct V_192 * V_43 )
{
int V_21 = - V_26 ;
switch ( V_43 -> V_207 ) {
case V_380 :
if ( V_20 -> V_89 )
break;
V_21 = V_20 -> V_32 -> V_402 ( V_20 , V_42 ) ;
break;
case V_381 :
if ( V_20 -> V_89 )
break;
V_20 -> V_91 = F_102 ( V_42 -> V_176 ) ;
F_101 ( V_42 , V_375 ) ;
if ( V_20 -> V_91 > V_20 -> V_96 ) {
V_21 = - V_384 ;
break;
}
if ( V_42 -> V_175 >= V_20 -> V_91 )
break;
V_20 -> V_89 = V_42 ;
V_20 -> V_90 = V_42 ;
V_42 = NULL ;
V_21 = 0 ;
break;
case V_383 :
if ( ! V_20 -> V_89 )
break;
F_296 ( V_20 -> V_89 , V_42 ,
& V_20 -> V_90 ) ;
V_42 = NULL ;
if ( V_20 -> V_89 -> V_175 >= V_20 -> V_91 )
break;
V_21 = 0 ;
break;
case V_382 :
if ( ! V_20 -> V_89 )
break;
F_296 ( V_20 -> V_89 , V_42 ,
& V_20 -> V_90 ) ;
V_42 = NULL ;
if ( V_20 -> V_89 -> V_175 != V_20 -> V_91 )
break;
V_21 = V_20 -> V_32 -> V_402 ( V_20 , V_20 -> V_89 ) ;
if ( ! V_21 ) {
V_20 -> V_89 = NULL ;
V_20 -> V_90 = NULL ;
V_20 -> V_91 = 0 ;
}
break;
}
if ( V_21 ) {
F_96 ( V_42 ) ;
F_96 ( V_20 -> V_89 ) ;
V_20 -> V_89 = NULL ;
V_20 -> V_90 = NULL ;
V_20 -> V_91 = 0 ;
}
return V_21 ;
}
static int F_299 ( struct V_8 * V_20 )
{
return 0 ;
}
void F_300 ( struct V_8 * V_20 , int V_588 )
{
T_3 V_392 ;
if ( V_20 -> V_130 != V_133 )
return;
V_392 = V_588 ? V_393 : V_395 ;
F_128 ( V_20 , NULL , NULL , V_392 ) ;
}
static int F_301 ( struct V_8 * V_20 )
{
int V_21 = 0 ;
F_21 ( L_3 , V_20 ) ;
while ( ! F_73 ( V_245 , & V_20 -> V_239 ) ) {
struct V_38 * V_42 ;
F_21 ( L_74 ,
V_20 -> V_246 , F_178 ( & V_20 -> V_134 ) ) ;
V_42 = F_31 ( & V_20 -> V_134 , V_20 -> V_246 ) ;
if ( ! V_42 )
break;
F_208 ( V_42 , & V_20 -> V_134 ) ;
V_20 -> V_246 = F_173 ( V_20 , V_20 -> V_246 ) ;
V_21 = F_298 ( V_20 , V_42 , & F_33 ( V_42 ) -> V_43 ) ;
if ( V_21 )
break;
}
if ( F_171 ( & V_20 -> V_134 ) ) {
V_20 -> V_272 = V_361 ;
F_185 ( V_20 ) ;
}
return V_21 ;
}
static void F_302 ( struct V_8 * V_20 ,
struct V_192 * V_43 )
{
struct V_38 * V_42 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( V_43 -> V_193 == V_20 -> V_351 ) {
F_21 ( L_75 , V_43 -> V_193 ) ;
F_83 ( V_20 , V_306 ) ;
return;
}
V_42 = F_31 ( & V_20 -> V_98 , V_43 -> V_193 ) ;
if ( V_42 == NULL ) {
F_21 ( L_76 ,
V_43 -> V_193 ) ;
return;
}
if ( V_20 -> V_80 != 0 && F_33 ( V_42 ) -> V_43 . V_266 >= V_20 -> V_80 ) {
F_21 ( L_21 , V_20 -> V_80 ) ;
F_83 ( V_20 , V_306 ) ;
return;
}
F_116 ( V_274 , & V_20 -> V_239 ) ;
if ( V_43 -> V_201 ) {
F_213 ( V_20 , V_43 ) ;
F_54 ( V_238 , & V_20 -> V_239 ) ;
F_182 ( V_20 , V_43 ) ;
F_174 ( V_20 ) ;
if ( V_20 -> V_270 == V_397 ) {
F_54 ( V_269 , & V_20 -> V_239 ) ;
V_20 -> V_589 = V_43 -> V_193 ;
}
} else {
F_214 ( V_20 , V_43 ) ;
if ( V_43 -> V_196 ) {
if ( V_20 -> V_589 != V_43 -> V_193 ||
! F_115 ( V_269 ,
& V_20 -> V_239 ) )
F_182 ( V_20 , V_43 ) ;
} else {
F_182 ( V_20 , V_43 ) ;
if ( V_20 -> V_270 == V_397 ) {
F_54 ( V_269 , & V_20 -> V_239 ) ;
V_20 -> V_589 = V_43 -> V_193 ;
}
}
}
}
static void F_303 ( struct V_8 * V_20 ,
struct V_192 * V_43 )
{
struct V_38 * V_42 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( V_43 -> V_193 == V_20 -> V_351 ) {
F_21 ( L_75 , V_43 -> V_193 ) ;
F_83 ( V_20 , V_306 ) ;
return;
}
V_42 = F_31 ( & V_20 -> V_98 , V_43 -> V_193 ) ;
if ( V_20 -> V_80 && V_42 &&
F_33 ( V_42 ) -> V_43 . V_266 >= V_20 -> V_80 ) {
F_21 ( L_21 , V_20 -> V_80 ) ;
F_83 ( V_20 , V_306 ) ;
return;
}
F_116 ( V_274 , & V_20 -> V_239 ) ;
F_213 ( V_20 , V_43 ) ;
if ( V_43 -> V_196 ) {
if ( ! F_115 ( V_268 , & V_20 -> V_239 ) )
F_183 ( V_20 , V_43 ) ;
} else {
F_183 ( V_20 , V_43 ) ;
F_174 ( V_20 ) ;
if ( V_20 -> V_270 == V_397 )
F_54 ( V_268 , & V_20 -> V_239 ) ;
}
}
static T_3 F_304 ( struct V_8 * V_20 , T_2 V_44 )
{
F_21 ( L_77 , V_20 , V_44 ) ;
F_21 ( L_78 , V_20 -> V_244 ,
V_20 -> V_267 ) ;
if ( V_20 -> V_272 == V_394 ) {
if ( F_186 ( V_20 , V_44 , V_20 -> V_244 ) >=
V_20 -> V_82 ) {
if ( V_20 -> V_82 <= ( ( V_20 -> V_84 + 1 ) >> 1 ) ) {
F_21 ( L_79 ) ;
return V_590 ;
} else {
F_21 ( L_80 ) ;
return V_591 ;
}
}
if ( V_20 -> V_135 . V_40 == V_44 ) {
F_21 ( L_81 ) ;
return V_592 ;
}
if ( F_31 ( & V_20 -> V_134 , V_44 ) ) {
F_21 ( L_82 ) ;
return V_593 ;
}
if ( F_39 ( & V_20 -> V_135 , V_44 ) ) {
F_21 ( L_83 ) ;
return V_594 ;
}
}
if ( V_20 -> V_267 == V_44 ) {
if ( F_186 ( V_20 , V_44 , V_20 -> V_244 ) >=
V_20 -> V_82 ) {
F_21 ( L_84 ) ;
return V_591 ;
} else {
F_21 ( L_85 ) ;
return V_595 ;
}
}
if ( F_186 ( V_20 , V_44 , V_20 -> V_244 ) <
F_186 ( V_20 , V_20 -> V_267 , V_20 -> V_244 ) ) {
F_21 ( L_86 ) ;
return V_596 ;
}
if ( F_186 ( V_20 , V_44 , V_20 -> V_244 ) >= V_20 -> V_82 ) {
if ( V_20 -> V_82 <= ( ( V_20 -> V_84 + 1 ) >> 1 ) ) {
F_21 ( L_87 ) ;
return V_590 ;
} else {
F_21 ( L_84 ) ;
return V_591 ;
}
} else {
F_21 ( L_88 ) ;
return V_597 ;
}
}
static int F_305 ( struct V_8 * V_20 ,
struct V_192 * V_43 ,
struct V_38 * V_42 , T_3 V_392 )
{
int V_21 = 0 ;
bool V_598 = false ;
F_21 ( L_89 , V_20 , V_43 , V_42 ,
V_392 ) ;
switch ( V_392 ) {
case V_599 :
switch ( F_304 ( V_20 , V_43 -> V_44 ) ) {
case V_595 :
F_213 ( V_20 , V_43 ) ;
if ( F_73 ( V_245 , & V_20 -> V_239 ) ) {
F_21 ( L_90 ,
V_43 -> V_44 ) ;
break;
}
V_20 -> V_267 = F_173 ( V_20 ,
V_43 -> V_44 ) ;
V_20 -> V_246 = V_20 -> V_267 ;
V_598 = true ;
V_21 = F_298 ( V_20 , V_42 , V_43 ) ;
if ( V_21 )
break;
if ( V_43 -> V_196 ) {
if ( ! F_115 ( V_268 ,
& V_20 -> V_239 ) ) {
V_43 -> V_196 = 0 ;
F_183 ( V_20 , V_43 ) ;
F_174 ( V_20 ) ;
}
}
if ( ! F_73 ( V_245 , & V_20 -> V_239 ) )
F_185 ( V_20 ) ;
break;
case V_597 :
F_213 ( V_20 , V_43 ) ;
if ( F_73 ( V_245 , & V_20 -> V_239 ) ) {
F_21 ( L_91 ,
V_43 -> V_44 ) ;
break;
}
F_306 ( & V_20 -> V_134 , V_42 ) ;
V_598 = true ;
F_21 ( L_92 , V_42 ,
F_178 ( & V_20 -> V_134 ) ) ;
F_116 ( V_269 , & V_20 -> V_239 ) ;
F_41 ( & V_20 -> V_135 ) ;
F_204 ( V_20 , V_43 -> V_44 ) ;
V_20 -> V_272 = V_394 ;
break;
case V_596 :
F_213 ( V_20 , V_43 ) ;
break;
case V_590 :
break;
case V_591 :
default:
F_83 ( V_20 , V_306 ) ;
break;
}
break;
case V_600 :
F_213 ( V_20 , V_43 ) ;
if ( V_43 -> V_196 ) {
F_116 ( V_274 , & V_20 -> V_239 ) ;
if ( ! F_115 ( V_268 , & V_20 -> V_239 ) &&
! F_94 ( V_20 ) ) {
V_43 -> V_196 = 0 ;
F_183 ( V_20 , V_43 ) ;
}
F_174 ( V_20 ) ;
} else if ( V_43 -> V_201 ) {
F_295 ( V_20 ) ;
} else {
if ( F_115 ( V_274 ,
& V_20 -> V_239 ) &&
V_20 -> V_357 )
F_25 ( V_20 ) ;
F_174 ( V_20 ) ;
}
break;
case V_601 :
F_54 ( V_274 , & V_20 -> V_239 ) ;
F_213 ( V_20 , V_43 ) ;
if ( V_43 && V_43 -> V_201 ) {
F_54 ( V_238 , & V_20 -> V_239 ) ;
F_118 ( V_20 , 0 ) ;
}
F_30 ( V_20 ) ;
F_41 ( & V_20 -> V_136 ) ;
break;
case V_602 :
F_303 ( V_20 , V_43 ) ;
break;
case V_603 :
F_302 ( V_20 , V_43 ) ;
break;
default:
break;
}
if ( V_42 && ! V_598 ) {
F_21 ( L_93 , V_42 ) ;
F_96 ( V_42 ) ;
}
return V_21 ;
}
static int F_307 ( struct V_8 * V_20 ,
struct V_192 * V_43 ,
struct V_38 * V_42 , T_3 V_392 )
{
int V_21 = 0 ;
T_2 V_44 = V_43 -> V_44 ;
bool V_598 = false ;
F_21 ( L_89 , V_20 , V_43 , V_42 ,
V_392 ) ;
switch ( V_392 ) {
case V_599 :
switch ( F_304 ( V_20 , V_44 ) ) {
case V_595 :
F_213 ( V_20 , V_43 ) ;
F_306 ( & V_20 -> V_134 , V_42 ) ;
V_598 = true ;
F_21 ( L_92 , V_42 ,
F_178 ( & V_20 -> V_134 ) ) ;
V_20 -> V_267 = F_173 ( V_20 , V_44 ) ;
break;
case V_592 :
F_40 ( & V_20 -> V_135 ) ;
F_213 ( V_20 , V_43 ) ;
F_306 ( & V_20 -> V_134 , V_42 ) ;
V_598 = true ;
F_21 ( L_92 , V_42 ,
F_178 ( & V_20 -> V_134 ) ) ;
V_21 = F_301 ( V_20 ) ;
if ( V_21 )
break;
break;
case V_597 :
F_306 ( & V_20 -> V_134 , V_42 ) ;
V_598 = true ;
F_21 ( L_92 , V_42 ,
F_178 ( & V_20 -> V_134 ) ) ;
F_213 ( V_20 , V_43 ) ;
F_204 ( V_20 , V_43 -> V_44 ) ;
break;
case V_594 :
F_306 ( & V_20 -> V_134 , V_42 ) ;
V_598 = true ;
F_21 ( L_92 , V_42 ,
F_178 ( & V_20 -> V_134 ) ) ;
F_213 ( V_20 , V_43 ) ;
F_206 ( V_20 , V_43 -> V_44 ) ;
break;
case V_593 :
F_213 ( V_20 , V_43 ) ;
break;
case V_596 :
break;
case V_590 :
break;
case V_591 :
default:
F_83 ( V_20 , V_306 ) ;
break;
}
break;
case V_600 :
F_213 ( V_20 , V_43 ) ;
if ( V_43 -> V_196 ) {
F_116 ( V_274 , & V_20 -> V_239 ) ;
if ( ! F_115 ( V_268 ,
& V_20 -> V_239 ) ) {
V_43 -> V_196 = 0 ;
F_183 ( V_20 , V_43 ) ;
}
F_174 ( V_20 ) ;
} else if ( V_43 -> V_201 ) {
if ( F_115 ( V_274 ,
& V_20 -> V_239 ) &&
V_20 -> V_357 ) {
F_25 ( V_20 ) ;
}
F_54 ( V_238 , & V_20 -> V_239 ) ;
F_205 ( V_20 ) ;
} else {
if ( F_115 ( V_274 ,
& V_20 -> V_239 ) &&
V_20 -> V_357 )
F_25 ( V_20 ) ;
F_185 ( V_20 ) ;
}
break;
case V_601 :
F_54 ( V_274 , & V_20 -> V_239 ) ;
F_213 ( V_20 , V_43 ) ;
if ( V_43 -> V_201 ) {
F_205 ( V_20 ) ;
} else {
struct V_192 V_604 ;
memset ( & V_604 , 0 , sizeof( V_604 ) ) ;
V_604 . V_200 = 1 ;
V_604 . V_204 = V_240 ;
V_604 . V_193 = V_20 -> V_246 ;
F_114 ( V_20 , & V_604 ) ;
}
break;
case V_602 :
F_303 ( V_20 , V_43 ) ;
break;
case V_603 :
F_302 ( V_20 , V_43 ) ;
break;
}
if ( V_42 && ! V_598 ) {
F_21 ( L_93 , V_42 ) ;
F_96 ( V_42 ) ;
}
return V_21 ;
}
static int F_308 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_272 = V_361 ;
if ( V_20 -> V_188 )
V_20 -> V_10 -> V_148 = V_20 -> V_188 -> V_177 -> V_523 ;
else
V_20 -> V_10 -> V_148 = V_20 -> V_10 -> V_2 -> V_177 -> V_605 ;
return F_299 ( V_20 ) ;
}
static int F_309 ( struct V_8 * V_20 ,
struct V_192 * V_43 ,
struct V_38 * V_42 , T_3 V_392 )
{
int V_21 ;
F_21 ( L_89 , V_20 , V_43 , V_42 ,
V_392 ) ;
if ( ! V_43 -> V_201 )
return - V_484 ;
F_207 ( V_20 , V_43 -> V_193 ) ;
if ( ! F_171 ( & V_20 -> V_98 ) )
V_20 -> V_356 = F_211 ( & V_20 -> V_98 ) ;
else
V_20 -> V_356 = NULL ;
V_20 -> V_351 = V_43 -> V_193 ;
V_20 -> V_357 = 0 ;
V_21 = F_308 ( V_20 ) ;
if ( V_21 )
return V_21 ;
F_54 ( V_238 , & V_20 -> V_239 ) ;
F_295 ( V_20 ) ;
if ( V_392 == V_599 )
return - V_484 ;
return F_305 ( V_20 , V_43 , NULL , V_392 ) ;
}
static int F_310 ( struct V_8 * V_20 ,
struct V_192 * V_43 ,
struct V_38 * V_42 , T_3 V_392 )
{
int V_21 ;
if ( ! V_43 -> V_196 )
return - V_484 ;
F_116 ( V_274 , & V_20 -> V_239 ) ;
V_20 -> V_272 = V_361 ;
F_207 ( V_20 , V_43 -> V_193 ) ;
if ( ! F_171 ( & V_20 -> V_98 ) )
V_20 -> V_356 = F_211 ( & V_20 -> V_98 ) ;
else
V_20 -> V_356 = NULL ;
V_20 -> V_351 = V_43 -> V_193 ;
V_20 -> V_357 = 0 ;
if ( V_20 -> V_188 )
V_20 -> V_10 -> V_148 = V_20 -> V_188 -> V_177 -> V_523 ;
else
V_20 -> V_10 -> V_148 = V_20 -> V_10 -> V_2 -> V_177 -> V_605 ;
V_21 = F_299 ( V_20 ) ;
if ( ! V_21 )
V_21 = F_305 ( V_20 , V_43 , V_42 , V_392 ) ;
return V_21 ;
}
static bool F_311 ( struct V_8 * V_20 , T_2 V_193 )
{
T_2 V_606 ;
V_606 = F_186 ( V_20 , V_20 -> V_351 , V_20 -> V_391 ) ;
return F_186 ( V_20 , V_20 -> V_351 , V_193 ) <= V_606 ;
}
static int F_312 ( struct V_8 * V_20 , struct V_192 * V_43 ,
struct V_38 * V_42 , T_3 V_392 )
{
int V_21 = 0 ;
F_21 ( L_94 , V_20 ,
V_43 , V_42 , V_392 , V_20 -> V_272 ) ;
if ( F_311 ( V_20 , V_43 -> V_193 ) ) {
switch ( V_20 -> V_272 ) {
case V_361 :
V_21 = F_305 ( V_20 , V_43 , V_42 , V_392 ) ;
break;
case V_394 :
V_21 = F_307 ( V_20 , V_43 , V_42 ,
V_392 ) ;
break;
case V_281 :
V_21 = F_309 ( V_20 , V_43 , V_42 , V_392 ) ;
break;
case V_279 :
V_21 = F_310 ( V_20 , V_43 , V_42 , V_392 ) ;
break;
default:
break;
}
} else {
F_21 ( L_95 ,
V_43 -> V_193 , V_20 -> V_351 ,
V_20 -> V_391 ) ;
F_83 ( V_20 , V_306 ) ;
}
return V_21 ;
}
static int F_313 ( struct V_8 * V_20 , struct V_192 * V_43 ,
struct V_38 * V_42 )
{
int V_21 = 0 ;
F_21 ( L_96 , V_20 , V_43 , V_42 ,
V_20 -> V_272 ) ;
if ( F_304 ( V_20 , V_43 -> V_44 ) ==
V_595 ) {
F_213 ( V_20 , V_43 ) ;
F_21 ( L_97 , V_20 -> V_246 ,
F_173 ( V_20 , V_20 -> V_246 ) ) ;
V_20 -> V_246 = F_173 ( V_20 , V_20 -> V_246 ) ;
F_298 ( V_20 , V_42 , V_43 ) ;
} else {
if ( V_20 -> V_89 ) {
F_96 ( V_20 -> V_89 ) ;
V_20 -> V_89 = NULL ;
}
V_20 -> V_90 = NULL ;
V_20 -> V_91 = 0 ;
if ( V_42 ) {
F_21 ( L_93 , V_42 ) ;
F_96 ( V_42 ) ;
}
}
V_20 -> V_244 = V_43 -> V_44 ;
V_20 -> V_267 = F_173 ( V_20 , V_43 -> V_44 ) ;
return V_21 ;
}
static int F_314 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
struct V_192 * V_43 = & F_33 ( V_42 ) -> V_43 ;
T_2 V_175 ;
T_3 V_392 ;
F_99 ( V_20 , V_42 ) ;
V_175 = V_42 -> V_175 ;
if ( F_293 ( V_20 , V_42 ) )
goto V_580;
if ( ! V_43 -> V_200 && V_43 -> V_207 == V_381 )
V_175 -= V_375 ;
if ( V_20 -> V_78 == V_79 )
V_175 -= V_236 ;
if ( V_175 > V_20 -> V_95 ) {
F_83 ( V_20 , V_306 ) ;
goto V_580;
}
if ( ! V_43 -> V_200 ) {
int V_21 ;
F_21 ( L_98 ,
V_43 -> V_207 , V_43 -> V_193 , V_43 -> V_196 ,
V_43 -> V_44 ) ;
if ( V_43 -> V_196 && V_20 -> V_270 != V_397 )
goto V_580;
if ( V_20 -> V_130 != V_137 ) {
V_392 = V_599 ;
V_21 = F_312 ( V_20 , V_43 , V_42 , V_392 ) ;
} else {
V_21 = F_313 ( V_20 , V_43 , V_42 ) ;
}
if ( V_21 )
F_83 ( V_20 , V_306 ) ;
} else {
const T_3 V_607 [ 4 ] = {
V_600 , V_602 ,
V_601 , V_603
} ;
if ( V_20 -> V_130 == V_137 )
goto V_580;
F_21 ( L_99 ,
V_43 -> V_193 , V_43 -> V_196 , V_43 -> V_201 ,
V_43 -> V_204 ) ;
if ( V_175 != 0 ) {
F_285 ( L_100 , V_175 ) ;
F_83 ( V_20 , V_306 ) ;
goto V_580;
}
if ( V_43 -> V_196 && ( V_43 -> V_201 ||
V_20 -> V_270 != V_397 ) )
goto V_580;
V_392 = V_607 [ V_43 -> V_204 ] ;
if ( F_312 ( V_20 , V_43 , V_42 , V_392 ) )
F_83 ( V_20 , V_306 ) ;
}
return 0 ;
V_580:
F_96 ( V_42 ) ;
return 0 ;
}
static void F_315 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct F_288 V_574 ;
T_2 V_608 ;
if ( V_20 -> V_93 >= ( V_94 + 1 ) / 2 )
return;
V_608 = V_94 - V_20 -> V_93 ;
F_21 ( L_101 , V_20 , V_608 ) ;
V_20 -> V_93 += V_608 ;
V_574 . V_11 = F_16 ( V_20 -> V_14 ) ;
V_574 . V_149 = F_16 ( V_608 ) ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_579 , sizeof( V_574 ) , & V_574 ) ;
}
static int F_316 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
int V_21 ;
if ( ! V_20 -> V_93 ) {
F_285 ( L_102 ) ;
F_83 ( V_20 , V_306 ) ;
return - V_609 ;
}
if ( V_20 -> V_96 < V_42 -> V_175 ) {
F_285 ( L_103 ) ;
return - V_609 ;
}
V_20 -> V_93 -- ;
F_21 ( L_104 , V_20 -> V_93 + 1 , V_20 -> V_93 ) ;
F_315 ( V_20 ) ;
V_21 = 0 ;
if ( ! V_20 -> V_89 ) {
T_2 V_91 ;
V_91 = F_102 ( V_42 -> V_176 ) ;
F_101 ( V_42 , V_375 ) ;
F_21 ( L_105 ,
V_91 , V_42 -> V_175 , V_20 -> V_96 ) ;
if ( V_91 > V_20 -> V_96 ) {
F_285 ( L_106 ) ;
V_21 = - V_384 ;
goto V_610;
}
if ( V_42 -> V_175 > V_91 ) {
F_285 ( L_107 ) ;
V_21 = - V_26 ;
goto V_610;
}
if ( V_42 -> V_175 == V_91 )
return V_20 -> V_32 -> V_402 ( V_20 , V_42 ) ;
V_20 -> V_89 = V_42 ;
V_20 -> V_91 = V_91 ;
V_20 -> V_90 = V_42 ;
return 0 ;
}
F_21 ( L_108 ,
V_20 -> V_89 -> V_175 , V_42 -> V_175 , V_20 -> V_91 ) ;
if ( V_20 -> V_89 -> V_175 + V_42 -> V_175 > V_20 -> V_91 ) {
F_285 ( L_107 ) ;
V_21 = - V_26 ;
goto V_610;
}
F_296 ( V_20 -> V_89 , V_42 , & V_20 -> V_90 ) ;
V_42 = NULL ;
if ( V_20 -> V_89 -> V_175 == V_20 -> V_91 ) {
V_21 = V_20 -> V_32 -> V_402 ( V_20 , V_20 -> V_89 ) ;
if ( ! V_21 ) {
V_20 -> V_89 = NULL ;
V_20 -> V_90 = NULL ;
V_20 -> V_91 = 0 ;
}
}
V_610:
if ( V_21 ) {
F_96 ( V_42 ) ;
F_96 ( V_20 -> V_89 ) ;
V_20 -> V_89 = NULL ;
V_20 -> V_90 = NULL ;
V_20 -> V_91 = 0 ;
}
return 0 ;
}
static void F_317 ( struct V_9 * V_10 , T_2 V_11 ,
struct V_38 * V_42 )
{
struct V_8 * V_20 ;
V_20 = F_5 ( V_10 , V_11 ) ;
if ( ! V_20 ) {
if ( V_11 == V_125 ) {
V_20 = F_318 ( V_10 , V_42 ) ;
if ( ! V_20 ) {
F_96 ( V_42 ) ;
return;
}
F_7 ( V_20 ) ;
} else {
F_21 ( L_109 , V_11 ) ;
F_96 ( V_42 ) ;
return;
}
}
F_21 ( L_110 , V_20 , V_42 -> V_175 ) ;
if ( V_20 -> V_31 != V_61 )
goto V_580;
switch ( V_20 -> V_130 ) {
case V_132 :
if ( F_316 ( V_20 , V_42 ) < 0 )
goto V_580;
goto V_24;
case V_131 :
if ( V_20 -> V_96 < V_42 -> V_175 ) {
F_285 ( L_111 ) ;
goto V_580;
}
if ( ! V_20 -> V_32 -> V_402 ( V_20 , V_42 ) )
goto V_24;
break;
case V_133 :
case V_137 :
F_314 ( V_20 , V_42 ) ;
goto V_24;
default:
F_21 ( L_112 , V_20 , V_20 -> V_130 ) ;
break;
}
V_580:
F_96 ( V_42 ) ;
V_24:
F_46 ( V_20 ) ;
}
static void F_319 ( struct V_9 * V_10 , T_4 V_17 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 ;
if ( V_2 -> type != V_103 )
goto V_580;
V_20 = F_166 ( 0 , V_17 , & V_2 -> V_18 , & V_2 -> V_139 ,
V_103 ) ;
if ( ! V_20 )
goto V_580;
F_21 ( L_110 , V_20 , V_42 -> V_175 ) ;
if ( V_20 -> V_31 != V_611 && V_20 -> V_31 != V_61 )
goto V_580;
if ( V_20 -> V_96 < V_42 -> V_175 )
goto V_580;
F_78 ( & F_33 ( V_42 ) -> V_612 , & V_2 -> V_139 ) ;
F_33 ( V_42 ) -> V_17 = V_17 ;
if ( ! V_20 -> V_32 -> V_402 ( V_20 , V_42 ) )
return;
V_580:
F_96 ( V_42 ) ;
}
static void F_320 ( struct V_9 * V_10 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 ;
if ( V_2 -> type != V_3 )
goto V_580;
V_20 = F_141 ( V_61 , V_323 ,
& V_2 -> V_18 , & V_2 -> V_139 ) ;
if ( ! V_20 )
goto V_580;
F_21 ( L_110 , V_20 , V_42 -> V_175 ) ;
if ( F_144 ( V_2 -> V_177 , & V_2 -> V_139 , V_2 -> V_140 ) )
goto V_580;
if ( V_20 -> V_96 < V_42 -> V_175 )
goto V_580;
if ( ! V_20 -> V_32 -> V_402 ( V_20 , V_42 ) )
return;
V_580:
F_96 ( V_42 ) ;
}
static void F_321 ( struct V_9 * V_10 , struct V_38 * V_42 )
{
struct V_233 * V_234 = ( void * ) V_42 -> V_176 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_11 , V_175 ;
T_4 V_17 ;
if ( V_2 -> V_31 != V_61 ) {
F_21 ( L_113 ) ;
F_306 ( & V_10 -> V_343 , V_42 ) ;
return;
}
F_101 ( V_42 , V_230 ) ;
V_11 = F_66 ( V_234 -> V_11 ) ;
V_175 = F_66 ( V_234 -> V_175 ) ;
if ( V_175 != V_42 -> V_175 ) {
F_96 ( V_42 ) ;
return;
}
F_21 ( L_114 , V_175 , V_11 ) ;
switch ( V_11 ) {
case V_109 :
F_292 ( V_10 , V_42 ) ;
break;
case V_107 :
V_17 = F_322 ( ( T_4 * ) V_42 -> V_176 ) ;
F_101 ( V_42 , V_373 ) ;
F_319 ( V_10 , V_17 , V_42 ) ;
break;
case V_323 :
F_320 ( V_10 , V_42 ) ;
break;
case V_407 :
F_291 ( V_10 , V_42 ) ;
break;
case V_613 :
if ( F_323 ( V_10 , V_42 ) )
F_156 ( V_10 -> V_2 , V_614 ) ;
break;
case V_615 :
F_324 ( V_10 , V_42 ) ;
break;
default:
F_317 ( V_10 , V_11 , V_42 ) ;
break;
}
}
static void F_325 ( struct V_57 * V_58 )
{
struct V_9 * V_10 = F_44 ( V_58 , struct V_9 ,
V_330 ) ;
struct V_38 * V_42 ;
F_21 ( L_15 ) ;
while ( ( V_42 = F_172 ( & V_10 -> V_343 ) ) )
F_321 ( V_10 , V_42 ) ;
}
static struct V_9 * F_326 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_138 ;
struct V_128 * V_184 ;
if ( V_10 )
return V_10 ;
V_184 = F_327 ( V_2 ) ;
if ( ! V_184 )
return NULL ;
V_10 = F_49 ( sizeof( struct V_9 ) , V_51 ) ;
if ( ! V_10 ) {
F_158 ( V_184 ) ;
return NULL ;
}
F_53 ( & V_10 -> V_346 ) ;
V_2 -> V_138 = V_10 ;
V_10 -> V_2 = V_2 ;
F_328 ( V_10 -> V_2 ) ;
V_10 -> V_184 = V_184 ;
F_21 ( L_115 , V_2 , V_10 , V_184 ) ;
switch ( V_2 -> type ) {
case V_3 :
if ( V_2 -> V_177 -> V_616 ) {
V_10 -> V_148 = V_2 -> V_177 -> V_616 ;
break;
}
default:
V_10 -> V_148 = V_2 -> V_177 -> V_605 ;
break;
}
V_10 -> V_296 = 0 ;
if ( V_2 -> type == V_103 )
V_10 -> V_250 = F_73 ( V_617 ,
& V_2 -> V_177 -> V_494 ) ;
F_329 ( & V_10 -> V_70 ) ;
F_50 ( & V_10 -> V_15 ) ;
F_330 ( & V_10 -> V_122 ) ;
F_330 ( & V_10 -> V_340 ) ;
if ( V_2 -> type == V_3 )
F_52 ( & V_10 -> V_345 , F_162 ) ;
else
F_52 ( & V_10 -> V_293 , F_148 ) ;
F_64 ( & V_10 -> V_343 ) ;
F_331 ( & V_10 -> V_330 , F_325 ) ;
V_10 -> V_99 = V_100 ;
return V_10 ;
}
static bool F_332 ( T_2 V_17 , T_3 V_140 ) {
if ( ! V_17 )
return false ;
if ( F_333 ( V_140 ) )
return ( V_17 <= 0x00ff ) ;
return ( ( V_17 & 0x0101 ) == 0x0001 ) ;
}
int F_334 ( struct V_8 * V_20 , T_4 V_17 , T_2 V_11 ,
T_5 * V_139 , T_3 V_140 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_248 * V_177 ;
T_1 V_171 ;
int V_21 ;
F_21 ( L_116 , & V_20 -> V_18 , V_139 ,
V_140 , F_66 ( V_17 ) ) ;
V_177 = F_335 ( V_139 , & V_20 -> V_18 ) ;
if ( ! V_177 )
return - V_618 ;
F_150 ( V_177 ) ;
F_7 ( V_20 ) ;
if ( ! F_332 ( F_66 ( V_17 ) , V_140 ) && ! V_11 &&
V_20 -> V_101 != V_159 ) {
V_21 = - V_26 ;
goto V_24;
}
if ( V_20 -> V_101 == V_102 && ! V_17 ) {
V_21 = - V_26 ;
goto V_24;
}
if ( V_20 -> V_101 == V_108 && ! V_11 ) {
V_21 = - V_26 ;
goto V_24;
}
switch ( V_20 -> V_130 ) {
case V_131 :
break;
case V_132 :
F_62 ( V_20 ) ;
break;
case V_133 :
case V_137 :
if ( ! V_299 )
break;
default:
V_21 = - V_619 ;
goto V_24;
}
switch ( V_20 -> V_31 ) {
case V_64 :
case V_158 :
case V_62 :
V_21 = 0 ;
goto V_24;
case V_61 :
V_21 = - V_620 ;
goto V_24;
case V_73 :
case V_611 :
break;
default:
V_21 = - V_387 ;
goto V_24;
}
F_78 ( & V_20 -> V_139 , V_139 ) ;
V_20 -> V_140 = V_140 ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_11 ;
V_171 = F_84 ( V_20 ) ;
if ( F_333 ( V_140 ) ) {
if ( V_140 == V_5 )
V_140 = V_4 ;
else
V_140 = V_621 ;
V_2 = F_336 ( V_177 , V_139 , V_140 , V_20 -> V_65 ,
V_171 ) ;
} else {
V_2 = F_337 ( V_177 , V_139 , V_20 -> V_65 , V_171 ) ;
}
if ( F_117 ( V_2 ) ) {
V_21 = F_191 ( V_2 ) ;
goto V_24;
}
V_10 = F_326 ( V_2 ) ;
if ( ! V_10 ) {
F_71 ( V_2 ) ;
V_21 = - V_52 ;
goto V_24;
}
if ( V_11 && F_2 ( V_10 , V_11 ) ) {
F_71 ( V_2 ) ;
V_21 = - V_622 ;
goto V_24;
}
F_78 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
V_20 -> V_326 = F_1 ( V_2 , V_2 -> V_326 ) ;
F_46 ( V_20 ) ;
F_68 ( V_10 , V_20 ) ;
F_7 ( V_20 ) ;
F_71 ( V_2 ) ;
F_20 ( V_20 , V_64 ) ;
F_82 ( V_20 , V_20 -> V_32 -> V_157 ( V_20 ) ) ;
F_15 ( & V_22 ) ;
V_20 -> V_19 = 0 ;
F_17 ( & V_22 ) ;
if ( V_2 -> V_31 == V_61 ) {
if ( V_20 -> V_101 != V_102 ) {
F_70 ( V_20 ) ;
if ( F_85 ( V_20 ) )
F_20 ( V_20 , V_61 ) ;
} else
F_135 ( V_20 ) ;
}
V_21 = 0 ;
V_24:
F_46 ( V_20 ) ;
F_151 ( V_177 ) ;
F_256 ( V_177 ) ;
return V_21 ;
}
int F_338 ( struct V_248 * V_177 , T_5 * V_612 )
{
int V_623 = 0 , V_624 = 0 , V_625 = 0 ;
struct V_8 * V_12 ;
F_21 ( L_117 , V_177 -> V_626 , V_612 ) ;
F_121 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_12 -> V_31 != V_156 )
continue;
if ( ! F_13 ( & V_12 -> V_18 , & V_177 -> V_612 ) ) {
V_624 |= V_627 ;
if ( F_73 ( V_628 , & V_12 -> V_88 ) )
V_624 |= V_566 ;
V_623 ++ ;
} else if ( ! F_13 ( & V_12 -> V_18 , V_321 ) ) {
V_625 |= V_627 ;
if ( F_73 ( V_628 , & V_12 -> V_88 ) )
V_625 |= V_566 ;
}
}
F_122 ( & V_22 ) ;
return V_623 ? V_624 : V_625 ;
}
void F_339 ( struct V_1 * V_2 , T_3 V_153 )
{
struct V_9 * V_10 ;
F_21 ( L_118 , V_2 , & V_2 -> V_139 , V_153 ) ;
if ( ! V_153 ) {
V_10 = F_326 ( V_2 ) ;
if ( V_10 )
F_145 ( V_10 ) ;
} else {
F_156 ( V_2 , F_340 ( V_153 ) ) ;
}
}
int F_341 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_138 ;
F_21 ( L_119 , V_2 ) ;
if ( ! V_10 )
return V_100 ;
return V_10 -> V_99 ;
}
void F_342 ( struct V_1 * V_2 , T_3 V_60 )
{
F_21 ( L_120 , V_2 , V_60 ) ;
F_343 ( V_2 -> V_138 ) ;
F_156 ( V_2 , F_340 ( V_60 ) ) ;
}
static inline void F_344 ( struct V_8 * V_20 , T_3 V_629 )
{
if ( V_20 -> V_101 != V_102 )
return;
if ( V_629 == 0x00 ) {
if ( V_20 -> V_65 == V_163 ) {
F_82 ( V_20 , V_630 ) ;
} else if ( V_20 -> V_65 == V_160 ||
V_20 -> V_65 == V_161 )
F_45 ( V_20 , V_63 ) ;
} else {
if ( V_20 -> V_65 == V_163 )
F_70 ( V_20 ) ;
}
}
int F_345 ( struct V_1 * V_2 , T_3 V_153 , T_3 V_629 )
{
struct V_9 * V_10 = V_2 -> V_138 ;
struct V_8 * V_20 ;
if ( ! V_10 )
return 0 ;
F_21 ( L_121 , V_10 , V_153 , V_629 ) ;
if ( V_2 -> type == V_3 ) {
if ( ! V_153 && V_629 )
F_346 ( V_10 ) ;
F_237 ( & V_10 -> V_345 ) ;
}
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
F_21 ( L_122 , V_20 , V_20 -> V_14 ,
F_22 ( V_20 -> V_31 ) ) ;
if ( V_20 -> V_14 == V_125 ) {
F_46 ( V_20 ) ;
continue;
}
if ( V_20 -> V_14 == V_323 ) {
if ( ! V_153 && V_629 ) {
V_20 -> V_65 = V_2 -> V_65 ;
F_129 ( V_20 ) ;
}
F_46 ( V_20 ) ;
continue;
}
if ( ! F_119 ( V_20 ) ) {
F_46 ( V_20 ) ;
continue;
}
if ( ! V_153 && ( V_20 -> V_31 == V_61 ||
V_20 -> V_31 == V_62 ) ) {
V_20 -> V_32 -> V_577 ( V_20 ) ;
F_344 ( V_20 , V_629 ) ;
F_46 ( V_20 ) ;
continue;
}
if ( V_20 -> V_31 == V_64 ) {
if ( ! V_153 )
F_133 ( V_20 ) ;
else
F_82 ( V_20 , V_631 ) ;
} else if ( V_20 -> V_31 == V_158 ) {
struct V_151 V_142 ;
T_6 V_632 , V_633 ;
if ( ! V_153 ) {
if ( F_73 ( V_144 , & V_20 -> V_88 ) ) {
V_632 = V_308 ;
V_633 = V_309 ;
V_20 -> V_32 -> V_310 ( V_20 ) ;
} else {
F_20 ( V_20 , V_62 ) ;
V_632 = V_311 ;
V_633 = V_154 ;
}
} else {
F_20 ( V_20 , V_147 ) ;
F_82 ( V_20 , V_631 ) ;
V_632 = V_152 ;
V_633 = V_154 ;
}
V_142 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_142 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_142 . V_143 = F_16 ( V_632 ) ;
V_142 . V_153 = F_16 ( V_633 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_155 ,
sizeof( V_142 ) , & V_142 ) ;
if ( ! F_73 ( V_313 , & V_20 -> V_76 ) &&
V_632 == V_311 ) {
char V_307 [ 128 ] ;
F_54 ( V_313 , & V_20 -> V_76 ) ;
F_80 ( V_10 , F_88 ( V_10 ) ,
V_314 ,
F_140 ( V_20 , V_307 ) ,
V_307 ) ;
V_20 -> V_315 ++ ;
}
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
int F_347 ( struct V_1 * V_2 , struct V_38 * V_42 , T_2 V_88 )
{
struct V_9 * V_10 = V_2 -> V_138 ;
struct V_233 * V_634 ;
int V_175 ;
if ( ! V_10 && V_2 -> V_177 -> V_520 != V_635 )
goto V_580;
if ( ! V_10 )
V_10 = F_326 ( V_2 ) ;
if ( ! V_10 )
goto V_580;
F_21 ( L_123 , V_10 , V_42 -> V_175 , V_88 ) ;
switch ( V_88 ) {
case V_179 :
case V_178 :
case V_189 :
if ( V_10 -> V_636 ) {
F_285 ( L_124 , V_42 -> V_175 ) ;
F_96 ( V_10 -> V_342 ) ;
V_10 -> V_342 = NULL ;
V_10 -> V_636 = 0 ;
F_147 ( V_10 , V_637 ) ;
}
if ( V_42 -> V_175 < V_230 ) {
F_285 ( L_125 , V_42 -> V_175 ) ;
F_147 ( V_10 , V_637 ) ;
goto V_580;
}
V_634 = (struct V_233 * ) V_42 -> V_176 ;
V_175 = F_66 ( V_634 -> V_175 ) + V_230 ;
if ( V_175 == V_42 -> V_175 ) {
F_321 ( V_10 , V_42 ) ;
return 0 ;
}
F_21 ( L_126 , V_175 , V_42 -> V_175 ) ;
if ( V_42 -> V_175 > V_175 ) {
F_285 ( L_127 ,
V_42 -> V_175 , V_175 ) ;
F_147 ( V_10 , V_637 ) ;
goto V_580;
}
V_10 -> V_342 = F_110 ( V_175 , V_51 ) ;
if ( ! V_10 -> V_342 )
goto V_580;
F_348 ( V_42 , F_112 ( V_10 -> V_342 , V_42 -> V_175 ) ,
V_42 -> V_175 ) ;
V_10 -> V_636 = V_175 - V_42 -> V_175 ;
break;
case V_638 :
F_21 ( L_128 , V_42 -> V_175 , V_10 -> V_636 ) ;
if ( ! V_10 -> V_636 ) {
F_285 ( L_129 , V_42 -> V_175 ) ;
F_147 ( V_10 , V_637 ) ;
goto V_580;
}
if ( V_42 -> V_175 > V_10 -> V_636 ) {
F_285 ( L_130 ,
V_42 -> V_175 , V_10 -> V_636 ) ;
F_96 ( V_10 -> V_342 ) ;
V_10 -> V_342 = NULL ;
V_10 -> V_636 = 0 ;
F_147 ( V_10 , V_637 ) ;
goto V_580;
}
F_348 ( V_42 , F_112 ( V_10 -> V_342 , V_42 -> V_175 ) ,
V_42 -> V_175 ) ;
V_10 -> V_636 -= V_42 -> V_175 ;
if ( ! V_10 -> V_636 ) {
struct V_38 * V_342 = V_10 -> V_342 ;
V_10 -> V_342 = NULL ;
F_321 ( V_10 , V_342 ) ;
}
break;
}
V_580:
F_96 ( V_42 ) ;
return 0 ;
}
static int F_349 ( struct V_639 * V_640 , void * V_25 )
{
struct V_8 * V_12 ;
F_121 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
F_350 ( V_640 , L_131 ,
& V_12 -> V_18 , & V_12 -> V_139 ,
V_12 -> V_31 , F_66 ( V_12 -> V_17 ) ,
V_12 -> V_14 , V_12 -> V_13 , V_12 -> V_96 , V_12 -> V_104 ,
V_12 -> V_65 , V_12 -> V_130 ) ;
}
F_122 ( & V_22 ) ;
return 0 ;
}
static int F_351 ( struct V_641 * V_641 , struct V_642 * V_642 )
{
return F_352 ( V_642 , F_349 , V_641 -> V_643 ) ;
}
int T_11 F_353 ( void )
{
int V_21 ;
V_21 = F_354 () ;
if ( V_21 < 0 )
return V_21 ;
if ( F_355 ( V_644 ) )
return 0 ;
V_645 = F_356 ( L_132 , 0444 , V_644 ,
NULL , & V_646 ) ;
F_357 ( L_133 , 0644 , V_644 ,
& V_94 ) ;
F_357 ( L_134 , 0644 , V_644 ,
& V_97 ) ;
F_358 () ;
return 0 ;
}
void F_359 ( void )
{
F_360 () ;
F_361 ( V_645 ) ;
F_362 () ;
}
