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
F_23 ( L_4 , V_15 , F_61 ( & V_15 -> V_90 . V_93 ) ) ;
F_62 ( & V_15 -> V_90 ) ;
}
void F_49 ( struct V_11 * V_15 )
{
F_23 ( L_4 , V_15 , F_61 ( & V_15 -> V_90 . V_93 ) ) ;
F_63 ( & V_15 -> V_90 , F_58 ) ;
}
void F_64 ( struct V_11 * V_23 )
{
V_23 -> V_94 = V_95 ;
V_23 -> V_96 = V_97 ;
V_23 -> V_98 = V_99 ;
V_23 -> V_100 = V_99 ;
V_23 -> V_101 = V_23 -> V_96 ;
V_23 -> V_102 = V_23 -> V_98 ;
V_23 -> V_103 = V_99 ;
V_23 -> V_79 = V_104 ;
V_23 -> V_105 = V_106 ;
V_23 -> V_49 = V_107 ;
V_23 -> V_51 = V_108 ;
V_23 -> V_92 = 0 ;
F_57 ( V_109 , & V_23 -> V_110 ) ;
}
static void F_65 ( struct V_11 * V_23 )
{
V_23 -> V_111 = NULL ;
V_23 -> V_112 = NULL ;
V_23 -> V_113 = 0 ;
V_23 -> V_114 = 0 ;
V_23 -> V_115 = V_116 ;
V_23 -> V_117 = F_66 ( T_2 , V_23 -> V_118 , V_119 ) ;
F_67 ( & V_23 -> V_120 ) ;
}
void F_68 ( struct V_12 * V_13 , struct V_11 * V_23 )
{
F_23 ( L_5 , V_13 ,
F_69 ( V_23 -> V_20 ) , V_23 -> V_16 ) ;
V_13 -> V_121 = V_122 ;
V_23 -> V_13 = V_13 ;
switch ( V_23 -> V_39 ) {
case V_123 :
V_23 -> V_17 = F_21 ( V_13 ) ;
if ( V_13 -> V_8 -> type == V_124 )
V_23 -> V_37 = V_38 ;
break;
case V_125 :
V_23 -> V_17 = V_126 ;
V_23 -> V_16 = V_126 ;
V_23 -> V_37 = V_38 ;
break;
case V_40 :
break;
default:
V_23 -> V_17 = V_127 ;
V_23 -> V_16 = V_127 ;
V_23 -> V_37 = V_38 ;
}
V_23 -> V_128 = V_129 ;
V_23 -> V_130 = V_131 ;
V_23 -> V_132 = V_133 ;
V_23 -> V_134 = V_135 ;
V_23 -> V_136 = V_137 ;
V_23 -> V_138 = V_139 ;
F_60 ( V_23 ) ;
if ( V_23 -> V_39 != V_40 ||
F_70 ( V_140 , & V_23 -> V_110 ) )
F_71 ( V_13 -> V_8 ) ;
F_54 ( & V_23 -> V_64 , & V_13 -> V_141 ) ;
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
V_23 -> V_46 -> V_142 ( V_23 , V_24 ) ;
if ( V_13 ) {
struct V_143 * V_144 = V_13 -> V_8 -> V_143 ;
F_59 ( & V_23 -> V_64 ) ;
F_49 ( V_23 ) ;
V_23 -> V_13 = NULL ;
if ( V_23 -> V_39 != V_40 ||
F_70 ( V_140 , & V_23 -> V_110 ) )
F_75 ( V_13 -> V_8 ) ;
if ( V_144 && V_144 -> V_145 == V_23 )
V_144 -> V_145 = NULL ;
}
if ( V_23 -> V_146 ) {
struct V_147 * V_146 = V_23 -> V_146 ;
F_23 ( L_7 , V_23 , V_146 ) ;
F_76 ( V_146 ) ;
}
if ( F_70 ( V_91 , & V_23 -> V_92 ) )
return;
switch( V_23 -> V_148 ) {
case V_149 :
break;
case V_150 :
F_77 ( & V_23 -> V_120 ) ;
break;
case V_151 :
F_32 ( V_23 ) ;
F_78 ( V_23 ) ;
F_79 ( V_23 ) ;
F_77 ( & V_23 -> V_152 ) ;
F_39 ( & V_23 -> V_153 ) ;
F_39 ( & V_23 -> V_154 ) ;
case V_155 :
F_77 ( & V_23 -> V_120 ) ;
break;
}
return;
}
static void F_80 ( struct V_71 * V_72 )
{
struct V_12 * V_13 = F_46 ( V_72 , struct V_12 ,
V_156 ) ;
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_11 * V_23 ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
F_9 ( V_23 ) ;
F_81 ( & V_23 -> V_157 , & V_8 -> V_157 ) ;
V_23 -> V_10 = F_3 ( V_8 ) ;
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static void F_82 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_158 V_159 ;
T_2 V_160 ;
if ( F_70 ( V_161 , & V_23 -> V_110 ) )
V_160 = V_162 ;
else
V_160 = V_163 ;
F_22 ( V_23 , V_164 ) ;
V_159 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_159 . V_165 = F_18 ( V_23 -> V_118 ) ;
V_159 . V_117 = F_18 ( V_23 -> V_117 ) ;
V_159 . V_166 = F_18 ( V_23 -> V_115 ) ;
V_159 . V_160 = F_18 ( V_160 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_167 , sizeof( V_159 ) ,
& V_159 ) ;
}
static void F_84 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_168 V_159 ;
T_2 V_160 ;
if ( F_70 ( V_161 , & V_23 -> V_110 ) )
V_160 = V_169 ;
else
V_160 = V_163 ;
F_22 ( V_23 , V_164 ) ;
V_159 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_159 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_159 . V_160 = F_18 ( V_160 ) ;
V_159 . V_170 = F_18 ( V_171 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_172 , sizeof( V_159 ) , & V_159 ) ;
}
void F_47 ( struct V_11 * V_23 , int V_74 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
F_23 ( L_2 , V_23 , F_24 ( V_23 -> V_45 ) ) ;
switch ( V_23 -> V_45 ) {
case V_173 :
V_23 -> V_46 -> V_142 ( V_23 , 0 ) ;
break;
case V_75 :
case V_76 :
if ( V_23 -> V_39 == V_123 ) {
F_85 ( V_23 , V_23 -> V_46 -> V_174 ( V_23 ) ) ;
F_86 ( V_23 , V_74 ) ;
} else
F_73 ( V_23 , V_74 ) ;
break;
case V_175 :
if ( V_23 -> V_39 == V_123 ) {
if ( V_13 -> V_8 -> type == V_124 )
F_84 ( V_23 ) ;
else if ( V_13 -> V_8 -> type == V_2 )
F_82 ( V_23 ) ;
}
F_73 ( V_23 , V_74 ) ;
break;
case V_78 :
case V_164 :
F_73 ( V_23 , V_74 ) ;
break;
default:
V_23 -> V_46 -> V_142 ( V_23 , 0 ) ;
break;
}
}
static inline T_1 F_87 ( struct V_11 * V_23 )
{
switch ( V_23 -> V_39 ) {
case V_176 :
switch ( V_23 -> V_79 ) {
case V_177 :
case V_178 :
return V_179 ;
case V_180 :
return V_181 ;
default:
return V_182 ;
}
break;
case V_125 :
if ( V_23 -> V_20 == F_18 ( V_183 ) ) {
if ( V_23 -> V_79 == V_104 )
V_23 -> V_79 = V_80 ;
}
if ( V_23 -> V_79 == V_177 ||
V_23 -> V_79 == V_178 )
return V_184 ;
else
return V_182 ;
break;
case V_123 :
if ( V_23 -> V_20 == F_18 ( V_185 ) ) {
if ( V_23 -> V_79 == V_104 )
V_23 -> V_79 = V_80 ;
if ( V_23 -> V_79 == V_177 ||
V_23 -> V_79 == V_178 )
return V_184 ;
else
return V_182 ;
}
default:
switch ( V_23 -> V_79 ) {
case V_177 :
case V_178 :
return V_186 ;
case V_180 :
return V_187 ;
default:
return V_182 ;
}
break;
}
}
int F_88 ( struct V_11 * V_23 , bool V_188 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
T_7 V_189 ;
if ( V_13 -> V_8 -> type == V_2 )
return F_89 ( V_13 -> V_8 , V_23 -> V_79 ) ;
V_189 = F_87 ( V_23 ) ;
return F_90 ( V_13 -> V_8 , V_23 -> V_79 , V_189 ,
V_188 ) ;
}
static T_1 F_91 ( struct V_12 * V_13 )
{
T_1 V_190 ;
F_8 ( & V_13 -> V_191 ) ;
if ( ++ V_13 -> V_192 > 128 )
V_13 -> V_192 = 1 ;
V_190 = V_13 -> V_192 ;
F_10 ( & V_13 -> V_191 ) ;
return V_190 ;
}
static void F_83 ( struct V_12 * V_13 , T_1 V_19 , T_1 V_193 , T_2 V_194 ,
void * V_195 )
{
struct V_52 * V_56 = F_92 ( V_13 , V_193 , V_19 , V_194 , V_195 ) ;
T_1 V_110 ;
F_23 ( L_8 , V_193 ) ;
if ( ! V_56 )
return;
if ( F_93 ( V_13 -> V_8 -> V_196 ) ||
V_13 -> V_8 -> type == V_2 )
V_110 = V_197 ;
else
V_110 = V_198 ;
F_35 ( V_56 ) -> V_199 = V_200 ;
V_56 -> V_201 = V_202 ;
F_94 ( V_13 -> V_203 , V_56 , V_110 ) ;
}
static bool F_95 ( struct V_11 * V_23 )
{
return V_23 -> V_204 != V_205 &&
V_23 -> V_204 != V_206 ;
}
static void F_96 ( struct V_11 * V_23 , struct V_52 * V_56 )
{
struct V_7 * V_8 = V_23 -> V_13 -> V_8 ;
T_2 V_110 ;
F_23 ( L_9 , V_23 , V_56 , V_56 -> V_194 ,
V_56 -> V_201 ) ;
if ( V_23 -> V_207 && ! F_95 ( V_23 ) ) {
if ( V_23 -> V_146 )
F_94 ( V_23 -> V_146 , V_56 , V_208 ) ;
else
F_97 ( V_56 ) ;
return;
}
if ( V_8 -> type == V_2 ||
( ! F_70 ( V_209 , & V_23 -> V_110 ) &&
F_93 ( V_8 -> V_196 ) ) )
V_110 = V_197 ;
else
V_110 = V_198 ;
F_35 ( V_56 ) -> V_199 = F_70 ( V_109 , & V_23 -> V_110 ) ;
F_94 ( V_23 -> V_13 -> V_203 , V_56 , V_110 ) ;
}
static void F_98 ( T_2 V_210 , struct V_211 * V_212 )
{
V_212 -> V_213 = ( V_210 & V_214 ) >> V_215 ;
V_212 -> V_216 = ( V_210 & V_217 ) >> V_218 ;
if ( V_210 & V_219 ) {
V_212 -> V_220 = 1 ;
V_212 -> V_221 = ( V_210 & V_222 ) >> V_223 ;
V_212 -> V_224 = ( V_210 & V_225 ) >> V_226 ;
V_212 -> V_227 = 0 ;
V_212 -> V_58 = 0 ;
} else {
V_212 -> V_220 = 0 ;
V_212 -> V_227 = ( V_210 & V_228 ) >> V_229 ;
V_212 -> V_58 = ( V_210 & V_230 ) >> V_231 ;
V_212 -> V_221 = 0 ;
V_212 -> V_224 = 0 ;
}
}
static void F_99 ( T_8 V_232 , struct V_211 * V_212 )
{
V_212 -> V_213 = ( V_232 & V_233 ) >> V_234 ;
V_212 -> V_216 = ( V_232 & V_235 ) >> V_236 ;
if ( V_232 & V_237 ) {
V_212 -> V_220 = 1 ;
V_212 -> V_221 = ( V_232 & V_238 ) >> V_239 ;
V_212 -> V_224 = ( V_232 & V_240 ) >> V_241 ;
V_212 -> V_227 = 0 ;
V_212 -> V_58 = 0 ;
} else {
V_212 -> V_220 = 0 ;
V_212 -> V_227 = ( V_232 & V_242 ) >> V_243 ;
V_212 -> V_58 = ( V_232 & V_244 ) >> V_245 ;
V_212 -> V_221 = 0 ;
V_212 -> V_224 = 0 ;
}
}
static inline void F_100 ( struct V_11 * V_23 ,
struct V_52 * V_56 )
{
if ( F_70 ( V_246 , & V_23 -> V_110 ) ) {
F_99 ( F_101 ( V_56 -> V_195 ) ,
& F_35 ( V_56 ) -> V_57 ) ;
F_102 ( V_56 , V_247 ) ;
} else {
F_98 ( F_103 ( V_56 -> V_195 ) ,
& F_35 ( V_56 ) -> V_57 ) ;
F_102 ( V_56 , V_248 ) ;
}
}
static T_8 F_104 ( struct V_211 * V_212 )
{
T_8 V_249 ;
V_249 = V_212 -> V_213 << V_234 ;
V_249 |= V_212 -> V_216 << V_236 ;
if ( V_212 -> V_220 ) {
V_249 |= V_212 -> V_221 << V_239 ;
V_249 |= V_212 -> V_224 << V_241 ;
V_249 |= V_237 ;
} else {
V_249 |= V_212 -> V_227 << V_243 ;
V_249 |= V_212 -> V_58 << V_245 ;
}
return V_249 ;
}
static T_2 F_105 ( struct V_211 * V_212 )
{
T_2 V_249 ;
V_249 = V_212 -> V_213 << V_215 ;
V_249 |= V_212 -> V_216 << V_218 ;
if ( V_212 -> V_220 ) {
V_249 |= V_212 -> V_221 << V_223 ;
V_249 |= V_212 -> V_224 << V_226 ;
V_249 |= V_219 ;
} else {
V_249 |= V_212 -> V_227 << V_229 ;
V_249 |= V_212 -> V_58 << V_231 ;
}
return V_249 ;
}
static inline void F_106 ( struct V_11 * V_23 ,
struct V_211 * V_212 ,
struct V_52 * V_56 )
{
if ( F_70 ( V_246 , & V_23 -> V_110 ) ) {
F_107 ( F_104 ( V_212 ) ,
V_56 -> V_195 + V_250 ) ;
} else {
F_108 ( F_105 ( V_212 ) ,
V_56 -> V_195 + V_250 ) ;
}
}
static inline unsigned int F_109 ( struct V_11 * V_23 )
{
if ( F_70 ( V_246 , & V_23 -> V_110 ) )
return V_251 ;
else
return V_252 ;
}
static struct V_52 * F_110 ( struct V_11 * V_23 ,
T_8 V_212 )
{
struct V_52 * V_56 ;
struct V_253 * V_254 ;
int V_255 = F_109 ( V_23 ) ;
if ( V_23 -> V_94 == V_95 )
V_255 += V_256 ;
V_56 = F_111 ( V_255 , V_65 ) ;
if ( ! V_56 )
return F_112 ( - V_66 ) ;
V_254 = (struct V_253 * ) F_113 ( V_56 , V_250 ) ;
V_254 -> V_194 = F_18 ( V_255 - V_250 ) ;
V_254 -> V_14 = F_18 ( V_23 -> V_16 ) ;
if ( F_70 ( V_246 , & V_23 -> V_110 ) )
F_107 ( V_212 , F_113 ( V_56 , V_247 ) ) ;
else
F_108 ( V_212 , F_113 ( V_56 , V_248 ) ) ;
if ( V_23 -> V_94 == V_95 ) {
T_2 V_94 = F_114 ( 0 , ( T_1 * ) V_56 -> V_195 , V_56 -> V_194 ) ;
F_108 ( V_94 , F_113 ( V_56 , V_256 ) ) ;
}
V_56 -> V_201 = V_202 ;
return V_56 ;
}
static void F_115 ( struct V_11 * V_23 ,
struct V_211 * V_212 )
{
struct V_52 * V_56 ;
T_8 V_257 ;
F_23 ( L_10 , V_23 , V_212 ) ;
if ( ! V_212 -> V_220 )
return;
if ( F_95 ( V_23 ) )
return;
if ( F_116 ( V_258 , & V_23 -> V_259 ) &&
! V_212 -> V_221 )
V_212 -> V_216 = 1 ;
if ( V_212 -> V_224 == V_260 )
F_117 ( V_261 , & V_23 -> V_259 ) ;
else if ( V_212 -> V_224 == V_262 )
F_57 ( V_261 , & V_23 -> V_259 ) ;
if ( V_212 -> V_224 != V_263 ) {
V_23 -> V_264 = V_212 -> V_213 ;
F_79 ( V_23 ) ;
}
F_23 ( L_11 , V_212 -> V_213 ,
V_212 -> V_216 , V_212 -> V_221 , V_212 -> V_224 ) ;
if ( F_70 ( V_246 , & V_23 -> V_110 ) )
V_257 = F_104 ( V_212 ) ;
else
V_257 = F_105 ( V_212 ) ;
V_56 = F_110 ( V_23 , V_257 ) ;
if ( ! F_118 ( V_56 ) )
F_96 ( V_23 , V_56 ) ;
}
static void F_119 ( struct V_11 * V_23 , bool V_221 )
{
struct V_211 V_212 ;
F_23 ( L_12 , V_23 , V_221 ) ;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
V_212 . V_220 = 1 ;
V_212 . V_221 = V_221 ;
if ( F_70 ( V_265 , & V_23 -> V_259 ) )
V_212 . V_224 = V_262 ;
else
V_212 . V_224 = V_260 ;
V_212 . V_213 = V_23 -> V_266 ;
F_115 ( V_23 , & V_212 ) ;
}
static inline int F_120 ( struct V_11 * V_23 )
{
if ( V_23 -> V_39 != V_123 )
return true ;
return ! F_70 ( V_267 , & V_23 -> V_92 ) ;
}
static bool F_121 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_268 * V_196 ;
bool V_269 = false ;
if ( ! ( V_13 -> V_270 & V_271 ) )
return false ;
if ( ! ( V_13 -> V_272 & V_271 ) )
return false ;
F_122 ( & V_273 ) ;
F_5 (hdev, &hci_dev_list, list) {
if ( V_196 -> V_274 != V_275 &&
F_70 ( V_276 , & V_196 -> V_110 ) ) {
V_269 = true ;
break;
}
}
F_123 ( & V_273 ) ;
if ( V_23 -> V_277 == V_278 )
return V_269 ;
return false ;
}
static bool F_124 ( struct V_11 * V_23 )
{
return true ;
}
void F_125 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_279 V_280 ;
V_280 . V_17 = F_18 ( V_23 -> V_17 ) ;
V_280 . V_20 = V_23 -> V_20 ;
V_23 -> V_19 = F_91 ( V_13 ) ;
F_57 ( V_267 , & V_23 -> V_92 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_281 , sizeof( V_280 ) , & V_280 ) ;
}
static void F_126 ( struct V_11 * V_23 , T_1 V_282 )
{
struct V_283 V_280 ;
V_280 . V_17 = F_18 ( V_23 -> V_17 ) ;
V_280 . V_20 = V_23 -> V_20 ;
V_280 . V_282 = V_282 ;
V_23 -> V_19 = F_91 ( V_23 -> V_13 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_284 ,
sizeof( V_280 ) , & V_280 ) ;
}
static void F_127 ( struct V_11 * V_23 )
{
struct V_52 * V_56 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_148 != V_151 )
return;
F_32 ( V_23 ) ;
F_78 ( V_23 ) ;
F_79 ( V_23 ) ;
V_23 -> V_285 = 0 ;
F_34 (&chan->tx_q, skb) {
if ( F_35 ( V_56 ) -> V_57 . V_286 )
F_35 ( V_56 ) -> V_57 . V_286 = 1 ;
else
break;
}
V_23 -> V_287 = V_23 -> V_266 ;
F_117 ( V_288 , & V_23 -> V_259 ) ;
F_117 ( V_289 , & V_23 -> V_259 ) ;
F_43 ( & V_23 -> V_154 ) ;
F_43 ( & V_23 -> V_153 ) ;
F_77 ( & V_23 -> V_152 ) ;
V_23 -> V_290 = V_291 ;
V_23 -> V_292 = V_293 ;
F_57 ( V_294 , & V_23 -> V_259 ) ;
}
static void F_128 ( struct V_11 * V_23 )
{
T_1 V_295 = V_23 -> V_295 ;
F_23 ( L_3 , V_23 ) ;
V_23 -> V_204 = V_205 ;
V_23 -> V_295 = V_296 ;
if ( V_23 -> V_148 != V_151 )
return;
switch ( V_295 ) {
case V_297 :
F_129 ( V_23 , NULL , NULL , V_298 ) ;
V_23 -> V_292 = V_299 ;
break;
case V_300 :
V_23 -> V_292 = V_301 ;
break;
}
}
static void F_130 ( struct V_11 * V_23 )
{
if ( V_23 -> V_45 == V_75 )
return;
V_23 -> V_92 = 0 ;
F_74 ( V_23 ) ;
if ( V_23 -> V_148 == V_150 && ! V_23 -> V_114 )
V_23 -> V_46 -> V_302 ( V_23 ) ;
V_23 -> V_45 = V_75 ;
V_23 -> V_46 -> V_303 ( V_23 ) ;
}
static void F_131 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_304 V_280 ;
if ( F_132 ( V_305 , & V_23 -> V_110 ) )
return;
V_280 . V_20 = V_23 -> V_20 ;
V_280 . V_17 = F_18 ( V_23 -> V_17 ) ;
V_280 . V_165 = F_18 ( V_23 -> V_118 ) ;
V_280 . V_117 = F_18 ( V_23 -> V_117 ) ;
V_280 . V_166 = F_18 ( V_23 -> V_115 ) ;
V_23 -> V_19 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_306 ,
sizeof( V_280 ) , & V_280 ) ;
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
struct V_307 V_280 ;
if ( V_13 -> V_308 & V_309 )
return;
V_280 . type = F_18 ( V_310 ) ;
V_13 -> V_308 |= V_309 ;
V_13 -> V_311 = F_91 ( V_13 ) ;
F_137 ( & V_13 -> V_312 , V_313 ) ;
F_83 ( V_13 , V_13 -> V_311 , V_314 ,
sizeof( V_280 ) , & V_280 ) ;
}
static void F_138 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
if ( V_13 -> V_8 -> type == V_2 ) {
F_133 ( V_23 ) ;
return;
}
if ( ! ( V_13 -> V_308 & V_309 ) ) {
F_136 ( V_13 ) ;
return;
}
if ( ! ( V_13 -> V_308 & V_315 ) )
return;
if ( F_88 ( V_23 , true ) &&
F_120 ( V_23 ) )
F_134 ( V_23 ) ;
}
static inline int F_139 ( T_7 V_148 , T_9 V_316 )
{
T_8 V_317 = V_318 ;
if ( ! V_319 )
V_317 |= V_320 | V_321 ;
switch ( V_148 ) {
case V_151 :
return V_320 & V_316 & V_317 ;
case V_155 :
return V_321 & V_316 & V_317 ;
default:
return 0x00 ;
}
}
static void F_86 ( struct V_11 * V_23 , int V_24 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_322 V_280 ;
if ( ! V_13 )
return;
if ( V_23 -> V_148 == V_151 && V_23 -> V_45 == V_75 ) {
F_32 ( V_23 ) ;
F_78 ( V_23 ) ;
F_79 ( V_23 ) ;
}
if ( V_23 -> V_17 == V_323 ) {
F_22 ( V_23 , V_164 ) ;
return;
}
V_280 . V_16 = F_18 ( V_23 -> V_16 ) ;
V_280 . V_17 = F_18 ( V_23 -> V_17 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_324 ,
sizeof( V_280 ) , & V_280 ) ;
F_25 ( V_23 , V_164 , V_24 ) ;
}
static void F_140 ( struct V_12 * V_13 )
{
struct V_11 * V_23 , * V_325 ;
F_23 ( L_14 , V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_141 (chan, tmp, &conn->chan_l, list) {
F_9 ( V_23 ) ;
if ( V_23 -> V_39 != V_123 ) {
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
if ( ! F_139 ( V_23 -> V_148 , V_13 -> V_316 )
&& F_70 ( V_326 ,
& V_23 -> V_92 ) ) {
F_47 ( V_23 , V_327 ) ;
F_48 ( V_23 ) ;
continue;
}
F_134 ( V_23 ) ;
} else if ( V_23 -> V_45 == V_175 ) {
struct V_168 V_159 ;
char V_328 [ 128 ] ;
V_159 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_159 . V_16 = F_18 ( V_23 -> V_17 ) ;
if ( F_88 ( V_23 , false ) ) {
if ( F_70 ( V_161 , & V_23 -> V_110 ) ) {
V_159 . V_160 = F_18 ( V_329 ) ;
V_159 . V_170 = F_18 ( V_330 ) ;
V_23 -> V_46 -> V_331 ( V_23 ) ;
} else {
F_22 ( V_23 , V_76 ) ;
V_159 . V_160 = F_18 ( V_332 ) ;
V_159 . V_170 = F_18 ( V_171 ) ;
}
} else {
V_159 . V_160 = F_18 ( V_329 ) ;
V_159 . V_170 = F_18 ( V_333 ) ;
}
F_83 ( V_13 , V_23 -> V_19 , V_172 ,
sizeof( V_159 ) , & V_159 ) ;
if ( F_70 ( V_334 , & V_23 -> V_92 ) ||
V_159 . V_160 != V_332 ) {
F_48 ( V_23 ) ;
continue;
}
F_57 ( V_334 , & V_23 -> V_92 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_335 ,
F_142 ( V_23 , V_328 ) , V_328 ) ;
V_23 -> V_336 ++ ;
}
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static void F_143 ( struct V_12 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_268 * V_196 = V_8 -> V_196 ;
F_23 ( L_15 , V_196 -> V_337 , V_13 ) ;
if ( V_8 -> V_338 )
F_89 ( V_8 , V_8 -> V_339 ) ;
if ( V_8 -> V_340 == V_341 &&
( V_8 -> V_342 < V_8 -> V_343 ||
V_8 -> V_342 > V_8 -> V_344 ) ) {
struct V_345 V_280 ;
V_280 . V_346 = F_18 ( V_8 -> V_343 ) ;
V_280 . V_347 = F_18 ( V_8 -> V_344 ) ;
V_280 . V_348 = F_18 ( V_8 -> V_349 ) ;
V_280 . V_350 = F_18 ( V_8 -> V_351 ) ;
F_83 ( V_13 , F_91 ( V_13 ) ,
V_352 , sizeof( V_280 ) , & V_280 ) ;
}
}
static void F_144 ( struct V_12 * V_13 )
{
struct V_11 * V_23 ;
struct V_7 * V_8 = V_13 -> V_8 ;
F_23 ( L_14 , V_13 ) ;
if ( V_8 -> type == V_124 )
F_136 ( V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
F_9 ( V_23 ) ;
if ( V_23 -> V_17 == V_323 ) {
F_48 ( V_23 ) ;
continue;
}
if ( V_8 -> type == V_2 ) {
F_133 ( V_23 ) ;
} else if ( V_23 -> V_39 != V_123 ) {
if ( V_13 -> V_308 & V_315 )
F_130 ( V_23 ) ;
} else if ( V_23 -> V_45 == V_78 ) {
F_138 ( V_23 ) ;
}
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
if ( V_8 -> type == V_2 )
F_143 ( V_13 ) ;
F_145 ( V_8 -> V_196 -> V_353 , & V_13 -> V_354 ) ;
}
static void F_146 ( struct V_12 * V_13 , int V_24 )
{
struct V_11 * V_23 ;
F_23 ( L_14 , V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
if ( F_70 ( V_355 , & V_23 -> V_110 ) )
F_26 ( V_23 , V_24 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static void F_147 ( struct V_71 * V_72 )
{
struct V_12 * V_13 = F_46 ( V_72 , struct V_12 ,
V_312 . V_72 ) ;
V_13 -> V_308 |= V_315 ;
V_13 -> V_311 = 0 ;
F_140 ( V_13 ) ;
}
int F_148 ( struct V_12 * V_13 , struct V_356 * V_357 )
{
struct V_268 * V_196 = V_13 -> V_8 -> V_196 ;
int V_358 ;
F_149 ( V_196 ) ;
if ( ! F_150 ( & V_357 -> V_64 ) ) {
V_358 = - V_36 ;
goto V_359;
}
if ( ! V_13 -> V_203 ) {
V_358 = - V_360 ;
goto V_359;
}
V_358 = V_357 -> V_361 ( V_13 , V_357 ) ;
if ( V_358 )
goto V_359;
F_54 ( & V_357 -> V_64 , & V_13 -> V_362 ) ;
V_358 = 0 ;
V_359:
F_151 ( V_196 ) ;
return V_358 ;
}
void F_152 ( struct V_12 * V_13 , struct V_356 * V_357 )
{
struct V_268 * V_196 = V_13 -> V_8 -> V_196 ;
F_149 ( V_196 ) ;
if ( F_150 ( & V_357 -> V_64 ) )
goto V_359;
F_153 ( & V_357 -> V_64 ) ;
V_357 -> remove ( V_13 , V_357 ) ;
V_359:
F_151 ( V_196 ) ;
}
static void F_154 ( struct V_12 * V_13 )
{
struct V_356 * V_357 ;
while ( ! F_150 ( & V_13 -> V_362 ) ) {
V_357 = F_155 ( & V_13 -> V_362 , struct V_356 , V_64 ) ;
F_153 ( & V_357 -> V_64 ) ;
V_357 -> remove ( V_13 , V_357 ) ;
}
}
static void F_156 ( struct V_7 * V_8 , int V_24 )
{
struct V_12 * V_13 = V_8 -> V_363 ;
struct V_11 * V_23 , * V_364 ;
if ( ! V_13 )
return;
F_23 ( L_16 , V_8 , V_13 , V_24 ) ;
F_97 ( V_13 -> V_365 ) ;
F_77 ( & V_13 -> V_366 ) ;
if ( F_157 ( & V_13 -> V_354 ) )
F_158 ( & V_13 -> V_354 ) ;
if ( F_157 ( & V_13 -> V_156 ) )
F_158 ( & V_13 -> V_156 ) ;
F_154 ( V_13 ) ;
V_8 -> V_367 = 0 ;
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
F_159 ( V_13 -> V_203 ) ;
if ( V_13 -> V_308 & V_309 )
F_160 ( & V_13 -> V_312 ) ;
V_8 -> V_363 = NULL ;
V_13 -> V_203 = NULL ;
F_161 ( V_13 ) ;
}
static void F_162 ( struct V_90 * V_368 )
{
struct V_12 * V_13 = F_46 ( V_368 , struct V_12 , V_368 ) ;
F_163 ( V_13 -> V_8 ) ;
F_40 ( V_13 ) ;
}
struct V_12 * F_164 ( struct V_12 * V_13 )
{
F_62 ( & V_13 -> V_368 ) ;
return V_13 ;
}
void F_161 ( struct V_12 * V_13 )
{
F_63 ( & V_13 -> V_368 , F_162 ) ;
}
static struct V_11 * F_165 ( int V_45 , T_3 V_20 ,
T_4 * V_21 ,
T_4 * V_157 ,
T_1 V_1 )
{
struct V_11 * V_15 , * V_369 = NULL ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
if ( V_45 && V_15 -> V_45 != V_45 )
continue;
if ( V_1 == V_124 && V_15 -> V_9 != V_6 )
continue;
if ( V_1 == V_2 && V_15 -> V_9 == V_6 )
continue;
if ( V_15 -> V_20 == V_20 ) {
int V_370 , V_371 ;
int V_372 , V_373 ;
V_370 = ! F_15 ( & V_15 -> V_21 , V_21 ) ;
V_371 = ! F_15 ( & V_15 -> V_157 , V_157 ) ;
if ( V_370 && V_371 ) {
F_60 ( V_15 ) ;
F_123 ( & V_25 ) ;
return V_15 ;
}
V_372 = ! F_15 ( & V_15 -> V_21 , V_374 ) ;
V_373 = ! F_15 ( & V_15 -> V_157 , V_374 ) ;
if ( ( V_370 && V_373 ) || ( V_372 && V_371 ) ||
( V_372 && V_373 ) )
V_369 = V_15 ;
}
}
if ( V_369 )
F_60 ( V_369 ) ;
F_123 ( & V_25 ) ;
return V_369 ;
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
F_129 ( V_23 , NULL , NULL , V_375 ) ;
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
F_129 ( V_23 , NULL , NULL , V_376 ) ;
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
}
static void F_168 ( struct V_11 * V_23 ,
struct V_53 * V_377 )
{
struct V_52 * V_56 ;
struct V_211 * V_212 ;
F_23 ( L_17 , V_23 , V_377 ) ;
if ( F_95 ( V_23 ) )
return;
F_169 ( V_377 , & V_23 -> V_120 ) ;
while ( ! F_170 ( & V_23 -> V_120 ) ) {
V_56 = F_171 ( & V_23 -> V_120 ) ;
F_35 ( V_56 ) -> V_57 . V_286 = 1 ;
V_212 = & F_35 ( V_56 ) -> V_57 ;
V_212 -> V_213 = 0 ;
V_212 -> V_58 = V_23 -> V_378 ;
F_106 ( V_23 , V_212 , V_56 ) ;
if ( V_23 -> V_94 == V_95 ) {
T_2 V_94 = F_114 ( 0 , ( T_1 * ) V_56 -> V_195 , V_56 -> V_194 ) ;
F_108 ( V_94 , F_113 ( V_56 , V_256 ) ) ;
}
F_96 ( V_23 , V_56 ) ;
F_23 ( L_18 , V_212 -> V_58 ) ;
V_23 -> V_378 = F_172 ( V_23 , V_23 -> V_378 ) ;
V_23 -> V_379 ++ ;
}
}
static int F_173 ( struct V_11 * V_23 )
{
struct V_52 * V_56 , * V_380 ;
struct V_211 * V_212 ;
int V_381 = 0 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_45 != V_75 )
return - V_382 ;
if ( F_70 ( V_294 , & V_23 -> V_259 ) )
return 0 ;
if ( F_95 ( V_23 ) )
return 0 ;
while ( V_23 -> V_383 &&
V_23 -> V_384 < V_23 -> V_102 &&
V_23 -> V_290 == V_291 ) {
V_56 = V_23 -> V_383 ;
F_35 ( V_56 ) -> V_57 . V_286 = 1 ;
V_212 = & F_35 ( V_56 ) -> V_57 ;
if ( F_116 ( V_258 , & V_23 -> V_259 ) )
V_212 -> V_216 = 1 ;
V_212 -> V_213 = V_23 -> V_266 ;
V_23 -> V_264 = V_23 -> V_266 ;
V_212 -> V_58 = V_23 -> V_378 ;
F_106 ( V_23 , V_212 , V_56 ) ;
if ( V_23 -> V_94 == V_95 ) {
T_2 V_94 = F_114 ( 0 , ( T_1 * ) V_56 -> V_195 , V_56 -> V_194 ) ;
F_108 ( V_94 , F_113 ( V_56 , V_256 ) ) ;
}
V_380 = F_174 ( V_56 , V_65 ) ;
if ( ! V_380 )
break;
F_27 ( V_23 ) ;
V_23 -> V_378 = F_172 ( V_23 , V_23 -> V_378 ) ;
V_23 -> V_384 ++ ;
V_23 -> V_379 ++ ;
V_381 ++ ;
if ( F_175 ( & V_23 -> V_120 , V_56 ) )
V_23 -> V_383 = NULL ;
else
V_23 -> V_383 = F_176 ( & V_23 -> V_120 , V_56 ) ;
F_96 ( V_23 , V_380 ) ;
F_23 ( L_18 , V_212 -> V_58 ) ;
}
F_23 ( L_19 , V_381 ,
V_23 -> V_384 , F_177 ( & V_23 -> V_120 ) ) ;
return V_381 ;
}
static void F_178 ( struct V_11 * V_23 )
{
struct V_211 V_212 ;
struct V_52 * V_56 ;
struct V_52 * V_380 ;
T_2 V_55 ;
F_23 ( L_3 , V_23 ) ;
if ( F_70 ( V_294 , & V_23 -> V_259 ) )
return;
if ( F_95 ( V_23 ) )
return;
while ( V_23 -> V_154 . V_54 != V_68 ) {
V_55 = F_42 ( & V_23 -> V_154 ) ;
V_56 = F_33 ( & V_23 -> V_120 , V_55 ) ;
if ( ! V_56 ) {
F_23 ( L_20 ,
V_55 ) ;
continue;
}
F_35 ( V_56 ) -> V_57 . V_286 ++ ;
V_212 = F_35 ( V_56 ) -> V_57 ;
if ( V_23 -> V_96 != 0 &&
F_35 ( V_56 ) -> V_57 . V_286 > V_23 -> V_96 ) {
F_23 ( L_21 , V_23 -> V_96 ) ;
F_86 ( V_23 , V_327 ) ;
F_43 ( & V_23 -> V_154 ) ;
break;
}
V_212 . V_213 = V_23 -> V_266 ;
if ( F_116 ( V_258 , & V_23 -> V_259 ) )
V_212 . V_216 = 1 ;
else
V_212 . V_216 = 0 ;
if ( F_179 ( V_56 ) ) {
V_380 = F_180 ( V_56 , V_65 ) ;
} else {
V_380 = F_174 ( V_56 , V_65 ) ;
}
if ( ! V_380 ) {
F_43 ( & V_23 -> V_154 ) ;
break;
}
if ( F_70 ( V_246 , & V_23 -> V_110 ) ) {
F_107 ( F_104 ( & V_212 ) ,
V_380 -> V_195 + V_250 ) ;
} else {
F_108 ( F_105 ( & V_212 ) ,
V_380 -> V_195 + V_250 ) ;
}
if ( V_23 -> V_94 == V_95 ) {
T_2 V_94 = F_114 ( 0 , ( T_1 * ) V_380 -> V_195 ,
V_380 -> V_194 - V_256 ) ;
F_108 ( V_94 , F_181 ( V_380 ) -
V_256 ) ;
}
F_96 ( V_23 , V_380 ) ;
F_23 ( L_22 , V_212 . V_58 ) ;
V_23 -> V_264 = V_23 -> V_266 ;
}
}
static void F_182 ( struct V_11 * V_23 ,
struct V_211 * V_212 )
{
F_23 ( L_10 , V_23 , V_212 ) ;
F_44 ( & V_23 -> V_154 , V_212 -> V_213 ) ;
F_178 ( V_23 ) ;
}
static void F_183 ( struct V_11 * V_23 ,
struct V_211 * V_212 )
{
struct V_52 * V_56 ;
F_23 ( L_10 , V_23 , V_212 ) ;
if ( V_212 -> V_221 )
F_57 ( V_258 , & V_23 -> V_259 ) ;
F_43 ( & V_23 -> V_154 ) ;
if ( F_70 ( V_294 , & V_23 -> V_259 ) )
return;
if ( V_23 -> V_384 ) {
F_34 (&chan->tx_q, skb) {
if ( F_35 ( V_56 ) -> V_57 . V_58 == V_212 -> V_213 ||
V_56 == V_23 -> V_383 )
break;
}
F_184 (&chan->tx_q, skb) {
if ( V_56 == V_23 -> V_383 )
break;
F_44 ( & V_23 -> V_154 ,
F_35 ( V_56 ) -> V_57 . V_58 ) ;
}
F_178 ( V_23 ) ;
}
}
static void F_185 ( struct V_11 * V_23 )
{
struct V_211 V_212 ;
T_2 V_385 = F_186 ( V_23 , V_23 -> V_266 ,
V_23 -> V_264 ) ;
int V_386 ;
F_23 ( L_23 ,
V_23 , V_23 -> V_264 , V_23 -> V_266 ) ;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
V_212 . V_220 = 1 ;
if ( F_70 ( V_265 , & V_23 -> V_259 ) &&
V_23 -> V_292 == V_387 ) {
F_79 ( V_23 ) ;
V_212 . V_224 = V_262 ;
V_212 . V_213 = V_23 -> V_266 ;
F_115 ( V_23 , & V_212 ) ;
} else {
if ( ! F_70 ( V_294 , & V_23 -> V_259 ) ) {
F_173 ( V_23 ) ;
if ( V_23 -> V_266 == V_23 -> V_264 )
V_385 = 0 ;
}
V_386 = V_23 -> V_103 ;
V_386 += V_386 << 1 ;
V_386 >>= 2 ;
F_23 ( L_24 , V_385 ,
V_386 ) ;
if ( V_385 >= V_386 ) {
F_79 ( V_23 ) ;
V_212 . V_224 = V_260 ;
V_212 . V_213 = V_23 -> V_266 ;
F_115 ( V_23 , & V_212 ) ;
V_385 = 0 ;
}
if ( V_385 )
F_187 ( V_23 ) ;
}
}
static inline int F_188 ( struct V_11 * V_23 ,
struct V_388 * V_389 , int V_194 ,
int V_390 , struct V_52 * V_56 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_52 * * V_391 ;
int V_381 = 0 ;
if ( F_189 ( F_113 ( V_56 , V_390 ) , V_390 , & V_389 -> V_392 ) != V_390 )
return - V_393 ;
V_381 += V_390 ;
V_194 -= V_390 ;
V_391 = & F_190 ( V_56 ) -> V_394 ;
while ( V_194 ) {
struct V_52 * V_325 ;
V_390 = F_66 (unsigned int, conn->mtu, len) ;
V_325 = V_23 -> V_46 -> V_395 ( V_23 , 0 , V_390 ,
V_389 -> V_396 & V_397 ) ;
if ( F_118 ( V_325 ) )
return F_191 ( V_325 ) ;
* V_391 = V_325 ;
if ( F_189 ( F_113 ( * V_391 , V_390 ) , V_390 ,
& V_389 -> V_392 ) != V_390 )
return - V_393 ;
V_381 += V_390 ;
V_194 -= V_390 ;
V_56 -> V_194 += ( * V_391 ) -> V_194 ;
V_56 -> V_398 += ( * V_391 ) -> V_194 ;
V_391 = & ( * V_391 ) -> V_399 ;
}
return V_381 ;
}
static struct V_52 * F_192 ( struct V_11 * V_23 ,
struct V_388 * V_389 , T_6 V_194 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_52 * V_56 ;
int V_24 , V_390 , V_255 = V_250 + V_400 ;
struct V_253 * V_254 ;
F_23 ( L_25 , V_23 ,
F_69 ( V_23 -> V_20 ) , V_194 ) ;
V_390 = F_66 (unsigned int, (conn->mtu - hlen), len) ;
V_56 = V_23 -> V_46 -> V_395 ( V_23 , V_255 , V_390 ,
V_389 -> V_396 & V_397 ) ;
if ( F_118 ( V_56 ) )
return V_56 ;
V_254 = (struct V_253 * ) F_113 ( V_56 , V_250 ) ;
V_254 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_254 -> V_194 = F_18 ( V_194 + V_400 ) ;
F_193 ( V_23 -> V_20 , ( T_3 * ) F_113 ( V_56 , V_400 ) ) ;
V_24 = F_188 ( V_23 , V_389 , V_194 , V_390 , V_56 ) ;
if ( F_194 ( V_24 < 0 ) ) {
F_97 ( V_56 ) ;
return F_112 ( V_24 ) ;
}
return V_56 ;
}
static struct V_52 * F_195 ( struct V_11 * V_23 ,
struct V_388 * V_389 , T_6 V_194 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_52 * V_56 ;
int V_24 , V_390 ;
struct V_253 * V_254 ;
F_23 ( L_26 , V_23 , V_194 ) ;
V_390 = F_66 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_56 = V_23 -> V_46 -> V_395 ( V_23 , V_250 , V_390 ,
V_389 -> V_396 & V_397 ) ;
if ( F_118 ( V_56 ) )
return V_56 ;
V_254 = (struct V_253 * ) F_113 ( V_56 , V_250 ) ;
V_254 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_254 -> V_194 = F_18 ( V_194 ) ;
V_24 = F_188 ( V_23 , V_389 , V_194 , V_390 , V_56 ) ;
if ( F_194 ( V_24 < 0 ) ) {
F_97 ( V_56 ) ;
return F_112 ( V_24 ) ;
}
return V_56 ;
}
static struct V_52 * F_196 ( struct V_11 * V_23 ,
struct V_388 * V_389 , T_6 V_194 ,
T_2 V_401 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_52 * V_56 ;
int V_24 , V_390 , V_255 ;
struct V_253 * V_254 ;
F_23 ( L_26 , V_23 , V_194 ) ;
if ( ! V_13 )
return F_112 ( - V_382 ) ;
V_255 = F_109 ( V_23 ) ;
if ( V_401 )
V_255 += V_402 ;
if ( V_23 -> V_94 == V_95 )
V_255 += V_256 ;
V_390 = F_66 (unsigned int, (conn->mtu - hlen), len) ;
V_56 = V_23 -> V_46 -> V_395 ( V_23 , V_255 , V_390 ,
V_389 -> V_396 & V_397 ) ;
if ( F_118 ( V_56 ) )
return V_56 ;
V_254 = (struct V_253 * ) F_113 ( V_56 , V_250 ) ;
V_254 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_254 -> V_194 = F_18 ( V_194 + ( V_255 - V_250 ) ) ;
if ( F_70 ( V_246 , & V_23 -> V_110 ) )
F_107 ( 0 , F_113 ( V_56 , V_247 ) ) ;
else
F_108 ( 0 , F_113 ( V_56 , V_248 ) ) ;
if ( V_401 )
F_108 ( V_401 , F_113 ( V_56 , V_402 ) ) ;
V_24 = F_188 ( V_23 , V_389 , V_194 , V_390 , V_56 ) ;
if ( F_194 ( V_24 < 0 ) ) {
F_97 ( V_56 ) ;
return F_112 ( V_24 ) ;
}
F_35 ( V_56 ) -> V_57 . V_94 = V_23 -> V_94 ;
F_35 ( V_56 ) -> V_57 . V_286 = 0 ;
return V_56 ;
}
static int F_197 ( struct V_11 * V_23 ,
struct V_53 * V_403 ,
struct V_388 * V_389 , T_6 V_194 )
{
struct V_52 * V_56 ;
T_2 V_113 ;
T_6 V_404 ;
T_1 V_227 ;
F_23 ( L_27 , V_23 , V_389 , V_194 ) ;
V_404 = V_23 -> V_13 -> V_165 ;
if ( ! V_23 -> V_207 )
V_404 = F_66 ( T_6 , V_404 , V_405 ) ;
if ( V_23 -> V_94 )
V_404 -= V_256 ;
V_404 -= F_109 ( V_23 ) ;
V_404 = F_66 ( T_6 , V_404 , V_23 -> V_406 ) ;
if ( V_194 <= V_404 ) {
V_227 = V_407 ;
V_113 = 0 ;
V_404 = V_194 ;
} else {
V_227 = V_408 ;
V_113 = V_194 ;
}
while ( V_194 > 0 ) {
V_56 = F_196 ( V_23 , V_389 , V_404 , V_113 ) ;
if ( F_118 ( V_56 ) ) {
F_198 ( V_403 ) ;
return F_191 ( V_56 ) ;
}
F_35 ( V_56 ) -> V_57 . V_227 = V_227 ;
F_199 ( V_403 , V_56 ) ;
V_194 -= V_404 ;
if ( V_113 )
V_113 = 0 ;
if ( V_194 <= V_404 ) {
V_227 = V_409 ;
V_404 = V_194 ;
} else {
V_227 = V_410 ;
}
}
return 0 ;
}
static struct V_52 * F_200 ( struct V_11 * V_23 ,
struct V_388 * V_389 ,
T_6 V_194 , T_2 V_401 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct V_52 * V_56 ;
int V_24 , V_390 , V_255 ;
struct V_253 * V_254 ;
F_23 ( L_26 , V_23 , V_194 ) ;
if ( ! V_13 )
return F_112 ( - V_382 ) ;
V_255 = V_250 ;
if ( V_401 )
V_255 += V_402 ;
V_390 = F_66 (unsigned int, (conn->mtu - hlen), len) ;
V_56 = V_23 -> V_46 -> V_395 ( V_23 , V_255 , V_390 ,
V_389 -> V_396 & V_397 ) ;
if ( F_118 ( V_56 ) )
return V_56 ;
V_254 = (struct V_253 * ) F_113 ( V_56 , V_250 ) ;
V_254 -> V_14 = F_18 ( V_23 -> V_16 ) ;
V_254 -> V_194 = F_18 ( V_194 + ( V_255 - V_250 ) ) ;
if ( V_401 )
F_108 ( V_401 , F_113 ( V_56 , V_402 ) ) ;
V_24 = F_188 ( V_23 , V_389 , V_194 , V_390 , V_56 ) ;
if ( F_194 ( V_24 < 0 ) ) {
F_97 ( V_56 ) ;
return F_112 ( V_24 ) ;
}
return V_56 ;
}
static int F_201 ( struct V_11 * V_23 ,
struct V_53 * V_403 ,
struct V_388 * V_389 , T_6 V_194 )
{
struct V_52 * V_56 ;
T_6 V_404 ;
T_2 V_113 ;
F_23 ( L_27 , V_23 , V_389 , V_194 ) ;
V_113 = V_194 ;
V_404 = V_23 -> V_406 - V_402 ;
while ( V_194 > 0 ) {
if ( V_194 <= V_404 )
V_404 = V_194 ;
V_56 = F_200 ( V_23 , V_389 , V_404 , V_113 ) ;
if ( F_118 ( V_56 ) ) {
F_198 ( V_403 ) ;
return F_191 ( V_56 ) ;
}
F_199 ( V_403 , V_56 ) ;
V_194 -= V_404 ;
if ( V_113 ) {
V_113 = 0 ;
V_404 += V_402 ;
}
}
return 0 ;
}
int F_202 ( struct V_11 * V_23 , struct V_388 * V_389 , T_6 V_194 )
{
struct V_52 * V_56 ;
int V_24 ;
struct V_53 V_403 ;
if ( ! V_23 -> V_13 )
return - V_382 ;
if ( V_23 -> V_39 == V_125 ) {
V_56 = F_192 ( V_23 , V_389 , V_194 ) ;
if ( F_118 ( V_56 ) )
return F_191 ( V_56 ) ;
if ( V_23 -> V_45 != V_75 ) {
F_97 ( V_56 ) ;
return - V_382 ;
}
F_96 ( V_23 , V_56 ) ;
return V_194 ;
}
switch ( V_23 -> V_148 ) {
case V_150 :
if ( V_194 > V_23 -> V_37 )
return - V_411 ;
if ( ! V_23 -> V_114 )
return - V_412 ;
F_203 ( & V_403 ) ;
V_24 = F_201 ( V_23 , & V_403 , V_389 , V_194 ) ;
if ( V_23 -> V_45 != V_75 ) {
F_198 ( & V_403 ) ;
V_24 = - V_382 ;
}
if ( V_24 )
return V_24 ;
F_169 ( & V_403 , & V_23 -> V_120 ) ;
while ( V_23 -> V_114 && ! F_170 ( & V_23 -> V_120 ) ) {
F_96 ( V_23 , F_171 ( & V_23 -> V_120 ) ) ;
V_23 -> V_114 -- ;
}
if ( ! V_23 -> V_114 )
V_23 -> V_46 -> V_302 ( V_23 ) ;
V_24 = V_194 ;
break;
case V_149 :
if ( V_194 > V_23 -> V_37 )
return - V_411 ;
V_56 = F_195 ( V_23 , V_389 , V_194 ) ;
if ( F_118 ( V_56 ) )
return F_191 ( V_56 ) ;
if ( V_23 -> V_45 != V_75 ) {
F_97 ( V_56 ) ;
return - V_382 ;
}
F_96 ( V_23 , V_56 ) ;
V_24 = V_194 ;
break;
case V_151 :
case V_155 :
if ( V_194 > V_23 -> V_37 ) {
V_24 = - V_411 ;
break;
}
F_203 ( & V_403 ) ;
V_24 = F_197 ( V_23 , & V_403 , V_389 , V_194 ) ;
if ( V_23 -> V_45 != V_75 ) {
F_198 ( & V_403 ) ;
V_24 = - V_382 ;
}
if ( V_24 )
break;
if ( V_23 -> V_148 == V_151 )
F_129 ( V_23 , NULL , & V_403 , V_413 ) ;
else
F_168 ( V_23 , & V_403 ) ;
V_24 = V_194 ;
F_198 ( & V_403 ) ;
break;
default:
F_23 ( L_28 , V_23 -> V_148 ) ;
V_24 = - V_414 ;
}
return V_24 ;
}
static void F_204 ( struct V_11 * V_23 , T_2 V_58 )
{
struct V_211 V_212 ;
T_2 V_55 ;
F_23 ( L_29 , V_23 , V_58 ) ;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
V_212 . V_220 = 1 ;
V_212 . V_224 = V_263 ;
for ( V_55 = V_23 -> V_287 ; V_55 != V_58 ;
V_55 = F_172 ( V_23 , V_55 ) ) {
if ( ! F_33 ( & V_23 -> V_152 , V_55 ) ) {
V_212 . V_213 = V_55 ;
F_115 ( V_23 , & V_212 ) ;
F_44 ( & V_23 -> V_153 , V_55 ) ;
}
}
V_23 -> V_287 = F_172 ( V_23 , V_58 ) ;
}
static void F_205 ( struct V_11 * V_23 )
{
struct V_211 V_212 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_153 . V_69 == V_68 )
return;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
V_212 . V_220 = 1 ;
V_212 . V_224 = V_263 ;
V_212 . V_213 = V_23 -> V_153 . V_69 ;
F_115 ( V_23 , & V_212 ) ;
}
static void F_206 ( struct V_11 * V_23 , T_2 V_58 )
{
struct V_211 V_212 ;
T_2 V_415 ;
T_2 V_55 ;
F_23 ( L_29 , V_23 , V_58 ) ;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
V_212 . V_220 = 1 ;
V_212 . V_224 = V_263 ;
V_415 = V_23 -> V_153 . V_54 ;
do {
V_55 = F_42 ( & V_23 -> V_153 ) ;
if ( V_55 == V_58 || V_55 == V_68 )
break;
V_212 . V_213 = V_55 ;
F_115 ( V_23 , & V_212 ) ;
F_44 ( & V_23 -> V_153 , V_55 ) ;
} while ( V_23 -> V_153 . V_54 != V_415 );
}
static void F_207 ( struct V_11 * V_23 , T_2 V_213 )
{
struct V_52 * V_416 ;
T_2 V_417 ;
F_23 ( L_30 , V_23 , V_213 ) ;
if ( V_23 -> V_384 == 0 || V_213 == V_23 -> V_418 )
return;
F_23 ( L_31 ,
V_23 -> V_418 , V_23 -> V_384 ) ;
for ( V_417 = V_23 -> V_418 ; V_417 != V_213 ;
V_417 = F_172 ( V_23 , V_417 ) ) {
V_416 = F_33 ( & V_23 -> V_120 , V_417 ) ;
if ( V_416 ) {
F_208 ( V_416 , & V_23 -> V_120 ) ;
F_97 ( V_416 ) ;
V_23 -> V_384 -- ;
}
}
V_23 -> V_418 = V_213 ;
if ( V_23 -> V_384 == 0 )
F_32 ( V_23 ) ;
F_23 ( L_32 , V_23 -> V_384 ) ;
}
static void F_209 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
V_23 -> V_287 = V_23 -> V_266 ;
F_43 ( & V_23 -> V_153 ) ;
F_77 ( & V_23 -> V_152 ) ;
V_23 -> V_292 = V_387 ;
}
static void F_210 ( struct V_11 * V_23 ,
struct V_211 * V_212 ,
struct V_53 * V_377 , T_1 V_419 )
{
F_23 ( L_33 , V_23 , V_212 , V_377 ,
V_419 ) ;
switch ( V_419 ) {
case V_413 :
if ( V_23 -> V_383 == NULL )
V_23 -> V_383 = F_211 ( V_377 ) ;
F_169 ( V_377 , & V_23 -> V_120 ) ;
F_173 ( V_23 ) ;
break;
case V_420 :
F_23 ( L_34 ) ;
F_57 ( V_265 , & V_23 -> V_259 ) ;
if ( V_23 -> V_292 == V_421 ) {
F_209 ( V_23 ) ;
}
F_185 ( V_23 ) ;
break;
case V_422 :
F_23 ( L_35 ) ;
F_117 ( V_265 , & V_23 -> V_259 ) ;
if ( F_70 ( V_261 , & V_23 -> V_259 ) ) {
struct V_211 V_423 ;
memset ( & V_423 , 0 , sizeof( V_423 ) ) ;
V_423 . V_220 = 1 ;
V_423 . V_224 = V_260 ;
V_423 . V_221 = 1 ;
V_423 . V_213 = V_23 -> V_266 ;
F_115 ( V_23 , & V_423 ) ;
V_23 -> V_285 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_290 = V_424 ;
}
break;
case V_425 :
F_207 ( V_23 , V_212 -> V_213 ) ;
break;
case V_298 :
F_119 ( V_23 , 1 ) ;
V_23 -> V_285 = 1 ;
F_31 ( V_23 ) ;
F_79 ( V_23 ) ;
V_23 -> V_290 = V_424 ;
break;
case V_376 :
F_119 ( V_23 , 1 ) ;
V_23 -> V_285 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_290 = V_424 ;
break;
case V_426 :
break;
default:
break;
}
}
static void F_212 ( struct V_11 * V_23 ,
struct V_211 * V_212 ,
struct V_53 * V_377 , T_1 V_419 )
{
F_23 ( L_33 , V_23 , V_212 , V_377 ,
V_419 ) ;
switch ( V_419 ) {
case V_413 :
if ( V_23 -> V_383 == NULL )
V_23 -> V_383 = F_211 ( V_377 ) ;
F_169 ( V_377 , & V_23 -> V_120 ) ;
break;
case V_420 :
F_23 ( L_34 ) ;
F_57 ( V_265 , & V_23 -> V_259 ) ;
if ( V_23 -> V_292 == V_421 ) {
F_209 ( V_23 ) ;
}
F_185 ( V_23 ) ;
break;
case V_422 :
F_23 ( L_35 ) ;
F_117 ( V_265 , & V_23 -> V_259 ) ;
if ( F_70 ( V_261 , & V_23 -> V_259 ) ) {
struct V_211 V_423 ;
memset ( & V_423 , 0 , sizeof( V_423 ) ) ;
V_423 . V_220 = 1 ;
V_423 . V_224 = V_260 ;
V_423 . V_221 = 1 ;
V_423 . V_213 = V_23 -> V_266 ;
F_115 ( V_23 , & V_423 ) ;
V_23 -> V_285 = 1 ;
F_31 ( V_23 ) ;
V_23 -> V_290 = V_424 ;
}
break;
case V_425 :
F_207 ( V_23 , V_212 -> V_213 ) ;
case V_426 :
if ( V_212 && V_212 -> V_216 ) {
F_78 ( V_23 ) ;
if ( V_23 -> V_384 > 0 )
F_27 ( V_23 ) ;
V_23 -> V_285 = 0 ;
V_23 -> V_290 = V_291 ;
F_23 ( L_36 , V_23 -> V_290 ) ;
}
break;
case V_298 :
break;
case V_375 :
if ( V_23 -> V_96 == 0 || V_23 -> V_285 < V_23 -> V_96 ) {
F_119 ( V_23 , 1 ) ;
F_31 ( V_23 ) ;
V_23 -> V_285 ++ ;
} else {
F_86 ( V_23 , V_427 ) ;
}
break;
default:
break;
}
}
static void F_129 ( struct V_11 * V_23 , struct V_211 * V_212 ,
struct V_53 * V_377 , T_1 V_419 )
{
F_23 ( L_37 ,
V_23 , V_212 , V_377 , V_419 , V_23 -> V_290 ) ;
switch ( V_23 -> V_290 ) {
case V_291 :
F_210 ( V_23 , V_212 , V_377 , V_419 ) ;
break;
case V_424 :
F_212 ( V_23 , V_212 , V_377 , V_419 ) ;
break;
default:
break;
}
}
static void F_213 ( struct V_11 * V_23 ,
struct V_211 * V_212 )
{
F_23 ( L_10 , V_23 , V_212 ) ;
F_129 ( V_23 , V_212 , NULL , V_425 ) ;
}
static void F_214 ( struct V_11 * V_23 ,
struct V_211 * V_212 )
{
F_23 ( L_10 , V_23 , V_212 ) ;
F_129 ( V_23 , V_212 , NULL , V_426 ) ;
}
static void F_215 ( struct V_12 * V_13 , struct V_52 * V_56 )
{
struct V_52 * V_428 ;
struct V_11 * V_23 ;
F_23 ( L_14 , V_13 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
if ( V_23 -> V_39 != V_176 )
continue;
if ( F_35 ( V_56 ) -> V_57 . V_23 == V_23 )
continue;
V_428 = F_174 ( V_56 , V_65 ) ;
if ( ! V_428 )
continue;
if ( V_23 -> V_46 -> V_429 ( V_23 , V_428 ) )
F_97 ( V_428 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
static struct V_52 * F_92 ( struct V_12 * V_13 , T_1 V_193 ,
T_1 V_19 , T_2 V_430 , void * V_195 )
{
struct V_52 * V_56 , * * V_391 ;
struct V_431 * V_432 ;
struct V_253 * V_254 ;
int V_194 , V_390 ;
F_23 ( L_38 ,
V_13 , V_193 , V_19 , V_430 ) ;
if ( V_13 -> V_165 < V_250 + V_433 )
return NULL ;
V_194 = V_250 + V_433 + V_430 ;
V_390 = F_66 (unsigned int, conn->mtu, len) ;
V_56 = F_111 ( V_390 , V_65 ) ;
if ( ! V_56 )
return NULL ;
V_254 = (struct V_253 * ) F_113 ( V_56 , V_250 ) ;
V_254 -> V_194 = F_18 ( V_433 + V_430 ) ;
if ( V_13 -> V_8 -> type == V_2 )
V_254 -> V_14 = F_18 ( V_434 ) ;
else
V_254 -> V_14 = F_18 ( V_127 ) ;
V_432 = (struct V_431 * ) F_113 ( V_56 , V_433 ) ;
V_432 -> V_193 = V_193 ;
V_432 -> V_19 = V_19 ;
V_432 -> V_194 = F_18 ( V_430 ) ;
if ( V_430 ) {
V_390 -= V_250 + V_433 ;
memcpy ( F_113 ( V_56 , V_390 ) , V_195 , V_390 ) ;
V_195 += V_390 ;
}
V_194 -= V_56 -> V_194 ;
V_391 = & F_190 ( V_56 ) -> V_394 ;
while ( V_194 ) {
V_390 = F_66 (unsigned int, conn->mtu, len) ;
* V_391 = F_111 ( V_390 , V_65 ) ;
if ( ! * V_391 )
goto V_435;
memcpy ( F_113 ( * V_391 , V_390 ) , V_195 , V_390 ) ;
V_194 -= V_390 ;
V_195 += V_390 ;
V_391 = & ( * V_391 ) -> V_399 ;
}
return V_56 ;
V_435:
F_97 ( V_56 ) ;
return NULL ;
}
static inline int F_216 ( void * * V_436 , int * type , int * V_437 ,
unsigned long * V_438 )
{
struct V_439 * V_440 = * V_436 ;
int V_194 ;
V_194 = V_441 + V_440 -> V_194 ;
* V_436 += V_194 ;
* type = V_440 -> type ;
* V_437 = V_440 -> V_194 ;
switch ( V_440 -> V_194 ) {
case 1 :
* V_438 = * ( ( T_1 * ) V_440 -> V_438 ) ;
break;
case 2 :
* V_438 = F_103 ( V_440 -> V_438 ) ;
break;
case 4 :
* V_438 = F_101 ( V_440 -> V_438 ) ;
break;
default:
* V_438 = ( unsigned long ) V_440 -> V_438 ;
break;
}
F_23 ( L_39 , * type , V_440 -> V_194 , * V_438 ) ;
return V_194 ;
}
static void F_217 ( void * * V_436 , T_1 type , T_1 V_194 , unsigned long V_438 )
{
struct V_439 * V_440 = * V_436 ;
F_23 ( L_39 , type , V_194 , V_438 ) ;
V_440 -> type = type ;
V_440 -> V_194 = V_194 ;
switch ( V_194 ) {
case 1 :
* ( ( T_1 * ) V_440 -> V_438 ) = V_438 ;
break;
case 2 :
F_108 ( V_438 , V_440 -> V_438 ) ;
break;
case 4 :
F_107 ( V_438 , V_440 -> V_438 ) ;
break;
default:
memcpy ( V_440 -> V_438 , ( void * ) V_438 , V_194 ) ;
break;
}
* V_436 += V_441 + V_194 ;
}
static void F_218 ( void * * V_436 , struct V_11 * V_23 )
{
struct V_442 V_443 ;
switch ( V_23 -> V_148 ) {
case V_151 :
V_443 . V_190 = V_23 -> V_128 ;
V_443 . V_444 = V_23 -> V_130 ;
V_443 . V_445 = F_18 ( V_23 -> V_132 ) ;
V_443 . V_446 = F_219 ( V_23 -> V_134 ) ;
V_443 . V_447 = F_219 ( V_137 ) ;
V_443 . V_105 = F_219 ( V_139 ) ;
break;
case V_155 :
V_443 . V_190 = 1 ;
V_443 . V_444 = V_131 ;
V_443 . V_445 = F_18 ( V_23 -> V_132 ) ;
V_443 . V_446 = F_219 ( V_23 -> V_134 ) ;
V_443 . V_447 = 0 ;
V_443 . V_105 = 0 ;
break;
default:
return;
}
F_217 ( V_436 , V_448 , sizeof( V_443 ) ,
( unsigned long ) & V_443 ) ;
}
static void F_220 ( struct V_71 * V_72 )
{
struct V_11 * V_23 = F_46 ( V_72 , struct V_11 ,
V_449 . V_72 ) ;
T_2 V_385 ;
F_23 ( L_3 , V_23 ) ;
F_9 ( V_23 ) ;
V_385 = F_186 ( V_23 , V_23 -> V_266 ,
V_23 -> V_264 ) ;
if ( V_385 )
F_119 ( V_23 , 0 ) ;
F_48 ( V_23 ) ;
F_49 ( V_23 ) ;
}
int F_221 ( struct V_11 * V_23 )
{
int V_24 ;
V_23 -> V_378 = 0 ;
V_23 -> V_287 = 0 ;
V_23 -> V_418 = 0 ;
V_23 -> V_384 = 0 ;
V_23 -> V_266 = 0 ;
V_23 -> V_379 = 0 ;
V_23 -> V_264 = 0 ;
V_23 -> V_111 = NULL ;
V_23 -> V_112 = NULL ;
V_23 -> V_113 = 0 ;
F_67 ( & V_23 -> V_120 ) ;
V_23 -> V_450 = V_451 ;
V_23 -> V_452 = V_451 ;
V_23 -> V_204 = V_205 ;
V_23 -> V_295 = V_296 ;
if ( V_23 -> V_148 != V_151 )
return 0 ;
V_23 -> V_292 = V_387 ;
V_23 -> V_290 = V_291 ;
F_55 ( & V_23 -> V_50 , F_167 ) ;
F_55 ( & V_23 -> V_48 , F_166 ) ;
F_55 ( & V_23 -> V_449 , F_220 ) ;
F_67 ( & V_23 -> V_152 ) ;
V_24 = F_36 ( & V_23 -> V_153 , V_23 -> V_98 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_36 ( & V_23 -> V_154 , V_23 -> V_102 ) ;
if ( V_24 < 0 )
F_39 ( & V_23 -> V_153 ) ;
return V_24 ;
}
static inline T_7 F_222 ( T_7 V_148 , T_5 V_453 )
{
switch ( V_148 ) {
case V_155 :
case V_151 :
if ( F_139 ( V_148 , V_453 ) )
return V_148 ;
default:
return V_149 ;
}
}
static inline bool F_223 ( struct V_12 * V_13 )
{
return ( ( V_13 -> V_270 & V_271 ) &&
( V_13 -> V_316 & V_454 ) ) ;
}
static inline bool F_224 ( struct V_12 * V_13 )
{
return ( ( V_13 -> V_270 & V_271 ) &&
( V_13 -> V_316 & V_455 ) ) ;
}
static void F_225 ( struct V_11 * V_23 ,
struct V_456 * V_457 )
{
if ( V_23 -> V_450 != V_451 && V_23 -> V_207 ) {
T_10 V_458 = V_23 -> V_207 -> V_196 -> V_459 ;
V_458 = F_226 ( V_458 , 1000 ) ;
V_458 = 3 * V_458 + 500 ;
if ( V_458 > 0xffff )
V_458 = 0xffff ;
V_457 -> V_49 = F_18 ( ( T_2 ) V_458 ) ;
V_457 -> V_51 = V_457 -> V_49 ;
} else {
V_457 -> V_49 = F_18 ( V_107 ) ;
V_457 -> V_51 = F_18 ( V_108 ) ;
}
}
static inline void F_227 ( struct V_11 * V_23 )
{
if ( V_23 -> V_98 > V_99 &&
F_223 ( V_23 -> V_13 ) ) {
F_57 ( V_246 , & V_23 -> V_110 ) ;
V_23 -> V_100 = V_460 ;
} else {
V_23 -> V_98 = F_66 ( T_2 , V_23 -> V_98 ,
V_99 ) ;
V_23 -> V_100 = V_99 ;
}
V_23 -> V_103 = V_23 -> V_98 ;
}
static int F_142 ( struct V_11 * V_23 , void * V_195 )
{
struct V_461 * V_280 = V_195 ;
struct V_456 V_457 = { . V_148 = V_23 -> V_148 } ;
void * V_436 = V_280 -> V_195 ;
T_2 V_61 ;
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_336 || V_23 -> V_462 )
goto V_27;
switch ( V_23 -> V_148 ) {
case V_155 :
case V_151 :
if ( F_70 ( V_326 , & V_23 -> V_92 ) )
break;
if ( F_224 ( V_23 -> V_13 ) )
F_57 ( V_463 , & V_23 -> V_110 ) ;
default:
V_23 -> V_148 = F_222 ( V_457 . V_148 , V_23 -> V_13 -> V_316 ) ;
break;
}
V_27:
if ( V_23 -> V_118 != V_38 )
F_217 ( & V_436 , V_464 , 2 , V_23 -> V_118 ) ;
switch ( V_23 -> V_148 ) {
case V_149 :
if ( V_319 )
break;
if ( ! ( V_23 -> V_13 -> V_316 & V_320 ) &&
! ( V_23 -> V_13 -> V_316 & V_321 ) )
break;
V_457 . V_148 = V_149 ;
V_457 . V_465 = 0 ;
V_457 . V_466 = 0 ;
V_457 . V_49 = 0 ;
V_457 . V_51 = 0 ;
V_457 . V_467 = 0 ;
F_217 ( & V_436 , V_468 , sizeof( V_457 ) ,
( unsigned long ) & V_457 ) ;
break;
case V_151 :
V_457 . V_148 = V_151 ;
V_457 . V_466 = V_23 -> V_96 ;
F_225 ( V_23 , & V_457 ) ;
V_61 = F_66 ( T_2 , V_469 , V_23 -> V_13 -> V_165 -
V_251 - V_402 -
V_256 ) ;
V_457 . V_467 = F_18 ( V_61 ) ;
F_227 ( V_23 ) ;
V_457 . V_465 = F_66 ( T_2 , V_23 -> V_98 ,
V_99 ) ;
F_217 ( & V_436 , V_468 , sizeof( V_457 ) ,
( unsigned long ) & V_457 ) ;
if ( F_70 ( V_463 , & V_23 -> V_110 ) )
F_218 ( & V_436 , V_23 ) ;
if ( F_70 ( V_246 , & V_23 -> V_110 ) )
F_217 ( & V_436 , V_470 , 2 ,
V_23 -> V_98 ) ;
if ( V_23 -> V_13 -> V_316 & V_471 )
if ( V_23 -> V_94 == V_472 ||
F_70 ( V_473 , & V_23 -> V_92 ) ) {
V_23 -> V_94 = V_472 ;
F_217 ( & V_436 , V_474 , 1 ,
V_23 -> V_94 ) ;
}
break;
case V_155 :
F_227 ( V_23 ) ;
V_457 . V_148 = V_155 ;
V_457 . V_465 = 0 ;
V_457 . V_466 = 0 ;
V_457 . V_49 = 0 ;
V_457 . V_51 = 0 ;
V_61 = F_66 ( T_2 , V_469 , V_23 -> V_13 -> V_165 -
V_251 - V_402 -
V_256 ) ;
V_457 . V_467 = F_18 ( V_61 ) ;
F_217 ( & V_436 , V_468 , sizeof( V_457 ) ,
( unsigned long ) & V_457 ) ;
if ( F_70 ( V_463 , & V_23 -> V_110 ) )
F_218 ( & V_436 , V_23 ) ;
if ( V_23 -> V_13 -> V_316 & V_471 )
if ( V_23 -> V_94 == V_472 ||
F_70 ( V_473 , & V_23 -> V_92 ) ) {
V_23 -> V_94 = V_472 ;
F_217 ( & V_436 , V_474 , 1 ,
V_23 -> V_94 ) ;
}
break;
}
V_280 -> V_16 = F_18 ( V_23 -> V_16 ) ;
V_280 -> V_110 = F_18 ( 0 ) ;
return V_436 - V_195 ;
}
static int F_228 ( struct V_11 * V_23 , void * V_195 )
{
struct V_475 * V_159 = V_195 ;
void * V_436 = V_159 -> V_195 ;
void * V_280 = V_23 -> V_476 ;
int V_194 = V_23 -> V_477 ;
int type , V_478 , V_437 ;
unsigned long V_438 ;
struct V_456 V_457 = { . V_148 = V_149 } ;
struct V_442 V_443 ;
T_1 V_479 = 0 ;
T_2 V_165 = V_38 ;
T_2 V_160 = V_480 ;
T_2 V_61 ;
F_23 ( L_3 , V_23 ) ;
while ( V_194 >= V_441 ) {
V_194 -= F_216 ( & V_280 , & type , & V_437 , & V_438 ) ;
V_478 = type & V_481 ;
type &= V_482 ;
switch ( type ) {
case V_464 :
V_165 = V_438 ;
break;
case V_483 :
V_23 -> V_105 = V_438 ;
break;
case V_484 :
break;
case V_468 :
if ( V_437 == sizeof( V_457 ) )
memcpy ( & V_457 , ( void * ) V_438 , V_437 ) ;
break;
case V_474 :
if ( V_438 == V_472 )
F_57 ( V_473 , & V_23 -> V_92 ) ;
break;
case V_448 :
V_479 = 1 ;
if ( V_437 == sizeof( V_443 ) )
memcpy ( & V_443 , ( void * ) V_438 , V_437 ) ;
break;
case V_470 :
if ( ! ( V_23 -> V_13 -> V_270 & V_271 ) )
return - V_77 ;
F_57 ( V_246 , & V_23 -> V_110 ) ;
F_57 ( V_485 , & V_23 -> V_92 ) ;
V_23 -> V_100 = V_460 ;
V_23 -> V_102 = V_438 ;
break;
default:
if ( V_478 )
break;
V_160 = V_486 ;
* ( ( T_1 * ) V_436 ++ ) = type ;
break;
}
}
if ( V_23 -> V_462 || V_23 -> V_336 > 1 )
goto V_27;
switch ( V_23 -> V_148 ) {
case V_155 :
case V_151 :
if ( ! F_70 ( V_326 , & V_23 -> V_92 ) ) {
V_23 -> V_148 = F_222 ( V_457 . V_148 ,
V_23 -> V_13 -> V_316 ) ;
break;
}
if ( V_479 ) {
if ( F_224 ( V_23 -> V_13 ) )
F_57 ( V_463 , & V_23 -> V_110 ) ;
else
return - V_77 ;
}
if ( V_23 -> V_148 != V_457 . V_148 )
return - V_77 ;
break;
}
V_27:
if ( V_23 -> V_148 != V_457 . V_148 ) {
V_160 = V_487 ;
V_457 . V_148 = V_23 -> V_148 ;
if ( V_23 -> V_462 == 1 )
return - V_77 ;
F_217 ( & V_436 , V_468 , sizeof( V_457 ) ,
( unsigned long ) & V_457 ) ;
}
if ( V_160 == V_480 ) {
if ( V_165 < V_488 )
V_160 = V_487 ;
else {
V_23 -> V_37 = V_165 ;
F_57 ( V_489 , & V_23 -> V_92 ) ;
}
F_217 ( & V_436 , V_464 , 2 , V_23 -> V_37 ) ;
if ( V_479 ) {
if ( V_23 -> V_130 != V_490 &&
V_443 . V_444 != V_490 &&
V_443 . V_444 != V_23 -> V_130 ) {
V_160 = V_487 ;
if ( V_23 -> V_336 >= 1 )
return - V_77 ;
F_217 ( & V_436 , V_448 ,
sizeof( V_443 ) ,
( unsigned long ) & V_443 ) ;
} else {
V_160 = V_491 ;
F_57 ( V_492 , & V_23 -> V_92 ) ;
}
}
switch ( V_457 . V_148 ) {
case V_149 :
V_23 -> V_94 = V_472 ;
F_57 ( V_493 , & V_23 -> V_92 ) ;
break;
case V_151 :
if ( ! F_70 ( V_485 , & V_23 -> V_92 ) )
V_23 -> V_102 = V_457 . V_465 ;
else
V_457 . V_465 = V_99 ;
V_23 -> V_101 = V_457 . V_466 ;
V_61 = F_66 ( T_2 , F_229 ( V_457 . V_467 ) ,
V_23 -> V_13 -> V_165 - V_251 -
V_402 - V_256 ) ;
V_457 . V_467 = F_18 ( V_61 ) ;
V_23 -> V_406 = V_61 ;
F_225 ( V_23 , & V_457 ) ;
F_57 ( V_493 , & V_23 -> V_92 ) ;
F_217 ( & V_436 , V_468 ,
sizeof( V_457 ) , ( unsigned long ) & V_457 ) ;
if ( F_70 ( V_463 , & V_23 -> V_110 ) ) {
V_23 -> V_494 = V_443 . V_190 ;
V_23 -> V_495 = V_443 . V_444 ;
V_23 -> V_496 = F_229 ( V_443 . V_445 ) ;
V_23 -> V_497 =
F_230 ( V_443 . V_105 ) ;
V_23 -> V_498 =
F_230 ( V_443 . V_447 ) ;
V_23 -> V_499 =
F_230 ( V_443 . V_446 ) ;
F_217 ( & V_436 , V_448 ,
sizeof( V_443 ) ,
( unsigned long ) & V_443 ) ;
}
break;
case V_155 :
V_61 = F_66 ( T_2 , F_229 ( V_457 . V_467 ) ,
V_23 -> V_13 -> V_165 - V_251 -
V_402 - V_256 ) ;
V_457 . V_467 = F_18 ( V_61 ) ;
V_23 -> V_406 = V_61 ;
F_57 ( V_493 , & V_23 -> V_92 ) ;
F_217 ( & V_436 , V_468 , sizeof( V_457 ) ,
( unsigned long ) & V_457 ) ;
break;
default:
V_160 = V_487 ;
memset ( & V_457 , 0 , sizeof( V_457 ) ) ;
V_457 . V_148 = V_23 -> V_148 ;
}
if ( V_160 == V_480 )
F_57 ( V_500 , & V_23 -> V_92 ) ;
}
V_159 -> V_17 = F_18 ( V_23 -> V_16 ) ;
V_159 -> V_160 = F_18 ( V_160 ) ;
V_159 -> V_110 = F_18 ( 0 ) ;
return V_436 - V_195 ;
}
static int F_231 ( struct V_11 * V_23 , void * V_159 , int V_194 ,
void * V_195 , T_2 * V_160 )
{
struct V_461 * V_280 = V_195 ;
void * V_436 = V_280 -> V_195 ;
int type , V_437 ;
unsigned long V_438 ;
struct V_456 V_457 = { . V_148 = V_149 } ;
struct V_442 V_443 ;
F_23 ( L_40 , V_23 , V_159 , V_194 , V_195 ) ;
while ( V_194 >= V_441 ) {
V_194 -= F_216 ( & V_159 , & type , & V_437 , & V_438 ) ;
switch ( type ) {
case V_464 :
if ( V_438 < V_488 ) {
* V_160 = V_487 ;
V_23 -> V_118 = V_488 ;
} else
V_23 -> V_118 = V_438 ;
F_217 ( & V_436 , V_464 , 2 , V_23 -> V_118 ) ;
break;
case V_483 :
V_23 -> V_105 = V_438 ;
F_217 ( & V_436 , V_483 ,
2 , V_23 -> V_105 ) ;
break;
case V_468 :
if ( V_437 == sizeof( V_457 ) )
memcpy ( & V_457 , ( void * ) V_438 , V_437 ) ;
if ( F_70 ( V_326 , & V_23 -> V_92 ) &&
V_457 . V_148 != V_23 -> V_148 )
return - V_77 ;
V_23 -> V_94 = 0 ;
F_217 ( & V_436 , V_468 ,
sizeof( V_457 ) , ( unsigned long ) & V_457 ) ;
break;
case V_470 :
V_23 -> V_103 = F_66 ( T_2 , V_438 , V_23 -> V_103 ) ;
F_217 ( & V_436 , V_470 , 2 ,
V_23 -> V_98 ) ;
break;
case V_448 :
if ( V_437 == sizeof( V_443 ) )
memcpy ( & V_443 , ( void * ) V_438 , V_437 ) ;
if ( V_23 -> V_130 != V_490 &&
V_443 . V_444 != V_490 &&
V_443 . V_444 != V_23 -> V_130 )
return - V_77 ;
F_217 ( & V_436 , V_448 , sizeof( V_443 ) ,
( unsigned long ) & V_443 ) ;
break;
case V_474 :
if ( * V_160 == V_491 )
if ( V_438 == V_472 )
F_57 ( V_473 ,
& V_23 -> V_92 ) ;
break;
}
}
if ( V_23 -> V_148 == V_149 && V_23 -> V_148 != V_457 . V_148 )
return - V_77 ;
V_23 -> V_148 = V_457 . V_148 ;
if ( * V_160 == V_480 || * V_160 == V_491 ) {
switch ( V_457 . V_148 ) {
case V_151 :
V_23 -> V_49 = F_229 ( V_457 . V_49 ) ;
V_23 -> V_51 = F_229 ( V_457 . V_51 ) ;
V_23 -> V_117 = F_229 ( V_457 . V_467 ) ;
if ( ! F_70 ( V_246 , & V_23 -> V_110 ) )
V_23 -> V_103 = F_66 ( T_2 , V_23 -> V_103 ,
V_457 . V_465 ) ;
if ( F_70 ( V_463 , & V_23 -> V_110 ) ) {
V_23 -> V_132 = F_229 ( V_443 . V_445 ) ;
V_23 -> V_134 =
F_230 ( V_443 . V_446 ) ;
V_23 -> V_136 = F_230 ( V_443 . V_447 ) ;
V_23 -> V_138 =
F_230 ( V_443 . V_105 ) ;
}
break;
case V_155 :
V_23 -> V_117 = F_229 ( V_457 . V_467 ) ;
}
}
V_280 -> V_16 = F_18 ( V_23 -> V_16 ) ;
V_280 -> V_110 = F_18 ( 0 ) ;
return V_436 - V_195 ;
}
static int F_232 ( struct V_11 * V_23 , void * V_195 ,
T_2 V_160 , T_2 V_110 )
{
struct V_475 * V_159 = V_195 ;
void * V_436 = V_159 -> V_195 ;
F_23 ( L_3 , V_23 ) ;
V_159 -> V_17 = F_18 ( V_23 -> V_16 ) ;
V_159 -> V_160 = F_18 ( V_160 ) ;
V_159 -> V_110 = F_18 ( V_110 ) ;
return V_436 - V_195 ;
}
void F_233 ( struct V_11 * V_23 )
{
struct V_158 V_159 ;
struct V_12 * V_13 = V_23 -> V_13 ;
F_23 ( L_3 , V_23 ) ;
V_159 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_159 . V_165 = F_18 ( V_23 -> V_118 ) ;
V_159 . V_117 = F_18 ( V_23 -> V_117 ) ;
V_159 . V_166 = F_18 ( V_23 -> V_115 ) ;
V_159 . V_160 = F_18 ( V_332 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_167 , sizeof( V_159 ) ,
& V_159 ) ;
}
void F_234 ( struct V_11 * V_23 )
{
struct V_168 V_159 ;
struct V_12 * V_13 = V_23 -> V_13 ;
T_1 V_328 [ 128 ] ;
T_1 V_501 ;
V_159 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_159 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_159 . V_160 = F_18 ( V_332 ) ;
V_159 . V_170 = F_18 ( V_171 ) ;
if ( V_23 -> V_207 )
V_501 = V_502 ;
else
V_501 = V_172 ;
F_23 ( L_41 , V_23 , V_501 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_501 , sizeof( V_159 ) , & V_159 ) ;
if ( F_132 ( V_334 , & V_23 -> V_92 ) )
return;
F_83 ( V_13 , F_91 ( V_13 ) , V_335 ,
F_142 ( V_23 , V_328 ) , V_328 ) ;
V_23 -> V_336 ++ ;
}
static void F_235 ( struct V_11 * V_23 , void * V_159 , int V_194 )
{
int type , V_437 ;
unsigned long V_438 ;
T_2 V_503 = V_23 -> V_103 ;
struct V_456 V_457 = {
. V_148 = V_23 -> V_148 ,
. V_49 = F_18 ( V_107 ) ,
. V_51 = F_18 ( V_108 ) ,
. V_467 = F_18 ( V_23 -> V_118 ) ,
. V_465 = F_66 ( T_2 , V_23 -> V_103 , V_99 ) ,
} ;
F_23 ( L_42 , V_23 , V_159 , V_194 ) ;
if ( ( V_23 -> V_148 != V_151 ) && ( V_23 -> V_148 != V_155 ) )
return;
while ( V_194 >= V_441 ) {
V_194 -= F_216 ( & V_159 , & type , & V_437 , & V_438 ) ;
switch ( type ) {
case V_468 :
if ( V_437 == sizeof( V_457 ) )
memcpy ( & V_457 , ( void * ) V_438 , V_437 ) ;
break;
case V_470 :
V_503 = V_438 ;
break;
}
}
switch ( V_457 . V_148 ) {
case V_151 :
V_23 -> V_49 = F_229 ( V_457 . V_49 ) ;
V_23 -> V_51 = F_229 ( V_457 . V_51 ) ;
V_23 -> V_117 = F_229 ( V_457 . V_467 ) ;
if ( F_70 ( V_246 , & V_23 -> V_110 ) )
V_23 -> V_103 = F_66 ( T_2 , V_23 -> V_103 , V_503 ) ;
else
V_23 -> V_103 = F_66 ( T_2 , V_23 -> V_103 ,
V_457 . V_465 ) ;
break;
case V_155 :
V_23 -> V_117 = F_229 ( V_457 . V_467 ) ;
}
}
static inline int F_236 ( struct V_12 * V_13 ,
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
struct V_505 * V_506 = (struct V_505 * ) V_195 ;
if ( V_504 < sizeof( * V_506 ) )
return - V_507 ;
if ( V_506 -> V_74 != V_508 )
return 0 ;
if ( ( V_13 -> V_308 & V_309 ) &&
V_432 -> V_19 == V_13 -> V_311 ) {
F_237 ( & V_13 -> V_312 ) ;
V_13 -> V_308 |= V_315 ;
V_13 -> V_311 = 0 ;
F_140 ( V_13 ) ;
}
return 0 ;
}
static struct V_11 * F_238 ( struct V_12 * V_13 ,
struct V_431 * V_432 ,
T_1 * V_195 , T_1 V_501 , T_1 V_282 )
{
struct V_279 * V_280 = (struct V_279 * ) V_195 ;
struct V_168 V_159 ;
struct V_11 * V_23 = NULL , * V_509 ;
int V_160 , V_170 = V_171 ;
T_2 V_16 = 0 , V_17 = F_69 ( V_280 -> V_17 ) ;
T_3 V_20 = V_280 -> V_20 ;
F_23 ( L_43 , F_69 ( V_20 ) , V_17 ) ;
V_509 = F_165 ( V_173 , V_20 , & V_13 -> V_8 -> V_21 ,
& V_13 -> V_8 -> V_157 , V_124 ) ;
if ( ! V_509 ) {
V_160 = V_163 ;
goto V_510;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_509 ) ;
if ( V_20 != F_18 ( V_185 ) &&
! F_239 ( V_13 -> V_8 ) ) {
V_13 -> V_121 = V_511 ;
V_160 = V_169 ;
goto V_512;
}
V_160 = V_513 ;
if ( F_4 ( V_13 , V_17 ) )
goto V_512;
V_23 = V_509 -> V_46 -> V_514 ( V_509 ) ;
if ( ! V_23 )
goto V_512;
V_13 -> V_8 -> V_367 = V_515 ;
F_81 ( & V_23 -> V_21 , & V_13 -> V_8 -> V_21 ) ;
F_81 ( & V_23 -> V_157 , & V_13 -> V_8 -> V_157 ) ;
V_23 -> V_9 = F_2 ( V_13 -> V_8 ) ;
V_23 -> V_10 = F_3 ( V_13 -> V_8 ) ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_17 ;
V_23 -> V_450 = V_282 ;
F_68 ( V_13 , V_23 ) ;
V_16 = V_23 -> V_17 ;
F_85 ( V_23 , V_23 -> V_46 -> V_174 ( V_23 ) ) ;
V_23 -> V_19 = V_432 -> V_19 ;
if ( V_13 -> V_308 & V_315 ) {
if ( F_88 ( V_23 , false ) ) {
if ( F_70 ( V_161 , & V_23 -> V_110 ) ) {
F_22 ( V_23 , V_175 ) ;
V_160 = V_329 ;
V_170 = V_330 ;
V_23 -> V_46 -> V_331 ( V_23 ) ;
} else {
if ( V_282 == V_451 ) {
F_22 ( V_23 , V_76 ) ;
V_160 = V_332 ;
} else {
F_22 ( V_23 , V_175 ) ;
V_160 = V_329 ;
}
V_170 = V_171 ;
}
} else {
F_22 ( V_23 , V_175 ) ;
V_160 = V_329 ;
V_170 = V_333 ;
}
} else {
F_22 ( V_23 , V_175 ) ;
V_160 = V_329 ;
V_170 = V_171 ;
}
V_512:
F_48 ( V_509 ) ;
F_10 ( & V_13 -> V_18 ) ;
F_49 ( V_509 ) ;
V_510:
V_159 . V_17 = F_18 ( V_17 ) ;
V_159 . V_16 = F_18 ( V_16 ) ;
V_159 . V_160 = F_18 ( V_160 ) ;
V_159 . V_170 = F_18 ( V_170 ) ;
F_83 ( V_13 , V_432 -> V_19 , V_501 , sizeof( V_159 ) , & V_159 ) ;
if ( V_160 == V_329 && V_170 == V_171 ) {
struct V_307 V_516 ;
V_516 . type = F_18 ( V_310 ) ;
V_13 -> V_308 |= V_309 ;
V_13 -> V_311 = F_91 ( V_13 ) ;
F_137 ( & V_13 -> V_312 , V_313 ) ;
F_83 ( V_13 , V_13 -> V_311 , V_314 ,
sizeof( V_516 ) , & V_516 ) ;
}
if ( V_23 && ! F_70 ( V_334 , & V_23 -> V_92 ) &&
V_160 == V_332 ) {
T_1 V_328 [ 128 ] ;
F_57 ( V_334 , & V_23 -> V_92 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_335 ,
F_142 ( V_23 , V_328 ) , V_328 ) ;
V_23 -> V_336 ++ ;
}
return V_23 ;
}
static int F_240 ( struct V_12 * V_13 ,
struct V_431 * V_432 , T_2 V_504 , T_1 * V_195 )
{
struct V_268 * V_196 = V_13 -> V_8 -> V_196 ;
struct V_7 * V_8 = V_13 -> V_8 ;
if ( V_504 < sizeof( struct V_279 ) )
return - V_507 ;
F_149 ( V_196 ) ;
if ( F_241 ( V_196 , V_517 ) &&
! F_132 ( V_518 , & V_8 -> V_110 ) )
F_242 ( V_196 , V_8 , 0 , NULL , 0 ) ;
F_151 ( V_196 ) ;
F_238 ( V_13 , V_432 , V_195 , V_172 , 0 ) ;
return 0 ;
}
static int F_243 ( struct V_12 * V_13 ,
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
struct V_168 * V_159 = (struct V_168 * ) V_195 ;
T_2 V_17 , V_16 , V_160 , V_170 ;
struct V_11 * V_23 ;
T_1 V_280 [ 128 ] ;
int V_24 ;
if ( V_504 < sizeof( * V_159 ) )
return - V_507 ;
V_17 = F_69 ( V_159 -> V_17 ) ;
V_16 = F_69 ( V_159 -> V_16 ) ;
V_160 = F_69 ( V_159 -> V_160 ) ;
V_170 = F_69 ( V_159 -> V_170 ) ;
F_23 ( L_44 ,
V_16 , V_17 , V_160 , V_170 ) ;
F_8 ( & V_13 -> V_18 ) ;
if ( V_17 ) {
V_23 = F_6 ( V_13 , V_17 ) ;
if ( ! V_23 ) {
V_24 = - V_519 ;
goto V_520;
}
} else {
V_23 = F_12 ( V_13 , V_432 -> V_19 ) ;
if ( ! V_23 ) {
V_24 = - V_519 ;
goto V_520;
}
}
V_24 = 0 ;
F_9 ( V_23 ) ;
switch ( V_160 ) {
case V_332 :
F_22 ( V_23 , V_76 ) ;
V_23 -> V_19 = 0 ;
V_23 -> V_16 = V_16 ;
F_117 ( V_267 , & V_23 -> V_92 ) ;
if ( F_132 ( V_334 , & V_23 -> V_92 ) )
break;
F_83 ( V_13 , F_91 ( V_13 ) , V_335 ,
F_142 ( V_23 , V_280 ) , V_280 ) ;
V_23 -> V_336 ++ ;
break;
case V_329 :
F_57 ( V_267 , & V_23 -> V_92 ) ;
break;
default:
F_73 ( V_23 , V_77 ) ;
break;
}
F_48 ( V_23 ) ;
V_520:
F_10 ( & V_13 -> V_18 ) ;
return V_24 ;
}
static inline void F_244 ( struct V_11 * V_23 )
{
if ( V_23 -> V_148 != V_151 && V_23 -> V_148 != V_155 )
V_23 -> V_94 = V_472 ;
else if ( ! F_70 ( V_473 , & V_23 -> V_92 ) )
V_23 -> V_94 = V_95 ;
}
static void F_245 ( struct V_11 * V_23 , void * V_195 ,
T_1 V_19 , T_2 V_110 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
F_23 ( L_45 , V_13 , V_23 , V_19 ,
V_110 ) ;
F_117 ( V_492 , & V_23 -> V_92 ) ;
F_57 ( V_500 , & V_23 -> V_92 ) ;
F_83 ( V_13 , V_19 , V_521 ,
F_232 ( V_23 , V_195 ,
V_480 , V_110 ) , V_195 ) ;
}
static void F_246 ( struct V_12 * V_13 , T_1 V_19 ,
T_2 V_17 , T_2 V_16 )
{
struct V_522 V_506 ;
V_506 . V_74 = F_18 ( V_523 ) ;
V_506 . V_17 = F_247 ( V_17 ) ;
V_506 . V_16 = F_247 ( V_16 ) ;
F_83 ( V_13 , V_19 , V_524 , sizeof( V_506 ) , & V_506 ) ;
}
static inline int F_248 ( struct V_12 * V_13 ,
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
struct V_461 * V_280 = (struct V_461 * ) V_195 ;
T_2 V_16 , V_110 ;
T_1 V_159 [ 64 ] ;
struct V_11 * V_23 ;
int V_194 , V_24 = 0 ;
if ( V_504 < sizeof( * V_280 ) )
return - V_507 ;
V_16 = F_69 ( V_280 -> V_16 ) ;
V_110 = F_69 ( V_280 -> V_110 ) ;
F_23 ( L_46 , V_16 , V_110 ) ;
V_23 = F_7 ( V_13 , V_16 ) ;
if ( ! V_23 ) {
F_246 ( V_13 , V_432 -> V_19 , V_16 , 0 ) ;
return 0 ;
}
if ( V_23 -> V_45 != V_76 && V_23 -> V_45 != V_175 ) {
F_246 ( V_13 , V_432 -> V_19 , V_23 -> V_17 ,
V_23 -> V_16 ) ;
goto V_520;
}
V_194 = V_504 - sizeof( * V_280 ) ;
if ( V_23 -> V_477 + V_194 > sizeof( V_23 -> V_476 ) ) {
F_83 ( V_13 , V_432 -> V_19 , V_521 ,
F_232 ( V_23 , V_159 ,
V_525 , V_110 ) , V_159 ) ;
goto V_520;
}
memcpy ( V_23 -> V_476 + V_23 -> V_477 , V_280 -> V_195 , V_194 ) ;
V_23 -> V_477 += V_194 ;
if ( V_110 & V_526 ) {
F_83 ( V_13 , V_432 -> V_19 , V_521 ,
F_232 ( V_23 , V_159 ,
V_480 , V_110 ) , V_159 ) ;
goto V_520;
}
V_194 = F_228 ( V_23 , V_159 ) ;
if ( V_194 < 0 ) {
F_86 ( V_23 , V_327 ) ;
goto V_520;
}
V_23 -> V_19 = V_432 -> V_19 ;
F_83 ( V_13 , V_432 -> V_19 , V_521 , V_194 , V_159 ) ;
V_23 -> V_462 ++ ;
V_23 -> V_477 = 0 ;
if ( ! F_70 ( V_500 , & V_23 -> V_92 ) )
goto V_520;
if ( F_70 ( V_527 , & V_23 -> V_92 ) ) {
F_244 ( V_23 ) ;
if ( V_23 -> V_148 == V_151 ||
V_23 -> V_148 == V_155 )
V_24 = F_221 ( V_23 ) ;
if ( V_24 < 0 )
F_86 ( V_23 , - V_24 ) ;
else
F_130 ( V_23 ) ;
goto V_520;
}
if ( ! F_132 ( V_334 , & V_23 -> V_92 ) ) {
T_1 V_328 [ 64 ] ;
F_83 ( V_13 , F_91 ( V_13 ) , V_335 ,
F_142 ( V_23 , V_328 ) , V_328 ) ;
V_23 -> V_336 ++ ;
}
if ( F_70 ( V_528 , & V_23 -> V_92 ) &&
F_70 ( V_492 , & V_23 -> V_92 ) ) {
if ( ! V_23 -> V_207 )
F_245 ( V_23 , V_159 , V_432 -> V_19 , V_110 ) ;
else
V_23 -> V_19 = V_432 -> V_19 ;
}
V_520:
F_48 ( V_23 ) ;
return V_24 ;
}
static inline int F_249 ( struct V_12 * V_13 ,
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
struct V_475 * V_159 = (struct V_475 * ) V_195 ;
T_2 V_17 , V_110 , V_160 ;
struct V_11 * V_23 ;
int V_194 = V_504 - sizeof( * V_159 ) ;
int V_24 = 0 ;
if ( V_504 < sizeof( * V_159 ) )
return - V_507 ;
V_17 = F_69 ( V_159 -> V_17 ) ;
V_110 = F_69 ( V_159 -> V_110 ) ;
V_160 = F_69 ( V_159 -> V_160 ) ;
F_23 ( L_47 , V_17 , V_110 ,
V_160 , V_194 ) ;
V_23 = F_7 ( V_13 , V_17 ) ;
if ( ! V_23 )
return 0 ;
switch ( V_160 ) {
case V_480 :
F_235 ( V_23 , V_159 -> V_195 , V_194 ) ;
F_117 ( V_528 , & V_23 -> V_92 ) ;
break;
case V_491 :
F_57 ( V_528 , & V_23 -> V_92 ) ;
if ( F_70 ( V_492 , & V_23 -> V_92 ) ) {
char V_328 [ 64 ] ;
V_194 = F_231 ( V_23 , V_159 -> V_195 , V_194 ,
V_328 , & V_160 ) ;
if ( V_194 < 0 ) {
F_86 ( V_23 , V_327 ) ;
goto V_27;
}
if ( ! V_23 -> V_207 ) {
F_245 ( V_23 , V_328 , V_432 -> V_19 ,
0 ) ;
} else {
if ( F_124 ( V_23 ) ) {
F_250 ( V_23 ) ;
V_23 -> V_19 = V_432 -> V_19 ;
}
}
}
goto V_27;
case V_487 :
if ( V_23 -> V_462 <= V_529 ) {
char V_280 [ 64 ] ;
if ( V_194 > sizeof( V_280 ) - sizeof( struct V_461 ) ) {
F_86 ( V_23 , V_327 ) ;
goto V_27;
}
V_160 = V_480 ;
V_194 = F_231 ( V_23 , V_159 -> V_195 , V_194 ,
V_280 , & V_160 ) ;
if ( V_194 < 0 ) {
F_86 ( V_23 , V_327 ) ;
goto V_27;
}
F_83 ( V_13 , F_91 ( V_13 ) ,
V_335 , V_194 , V_280 ) ;
V_23 -> V_336 ++ ;
if ( V_160 != V_480 )
goto V_27;
break;
}
default:
F_26 ( V_23 , V_327 ) ;
F_85 ( V_23 , V_530 ) ;
F_86 ( V_23 , V_327 ) ;
goto V_27;
}
if ( V_110 & V_526 )
goto V_27;
F_57 ( V_527 , & V_23 -> V_92 ) ;
if ( F_70 ( V_500 , & V_23 -> V_92 ) ) {
F_244 ( V_23 ) ;
if ( V_23 -> V_148 == V_151 ||
V_23 -> V_148 == V_155 )
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
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
struct V_322 * V_280 = (struct V_322 * ) V_195 ;
struct V_531 V_159 ;
T_2 V_16 , V_17 ;
struct V_11 * V_23 ;
if ( V_504 != sizeof( * V_280 ) )
return - V_507 ;
V_17 = F_69 ( V_280 -> V_17 ) ;
V_16 = F_69 ( V_280 -> V_16 ) ;
F_23 ( L_48 , V_17 , V_16 ) ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_6 ( V_13 , V_16 ) ;
if ( ! V_23 ) {
F_10 ( & V_13 -> V_18 ) ;
F_246 ( V_13 , V_432 -> V_19 , V_16 , V_17 ) ;
return 0 ;
}
F_9 ( V_23 ) ;
V_159 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_159 . V_17 = F_18 ( V_23 -> V_16 ) ;
F_83 ( V_13 , V_432 -> V_19 , V_532 , sizeof( V_159 ) , & V_159 ) ;
V_23 -> V_46 -> V_533 ( V_23 ) ;
F_60 ( V_23 ) ;
F_73 ( V_23 , V_327 ) ;
F_48 ( V_23 ) ;
V_23 -> V_46 -> V_82 ( V_23 ) ;
F_49 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
return 0 ;
}
static inline int F_252 ( struct V_12 * V_13 ,
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
struct V_531 * V_159 = (struct V_531 * ) V_195 ;
T_2 V_16 , V_17 ;
struct V_11 * V_23 ;
if ( V_504 != sizeof( * V_159 ) )
return - V_507 ;
V_17 = F_69 ( V_159 -> V_17 ) ;
V_16 = F_69 ( V_159 -> V_16 ) ;
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
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
struct V_307 * V_280 = (struct V_307 * ) V_195 ;
T_2 type ;
if ( V_504 != sizeof( * V_280 ) )
return - V_507 ;
type = F_69 ( V_280 -> type ) ;
F_23 ( L_50 , type ) ;
if ( type == V_310 ) {
T_1 V_328 [ 8 ] ;
T_8 V_316 = V_318 ;
struct V_534 * V_159 = (struct V_534 * ) V_328 ;
V_159 -> type = F_18 ( V_310 ) ;
V_159 -> V_160 = F_18 ( V_535 ) ;
if ( ! V_319 )
V_316 |= V_320 | V_321
| V_471 ;
if ( V_13 -> V_270 & V_271 )
V_316 |= V_455
| V_454 ;
F_107 ( V_316 , V_159 -> V_195 ) ;
F_83 ( V_13 , V_432 -> V_19 , V_536 , sizeof( V_328 ) ,
V_328 ) ;
} else if ( type == V_537 ) {
T_1 V_328 [ 12 ] ;
struct V_534 * V_159 = (struct V_534 * ) V_328 ;
V_159 -> type = F_18 ( V_537 ) ;
V_159 -> V_160 = F_18 ( V_535 ) ;
V_159 -> V_195 [ 0 ] = V_13 -> V_270 ;
memset ( V_159 -> V_195 + 1 , 0 , 7 ) ;
F_83 ( V_13 , V_432 -> V_19 , V_536 , sizeof( V_328 ) ,
V_328 ) ;
} else {
struct V_534 V_159 ;
V_159 . type = F_18 ( type ) ;
V_159 . V_160 = F_18 ( V_538 ) ;
F_83 ( V_13 , V_432 -> V_19 , V_536 , sizeof( V_159 ) ,
& V_159 ) ;
}
return 0 ;
}
static inline int F_254 ( struct V_12 * V_13 ,
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
struct V_534 * V_159 = (struct V_534 * ) V_195 ;
T_2 type , V_160 ;
if ( V_504 < sizeof( * V_159 ) )
return - V_507 ;
type = F_69 ( V_159 -> type ) ;
V_160 = F_69 ( V_159 -> V_160 ) ;
F_23 ( L_51 , type , V_160 ) ;
if ( V_432 -> V_19 != V_13 -> V_311 ||
V_13 -> V_308 & V_315 )
return 0 ;
F_237 ( & V_13 -> V_312 ) ;
if ( V_160 != V_535 ) {
V_13 -> V_308 |= V_315 ;
V_13 -> V_311 = 0 ;
F_140 ( V_13 ) ;
return 0 ;
}
switch ( type ) {
case V_310 :
V_13 -> V_316 = F_101 ( V_159 -> V_195 ) ;
if ( V_13 -> V_316 & V_539 ) {
struct V_307 V_280 ;
V_280 . type = F_18 ( V_537 ) ;
V_13 -> V_311 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_13 -> V_311 ,
V_314 , sizeof( V_280 ) , & V_280 ) ;
} else {
V_13 -> V_308 |= V_315 ;
V_13 -> V_311 = 0 ;
F_140 ( V_13 ) ;
}
break;
case V_537 :
V_13 -> V_272 = V_159 -> V_195 [ 0 ] ;
V_13 -> V_308 |= V_315 ;
V_13 -> V_311 = 0 ;
F_140 ( V_13 ) ;
break;
}
return 0 ;
}
static int F_255 ( struct V_12 * V_13 ,
struct V_431 * V_432 ,
T_2 V_504 , void * V_195 )
{
struct V_283 * V_280 = V_195 ;
struct V_540 V_159 ;
struct V_11 * V_23 ;
struct V_268 * V_196 ;
T_2 V_20 , V_17 ;
if ( V_504 != sizeof( * V_280 ) )
return - V_507 ;
if ( ! ( V_13 -> V_270 & V_271 ) )
return - V_36 ;
V_20 = F_229 ( V_280 -> V_20 ) ;
V_17 = F_229 ( V_280 -> V_17 ) ;
F_23 ( L_52 , V_20 , V_17 , V_280 -> V_282 ) ;
if ( V_280 -> V_282 == V_451 ) {
F_238 ( V_13 , V_432 , V_195 , V_502 ,
V_280 -> V_282 ) ;
return 0 ;
}
V_196 = F_256 ( V_280 -> V_282 ) ;
if ( ! V_196 )
goto error;
if ( V_196 -> V_541 != V_542 || ! F_70 ( V_276 , & V_196 -> V_110 ) ) {
F_257 ( V_196 ) ;
goto error;
}
V_23 = F_238 ( V_13 , V_432 , V_195 , V_502 ,
V_280 -> V_282 ) ;
if ( V_23 ) {
struct V_143 * V_144 = V_13 -> V_8 -> V_143 ;
struct V_7 * V_207 ;
V_207 = F_258 ( V_196 , V_543 ,
& V_13 -> V_8 -> V_157 ) ;
if ( ! V_207 ) {
F_257 ( V_196 ) ;
F_246 ( V_13 , V_432 -> V_19 , V_23 -> V_17 ,
V_23 -> V_16 ) ;
return 0 ;
}
F_23 ( L_53 , V_144 , V_23 , V_207 ) ;
V_144 -> V_145 = V_23 ;
V_23 -> V_207 = V_207 ;
V_23 -> V_94 = V_472 ;
V_13 -> V_165 = V_196 -> V_544 ;
}
F_257 ( V_196 ) ;
return 0 ;
error:
V_159 . V_16 = 0 ;
V_159 . V_17 = F_18 ( V_17 ) ;
V_159 . V_160 = F_18 ( V_545 ) ;
V_159 . V_170 = F_18 ( V_171 ) ;
F_83 ( V_13 , V_432 -> V_19 , V_502 ,
sizeof( V_159 ) , & V_159 ) ;
return 0 ;
}
static void F_259 ( struct V_11 * V_23 , T_1 V_546 )
{
struct V_547 V_280 ;
T_1 V_19 ;
F_23 ( L_54 , V_23 , V_546 ) ;
V_19 = F_91 ( V_23 -> V_13 ) ;
V_23 -> V_19 = V_19 ;
V_280 . V_548 = F_18 ( V_23 -> V_17 ) ;
V_280 . V_546 = V_546 ;
F_83 ( V_23 -> V_13 , V_19 , V_549 , sizeof( V_280 ) ,
& V_280 ) ;
F_85 ( V_23 , V_550 ) ;
}
static void F_260 ( struct V_11 * V_23 , T_2 V_160 )
{
struct V_551 V_159 ;
F_23 ( L_55 , V_23 , V_160 ) ;
V_159 . V_548 = F_18 ( V_23 -> V_16 ) ;
V_159 . V_160 = F_18 ( V_160 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_552 ,
sizeof( V_159 ) , & V_159 ) ;
}
static void F_261 ( struct V_11 * V_23 , T_2 V_160 )
{
struct V_553 V_554 ;
F_23 ( L_55 , V_23 , V_160 ) ;
V_23 -> V_19 = F_91 ( V_23 -> V_13 ) ;
V_554 . V_548 = F_18 ( V_23 -> V_17 ) ;
V_554 . V_160 = F_18 ( V_160 ) ;
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_555 ,
sizeof( V_554 ) , & V_554 ) ;
F_85 ( V_23 , V_550 ) ;
}
static void F_262 ( struct V_12 * V_13 , T_2 V_548 )
{
struct V_553 V_554 ;
F_23 ( L_56 , V_13 , V_548 ) ;
V_554 . V_548 = F_18 ( V_548 ) ;
V_554 . V_160 = F_18 ( V_556 ) ;
F_83 ( V_13 , F_91 ( V_13 ) , V_555 ,
sizeof( V_554 ) , & V_554 ) ;
}
static void F_263 ( struct V_12 * V_13 , T_1 V_19 ,
T_2 V_548 )
{
struct V_557 V_159 ;
F_23 ( L_57 , V_548 ) ;
V_159 . V_548 = F_18 ( V_548 ) ;
F_83 ( V_13 , V_19 , V_558 , sizeof( V_159 ) , & V_159 ) ;
}
static void F_264 ( struct V_11 * V_23 )
{
V_23 -> V_146 = NULL ;
V_23 -> V_207 = NULL ;
}
static void F_265 ( struct V_11 * V_23 )
{
if ( V_23 -> V_45 != V_75 ) {
F_86 ( V_23 , V_327 ) ;
return;
}
switch ( V_23 -> V_295 ) {
case V_300 :
F_128 ( V_23 ) ;
F_260 ( V_23 , V_559 ) ;
break;
case V_297 :
if ( V_23 -> V_204 == V_560 ||
V_23 -> V_204 == V_561 ) {
F_128 ( V_23 ) ;
}
F_261 ( V_23 , V_556 ) ;
break;
}
}
static void F_266 ( struct V_11 * V_23 ,
struct V_147 * V_203 )
{
struct V_475 V_159 ;
V_23 -> V_146 = V_203 ;
V_23 -> V_207 -> V_363 = V_23 -> V_13 ;
F_245 ( V_23 , & V_159 , V_23 -> V_19 , 0 ) ;
if ( F_70 ( V_527 , & V_23 -> V_92 ) ) {
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
struct V_147 * V_203 )
{
V_23 -> V_207 = V_203 -> V_13 ;
V_23 -> V_207 -> V_363 = V_23 -> V_13 ;
F_23 ( L_58 , V_23 -> V_204 ) ;
switch ( V_23 -> V_204 ) {
case V_560 :
V_23 -> V_204 = V_562 ;
break;
case V_561 :
if ( F_70 ( V_265 , & V_23 -> V_259 ) ) {
V_23 -> V_204 = V_563 ;
} else if ( V_23 -> V_295 == V_297 ) {
V_23 -> V_204 = V_564 ;
F_261 ( V_23 , V_565 ) ;
} else if ( V_23 -> V_295 == V_300 ) {
V_23 -> V_204 = V_566 ;
F_260 ( V_23 , V_567 ) ;
}
break;
default:
F_264 ( V_23 ) ;
V_23 -> V_204 = V_205 ;
}
}
void F_268 ( struct V_11 * V_23 , struct V_147 * V_203 ,
T_1 V_170 )
{
F_23 ( L_59 , V_23 , V_203 , V_170 ) ;
if ( V_170 ) {
F_265 ( V_23 ) ;
F_264 ( V_23 ) ;
return;
}
if ( V_23 -> V_45 != V_75 ) {
if ( V_23 -> V_450 != V_451 )
F_266 ( V_23 , V_203 ) ;
} else {
F_267 ( V_23 , V_203 ) ;
}
}
void F_269 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
if ( V_23 -> V_450 == V_451 ) {
if ( V_23 -> V_277 != V_278 )
return;
V_23 -> V_295 = V_297 ;
V_23 -> V_204 = V_206 ;
} else {
V_23 -> V_295 = V_297 ;
V_23 -> V_204 = V_562 ;
V_23 -> V_452 = 0 ;
F_127 ( V_23 ) ;
F_259 ( V_23 , 0 ) ;
}
}
static void F_270 ( struct V_11 * V_23 , int V_160 ,
T_1 V_450 , T_1 V_568 )
{
F_23 ( L_60 , V_23 , F_24 ( V_23 -> V_45 ) ,
V_450 , V_568 ) ;
V_23 -> V_94 = V_472 ;
if ( V_23 -> V_45 == V_78 ) {
if ( V_160 == V_332 ) {
V_23 -> V_450 = V_450 ;
F_126 ( V_23 , V_568 ) ;
} else {
F_125 ( V_23 ) ;
}
return;
}
if ( F_120 ( V_23 ) ) {
struct V_168 V_159 ;
char V_328 [ 128 ] ;
V_159 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_159 . V_16 = F_18 ( V_23 -> V_17 ) ;
if ( V_160 == V_332 ) {
V_159 . V_160 = F_18 ( V_332 ) ;
V_159 . V_170 = F_18 ( V_171 ) ;
} else {
V_159 . V_160 = F_18 ( V_513 ) ;
V_159 . V_170 = F_18 ( V_171 ) ;
}
F_83 ( V_23 -> V_13 , V_23 -> V_19 , V_502 ,
sizeof( V_159 ) , & V_159 ) ;
if ( V_160 == V_332 ) {
F_22 ( V_23 , V_76 ) ;
F_57 ( V_334 , & V_23 -> V_92 ) ;
F_83 ( V_23 -> V_13 , F_91 ( V_23 -> V_13 ) ,
V_335 ,
F_142 ( V_23 , V_328 ) , V_328 ) ;
V_23 -> V_336 ++ ;
}
}
}
static void F_271 ( struct V_11 * V_23 , T_1 V_450 ,
T_1 V_568 )
{
F_127 ( V_23 ) ;
V_23 -> V_452 = V_450 ;
V_23 -> V_204 = V_569 ;
F_259 ( V_23 , V_568 ) ;
}
static void F_272 ( struct V_11 * V_23 , int V_160 )
{
struct V_147 * V_203 = NULL ;
if ( V_203 ) {
if ( V_203 -> V_45 == V_75 ) {
V_23 -> V_207 = V_203 -> V_13 ;
V_23 -> V_207 -> V_363 = V_23 -> V_13 ;
V_23 -> V_204 = V_566 ;
F_260 ( V_23 , V_567 ) ;
F_268 ( V_23 , V_203 , V_567 ) ;
} else {
V_23 -> V_204 = V_561 ;
}
} else {
F_260 ( V_23 , V_570 ) ;
}
}
static void F_273 ( struct V_11 * V_23 , int V_160 )
{
if ( V_23 -> V_295 == V_300 ) {
T_1 V_571 ;
if ( V_160 == - V_36 )
V_571 = V_572 ;
else
V_571 = V_570 ;
F_260 ( V_23 , V_571 ) ;
}
V_23 -> V_295 = V_296 ;
V_23 -> V_204 = V_205 ;
F_173 ( V_23 ) ;
}
void F_274 ( struct V_11 * V_23 , int V_160 )
{
T_1 V_450 = V_23 -> V_450 ;
T_1 V_568 = V_23 -> V_568 ;
F_23 ( L_61 ,
V_23 , V_160 , V_450 , V_568 ) ;
if ( V_23 -> V_45 == V_164 || V_23 -> V_45 == V_573 ) {
F_48 ( V_23 ) ;
return;
}
if ( V_23 -> V_45 != V_75 ) {
F_270 ( V_23 , V_160 , V_450 , V_568 ) ;
} else if ( V_160 != V_567 ) {
F_273 ( V_23 , V_160 ) ;
} else {
switch ( V_23 -> V_295 ) {
case V_297 :
F_271 ( V_23 , V_450 ,
V_568 ) ;
break;
case V_300 :
F_272 ( V_23 , V_160 ) ;
break;
default:
F_273 ( V_23 , V_160 ) ;
break;
}
}
}
static inline int F_275 ( struct V_12 * V_13 ,
struct V_431 * V_432 ,
T_2 V_504 , void * V_195 )
{
struct V_547 * V_280 = V_195 ;
struct V_551 V_159 ;
struct V_11 * V_23 ;
T_2 V_548 = 0 ;
T_2 V_160 = V_570 ;
if ( V_504 != sizeof( * V_280 ) )
return - V_507 ;
V_548 = F_229 ( V_280 -> V_548 ) ;
F_23 ( L_62 , V_548 , V_280 -> V_546 ) ;
if ( ! ( V_13 -> V_270 & V_271 ) )
return - V_36 ;
V_23 = F_11 ( V_13 , V_548 ) ;
if ( ! V_23 ) {
V_159 . V_548 = F_18 ( V_548 ) ;
V_159 . V_160 = F_18 ( V_570 ) ;
F_83 ( V_13 , V_432 -> V_19 , V_552 ,
sizeof( V_159 ) , & V_159 ) ;
return 0 ;
}
V_23 -> V_19 = V_432 -> V_19 ;
if ( V_23 -> V_17 < V_44 ||
V_23 -> V_277 == V_574 ||
( V_23 -> V_148 != V_151 &&
V_23 -> V_148 != V_155 ) ) {
V_160 = V_570 ;
goto V_575;
}
if ( V_23 -> V_450 == V_280 -> V_546 ) {
V_160 = V_576 ;
goto V_575;
}
if ( V_280 -> V_546 != V_451 ) {
struct V_268 * V_196 ;
V_196 = F_256 ( V_280 -> V_546 ) ;
if ( ! V_196 || V_196 -> V_541 != V_542 ||
! F_70 ( V_276 , & V_196 -> V_110 ) ) {
if ( V_196 )
F_257 ( V_196 ) ;
V_160 = V_572 ;
goto V_575;
}
F_257 ( V_196 ) ;
}
if ( ( F_95 ( V_23 ) ||
V_23 -> V_295 != V_296 ) &&
F_15 ( & V_13 -> V_8 -> V_21 , & V_13 -> V_8 -> V_157 ) > 0 ) {
V_160 = V_577 ;
goto V_575;
}
V_23 -> V_295 = V_300 ;
F_127 ( V_23 ) ;
V_23 -> V_452 = V_280 -> V_546 ;
V_548 = V_23 -> V_16 ;
if ( V_280 -> V_546 == V_451 ) {
if ( F_70 ( V_265 , & V_23 -> V_259 ) ) {
V_23 -> V_204 = V_563 ;
V_160 = V_578 ;
} else {
V_23 -> V_204 = V_566 ;
V_160 = V_567 ;
}
} else {
V_23 -> V_204 = V_206 ;
V_160 = V_578 ;
}
V_575:
F_260 ( V_23 , V_160 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static void F_276 ( struct V_12 * V_13 , T_2 V_548 , T_2 V_160 )
{
struct V_11 * V_23 ;
struct V_147 * V_203 = NULL ;
V_23 = F_7 ( V_13 , V_548 ) ;
if ( ! V_23 ) {
F_262 ( V_13 , V_548 ) ;
return;
}
F_74 ( V_23 ) ;
if ( V_160 == V_578 )
F_85 ( V_23 , V_579 ) ;
switch ( V_23 -> V_204 ) {
case V_560 :
V_23 -> V_204 = V_561 ;
break;
case V_562 :
if ( V_160 == V_578 ) {
break;
} else if ( F_70 ( V_265 ,
& V_23 -> V_259 ) ) {
V_23 -> V_204 = V_563 ;
} else {
V_23 -> V_204 = V_564 ;
F_261 ( V_23 , V_565 ) ;
}
break;
case V_569 :
if ( V_160 == V_567 ) {
V_23 -> V_204 = V_561 ;
} else {
V_23 -> V_204 = V_560 ;
}
if ( ! V_203 ) {
F_261 ( V_23 , V_556 ) ;
break;
}
if ( V_203 -> V_45 != V_75 )
break;
V_23 -> V_207 = V_203 -> V_13 ;
V_23 -> V_207 -> V_363 = V_23 -> V_13 ;
if ( V_160 == V_567 ) {
F_261 ( V_23 , V_565 ) ;
} else {
V_23 -> V_204 = V_562 ;
}
F_268 ( V_23 , V_203 , V_567 ) ;
break;
default:
V_23 -> V_452 = V_23 -> V_450 ;
F_128 ( V_23 ) ;
F_261 ( V_23 , V_556 ) ;
}
F_48 ( V_23 ) ;
}
static void F_277 ( struct V_12 * V_13 , T_1 V_19 , T_2 V_548 ,
T_2 V_160 )
{
struct V_11 * V_23 ;
V_23 = F_13 ( V_13 , V_19 ) ;
if ( ! V_23 ) {
F_262 ( V_13 , V_548 ) ;
return;
}
F_74 ( V_23 ) ;
if ( V_23 -> V_295 == V_297 ) {
if ( V_160 == V_577 ) {
V_23 -> V_295 = V_300 ;
} else {
V_23 -> V_452 = V_23 -> V_450 ;
F_128 ( V_23 ) ;
}
}
F_261 ( V_23 , V_556 ) ;
F_48 ( V_23 ) ;
}
static int F_278 ( struct V_12 * V_13 ,
struct V_431 * V_432 ,
T_2 V_504 , void * V_195 )
{
struct V_551 * V_159 = V_195 ;
T_2 V_548 , V_160 ;
if ( V_504 != sizeof( * V_159 ) )
return - V_507 ;
V_548 = F_229 ( V_159 -> V_548 ) ;
V_160 = F_229 ( V_159 -> V_160 ) ;
F_23 ( L_63 , V_548 , V_160 ) ;
if ( V_160 == V_567 || V_160 == V_578 )
F_276 ( V_13 , V_548 , V_160 ) ;
else
F_277 ( V_13 , V_432 -> V_19 , V_548 , V_160 ) ;
return 0 ;
}
static int F_279 ( struct V_12 * V_13 ,
struct V_431 * V_432 ,
T_2 V_504 , void * V_195 )
{
struct V_553 * V_554 = V_195 ;
struct V_11 * V_23 ;
T_2 V_548 , V_160 ;
if ( V_504 != sizeof( * V_554 ) )
return - V_507 ;
V_548 = F_229 ( V_554 -> V_548 ) ;
V_160 = F_229 ( V_554 -> V_160 ) ;
F_23 ( L_63 , V_548 , V_160 ) ;
V_23 = F_11 ( V_13 , V_548 ) ;
if ( ! V_23 ) {
F_263 ( V_13 , V_432 -> V_19 , V_548 ) ;
return 0 ;
}
if ( V_23 -> V_204 == V_566 ) {
if ( V_160 == V_565 ) {
V_23 -> V_450 = V_23 -> V_452 ;
if ( V_23 -> V_450 == V_451 )
F_264 ( V_23 ) ;
} else {
V_23 -> V_452 = V_23 -> V_450 ;
}
F_128 ( V_23 ) ;
}
F_263 ( V_13 , V_432 -> V_19 , V_548 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static inline int F_280 ( struct V_12 * V_13 ,
struct V_431 * V_432 ,
T_2 V_504 , void * V_195 )
{
struct V_557 * V_159 = V_195 ;
struct V_11 * V_23 ;
T_2 V_548 ;
if ( V_504 != sizeof( * V_159 ) )
return - V_507 ;
V_548 = F_229 ( V_159 -> V_548 ) ;
F_23 ( L_57 , V_548 ) ;
V_23 = F_7 ( V_13 , V_548 ) ;
if ( ! V_23 )
return 0 ;
F_74 ( V_23 ) ;
if ( V_23 -> V_204 == V_564 ) {
V_23 -> V_450 = V_23 -> V_452 ;
if ( V_23 -> V_450 == V_451 && V_23 -> V_146 )
F_264 ( V_23 ) ;
F_128 ( V_23 ) ;
}
F_48 ( V_23 ) ;
return 0 ;
}
static inline int V_345 ( struct V_12 * V_13 ,
struct V_431 * V_432 ,
T_2 V_504 , T_1 * V_195 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_345 * V_280 ;
struct V_580 V_159 ;
T_2 V_346 , V_347 , V_348 , V_350 ;
int V_24 ;
if ( V_8 -> V_340 != V_581 )
return - V_36 ;
if ( V_504 != sizeof( struct V_345 ) )
return - V_507 ;
V_280 = (struct V_345 * ) V_195 ;
V_346 = F_69 ( V_280 -> V_346 ) ;
V_347 = F_69 ( V_280 -> V_347 ) ;
V_348 = F_69 ( V_280 -> V_348 ) ;
V_350 = F_69 ( V_280 -> V_350 ) ;
F_23 ( L_64 ,
V_346 , V_347 , V_348 , V_350 ) ;
memset ( & V_159 , 0 , sizeof( V_159 ) ) ;
V_24 = F_281 ( V_346 , V_347 , V_348 , V_350 ) ;
if ( V_24 )
V_159 . V_160 = F_18 ( V_582 ) ;
else
V_159 . V_160 = F_18 ( V_583 ) ;
F_83 ( V_13 , V_432 -> V_19 , V_584 ,
sizeof( V_159 ) , & V_159 ) ;
if ( ! V_24 ) {
T_1 V_585 ;
V_585 = F_282 ( V_8 , V_346 , V_347 , V_348 ,
V_350 ) ;
F_283 ( V_8 -> V_196 , & V_8 -> V_157 , V_8 -> V_10 ,
V_585 , V_346 , V_347 , V_348 ,
V_350 ) ;
}
return 0 ;
}
static int F_284 ( struct V_12 * V_13 ,
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
struct V_158 * V_159 = (struct V_158 * ) V_195 ;
struct V_7 * V_8 = V_13 -> V_8 ;
T_2 V_16 , V_165 , V_117 , V_166 , V_160 ;
struct V_11 * V_23 ;
int V_24 , V_79 ;
if ( V_504 < sizeof( * V_159 ) )
return - V_507 ;
V_16 = F_69 ( V_159 -> V_16 ) ;
V_165 = F_69 ( V_159 -> V_165 ) ;
V_117 = F_69 ( V_159 -> V_117 ) ;
V_166 = F_69 ( V_159 -> V_166 ) ;
V_160 = F_69 ( V_159 -> V_160 ) ;
if ( V_160 == V_332 && ( V_165 < 23 || V_117 < 23 ||
V_16 < V_44 ||
V_16 > V_42 ) )
return - V_507 ;
F_23 ( L_65 ,
V_16 , V_165 , V_117 , V_166 , V_160 ) ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_12 ( V_13 , V_432 -> V_19 ) ;
if ( ! V_23 ) {
V_24 = - V_519 ;
goto V_520;
}
V_24 = 0 ;
F_9 ( V_23 ) ;
switch ( V_160 ) {
case V_332 :
if ( F_4 ( V_13 , V_16 ) ) {
V_24 = - V_519 ;
break;
}
V_23 -> V_19 = 0 ;
V_23 -> V_16 = V_16 ;
V_23 -> V_37 = V_165 ;
V_23 -> V_406 = V_117 ;
V_23 -> V_114 = V_166 ;
F_130 ( V_23 ) ;
break;
case V_586 :
case V_587 :
if ( V_8 -> V_79 > V_180 ) {
F_73 ( V_23 , V_77 ) ;
break;
}
V_79 = V_8 -> V_79 + 1 ;
if ( V_23 -> V_79 < V_79 )
V_23 -> V_79 = V_79 ;
F_117 ( V_305 , & V_23 -> V_110 ) ;
F_89 ( V_8 , V_23 -> V_79 ) ;
break;
default:
F_73 ( V_23 , V_77 ) ;
break;
}
F_48 ( V_23 ) ;
V_520:
F_10 ( & V_13 -> V_18 ) ;
return V_24 ;
}
static inline int F_285 ( struct V_12 * V_13 ,
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
int V_24 = 0 ;
switch ( V_432 -> V_193 ) {
case V_524 :
F_236 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_281 :
V_24 = F_240 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_172 :
case V_502 :
F_243 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_335 :
V_24 = F_248 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_521 :
F_249 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_324 :
V_24 = F_251 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_532 :
F_252 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_588 :
F_83 ( V_13 , V_432 -> V_19 , V_589 , V_504 , V_195 ) ;
break;
case V_589 :
break;
case V_314 :
V_24 = F_253 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_536 :
F_254 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_284 :
V_24 = F_255 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_549 :
V_24 = F_275 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_552 :
F_278 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_555 :
V_24 = F_279 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_558 :
F_280 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
default:
F_286 ( L_66 , V_432 -> V_193 ) ;
V_24 = - V_36 ;
break;
}
return V_24 ;
}
static int F_287 ( struct V_12 * V_13 ,
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
struct V_304 * V_280 = (struct V_304 * ) V_195 ;
struct V_158 V_159 ;
struct V_11 * V_23 , * V_509 ;
T_2 V_16 , V_17 , V_166 , V_165 , V_117 ;
T_3 V_20 ;
T_1 V_160 ;
if ( V_504 != sizeof( * V_280 ) )
return - V_507 ;
V_17 = F_69 ( V_280 -> V_17 ) ;
V_165 = F_69 ( V_280 -> V_165 ) ;
V_117 = F_69 ( V_280 -> V_117 ) ;
V_20 = V_280 -> V_20 ;
V_16 = 0 ;
V_166 = 0 ;
if ( V_165 < 23 || V_117 < 23 )
return - V_507 ;
F_23 ( L_67 , F_69 ( V_20 ) ,
V_17 , V_165 , V_117 ) ;
V_509 = F_165 ( V_173 , V_20 , & V_13 -> V_8 -> V_21 ,
& V_13 -> V_8 -> V_157 , V_2 ) ;
if ( ! V_509 ) {
V_160 = V_163 ;
V_23 = NULL ;
goto V_512;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_509 ) ;
if ( ! F_288 ( V_13 -> V_8 , V_509 -> V_79 ,
V_590 ) ) {
V_160 = V_586 ;
V_23 = NULL ;
goto V_591;
}
if ( V_17 < V_44 || V_17 > V_42 ) {
V_160 = V_592 ;
V_23 = NULL ;
goto V_591;
}
if ( F_4 ( V_13 , V_17 ) ) {
V_160 = V_593 ;
V_23 = NULL ;
goto V_591;
}
V_23 = V_509 -> V_46 -> V_514 ( V_509 ) ;
if ( ! V_23 ) {
V_160 = V_513 ;
goto V_591;
}
F_65 ( V_23 ) ;
F_81 ( & V_23 -> V_21 , & V_13 -> V_8 -> V_21 ) ;
F_81 ( & V_23 -> V_157 , & V_13 -> V_8 -> V_157 ) ;
V_23 -> V_9 = F_2 ( V_13 -> V_8 ) ;
V_23 -> V_10 = F_3 ( V_13 -> V_8 ) ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_17 ;
V_23 -> V_37 = V_165 ;
V_23 -> V_406 = V_117 ;
V_23 -> V_114 = F_69 ( V_280 -> V_166 ) ;
F_68 ( V_13 , V_23 ) ;
V_16 = V_23 -> V_17 ;
V_166 = V_23 -> V_115 ;
F_85 ( V_23 , V_23 -> V_46 -> V_174 ( V_23 ) ) ;
V_23 -> V_19 = V_432 -> V_19 ;
if ( F_70 ( V_161 , & V_23 -> V_110 ) ) {
F_22 ( V_23 , V_175 ) ;
V_160 = V_329 ;
V_23 -> V_46 -> V_331 ( V_23 ) ;
} else {
F_130 ( V_23 ) ;
V_160 = V_332 ;
}
V_591:
F_48 ( V_509 ) ;
F_10 ( & V_13 -> V_18 ) ;
F_49 ( V_509 ) ;
if ( V_160 == V_329 )
return 0 ;
V_512:
if ( V_23 ) {
V_159 . V_165 = F_18 ( V_23 -> V_118 ) ;
V_159 . V_117 = F_18 ( V_23 -> V_117 ) ;
} else {
V_159 . V_165 = 0 ;
V_159 . V_117 = 0 ;
}
V_159 . V_16 = F_18 ( V_16 ) ;
V_159 . V_166 = F_18 ( V_166 ) ;
V_159 . V_160 = F_18 ( V_160 ) ;
F_83 ( V_13 , V_432 -> V_19 , V_167 , sizeof( V_159 ) , & V_159 ) ;
return 0 ;
}
static inline int F_289 ( struct V_12 * V_13 ,
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
struct F_289 * V_594 ;
struct V_11 * V_23 ;
T_2 V_14 , V_166 , V_595 ;
if ( V_504 != sizeof( * V_594 ) )
return - V_507 ;
V_594 = (struct F_289 * ) V_195 ;
V_14 = F_69 ( V_594 -> V_14 ) ;
V_166 = F_69 ( V_594 -> V_166 ) ;
F_23 ( L_68 , V_14 , V_166 ) ;
V_23 = F_11 ( V_13 , V_14 ) ;
if ( ! V_23 )
return - V_519 ;
V_595 = V_596 - V_23 -> V_114 ;
if ( V_166 > V_595 ) {
F_286 ( L_69 ) ;
F_86 ( V_23 , V_327 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
V_23 -> V_114 += V_166 ;
while ( V_23 -> V_114 && ! F_170 ( & V_23 -> V_120 ) ) {
F_96 ( V_23 , F_171 ( & V_23 -> V_120 ) ) ;
V_23 -> V_114 -- ;
}
if ( V_23 -> V_114 )
V_23 -> V_46 -> V_597 ( V_23 ) ;
F_48 ( V_23 ) ;
return 0 ;
}
static inline int F_290 ( struct V_12 * V_13 ,
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
struct V_505 * V_506 = (struct V_505 * ) V_195 ;
struct V_11 * V_23 ;
if ( V_504 < sizeof( * V_506 ) )
return - V_507 ;
F_8 ( & V_13 -> V_18 ) ;
V_23 = F_12 ( V_13 , V_432 -> V_19 ) ;
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
struct V_431 * V_432 , T_2 V_504 ,
T_1 * V_195 )
{
int V_24 = 0 ;
switch ( V_432 -> V_193 ) {
case V_524 :
F_290 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_352 :
V_24 = V_345 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_584 :
break;
case V_167 :
F_284 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_306 :
V_24 = F_287 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_598 :
V_24 = F_289 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_324 :
V_24 = F_251 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
case V_532 :
F_252 ( V_13 , V_432 , V_504 , V_195 ) ;
break;
default:
F_286 ( L_70 , V_432 -> V_193 ) ;
V_24 = - V_36 ;
break;
}
return V_24 ;
}
static inline void F_292 ( struct V_12 * V_13 ,
struct V_52 * V_56 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_431 * V_432 ;
T_2 V_194 ;
int V_24 ;
if ( V_8 -> type != V_2 )
goto V_599;
if ( V_56 -> V_194 < V_433 )
goto V_599;
V_432 = ( void * ) V_56 -> V_195 ;
F_102 ( V_56 , V_433 ) ;
V_194 = F_229 ( V_432 -> V_194 ) ;
F_23 ( L_71 , V_432 -> V_193 , V_194 , V_432 -> V_19 ) ;
if ( V_194 != V_56 -> V_194 || ! V_432 -> V_19 ) {
F_23 ( L_72 ) ;
goto V_599;
}
V_24 = F_291 ( V_13 , V_432 , V_194 , V_56 -> V_195 ) ;
if ( V_24 ) {
struct V_505 V_506 ;
F_286 ( L_73 , V_24 ) ;
V_506 . V_74 = F_18 ( V_508 ) ;
F_83 ( V_13 , V_432 -> V_19 , V_524 ,
sizeof( V_506 ) , & V_506 ) ;
}
V_599:
F_97 ( V_56 ) ;
}
static inline void F_293 ( struct V_12 * V_13 ,
struct V_52 * V_56 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
T_1 * V_195 = V_56 -> V_195 ;
int V_194 = V_56 -> V_194 ;
struct V_431 V_432 ;
int V_24 ;
F_215 ( V_13 , V_56 ) ;
if ( V_8 -> type != V_124 )
goto V_599;
while ( V_194 >= V_433 ) {
T_2 V_504 ;
memcpy ( & V_432 , V_195 , V_433 ) ;
V_195 += V_433 ;
V_194 -= V_433 ;
V_504 = F_229 ( V_432 . V_194 ) ;
F_23 ( L_71 , V_432 . V_193 , V_504 ,
V_432 . V_19 ) ;
if ( V_504 > V_194 || ! V_432 . V_19 ) {
F_23 ( L_72 ) ;
break;
}
V_24 = F_285 ( V_13 , & V_432 , V_504 , V_195 ) ;
if ( V_24 ) {
struct V_505 V_506 ;
F_286 ( L_73 , V_24 ) ;
V_506 . V_74 = F_18 ( V_508 ) ;
F_83 ( V_13 , V_432 . V_19 , V_524 ,
sizeof( V_506 ) , & V_506 ) ;
}
V_195 += V_504 ;
V_194 -= V_504 ;
}
V_599:
F_97 ( V_56 ) ;
}
static int F_294 ( struct V_11 * V_23 , struct V_52 * V_56 )
{
T_2 V_600 , V_601 ;
int V_602 ;
if ( F_70 ( V_246 , & V_23 -> V_110 ) )
V_602 = V_251 ;
else
V_602 = V_252 ;
if ( V_23 -> V_94 == V_95 ) {
F_295 ( V_56 , V_56 -> V_194 - V_256 ) ;
V_601 = F_103 ( V_56 -> V_195 + V_56 -> V_194 ) ;
V_600 = F_114 ( 0 , V_56 -> V_195 - V_602 , V_56 -> V_194 + V_602 ) ;
if ( V_600 != V_601 )
return - V_603 ;
}
return 0 ;
}
static void F_296 ( struct V_11 * V_23 )
{
struct V_211 V_212 ;
F_23 ( L_3 , V_23 ) ;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
V_212 . V_220 = 1 ;
V_212 . V_216 = 1 ;
V_212 . V_213 = V_23 -> V_266 ;
F_57 ( V_258 , & V_23 -> V_259 ) ;
if ( F_70 ( V_265 , & V_23 -> V_259 ) ) {
V_212 . V_224 = V_262 ;
F_115 ( V_23 , & V_212 ) ;
}
if ( F_116 ( V_294 , & V_23 -> V_259 ) &&
V_23 -> V_384 > 0 )
F_27 ( V_23 ) ;
F_173 ( V_23 ) ;
if ( ! F_70 ( V_265 , & V_23 -> V_259 ) &&
F_70 ( V_258 , & V_23 -> V_259 ) ) {
V_212 . V_224 = V_260 ;
F_115 ( V_23 , & V_212 ) ;
}
}
static void F_297 ( struct V_52 * V_56 , struct V_52 * V_604 ,
struct V_52 * * V_605 )
{
if ( ! F_298 ( V_56 ) )
F_190 ( V_56 ) -> V_394 = V_604 ;
V_604 -> V_399 = NULL ;
( * V_605 ) -> V_399 = V_604 ;
* V_605 = V_604 ;
V_56 -> V_194 += V_604 -> V_194 ;
V_56 -> V_398 += V_604 -> V_194 ;
V_56 -> V_606 += V_604 -> V_606 ;
}
static int F_299 ( struct V_11 * V_23 , struct V_52 * V_56 ,
struct V_211 * V_212 )
{
int V_24 = - V_36 ;
switch ( V_212 -> V_227 ) {
case V_407 :
if ( V_23 -> V_111 )
break;
V_24 = V_23 -> V_46 -> V_429 ( V_23 , V_56 ) ;
break;
case V_408 :
if ( V_23 -> V_111 )
break;
V_23 -> V_113 = F_103 ( V_56 -> V_195 ) ;
F_102 ( V_56 , V_402 ) ;
if ( V_23 -> V_113 > V_23 -> V_118 ) {
V_24 = - V_411 ;
break;
}
if ( V_56 -> V_194 >= V_23 -> V_113 )
break;
V_23 -> V_111 = V_56 ;
V_23 -> V_112 = V_56 ;
V_56 = NULL ;
V_24 = 0 ;
break;
case V_410 :
if ( ! V_23 -> V_111 )
break;
F_297 ( V_23 -> V_111 , V_56 ,
& V_23 -> V_112 ) ;
V_56 = NULL ;
if ( V_23 -> V_111 -> V_194 >= V_23 -> V_113 )
break;
V_24 = 0 ;
break;
case V_409 :
if ( ! V_23 -> V_111 )
break;
F_297 ( V_23 -> V_111 , V_56 ,
& V_23 -> V_112 ) ;
V_56 = NULL ;
if ( V_23 -> V_111 -> V_194 != V_23 -> V_113 )
break;
V_24 = V_23 -> V_46 -> V_429 ( V_23 , V_23 -> V_111 ) ;
if ( ! V_24 ) {
V_23 -> V_111 = NULL ;
V_23 -> V_112 = NULL ;
V_23 -> V_113 = 0 ;
}
break;
}
if ( V_24 ) {
F_97 ( V_56 ) ;
F_97 ( V_23 -> V_111 ) ;
V_23 -> V_111 = NULL ;
V_23 -> V_112 = NULL ;
V_23 -> V_113 = 0 ;
}
return V_24 ;
}
static int F_300 ( struct V_11 * V_23 )
{
return 0 ;
}
void F_301 ( struct V_11 * V_23 , int V_607 )
{
T_1 V_419 ;
if ( V_23 -> V_148 != V_151 )
return;
V_419 = V_607 ? V_420 : V_422 ;
F_129 ( V_23 , NULL , NULL , V_419 ) ;
}
static int F_302 ( struct V_11 * V_23 )
{
int V_24 = 0 ;
F_23 ( L_3 , V_23 ) ;
while ( ! F_70 ( V_265 , & V_23 -> V_259 ) ) {
struct V_52 * V_56 ;
F_23 ( L_74 ,
V_23 -> V_266 , F_177 ( & V_23 -> V_152 ) ) ;
V_56 = F_33 ( & V_23 -> V_152 , V_23 -> V_266 ) ;
if ( ! V_56 )
break;
F_208 ( V_56 , & V_23 -> V_152 ) ;
V_23 -> V_266 = F_172 ( V_23 , V_23 -> V_266 ) ;
V_24 = F_299 ( V_23 , V_56 , & F_35 ( V_56 ) -> V_57 ) ;
if ( V_24 )
break;
}
if ( F_170 ( & V_23 -> V_152 ) ) {
V_23 -> V_292 = V_387 ;
F_185 ( V_23 ) ;
}
return V_24 ;
}
static void F_303 ( struct V_11 * V_23 ,
struct V_211 * V_212 )
{
struct V_52 * V_56 ;
F_23 ( L_10 , V_23 , V_212 ) ;
if ( V_212 -> V_213 == V_23 -> V_378 ) {
F_23 ( L_75 , V_212 -> V_213 ) ;
F_86 ( V_23 , V_327 ) ;
return;
}
V_56 = F_33 ( & V_23 -> V_120 , V_212 -> V_213 ) ;
if ( V_56 == NULL ) {
F_23 ( L_76 ,
V_212 -> V_213 ) ;
return;
}
if ( V_23 -> V_96 != 0 && F_35 ( V_56 ) -> V_57 . V_286 >= V_23 -> V_96 ) {
F_23 ( L_21 , V_23 -> V_96 ) ;
F_86 ( V_23 , V_327 ) ;
return;
}
F_117 ( V_294 , & V_23 -> V_259 ) ;
if ( V_212 -> V_221 ) {
F_213 ( V_23 , V_212 ) ;
F_57 ( V_258 , & V_23 -> V_259 ) ;
F_182 ( V_23 , V_212 ) ;
F_173 ( V_23 ) ;
if ( V_23 -> V_290 == V_424 ) {
F_57 ( V_289 , & V_23 -> V_259 ) ;
V_23 -> V_608 = V_212 -> V_213 ;
}
} else {
F_214 ( V_23 , V_212 ) ;
if ( V_212 -> V_216 ) {
if ( V_23 -> V_608 != V_212 -> V_213 ||
! F_116 ( V_289 ,
& V_23 -> V_259 ) )
F_182 ( V_23 , V_212 ) ;
} else {
F_182 ( V_23 , V_212 ) ;
if ( V_23 -> V_290 == V_424 ) {
F_57 ( V_289 , & V_23 -> V_259 ) ;
V_23 -> V_608 = V_212 -> V_213 ;
}
}
}
}
static void F_304 ( struct V_11 * V_23 ,
struct V_211 * V_212 )
{
struct V_52 * V_56 ;
F_23 ( L_10 , V_23 , V_212 ) ;
if ( V_212 -> V_213 == V_23 -> V_378 ) {
F_23 ( L_75 , V_212 -> V_213 ) ;
F_86 ( V_23 , V_327 ) ;
return;
}
V_56 = F_33 ( & V_23 -> V_120 , V_212 -> V_213 ) ;
if ( V_23 -> V_96 && V_56 &&
F_35 ( V_56 ) -> V_57 . V_286 >= V_23 -> V_96 ) {
F_23 ( L_21 , V_23 -> V_96 ) ;
F_86 ( V_23 , V_327 ) ;
return;
}
F_117 ( V_294 , & V_23 -> V_259 ) ;
F_213 ( V_23 , V_212 ) ;
if ( V_212 -> V_216 ) {
if ( ! F_116 ( V_288 , & V_23 -> V_259 ) )
F_183 ( V_23 , V_212 ) ;
} else {
F_183 ( V_23 , V_212 ) ;
F_173 ( V_23 ) ;
if ( V_23 -> V_290 == V_424 )
F_57 ( V_288 , & V_23 -> V_259 ) ;
}
}
static T_1 F_305 ( struct V_11 * V_23 , T_2 V_58 )
{
F_23 ( L_77 , V_23 , V_58 ) ;
F_23 ( L_78 , V_23 -> V_264 ,
V_23 -> V_287 ) ;
if ( V_23 -> V_292 == V_421 ) {
if ( F_186 ( V_23 , V_58 , V_23 -> V_264 ) >=
V_23 -> V_98 ) {
if ( V_23 -> V_98 <= ( ( V_23 -> V_100 + 1 ) >> 1 ) ) {
F_23 ( L_79 ) ;
return V_609 ;
} else {
F_23 ( L_80 ) ;
return V_610 ;
}
}
if ( V_23 -> V_153 . V_54 == V_58 ) {
F_23 ( L_81 ) ;
return V_611 ;
}
if ( F_33 ( & V_23 -> V_152 , V_58 ) ) {
F_23 ( L_82 ) ;
return V_612 ;
}
if ( F_41 ( & V_23 -> V_153 , V_58 ) ) {
F_23 ( L_83 ) ;
return V_613 ;
}
}
if ( V_23 -> V_287 == V_58 ) {
if ( F_186 ( V_23 , V_58 , V_23 -> V_264 ) >=
V_23 -> V_98 ) {
F_23 ( L_84 ) ;
return V_610 ;
} else {
F_23 ( L_85 ) ;
return V_614 ;
}
}
if ( F_186 ( V_23 , V_58 , V_23 -> V_264 ) <
F_186 ( V_23 , V_23 -> V_287 , V_23 -> V_264 ) ) {
F_23 ( L_86 ) ;
return V_615 ;
}
if ( F_186 ( V_23 , V_58 , V_23 -> V_264 ) >= V_23 -> V_98 ) {
if ( V_23 -> V_98 <= ( ( V_23 -> V_100 + 1 ) >> 1 ) ) {
F_23 ( L_87 ) ;
return V_609 ;
} else {
F_23 ( L_84 ) ;
return V_610 ;
}
} else {
F_23 ( L_88 ) ;
return V_616 ;
}
}
static int F_306 ( struct V_11 * V_23 ,
struct V_211 * V_212 ,
struct V_52 * V_56 , T_1 V_419 )
{
int V_24 = 0 ;
bool V_617 = false ;
F_23 ( L_89 , V_23 , V_212 , V_56 ,
V_419 ) ;
switch ( V_419 ) {
case V_618 :
switch ( F_305 ( V_23 , V_212 -> V_58 ) ) {
case V_614 :
F_213 ( V_23 , V_212 ) ;
if ( F_70 ( V_265 , & V_23 -> V_259 ) ) {
F_23 ( L_90 ,
V_212 -> V_58 ) ;
break;
}
V_23 -> V_287 = F_172 ( V_23 ,
V_212 -> V_58 ) ;
V_23 -> V_266 = V_23 -> V_287 ;
V_617 = true ;
V_24 = F_299 ( V_23 , V_56 , V_212 ) ;
if ( V_24 )
break;
if ( V_212 -> V_216 ) {
if ( ! F_116 ( V_288 ,
& V_23 -> V_259 ) ) {
V_212 -> V_216 = 0 ;
F_183 ( V_23 , V_212 ) ;
F_173 ( V_23 ) ;
}
}
if ( ! F_70 ( V_265 , & V_23 -> V_259 ) )
F_185 ( V_23 ) ;
break;
case V_616 :
F_213 ( V_23 , V_212 ) ;
if ( F_70 ( V_265 , & V_23 -> V_259 ) ) {
F_23 ( L_91 ,
V_212 -> V_58 ) ;
break;
}
F_307 ( & V_23 -> V_152 , V_56 ) ;
V_617 = true ;
F_23 ( L_92 , V_56 ,
F_177 ( & V_23 -> V_152 ) ) ;
F_117 ( V_289 , & V_23 -> V_259 ) ;
F_43 ( & V_23 -> V_153 ) ;
F_204 ( V_23 , V_212 -> V_58 ) ;
V_23 -> V_292 = V_421 ;
break;
case V_615 :
F_213 ( V_23 , V_212 ) ;
break;
case V_609 :
break;
case V_610 :
default:
F_86 ( V_23 , V_327 ) ;
break;
}
break;
case V_619 :
F_213 ( V_23 , V_212 ) ;
if ( V_212 -> V_216 ) {
F_117 ( V_294 , & V_23 -> V_259 ) ;
if ( ! F_116 ( V_288 , & V_23 -> V_259 ) &&
! F_95 ( V_23 ) ) {
V_212 -> V_216 = 0 ;
F_183 ( V_23 , V_212 ) ;
}
F_173 ( V_23 ) ;
} else if ( V_212 -> V_221 ) {
F_296 ( V_23 ) ;
} else {
if ( F_116 ( V_294 ,
& V_23 -> V_259 ) &&
V_23 -> V_384 )
F_27 ( V_23 ) ;
F_173 ( V_23 ) ;
}
break;
case V_620 :
F_57 ( V_294 , & V_23 -> V_259 ) ;
F_213 ( V_23 , V_212 ) ;
if ( V_212 && V_212 -> V_221 ) {
F_57 ( V_258 , & V_23 -> V_259 ) ;
F_119 ( V_23 , 0 ) ;
}
F_32 ( V_23 ) ;
F_43 ( & V_23 -> V_154 ) ;
break;
case V_621 :
F_304 ( V_23 , V_212 ) ;
break;
case V_622 :
F_303 ( V_23 , V_212 ) ;
break;
default:
break;
}
if ( V_56 && ! V_617 ) {
F_23 ( L_93 , V_56 ) ;
F_97 ( V_56 ) ;
}
return V_24 ;
}
static int F_308 ( struct V_11 * V_23 ,
struct V_211 * V_212 ,
struct V_52 * V_56 , T_1 V_419 )
{
int V_24 = 0 ;
T_2 V_58 = V_212 -> V_58 ;
bool V_617 = false ;
F_23 ( L_89 , V_23 , V_212 , V_56 ,
V_419 ) ;
switch ( V_419 ) {
case V_618 :
switch ( F_305 ( V_23 , V_58 ) ) {
case V_614 :
F_213 ( V_23 , V_212 ) ;
F_307 ( & V_23 -> V_152 , V_56 ) ;
V_617 = true ;
F_23 ( L_92 , V_56 ,
F_177 ( & V_23 -> V_152 ) ) ;
V_23 -> V_287 = F_172 ( V_23 , V_58 ) ;
break;
case V_611 :
F_42 ( & V_23 -> V_153 ) ;
F_213 ( V_23 , V_212 ) ;
F_307 ( & V_23 -> V_152 , V_56 ) ;
V_617 = true ;
F_23 ( L_92 , V_56 ,
F_177 ( & V_23 -> V_152 ) ) ;
V_24 = F_302 ( V_23 ) ;
if ( V_24 )
break;
break;
case V_616 :
F_307 ( & V_23 -> V_152 , V_56 ) ;
V_617 = true ;
F_23 ( L_92 , V_56 ,
F_177 ( & V_23 -> V_152 ) ) ;
F_213 ( V_23 , V_212 ) ;
F_204 ( V_23 , V_212 -> V_58 ) ;
break;
case V_613 :
F_307 ( & V_23 -> V_152 , V_56 ) ;
V_617 = true ;
F_23 ( L_92 , V_56 ,
F_177 ( & V_23 -> V_152 ) ) ;
F_213 ( V_23 , V_212 ) ;
F_206 ( V_23 , V_212 -> V_58 ) ;
break;
case V_612 :
F_213 ( V_23 , V_212 ) ;
break;
case V_615 :
break;
case V_609 :
break;
case V_610 :
default:
F_86 ( V_23 , V_327 ) ;
break;
}
break;
case V_619 :
F_213 ( V_23 , V_212 ) ;
if ( V_212 -> V_216 ) {
F_117 ( V_294 , & V_23 -> V_259 ) ;
if ( ! F_116 ( V_288 ,
& V_23 -> V_259 ) ) {
V_212 -> V_216 = 0 ;
F_183 ( V_23 , V_212 ) ;
}
F_173 ( V_23 ) ;
} else if ( V_212 -> V_221 ) {
if ( F_116 ( V_294 ,
& V_23 -> V_259 ) &&
V_23 -> V_384 ) {
F_27 ( V_23 ) ;
}
F_57 ( V_258 , & V_23 -> V_259 ) ;
F_205 ( V_23 ) ;
} else {
if ( F_116 ( V_294 ,
& V_23 -> V_259 ) &&
V_23 -> V_384 )
F_27 ( V_23 ) ;
F_185 ( V_23 ) ;
}
break;
case V_620 :
F_57 ( V_294 , & V_23 -> V_259 ) ;
F_213 ( V_23 , V_212 ) ;
if ( V_212 -> V_221 ) {
F_205 ( V_23 ) ;
} else {
struct V_211 V_623 ;
memset ( & V_623 , 0 , sizeof( V_623 ) ) ;
V_623 . V_220 = 1 ;
V_623 . V_224 = V_260 ;
V_623 . V_213 = V_23 -> V_266 ;
F_115 ( V_23 , & V_623 ) ;
}
break;
case V_621 :
F_304 ( V_23 , V_212 ) ;
break;
case V_622 :
F_303 ( V_23 , V_212 ) ;
break;
}
if ( V_56 && ! V_617 ) {
F_23 ( L_93 , V_56 ) ;
F_97 ( V_56 ) ;
}
return V_24 ;
}
static int F_309 ( struct V_11 * V_23 )
{
F_23 ( L_3 , V_23 ) ;
V_23 -> V_292 = V_387 ;
if ( V_23 -> V_207 )
V_23 -> V_13 -> V_165 = V_23 -> V_207 -> V_196 -> V_544 ;
else
V_23 -> V_13 -> V_165 = V_23 -> V_13 -> V_8 -> V_196 -> V_624 ;
return F_300 ( V_23 ) ;
}
static int F_310 ( struct V_11 * V_23 ,
struct V_211 * V_212 ,
struct V_52 * V_56 , T_1 V_419 )
{
int V_24 ;
F_23 ( L_89 , V_23 , V_212 , V_56 ,
V_419 ) ;
if ( ! V_212 -> V_221 )
return - V_507 ;
F_207 ( V_23 , V_212 -> V_213 ) ;
if ( ! F_170 ( & V_23 -> V_120 ) )
V_23 -> V_383 = F_211 ( & V_23 -> V_120 ) ;
else
V_23 -> V_383 = NULL ;
V_23 -> V_378 = V_212 -> V_213 ;
V_23 -> V_384 = 0 ;
V_24 = F_309 ( V_23 ) ;
if ( V_24 )
return V_24 ;
F_57 ( V_258 , & V_23 -> V_259 ) ;
F_296 ( V_23 ) ;
if ( V_419 == V_618 )
return - V_507 ;
return F_306 ( V_23 , V_212 , NULL , V_419 ) ;
}
static int F_311 ( struct V_11 * V_23 ,
struct V_211 * V_212 ,
struct V_52 * V_56 , T_1 V_419 )
{
int V_24 ;
if ( ! V_212 -> V_216 )
return - V_507 ;
F_117 ( V_294 , & V_23 -> V_259 ) ;
V_23 -> V_292 = V_387 ;
F_207 ( V_23 , V_212 -> V_213 ) ;
if ( ! F_170 ( & V_23 -> V_120 ) )
V_23 -> V_383 = F_211 ( & V_23 -> V_120 ) ;
else
V_23 -> V_383 = NULL ;
V_23 -> V_378 = V_212 -> V_213 ;
V_23 -> V_384 = 0 ;
if ( V_23 -> V_207 )
V_23 -> V_13 -> V_165 = V_23 -> V_207 -> V_196 -> V_544 ;
else
V_23 -> V_13 -> V_165 = V_23 -> V_13 -> V_8 -> V_196 -> V_624 ;
V_24 = F_300 ( V_23 ) ;
if ( ! V_24 )
V_24 = F_306 ( V_23 , V_212 , V_56 , V_419 ) ;
return V_24 ;
}
static bool F_312 ( struct V_11 * V_23 , T_2 V_213 )
{
T_2 V_625 ;
V_625 = F_186 ( V_23 , V_23 -> V_378 , V_23 -> V_418 ) ;
return F_186 ( V_23 , V_23 -> V_378 , V_213 ) <= V_625 ;
}
static int F_313 ( struct V_11 * V_23 , struct V_211 * V_212 ,
struct V_52 * V_56 , T_1 V_419 )
{
int V_24 = 0 ;
F_23 ( L_94 , V_23 ,
V_212 , V_56 , V_419 , V_23 -> V_292 ) ;
if ( F_312 ( V_23 , V_212 -> V_213 ) ) {
switch ( V_23 -> V_292 ) {
case V_387 :
V_24 = F_306 ( V_23 , V_212 , V_56 , V_419 ) ;
break;
case V_421 :
V_24 = F_308 ( V_23 , V_212 , V_56 ,
V_419 ) ;
break;
case V_301 :
V_24 = F_310 ( V_23 , V_212 , V_56 , V_419 ) ;
break;
case V_299 :
V_24 = F_311 ( V_23 , V_212 , V_56 , V_419 ) ;
break;
default:
break;
}
} else {
F_23 ( L_95 ,
V_212 -> V_213 , V_23 -> V_378 ,
V_23 -> V_418 ) ;
F_86 ( V_23 , V_327 ) ;
}
return V_24 ;
}
static int F_314 ( struct V_11 * V_23 , struct V_211 * V_212 ,
struct V_52 * V_56 )
{
F_23 ( L_96 , V_23 , V_212 , V_56 ,
V_23 -> V_292 ) ;
if ( F_305 ( V_23 , V_212 -> V_58 ) ==
V_614 ) {
F_213 ( V_23 , V_212 ) ;
F_23 ( L_97 , V_23 -> V_266 ,
F_172 ( V_23 , V_23 -> V_266 ) ) ;
V_23 -> V_266 = F_172 ( V_23 , V_23 -> V_266 ) ;
F_299 ( V_23 , V_56 , V_212 ) ;
} else {
if ( V_23 -> V_111 ) {
F_97 ( V_23 -> V_111 ) ;
V_23 -> V_111 = NULL ;
}
V_23 -> V_112 = NULL ;
V_23 -> V_113 = 0 ;
if ( V_56 ) {
F_23 ( L_93 , V_56 ) ;
F_97 ( V_56 ) ;
}
}
V_23 -> V_264 = V_212 -> V_58 ;
V_23 -> V_287 = F_172 ( V_23 , V_212 -> V_58 ) ;
return 0 ;
}
static int F_315 ( struct V_11 * V_23 , struct V_52 * V_56 )
{
struct V_211 * V_212 = & F_35 ( V_56 ) -> V_57 ;
T_2 V_194 ;
T_1 V_419 ;
F_100 ( V_23 , V_56 ) ;
V_194 = V_56 -> V_194 ;
if ( F_294 ( V_23 , V_56 ) )
goto V_599;
if ( ! V_212 -> V_220 && V_212 -> V_227 == V_408 )
V_194 -= V_402 ;
if ( V_23 -> V_94 == V_95 )
V_194 -= V_256 ;
if ( V_194 > V_23 -> V_117 ) {
F_86 ( V_23 , V_327 ) ;
goto V_599;
}
if ( ! V_212 -> V_220 ) {
int V_24 ;
F_23 ( L_98 ,
V_212 -> V_227 , V_212 -> V_213 , V_212 -> V_216 ,
V_212 -> V_58 ) ;
if ( V_212 -> V_216 && V_23 -> V_290 != V_424 )
goto V_599;
if ( V_23 -> V_148 != V_155 ) {
V_419 = V_618 ;
V_24 = F_313 ( V_23 , V_212 , V_56 , V_419 ) ;
} else {
V_24 = F_314 ( V_23 , V_212 , V_56 ) ;
}
if ( V_24 )
F_86 ( V_23 , V_327 ) ;
} else {
const T_1 V_626 [ 4 ] = {
V_619 , V_621 ,
V_620 , V_622
} ;
if ( V_23 -> V_148 == V_155 )
goto V_599;
F_23 ( L_99 ,
V_212 -> V_213 , V_212 -> V_216 , V_212 -> V_221 ,
V_212 -> V_224 ) ;
if ( V_194 != 0 ) {
F_286 ( L_100 , V_194 ) ;
F_86 ( V_23 , V_327 ) ;
goto V_599;
}
if ( V_212 -> V_216 && ( V_212 -> V_221 ||
V_23 -> V_290 != V_424 ) )
goto V_599;
V_419 = V_626 [ V_212 -> V_224 ] ;
if ( F_313 ( V_23 , V_212 , V_56 , V_419 ) )
F_86 ( V_23 , V_327 ) ;
}
return 0 ;
V_599:
F_97 ( V_56 ) ;
return 0 ;
}
static void F_316 ( struct V_11 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
struct F_289 V_594 ;
T_2 V_627 ;
if ( V_23 -> V_115 >= ( V_116 + 1 ) / 2 )
return;
V_627 = V_116 - V_23 -> V_115 ;
F_23 ( L_101 , V_23 , V_627 ) ;
V_23 -> V_115 += V_627 ;
V_594 . V_14 = F_18 ( V_23 -> V_17 ) ;
V_594 . V_166 = F_18 ( V_627 ) ;
V_23 -> V_19 = F_91 ( V_13 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_598 , sizeof( V_594 ) , & V_594 ) ;
}
static int F_317 ( struct V_11 * V_23 , struct V_52 * V_56 )
{
int V_24 ;
if ( ! V_23 -> V_115 ) {
F_286 ( L_102 ) ;
F_86 ( V_23 , V_327 ) ;
return - V_628 ;
}
if ( V_23 -> V_118 < V_56 -> V_194 ) {
F_286 ( L_103 ) ;
return - V_628 ;
}
V_23 -> V_115 -- ;
F_23 ( L_104 , V_23 -> V_115 + 1 , V_23 -> V_115 ) ;
F_316 ( V_23 ) ;
V_24 = 0 ;
if ( ! V_23 -> V_111 ) {
T_2 V_113 ;
V_113 = F_103 ( V_56 -> V_195 ) ;
F_102 ( V_56 , V_402 ) ;
F_23 ( L_105 ,
V_113 , V_56 -> V_194 , V_23 -> V_118 ) ;
if ( V_113 > V_23 -> V_118 ) {
F_286 ( L_106 ) ;
V_24 = - V_411 ;
goto V_629;
}
if ( V_56 -> V_194 > V_113 ) {
F_286 ( L_107 ) ;
V_24 = - V_36 ;
goto V_629;
}
if ( V_56 -> V_194 == V_113 )
return V_23 -> V_46 -> V_429 ( V_23 , V_56 ) ;
V_23 -> V_111 = V_56 ;
V_23 -> V_113 = V_113 ;
V_23 -> V_112 = V_56 ;
return 0 ;
}
F_23 ( L_108 ,
V_23 -> V_111 -> V_194 , V_56 -> V_194 , V_23 -> V_113 ) ;
if ( V_23 -> V_111 -> V_194 + V_56 -> V_194 > V_23 -> V_113 ) {
F_286 ( L_107 ) ;
V_24 = - V_36 ;
goto V_629;
}
F_297 ( V_23 -> V_111 , V_56 , & V_23 -> V_112 ) ;
V_56 = NULL ;
if ( V_23 -> V_111 -> V_194 == V_23 -> V_113 ) {
V_24 = V_23 -> V_46 -> V_429 ( V_23 , V_23 -> V_111 ) ;
if ( ! V_24 ) {
V_23 -> V_111 = NULL ;
V_23 -> V_112 = NULL ;
V_23 -> V_113 = 0 ;
}
}
V_629:
if ( V_24 ) {
F_97 ( V_56 ) ;
F_97 ( V_23 -> V_111 ) ;
V_23 -> V_111 = NULL ;
V_23 -> V_112 = NULL ;
V_23 -> V_113 = 0 ;
}
return 0 ;
}
static void F_318 ( struct V_12 * V_13 , T_2 V_14 ,
struct V_52 * V_56 )
{
struct V_11 * V_23 ;
V_23 = F_7 ( V_13 , V_14 ) ;
if ( ! V_23 ) {
if ( V_14 == V_323 ) {
V_23 = F_319 ( V_13 , V_56 ) ;
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
F_23 ( L_110 , V_23 , V_56 -> V_194 ) ;
if ( V_23 -> V_39 == V_40 )
F_130 ( V_23 ) ;
if ( V_23 -> V_45 != V_75 )
goto V_599;
switch ( V_23 -> V_148 ) {
case V_150 :
if ( F_317 ( V_23 , V_56 ) < 0 )
goto V_599;
goto V_27;
case V_149 :
if ( V_23 -> V_118 < V_56 -> V_194 ) {
F_286 ( L_111 ) ;
goto V_599;
}
if ( ! V_23 -> V_46 -> V_429 ( V_23 , V_56 ) )
goto V_27;
break;
case V_151 :
case V_155 :
F_315 ( V_23 , V_56 ) ;
goto V_27;
default:
F_23 ( L_112 , V_23 , V_23 -> V_148 ) ;
break;
}
V_599:
F_97 ( V_56 ) ;
V_27:
F_48 ( V_23 ) ;
}
static void F_320 ( struct V_12 * V_13 , T_3 V_20 ,
struct V_52 * V_56 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_11 * V_23 ;
if ( V_8 -> type != V_124 )
goto V_630;
V_23 = F_165 ( 0 , V_20 , & V_8 -> V_21 , & V_8 -> V_157 ,
V_124 ) ;
if ( ! V_23 )
goto V_630;
F_23 ( L_110 , V_23 , V_56 -> V_194 ) ;
if ( V_23 -> V_45 != V_631 && V_23 -> V_45 != V_75 )
goto V_599;
if ( V_23 -> V_118 < V_56 -> V_194 )
goto V_599;
F_81 ( & F_35 ( V_56 ) -> V_57 . V_632 , & V_8 -> V_157 ) ;
F_35 ( V_56 ) -> V_57 . V_20 = V_20 ;
if ( ! V_23 -> V_46 -> V_429 ( V_23 , V_56 ) ) {
F_49 ( V_23 ) ;
return;
}
V_599:
F_49 ( V_23 ) ;
V_630:
F_97 ( V_56 ) ;
}
static void F_321 ( struct V_12 * V_13 , struct V_52 * V_56 )
{
struct V_253 * V_254 = ( void * ) V_56 -> V_195 ;
struct V_7 * V_8 = V_13 -> V_8 ;
T_2 V_14 , V_194 ;
T_3 V_20 ;
if ( V_8 -> V_45 != V_75 ) {
F_23 ( L_113 ) ;
F_307 ( & V_13 -> V_366 , V_56 ) ;
return;
}
F_102 ( V_56 , V_250 ) ;
V_14 = F_69 ( V_254 -> V_14 ) ;
V_194 = F_69 ( V_254 -> V_194 ) ;
if ( V_194 != V_56 -> V_194 ) {
F_97 ( V_56 ) ;
return;
}
if ( V_8 -> type == V_2 &&
F_322 ( & V_8 -> V_196 -> V_633 , & V_8 -> V_157 ,
F_3 ( V_8 ) ) ) {
F_97 ( V_56 ) ;
return;
}
F_23 ( L_114 , V_194 , V_14 ) ;
switch ( V_14 ) {
case V_127 :
F_293 ( V_13 , V_56 ) ;
break;
case V_126 :
V_20 = F_323 ( ( T_3 * ) V_56 -> V_195 ) ;
F_102 ( V_56 , V_400 ) ;
F_320 ( V_13 , V_20 , V_56 ) ;
break;
case V_434 :
F_292 ( V_13 , V_56 ) ;
break;
default:
F_318 ( V_13 , V_14 , V_56 ) ;
break;
}
}
static void F_324 ( struct V_71 * V_72 )
{
struct V_12 * V_13 = F_46 ( V_72 , struct V_12 ,
V_354 ) ;
struct V_52 * V_56 ;
F_23 ( L_115 ) ;
while ( ( V_56 = F_171 ( & V_13 -> V_366 ) ) )
F_321 ( V_13 , V_56 ) ;
}
static struct V_12 * F_325 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_363 ;
struct V_147 * V_203 ;
if ( V_13 )
return V_13 ;
V_203 = F_326 ( V_8 ) ;
if ( ! V_203 )
return NULL ;
V_13 = F_51 ( sizeof( * V_13 ) , V_65 ) ;
if ( ! V_13 ) {
F_159 ( V_203 ) ;
return NULL ;
}
F_56 ( & V_13 -> V_368 ) ;
V_8 -> V_363 = V_13 ;
V_13 -> V_8 = F_327 ( V_8 ) ;
V_13 -> V_203 = V_203 ;
F_23 ( L_116 , V_8 , V_13 , V_203 ) ;
switch ( V_8 -> type ) {
case V_2 :
if ( V_8 -> V_196 -> V_634 ) {
V_13 -> V_165 = V_8 -> V_196 -> V_634 ;
break;
}
default:
V_13 -> V_165 = V_8 -> V_196 -> V_624 ;
break;
}
V_13 -> V_316 = 0 ;
V_13 -> V_270 = V_635 | V_636 ;
if ( V_8 -> type == V_124 &&
F_241 ( V_8 -> V_196 , V_637 ) )
V_13 -> V_270 |= V_271 ;
if ( F_241 ( V_8 -> V_196 , V_638 ) &&
( F_328 ( V_8 -> V_196 ) ||
F_241 ( V_8 -> V_196 , V_639 ) ) )
V_13 -> V_270 |= V_640 ;
F_52 ( & V_13 -> V_191 ) ;
F_52 ( & V_13 -> V_18 ) ;
F_329 ( & V_13 -> V_141 ) ;
F_329 ( & V_13 -> V_362 ) ;
F_55 ( & V_13 -> V_312 , F_147 ) ;
F_67 ( & V_13 -> V_366 ) ;
F_330 ( & V_13 -> V_354 , F_324 ) ;
F_330 ( & V_13 -> V_156 , F_80 ) ;
V_13 -> V_121 = V_122 ;
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
T_4 * V_157 , T_1 V_10 )
{
struct V_12 * V_13 ;
struct V_7 * V_8 ;
struct V_268 * V_196 ;
int V_24 ;
F_23 ( L_117 , & V_23 -> V_21 , V_157 ,
V_10 , F_69 ( V_20 ) ) ;
V_196 = F_334 ( V_157 , & V_23 -> V_21 ) ;
if ( ! V_196 )
return - V_641 ;
F_149 ( V_196 ) ;
if ( ! F_331 ( F_69 ( V_20 ) , V_10 ) && ! V_14 &&
V_23 -> V_39 != V_176 ) {
V_24 = - V_36 ;
goto V_27;
}
if ( V_23 -> V_39 == V_123 && ! V_20 ) {
V_24 = - V_36 ;
goto V_27;
}
if ( V_23 -> V_39 == V_40 && ! V_14 ) {
V_24 = - V_36 ;
goto V_27;
}
switch ( V_23 -> V_148 ) {
case V_149 :
break;
case V_150 :
F_65 ( V_23 ) ;
break;
case V_151 :
case V_155 :
if ( ! V_319 )
break;
default:
V_24 = - V_642 ;
goto V_27;
}
switch ( V_23 -> V_45 ) {
case V_78 :
case V_175 :
case V_76 :
V_24 = 0 ;
goto V_27;
case V_75 :
V_24 = - V_643 ;
goto V_27;
case V_89 :
case V_631 :
break;
default:
V_24 = - V_414 ;
goto V_27;
}
F_81 ( & V_23 -> V_157 , V_157 ) ;
V_23 -> V_10 = V_10 ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_14 ;
if ( F_332 ( V_10 ) ) {
if ( V_10 == V_4 )
V_10 = V_3 ;
else
V_10 = V_644 ;
if ( F_241 ( V_196 , V_645 ) )
V_8 = F_335 ( V_196 , V_157 , V_10 ,
V_23 -> V_79 ,
V_646 ,
V_341 ) ;
else
V_8 = F_336 ( V_196 , V_157 , V_10 ,
V_23 -> V_79 ,
V_646 ) ;
} else {
T_1 V_189 = F_87 ( V_23 ) ;
V_8 = F_337 ( V_196 , V_157 , V_23 -> V_79 , V_189 ) ;
}
if ( F_118 ( V_8 ) ) {
V_24 = F_191 ( V_8 ) ;
goto V_27;
}
V_13 = F_325 ( V_8 ) ;
if ( ! V_13 ) {
F_75 ( V_8 ) ;
V_24 = - V_66 ;
goto V_27;
}
F_8 ( & V_13 -> V_18 ) ;
F_9 ( V_23 ) ;
if ( V_14 && F_4 ( V_13 , V_14 ) ) {
F_75 ( V_8 ) ;
V_24 = - V_647 ;
goto V_648;
}
F_81 ( & V_23 -> V_21 , & V_8 -> V_21 ) ;
V_23 -> V_9 = F_2 ( V_8 ) ;
F_68 ( V_13 , V_23 ) ;
F_75 ( V_8 ) ;
F_22 ( V_23 , V_78 ) ;
F_85 ( V_23 , V_23 -> V_46 -> V_174 ( V_23 ) ) ;
F_17 ( & V_25 ) ;
V_23 -> V_22 = 0 ;
F_19 ( & V_25 ) ;
if ( V_8 -> V_45 == V_75 ) {
if ( V_23 -> V_39 != V_123 ) {
F_74 ( V_23 ) ;
if ( F_88 ( V_23 , true ) )
F_22 ( V_23 , V_75 ) ;
} else
F_138 ( V_23 ) ;
}
V_24 = 0 ;
V_648:
F_48 ( V_23 ) ;
F_10 ( & V_13 -> V_18 ) ;
V_27:
F_151 ( V_196 ) ;
F_257 ( V_196 ) ;
return V_24 ;
}
int F_338 ( struct V_268 * V_196 , T_4 * V_632 )
{
int V_649 = 0 , V_650 = 0 , V_651 = 0 ;
struct V_11 * V_15 ;
F_23 ( L_118 , V_196 -> V_337 , V_632 ) ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
if ( V_15 -> V_45 != V_173 )
continue;
if ( ! F_15 ( & V_15 -> V_21 , & V_196 -> V_632 ) ) {
V_650 |= V_652 ;
if ( F_70 ( V_653 , & V_15 -> V_110 ) )
V_650 |= V_654 ;
V_649 ++ ;
} else if ( ! F_15 ( & V_15 -> V_21 , V_374 ) ) {
V_651 |= V_652 ;
if ( F_70 ( V_653 , & V_15 -> V_110 ) )
V_651 |= V_654 ;
}
}
F_123 ( & V_25 ) ;
return V_649 ? V_650 : V_651 ;
}
static struct V_11 * F_339 ( struct V_11 * V_15 ,
struct V_7 * V_8 )
{
T_1 V_9 = F_2 ( V_8 ) ;
F_122 ( & V_25 ) ;
if ( V_15 )
V_15 = F_340 ( V_15 , V_87 ) ;
else
V_15 = F_341 ( V_88 . V_399 , F_342 ( * V_15 ) , V_87 ) ;
F_343 (c, &chan_list, global_l) {
if ( V_15 -> V_39 != V_40 )
continue;
if ( V_15 -> V_45 != V_173 )
continue;
if ( F_15 ( & V_15 -> V_21 , & V_8 -> V_21 ) && F_15 ( & V_15 -> V_21 , V_374 ) )
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
static void F_344 ( struct V_7 * V_8 , T_1 V_170 )
{
struct V_268 * V_196 = V_8 -> V_196 ;
struct V_12 * V_13 ;
struct V_11 * V_509 ;
T_1 V_10 ;
if ( V_8 -> type != V_124 && V_8 -> type != V_2 )
return;
F_23 ( L_119 , V_8 , & V_8 -> V_157 , V_170 ) ;
if ( V_170 ) {
F_156 ( V_8 , F_345 ( V_170 ) ) ;
return;
}
V_13 = F_325 ( V_8 ) ;
if ( ! V_13 )
return;
V_10 = F_3 ( V_8 ) ;
if ( F_322 ( & V_196 -> V_633 , & V_8 -> V_157 , V_10 ) )
return;
V_509 = F_339 ( NULL , V_8 ) ;
while ( V_509 ) {
struct V_11 * V_23 , * V_399 ;
if ( F_4 ( V_13 , V_509 -> V_17 ) )
goto V_399;
F_9 ( V_509 ) ;
V_23 = V_509 -> V_46 -> V_514 ( V_509 ) ;
if ( V_23 ) {
F_81 ( & V_23 -> V_21 , & V_8 -> V_21 ) ;
F_81 ( & V_23 -> V_157 , & V_8 -> V_157 ) ;
V_23 -> V_9 = F_2 ( V_8 ) ;
V_23 -> V_10 = V_10 ;
F_68 ( V_13 , V_23 ) ;
}
F_48 ( V_509 ) ;
V_399:
V_399 = F_339 ( V_509 , V_8 ) ;
F_49 ( V_509 ) ;
V_509 = V_399 ;
}
F_144 ( V_13 ) ;
}
int F_346 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_363 ;
F_23 ( L_120 , V_8 ) ;
if ( ! V_13 )
return V_122 ;
return V_13 -> V_121 ;
}
static void F_347 ( struct V_7 * V_8 , T_1 V_74 )
{
if ( V_8 -> type != V_124 && V_8 -> type != V_2 )
return;
F_23 ( L_121 , V_8 , V_74 ) ;
F_156 ( V_8 , F_345 ( V_74 ) ) ;
}
static inline void F_348 ( struct V_11 * V_23 , T_1 V_655 )
{
if ( V_23 -> V_39 != V_123 )
return;
if ( V_655 == 0x00 ) {
if ( V_23 -> V_79 == V_180 ) {
F_85 ( V_23 , V_656 ) ;
} else if ( V_23 -> V_79 == V_177 ||
V_23 -> V_79 == V_178 )
F_47 ( V_23 , V_77 ) ;
} else {
if ( V_23 -> V_79 == V_180 )
F_74 ( V_23 ) ;
}
}
static void F_349 ( struct V_7 * V_8 , T_1 V_170 , T_1 V_655 )
{
struct V_12 * V_13 = V_8 -> V_363 ;
struct V_11 * V_23 ;
if ( ! V_13 )
return;
F_23 ( L_122 , V_13 , V_170 , V_655 ) ;
F_8 ( & V_13 -> V_18 ) ;
F_5 (chan, &conn->chan_l, list) {
F_9 ( V_23 ) ;
F_23 ( L_123 , V_23 , V_23 -> V_17 ,
F_24 ( V_23 -> V_45 ) ) ;
if ( V_23 -> V_17 == V_323 ) {
F_48 ( V_23 ) ;
continue;
}
if ( ! V_170 && V_655 )
V_23 -> V_79 = V_8 -> V_79 ;
if ( ! F_120 ( V_23 ) ) {
F_48 ( V_23 ) ;
continue;
}
if ( ! V_170 && ( V_23 -> V_45 == V_75 ||
V_23 -> V_45 == V_76 ) ) {
V_23 -> V_46 -> V_597 ( V_23 ) ;
F_348 ( V_23 , V_655 ) ;
F_48 ( V_23 ) ;
continue;
}
if ( V_23 -> V_45 == V_78 ) {
if ( ! V_170 )
F_134 ( V_23 ) ;
else
F_85 ( V_23 , V_657 ) ;
} else if ( V_23 -> V_45 == V_175 &&
V_23 -> V_148 != V_150 ) {
struct V_168 V_159 ;
T_5 V_658 , V_659 ;
if ( ! V_170 ) {
if ( F_70 ( V_161 , & V_23 -> V_110 ) ) {
V_658 = V_329 ;
V_659 = V_330 ;
V_23 -> V_46 -> V_331 ( V_23 ) ;
} else {
F_22 ( V_23 , V_76 ) ;
V_658 = V_332 ;
V_659 = V_171 ;
}
} else {
F_22 ( V_23 , V_164 ) ;
F_85 ( V_23 , V_657 ) ;
V_658 = V_169 ;
V_659 = V_171 ;
}
V_159 . V_17 = F_18 ( V_23 -> V_16 ) ;
V_159 . V_16 = F_18 ( V_23 -> V_17 ) ;
V_159 . V_160 = F_18 ( V_658 ) ;
V_159 . V_170 = F_18 ( V_659 ) ;
F_83 ( V_13 , V_23 -> V_19 , V_172 ,
sizeof( V_159 ) , & V_159 ) ;
if ( ! F_70 ( V_334 , & V_23 -> V_92 ) &&
V_658 == V_332 ) {
char V_328 [ 128 ] ;
F_57 ( V_334 , & V_23 -> V_92 ) ;
F_83 ( V_13 , F_91 ( V_13 ) ,
V_335 ,
F_142 ( V_23 , V_328 ) ,
V_328 ) ;
V_23 -> V_336 ++ ;
}
}
F_48 ( V_23 ) ;
}
F_10 ( & V_13 -> V_18 ) ;
}
void F_350 ( struct V_7 * V_8 , struct V_52 * V_56 , T_2 V_110 )
{
struct V_12 * V_13 = V_8 -> V_363 ;
struct V_253 * V_660 ;
int V_194 ;
if ( ! V_13 && V_8 -> V_196 -> V_541 != V_661 )
goto V_599;
if ( ! V_13 )
V_13 = F_325 ( V_8 ) ;
if ( ! V_13 )
goto V_599;
F_23 ( L_124 , V_13 , V_56 -> V_194 , V_110 ) ;
switch ( V_110 ) {
case V_198 :
case V_197 :
case V_208 :
if ( V_13 -> V_662 ) {
F_286 ( L_125 , V_56 -> V_194 ) ;
F_97 ( V_13 -> V_365 ) ;
V_13 -> V_365 = NULL ;
V_13 -> V_662 = 0 ;
F_146 ( V_13 , V_663 ) ;
}
if ( V_56 -> V_194 < V_250 ) {
F_286 ( L_126 , V_56 -> V_194 ) ;
F_146 ( V_13 , V_663 ) ;
goto V_599;
}
V_660 = (struct V_253 * ) V_56 -> V_195 ;
V_194 = F_69 ( V_660 -> V_194 ) + V_250 ;
if ( V_194 == V_56 -> V_194 ) {
F_321 ( V_13 , V_56 ) ;
return;
}
F_23 ( L_127 , V_194 , V_56 -> V_194 ) ;
if ( V_56 -> V_194 > V_194 ) {
F_286 ( L_128 ,
V_56 -> V_194 , V_194 ) ;
F_146 ( V_13 , V_663 ) ;
goto V_599;
}
V_13 -> V_365 = F_111 ( V_194 , V_65 ) ;
if ( ! V_13 -> V_365 )
goto V_599;
F_351 ( V_56 , F_113 ( V_13 -> V_365 , V_56 -> V_194 ) ,
V_56 -> V_194 ) ;
V_13 -> V_662 = V_194 - V_56 -> V_194 ;
break;
case V_664 :
F_23 ( L_129 , V_56 -> V_194 , V_13 -> V_662 ) ;
if ( ! V_13 -> V_662 ) {
F_286 ( L_130 , V_56 -> V_194 ) ;
F_146 ( V_13 , V_663 ) ;
goto V_599;
}
if ( V_56 -> V_194 > V_13 -> V_662 ) {
F_286 ( L_131 ,
V_56 -> V_194 , V_13 -> V_662 ) ;
F_97 ( V_13 -> V_365 ) ;
V_13 -> V_365 = NULL ;
V_13 -> V_662 = 0 ;
F_146 ( V_13 , V_663 ) ;
goto V_599;
}
F_351 ( V_56 , F_113 ( V_13 -> V_365 , V_56 -> V_194 ) ,
V_56 -> V_194 ) ;
V_13 -> V_662 -= V_56 -> V_194 ;
if ( ! V_13 -> V_662 ) {
struct V_52 * V_365 = V_13 -> V_365 ;
V_13 -> V_365 = NULL ;
F_321 ( V_13 , V_365 ) ;
}
break;
}
V_599:
F_97 ( V_56 ) ;
}
static int F_352 ( struct V_665 * V_666 , void * V_28 )
{
struct V_11 * V_15 ;
F_122 ( & V_25 ) ;
F_5 (c, &chan_list, global_l) {
F_353 ( V_666 , L_132 ,
& V_15 -> V_21 , V_15 -> V_9 , & V_15 -> V_157 , V_15 -> V_10 ,
V_15 -> V_45 , F_69 ( V_15 -> V_20 ) ,
V_15 -> V_17 , V_15 -> V_16 , V_15 -> V_118 , V_15 -> V_37 ,
V_15 -> V_79 , V_15 -> V_148 ) ;
}
F_123 ( & V_25 ) ;
return 0 ;
}
static int F_354 ( struct V_667 * V_667 , struct V_668 * V_668 )
{
return F_355 ( V_668 , F_352 , V_667 -> V_669 ) ;
}
int T_11 F_356 ( void )
{
int V_24 ;
V_24 = F_357 () ;
if ( V_24 < 0 )
return V_24 ;
F_358 ( & V_670 ) ;
if ( F_359 ( V_671 ) )
return 0 ;
V_672 = F_360 ( L_133 , 0444 , V_671 ,
NULL , & V_673 ) ;
F_361 ( L_134 , 0644 , V_671 ,
& V_116 ) ;
F_361 ( L_135 , 0644 , V_671 ,
& V_119 ) ;
return 0 ;
}
void F_362 ( void )
{
F_363 ( V_672 ) ;
F_364 ( & V_670 ) ;
F_365 () ;
}
