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
static void F_202 ( struct V_11 * V_23 )
{
int V_380 = 0 ;
F_23 ( L_3 , V_23 ) ;
while ( V_23 -> V_113 && ! F_170 ( & V_23 -> V_119 ) ) {
F_96 ( V_23 , F_171 ( & V_23 -> V_119 ) ) ;
V_23 -> V_113 -- ;
V_380 ++ ;
}
F_23 ( L_28 , V_380 , V_23 -> V_113 ,
F_177 ( & V_23 -> V_119 ) ) ;
}
int F_203 ( struct V_11 * V_23 , struct V_387 * V_388 , T_6 V_193 )
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
F_204 ( & V_402 ) ;
V_24 = F_201 ( V_23 , & V_402 , V_388 , V_193 ) ;
if ( V_23 -> V_45 != V_75 ) {
F_198 ( & V_402 ) ;
V_24 = - V_381 ;
}
if ( V_24 )
return V_24 ;
F_169 ( & V_402 , & V_23 -> V_119 ) ;
F_202 ( V_23 ) ;
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
F_204 ( & V_402 ) ;
V_24 = F_197 ( V_23 , & V_402 , V_388 , V_193 ) ;
if ( V_23 -> V_45 != V_75 ) {
F_198 ( & V_402 ) ;
V_24 = - V_381 ;
}
if ( V_24 )
break;
if ( V_23 -> V_147 == V_150 )
F_129 ( V_23 , NULL , & V_402 , V_411 ) ;
else
F_168 ( V_23 , & V_402 ) ;
V_24 = V_193 ;
F_198 ( & V_402 ) ;
break;
default:
F_23 ( L_29 , V_23 -> V_147 ) ;
V_24 = - V_412 ;
}
return V_24 ;
}
static void F_205 ( struct V_11 * V_23 , T_2 V_58 )
{
struct V_210 V_211 ;
T_2 V_55 ;
F_23 ( L_30 , V_23 , V_58 ) ;
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
static void F_206 ( struct V_11 * V_23 )
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
static void F_207 ( struct V_11 * V_23 , T_2 V_58 )
{
struct V_210 V_211 ;
T_2 V_413 ;
T_2 V_55 ;
F_23 ( L_30 , V_23 , V_58 ) ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
V_211 . V_219 = 1 ;
V_211 . V_223 = V_262 ;
V_413 = V_23 -> V_152 . V_54 ;
do {
V_55 = F_42 ( & V_23 -> V_152 ) ;
if ( V_55 == V_58 || V_55 == V_68 )
break;
V_211 . V_212 = V_55 ;
F_115 ( V_23 , & V_211 ) ;
F_44 ( & V_23 -> V_152 , V_55 ) ;
} while ( V_23 -> V_152 . V_54 != V_413 );
}
static void F_208 ( struct V_11 * V_23 , T_2 V_212 )
{
struct V_52 * V_414 ;
T_2 V_415 ;
F_23 ( L_31 , V_23 , V_212 ) ;
if ( V_23 -> V_383 == 0 || V_212 == V_23 -> V_416 )
return;
F_23 ( L_32 ,
V_23 -> V_416 , V_23 -> V_383 ) ;
for ( V_415 = V_23 -> V_416 ; V_415 != V_212 ;
V_415 = F_172 ( V_23 , V_415 ) ) {
V_414 = F_33 ( & V_23 -> V_119 , V_415 ) ;
if ( V_414 ) {
F_209 ( V_414 , & V_23 -> V_119 ) ;
F_97 ( V_414 ) ;
V_23 -> V_383 -- ;
}
}
V_23 -> V_416 = V_212 ;
if ( V_23 -> V_383 == 0 )
F_32 ( V_23 ) ;
F_23 ( L_33 , V_23 -> V_383 ) ;
}
static void F_210 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
V_23 -> V_286 = V_23 -> V_265 ;
F_43 ( & V_23 -> V_152 ) ;
F_77 ( & V_23 -> V_151 ) ;
V_23 -> V_291 = V_386 ;
}
static void F_211 ( struct V_11 * V_23 ,
struct V_210 * V_211 ,
struct V_53 * V_376 , T_1 V_417 )
{
F_23 ( L_34 , V_23 , V_211 , V_376 ,
V_417 ) ;
switch ( V_417 ) {
case V_411 :
if ( V_23 -> V_382 == NULL )
V_23 -> V_382 = F_212 ( V_376 ) ;
F_169 ( V_376 , & V_23 -> V_119 ) ;
F_173 ( V_23 ) ;
break;
case V_418 :
F_23 ( L_35 ) ;
F_57 ( V_264 , & V_23 -> V_258 ) ;
if ( V_23 -> V_291 == V_419 ) {
F_210 ( V_23 ) ;
}
F_185 ( V_23 ) ;
break;
case V_420 :
F_23 ( L_36 ) ;
F_117 ( V_264 , & V_23 -> V_258 ) ;
if ( F_70 ( V_260 , & V_23 -> V_258 ) ) {
struct V_210 V_421 ;
memset ( & V_421 , 0 , sizeof( V_421 ) ) ;
V_421 . V_219 = 1 ;
V_421 . V_223 = V_259 ;
V_421 . V_220 = 1 ;
V_421 . V_212 = V_23 -> V_265 ;
F_115 ( V_23 , & V_421 ) ;
V_23 -> V_284 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_289 = V_422 ;
}
break;
case V_423 :
F_208 ( V_23 , V_211 -> V_212 ) ;
break;
case V_297 :
F_119 ( V_23 , 1 ) ;
V_23 -> V_284 = 1 ;
F_31 ( V_23 ) ;
F_79 ( V_23 ) ;
V_23 -> V_289 = V_422 ;
break;
case V_375 :
F_119 ( V_23 , 1 ) ;
V_23 -> V_284 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_289 = V_422 ;
break;
case V_424 :
break;
default:
break;
}
}
static void F_213 ( struct V_11 * V_23 ,
struct V_210 * V_211 ,
struct V_53 * V_376 , T_1 V_417 )
{
F_23 ( L_34 , V_23 , V_211 , V_376 ,
V_417 ) ;
switch ( V_417 ) {
case V_411 :
if ( V_23 -> V_382 == NULL )
V_23 -> V_382 = F_212 ( V_376 ) ;
F_169 ( V_376 , & V_23 -> V_119 ) ;
break;
case V_418 :
F_23 ( L_35 ) ;
F_57 ( V_264 , & V_23 -> V_258 ) ;
if ( V_23 -> V_291 == V_419 ) {
F_210 ( V_23 ) ;
}
F_185 ( V_23 ) ;
break;
case V_420 :
F_23 ( L_36 ) ;
F_117 ( V_264 , & V_23 -> V_258 ) ;
if ( F_70 ( V_260 , & V_23 -> V_258 ) ) {
struct V_210 V_421 ;
memset ( & V_421 , 0 , sizeof( V_421 ) ) ;
V_421 . V_219 = 1 ;
V_421 . V_223 = V_259 ;
V_421 . V_220 = 1 ;
V_421 . V_212 = V_23 -> V_265 ;
F_115 ( V_23 , & V_421 ) ;
V_23 -> V_284 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_289 = V_422 ;
}
break;
case V_423 :
F_208 ( V_23 , V_211 -> V_212 ) ;
case V_424 :
if ( V_211 && V_211 -> V_215 ) {
F_78 ( V_23 ) ;
if ( V_23 -> V_383 > 0 )
F_27 ( V_23 ) ;
V_23 -> V_284 = 0 ;
V_23 -> V_289 = V_290 ;
F_23 ( L_37 , V_23 -> V_289 ) ;
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
F_86 ( V_23 , V_425 ) ;
}
break;
default:
break;
}
}
static void F_129 ( struct V_11 * V_23 , struct V_210 * V_211 ,
struct V_53 * V_376 , T_1 V_417 )
{
F_23 ( L_38 ,
V_23 , V_211 , V_376 , V_417 , V_23 -> V_289 ) ;
switch ( V_23 -> V_289 ) {
case V_290 :
F_211 ( V_23 , V_211 , V_376 , V_417 ) ;
break;
case V_422 :
F_213 ( V_23 , V_211 , V_376 , V_417 ) ;
break;
default:
break;
}
}
static void F_214 ( struct V_11 * V_23 ,
struct V_210 * V_211 )
{
F_23 ( L_10 , V_23 , V_211 ) ;
F_129 ( V_23 , V_211 , NULL , V_423 ) ;
}
static void F_215 ( struct V_11 * V_23 ,
struct V_210 * V_211 )
{
F_23 ( L_10 , V_23 , V_211 ) ;
F_129 ( V_23 , V_211 , NULL , V_424 ) ;
}
static void F_216 ( struct V_12 * V_13 , struct V_52 * V_56 )
{
struct V_52 * V_426 ;
struct V_11 * V_23 ;
F_23 ( L_14 , V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
if ( V_23 -> V_39 != V_175 )
continue;
if ( F_35 ( V_56 ) -> V_57 . V_23 == V_23 )
continue;
V_426 = F_174 ( V_56 , V_65 ) ;
if ( ! V_426 )
continue;
if ( V_23 -> V_46 -> V_427 ( V_23 , V_426 ) )
F_97 ( V_426 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static struct V_52 * F_92 ( struct V_12 * V_13 , T_1 V_192 ,
T_1 V_19 , T_2 V_428 , void * V_194 )
{
struct V_52 * V_56 , * * V_390 ;
struct V_429 * V_430 ;
struct V_252 * V_253 ;
int V_193 , V_389 ;
F_23 ( L_39 ,
V_13 , V_192 , V_19 , V_428 ) ;
if ( V_13 -> V_164 < V_249 + V_431 )
return NULL ;
V_193 = V_249 + V_431 + V_428 ;
V_389 = F_66 (unsigned int, conn->mtu, len) ;
V_56 = F_111 ( V_389 , V_65 ) ;
if ( ! V_56 )
return NULL ;
V_253 = (struct V_252 * ) F_113 ( V_56 , V_249 ) ;
V_253 -> V_193 = F_18 ( V_431 + V_428 ) ;
if ( V_13 -> V_8 -> type == V_2 )
V_253 -> V_14 = F_18 ( V_432 ) ;
else
V_253 -> V_14 = F_18 ( V_126 ) ;
V_430 = (struct V_429 * ) F_113 ( V_56 , V_431 ) ;
V_430 -> V_192 = V_192 ;
V_430 -> V_19 = V_19 ;
V_430 -> V_193 = F_18 ( V_428 ) ;
if ( V_428 ) {
V_389 -= V_249 + V_431 ;
memcpy ( F_113 ( V_56 , V_389 ) , V_194 , V_389 ) ;
V_194 += V_389 ;
}
V_193 -= V_56 -> V_193 ;
V_390 = & F_190 ( V_56 ) -> V_393 ;
while ( V_193 ) {
V_389 = F_66 (unsigned int, conn->mtu, len) ;
* V_390 = F_111 ( V_389 , V_65 ) ;
if ( ! * V_390 )
goto V_433;
memcpy ( F_113 ( * V_390 , V_389 ) , V_194 , V_389 ) ;
V_193 -= V_389 ;
V_194 += V_389 ;
V_390 = & ( * V_390 ) -> V_398 ;
}
return V_56 ;
V_433:
F_97 ( V_56 ) ;
return NULL ;
}
static inline int F_217 ( void * * V_434 , int * type , int * V_435 ,
unsigned long * V_436 )
{
struct V_437 * V_438 = * V_434 ;
int V_193 ;
V_193 = V_439 + V_438 -> V_193 ;
* V_434 += V_193 ;
* type = V_438 -> type ;
* V_435 = V_438 -> V_193 ;
switch ( V_438 -> V_193 ) {
case 1 :
* V_436 = * ( ( T_1 * ) V_438 -> V_436 ) ;
break;
case 2 :
* V_436 = F_103 ( V_438 -> V_436 ) ;
break;
case 4 :
* V_436 = F_101 ( V_438 -> V_436 ) ;
break;
default:
* V_436 = ( unsigned long ) V_438 -> V_436 ;
break;
}
F_23 ( L_40 , * type , V_438 -> V_193 , * V_436 ) ;
return V_193 ;
}
static void F_218 ( void * * V_434 , T_1 type , T_1 V_193 , unsigned long V_436 )
{
struct V_437 * V_438 = * V_434 ;
F_23 ( L_40 , type , V_193 , V_436 ) ;
V_438 -> type = type ;
V_438 -> V_193 = V_193 ;
switch ( V_193 ) {
case 1 :
* ( ( T_1 * ) V_438 -> V_436 ) = V_436 ;
break;
case 2 :
F_108 ( V_436 , V_438 -> V_436 ) ;
break;
case 4 :
F_107 ( V_436 , V_438 -> V_436 ) ;
break;
default:
memcpy ( V_438 -> V_436 , ( void * ) V_436 , V_193 ) ;
break;
}
* V_434 += V_439 + V_193 ;
}
static void F_219 ( void * * V_434 , struct V_11 * V_23 )
{
struct V_440 V_441 ;
switch ( V_23 -> V_147 ) {
case V_150 :
V_441 . V_189 = V_23 -> V_127 ;
V_441 . V_442 = V_23 -> V_129 ;
V_441 . V_443 = F_18 ( V_23 -> V_131 ) ;
V_441 . V_444 = F_220 ( V_23 -> V_133 ) ;
V_441 . V_445 = F_220 ( V_136 ) ;
V_441 . V_104 = F_220 ( V_138 ) ;
break;
case V_154 :
V_441 . V_189 = 1 ;
V_441 . V_442 = V_130 ;
V_441 . V_443 = F_18 ( V_23 -> V_131 ) ;
V_441 . V_444 = F_220 ( V_23 -> V_133 ) ;
V_441 . V_445 = 0 ;
V_441 . V_104 = 0 ;
break;
default:
return;
}
F_218 ( V_434 , V_446 , sizeof( V_441 ) ,
( unsigned long ) & V_441 ) ;
}
static void F_221 ( struct V_71 * V_72 )
{
struct V_11 * V_23 = F_46 ( V_72 , struct V_11 ,
V_447 . V_72 ) ;
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
int F_222 ( struct V_11 * V_23 )
{
int V_24 ;
V_23 -> V_377 = 0 ;
V_23 -> V_286 = 0 ;
V_23 -> V_416 = 0 ;
V_23 -> V_383 = 0 ;
V_23 -> V_265 = 0 ;
V_23 -> V_378 = 0 ;
V_23 -> V_263 = 0 ;
V_23 -> V_110 = NULL ;
V_23 -> V_111 = NULL ;
V_23 -> V_112 = 0 ;
F_67 ( & V_23 -> V_119 ) ;
V_23 -> V_448 = V_449 ;
V_23 -> V_450 = V_449 ;
V_23 -> V_203 = V_204 ;
V_23 -> V_294 = V_295 ;
if ( V_23 -> V_147 != V_150 )
return 0 ;
V_23 -> V_291 = V_386 ;
V_23 -> V_289 = V_290 ;
F_55 ( & V_23 -> V_50 , F_167 ) ;
F_55 ( & V_23 -> V_48 , F_166 ) ;
F_55 ( & V_23 -> V_447 , F_221 ) ;
F_67 ( & V_23 -> V_151 ) ;
V_24 = F_36 ( & V_23 -> V_152 , V_23 -> V_97 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_36 ( & V_23 -> V_153 , V_23 -> V_101 ) ;
if ( V_24 < 0 )
F_39 ( & V_23 -> V_152 ) ;
return V_24 ;
}
static inline T_7 F_223 ( T_7 V_147 , T_5 V_451 )
{
switch ( V_147 ) {
case V_154 :
case V_150 :
if ( F_139 ( V_147 , V_451 ) )
return V_147 ;
default:
return V_148 ;
}
}
static inline bool F_224 ( struct V_12 * V_13 )
{
return ( ( V_13 -> V_269 & V_270 ) &&
( V_13 -> V_315 & V_452 ) ) ;
}
static inline bool F_225 ( struct V_12 * V_13 )
{
return ( ( V_13 -> V_269 & V_270 ) &&
( V_13 -> V_315 & V_453 ) ) ;
}
static void F_226 ( struct V_11 * V_23 ,
struct V_454 * V_455 )
{
if ( V_23 -> V_448 != V_449 && V_23 -> V_206 ) {
T_10 V_456 = V_23 -> V_206 -> V_195 -> V_457 ;
V_456 = F_227 ( V_456 , 1000 ) ;
V_456 = 3 * V_456 + 500 ;
if ( V_456 > 0xffff )
V_456 = 0xffff ;
V_455 -> V_49 = F_18 ( ( T_2 ) V_456 ) ;
V_455 -> V_51 = V_455 -> V_49 ;
} else {
V_455 -> V_49 = F_18 ( V_106 ) ;
V_455 -> V_51 = F_18 ( V_107 ) ;
}
}
static inline void F_228 ( struct V_11 * V_23 )
{
if ( V_23 -> V_97 > V_98 &&
F_224 ( V_23 -> V_13 ) ) {
F_57 ( V_245 , & V_23 -> V_109 ) ;
V_23 -> V_99 = V_458 ;
} else {
V_23 -> V_97 = F_66 ( T_2 , V_23 -> V_97 ,
V_98 ) ;
V_23 -> V_99 = V_98 ;
}
V_23 -> V_102 = V_23 -> V_97 ;
}
static int F_142 ( struct V_11 * V_23 , void * V_194 )
{
struct V_459 * V_279 = V_194 ;
struct V_454 V_455 = { . V_147 = V_23 -> V_147 } ;
void * V_434 = V_279 -> V_194 ;
T_2 V_61 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_335 || V_23 -> V_460 )
goto V_27;
switch ( V_23 -> V_147 ) {
case V_154 :
case V_150 :
if ( F_70 ( V_325 , & V_23 -> V_92 ) )
break;
if ( F_225 ( V_23 -> V_13 ) )
F_57 ( V_461 , & V_23 -> V_109 ) ;
default:
V_23 -> V_147 = F_223 ( V_455 . V_147 , V_23 -> V_13 -> V_315 ) ;
break;
}
V_27:
if ( V_23 -> V_117 != V_38 )
F_218 ( & V_434 , V_462 , 2 , V_23 -> V_117 ) ;
switch ( V_23 -> V_147 ) {
case V_148 :
if ( V_318 )
break;
if ( ! ( V_23 -> V_13 -> V_315 & V_319 ) &&
! ( V_23 -> V_13 -> V_315 & V_320 ) )
break;
V_455 . V_147 = V_148 ;
V_455 . V_463 = 0 ;
V_455 . V_464 = 0 ;
V_455 . V_49 = 0 ;
V_455 . V_51 = 0 ;
V_455 . V_465 = 0 ;
F_218 ( & V_434 , V_466 , sizeof( V_455 ) ,
( unsigned long ) & V_455 ) ;
break;
case V_150 :
V_455 . V_147 = V_150 ;
V_455 . V_464 = V_23 -> V_95 ;
F_226 ( V_23 , & V_455 ) ;
V_61 = F_66 ( T_2 , V_467 , V_23 -> V_13 -> V_164 -
V_250 - V_401 -
V_255 ) ;
V_455 . V_465 = F_18 ( V_61 ) ;
F_228 ( V_23 ) ;
V_455 . V_463 = F_66 ( T_2 , V_23 -> V_97 ,
V_98 ) ;
F_218 ( & V_434 , V_466 , sizeof( V_455 ) ,
( unsigned long ) & V_455 ) ;
if ( F_70 ( V_461 , & V_23 -> V_109 ) )
F_219 ( & V_434 , V_23 ) ;
if ( F_70 ( V_245 , & V_23 -> V_109 ) )
F_218 ( & V_434 , V_468 , 2 ,
V_23 -> V_97 ) ;
if ( V_23 -> V_13 -> V_315 & V_469 )
if ( V_23 -> V_93 == V_470 ||
F_70 ( V_471 , & V_23 -> V_92 ) ) {
V_23 -> V_93 = V_470 ;
F_218 ( & V_434 , V_472 , 1 ,
V_23 -> V_93 ) ;
}
break;
case V_154 :
F_228 ( V_23 ) ;
V_455 . V_147 = V_154 ;
V_455 . V_463 = 0 ;
V_455 . V_464 = 0 ;
V_455 . V_49 = 0 ;
V_455 . V_51 = 0 ;
V_61 = F_66 ( T_2 , V_467 , V_23 -> V_13 -> V_164 -
V_250 - V_401 -
V_255 ) ;
V_455 . V_465 = F_18 ( V_61 ) ;
F_218 ( & V_434 , V_466 , sizeof( V_455 ) ,
( unsigned long ) & V_455 ) ;
if ( F_70 ( V_461 , & V_23 -> V_109 ) )
F_219 ( & V_434 , V_23 ) ;
if ( V_23 -> V_13 -> V_315 & V_469 )
if ( V_23 -> V_93 == V_470 ||
F_70 ( V_471 , & V_23 -> V_92 ) ) {
V_23 -> V_93 = V_470 ;
F_218 ( & V_434 , V_472 , 1 ,
V_23 -> V_93 ) ;
}
break;
}
V_279 -> V_16 = F_18 ( V_23 -> V_16 ) ;
V_279 -> V_109 = F_18 ( 0 ) ;
return V_434 - V_194 ;
}
static int F_229 ( struct V_11 * V_23 , void * V_194 )
{
struct V_473 * V_158 = V_194 ;
void * V_434 = V_158 -> V_194 ;
void * V_279 = V_23 -> V_474 ;
int V_193 = V_23 -> V_475 ;
int type , V_476 , V_435 ;
unsigned long V_436 ;
struct V_454 V_455 = { . V_147 = V_148 } ;
struct V_440 V_441 ;
T_1 V_477 = 0 ;
T_2 V_164 = V_38 ;
T_2 V_159 = V_478 ;
T_2 V_61 ;
F_23 ( L_3 , V_23 ) ;
while ( V_193 >= V_439 ) {
V_193 -= F_217 ( & V_279 , & type , & V_435 , & V_436 ) ;
V_476 = type & V_479 ;
type &= V_480 ;
switch ( type ) {
case V_462 :
V_164 = V_436 ;
break;
case V_481 :
V_23 -> V_104 = V_436 ;
break;
case V_482 :
break;
case V_466 :
if ( V_435 == sizeof( V_455 ) )
memcpy ( & V_455 , ( void * ) V_436 , V_435 ) ;
break;
case V_472 :
if ( V_436 == V_470 )
F_57 ( V_471 , & V_23 -> V_92 ) ;
break;
case V_446 :
V_477 = 1 ;
if ( V_435 == sizeof( V_441 ) )
memcpy ( & V_441 , ( void * ) V_436 , V_435 ) ;
break;
case V_468 :
if ( ! ( V_23 -> V_13 -> V_269 & V_270 ) )
return - V_77 ;
F_57 ( V_245 , & V_23 -> V_109 ) ;
F_57 ( V_483 , & V_23 -> V_92 ) ;
V_23 -> V_99 = V_458 ;
V_23 -> V_101 = V_436 ;
break;
default:
if ( V_476 )
break;
V_159 = V_484 ;
* ( ( T_1 * ) V_434 ++ ) = type ;
break;
}
}
if ( V_23 -> V_460 || V_23 -> V_335 > 1 )
goto V_27;
switch ( V_23 -> V_147 ) {
case V_154 :
case V_150 :
if ( ! F_70 ( V_325 , & V_23 -> V_92 ) ) {
V_23 -> V_147 = F_223 ( V_455 . V_147 ,
V_23 -> V_13 -> V_315 ) ;
break;
}
if ( V_477 ) {
if ( F_225 ( V_23 -> V_13 ) )
F_57 ( V_461 , & V_23 -> V_109 ) ;
else
return - V_77 ;
}
if ( V_23 -> V_147 != V_455 . V_147 )
return - V_77 ;
break;
}
V_27:
if ( V_23 -> V_147 != V_455 . V_147 ) {
V_159 = V_485 ;
V_455 . V_147 = V_23 -> V_147 ;
if ( V_23 -> V_460 == 1 )
return - V_77 ;
F_218 ( & V_434 , V_466 , sizeof( V_455 ) ,
( unsigned long ) & V_455 ) ;
}
if ( V_159 == V_478 ) {
if ( V_164 < V_486 )
V_159 = V_485 ;
else {
V_23 -> V_37 = V_164 ;
F_57 ( V_487 , & V_23 -> V_92 ) ;
}
F_218 ( & V_434 , V_462 , 2 , V_23 -> V_37 ) ;
if ( V_477 ) {
if ( V_23 -> V_129 != V_488 &&
V_441 . V_442 != V_488 &&
V_441 . V_442 != V_23 -> V_129 ) {
V_159 = V_485 ;
if ( V_23 -> V_335 >= 1 )
return - V_77 ;
F_218 ( & V_434 , V_446 ,
sizeof( V_441 ) ,
( unsigned long ) & V_441 ) ;
} else {
V_159 = V_489 ;
F_57 ( V_490 , & V_23 -> V_92 ) ;
}
}
switch ( V_455 . V_147 ) {
case V_148 :
V_23 -> V_93 = V_470 ;
F_57 ( V_491 , & V_23 -> V_92 ) ;
break;
case V_150 :
if ( ! F_70 ( V_483 , & V_23 -> V_92 ) )
V_23 -> V_101 = V_455 . V_463 ;
else
V_455 . V_463 = V_98 ;
V_23 -> V_100 = V_455 . V_464 ;
V_61 = F_66 ( T_2 , F_230 ( V_455 . V_465 ) ,
V_23 -> V_13 -> V_164 - V_250 -
V_401 - V_255 ) ;
V_455 . V_465 = F_18 ( V_61 ) ;
V_23 -> V_405 = V_61 ;
F_226 ( V_23 , & V_455 ) ;
F_57 ( V_491 , & V_23 -> V_92 ) ;
F_218 ( & V_434 , V_466 ,
sizeof( V_455 ) , ( unsigned long ) & V_455 ) ;
if ( F_70 ( V_461 , & V_23 -> V_109 ) ) {
V_23 -> V_492 = V_441 . V_189 ;
V_23 -> V_493 = V_441 . V_442 ;
V_23 -> V_494 = F_230 ( V_441 . V_443 ) ;
V_23 -> V_495 =
F_231 ( V_441 . V_104 ) ;
V_23 -> V_496 =
F_231 ( V_441 . V_445 ) ;
V_23 -> V_497 =
F_231 ( V_441 . V_444 ) ;
F_218 ( & V_434 , V_446 ,
sizeof( V_441 ) ,
( unsigned long ) & V_441 ) ;
}
break;
case V_154 :
V_61 = F_66 ( T_2 , F_230 ( V_455 . V_465 ) ,
V_23 -> V_13 -> V_164 - V_250 -
V_401 - V_255 ) ;
V_455 . V_465 = F_18 ( V_61 ) ;
V_23 -> V_405 = V_61 ;
F_57 ( V_491 , & V_23 -> V_92 ) ;
F_218 ( & V_434 , V_466 , sizeof( V_455 ) ,
( unsigned long ) & V_455 ) ;
break;
default:
V_159 = V_485 ;
memset ( & V_455 , 0 , sizeof( V_455 ) ) ;
V_455 . V_147 = V_23 -> V_147 ;
}
if ( V_159 == V_478 )
F_57 ( V_498 , & V_23 -> V_92 ) ;
}
V_158 -> V_17 = F_18 ( V_23 -> V_16 ) ;
V_158 -> V_159 = F_18 ( V_159 ) ;
V_158 -> V_109 = F_18 ( 0 ) ;
return V_434 - V_194 ;
}
static int F_232 ( struct V_11 * V_23 , void * V_158 , int V_193 ,
void * V_194 , T_2 * V_159 )
{
struct V_459 * V_279 = V_194 ;
void * V_434 = V_279 -> V_194 ;
int type , V_435 ;
unsigned long V_436 ;
struct V_454 V_455 = { . V_147 = V_148 } ;
struct V_440 V_441 ;
F_23 ( L_41 , V_23 , V_158 , V_193 , V_194 ) ;
while ( V_193 >= V_439 ) {
V_193 -= F_217 ( & V_158 , & type , & V_435 , & V_436 ) ;
switch ( type ) {
case V_462 :
if ( V_436 < V_486 ) {
* V_159 = V_485 ;
V_23 -> V_117 = V_486 ;
} else
V_23 -> V_117 = V_436 ;
F_218 ( & V_434 , V_462 , 2 , V_23 -> V_117 ) ;
break;
case V_481 :
V_23 -> V_104 = V_436 ;
F_218 ( & V_434 , V_481 ,
2 , V_23 -> V_104 ) ;
break;
case V_466 :
if ( V_435 == sizeof( V_455 ) )
memcpy ( & V_455 , ( void * ) V_436 , V_435 ) ;
if ( F_70 ( V_325 , & V_23 -> V_92 ) &&
V_455 . V_147 != V_23 -> V_147 )
return - V_77 ;
V_23 -> V_93 = 0 ;
F_218 ( & V_434 , V_466 ,
sizeof( V_455 ) , ( unsigned long ) & V_455 ) ;
break;
case V_468 :
V_23 -> V_102 = F_66 ( T_2 , V_436 , V_23 -> V_102 ) ;
F_218 ( & V_434 , V_468 , 2 ,
V_23 -> V_97 ) ;
break;
case V_446 :
if ( V_435 == sizeof( V_441 ) )
memcpy ( & V_441 , ( void * ) V_436 , V_435 ) ;
if ( V_23 -> V_129 != V_488 &&
V_441 . V_442 != V_488 &&
V_441 . V_442 != V_23 -> V_129 )
return - V_77 ;
F_218 ( & V_434 , V_446 , sizeof( V_441 ) ,
( unsigned long ) & V_441 ) ;
break;
case V_472 :
if ( * V_159 == V_489 )
if ( V_436 == V_470 )
F_57 ( V_471 ,
& V_23 -> V_92 ) ;
break;
}
}
if ( V_23 -> V_147 == V_148 && V_23 -> V_147 != V_455 . V_147 )
return - V_77 ;
V_23 -> V_147 = V_455 . V_147 ;
if ( * V_159 == V_478 || * V_159 == V_489 ) {
switch ( V_455 . V_147 ) {
case V_150 :
V_23 -> V_49 = F_230 ( V_455 . V_49 ) ;
V_23 -> V_51 = F_230 ( V_455 . V_51 ) ;
V_23 -> V_116 = F_230 ( V_455 . V_465 ) ;
if ( ! F_70 ( V_245 , & V_23 -> V_109 ) )
V_23 -> V_102 = F_66 ( T_2 , V_23 -> V_102 ,
V_455 . V_463 ) ;
if ( F_70 ( V_461 , & V_23 -> V_109 ) ) {
V_23 -> V_131 = F_230 ( V_441 . V_443 ) ;
V_23 -> V_133 =
F_231 ( V_441 . V_444 ) ;
V_23 -> V_135 = F_231 ( V_441 . V_445 ) ;
V_23 -> V_137 =
F_231 ( V_441 . V_104 ) ;
}
break;
case V_154 :
V_23 -> V_116 = F_230 ( V_455 . V_465 ) ;
}
}
V_279 -> V_16 = F_18 ( V_23 -> V_16 ) ;
V_279 -> V_109 = F_18 ( 0 ) ;
return V_434 - V_194 ;
}
static int F_233 ( struct V_11 * V_23 , void * V_194 ,
T_2 V_159 , T_2 V_109 )
{
struct V_473 * V_158 = V_194 ;
void * V_434 = V_158 -> V_194 ;
F_23 ( L_3 , V_23 ) ;
V_158 -> V_17 = F_18 ( V_23 -> V_16 ) ;
V_158 -> V_159 = F_18 ( V_159 ) ;
V_158 -> V_109 = F_18 ( V_109 ) ;
return V_434 - V_194 ;
}
void F_234 ( struct V_11 * V_23 )
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
void F_235 ( struct V_11 * V_23 )
{
struct V_167 V_158 ;
struct V_12 * V_13 = V_23 -> V_13 ;
T_1 V_327 [ 128 ] ;
T_1 V_499 ;
V_158 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_158 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_158 . V_159 = F_18 ( V_331 ) ;
V_158 . V_169 = F_18 ( V_170 ) ;
if ( V_23 -> V_206 )
V_499 = V_500 ;
else
V_499 = V_171 ;
F_23 ( L_42 , V_23 , V_499 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_499 , sizeof( V_158 ) , & V_158 ) ;
if ( F_132 ( V_333 , & V_23 -> V_92 ) )
return;
F_83 ( V_13 , F_91 ( V_13 ) , V_334 ,
F_142 ( V_23 , V_327 ) , V_327 ) ;
V_23 -> V_335 ++ ;
}
static void F_236 ( struct V_11 * V_23 , void * V_158 , int V_193 )
{
int type , V_435 ;
unsigned long V_436 ;
T_2 V_501 = V_23 -> V_102 ;
struct V_454 V_455 = {
. V_147 = V_23 -> V_147 ,
. V_49 = F_18 ( V_106 ) ,
. V_51 = F_18 ( V_107 ) ,
. V_465 = F_18 ( V_23 -> V_117 ) ,
. V_463 = F_66 ( T_2 , V_23 -> V_102 , V_98 ) ,
} ;
F_23 ( L_43 , V_23 , V_158 , V_193 ) ;
if ( ( V_23 -> V_147 != V_150 ) && ( V_23 -> V_147 != V_154 ) )
return;
while ( V_193 >= V_439 ) {
V_193 -= F_217 ( & V_158 , & type , & V_435 , & V_436 ) ;
switch ( type ) {
case V_466 :
if ( V_435 == sizeof( V_455 ) )
memcpy ( & V_455 , ( void * ) V_436 , V_435 ) ;
break;
case V_468 :
V_501 = V_436 ;
break;
}
}
switch ( V_455 . V_147 ) {
case V_150 :
V_23 -> V_49 = F_230 ( V_455 . V_49 ) ;
V_23 -> V_51 = F_230 ( V_455 . V_51 ) ;
V_23 -> V_116 = F_230 ( V_455 . V_465 ) ;
if ( F_70 ( V_245 , & V_23 -> V_109 ) )
V_23 -> V_102 = F_66 ( T_2 , V_23 -> V_102 , V_501 ) ;
else
V_23 -> V_102 = F_66 ( T_2 , V_23 -> V_102 ,
V_455 . V_463 ) ;
break;
case V_154 :
V_23 -> V_116 = F_230 ( V_455 . V_465 ) ;
}
}
static inline int F_237 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
struct V_503 * V_504 = (struct V_503 * ) V_194 ;
if ( V_502 < sizeof( * V_504 ) )
return - V_505 ;
if ( V_504 -> V_74 != V_506 )
return 0 ;
if ( ( V_13 -> V_307 & V_308 ) &&
V_430 -> V_19 == V_13 -> V_310 ) {
F_238 ( & V_13 -> V_311 ) ;
V_13 -> V_307 |= V_314 ;
V_13 -> V_310 = 0 ;
F_140 ( V_13 ) ;
}
return 0 ;
}
static struct V_11 * F_239 ( struct V_12 * V_13 ,
struct V_429 * V_430 ,
T_1 * V_194 , T_1 V_499 , T_1 V_281 )
{
struct V_278 * V_279 = (struct V_278 * ) V_194 ;
struct V_167 V_158 ;
struct V_11 * V_23 = NULL , * V_507 ;
int V_159 , V_169 = V_170 ;
T_2 V_16 = 0 , V_17 = F_69 ( V_279 -> V_17 ) ;
T_3 V_20 = V_279 -> V_20 ;
F_23 ( L_44 , F_69 ( V_20 ) , V_17 ) ;
V_507 = F_165 ( V_172 , V_20 , & V_13 -> V_8 -> V_21 ,
& V_13 -> V_8 -> V_156 , V_123 ) ;
if ( ! V_507 ) {
V_159 = V_162 ;
goto V_508;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_507 ) ;
if ( V_20 != F_18 ( V_184 ) &&
! F_240 ( V_13 -> V_8 ) ) {
V_13 -> V_120 = V_509 ;
V_159 = V_168 ;
goto V_510;
}
V_159 = V_511 ;
if ( F_4 ( V_13 , V_17 ) )
goto V_510;
V_23 = V_507 -> V_46 -> V_512 ( V_507 ) ;
if ( ! V_23 )
goto V_510;
V_13 -> V_8 -> V_366 = V_513 ;
F_81 ( & V_23 -> V_21 , & V_13 -> V_8 -> V_21 ) ;
F_81 ( & V_23 -> V_156 , & V_13 -> V_8 -> V_156 ) ;
V_23 -> V_9 = F_2 ( V_13 -> V_8 ) ;
V_23 -> V_10 = F_3 ( V_13 -> V_8 ) ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_17 ;
V_23 -> V_448 = V_281 ;
F_68 ( V_13 , V_23 ) ;
V_16 = V_23 -> V_17 ;
F_85 ( V_23 , V_23 -> V_46 -> V_173 ( V_23 ) ) ;
V_23 -> V_19 = V_430 -> V_19 ;
if ( V_13 -> V_307 & V_314 ) {
if ( F_88 ( V_23 , false ) ) {
if ( F_70 ( V_160 , & V_23 -> V_109 ) ) {
F_22 ( V_23 , V_174 ) ;
V_159 = V_328 ;
V_169 = V_329 ;
V_23 -> V_46 -> V_330 ( V_23 ) ;
} else {
if ( V_281 == V_449 ) {
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
V_510:
F_48 ( V_507 ) ;
F_10 ( & V_13 -> V_18 ) ;
F_49 ( V_507 ) ;
V_508:
V_158 . V_17 = F_18 ( V_17 ) ;
V_158 . V_16 = F_18 ( V_16 ) ;
V_158 . V_159 = F_18 ( V_159 ) ;
V_158 . V_169 = F_18 ( V_169 ) ;
F_83 ( V_13 , V_430 -> V_19 , V_499 , sizeof( V_158 ) , & V_158 ) ;
if ( V_159 == V_328 && V_169 == V_170 ) {
struct V_306 V_514 ;
V_514 . type = F_18 ( V_309 ) ;
V_13 -> V_307 |= V_308 ;
V_13 -> V_310 = F_91 ( V_13 ) ;
F_137 ( & V_13 -> V_311 , V_312 ) ;
F_83 ( V_13 , V_13 -> V_310 , V_313 ,
sizeof( V_514 ) , & V_514 ) ;
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
static int F_241 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 , T_1 * V_194 )
{
struct V_267 * V_195 = V_13 -> V_8 -> V_195 ;
struct V_7 * V_8 = V_13 -> V_8 ;
if ( V_502 < sizeof( struct V_278 ) )
return - V_505 ;
F_149 ( V_195 ) ;
if ( F_242 ( V_195 , V_515 ) &&
! F_132 ( V_516 , & V_8 -> V_109 ) )
F_243 ( V_195 , V_8 , 0 , NULL , 0 ) ;
F_151 ( V_195 ) ;
F_239 ( V_13 , V_430 , V_194 , V_171 , 0 ) ;
return 0 ;
}
static int F_244 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
struct V_167 * V_158 = (struct V_167 * ) V_194 ;
T_2 V_17 , V_16 , V_159 , V_169 ;
struct V_11 * V_23 ;
T_1 V_279 [ 128 ] ;
int V_24 ;
if ( V_502 < sizeof( * V_158 ) )
return - V_505 ;
V_17 = F_69 ( V_158 -> V_17 ) ;
V_16 = F_69 ( V_158 -> V_16 ) ;
V_159 = F_69 ( V_158 -> V_159 ) ;
V_169 = F_69 ( V_158 -> V_169 ) ;
F_23 ( L_45 ,
V_16 , V_17 , V_159 , V_169 ) ;
F_8 ( & V_13 -> V_18 ) ;
if ( V_17 ) {
V_23 = F_6 ( V_13 , V_17 ) ;
if ( ! V_23 ) {
V_24 = - V_517 ;
goto V_518;
}
} else {
V_23 = F_12 ( V_13 , V_430 -> V_19 ) ;
if ( ! V_23 ) {
V_24 = - V_517 ;
goto V_518;
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
V_518:
F_10 ( & V_13 -> V_18 ) ;
return V_24 ;
}
static inline void F_245 ( struct V_11 * V_23 )
{
if ( V_23 -> V_147 != V_150 && V_23 -> V_147 != V_154 )
V_23 -> V_93 = V_470 ;
else if ( ! F_70 ( V_471 , & V_23 -> V_92 ) )
V_23 -> V_93 = V_94 ;
}
static void F_246 ( struct V_11 * V_23 , void * V_194 ,
T_1 V_19 , T_2 V_109 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
F_23 ( L_46 , V_13 , V_23 , V_19 ,
V_109 ) ;
F_117 ( V_490 , & V_23 -> V_92 ) ;
F_57 ( V_498 , & V_23 -> V_92 ) ;
F_83 ( V_13 , V_19 , V_519 ,
F_233 ( V_23 , V_194 ,
V_478 , V_109 ) , V_194 ) ;
}
static void F_247 ( struct V_12 * V_13 , T_1 V_19 ,
T_2 V_17 , T_2 V_16 )
{
struct V_520 V_504 ;
V_504 . V_74 = F_18 ( V_521 ) ;
V_504 . V_17 = F_248 ( V_17 ) ;
V_504 . V_16 = F_248 ( V_16 ) ;
F_83 ( V_13 , V_19 , V_522 , sizeof( V_504 ) , & V_504 ) ;
}
static inline int F_249 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
struct V_459 * V_279 = (struct V_459 * ) V_194 ;
T_2 V_16 , V_109 ;
T_1 V_158 [ 64 ] ;
struct V_11 * V_23 ;
int V_193 , V_24 = 0 ;
if ( V_502 < sizeof( * V_279 ) )
return - V_505 ;
V_16 = F_69 ( V_279 -> V_16 ) ;
V_109 = F_69 ( V_279 -> V_109 ) ;
F_23 ( L_47 , V_16 , V_109 ) ;
V_23 = F_7 ( V_13 , V_16 ) ;
if ( ! V_23 ) {
F_247 ( V_13 , V_430 -> V_19 , V_16 , 0 ) ;
return 0 ;
}
if ( V_23 -> V_45 != V_76 && V_23 -> V_45 != V_174 ) {
F_247 ( V_13 , V_430 -> V_19 , V_23 -> V_17 ,
V_23 -> V_16 ) ;
goto V_518;
}
V_193 = V_502 - sizeof( * V_279 ) ;
if ( V_23 -> V_475 + V_193 > sizeof( V_23 -> V_474 ) ) {
F_83 ( V_13 , V_430 -> V_19 , V_519 ,
F_233 ( V_23 , V_158 ,
V_523 , V_109 ) , V_158 ) ;
goto V_518;
}
memcpy ( V_23 -> V_474 + V_23 -> V_475 , V_279 -> V_194 , V_193 ) ;
V_23 -> V_475 += V_193 ;
if ( V_109 & V_524 ) {
F_83 ( V_13 , V_430 -> V_19 , V_519 ,
F_233 ( V_23 , V_158 ,
V_478 , V_109 ) , V_158 ) ;
goto V_518;
}
V_193 = F_229 ( V_23 , V_158 ) ;
if ( V_193 < 0 ) {
F_86 ( V_23 , V_326 ) ;
goto V_518;
}
V_23 -> V_19 = V_430 -> V_19 ;
F_83 ( V_13 , V_430 -> V_19 , V_519 , V_193 , V_158 ) ;
V_23 -> V_460 ++ ;
V_23 -> V_475 = 0 ;
if ( ! F_70 ( V_498 , & V_23 -> V_92 ) )
goto V_518;
if ( F_70 ( V_525 , & V_23 -> V_92 ) ) {
F_245 ( V_23 ) ;
if ( V_23 -> V_147 == V_150 ||
V_23 -> V_147 == V_154 )
V_24 = F_222 ( V_23 ) ;
if ( V_24 < 0 )
F_86 ( V_23 , - V_24 ) ;
else
F_130 ( V_23 ) ;
goto V_518;
}
if ( ! F_132 ( V_333 , & V_23 -> V_92 ) ) {
T_1 V_327 [ 64 ] ;
F_83 ( V_13 , F_91 ( V_13 ) , V_334 ,
F_142 ( V_23 , V_327 ) , V_327 ) ;
V_23 -> V_335 ++ ;
}
if ( F_70 ( V_526 , & V_23 -> V_92 ) &&
F_70 ( V_490 , & V_23 -> V_92 ) ) {
if ( ! V_23 -> V_206 )
F_246 ( V_23 , V_158 , V_430 -> V_19 , V_109 ) ;
else
V_23 -> V_19 = V_430 -> V_19 ;
}
V_518:
F_48 ( V_23 ) ;
return V_24 ;
}
static inline int F_250 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
struct V_473 * V_158 = (struct V_473 * ) V_194 ;
T_2 V_17 , V_109 , V_159 ;
struct V_11 * V_23 ;
int V_193 = V_502 - sizeof( * V_158 ) ;
int V_24 = 0 ;
if ( V_502 < sizeof( * V_158 ) )
return - V_505 ;
V_17 = F_69 ( V_158 -> V_17 ) ;
V_109 = F_69 ( V_158 -> V_109 ) ;
V_159 = F_69 ( V_158 -> V_159 ) ;
F_23 ( L_48 , V_17 , V_109 ,
V_159 , V_193 ) ;
V_23 = F_7 ( V_13 , V_17 ) ;
if ( ! V_23 )
return 0 ;
switch ( V_159 ) {
case V_478 :
F_236 ( V_23 , V_158 -> V_194 , V_193 ) ;
F_117 ( V_526 , & V_23 -> V_92 ) ;
break;
case V_489 :
F_57 ( V_526 , & V_23 -> V_92 ) ;
if ( F_70 ( V_490 , & V_23 -> V_92 ) ) {
char V_327 [ 64 ] ;
V_193 = F_232 ( V_23 , V_158 -> V_194 , V_193 ,
V_327 , & V_159 ) ;
if ( V_193 < 0 ) {
F_86 ( V_23 , V_326 ) ;
goto V_27;
}
if ( ! V_23 -> V_206 ) {
F_246 ( V_23 , V_327 , V_430 -> V_19 ,
0 ) ;
} else {
if ( F_124 ( V_23 ) ) {
F_251 ( V_23 ) ;
V_23 -> V_19 = V_430 -> V_19 ;
}
}
}
goto V_27;
case V_485 :
if ( V_23 -> V_460 <= V_527 ) {
char V_279 [ 64 ] ;
if ( V_193 > sizeof( V_279 ) - sizeof( struct V_459 ) ) {
F_86 ( V_23 , V_326 ) ;
goto V_27;
}
V_159 = V_478 ;
V_193 = F_232 ( V_23 , V_158 -> V_194 , V_193 ,
V_279 , & V_159 ) ;
if ( V_193 < 0 ) {
F_86 ( V_23 , V_326 ) ;
goto V_27;
}
F_83 ( V_13 , F_91 ( V_13 ) ,
V_334 , V_193 , V_279 ) ;
V_23 -> V_335 ++ ;
if ( V_159 != V_478 )
goto V_27;
break;
}
default:
F_26 ( V_23 , V_326 ) ;
F_85 ( V_23 , V_528 ) ;
F_86 ( V_23 , V_326 ) ;
goto V_27;
}
if ( V_109 & V_524 )
goto V_27;
F_57 ( V_525 , & V_23 -> V_92 ) ;
if ( F_70 ( V_498 , & V_23 -> V_92 ) ) {
F_245 ( V_23 ) ;
if ( V_23 -> V_147 == V_150 ||
V_23 -> V_147 == V_154 )
V_24 = F_222 ( V_23 ) ;
if ( V_24 < 0 )
F_86 ( V_23 , - V_24 ) ;
else
F_130 ( V_23 ) ;
}
V_27:
F_48 ( V_23 ) ;
return V_24 ;
}
static inline int F_252 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
struct V_321 * V_279 = (struct V_321 * ) V_194 ;
struct V_529 V_158 ;
T_2 V_16 , V_17 ;
struct V_11 * V_23 ;
if ( V_502 != sizeof( * V_279 ) )
return - V_505 ;
V_17 = F_69 ( V_279 -> V_17 ) ;
V_16 = F_69 ( V_279 -> V_16 ) ;
F_23 ( L_49 , V_17 , V_16 ) ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_6 ( V_13 , V_16 ) ;
if ( ! V_23 ) {
F_10 ( & V_13 -> V_18 ) ;
F_247 ( V_13 , V_430 -> V_19 , V_16 , V_17 ) ;
return 0 ;
}
F_9 ( V_23 ) ;
V_158 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_158 . V_17 = F_18 ( V_23 -> V_16 ) ;
F_83 ( V_13 , V_430 -> V_19 , V_530 , sizeof( V_158 ) , & V_158 ) ;
V_23 -> V_46 -> V_531 ( V_23 ) ;
F_60 ( V_23 ) ;
F_73 ( V_23 , V_326 ) ;
F_48 ( V_23 ) ;
V_23 -> V_46 -> V_82 ( V_23 ) ;
F_49 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
return 0 ;
}
static inline int F_253 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
struct V_529 * V_158 = (struct V_529 * ) V_194 ;
T_2 V_16 , V_17 ;
struct V_11 * V_23 ;
if ( V_502 != sizeof( * V_158 ) )
return - V_505 ;
V_17 = F_69 ( V_158 -> V_17 ) ;
V_16 = F_69 ( V_158 -> V_16 ) ;
F_23 ( L_50 , V_16 , V_17 ) ;
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
static inline int F_254 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
struct V_306 * V_279 = (struct V_306 * ) V_194 ;
T_2 type ;
if ( V_502 != sizeof( * V_279 ) )
return - V_505 ;
type = F_69 ( V_279 -> type ) ;
F_23 ( L_51 , type ) ;
if ( type == V_309 ) {
T_1 V_327 [ 8 ] ;
T_8 V_315 = V_317 ;
struct V_532 * V_158 = (struct V_532 * ) V_327 ;
V_158 -> type = F_18 ( V_309 ) ;
V_158 -> V_159 = F_18 ( V_533 ) ;
if ( ! V_318 )
V_315 |= V_319 | V_320
| V_469 ;
if ( V_13 -> V_269 & V_270 )
V_315 |= V_453
| V_452 ;
F_107 ( V_315 , V_158 -> V_194 ) ;
F_83 ( V_13 , V_430 -> V_19 , V_534 , sizeof( V_327 ) ,
V_327 ) ;
} else if ( type == V_535 ) {
T_1 V_327 [ 12 ] ;
struct V_532 * V_158 = (struct V_532 * ) V_327 ;
V_158 -> type = F_18 ( V_535 ) ;
V_158 -> V_159 = F_18 ( V_533 ) ;
V_158 -> V_194 [ 0 ] = V_13 -> V_269 ;
memset ( V_158 -> V_194 + 1 , 0 , 7 ) ;
F_83 ( V_13 , V_430 -> V_19 , V_534 , sizeof( V_327 ) ,
V_327 ) ;
} else {
struct V_532 V_158 ;
V_158 . type = F_18 ( type ) ;
V_158 . V_159 = F_18 ( V_536 ) ;
F_83 ( V_13 , V_430 -> V_19 , V_534 , sizeof( V_158 ) ,
& V_158 ) ;
}
return 0 ;
}
static inline int F_255 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
struct V_532 * V_158 = (struct V_532 * ) V_194 ;
T_2 type , V_159 ;
if ( V_502 < sizeof( * V_158 ) )
return - V_505 ;
type = F_69 ( V_158 -> type ) ;
V_159 = F_69 ( V_158 -> V_159 ) ;
F_23 ( L_52 , type , V_159 ) ;
if ( V_430 -> V_19 != V_13 -> V_310 ||
V_13 -> V_307 & V_314 )
return 0 ;
F_238 ( & V_13 -> V_311 ) ;
if ( V_159 != V_533 ) {
V_13 -> V_307 |= V_314 ;
V_13 -> V_310 = 0 ;
F_140 ( V_13 ) ;
return 0 ;
}
switch ( type ) {
case V_309 :
V_13 -> V_315 = F_101 ( V_158 -> V_194 ) ;
if ( V_13 -> V_315 & V_537 ) {
struct V_306 V_279 ;
V_279 . type = F_18 ( V_535 ) ;
V_13 -> V_310 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_13 -> V_310 ,
V_313 , sizeof( V_279 ) , & V_279 ) ;
} else {
V_13 -> V_307 |= V_314 ;
V_13 -> V_310 = 0 ;
F_140 ( V_13 ) ;
}
break;
case V_535 :
V_13 -> V_271 = V_158 -> V_194 [ 0 ] ;
V_13 -> V_307 |= V_314 ;
V_13 -> V_310 = 0 ;
F_140 ( V_13 ) ;
break;
}
return 0 ;
}
static int F_256 ( struct V_12 * V_13 ,
struct V_429 * V_430 ,
T_2 V_502 , void * V_194 )
{
struct V_282 * V_279 = V_194 ;
struct V_538 V_158 ;
struct V_11 * V_23 ;
struct V_267 * V_195 ;
T_2 V_20 , V_17 ;
if ( V_502 != sizeof( * V_279 ) )
return - V_505 ;
if ( ! ( V_13 -> V_269 & V_270 ) )
return - V_36 ;
V_20 = F_230 ( V_279 -> V_20 ) ;
V_17 = F_230 ( V_279 -> V_17 ) ;
F_23 ( L_53 , V_20 , V_17 , V_279 -> V_281 ) ;
if ( V_279 -> V_281 == V_449 ) {
F_239 ( V_13 , V_430 , V_194 , V_500 ,
V_279 -> V_281 ) ;
return 0 ;
}
V_195 = F_257 ( V_279 -> V_281 ) ;
if ( ! V_195 )
goto error;
if ( V_195 -> V_539 != V_540 || ! F_70 ( V_275 , & V_195 -> V_109 ) ) {
F_258 ( V_195 ) ;
goto error;
}
V_23 = F_239 ( V_13 , V_430 , V_194 , V_500 ,
V_279 -> V_281 ) ;
if ( V_23 ) {
struct V_142 * V_143 = V_13 -> V_8 -> V_142 ;
struct V_7 * V_206 ;
V_206 = F_259 ( V_195 , V_541 ,
& V_13 -> V_8 -> V_156 ) ;
if ( ! V_206 ) {
F_258 ( V_195 ) ;
F_247 ( V_13 , V_430 -> V_19 , V_23 -> V_17 ,
V_23 -> V_16 ) ;
return 0 ;
}
F_23 ( L_54 , V_143 , V_23 , V_206 ) ;
V_143 -> V_144 = V_23 ;
V_23 -> V_206 = V_206 ;
V_23 -> V_93 = V_470 ;
V_13 -> V_164 = V_195 -> V_542 ;
}
F_258 ( V_195 ) ;
return 0 ;
error:
V_158 . V_16 = 0 ;
V_158 . V_17 = F_18 ( V_17 ) ;
V_158 . V_159 = F_18 ( V_543 ) ;
V_158 . V_169 = F_18 ( V_170 ) ;
F_83 ( V_13 , V_430 -> V_19 , V_500 ,
sizeof( V_158 ) , & V_158 ) ;
return 0 ;
}
static void F_260 ( struct V_11 * V_23 , T_1 V_544 )
{
struct V_545 V_279 ;
T_1 V_19 ;
F_23 ( L_55 , V_23 , V_544 ) ;
V_19 = F_91 ( V_23 -> V_13 ) ;
V_23 -> V_19 = V_19 ;
V_279 . V_546 = F_18 ( V_23 -> V_17 ) ;
V_279 . V_544 = V_544 ;
F_83 ( V_23 -> V_13 , V_19 , V_547 , sizeof( V_279 ) ,
& V_279 ) ;
F_85 ( V_23 , V_548 ) ;
}
static void F_261 ( struct V_11 * V_23 , T_2 V_159 )
{
struct V_549 V_158 ;
F_23 ( L_56 , V_23 , V_159 ) ;
V_158 . V_546 = F_18 ( V_23 -> V_16 ) ;
V_158 . V_159 = F_18 ( V_159 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_550 ,
sizeof( V_158 ) , & V_158 ) ;
}
static void F_262 ( struct V_11 * V_23 , T_2 V_159 )
{
struct V_551 V_552 ;
F_23 ( L_56 , V_23 , V_159 ) ;
V_23 -> V_19 = F_91 ( V_23 -> V_13 ) ;
V_552 . V_546 = F_18 ( V_23 -> V_17 ) ;
V_552 . V_159 = F_18 ( V_159 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_553 ,
sizeof( V_552 ) , & V_552 ) ;
F_85 ( V_23 , V_548 ) ;
}
static void F_263 ( struct V_12 * V_13 , T_2 V_546 )
{
struct V_551 V_552 ;
F_23 ( L_57 , V_13 , V_546 ) ;
V_552 . V_546 = F_18 ( V_546 ) ;
V_552 . V_159 = F_18 ( V_554 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_553 ,
sizeof( V_552 ) , & V_552 ) ;
}
static void F_264 ( struct V_12 * V_13 , T_1 V_19 ,
T_2 V_546 )
{
struct V_555 V_158 ;
F_23 ( L_58 , V_546 ) ;
V_158 . V_546 = F_18 ( V_546 ) ;
F_83 ( V_13 , V_19 , V_556 , sizeof( V_158 ) , & V_158 ) ;
}
static void F_265 ( struct V_11 * V_23 )
{
V_23 -> V_145 = NULL ;
V_23 -> V_206 = NULL ;
}
static void F_266 ( struct V_11 * V_23 )
{
if ( V_23 -> V_45 != V_75 ) {
F_86 ( V_23 , V_326 ) ;
return;
}
switch ( V_23 -> V_294 ) {
case V_299 :
F_128 ( V_23 ) ;
F_261 ( V_23 , V_557 ) ;
break;
case V_296 :
if ( V_23 -> V_203 == V_558 ||
V_23 -> V_203 == V_559 ) {
F_128 ( V_23 ) ;
}
F_262 ( V_23 , V_554 ) ;
break;
}
}
static void F_267 ( struct V_11 * V_23 ,
struct V_146 * V_202 )
{
struct V_473 V_158 ;
V_23 -> V_145 = V_202 ;
V_23 -> V_206 -> V_362 = V_23 -> V_13 ;
F_246 ( V_23 , & V_158 , V_23 -> V_19 , 0 ) ;
if ( F_70 ( V_525 , & V_23 -> V_92 ) ) {
int V_24 ;
F_245 ( V_23 ) ;
V_24 = F_222 ( V_23 ) ;
if ( V_24 < 0 )
F_86 ( V_23 , - V_24 ) ;
else
F_130 ( V_23 ) ;
}
}
static void F_268 ( struct V_11 * V_23 ,
struct V_146 * V_202 )
{
V_23 -> V_206 = V_202 -> V_13 ;
V_23 -> V_206 -> V_362 = V_23 -> V_13 ;
F_23 ( L_59 , V_23 -> V_203 ) ;
switch ( V_23 -> V_203 ) {
case V_558 :
V_23 -> V_203 = V_560 ;
break;
case V_559 :
if ( F_70 ( V_264 , & V_23 -> V_258 ) ) {
V_23 -> V_203 = V_561 ;
} else if ( V_23 -> V_294 == V_296 ) {
V_23 -> V_203 = V_562 ;
F_262 ( V_23 , V_563 ) ;
} else if ( V_23 -> V_294 == V_299 ) {
V_23 -> V_203 = V_564 ;
F_261 ( V_23 , V_565 ) ;
}
break;
default:
F_265 ( V_23 ) ;
V_23 -> V_203 = V_204 ;
}
}
void F_269 ( struct V_11 * V_23 , struct V_146 * V_202 ,
T_1 V_169 )
{
F_23 ( L_60 , V_23 , V_202 , V_169 ) ;
if ( V_169 ) {
F_266 ( V_23 ) ;
F_265 ( V_23 ) ;
return;
}
if ( V_23 -> V_45 != V_75 ) {
if ( V_23 -> V_448 != V_449 )
F_267 ( V_23 , V_202 ) ;
} else {
F_268 ( V_23 , V_202 ) ;
}
}
void F_270 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_448 == V_449 ) {
if ( V_23 -> V_276 != V_277 )
return;
V_23 -> V_294 = V_296 ;
V_23 -> V_203 = V_205 ;
} else {
V_23 -> V_294 = V_296 ;
V_23 -> V_203 = V_560 ;
V_23 -> V_450 = 0 ;
F_127 ( V_23 ) ;
F_260 ( V_23 , 0 ) ;
}
}
static void F_271 ( struct V_11 * V_23 , int V_159 ,
T_1 V_448 , T_1 V_566 )
{
F_23 ( L_61 , V_23 , F_24 ( V_23 -> V_45 ) ,
V_448 , V_566 ) ;
V_23 -> V_93 = V_470 ;
if ( V_23 -> V_45 == V_78 ) {
if ( V_159 == V_331 ) {
V_23 -> V_448 = V_448 ;
F_126 ( V_23 , V_566 ) ;
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
V_158 . V_159 = F_18 ( V_511 ) ;
V_158 . V_169 = F_18 ( V_170 ) ;
}
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_500 ,
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
static void F_272 ( struct V_11 * V_23 , T_1 V_448 ,
T_1 V_566 )
{
F_127 ( V_23 ) ;
V_23 -> V_450 = V_448 ;
V_23 -> V_203 = V_567 ;
F_260 ( V_23 , V_566 ) ;
}
static void F_273 ( struct V_11 * V_23 , int V_159 )
{
struct V_146 * V_202 = NULL ;
if ( V_202 ) {
if ( V_202 -> V_45 == V_75 ) {
V_23 -> V_206 = V_202 -> V_13 ;
V_23 -> V_206 -> V_362 = V_23 -> V_13 ;
V_23 -> V_203 = V_564 ;
F_261 ( V_23 , V_565 ) ;
F_269 ( V_23 , V_202 , V_565 ) ;
} else {
V_23 -> V_203 = V_559 ;
}
} else {
F_261 ( V_23 , V_568 ) ;
}
}
static void F_274 ( struct V_11 * V_23 , int V_159 )
{
if ( V_23 -> V_294 == V_299 ) {
T_1 V_569 ;
if ( V_159 == - V_36 )
V_569 = V_570 ;
else
V_569 = V_568 ;
F_261 ( V_23 , V_569 ) ;
}
V_23 -> V_294 = V_295 ;
V_23 -> V_203 = V_204 ;
F_173 ( V_23 ) ;
}
void F_275 ( struct V_11 * V_23 , int V_159 )
{
T_1 V_448 = V_23 -> V_448 ;
T_1 V_566 = V_23 -> V_566 ;
F_23 ( L_62 ,
V_23 , V_159 , V_448 , V_566 ) ;
if ( V_23 -> V_45 == V_163 || V_23 -> V_45 == V_571 ) {
F_48 ( V_23 ) ;
return;
}
if ( V_23 -> V_45 != V_75 ) {
F_271 ( V_23 , V_159 , V_448 , V_566 ) ;
} else if ( V_159 != V_565 ) {
F_274 ( V_23 , V_159 ) ;
} else {
switch ( V_23 -> V_294 ) {
case V_296 :
F_272 ( V_23 , V_448 ,
V_566 ) ;
break;
case V_299 :
F_273 ( V_23 , V_159 ) ;
break;
default:
F_274 ( V_23 , V_159 ) ;
break;
}
}
}
static inline int F_276 ( struct V_12 * V_13 ,
struct V_429 * V_430 ,
T_2 V_502 , void * V_194 )
{
struct V_545 * V_279 = V_194 ;
struct V_549 V_158 ;
struct V_11 * V_23 ;
T_2 V_546 = 0 ;
T_2 V_159 = V_568 ;
if ( V_502 != sizeof( * V_279 ) )
return - V_505 ;
V_546 = F_230 ( V_279 -> V_546 ) ;
F_23 ( L_63 , V_546 , V_279 -> V_544 ) ;
if ( ! ( V_13 -> V_269 & V_270 ) )
return - V_36 ;
V_23 = F_11 ( V_13 , V_546 ) ;
if ( ! V_23 ) {
V_158 . V_546 = F_18 ( V_546 ) ;
V_158 . V_159 = F_18 ( V_568 ) ;
F_83 ( V_13 , V_430 -> V_19 , V_550 ,
sizeof( V_158 ) , & V_158 ) ;
return 0 ;
}
V_23 -> V_19 = V_430 -> V_19 ;
if ( V_23 -> V_17 < V_44 ||
V_23 -> V_276 == V_572 ||
( V_23 -> V_147 != V_150 &&
V_23 -> V_147 != V_154 ) ) {
V_159 = V_568 ;
goto V_573;
}
if ( V_23 -> V_448 == V_279 -> V_544 ) {
V_159 = V_574 ;
goto V_573;
}
if ( V_279 -> V_544 != V_449 ) {
struct V_267 * V_195 ;
V_195 = F_257 ( V_279 -> V_544 ) ;
if ( ! V_195 || V_195 -> V_539 != V_540 ||
! F_70 ( V_275 , & V_195 -> V_109 ) ) {
if ( V_195 )
F_258 ( V_195 ) ;
V_159 = V_570 ;
goto V_573;
}
F_258 ( V_195 ) ;
}
if ( ( F_95 ( V_23 ) ||
V_23 -> V_294 != V_295 ) &&
F_15 ( & V_13 -> V_8 -> V_21 , & V_13 -> V_8 -> V_156 ) > 0 ) {
V_159 = V_575 ;
goto V_573;
}
V_23 -> V_294 = V_299 ;
F_127 ( V_23 ) ;
V_23 -> V_450 = V_279 -> V_544 ;
V_546 = V_23 -> V_16 ;
if ( V_279 -> V_544 == V_449 ) {
if ( F_70 ( V_264 , & V_23 -> V_258 ) ) {
V_23 -> V_203 = V_561 ;
V_159 = V_576 ;
} else {
V_23 -> V_203 = V_564 ;
V_159 = V_565 ;
}
} else {
V_23 -> V_203 = V_205 ;
V_159 = V_576 ;
}
V_573:
F_261 ( V_23 , V_159 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static void F_277 ( struct V_12 * V_13 , T_2 V_546 , T_2 V_159 )
{
struct V_11 * V_23 ;
struct V_146 * V_202 = NULL ;
V_23 = F_7 ( V_13 , V_546 ) ;
if ( ! V_23 ) {
F_263 ( V_13 , V_546 ) ;
return;
}
F_74 ( V_23 ) ;
if ( V_159 == V_576 )
F_85 ( V_23 , V_577 ) ;
switch ( V_23 -> V_203 ) {
case V_558 :
V_23 -> V_203 = V_559 ;
break;
case V_560 :
if ( V_159 == V_576 ) {
break;
} else if ( F_70 ( V_264 ,
& V_23 -> V_258 ) ) {
V_23 -> V_203 = V_561 ;
} else {
V_23 -> V_203 = V_562 ;
F_262 ( V_23 , V_563 ) ;
}
break;
case V_567 :
if ( V_159 == V_565 ) {
V_23 -> V_203 = V_559 ;
} else {
V_23 -> V_203 = V_558 ;
}
if ( ! V_202 ) {
F_262 ( V_23 , V_554 ) ;
break;
}
if ( V_202 -> V_45 != V_75 )
break;
V_23 -> V_206 = V_202 -> V_13 ;
V_23 -> V_206 -> V_362 = V_23 -> V_13 ;
if ( V_159 == V_565 ) {
F_262 ( V_23 , V_563 ) ;
} else {
V_23 -> V_203 = V_560 ;
}
F_269 ( V_23 , V_202 , V_565 ) ;
break;
default:
V_23 -> V_450 = V_23 -> V_448 ;
F_128 ( V_23 ) ;
F_262 ( V_23 , V_554 ) ;
}
F_48 ( V_23 ) ;
}
static void F_278 ( struct V_12 * V_13 , T_1 V_19 , T_2 V_546 ,
T_2 V_159 )
{
struct V_11 * V_23 ;
V_23 = F_13 ( V_13 , V_19 ) ;
if ( ! V_23 ) {
F_263 ( V_13 , V_546 ) ;
return;
}
F_74 ( V_23 ) ;
if ( V_23 -> V_294 == V_296 ) {
if ( V_159 == V_575 ) {
V_23 -> V_294 = V_299 ;
} else {
V_23 -> V_450 = V_23 -> V_448 ;
F_128 ( V_23 ) ;
}
}
F_262 ( V_23 , V_554 ) ;
F_48 ( V_23 ) ;
}
static int F_279 ( struct V_12 * V_13 ,
struct V_429 * V_430 ,
T_2 V_502 , void * V_194 )
{
struct V_549 * V_158 = V_194 ;
T_2 V_546 , V_159 ;
if ( V_502 != sizeof( * V_158 ) )
return - V_505 ;
V_546 = F_230 ( V_158 -> V_546 ) ;
V_159 = F_230 ( V_158 -> V_159 ) ;
F_23 ( L_64 , V_546 , V_159 ) ;
if ( V_159 == V_565 || V_159 == V_576 )
F_277 ( V_13 , V_546 , V_159 ) ;
else
F_278 ( V_13 , V_430 -> V_19 , V_546 , V_159 ) ;
return 0 ;
}
static int F_280 ( struct V_12 * V_13 ,
struct V_429 * V_430 ,
T_2 V_502 , void * V_194 )
{
struct V_551 * V_552 = V_194 ;
struct V_11 * V_23 ;
T_2 V_546 , V_159 ;
if ( V_502 != sizeof( * V_552 ) )
return - V_505 ;
V_546 = F_230 ( V_552 -> V_546 ) ;
V_159 = F_230 ( V_552 -> V_159 ) ;
F_23 ( L_64 , V_546 , V_159 ) ;
V_23 = F_11 ( V_13 , V_546 ) ;
if ( ! V_23 ) {
F_264 ( V_13 , V_430 -> V_19 , V_546 ) ;
return 0 ;
}
if ( V_23 -> V_203 == V_564 ) {
if ( V_159 == V_563 ) {
V_23 -> V_448 = V_23 -> V_450 ;
if ( V_23 -> V_448 == V_449 )
F_265 ( V_23 ) ;
} else {
V_23 -> V_450 = V_23 -> V_448 ;
}
F_128 ( V_23 ) ;
}
F_264 ( V_13 , V_430 -> V_19 , V_546 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static inline int F_281 ( struct V_12 * V_13 ,
struct V_429 * V_430 ,
T_2 V_502 , void * V_194 )
{
struct V_555 * V_158 = V_194 ;
struct V_11 * V_23 ;
T_2 V_546 ;
if ( V_502 != sizeof( * V_158 ) )
return - V_505 ;
V_546 = F_230 ( V_158 -> V_546 ) ;
F_23 ( L_58 , V_546 ) ;
V_23 = F_7 ( V_13 , V_546 ) ;
if ( ! V_23 )
return 0 ;
F_74 ( V_23 ) ;
if ( V_23 -> V_203 == V_562 ) {
V_23 -> V_448 = V_23 -> V_450 ;
if ( V_23 -> V_448 == V_449 && V_23 -> V_145 )
F_265 ( V_23 ) ;
F_128 ( V_23 ) ;
}
F_48 ( V_23 ) ;
return 0 ;
}
static inline int V_344 ( struct V_12 * V_13 ,
struct V_429 * V_430 ,
T_2 V_502 , T_1 * V_194 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_344 * V_279 ;
struct V_578 V_158 ;
T_2 V_345 , V_346 , V_347 , V_349 ;
int V_24 ;
if ( V_8 -> V_339 != V_579 )
return - V_36 ;
if ( V_502 != sizeof( struct V_344 ) )
return - V_505 ;
V_279 = (struct V_344 * ) V_194 ;
V_345 = F_69 ( V_279 -> V_345 ) ;
V_346 = F_69 ( V_279 -> V_346 ) ;
V_347 = F_69 ( V_279 -> V_347 ) ;
V_349 = F_69 ( V_279 -> V_349 ) ;
F_23 ( L_65 ,
V_345 , V_346 , V_347 , V_349 ) ;
memset ( & V_158 , 0 , sizeof( V_158 ) ) ;
V_24 = F_282 ( V_345 , V_346 , V_347 , V_349 ) ;
if ( V_24 )
V_158 . V_159 = F_18 ( V_580 ) ;
else
V_158 . V_159 = F_18 ( V_581 ) ;
F_83 ( V_13 , V_430 -> V_19 , V_582 ,
sizeof( V_158 ) , & V_158 ) ;
if ( ! V_24 ) {
T_1 V_583 ;
V_583 = F_283 ( V_8 , V_345 , V_346 , V_347 ,
V_349 ) ;
F_284 ( V_8 -> V_195 , & V_8 -> V_156 , V_8 -> V_10 ,
V_583 , V_345 , V_346 , V_347 ,
V_349 ) ;
}
return 0 ;
}
static int F_285 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
struct V_157 * V_158 = (struct V_157 * ) V_194 ;
struct V_7 * V_8 = V_13 -> V_8 ;
T_2 V_16 , V_164 , V_116 , V_165 , V_159 ;
struct V_11 * V_23 ;
int V_24 , V_79 ;
if ( V_502 < sizeof( * V_158 ) )
return - V_505 ;
V_16 = F_69 ( V_158 -> V_16 ) ;
V_164 = F_69 ( V_158 -> V_164 ) ;
V_116 = F_69 ( V_158 -> V_116 ) ;
V_165 = F_69 ( V_158 -> V_165 ) ;
V_159 = F_69 ( V_158 -> V_159 ) ;
if ( V_159 == V_331 && ( V_164 < 23 || V_116 < 23 ||
V_16 < V_44 ||
V_16 > V_42 ) )
return - V_505 ;
F_23 ( L_66 ,
V_16 , V_164 , V_116 , V_165 , V_159 ) ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_12 ( V_13 , V_430 -> V_19 ) ;
if ( ! V_23 ) {
V_24 = - V_517 ;
goto V_518;
}
V_24 = 0 ;
F_9 ( V_23 ) ;
switch ( V_159 ) {
case V_331 :
if ( F_4 ( V_13 , V_16 ) ) {
V_24 = - V_517 ;
break;
}
V_23 -> V_19 = 0 ;
V_23 -> V_16 = V_16 ;
V_23 -> V_37 = V_164 ;
V_23 -> V_405 = V_116 ;
V_23 -> V_113 = V_165 ;
F_130 ( V_23 ) ;
break;
case V_584 :
case V_585 :
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
V_518:
F_10 ( & V_13 -> V_18 ) ;
return V_24 ;
}
static inline int F_286 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
int V_24 = 0 ;
switch ( V_430 -> V_192 ) {
case V_522 :
F_237 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_280 :
V_24 = F_241 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_171 :
case V_500 :
F_244 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_334 :
V_24 = F_249 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_519 :
F_250 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_323 :
V_24 = F_252 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_530 :
F_253 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_586 :
F_83 ( V_13 , V_430 -> V_19 , V_587 , V_502 , V_194 ) ;
break;
case V_587 :
break;
case V_313 :
V_24 = F_254 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_534 :
F_255 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_283 :
V_24 = F_256 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_547 :
V_24 = F_276 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_550 :
F_279 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_553 :
V_24 = F_280 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_556 :
F_281 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
default:
F_287 ( L_67 , V_430 -> V_192 ) ;
V_24 = - V_36 ;
break;
}
return V_24 ;
}
static int F_288 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
struct V_303 * V_279 = (struct V_303 * ) V_194 ;
struct V_157 V_158 ;
struct V_11 * V_23 , * V_507 ;
T_2 V_16 , V_17 , V_165 , V_164 , V_116 ;
T_3 V_20 ;
T_1 V_159 ;
if ( V_502 != sizeof( * V_279 ) )
return - V_505 ;
V_17 = F_69 ( V_279 -> V_17 ) ;
V_164 = F_69 ( V_279 -> V_164 ) ;
V_116 = F_69 ( V_279 -> V_116 ) ;
V_20 = V_279 -> V_20 ;
V_16 = 0 ;
V_165 = 0 ;
if ( V_164 < 23 || V_116 < 23 )
return - V_505 ;
F_23 ( L_68 , F_69 ( V_20 ) ,
V_17 , V_164 , V_116 ) ;
V_507 = F_165 ( V_172 , V_20 , & V_13 -> V_8 -> V_21 ,
& V_13 -> V_8 -> V_156 , V_2 ) ;
if ( ! V_507 ) {
V_159 = V_162 ;
V_23 = NULL ;
goto V_510;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_507 ) ;
if ( ! F_289 ( V_13 -> V_8 , V_507 -> V_79 ,
V_588 ) ) {
V_159 = V_584 ;
V_23 = NULL ;
goto V_589;
}
if ( V_17 < V_44 || V_17 > V_42 ) {
V_159 = V_590 ;
V_23 = NULL ;
goto V_589;
}
if ( F_4 ( V_13 , V_17 ) ) {
V_159 = V_591 ;
V_23 = NULL ;
goto V_589;
}
V_23 = V_507 -> V_46 -> V_512 ( V_507 ) ;
if ( ! V_23 ) {
V_159 = V_511 ;
goto V_589;
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
V_23 -> V_19 = V_430 -> V_19 ;
if ( F_70 ( V_160 , & V_23 -> V_109 ) ) {
F_22 ( V_23 , V_174 ) ;
V_159 = V_328 ;
V_23 -> V_46 -> V_330 ( V_23 ) ;
} else {
F_130 ( V_23 ) ;
V_159 = V_331 ;
}
V_589:
F_48 ( V_507 ) ;
F_10 ( & V_13 -> V_18 ) ;
F_49 ( V_507 ) ;
if ( V_159 == V_328 )
return 0 ;
V_510:
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
F_83 ( V_13 , V_430 -> V_19 , V_166 , sizeof( V_158 ) , & V_158 ) ;
return 0 ;
}
static inline int F_290 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
struct F_290 * V_592 ;
struct V_11 * V_23 ;
T_2 V_14 , V_165 , V_593 ;
if ( V_502 != sizeof( * V_592 ) )
return - V_505 ;
V_592 = (struct F_290 * ) V_194 ;
V_14 = F_69 ( V_592 -> V_14 ) ;
V_165 = F_69 ( V_592 -> V_165 ) ;
F_23 ( L_69 , V_14 , V_165 ) ;
V_23 = F_11 ( V_13 , V_14 ) ;
if ( ! V_23 )
return - V_517 ;
V_593 = V_594 - V_23 -> V_113 ;
if ( V_165 > V_593 ) {
F_287 ( L_70 ) ;
F_86 ( V_23 , V_326 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
V_23 -> V_113 += V_165 ;
F_202 ( V_23 ) ;
if ( V_23 -> V_113 )
V_23 -> V_46 -> V_595 ( V_23 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static inline int F_291 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
struct V_503 * V_504 = (struct V_503 * ) V_194 ;
struct V_11 * V_23 ;
if ( V_502 < sizeof( * V_504 ) )
return - V_505 ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_12 ( V_13 , V_430 -> V_19 ) ;
if ( ! V_23 )
goto V_27;
F_9 ( V_23 ) ;
F_73 ( V_23 , V_77 ) ;
F_48 ( V_23 ) ;
V_27:
F_10 ( & V_13 -> V_18 ) ;
return 0 ;
}
static inline int F_292 ( struct V_12 * V_13 ,
struct V_429 * V_430 , T_2 V_502 ,
T_1 * V_194 )
{
int V_24 = 0 ;
switch ( V_430 -> V_192 ) {
case V_522 :
F_291 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_351 :
V_24 = V_344 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_582 :
break;
case V_166 :
F_285 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_305 :
V_24 = F_288 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_596 :
V_24 = F_290 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_323 :
V_24 = F_252 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
case V_530 :
F_253 ( V_13 , V_430 , V_502 , V_194 ) ;
break;
default:
F_287 ( L_71 , V_430 -> V_192 ) ;
V_24 = - V_36 ;
break;
}
return V_24 ;
}
static inline void F_293 ( struct V_12 * V_13 ,
struct V_52 * V_56 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_429 * V_430 ;
T_2 V_193 ;
int V_24 ;
if ( V_8 -> type != V_2 )
goto V_597;
if ( V_56 -> V_193 < V_431 )
goto V_597;
V_430 = ( void * ) V_56 -> V_194 ;
F_102 ( V_56 , V_431 ) ;
V_193 = F_230 ( V_430 -> V_193 ) ;
F_23 ( L_72 , V_430 -> V_192 , V_193 , V_430 -> V_19 ) ;
if ( V_193 != V_56 -> V_193 || ! V_430 -> V_19 ) {
F_23 ( L_73 ) ;
goto V_597;
}
V_24 = F_292 ( V_13 , V_430 , V_193 , V_56 -> V_194 ) ;
if ( V_24 ) {
struct V_503 V_504 ;
F_287 ( L_74 , V_24 ) ;
V_504 . V_74 = F_18 ( V_506 ) ;
F_83 ( V_13 , V_430 -> V_19 , V_522 ,
sizeof( V_504 ) , & V_504 ) ;
}
V_597:
F_97 ( V_56 ) ;
}
static inline void F_294 ( struct V_12 * V_13 ,
struct V_52 * V_56 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
T_1 * V_194 = V_56 -> V_194 ;
int V_193 = V_56 -> V_193 ;
struct V_429 V_430 ;
int V_24 ;
F_216 ( V_13 , V_56 ) ;
if ( V_8 -> type != V_123 )
goto V_597;
while ( V_193 >= V_431 ) {
T_2 V_502 ;
memcpy ( & V_430 , V_194 , V_431 ) ;
V_194 += V_431 ;
V_193 -= V_431 ;
V_502 = F_230 ( V_430 . V_193 ) ;
F_23 ( L_72 , V_430 . V_192 , V_502 ,
V_430 . V_19 ) ;
if ( V_502 > V_193 || ! V_430 . V_19 ) {
F_23 ( L_73 ) ;
break;
}
V_24 = F_286 ( V_13 , & V_430 , V_502 , V_194 ) ;
if ( V_24 ) {
struct V_503 V_504 ;
F_287 ( L_74 , V_24 ) ;
V_504 . V_74 = F_18 ( V_506 ) ;
F_83 ( V_13 , V_430 . V_19 , V_522 ,
sizeof( V_504 ) , & V_504 ) ;
}
V_194 += V_502 ;
V_193 -= V_502 ;
}
V_597:
F_97 ( V_56 ) ;
}
static int F_295 ( struct V_11 * V_23 , struct V_52 * V_56 )
{
T_2 V_598 , V_599 ;
int V_600 ;
if ( F_70 ( V_245 , & V_23 -> V_109 ) )
V_600 = V_250 ;
else
V_600 = V_251 ;
if ( V_23 -> V_93 == V_94 ) {
F_296 ( V_56 , V_56 -> V_193 - V_255 ) ;
V_599 = F_103 ( V_56 -> V_194 + V_56 -> V_193 ) ;
V_598 = F_114 ( 0 , V_56 -> V_194 - V_600 , V_56 -> V_193 + V_600 ) ;
if ( V_598 != V_599 )
return - V_601 ;
}
return 0 ;
}
static void F_297 ( struct V_11 * V_23 )
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
static void F_298 ( struct V_52 * V_56 , struct V_52 * V_602 ,
struct V_52 * * V_603 )
{
if ( ! F_299 ( V_56 ) )
F_190 ( V_56 ) -> V_393 = V_602 ;
V_602 -> V_398 = NULL ;
( * V_603 ) -> V_398 = V_602 ;
* V_603 = V_602 ;
V_56 -> V_193 += V_602 -> V_193 ;
V_56 -> V_397 += V_602 -> V_193 ;
V_56 -> V_604 += V_602 -> V_604 ;
}
static int F_300 ( struct V_11 * V_23 , struct V_52 * V_56 ,
struct V_210 * V_211 )
{
int V_24 = - V_36 ;
switch ( V_211 -> V_226 ) {
case V_406 :
if ( V_23 -> V_110 )
break;
V_24 = V_23 -> V_46 -> V_427 ( V_23 , V_56 ) ;
break;
case V_407 :
if ( V_23 -> V_110 )
break;
if ( ! F_301 ( V_56 , V_401 ) )
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
F_298 ( V_23 -> V_110 , V_56 ,
& V_23 -> V_111 ) ;
V_56 = NULL ;
if ( V_23 -> V_110 -> V_193 >= V_23 -> V_112 )
break;
V_24 = 0 ;
break;
case V_408 :
if ( ! V_23 -> V_110 )
break;
F_298 ( V_23 -> V_110 , V_56 ,
& V_23 -> V_111 ) ;
V_56 = NULL ;
if ( V_23 -> V_110 -> V_193 != V_23 -> V_112 )
break;
V_24 = V_23 -> V_46 -> V_427 ( V_23 , V_23 -> V_110 ) ;
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
static int F_302 ( struct V_11 * V_23 )
{
return 0 ;
}
void F_303 ( struct V_11 * V_23 , int V_605 )
{
T_1 V_417 ;
if ( V_23 -> V_147 != V_150 )
return;
V_417 = V_605 ? V_418 : V_420 ;
F_129 ( V_23 , NULL , NULL , V_417 ) ;
}
static int F_304 ( struct V_11 * V_23 )
{
int V_24 = 0 ;
F_23 ( L_3 , V_23 ) ;
while ( ! F_70 ( V_264 , & V_23 -> V_258 ) ) {
struct V_52 * V_56 ;
F_23 ( L_75 ,
V_23 -> V_265 , F_177 ( & V_23 -> V_151 ) ) ;
V_56 = F_33 ( & V_23 -> V_151 , V_23 -> V_265 ) ;
if ( ! V_56 )
break;
F_209 ( V_56 , & V_23 -> V_151 ) ;
V_23 -> V_265 = F_172 ( V_23 , V_23 -> V_265 ) ;
V_24 = F_300 ( V_23 , V_56 , & F_35 ( V_56 ) -> V_57 ) ;
if ( V_24 )
break;
}
if ( F_170 ( & V_23 -> V_151 ) ) {
V_23 -> V_291 = V_386 ;
F_185 ( V_23 ) ;
}
return V_24 ;
}
static void F_305 ( struct V_11 * V_23 ,
struct V_210 * V_211 )
{
struct V_52 * V_56 ;
F_23 ( L_10 , V_23 , V_211 ) ;
if ( V_211 -> V_212 == V_23 -> V_377 ) {
F_23 ( L_76 , V_211 -> V_212 ) ;
F_86 ( V_23 , V_326 ) ;
return;
}
V_56 = F_33 ( & V_23 -> V_119 , V_211 -> V_212 ) ;
if ( V_56 == NULL ) {
F_23 ( L_77 ,
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
F_214 ( V_23 , V_211 ) ;
F_57 ( V_257 , & V_23 -> V_258 ) ;
F_182 ( V_23 , V_211 ) ;
F_173 ( V_23 ) ;
if ( V_23 -> V_289 == V_422 ) {
F_57 ( V_288 , & V_23 -> V_258 ) ;
V_23 -> V_606 = V_211 -> V_212 ;
}
} else {
F_215 ( V_23 , V_211 ) ;
if ( V_211 -> V_215 ) {
if ( V_23 -> V_606 != V_211 -> V_212 ||
! F_116 ( V_288 ,
& V_23 -> V_258 ) )
F_182 ( V_23 , V_211 ) ;
} else {
F_182 ( V_23 , V_211 ) ;
if ( V_23 -> V_289 == V_422 ) {
F_57 ( V_288 , & V_23 -> V_258 ) ;
V_23 -> V_606 = V_211 -> V_212 ;
}
}
}
}
static void F_306 ( struct V_11 * V_23 ,
struct V_210 * V_211 )
{
struct V_52 * V_56 ;
F_23 ( L_10 , V_23 , V_211 ) ;
if ( V_211 -> V_212 == V_23 -> V_377 ) {
F_23 ( L_76 , V_211 -> V_212 ) ;
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
F_214 ( V_23 , V_211 ) ;
if ( V_211 -> V_215 ) {
if ( ! F_116 ( V_287 , & V_23 -> V_258 ) )
F_183 ( V_23 , V_211 ) ;
} else {
F_183 ( V_23 , V_211 ) ;
F_173 ( V_23 ) ;
if ( V_23 -> V_289 == V_422 )
F_57 ( V_287 , & V_23 -> V_258 ) ;
}
}
static T_1 F_307 ( struct V_11 * V_23 , T_2 V_58 )
{
F_23 ( L_78 , V_23 , V_58 ) ;
F_23 ( L_79 , V_23 -> V_263 ,
V_23 -> V_286 ) ;
if ( V_23 -> V_291 == V_419 ) {
if ( F_186 ( V_23 , V_58 , V_23 -> V_263 ) >=
V_23 -> V_97 ) {
if ( V_23 -> V_97 <= ( ( V_23 -> V_99 + 1 ) >> 1 ) ) {
F_23 ( L_80 ) ;
return V_607 ;
} else {
F_23 ( L_81 ) ;
return V_608 ;
}
}
if ( V_23 -> V_152 . V_54 == V_58 ) {
F_23 ( L_82 ) ;
return V_609 ;
}
if ( F_33 ( & V_23 -> V_151 , V_58 ) ) {
F_23 ( L_83 ) ;
return V_610 ;
}
if ( F_41 ( & V_23 -> V_152 , V_58 ) ) {
F_23 ( L_84 ) ;
return V_611 ;
}
}
if ( V_23 -> V_286 == V_58 ) {
if ( F_186 ( V_23 , V_58 , V_23 -> V_263 ) >=
V_23 -> V_97 ) {
F_23 ( L_85 ) ;
return V_608 ;
} else {
F_23 ( L_86 ) ;
return V_612 ;
}
}
if ( F_186 ( V_23 , V_58 , V_23 -> V_263 ) <
F_186 ( V_23 , V_23 -> V_286 , V_23 -> V_263 ) ) {
F_23 ( L_87 ) ;
return V_613 ;
}
if ( F_186 ( V_23 , V_58 , V_23 -> V_263 ) >= V_23 -> V_97 ) {
if ( V_23 -> V_97 <= ( ( V_23 -> V_99 + 1 ) >> 1 ) ) {
F_23 ( L_88 ) ;
return V_607 ;
} else {
F_23 ( L_85 ) ;
return V_608 ;
}
} else {
F_23 ( L_89 ) ;
return V_614 ;
}
}
static int F_308 ( struct V_11 * V_23 ,
struct V_210 * V_211 ,
struct V_52 * V_56 , T_1 V_417 )
{
int V_24 = 0 ;
bool V_615 = false ;
F_23 ( L_90 , V_23 , V_211 , V_56 ,
V_417 ) ;
switch ( V_417 ) {
case V_616 :
switch ( F_307 ( V_23 , V_211 -> V_58 ) ) {
case V_612 :
F_214 ( V_23 , V_211 ) ;
if ( F_70 ( V_264 , & V_23 -> V_258 ) ) {
F_23 ( L_91 ,
V_211 -> V_58 ) ;
break;
}
V_23 -> V_286 = F_172 ( V_23 ,
V_211 -> V_58 ) ;
V_23 -> V_265 = V_23 -> V_286 ;
V_615 = true ;
V_24 = F_300 ( V_23 , V_56 , V_211 ) ;
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
case V_614 :
F_214 ( V_23 , V_211 ) ;
if ( F_70 ( V_264 , & V_23 -> V_258 ) ) {
F_23 ( L_92 ,
V_211 -> V_58 ) ;
break;
}
F_309 ( & V_23 -> V_151 , V_56 ) ;
V_615 = true ;
F_23 ( L_93 , V_56 ,
F_177 ( & V_23 -> V_151 ) ) ;
F_117 ( V_288 , & V_23 -> V_258 ) ;
F_43 ( & V_23 -> V_152 ) ;
F_205 ( V_23 , V_211 -> V_58 ) ;
V_23 -> V_291 = V_419 ;
break;
case V_613 :
F_214 ( V_23 , V_211 ) ;
break;
case V_607 :
break;
case V_608 :
default:
F_86 ( V_23 , V_326 ) ;
break;
}
break;
case V_617 :
F_214 ( V_23 , V_211 ) ;
if ( V_211 -> V_215 ) {
F_117 ( V_293 , & V_23 -> V_258 ) ;
if ( ! F_116 ( V_287 , & V_23 -> V_258 ) &&
! F_95 ( V_23 ) ) {
V_211 -> V_215 = 0 ;
F_183 ( V_23 , V_211 ) ;
}
F_173 ( V_23 ) ;
} else if ( V_211 -> V_220 ) {
F_297 ( V_23 ) ;
} else {
if ( F_116 ( V_293 ,
& V_23 -> V_258 ) &&
V_23 -> V_383 )
F_27 ( V_23 ) ;
F_173 ( V_23 ) ;
}
break;
case V_618 :
F_57 ( V_293 , & V_23 -> V_258 ) ;
F_214 ( V_23 , V_211 ) ;
if ( V_211 && V_211 -> V_220 ) {
F_57 ( V_257 , & V_23 -> V_258 ) ;
F_119 ( V_23 , 0 ) ;
}
F_32 ( V_23 ) ;
F_43 ( & V_23 -> V_153 ) ;
break;
case V_619 :
F_306 ( V_23 , V_211 ) ;
break;
case V_620 :
F_305 ( V_23 , V_211 ) ;
break;
default:
break;
}
if ( V_56 && ! V_615 ) {
F_23 ( L_94 , V_56 ) ;
F_97 ( V_56 ) ;
}
return V_24 ;
}
static int F_310 ( struct V_11 * V_23 ,
struct V_210 * V_211 ,
struct V_52 * V_56 , T_1 V_417 )
{
int V_24 = 0 ;
T_2 V_58 = V_211 -> V_58 ;
bool V_615 = false ;
F_23 ( L_90 , V_23 , V_211 , V_56 ,
V_417 ) ;
switch ( V_417 ) {
case V_616 :
switch ( F_307 ( V_23 , V_58 ) ) {
case V_612 :
F_214 ( V_23 , V_211 ) ;
F_309 ( & V_23 -> V_151 , V_56 ) ;
V_615 = true ;
F_23 ( L_93 , V_56 ,
F_177 ( & V_23 -> V_151 ) ) ;
V_23 -> V_286 = F_172 ( V_23 , V_58 ) ;
break;
case V_609 :
F_42 ( & V_23 -> V_152 ) ;
F_214 ( V_23 , V_211 ) ;
F_309 ( & V_23 -> V_151 , V_56 ) ;
V_615 = true ;
F_23 ( L_93 , V_56 ,
F_177 ( & V_23 -> V_151 ) ) ;
V_24 = F_304 ( V_23 ) ;
if ( V_24 )
break;
break;
case V_614 :
F_309 ( & V_23 -> V_151 , V_56 ) ;
V_615 = true ;
F_23 ( L_93 , V_56 ,
F_177 ( & V_23 -> V_151 ) ) ;
F_214 ( V_23 , V_211 ) ;
F_205 ( V_23 , V_211 -> V_58 ) ;
break;
case V_611 :
F_309 ( & V_23 -> V_151 , V_56 ) ;
V_615 = true ;
F_23 ( L_93 , V_56 ,
F_177 ( & V_23 -> V_151 ) ) ;
F_214 ( V_23 , V_211 ) ;
F_207 ( V_23 , V_211 -> V_58 ) ;
break;
case V_610 :
F_214 ( V_23 , V_211 ) ;
break;
case V_613 :
break;
case V_607 :
break;
case V_608 :
default:
F_86 ( V_23 , V_326 ) ;
break;
}
break;
case V_617 :
F_214 ( V_23 , V_211 ) ;
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
F_206 ( V_23 ) ;
} else {
if ( F_116 ( V_293 ,
& V_23 -> V_258 ) &&
V_23 -> V_383 )
F_27 ( V_23 ) ;
F_185 ( V_23 ) ;
}
break;
case V_618 :
F_57 ( V_293 , & V_23 -> V_258 ) ;
F_214 ( V_23 , V_211 ) ;
if ( V_211 -> V_220 ) {
F_206 ( V_23 ) ;
} else {
struct V_210 V_621 ;
memset ( & V_621 , 0 , sizeof( V_621 ) ) ;
V_621 . V_219 = 1 ;
V_621 . V_223 = V_259 ;
V_621 . V_212 = V_23 -> V_265 ;
F_115 ( V_23 , & V_621 ) ;
}
break;
case V_619 :
F_306 ( V_23 , V_211 ) ;
break;
case V_620 :
F_305 ( V_23 , V_211 ) ;
break;
}
if ( V_56 && ! V_615 ) {
F_23 ( L_94 , V_56 ) ;
F_97 ( V_56 ) ;
}
return V_24 ;
}
static int F_311 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
V_23 -> V_291 = V_386 ;
if ( V_23 -> V_206 )
V_23 -> V_13 -> V_164 = V_23 -> V_206 -> V_195 -> V_542 ;
else
V_23 -> V_13 -> V_164 = V_23 -> V_13 -> V_8 -> V_195 -> V_622 ;
return F_302 ( V_23 ) ;
}
static int F_312 ( struct V_11 * V_23 ,
struct V_210 * V_211 ,
struct V_52 * V_56 , T_1 V_417 )
{
int V_24 ;
F_23 ( L_90 , V_23 , V_211 , V_56 ,
V_417 ) ;
if ( ! V_211 -> V_220 )
return - V_505 ;
F_208 ( V_23 , V_211 -> V_212 ) ;
if ( ! F_170 ( & V_23 -> V_119 ) )
V_23 -> V_382 = F_212 ( & V_23 -> V_119 ) ;
else
V_23 -> V_382 = NULL ;
V_23 -> V_377 = V_211 -> V_212 ;
V_23 -> V_383 = 0 ;
V_24 = F_311 ( V_23 ) ;
if ( V_24 )
return V_24 ;
F_57 ( V_257 , & V_23 -> V_258 ) ;
F_297 ( V_23 ) ;
if ( V_417 == V_616 )
return - V_505 ;
return F_308 ( V_23 , V_211 , NULL , V_417 ) ;
}
static int F_313 ( struct V_11 * V_23 ,
struct V_210 * V_211 ,
struct V_52 * V_56 , T_1 V_417 )
{
int V_24 ;
if ( ! V_211 -> V_215 )
return - V_505 ;
F_117 ( V_293 , & V_23 -> V_258 ) ;
V_23 -> V_291 = V_386 ;
F_208 ( V_23 , V_211 -> V_212 ) ;
if ( ! F_170 ( & V_23 -> V_119 ) )
V_23 -> V_382 = F_212 ( & V_23 -> V_119 ) ;
else
V_23 -> V_382 = NULL ;
V_23 -> V_377 = V_211 -> V_212 ;
V_23 -> V_383 = 0 ;
if ( V_23 -> V_206 )
V_23 -> V_13 -> V_164 = V_23 -> V_206 -> V_195 -> V_542 ;
else
V_23 -> V_13 -> V_164 = V_23 -> V_13 -> V_8 -> V_195 -> V_622 ;
V_24 = F_302 ( V_23 ) ;
if ( ! V_24 )
V_24 = F_308 ( V_23 , V_211 , V_56 , V_417 ) ;
return V_24 ;
}
static bool F_314 ( struct V_11 * V_23 , T_2 V_212 )
{
T_2 V_623 ;
V_623 = F_186 ( V_23 , V_23 -> V_377 , V_23 -> V_416 ) ;
return F_186 ( V_23 , V_23 -> V_377 , V_212 ) <= V_623 ;
}
static int F_315 ( struct V_11 * V_23 , struct V_210 * V_211 ,
struct V_52 * V_56 , T_1 V_417 )
{
int V_24 = 0 ;
F_23 ( L_95 , V_23 ,
V_211 , V_56 , V_417 , V_23 -> V_291 ) ;
if ( F_314 ( V_23 , V_211 -> V_212 ) ) {
switch ( V_23 -> V_291 ) {
case V_386 :
V_24 = F_308 ( V_23 , V_211 , V_56 , V_417 ) ;
break;
case V_419 :
V_24 = F_310 ( V_23 , V_211 , V_56 ,
V_417 ) ;
break;
case V_300 :
V_24 = F_312 ( V_23 , V_211 , V_56 , V_417 ) ;
break;
case V_298 :
V_24 = F_313 ( V_23 , V_211 , V_56 , V_417 ) ;
break;
default:
break;
}
} else {
F_23 ( L_96 ,
V_211 -> V_212 , V_23 -> V_377 ,
V_23 -> V_416 ) ;
F_86 ( V_23 , V_326 ) ;
}
return V_24 ;
}
static int F_316 ( struct V_11 * V_23 , struct V_210 * V_211 ,
struct V_52 * V_56 )
{
F_23 ( L_97 , V_23 , V_211 , V_56 ,
V_23 -> V_291 ) ;
if ( F_307 ( V_23 , V_211 -> V_58 ) ==
V_612 ) {
F_214 ( V_23 , V_211 ) ;
F_23 ( L_98 , V_23 -> V_265 ,
F_172 ( V_23 , V_23 -> V_265 ) ) ;
V_23 -> V_265 = F_172 ( V_23 , V_23 -> V_265 ) ;
F_300 ( V_23 , V_56 , V_211 ) ;
} else {
if ( V_23 -> V_110 ) {
F_97 ( V_23 -> V_110 ) ;
V_23 -> V_110 = NULL ;
}
V_23 -> V_111 = NULL ;
V_23 -> V_112 = 0 ;
if ( V_56 ) {
F_23 ( L_94 , V_56 ) ;
F_97 ( V_56 ) ;
}
}
V_23 -> V_263 = V_211 -> V_58 ;
V_23 -> V_286 = F_172 ( V_23 , V_211 -> V_58 ) ;
return 0 ;
}
static int F_317 ( struct V_11 * V_23 , struct V_52 * V_56 )
{
struct V_210 * V_211 = & F_35 ( V_56 ) -> V_57 ;
T_2 V_193 ;
T_1 V_417 ;
F_100 ( V_23 , V_56 ) ;
V_193 = V_56 -> V_193 ;
if ( F_295 ( V_23 , V_56 ) )
goto V_597;
if ( ! V_211 -> V_219 && V_211 -> V_226 == V_407 )
V_193 -= V_401 ;
if ( V_23 -> V_93 == V_94 )
V_193 -= V_255 ;
if ( V_193 > V_23 -> V_116 ) {
F_86 ( V_23 , V_326 ) ;
goto V_597;
}
if ( ( V_23 -> V_147 == V_150 ||
V_23 -> V_147 == V_154 ) && F_318 ( V_23 -> V_194 , V_56 ) )
goto V_597;
if ( ! V_211 -> V_219 ) {
int V_24 ;
F_23 ( L_99 ,
V_211 -> V_226 , V_211 -> V_212 , V_211 -> V_215 ,
V_211 -> V_58 ) ;
if ( V_211 -> V_215 && V_23 -> V_289 != V_422 )
goto V_597;
if ( V_23 -> V_147 != V_154 ) {
V_417 = V_616 ;
V_24 = F_315 ( V_23 , V_211 , V_56 , V_417 ) ;
} else {
V_24 = F_316 ( V_23 , V_211 , V_56 ) ;
}
if ( V_24 )
F_86 ( V_23 , V_326 ) ;
} else {
const T_1 V_624 [ 4 ] = {
V_617 , V_619 ,
V_618 , V_620
} ;
if ( V_23 -> V_147 == V_154 )
goto V_597;
F_23 ( L_100 ,
V_211 -> V_212 , V_211 -> V_215 , V_211 -> V_220 ,
V_211 -> V_223 ) ;
if ( V_193 != 0 ) {
F_287 ( L_101 , V_193 ) ;
F_86 ( V_23 , V_326 ) ;
goto V_597;
}
if ( V_211 -> V_215 && ( V_211 -> V_220 ||
V_23 -> V_289 != V_422 ) )
goto V_597;
V_417 = V_624 [ V_211 -> V_223 ] ;
if ( F_315 ( V_23 , V_211 , V_56 , V_417 ) )
F_86 ( V_23 , V_326 ) ;
}
return 0 ;
V_597:
F_97 ( V_56 ) ;
return 0 ;
}
static void F_319 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct F_290 V_592 ;
T_2 V_625 ;
if ( V_23 -> V_114 >= ( V_115 + 1 ) / 2 )
return;
V_625 = V_115 - V_23 -> V_114 ;
F_23 ( L_102 , V_23 , V_625 ) ;
V_23 -> V_114 += V_625 ;
V_592 . V_14 = F_18 ( V_23 -> V_17 ) ;
V_592 . V_165 = F_18 ( V_625 ) ;
V_23 -> V_19 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_596 , sizeof( V_592 ) , & V_592 ) ;
}
static int F_320 ( struct V_11 * V_23 , struct V_52 * V_56 )
{
int V_24 ;
if ( ! V_23 -> V_114 ) {
F_287 ( L_103 ) ;
F_86 ( V_23 , V_326 ) ;
return - V_626 ;
}
if ( V_23 -> V_117 < V_56 -> V_193 ) {
F_287 ( L_104 ) ;
return - V_626 ;
}
V_23 -> V_114 -- ;
F_23 ( L_105 , V_23 -> V_114 + 1 , V_23 -> V_114 ) ;
F_319 ( V_23 ) ;
V_24 = 0 ;
if ( ! V_23 -> V_110 ) {
T_2 V_112 ;
V_112 = F_103 ( V_56 -> V_194 ) ;
F_102 ( V_56 , V_401 ) ;
F_23 ( L_106 ,
V_112 , V_56 -> V_193 , V_23 -> V_117 ) ;
if ( V_112 > V_23 -> V_117 ) {
F_287 ( L_107 ) ;
V_24 = - V_410 ;
goto V_627;
}
if ( V_56 -> V_193 > V_112 ) {
F_287 ( L_108 ) ;
V_24 = - V_36 ;
goto V_627;
}
if ( V_56 -> V_193 == V_112 )
return V_23 -> V_46 -> V_427 ( V_23 , V_56 ) ;
V_23 -> V_110 = V_56 ;
V_23 -> V_112 = V_112 ;
V_23 -> V_111 = V_56 ;
return 0 ;
}
F_23 ( L_109 ,
V_23 -> V_110 -> V_193 , V_56 -> V_193 , V_23 -> V_112 ) ;
if ( V_23 -> V_110 -> V_193 + V_56 -> V_193 > V_23 -> V_112 ) {
F_287 ( L_108 ) ;
V_24 = - V_36 ;
goto V_627;
}
F_298 ( V_23 -> V_110 , V_56 , & V_23 -> V_111 ) ;
V_56 = NULL ;
if ( V_23 -> V_110 -> V_193 == V_23 -> V_112 ) {
V_24 = V_23 -> V_46 -> V_427 ( V_23 , V_23 -> V_110 ) ;
if ( ! V_24 ) {
V_23 -> V_110 = NULL ;
V_23 -> V_111 = NULL ;
V_23 -> V_112 = 0 ;
}
}
V_627:
if ( V_24 ) {
F_97 ( V_56 ) ;
F_97 ( V_23 -> V_110 ) ;
V_23 -> V_110 = NULL ;
V_23 -> V_111 = NULL ;
V_23 -> V_112 = 0 ;
}
return 0 ;
}
static void F_321 ( struct V_12 * V_13 , T_2 V_14 ,
struct V_52 * V_56 )
{
struct V_11 * V_23 ;
V_23 = F_7 ( V_13 , V_14 ) ;
if ( ! V_23 ) {
if ( V_14 == V_322 ) {
V_23 = F_322 ( V_13 , V_56 ) ;
if ( ! V_23 ) {
F_97 ( V_56 ) ;
return;
}
F_9 ( V_23 ) ;
} else {
F_23 ( L_110 , V_14 ) ;
F_97 ( V_56 ) ;
return;
}
}
F_23 ( L_111 , V_23 , V_56 -> V_193 ) ;
if ( V_23 -> V_39 == V_40 )
F_130 ( V_23 ) ;
if ( V_23 -> V_45 != V_75 )
goto V_597;
switch ( V_23 -> V_147 ) {
case V_149 :
if ( F_320 ( V_23 , V_56 ) < 0 )
goto V_597;
goto V_27;
case V_148 :
if ( V_23 -> V_117 < V_56 -> V_193 ) {
F_287 ( L_112 ) ;
goto V_597;
}
if ( ! V_23 -> V_46 -> V_427 ( V_23 , V_56 ) )
goto V_27;
break;
case V_150 :
case V_154 :
F_317 ( V_23 , V_56 ) ;
goto V_27;
default:
F_23 ( L_113 , V_23 , V_23 -> V_147 ) ;
break;
}
V_597:
F_97 ( V_56 ) ;
V_27:
F_48 ( V_23 ) ;
}
static void F_323 ( struct V_12 * V_13 , T_3 V_20 ,
struct V_52 * V_56 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_11 * V_23 ;
if ( V_8 -> type != V_123 )
goto V_628;
V_23 = F_165 ( 0 , V_20 , & V_8 -> V_21 , & V_8 -> V_156 ,
V_123 ) ;
if ( ! V_23 )
goto V_628;
F_23 ( L_111 , V_23 , V_56 -> V_193 ) ;
if ( V_23 -> V_45 != V_629 && V_23 -> V_45 != V_75 )
goto V_597;
if ( V_23 -> V_117 < V_56 -> V_193 )
goto V_597;
F_81 ( & F_35 ( V_56 ) -> V_57 . V_630 , & V_8 -> V_156 ) ;
F_35 ( V_56 ) -> V_57 . V_20 = V_20 ;
if ( ! V_23 -> V_46 -> V_427 ( V_23 , V_56 ) ) {
F_49 ( V_23 ) ;
return;
}
V_597:
F_49 ( V_23 ) ;
V_628:
F_97 ( V_56 ) ;
}
static void F_324 ( struct V_12 * V_13 , struct V_52 * V_56 )
{
struct V_252 * V_253 = ( void * ) V_56 -> V_194 ;
struct V_7 * V_8 = V_13 -> V_8 ;
T_2 V_14 , V_193 ;
T_3 V_20 ;
if ( V_8 -> V_45 != V_75 ) {
F_23 ( L_114 ) ;
F_309 ( & V_13 -> V_365 , V_56 ) ;
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
F_325 ( & V_8 -> V_195 -> V_631 , & V_8 -> V_156 ,
F_3 ( V_8 ) ) ) {
F_97 ( V_56 ) ;
return;
}
F_23 ( L_115 , V_193 , V_14 ) ;
switch ( V_14 ) {
case V_126 :
F_294 ( V_13 , V_56 ) ;
break;
case V_125 :
V_20 = F_326 ( ( T_3 * ) V_56 -> V_194 ) ;
F_102 ( V_56 , V_399 ) ;
F_323 ( V_13 , V_20 , V_56 ) ;
break;
case V_432 :
F_293 ( V_13 , V_56 ) ;
break;
default:
F_321 ( V_13 , V_14 , V_56 ) ;
break;
}
}
static void F_327 ( struct V_71 * V_72 )
{
struct V_12 * V_13 = F_46 ( V_72 , struct V_12 ,
V_353 ) ;
struct V_52 * V_56 ;
F_23 ( L_116 ) ;
while ( ( V_56 = F_171 ( & V_13 -> V_365 ) ) )
F_324 ( V_13 , V_56 ) ;
}
static struct V_12 * F_328 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_362 ;
struct V_146 * V_202 ;
if ( V_13 )
return V_13 ;
V_202 = F_329 ( V_8 ) ;
if ( ! V_202 )
return NULL ;
V_13 = F_51 ( sizeof( * V_13 ) , V_65 ) ;
if ( ! V_13 ) {
F_159 ( V_202 ) ;
return NULL ;
}
F_56 ( & V_13 -> V_367 ) ;
V_8 -> V_362 = V_13 ;
V_13 -> V_8 = F_330 ( V_8 ) ;
V_13 -> V_202 = V_202 ;
F_23 ( L_117 , V_8 , V_13 , V_202 ) ;
switch ( V_8 -> type ) {
case V_2 :
if ( V_8 -> V_195 -> V_632 ) {
V_13 -> V_164 = V_8 -> V_195 -> V_632 ;
break;
}
default:
V_13 -> V_164 = V_8 -> V_195 -> V_622 ;
break;
}
V_13 -> V_315 = 0 ;
V_13 -> V_269 = V_633 | V_634 ;
if ( V_8 -> type == V_123 &&
F_242 ( V_8 -> V_195 , V_635 ) )
V_13 -> V_269 |= V_270 ;
if ( F_242 ( V_8 -> V_195 , V_636 ) &&
( F_331 ( V_8 -> V_195 ) ||
F_242 ( V_8 -> V_195 , V_637 ) ) )
V_13 -> V_269 |= V_638 ;
F_52 ( & V_13 -> V_190 ) ;
F_52 ( & V_13 -> V_18 ) ;
F_332 ( & V_13 -> V_140 ) ;
F_332 ( & V_13 -> V_361 ) ;
F_55 ( & V_13 -> V_311 , F_147 ) ;
F_67 ( & V_13 -> V_365 ) ;
F_333 ( & V_13 -> V_353 , F_327 ) ;
F_333 ( & V_13 -> V_155 , F_80 ) ;
V_13 -> V_120 = V_121 ;
return V_13 ;
}
static bool F_334 ( T_2 V_20 , T_1 V_10 ) {
if ( ! V_20 )
return false ;
if ( F_335 ( V_10 ) )
return ( V_20 <= 0x00ff ) ;
return ( ( V_20 & 0x0101 ) == 0x0001 ) ;
}
int F_336 ( struct V_11 * V_23 , T_3 V_20 , T_2 V_14 ,
T_4 * V_156 , T_1 V_10 )
{
struct V_12 * V_13 ;
struct V_7 * V_8 ;
struct V_267 * V_195 ;
int V_24 ;
F_23 ( L_118 , & V_23 -> V_21 , V_156 ,
V_10 , F_69 ( V_20 ) ) ;
V_195 = F_337 ( V_156 , & V_23 -> V_21 , V_23 -> V_9 ) ;
if ( ! V_195 )
return - V_639 ;
F_149 ( V_195 ) ;
if ( ! F_334 ( F_69 ( V_20 ) , V_10 ) && ! V_14 &&
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
V_24 = - V_640 ;
goto V_27;
}
switch ( V_23 -> V_45 ) {
case V_78 :
case V_174 :
case V_76 :
V_24 = 0 ;
goto V_27;
case V_75 :
V_24 = - V_641 ;
goto V_27;
case V_89 :
case V_629 :
break;
default:
V_24 = - V_412 ;
goto V_27;
}
F_81 ( & V_23 -> V_156 , V_156 ) ;
V_23 -> V_10 = V_10 ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_14 ;
if ( F_335 ( V_10 ) ) {
if ( V_10 == V_4 )
V_10 = V_3 ;
else
V_10 = V_642 ;
if ( F_242 ( V_195 , V_643 ) )
V_8 = F_338 ( V_195 , V_156 , V_10 ,
V_23 -> V_79 ,
V_644 ,
V_340 ) ;
else
V_8 = F_339 ( V_195 , V_156 , V_10 ,
V_23 -> V_79 ,
V_644 ) ;
} else {
T_1 V_188 = F_87 ( V_23 ) ;
V_8 = F_340 ( V_195 , V_156 , V_23 -> V_79 , V_188 ) ;
}
if ( F_118 ( V_8 ) ) {
V_24 = F_191 ( V_8 ) ;
goto V_27;
}
V_13 = F_328 ( V_8 ) ;
if ( ! V_13 ) {
F_75 ( V_8 ) ;
V_24 = - V_66 ;
goto V_27;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_23 ) ;
if ( V_14 && F_4 ( V_13 , V_14 ) ) {
F_75 ( V_8 ) ;
V_24 = - V_645 ;
goto V_646;
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
V_646:
F_48 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
V_27:
F_151 ( V_195 ) ;
F_258 ( V_195 ) ;
return V_24 ;
}
int F_341 ( struct V_267 * V_195 , T_4 * V_630 )
{
int V_647 = 0 , V_648 = 0 , V_649 = 0 ;
struct V_11 * V_15 ;
F_23 ( L_119 , V_195 -> V_336 , V_630 ) ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
if ( V_15 -> V_45 != V_172 )
continue;
if ( ! F_15 ( & V_15 -> V_21 , & V_195 -> V_630 ) ) {
V_648 |= V_650 ;
if ( F_70 ( V_651 , & V_15 -> V_109 ) )
V_648 |= V_652 ;
V_647 ++ ;
} else if ( ! F_15 ( & V_15 -> V_21 , V_373 ) ) {
V_649 |= V_650 ;
if ( F_70 ( V_651 , & V_15 -> V_109 ) )
V_649 |= V_652 ;
}
}
F_123 ( & V_25 ) ;
return V_647 ? V_648 : V_649 ;
}
static struct V_11 * F_342 ( struct V_11 * V_15 ,
struct V_7 * V_8 )
{
T_1 V_9 = F_2 ( V_8 ) ;
F_122 ( & V_25 ) ;
if ( V_15 )
V_15 = F_343 ( V_15 , V_87 ) ;
else
V_15 = F_344 ( V_88 . V_398 , F_345 ( * V_15 ) , V_87 ) ;
F_346 (c, &chan_list, global_l) {
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
static void F_347 ( struct V_7 * V_8 , T_1 V_169 )
{
struct V_267 * V_195 = V_8 -> V_195 ;
struct V_12 * V_13 ;
struct V_11 * V_507 ;
T_1 V_10 ;
if ( V_8 -> type != V_123 && V_8 -> type != V_2 )
return;
F_23 ( L_120 , V_8 , & V_8 -> V_156 , V_169 ) ;
if ( V_169 ) {
F_156 ( V_8 , F_348 ( V_169 ) ) ;
return;
}
V_13 = F_328 ( V_8 ) ;
if ( ! V_13 )
return;
V_10 = F_3 ( V_8 ) ;
if ( F_325 ( & V_195 -> V_631 , & V_8 -> V_156 , V_10 ) )
return;
V_507 = F_342 ( NULL , V_8 ) ;
while ( V_507 ) {
struct V_11 * V_23 , * V_398 ;
if ( F_4 ( V_13 , V_507 -> V_17 ) )
goto V_398;
F_9 ( V_507 ) ;
V_23 = V_507 -> V_46 -> V_512 ( V_507 ) ;
if ( V_23 ) {
F_81 ( & V_23 -> V_21 , & V_8 -> V_21 ) ;
F_81 ( & V_23 -> V_156 , & V_8 -> V_156 ) ;
V_23 -> V_9 = F_2 ( V_8 ) ;
V_23 -> V_10 = V_10 ;
F_68 ( V_13 , V_23 ) ;
}
F_48 ( V_507 ) ;
V_398:
V_398 = F_342 ( V_507 , V_8 ) ;
F_49 ( V_507 ) ;
V_507 = V_398 ;
}
F_144 ( V_13 ) ;
}
int F_349 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_362 ;
F_23 ( L_121 , V_8 ) ;
if ( ! V_13 )
return V_121 ;
return V_13 -> V_120 ;
}
static void F_350 ( struct V_7 * V_8 , T_1 V_74 )
{
if ( V_8 -> type != V_123 && V_8 -> type != V_2 )
return;
F_23 ( L_122 , V_8 , V_74 ) ;
F_156 ( V_8 , F_348 ( V_74 ) ) ;
}
static inline void F_351 ( struct V_11 * V_23 , T_1 V_653 )
{
if ( V_23 -> V_39 != V_122 )
return;
if ( V_653 == 0x00 ) {
if ( V_23 -> V_79 == V_179 ) {
F_85 ( V_23 , V_654 ) ;
} else if ( V_23 -> V_79 == V_176 ||
V_23 -> V_79 == V_177 )
F_47 ( V_23 , V_77 ) ;
} else {
if ( V_23 -> V_79 == V_179 )
F_74 ( V_23 ) ;
}
}
static void F_352 ( struct V_7 * V_8 , T_1 V_169 , T_1 V_653 )
{
struct V_12 * V_13 = V_8 -> V_362 ;
struct V_11 * V_23 ;
if ( ! V_13 )
return;
F_23 ( L_123 , V_13 , V_169 , V_653 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
F_9 ( V_23 ) ;
F_23 ( L_124 , V_23 , V_23 -> V_17 ,
F_24 ( V_23 -> V_45 ) ) ;
if ( V_23 -> V_17 == V_322 ) {
F_48 ( V_23 ) ;
continue;
}
if ( ! V_169 && V_653 )
V_23 -> V_79 = V_8 -> V_79 ;
if ( ! F_120 ( V_23 ) ) {
F_48 ( V_23 ) ;
continue;
}
if ( ! V_169 && ( V_23 -> V_45 == V_75 ||
V_23 -> V_45 == V_76 ) ) {
V_23 -> V_46 -> V_595 ( V_23 ) ;
F_351 ( V_23 , V_653 ) ;
F_48 ( V_23 ) ;
continue;
}
if ( V_23 -> V_45 == V_78 ) {
if ( ! V_169 )
F_134 ( V_23 ) ;
else
F_85 ( V_23 , V_655 ) ;
} else if ( V_23 -> V_45 == V_174 &&
V_23 -> V_147 != V_149 ) {
struct V_167 V_158 ;
T_5 V_656 , V_657 ;
if ( ! V_169 ) {
if ( F_70 ( V_160 , & V_23 -> V_109 ) ) {
V_656 = V_328 ;
V_657 = V_329 ;
V_23 -> V_46 -> V_330 ( V_23 ) ;
} else {
F_22 ( V_23 , V_76 ) ;
V_656 = V_331 ;
V_657 = V_170 ;
}
} else {
F_22 ( V_23 , V_163 ) ;
F_85 ( V_23 , V_655 ) ;
V_656 = V_168 ;
V_657 = V_170 ;
}
V_158 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_158 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_158 . V_159 = F_18 ( V_656 ) ;
V_158 . V_169 = F_18 ( V_657 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_171 ,
sizeof( V_158 ) , & V_158 ) ;
if ( ! F_70 ( V_333 , & V_23 -> V_92 ) &&
V_656 == V_331 ) {
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
void F_353 ( struct V_7 * V_8 , struct V_52 * V_56 , T_2 V_109 )
{
struct V_12 * V_13 = V_8 -> V_362 ;
struct V_252 * V_658 ;
int V_193 ;
if ( ! V_13 && V_8 -> V_195 -> V_539 != V_659 )
goto V_597;
if ( ! V_13 )
V_13 = F_328 ( V_8 ) ;
if ( ! V_13 )
goto V_597;
F_23 ( L_125 , V_13 , V_56 -> V_193 , V_109 ) ;
switch ( V_109 ) {
case V_197 :
case V_196 :
case V_207 :
if ( V_13 -> V_660 ) {
F_287 ( L_126 , V_56 -> V_193 ) ;
F_97 ( V_13 -> V_364 ) ;
V_13 -> V_364 = NULL ;
V_13 -> V_660 = 0 ;
F_146 ( V_13 , V_661 ) ;
}
if ( V_56 -> V_193 < V_249 ) {
F_287 ( L_127 , V_56 -> V_193 ) ;
F_146 ( V_13 , V_661 ) ;
goto V_597;
}
V_658 = (struct V_252 * ) V_56 -> V_194 ;
V_193 = F_69 ( V_658 -> V_193 ) + V_249 ;
if ( V_193 == V_56 -> V_193 ) {
F_324 ( V_13 , V_56 ) ;
return;
}
F_23 ( L_128 , V_193 , V_56 -> V_193 ) ;
if ( V_56 -> V_193 > V_193 ) {
F_287 ( L_129 ,
V_56 -> V_193 , V_193 ) ;
F_146 ( V_13 , V_661 ) ;
goto V_597;
}
V_13 -> V_364 = F_111 ( V_193 , V_65 ) ;
if ( ! V_13 -> V_364 )
goto V_597;
F_354 ( V_56 , F_113 ( V_13 -> V_364 , V_56 -> V_193 ) ,
V_56 -> V_193 ) ;
V_13 -> V_660 = V_193 - V_56 -> V_193 ;
break;
case V_662 :
F_23 ( L_130 , V_56 -> V_193 , V_13 -> V_660 ) ;
if ( ! V_13 -> V_660 ) {
F_287 ( L_131 , V_56 -> V_193 ) ;
F_146 ( V_13 , V_661 ) ;
goto V_597;
}
if ( V_56 -> V_193 > V_13 -> V_660 ) {
F_287 ( L_132 ,
V_56 -> V_193 , V_13 -> V_660 ) ;
F_97 ( V_13 -> V_364 ) ;
V_13 -> V_364 = NULL ;
V_13 -> V_660 = 0 ;
F_146 ( V_13 , V_661 ) ;
goto V_597;
}
F_354 ( V_56 , F_113 ( V_13 -> V_364 , V_56 -> V_193 ) ,
V_56 -> V_193 ) ;
V_13 -> V_660 -= V_56 -> V_193 ;
if ( ! V_13 -> V_660 ) {
struct V_52 * V_364 = V_13 -> V_364 ;
V_13 -> V_364 = NULL ;
F_324 ( V_13 , V_364 ) ;
}
break;
}
V_597:
F_97 ( V_56 ) ;
}
static int F_355 ( struct V_663 * V_664 , void * V_28 )
{
struct V_11 * V_15 ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
F_356 ( V_664 , L_133 ,
& V_15 -> V_21 , V_15 -> V_9 , & V_15 -> V_156 , V_15 -> V_10 ,
V_15 -> V_45 , F_69 ( V_15 -> V_20 ) ,
V_15 -> V_17 , V_15 -> V_16 , V_15 -> V_117 , V_15 -> V_37 ,
V_15 -> V_79 , V_15 -> V_147 ) ;
}
F_123 ( & V_25 ) ;
return 0 ;
}
static int F_357 ( struct V_665 * V_665 , struct V_666 * V_666 )
{
return F_358 ( V_666 , F_355 , V_665 -> V_667 ) ;
}
int T_11 F_359 ( void )
{
int V_24 ;
V_24 = F_360 () ;
if ( V_24 < 0 )
return V_24 ;
F_361 ( & V_668 ) ;
if ( F_362 ( V_669 ) )
return 0 ;
V_670 = F_363 ( L_134 , 0444 , V_669 ,
NULL , & V_671 ) ;
F_364 ( L_135 , 0644 , V_669 ,
& V_115 ) ;
F_364 ( L_136 , 0644 , V_669 ,
& V_118 ) ;
return 0 ;
}
void F_365 ( void )
{
F_366 ( V_670 ) ;
F_367 ( & V_668 ) ;
F_368 () ;
}
