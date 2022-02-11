static inline T_1 F_1 ( T_1 V_1 , T_1 F_1 )
{
if ( V_1 == V_2 ) {
if ( F_1 == V_3 )
return V_4 ;
else
return V_5 ;
}
return V_6 ;
}
static inline T_1 F_2 ( struct V_7 * V_8 )
{
return F_1 ( V_8 -> type , V_8 -> V_9 ) ;
}
static inline T_1 F_3 ( struct V_7 * V_8 )
{
return F_1 ( V_8 -> type , V_8 -> V_10 ) ;
}
static struct V_11 * F_4 ( struct V_12 * V_13 ,
T_2 V_14 )
{
struct V_11 * V_15 ;
F_5 (c, &conn->chan_l, list) {
if ( V_15 -> V_16 == V_14 )
return V_15 ;
}
return NULL ;
}
static struct V_11 * F_6 ( struct V_12 * V_13 ,
T_2 V_14 )
{
struct V_11 * V_15 ;
F_5 (c, &conn->chan_l, list) {
if ( V_15 -> V_17 == V_14 )
return V_15 ;
}
return NULL ;
}
static struct V_11 * F_7 ( struct V_12 * V_13 ,
T_2 V_14 )
{
struct V_11 * V_15 ;
F_8 ( & V_13 -> V_18 ) ;
V_15 = F_6 ( V_13 , V_14 ) ;
if ( V_15 )
F_9 ( V_15 ) ;
F_10 ( & V_13 -> V_18 ) ;
return V_15 ;
}
static struct V_11 * F_11 ( struct V_12 * V_13 ,
T_2 V_14 )
{
struct V_11 * V_15 ;
F_8 ( & V_13 -> V_18 ) ;
V_15 = F_4 ( V_13 , V_14 ) ;
if ( V_15 )
F_9 ( V_15 ) ;
F_10 ( & V_13 -> V_18 ) ;
return V_15 ;
}
static struct V_11 * F_12 ( struct V_12 * V_13 ,
T_1 V_19 )
{
struct V_11 * V_15 ;
F_5 (c, &conn->chan_l, list) {
if ( V_15 -> V_19 == V_19 )
return V_15 ;
}
return NULL ;
}
static struct V_11 * F_13 ( struct V_12 * V_13 ,
T_1 V_19 )
{
struct V_11 * V_15 ;
F_8 ( & V_13 -> V_18 ) ;
V_15 = F_12 ( V_13 , V_19 ) ;
if ( V_15 )
F_9 ( V_15 ) ;
F_10 ( & V_13 -> V_18 ) ;
return V_15 ;
}
static struct V_11 * F_14 ( T_3 V_20 , T_4 * V_21 )
{
struct V_11 * V_15 ;
F_5 (c, &chan_list, global_l) {
if ( V_15 -> V_22 == V_20 && ! F_15 ( & V_15 -> V_21 , V_21 ) )
return V_15 ;
}
return NULL ;
}
int F_16 ( struct V_11 * V_23 , T_4 * V_21 , T_3 V_20 )
{
int V_24 ;
F_17 ( & V_25 ) ;
if ( V_20 && F_14 ( V_20 , V_21 ) ) {
V_24 = - V_26 ;
goto V_27;
}
if ( V_20 ) {
V_23 -> V_20 = V_20 ;
V_23 -> V_22 = V_20 ;
V_24 = 0 ;
} else {
T_2 V_28 ;
V_24 = - V_29 ;
for ( V_28 = 0x1001 ; V_28 < 0x1100 ; V_28 += 2 )
if ( ! F_14 ( F_18 ( V_28 ) , V_21 ) ) {
V_23 -> V_20 = F_18 ( V_28 ) ;
V_23 -> V_22 = F_18 ( V_28 ) ;
V_24 = 0 ;
break;
}
}
V_27:
F_19 ( & V_25 ) ;
return V_24 ;
}
int F_20 ( struct V_11 * V_23 , T_5 V_17 )
{
F_17 ( & V_25 ) ;
V_23 -> V_30 = V_31 ;
V_23 -> V_32 = V_33 ;
V_23 -> V_17 = V_17 ;
F_19 ( & V_25 ) ;
return 0 ;
}
static T_2 F_21 ( struct V_12 * V_13 )
{
T_2 V_14 , V_34 ;
if ( V_13 -> V_8 -> type == V_2 )
V_34 = V_35 ;
else
V_34 = V_36 ;
for ( V_14 = V_37 ; V_14 < V_34 ; V_14 ++ ) {
if ( ! F_6 ( V_13 , V_14 ) )
return V_14 ;
}
return 0 ;
}
static void F_22 ( struct V_11 * V_23 , int V_38 )
{
F_23 ( L_1 , V_23 , F_24 ( V_23 -> V_38 ) ,
F_24 ( V_38 ) ) ;
V_23 -> V_38 = V_38 ;
V_23 -> V_39 -> V_40 ( V_23 , V_38 , 0 ) ;
}
static inline void F_25 ( struct V_11 * V_23 ,
int V_38 , int V_24 )
{
V_23 -> V_38 = V_38 ;
V_23 -> V_39 -> V_40 ( V_23 , V_23 -> V_38 , V_24 ) ;
}
static inline void F_26 ( struct V_11 * V_23 , int V_24 )
{
V_23 -> V_39 -> V_40 ( V_23 , V_23 -> V_38 , V_24 ) ;
}
static void F_27 ( struct V_11 * V_23 )
{
if ( ! F_28 ( & V_23 -> V_41 ) &&
V_23 -> V_42 ) {
F_29 ( V_23 , & V_23 -> V_43 ,
F_30 ( V_23 -> V_42 ) ) ;
}
}
static void F_31 ( struct V_11 * V_23 )
{
F_32 ( V_23 ) ;
if ( V_23 -> V_44 ) {
F_29 ( V_23 , & V_23 -> V_41 ,
F_30 ( V_23 -> V_44 ) ) ;
}
}
static struct V_45 * F_33 ( struct V_46 * V_47 ,
T_2 V_48 )
{
struct V_45 * V_49 ;
F_34 (head, skb) {
if ( F_35 ( V_49 ) -> V_50 . V_51 == V_48 )
return V_49 ;
}
return NULL ;
}
static int F_36 ( struct V_52 * V_53 , T_2 V_54 )
{
T_6 V_55 , V_56 ;
V_55 = F_37 ( V_54 ) ;
V_53 -> V_57 = F_38 ( sizeof( T_2 ) * V_55 , V_58 ) ;
if ( ! V_53 -> V_57 )
return - V_59 ;
V_53 -> V_60 = V_55 - 1 ;
V_53 -> V_47 = V_61 ;
V_53 -> V_62 = V_61 ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ )
V_53 -> V_57 [ V_56 ] = V_61 ;
return 0 ;
}
static inline void F_39 ( struct V_52 * V_53 )
{
F_40 ( V_53 -> V_57 ) ;
}
static inline bool F_41 ( struct V_52 * V_53 ,
T_2 V_48 )
{
return V_53 -> V_57 [ V_48 & V_53 -> V_60 ] != V_61 ;
}
static inline T_2 F_42 ( struct V_52 * V_53 )
{
T_2 V_48 = V_53 -> V_47 ;
T_2 V_60 = V_53 -> V_60 ;
V_53 -> V_47 = V_53 -> V_57 [ V_48 & V_60 ] ;
V_53 -> V_57 [ V_48 & V_60 ] = V_61 ;
if ( V_53 -> V_47 == V_63 ) {
V_53 -> V_47 = V_61 ;
V_53 -> V_62 = V_61 ;
}
return V_48 ;
}
static void F_43 ( struct V_52 * V_53 )
{
T_2 V_56 ;
if ( V_53 -> V_47 == V_61 )
return;
for ( V_56 = 0 ; V_56 <= V_53 -> V_60 ; V_56 ++ )
V_53 -> V_57 [ V_56 ] = V_61 ;
V_53 -> V_47 = V_61 ;
V_53 -> V_62 = V_61 ;
}
static void F_44 ( struct V_52 * V_53 , T_2 V_48 )
{
T_2 V_60 = V_53 -> V_60 ;
if ( V_53 -> V_57 [ V_48 & V_60 ] != V_61 )
return;
if ( V_53 -> V_62 == V_61 )
V_53 -> V_47 = V_48 ;
else
V_53 -> V_57 [ V_53 -> V_62 & V_60 ] = V_48 ;
V_53 -> V_62 = V_48 ;
V_53 -> V_57 [ V_48 & V_60 ] = V_63 ;
}
static void F_45 ( struct V_64 * V_65 )
{
struct V_11 * V_23 = F_46 ( V_65 , struct V_11 ,
V_66 . V_65 ) ;
struct V_12 * V_13 = V_23 -> V_13 ;
int V_67 ;
F_23 ( L_2 , V_23 , F_24 ( V_23 -> V_38 ) ) ;
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_23 ) ;
if ( V_23 -> V_38 == V_68 || V_23 -> V_38 == V_69 )
V_67 = V_70 ;
else if ( V_23 -> V_38 == V_71 &&
V_23 -> V_72 != V_73 )
V_67 = V_70 ;
else
V_67 = V_74 ;
F_47 ( V_23 , V_67 ) ;
F_48 ( V_23 ) ;
V_23 -> V_39 -> V_75 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
F_49 ( V_23 ) ;
}
struct V_11 * F_50 ( void )
{
struct V_11 * V_23 ;
V_23 = F_51 ( sizeof( * V_23 ) , V_76 ) ;
if ( ! V_23 )
return NULL ;
F_52 ( & V_23 -> V_77 ) ;
F_53 ( & V_23 -> V_78 , V_79 ) ;
F_17 ( & V_25 ) ;
F_54 ( & V_23 -> V_80 , & V_81 ) ;
F_19 ( & V_25 ) ;
F_55 ( & V_23 -> V_66 , F_45 ) ;
V_23 -> V_38 = V_82 ;
F_56 ( & V_23 -> V_83 ) ;
F_57 ( V_84 , & V_23 -> V_85 ) ;
F_23 ( L_3 , V_23 ) ;
return V_23 ;
}
static void F_58 ( struct V_83 * V_83 )
{
struct V_11 * V_23 = F_46 ( V_83 , struct V_11 , V_83 ) ;
F_23 ( L_3 , V_23 ) ;
F_17 ( & V_25 ) ;
F_59 ( & V_23 -> V_80 ) ;
F_19 ( & V_25 ) ;
F_40 ( V_23 ) ;
}
void F_60 ( struct V_11 * V_15 )
{
F_23 ( L_4 , V_15 , F_61 ( & V_15 -> V_83 . V_86 ) ) ;
F_62 ( & V_15 -> V_83 ) ;
}
void F_49 ( struct V_11 * V_15 )
{
F_23 ( L_4 , V_15 , F_61 ( & V_15 -> V_83 . V_86 ) ) ;
F_63 ( & V_15 -> V_83 , F_58 ) ;
}
void F_64 ( struct V_11 * V_23 )
{
V_23 -> V_87 = V_88 ;
V_23 -> V_89 = V_90 ;
V_23 -> V_91 = V_92 ;
V_23 -> V_93 = V_92 ;
V_23 -> V_94 = V_23 -> V_89 ;
V_23 -> V_95 = V_23 -> V_91 ;
V_23 -> V_96 = V_92 ;
V_23 -> V_72 = V_97 ;
V_23 -> V_98 = V_99 ;
V_23 -> V_42 = V_100 ;
V_23 -> V_44 = V_101 ;
V_23 -> V_85 = 0 ;
F_57 ( V_102 , & V_23 -> V_103 ) ;
}
static void F_65 ( struct V_11 * V_23 )
{
V_23 -> V_104 = NULL ;
V_23 -> V_105 = NULL ;
V_23 -> V_106 = 0 ;
V_23 -> V_107 = 0 ;
V_23 -> V_108 = V_109 ;
V_23 -> V_110 = F_66 ( T_2 , V_23 -> V_111 , V_112 ) ;
F_67 ( & V_23 -> V_113 ) ;
}
void F_68 ( struct V_12 * V_13 , struct V_11 * V_23 )
{
F_23 ( L_5 , V_13 ,
F_69 ( V_23 -> V_20 ) , V_23 -> V_16 ) ;
V_13 -> V_114 = V_115 ;
V_23 -> V_13 = V_13 ;
switch ( V_23 -> V_32 ) {
case V_116 :
V_23 -> V_17 = F_21 ( V_13 ) ;
if ( V_13 -> V_8 -> type == V_117 )
V_23 -> V_30 = V_31 ;
break;
case V_118 :
V_23 -> V_17 = V_119 ;
V_23 -> V_16 = V_119 ;
V_23 -> V_30 = V_31 ;
break;
case V_33 :
break;
default:
V_23 -> V_17 = V_120 ;
V_23 -> V_16 = V_120 ;
V_23 -> V_30 = V_31 ;
}
V_23 -> V_121 = V_122 ;
V_23 -> V_123 = V_124 ;
V_23 -> V_125 = V_126 ;
V_23 -> V_127 = V_128 ;
V_23 -> V_129 = V_130 ;
V_23 -> V_131 = V_132 ;
F_60 ( V_23 ) ;
if ( V_23 -> V_32 != V_33 ||
F_70 ( V_133 , & V_23 -> V_103 ) )
F_71 ( V_13 -> V_8 ) ;
F_54 ( & V_23 -> V_57 , & V_13 -> V_134 ) ;
}
void F_72 ( struct V_12 * V_13 , struct V_11 * V_23 )
{
F_8 ( & V_13 -> V_18 ) ;
F_68 ( V_13 , V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
}
void F_73 ( struct V_11 * V_23 , int V_24 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
F_74 ( V_23 ) ;
F_23 ( L_6 , V_23 , V_13 , V_24 ,
F_24 ( V_23 -> V_38 ) ) ;
V_23 -> V_39 -> V_135 ( V_23 , V_24 ) ;
if ( V_13 ) {
struct V_136 * V_137 = V_13 -> V_8 -> V_136 ;
F_59 ( & V_23 -> V_57 ) ;
F_49 ( V_23 ) ;
V_23 -> V_13 = NULL ;
if ( V_23 -> V_32 != V_33 ||
F_70 ( V_133 , & V_23 -> V_103 ) )
F_75 ( V_13 -> V_8 ) ;
if ( V_137 && V_137 -> V_138 == V_23 )
V_137 -> V_138 = NULL ;
}
if ( V_23 -> V_139 ) {
struct V_140 * V_139 = V_23 -> V_139 ;
F_23 ( L_7 , V_23 , V_139 ) ;
F_76 ( V_139 ) ;
}
if ( F_70 ( V_84 , & V_23 -> V_85 ) )
return;
switch( V_23 -> V_141 ) {
case V_142 :
break;
case V_143 :
F_77 ( & V_23 -> V_113 ) ;
break;
case V_144 :
F_32 ( V_23 ) ;
F_78 ( V_23 ) ;
F_79 ( V_23 ) ;
F_77 ( & V_23 -> V_145 ) ;
F_39 ( & V_23 -> V_146 ) ;
F_39 ( & V_23 -> V_147 ) ;
case V_148 :
F_77 ( & V_23 -> V_113 ) ;
break;
}
return;
}
static void F_80 ( struct V_64 * V_65 )
{
struct V_12 * V_13 = F_46 ( V_65 , struct V_12 ,
V_149 ) ;
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_11 * V_23 ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
F_9 ( V_23 ) ;
F_81 ( & V_23 -> V_150 , & V_8 -> V_150 ) ;
V_23 -> V_10 = F_3 ( V_8 ) ;
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static void F_82 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_151 V_152 ;
T_2 V_153 ;
if ( F_70 ( V_154 , & V_23 -> V_103 ) )
V_153 = V_155 ;
else
V_153 = V_156 ;
F_22 ( V_23 , V_157 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_152 . V_158 = F_18 ( V_23 -> V_111 ) ;
V_152 . V_110 = F_18 ( V_23 -> V_110 ) ;
V_152 . V_159 = F_18 ( V_23 -> V_108 ) ;
V_152 . V_153 = F_18 ( V_153 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_160 , sizeof( V_152 ) ,
& V_152 ) ;
}
static void F_84 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_161 V_152 ;
T_2 V_153 ;
if ( F_70 ( V_154 , & V_23 -> V_103 ) )
V_153 = V_162 ;
else
V_153 = V_156 ;
F_22 ( V_23 , V_157 ) ;
V_152 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_152 . V_153 = F_18 ( V_153 ) ;
V_152 . V_163 = F_18 ( V_164 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_165 , sizeof( V_152 ) , & V_152 ) ;
}
void F_47 ( struct V_11 * V_23 , int V_67 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
F_23 ( L_2 , V_23 , F_24 ( V_23 -> V_38 ) ) ;
switch ( V_23 -> V_38 ) {
case V_166 :
V_23 -> V_39 -> V_135 ( V_23 , 0 ) ;
break;
case V_68 :
case V_69 :
if ( V_23 -> V_32 == V_116 ) {
F_85 ( V_23 , V_23 -> V_39 -> V_167 ( V_23 ) ) ;
F_86 ( V_23 , V_67 ) ;
} else
F_73 ( V_23 , V_67 ) ;
break;
case V_168 :
if ( V_23 -> V_32 == V_116 ) {
if ( V_13 -> V_8 -> type == V_117 )
F_84 ( V_23 ) ;
else if ( V_13 -> V_8 -> type == V_2 )
F_82 ( V_23 ) ;
}
F_73 ( V_23 , V_67 ) ;
break;
case V_71 :
case V_157 :
F_73 ( V_23 , V_67 ) ;
break;
default:
V_23 -> V_39 -> V_135 ( V_23 , 0 ) ;
break;
}
}
static inline T_1 F_87 ( struct V_11 * V_23 )
{
switch ( V_23 -> V_32 ) {
case V_169 :
switch ( V_23 -> V_72 ) {
case V_170 :
case V_171 :
return V_172 ;
case V_173 :
return V_174 ;
default:
return V_175 ;
}
break;
case V_118 :
if ( V_23 -> V_20 == F_18 ( V_176 ) ) {
if ( V_23 -> V_72 == V_97 )
V_23 -> V_72 = V_73 ;
}
if ( V_23 -> V_72 == V_170 ||
V_23 -> V_72 == V_171 )
return V_177 ;
else
return V_175 ;
break;
case V_116 :
if ( V_23 -> V_20 == F_18 ( V_178 ) ) {
if ( V_23 -> V_72 == V_97 )
V_23 -> V_72 = V_73 ;
if ( V_23 -> V_72 == V_170 ||
V_23 -> V_72 == V_171 )
return V_177 ;
else
return V_175 ;
}
default:
switch ( V_23 -> V_72 ) {
case V_170 :
case V_171 :
return V_179 ;
case V_173 :
return V_180 ;
default:
return V_175 ;
}
break;
}
}
int F_88 ( struct V_11 * V_23 , bool V_181 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
T_7 V_182 ;
if ( V_13 -> V_8 -> type == V_2 )
return F_89 ( V_13 -> V_8 , V_23 -> V_72 ) ;
V_182 = F_87 ( V_23 ) ;
return F_90 ( V_13 -> V_8 , V_23 -> V_72 , V_182 ,
V_181 ) ;
}
static T_1 F_91 ( struct V_12 * V_13 )
{
T_1 V_183 ;
F_8 ( & V_13 -> V_184 ) ;
if ( ++ V_13 -> V_185 > 128 )
V_13 -> V_185 = 1 ;
V_183 = V_13 -> V_185 ;
F_10 ( & V_13 -> V_184 ) ;
return V_183 ;
}
static void F_83 ( struct V_12 * V_13 , T_1 V_19 , T_1 V_186 , T_2 V_187 ,
void * V_188 )
{
struct V_45 * V_49 = F_92 ( V_13 , V_186 , V_19 , V_187 , V_188 ) ;
T_1 V_103 ;
F_23 ( L_8 , V_186 ) ;
if ( ! V_49 )
return;
if ( F_93 ( V_13 -> V_8 -> V_189 ) ||
V_13 -> V_8 -> type == V_2 )
V_103 = V_190 ;
else
V_103 = V_191 ;
F_35 ( V_49 ) -> V_192 = V_193 ;
V_49 -> V_194 = V_195 ;
F_94 ( V_13 -> V_196 , V_49 , V_103 ) ;
}
static bool F_95 ( struct V_11 * V_23 )
{
return V_23 -> V_197 != V_198 &&
V_23 -> V_197 != V_199 ;
}
static void F_96 ( struct V_11 * V_23 , struct V_45 * V_49 )
{
struct V_7 * V_8 = V_23 -> V_13 -> V_8 ;
T_2 V_103 ;
F_23 ( L_9 , V_23 , V_49 , V_49 -> V_187 ,
V_49 -> V_194 ) ;
if ( V_23 -> V_200 && ! F_95 ( V_23 ) ) {
if ( V_23 -> V_139 )
F_94 ( V_23 -> V_139 , V_49 , V_201 ) ;
else
F_97 ( V_49 ) ;
return;
}
if ( V_8 -> type == V_2 ||
( ! F_70 ( V_202 , & V_23 -> V_103 ) &&
F_93 ( V_8 -> V_189 ) ) )
V_103 = V_190 ;
else
V_103 = V_191 ;
F_35 ( V_49 ) -> V_192 = F_70 ( V_102 , & V_23 -> V_103 ) ;
F_94 ( V_23 -> V_13 -> V_196 , V_49 , V_103 ) ;
}
static void F_98 ( T_2 V_203 , struct V_204 * V_205 )
{
V_205 -> V_206 = ( V_203 & V_207 ) >> V_208 ;
V_205 -> V_209 = ( V_203 & V_210 ) >> V_211 ;
if ( V_203 & V_212 ) {
V_205 -> V_213 = 1 ;
V_205 -> V_214 = ( V_203 & V_215 ) >> V_216 ;
V_205 -> V_217 = ( V_203 & V_218 ) >> V_219 ;
V_205 -> V_220 = 0 ;
V_205 -> V_51 = 0 ;
} else {
V_205 -> V_213 = 0 ;
V_205 -> V_220 = ( V_203 & V_221 ) >> V_222 ;
V_205 -> V_51 = ( V_203 & V_223 ) >> V_224 ;
V_205 -> V_214 = 0 ;
V_205 -> V_217 = 0 ;
}
}
static void F_99 ( T_8 V_225 , struct V_204 * V_205 )
{
V_205 -> V_206 = ( V_225 & V_226 ) >> V_227 ;
V_205 -> V_209 = ( V_225 & V_228 ) >> V_229 ;
if ( V_225 & V_230 ) {
V_205 -> V_213 = 1 ;
V_205 -> V_214 = ( V_225 & V_231 ) >> V_232 ;
V_205 -> V_217 = ( V_225 & V_233 ) >> V_234 ;
V_205 -> V_220 = 0 ;
V_205 -> V_51 = 0 ;
} else {
V_205 -> V_213 = 0 ;
V_205 -> V_220 = ( V_225 & V_235 ) >> V_236 ;
V_205 -> V_51 = ( V_225 & V_237 ) >> V_238 ;
V_205 -> V_214 = 0 ;
V_205 -> V_217 = 0 ;
}
}
static inline void F_100 ( struct V_11 * V_23 ,
struct V_45 * V_49 )
{
if ( F_70 ( V_239 , & V_23 -> V_103 ) ) {
F_99 ( F_101 ( V_49 -> V_188 ) ,
& F_35 ( V_49 ) -> V_50 ) ;
F_102 ( V_49 , V_240 ) ;
} else {
F_98 ( F_103 ( V_49 -> V_188 ) ,
& F_35 ( V_49 ) -> V_50 ) ;
F_102 ( V_49 , V_241 ) ;
}
}
static T_8 F_104 ( struct V_204 * V_205 )
{
T_8 V_242 ;
V_242 = V_205 -> V_206 << V_227 ;
V_242 |= V_205 -> V_209 << V_229 ;
if ( V_205 -> V_213 ) {
V_242 |= V_205 -> V_214 << V_232 ;
V_242 |= V_205 -> V_217 << V_234 ;
V_242 |= V_230 ;
} else {
V_242 |= V_205 -> V_220 << V_236 ;
V_242 |= V_205 -> V_51 << V_238 ;
}
return V_242 ;
}
static T_2 F_105 ( struct V_204 * V_205 )
{
T_2 V_242 ;
V_242 = V_205 -> V_206 << V_208 ;
V_242 |= V_205 -> V_209 << V_211 ;
if ( V_205 -> V_213 ) {
V_242 |= V_205 -> V_214 << V_216 ;
V_242 |= V_205 -> V_217 << V_219 ;
V_242 |= V_212 ;
} else {
V_242 |= V_205 -> V_220 << V_222 ;
V_242 |= V_205 -> V_51 << V_224 ;
}
return V_242 ;
}
static inline void F_106 ( struct V_11 * V_23 ,
struct V_204 * V_205 ,
struct V_45 * V_49 )
{
if ( F_70 ( V_239 , & V_23 -> V_103 ) ) {
F_107 ( F_104 ( V_205 ) ,
V_49 -> V_188 + V_243 ) ;
} else {
F_108 ( F_105 ( V_205 ) ,
V_49 -> V_188 + V_243 ) ;
}
}
static inline unsigned int F_109 ( struct V_11 * V_23 )
{
if ( F_70 ( V_239 , & V_23 -> V_103 ) )
return V_244 ;
else
return V_245 ;
}
static struct V_45 * F_110 ( struct V_11 * V_23 ,
T_8 V_205 )
{
struct V_45 * V_49 ;
struct V_246 * V_247 ;
int V_248 = F_109 ( V_23 ) ;
if ( V_23 -> V_87 == V_88 )
V_248 += V_249 ;
V_49 = F_111 ( V_248 , V_58 ) ;
if ( ! V_49 )
return F_112 ( - V_59 ) ;
V_247 = (struct V_246 * ) F_113 ( V_49 , V_243 ) ;
V_247 -> V_187 = F_18 ( V_248 - V_243 ) ;
V_247 -> V_14 = F_18 ( V_23 -> V_16 ) ;
if ( F_70 ( V_239 , & V_23 -> V_103 ) )
F_107 ( V_205 , F_113 ( V_49 , V_240 ) ) ;
else
F_108 ( V_205 , F_113 ( V_49 , V_241 ) ) ;
if ( V_23 -> V_87 == V_88 ) {
T_2 V_87 = F_114 ( 0 , ( T_1 * ) V_49 -> V_188 , V_49 -> V_187 ) ;
F_108 ( V_87 , F_113 ( V_49 , V_249 ) ) ;
}
V_49 -> V_194 = V_195 ;
return V_49 ;
}
static void F_115 ( struct V_11 * V_23 ,
struct V_204 * V_205 )
{
struct V_45 * V_49 ;
T_8 V_250 ;
F_23 ( L_10 , V_23 , V_205 ) ;
if ( ! V_205 -> V_213 )
return;
if ( F_95 ( V_23 ) )
return;
if ( F_116 ( V_251 , & V_23 -> V_252 ) &&
! V_205 -> V_214 )
V_205 -> V_209 = 1 ;
if ( V_205 -> V_217 == V_253 )
F_117 ( V_254 , & V_23 -> V_252 ) ;
else if ( V_205 -> V_217 == V_255 )
F_57 ( V_254 , & V_23 -> V_252 ) ;
if ( V_205 -> V_217 != V_256 ) {
V_23 -> V_257 = V_205 -> V_206 ;
F_79 ( V_23 ) ;
}
F_23 ( L_11 , V_205 -> V_206 ,
V_205 -> V_209 , V_205 -> V_214 , V_205 -> V_217 ) ;
if ( F_70 ( V_239 , & V_23 -> V_103 ) )
V_250 = F_104 ( V_205 ) ;
else
V_250 = F_105 ( V_205 ) ;
V_49 = F_110 ( V_23 , V_250 ) ;
if ( ! F_118 ( V_49 ) )
F_96 ( V_23 , V_49 ) ;
}
static void F_119 ( struct V_11 * V_23 , bool V_214 )
{
struct V_204 V_205 ;
F_23 ( L_12 , V_23 , V_214 ) ;
memset ( & V_205 , 0 , sizeof( V_205 ) ) ;
V_205 . V_213 = 1 ;
V_205 . V_214 = V_214 ;
if ( F_70 ( V_258 , & V_23 -> V_252 ) )
V_205 . V_217 = V_255 ;
else
V_205 . V_217 = V_253 ;
V_205 . V_206 = V_23 -> V_259 ;
F_115 ( V_23 , & V_205 ) ;
}
static inline int F_120 ( struct V_11 * V_23 )
{
if ( V_23 -> V_32 != V_116 )
return true ;
return ! F_70 ( V_260 , & V_23 -> V_85 ) ;
}
static bool F_121 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_261 * V_189 ;
bool V_262 = false ;
if ( ! ( V_13 -> V_263 & V_264 ) )
return false ;
if ( ! ( V_13 -> V_265 & V_264 ) )
return false ;
F_122 ( & V_266 ) ;
F_5 (hdev, &hci_dev_list, list) {
if ( V_189 -> V_267 != V_268 &&
F_70 ( V_269 , & V_189 -> V_103 ) ) {
V_262 = true ;
break;
}
}
F_123 ( & V_266 ) ;
if ( V_23 -> V_270 == V_271 )
return V_262 ;
return false ;
}
static bool F_124 ( struct V_11 * V_23 )
{
return true ;
}
void F_125 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_272 V_273 ;
V_273 . V_17 = F_18 ( V_23 -> V_17 ) ;
V_273 . V_20 = V_23 -> V_20 ;
V_23 -> V_19 = F_91 ( V_13 ) ;
F_57 ( V_260 , & V_23 -> V_85 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_274 , sizeof( V_273 ) , & V_273 ) ;
}
static void F_126 ( struct V_11 * V_23 , T_1 V_275 )
{
struct V_276 V_273 ;
V_273 . V_17 = F_18 ( V_23 -> V_17 ) ;
V_273 . V_20 = V_23 -> V_20 ;
V_273 . V_275 = V_275 ;
V_23 -> V_19 = F_91 ( V_23 -> V_13 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_277 ,
sizeof( V_273 ) , & V_273 ) ;
}
static void F_127 ( struct V_11 * V_23 )
{
struct V_45 * V_49 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_141 != V_144 )
return;
F_32 ( V_23 ) ;
F_78 ( V_23 ) ;
F_79 ( V_23 ) ;
V_23 -> V_278 = 0 ;
F_34 (&chan->tx_q, skb) {
if ( F_35 ( V_49 ) -> V_50 . V_279 )
F_35 ( V_49 ) -> V_50 . V_279 = 1 ;
else
break;
}
V_23 -> V_280 = V_23 -> V_259 ;
F_117 ( V_281 , & V_23 -> V_252 ) ;
F_117 ( V_282 , & V_23 -> V_252 ) ;
F_43 ( & V_23 -> V_147 ) ;
F_43 ( & V_23 -> V_146 ) ;
F_77 ( & V_23 -> V_145 ) ;
V_23 -> V_283 = V_284 ;
V_23 -> V_285 = V_286 ;
F_57 ( V_287 , & V_23 -> V_252 ) ;
}
static void F_128 ( struct V_11 * V_23 )
{
T_1 V_288 = V_23 -> V_288 ;
F_23 ( L_3 , V_23 ) ;
V_23 -> V_197 = V_198 ;
V_23 -> V_288 = V_289 ;
if ( V_23 -> V_141 != V_144 )
return;
switch ( V_288 ) {
case V_290 :
F_129 ( V_23 , NULL , NULL , V_291 ) ;
V_23 -> V_285 = V_292 ;
break;
case V_293 :
V_23 -> V_285 = V_294 ;
break;
}
}
static void F_130 ( struct V_11 * V_23 )
{
if ( V_23 -> V_38 == V_68 )
return;
V_23 -> V_85 = 0 ;
F_74 ( V_23 ) ;
if ( V_23 -> V_141 == V_143 && ! V_23 -> V_107 )
V_23 -> V_39 -> V_295 ( V_23 ) ;
V_23 -> V_38 = V_68 ;
V_23 -> V_39 -> V_296 ( V_23 ) ;
}
static void F_131 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_297 V_273 ;
if ( F_132 ( V_298 , & V_23 -> V_103 ) )
return;
V_273 . V_20 = V_23 -> V_20 ;
V_273 . V_17 = F_18 ( V_23 -> V_17 ) ;
V_273 . V_158 = F_18 ( V_23 -> V_111 ) ;
V_273 . V_110 = F_18 ( V_23 -> V_110 ) ;
V_273 . V_159 = F_18 ( V_23 -> V_108 ) ;
V_23 -> V_19 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_299 ,
sizeof( V_273 ) , & V_273 ) ;
}
static void F_133 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
if ( ! F_89 ( V_13 -> V_8 , V_23 -> V_72 ) )
return;
if ( ! V_23 -> V_20 ) {
F_130 ( V_23 ) ;
return;
}
if ( V_23 -> V_38 == V_71 )
F_131 ( V_23 ) ;
}
static void F_134 ( struct V_11 * V_23 )
{
if ( F_121 ( V_23 ) ) {
F_23 ( L_13 , V_23 ) ;
F_135 ( V_23 ) ;
} else if ( V_23 -> V_13 -> V_8 -> type == V_2 ) {
F_133 ( V_23 ) ;
} else {
F_125 ( V_23 ) ;
}
}
static void F_136 ( struct V_12 * V_13 )
{
struct V_300 V_273 ;
if ( V_13 -> V_301 & V_302 )
return;
V_273 . type = F_18 ( V_303 ) ;
V_13 -> V_301 |= V_302 ;
V_13 -> V_304 = F_91 ( V_13 ) ;
F_137 ( & V_13 -> V_305 , V_306 ) ;
F_83 ( V_13 , V_13 -> V_304 , V_307 ,
sizeof( V_273 ) , & V_273 ) ;
}
static void F_138 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
if ( V_13 -> V_8 -> type == V_2 ) {
F_133 ( V_23 ) ;
return;
}
if ( ! ( V_13 -> V_301 & V_302 ) ) {
F_136 ( V_13 ) ;
return;
}
if ( ! ( V_13 -> V_301 & V_308 ) )
return;
if ( F_88 ( V_23 , true ) &&
F_120 ( V_23 ) )
F_134 ( V_23 ) ;
}
static inline int F_139 ( T_7 V_141 , T_9 V_309 )
{
T_8 V_310 = V_311 ;
if ( ! V_312 )
V_310 |= V_313 | V_314 ;
switch ( V_141 ) {
case V_144 :
return V_313 & V_309 & V_310 ;
case V_148 :
return V_314 & V_309 & V_310 ;
default:
return 0x00 ;
}
}
static void F_86 ( struct V_11 * V_23 , int V_24 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_315 V_273 ;
if ( ! V_13 )
return;
if ( V_23 -> V_141 == V_144 && V_23 -> V_38 == V_68 ) {
F_32 ( V_23 ) ;
F_78 ( V_23 ) ;
F_79 ( V_23 ) ;
}
if ( V_23 -> V_17 == V_316 ) {
F_22 ( V_23 , V_157 ) ;
return;
}
V_273 . V_16 = F_18 ( V_23 -> V_16 ) ;
V_273 . V_17 = F_18 ( V_23 -> V_17 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_317 ,
sizeof( V_273 ) , & V_273 ) ;
F_25 ( V_23 , V_157 , V_24 ) ;
}
static void F_140 ( struct V_12 * V_13 )
{
struct V_11 * V_23 , * V_318 ;
F_23 ( L_14 , V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_141 (chan, tmp, &conn->chan_l, list) {
F_9 ( V_23 ) ;
if ( V_23 -> V_32 != V_116 ) {
F_130 ( V_23 ) ;
F_48 ( V_23 ) ;
continue;
}
if ( V_23 -> V_38 == V_71 ) {
if ( ! F_88 ( V_23 , true ) ||
! F_120 ( V_23 ) ) {
F_48 ( V_23 ) ;
continue;
}
if ( ! F_139 ( V_23 -> V_141 , V_13 -> V_309 )
&& F_70 ( V_319 ,
& V_23 -> V_85 ) ) {
F_47 ( V_23 , V_320 ) ;
F_48 ( V_23 ) ;
continue;
}
F_134 ( V_23 ) ;
} else if ( V_23 -> V_38 == V_168 ) {
struct V_161 V_152 ;
char V_321 [ 128 ] ;
V_152 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
if ( F_88 ( V_23 , false ) ) {
if ( F_70 ( V_154 , & V_23 -> V_103 ) ) {
V_152 . V_153 = F_18 ( V_322 ) ;
V_152 . V_163 = F_18 ( V_323 ) ;
V_23 -> V_39 -> V_324 ( V_23 ) ;
} else {
F_22 ( V_23 , V_69 ) ;
V_152 . V_153 = F_18 ( V_325 ) ;
V_152 . V_163 = F_18 ( V_164 ) ;
}
} else {
V_152 . V_153 = F_18 ( V_322 ) ;
V_152 . V_163 = F_18 ( V_326 ) ;
}
F_83 ( V_13 , V_23 -> V_19 , V_165 ,
sizeof( V_152 ) , & V_152 ) ;
if ( F_70 ( V_327 , & V_23 -> V_85 ) ||
V_152 . V_153 != V_325 ) {
F_48 ( V_23 ) ;
continue;
}
F_57 ( V_327 , & V_23 -> V_85 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_328 ,
F_142 ( V_23 , V_321 ) , V_321 ) ;
V_23 -> V_329 ++ ;
}
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static void F_143 ( struct V_12 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_261 * V_189 = V_8 -> V_189 ;
F_23 ( L_15 , V_189 -> V_330 , V_13 ) ;
if ( V_8 -> V_331 )
F_89 ( V_8 , V_8 -> V_332 ) ;
if ( V_8 -> V_333 == V_334 &&
( V_8 -> V_335 < V_8 -> V_336 ||
V_8 -> V_335 > V_8 -> V_337 ) ) {
struct V_338 V_273 ;
V_273 . V_339 = F_18 ( V_8 -> V_336 ) ;
V_273 . V_340 = F_18 ( V_8 -> V_337 ) ;
V_273 . V_341 = F_18 ( V_8 -> V_342 ) ;
V_273 . V_343 = F_18 ( V_8 -> V_344 ) ;
F_83 ( V_13 , F_91 ( V_13 ) ,
V_345 , sizeof( V_273 ) , & V_273 ) ;
}
}
static void F_144 ( struct V_12 * V_13 )
{
struct V_11 * V_23 ;
struct V_7 * V_8 = V_13 -> V_8 ;
F_23 ( L_14 , V_13 ) ;
if ( V_8 -> type == V_117 )
F_136 ( V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
F_9 ( V_23 ) ;
if ( V_23 -> V_17 == V_316 ) {
F_48 ( V_23 ) ;
continue;
}
if ( V_8 -> type == V_2 ) {
F_133 ( V_23 ) ;
} else if ( V_23 -> V_32 != V_116 ) {
if ( V_13 -> V_301 & V_308 )
F_130 ( V_23 ) ;
} else if ( V_23 -> V_38 == V_71 ) {
F_138 ( V_23 ) ;
}
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
if ( V_8 -> type == V_2 )
F_143 ( V_13 ) ;
F_145 ( V_8 -> V_189 -> V_346 , & V_13 -> V_347 ) ;
}
static void F_146 ( struct V_12 * V_13 , int V_24 )
{
struct V_11 * V_23 ;
F_23 ( L_14 , V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
if ( F_70 ( V_348 , & V_23 -> V_103 ) )
F_26 ( V_23 , V_24 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static void F_147 ( struct V_64 * V_65 )
{
struct V_12 * V_13 = F_46 ( V_65 , struct V_12 ,
V_305 . V_65 ) ;
V_13 -> V_301 |= V_308 ;
V_13 -> V_304 = 0 ;
F_140 ( V_13 ) ;
}
int F_148 ( struct V_12 * V_13 , struct V_349 * V_350 )
{
struct V_261 * V_189 = V_13 -> V_8 -> V_189 ;
int V_351 ;
F_149 ( V_189 ) ;
if ( ! F_150 ( & V_350 -> V_57 ) ) {
V_351 = - V_29 ;
goto V_352;
}
if ( ! V_13 -> V_196 ) {
V_351 = - V_353 ;
goto V_352;
}
V_351 = V_350 -> V_354 ( V_13 , V_350 ) ;
if ( V_351 )
goto V_352;
F_54 ( & V_350 -> V_57 , & V_13 -> V_355 ) ;
V_351 = 0 ;
V_352:
F_151 ( V_189 ) ;
return V_351 ;
}
void F_152 ( struct V_12 * V_13 , struct V_349 * V_350 )
{
struct V_261 * V_189 = V_13 -> V_8 -> V_189 ;
F_149 ( V_189 ) ;
if ( F_150 ( & V_350 -> V_57 ) )
goto V_352;
F_153 ( & V_350 -> V_57 ) ;
V_350 -> remove ( V_13 , V_350 ) ;
V_352:
F_151 ( V_189 ) ;
}
static void F_154 ( struct V_12 * V_13 )
{
struct V_349 * V_350 ;
while ( ! F_150 ( & V_13 -> V_355 ) ) {
V_350 = F_155 ( & V_13 -> V_355 , struct V_349 , V_57 ) ;
F_153 ( & V_350 -> V_57 ) ;
V_350 -> remove ( V_13 , V_350 ) ;
}
}
static void F_156 ( struct V_7 * V_8 , int V_24 )
{
struct V_12 * V_13 = V_8 -> V_356 ;
struct V_11 * V_23 , * V_357 ;
if ( ! V_13 )
return;
F_23 ( L_16 , V_8 , V_13 , V_24 ) ;
F_97 ( V_13 -> V_358 ) ;
F_77 ( & V_13 -> V_359 ) ;
if ( F_157 ( & V_13 -> V_347 ) )
F_158 ( & V_13 -> V_347 ) ;
if ( F_157 ( & V_13 -> V_149 ) )
F_158 ( & V_13 -> V_149 ) ;
F_154 ( V_13 ) ;
V_8 -> V_360 = 0 ;
F_8 ( & V_13 -> V_18 ) ;
F_141 (chan, l, &conn->chan_l, list) {
F_60 ( V_23 ) ;
F_9 ( V_23 ) ;
F_73 ( V_23 , V_24 ) ;
F_48 ( V_23 ) ;
V_23 -> V_39 -> V_75 ( V_23 ) ;
F_49 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
F_159 ( V_13 -> V_196 ) ;
if ( V_13 -> V_301 & V_302 )
F_160 ( & V_13 -> V_305 ) ;
V_8 -> V_356 = NULL ;
V_13 -> V_196 = NULL ;
F_161 ( V_13 ) ;
}
static void F_162 ( struct V_83 * V_361 )
{
struct V_12 * V_13 = F_46 ( V_361 , struct V_12 , V_361 ) ;
F_163 ( V_13 -> V_8 ) ;
F_40 ( V_13 ) ;
}
struct V_12 * F_164 ( struct V_12 * V_13 )
{
F_62 ( & V_13 -> V_361 ) ;
return V_13 ;
}
void F_161 ( struct V_12 * V_13 )
{
F_63 ( & V_13 -> V_361 , F_162 ) ;
}
static struct V_11 * F_165 ( int V_38 , T_3 V_20 ,
T_4 * V_21 ,
T_4 * V_150 ,
T_1 V_1 )
{
struct V_11 * V_15 , * V_362 = NULL ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
if ( V_38 && V_15 -> V_38 != V_38 )
continue;
if ( V_1 == V_117 && V_15 -> V_9 != V_6 )
continue;
if ( V_1 == V_2 && V_15 -> V_9 == V_6 )
continue;
if ( V_15 -> V_20 == V_20 ) {
int V_363 , V_364 ;
int V_365 , V_366 ;
V_363 = ! F_15 ( & V_15 -> V_21 , V_21 ) ;
V_364 = ! F_15 ( & V_15 -> V_150 , V_150 ) ;
if ( V_363 && V_364 ) {
F_60 ( V_15 ) ;
F_123 ( & V_25 ) ;
return V_15 ;
}
V_365 = ! F_15 ( & V_15 -> V_21 , V_367 ) ;
V_366 = ! F_15 ( & V_15 -> V_150 , V_367 ) ;
if ( ( V_363 && V_366 ) || ( V_365 && V_364 ) ||
( V_365 && V_366 ) )
V_362 = V_15 ;
}
}
if ( V_362 )
F_60 ( V_362 ) ;
F_123 ( & V_25 ) ;
return V_362 ;
}
static void F_166 ( struct V_64 * V_65 )
{
struct V_11 * V_23 = F_46 ( V_65 , struct V_11 ,
V_41 . V_65 ) ;
F_23 ( L_3 , V_23 ) ;
F_9 ( V_23 ) ;
if ( ! V_23 -> V_13 ) {
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
return;
}
F_129 ( V_23 , NULL , NULL , V_368 ) ;
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
}
static void F_167 ( struct V_64 * V_65 )
{
struct V_11 * V_23 = F_46 ( V_65 , struct V_11 ,
V_43 . V_65 ) ;
F_23 ( L_3 , V_23 ) ;
F_9 ( V_23 ) ;
if ( ! V_23 -> V_13 ) {
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
return;
}
F_129 ( V_23 , NULL , NULL , V_369 ) ;
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
}
static void F_168 ( struct V_11 * V_23 ,
struct V_46 * V_370 )
{
struct V_45 * V_49 ;
struct V_204 * V_205 ;
F_23 ( L_17 , V_23 , V_370 ) ;
if ( F_95 ( V_23 ) )
return;
F_169 ( V_370 , & V_23 -> V_113 ) ;
while ( ! F_170 ( & V_23 -> V_113 ) ) {
V_49 = F_171 ( & V_23 -> V_113 ) ;
F_35 ( V_49 ) -> V_50 . V_279 = 1 ;
V_205 = & F_35 ( V_49 ) -> V_50 ;
V_205 -> V_206 = 0 ;
V_205 -> V_51 = V_23 -> V_371 ;
F_106 ( V_23 , V_205 , V_49 ) ;
if ( V_23 -> V_87 == V_88 ) {
T_2 V_87 = F_114 ( 0 , ( T_1 * ) V_49 -> V_188 , V_49 -> V_187 ) ;
F_108 ( V_87 , F_113 ( V_49 , V_249 ) ) ;
}
F_96 ( V_23 , V_49 ) ;
F_23 ( L_18 , V_205 -> V_51 ) ;
V_23 -> V_371 = F_172 ( V_23 , V_23 -> V_371 ) ;
V_23 -> V_372 ++ ;
}
}
static int F_173 ( struct V_11 * V_23 )
{
struct V_45 * V_49 , * V_373 ;
struct V_204 * V_205 ;
int V_374 = 0 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_38 != V_68 )
return - V_375 ;
if ( F_70 ( V_287 , & V_23 -> V_252 ) )
return 0 ;
if ( F_95 ( V_23 ) )
return 0 ;
while ( V_23 -> V_376 &&
V_23 -> V_377 < V_23 -> V_95 &&
V_23 -> V_283 == V_284 ) {
V_49 = V_23 -> V_376 ;
F_35 ( V_49 ) -> V_50 . V_279 = 1 ;
V_205 = & F_35 ( V_49 ) -> V_50 ;
if ( F_116 ( V_251 , & V_23 -> V_252 ) )
V_205 -> V_209 = 1 ;
V_205 -> V_206 = V_23 -> V_259 ;
V_23 -> V_257 = V_23 -> V_259 ;
V_205 -> V_51 = V_23 -> V_371 ;
F_106 ( V_23 , V_205 , V_49 ) ;
if ( V_23 -> V_87 == V_88 ) {
T_2 V_87 = F_114 ( 0 , ( T_1 * ) V_49 -> V_188 , V_49 -> V_187 ) ;
F_108 ( V_87 , F_113 ( V_49 , V_249 ) ) ;
}
V_373 = F_174 ( V_49 , V_58 ) ;
if ( ! V_373 )
break;
F_27 ( V_23 ) ;
V_23 -> V_371 = F_172 ( V_23 , V_23 -> V_371 ) ;
V_23 -> V_377 ++ ;
V_23 -> V_372 ++ ;
V_374 ++ ;
if ( F_175 ( & V_23 -> V_113 , V_49 ) )
V_23 -> V_376 = NULL ;
else
V_23 -> V_376 = F_176 ( & V_23 -> V_113 , V_49 ) ;
F_96 ( V_23 , V_373 ) ;
F_23 ( L_18 , V_205 -> V_51 ) ;
}
F_23 ( L_19 , V_374 ,
V_23 -> V_377 , F_177 ( & V_23 -> V_113 ) ) ;
return V_374 ;
}
static void F_178 ( struct V_11 * V_23 )
{
struct V_204 V_205 ;
struct V_45 * V_49 ;
struct V_45 * V_373 ;
T_2 V_48 ;
F_23 ( L_3 , V_23 ) ;
if ( F_70 ( V_287 , & V_23 -> V_252 ) )
return;
if ( F_95 ( V_23 ) )
return;
while ( V_23 -> V_147 . V_47 != V_61 ) {
V_48 = F_42 ( & V_23 -> V_147 ) ;
V_49 = F_33 ( & V_23 -> V_113 , V_48 ) ;
if ( ! V_49 ) {
F_23 ( L_20 ,
V_48 ) ;
continue;
}
F_35 ( V_49 ) -> V_50 . V_279 ++ ;
V_205 = F_35 ( V_49 ) -> V_50 ;
if ( V_23 -> V_89 != 0 &&
F_35 ( V_49 ) -> V_50 . V_279 > V_23 -> V_89 ) {
F_23 ( L_21 , V_23 -> V_89 ) ;
F_86 ( V_23 , V_320 ) ;
F_43 ( & V_23 -> V_147 ) ;
break;
}
V_205 . V_206 = V_23 -> V_259 ;
if ( F_116 ( V_251 , & V_23 -> V_252 ) )
V_205 . V_209 = 1 ;
else
V_205 . V_209 = 0 ;
if ( F_179 ( V_49 ) ) {
V_373 = F_180 ( V_49 , V_58 ) ;
} else {
V_373 = F_174 ( V_49 , V_58 ) ;
}
if ( ! V_373 ) {
F_43 ( & V_23 -> V_147 ) ;
break;
}
if ( F_70 ( V_239 , & V_23 -> V_103 ) ) {
F_107 ( F_104 ( & V_205 ) ,
V_373 -> V_188 + V_243 ) ;
} else {
F_108 ( F_105 ( & V_205 ) ,
V_373 -> V_188 + V_243 ) ;
}
if ( V_23 -> V_87 == V_88 ) {
T_2 V_87 = F_114 ( 0 , ( T_1 * ) V_373 -> V_188 ,
V_373 -> V_187 - V_249 ) ;
F_108 ( V_87 , F_181 ( V_373 ) -
V_249 ) ;
}
F_96 ( V_23 , V_373 ) ;
F_23 ( L_22 , V_205 . V_51 ) ;
V_23 -> V_257 = V_23 -> V_259 ;
}
}
static void F_182 ( struct V_11 * V_23 ,
struct V_204 * V_205 )
{
F_23 ( L_10 , V_23 , V_205 ) ;
F_44 ( & V_23 -> V_147 , V_205 -> V_206 ) ;
F_178 ( V_23 ) ;
}
static void F_183 ( struct V_11 * V_23 ,
struct V_204 * V_205 )
{
struct V_45 * V_49 ;
F_23 ( L_10 , V_23 , V_205 ) ;
if ( V_205 -> V_214 )
F_57 ( V_251 , & V_23 -> V_252 ) ;
F_43 ( & V_23 -> V_147 ) ;
if ( F_70 ( V_287 , & V_23 -> V_252 ) )
return;
if ( V_23 -> V_377 ) {
F_34 (&chan->tx_q, skb) {
if ( F_35 ( V_49 ) -> V_50 . V_51 == V_205 -> V_206 ||
V_49 == V_23 -> V_376 )
break;
}
F_184 (&chan->tx_q, skb) {
if ( V_49 == V_23 -> V_376 )
break;
F_44 ( & V_23 -> V_147 ,
F_35 ( V_49 ) -> V_50 . V_51 ) ;
}
F_178 ( V_23 ) ;
}
}
static void F_185 ( struct V_11 * V_23 )
{
struct V_204 V_205 ;
T_2 V_378 = F_186 ( V_23 , V_23 -> V_259 ,
V_23 -> V_257 ) ;
int V_379 ;
F_23 ( L_23 ,
V_23 , V_23 -> V_257 , V_23 -> V_259 ) ;
memset ( & V_205 , 0 , sizeof( V_205 ) ) ;
V_205 . V_213 = 1 ;
if ( F_70 ( V_258 , & V_23 -> V_252 ) &&
V_23 -> V_285 == V_380 ) {
F_79 ( V_23 ) ;
V_205 . V_217 = V_255 ;
V_205 . V_206 = V_23 -> V_259 ;
F_115 ( V_23 , & V_205 ) ;
} else {
if ( ! F_70 ( V_287 , & V_23 -> V_252 ) ) {
F_173 ( V_23 ) ;
if ( V_23 -> V_259 == V_23 -> V_257 )
V_378 = 0 ;
}
V_379 = V_23 -> V_96 ;
V_379 += V_379 << 1 ;
V_379 >>= 2 ;
F_23 ( L_24 , V_378 ,
V_379 ) ;
if ( V_378 >= V_379 ) {
F_79 ( V_23 ) ;
V_205 . V_217 = V_253 ;
V_205 . V_206 = V_23 -> V_259 ;
F_115 ( V_23 , & V_205 ) ;
V_378 = 0 ;
}
if ( V_378 )
F_187 ( V_23 ) ;
}
}
static inline int F_188 ( struct V_11 * V_23 ,
struct V_381 * V_382 , int V_187 ,
int V_383 , struct V_45 * V_49 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_45 * * V_384 ;
int V_374 = 0 ;
if ( F_189 ( F_113 ( V_49 , V_383 ) , V_383 , & V_382 -> V_385 ) != V_383 )
return - V_386 ;
V_374 += V_383 ;
V_187 -= V_383 ;
V_384 = & F_190 ( V_49 ) -> V_387 ;
while ( V_187 ) {
struct V_45 * V_318 ;
V_383 = F_66 (unsigned int, conn->mtu, len) ;
V_318 = V_23 -> V_39 -> V_388 ( V_23 , 0 , V_383 ,
V_382 -> V_389 & V_390 ) ;
if ( F_118 ( V_318 ) )
return F_191 ( V_318 ) ;
* V_384 = V_318 ;
if ( F_189 ( F_113 ( * V_384 , V_383 ) , V_383 ,
& V_382 -> V_385 ) != V_383 )
return - V_386 ;
V_374 += V_383 ;
V_187 -= V_383 ;
V_49 -> V_187 += ( * V_384 ) -> V_187 ;
V_49 -> V_391 += ( * V_384 ) -> V_187 ;
V_384 = & ( * V_384 ) -> V_392 ;
}
return V_374 ;
}
static struct V_45 * F_192 ( struct V_11 * V_23 ,
struct V_381 * V_382 , T_6 V_187 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_45 * V_49 ;
int V_24 , V_383 , V_248 = V_243 + V_393 ;
struct V_246 * V_247 ;
F_23 ( L_25 , V_23 ,
F_69 ( V_23 -> V_20 ) , V_187 ) ;
V_383 = F_66 (unsigned int, (conn->mtu - hlen), len) ;
V_49 = V_23 -> V_39 -> V_388 ( V_23 , V_248 , V_383 ,
V_382 -> V_389 & V_390 ) ;
if ( F_118 ( V_49 ) )
return V_49 ;
V_247 = (struct V_246 * ) F_113 ( V_49 , V_243 ) ;
V_247 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_247 -> V_187 = F_18 ( V_187 + V_393 ) ;
F_193 ( V_23 -> V_20 , ( T_3 * ) F_113 ( V_49 , V_393 ) ) ;
V_24 = F_188 ( V_23 , V_382 , V_187 , V_383 , V_49 ) ;
if ( F_194 ( V_24 < 0 ) ) {
F_97 ( V_49 ) ;
return F_112 ( V_24 ) ;
}
return V_49 ;
}
static struct V_45 * F_195 ( struct V_11 * V_23 ,
struct V_381 * V_382 , T_6 V_187 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_45 * V_49 ;
int V_24 , V_383 ;
struct V_246 * V_247 ;
F_23 ( L_26 , V_23 , V_187 ) ;
V_383 = F_66 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_49 = V_23 -> V_39 -> V_388 ( V_23 , V_243 , V_383 ,
V_382 -> V_389 & V_390 ) ;
if ( F_118 ( V_49 ) )
return V_49 ;
V_247 = (struct V_246 * ) F_113 ( V_49 , V_243 ) ;
V_247 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_247 -> V_187 = F_18 ( V_187 ) ;
V_24 = F_188 ( V_23 , V_382 , V_187 , V_383 , V_49 ) ;
if ( F_194 ( V_24 < 0 ) ) {
F_97 ( V_49 ) ;
return F_112 ( V_24 ) ;
}
return V_49 ;
}
static struct V_45 * F_196 ( struct V_11 * V_23 ,
struct V_381 * V_382 , T_6 V_187 ,
T_2 V_394 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_45 * V_49 ;
int V_24 , V_383 , V_248 ;
struct V_246 * V_247 ;
F_23 ( L_26 , V_23 , V_187 ) ;
if ( ! V_13 )
return F_112 ( - V_375 ) ;
V_248 = F_109 ( V_23 ) ;
if ( V_394 )
V_248 += V_395 ;
if ( V_23 -> V_87 == V_88 )
V_248 += V_249 ;
V_383 = F_66 (unsigned int, (conn->mtu - hlen), len) ;
V_49 = V_23 -> V_39 -> V_388 ( V_23 , V_248 , V_383 ,
V_382 -> V_389 & V_390 ) ;
if ( F_118 ( V_49 ) )
return V_49 ;
V_247 = (struct V_246 * ) F_113 ( V_49 , V_243 ) ;
V_247 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_247 -> V_187 = F_18 ( V_187 + ( V_248 - V_243 ) ) ;
if ( F_70 ( V_239 , & V_23 -> V_103 ) )
F_107 ( 0 , F_113 ( V_49 , V_240 ) ) ;
else
F_108 ( 0 , F_113 ( V_49 , V_241 ) ) ;
if ( V_394 )
F_108 ( V_394 , F_113 ( V_49 , V_395 ) ) ;
V_24 = F_188 ( V_23 , V_382 , V_187 , V_383 , V_49 ) ;
if ( F_194 ( V_24 < 0 ) ) {
F_97 ( V_49 ) ;
return F_112 ( V_24 ) ;
}
F_35 ( V_49 ) -> V_50 . V_87 = V_23 -> V_87 ;
F_35 ( V_49 ) -> V_50 . V_279 = 0 ;
return V_49 ;
}
static int F_197 ( struct V_11 * V_23 ,
struct V_46 * V_396 ,
struct V_381 * V_382 , T_6 V_187 )
{
struct V_45 * V_49 ;
T_2 V_106 ;
T_6 V_397 ;
T_1 V_220 ;
F_23 ( L_27 , V_23 , V_382 , V_187 ) ;
V_397 = V_23 -> V_13 -> V_158 ;
if ( ! V_23 -> V_200 )
V_397 = F_66 ( T_6 , V_397 , V_398 ) ;
if ( V_23 -> V_87 )
V_397 -= V_249 ;
V_397 -= F_109 ( V_23 ) ;
V_397 = F_66 ( T_6 , V_397 , V_23 -> V_399 ) ;
if ( V_187 <= V_397 ) {
V_220 = V_400 ;
V_106 = 0 ;
V_397 = V_187 ;
} else {
V_220 = V_401 ;
V_106 = V_187 ;
}
while ( V_187 > 0 ) {
V_49 = F_196 ( V_23 , V_382 , V_397 , V_106 ) ;
if ( F_118 ( V_49 ) ) {
F_198 ( V_396 ) ;
return F_191 ( V_49 ) ;
}
F_35 ( V_49 ) -> V_50 . V_220 = V_220 ;
F_199 ( V_396 , V_49 ) ;
V_187 -= V_397 ;
if ( V_106 )
V_106 = 0 ;
if ( V_187 <= V_397 ) {
V_220 = V_402 ;
V_397 = V_187 ;
} else {
V_220 = V_403 ;
}
}
return 0 ;
}
static struct V_45 * F_200 ( struct V_11 * V_23 ,
struct V_381 * V_382 ,
T_6 V_187 , T_2 V_394 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_45 * V_49 ;
int V_24 , V_383 , V_248 ;
struct V_246 * V_247 ;
F_23 ( L_26 , V_23 , V_187 ) ;
if ( ! V_13 )
return F_112 ( - V_375 ) ;
V_248 = V_243 ;
if ( V_394 )
V_248 += V_395 ;
V_383 = F_66 (unsigned int, (conn->mtu - hlen), len) ;
V_49 = V_23 -> V_39 -> V_388 ( V_23 , V_248 , V_383 ,
V_382 -> V_389 & V_390 ) ;
if ( F_118 ( V_49 ) )
return V_49 ;
V_247 = (struct V_246 * ) F_113 ( V_49 , V_243 ) ;
V_247 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_247 -> V_187 = F_18 ( V_187 + ( V_248 - V_243 ) ) ;
if ( V_394 )
F_108 ( V_394 , F_113 ( V_49 , V_395 ) ) ;
V_24 = F_188 ( V_23 , V_382 , V_187 , V_383 , V_49 ) ;
if ( F_194 ( V_24 < 0 ) ) {
F_97 ( V_49 ) ;
return F_112 ( V_24 ) ;
}
return V_49 ;
}
static int F_201 ( struct V_11 * V_23 ,
struct V_46 * V_396 ,
struct V_381 * V_382 , T_6 V_187 )
{
struct V_45 * V_49 ;
T_6 V_397 ;
T_2 V_106 ;
F_23 ( L_27 , V_23 , V_382 , V_187 ) ;
V_106 = V_187 ;
V_397 = V_23 -> V_399 - V_395 ;
while ( V_187 > 0 ) {
if ( V_187 <= V_397 )
V_397 = V_187 ;
V_49 = F_200 ( V_23 , V_382 , V_397 , V_106 ) ;
if ( F_118 ( V_49 ) ) {
F_198 ( V_396 ) ;
return F_191 ( V_49 ) ;
}
F_199 ( V_396 , V_49 ) ;
V_187 -= V_397 ;
if ( V_106 ) {
V_106 = 0 ;
V_397 += V_395 ;
}
}
return 0 ;
}
int F_202 ( struct V_11 * V_23 , struct V_381 * V_382 , T_6 V_187 )
{
struct V_45 * V_49 ;
int V_24 ;
struct V_46 V_396 ;
if ( ! V_23 -> V_13 )
return - V_375 ;
if ( V_23 -> V_32 == V_118 ) {
V_49 = F_192 ( V_23 , V_382 , V_187 ) ;
if ( F_118 ( V_49 ) )
return F_191 ( V_49 ) ;
if ( V_23 -> V_38 != V_68 ) {
F_97 ( V_49 ) ;
return - V_375 ;
}
F_96 ( V_23 , V_49 ) ;
return V_187 ;
}
switch ( V_23 -> V_141 ) {
case V_143 :
if ( V_187 > V_23 -> V_30 )
return - V_404 ;
if ( ! V_23 -> V_107 )
return - V_405 ;
F_203 ( & V_396 ) ;
V_24 = F_201 ( V_23 , & V_396 , V_382 , V_187 ) ;
if ( V_23 -> V_38 != V_68 ) {
F_198 ( & V_396 ) ;
V_24 = - V_375 ;
}
if ( V_24 )
return V_24 ;
F_169 ( & V_396 , & V_23 -> V_113 ) ;
while ( V_23 -> V_107 && ! F_170 ( & V_23 -> V_113 ) ) {
F_96 ( V_23 , F_171 ( & V_23 -> V_113 ) ) ;
V_23 -> V_107 -- ;
}
if ( ! V_23 -> V_107 )
V_23 -> V_39 -> V_295 ( V_23 ) ;
V_24 = V_187 ;
break;
case V_142 :
if ( V_187 > V_23 -> V_30 )
return - V_404 ;
V_49 = F_195 ( V_23 , V_382 , V_187 ) ;
if ( F_118 ( V_49 ) )
return F_191 ( V_49 ) ;
if ( V_23 -> V_38 != V_68 ) {
F_97 ( V_49 ) ;
return - V_375 ;
}
F_96 ( V_23 , V_49 ) ;
V_24 = V_187 ;
break;
case V_144 :
case V_148 :
if ( V_187 > V_23 -> V_30 ) {
V_24 = - V_404 ;
break;
}
F_203 ( & V_396 ) ;
V_24 = F_197 ( V_23 , & V_396 , V_382 , V_187 ) ;
if ( V_23 -> V_38 != V_68 ) {
F_198 ( & V_396 ) ;
V_24 = - V_375 ;
}
if ( V_24 )
break;
if ( V_23 -> V_141 == V_144 )
F_129 ( V_23 , NULL , & V_396 , V_406 ) ;
else
F_168 ( V_23 , & V_396 ) ;
V_24 = V_187 ;
F_198 ( & V_396 ) ;
break;
default:
F_23 ( L_28 , V_23 -> V_141 ) ;
V_24 = - V_407 ;
}
return V_24 ;
}
static void F_204 ( struct V_11 * V_23 , T_2 V_51 )
{
struct V_204 V_205 ;
T_2 V_48 ;
F_23 ( L_29 , V_23 , V_51 ) ;
memset ( & V_205 , 0 , sizeof( V_205 ) ) ;
V_205 . V_213 = 1 ;
V_205 . V_217 = V_256 ;
for ( V_48 = V_23 -> V_280 ; V_48 != V_51 ;
V_48 = F_172 ( V_23 , V_48 ) ) {
if ( ! F_33 ( & V_23 -> V_145 , V_48 ) ) {
V_205 . V_206 = V_48 ;
F_115 ( V_23 , & V_205 ) ;
F_44 ( & V_23 -> V_146 , V_48 ) ;
}
}
V_23 -> V_280 = F_172 ( V_23 , V_51 ) ;
}
static void F_205 ( struct V_11 * V_23 )
{
struct V_204 V_205 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_146 . V_62 == V_61 )
return;
memset ( & V_205 , 0 , sizeof( V_205 ) ) ;
V_205 . V_213 = 1 ;
V_205 . V_217 = V_256 ;
V_205 . V_206 = V_23 -> V_146 . V_62 ;
F_115 ( V_23 , & V_205 ) ;
}
static void F_206 ( struct V_11 * V_23 , T_2 V_51 )
{
struct V_204 V_205 ;
T_2 V_408 ;
T_2 V_48 ;
F_23 ( L_29 , V_23 , V_51 ) ;
memset ( & V_205 , 0 , sizeof( V_205 ) ) ;
V_205 . V_213 = 1 ;
V_205 . V_217 = V_256 ;
V_408 = V_23 -> V_146 . V_47 ;
do {
V_48 = F_42 ( & V_23 -> V_146 ) ;
if ( V_48 == V_51 || V_48 == V_61 )
break;
V_205 . V_206 = V_48 ;
F_115 ( V_23 , & V_205 ) ;
F_44 ( & V_23 -> V_146 , V_48 ) ;
} while ( V_23 -> V_146 . V_47 != V_408 );
}
static void F_207 ( struct V_11 * V_23 , T_2 V_206 )
{
struct V_45 * V_409 ;
T_2 V_410 ;
F_23 ( L_30 , V_23 , V_206 ) ;
if ( V_23 -> V_377 == 0 || V_206 == V_23 -> V_411 )
return;
F_23 ( L_31 ,
V_23 -> V_411 , V_23 -> V_377 ) ;
for ( V_410 = V_23 -> V_411 ; V_410 != V_206 ;
V_410 = F_172 ( V_23 , V_410 ) ) {
V_409 = F_33 ( & V_23 -> V_113 , V_410 ) ;
if ( V_409 ) {
F_208 ( V_409 , & V_23 -> V_113 ) ;
F_97 ( V_409 ) ;
V_23 -> V_377 -- ;
}
}
V_23 -> V_411 = V_206 ;
if ( V_23 -> V_377 == 0 )
F_32 ( V_23 ) ;
F_23 ( L_32 , V_23 -> V_377 ) ;
}
static void F_209 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
V_23 -> V_280 = V_23 -> V_259 ;
F_43 ( & V_23 -> V_146 ) ;
F_77 ( & V_23 -> V_145 ) ;
V_23 -> V_285 = V_380 ;
}
static void F_210 ( struct V_11 * V_23 ,
struct V_204 * V_205 ,
struct V_46 * V_370 , T_1 V_412 )
{
F_23 ( L_33 , V_23 , V_205 , V_370 ,
V_412 ) ;
switch ( V_412 ) {
case V_406 :
if ( V_23 -> V_376 == NULL )
V_23 -> V_376 = F_211 ( V_370 ) ;
F_169 ( V_370 , & V_23 -> V_113 ) ;
F_173 ( V_23 ) ;
break;
case V_413 :
F_23 ( L_34 ) ;
F_57 ( V_258 , & V_23 -> V_252 ) ;
if ( V_23 -> V_285 == V_414 ) {
F_209 ( V_23 ) ;
}
F_185 ( V_23 ) ;
break;
case V_415 :
F_23 ( L_35 ) ;
F_117 ( V_258 , & V_23 -> V_252 ) ;
if ( F_70 ( V_254 , & V_23 -> V_252 ) ) {
struct V_204 V_416 ;
memset ( & V_416 , 0 , sizeof( V_416 ) ) ;
V_416 . V_213 = 1 ;
V_416 . V_217 = V_253 ;
V_416 . V_214 = 1 ;
V_416 . V_206 = V_23 -> V_259 ;
F_115 ( V_23 , & V_416 ) ;
V_23 -> V_278 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_283 = V_417 ;
}
break;
case V_418 :
F_207 ( V_23 , V_205 -> V_206 ) ;
break;
case V_291 :
F_119 ( V_23 , 1 ) ;
V_23 -> V_278 = 1 ;
F_31 ( V_23 ) ;
F_79 ( V_23 ) ;
V_23 -> V_283 = V_417 ;
break;
case V_369 :
F_119 ( V_23 , 1 ) ;
V_23 -> V_278 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_283 = V_417 ;
break;
case V_419 :
break;
default:
break;
}
}
static void F_212 ( struct V_11 * V_23 ,
struct V_204 * V_205 ,
struct V_46 * V_370 , T_1 V_412 )
{
F_23 ( L_33 , V_23 , V_205 , V_370 ,
V_412 ) ;
switch ( V_412 ) {
case V_406 :
if ( V_23 -> V_376 == NULL )
V_23 -> V_376 = F_211 ( V_370 ) ;
F_169 ( V_370 , & V_23 -> V_113 ) ;
break;
case V_413 :
F_23 ( L_34 ) ;
F_57 ( V_258 , & V_23 -> V_252 ) ;
if ( V_23 -> V_285 == V_414 ) {
F_209 ( V_23 ) ;
}
F_185 ( V_23 ) ;
break;
case V_415 :
F_23 ( L_35 ) ;
F_117 ( V_258 , & V_23 -> V_252 ) ;
if ( F_70 ( V_254 , & V_23 -> V_252 ) ) {
struct V_204 V_416 ;
memset ( & V_416 , 0 , sizeof( V_416 ) ) ;
V_416 . V_213 = 1 ;
V_416 . V_217 = V_253 ;
V_416 . V_214 = 1 ;
V_416 . V_206 = V_23 -> V_259 ;
F_115 ( V_23 , & V_416 ) ;
V_23 -> V_278 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_283 = V_417 ;
}
break;
case V_418 :
F_207 ( V_23 , V_205 -> V_206 ) ;
case V_419 :
if ( V_205 && V_205 -> V_209 ) {
F_78 ( V_23 ) ;
if ( V_23 -> V_377 > 0 )
F_27 ( V_23 ) ;
V_23 -> V_278 = 0 ;
V_23 -> V_283 = V_284 ;
F_23 ( L_36 , V_23 -> V_283 ) ;
}
break;
case V_291 :
break;
case V_368 :
if ( V_23 -> V_89 == 0 || V_23 -> V_278 < V_23 -> V_89 ) {
F_119 ( V_23 , 1 ) ;
F_31 ( V_23 ) ;
V_23 -> V_278 ++ ;
} else {
F_86 ( V_23 , V_420 ) ;
}
break;
default:
break;
}
}
static void F_129 ( struct V_11 * V_23 , struct V_204 * V_205 ,
struct V_46 * V_370 , T_1 V_412 )
{
F_23 ( L_37 ,
V_23 , V_205 , V_370 , V_412 , V_23 -> V_283 ) ;
switch ( V_23 -> V_283 ) {
case V_284 :
F_210 ( V_23 , V_205 , V_370 , V_412 ) ;
break;
case V_417 :
F_212 ( V_23 , V_205 , V_370 , V_412 ) ;
break;
default:
break;
}
}
static void F_213 ( struct V_11 * V_23 ,
struct V_204 * V_205 )
{
F_23 ( L_10 , V_23 , V_205 ) ;
F_129 ( V_23 , V_205 , NULL , V_418 ) ;
}
static void F_214 ( struct V_11 * V_23 ,
struct V_204 * V_205 )
{
F_23 ( L_10 , V_23 , V_205 ) ;
F_129 ( V_23 , V_205 , NULL , V_419 ) ;
}
static void F_215 ( struct V_12 * V_13 , struct V_45 * V_49 )
{
struct V_45 * V_421 ;
struct V_11 * V_23 ;
F_23 ( L_14 , V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
if ( V_23 -> V_32 != V_169 )
continue;
if ( F_35 ( V_49 ) -> V_50 . V_23 == V_23 )
continue;
V_421 = F_174 ( V_49 , V_58 ) ;
if ( ! V_421 )
continue;
if ( V_23 -> V_39 -> V_422 ( V_23 , V_421 ) )
F_97 ( V_421 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static struct V_45 * F_92 ( struct V_12 * V_13 , T_1 V_186 ,
T_1 V_19 , T_2 V_423 , void * V_188 )
{
struct V_45 * V_49 , * * V_384 ;
struct V_424 * V_425 ;
struct V_246 * V_247 ;
int V_187 , V_383 ;
F_23 ( L_38 ,
V_13 , V_186 , V_19 , V_423 ) ;
if ( V_13 -> V_158 < V_243 + V_426 )
return NULL ;
V_187 = V_243 + V_426 + V_423 ;
V_383 = F_66 (unsigned int, conn->mtu, len) ;
V_49 = F_111 ( V_383 , V_58 ) ;
if ( ! V_49 )
return NULL ;
V_247 = (struct V_246 * ) F_113 ( V_49 , V_243 ) ;
V_247 -> V_187 = F_18 ( V_426 + V_423 ) ;
if ( V_13 -> V_8 -> type == V_2 )
V_247 -> V_14 = F_18 ( V_427 ) ;
else
V_247 -> V_14 = F_18 ( V_120 ) ;
V_425 = (struct V_424 * ) F_113 ( V_49 , V_426 ) ;
V_425 -> V_186 = V_186 ;
V_425 -> V_19 = V_19 ;
V_425 -> V_187 = F_18 ( V_423 ) ;
if ( V_423 ) {
V_383 -= V_243 + V_426 ;
memcpy ( F_113 ( V_49 , V_383 ) , V_188 , V_383 ) ;
V_188 += V_383 ;
}
V_187 -= V_49 -> V_187 ;
V_384 = & F_190 ( V_49 ) -> V_387 ;
while ( V_187 ) {
V_383 = F_66 (unsigned int, conn->mtu, len) ;
* V_384 = F_111 ( V_383 , V_58 ) ;
if ( ! * V_384 )
goto V_428;
memcpy ( F_113 ( * V_384 , V_383 ) , V_188 , V_383 ) ;
V_187 -= V_383 ;
V_188 += V_383 ;
V_384 = & ( * V_384 ) -> V_392 ;
}
return V_49 ;
V_428:
F_97 ( V_49 ) ;
return NULL ;
}
static inline int F_216 ( void * * V_429 , int * type , int * V_430 ,
unsigned long * V_431 )
{
struct V_432 * V_433 = * V_429 ;
int V_187 ;
V_187 = V_434 + V_433 -> V_187 ;
* V_429 += V_187 ;
* type = V_433 -> type ;
* V_430 = V_433 -> V_187 ;
switch ( V_433 -> V_187 ) {
case 1 :
* V_431 = * ( ( T_1 * ) V_433 -> V_431 ) ;
break;
case 2 :
* V_431 = F_103 ( V_433 -> V_431 ) ;
break;
case 4 :
* V_431 = F_101 ( V_433 -> V_431 ) ;
break;
default:
* V_431 = ( unsigned long ) V_433 -> V_431 ;
break;
}
F_23 ( L_39 , * type , V_433 -> V_187 , * V_431 ) ;
return V_187 ;
}
static void F_217 ( void * * V_429 , T_1 type , T_1 V_187 , unsigned long V_431 )
{
struct V_432 * V_433 = * V_429 ;
F_23 ( L_39 , type , V_187 , V_431 ) ;
V_433 -> type = type ;
V_433 -> V_187 = V_187 ;
switch ( V_187 ) {
case 1 :
* ( ( T_1 * ) V_433 -> V_431 ) = V_431 ;
break;
case 2 :
F_108 ( V_431 , V_433 -> V_431 ) ;
break;
case 4 :
F_107 ( V_431 , V_433 -> V_431 ) ;
break;
default:
memcpy ( V_433 -> V_431 , ( void * ) V_431 , V_187 ) ;
break;
}
* V_429 += V_434 + V_187 ;
}
static void F_218 ( void * * V_429 , struct V_11 * V_23 )
{
struct V_435 V_436 ;
switch ( V_23 -> V_141 ) {
case V_144 :
V_436 . V_183 = V_23 -> V_121 ;
V_436 . V_437 = V_23 -> V_123 ;
V_436 . V_438 = F_18 ( V_23 -> V_125 ) ;
V_436 . V_439 = F_219 ( V_23 -> V_127 ) ;
V_436 . V_440 = F_219 ( V_130 ) ;
V_436 . V_98 = F_219 ( V_132 ) ;
break;
case V_148 :
V_436 . V_183 = 1 ;
V_436 . V_437 = V_124 ;
V_436 . V_438 = F_18 ( V_23 -> V_125 ) ;
V_436 . V_439 = F_219 ( V_23 -> V_127 ) ;
V_436 . V_440 = 0 ;
V_436 . V_98 = 0 ;
break;
default:
return;
}
F_217 ( V_429 , V_441 , sizeof( V_436 ) ,
( unsigned long ) & V_436 ) ;
}
static void F_220 ( struct V_64 * V_65 )
{
struct V_11 * V_23 = F_46 ( V_65 , struct V_11 ,
V_442 . V_65 ) ;
T_2 V_378 ;
F_23 ( L_3 , V_23 ) ;
F_9 ( V_23 ) ;
V_378 = F_186 ( V_23 , V_23 -> V_259 ,
V_23 -> V_257 ) ;
if ( V_378 )
F_119 ( V_23 , 0 ) ;
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
}
int F_221 ( struct V_11 * V_23 )
{
int V_24 ;
V_23 -> V_371 = 0 ;
V_23 -> V_280 = 0 ;
V_23 -> V_411 = 0 ;
V_23 -> V_377 = 0 ;
V_23 -> V_259 = 0 ;
V_23 -> V_372 = 0 ;
V_23 -> V_257 = 0 ;
V_23 -> V_104 = NULL ;
V_23 -> V_105 = NULL ;
V_23 -> V_106 = 0 ;
F_67 ( & V_23 -> V_113 ) ;
V_23 -> V_443 = V_444 ;
V_23 -> V_445 = V_444 ;
V_23 -> V_197 = V_198 ;
V_23 -> V_288 = V_289 ;
if ( V_23 -> V_141 != V_144 )
return 0 ;
V_23 -> V_285 = V_380 ;
V_23 -> V_283 = V_284 ;
F_55 ( & V_23 -> V_43 , F_167 ) ;
F_55 ( & V_23 -> V_41 , F_166 ) ;
F_55 ( & V_23 -> V_442 , F_220 ) ;
F_67 ( & V_23 -> V_145 ) ;
V_24 = F_36 ( & V_23 -> V_146 , V_23 -> V_91 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_36 ( & V_23 -> V_147 , V_23 -> V_95 ) ;
if ( V_24 < 0 )
F_39 ( & V_23 -> V_146 ) ;
return V_24 ;
}
static inline T_7 F_222 ( T_7 V_141 , T_5 V_446 )
{
switch ( V_141 ) {
case V_148 :
case V_144 :
if ( F_139 ( V_141 , V_446 ) )
return V_141 ;
default:
return V_142 ;
}
}
static inline bool F_223 ( struct V_12 * V_13 )
{
return ( ( V_13 -> V_263 & V_264 ) &&
( V_13 -> V_309 & V_447 ) ) ;
}
static inline bool F_224 ( struct V_12 * V_13 )
{
return ( ( V_13 -> V_263 & V_264 ) &&
( V_13 -> V_309 & V_448 ) ) ;
}
static void F_225 ( struct V_11 * V_23 ,
struct V_449 * V_450 )
{
if ( V_23 -> V_443 != V_444 && V_23 -> V_200 ) {
T_10 V_451 = V_23 -> V_200 -> V_189 -> V_452 ;
V_451 = F_226 ( V_451 , 1000 ) ;
V_451 = 3 * V_451 + 500 ;
if ( V_451 > 0xffff )
V_451 = 0xffff ;
V_450 -> V_42 = F_18 ( ( T_2 ) V_451 ) ;
V_450 -> V_44 = V_450 -> V_42 ;
} else {
V_450 -> V_42 = F_18 ( V_100 ) ;
V_450 -> V_44 = F_18 ( V_101 ) ;
}
}
static inline void F_227 ( struct V_11 * V_23 )
{
if ( V_23 -> V_91 > V_92 &&
F_223 ( V_23 -> V_13 ) ) {
F_57 ( V_239 , & V_23 -> V_103 ) ;
V_23 -> V_93 = V_453 ;
} else {
V_23 -> V_91 = F_66 ( T_2 , V_23 -> V_91 ,
V_92 ) ;
V_23 -> V_93 = V_92 ;
}
V_23 -> V_96 = V_23 -> V_91 ;
}
static int F_142 ( struct V_11 * V_23 , void * V_188 )
{
struct V_454 * V_273 = V_188 ;
struct V_449 V_450 = { . V_141 = V_23 -> V_141 } ;
void * V_429 = V_273 -> V_188 ;
T_2 V_54 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_329 || V_23 -> V_455 )
goto V_27;
switch ( V_23 -> V_141 ) {
case V_148 :
case V_144 :
if ( F_70 ( V_319 , & V_23 -> V_85 ) )
break;
if ( F_224 ( V_23 -> V_13 ) )
F_57 ( V_456 , & V_23 -> V_103 ) ;
default:
V_23 -> V_141 = F_222 ( V_450 . V_141 , V_23 -> V_13 -> V_309 ) ;
break;
}
V_27:
if ( V_23 -> V_111 != V_31 )
F_217 ( & V_429 , V_457 , 2 , V_23 -> V_111 ) ;
switch ( V_23 -> V_141 ) {
case V_142 :
if ( V_312 )
break;
if ( ! ( V_23 -> V_13 -> V_309 & V_313 ) &&
! ( V_23 -> V_13 -> V_309 & V_314 ) )
break;
V_450 . V_141 = V_142 ;
V_450 . V_458 = 0 ;
V_450 . V_459 = 0 ;
V_450 . V_42 = 0 ;
V_450 . V_44 = 0 ;
V_450 . V_460 = 0 ;
F_217 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
break;
case V_144 :
V_450 . V_141 = V_144 ;
V_450 . V_459 = V_23 -> V_89 ;
F_225 ( V_23 , & V_450 ) ;
V_54 = F_66 ( T_2 , V_462 , V_23 -> V_13 -> V_158 -
V_244 - V_395 -
V_249 ) ;
V_450 . V_460 = F_18 ( V_54 ) ;
F_227 ( V_23 ) ;
V_450 . V_458 = F_66 ( T_2 , V_23 -> V_91 ,
V_92 ) ;
F_217 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
if ( F_70 ( V_456 , & V_23 -> V_103 ) )
F_218 ( & V_429 , V_23 ) ;
if ( F_70 ( V_239 , & V_23 -> V_103 ) )
F_217 ( & V_429 , V_463 , 2 ,
V_23 -> V_91 ) ;
if ( V_23 -> V_13 -> V_309 & V_464 )
if ( V_23 -> V_87 == V_465 ||
F_70 ( V_466 , & V_23 -> V_85 ) ) {
V_23 -> V_87 = V_465 ;
F_217 ( & V_429 , V_467 , 1 ,
V_23 -> V_87 ) ;
}
break;
case V_148 :
F_227 ( V_23 ) ;
V_450 . V_141 = V_148 ;
V_450 . V_458 = 0 ;
V_450 . V_459 = 0 ;
V_450 . V_42 = 0 ;
V_450 . V_44 = 0 ;
V_54 = F_66 ( T_2 , V_462 , V_23 -> V_13 -> V_158 -
V_244 - V_395 -
V_249 ) ;
V_450 . V_460 = F_18 ( V_54 ) ;
F_217 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
if ( F_70 ( V_456 , & V_23 -> V_103 ) )
F_218 ( & V_429 , V_23 ) ;
if ( V_23 -> V_13 -> V_309 & V_464 )
if ( V_23 -> V_87 == V_465 ||
F_70 ( V_466 , & V_23 -> V_85 ) ) {
V_23 -> V_87 = V_465 ;
F_217 ( & V_429 , V_467 , 1 ,
V_23 -> V_87 ) ;
}
break;
}
V_273 -> V_16 = F_18 ( V_23 -> V_16 ) ;
V_273 -> V_103 = F_18 ( 0 ) ;
return V_429 - V_188 ;
}
static int F_228 ( struct V_11 * V_23 , void * V_188 )
{
struct V_468 * V_152 = V_188 ;
void * V_429 = V_152 -> V_188 ;
void * V_273 = V_23 -> V_469 ;
int V_187 = V_23 -> V_470 ;
int type , V_471 , V_430 ;
unsigned long V_431 ;
struct V_449 V_450 = { . V_141 = V_142 } ;
struct V_435 V_436 ;
T_1 V_472 = 0 ;
T_2 V_158 = V_31 ;
T_2 V_153 = V_473 ;
T_2 V_54 ;
F_23 ( L_3 , V_23 ) ;
while ( V_187 >= V_434 ) {
V_187 -= F_216 ( & V_273 , & type , & V_430 , & V_431 ) ;
V_471 = type & V_474 ;
type &= V_475 ;
switch ( type ) {
case V_457 :
V_158 = V_431 ;
break;
case V_476 :
V_23 -> V_98 = V_431 ;
break;
case V_477 :
break;
case V_461 :
if ( V_430 == sizeof( V_450 ) )
memcpy ( & V_450 , ( void * ) V_431 , V_430 ) ;
break;
case V_467 :
if ( V_431 == V_465 )
F_57 ( V_466 , & V_23 -> V_85 ) ;
break;
case V_441 :
V_472 = 1 ;
if ( V_430 == sizeof( V_436 ) )
memcpy ( & V_436 , ( void * ) V_431 , V_430 ) ;
break;
case V_463 :
if ( ! ( V_23 -> V_13 -> V_263 & V_264 ) )
return - V_70 ;
F_57 ( V_239 , & V_23 -> V_103 ) ;
F_57 ( V_478 , & V_23 -> V_85 ) ;
V_23 -> V_93 = V_453 ;
V_23 -> V_95 = V_431 ;
break;
default:
if ( V_471 )
break;
V_153 = V_479 ;
* ( ( T_1 * ) V_429 ++ ) = type ;
break;
}
}
if ( V_23 -> V_455 || V_23 -> V_329 > 1 )
goto V_27;
switch ( V_23 -> V_141 ) {
case V_148 :
case V_144 :
if ( ! F_70 ( V_319 , & V_23 -> V_85 ) ) {
V_23 -> V_141 = F_222 ( V_450 . V_141 ,
V_23 -> V_13 -> V_309 ) ;
break;
}
if ( V_472 ) {
if ( F_224 ( V_23 -> V_13 ) )
F_57 ( V_456 , & V_23 -> V_103 ) ;
else
return - V_70 ;
}
if ( V_23 -> V_141 != V_450 . V_141 )
return - V_70 ;
break;
}
V_27:
if ( V_23 -> V_141 != V_450 . V_141 ) {
V_153 = V_480 ;
V_450 . V_141 = V_23 -> V_141 ;
if ( V_23 -> V_455 == 1 )
return - V_70 ;
F_217 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
}
if ( V_153 == V_473 ) {
if ( V_158 < V_481 )
V_153 = V_480 ;
else {
V_23 -> V_30 = V_158 ;
F_57 ( V_482 , & V_23 -> V_85 ) ;
}
F_217 ( & V_429 , V_457 , 2 , V_23 -> V_30 ) ;
if ( V_472 ) {
if ( V_23 -> V_123 != V_483 &&
V_436 . V_437 != V_483 &&
V_436 . V_437 != V_23 -> V_123 ) {
V_153 = V_480 ;
if ( V_23 -> V_329 >= 1 )
return - V_70 ;
F_217 ( & V_429 , V_441 ,
sizeof( V_436 ) ,
( unsigned long ) & V_436 ) ;
} else {
V_153 = V_484 ;
F_57 ( V_485 , & V_23 -> V_85 ) ;
}
}
switch ( V_450 . V_141 ) {
case V_142 :
V_23 -> V_87 = V_465 ;
F_57 ( V_486 , & V_23 -> V_85 ) ;
break;
case V_144 :
if ( ! F_70 ( V_478 , & V_23 -> V_85 ) )
V_23 -> V_95 = V_450 . V_458 ;
else
V_450 . V_458 = V_92 ;
V_23 -> V_94 = V_450 . V_459 ;
V_54 = F_66 ( T_2 , F_229 ( V_450 . V_460 ) ,
V_23 -> V_13 -> V_158 - V_244 -
V_395 - V_249 ) ;
V_450 . V_460 = F_18 ( V_54 ) ;
V_23 -> V_399 = V_54 ;
F_225 ( V_23 , & V_450 ) ;
F_57 ( V_486 , & V_23 -> V_85 ) ;
F_217 ( & V_429 , V_461 ,
sizeof( V_450 ) , ( unsigned long ) & V_450 ) ;
if ( F_70 ( V_456 , & V_23 -> V_103 ) ) {
V_23 -> V_487 = V_436 . V_183 ;
V_23 -> V_488 = V_436 . V_437 ;
V_23 -> V_489 = F_229 ( V_436 . V_438 ) ;
V_23 -> V_490 =
F_230 ( V_436 . V_98 ) ;
V_23 -> V_491 =
F_230 ( V_436 . V_440 ) ;
V_23 -> V_492 =
F_230 ( V_436 . V_439 ) ;
F_217 ( & V_429 , V_441 ,
sizeof( V_436 ) ,
( unsigned long ) & V_436 ) ;
}
break;
case V_148 :
V_54 = F_66 ( T_2 , F_229 ( V_450 . V_460 ) ,
V_23 -> V_13 -> V_158 - V_244 -
V_395 - V_249 ) ;
V_450 . V_460 = F_18 ( V_54 ) ;
V_23 -> V_399 = V_54 ;
F_57 ( V_486 , & V_23 -> V_85 ) ;
F_217 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
break;
default:
V_153 = V_480 ;
memset ( & V_450 , 0 , sizeof( V_450 ) ) ;
V_450 . V_141 = V_23 -> V_141 ;
}
if ( V_153 == V_473 )
F_57 ( V_493 , & V_23 -> V_85 ) ;
}
V_152 -> V_17 = F_18 ( V_23 -> V_16 ) ;
V_152 -> V_153 = F_18 ( V_153 ) ;
V_152 -> V_103 = F_18 ( 0 ) ;
return V_429 - V_188 ;
}
static int F_231 ( struct V_11 * V_23 , void * V_152 , int V_187 ,
void * V_188 , T_2 * V_153 )
{
struct V_454 * V_273 = V_188 ;
void * V_429 = V_273 -> V_188 ;
int type , V_430 ;
unsigned long V_431 ;
struct V_449 V_450 = { . V_141 = V_142 } ;
struct V_435 V_436 ;
F_23 ( L_40 , V_23 , V_152 , V_187 , V_188 ) ;
while ( V_187 >= V_434 ) {
V_187 -= F_216 ( & V_152 , & type , & V_430 , & V_431 ) ;
switch ( type ) {
case V_457 :
if ( V_431 < V_481 ) {
* V_153 = V_480 ;
V_23 -> V_111 = V_481 ;
} else
V_23 -> V_111 = V_431 ;
F_217 ( & V_429 , V_457 , 2 , V_23 -> V_111 ) ;
break;
case V_476 :
V_23 -> V_98 = V_431 ;
F_217 ( & V_429 , V_476 ,
2 , V_23 -> V_98 ) ;
break;
case V_461 :
if ( V_430 == sizeof( V_450 ) )
memcpy ( & V_450 , ( void * ) V_431 , V_430 ) ;
if ( F_70 ( V_319 , & V_23 -> V_85 ) &&
V_450 . V_141 != V_23 -> V_141 )
return - V_70 ;
V_23 -> V_87 = 0 ;
F_217 ( & V_429 , V_461 ,
sizeof( V_450 ) , ( unsigned long ) & V_450 ) ;
break;
case V_463 :
V_23 -> V_96 = F_66 ( T_2 , V_431 , V_23 -> V_96 ) ;
F_217 ( & V_429 , V_463 , 2 ,
V_23 -> V_91 ) ;
break;
case V_441 :
if ( V_430 == sizeof( V_436 ) )
memcpy ( & V_436 , ( void * ) V_431 , V_430 ) ;
if ( V_23 -> V_123 != V_483 &&
V_436 . V_437 != V_483 &&
V_436 . V_437 != V_23 -> V_123 )
return - V_70 ;
F_217 ( & V_429 , V_441 , sizeof( V_436 ) ,
( unsigned long ) & V_436 ) ;
break;
case V_467 :
if ( * V_153 == V_484 )
if ( V_431 == V_465 )
F_57 ( V_466 ,
& V_23 -> V_85 ) ;
break;
}
}
if ( V_23 -> V_141 == V_142 && V_23 -> V_141 != V_450 . V_141 )
return - V_70 ;
V_23 -> V_141 = V_450 . V_141 ;
if ( * V_153 == V_473 || * V_153 == V_484 ) {
switch ( V_450 . V_141 ) {
case V_144 :
V_23 -> V_42 = F_229 ( V_450 . V_42 ) ;
V_23 -> V_44 = F_229 ( V_450 . V_44 ) ;
V_23 -> V_110 = F_229 ( V_450 . V_460 ) ;
if ( ! F_70 ( V_239 , & V_23 -> V_103 ) )
V_23 -> V_96 = F_66 ( T_2 , V_23 -> V_96 ,
V_450 . V_458 ) ;
if ( F_70 ( V_456 , & V_23 -> V_103 ) ) {
V_23 -> V_125 = F_229 ( V_436 . V_438 ) ;
V_23 -> V_127 =
F_230 ( V_436 . V_439 ) ;
V_23 -> V_129 = F_230 ( V_436 . V_440 ) ;
V_23 -> V_131 =
F_230 ( V_436 . V_98 ) ;
}
break;
case V_148 :
V_23 -> V_110 = F_229 ( V_450 . V_460 ) ;
}
}
V_273 -> V_16 = F_18 ( V_23 -> V_16 ) ;
V_273 -> V_103 = F_18 ( 0 ) ;
return V_429 - V_188 ;
}
static int F_232 ( struct V_11 * V_23 , void * V_188 ,
T_2 V_153 , T_2 V_103 )
{
struct V_468 * V_152 = V_188 ;
void * V_429 = V_152 -> V_188 ;
F_23 ( L_3 , V_23 ) ;
V_152 -> V_17 = F_18 ( V_23 -> V_16 ) ;
V_152 -> V_153 = F_18 ( V_153 ) ;
V_152 -> V_103 = F_18 ( V_103 ) ;
return V_429 - V_188 ;
}
void F_233 ( struct V_11 * V_23 )
{
struct V_151 V_152 ;
struct V_12 * V_13 = V_23 -> V_13 ;
F_23 ( L_3 , V_23 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_152 . V_158 = F_18 ( V_23 -> V_111 ) ;
V_152 . V_110 = F_18 ( V_23 -> V_110 ) ;
V_152 . V_159 = F_18 ( V_23 -> V_108 ) ;
V_152 . V_153 = F_18 ( V_325 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_160 , sizeof( V_152 ) ,
& V_152 ) ;
}
void F_234 ( struct V_11 * V_23 )
{
struct V_161 V_152 ;
struct V_12 * V_13 = V_23 -> V_13 ;
T_1 V_321 [ 128 ] ;
T_1 V_494 ;
V_152 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_152 . V_153 = F_18 ( V_325 ) ;
V_152 . V_163 = F_18 ( V_164 ) ;
if ( V_23 -> V_200 )
V_494 = V_495 ;
else
V_494 = V_165 ;
F_23 ( L_41 , V_23 , V_494 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_494 , sizeof( V_152 ) , & V_152 ) ;
if ( F_132 ( V_327 , & V_23 -> V_85 ) )
return;
F_83 ( V_13 , F_91 ( V_13 ) , V_328 ,
F_142 ( V_23 , V_321 ) , V_321 ) ;
V_23 -> V_329 ++ ;
}
static void F_235 ( struct V_11 * V_23 , void * V_152 , int V_187 )
{
int type , V_430 ;
unsigned long V_431 ;
T_2 V_496 = V_23 -> V_96 ;
struct V_449 V_450 = {
. V_141 = V_23 -> V_141 ,
. V_42 = F_18 ( V_100 ) ,
. V_44 = F_18 ( V_101 ) ,
. V_460 = F_18 ( V_23 -> V_111 ) ,
. V_458 = F_66 ( T_2 , V_23 -> V_96 , V_92 ) ,
} ;
F_23 ( L_42 , V_23 , V_152 , V_187 ) ;
if ( ( V_23 -> V_141 != V_144 ) && ( V_23 -> V_141 != V_148 ) )
return;
while ( V_187 >= V_434 ) {
V_187 -= F_216 ( & V_152 , & type , & V_430 , & V_431 ) ;
switch ( type ) {
case V_461 :
if ( V_430 == sizeof( V_450 ) )
memcpy ( & V_450 , ( void * ) V_431 , V_430 ) ;
break;
case V_463 :
V_496 = V_431 ;
break;
}
}
switch ( V_450 . V_141 ) {
case V_144 :
V_23 -> V_42 = F_229 ( V_450 . V_42 ) ;
V_23 -> V_44 = F_229 ( V_450 . V_44 ) ;
V_23 -> V_110 = F_229 ( V_450 . V_460 ) ;
if ( F_70 ( V_239 , & V_23 -> V_103 ) )
V_23 -> V_96 = F_66 ( T_2 , V_23 -> V_96 , V_496 ) ;
else
V_23 -> V_96 = F_66 ( T_2 , V_23 -> V_96 ,
V_450 . V_458 ) ;
break;
case V_148 :
V_23 -> V_110 = F_229 ( V_450 . V_460 ) ;
}
}
static inline int F_236 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_498 * V_499 = (struct V_498 * ) V_188 ;
if ( V_497 < sizeof( * V_499 ) )
return - V_500 ;
if ( V_499 -> V_67 != V_501 )
return 0 ;
if ( ( V_13 -> V_301 & V_302 ) &&
V_425 -> V_19 == V_13 -> V_304 ) {
F_237 ( & V_13 -> V_305 ) ;
V_13 -> V_301 |= V_308 ;
V_13 -> V_304 = 0 ;
F_140 ( V_13 ) ;
}
return 0 ;
}
static struct V_11 * F_238 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_1 * V_188 , T_1 V_494 , T_1 V_275 )
{
struct V_272 * V_273 = (struct V_272 * ) V_188 ;
struct V_161 V_152 ;
struct V_11 * V_23 = NULL , * V_502 ;
int V_153 , V_163 = V_164 ;
T_2 V_16 = 0 , V_17 = F_69 ( V_273 -> V_17 ) ;
T_3 V_20 = V_273 -> V_20 ;
F_23 ( L_43 , F_69 ( V_20 ) , V_17 ) ;
V_502 = F_165 ( V_166 , V_20 , & V_13 -> V_8 -> V_21 ,
& V_13 -> V_8 -> V_150 , V_117 ) ;
if ( ! V_502 ) {
V_153 = V_156 ;
goto V_503;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_502 ) ;
if ( V_20 != F_18 ( V_178 ) &&
! F_239 ( V_13 -> V_8 ) ) {
V_13 -> V_114 = V_504 ;
V_153 = V_162 ;
goto V_505;
}
V_153 = V_506 ;
if ( F_4 ( V_13 , V_17 ) )
goto V_505;
V_23 = V_502 -> V_39 -> V_507 ( V_502 ) ;
if ( ! V_23 )
goto V_505;
V_13 -> V_8 -> V_360 = V_508 ;
F_81 ( & V_23 -> V_21 , & V_13 -> V_8 -> V_21 ) ;
F_81 ( & V_23 -> V_150 , & V_13 -> V_8 -> V_150 ) ;
V_23 -> V_9 = F_2 ( V_13 -> V_8 ) ;
V_23 -> V_10 = F_3 ( V_13 -> V_8 ) ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_17 ;
V_23 -> V_443 = V_275 ;
F_68 ( V_13 , V_23 ) ;
V_16 = V_23 -> V_17 ;
F_85 ( V_23 , V_23 -> V_39 -> V_167 ( V_23 ) ) ;
V_23 -> V_19 = V_425 -> V_19 ;
if ( V_13 -> V_301 & V_308 ) {
if ( F_88 ( V_23 , false ) ) {
if ( F_70 ( V_154 , & V_23 -> V_103 ) ) {
F_22 ( V_23 , V_168 ) ;
V_153 = V_322 ;
V_163 = V_323 ;
V_23 -> V_39 -> V_324 ( V_23 ) ;
} else {
if ( V_275 == V_444 ) {
F_22 ( V_23 , V_69 ) ;
V_153 = V_325 ;
} else {
F_22 ( V_23 , V_168 ) ;
V_153 = V_322 ;
}
V_163 = V_164 ;
}
} else {
F_22 ( V_23 , V_168 ) ;
V_153 = V_322 ;
V_163 = V_326 ;
}
} else {
F_22 ( V_23 , V_168 ) ;
V_153 = V_322 ;
V_163 = V_164 ;
}
V_505:
F_48 ( V_502 ) ;
F_10 ( & V_13 -> V_18 ) ;
F_49 ( V_502 ) ;
V_503:
V_152 . V_17 = F_18 ( V_17 ) ;
V_152 . V_16 = F_18 ( V_16 ) ;
V_152 . V_153 = F_18 ( V_153 ) ;
V_152 . V_163 = F_18 ( V_163 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_494 , sizeof( V_152 ) , & V_152 ) ;
if ( V_153 == V_322 && V_163 == V_164 ) {
struct V_300 V_509 ;
V_509 . type = F_18 ( V_303 ) ;
V_13 -> V_301 |= V_302 ;
V_13 -> V_304 = F_91 ( V_13 ) ;
F_137 ( & V_13 -> V_305 , V_306 ) ;
F_83 ( V_13 , V_13 -> V_304 , V_307 ,
sizeof( V_509 ) , & V_509 ) ;
}
if ( V_23 && ! F_70 ( V_327 , & V_23 -> V_85 ) &&
V_153 == V_325 ) {
T_1 V_321 [ 128 ] ;
F_57 ( V_327 , & V_23 -> V_85 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_328 ,
F_142 ( V_23 , V_321 ) , V_321 ) ;
V_23 -> V_329 ++ ;
}
return V_23 ;
}
static int F_240 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 , T_1 * V_188 )
{
struct V_261 * V_189 = V_13 -> V_8 -> V_189 ;
struct V_7 * V_8 = V_13 -> V_8 ;
if ( V_497 < sizeof( struct V_272 ) )
return - V_500 ;
F_149 ( V_189 ) ;
if ( F_241 ( V_189 , V_510 ) &&
! F_132 ( V_511 , & V_8 -> V_103 ) )
F_242 ( V_189 , V_8 , 0 , NULL , 0 ) ;
F_151 ( V_189 ) ;
F_238 ( V_13 , V_425 , V_188 , V_165 , 0 ) ;
return 0 ;
}
static int F_243 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_161 * V_152 = (struct V_161 * ) V_188 ;
T_2 V_17 , V_16 , V_153 , V_163 ;
struct V_11 * V_23 ;
T_1 V_273 [ 128 ] ;
int V_24 ;
if ( V_497 < sizeof( * V_152 ) )
return - V_500 ;
V_17 = F_69 ( V_152 -> V_17 ) ;
V_16 = F_69 ( V_152 -> V_16 ) ;
V_153 = F_69 ( V_152 -> V_153 ) ;
V_163 = F_69 ( V_152 -> V_163 ) ;
F_23 ( L_44 ,
V_16 , V_17 , V_153 , V_163 ) ;
F_8 ( & V_13 -> V_18 ) ;
if ( V_17 ) {
V_23 = F_6 ( V_13 , V_17 ) ;
if ( ! V_23 ) {
V_24 = - V_512 ;
goto V_513;
}
} else {
V_23 = F_12 ( V_13 , V_425 -> V_19 ) ;
if ( ! V_23 ) {
V_24 = - V_512 ;
goto V_513;
}
}
V_24 = 0 ;
F_9 ( V_23 ) ;
switch ( V_153 ) {
case V_325 :
F_22 ( V_23 , V_69 ) ;
V_23 -> V_19 = 0 ;
V_23 -> V_16 = V_16 ;
F_117 ( V_260 , & V_23 -> V_85 ) ;
if ( F_132 ( V_327 , & V_23 -> V_85 ) )
break;
F_83 ( V_13 , F_91 ( V_13 ) , V_328 ,
F_142 ( V_23 , V_273 ) , V_273 ) ;
V_23 -> V_329 ++ ;
break;
case V_322 :
F_57 ( V_260 , & V_23 -> V_85 ) ;
break;
default:
F_73 ( V_23 , V_70 ) ;
break;
}
F_48 ( V_23 ) ;
V_513:
F_10 ( & V_13 -> V_18 ) ;
return V_24 ;
}
static inline void F_244 ( struct V_11 * V_23 )
{
if ( V_23 -> V_141 != V_144 && V_23 -> V_141 != V_148 )
V_23 -> V_87 = V_465 ;
else if ( ! F_70 ( V_466 , & V_23 -> V_85 ) )
V_23 -> V_87 = V_88 ;
}
static void F_245 ( struct V_11 * V_23 , void * V_188 ,
T_1 V_19 , T_2 V_103 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
F_23 ( L_45 , V_13 , V_23 , V_19 ,
V_103 ) ;
F_117 ( V_485 , & V_23 -> V_85 ) ;
F_57 ( V_493 , & V_23 -> V_85 ) ;
F_83 ( V_13 , V_19 , V_514 ,
F_232 ( V_23 , V_188 ,
V_473 , V_103 ) , V_188 ) ;
}
static void F_246 ( struct V_12 * V_13 , T_1 V_19 ,
T_2 V_17 , T_2 V_16 )
{
struct V_515 V_499 ;
V_499 . V_67 = F_18 ( V_516 ) ;
V_499 . V_17 = F_247 ( V_17 ) ;
V_499 . V_16 = F_247 ( V_16 ) ;
F_83 ( V_13 , V_19 , V_517 , sizeof( V_499 ) , & V_499 ) ;
}
static inline int F_248 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_454 * V_273 = (struct V_454 * ) V_188 ;
T_2 V_16 , V_103 ;
T_1 V_152 [ 64 ] ;
struct V_11 * V_23 ;
int V_187 , V_24 = 0 ;
if ( V_497 < sizeof( * V_273 ) )
return - V_500 ;
V_16 = F_69 ( V_273 -> V_16 ) ;
V_103 = F_69 ( V_273 -> V_103 ) ;
F_23 ( L_46 , V_16 , V_103 ) ;
V_23 = F_7 ( V_13 , V_16 ) ;
if ( ! V_23 ) {
F_246 ( V_13 , V_425 -> V_19 , V_16 , 0 ) ;
return 0 ;
}
if ( V_23 -> V_38 != V_69 && V_23 -> V_38 != V_168 ) {
F_246 ( V_13 , V_425 -> V_19 , V_23 -> V_17 ,
V_23 -> V_16 ) ;
goto V_513;
}
V_187 = V_497 - sizeof( * V_273 ) ;
if ( V_23 -> V_470 + V_187 > sizeof( V_23 -> V_469 ) ) {
F_83 ( V_13 , V_425 -> V_19 , V_514 ,
F_232 ( V_23 , V_152 ,
V_518 , V_103 ) , V_152 ) ;
goto V_513;
}
memcpy ( V_23 -> V_469 + V_23 -> V_470 , V_273 -> V_188 , V_187 ) ;
V_23 -> V_470 += V_187 ;
if ( V_103 & V_519 ) {
F_83 ( V_13 , V_425 -> V_19 , V_514 ,
F_232 ( V_23 , V_152 ,
V_473 , V_103 ) , V_152 ) ;
goto V_513;
}
V_187 = F_228 ( V_23 , V_152 ) ;
if ( V_187 < 0 ) {
F_86 ( V_23 , V_320 ) ;
goto V_513;
}
V_23 -> V_19 = V_425 -> V_19 ;
F_83 ( V_13 , V_425 -> V_19 , V_514 , V_187 , V_152 ) ;
V_23 -> V_455 ++ ;
V_23 -> V_470 = 0 ;
if ( ! F_70 ( V_493 , & V_23 -> V_85 ) )
goto V_513;
if ( F_70 ( V_520 , & V_23 -> V_85 ) ) {
F_244 ( V_23 ) ;
if ( V_23 -> V_141 == V_144 ||
V_23 -> V_141 == V_148 )
V_24 = F_221 ( V_23 ) ;
if ( V_24 < 0 )
F_86 ( V_23 , - V_24 ) ;
else
F_130 ( V_23 ) ;
goto V_513;
}
if ( ! F_132 ( V_327 , & V_23 -> V_85 ) ) {
T_1 V_321 [ 64 ] ;
F_83 ( V_13 , F_91 ( V_13 ) , V_328 ,
F_142 ( V_23 , V_321 ) , V_321 ) ;
V_23 -> V_329 ++ ;
}
if ( F_70 ( V_521 , & V_23 -> V_85 ) &&
F_70 ( V_485 , & V_23 -> V_85 ) ) {
if ( ! V_23 -> V_200 )
F_245 ( V_23 , V_152 , V_425 -> V_19 , V_103 ) ;
else
V_23 -> V_19 = V_425 -> V_19 ;
}
V_513:
F_48 ( V_23 ) ;
return V_24 ;
}
static inline int F_249 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_468 * V_152 = (struct V_468 * ) V_188 ;
T_2 V_17 , V_103 , V_153 ;
struct V_11 * V_23 ;
int V_187 = V_497 - sizeof( * V_152 ) ;
int V_24 = 0 ;
if ( V_497 < sizeof( * V_152 ) )
return - V_500 ;
V_17 = F_69 ( V_152 -> V_17 ) ;
V_103 = F_69 ( V_152 -> V_103 ) ;
V_153 = F_69 ( V_152 -> V_153 ) ;
F_23 ( L_47 , V_17 , V_103 ,
V_153 , V_187 ) ;
V_23 = F_7 ( V_13 , V_17 ) ;
if ( ! V_23 )
return 0 ;
switch ( V_153 ) {
case V_473 :
F_235 ( V_23 , V_152 -> V_188 , V_187 ) ;
F_117 ( V_521 , & V_23 -> V_85 ) ;
break;
case V_484 :
F_57 ( V_521 , & V_23 -> V_85 ) ;
if ( F_70 ( V_485 , & V_23 -> V_85 ) ) {
char V_321 [ 64 ] ;
V_187 = F_231 ( V_23 , V_152 -> V_188 , V_187 ,
V_321 , & V_153 ) ;
if ( V_187 < 0 ) {
F_86 ( V_23 , V_320 ) ;
goto V_27;
}
if ( ! V_23 -> V_200 ) {
F_245 ( V_23 , V_321 , V_425 -> V_19 ,
0 ) ;
} else {
if ( F_124 ( V_23 ) ) {
F_250 ( V_23 ) ;
V_23 -> V_19 = V_425 -> V_19 ;
}
}
}
goto V_27;
case V_480 :
if ( V_23 -> V_455 <= V_522 ) {
char V_273 [ 64 ] ;
if ( V_187 > sizeof( V_273 ) - sizeof( struct V_454 ) ) {
F_86 ( V_23 , V_320 ) ;
goto V_27;
}
V_153 = V_473 ;
V_187 = F_231 ( V_23 , V_152 -> V_188 , V_187 ,
V_273 , & V_153 ) ;
if ( V_187 < 0 ) {
F_86 ( V_23 , V_320 ) ;
goto V_27;
}
F_83 ( V_13 , F_91 ( V_13 ) ,
V_328 , V_187 , V_273 ) ;
V_23 -> V_329 ++ ;
if ( V_153 != V_473 )
goto V_27;
break;
}
default:
F_26 ( V_23 , V_320 ) ;
F_85 ( V_23 , V_523 ) ;
F_86 ( V_23 , V_320 ) ;
goto V_27;
}
if ( V_103 & V_519 )
goto V_27;
F_57 ( V_520 , & V_23 -> V_85 ) ;
if ( F_70 ( V_493 , & V_23 -> V_85 ) ) {
F_244 ( V_23 ) ;
if ( V_23 -> V_141 == V_144 ||
V_23 -> V_141 == V_148 )
V_24 = F_221 ( V_23 ) ;
if ( V_24 < 0 )
F_86 ( V_23 , - V_24 ) ;
else
F_130 ( V_23 ) ;
}
V_27:
F_48 ( V_23 ) ;
return V_24 ;
}
static inline int F_251 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_315 * V_273 = (struct V_315 * ) V_188 ;
struct V_524 V_152 ;
T_2 V_16 , V_17 ;
struct V_11 * V_23 ;
if ( V_497 != sizeof( * V_273 ) )
return - V_500 ;
V_17 = F_69 ( V_273 -> V_17 ) ;
V_16 = F_69 ( V_273 -> V_16 ) ;
F_23 ( L_48 , V_17 , V_16 ) ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_6 ( V_13 , V_16 ) ;
if ( ! V_23 ) {
F_10 ( & V_13 -> V_18 ) ;
F_246 ( V_13 , V_425 -> V_19 , V_16 , V_17 ) ;
return 0 ;
}
F_9 ( V_23 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_152 . V_17 = F_18 ( V_23 -> V_16 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_525 , sizeof( V_152 ) , & V_152 ) ;
V_23 -> V_39 -> V_526 ( V_23 ) ;
F_60 ( V_23 ) ;
F_73 ( V_23 , V_320 ) ;
F_48 ( V_23 ) ;
V_23 -> V_39 -> V_75 ( V_23 ) ;
F_49 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
return 0 ;
}
static inline int F_252 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_524 * V_152 = (struct V_524 * ) V_188 ;
T_2 V_16 , V_17 ;
struct V_11 * V_23 ;
if ( V_497 != sizeof( * V_152 ) )
return - V_500 ;
V_17 = F_69 ( V_152 -> V_17 ) ;
V_16 = F_69 ( V_152 -> V_16 ) ;
F_23 ( L_49 , V_16 , V_17 ) ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_6 ( V_13 , V_17 ) ;
if ( ! V_23 ) {
F_10 ( & V_13 -> V_18 ) ;
return 0 ;
}
F_9 ( V_23 ) ;
F_60 ( V_23 ) ;
F_73 ( V_23 , 0 ) ;
F_48 ( V_23 ) ;
V_23 -> V_39 -> V_75 ( V_23 ) ;
F_49 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
return 0 ;
}
static inline int F_253 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_300 * V_273 = (struct V_300 * ) V_188 ;
T_2 type ;
if ( V_497 != sizeof( * V_273 ) )
return - V_500 ;
type = F_69 ( V_273 -> type ) ;
F_23 ( L_50 , type ) ;
if ( type == V_303 ) {
T_1 V_321 [ 8 ] ;
T_8 V_309 = V_311 ;
struct V_527 * V_152 = (struct V_527 * ) V_321 ;
V_152 -> type = F_18 ( V_303 ) ;
V_152 -> V_153 = F_18 ( V_528 ) ;
if ( ! V_312 )
V_309 |= V_313 | V_314
| V_464 ;
if ( V_13 -> V_263 & V_264 )
V_309 |= V_448
| V_447 ;
F_107 ( V_309 , V_152 -> V_188 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_529 , sizeof( V_321 ) ,
V_321 ) ;
} else if ( type == V_530 ) {
T_1 V_321 [ 12 ] ;
struct V_527 * V_152 = (struct V_527 * ) V_321 ;
V_152 -> type = F_18 ( V_530 ) ;
V_152 -> V_153 = F_18 ( V_528 ) ;
V_152 -> V_188 [ 0 ] = V_13 -> V_263 ;
memset ( V_152 -> V_188 + 1 , 0 , 7 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_529 , sizeof( V_321 ) ,
V_321 ) ;
} else {
struct V_527 V_152 ;
V_152 . type = F_18 ( type ) ;
V_152 . V_153 = F_18 ( V_531 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_529 , sizeof( V_152 ) ,
& V_152 ) ;
}
return 0 ;
}
static inline int F_254 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_527 * V_152 = (struct V_527 * ) V_188 ;
T_2 type , V_153 ;
if ( V_497 < sizeof( * V_152 ) )
return - V_500 ;
type = F_69 ( V_152 -> type ) ;
V_153 = F_69 ( V_152 -> V_153 ) ;
F_23 ( L_51 , type , V_153 ) ;
if ( V_425 -> V_19 != V_13 -> V_304 ||
V_13 -> V_301 & V_308 )
return 0 ;
F_237 ( & V_13 -> V_305 ) ;
if ( V_153 != V_528 ) {
V_13 -> V_301 |= V_308 ;
V_13 -> V_304 = 0 ;
F_140 ( V_13 ) ;
return 0 ;
}
switch ( type ) {
case V_303 :
V_13 -> V_309 = F_101 ( V_152 -> V_188 ) ;
if ( V_13 -> V_309 & V_532 ) {
struct V_300 V_273 ;
V_273 . type = F_18 ( V_530 ) ;
V_13 -> V_304 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_13 -> V_304 ,
V_307 , sizeof( V_273 ) , & V_273 ) ;
} else {
V_13 -> V_301 |= V_308 ;
V_13 -> V_304 = 0 ;
F_140 ( V_13 ) ;
}
break;
case V_530 :
V_13 -> V_265 = V_152 -> V_188 [ 0 ] ;
V_13 -> V_301 |= V_308 ;
V_13 -> V_304 = 0 ;
F_140 ( V_13 ) ;
break;
}
return 0 ;
}
static int F_255 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_188 )
{
struct V_276 * V_273 = V_188 ;
struct V_533 V_152 ;
struct V_11 * V_23 ;
struct V_261 * V_189 ;
T_2 V_20 , V_17 ;
if ( V_497 != sizeof( * V_273 ) )
return - V_500 ;
if ( ! ( V_13 -> V_263 & V_264 ) )
return - V_29 ;
V_20 = F_229 ( V_273 -> V_20 ) ;
V_17 = F_229 ( V_273 -> V_17 ) ;
F_23 ( L_52 , V_20 , V_17 , V_273 -> V_275 ) ;
if ( V_273 -> V_275 == V_444 ) {
F_238 ( V_13 , V_425 , V_188 , V_495 ,
V_273 -> V_275 ) ;
return 0 ;
}
V_189 = F_256 ( V_273 -> V_275 ) ;
if ( ! V_189 )
goto error;
if ( V_189 -> V_534 != V_535 || ! F_70 ( V_269 , & V_189 -> V_103 ) ) {
F_257 ( V_189 ) ;
goto error;
}
V_23 = F_238 ( V_13 , V_425 , V_188 , V_495 ,
V_273 -> V_275 ) ;
if ( V_23 ) {
struct V_136 * V_137 = V_13 -> V_8 -> V_136 ;
struct V_7 * V_200 ;
V_200 = F_258 ( V_189 , V_536 ,
& V_13 -> V_8 -> V_150 ) ;
if ( ! V_200 ) {
F_257 ( V_189 ) ;
F_246 ( V_13 , V_425 -> V_19 , V_23 -> V_17 ,
V_23 -> V_16 ) ;
return 0 ;
}
F_23 ( L_53 , V_137 , V_23 , V_200 ) ;
V_137 -> V_138 = V_23 ;
V_23 -> V_200 = V_200 ;
V_23 -> V_87 = V_465 ;
V_13 -> V_158 = V_189 -> V_537 ;
}
F_257 ( V_189 ) ;
return 0 ;
error:
V_152 . V_16 = 0 ;
V_152 . V_17 = F_18 ( V_17 ) ;
V_152 . V_153 = F_18 ( V_538 ) ;
V_152 . V_163 = F_18 ( V_164 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_495 ,
sizeof( V_152 ) , & V_152 ) ;
return 0 ;
}
static void F_259 ( struct V_11 * V_23 , T_1 V_539 )
{
struct V_540 V_273 ;
T_1 V_19 ;
F_23 ( L_54 , V_23 , V_539 ) ;
V_19 = F_91 ( V_23 -> V_13 ) ;
V_23 -> V_19 = V_19 ;
V_273 . V_541 = F_18 ( V_23 -> V_17 ) ;
V_273 . V_539 = V_539 ;
F_83 ( V_23 -> V_13 , V_19 , V_542 , sizeof( V_273 ) ,
& V_273 ) ;
F_85 ( V_23 , V_543 ) ;
}
static void F_260 ( struct V_11 * V_23 , T_2 V_153 )
{
struct V_544 V_152 ;
F_23 ( L_55 , V_23 , V_153 ) ;
V_152 . V_541 = F_18 ( V_23 -> V_16 ) ;
V_152 . V_153 = F_18 ( V_153 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_545 ,
sizeof( V_152 ) , & V_152 ) ;
}
static void F_261 ( struct V_11 * V_23 , T_2 V_153 )
{
struct V_546 V_547 ;
F_23 ( L_55 , V_23 , V_153 ) ;
V_23 -> V_19 = F_91 ( V_23 -> V_13 ) ;
V_547 . V_541 = F_18 ( V_23 -> V_17 ) ;
V_547 . V_153 = F_18 ( V_153 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_548 ,
sizeof( V_547 ) , & V_547 ) ;
F_85 ( V_23 , V_543 ) ;
}
static void F_262 ( struct V_12 * V_13 , T_2 V_541 )
{
struct V_546 V_547 ;
F_23 ( L_56 , V_13 , V_541 ) ;
V_547 . V_541 = F_18 ( V_541 ) ;
V_547 . V_153 = F_18 ( V_549 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_548 ,
sizeof( V_547 ) , & V_547 ) ;
}
static void F_263 ( struct V_12 * V_13 , T_1 V_19 ,
T_2 V_541 )
{
struct V_550 V_152 ;
F_23 ( L_57 , V_541 ) ;
V_152 . V_541 = F_18 ( V_541 ) ;
F_83 ( V_13 , V_19 , V_551 , sizeof( V_152 ) , & V_152 ) ;
}
static void F_264 ( struct V_11 * V_23 )
{
V_23 -> V_139 = NULL ;
V_23 -> V_200 = NULL ;
}
static void F_265 ( struct V_11 * V_23 )
{
if ( V_23 -> V_38 != V_68 ) {
F_86 ( V_23 , V_320 ) ;
return;
}
switch ( V_23 -> V_288 ) {
case V_293 :
F_128 ( V_23 ) ;
F_260 ( V_23 , V_552 ) ;
break;
case V_290 :
if ( V_23 -> V_197 == V_553 ||
V_23 -> V_197 == V_554 ) {
F_128 ( V_23 ) ;
}
F_261 ( V_23 , V_549 ) ;
break;
}
}
static void F_266 ( struct V_11 * V_23 ,
struct V_140 * V_196 )
{
struct V_468 V_152 ;
V_23 -> V_139 = V_196 ;
V_23 -> V_200 -> V_356 = V_23 -> V_13 ;
F_245 ( V_23 , & V_152 , V_23 -> V_19 , 0 ) ;
if ( F_70 ( V_520 , & V_23 -> V_85 ) ) {
int V_24 ;
F_244 ( V_23 ) ;
V_24 = F_221 ( V_23 ) ;
if ( V_24 < 0 )
F_86 ( V_23 , - V_24 ) ;
else
F_130 ( V_23 ) ;
}
}
static void F_267 ( struct V_11 * V_23 ,
struct V_140 * V_196 )
{
V_23 -> V_200 = V_196 -> V_13 ;
V_23 -> V_200 -> V_356 = V_23 -> V_13 ;
F_23 ( L_58 , V_23 -> V_197 ) ;
switch ( V_23 -> V_197 ) {
case V_553 :
V_23 -> V_197 = V_555 ;
break;
case V_554 :
if ( F_70 ( V_258 , & V_23 -> V_252 ) ) {
V_23 -> V_197 = V_556 ;
} else if ( V_23 -> V_288 == V_290 ) {
V_23 -> V_197 = V_557 ;
F_261 ( V_23 , V_558 ) ;
} else if ( V_23 -> V_288 == V_293 ) {
V_23 -> V_197 = V_559 ;
F_260 ( V_23 , V_560 ) ;
}
break;
default:
F_264 ( V_23 ) ;
V_23 -> V_197 = V_198 ;
}
}
void F_268 ( struct V_11 * V_23 , struct V_140 * V_196 ,
T_1 V_163 )
{
F_23 ( L_59 , V_23 , V_196 , V_163 ) ;
if ( V_163 ) {
F_265 ( V_23 ) ;
F_264 ( V_23 ) ;
return;
}
if ( V_23 -> V_38 != V_68 ) {
if ( V_23 -> V_443 != V_444 )
F_266 ( V_23 , V_196 ) ;
} else {
F_267 ( V_23 , V_196 ) ;
}
}
void F_269 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_443 == V_444 ) {
if ( V_23 -> V_270 != V_271 )
return;
V_23 -> V_288 = V_290 ;
V_23 -> V_197 = V_199 ;
} else {
V_23 -> V_288 = V_290 ;
V_23 -> V_197 = V_555 ;
V_23 -> V_445 = 0 ;
F_127 ( V_23 ) ;
F_259 ( V_23 , 0 ) ;
}
}
static void F_270 ( struct V_11 * V_23 , int V_153 ,
T_1 V_443 , T_1 V_561 )
{
F_23 ( L_60 , V_23 , F_24 ( V_23 -> V_38 ) ,
V_443 , V_561 ) ;
V_23 -> V_87 = V_465 ;
if ( V_23 -> V_38 == V_71 ) {
if ( V_153 == V_325 ) {
V_23 -> V_443 = V_443 ;
F_126 ( V_23 , V_561 ) ;
} else {
F_125 ( V_23 ) ;
}
return;
}
if ( F_120 ( V_23 ) ) {
struct V_161 V_152 ;
char V_321 [ 128 ] ;
V_152 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
if ( V_153 == V_325 ) {
V_152 . V_153 = F_18 ( V_325 ) ;
V_152 . V_163 = F_18 ( V_164 ) ;
} else {
V_152 . V_153 = F_18 ( V_506 ) ;
V_152 . V_163 = F_18 ( V_164 ) ;
}
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_495 ,
sizeof( V_152 ) , & V_152 ) ;
if ( V_153 == V_325 ) {
F_22 ( V_23 , V_69 ) ;
F_57 ( V_327 , & V_23 -> V_85 ) ;
F_83 ( V_23 -> V_13 , F_91 ( V_23 -> V_13 ) ,
V_328 ,
F_142 ( V_23 , V_321 ) , V_321 ) ;
V_23 -> V_329 ++ ;
}
}
}
static void F_271 ( struct V_11 * V_23 , T_1 V_443 ,
T_1 V_561 )
{
F_127 ( V_23 ) ;
V_23 -> V_445 = V_443 ;
V_23 -> V_197 = V_562 ;
F_259 ( V_23 , V_561 ) ;
}
static void F_272 ( struct V_11 * V_23 , int V_153 )
{
struct V_140 * V_196 = NULL ;
if ( V_196 ) {
if ( V_196 -> V_38 == V_68 ) {
V_23 -> V_200 = V_196 -> V_13 ;
V_23 -> V_200 -> V_356 = V_23 -> V_13 ;
V_23 -> V_197 = V_559 ;
F_260 ( V_23 , V_560 ) ;
F_268 ( V_23 , V_196 , V_560 ) ;
} else {
V_23 -> V_197 = V_554 ;
}
} else {
F_260 ( V_23 , V_563 ) ;
}
}
static void F_273 ( struct V_11 * V_23 , int V_153 )
{
if ( V_23 -> V_288 == V_293 ) {
T_1 V_564 ;
if ( V_153 == - V_29 )
V_564 = V_565 ;
else
V_564 = V_563 ;
F_260 ( V_23 , V_564 ) ;
}
V_23 -> V_288 = V_289 ;
V_23 -> V_197 = V_198 ;
F_173 ( V_23 ) ;
}
void F_274 ( struct V_11 * V_23 , int V_153 )
{
T_1 V_443 = V_23 -> V_443 ;
T_1 V_561 = V_23 -> V_561 ;
F_23 ( L_61 ,
V_23 , V_153 , V_443 , V_561 ) ;
if ( V_23 -> V_38 == V_157 || V_23 -> V_38 == V_566 ) {
F_48 ( V_23 ) ;
return;
}
if ( V_23 -> V_38 != V_68 ) {
F_270 ( V_23 , V_153 , V_443 , V_561 ) ;
} else if ( V_153 != V_560 ) {
F_273 ( V_23 , V_153 ) ;
} else {
switch ( V_23 -> V_288 ) {
case V_290 :
F_271 ( V_23 , V_443 ,
V_561 ) ;
break;
case V_293 :
F_272 ( V_23 , V_153 ) ;
break;
default:
F_273 ( V_23 , V_153 ) ;
break;
}
}
}
static inline int F_275 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_188 )
{
struct V_540 * V_273 = V_188 ;
struct V_544 V_152 ;
struct V_11 * V_23 ;
T_2 V_541 = 0 ;
T_2 V_153 = V_563 ;
if ( V_497 != sizeof( * V_273 ) )
return - V_500 ;
V_541 = F_229 ( V_273 -> V_541 ) ;
F_23 ( L_62 , V_541 , V_273 -> V_539 ) ;
if ( ! ( V_13 -> V_263 & V_264 ) )
return - V_29 ;
V_23 = F_11 ( V_13 , V_541 ) ;
if ( ! V_23 ) {
V_152 . V_541 = F_18 ( V_541 ) ;
V_152 . V_153 = F_18 ( V_563 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_545 ,
sizeof( V_152 ) , & V_152 ) ;
return 0 ;
}
V_23 -> V_19 = V_425 -> V_19 ;
if ( V_23 -> V_17 < V_37 ||
V_23 -> V_270 == V_567 ||
( V_23 -> V_141 != V_144 &&
V_23 -> V_141 != V_148 ) ) {
V_153 = V_563 ;
goto V_568;
}
if ( V_23 -> V_443 == V_273 -> V_539 ) {
V_153 = V_569 ;
goto V_568;
}
if ( V_273 -> V_539 != V_444 ) {
struct V_261 * V_189 ;
V_189 = F_256 ( V_273 -> V_539 ) ;
if ( ! V_189 || V_189 -> V_534 != V_535 ||
! F_70 ( V_269 , & V_189 -> V_103 ) ) {
if ( V_189 )
F_257 ( V_189 ) ;
V_153 = V_565 ;
goto V_568;
}
F_257 ( V_189 ) ;
}
if ( ( F_95 ( V_23 ) ||
V_23 -> V_288 != V_289 ) &&
F_15 ( & V_13 -> V_8 -> V_21 , & V_13 -> V_8 -> V_150 ) > 0 ) {
V_153 = V_570 ;
goto V_568;
}
V_23 -> V_288 = V_293 ;
F_127 ( V_23 ) ;
V_23 -> V_445 = V_273 -> V_539 ;
V_541 = V_23 -> V_16 ;
if ( V_273 -> V_539 == V_444 ) {
if ( F_70 ( V_258 , & V_23 -> V_252 ) ) {
V_23 -> V_197 = V_556 ;
V_153 = V_571 ;
} else {
V_23 -> V_197 = V_559 ;
V_153 = V_560 ;
}
} else {
V_23 -> V_197 = V_199 ;
V_153 = V_571 ;
}
V_568:
F_260 ( V_23 , V_153 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static void F_276 ( struct V_12 * V_13 , T_2 V_541 , T_2 V_153 )
{
struct V_11 * V_23 ;
struct V_140 * V_196 = NULL ;
V_23 = F_7 ( V_13 , V_541 ) ;
if ( ! V_23 ) {
F_262 ( V_13 , V_541 ) ;
return;
}
F_74 ( V_23 ) ;
if ( V_153 == V_571 )
F_85 ( V_23 , V_572 ) ;
switch ( V_23 -> V_197 ) {
case V_553 :
V_23 -> V_197 = V_554 ;
break;
case V_555 :
if ( V_153 == V_571 ) {
break;
} else if ( F_70 ( V_258 ,
& V_23 -> V_252 ) ) {
V_23 -> V_197 = V_556 ;
} else {
V_23 -> V_197 = V_557 ;
F_261 ( V_23 , V_558 ) ;
}
break;
case V_562 :
if ( V_153 == V_560 ) {
V_23 -> V_197 = V_554 ;
} else {
V_23 -> V_197 = V_553 ;
}
if ( ! V_196 ) {
F_261 ( V_23 , V_549 ) ;
break;
}
if ( V_196 -> V_38 != V_68 )
break;
V_23 -> V_200 = V_196 -> V_13 ;
V_23 -> V_200 -> V_356 = V_23 -> V_13 ;
if ( V_153 == V_560 ) {
F_261 ( V_23 , V_558 ) ;
} else {
V_23 -> V_197 = V_555 ;
}
F_268 ( V_23 , V_196 , V_560 ) ;
break;
default:
V_23 -> V_445 = V_23 -> V_443 ;
F_128 ( V_23 ) ;
F_261 ( V_23 , V_549 ) ;
}
F_48 ( V_23 ) ;
}
static void F_277 ( struct V_12 * V_13 , T_1 V_19 , T_2 V_541 ,
T_2 V_153 )
{
struct V_11 * V_23 ;
V_23 = F_13 ( V_13 , V_19 ) ;
if ( ! V_23 ) {
F_262 ( V_13 , V_541 ) ;
return;
}
F_74 ( V_23 ) ;
if ( V_23 -> V_288 == V_290 ) {
if ( V_153 == V_570 ) {
V_23 -> V_288 = V_293 ;
} else {
V_23 -> V_445 = V_23 -> V_443 ;
F_128 ( V_23 ) ;
}
}
F_261 ( V_23 , V_549 ) ;
F_48 ( V_23 ) ;
}
static int F_278 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_188 )
{
struct V_544 * V_152 = V_188 ;
T_2 V_541 , V_153 ;
if ( V_497 != sizeof( * V_152 ) )
return - V_500 ;
V_541 = F_229 ( V_152 -> V_541 ) ;
V_153 = F_229 ( V_152 -> V_153 ) ;
F_23 ( L_63 , V_541 , V_153 ) ;
if ( V_153 == V_560 || V_153 == V_571 )
F_276 ( V_13 , V_541 , V_153 ) ;
else
F_277 ( V_13 , V_425 -> V_19 , V_541 , V_153 ) ;
return 0 ;
}
static int F_279 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_188 )
{
struct V_546 * V_547 = V_188 ;
struct V_11 * V_23 ;
T_2 V_541 , V_153 ;
if ( V_497 != sizeof( * V_547 ) )
return - V_500 ;
V_541 = F_229 ( V_547 -> V_541 ) ;
V_153 = F_229 ( V_547 -> V_153 ) ;
F_23 ( L_63 , V_541 , V_153 ) ;
V_23 = F_11 ( V_13 , V_541 ) ;
if ( ! V_23 ) {
F_263 ( V_13 , V_425 -> V_19 , V_541 ) ;
return 0 ;
}
if ( V_23 -> V_197 == V_559 ) {
if ( V_153 == V_558 ) {
V_23 -> V_443 = V_23 -> V_445 ;
if ( V_23 -> V_443 == V_444 )
F_264 ( V_23 ) ;
} else {
V_23 -> V_445 = V_23 -> V_443 ;
}
F_128 ( V_23 ) ;
}
F_263 ( V_13 , V_425 -> V_19 , V_541 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static inline int F_280 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_188 )
{
struct V_550 * V_152 = V_188 ;
struct V_11 * V_23 ;
T_2 V_541 ;
if ( V_497 != sizeof( * V_152 ) )
return - V_500 ;
V_541 = F_229 ( V_152 -> V_541 ) ;
F_23 ( L_57 , V_541 ) ;
V_23 = F_7 ( V_13 , V_541 ) ;
if ( ! V_23 )
return 0 ;
F_74 ( V_23 ) ;
if ( V_23 -> V_197 == V_557 ) {
V_23 -> V_443 = V_23 -> V_445 ;
if ( V_23 -> V_443 == V_444 && V_23 -> V_139 )
F_264 ( V_23 ) ;
F_128 ( V_23 ) ;
}
F_48 ( V_23 ) ;
return 0 ;
}
static inline int V_338 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_2 V_497 , T_1 * V_188 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_338 * V_273 ;
struct V_573 V_152 ;
T_2 V_339 , V_340 , V_341 , V_343 ;
int V_24 ;
if ( V_8 -> V_333 != V_574 )
return - V_29 ;
if ( V_497 != sizeof( struct V_338 ) )
return - V_500 ;
V_273 = (struct V_338 * ) V_188 ;
V_339 = F_69 ( V_273 -> V_339 ) ;
V_340 = F_69 ( V_273 -> V_340 ) ;
V_341 = F_69 ( V_273 -> V_341 ) ;
V_343 = F_69 ( V_273 -> V_343 ) ;
F_23 ( L_64 ,
V_339 , V_340 , V_341 , V_343 ) ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_24 = F_281 ( V_339 , V_340 , V_341 , V_343 ) ;
if ( V_24 )
V_152 . V_153 = F_18 ( V_575 ) ;
else
V_152 . V_153 = F_18 ( V_576 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_577 ,
sizeof( V_152 ) , & V_152 ) ;
if ( ! V_24 ) {
T_1 V_578 ;
V_578 = F_282 ( V_8 , V_339 , V_340 , V_341 ,
V_343 ) ;
F_283 ( V_8 -> V_189 , & V_8 -> V_150 , V_8 -> V_10 ,
V_578 , V_339 , V_340 , V_341 ,
V_343 ) ;
}
return 0 ;
}
static int F_284 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_151 * V_152 = (struct V_151 * ) V_188 ;
struct V_7 * V_8 = V_13 -> V_8 ;
T_2 V_16 , V_158 , V_110 , V_159 , V_153 ;
struct V_11 * V_23 ;
int V_24 , V_72 ;
if ( V_497 < sizeof( * V_152 ) )
return - V_500 ;
V_16 = F_69 ( V_152 -> V_16 ) ;
V_158 = F_69 ( V_152 -> V_158 ) ;
V_110 = F_69 ( V_152 -> V_110 ) ;
V_159 = F_69 ( V_152 -> V_159 ) ;
V_153 = F_69 ( V_152 -> V_153 ) ;
if ( V_153 == V_325 && ( V_158 < 23 || V_110 < 23 ) )
return - V_500 ;
F_23 ( L_65 ,
V_16 , V_158 , V_110 , V_159 , V_153 ) ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_12 ( V_13 , V_425 -> V_19 ) ;
if ( ! V_23 ) {
V_24 = - V_512 ;
goto V_513;
}
V_24 = 0 ;
F_9 ( V_23 ) ;
switch ( V_153 ) {
case V_325 :
V_23 -> V_19 = 0 ;
V_23 -> V_16 = V_16 ;
V_23 -> V_30 = V_158 ;
V_23 -> V_399 = V_110 ;
V_23 -> V_107 = V_159 ;
F_130 ( V_23 ) ;
break;
case V_579 :
case V_580 :
if ( V_8 -> V_72 > V_173 ) {
F_73 ( V_23 , V_70 ) ;
break;
}
V_72 = V_8 -> V_72 + 1 ;
if ( V_23 -> V_72 < V_72 )
V_23 -> V_72 = V_72 ;
F_117 ( V_298 , & V_23 -> V_103 ) ;
F_89 ( V_8 , V_23 -> V_72 ) ;
break;
default:
F_73 ( V_23 , V_70 ) ;
break;
}
F_48 ( V_23 ) ;
V_513:
F_10 ( & V_13 -> V_18 ) ;
return V_24 ;
}
static inline int F_285 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
int V_24 = 0 ;
switch ( V_425 -> V_186 ) {
case V_517 :
F_236 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_274 :
V_24 = F_240 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_165 :
case V_495 :
F_243 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_328 :
V_24 = F_248 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_514 :
F_249 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_317 :
V_24 = F_251 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_525 :
F_252 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_581 :
F_83 ( V_13 , V_425 -> V_19 , V_582 , V_497 , V_188 ) ;
break;
case V_582 :
break;
case V_307 :
V_24 = F_253 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_529 :
F_254 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_277 :
V_24 = F_255 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_542 :
V_24 = F_275 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_545 :
F_278 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_548 :
V_24 = F_279 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_551 :
F_280 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
default:
F_286 ( L_66 , V_425 -> V_186 ) ;
V_24 = - V_29 ;
break;
}
return V_24 ;
}
static int F_287 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_297 * V_273 = (struct V_297 * ) V_188 ;
struct V_151 V_152 ;
struct V_11 * V_23 , * V_502 ;
T_2 V_16 , V_17 , V_159 , V_158 , V_110 ;
T_3 V_20 ;
T_1 V_153 ;
if ( V_497 != sizeof( * V_273 ) )
return - V_500 ;
V_17 = F_69 ( V_273 -> V_17 ) ;
V_158 = F_69 ( V_273 -> V_158 ) ;
V_110 = F_69 ( V_273 -> V_110 ) ;
V_20 = V_273 -> V_20 ;
V_16 = 0 ;
V_159 = 0 ;
if ( V_158 < 23 || V_110 < 23 )
return - V_500 ;
F_23 ( L_67 , F_69 ( V_20 ) ,
V_17 , V_158 , V_110 ) ;
V_502 = F_165 ( V_166 , V_20 , & V_13 -> V_8 -> V_21 ,
& V_13 -> V_8 -> V_150 , V_2 ) ;
if ( ! V_502 ) {
V_153 = V_156 ;
V_23 = NULL ;
goto V_505;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_502 ) ;
if ( ! F_288 ( V_13 -> V_8 , V_502 -> V_72 ,
V_583 ) ) {
V_153 = V_579 ;
V_23 = NULL ;
goto V_584;
}
if ( F_4 ( V_13 , V_17 ) ) {
V_153 = V_506 ;
V_23 = NULL ;
goto V_584;
}
V_23 = V_502 -> V_39 -> V_507 ( V_502 ) ;
if ( ! V_23 ) {
V_153 = V_506 ;
goto V_584;
}
F_65 ( V_23 ) ;
F_81 ( & V_23 -> V_21 , & V_13 -> V_8 -> V_21 ) ;
F_81 ( & V_23 -> V_150 , & V_13 -> V_8 -> V_150 ) ;
V_23 -> V_9 = F_2 ( V_13 -> V_8 ) ;
V_23 -> V_10 = F_3 ( V_13 -> V_8 ) ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_17 ;
V_23 -> V_30 = V_158 ;
V_23 -> V_399 = V_110 ;
V_23 -> V_107 = F_69 ( V_273 -> V_159 ) ;
F_68 ( V_13 , V_23 ) ;
V_16 = V_23 -> V_17 ;
V_159 = V_23 -> V_108 ;
F_85 ( V_23 , V_23 -> V_39 -> V_167 ( V_23 ) ) ;
V_23 -> V_19 = V_425 -> V_19 ;
if ( F_70 ( V_154 , & V_23 -> V_103 ) ) {
F_22 ( V_23 , V_168 ) ;
V_153 = V_322 ;
V_23 -> V_39 -> V_324 ( V_23 ) ;
} else {
F_130 ( V_23 ) ;
V_153 = V_325 ;
}
V_584:
F_48 ( V_502 ) ;
F_10 ( & V_13 -> V_18 ) ;
F_49 ( V_502 ) ;
if ( V_153 == V_322 )
return 0 ;
V_505:
if ( V_23 ) {
V_152 . V_158 = F_18 ( V_23 -> V_111 ) ;
V_152 . V_110 = F_18 ( V_23 -> V_110 ) ;
} else {
V_152 . V_158 = 0 ;
V_152 . V_110 = 0 ;
}
V_152 . V_16 = F_18 ( V_16 ) ;
V_152 . V_159 = F_18 ( V_159 ) ;
V_152 . V_153 = F_18 ( V_153 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_160 , sizeof( V_152 ) , & V_152 ) ;
return 0 ;
}
static inline int F_289 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct F_289 * V_585 ;
struct V_11 * V_23 ;
T_2 V_14 , V_159 , V_586 ;
if ( V_497 != sizeof( * V_585 ) )
return - V_500 ;
V_585 = (struct F_289 * ) V_188 ;
V_14 = F_69 ( V_585 -> V_14 ) ;
V_159 = F_69 ( V_585 -> V_159 ) ;
F_23 ( L_68 , V_14 , V_159 ) ;
V_23 = F_11 ( V_13 , V_14 ) ;
if ( ! V_23 )
return - V_512 ;
V_586 = V_587 - V_23 -> V_107 ;
if ( V_159 > V_586 ) {
F_286 ( L_69 ) ;
F_86 ( V_23 , V_320 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
V_23 -> V_107 += V_159 ;
while ( V_23 -> V_107 && ! F_170 ( & V_23 -> V_113 ) ) {
F_96 ( V_23 , F_171 ( & V_23 -> V_113 ) ) ;
V_23 -> V_107 -- ;
}
if ( V_23 -> V_107 )
V_23 -> V_39 -> V_588 ( V_23 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static inline int F_290 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_498 * V_499 = (struct V_498 * ) V_188 ;
struct V_11 * V_23 ;
if ( V_497 < sizeof( * V_499 ) )
return - V_500 ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_12 ( V_13 , V_425 -> V_19 ) ;
if ( ! V_23 )
goto V_27;
F_9 ( V_23 ) ;
F_73 ( V_23 , V_70 ) ;
F_48 ( V_23 ) ;
V_27:
F_10 ( & V_13 -> V_18 ) ;
return 0 ;
}
static inline int F_291 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
int V_24 = 0 ;
switch ( V_425 -> V_186 ) {
case V_517 :
F_290 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_345 :
V_24 = V_338 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_577 :
break;
case V_160 :
F_284 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_299 :
V_24 = F_287 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_589 :
V_24 = F_289 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_317 :
V_24 = F_251 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_525 :
F_252 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
default:
F_286 ( L_70 , V_425 -> V_186 ) ;
V_24 = - V_29 ;
break;
}
return V_24 ;
}
static inline void F_292 ( struct V_12 * V_13 ,
struct V_45 * V_49 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_424 * V_425 ;
T_2 V_187 ;
int V_24 ;
if ( V_8 -> type != V_2 )
goto V_590;
if ( V_49 -> V_187 < V_426 )
goto V_590;
V_425 = ( void * ) V_49 -> V_188 ;
F_102 ( V_49 , V_426 ) ;
V_187 = F_229 ( V_425 -> V_187 ) ;
F_23 ( L_71 , V_425 -> V_186 , V_187 , V_425 -> V_19 ) ;
if ( V_187 != V_49 -> V_187 || ! V_425 -> V_19 ) {
F_23 ( L_72 ) ;
goto V_590;
}
V_24 = F_291 ( V_13 , V_425 , V_187 , V_49 -> V_188 ) ;
if ( V_24 ) {
struct V_498 V_499 ;
F_286 ( L_73 , V_24 ) ;
V_499 . V_67 = F_18 ( V_501 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_517 ,
sizeof( V_499 ) , & V_499 ) ;
}
V_590:
F_97 ( V_49 ) ;
}
static inline void F_293 ( struct V_12 * V_13 ,
struct V_45 * V_49 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
T_1 * V_188 = V_49 -> V_188 ;
int V_187 = V_49 -> V_187 ;
struct V_424 V_425 ;
int V_24 ;
F_215 ( V_13 , V_49 ) ;
if ( V_8 -> type != V_117 )
goto V_590;
while ( V_187 >= V_426 ) {
T_2 V_497 ;
memcpy ( & V_425 , V_188 , V_426 ) ;
V_188 += V_426 ;
V_187 -= V_426 ;
V_497 = F_229 ( V_425 . V_187 ) ;
F_23 ( L_71 , V_425 . V_186 , V_497 ,
V_425 . V_19 ) ;
if ( V_497 > V_187 || ! V_425 . V_19 ) {
F_23 ( L_72 ) ;
break;
}
V_24 = F_285 ( V_13 , & V_425 , V_497 , V_188 ) ;
if ( V_24 ) {
struct V_498 V_499 ;
F_286 ( L_73 , V_24 ) ;
V_499 . V_67 = F_18 ( V_501 ) ;
F_83 ( V_13 , V_425 . V_19 , V_517 ,
sizeof( V_499 ) , & V_499 ) ;
}
V_188 += V_497 ;
V_187 -= V_497 ;
}
V_590:
F_97 ( V_49 ) ;
}
static int F_294 ( struct V_11 * V_23 , struct V_45 * V_49 )
{
T_2 V_591 , V_592 ;
int V_593 ;
if ( F_70 ( V_239 , & V_23 -> V_103 ) )
V_593 = V_244 ;
else
V_593 = V_245 ;
if ( V_23 -> V_87 == V_88 ) {
F_295 ( V_49 , V_49 -> V_187 - V_249 ) ;
V_592 = F_103 ( V_49 -> V_188 + V_49 -> V_187 ) ;
V_591 = F_114 ( 0 , V_49 -> V_188 - V_593 , V_49 -> V_187 + V_593 ) ;
if ( V_591 != V_592 )
return - V_594 ;
}
return 0 ;
}
static void F_296 ( struct V_11 * V_23 )
{
struct V_204 V_205 ;
F_23 ( L_3 , V_23 ) ;
memset ( & V_205 , 0 , sizeof( V_205 ) ) ;
V_205 . V_213 = 1 ;
V_205 . V_209 = 1 ;
V_205 . V_206 = V_23 -> V_259 ;
F_57 ( V_251 , & V_23 -> V_252 ) ;
if ( F_70 ( V_258 , & V_23 -> V_252 ) ) {
V_205 . V_217 = V_255 ;
F_115 ( V_23 , & V_205 ) ;
}
if ( F_116 ( V_287 , & V_23 -> V_252 ) &&
V_23 -> V_377 > 0 )
F_27 ( V_23 ) ;
F_173 ( V_23 ) ;
if ( ! F_70 ( V_258 , & V_23 -> V_252 ) &&
F_70 ( V_251 , & V_23 -> V_252 ) ) {
V_205 . V_217 = V_253 ;
F_115 ( V_23 , & V_205 ) ;
}
}
static void F_297 ( struct V_45 * V_49 , struct V_45 * V_595 ,
struct V_45 * * V_596 )
{
if ( ! F_298 ( V_49 ) )
F_190 ( V_49 ) -> V_387 = V_595 ;
V_595 -> V_392 = NULL ;
( * V_596 ) -> V_392 = V_595 ;
* V_596 = V_595 ;
V_49 -> V_187 += V_595 -> V_187 ;
V_49 -> V_391 += V_595 -> V_187 ;
V_49 -> V_597 += V_595 -> V_597 ;
}
static int F_299 ( struct V_11 * V_23 , struct V_45 * V_49 ,
struct V_204 * V_205 )
{
int V_24 = - V_29 ;
switch ( V_205 -> V_220 ) {
case V_400 :
if ( V_23 -> V_104 )
break;
V_24 = V_23 -> V_39 -> V_422 ( V_23 , V_49 ) ;
break;
case V_401 :
if ( V_23 -> V_104 )
break;
V_23 -> V_106 = F_103 ( V_49 -> V_188 ) ;
F_102 ( V_49 , V_395 ) ;
if ( V_23 -> V_106 > V_23 -> V_111 ) {
V_24 = - V_404 ;
break;
}
if ( V_49 -> V_187 >= V_23 -> V_106 )
break;
V_23 -> V_104 = V_49 ;
V_23 -> V_105 = V_49 ;
V_49 = NULL ;
V_24 = 0 ;
break;
case V_403 :
if ( ! V_23 -> V_104 )
break;
F_297 ( V_23 -> V_104 , V_49 ,
& V_23 -> V_105 ) ;
V_49 = NULL ;
if ( V_23 -> V_104 -> V_187 >= V_23 -> V_106 )
break;
V_24 = 0 ;
break;
case V_402 :
if ( ! V_23 -> V_104 )
break;
F_297 ( V_23 -> V_104 , V_49 ,
& V_23 -> V_105 ) ;
V_49 = NULL ;
if ( V_23 -> V_104 -> V_187 != V_23 -> V_106 )
break;
V_24 = V_23 -> V_39 -> V_422 ( V_23 , V_23 -> V_104 ) ;
if ( ! V_24 ) {
V_23 -> V_104 = NULL ;
V_23 -> V_105 = NULL ;
V_23 -> V_106 = 0 ;
}
break;
}
if ( V_24 ) {
F_97 ( V_49 ) ;
F_97 ( V_23 -> V_104 ) ;
V_23 -> V_104 = NULL ;
V_23 -> V_105 = NULL ;
V_23 -> V_106 = 0 ;
}
return V_24 ;
}
static int F_300 ( struct V_11 * V_23 )
{
return 0 ;
}
void F_301 ( struct V_11 * V_23 , int V_598 )
{
T_1 V_412 ;
if ( V_23 -> V_141 != V_144 )
return;
V_412 = V_598 ? V_413 : V_415 ;
F_129 ( V_23 , NULL , NULL , V_412 ) ;
}
static int F_302 ( struct V_11 * V_23 )
{
int V_24 = 0 ;
F_23 ( L_3 , V_23 ) ;
while ( ! F_70 ( V_258 , & V_23 -> V_252 ) ) {
struct V_45 * V_49 ;
F_23 ( L_74 ,
V_23 -> V_259 , F_177 ( & V_23 -> V_145 ) ) ;
V_49 = F_33 ( & V_23 -> V_145 , V_23 -> V_259 ) ;
if ( ! V_49 )
break;
F_208 ( V_49 , & V_23 -> V_145 ) ;
V_23 -> V_259 = F_172 ( V_23 , V_23 -> V_259 ) ;
V_24 = F_299 ( V_23 , V_49 , & F_35 ( V_49 ) -> V_50 ) ;
if ( V_24 )
break;
}
if ( F_170 ( & V_23 -> V_145 ) ) {
V_23 -> V_285 = V_380 ;
F_185 ( V_23 ) ;
}
return V_24 ;
}
static void F_303 ( struct V_11 * V_23 ,
struct V_204 * V_205 )
{
struct V_45 * V_49 ;
F_23 ( L_10 , V_23 , V_205 ) ;
if ( V_205 -> V_206 == V_23 -> V_371 ) {
F_23 ( L_75 , V_205 -> V_206 ) ;
F_86 ( V_23 , V_320 ) ;
return;
}
V_49 = F_33 ( & V_23 -> V_113 , V_205 -> V_206 ) ;
if ( V_49 == NULL ) {
F_23 ( L_76 ,
V_205 -> V_206 ) ;
return;
}
if ( V_23 -> V_89 != 0 && F_35 ( V_49 ) -> V_50 . V_279 >= V_23 -> V_89 ) {
F_23 ( L_21 , V_23 -> V_89 ) ;
F_86 ( V_23 , V_320 ) ;
return;
}
F_117 ( V_287 , & V_23 -> V_252 ) ;
if ( V_205 -> V_214 ) {
F_213 ( V_23 , V_205 ) ;
F_57 ( V_251 , & V_23 -> V_252 ) ;
F_182 ( V_23 , V_205 ) ;
F_173 ( V_23 ) ;
if ( V_23 -> V_283 == V_417 ) {
F_57 ( V_282 , & V_23 -> V_252 ) ;
V_23 -> V_599 = V_205 -> V_206 ;
}
} else {
F_214 ( V_23 , V_205 ) ;
if ( V_205 -> V_209 ) {
if ( V_23 -> V_599 != V_205 -> V_206 ||
! F_116 ( V_282 ,
& V_23 -> V_252 ) )
F_182 ( V_23 , V_205 ) ;
} else {
F_182 ( V_23 , V_205 ) ;
if ( V_23 -> V_283 == V_417 ) {
F_57 ( V_282 , & V_23 -> V_252 ) ;
V_23 -> V_599 = V_205 -> V_206 ;
}
}
}
}
static void F_304 ( struct V_11 * V_23 ,
struct V_204 * V_205 )
{
struct V_45 * V_49 ;
F_23 ( L_10 , V_23 , V_205 ) ;
if ( V_205 -> V_206 == V_23 -> V_371 ) {
F_23 ( L_75 , V_205 -> V_206 ) ;
F_86 ( V_23 , V_320 ) ;
return;
}
V_49 = F_33 ( & V_23 -> V_113 , V_205 -> V_206 ) ;
if ( V_23 -> V_89 && V_49 &&
F_35 ( V_49 ) -> V_50 . V_279 >= V_23 -> V_89 ) {
F_23 ( L_21 , V_23 -> V_89 ) ;
F_86 ( V_23 , V_320 ) ;
return;
}
F_117 ( V_287 , & V_23 -> V_252 ) ;
F_213 ( V_23 , V_205 ) ;
if ( V_205 -> V_209 ) {
if ( ! F_116 ( V_281 , & V_23 -> V_252 ) )
F_183 ( V_23 , V_205 ) ;
} else {
F_183 ( V_23 , V_205 ) ;
F_173 ( V_23 ) ;
if ( V_23 -> V_283 == V_417 )
F_57 ( V_281 , & V_23 -> V_252 ) ;
}
}
static T_1 F_305 ( struct V_11 * V_23 , T_2 V_51 )
{
F_23 ( L_77 , V_23 , V_51 ) ;
F_23 ( L_78 , V_23 -> V_257 ,
V_23 -> V_280 ) ;
if ( V_23 -> V_285 == V_414 ) {
if ( F_186 ( V_23 , V_51 , V_23 -> V_257 ) >=
V_23 -> V_91 ) {
if ( V_23 -> V_91 <= ( ( V_23 -> V_93 + 1 ) >> 1 ) ) {
F_23 ( L_79 ) ;
return V_600 ;
} else {
F_23 ( L_80 ) ;
return V_601 ;
}
}
if ( V_23 -> V_146 . V_47 == V_51 ) {
F_23 ( L_81 ) ;
return V_602 ;
}
if ( F_33 ( & V_23 -> V_145 , V_51 ) ) {
F_23 ( L_82 ) ;
return V_603 ;
}
if ( F_41 ( & V_23 -> V_146 , V_51 ) ) {
F_23 ( L_83 ) ;
return V_604 ;
}
}
if ( V_23 -> V_280 == V_51 ) {
if ( F_186 ( V_23 , V_51 , V_23 -> V_257 ) >=
V_23 -> V_91 ) {
F_23 ( L_84 ) ;
return V_601 ;
} else {
F_23 ( L_85 ) ;
return V_605 ;
}
}
if ( F_186 ( V_23 , V_51 , V_23 -> V_257 ) <
F_186 ( V_23 , V_23 -> V_280 , V_23 -> V_257 ) ) {
F_23 ( L_86 ) ;
return V_606 ;
}
if ( F_186 ( V_23 , V_51 , V_23 -> V_257 ) >= V_23 -> V_91 ) {
if ( V_23 -> V_91 <= ( ( V_23 -> V_93 + 1 ) >> 1 ) ) {
F_23 ( L_87 ) ;
return V_600 ;
} else {
F_23 ( L_84 ) ;
return V_601 ;
}
} else {
F_23 ( L_88 ) ;
return V_607 ;
}
}
static int F_306 ( struct V_11 * V_23 ,
struct V_204 * V_205 ,
struct V_45 * V_49 , T_1 V_412 )
{
int V_24 = 0 ;
bool V_608 = false ;
F_23 ( L_89 , V_23 , V_205 , V_49 ,
V_412 ) ;
switch ( V_412 ) {
case V_609 :
switch ( F_305 ( V_23 , V_205 -> V_51 ) ) {
case V_605 :
F_213 ( V_23 , V_205 ) ;
if ( F_70 ( V_258 , & V_23 -> V_252 ) ) {
F_23 ( L_90 ,
V_205 -> V_51 ) ;
break;
}
V_23 -> V_280 = F_172 ( V_23 ,
V_205 -> V_51 ) ;
V_23 -> V_259 = V_23 -> V_280 ;
V_608 = true ;
V_24 = F_299 ( V_23 , V_49 , V_205 ) ;
if ( V_24 )
break;
if ( V_205 -> V_209 ) {
if ( ! F_116 ( V_281 ,
& V_23 -> V_252 ) ) {
V_205 -> V_209 = 0 ;
F_183 ( V_23 , V_205 ) ;
F_173 ( V_23 ) ;
}
}
if ( ! F_70 ( V_258 , & V_23 -> V_252 ) )
F_185 ( V_23 ) ;
break;
case V_607 :
F_213 ( V_23 , V_205 ) ;
if ( F_70 ( V_258 , & V_23 -> V_252 ) ) {
F_23 ( L_91 ,
V_205 -> V_51 ) ;
break;
}
F_307 ( & V_23 -> V_145 , V_49 ) ;
V_608 = true ;
F_23 ( L_92 , V_49 ,
F_177 ( & V_23 -> V_145 ) ) ;
F_117 ( V_282 , & V_23 -> V_252 ) ;
F_43 ( & V_23 -> V_146 ) ;
F_204 ( V_23 , V_205 -> V_51 ) ;
V_23 -> V_285 = V_414 ;
break;
case V_606 :
F_213 ( V_23 , V_205 ) ;
break;
case V_600 :
break;
case V_601 :
default:
F_86 ( V_23 , V_320 ) ;
break;
}
break;
case V_610 :
F_213 ( V_23 , V_205 ) ;
if ( V_205 -> V_209 ) {
F_117 ( V_287 , & V_23 -> V_252 ) ;
if ( ! F_116 ( V_281 , & V_23 -> V_252 ) &&
! F_95 ( V_23 ) ) {
V_205 -> V_209 = 0 ;
F_183 ( V_23 , V_205 ) ;
}
F_173 ( V_23 ) ;
} else if ( V_205 -> V_214 ) {
F_296 ( V_23 ) ;
} else {
if ( F_116 ( V_287 ,
& V_23 -> V_252 ) &&
V_23 -> V_377 )
F_27 ( V_23 ) ;
F_173 ( V_23 ) ;
}
break;
case V_611 :
F_57 ( V_287 , & V_23 -> V_252 ) ;
F_213 ( V_23 , V_205 ) ;
if ( V_205 && V_205 -> V_214 ) {
F_57 ( V_251 , & V_23 -> V_252 ) ;
F_119 ( V_23 , 0 ) ;
}
F_32 ( V_23 ) ;
F_43 ( & V_23 -> V_147 ) ;
break;
case V_612 :
F_304 ( V_23 , V_205 ) ;
break;
case V_613 :
F_303 ( V_23 , V_205 ) ;
break;
default:
break;
}
if ( V_49 && ! V_608 ) {
F_23 ( L_93 , V_49 ) ;
F_97 ( V_49 ) ;
}
return V_24 ;
}
static int F_308 ( struct V_11 * V_23 ,
struct V_204 * V_205 ,
struct V_45 * V_49 , T_1 V_412 )
{
int V_24 = 0 ;
T_2 V_51 = V_205 -> V_51 ;
bool V_608 = false ;
F_23 ( L_89 , V_23 , V_205 , V_49 ,
V_412 ) ;
switch ( V_412 ) {
case V_609 :
switch ( F_305 ( V_23 , V_51 ) ) {
case V_605 :
F_213 ( V_23 , V_205 ) ;
F_307 ( & V_23 -> V_145 , V_49 ) ;
V_608 = true ;
F_23 ( L_92 , V_49 ,
F_177 ( & V_23 -> V_145 ) ) ;
V_23 -> V_280 = F_172 ( V_23 , V_51 ) ;
break;
case V_602 :
F_42 ( & V_23 -> V_146 ) ;
F_213 ( V_23 , V_205 ) ;
F_307 ( & V_23 -> V_145 , V_49 ) ;
V_608 = true ;
F_23 ( L_92 , V_49 ,
F_177 ( & V_23 -> V_145 ) ) ;
V_24 = F_302 ( V_23 ) ;
if ( V_24 )
break;
break;
case V_607 :
F_307 ( & V_23 -> V_145 , V_49 ) ;
V_608 = true ;
F_23 ( L_92 , V_49 ,
F_177 ( & V_23 -> V_145 ) ) ;
F_213 ( V_23 , V_205 ) ;
F_204 ( V_23 , V_205 -> V_51 ) ;
break;
case V_604 :
F_307 ( & V_23 -> V_145 , V_49 ) ;
V_608 = true ;
F_23 ( L_92 , V_49 ,
F_177 ( & V_23 -> V_145 ) ) ;
F_213 ( V_23 , V_205 ) ;
F_206 ( V_23 , V_205 -> V_51 ) ;
break;
case V_603 :
F_213 ( V_23 , V_205 ) ;
break;
case V_606 :
break;
case V_600 :
break;
case V_601 :
default:
F_86 ( V_23 , V_320 ) ;
break;
}
break;
case V_610 :
F_213 ( V_23 , V_205 ) ;
if ( V_205 -> V_209 ) {
F_117 ( V_287 , & V_23 -> V_252 ) ;
if ( ! F_116 ( V_281 ,
& V_23 -> V_252 ) ) {
V_205 -> V_209 = 0 ;
F_183 ( V_23 , V_205 ) ;
}
F_173 ( V_23 ) ;
} else if ( V_205 -> V_214 ) {
if ( F_116 ( V_287 ,
& V_23 -> V_252 ) &&
V_23 -> V_377 ) {
F_27 ( V_23 ) ;
}
F_57 ( V_251 , & V_23 -> V_252 ) ;
F_205 ( V_23 ) ;
} else {
if ( F_116 ( V_287 ,
& V_23 -> V_252 ) &&
V_23 -> V_377 )
F_27 ( V_23 ) ;
F_185 ( V_23 ) ;
}
break;
case V_611 :
F_57 ( V_287 , & V_23 -> V_252 ) ;
F_213 ( V_23 , V_205 ) ;
if ( V_205 -> V_214 ) {
F_205 ( V_23 ) ;
} else {
struct V_204 V_614 ;
memset ( & V_614 , 0 , sizeof( V_614 ) ) ;
V_614 . V_213 = 1 ;
V_614 . V_217 = V_253 ;
V_614 . V_206 = V_23 -> V_259 ;
F_115 ( V_23 , & V_614 ) ;
}
break;
case V_612 :
F_304 ( V_23 , V_205 ) ;
break;
case V_613 :
F_303 ( V_23 , V_205 ) ;
break;
}
if ( V_49 && ! V_608 ) {
F_23 ( L_93 , V_49 ) ;
F_97 ( V_49 ) ;
}
return V_24 ;
}
static int F_309 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
V_23 -> V_285 = V_380 ;
if ( V_23 -> V_200 )
V_23 -> V_13 -> V_158 = V_23 -> V_200 -> V_189 -> V_537 ;
else
V_23 -> V_13 -> V_158 = V_23 -> V_13 -> V_8 -> V_189 -> V_615 ;
return F_300 ( V_23 ) ;
}
static int F_310 ( struct V_11 * V_23 ,
struct V_204 * V_205 ,
struct V_45 * V_49 , T_1 V_412 )
{
int V_24 ;
F_23 ( L_89 , V_23 , V_205 , V_49 ,
V_412 ) ;
if ( ! V_205 -> V_214 )
return - V_500 ;
F_207 ( V_23 , V_205 -> V_206 ) ;
if ( ! F_170 ( & V_23 -> V_113 ) )
V_23 -> V_376 = F_211 ( & V_23 -> V_113 ) ;
else
V_23 -> V_376 = NULL ;
V_23 -> V_371 = V_205 -> V_206 ;
V_23 -> V_377 = 0 ;
V_24 = F_309 ( V_23 ) ;
if ( V_24 )
return V_24 ;
F_57 ( V_251 , & V_23 -> V_252 ) ;
F_296 ( V_23 ) ;
if ( V_412 == V_609 )
return - V_500 ;
return F_306 ( V_23 , V_205 , NULL , V_412 ) ;
}
static int F_311 ( struct V_11 * V_23 ,
struct V_204 * V_205 ,
struct V_45 * V_49 , T_1 V_412 )
{
int V_24 ;
if ( ! V_205 -> V_209 )
return - V_500 ;
F_117 ( V_287 , & V_23 -> V_252 ) ;
V_23 -> V_285 = V_380 ;
F_207 ( V_23 , V_205 -> V_206 ) ;
if ( ! F_170 ( & V_23 -> V_113 ) )
V_23 -> V_376 = F_211 ( & V_23 -> V_113 ) ;
else
V_23 -> V_376 = NULL ;
V_23 -> V_371 = V_205 -> V_206 ;
V_23 -> V_377 = 0 ;
if ( V_23 -> V_200 )
V_23 -> V_13 -> V_158 = V_23 -> V_200 -> V_189 -> V_537 ;
else
V_23 -> V_13 -> V_158 = V_23 -> V_13 -> V_8 -> V_189 -> V_615 ;
V_24 = F_300 ( V_23 ) ;
if ( ! V_24 )
V_24 = F_306 ( V_23 , V_205 , V_49 , V_412 ) ;
return V_24 ;
}
static bool F_312 ( struct V_11 * V_23 , T_2 V_206 )
{
T_2 V_616 ;
V_616 = F_186 ( V_23 , V_23 -> V_371 , V_23 -> V_411 ) ;
return F_186 ( V_23 , V_23 -> V_371 , V_206 ) <= V_616 ;
}
static int F_313 ( struct V_11 * V_23 , struct V_204 * V_205 ,
struct V_45 * V_49 , T_1 V_412 )
{
int V_24 = 0 ;
F_23 ( L_94 , V_23 ,
V_205 , V_49 , V_412 , V_23 -> V_285 ) ;
if ( F_312 ( V_23 , V_205 -> V_206 ) ) {
switch ( V_23 -> V_285 ) {
case V_380 :
V_24 = F_306 ( V_23 , V_205 , V_49 , V_412 ) ;
break;
case V_414 :
V_24 = F_308 ( V_23 , V_205 , V_49 ,
V_412 ) ;
break;
case V_294 :
V_24 = F_310 ( V_23 , V_205 , V_49 , V_412 ) ;
break;
case V_292 :
V_24 = F_311 ( V_23 , V_205 , V_49 , V_412 ) ;
break;
default:
break;
}
} else {
F_23 ( L_95 ,
V_205 -> V_206 , V_23 -> V_371 ,
V_23 -> V_411 ) ;
F_86 ( V_23 , V_320 ) ;
}
return V_24 ;
}
static int F_314 ( struct V_11 * V_23 , struct V_204 * V_205 ,
struct V_45 * V_49 )
{
int V_24 = 0 ;
F_23 ( L_96 , V_23 , V_205 , V_49 ,
V_23 -> V_285 ) ;
if ( F_305 ( V_23 , V_205 -> V_51 ) ==
V_605 ) {
F_213 ( V_23 , V_205 ) ;
F_23 ( L_97 , V_23 -> V_259 ,
F_172 ( V_23 , V_23 -> V_259 ) ) ;
V_23 -> V_259 = F_172 ( V_23 , V_23 -> V_259 ) ;
F_299 ( V_23 , V_49 , V_205 ) ;
} else {
if ( V_23 -> V_104 ) {
F_97 ( V_23 -> V_104 ) ;
V_23 -> V_104 = NULL ;
}
V_23 -> V_105 = NULL ;
V_23 -> V_106 = 0 ;
if ( V_49 ) {
F_23 ( L_93 , V_49 ) ;
F_97 ( V_49 ) ;
}
}
V_23 -> V_257 = V_205 -> V_51 ;
V_23 -> V_280 = F_172 ( V_23 , V_205 -> V_51 ) ;
return V_24 ;
}
static int F_315 ( struct V_11 * V_23 , struct V_45 * V_49 )
{
struct V_204 * V_205 = & F_35 ( V_49 ) -> V_50 ;
T_2 V_187 ;
T_1 V_412 ;
F_100 ( V_23 , V_49 ) ;
V_187 = V_49 -> V_187 ;
if ( F_294 ( V_23 , V_49 ) )
goto V_590;
if ( ! V_205 -> V_213 && V_205 -> V_220 == V_401 )
V_187 -= V_395 ;
if ( V_23 -> V_87 == V_88 )
V_187 -= V_249 ;
if ( V_187 > V_23 -> V_110 ) {
F_86 ( V_23 , V_320 ) ;
goto V_590;
}
if ( ! V_205 -> V_213 ) {
int V_24 ;
F_23 ( L_98 ,
V_205 -> V_220 , V_205 -> V_206 , V_205 -> V_209 ,
V_205 -> V_51 ) ;
if ( V_205 -> V_209 && V_23 -> V_283 != V_417 )
goto V_590;
if ( V_23 -> V_141 != V_148 ) {
V_412 = V_609 ;
V_24 = F_313 ( V_23 , V_205 , V_49 , V_412 ) ;
} else {
V_24 = F_314 ( V_23 , V_205 , V_49 ) ;
}
if ( V_24 )
F_86 ( V_23 , V_320 ) ;
} else {
const T_1 V_617 [ 4 ] = {
V_610 , V_612 ,
V_611 , V_613
} ;
if ( V_23 -> V_141 == V_148 )
goto V_590;
F_23 ( L_99 ,
V_205 -> V_206 , V_205 -> V_209 , V_205 -> V_214 ,
V_205 -> V_217 ) ;
if ( V_187 != 0 ) {
F_286 ( L_100 , V_187 ) ;
F_86 ( V_23 , V_320 ) ;
goto V_590;
}
if ( V_205 -> V_209 && ( V_205 -> V_214 ||
V_23 -> V_283 != V_417 ) )
goto V_590;
V_412 = V_617 [ V_205 -> V_217 ] ;
if ( F_313 ( V_23 , V_205 , V_49 , V_412 ) )
F_86 ( V_23 , V_320 ) ;
}
return 0 ;
V_590:
F_97 ( V_49 ) ;
return 0 ;
}
static void F_316 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct F_289 V_585 ;
T_2 V_618 ;
if ( V_23 -> V_108 >= ( V_109 + 1 ) / 2 )
return;
V_618 = V_109 - V_23 -> V_108 ;
F_23 ( L_101 , V_23 , V_618 ) ;
V_23 -> V_108 += V_618 ;
V_585 . V_14 = F_18 ( V_23 -> V_17 ) ;
V_585 . V_159 = F_18 ( V_618 ) ;
V_23 -> V_19 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_589 , sizeof( V_585 ) , & V_585 ) ;
}
static int F_317 ( struct V_11 * V_23 , struct V_45 * V_49 )
{
int V_24 ;
if ( ! V_23 -> V_108 ) {
F_286 ( L_102 ) ;
F_86 ( V_23 , V_320 ) ;
return - V_619 ;
}
if ( V_23 -> V_111 < V_49 -> V_187 ) {
F_286 ( L_103 ) ;
return - V_619 ;
}
V_23 -> V_108 -- ;
F_23 ( L_104 , V_23 -> V_108 + 1 , V_23 -> V_108 ) ;
F_316 ( V_23 ) ;
V_24 = 0 ;
if ( ! V_23 -> V_104 ) {
T_2 V_106 ;
V_106 = F_103 ( V_49 -> V_188 ) ;
F_102 ( V_49 , V_395 ) ;
F_23 ( L_105 ,
V_106 , V_49 -> V_187 , V_23 -> V_111 ) ;
if ( V_106 > V_23 -> V_111 ) {
F_286 ( L_106 ) ;
V_24 = - V_404 ;
goto V_620;
}
if ( V_49 -> V_187 > V_106 ) {
F_286 ( L_107 ) ;
V_24 = - V_29 ;
goto V_620;
}
if ( V_49 -> V_187 == V_106 )
return V_23 -> V_39 -> V_422 ( V_23 , V_49 ) ;
V_23 -> V_104 = V_49 ;
V_23 -> V_106 = V_106 ;
V_23 -> V_105 = V_49 ;
return 0 ;
}
F_23 ( L_108 ,
V_23 -> V_104 -> V_187 , V_49 -> V_187 , V_23 -> V_106 ) ;
if ( V_23 -> V_104 -> V_187 + V_49 -> V_187 > V_23 -> V_106 ) {
F_286 ( L_107 ) ;
V_24 = - V_29 ;
goto V_620;
}
F_297 ( V_23 -> V_104 , V_49 , & V_23 -> V_105 ) ;
V_49 = NULL ;
if ( V_23 -> V_104 -> V_187 == V_23 -> V_106 ) {
V_24 = V_23 -> V_39 -> V_422 ( V_23 , V_23 -> V_104 ) ;
if ( ! V_24 ) {
V_23 -> V_104 = NULL ;
V_23 -> V_105 = NULL ;
V_23 -> V_106 = 0 ;
}
}
V_620:
if ( V_24 ) {
F_97 ( V_49 ) ;
F_97 ( V_23 -> V_104 ) ;
V_23 -> V_104 = NULL ;
V_23 -> V_105 = NULL ;
V_23 -> V_106 = 0 ;
}
return 0 ;
}
static void F_318 ( struct V_12 * V_13 , T_2 V_14 ,
struct V_45 * V_49 )
{
struct V_11 * V_23 ;
V_23 = F_7 ( V_13 , V_14 ) ;
if ( ! V_23 ) {
if ( V_14 == V_316 ) {
V_23 = F_319 ( V_13 , V_49 ) ;
if ( ! V_23 ) {
F_97 ( V_49 ) ;
return;
}
F_9 ( V_23 ) ;
} else {
F_23 ( L_109 , V_14 ) ;
F_97 ( V_49 ) ;
return;
}
}
F_23 ( L_110 , V_23 , V_49 -> V_187 ) ;
if ( V_23 -> V_32 == V_33 )
F_130 ( V_23 ) ;
if ( V_23 -> V_38 != V_68 )
goto V_590;
switch ( V_23 -> V_141 ) {
case V_143 :
if ( F_317 ( V_23 , V_49 ) < 0 )
goto V_590;
goto V_27;
case V_142 :
if ( V_23 -> V_111 < V_49 -> V_187 ) {
F_286 ( L_111 ) ;
goto V_590;
}
if ( ! V_23 -> V_39 -> V_422 ( V_23 , V_49 ) )
goto V_27;
break;
case V_144 :
case V_148 :
F_315 ( V_23 , V_49 ) ;
goto V_27;
default:
F_23 ( L_112 , V_23 , V_23 -> V_141 ) ;
break;
}
V_590:
F_97 ( V_49 ) ;
V_27:
F_48 ( V_23 ) ;
}
static void F_320 ( struct V_12 * V_13 , T_3 V_20 ,
struct V_45 * V_49 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_11 * V_23 ;
if ( V_8 -> type != V_117 )
goto V_621;
V_23 = F_165 ( 0 , V_20 , & V_8 -> V_21 , & V_8 -> V_150 ,
V_117 ) ;
if ( ! V_23 )
goto V_621;
F_23 ( L_110 , V_23 , V_49 -> V_187 ) ;
if ( V_23 -> V_38 != V_622 && V_23 -> V_38 != V_68 )
goto V_590;
if ( V_23 -> V_111 < V_49 -> V_187 )
goto V_590;
F_81 ( & F_35 ( V_49 ) -> V_50 . V_623 , & V_8 -> V_150 ) ;
F_35 ( V_49 ) -> V_50 . V_20 = V_20 ;
if ( ! V_23 -> V_39 -> V_422 ( V_23 , V_49 ) ) {
F_49 ( V_23 ) ;
return;
}
V_590:
F_49 ( V_23 ) ;
V_621:
F_97 ( V_49 ) ;
}
static void F_321 ( struct V_12 * V_13 , struct V_45 * V_49 )
{
struct V_246 * V_247 = ( void * ) V_49 -> V_188 ;
struct V_7 * V_8 = V_13 -> V_8 ;
T_2 V_14 , V_187 ;
T_3 V_20 ;
if ( V_8 -> V_38 != V_68 ) {
F_23 ( L_113 ) ;
F_307 ( & V_13 -> V_359 , V_49 ) ;
return;
}
F_102 ( V_49 , V_243 ) ;
V_14 = F_69 ( V_247 -> V_14 ) ;
V_187 = F_69 ( V_247 -> V_187 ) ;
if ( V_187 != V_49 -> V_187 ) {
F_97 ( V_49 ) ;
return;
}
if ( V_8 -> type == V_2 &&
F_322 ( & V_8 -> V_189 -> V_624 , & V_8 -> V_150 ,
F_3 ( V_8 ) ) ) {
F_97 ( V_49 ) ;
return;
}
F_23 ( L_114 , V_187 , V_14 ) ;
switch ( V_14 ) {
case V_120 :
F_293 ( V_13 , V_49 ) ;
break;
case V_119 :
V_20 = F_323 ( ( T_3 * ) V_49 -> V_188 ) ;
F_102 ( V_49 , V_393 ) ;
F_320 ( V_13 , V_20 , V_49 ) ;
break;
case V_427 :
F_292 ( V_13 , V_49 ) ;
break;
default:
F_318 ( V_13 , V_14 , V_49 ) ;
break;
}
}
static void F_324 ( struct V_64 * V_65 )
{
struct V_12 * V_13 = F_46 ( V_65 , struct V_12 ,
V_347 ) ;
struct V_45 * V_49 ;
F_23 ( L_115 ) ;
while ( ( V_49 = F_171 ( & V_13 -> V_359 ) ) )
F_321 ( V_13 , V_49 ) ;
}
static struct V_12 * F_325 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_356 ;
struct V_140 * V_196 ;
if ( V_13 )
return V_13 ;
V_196 = F_326 ( V_8 ) ;
if ( ! V_196 )
return NULL ;
V_13 = F_51 ( sizeof( * V_13 ) , V_58 ) ;
if ( ! V_13 ) {
F_159 ( V_196 ) ;
return NULL ;
}
F_56 ( & V_13 -> V_361 ) ;
V_8 -> V_356 = V_13 ;
V_13 -> V_8 = F_327 ( V_8 ) ;
V_13 -> V_196 = V_196 ;
F_23 ( L_116 , V_8 , V_13 , V_196 ) ;
switch ( V_8 -> type ) {
case V_2 :
if ( V_8 -> V_189 -> V_625 ) {
V_13 -> V_158 = V_8 -> V_189 -> V_625 ;
break;
}
default:
V_13 -> V_158 = V_8 -> V_189 -> V_615 ;
break;
}
V_13 -> V_309 = 0 ;
V_13 -> V_263 = V_626 | V_627 ;
if ( V_8 -> type == V_117 &&
F_241 ( V_8 -> V_189 , V_628 ) )
V_13 -> V_263 |= V_264 ;
if ( F_241 ( V_8 -> V_189 , V_629 ) &&
( F_328 ( V_8 -> V_189 ) ||
F_241 ( V_8 -> V_189 , V_630 ) ) )
V_13 -> V_263 |= V_631 ;
F_52 ( & V_13 -> V_184 ) ;
F_52 ( & V_13 -> V_18 ) ;
F_329 ( & V_13 -> V_134 ) ;
F_329 ( & V_13 -> V_355 ) ;
F_55 ( & V_13 -> V_305 , F_147 ) ;
F_67 ( & V_13 -> V_359 ) ;
F_330 ( & V_13 -> V_347 , F_324 ) ;
F_330 ( & V_13 -> V_149 , F_80 ) ;
V_13 -> V_114 = V_115 ;
return V_13 ;
}
static bool F_331 ( T_2 V_20 , T_1 V_10 ) {
if ( ! V_20 )
return false ;
if ( F_332 ( V_10 ) )
return ( V_20 <= 0x00ff ) ;
return ( ( V_20 & 0x0101 ) == 0x0001 ) ;
}
int F_333 ( struct V_11 * V_23 , T_3 V_20 , T_2 V_14 ,
T_4 * V_150 , T_1 V_10 )
{
struct V_12 * V_13 ;
struct V_7 * V_8 ;
struct V_261 * V_189 ;
int V_24 ;
F_23 ( L_117 , & V_23 -> V_21 , V_150 ,
V_10 , F_69 ( V_20 ) ) ;
V_189 = F_334 ( V_150 , & V_23 -> V_21 ) ;
if ( ! V_189 )
return - V_632 ;
F_149 ( V_189 ) ;
if ( ! F_331 ( F_69 ( V_20 ) , V_10 ) && ! V_14 &&
V_23 -> V_32 != V_169 ) {
V_24 = - V_29 ;
goto V_27;
}
if ( V_23 -> V_32 == V_116 && ! V_20 ) {
V_24 = - V_29 ;
goto V_27;
}
if ( V_23 -> V_32 == V_33 && ! V_14 ) {
V_24 = - V_29 ;
goto V_27;
}
switch ( V_23 -> V_141 ) {
case V_142 :
break;
case V_143 :
F_65 ( V_23 ) ;
break;
case V_144 :
case V_148 :
if ( ! V_312 )
break;
default:
V_24 = - V_633 ;
goto V_27;
}
switch ( V_23 -> V_38 ) {
case V_71 :
case V_168 :
case V_69 :
V_24 = 0 ;
goto V_27;
case V_68 :
V_24 = - V_634 ;
goto V_27;
case V_82 :
case V_622 :
break;
default:
V_24 = - V_407 ;
goto V_27;
}
F_81 ( & V_23 -> V_150 , V_150 ) ;
V_23 -> V_10 = V_10 ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_14 ;
if ( F_332 ( V_10 ) ) {
T_1 V_333 ;
if ( V_10 == V_4 )
V_10 = V_3 ;
else
V_10 = V_635 ;
if ( F_241 ( V_189 , V_636 ) )
V_333 = V_334 ;
else
V_333 = V_574 ;
V_8 = F_335 ( V_189 , V_150 , V_10 , V_23 -> V_72 ,
V_637 , V_333 ) ;
} else {
T_1 V_182 = F_87 ( V_23 ) ;
V_8 = F_336 ( V_189 , V_150 , V_23 -> V_72 , V_182 ) ;
}
if ( F_118 ( V_8 ) ) {
V_24 = F_191 ( V_8 ) ;
goto V_27;
}
V_13 = F_325 ( V_8 ) ;
if ( ! V_13 ) {
F_75 ( V_8 ) ;
V_24 = - V_59 ;
goto V_27;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_23 ) ;
if ( V_14 && F_4 ( V_13 , V_14 ) ) {
F_75 ( V_8 ) ;
V_24 = - V_638 ;
goto V_639;
}
F_81 ( & V_23 -> V_21 , & V_8 -> V_21 ) ;
V_23 -> V_9 = F_2 ( V_8 ) ;
F_68 ( V_13 , V_23 ) ;
F_75 ( V_8 ) ;
F_22 ( V_23 , V_71 ) ;
F_85 ( V_23 , V_23 -> V_39 -> V_167 ( V_23 ) ) ;
F_17 ( & V_25 ) ;
V_23 -> V_22 = 0 ;
F_19 ( & V_25 ) ;
if ( V_8 -> V_38 == V_68 ) {
if ( V_23 -> V_32 != V_116 ) {
F_74 ( V_23 ) ;
if ( F_88 ( V_23 , true ) )
F_22 ( V_23 , V_68 ) ;
} else
F_138 ( V_23 ) ;
}
V_24 = 0 ;
V_639:
F_48 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
V_27:
F_151 ( V_189 ) ;
F_257 ( V_189 ) ;
return V_24 ;
}
int F_337 ( struct V_261 * V_189 , T_4 * V_623 )
{
int V_640 = 0 , V_641 = 0 , V_642 = 0 ;
struct V_11 * V_15 ;
F_23 ( L_118 , V_189 -> V_330 , V_623 ) ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
if ( V_15 -> V_38 != V_166 )
continue;
if ( ! F_15 ( & V_15 -> V_21 , & V_189 -> V_623 ) ) {
V_641 |= V_643 ;
if ( F_70 ( V_644 , & V_15 -> V_103 ) )
V_641 |= V_645 ;
V_640 ++ ;
} else if ( ! F_15 ( & V_15 -> V_21 , V_367 ) ) {
V_642 |= V_643 ;
if ( F_70 ( V_644 , & V_15 -> V_103 ) )
V_642 |= V_645 ;
}
}
F_123 ( & V_25 ) ;
return V_640 ? V_641 : V_642 ;
}
static struct V_11 * F_338 ( struct V_11 * V_15 ,
struct V_7 * V_8 )
{
T_1 V_9 = F_2 ( V_8 ) ;
F_122 ( & V_25 ) ;
if ( V_15 )
V_15 = F_339 ( V_15 , V_80 ) ;
else
V_15 = F_340 ( V_81 . V_392 , F_341 ( * V_15 ) , V_80 ) ;
F_342 (c, &chan_list, global_l) {
if ( V_15 -> V_32 != V_33 )
continue;
if ( V_15 -> V_38 != V_166 )
continue;
if ( F_15 ( & V_15 -> V_21 , & V_8 -> V_21 ) && F_15 ( & V_15 -> V_21 , V_367 ) )
continue;
if ( V_9 != V_15 -> V_9 )
continue;
F_60 ( V_15 ) ;
F_123 ( & V_25 ) ;
return V_15 ;
}
F_123 ( & V_25 ) ;
return NULL ;
}
static void F_343 ( struct V_7 * V_8 , T_1 V_163 )
{
struct V_261 * V_189 = V_8 -> V_189 ;
struct V_12 * V_13 ;
struct V_11 * V_502 ;
T_1 V_10 ;
if ( V_8 -> type != V_117 && V_8 -> type != V_2 )
return;
F_23 ( L_119 , V_8 , & V_8 -> V_150 , V_163 ) ;
if ( V_163 ) {
F_156 ( V_8 , F_344 ( V_163 ) ) ;
return;
}
V_13 = F_325 ( V_8 ) ;
if ( ! V_13 )
return;
V_10 = F_3 ( V_8 ) ;
if ( F_322 ( & V_189 -> V_624 , & V_8 -> V_150 , V_10 ) )
return;
V_502 = F_338 ( NULL , V_8 ) ;
while ( V_502 ) {
struct V_11 * V_23 , * V_392 ;
if ( F_4 ( V_13 , V_502 -> V_17 ) )
goto V_392;
F_9 ( V_502 ) ;
V_23 = V_502 -> V_39 -> V_507 ( V_502 ) ;
if ( V_23 ) {
F_81 ( & V_23 -> V_21 , & V_8 -> V_21 ) ;
F_81 ( & V_23 -> V_150 , & V_8 -> V_150 ) ;
V_23 -> V_9 = F_2 ( V_8 ) ;
V_23 -> V_10 = V_10 ;
F_68 ( V_13 , V_23 ) ;
}
F_48 ( V_502 ) ;
V_392:
V_392 = F_338 ( V_502 , V_8 ) ;
F_49 ( V_502 ) ;
V_502 = V_392 ;
}
F_144 ( V_13 ) ;
}
int F_345 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_356 ;
F_23 ( L_120 , V_8 ) ;
if ( ! V_13 )
return V_115 ;
return V_13 -> V_114 ;
}
static void F_346 ( struct V_7 * V_8 , T_1 V_67 )
{
if ( V_8 -> type != V_117 && V_8 -> type != V_2 )
return;
F_23 ( L_121 , V_8 , V_67 ) ;
F_156 ( V_8 , F_344 ( V_67 ) ) ;
}
static inline void F_347 ( struct V_11 * V_23 , T_1 V_646 )
{
if ( V_23 -> V_32 != V_116 )
return;
if ( V_646 == 0x00 ) {
if ( V_23 -> V_72 == V_173 ) {
F_85 ( V_23 , V_647 ) ;
} else if ( V_23 -> V_72 == V_170 ||
V_23 -> V_72 == V_171 )
F_47 ( V_23 , V_70 ) ;
} else {
if ( V_23 -> V_72 == V_173 )
F_74 ( V_23 ) ;
}
}
static void F_348 ( struct V_7 * V_8 , T_1 V_163 , T_1 V_646 )
{
struct V_12 * V_13 = V_8 -> V_356 ;
struct V_11 * V_23 ;
if ( ! V_13 )
return;
F_23 ( L_122 , V_13 , V_163 , V_646 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
F_9 ( V_23 ) ;
F_23 ( L_123 , V_23 , V_23 -> V_17 ,
F_24 ( V_23 -> V_38 ) ) ;
if ( V_23 -> V_17 == V_316 ) {
F_48 ( V_23 ) ;
continue;
}
if ( ! V_163 && V_646 )
V_23 -> V_72 = V_8 -> V_72 ;
if ( ! F_120 ( V_23 ) ) {
F_48 ( V_23 ) ;
continue;
}
if ( ! V_163 && ( V_23 -> V_38 == V_68 ||
V_23 -> V_38 == V_69 ) ) {
V_23 -> V_39 -> V_588 ( V_23 ) ;
F_347 ( V_23 , V_646 ) ;
F_48 ( V_23 ) ;
continue;
}
if ( V_23 -> V_38 == V_71 ) {
if ( ! V_163 )
F_134 ( V_23 ) ;
else
F_85 ( V_23 , V_648 ) ;
} else if ( V_23 -> V_38 == V_168 &&
V_23 -> V_141 != V_143 ) {
struct V_161 V_152 ;
T_5 V_649 , V_650 ;
if ( ! V_163 ) {
if ( F_70 ( V_154 , & V_23 -> V_103 ) ) {
V_649 = V_322 ;
V_650 = V_323 ;
V_23 -> V_39 -> V_324 ( V_23 ) ;
} else {
F_22 ( V_23 , V_69 ) ;
V_649 = V_325 ;
V_650 = V_164 ;
}
} else {
F_22 ( V_23 , V_157 ) ;
F_85 ( V_23 , V_648 ) ;
V_649 = V_162 ;
V_650 = V_164 ;
}
V_152 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_152 . V_153 = F_18 ( V_649 ) ;
V_152 . V_163 = F_18 ( V_650 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_165 ,
sizeof( V_152 ) , & V_152 ) ;
if ( ! F_70 ( V_327 , & V_23 -> V_85 ) &&
V_649 == V_325 ) {
char V_321 [ 128 ] ;
F_57 ( V_327 , & V_23 -> V_85 ) ;
F_83 ( V_13 , F_91 ( V_13 ) ,
V_328 ,
F_142 ( V_23 , V_321 ) ,
V_321 ) ;
V_23 -> V_329 ++ ;
}
}
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
void F_349 ( struct V_7 * V_8 , struct V_45 * V_49 , T_2 V_103 )
{
struct V_12 * V_13 = V_8 -> V_356 ;
struct V_246 * V_651 ;
int V_187 ;
if ( ! V_13 && V_8 -> V_189 -> V_534 != V_652 )
goto V_590;
if ( ! V_13 )
V_13 = F_325 ( V_8 ) ;
if ( ! V_13 )
goto V_590;
F_23 ( L_124 , V_13 , V_49 -> V_187 , V_103 ) ;
switch ( V_103 ) {
case V_191 :
case V_190 :
case V_201 :
if ( V_13 -> V_653 ) {
F_286 ( L_125 , V_49 -> V_187 ) ;
F_97 ( V_13 -> V_358 ) ;
V_13 -> V_358 = NULL ;
V_13 -> V_653 = 0 ;
F_146 ( V_13 , V_654 ) ;
}
if ( V_49 -> V_187 < V_243 ) {
F_286 ( L_126 , V_49 -> V_187 ) ;
F_146 ( V_13 , V_654 ) ;
goto V_590;
}
V_651 = (struct V_246 * ) V_49 -> V_188 ;
V_187 = F_69 ( V_651 -> V_187 ) + V_243 ;
if ( V_187 == V_49 -> V_187 ) {
F_321 ( V_13 , V_49 ) ;
return;
}
F_23 ( L_127 , V_187 , V_49 -> V_187 ) ;
if ( V_49 -> V_187 > V_187 ) {
F_286 ( L_128 ,
V_49 -> V_187 , V_187 ) ;
F_146 ( V_13 , V_654 ) ;
goto V_590;
}
V_13 -> V_358 = F_111 ( V_187 , V_58 ) ;
if ( ! V_13 -> V_358 )
goto V_590;
F_350 ( V_49 , F_113 ( V_13 -> V_358 , V_49 -> V_187 ) ,
V_49 -> V_187 ) ;
V_13 -> V_653 = V_187 - V_49 -> V_187 ;
break;
case V_655 :
F_23 ( L_129 , V_49 -> V_187 , V_13 -> V_653 ) ;
if ( ! V_13 -> V_653 ) {
F_286 ( L_130 , V_49 -> V_187 ) ;
F_146 ( V_13 , V_654 ) ;
goto V_590;
}
if ( V_49 -> V_187 > V_13 -> V_653 ) {
F_286 ( L_131 ,
V_49 -> V_187 , V_13 -> V_653 ) ;
F_97 ( V_13 -> V_358 ) ;
V_13 -> V_358 = NULL ;
V_13 -> V_653 = 0 ;
F_146 ( V_13 , V_654 ) ;
goto V_590;
}
F_350 ( V_49 , F_113 ( V_13 -> V_358 , V_49 -> V_187 ) ,
V_49 -> V_187 ) ;
V_13 -> V_653 -= V_49 -> V_187 ;
if ( ! V_13 -> V_653 ) {
struct V_45 * V_358 = V_13 -> V_358 ;
V_13 -> V_358 = NULL ;
F_321 ( V_13 , V_358 ) ;
}
break;
}
V_590:
F_97 ( V_49 ) ;
}
static int F_351 ( struct V_656 * V_657 , void * V_28 )
{
struct V_11 * V_15 ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
F_352 ( V_657 , L_132 ,
& V_15 -> V_21 , V_15 -> V_9 , & V_15 -> V_150 , V_15 -> V_10 ,
V_15 -> V_38 , F_69 ( V_15 -> V_20 ) ,
V_15 -> V_17 , V_15 -> V_16 , V_15 -> V_111 , V_15 -> V_30 ,
V_15 -> V_72 , V_15 -> V_141 ) ;
}
F_123 ( & V_25 ) ;
return 0 ;
}
static int F_353 ( struct V_658 * V_658 , struct V_659 * V_659 )
{
return F_354 ( V_659 , F_351 , V_658 -> V_660 ) ;
}
int T_11 F_355 ( void )
{
int V_24 ;
V_24 = F_356 () ;
if ( V_24 < 0 )
return V_24 ;
F_357 ( & V_661 ) ;
if ( F_358 ( V_662 ) )
return 0 ;
V_663 = F_359 ( L_133 , 0444 , V_662 ,
NULL , & V_664 ) ;
F_360 ( L_134 , 0644 , V_662 ,
& V_109 ) ;
F_360 ( L_135 , 0644 , V_662 ,
& V_112 ) ;
return 0 ;
}
void F_361 ( void )
{
F_362 ( V_663 ) ;
F_363 ( & V_661 ) ;
F_364 () ;
}
