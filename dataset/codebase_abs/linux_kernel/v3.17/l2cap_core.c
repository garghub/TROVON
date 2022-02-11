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
V_20 -> V_85 = V_20 -> V_80 ;
V_20 -> V_86 = V_20 -> V_82 ;
V_20 -> V_87 = V_83 ;
V_20 -> V_65 = V_88 ;
V_20 -> V_89 = V_90 ;
V_20 -> V_35 = V_91 ;
V_20 -> V_37 = V_92 ;
V_20 -> V_76 = 0 ;
F_54 ( V_93 , & V_20 -> V_94 ) ;
}
static void F_62 ( struct V_8 * V_20 )
{
V_20 -> V_95 = NULL ;
V_20 -> V_96 = NULL ;
V_20 -> V_97 = 0 ;
V_20 -> V_98 = 0 ;
V_20 -> V_99 = V_100 ;
V_20 -> V_101 = F_63 ( T_2 , V_20 -> V_102 , V_103 ) ;
F_64 ( & V_20 -> V_104 ) ;
}
void F_65 ( struct V_9 * V_10 , struct V_8 * V_20 )
{
F_21 ( L_5 , V_10 ,
F_66 ( V_20 -> V_17 ) , V_20 -> V_13 ) ;
V_10 -> V_105 = V_106 ;
V_20 -> V_10 = V_10 ;
switch ( V_20 -> V_107 ) {
case V_108 :
V_20 -> V_14 = F_19 ( V_10 ) ;
if ( V_10 -> V_2 -> type == V_109 )
V_20 -> V_110 = V_111 ;
break;
case V_112 :
V_20 -> V_14 = V_113 ;
V_20 -> V_13 = V_113 ;
V_20 -> V_110 = V_111 ;
break;
case V_114 :
break;
default:
V_20 -> V_14 = V_115 ;
V_20 -> V_13 = V_115 ;
V_20 -> V_110 = V_111 ;
}
V_20 -> V_116 = V_117 ;
V_20 -> V_118 = V_119 ;
V_20 -> V_120 = V_121 ;
V_20 -> V_122 = V_123 ;
V_20 -> V_124 = V_125 ;
V_20 -> V_126 = V_127 ;
F_57 ( V_20 ) ;
F_67 ( V_10 -> V_2 ) ;
F_51 ( & V_20 -> V_50 , & V_10 -> V_128 ) ;
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
struct V_129 * V_130 = V_10 -> V_2 -> V_129 ;
F_56 ( & V_20 -> V_50 ) ;
F_47 ( V_20 ) ;
V_20 -> V_10 = NULL ;
if ( V_20 -> V_14 != V_131 )
F_71 ( V_10 -> V_2 ) ;
if ( V_130 && V_130 -> V_132 == V_20 )
V_130 -> V_132 = NULL ;
}
if ( V_20 -> V_133 ) {
struct V_134 * V_133 = V_20 -> V_133 ;
F_21 ( L_7 , V_20 , V_133 ) ;
F_72 ( V_133 ) ;
}
V_20 -> V_32 -> V_135 ( V_20 , V_21 ) ;
if ( F_73 ( V_75 , & V_20 -> V_76 ) )
return;
switch( V_20 -> V_136 ) {
case V_137 :
break;
case V_138 :
F_74 ( & V_20 -> V_104 ) ;
break;
case V_139 :
F_30 ( V_20 ) ;
F_75 ( V_20 ) ;
F_76 ( V_20 ) ;
F_74 ( & V_20 -> V_140 ) ;
F_37 ( & V_20 -> V_141 ) ;
F_37 ( & V_20 -> V_142 ) ;
case V_143 :
F_74 ( & V_20 -> V_104 ) ;
break;
}
return;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_144 ;
struct V_8 * V_20 ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
F_78 ( & V_20 -> V_145 , & V_2 -> V_145 ) ;
V_20 -> V_146 = F_1 ( V_2 , V_2 -> V_146 ) ;
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_79 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_147 V_148 ;
T_2 V_149 ;
if ( F_73 ( V_150 , & V_20 -> V_94 ) )
V_149 = V_151 ;
else
V_149 = V_152 ;
F_20 ( V_20 , V_153 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_154 = F_16 ( V_20 -> V_102 ) ;
V_148 . V_101 = F_16 ( V_20 -> V_101 ) ;
V_148 . V_155 = F_16 ( V_20 -> V_99 ) ;
V_148 . V_149 = F_16 ( V_149 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_156 , sizeof( V_148 ) ,
& V_148 ) ;
}
static void F_81 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_157 V_148 ;
T_2 V_149 ;
if ( F_73 ( V_150 , & V_20 -> V_94 ) )
V_149 = V_158 ;
else
V_149 = V_152 ;
F_20 ( V_20 , V_153 ) ;
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_149 = F_16 ( V_149 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_161 , sizeof( V_148 ) , & V_148 ) ;
}
void F_45 ( struct V_8 * V_20 , int V_60 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_2 , V_20 , F_22 ( V_20 -> V_31 ) ) ;
switch ( V_20 -> V_31 ) {
case V_162 :
V_20 -> V_32 -> V_135 ( V_20 , 0 ) ;
break;
case V_61 :
case V_62 :
if ( V_20 -> V_107 == V_108 ) {
F_82 ( V_20 , V_20 -> V_32 -> V_163 ( V_20 ) ) ;
F_83 ( V_20 , V_60 ) ;
} else
F_69 ( V_20 , V_60 ) ;
break;
case V_164 :
if ( V_20 -> V_107 == V_108 ) {
if ( V_10 -> V_2 -> type == V_109 )
F_81 ( V_20 ) ;
else if ( V_10 -> V_2 -> type == V_3 )
F_79 ( V_20 ) ;
}
F_69 ( V_20 , V_60 ) ;
break;
case V_64 :
case V_153 :
F_69 ( V_20 , V_60 ) ;
break;
default:
V_20 -> V_32 -> V_135 ( V_20 , 0 ) ;
break;
}
}
static inline T_3 F_84 ( struct V_8 * V_20 )
{
switch ( V_20 -> V_107 ) {
case V_165 :
switch ( V_20 -> V_65 ) {
case V_166 :
case V_167 :
return V_168 ;
case V_169 :
return V_170 ;
default:
return V_171 ;
}
break;
case V_112 :
if ( V_20 -> V_17 == F_16 ( V_172 ) ) {
if ( V_20 -> V_65 == V_88 )
V_20 -> V_65 = V_66 ;
}
if ( V_20 -> V_65 == V_166 ||
V_20 -> V_65 == V_167 )
return V_173 ;
else
return V_171 ;
break;
case V_108 :
if ( V_20 -> V_17 == F_16 ( V_174 ) ) {
if ( V_20 -> V_65 == V_88 )
V_20 -> V_65 = V_66 ;
if ( V_20 -> V_65 == V_166 ||
V_20 -> V_65 == V_167 )
return V_173 ;
else
return V_171 ;
}
default:
switch ( V_20 -> V_65 ) {
case V_166 :
case V_167 :
return V_175 ;
case V_169 :
return V_176 ;
default:
return V_171 ;
}
break;
}
}
int F_85 ( struct V_8 * V_20 , bool V_177 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
T_1 V_178 ;
if ( V_10 -> V_2 -> type == V_3 )
return F_86 ( V_10 -> V_2 , V_20 -> V_65 ) ;
V_178 = F_84 ( V_20 ) ;
return F_87 ( V_10 -> V_2 , V_20 -> V_65 , V_178 ,
V_177 ) ;
}
static T_3 F_88 ( struct V_9 * V_10 )
{
T_3 V_179 ;
F_6 ( & V_10 -> V_180 ) ;
if ( ++ V_10 -> V_181 > 128 )
V_10 -> V_181 = 1 ;
V_179 = V_10 -> V_181 ;
F_8 ( & V_10 -> V_180 ) ;
return V_179 ;
}
static void F_80 ( struct V_9 * V_10 , T_3 V_16 , T_3 V_182 , T_2 V_183 ,
void * V_184 )
{
struct V_38 * V_42 = F_89 ( V_10 , V_182 , V_16 , V_183 , V_184 ) ;
T_3 V_94 ;
F_21 ( L_8 , V_182 ) ;
if ( ! V_42 )
return;
if ( F_90 ( V_10 -> V_2 -> V_185 ) )
V_94 = V_186 ;
else
V_94 = V_187 ;
F_33 ( V_42 ) -> V_188 = V_189 ;
V_42 -> V_190 = V_191 ;
F_91 ( V_10 -> V_192 , V_42 , V_94 ) ;
}
static bool F_92 ( struct V_8 * V_20 )
{
return V_20 -> V_193 != V_194 &&
V_20 -> V_193 != V_195 ;
}
static void F_93 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
struct V_1 * V_2 = V_20 -> V_10 -> V_2 ;
T_2 V_94 ;
F_21 ( L_9 , V_20 , V_42 , V_42 -> V_183 ,
V_42 -> V_190 ) ;
if ( V_20 -> V_196 && ! F_92 ( V_20 ) ) {
if ( V_20 -> V_133 )
F_91 ( V_20 -> V_133 , V_42 , V_197 ) ;
else
F_94 ( V_42 ) ;
return;
}
if ( ! F_73 ( V_198 , & V_20 -> V_94 ) &&
F_90 ( V_2 -> V_185 ) )
V_94 = V_186 ;
else
V_94 = V_187 ;
F_33 ( V_42 ) -> V_188 = F_73 ( V_93 , & V_20 -> V_94 ) ;
F_91 ( V_20 -> V_10 -> V_192 , V_42 , V_94 ) ;
}
static void F_95 ( T_2 V_199 , struct V_200 * V_43 )
{
V_43 -> V_201 = ( V_199 & V_202 ) >> V_203 ;
V_43 -> V_204 = ( V_199 & V_205 ) >> V_206 ;
if ( V_199 & V_207 ) {
V_43 -> V_208 = 1 ;
V_43 -> V_209 = ( V_199 & V_210 ) >> V_211 ;
V_43 -> V_212 = ( V_199 & V_213 ) >> V_214 ;
V_43 -> V_215 = 0 ;
V_43 -> V_44 = 0 ;
} else {
V_43 -> V_208 = 0 ;
V_43 -> V_215 = ( V_199 & V_216 ) >> V_217 ;
V_43 -> V_44 = ( V_199 & V_218 ) >> V_219 ;
V_43 -> V_209 = 0 ;
V_43 -> V_212 = 0 ;
}
}
static void F_96 ( T_8 V_220 , struct V_200 * V_43 )
{
V_43 -> V_201 = ( V_220 & V_221 ) >> V_222 ;
V_43 -> V_204 = ( V_220 & V_223 ) >> V_224 ;
if ( V_220 & V_225 ) {
V_43 -> V_208 = 1 ;
V_43 -> V_209 = ( V_220 & V_226 ) >> V_227 ;
V_43 -> V_212 = ( V_220 & V_228 ) >> V_229 ;
V_43 -> V_215 = 0 ;
V_43 -> V_44 = 0 ;
} else {
V_43 -> V_208 = 0 ;
V_43 -> V_215 = ( V_220 & V_230 ) >> V_231 ;
V_43 -> V_44 = ( V_220 & V_232 ) >> V_233 ;
V_43 -> V_209 = 0 ;
V_43 -> V_212 = 0 ;
}
}
static inline void F_97 ( struct V_8 * V_20 ,
struct V_38 * V_42 )
{
if ( F_73 ( V_234 , & V_20 -> V_94 ) ) {
F_96 ( F_98 ( V_42 -> V_184 ) ,
& F_33 ( V_42 ) -> V_43 ) ;
F_99 ( V_42 , V_235 ) ;
} else {
F_95 ( F_100 ( V_42 -> V_184 ) ,
& F_33 ( V_42 ) -> V_43 ) ;
F_99 ( V_42 , V_236 ) ;
}
}
static T_8 F_101 ( struct V_200 * V_43 )
{
T_8 V_237 ;
V_237 = V_43 -> V_201 << V_222 ;
V_237 |= V_43 -> V_204 << V_224 ;
if ( V_43 -> V_208 ) {
V_237 |= V_43 -> V_209 << V_227 ;
V_237 |= V_43 -> V_212 << V_229 ;
V_237 |= V_225 ;
} else {
V_237 |= V_43 -> V_215 << V_231 ;
V_237 |= V_43 -> V_44 << V_233 ;
}
return V_237 ;
}
static T_2 F_102 ( struct V_200 * V_43 )
{
T_2 V_237 ;
V_237 = V_43 -> V_201 << V_203 ;
V_237 |= V_43 -> V_204 << V_206 ;
if ( V_43 -> V_208 ) {
V_237 |= V_43 -> V_209 << V_211 ;
V_237 |= V_43 -> V_212 << V_214 ;
V_237 |= V_207 ;
} else {
V_237 |= V_43 -> V_215 << V_217 ;
V_237 |= V_43 -> V_44 << V_219 ;
}
return V_237 ;
}
static inline void F_103 ( struct V_8 * V_20 ,
struct V_200 * V_43 ,
struct V_38 * V_42 )
{
if ( F_73 ( V_234 , & V_20 -> V_94 ) ) {
F_104 ( F_101 ( V_43 ) ,
V_42 -> V_184 + V_238 ) ;
} else {
F_105 ( F_102 ( V_43 ) ,
V_42 -> V_184 + V_238 ) ;
}
}
static inline unsigned int F_106 ( struct V_8 * V_20 )
{
if ( F_73 ( V_234 , & V_20 -> V_94 ) )
return V_239 ;
else
return V_240 ;
}
static struct V_38 * F_107 ( struct V_8 * V_20 ,
T_8 V_43 )
{
struct V_38 * V_42 ;
struct V_241 * V_242 ;
int V_243 = F_106 ( V_20 ) ;
if ( V_20 -> V_78 == V_79 )
V_243 += V_244 ;
V_42 = F_108 ( V_243 , V_51 ) ;
if ( ! V_42 )
return F_109 ( - V_52 ) ;
V_242 = (struct V_241 * ) F_110 ( V_42 , V_238 ) ;
V_242 -> V_183 = F_16 ( V_243 - V_238 ) ;
V_242 -> V_11 = F_16 ( V_20 -> V_13 ) ;
if ( F_73 ( V_234 , & V_20 -> V_94 ) )
F_104 ( V_43 , F_110 ( V_42 , V_235 ) ) ;
else
F_105 ( V_43 , F_110 ( V_42 , V_236 ) ) ;
if ( V_20 -> V_78 == V_79 ) {
T_2 V_78 = F_111 ( 0 , ( T_3 * ) V_42 -> V_184 , V_42 -> V_183 ) ;
F_105 ( V_78 , F_110 ( V_42 , V_244 ) ) ;
}
V_42 -> V_190 = V_191 ;
return V_42 ;
}
static void F_112 ( struct V_8 * V_20 ,
struct V_200 * V_43 )
{
struct V_38 * V_42 ;
T_8 V_245 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( ! V_43 -> V_208 )
return;
if ( F_92 ( V_20 ) )
return;
if ( F_113 ( V_246 , & V_20 -> V_247 ) &&
! V_43 -> V_209 )
V_43 -> V_204 = 1 ;
if ( V_43 -> V_212 == V_248 )
F_114 ( V_249 , & V_20 -> V_247 ) ;
else if ( V_43 -> V_212 == V_250 )
F_54 ( V_249 , & V_20 -> V_247 ) ;
if ( V_43 -> V_212 != V_251 ) {
V_20 -> V_252 = V_43 -> V_201 ;
F_76 ( V_20 ) ;
}
F_21 ( L_11 , V_43 -> V_201 ,
V_43 -> V_204 , V_43 -> V_209 , V_43 -> V_212 ) ;
if ( F_73 ( V_234 , & V_20 -> V_94 ) )
V_245 = F_101 ( V_43 ) ;
else
V_245 = F_102 ( V_43 ) ;
V_42 = F_107 ( V_20 , V_245 ) ;
if ( ! F_115 ( V_42 ) )
F_93 ( V_20 , V_42 ) ;
}
static void F_116 ( struct V_8 * V_20 , bool V_209 )
{
struct V_200 V_43 ;
F_21 ( L_12 , V_20 , V_209 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_208 = 1 ;
V_43 . V_209 = V_209 ;
if ( F_73 ( V_253 , & V_20 -> V_247 ) )
V_43 . V_212 = V_250 ;
else
V_43 . V_212 = V_248 ;
V_43 . V_201 = V_20 -> V_254 ;
F_112 ( V_20 , & V_43 ) ;
}
static inline int F_117 ( struct V_8 * V_20 )
{
return ! F_73 ( V_255 , & V_20 -> V_76 ) ;
}
static bool F_118 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_256 * V_185 ;
bool V_257 = false ;
if ( ! V_10 -> V_258 )
return false ;
if ( ! ( V_10 -> V_259 & V_260 ) )
return false ;
F_119 ( & V_261 ) ;
F_3 (hdev, &hci_dev_list, list) {
if ( V_185 -> V_262 != V_263 &&
F_73 ( V_264 , & V_185 -> V_94 ) ) {
V_257 = true ;
break;
}
}
F_120 ( & V_261 ) ;
if ( V_20 -> V_265 == V_266 )
return V_257 ;
return false ;
}
static bool F_121 ( struct V_8 * V_20 )
{
return true ;
}
void F_122 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_267 V_268 ;
V_268 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_268 . V_17 = V_20 -> V_17 ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_54 ( V_255 , & V_20 -> V_76 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_269 , sizeof( V_268 ) , & V_268 ) ;
}
static void F_123 ( struct V_8 * V_20 , T_3 V_270 )
{
struct V_271 V_268 ;
V_268 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_268 . V_17 = V_20 -> V_17 ;
V_268 . V_270 = V_270 ;
V_20 -> V_16 = F_88 ( V_20 -> V_10 ) ;
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_272 ,
sizeof( V_268 ) , & V_268 ) ;
}
static void F_124 ( struct V_8 * V_20 )
{
struct V_38 * V_42 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_136 != V_139 )
return;
F_30 ( V_20 ) ;
F_75 ( V_20 ) ;
F_76 ( V_20 ) ;
V_20 -> V_273 = 0 ;
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_42 ) -> V_43 . V_274 )
F_33 ( V_42 ) -> V_43 . V_274 = 1 ;
else
break;
}
V_20 -> V_275 = V_20 -> V_254 ;
F_114 ( V_276 , & V_20 -> V_247 ) ;
F_114 ( V_277 , & V_20 -> V_247 ) ;
F_41 ( & V_20 -> V_142 ) ;
F_41 ( & V_20 -> V_141 ) ;
F_74 ( & V_20 -> V_140 ) ;
V_20 -> V_278 = V_279 ;
V_20 -> V_280 = V_281 ;
F_54 ( V_282 , & V_20 -> V_247 ) ;
}
static void F_125 ( struct V_8 * V_20 )
{
T_3 V_283 = V_20 -> V_283 ;
F_21 ( L_3 , V_20 ) ;
V_20 -> V_193 = V_194 ;
V_20 -> V_283 = V_284 ;
if ( V_20 -> V_136 != V_139 )
return;
switch ( V_283 ) {
case V_285 :
F_126 ( V_20 , NULL , NULL , V_286 ) ;
V_20 -> V_280 = V_287 ;
break;
case V_288 :
V_20 -> V_280 = V_289 ;
break;
}
}
static void F_127 ( struct V_8 * V_20 )
{
V_20 -> V_76 = 0 ;
F_70 ( V_20 ) ;
if ( V_20 -> V_136 == V_138 && ! V_20 -> V_98 )
V_20 -> V_32 -> V_290 ( V_20 ) ;
V_20 -> V_31 = V_61 ;
V_20 -> V_32 -> V_291 ( V_20 ) ;
}
static void F_128 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_292 V_268 ;
if ( F_129 ( V_293 , & V_20 -> V_94 ) )
return;
V_268 . V_17 = V_20 -> V_17 ;
V_268 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_268 . V_154 = F_16 ( V_20 -> V_102 ) ;
V_268 . V_101 = F_16 ( V_20 -> V_101 ) ;
V_268 . V_155 = F_16 ( V_20 -> V_99 ) ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_294 ,
sizeof( V_268 ) , & V_268 ) ;
}
static void F_130 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
if ( ! F_86 ( V_10 -> V_2 , V_20 -> V_65 ) )
return;
if ( ! V_20 -> V_17 ) {
F_127 ( V_20 ) ;
return;
}
if ( V_20 -> V_31 == V_64 )
F_128 ( V_20 ) ;
}
static void F_131 ( struct V_8 * V_20 )
{
if ( F_118 ( V_20 ) ) {
F_21 ( L_13 , V_20 ) ;
F_132 ( V_20 ) ;
} else if ( V_20 -> V_10 -> V_2 -> type == V_3 ) {
F_130 ( V_20 ) ;
} else {
F_122 ( V_20 ) ;
}
}
static void F_133 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
if ( V_10 -> V_2 -> type == V_3 ) {
F_130 ( V_20 ) ;
return;
}
if ( V_10 -> V_295 & V_296 ) {
if ( ! ( V_10 -> V_295 & V_297 ) )
return;
if ( F_85 ( V_20 , true ) &&
F_117 ( V_20 ) ) {
F_131 ( V_20 ) ;
}
} else {
struct V_298 V_268 ;
V_268 . type = F_16 ( V_299 ) ;
V_10 -> V_295 |= V_296 ;
V_10 -> V_300 = F_88 ( V_10 ) ;
F_134 ( & V_10 -> V_301 , V_302 ) ;
F_80 ( V_10 , V_10 -> V_300 , V_303 ,
sizeof( V_268 ) , & V_268 ) ;
}
}
static inline int F_135 ( T_1 V_136 , T_9 V_304 )
{
T_8 V_305 = V_306 ;
if ( ! V_307 )
V_305 |= V_308 | V_309 ;
switch ( V_136 ) {
case V_139 :
return V_308 & V_304 & V_305 ;
case V_143 :
return V_309 & V_304 & V_305 ;
default:
return 0x00 ;
}
}
static void F_83 ( struct V_8 * V_20 , int V_21 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_310 V_268 ;
if ( ! V_10 )
return;
if ( V_20 -> V_136 == V_139 && V_20 -> V_31 == V_61 ) {
F_30 ( V_20 ) ;
F_75 ( V_20 ) ;
F_76 ( V_20 ) ;
}
if ( V_20 -> V_14 == V_131 ) {
F_20 ( V_20 , V_153 ) ;
return;
}
V_268 . V_13 = F_16 ( V_20 -> V_13 ) ;
V_268 . V_14 = F_16 ( V_20 -> V_14 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_311 ,
sizeof( V_268 ) , & V_268 ) ;
F_23 ( V_20 , V_153 , V_21 ) ;
}
static void F_136 ( struct V_9 * V_10 )
{
struct V_8 * V_20 , * V_312 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_137 (chan, tmp, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_107 != V_108 ) {
F_46 ( V_20 ) ;
continue;
}
if ( V_20 -> V_31 == V_64 ) {
if ( ! F_85 ( V_20 , true ) ||
! F_117 ( V_20 ) ) {
F_46 ( V_20 ) ;
continue;
}
if ( ! F_135 ( V_20 -> V_136 , V_10 -> V_304 )
&& F_73 ( V_313 ,
& V_20 -> V_76 ) ) {
F_45 ( V_20 , V_314 ) ;
F_46 ( V_20 ) ;
continue;
}
F_131 ( V_20 ) ;
} else if ( V_20 -> V_31 == V_164 ) {
struct V_157 V_148 ;
char V_315 [ 128 ] ;
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( F_85 ( V_20 , false ) ) {
if ( F_73 ( V_150 , & V_20 -> V_94 ) ) {
V_148 . V_149 = F_16 ( V_316 ) ;
V_148 . V_159 = F_16 ( V_317 ) ;
V_20 -> V_32 -> V_318 ( V_20 ) ;
} else {
F_20 ( V_20 , V_62 ) ;
V_148 . V_149 = F_16 ( V_319 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
}
} else {
V_148 . V_149 = F_16 ( V_316 ) ;
V_148 . V_159 = F_16 ( V_320 ) ;
}
F_80 ( V_10 , V_20 -> V_16 , V_161 ,
sizeof( V_148 ) , & V_148 ) ;
if ( F_73 ( V_321 , & V_20 -> V_76 ) ||
V_148 . V_149 != V_319 ) {
F_46 ( V_20 ) ;
continue;
}
F_54 ( V_321 , & V_20 -> V_76 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_322 ,
F_138 ( V_20 , V_315 ) , V_315 ) ;
V_20 -> V_323 ++ ;
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static struct V_8 * F_139 ( int V_31 , T_2 V_11 ,
T_5 * V_18 ,
T_5 * V_145 )
{
struct V_8 * V_12 , * V_324 = NULL ;
F_119 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_31 && V_12 -> V_31 != V_31 )
continue;
if ( V_12 -> V_14 == V_11 ) {
int V_325 , V_326 ;
int V_327 , V_328 ;
V_325 = ! F_13 ( & V_12 -> V_18 , V_18 ) ;
V_326 = ! F_13 ( & V_12 -> V_145 , V_145 ) ;
if ( V_325 && V_326 ) {
F_120 ( & V_22 ) ;
return V_12 ;
}
V_327 = ! F_13 ( & V_12 -> V_18 , V_329 ) ;
V_328 = ! F_13 ( & V_12 -> V_145 , V_329 ) ;
if ( ( V_325 && V_328 ) || ( V_327 && V_326 ) ||
( V_327 && V_328 ) )
V_324 = V_12 ;
}
}
F_120 ( & V_22 ) ;
return V_324 ;
}
static void F_140 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_256 * V_185 = V_2 -> V_185 ;
struct V_8 * V_20 , * V_330 ;
T_3 V_146 ;
F_21 ( L_15 ) ;
V_330 = F_139 ( V_162 , V_331 ,
& V_2 -> V_18 , & V_2 -> V_145 ) ;
if ( ! V_330 )
return;
if ( F_2 ( V_10 , V_331 ) )
return;
V_146 = F_1 ( V_2 , V_2 -> V_146 ) ;
if ( F_141 ( & V_185 -> V_332 , & V_2 -> V_145 , V_146 ) )
return;
if ( V_2 -> V_333 == V_334 &&
( V_2 -> V_335 < V_2 -> V_336 ||
V_2 -> V_335 > V_2 -> V_337 ) ) {
struct V_338 V_268 ;
V_268 . V_339 = F_16 ( V_2 -> V_336 ) ;
V_268 . V_340 = F_16 ( V_2 -> V_337 ) ;
V_268 . V_341 = F_16 ( V_2 -> V_342 ) ;
V_268 . V_343 = F_16 ( V_2 -> V_344 ) ;
F_80 ( V_10 , F_88 ( V_10 ) ,
V_345 , sizeof( V_268 ) , & V_268 ) ;
}
F_7 ( V_330 ) ;
V_20 = V_330 -> V_32 -> V_346 ( V_330 ) ;
if ( ! V_20 )
goto V_347;
F_78 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
F_78 ( & V_20 -> V_145 , & V_2 -> V_145 ) ;
V_20 -> V_348 = F_1 ( V_2 , V_2 -> V_348 ) ;
V_20 -> V_146 = V_146 ;
F_65 ( V_10 , V_20 ) ;
V_347:
F_46 ( V_330 ) ;
}
static void F_142 ( struct V_9 * V_10 )
{
struct V_8 * V_20 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_21 ( L_14 , V_10 ) ;
if ( V_2 -> V_349 && V_2 -> type == V_3 )
F_86 ( V_2 , V_2 -> V_350 ) ;
F_6 ( & V_10 -> V_15 ) ;
if ( V_2 -> type == V_3 )
F_140 ( V_10 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_14 == V_131 ) {
F_46 ( V_20 ) ;
continue;
}
if ( V_2 -> type == V_3 ) {
F_130 ( V_20 ) ;
} else if ( V_20 -> V_107 != V_108 ) {
F_127 ( V_20 ) ;
} else if ( V_20 -> V_31 == V_64 ) {
F_133 ( V_20 ) ;
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
F_143 ( V_2 -> V_185 -> V_351 , & V_10 -> V_352 ) ;
}
static void F_144 ( struct V_9 * V_10 , int V_21 )
{
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( F_73 ( V_353 , & V_20 -> V_94 ) )
F_24 ( V_20 , V_21 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_145 ( struct V_57 * V_58 )
{
struct V_9 * V_10 = F_44 ( V_58 , struct V_9 ,
V_301 . V_58 ) ;
V_10 -> V_295 |= V_297 ;
V_10 -> V_300 = 0 ;
F_136 ( V_10 ) ;
}
int F_146 ( struct V_9 * V_10 , struct V_354 * V_355 )
{
struct V_256 * V_185 = V_10 -> V_2 -> V_185 ;
int V_356 ;
F_147 ( V_185 ) ;
if ( V_355 -> V_50 . V_357 || V_355 -> V_50 . V_358 ) {
V_356 = - V_26 ;
goto V_359;
}
if ( ! V_10 -> V_192 ) {
V_356 = - V_360 ;
goto V_359;
}
V_356 = V_355 -> V_361 ( V_10 , V_355 ) ;
if ( V_356 )
goto V_359;
F_51 ( & V_355 -> V_50 , & V_10 -> V_362 ) ;
V_356 = 0 ;
V_359:
F_148 ( V_185 ) ;
return V_356 ;
}
void F_149 ( struct V_9 * V_10 , struct V_354 * V_355 )
{
struct V_256 * V_185 = V_10 -> V_2 -> V_185 ;
F_147 ( V_185 ) ;
if ( ! V_355 -> V_50 . V_357 || ! V_355 -> V_50 . V_358 )
goto V_359;
F_56 ( & V_355 -> V_50 ) ;
V_355 -> V_50 . V_357 = NULL ;
V_355 -> V_50 . V_358 = NULL ;
V_355 -> remove ( V_10 , V_355 ) ;
V_359:
F_148 ( V_185 ) ;
}
static void F_150 ( struct V_9 * V_10 )
{
struct V_354 * V_355 ;
while ( ! F_151 ( & V_10 -> V_362 ) ) {
V_355 = F_152 ( & V_10 -> V_362 , struct V_354 , V_50 ) ;
F_56 ( & V_355 -> V_50 ) ;
V_355 -> V_50 . V_357 = NULL ;
V_355 -> V_50 . V_358 = NULL ;
V_355 -> remove ( V_10 , V_355 ) ;
}
}
static void F_153 ( struct V_1 * V_2 , int V_21 )
{
struct V_9 * V_10 = V_2 -> V_144 ;
struct V_8 * V_20 , * V_363 ;
if ( ! V_10 )
return;
F_21 ( L_16 , V_2 , V_10 , V_21 ) ;
F_94 ( V_10 -> V_364 ) ;
F_74 ( & V_10 -> V_365 ) ;
if ( F_154 ( & V_10 -> V_352 ) )
F_155 ( & V_10 -> V_352 ) ;
F_150 ( V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_137 (chan, l, &conn->chan_l, list) {
F_57 ( V_20 ) ;
F_7 ( V_20 ) ;
F_69 ( V_20 , V_21 ) ;
F_46 ( V_20 ) ;
V_20 -> V_32 -> V_68 ( V_20 ) ;
F_47 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
F_156 ( V_10 -> V_192 ) ;
if ( V_10 -> V_295 & V_296 )
F_157 ( & V_10 -> V_301 ) ;
if ( F_113 ( V_366 , & V_2 -> V_94 ) ) {
F_157 ( & V_10 -> V_367 ) ;
F_158 ( V_10 ) ;
}
V_2 -> V_144 = NULL ;
V_10 -> V_192 = NULL ;
F_159 ( V_10 ) ;
}
static void F_160 ( struct V_57 * V_58 )
{
struct V_9 * V_10 = F_44 ( V_58 , struct V_9 ,
V_367 . V_58 ) ;
F_21 ( L_14 , V_10 ) ;
if ( F_113 ( V_366 , & V_10 -> V_2 -> V_94 ) ) {
F_158 ( V_10 ) ;
F_153 ( V_10 -> V_2 , V_67 ) ;
}
}
static void F_161 ( struct V_74 * V_368 )
{
struct V_9 * V_10 = F_44 ( V_368 , struct V_9 , V_368 ) ;
F_162 ( V_10 -> V_2 ) ;
F_38 ( V_10 ) ;
}
void F_163 ( struct V_9 * V_10 )
{
F_59 ( & V_10 -> V_368 ) ;
}
void F_159 ( struct V_9 * V_10 )
{
F_60 ( & V_10 -> V_368 , F_161 ) ;
}
static struct V_8 * F_164 ( int V_31 , T_4 V_17 ,
T_5 * V_18 ,
T_5 * V_145 ,
T_3 V_369 )
{
struct V_8 * V_12 , * V_324 = NULL ;
F_119 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_31 && V_12 -> V_31 != V_31 )
continue;
if ( V_369 == V_109 && V_12 -> V_348 != V_7 )
continue;
if ( V_369 == V_3 && V_12 -> V_348 == V_7 )
continue;
if ( V_12 -> V_17 == V_17 ) {
int V_325 , V_326 ;
int V_327 , V_328 ;
V_325 = ! F_13 ( & V_12 -> V_18 , V_18 ) ;
V_326 = ! F_13 ( & V_12 -> V_145 , V_145 ) ;
if ( V_325 && V_326 ) {
F_120 ( & V_22 ) ;
return V_12 ;
}
V_327 = ! F_13 ( & V_12 -> V_18 , V_329 ) ;
V_328 = ! F_13 ( & V_12 -> V_145 , V_329 ) ;
if ( ( V_325 && V_328 ) || ( V_327 && V_326 ) ||
( V_327 && V_328 ) )
V_324 = V_12 ;
}
}
F_120 ( & V_22 ) ;
return V_324 ;
}
static void F_165 ( struct V_57 * V_58 )
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
F_126 ( V_20 , NULL , NULL , V_370 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
static void F_166 ( struct V_57 * V_58 )
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
F_126 ( V_20 , NULL , NULL , V_371 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
static void F_167 ( struct V_8 * V_20 ,
struct V_39 * V_372 )
{
struct V_38 * V_42 ;
struct V_200 * V_43 ;
F_21 ( L_17 , V_20 , V_372 ) ;
if ( F_92 ( V_20 ) )
return;
F_168 ( V_372 , & V_20 -> V_104 ) ;
while ( ! F_169 ( & V_20 -> V_104 ) ) {
V_42 = F_170 ( & V_20 -> V_104 ) ;
F_33 ( V_42 ) -> V_43 . V_274 = 1 ;
V_43 = & F_33 ( V_42 ) -> V_43 ;
V_43 -> V_201 = 0 ;
V_43 -> V_44 = V_20 -> V_373 ;
F_103 ( V_20 , V_43 , V_42 ) ;
if ( V_20 -> V_78 == V_79 ) {
T_2 V_78 = F_111 ( 0 , ( T_3 * ) V_42 -> V_184 , V_42 -> V_183 ) ;
F_105 ( V_78 , F_110 ( V_42 , V_244 ) ) ;
}
F_93 ( V_20 , V_42 ) ;
F_21 ( L_18 , V_43 -> V_44 ) ;
V_20 -> V_373 = F_171 ( V_20 , V_20 -> V_373 ) ;
V_20 -> V_374 ++ ;
}
}
static int F_172 ( struct V_8 * V_20 )
{
struct V_38 * V_42 , * V_375 ;
struct V_200 * V_43 ;
int V_376 = 0 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_31 != V_61 )
return - V_377 ;
if ( F_73 ( V_282 , & V_20 -> V_247 ) )
return 0 ;
if ( F_92 ( V_20 ) )
return 0 ;
while ( V_20 -> V_378 &&
V_20 -> V_379 < V_20 -> V_86 &&
V_20 -> V_278 == V_279 ) {
V_42 = V_20 -> V_378 ;
F_33 ( V_42 ) -> V_43 . V_274 = 1 ;
V_43 = & F_33 ( V_42 ) -> V_43 ;
if ( F_113 ( V_246 , & V_20 -> V_247 ) )
V_43 -> V_204 = 1 ;
V_43 -> V_201 = V_20 -> V_254 ;
V_20 -> V_252 = V_20 -> V_254 ;
V_43 -> V_44 = V_20 -> V_373 ;
F_103 ( V_20 , V_43 , V_42 ) ;
if ( V_20 -> V_78 == V_79 ) {
T_2 V_78 = F_111 ( 0 , ( T_3 * ) V_42 -> V_184 , V_42 -> V_183 ) ;
F_105 ( V_78 , F_110 ( V_42 , V_244 ) ) ;
}
V_375 = F_173 ( V_42 , V_51 ) ;
if ( ! V_375 )
break;
F_25 ( V_20 ) ;
V_20 -> V_373 = F_171 ( V_20 , V_20 -> V_373 ) ;
V_20 -> V_379 ++ ;
V_20 -> V_374 ++ ;
V_376 ++ ;
if ( F_174 ( & V_20 -> V_104 , V_42 ) )
V_20 -> V_378 = NULL ;
else
V_20 -> V_378 = F_175 ( & V_20 -> V_104 , V_42 ) ;
F_93 ( V_20 , V_375 ) ;
F_21 ( L_18 , V_43 -> V_44 ) ;
}
F_21 ( L_19 , V_376 ,
V_20 -> V_379 , F_176 ( & V_20 -> V_104 ) ) ;
return V_376 ;
}
static void F_177 ( struct V_8 * V_20 )
{
struct V_200 V_43 ;
struct V_38 * V_42 ;
struct V_38 * V_375 ;
T_2 V_41 ;
F_21 ( L_3 , V_20 ) ;
if ( F_73 ( V_282 , & V_20 -> V_247 ) )
return;
if ( F_92 ( V_20 ) )
return;
while ( V_20 -> V_142 . V_40 != V_54 ) {
V_41 = F_40 ( & V_20 -> V_142 ) ;
V_42 = F_31 ( & V_20 -> V_104 , V_41 ) ;
if ( ! V_42 ) {
F_21 ( L_20 ,
V_41 ) ;
continue;
}
F_33 ( V_42 ) -> V_43 . V_274 ++ ;
V_43 = F_33 ( V_42 ) -> V_43 ;
if ( V_20 -> V_80 != 0 &&
F_33 ( V_42 ) -> V_43 . V_274 > V_20 -> V_80 ) {
F_21 ( L_21 , V_20 -> V_80 ) ;
F_83 ( V_20 , V_314 ) ;
F_41 ( & V_20 -> V_142 ) ;
break;
}
V_43 . V_201 = V_20 -> V_254 ;
if ( F_113 ( V_246 , & V_20 -> V_247 ) )
V_43 . V_204 = 1 ;
else
V_43 . V_204 = 0 ;
if ( F_178 ( V_42 ) ) {
V_375 = F_179 ( V_42 , V_51 ) ;
} else {
V_375 = F_173 ( V_42 , V_51 ) ;
}
if ( ! V_375 ) {
F_41 ( & V_20 -> V_142 ) ;
break;
}
if ( F_73 ( V_234 , & V_20 -> V_94 ) ) {
F_104 ( F_101 ( & V_43 ) ,
V_375 -> V_184 + V_238 ) ;
} else {
F_105 ( F_102 ( & V_43 ) ,
V_375 -> V_184 + V_238 ) ;
}
if ( V_20 -> V_78 == V_79 ) {
T_2 V_78 = F_111 ( 0 , ( T_3 * ) V_375 -> V_184 , V_375 -> V_183 ) ;
F_105 ( V_78 , F_110 ( V_375 ,
V_244 ) ) ;
}
F_93 ( V_20 , V_375 ) ;
F_21 ( L_22 , V_43 . V_44 ) ;
V_20 -> V_252 = V_20 -> V_254 ;
}
}
static void F_180 ( struct V_8 * V_20 ,
struct V_200 * V_43 )
{
F_21 ( L_10 , V_20 , V_43 ) ;
F_42 ( & V_20 -> V_142 , V_43 -> V_201 ) ;
F_177 ( V_20 ) ;
}
static void F_181 ( struct V_8 * V_20 ,
struct V_200 * V_43 )
{
struct V_38 * V_42 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( V_43 -> V_209 )
F_54 ( V_246 , & V_20 -> V_247 ) ;
F_41 ( & V_20 -> V_142 ) ;
if ( F_73 ( V_282 , & V_20 -> V_247 ) )
return;
if ( V_20 -> V_379 ) {
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_42 ) -> V_43 . V_44 == V_43 -> V_201 ||
V_42 == V_20 -> V_378 )
break;
}
F_182 (&chan->tx_q, skb) {
if ( V_42 == V_20 -> V_378 )
break;
F_42 ( & V_20 -> V_142 ,
F_33 ( V_42 ) -> V_43 . V_44 ) ;
}
F_177 ( V_20 ) ;
}
}
static void F_183 ( struct V_8 * V_20 )
{
struct V_200 V_43 ;
T_2 V_380 = F_184 ( V_20 , V_20 -> V_254 ,
V_20 -> V_252 ) ;
int V_381 ;
F_21 ( L_23 ,
V_20 , V_20 -> V_252 , V_20 -> V_254 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_208 = 1 ;
if ( F_73 ( V_253 , & V_20 -> V_247 ) &&
V_20 -> V_280 == V_382 ) {
F_76 ( V_20 ) ;
V_43 . V_212 = V_250 ;
V_43 . V_201 = V_20 -> V_254 ;
F_112 ( V_20 , & V_43 ) ;
} else {
if ( ! F_73 ( V_282 , & V_20 -> V_247 ) ) {
F_172 ( V_20 ) ;
if ( V_20 -> V_254 == V_20 -> V_252 )
V_380 = 0 ;
}
V_381 = V_20 -> V_87 ;
V_381 += V_381 << 1 ;
V_381 >>= 2 ;
F_21 ( L_24 , V_380 ,
V_381 ) ;
if ( V_380 >= V_381 ) {
F_76 ( V_20 ) ;
V_43 . V_212 = V_248 ;
V_43 . V_201 = V_20 -> V_254 ;
F_112 ( V_20 , & V_43 ) ;
V_380 = 0 ;
}
if ( V_380 )
F_185 ( V_20 ) ;
}
}
static inline int F_186 ( struct V_8 * V_20 ,
struct V_383 * V_384 , int V_183 ,
int V_385 , struct V_38 * V_42 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * * V_386 ;
int V_376 = 0 ;
if ( V_20 -> V_32 -> V_387 ( V_20 , F_110 ( V_42 , V_385 ) ,
V_384 -> V_388 , V_385 ) )
return - V_389 ;
V_376 += V_385 ;
V_183 -= V_385 ;
V_386 = & F_187 ( V_42 ) -> V_390 ;
while ( V_183 ) {
struct V_38 * V_312 ;
V_385 = F_63 (unsigned int, conn->mtu, len) ;
V_312 = V_20 -> V_32 -> V_391 ( V_20 , 0 , V_385 ,
V_384 -> V_392 & V_393 ) ;
if ( F_115 ( V_312 ) )
return F_188 ( V_312 ) ;
* V_386 = V_312 ;
if ( V_20 -> V_32 -> V_387 ( V_20 , F_110 ( * V_386 , V_385 ) ,
V_384 -> V_388 , V_385 ) )
return - V_389 ;
V_376 += V_385 ;
V_183 -= V_385 ;
V_42 -> V_183 += ( * V_386 ) -> V_183 ;
V_42 -> V_394 += ( * V_386 ) -> V_183 ;
V_386 = & ( * V_386 ) -> V_357 ;
}
return V_376 ;
}
static struct V_38 * F_189 ( struct V_8 * V_20 ,
struct V_383 * V_384 , T_7 V_183 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_385 , V_243 = V_238 + V_395 ;
struct V_241 * V_242 ;
F_21 ( L_25 , V_20 ,
F_66 ( V_20 -> V_17 ) , V_183 ) ;
V_385 = F_63 (unsigned int, (conn->mtu - hlen), len) ;
V_42 = V_20 -> V_32 -> V_391 ( V_20 , V_243 , V_385 ,
V_384 -> V_392 & V_393 ) ;
if ( F_115 ( V_42 ) )
return V_42 ;
V_242 = (struct V_241 * ) F_110 ( V_42 , V_238 ) ;
V_242 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_242 -> V_183 = F_16 ( V_183 + V_395 ) ;
F_190 ( V_20 -> V_17 , ( T_4 * ) F_110 ( V_42 , V_395 ) ) ;
V_21 = F_186 ( V_20 , V_384 , V_183 , V_385 , V_42 ) ;
if ( F_191 ( V_21 < 0 ) ) {
F_94 ( V_42 ) ;
return F_109 ( V_21 ) ;
}
return V_42 ;
}
static struct V_38 * F_192 ( struct V_8 * V_20 ,
struct V_383 * V_384 , T_7 V_183 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_385 ;
struct V_241 * V_242 ;
F_21 ( L_26 , V_20 , V_183 ) ;
V_385 = F_63 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_42 = V_20 -> V_32 -> V_391 ( V_20 , V_238 , V_385 ,
V_384 -> V_392 & V_393 ) ;
if ( F_115 ( V_42 ) )
return V_42 ;
V_242 = (struct V_241 * ) F_110 ( V_42 , V_238 ) ;
V_242 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_242 -> V_183 = F_16 ( V_183 ) ;
V_21 = F_186 ( V_20 , V_384 , V_183 , V_385 , V_42 ) ;
if ( F_191 ( V_21 < 0 ) ) {
F_94 ( V_42 ) ;
return F_109 ( V_21 ) ;
}
return V_42 ;
}
static struct V_38 * F_193 ( struct V_8 * V_20 ,
struct V_383 * V_384 , T_7 V_183 ,
T_2 V_396 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_385 , V_243 ;
struct V_241 * V_242 ;
F_21 ( L_26 , V_20 , V_183 ) ;
if ( ! V_10 )
return F_109 ( - V_377 ) ;
V_243 = F_106 ( V_20 ) ;
if ( V_396 )
V_243 += V_397 ;
if ( V_20 -> V_78 == V_79 )
V_243 += V_244 ;
V_385 = F_63 (unsigned int, (conn->mtu - hlen), len) ;
V_42 = V_20 -> V_32 -> V_391 ( V_20 , V_243 , V_385 ,
V_384 -> V_392 & V_393 ) ;
if ( F_115 ( V_42 ) )
return V_42 ;
V_242 = (struct V_241 * ) F_110 ( V_42 , V_238 ) ;
V_242 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_242 -> V_183 = F_16 ( V_183 + ( V_243 - V_238 ) ) ;
if ( F_73 ( V_234 , & V_20 -> V_94 ) )
F_104 ( 0 , F_110 ( V_42 , V_235 ) ) ;
else
F_105 ( 0 , F_110 ( V_42 , V_236 ) ) ;
if ( V_396 )
F_105 ( V_396 , F_110 ( V_42 , V_397 ) ) ;
V_21 = F_186 ( V_20 , V_384 , V_183 , V_385 , V_42 ) ;
if ( F_191 ( V_21 < 0 ) ) {
F_94 ( V_42 ) ;
return F_109 ( V_21 ) ;
}
F_33 ( V_42 ) -> V_43 . V_78 = V_20 -> V_78 ;
F_33 ( V_42 ) -> V_43 . V_274 = 0 ;
return V_42 ;
}
static int F_194 ( struct V_8 * V_20 ,
struct V_39 * V_398 ,
struct V_383 * V_384 , T_7 V_183 )
{
struct V_38 * V_42 ;
T_2 V_97 ;
T_7 V_399 ;
T_3 V_215 ;
F_21 ( L_27 , V_20 , V_384 , V_183 ) ;
V_399 = V_20 -> V_10 -> V_154 ;
if ( ! V_20 -> V_196 )
V_399 = F_63 ( T_7 , V_399 , V_400 ) ;
if ( V_20 -> V_78 )
V_399 -= V_244 ;
V_399 -= F_106 ( V_20 ) ;
V_399 = F_63 ( T_7 , V_399 , V_20 -> V_401 ) ;
if ( V_183 <= V_399 ) {
V_215 = V_402 ;
V_97 = 0 ;
V_399 = V_183 ;
} else {
V_215 = V_403 ;
V_97 = V_183 ;
V_399 -= V_397 ;
}
while ( V_183 > 0 ) {
V_42 = F_193 ( V_20 , V_384 , V_399 , V_97 ) ;
if ( F_115 ( V_42 ) ) {
F_195 ( V_398 ) ;
return F_188 ( V_42 ) ;
}
F_33 ( V_42 ) -> V_43 . V_215 = V_215 ;
F_196 ( V_398 , V_42 ) ;
V_183 -= V_399 ;
if ( V_97 ) {
V_97 = 0 ;
V_399 += V_397 ;
}
if ( V_183 <= V_399 ) {
V_215 = V_404 ;
V_399 = V_183 ;
} else {
V_215 = V_405 ;
}
}
return 0 ;
}
static struct V_38 * F_197 ( struct V_8 * V_20 ,
struct V_383 * V_384 ,
T_7 V_183 , T_2 V_396 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_385 , V_243 ;
struct V_241 * V_242 ;
F_21 ( L_26 , V_20 , V_183 ) ;
if ( ! V_10 )
return F_109 ( - V_377 ) ;
V_243 = V_238 ;
if ( V_396 )
V_243 += V_397 ;
V_385 = F_63 (unsigned int, (conn->mtu - hlen), len) ;
V_42 = V_20 -> V_32 -> V_391 ( V_20 , V_243 , V_385 ,
V_384 -> V_392 & V_393 ) ;
if ( F_115 ( V_42 ) )
return V_42 ;
V_242 = (struct V_241 * ) F_110 ( V_42 , V_238 ) ;
V_242 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_242 -> V_183 = F_16 ( V_183 + ( V_243 - V_238 ) ) ;
if ( V_396 )
F_105 ( V_396 , F_110 ( V_42 , V_397 ) ) ;
V_21 = F_186 ( V_20 , V_384 , V_183 , V_385 , V_42 ) ;
if ( F_191 ( V_21 < 0 ) ) {
F_94 ( V_42 ) ;
return F_109 ( V_21 ) ;
}
return V_42 ;
}
static int F_198 ( struct V_8 * V_20 ,
struct V_39 * V_398 ,
struct V_383 * V_384 , T_7 V_183 )
{
struct V_38 * V_42 ;
T_7 V_399 ;
T_2 V_97 ;
F_21 ( L_27 , V_20 , V_384 , V_183 ) ;
V_399 = V_20 -> V_10 -> V_154 - V_238 ;
V_399 = F_63 ( T_7 , V_399 , V_20 -> V_401 ) ;
V_97 = V_183 ;
V_399 -= V_397 ;
while ( V_183 > 0 ) {
if ( V_183 <= V_399 )
V_399 = V_183 ;
V_42 = F_197 ( V_20 , V_384 , V_399 , V_97 ) ;
if ( F_115 ( V_42 ) ) {
F_195 ( V_398 ) ;
return F_188 ( V_42 ) ;
}
F_196 ( V_398 , V_42 ) ;
V_183 -= V_399 ;
if ( V_97 ) {
V_97 = 0 ;
V_399 += V_397 ;
}
}
return 0 ;
}
int F_199 ( struct V_8 * V_20 , struct V_383 * V_384 , T_7 V_183 )
{
struct V_38 * V_42 ;
int V_21 ;
struct V_39 V_398 ;
if ( ! V_20 -> V_10 )
return - V_377 ;
if ( V_20 -> V_107 == V_112 ) {
V_42 = F_189 ( V_20 , V_384 , V_183 ) ;
if ( F_115 ( V_42 ) )
return F_188 ( V_42 ) ;
if ( V_20 -> V_31 != V_61 ) {
F_94 ( V_42 ) ;
return - V_377 ;
}
F_93 ( V_20 , V_42 ) ;
return V_183 ;
}
switch ( V_20 -> V_136 ) {
case V_138 :
if ( V_183 > V_20 -> V_110 )
return - V_406 ;
if ( ! V_20 -> V_98 )
return - V_407 ;
F_200 ( & V_398 ) ;
V_21 = F_198 ( V_20 , & V_398 , V_384 , V_183 ) ;
if ( V_20 -> V_31 != V_61 ) {
F_195 ( & V_398 ) ;
V_21 = - V_377 ;
}
if ( V_21 )
return V_21 ;
F_168 ( & V_398 , & V_20 -> V_104 ) ;
while ( V_20 -> V_98 && ! F_169 ( & V_20 -> V_104 ) ) {
F_93 ( V_20 , F_170 ( & V_20 -> V_104 ) ) ;
V_20 -> V_98 -- ;
}
if ( ! V_20 -> V_98 )
V_20 -> V_32 -> V_290 ( V_20 ) ;
V_21 = V_183 ;
break;
case V_137 :
if ( V_183 > V_20 -> V_110 )
return - V_406 ;
V_42 = F_192 ( V_20 , V_384 , V_183 ) ;
if ( F_115 ( V_42 ) )
return F_188 ( V_42 ) ;
if ( V_20 -> V_31 != V_61 ) {
F_94 ( V_42 ) ;
return - V_377 ;
}
F_93 ( V_20 , V_42 ) ;
V_21 = V_183 ;
break;
case V_139 :
case V_143 :
if ( V_183 > V_20 -> V_110 ) {
V_21 = - V_406 ;
break;
}
F_200 ( & V_398 ) ;
V_21 = F_194 ( V_20 , & V_398 , V_384 , V_183 ) ;
if ( V_20 -> V_31 != V_61 ) {
F_195 ( & V_398 ) ;
V_21 = - V_377 ;
}
if ( V_21 )
break;
if ( V_20 -> V_136 == V_139 )
F_126 ( V_20 , NULL , & V_398 , V_408 ) ;
else
F_167 ( V_20 , & V_398 ) ;
V_21 = V_183 ;
F_195 ( & V_398 ) ;
break;
default:
F_21 ( L_28 , V_20 -> V_136 ) ;
V_21 = - V_409 ;
}
return V_21 ;
}
static void F_201 ( struct V_8 * V_20 , T_2 V_44 )
{
struct V_200 V_43 ;
T_2 V_41 ;
F_21 ( L_29 , V_20 , V_44 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_208 = 1 ;
V_43 . V_212 = V_251 ;
for ( V_41 = V_20 -> V_275 ; V_41 != V_44 ;
V_41 = F_171 ( V_20 , V_41 ) ) {
if ( ! F_31 ( & V_20 -> V_140 , V_41 ) ) {
V_43 . V_201 = V_41 ;
F_112 ( V_20 , & V_43 ) ;
F_42 ( & V_20 -> V_141 , V_41 ) ;
}
}
V_20 -> V_275 = F_171 ( V_20 , V_44 ) ;
}
static void F_202 ( struct V_8 * V_20 )
{
struct V_200 V_43 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_141 . V_55 == V_54 )
return;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_208 = 1 ;
V_43 . V_212 = V_251 ;
V_43 . V_201 = V_20 -> V_141 . V_55 ;
F_112 ( V_20 , & V_43 ) ;
}
static void F_203 ( struct V_8 * V_20 , T_2 V_44 )
{
struct V_200 V_43 ;
T_2 V_410 ;
T_2 V_41 ;
F_21 ( L_29 , V_20 , V_44 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_208 = 1 ;
V_43 . V_212 = V_251 ;
V_410 = V_20 -> V_141 . V_40 ;
do {
V_41 = F_40 ( & V_20 -> V_141 ) ;
if ( V_41 == V_44 || V_41 == V_54 )
break;
V_43 . V_201 = V_41 ;
F_112 ( V_20 , & V_43 ) ;
F_42 ( & V_20 -> V_141 , V_41 ) ;
} while ( V_20 -> V_141 . V_40 != V_410 );
}
static void F_204 ( struct V_8 * V_20 , T_2 V_201 )
{
struct V_38 * V_411 ;
T_2 V_412 ;
F_21 ( L_30 , V_20 , V_201 ) ;
if ( V_20 -> V_379 == 0 || V_201 == V_20 -> V_413 )
return;
F_21 ( L_31 ,
V_20 -> V_413 , V_20 -> V_379 ) ;
for ( V_412 = V_20 -> V_413 ; V_412 != V_201 ;
V_412 = F_171 ( V_20 , V_412 ) ) {
V_411 = F_31 ( & V_20 -> V_104 , V_412 ) ;
if ( V_411 ) {
F_205 ( V_411 , & V_20 -> V_104 ) ;
F_94 ( V_411 ) ;
V_20 -> V_379 -- ;
}
}
V_20 -> V_413 = V_201 ;
if ( V_20 -> V_379 == 0 )
F_30 ( V_20 ) ;
F_21 ( L_32 , V_20 -> V_379 ) ;
}
static void F_206 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_275 = V_20 -> V_254 ;
F_41 ( & V_20 -> V_141 ) ;
F_74 ( & V_20 -> V_140 ) ;
V_20 -> V_280 = V_382 ;
}
static void F_207 ( struct V_8 * V_20 ,
struct V_200 * V_43 ,
struct V_39 * V_372 , T_3 V_414 )
{
F_21 ( L_33 , V_20 , V_43 , V_372 ,
V_414 ) ;
switch ( V_414 ) {
case V_408 :
if ( V_20 -> V_378 == NULL )
V_20 -> V_378 = F_208 ( V_372 ) ;
F_168 ( V_372 , & V_20 -> V_104 ) ;
F_172 ( V_20 ) ;
break;
case V_415 :
F_21 ( L_34 ) ;
F_54 ( V_253 , & V_20 -> V_247 ) ;
if ( V_20 -> V_280 == V_416 ) {
F_206 ( V_20 ) ;
}
F_183 ( V_20 ) ;
break;
case V_417 :
F_21 ( L_35 ) ;
F_114 ( V_253 , & V_20 -> V_247 ) ;
if ( F_73 ( V_249 , & V_20 -> V_247 ) ) {
struct V_200 V_418 ;
memset ( & V_418 , 0 , sizeof( V_418 ) ) ;
V_418 . V_208 = 1 ;
V_418 . V_212 = V_248 ;
V_418 . V_209 = 1 ;
V_418 . V_201 = V_20 -> V_254 ;
F_112 ( V_20 , & V_418 ) ;
V_20 -> V_273 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_278 = V_419 ;
}
break;
case V_420 :
F_204 ( V_20 , V_43 -> V_201 ) ;
break;
case V_286 :
F_116 ( V_20 , 1 ) ;
V_20 -> V_273 = 1 ;
F_29 ( V_20 ) ;
F_76 ( V_20 ) ;
V_20 -> V_278 = V_419 ;
break;
case V_371 :
F_116 ( V_20 , 1 ) ;
V_20 -> V_273 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_278 = V_419 ;
break;
case V_421 :
break;
default:
break;
}
}
static void F_209 ( struct V_8 * V_20 ,
struct V_200 * V_43 ,
struct V_39 * V_372 , T_3 V_414 )
{
F_21 ( L_33 , V_20 , V_43 , V_372 ,
V_414 ) ;
switch ( V_414 ) {
case V_408 :
if ( V_20 -> V_378 == NULL )
V_20 -> V_378 = F_208 ( V_372 ) ;
F_168 ( V_372 , & V_20 -> V_104 ) ;
break;
case V_415 :
F_21 ( L_34 ) ;
F_54 ( V_253 , & V_20 -> V_247 ) ;
if ( V_20 -> V_280 == V_416 ) {
F_206 ( V_20 ) ;
}
F_183 ( V_20 ) ;
break;
case V_417 :
F_21 ( L_35 ) ;
F_114 ( V_253 , & V_20 -> V_247 ) ;
if ( F_73 ( V_249 , & V_20 -> V_247 ) ) {
struct V_200 V_418 ;
memset ( & V_418 , 0 , sizeof( V_418 ) ) ;
V_418 . V_208 = 1 ;
V_418 . V_212 = V_248 ;
V_418 . V_209 = 1 ;
V_418 . V_201 = V_20 -> V_254 ;
F_112 ( V_20 , & V_418 ) ;
V_20 -> V_273 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_278 = V_419 ;
}
break;
case V_420 :
F_204 ( V_20 , V_43 -> V_201 ) ;
case V_421 :
if ( V_43 && V_43 -> V_204 ) {
F_75 ( V_20 ) ;
if ( V_20 -> V_379 > 0 )
F_25 ( V_20 ) ;
V_20 -> V_273 = 0 ;
V_20 -> V_278 = V_279 ;
F_21 ( L_36 , V_20 -> V_278 ) ;
}
break;
case V_286 :
break;
case V_370 :
if ( V_20 -> V_80 == 0 || V_20 -> V_273 < V_20 -> V_80 ) {
F_116 ( V_20 , 1 ) ;
F_29 ( V_20 ) ;
V_20 -> V_273 ++ ;
} else {
F_83 ( V_20 , V_422 ) ;
}
break;
default:
break;
}
}
static void F_126 ( struct V_8 * V_20 , struct V_200 * V_43 ,
struct V_39 * V_372 , T_3 V_414 )
{
F_21 ( L_37 ,
V_20 , V_43 , V_372 , V_414 , V_20 -> V_278 ) ;
switch ( V_20 -> V_278 ) {
case V_279 :
F_207 ( V_20 , V_43 , V_372 , V_414 ) ;
break;
case V_419 :
F_209 ( V_20 , V_43 , V_372 , V_414 ) ;
break;
default:
break;
}
}
static void F_210 ( struct V_8 * V_20 ,
struct V_200 * V_43 )
{
F_21 ( L_10 , V_20 , V_43 ) ;
F_126 ( V_20 , V_43 , NULL , V_420 ) ;
}
static void F_211 ( struct V_8 * V_20 ,
struct V_200 * V_43 )
{
F_21 ( L_10 , V_20 , V_43 ) ;
F_126 ( V_20 , V_43 , NULL , V_421 ) ;
}
static void F_212 ( struct V_9 * V_10 , struct V_38 * V_42 )
{
struct V_38 * V_423 ;
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( V_20 -> V_107 != V_165 )
continue;
if ( F_33 ( V_42 ) -> V_20 == V_20 )
continue;
V_423 = F_173 ( V_42 , V_51 ) ;
if ( ! V_423 )
continue;
if ( V_20 -> V_32 -> V_424 ( V_20 , V_423 ) )
F_94 ( V_423 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static struct V_38 * F_89 ( struct V_9 * V_10 , T_3 V_182 ,
T_3 V_16 , T_2 V_425 , void * V_184 )
{
struct V_38 * V_42 , * * V_386 ;
struct V_426 * V_427 ;
struct V_241 * V_242 ;
int V_183 , V_385 ;
F_21 ( L_38 ,
V_10 , V_182 , V_16 , V_425 ) ;
if ( V_10 -> V_154 < V_238 + V_428 )
return NULL ;
V_183 = V_238 + V_428 + V_425 ;
V_385 = F_63 (unsigned int, conn->mtu, len) ;
V_42 = F_108 ( V_385 , V_51 ) ;
if ( ! V_42 )
return NULL ;
V_242 = (struct V_241 * ) F_110 ( V_42 , V_238 ) ;
V_242 -> V_183 = F_16 ( V_428 + V_425 ) ;
if ( V_10 -> V_2 -> type == V_3 )
V_242 -> V_11 = F_16 ( V_429 ) ;
else
V_242 -> V_11 = F_16 ( V_115 ) ;
V_427 = (struct V_426 * ) F_110 ( V_42 , V_428 ) ;
V_427 -> V_182 = V_182 ;
V_427 -> V_16 = V_16 ;
V_427 -> V_183 = F_16 ( V_425 ) ;
if ( V_425 ) {
V_385 -= V_238 + V_428 ;
memcpy ( F_110 ( V_42 , V_385 ) , V_184 , V_385 ) ;
V_184 += V_385 ;
}
V_183 -= V_42 -> V_183 ;
V_386 = & F_187 ( V_42 ) -> V_390 ;
while ( V_183 ) {
V_385 = F_63 (unsigned int, conn->mtu, len) ;
* V_386 = F_108 ( V_385 , V_51 ) ;
if ( ! * V_386 )
goto V_430;
memcpy ( F_110 ( * V_386 , V_385 ) , V_184 , V_385 ) ;
V_183 -= V_385 ;
V_184 += V_385 ;
V_386 = & ( * V_386 ) -> V_357 ;
}
return V_42 ;
V_430:
F_94 ( V_42 ) ;
return NULL ;
}
static inline int F_213 ( void * * V_431 , int * type , int * V_432 ,
unsigned long * V_433 )
{
struct V_434 * V_435 = * V_431 ;
int V_183 ;
V_183 = V_436 + V_435 -> V_183 ;
* V_431 += V_183 ;
* type = V_435 -> type ;
* V_432 = V_435 -> V_183 ;
switch ( V_435 -> V_183 ) {
case 1 :
* V_433 = * ( ( T_3 * ) V_435 -> V_433 ) ;
break;
case 2 :
* V_433 = F_100 ( V_435 -> V_433 ) ;
break;
case 4 :
* V_433 = F_98 ( V_435 -> V_433 ) ;
break;
default:
* V_433 = ( unsigned long ) V_435 -> V_433 ;
break;
}
F_21 ( L_39 , * type , V_435 -> V_183 , * V_433 ) ;
return V_183 ;
}
static void F_214 ( void * * V_431 , T_3 type , T_3 V_183 , unsigned long V_433 )
{
struct V_434 * V_435 = * V_431 ;
F_21 ( L_39 , type , V_183 , V_433 ) ;
V_435 -> type = type ;
V_435 -> V_183 = V_183 ;
switch ( V_183 ) {
case 1 :
* ( ( T_3 * ) V_435 -> V_433 ) = V_433 ;
break;
case 2 :
F_105 ( V_433 , V_435 -> V_433 ) ;
break;
case 4 :
F_104 ( V_433 , V_435 -> V_433 ) ;
break;
default:
memcpy ( V_435 -> V_433 , ( void * ) V_433 , V_183 ) ;
break;
}
* V_431 += V_436 + V_183 ;
}
static void F_215 ( void * * V_431 , struct V_8 * V_20 )
{
struct V_437 V_438 ;
switch ( V_20 -> V_136 ) {
case V_139 :
V_438 . V_179 = V_20 -> V_116 ;
V_438 . V_439 = V_20 -> V_118 ;
V_438 . V_440 = F_16 ( V_20 -> V_120 ) ;
V_438 . V_441 = F_216 ( V_20 -> V_122 ) ;
V_438 . V_442 = F_216 ( V_125 ) ;
V_438 . V_89 = F_216 ( V_127 ) ;
break;
case V_143 :
V_438 . V_179 = 1 ;
V_438 . V_439 = V_119 ;
V_438 . V_440 = F_16 ( V_20 -> V_120 ) ;
V_438 . V_441 = F_216 ( V_20 -> V_122 ) ;
V_438 . V_442 = 0 ;
V_438 . V_89 = 0 ;
break;
default:
return;
}
F_214 ( V_431 , V_443 , sizeof( V_438 ) ,
( unsigned long ) & V_438 ) ;
}
static void F_217 ( struct V_57 * V_58 )
{
struct V_8 * V_20 = F_44 ( V_58 , struct V_8 ,
V_444 . V_58 ) ;
T_2 V_380 ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
V_380 = F_184 ( V_20 , V_20 -> V_254 ,
V_20 -> V_252 ) ;
if ( V_380 )
F_116 ( V_20 , 0 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
int F_218 ( struct V_8 * V_20 )
{
int V_21 ;
V_20 -> V_373 = 0 ;
V_20 -> V_275 = 0 ;
V_20 -> V_413 = 0 ;
V_20 -> V_379 = 0 ;
V_20 -> V_254 = 0 ;
V_20 -> V_374 = 0 ;
V_20 -> V_252 = 0 ;
V_20 -> V_95 = NULL ;
V_20 -> V_96 = NULL ;
V_20 -> V_97 = 0 ;
F_64 ( & V_20 -> V_104 ) ;
V_20 -> V_445 = V_446 ;
V_20 -> V_447 = V_446 ;
V_20 -> V_193 = V_194 ;
V_20 -> V_283 = V_284 ;
if ( V_20 -> V_136 != V_139 )
return 0 ;
V_20 -> V_280 = V_382 ;
V_20 -> V_278 = V_279 ;
F_52 ( & V_20 -> V_36 , F_166 ) ;
F_52 ( & V_20 -> V_34 , F_165 ) ;
F_52 ( & V_20 -> V_444 , F_217 ) ;
F_64 ( & V_20 -> V_140 ) ;
V_21 = F_34 ( & V_20 -> V_141 , V_20 -> V_82 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_34 ( & V_20 -> V_142 , V_20 -> V_86 ) ;
if ( V_21 < 0 )
F_37 ( & V_20 -> V_141 ) ;
return V_21 ;
}
static inline T_1 F_219 ( T_1 V_136 , T_6 V_448 )
{
switch ( V_136 ) {
case V_143 :
case V_139 :
if ( F_135 ( V_136 , V_448 ) )
return V_136 ;
default:
return V_137 ;
}
}
static inline bool F_220 ( struct V_9 * V_10 )
{
return V_10 -> V_258 && V_10 -> V_304 & V_449 ;
}
static inline bool F_221 ( struct V_9 * V_10 )
{
return V_10 -> V_258 && V_10 -> V_304 & V_450 ;
}
static void F_222 ( struct V_8 * V_20 ,
struct V_451 * V_452 )
{
if ( V_20 -> V_445 != V_446 && V_20 -> V_196 ) {
T_10 V_453 = V_20 -> V_196 -> V_185 -> V_454 ;
V_453 = F_223 ( V_453 , 1000 ) ;
V_453 = 3 * V_453 + 500 ;
if ( V_453 > 0xffff )
V_453 = 0xffff ;
V_452 -> V_35 = F_16 ( ( T_2 ) V_453 ) ;
V_452 -> V_37 = V_452 -> V_35 ;
} else {
V_452 -> V_35 = F_16 ( V_91 ) ;
V_452 -> V_37 = F_16 ( V_92 ) ;
}
}
static inline void F_224 ( struct V_8 * V_20 )
{
if ( V_20 -> V_82 > V_83 &&
F_220 ( V_20 -> V_10 ) ) {
F_54 ( V_234 , & V_20 -> V_94 ) ;
V_20 -> V_84 = V_455 ;
} else {
V_20 -> V_82 = F_63 ( T_2 , V_20 -> V_82 ,
V_83 ) ;
V_20 -> V_84 = V_83 ;
}
V_20 -> V_87 = V_20 -> V_82 ;
}
static int F_138 ( struct V_8 * V_20 , void * V_184 )
{
struct V_456 * V_268 = V_184 ;
struct V_451 V_452 = { . V_136 = V_20 -> V_136 } ;
void * V_431 = V_268 -> V_184 ;
T_2 V_47 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_323 || V_20 -> V_457 )
goto V_24;
switch ( V_20 -> V_136 ) {
case V_143 :
case V_139 :
if ( F_73 ( V_313 , & V_20 -> V_76 ) )
break;
if ( F_221 ( V_20 -> V_10 ) )
F_54 ( V_458 , & V_20 -> V_94 ) ;
default:
V_20 -> V_136 = F_219 ( V_452 . V_136 , V_20 -> V_10 -> V_304 ) ;
break;
}
V_24:
if ( V_20 -> V_102 != V_111 )
F_214 ( & V_431 , V_459 , 2 , V_20 -> V_102 ) ;
switch ( V_20 -> V_136 ) {
case V_137 :
if ( V_307 )
break;
if ( ! ( V_20 -> V_10 -> V_304 & V_308 ) &&
! ( V_20 -> V_10 -> V_304 & V_309 ) )
break;
V_452 . V_136 = V_137 ;
V_452 . V_460 = 0 ;
V_452 . V_461 = 0 ;
V_452 . V_35 = 0 ;
V_452 . V_37 = 0 ;
V_452 . V_462 = 0 ;
F_214 ( & V_431 , V_463 , sizeof( V_452 ) ,
( unsigned long ) & V_452 ) ;
break;
case V_139 :
V_452 . V_136 = V_139 ;
V_452 . V_461 = V_20 -> V_80 ;
F_222 ( V_20 , & V_452 ) ;
V_47 = F_63 ( T_2 , V_464 , V_20 -> V_10 -> V_154 -
V_239 - V_397 -
V_244 ) ;
V_452 . V_462 = F_16 ( V_47 ) ;
F_224 ( V_20 ) ;
V_452 . V_460 = F_63 ( T_2 , V_20 -> V_82 ,
V_83 ) ;
F_214 ( & V_431 , V_463 , sizeof( V_452 ) ,
( unsigned long ) & V_452 ) ;
if ( F_73 ( V_458 , & V_20 -> V_94 ) )
F_215 ( & V_431 , V_20 ) ;
if ( F_73 ( V_234 , & V_20 -> V_94 ) )
F_214 ( & V_431 , V_465 , 2 ,
V_20 -> V_82 ) ;
if ( V_20 -> V_10 -> V_304 & V_466 )
if ( V_20 -> V_78 == V_467 ||
F_73 ( V_468 , & V_20 -> V_76 ) ) {
V_20 -> V_78 = V_467 ;
F_214 ( & V_431 , V_469 , 1 ,
V_20 -> V_78 ) ;
}
break;
case V_143 :
F_224 ( V_20 ) ;
V_452 . V_136 = V_143 ;
V_452 . V_460 = 0 ;
V_452 . V_461 = 0 ;
V_452 . V_35 = 0 ;
V_452 . V_37 = 0 ;
V_47 = F_63 ( T_2 , V_464 , V_20 -> V_10 -> V_154 -
V_239 - V_397 -
V_244 ) ;
V_452 . V_462 = F_16 ( V_47 ) ;
F_214 ( & V_431 , V_463 , sizeof( V_452 ) ,
( unsigned long ) & V_452 ) ;
if ( F_73 ( V_458 , & V_20 -> V_94 ) )
F_215 ( & V_431 , V_20 ) ;
if ( V_20 -> V_10 -> V_304 & V_466 )
if ( V_20 -> V_78 == V_467 ||
F_73 ( V_468 , & V_20 -> V_76 ) ) {
V_20 -> V_78 = V_467 ;
F_214 ( & V_431 , V_469 , 1 ,
V_20 -> V_78 ) ;
}
break;
}
V_268 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_268 -> V_94 = F_16 ( 0 ) ;
return V_431 - V_184 ;
}
static int F_225 ( struct V_8 * V_20 , void * V_184 )
{
struct V_470 * V_148 = V_184 ;
void * V_431 = V_148 -> V_184 ;
void * V_268 = V_20 -> V_471 ;
int V_183 = V_20 -> V_472 ;
int type , V_473 , V_432 ;
unsigned long V_433 ;
struct V_451 V_452 = { . V_136 = V_137 } ;
struct V_437 V_438 ;
T_3 V_474 = 0 ;
T_2 V_154 = V_111 ;
T_2 V_149 = V_475 ;
T_2 V_47 ;
F_21 ( L_3 , V_20 ) ;
while ( V_183 >= V_436 ) {
V_183 -= F_213 ( & V_268 , & type , & V_432 , & V_433 ) ;
V_473 = type & V_476 ;
type &= V_477 ;
switch ( type ) {
case V_459 :
V_154 = V_433 ;
break;
case V_478 :
V_20 -> V_89 = V_433 ;
break;
case V_479 :
break;
case V_463 :
if ( V_432 == sizeof( V_452 ) )
memcpy ( & V_452 , ( void * ) V_433 , V_432 ) ;
break;
case V_469 :
if ( V_433 == V_467 )
F_54 ( V_468 , & V_20 -> V_76 ) ;
break;
case V_443 :
V_474 = 1 ;
if ( V_432 == sizeof( V_438 ) )
memcpy ( & V_438 , ( void * ) V_433 , V_432 ) ;
break;
case V_465 :
if ( ! V_20 -> V_10 -> V_258 )
return - V_63 ;
F_54 ( V_234 , & V_20 -> V_94 ) ;
F_54 ( V_480 , & V_20 -> V_76 ) ;
V_20 -> V_84 = V_455 ;
V_20 -> V_86 = V_433 ;
break;
default:
if ( V_473 )
break;
V_149 = V_481 ;
* ( ( T_3 * ) V_431 ++ ) = type ;
break;
}
}
if ( V_20 -> V_457 || V_20 -> V_323 > 1 )
goto V_24;
switch ( V_20 -> V_136 ) {
case V_143 :
case V_139 :
if ( ! F_73 ( V_313 , & V_20 -> V_76 ) ) {
V_20 -> V_136 = F_219 ( V_452 . V_136 ,
V_20 -> V_10 -> V_304 ) ;
break;
}
if ( V_474 ) {
if ( F_221 ( V_20 -> V_10 ) )
F_54 ( V_458 , & V_20 -> V_94 ) ;
else
return - V_63 ;
}
if ( V_20 -> V_136 != V_452 . V_136 )
return - V_63 ;
break;
}
V_24:
if ( V_20 -> V_136 != V_452 . V_136 ) {
V_149 = V_482 ;
V_452 . V_136 = V_20 -> V_136 ;
if ( V_20 -> V_457 == 1 )
return - V_63 ;
F_214 ( & V_431 , V_463 , sizeof( V_452 ) ,
( unsigned long ) & V_452 ) ;
}
if ( V_149 == V_475 ) {
if ( V_154 < V_483 )
V_149 = V_482 ;
else {
V_20 -> V_110 = V_154 ;
F_54 ( V_484 , & V_20 -> V_76 ) ;
}
F_214 ( & V_431 , V_459 , 2 , V_20 -> V_110 ) ;
if ( V_474 ) {
if ( V_20 -> V_118 != V_485 &&
V_438 . V_439 != V_485 &&
V_438 . V_439 != V_20 -> V_118 ) {
V_149 = V_482 ;
if ( V_20 -> V_323 >= 1 )
return - V_63 ;
F_214 ( & V_431 , V_443 ,
sizeof( V_438 ) ,
( unsigned long ) & V_438 ) ;
} else {
V_149 = V_486 ;
F_54 ( V_487 , & V_20 -> V_76 ) ;
}
}
switch ( V_452 . V_136 ) {
case V_137 :
V_20 -> V_78 = V_467 ;
F_54 ( V_488 , & V_20 -> V_76 ) ;
break;
case V_139 :
if ( ! F_73 ( V_480 , & V_20 -> V_76 ) )
V_20 -> V_86 = V_452 . V_460 ;
else
V_452 . V_460 = V_83 ;
V_20 -> V_85 = V_452 . V_461 ;
V_47 = F_63 ( T_2 , F_226 ( V_452 . V_462 ) ,
V_20 -> V_10 -> V_154 - V_239 -
V_397 - V_244 ) ;
V_452 . V_462 = F_16 ( V_47 ) ;
V_20 -> V_401 = V_47 ;
F_222 ( V_20 , & V_452 ) ;
F_54 ( V_488 , & V_20 -> V_76 ) ;
F_214 ( & V_431 , V_463 ,
sizeof( V_452 ) , ( unsigned long ) & V_452 ) ;
if ( F_73 ( V_458 , & V_20 -> V_94 ) ) {
V_20 -> V_489 = V_438 . V_179 ;
V_20 -> V_490 = V_438 . V_439 ;
V_20 -> V_491 = F_226 ( V_438 . V_440 ) ;
V_20 -> V_492 =
F_227 ( V_438 . V_89 ) ;
V_20 -> V_493 =
F_227 ( V_438 . V_442 ) ;
V_20 -> V_494 =
F_227 ( V_438 . V_441 ) ;
F_214 ( & V_431 , V_443 ,
sizeof( V_438 ) ,
( unsigned long ) & V_438 ) ;
}
break;
case V_143 :
V_47 = F_63 ( T_2 , F_226 ( V_452 . V_462 ) ,
V_20 -> V_10 -> V_154 - V_239 -
V_397 - V_244 ) ;
V_452 . V_462 = F_16 ( V_47 ) ;
V_20 -> V_401 = V_47 ;
F_54 ( V_488 , & V_20 -> V_76 ) ;
F_214 ( & V_431 , V_463 , sizeof( V_452 ) ,
( unsigned long ) & V_452 ) ;
break;
default:
V_149 = V_482 ;
memset ( & V_452 , 0 , sizeof( V_452 ) ) ;
V_452 . V_136 = V_20 -> V_136 ;
}
if ( V_149 == V_475 )
F_54 ( V_495 , & V_20 -> V_76 ) ;
}
V_148 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 -> V_149 = F_16 ( V_149 ) ;
V_148 -> V_94 = F_16 ( 0 ) ;
return V_431 - V_184 ;
}
static int F_228 ( struct V_8 * V_20 , void * V_148 , int V_183 ,
void * V_184 , T_2 * V_149 )
{
struct V_456 * V_268 = V_184 ;
void * V_431 = V_268 -> V_184 ;
int type , V_432 ;
unsigned long V_433 ;
struct V_451 V_452 = { . V_136 = V_137 } ;
struct V_437 V_438 ;
F_21 ( L_40 , V_20 , V_148 , V_183 , V_184 ) ;
while ( V_183 >= V_436 ) {
V_183 -= F_213 ( & V_148 , & type , & V_432 , & V_433 ) ;
switch ( type ) {
case V_459 :
if ( V_433 < V_483 ) {
* V_149 = V_482 ;
V_20 -> V_102 = V_483 ;
} else
V_20 -> V_102 = V_433 ;
F_214 ( & V_431 , V_459 , 2 , V_20 -> V_102 ) ;
break;
case V_478 :
V_20 -> V_89 = V_433 ;
F_214 ( & V_431 , V_478 ,
2 , V_20 -> V_89 ) ;
break;
case V_463 :
if ( V_432 == sizeof( V_452 ) )
memcpy ( & V_452 , ( void * ) V_433 , V_432 ) ;
if ( F_73 ( V_313 , & V_20 -> V_76 ) &&
V_452 . V_136 != V_20 -> V_136 )
return - V_63 ;
V_20 -> V_78 = 0 ;
F_214 ( & V_431 , V_463 ,
sizeof( V_452 ) , ( unsigned long ) & V_452 ) ;
break;
case V_465 :
V_20 -> V_87 = F_63 ( T_2 , V_433 , V_20 -> V_87 ) ;
F_214 ( & V_431 , V_465 , 2 ,
V_20 -> V_82 ) ;
break;
case V_443 :
if ( V_432 == sizeof( V_438 ) )
memcpy ( & V_438 , ( void * ) V_433 , V_432 ) ;
if ( V_20 -> V_118 != V_485 &&
V_438 . V_439 != V_485 &&
V_438 . V_439 != V_20 -> V_118 )
return - V_63 ;
F_214 ( & V_431 , V_443 , sizeof( V_438 ) ,
( unsigned long ) & V_438 ) ;
break;
case V_469 :
if ( * V_149 == V_486 )
if ( V_433 == V_467 )
F_54 ( V_468 ,
& V_20 -> V_76 ) ;
break;
}
}
if ( V_20 -> V_136 == V_137 && V_20 -> V_136 != V_452 . V_136 )
return - V_63 ;
V_20 -> V_136 = V_452 . V_136 ;
if ( * V_149 == V_475 || * V_149 == V_486 ) {
switch ( V_452 . V_136 ) {
case V_139 :
V_20 -> V_35 = F_226 ( V_452 . V_35 ) ;
V_20 -> V_37 = F_226 ( V_452 . V_37 ) ;
V_20 -> V_101 = F_226 ( V_452 . V_462 ) ;
if ( ! F_73 ( V_234 , & V_20 -> V_94 ) )
V_20 -> V_87 = F_63 ( T_2 , V_20 -> V_87 ,
V_452 . V_460 ) ;
if ( F_73 ( V_458 , & V_20 -> V_94 ) ) {
V_20 -> V_120 = F_226 ( V_438 . V_440 ) ;
V_20 -> V_122 =
F_227 ( V_438 . V_441 ) ;
V_20 -> V_124 = F_227 ( V_438 . V_442 ) ;
V_20 -> V_126 =
F_227 ( V_438 . V_89 ) ;
}
break;
case V_143 :
V_20 -> V_101 = F_226 ( V_452 . V_462 ) ;
}
}
V_268 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_268 -> V_94 = F_16 ( 0 ) ;
return V_431 - V_184 ;
}
static int F_229 ( struct V_8 * V_20 , void * V_184 ,
T_2 V_149 , T_2 V_94 )
{
struct V_470 * V_148 = V_184 ;
void * V_431 = V_148 -> V_184 ;
F_21 ( L_3 , V_20 ) ;
V_148 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 -> V_149 = F_16 ( V_149 ) ;
V_148 -> V_94 = F_16 ( V_94 ) ;
return V_431 - V_184 ;
}
void F_230 ( struct V_8 * V_20 )
{
struct V_147 V_148 ;
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_3 , V_20 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_154 = F_16 ( V_20 -> V_102 ) ;
V_148 . V_101 = F_16 ( V_20 -> V_101 ) ;
V_148 . V_155 = F_16 ( V_20 -> V_99 ) ;
V_148 . V_149 = F_16 ( V_319 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_156 , sizeof( V_148 ) ,
& V_148 ) ;
}
void F_231 ( struct V_8 * V_20 )
{
struct V_157 V_148 ;
struct V_9 * V_10 = V_20 -> V_10 ;
T_3 V_315 [ 128 ] ;
T_3 V_496 ;
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_149 = F_16 ( V_319 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
if ( V_20 -> V_196 )
V_496 = V_497 ;
else
V_496 = V_161 ;
F_21 ( L_41 , V_20 , V_496 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_496 , sizeof( V_148 ) , & V_148 ) ;
if ( F_129 ( V_321 , & V_20 -> V_76 ) )
return;
F_80 ( V_10 , F_88 ( V_10 ) , V_322 ,
F_138 ( V_20 , V_315 ) , V_315 ) ;
V_20 -> V_323 ++ ;
}
static void F_232 ( struct V_8 * V_20 , void * V_148 , int V_183 )
{
int type , V_432 ;
unsigned long V_433 ;
T_2 V_498 = V_20 -> V_87 ;
struct V_451 V_452 = {
. V_136 = V_20 -> V_136 ,
. V_35 = F_16 ( V_91 ) ,
. V_37 = F_16 ( V_92 ) ,
. V_462 = F_16 ( V_20 -> V_102 ) ,
. V_460 = F_63 ( T_2 , V_20 -> V_87 , V_83 ) ,
} ;
F_21 ( L_42 , V_20 , V_148 , V_183 ) ;
if ( ( V_20 -> V_136 != V_139 ) && ( V_20 -> V_136 != V_143 ) )
return;
while ( V_183 >= V_436 ) {
V_183 -= F_213 ( & V_148 , & type , & V_432 , & V_433 ) ;
switch ( type ) {
case V_463 :
if ( V_432 == sizeof( V_452 ) )
memcpy ( & V_452 , ( void * ) V_433 , V_432 ) ;
break;
case V_465 :
V_498 = V_433 ;
break;
}
}
switch ( V_452 . V_136 ) {
case V_139 :
V_20 -> V_35 = F_226 ( V_452 . V_35 ) ;
V_20 -> V_37 = F_226 ( V_452 . V_37 ) ;
V_20 -> V_101 = F_226 ( V_452 . V_462 ) ;
if ( F_73 ( V_234 , & V_20 -> V_94 ) )
V_20 -> V_87 = F_63 ( T_2 , V_20 -> V_87 , V_498 ) ;
else
V_20 -> V_87 = F_63 ( T_2 , V_20 -> V_87 ,
V_452 . V_460 ) ;
break;
case V_143 :
V_20 -> V_101 = F_226 ( V_452 . V_462 ) ;
}
}
static inline int F_233 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
struct V_500 * V_501 = (struct V_500 * ) V_184 ;
if ( V_499 < sizeof( * V_501 ) )
return - V_502 ;
if ( V_501 -> V_60 != V_503 )
return 0 ;
if ( ( V_10 -> V_295 & V_296 ) &&
V_427 -> V_16 == V_10 -> V_300 ) {
F_234 ( & V_10 -> V_301 ) ;
V_10 -> V_295 |= V_297 ;
V_10 -> V_300 = 0 ;
F_136 ( V_10 ) ;
}
return 0 ;
}
static struct V_8 * F_235 ( struct V_9 * V_10 ,
struct V_426 * V_427 ,
T_3 * V_184 , T_3 V_496 , T_3 V_270 )
{
struct V_267 * V_268 = (struct V_267 * ) V_184 ;
struct V_157 V_148 ;
struct V_8 * V_20 = NULL , * V_330 ;
int V_149 , V_159 = V_160 ;
T_2 V_13 = 0 , V_14 = F_66 ( V_268 -> V_14 ) ;
T_4 V_17 = V_268 -> V_17 ;
F_21 ( L_43 , F_66 ( V_17 ) , V_14 ) ;
V_330 = F_164 ( V_162 , V_17 , & V_10 -> V_2 -> V_18 ,
& V_10 -> V_2 -> V_145 , V_109 ) ;
if ( ! V_330 ) {
V_149 = V_152 ;
goto V_504;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_330 ) ;
if ( V_17 != F_16 ( V_174 ) &&
! F_236 ( V_10 -> V_2 ) ) {
V_10 -> V_105 = V_505 ;
V_149 = V_158 ;
goto V_506;
}
V_149 = V_507 ;
if ( F_2 ( V_10 , V_14 ) )
goto V_506;
V_20 = V_330 -> V_32 -> V_346 ( V_330 ) ;
if ( ! V_20 )
goto V_506;
V_10 -> V_2 -> V_508 = V_509 ;
F_78 ( & V_20 -> V_18 , & V_10 -> V_2 -> V_18 ) ;
F_78 ( & V_20 -> V_145 , & V_10 -> V_2 -> V_145 ) ;
V_20 -> V_348 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_348 ) ;
V_20 -> V_146 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_146 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_14 ;
V_20 -> V_445 = V_270 ;
F_65 ( V_10 , V_20 ) ;
V_13 = V_20 -> V_14 ;
F_82 ( V_20 , V_20 -> V_32 -> V_163 ( V_20 ) ) ;
V_20 -> V_16 = V_427 -> V_16 ;
if ( V_10 -> V_295 & V_297 ) {
if ( F_85 ( V_20 , false ) ) {
if ( F_73 ( V_150 , & V_20 -> V_94 ) ) {
F_20 ( V_20 , V_164 ) ;
V_149 = V_316 ;
V_159 = V_317 ;
V_20 -> V_32 -> V_318 ( V_20 ) ;
} else {
if ( V_270 == V_446 ) {
F_20 ( V_20 , V_62 ) ;
V_149 = V_319 ;
} else {
F_20 ( V_20 , V_164 ) ;
V_149 = V_316 ;
}
V_159 = V_160 ;
}
} else {
F_20 ( V_20 , V_164 ) ;
V_149 = V_316 ;
V_159 = V_320 ;
}
} else {
F_20 ( V_20 , V_164 ) ;
V_149 = V_316 ;
V_159 = V_160 ;
}
V_506:
F_46 ( V_330 ) ;
F_8 ( & V_10 -> V_15 ) ;
V_504:
V_148 . V_14 = F_16 ( V_14 ) ;
V_148 . V_13 = F_16 ( V_13 ) ;
V_148 . V_149 = F_16 ( V_149 ) ;
V_148 . V_159 = F_16 ( V_159 ) ;
F_80 ( V_10 , V_427 -> V_16 , V_496 , sizeof( V_148 ) , & V_148 ) ;
if ( V_149 == V_316 && V_159 == V_160 ) {
struct V_298 V_510 ;
V_510 . type = F_16 ( V_299 ) ;
V_10 -> V_295 |= V_296 ;
V_10 -> V_300 = F_88 ( V_10 ) ;
F_134 ( & V_10 -> V_301 , V_302 ) ;
F_80 ( V_10 , V_10 -> V_300 , V_303 ,
sizeof( V_510 ) , & V_510 ) ;
}
if ( V_20 && ! F_73 ( V_321 , & V_20 -> V_76 ) &&
V_149 == V_319 ) {
T_3 V_315 [ 128 ] ;
F_54 ( V_321 , & V_20 -> V_76 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_322 ,
F_138 ( V_20 , V_315 ) , V_315 ) ;
V_20 -> V_323 ++ ;
}
return V_20 ;
}
static int F_237 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 , T_3 * V_184 )
{
struct V_256 * V_185 = V_10 -> V_2 -> V_185 ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_499 < sizeof( struct V_267 ) )
return - V_502 ;
F_147 ( V_185 ) ;
if ( F_73 ( V_511 , & V_185 -> V_512 ) &&
! F_129 ( V_513 , & V_2 -> V_94 ) )
F_238 ( V_185 , & V_2 -> V_145 , V_2 -> type ,
V_2 -> V_146 , 0 , NULL , 0 ,
V_2 -> V_514 ) ;
F_148 ( V_185 ) ;
F_235 ( V_10 , V_427 , V_184 , V_161 , 0 ) ;
return 0 ;
}
static int F_239 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
struct V_157 * V_148 = (struct V_157 * ) V_184 ;
T_2 V_14 , V_13 , V_149 , V_159 ;
struct V_8 * V_20 ;
T_3 V_268 [ 128 ] ;
int V_21 ;
if ( V_499 < sizeof( * V_148 ) )
return - V_502 ;
V_14 = F_66 ( V_148 -> V_14 ) ;
V_13 = F_66 ( V_148 -> V_13 ) ;
V_149 = F_66 ( V_148 -> V_149 ) ;
V_159 = F_66 ( V_148 -> V_159 ) ;
F_21 ( L_44 ,
V_13 , V_14 , V_149 , V_159 ) ;
F_6 ( & V_10 -> V_15 ) ;
if ( V_14 ) {
V_20 = F_4 ( V_10 , V_14 ) ;
if ( ! V_20 ) {
V_21 = - V_515 ;
goto V_516;
}
} else {
V_20 = F_10 ( V_10 , V_427 -> V_16 ) ;
if ( ! V_20 ) {
V_21 = - V_515 ;
goto V_516;
}
}
V_21 = 0 ;
F_7 ( V_20 ) ;
switch ( V_149 ) {
case V_319 :
F_20 ( V_20 , V_62 ) ;
V_20 -> V_16 = 0 ;
V_20 -> V_13 = V_13 ;
F_114 ( V_255 , & V_20 -> V_76 ) ;
if ( F_129 ( V_321 , & V_20 -> V_76 ) )
break;
F_80 ( V_10 , F_88 ( V_10 ) , V_322 ,
F_138 ( V_20 , V_268 ) , V_268 ) ;
V_20 -> V_323 ++ ;
break;
case V_316 :
F_54 ( V_255 , & V_20 -> V_76 ) ;
break;
default:
F_69 ( V_20 , V_63 ) ;
break;
}
F_46 ( V_20 ) ;
V_516:
F_8 ( & V_10 -> V_15 ) ;
return V_21 ;
}
static inline void F_240 ( struct V_8 * V_20 )
{
if ( V_20 -> V_136 != V_139 && V_20 -> V_136 != V_143 )
V_20 -> V_78 = V_467 ;
else if ( ! F_73 ( V_468 , & V_20 -> V_76 ) )
V_20 -> V_78 = V_79 ;
}
static void F_241 ( struct V_8 * V_20 , void * V_184 ,
T_3 V_16 , T_2 V_94 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_45 , V_10 , V_20 , V_16 ,
V_94 ) ;
F_114 ( V_487 , & V_20 -> V_76 ) ;
F_54 ( V_495 , & V_20 -> V_76 ) ;
F_80 ( V_10 , V_16 , V_517 ,
F_229 ( V_20 , V_184 ,
V_475 , V_94 ) , V_184 ) ;
}
static void F_242 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_14 , T_2 V_13 )
{
struct V_518 V_501 ;
V_501 . V_60 = F_16 ( V_519 ) ;
V_501 . V_14 = F_243 ( V_14 ) ;
V_501 . V_13 = F_243 ( V_13 ) ;
F_80 ( V_10 , V_16 , V_520 , sizeof( V_501 ) , & V_501 ) ;
}
static inline int F_244 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
struct V_456 * V_268 = (struct V_456 * ) V_184 ;
T_2 V_13 , V_94 ;
T_3 V_148 [ 64 ] ;
struct V_8 * V_20 ;
int V_183 , V_21 = 0 ;
if ( V_499 < sizeof( * V_268 ) )
return - V_502 ;
V_13 = F_66 ( V_268 -> V_13 ) ;
V_94 = F_66 ( V_268 -> V_94 ) ;
F_21 ( L_46 , V_13 , V_94 ) ;
V_20 = F_5 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_242 ( V_10 , V_427 -> V_16 , V_13 , 0 ) ;
return 0 ;
}
if ( V_20 -> V_31 != V_62 && V_20 -> V_31 != V_164 ) {
F_242 ( V_10 , V_427 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
goto V_516;
}
V_183 = V_499 - sizeof( * V_268 ) ;
if ( V_20 -> V_472 + V_183 > sizeof( V_20 -> V_471 ) ) {
F_80 ( V_10 , V_427 -> V_16 , V_517 ,
F_229 ( V_20 , V_148 ,
V_521 , V_94 ) , V_148 ) ;
goto V_516;
}
memcpy ( V_20 -> V_471 + V_20 -> V_472 , V_268 -> V_184 , V_183 ) ;
V_20 -> V_472 += V_183 ;
if ( V_94 & V_522 ) {
F_80 ( V_10 , V_427 -> V_16 , V_517 ,
F_229 ( V_20 , V_148 ,
V_475 , V_94 ) , V_148 ) ;
goto V_516;
}
V_183 = F_225 ( V_20 , V_148 ) ;
if ( V_183 < 0 ) {
F_83 ( V_20 , V_314 ) ;
goto V_516;
}
V_20 -> V_16 = V_427 -> V_16 ;
F_80 ( V_10 , V_427 -> V_16 , V_517 , V_183 , V_148 ) ;
V_20 -> V_457 ++ ;
V_20 -> V_472 = 0 ;
if ( ! F_73 ( V_495 , & V_20 -> V_76 ) )
goto V_516;
if ( F_73 ( V_523 , & V_20 -> V_76 ) ) {
F_240 ( V_20 ) ;
if ( V_20 -> V_136 == V_139 ||
V_20 -> V_136 == V_143 )
V_21 = F_218 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_127 ( V_20 ) ;
goto V_516;
}
if ( ! F_129 ( V_321 , & V_20 -> V_76 ) ) {
T_3 V_315 [ 64 ] ;
F_80 ( V_10 , F_88 ( V_10 ) , V_322 ,
F_138 ( V_20 , V_315 ) , V_315 ) ;
V_20 -> V_323 ++ ;
}
if ( F_73 ( V_524 , & V_20 -> V_76 ) &&
F_73 ( V_487 , & V_20 -> V_76 ) ) {
if ( ! V_20 -> V_196 )
F_241 ( V_20 , V_148 , V_427 -> V_16 , V_94 ) ;
else
V_20 -> V_16 = V_427 -> V_16 ;
}
V_516:
F_46 ( V_20 ) ;
return V_21 ;
}
static inline int F_245 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
struct V_470 * V_148 = (struct V_470 * ) V_184 ;
T_2 V_14 , V_94 , V_149 ;
struct V_8 * V_20 ;
int V_183 = V_499 - sizeof( * V_148 ) ;
int V_21 = 0 ;
if ( V_499 < sizeof( * V_148 ) )
return - V_502 ;
V_14 = F_66 ( V_148 -> V_14 ) ;
V_94 = F_66 ( V_148 -> V_94 ) ;
V_149 = F_66 ( V_148 -> V_149 ) ;
F_21 ( L_47 , V_14 , V_94 ,
V_149 , V_183 ) ;
V_20 = F_5 ( V_10 , V_14 ) ;
if ( ! V_20 )
return 0 ;
switch ( V_149 ) {
case V_475 :
F_232 ( V_20 , V_148 -> V_184 , V_183 ) ;
F_114 ( V_524 , & V_20 -> V_76 ) ;
break;
case V_486 :
F_54 ( V_524 , & V_20 -> V_76 ) ;
if ( F_73 ( V_487 , & V_20 -> V_76 ) ) {
char V_315 [ 64 ] ;
V_183 = F_228 ( V_20 , V_148 -> V_184 , V_183 ,
V_315 , & V_149 ) ;
if ( V_183 < 0 ) {
F_83 ( V_20 , V_314 ) ;
goto V_24;
}
if ( ! V_20 -> V_196 ) {
F_241 ( V_20 , V_315 , V_427 -> V_16 ,
0 ) ;
} else {
if ( F_121 ( V_20 ) ) {
F_246 ( V_20 ) ;
V_20 -> V_16 = V_427 -> V_16 ;
}
}
}
goto V_24;
case V_482 :
if ( V_20 -> V_457 <= V_525 ) {
char V_268 [ 64 ] ;
if ( V_183 > sizeof( V_268 ) - sizeof( struct V_456 ) ) {
F_83 ( V_20 , V_314 ) ;
goto V_24;
}
V_149 = V_475 ;
V_183 = F_228 ( V_20 , V_148 -> V_184 , V_183 ,
V_268 , & V_149 ) ;
if ( V_183 < 0 ) {
F_83 ( V_20 , V_314 ) ;
goto V_24;
}
F_80 ( V_10 , F_88 ( V_10 ) ,
V_322 , V_183 , V_268 ) ;
V_20 -> V_323 ++ ;
if ( V_149 != V_475 )
goto V_24;
break;
}
default:
F_24 ( V_20 , V_314 ) ;
F_82 ( V_20 , V_526 ) ;
F_83 ( V_20 , V_314 ) ;
goto V_24;
}
if ( V_94 & V_522 )
goto V_24;
F_54 ( V_523 , & V_20 -> V_76 ) ;
if ( F_73 ( V_495 , & V_20 -> V_76 ) ) {
F_240 ( V_20 ) ;
if ( V_20 -> V_136 == V_139 ||
V_20 -> V_136 == V_143 )
V_21 = F_218 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_127 ( V_20 ) ;
}
V_24:
F_46 ( V_20 ) ;
return V_21 ;
}
static inline int F_247 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
struct V_310 * V_268 = (struct V_310 * ) V_184 ;
struct V_527 V_148 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_499 != sizeof( * V_268 ) )
return - V_502 ;
V_14 = F_66 ( V_268 -> V_14 ) ;
V_13 = F_66 ( V_268 -> V_13 ) ;
F_21 ( L_48 , V_14 , V_13 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_4 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_8 ( & V_10 -> V_15 ) ;
F_242 ( V_10 , V_427 -> V_16 , V_13 , V_14 ) ;
return 0 ;
}
F_7 ( V_20 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
F_80 ( V_10 , V_427 -> V_16 , V_528 , sizeof( V_148 ) , & V_148 ) ;
V_20 -> V_32 -> V_529 ( V_20 ) ;
F_57 ( V_20 ) ;
F_69 ( V_20 , V_314 ) ;
F_46 ( V_20 ) ;
V_20 -> V_32 -> V_68 ( V_20 ) ;
F_47 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_248 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
struct V_527 * V_148 = (struct V_527 * ) V_184 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_499 != sizeof( * V_148 ) )
return - V_502 ;
V_14 = F_66 ( V_148 -> V_14 ) ;
V_13 = F_66 ( V_148 -> V_13 ) ;
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
static inline int F_249 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
struct V_298 * V_268 = (struct V_298 * ) V_184 ;
T_2 type ;
if ( V_499 != sizeof( * V_268 ) )
return - V_502 ;
type = F_66 ( V_268 -> type ) ;
F_21 ( L_50 , type ) ;
if ( type == V_299 ) {
T_3 V_315 [ 8 ] ;
T_8 V_304 = V_306 ;
struct V_530 * V_148 = (struct V_530 * ) V_315 ;
V_148 -> type = F_16 ( V_299 ) ;
V_148 -> V_149 = F_16 ( V_531 ) ;
if ( ! V_307 )
V_304 |= V_308 | V_309
| V_466 ;
if ( V_10 -> V_258 )
V_304 |= V_450
| V_449 ;
F_104 ( V_304 , V_148 -> V_184 ) ;
F_80 ( V_10 , V_427 -> V_16 , V_532 , sizeof( V_315 ) ,
V_315 ) ;
} else if ( type == V_533 ) {
T_3 V_315 [ 12 ] ;
struct V_530 * V_148 = (struct V_530 * ) V_315 ;
if ( V_10 -> V_258 )
V_534 [ 0 ] |= V_260 ;
else
V_534 [ 0 ] &= ~ V_260 ;
V_148 -> type = F_16 ( V_533 ) ;
V_148 -> V_149 = F_16 ( V_531 ) ;
memcpy ( V_148 -> V_184 , V_534 , sizeof( V_534 ) ) ;
F_80 ( V_10 , V_427 -> V_16 , V_532 , sizeof( V_315 ) ,
V_315 ) ;
} else {
struct V_530 V_148 ;
V_148 . type = F_16 ( type ) ;
V_148 . V_149 = F_16 ( V_535 ) ;
F_80 ( V_10 , V_427 -> V_16 , V_532 , sizeof( V_148 ) ,
& V_148 ) ;
}
return 0 ;
}
static inline int F_250 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
struct V_530 * V_148 = (struct V_530 * ) V_184 ;
T_2 type , V_149 ;
if ( V_499 < sizeof( * V_148 ) )
return - V_502 ;
type = F_66 ( V_148 -> type ) ;
V_149 = F_66 ( V_148 -> V_149 ) ;
F_21 ( L_51 , type , V_149 ) ;
if ( V_427 -> V_16 != V_10 -> V_300 ||
V_10 -> V_295 & V_297 )
return 0 ;
F_234 ( & V_10 -> V_301 ) ;
if ( V_149 != V_531 ) {
V_10 -> V_295 |= V_297 ;
V_10 -> V_300 = 0 ;
F_136 ( V_10 ) ;
return 0 ;
}
switch ( type ) {
case V_299 :
V_10 -> V_304 = F_98 ( V_148 -> V_184 ) ;
if ( V_10 -> V_304 & V_536 ) {
struct V_298 V_268 ;
V_268 . type = F_16 ( V_533 ) ;
V_10 -> V_300 = F_88 ( V_10 ) ;
F_80 ( V_10 , V_10 -> V_300 ,
V_303 , sizeof( V_268 ) , & V_268 ) ;
} else {
V_10 -> V_295 |= V_297 ;
V_10 -> V_300 = 0 ;
F_136 ( V_10 ) ;
}
break;
case V_533 :
V_10 -> V_259 = V_148 -> V_184 [ 0 ] ;
V_10 -> V_295 |= V_297 ;
V_10 -> V_300 = 0 ;
F_136 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_251 ( struct V_9 * V_10 ,
struct V_426 * V_427 ,
T_2 V_499 , void * V_184 )
{
struct V_271 * V_268 = V_184 ;
struct V_537 V_148 ;
struct V_8 * V_20 ;
struct V_256 * V_185 ;
T_2 V_17 , V_14 ;
if ( V_499 != sizeof( * V_268 ) )
return - V_502 ;
if ( ! V_10 -> V_258 )
return - V_26 ;
V_17 = F_226 ( V_268 -> V_17 ) ;
V_14 = F_226 ( V_268 -> V_14 ) ;
F_21 ( L_52 , V_17 , V_14 , V_268 -> V_270 ) ;
if ( V_268 -> V_270 == V_446 ) {
F_235 ( V_10 , V_427 , V_184 , V_497 ,
V_268 -> V_270 ) ;
return 0 ;
}
V_185 = F_252 ( V_268 -> V_270 ) ;
if ( ! V_185 )
goto error;
if ( V_185 -> V_538 != V_539 || ! F_73 ( V_264 , & V_185 -> V_94 ) ) {
F_253 ( V_185 ) ;
goto error;
}
V_20 = F_235 ( V_10 , V_427 , V_184 , V_497 ,
V_268 -> V_270 ) ;
if ( V_20 ) {
struct V_129 * V_130 = V_10 -> V_2 -> V_129 ;
struct V_1 * V_196 ;
V_196 = F_254 ( V_185 , V_540 ,
& V_10 -> V_2 -> V_145 ) ;
if ( ! V_196 ) {
F_253 ( V_185 ) ;
F_242 ( V_10 , V_427 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
return 0 ;
}
F_21 ( L_53 , V_130 , V_20 , V_196 ) ;
V_130 -> V_132 = V_20 ;
V_20 -> V_196 = V_196 ;
V_20 -> V_78 = V_467 ;
V_10 -> V_154 = V_185 -> V_541 ;
}
F_253 ( V_185 ) ;
return 0 ;
error:
V_148 . V_13 = 0 ;
V_148 . V_14 = F_16 ( V_14 ) ;
V_148 . V_149 = F_16 ( V_542 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
F_80 ( V_10 , V_427 -> V_16 , V_497 ,
sizeof( V_148 ) , & V_148 ) ;
return 0 ;
}
static void F_255 ( struct V_8 * V_20 , T_3 V_543 )
{
struct V_544 V_268 ;
T_3 V_16 ;
F_21 ( L_54 , V_20 , V_543 ) ;
V_16 = F_88 ( V_20 -> V_10 ) ;
V_20 -> V_16 = V_16 ;
V_268 . V_545 = F_16 ( V_20 -> V_14 ) ;
V_268 . V_543 = V_543 ;
F_80 ( V_20 -> V_10 , V_16 , V_546 , sizeof( V_268 ) ,
& V_268 ) ;
F_82 ( V_20 , V_547 ) ;
}
static void F_256 ( struct V_8 * V_20 , T_2 V_149 )
{
struct V_548 V_148 ;
F_21 ( L_55 , V_20 , V_149 ) ;
V_148 . V_545 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_149 = F_16 ( V_149 ) ;
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_549 ,
sizeof( V_148 ) , & V_148 ) ;
}
static void F_257 ( struct V_8 * V_20 , T_2 V_149 )
{
struct V_550 V_551 ;
F_21 ( L_55 , V_20 , V_149 ) ;
V_20 -> V_16 = F_88 ( V_20 -> V_10 ) ;
V_551 . V_545 = F_16 ( V_20 -> V_14 ) ;
V_551 . V_149 = F_16 ( V_149 ) ;
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_552 ,
sizeof( V_551 ) , & V_551 ) ;
F_82 ( V_20 , V_547 ) ;
}
static void F_258 ( struct V_9 * V_10 , T_2 V_545 )
{
struct V_550 V_551 ;
F_21 ( L_56 , V_10 , V_545 ) ;
V_551 . V_545 = F_16 ( V_545 ) ;
V_551 . V_149 = F_16 ( V_553 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_552 ,
sizeof( V_551 ) , & V_551 ) ;
}
static void F_259 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_545 )
{
struct V_554 V_148 ;
F_21 ( L_57 , V_545 ) ;
V_148 . V_545 = F_16 ( V_545 ) ;
F_80 ( V_10 , V_16 , V_555 , sizeof( V_148 ) , & V_148 ) ;
}
static void F_260 ( struct V_8 * V_20 )
{
V_20 -> V_133 = NULL ;
V_20 -> V_196 = NULL ;
}
static void F_261 ( struct V_8 * V_20 )
{
if ( V_20 -> V_31 != V_61 ) {
F_83 ( V_20 , V_314 ) ;
return;
}
switch ( V_20 -> V_283 ) {
case V_288 :
F_125 ( V_20 ) ;
F_256 ( V_20 , V_556 ) ;
break;
case V_285 :
if ( V_20 -> V_193 == V_557 ||
V_20 -> V_193 == V_558 ) {
F_125 ( V_20 ) ;
}
F_257 ( V_20 , V_553 ) ;
break;
}
}
static void F_262 ( struct V_8 * V_20 ,
struct V_134 * V_192 )
{
struct V_470 V_148 ;
V_20 -> V_133 = V_192 ;
V_20 -> V_196 -> V_144 = V_20 -> V_10 ;
F_241 ( V_20 , & V_148 , V_20 -> V_16 , 0 ) ;
if ( F_73 ( V_523 , & V_20 -> V_76 ) ) {
int V_21 ;
F_240 ( V_20 ) ;
V_21 = F_218 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_127 ( V_20 ) ;
}
}
static void F_263 ( struct V_8 * V_20 ,
struct V_134 * V_192 )
{
V_20 -> V_196 = V_192 -> V_10 ;
V_20 -> V_196 -> V_144 = V_20 -> V_10 ;
F_21 ( L_58 , V_20 -> V_193 ) ;
switch ( V_20 -> V_193 ) {
case V_557 :
V_20 -> V_193 = V_559 ;
break;
case V_558 :
if ( F_73 ( V_253 , & V_20 -> V_247 ) ) {
V_20 -> V_193 = V_560 ;
} else if ( V_20 -> V_283 == V_285 ) {
V_20 -> V_193 = V_561 ;
F_257 ( V_20 , V_562 ) ;
} else if ( V_20 -> V_283 == V_288 ) {
V_20 -> V_193 = V_563 ;
F_256 ( V_20 , V_564 ) ;
}
break;
default:
F_260 ( V_20 ) ;
V_20 -> V_193 = V_194 ;
}
}
void F_264 ( struct V_8 * V_20 , struct V_134 * V_192 ,
T_3 V_159 )
{
F_21 ( L_59 , V_20 , V_192 , V_159 ) ;
if ( V_159 ) {
F_261 ( V_20 ) ;
F_260 ( V_20 ) ;
return;
}
if ( V_20 -> V_31 != V_61 ) {
if ( V_20 -> V_445 != V_446 )
F_262 ( V_20 , V_192 ) ;
} else {
F_263 ( V_20 , V_192 ) ;
}
}
void F_265 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_445 == V_446 ) {
if ( V_20 -> V_265 != V_266 )
return;
V_20 -> V_283 = V_285 ;
V_20 -> V_193 = V_195 ;
} else {
V_20 -> V_283 = V_285 ;
V_20 -> V_193 = V_559 ;
V_20 -> V_447 = 0 ;
F_124 ( V_20 ) ;
F_255 ( V_20 , 0 ) ;
}
}
static void F_266 ( struct V_8 * V_20 , int V_149 ,
T_3 V_445 , T_3 V_565 )
{
F_21 ( L_60 , V_20 , F_22 ( V_20 -> V_31 ) ,
V_445 , V_565 ) ;
V_20 -> V_78 = V_467 ;
if ( V_20 -> V_31 == V_64 ) {
if ( V_149 == V_319 ) {
V_20 -> V_445 = V_445 ;
F_123 ( V_20 , V_565 ) ;
} else {
F_122 ( V_20 ) ;
}
return;
}
if ( F_117 ( V_20 ) ) {
struct V_157 V_148 ;
char V_315 [ 128 ] ;
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( V_149 == V_319 ) {
V_148 . V_149 = F_16 ( V_319 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
} else {
V_148 . V_149 = F_16 ( V_507 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
}
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_497 ,
sizeof( V_148 ) , & V_148 ) ;
if ( V_149 == V_319 ) {
F_20 ( V_20 , V_62 ) ;
F_54 ( V_321 , & V_20 -> V_76 ) ;
F_80 ( V_20 -> V_10 , F_88 ( V_20 -> V_10 ) ,
V_322 ,
F_138 ( V_20 , V_315 ) , V_315 ) ;
V_20 -> V_323 ++ ;
}
}
}
static void F_267 ( struct V_8 * V_20 , T_3 V_445 ,
T_3 V_565 )
{
F_124 ( V_20 ) ;
V_20 -> V_447 = V_445 ;
V_20 -> V_193 = V_566 ;
F_255 ( V_20 , V_565 ) ;
}
static void F_268 ( struct V_8 * V_20 , int V_149 )
{
struct V_134 * V_192 = NULL ;
if ( V_192 ) {
if ( V_192 -> V_31 == V_61 ) {
V_20 -> V_196 = V_192 -> V_10 ;
V_20 -> V_196 -> V_144 = V_20 -> V_10 ;
V_20 -> V_193 = V_563 ;
F_256 ( V_20 , V_564 ) ;
F_264 ( V_20 , V_192 , V_564 ) ;
} else {
V_20 -> V_193 = V_558 ;
}
} else {
F_256 ( V_20 , V_567 ) ;
}
}
static void F_269 ( struct V_8 * V_20 , int V_149 )
{
if ( V_20 -> V_283 == V_288 ) {
T_3 V_568 ;
if ( V_149 == - V_26 )
V_568 = V_569 ;
else
V_568 = V_567 ;
F_256 ( V_20 , V_568 ) ;
}
V_20 -> V_283 = V_284 ;
V_20 -> V_193 = V_194 ;
F_172 ( V_20 ) ;
}
void F_270 ( struct V_8 * V_20 , int V_149 )
{
T_3 V_445 = V_20 -> V_445 ;
T_3 V_565 = V_20 -> V_565 ;
F_21 ( L_61 ,
V_20 , V_149 , V_445 , V_565 ) ;
if ( V_20 -> V_31 == V_153 || V_20 -> V_31 == V_570 ) {
F_46 ( V_20 ) ;
return;
}
if ( V_20 -> V_31 != V_61 ) {
F_266 ( V_20 , V_149 , V_445 , V_565 ) ;
} else if ( V_149 != V_564 ) {
F_269 ( V_20 , V_149 ) ;
} else {
switch ( V_20 -> V_283 ) {
case V_285 :
F_267 ( V_20 , V_445 ,
V_565 ) ;
break;
case V_288 :
F_268 ( V_20 , V_149 ) ;
break;
default:
F_269 ( V_20 , V_149 ) ;
break;
}
}
}
static inline int F_271 ( struct V_9 * V_10 ,
struct V_426 * V_427 ,
T_2 V_499 , void * V_184 )
{
struct V_544 * V_268 = V_184 ;
struct V_548 V_148 ;
struct V_8 * V_20 ;
T_2 V_545 = 0 ;
T_2 V_149 = V_567 ;
if ( V_499 != sizeof( * V_268 ) )
return - V_502 ;
V_545 = F_226 ( V_268 -> V_545 ) ;
F_21 ( L_62 , V_545 , V_268 -> V_543 ) ;
if ( ! V_10 -> V_258 )
return - V_26 ;
V_20 = F_9 ( V_10 , V_545 ) ;
if ( ! V_20 ) {
V_148 . V_545 = F_16 ( V_545 ) ;
V_148 . V_149 = F_16 ( V_567 ) ;
F_80 ( V_10 , V_427 -> V_16 , V_549 ,
sizeof( V_148 ) , & V_148 ) ;
return 0 ;
}
V_20 -> V_16 = V_427 -> V_16 ;
if ( V_20 -> V_14 < V_30 ||
V_20 -> V_265 == V_571 ||
( V_20 -> V_136 != V_139 &&
V_20 -> V_136 != V_143 ) ) {
V_149 = V_567 ;
goto V_572;
}
if ( V_20 -> V_445 == V_268 -> V_543 ) {
V_149 = V_573 ;
goto V_572;
}
if ( V_268 -> V_543 != V_446 ) {
struct V_256 * V_185 ;
V_185 = F_252 ( V_268 -> V_543 ) ;
if ( ! V_185 || V_185 -> V_538 != V_539 ||
! F_73 ( V_264 , & V_185 -> V_94 ) ) {
if ( V_185 )
F_253 ( V_185 ) ;
V_149 = V_569 ;
goto V_572;
}
F_253 ( V_185 ) ;
}
if ( ( F_92 ( V_20 ) ||
V_20 -> V_283 != V_284 ) &&
F_13 ( & V_10 -> V_2 -> V_18 , & V_10 -> V_2 -> V_145 ) > 0 ) {
V_149 = V_574 ;
goto V_572;
}
V_20 -> V_283 = V_288 ;
F_124 ( V_20 ) ;
V_20 -> V_447 = V_268 -> V_543 ;
V_545 = V_20 -> V_13 ;
if ( V_268 -> V_543 == V_446 ) {
if ( F_73 ( V_253 , & V_20 -> V_247 ) ) {
V_20 -> V_193 = V_560 ;
V_149 = V_575 ;
} else {
V_20 -> V_193 = V_563 ;
V_149 = V_564 ;
}
} else {
V_20 -> V_193 = V_195 ;
V_149 = V_575 ;
}
V_572:
F_256 ( V_20 , V_149 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static void F_272 ( struct V_9 * V_10 , T_2 V_545 , T_2 V_149 )
{
struct V_8 * V_20 ;
struct V_134 * V_192 = NULL ;
V_20 = F_5 ( V_10 , V_545 ) ;
if ( ! V_20 ) {
F_258 ( V_10 , V_545 ) ;
return;
}
F_70 ( V_20 ) ;
if ( V_149 == V_575 )
F_82 ( V_20 , V_576 ) ;
switch ( V_20 -> V_193 ) {
case V_557 :
V_20 -> V_193 = V_558 ;
break;
case V_559 :
if ( V_149 == V_575 ) {
break;
} else if ( F_73 ( V_253 ,
& V_20 -> V_247 ) ) {
V_20 -> V_193 = V_560 ;
} else {
V_20 -> V_193 = V_561 ;
F_257 ( V_20 , V_562 ) ;
}
break;
case V_566 :
if ( V_149 == V_564 ) {
V_20 -> V_193 = V_558 ;
} else {
V_20 -> V_193 = V_557 ;
}
if ( ! V_192 ) {
F_257 ( V_20 , V_553 ) ;
break;
}
if ( V_192 -> V_31 != V_61 )
break;
V_20 -> V_196 = V_192 -> V_10 ;
V_20 -> V_196 -> V_144 = V_20 -> V_10 ;
if ( V_149 == V_564 ) {
F_257 ( V_20 , V_562 ) ;
} else {
V_20 -> V_193 = V_559 ;
}
F_264 ( V_20 , V_192 , V_564 ) ;
break;
default:
V_20 -> V_447 = V_20 -> V_445 ;
F_125 ( V_20 ) ;
F_257 ( V_20 , V_553 ) ;
}
F_46 ( V_20 ) ;
}
static void F_273 ( struct V_9 * V_10 , T_3 V_16 , T_2 V_545 ,
T_2 V_149 )
{
struct V_8 * V_20 ;
V_20 = F_11 ( V_10 , V_16 ) ;
if ( ! V_20 ) {
F_258 ( V_10 , V_545 ) ;
return;
}
F_70 ( V_20 ) ;
if ( V_20 -> V_283 == V_285 ) {
if ( V_149 == V_574 ) {
V_20 -> V_283 = V_288 ;
} else {
V_20 -> V_447 = V_20 -> V_445 ;
F_125 ( V_20 ) ;
}
}
F_257 ( V_20 , V_553 ) ;
F_46 ( V_20 ) ;
}
static int F_274 ( struct V_9 * V_10 ,
struct V_426 * V_427 ,
T_2 V_499 , void * V_184 )
{
struct V_548 * V_148 = V_184 ;
T_2 V_545 , V_149 ;
if ( V_499 != sizeof( * V_148 ) )
return - V_502 ;
V_545 = F_226 ( V_148 -> V_545 ) ;
V_149 = F_226 ( V_148 -> V_149 ) ;
F_21 ( L_63 , V_545 , V_149 ) ;
if ( V_149 == V_564 || V_149 == V_575 )
F_272 ( V_10 , V_545 , V_149 ) ;
else
F_273 ( V_10 , V_427 -> V_16 , V_545 , V_149 ) ;
return 0 ;
}
static int F_275 ( struct V_9 * V_10 ,
struct V_426 * V_427 ,
T_2 V_499 , void * V_184 )
{
struct V_550 * V_551 = V_184 ;
struct V_8 * V_20 ;
T_2 V_545 , V_149 ;
if ( V_499 != sizeof( * V_551 ) )
return - V_502 ;
V_545 = F_226 ( V_551 -> V_545 ) ;
V_149 = F_226 ( V_551 -> V_149 ) ;
F_21 ( L_63 , V_545 , V_149 ) ;
V_20 = F_9 ( V_10 , V_545 ) ;
if ( ! V_20 ) {
F_259 ( V_10 , V_427 -> V_16 , V_545 ) ;
return 0 ;
}
if ( V_20 -> V_193 == V_563 ) {
if ( V_149 == V_562 ) {
V_20 -> V_445 = V_20 -> V_447 ;
if ( V_20 -> V_445 == V_446 )
F_260 ( V_20 ) ;
} else {
V_20 -> V_447 = V_20 -> V_445 ;
}
F_125 ( V_20 ) ;
}
F_259 ( V_10 , V_427 -> V_16 , V_545 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static inline int F_276 ( struct V_9 * V_10 ,
struct V_426 * V_427 ,
T_2 V_499 , void * V_184 )
{
struct V_554 * V_148 = V_184 ;
struct V_8 * V_20 ;
T_2 V_545 ;
if ( V_499 != sizeof( * V_148 ) )
return - V_502 ;
V_545 = F_226 ( V_148 -> V_545 ) ;
F_21 ( L_57 , V_545 ) ;
V_20 = F_5 ( V_10 , V_545 ) ;
if ( ! V_20 )
return 0 ;
F_70 ( V_20 ) ;
if ( V_20 -> V_193 == V_561 ) {
V_20 -> V_445 = V_20 -> V_447 ;
if ( V_20 -> V_445 == V_446 && V_20 -> V_133 )
F_260 ( V_20 ) ;
F_125 ( V_20 ) ;
}
F_46 ( V_20 ) ;
return 0 ;
}
static inline int V_338 ( struct V_9 * V_10 ,
struct V_426 * V_427 ,
T_2 V_499 , T_3 * V_184 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_338 * V_268 ;
struct V_577 V_148 ;
T_2 V_339 , V_340 , V_341 , V_343 ;
int V_21 ;
if ( V_2 -> V_333 != V_578 )
return - V_26 ;
if ( V_499 != sizeof( struct V_338 ) )
return - V_502 ;
V_268 = (struct V_338 * ) V_184 ;
V_339 = F_66 ( V_268 -> V_339 ) ;
V_340 = F_66 ( V_268 -> V_340 ) ;
V_341 = F_66 ( V_268 -> V_341 ) ;
V_343 = F_66 ( V_268 -> V_343 ) ;
F_21 ( L_64 ,
V_339 , V_340 , V_341 , V_343 ) ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_21 = F_277 ( V_339 , V_340 , V_341 , V_343 ) ;
if ( V_21 )
V_148 . V_149 = F_16 ( V_579 ) ;
else
V_148 . V_149 = F_16 ( V_580 ) ;
F_80 ( V_10 , V_427 -> V_16 , V_581 ,
sizeof( V_148 ) , & V_148 ) ;
if ( ! V_21 ) {
T_3 V_582 ;
V_582 = F_278 ( V_2 , V_339 , V_340 , V_341 ,
V_343 ) ;
F_279 ( V_2 -> V_185 , & V_2 -> V_145 , V_2 -> V_146 ,
V_582 , V_339 , V_340 , V_341 ,
V_343 ) ;
}
return 0 ;
}
static int F_280 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
struct V_147 * V_148 = (struct V_147 * ) V_184 ;
T_2 V_13 , V_154 , V_101 , V_155 , V_149 ;
struct V_8 * V_20 ;
int V_21 ;
if ( V_499 < sizeof( * V_148 ) )
return - V_502 ;
V_13 = F_66 ( V_148 -> V_13 ) ;
V_154 = F_66 ( V_148 -> V_154 ) ;
V_101 = F_66 ( V_148 -> V_101 ) ;
V_155 = F_66 ( V_148 -> V_155 ) ;
V_149 = F_66 ( V_148 -> V_149 ) ;
if ( V_149 == V_319 && ( V_154 < 23 || V_101 < 23 ) )
return - V_502 ;
F_21 ( L_65 ,
V_13 , V_154 , V_101 , V_155 , V_149 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_10 ( V_10 , V_427 -> V_16 ) ;
if ( ! V_20 ) {
V_21 = - V_515 ;
goto V_516;
}
V_21 = 0 ;
F_7 ( V_20 ) ;
switch ( V_149 ) {
case V_319 :
V_20 -> V_16 = 0 ;
V_20 -> V_13 = V_13 ;
V_20 -> V_110 = V_154 ;
V_20 -> V_401 = V_101 ;
V_20 -> V_98 = V_155 ;
F_127 ( V_20 ) ;
break;
default:
F_69 ( V_20 , V_63 ) ;
break;
}
F_46 ( V_20 ) ;
V_516:
F_8 ( & V_10 -> V_15 ) ;
return V_21 ;
}
static inline int F_281 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
int V_21 = 0 ;
switch ( V_427 -> V_182 ) {
case V_520 :
F_233 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_269 :
V_21 = F_237 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_161 :
case V_497 :
F_239 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_322 :
V_21 = F_244 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_517 :
F_245 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_311 :
V_21 = F_247 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_528 :
F_248 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_583 :
F_80 ( V_10 , V_427 -> V_16 , V_584 , V_499 , V_184 ) ;
break;
case V_584 :
break;
case V_303 :
V_21 = F_249 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_532 :
F_250 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_272 :
V_21 = F_251 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_546 :
V_21 = F_271 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_549 :
F_274 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_552 :
V_21 = F_275 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_555 :
F_276 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
default:
F_282 ( L_66 , V_427 -> V_182 ) ;
V_21 = - V_26 ;
break;
}
return V_21 ;
}
static int F_283 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
struct V_292 * V_268 = (struct V_292 * ) V_184 ;
struct V_147 V_148 ;
struct V_8 * V_20 , * V_330 ;
T_2 V_13 , V_14 , V_155 , V_154 , V_101 ;
T_4 V_17 ;
T_3 V_149 ;
if ( V_499 != sizeof( * V_268 ) )
return - V_502 ;
V_14 = F_66 ( V_268 -> V_14 ) ;
V_154 = F_66 ( V_268 -> V_154 ) ;
V_101 = F_66 ( V_268 -> V_101 ) ;
V_17 = V_268 -> V_17 ;
V_13 = 0 ;
V_155 = 0 ;
if ( V_154 < 23 || V_101 < 23 )
return - V_502 ;
F_21 ( L_67 , F_66 ( V_17 ) ,
V_14 , V_154 , V_101 ) ;
V_330 = F_164 ( V_162 , V_17 , & V_10 -> V_2 -> V_18 ,
& V_10 -> V_2 -> V_145 , V_3 ) ;
if ( ! V_330 ) {
V_149 = V_152 ;
V_20 = NULL ;
goto V_506;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_330 ) ;
if ( ! F_284 ( V_10 -> V_2 , V_330 -> V_65 ) ) {
V_149 = V_585 ;
V_20 = NULL ;
goto V_586;
}
if ( F_2 ( V_10 , V_14 ) ) {
V_149 = V_507 ;
V_20 = NULL ;
goto V_586;
}
V_20 = V_330 -> V_32 -> V_346 ( V_330 ) ;
if ( ! V_20 ) {
V_149 = V_507 ;
goto V_586;
}
F_62 ( V_20 ) ;
F_78 ( & V_20 -> V_18 , & V_10 -> V_2 -> V_18 ) ;
F_78 ( & V_20 -> V_145 , & V_10 -> V_2 -> V_145 ) ;
V_20 -> V_348 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_348 ) ;
V_20 -> V_146 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_146 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_14 ;
V_20 -> V_110 = V_154 ;
V_20 -> V_401 = V_101 ;
V_20 -> V_98 = F_66 ( V_268 -> V_155 ) ;
F_65 ( V_10 , V_20 ) ;
V_13 = V_20 -> V_14 ;
V_155 = V_20 -> V_99 ;
F_82 ( V_20 , V_20 -> V_32 -> V_163 ( V_20 ) ) ;
V_20 -> V_16 = V_427 -> V_16 ;
if ( F_73 ( V_150 , & V_20 -> V_94 ) ) {
F_20 ( V_20 , V_164 ) ;
V_149 = V_316 ;
V_20 -> V_32 -> V_318 ( V_20 ) ;
} else {
F_127 ( V_20 ) ;
V_149 = V_319 ;
}
V_586:
F_46 ( V_330 ) ;
F_8 ( & V_10 -> V_15 ) ;
if ( V_149 == V_316 )
return 0 ;
V_506:
if ( V_20 ) {
V_148 . V_154 = F_16 ( V_20 -> V_102 ) ;
V_148 . V_101 = F_16 ( V_20 -> V_101 ) ;
} else {
V_148 . V_154 = 0 ;
V_148 . V_101 = 0 ;
}
V_148 . V_13 = F_16 ( V_13 ) ;
V_148 . V_155 = F_16 ( V_155 ) ;
V_148 . V_149 = F_16 ( V_149 ) ;
F_80 ( V_10 , V_427 -> V_16 , V_156 , sizeof( V_148 ) , & V_148 ) ;
return 0 ;
}
static inline int F_285 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
struct F_285 * V_587 ;
struct V_8 * V_20 ;
T_2 V_11 , V_155 , V_588 ;
if ( V_499 != sizeof( * V_587 ) )
return - V_502 ;
V_587 = (struct F_285 * ) V_184 ;
V_11 = F_66 ( V_587 -> V_11 ) ;
V_155 = F_66 ( V_587 -> V_155 ) ;
F_21 ( L_68 , V_11 , V_155 ) ;
V_20 = F_9 ( V_10 , V_11 ) ;
if ( ! V_20 )
return - V_515 ;
V_588 = V_589 - V_20 -> V_98 ;
if ( V_155 > V_588 ) {
F_282 ( L_69 ) ;
F_83 ( V_20 , V_314 ) ;
return 0 ;
}
V_20 -> V_98 += V_155 ;
while ( V_20 -> V_98 && ! F_169 ( & V_20 -> V_104 ) ) {
F_93 ( V_20 , F_170 ( & V_20 -> V_104 ) ) ;
V_20 -> V_98 -- ;
}
if ( V_20 -> V_98 )
V_20 -> V_32 -> V_590 ( V_20 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static inline int F_286 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
struct V_500 * V_501 = (struct V_500 * ) V_184 ;
struct V_8 * V_20 ;
if ( V_499 < sizeof( * V_501 ) )
return - V_502 ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_10 ( V_10 , V_427 -> V_16 ) ;
if ( ! V_20 )
goto V_24;
F_7 ( V_20 ) ;
F_69 ( V_20 , V_63 ) ;
F_46 ( V_20 ) ;
V_24:
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_287 ( struct V_9 * V_10 ,
struct V_426 * V_427 , T_2 V_499 ,
T_3 * V_184 )
{
int V_21 = 0 ;
switch ( V_427 -> V_182 ) {
case V_520 :
F_286 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_345 :
V_21 = V_338 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_581 :
break;
case V_156 :
F_280 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_294 :
V_21 = F_283 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_591 :
V_21 = F_285 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_311 :
V_21 = F_247 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
case V_528 :
F_248 ( V_10 , V_427 , V_499 , V_184 ) ;
break;
default:
F_282 ( L_70 , V_427 -> V_182 ) ;
V_21 = - V_26 ;
break;
}
return V_21 ;
}
static inline void F_288 ( struct V_9 * V_10 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_426 * V_427 ;
T_2 V_183 ;
int V_21 ;
if ( V_2 -> type != V_3 )
goto V_592;
if ( V_42 -> V_183 < V_428 )
goto V_592;
V_427 = ( void * ) V_42 -> V_184 ;
F_99 ( V_42 , V_428 ) ;
V_183 = F_226 ( V_427 -> V_183 ) ;
F_21 ( L_71 , V_427 -> V_182 , V_183 , V_427 -> V_16 ) ;
if ( V_183 != V_42 -> V_183 || ! V_427 -> V_16 ) {
F_21 ( L_72 ) ;
goto V_592;
}
V_21 = F_287 ( V_10 , V_427 , V_183 , V_42 -> V_184 ) ;
if ( V_21 ) {
struct V_500 V_501 ;
F_282 ( L_73 , V_21 ) ;
V_501 . V_60 = F_16 ( V_503 ) ;
F_80 ( V_10 , V_427 -> V_16 , V_520 ,
sizeof( V_501 ) , & V_501 ) ;
}
V_592:
F_94 ( V_42 ) ;
}
static inline void F_289 ( struct V_9 * V_10 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 * V_184 = V_42 -> V_184 ;
int V_183 = V_42 -> V_183 ;
struct V_426 V_427 ;
int V_21 ;
F_212 ( V_10 , V_42 ) ;
if ( V_2 -> type != V_109 )
goto V_592;
while ( V_183 >= V_428 ) {
T_2 V_499 ;
memcpy ( & V_427 , V_184 , V_428 ) ;
V_184 += V_428 ;
V_183 -= V_428 ;
V_499 = F_226 ( V_427 . V_183 ) ;
F_21 ( L_71 , V_427 . V_182 , V_499 ,
V_427 . V_16 ) ;
if ( V_499 > V_183 || ! V_427 . V_16 ) {
F_21 ( L_72 ) ;
break;
}
V_21 = F_281 ( V_10 , & V_427 , V_499 , V_184 ) ;
if ( V_21 ) {
struct V_500 V_501 ;
F_282 ( L_73 , V_21 ) ;
V_501 . V_60 = F_16 ( V_503 ) ;
F_80 ( V_10 , V_427 . V_16 , V_520 ,
sizeof( V_501 ) , & V_501 ) ;
}
V_184 += V_499 ;
V_183 -= V_499 ;
}
V_592:
F_94 ( V_42 ) ;
}
static int F_290 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
T_2 V_593 , V_594 ;
int V_595 ;
if ( F_73 ( V_234 , & V_20 -> V_94 ) )
V_595 = V_239 ;
else
V_595 = V_240 ;
if ( V_20 -> V_78 == V_79 ) {
F_291 ( V_42 , V_42 -> V_183 - V_244 ) ;
V_594 = F_100 ( V_42 -> V_184 + V_42 -> V_183 ) ;
V_593 = F_111 ( 0 , V_42 -> V_184 - V_595 , V_42 -> V_183 + V_595 ) ;
if ( V_593 != V_594 )
return - V_596 ;
}
return 0 ;
}
static void F_292 ( struct V_8 * V_20 )
{
struct V_200 V_43 ;
F_21 ( L_3 , V_20 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_208 = 1 ;
V_43 . V_204 = 1 ;
V_43 . V_201 = V_20 -> V_254 ;
F_54 ( V_246 , & V_20 -> V_247 ) ;
if ( F_73 ( V_253 , & V_20 -> V_247 ) ) {
V_43 . V_212 = V_250 ;
F_112 ( V_20 , & V_43 ) ;
}
if ( F_113 ( V_282 , & V_20 -> V_247 ) &&
V_20 -> V_379 > 0 )
F_25 ( V_20 ) ;
F_172 ( V_20 ) ;
if ( ! F_73 ( V_253 , & V_20 -> V_247 ) &&
F_73 ( V_246 , & V_20 -> V_247 ) ) {
V_43 . V_212 = V_248 ;
F_112 ( V_20 , & V_43 ) ;
}
}
static void F_293 ( struct V_38 * V_42 , struct V_38 * V_597 ,
struct V_38 * * V_598 )
{
if ( ! F_294 ( V_42 ) )
F_187 ( V_42 ) -> V_390 = V_597 ;
V_597 -> V_357 = NULL ;
( * V_598 ) -> V_357 = V_597 ;
* V_598 = V_597 ;
V_42 -> V_183 += V_597 -> V_183 ;
V_42 -> V_394 += V_597 -> V_183 ;
V_42 -> V_599 += V_597 -> V_599 ;
}
static int F_295 ( struct V_8 * V_20 , struct V_38 * V_42 ,
struct V_200 * V_43 )
{
int V_21 = - V_26 ;
switch ( V_43 -> V_215 ) {
case V_402 :
if ( V_20 -> V_95 )
break;
V_21 = V_20 -> V_32 -> V_424 ( V_20 , V_42 ) ;
break;
case V_403 :
if ( V_20 -> V_95 )
break;
V_20 -> V_97 = F_100 ( V_42 -> V_184 ) ;
F_99 ( V_42 , V_397 ) ;
if ( V_20 -> V_97 > V_20 -> V_102 ) {
V_21 = - V_406 ;
break;
}
if ( V_42 -> V_183 >= V_20 -> V_97 )
break;
V_20 -> V_95 = V_42 ;
V_20 -> V_96 = V_42 ;
V_42 = NULL ;
V_21 = 0 ;
break;
case V_405 :
if ( ! V_20 -> V_95 )
break;
F_293 ( V_20 -> V_95 , V_42 ,
& V_20 -> V_96 ) ;
V_42 = NULL ;
if ( V_20 -> V_95 -> V_183 >= V_20 -> V_97 )
break;
V_21 = 0 ;
break;
case V_404 :
if ( ! V_20 -> V_95 )
break;
F_293 ( V_20 -> V_95 , V_42 ,
& V_20 -> V_96 ) ;
V_42 = NULL ;
if ( V_20 -> V_95 -> V_183 != V_20 -> V_97 )
break;
V_21 = V_20 -> V_32 -> V_424 ( V_20 , V_20 -> V_95 ) ;
if ( ! V_21 ) {
V_20 -> V_95 = NULL ;
V_20 -> V_96 = NULL ;
V_20 -> V_97 = 0 ;
}
break;
}
if ( V_21 ) {
F_94 ( V_42 ) ;
F_94 ( V_20 -> V_95 ) ;
V_20 -> V_95 = NULL ;
V_20 -> V_96 = NULL ;
V_20 -> V_97 = 0 ;
}
return V_21 ;
}
static int F_296 ( struct V_8 * V_20 )
{
return 0 ;
}
void F_297 ( struct V_8 * V_20 , int V_600 )
{
T_3 V_414 ;
if ( V_20 -> V_136 != V_139 )
return;
V_414 = V_600 ? V_415 : V_417 ;
F_126 ( V_20 , NULL , NULL , V_414 ) ;
}
static int F_298 ( struct V_8 * V_20 )
{
int V_21 = 0 ;
F_21 ( L_3 , V_20 ) ;
while ( ! F_73 ( V_253 , & V_20 -> V_247 ) ) {
struct V_38 * V_42 ;
F_21 ( L_74 ,
V_20 -> V_254 , F_176 ( & V_20 -> V_140 ) ) ;
V_42 = F_31 ( & V_20 -> V_140 , V_20 -> V_254 ) ;
if ( ! V_42 )
break;
F_205 ( V_42 , & V_20 -> V_140 ) ;
V_20 -> V_254 = F_171 ( V_20 , V_20 -> V_254 ) ;
V_21 = F_295 ( V_20 , V_42 , & F_33 ( V_42 ) -> V_43 ) ;
if ( V_21 )
break;
}
if ( F_169 ( & V_20 -> V_140 ) ) {
V_20 -> V_280 = V_382 ;
F_183 ( V_20 ) ;
}
return V_21 ;
}
static void F_299 ( struct V_8 * V_20 ,
struct V_200 * V_43 )
{
struct V_38 * V_42 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( V_43 -> V_201 == V_20 -> V_373 ) {
F_21 ( L_75 , V_43 -> V_201 ) ;
F_83 ( V_20 , V_314 ) ;
return;
}
V_42 = F_31 ( & V_20 -> V_104 , V_43 -> V_201 ) ;
if ( V_42 == NULL ) {
F_21 ( L_76 ,
V_43 -> V_201 ) ;
return;
}
if ( V_20 -> V_80 != 0 && F_33 ( V_42 ) -> V_43 . V_274 >= V_20 -> V_80 ) {
F_21 ( L_21 , V_20 -> V_80 ) ;
F_83 ( V_20 , V_314 ) ;
return;
}
F_114 ( V_282 , & V_20 -> V_247 ) ;
if ( V_43 -> V_209 ) {
F_210 ( V_20 , V_43 ) ;
F_54 ( V_246 , & V_20 -> V_247 ) ;
F_180 ( V_20 , V_43 ) ;
F_172 ( V_20 ) ;
if ( V_20 -> V_278 == V_419 ) {
F_54 ( V_277 , & V_20 -> V_247 ) ;
V_20 -> V_601 = V_43 -> V_201 ;
}
} else {
F_211 ( V_20 , V_43 ) ;
if ( V_43 -> V_204 ) {
if ( V_20 -> V_601 != V_43 -> V_201 ||
! F_113 ( V_277 ,
& V_20 -> V_247 ) )
F_180 ( V_20 , V_43 ) ;
} else {
F_180 ( V_20 , V_43 ) ;
if ( V_20 -> V_278 == V_419 ) {
F_54 ( V_277 , & V_20 -> V_247 ) ;
V_20 -> V_601 = V_43 -> V_201 ;
}
}
}
}
static void F_300 ( struct V_8 * V_20 ,
struct V_200 * V_43 )
{
struct V_38 * V_42 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( V_43 -> V_201 == V_20 -> V_373 ) {
F_21 ( L_75 , V_43 -> V_201 ) ;
F_83 ( V_20 , V_314 ) ;
return;
}
V_42 = F_31 ( & V_20 -> V_104 , V_43 -> V_201 ) ;
if ( V_20 -> V_80 && V_42 &&
F_33 ( V_42 ) -> V_43 . V_274 >= V_20 -> V_80 ) {
F_21 ( L_21 , V_20 -> V_80 ) ;
F_83 ( V_20 , V_314 ) ;
return;
}
F_114 ( V_282 , & V_20 -> V_247 ) ;
F_210 ( V_20 , V_43 ) ;
if ( V_43 -> V_204 ) {
if ( ! F_113 ( V_276 , & V_20 -> V_247 ) )
F_181 ( V_20 , V_43 ) ;
} else {
F_181 ( V_20 , V_43 ) ;
F_172 ( V_20 ) ;
if ( V_20 -> V_278 == V_419 )
F_54 ( V_276 , & V_20 -> V_247 ) ;
}
}
static T_3 F_301 ( struct V_8 * V_20 , T_2 V_44 )
{
F_21 ( L_77 , V_20 , V_44 ) ;
F_21 ( L_78 , V_20 -> V_252 ,
V_20 -> V_275 ) ;
if ( V_20 -> V_280 == V_416 ) {
if ( F_184 ( V_20 , V_44 , V_20 -> V_252 ) >=
V_20 -> V_82 ) {
if ( V_20 -> V_82 <= ( ( V_20 -> V_84 + 1 ) >> 1 ) ) {
F_21 ( L_79 ) ;
return V_602 ;
} else {
F_21 ( L_80 ) ;
return V_603 ;
}
}
if ( V_20 -> V_141 . V_40 == V_44 ) {
F_21 ( L_81 ) ;
return V_604 ;
}
if ( F_31 ( & V_20 -> V_140 , V_44 ) ) {
F_21 ( L_82 ) ;
return V_605 ;
}
if ( F_39 ( & V_20 -> V_141 , V_44 ) ) {
F_21 ( L_83 ) ;
return V_606 ;
}
}
if ( V_20 -> V_275 == V_44 ) {
if ( F_184 ( V_20 , V_44 , V_20 -> V_252 ) >=
V_20 -> V_82 ) {
F_21 ( L_84 ) ;
return V_603 ;
} else {
F_21 ( L_85 ) ;
return V_607 ;
}
}
if ( F_184 ( V_20 , V_44 , V_20 -> V_252 ) <
F_184 ( V_20 , V_20 -> V_275 , V_20 -> V_252 ) ) {
F_21 ( L_86 ) ;
return V_608 ;
}
if ( F_184 ( V_20 , V_44 , V_20 -> V_252 ) >= V_20 -> V_82 ) {
if ( V_20 -> V_82 <= ( ( V_20 -> V_84 + 1 ) >> 1 ) ) {
F_21 ( L_87 ) ;
return V_602 ;
} else {
F_21 ( L_84 ) ;
return V_603 ;
}
} else {
F_21 ( L_88 ) ;
return V_609 ;
}
}
static int F_302 ( struct V_8 * V_20 ,
struct V_200 * V_43 ,
struct V_38 * V_42 , T_3 V_414 )
{
int V_21 = 0 ;
bool V_610 = false ;
F_21 ( L_89 , V_20 , V_43 , V_42 ,
V_414 ) ;
switch ( V_414 ) {
case V_611 :
switch ( F_301 ( V_20 , V_43 -> V_44 ) ) {
case V_607 :
F_210 ( V_20 , V_43 ) ;
if ( F_73 ( V_253 , & V_20 -> V_247 ) ) {
F_21 ( L_90 ,
V_43 -> V_44 ) ;
break;
}
V_20 -> V_275 = F_171 ( V_20 ,
V_43 -> V_44 ) ;
V_20 -> V_254 = V_20 -> V_275 ;
V_610 = true ;
V_21 = F_295 ( V_20 , V_42 , V_43 ) ;
if ( V_21 )
break;
if ( V_43 -> V_204 ) {
if ( ! F_113 ( V_276 ,
& V_20 -> V_247 ) ) {
V_43 -> V_204 = 0 ;
F_181 ( V_20 , V_43 ) ;
F_172 ( V_20 ) ;
}
}
if ( ! F_73 ( V_253 , & V_20 -> V_247 ) )
F_183 ( V_20 ) ;
break;
case V_609 :
F_210 ( V_20 , V_43 ) ;
if ( F_73 ( V_253 , & V_20 -> V_247 ) ) {
F_21 ( L_91 ,
V_43 -> V_44 ) ;
break;
}
F_303 ( & V_20 -> V_140 , V_42 ) ;
V_610 = true ;
F_21 ( L_92 , V_42 ,
F_176 ( & V_20 -> V_140 ) ) ;
F_114 ( V_277 , & V_20 -> V_247 ) ;
F_41 ( & V_20 -> V_141 ) ;
F_201 ( V_20 , V_43 -> V_44 ) ;
V_20 -> V_280 = V_416 ;
break;
case V_608 :
F_210 ( V_20 , V_43 ) ;
break;
case V_602 :
break;
case V_603 :
default:
F_83 ( V_20 , V_314 ) ;
break;
}
break;
case V_612 :
F_210 ( V_20 , V_43 ) ;
if ( V_43 -> V_204 ) {
F_114 ( V_282 , & V_20 -> V_247 ) ;
if ( ! F_113 ( V_276 , & V_20 -> V_247 ) &&
! F_92 ( V_20 ) ) {
V_43 -> V_204 = 0 ;
F_181 ( V_20 , V_43 ) ;
}
F_172 ( V_20 ) ;
} else if ( V_43 -> V_209 ) {
F_292 ( V_20 ) ;
} else {
if ( F_113 ( V_282 ,
& V_20 -> V_247 ) &&
V_20 -> V_379 )
F_25 ( V_20 ) ;
F_172 ( V_20 ) ;
}
break;
case V_613 :
F_54 ( V_282 , & V_20 -> V_247 ) ;
F_210 ( V_20 , V_43 ) ;
if ( V_43 && V_43 -> V_209 ) {
F_54 ( V_246 , & V_20 -> V_247 ) ;
F_116 ( V_20 , 0 ) ;
}
F_30 ( V_20 ) ;
F_41 ( & V_20 -> V_142 ) ;
break;
case V_614 :
F_300 ( V_20 , V_43 ) ;
break;
case V_615 :
F_299 ( V_20 , V_43 ) ;
break;
default:
break;
}
if ( V_42 && ! V_610 ) {
F_21 ( L_93 , V_42 ) ;
F_94 ( V_42 ) ;
}
return V_21 ;
}
static int F_304 ( struct V_8 * V_20 ,
struct V_200 * V_43 ,
struct V_38 * V_42 , T_3 V_414 )
{
int V_21 = 0 ;
T_2 V_44 = V_43 -> V_44 ;
bool V_610 = false ;
F_21 ( L_89 , V_20 , V_43 , V_42 ,
V_414 ) ;
switch ( V_414 ) {
case V_611 :
switch ( F_301 ( V_20 , V_44 ) ) {
case V_607 :
F_210 ( V_20 , V_43 ) ;
F_303 ( & V_20 -> V_140 , V_42 ) ;
V_610 = true ;
F_21 ( L_92 , V_42 ,
F_176 ( & V_20 -> V_140 ) ) ;
V_20 -> V_275 = F_171 ( V_20 , V_44 ) ;
break;
case V_604 :
F_40 ( & V_20 -> V_141 ) ;
F_210 ( V_20 , V_43 ) ;
F_303 ( & V_20 -> V_140 , V_42 ) ;
V_610 = true ;
F_21 ( L_92 , V_42 ,
F_176 ( & V_20 -> V_140 ) ) ;
V_21 = F_298 ( V_20 ) ;
if ( V_21 )
break;
break;
case V_609 :
F_303 ( & V_20 -> V_140 , V_42 ) ;
V_610 = true ;
F_21 ( L_92 , V_42 ,
F_176 ( & V_20 -> V_140 ) ) ;
F_210 ( V_20 , V_43 ) ;
F_201 ( V_20 , V_43 -> V_44 ) ;
break;
case V_606 :
F_303 ( & V_20 -> V_140 , V_42 ) ;
V_610 = true ;
F_21 ( L_92 , V_42 ,
F_176 ( & V_20 -> V_140 ) ) ;
F_210 ( V_20 , V_43 ) ;
F_203 ( V_20 , V_43 -> V_44 ) ;
break;
case V_605 :
F_210 ( V_20 , V_43 ) ;
break;
case V_608 :
break;
case V_602 :
break;
case V_603 :
default:
F_83 ( V_20 , V_314 ) ;
break;
}
break;
case V_612 :
F_210 ( V_20 , V_43 ) ;
if ( V_43 -> V_204 ) {
F_114 ( V_282 , & V_20 -> V_247 ) ;
if ( ! F_113 ( V_276 ,
& V_20 -> V_247 ) ) {
V_43 -> V_204 = 0 ;
F_181 ( V_20 , V_43 ) ;
}
F_172 ( V_20 ) ;
} else if ( V_43 -> V_209 ) {
if ( F_113 ( V_282 ,
& V_20 -> V_247 ) &&
V_20 -> V_379 ) {
F_25 ( V_20 ) ;
}
F_54 ( V_246 , & V_20 -> V_247 ) ;
F_202 ( V_20 ) ;
} else {
if ( F_113 ( V_282 ,
& V_20 -> V_247 ) &&
V_20 -> V_379 )
F_25 ( V_20 ) ;
F_183 ( V_20 ) ;
}
break;
case V_613 :
F_54 ( V_282 , & V_20 -> V_247 ) ;
F_210 ( V_20 , V_43 ) ;
if ( V_43 -> V_209 ) {
F_202 ( V_20 ) ;
} else {
struct V_200 V_616 ;
memset ( & V_616 , 0 , sizeof( V_616 ) ) ;
V_616 . V_208 = 1 ;
V_616 . V_212 = V_248 ;
V_616 . V_201 = V_20 -> V_254 ;
F_112 ( V_20 , & V_616 ) ;
}
break;
case V_614 :
F_300 ( V_20 , V_43 ) ;
break;
case V_615 :
F_299 ( V_20 , V_43 ) ;
break;
}
if ( V_42 && ! V_610 ) {
F_21 ( L_93 , V_42 ) ;
F_94 ( V_42 ) ;
}
return V_21 ;
}
static int F_305 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_280 = V_382 ;
if ( V_20 -> V_196 )
V_20 -> V_10 -> V_154 = V_20 -> V_196 -> V_185 -> V_541 ;
else
V_20 -> V_10 -> V_154 = V_20 -> V_10 -> V_2 -> V_185 -> V_617 ;
return F_296 ( V_20 ) ;
}
static int F_306 ( struct V_8 * V_20 ,
struct V_200 * V_43 ,
struct V_38 * V_42 , T_3 V_414 )
{
int V_21 ;
F_21 ( L_89 , V_20 , V_43 , V_42 ,
V_414 ) ;
if ( ! V_43 -> V_209 )
return - V_502 ;
F_204 ( V_20 , V_43 -> V_201 ) ;
if ( ! F_169 ( & V_20 -> V_104 ) )
V_20 -> V_378 = F_208 ( & V_20 -> V_104 ) ;
else
V_20 -> V_378 = NULL ;
V_20 -> V_373 = V_43 -> V_201 ;
V_20 -> V_379 = 0 ;
V_21 = F_305 ( V_20 ) ;
if ( V_21 )
return V_21 ;
F_54 ( V_246 , & V_20 -> V_247 ) ;
F_292 ( V_20 ) ;
if ( V_414 == V_611 )
return - V_502 ;
return F_302 ( V_20 , V_43 , NULL , V_414 ) ;
}
static int F_307 ( struct V_8 * V_20 ,
struct V_200 * V_43 ,
struct V_38 * V_42 , T_3 V_414 )
{
int V_21 ;
if ( ! V_43 -> V_204 )
return - V_502 ;
F_114 ( V_282 , & V_20 -> V_247 ) ;
V_20 -> V_280 = V_382 ;
F_204 ( V_20 , V_43 -> V_201 ) ;
if ( ! F_169 ( & V_20 -> V_104 ) )
V_20 -> V_378 = F_208 ( & V_20 -> V_104 ) ;
else
V_20 -> V_378 = NULL ;
V_20 -> V_373 = V_43 -> V_201 ;
V_20 -> V_379 = 0 ;
if ( V_20 -> V_196 )
V_20 -> V_10 -> V_154 = V_20 -> V_196 -> V_185 -> V_541 ;
else
V_20 -> V_10 -> V_154 = V_20 -> V_10 -> V_2 -> V_185 -> V_617 ;
V_21 = F_296 ( V_20 ) ;
if ( ! V_21 )
V_21 = F_302 ( V_20 , V_43 , V_42 , V_414 ) ;
return V_21 ;
}
static bool F_308 ( struct V_8 * V_20 , T_2 V_201 )
{
T_2 V_618 ;
V_618 = F_184 ( V_20 , V_20 -> V_373 , V_20 -> V_413 ) ;
return F_184 ( V_20 , V_20 -> V_373 , V_201 ) <= V_618 ;
}
static int F_309 ( struct V_8 * V_20 , struct V_200 * V_43 ,
struct V_38 * V_42 , T_3 V_414 )
{
int V_21 = 0 ;
F_21 ( L_94 , V_20 ,
V_43 , V_42 , V_414 , V_20 -> V_280 ) ;
if ( F_308 ( V_20 , V_43 -> V_201 ) ) {
switch ( V_20 -> V_280 ) {
case V_382 :
V_21 = F_302 ( V_20 , V_43 , V_42 , V_414 ) ;
break;
case V_416 :
V_21 = F_304 ( V_20 , V_43 , V_42 ,
V_414 ) ;
break;
case V_289 :
V_21 = F_306 ( V_20 , V_43 , V_42 , V_414 ) ;
break;
case V_287 :
V_21 = F_307 ( V_20 , V_43 , V_42 , V_414 ) ;
break;
default:
break;
}
} else {
F_21 ( L_95 ,
V_43 -> V_201 , V_20 -> V_373 ,
V_20 -> V_413 ) ;
F_83 ( V_20 , V_314 ) ;
}
return V_21 ;
}
static int F_310 ( struct V_8 * V_20 , struct V_200 * V_43 ,
struct V_38 * V_42 )
{
int V_21 = 0 ;
F_21 ( L_96 , V_20 , V_43 , V_42 ,
V_20 -> V_280 ) ;
if ( F_301 ( V_20 , V_43 -> V_44 ) ==
V_607 ) {
F_210 ( V_20 , V_43 ) ;
F_21 ( L_97 , V_20 -> V_254 ,
F_171 ( V_20 , V_20 -> V_254 ) ) ;
V_20 -> V_254 = F_171 ( V_20 , V_20 -> V_254 ) ;
F_295 ( V_20 , V_42 , V_43 ) ;
} else {
if ( V_20 -> V_95 ) {
F_94 ( V_20 -> V_95 ) ;
V_20 -> V_95 = NULL ;
}
V_20 -> V_96 = NULL ;
V_20 -> V_97 = 0 ;
if ( V_42 ) {
F_21 ( L_93 , V_42 ) ;
F_94 ( V_42 ) ;
}
}
V_20 -> V_252 = V_43 -> V_44 ;
V_20 -> V_275 = F_171 ( V_20 , V_43 -> V_44 ) ;
return V_21 ;
}
static int F_311 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
struct V_200 * V_43 = & F_33 ( V_42 ) -> V_43 ;
T_2 V_183 ;
T_3 V_414 ;
F_97 ( V_20 , V_42 ) ;
V_183 = V_42 -> V_183 ;
if ( F_290 ( V_20 , V_42 ) )
goto V_592;
if ( ! V_43 -> V_208 && V_43 -> V_215 == V_403 )
V_183 -= V_397 ;
if ( V_20 -> V_78 == V_79 )
V_183 -= V_244 ;
if ( V_183 > V_20 -> V_101 ) {
F_83 ( V_20 , V_314 ) ;
goto V_592;
}
if ( ! V_43 -> V_208 ) {
int V_21 ;
F_21 ( L_98 ,
V_43 -> V_215 , V_43 -> V_201 , V_43 -> V_204 ,
V_43 -> V_44 ) ;
if ( V_43 -> V_204 && V_20 -> V_278 != V_419 )
goto V_592;
if ( V_20 -> V_136 != V_143 ) {
V_414 = V_611 ;
V_21 = F_309 ( V_20 , V_43 , V_42 , V_414 ) ;
} else {
V_21 = F_310 ( V_20 , V_43 , V_42 ) ;
}
if ( V_21 )
F_83 ( V_20 , V_314 ) ;
} else {
const T_3 V_619 [ 4 ] = {
V_612 , V_614 ,
V_613 , V_615
} ;
if ( V_20 -> V_136 == V_143 )
goto V_592;
F_21 ( L_99 ,
V_43 -> V_201 , V_43 -> V_204 , V_43 -> V_209 ,
V_43 -> V_212 ) ;
if ( V_183 != 0 ) {
F_282 ( L_100 , V_183 ) ;
F_83 ( V_20 , V_314 ) ;
goto V_592;
}
if ( V_43 -> V_204 && ( V_43 -> V_209 ||
V_20 -> V_278 != V_419 ) )
goto V_592;
V_414 = V_619 [ V_43 -> V_212 ] ;
if ( F_309 ( V_20 , V_43 , V_42 , V_414 ) )
F_83 ( V_20 , V_314 ) ;
}
return 0 ;
V_592:
F_94 ( V_42 ) ;
return 0 ;
}
static void F_312 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct F_285 V_587 ;
T_2 V_620 ;
if ( V_20 -> V_99 >= ( V_100 + 1 ) / 2 )
return;
V_620 = V_100 - V_20 -> V_99 ;
F_21 ( L_101 , V_20 , V_620 ) ;
V_20 -> V_99 += V_620 ;
V_587 . V_11 = F_16 ( V_20 -> V_14 ) ;
V_587 . V_155 = F_16 ( V_620 ) ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_591 , sizeof( V_587 ) , & V_587 ) ;
}
static int F_313 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
int V_21 ;
if ( ! V_20 -> V_99 ) {
F_282 ( L_102 ) ;
F_83 ( V_20 , V_314 ) ;
return - V_621 ;
}
if ( V_20 -> V_102 < V_42 -> V_183 ) {
F_282 ( L_103 ) ;
return - V_621 ;
}
V_20 -> V_99 -- ;
F_21 ( L_104 , V_20 -> V_99 + 1 , V_20 -> V_99 ) ;
F_312 ( V_20 ) ;
V_21 = 0 ;
if ( ! V_20 -> V_95 ) {
T_2 V_97 ;
V_97 = F_100 ( V_42 -> V_184 ) ;
F_99 ( V_42 , V_397 ) ;
F_21 ( L_105 ,
V_97 , V_42 -> V_183 , V_20 -> V_102 ) ;
if ( V_97 > V_20 -> V_102 ) {
F_282 ( L_106 ) ;
V_21 = - V_406 ;
goto V_622;
}
if ( V_42 -> V_183 > V_97 ) {
F_282 ( L_107 ) ;
V_21 = - V_26 ;
goto V_622;
}
if ( V_42 -> V_183 == V_97 )
return V_20 -> V_32 -> V_424 ( V_20 , V_42 ) ;
V_20 -> V_95 = V_42 ;
V_20 -> V_97 = V_97 ;
V_20 -> V_96 = V_42 ;
return 0 ;
}
F_21 ( L_108 ,
V_20 -> V_95 -> V_183 , V_42 -> V_183 , V_20 -> V_97 ) ;
if ( V_20 -> V_95 -> V_183 + V_42 -> V_183 > V_20 -> V_97 ) {
F_282 ( L_107 ) ;
V_21 = - V_26 ;
goto V_622;
}
F_293 ( V_20 -> V_95 , V_42 , & V_20 -> V_96 ) ;
V_42 = NULL ;
if ( V_20 -> V_95 -> V_183 == V_20 -> V_97 ) {
V_21 = V_20 -> V_32 -> V_424 ( V_20 , V_20 -> V_95 ) ;
if ( ! V_21 ) {
V_20 -> V_95 = NULL ;
V_20 -> V_96 = NULL ;
V_20 -> V_97 = 0 ;
}
}
V_622:
if ( V_21 ) {
F_94 ( V_42 ) ;
F_94 ( V_20 -> V_95 ) ;
V_20 -> V_95 = NULL ;
V_20 -> V_96 = NULL ;
V_20 -> V_97 = 0 ;
}
return 0 ;
}
static void F_314 ( struct V_9 * V_10 , T_2 V_11 ,
struct V_38 * V_42 )
{
struct V_8 * V_20 ;
V_20 = F_5 ( V_10 , V_11 ) ;
if ( ! V_20 ) {
if ( V_11 == V_131 ) {
V_20 = F_315 ( V_10 , V_42 ) ;
if ( ! V_20 ) {
F_94 ( V_42 ) ;
return;
}
F_7 ( V_20 ) ;
} else {
F_21 ( L_109 , V_11 ) ;
F_94 ( V_42 ) ;
return;
}
}
F_21 ( L_110 , V_20 , V_42 -> V_183 ) ;
if ( V_20 -> V_31 != V_61 )
goto V_592;
switch ( V_20 -> V_136 ) {
case V_138 :
if ( F_313 ( V_20 , V_42 ) < 0 )
goto V_592;
goto V_24;
case V_137 :
if ( V_20 -> V_102 < V_42 -> V_183 ) {
F_282 ( L_111 ) ;
goto V_592;
}
if ( ! V_20 -> V_32 -> V_424 ( V_20 , V_42 ) )
goto V_24;
break;
case V_139 :
case V_143 :
F_311 ( V_20 , V_42 ) ;
goto V_24;
default:
F_21 ( L_112 , V_20 , V_20 -> V_136 ) ;
break;
}
V_592:
F_94 ( V_42 ) ;
V_24:
F_46 ( V_20 ) ;
}
static void F_316 ( struct V_9 * V_10 , T_4 V_17 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 ;
if ( V_2 -> type != V_109 )
goto V_592;
V_20 = F_164 ( 0 , V_17 , & V_2 -> V_18 , & V_2 -> V_145 ,
V_109 ) ;
if ( ! V_20 )
goto V_592;
F_21 ( L_110 , V_20 , V_42 -> V_183 ) ;
if ( V_20 -> V_31 != V_623 && V_20 -> V_31 != V_61 )
goto V_592;
if ( V_20 -> V_102 < V_42 -> V_183 )
goto V_592;
F_78 ( & F_33 ( V_42 ) -> V_624 , & V_2 -> V_145 ) ;
F_33 ( V_42 ) -> V_17 = V_17 ;
if ( ! V_20 -> V_32 -> V_424 ( V_20 , V_42 ) )
return;
V_592:
F_94 ( V_42 ) ;
}
static void F_317 ( struct V_9 * V_10 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 ;
if ( V_2 -> type != V_3 )
goto V_592;
V_20 = F_139 ( V_61 , V_331 ,
& V_2 -> V_18 , & V_2 -> V_145 ) ;
if ( ! V_20 )
goto V_592;
F_21 ( L_110 , V_20 , V_42 -> V_183 ) ;
if ( V_20 -> V_102 < V_42 -> V_183 )
goto V_592;
if ( ! V_20 -> V_32 -> V_424 ( V_20 , V_42 ) )
return;
V_592:
F_94 ( V_42 ) ;
}
static void F_318 ( struct V_9 * V_10 , struct V_38 * V_42 )
{
struct V_241 * V_242 = ( void * ) V_42 -> V_184 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_11 , V_183 ;
T_4 V_17 ;
if ( V_2 -> V_31 != V_61 ) {
F_21 ( L_113 ) ;
F_303 ( & V_10 -> V_365 , V_42 ) ;
return;
}
F_99 ( V_42 , V_238 ) ;
V_11 = F_66 ( V_242 -> V_11 ) ;
V_183 = F_66 ( V_242 -> V_183 ) ;
if ( V_183 != V_42 -> V_183 ) {
F_94 ( V_42 ) ;
return;
}
if ( V_2 -> type == V_3 &&
F_141 ( & V_2 -> V_185 -> V_332 , & V_2 -> V_145 ,
F_1 ( V_2 , V_2 -> V_146 ) ) ) {
F_94 ( V_42 ) ;
return;
}
F_21 ( L_114 , V_183 , V_11 ) ;
switch ( V_11 ) {
case V_115 :
F_289 ( V_10 , V_42 ) ;
break;
case V_113 :
V_17 = F_319 ( ( T_4 * ) V_42 -> V_184 ) ;
F_99 ( V_42 , V_395 ) ;
F_316 ( V_10 , V_17 , V_42 ) ;
break;
case V_331 :
F_317 ( V_10 , V_42 ) ;
break;
case V_429 :
F_288 ( V_10 , V_42 ) ;
break;
case V_625 :
if ( F_320 ( V_10 , V_42 ) )
F_153 ( V_10 -> V_2 , V_626 ) ;
break;
default:
F_314 ( V_10 , V_11 , V_42 ) ;
break;
}
}
static void F_321 ( struct V_57 * V_58 )
{
struct V_9 * V_10 = F_44 ( V_58 , struct V_9 ,
V_352 ) ;
struct V_38 * V_42 ;
F_21 ( L_15 ) ;
while ( ( V_42 = F_170 ( & V_10 -> V_365 ) ) )
F_318 ( V_10 , V_42 ) ;
}
static struct V_9 * F_322 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_144 ;
struct V_134 * V_192 ;
if ( V_10 )
return V_10 ;
V_192 = F_323 ( V_2 ) ;
if ( ! V_192 )
return NULL ;
V_10 = F_49 ( sizeof( * V_10 ) , V_51 ) ;
if ( ! V_10 ) {
F_156 ( V_192 ) ;
return NULL ;
}
F_53 ( & V_10 -> V_368 ) ;
V_2 -> V_144 = V_10 ;
V_10 -> V_2 = V_2 ;
F_324 ( V_10 -> V_2 ) ;
V_10 -> V_192 = V_192 ;
F_21 ( L_115 , V_2 , V_10 , V_192 ) ;
switch ( V_2 -> type ) {
case V_3 :
if ( V_2 -> V_185 -> V_627 ) {
V_10 -> V_154 = V_2 -> V_185 -> V_627 ;
break;
}
default:
V_10 -> V_154 = V_2 -> V_185 -> V_617 ;
break;
}
V_10 -> V_304 = 0 ;
if ( V_2 -> type == V_109 )
V_10 -> V_258 = F_73 ( V_628 ,
& V_2 -> V_185 -> V_512 ) ;
F_50 ( & V_10 -> V_180 ) ;
F_50 ( & V_10 -> V_15 ) ;
F_325 ( & V_10 -> V_128 ) ;
F_325 ( & V_10 -> V_362 ) ;
if ( V_2 -> type == V_3 )
F_52 ( & V_10 -> V_367 , F_160 ) ;
else
F_52 ( & V_10 -> V_301 , F_145 ) ;
F_64 ( & V_10 -> V_365 ) ;
F_326 ( & V_10 -> V_352 , F_321 ) ;
V_10 -> V_105 = V_106 ;
return V_10 ;
}
static bool F_327 ( T_2 V_17 , T_3 V_146 ) {
if ( ! V_17 )
return false ;
if ( F_328 ( V_146 ) )
return ( V_17 <= 0x00ff ) ;
return ( ( V_17 & 0x0101 ) == 0x0001 ) ;
}
int F_329 ( struct V_8 * V_20 , T_4 V_17 , T_2 V_11 ,
T_5 * V_145 , T_3 V_146 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_256 * V_185 ;
int V_21 ;
F_21 ( L_116 , & V_20 -> V_18 , V_145 ,
V_146 , F_66 ( V_17 ) ) ;
V_185 = F_330 ( V_145 , & V_20 -> V_18 ) ;
if ( ! V_185 )
return - V_629 ;
F_147 ( V_185 ) ;
F_7 ( V_20 ) ;
if ( ! F_327 ( F_66 ( V_17 ) , V_146 ) && ! V_11 &&
V_20 -> V_107 != V_165 ) {
V_21 = - V_26 ;
goto V_24;
}
if ( V_20 -> V_107 == V_108 && ! V_17 ) {
V_21 = - V_26 ;
goto V_24;
}
if ( V_20 -> V_107 == V_114 && ! V_11 ) {
V_21 = - V_26 ;
goto V_24;
}
switch ( V_20 -> V_136 ) {
case V_137 :
break;
case V_138 :
F_62 ( V_20 ) ;
break;
case V_139 :
case V_143 :
if ( ! V_307 )
break;
default:
V_21 = - V_630 ;
goto V_24;
}
switch ( V_20 -> V_31 ) {
case V_64 :
case V_164 :
case V_62 :
V_21 = 0 ;
goto V_24;
case V_61 :
V_21 = - V_631 ;
goto V_24;
case V_73 :
case V_623 :
break;
default:
V_21 = - V_409 ;
goto V_24;
}
F_78 ( & V_20 -> V_145 , V_145 ) ;
V_20 -> V_146 = V_146 ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_11 ;
if ( F_328 ( V_146 ) ) {
T_3 V_333 ;
if ( V_146 == V_5 )
V_146 = V_4 ;
else
V_146 = V_632 ;
if ( F_73 ( V_633 , & V_185 -> V_512 ) )
V_333 = V_334 ;
else
V_333 = V_578 ;
V_2 = F_331 ( V_185 , V_145 , V_146 , V_20 -> V_65 ,
V_634 , V_333 ) ;
} else {
T_3 V_178 = F_84 ( V_20 ) ;
V_2 = F_332 ( V_185 , V_145 , V_20 -> V_65 , V_178 ) ;
}
if ( F_115 ( V_2 ) ) {
V_21 = F_188 ( V_2 ) ;
goto V_24;
}
V_10 = F_322 ( V_2 ) ;
if ( ! V_10 ) {
F_71 ( V_2 ) ;
V_21 = - V_52 ;
goto V_24;
}
if ( V_11 && F_2 ( V_10 , V_11 ) ) {
F_71 ( V_2 ) ;
V_21 = - V_635 ;
goto V_24;
}
F_78 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
V_20 -> V_348 = F_1 ( V_2 , V_2 -> V_348 ) ;
F_46 ( V_20 ) ;
F_68 ( V_10 , V_20 ) ;
F_7 ( V_20 ) ;
F_71 ( V_2 ) ;
F_20 ( V_20 , V_64 ) ;
F_82 ( V_20 , V_20 -> V_32 -> V_163 ( V_20 ) ) ;
F_15 ( & V_22 ) ;
V_20 -> V_19 = 0 ;
F_17 ( & V_22 ) ;
if ( V_2 -> V_31 == V_61 ) {
if ( V_20 -> V_107 != V_108 ) {
F_70 ( V_20 ) ;
if ( F_85 ( V_20 , true ) )
F_20 ( V_20 , V_61 ) ;
} else
F_133 ( V_20 ) ;
}
V_21 = 0 ;
V_24:
F_46 ( V_20 ) ;
F_148 ( V_185 ) ;
F_253 ( V_185 ) ;
return V_21 ;
}
int F_333 ( struct V_256 * V_185 , T_5 * V_624 )
{
int V_636 = 0 , V_637 = 0 , V_638 = 0 ;
struct V_8 * V_12 ;
F_21 ( L_117 , V_185 -> V_639 , V_624 ) ;
F_119 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_12 -> V_31 != V_162 )
continue;
if ( ! F_13 ( & V_12 -> V_18 , & V_185 -> V_624 ) ) {
V_637 |= V_640 ;
if ( F_73 ( V_641 , & V_12 -> V_94 ) )
V_637 |= V_642 ;
V_636 ++ ;
} else if ( ! F_13 ( & V_12 -> V_18 , V_329 ) ) {
V_638 |= V_640 ;
if ( F_73 ( V_641 , & V_12 -> V_94 ) )
V_638 |= V_642 ;
}
}
F_120 ( & V_22 ) ;
return V_636 ? V_637 : V_638 ;
}
void F_334 ( struct V_1 * V_2 , T_3 V_159 )
{
struct V_9 * V_10 ;
F_21 ( L_118 , V_2 , & V_2 -> V_145 , V_159 ) ;
if ( ! V_159 ) {
V_10 = F_322 ( V_2 ) ;
if ( V_10 )
F_142 ( V_10 ) ;
} else {
F_153 ( V_2 , F_335 ( V_159 ) ) ;
}
}
int F_336 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_144 ;
F_21 ( L_119 , V_2 ) ;
if ( ! V_10 )
return V_106 ;
return V_10 -> V_105 ;
}
void F_337 ( struct V_1 * V_2 , T_3 V_60 )
{
F_21 ( L_120 , V_2 , V_60 ) ;
F_153 ( V_2 , F_335 ( V_60 ) ) ;
}
static inline void F_338 ( struct V_8 * V_20 , T_3 V_643 )
{
if ( V_20 -> V_107 != V_108 )
return;
if ( V_643 == 0x00 ) {
if ( V_20 -> V_65 == V_169 ) {
F_82 ( V_20 , V_644 ) ;
} else if ( V_20 -> V_65 == V_166 ||
V_20 -> V_65 == V_167 )
F_45 ( V_20 , V_63 ) ;
} else {
if ( V_20 -> V_65 == V_169 )
F_70 ( V_20 ) ;
}
}
int F_339 ( struct V_1 * V_2 , T_3 V_159 , T_3 V_643 )
{
struct V_9 * V_10 = V_2 -> V_144 ;
struct V_8 * V_20 ;
if ( ! V_10 )
return 0 ;
F_21 ( L_121 , V_10 , V_159 , V_643 ) ;
if ( V_2 -> type == V_3 ) {
if ( ! V_159 && V_643 )
F_340 ( V_10 ) ;
F_234 ( & V_10 -> V_367 ) ;
}
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
F_21 ( L_122 , V_20 , V_20 -> V_14 ,
F_22 ( V_20 -> V_31 ) ) ;
if ( V_20 -> V_14 == V_131 ) {
F_46 ( V_20 ) ;
continue;
}
if ( V_20 -> V_14 == V_331 ) {
if ( ! V_159 && V_643 ) {
V_20 -> V_65 = V_2 -> V_65 ;
F_127 ( V_20 ) ;
}
F_46 ( V_20 ) ;
continue;
}
if ( ! F_117 ( V_20 ) ) {
F_46 ( V_20 ) ;
continue;
}
if ( ! V_159 && ( V_20 -> V_31 == V_61 ||
V_20 -> V_31 == V_62 ) ) {
V_20 -> V_32 -> V_590 ( V_20 ) ;
F_338 ( V_20 , V_643 ) ;
F_46 ( V_20 ) ;
continue;
}
if ( V_20 -> V_31 == V_64 ) {
if ( ! V_159 )
F_131 ( V_20 ) ;
else
F_82 ( V_20 , V_645 ) ;
} else if ( V_20 -> V_31 == V_164 ) {
struct V_157 V_148 ;
T_6 V_646 , V_647 ;
if ( ! V_159 ) {
if ( F_73 ( V_150 , & V_20 -> V_94 ) ) {
V_646 = V_316 ;
V_647 = V_317 ;
V_20 -> V_32 -> V_318 ( V_20 ) ;
} else {
F_20 ( V_20 , V_62 ) ;
V_646 = V_319 ;
V_647 = V_160 ;
}
} else {
F_20 ( V_20 , V_153 ) ;
F_82 ( V_20 , V_645 ) ;
V_646 = V_158 ;
V_647 = V_160 ;
}
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_149 = F_16 ( V_646 ) ;
V_148 . V_159 = F_16 ( V_647 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_161 ,
sizeof( V_148 ) , & V_148 ) ;
if ( ! F_73 ( V_321 , & V_20 -> V_76 ) &&
V_646 == V_319 ) {
char V_315 [ 128 ] ;
F_54 ( V_321 , & V_20 -> V_76 ) ;
F_80 ( V_10 , F_88 ( V_10 ) ,
V_322 ,
F_138 ( V_20 , V_315 ) ,
V_315 ) ;
V_20 -> V_323 ++ ;
}
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
int F_341 ( struct V_1 * V_2 , struct V_38 * V_42 , T_2 V_94 )
{
struct V_9 * V_10 = V_2 -> V_144 ;
struct V_241 * V_648 ;
int V_183 ;
if ( ! V_10 && V_2 -> V_185 -> V_538 != V_649 )
goto V_592;
if ( ! V_10 )
V_10 = F_322 ( V_2 ) ;
if ( ! V_10 )
goto V_592;
F_21 ( L_123 , V_10 , V_42 -> V_183 , V_94 ) ;
switch ( V_94 ) {
case V_187 :
case V_186 :
case V_197 :
if ( V_10 -> V_650 ) {
F_282 ( L_124 , V_42 -> V_183 ) ;
F_94 ( V_10 -> V_364 ) ;
V_10 -> V_364 = NULL ;
V_10 -> V_650 = 0 ;
F_144 ( V_10 , V_651 ) ;
}
if ( V_42 -> V_183 < V_238 ) {
F_282 ( L_125 , V_42 -> V_183 ) ;
F_144 ( V_10 , V_651 ) ;
goto V_592;
}
V_648 = (struct V_241 * ) V_42 -> V_184 ;
V_183 = F_66 ( V_648 -> V_183 ) + V_238 ;
if ( V_183 == V_42 -> V_183 ) {
F_318 ( V_10 , V_42 ) ;
return 0 ;
}
F_21 ( L_126 , V_183 , V_42 -> V_183 ) ;
if ( V_42 -> V_183 > V_183 ) {
F_282 ( L_127 ,
V_42 -> V_183 , V_183 ) ;
F_144 ( V_10 , V_651 ) ;
goto V_592;
}
V_10 -> V_364 = F_108 ( V_183 , V_51 ) ;
if ( ! V_10 -> V_364 )
goto V_592;
F_342 ( V_42 , F_110 ( V_10 -> V_364 , V_42 -> V_183 ) ,
V_42 -> V_183 ) ;
V_10 -> V_650 = V_183 - V_42 -> V_183 ;
break;
case V_652 :
F_21 ( L_128 , V_42 -> V_183 , V_10 -> V_650 ) ;
if ( ! V_10 -> V_650 ) {
F_282 ( L_129 , V_42 -> V_183 ) ;
F_144 ( V_10 , V_651 ) ;
goto V_592;
}
if ( V_42 -> V_183 > V_10 -> V_650 ) {
F_282 ( L_130 ,
V_42 -> V_183 , V_10 -> V_650 ) ;
F_94 ( V_10 -> V_364 ) ;
V_10 -> V_364 = NULL ;
V_10 -> V_650 = 0 ;
F_144 ( V_10 , V_651 ) ;
goto V_592;
}
F_342 ( V_42 , F_110 ( V_10 -> V_364 , V_42 -> V_183 ) ,
V_42 -> V_183 ) ;
V_10 -> V_650 -= V_42 -> V_183 ;
if ( ! V_10 -> V_650 ) {
struct V_38 * V_364 = V_10 -> V_364 ;
V_10 -> V_364 = NULL ;
F_318 ( V_10 , V_364 ) ;
}
break;
}
V_592:
F_94 ( V_42 ) ;
return 0 ;
}
static int F_343 ( struct V_653 * V_654 , void * V_25 )
{
struct V_8 * V_12 ;
F_119 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
F_344 ( V_654 , L_131 ,
& V_12 -> V_18 , & V_12 -> V_145 ,
V_12 -> V_31 , F_66 ( V_12 -> V_17 ) ,
V_12 -> V_14 , V_12 -> V_13 , V_12 -> V_102 , V_12 -> V_110 ,
V_12 -> V_65 , V_12 -> V_136 ) ;
}
F_120 ( & V_22 ) ;
return 0 ;
}
static int F_345 ( struct V_655 * V_655 , struct V_656 * V_656 )
{
return F_346 ( V_656 , F_343 , V_655 -> V_657 ) ;
}
int T_11 F_347 ( void )
{
int V_21 ;
V_21 = F_348 () ;
if ( V_21 < 0 )
return V_21 ;
if ( F_349 ( V_658 ) )
return 0 ;
V_659 = F_350 ( L_132 , 0444 , V_658 ,
NULL , & V_660 ) ;
F_351 ( L_133 , 0644 , V_658 ,
& V_100 ) ;
F_351 ( L_134 , 0644 , V_658 ,
& V_103 ) ;
return 0 ;
}
void F_352 ( void )
{
F_353 ( V_659 ) ;
F_354 () ;
}
