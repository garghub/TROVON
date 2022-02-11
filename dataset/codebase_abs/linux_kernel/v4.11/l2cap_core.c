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
T_2 V_28 , V_29 , V_30 , V_31 ;
if ( V_23 -> V_9 == V_6 ) {
V_29 = V_32 ;
V_30 = V_33 ;
V_31 = 2 ;
} else {
V_29 = V_34 ;
V_30 = V_35 ;
V_31 = 1 ;
}
V_24 = - V_36 ;
for ( V_28 = V_29 ; V_28 <= V_30 ; V_28 += V_31 )
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
V_23 -> V_37 = V_38 ;
V_23 -> V_39 = V_40 ;
V_23 -> V_17 = V_17 ;
F_19 ( & V_25 ) ;
return 0 ;
}
static T_2 F_21 ( struct V_12 * V_13 )
{
T_2 V_14 , V_41 ;
if ( V_13 -> V_8 -> type == V_2 )
V_41 = V_42 ;
else
V_41 = V_43 ;
for ( V_14 = V_44 ; V_14 <= V_41 ; V_14 ++ ) {
if ( ! F_6 ( V_13 , V_14 ) )
return V_14 ;
}
return 0 ;
}
static void F_22 ( struct V_11 * V_23 , int V_45 )
{
F_23 ( L_1 , V_23 , F_24 ( V_23 -> V_45 ) ,
F_24 ( V_45 ) ) ;
V_23 -> V_45 = V_45 ;
V_23 -> V_46 -> V_47 ( V_23 , V_45 , 0 ) ;
}
static inline void F_25 ( struct V_11 * V_23 ,
int V_45 , int V_24 )
{
V_23 -> V_45 = V_45 ;
V_23 -> V_46 -> V_47 ( V_23 , V_23 -> V_45 , V_24 ) ;
}
static inline void F_26 ( struct V_11 * V_23 , int V_24 )
{
V_23 -> V_46 -> V_47 ( V_23 , V_23 -> V_45 , V_24 ) ;
}
static void F_27 ( struct V_11 * V_23 )
{
if ( ! F_28 ( & V_23 -> V_48 ) &&
V_23 -> V_49 ) {
F_29 ( V_23 , & V_23 -> V_50 ,
F_30 ( V_23 -> V_49 ) ) ;
}
}
static void F_31 ( struct V_11 * V_23 )
{
F_32 ( V_23 ) ;
if ( V_23 -> V_51 ) {
F_29 ( V_23 , & V_23 -> V_48 ,
F_30 ( V_23 -> V_51 ) ) ;
}
}
static struct V_52 * F_33 ( struct V_53 * V_54 ,
T_2 V_55 )
{
struct V_52 * V_56 ;
F_34 (head, skb) {
if ( F_35 ( V_56 ) -> V_57 . V_58 == V_55 )
return V_56 ;
}
return NULL ;
}
static int F_36 ( struct V_59 * V_60 , T_2 V_61 )
{
T_6 V_62 , V_63 ;
V_62 = F_37 ( V_61 ) ;
V_60 -> V_64 = F_38 ( sizeof( T_2 ) * V_62 , V_65 ) ;
if ( ! V_60 -> V_64 )
return - V_66 ;
V_60 -> V_67 = V_62 - 1 ;
V_60 -> V_54 = V_68 ;
V_60 -> V_69 = V_68 ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ )
V_60 -> V_64 [ V_63 ] = V_68 ;
return 0 ;
}
static inline void F_39 ( struct V_59 * V_60 )
{
F_40 ( V_60 -> V_64 ) ;
}
static inline bool F_41 ( struct V_59 * V_60 ,
T_2 V_55 )
{
return V_60 -> V_64 [ V_55 & V_60 -> V_67 ] != V_68 ;
}
static inline T_2 F_42 ( struct V_59 * V_60 )
{
T_2 V_55 = V_60 -> V_54 ;
T_2 V_67 = V_60 -> V_67 ;
V_60 -> V_54 = V_60 -> V_64 [ V_55 & V_67 ] ;
V_60 -> V_64 [ V_55 & V_67 ] = V_68 ;
if ( V_60 -> V_54 == V_70 ) {
V_60 -> V_54 = V_68 ;
V_60 -> V_69 = V_68 ;
}
return V_55 ;
}
static void F_43 ( struct V_59 * V_60 )
{
T_2 V_63 ;
if ( V_60 -> V_54 == V_68 )
return;
for ( V_63 = 0 ; V_63 <= V_60 -> V_67 ; V_63 ++ )
V_60 -> V_64 [ V_63 ] = V_68 ;
V_60 -> V_54 = V_68 ;
V_60 -> V_69 = V_68 ;
}
static void F_44 ( struct V_59 * V_60 , T_2 V_55 )
{
T_2 V_67 = V_60 -> V_67 ;
if ( V_60 -> V_64 [ V_55 & V_67 ] != V_68 )
return;
if ( V_60 -> V_69 == V_68 )
V_60 -> V_54 = V_55 ;
else
V_60 -> V_64 [ V_60 -> V_69 & V_67 ] = V_55 ;
V_60 -> V_69 = V_55 ;
V_60 -> V_64 [ V_55 & V_67 ] = V_70 ;
}
static void F_45 ( struct V_71 * V_72 )
{
struct V_11 * V_23 = F_46 ( V_72 , struct V_11 ,
V_73 . V_72 ) ;
struct V_12 * V_13 = V_23 -> V_13 ;
int V_74 ;
F_23 ( L_2 , V_23 , F_24 ( V_23 -> V_45 ) ) ;
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_23 ) ;
if ( V_23 -> V_45 == V_75 || V_23 -> V_45 == V_76 )
V_74 = V_77 ;
else if ( V_23 -> V_45 == V_78 &&
V_23 -> V_79 != V_80 )
V_74 = V_77 ;
else
V_74 = V_81 ;
F_47 ( V_23 , V_74 ) ;
F_48 ( V_23 ) ;
V_23 -> V_46 -> V_82 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
F_49 ( V_23 ) ;
}
struct V_11 * F_50 ( void )
{
struct V_11 * V_23 ;
V_23 = F_51 ( sizeof( * V_23 ) , V_83 ) ;
if ( ! V_23 )
return NULL ;
F_52 ( & V_23 -> V_84 ) ;
F_53 ( & V_23 -> V_85 , V_86 ) ;
F_17 ( & V_25 ) ;
F_54 ( & V_23 -> V_87 , & V_88 ) ;
F_19 ( & V_25 ) ;
F_55 ( & V_23 -> V_73 , F_45 ) ;
V_23 -> V_45 = V_89 ;
F_56 ( & V_23 -> V_90 ) ;
F_57 ( V_91 , & V_23 -> V_92 ) ;
F_23 ( L_3 , V_23 ) ;
return V_23 ;
}
static void F_58 ( struct V_90 * V_90 )
{
struct V_11 * V_23 = F_46 ( V_90 , struct V_11 , V_90 ) ;
F_23 ( L_3 , V_23 ) ;
F_17 ( & V_25 ) ;
F_59 ( & V_23 -> V_87 ) ;
F_19 ( & V_25 ) ;
F_40 ( V_23 ) ;
}
void F_60 ( struct V_11 * V_15 )
{
F_23 ( L_4 , V_15 , F_61 ( & V_15 -> V_90 ) ) ;
F_62 ( & V_15 -> V_90 ) ;
}
void F_49 ( struct V_11 * V_15 )
{
F_23 ( L_4 , V_15 , F_61 ( & V_15 -> V_90 ) ) ;
F_63 ( & V_15 -> V_90 , F_58 ) ;
}
void F_64 ( struct V_11 * V_23 )
{
V_23 -> V_93 = V_94 ;
V_23 -> V_95 = V_96 ;
V_23 -> V_97 = V_98 ;
V_23 -> V_99 = V_98 ;
V_23 -> V_100 = V_23 -> V_95 ;
V_23 -> V_101 = V_23 -> V_97 ;
V_23 -> V_102 = V_98 ;
V_23 -> V_79 = V_103 ;
V_23 -> V_104 = V_105 ;
V_23 -> V_49 = V_106 ;
V_23 -> V_51 = V_107 ;
V_23 -> V_92 = 0 ;
F_57 ( V_108 , & V_23 -> V_109 ) ;
}
static void F_65 ( struct V_11 * V_23 )
{
V_23 -> V_110 = NULL ;
V_23 -> V_111 = NULL ;
V_23 -> V_112 = 0 ;
V_23 -> V_113 = 0 ;
V_23 -> V_114 = V_115 ;
V_23 -> V_116 = F_66 ( T_2 , V_23 -> V_117 , V_118 ) ;
F_67 ( & V_23 -> V_119 ) ;
}
void F_68 ( struct V_12 * V_13 , struct V_11 * V_23 )
{
F_23 ( L_5 , V_13 ,
F_69 ( V_23 -> V_20 ) , V_23 -> V_16 ) ;
V_13 -> V_120 = V_121 ;
V_23 -> V_13 = V_13 ;
switch ( V_23 -> V_39 ) {
case V_122 :
V_23 -> V_17 = F_21 ( V_13 ) ;
if ( V_13 -> V_8 -> type == V_123 )
V_23 -> V_37 = V_38 ;
break;
case V_124 :
V_23 -> V_17 = V_125 ;
V_23 -> V_16 = V_125 ;
V_23 -> V_37 = V_38 ;
break;
case V_40 :
break;
default:
V_23 -> V_17 = V_126 ;
V_23 -> V_16 = V_126 ;
V_23 -> V_37 = V_38 ;
}
V_23 -> V_127 = V_128 ;
V_23 -> V_129 = V_130 ;
V_23 -> V_131 = V_132 ;
V_23 -> V_133 = V_134 ;
V_23 -> V_135 = V_136 ;
V_23 -> V_137 = V_138 ;
F_60 ( V_23 ) ;
if ( V_23 -> V_39 != V_40 ||
F_70 ( V_139 , & V_23 -> V_109 ) )
F_71 ( V_13 -> V_8 ) ;
F_54 ( & V_23 -> V_64 , & V_13 -> V_140 ) ;
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
F_24 ( V_23 -> V_45 ) ) ;
V_23 -> V_46 -> V_141 ( V_23 , V_24 ) ;
if ( V_13 ) {
struct V_142 * V_143 = V_13 -> V_8 -> V_142 ;
F_59 ( & V_23 -> V_64 ) ;
F_49 ( V_23 ) ;
V_23 -> V_13 = NULL ;
if ( V_23 -> V_39 != V_40 ||
F_70 ( V_139 , & V_23 -> V_109 ) )
F_75 ( V_13 -> V_8 ) ;
if ( V_143 && V_143 -> V_144 == V_23 )
V_143 -> V_144 = NULL ;
}
if ( V_23 -> V_145 ) {
struct V_146 * V_145 = V_23 -> V_145 ;
F_23 ( L_7 , V_23 , V_145 ) ;
F_76 ( V_145 ) ;
}
if ( F_70 ( V_91 , & V_23 -> V_92 ) )
return;
switch( V_23 -> V_147 ) {
case V_148 :
break;
case V_149 :
F_77 ( & V_23 -> V_119 ) ;
break;
case V_150 :
F_32 ( V_23 ) ;
F_78 ( V_23 ) ;
F_79 ( V_23 ) ;
F_77 ( & V_23 -> V_151 ) ;
F_39 ( & V_23 -> V_152 ) ;
F_39 ( & V_23 -> V_153 ) ;
case V_154 :
F_77 ( & V_23 -> V_119 ) ;
break;
}
return;
}
static void F_80 ( struct V_71 * V_72 )
{
struct V_12 * V_13 = F_46 ( V_72 , struct V_12 ,
V_155 ) ;
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_11 * V_23 ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
F_9 ( V_23 ) ;
F_81 ( & V_23 -> V_156 , & V_8 -> V_156 ) ;
V_23 -> V_10 = F_3 ( V_8 ) ;
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static void F_82 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_157 V_158 ;
T_2 V_159 ;
if ( F_70 ( V_160 , & V_23 -> V_109 ) )
V_159 = V_161 ;
else
V_159 = V_162 ;
F_22 ( V_23 , V_163 ) ;
V_158 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_158 . V_164 = F_18 ( V_23 -> V_117 ) ;
V_158 . V_116 = F_18 ( V_23 -> V_116 ) ;
V_158 . V_165 = F_18 ( V_23 -> V_114 ) ;
V_158 . V_159 = F_18 ( V_159 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_166 , sizeof( V_158 ) ,
& V_158 ) ;
}
static void F_84 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_167 V_158 ;
T_2 V_159 ;
if ( F_70 ( V_160 , & V_23 -> V_109 ) )
V_159 = V_168 ;
else
V_159 = V_162 ;
F_22 ( V_23 , V_163 ) ;
V_158 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_158 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_158 . V_159 = F_18 ( V_159 ) ;
V_158 . V_169 = F_18 ( V_170 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_171 , sizeof( V_158 ) , & V_158 ) ;
}
void F_47 ( struct V_11 * V_23 , int V_74 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
F_23 ( L_2 , V_23 , F_24 ( V_23 -> V_45 ) ) ;
switch ( V_23 -> V_45 ) {
case V_172 :
V_23 -> V_46 -> V_141 ( V_23 , 0 ) ;
break;
case V_75 :
case V_76 :
if ( V_23 -> V_39 == V_122 ) {
F_85 ( V_23 , V_23 -> V_46 -> V_173 ( V_23 ) ) ;
F_86 ( V_23 , V_74 ) ;
} else
F_73 ( V_23 , V_74 ) ;
break;
case V_174 :
if ( V_23 -> V_39 == V_122 ) {
if ( V_13 -> V_8 -> type == V_123 )
F_84 ( V_23 ) ;
else if ( V_13 -> V_8 -> type == V_2 )
F_82 ( V_23 ) ;
}
F_73 ( V_23 , V_74 ) ;
break;
case V_78 :
case V_163 :
F_73 ( V_23 , V_74 ) ;
break;
default:
V_23 -> V_46 -> V_141 ( V_23 , 0 ) ;
break;
}
}
static inline T_1 F_87 ( struct V_11 * V_23 )
{
switch ( V_23 -> V_39 ) {
case V_175 :
switch ( V_23 -> V_79 ) {
case V_176 :
case V_177 :
return V_178 ;
case V_179 :
return V_180 ;
default:
return V_181 ;
}
break;
case V_124 :
if ( V_23 -> V_20 == F_18 ( V_182 ) ) {
if ( V_23 -> V_79 == V_103 )
V_23 -> V_79 = V_80 ;
}
if ( V_23 -> V_79 == V_176 ||
V_23 -> V_79 == V_177 )
return V_183 ;
else
return V_181 ;
break;
case V_122 :
if ( V_23 -> V_20 == F_18 ( V_184 ) ) {
if ( V_23 -> V_79 == V_103 )
V_23 -> V_79 = V_80 ;
if ( V_23 -> V_79 == V_176 ||
V_23 -> V_79 == V_177 )
return V_183 ;
else
return V_181 ;
}
default:
switch ( V_23 -> V_79 ) {
case V_176 :
case V_177 :
return V_185 ;
case V_179 :
return V_186 ;
default:
return V_181 ;
}
break;
}
}
int F_88 ( struct V_11 * V_23 , bool V_187 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
T_7 V_188 ;
if ( V_13 -> V_8 -> type == V_2 )
return F_89 ( V_13 -> V_8 , V_23 -> V_79 ) ;
V_188 = F_87 ( V_23 ) ;
return F_90 ( V_13 -> V_8 , V_23 -> V_79 , V_188 ,
V_187 ) ;
}
static T_1 F_91 ( struct V_12 * V_13 )
{
T_1 V_189 ;
F_8 ( & V_13 -> V_190 ) ;
if ( ++ V_13 -> V_191 > 128 )
V_13 -> V_191 = 1 ;
V_189 = V_13 -> V_191 ;
F_10 ( & V_13 -> V_190 ) ;
return V_189 ;
}
static void F_83 ( struct V_12 * V_13 , T_1 V_19 , T_1 V_192 , T_2 V_193 ,
void * V_194 )
{
struct V_52 * V_56 = F_92 ( V_13 , V_192 , V_19 , V_193 , V_194 ) ;
T_1 V_109 ;
F_23 ( L_8 , V_192 ) ;
if ( ! V_56 )
return;
if ( F_93 ( V_13 -> V_8 -> V_195 ) ||
V_13 -> V_8 -> type == V_2 )
V_109 = V_196 ;
else
V_109 = V_197 ;
F_35 ( V_56 ) -> V_198 = V_199 ;
V_56 -> V_200 = V_201 ;
F_94 ( V_13 -> V_202 , V_56 , V_109 ) ;
}
static bool F_95 ( struct V_11 * V_23 )
{
return V_23 -> V_203 != V_204 &&
V_23 -> V_203 != V_205 ;
}
static void F_96 ( struct V_11 * V_23 , struct V_52 * V_56 )
{
struct V_7 * V_8 = V_23 -> V_13 -> V_8 ;
T_2 V_109 ;
F_23 ( L_9 , V_23 , V_56 , V_56 -> V_193 ,
V_56 -> V_200 ) ;
if ( V_23 -> V_206 && ! F_95 ( V_23 ) ) {
if ( V_23 -> V_145 )
F_94 ( V_23 -> V_145 , V_56 , V_207 ) ;
else
F_97 ( V_56 ) ;
return;
}
if ( V_8 -> type == V_2 ||
( ! F_70 ( V_208 , & V_23 -> V_109 ) &&
F_93 ( V_8 -> V_195 ) ) )
V_109 = V_196 ;
else
V_109 = V_197 ;
F_35 ( V_56 ) -> V_198 = F_70 ( V_108 , & V_23 -> V_109 ) ;
F_94 ( V_23 -> V_13 -> V_202 , V_56 , V_109 ) ;
}
static void F_98 ( T_2 V_209 , struct V_210 * V_211 )
{
V_211 -> V_212 = ( V_209 & V_213 ) >> V_214 ;
V_211 -> V_215 = ( V_209 & V_216 ) >> V_217 ;
if ( V_209 & V_218 ) {
V_211 -> V_219 = 1 ;
V_211 -> V_220 = ( V_209 & V_221 ) >> V_222 ;
V_211 -> V_223 = ( V_209 & V_224 ) >> V_225 ;
V_211 -> V_226 = 0 ;
V_211 -> V_58 = 0 ;
} else {
V_211 -> V_219 = 0 ;
V_211 -> V_226 = ( V_209 & V_227 ) >> V_228 ;
V_211 -> V_58 = ( V_209 & V_229 ) >> V_230 ;
V_211 -> V_220 = 0 ;
V_211 -> V_223 = 0 ;
}
}
static void F_99 ( T_8 V_231 , struct V_210 * V_211 )
{
V_211 -> V_212 = ( V_231 & V_232 ) >> V_233 ;
V_211 -> V_215 = ( V_231 & V_234 ) >> V_235 ;
if ( V_231 & V_236 ) {
V_211 -> V_219 = 1 ;
V_211 -> V_220 = ( V_231 & V_237 ) >> V_238 ;
V_211 -> V_223 = ( V_231 & V_239 ) >> V_240 ;
V_211 -> V_226 = 0 ;
V_211 -> V_58 = 0 ;
} else {
V_211 -> V_219 = 0 ;
V_211 -> V_226 = ( V_231 & V_241 ) >> V_242 ;
V_211 -> V_58 = ( V_231 & V_243 ) >> V_244 ;
V_211 -> V_220 = 0 ;
V_211 -> V_223 = 0 ;
}
}
static inline void F_100 ( struct V_11 * V_23 ,
struct V_52 * V_56 )
{
if ( F_70 ( V_245 , & V_23 -> V_109 ) ) {
F_99 ( F_101 ( V_56 -> V_194 ) ,
& F_35 ( V_56 ) -> V_57 ) ;
F_102 ( V_56 , V_246 ) ;
} else {
F_98 ( F_103 ( V_56 -> V_194 ) ,
& F_35 ( V_56 ) -> V_57 ) ;
F_102 ( V_56 , V_247 ) ;
}
}
static T_8 F_104 ( struct V_210 * V_211 )
{
T_8 V_248 ;
V_248 = V_211 -> V_212 << V_233 ;
V_248 |= V_211 -> V_215 << V_235 ;
if ( V_211 -> V_219 ) {
V_248 |= V_211 -> V_220 << V_238 ;
V_248 |= V_211 -> V_223 << V_240 ;
V_248 |= V_236 ;
} else {
V_248 |= V_211 -> V_226 << V_242 ;
V_248 |= V_211 -> V_58 << V_244 ;
}
return V_248 ;
}
static T_2 F_105 ( struct V_210 * V_211 )
{
T_2 V_248 ;
V_248 = V_211 -> V_212 << V_214 ;
V_248 |= V_211 -> V_215 << V_217 ;
if ( V_211 -> V_219 ) {
V_248 |= V_211 -> V_220 << V_222 ;
V_248 |= V_211 -> V_223 << V_225 ;
V_248 |= V_218 ;
} else {
V_248 |= V_211 -> V_226 << V_228 ;
V_248 |= V_211 -> V_58 << V_230 ;
}
return V_248 ;
}
static inline void F_106 ( struct V_11 * V_23 ,
struct V_210 * V_211 ,
struct V_52 * V_56 )
{
if ( F_70 ( V_245 , & V_23 -> V_109 ) ) {
F_107 ( F_104 ( V_211 ) ,
V_56 -> V_194 + V_249 ) ;
} else {
F_108 ( F_105 ( V_211 ) ,
V_56 -> V_194 + V_249 ) ;
}
}
static inline unsigned int F_109 ( struct V_11 * V_23 )
{
if ( F_70 ( V_245 , & V_23 -> V_109 ) )
return V_250 ;
else
return V_251 ;
}
static struct V_52 * F_110 ( struct V_11 * V_23 ,
T_8 V_211 )
{
struct V_52 * V_56 ;
struct V_252 * V_253 ;
int V_254 = F_109 ( V_23 ) ;
if ( V_23 -> V_93 == V_94 )
V_254 += V_255 ;
V_56 = F_111 ( V_254 , V_65 ) ;
if ( ! V_56 )
return F_112 ( - V_66 ) ;
V_253 = (struct V_252 * ) F_113 ( V_56 , V_249 ) ;
V_253 -> V_193 = F_18 ( V_254 - V_249 ) ;
V_253 -> V_14 = F_18 ( V_23 -> V_16 ) ;
if ( F_70 ( V_245 , & V_23 -> V_109 ) )
F_107 ( V_211 , F_113 ( V_56 , V_246 ) ) ;
else
F_108 ( V_211 , F_113 ( V_56 , V_247 ) ) ;
if ( V_23 -> V_93 == V_94 ) {
T_2 V_93 = F_114 ( 0 , ( T_1 * ) V_56 -> V_194 , V_56 -> V_193 ) ;
F_108 ( V_93 , F_113 ( V_56 , V_255 ) ) ;
}
V_56 -> V_200 = V_201 ;
return V_56 ;
}
static void F_115 ( struct V_11 * V_23 ,
struct V_210 * V_211 )
{
struct V_52 * V_56 ;
T_8 V_256 ;
F_23 ( L_10 , V_23 , V_211 ) ;
if ( ! V_211 -> V_219 )
return;
if ( F_95 ( V_23 ) )
return;
if ( F_116 ( V_257 , & V_23 -> V_258 ) &&
! V_211 -> V_220 )
V_211 -> V_215 = 1 ;
if ( V_211 -> V_223 == V_259 )
F_117 ( V_260 , & V_23 -> V_258 ) ;
else if ( V_211 -> V_223 == V_261 )
F_57 ( V_260 , & V_23 -> V_258 ) ;
if ( V_211 -> V_223 != V_262 ) {
V_23 -> V_263 = V_211 -> V_212 ;
F_79 ( V_23 ) ;
}
F_23 ( L_11 , V_211 -> V_212 ,
V_211 -> V_215 , V_211 -> V_220 , V_211 -> V_223 ) ;
if ( F_70 ( V_245 , & V_23 -> V_109 ) )
V_256 = F_104 ( V_211 ) ;
else
V_256 = F_105 ( V_211 ) ;
V_56 = F_110 ( V_23 , V_256 ) ;
if ( ! F_118 ( V_56 ) )
F_96 ( V_23 , V_56 ) ;
}
static void F_119 ( struct V_11 * V_23 , bool V_220 )
{
struct V_210 V_211 ;
F_23 ( L_12 , V_23 , V_220 ) ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
V_211 . V_219 = 1 ;
V_211 . V_220 = V_220 ;
if ( F_70 ( V_264 , & V_23 -> V_258 ) )
V_211 . V_223 = V_261 ;
else
V_211 . V_223 = V_259 ;
V_211 . V_212 = V_23 -> V_265 ;
F_115 ( V_23 , & V_211 ) ;
}
static inline int F_120 ( struct V_11 * V_23 )
{
if ( V_23 -> V_39 != V_122 )
return true ;
return ! F_70 ( V_266 , & V_23 -> V_92 ) ;
}
static bool F_121 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_267 * V_195 ;
bool V_268 = false ;
if ( ! ( V_13 -> V_269 & V_270 ) )
return false ;
if ( ! ( V_13 -> V_271 & V_270 ) )
return false ;
F_122 ( & V_272 ) ;
F_5 (hdev, &hci_dev_list, list) {
if ( V_195 -> V_273 != V_274 &&
F_70 ( V_275 , & V_195 -> V_109 ) ) {
V_268 = true ;
break;
}
}
F_123 ( & V_272 ) ;
if ( V_23 -> V_276 == V_277 )
return V_268 ;
return false ;
}
static bool F_124 ( struct V_11 * V_23 )
{
return true ;
}
void F_125 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_278 V_279 ;
V_279 . V_17 = F_18 ( V_23 -> V_17 ) ;
V_279 . V_20 = V_23 -> V_20 ;
V_23 -> V_19 = F_91 ( V_13 ) ;
F_57 ( V_266 , & V_23 -> V_92 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_280 , sizeof( V_279 ) , & V_279 ) ;
}
static void F_126 ( struct V_11 * V_23 , T_1 V_281 )
{
struct V_282 V_279 ;
V_279 . V_17 = F_18 ( V_23 -> V_17 ) ;
V_279 . V_20 = V_23 -> V_20 ;
V_279 . V_281 = V_281 ;
V_23 -> V_19 = F_91 ( V_23 -> V_13 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_283 ,
sizeof( V_279 ) , & V_279 ) ;
}
static void F_127 ( struct V_11 * V_23 )
{
struct V_52 * V_56 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_147 != V_150 )
return;
F_32 ( V_23 ) ;
F_78 ( V_23 ) ;
F_79 ( V_23 ) ;
V_23 -> V_284 = 0 ;
F_34 (&chan->tx_q, skb) {
if ( F_35 ( V_56 ) -> V_57 . V_285 )
F_35 ( V_56 ) -> V_57 . V_285 = 1 ;
else
break;
}
V_23 -> V_286 = V_23 -> V_265 ;
F_117 ( V_287 , & V_23 -> V_258 ) ;
F_117 ( V_288 , & V_23 -> V_258 ) ;
F_43 ( & V_23 -> V_153 ) ;
F_43 ( & V_23 -> V_152 ) ;
F_77 ( & V_23 -> V_151 ) ;
V_23 -> V_289 = V_290 ;
V_23 -> V_291 = V_292 ;
F_57 ( V_293 , & V_23 -> V_258 ) ;
}
static void F_128 ( struct V_11 * V_23 )
{
T_1 V_294 = V_23 -> V_294 ;
F_23 ( L_3 , V_23 ) ;
V_23 -> V_203 = V_204 ;
V_23 -> V_294 = V_295 ;
if ( V_23 -> V_147 != V_150 )
return;
switch ( V_294 ) {
case V_296 :
F_129 ( V_23 , NULL , NULL , V_297 ) ;
V_23 -> V_291 = V_298 ;
break;
case V_299 :
V_23 -> V_291 = V_300 ;
break;
}
}
static void F_130 ( struct V_11 * V_23 )
{
if ( V_23 -> V_45 == V_75 )
return;
V_23 -> V_92 = 0 ;
F_74 ( V_23 ) ;
if ( V_23 -> V_147 == V_149 && ! V_23 -> V_113 )
V_23 -> V_46 -> V_301 ( V_23 ) ;
V_23 -> V_45 = V_75 ;
V_23 -> V_46 -> V_302 ( V_23 ) ;
}
static void F_131 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_303 V_279 ;
if ( F_132 ( V_304 , & V_23 -> V_109 ) )
return;
V_279 . V_20 = V_23 -> V_20 ;
V_279 . V_17 = F_18 ( V_23 -> V_17 ) ;
V_279 . V_164 = F_18 ( V_23 -> V_117 ) ;
V_279 . V_116 = F_18 ( V_23 -> V_116 ) ;
V_279 . V_165 = F_18 ( V_23 -> V_114 ) ;
V_23 -> V_19 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_305 ,
sizeof( V_279 ) , & V_279 ) ;
}
static void F_133 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
if ( ! F_89 ( V_13 -> V_8 , V_23 -> V_79 ) )
return;
if ( ! V_23 -> V_20 ) {
F_130 ( V_23 ) ;
return;
}
if ( V_23 -> V_45 == V_78 )
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
struct V_306 V_279 ;
if ( V_13 -> V_307 & V_308 )
return;
V_279 . type = F_18 ( V_309 ) ;
V_13 -> V_307 |= V_308 ;
V_13 -> V_310 = F_91 ( V_13 ) ;
F_137 ( & V_13 -> V_311 , V_312 ) ;
F_83 ( V_13 , V_13 -> V_310 , V_313 ,
sizeof( V_279 ) , & V_279 ) ;
}
static void F_138 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
if ( V_13 -> V_8 -> type == V_2 ) {
F_133 ( V_23 ) ;
return;
}
if ( ! ( V_13 -> V_307 & V_308 ) ) {
F_136 ( V_13 ) ;
return;
}
if ( ! ( V_13 -> V_307 & V_314 ) )
return;
if ( F_88 ( V_23 , true ) &&
F_120 ( V_23 ) )
F_134 ( V_23 ) ;
}
static inline int F_139 ( T_7 V_147 , T_9 V_315 )
{
T_8 V_316 = V_317 ;
if ( ! V_318 )
V_316 |= V_319 | V_320 ;
switch ( V_147 ) {
case V_150 :
return V_319 & V_315 & V_316 ;
case V_154 :
return V_320 & V_315 & V_316 ;
default:
return 0x00 ;
}
}
static void F_86 ( struct V_11 * V_23 , int V_24 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_321 V_279 ;
if ( ! V_13 )
return;
if ( V_23 -> V_147 == V_150 && V_23 -> V_45 == V_75 ) {
F_32 ( V_23 ) ;
F_78 ( V_23 ) ;
F_79 ( V_23 ) ;
}
if ( V_23 -> V_17 == V_322 ) {
F_22 ( V_23 , V_163 ) ;
return;
}
V_279 . V_16 = F_18 ( V_23 -> V_16 ) ;
V_279 . V_17 = F_18 ( V_23 -> V_17 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_323 ,
sizeof( V_279 ) , & V_279 ) ;
F_25 ( V_23 , V_163 , V_24 ) ;
}
static void F_140 ( struct V_12 * V_13 )
{
struct V_11 * V_23 , * V_324 ;
F_23 ( L_14 , V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_141 (chan, tmp, &conn->chan_l, list) {
F_9 ( V_23 ) ;
if ( V_23 -> V_39 != V_122 ) {
F_130 ( V_23 ) ;
F_48 ( V_23 ) ;
continue;
}
if ( V_23 -> V_45 == V_78 ) {
if ( ! F_88 ( V_23 , true ) ||
! F_120 ( V_23 ) ) {
F_48 ( V_23 ) ;
continue;
}
if ( ! F_139 ( V_23 -> V_147 , V_13 -> V_315 )
&& F_70 ( V_325 ,
& V_23 -> V_92 ) ) {
F_47 ( V_23 , V_326 ) ;
F_48 ( V_23 ) ;
continue;
}
F_134 ( V_23 ) ;
} else if ( V_23 -> V_45 == V_174 ) {
struct V_167 V_158 ;
char V_327 [ 128 ] ;
V_158 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_158 . V_16 = F_18 ( V_23 -> V_17 ) ;
if ( F_88 ( V_23 , false ) ) {
if ( F_70 ( V_160 , & V_23 -> V_109 ) ) {
V_158 . V_159 = F_18 ( V_328 ) ;
V_158 . V_169 = F_18 ( V_329 ) ;
V_23 -> V_46 -> V_330 ( V_23 ) ;
} else {
F_22 ( V_23 , V_76 ) ;
V_158 . V_159 = F_18 ( V_331 ) ;
V_158 . V_169 = F_18 ( V_170 ) ;
}
} else {
V_158 . V_159 = F_18 ( V_328 ) ;
V_158 . V_169 = F_18 ( V_332 ) ;
}
F_83 ( V_13 , V_23 -> V_19 , V_171 ,
sizeof( V_158 ) , & V_158 ) ;
if ( F_70 ( V_333 , & V_23 -> V_92 ) ||
V_158 . V_159 != V_331 ) {
F_48 ( V_23 ) ;
continue;
}
F_57 ( V_333 , & V_23 -> V_92 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_334 ,
F_142 ( V_23 , V_327 ) , V_327 ) ;
V_23 -> V_335 ++ ;
}
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static void F_143 ( struct V_12 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_267 * V_195 = V_8 -> V_195 ;
F_23 ( L_15 , V_195 -> V_336 , V_13 ) ;
if ( V_8 -> V_337 )
F_89 ( V_8 , V_8 -> V_338 ) ;
if ( V_8 -> V_339 == V_340 &&
( V_8 -> V_341 < V_8 -> V_342 ||
V_8 -> V_341 > V_8 -> V_343 ) ) {
struct V_344 V_279 ;
V_279 . V_345 = F_18 ( V_8 -> V_342 ) ;
V_279 . V_346 = F_18 ( V_8 -> V_343 ) ;
V_279 . V_347 = F_18 ( V_8 -> V_348 ) ;
V_279 . V_349 = F_18 ( V_8 -> V_350 ) ;
F_83 ( V_13 , F_91 ( V_13 ) ,
V_351 , sizeof( V_279 ) , & V_279 ) ;
}
}
static void F_144 ( struct V_12 * V_13 )
{
struct V_11 * V_23 ;
struct V_7 * V_8 = V_13 -> V_8 ;
F_23 ( L_14 , V_13 ) ;
if ( V_8 -> type == V_123 )
F_136 ( V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
F_9 ( V_23 ) ;
if ( V_23 -> V_17 == V_322 ) {
F_48 ( V_23 ) ;
continue;
}
if ( V_8 -> type == V_2 ) {
F_133 ( V_23 ) ;
} else if ( V_23 -> V_39 != V_122 ) {
if ( V_13 -> V_307 & V_314 )
F_130 ( V_23 ) ;
} else if ( V_23 -> V_45 == V_78 ) {
F_138 ( V_23 ) ;
}
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
if ( V_8 -> type == V_2 )
F_143 ( V_13 ) ;
F_145 ( V_8 -> V_195 -> V_352 , & V_13 -> V_353 ) ;
}
static void F_146 ( struct V_12 * V_13 , int V_24 )
{
struct V_11 * V_23 ;
F_23 ( L_14 , V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
if ( F_70 ( V_354 , & V_23 -> V_109 ) )
F_26 ( V_23 , V_24 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static void F_147 ( struct V_71 * V_72 )
{
struct V_12 * V_13 = F_46 ( V_72 , struct V_12 ,
V_311 . V_72 ) ;
V_13 -> V_307 |= V_314 ;
V_13 -> V_310 = 0 ;
F_140 ( V_13 ) ;
}
int F_148 ( struct V_12 * V_13 , struct V_355 * V_356 )
{
struct V_267 * V_195 = V_13 -> V_8 -> V_195 ;
int V_357 ;
F_149 ( V_195 ) ;
if ( ! F_150 ( & V_356 -> V_64 ) ) {
V_357 = - V_36 ;
goto V_358;
}
if ( ! V_13 -> V_202 ) {
V_357 = - V_359 ;
goto V_358;
}
V_357 = V_356 -> V_360 ( V_13 , V_356 ) ;
if ( V_357 )
goto V_358;
F_54 ( & V_356 -> V_64 , & V_13 -> V_361 ) ;
V_357 = 0 ;
V_358:
F_151 ( V_195 ) ;
return V_357 ;
}
void F_152 ( struct V_12 * V_13 , struct V_355 * V_356 )
{
struct V_267 * V_195 = V_13 -> V_8 -> V_195 ;
F_149 ( V_195 ) ;
if ( F_150 ( & V_356 -> V_64 ) )
goto V_358;
F_153 ( & V_356 -> V_64 ) ;
V_356 -> remove ( V_13 , V_356 ) ;
V_358:
F_151 ( V_195 ) ;
}
static void F_154 ( struct V_12 * V_13 )
{
struct V_355 * V_356 ;
while ( ! F_150 ( & V_13 -> V_361 ) ) {
V_356 = F_155 ( & V_13 -> V_361 , struct V_355 , V_64 ) ;
F_153 ( & V_356 -> V_64 ) ;
V_356 -> remove ( V_13 , V_356 ) ;
}
}
static void F_156 ( struct V_7 * V_8 , int V_24 )
{
struct V_12 * V_13 = V_8 -> V_362 ;
struct V_11 * V_23 , * V_363 ;
if ( ! V_13 )
return;
F_23 ( L_16 , V_8 , V_13 , V_24 ) ;
F_97 ( V_13 -> V_364 ) ;
F_77 ( & V_13 -> V_365 ) ;
if ( F_157 ( & V_13 -> V_353 ) )
F_158 ( & V_13 -> V_353 ) ;
if ( F_157 ( & V_13 -> V_155 ) )
F_158 ( & V_13 -> V_155 ) ;
F_154 ( V_13 ) ;
V_8 -> V_366 = 0 ;
F_8 ( & V_13 -> V_18 ) ;
F_141 (chan, l, &conn->chan_l, list) {
F_60 ( V_23 ) ;
F_9 ( V_23 ) ;
F_73 ( V_23 , V_24 ) ;
F_48 ( V_23 ) ;
V_23 -> V_46 -> V_82 ( V_23 ) ;
F_49 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
F_159 ( V_13 -> V_202 ) ;
if ( V_13 -> V_307 & V_308 )
F_160 ( & V_13 -> V_311 ) ;
V_8 -> V_362 = NULL ;
V_13 -> V_202 = NULL ;
F_161 ( V_13 ) ;
}
static void F_162 ( struct V_90 * V_367 )
{
struct V_12 * V_13 = F_46 ( V_367 , struct V_12 , V_367 ) ;
F_163 ( V_13 -> V_8 ) ;
F_40 ( V_13 ) ;
}
struct V_12 * F_164 ( struct V_12 * V_13 )
{
F_62 ( & V_13 -> V_367 ) ;
return V_13 ;
}
void F_161 ( struct V_12 * V_13 )
{
F_63 ( & V_13 -> V_367 , F_162 ) ;
}
static struct V_11 * F_165 ( int V_45 , T_3 V_20 ,
T_4 * V_21 ,
T_4 * V_156 ,
T_1 V_1 )
{
struct V_11 * V_15 , * V_368 = NULL ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
if ( V_45 && V_15 -> V_45 != V_45 )
continue;
if ( V_1 == V_123 && V_15 -> V_9 != V_6 )
continue;
if ( V_1 == V_2 && V_15 -> V_9 == V_6 )
continue;
if ( V_15 -> V_20 == V_20 ) {
int V_369 , V_370 ;
int V_371 , V_372 ;
V_369 = ! F_15 ( & V_15 -> V_21 , V_21 ) ;
V_370 = ! F_15 ( & V_15 -> V_156 , V_156 ) ;
if ( V_369 && V_370 ) {
F_60 ( V_15 ) ;
F_123 ( & V_25 ) ;
return V_15 ;
}
V_371 = ! F_15 ( & V_15 -> V_21 , V_373 ) ;
V_372 = ! F_15 ( & V_15 -> V_156 , V_373 ) ;
if ( ( V_369 && V_372 ) || ( V_371 && V_370 ) ||
( V_371 && V_372 ) )
V_368 = V_15 ;
}
}
if ( V_368 )
F_60 ( V_368 ) ;
F_123 ( & V_25 ) ;
return V_368 ;
}
static void F_166 ( struct V_71 * V_72 )
{
struct V_11 * V_23 = F_46 ( V_72 , struct V_11 ,
V_48 . V_72 ) ;
F_23 ( L_3 , V_23 ) ;
F_9 ( V_23 ) ;
if ( ! V_23 -> V_13 ) {
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
return;
}
F_129 ( V_23 , NULL , NULL , V_374 ) ;
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
}
static void F_167 ( struct V_71 * V_72 )
{
struct V_11 * V_23 = F_46 ( V_72 , struct V_11 ,
V_50 . V_72 ) ;
F_23 ( L_3 , V_23 ) ;
F_9 ( V_23 ) ;
if ( ! V_23 -> V_13 ) {
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
return;
}
F_129 ( V_23 , NULL , NULL , V_375 ) ;
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
}
static void F_168 ( struct V_11 * V_23 ,
struct V_53 * V_376 )
{
struct V_52 * V_56 ;
struct V_210 * V_211 ;
F_23 ( L_17 , V_23 , V_376 ) ;
if ( F_95 ( V_23 ) )
return;
F_169 ( V_376 , & V_23 -> V_119 ) ;
while ( ! F_170 ( & V_23 -> V_119 ) ) {
V_56 = F_171 ( & V_23 -> V_119 ) ;
F_35 ( V_56 ) -> V_57 . V_285 = 1 ;
V_211 = & F_35 ( V_56 ) -> V_57 ;
V_211 -> V_212 = 0 ;
V_211 -> V_58 = V_23 -> V_377 ;
F_106 ( V_23 , V_211 , V_56 ) ;
if ( V_23 -> V_93 == V_94 ) {
T_2 V_93 = F_114 ( 0 , ( T_1 * ) V_56 -> V_194 , V_56 -> V_193 ) ;
F_108 ( V_93 , F_113 ( V_56 , V_255 ) ) ;
}
F_96 ( V_23 , V_56 ) ;
F_23 ( L_18 , V_211 -> V_58 ) ;
V_23 -> V_377 = F_172 ( V_23 , V_23 -> V_377 ) ;
V_23 -> V_378 ++ ;
}
}
static int F_173 ( struct V_11 * V_23 )
{
struct V_52 * V_56 , * V_379 ;
struct V_210 * V_211 ;
int V_380 = 0 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_45 != V_75 )
return - V_381 ;
if ( F_70 ( V_293 , & V_23 -> V_258 ) )
return 0 ;
if ( F_95 ( V_23 ) )
return 0 ;
while ( V_23 -> V_382 &&
V_23 -> V_383 < V_23 -> V_101 &&
V_23 -> V_289 == V_290 ) {
V_56 = V_23 -> V_382 ;
F_35 ( V_56 ) -> V_57 . V_285 = 1 ;
V_211 = & F_35 ( V_56 ) -> V_57 ;
if ( F_116 ( V_257 , & V_23 -> V_258 ) )
V_211 -> V_215 = 1 ;
V_211 -> V_212 = V_23 -> V_265 ;
V_23 -> V_263 = V_23 -> V_265 ;
V_211 -> V_58 = V_23 -> V_377 ;
F_106 ( V_23 , V_211 , V_56 ) ;
if ( V_23 -> V_93 == V_94 ) {
T_2 V_93 = F_114 ( 0 , ( T_1 * ) V_56 -> V_194 , V_56 -> V_193 ) ;
F_108 ( V_93 , F_113 ( V_56 , V_255 ) ) ;
}
V_379 = F_174 ( V_56 , V_65 ) ;
if ( ! V_379 )
break;
F_27 ( V_23 ) ;
V_23 -> V_377 = F_172 ( V_23 , V_23 -> V_377 ) ;
V_23 -> V_383 ++ ;
V_23 -> V_378 ++ ;
V_380 ++ ;
if ( F_175 ( & V_23 -> V_119 , V_56 ) )
V_23 -> V_382 = NULL ;
else
V_23 -> V_382 = F_176 ( & V_23 -> V_119 , V_56 ) ;
F_96 ( V_23 , V_379 ) ;
F_23 ( L_18 , V_211 -> V_58 ) ;
}
F_23 ( L_19 , V_380 ,
V_23 -> V_383 , F_177 ( & V_23 -> V_119 ) ) ;
return V_380 ;
}
static void F_178 ( struct V_11 * V_23 )
{
struct V_210 V_211 ;
struct V_52 * V_56 ;
struct V_52 * V_379 ;
T_2 V_55 ;
F_23 ( L_3 , V_23 ) ;
if ( F_70 ( V_293 , & V_23 -> V_258 ) )
return;
if ( F_95 ( V_23 ) )
return;
while ( V_23 -> V_153 . V_54 != V_68 ) {
V_55 = F_42 ( & V_23 -> V_153 ) ;
V_56 = F_33 ( & V_23 -> V_119 , V_55 ) ;
if ( ! V_56 ) {
F_23 ( L_20 ,
V_55 ) ;
continue;
}
F_35 ( V_56 ) -> V_57 . V_285 ++ ;
V_211 = F_35 ( V_56 ) -> V_57 ;
if ( V_23 -> V_95 != 0 &&
F_35 ( V_56 ) -> V_57 . V_285 > V_23 -> V_95 ) {
F_23 ( L_21 , V_23 -> V_95 ) ;
F_86 ( V_23 , V_326 ) ;
F_43 ( & V_23 -> V_153 ) ;
break;
}
V_211 . V_212 = V_23 -> V_265 ;
if ( F_116 ( V_257 , & V_23 -> V_258 ) )
V_211 . V_215 = 1 ;
else
V_211 . V_215 = 0 ;
if ( F_179 ( V_56 ) ) {
V_379 = F_180 ( V_56 , V_65 ) ;
} else {
V_379 = F_174 ( V_56 , V_65 ) ;
}
if ( ! V_379 ) {
F_43 ( & V_23 -> V_153 ) ;
break;
}
if ( F_70 ( V_245 , & V_23 -> V_109 ) ) {
F_107 ( F_104 ( & V_211 ) ,
V_379 -> V_194 + V_249 ) ;
} else {
F_108 ( F_105 ( & V_211 ) ,
V_379 -> V_194 + V_249 ) ;
}
if ( V_23 -> V_93 == V_94 ) {
T_2 V_93 = F_114 ( 0 , ( T_1 * ) V_379 -> V_194 ,
V_379 -> V_193 - V_255 ) ;
F_108 ( V_93 , F_181 ( V_379 ) -
V_255 ) ;
}
F_96 ( V_23 , V_379 ) ;
F_23 ( L_22 , V_211 . V_58 ) ;
V_23 -> V_263 = V_23 -> V_265 ;
}
}
static void F_182 ( struct V_11 * V_23 ,
struct V_210 * V_211 )
{
F_23 ( L_10 , V_23 , V_211 ) ;
F_44 ( & V_23 -> V_153 , V_211 -> V_212 ) ;
F_178 ( V_23 ) ;
}
static void F_183 ( struct V_11 * V_23 ,
struct V_210 * V_211 )
{
struct V_52 * V_56 ;
F_23 ( L_10 , V_23 , V_211 ) ;
if ( V_211 -> V_220 )
F_57 ( V_257 , & V_23 -> V_258 ) ;
F_43 ( & V_23 -> V_153 ) ;
if ( F_70 ( V_293 , & V_23 -> V_258 ) )
return;
if ( V_23 -> V_383 ) {
F_34 (&chan->tx_q, skb) {
if ( F_35 ( V_56 ) -> V_57 . V_58 == V_211 -> V_212 ||
V_56 == V_23 -> V_382 )
break;
}
F_184 (&chan->tx_q, skb) {
if ( V_56 == V_23 -> V_382 )
break;
F_44 ( & V_23 -> V_153 ,
F_35 ( V_56 ) -> V_57 . V_58 ) ;
}
F_178 ( V_23 ) ;
}
}
static void F_185 ( struct V_11 * V_23 )
{
struct V_210 V_211 ;
T_2 V_384 = F_186 ( V_23 , V_23 -> V_265 ,
V_23 -> V_263 ) ;
int V_385 ;
F_23 ( L_23 ,
V_23 , V_23 -> V_263 , V_23 -> V_265 ) ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
V_211 . V_219 = 1 ;
if ( F_70 ( V_264 , & V_23 -> V_258 ) &&
V_23 -> V_291 == V_386 ) {
F_79 ( V_23 ) ;
V_211 . V_223 = V_261 ;
V_211 . V_212 = V_23 -> V_265 ;
F_115 ( V_23 , & V_211 ) ;
} else {
if ( ! F_70 ( V_293 , & V_23 -> V_258 ) ) {
F_173 ( V_23 ) ;
if ( V_23 -> V_265 == V_23 -> V_263 )
V_384 = 0 ;
}
V_385 = V_23 -> V_102 ;
V_385 += V_385 << 1 ;
V_385 >>= 2 ;
F_23 ( L_24 , V_384 ,
V_385 ) ;
if ( V_384 >= V_385 ) {
F_79 ( V_23 ) ;
V_211 . V_223 = V_259 ;
V_211 . V_212 = V_23 -> V_265 ;
F_115 ( V_23 , & V_211 ) ;
V_384 = 0 ;
}
if ( V_384 )
F_187 ( V_23 ) ;
}
}
static inline int F_188 ( struct V_11 * V_23 ,
struct V_387 * V_388 , int V_193 ,
int V_389 , struct V_52 * V_56 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_52 * * V_390 ;
int V_380 = 0 ;
if ( ! F_189 ( F_113 ( V_56 , V_389 ) , V_389 , & V_388 -> V_391 ) )
return - V_392 ;
V_380 += V_389 ;
V_193 -= V_389 ;
V_390 = & F_190 ( V_56 ) -> V_393 ;
while ( V_193 ) {
struct V_52 * V_324 ;
V_389 = F_66 (unsigned int, conn->mtu, len) ;
V_324 = V_23 -> V_46 -> V_394 ( V_23 , 0 , V_389 ,
V_388 -> V_395 & V_396 ) ;
if ( F_118 ( V_324 ) )
return F_191 ( V_324 ) ;
* V_390 = V_324 ;
if ( ! F_189 ( F_113 ( * V_390 , V_389 ) , V_389 ,
& V_388 -> V_391 ) )
return - V_392 ;
V_380 += V_389 ;
V_193 -= V_389 ;
V_56 -> V_193 += ( * V_390 ) -> V_193 ;
V_56 -> V_397 += ( * V_390 ) -> V_193 ;
V_390 = & ( * V_390 ) -> V_398 ;
}
return V_380 ;
}
static struct V_52 * F_192 ( struct V_11 * V_23 ,
struct V_387 * V_388 , T_6 V_193 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_52 * V_56 ;
int V_24 , V_389 , V_254 = V_249 + V_399 ;
struct V_252 * V_253 ;
F_23 ( L_25 , V_23 ,
F_69 ( V_23 -> V_20 ) , V_193 ) ;
V_389 = F_66 (unsigned int, (conn->mtu - hlen), len) ;
V_56 = V_23 -> V_46 -> V_394 ( V_23 , V_254 , V_389 ,
V_388 -> V_395 & V_396 ) ;
if ( F_118 ( V_56 ) )
return V_56 ;
V_253 = (struct V_252 * ) F_113 ( V_56 , V_249 ) ;
V_253 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_253 -> V_193 = F_18 ( V_193 + V_399 ) ;
F_193 ( V_23 -> V_20 , ( T_3 * ) F_113 ( V_56 , V_399 ) ) ;
V_24 = F_188 ( V_23 , V_388 , V_193 , V_389 , V_56 ) ;
if ( F_194 ( V_24 < 0 ) ) {
F_97 ( V_56 ) ;
return F_112 ( V_24 ) ;
}
return V_56 ;
}
static struct V_52 * F_195 ( struct V_11 * V_23 ,
struct V_387 * V_388 , T_6 V_193 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_52 * V_56 ;
int V_24 , V_389 ;
struct V_252 * V_253 ;
F_23 ( L_26 , V_23 , V_193 ) ;
V_389 = F_66 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_56 = V_23 -> V_46 -> V_394 ( V_23 , V_249 , V_389 ,
V_388 -> V_395 & V_396 ) ;
if ( F_118 ( V_56 ) )
return V_56 ;
V_253 = (struct V_252 * ) F_113 ( V_56 , V_249 ) ;
V_253 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_253 -> V_193 = F_18 ( V_193 ) ;
V_24 = F_188 ( V_23 , V_388 , V_193 , V_389 , V_56 ) ;
if ( F_194 ( V_24 < 0 ) ) {
F_97 ( V_56 ) ;
return F_112 ( V_24 ) ;
}
return V_56 ;
}
static struct V_52 * F_196 ( struct V_11 * V_23 ,
struct V_387 * V_388 , T_6 V_193 ,
T_2 V_400 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_52 * V_56 ;
int V_24 , V_389 , V_254 ;
struct V_252 * V_253 ;
F_23 ( L_26 , V_23 , V_193 ) ;
if ( ! V_13 )
return F_112 ( - V_381 ) ;
V_254 = F_109 ( V_23 ) ;
if ( V_400 )
V_254 += V_401 ;
if ( V_23 -> V_93 == V_94 )
V_254 += V_255 ;
V_389 = F_66 (unsigned int, (conn->mtu - hlen), len) ;
V_56 = V_23 -> V_46 -> V_394 ( V_23 , V_254 , V_389 ,
V_388 -> V_395 & V_396 ) ;
if ( F_118 ( V_56 ) )
return V_56 ;
V_253 = (struct V_252 * ) F_113 ( V_56 , V_249 ) ;
V_253 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_253 -> V_193 = F_18 ( V_193 + ( V_254 - V_249 ) ) ;
if ( F_70 ( V_245 , & V_23 -> V_109 ) )
F_107 ( 0 , F_113 ( V_56 , V_246 ) ) ;
else
F_108 ( 0 , F_113 ( V_56 , V_247 ) ) ;
if ( V_400 )
F_108 ( V_400 , F_113 ( V_56 , V_401 ) ) ;
V_24 = F_188 ( V_23 , V_388 , V_193 , V_389 , V_56 ) ;
if ( F_194 ( V_24 < 0 ) ) {
F_97 ( V_56 ) ;
return F_112 ( V_24 ) ;
}
F_35 ( V_56 ) -> V_57 . V_93 = V_23 -> V_93 ;
F_35 ( V_56 ) -> V_57 . V_285 = 0 ;
return V_56 ;
}
static int F_197 ( struct V_11 * V_23 ,
struct V_53 * V_402 ,
struct V_387 * V_388 , T_6 V_193 )
{
struct V_52 * V_56 ;
T_2 V_112 ;
T_6 V_403 ;
T_1 V_226 ;
F_23 ( L_27 , V_23 , V_388 , V_193 ) ;
V_403 = V_23 -> V_13 -> V_164 ;
if ( ! V_23 -> V_206 )
V_403 = F_66 ( T_6 , V_403 , V_404 ) ;
if ( V_23 -> V_93 )
V_403 -= V_255 ;
V_403 -= F_109 ( V_23 ) ;
V_403 = F_66 ( T_6 , V_403 , V_23 -> V_405 ) ;
if ( V_193 <= V_403 ) {
V_226 = V_406 ;
V_112 = 0 ;
V_403 = V_193 ;
} else {
V_226 = V_407 ;
V_112 = V_193 ;
}
while ( V_193 > 0 ) {
V_56 = F_196 ( V_23 , V_388 , V_403 , V_112 ) ;
if ( F_118 ( V_56 ) ) {
F_198 ( V_402 ) ;
return F_191 ( V_56 ) ;
}
F_35 ( V_56 ) -> V_57 . V_226 = V_226 ;
F_199 ( V_402 , V_56 ) ;
V_193 -= V_403 ;
if ( V_112 )
V_112 = 0 ;
if ( V_193 <= V_403 ) {
V_226 = V_408 ;
V_403 = V_193 ;
} else {
V_226 = V_409 ;
}
}
return 0 ;
}
static struct V_52 * F_200 ( struct V_11 * V_23 ,
struct V_387 * V_388 ,
T_6 V_193 , T_2 V_400 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_52 * V_56 ;
int V_24 , V_389 , V_254 ;
struct V_252 * V_253 ;
F_23 ( L_26 , V_23 , V_193 ) ;
if ( ! V_13 )
return F_112 ( - V_381 ) ;
V_254 = V_249 ;
if ( V_400 )
V_254 += V_401 ;
V_389 = F_66 (unsigned int, (conn->mtu - hlen), len) ;
V_56 = V_23 -> V_46 -> V_394 ( V_23 , V_254 , V_389 ,
V_388 -> V_395 & V_396 ) ;
if ( F_118 ( V_56 ) )
return V_56 ;
V_253 = (struct V_252 * ) F_113 ( V_56 , V_249 ) ;
V_253 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_253 -> V_193 = F_18 ( V_193 + ( V_254 - V_249 ) ) ;
if ( V_400 )
F_108 ( V_400 , F_113 ( V_56 , V_401 ) ) ;
V_24 = F_188 ( V_23 , V_388 , V_193 , V_389 , V_56 ) ;
if ( F_194 ( V_24 < 0 ) ) {
F_97 ( V_56 ) ;
return F_112 ( V_24 ) ;
}
return V_56 ;
}
static int F_201 ( struct V_11 * V_23 ,
struct V_53 * V_402 ,
struct V_387 * V_388 , T_6 V_193 )
{
struct V_52 * V_56 ;
T_6 V_403 ;
T_2 V_112 ;
F_23 ( L_27 , V_23 , V_388 , V_193 ) ;
V_112 = V_193 ;
V_403 = V_23 -> V_405 - V_401 ;
while ( V_193 > 0 ) {
if ( V_193 <= V_403 )
V_403 = V_193 ;
V_56 = F_200 ( V_23 , V_388 , V_403 , V_112 ) ;
if ( F_118 ( V_56 ) ) {
F_198 ( V_402 ) ;
return F_191 ( V_56 ) ;
}
F_199 ( V_402 , V_56 ) ;
V_193 -= V_403 ;
if ( V_112 ) {
V_112 = 0 ;
V_403 += V_401 ;
}
}
return 0 ;
}
int F_202 ( struct V_11 * V_23 , struct V_387 * V_388 , T_6 V_193 )
{
struct V_52 * V_56 ;
int V_24 ;
struct V_53 V_402 ;
if ( ! V_23 -> V_13 )
return - V_381 ;
if ( V_23 -> V_39 == V_124 ) {
V_56 = F_192 ( V_23 , V_388 , V_193 ) ;
if ( F_118 ( V_56 ) )
return F_191 ( V_56 ) ;
if ( V_23 -> V_45 != V_75 ) {
F_97 ( V_56 ) ;
return - V_381 ;
}
F_96 ( V_23 , V_56 ) ;
return V_193 ;
}
switch ( V_23 -> V_147 ) {
case V_149 :
if ( V_193 > V_23 -> V_37 )
return - V_410 ;
if ( ! V_23 -> V_113 )
return - V_411 ;
F_203 ( & V_402 ) ;
V_24 = F_201 ( V_23 , & V_402 , V_388 , V_193 ) ;
if ( V_23 -> V_45 != V_75 ) {
F_198 ( & V_402 ) ;
V_24 = - V_381 ;
}
if ( V_24 )
return V_24 ;
F_169 ( & V_402 , & V_23 -> V_119 ) ;
while ( V_23 -> V_113 && ! F_170 ( & V_23 -> V_119 ) ) {
F_96 ( V_23 , F_171 ( & V_23 -> V_119 ) ) ;
V_23 -> V_113 -- ;
}
if ( ! V_23 -> V_113 )
V_23 -> V_46 -> V_301 ( V_23 ) ;
V_24 = V_193 ;
break;
case V_148 :
if ( V_193 > V_23 -> V_37 )
return - V_410 ;
V_56 = F_195 ( V_23 , V_388 , V_193 ) ;
if ( F_118 ( V_56 ) )
return F_191 ( V_56 ) ;
if ( V_23 -> V_45 != V_75 ) {
F_97 ( V_56 ) ;
return - V_381 ;
}
F_96 ( V_23 , V_56 ) ;
V_24 = V_193 ;
break;
case V_150 :
case V_154 :
if ( V_193 > V_23 -> V_37 ) {
V_24 = - V_410 ;
break;
}
F_203 ( & V_402 ) ;
V_24 = F_197 ( V_23 , & V_402 , V_388 , V_193 ) ;
if ( V_23 -> V_45 != V_75 ) {
F_198 ( & V_402 ) ;
V_24 = - V_381 ;
}
if ( V_24 )
break;
if ( V_23 -> V_147 == V_150 )
F_129 ( V_23 , NULL , & V_402 , V_412 ) ;
else
F_168 ( V_23 , & V_402 ) ;
V_24 = V_193 ;
F_198 ( & V_402 ) ;
break;
default:
F_23 ( L_28 , V_23 -> V_147 ) ;
V_24 = - V_413 ;
}
return V_24 ;
}
static void F_204 ( struct V_11 * V_23 , T_2 V_58 )
{
struct V_210 V_211 ;
T_2 V_55 ;
F_23 ( L_29 , V_23 , V_58 ) ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
V_211 . V_219 = 1 ;
V_211 . V_223 = V_262 ;
for ( V_55 = V_23 -> V_286 ; V_55 != V_58 ;
V_55 = F_172 ( V_23 , V_55 ) ) {
if ( ! F_33 ( & V_23 -> V_151 , V_55 ) ) {
V_211 . V_212 = V_55 ;
F_115 ( V_23 , & V_211 ) ;
F_44 ( & V_23 -> V_152 , V_55 ) ;
}
}
V_23 -> V_286 = F_172 ( V_23 , V_58 ) ;
}
static void F_205 ( struct V_11 * V_23 )
{
struct V_210 V_211 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_152 . V_69 == V_68 )
return;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
V_211 . V_219 = 1 ;
V_211 . V_223 = V_262 ;
V_211 . V_212 = V_23 -> V_152 . V_69 ;
F_115 ( V_23 , & V_211 ) ;
}
static void F_206 ( struct V_11 * V_23 , T_2 V_58 )
{
struct V_210 V_211 ;
T_2 V_414 ;
T_2 V_55 ;
F_23 ( L_29 , V_23 , V_58 ) ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
V_211 . V_219 = 1 ;
V_211 . V_223 = V_262 ;
V_414 = V_23 -> V_152 . V_54 ;
do {
V_55 = F_42 ( & V_23 -> V_152 ) ;
if ( V_55 == V_58 || V_55 == V_68 )
break;
V_211 . V_212 = V_55 ;
F_115 ( V_23 , & V_211 ) ;
F_44 ( & V_23 -> V_152 , V_55 ) ;
} while ( V_23 -> V_152 . V_54 != V_414 );
}
static void F_207 ( struct V_11 * V_23 , T_2 V_212 )
{
struct V_52 * V_415 ;
T_2 V_416 ;
F_23 ( L_30 , V_23 , V_212 ) ;
if ( V_23 -> V_383 == 0 || V_212 == V_23 -> V_417 )
return;
F_23 ( L_31 ,
V_23 -> V_417 , V_23 -> V_383 ) ;
for ( V_416 = V_23 -> V_417 ; V_416 != V_212 ;
V_416 = F_172 ( V_23 , V_416 ) ) {
V_415 = F_33 ( & V_23 -> V_119 , V_416 ) ;
if ( V_415 ) {
F_208 ( V_415 , & V_23 -> V_119 ) ;
F_97 ( V_415 ) ;
V_23 -> V_383 -- ;
}
}
V_23 -> V_417 = V_212 ;
if ( V_23 -> V_383 == 0 )
F_32 ( V_23 ) ;
F_23 ( L_32 , V_23 -> V_383 ) ;
}
static void F_209 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
V_23 -> V_286 = V_23 -> V_265 ;
F_43 ( & V_23 -> V_152 ) ;
F_77 ( & V_23 -> V_151 ) ;
V_23 -> V_291 = V_386 ;
}
static void F_210 ( struct V_11 * V_23 ,
struct V_210 * V_211 ,
struct V_53 * V_376 , T_1 V_418 )
{
F_23 ( L_33 , V_23 , V_211 , V_376 ,
V_418 ) ;
switch ( V_418 ) {
case V_412 :
if ( V_23 -> V_382 == NULL )
V_23 -> V_382 = F_211 ( V_376 ) ;
F_169 ( V_376 , & V_23 -> V_119 ) ;
F_173 ( V_23 ) ;
break;
case V_419 :
F_23 ( L_34 ) ;
F_57 ( V_264 , & V_23 -> V_258 ) ;
if ( V_23 -> V_291 == V_420 ) {
F_209 ( V_23 ) ;
}
F_185 ( V_23 ) ;
break;
case V_421 :
F_23 ( L_35 ) ;
F_117 ( V_264 , & V_23 -> V_258 ) ;
if ( F_70 ( V_260 , & V_23 -> V_258 ) ) {
struct V_210 V_422 ;
memset ( & V_422 , 0 , sizeof( V_422 ) ) ;
V_422 . V_219 = 1 ;
V_422 . V_223 = V_259 ;
V_422 . V_220 = 1 ;
V_422 . V_212 = V_23 -> V_265 ;
F_115 ( V_23 , & V_422 ) ;
V_23 -> V_284 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_289 = V_423 ;
}
break;
case V_424 :
F_207 ( V_23 , V_211 -> V_212 ) ;
break;
case V_297 :
F_119 ( V_23 , 1 ) ;
V_23 -> V_284 = 1 ;
F_31 ( V_23 ) ;
F_79 ( V_23 ) ;
V_23 -> V_289 = V_423 ;
break;
case V_375 :
F_119 ( V_23 , 1 ) ;
V_23 -> V_284 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_289 = V_423 ;
break;
case V_425 :
break;
default:
break;
}
}
static void F_212 ( struct V_11 * V_23 ,
struct V_210 * V_211 ,
struct V_53 * V_376 , T_1 V_418 )
{
F_23 ( L_33 , V_23 , V_211 , V_376 ,
V_418 ) ;
switch ( V_418 ) {
case V_412 :
if ( V_23 -> V_382 == NULL )
V_23 -> V_382 = F_211 ( V_376 ) ;
F_169 ( V_376 , & V_23 -> V_119 ) ;
break;
case V_419 :
F_23 ( L_34 ) ;
F_57 ( V_264 , & V_23 -> V_258 ) ;
if ( V_23 -> V_291 == V_420 ) {
F_209 ( V_23 ) ;
}
F_185 ( V_23 ) ;
break;
case V_421 :
F_23 ( L_35 ) ;
F_117 ( V_264 , & V_23 -> V_258 ) ;
if ( F_70 ( V_260 , & V_23 -> V_258 ) ) {
struct V_210 V_422 ;
memset ( & V_422 , 0 , sizeof( V_422 ) ) ;
V_422 . V_219 = 1 ;
V_422 . V_223 = V_259 ;
V_422 . V_220 = 1 ;
V_422 . V_212 = V_23 -> V_265 ;
F_115 ( V_23 , & V_422 ) ;
V_23 -> V_284 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_289 = V_423 ;
}
break;
case V_424 :
F_207 ( V_23 , V_211 -> V_212 ) ;
case V_425 :
if ( V_211 && V_211 -> V_215 ) {
F_78 ( V_23 ) ;
if ( V_23 -> V_383 > 0 )
F_27 ( V_23 ) ;
V_23 -> V_284 = 0 ;
V_23 -> V_289 = V_290 ;
F_23 ( L_36 , V_23 -> V_289 ) ;
}
break;
case V_297 :
break;
case V_374 :
if ( V_23 -> V_95 == 0 || V_23 -> V_284 < V_23 -> V_95 ) {
F_119 ( V_23 , 1 ) ;
F_31 ( V_23 ) ;
V_23 -> V_284 ++ ;
} else {
F_86 ( V_23 , V_426 ) ;
}
break;
default:
break;
}
}
static void F_129 ( struct V_11 * V_23 , struct V_210 * V_211 ,
struct V_53 * V_376 , T_1 V_418 )
{
F_23 ( L_37 ,
V_23 , V_211 , V_376 , V_418 , V_23 -> V_289 ) ;
switch ( V_23 -> V_289 ) {
case V_290 :
F_210 ( V_23 , V_211 , V_376 , V_418 ) ;
break;
case V_423 :
F_212 ( V_23 , V_211 , V_376 , V_418 ) ;
break;
default:
break;
}
}
static void F_213 ( struct V_11 * V_23 ,
struct V_210 * V_211 )
{
F_23 ( L_10 , V_23 , V_211 ) ;
F_129 ( V_23 , V_211 , NULL , V_424 ) ;
}
static void F_214 ( struct V_11 * V_23 ,
struct V_210 * V_211 )
{
F_23 ( L_10 , V_23 , V_211 ) ;
F_129 ( V_23 , V_211 , NULL , V_425 ) ;
}
static void F_215 ( struct V_12 * V_13 , struct V_52 * V_56 )
{
struct V_52 * V_427 ;
struct V_11 * V_23 ;
F_23 ( L_14 , V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
if ( V_23 -> V_39 != V_175 )
continue;
if ( F_35 ( V_56 ) -> V_57 . V_23 == V_23 )
continue;
V_427 = F_174 ( V_56 , V_65 ) ;
if ( ! V_427 )
continue;
if ( V_23 -> V_46 -> V_428 ( V_23 , V_427 ) )
F_97 ( V_427 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static struct V_52 * F_92 ( struct V_12 * V_13 , T_1 V_192 ,
T_1 V_19 , T_2 V_429 , void * V_194 )
{
struct V_52 * V_56 , * * V_390 ;
struct V_430 * V_431 ;
struct V_252 * V_253 ;
int V_193 , V_389 ;
F_23 ( L_38 ,
V_13 , V_192 , V_19 , V_429 ) ;
if ( V_13 -> V_164 < V_249 + V_432 )
return NULL ;
V_193 = V_249 + V_432 + V_429 ;
V_389 = F_66 (unsigned int, conn->mtu, len) ;
V_56 = F_111 ( V_389 , V_65 ) ;
if ( ! V_56 )
return NULL ;
V_253 = (struct V_252 * ) F_113 ( V_56 , V_249 ) ;
V_253 -> V_193 = F_18 ( V_432 + V_429 ) ;
if ( V_13 -> V_8 -> type == V_2 )
V_253 -> V_14 = F_18 ( V_433 ) ;
else
V_253 -> V_14 = F_18 ( V_126 ) ;
V_431 = (struct V_430 * ) F_113 ( V_56 , V_432 ) ;
V_431 -> V_192 = V_192 ;
V_431 -> V_19 = V_19 ;
V_431 -> V_193 = F_18 ( V_429 ) ;
if ( V_429 ) {
V_389 -= V_249 + V_432 ;
memcpy ( F_113 ( V_56 , V_389 ) , V_194 , V_389 ) ;
V_194 += V_389 ;
}
V_193 -= V_56 -> V_193 ;
V_390 = & F_190 ( V_56 ) -> V_393 ;
while ( V_193 ) {
V_389 = F_66 (unsigned int, conn->mtu, len) ;
* V_390 = F_111 ( V_389 , V_65 ) ;
if ( ! * V_390 )
goto V_434;
memcpy ( F_113 ( * V_390 , V_389 ) , V_194 , V_389 ) ;
V_193 -= V_389 ;
V_194 += V_389 ;
V_390 = & ( * V_390 ) -> V_398 ;
}
return V_56 ;
V_434:
F_97 ( V_56 ) ;
return NULL ;
}
static inline int F_216 ( void * * V_435 , int * type , int * V_436 ,
unsigned long * V_437 )
{
struct V_438 * V_439 = * V_435 ;
int V_193 ;
V_193 = V_440 + V_439 -> V_193 ;
* V_435 += V_193 ;
* type = V_439 -> type ;
* V_436 = V_439 -> V_193 ;
switch ( V_439 -> V_193 ) {
case 1 :
* V_437 = * ( ( T_1 * ) V_439 -> V_437 ) ;
break;
case 2 :
* V_437 = F_103 ( V_439 -> V_437 ) ;
break;
case 4 :
* V_437 = F_101 ( V_439 -> V_437 ) ;
break;
default:
* V_437 = ( unsigned long ) V_439 -> V_437 ;
break;
}
F_23 ( L_39 , * type , V_439 -> V_193 , * V_437 ) ;
return V_193 ;
}
static void F_217 ( void * * V_435 , T_1 type , T_1 V_193 , unsigned long V_437 )
{
struct V_438 * V_439 = * V_435 ;
F_23 ( L_39 , type , V_193 , V_437 ) ;
V_439 -> type = type ;
V_439 -> V_193 = V_193 ;
switch ( V_193 ) {
case 1 :
* ( ( T_1 * ) V_439 -> V_437 ) = V_437 ;
break;
case 2 :
F_108 ( V_437 , V_439 -> V_437 ) ;
break;
case 4 :
F_107 ( V_437 , V_439 -> V_437 ) ;
break;
default:
memcpy ( V_439 -> V_437 , ( void * ) V_437 , V_193 ) ;
break;
}
* V_435 += V_440 + V_193 ;
}
static void F_218 ( void * * V_435 , struct V_11 * V_23 )
{
struct V_441 V_442 ;
switch ( V_23 -> V_147 ) {
case V_150 :
V_442 . V_189 = V_23 -> V_127 ;
V_442 . V_443 = V_23 -> V_129 ;
V_442 . V_444 = F_18 ( V_23 -> V_131 ) ;
V_442 . V_445 = F_219 ( V_23 -> V_133 ) ;
V_442 . V_446 = F_219 ( V_136 ) ;
V_442 . V_104 = F_219 ( V_138 ) ;
break;
case V_154 :
V_442 . V_189 = 1 ;
V_442 . V_443 = V_130 ;
V_442 . V_444 = F_18 ( V_23 -> V_131 ) ;
V_442 . V_445 = F_219 ( V_23 -> V_133 ) ;
V_442 . V_446 = 0 ;
V_442 . V_104 = 0 ;
break;
default:
return;
}
F_217 ( V_435 , V_447 , sizeof( V_442 ) ,
( unsigned long ) & V_442 ) ;
}
static void F_220 ( struct V_71 * V_72 )
{
struct V_11 * V_23 = F_46 ( V_72 , struct V_11 ,
V_448 . V_72 ) ;
T_2 V_384 ;
F_23 ( L_3 , V_23 ) ;
F_9 ( V_23 ) ;
V_384 = F_186 ( V_23 , V_23 -> V_265 ,
V_23 -> V_263 ) ;
if ( V_384 )
F_119 ( V_23 , 0 ) ;
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
}
int F_221 ( struct V_11 * V_23 )
{
int V_24 ;
V_23 -> V_377 = 0 ;
V_23 -> V_286 = 0 ;
V_23 -> V_417 = 0 ;
V_23 -> V_383 = 0 ;
V_23 -> V_265 = 0 ;
V_23 -> V_378 = 0 ;
V_23 -> V_263 = 0 ;
V_23 -> V_110 = NULL ;
V_23 -> V_111 = NULL ;
V_23 -> V_112 = 0 ;
F_67 ( & V_23 -> V_119 ) ;
V_23 -> V_449 = V_450 ;
V_23 -> V_451 = V_450 ;
V_23 -> V_203 = V_204 ;
V_23 -> V_294 = V_295 ;
if ( V_23 -> V_147 != V_150 )
return 0 ;
V_23 -> V_291 = V_386 ;
V_23 -> V_289 = V_290 ;
F_55 ( & V_23 -> V_50 , F_167 ) ;
F_55 ( & V_23 -> V_48 , F_166 ) ;
F_55 ( & V_23 -> V_448 , F_220 ) ;
F_67 ( & V_23 -> V_151 ) ;
V_24 = F_36 ( & V_23 -> V_152 , V_23 -> V_97 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_36 ( & V_23 -> V_153 , V_23 -> V_101 ) ;
if ( V_24 < 0 )
F_39 ( & V_23 -> V_152 ) ;
return V_24 ;
}
static inline T_7 F_222 ( T_7 V_147 , T_5 V_452 )
{
switch ( V_147 ) {
case V_154 :
case V_150 :
if ( F_139 ( V_147 , V_452 ) )
return V_147 ;
default:
return V_148 ;
}
}
static inline bool F_223 ( struct V_12 * V_13 )
{
return ( ( V_13 -> V_269 & V_270 ) &&
( V_13 -> V_315 & V_453 ) ) ;
}
static inline bool F_224 ( struct V_12 * V_13 )
{
return ( ( V_13 -> V_269 & V_270 ) &&
( V_13 -> V_315 & V_454 ) ) ;
}
static void F_225 ( struct V_11 * V_23 ,
struct V_455 * V_456 )
{
if ( V_23 -> V_449 != V_450 && V_23 -> V_206 ) {
T_10 V_457 = V_23 -> V_206 -> V_195 -> V_458 ;
V_457 = F_226 ( V_457 , 1000 ) ;
V_457 = 3 * V_457 + 500 ;
if ( V_457 > 0xffff )
V_457 = 0xffff ;
V_456 -> V_49 = F_18 ( ( T_2 ) V_457 ) ;
V_456 -> V_51 = V_456 -> V_49 ;
} else {
V_456 -> V_49 = F_18 ( V_106 ) ;
V_456 -> V_51 = F_18 ( V_107 ) ;
}
}
static inline void F_227 ( struct V_11 * V_23 )
{
if ( V_23 -> V_97 > V_98 &&
F_223 ( V_23 -> V_13 ) ) {
F_57 ( V_245 , & V_23 -> V_109 ) ;
V_23 -> V_99 = V_459 ;
} else {
V_23 -> V_97 = F_66 ( T_2 , V_23 -> V_97 ,
V_98 ) ;
V_23 -> V_99 = V_98 ;
}
V_23 -> V_102 = V_23 -> V_97 ;
}
static int F_142 ( struct V_11 * V_23 , void * V_194 )
{
struct V_460 * V_279 = V_194 ;
struct V_455 V_456 = { . V_147 = V_23 -> V_147 } ;
void * V_435 = V_279 -> V_194 ;
T_2 V_61 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_335 || V_23 -> V_461 )
goto V_27;
switch ( V_23 -> V_147 ) {
case V_154 :
case V_150 :
if ( F_70 ( V_325 , & V_23 -> V_92 ) )
break;
if ( F_224 ( V_23 -> V_13 ) )
F_57 ( V_462 , & V_23 -> V_109 ) ;
default:
V_23 -> V_147 = F_222 ( V_456 . V_147 , V_23 -> V_13 -> V_315 ) ;
break;
}
V_27:
if ( V_23 -> V_117 != V_38 )
F_217 ( & V_435 , V_463 , 2 , V_23 -> V_117 ) ;
switch ( V_23 -> V_147 ) {
case V_148 :
if ( V_318 )
break;
if ( ! ( V_23 -> V_13 -> V_315 & V_319 ) &&
! ( V_23 -> V_13 -> V_315 & V_320 ) )
break;
V_456 . V_147 = V_148 ;
V_456 . V_464 = 0 ;
V_456 . V_465 = 0 ;
V_456 . V_49 = 0 ;
V_456 . V_51 = 0 ;
V_456 . V_466 = 0 ;
F_217 ( & V_435 , V_467 , sizeof( V_456 ) ,
( unsigned long ) & V_456 ) ;
break;
case V_150 :
V_456 . V_147 = V_150 ;
V_456 . V_465 = V_23 -> V_95 ;
F_225 ( V_23 , & V_456 ) ;
V_61 = F_66 ( T_2 , V_468 , V_23 -> V_13 -> V_164 -
V_250 - V_401 -
V_255 ) ;
V_456 . V_466 = F_18 ( V_61 ) ;
F_227 ( V_23 ) ;
V_456 . V_464 = F_66 ( T_2 , V_23 -> V_97 ,
V_98 ) ;
F_217 ( & V_435 , V_467 , sizeof( V_456 ) ,
( unsigned long ) & V_456 ) ;
if ( F_70 ( V_462 , & V_23 -> V_109 ) )
F_218 ( & V_435 , V_23 ) ;
if ( F_70 ( V_245 , & V_23 -> V_109 ) )
F_217 ( & V_435 , V_469 , 2 ,
V_23 -> V_97 ) ;
if ( V_23 -> V_13 -> V_315 & V_470 )
if ( V_23 -> V_93 == V_471 ||
F_70 ( V_472 , & V_23 -> V_92 ) ) {
V_23 -> V_93 = V_471 ;
F_217 ( & V_435 , V_473 , 1 ,
V_23 -> V_93 ) ;
}
break;
case V_154 :
F_227 ( V_23 ) ;
V_456 . V_147 = V_154 ;
V_456 . V_464 = 0 ;
V_456 . V_465 = 0 ;
V_456 . V_49 = 0 ;
V_456 . V_51 = 0 ;
V_61 = F_66 ( T_2 , V_468 , V_23 -> V_13 -> V_164 -
V_250 - V_401 -
V_255 ) ;
V_456 . V_466 = F_18 ( V_61 ) ;
F_217 ( & V_435 , V_467 , sizeof( V_456 ) ,
( unsigned long ) & V_456 ) ;
if ( F_70 ( V_462 , & V_23 -> V_109 ) )
F_218 ( & V_435 , V_23 ) ;
if ( V_23 -> V_13 -> V_315 & V_470 )
if ( V_23 -> V_93 == V_471 ||
F_70 ( V_472 , & V_23 -> V_92 ) ) {
V_23 -> V_93 = V_471 ;
F_217 ( & V_435 , V_473 , 1 ,
V_23 -> V_93 ) ;
}
break;
}
V_279 -> V_16 = F_18 ( V_23 -> V_16 ) ;
V_279 -> V_109 = F_18 ( 0 ) ;
return V_435 - V_194 ;
}
static int F_228 ( struct V_11 * V_23 , void * V_194 )
{
struct V_474 * V_158 = V_194 ;
void * V_435 = V_158 -> V_194 ;
void * V_279 = V_23 -> V_475 ;
int V_193 = V_23 -> V_476 ;
int type , V_477 , V_436 ;
unsigned long V_437 ;
struct V_455 V_456 = { . V_147 = V_148 } ;
struct V_441 V_442 ;
T_1 V_478 = 0 ;
T_2 V_164 = V_38 ;
T_2 V_159 = V_479 ;
T_2 V_61 ;
F_23 ( L_3 , V_23 ) ;
while ( V_193 >= V_440 ) {
V_193 -= F_216 ( & V_279 , & type , & V_436 , & V_437 ) ;
V_477 = type & V_480 ;
type &= V_481 ;
switch ( type ) {
case V_463 :
V_164 = V_437 ;
break;
case V_482 :
V_23 -> V_104 = V_437 ;
break;
case V_483 :
break;
case V_467 :
if ( V_436 == sizeof( V_456 ) )
memcpy ( & V_456 , ( void * ) V_437 , V_436 ) ;
break;
case V_473 :
if ( V_437 == V_471 )
F_57 ( V_472 , & V_23 -> V_92 ) ;
break;
case V_447 :
V_478 = 1 ;
if ( V_436 == sizeof( V_442 ) )
memcpy ( & V_442 , ( void * ) V_437 , V_436 ) ;
break;
case V_469 :
if ( ! ( V_23 -> V_13 -> V_269 & V_270 ) )
return - V_77 ;
F_57 ( V_245 , & V_23 -> V_109 ) ;
F_57 ( V_484 , & V_23 -> V_92 ) ;
V_23 -> V_99 = V_459 ;
V_23 -> V_101 = V_437 ;
break;
default:
if ( V_477 )
break;
V_159 = V_485 ;
* ( ( T_1 * ) V_435 ++ ) = type ;
break;
}
}
if ( V_23 -> V_461 || V_23 -> V_335 > 1 )
goto V_27;
switch ( V_23 -> V_147 ) {
case V_154 :
case V_150 :
if ( ! F_70 ( V_325 , & V_23 -> V_92 ) ) {
V_23 -> V_147 = F_222 ( V_456 . V_147 ,
V_23 -> V_13 -> V_315 ) ;
break;
}
if ( V_478 ) {
if ( F_224 ( V_23 -> V_13 ) )
F_57 ( V_462 , & V_23 -> V_109 ) ;
else
return - V_77 ;
}
if ( V_23 -> V_147 != V_456 . V_147 )
return - V_77 ;
break;
}
V_27:
if ( V_23 -> V_147 != V_456 . V_147 ) {
V_159 = V_486 ;
V_456 . V_147 = V_23 -> V_147 ;
if ( V_23 -> V_461 == 1 )
return - V_77 ;
F_217 ( & V_435 , V_467 , sizeof( V_456 ) ,
( unsigned long ) & V_456 ) ;
}
if ( V_159 == V_479 ) {
if ( V_164 < V_487 )
V_159 = V_486 ;
else {
V_23 -> V_37 = V_164 ;
F_57 ( V_488 , & V_23 -> V_92 ) ;
}
F_217 ( & V_435 , V_463 , 2 , V_23 -> V_37 ) ;
if ( V_478 ) {
if ( V_23 -> V_129 != V_489 &&
V_442 . V_443 != V_489 &&
V_442 . V_443 != V_23 -> V_129 ) {
V_159 = V_486 ;
if ( V_23 -> V_335 >= 1 )
return - V_77 ;
F_217 ( & V_435 , V_447 ,
sizeof( V_442 ) ,
( unsigned long ) & V_442 ) ;
} else {
V_159 = V_490 ;
F_57 ( V_491 , & V_23 -> V_92 ) ;
}
}
switch ( V_456 . V_147 ) {
case V_148 :
V_23 -> V_93 = V_471 ;
F_57 ( V_492 , & V_23 -> V_92 ) ;
break;
case V_150 :
if ( ! F_70 ( V_484 , & V_23 -> V_92 ) )
V_23 -> V_101 = V_456 . V_464 ;
else
V_456 . V_464 = V_98 ;
V_23 -> V_100 = V_456 . V_465 ;
V_61 = F_66 ( T_2 , F_229 ( V_456 . V_466 ) ,
V_23 -> V_13 -> V_164 - V_250 -
V_401 - V_255 ) ;
V_456 . V_466 = F_18 ( V_61 ) ;
V_23 -> V_405 = V_61 ;
F_225 ( V_23 , & V_456 ) ;
F_57 ( V_492 , & V_23 -> V_92 ) ;
F_217 ( & V_435 , V_467 ,
sizeof( V_456 ) , ( unsigned long ) & V_456 ) ;
if ( F_70 ( V_462 , & V_23 -> V_109 ) ) {
V_23 -> V_493 = V_442 . V_189 ;
V_23 -> V_494 = V_442 . V_443 ;
V_23 -> V_495 = F_229 ( V_442 . V_444 ) ;
V_23 -> V_496 =
F_230 ( V_442 . V_104 ) ;
V_23 -> V_497 =
F_230 ( V_442 . V_446 ) ;
V_23 -> V_498 =
F_230 ( V_442 . V_445 ) ;
F_217 ( & V_435 , V_447 ,
sizeof( V_442 ) ,
( unsigned long ) & V_442 ) ;
}
break;
case V_154 :
V_61 = F_66 ( T_2 , F_229 ( V_456 . V_466 ) ,
V_23 -> V_13 -> V_164 - V_250 -
V_401 - V_255 ) ;
V_456 . V_466 = F_18 ( V_61 ) ;
V_23 -> V_405 = V_61 ;
F_57 ( V_492 , & V_23 -> V_92 ) ;
F_217 ( & V_435 , V_467 , sizeof( V_456 ) ,
( unsigned long ) & V_456 ) ;
break;
default:
V_159 = V_486 ;
memset ( & V_456 , 0 , sizeof( V_456 ) ) ;
V_456 . V_147 = V_23 -> V_147 ;
}
if ( V_159 == V_479 )
F_57 ( V_499 , & V_23 -> V_92 ) ;
}
V_158 -> V_17 = F_18 ( V_23 -> V_16 ) ;
V_158 -> V_159 = F_18 ( V_159 ) ;
V_158 -> V_109 = F_18 ( 0 ) ;
return V_435 - V_194 ;
}
static int F_231 ( struct V_11 * V_23 , void * V_158 , int V_193 ,
void * V_194 , T_2 * V_159 )
{
struct V_460 * V_279 = V_194 ;
void * V_435 = V_279 -> V_194 ;
int type , V_436 ;
unsigned long V_437 ;
struct V_455 V_456 = { . V_147 = V_148 } ;
struct V_441 V_442 ;
F_23 ( L_40 , V_23 , V_158 , V_193 , V_194 ) ;
while ( V_193 >= V_440 ) {
V_193 -= F_216 ( & V_158 , & type , & V_436 , & V_437 ) ;
switch ( type ) {
case V_463 :
if ( V_437 < V_487 ) {
* V_159 = V_486 ;
V_23 -> V_117 = V_487 ;
} else
V_23 -> V_117 = V_437 ;
F_217 ( & V_435 , V_463 , 2 , V_23 -> V_117 ) ;
break;
case V_482 :
V_23 -> V_104 = V_437 ;
F_217 ( & V_435 , V_482 ,
2 , V_23 -> V_104 ) ;
break;
case V_467 :
if ( V_436 == sizeof( V_456 ) )
memcpy ( & V_456 , ( void * ) V_437 , V_436 ) ;
if ( F_70 ( V_325 , & V_23 -> V_92 ) &&
V_456 . V_147 != V_23 -> V_147 )
return - V_77 ;
V_23 -> V_93 = 0 ;
F_217 ( & V_435 , V_467 ,
sizeof( V_456 ) , ( unsigned long ) & V_456 ) ;
break;
case V_469 :
V_23 -> V_102 = F_66 ( T_2 , V_437 , V_23 -> V_102 ) ;
F_217 ( & V_435 , V_469 , 2 ,
V_23 -> V_97 ) ;
break;
case V_447 :
if ( V_436 == sizeof( V_442 ) )
memcpy ( & V_442 , ( void * ) V_437 , V_436 ) ;
if ( V_23 -> V_129 != V_489 &&
V_442 . V_443 != V_489 &&
V_442 . V_443 != V_23 -> V_129 )
return - V_77 ;
F_217 ( & V_435 , V_447 , sizeof( V_442 ) ,
( unsigned long ) & V_442 ) ;
break;
case V_473 :
if ( * V_159 == V_490 )
if ( V_437 == V_471 )
F_57 ( V_472 ,
& V_23 -> V_92 ) ;
break;
}
}
if ( V_23 -> V_147 == V_148 && V_23 -> V_147 != V_456 . V_147 )
return - V_77 ;
V_23 -> V_147 = V_456 . V_147 ;
if ( * V_159 == V_479 || * V_159 == V_490 ) {
switch ( V_456 . V_147 ) {
case V_150 :
V_23 -> V_49 = F_229 ( V_456 . V_49 ) ;
V_23 -> V_51 = F_229 ( V_456 . V_51 ) ;
V_23 -> V_116 = F_229 ( V_456 . V_466 ) ;
if ( ! F_70 ( V_245 , & V_23 -> V_109 ) )
V_23 -> V_102 = F_66 ( T_2 , V_23 -> V_102 ,
V_456 . V_464 ) ;
if ( F_70 ( V_462 , & V_23 -> V_109 ) ) {
V_23 -> V_131 = F_229 ( V_442 . V_444 ) ;
V_23 -> V_133 =
F_230 ( V_442 . V_445 ) ;
V_23 -> V_135 = F_230 ( V_442 . V_446 ) ;
V_23 -> V_137 =
F_230 ( V_442 . V_104 ) ;
}
break;
case V_154 :
V_23 -> V_116 = F_229 ( V_456 . V_466 ) ;
}
}
V_279 -> V_16 = F_18 ( V_23 -> V_16 ) ;
V_279 -> V_109 = F_18 ( 0 ) ;
return V_435 - V_194 ;
}
static int F_232 ( struct V_11 * V_23 , void * V_194 ,
T_2 V_159 , T_2 V_109 )
{
struct V_474 * V_158 = V_194 ;
void * V_435 = V_158 -> V_194 ;
F_23 ( L_3 , V_23 ) ;
V_158 -> V_17 = F_18 ( V_23 -> V_16 ) ;
V_158 -> V_159 = F_18 ( V_159 ) ;
V_158 -> V_109 = F_18 ( V_109 ) ;
return V_435 - V_194 ;
}
void F_233 ( struct V_11 * V_23 )
{
struct V_157 V_158 ;
struct V_12 * V_13 = V_23 -> V_13 ;
F_23 ( L_3 , V_23 ) ;
V_158 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_158 . V_164 = F_18 ( V_23 -> V_117 ) ;
V_158 . V_116 = F_18 ( V_23 -> V_116 ) ;
V_158 . V_165 = F_18 ( V_23 -> V_114 ) ;
V_158 . V_159 = F_18 ( V_331 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_166 , sizeof( V_158 ) ,
& V_158 ) ;
}
void F_234 ( struct V_11 * V_23 )
{
struct V_167 V_158 ;
struct V_12 * V_13 = V_23 -> V_13 ;
T_1 V_327 [ 128 ] ;
T_1 V_500 ;
V_158 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_158 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_158 . V_159 = F_18 ( V_331 ) ;
V_158 . V_169 = F_18 ( V_170 ) ;
if ( V_23 -> V_206 )
V_500 = V_501 ;
else
V_500 = V_171 ;
F_23 ( L_41 , V_23 , V_500 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_500 , sizeof( V_158 ) , & V_158 ) ;
if ( F_132 ( V_333 , & V_23 -> V_92 ) )
return;
F_83 ( V_13 , F_91 ( V_13 ) , V_334 ,
F_142 ( V_23 , V_327 ) , V_327 ) ;
V_23 -> V_335 ++ ;
}
static void F_235 ( struct V_11 * V_23 , void * V_158 , int V_193 )
{
int type , V_436 ;
unsigned long V_437 ;
T_2 V_502 = V_23 -> V_102 ;
struct V_455 V_456 = {
. V_147 = V_23 -> V_147 ,
. V_49 = F_18 ( V_106 ) ,
. V_51 = F_18 ( V_107 ) ,
. V_466 = F_18 ( V_23 -> V_117 ) ,
. V_464 = F_66 ( T_2 , V_23 -> V_102 , V_98 ) ,
} ;
F_23 ( L_42 , V_23 , V_158 , V_193 ) ;
if ( ( V_23 -> V_147 != V_150 ) && ( V_23 -> V_147 != V_154 ) )
return;
while ( V_193 >= V_440 ) {
V_193 -= F_216 ( & V_158 , & type , & V_436 , & V_437 ) ;
switch ( type ) {
case V_467 :
if ( V_436 == sizeof( V_456 ) )
memcpy ( & V_456 , ( void * ) V_437 , V_436 ) ;
break;
case V_469 :
V_502 = V_437 ;
break;
}
}
switch ( V_456 . V_147 ) {
case V_150 :
V_23 -> V_49 = F_229 ( V_456 . V_49 ) ;
V_23 -> V_51 = F_229 ( V_456 . V_51 ) ;
V_23 -> V_116 = F_229 ( V_456 . V_466 ) ;
if ( F_70 ( V_245 , & V_23 -> V_109 ) )
V_23 -> V_102 = F_66 ( T_2 , V_23 -> V_102 , V_502 ) ;
else
V_23 -> V_102 = F_66 ( T_2 , V_23 -> V_102 ,
V_456 . V_464 ) ;
break;
case V_154 :
V_23 -> V_116 = F_229 ( V_456 . V_466 ) ;
}
}
static inline int F_236 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
struct V_504 * V_505 = (struct V_504 * ) V_194 ;
if ( V_503 < sizeof( * V_505 ) )
return - V_506 ;
if ( V_505 -> V_74 != V_507 )
return 0 ;
if ( ( V_13 -> V_307 & V_308 ) &&
V_431 -> V_19 == V_13 -> V_310 ) {
F_237 ( & V_13 -> V_311 ) ;
V_13 -> V_307 |= V_314 ;
V_13 -> V_310 = 0 ;
F_140 ( V_13 ) ;
}
return 0 ;
}
static struct V_11 * F_238 ( struct V_12 * V_13 ,
struct V_430 * V_431 ,
T_1 * V_194 , T_1 V_500 , T_1 V_281 )
{
struct V_278 * V_279 = (struct V_278 * ) V_194 ;
struct V_167 V_158 ;
struct V_11 * V_23 = NULL , * V_508 ;
int V_159 , V_169 = V_170 ;
T_2 V_16 = 0 , V_17 = F_69 ( V_279 -> V_17 ) ;
T_3 V_20 = V_279 -> V_20 ;
F_23 ( L_43 , F_69 ( V_20 ) , V_17 ) ;
V_508 = F_165 ( V_172 , V_20 , & V_13 -> V_8 -> V_21 ,
& V_13 -> V_8 -> V_156 , V_123 ) ;
if ( ! V_508 ) {
V_159 = V_162 ;
goto V_509;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_508 ) ;
if ( V_20 != F_18 ( V_184 ) &&
! F_239 ( V_13 -> V_8 ) ) {
V_13 -> V_120 = V_510 ;
V_159 = V_168 ;
goto V_511;
}
V_159 = V_512 ;
if ( F_4 ( V_13 , V_17 ) )
goto V_511;
V_23 = V_508 -> V_46 -> V_513 ( V_508 ) ;
if ( ! V_23 )
goto V_511;
V_13 -> V_8 -> V_366 = V_514 ;
F_81 ( & V_23 -> V_21 , & V_13 -> V_8 -> V_21 ) ;
F_81 ( & V_23 -> V_156 , & V_13 -> V_8 -> V_156 ) ;
V_23 -> V_9 = F_2 ( V_13 -> V_8 ) ;
V_23 -> V_10 = F_3 ( V_13 -> V_8 ) ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_17 ;
V_23 -> V_449 = V_281 ;
F_68 ( V_13 , V_23 ) ;
V_16 = V_23 -> V_17 ;
F_85 ( V_23 , V_23 -> V_46 -> V_173 ( V_23 ) ) ;
V_23 -> V_19 = V_431 -> V_19 ;
if ( V_13 -> V_307 & V_314 ) {
if ( F_88 ( V_23 , false ) ) {
if ( F_70 ( V_160 , & V_23 -> V_109 ) ) {
F_22 ( V_23 , V_174 ) ;
V_159 = V_328 ;
V_169 = V_329 ;
V_23 -> V_46 -> V_330 ( V_23 ) ;
} else {
if ( V_281 == V_450 ) {
F_22 ( V_23 , V_76 ) ;
V_159 = V_331 ;
} else {
F_22 ( V_23 , V_174 ) ;
V_159 = V_328 ;
}
V_169 = V_170 ;
}
} else {
F_22 ( V_23 , V_174 ) ;
V_159 = V_328 ;
V_169 = V_332 ;
}
} else {
F_22 ( V_23 , V_174 ) ;
V_159 = V_328 ;
V_169 = V_170 ;
}
V_511:
F_48 ( V_508 ) ;
F_10 ( & V_13 -> V_18 ) ;
F_49 ( V_508 ) ;
V_509:
V_158 . V_17 = F_18 ( V_17 ) ;
V_158 . V_16 = F_18 ( V_16 ) ;
V_158 . V_159 = F_18 ( V_159 ) ;
V_158 . V_169 = F_18 ( V_169 ) ;
F_83 ( V_13 , V_431 -> V_19 , V_500 , sizeof( V_158 ) , & V_158 ) ;
if ( V_159 == V_328 && V_169 == V_170 ) {
struct V_306 V_515 ;
V_515 . type = F_18 ( V_309 ) ;
V_13 -> V_307 |= V_308 ;
V_13 -> V_310 = F_91 ( V_13 ) ;
F_137 ( & V_13 -> V_311 , V_312 ) ;
F_83 ( V_13 , V_13 -> V_310 , V_313 ,
sizeof( V_515 ) , & V_515 ) ;
}
if ( V_23 && ! F_70 ( V_333 , & V_23 -> V_92 ) &&
V_159 == V_331 ) {
T_1 V_327 [ 128 ] ;
F_57 ( V_333 , & V_23 -> V_92 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_334 ,
F_142 ( V_23 , V_327 ) , V_327 ) ;
V_23 -> V_335 ++ ;
}
return V_23 ;
}
static int F_240 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 , T_1 * V_194 )
{
struct V_267 * V_195 = V_13 -> V_8 -> V_195 ;
struct V_7 * V_8 = V_13 -> V_8 ;
if ( V_503 < sizeof( struct V_278 ) )
return - V_506 ;
F_149 ( V_195 ) ;
if ( F_241 ( V_195 , V_516 ) &&
! F_132 ( V_517 , & V_8 -> V_109 ) )
F_242 ( V_195 , V_8 , 0 , NULL , 0 ) ;
F_151 ( V_195 ) ;
F_238 ( V_13 , V_431 , V_194 , V_171 , 0 ) ;
return 0 ;
}
static int F_243 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
struct V_167 * V_158 = (struct V_167 * ) V_194 ;
T_2 V_17 , V_16 , V_159 , V_169 ;
struct V_11 * V_23 ;
T_1 V_279 [ 128 ] ;
int V_24 ;
if ( V_503 < sizeof( * V_158 ) )
return - V_506 ;
V_17 = F_69 ( V_158 -> V_17 ) ;
V_16 = F_69 ( V_158 -> V_16 ) ;
V_159 = F_69 ( V_158 -> V_159 ) ;
V_169 = F_69 ( V_158 -> V_169 ) ;
F_23 ( L_44 ,
V_16 , V_17 , V_159 , V_169 ) ;
F_8 ( & V_13 -> V_18 ) ;
if ( V_17 ) {
V_23 = F_6 ( V_13 , V_17 ) ;
if ( ! V_23 ) {
V_24 = - V_518 ;
goto V_519;
}
} else {
V_23 = F_12 ( V_13 , V_431 -> V_19 ) ;
if ( ! V_23 ) {
V_24 = - V_518 ;
goto V_519;
}
}
V_24 = 0 ;
F_9 ( V_23 ) ;
switch ( V_159 ) {
case V_331 :
F_22 ( V_23 , V_76 ) ;
V_23 -> V_19 = 0 ;
V_23 -> V_16 = V_16 ;
F_117 ( V_266 , & V_23 -> V_92 ) ;
if ( F_132 ( V_333 , & V_23 -> V_92 ) )
break;
F_83 ( V_13 , F_91 ( V_13 ) , V_334 ,
F_142 ( V_23 , V_279 ) , V_279 ) ;
V_23 -> V_335 ++ ;
break;
case V_328 :
F_57 ( V_266 , & V_23 -> V_92 ) ;
break;
default:
F_73 ( V_23 , V_77 ) ;
break;
}
F_48 ( V_23 ) ;
V_519:
F_10 ( & V_13 -> V_18 ) ;
return V_24 ;
}
static inline void F_244 ( struct V_11 * V_23 )
{
if ( V_23 -> V_147 != V_150 && V_23 -> V_147 != V_154 )
V_23 -> V_93 = V_471 ;
else if ( ! F_70 ( V_472 , & V_23 -> V_92 ) )
V_23 -> V_93 = V_94 ;
}
static void F_245 ( struct V_11 * V_23 , void * V_194 ,
T_1 V_19 , T_2 V_109 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
F_23 ( L_45 , V_13 , V_23 , V_19 ,
V_109 ) ;
F_117 ( V_491 , & V_23 -> V_92 ) ;
F_57 ( V_499 , & V_23 -> V_92 ) ;
F_83 ( V_13 , V_19 , V_520 ,
F_232 ( V_23 , V_194 ,
V_479 , V_109 ) , V_194 ) ;
}
static void F_246 ( struct V_12 * V_13 , T_1 V_19 ,
T_2 V_17 , T_2 V_16 )
{
struct V_521 V_505 ;
V_505 . V_74 = F_18 ( V_522 ) ;
V_505 . V_17 = F_247 ( V_17 ) ;
V_505 . V_16 = F_247 ( V_16 ) ;
F_83 ( V_13 , V_19 , V_523 , sizeof( V_505 ) , & V_505 ) ;
}
static inline int F_248 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
struct V_460 * V_279 = (struct V_460 * ) V_194 ;
T_2 V_16 , V_109 ;
T_1 V_158 [ 64 ] ;
struct V_11 * V_23 ;
int V_193 , V_24 = 0 ;
if ( V_503 < sizeof( * V_279 ) )
return - V_506 ;
V_16 = F_69 ( V_279 -> V_16 ) ;
V_109 = F_69 ( V_279 -> V_109 ) ;
F_23 ( L_46 , V_16 , V_109 ) ;
V_23 = F_7 ( V_13 , V_16 ) ;
if ( ! V_23 ) {
F_246 ( V_13 , V_431 -> V_19 , V_16 , 0 ) ;
return 0 ;
}
if ( V_23 -> V_45 != V_76 && V_23 -> V_45 != V_174 ) {
F_246 ( V_13 , V_431 -> V_19 , V_23 -> V_17 ,
V_23 -> V_16 ) ;
goto V_519;
}
V_193 = V_503 - sizeof( * V_279 ) ;
if ( V_23 -> V_476 + V_193 > sizeof( V_23 -> V_475 ) ) {
F_83 ( V_13 , V_431 -> V_19 , V_520 ,
F_232 ( V_23 , V_158 ,
V_524 , V_109 ) , V_158 ) ;
goto V_519;
}
memcpy ( V_23 -> V_475 + V_23 -> V_476 , V_279 -> V_194 , V_193 ) ;
V_23 -> V_476 += V_193 ;
if ( V_109 & V_525 ) {
F_83 ( V_13 , V_431 -> V_19 , V_520 ,
F_232 ( V_23 , V_158 ,
V_479 , V_109 ) , V_158 ) ;
goto V_519;
}
V_193 = F_228 ( V_23 , V_158 ) ;
if ( V_193 < 0 ) {
F_86 ( V_23 , V_326 ) ;
goto V_519;
}
V_23 -> V_19 = V_431 -> V_19 ;
F_83 ( V_13 , V_431 -> V_19 , V_520 , V_193 , V_158 ) ;
V_23 -> V_461 ++ ;
V_23 -> V_476 = 0 ;
if ( ! F_70 ( V_499 , & V_23 -> V_92 ) )
goto V_519;
if ( F_70 ( V_526 , & V_23 -> V_92 ) ) {
F_244 ( V_23 ) ;
if ( V_23 -> V_147 == V_150 ||
V_23 -> V_147 == V_154 )
V_24 = F_221 ( V_23 ) ;
if ( V_24 < 0 )
F_86 ( V_23 , - V_24 ) ;
else
F_130 ( V_23 ) ;
goto V_519;
}
if ( ! F_132 ( V_333 , & V_23 -> V_92 ) ) {
T_1 V_327 [ 64 ] ;
F_83 ( V_13 , F_91 ( V_13 ) , V_334 ,
F_142 ( V_23 , V_327 ) , V_327 ) ;
V_23 -> V_335 ++ ;
}
if ( F_70 ( V_527 , & V_23 -> V_92 ) &&
F_70 ( V_491 , & V_23 -> V_92 ) ) {
if ( ! V_23 -> V_206 )
F_245 ( V_23 , V_158 , V_431 -> V_19 , V_109 ) ;
else
V_23 -> V_19 = V_431 -> V_19 ;
}
V_519:
F_48 ( V_23 ) ;
return V_24 ;
}
static inline int F_249 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
struct V_474 * V_158 = (struct V_474 * ) V_194 ;
T_2 V_17 , V_109 , V_159 ;
struct V_11 * V_23 ;
int V_193 = V_503 - sizeof( * V_158 ) ;
int V_24 = 0 ;
if ( V_503 < sizeof( * V_158 ) )
return - V_506 ;
V_17 = F_69 ( V_158 -> V_17 ) ;
V_109 = F_69 ( V_158 -> V_109 ) ;
V_159 = F_69 ( V_158 -> V_159 ) ;
F_23 ( L_47 , V_17 , V_109 ,
V_159 , V_193 ) ;
V_23 = F_7 ( V_13 , V_17 ) ;
if ( ! V_23 )
return 0 ;
switch ( V_159 ) {
case V_479 :
F_235 ( V_23 , V_158 -> V_194 , V_193 ) ;
F_117 ( V_527 , & V_23 -> V_92 ) ;
break;
case V_490 :
F_57 ( V_527 , & V_23 -> V_92 ) ;
if ( F_70 ( V_491 , & V_23 -> V_92 ) ) {
char V_327 [ 64 ] ;
V_193 = F_231 ( V_23 , V_158 -> V_194 , V_193 ,
V_327 , & V_159 ) ;
if ( V_193 < 0 ) {
F_86 ( V_23 , V_326 ) ;
goto V_27;
}
if ( ! V_23 -> V_206 ) {
F_245 ( V_23 , V_327 , V_431 -> V_19 ,
0 ) ;
} else {
if ( F_124 ( V_23 ) ) {
F_250 ( V_23 ) ;
V_23 -> V_19 = V_431 -> V_19 ;
}
}
}
goto V_27;
case V_486 :
if ( V_23 -> V_461 <= V_528 ) {
char V_279 [ 64 ] ;
if ( V_193 > sizeof( V_279 ) - sizeof( struct V_460 ) ) {
F_86 ( V_23 , V_326 ) ;
goto V_27;
}
V_159 = V_479 ;
V_193 = F_231 ( V_23 , V_158 -> V_194 , V_193 ,
V_279 , & V_159 ) ;
if ( V_193 < 0 ) {
F_86 ( V_23 , V_326 ) ;
goto V_27;
}
F_83 ( V_13 , F_91 ( V_13 ) ,
V_334 , V_193 , V_279 ) ;
V_23 -> V_335 ++ ;
if ( V_159 != V_479 )
goto V_27;
break;
}
default:
F_26 ( V_23 , V_326 ) ;
F_85 ( V_23 , V_529 ) ;
F_86 ( V_23 , V_326 ) ;
goto V_27;
}
if ( V_109 & V_525 )
goto V_27;
F_57 ( V_526 , & V_23 -> V_92 ) ;
if ( F_70 ( V_499 , & V_23 -> V_92 ) ) {
F_244 ( V_23 ) ;
if ( V_23 -> V_147 == V_150 ||
V_23 -> V_147 == V_154 )
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
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
struct V_321 * V_279 = (struct V_321 * ) V_194 ;
struct V_530 V_158 ;
T_2 V_16 , V_17 ;
struct V_11 * V_23 ;
if ( V_503 != sizeof( * V_279 ) )
return - V_506 ;
V_17 = F_69 ( V_279 -> V_17 ) ;
V_16 = F_69 ( V_279 -> V_16 ) ;
F_23 ( L_48 , V_17 , V_16 ) ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_6 ( V_13 , V_16 ) ;
if ( ! V_23 ) {
F_10 ( & V_13 -> V_18 ) ;
F_246 ( V_13 , V_431 -> V_19 , V_16 , V_17 ) ;
return 0 ;
}
F_9 ( V_23 ) ;
V_158 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_158 . V_17 = F_18 ( V_23 -> V_16 ) ;
F_83 ( V_13 , V_431 -> V_19 , V_531 , sizeof( V_158 ) , & V_158 ) ;
V_23 -> V_46 -> V_532 ( V_23 ) ;
F_60 ( V_23 ) ;
F_73 ( V_23 , V_326 ) ;
F_48 ( V_23 ) ;
V_23 -> V_46 -> V_82 ( V_23 ) ;
F_49 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
return 0 ;
}
static inline int F_252 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
struct V_530 * V_158 = (struct V_530 * ) V_194 ;
T_2 V_16 , V_17 ;
struct V_11 * V_23 ;
if ( V_503 != sizeof( * V_158 ) )
return - V_506 ;
V_17 = F_69 ( V_158 -> V_17 ) ;
V_16 = F_69 ( V_158 -> V_16 ) ;
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
V_23 -> V_46 -> V_82 ( V_23 ) ;
F_49 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
return 0 ;
}
static inline int F_253 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
struct V_306 * V_279 = (struct V_306 * ) V_194 ;
T_2 type ;
if ( V_503 != sizeof( * V_279 ) )
return - V_506 ;
type = F_69 ( V_279 -> type ) ;
F_23 ( L_50 , type ) ;
if ( type == V_309 ) {
T_1 V_327 [ 8 ] ;
T_8 V_315 = V_317 ;
struct V_533 * V_158 = (struct V_533 * ) V_327 ;
V_158 -> type = F_18 ( V_309 ) ;
V_158 -> V_159 = F_18 ( V_534 ) ;
if ( ! V_318 )
V_315 |= V_319 | V_320
| V_470 ;
if ( V_13 -> V_269 & V_270 )
V_315 |= V_454
| V_453 ;
F_107 ( V_315 , V_158 -> V_194 ) ;
F_83 ( V_13 , V_431 -> V_19 , V_535 , sizeof( V_327 ) ,
V_327 ) ;
} else if ( type == V_536 ) {
T_1 V_327 [ 12 ] ;
struct V_533 * V_158 = (struct V_533 * ) V_327 ;
V_158 -> type = F_18 ( V_536 ) ;
V_158 -> V_159 = F_18 ( V_534 ) ;
V_158 -> V_194 [ 0 ] = V_13 -> V_269 ;
memset ( V_158 -> V_194 + 1 , 0 , 7 ) ;
F_83 ( V_13 , V_431 -> V_19 , V_535 , sizeof( V_327 ) ,
V_327 ) ;
} else {
struct V_533 V_158 ;
V_158 . type = F_18 ( type ) ;
V_158 . V_159 = F_18 ( V_537 ) ;
F_83 ( V_13 , V_431 -> V_19 , V_535 , sizeof( V_158 ) ,
& V_158 ) ;
}
return 0 ;
}
static inline int F_254 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
struct V_533 * V_158 = (struct V_533 * ) V_194 ;
T_2 type , V_159 ;
if ( V_503 < sizeof( * V_158 ) )
return - V_506 ;
type = F_69 ( V_158 -> type ) ;
V_159 = F_69 ( V_158 -> V_159 ) ;
F_23 ( L_51 , type , V_159 ) ;
if ( V_431 -> V_19 != V_13 -> V_310 ||
V_13 -> V_307 & V_314 )
return 0 ;
F_237 ( & V_13 -> V_311 ) ;
if ( V_159 != V_534 ) {
V_13 -> V_307 |= V_314 ;
V_13 -> V_310 = 0 ;
F_140 ( V_13 ) ;
return 0 ;
}
switch ( type ) {
case V_309 :
V_13 -> V_315 = F_101 ( V_158 -> V_194 ) ;
if ( V_13 -> V_315 & V_538 ) {
struct V_306 V_279 ;
V_279 . type = F_18 ( V_536 ) ;
V_13 -> V_310 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_13 -> V_310 ,
V_313 , sizeof( V_279 ) , & V_279 ) ;
} else {
V_13 -> V_307 |= V_314 ;
V_13 -> V_310 = 0 ;
F_140 ( V_13 ) ;
}
break;
case V_536 :
V_13 -> V_271 = V_158 -> V_194 [ 0 ] ;
V_13 -> V_307 |= V_314 ;
V_13 -> V_310 = 0 ;
F_140 ( V_13 ) ;
break;
}
return 0 ;
}
static int F_255 ( struct V_12 * V_13 ,
struct V_430 * V_431 ,
T_2 V_503 , void * V_194 )
{
struct V_282 * V_279 = V_194 ;
struct V_539 V_158 ;
struct V_11 * V_23 ;
struct V_267 * V_195 ;
T_2 V_20 , V_17 ;
if ( V_503 != sizeof( * V_279 ) )
return - V_506 ;
if ( ! ( V_13 -> V_269 & V_270 ) )
return - V_36 ;
V_20 = F_229 ( V_279 -> V_20 ) ;
V_17 = F_229 ( V_279 -> V_17 ) ;
F_23 ( L_52 , V_20 , V_17 , V_279 -> V_281 ) ;
if ( V_279 -> V_281 == V_450 ) {
F_238 ( V_13 , V_431 , V_194 , V_501 ,
V_279 -> V_281 ) ;
return 0 ;
}
V_195 = F_256 ( V_279 -> V_281 ) ;
if ( ! V_195 )
goto error;
if ( V_195 -> V_540 != V_541 || ! F_70 ( V_275 , & V_195 -> V_109 ) ) {
F_257 ( V_195 ) ;
goto error;
}
V_23 = F_238 ( V_13 , V_431 , V_194 , V_501 ,
V_279 -> V_281 ) ;
if ( V_23 ) {
struct V_142 * V_143 = V_13 -> V_8 -> V_142 ;
struct V_7 * V_206 ;
V_206 = F_258 ( V_195 , V_542 ,
& V_13 -> V_8 -> V_156 ) ;
if ( ! V_206 ) {
F_257 ( V_195 ) ;
F_246 ( V_13 , V_431 -> V_19 , V_23 -> V_17 ,
V_23 -> V_16 ) ;
return 0 ;
}
F_23 ( L_53 , V_143 , V_23 , V_206 ) ;
V_143 -> V_144 = V_23 ;
V_23 -> V_206 = V_206 ;
V_23 -> V_93 = V_471 ;
V_13 -> V_164 = V_195 -> V_543 ;
}
F_257 ( V_195 ) ;
return 0 ;
error:
V_158 . V_16 = 0 ;
V_158 . V_17 = F_18 ( V_17 ) ;
V_158 . V_159 = F_18 ( V_544 ) ;
V_158 . V_169 = F_18 ( V_170 ) ;
F_83 ( V_13 , V_431 -> V_19 , V_501 ,
sizeof( V_158 ) , & V_158 ) ;
return 0 ;
}
static void F_259 ( struct V_11 * V_23 , T_1 V_545 )
{
struct V_546 V_279 ;
T_1 V_19 ;
F_23 ( L_54 , V_23 , V_545 ) ;
V_19 = F_91 ( V_23 -> V_13 ) ;
V_23 -> V_19 = V_19 ;
V_279 . V_547 = F_18 ( V_23 -> V_17 ) ;
V_279 . V_545 = V_545 ;
F_83 ( V_23 -> V_13 , V_19 , V_548 , sizeof( V_279 ) ,
& V_279 ) ;
F_85 ( V_23 , V_549 ) ;
}
static void F_260 ( struct V_11 * V_23 , T_2 V_159 )
{
struct V_550 V_158 ;
F_23 ( L_55 , V_23 , V_159 ) ;
V_158 . V_547 = F_18 ( V_23 -> V_16 ) ;
V_158 . V_159 = F_18 ( V_159 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_551 ,
sizeof( V_158 ) , & V_158 ) ;
}
static void F_261 ( struct V_11 * V_23 , T_2 V_159 )
{
struct V_552 V_553 ;
F_23 ( L_55 , V_23 , V_159 ) ;
V_23 -> V_19 = F_91 ( V_23 -> V_13 ) ;
V_553 . V_547 = F_18 ( V_23 -> V_17 ) ;
V_553 . V_159 = F_18 ( V_159 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_554 ,
sizeof( V_553 ) , & V_553 ) ;
F_85 ( V_23 , V_549 ) ;
}
static void F_262 ( struct V_12 * V_13 , T_2 V_547 )
{
struct V_552 V_553 ;
F_23 ( L_56 , V_13 , V_547 ) ;
V_553 . V_547 = F_18 ( V_547 ) ;
V_553 . V_159 = F_18 ( V_555 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_554 ,
sizeof( V_553 ) , & V_553 ) ;
}
static void F_263 ( struct V_12 * V_13 , T_1 V_19 ,
T_2 V_547 )
{
struct V_556 V_158 ;
F_23 ( L_57 , V_547 ) ;
V_158 . V_547 = F_18 ( V_547 ) ;
F_83 ( V_13 , V_19 , V_557 , sizeof( V_158 ) , & V_158 ) ;
}
static void F_264 ( struct V_11 * V_23 )
{
V_23 -> V_145 = NULL ;
V_23 -> V_206 = NULL ;
}
static void F_265 ( struct V_11 * V_23 )
{
if ( V_23 -> V_45 != V_75 ) {
F_86 ( V_23 , V_326 ) ;
return;
}
switch ( V_23 -> V_294 ) {
case V_299 :
F_128 ( V_23 ) ;
F_260 ( V_23 , V_558 ) ;
break;
case V_296 :
if ( V_23 -> V_203 == V_559 ||
V_23 -> V_203 == V_560 ) {
F_128 ( V_23 ) ;
}
F_261 ( V_23 , V_555 ) ;
break;
}
}
static void F_266 ( struct V_11 * V_23 ,
struct V_146 * V_202 )
{
struct V_474 V_158 ;
V_23 -> V_145 = V_202 ;
V_23 -> V_206 -> V_362 = V_23 -> V_13 ;
F_245 ( V_23 , & V_158 , V_23 -> V_19 , 0 ) ;
if ( F_70 ( V_526 , & V_23 -> V_92 ) ) {
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
struct V_146 * V_202 )
{
V_23 -> V_206 = V_202 -> V_13 ;
V_23 -> V_206 -> V_362 = V_23 -> V_13 ;
F_23 ( L_58 , V_23 -> V_203 ) ;
switch ( V_23 -> V_203 ) {
case V_559 :
V_23 -> V_203 = V_561 ;
break;
case V_560 :
if ( F_70 ( V_264 , & V_23 -> V_258 ) ) {
V_23 -> V_203 = V_562 ;
} else if ( V_23 -> V_294 == V_296 ) {
V_23 -> V_203 = V_563 ;
F_261 ( V_23 , V_564 ) ;
} else if ( V_23 -> V_294 == V_299 ) {
V_23 -> V_203 = V_565 ;
F_260 ( V_23 , V_566 ) ;
}
break;
default:
F_264 ( V_23 ) ;
V_23 -> V_203 = V_204 ;
}
}
void F_268 ( struct V_11 * V_23 , struct V_146 * V_202 ,
T_1 V_169 )
{
F_23 ( L_59 , V_23 , V_202 , V_169 ) ;
if ( V_169 ) {
F_265 ( V_23 ) ;
F_264 ( V_23 ) ;
return;
}
if ( V_23 -> V_45 != V_75 ) {
if ( V_23 -> V_449 != V_450 )
F_266 ( V_23 , V_202 ) ;
} else {
F_267 ( V_23 , V_202 ) ;
}
}
void F_269 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_449 == V_450 ) {
if ( V_23 -> V_276 != V_277 )
return;
V_23 -> V_294 = V_296 ;
V_23 -> V_203 = V_205 ;
} else {
V_23 -> V_294 = V_296 ;
V_23 -> V_203 = V_561 ;
V_23 -> V_451 = 0 ;
F_127 ( V_23 ) ;
F_259 ( V_23 , 0 ) ;
}
}
static void F_270 ( struct V_11 * V_23 , int V_159 ,
T_1 V_449 , T_1 V_567 )
{
F_23 ( L_60 , V_23 , F_24 ( V_23 -> V_45 ) ,
V_449 , V_567 ) ;
V_23 -> V_93 = V_471 ;
if ( V_23 -> V_45 == V_78 ) {
if ( V_159 == V_331 ) {
V_23 -> V_449 = V_449 ;
F_126 ( V_23 , V_567 ) ;
} else {
F_125 ( V_23 ) ;
}
return;
}
if ( F_120 ( V_23 ) ) {
struct V_167 V_158 ;
char V_327 [ 128 ] ;
V_158 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_158 . V_16 = F_18 ( V_23 -> V_17 ) ;
if ( V_159 == V_331 ) {
V_158 . V_159 = F_18 ( V_331 ) ;
V_158 . V_169 = F_18 ( V_170 ) ;
} else {
V_158 . V_159 = F_18 ( V_512 ) ;
V_158 . V_169 = F_18 ( V_170 ) ;
}
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_501 ,
sizeof( V_158 ) , & V_158 ) ;
if ( V_159 == V_331 ) {
F_22 ( V_23 , V_76 ) ;
F_57 ( V_333 , & V_23 -> V_92 ) ;
F_83 ( V_23 -> V_13 , F_91 ( V_23 -> V_13 ) ,
V_334 ,
F_142 ( V_23 , V_327 ) , V_327 ) ;
V_23 -> V_335 ++ ;
}
}
}
static void F_271 ( struct V_11 * V_23 , T_1 V_449 ,
T_1 V_567 )
{
F_127 ( V_23 ) ;
V_23 -> V_451 = V_449 ;
V_23 -> V_203 = V_568 ;
F_259 ( V_23 , V_567 ) ;
}
static void F_272 ( struct V_11 * V_23 , int V_159 )
{
struct V_146 * V_202 = NULL ;
if ( V_202 ) {
if ( V_202 -> V_45 == V_75 ) {
V_23 -> V_206 = V_202 -> V_13 ;
V_23 -> V_206 -> V_362 = V_23 -> V_13 ;
V_23 -> V_203 = V_565 ;
F_260 ( V_23 , V_566 ) ;
F_268 ( V_23 , V_202 , V_566 ) ;
} else {
V_23 -> V_203 = V_560 ;
}
} else {
F_260 ( V_23 , V_569 ) ;
}
}
static void F_273 ( struct V_11 * V_23 , int V_159 )
{
if ( V_23 -> V_294 == V_299 ) {
T_1 V_570 ;
if ( V_159 == - V_36 )
V_570 = V_571 ;
else
V_570 = V_569 ;
F_260 ( V_23 , V_570 ) ;
}
V_23 -> V_294 = V_295 ;
V_23 -> V_203 = V_204 ;
F_173 ( V_23 ) ;
}
void F_274 ( struct V_11 * V_23 , int V_159 )
{
T_1 V_449 = V_23 -> V_449 ;
T_1 V_567 = V_23 -> V_567 ;
F_23 ( L_61 ,
V_23 , V_159 , V_449 , V_567 ) ;
if ( V_23 -> V_45 == V_163 || V_23 -> V_45 == V_572 ) {
F_48 ( V_23 ) ;
return;
}
if ( V_23 -> V_45 != V_75 ) {
F_270 ( V_23 , V_159 , V_449 , V_567 ) ;
} else if ( V_159 != V_566 ) {
F_273 ( V_23 , V_159 ) ;
} else {
switch ( V_23 -> V_294 ) {
case V_296 :
F_271 ( V_23 , V_449 ,
V_567 ) ;
break;
case V_299 :
F_272 ( V_23 , V_159 ) ;
break;
default:
F_273 ( V_23 , V_159 ) ;
break;
}
}
}
static inline int F_275 ( struct V_12 * V_13 ,
struct V_430 * V_431 ,
T_2 V_503 , void * V_194 )
{
struct V_546 * V_279 = V_194 ;
struct V_550 V_158 ;
struct V_11 * V_23 ;
T_2 V_547 = 0 ;
T_2 V_159 = V_569 ;
if ( V_503 != sizeof( * V_279 ) )
return - V_506 ;
V_547 = F_229 ( V_279 -> V_547 ) ;
F_23 ( L_62 , V_547 , V_279 -> V_545 ) ;
if ( ! ( V_13 -> V_269 & V_270 ) )
return - V_36 ;
V_23 = F_11 ( V_13 , V_547 ) ;
if ( ! V_23 ) {
V_158 . V_547 = F_18 ( V_547 ) ;
V_158 . V_159 = F_18 ( V_569 ) ;
F_83 ( V_13 , V_431 -> V_19 , V_551 ,
sizeof( V_158 ) , & V_158 ) ;
return 0 ;
}
V_23 -> V_19 = V_431 -> V_19 ;
if ( V_23 -> V_17 < V_44 ||
V_23 -> V_276 == V_573 ||
( V_23 -> V_147 != V_150 &&
V_23 -> V_147 != V_154 ) ) {
V_159 = V_569 ;
goto V_574;
}
if ( V_23 -> V_449 == V_279 -> V_545 ) {
V_159 = V_575 ;
goto V_574;
}
if ( V_279 -> V_545 != V_450 ) {
struct V_267 * V_195 ;
V_195 = F_256 ( V_279 -> V_545 ) ;
if ( ! V_195 || V_195 -> V_540 != V_541 ||
! F_70 ( V_275 , & V_195 -> V_109 ) ) {
if ( V_195 )
F_257 ( V_195 ) ;
V_159 = V_571 ;
goto V_574;
}
F_257 ( V_195 ) ;
}
if ( ( F_95 ( V_23 ) ||
V_23 -> V_294 != V_295 ) &&
F_15 ( & V_13 -> V_8 -> V_21 , & V_13 -> V_8 -> V_156 ) > 0 ) {
V_159 = V_576 ;
goto V_574;
}
V_23 -> V_294 = V_299 ;
F_127 ( V_23 ) ;
V_23 -> V_451 = V_279 -> V_545 ;
V_547 = V_23 -> V_16 ;
if ( V_279 -> V_545 == V_450 ) {
if ( F_70 ( V_264 , & V_23 -> V_258 ) ) {
V_23 -> V_203 = V_562 ;
V_159 = V_577 ;
} else {
V_23 -> V_203 = V_565 ;
V_159 = V_566 ;
}
} else {
V_23 -> V_203 = V_205 ;
V_159 = V_577 ;
}
V_574:
F_260 ( V_23 , V_159 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static void F_276 ( struct V_12 * V_13 , T_2 V_547 , T_2 V_159 )
{
struct V_11 * V_23 ;
struct V_146 * V_202 = NULL ;
V_23 = F_7 ( V_13 , V_547 ) ;
if ( ! V_23 ) {
F_262 ( V_13 , V_547 ) ;
return;
}
F_74 ( V_23 ) ;
if ( V_159 == V_577 )
F_85 ( V_23 , V_578 ) ;
switch ( V_23 -> V_203 ) {
case V_559 :
V_23 -> V_203 = V_560 ;
break;
case V_561 :
if ( V_159 == V_577 ) {
break;
} else if ( F_70 ( V_264 ,
& V_23 -> V_258 ) ) {
V_23 -> V_203 = V_562 ;
} else {
V_23 -> V_203 = V_563 ;
F_261 ( V_23 , V_564 ) ;
}
break;
case V_568 :
if ( V_159 == V_566 ) {
V_23 -> V_203 = V_560 ;
} else {
V_23 -> V_203 = V_559 ;
}
if ( ! V_202 ) {
F_261 ( V_23 , V_555 ) ;
break;
}
if ( V_202 -> V_45 != V_75 )
break;
V_23 -> V_206 = V_202 -> V_13 ;
V_23 -> V_206 -> V_362 = V_23 -> V_13 ;
if ( V_159 == V_566 ) {
F_261 ( V_23 , V_564 ) ;
} else {
V_23 -> V_203 = V_561 ;
}
F_268 ( V_23 , V_202 , V_566 ) ;
break;
default:
V_23 -> V_451 = V_23 -> V_449 ;
F_128 ( V_23 ) ;
F_261 ( V_23 , V_555 ) ;
}
F_48 ( V_23 ) ;
}
static void F_277 ( struct V_12 * V_13 , T_1 V_19 , T_2 V_547 ,
T_2 V_159 )
{
struct V_11 * V_23 ;
V_23 = F_13 ( V_13 , V_19 ) ;
if ( ! V_23 ) {
F_262 ( V_13 , V_547 ) ;
return;
}
F_74 ( V_23 ) ;
if ( V_23 -> V_294 == V_296 ) {
if ( V_159 == V_576 ) {
V_23 -> V_294 = V_299 ;
} else {
V_23 -> V_451 = V_23 -> V_449 ;
F_128 ( V_23 ) ;
}
}
F_261 ( V_23 , V_555 ) ;
F_48 ( V_23 ) ;
}
static int F_278 ( struct V_12 * V_13 ,
struct V_430 * V_431 ,
T_2 V_503 , void * V_194 )
{
struct V_550 * V_158 = V_194 ;
T_2 V_547 , V_159 ;
if ( V_503 != sizeof( * V_158 ) )
return - V_506 ;
V_547 = F_229 ( V_158 -> V_547 ) ;
V_159 = F_229 ( V_158 -> V_159 ) ;
F_23 ( L_63 , V_547 , V_159 ) ;
if ( V_159 == V_566 || V_159 == V_577 )
F_276 ( V_13 , V_547 , V_159 ) ;
else
F_277 ( V_13 , V_431 -> V_19 , V_547 , V_159 ) ;
return 0 ;
}
static int F_279 ( struct V_12 * V_13 ,
struct V_430 * V_431 ,
T_2 V_503 , void * V_194 )
{
struct V_552 * V_553 = V_194 ;
struct V_11 * V_23 ;
T_2 V_547 , V_159 ;
if ( V_503 != sizeof( * V_553 ) )
return - V_506 ;
V_547 = F_229 ( V_553 -> V_547 ) ;
V_159 = F_229 ( V_553 -> V_159 ) ;
F_23 ( L_63 , V_547 , V_159 ) ;
V_23 = F_11 ( V_13 , V_547 ) ;
if ( ! V_23 ) {
F_263 ( V_13 , V_431 -> V_19 , V_547 ) ;
return 0 ;
}
if ( V_23 -> V_203 == V_565 ) {
if ( V_159 == V_564 ) {
V_23 -> V_449 = V_23 -> V_451 ;
if ( V_23 -> V_449 == V_450 )
F_264 ( V_23 ) ;
} else {
V_23 -> V_451 = V_23 -> V_449 ;
}
F_128 ( V_23 ) ;
}
F_263 ( V_13 , V_431 -> V_19 , V_547 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static inline int F_280 ( struct V_12 * V_13 ,
struct V_430 * V_431 ,
T_2 V_503 , void * V_194 )
{
struct V_556 * V_158 = V_194 ;
struct V_11 * V_23 ;
T_2 V_547 ;
if ( V_503 != sizeof( * V_158 ) )
return - V_506 ;
V_547 = F_229 ( V_158 -> V_547 ) ;
F_23 ( L_57 , V_547 ) ;
V_23 = F_7 ( V_13 , V_547 ) ;
if ( ! V_23 )
return 0 ;
F_74 ( V_23 ) ;
if ( V_23 -> V_203 == V_563 ) {
V_23 -> V_449 = V_23 -> V_451 ;
if ( V_23 -> V_449 == V_450 && V_23 -> V_145 )
F_264 ( V_23 ) ;
F_128 ( V_23 ) ;
}
F_48 ( V_23 ) ;
return 0 ;
}
static inline int V_344 ( struct V_12 * V_13 ,
struct V_430 * V_431 ,
T_2 V_503 , T_1 * V_194 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_344 * V_279 ;
struct V_579 V_158 ;
T_2 V_345 , V_346 , V_347 , V_349 ;
int V_24 ;
if ( V_8 -> V_339 != V_580 )
return - V_36 ;
if ( V_503 != sizeof( struct V_344 ) )
return - V_506 ;
V_279 = (struct V_344 * ) V_194 ;
V_345 = F_69 ( V_279 -> V_345 ) ;
V_346 = F_69 ( V_279 -> V_346 ) ;
V_347 = F_69 ( V_279 -> V_347 ) ;
V_349 = F_69 ( V_279 -> V_349 ) ;
F_23 ( L_64 ,
V_345 , V_346 , V_347 , V_349 ) ;
memset ( & V_158 , 0 , sizeof( V_158 ) ) ;
V_24 = F_281 ( V_345 , V_346 , V_347 , V_349 ) ;
if ( V_24 )
V_158 . V_159 = F_18 ( V_581 ) ;
else
V_158 . V_159 = F_18 ( V_582 ) ;
F_83 ( V_13 , V_431 -> V_19 , V_583 ,
sizeof( V_158 ) , & V_158 ) ;
if ( ! V_24 ) {
T_1 V_584 ;
V_584 = F_282 ( V_8 , V_345 , V_346 , V_347 ,
V_349 ) ;
F_283 ( V_8 -> V_195 , & V_8 -> V_156 , V_8 -> V_10 ,
V_584 , V_345 , V_346 , V_347 ,
V_349 ) ;
}
return 0 ;
}
static int F_284 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
struct V_157 * V_158 = (struct V_157 * ) V_194 ;
struct V_7 * V_8 = V_13 -> V_8 ;
T_2 V_16 , V_164 , V_116 , V_165 , V_159 ;
struct V_11 * V_23 ;
int V_24 , V_79 ;
if ( V_503 < sizeof( * V_158 ) )
return - V_506 ;
V_16 = F_69 ( V_158 -> V_16 ) ;
V_164 = F_69 ( V_158 -> V_164 ) ;
V_116 = F_69 ( V_158 -> V_116 ) ;
V_165 = F_69 ( V_158 -> V_165 ) ;
V_159 = F_69 ( V_158 -> V_159 ) ;
if ( V_159 == V_331 && ( V_164 < 23 || V_116 < 23 ||
V_16 < V_44 ||
V_16 > V_42 ) )
return - V_506 ;
F_23 ( L_65 ,
V_16 , V_164 , V_116 , V_165 , V_159 ) ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_12 ( V_13 , V_431 -> V_19 ) ;
if ( ! V_23 ) {
V_24 = - V_518 ;
goto V_519;
}
V_24 = 0 ;
F_9 ( V_23 ) ;
switch ( V_159 ) {
case V_331 :
if ( F_4 ( V_13 , V_16 ) ) {
V_24 = - V_518 ;
break;
}
V_23 -> V_19 = 0 ;
V_23 -> V_16 = V_16 ;
V_23 -> V_37 = V_164 ;
V_23 -> V_405 = V_116 ;
V_23 -> V_113 = V_165 ;
F_130 ( V_23 ) ;
break;
case V_585 :
case V_586 :
if ( V_8 -> V_79 > V_179 ) {
F_73 ( V_23 , V_77 ) ;
break;
}
V_79 = V_8 -> V_79 + 1 ;
if ( V_23 -> V_79 < V_79 )
V_23 -> V_79 = V_79 ;
F_117 ( V_304 , & V_23 -> V_109 ) ;
F_89 ( V_8 , V_23 -> V_79 ) ;
break;
default:
F_73 ( V_23 , V_77 ) ;
break;
}
F_48 ( V_23 ) ;
V_519:
F_10 ( & V_13 -> V_18 ) ;
return V_24 ;
}
static inline int F_285 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
int V_24 = 0 ;
switch ( V_431 -> V_192 ) {
case V_523 :
F_236 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_280 :
V_24 = F_240 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_171 :
case V_501 :
F_243 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_334 :
V_24 = F_248 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_520 :
F_249 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_323 :
V_24 = F_251 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_531 :
F_252 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_587 :
F_83 ( V_13 , V_431 -> V_19 , V_588 , V_503 , V_194 ) ;
break;
case V_588 :
break;
case V_313 :
V_24 = F_253 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_535 :
F_254 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_283 :
V_24 = F_255 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_548 :
V_24 = F_275 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_551 :
F_278 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_554 :
V_24 = F_279 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_557 :
F_280 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
default:
F_286 ( L_66 , V_431 -> V_192 ) ;
V_24 = - V_36 ;
break;
}
return V_24 ;
}
static int F_287 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
struct V_303 * V_279 = (struct V_303 * ) V_194 ;
struct V_157 V_158 ;
struct V_11 * V_23 , * V_508 ;
T_2 V_16 , V_17 , V_165 , V_164 , V_116 ;
T_3 V_20 ;
T_1 V_159 ;
if ( V_503 != sizeof( * V_279 ) )
return - V_506 ;
V_17 = F_69 ( V_279 -> V_17 ) ;
V_164 = F_69 ( V_279 -> V_164 ) ;
V_116 = F_69 ( V_279 -> V_116 ) ;
V_20 = V_279 -> V_20 ;
V_16 = 0 ;
V_165 = 0 ;
if ( V_164 < 23 || V_116 < 23 )
return - V_506 ;
F_23 ( L_67 , F_69 ( V_20 ) ,
V_17 , V_164 , V_116 ) ;
V_508 = F_165 ( V_172 , V_20 , & V_13 -> V_8 -> V_21 ,
& V_13 -> V_8 -> V_156 , V_2 ) ;
if ( ! V_508 ) {
V_159 = V_162 ;
V_23 = NULL ;
goto V_511;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_508 ) ;
if ( ! F_288 ( V_13 -> V_8 , V_508 -> V_79 ,
V_589 ) ) {
V_159 = V_585 ;
V_23 = NULL ;
goto V_590;
}
if ( V_17 < V_44 || V_17 > V_42 ) {
V_159 = V_591 ;
V_23 = NULL ;
goto V_590;
}
if ( F_4 ( V_13 , V_17 ) ) {
V_159 = V_592 ;
V_23 = NULL ;
goto V_590;
}
V_23 = V_508 -> V_46 -> V_513 ( V_508 ) ;
if ( ! V_23 ) {
V_159 = V_512 ;
goto V_590;
}
F_65 ( V_23 ) ;
F_81 ( & V_23 -> V_21 , & V_13 -> V_8 -> V_21 ) ;
F_81 ( & V_23 -> V_156 , & V_13 -> V_8 -> V_156 ) ;
V_23 -> V_9 = F_2 ( V_13 -> V_8 ) ;
V_23 -> V_10 = F_3 ( V_13 -> V_8 ) ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_17 ;
V_23 -> V_37 = V_164 ;
V_23 -> V_405 = V_116 ;
V_23 -> V_113 = F_69 ( V_279 -> V_165 ) ;
F_68 ( V_13 , V_23 ) ;
V_16 = V_23 -> V_17 ;
V_165 = V_23 -> V_114 ;
F_85 ( V_23 , V_23 -> V_46 -> V_173 ( V_23 ) ) ;
V_23 -> V_19 = V_431 -> V_19 ;
if ( F_70 ( V_160 , & V_23 -> V_109 ) ) {
F_22 ( V_23 , V_174 ) ;
V_159 = V_328 ;
V_23 -> V_46 -> V_330 ( V_23 ) ;
} else {
F_130 ( V_23 ) ;
V_159 = V_331 ;
}
V_590:
F_48 ( V_508 ) ;
F_10 ( & V_13 -> V_18 ) ;
F_49 ( V_508 ) ;
if ( V_159 == V_328 )
return 0 ;
V_511:
if ( V_23 ) {
V_158 . V_164 = F_18 ( V_23 -> V_117 ) ;
V_158 . V_116 = F_18 ( V_23 -> V_116 ) ;
} else {
V_158 . V_164 = 0 ;
V_158 . V_116 = 0 ;
}
V_158 . V_16 = F_18 ( V_16 ) ;
V_158 . V_165 = F_18 ( V_165 ) ;
V_158 . V_159 = F_18 ( V_159 ) ;
F_83 ( V_13 , V_431 -> V_19 , V_166 , sizeof( V_158 ) , & V_158 ) ;
return 0 ;
}
static inline int F_289 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
struct F_289 * V_593 ;
struct V_11 * V_23 ;
T_2 V_14 , V_165 , V_594 ;
if ( V_503 != sizeof( * V_593 ) )
return - V_506 ;
V_593 = (struct F_289 * ) V_194 ;
V_14 = F_69 ( V_593 -> V_14 ) ;
V_165 = F_69 ( V_593 -> V_165 ) ;
F_23 ( L_68 , V_14 , V_165 ) ;
V_23 = F_11 ( V_13 , V_14 ) ;
if ( ! V_23 )
return - V_518 ;
V_594 = V_595 - V_23 -> V_113 ;
if ( V_165 > V_594 ) {
F_286 ( L_69 ) ;
F_86 ( V_23 , V_326 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
V_23 -> V_113 += V_165 ;
while ( V_23 -> V_113 && ! F_170 ( & V_23 -> V_119 ) ) {
F_96 ( V_23 , F_171 ( & V_23 -> V_119 ) ) ;
V_23 -> V_113 -- ;
}
if ( V_23 -> V_113 )
V_23 -> V_46 -> V_596 ( V_23 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static inline int F_290 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
struct V_504 * V_505 = (struct V_504 * ) V_194 ;
struct V_11 * V_23 ;
if ( V_503 < sizeof( * V_505 ) )
return - V_506 ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_12 ( V_13 , V_431 -> V_19 ) ;
if ( ! V_23 )
goto V_27;
F_9 ( V_23 ) ;
F_73 ( V_23 , V_77 ) ;
F_48 ( V_23 ) ;
V_27:
F_10 ( & V_13 -> V_18 ) ;
return 0 ;
}
static inline int F_291 ( struct V_12 * V_13 ,
struct V_430 * V_431 , T_2 V_503 ,
T_1 * V_194 )
{
int V_24 = 0 ;
switch ( V_431 -> V_192 ) {
case V_523 :
F_290 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_351 :
V_24 = V_344 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_583 :
break;
case V_166 :
F_284 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_305 :
V_24 = F_287 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_597 :
V_24 = F_289 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_323 :
V_24 = F_251 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
case V_531 :
F_252 ( V_13 , V_431 , V_503 , V_194 ) ;
break;
default:
F_286 ( L_70 , V_431 -> V_192 ) ;
V_24 = - V_36 ;
break;
}
return V_24 ;
}
static inline void F_292 ( struct V_12 * V_13 ,
struct V_52 * V_56 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_430 * V_431 ;
T_2 V_193 ;
int V_24 ;
if ( V_8 -> type != V_2 )
goto V_598;
if ( V_56 -> V_193 < V_432 )
goto V_598;
V_431 = ( void * ) V_56 -> V_194 ;
F_102 ( V_56 , V_432 ) ;
V_193 = F_229 ( V_431 -> V_193 ) ;
F_23 ( L_71 , V_431 -> V_192 , V_193 , V_431 -> V_19 ) ;
if ( V_193 != V_56 -> V_193 || ! V_431 -> V_19 ) {
F_23 ( L_72 ) ;
goto V_598;
}
V_24 = F_291 ( V_13 , V_431 , V_193 , V_56 -> V_194 ) ;
if ( V_24 ) {
struct V_504 V_505 ;
F_286 ( L_73 , V_24 ) ;
V_505 . V_74 = F_18 ( V_507 ) ;
F_83 ( V_13 , V_431 -> V_19 , V_523 ,
sizeof( V_505 ) , & V_505 ) ;
}
V_598:
F_97 ( V_56 ) ;
}
static inline void F_293 ( struct V_12 * V_13 ,
struct V_52 * V_56 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
T_1 * V_194 = V_56 -> V_194 ;
int V_193 = V_56 -> V_193 ;
struct V_430 V_431 ;
int V_24 ;
F_215 ( V_13 , V_56 ) ;
if ( V_8 -> type != V_123 )
goto V_598;
while ( V_193 >= V_432 ) {
T_2 V_503 ;
memcpy ( & V_431 , V_194 , V_432 ) ;
V_194 += V_432 ;
V_193 -= V_432 ;
V_503 = F_229 ( V_431 . V_193 ) ;
F_23 ( L_71 , V_431 . V_192 , V_503 ,
V_431 . V_19 ) ;
if ( V_503 > V_193 || ! V_431 . V_19 ) {
F_23 ( L_72 ) ;
break;
}
V_24 = F_285 ( V_13 , & V_431 , V_503 , V_194 ) ;
if ( V_24 ) {
struct V_504 V_505 ;
F_286 ( L_73 , V_24 ) ;
V_505 . V_74 = F_18 ( V_507 ) ;
F_83 ( V_13 , V_431 . V_19 , V_523 ,
sizeof( V_505 ) , & V_505 ) ;
}
V_194 += V_503 ;
V_193 -= V_503 ;
}
V_598:
F_97 ( V_56 ) ;
}
static int F_294 ( struct V_11 * V_23 , struct V_52 * V_56 )
{
T_2 V_599 , V_600 ;
int V_601 ;
if ( F_70 ( V_245 , & V_23 -> V_109 ) )
V_601 = V_250 ;
else
V_601 = V_251 ;
if ( V_23 -> V_93 == V_94 ) {
F_295 ( V_56 , V_56 -> V_193 - V_255 ) ;
V_600 = F_103 ( V_56 -> V_194 + V_56 -> V_193 ) ;
V_599 = F_114 ( 0 , V_56 -> V_194 - V_601 , V_56 -> V_193 + V_601 ) ;
if ( V_599 != V_600 )
return - V_602 ;
}
return 0 ;
}
static void F_296 ( struct V_11 * V_23 )
{
struct V_210 V_211 ;
F_23 ( L_3 , V_23 ) ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
V_211 . V_219 = 1 ;
V_211 . V_215 = 1 ;
V_211 . V_212 = V_23 -> V_265 ;
F_57 ( V_257 , & V_23 -> V_258 ) ;
if ( F_70 ( V_264 , & V_23 -> V_258 ) ) {
V_211 . V_223 = V_261 ;
F_115 ( V_23 , & V_211 ) ;
}
if ( F_116 ( V_293 , & V_23 -> V_258 ) &&
V_23 -> V_383 > 0 )
F_27 ( V_23 ) ;
F_173 ( V_23 ) ;
if ( ! F_70 ( V_264 , & V_23 -> V_258 ) &&
F_70 ( V_257 , & V_23 -> V_258 ) ) {
V_211 . V_223 = V_259 ;
F_115 ( V_23 , & V_211 ) ;
}
}
static void F_297 ( struct V_52 * V_56 , struct V_52 * V_603 ,
struct V_52 * * V_604 )
{
if ( ! F_298 ( V_56 ) )
F_190 ( V_56 ) -> V_393 = V_603 ;
V_603 -> V_398 = NULL ;
( * V_604 ) -> V_398 = V_603 ;
* V_604 = V_603 ;
V_56 -> V_193 += V_603 -> V_193 ;
V_56 -> V_397 += V_603 -> V_193 ;
V_56 -> V_605 += V_603 -> V_605 ;
}
static int F_299 ( struct V_11 * V_23 , struct V_52 * V_56 ,
struct V_210 * V_211 )
{
int V_24 = - V_36 ;
switch ( V_211 -> V_226 ) {
case V_406 :
if ( V_23 -> V_110 )
break;
V_24 = V_23 -> V_46 -> V_428 ( V_23 , V_56 ) ;
break;
case V_407 :
if ( V_23 -> V_110 )
break;
if ( ! F_300 ( V_56 , V_401 ) )
break;
V_23 -> V_112 = F_103 ( V_56 -> V_194 ) ;
F_102 ( V_56 , V_401 ) ;
if ( V_23 -> V_112 > V_23 -> V_117 ) {
V_24 = - V_410 ;
break;
}
if ( V_56 -> V_193 >= V_23 -> V_112 )
break;
V_23 -> V_110 = V_56 ;
V_23 -> V_111 = V_56 ;
V_56 = NULL ;
V_24 = 0 ;
break;
case V_409 :
if ( ! V_23 -> V_110 )
break;
F_297 ( V_23 -> V_110 , V_56 ,
& V_23 -> V_111 ) ;
V_56 = NULL ;
if ( V_23 -> V_110 -> V_193 >= V_23 -> V_112 )
break;
V_24 = 0 ;
break;
case V_408 :
if ( ! V_23 -> V_110 )
break;
F_297 ( V_23 -> V_110 , V_56 ,
& V_23 -> V_111 ) ;
V_56 = NULL ;
if ( V_23 -> V_110 -> V_193 != V_23 -> V_112 )
break;
V_24 = V_23 -> V_46 -> V_428 ( V_23 , V_23 -> V_110 ) ;
if ( ! V_24 ) {
V_23 -> V_110 = NULL ;
V_23 -> V_111 = NULL ;
V_23 -> V_112 = 0 ;
}
break;
}
if ( V_24 ) {
F_97 ( V_56 ) ;
F_97 ( V_23 -> V_110 ) ;
V_23 -> V_110 = NULL ;
V_23 -> V_111 = NULL ;
V_23 -> V_112 = 0 ;
}
return V_24 ;
}
static int F_301 ( struct V_11 * V_23 )
{
return 0 ;
}
void F_302 ( struct V_11 * V_23 , int V_606 )
{
T_1 V_418 ;
if ( V_23 -> V_147 != V_150 )
return;
V_418 = V_606 ? V_419 : V_421 ;
F_129 ( V_23 , NULL , NULL , V_418 ) ;
}
static int F_303 ( struct V_11 * V_23 )
{
int V_24 = 0 ;
F_23 ( L_3 , V_23 ) ;
while ( ! F_70 ( V_264 , & V_23 -> V_258 ) ) {
struct V_52 * V_56 ;
F_23 ( L_74 ,
V_23 -> V_265 , F_177 ( & V_23 -> V_151 ) ) ;
V_56 = F_33 ( & V_23 -> V_151 , V_23 -> V_265 ) ;
if ( ! V_56 )
break;
F_208 ( V_56 , & V_23 -> V_151 ) ;
V_23 -> V_265 = F_172 ( V_23 , V_23 -> V_265 ) ;
V_24 = F_299 ( V_23 , V_56 , & F_35 ( V_56 ) -> V_57 ) ;
if ( V_24 )
break;
}
if ( F_170 ( & V_23 -> V_151 ) ) {
V_23 -> V_291 = V_386 ;
F_185 ( V_23 ) ;
}
return V_24 ;
}
static void F_304 ( struct V_11 * V_23 ,
struct V_210 * V_211 )
{
struct V_52 * V_56 ;
F_23 ( L_10 , V_23 , V_211 ) ;
if ( V_211 -> V_212 == V_23 -> V_377 ) {
F_23 ( L_75 , V_211 -> V_212 ) ;
F_86 ( V_23 , V_326 ) ;
return;
}
V_56 = F_33 ( & V_23 -> V_119 , V_211 -> V_212 ) ;
if ( V_56 == NULL ) {
F_23 ( L_76 ,
V_211 -> V_212 ) ;
return;
}
if ( V_23 -> V_95 != 0 && F_35 ( V_56 ) -> V_57 . V_285 >= V_23 -> V_95 ) {
F_23 ( L_21 , V_23 -> V_95 ) ;
F_86 ( V_23 , V_326 ) ;
return;
}
F_117 ( V_293 , & V_23 -> V_258 ) ;
if ( V_211 -> V_220 ) {
F_213 ( V_23 , V_211 ) ;
F_57 ( V_257 , & V_23 -> V_258 ) ;
F_182 ( V_23 , V_211 ) ;
F_173 ( V_23 ) ;
if ( V_23 -> V_289 == V_423 ) {
F_57 ( V_288 , & V_23 -> V_258 ) ;
V_23 -> V_607 = V_211 -> V_212 ;
}
} else {
F_214 ( V_23 , V_211 ) ;
if ( V_211 -> V_215 ) {
if ( V_23 -> V_607 != V_211 -> V_212 ||
! F_116 ( V_288 ,
& V_23 -> V_258 ) )
F_182 ( V_23 , V_211 ) ;
} else {
F_182 ( V_23 , V_211 ) ;
if ( V_23 -> V_289 == V_423 ) {
F_57 ( V_288 , & V_23 -> V_258 ) ;
V_23 -> V_607 = V_211 -> V_212 ;
}
}
}
}
static void F_305 ( struct V_11 * V_23 ,
struct V_210 * V_211 )
{
struct V_52 * V_56 ;
F_23 ( L_10 , V_23 , V_211 ) ;
if ( V_211 -> V_212 == V_23 -> V_377 ) {
F_23 ( L_75 , V_211 -> V_212 ) ;
F_86 ( V_23 , V_326 ) ;
return;
}
V_56 = F_33 ( & V_23 -> V_119 , V_211 -> V_212 ) ;
if ( V_23 -> V_95 && V_56 &&
F_35 ( V_56 ) -> V_57 . V_285 >= V_23 -> V_95 ) {
F_23 ( L_21 , V_23 -> V_95 ) ;
F_86 ( V_23 , V_326 ) ;
return;
}
F_117 ( V_293 , & V_23 -> V_258 ) ;
F_213 ( V_23 , V_211 ) ;
if ( V_211 -> V_215 ) {
if ( ! F_116 ( V_287 , & V_23 -> V_258 ) )
F_183 ( V_23 , V_211 ) ;
} else {
F_183 ( V_23 , V_211 ) ;
F_173 ( V_23 ) ;
if ( V_23 -> V_289 == V_423 )
F_57 ( V_287 , & V_23 -> V_258 ) ;
}
}
static T_1 F_306 ( struct V_11 * V_23 , T_2 V_58 )
{
F_23 ( L_77 , V_23 , V_58 ) ;
F_23 ( L_78 , V_23 -> V_263 ,
V_23 -> V_286 ) ;
if ( V_23 -> V_291 == V_420 ) {
if ( F_186 ( V_23 , V_58 , V_23 -> V_263 ) >=
V_23 -> V_97 ) {
if ( V_23 -> V_97 <= ( ( V_23 -> V_99 + 1 ) >> 1 ) ) {
F_23 ( L_79 ) ;
return V_608 ;
} else {
F_23 ( L_80 ) ;
return V_609 ;
}
}
if ( V_23 -> V_152 . V_54 == V_58 ) {
F_23 ( L_81 ) ;
return V_610 ;
}
if ( F_33 ( & V_23 -> V_151 , V_58 ) ) {
F_23 ( L_82 ) ;
return V_611 ;
}
if ( F_41 ( & V_23 -> V_152 , V_58 ) ) {
F_23 ( L_83 ) ;
return V_612 ;
}
}
if ( V_23 -> V_286 == V_58 ) {
if ( F_186 ( V_23 , V_58 , V_23 -> V_263 ) >=
V_23 -> V_97 ) {
F_23 ( L_84 ) ;
return V_609 ;
} else {
F_23 ( L_85 ) ;
return V_613 ;
}
}
if ( F_186 ( V_23 , V_58 , V_23 -> V_263 ) <
F_186 ( V_23 , V_23 -> V_286 , V_23 -> V_263 ) ) {
F_23 ( L_86 ) ;
return V_614 ;
}
if ( F_186 ( V_23 , V_58 , V_23 -> V_263 ) >= V_23 -> V_97 ) {
if ( V_23 -> V_97 <= ( ( V_23 -> V_99 + 1 ) >> 1 ) ) {
F_23 ( L_87 ) ;
return V_608 ;
} else {
F_23 ( L_84 ) ;
return V_609 ;
}
} else {
F_23 ( L_88 ) ;
return V_615 ;
}
}
static int F_307 ( struct V_11 * V_23 ,
struct V_210 * V_211 ,
struct V_52 * V_56 , T_1 V_418 )
{
int V_24 = 0 ;
bool V_616 = false ;
F_23 ( L_89 , V_23 , V_211 , V_56 ,
V_418 ) ;
switch ( V_418 ) {
case V_617 :
switch ( F_306 ( V_23 , V_211 -> V_58 ) ) {
case V_613 :
F_213 ( V_23 , V_211 ) ;
if ( F_70 ( V_264 , & V_23 -> V_258 ) ) {
F_23 ( L_90 ,
V_211 -> V_58 ) ;
break;
}
V_23 -> V_286 = F_172 ( V_23 ,
V_211 -> V_58 ) ;
V_23 -> V_265 = V_23 -> V_286 ;
V_616 = true ;
V_24 = F_299 ( V_23 , V_56 , V_211 ) ;
if ( V_24 )
break;
if ( V_211 -> V_215 ) {
if ( ! F_116 ( V_287 ,
& V_23 -> V_258 ) ) {
V_211 -> V_215 = 0 ;
F_183 ( V_23 , V_211 ) ;
F_173 ( V_23 ) ;
}
}
if ( ! F_70 ( V_264 , & V_23 -> V_258 ) )
F_185 ( V_23 ) ;
break;
case V_615 :
F_213 ( V_23 , V_211 ) ;
if ( F_70 ( V_264 , & V_23 -> V_258 ) ) {
F_23 ( L_91 ,
V_211 -> V_58 ) ;
break;
}
F_308 ( & V_23 -> V_151 , V_56 ) ;
V_616 = true ;
F_23 ( L_92 , V_56 ,
F_177 ( & V_23 -> V_151 ) ) ;
F_117 ( V_288 , & V_23 -> V_258 ) ;
F_43 ( & V_23 -> V_152 ) ;
F_204 ( V_23 , V_211 -> V_58 ) ;
V_23 -> V_291 = V_420 ;
break;
case V_614 :
F_213 ( V_23 , V_211 ) ;
break;
case V_608 :
break;
case V_609 :
default:
F_86 ( V_23 , V_326 ) ;
break;
}
break;
case V_618 :
F_213 ( V_23 , V_211 ) ;
if ( V_211 -> V_215 ) {
F_117 ( V_293 , & V_23 -> V_258 ) ;
if ( ! F_116 ( V_287 , & V_23 -> V_258 ) &&
! F_95 ( V_23 ) ) {
V_211 -> V_215 = 0 ;
F_183 ( V_23 , V_211 ) ;
}
F_173 ( V_23 ) ;
} else if ( V_211 -> V_220 ) {
F_296 ( V_23 ) ;
} else {
if ( F_116 ( V_293 ,
& V_23 -> V_258 ) &&
V_23 -> V_383 )
F_27 ( V_23 ) ;
F_173 ( V_23 ) ;
}
break;
case V_619 :
F_57 ( V_293 , & V_23 -> V_258 ) ;
F_213 ( V_23 , V_211 ) ;
if ( V_211 && V_211 -> V_220 ) {
F_57 ( V_257 , & V_23 -> V_258 ) ;
F_119 ( V_23 , 0 ) ;
}
F_32 ( V_23 ) ;
F_43 ( & V_23 -> V_153 ) ;
break;
case V_620 :
F_305 ( V_23 , V_211 ) ;
break;
case V_621 :
F_304 ( V_23 , V_211 ) ;
break;
default:
break;
}
if ( V_56 && ! V_616 ) {
F_23 ( L_93 , V_56 ) ;
F_97 ( V_56 ) ;
}
return V_24 ;
}
static int F_309 ( struct V_11 * V_23 ,
struct V_210 * V_211 ,
struct V_52 * V_56 , T_1 V_418 )
{
int V_24 = 0 ;
T_2 V_58 = V_211 -> V_58 ;
bool V_616 = false ;
F_23 ( L_89 , V_23 , V_211 , V_56 ,
V_418 ) ;
switch ( V_418 ) {
case V_617 :
switch ( F_306 ( V_23 , V_58 ) ) {
case V_613 :
F_213 ( V_23 , V_211 ) ;
F_308 ( & V_23 -> V_151 , V_56 ) ;
V_616 = true ;
F_23 ( L_92 , V_56 ,
F_177 ( & V_23 -> V_151 ) ) ;
V_23 -> V_286 = F_172 ( V_23 , V_58 ) ;
break;
case V_610 :
F_42 ( & V_23 -> V_152 ) ;
F_213 ( V_23 , V_211 ) ;
F_308 ( & V_23 -> V_151 , V_56 ) ;
V_616 = true ;
F_23 ( L_92 , V_56 ,
F_177 ( & V_23 -> V_151 ) ) ;
V_24 = F_303 ( V_23 ) ;
if ( V_24 )
break;
break;
case V_615 :
F_308 ( & V_23 -> V_151 , V_56 ) ;
V_616 = true ;
F_23 ( L_92 , V_56 ,
F_177 ( & V_23 -> V_151 ) ) ;
F_213 ( V_23 , V_211 ) ;
F_204 ( V_23 , V_211 -> V_58 ) ;
break;
case V_612 :
F_308 ( & V_23 -> V_151 , V_56 ) ;
V_616 = true ;
F_23 ( L_92 , V_56 ,
F_177 ( & V_23 -> V_151 ) ) ;
F_213 ( V_23 , V_211 ) ;
F_206 ( V_23 , V_211 -> V_58 ) ;
break;
case V_611 :
F_213 ( V_23 , V_211 ) ;
break;
case V_614 :
break;
case V_608 :
break;
case V_609 :
default:
F_86 ( V_23 , V_326 ) ;
break;
}
break;
case V_618 :
F_213 ( V_23 , V_211 ) ;
if ( V_211 -> V_215 ) {
F_117 ( V_293 , & V_23 -> V_258 ) ;
if ( ! F_116 ( V_287 ,
& V_23 -> V_258 ) ) {
V_211 -> V_215 = 0 ;
F_183 ( V_23 , V_211 ) ;
}
F_173 ( V_23 ) ;
} else if ( V_211 -> V_220 ) {
if ( F_116 ( V_293 ,
& V_23 -> V_258 ) &&
V_23 -> V_383 ) {
F_27 ( V_23 ) ;
}
F_57 ( V_257 , & V_23 -> V_258 ) ;
F_205 ( V_23 ) ;
} else {
if ( F_116 ( V_293 ,
& V_23 -> V_258 ) &&
V_23 -> V_383 )
F_27 ( V_23 ) ;
F_185 ( V_23 ) ;
}
break;
case V_619 :
F_57 ( V_293 , & V_23 -> V_258 ) ;
F_213 ( V_23 , V_211 ) ;
if ( V_211 -> V_220 ) {
F_205 ( V_23 ) ;
} else {
struct V_210 V_622 ;
memset ( & V_622 , 0 , sizeof( V_622 ) ) ;
V_622 . V_219 = 1 ;
V_622 . V_223 = V_259 ;
V_622 . V_212 = V_23 -> V_265 ;
F_115 ( V_23 , & V_622 ) ;
}
break;
case V_620 :
F_305 ( V_23 , V_211 ) ;
break;
case V_621 :
F_304 ( V_23 , V_211 ) ;
break;
}
if ( V_56 && ! V_616 ) {
F_23 ( L_93 , V_56 ) ;
F_97 ( V_56 ) ;
}
return V_24 ;
}
static int F_310 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
V_23 -> V_291 = V_386 ;
if ( V_23 -> V_206 )
V_23 -> V_13 -> V_164 = V_23 -> V_206 -> V_195 -> V_543 ;
else
V_23 -> V_13 -> V_164 = V_23 -> V_13 -> V_8 -> V_195 -> V_623 ;
return F_301 ( V_23 ) ;
}
static int F_311 ( struct V_11 * V_23 ,
struct V_210 * V_211 ,
struct V_52 * V_56 , T_1 V_418 )
{
int V_24 ;
F_23 ( L_89 , V_23 , V_211 , V_56 ,
V_418 ) ;
if ( ! V_211 -> V_220 )
return - V_506 ;
F_207 ( V_23 , V_211 -> V_212 ) ;
if ( ! F_170 ( & V_23 -> V_119 ) )
V_23 -> V_382 = F_211 ( & V_23 -> V_119 ) ;
else
V_23 -> V_382 = NULL ;
V_23 -> V_377 = V_211 -> V_212 ;
V_23 -> V_383 = 0 ;
V_24 = F_310 ( V_23 ) ;
if ( V_24 )
return V_24 ;
F_57 ( V_257 , & V_23 -> V_258 ) ;
F_296 ( V_23 ) ;
if ( V_418 == V_617 )
return - V_506 ;
return F_307 ( V_23 , V_211 , NULL , V_418 ) ;
}
static int F_312 ( struct V_11 * V_23 ,
struct V_210 * V_211 ,
struct V_52 * V_56 , T_1 V_418 )
{
int V_24 ;
if ( ! V_211 -> V_215 )
return - V_506 ;
F_117 ( V_293 , & V_23 -> V_258 ) ;
V_23 -> V_291 = V_386 ;
F_207 ( V_23 , V_211 -> V_212 ) ;
if ( ! F_170 ( & V_23 -> V_119 ) )
V_23 -> V_382 = F_211 ( & V_23 -> V_119 ) ;
else
V_23 -> V_382 = NULL ;
V_23 -> V_377 = V_211 -> V_212 ;
V_23 -> V_383 = 0 ;
if ( V_23 -> V_206 )
V_23 -> V_13 -> V_164 = V_23 -> V_206 -> V_195 -> V_543 ;
else
V_23 -> V_13 -> V_164 = V_23 -> V_13 -> V_8 -> V_195 -> V_623 ;
V_24 = F_301 ( V_23 ) ;
if ( ! V_24 )
V_24 = F_307 ( V_23 , V_211 , V_56 , V_418 ) ;
return V_24 ;
}
static bool F_313 ( struct V_11 * V_23 , T_2 V_212 )
{
T_2 V_624 ;
V_624 = F_186 ( V_23 , V_23 -> V_377 , V_23 -> V_417 ) ;
return F_186 ( V_23 , V_23 -> V_377 , V_212 ) <= V_624 ;
}
static int F_314 ( struct V_11 * V_23 , struct V_210 * V_211 ,
struct V_52 * V_56 , T_1 V_418 )
{
int V_24 = 0 ;
F_23 ( L_94 , V_23 ,
V_211 , V_56 , V_418 , V_23 -> V_291 ) ;
if ( F_313 ( V_23 , V_211 -> V_212 ) ) {
switch ( V_23 -> V_291 ) {
case V_386 :
V_24 = F_307 ( V_23 , V_211 , V_56 , V_418 ) ;
break;
case V_420 :
V_24 = F_309 ( V_23 , V_211 , V_56 ,
V_418 ) ;
break;
case V_300 :
V_24 = F_311 ( V_23 , V_211 , V_56 , V_418 ) ;
break;
case V_298 :
V_24 = F_312 ( V_23 , V_211 , V_56 , V_418 ) ;
break;
default:
break;
}
} else {
F_23 ( L_95 ,
V_211 -> V_212 , V_23 -> V_377 ,
V_23 -> V_417 ) ;
F_86 ( V_23 , V_326 ) ;
}
return V_24 ;
}
static int F_315 ( struct V_11 * V_23 , struct V_210 * V_211 ,
struct V_52 * V_56 )
{
F_23 ( L_96 , V_23 , V_211 , V_56 ,
V_23 -> V_291 ) ;
if ( F_306 ( V_23 , V_211 -> V_58 ) ==
V_613 ) {
F_213 ( V_23 , V_211 ) ;
F_23 ( L_97 , V_23 -> V_265 ,
F_172 ( V_23 , V_23 -> V_265 ) ) ;
V_23 -> V_265 = F_172 ( V_23 , V_23 -> V_265 ) ;
F_299 ( V_23 , V_56 , V_211 ) ;
} else {
if ( V_23 -> V_110 ) {
F_97 ( V_23 -> V_110 ) ;
V_23 -> V_110 = NULL ;
}
V_23 -> V_111 = NULL ;
V_23 -> V_112 = 0 ;
if ( V_56 ) {
F_23 ( L_93 , V_56 ) ;
F_97 ( V_56 ) ;
}
}
V_23 -> V_263 = V_211 -> V_58 ;
V_23 -> V_286 = F_172 ( V_23 , V_211 -> V_58 ) ;
return 0 ;
}
static int F_316 ( struct V_11 * V_23 , struct V_52 * V_56 )
{
struct V_210 * V_211 = & F_35 ( V_56 ) -> V_57 ;
T_2 V_193 ;
T_1 V_418 ;
F_100 ( V_23 , V_56 ) ;
V_193 = V_56 -> V_193 ;
if ( F_294 ( V_23 , V_56 ) )
goto V_598;
if ( ! V_211 -> V_219 && V_211 -> V_226 == V_407 )
V_193 -= V_401 ;
if ( V_23 -> V_93 == V_94 )
V_193 -= V_255 ;
if ( V_193 > V_23 -> V_116 ) {
F_86 ( V_23 , V_326 ) ;
goto V_598;
}
if ( ( V_23 -> V_147 == V_150 ||
V_23 -> V_147 == V_154 ) && F_317 ( V_23 -> V_194 , V_56 ) )
goto V_598;
if ( ! V_211 -> V_219 ) {
int V_24 ;
F_23 ( L_98 ,
V_211 -> V_226 , V_211 -> V_212 , V_211 -> V_215 ,
V_211 -> V_58 ) ;
if ( V_211 -> V_215 && V_23 -> V_289 != V_423 )
goto V_598;
if ( V_23 -> V_147 != V_154 ) {
V_418 = V_617 ;
V_24 = F_314 ( V_23 , V_211 , V_56 , V_418 ) ;
} else {
V_24 = F_315 ( V_23 , V_211 , V_56 ) ;
}
if ( V_24 )
F_86 ( V_23 , V_326 ) ;
} else {
const T_1 V_625 [ 4 ] = {
V_618 , V_620 ,
V_619 , V_621
} ;
if ( V_23 -> V_147 == V_154 )
goto V_598;
F_23 ( L_99 ,
V_211 -> V_212 , V_211 -> V_215 , V_211 -> V_220 ,
V_211 -> V_223 ) ;
if ( V_193 != 0 ) {
F_286 ( L_100 , V_193 ) ;
F_86 ( V_23 , V_326 ) ;
goto V_598;
}
if ( V_211 -> V_215 && ( V_211 -> V_220 ||
V_23 -> V_289 != V_423 ) )
goto V_598;
V_418 = V_625 [ V_211 -> V_223 ] ;
if ( F_314 ( V_23 , V_211 , V_56 , V_418 ) )
F_86 ( V_23 , V_326 ) ;
}
return 0 ;
V_598:
F_97 ( V_56 ) ;
return 0 ;
}
static void F_318 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct F_289 V_593 ;
T_2 V_626 ;
if ( V_23 -> V_114 >= ( V_115 + 1 ) / 2 )
return;
V_626 = V_115 - V_23 -> V_114 ;
F_23 ( L_101 , V_23 , V_626 ) ;
V_23 -> V_114 += V_626 ;
V_593 . V_14 = F_18 ( V_23 -> V_17 ) ;
V_593 . V_165 = F_18 ( V_626 ) ;
V_23 -> V_19 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_597 , sizeof( V_593 ) , & V_593 ) ;
}
static int F_319 ( struct V_11 * V_23 , struct V_52 * V_56 )
{
int V_24 ;
if ( ! V_23 -> V_114 ) {
F_286 ( L_102 ) ;
F_86 ( V_23 , V_326 ) ;
return - V_627 ;
}
if ( V_23 -> V_117 < V_56 -> V_193 ) {
F_286 ( L_103 ) ;
return - V_627 ;
}
V_23 -> V_114 -- ;
F_23 ( L_104 , V_23 -> V_114 + 1 , V_23 -> V_114 ) ;
F_318 ( V_23 ) ;
V_24 = 0 ;
if ( ! V_23 -> V_110 ) {
T_2 V_112 ;
V_112 = F_103 ( V_56 -> V_194 ) ;
F_102 ( V_56 , V_401 ) ;
F_23 ( L_105 ,
V_112 , V_56 -> V_193 , V_23 -> V_117 ) ;
if ( V_112 > V_23 -> V_117 ) {
F_286 ( L_106 ) ;
V_24 = - V_410 ;
goto V_628;
}
if ( V_56 -> V_193 > V_112 ) {
F_286 ( L_107 ) ;
V_24 = - V_36 ;
goto V_628;
}
if ( V_56 -> V_193 == V_112 )
return V_23 -> V_46 -> V_428 ( V_23 , V_56 ) ;
V_23 -> V_110 = V_56 ;
V_23 -> V_112 = V_112 ;
V_23 -> V_111 = V_56 ;
return 0 ;
}
F_23 ( L_108 ,
V_23 -> V_110 -> V_193 , V_56 -> V_193 , V_23 -> V_112 ) ;
if ( V_23 -> V_110 -> V_193 + V_56 -> V_193 > V_23 -> V_112 ) {
F_286 ( L_107 ) ;
V_24 = - V_36 ;
goto V_628;
}
F_297 ( V_23 -> V_110 , V_56 , & V_23 -> V_111 ) ;
V_56 = NULL ;
if ( V_23 -> V_110 -> V_193 == V_23 -> V_112 ) {
V_24 = V_23 -> V_46 -> V_428 ( V_23 , V_23 -> V_110 ) ;
if ( ! V_24 ) {
V_23 -> V_110 = NULL ;
V_23 -> V_111 = NULL ;
V_23 -> V_112 = 0 ;
}
}
V_628:
if ( V_24 ) {
F_97 ( V_56 ) ;
F_97 ( V_23 -> V_110 ) ;
V_23 -> V_110 = NULL ;
V_23 -> V_111 = NULL ;
V_23 -> V_112 = 0 ;
}
return 0 ;
}
static void F_320 ( struct V_12 * V_13 , T_2 V_14 ,
struct V_52 * V_56 )
{
struct V_11 * V_23 ;
V_23 = F_7 ( V_13 , V_14 ) ;
if ( ! V_23 ) {
if ( V_14 == V_322 ) {
V_23 = F_321 ( V_13 , V_56 ) ;
if ( ! V_23 ) {
F_97 ( V_56 ) ;
return;
}
F_9 ( V_23 ) ;
} else {
F_23 ( L_109 , V_14 ) ;
F_97 ( V_56 ) ;
return;
}
}
F_23 ( L_110 , V_23 , V_56 -> V_193 ) ;
if ( V_23 -> V_39 == V_40 )
F_130 ( V_23 ) ;
if ( V_23 -> V_45 != V_75 )
goto V_598;
switch ( V_23 -> V_147 ) {
case V_149 :
if ( F_319 ( V_23 , V_56 ) < 0 )
goto V_598;
goto V_27;
case V_148 :
if ( V_23 -> V_117 < V_56 -> V_193 ) {
F_286 ( L_111 ) ;
goto V_598;
}
if ( ! V_23 -> V_46 -> V_428 ( V_23 , V_56 ) )
goto V_27;
break;
case V_150 :
case V_154 :
F_316 ( V_23 , V_56 ) ;
goto V_27;
default:
F_23 ( L_112 , V_23 , V_23 -> V_147 ) ;
break;
}
V_598:
F_97 ( V_56 ) ;
V_27:
F_48 ( V_23 ) ;
}
static void F_322 ( struct V_12 * V_13 , T_3 V_20 ,
struct V_52 * V_56 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_11 * V_23 ;
if ( V_8 -> type != V_123 )
goto V_629;
V_23 = F_165 ( 0 , V_20 , & V_8 -> V_21 , & V_8 -> V_156 ,
V_123 ) ;
if ( ! V_23 )
goto V_629;
F_23 ( L_110 , V_23 , V_56 -> V_193 ) ;
if ( V_23 -> V_45 != V_630 && V_23 -> V_45 != V_75 )
goto V_598;
if ( V_23 -> V_117 < V_56 -> V_193 )
goto V_598;
F_81 ( & F_35 ( V_56 ) -> V_57 . V_631 , & V_8 -> V_156 ) ;
F_35 ( V_56 ) -> V_57 . V_20 = V_20 ;
if ( ! V_23 -> V_46 -> V_428 ( V_23 , V_56 ) ) {
F_49 ( V_23 ) ;
return;
}
V_598:
F_49 ( V_23 ) ;
V_629:
F_97 ( V_56 ) ;
}
static void F_323 ( struct V_12 * V_13 , struct V_52 * V_56 )
{
struct V_252 * V_253 = ( void * ) V_56 -> V_194 ;
struct V_7 * V_8 = V_13 -> V_8 ;
T_2 V_14 , V_193 ;
T_3 V_20 ;
if ( V_8 -> V_45 != V_75 ) {
F_23 ( L_113 ) ;
F_308 ( & V_13 -> V_365 , V_56 ) ;
return;
}
F_102 ( V_56 , V_249 ) ;
V_14 = F_69 ( V_253 -> V_14 ) ;
V_193 = F_69 ( V_253 -> V_193 ) ;
if ( V_193 != V_56 -> V_193 ) {
F_97 ( V_56 ) ;
return;
}
if ( V_8 -> type == V_2 &&
F_324 ( & V_8 -> V_195 -> V_632 , & V_8 -> V_156 ,
F_3 ( V_8 ) ) ) {
F_97 ( V_56 ) ;
return;
}
F_23 ( L_114 , V_193 , V_14 ) ;
switch ( V_14 ) {
case V_126 :
F_293 ( V_13 , V_56 ) ;
break;
case V_125 :
V_20 = F_325 ( ( T_3 * ) V_56 -> V_194 ) ;
F_102 ( V_56 , V_399 ) ;
F_322 ( V_13 , V_20 , V_56 ) ;
break;
case V_433 :
F_292 ( V_13 , V_56 ) ;
break;
default:
F_320 ( V_13 , V_14 , V_56 ) ;
break;
}
}
static void F_326 ( struct V_71 * V_72 )
{
struct V_12 * V_13 = F_46 ( V_72 , struct V_12 ,
V_353 ) ;
struct V_52 * V_56 ;
F_23 ( L_115 ) ;
while ( ( V_56 = F_171 ( & V_13 -> V_365 ) ) )
F_323 ( V_13 , V_56 ) ;
}
static struct V_12 * F_327 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_362 ;
struct V_146 * V_202 ;
if ( V_13 )
return V_13 ;
V_202 = F_328 ( V_8 ) ;
if ( ! V_202 )
return NULL ;
V_13 = F_51 ( sizeof( * V_13 ) , V_65 ) ;
if ( ! V_13 ) {
F_159 ( V_202 ) ;
return NULL ;
}
F_56 ( & V_13 -> V_367 ) ;
V_8 -> V_362 = V_13 ;
V_13 -> V_8 = F_329 ( V_8 ) ;
V_13 -> V_202 = V_202 ;
F_23 ( L_116 , V_8 , V_13 , V_202 ) ;
switch ( V_8 -> type ) {
case V_2 :
if ( V_8 -> V_195 -> V_633 ) {
V_13 -> V_164 = V_8 -> V_195 -> V_633 ;
break;
}
default:
V_13 -> V_164 = V_8 -> V_195 -> V_623 ;
break;
}
V_13 -> V_315 = 0 ;
V_13 -> V_269 = V_634 | V_635 ;
if ( V_8 -> type == V_123 &&
F_241 ( V_8 -> V_195 , V_636 ) )
V_13 -> V_269 |= V_270 ;
if ( F_241 ( V_8 -> V_195 , V_637 ) &&
( F_330 ( V_8 -> V_195 ) ||
F_241 ( V_8 -> V_195 , V_638 ) ) )
V_13 -> V_269 |= V_639 ;
F_52 ( & V_13 -> V_190 ) ;
F_52 ( & V_13 -> V_18 ) ;
F_331 ( & V_13 -> V_140 ) ;
F_331 ( & V_13 -> V_361 ) ;
F_55 ( & V_13 -> V_311 , F_147 ) ;
F_67 ( & V_13 -> V_365 ) ;
F_332 ( & V_13 -> V_353 , F_326 ) ;
F_332 ( & V_13 -> V_155 , F_80 ) ;
V_13 -> V_120 = V_121 ;
return V_13 ;
}
static bool F_333 ( T_2 V_20 , T_1 V_10 ) {
if ( ! V_20 )
return false ;
if ( F_334 ( V_10 ) )
return ( V_20 <= 0x00ff ) ;
return ( ( V_20 & 0x0101 ) == 0x0001 ) ;
}
int F_335 ( struct V_11 * V_23 , T_3 V_20 , T_2 V_14 ,
T_4 * V_156 , T_1 V_10 )
{
struct V_12 * V_13 ;
struct V_7 * V_8 ;
struct V_267 * V_195 ;
int V_24 ;
F_23 ( L_117 , & V_23 -> V_21 , V_156 ,
V_10 , F_69 ( V_20 ) ) ;
V_195 = F_336 ( V_156 , & V_23 -> V_21 , V_23 -> V_9 ) ;
if ( ! V_195 )
return - V_640 ;
F_149 ( V_195 ) ;
if ( ! F_333 ( F_69 ( V_20 ) , V_10 ) && ! V_14 &&
V_23 -> V_39 != V_175 ) {
V_24 = - V_36 ;
goto V_27;
}
if ( V_23 -> V_39 == V_122 && ! V_20 ) {
V_24 = - V_36 ;
goto V_27;
}
if ( V_23 -> V_39 == V_40 && ! V_14 ) {
V_24 = - V_36 ;
goto V_27;
}
switch ( V_23 -> V_147 ) {
case V_148 :
break;
case V_149 :
F_65 ( V_23 ) ;
break;
case V_150 :
case V_154 :
if ( ! V_318 )
break;
default:
V_24 = - V_641 ;
goto V_27;
}
switch ( V_23 -> V_45 ) {
case V_78 :
case V_174 :
case V_76 :
V_24 = 0 ;
goto V_27;
case V_75 :
V_24 = - V_642 ;
goto V_27;
case V_89 :
case V_630 :
break;
default:
V_24 = - V_413 ;
goto V_27;
}
F_81 ( & V_23 -> V_156 , V_156 ) ;
V_23 -> V_10 = V_10 ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_14 ;
if ( F_334 ( V_10 ) ) {
if ( V_10 == V_4 )
V_10 = V_3 ;
else
V_10 = V_643 ;
if ( F_241 ( V_195 , V_644 ) )
V_8 = F_337 ( V_195 , V_156 , V_10 ,
V_23 -> V_79 ,
V_645 ,
V_340 ) ;
else
V_8 = F_338 ( V_195 , V_156 , V_10 ,
V_23 -> V_79 ,
V_645 ) ;
} else {
T_1 V_188 = F_87 ( V_23 ) ;
V_8 = F_339 ( V_195 , V_156 , V_23 -> V_79 , V_188 ) ;
}
if ( F_118 ( V_8 ) ) {
V_24 = F_191 ( V_8 ) ;
goto V_27;
}
V_13 = F_327 ( V_8 ) ;
if ( ! V_13 ) {
F_75 ( V_8 ) ;
V_24 = - V_66 ;
goto V_27;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_23 ) ;
if ( V_14 && F_4 ( V_13 , V_14 ) ) {
F_75 ( V_8 ) ;
V_24 = - V_646 ;
goto V_647;
}
F_81 ( & V_23 -> V_21 , & V_8 -> V_21 ) ;
V_23 -> V_9 = F_2 ( V_8 ) ;
F_68 ( V_13 , V_23 ) ;
F_75 ( V_8 ) ;
F_22 ( V_23 , V_78 ) ;
F_85 ( V_23 , V_23 -> V_46 -> V_173 ( V_23 ) ) ;
F_17 ( & V_25 ) ;
V_23 -> V_22 = 0 ;
F_19 ( & V_25 ) ;
if ( V_8 -> V_45 == V_75 ) {
if ( V_23 -> V_39 != V_122 ) {
F_74 ( V_23 ) ;
if ( F_88 ( V_23 , true ) )
F_22 ( V_23 , V_75 ) ;
} else
F_138 ( V_23 ) ;
}
V_24 = 0 ;
V_647:
F_48 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
V_27:
F_151 ( V_195 ) ;
F_257 ( V_195 ) ;
return V_24 ;
}
int F_340 ( struct V_267 * V_195 , T_4 * V_631 )
{
int V_648 = 0 , V_649 = 0 , V_650 = 0 ;
struct V_11 * V_15 ;
F_23 ( L_118 , V_195 -> V_336 , V_631 ) ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
if ( V_15 -> V_45 != V_172 )
continue;
if ( ! F_15 ( & V_15 -> V_21 , & V_195 -> V_631 ) ) {
V_649 |= V_651 ;
if ( F_70 ( V_652 , & V_15 -> V_109 ) )
V_649 |= V_653 ;
V_648 ++ ;
} else if ( ! F_15 ( & V_15 -> V_21 , V_373 ) ) {
V_650 |= V_651 ;
if ( F_70 ( V_652 , & V_15 -> V_109 ) )
V_650 |= V_653 ;
}
}
F_123 ( & V_25 ) ;
return V_648 ? V_649 : V_650 ;
}
static struct V_11 * F_341 ( struct V_11 * V_15 ,
struct V_7 * V_8 )
{
T_1 V_9 = F_2 ( V_8 ) ;
F_122 ( & V_25 ) ;
if ( V_15 )
V_15 = F_342 ( V_15 , V_87 ) ;
else
V_15 = F_343 ( V_88 . V_398 , F_344 ( * V_15 ) , V_87 ) ;
F_345 (c, &chan_list, global_l) {
if ( V_15 -> V_39 != V_40 )
continue;
if ( V_15 -> V_45 != V_172 )
continue;
if ( F_15 ( & V_15 -> V_21 , & V_8 -> V_21 ) && F_15 ( & V_15 -> V_21 , V_373 ) )
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
static void F_346 ( struct V_7 * V_8 , T_1 V_169 )
{
struct V_267 * V_195 = V_8 -> V_195 ;
struct V_12 * V_13 ;
struct V_11 * V_508 ;
T_1 V_10 ;
if ( V_8 -> type != V_123 && V_8 -> type != V_2 )
return;
F_23 ( L_119 , V_8 , & V_8 -> V_156 , V_169 ) ;
if ( V_169 ) {
F_156 ( V_8 , F_347 ( V_169 ) ) ;
return;
}
V_13 = F_327 ( V_8 ) ;
if ( ! V_13 )
return;
V_10 = F_3 ( V_8 ) ;
if ( F_324 ( & V_195 -> V_632 , & V_8 -> V_156 , V_10 ) )
return;
V_508 = F_341 ( NULL , V_8 ) ;
while ( V_508 ) {
struct V_11 * V_23 , * V_398 ;
if ( F_4 ( V_13 , V_508 -> V_17 ) )
goto V_398;
F_9 ( V_508 ) ;
V_23 = V_508 -> V_46 -> V_513 ( V_508 ) ;
if ( V_23 ) {
F_81 ( & V_23 -> V_21 , & V_8 -> V_21 ) ;
F_81 ( & V_23 -> V_156 , & V_8 -> V_156 ) ;
V_23 -> V_9 = F_2 ( V_8 ) ;
V_23 -> V_10 = V_10 ;
F_68 ( V_13 , V_23 ) ;
}
F_48 ( V_508 ) ;
V_398:
V_398 = F_341 ( V_508 , V_8 ) ;
F_49 ( V_508 ) ;
V_508 = V_398 ;
}
F_144 ( V_13 ) ;
}
int F_348 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_362 ;
F_23 ( L_120 , V_8 ) ;
if ( ! V_13 )
return V_121 ;
return V_13 -> V_120 ;
}
static void F_349 ( struct V_7 * V_8 , T_1 V_74 )
{
if ( V_8 -> type != V_123 && V_8 -> type != V_2 )
return;
F_23 ( L_121 , V_8 , V_74 ) ;
F_156 ( V_8 , F_347 ( V_74 ) ) ;
}
static inline void F_350 ( struct V_11 * V_23 , T_1 V_654 )
{
if ( V_23 -> V_39 != V_122 )
return;
if ( V_654 == 0x00 ) {
if ( V_23 -> V_79 == V_179 ) {
F_85 ( V_23 , V_655 ) ;
} else if ( V_23 -> V_79 == V_176 ||
V_23 -> V_79 == V_177 )
F_47 ( V_23 , V_77 ) ;
} else {
if ( V_23 -> V_79 == V_179 )
F_74 ( V_23 ) ;
}
}
static void F_351 ( struct V_7 * V_8 , T_1 V_169 , T_1 V_654 )
{
struct V_12 * V_13 = V_8 -> V_362 ;
struct V_11 * V_23 ;
if ( ! V_13 )
return;
F_23 ( L_122 , V_13 , V_169 , V_654 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
F_9 ( V_23 ) ;
F_23 ( L_123 , V_23 , V_23 -> V_17 ,
F_24 ( V_23 -> V_45 ) ) ;
if ( V_23 -> V_17 == V_322 ) {
F_48 ( V_23 ) ;
continue;
}
if ( ! V_169 && V_654 )
V_23 -> V_79 = V_8 -> V_79 ;
if ( ! F_120 ( V_23 ) ) {
F_48 ( V_23 ) ;
continue;
}
if ( ! V_169 && ( V_23 -> V_45 == V_75 ||
V_23 -> V_45 == V_76 ) ) {
V_23 -> V_46 -> V_596 ( V_23 ) ;
F_350 ( V_23 , V_654 ) ;
F_48 ( V_23 ) ;
continue;
}
if ( V_23 -> V_45 == V_78 ) {
if ( ! V_169 )
F_134 ( V_23 ) ;
else
F_85 ( V_23 , V_656 ) ;
} else if ( V_23 -> V_45 == V_174 &&
V_23 -> V_147 != V_149 ) {
struct V_167 V_158 ;
T_5 V_657 , V_658 ;
if ( ! V_169 ) {
if ( F_70 ( V_160 , & V_23 -> V_109 ) ) {
V_657 = V_328 ;
V_658 = V_329 ;
V_23 -> V_46 -> V_330 ( V_23 ) ;
} else {
F_22 ( V_23 , V_76 ) ;
V_657 = V_331 ;
V_658 = V_170 ;
}
} else {
F_22 ( V_23 , V_163 ) ;
F_85 ( V_23 , V_656 ) ;
V_657 = V_168 ;
V_658 = V_170 ;
}
V_158 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_158 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_158 . V_159 = F_18 ( V_657 ) ;
V_158 . V_169 = F_18 ( V_658 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_171 ,
sizeof( V_158 ) , & V_158 ) ;
if ( ! F_70 ( V_333 , & V_23 -> V_92 ) &&
V_657 == V_331 ) {
char V_327 [ 128 ] ;
F_57 ( V_333 , & V_23 -> V_92 ) ;
F_83 ( V_13 , F_91 ( V_13 ) ,
V_334 ,
F_142 ( V_23 , V_327 ) ,
V_327 ) ;
V_23 -> V_335 ++ ;
}
}
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
void F_352 ( struct V_7 * V_8 , struct V_52 * V_56 , T_2 V_109 )
{
struct V_12 * V_13 = V_8 -> V_362 ;
struct V_252 * V_659 ;
int V_193 ;
if ( ! V_13 && V_8 -> V_195 -> V_540 != V_660 )
goto V_598;
if ( ! V_13 )
V_13 = F_327 ( V_8 ) ;
if ( ! V_13 )
goto V_598;
F_23 ( L_124 , V_13 , V_56 -> V_193 , V_109 ) ;
switch ( V_109 ) {
case V_197 :
case V_196 :
case V_207 :
if ( V_13 -> V_661 ) {
F_286 ( L_125 , V_56 -> V_193 ) ;
F_97 ( V_13 -> V_364 ) ;
V_13 -> V_364 = NULL ;
V_13 -> V_661 = 0 ;
F_146 ( V_13 , V_662 ) ;
}
if ( V_56 -> V_193 < V_249 ) {
F_286 ( L_126 , V_56 -> V_193 ) ;
F_146 ( V_13 , V_662 ) ;
goto V_598;
}
V_659 = (struct V_252 * ) V_56 -> V_194 ;
V_193 = F_69 ( V_659 -> V_193 ) + V_249 ;
if ( V_193 == V_56 -> V_193 ) {
F_323 ( V_13 , V_56 ) ;
return;
}
F_23 ( L_127 , V_193 , V_56 -> V_193 ) ;
if ( V_56 -> V_193 > V_193 ) {
F_286 ( L_128 ,
V_56 -> V_193 , V_193 ) ;
F_146 ( V_13 , V_662 ) ;
goto V_598;
}
V_13 -> V_364 = F_111 ( V_193 , V_65 ) ;
if ( ! V_13 -> V_364 )
goto V_598;
F_353 ( V_56 , F_113 ( V_13 -> V_364 , V_56 -> V_193 ) ,
V_56 -> V_193 ) ;
V_13 -> V_661 = V_193 - V_56 -> V_193 ;
break;
case V_663 :
F_23 ( L_129 , V_56 -> V_193 , V_13 -> V_661 ) ;
if ( ! V_13 -> V_661 ) {
F_286 ( L_130 , V_56 -> V_193 ) ;
F_146 ( V_13 , V_662 ) ;
goto V_598;
}
if ( V_56 -> V_193 > V_13 -> V_661 ) {
F_286 ( L_131 ,
V_56 -> V_193 , V_13 -> V_661 ) ;
F_97 ( V_13 -> V_364 ) ;
V_13 -> V_364 = NULL ;
V_13 -> V_661 = 0 ;
F_146 ( V_13 , V_662 ) ;
goto V_598;
}
F_353 ( V_56 , F_113 ( V_13 -> V_364 , V_56 -> V_193 ) ,
V_56 -> V_193 ) ;
V_13 -> V_661 -= V_56 -> V_193 ;
if ( ! V_13 -> V_661 ) {
struct V_52 * V_364 = V_13 -> V_364 ;
V_13 -> V_364 = NULL ;
F_323 ( V_13 , V_364 ) ;
}
break;
}
V_598:
F_97 ( V_56 ) ;
}
static int F_354 ( struct V_664 * V_665 , void * V_28 )
{
struct V_11 * V_15 ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
F_355 ( V_665 , L_132 ,
& V_15 -> V_21 , V_15 -> V_9 , & V_15 -> V_156 , V_15 -> V_10 ,
V_15 -> V_45 , F_69 ( V_15 -> V_20 ) ,
V_15 -> V_17 , V_15 -> V_16 , V_15 -> V_117 , V_15 -> V_37 ,
V_15 -> V_79 , V_15 -> V_147 ) ;
}
F_123 ( & V_25 ) ;
return 0 ;
}
static int F_356 ( struct V_666 * V_666 , struct V_667 * V_667 )
{
return F_357 ( V_667 , F_354 , V_666 -> V_668 ) ;
}
int T_11 F_358 ( void )
{
int V_24 ;
V_24 = F_359 () ;
if ( V_24 < 0 )
return V_24 ;
F_360 ( & V_669 ) ;
if ( F_361 ( V_670 ) )
return 0 ;
V_671 = F_362 ( L_133 , 0444 , V_670 ,
NULL , & V_672 ) ;
F_363 ( L_134 , 0644 , V_670 ,
& V_115 ) ;
F_363 ( L_135 , 0644 , V_670 ,
& V_118 ) ;
return 0 ;
}
void F_364 ( void )
{
F_365 ( V_671 ) ;
F_366 ( & V_669 ) ;
F_367 () ;
}
