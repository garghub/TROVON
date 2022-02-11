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
int F_85 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
T_1 V_177 ;
if ( V_10 -> V_2 -> type == V_3 )
return F_86 ( V_10 -> V_2 , V_20 -> V_65 ) ;
V_177 = F_84 ( V_20 ) ;
return F_87 ( V_10 -> V_2 , V_20 -> V_65 , V_177 ) ;
}
static T_3 F_88 ( struct V_9 * V_10 )
{
T_3 V_178 ;
F_89 ( & V_10 -> V_70 ) ;
if ( ++ V_10 -> V_179 > 128 )
V_10 -> V_179 = 1 ;
V_178 = V_10 -> V_179 ;
F_90 ( & V_10 -> V_70 ) ;
return V_178 ;
}
static void F_80 ( struct V_9 * V_10 , T_3 V_16 , T_3 V_180 , T_2 V_181 ,
void * V_182 )
{
struct V_38 * V_42 = F_91 ( V_10 , V_180 , V_16 , V_181 , V_182 ) ;
T_3 V_94 ;
F_21 ( L_8 , V_180 ) ;
if ( ! V_42 )
return;
if ( F_92 ( V_10 -> V_2 -> V_183 ) )
V_94 = V_184 ;
else
V_94 = V_185 ;
F_33 ( V_42 ) -> V_186 = V_187 ;
V_42 -> V_188 = V_189 ;
F_93 ( V_10 -> V_190 , V_42 , V_94 ) ;
}
static bool F_94 ( struct V_8 * V_20 )
{
return V_20 -> V_191 != V_192 &&
V_20 -> V_191 != V_193 ;
}
static void F_95 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
struct V_1 * V_2 = V_20 -> V_10 -> V_2 ;
T_2 V_94 ;
F_21 ( L_9 , V_20 , V_42 , V_42 -> V_181 ,
V_42 -> V_188 ) ;
if ( V_20 -> V_194 && ! F_94 ( V_20 ) ) {
if ( V_20 -> V_133 )
F_93 ( V_20 -> V_133 , V_42 , V_195 ) ;
else
F_96 ( V_42 ) ;
return;
}
if ( ! F_73 ( V_196 , & V_20 -> V_94 ) &&
F_92 ( V_2 -> V_183 ) )
V_94 = V_184 ;
else
V_94 = V_185 ;
F_33 ( V_42 ) -> V_186 = F_73 ( V_93 , & V_20 -> V_94 ) ;
F_93 ( V_20 -> V_10 -> V_190 , V_42 , V_94 ) ;
}
static void F_97 ( T_2 V_197 , struct V_198 * V_43 )
{
V_43 -> V_199 = ( V_197 & V_200 ) >> V_201 ;
V_43 -> V_202 = ( V_197 & V_203 ) >> V_204 ;
if ( V_197 & V_205 ) {
V_43 -> V_206 = 1 ;
V_43 -> V_207 = ( V_197 & V_208 ) >> V_209 ;
V_43 -> V_210 = ( V_197 & V_211 ) >> V_212 ;
V_43 -> V_213 = 0 ;
V_43 -> V_44 = 0 ;
} else {
V_43 -> V_206 = 0 ;
V_43 -> V_213 = ( V_197 & V_214 ) >> V_215 ;
V_43 -> V_44 = ( V_197 & V_216 ) >> V_217 ;
V_43 -> V_207 = 0 ;
V_43 -> V_210 = 0 ;
}
}
static void F_98 ( T_8 V_218 , struct V_198 * V_43 )
{
V_43 -> V_199 = ( V_218 & V_219 ) >> V_220 ;
V_43 -> V_202 = ( V_218 & V_221 ) >> V_222 ;
if ( V_218 & V_223 ) {
V_43 -> V_206 = 1 ;
V_43 -> V_207 = ( V_218 & V_224 ) >> V_225 ;
V_43 -> V_210 = ( V_218 & V_226 ) >> V_227 ;
V_43 -> V_213 = 0 ;
V_43 -> V_44 = 0 ;
} else {
V_43 -> V_206 = 0 ;
V_43 -> V_213 = ( V_218 & V_228 ) >> V_229 ;
V_43 -> V_44 = ( V_218 & V_230 ) >> V_231 ;
V_43 -> V_207 = 0 ;
V_43 -> V_210 = 0 ;
}
}
static inline void F_99 ( struct V_8 * V_20 ,
struct V_38 * V_42 )
{
if ( F_73 ( V_232 , & V_20 -> V_94 ) ) {
F_98 ( F_100 ( V_42 -> V_182 ) ,
& F_33 ( V_42 ) -> V_43 ) ;
F_101 ( V_42 , V_233 ) ;
} else {
F_97 ( F_102 ( V_42 -> V_182 ) ,
& F_33 ( V_42 ) -> V_43 ) ;
F_101 ( V_42 , V_234 ) ;
}
}
static T_8 F_103 ( struct V_198 * V_43 )
{
T_8 V_235 ;
V_235 = V_43 -> V_199 << V_220 ;
V_235 |= V_43 -> V_202 << V_222 ;
if ( V_43 -> V_206 ) {
V_235 |= V_43 -> V_207 << V_225 ;
V_235 |= V_43 -> V_210 << V_227 ;
V_235 |= V_223 ;
} else {
V_235 |= V_43 -> V_213 << V_229 ;
V_235 |= V_43 -> V_44 << V_231 ;
}
return V_235 ;
}
static T_2 F_104 ( struct V_198 * V_43 )
{
T_2 V_235 ;
V_235 = V_43 -> V_199 << V_201 ;
V_235 |= V_43 -> V_202 << V_204 ;
if ( V_43 -> V_206 ) {
V_235 |= V_43 -> V_207 << V_209 ;
V_235 |= V_43 -> V_210 << V_212 ;
V_235 |= V_205 ;
} else {
V_235 |= V_43 -> V_213 << V_215 ;
V_235 |= V_43 -> V_44 << V_217 ;
}
return V_235 ;
}
static inline void F_105 ( struct V_8 * V_20 ,
struct V_198 * V_43 ,
struct V_38 * V_42 )
{
if ( F_73 ( V_232 , & V_20 -> V_94 ) ) {
F_106 ( F_103 ( V_43 ) ,
V_42 -> V_182 + V_236 ) ;
} else {
F_107 ( F_104 ( V_43 ) ,
V_42 -> V_182 + V_236 ) ;
}
}
static inline unsigned int F_108 ( struct V_8 * V_20 )
{
if ( F_73 ( V_232 , & V_20 -> V_94 ) )
return V_237 ;
else
return V_238 ;
}
static struct V_38 * F_109 ( struct V_8 * V_20 ,
T_8 V_43 )
{
struct V_38 * V_42 ;
struct V_239 * V_240 ;
int V_241 = F_108 ( V_20 ) ;
if ( V_20 -> V_78 == V_79 )
V_241 += V_242 ;
V_42 = F_110 ( V_241 , V_51 ) ;
if ( ! V_42 )
return F_111 ( - V_52 ) ;
V_240 = (struct V_239 * ) F_112 ( V_42 , V_236 ) ;
V_240 -> V_181 = F_16 ( V_241 - V_236 ) ;
V_240 -> V_11 = F_16 ( V_20 -> V_13 ) ;
if ( F_73 ( V_232 , & V_20 -> V_94 ) )
F_106 ( V_43 , F_112 ( V_42 , V_233 ) ) ;
else
F_107 ( V_43 , F_112 ( V_42 , V_234 ) ) ;
if ( V_20 -> V_78 == V_79 ) {
T_2 V_78 = F_113 ( 0 , ( T_3 * ) V_42 -> V_182 , V_42 -> V_181 ) ;
F_107 ( V_78 , F_112 ( V_42 , V_242 ) ) ;
}
V_42 -> V_188 = V_189 ;
return V_42 ;
}
static void F_114 ( struct V_8 * V_20 ,
struct V_198 * V_43 )
{
struct V_38 * V_42 ;
T_8 V_243 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( ! V_43 -> V_206 )
return;
if ( F_94 ( V_20 ) )
return;
if ( F_115 ( V_244 , & V_20 -> V_245 ) &&
! V_43 -> V_207 )
V_43 -> V_202 = 1 ;
if ( V_43 -> V_210 == V_246 )
F_116 ( V_247 , & V_20 -> V_245 ) ;
else if ( V_43 -> V_210 == V_248 )
F_54 ( V_247 , & V_20 -> V_245 ) ;
if ( V_43 -> V_210 != V_249 ) {
V_20 -> V_250 = V_43 -> V_199 ;
F_76 ( V_20 ) ;
}
F_21 ( L_11 , V_43 -> V_199 ,
V_43 -> V_202 , V_43 -> V_207 , V_43 -> V_210 ) ;
if ( F_73 ( V_232 , & V_20 -> V_94 ) )
V_243 = F_103 ( V_43 ) ;
else
V_243 = F_104 ( V_43 ) ;
V_42 = F_109 ( V_20 , V_243 ) ;
if ( ! F_117 ( V_42 ) )
F_95 ( V_20 , V_42 ) ;
}
static void F_118 ( struct V_8 * V_20 , bool V_207 )
{
struct V_198 V_43 ;
F_21 ( L_12 , V_20 , V_207 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_206 = 1 ;
V_43 . V_207 = V_207 ;
if ( F_73 ( V_251 , & V_20 -> V_245 ) )
V_43 . V_210 = V_248 ;
else
V_43 . V_210 = V_246 ;
V_43 . V_199 = V_20 -> V_252 ;
F_114 ( V_20 , & V_43 ) ;
}
static inline int F_119 ( struct V_8 * V_20 )
{
return ! F_73 ( V_253 , & V_20 -> V_76 ) ;
}
static bool F_120 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_254 * V_183 ;
bool V_255 = false ;
if ( ! V_10 -> V_256 )
return false ;
if ( ! ( V_10 -> V_257 & V_258 ) )
return false ;
F_121 ( & V_259 ) ;
F_3 (hdev, &hci_dev_list, list) {
if ( V_183 -> V_260 != V_261 &&
F_73 ( V_262 , & V_183 -> V_94 ) ) {
V_255 = true ;
break;
}
}
F_122 ( & V_259 ) ;
if ( V_20 -> V_263 == V_264 )
return V_255 ;
return false ;
}
static bool F_123 ( struct V_8 * V_20 )
{
return true ;
}
void F_124 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_265 V_266 ;
V_266 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_266 . V_17 = V_20 -> V_17 ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_54 ( V_253 , & V_20 -> V_76 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_267 , sizeof( V_266 ) , & V_266 ) ;
}
static void F_125 ( struct V_8 * V_20 , T_3 V_268 )
{
struct V_269 V_266 ;
V_266 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_266 . V_17 = V_20 -> V_17 ;
V_266 . V_268 = V_268 ;
V_20 -> V_16 = F_88 ( V_20 -> V_10 ) ;
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_270 ,
sizeof( V_266 ) , & V_266 ) ;
}
static void F_126 ( struct V_8 * V_20 )
{
struct V_38 * V_42 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_136 != V_139 )
return;
F_30 ( V_20 ) ;
F_75 ( V_20 ) ;
F_76 ( V_20 ) ;
V_20 -> V_271 = 0 ;
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_42 ) -> V_43 . V_272 )
F_33 ( V_42 ) -> V_43 . V_272 = 1 ;
else
break;
}
V_20 -> V_273 = V_20 -> V_252 ;
F_116 ( V_274 , & V_20 -> V_245 ) ;
F_116 ( V_275 , & V_20 -> V_245 ) ;
F_41 ( & V_20 -> V_142 ) ;
F_41 ( & V_20 -> V_141 ) ;
F_74 ( & V_20 -> V_140 ) ;
V_20 -> V_276 = V_277 ;
V_20 -> V_278 = V_279 ;
F_54 ( V_280 , & V_20 -> V_245 ) ;
}
static void F_127 ( struct V_8 * V_20 )
{
T_3 V_281 = V_20 -> V_281 ;
F_21 ( L_3 , V_20 ) ;
V_20 -> V_191 = V_192 ;
V_20 -> V_281 = V_282 ;
if ( V_20 -> V_136 != V_139 )
return;
switch ( V_281 ) {
case V_283 :
F_128 ( V_20 , NULL , NULL , V_284 ) ;
V_20 -> V_278 = V_285 ;
break;
case V_286 :
V_20 -> V_278 = V_287 ;
break;
}
}
static void F_129 ( struct V_8 * V_20 )
{
V_20 -> V_76 = 0 ;
F_70 ( V_20 ) ;
if ( V_20 -> V_136 == V_138 && ! V_20 -> V_98 )
V_20 -> V_32 -> V_288 ( V_20 ) ;
V_20 -> V_31 = V_61 ;
V_20 -> V_32 -> V_289 ( V_20 ) ;
}
static void F_130 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_290 V_266 ;
if ( F_131 ( V_291 , & V_20 -> V_94 ) )
return;
V_266 . V_17 = V_20 -> V_17 ;
V_266 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_266 . V_154 = F_16 ( V_20 -> V_102 ) ;
V_266 . V_101 = F_16 ( V_20 -> V_101 ) ;
V_266 . V_155 = F_16 ( V_20 -> V_99 ) ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_292 ,
sizeof( V_266 ) , & V_266 ) ;
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
if ( V_10 -> V_293 & V_294 ) {
if ( ! ( V_10 -> V_293 & V_295 ) )
return;
if ( F_85 ( V_20 ) &&
F_119 ( V_20 ) ) {
F_133 ( V_20 ) ;
}
} else {
struct V_296 V_266 ;
V_266 . type = F_16 ( V_297 ) ;
V_10 -> V_293 |= V_294 ;
V_10 -> V_298 = F_88 ( V_10 ) ;
F_136 ( & V_10 -> V_299 , V_300 ) ;
F_80 ( V_10 , V_10 -> V_298 , V_301 ,
sizeof( V_266 ) , & V_266 ) ;
}
}
static inline int F_137 ( T_1 V_136 , T_9 V_302 )
{
T_8 V_303 = V_304 ;
if ( ! V_305 )
V_303 |= V_306 | V_307 ;
switch ( V_136 ) {
case V_139 :
return V_306 & V_302 & V_303 ;
case V_143 :
return V_307 & V_302 & V_303 ;
default:
return 0x00 ;
}
}
static void F_83 ( struct V_8 * V_20 , int V_21 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_308 V_266 ;
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
V_266 . V_13 = F_16 ( V_20 -> V_13 ) ;
V_266 . V_14 = F_16 ( V_20 -> V_14 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_309 ,
sizeof( V_266 ) , & V_266 ) ;
F_23 ( V_20 , V_153 , V_21 ) ;
}
static void F_138 ( struct V_9 * V_10 )
{
struct V_8 * V_20 , * V_310 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_139 (chan, tmp, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_107 != V_108 ) {
F_46 ( V_20 ) ;
continue;
}
if ( V_20 -> V_31 == V_64 ) {
if ( ! F_85 ( V_20 ) ||
! F_119 ( V_20 ) ) {
F_46 ( V_20 ) ;
continue;
}
if ( ! F_137 ( V_20 -> V_136 , V_10 -> V_302 )
&& F_73 ( V_311 ,
& V_20 -> V_76 ) ) {
F_45 ( V_20 , V_312 ) ;
F_46 ( V_20 ) ;
continue;
}
F_133 ( V_20 ) ;
} else if ( V_20 -> V_31 == V_164 ) {
struct V_157 V_148 ;
char V_313 [ 128 ] ;
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( F_85 ( V_20 ) ) {
if ( F_73 ( V_150 , & V_20 -> V_94 ) ) {
V_148 . V_149 = F_16 ( V_314 ) ;
V_148 . V_159 = F_16 ( V_315 ) ;
V_20 -> V_32 -> V_316 ( V_20 ) ;
} else {
F_20 ( V_20 , V_62 ) ;
V_148 . V_149 = F_16 ( V_317 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
}
} else {
V_148 . V_149 = F_16 ( V_314 ) ;
V_148 . V_159 = F_16 ( V_318 ) ;
}
F_80 ( V_10 , V_20 -> V_16 , V_161 ,
sizeof( V_148 ) , & V_148 ) ;
if ( F_73 ( V_319 , & V_20 -> V_76 ) ||
V_148 . V_149 != V_317 ) {
F_46 ( V_20 ) ;
continue;
}
F_54 ( V_319 , & V_20 -> V_76 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_320 ,
F_140 ( V_20 , V_313 ) , V_313 ) ;
V_20 -> V_321 ++ ;
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static struct V_8 * F_141 ( int V_31 , T_2 V_11 ,
T_5 * V_18 ,
T_5 * V_145 )
{
struct V_8 * V_12 , * V_322 = NULL ;
F_121 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_31 && V_12 -> V_31 != V_31 )
continue;
if ( V_12 -> V_14 == V_11 ) {
int V_323 , V_324 ;
int V_325 , V_326 ;
V_323 = ! F_13 ( & V_12 -> V_18 , V_18 ) ;
V_324 = ! F_13 ( & V_12 -> V_145 , V_145 ) ;
if ( V_323 && V_324 ) {
F_122 ( & V_22 ) ;
return V_12 ;
}
V_325 = ! F_13 ( & V_12 -> V_18 , V_327 ) ;
V_326 = ! F_13 ( & V_12 -> V_145 , V_327 ) ;
if ( ( V_323 && V_326 ) || ( V_325 && V_324 ) ||
( V_325 && V_326 ) )
V_322 = V_12 ;
}
}
F_122 ( & V_22 ) ;
return V_322 ;
}
static void F_142 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 , * V_328 ;
T_3 V_146 ;
F_21 ( L_15 ) ;
F_143 ( V_10 ) ;
V_328 = F_141 ( V_162 , V_329 ,
& V_2 -> V_18 , & V_2 -> V_145 ) ;
if ( ! V_328 )
return;
if ( F_2 ( V_10 , V_329 ) )
return;
V_146 = F_1 ( V_2 , V_2 -> V_146 ) ;
if ( F_144 ( V_2 -> V_183 , & V_2 -> V_145 , V_146 ) )
return;
F_7 ( V_328 ) ;
V_20 = V_328 -> V_32 -> V_330 ( V_328 ) ;
if ( ! V_20 )
goto V_331;
F_78 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
F_78 ( & V_20 -> V_145 , & V_2 -> V_145 ) ;
V_20 -> V_332 = F_1 ( V_2 , V_2 -> V_332 ) ;
V_20 -> V_146 = V_146 ;
F_65 ( V_10 , V_20 ) ;
V_331:
F_46 ( V_328 ) ;
}
static void F_145 ( struct V_9 * V_10 )
{
struct V_8 * V_20 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_21 ( L_14 , V_10 ) ;
if ( V_2 -> V_333 && V_2 -> type == V_3 )
F_86 ( V_2 , V_2 -> V_334 ) ;
F_6 ( & V_10 -> V_15 ) ;
if ( V_2 -> type == V_3 )
F_142 ( V_10 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_14 == V_131 ) {
F_46 ( V_20 ) ;
continue;
}
if ( V_2 -> type == V_3 ) {
F_132 ( V_20 ) ;
} else if ( V_20 -> V_107 != V_108 ) {
F_129 ( V_20 ) ;
} else if ( V_20 -> V_31 == V_64 ) {
F_135 ( V_20 ) ;
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
F_146 ( V_2 -> V_183 -> V_335 , & V_10 -> V_336 ) ;
}
static void F_147 ( struct V_9 * V_10 , int V_21 )
{
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( F_73 ( V_337 , & V_20 -> V_94 ) )
F_24 ( V_20 , V_21 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_148 ( struct V_57 * V_58 )
{
struct V_9 * V_10 = F_44 ( V_58 , struct V_9 ,
V_299 . V_58 ) ;
V_10 -> V_293 |= V_295 ;
V_10 -> V_298 = 0 ;
F_138 ( V_10 ) ;
}
int F_149 ( struct V_9 * V_10 , struct V_338 * V_339 )
{
struct V_254 * V_183 = V_10 -> V_2 -> V_183 ;
int V_340 ;
F_150 ( V_183 ) ;
if ( V_339 -> V_50 . V_341 || V_339 -> V_50 . V_342 ) {
V_340 = - V_26 ;
goto V_343;
}
if ( ! V_10 -> V_190 ) {
V_340 = - V_344 ;
goto V_343;
}
V_340 = V_339 -> V_345 ( V_10 , V_339 ) ;
if ( V_340 )
goto V_343;
F_51 ( & V_339 -> V_50 , & V_10 -> V_346 ) ;
V_340 = 0 ;
V_343:
F_151 ( V_183 ) ;
return V_340 ;
}
void F_152 ( struct V_9 * V_10 , struct V_338 * V_339 )
{
struct V_254 * V_183 = V_10 -> V_2 -> V_183 ;
F_150 ( V_183 ) ;
if ( ! V_339 -> V_50 . V_341 || ! V_339 -> V_50 . V_342 )
goto V_343;
F_56 ( & V_339 -> V_50 ) ;
V_339 -> V_50 . V_341 = NULL ;
V_339 -> V_50 . V_342 = NULL ;
V_339 -> remove ( V_10 , V_339 ) ;
V_343:
F_151 ( V_183 ) ;
}
static void F_153 ( struct V_9 * V_10 )
{
struct V_338 * V_339 ;
while ( ! F_154 ( & V_10 -> V_346 ) ) {
V_339 = F_155 ( & V_10 -> V_346 , struct V_338 , V_50 ) ;
F_56 ( & V_339 -> V_50 ) ;
V_339 -> V_50 . V_341 = NULL ;
V_339 -> V_50 . V_342 = NULL ;
V_339 -> remove ( V_10 , V_339 ) ;
}
}
static void F_156 ( struct V_1 * V_2 , int V_21 )
{
struct V_9 * V_10 = V_2 -> V_144 ;
struct V_8 * V_20 , * V_347 ;
if ( ! V_10 )
return;
F_21 ( L_16 , V_2 , V_10 , V_21 ) ;
F_96 ( V_10 -> V_348 ) ;
F_74 ( & V_10 -> V_349 ) ;
if ( F_157 ( & V_10 -> V_336 ) )
F_158 ( & V_10 -> V_336 ) ;
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
F_159 ( V_10 -> V_190 ) ;
if ( V_10 -> V_293 & V_294 )
F_160 ( & V_10 -> V_299 ) ;
if ( F_115 ( V_350 , & V_2 -> V_94 ) ) {
F_160 ( & V_10 -> V_351 ) ;
F_161 ( V_10 ) ;
}
V_2 -> V_144 = NULL ;
V_10 -> V_190 = NULL ;
F_162 ( V_10 ) ;
}
static void F_163 ( struct V_57 * V_58 )
{
struct V_9 * V_10 = F_44 ( V_58 , struct V_9 ,
V_351 . V_58 ) ;
F_21 ( L_14 , V_10 ) ;
if ( F_115 ( V_350 , & V_10 -> V_2 -> V_94 ) ) {
F_161 ( V_10 ) ;
F_156 ( V_10 -> V_2 , V_67 ) ;
}
}
static void F_164 ( struct V_74 * V_352 )
{
struct V_9 * V_10 = F_44 ( V_352 , struct V_9 , V_352 ) ;
F_165 ( V_10 -> V_2 ) ;
F_38 ( V_10 ) ;
}
void F_166 ( struct V_9 * V_10 )
{
F_59 ( & V_10 -> V_352 ) ;
}
void F_162 ( struct V_9 * V_10 )
{
F_60 ( & V_10 -> V_352 , F_164 ) ;
}
static struct V_8 * F_167 ( int V_31 , T_4 V_17 ,
T_5 * V_18 ,
T_5 * V_145 ,
T_3 V_353 )
{
struct V_8 * V_12 , * V_322 = NULL ;
F_121 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_31 && V_12 -> V_31 != V_31 )
continue;
if ( V_353 == V_109 && V_12 -> V_332 != V_7 )
continue;
if ( V_353 == V_3 && V_12 -> V_332 == V_7 )
continue;
if ( V_12 -> V_17 == V_17 ) {
int V_323 , V_324 ;
int V_325 , V_326 ;
V_323 = ! F_13 ( & V_12 -> V_18 , V_18 ) ;
V_324 = ! F_13 ( & V_12 -> V_145 , V_145 ) ;
if ( V_323 && V_324 ) {
F_122 ( & V_22 ) ;
return V_12 ;
}
V_325 = ! F_13 ( & V_12 -> V_18 , V_327 ) ;
V_326 = ! F_13 ( & V_12 -> V_145 , V_327 ) ;
if ( ( V_323 && V_326 ) || ( V_325 && V_324 ) ||
( V_325 && V_326 ) )
V_322 = V_12 ;
}
}
F_122 ( & V_22 ) ;
return V_322 ;
}
static void F_168 ( struct V_57 * V_58 )
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
F_128 ( V_20 , NULL , NULL , V_354 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
static void F_169 ( struct V_57 * V_58 )
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
F_128 ( V_20 , NULL , NULL , V_355 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
static void F_170 ( struct V_8 * V_20 ,
struct V_39 * V_356 )
{
struct V_38 * V_42 ;
struct V_198 * V_43 ;
F_21 ( L_17 , V_20 , V_356 ) ;
if ( F_94 ( V_20 ) )
return;
F_171 ( V_356 , & V_20 -> V_104 ) ;
while ( ! F_172 ( & V_20 -> V_104 ) ) {
V_42 = F_173 ( & V_20 -> V_104 ) ;
F_33 ( V_42 ) -> V_43 . V_272 = 1 ;
V_43 = & F_33 ( V_42 ) -> V_43 ;
V_43 -> V_199 = 0 ;
V_43 -> V_44 = V_20 -> V_357 ;
F_105 ( V_20 , V_43 , V_42 ) ;
if ( V_20 -> V_78 == V_79 ) {
T_2 V_78 = F_113 ( 0 , ( T_3 * ) V_42 -> V_182 , V_42 -> V_181 ) ;
F_107 ( V_78 , F_112 ( V_42 , V_242 ) ) ;
}
F_95 ( V_20 , V_42 ) ;
F_21 ( L_18 , V_43 -> V_44 ) ;
V_20 -> V_357 = F_174 ( V_20 , V_20 -> V_357 ) ;
V_20 -> V_358 ++ ;
}
}
static int F_175 ( struct V_8 * V_20 )
{
struct V_38 * V_42 , * V_359 ;
struct V_198 * V_43 ;
int V_360 = 0 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_31 != V_61 )
return - V_361 ;
if ( F_73 ( V_280 , & V_20 -> V_245 ) )
return 0 ;
if ( F_94 ( V_20 ) )
return 0 ;
while ( V_20 -> V_362 &&
V_20 -> V_363 < V_20 -> V_86 &&
V_20 -> V_276 == V_277 ) {
V_42 = V_20 -> V_362 ;
F_33 ( V_42 ) -> V_43 . V_272 = 1 ;
V_43 = & F_33 ( V_42 ) -> V_43 ;
if ( F_115 ( V_244 , & V_20 -> V_245 ) )
V_43 -> V_202 = 1 ;
V_43 -> V_199 = V_20 -> V_252 ;
V_20 -> V_250 = V_20 -> V_252 ;
V_43 -> V_44 = V_20 -> V_357 ;
F_105 ( V_20 , V_43 , V_42 ) ;
if ( V_20 -> V_78 == V_79 ) {
T_2 V_78 = F_113 ( 0 , ( T_3 * ) V_42 -> V_182 , V_42 -> V_181 ) ;
F_107 ( V_78 , F_112 ( V_42 , V_242 ) ) ;
}
V_359 = F_176 ( V_42 , V_51 ) ;
if ( ! V_359 )
break;
F_25 ( V_20 ) ;
V_20 -> V_357 = F_174 ( V_20 , V_20 -> V_357 ) ;
V_20 -> V_363 ++ ;
V_20 -> V_358 ++ ;
V_360 ++ ;
if ( F_177 ( & V_20 -> V_104 , V_42 ) )
V_20 -> V_362 = NULL ;
else
V_20 -> V_362 = F_178 ( & V_20 -> V_104 , V_42 ) ;
F_95 ( V_20 , V_359 ) ;
F_21 ( L_18 , V_43 -> V_44 ) ;
}
F_21 ( L_19 , V_360 ,
V_20 -> V_363 , F_179 ( & V_20 -> V_104 ) ) ;
return V_360 ;
}
static void F_180 ( struct V_8 * V_20 )
{
struct V_198 V_43 ;
struct V_38 * V_42 ;
struct V_38 * V_359 ;
T_2 V_41 ;
F_21 ( L_3 , V_20 ) ;
if ( F_73 ( V_280 , & V_20 -> V_245 ) )
return;
if ( F_94 ( V_20 ) )
return;
while ( V_20 -> V_142 . V_40 != V_54 ) {
V_41 = F_40 ( & V_20 -> V_142 ) ;
V_42 = F_31 ( & V_20 -> V_104 , V_41 ) ;
if ( ! V_42 ) {
F_21 ( L_20 ,
V_41 ) ;
continue;
}
F_33 ( V_42 ) -> V_43 . V_272 ++ ;
V_43 = F_33 ( V_42 ) -> V_43 ;
if ( V_20 -> V_80 != 0 &&
F_33 ( V_42 ) -> V_43 . V_272 > V_20 -> V_80 ) {
F_21 ( L_21 , V_20 -> V_80 ) ;
F_83 ( V_20 , V_312 ) ;
F_41 ( & V_20 -> V_142 ) ;
break;
}
V_43 . V_199 = V_20 -> V_252 ;
if ( F_115 ( V_244 , & V_20 -> V_245 ) )
V_43 . V_202 = 1 ;
else
V_43 . V_202 = 0 ;
if ( F_181 ( V_42 ) ) {
V_359 = F_182 ( V_42 , V_51 ) ;
} else {
V_359 = F_176 ( V_42 , V_51 ) ;
}
if ( ! V_359 ) {
F_41 ( & V_20 -> V_142 ) ;
break;
}
if ( F_73 ( V_232 , & V_20 -> V_94 ) ) {
F_106 ( F_103 ( & V_43 ) ,
V_359 -> V_182 + V_236 ) ;
} else {
F_107 ( F_104 ( & V_43 ) ,
V_359 -> V_182 + V_236 ) ;
}
if ( V_20 -> V_78 == V_79 ) {
T_2 V_78 = F_113 ( 0 , ( T_3 * ) V_359 -> V_182 , V_359 -> V_181 ) ;
F_107 ( V_78 , F_112 ( V_359 ,
V_242 ) ) ;
}
F_95 ( V_20 , V_359 ) ;
F_21 ( L_22 , V_43 . V_44 ) ;
V_20 -> V_250 = V_20 -> V_252 ;
}
}
static void F_183 ( struct V_8 * V_20 ,
struct V_198 * V_43 )
{
F_21 ( L_10 , V_20 , V_43 ) ;
F_42 ( & V_20 -> V_142 , V_43 -> V_199 ) ;
F_180 ( V_20 ) ;
}
static void F_184 ( struct V_8 * V_20 ,
struct V_198 * V_43 )
{
struct V_38 * V_42 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( V_43 -> V_207 )
F_54 ( V_244 , & V_20 -> V_245 ) ;
F_41 ( & V_20 -> V_142 ) ;
if ( F_73 ( V_280 , & V_20 -> V_245 ) )
return;
if ( V_20 -> V_363 ) {
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_42 ) -> V_43 . V_44 == V_43 -> V_199 ||
V_42 == V_20 -> V_362 )
break;
}
F_185 (&chan->tx_q, skb) {
if ( V_42 == V_20 -> V_362 )
break;
F_42 ( & V_20 -> V_142 ,
F_33 ( V_42 ) -> V_43 . V_44 ) ;
}
F_180 ( V_20 ) ;
}
}
static void F_186 ( struct V_8 * V_20 )
{
struct V_198 V_43 ;
T_2 V_364 = F_187 ( V_20 , V_20 -> V_252 ,
V_20 -> V_250 ) ;
int V_365 ;
F_21 ( L_23 ,
V_20 , V_20 -> V_250 , V_20 -> V_252 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_206 = 1 ;
if ( F_73 ( V_251 , & V_20 -> V_245 ) &&
V_20 -> V_278 == V_366 ) {
F_76 ( V_20 ) ;
V_43 . V_210 = V_248 ;
V_43 . V_199 = V_20 -> V_252 ;
F_114 ( V_20 , & V_43 ) ;
} else {
if ( ! F_73 ( V_280 , & V_20 -> V_245 ) ) {
F_175 ( V_20 ) ;
if ( V_20 -> V_252 == V_20 -> V_250 )
V_364 = 0 ;
}
V_365 = V_20 -> V_87 ;
V_365 += V_365 << 1 ;
V_365 >>= 2 ;
F_21 ( L_24 , V_364 ,
V_365 ) ;
if ( V_364 >= V_365 ) {
F_76 ( V_20 ) ;
V_43 . V_210 = V_246 ;
V_43 . V_199 = V_20 -> V_252 ;
F_114 ( V_20 , & V_43 ) ;
V_364 = 0 ;
}
if ( V_364 )
F_188 ( V_20 ) ;
}
}
static inline int F_189 ( struct V_8 * V_20 ,
struct V_367 * V_368 , int V_181 ,
int V_369 , struct V_38 * V_42 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * * V_370 ;
int V_360 = 0 ;
if ( F_190 ( F_112 ( V_42 , V_369 ) , V_368 -> V_371 , V_369 ) )
return - V_372 ;
V_360 += V_369 ;
V_181 -= V_369 ;
V_370 = & F_191 ( V_42 ) -> V_373 ;
while ( V_181 ) {
struct V_38 * V_310 ;
V_369 = F_63 (unsigned int, conn->mtu, len) ;
V_310 = V_20 -> V_32 -> V_374 ( V_20 , V_369 ,
V_368 -> V_375 & V_376 ) ;
if ( F_117 ( V_310 ) )
return F_192 ( V_310 ) ;
* V_370 = V_310 ;
if ( F_190 ( F_112 ( * V_370 , V_369 ) , V_368 -> V_371 , V_369 ) )
return - V_372 ;
( * V_370 ) -> V_188 = V_42 -> V_188 ;
V_360 += V_369 ;
V_181 -= V_369 ;
V_42 -> V_181 += ( * V_370 ) -> V_181 ;
V_42 -> V_377 += ( * V_370 ) -> V_181 ;
V_370 = & ( * V_370 ) -> V_341 ;
}
return V_360 ;
}
static struct V_38 * F_193 ( struct V_8 * V_20 ,
struct V_367 * V_368 , T_7 V_181 ,
T_8 V_188 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_369 , V_241 = V_236 + V_378 ;
struct V_239 * V_240 ;
F_21 ( L_25 , V_20 ,
F_66 ( V_20 -> V_17 ) , V_181 , V_188 ) ;
V_369 = F_63 (unsigned int, (conn->mtu - hlen), len) ;
V_42 = V_20 -> V_32 -> V_374 ( V_20 , V_369 + V_241 ,
V_368 -> V_375 & V_376 ) ;
if ( F_117 ( V_42 ) )
return V_42 ;
V_42 -> V_188 = V_188 ;
V_240 = (struct V_239 * ) F_112 ( V_42 , V_236 ) ;
V_240 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_240 -> V_181 = F_16 ( V_181 + V_378 ) ;
F_194 ( V_20 -> V_17 , ( T_4 * ) F_112 ( V_42 , V_378 ) ) ;
V_21 = F_189 ( V_20 , V_368 , V_181 , V_369 , V_42 ) ;
if ( F_195 ( V_21 < 0 ) ) {
F_96 ( V_42 ) ;
return F_111 ( V_21 ) ;
}
return V_42 ;
}
static struct V_38 * F_196 ( struct V_8 * V_20 ,
struct V_367 * V_368 , T_7 V_181 ,
T_8 V_188 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_369 ;
struct V_239 * V_240 ;
F_21 ( L_26 , V_20 , V_181 ) ;
V_369 = F_63 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_42 = V_20 -> V_32 -> V_374 ( V_20 , V_369 + V_236 ,
V_368 -> V_375 & V_376 ) ;
if ( F_117 ( V_42 ) )
return V_42 ;
V_42 -> V_188 = V_188 ;
V_240 = (struct V_239 * ) F_112 ( V_42 , V_236 ) ;
V_240 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_240 -> V_181 = F_16 ( V_181 ) ;
V_21 = F_189 ( V_20 , V_368 , V_181 , V_369 , V_42 ) ;
if ( F_195 ( V_21 < 0 ) ) {
F_96 ( V_42 ) ;
return F_111 ( V_21 ) ;
}
return V_42 ;
}
static struct V_38 * F_197 ( struct V_8 * V_20 ,
struct V_367 * V_368 , T_7 V_181 ,
T_2 V_379 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_369 , V_241 ;
struct V_239 * V_240 ;
F_21 ( L_26 , V_20 , V_181 ) ;
if ( ! V_10 )
return F_111 ( - V_361 ) ;
V_241 = F_108 ( V_20 ) ;
if ( V_379 )
V_241 += V_380 ;
if ( V_20 -> V_78 == V_79 )
V_241 += V_242 ;
V_369 = F_63 (unsigned int, (conn->mtu - hlen), len) ;
V_42 = V_20 -> V_32 -> V_374 ( V_20 , V_369 + V_241 ,
V_368 -> V_375 & V_376 ) ;
if ( F_117 ( V_42 ) )
return V_42 ;
V_240 = (struct V_239 * ) F_112 ( V_42 , V_236 ) ;
V_240 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_240 -> V_181 = F_16 ( V_181 + ( V_241 - V_236 ) ) ;
if ( F_73 ( V_232 , & V_20 -> V_94 ) )
F_106 ( 0 , F_112 ( V_42 , V_233 ) ) ;
else
F_107 ( 0 , F_112 ( V_42 , V_234 ) ) ;
if ( V_379 )
F_107 ( V_379 , F_112 ( V_42 , V_380 ) ) ;
V_21 = F_189 ( V_20 , V_368 , V_181 , V_369 , V_42 ) ;
if ( F_195 ( V_21 < 0 ) ) {
F_96 ( V_42 ) ;
return F_111 ( V_21 ) ;
}
F_33 ( V_42 ) -> V_43 . V_78 = V_20 -> V_78 ;
F_33 ( V_42 ) -> V_43 . V_272 = 0 ;
return V_42 ;
}
static int F_198 ( struct V_8 * V_20 ,
struct V_39 * V_381 ,
struct V_367 * V_368 , T_7 V_181 )
{
struct V_38 * V_42 ;
T_2 V_97 ;
T_7 V_382 ;
T_3 V_213 ;
F_21 ( L_27 , V_20 , V_368 , V_181 ) ;
V_382 = V_20 -> V_10 -> V_154 ;
if ( ! V_20 -> V_194 )
V_382 = F_63 ( T_7 , V_382 , V_383 ) ;
if ( V_20 -> V_78 )
V_382 -= V_242 ;
V_382 -= F_108 ( V_20 ) ;
V_382 = F_63 ( T_7 , V_382 , V_20 -> V_384 ) ;
if ( V_181 <= V_382 ) {
V_213 = V_385 ;
V_97 = 0 ;
V_382 = V_181 ;
} else {
V_213 = V_386 ;
V_97 = V_181 ;
V_382 -= V_380 ;
}
while ( V_181 > 0 ) {
V_42 = F_197 ( V_20 , V_368 , V_382 , V_97 ) ;
if ( F_117 ( V_42 ) ) {
F_199 ( V_381 ) ;
return F_192 ( V_42 ) ;
}
F_33 ( V_42 ) -> V_43 . V_213 = V_213 ;
F_200 ( V_381 , V_42 ) ;
V_181 -= V_382 ;
if ( V_97 ) {
V_97 = 0 ;
V_382 += V_380 ;
}
if ( V_181 <= V_382 ) {
V_213 = V_387 ;
V_382 = V_181 ;
} else {
V_213 = V_388 ;
}
}
return 0 ;
}
static struct V_38 * F_201 ( struct V_8 * V_20 ,
struct V_367 * V_368 ,
T_7 V_181 , T_2 V_379 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_369 , V_241 ;
struct V_239 * V_240 ;
F_21 ( L_26 , V_20 , V_181 ) ;
if ( ! V_10 )
return F_111 ( - V_361 ) ;
V_241 = V_236 ;
if ( V_379 )
V_241 += V_380 ;
V_369 = F_63 (unsigned int, (conn->mtu - hlen), len) ;
V_42 = V_20 -> V_32 -> V_374 ( V_20 , V_369 + V_241 ,
V_368 -> V_375 & V_376 ) ;
if ( F_117 ( V_42 ) )
return V_42 ;
V_240 = (struct V_239 * ) F_112 ( V_42 , V_236 ) ;
V_240 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_240 -> V_181 = F_16 ( V_181 + ( V_241 - V_236 ) ) ;
if ( V_379 )
F_107 ( V_379 , F_112 ( V_42 , V_380 ) ) ;
V_21 = F_189 ( V_20 , V_368 , V_181 , V_369 , V_42 ) ;
if ( F_195 ( V_21 < 0 ) ) {
F_96 ( V_42 ) ;
return F_111 ( V_21 ) ;
}
return V_42 ;
}
static int F_202 ( struct V_8 * V_20 ,
struct V_39 * V_381 ,
struct V_367 * V_368 , T_7 V_181 )
{
struct V_38 * V_42 ;
T_7 V_382 ;
T_2 V_97 ;
F_21 ( L_27 , V_20 , V_368 , V_181 ) ;
V_382 = V_20 -> V_10 -> V_154 - V_236 ;
V_382 = F_63 ( T_7 , V_382 , V_20 -> V_384 ) ;
V_97 = V_181 ;
V_382 -= V_380 ;
while ( V_181 > 0 ) {
if ( V_181 <= V_382 )
V_382 = V_181 ;
V_42 = F_201 ( V_20 , V_368 , V_382 , V_97 ) ;
if ( F_117 ( V_42 ) ) {
F_199 ( V_381 ) ;
return F_192 ( V_42 ) ;
}
F_200 ( V_381 , V_42 ) ;
V_181 -= V_382 ;
if ( V_97 ) {
V_97 = 0 ;
V_382 += V_380 ;
}
}
return 0 ;
}
int F_203 ( struct V_8 * V_20 , struct V_367 * V_368 , T_7 V_181 ,
T_8 V_188 )
{
struct V_38 * V_42 ;
int V_21 ;
struct V_39 V_381 ;
if ( ! V_20 -> V_10 )
return - V_361 ;
if ( V_20 -> V_107 == V_112 ) {
V_42 = F_193 ( V_20 , V_368 , V_181 , V_188 ) ;
if ( F_117 ( V_42 ) )
return F_192 ( V_42 ) ;
if ( V_20 -> V_31 != V_61 ) {
F_96 ( V_42 ) ;
return - V_361 ;
}
F_95 ( V_20 , V_42 ) ;
return V_181 ;
}
switch ( V_20 -> V_136 ) {
case V_138 :
if ( V_181 > V_20 -> V_110 )
return - V_389 ;
if ( ! V_20 -> V_98 )
return - V_390 ;
F_204 ( & V_381 ) ;
V_21 = F_202 ( V_20 , & V_381 , V_368 , V_181 ) ;
if ( V_20 -> V_31 != V_61 ) {
F_199 ( & V_381 ) ;
V_21 = - V_361 ;
}
if ( V_21 )
return V_21 ;
F_171 ( & V_381 , & V_20 -> V_104 ) ;
while ( V_20 -> V_98 && ! F_172 ( & V_20 -> V_104 ) ) {
F_95 ( V_20 , F_173 ( & V_20 -> V_104 ) ) ;
V_20 -> V_98 -- ;
}
if ( ! V_20 -> V_98 )
V_20 -> V_32 -> V_288 ( V_20 ) ;
V_21 = V_181 ;
break;
case V_137 :
if ( V_181 > V_20 -> V_110 )
return - V_389 ;
V_42 = F_196 ( V_20 , V_368 , V_181 , V_188 ) ;
if ( F_117 ( V_42 ) )
return F_192 ( V_42 ) ;
if ( V_20 -> V_31 != V_61 ) {
F_96 ( V_42 ) ;
return - V_361 ;
}
F_95 ( V_20 , V_42 ) ;
V_21 = V_181 ;
break;
case V_139 :
case V_143 :
if ( V_181 > V_20 -> V_110 ) {
V_21 = - V_389 ;
break;
}
F_204 ( & V_381 ) ;
V_21 = F_198 ( V_20 , & V_381 , V_368 , V_181 ) ;
if ( V_20 -> V_31 != V_61 ) {
F_199 ( & V_381 ) ;
V_21 = - V_361 ;
}
if ( V_21 )
break;
if ( V_20 -> V_136 == V_139 )
F_128 ( V_20 , NULL , & V_381 , V_391 ) ;
else
F_170 ( V_20 , & V_381 ) ;
V_21 = V_181 ;
F_199 ( & V_381 ) ;
break;
default:
F_21 ( L_28 , V_20 -> V_136 ) ;
V_21 = - V_392 ;
}
return V_21 ;
}
static void F_205 ( struct V_8 * V_20 , T_2 V_44 )
{
struct V_198 V_43 ;
T_2 V_41 ;
F_21 ( L_29 , V_20 , V_44 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_206 = 1 ;
V_43 . V_210 = V_249 ;
for ( V_41 = V_20 -> V_273 ; V_41 != V_44 ;
V_41 = F_174 ( V_20 , V_41 ) ) {
if ( ! F_31 ( & V_20 -> V_140 , V_41 ) ) {
V_43 . V_199 = V_41 ;
F_114 ( V_20 , & V_43 ) ;
F_42 ( & V_20 -> V_141 , V_41 ) ;
}
}
V_20 -> V_273 = F_174 ( V_20 , V_44 ) ;
}
static void F_206 ( struct V_8 * V_20 )
{
struct V_198 V_43 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_141 . V_55 == V_54 )
return;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_206 = 1 ;
V_43 . V_210 = V_249 ;
V_43 . V_199 = V_20 -> V_141 . V_55 ;
F_114 ( V_20 , & V_43 ) ;
}
static void F_207 ( struct V_8 * V_20 , T_2 V_44 )
{
struct V_198 V_43 ;
T_2 V_393 ;
T_2 V_41 ;
F_21 ( L_29 , V_20 , V_44 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_206 = 1 ;
V_43 . V_210 = V_249 ;
V_393 = V_20 -> V_141 . V_40 ;
do {
V_41 = F_40 ( & V_20 -> V_141 ) ;
if ( V_41 == V_44 || V_41 == V_54 )
break;
V_43 . V_199 = V_41 ;
F_114 ( V_20 , & V_43 ) ;
F_42 ( & V_20 -> V_141 , V_41 ) ;
} while ( V_20 -> V_141 . V_40 != V_393 );
}
static void F_208 ( struct V_8 * V_20 , T_2 V_199 )
{
struct V_38 * V_394 ;
T_2 V_395 ;
F_21 ( L_30 , V_20 , V_199 ) ;
if ( V_20 -> V_363 == 0 || V_199 == V_20 -> V_396 )
return;
F_21 ( L_31 ,
V_20 -> V_396 , V_20 -> V_363 ) ;
for ( V_395 = V_20 -> V_396 ; V_395 != V_199 ;
V_395 = F_174 ( V_20 , V_395 ) ) {
V_394 = F_31 ( & V_20 -> V_104 , V_395 ) ;
if ( V_394 ) {
F_209 ( V_394 , & V_20 -> V_104 ) ;
F_96 ( V_394 ) ;
V_20 -> V_363 -- ;
}
}
V_20 -> V_396 = V_199 ;
if ( V_20 -> V_363 == 0 )
F_30 ( V_20 ) ;
F_21 ( L_32 , V_20 -> V_363 ) ;
}
static void F_210 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_273 = V_20 -> V_252 ;
F_41 ( & V_20 -> V_141 ) ;
F_74 ( & V_20 -> V_140 ) ;
V_20 -> V_278 = V_366 ;
}
static void F_211 ( struct V_8 * V_20 ,
struct V_198 * V_43 ,
struct V_39 * V_356 , T_3 V_397 )
{
F_21 ( L_33 , V_20 , V_43 , V_356 ,
V_397 ) ;
switch ( V_397 ) {
case V_391 :
if ( V_20 -> V_362 == NULL )
V_20 -> V_362 = F_212 ( V_356 ) ;
F_171 ( V_356 , & V_20 -> V_104 ) ;
F_175 ( V_20 ) ;
break;
case V_398 :
F_21 ( L_34 ) ;
F_54 ( V_251 , & V_20 -> V_245 ) ;
if ( V_20 -> V_278 == V_399 ) {
F_210 ( V_20 ) ;
}
F_186 ( V_20 ) ;
break;
case V_400 :
F_21 ( L_35 ) ;
F_116 ( V_251 , & V_20 -> V_245 ) ;
if ( F_73 ( V_247 , & V_20 -> V_245 ) ) {
struct V_198 V_401 ;
memset ( & V_401 , 0 , sizeof( V_401 ) ) ;
V_401 . V_206 = 1 ;
V_401 . V_210 = V_246 ;
V_401 . V_207 = 1 ;
V_401 . V_199 = V_20 -> V_252 ;
F_114 ( V_20 , & V_401 ) ;
V_20 -> V_271 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_276 = V_402 ;
}
break;
case V_403 :
F_208 ( V_20 , V_43 -> V_199 ) ;
break;
case V_284 :
F_118 ( V_20 , 1 ) ;
V_20 -> V_271 = 1 ;
F_29 ( V_20 ) ;
F_76 ( V_20 ) ;
V_20 -> V_276 = V_402 ;
break;
case V_355 :
F_118 ( V_20 , 1 ) ;
V_20 -> V_271 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_276 = V_402 ;
break;
case V_404 :
break;
default:
break;
}
}
static void F_213 ( struct V_8 * V_20 ,
struct V_198 * V_43 ,
struct V_39 * V_356 , T_3 V_397 )
{
F_21 ( L_33 , V_20 , V_43 , V_356 ,
V_397 ) ;
switch ( V_397 ) {
case V_391 :
if ( V_20 -> V_362 == NULL )
V_20 -> V_362 = F_212 ( V_356 ) ;
F_171 ( V_356 , & V_20 -> V_104 ) ;
break;
case V_398 :
F_21 ( L_34 ) ;
F_54 ( V_251 , & V_20 -> V_245 ) ;
if ( V_20 -> V_278 == V_399 ) {
F_210 ( V_20 ) ;
}
F_186 ( V_20 ) ;
break;
case V_400 :
F_21 ( L_35 ) ;
F_116 ( V_251 , & V_20 -> V_245 ) ;
if ( F_73 ( V_247 , & V_20 -> V_245 ) ) {
struct V_198 V_401 ;
memset ( & V_401 , 0 , sizeof( V_401 ) ) ;
V_401 . V_206 = 1 ;
V_401 . V_210 = V_246 ;
V_401 . V_207 = 1 ;
V_401 . V_199 = V_20 -> V_252 ;
F_114 ( V_20 , & V_401 ) ;
V_20 -> V_271 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_276 = V_402 ;
}
break;
case V_403 :
F_208 ( V_20 , V_43 -> V_199 ) ;
case V_404 :
if ( V_43 && V_43 -> V_202 ) {
F_75 ( V_20 ) ;
if ( V_20 -> V_363 > 0 )
F_25 ( V_20 ) ;
V_20 -> V_271 = 0 ;
V_20 -> V_276 = V_277 ;
F_21 ( L_36 , V_20 -> V_276 ) ;
}
break;
case V_284 :
break;
case V_354 :
if ( V_20 -> V_80 == 0 || V_20 -> V_271 < V_20 -> V_80 ) {
F_118 ( V_20 , 1 ) ;
F_29 ( V_20 ) ;
V_20 -> V_271 ++ ;
} else {
F_83 ( V_20 , V_405 ) ;
}
break;
default:
break;
}
}
static void F_128 ( struct V_8 * V_20 , struct V_198 * V_43 ,
struct V_39 * V_356 , T_3 V_397 )
{
F_21 ( L_37 ,
V_20 , V_43 , V_356 , V_397 , V_20 -> V_276 ) ;
switch ( V_20 -> V_276 ) {
case V_277 :
F_211 ( V_20 , V_43 , V_356 , V_397 ) ;
break;
case V_402 :
F_213 ( V_20 , V_43 , V_356 , V_397 ) ;
break;
default:
break;
}
}
static void F_214 ( struct V_8 * V_20 ,
struct V_198 * V_43 )
{
F_21 ( L_10 , V_20 , V_43 ) ;
F_128 ( V_20 , V_43 , NULL , V_403 ) ;
}
static void F_215 ( struct V_8 * V_20 ,
struct V_198 * V_43 )
{
F_21 ( L_10 , V_20 , V_43 ) ;
F_128 ( V_20 , V_43 , NULL , V_404 ) ;
}
static void F_216 ( struct V_9 * V_10 , struct V_38 * V_42 )
{
struct V_38 * V_406 ;
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( V_20 -> V_107 != V_165 )
continue;
if ( F_33 ( V_42 ) -> V_20 == V_20 )
continue;
V_406 = F_176 ( V_42 , V_51 ) ;
if ( ! V_406 )
continue;
if ( V_20 -> V_32 -> V_407 ( V_20 , V_406 ) )
F_96 ( V_406 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static struct V_38 * F_91 ( struct V_9 * V_10 , T_3 V_180 ,
T_3 V_16 , T_2 V_408 , void * V_182 )
{
struct V_38 * V_42 , * * V_370 ;
struct V_409 * V_410 ;
struct V_239 * V_240 ;
int V_181 , V_369 ;
F_21 ( L_38 ,
V_10 , V_180 , V_16 , V_408 ) ;
if ( V_10 -> V_154 < V_236 + V_411 )
return NULL ;
V_181 = V_236 + V_411 + V_408 ;
V_369 = F_63 (unsigned int, conn->mtu, len) ;
V_42 = F_110 ( V_369 , V_51 ) ;
if ( ! V_42 )
return NULL ;
V_240 = (struct V_239 * ) F_112 ( V_42 , V_236 ) ;
V_240 -> V_181 = F_16 ( V_411 + V_408 ) ;
if ( V_10 -> V_2 -> type == V_3 )
V_240 -> V_11 = F_16 ( V_412 ) ;
else
V_240 -> V_11 = F_16 ( V_115 ) ;
V_410 = (struct V_409 * ) F_112 ( V_42 , V_411 ) ;
V_410 -> V_180 = V_180 ;
V_410 -> V_16 = V_16 ;
V_410 -> V_181 = F_16 ( V_408 ) ;
if ( V_408 ) {
V_369 -= V_236 + V_411 ;
memcpy ( F_112 ( V_42 , V_369 ) , V_182 , V_369 ) ;
V_182 += V_369 ;
}
V_181 -= V_42 -> V_181 ;
V_370 = & F_191 ( V_42 ) -> V_373 ;
while ( V_181 ) {
V_369 = F_63 (unsigned int, conn->mtu, len) ;
* V_370 = F_110 ( V_369 , V_51 ) ;
if ( ! * V_370 )
goto V_413;
memcpy ( F_112 ( * V_370 , V_369 ) , V_182 , V_369 ) ;
V_181 -= V_369 ;
V_182 += V_369 ;
V_370 = & ( * V_370 ) -> V_341 ;
}
return V_42 ;
V_413:
F_96 ( V_42 ) ;
return NULL ;
}
static inline int F_217 ( void * * V_414 , int * type , int * V_415 ,
unsigned long * V_416 )
{
struct V_417 * V_418 = * V_414 ;
int V_181 ;
V_181 = V_419 + V_418 -> V_181 ;
* V_414 += V_181 ;
* type = V_418 -> type ;
* V_415 = V_418 -> V_181 ;
switch ( V_418 -> V_181 ) {
case 1 :
* V_416 = * ( ( T_3 * ) V_418 -> V_416 ) ;
break;
case 2 :
* V_416 = F_102 ( V_418 -> V_416 ) ;
break;
case 4 :
* V_416 = F_100 ( V_418 -> V_416 ) ;
break;
default:
* V_416 = ( unsigned long ) V_418 -> V_416 ;
break;
}
F_21 ( L_39 , * type , V_418 -> V_181 , * V_416 ) ;
return V_181 ;
}
static void F_218 ( void * * V_414 , T_3 type , T_3 V_181 , unsigned long V_416 )
{
struct V_417 * V_418 = * V_414 ;
F_21 ( L_39 , type , V_181 , V_416 ) ;
V_418 -> type = type ;
V_418 -> V_181 = V_181 ;
switch ( V_181 ) {
case 1 :
* ( ( T_3 * ) V_418 -> V_416 ) = V_416 ;
break;
case 2 :
F_107 ( V_416 , V_418 -> V_416 ) ;
break;
case 4 :
F_106 ( V_416 , V_418 -> V_416 ) ;
break;
default:
memcpy ( V_418 -> V_416 , ( void * ) V_416 , V_181 ) ;
break;
}
* V_414 += V_419 + V_181 ;
}
static void F_219 ( void * * V_414 , struct V_8 * V_20 )
{
struct V_420 V_421 ;
switch ( V_20 -> V_136 ) {
case V_139 :
V_421 . V_178 = V_20 -> V_116 ;
V_421 . V_422 = V_20 -> V_118 ;
V_421 . V_423 = F_16 ( V_20 -> V_120 ) ;
V_421 . V_424 = F_220 ( V_20 -> V_122 ) ;
V_421 . V_425 = F_220 ( V_125 ) ;
V_421 . V_89 = F_220 ( V_127 ) ;
break;
case V_143 :
V_421 . V_178 = 1 ;
V_421 . V_422 = V_119 ;
V_421 . V_423 = F_16 ( V_20 -> V_120 ) ;
V_421 . V_424 = F_220 ( V_20 -> V_122 ) ;
V_421 . V_425 = 0 ;
V_421 . V_89 = 0 ;
break;
default:
return;
}
F_218 ( V_414 , V_426 , sizeof( V_421 ) ,
( unsigned long ) & V_421 ) ;
}
static void F_221 ( struct V_57 * V_58 )
{
struct V_8 * V_20 = F_44 ( V_58 , struct V_8 ,
V_427 . V_58 ) ;
T_2 V_364 ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
V_364 = F_187 ( V_20 , V_20 -> V_252 ,
V_20 -> V_250 ) ;
if ( V_364 )
F_118 ( V_20 , 0 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
int F_222 ( struct V_8 * V_20 )
{
int V_21 ;
V_20 -> V_357 = 0 ;
V_20 -> V_273 = 0 ;
V_20 -> V_396 = 0 ;
V_20 -> V_363 = 0 ;
V_20 -> V_252 = 0 ;
V_20 -> V_358 = 0 ;
V_20 -> V_250 = 0 ;
V_20 -> V_95 = NULL ;
V_20 -> V_96 = NULL ;
V_20 -> V_97 = 0 ;
F_64 ( & V_20 -> V_104 ) ;
V_20 -> V_428 = V_429 ;
V_20 -> V_430 = V_429 ;
V_20 -> V_191 = V_192 ;
V_20 -> V_281 = V_282 ;
if ( V_20 -> V_136 != V_139 )
return 0 ;
V_20 -> V_278 = V_366 ;
V_20 -> V_276 = V_277 ;
F_52 ( & V_20 -> V_36 , F_169 ) ;
F_52 ( & V_20 -> V_34 , F_168 ) ;
F_52 ( & V_20 -> V_427 , F_221 ) ;
F_64 ( & V_20 -> V_140 ) ;
V_21 = F_34 ( & V_20 -> V_141 , V_20 -> V_82 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_34 ( & V_20 -> V_142 , V_20 -> V_86 ) ;
if ( V_21 < 0 )
F_37 ( & V_20 -> V_141 ) ;
return V_21 ;
}
static inline T_1 F_223 ( T_1 V_136 , T_6 V_431 )
{
switch ( V_136 ) {
case V_143 :
case V_139 :
if ( F_137 ( V_136 , V_431 ) )
return V_136 ;
default:
return V_137 ;
}
}
static inline bool F_224 ( struct V_9 * V_10 )
{
return V_10 -> V_256 && V_10 -> V_302 & V_432 ;
}
static inline bool F_225 ( struct V_9 * V_10 )
{
return V_10 -> V_256 && V_10 -> V_302 & V_433 ;
}
static void F_226 ( struct V_8 * V_20 ,
struct V_434 * V_435 )
{
if ( V_20 -> V_428 != V_429 && V_20 -> V_194 ) {
T_10 V_436 = V_20 -> V_194 -> V_183 -> V_437 ;
V_436 = F_227 ( V_436 , 1000 ) ;
V_436 = 3 * V_436 + 500 ;
if ( V_436 > 0xffff )
V_436 = 0xffff ;
V_435 -> V_35 = F_16 ( ( T_2 ) V_436 ) ;
V_435 -> V_37 = V_435 -> V_35 ;
} else {
V_435 -> V_35 = F_16 ( V_91 ) ;
V_435 -> V_37 = F_16 ( V_92 ) ;
}
}
static inline void F_228 ( struct V_8 * V_20 )
{
if ( V_20 -> V_82 > V_83 &&
F_224 ( V_20 -> V_10 ) ) {
F_54 ( V_232 , & V_20 -> V_94 ) ;
V_20 -> V_84 = V_438 ;
} else {
V_20 -> V_82 = F_63 ( T_2 , V_20 -> V_82 ,
V_83 ) ;
V_20 -> V_84 = V_83 ;
}
V_20 -> V_87 = V_20 -> V_82 ;
}
static int F_140 ( struct V_8 * V_20 , void * V_182 )
{
struct V_439 * V_266 = V_182 ;
struct V_434 V_435 = { . V_136 = V_20 -> V_136 } ;
void * V_414 = V_266 -> V_182 ;
T_2 V_47 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_321 || V_20 -> V_440 )
goto V_24;
switch ( V_20 -> V_136 ) {
case V_143 :
case V_139 :
if ( F_73 ( V_311 , & V_20 -> V_76 ) )
break;
if ( F_225 ( V_20 -> V_10 ) )
F_54 ( V_441 , & V_20 -> V_94 ) ;
default:
V_20 -> V_136 = F_223 ( V_435 . V_136 , V_20 -> V_10 -> V_302 ) ;
break;
}
V_24:
if ( V_20 -> V_102 != V_111 )
F_218 ( & V_414 , V_442 , 2 , V_20 -> V_102 ) ;
switch ( V_20 -> V_136 ) {
case V_137 :
if ( ! ( V_20 -> V_10 -> V_302 & V_306 ) &&
! ( V_20 -> V_10 -> V_302 & V_307 ) )
break;
V_435 . V_136 = V_137 ;
V_435 . V_443 = 0 ;
V_435 . V_444 = 0 ;
V_435 . V_35 = 0 ;
V_435 . V_37 = 0 ;
V_435 . V_445 = 0 ;
F_218 ( & V_414 , V_446 , sizeof( V_435 ) ,
( unsigned long ) & V_435 ) ;
break;
case V_139 :
V_435 . V_136 = V_139 ;
V_435 . V_444 = V_20 -> V_80 ;
F_226 ( V_20 , & V_435 ) ;
V_47 = F_63 ( T_2 , V_447 , V_20 -> V_10 -> V_154 -
V_237 - V_380 -
V_242 ) ;
V_435 . V_445 = F_16 ( V_47 ) ;
F_228 ( V_20 ) ;
V_435 . V_443 = F_63 ( T_2 , V_20 -> V_82 ,
V_83 ) ;
F_218 ( & V_414 , V_446 , sizeof( V_435 ) ,
( unsigned long ) & V_435 ) ;
if ( F_73 ( V_441 , & V_20 -> V_94 ) )
F_219 ( & V_414 , V_20 ) ;
if ( F_73 ( V_232 , & V_20 -> V_94 ) )
F_218 ( & V_414 , V_448 , 2 ,
V_20 -> V_82 ) ;
if ( V_20 -> V_10 -> V_302 & V_449 )
if ( V_20 -> V_78 == V_450 ||
F_73 ( V_451 , & V_20 -> V_76 ) ) {
V_20 -> V_78 = V_450 ;
F_218 ( & V_414 , V_452 , 1 ,
V_20 -> V_78 ) ;
}
break;
case V_143 :
F_228 ( V_20 ) ;
V_435 . V_136 = V_143 ;
V_435 . V_443 = 0 ;
V_435 . V_444 = 0 ;
V_435 . V_35 = 0 ;
V_435 . V_37 = 0 ;
V_47 = F_63 ( T_2 , V_447 , V_20 -> V_10 -> V_154 -
V_237 - V_380 -
V_242 ) ;
V_435 . V_445 = F_16 ( V_47 ) ;
F_218 ( & V_414 , V_446 , sizeof( V_435 ) ,
( unsigned long ) & V_435 ) ;
if ( F_73 ( V_441 , & V_20 -> V_94 ) )
F_219 ( & V_414 , V_20 ) ;
if ( V_20 -> V_10 -> V_302 & V_449 )
if ( V_20 -> V_78 == V_450 ||
F_73 ( V_451 , & V_20 -> V_76 ) ) {
V_20 -> V_78 = V_450 ;
F_218 ( & V_414 , V_452 , 1 ,
V_20 -> V_78 ) ;
}
break;
}
V_266 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_266 -> V_94 = F_16 ( 0 ) ;
return V_414 - V_182 ;
}
static int F_229 ( struct V_8 * V_20 , void * V_182 )
{
struct V_453 * V_148 = V_182 ;
void * V_414 = V_148 -> V_182 ;
void * V_266 = V_20 -> V_454 ;
int V_181 = V_20 -> V_455 ;
int type , V_456 , V_415 ;
unsigned long V_416 ;
struct V_434 V_435 = { . V_136 = V_137 } ;
struct V_420 V_421 ;
T_3 V_457 = 0 ;
T_2 V_154 = V_111 ;
T_2 V_149 = V_458 ;
T_2 V_47 ;
F_21 ( L_3 , V_20 ) ;
while ( V_181 >= V_419 ) {
V_181 -= F_217 ( & V_266 , & type , & V_415 , & V_416 ) ;
V_456 = type & V_459 ;
type &= V_460 ;
switch ( type ) {
case V_442 :
V_154 = V_416 ;
break;
case V_461 :
V_20 -> V_89 = V_416 ;
break;
case V_462 :
break;
case V_446 :
if ( V_415 == sizeof( V_435 ) )
memcpy ( & V_435 , ( void * ) V_416 , V_415 ) ;
break;
case V_452 :
if ( V_416 == V_450 )
F_54 ( V_451 , & V_20 -> V_76 ) ;
break;
case V_426 :
V_457 = 1 ;
if ( V_415 == sizeof( V_421 ) )
memcpy ( & V_421 , ( void * ) V_416 , V_415 ) ;
break;
case V_448 :
if ( ! V_20 -> V_10 -> V_256 )
return - V_63 ;
F_54 ( V_232 , & V_20 -> V_94 ) ;
F_54 ( V_463 , & V_20 -> V_76 ) ;
V_20 -> V_84 = V_438 ;
V_20 -> V_86 = V_416 ;
break;
default:
if ( V_456 )
break;
V_149 = V_464 ;
* ( ( T_3 * ) V_414 ++ ) = type ;
break;
}
}
if ( V_20 -> V_440 || V_20 -> V_321 > 1 )
goto V_24;
switch ( V_20 -> V_136 ) {
case V_143 :
case V_139 :
if ( ! F_73 ( V_311 , & V_20 -> V_76 ) ) {
V_20 -> V_136 = F_223 ( V_435 . V_136 ,
V_20 -> V_10 -> V_302 ) ;
break;
}
if ( V_457 ) {
if ( F_225 ( V_20 -> V_10 ) )
F_54 ( V_441 , & V_20 -> V_94 ) ;
else
return - V_63 ;
}
if ( V_20 -> V_136 != V_435 . V_136 )
return - V_63 ;
break;
}
V_24:
if ( V_20 -> V_136 != V_435 . V_136 ) {
V_149 = V_465 ;
V_435 . V_136 = V_20 -> V_136 ;
if ( V_20 -> V_440 == 1 )
return - V_63 ;
F_218 ( & V_414 , V_446 , sizeof( V_435 ) ,
( unsigned long ) & V_435 ) ;
}
if ( V_149 == V_458 ) {
if ( V_154 < V_466 )
V_149 = V_465 ;
else {
V_20 -> V_110 = V_154 ;
F_54 ( V_467 , & V_20 -> V_76 ) ;
}
F_218 ( & V_414 , V_442 , 2 , V_20 -> V_110 ) ;
if ( V_457 ) {
if ( V_20 -> V_118 != V_468 &&
V_421 . V_422 != V_468 &&
V_421 . V_422 != V_20 -> V_118 ) {
V_149 = V_465 ;
if ( V_20 -> V_321 >= 1 )
return - V_63 ;
F_218 ( & V_414 , V_426 ,
sizeof( V_421 ) ,
( unsigned long ) & V_421 ) ;
} else {
V_149 = V_469 ;
F_54 ( V_470 , & V_20 -> V_76 ) ;
}
}
switch ( V_435 . V_136 ) {
case V_137 :
V_20 -> V_78 = V_450 ;
F_54 ( V_471 , & V_20 -> V_76 ) ;
break;
case V_139 :
if ( ! F_73 ( V_463 , & V_20 -> V_76 ) )
V_20 -> V_86 = V_435 . V_443 ;
else
V_435 . V_443 = V_83 ;
V_20 -> V_85 = V_435 . V_444 ;
V_47 = F_63 ( T_2 , F_230 ( V_435 . V_445 ) ,
V_20 -> V_10 -> V_154 - V_237 -
V_380 - V_242 ) ;
V_435 . V_445 = F_16 ( V_47 ) ;
V_20 -> V_384 = V_47 ;
F_226 ( V_20 , & V_435 ) ;
F_54 ( V_471 , & V_20 -> V_76 ) ;
F_218 ( & V_414 , V_446 ,
sizeof( V_435 ) , ( unsigned long ) & V_435 ) ;
if ( F_73 ( V_441 , & V_20 -> V_94 ) ) {
V_20 -> V_472 = V_421 . V_178 ;
V_20 -> V_473 = V_421 . V_422 ;
V_20 -> V_474 = F_230 ( V_421 . V_423 ) ;
V_20 -> V_475 =
F_231 ( V_421 . V_89 ) ;
V_20 -> V_476 =
F_231 ( V_421 . V_425 ) ;
V_20 -> V_477 =
F_231 ( V_421 . V_424 ) ;
F_218 ( & V_414 , V_426 ,
sizeof( V_421 ) ,
( unsigned long ) & V_421 ) ;
}
break;
case V_143 :
V_47 = F_63 ( T_2 , F_230 ( V_435 . V_445 ) ,
V_20 -> V_10 -> V_154 - V_237 -
V_380 - V_242 ) ;
V_435 . V_445 = F_16 ( V_47 ) ;
V_20 -> V_384 = V_47 ;
F_54 ( V_471 , & V_20 -> V_76 ) ;
F_218 ( & V_414 , V_446 , sizeof( V_435 ) ,
( unsigned long ) & V_435 ) ;
break;
default:
V_149 = V_465 ;
memset ( & V_435 , 0 , sizeof( V_435 ) ) ;
V_435 . V_136 = V_20 -> V_136 ;
}
if ( V_149 == V_458 )
F_54 ( V_478 , & V_20 -> V_76 ) ;
}
V_148 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 -> V_149 = F_16 ( V_149 ) ;
V_148 -> V_94 = F_16 ( 0 ) ;
return V_414 - V_182 ;
}
static int F_232 ( struct V_8 * V_20 , void * V_148 , int V_181 ,
void * V_182 , T_2 * V_149 )
{
struct V_439 * V_266 = V_182 ;
void * V_414 = V_266 -> V_182 ;
int type , V_415 ;
unsigned long V_416 ;
struct V_434 V_435 = { . V_136 = V_137 } ;
struct V_420 V_421 ;
F_21 ( L_40 , V_20 , V_148 , V_181 , V_182 ) ;
while ( V_181 >= V_419 ) {
V_181 -= F_217 ( & V_148 , & type , & V_415 , & V_416 ) ;
switch ( type ) {
case V_442 :
if ( V_416 < V_466 ) {
* V_149 = V_465 ;
V_20 -> V_102 = V_466 ;
} else
V_20 -> V_102 = V_416 ;
F_218 ( & V_414 , V_442 , 2 , V_20 -> V_102 ) ;
break;
case V_461 :
V_20 -> V_89 = V_416 ;
F_218 ( & V_414 , V_461 ,
2 , V_20 -> V_89 ) ;
break;
case V_446 :
if ( V_415 == sizeof( V_435 ) )
memcpy ( & V_435 , ( void * ) V_416 , V_415 ) ;
if ( F_73 ( V_311 , & V_20 -> V_76 ) &&
V_435 . V_136 != V_20 -> V_136 )
return - V_63 ;
V_20 -> V_78 = 0 ;
F_218 ( & V_414 , V_446 ,
sizeof( V_435 ) , ( unsigned long ) & V_435 ) ;
break;
case V_448 :
V_20 -> V_87 = F_63 ( T_2 , V_416 , V_20 -> V_87 ) ;
F_218 ( & V_414 , V_448 , 2 ,
V_20 -> V_82 ) ;
break;
case V_426 :
if ( V_415 == sizeof( V_421 ) )
memcpy ( & V_421 , ( void * ) V_416 , V_415 ) ;
if ( V_20 -> V_118 != V_468 &&
V_421 . V_422 != V_468 &&
V_421 . V_422 != V_20 -> V_118 )
return - V_63 ;
F_218 ( & V_414 , V_426 , sizeof( V_421 ) ,
( unsigned long ) & V_421 ) ;
break;
case V_452 :
if ( * V_149 == V_469 )
if ( V_416 == V_450 )
F_54 ( V_451 ,
& V_20 -> V_76 ) ;
break;
}
}
if ( V_20 -> V_136 == V_137 && V_20 -> V_136 != V_435 . V_136 )
return - V_63 ;
V_20 -> V_136 = V_435 . V_136 ;
if ( * V_149 == V_458 || * V_149 == V_469 ) {
switch ( V_435 . V_136 ) {
case V_139 :
V_20 -> V_35 = F_230 ( V_435 . V_35 ) ;
V_20 -> V_37 = F_230 ( V_435 . V_37 ) ;
V_20 -> V_101 = F_230 ( V_435 . V_445 ) ;
if ( ! F_73 ( V_232 , & V_20 -> V_94 ) )
V_20 -> V_87 = F_63 ( T_2 , V_20 -> V_87 ,
V_435 . V_443 ) ;
if ( F_73 ( V_441 , & V_20 -> V_94 ) ) {
V_20 -> V_120 = F_230 ( V_421 . V_423 ) ;
V_20 -> V_122 =
F_231 ( V_421 . V_424 ) ;
V_20 -> V_124 = F_231 ( V_421 . V_425 ) ;
V_20 -> V_126 =
F_231 ( V_421 . V_89 ) ;
}
break;
case V_143 :
V_20 -> V_101 = F_230 ( V_435 . V_445 ) ;
}
}
V_266 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_266 -> V_94 = F_16 ( 0 ) ;
return V_414 - V_182 ;
}
static int F_233 ( struct V_8 * V_20 , void * V_182 ,
T_2 V_149 , T_2 V_94 )
{
struct V_453 * V_148 = V_182 ;
void * V_414 = V_148 -> V_182 ;
F_21 ( L_3 , V_20 ) ;
V_148 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 -> V_149 = F_16 ( V_149 ) ;
V_148 -> V_94 = F_16 ( V_94 ) ;
return V_414 - V_182 ;
}
void F_234 ( struct V_8 * V_20 )
{
struct V_147 V_148 ;
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_3 , V_20 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_154 = F_16 ( V_20 -> V_102 ) ;
V_148 . V_101 = F_16 ( V_20 -> V_101 ) ;
V_148 . V_155 = F_16 ( V_20 -> V_99 ) ;
V_148 . V_149 = F_16 ( V_317 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_156 , sizeof( V_148 ) ,
& V_148 ) ;
}
void F_235 ( struct V_8 * V_20 )
{
struct V_157 V_148 ;
struct V_9 * V_10 = V_20 -> V_10 ;
T_3 V_313 [ 128 ] ;
T_3 V_479 ;
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_149 = F_16 ( V_317 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
if ( V_20 -> V_194 )
V_479 = V_480 ;
else
V_479 = V_161 ;
F_21 ( L_41 , V_20 , V_479 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_479 , sizeof( V_148 ) , & V_148 ) ;
if ( F_131 ( V_319 , & V_20 -> V_76 ) )
return;
F_80 ( V_10 , F_88 ( V_10 ) , V_320 ,
F_140 ( V_20 , V_313 ) , V_313 ) ;
V_20 -> V_321 ++ ;
}
static void F_236 ( struct V_8 * V_20 , void * V_148 , int V_181 )
{
int type , V_415 ;
unsigned long V_416 ;
T_2 V_481 = V_20 -> V_87 ;
struct V_434 V_435 = {
. V_136 = V_20 -> V_136 ,
. V_35 = F_16 ( V_91 ) ,
. V_37 = F_16 ( V_92 ) ,
. V_445 = F_16 ( V_20 -> V_102 ) ,
. V_443 = F_63 ( T_2 , V_20 -> V_87 , V_83 ) ,
} ;
F_21 ( L_42 , V_20 , V_148 , V_181 ) ;
if ( ( V_20 -> V_136 != V_139 ) && ( V_20 -> V_136 != V_143 ) )
return;
while ( V_181 >= V_419 ) {
V_181 -= F_217 ( & V_148 , & type , & V_415 , & V_416 ) ;
switch ( type ) {
case V_446 :
if ( V_415 == sizeof( V_435 ) )
memcpy ( & V_435 , ( void * ) V_416 , V_415 ) ;
break;
case V_448 :
V_481 = V_416 ;
break;
}
}
switch ( V_435 . V_136 ) {
case V_139 :
V_20 -> V_35 = F_230 ( V_435 . V_35 ) ;
V_20 -> V_37 = F_230 ( V_435 . V_37 ) ;
V_20 -> V_101 = F_230 ( V_435 . V_445 ) ;
if ( F_73 ( V_232 , & V_20 -> V_94 ) )
V_20 -> V_87 = F_63 ( T_2 , V_20 -> V_87 , V_481 ) ;
else
V_20 -> V_87 = F_63 ( T_2 , V_20 -> V_87 ,
V_435 . V_443 ) ;
break;
case V_143 :
V_20 -> V_101 = F_230 ( V_435 . V_445 ) ;
}
}
static inline int F_237 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
struct V_483 * V_484 = (struct V_483 * ) V_182 ;
if ( V_482 < sizeof( * V_484 ) )
return - V_485 ;
if ( V_484 -> V_60 != V_486 )
return 0 ;
if ( ( V_10 -> V_293 & V_294 ) &&
V_410 -> V_16 == V_10 -> V_298 ) {
F_238 ( & V_10 -> V_299 ) ;
V_10 -> V_293 |= V_295 ;
V_10 -> V_298 = 0 ;
F_138 ( V_10 ) ;
}
return 0 ;
}
static struct V_8 * F_239 ( struct V_9 * V_10 ,
struct V_409 * V_410 ,
T_3 * V_182 , T_3 V_479 , T_3 V_268 )
{
struct V_265 * V_266 = (struct V_265 * ) V_182 ;
struct V_157 V_148 ;
struct V_8 * V_20 = NULL , * V_328 ;
int V_149 , V_159 = V_160 ;
T_2 V_13 = 0 , V_14 = F_66 ( V_266 -> V_14 ) ;
T_4 V_17 = V_266 -> V_17 ;
F_21 ( L_43 , F_66 ( V_17 ) , V_14 ) ;
V_328 = F_167 ( V_162 , V_17 , & V_10 -> V_2 -> V_18 ,
& V_10 -> V_2 -> V_145 , V_109 ) ;
if ( ! V_328 ) {
V_149 = V_152 ;
goto V_487;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_328 ) ;
if ( V_17 != F_16 ( V_174 ) &&
! F_240 ( V_10 -> V_2 ) ) {
V_10 -> V_105 = V_488 ;
V_149 = V_158 ;
goto V_489;
}
V_149 = V_490 ;
if ( F_2 ( V_10 , V_14 ) )
goto V_489;
V_20 = V_328 -> V_32 -> V_330 ( V_328 ) ;
if ( ! V_20 )
goto V_489;
V_10 -> V_2 -> V_491 = V_492 ;
F_78 ( & V_20 -> V_18 , & V_10 -> V_2 -> V_18 ) ;
F_78 ( & V_20 -> V_145 , & V_10 -> V_2 -> V_145 ) ;
V_20 -> V_332 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_332 ) ;
V_20 -> V_146 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_146 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_14 ;
V_20 -> V_428 = V_268 ;
F_65 ( V_10 , V_20 ) ;
V_13 = V_20 -> V_14 ;
F_82 ( V_20 , V_20 -> V_32 -> V_163 ( V_20 ) ) ;
V_20 -> V_16 = V_410 -> V_16 ;
if ( V_10 -> V_293 & V_295 ) {
if ( F_85 ( V_20 ) ) {
if ( F_73 ( V_150 , & V_20 -> V_94 ) ) {
F_20 ( V_20 , V_164 ) ;
V_149 = V_314 ;
V_159 = V_315 ;
V_20 -> V_32 -> V_316 ( V_20 ) ;
} else {
if ( V_268 == V_429 ) {
F_20 ( V_20 , V_62 ) ;
V_149 = V_317 ;
} else {
F_20 ( V_20 , V_164 ) ;
V_149 = V_314 ;
}
V_159 = V_160 ;
}
} else {
F_20 ( V_20 , V_164 ) ;
V_149 = V_314 ;
V_159 = V_318 ;
}
} else {
F_20 ( V_20 , V_164 ) ;
V_149 = V_314 ;
V_159 = V_160 ;
}
V_489:
F_46 ( V_328 ) ;
F_8 ( & V_10 -> V_15 ) ;
V_487:
V_148 . V_14 = F_16 ( V_14 ) ;
V_148 . V_13 = F_16 ( V_13 ) ;
V_148 . V_149 = F_16 ( V_149 ) ;
V_148 . V_159 = F_16 ( V_159 ) ;
F_80 ( V_10 , V_410 -> V_16 , V_479 , sizeof( V_148 ) , & V_148 ) ;
if ( V_149 == V_314 && V_159 == V_160 ) {
struct V_296 V_493 ;
V_493 . type = F_16 ( V_297 ) ;
V_10 -> V_293 |= V_294 ;
V_10 -> V_298 = F_88 ( V_10 ) ;
F_136 ( & V_10 -> V_299 , V_300 ) ;
F_80 ( V_10 , V_10 -> V_298 , V_301 ,
sizeof( V_493 ) , & V_493 ) ;
}
if ( V_20 && ! F_73 ( V_319 , & V_20 -> V_76 ) &&
V_149 == V_317 ) {
T_3 V_313 [ 128 ] ;
F_54 ( V_319 , & V_20 -> V_76 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_320 ,
F_140 ( V_20 , V_313 ) , V_313 ) ;
V_20 -> V_321 ++ ;
}
return V_20 ;
}
static int F_241 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 , T_3 * V_182 )
{
struct V_254 * V_183 = V_10 -> V_2 -> V_183 ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_482 < sizeof( struct V_265 ) )
return - V_485 ;
F_150 ( V_183 ) ;
if ( F_73 ( V_494 , & V_183 -> V_495 ) &&
! F_131 ( V_496 , & V_2 -> V_94 ) )
F_242 ( V_183 , & V_2 -> V_145 , V_2 -> type ,
V_2 -> V_146 , 0 , NULL , 0 ,
V_2 -> V_497 ) ;
F_151 ( V_183 ) ;
F_239 ( V_10 , V_410 , V_182 , V_161 , 0 ) ;
return 0 ;
}
static int F_243 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
struct V_157 * V_148 = (struct V_157 * ) V_182 ;
T_2 V_14 , V_13 , V_149 , V_159 ;
struct V_8 * V_20 ;
T_3 V_266 [ 128 ] ;
int V_21 ;
if ( V_482 < sizeof( * V_148 ) )
return - V_485 ;
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
V_21 = - V_498 ;
goto V_499;
}
} else {
V_20 = F_10 ( V_10 , V_410 -> V_16 ) ;
if ( ! V_20 ) {
V_21 = - V_498 ;
goto V_499;
}
}
V_21 = 0 ;
F_7 ( V_20 ) ;
switch ( V_149 ) {
case V_317 :
F_20 ( V_20 , V_62 ) ;
V_20 -> V_16 = 0 ;
V_20 -> V_13 = V_13 ;
F_116 ( V_253 , & V_20 -> V_76 ) ;
if ( F_131 ( V_319 , & V_20 -> V_76 ) )
break;
F_80 ( V_10 , F_88 ( V_10 ) , V_320 ,
F_140 ( V_20 , V_266 ) , V_266 ) ;
V_20 -> V_321 ++ ;
break;
case V_314 :
F_54 ( V_253 , & V_20 -> V_76 ) ;
break;
default:
F_69 ( V_20 , V_63 ) ;
break;
}
F_46 ( V_20 ) ;
V_499:
F_8 ( & V_10 -> V_15 ) ;
return V_21 ;
}
static inline void F_244 ( struct V_8 * V_20 )
{
if ( V_20 -> V_136 != V_139 && V_20 -> V_136 != V_143 )
V_20 -> V_78 = V_450 ;
else if ( ! F_73 ( V_451 , & V_20 -> V_76 ) )
V_20 -> V_78 = V_79 ;
}
static void F_245 ( struct V_8 * V_20 , void * V_182 ,
T_3 V_16 , T_2 V_94 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_45 , V_10 , V_20 , V_16 ,
V_94 ) ;
F_116 ( V_470 , & V_20 -> V_76 ) ;
F_54 ( V_478 , & V_20 -> V_76 ) ;
F_80 ( V_10 , V_16 , V_500 ,
F_233 ( V_20 , V_182 ,
V_458 , V_94 ) , V_182 ) ;
}
static void F_246 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_14 , T_2 V_13 )
{
struct V_501 V_484 ;
V_484 . V_60 = F_16 ( V_502 ) ;
V_484 . V_14 = F_247 ( V_14 ) ;
V_484 . V_13 = F_247 ( V_13 ) ;
F_80 ( V_10 , V_16 , V_503 , sizeof( V_484 ) , & V_484 ) ;
}
static inline int F_248 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
struct V_439 * V_266 = (struct V_439 * ) V_182 ;
T_2 V_13 , V_94 ;
T_3 V_148 [ 64 ] ;
struct V_8 * V_20 ;
int V_181 , V_21 = 0 ;
if ( V_482 < sizeof( * V_266 ) )
return - V_485 ;
V_13 = F_66 ( V_266 -> V_13 ) ;
V_94 = F_66 ( V_266 -> V_94 ) ;
F_21 ( L_46 , V_13 , V_94 ) ;
V_20 = F_5 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_246 ( V_10 , V_410 -> V_16 , V_13 , 0 ) ;
return 0 ;
}
if ( V_20 -> V_31 != V_62 && V_20 -> V_31 != V_164 ) {
F_246 ( V_10 , V_410 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
goto V_499;
}
V_181 = V_482 - sizeof( * V_266 ) ;
if ( V_20 -> V_455 + V_181 > sizeof( V_20 -> V_454 ) ) {
F_80 ( V_10 , V_410 -> V_16 , V_500 ,
F_233 ( V_20 , V_148 ,
V_504 , V_94 ) , V_148 ) ;
goto V_499;
}
memcpy ( V_20 -> V_454 + V_20 -> V_455 , V_266 -> V_182 , V_181 ) ;
V_20 -> V_455 += V_181 ;
if ( V_94 & V_505 ) {
F_80 ( V_10 , V_410 -> V_16 , V_500 ,
F_233 ( V_20 , V_148 ,
V_458 , V_94 ) , V_148 ) ;
goto V_499;
}
V_181 = F_229 ( V_20 , V_148 ) ;
if ( V_181 < 0 ) {
F_83 ( V_20 , V_312 ) ;
goto V_499;
}
V_20 -> V_16 = V_410 -> V_16 ;
F_80 ( V_10 , V_410 -> V_16 , V_500 , V_181 , V_148 ) ;
V_20 -> V_440 ++ ;
V_20 -> V_455 = 0 ;
if ( ! F_73 ( V_478 , & V_20 -> V_76 ) )
goto V_499;
if ( F_73 ( V_506 , & V_20 -> V_76 ) ) {
F_244 ( V_20 ) ;
if ( V_20 -> V_136 == V_139 ||
V_20 -> V_136 == V_143 )
V_21 = F_222 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_129 ( V_20 ) ;
goto V_499;
}
if ( ! F_131 ( V_319 , & V_20 -> V_76 ) ) {
T_3 V_313 [ 64 ] ;
F_80 ( V_10 , F_88 ( V_10 ) , V_320 ,
F_140 ( V_20 , V_313 ) , V_313 ) ;
V_20 -> V_321 ++ ;
}
if ( F_73 ( V_507 , & V_20 -> V_76 ) &&
F_73 ( V_470 , & V_20 -> V_76 ) ) {
if ( ! V_20 -> V_194 )
F_245 ( V_20 , V_148 , V_410 -> V_16 , V_94 ) ;
else
V_20 -> V_16 = V_410 -> V_16 ;
}
V_499:
F_46 ( V_20 ) ;
return V_21 ;
}
static inline int F_249 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
struct V_453 * V_148 = (struct V_453 * ) V_182 ;
T_2 V_14 , V_94 , V_149 ;
struct V_8 * V_20 ;
int V_181 = V_482 - sizeof( * V_148 ) ;
int V_21 = 0 ;
if ( V_482 < sizeof( * V_148 ) )
return - V_485 ;
V_14 = F_66 ( V_148 -> V_14 ) ;
V_94 = F_66 ( V_148 -> V_94 ) ;
V_149 = F_66 ( V_148 -> V_149 ) ;
F_21 ( L_47 , V_14 , V_94 ,
V_149 , V_181 ) ;
V_20 = F_5 ( V_10 , V_14 ) ;
if ( ! V_20 )
return 0 ;
switch ( V_149 ) {
case V_458 :
F_236 ( V_20 , V_148 -> V_182 , V_181 ) ;
F_116 ( V_507 , & V_20 -> V_76 ) ;
break;
case V_469 :
F_54 ( V_507 , & V_20 -> V_76 ) ;
if ( F_73 ( V_470 , & V_20 -> V_76 ) ) {
char V_313 [ 64 ] ;
V_181 = F_232 ( V_20 , V_148 -> V_182 , V_181 ,
V_313 , & V_149 ) ;
if ( V_181 < 0 ) {
F_83 ( V_20 , V_312 ) ;
goto V_24;
}
if ( ! V_20 -> V_194 ) {
F_245 ( V_20 , V_313 , V_410 -> V_16 ,
0 ) ;
} else {
if ( F_123 ( V_20 ) ) {
F_250 ( V_20 ) ;
V_20 -> V_16 = V_410 -> V_16 ;
}
}
}
goto V_24;
case V_465 :
if ( V_20 -> V_440 <= V_508 ) {
char V_266 [ 64 ] ;
if ( V_181 > sizeof( V_266 ) - sizeof( struct V_439 ) ) {
F_83 ( V_20 , V_312 ) ;
goto V_24;
}
V_149 = V_458 ;
V_181 = F_232 ( V_20 , V_148 -> V_182 , V_181 ,
V_266 , & V_149 ) ;
if ( V_181 < 0 ) {
F_83 ( V_20 , V_312 ) ;
goto V_24;
}
F_80 ( V_10 , F_88 ( V_10 ) ,
V_320 , V_181 , V_266 ) ;
V_20 -> V_321 ++ ;
if ( V_149 != V_458 )
goto V_24;
break;
}
default:
F_24 ( V_20 , V_312 ) ;
F_82 ( V_20 , V_509 ) ;
F_83 ( V_20 , V_312 ) ;
goto V_24;
}
if ( V_94 & V_505 )
goto V_24;
F_54 ( V_506 , & V_20 -> V_76 ) ;
if ( F_73 ( V_478 , & V_20 -> V_76 ) ) {
F_244 ( V_20 ) ;
if ( V_20 -> V_136 == V_139 ||
V_20 -> V_136 == V_143 )
V_21 = F_222 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_129 ( V_20 ) ;
}
V_24:
F_46 ( V_20 ) ;
return V_21 ;
}
static inline int F_251 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
struct V_308 * V_266 = (struct V_308 * ) V_182 ;
struct V_510 V_148 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_482 != sizeof( * V_266 ) )
return - V_485 ;
V_14 = F_66 ( V_266 -> V_14 ) ;
V_13 = F_66 ( V_266 -> V_13 ) ;
F_21 ( L_48 , V_14 , V_13 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_4 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_8 ( & V_10 -> V_15 ) ;
F_246 ( V_10 , V_410 -> V_16 , V_13 , V_14 ) ;
return 0 ;
}
F_7 ( V_20 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
F_80 ( V_10 , V_410 -> V_16 , V_511 , sizeof( V_148 ) , & V_148 ) ;
V_20 -> V_32 -> V_512 ( V_20 ) ;
F_57 ( V_20 ) ;
F_69 ( V_20 , V_312 ) ;
F_46 ( V_20 ) ;
V_20 -> V_32 -> V_68 ( V_20 ) ;
F_47 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_252 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
struct V_510 * V_148 = (struct V_510 * ) V_182 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_482 != sizeof( * V_148 ) )
return - V_485 ;
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
static inline int F_253 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
struct V_296 * V_266 = (struct V_296 * ) V_182 ;
T_2 type ;
if ( V_482 != sizeof( * V_266 ) )
return - V_485 ;
type = F_66 ( V_266 -> type ) ;
F_21 ( L_50 , type ) ;
if ( type == V_297 ) {
T_3 V_313 [ 8 ] ;
T_8 V_302 = V_304 ;
struct V_513 * V_148 = (struct V_513 * ) V_313 ;
V_148 -> type = F_16 ( V_297 ) ;
V_148 -> V_149 = F_16 ( V_514 ) ;
if ( ! V_305 )
V_302 |= V_306 | V_307
| V_449 ;
if ( V_10 -> V_256 )
V_302 |= V_433
| V_432 ;
F_106 ( V_302 , V_148 -> V_182 ) ;
F_80 ( V_10 , V_410 -> V_16 , V_515 , sizeof( V_313 ) ,
V_313 ) ;
} else if ( type == V_516 ) {
T_3 V_313 [ 12 ] ;
struct V_513 * V_148 = (struct V_513 * ) V_313 ;
if ( V_10 -> V_256 )
V_517 [ 0 ] |= V_258 ;
else
V_517 [ 0 ] &= ~ V_258 ;
V_148 -> type = F_16 ( V_516 ) ;
V_148 -> V_149 = F_16 ( V_514 ) ;
memcpy ( V_148 -> V_182 , V_517 , sizeof( V_517 ) ) ;
F_80 ( V_10 , V_410 -> V_16 , V_515 , sizeof( V_313 ) ,
V_313 ) ;
} else {
struct V_513 V_148 ;
V_148 . type = F_16 ( type ) ;
V_148 . V_149 = F_16 ( V_518 ) ;
F_80 ( V_10 , V_410 -> V_16 , V_515 , sizeof( V_148 ) ,
& V_148 ) ;
}
return 0 ;
}
static inline int F_254 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
struct V_513 * V_148 = (struct V_513 * ) V_182 ;
T_2 type , V_149 ;
if ( V_482 < sizeof( * V_148 ) )
return - V_485 ;
type = F_66 ( V_148 -> type ) ;
V_149 = F_66 ( V_148 -> V_149 ) ;
F_21 ( L_51 , type , V_149 ) ;
if ( V_410 -> V_16 != V_10 -> V_298 ||
V_10 -> V_293 & V_295 )
return 0 ;
F_238 ( & V_10 -> V_299 ) ;
if ( V_149 != V_514 ) {
V_10 -> V_293 |= V_295 ;
V_10 -> V_298 = 0 ;
F_138 ( V_10 ) ;
return 0 ;
}
switch ( type ) {
case V_297 :
V_10 -> V_302 = F_100 ( V_148 -> V_182 ) ;
if ( V_10 -> V_302 & V_519 ) {
struct V_296 V_266 ;
V_266 . type = F_16 ( V_516 ) ;
V_10 -> V_298 = F_88 ( V_10 ) ;
F_80 ( V_10 , V_10 -> V_298 ,
V_301 , sizeof( V_266 ) , & V_266 ) ;
} else {
V_10 -> V_293 |= V_295 ;
V_10 -> V_298 = 0 ;
F_138 ( V_10 ) ;
}
break;
case V_516 :
V_10 -> V_257 = V_148 -> V_182 [ 0 ] ;
V_10 -> V_293 |= V_295 ;
V_10 -> V_298 = 0 ;
F_138 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_255 ( struct V_9 * V_10 ,
struct V_409 * V_410 ,
T_2 V_482 , void * V_182 )
{
struct V_269 * V_266 = V_182 ;
struct V_520 V_148 ;
struct V_8 * V_20 ;
struct V_254 * V_183 ;
T_2 V_17 , V_14 ;
if ( V_482 != sizeof( * V_266 ) )
return - V_485 ;
if ( ! V_10 -> V_256 )
return - V_26 ;
V_17 = F_230 ( V_266 -> V_17 ) ;
V_14 = F_230 ( V_266 -> V_14 ) ;
F_21 ( L_52 , V_17 , V_14 , V_266 -> V_268 ) ;
if ( V_266 -> V_268 == V_429 ) {
F_239 ( V_10 , V_410 , V_182 , V_480 ,
V_266 -> V_268 ) ;
return 0 ;
}
V_183 = F_256 ( V_266 -> V_268 ) ;
if ( ! V_183 )
goto error;
if ( V_183 -> V_521 != V_522 || ! F_73 ( V_262 , & V_183 -> V_94 ) ) {
F_257 ( V_183 ) ;
goto error;
}
V_20 = F_239 ( V_10 , V_410 , V_182 , V_480 ,
V_266 -> V_268 ) ;
if ( V_20 ) {
struct V_129 * V_130 = V_10 -> V_2 -> V_129 ;
struct V_1 * V_194 ;
V_194 = F_258 ( V_183 , V_523 ,
& V_10 -> V_2 -> V_145 ) ;
if ( ! V_194 ) {
F_257 ( V_183 ) ;
F_246 ( V_10 , V_410 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
return 0 ;
}
F_21 ( L_53 , V_130 , V_20 , V_194 ) ;
V_130 -> V_132 = V_20 ;
V_20 -> V_194 = V_194 ;
V_20 -> V_78 = V_450 ;
V_10 -> V_154 = V_183 -> V_524 ;
}
F_257 ( V_183 ) ;
return 0 ;
error:
V_148 . V_13 = 0 ;
V_148 . V_14 = F_16 ( V_14 ) ;
V_148 . V_149 = F_16 ( V_525 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
F_80 ( V_10 , V_410 -> V_16 , V_480 ,
sizeof( V_148 ) , & V_148 ) ;
return 0 ;
}
static void F_259 ( struct V_8 * V_20 , T_3 V_526 )
{
struct V_527 V_266 ;
T_3 V_16 ;
F_21 ( L_54 , V_20 , V_526 ) ;
V_16 = F_88 ( V_20 -> V_10 ) ;
V_20 -> V_16 = V_16 ;
V_266 . V_528 = F_16 ( V_20 -> V_14 ) ;
V_266 . V_526 = V_526 ;
F_80 ( V_20 -> V_10 , V_16 , V_529 , sizeof( V_266 ) ,
& V_266 ) ;
F_82 ( V_20 , V_530 ) ;
}
static void F_260 ( struct V_8 * V_20 , T_2 V_149 )
{
struct V_531 V_148 ;
F_21 ( L_55 , V_20 , V_149 ) ;
V_148 . V_528 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_149 = F_16 ( V_149 ) ;
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_532 ,
sizeof( V_148 ) , & V_148 ) ;
}
static void F_261 ( struct V_8 * V_20 , T_2 V_149 )
{
struct V_533 V_534 ;
F_21 ( L_55 , V_20 , V_149 ) ;
V_20 -> V_16 = F_88 ( V_20 -> V_10 ) ;
V_534 . V_528 = F_16 ( V_20 -> V_14 ) ;
V_534 . V_149 = F_16 ( V_149 ) ;
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_535 ,
sizeof( V_534 ) , & V_534 ) ;
F_82 ( V_20 , V_530 ) ;
}
static void F_262 ( struct V_9 * V_10 , T_2 V_528 )
{
struct V_533 V_534 ;
F_21 ( L_56 , V_10 , V_528 ) ;
V_534 . V_528 = F_16 ( V_528 ) ;
V_534 . V_149 = F_16 ( V_536 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_535 ,
sizeof( V_534 ) , & V_534 ) ;
}
static void F_263 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_528 )
{
struct V_537 V_148 ;
F_21 ( L_57 , V_528 ) ;
V_148 . V_528 = F_16 ( V_528 ) ;
F_80 ( V_10 , V_16 , V_538 , sizeof( V_148 ) , & V_148 ) ;
}
static void F_264 ( struct V_8 * V_20 )
{
V_20 -> V_133 = NULL ;
V_20 -> V_194 = NULL ;
}
static void F_265 ( struct V_8 * V_20 )
{
if ( V_20 -> V_31 != V_61 ) {
F_83 ( V_20 , V_312 ) ;
return;
}
switch ( V_20 -> V_281 ) {
case V_286 :
F_127 ( V_20 ) ;
F_260 ( V_20 , V_539 ) ;
break;
case V_283 :
if ( V_20 -> V_191 == V_540 ||
V_20 -> V_191 == V_541 ) {
F_127 ( V_20 ) ;
}
F_261 ( V_20 , V_536 ) ;
break;
}
}
static void F_266 ( struct V_8 * V_20 ,
struct V_134 * V_190 )
{
struct V_453 V_148 ;
V_20 -> V_133 = V_190 ;
V_20 -> V_194 -> V_144 = V_20 -> V_10 ;
F_245 ( V_20 , & V_148 , V_20 -> V_16 , 0 ) ;
if ( F_73 ( V_506 , & V_20 -> V_76 ) ) {
int V_21 ;
F_244 ( V_20 ) ;
V_21 = F_222 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_129 ( V_20 ) ;
}
}
static void F_267 ( struct V_8 * V_20 ,
struct V_134 * V_190 )
{
V_20 -> V_194 = V_190 -> V_10 ;
V_20 -> V_194 -> V_144 = V_20 -> V_10 ;
F_21 ( L_58 , V_20 -> V_191 ) ;
switch ( V_20 -> V_191 ) {
case V_540 :
V_20 -> V_191 = V_542 ;
break;
case V_541 :
if ( F_73 ( V_251 , & V_20 -> V_245 ) ) {
V_20 -> V_191 = V_543 ;
} else if ( V_20 -> V_281 == V_283 ) {
V_20 -> V_191 = V_544 ;
F_261 ( V_20 , V_545 ) ;
} else if ( V_20 -> V_281 == V_286 ) {
V_20 -> V_191 = V_546 ;
F_260 ( V_20 , V_547 ) ;
}
break;
default:
F_264 ( V_20 ) ;
V_20 -> V_191 = V_192 ;
}
}
void F_268 ( struct V_8 * V_20 , struct V_134 * V_190 ,
T_3 V_159 )
{
F_21 ( L_59 , V_20 , V_190 , V_159 ) ;
if ( V_159 ) {
F_265 ( V_20 ) ;
F_264 ( V_20 ) ;
return;
}
if ( V_20 -> V_31 != V_61 ) {
if ( V_20 -> V_428 != V_429 )
F_266 ( V_20 , V_190 ) ;
} else {
F_267 ( V_20 , V_190 ) ;
}
}
void F_269 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_428 == V_429 ) {
if ( V_20 -> V_263 != V_264 )
return;
V_20 -> V_281 = V_283 ;
V_20 -> V_191 = V_193 ;
} else {
V_20 -> V_281 = V_283 ;
V_20 -> V_191 = V_542 ;
V_20 -> V_430 = 0 ;
F_126 ( V_20 ) ;
F_259 ( V_20 , 0 ) ;
}
}
static void F_270 ( struct V_8 * V_20 , int V_149 ,
T_3 V_428 , T_3 V_548 )
{
F_21 ( L_60 , V_20 , F_22 ( V_20 -> V_31 ) ,
V_428 , V_548 ) ;
V_20 -> V_78 = V_450 ;
if ( V_20 -> V_31 == V_64 ) {
if ( V_149 == V_317 ) {
V_20 -> V_428 = V_428 ;
F_125 ( V_20 , V_548 ) ;
} else {
F_124 ( V_20 ) ;
}
return;
}
if ( F_119 ( V_20 ) ) {
struct V_157 V_148 ;
char V_313 [ 128 ] ;
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( V_149 == V_317 ) {
V_148 . V_149 = F_16 ( V_317 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
} else {
V_148 . V_149 = F_16 ( V_490 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
}
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_480 ,
sizeof( V_148 ) , & V_148 ) ;
if ( V_149 == V_317 ) {
F_20 ( V_20 , V_62 ) ;
F_54 ( V_319 , & V_20 -> V_76 ) ;
F_80 ( V_20 -> V_10 , F_88 ( V_20 -> V_10 ) ,
V_320 ,
F_140 ( V_20 , V_313 ) , V_313 ) ;
V_20 -> V_321 ++ ;
}
}
}
static void F_271 ( struct V_8 * V_20 , T_3 V_428 ,
T_3 V_548 )
{
F_126 ( V_20 ) ;
V_20 -> V_430 = V_428 ;
V_20 -> V_191 = V_549 ;
F_259 ( V_20 , V_548 ) ;
}
static void F_272 ( struct V_8 * V_20 , int V_149 )
{
struct V_134 * V_190 = NULL ;
if ( V_190 ) {
if ( V_190 -> V_31 == V_61 ) {
V_20 -> V_194 = V_190 -> V_10 ;
V_20 -> V_194 -> V_144 = V_20 -> V_10 ;
V_20 -> V_191 = V_546 ;
F_260 ( V_20 , V_547 ) ;
F_268 ( V_20 , V_190 , V_547 ) ;
} else {
V_20 -> V_191 = V_541 ;
}
} else {
F_260 ( V_20 , V_550 ) ;
}
}
static void F_273 ( struct V_8 * V_20 , int V_149 )
{
if ( V_20 -> V_281 == V_286 ) {
T_3 V_551 ;
if ( V_149 == - V_26 )
V_551 = V_552 ;
else
V_551 = V_550 ;
F_260 ( V_20 , V_551 ) ;
}
V_20 -> V_281 = V_282 ;
V_20 -> V_191 = V_192 ;
F_175 ( V_20 ) ;
}
void F_274 ( struct V_8 * V_20 , int V_149 )
{
T_3 V_428 = V_20 -> V_428 ;
T_3 V_548 = V_20 -> V_548 ;
F_21 ( L_61 ,
V_20 , V_149 , V_428 , V_548 ) ;
if ( V_20 -> V_31 == V_153 || V_20 -> V_31 == V_553 ) {
F_46 ( V_20 ) ;
return;
}
if ( V_20 -> V_31 != V_61 ) {
F_270 ( V_20 , V_149 , V_428 , V_548 ) ;
} else if ( V_149 != V_547 ) {
F_273 ( V_20 , V_149 ) ;
} else {
switch ( V_20 -> V_281 ) {
case V_283 :
F_271 ( V_20 , V_428 ,
V_548 ) ;
break;
case V_286 :
F_272 ( V_20 , V_149 ) ;
break;
default:
F_273 ( V_20 , V_149 ) ;
break;
}
}
}
static inline int F_275 ( struct V_9 * V_10 ,
struct V_409 * V_410 ,
T_2 V_482 , void * V_182 )
{
struct V_527 * V_266 = V_182 ;
struct V_531 V_148 ;
struct V_8 * V_20 ;
T_2 V_528 = 0 ;
T_2 V_149 = V_550 ;
if ( V_482 != sizeof( * V_266 ) )
return - V_485 ;
V_528 = F_230 ( V_266 -> V_528 ) ;
F_21 ( L_62 , V_528 , V_266 -> V_526 ) ;
if ( ! V_10 -> V_256 )
return - V_26 ;
V_20 = F_9 ( V_10 , V_528 ) ;
if ( ! V_20 ) {
V_148 . V_528 = F_16 ( V_528 ) ;
V_148 . V_149 = F_16 ( V_550 ) ;
F_80 ( V_10 , V_410 -> V_16 , V_532 ,
sizeof( V_148 ) , & V_148 ) ;
return 0 ;
}
V_20 -> V_16 = V_410 -> V_16 ;
if ( V_20 -> V_14 < V_30 ||
V_20 -> V_263 == V_554 ||
( V_20 -> V_136 != V_139 &&
V_20 -> V_136 != V_143 ) ) {
V_149 = V_550 ;
goto V_555;
}
if ( V_20 -> V_428 == V_266 -> V_526 ) {
V_149 = V_556 ;
goto V_555;
}
if ( V_266 -> V_526 != V_429 ) {
struct V_254 * V_183 ;
V_183 = F_256 ( V_266 -> V_526 ) ;
if ( ! V_183 || V_183 -> V_521 != V_522 ||
! F_73 ( V_262 , & V_183 -> V_94 ) ) {
if ( V_183 )
F_257 ( V_183 ) ;
V_149 = V_552 ;
goto V_555;
}
F_257 ( V_183 ) ;
}
if ( ( F_94 ( V_20 ) ||
V_20 -> V_281 != V_282 ) &&
F_13 ( & V_10 -> V_2 -> V_18 , & V_10 -> V_2 -> V_145 ) > 0 ) {
V_149 = V_557 ;
goto V_555;
}
V_20 -> V_281 = V_286 ;
F_126 ( V_20 ) ;
V_20 -> V_430 = V_266 -> V_526 ;
V_528 = V_20 -> V_13 ;
if ( V_266 -> V_526 == V_429 ) {
if ( F_73 ( V_251 , & V_20 -> V_245 ) ) {
V_20 -> V_191 = V_543 ;
V_149 = V_558 ;
} else {
V_20 -> V_191 = V_546 ;
V_149 = V_547 ;
}
} else {
V_20 -> V_191 = V_193 ;
V_149 = V_558 ;
}
V_555:
F_260 ( V_20 , V_149 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static void F_276 ( struct V_9 * V_10 , T_2 V_528 , T_2 V_149 )
{
struct V_8 * V_20 ;
struct V_134 * V_190 = NULL ;
V_20 = F_5 ( V_10 , V_528 ) ;
if ( ! V_20 ) {
F_262 ( V_10 , V_528 ) ;
return;
}
F_70 ( V_20 ) ;
if ( V_149 == V_558 )
F_82 ( V_20 , V_559 ) ;
switch ( V_20 -> V_191 ) {
case V_540 :
V_20 -> V_191 = V_541 ;
break;
case V_542 :
if ( V_149 == V_558 ) {
break;
} else if ( F_73 ( V_251 ,
& V_20 -> V_245 ) ) {
V_20 -> V_191 = V_543 ;
} else {
V_20 -> V_191 = V_544 ;
F_261 ( V_20 , V_545 ) ;
}
break;
case V_549 :
if ( V_149 == V_547 ) {
V_20 -> V_191 = V_541 ;
} else {
V_20 -> V_191 = V_540 ;
}
if ( ! V_190 ) {
F_261 ( V_20 , V_536 ) ;
break;
}
if ( V_190 -> V_31 != V_61 )
break;
V_20 -> V_194 = V_190 -> V_10 ;
V_20 -> V_194 -> V_144 = V_20 -> V_10 ;
if ( V_149 == V_547 ) {
F_261 ( V_20 , V_545 ) ;
} else {
V_20 -> V_191 = V_542 ;
}
F_268 ( V_20 , V_190 , V_547 ) ;
break;
default:
V_20 -> V_430 = V_20 -> V_428 ;
F_127 ( V_20 ) ;
F_261 ( V_20 , V_536 ) ;
}
F_46 ( V_20 ) ;
}
static void F_277 ( struct V_9 * V_10 , T_3 V_16 , T_2 V_528 ,
T_2 V_149 )
{
struct V_8 * V_20 ;
V_20 = F_11 ( V_10 , V_16 ) ;
if ( ! V_20 ) {
F_262 ( V_10 , V_528 ) ;
return;
}
F_70 ( V_20 ) ;
if ( V_20 -> V_281 == V_283 ) {
if ( V_149 == V_557 ) {
V_20 -> V_281 = V_286 ;
} else {
V_20 -> V_430 = V_20 -> V_428 ;
F_127 ( V_20 ) ;
}
}
F_261 ( V_20 , V_536 ) ;
F_46 ( V_20 ) ;
}
static int F_278 ( struct V_9 * V_10 ,
struct V_409 * V_410 ,
T_2 V_482 , void * V_182 )
{
struct V_531 * V_148 = V_182 ;
T_2 V_528 , V_149 ;
if ( V_482 != sizeof( * V_148 ) )
return - V_485 ;
V_528 = F_230 ( V_148 -> V_528 ) ;
V_149 = F_230 ( V_148 -> V_149 ) ;
F_21 ( L_63 , V_528 , V_149 ) ;
if ( V_149 == V_547 || V_149 == V_558 )
F_276 ( V_10 , V_528 , V_149 ) ;
else
F_277 ( V_10 , V_410 -> V_16 , V_528 , V_149 ) ;
return 0 ;
}
static int F_279 ( struct V_9 * V_10 ,
struct V_409 * V_410 ,
T_2 V_482 , void * V_182 )
{
struct V_533 * V_534 = V_182 ;
struct V_8 * V_20 ;
T_2 V_528 , V_149 ;
if ( V_482 != sizeof( * V_534 ) )
return - V_485 ;
V_528 = F_230 ( V_534 -> V_528 ) ;
V_149 = F_230 ( V_534 -> V_149 ) ;
F_21 ( L_63 , V_528 , V_149 ) ;
V_20 = F_9 ( V_10 , V_528 ) ;
if ( ! V_20 ) {
F_263 ( V_10 , V_410 -> V_16 , V_528 ) ;
return 0 ;
}
if ( V_20 -> V_191 == V_546 ) {
if ( V_149 == V_545 ) {
V_20 -> V_428 = V_20 -> V_430 ;
if ( V_20 -> V_428 == V_429 )
F_264 ( V_20 ) ;
} else {
V_20 -> V_430 = V_20 -> V_428 ;
}
F_127 ( V_20 ) ;
}
F_263 ( V_10 , V_410 -> V_16 , V_528 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static inline int F_280 ( struct V_9 * V_10 ,
struct V_409 * V_410 ,
T_2 V_482 , void * V_182 )
{
struct V_537 * V_148 = V_182 ;
struct V_8 * V_20 ;
T_2 V_528 ;
if ( V_482 != sizeof( * V_148 ) )
return - V_485 ;
V_528 = F_230 ( V_148 -> V_528 ) ;
F_21 ( L_57 , V_528 ) ;
V_20 = F_5 ( V_10 , V_528 ) ;
if ( ! V_20 )
return 0 ;
F_70 ( V_20 ) ;
if ( V_20 -> V_191 == V_544 ) {
V_20 -> V_428 = V_20 -> V_430 ;
if ( V_20 -> V_428 == V_429 && V_20 -> V_133 )
F_264 ( V_20 ) ;
F_127 ( V_20 ) ;
}
F_46 ( V_20 ) ;
return 0 ;
}
static inline int F_281 ( T_2 V_560 , T_2 V_561 , T_2 V_562 ,
T_2 V_563 )
{
T_2 V_564 ;
if ( V_560 > V_561 || V_560 < 6 || V_561 > 3200 )
return - V_26 ;
if ( V_563 < 10 || V_563 > 3200 )
return - V_26 ;
if ( V_561 >= V_563 * 8 )
return - V_26 ;
V_564 = ( V_563 * 8 / V_561 ) - 1 ;
if ( V_562 > 499 || V_562 > V_564 )
return - V_26 ;
return 0 ;
}
static inline int F_282 ( struct V_9 * V_10 ,
struct V_409 * V_410 ,
T_2 V_482 , T_3 * V_182 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct F_282 * V_266 ;
struct V_565 V_148 ;
T_2 V_560 , V_561 , V_562 , V_563 ;
int V_21 ;
if ( ! ( V_2 -> V_566 & V_567 ) )
return - V_26 ;
if ( V_482 != sizeof( struct F_282 ) )
return - V_485 ;
V_266 = (struct F_282 * ) V_182 ;
V_560 = F_66 ( V_266 -> V_560 ) ;
V_561 = F_66 ( V_266 -> V_561 ) ;
V_562 = F_66 ( V_266 -> V_562 ) ;
V_563 = F_66 ( V_266 -> V_563 ) ;
F_21 ( L_64 ,
V_560 , V_561 , V_562 , V_563 ) ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_21 = F_281 ( V_560 , V_561 , V_562 , V_563 ) ;
if ( V_21 )
V_148 . V_149 = F_16 ( V_568 ) ;
else
V_148 . V_149 = F_16 ( V_569 ) ;
F_80 ( V_10 , V_410 -> V_16 , V_570 ,
sizeof( V_148 ) , & V_148 ) ;
if ( ! V_21 )
F_283 ( V_2 , V_560 , V_561 , V_562 , V_563 ) ;
return 0 ;
}
static int F_284 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
struct V_147 * V_148 = (struct V_147 * ) V_182 ;
T_2 V_13 , V_154 , V_101 , V_155 , V_149 ;
struct V_8 * V_20 ;
int V_21 ;
if ( V_482 < sizeof( * V_148 ) )
return - V_485 ;
V_13 = F_66 ( V_148 -> V_13 ) ;
V_154 = F_66 ( V_148 -> V_154 ) ;
V_101 = F_66 ( V_148 -> V_101 ) ;
V_155 = F_66 ( V_148 -> V_155 ) ;
V_149 = F_66 ( V_148 -> V_149 ) ;
if ( V_149 == V_317 && ( V_154 < 23 || V_101 < 23 ) )
return - V_485 ;
F_21 ( L_65 ,
V_13 , V_154 , V_101 , V_155 , V_149 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_10 ( V_10 , V_410 -> V_16 ) ;
if ( ! V_20 ) {
V_21 = - V_498 ;
goto V_499;
}
V_21 = 0 ;
F_7 ( V_20 ) ;
switch ( V_149 ) {
case V_317 :
V_20 -> V_16 = 0 ;
V_20 -> V_13 = V_13 ;
V_20 -> V_110 = V_154 ;
V_20 -> V_384 = V_101 ;
V_20 -> V_98 = V_155 ;
F_129 ( V_20 ) ;
break;
default:
F_69 ( V_20 , V_63 ) ;
break;
}
F_46 ( V_20 ) ;
V_499:
F_8 ( & V_10 -> V_15 ) ;
return V_21 ;
}
static inline int F_285 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
int V_21 = 0 ;
switch ( V_410 -> V_180 ) {
case V_503 :
F_237 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_267 :
V_21 = F_241 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_161 :
case V_480 :
F_243 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_320 :
V_21 = F_248 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_500 :
F_249 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_309 :
V_21 = F_251 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_511 :
F_252 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_571 :
F_80 ( V_10 , V_410 -> V_16 , V_572 , V_482 , V_182 ) ;
break;
case V_572 :
break;
case V_301 :
V_21 = F_253 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_515 :
F_254 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_270 :
V_21 = F_255 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_529 :
V_21 = F_275 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_532 :
F_278 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_535 :
V_21 = F_279 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_538 :
F_280 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
default:
F_286 ( L_66 , V_410 -> V_180 ) ;
V_21 = - V_26 ;
break;
}
return V_21 ;
}
static int F_287 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
struct V_290 * V_266 = (struct V_290 * ) V_182 ;
struct V_147 V_148 ;
struct V_8 * V_20 , * V_328 ;
T_2 V_13 , V_14 , V_155 , V_154 , V_101 ;
T_4 V_17 ;
T_3 V_149 ;
if ( V_482 != sizeof( * V_266 ) )
return - V_485 ;
V_14 = F_66 ( V_266 -> V_14 ) ;
V_154 = F_66 ( V_266 -> V_154 ) ;
V_101 = F_66 ( V_266 -> V_101 ) ;
V_17 = V_266 -> V_17 ;
V_13 = 0 ;
V_155 = 0 ;
if ( V_154 < 23 || V_101 < 23 )
return - V_485 ;
F_21 ( L_67 , F_66 ( V_17 ) ,
V_14 , V_154 , V_101 ) ;
V_328 = F_167 ( V_162 , V_17 , & V_10 -> V_2 -> V_18 ,
& V_10 -> V_2 -> V_145 , V_3 ) ;
if ( ! V_328 ) {
V_149 = V_152 ;
V_20 = NULL ;
goto V_489;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_328 ) ;
if ( ! F_288 ( V_10 -> V_2 , V_328 -> V_65 ) ) {
V_149 = V_573 ;
V_20 = NULL ;
goto V_574;
}
if ( F_2 ( V_10 , V_14 ) ) {
V_149 = V_490 ;
V_20 = NULL ;
goto V_574;
}
V_20 = V_328 -> V_32 -> V_330 ( V_328 ) ;
if ( ! V_20 ) {
V_149 = V_490 ;
goto V_574;
}
F_62 ( V_20 ) ;
F_78 ( & V_20 -> V_18 , & V_10 -> V_2 -> V_18 ) ;
F_78 ( & V_20 -> V_145 , & V_10 -> V_2 -> V_145 ) ;
V_20 -> V_332 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_332 ) ;
V_20 -> V_146 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_146 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_14 ;
V_20 -> V_110 = V_154 ;
V_20 -> V_384 = V_101 ;
V_20 -> V_98 = F_66 ( V_266 -> V_155 ) ;
F_65 ( V_10 , V_20 ) ;
V_13 = V_20 -> V_14 ;
V_155 = V_20 -> V_99 ;
F_82 ( V_20 , V_20 -> V_32 -> V_163 ( V_20 ) ) ;
V_20 -> V_16 = V_410 -> V_16 ;
if ( F_73 ( V_150 , & V_20 -> V_94 ) ) {
F_20 ( V_20 , V_164 ) ;
V_149 = V_314 ;
V_20 -> V_32 -> V_316 ( V_20 ) ;
} else {
F_129 ( V_20 ) ;
V_149 = V_317 ;
}
V_574:
F_46 ( V_328 ) ;
F_8 ( & V_10 -> V_15 ) ;
if ( V_149 == V_314 )
return 0 ;
V_489:
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
F_80 ( V_10 , V_410 -> V_16 , V_156 , sizeof( V_148 ) , & V_148 ) ;
return 0 ;
}
static inline int F_289 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
struct F_289 * V_575 ;
struct V_8 * V_20 ;
T_2 V_11 , V_155 , V_576 ;
if ( V_482 != sizeof( * V_575 ) )
return - V_485 ;
V_575 = (struct F_289 * ) V_182 ;
V_11 = F_66 ( V_575 -> V_11 ) ;
V_155 = F_66 ( V_575 -> V_155 ) ;
F_21 ( L_68 , V_11 , V_155 ) ;
V_20 = F_9 ( V_10 , V_11 ) ;
if ( ! V_20 )
return - V_498 ;
V_576 = V_577 - V_20 -> V_98 ;
if ( V_155 > V_576 ) {
F_286 ( L_69 ) ;
F_83 ( V_20 , V_312 ) ;
return 0 ;
}
V_20 -> V_98 += V_155 ;
while ( V_20 -> V_98 && ! F_172 ( & V_20 -> V_104 ) ) {
F_95 ( V_20 , F_173 ( & V_20 -> V_104 ) ) ;
V_20 -> V_98 -- ;
}
if ( V_20 -> V_98 )
V_20 -> V_32 -> V_578 ( V_20 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static inline int F_290 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
struct V_483 * V_484 = (struct V_483 * ) V_182 ;
struct V_8 * V_20 ;
if ( V_482 < sizeof( * V_484 ) )
return - V_485 ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_10 ( V_10 , V_410 -> V_16 ) ;
if ( ! V_20 )
goto V_24;
F_7 ( V_20 ) ;
F_69 ( V_20 , V_63 ) ;
F_46 ( V_20 ) ;
V_24:
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_291 ( struct V_9 * V_10 ,
struct V_409 * V_410 , T_2 V_482 ,
T_3 * V_182 )
{
int V_21 = 0 ;
switch ( V_410 -> V_180 ) {
case V_503 :
F_290 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_579 :
V_21 = F_282 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_570 :
break;
case V_156 :
F_284 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_292 :
V_21 = F_287 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_580 :
V_21 = F_289 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_309 :
V_21 = F_251 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
case V_511 :
F_252 ( V_10 , V_410 , V_482 , V_182 ) ;
break;
default:
F_286 ( L_70 , V_410 -> V_180 ) ;
V_21 = - V_26 ;
break;
}
return V_21 ;
}
static inline void F_292 ( struct V_9 * V_10 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_409 * V_410 ;
T_2 V_181 ;
int V_21 ;
if ( V_2 -> type != V_3 )
goto V_581;
if ( V_42 -> V_181 < V_411 )
goto V_581;
V_410 = ( void * ) V_42 -> V_182 ;
F_101 ( V_42 , V_411 ) ;
V_181 = F_230 ( V_410 -> V_181 ) ;
F_21 ( L_71 , V_410 -> V_180 , V_181 , V_410 -> V_16 ) ;
if ( V_181 != V_42 -> V_181 || ! V_410 -> V_16 ) {
F_21 ( L_72 ) ;
goto V_581;
}
V_21 = F_291 ( V_10 , V_410 , V_181 , V_42 -> V_182 ) ;
if ( V_21 ) {
struct V_483 V_484 ;
F_286 ( L_73 , V_21 ) ;
V_484 . V_60 = F_16 ( V_486 ) ;
F_80 ( V_10 , V_410 -> V_16 , V_503 ,
sizeof( V_484 ) , & V_484 ) ;
}
V_581:
F_96 ( V_42 ) ;
}
static inline void F_293 ( struct V_9 * V_10 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 * V_182 = V_42 -> V_182 ;
int V_181 = V_42 -> V_181 ;
struct V_409 V_410 ;
int V_21 ;
F_216 ( V_10 , V_42 ) ;
if ( V_2 -> type != V_109 )
goto V_581;
while ( V_181 >= V_411 ) {
T_2 V_482 ;
memcpy ( & V_410 , V_182 , V_411 ) ;
V_182 += V_411 ;
V_181 -= V_411 ;
V_482 = F_230 ( V_410 . V_181 ) ;
F_21 ( L_71 , V_410 . V_180 , V_482 ,
V_410 . V_16 ) ;
if ( V_482 > V_181 || ! V_410 . V_16 ) {
F_21 ( L_72 ) ;
break;
}
V_21 = F_285 ( V_10 , & V_410 , V_482 , V_182 ) ;
if ( V_21 ) {
struct V_483 V_484 ;
F_286 ( L_73 , V_21 ) ;
V_484 . V_60 = F_16 ( V_486 ) ;
F_80 ( V_10 , V_410 . V_16 , V_503 ,
sizeof( V_484 ) , & V_484 ) ;
}
V_182 += V_482 ;
V_181 -= V_482 ;
}
V_581:
F_96 ( V_42 ) ;
}
static int F_294 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
T_2 V_582 , V_583 ;
int V_584 ;
if ( F_73 ( V_232 , & V_20 -> V_94 ) )
V_584 = V_237 ;
else
V_584 = V_238 ;
if ( V_20 -> V_78 == V_79 ) {
F_295 ( V_42 , V_42 -> V_181 - V_242 ) ;
V_583 = F_102 ( V_42 -> V_182 + V_42 -> V_181 ) ;
V_582 = F_113 ( 0 , V_42 -> V_182 - V_584 , V_42 -> V_181 + V_584 ) ;
if ( V_582 != V_583 )
return - V_585 ;
}
return 0 ;
}
static void F_296 ( struct V_8 * V_20 )
{
struct V_198 V_43 ;
F_21 ( L_3 , V_20 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_206 = 1 ;
V_43 . V_202 = 1 ;
V_43 . V_199 = V_20 -> V_252 ;
F_54 ( V_244 , & V_20 -> V_245 ) ;
if ( F_73 ( V_251 , & V_20 -> V_245 ) ) {
V_43 . V_210 = V_248 ;
F_114 ( V_20 , & V_43 ) ;
}
if ( F_115 ( V_280 , & V_20 -> V_245 ) &&
V_20 -> V_363 > 0 )
F_25 ( V_20 ) ;
F_175 ( V_20 ) ;
if ( ! F_73 ( V_251 , & V_20 -> V_245 ) &&
F_73 ( V_244 , & V_20 -> V_245 ) ) {
V_43 . V_210 = V_246 ;
F_114 ( V_20 , & V_43 ) ;
}
}
static void F_297 ( struct V_38 * V_42 , struct V_38 * V_586 ,
struct V_38 * * V_587 )
{
if ( ! F_298 ( V_42 ) )
F_191 ( V_42 ) -> V_373 = V_586 ;
V_586 -> V_341 = NULL ;
( * V_587 ) -> V_341 = V_586 ;
* V_587 = V_586 ;
V_42 -> V_181 += V_586 -> V_181 ;
V_42 -> V_377 += V_586 -> V_181 ;
V_42 -> V_588 += V_586 -> V_588 ;
}
static int F_299 ( struct V_8 * V_20 , struct V_38 * V_42 ,
struct V_198 * V_43 )
{
int V_21 = - V_26 ;
switch ( V_43 -> V_213 ) {
case V_385 :
if ( V_20 -> V_95 )
break;
V_21 = V_20 -> V_32 -> V_407 ( V_20 , V_42 ) ;
break;
case V_386 :
if ( V_20 -> V_95 )
break;
V_20 -> V_97 = F_102 ( V_42 -> V_182 ) ;
F_101 ( V_42 , V_380 ) ;
if ( V_20 -> V_97 > V_20 -> V_102 ) {
V_21 = - V_389 ;
break;
}
if ( V_42 -> V_181 >= V_20 -> V_97 )
break;
V_20 -> V_95 = V_42 ;
V_20 -> V_96 = V_42 ;
V_42 = NULL ;
V_21 = 0 ;
break;
case V_388 :
if ( ! V_20 -> V_95 )
break;
F_297 ( V_20 -> V_95 , V_42 ,
& V_20 -> V_96 ) ;
V_42 = NULL ;
if ( V_20 -> V_95 -> V_181 >= V_20 -> V_97 )
break;
V_21 = 0 ;
break;
case V_387 :
if ( ! V_20 -> V_95 )
break;
F_297 ( V_20 -> V_95 , V_42 ,
& V_20 -> V_96 ) ;
V_42 = NULL ;
if ( V_20 -> V_95 -> V_181 != V_20 -> V_97 )
break;
V_21 = V_20 -> V_32 -> V_407 ( V_20 , V_20 -> V_95 ) ;
if ( ! V_21 ) {
V_20 -> V_95 = NULL ;
V_20 -> V_96 = NULL ;
V_20 -> V_97 = 0 ;
}
break;
}
if ( V_21 ) {
F_96 ( V_42 ) ;
F_96 ( V_20 -> V_95 ) ;
V_20 -> V_95 = NULL ;
V_20 -> V_96 = NULL ;
V_20 -> V_97 = 0 ;
}
return V_21 ;
}
static int F_300 ( struct V_8 * V_20 )
{
return 0 ;
}
void F_301 ( struct V_8 * V_20 , int V_589 )
{
T_3 V_397 ;
if ( V_20 -> V_136 != V_139 )
return;
V_397 = V_589 ? V_398 : V_400 ;
F_128 ( V_20 , NULL , NULL , V_397 ) ;
}
static int F_302 ( struct V_8 * V_20 )
{
int V_21 = 0 ;
F_21 ( L_3 , V_20 ) ;
while ( ! F_73 ( V_251 , & V_20 -> V_245 ) ) {
struct V_38 * V_42 ;
F_21 ( L_74 ,
V_20 -> V_252 , F_179 ( & V_20 -> V_140 ) ) ;
V_42 = F_31 ( & V_20 -> V_140 , V_20 -> V_252 ) ;
if ( ! V_42 )
break;
F_209 ( V_42 , & V_20 -> V_140 ) ;
V_20 -> V_252 = F_174 ( V_20 , V_20 -> V_252 ) ;
V_21 = F_299 ( V_20 , V_42 , & F_33 ( V_42 ) -> V_43 ) ;
if ( V_21 )
break;
}
if ( F_172 ( & V_20 -> V_140 ) ) {
V_20 -> V_278 = V_366 ;
F_186 ( V_20 ) ;
}
return V_21 ;
}
static void F_303 ( struct V_8 * V_20 ,
struct V_198 * V_43 )
{
struct V_38 * V_42 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( V_43 -> V_199 == V_20 -> V_357 ) {
F_21 ( L_75 , V_43 -> V_199 ) ;
F_83 ( V_20 , V_312 ) ;
return;
}
V_42 = F_31 ( & V_20 -> V_104 , V_43 -> V_199 ) ;
if ( V_42 == NULL ) {
F_21 ( L_76 ,
V_43 -> V_199 ) ;
return;
}
if ( V_20 -> V_80 != 0 && F_33 ( V_42 ) -> V_43 . V_272 >= V_20 -> V_80 ) {
F_21 ( L_21 , V_20 -> V_80 ) ;
F_83 ( V_20 , V_312 ) ;
return;
}
F_116 ( V_280 , & V_20 -> V_245 ) ;
if ( V_43 -> V_207 ) {
F_214 ( V_20 , V_43 ) ;
F_54 ( V_244 , & V_20 -> V_245 ) ;
F_183 ( V_20 , V_43 ) ;
F_175 ( V_20 ) ;
if ( V_20 -> V_276 == V_402 ) {
F_54 ( V_275 , & V_20 -> V_245 ) ;
V_20 -> V_590 = V_43 -> V_199 ;
}
} else {
F_215 ( V_20 , V_43 ) ;
if ( V_43 -> V_202 ) {
if ( V_20 -> V_590 != V_43 -> V_199 ||
! F_115 ( V_275 ,
& V_20 -> V_245 ) )
F_183 ( V_20 , V_43 ) ;
} else {
F_183 ( V_20 , V_43 ) ;
if ( V_20 -> V_276 == V_402 ) {
F_54 ( V_275 , & V_20 -> V_245 ) ;
V_20 -> V_590 = V_43 -> V_199 ;
}
}
}
}
static void F_304 ( struct V_8 * V_20 ,
struct V_198 * V_43 )
{
struct V_38 * V_42 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( V_43 -> V_199 == V_20 -> V_357 ) {
F_21 ( L_75 , V_43 -> V_199 ) ;
F_83 ( V_20 , V_312 ) ;
return;
}
V_42 = F_31 ( & V_20 -> V_104 , V_43 -> V_199 ) ;
if ( V_20 -> V_80 && V_42 &&
F_33 ( V_42 ) -> V_43 . V_272 >= V_20 -> V_80 ) {
F_21 ( L_21 , V_20 -> V_80 ) ;
F_83 ( V_20 , V_312 ) ;
return;
}
F_116 ( V_280 , & V_20 -> V_245 ) ;
F_214 ( V_20 , V_43 ) ;
if ( V_43 -> V_202 ) {
if ( ! F_115 ( V_274 , & V_20 -> V_245 ) )
F_184 ( V_20 , V_43 ) ;
} else {
F_184 ( V_20 , V_43 ) ;
F_175 ( V_20 ) ;
if ( V_20 -> V_276 == V_402 )
F_54 ( V_274 , & V_20 -> V_245 ) ;
}
}
static T_3 F_305 ( struct V_8 * V_20 , T_2 V_44 )
{
F_21 ( L_77 , V_20 , V_44 ) ;
F_21 ( L_78 , V_20 -> V_250 ,
V_20 -> V_273 ) ;
if ( V_20 -> V_278 == V_399 ) {
if ( F_187 ( V_20 , V_44 , V_20 -> V_250 ) >=
V_20 -> V_82 ) {
if ( V_20 -> V_82 <= ( ( V_20 -> V_84 + 1 ) >> 1 ) ) {
F_21 ( L_79 ) ;
return V_591 ;
} else {
F_21 ( L_80 ) ;
return V_592 ;
}
}
if ( V_20 -> V_141 . V_40 == V_44 ) {
F_21 ( L_81 ) ;
return V_593 ;
}
if ( F_31 ( & V_20 -> V_140 , V_44 ) ) {
F_21 ( L_82 ) ;
return V_594 ;
}
if ( F_39 ( & V_20 -> V_141 , V_44 ) ) {
F_21 ( L_83 ) ;
return V_595 ;
}
}
if ( V_20 -> V_273 == V_44 ) {
if ( F_187 ( V_20 , V_44 , V_20 -> V_250 ) >=
V_20 -> V_82 ) {
F_21 ( L_84 ) ;
return V_592 ;
} else {
F_21 ( L_85 ) ;
return V_596 ;
}
}
if ( F_187 ( V_20 , V_44 , V_20 -> V_250 ) <
F_187 ( V_20 , V_20 -> V_273 , V_20 -> V_250 ) ) {
F_21 ( L_86 ) ;
return V_597 ;
}
if ( F_187 ( V_20 , V_44 , V_20 -> V_250 ) >= V_20 -> V_82 ) {
if ( V_20 -> V_82 <= ( ( V_20 -> V_84 + 1 ) >> 1 ) ) {
F_21 ( L_87 ) ;
return V_591 ;
} else {
F_21 ( L_84 ) ;
return V_592 ;
}
} else {
F_21 ( L_88 ) ;
return V_598 ;
}
}
static int F_306 ( struct V_8 * V_20 ,
struct V_198 * V_43 ,
struct V_38 * V_42 , T_3 V_397 )
{
int V_21 = 0 ;
bool V_599 = false ;
F_21 ( L_89 , V_20 , V_43 , V_42 ,
V_397 ) ;
switch ( V_397 ) {
case V_600 :
switch ( F_305 ( V_20 , V_43 -> V_44 ) ) {
case V_596 :
F_214 ( V_20 , V_43 ) ;
if ( F_73 ( V_251 , & V_20 -> V_245 ) ) {
F_21 ( L_90 ,
V_43 -> V_44 ) ;
break;
}
V_20 -> V_273 = F_174 ( V_20 ,
V_43 -> V_44 ) ;
V_20 -> V_252 = V_20 -> V_273 ;
V_599 = true ;
V_21 = F_299 ( V_20 , V_42 , V_43 ) ;
if ( V_21 )
break;
if ( V_43 -> V_202 ) {
if ( ! F_115 ( V_274 ,
& V_20 -> V_245 ) ) {
V_43 -> V_202 = 0 ;
F_184 ( V_20 , V_43 ) ;
F_175 ( V_20 ) ;
}
}
if ( ! F_73 ( V_251 , & V_20 -> V_245 ) )
F_186 ( V_20 ) ;
break;
case V_598 :
F_214 ( V_20 , V_43 ) ;
if ( F_73 ( V_251 , & V_20 -> V_245 ) ) {
F_21 ( L_91 ,
V_43 -> V_44 ) ;
break;
}
F_307 ( & V_20 -> V_140 , V_42 ) ;
V_599 = true ;
F_21 ( L_92 , V_42 ,
F_179 ( & V_20 -> V_140 ) ) ;
F_116 ( V_275 , & V_20 -> V_245 ) ;
F_41 ( & V_20 -> V_141 ) ;
F_205 ( V_20 , V_43 -> V_44 ) ;
V_20 -> V_278 = V_399 ;
break;
case V_597 :
F_214 ( V_20 , V_43 ) ;
break;
case V_591 :
break;
case V_592 :
default:
F_83 ( V_20 , V_312 ) ;
break;
}
break;
case V_601 :
F_214 ( V_20 , V_43 ) ;
if ( V_43 -> V_202 ) {
F_116 ( V_280 , & V_20 -> V_245 ) ;
if ( ! F_115 ( V_274 , & V_20 -> V_245 ) &&
! F_94 ( V_20 ) ) {
V_43 -> V_202 = 0 ;
F_184 ( V_20 , V_43 ) ;
}
F_175 ( V_20 ) ;
} else if ( V_43 -> V_207 ) {
F_296 ( V_20 ) ;
} else {
if ( F_115 ( V_280 ,
& V_20 -> V_245 ) &&
V_20 -> V_363 )
F_25 ( V_20 ) ;
F_175 ( V_20 ) ;
}
break;
case V_602 :
F_54 ( V_280 , & V_20 -> V_245 ) ;
F_214 ( V_20 , V_43 ) ;
if ( V_43 && V_43 -> V_207 ) {
F_54 ( V_244 , & V_20 -> V_245 ) ;
F_118 ( V_20 , 0 ) ;
}
F_30 ( V_20 ) ;
F_41 ( & V_20 -> V_142 ) ;
break;
case V_603 :
F_304 ( V_20 , V_43 ) ;
break;
case V_604 :
F_303 ( V_20 , V_43 ) ;
break;
default:
break;
}
if ( V_42 && ! V_599 ) {
F_21 ( L_93 , V_42 ) ;
F_96 ( V_42 ) ;
}
return V_21 ;
}
static int F_308 ( struct V_8 * V_20 ,
struct V_198 * V_43 ,
struct V_38 * V_42 , T_3 V_397 )
{
int V_21 = 0 ;
T_2 V_44 = V_43 -> V_44 ;
bool V_599 = false ;
F_21 ( L_89 , V_20 , V_43 , V_42 ,
V_397 ) ;
switch ( V_397 ) {
case V_600 :
switch ( F_305 ( V_20 , V_44 ) ) {
case V_596 :
F_214 ( V_20 , V_43 ) ;
F_307 ( & V_20 -> V_140 , V_42 ) ;
V_599 = true ;
F_21 ( L_92 , V_42 ,
F_179 ( & V_20 -> V_140 ) ) ;
V_20 -> V_273 = F_174 ( V_20 , V_44 ) ;
break;
case V_593 :
F_40 ( & V_20 -> V_141 ) ;
F_214 ( V_20 , V_43 ) ;
F_307 ( & V_20 -> V_140 , V_42 ) ;
V_599 = true ;
F_21 ( L_92 , V_42 ,
F_179 ( & V_20 -> V_140 ) ) ;
V_21 = F_302 ( V_20 ) ;
if ( V_21 )
break;
break;
case V_598 :
F_307 ( & V_20 -> V_140 , V_42 ) ;
V_599 = true ;
F_21 ( L_92 , V_42 ,
F_179 ( & V_20 -> V_140 ) ) ;
F_214 ( V_20 , V_43 ) ;
F_205 ( V_20 , V_43 -> V_44 ) ;
break;
case V_595 :
F_307 ( & V_20 -> V_140 , V_42 ) ;
V_599 = true ;
F_21 ( L_92 , V_42 ,
F_179 ( & V_20 -> V_140 ) ) ;
F_214 ( V_20 , V_43 ) ;
F_207 ( V_20 , V_43 -> V_44 ) ;
break;
case V_594 :
F_214 ( V_20 , V_43 ) ;
break;
case V_597 :
break;
case V_591 :
break;
case V_592 :
default:
F_83 ( V_20 , V_312 ) ;
break;
}
break;
case V_601 :
F_214 ( V_20 , V_43 ) ;
if ( V_43 -> V_202 ) {
F_116 ( V_280 , & V_20 -> V_245 ) ;
if ( ! F_115 ( V_274 ,
& V_20 -> V_245 ) ) {
V_43 -> V_202 = 0 ;
F_184 ( V_20 , V_43 ) ;
}
F_175 ( V_20 ) ;
} else if ( V_43 -> V_207 ) {
if ( F_115 ( V_280 ,
& V_20 -> V_245 ) &&
V_20 -> V_363 ) {
F_25 ( V_20 ) ;
}
F_54 ( V_244 , & V_20 -> V_245 ) ;
F_206 ( V_20 ) ;
} else {
if ( F_115 ( V_280 ,
& V_20 -> V_245 ) &&
V_20 -> V_363 )
F_25 ( V_20 ) ;
F_186 ( V_20 ) ;
}
break;
case V_602 :
F_54 ( V_280 , & V_20 -> V_245 ) ;
F_214 ( V_20 , V_43 ) ;
if ( V_43 -> V_207 ) {
F_206 ( V_20 ) ;
} else {
struct V_198 V_605 ;
memset ( & V_605 , 0 , sizeof( V_605 ) ) ;
V_605 . V_206 = 1 ;
V_605 . V_210 = V_246 ;
V_605 . V_199 = V_20 -> V_252 ;
F_114 ( V_20 , & V_605 ) ;
}
break;
case V_603 :
F_304 ( V_20 , V_43 ) ;
break;
case V_604 :
F_303 ( V_20 , V_43 ) ;
break;
}
if ( V_42 && ! V_599 ) {
F_21 ( L_93 , V_42 ) ;
F_96 ( V_42 ) ;
}
return V_21 ;
}
static int F_309 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_278 = V_366 ;
if ( V_20 -> V_194 )
V_20 -> V_10 -> V_154 = V_20 -> V_194 -> V_183 -> V_524 ;
else
V_20 -> V_10 -> V_154 = V_20 -> V_10 -> V_2 -> V_183 -> V_606 ;
return F_300 ( V_20 ) ;
}
static int F_310 ( struct V_8 * V_20 ,
struct V_198 * V_43 ,
struct V_38 * V_42 , T_3 V_397 )
{
int V_21 ;
F_21 ( L_89 , V_20 , V_43 , V_42 ,
V_397 ) ;
if ( ! V_43 -> V_207 )
return - V_485 ;
F_208 ( V_20 , V_43 -> V_199 ) ;
if ( ! F_172 ( & V_20 -> V_104 ) )
V_20 -> V_362 = F_212 ( & V_20 -> V_104 ) ;
else
V_20 -> V_362 = NULL ;
V_20 -> V_357 = V_43 -> V_199 ;
V_20 -> V_363 = 0 ;
V_21 = F_309 ( V_20 ) ;
if ( V_21 )
return V_21 ;
F_54 ( V_244 , & V_20 -> V_245 ) ;
F_296 ( V_20 ) ;
if ( V_397 == V_600 )
return - V_485 ;
return F_306 ( V_20 , V_43 , NULL , V_397 ) ;
}
static int F_311 ( struct V_8 * V_20 ,
struct V_198 * V_43 ,
struct V_38 * V_42 , T_3 V_397 )
{
int V_21 ;
if ( ! V_43 -> V_202 )
return - V_485 ;
F_116 ( V_280 , & V_20 -> V_245 ) ;
V_20 -> V_278 = V_366 ;
F_208 ( V_20 , V_43 -> V_199 ) ;
if ( ! F_172 ( & V_20 -> V_104 ) )
V_20 -> V_362 = F_212 ( & V_20 -> V_104 ) ;
else
V_20 -> V_362 = NULL ;
V_20 -> V_357 = V_43 -> V_199 ;
V_20 -> V_363 = 0 ;
if ( V_20 -> V_194 )
V_20 -> V_10 -> V_154 = V_20 -> V_194 -> V_183 -> V_524 ;
else
V_20 -> V_10 -> V_154 = V_20 -> V_10 -> V_2 -> V_183 -> V_606 ;
V_21 = F_300 ( V_20 ) ;
if ( ! V_21 )
V_21 = F_306 ( V_20 , V_43 , V_42 , V_397 ) ;
return V_21 ;
}
static bool F_312 ( struct V_8 * V_20 , T_2 V_199 )
{
T_2 V_607 ;
V_607 = F_187 ( V_20 , V_20 -> V_357 , V_20 -> V_396 ) ;
return F_187 ( V_20 , V_20 -> V_357 , V_199 ) <= V_607 ;
}
static int F_313 ( struct V_8 * V_20 , struct V_198 * V_43 ,
struct V_38 * V_42 , T_3 V_397 )
{
int V_21 = 0 ;
F_21 ( L_94 , V_20 ,
V_43 , V_42 , V_397 , V_20 -> V_278 ) ;
if ( F_312 ( V_20 , V_43 -> V_199 ) ) {
switch ( V_20 -> V_278 ) {
case V_366 :
V_21 = F_306 ( V_20 , V_43 , V_42 , V_397 ) ;
break;
case V_399 :
V_21 = F_308 ( V_20 , V_43 , V_42 ,
V_397 ) ;
break;
case V_287 :
V_21 = F_310 ( V_20 , V_43 , V_42 , V_397 ) ;
break;
case V_285 :
V_21 = F_311 ( V_20 , V_43 , V_42 , V_397 ) ;
break;
default:
break;
}
} else {
F_21 ( L_95 ,
V_43 -> V_199 , V_20 -> V_357 ,
V_20 -> V_396 ) ;
F_83 ( V_20 , V_312 ) ;
}
return V_21 ;
}
static int F_314 ( struct V_8 * V_20 , struct V_198 * V_43 ,
struct V_38 * V_42 )
{
int V_21 = 0 ;
F_21 ( L_96 , V_20 , V_43 , V_42 ,
V_20 -> V_278 ) ;
if ( F_305 ( V_20 , V_43 -> V_44 ) ==
V_596 ) {
F_214 ( V_20 , V_43 ) ;
F_21 ( L_97 , V_20 -> V_252 ,
F_174 ( V_20 , V_20 -> V_252 ) ) ;
V_20 -> V_252 = F_174 ( V_20 , V_20 -> V_252 ) ;
F_299 ( V_20 , V_42 , V_43 ) ;
} else {
if ( V_20 -> V_95 ) {
F_96 ( V_20 -> V_95 ) ;
V_20 -> V_95 = NULL ;
}
V_20 -> V_96 = NULL ;
V_20 -> V_97 = 0 ;
if ( V_42 ) {
F_21 ( L_93 , V_42 ) ;
F_96 ( V_42 ) ;
}
}
V_20 -> V_250 = V_43 -> V_44 ;
V_20 -> V_273 = F_174 ( V_20 , V_43 -> V_44 ) ;
return V_21 ;
}
static int F_315 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
struct V_198 * V_43 = & F_33 ( V_42 ) -> V_43 ;
T_2 V_181 ;
T_3 V_397 ;
F_99 ( V_20 , V_42 ) ;
V_181 = V_42 -> V_181 ;
if ( F_294 ( V_20 , V_42 ) )
goto V_581;
if ( ! V_43 -> V_206 && V_43 -> V_213 == V_386 )
V_181 -= V_380 ;
if ( V_20 -> V_78 == V_79 )
V_181 -= V_242 ;
if ( V_181 > V_20 -> V_101 ) {
F_83 ( V_20 , V_312 ) ;
goto V_581;
}
if ( ! V_43 -> V_206 ) {
int V_21 ;
F_21 ( L_98 ,
V_43 -> V_213 , V_43 -> V_199 , V_43 -> V_202 ,
V_43 -> V_44 ) ;
if ( V_43 -> V_202 && V_20 -> V_276 != V_402 )
goto V_581;
if ( V_20 -> V_136 != V_143 ) {
V_397 = V_600 ;
V_21 = F_313 ( V_20 , V_43 , V_42 , V_397 ) ;
} else {
V_21 = F_314 ( V_20 , V_43 , V_42 ) ;
}
if ( V_21 )
F_83 ( V_20 , V_312 ) ;
} else {
const T_3 V_608 [ 4 ] = {
V_601 , V_603 ,
V_602 , V_604
} ;
if ( V_20 -> V_136 == V_143 )
goto V_581;
F_21 ( L_99 ,
V_43 -> V_199 , V_43 -> V_202 , V_43 -> V_207 ,
V_43 -> V_210 ) ;
if ( V_181 != 0 ) {
F_286 ( L_100 , V_181 ) ;
F_83 ( V_20 , V_312 ) ;
goto V_581;
}
if ( V_43 -> V_202 && ( V_43 -> V_207 ||
V_20 -> V_276 != V_402 ) )
goto V_581;
V_397 = V_608 [ V_43 -> V_210 ] ;
if ( F_313 ( V_20 , V_43 , V_42 , V_397 ) )
F_83 ( V_20 , V_312 ) ;
}
return 0 ;
V_581:
F_96 ( V_42 ) ;
return 0 ;
}
static void F_316 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct F_289 V_575 ;
T_2 V_609 ;
if ( V_20 -> V_99 >= ( V_100 + 1 ) / 2 )
return;
V_609 = V_100 - V_20 -> V_99 ;
F_21 ( L_101 , V_20 , V_609 ) ;
V_20 -> V_99 += V_609 ;
V_575 . V_11 = F_16 ( V_20 -> V_14 ) ;
V_575 . V_155 = F_16 ( V_609 ) ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_580 , sizeof( V_575 ) , & V_575 ) ;
}
static int F_317 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
int V_21 ;
if ( ! V_20 -> V_99 ) {
F_286 ( L_102 ) ;
F_83 ( V_20 , V_312 ) ;
return - V_610 ;
}
if ( V_20 -> V_102 < V_42 -> V_181 ) {
F_286 ( L_103 ) ;
return - V_610 ;
}
V_20 -> V_99 -- ;
F_21 ( L_104 , V_20 -> V_99 + 1 , V_20 -> V_99 ) ;
F_316 ( V_20 ) ;
V_21 = 0 ;
if ( ! V_20 -> V_95 ) {
T_2 V_97 ;
V_97 = F_102 ( V_42 -> V_182 ) ;
F_101 ( V_42 , V_380 ) ;
F_21 ( L_105 ,
V_97 , V_42 -> V_181 , V_20 -> V_102 ) ;
if ( V_97 > V_20 -> V_102 ) {
F_286 ( L_106 ) ;
V_21 = - V_389 ;
goto V_611;
}
if ( V_42 -> V_181 > V_97 ) {
F_286 ( L_107 ) ;
V_21 = - V_26 ;
goto V_611;
}
if ( V_42 -> V_181 == V_97 )
return V_20 -> V_32 -> V_407 ( V_20 , V_42 ) ;
V_20 -> V_95 = V_42 ;
V_20 -> V_97 = V_97 ;
V_20 -> V_96 = V_42 ;
return 0 ;
}
F_21 ( L_108 ,
V_20 -> V_95 -> V_181 , V_42 -> V_181 , V_20 -> V_97 ) ;
if ( V_20 -> V_95 -> V_181 + V_42 -> V_181 > V_20 -> V_97 ) {
F_286 ( L_107 ) ;
V_21 = - V_26 ;
goto V_611;
}
F_297 ( V_20 -> V_95 , V_42 , & V_20 -> V_96 ) ;
V_42 = NULL ;
if ( V_20 -> V_95 -> V_181 == V_20 -> V_97 ) {
V_21 = V_20 -> V_32 -> V_407 ( V_20 , V_20 -> V_95 ) ;
if ( ! V_21 ) {
V_20 -> V_95 = NULL ;
V_20 -> V_96 = NULL ;
V_20 -> V_97 = 0 ;
}
}
V_611:
if ( V_21 ) {
F_96 ( V_42 ) ;
F_96 ( V_20 -> V_95 ) ;
V_20 -> V_95 = NULL ;
V_20 -> V_96 = NULL ;
V_20 -> V_97 = 0 ;
}
return 0 ;
}
static void F_318 ( struct V_9 * V_10 , T_2 V_11 ,
struct V_38 * V_42 )
{
struct V_8 * V_20 ;
V_20 = F_5 ( V_10 , V_11 ) ;
if ( ! V_20 ) {
if ( V_11 == V_131 ) {
V_20 = F_319 ( V_10 , V_42 ) ;
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
F_21 ( L_110 , V_20 , V_42 -> V_181 ) ;
if ( V_20 -> V_31 != V_61 )
goto V_581;
switch ( V_20 -> V_136 ) {
case V_138 :
if ( F_317 ( V_20 , V_42 ) < 0 )
goto V_581;
goto V_24;
case V_137 :
if ( V_20 -> V_102 < V_42 -> V_181 ) {
F_286 ( L_111 ) ;
goto V_581;
}
if ( ! V_20 -> V_32 -> V_407 ( V_20 , V_42 ) )
goto V_24;
break;
case V_139 :
case V_143 :
F_315 ( V_20 , V_42 ) ;
goto V_24;
default:
F_21 ( L_112 , V_20 , V_20 -> V_136 ) ;
break;
}
V_581:
F_96 ( V_42 ) ;
V_24:
F_46 ( V_20 ) ;
}
static void F_320 ( struct V_9 * V_10 , T_4 V_17 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 ;
if ( V_2 -> type != V_109 )
goto V_581;
V_20 = F_167 ( 0 , V_17 , & V_2 -> V_18 , & V_2 -> V_145 ,
V_109 ) ;
if ( ! V_20 )
goto V_581;
F_21 ( L_110 , V_20 , V_42 -> V_181 ) ;
if ( V_20 -> V_31 != V_612 && V_20 -> V_31 != V_61 )
goto V_581;
if ( V_20 -> V_102 < V_42 -> V_181 )
goto V_581;
F_78 ( & F_33 ( V_42 ) -> V_613 , & V_2 -> V_145 ) ;
F_33 ( V_42 ) -> V_17 = V_17 ;
if ( ! V_20 -> V_32 -> V_407 ( V_20 , V_42 ) )
return;
V_581:
F_96 ( V_42 ) ;
}
static void F_321 ( struct V_9 * V_10 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 ;
if ( V_2 -> type != V_3 )
goto V_581;
V_20 = F_141 ( V_61 , V_329 ,
& V_2 -> V_18 , & V_2 -> V_145 ) ;
if ( ! V_20 )
goto V_581;
F_21 ( L_110 , V_20 , V_42 -> V_181 ) ;
if ( F_144 ( V_2 -> V_183 , & V_2 -> V_145 , V_2 -> V_146 ) )
goto V_581;
if ( V_20 -> V_102 < V_42 -> V_181 )
goto V_581;
if ( ! V_20 -> V_32 -> V_407 ( V_20 , V_42 ) )
return;
V_581:
F_96 ( V_42 ) ;
}
static void F_322 ( struct V_9 * V_10 , struct V_38 * V_42 )
{
struct V_239 * V_240 = ( void * ) V_42 -> V_182 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_11 , V_181 ;
T_4 V_17 ;
if ( V_2 -> V_31 != V_61 ) {
F_21 ( L_113 ) ;
F_307 ( & V_10 -> V_349 , V_42 ) ;
return;
}
F_101 ( V_42 , V_236 ) ;
V_11 = F_66 ( V_240 -> V_11 ) ;
V_181 = F_66 ( V_240 -> V_181 ) ;
if ( V_181 != V_42 -> V_181 ) {
F_96 ( V_42 ) ;
return;
}
F_21 ( L_114 , V_181 , V_11 ) ;
switch ( V_11 ) {
case V_115 :
F_293 ( V_10 , V_42 ) ;
break;
case V_113 :
V_17 = F_323 ( ( T_4 * ) V_42 -> V_182 ) ;
F_101 ( V_42 , V_378 ) ;
F_320 ( V_10 , V_17 , V_42 ) ;
break;
case V_329 :
F_321 ( V_10 , V_42 ) ;
break;
case V_412 :
F_292 ( V_10 , V_42 ) ;
break;
case V_614 :
if ( F_324 ( V_10 , V_42 ) )
F_156 ( V_10 -> V_2 , V_615 ) ;
break;
case V_616 :
F_325 ( V_10 , V_42 ) ;
break;
default:
F_318 ( V_10 , V_11 , V_42 ) ;
break;
}
}
static void F_326 ( struct V_57 * V_58 )
{
struct V_9 * V_10 = F_44 ( V_58 , struct V_9 ,
V_336 ) ;
struct V_38 * V_42 ;
F_21 ( L_15 ) ;
while ( ( V_42 = F_173 ( & V_10 -> V_349 ) ) )
F_322 ( V_10 , V_42 ) ;
}
static struct V_9 * F_327 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_144 ;
struct V_134 * V_190 ;
if ( V_10 )
return V_10 ;
V_190 = F_328 ( V_2 ) ;
if ( ! V_190 )
return NULL ;
V_10 = F_49 ( sizeof( struct V_9 ) , V_51 ) ;
if ( ! V_10 ) {
F_159 ( V_190 ) ;
return NULL ;
}
F_53 ( & V_10 -> V_352 ) ;
V_2 -> V_144 = V_10 ;
V_10 -> V_2 = V_2 ;
F_329 ( V_10 -> V_2 ) ;
V_10 -> V_190 = V_190 ;
F_21 ( L_115 , V_2 , V_10 , V_190 ) ;
switch ( V_2 -> type ) {
case V_3 :
if ( V_2 -> V_183 -> V_617 ) {
V_10 -> V_154 = V_2 -> V_183 -> V_617 ;
break;
}
default:
V_10 -> V_154 = V_2 -> V_183 -> V_606 ;
break;
}
V_10 -> V_302 = 0 ;
if ( V_2 -> type == V_109 )
V_10 -> V_256 = F_73 ( V_618 ,
& V_2 -> V_183 -> V_495 ) ;
F_330 ( & V_10 -> V_70 ) ;
F_50 ( & V_10 -> V_15 ) ;
F_331 ( & V_10 -> V_128 ) ;
F_331 ( & V_10 -> V_346 ) ;
if ( V_2 -> type == V_3 )
F_52 ( & V_10 -> V_351 , F_163 ) ;
else
F_52 ( & V_10 -> V_299 , F_148 ) ;
F_64 ( & V_10 -> V_349 ) ;
F_332 ( & V_10 -> V_336 , F_326 ) ;
V_10 -> V_105 = V_106 ;
return V_10 ;
}
static bool F_333 ( T_2 V_17 , T_3 V_146 ) {
if ( ! V_17 )
return false ;
if ( F_334 ( V_146 ) )
return ( V_17 <= 0x00ff ) ;
return ( ( V_17 & 0x0101 ) == 0x0001 ) ;
}
int F_335 ( struct V_8 * V_20 , T_4 V_17 , T_2 V_11 ,
T_5 * V_145 , T_3 V_146 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_254 * V_183 ;
T_1 V_177 ;
int V_21 ;
F_21 ( L_116 , & V_20 -> V_18 , V_145 ,
V_146 , F_66 ( V_17 ) ) ;
V_183 = F_336 ( V_145 , & V_20 -> V_18 ) ;
if ( ! V_183 )
return - V_619 ;
F_150 ( V_183 ) ;
F_7 ( V_20 ) ;
if ( ! F_333 ( F_66 ( V_17 ) , V_146 ) && ! V_11 &&
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
if ( ! V_305 )
break;
default:
V_21 = - V_620 ;
goto V_24;
}
switch ( V_20 -> V_31 ) {
case V_64 :
case V_164 :
case V_62 :
V_21 = 0 ;
goto V_24;
case V_61 :
V_21 = - V_621 ;
goto V_24;
case V_73 :
case V_612 :
break;
default:
V_21 = - V_392 ;
goto V_24;
}
F_78 ( & V_20 -> V_145 , V_145 ) ;
V_20 -> V_146 = V_146 ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_11 ;
V_177 = F_84 ( V_20 ) ;
if ( F_334 ( V_146 ) ) {
if ( V_146 == V_5 )
V_146 = V_4 ;
else
V_146 = V_622 ;
V_2 = F_337 ( V_183 , V_145 , V_146 , V_20 -> V_65 ,
V_177 ) ;
} else {
V_2 = F_338 ( V_183 , V_145 , V_20 -> V_65 , V_177 ) ;
}
if ( F_117 ( V_2 ) ) {
V_21 = F_192 ( V_2 ) ;
goto V_24;
}
V_10 = F_327 ( V_2 ) ;
if ( ! V_10 ) {
F_71 ( V_2 ) ;
V_21 = - V_52 ;
goto V_24;
}
if ( V_11 && F_2 ( V_10 , V_11 ) ) {
F_71 ( V_2 ) ;
V_21 = - V_623 ;
goto V_24;
}
F_78 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
V_20 -> V_332 = F_1 ( V_2 , V_2 -> V_332 ) ;
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
if ( F_85 ( V_20 ) )
F_20 ( V_20 , V_61 ) ;
} else
F_135 ( V_20 ) ;
}
V_21 = 0 ;
V_24:
F_46 ( V_20 ) ;
F_151 ( V_183 ) ;
F_257 ( V_183 ) ;
return V_21 ;
}
int F_339 ( struct V_254 * V_183 , T_5 * V_613 )
{
int V_624 = 0 , V_625 = 0 , V_626 = 0 ;
struct V_8 * V_12 ;
F_21 ( L_117 , V_183 -> V_627 , V_613 ) ;
F_121 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_12 -> V_31 != V_162 )
continue;
if ( ! F_13 ( & V_12 -> V_18 , & V_183 -> V_613 ) ) {
V_625 |= V_628 ;
if ( F_73 ( V_629 , & V_12 -> V_94 ) )
V_625 |= V_567 ;
V_624 ++ ;
} else if ( ! F_13 ( & V_12 -> V_18 , V_327 ) ) {
V_626 |= V_628 ;
if ( F_73 ( V_629 , & V_12 -> V_94 ) )
V_626 |= V_567 ;
}
}
F_122 ( & V_22 ) ;
return V_624 ? V_625 : V_626 ;
}
void F_340 ( struct V_1 * V_2 , T_3 V_159 )
{
struct V_9 * V_10 ;
F_21 ( L_118 , V_2 , & V_2 -> V_145 , V_159 ) ;
if ( ! V_159 ) {
V_10 = F_327 ( V_2 ) ;
if ( V_10 )
F_145 ( V_10 ) ;
} else {
F_156 ( V_2 , F_341 ( V_159 ) ) ;
}
}
int F_342 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_144 ;
F_21 ( L_119 , V_2 ) ;
if ( ! V_10 )
return V_106 ;
return V_10 -> V_105 ;
}
void F_343 ( struct V_1 * V_2 , T_3 V_60 )
{
F_21 ( L_120 , V_2 , V_60 ) ;
F_344 ( V_2 -> V_144 ) ;
F_156 ( V_2 , F_341 ( V_60 ) ) ;
}
static inline void F_345 ( struct V_8 * V_20 , T_3 V_630 )
{
if ( V_20 -> V_107 != V_108 )
return;
if ( V_630 == 0x00 ) {
if ( V_20 -> V_65 == V_169 ) {
F_82 ( V_20 , V_631 ) ;
} else if ( V_20 -> V_65 == V_166 ||
V_20 -> V_65 == V_167 )
F_45 ( V_20 , V_63 ) ;
} else {
if ( V_20 -> V_65 == V_169 )
F_70 ( V_20 ) ;
}
}
int F_346 ( struct V_1 * V_2 , T_3 V_159 , T_3 V_630 )
{
struct V_9 * V_10 = V_2 -> V_144 ;
struct V_8 * V_20 ;
if ( ! V_10 )
return 0 ;
F_21 ( L_121 , V_10 , V_159 , V_630 ) ;
if ( V_2 -> type == V_3 ) {
if ( ! V_159 && V_630 )
F_347 ( V_10 ) ;
F_238 ( & V_10 -> V_351 ) ;
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
if ( V_20 -> V_14 == V_329 ) {
if ( ! V_159 && V_630 ) {
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
if ( ! V_159 && ( V_20 -> V_31 == V_61 ||
V_20 -> V_31 == V_62 ) ) {
V_20 -> V_32 -> V_578 ( V_20 ) ;
F_345 ( V_20 , V_630 ) ;
F_46 ( V_20 ) ;
continue;
}
if ( V_20 -> V_31 == V_64 ) {
if ( ! V_159 )
F_133 ( V_20 ) ;
else
F_82 ( V_20 , V_632 ) ;
} else if ( V_20 -> V_31 == V_164 ) {
struct V_157 V_148 ;
T_6 V_633 , V_634 ;
if ( ! V_159 ) {
if ( F_73 ( V_150 , & V_20 -> V_94 ) ) {
V_633 = V_314 ;
V_634 = V_315 ;
V_20 -> V_32 -> V_316 ( V_20 ) ;
} else {
F_20 ( V_20 , V_62 ) ;
V_633 = V_317 ;
V_634 = V_160 ;
}
} else {
F_20 ( V_20 , V_153 ) ;
F_82 ( V_20 , V_632 ) ;
V_633 = V_158 ;
V_634 = V_160 ;
}
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_149 = F_16 ( V_633 ) ;
V_148 . V_159 = F_16 ( V_634 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_161 ,
sizeof( V_148 ) , & V_148 ) ;
if ( ! F_73 ( V_319 , & V_20 -> V_76 ) &&
V_633 == V_317 ) {
char V_313 [ 128 ] ;
F_54 ( V_319 , & V_20 -> V_76 ) ;
F_80 ( V_10 , F_88 ( V_10 ) ,
V_320 ,
F_140 ( V_20 , V_313 ) ,
V_313 ) ;
V_20 -> V_321 ++ ;
}
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
int F_348 ( struct V_1 * V_2 , struct V_38 * V_42 , T_2 V_94 )
{
struct V_9 * V_10 = V_2 -> V_144 ;
struct V_239 * V_635 ;
int V_181 ;
if ( ! V_10 && V_2 -> V_183 -> V_521 != V_636 )
goto V_581;
if ( ! V_10 )
V_10 = F_327 ( V_2 ) ;
if ( ! V_10 )
goto V_581;
F_21 ( L_123 , V_10 , V_42 -> V_181 , V_94 ) ;
switch ( V_94 ) {
case V_185 :
case V_184 :
case V_195 :
if ( V_10 -> V_637 ) {
F_286 ( L_124 , V_42 -> V_181 ) ;
F_96 ( V_10 -> V_348 ) ;
V_10 -> V_348 = NULL ;
V_10 -> V_637 = 0 ;
F_147 ( V_10 , V_638 ) ;
}
if ( V_42 -> V_181 < V_236 ) {
F_286 ( L_125 , V_42 -> V_181 ) ;
F_147 ( V_10 , V_638 ) ;
goto V_581;
}
V_635 = (struct V_239 * ) V_42 -> V_182 ;
V_181 = F_66 ( V_635 -> V_181 ) + V_236 ;
if ( V_181 == V_42 -> V_181 ) {
F_322 ( V_10 , V_42 ) ;
return 0 ;
}
F_21 ( L_126 , V_181 , V_42 -> V_181 ) ;
if ( V_42 -> V_181 > V_181 ) {
F_286 ( L_127 ,
V_42 -> V_181 , V_181 ) ;
F_147 ( V_10 , V_638 ) ;
goto V_581;
}
V_10 -> V_348 = F_110 ( V_181 , V_51 ) ;
if ( ! V_10 -> V_348 )
goto V_581;
F_349 ( V_42 , F_112 ( V_10 -> V_348 , V_42 -> V_181 ) ,
V_42 -> V_181 ) ;
V_10 -> V_637 = V_181 - V_42 -> V_181 ;
break;
case V_639 :
F_21 ( L_128 , V_42 -> V_181 , V_10 -> V_637 ) ;
if ( ! V_10 -> V_637 ) {
F_286 ( L_129 , V_42 -> V_181 ) ;
F_147 ( V_10 , V_638 ) ;
goto V_581;
}
if ( V_42 -> V_181 > V_10 -> V_637 ) {
F_286 ( L_130 ,
V_42 -> V_181 , V_10 -> V_637 ) ;
F_96 ( V_10 -> V_348 ) ;
V_10 -> V_348 = NULL ;
V_10 -> V_637 = 0 ;
F_147 ( V_10 , V_638 ) ;
goto V_581;
}
F_349 ( V_42 , F_112 ( V_10 -> V_348 , V_42 -> V_181 ) ,
V_42 -> V_181 ) ;
V_10 -> V_637 -= V_42 -> V_181 ;
if ( ! V_10 -> V_637 ) {
struct V_38 * V_348 = V_10 -> V_348 ;
V_10 -> V_348 = NULL ;
F_322 ( V_10 , V_348 ) ;
}
break;
}
V_581:
F_96 ( V_42 ) ;
return 0 ;
}
static int F_350 ( struct V_640 * V_641 , void * V_25 )
{
struct V_8 * V_12 ;
F_121 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
F_351 ( V_641 , L_131 ,
& V_12 -> V_18 , & V_12 -> V_145 ,
V_12 -> V_31 , F_66 ( V_12 -> V_17 ) ,
V_12 -> V_14 , V_12 -> V_13 , V_12 -> V_102 , V_12 -> V_110 ,
V_12 -> V_65 , V_12 -> V_136 ) ;
}
F_122 ( & V_22 ) ;
return 0 ;
}
static int F_352 ( struct V_642 * V_642 , struct V_643 * V_643 )
{
return F_353 ( V_643 , F_350 , V_642 -> V_644 ) ;
}
int T_11 F_354 ( void )
{
int V_21 ;
V_21 = F_355 () ;
if ( V_21 < 0 )
return V_21 ;
if ( F_356 ( V_645 ) )
return 0 ;
V_646 = F_357 ( L_132 , 0444 , V_645 ,
NULL , & V_647 ) ;
F_358 ( L_133 , 0644 , V_645 ,
& V_100 ) ;
F_358 ( L_134 , 0644 , V_645 ,
& V_103 ) ;
F_359 () ;
return 0 ;
}
void F_360 ( void )
{
F_361 () ;
F_362 ( V_646 ) ;
F_363 () ;
}
