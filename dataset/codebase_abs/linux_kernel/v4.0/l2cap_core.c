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
static void F_98 ( T_2 V_203 , struct V_204 * V_50 )
{
V_50 -> V_205 = ( V_203 & V_206 ) >> V_207 ;
V_50 -> V_208 = ( V_203 & V_209 ) >> V_210 ;
if ( V_203 & V_211 ) {
V_50 -> V_212 = 1 ;
V_50 -> V_213 = ( V_203 & V_214 ) >> V_215 ;
V_50 -> V_216 = ( V_203 & V_217 ) >> V_218 ;
V_50 -> V_219 = 0 ;
V_50 -> V_51 = 0 ;
} else {
V_50 -> V_212 = 0 ;
V_50 -> V_219 = ( V_203 & V_220 ) >> V_221 ;
V_50 -> V_51 = ( V_203 & V_222 ) >> V_223 ;
V_50 -> V_213 = 0 ;
V_50 -> V_216 = 0 ;
}
}
static void F_99 ( T_8 V_224 , struct V_204 * V_50 )
{
V_50 -> V_205 = ( V_224 & V_225 ) >> V_226 ;
V_50 -> V_208 = ( V_224 & V_227 ) >> V_228 ;
if ( V_224 & V_229 ) {
V_50 -> V_212 = 1 ;
V_50 -> V_213 = ( V_224 & V_230 ) >> V_231 ;
V_50 -> V_216 = ( V_224 & V_232 ) >> V_233 ;
V_50 -> V_219 = 0 ;
V_50 -> V_51 = 0 ;
} else {
V_50 -> V_212 = 0 ;
V_50 -> V_219 = ( V_224 & V_234 ) >> V_235 ;
V_50 -> V_51 = ( V_224 & V_236 ) >> V_237 ;
V_50 -> V_213 = 0 ;
V_50 -> V_216 = 0 ;
}
}
static inline void F_100 ( struct V_11 * V_23 ,
struct V_45 * V_49 )
{
if ( F_70 ( V_238 , & V_23 -> V_103 ) ) {
F_99 ( F_101 ( V_49 -> V_188 ) ,
& F_35 ( V_49 ) -> V_50 ) ;
F_102 ( V_49 , V_239 ) ;
} else {
F_98 ( F_103 ( V_49 -> V_188 ) ,
& F_35 ( V_49 ) -> V_50 ) ;
F_102 ( V_49 , V_240 ) ;
}
}
static T_8 F_104 ( struct V_204 * V_50 )
{
T_8 V_241 ;
V_241 = V_50 -> V_205 << V_226 ;
V_241 |= V_50 -> V_208 << V_228 ;
if ( V_50 -> V_212 ) {
V_241 |= V_50 -> V_213 << V_231 ;
V_241 |= V_50 -> V_216 << V_233 ;
V_241 |= V_229 ;
} else {
V_241 |= V_50 -> V_219 << V_235 ;
V_241 |= V_50 -> V_51 << V_237 ;
}
return V_241 ;
}
static T_2 F_105 ( struct V_204 * V_50 )
{
T_2 V_241 ;
V_241 = V_50 -> V_205 << V_207 ;
V_241 |= V_50 -> V_208 << V_210 ;
if ( V_50 -> V_212 ) {
V_241 |= V_50 -> V_213 << V_215 ;
V_241 |= V_50 -> V_216 << V_218 ;
V_241 |= V_211 ;
} else {
V_241 |= V_50 -> V_219 << V_221 ;
V_241 |= V_50 -> V_51 << V_223 ;
}
return V_241 ;
}
static inline void F_106 ( struct V_11 * V_23 ,
struct V_204 * V_50 ,
struct V_45 * V_49 )
{
if ( F_70 ( V_238 , & V_23 -> V_103 ) ) {
F_107 ( F_104 ( V_50 ) ,
V_49 -> V_188 + V_242 ) ;
} else {
F_108 ( F_105 ( V_50 ) ,
V_49 -> V_188 + V_242 ) ;
}
}
static inline unsigned int F_109 ( struct V_11 * V_23 )
{
if ( F_70 ( V_238 , & V_23 -> V_103 ) )
return V_243 ;
else
return V_244 ;
}
static struct V_45 * F_110 ( struct V_11 * V_23 ,
T_8 V_50 )
{
struct V_45 * V_49 ;
struct V_245 * V_246 ;
int V_247 = F_109 ( V_23 ) ;
if ( V_23 -> V_87 == V_88 )
V_247 += V_248 ;
V_49 = F_111 ( V_247 , V_58 ) ;
if ( ! V_49 )
return F_112 ( - V_59 ) ;
V_246 = (struct V_245 * ) F_113 ( V_49 , V_242 ) ;
V_246 -> V_187 = F_18 ( V_247 - V_242 ) ;
V_246 -> V_14 = F_18 ( V_23 -> V_16 ) ;
if ( F_70 ( V_238 , & V_23 -> V_103 ) )
F_107 ( V_50 , F_113 ( V_49 , V_239 ) ) ;
else
F_108 ( V_50 , F_113 ( V_49 , V_240 ) ) ;
if ( V_23 -> V_87 == V_88 ) {
T_2 V_87 = F_114 ( 0 , ( T_1 * ) V_49 -> V_188 , V_49 -> V_187 ) ;
F_108 ( V_87 , F_113 ( V_49 , V_248 ) ) ;
}
V_49 -> V_194 = V_195 ;
return V_49 ;
}
static void F_115 ( struct V_11 * V_23 ,
struct V_204 * V_50 )
{
struct V_45 * V_49 ;
T_8 V_249 ;
F_23 ( L_10 , V_23 , V_50 ) ;
if ( ! V_50 -> V_212 )
return;
if ( F_95 ( V_23 ) )
return;
if ( F_116 ( V_250 , & V_23 -> V_251 ) &&
! V_50 -> V_213 )
V_50 -> V_208 = 1 ;
if ( V_50 -> V_216 == V_252 )
F_117 ( V_253 , & V_23 -> V_251 ) ;
else if ( V_50 -> V_216 == V_254 )
F_57 ( V_253 , & V_23 -> V_251 ) ;
if ( V_50 -> V_216 != V_255 ) {
V_23 -> V_256 = V_50 -> V_205 ;
F_79 ( V_23 ) ;
}
F_23 ( L_11 , V_50 -> V_205 ,
V_50 -> V_208 , V_50 -> V_213 , V_50 -> V_216 ) ;
if ( F_70 ( V_238 , & V_23 -> V_103 ) )
V_249 = F_104 ( V_50 ) ;
else
V_249 = F_105 ( V_50 ) ;
V_49 = F_110 ( V_23 , V_249 ) ;
if ( ! F_118 ( V_49 ) )
F_96 ( V_23 , V_49 ) ;
}
static void F_119 ( struct V_11 * V_23 , bool V_213 )
{
struct V_204 V_50 ;
F_23 ( L_12 , V_23 , V_213 ) ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_212 = 1 ;
V_50 . V_213 = V_213 ;
if ( F_70 ( V_257 , & V_23 -> V_251 ) )
V_50 . V_216 = V_254 ;
else
V_50 . V_216 = V_252 ;
V_50 . V_205 = V_23 -> V_258 ;
F_115 ( V_23 , & V_50 ) ;
}
static inline int F_120 ( struct V_11 * V_23 )
{
if ( V_23 -> V_32 != V_116 )
return true ;
return ! F_70 ( V_259 , & V_23 -> V_85 ) ;
}
static bool F_121 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_260 * V_189 ;
bool V_261 = false ;
if ( ! ( V_13 -> V_262 & V_263 ) )
return false ;
if ( ! ( V_13 -> V_264 & V_263 ) )
return false ;
F_122 ( & V_265 ) ;
F_5 (hdev, &hci_dev_list, list) {
if ( V_189 -> V_266 != V_267 &&
F_70 ( V_268 , & V_189 -> V_103 ) ) {
V_261 = true ;
break;
}
}
F_123 ( & V_265 ) ;
if ( V_23 -> V_269 == V_270 )
return V_261 ;
return false ;
}
static bool F_124 ( struct V_11 * V_23 )
{
return true ;
}
void F_125 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_271 V_272 ;
V_272 . V_17 = F_18 ( V_23 -> V_17 ) ;
V_272 . V_20 = V_23 -> V_20 ;
V_23 -> V_19 = F_91 ( V_13 ) ;
F_57 ( V_259 , & V_23 -> V_85 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_273 , sizeof( V_272 ) , & V_272 ) ;
}
static void F_126 ( struct V_11 * V_23 , T_1 V_274 )
{
struct V_275 V_272 ;
V_272 . V_17 = F_18 ( V_23 -> V_17 ) ;
V_272 . V_20 = V_23 -> V_20 ;
V_272 . V_274 = V_274 ;
V_23 -> V_19 = F_91 ( V_23 -> V_13 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_276 ,
sizeof( V_272 ) , & V_272 ) ;
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
V_23 -> V_277 = 0 ;
F_34 (&chan->tx_q, skb) {
if ( F_35 ( V_49 ) -> V_50 . V_278 )
F_35 ( V_49 ) -> V_50 . V_278 = 1 ;
else
break;
}
V_23 -> V_279 = V_23 -> V_258 ;
F_117 ( V_280 , & V_23 -> V_251 ) ;
F_117 ( V_281 , & V_23 -> V_251 ) ;
F_43 ( & V_23 -> V_147 ) ;
F_43 ( & V_23 -> V_146 ) ;
F_77 ( & V_23 -> V_145 ) ;
V_23 -> V_282 = V_283 ;
V_23 -> V_284 = V_285 ;
F_57 ( V_286 , & V_23 -> V_251 ) ;
}
static void F_128 ( struct V_11 * V_23 )
{
T_1 V_287 = V_23 -> V_287 ;
F_23 ( L_3 , V_23 ) ;
V_23 -> V_197 = V_198 ;
V_23 -> V_287 = V_288 ;
if ( V_23 -> V_141 != V_144 )
return;
switch ( V_287 ) {
case V_289 :
F_129 ( V_23 , NULL , NULL , V_290 ) ;
V_23 -> V_284 = V_291 ;
break;
case V_292 :
V_23 -> V_284 = V_293 ;
break;
}
}
static void F_130 ( struct V_11 * V_23 )
{
V_23 -> V_85 = 0 ;
F_74 ( V_23 ) ;
if ( V_23 -> V_141 == V_143 && ! V_23 -> V_107 )
V_23 -> V_39 -> V_294 ( V_23 ) ;
V_23 -> V_38 = V_68 ;
V_23 -> V_39 -> V_295 ( V_23 ) ;
}
static void F_131 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_296 V_272 ;
if ( F_132 ( V_297 , & V_23 -> V_103 ) )
return;
V_272 . V_20 = V_23 -> V_20 ;
V_272 . V_17 = F_18 ( V_23 -> V_17 ) ;
V_272 . V_158 = F_18 ( V_23 -> V_111 ) ;
V_272 . V_110 = F_18 ( V_23 -> V_110 ) ;
V_272 . V_159 = F_18 ( V_23 -> V_108 ) ;
V_23 -> V_19 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_298 ,
sizeof( V_272 ) , & V_272 ) ;
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
struct V_299 V_272 ;
if ( V_13 -> V_300 & V_301 )
return;
V_272 . type = F_18 ( V_302 ) ;
V_13 -> V_300 |= V_301 ;
V_13 -> V_303 = F_91 ( V_13 ) ;
F_137 ( & V_13 -> V_304 , V_305 ) ;
F_83 ( V_13 , V_13 -> V_303 , V_306 ,
sizeof( V_272 ) , & V_272 ) ;
}
static void F_138 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
if ( V_13 -> V_8 -> type == V_2 ) {
F_133 ( V_23 ) ;
return;
}
if ( ! ( V_13 -> V_300 & V_301 ) ) {
F_136 ( V_13 ) ;
return;
}
if ( ! ( V_13 -> V_300 & V_307 ) )
return;
if ( F_88 ( V_23 , true ) &&
F_120 ( V_23 ) )
F_134 ( V_23 ) ;
}
static inline int F_139 ( T_7 V_141 , T_9 V_308 )
{
T_8 V_309 = V_310 ;
if ( ! V_311 )
V_309 |= V_312 | V_313 ;
switch ( V_141 ) {
case V_144 :
return V_312 & V_308 & V_309 ;
case V_148 :
return V_313 & V_308 & V_309 ;
default:
return 0x00 ;
}
}
static void F_86 ( struct V_11 * V_23 , int V_24 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_314 V_272 ;
if ( ! V_13 )
return;
if ( V_23 -> V_141 == V_144 && V_23 -> V_38 == V_68 ) {
F_32 ( V_23 ) ;
F_78 ( V_23 ) ;
F_79 ( V_23 ) ;
}
if ( V_23 -> V_17 == V_315 ) {
F_22 ( V_23 , V_157 ) ;
return;
}
V_272 . V_16 = F_18 ( V_23 -> V_16 ) ;
V_272 . V_17 = F_18 ( V_23 -> V_17 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_316 ,
sizeof( V_272 ) , & V_272 ) ;
F_25 ( V_23 , V_157 , V_24 ) ;
}
static void F_140 ( struct V_12 * V_13 )
{
struct V_11 * V_23 , * V_317 ;
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
if ( ! F_139 ( V_23 -> V_141 , V_13 -> V_308 )
&& F_70 ( V_318 ,
& V_23 -> V_85 ) ) {
F_47 ( V_23 , V_319 ) ;
F_48 ( V_23 ) ;
continue;
}
F_134 ( V_23 ) ;
} else if ( V_23 -> V_38 == V_168 ) {
struct V_161 V_152 ;
char V_320 [ 128 ] ;
V_152 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
if ( F_88 ( V_23 , false ) ) {
if ( F_70 ( V_154 , & V_23 -> V_103 ) ) {
V_152 . V_153 = F_18 ( V_321 ) ;
V_152 . V_163 = F_18 ( V_322 ) ;
V_23 -> V_39 -> V_323 ( V_23 ) ;
} else {
F_22 ( V_23 , V_69 ) ;
V_152 . V_153 = F_18 ( V_324 ) ;
V_152 . V_163 = F_18 ( V_164 ) ;
}
} else {
V_152 . V_153 = F_18 ( V_321 ) ;
V_152 . V_163 = F_18 ( V_325 ) ;
}
F_83 ( V_13 , V_23 -> V_19 , V_165 ,
sizeof( V_152 ) , & V_152 ) ;
if ( F_70 ( V_326 , & V_23 -> V_85 ) ||
V_152 . V_153 != V_324 ) {
F_48 ( V_23 ) ;
continue;
}
F_57 ( V_326 , & V_23 -> V_85 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_327 ,
F_142 ( V_23 , V_320 ) , V_320 ) ;
V_23 -> V_328 ++ ;
}
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static void F_143 ( struct V_12 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_260 * V_189 = V_8 -> V_189 ;
F_23 ( L_15 , V_189 -> V_329 , V_13 ) ;
if ( V_8 -> V_330 )
F_89 ( V_8 , V_8 -> V_331 ) ;
if ( V_8 -> V_332 == V_333 &&
( V_8 -> V_334 < V_8 -> V_335 ||
V_8 -> V_334 > V_8 -> V_336 ) ) {
struct V_337 V_272 ;
V_272 . V_338 = F_18 ( V_8 -> V_335 ) ;
V_272 . V_339 = F_18 ( V_8 -> V_336 ) ;
V_272 . V_340 = F_18 ( V_8 -> V_341 ) ;
V_272 . V_342 = F_18 ( V_8 -> V_343 ) ;
F_83 ( V_13 , F_91 ( V_13 ) ,
V_344 , sizeof( V_272 ) , & V_272 ) ;
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
if ( V_23 -> V_17 == V_315 ) {
F_48 ( V_23 ) ;
continue;
}
if ( V_8 -> type == V_2 ) {
F_133 ( V_23 ) ;
} else if ( V_23 -> V_32 != V_116 ) {
if ( V_13 -> V_300 & V_307 )
F_130 ( V_23 ) ;
} else if ( V_23 -> V_38 == V_71 ) {
F_138 ( V_23 ) ;
}
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
if ( V_8 -> type == V_2 )
F_143 ( V_13 ) ;
F_145 ( V_8 -> V_189 -> V_345 , & V_13 -> V_346 ) ;
}
static void F_146 ( struct V_12 * V_13 , int V_24 )
{
struct V_11 * V_23 ;
F_23 ( L_14 , V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
if ( F_70 ( V_347 , & V_23 -> V_103 ) )
F_26 ( V_23 , V_24 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static void F_147 ( struct V_64 * V_65 )
{
struct V_12 * V_13 = F_46 ( V_65 , struct V_12 ,
V_304 . V_65 ) ;
V_13 -> V_300 |= V_307 ;
V_13 -> V_303 = 0 ;
F_140 ( V_13 ) ;
}
int F_148 ( struct V_12 * V_13 , struct V_348 * V_349 )
{
struct V_260 * V_189 = V_13 -> V_8 -> V_189 ;
int V_350 ;
F_149 ( V_189 ) ;
if ( V_349 -> V_57 . V_351 || V_349 -> V_57 . V_352 ) {
V_350 = - V_29 ;
goto V_353;
}
if ( ! V_13 -> V_196 ) {
V_350 = - V_354 ;
goto V_353;
}
V_350 = V_349 -> V_355 ( V_13 , V_349 ) ;
if ( V_350 )
goto V_353;
F_54 ( & V_349 -> V_57 , & V_13 -> V_356 ) ;
V_350 = 0 ;
V_353:
F_150 ( V_189 ) ;
return V_350 ;
}
void F_151 ( struct V_12 * V_13 , struct V_348 * V_349 )
{
struct V_260 * V_189 = V_13 -> V_8 -> V_189 ;
F_149 ( V_189 ) ;
if ( ! V_349 -> V_57 . V_351 || ! V_349 -> V_57 . V_352 )
goto V_353;
F_59 ( & V_349 -> V_57 ) ;
V_349 -> V_57 . V_351 = NULL ;
V_349 -> V_57 . V_352 = NULL ;
V_349 -> remove ( V_13 , V_349 ) ;
V_353:
F_150 ( V_189 ) ;
}
static void F_152 ( struct V_12 * V_13 )
{
struct V_348 * V_349 ;
while ( ! F_153 ( & V_13 -> V_356 ) ) {
V_349 = F_154 ( & V_13 -> V_356 , struct V_348 , V_57 ) ;
F_59 ( & V_349 -> V_57 ) ;
V_349 -> V_57 . V_351 = NULL ;
V_349 -> V_57 . V_352 = NULL ;
V_349 -> remove ( V_13 , V_349 ) ;
}
}
static void F_155 ( struct V_7 * V_8 , int V_24 )
{
struct V_12 * V_13 = V_8 -> V_357 ;
struct V_11 * V_23 , * V_358 ;
if ( ! V_13 )
return;
F_23 ( L_16 , V_8 , V_13 , V_24 ) ;
F_97 ( V_13 -> V_359 ) ;
F_77 ( & V_13 -> V_360 ) ;
if ( F_156 ( & V_13 -> V_346 ) )
F_157 ( & V_13 -> V_346 ) ;
if ( F_156 ( & V_13 -> V_149 ) )
F_157 ( & V_13 -> V_149 ) ;
F_152 ( V_13 ) ;
V_8 -> V_361 = 0 ;
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
F_158 ( V_13 -> V_196 ) ;
if ( V_13 -> V_300 & V_301 )
F_159 ( & V_13 -> V_304 ) ;
V_8 -> V_357 = NULL ;
V_13 -> V_196 = NULL ;
F_160 ( V_13 ) ;
}
static void F_161 ( struct V_83 * V_362 )
{
struct V_12 * V_13 = F_46 ( V_362 , struct V_12 , V_362 ) ;
F_162 ( V_13 -> V_8 ) ;
F_40 ( V_13 ) ;
}
struct V_12 * F_163 ( struct V_12 * V_13 )
{
F_62 ( & V_13 -> V_362 ) ;
return V_13 ;
}
void F_160 ( struct V_12 * V_13 )
{
F_63 ( & V_13 -> V_362 , F_161 ) ;
}
static struct V_11 * F_164 ( int V_38 , T_3 V_20 ,
T_4 * V_21 ,
T_4 * V_150 ,
T_1 V_1 )
{
struct V_11 * V_15 , * V_363 = NULL ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
if ( V_38 && V_15 -> V_38 != V_38 )
continue;
if ( V_1 == V_117 && V_15 -> V_9 != V_6 )
continue;
if ( V_1 == V_2 && V_15 -> V_9 == V_6 )
continue;
if ( V_15 -> V_20 == V_20 ) {
int V_364 , V_365 ;
int V_366 , V_367 ;
V_364 = ! F_15 ( & V_15 -> V_21 , V_21 ) ;
V_365 = ! F_15 ( & V_15 -> V_150 , V_150 ) ;
if ( V_364 && V_365 ) {
F_60 ( V_15 ) ;
F_123 ( & V_25 ) ;
return V_15 ;
}
V_366 = ! F_15 ( & V_15 -> V_21 , V_368 ) ;
V_367 = ! F_15 ( & V_15 -> V_150 , V_368 ) ;
if ( ( V_364 && V_367 ) || ( V_366 && V_365 ) ||
( V_366 && V_367 ) )
V_363 = V_15 ;
}
}
if ( V_363 )
F_60 ( V_363 ) ;
F_123 ( & V_25 ) ;
return V_363 ;
}
static void F_165 ( struct V_64 * V_65 )
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
F_129 ( V_23 , NULL , NULL , V_369 ) ;
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
}
static void F_166 ( struct V_64 * V_65 )
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
F_129 ( V_23 , NULL , NULL , V_370 ) ;
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
}
static void F_167 ( struct V_11 * V_23 ,
struct V_46 * V_371 )
{
struct V_45 * V_49 ;
struct V_204 * V_50 ;
F_23 ( L_17 , V_23 , V_371 ) ;
if ( F_95 ( V_23 ) )
return;
F_168 ( V_371 , & V_23 -> V_113 ) ;
while ( ! F_169 ( & V_23 -> V_113 ) ) {
V_49 = F_170 ( & V_23 -> V_113 ) ;
F_35 ( V_49 ) -> V_50 . V_278 = 1 ;
V_50 = & F_35 ( V_49 ) -> V_50 ;
V_50 -> V_205 = 0 ;
V_50 -> V_51 = V_23 -> V_372 ;
F_106 ( V_23 , V_50 , V_49 ) ;
if ( V_23 -> V_87 == V_88 ) {
T_2 V_87 = F_114 ( 0 , ( T_1 * ) V_49 -> V_188 , V_49 -> V_187 ) ;
F_108 ( V_87 , F_113 ( V_49 , V_248 ) ) ;
}
F_96 ( V_23 , V_49 ) ;
F_23 ( L_18 , V_50 -> V_51 ) ;
V_23 -> V_372 = F_171 ( V_23 , V_23 -> V_372 ) ;
V_23 -> V_373 ++ ;
}
}
static int F_172 ( struct V_11 * V_23 )
{
struct V_45 * V_49 , * V_374 ;
struct V_204 * V_50 ;
int V_375 = 0 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_38 != V_68 )
return - V_376 ;
if ( F_70 ( V_286 , & V_23 -> V_251 ) )
return 0 ;
if ( F_95 ( V_23 ) )
return 0 ;
while ( V_23 -> V_377 &&
V_23 -> V_378 < V_23 -> V_95 &&
V_23 -> V_282 == V_283 ) {
V_49 = V_23 -> V_377 ;
F_35 ( V_49 ) -> V_50 . V_278 = 1 ;
V_50 = & F_35 ( V_49 ) -> V_50 ;
if ( F_116 ( V_250 , & V_23 -> V_251 ) )
V_50 -> V_208 = 1 ;
V_50 -> V_205 = V_23 -> V_258 ;
V_23 -> V_256 = V_23 -> V_258 ;
V_50 -> V_51 = V_23 -> V_372 ;
F_106 ( V_23 , V_50 , V_49 ) ;
if ( V_23 -> V_87 == V_88 ) {
T_2 V_87 = F_114 ( 0 , ( T_1 * ) V_49 -> V_188 , V_49 -> V_187 ) ;
F_108 ( V_87 , F_113 ( V_49 , V_248 ) ) ;
}
V_374 = F_173 ( V_49 , V_58 ) ;
if ( ! V_374 )
break;
F_27 ( V_23 ) ;
V_23 -> V_372 = F_171 ( V_23 , V_23 -> V_372 ) ;
V_23 -> V_378 ++ ;
V_23 -> V_373 ++ ;
V_375 ++ ;
if ( F_174 ( & V_23 -> V_113 , V_49 ) )
V_23 -> V_377 = NULL ;
else
V_23 -> V_377 = F_175 ( & V_23 -> V_113 , V_49 ) ;
F_96 ( V_23 , V_374 ) ;
F_23 ( L_18 , V_50 -> V_51 ) ;
}
F_23 ( L_19 , V_375 ,
V_23 -> V_378 , F_176 ( & V_23 -> V_113 ) ) ;
return V_375 ;
}
static void F_177 ( struct V_11 * V_23 )
{
struct V_204 V_50 ;
struct V_45 * V_49 ;
struct V_45 * V_374 ;
T_2 V_48 ;
F_23 ( L_3 , V_23 ) ;
if ( F_70 ( V_286 , & V_23 -> V_251 ) )
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
F_35 ( V_49 ) -> V_50 . V_278 ++ ;
V_50 = F_35 ( V_49 ) -> V_50 ;
if ( V_23 -> V_89 != 0 &&
F_35 ( V_49 ) -> V_50 . V_278 > V_23 -> V_89 ) {
F_23 ( L_21 , V_23 -> V_89 ) ;
F_86 ( V_23 , V_319 ) ;
F_43 ( & V_23 -> V_147 ) ;
break;
}
V_50 . V_205 = V_23 -> V_258 ;
if ( F_116 ( V_250 , & V_23 -> V_251 ) )
V_50 . V_208 = 1 ;
else
V_50 . V_208 = 0 ;
if ( F_178 ( V_49 ) ) {
V_374 = F_179 ( V_49 , V_58 ) ;
} else {
V_374 = F_173 ( V_49 , V_58 ) ;
}
if ( ! V_374 ) {
F_43 ( & V_23 -> V_147 ) ;
break;
}
if ( F_70 ( V_238 , & V_23 -> V_103 ) ) {
F_107 ( F_104 ( & V_50 ) ,
V_374 -> V_188 + V_242 ) ;
} else {
F_108 ( F_105 ( & V_50 ) ,
V_374 -> V_188 + V_242 ) ;
}
if ( V_23 -> V_87 == V_88 ) {
T_2 V_87 = F_114 ( 0 , ( T_1 * ) V_374 -> V_188 ,
V_374 -> V_187 - V_248 ) ;
F_108 ( V_87 , F_180 ( V_374 ) -
V_248 ) ;
}
F_96 ( V_23 , V_374 ) ;
F_23 ( L_22 , V_50 . V_51 ) ;
V_23 -> V_256 = V_23 -> V_258 ;
}
}
static void F_181 ( struct V_11 * V_23 ,
struct V_204 * V_50 )
{
F_23 ( L_10 , V_23 , V_50 ) ;
F_44 ( & V_23 -> V_147 , V_50 -> V_205 ) ;
F_177 ( V_23 ) ;
}
static void F_182 ( struct V_11 * V_23 ,
struct V_204 * V_50 )
{
struct V_45 * V_49 ;
F_23 ( L_10 , V_23 , V_50 ) ;
if ( V_50 -> V_213 )
F_57 ( V_250 , & V_23 -> V_251 ) ;
F_43 ( & V_23 -> V_147 ) ;
if ( F_70 ( V_286 , & V_23 -> V_251 ) )
return;
if ( V_23 -> V_378 ) {
F_34 (&chan->tx_q, skb) {
if ( F_35 ( V_49 ) -> V_50 . V_51 == V_50 -> V_205 ||
V_49 == V_23 -> V_377 )
break;
}
F_183 (&chan->tx_q, skb) {
if ( V_49 == V_23 -> V_377 )
break;
F_44 ( & V_23 -> V_147 ,
F_35 ( V_49 ) -> V_50 . V_51 ) ;
}
F_177 ( V_23 ) ;
}
}
static void F_184 ( struct V_11 * V_23 )
{
struct V_204 V_50 ;
T_2 V_379 = F_185 ( V_23 , V_23 -> V_258 ,
V_23 -> V_256 ) ;
int V_380 ;
F_23 ( L_23 ,
V_23 , V_23 -> V_256 , V_23 -> V_258 ) ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_212 = 1 ;
if ( F_70 ( V_257 , & V_23 -> V_251 ) &&
V_23 -> V_284 == V_381 ) {
F_79 ( V_23 ) ;
V_50 . V_216 = V_254 ;
V_50 . V_205 = V_23 -> V_258 ;
F_115 ( V_23 , & V_50 ) ;
} else {
if ( ! F_70 ( V_286 , & V_23 -> V_251 ) ) {
F_172 ( V_23 ) ;
if ( V_23 -> V_258 == V_23 -> V_256 )
V_379 = 0 ;
}
V_380 = V_23 -> V_96 ;
V_380 += V_380 << 1 ;
V_380 >>= 2 ;
F_23 ( L_24 , V_379 ,
V_380 ) ;
if ( V_379 >= V_380 ) {
F_79 ( V_23 ) ;
V_50 . V_216 = V_252 ;
V_50 . V_205 = V_23 -> V_258 ;
F_115 ( V_23 , & V_50 ) ;
V_379 = 0 ;
}
if ( V_379 )
F_186 ( V_23 ) ;
}
}
static inline int F_187 ( struct V_11 * V_23 ,
struct V_382 * V_383 , int V_187 ,
int V_384 , struct V_45 * V_49 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_45 * * V_385 ;
int V_375 = 0 ;
if ( F_188 ( F_113 ( V_49 , V_384 ) , V_384 , & V_383 -> V_386 ) != V_384 )
return - V_387 ;
V_375 += V_384 ;
V_187 -= V_384 ;
V_385 = & F_189 ( V_49 ) -> V_388 ;
while ( V_187 ) {
struct V_45 * V_317 ;
V_384 = F_66 (unsigned int, conn->mtu, len) ;
V_317 = V_23 -> V_39 -> V_389 ( V_23 , 0 , V_384 ,
V_383 -> V_390 & V_391 ) ;
if ( F_118 ( V_317 ) )
return F_190 ( V_317 ) ;
* V_385 = V_317 ;
if ( F_188 ( F_113 ( * V_385 , V_384 ) , V_384 ,
& V_383 -> V_386 ) != V_384 )
return - V_387 ;
V_375 += V_384 ;
V_187 -= V_384 ;
V_49 -> V_187 += ( * V_385 ) -> V_187 ;
V_49 -> V_392 += ( * V_385 ) -> V_187 ;
V_385 = & ( * V_385 ) -> V_351 ;
}
return V_375 ;
}
static struct V_45 * F_191 ( struct V_11 * V_23 ,
struct V_382 * V_383 , T_6 V_187 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_45 * V_49 ;
int V_24 , V_384 , V_247 = V_242 + V_393 ;
struct V_245 * V_246 ;
F_23 ( L_25 , V_23 ,
F_69 ( V_23 -> V_20 ) , V_187 ) ;
V_384 = F_66 (unsigned int, (conn->mtu - hlen), len) ;
V_49 = V_23 -> V_39 -> V_389 ( V_23 , V_247 , V_384 ,
V_383 -> V_390 & V_391 ) ;
if ( F_118 ( V_49 ) )
return V_49 ;
V_246 = (struct V_245 * ) F_113 ( V_49 , V_242 ) ;
V_246 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_246 -> V_187 = F_18 ( V_187 + V_393 ) ;
F_192 ( V_23 -> V_20 , ( T_3 * ) F_113 ( V_49 , V_393 ) ) ;
V_24 = F_187 ( V_23 , V_383 , V_187 , V_384 , V_49 ) ;
if ( F_193 ( V_24 < 0 ) ) {
F_97 ( V_49 ) ;
return F_112 ( V_24 ) ;
}
return V_49 ;
}
static struct V_45 * F_194 ( struct V_11 * V_23 ,
struct V_382 * V_383 , T_6 V_187 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_45 * V_49 ;
int V_24 , V_384 ;
struct V_245 * V_246 ;
F_23 ( L_26 , V_23 , V_187 ) ;
V_384 = F_66 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_49 = V_23 -> V_39 -> V_389 ( V_23 , V_242 , V_384 ,
V_383 -> V_390 & V_391 ) ;
if ( F_118 ( V_49 ) )
return V_49 ;
V_246 = (struct V_245 * ) F_113 ( V_49 , V_242 ) ;
V_246 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_246 -> V_187 = F_18 ( V_187 ) ;
V_24 = F_187 ( V_23 , V_383 , V_187 , V_384 , V_49 ) ;
if ( F_193 ( V_24 < 0 ) ) {
F_97 ( V_49 ) ;
return F_112 ( V_24 ) ;
}
return V_49 ;
}
static struct V_45 * F_195 ( struct V_11 * V_23 ,
struct V_382 * V_383 , T_6 V_187 ,
T_2 V_394 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_45 * V_49 ;
int V_24 , V_384 , V_247 ;
struct V_245 * V_246 ;
F_23 ( L_26 , V_23 , V_187 ) ;
if ( ! V_13 )
return F_112 ( - V_376 ) ;
V_247 = F_109 ( V_23 ) ;
if ( V_394 )
V_247 += V_395 ;
if ( V_23 -> V_87 == V_88 )
V_247 += V_248 ;
V_384 = F_66 (unsigned int, (conn->mtu - hlen), len) ;
V_49 = V_23 -> V_39 -> V_389 ( V_23 , V_247 , V_384 ,
V_383 -> V_390 & V_391 ) ;
if ( F_118 ( V_49 ) )
return V_49 ;
V_246 = (struct V_245 * ) F_113 ( V_49 , V_242 ) ;
V_246 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_246 -> V_187 = F_18 ( V_187 + ( V_247 - V_242 ) ) ;
if ( F_70 ( V_238 , & V_23 -> V_103 ) )
F_107 ( 0 , F_113 ( V_49 , V_239 ) ) ;
else
F_108 ( 0 , F_113 ( V_49 , V_240 ) ) ;
if ( V_394 )
F_108 ( V_394 , F_113 ( V_49 , V_395 ) ) ;
V_24 = F_187 ( V_23 , V_383 , V_187 , V_384 , V_49 ) ;
if ( F_193 ( V_24 < 0 ) ) {
F_97 ( V_49 ) ;
return F_112 ( V_24 ) ;
}
F_35 ( V_49 ) -> V_50 . V_87 = V_23 -> V_87 ;
F_35 ( V_49 ) -> V_50 . V_278 = 0 ;
return V_49 ;
}
static int F_196 ( struct V_11 * V_23 ,
struct V_46 * V_396 ,
struct V_382 * V_383 , T_6 V_187 )
{
struct V_45 * V_49 ;
T_2 V_106 ;
T_6 V_397 ;
T_1 V_219 ;
F_23 ( L_27 , V_23 , V_383 , V_187 ) ;
V_397 = V_23 -> V_13 -> V_158 ;
if ( ! V_23 -> V_200 )
V_397 = F_66 ( T_6 , V_397 , V_398 ) ;
if ( V_23 -> V_87 )
V_397 -= V_248 ;
V_397 -= F_109 ( V_23 ) ;
V_397 = F_66 ( T_6 , V_397 , V_23 -> V_399 ) ;
if ( V_187 <= V_397 ) {
V_219 = V_400 ;
V_106 = 0 ;
V_397 = V_187 ;
} else {
V_219 = V_401 ;
V_106 = V_187 ;
}
while ( V_187 > 0 ) {
V_49 = F_195 ( V_23 , V_383 , V_397 , V_106 ) ;
if ( F_118 ( V_49 ) ) {
F_197 ( V_396 ) ;
return F_190 ( V_49 ) ;
}
F_35 ( V_49 ) -> V_50 . V_219 = V_219 ;
F_198 ( V_396 , V_49 ) ;
V_187 -= V_397 ;
if ( V_106 )
V_106 = 0 ;
if ( V_187 <= V_397 ) {
V_219 = V_402 ;
V_397 = V_187 ;
} else {
V_219 = V_403 ;
}
}
return 0 ;
}
static struct V_45 * F_199 ( struct V_11 * V_23 ,
struct V_382 * V_383 ,
T_6 V_187 , T_2 V_394 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_45 * V_49 ;
int V_24 , V_384 , V_247 ;
struct V_245 * V_246 ;
F_23 ( L_26 , V_23 , V_187 ) ;
if ( ! V_13 )
return F_112 ( - V_376 ) ;
V_247 = V_242 ;
if ( V_394 )
V_247 += V_395 ;
V_384 = F_66 (unsigned int, (conn->mtu - hlen), len) ;
V_49 = V_23 -> V_39 -> V_389 ( V_23 , V_247 , V_384 ,
V_383 -> V_390 & V_391 ) ;
if ( F_118 ( V_49 ) )
return V_49 ;
V_246 = (struct V_245 * ) F_113 ( V_49 , V_242 ) ;
V_246 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_246 -> V_187 = F_18 ( V_187 + ( V_247 - V_242 ) ) ;
if ( V_394 )
F_108 ( V_394 , F_113 ( V_49 , V_395 ) ) ;
V_24 = F_187 ( V_23 , V_383 , V_187 , V_384 , V_49 ) ;
if ( F_193 ( V_24 < 0 ) ) {
F_97 ( V_49 ) ;
return F_112 ( V_24 ) ;
}
return V_49 ;
}
static int F_200 ( struct V_11 * V_23 ,
struct V_46 * V_396 ,
struct V_382 * V_383 , T_6 V_187 )
{
struct V_45 * V_49 ;
T_6 V_397 ;
T_2 V_106 ;
F_23 ( L_27 , V_23 , V_383 , V_187 ) ;
V_106 = V_187 ;
V_397 = V_23 -> V_399 - V_395 ;
while ( V_187 > 0 ) {
if ( V_187 <= V_397 )
V_397 = V_187 ;
V_49 = F_199 ( V_23 , V_383 , V_397 , V_106 ) ;
if ( F_118 ( V_49 ) ) {
F_197 ( V_396 ) ;
return F_190 ( V_49 ) ;
}
F_198 ( V_396 , V_49 ) ;
V_187 -= V_397 ;
if ( V_106 ) {
V_106 = 0 ;
V_397 += V_395 ;
}
}
return 0 ;
}
int F_201 ( struct V_11 * V_23 , struct V_382 * V_383 , T_6 V_187 )
{
struct V_45 * V_49 ;
int V_24 ;
struct V_46 V_396 ;
if ( ! V_23 -> V_13 )
return - V_376 ;
if ( V_23 -> V_32 == V_118 ) {
V_49 = F_191 ( V_23 , V_383 , V_187 ) ;
if ( F_118 ( V_49 ) )
return F_190 ( V_49 ) ;
if ( V_23 -> V_38 != V_68 ) {
F_97 ( V_49 ) ;
return - V_376 ;
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
F_202 ( & V_396 ) ;
V_24 = F_200 ( V_23 , & V_396 , V_383 , V_187 ) ;
if ( V_23 -> V_38 != V_68 ) {
F_197 ( & V_396 ) ;
V_24 = - V_376 ;
}
if ( V_24 )
return V_24 ;
F_168 ( & V_396 , & V_23 -> V_113 ) ;
while ( V_23 -> V_107 && ! F_169 ( & V_23 -> V_113 ) ) {
F_96 ( V_23 , F_170 ( & V_23 -> V_113 ) ) ;
V_23 -> V_107 -- ;
}
if ( ! V_23 -> V_107 )
V_23 -> V_39 -> V_294 ( V_23 ) ;
V_24 = V_187 ;
break;
case V_142 :
if ( V_187 > V_23 -> V_30 )
return - V_404 ;
V_49 = F_194 ( V_23 , V_383 , V_187 ) ;
if ( F_118 ( V_49 ) )
return F_190 ( V_49 ) ;
if ( V_23 -> V_38 != V_68 ) {
F_97 ( V_49 ) ;
return - V_376 ;
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
F_202 ( & V_396 ) ;
V_24 = F_196 ( V_23 , & V_396 , V_383 , V_187 ) ;
if ( V_23 -> V_38 != V_68 ) {
F_197 ( & V_396 ) ;
V_24 = - V_376 ;
}
if ( V_24 )
break;
if ( V_23 -> V_141 == V_144 )
F_129 ( V_23 , NULL , & V_396 , V_406 ) ;
else
F_167 ( V_23 , & V_396 ) ;
V_24 = V_187 ;
F_197 ( & V_396 ) ;
break;
default:
F_23 ( L_28 , V_23 -> V_141 ) ;
V_24 = - V_407 ;
}
return V_24 ;
}
static void F_203 ( struct V_11 * V_23 , T_2 V_51 )
{
struct V_204 V_50 ;
T_2 V_48 ;
F_23 ( L_29 , V_23 , V_51 ) ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_212 = 1 ;
V_50 . V_216 = V_255 ;
for ( V_48 = V_23 -> V_279 ; V_48 != V_51 ;
V_48 = F_171 ( V_23 , V_48 ) ) {
if ( ! F_33 ( & V_23 -> V_145 , V_48 ) ) {
V_50 . V_205 = V_48 ;
F_115 ( V_23 , & V_50 ) ;
F_44 ( & V_23 -> V_146 , V_48 ) ;
}
}
V_23 -> V_279 = F_171 ( V_23 , V_51 ) ;
}
static void F_204 ( struct V_11 * V_23 )
{
struct V_204 V_50 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_146 . V_62 == V_61 )
return;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_212 = 1 ;
V_50 . V_216 = V_255 ;
V_50 . V_205 = V_23 -> V_146 . V_62 ;
F_115 ( V_23 , & V_50 ) ;
}
static void F_205 ( struct V_11 * V_23 , T_2 V_51 )
{
struct V_204 V_50 ;
T_2 V_408 ;
T_2 V_48 ;
F_23 ( L_29 , V_23 , V_51 ) ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_212 = 1 ;
V_50 . V_216 = V_255 ;
V_408 = V_23 -> V_146 . V_47 ;
do {
V_48 = F_42 ( & V_23 -> V_146 ) ;
if ( V_48 == V_51 || V_48 == V_61 )
break;
V_50 . V_205 = V_48 ;
F_115 ( V_23 , & V_50 ) ;
F_44 ( & V_23 -> V_146 , V_48 ) ;
} while ( V_23 -> V_146 . V_47 != V_408 );
}
static void F_206 ( struct V_11 * V_23 , T_2 V_205 )
{
struct V_45 * V_409 ;
T_2 V_410 ;
F_23 ( L_30 , V_23 , V_205 ) ;
if ( V_23 -> V_378 == 0 || V_205 == V_23 -> V_411 )
return;
F_23 ( L_31 ,
V_23 -> V_411 , V_23 -> V_378 ) ;
for ( V_410 = V_23 -> V_411 ; V_410 != V_205 ;
V_410 = F_171 ( V_23 , V_410 ) ) {
V_409 = F_33 ( & V_23 -> V_113 , V_410 ) ;
if ( V_409 ) {
F_207 ( V_409 , & V_23 -> V_113 ) ;
F_97 ( V_409 ) ;
V_23 -> V_378 -- ;
}
}
V_23 -> V_411 = V_205 ;
if ( V_23 -> V_378 == 0 )
F_32 ( V_23 ) ;
F_23 ( L_32 , V_23 -> V_378 ) ;
}
static void F_208 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
V_23 -> V_279 = V_23 -> V_258 ;
F_43 ( & V_23 -> V_146 ) ;
F_77 ( & V_23 -> V_145 ) ;
V_23 -> V_284 = V_381 ;
}
static void F_209 ( struct V_11 * V_23 ,
struct V_204 * V_50 ,
struct V_46 * V_371 , T_1 V_412 )
{
F_23 ( L_33 , V_23 , V_50 , V_371 ,
V_412 ) ;
switch ( V_412 ) {
case V_406 :
if ( V_23 -> V_377 == NULL )
V_23 -> V_377 = F_210 ( V_371 ) ;
F_168 ( V_371 , & V_23 -> V_113 ) ;
F_172 ( V_23 ) ;
break;
case V_413 :
F_23 ( L_34 ) ;
F_57 ( V_257 , & V_23 -> V_251 ) ;
if ( V_23 -> V_284 == V_414 ) {
F_208 ( V_23 ) ;
}
F_184 ( V_23 ) ;
break;
case V_415 :
F_23 ( L_35 ) ;
F_117 ( V_257 , & V_23 -> V_251 ) ;
if ( F_70 ( V_253 , & V_23 -> V_251 ) ) {
struct V_204 V_416 ;
memset ( & V_416 , 0 , sizeof( V_416 ) ) ;
V_416 . V_212 = 1 ;
V_416 . V_216 = V_252 ;
V_416 . V_213 = 1 ;
V_416 . V_205 = V_23 -> V_258 ;
F_115 ( V_23 , & V_416 ) ;
V_23 -> V_277 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_282 = V_417 ;
}
break;
case V_418 :
F_206 ( V_23 , V_50 -> V_205 ) ;
break;
case V_290 :
F_119 ( V_23 , 1 ) ;
V_23 -> V_277 = 1 ;
F_31 ( V_23 ) ;
F_79 ( V_23 ) ;
V_23 -> V_282 = V_417 ;
break;
case V_370 :
F_119 ( V_23 , 1 ) ;
V_23 -> V_277 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_282 = V_417 ;
break;
case V_419 :
break;
default:
break;
}
}
static void F_211 ( struct V_11 * V_23 ,
struct V_204 * V_50 ,
struct V_46 * V_371 , T_1 V_412 )
{
F_23 ( L_33 , V_23 , V_50 , V_371 ,
V_412 ) ;
switch ( V_412 ) {
case V_406 :
if ( V_23 -> V_377 == NULL )
V_23 -> V_377 = F_210 ( V_371 ) ;
F_168 ( V_371 , & V_23 -> V_113 ) ;
break;
case V_413 :
F_23 ( L_34 ) ;
F_57 ( V_257 , & V_23 -> V_251 ) ;
if ( V_23 -> V_284 == V_414 ) {
F_208 ( V_23 ) ;
}
F_184 ( V_23 ) ;
break;
case V_415 :
F_23 ( L_35 ) ;
F_117 ( V_257 , & V_23 -> V_251 ) ;
if ( F_70 ( V_253 , & V_23 -> V_251 ) ) {
struct V_204 V_416 ;
memset ( & V_416 , 0 , sizeof( V_416 ) ) ;
V_416 . V_212 = 1 ;
V_416 . V_216 = V_252 ;
V_416 . V_213 = 1 ;
V_416 . V_205 = V_23 -> V_258 ;
F_115 ( V_23 , & V_416 ) ;
V_23 -> V_277 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_282 = V_417 ;
}
break;
case V_418 :
F_206 ( V_23 , V_50 -> V_205 ) ;
case V_419 :
if ( V_50 && V_50 -> V_208 ) {
F_78 ( V_23 ) ;
if ( V_23 -> V_378 > 0 )
F_27 ( V_23 ) ;
V_23 -> V_277 = 0 ;
V_23 -> V_282 = V_283 ;
F_23 ( L_36 , V_23 -> V_282 ) ;
}
break;
case V_290 :
break;
case V_369 :
if ( V_23 -> V_89 == 0 || V_23 -> V_277 < V_23 -> V_89 ) {
F_119 ( V_23 , 1 ) ;
F_31 ( V_23 ) ;
V_23 -> V_277 ++ ;
} else {
F_86 ( V_23 , V_420 ) ;
}
break;
default:
break;
}
}
static void F_129 ( struct V_11 * V_23 , struct V_204 * V_50 ,
struct V_46 * V_371 , T_1 V_412 )
{
F_23 ( L_37 ,
V_23 , V_50 , V_371 , V_412 , V_23 -> V_282 ) ;
switch ( V_23 -> V_282 ) {
case V_283 :
F_209 ( V_23 , V_50 , V_371 , V_412 ) ;
break;
case V_417 :
F_211 ( V_23 , V_50 , V_371 , V_412 ) ;
break;
default:
break;
}
}
static void F_212 ( struct V_11 * V_23 ,
struct V_204 * V_50 )
{
F_23 ( L_10 , V_23 , V_50 ) ;
F_129 ( V_23 , V_50 , NULL , V_418 ) ;
}
static void F_213 ( struct V_11 * V_23 ,
struct V_204 * V_50 )
{
F_23 ( L_10 , V_23 , V_50 ) ;
F_129 ( V_23 , V_50 , NULL , V_419 ) ;
}
static void F_214 ( struct V_12 * V_13 , struct V_45 * V_49 )
{
struct V_45 * V_421 ;
struct V_11 * V_23 ;
F_23 ( L_14 , V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
if ( V_23 -> V_32 != V_169 )
continue;
if ( F_35 ( V_49 ) -> V_23 == V_23 )
continue;
V_421 = F_173 ( V_49 , V_58 ) ;
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
struct V_45 * V_49 , * * V_385 ;
struct V_424 * V_425 ;
struct V_245 * V_246 ;
int V_187 , V_384 ;
F_23 ( L_38 ,
V_13 , V_186 , V_19 , V_423 ) ;
if ( V_13 -> V_158 < V_242 + V_426 )
return NULL ;
V_187 = V_242 + V_426 + V_423 ;
V_384 = F_66 (unsigned int, conn->mtu, len) ;
V_49 = F_111 ( V_384 , V_58 ) ;
if ( ! V_49 )
return NULL ;
V_246 = (struct V_245 * ) F_113 ( V_49 , V_242 ) ;
V_246 -> V_187 = F_18 ( V_426 + V_423 ) ;
if ( V_13 -> V_8 -> type == V_2 )
V_246 -> V_14 = F_18 ( V_427 ) ;
else
V_246 -> V_14 = F_18 ( V_120 ) ;
V_425 = (struct V_424 * ) F_113 ( V_49 , V_426 ) ;
V_425 -> V_186 = V_186 ;
V_425 -> V_19 = V_19 ;
V_425 -> V_187 = F_18 ( V_423 ) ;
if ( V_423 ) {
V_384 -= V_242 + V_426 ;
memcpy ( F_113 ( V_49 , V_384 ) , V_188 , V_384 ) ;
V_188 += V_384 ;
}
V_187 -= V_49 -> V_187 ;
V_385 = & F_189 ( V_49 ) -> V_388 ;
while ( V_187 ) {
V_384 = F_66 (unsigned int, conn->mtu, len) ;
* V_385 = F_111 ( V_384 , V_58 ) ;
if ( ! * V_385 )
goto V_428;
memcpy ( F_113 ( * V_385 , V_384 ) , V_188 , V_384 ) ;
V_187 -= V_384 ;
V_188 += V_384 ;
V_385 = & ( * V_385 ) -> V_351 ;
}
return V_49 ;
V_428:
F_97 ( V_49 ) ;
return NULL ;
}
static inline int F_215 ( void * * V_429 , int * type , int * V_430 ,
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
static void F_216 ( void * * V_429 , T_1 type , T_1 V_187 , unsigned long V_431 )
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
static void F_217 ( void * * V_429 , struct V_11 * V_23 )
{
struct V_435 V_436 ;
switch ( V_23 -> V_141 ) {
case V_144 :
V_436 . V_183 = V_23 -> V_121 ;
V_436 . V_437 = V_23 -> V_123 ;
V_436 . V_438 = F_18 ( V_23 -> V_125 ) ;
V_436 . V_439 = F_218 ( V_23 -> V_127 ) ;
V_436 . V_440 = F_218 ( V_130 ) ;
V_436 . V_98 = F_218 ( V_132 ) ;
break;
case V_148 :
V_436 . V_183 = 1 ;
V_436 . V_437 = V_124 ;
V_436 . V_438 = F_18 ( V_23 -> V_125 ) ;
V_436 . V_439 = F_218 ( V_23 -> V_127 ) ;
V_436 . V_440 = 0 ;
V_436 . V_98 = 0 ;
break;
default:
return;
}
F_216 ( V_429 , V_441 , sizeof( V_436 ) ,
( unsigned long ) & V_436 ) ;
}
static void F_219 ( struct V_64 * V_65 )
{
struct V_11 * V_23 = F_46 ( V_65 , struct V_11 ,
V_442 . V_65 ) ;
T_2 V_379 ;
F_23 ( L_3 , V_23 ) ;
F_9 ( V_23 ) ;
V_379 = F_185 ( V_23 , V_23 -> V_258 ,
V_23 -> V_256 ) ;
if ( V_379 )
F_119 ( V_23 , 0 ) ;
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
}
int F_220 ( struct V_11 * V_23 )
{
int V_24 ;
V_23 -> V_372 = 0 ;
V_23 -> V_279 = 0 ;
V_23 -> V_411 = 0 ;
V_23 -> V_378 = 0 ;
V_23 -> V_258 = 0 ;
V_23 -> V_373 = 0 ;
V_23 -> V_256 = 0 ;
V_23 -> V_104 = NULL ;
V_23 -> V_105 = NULL ;
V_23 -> V_106 = 0 ;
F_67 ( & V_23 -> V_113 ) ;
V_23 -> V_443 = V_444 ;
V_23 -> V_445 = V_444 ;
V_23 -> V_197 = V_198 ;
V_23 -> V_287 = V_288 ;
if ( V_23 -> V_141 != V_144 )
return 0 ;
V_23 -> V_284 = V_381 ;
V_23 -> V_282 = V_283 ;
F_55 ( & V_23 -> V_43 , F_166 ) ;
F_55 ( & V_23 -> V_41 , F_165 ) ;
F_55 ( & V_23 -> V_442 , F_219 ) ;
F_67 ( & V_23 -> V_145 ) ;
V_24 = F_36 ( & V_23 -> V_146 , V_23 -> V_91 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_36 ( & V_23 -> V_147 , V_23 -> V_95 ) ;
if ( V_24 < 0 )
F_39 ( & V_23 -> V_146 ) ;
return V_24 ;
}
static inline T_7 F_221 ( T_7 V_141 , T_5 V_446 )
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
static inline bool F_222 ( struct V_12 * V_13 )
{
return ( ( V_13 -> V_262 & V_263 ) &&
( V_13 -> V_308 & V_447 ) ) ;
}
static inline bool F_223 ( struct V_12 * V_13 )
{
return ( ( V_13 -> V_262 & V_263 ) &&
( V_13 -> V_308 & V_448 ) ) ;
}
static void F_224 ( struct V_11 * V_23 ,
struct V_449 * V_450 )
{
if ( V_23 -> V_443 != V_444 && V_23 -> V_200 ) {
T_10 V_451 = V_23 -> V_200 -> V_189 -> V_452 ;
V_451 = F_225 ( V_451 , 1000 ) ;
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
static inline void F_226 ( struct V_11 * V_23 )
{
if ( V_23 -> V_91 > V_92 &&
F_222 ( V_23 -> V_13 ) ) {
F_57 ( V_238 , & V_23 -> V_103 ) ;
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
struct V_454 * V_272 = V_188 ;
struct V_449 V_450 = { . V_141 = V_23 -> V_141 } ;
void * V_429 = V_272 -> V_188 ;
T_2 V_54 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_328 || V_23 -> V_455 )
goto V_27;
switch ( V_23 -> V_141 ) {
case V_148 :
case V_144 :
if ( F_70 ( V_318 , & V_23 -> V_85 ) )
break;
if ( F_223 ( V_23 -> V_13 ) )
F_57 ( V_456 , & V_23 -> V_103 ) ;
default:
V_23 -> V_141 = F_221 ( V_450 . V_141 , V_23 -> V_13 -> V_308 ) ;
break;
}
V_27:
if ( V_23 -> V_111 != V_31 )
F_216 ( & V_429 , V_457 , 2 , V_23 -> V_111 ) ;
switch ( V_23 -> V_141 ) {
case V_142 :
if ( V_311 )
break;
if ( ! ( V_23 -> V_13 -> V_308 & V_312 ) &&
! ( V_23 -> V_13 -> V_308 & V_313 ) )
break;
V_450 . V_141 = V_142 ;
V_450 . V_458 = 0 ;
V_450 . V_459 = 0 ;
V_450 . V_42 = 0 ;
V_450 . V_44 = 0 ;
V_450 . V_460 = 0 ;
F_216 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
break;
case V_144 :
V_450 . V_141 = V_144 ;
V_450 . V_459 = V_23 -> V_89 ;
F_224 ( V_23 , & V_450 ) ;
V_54 = F_66 ( T_2 , V_462 , V_23 -> V_13 -> V_158 -
V_243 - V_395 -
V_248 ) ;
V_450 . V_460 = F_18 ( V_54 ) ;
F_226 ( V_23 ) ;
V_450 . V_458 = F_66 ( T_2 , V_23 -> V_91 ,
V_92 ) ;
F_216 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
if ( F_70 ( V_456 , & V_23 -> V_103 ) )
F_217 ( & V_429 , V_23 ) ;
if ( F_70 ( V_238 , & V_23 -> V_103 ) )
F_216 ( & V_429 , V_463 , 2 ,
V_23 -> V_91 ) ;
if ( V_23 -> V_13 -> V_308 & V_464 )
if ( V_23 -> V_87 == V_465 ||
F_70 ( V_466 , & V_23 -> V_85 ) ) {
V_23 -> V_87 = V_465 ;
F_216 ( & V_429 , V_467 , 1 ,
V_23 -> V_87 ) ;
}
break;
case V_148 :
F_226 ( V_23 ) ;
V_450 . V_141 = V_148 ;
V_450 . V_458 = 0 ;
V_450 . V_459 = 0 ;
V_450 . V_42 = 0 ;
V_450 . V_44 = 0 ;
V_54 = F_66 ( T_2 , V_462 , V_23 -> V_13 -> V_158 -
V_243 - V_395 -
V_248 ) ;
V_450 . V_460 = F_18 ( V_54 ) ;
F_216 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
if ( F_70 ( V_456 , & V_23 -> V_103 ) )
F_217 ( & V_429 , V_23 ) ;
if ( V_23 -> V_13 -> V_308 & V_464 )
if ( V_23 -> V_87 == V_465 ||
F_70 ( V_466 , & V_23 -> V_85 ) ) {
V_23 -> V_87 = V_465 ;
F_216 ( & V_429 , V_467 , 1 ,
V_23 -> V_87 ) ;
}
break;
}
V_272 -> V_16 = F_18 ( V_23 -> V_16 ) ;
V_272 -> V_103 = F_18 ( 0 ) ;
return V_429 - V_188 ;
}
static int F_227 ( struct V_11 * V_23 , void * V_188 )
{
struct V_468 * V_152 = V_188 ;
void * V_429 = V_152 -> V_188 ;
void * V_272 = V_23 -> V_469 ;
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
V_187 -= F_215 ( & V_272 , & type , & V_430 , & V_431 ) ;
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
if ( ! ( V_23 -> V_13 -> V_262 & V_263 ) )
return - V_70 ;
F_57 ( V_238 , & V_23 -> V_103 ) ;
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
if ( V_23 -> V_455 || V_23 -> V_328 > 1 )
goto V_27;
switch ( V_23 -> V_141 ) {
case V_148 :
case V_144 :
if ( ! F_70 ( V_318 , & V_23 -> V_85 ) ) {
V_23 -> V_141 = F_221 ( V_450 . V_141 ,
V_23 -> V_13 -> V_308 ) ;
break;
}
if ( V_472 ) {
if ( F_223 ( V_23 -> V_13 ) )
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
F_216 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
}
if ( V_153 == V_473 ) {
if ( V_158 < V_481 )
V_153 = V_480 ;
else {
V_23 -> V_30 = V_158 ;
F_57 ( V_482 , & V_23 -> V_85 ) ;
}
F_216 ( & V_429 , V_457 , 2 , V_23 -> V_30 ) ;
if ( V_472 ) {
if ( V_23 -> V_123 != V_483 &&
V_436 . V_437 != V_483 &&
V_436 . V_437 != V_23 -> V_123 ) {
V_153 = V_480 ;
if ( V_23 -> V_328 >= 1 )
return - V_70 ;
F_216 ( & V_429 , V_441 ,
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
V_54 = F_66 ( T_2 , F_228 ( V_450 . V_460 ) ,
V_23 -> V_13 -> V_158 - V_243 -
V_395 - V_248 ) ;
V_450 . V_460 = F_18 ( V_54 ) ;
V_23 -> V_399 = V_54 ;
F_224 ( V_23 , & V_450 ) ;
F_57 ( V_486 , & V_23 -> V_85 ) ;
F_216 ( & V_429 , V_461 ,
sizeof( V_450 ) , ( unsigned long ) & V_450 ) ;
if ( F_70 ( V_456 , & V_23 -> V_103 ) ) {
V_23 -> V_487 = V_436 . V_183 ;
V_23 -> V_488 = V_436 . V_437 ;
V_23 -> V_489 = F_228 ( V_436 . V_438 ) ;
V_23 -> V_490 =
F_229 ( V_436 . V_98 ) ;
V_23 -> V_491 =
F_229 ( V_436 . V_440 ) ;
V_23 -> V_492 =
F_229 ( V_436 . V_439 ) ;
F_216 ( & V_429 , V_441 ,
sizeof( V_436 ) ,
( unsigned long ) & V_436 ) ;
}
break;
case V_148 :
V_54 = F_66 ( T_2 , F_228 ( V_450 . V_460 ) ,
V_23 -> V_13 -> V_158 - V_243 -
V_395 - V_248 ) ;
V_450 . V_460 = F_18 ( V_54 ) ;
V_23 -> V_399 = V_54 ;
F_57 ( V_486 , & V_23 -> V_85 ) ;
F_216 ( & V_429 , V_461 , sizeof( V_450 ) ,
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
static int F_230 ( struct V_11 * V_23 , void * V_152 , int V_187 ,
void * V_188 , T_2 * V_153 )
{
struct V_454 * V_272 = V_188 ;
void * V_429 = V_272 -> V_188 ;
int type , V_430 ;
unsigned long V_431 ;
struct V_449 V_450 = { . V_141 = V_142 } ;
struct V_435 V_436 ;
F_23 ( L_40 , V_23 , V_152 , V_187 , V_188 ) ;
while ( V_187 >= V_434 ) {
V_187 -= F_215 ( & V_152 , & type , & V_430 , & V_431 ) ;
switch ( type ) {
case V_457 :
if ( V_431 < V_481 ) {
* V_153 = V_480 ;
V_23 -> V_111 = V_481 ;
} else
V_23 -> V_111 = V_431 ;
F_216 ( & V_429 , V_457 , 2 , V_23 -> V_111 ) ;
break;
case V_476 :
V_23 -> V_98 = V_431 ;
F_216 ( & V_429 , V_476 ,
2 , V_23 -> V_98 ) ;
break;
case V_461 :
if ( V_430 == sizeof( V_450 ) )
memcpy ( & V_450 , ( void * ) V_431 , V_430 ) ;
if ( F_70 ( V_318 , & V_23 -> V_85 ) &&
V_450 . V_141 != V_23 -> V_141 )
return - V_70 ;
V_23 -> V_87 = 0 ;
F_216 ( & V_429 , V_461 ,
sizeof( V_450 ) , ( unsigned long ) & V_450 ) ;
break;
case V_463 :
V_23 -> V_96 = F_66 ( T_2 , V_431 , V_23 -> V_96 ) ;
F_216 ( & V_429 , V_463 , 2 ,
V_23 -> V_91 ) ;
break;
case V_441 :
if ( V_430 == sizeof( V_436 ) )
memcpy ( & V_436 , ( void * ) V_431 , V_430 ) ;
if ( V_23 -> V_123 != V_483 &&
V_436 . V_437 != V_483 &&
V_436 . V_437 != V_23 -> V_123 )
return - V_70 ;
F_216 ( & V_429 , V_441 , sizeof( V_436 ) ,
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
V_23 -> V_42 = F_228 ( V_450 . V_42 ) ;
V_23 -> V_44 = F_228 ( V_450 . V_44 ) ;
V_23 -> V_110 = F_228 ( V_450 . V_460 ) ;
if ( ! F_70 ( V_238 , & V_23 -> V_103 ) )
V_23 -> V_96 = F_66 ( T_2 , V_23 -> V_96 ,
V_450 . V_458 ) ;
if ( F_70 ( V_456 , & V_23 -> V_103 ) ) {
V_23 -> V_125 = F_228 ( V_436 . V_438 ) ;
V_23 -> V_127 =
F_229 ( V_436 . V_439 ) ;
V_23 -> V_129 = F_229 ( V_436 . V_440 ) ;
V_23 -> V_131 =
F_229 ( V_436 . V_98 ) ;
}
break;
case V_148 :
V_23 -> V_110 = F_228 ( V_450 . V_460 ) ;
}
}
V_272 -> V_16 = F_18 ( V_23 -> V_16 ) ;
V_272 -> V_103 = F_18 ( 0 ) ;
return V_429 - V_188 ;
}
static int F_231 ( struct V_11 * V_23 , void * V_188 ,
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
void F_232 ( struct V_11 * V_23 )
{
struct V_151 V_152 ;
struct V_12 * V_13 = V_23 -> V_13 ;
F_23 ( L_3 , V_23 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_152 . V_158 = F_18 ( V_23 -> V_111 ) ;
V_152 . V_110 = F_18 ( V_23 -> V_110 ) ;
V_152 . V_159 = F_18 ( V_23 -> V_108 ) ;
V_152 . V_153 = F_18 ( V_324 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_160 , sizeof( V_152 ) ,
& V_152 ) ;
}
void F_233 ( struct V_11 * V_23 )
{
struct V_161 V_152 ;
struct V_12 * V_13 = V_23 -> V_13 ;
T_1 V_320 [ 128 ] ;
T_1 V_494 ;
V_152 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_152 . V_153 = F_18 ( V_324 ) ;
V_152 . V_163 = F_18 ( V_164 ) ;
if ( V_23 -> V_200 )
V_494 = V_495 ;
else
V_494 = V_165 ;
F_23 ( L_41 , V_23 , V_494 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_494 , sizeof( V_152 ) , & V_152 ) ;
if ( F_132 ( V_326 , & V_23 -> V_85 ) )
return;
F_83 ( V_13 , F_91 ( V_13 ) , V_327 ,
F_142 ( V_23 , V_320 ) , V_320 ) ;
V_23 -> V_328 ++ ;
}
static void F_234 ( struct V_11 * V_23 , void * V_152 , int V_187 )
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
V_187 -= F_215 ( & V_152 , & type , & V_430 , & V_431 ) ;
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
V_23 -> V_42 = F_228 ( V_450 . V_42 ) ;
V_23 -> V_44 = F_228 ( V_450 . V_44 ) ;
V_23 -> V_110 = F_228 ( V_450 . V_460 ) ;
if ( F_70 ( V_238 , & V_23 -> V_103 ) )
V_23 -> V_96 = F_66 ( T_2 , V_23 -> V_96 , V_496 ) ;
else
V_23 -> V_96 = F_66 ( T_2 , V_23 -> V_96 ,
V_450 . V_458 ) ;
break;
case V_148 :
V_23 -> V_110 = F_228 ( V_450 . V_460 ) ;
}
}
static inline int F_235 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_498 * V_499 = (struct V_498 * ) V_188 ;
if ( V_497 < sizeof( * V_499 ) )
return - V_500 ;
if ( V_499 -> V_67 != V_501 )
return 0 ;
if ( ( V_13 -> V_300 & V_301 ) &&
V_425 -> V_19 == V_13 -> V_303 ) {
F_236 ( & V_13 -> V_304 ) ;
V_13 -> V_300 |= V_307 ;
V_13 -> V_303 = 0 ;
F_140 ( V_13 ) ;
}
return 0 ;
}
static struct V_11 * F_237 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_1 * V_188 , T_1 V_494 , T_1 V_274 )
{
struct V_271 * V_272 = (struct V_271 * ) V_188 ;
struct V_161 V_152 ;
struct V_11 * V_23 = NULL , * V_502 ;
int V_153 , V_163 = V_164 ;
T_2 V_16 = 0 , V_17 = F_69 ( V_272 -> V_17 ) ;
T_3 V_20 = V_272 -> V_20 ;
F_23 ( L_43 , F_69 ( V_20 ) , V_17 ) ;
V_502 = F_164 ( V_166 , V_20 , & V_13 -> V_8 -> V_21 ,
& V_13 -> V_8 -> V_150 , V_117 ) ;
if ( ! V_502 ) {
V_153 = V_156 ;
goto V_503;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_502 ) ;
if ( V_20 != F_18 ( V_178 ) &&
! F_238 ( V_13 -> V_8 ) ) {
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
V_13 -> V_8 -> V_361 = V_508 ;
F_81 ( & V_23 -> V_21 , & V_13 -> V_8 -> V_21 ) ;
F_81 ( & V_23 -> V_150 , & V_13 -> V_8 -> V_150 ) ;
V_23 -> V_9 = F_2 ( V_13 -> V_8 ) ;
V_23 -> V_10 = F_3 ( V_13 -> V_8 ) ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_17 ;
V_23 -> V_443 = V_274 ;
F_68 ( V_13 , V_23 ) ;
V_16 = V_23 -> V_17 ;
F_85 ( V_23 , V_23 -> V_39 -> V_167 ( V_23 ) ) ;
V_23 -> V_19 = V_425 -> V_19 ;
if ( V_13 -> V_300 & V_307 ) {
if ( F_88 ( V_23 , false ) ) {
if ( F_70 ( V_154 , & V_23 -> V_103 ) ) {
F_22 ( V_23 , V_168 ) ;
V_153 = V_321 ;
V_163 = V_322 ;
V_23 -> V_39 -> V_323 ( V_23 ) ;
} else {
if ( V_274 == V_444 ) {
F_22 ( V_23 , V_69 ) ;
V_153 = V_324 ;
} else {
F_22 ( V_23 , V_168 ) ;
V_153 = V_321 ;
}
V_163 = V_164 ;
}
} else {
F_22 ( V_23 , V_168 ) ;
V_153 = V_321 ;
V_163 = V_325 ;
}
} else {
F_22 ( V_23 , V_168 ) ;
V_153 = V_321 ;
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
if ( V_153 == V_321 && V_163 == V_164 ) {
struct V_299 V_509 ;
V_509 . type = F_18 ( V_302 ) ;
V_13 -> V_300 |= V_301 ;
V_13 -> V_303 = F_91 ( V_13 ) ;
F_137 ( & V_13 -> V_304 , V_305 ) ;
F_83 ( V_13 , V_13 -> V_303 , V_306 ,
sizeof( V_509 ) , & V_509 ) ;
}
if ( V_23 && ! F_70 ( V_326 , & V_23 -> V_85 ) &&
V_153 == V_324 ) {
T_1 V_320 [ 128 ] ;
F_57 ( V_326 , & V_23 -> V_85 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_327 ,
F_142 ( V_23 , V_320 ) , V_320 ) ;
V_23 -> V_328 ++ ;
}
return V_23 ;
}
static int F_239 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 , T_1 * V_188 )
{
struct V_260 * V_189 = V_13 -> V_8 -> V_189 ;
struct V_7 * V_8 = V_13 -> V_8 ;
if ( V_497 < sizeof( struct V_271 ) )
return - V_500 ;
F_149 ( V_189 ) ;
if ( F_70 ( V_510 , & V_189 -> V_511 ) &&
! F_132 ( V_512 , & V_8 -> V_103 ) )
F_240 ( V_189 , V_8 , 0 , NULL , 0 ) ;
F_150 ( V_189 ) ;
F_237 ( V_13 , V_425 , V_188 , V_165 , 0 ) ;
return 0 ;
}
static int F_241 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_161 * V_152 = (struct V_161 * ) V_188 ;
T_2 V_17 , V_16 , V_153 , V_163 ;
struct V_11 * V_23 ;
T_1 V_272 [ 128 ] ;
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
V_24 = - V_513 ;
goto V_514;
}
} else {
V_23 = F_12 ( V_13 , V_425 -> V_19 ) ;
if ( ! V_23 ) {
V_24 = - V_513 ;
goto V_514;
}
}
V_24 = 0 ;
F_9 ( V_23 ) ;
switch ( V_153 ) {
case V_324 :
F_22 ( V_23 , V_69 ) ;
V_23 -> V_19 = 0 ;
V_23 -> V_16 = V_16 ;
F_117 ( V_259 , & V_23 -> V_85 ) ;
if ( F_132 ( V_326 , & V_23 -> V_85 ) )
break;
F_83 ( V_13 , F_91 ( V_13 ) , V_327 ,
F_142 ( V_23 , V_272 ) , V_272 ) ;
V_23 -> V_328 ++ ;
break;
case V_321 :
F_57 ( V_259 , & V_23 -> V_85 ) ;
break;
default:
F_73 ( V_23 , V_70 ) ;
break;
}
F_48 ( V_23 ) ;
V_514:
F_10 ( & V_13 -> V_18 ) ;
return V_24 ;
}
static inline void F_242 ( struct V_11 * V_23 )
{
if ( V_23 -> V_141 != V_144 && V_23 -> V_141 != V_148 )
V_23 -> V_87 = V_465 ;
else if ( ! F_70 ( V_466 , & V_23 -> V_85 ) )
V_23 -> V_87 = V_88 ;
}
static void F_243 ( struct V_11 * V_23 , void * V_188 ,
T_1 V_19 , T_2 V_103 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
F_23 ( L_45 , V_13 , V_23 , V_19 ,
V_103 ) ;
F_117 ( V_485 , & V_23 -> V_85 ) ;
F_57 ( V_493 , & V_23 -> V_85 ) ;
F_83 ( V_13 , V_19 , V_515 ,
F_231 ( V_23 , V_188 ,
V_473 , V_103 ) , V_188 ) ;
}
static void F_244 ( struct V_12 * V_13 , T_1 V_19 ,
T_2 V_17 , T_2 V_16 )
{
struct V_516 V_499 ;
V_499 . V_67 = F_18 ( V_517 ) ;
V_499 . V_17 = F_245 ( V_17 ) ;
V_499 . V_16 = F_245 ( V_16 ) ;
F_83 ( V_13 , V_19 , V_518 , sizeof( V_499 ) , & V_499 ) ;
}
static inline int F_246 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_454 * V_272 = (struct V_454 * ) V_188 ;
T_2 V_16 , V_103 ;
T_1 V_152 [ 64 ] ;
struct V_11 * V_23 ;
int V_187 , V_24 = 0 ;
if ( V_497 < sizeof( * V_272 ) )
return - V_500 ;
V_16 = F_69 ( V_272 -> V_16 ) ;
V_103 = F_69 ( V_272 -> V_103 ) ;
F_23 ( L_46 , V_16 , V_103 ) ;
V_23 = F_7 ( V_13 , V_16 ) ;
if ( ! V_23 ) {
F_244 ( V_13 , V_425 -> V_19 , V_16 , 0 ) ;
return 0 ;
}
if ( V_23 -> V_38 != V_69 && V_23 -> V_38 != V_168 ) {
F_244 ( V_13 , V_425 -> V_19 , V_23 -> V_17 ,
V_23 -> V_16 ) ;
goto V_514;
}
V_187 = V_497 - sizeof( * V_272 ) ;
if ( V_23 -> V_470 + V_187 > sizeof( V_23 -> V_469 ) ) {
F_83 ( V_13 , V_425 -> V_19 , V_515 ,
F_231 ( V_23 , V_152 ,
V_519 , V_103 ) , V_152 ) ;
goto V_514;
}
memcpy ( V_23 -> V_469 + V_23 -> V_470 , V_272 -> V_188 , V_187 ) ;
V_23 -> V_470 += V_187 ;
if ( V_103 & V_520 ) {
F_83 ( V_13 , V_425 -> V_19 , V_515 ,
F_231 ( V_23 , V_152 ,
V_473 , V_103 ) , V_152 ) ;
goto V_514;
}
V_187 = F_227 ( V_23 , V_152 ) ;
if ( V_187 < 0 ) {
F_86 ( V_23 , V_319 ) ;
goto V_514;
}
V_23 -> V_19 = V_425 -> V_19 ;
F_83 ( V_13 , V_425 -> V_19 , V_515 , V_187 , V_152 ) ;
V_23 -> V_455 ++ ;
V_23 -> V_470 = 0 ;
if ( ! F_70 ( V_493 , & V_23 -> V_85 ) )
goto V_514;
if ( F_70 ( V_521 , & V_23 -> V_85 ) ) {
F_242 ( V_23 ) ;
if ( V_23 -> V_141 == V_144 ||
V_23 -> V_141 == V_148 )
V_24 = F_220 ( V_23 ) ;
if ( V_24 < 0 )
F_86 ( V_23 , - V_24 ) ;
else
F_130 ( V_23 ) ;
goto V_514;
}
if ( ! F_132 ( V_326 , & V_23 -> V_85 ) ) {
T_1 V_320 [ 64 ] ;
F_83 ( V_13 , F_91 ( V_13 ) , V_327 ,
F_142 ( V_23 , V_320 ) , V_320 ) ;
V_23 -> V_328 ++ ;
}
if ( F_70 ( V_522 , & V_23 -> V_85 ) &&
F_70 ( V_485 , & V_23 -> V_85 ) ) {
if ( ! V_23 -> V_200 )
F_243 ( V_23 , V_152 , V_425 -> V_19 , V_103 ) ;
else
V_23 -> V_19 = V_425 -> V_19 ;
}
V_514:
F_48 ( V_23 ) ;
return V_24 ;
}
static inline int F_247 ( struct V_12 * V_13 ,
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
F_234 ( V_23 , V_152 -> V_188 , V_187 ) ;
F_117 ( V_522 , & V_23 -> V_85 ) ;
break;
case V_484 :
F_57 ( V_522 , & V_23 -> V_85 ) ;
if ( F_70 ( V_485 , & V_23 -> V_85 ) ) {
char V_320 [ 64 ] ;
V_187 = F_230 ( V_23 , V_152 -> V_188 , V_187 ,
V_320 , & V_153 ) ;
if ( V_187 < 0 ) {
F_86 ( V_23 , V_319 ) ;
goto V_27;
}
if ( ! V_23 -> V_200 ) {
F_243 ( V_23 , V_320 , V_425 -> V_19 ,
0 ) ;
} else {
if ( F_124 ( V_23 ) ) {
F_248 ( V_23 ) ;
V_23 -> V_19 = V_425 -> V_19 ;
}
}
}
goto V_27;
case V_480 :
if ( V_23 -> V_455 <= V_523 ) {
char V_272 [ 64 ] ;
if ( V_187 > sizeof( V_272 ) - sizeof( struct V_454 ) ) {
F_86 ( V_23 , V_319 ) ;
goto V_27;
}
V_153 = V_473 ;
V_187 = F_230 ( V_23 , V_152 -> V_188 , V_187 ,
V_272 , & V_153 ) ;
if ( V_187 < 0 ) {
F_86 ( V_23 , V_319 ) ;
goto V_27;
}
F_83 ( V_13 , F_91 ( V_13 ) ,
V_327 , V_187 , V_272 ) ;
V_23 -> V_328 ++ ;
if ( V_153 != V_473 )
goto V_27;
break;
}
default:
F_26 ( V_23 , V_319 ) ;
F_85 ( V_23 , V_524 ) ;
F_86 ( V_23 , V_319 ) ;
goto V_27;
}
if ( V_103 & V_520 )
goto V_27;
F_57 ( V_521 , & V_23 -> V_85 ) ;
if ( F_70 ( V_493 , & V_23 -> V_85 ) ) {
F_242 ( V_23 ) ;
if ( V_23 -> V_141 == V_144 ||
V_23 -> V_141 == V_148 )
V_24 = F_220 ( V_23 ) ;
if ( V_24 < 0 )
F_86 ( V_23 , - V_24 ) ;
else
F_130 ( V_23 ) ;
}
V_27:
F_48 ( V_23 ) ;
return V_24 ;
}
static inline int F_249 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_314 * V_272 = (struct V_314 * ) V_188 ;
struct V_525 V_152 ;
T_2 V_16 , V_17 ;
struct V_11 * V_23 ;
if ( V_497 != sizeof( * V_272 ) )
return - V_500 ;
V_17 = F_69 ( V_272 -> V_17 ) ;
V_16 = F_69 ( V_272 -> V_16 ) ;
F_23 ( L_48 , V_17 , V_16 ) ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_6 ( V_13 , V_16 ) ;
if ( ! V_23 ) {
F_10 ( & V_13 -> V_18 ) ;
F_244 ( V_13 , V_425 -> V_19 , V_16 , V_17 ) ;
return 0 ;
}
F_9 ( V_23 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_152 . V_17 = F_18 ( V_23 -> V_16 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_526 , sizeof( V_152 ) , & V_152 ) ;
V_23 -> V_39 -> V_527 ( V_23 ) ;
F_60 ( V_23 ) ;
F_73 ( V_23 , V_319 ) ;
F_48 ( V_23 ) ;
V_23 -> V_39 -> V_75 ( V_23 ) ;
F_49 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
return 0 ;
}
static inline int F_250 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_525 * V_152 = (struct V_525 * ) V_188 ;
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
static inline int F_251 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_299 * V_272 = (struct V_299 * ) V_188 ;
T_2 type ;
if ( V_497 != sizeof( * V_272 ) )
return - V_500 ;
type = F_69 ( V_272 -> type ) ;
F_23 ( L_50 , type ) ;
if ( type == V_302 ) {
T_1 V_320 [ 8 ] ;
T_8 V_308 = V_310 ;
struct V_528 * V_152 = (struct V_528 * ) V_320 ;
V_152 -> type = F_18 ( V_302 ) ;
V_152 -> V_153 = F_18 ( V_529 ) ;
if ( ! V_311 )
V_308 |= V_312 | V_313
| V_464 ;
if ( V_13 -> V_262 & V_263 )
V_308 |= V_448
| V_447 ;
F_107 ( V_308 , V_152 -> V_188 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_530 , sizeof( V_320 ) ,
V_320 ) ;
} else if ( type == V_531 ) {
T_1 V_320 [ 12 ] ;
struct V_528 * V_152 = (struct V_528 * ) V_320 ;
V_152 -> type = F_18 ( V_531 ) ;
V_152 -> V_153 = F_18 ( V_529 ) ;
V_152 -> V_188 [ 0 ] = V_13 -> V_262 ;
memset ( V_152 -> V_188 + 1 , 0 , 7 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_530 , sizeof( V_320 ) ,
V_320 ) ;
} else {
struct V_528 V_152 ;
V_152 . type = F_18 ( type ) ;
V_152 . V_153 = F_18 ( V_532 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_530 , sizeof( V_152 ) ,
& V_152 ) ;
}
return 0 ;
}
static inline int F_252 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_528 * V_152 = (struct V_528 * ) V_188 ;
T_2 type , V_153 ;
if ( V_497 < sizeof( * V_152 ) )
return - V_500 ;
type = F_69 ( V_152 -> type ) ;
V_153 = F_69 ( V_152 -> V_153 ) ;
F_23 ( L_51 , type , V_153 ) ;
if ( V_425 -> V_19 != V_13 -> V_303 ||
V_13 -> V_300 & V_307 )
return 0 ;
F_236 ( & V_13 -> V_304 ) ;
if ( V_153 != V_529 ) {
V_13 -> V_300 |= V_307 ;
V_13 -> V_303 = 0 ;
F_140 ( V_13 ) ;
return 0 ;
}
switch ( type ) {
case V_302 :
V_13 -> V_308 = F_101 ( V_152 -> V_188 ) ;
if ( V_13 -> V_308 & V_533 ) {
struct V_299 V_272 ;
V_272 . type = F_18 ( V_531 ) ;
V_13 -> V_303 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_13 -> V_303 ,
V_306 , sizeof( V_272 ) , & V_272 ) ;
} else {
V_13 -> V_300 |= V_307 ;
V_13 -> V_303 = 0 ;
F_140 ( V_13 ) ;
}
break;
case V_531 :
V_13 -> V_264 = V_152 -> V_188 [ 0 ] ;
V_13 -> V_300 |= V_307 ;
V_13 -> V_303 = 0 ;
F_140 ( V_13 ) ;
break;
}
return 0 ;
}
static int F_253 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_188 )
{
struct V_275 * V_272 = V_188 ;
struct V_534 V_152 ;
struct V_11 * V_23 ;
struct V_260 * V_189 ;
T_2 V_20 , V_17 ;
if ( V_497 != sizeof( * V_272 ) )
return - V_500 ;
if ( ! ( V_13 -> V_262 & V_263 ) )
return - V_29 ;
V_20 = F_228 ( V_272 -> V_20 ) ;
V_17 = F_228 ( V_272 -> V_17 ) ;
F_23 ( L_52 , V_20 , V_17 , V_272 -> V_274 ) ;
if ( V_272 -> V_274 == V_444 ) {
F_237 ( V_13 , V_425 , V_188 , V_495 ,
V_272 -> V_274 ) ;
return 0 ;
}
V_189 = F_254 ( V_272 -> V_274 ) ;
if ( ! V_189 )
goto error;
if ( V_189 -> V_535 != V_536 || ! F_70 ( V_268 , & V_189 -> V_103 ) ) {
F_255 ( V_189 ) ;
goto error;
}
V_23 = F_237 ( V_13 , V_425 , V_188 , V_495 ,
V_272 -> V_274 ) ;
if ( V_23 ) {
struct V_136 * V_137 = V_13 -> V_8 -> V_136 ;
struct V_7 * V_200 ;
V_200 = F_256 ( V_189 , V_537 ,
& V_13 -> V_8 -> V_150 ) ;
if ( ! V_200 ) {
F_255 ( V_189 ) ;
F_244 ( V_13 , V_425 -> V_19 , V_23 -> V_17 ,
V_23 -> V_16 ) ;
return 0 ;
}
F_23 ( L_53 , V_137 , V_23 , V_200 ) ;
V_137 -> V_138 = V_23 ;
V_23 -> V_200 = V_200 ;
V_23 -> V_87 = V_465 ;
V_13 -> V_158 = V_189 -> V_538 ;
}
F_255 ( V_189 ) ;
return 0 ;
error:
V_152 . V_16 = 0 ;
V_152 . V_17 = F_18 ( V_17 ) ;
V_152 . V_153 = F_18 ( V_539 ) ;
V_152 . V_163 = F_18 ( V_164 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_495 ,
sizeof( V_152 ) , & V_152 ) ;
return 0 ;
}
static void F_257 ( struct V_11 * V_23 , T_1 V_540 )
{
struct V_541 V_272 ;
T_1 V_19 ;
F_23 ( L_54 , V_23 , V_540 ) ;
V_19 = F_91 ( V_23 -> V_13 ) ;
V_23 -> V_19 = V_19 ;
V_272 . V_542 = F_18 ( V_23 -> V_17 ) ;
V_272 . V_540 = V_540 ;
F_83 ( V_23 -> V_13 , V_19 , V_543 , sizeof( V_272 ) ,
& V_272 ) ;
F_85 ( V_23 , V_544 ) ;
}
static void F_258 ( struct V_11 * V_23 , T_2 V_153 )
{
struct V_545 V_152 ;
F_23 ( L_55 , V_23 , V_153 ) ;
V_152 . V_542 = F_18 ( V_23 -> V_16 ) ;
V_152 . V_153 = F_18 ( V_153 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_546 ,
sizeof( V_152 ) , & V_152 ) ;
}
static void F_259 ( struct V_11 * V_23 , T_2 V_153 )
{
struct V_547 V_548 ;
F_23 ( L_55 , V_23 , V_153 ) ;
V_23 -> V_19 = F_91 ( V_23 -> V_13 ) ;
V_548 . V_542 = F_18 ( V_23 -> V_17 ) ;
V_548 . V_153 = F_18 ( V_153 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_549 ,
sizeof( V_548 ) , & V_548 ) ;
F_85 ( V_23 , V_544 ) ;
}
static void F_260 ( struct V_12 * V_13 , T_2 V_542 )
{
struct V_547 V_548 ;
F_23 ( L_56 , V_13 , V_542 ) ;
V_548 . V_542 = F_18 ( V_542 ) ;
V_548 . V_153 = F_18 ( V_550 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_549 ,
sizeof( V_548 ) , & V_548 ) ;
}
static void F_261 ( struct V_12 * V_13 , T_1 V_19 ,
T_2 V_542 )
{
struct V_551 V_152 ;
F_23 ( L_57 , V_542 ) ;
V_152 . V_542 = F_18 ( V_542 ) ;
F_83 ( V_13 , V_19 , V_552 , sizeof( V_152 ) , & V_152 ) ;
}
static void F_262 ( struct V_11 * V_23 )
{
V_23 -> V_139 = NULL ;
V_23 -> V_200 = NULL ;
}
static void F_263 ( struct V_11 * V_23 )
{
if ( V_23 -> V_38 != V_68 ) {
F_86 ( V_23 , V_319 ) ;
return;
}
switch ( V_23 -> V_287 ) {
case V_292 :
F_128 ( V_23 ) ;
F_258 ( V_23 , V_553 ) ;
break;
case V_289 :
if ( V_23 -> V_197 == V_554 ||
V_23 -> V_197 == V_555 ) {
F_128 ( V_23 ) ;
}
F_259 ( V_23 , V_550 ) ;
break;
}
}
static void F_264 ( struct V_11 * V_23 ,
struct V_140 * V_196 )
{
struct V_468 V_152 ;
V_23 -> V_139 = V_196 ;
V_23 -> V_200 -> V_357 = V_23 -> V_13 ;
F_243 ( V_23 , & V_152 , V_23 -> V_19 , 0 ) ;
if ( F_70 ( V_521 , & V_23 -> V_85 ) ) {
int V_24 ;
F_242 ( V_23 ) ;
V_24 = F_220 ( V_23 ) ;
if ( V_24 < 0 )
F_86 ( V_23 , - V_24 ) ;
else
F_130 ( V_23 ) ;
}
}
static void F_265 ( struct V_11 * V_23 ,
struct V_140 * V_196 )
{
V_23 -> V_200 = V_196 -> V_13 ;
V_23 -> V_200 -> V_357 = V_23 -> V_13 ;
F_23 ( L_58 , V_23 -> V_197 ) ;
switch ( V_23 -> V_197 ) {
case V_554 :
V_23 -> V_197 = V_556 ;
break;
case V_555 :
if ( F_70 ( V_257 , & V_23 -> V_251 ) ) {
V_23 -> V_197 = V_557 ;
} else if ( V_23 -> V_287 == V_289 ) {
V_23 -> V_197 = V_558 ;
F_259 ( V_23 , V_559 ) ;
} else if ( V_23 -> V_287 == V_292 ) {
V_23 -> V_197 = V_560 ;
F_258 ( V_23 , V_561 ) ;
}
break;
default:
F_262 ( V_23 ) ;
V_23 -> V_197 = V_198 ;
}
}
void F_266 ( struct V_11 * V_23 , struct V_140 * V_196 ,
T_1 V_163 )
{
F_23 ( L_59 , V_23 , V_196 , V_163 ) ;
if ( V_163 ) {
F_263 ( V_23 ) ;
F_262 ( V_23 ) ;
return;
}
if ( V_23 -> V_38 != V_68 ) {
if ( V_23 -> V_443 != V_444 )
F_264 ( V_23 , V_196 ) ;
} else {
F_265 ( V_23 , V_196 ) ;
}
}
void F_267 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_443 == V_444 ) {
if ( V_23 -> V_269 != V_270 )
return;
V_23 -> V_287 = V_289 ;
V_23 -> V_197 = V_199 ;
} else {
V_23 -> V_287 = V_289 ;
V_23 -> V_197 = V_556 ;
V_23 -> V_445 = 0 ;
F_127 ( V_23 ) ;
F_257 ( V_23 , 0 ) ;
}
}
static void F_268 ( struct V_11 * V_23 , int V_153 ,
T_1 V_443 , T_1 V_562 )
{
F_23 ( L_60 , V_23 , F_24 ( V_23 -> V_38 ) ,
V_443 , V_562 ) ;
V_23 -> V_87 = V_465 ;
if ( V_23 -> V_38 == V_71 ) {
if ( V_153 == V_324 ) {
V_23 -> V_443 = V_443 ;
F_126 ( V_23 , V_562 ) ;
} else {
F_125 ( V_23 ) ;
}
return;
}
if ( F_120 ( V_23 ) ) {
struct V_161 V_152 ;
char V_320 [ 128 ] ;
V_152 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
if ( V_153 == V_324 ) {
V_152 . V_153 = F_18 ( V_324 ) ;
V_152 . V_163 = F_18 ( V_164 ) ;
} else {
V_152 . V_153 = F_18 ( V_506 ) ;
V_152 . V_163 = F_18 ( V_164 ) ;
}
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_495 ,
sizeof( V_152 ) , & V_152 ) ;
if ( V_153 == V_324 ) {
F_22 ( V_23 , V_69 ) ;
F_57 ( V_326 , & V_23 -> V_85 ) ;
F_83 ( V_23 -> V_13 , F_91 ( V_23 -> V_13 ) ,
V_327 ,
F_142 ( V_23 , V_320 ) , V_320 ) ;
V_23 -> V_328 ++ ;
}
}
}
static void F_269 ( struct V_11 * V_23 , T_1 V_443 ,
T_1 V_562 )
{
F_127 ( V_23 ) ;
V_23 -> V_445 = V_443 ;
V_23 -> V_197 = V_563 ;
F_257 ( V_23 , V_562 ) ;
}
static void F_270 ( struct V_11 * V_23 , int V_153 )
{
struct V_140 * V_196 = NULL ;
if ( V_196 ) {
if ( V_196 -> V_38 == V_68 ) {
V_23 -> V_200 = V_196 -> V_13 ;
V_23 -> V_200 -> V_357 = V_23 -> V_13 ;
V_23 -> V_197 = V_560 ;
F_258 ( V_23 , V_561 ) ;
F_266 ( V_23 , V_196 , V_561 ) ;
} else {
V_23 -> V_197 = V_555 ;
}
} else {
F_258 ( V_23 , V_564 ) ;
}
}
static void F_271 ( struct V_11 * V_23 , int V_153 )
{
if ( V_23 -> V_287 == V_292 ) {
T_1 V_565 ;
if ( V_153 == - V_29 )
V_565 = V_566 ;
else
V_565 = V_564 ;
F_258 ( V_23 , V_565 ) ;
}
V_23 -> V_287 = V_288 ;
V_23 -> V_197 = V_198 ;
F_172 ( V_23 ) ;
}
void F_272 ( struct V_11 * V_23 , int V_153 )
{
T_1 V_443 = V_23 -> V_443 ;
T_1 V_562 = V_23 -> V_562 ;
F_23 ( L_61 ,
V_23 , V_153 , V_443 , V_562 ) ;
if ( V_23 -> V_38 == V_157 || V_23 -> V_38 == V_567 ) {
F_48 ( V_23 ) ;
return;
}
if ( V_23 -> V_38 != V_68 ) {
F_268 ( V_23 , V_153 , V_443 , V_562 ) ;
} else if ( V_153 != V_561 ) {
F_271 ( V_23 , V_153 ) ;
} else {
switch ( V_23 -> V_287 ) {
case V_289 :
F_269 ( V_23 , V_443 ,
V_562 ) ;
break;
case V_292 :
F_270 ( V_23 , V_153 ) ;
break;
default:
F_271 ( V_23 , V_153 ) ;
break;
}
}
}
static inline int F_273 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_188 )
{
struct V_541 * V_272 = V_188 ;
struct V_545 V_152 ;
struct V_11 * V_23 ;
T_2 V_542 = 0 ;
T_2 V_153 = V_564 ;
if ( V_497 != sizeof( * V_272 ) )
return - V_500 ;
V_542 = F_228 ( V_272 -> V_542 ) ;
F_23 ( L_62 , V_542 , V_272 -> V_540 ) ;
if ( ! ( V_13 -> V_262 & V_263 ) )
return - V_29 ;
V_23 = F_11 ( V_13 , V_542 ) ;
if ( ! V_23 ) {
V_152 . V_542 = F_18 ( V_542 ) ;
V_152 . V_153 = F_18 ( V_564 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_546 ,
sizeof( V_152 ) , & V_152 ) ;
return 0 ;
}
V_23 -> V_19 = V_425 -> V_19 ;
if ( V_23 -> V_17 < V_37 ||
V_23 -> V_269 == V_568 ||
( V_23 -> V_141 != V_144 &&
V_23 -> V_141 != V_148 ) ) {
V_153 = V_564 ;
goto V_569;
}
if ( V_23 -> V_443 == V_272 -> V_540 ) {
V_153 = V_570 ;
goto V_569;
}
if ( V_272 -> V_540 != V_444 ) {
struct V_260 * V_189 ;
V_189 = F_254 ( V_272 -> V_540 ) ;
if ( ! V_189 || V_189 -> V_535 != V_536 ||
! F_70 ( V_268 , & V_189 -> V_103 ) ) {
if ( V_189 )
F_255 ( V_189 ) ;
V_153 = V_566 ;
goto V_569;
}
F_255 ( V_189 ) ;
}
if ( ( F_95 ( V_23 ) ||
V_23 -> V_287 != V_288 ) &&
F_15 ( & V_13 -> V_8 -> V_21 , & V_13 -> V_8 -> V_150 ) > 0 ) {
V_153 = V_571 ;
goto V_569;
}
V_23 -> V_287 = V_292 ;
F_127 ( V_23 ) ;
V_23 -> V_445 = V_272 -> V_540 ;
V_542 = V_23 -> V_16 ;
if ( V_272 -> V_540 == V_444 ) {
if ( F_70 ( V_257 , & V_23 -> V_251 ) ) {
V_23 -> V_197 = V_557 ;
V_153 = V_572 ;
} else {
V_23 -> V_197 = V_560 ;
V_153 = V_561 ;
}
} else {
V_23 -> V_197 = V_199 ;
V_153 = V_572 ;
}
V_569:
F_258 ( V_23 , V_153 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static void F_274 ( struct V_12 * V_13 , T_2 V_542 , T_2 V_153 )
{
struct V_11 * V_23 ;
struct V_140 * V_196 = NULL ;
V_23 = F_7 ( V_13 , V_542 ) ;
if ( ! V_23 ) {
F_260 ( V_13 , V_542 ) ;
return;
}
F_74 ( V_23 ) ;
if ( V_153 == V_572 )
F_85 ( V_23 , V_573 ) ;
switch ( V_23 -> V_197 ) {
case V_554 :
V_23 -> V_197 = V_555 ;
break;
case V_556 :
if ( V_153 == V_572 ) {
break;
} else if ( F_70 ( V_257 ,
& V_23 -> V_251 ) ) {
V_23 -> V_197 = V_557 ;
} else {
V_23 -> V_197 = V_558 ;
F_259 ( V_23 , V_559 ) ;
}
break;
case V_563 :
if ( V_153 == V_561 ) {
V_23 -> V_197 = V_555 ;
} else {
V_23 -> V_197 = V_554 ;
}
if ( ! V_196 ) {
F_259 ( V_23 , V_550 ) ;
break;
}
if ( V_196 -> V_38 != V_68 )
break;
V_23 -> V_200 = V_196 -> V_13 ;
V_23 -> V_200 -> V_357 = V_23 -> V_13 ;
if ( V_153 == V_561 ) {
F_259 ( V_23 , V_559 ) ;
} else {
V_23 -> V_197 = V_556 ;
}
F_266 ( V_23 , V_196 , V_561 ) ;
break;
default:
V_23 -> V_445 = V_23 -> V_443 ;
F_128 ( V_23 ) ;
F_259 ( V_23 , V_550 ) ;
}
F_48 ( V_23 ) ;
}
static void F_275 ( struct V_12 * V_13 , T_1 V_19 , T_2 V_542 ,
T_2 V_153 )
{
struct V_11 * V_23 ;
V_23 = F_13 ( V_13 , V_19 ) ;
if ( ! V_23 ) {
F_260 ( V_13 , V_542 ) ;
return;
}
F_74 ( V_23 ) ;
if ( V_23 -> V_287 == V_289 ) {
if ( V_153 == V_571 ) {
V_23 -> V_287 = V_292 ;
} else {
V_23 -> V_445 = V_23 -> V_443 ;
F_128 ( V_23 ) ;
}
}
F_259 ( V_23 , V_550 ) ;
F_48 ( V_23 ) ;
}
static int F_276 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_188 )
{
struct V_545 * V_152 = V_188 ;
T_2 V_542 , V_153 ;
if ( V_497 != sizeof( * V_152 ) )
return - V_500 ;
V_542 = F_228 ( V_152 -> V_542 ) ;
V_153 = F_228 ( V_152 -> V_153 ) ;
F_23 ( L_63 , V_542 , V_153 ) ;
if ( V_153 == V_561 || V_153 == V_572 )
F_274 ( V_13 , V_542 , V_153 ) ;
else
F_275 ( V_13 , V_425 -> V_19 , V_542 , V_153 ) ;
return 0 ;
}
static int F_277 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_188 )
{
struct V_547 * V_548 = V_188 ;
struct V_11 * V_23 ;
T_2 V_542 , V_153 ;
if ( V_497 != sizeof( * V_548 ) )
return - V_500 ;
V_542 = F_228 ( V_548 -> V_542 ) ;
V_153 = F_228 ( V_548 -> V_153 ) ;
F_23 ( L_63 , V_542 , V_153 ) ;
V_23 = F_11 ( V_13 , V_542 ) ;
if ( ! V_23 ) {
F_261 ( V_13 , V_425 -> V_19 , V_542 ) ;
return 0 ;
}
if ( V_23 -> V_197 == V_560 ) {
if ( V_153 == V_559 ) {
V_23 -> V_443 = V_23 -> V_445 ;
if ( V_23 -> V_443 == V_444 )
F_262 ( V_23 ) ;
} else {
V_23 -> V_445 = V_23 -> V_443 ;
}
F_128 ( V_23 ) ;
}
F_261 ( V_13 , V_425 -> V_19 , V_542 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static inline int F_278 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_188 )
{
struct V_551 * V_152 = V_188 ;
struct V_11 * V_23 ;
T_2 V_542 ;
if ( V_497 != sizeof( * V_152 ) )
return - V_500 ;
V_542 = F_228 ( V_152 -> V_542 ) ;
F_23 ( L_57 , V_542 ) ;
V_23 = F_7 ( V_13 , V_542 ) ;
if ( ! V_23 )
return 0 ;
F_74 ( V_23 ) ;
if ( V_23 -> V_197 == V_558 ) {
V_23 -> V_443 = V_23 -> V_445 ;
if ( V_23 -> V_443 == V_444 && V_23 -> V_139 )
F_262 ( V_23 ) ;
F_128 ( V_23 ) ;
}
F_48 ( V_23 ) ;
return 0 ;
}
static inline int V_337 ( struct V_12 * V_13 ,
struct V_424 * V_425 ,
T_2 V_497 , T_1 * V_188 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_337 * V_272 ;
struct V_574 V_152 ;
T_2 V_338 , V_339 , V_340 , V_342 ;
int V_24 ;
if ( V_8 -> V_332 != V_575 )
return - V_29 ;
if ( V_497 != sizeof( struct V_337 ) )
return - V_500 ;
V_272 = (struct V_337 * ) V_188 ;
V_338 = F_69 ( V_272 -> V_338 ) ;
V_339 = F_69 ( V_272 -> V_339 ) ;
V_340 = F_69 ( V_272 -> V_340 ) ;
V_342 = F_69 ( V_272 -> V_342 ) ;
F_23 ( L_64 ,
V_338 , V_339 , V_340 , V_342 ) ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_24 = F_279 ( V_338 , V_339 , V_340 , V_342 ) ;
if ( V_24 )
V_152 . V_153 = F_18 ( V_576 ) ;
else
V_152 . V_153 = F_18 ( V_577 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_578 ,
sizeof( V_152 ) , & V_152 ) ;
if ( ! V_24 ) {
T_1 V_579 ;
V_579 = F_280 ( V_8 , V_338 , V_339 , V_340 ,
V_342 ) ;
F_281 ( V_8 -> V_189 , & V_8 -> V_150 , V_8 -> V_10 ,
V_579 , V_338 , V_339 , V_340 ,
V_342 ) ;
}
return 0 ;
}
static int F_282 ( struct V_12 * V_13 ,
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
if ( V_153 == V_324 && ( V_158 < 23 || V_110 < 23 ) )
return - V_500 ;
F_23 ( L_65 ,
V_16 , V_158 , V_110 , V_159 , V_153 ) ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_12 ( V_13 , V_425 -> V_19 ) ;
if ( ! V_23 ) {
V_24 = - V_513 ;
goto V_514;
}
V_24 = 0 ;
F_9 ( V_23 ) ;
switch ( V_153 ) {
case V_324 :
V_23 -> V_19 = 0 ;
V_23 -> V_16 = V_16 ;
V_23 -> V_30 = V_158 ;
V_23 -> V_399 = V_110 ;
V_23 -> V_107 = V_159 ;
F_130 ( V_23 ) ;
break;
case V_580 :
case V_581 :
if ( V_8 -> V_72 > V_173 ) {
F_73 ( V_23 , V_70 ) ;
break;
}
V_72 = V_8 -> V_72 + 1 ;
if ( V_23 -> V_72 < V_72 )
V_23 -> V_72 = V_72 ;
F_117 ( V_297 , & V_23 -> V_103 ) ;
F_89 ( V_8 , V_23 -> V_72 ) ;
break;
default:
F_73 ( V_23 , V_70 ) ;
break;
}
F_48 ( V_23 ) ;
V_514:
F_10 ( & V_13 -> V_18 ) ;
return V_24 ;
}
static inline int F_283 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
int V_24 = 0 ;
switch ( V_425 -> V_186 ) {
case V_518 :
F_235 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_273 :
V_24 = F_239 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_165 :
case V_495 :
F_241 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_327 :
V_24 = F_246 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_515 :
F_247 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_316 :
V_24 = F_249 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_526 :
F_250 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_582 :
F_83 ( V_13 , V_425 -> V_19 , V_583 , V_497 , V_188 ) ;
break;
case V_583 :
break;
case V_306 :
V_24 = F_251 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_530 :
F_252 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_276 :
V_24 = F_253 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_543 :
V_24 = F_273 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_546 :
F_276 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_549 :
V_24 = F_277 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_552 :
F_278 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
default:
F_284 ( L_66 , V_425 -> V_186 ) ;
V_24 = - V_29 ;
break;
}
return V_24 ;
}
static int F_285 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct V_296 * V_272 = (struct V_296 * ) V_188 ;
struct V_151 V_152 ;
struct V_11 * V_23 , * V_502 ;
T_2 V_16 , V_17 , V_159 , V_158 , V_110 ;
T_3 V_20 ;
T_1 V_153 ;
if ( V_497 != sizeof( * V_272 ) )
return - V_500 ;
V_17 = F_69 ( V_272 -> V_17 ) ;
V_158 = F_69 ( V_272 -> V_158 ) ;
V_110 = F_69 ( V_272 -> V_110 ) ;
V_20 = V_272 -> V_20 ;
V_16 = 0 ;
V_159 = 0 ;
if ( V_158 < 23 || V_110 < 23 )
return - V_500 ;
F_23 ( L_67 , F_69 ( V_20 ) ,
V_17 , V_158 , V_110 ) ;
V_502 = F_164 ( V_166 , V_20 , & V_13 -> V_8 -> V_21 ,
& V_13 -> V_8 -> V_150 , V_2 ) ;
if ( ! V_502 ) {
V_153 = V_156 ;
V_23 = NULL ;
goto V_505;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_502 ) ;
if ( ! F_286 ( V_13 -> V_8 , V_502 -> V_72 ,
V_584 ) ) {
V_153 = V_580 ;
V_23 = NULL ;
goto V_585;
}
if ( F_4 ( V_13 , V_17 ) ) {
V_153 = V_506 ;
V_23 = NULL ;
goto V_585;
}
V_23 = V_502 -> V_39 -> V_507 ( V_502 ) ;
if ( ! V_23 ) {
V_153 = V_506 ;
goto V_585;
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
V_23 -> V_107 = F_69 ( V_272 -> V_159 ) ;
F_68 ( V_13 , V_23 ) ;
V_16 = V_23 -> V_17 ;
V_159 = V_23 -> V_108 ;
F_85 ( V_23 , V_23 -> V_39 -> V_167 ( V_23 ) ) ;
V_23 -> V_19 = V_425 -> V_19 ;
if ( F_70 ( V_154 , & V_23 -> V_103 ) ) {
F_22 ( V_23 , V_168 ) ;
V_153 = V_321 ;
V_23 -> V_39 -> V_323 ( V_23 ) ;
} else {
F_130 ( V_23 ) ;
V_153 = V_324 ;
}
V_585:
F_48 ( V_502 ) ;
F_10 ( & V_13 -> V_18 ) ;
F_49 ( V_502 ) ;
if ( V_153 == V_321 )
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
static inline int F_287 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
struct F_287 * V_586 ;
struct V_11 * V_23 ;
T_2 V_14 , V_159 , V_587 ;
if ( V_497 != sizeof( * V_586 ) )
return - V_500 ;
V_586 = (struct F_287 * ) V_188 ;
V_14 = F_69 ( V_586 -> V_14 ) ;
V_159 = F_69 ( V_586 -> V_159 ) ;
F_23 ( L_68 , V_14 , V_159 ) ;
V_23 = F_11 ( V_13 , V_14 ) ;
if ( ! V_23 )
return - V_513 ;
V_587 = V_588 - V_23 -> V_107 ;
if ( V_159 > V_587 ) {
F_284 ( L_69 ) ;
F_86 ( V_23 , V_319 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
V_23 -> V_107 += V_159 ;
while ( V_23 -> V_107 && ! F_169 ( & V_23 -> V_113 ) ) {
F_96 ( V_23 , F_170 ( & V_23 -> V_113 ) ) ;
V_23 -> V_107 -- ;
}
if ( V_23 -> V_107 )
V_23 -> V_39 -> V_589 ( V_23 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static inline int F_288 ( struct V_12 * V_13 ,
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
static inline int F_289 ( struct V_12 * V_13 ,
struct V_424 * V_425 , T_2 V_497 ,
T_1 * V_188 )
{
int V_24 = 0 ;
switch ( V_425 -> V_186 ) {
case V_518 :
F_288 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_344 :
V_24 = V_337 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_578 :
break;
case V_160 :
F_282 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_298 :
V_24 = F_285 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_590 :
V_24 = F_287 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_316 :
V_24 = F_249 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
case V_526 :
F_250 ( V_13 , V_425 , V_497 , V_188 ) ;
break;
default:
F_284 ( L_70 , V_425 -> V_186 ) ;
V_24 = - V_29 ;
break;
}
return V_24 ;
}
static inline void F_290 ( struct V_12 * V_13 ,
struct V_45 * V_49 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_424 * V_425 ;
T_2 V_187 ;
int V_24 ;
if ( V_8 -> type != V_2 )
goto V_591;
if ( V_49 -> V_187 < V_426 )
goto V_591;
V_425 = ( void * ) V_49 -> V_188 ;
F_102 ( V_49 , V_426 ) ;
V_187 = F_228 ( V_425 -> V_187 ) ;
F_23 ( L_71 , V_425 -> V_186 , V_187 , V_425 -> V_19 ) ;
if ( V_187 != V_49 -> V_187 || ! V_425 -> V_19 ) {
F_23 ( L_72 ) ;
goto V_591;
}
V_24 = F_289 ( V_13 , V_425 , V_187 , V_49 -> V_188 ) ;
if ( V_24 ) {
struct V_498 V_499 ;
F_284 ( L_73 , V_24 ) ;
V_499 . V_67 = F_18 ( V_501 ) ;
F_83 ( V_13 , V_425 -> V_19 , V_518 ,
sizeof( V_499 ) , & V_499 ) ;
}
V_591:
F_97 ( V_49 ) ;
}
static inline void F_291 ( struct V_12 * V_13 ,
struct V_45 * V_49 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
T_1 * V_188 = V_49 -> V_188 ;
int V_187 = V_49 -> V_187 ;
struct V_424 V_425 ;
int V_24 ;
F_214 ( V_13 , V_49 ) ;
if ( V_8 -> type != V_117 )
goto V_591;
while ( V_187 >= V_426 ) {
T_2 V_497 ;
memcpy ( & V_425 , V_188 , V_426 ) ;
V_188 += V_426 ;
V_187 -= V_426 ;
V_497 = F_228 ( V_425 . V_187 ) ;
F_23 ( L_71 , V_425 . V_186 , V_497 ,
V_425 . V_19 ) ;
if ( V_497 > V_187 || ! V_425 . V_19 ) {
F_23 ( L_72 ) ;
break;
}
V_24 = F_283 ( V_13 , & V_425 , V_497 , V_188 ) ;
if ( V_24 ) {
struct V_498 V_499 ;
F_284 ( L_73 , V_24 ) ;
V_499 . V_67 = F_18 ( V_501 ) ;
F_83 ( V_13 , V_425 . V_19 , V_518 ,
sizeof( V_499 ) , & V_499 ) ;
}
V_188 += V_497 ;
V_187 -= V_497 ;
}
V_591:
F_97 ( V_49 ) ;
}
static int F_292 ( struct V_11 * V_23 , struct V_45 * V_49 )
{
T_2 V_592 , V_593 ;
int V_594 ;
if ( F_70 ( V_238 , & V_23 -> V_103 ) )
V_594 = V_243 ;
else
V_594 = V_244 ;
if ( V_23 -> V_87 == V_88 ) {
F_293 ( V_49 , V_49 -> V_187 - V_248 ) ;
V_593 = F_103 ( V_49 -> V_188 + V_49 -> V_187 ) ;
V_592 = F_114 ( 0 , V_49 -> V_188 - V_594 , V_49 -> V_187 + V_594 ) ;
if ( V_592 != V_593 )
return - V_595 ;
}
return 0 ;
}
static void F_294 ( struct V_11 * V_23 )
{
struct V_204 V_50 ;
F_23 ( L_3 , V_23 ) ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_212 = 1 ;
V_50 . V_208 = 1 ;
V_50 . V_205 = V_23 -> V_258 ;
F_57 ( V_250 , & V_23 -> V_251 ) ;
if ( F_70 ( V_257 , & V_23 -> V_251 ) ) {
V_50 . V_216 = V_254 ;
F_115 ( V_23 , & V_50 ) ;
}
if ( F_116 ( V_286 , & V_23 -> V_251 ) &&
V_23 -> V_378 > 0 )
F_27 ( V_23 ) ;
F_172 ( V_23 ) ;
if ( ! F_70 ( V_257 , & V_23 -> V_251 ) &&
F_70 ( V_250 , & V_23 -> V_251 ) ) {
V_50 . V_216 = V_252 ;
F_115 ( V_23 , & V_50 ) ;
}
}
static void F_295 ( struct V_45 * V_49 , struct V_45 * V_596 ,
struct V_45 * * V_597 )
{
if ( ! F_296 ( V_49 ) )
F_189 ( V_49 ) -> V_388 = V_596 ;
V_596 -> V_351 = NULL ;
( * V_597 ) -> V_351 = V_596 ;
* V_597 = V_596 ;
V_49 -> V_187 += V_596 -> V_187 ;
V_49 -> V_392 += V_596 -> V_187 ;
V_49 -> V_598 += V_596 -> V_598 ;
}
static int F_297 ( struct V_11 * V_23 , struct V_45 * V_49 ,
struct V_204 * V_50 )
{
int V_24 = - V_29 ;
switch ( V_50 -> V_219 ) {
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
F_295 ( V_23 -> V_104 , V_49 ,
& V_23 -> V_105 ) ;
V_49 = NULL ;
if ( V_23 -> V_104 -> V_187 >= V_23 -> V_106 )
break;
V_24 = 0 ;
break;
case V_402 :
if ( ! V_23 -> V_104 )
break;
F_295 ( V_23 -> V_104 , V_49 ,
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
static int F_298 ( struct V_11 * V_23 )
{
return 0 ;
}
void F_299 ( struct V_11 * V_23 , int V_599 )
{
T_1 V_412 ;
if ( V_23 -> V_141 != V_144 )
return;
V_412 = V_599 ? V_413 : V_415 ;
F_129 ( V_23 , NULL , NULL , V_412 ) ;
}
static int F_300 ( struct V_11 * V_23 )
{
int V_24 = 0 ;
F_23 ( L_3 , V_23 ) ;
while ( ! F_70 ( V_257 , & V_23 -> V_251 ) ) {
struct V_45 * V_49 ;
F_23 ( L_74 ,
V_23 -> V_258 , F_176 ( & V_23 -> V_145 ) ) ;
V_49 = F_33 ( & V_23 -> V_145 , V_23 -> V_258 ) ;
if ( ! V_49 )
break;
F_207 ( V_49 , & V_23 -> V_145 ) ;
V_23 -> V_258 = F_171 ( V_23 , V_23 -> V_258 ) ;
V_24 = F_297 ( V_23 , V_49 , & F_35 ( V_49 ) -> V_50 ) ;
if ( V_24 )
break;
}
if ( F_169 ( & V_23 -> V_145 ) ) {
V_23 -> V_284 = V_381 ;
F_184 ( V_23 ) ;
}
return V_24 ;
}
static void F_301 ( struct V_11 * V_23 ,
struct V_204 * V_50 )
{
struct V_45 * V_49 ;
F_23 ( L_10 , V_23 , V_50 ) ;
if ( V_50 -> V_205 == V_23 -> V_372 ) {
F_23 ( L_75 , V_50 -> V_205 ) ;
F_86 ( V_23 , V_319 ) ;
return;
}
V_49 = F_33 ( & V_23 -> V_113 , V_50 -> V_205 ) ;
if ( V_49 == NULL ) {
F_23 ( L_76 ,
V_50 -> V_205 ) ;
return;
}
if ( V_23 -> V_89 != 0 && F_35 ( V_49 ) -> V_50 . V_278 >= V_23 -> V_89 ) {
F_23 ( L_21 , V_23 -> V_89 ) ;
F_86 ( V_23 , V_319 ) ;
return;
}
F_117 ( V_286 , & V_23 -> V_251 ) ;
if ( V_50 -> V_213 ) {
F_212 ( V_23 , V_50 ) ;
F_57 ( V_250 , & V_23 -> V_251 ) ;
F_181 ( V_23 , V_50 ) ;
F_172 ( V_23 ) ;
if ( V_23 -> V_282 == V_417 ) {
F_57 ( V_281 , & V_23 -> V_251 ) ;
V_23 -> V_600 = V_50 -> V_205 ;
}
} else {
F_213 ( V_23 , V_50 ) ;
if ( V_50 -> V_208 ) {
if ( V_23 -> V_600 != V_50 -> V_205 ||
! F_116 ( V_281 ,
& V_23 -> V_251 ) )
F_181 ( V_23 , V_50 ) ;
} else {
F_181 ( V_23 , V_50 ) ;
if ( V_23 -> V_282 == V_417 ) {
F_57 ( V_281 , & V_23 -> V_251 ) ;
V_23 -> V_600 = V_50 -> V_205 ;
}
}
}
}
static void F_302 ( struct V_11 * V_23 ,
struct V_204 * V_50 )
{
struct V_45 * V_49 ;
F_23 ( L_10 , V_23 , V_50 ) ;
if ( V_50 -> V_205 == V_23 -> V_372 ) {
F_23 ( L_75 , V_50 -> V_205 ) ;
F_86 ( V_23 , V_319 ) ;
return;
}
V_49 = F_33 ( & V_23 -> V_113 , V_50 -> V_205 ) ;
if ( V_23 -> V_89 && V_49 &&
F_35 ( V_49 ) -> V_50 . V_278 >= V_23 -> V_89 ) {
F_23 ( L_21 , V_23 -> V_89 ) ;
F_86 ( V_23 , V_319 ) ;
return;
}
F_117 ( V_286 , & V_23 -> V_251 ) ;
F_212 ( V_23 , V_50 ) ;
if ( V_50 -> V_208 ) {
if ( ! F_116 ( V_280 , & V_23 -> V_251 ) )
F_182 ( V_23 , V_50 ) ;
} else {
F_182 ( V_23 , V_50 ) ;
F_172 ( V_23 ) ;
if ( V_23 -> V_282 == V_417 )
F_57 ( V_280 , & V_23 -> V_251 ) ;
}
}
static T_1 F_303 ( struct V_11 * V_23 , T_2 V_51 )
{
F_23 ( L_77 , V_23 , V_51 ) ;
F_23 ( L_78 , V_23 -> V_256 ,
V_23 -> V_279 ) ;
if ( V_23 -> V_284 == V_414 ) {
if ( F_185 ( V_23 , V_51 , V_23 -> V_256 ) >=
V_23 -> V_91 ) {
if ( V_23 -> V_91 <= ( ( V_23 -> V_93 + 1 ) >> 1 ) ) {
F_23 ( L_79 ) ;
return V_601 ;
} else {
F_23 ( L_80 ) ;
return V_602 ;
}
}
if ( V_23 -> V_146 . V_47 == V_51 ) {
F_23 ( L_81 ) ;
return V_603 ;
}
if ( F_33 ( & V_23 -> V_145 , V_51 ) ) {
F_23 ( L_82 ) ;
return V_604 ;
}
if ( F_41 ( & V_23 -> V_146 , V_51 ) ) {
F_23 ( L_83 ) ;
return V_605 ;
}
}
if ( V_23 -> V_279 == V_51 ) {
if ( F_185 ( V_23 , V_51 , V_23 -> V_256 ) >=
V_23 -> V_91 ) {
F_23 ( L_84 ) ;
return V_602 ;
} else {
F_23 ( L_85 ) ;
return V_606 ;
}
}
if ( F_185 ( V_23 , V_51 , V_23 -> V_256 ) <
F_185 ( V_23 , V_23 -> V_279 , V_23 -> V_256 ) ) {
F_23 ( L_86 ) ;
return V_607 ;
}
if ( F_185 ( V_23 , V_51 , V_23 -> V_256 ) >= V_23 -> V_91 ) {
if ( V_23 -> V_91 <= ( ( V_23 -> V_93 + 1 ) >> 1 ) ) {
F_23 ( L_87 ) ;
return V_601 ;
} else {
F_23 ( L_84 ) ;
return V_602 ;
}
} else {
F_23 ( L_88 ) ;
return V_608 ;
}
}
static int F_304 ( struct V_11 * V_23 ,
struct V_204 * V_50 ,
struct V_45 * V_49 , T_1 V_412 )
{
int V_24 = 0 ;
bool V_609 = false ;
F_23 ( L_89 , V_23 , V_50 , V_49 ,
V_412 ) ;
switch ( V_412 ) {
case V_610 :
switch ( F_303 ( V_23 , V_50 -> V_51 ) ) {
case V_606 :
F_212 ( V_23 , V_50 ) ;
if ( F_70 ( V_257 , & V_23 -> V_251 ) ) {
F_23 ( L_90 ,
V_50 -> V_51 ) ;
break;
}
V_23 -> V_279 = F_171 ( V_23 ,
V_50 -> V_51 ) ;
V_23 -> V_258 = V_23 -> V_279 ;
V_609 = true ;
V_24 = F_297 ( V_23 , V_49 , V_50 ) ;
if ( V_24 )
break;
if ( V_50 -> V_208 ) {
if ( ! F_116 ( V_280 ,
& V_23 -> V_251 ) ) {
V_50 -> V_208 = 0 ;
F_182 ( V_23 , V_50 ) ;
F_172 ( V_23 ) ;
}
}
if ( ! F_70 ( V_257 , & V_23 -> V_251 ) )
F_184 ( V_23 ) ;
break;
case V_608 :
F_212 ( V_23 , V_50 ) ;
if ( F_70 ( V_257 , & V_23 -> V_251 ) ) {
F_23 ( L_91 ,
V_50 -> V_51 ) ;
break;
}
F_305 ( & V_23 -> V_145 , V_49 ) ;
V_609 = true ;
F_23 ( L_92 , V_49 ,
F_176 ( & V_23 -> V_145 ) ) ;
F_117 ( V_281 , & V_23 -> V_251 ) ;
F_43 ( & V_23 -> V_146 ) ;
F_203 ( V_23 , V_50 -> V_51 ) ;
V_23 -> V_284 = V_414 ;
break;
case V_607 :
F_212 ( V_23 , V_50 ) ;
break;
case V_601 :
break;
case V_602 :
default:
F_86 ( V_23 , V_319 ) ;
break;
}
break;
case V_611 :
F_212 ( V_23 , V_50 ) ;
if ( V_50 -> V_208 ) {
F_117 ( V_286 , & V_23 -> V_251 ) ;
if ( ! F_116 ( V_280 , & V_23 -> V_251 ) &&
! F_95 ( V_23 ) ) {
V_50 -> V_208 = 0 ;
F_182 ( V_23 , V_50 ) ;
}
F_172 ( V_23 ) ;
} else if ( V_50 -> V_213 ) {
F_294 ( V_23 ) ;
} else {
if ( F_116 ( V_286 ,
& V_23 -> V_251 ) &&
V_23 -> V_378 )
F_27 ( V_23 ) ;
F_172 ( V_23 ) ;
}
break;
case V_612 :
F_57 ( V_286 , & V_23 -> V_251 ) ;
F_212 ( V_23 , V_50 ) ;
if ( V_50 && V_50 -> V_213 ) {
F_57 ( V_250 , & V_23 -> V_251 ) ;
F_119 ( V_23 , 0 ) ;
}
F_32 ( V_23 ) ;
F_43 ( & V_23 -> V_147 ) ;
break;
case V_613 :
F_302 ( V_23 , V_50 ) ;
break;
case V_614 :
F_301 ( V_23 , V_50 ) ;
break;
default:
break;
}
if ( V_49 && ! V_609 ) {
F_23 ( L_93 , V_49 ) ;
F_97 ( V_49 ) ;
}
return V_24 ;
}
static int F_306 ( struct V_11 * V_23 ,
struct V_204 * V_50 ,
struct V_45 * V_49 , T_1 V_412 )
{
int V_24 = 0 ;
T_2 V_51 = V_50 -> V_51 ;
bool V_609 = false ;
F_23 ( L_89 , V_23 , V_50 , V_49 ,
V_412 ) ;
switch ( V_412 ) {
case V_610 :
switch ( F_303 ( V_23 , V_51 ) ) {
case V_606 :
F_212 ( V_23 , V_50 ) ;
F_305 ( & V_23 -> V_145 , V_49 ) ;
V_609 = true ;
F_23 ( L_92 , V_49 ,
F_176 ( & V_23 -> V_145 ) ) ;
V_23 -> V_279 = F_171 ( V_23 , V_51 ) ;
break;
case V_603 :
F_42 ( & V_23 -> V_146 ) ;
F_212 ( V_23 , V_50 ) ;
F_305 ( & V_23 -> V_145 , V_49 ) ;
V_609 = true ;
F_23 ( L_92 , V_49 ,
F_176 ( & V_23 -> V_145 ) ) ;
V_24 = F_300 ( V_23 ) ;
if ( V_24 )
break;
break;
case V_608 :
F_305 ( & V_23 -> V_145 , V_49 ) ;
V_609 = true ;
F_23 ( L_92 , V_49 ,
F_176 ( & V_23 -> V_145 ) ) ;
F_212 ( V_23 , V_50 ) ;
F_203 ( V_23 , V_50 -> V_51 ) ;
break;
case V_605 :
F_305 ( & V_23 -> V_145 , V_49 ) ;
V_609 = true ;
F_23 ( L_92 , V_49 ,
F_176 ( & V_23 -> V_145 ) ) ;
F_212 ( V_23 , V_50 ) ;
F_205 ( V_23 , V_50 -> V_51 ) ;
break;
case V_604 :
F_212 ( V_23 , V_50 ) ;
break;
case V_607 :
break;
case V_601 :
break;
case V_602 :
default:
F_86 ( V_23 , V_319 ) ;
break;
}
break;
case V_611 :
F_212 ( V_23 , V_50 ) ;
if ( V_50 -> V_208 ) {
F_117 ( V_286 , & V_23 -> V_251 ) ;
if ( ! F_116 ( V_280 ,
& V_23 -> V_251 ) ) {
V_50 -> V_208 = 0 ;
F_182 ( V_23 , V_50 ) ;
}
F_172 ( V_23 ) ;
} else if ( V_50 -> V_213 ) {
if ( F_116 ( V_286 ,
& V_23 -> V_251 ) &&
V_23 -> V_378 ) {
F_27 ( V_23 ) ;
}
F_57 ( V_250 , & V_23 -> V_251 ) ;
F_204 ( V_23 ) ;
} else {
if ( F_116 ( V_286 ,
& V_23 -> V_251 ) &&
V_23 -> V_378 )
F_27 ( V_23 ) ;
F_184 ( V_23 ) ;
}
break;
case V_612 :
F_57 ( V_286 , & V_23 -> V_251 ) ;
F_212 ( V_23 , V_50 ) ;
if ( V_50 -> V_213 ) {
F_204 ( V_23 ) ;
} else {
struct V_204 V_615 ;
memset ( & V_615 , 0 , sizeof( V_615 ) ) ;
V_615 . V_212 = 1 ;
V_615 . V_216 = V_252 ;
V_615 . V_205 = V_23 -> V_258 ;
F_115 ( V_23 , & V_615 ) ;
}
break;
case V_613 :
F_302 ( V_23 , V_50 ) ;
break;
case V_614 :
F_301 ( V_23 , V_50 ) ;
break;
}
if ( V_49 && ! V_609 ) {
F_23 ( L_93 , V_49 ) ;
F_97 ( V_49 ) ;
}
return V_24 ;
}
static int F_307 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
V_23 -> V_284 = V_381 ;
if ( V_23 -> V_200 )
V_23 -> V_13 -> V_158 = V_23 -> V_200 -> V_189 -> V_538 ;
else
V_23 -> V_13 -> V_158 = V_23 -> V_13 -> V_8 -> V_189 -> V_616 ;
return F_298 ( V_23 ) ;
}
static int F_308 ( struct V_11 * V_23 ,
struct V_204 * V_50 ,
struct V_45 * V_49 , T_1 V_412 )
{
int V_24 ;
F_23 ( L_89 , V_23 , V_50 , V_49 ,
V_412 ) ;
if ( ! V_50 -> V_213 )
return - V_500 ;
F_206 ( V_23 , V_50 -> V_205 ) ;
if ( ! F_169 ( & V_23 -> V_113 ) )
V_23 -> V_377 = F_210 ( & V_23 -> V_113 ) ;
else
V_23 -> V_377 = NULL ;
V_23 -> V_372 = V_50 -> V_205 ;
V_23 -> V_378 = 0 ;
V_24 = F_307 ( V_23 ) ;
if ( V_24 )
return V_24 ;
F_57 ( V_250 , & V_23 -> V_251 ) ;
F_294 ( V_23 ) ;
if ( V_412 == V_610 )
return - V_500 ;
return F_304 ( V_23 , V_50 , NULL , V_412 ) ;
}
static int F_309 ( struct V_11 * V_23 ,
struct V_204 * V_50 ,
struct V_45 * V_49 , T_1 V_412 )
{
int V_24 ;
if ( ! V_50 -> V_208 )
return - V_500 ;
F_117 ( V_286 , & V_23 -> V_251 ) ;
V_23 -> V_284 = V_381 ;
F_206 ( V_23 , V_50 -> V_205 ) ;
if ( ! F_169 ( & V_23 -> V_113 ) )
V_23 -> V_377 = F_210 ( & V_23 -> V_113 ) ;
else
V_23 -> V_377 = NULL ;
V_23 -> V_372 = V_50 -> V_205 ;
V_23 -> V_378 = 0 ;
if ( V_23 -> V_200 )
V_23 -> V_13 -> V_158 = V_23 -> V_200 -> V_189 -> V_538 ;
else
V_23 -> V_13 -> V_158 = V_23 -> V_13 -> V_8 -> V_189 -> V_616 ;
V_24 = F_298 ( V_23 ) ;
if ( ! V_24 )
V_24 = F_304 ( V_23 , V_50 , V_49 , V_412 ) ;
return V_24 ;
}
static bool F_310 ( struct V_11 * V_23 , T_2 V_205 )
{
T_2 V_617 ;
V_617 = F_185 ( V_23 , V_23 -> V_372 , V_23 -> V_411 ) ;
return F_185 ( V_23 , V_23 -> V_372 , V_205 ) <= V_617 ;
}
static int F_311 ( struct V_11 * V_23 , struct V_204 * V_50 ,
struct V_45 * V_49 , T_1 V_412 )
{
int V_24 = 0 ;
F_23 ( L_94 , V_23 ,
V_50 , V_49 , V_412 , V_23 -> V_284 ) ;
if ( F_310 ( V_23 , V_50 -> V_205 ) ) {
switch ( V_23 -> V_284 ) {
case V_381 :
V_24 = F_304 ( V_23 , V_50 , V_49 , V_412 ) ;
break;
case V_414 :
V_24 = F_306 ( V_23 , V_50 , V_49 ,
V_412 ) ;
break;
case V_293 :
V_24 = F_308 ( V_23 , V_50 , V_49 , V_412 ) ;
break;
case V_291 :
V_24 = F_309 ( V_23 , V_50 , V_49 , V_412 ) ;
break;
default:
break;
}
} else {
F_23 ( L_95 ,
V_50 -> V_205 , V_23 -> V_372 ,
V_23 -> V_411 ) ;
F_86 ( V_23 , V_319 ) ;
}
return V_24 ;
}
static int F_312 ( struct V_11 * V_23 , struct V_204 * V_50 ,
struct V_45 * V_49 )
{
int V_24 = 0 ;
F_23 ( L_96 , V_23 , V_50 , V_49 ,
V_23 -> V_284 ) ;
if ( F_303 ( V_23 , V_50 -> V_51 ) ==
V_606 ) {
F_212 ( V_23 , V_50 ) ;
F_23 ( L_97 , V_23 -> V_258 ,
F_171 ( V_23 , V_23 -> V_258 ) ) ;
V_23 -> V_258 = F_171 ( V_23 , V_23 -> V_258 ) ;
F_297 ( V_23 , V_49 , V_50 ) ;
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
V_23 -> V_256 = V_50 -> V_51 ;
V_23 -> V_279 = F_171 ( V_23 , V_50 -> V_51 ) ;
return V_24 ;
}
static int F_313 ( struct V_11 * V_23 , struct V_45 * V_49 )
{
struct V_204 * V_50 = & F_35 ( V_49 ) -> V_50 ;
T_2 V_187 ;
T_1 V_412 ;
F_100 ( V_23 , V_49 ) ;
V_187 = V_49 -> V_187 ;
if ( F_292 ( V_23 , V_49 ) )
goto V_591;
if ( ! V_50 -> V_212 && V_50 -> V_219 == V_401 )
V_187 -= V_395 ;
if ( V_23 -> V_87 == V_88 )
V_187 -= V_248 ;
if ( V_187 > V_23 -> V_110 ) {
F_86 ( V_23 , V_319 ) ;
goto V_591;
}
if ( ! V_50 -> V_212 ) {
int V_24 ;
F_23 ( L_98 ,
V_50 -> V_219 , V_50 -> V_205 , V_50 -> V_208 ,
V_50 -> V_51 ) ;
if ( V_50 -> V_208 && V_23 -> V_282 != V_417 )
goto V_591;
if ( V_23 -> V_141 != V_148 ) {
V_412 = V_610 ;
V_24 = F_311 ( V_23 , V_50 , V_49 , V_412 ) ;
} else {
V_24 = F_312 ( V_23 , V_50 , V_49 ) ;
}
if ( V_24 )
F_86 ( V_23 , V_319 ) ;
} else {
const T_1 V_618 [ 4 ] = {
V_611 , V_613 ,
V_612 , V_614
} ;
if ( V_23 -> V_141 == V_148 )
goto V_591;
F_23 ( L_99 ,
V_50 -> V_205 , V_50 -> V_208 , V_50 -> V_213 ,
V_50 -> V_216 ) ;
if ( V_187 != 0 ) {
F_284 ( L_100 , V_187 ) ;
F_86 ( V_23 , V_319 ) ;
goto V_591;
}
if ( V_50 -> V_208 && ( V_50 -> V_213 ||
V_23 -> V_282 != V_417 ) )
goto V_591;
V_412 = V_618 [ V_50 -> V_216 ] ;
if ( F_311 ( V_23 , V_50 , V_49 , V_412 ) )
F_86 ( V_23 , V_319 ) ;
}
return 0 ;
V_591:
F_97 ( V_49 ) ;
return 0 ;
}
static void F_314 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct F_287 V_586 ;
T_2 V_619 ;
if ( V_23 -> V_108 >= ( V_109 + 1 ) / 2 )
return;
V_619 = V_109 - V_23 -> V_108 ;
F_23 ( L_101 , V_23 , V_619 ) ;
V_23 -> V_108 += V_619 ;
V_586 . V_14 = F_18 ( V_23 -> V_17 ) ;
V_586 . V_159 = F_18 ( V_619 ) ;
V_23 -> V_19 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_590 , sizeof( V_586 ) , & V_586 ) ;
}
static int F_315 ( struct V_11 * V_23 , struct V_45 * V_49 )
{
int V_24 ;
if ( ! V_23 -> V_108 ) {
F_284 ( L_102 ) ;
F_86 ( V_23 , V_319 ) ;
return - V_620 ;
}
if ( V_23 -> V_111 < V_49 -> V_187 ) {
F_284 ( L_103 ) ;
return - V_620 ;
}
V_23 -> V_108 -- ;
F_23 ( L_104 , V_23 -> V_108 + 1 , V_23 -> V_108 ) ;
F_314 ( V_23 ) ;
V_24 = 0 ;
if ( ! V_23 -> V_104 ) {
T_2 V_106 ;
V_106 = F_103 ( V_49 -> V_188 ) ;
F_102 ( V_49 , V_395 ) ;
F_23 ( L_105 ,
V_106 , V_49 -> V_187 , V_23 -> V_111 ) ;
if ( V_106 > V_23 -> V_111 ) {
F_284 ( L_106 ) ;
V_24 = - V_404 ;
goto V_621;
}
if ( V_49 -> V_187 > V_106 ) {
F_284 ( L_107 ) ;
V_24 = - V_29 ;
goto V_621;
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
F_284 ( L_107 ) ;
V_24 = - V_29 ;
goto V_621;
}
F_295 ( V_23 -> V_104 , V_49 , & V_23 -> V_105 ) ;
V_49 = NULL ;
if ( V_23 -> V_104 -> V_187 == V_23 -> V_106 ) {
V_24 = V_23 -> V_39 -> V_422 ( V_23 , V_23 -> V_104 ) ;
if ( ! V_24 ) {
V_23 -> V_104 = NULL ;
V_23 -> V_105 = NULL ;
V_23 -> V_106 = 0 ;
}
}
V_621:
if ( V_24 ) {
F_97 ( V_49 ) ;
F_97 ( V_23 -> V_104 ) ;
V_23 -> V_104 = NULL ;
V_23 -> V_105 = NULL ;
V_23 -> V_106 = 0 ;
}
return 0 ;
}
static void F_316 ( struct V_12 * V_13 , T_2 V_14 ,
struct V_45 * V_49 )
{
struct V_11 * V_23 ;
V_23 = F_7 ( V_13 , V_14 ) ;
if ( ! V_23 ) {
if ( V_14 == V_315 ) {
V_23 = F_317 ( V_13 , V_49 ) ;
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
if ( V_23 -> V_38 != V_68 )
goto V_591;
switch ( V_23 -> V_141 ) {
case V_143 :
if ( F_315 ( V_23 , V_49 ) < 0 )
goto V_591;
goto V_27;
case V_142 :
if ( V_23 -> V_111 < V_49 -> V_187 ) {
F_284 ( L_111 ) ;
goto V_591;
}
if ( ! V_23 -> V_39 -> V_422 ( V_23 , V_49 ) )
goto V_27;
break;
case V_144 :
case V_148 :
F_313 ( V_23 , V_49 ) ;
goto V_27;
default:
F_23 ( L_112 , V_23 , V_23 -> V_141 ) ;
break;
}
V_591:
F_97 ( V_49 ) ;
V_27:
F_48 ( V_23 ) ;
}
static void F_318 ( struct V_12 * V_13 , T_3 V_20 ,
struct V_45 * V_49 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_11 * V_23 ;
if ( V_8 -> type != V_117 )
goto V_622;
V_23 = F_164 ( 0 , V_20 , & V_8 -> V_21 , & V_8 -> V_150 ,
V_117 ) ;
if ( ! V_23 )
goto V_622;
F_23 ( L_110 , V_23 , V_49 -> V_187 ) ;
if ( V_23 -> V_38 != V_623 && V_23 -> V_38 != V_68 )
goto V_591;
if ( V_23 -> V_111 < V_49 -> V_187 )
goto V_591;
F_81 ( & F_35 ( V_49 ) -> V_624 , & V_8 -> V_150 ) ;
F_35 ( V_49 ) -> V_20 = V_20 ;
if ( ! V_23 -> V_39 -> V_422 ( V_23 , V_49 ) ) {
F_49 ( V_23 ) ;
return;
}
V_591:
F_49 ( V_23 ) ;
V_622:
F_97 ( V_49 ) ;
}
static void F_319 ( struct V_12 * V_13 , struct V_45 * V_49 )
{
struct V_245 * V_246 = ( void * ) V_49 -> V_188 ;
struct V_7 * V_8 = V_13 -> V_8 ;
T_2 V_14 , V_187 ;
T_3 V_20 ;
if ( V_8 -> V_38 != V_68 ) {
F_23 ( L_113 ) ;
F_305 ( & V_13 -> V_360 , V_49 ) ;
return;
}
F_102 ( V_49 , V_242 ) ;
V_14 = F_69 ( V_246 -> V_14 ) ;
V_187 = F_69 ( V_246 -> V_187 ) ;
if ( V_187 != V_49 -> V_187 ) {
F_97 ( V_49 ) ;
return;
}
if ( V_8 -> type == V_2 &&
F_320 ( & V_8 -> V_189 -> V_625 , & V_8 -> V_150 ,
F_3 ( V_8 ) ) ) {
F_97 ( V_49 ) ;
return;
}
F_23 ( L_114 , V_187 , V_14 ) ;
switch ( V_14 ) {
case V_120 :
F_291 ( V_13 , V_49 ) ;
break;
case V_119 :
V_20 = F_321 ( ( T_3 * ) V_49 -> V_188 ) ;
F_102 ( V_49 , V_393 ) ;
F_318 ( V_13 , V_20 , V_49 ) ;
break;
case V_427 :
F_290 ( V_13 , V_49 ) ;
break;
default:
F_316 ( V_13 , V_14 , V_49 ) ;
break;
}
}
static void F_322 ( struct V_64 * V_65 )
{
struct V_12 * V_13 = F_46 ( V_65 , struct V_12 ,
V_346 ) ;
struct V_45 * V_49 ;
F_23 ( L_115 ) ;
while ( ( V_49 = F_170 ( & V_13 -> V_360 ) ) )
F_319 ( V_13 , V_49 ) ;
}
static struct V_12 * F_323 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_357 ;
struct V_140 * V_196 ;
if ( V_13 )
return V_13 ;
V_196 = F_324 ( V_8 ) ;
if ( ! V_196 )
return NULL ;
V_13 = F_51 ( sizeof( * V_13 ) , V_58 ) ;
if ( ! V_13 ) {
F_158 ( V_196 ) ;
return NULL ;
}
F_56 ( & V_13 -> V_362 ) ;
V_8 -> V_357 = V_13 ;
V_13 -> V_8 = F_325 ( V_8 ) ;
V_13 -> V_196 = V_196 ;
F_23 ( L_116 , V_8 , V_13 , V_196 ) ;
switch ( V_8 -> type ) {
case V_2 :
if ( V_8 -> V_189 -> V_626 ) {
V_13 -> V_158 = V_8 -> V_189 -> V_626 ;
break;
}
default:
V_13 -> V_158 = V_8 -> V_189 -> V_616 ;
break;
}
V_13 -> V_308 = 0 ;
V_13 -> V_262 = V_627 | V_628 ;
if ( V_8 -> type == V_117 &&
F_70 ( V_629 , & V_8 -> V_189 -> V_511 ) )
V_13 -> V_262 |= V_263 ;
if ( F_70 ( V_630 , & V_8 -> V_189 -> V_511 ) &&
( F_326 ( V_8 -> V_189 ) ||
F_70 ( V_631 , & V_8 -> V_189 -> V_632 ) ) )
V_13 -> V_262 |= V_633 ;
F_52 ( & V_13 -> V_184 ) ;
F_52 ( & V_13 -> V_18 ) ;
F_327 ( & V_13 -> V_134 ) ;
F_327 ( & V_13 -> V_356 ) ;
F_55 ( & V_13 -> V_304 , F_147 ) ;
F_67 ( & V_13 -> V_360 ) ;
F_328 ( & V_13 -> V_346 , F_322 ) ;
F_328 ( & V_13 -> V_149 , F_80 ) ;
V_13 -> V_114 = V_115 ;
return V_13 ;
}
static bool F_329 ( T_2 V_20 , T_1 V_10 ) {
if ( ! V_20 )
return false ;
if ( F_330 ( V_10 ) )
return ( V_20 <= 0x00ff ) ;
return ( ( V_20 & 0x0101 ) == 0x0001 ) ;
}
int F_331 ( struct V_11 * V_23 , T_3 V_20 , T_2 V_14 ,
T_4 * V_150 , T_1 V_10 )
{
struct V_12 * V_13 ;
struct V_7 * V_8 ;
struct V_260 * V_189 ;
int V_24 ;
F_23 ( L_117 , & V_23 -> V_21 , V_150 ,
V_10 , F_69 ( V_20 ) ) ;
V_189 = F_332 ( V_150 , & V_23 -> V_21 ) ;
if ( ! V_189 )
return - V_634 ;
F_149 ( V_189 ) ;
if ( ! F_329 ( F_69 ( V_20 ) , V_10 ) && ! V_14 &&
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
if ( ! V_311 )
break;
default:
V_24 = - V_635 ;
goto V_27;
}
switch ( V_23 -> V_38 ) {
case V_71 :
case V_168 :
case V_69 :
V_24 = 0 ;
goto V_27;
case V_68 :
V_24 = - V_636 ;
goto V_27;
case V_82 :
case V_623 :
break;
default:
V_24 = - V_407 ;
goto V_27;
}
F_81 ( & V_23 -> V_150 , V_150 ) ;
V_23 -> V_10 = V_10 ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_14 ;
if ( F_330 ( V_10 ) ) {
T_1 V_332 ;
if ( V_10 == V_4 )
V_10 = V_3 ;
else
V_10 = V_637 ;
if ( F_70 ( V_638 , & V_189 -> V_511 ) )
V_332 = V_333 ;
else
V_332 = V_575 ;
V_8 = F_333 ( V_189 , V_150 , V_10 , V_23 -> V_72 ,
V_639 , V_332 ) ;
} else {
T_1 V_182 = F_87 ( V_23 ) ;
V_8 = F_334 ( V_189 , V_150 , V_23 -> V_72 , V_182 ) ;
}
if ( F_118 ( V_8 ) ) {
V_24 = F_190 ( V_8 ) ;
goto V_27;
}
V_13 = F_323 ( V_8 ) ;
if ( ! V_13 ) {
F_75 ( V_8 ) ;
V_24 = - V_59 ;
goto V_27;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_23 ) ;
if ( V_14 && F_4 ( V_13 , V_14 ) ) {
F_75 ( V_8 ) ;
V_24 = - V_640 ;
goto V_641;
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
V_641:
F_48 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
V_27:
F_150 ( V_189 ) ;
F_255 ( V_189 ) ;
return V_24 ;
}
int F_335 ( struct V_260 * V_189 , T_4 * V_624 )
{
int V_642 = 0 , V_643 = 0 , V_644 = 0 ;
struct V_11 * V_15 ;
F_23 ( L_118 , V_189 -> V_329 , V_624 ) ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
if ( V_15 -> V_38 != V_166 )
continue;
if ( ! F_15 ( & V_15 -> V_21 , & V_189 -> V_624 ) ) {
V_643 |= V_645 ;
if ( F_70 ( V_646 , & V_15 -> V_103 ) )
V_643 |= V_647 ;
V_642 ++ ;
} else if ( ! F_15 ( & V_15 -> V_21 , V_368 ) ) {
V_644 |= V_645 ;
if ( F_70 ( V_646 , & V_15 -> V_103 ) )
V_644 |= V_647 ;
}
}
F_123 ( & V_25 ) ;
return V_642 ? V_643 : V_644 ;
}
static struct V_11 * F_336 ( struct V_11 * V_15 ,
struct V_7 * V_8 )
{
T_1 V_9 = F_2 ( V_8 ) ;
F_122 ( & V_25 ) ;
if ( V_15 )
V_15 = F_337 ( V_15 , V_80 ) ;
else
V_15 = F_338 ( V_81 . V_351 , F_339 ( * V_15 ) , V_80 ) ;
F_340 (c, &chan_list, global_l) {
if ( V_15 -> V_32 != V_33 )
continue;
if ( V_15 -> V_38 != V_166 )
continue;
if ( F_15 ( & V_15 -> V_21 , & V_8 -> V_21 ) && F_15 ( & V_15 -> V_21 , V_368 ) )
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
void F_341 ( struct V_7 * V_8 , T_1 V_163 )
{
struct V_260 * V_189 = V_8 -> V_189 ;
struct V_12 * V_13 ;
struct V_11 * V_502 ;
T_1 V_10 ;
F_23 ( L_119 , V_8 , & V_8 -> V_150 , V_163 ) ;
if ( V_163 ) {
F_155 ( V_8 , F_342 ( V_163 ) ) ;
return;
}
V_13 = F_323 ( V_8 ) ;
if ( ! V_13 )
return;
V_10 = F_3 ( V_8 ) ;
if ( F_320 ( & V_189 -> V_625 , & V_8 -> V_150 , V_10 ) )
return;
V_502 = F_336 ( NULL , V_8 ) ;
while ( V_502 ) {
struct V_11 * V_23 , * V_351 ;
if ( F_4 ( V_13 , V_502 -> V_17 ) )
goto V_351;
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
V_351:
V_351 = F_336 ( V_502 , V_8 ) ;
F_49 ( V_502 ) ;
V_502 = V_351 ;
}
F_144 ( V_13 ) ;
}
int F_343 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_357 ;
F_23 ( L_120 , V_8 ) ;
if ( ! V_13 )
return V_115 ;
return V_13 -> V_114 ;
}
void F_344 ( struct V_7 * V_8 , T_1 V_67 )
{
F_23 ( L_121 , V_8 , V_67 ) ;
F_155 ( V_8 , F_342 ( V_67 ) ) ;
}
static inline void F_345 ( struct V_11 * V_23 , T_1 V_648 )
{
if ( V_23 -> V_32 != V_116 )
return;
if ( V_648 == 0x00 ) {
if ( V_23 -> V_72 == V_173 ) {
F_85 ( V_23 , V_649 ) ;
} else if ( V_23 -> V_72 == V_170 ||
V_23 -> V_72 == V_171 )
F_47 ( V_23 , V_70 ) ;
} else {
if ( V_23 -> V_72 == V_173 )
F_74 ( V_23 ) ;
}
}
int F_346 ( struct V_7 * V_8 , T_1 V_163 , T_1 V_648 )
{
struct V_12 * V_13 = V_8 -> V_357 ;
struct V_11 * V_23 ;
if ( ! V_13 )
return 0 ;
F_23 ( L_122 , V_13 , V_163 , V_648 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
F_9 ( V_23 ) ;
F_23 ( L_123 , V_23 , V_23 -> V_17 ,
F_24 ( V_23 -> V_38 ) ) ;
if ( V_23 -> V_17 == V_315 ) {
F_48 ( V_23 ) ;
continue;
}
if ( ! V_163 && V_648 )
V_23 -> V_72 = V_8 -> V_72 ;
if ( ! F_120 ( V_23 ) ) {
F_48 ( V_23 ) ;
continue;
}
if ( ! V_163 && ( V_23 -> V_38 == V_68 ||
V_23 -> V_38 == V_69 ) ) {
V_23 -> V_39 -> V_589 ( V_23 ) ;
F_345 ( V_23 , V_648 ) ;
F_48 ( V_23 ) ;
continue;
}
if ( V_23 -> V_38 == V_71 ) {
if ( ! V_163 )
F_134 ( V_23 ) ;
else
F_85 ( V_23 , V_650 ) ;
} else if ( V_23 -> V_38 == V_168 &&
V_23 -> V_141 != V_143 ) {
struct V_161 V_152 ;
T_5 V_651 , V_652 ;
if ( ! V_163 ) {
if ( F_70 ( V_154 , & V_23 -> V_103 ) ) {
V_651 = V_321 ;
V_652 = V_322 ;
V_23 -> V_39 -> V_323 ( V_23 ) ;
} else {
F_22 ( V_23 , V_69 ) ;
V_651 = V_324 ;
V_652 = V_164 ;
}
} else {
F_22 ( V_23 , V_157 ) ;
F_85 ( V_23 , V_650 ) ;
V_651 = V_162 ;
V_652 = V_164 ;
}
V_152 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_152 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_152 . V_153 = F_18 ( V_651 ) ;
V_152 . V_163 = F_18 ( V_652 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_165 ,
sizeof( V_152 ) , & V_152 ) ;
if ( ! F_70 ( V_326 , & V_23 -> V_85 ) &&
V_651 == V_324 ) {
char V_320 [ 128 ] ;
F_57 ( V_326 , & V_23 -> V_85 ) ;
F_83 ( V_13 , F_91 ( V_13 ) ,
V_327 ,
F_142 ( V_23 , V_320 ) ,
V_320 ) ;
V_23 -> V_328 ++ ;
}
}
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
return 0 ;
}
int F_347 ( struct V_7 * V_8 , struct V_45 * V_49 , T_2 V_103 )
{
struct V_12 * V_13 = V_8 -> V_357 ;
struct V_245 * V_653 ;
int V_187 ;
if ( ! V_13 && V_8 -> V_189 -> V_535 != V_654 )
goto V_591;
if ( ! V_13 )
V_13 = F_323 ( V_8 ) ;
if ( ! V_13 )
goto V_591;
F_23 ( L_124 , V_13 , V_49 -> V_187 , V_103 ) ;
switch ( V_103 ) {
case V_191 :
case V_190 :
case V_201 :
if ( V_13 -> V_655 ) {
F_284 ( L_125 , V_49 -> V_187 ) ;
F_97 ( V_13 -> V_359 ) ;
V_13 -> V_359 = NULL ;
V_13 -> V_655 = 0 ;
F_146 ( V_13 , V_656 ) ;
}
if ( V_49 -> V_187 < V_242 ) {
F_284 ( L_126 , V_49 -> V_187 ) ;
F_146 ( V_13 , V_656 ) ;
goto V_591;
}
V_653 = (struct V_245 * ) V_49 -> V_188 ;
V_187 = F_69 ( V_653 -> V_187 ) + V_242 ;
if ( V_187 == V_49 -> V_187 ) {
F_319 ( V_13 , V_49 ) ;
return 0 ;
}
F_23 ( L_127 , V_187 , V_49 -> V_187 ) ;
if ( V_49 -> V_187 > V_187 ) {
F_284 ( L_128 ,
V_49 -> V_187 , V_187 ) ;
F_146 ( V_13 , V_656 ) ;
goto V_591;
}
V_13 -> V_359 = F_111 ( V_187 , V_58 ) ;
if ( ! V_13 -> V_359 )
goto V_591;
F_348 ( V_49 , F_113 ( V_13 -> V_359 , V_49 -> V_187 ) ,
V_49 -> V_187 ) ;
V_13 -> V_655 = V_187 - V_49 -> V_187 ;
break;
case V_657 :
F_23 ( L_129 , V_49 -> V_187 , V_13 -> V_655 ) ;
if ( ! V_13 -> V_655 ) {
F_284 ( L_130 , V_49 -> V_187 ) ;
F_146 ( V_13 , V_656 ) ;
goto V_591;
}
if ( V_49 -> V_187 > V_13 -> V_655 ) {
F_284 ( L_131 ,
V_49 -> V_187 , V_13 -> V_655 ) ;
F_97 ( V_13 -> V_359 ) ;
V_13 -> V_359 = NULL ;
V_13 -> V_655 = 0 ;
F_146 ( V_13 , V_656 ) ;
goto V_591;
}
F_348 ( V_49 , F_113 ( V_13 -> V_359 , V_49 -> V_187 ) ,
V_49 -> V_187 ) ;
V_13 -> V_655 -= V_49 -> V_187 ;
if ( ! V_13 -> V_655 ) {
struct V_45 * V_359 = V_13 -> V_359 ;
V_13 -> V_359 = NULL ;
F_319 ( V_13 , V_359 ) ;
}
break;
}
V_591:
F_97 ( V_49 ) ;
return 0 ;
}
static int F_349 ( struct V_658 * V_659 , void * V_28 )
{
struct V_11 * V_15 ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
F_350 ( V_659 , L_132 ,
& V_15 -> V_21 , V_15 -> V_9 , & V_15 -> V_150 , V_15 -> V_10 ,
V_15 -> V_38 , F_69 ( V_15 -> V_20 ) ,
V_15 -> V_17 , V_15 -> V_16 , V_15 -> V_111 , V_15 -> V_30 ,
V_15 -> V_72 , V_15 -> V_141 ) ;
}
F_123 ( & V_25 ) ;
return 0 ;
}
static int F_351 ( struct V_660 * V_660 , struct V_661 * V_661 )
{
return F_352 ( V_661 , F_349 , V_660 -> V_662 ) ;
}
int T_11 F_353 ( void )
{
int V_24 ;
V_24 = F_354 () ;
if ( V_24 < 0 )
return V_24 ;
if ( F_355 ( V_663 ) )
return 0 ;
V_664 = F_356 ( L_133 , 0444 , V_663 ,
NULL , & V_665 ) ;
F_357 ( L_134 , 0644 , V_663 ,
& V_109 ) ;
F_357 ( L_135 , 0644 , V_663 ,
& V_112 ) ;
return 0 ;
}
void F_358 ( void )
{
F_359 ( V_664 ) ;
F_360 () ;
}
