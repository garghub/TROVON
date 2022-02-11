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
V_20 -> V_27 = V_28 ;
V_20 -> V_29 = V_30 ;
V_20 -> V_14 = V_14 ;
F_17 ( & V_22 ) ;
return 0 ;
}
static T_2 F_19 ( struct V_9 * V_10 )
{
T_2 V_11 , V_31 ;
if ( V_10 -> V_2 -> type == V_3 )
V_31 = V_32 ;
else
V_31 = V_33 ;
for ( V_11 = V_34 ; V_11 < V_31 ; V_11 ++ ) {
if ( ! F_4 ( V_10 , V_11 ) )
return V_11 ;
}
return 0 ;
}
static void F_20 ( struct V_8 * V_20 , int V_35 )
{
F_21 ( L_1 , V_20 , F_22 ( V_20 -> V_35 ) ,
F_22 ( V_35 ) ) ;
V_20 -> V_35 = V_35 ;
V_20 -> V_36 -> V_37 ( V_20 , V_35 , 0 ) ;
}
static inline void F_23 ( struct V_8 * V_20 ,
int V_35 , int V_21 )
{
V_20 -> V_35 = V_35 ;
V_20 -> V_36 -> V_37 ( V_20 , V_20 -> V_35 , V_21 ) ;
}
static inline void F_24 ( struct V_8 * V_20 , int V_21 )
{
V_20 -> V_36 -> V_37 ( V_20 , V_20 -> V_35 , V_21 ) ;
}
static void F_25 ( struct V_8 * V_20 )
{
if ( ! F_26 ( & V_20 -> V_38 ) &&
V_20 -> V_39 ) {
F_27 ( V_20 , & V_20 -> V_40 ,
F_28 ( V_20 -> V_39 ) ) ;
}
}
static void F_29 ( struct V_8 * V_20 )
{
F_30 ( V_20 ) ;
if ( V_20 -> V_41 ) {
F_27 ( V_20 , & V_20 -> V_38 ,
F_28 ( V_20 -> V_41 ) ) ;
}
}
static struct V_42 * F_31 ( struct V_43 * V_44 ,
T_2 V_45 )
{
struct V_42 * V_46 ;
F_32 (head, skb) {
if ( F_33 ( V_46 ) -> V_47 . V_48 == V_45 )
return V_46 ;
}
return NULL ;
}
static int F_34 ( struct V_49 * V_50 , T_2 V_51 )
{
T_7 V_52 , V_53 ;
V_52 = F_35 ( V_51 ) ;
V_50 -> V_54 = F_36 ( sizeof( T_2 ) * V_52 , V_55 ) ;
if ( ! V_50 -> V_54 )
return - V_56 ;
V_50 -> V_57 = V_52 - 1 ;
V_50 -> V_44 = V_58 ;
V_50 -> V_59 = V_58 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ )
V_50 -> V_54 [ V_53 ] = V_58 ;
return 0 ;
}
static inline void F_37 ( struct V_49 * V_50 )
{
F_38 ( V_50 -> V_54 ) ;
}
static inline bool F_39 ( struct V_49 * V_50 ,
T_2 V_45 )
{
return V_50 -> V_54 [ V_45 & V_50 -> V_57 ] != V_58 ;
}
static inline T_2 F_40 ( struct V_49 * V_50 )
{
T_2 V_45 = V_50 -> V_44 ;
T_2 V_57 = V_50 -> V_57 ;
V_50 -> V_44 = V_50 -> V_54 [ V_45 & V_57 ] ;
V_50 -> V_54 [ V_45 & V_57 ] = V_58 ;
if ( V_50 -> V_44 == V_60 ) {
V_50 -> V_44 = V_58 ;
V_50 -> V_59 = V_58 ;
}
return V_45 ;
}
static void F_41 ( struct V_49 * V_50 )
{
T_2 V_53 ;
if ( V_50 -> V_44 == V_58 )
return;
for ( V_53 = 0 ; V_53 <= V_50 -> V_57 ; V_53 ++ )
V_50 -> V_54 [ V_53 ] = V_58 ;
V_50 -> V_44 = V_58 ;
V_50 -> V_59 = V_58 ;
}
static void F_42 ( struct V_49 * V_50 , T_2 V_45 )
{
T_2 V_57 = V_50 -> V_57 ;
if ( V_50 -> V_54 [ V_45 & V_57 ] != V_58 )
return;
if ( V_50 -> V_59 == V_58 )
V_50 -> V_44 = V_45 ;
else
V_50 -> V_54 [ V_50 -> V_59 & V_57 ] = V_45 ;
V_50 -> V_59 = V_45 ;
V_50 -> V_54 [ V_45 & V_57 ] = V_60 ;
}
static void F_43 ( struct V_61 * V_62 )
{
struct V_8 * V_20 = F_44 ( V_62 , struct V_8 ,
V_63 . V_62 ) ;
struct V_9 * V_10 = V_20 -> V_10 ;
int V_64 ;
F_21 ( L_2 , V_20 , F_22 ( V_20 -> V_35 ) ) ;
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_20 ) ;
if ( V_20 -> V_35 == V_65 || V_20 -> V_35 == V_66 )
V_64 = V_67 ;
else if ( V_20 -> V_35 == V_68 &&
V_20 -> V_69 != V_70 )
V_64 = V_67 ;
else
V_64 = V_71 ;
F_45 ( V_20 , V_64 ) ;
F_46 ( V_20 ) ;
V_20 -> V_36 -> V_72 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
F_47 ( V_20 ) ;
}
struct V_8 * F_48 ( void )
{
struct V_8 * V_20 ;
V_20 = F_49 ( sizeof( * V_20 ) , V_73 ) ;
if ( ! V_20 )
return NULL ;
F_50 ( & V_20 -> V_74 ) ;
F_51 ( & V_20 -> V_75 , V_76 ) ;
F_15 ( & V_22 ) ;
F_52 ( & V_20 -> V_77 , & V_78 ) ;
F_17 ( & V_22 ) ;
F_53 ( & V_20 -> V_63 , F_43 ) ;
V_20 -> V_35 = V_79 ;
F_54 ( & V_20 -> V_80 ) ;
F_55 ( V_81 , & V_20 -> V_82 ) ;
F_21 ( L_3 , V_20 ) ;
return V_20 ;
}
static void F_56 ( struct V_80 * V_80 )
{
struct V_8 * V_20 = F_44 ( V_80 , struct V_8 , V_80 ) ;
F_21 ( L_3 , V_20 ) ;
F_15 ( & V_22 ) ;
F_57 ( & V_20 -> V_77 ) ;
F_17 ( & V_22 ) ;
F_38 ( V_20 ) ;
}
void F_58 ( struct V_8 * V_12 )
{
F_21 ( L_4 , V_12 , F_59 ( & V_12 -> V_80 . V_83 ) ) ;
F_60 ( & V_12 -> V_80 ) ;
}
void F_47 ( struct V_8 * V_12 )
{
F_21 ( L_4 , V_12 , F_59 ( & V_12 -> V_80 . V_83 ) ) ;
F_61 ( & V_12 -> V_80 , F_56 ) ;
}
void F_62 ( struct V_8 * V_20 )
{
V_20 -> V_84 = V_85 ;
V_20 -> V_86 = V_87 ;
V_20 -> V_88 = V_89 ;
V_20 -> V_90 = V_89 ;
V_20 -> V_91 = V_20 -> V_86 ;
V_20 -> V_92 = V_20 -> V_88 ;
V_20 -> V_93 = V_89 ;
V_20 -> V_69 = V_94 ;
V_20 -> V_95 = V_96 ;
V_20 -> V_39 = V_97 ;
V_20 -> V_41 = V_98 ;
V_20 -> V_82 = 0 ;
F_55 ( V_99 , & V_20 -> V_100 ) ;
}
static void F_63 ( struct V_8 * V_20 )
{
V_20 -> V_101 = NULL ;
V_20 -> V_102 = NULL ;
V_20 -> V_103 = 0 ;
V_20 -> V_104 = 0 ;
V_20 -> V_105 = V_106 ;
V_20 -> V_107 = F_64 ( T_2 , V_20 -> V_108 , V_109 ) ;
F_65 ( & V_20 -> V_110 ) ;
}
void F_66 ( struct V_9 * V_10 , struct V_8 * V_20 )
{
F_21 ( L_5 , V_10 ,
F_67 ( V_20 -> V_17 ) , V_20 -> V_13 ) ;
V_10 -> V_111 = V_112 ;
V_20 -> V_10 = V_10 ;
switch ( V_20 -> V_29 ) {
case V_113 :
V_20 -> V_14 = F_19 ( V_10 ) ;
if ( V_10 -> V_2 -> type == V_114 )
V_20 -> V_27 = V_28 ;
break;
case V_115 :
V_20 -> V_14 = V_116 ;
V_20 -> V_13 = V_116 ;
V_20 -> V_27 = V_28 ;
break;
case V_30 :
break;
default:
V_20 -> V_14 = V_117 ;
V_20 -> V_13 = V_117 ;
V_20 -> V_27 = V_28 ;
}
V_20 -> V_118 = V_119 ;
V_20 -> V_120 = V_121 ;
V_20 -> V_122 = V_123 ;
V_20 -> V_124 = V_125 ;
V_20 -> V_126 = V_127 ;
V_20 -> V_128 = V_129 ;
F_58 ( V_20 ) ;
if ( V_20 -> V_29 != V_30 ||
F_68 ( V_130 , & V_20 -> V_100 ) )
F_69 ( V_10 -> V_2 ) ;
F_52 ( & V_20 -> V_54 , & V_10 -> V_131 ) ;
}
void F_70 ( struct V_9 * V_10 , struct V_8 * V_20 )
{
F_6 ( & V_10 -> V_15 ) ;
F_66 ( V_10 , V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
}
void F_71 ( struct V_8 * V_20 , int V_21 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_72 ( V_20 ) ;
F_21 ( L_6 , V_20 , V_10 , V_21 ,
F_22 ( V_20 -> V_35 ) ) ;
V_20 -> V_36 -> V_132 ( V_20 , V_21 ) ;
if ( V_10 ) {
struct V_133 * V_134 = V_10 -> V_2 -> V_133 ;
F_57 ( & V_20 -> V_54 ) ;
F_47 ( V_20 ) ;
V_20 -> V_10 = NULL ;
if ( V_20 -> V_29 != V_30 ||
F_68 ( V_130 , & V_20 -> V_100 ) )
F_73 ( V_10 -> V_2 ) ;
if ( V_134 && V_134 -> V_135 == V_20 )
V_134 -> V_135 = NULL ;
}
if ( V_20 -> V_136 ) {
struct V_137 * V_136 = V_20 -> V_136 ;
F_21 ( L_7 , V_20 , V_136 ) ;
F_74 ( V_136 ) ;
}
if ( F_68 ( V_81 , & V_20 -> V_82 ) )
return;
switch( V_20 -> V_138 ) {
case V_139 :
break;
case V_140 :
F_75 ( & V_20 -> V_110 ) ;
break;
case V_141 :
F_30 ( V_20 ) ;
F_76 ( V_20 ) ;
F_77 ( V_20 ) ;
F_75 ( & V_20 -> V_142 ) ;
F_37 ( & V_20 -> V_143 ) ;
F_37 ( & V_20 -> V_144 ) ;
case V_145 :
F_75 ( & V_20 -> V_110 ) ;
break;
}
return;
}
static void F_78 ( struct V_61 * V_62 )
{
struct V_9 * V_10 = F_44 ( V_62 , struct V_9 ,
V_146 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
F_79 ( & V_20 -> V_147 , & V_2 -> V_147 ) ;
V_20 -> V_148 = F_1 ( V_2 , V_2 -> V_148 ) ;
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_80 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_149 V_150 ;
T_2 V_151 ;
if ( F_68 ( V_152 , & V_20 -> V_100 ) )
V_151 = V_153 ;
else
V_151 = V_154 ;
F_20 ( V_20 , V_155 ) ;
V_150 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_150 . V_156 = F_16 ( V_20 -> V_108 ) ;
V_150 . V_107 = F_16 ( V_20 -> V_107 ) ;
V_150 . V_157 = F_16 ( V_20 -> V_105 ) ;
V_150 . V_151 = F_16 ( V_151 ) ;
F_81 ( V_10 , V_20 -> V_16 , V_158 , sizeof( V_150 ) ,
& V_150 ) ;
}
static void F_82 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_159 V_150 ;
T_2 V_151 ;
if ( F_68 ( V_152 , & V_20 -> V_100 ) )
V_151 = V_160 ;
else
V_151 = V_154 ;
F_20 ( V_20 , V_155 ) ;
V_150 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_150 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_150 . V_151 = F_16 ( V_151 ) ;
V_150 . V_161 = F_16 ( V_162 ) ;
F_81 ( V_10 , V_20 -> V_16 , V_163 , sizeof( V_150 ) , & V_150 ) ;
}
void F_45 ( struct V_8 * V_20 , int V_64 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_2 , V_20 , F_22 ( V_20 -> V_35 ) ) ;
switch ( V_20 -> V_35 ) {
case V_164 :
V_20 -> V_36 -> V_132 ( V_20 , 0 ) ;
break;
case V_65 :
case V_66 :
if ( V_20 -> V_29 == V_113 ) {
F_83 ( V_20 , V_20 -> V_36 -> V_165 ( V_20 ) ) ;
F_84 ( V_20 , V_64 ) ;
} else
F_71 ( V_20 , V_64 ) ;
break;
case V_166 :
if ( V_20 -> V_29 == V_113 ) {
if ( V_10 -> V_2 -> type == V_114 )
F_82 ( V_20 ) ;
else if ( V_10 -> V_2 -> type == V_3 )
F_80 ( V_20 ) ;
}
F_71 ( V_20 , V_64 ) ;
break;
case V_68 :
case V_155 :
F_71 ( V_20 , V_64 ) ;
break;
default:
V_20 -> V_36 -> V_132 ( V_20 , 0 ) ;
break;
}
}
static inline T_3 F_85 ( struct V_8 * V_20 )
{
switch ( V_20 -> V_29 ) {
case V_167 :
switch ( V_20 -> V_69 ) {
case V_168 :
case V_169 :
return V_170 ;
case V_171 :
return V_172 ;
default:
return V_173 ;
}
break;
case V_115 :
if ( V_20 -> V_17 == F_16 ( V_174 ) ) {
if ( V_20 -> V_69 == V_94 )
V_20 -> V_69 = V_70 ;
}
if ( V_20 -> V_69 == V_168 ||
V_20 -> V_69 == V_169 )
return V_175 ;
else
return V_173 ;
break;
case V_113 :
if ( V_20 -> V_17 == F_16 ( V_176 ) ) {
if ( V_20 -> V_69 == V_94 )
V_20 -> V_69 = V_70 ;
if ( V_20 -> V_69 == V_168 ||
V_20 -> V_69 == V_169 )
return V_175 ;
else
return V_173 ;
}
default:
switch ( V_20 -> V_69 ) {
case V_168 :
case V_169 :
return V_177 ;
case V_171 :
return V_178 ;
default:
return V_173 ;
}
break;
}
}
int F_86 ( struct V_8 * V_20 , bool V_179 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
T_1 V_180 ;
if ( V_10 -> V_2 -> type == V_3 )
return F_87 ( V_10 -> V_2 , V_20 -> V_69 ) ;
V_180 = F_85 ( V_20 ) ;
return F_88 ( V_10 -> V_2 , V_20 -> V_69 , V_180 ,
V_179 ) ;
}
static T_3 F_89 ( struct V_9 * V_10 )
{
T_3 V_181 ;
F_6 ( & V_10 -> V_182 ) ;
if ( ++ V_10 -> V_183 > 128 )
V_10 -> V_183 = 1 ;
V_181 = V_10 -> V_183 ;
F_8 ( & V_10 -> V_182 ) ;
return V_181 ;
}
static void F_81 ( struct V_9 * V_10 , T_3 V_16 , T_3 V_184 , T_2 V_185 ,
void * V_186 )
{
struct V_42 * V_46 = F_90 ( V_10 , V_184 , V_16 , V_185 , V_186 ) ;
T_3 V_100 ;
F_21 ( L_8 , V_184 ) ;
if ( ! V_46 )
return;
if ( F_91 ( V_10 -> V_2 -> V_187 ) ||
V_10 -> V_2 -> type == V_3 )
V_100 = V_188 ;
else
V_100 = V_189 ;
F_33 ( V_46 ) -> V_190 = V_191 ;
V_46 -> V_192 = V_193 ;
F_92 ( V_10 -> V_194 , V_46 , V_100 ) ;
}
static bool F_93 ( struct V_8 * V_20 )
{
return V_20 -> V_195 != V_196 &&
V_20 -> V_195 != V_197 ;
}
static void F_94 ( struct V_8 * V_20 , struct V_42 * V_46 )
{
struct V_1 * V_2 = V_20 -> V_10 -> V_2 ;
T_2 V_100 ;
F_21 ( L_9 , V_20 , V_46 , V_46 -> V_185 ,
V_46 -> V_192 ) ;
if ( V_20 -> V_198 && ! F_93 ( V_20 ) ) {
if ( V_20 -> V_136 )
F_92 ( V_20 -> V_136 , V_46 , V_199 ) ;
else
F_95 ( V_46 ) ;
return;
}
if ( V_2 -> type == V_3 ||
( ! F_68 ( V_200 , & V_20 -> V_100 ) &&
F_91 ( V_2 -> V_187 ) ) )
V_100 = V_188 ;
else
V_100 = V_189 ;
F_33 ( V_46 ) -> V_190 = F_68 ( V_99 , & V_20 -> V_100 ) ;
F_92 ( V_20 -> V_10 -> V_194 , V_46 , V_100 ) ;
}
static void F_96 ( T_2 V_201 , struct V_202 * V_47 )
{
V_47 -> V_203 = ( V_201 & V_204 ) >> V_205 ;
V_47 -> V_206 = ( V_201 & V_207 ) >> V_208 ;
if ( V_201 & V_209 ) {
V_47 -> V_210 = 1 ;
V_47 -> V_211 = ( V_201 & V_212 ) >> V_213 ;
V_47 -> V_214 = ( V_201 & V_215 ) >> V_216 ;
V_47 -> V_217 = 0 ;
V_47 -> V_48 = 0 ;
} else {
V_47 -> V_210 = 0 ;
V_47 -> V_217 = ( V_201 & V_218 ) >> V_219 ;
V_47 -> V_48 = ( V_201 & V_220 ) >> V_221 ;
V_47 -> V_211 = 0 ;
V_47 -> V_214 = 0 ;
}
}
static void F_97 ( T_8 V_222 , struct V_202 * V_47 )
{
V_47 -> V_203 = ( V_222 & V_223 ) >> V_224 ;
V_47 -> V_206 = ( V_222 & V_225 ) >> V_226 ;
if ( V_222 & V_227 ) {
V_47 -> V_210 = 1 ;
V_47 -> V_211 = ( V_222 & V_228 ) >> V_229 ;
V_47 -> V_214 = ( V_222 & V_230 ) >> V_231 ;
V_47 -> V_217 = 0 ;
V_47 -> V_48 = 0 ;
} else {
V_47 -> V_210 = 0 ;
V_47 -> V_217 = ( V_222 & V_232 ) >> V_233 ;
V_47 -> V_48 = ( V_222 & V_234 ) >> V_235 ;
V_47 -> V_211 = 0 ;
V_47 -> V_214 = 0 ;
}
}
static inline void F_98 ( struct V_8 * V_20 ,
struct V_42 * V_46 )
{
if ( F_68 ( V_236 , & V_20 -> V_100 ) ) {
F_97 ( F_99 ( V_46 -> V_186 ) ,
& F_33 ( V_46 ) -> V_47 ) ;
F_100 ( V_46 , V_237 ) ;
} else {
F_96 ( F_101 ( V_46 -> V_186 ) ,
& F_33 ( V_46 ) -> V_47 ) ;
F_100 ( V_46 , V_238 ) ;
}
}
static T_8 F_102 ( struct V_202 * V_47 )
{
T_8 V_239 ;
V_239 = V_47 -> V_203 << V_224 ;
V_239 |= V_47 -> V_206 << V_226 ;
if ( V_47 -> V_210 ) {
V_239 |= V_47 -> V_211 << V_229 ;
V_239 |= V_47 -> V_214 << V_231 ;
V_239 |= V_227 ;
} else {
V_239 |= V_47 -> V_217 << V_233 ;
V_239 |= V_47 -> V_48 << V_235 ;
}
return V_239 ;
}
static T_2 F_103 ( struct V_202 * V_47 )
{
T_2 V_239 ;
V_239 = V_47 -> V_203 << V_205 ;
V_239 |= V_47 -> V_206 << V_208 ;
if ( V_47 -> V_210 ) {
V_239 |= V_47 -> V_211 << V_213 ;
V_239 |= V_47 -> V_214 << V_216 ;
V_239 |= V_209 ;
} else {
V_239 |= V_47 -> V_217 << V_219 ;
V_239 |= V_47 -> V_48 << V_221 ;
}
return V_239 ;
}
static inline void F_104 ( struct V_8 * V_20 ,
struct V_202 * V_47 ,
struct V_42 * V_46 )
{
if ( F_68 ( V_236 , & V_20 -> V_100 ) ) {
F_105 ( F_102 ( V_47 ) ,
V_46 -> V_186 + V_240 ) ;
} else {
F_106 ( F_103 ( V_47 ) ,
V_46 -> V_186 + V_240 ) ;
}
}
static inline unsigned int F_107 ( struct V_8 * V_20 )
{
if ( F_68 ( V_236 , & V_20 -> V_100 ) )
return V_241 ;
else
return V_242 ;
}
static struct V_42 * F_108 ( struct V_8 * V_20 ,
T_8 V_47 )
{
struct V_42 * V_46 ;
struct V_243 * V_244 ;
int V_245 = F_107 ( V_20 ) ;
if ( V_20 -> V_84 == V_85 )
V_245 += V_246 ;
V_46 = F_109 ( V_245 , V_55 ) ;
if ( ! V_46 )
return F_110 ( - V_56 ) ;
V_244 = (struct V_243 * ) F_111 ( V_46 , V_240 ) ;
V_244 -> V_185 = F_16 ( V_245 - V_240 ) ;
V_244 -> V_11 = F_16 ( V_20 -> V_13 ) ;
if ( F_68 ( V_236 , & V_20 -> V_100 ) )
F_105 ( V_47 , F_111 ( V_46 , V_237 ) ) ;
else
F_106 ( V_47 , F_111 ( V_46 , V_238 ) ) ;
if ( V_20 -> V_84 == V_85 ) {
T_2 V_84 = F_112 ( 0 , ( T_3 * ) V_46 -> V_186 , V_46 -> V_185 ) ;
F_106 ( V_84 , F_111 ( V_46 , V_246 ) ) ;
}
V_46 -> V_192 = V_193 ;
return V_46 ;
}
static void F_113 ( struct V_8 * V_20 ,
struct V_202 * V_47 )
{
struct V_42 * V_46 ;
T_8 V_247 ;
F_21 ( L_10 , V_20 , V_47 ) ;
if ( ! V_47 -> V_210 )
return;
if ( F_93 ( V_20 ) )
return;
if ( F_114 ( V_248 , & V_20 -> V_249 ) &&
! V_47 -> V_211 )
V_47 -> V_206 = 1 ;
if ( V_47 -> V_214 == V_250 )
F_115 ( V_251 , & V_20 -> V_249 ) ;
else if ( V_47 -> V_214 == V_252 )
F_55 ( V_251 , & V_20 -> V_249 ) ;
if ( V_47 -> V_214 != V_253 ) {
V_20 -> V_254 = V_47 -> V_203 ;
F_77 ( V_20 ) ;
}
F_21 ( L_11 , V_47 -> V_203 ,
V_47 -> V_206 , V_47 -> V_211 , V_47 -> V_214 ) ;
if ( F_68 ( V_236 , & V_20 -> V_100 ) )
V_247 = F_102 ( V_47 ) ;
else
V_247 = F_103 ( V_47 ) ;
V_46 = F_108 ( V_20 , V_247 ) ;
if ( ! F_116 ( V_46 ) )
F_94 ( V_20 , V_46 ) ;
}
static void F_117 ( struct V_8 * V_20 , bool V_211 )
{
struct V_202 V_47 ;
F_21 ( L_12 , V_20 , V_211 ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_210 = 1 ;
V_47 . V_211 = V_211 ;
if ( F_68 ( V_255 , & V_20 -> V_249 ) )
V_47 . V_214 = V_252 ;
else
V_47 . V_214 = V_250 ;
V_47 . V_203 = V_20 -> V_256 ;
F_113 ( V_20 , & V_47 ) ;
}
static inline int F_118 ( struct V_8 * V_20 )
{
if ( V_20 -> V_29 != V_113 )
return true ;
return ! F_68 ( V_257 , & V_20 -> V_82 ) ;
}
static bool F_119 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_258 * V_187 ;
bool V_259 = false ;
if ( ! ( V_10 -> V_260 & V_261 ) )
return false ;
if ( ! ( V_10 -> V_262 & V_261 ) )
return false ;
F_120 ( & V_263 ) ;
F_3 (hdev, &hci_dev_list, list) {
if ( V_187 -> V_264 != V_265 &&
F_68 ( V_266 , & V_187 -> V_100 ) ) {
V_259 = true ;
break;
}
}
F_121 ( & V_263 ) ;
if ( V_20 -> V_267 == V_268 )
return V_259 ;
return false ;
}
static bool F_122 ( struct V_8 * V_20 )
{
return true ;
}
void F_123 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_269 V_270 ;
V_270 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_270 . V_17 = V_20 -> V_17 ;
V_20 -> V_16 = F_89 ( V_10 ) ;
F_55 ( V_257 , & V_20 -> V_82 ) ;
F_81 ( V_10 , V_20 -> V_16 , V_271 , sizeof( V_270 ) , & V_270 ) ;
}
static void F_124 ( struct V_8 * V_20 , T_3 V_272 )
{
struct V_273 V_270 ;
V_270 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_270 . V_17 = V_20 -> V_17 ;
V_270 . V_272 = V_272 ;
V_20 -> V_16 = F_89 ( V_20 -> V_10 ) ;
F_81 ( V_20 -> V_10 , V_20 -> V_16 , V_274 ,
sizeof( V_270 ) , & V_270 ) ;
}
static void F_125 ( struct V_8 * V_20 )
{
struct V_42 * V_46 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_138 != V_141 )
return;
F_30 ( V_20 ) ;
F_76 ( V_20 ) ;
F_77 ( V_20 ) ;
V_20 -> V_275 = 0 ;
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_46 ) -> V_47 . V_276 )
F_33 ( V_46 ) -> V_47 . V_276 = 1 ;
else
break;
}
V_20 -> V_277 = V_20 -> V_256 ;
F_115 ( V_278 , & V_20 -> V_249 ) ;
F_115 ( V_279 , & V_20 -> V_249 ) ;
F_41 ( & V_20 -> V_144 ) ;
F_41 ( & V_20 -> V_143 ) ;
F_75 ( & V_20 -> V_142 ) ;
V_20 -> V_280 = V_281 ;
V_20 -> V_282 = V_283 ;
F_55 ( V_284 , & V_20 -> V_249 ) ;
}
static void F_126 ( struct V_8 * V_20 )
{
T_3 V_285 = V_20 -> V_285 ;
F_21 ( L_3 , V_20 ) ;
V_20 -> V_195 = V_196 ;
V_20 -> V_285 = V_286 ;
if ( V_20 -> V_138 != V_141 )
return;
switch ( V_285 ) {
case V_287 :
F_127 ( V_20 , NULL , NULL , V_288 ) ;
V_20 -> V_282 = V_289 ;
break;
case V_290 :
V_20 -> V_282 = V_291 ;
break;
}
}
static void F_128 ( struct V_8 * V_20 )
{
V_20 -> V_82 = 0 ;
F_72 ( V_20 ) ;
if ( V_20 -> V_138 == V_140 && ! V_20 -> V_104 )
V_20 -> V_36 -> V_292 ( V_20 ) ;
V_20 -> V_35 = V_65 ;
V_20 -> V_36 -> V_293 ( V_20 ) ;
}
static void F_129 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_294 V_270 ;
if ( F_130 ( V_295 , & V_20 -> V_100 ) )
return;
V_270 . V_17 = V_20 -> V_17 ;
V_270 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_270 . V_156 = F_16 ( V_20 -> V_108 ) ;
V_270 . V_107 = F_16 ( V_20 -> V_107 ) ;
V_270 . V_157 = F_16 ( V_20 -> V_105 ) ;
V_20 -> V_16 = F_89 ( V_10 ) ;
F_81 ( V_10 , V_20 -> V_16 , V_296 ,
sizeof( V_270 ) , & V_270 ) ;
}
static void F_131 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
if ( ! F_87 ( V_10 -> V_2 , V_20 -> V_69 ) )
return;
if ( ! V_20 -> V_17 ) {
F_128 ( V_20 ) ;
return;
}
if ( V_20 -> V_35 == V_68 )
F_129 ( V_20 ) ;
}
static void F_132 ( struct V_8 * V_20 )
{
if ( F_119 ( V_20 ) ) {
F_21 ( L_13 , V_20 ) ;
F_133 ( V_20 ) ;
} else if ( V_20 -> V_10 -> V_2 -> type == V_3 ) {
F_131 ( V_20 ) ;
} else {
F_123 ( V_20 ) ;
}
}
static void F_134 ( struct V_9 * V_10 )
{
struct V_297 V_270 ;
if ( V_10 -> V_298 & V_299 )
return;
V_270 . type = F_16 ( V_300 ) ;
V_10 -> V_298 |= V_299 ;
V_10 -> V_301 = F_89 ( V_10 ) ;
F_135 ( & V_10 -> V_302 , V_303 ) ;
F_81 ( V_10 , V_10 -> V_301 , V_304 ,
sizeof( V_270 ) , & V_270 ) ;
}
static void F_136 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
if ( V_10 -> V_2 -> type == V_3 ) {
F_131 ( V_20 ) ;
return;
}
if ( ! ( V_10 -> V_298 & V_299 ) ) {
F_134 ( V_10 ) ;
return;
}
if ( ! ( V_10 -> V_298 & V_305 ) )
return;
if ( F_86 ( V_20 , true ) &&
F_118 ( V_20 ) )
F_132 ( V_20 ) ;
}
static inline int F_137 ( T_1 V_138 , T_9 V_306 )
{
T_8 V_307 = V_308 ;
if ( ! V_309 )
V_307 |= V_310 | V_311 ;
switch ( V_138 ) {
case V_141 :
return V_310 & V_306 & V_307 ;
case V_145 :
return V_311 & V_306 & V_307 ;
default:
return 0x00 ;
}
}
static void F_84 ( struct V_8 * V_20 , int V_21 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_312 V_270 ;
if ( ! V_10 )
return;
if ( V_20 -> V_138 == V_141 && V_20 -> V_35 == V_65 ) {
F_30 ( V_20 ) ;
F_76 ( V_20 ) ;
F_77 ( V_20 ) ;
}
if ( V_20 -> V_14 == V_313 ) {
F_20 ( V_20 , V_155 ) ;
return;
}
V_270 . V_13 = F_16 ( V_20 -> V_13 ) ;
V_270 . V_14 = F_16 ( V_20 -> V_14 ) ;
F_81 ( V_10 , F_89 ( V_10 ) , V_314 ,
sizeof( V_270 ) , & V_270 ) ;
F_23 ( V_20 , V_155 , V_21 ) ;
}
static void F_138 ( struct V_9 * V_10 )
{
struct V_8 * V_20 , * V_315 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_139 (chan, tmp, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_29 != V_113 ) {
F_128 ( V_20 ) ;
F_46 ( V_20 ) ;
continue;
}
if ( V_20 -> V_35 == V_68 ) {
if ( ! F_86 ( V_20 , true ) ||
! F_118 ( V_20 ) ) {
F_46 ( V_20 ) ;
continue;
}
if ( ! F_137 ( V_20 -> V_138 , V_10 -> V_306 )
&& F_68 ( V_316 ,
& V_20 -> V_82 ) ) {
F_45 ( V_20 , V_317 ) ;
F_46 ( V_20 ) ;
continue;
}
F_132 ( V_20 ) ;
} else if ( V_20 -> V_35 == V_166 ) {
struct V_159 V_150 ;
char V_318 [ 128 ] ;
V_150 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_150 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( F_86 ( V_20 , false ) ) {
if ( F_68 ( V_152 , & V_20 -> V_100 ) ) {
V_150 . V_151 = F_16 ( V_319 ) ;
V_150 . V_161 = F_16 ( V_320 ) ;
V_20 -> V_36 -> V_321 ( V_20 ) ;
} else {
F_20 ( V_20 , V_66 ) ;
V_150 . V_151 = F_16 ( V_322 ) ;
V_150 . V_161 = F_16 ( V_162 ) ;
}
} else {
V_150 . V_151 = F_16 ( V_319 ) ;
V_150 . V_161 = F_16 ( V_323 ) ;
}
F_81 ( V_10 , V_20 -> V_16 , V_163 ,
sizeof( V_150 ) , & V_150 ) ;
if ( F_68 ( V_324 , & V_20 -> V_82 ) ||
V_150 . V_151 != V_322 ) {
F_46 ( V_20 ) ;
continue;
}
F_55 ( V_324 , & V_20 -> V_82 ) ;
F_81 ( V_10 , F_89 ( V_10 ) , V_325 ,
F_140 ( V_20 , V_318 ) , V_318 ) ;
V_20 -> V_326 ++ ;
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_141 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_258 * V_187 = V_2 -> V_187 ;
F_21 ( L_15 , V_187 -> V_327 , V_10 ) ;
if ( V_2 -> V_328 )
F_87 ( V_2 , V_2 -> V_329 ) ;
if ( V_2 -> V_330 == V_331 &&
( V_2 -> V_332 < V_2 -> V_333 ||
V_2 -> V_332 > V_2 -> V_334 ) ) {
struct V_335 V_270 ;
V_270 . V_336 = F_16 ( V_2 -> V_333 ) ;
V_270 . V_337 = F_16 ( V_2 -> V_334 ) ;
V_270 . V_338 = F_16 ( V_2 -> V_339 ) ;
V_270 . V_340 = F_16 ( V_2 -> V_341 ) ;
F_81 ( V_10 , F_89 ( V_10 ) ,
V_342 , sizeof( V_270 ) , & V_270 ) ;
}
}
static void F_142 ( struct V_9 * V_10 )
{
struct V_8 * V_20 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_21 ( L_14 , V_10 ) ;
if ( V_2 -> type == V_114 )
F_134 ( V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_14 == V_313 ) {
F_46 ( V_20 ) ;
continue;
}
if ( V_2 -> type == V_3 ) {
F_131 ( V_20 ) ;
} else if ( V_20 -> V_29 != V_113 ) {
if ( V_10 -> V_298 & V_305 )
F_128 ( V_20 ) ;
} else if ( V_20 -> V_35 == V_68 ) {
F_136 ( V_20 ) ;
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
if ( V_2 -> type == V_3 )
F_141 ( V_10 ) ;
F_143 ( V_2 -> V_187 -> V_343 , & V_10 -> V_344 ) ;
}
static void F_144 ( struct V_9 * V_10 , int V_21 )
{
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( F_68 ( V_345 , & V_20 -> V_100 ) )
F_24 ( V_20 , V_21 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_145 ( struct V_61 * V_62 )
{
struct V_9 * V_10 = F_44 ( V_62 , struct V_9 ,
V_302 . V_62 ) ;
V_10 -> V_298 |= V_305 ;
V_10 -> V_301 = 0 ;
F_138 ( V_10 ) ;
}
int F_146 ( struct V_9 * V_10 , struct V_346 * V_347 )
{
struct V_258 * V_187 = V_10 -> V_2 -> V_187 ;
int V_348 ;
F_147 ( V_187 ) ;
if ( V_347 -> V_54 . V_349 || V_347 -> V_54 . V_350 ) {
V_348 = - V_26 ;
goto V_351;
}
if ( ! V_10 -> V_194 ) {
V_348 = - V_352 ;
goto V_351;
}
V_348 = V_347 -> V_353 ( V_10 , V_347 ) ;
if ( V_348 )
goto V_351;
F_52 ( & V_347 -> V_54 , & V_10 -> V_354 ) ;
V_348 = 0 ;
V_351:
F_148 ( V_187 ) ;
return V_348 ;
}
void F_149 ( struct V_9 * V_10 , struct V_346 * V_347 )
{
struct V_258 * V_187 = V_10 -> V_2 -> V_187 ;
F_147 ( V_187 ) ;
if ( ! V_347 -> V_54 . V_349 || ! V_347 -> V_54 . V_350 )
goto V_351;
F_57 ( & V_347 -> V_54 ) ;
V_347 -> V_54 . V_349 = NULL ;
V_347 -> V_54 . V_350 = NULL ;
V_347 -> remove ( V_10 , V_347 ) ;
V_351:
F_148 ( V_187 ) ;
}
static void F_150 ( struct V_9 * V_10 )
{
struct V_346 * V_347 ;
while ( ! F_151 ( & V_10 -> V_354 ) ) {
V_347 = F_152 ( & V_10 -> V_354 , struct V_346 , V_54 ) ;
F_57 ( & V_347 -> V_54 ) ;
V_347 -> V_54 . V_349 = NULL ;
V_347 -> V_54 . V_350 = NULL ;
V_347 -> remove ( V_10 , V_347 ) ;
}
}
static void F_153 ( struct V_1 * V_2 , int V_21 )
{
struct V_9 * V_10 = V_2 -> V_355 ;
struct V_8 * V_20 , * V_356 ;
if ( ! V_10 )
return;
F_21 ( L_16 , V_2 , V_10 , V_21 ) ;
F_95 ( V_10 -> V_357 ) ;
F_75 ( & V_10 -> V_358 ) ;
if ( F_154 ( & V_10 -> V_344 ) )
F_155 ( & V_10 -> V_344 ) ;
if ( F_154 ( & V_10 -> V_146 ) )
F_155 ( & V_10 -> V_146 ) ;
F_150 ( V_10 ) ;
V_2 -> V_359 = 0 ;
F_6 ( & V_10 -> V_15 ) ;
F_139 (chan, l, &conn->chan_l, list) {
F_58 ( V_20 ) ;
F_7 ( V_20 ) ;
F_71 ( V_20 , V_21 ) ;
F_46 ( V_20 ) ;
V_20 -> V_36 -> V_72 ( V_20 ) ;
F_47 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
F_156 ( V_10 -> V_194 ) ;
if ( V_10 -> V_298 & V_299 )
F_157 ( & V_10 -> V_302 ) ;
V_2 -> V_355 = NULL ;
V_10 -> V_194 = NULL ;
F_158 ( V_10 ) ;
}
static void F_159 ( struct V_80 * V_360 )
{
struct V_9 * V_10 = F_44 ( V_360 , struct V_9 , V_360 ) ;
F_160 ( V_10 -> V_2 ) ;
F_38 ( V_10 ) ;
}
struct V_9 * F_161 ( struct V_9 * V_10 )
{
F_60 ( & V_10 -> V_360 ) ;
return V_10 ;
}
void F_158 ( struct V_9 * V_10 )
{
F_61 ( & V_10 -> V_360 , F_159 ) ;
}
static struct V_8 * F_162 ( int V_35 , T_4 V_17 ,
T_5 * V_18 ,
T_5 * V_147 ,
T_3 V_361 )
{
struct V_8 * V_12 , * V_362 = NULL ;
F_120 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_35 && V_12 -> V_35 != V_35 )
continue;
if ( V_361 == V_114 && V_12 -> V_363 != V_7 )
continue;
if ( V_361 == V_3 && V_12 -> V_363 == V_7 )
continue;
if ( V_12 -> V_17 == V_17 ) {
int V_364 , V_365 ;
int V_366 , V_367 ;
V_364 = ! F_13 ( & V_12 -> V_18 , V_18 ) ;
V_365 = ! F_13 ( & V_12 -> V_147 , V_147 ) ;
if ( V_364 && V_365 ) {
F_58 ( V_12 ) ;
F_121 ( & V_22 ) ;
return V_12 ;
}
V_366 = ! F_13 ( & V_12 -> V_18 , V_368 ) ;
V_367 = ! F_13 ( & V_12 -> V_147 , V_368 ) ;
if ( ( V_364 && V_367 ) || ( V_366 && V_365 ) ||
( V_366 && V_367 ) )
V_362 = V_12 ;
}
}
if ( V_362 )
F_58 ( V_362 ) ;
F_121 ( & V_22 ) ;
return V_362 ;
}
static void F_163 ( struct V_61 * V_62 )
{
struct V_8 * V_20 = F_44 ( V_62 , struct V_8 ,
V_38 . V_62 ) ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
if ( ! V_20 -> V_10 ) {
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
return;
}
F_127 ( V_20 , NULL , NULL , V_369 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
static void F_164 ( struct V_61 * V_62 )
{
struct V_8 * V_20 = F_44 ( V_62 , struct V_8 ,
V_40 . V_62 ) ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
if ( ! V_20 -> V_10 ) {
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
return;
}
F_127 ( V_20 , NULL , NULL , V_370 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
static void F_165 ( struct V_8 * V_20 ,
struct V_43 * V_371 )
{
struct V_42 * V_46 ;
struct V_202 * V_47 ;
F_21 ( L_17 , V_20 , V_371 ) ;
if ( F_93 ( V_20 ) )
return;
F_166 ( V_371 , & V_20 -> V_110 ) ;
while ( ! F_167 ( & V_20 -> V_110 ) ) {
V_46 = F_168 ( & V_20 -> V_110 ) ;
F_33 ( V_46 ) -> V_47 . V_276 = 1 ;
V_47 = & F_33 ( V_46 ) -> V_47 ;
V_47 -> V_203 = 0 ;
V_47 -> V_48 = V_20 -> V_372 ;
F_104 ( V_20 , V_47 , V_46 ) ;
if ( V_20 -> V_84 == V_85 ) {
T_2 V_84 = F_112 ( 0 , ( T_3 * ) V_46 -> V_186 , V_46 -> V_185 ) ;
F_106 ( V_84 , F_111 ( V_46 , V_246 ) ) ;
}
F_94 ( V_20 , V_46 ) ;
F_21 ( L_18 , V_47 -> V_48 ) ;
V_20 -> V_372 = F_169 ( V_20 , V_20 -> V_372 ) ;
V_20 -> V_373 ++ ;
}
}
static int F_170 ( struct V_8 * V_20 )
{
struct V_42 * V_46 , * V_374 ;
struct V_202 * V_47 ;
int V_375 = 0 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_35 != V_65 )
return - V_376 ;
if ( F_68 ( V_284 , & V_20 -> V_249 ) )
return 0 ;
if ( F_93 ( V_20 ) )
return 0 ;
while ( V_20 -> V_377 &&
V_20 -> V_378 < V_20 -> V_92 &&
V_20 -> V_280 == V_281 ) {
V_46 = V_20 -> V_377 ;
F_33 ( V_46 ) -> V_47 . V_276 = 1 ;
V_47 = & F_33 ( V_46 ) -> V_47 ;
if ( F_114 ( V_248 , & V_20 -> V_249 ) )
V_47 -> V_206 = 1 ;
V_47 -> V_203 = V_20 -> V_256 ;
V_20 -> V_254 = V_20 -> V_256 ;
V_47 -> V_48 = V_20 -> V_372 ;
F_104 ( V_20 , V_47 , V_46 ) ;
if ( V_20 -> V_84 == V_85 ) {
T_2 V_84 = F_112 ( 0 , ( T_3 * ) V_46 -> V_186 , V_46 -> V_185 ) ;
F_106 ( V_84 , F_111 ( V_46 , V_246 ) ) ;
}
V_374 = F_171 ( V_46 , V_55 ) ;
if ( ! V_374 )
break;
F_25 ( V_20 ) ;
V_20 -> V_372 = F_169 ( V_20 , V_20 -> V_372 ) ;
V_20 -> V_378 ++ ;
V_20 -> V_373 ++ ;
V_375 ++ ;
if ( F_172 ( & V_20 -> V_110 , V_46 ) )
V_20 -> V_377 = NULL ;
else
V_20 -> V_377 = F_173 ( & V_20 -> V_110 , V_46 ) ;
F_94 ( V_20 , V_374 ) ;
F_21 ( L_18 , V_47 -> V_48 ) ;
}
F_21 ( L_19 , V_375 ,
V_20 -> V_378 , F_174 ( & V_20 -> V_110 ) ) ;
return V_375 ;
}
static void F_175 ( struct V_8 * V_20 )
{
struct V_202 V_47 ;
struct V_42 * V_46 ;
struct V_42 * V_374 ;
T_2 V_45 ;
F_21 ( L_3 , V_20 ) ;
if ( F_68 ( V_284 , & V_20 -> V_249 ) )
return;
if ( F_93 ( V_20 ) )
return;
while ( V_20 -> V_144 . V_44 != V_58 ) {
V_45 = F_40 ( & V_20 -> V_144 ) ;
V_46 = F_31 ( & V_20 -> V_110 , V_45 ) ;
if ( ! V_46 ) {
F_21 ( L_20 ,
V_45 ) ;
continue;
}
F_33 ( V_46 ) -> V_47 . V_276 ++ ;
V_47 = F_33 ( V_46 ) -> V_47 ;
if ( V_20 -> V_86 != 0 &&
F_33 ( V_46 ) -> V_47 . V_276 > V_20 -> V_86 ) {
F_21 ( L_21 , V_20 -> V_86 ) ;
F_84 ( V_20 , V_317 ) ;
F_41 ( & V_20 -> V_144 ) ;
break;
}
V_47 . V_203 = V_20 -> V_256 ;
if ( F_114 ( V_248 , & V_20 -> V_249 ) )
V_47 . V_206 = 1 ;
else
V_47 . V_206 = 0 ;
if ( F_176 ( V_46 ) ) {
V_374 = F_177 ( V_46 , V_55 ) ;
} else {
V_374 = F_171 ( V_46 , V_55 ) ;
}
if ( ! V_374 ) {
F_41 ( & V_20 -> V_144 ) ;
break;
}
if ( F_68 ( V_236 , & V_20 -> V_100 ) ) {
F_105 ( F_102 ( & V_47 ) ,
V_374 -> V_186 + V_240 ) ;
} else {
F_106 ( F_103 ( & V_47 ) ,
V_374 -> V_186 + V_240 ) ;
}
if ( V_20 -> V_84 == V_85 ) {
T_2 V_84 = F_112 ( 0 , ( T_3 * ) V_374 -> V_186 ,
V_374 -> V_185 - V_246 ) ;
F_106 ( V_84 , F_178 ( V_374 ) -
V_246 ) ;
}
F_94 ( V_20 , V_374 ) ;
F_21 ( L_22 , V_47 . V_48 ) ;
V_20 -> V_254 = V_20 -> V_256 ;
}
}
static void F_179 ( struct V_8 * V_20 ,
struct V_202 * V_47 )
{
F_21 ( L_10 , V_20 , V_47 ) ;
F_42 ( & V_20 -> V_144 , V_47 -> V_203 ) ;
F_175 ( V_20 ) ;
}
static void F_180 ( struct V_8 * V_20 ,
struct V_202 * V_47 )
{
struct V_42 * V_46 ;
F_21 ( L_10 , V_20 , V_47 ) ;
if ( V_47 -> V_211 )
F_55 ( V_248 , & V_20 -> V_249 ) ;
F_41 ( & V_20 -> V_144 ) ;
if ( F_68 ( V_284 , & V_20 -> V_249 ) )
return;
if ( V_20 -> V_378 ) {
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_46 ) -> V_47 . V_48 == V_47 -> V_203 ||
V_46 == V_20 -> V_377 )
break;
}
F_181 (&chan->tx_q, skb) {
if ( V_46 == V_20 -> V_377 )
break;
F_42 ( & V_20 -> V_144 ,
F_33 ( V_46 ) -> V_47 . V_48 ) ;
}
F_175 ( V_20 ) ;
}
}
static void F_182 ( struct V_8 * V_20 )
{
struct V_202 V_47 ;
T_2 V_379 = F_183 ( V_20 , V_20 -> V_256 ,
V_20 -> V_254 ) ;
int V_380 ;
F_21 ( L_23 ,
V_20 , V_20 -> V_254 , V_20 -> V_256 ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_210 = 1 ;
if ( F_68 ( V_255 , & V_20 -> V_249 ) &&
V_20 -> V_282 == V_381 ) {
F_77 ( V_20 ) ;
V_47 . V_214 = V_252 ;
V_47 . V_203 = V_20 -> V_256 ;
F_113 ( V_20 , & V_47 ) ;
} else {
if ( ! F_68 ( V_284 , & V_20 -> V_249 ) ) {
F_170 ( V_20 ) ;
if ( V_20 -> V_256 == V_20 -> V_254 )
V_379 = 0 ;
}
V_380 = V_20 -> V_93 ;
V_380 += V_380 << 1 ;
V_380 >>= 2 ;
F_21 ( L_24 , V_379 ,
V_380 ) ;
if ( V_379 >= V_380 ) {
F_77 ( V_20 ) ;
V_47 . V_214 = V_250 ;
V_47 . V_203 = V_20 -> V_256 ;
F_113 ( V_20 , & V_47 ) ;
V_379 = 0 ;
}
if ( V_379 )
F_184 ( V_20 ) ;
}
}
static inline int F_185 ( struct V_8 * V_20 ,
struct V_382 * V_383 , int V_185 ,
int V_384 , struct V_42 * V_46 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_42 * * V_385 ;
int V_375 = 0 ;
if ( F_186 ( F_111 ( V_46 , V_384 ) , V_384 , & V_383 -> V_386 ) != V_384 )
return - V_387 ;
V_375 += V_384 ;
V_185 -= V_384 ;
V_385 = & F_187 ( V_46 ) -> V_388 ;
while ( V_185 ) {
struct V_42 * V_315 ;
V_384 = F_64 (unsigned int, conn->mtu, len) ;
V_315 = V_20 -> V_36 -> V_389 ( V_20 , 0 , V_384 ,
V_383 -> V_390 & V_391 ) ;
if ( F_116 ( V_315 ) )
return F_188 ( V_315 ) ;
* V_385 = V_315 ;
if ( F_186 ( F_111 ( * V_385 , V_384 ) , V_384 ,
& V_383 -> V_386 ) != V_384 )
return - V_387 ;
V_375 += V_384 ;
V_185 -= V_384 ;
V_46 -> V_185 += ( * V_385 ) -> V_185 ;
V_46 -> V_392 += ( * V_385 ) -> V_185 ;
V_385 = & ( * V_385 ) -> V_349 ;
}
return V_375 ;
}
static struct V_42 * F_189 ( struct V_8 * V_20 ,
struct V_382 * V_383 , T_7 V_185 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_42 * V_46 ;
int V_21 , V_384 , V_245 = V_240 + V_393 ;
struct V_243 * V_244 ;
F_21 ( L_25 , V_20 ,
F_67 ( V_20 -> V_17 ) , V_185 ) ;
V_384 = F_64 (unsigned int, (conn->mtu - hlen), len) ;
V_46 = V_20 -> V_36 -> V_389 ( V_20 , V_245 , V_384 ,
V_383 -> V_390 & V_391 ) ;
if ( F_116 ( V_46 ) )
return V_46 ;
V_244 = (struct V_243 * ) F_111 ( V_46 , V_240 ) ;
V_244 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_244 -> V_185 = F_16 ( V_185 + V_393 ) ;
F_190 ( V_20 -> V_17 , ( T_4 * ) F_111 ( V_46 , V_393 ) ) ;
V_21 = F_185 ( V_20 , V_383 , V_185 , V_384 , V_46 ) ;
if ( F_191 ( V_21 < 0 ) ) {
F_95 ( V_46 ) ;
return F_110 ( V_21 ) ;
}
return V_46 ;
}
static struct V_42 * F_192 ( struct V_8 * V_20 ,
struct V_382 * V_383 , T_7 V_185 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_42 * V_46 ;
int V_21 , V_384 ;
struct V_243 * V_244 ;
F_21 ( L_26 , V_20 , V_185 ) ;
V_384 = F_64 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_46 = V_20 -> V_36 -> V_389 ( V_20 , V_240 , V_384 ,
V_383 -> V_390 & V_391 ) ;
if ( F_116 ( V_46 ) )
return V_46 ;
V_244 = (struct V_243 * ) F_111 ( V_46 , V_240 ) ;
V_244 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_244 -> V_185 = F_16 ( V_185 ) ;
V_21 = F_185 ( V_20 , V_383 , V_185 , V_384 , V_46 ) ;
if ( F_191 ( V_21 < 0 ) ) {
F_95 ( V_46 ) ;
return F_110 ( V_21 ) ;
}
return V_46 ;
}
static struct V_42 * F_193 ( struct V_8 * V_20 ,
struct V_382 * V_383 , T_7 V_185 ,
T_2 V_394 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_42 * V_46 ;
int V_21 , V_384 , V_245 ;
struct V_243 * V_244 ;
F_21 ( L_26 , V_20 , V_185 ) ;
if ( ! V_10 )
return F_110 ( - V_376 ) ;
V_245 = F_107 ( V_20 ) ;
if ( V_394 )
V_245 += V_395 ;
if ( V_20 -> V_84 == V_85 )
V_245 += V_246 ;
V_384 = F_64 (unsigned int, (conn->mtu - hlen), len) ;
V_46 = V_20 -> V_36 -> V_389 ( V_20 , V_245 , V_384 ,
V_383 -> V_390 & V_391 ) ;
if ( F_116 ( V_46 ) )
return V_46 ;
V_244 = (struct V_243 * ) F_111 ( V_46 , V_240 ) ;
V_244 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_244 -> V_185 = F_16 ( V_185 + ( V_245 - V_240 ) ) ;
if ( F_68 ( V_236 , & V_20 -> V_100 ) )
F_105 ( 0 , F_111 ( V_46 , V_237 ) ) ;
else
F_106 ( 0 , F_111 ( V_46 , V_238 ) ) ;
if ( V_394 )
F_106 ( V_394 , F_111 ( V_46 , V_395 ) ) ;
V_21 = F_185 ( V_20 , V_383 , V_185 , V_384 , V_46 ) ;
if ( F_191 ( V_21 < 0 ) ) {
F_95 ( V_46 ) ;
return F_110 ( V_21 ) ;
}
F_33 ( V_46 ) -> V_47 . V_84 = V_20 -> V_84 ;
F_33 ( V_46 ) -> V_47 . V_276 = 0 ;
return V_46 ;
}
static int F_194 ( struct V_8 * V_20 ,
struct V_43 * V_396 ,
struct V_382 * V_383 , T_7 V_185 )
{
struct V_42 * V_46 ;
T_2 V_103 ;
T_7 V_397 ;
T_3 V_217 ;
F_21 ( L_27 , V_20 , V_383 , V_185 ) ;
V_397 = V_20 -> V_10 -> V_156 ;
if ( ! V_20 -> V_198 )
V_397 = F_64 ( T_7 , V_397 , V_398 ) ;
if ( V_20 -> V_84 )
V_397 -= V_246 ;
V_397 -= F_107 ( V_20 ) ;
V_397 = F_64 ( T_7 , V_397 , V_20 -> V_399 ) ;
if ( V_185 <= V_397 ) {
V_217 = V_400 ;
V_103 = 0 ;
V_397 = V_185 ;
} else {
V_217 = V_401 ;
V_103 = V_185 ;
}
while ( V_185 > 0 ) {
V_46 = F_193 ( V_20 , V_383 , V_397 , V_103 ) ;
if ( F_116 ( V_46 ) ) {
F_195 ( V_396 ) ;
return F_188 ( V_46 ) ;
}
F_33 ( V_46 ) -> V_47 . V_217 = V_217 ;
F_196 ( V_396 , V_46 ) ;
V_185 -= V_397 ;
if ( V_103 )
V_103 = 0 ;
if ( V_185 <= V_397 ) {
V_217 = V_402 ;
V_397 = V_185 ;
} else {
V_217 = V_403 ;
}
}
return 0 ;
}
static struct V_42 * F_197 ( struct V_8 * V_20 ,
struct V_382 * V_383 ,
T_7 V_185 , T_2 V_394 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_42 * V_46 ;
int V_21 , V_384 , V_245 ;
struct V_243 * V_244 ;
F_21 ( L_26 , V_20 , V_185 ) ;
if ( ! V_10 )
return F_110 ( - V_376 ) ;
V_245 = V_240 ;
if ( V_394 )
V_245 += V_395 ;
V_384 = F_64 (unsigned int, (conn->mtu - hlen), len) ;
V_46 = V_20 -> V_36 -> V_389 ( V_20 , V_245 , V_384 ,
V_383 -> V_390 & V_391 ) ;
if ( F_116 ( V_46 ) )
return V_46 ;
V_244 = (struct V_243 * ) F_111 ( V_46 , V_240 ) ;
V_244 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_244 -> V_185 = F_16 ( V_185 + ( V_245 - V_240 ) ) ;
if ( V_394 )
F_106 ( V_394 , F_111 ( V_46 , V_395 ) ) ;
V_21 = F_185 ( V_20 , V_383 , V_185 , V_384 , V_46 ) ;
if ( F_191 ( V_21 < 0 ) ) {
F_95 ( V_46 ) ;
return F_110 ( V_21 ) ;
}
return V_46 ;
}
static int F_198 ( struct V_8 * V_20 ,
struct V_43 * V_396 ,
struct V_382 * V_383 , T_7 V_185 )
{
struct V_42 * V_46 ;
T_7 V_397 ;
T_2 V_103 ;
F_21 ( L_27 , V_20 , V_383 , V_185 ) ;
V_103 = V_185 ;
V_397 = V_20 -> V_399 - V_395 ;
while ( V_185 > 0 ) {
if ( V_185 <= V_397 )
V_397 = V_185 ;
V_46 = F_197 ( V_20 , V_383 , V_397 , V_103 ) ;
if ( F_116 ( V_46 ) ) {
F_195 ( V_396 ) ;
return F_188 ( V_46 ) ;
}
F_196 ( V_396 , V_46 ) ;
V_185 -= V_397 ;
if ( V_103 ) {
V_103 = 0 ;
V_397 += V_395 ;
}
}
return 0 ;
}
int F_199 ( struct V_8 * V_20 , struct V_382 * V_383 , T_7 V_185 )
{
struct V_42 * V_46 ;
int V_21 ;
struct V_43 V_396 ;
if ( ! V_20 -> V_10 )
return - V_376 ;
if ( V_20 -> V_29 == V_115 ) {
V_46 = F_189 ( V_20 , V_383 , V_185 ) ;
if ( F_116 ( V_46 ) )
return F_188 ( V_46 ) ;
if ( V_20 -> V_35 != V_65 ) {
F_95 ( V_46 ) ;
return - V_376 ;
}
F_94 ( V_20 , V_46 ) ;
return V_185 ;
}
switch ( V_20 -> V_138 ) {
case V_140 :
if ( V_185 > V_20 -> V_27 )
return - V_404 ;
if ( ! V_20 -> V_104 )
return - V_405 ;
F_200 ( & V_396 ) ;
V_21 = F_198 ( V_20 , & V_396 , V_383 , V_185 ) ;
if ( V_20 -> V_35 != V_65 ) {
F_195 ( & V_396 ) ;
V_21 = - V_376 ;
}
if ( V_21 )
return V_21 ;
F_166 ( & V_396 , & V_20 -> V_110 ) ;
while ( V_20 -> V_104 && ! F_167 ( & V_20 -> V_110 ) ) {
F_94 ( V_20 , F_168 ( & V_20 -> V_110 ) ) ;
V_20 -> V_104 -- ;
}
if ( ! V_20 -> V_104 )
V_20 -> V_36 -> V_292 ( V_20 ) ;
V_21 = V_185 ;
break;
case V_139 :
if ( V_185 > V_20 -> V_27 )
return - V_404 ;
V_46 = F_192 ( V_20 , V_383 , V_185 ) ;
if ( F_116 ( V_46 ) )
return F_188 ( V_46 ) ;
if ( V_20 -> V_35 != V_65 ) {
F_95 ( V_46 ) ;
return - V_376 ;
}
F_94 ( V_20 , V_46 ) ;
V_21 = V_185 ;
break;
case V_141 :
case V_145 :
if ( V_185 > V_20 -> V_27 ) {
V_21 = - V_404 ;
break;
}
F_200 ( & V_396 ) ;
V_21 = F_194 ( V_20 , & V_396 , V_383 , V_185 ) ;
if ( V_20 -> V_35 != V_65 ) {
F_195 ( & V_396 ) ;
V_21 = - V_376 ;
}
if ( V_21 )
break;
if ( V_20 -> V_138 == V_141 )
F_127 ( V_20 , NULL , & V_396 , V_406 ) ;
else
F_165 ( V_20 , & V_396 ) ;
V_21 = V_185 ;
F_195 ( & V_396 ) ;
break;
default:
F_21 ( L_28 , V_20 -> V_138 ) ;
V_21 = - V_407 ;
}
return V_21 ;
}
static void F_201 ( struct V_8 * V_20 , T_2 V_48 )
{
struct V_202 V_47 ;
T_2 V_45 ;
F_21 ( L_29 , V_20 , V_48 ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_210 = 1 ;
V_47 . V_214 = V_253 ;
for ( V_45 = V_20 -> V_277 ; V_45 != V_48 ;
V_45 = F_169 ( V_20 , V_45 ) ) {
if ( ! F_31 ( & V_20 -> V_142 , V_45 ) ) {
V_47 . V_203 = V_45 ;
F_113 ( V_20 , & V_47 ) ;
F_42 ( & V_20 -> V_143 , V_45 ) ;
}
}
V_20 -> V_277 = F_169 ( V_20 , V_48 ) ;
}
static void F_202 ( struct V_8 * V_20 )
{
struct V_202 V_47 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_143 . V_59 == V_58 )
return;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_210 = 1 ;
V_47 . V_214 = V_253 ;
V_47 . V_203 = V_20 -> V_143 . V_59 ;
F_113 ( V_20 , & V_47 ) ;
}
static void F_203 ( struct V_8 * V_20 , T_2 V_48 )
{
struct V_202 V_47 ;
T_2 V_408 ;
T_2 V_45 ;
F_21 ( L_29 , V_20 , V_48 ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_210 = 1 ;
V_47 . V_214 = V_253 ;
V_408 = V_20 -> V_143 . V_44 ;
do {
V_45 = F_40 ( & V_20 -> V_143 ) ;
if ( V_45 == V_48 || V_45 == V_58 )
break;
V_47 . V_203 = V_45 ;
F_113 ( V_20 , & V_47 ) ;
F_42 ( & V_20 -> V_143 , V_45 ) ;
} while ( V_20 -> V_143 . V_44 != V_408 );
}
static void F_204 ( struct V_8 * V_20 , T_2 V_203 )
{
struct V_42 * V_409 ;
T_2 V_410 ;
F_21 ( L_30 , V_20 , V_203 ) ;
if ( V_20 -> V_378 == 0 || V_203 == V_20 -> V_411 )
return;
F_21 ( L_31 ,
V_20 -> V_411 , V_20 -> V_378 ) ;
for ( V_410 = V_20 -> V_411 ; V_410 != V_203 ;
V_410 = F_169 ( V_20 , V_410 ) ) {
V_409 = F_31 ( & V_20 -> V_110 , V_410 ) ;
if ( V_409 ) {
F_205 ( V_409 , & V_20 -> V_110 ) ;
F_95 ( V_409 ) ;
V_20 -> V_378 -- ;
}
}
V_20 -> V_411 = V_203 ;
if ( V_20 -> V_378 == 0 )
F_30 ( V_20 ) ;
F_21 ( L_32 , V_20 -> V_378 ) ;
}
static void F_206 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_277 = V_20 -> V_256 ;
F_41 ( & V_20 -> V_143 ) ;
F_75 ( & V_20 -> V_142 ) ;
V_20 -> V_282 = V_381 ;
}
static void F_207 ( struct V_8 * V_20 ,
struct V_202 * V_47 ,
struct V_43 * V_371 , T_3 V_412 )
{
F_21 ( L_33 , V_20 , V_47 , V_371 ,
V_412 ) ;
switch ( V_412 ) {
case V_406 :
if ( V_20 -> V_377 == NULL )
V_20 -> V_377 = F_208 ( V_371 ) ;
F_166 ( V_371 , & V_20 -> V_110 ) ;
F_170 ( V_20 ) ;
break;
case V_413 :
F_21 ( L_34 ) ;
F_55 ( V_255 , & V_20 -> V_249 ) ;
if ( V_20 -> V_282 == V_414 ) {
F_206 ( V_20 ) ;
}
F_182 ( V_20 ) ;
break;
case V_415 :
F_21 ( L_35 ) ;
F_115 ( V_255 , & V_20 -> V_249 ) ;
if ( F_68 ( V_251 , & V_20 -> V_249 ) ) {
struct V_202 V_416 ;
memset ( & V_416 , 0 , sizeof( V_416 ) ) ;
V_416 . V_210 = 1 ;
V_416 . V_214 = V_250 ;
V_416 . V_211 = 1 ;
V_416 . V_203 = V_20 -> V_256 ;
F_113 ( V_20 , & V_416 ) ;
V_20 -> V_275 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_280 = V_417 ;
}
break;
case V_418 :
F_204 ( V_20 , V_47 -> V_203 ) ;
break;
case V_288 :
F_117 ( V_20 , 1 ) ;
V_20 -> V_275 = 1 ;
F_29 ( V_20 ) ;
F_77 ( V_20 ) ;
V_20 -> V_280 = V_417 ;
break;
case V_370 :
F_117 ( V_20 , 1 ) ;
V_20 -> V_275 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_280 = V_417 ;
break;
case V_419 :
break;
default:
break;
}
}
static void F_209 ( struct V_8 * V_20 ,
struct V_202 * V_47 ,
struct V_43 * V_371 , T_3 V_412 )
{
F_21 ( L_33 , V_20 , V_47 , V_371 ,
V_412 ) ;
switch ( V_412 ) {
case V_406 :
if ( V_20 -> V_377 == NULL )
V_20 -> V_377 = F_208 ( V_371 ) ;
F_166 ( V_371 , & V_20 -> V_110 ) ;
break;
case V_413 :
F_21 ( L_34 ) ;
F_55 ( V_255 , & V_20 -> V_249 ) ;
if ( V_20 -> V_282 == V_414 ) {
F_206 ( V_20 ) ;
}
F_182 ( V_20 ) ;
break;
case V_415 :
F_21 ( L_35 ) ;
F_115 ( V_255 , & V_20 -> V_249 ) ;
if ( F_68 ( V_251 , & V_20 -> V_249 ) ) {
struct V_202 V_416 ;
memset ( & V_416 , 0 , sizeof( V_416 ) ) ;
V_416 . V_210 = 1 ;
V_416 . V_214 = V_250 ;
V_416 . V_211 = 1 ;
V_416 . V_203 = V_20 -> V_256 ;
F_113 ( V_20 , & V_416 ) ;
V_20 -> V_275 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_280 = V_417 ;
}
break;
case V_418 :
F_204 ( V_20 , V_47 -> V_203 ) ;
case V_419 :
if ( V_47 && V_47 -> V_206 ) {
F_76 ( V_20 ) ;
if ( V_20 -> V_378 > 0 )
F_25 ( V_20 ) ;
V_20 -> V_275 = 0 ;
V_20 -> V_280 = V_281 ;
F_21 ( L_36 , V_20 -> V_280 ) ;
}
break;
case V_288 :
break;
case V_369 :
if ( V_20 -> V_86 == 0 || V_20 -> V_275 < V_20 -> V_86 ) {
F_117 ( V_20 , 1 ) ;
F_29 ( V_20 ) ;
V_20 -> V_275 ++ ;
} else {
F_84 ( V_20 , V_420 ) ;
}
break;
default:
break;
}
}
static void F_127 ( struct V_8 * V_20 , struct V_202 * V_47 ,
struct V_43 * V_371 , T_3 V_412 )
{
F_21 ( L_37 ,
V_20 , V_47 , V_371 , V_412 , V_20 -> V_280 ) ;
switch ( V_20 -> V_280 ) {
case V_281 :
F_207 ( V_20 , V_47 , V_371 , V_412 ) ;
break;
case V_417 :
F_209 ( V_20 , V_47 , V_371 , V_412 ) ;
break;
default:
break;
}
}
static void F_210 ( struct V_8 * V_20 ,
struct V_202 * V_47 )
{
F_21 ( L_10 , V_20 , V_47 ) ;
F_127 ( V_20 , V_47 , NULL , V_418 ) ;
}
static void F_211 ( struct V_8 * V_20 ,
struct V_202 * V_47 )
{
F_21 ( L_10 , V_20 , V_47 ) ;
F_127 ( V_20 , V_47 , NULL , V_419 ) ;
}
static void F_212 ( struct V_9 * V_10 , struct V_42 * V_46 )
{
struct V_42 * V_421 ;
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( V_20 -> V_29 != V_167 )
continue;
if ( F_33 ( V_46 ) -> V_20 == V_20 )
continue;
V_421 = F_171 ( V_46 , V_55 ) ;
if ( ! V_421 )
continue;
if ( V_20 -> V_36 -> V_422 ( V_20 , V_421 ) )
F_95 ( V_421 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static struct V_42 * F_90 ( struct V_9 * V_10 , T_3 V_184 ,
T_3 V_16 , T_2 V_423 , void * V_186 )
{
struct V_42 * V_46 , * * V_385 ;
struct V_424 * V_425 ;
struct V_243 * V_244 ;
int V_185 , V_384 ;
F_21 ( L_38 ,
V_10 , V_184 , V_16 , V_423 ) ;
if ( V_10 -> V_156 < V_240 + V_426 )
return NULL ;
V_185 = V_240 + V_426 + V_423 ;
V_384 = F_64 (unsigned int, conn->mtu, len) ;
V_46 = F_109 ( V_384 , V_55 ) ;
if ( ! V_46 )
return NULL ;
V_244 = (struct V_243 * ) F_111 ( V_46 , V_240 ) ;
V_244 -> V_185 = F_16 ( V_426 + V_423 ) ;
if ( V_10 -> V_2 -> type == V_3 )
V_244 -> V_11 = F_16 ( V_427 ) ;
else
V_244 -> V_11 = F_16 ( V_117 ) ;
V_425 = (struct V_424 * ) F_111 ( V_46 , V_426 ) ;
V_425 -> V_184 = V_184 ;
V_425 -> V_16 = V_16 ;
V_425 -> V_185 = F_16 ( V_423 ) ;
if ( V_423 ) {
V_384 -= V_240 + V_426 ;
memcpy ( F_111 ( V_46 , V_384 ) , V_186 , V_384 ) ;
V_186 += V_384 ;
}
V_185 -= V_46 -> V_185 ;
V_385 = & F_187 ( V_46 ) -> V_388 ;
while ( V_185 ) {
V_384 = F_64 (unsigned int, conn->mtu, len) ;
* V_385 = F_109 ( V_384 , V_55 ) ;
if ( ! * V_385 )
goto V_428;
memcpy ( F_111 ( * V_385 , V_384 ) , V_186 , V_384 ) ;
V_185 -= V_384 ;
V_186 += V_384 ;
V_385 = & ( * V_385 ) -> V_349 ;
}
return V_46 ;
V_428:
F_95 ( V_46 ) ;
return NULL ;
}
static inline int F_213 ( void * * V_429 , int * type , int * V_430 ,
unsigned long * V_431 )
{
struct V_432 * V_433 = * V_429 ;
int V_185 ;
V_185 = V_434 + V_433 -> V_185 ;
* V_429 += V_185 ;
* type = V_433 -> type ;
* V_430 = V_433 -> V_185 ;
switch ( V_433 -> V_185 ) {
case 1 :
* V_431 = * ( ( T_3 * ) V_433 -> V_431 ) ;
break;
case 2 :
* V_431 = F_101 ( V_433 -> V_431 ) ;
break;
case 4 :
* V_431 = F_99 ( V_433 -> V_431 ) ;
break;
default:
* V_431 = ( unsigned long ) V_433 -> V_431 ;
break;
}
F_21 ( L_39 , * type , V_433 -> V_185 , * V_431 ) ;
return V_185 ;
}
static void F_214 ( void * * V_429 , T_3 type , T_3 V_185 , unsigned long V_431 )
{
struct V_432 * V_433 = * V_429 ;
F_21 ( L_39 , type , V_185 , V_431 ) ;
V_433 -> type = type ;
V_433 -> V_185 = V_185 ;
switch ( V_185 ) {
case 1 :
* ( ( T_3 * ) V_433 -> V_431 ) = V_431 ;
break;
case 2 :
F_106 ( V_431 , V_433 -> V_431 ) ;
break;
case 4 :
F_105 ( V_431 , V_433 -> V_431 ) ;
break;
default:
memcpy ( V_433 -> V_431 , ( void * ) V_431 , V_185 ) ;
break;
}
* V_429 += V_434 + V_185 ;
}
static void F_215 ( void * * V_429 , struct V_8 * V_20 )
{
struct V_435 V_436 ;
switch ( V_20 -> V_138 ) {
case V_141 :
V_436 . V_181 = V_20 -> V_118 ;
V_436 . V_437 = V_20 -> V_120 ;
V_436 . V_438 = F_16 ( V_20 -> V_122 ) ;
V_436 . V_439 = F_216 ( V_20 -> V_124 ) ;
V_436 . V_440 = F_216 ( V_127 ) ;
V_436 . V_95 = F_216 ( V_129 ) ;
break;
case V_145 :
V_436 . V_181 = 1 ;
V_436 . V_437 = V_121 ;
V_436 . V_438 = F_16 ( V_20 -> V_122 ) ;
V_436 . V_439 = F_216 ( V_20 -> V_124 ) ;
V_436 . V_440 = 0 ;
V_436 . V_95 = 0 ;
break;
default:
return;
}
F_214 ( V_429 , V_441 , sizeof( V_436 ) ,
( unsigned long ) & V_436 ) ;
}
static void F_217 ( struct V_61 * V_62 )
{
struct V_8 * V_20 = F_44 ( V_62 , struct V_8 ,
V_442 . V_62 ) ;
T_2 V_379 ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
V_379 = F_183 ( V_20 , V_20 -> V_256 ,
V_20 -> V_254 ) ;
if ( V_379 )
F_117 ( V_20 , 0 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
int F_218 ( struct V_8 * V_20 )
{
int V_21 ;
V_20 -> V_372 = 0 ;
V_20 -> V_277 = 0 ;
V_20 -> V_411 = 0 ;
V_20 -> V_378 = 0 ;
V_20 -> V_256 = 0 ;
V_20 -> V_373 = 0 ;
V_20 -> V_254 = 0 ;
V_20 -> V_101 = NULL ;
V_20 -> V_102 = NULL ;
V_20 -> V_103 = 0 ;
F_65 ( & V_20 -> V_110 ) ;
V_20 -> V_443 = V_444 ;
V_20 -> V_445 = V_444 ;
V_20 -> V_195 = V_196 ;
V_20 -> V_285 = V_286 ;
if ( V_20 -> V_138 != V_141 )
return 0 ;
V_20 -> V_282 = V_381 ;
V_20 -> V_280 = V_281 ;
F_53 ( & V_20 -> V_40 , F_164 ) ;
F_53 ( & V_20 -> V_38 , F_163 ) ;
F_53 ( & V_20 -> V_442 , F_217 ) ;
F_65 ( & V_20 -> V_142 ) ;
V_21 = F_34 ( & V_20 -> V_143 , V_20 -> V_88 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_34 ( & V_20 -> V_144 , V_20 -> V_92 ) ;
if ( V_21 < 0 )
F_37 ( & V_20 -> V_143 ) ;
return V_21 ;
}
static inline T_1 F_219 ( T_1 V_138 , T_6 V_446 )
{
switch ( V_138 ) {
case V_145 :
case V_141 :
if ( F_137 ( V_138 , V_446 ) )
return V_138 ;
default:
return V_139 ;
}
}
static inline bool F_220 ( struct V_9 * V_10 )
{
return ( ( V_10 -> V_260 & V_261 ) &&
( V_10 -> V_306 & V_447 ) ) ;
}
static inline bool F_221 ( struct V_9 * V_10 )
{
return ( ( V_10 -> V_260 & V_261 ) &&
( V_10 -> V_306 & V_448 ) ) ;
}
static void F_222 ( struct V_8 * V_20 ,
struct V_449 * V_450 )
{
if ( V_20 -> V_443 != V_444 && V_20 -> V_198 ) {
T_10 V_451 = V_20 -> V_198 -> V_187 -> V_452 ;
V_451 = F_223 ( V_451 , 1000 ) ;
V_451 = 3 * V_451 + 500 ;
if ( V_451 > 0xffff )
V_451 = 0xffff ;
V_450 -> V_39 = F_16 ( ( T_2 ) V_451 ) ;
V_450 -> V_41 = V_450 -> V_39 ;
} else {
V_450 -> V_39 = F_16 ( V_97 ) ;
V_450 -> V_41 = F_16 ( V_98 ) ;
}
}
static inline void F_224 ( struct V_8 * V_20 )
{
if ( V_20 -> V_88 > V_89 &&
F_220 ( V_20 -> V_10 ) ) {
F_55 ( V_236 , & V_20 -> V_100 ) ;
V_20 -> V_90 = V_453 ;
} else {
V_20 -> V_88 = F_64 ( T_2 , V_20 -> V_88 ,
V_89 ) ;
V_20 -> V_90 = V_89 ;
}
V_20 -> V_93 = V_20 -> V_88 ;
}
static int F_140 ( struct V_8 * V_20 , void * V_186 )
{
struct V_454 * V_270 = V_186 ;
struct V_449 V_450 = { . V_138 = V_20 -> V_138 } ;
void * V_429 = V_270 -> V_186 ;
T_2 V_51 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_326 || V_20 -> V_455 )
goto V_24;
switch ( V_20 -> V_138 ) {
case V_145 :
case V_141 :
if ( F_68 ( V_316 , & V_20 -> V_82 ) )
break;
if ( F_221 ( V_20 -> V_10 ) )
F_55 ( V_456 , & V_20 -> V_100 ) ;
default:
V_20 -> V_138 = F_219 ( V_450 . V_138 , V_20 -> V_10 -> V_306 ) ;
break;
}
V_24:
if ( V_20 -> V_108 != V_28 )
F_214 ( & V_429 , V_457 , 2 , V_20 -> V_108 ) ;
switch ( V_20 -> V_138 ) {
case V_139 :
if ( V_309 )
break;
if ( ! ( V_20 -> V_10 -> V_306 & V_310 ) &&
! ( V_20 -> V_10 -> V_306 & V_311 ) )
break;
V_450 . V_138 = V_139 ;
V_450 . V_458 = 0 ;
V_450 . V_459 = 0 ;
V_450 . V_39 = 0 ;
V_450 . V_41 = 0 ;
V_450 . V_460 = 0 ;
F_214 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
break;
case V_141 :
V_450 . V_138 = V_141 ;
V_450 . V_459 = V_20 -> V_86 ;
F_222 ( V_20 , & V_450 ) ;
V_51 = F_64 ( T_2 , V_462 , V_20 -> V_10 -> V_156 -
V_241 - V_395 -
V_246 ) ;
V_450 . V_460 = F_16 ( V_51 ) ;
F_224 ( V_20 ) ;
V_450 . V_458 = F_64 ( T_2 , V_20 -> V_88 ,
V_89 ) ;
F_214 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
if ( F_68 ( V_456 , & V_20 -> V_100 ) )
F_215 ( & V_429 , V_20 ) ;
if ( F_68 ( V_236 , & V_20 -> V_100 ) )
F_214 ( & V_429 , V_463 , 2 ,
V_20 -> V_88 ) ;
if ( V_20 -> V_10 -> V_306 & V_464 )
if ( V_20 -> V_84 == V_465 ||
F_68 ( V_466 , & V_20 -> V_82 ) ) {
V_20 -> V_84 = V_465 ;
F_214 ( & V_429 , V_467 , 1 ,
V_20 -> V_84 ) ;
}
break;
case V_145 :
F_224 ( V_20 ) ;
V_450 . V_138 = V_145 ;
V_450 . V_458 = 0 ;
V_450 . V_459 = 0 ;
V_450 . V_39 = 0 ;
V_450 . V_41 = 0 ;
V_51 = F_64 ( T_2 , V_462 , V_20 -> V_10 -> V_156 -
V_241 - V_395 -
V_246 ) ;
V_450 . V_460 = F_16 ( V_51 ) ;
F_214 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
if ( F_68 ( V_456 , & V_20 -> V_100 ) )
F_215 ( & V_429 , V_20 ) ;
if ( V_20 -> V_10 -> V_306 & V_464 )
if ( V_20 -> V_84 == V_465 ||
F_68 ( V_466 , & V_20 -> V_82 ) ) {
V_20 -> V_84 = V_465 ;
F_214 ( & V_429 , V_467 , 1 ,
V_20 -> V_84 ) ;
}
break;
}
V_270 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_270 -> V_100 = F_16 ( 0 ) ;
return V_429 - V_186 ;
}
static int F_225 ( struct V_8 * V_20 , void * V_186 )
{
struct V_468 * V_150 = V_186 ;
void * V_429 = V_150 -> V_186 ;
void * V_270 = V_20 -> V_469 ;
int V_185 = V_20 -> V_470 ;
int type , V_471 , V_430 ;
unsigned long V_431 ;
struct V_449 V_450 = { . V_138 = V_139 } ;
struct V_435 V_436 ;
T_3 V_472 = 0 ;
T_2 V_156 = V_28 ;
T_2 V_151 = V_473 ;
T_2 V_51 ;
F_21 ( L_3 , V_20 ) ;
while ( V_185 >= V_434 ) {
V_185 -= F_213 ( & V_270 , & type , & V_430 , & V_431 ) ;
V_471 = type & V_474 ;
type &= V_475 ;
switch ( type ) {
case V_457 :
V_156 = V_431 ;
break;
case V_476 :
V_20 -> V_95 = V_431 ;
break;
case V_477 :
break;
case V_461 :
if ( V_430 == sizeof( V_450 ) )
memcpy ( & V_450 , ( void * ) V_431 , V_430 ) ;
break;
case V_467 :
if ( V_431 == V_465 )
F_55 ( V_466 , & V_20 -> V_82 ) ;
break;
case V_441 :
V_472 = 1 ;
if ( V_430 == sizeof( V_436 ) )
memcpy ( & V_436 , ( void * ) V_431 , V_430 ) ;
break;
case V_463 :
if ( ! ( V_20 -> V_10 -> V_260 & V_261 ) )
return - V_67 ;
F_55 ( V_236 , & V_20 -> V_100 ) ;
F_55 ( V_478 , & V_20 -> V_82 ) ;
V_20 -> V_90 = V_453 ;
V_20 -> V_92 = V_431 ;
break;
default:
if ( V_471 )
break;
V_151 = V_479 ;
* ( ( T_3 * ) V_429 ++ ) = type ;
break;
}
}
if ( V_20 -> V_455 || V_20 -> V_326 > 1 )
goto V_24;
switch ( V_20 -> V_138 ) {
case V_145 :
case V_141 :
if ( ! F_68 ( V_316 , & V_20 -> V_82 ) ) {
V_20 -> V_138 = F_219 ( V_450 . V_138 ,
V_20 -> V_10 -> V_306 ) ;
break;
}
if ( V_472 ) {
if ( F_221 ( V_20 -> V_10 ) )
F_55 ( V_456 , & V_20 -> V_100 ) ;
else
return - V_67 ;
}
if ( V_20 -> V_138 != V_450 . V_138 )
return - V_67 ;
break;
}
V_24:
if ( V_20 -> V_138 != V_450 . V_138 ) {
V_151 = V_480 ;
V_450 . V_138 = V_20 -> V_138 ;
if ( V_20 -> V_455 == 1 )
return - V_67 ;
F_214 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
}
if ( V_151 == V_473 ) {
if ( V_156 < V_481 )
V_151 = V_480 ;
else {
V_20 -> V_27 = V_156 ;
F_55 ( V_482 , & V_20 -> V_82 ) ;
}
F_214 ( & V_429 , V_457 , 2 , V_20 -> V_27 ) ;
if ( V_472 ) {
if ( V_20 -> V_120 != V_483 &&
V_436 . V_437 != V_483 &&
V_436 . V_437 != V_20 -> V_120 ) {
V_151 = V_480 ;
if ( V_20 -> V_326 >= 1 )
return - V_67 ;
F_214 ( & V_429 , V_441 ,
sizeof( V_436 ) ,
( unsigned long ) & V_436 ) ;
} else {
V_151 = V_484 ;
F_55 ( V_485 , & V_20 -> V_82 ) ;
}
}
switch ( V_450 . V_138 ) {
case V_139 :
V_20 -> V_84 = V_465 ;
F_55 ( V_486 , & V_20 -> V_82 ) ;
break;
case V_141 :
if ( ! F_68 ( V_478 , & V_20 -> V_82 ) )
V_20 -> V_92 = V_450 . V_458 ;
else
V_450 . V_458 = V_89 ;
V_20 -> V_91 = V_450 . V_459 ;
V_51 = F_64 ( T_2 , F_226 ( V_450 . V_460 ) ,
V_20 -> V_10 -> V_156 - V_241 -
V_395 - V_246 ) ;
V_450 . V_460 = F_16 ( V_51 ) ;
V_20 -> V_399 = V_51 ;
F_222 ( V_20 , & V_450 ) ;
F_55 ( V_486 , & V_20 -> V_82 ) ;
F_214 ( & V_429 , V_461 ,
sizeof( V_450 ) , ( unsigned long ) & V_450 ) ;
if ( F_68 ( V_456 , & V_20 -> V_100 ) ) {
V_20 -> V_487 = V_436 . V_181 ;
V_20 -> V_488 = V_436 . V_437 ;
V_20 -> V_489 = F_226 ( V_436 . V_438 ) ;
V_20 -> V_490 =
F_227 ( V_436 . V_95 ) ;
V_20 -> V_491 =
F_227 ( V_436 . V_440 ) ;
V_20 -> V_492 =
F_227 ( V_436 . V_439 ) ;
F_214 ( & V_429 , V_441 ,
sizeof( V_436 ) ,
( unsigned long ) & V_436 ) ;
}
break;
case V_145 :
V_51 = F_64 ( T_2 , F_226 ( V_450 . V_460 ) ,
V_20 -> V_10 -> V_156 - V_241 -
V_395 - V_246 ) ;
V_450 . V_460 = F_16 ( V_51 ) ;
V_20 -> V_399 = V_51 ;
F_55 ( V_486 , & V_20 -> V_82 ) ;
F_214 ( & V_429 , V_461 , sizeof( V_450 ) ,
( unsigned long ) & V_450 ) ;
break;
default:
V_151 = V_480 ;
memset ( & V_450 , 0 , sizeof( V_450 ) ) ;
V_450 . V_138 = V_20 -> V_138 ;
}
if ( V_151 == V_473 )
F_55 ( V_493 , & V_20 -> V_82 ) ;
}
V_150 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_150 -> V_151 = F_16 ( V_151 ) ;
V_150 -> V_100 = F_16 ( 0 ) ;
return V_429 - V_186 ;
}
static int F_228 ( struct V_8 * V_20 , void * V_150 , int V_185 ,
void * V_186 , T_2 * V_151 )
{
struct V_454 * V_270 = V_186 ;
void * V_429 = V_270 -> V_186 ;
int type , V_430 ;
unsigned long V_431 ;
struct V_449 V_450 = { . V_138 = V_139 } ;
struct V_435 V_436 ;
F_21 ( L_40 , V_20 , V_150 , V_185 , V_186 ) ;
while ( V_185 >= V_434 ) {
V_185 -= F_213 ( & V_150 , & type , & V_430 , & V_431 ) ;
switch ( type ) {
case V_457 :
if ( V_431 < V_481 ) {
* V_151 = V_480 ;
V_20 -> V_108 = V_481 ;
} else
V_20 -> V_108 = V_431 ;
F_214 ( & V_429 , V_457 , 2 , V_20 -> V_108 ) ;
break;
case V_476 :
V_20 -> V_95 = V_431 ;
F_214 ( & V_429 , V_476 ,
2 , V_20 -> V_95 ) ;
break;
case V_461 :
if ( V_430 == sizeof( V_450 ) )
memcpy ( & V_450 , ( void * ) V_431 , V_430 ) ;
if ( F_68 ( V_316 , & V_20 -> V_82 ) &&
V_450 . V_138 != V_20 -> V_138 )
return - V_67 ;
V_20 -> V_84 = 0 ;
F_214 ( & V_429 , V_461 ,
sizeof( V_450 ) , ( unsigned long ) & V_450 ) ;
break;
case V_463 :
V_20 -> V_93 = F_64 ( T_2 , V_431 , V_20 -> V_93 ) ;
F_214 ( & V_429 , V_463 , 2 ,
V_20 -> V_88 ) ;
break;
case V_441 :
if ( V_430 == sizeof( V_436 ) )
memcpy ( & V_436 , ( void * ) V_431 , V_430 ) ;
if ( V_20 -> V_120 != V_483 &&
V_436 . V_437 != V_483 &&
V_436 . V_437 != V_20 -> V_120 )
return - V_67 ;
F_214 ( & V_429 , V_441 , sizeof( V_436 ) ,
( unsigned long ) & V_436 ) ;
break;
case V_467 :
if ( * V_151 == V_484 )
if ( V_431 == V_465 )
F_55 ( V_466 ,
& V_20 -> V_82 ) ;
break;
}
}
if ( V_20 -> V_138 == V_139 && V_20 -> V_138 != V_450 . V_138 )
return - V_67 ;
V_20 -> V_138 = V_450 . V_138 ;
if ( * V_151 == V_473 || * V_151 == V_484 ) {
switch ( V_450 . V_138 ) {
case V_141 :
V_20 -> V_39 = F_226 ( V_450 . V_39 ) ;
V_20 -> V_41 = F_226 ( V_450 . V_41 ) ;
V_20 -> V_107 = F_226 ( V_450 . V_460 ) ;
if ( ! F_68 ( V_236 , & V_20 -> V_100 ) )
V_20 -> V_93 = F_64 ( T_2 , V_20 -> V_93 ,
V_450 . V_458 ) ;
if ( F_68 ( V_456 , & V_20 -> V_100 ) ) {
V_20 -> V_122 = F_226 ( V_436 . V_438 ) ;
V_20 -> V_124 =
F_227 ( V_436 . V_439 ) ;
V_20 -> V_126 = F_227 ( V_436 . V_440 ) ;
V_20 -> V_128 =
F_227 ( V_436 . V_95 ) ;
}
break;
case V_145 :
V_20 -> V_107 = F_226 ( V_450 . V_460 ) ;
}
}
V_270 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_270 -> V_100 = F_16 ( 0 ) ;
return V_429 - V_186 ;
}
static int F_229 ( struct V_8 * V_20 , void * V_186 ,
T_2 V_151 , T_2 V_100 )
{
struct V_468 * V_150 = V_186 ;
void * V_429 = V_150 -> V_186 ;
F_21 ( L_3 , V_20 ) ;
V_150 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_150 -> V_151 = F_16 ( V_151 ) ;
V_150 -> V_100 = F_16 ( V_100 ) ;
return V_429 - V_186 ;
}
void F_230 ( struct V_8 * V_20 )
{
struct V_149 V_150 ;
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_3 , V_20 ) ;
V_150 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_150 . V_156 = F_16 ( V_20 -> V_108 ) ;
V_150 . V_107 = F_16 ( V_20 -> V_107 ) ;
V_150 . V_157 = F_16 ( V_20 -> V_105 ) ;
V_150 . V_151 = F_16 ( V_322 ) ;
F_81 ( V_10 , V_20 -> V_16 , V_158 , sizeof( V_150 ) ,
& V_150 ) ;
}
void F_231 ( struct V_8 * V_20 )
{
struct V_159 V_150 ;
struct V_9 * V_10 = V_20 -> V_10 ;
T_3 V_318 [ 128 ] ;
T_3 V_494 ;
V_150 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_150 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_150 . V_151 = F_16 ( V_322 ) ;
V_150 . V_161 = F_16 ( V_162 ) ;
if ( V_20 -> V_198 )
V_494 = V_495 ;
else
V_494 = V_163 ;
F_21 ( L_41 , V_20 , V_494 ) ;
F_81 ( V_10 , V_20 -> V_16 , V_494 , sizeof( V_150 ) , & V_150 ) ;
if ( F_130 ( V_324 , & V_20 -> V_82 ) )
return;
F_81 ( V_10 , F_89 ( V_10 ) , V_325 ,
F_140 ( V_20 , V_318 ) , V_318 ) ;
V_20 -> V_326 ++ ;
}
static void F_232 ( struct V_8 * V_20 , void * V_150 , int V_185 )
{
int type , V_430 ;
unsigned long V_431 ;
T_2 V_496 = V_20 -> V_93 ;
struct V_449 V_450 = {
. V_138 = V_20 -> V_138 ,
. V_39 = F_16 ( V_97 ) ,
. V_41 = F_16 ( V_98 ) ,
. V_460 = F_16 ( V_20 -> V_108 ) ,
. V_458 = F_64 ( T_2 , V_20 -> V_93 , V_89 ) ,
} ;
F_21 ( L_42 , V_20 , V_150 , V_185 ) ;
if ( ( V_20 -> V_138 != V_141 ) && ( V_20 -> V_138 != V_145 ) )
return;
while ( V_185 >= V_434 ) {
V_185 -= F_213 ( & V_150 , & type , & V_430 , & V_431 ) ;
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
switch ( V_450 . V_138 ) {
case V_141 :
V_20 -> V_39 = F_226 ( V_450 . V_39 ) ;
V_20 -> V_41 = F_226 ( V_450 . V_41 ) ;
V_20 -> V_107 = F_226 ( V_450 . V_460 ) ;
if ( F_68 ( V_236 , & V_20 -> V_100 ) )
V_20 -> V_93 = F_64 ( T_2 , V_20 -> V_93 , V_496 ) ;
else
V_20 -> V_93 = F_64 ( T_2 , V_20 -> V_93 ,
V_450 . V_458 ) ;
break;
case V_145 :
V_20 -> V_107 = F_226 ( V_450 . V_460 ) ;
}
}
static inline int F_233 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
struct V_498 * V_499 = (struct V_498 * ) V_186 ;
if ( V_497 < sizeof( * V_499 ) )
return - V_500 ;
if ( V_499 -> V_64 != V_501 )
return 0 ;
if ( ( V_10 -> V_298 & V_299 ) &&
V_425 -> V_16 == V_10 -> V_301 ) {
F_234 ( & V_10 -> V_302 ) ;
V_10 -> V_298 |= V_305 ;
V_10 -> V_301 = 0 ;
F_138 ( V_10 ) ;
}
return 0 ;
}
static struct V_8 * F_235 ( struct V_9 * V_10 ,
struct V_424 * V_425 ,
T_3 * V_186 , T_3 V_494 , T_3 V_272 )
{
struct V_269 * V_270 = (struct V_269 * ) V_186 ;
struct V_159 V_150 ;
struct V_8 * V_20 = NULL , * V_502 ;
int V_151 , V_161 = V_162 ;
T_2 V_13 = 0 , V_14 = F_67 ( V_270 -> V_14 ) ;
T_4 V_17 = V_270 -> V_17 ;
F_21 ( L_43 , F_67 ( V_17 ) , V_14 ) ;
V_502 = F_162 ( V_164 , V_17 , & V_10 -> V_2 -> V_18 ,
& V_10 -> V_2 -> V_147 , V_114 ) ;
if ( ! V_502 ) {
V_151 = V_154 ;
goto V_503;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_502 ) ;
if ( V_17 != F_16 ( V_176 ) &&
! F_236 ( V_10 -> V_2 ) ) {
V_10 -> V_111 = V_504 ;
V_151 = V_160 ;
goto V_505;
}
V_151 = V_506 ;
if ( F_2 ( V_10 , V_14 ) )
goto V_505;
V_20 = V_502 -> V_36 -> V_507 ( V_502 ) ;
if ( ! V_20 )
goto V_505;
V_10 -> V_2 -> V_359 = V_508 ;
F_79 ( & V_20 -> V_18 , & V_10 -> V_2 -> V_18 ) ;
F_79 ( & V_20 -> V_147 , & V_10 -> V_2 -> V_147 ) ;
V_20 -> V_363 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_363 ) ;
V_20 -> V_148 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_148 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_14 ;
V_20 -> V_443 = V_272 ;
F_66 ( V_10 , V_20 ) ;
V_13 = V_20 -> V_14 ;
F_83 ( V_20 , V_20 -> V_36 -> V_165 ( V_20 ) ) ;
V_20 -> V_16 = V_425 -> V_16 ;
if ( V_10 -> V_298 & V_305 ) {
if ( F_86 ( V_20 , false ) ) {
if ( F_68 ( V_152 , & V_20 -> V_100 ) ) {
F_20 ( V_20 , V_166 ) ;
V_151 = V_319 ;
V_161 = V_320 ;
V_20 -> V_36 -> V_321 ( V_20 ) ;
} else {
if ( V_272 == V_444 ) {
F_20 ( V_20 , V_66 ) ;
V_151 = V_322 ;
} else {
F_20 ( V_20 , V_166 ) ;
V_151 = V_319 ;
}
V_161 = V_162 ;
}
} else {
F_20 ( V_20 , V_166 ) ;
V_151 = V_319 ;
V_161 = V_323 ;
}
} else {
F_20 ( V_20 , V_166 ) ;
V_151 = V_319 ;
V_161 = V_162 ;
}
V_505:
F_46 ( V_502 ) ;
F_8 ( & V_10 -> V_15 ) ;
F_47 ( V_502 ) ;
V_503:
V_150 . V_14 = F_16 ( V_14 ) ;
V_150 . V_13 = F_16 ( V_13 ) ;
V_150 . V_151 = F_16 ( V_151 ) ;
V_150 . V_161 = F_16 ( V_161 ) ;
F_81 ( V_10 , V_425 -> V_16 , V_494 , sizeof( V_150 ) , & V_150 ) ;
if ( V_151 == V_319 && V_161 == V_162 ) {
struct V_297 V_509 ;
V_509 . type = F_16 ( V_300 ) ;
V_10 -> V_298 |= V_299 ;
V_10 -> V_301 = F_89 ( V_10 ) ;
F_135 ( & V_10 -> V_302 , V_303 ) ;
F_81 ( V_10 , V_10 -> V_301 , V_304 ,
sizeof( V_509 ) , & V_509 ) ;
}
if ( V_20 && ! F_68 ( V_324 , & V_20 -> V_82 ) &&
V_151 == V_322 ) {
T_3 V_318 [ 128 ] ;
F_55 ( V_324 , & V_20 -> V_82 ) ;
F_81 ( V_10 , F_89 ( V_10 ) , V_325 ,
F_140 ( V_20 , V_318 ) , V_318 ) ;
V_20 -> V_326 ++ ;
}
return V_20 ;
}
static int F_237 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 , T_3 * V_186 )
{
struct V_258 * V_187 = V_10 -> V_2 -> V_187 ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_497 < sizeof( struct V_269 ) )
return - V_500 ;
F_147 ( V_187 ) ;
if ( F_68 ( V_510 , & V_187 -> V_511 ) &&
! F_130 ( V_512 , & V_2 -> V_100 ) )
F_238 ( V_187 , V_2 , 0 , NULL , 0 ) ;
F_148 ( V_187 ) ;
F_235 ( V_10 , V_425 , V_186 , V_163 , 0 ) ;
return 0 ;
}
static int F_239 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
struct V_159 * V_150 = (struct V_159 * ) V_186 ;
T_2 V_14 , V_13 , V_151 , V_161 ;
struct V_8 * V_20 ;
T_3 V_270 [ 128 ] ;
int V_21 ;
if ( V_497 < sizeof( * V_150 ) )
return - V_500 ;
V_14 = F_67 ( V_150 -> V_14 ) ;
V_13 = F_67 ( V_150 -> V_13 ) ;
V_151 = F_67 ( V_150 -> V_151 ) ;
V_161 = F_67 ( V_150 -> V_161 ) ;
F_21 ( L_44 ,
V_13 , V_14 , V_151 , V_161 ) ;
F_6 ( & V_10 -> V_15 ) ;
if ( V_14 ) {
V_20 = F_4 ( V_10 , V_14 ) ;
if ( ! V_20 ) {
V_21 = - V_513 ;
goto V_514;
}
} else {
V_20 = F_10 ( V_10 , V_425 -> V_16 ) ;
if ( ! V_20 ) {
V_21 = - V_513 ;
goto V_514;
}
}
V_21 = 0 ;
F_7 ( V_20 ) ;
switch ( V_151 ) {
case V_322 :
F_20 ( V_20 , V_66 ) ;
V_20 -> V_16 = 0 ;
V_20 -> V_13 = V_13 ;
F_115 ( V_257 , & V_20 -> V_82 ) ;
if ( F_130 ( V_324 , & V_20 -> V_82 ) )
break;
F_81 ( V_10 , F_89 ( V_10 ) , V_325 ,
F_140 ( V_20 , V_270 ) , V_270 ) ;
V_20 -> V_326 ++ ;
break;
case V_319 :
F_55 ( V_257 , & V_20 -> V_82 ) ;
break;
default:
F_71 ( V_20 , V_67 ) ;
break;
}
F_46 ( V_20 ) ;
V_514:
F_8 ( & V_10 -> V_15 ) ;
return V_21 ;
}
static inline void F_240 ( struct V_8 * V_20 )
{
if ( V_20 -> V_138 != V_141 && V_20 -> V_138 != V_145 )
V_20 -> V_84 = V_465 ;
else if ( ! F_68 ( V_466 , & V_20 -> V_82 ) )
V_20 -> V_84 = V_85 ;
}
static void F_241 ( struct V_8 * V_20 , void * V_186 ,
T_3 V_16 , T_2 V_100 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_45 , V_10 , V_20 , V_16 ,
V_100 ) ;
F_115 ( V_485 , & V_20 -> V_82 ) ;
F_55 ( V_493 , & V_20 -> V_82 ) ;
F_81 ( V_10 , V_16 , V_515 ,
F_229 ( V_20 , V_186 ,
V_473 , V_100 ) , V_186 ) ;
}
static void F_242 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_14 , T_2 V_13 )
{
struct V_516 V_499 ;
V_499 . V_64 = F_16 ( V_517 ) ;
V_499 . V_14 = F_243 ( V_14 ) ;
V_499 . V_13 = F_243 ( V_13 ) ;
F_81 ( V_10 , V_16 , V_518 , sizeof( V_499 ) , & V_499 ) ;
}
static inline int F_244 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
struct V_454 * V_270 = (struct V_454 * ) V_186 ;
T_2 V_13 , V_100 ;
T_3 V_150 [ 64 ] ;
struct V_8 * V_20 ;
int V_185 , V_21 = 0 ;
if ( V_497 < sizeof( * V_270 ) )
return - V_500 ;
V_13 = F_67 ( V_270 -> V_13 ) ;
V_100 = F_67 ( V_270 -> V_100 ) ;
F_21 ( L_46 , V_13 , V_100 ) ;
V_20 = F_5 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_242 ( V_10 , V_425 -> V_16 , V_13 , 0 ) ;
return 0 ;
}
if ( V_20 -> V_35 != V_66 && V_20 -> V_35 != V_166 ) {
F_242 ( V_10 , V_425 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
goto V_514;
}
V_185 = V_497 - sizeof( * V_270 ) ;
if ( V_20 -> V_470 + V_185 > sizeof( V_20 -> V_469 ) ) {
F_81 ( V_10 , V_425 -> V_16 , V_515 ,
F_229 ( V_20 , V_150 ,
V_519 , V_100 ) , V_150 ) ;
goto V_514;
}
memcpy ( V_20 -> V_469 + V_20 -> V_470 , V_270 -> V_186 , V_185 ) ;
V_20 -> V_470 += V_185 ;
if ( V_100 & V_520 ) {
F_81 ( V_10 , V_425 -> V_16 , V_515 ,
F_229 ( V_20 , V_150 ,
V_473 , V_100 ) , V_150 ) ;
goto V_514;
}
V_185 = F_225 ( V_20 , V_150 ) ;
if ( V_185 < 0 ) {
F_84 ( V_20 , V_317 ) ;
goto V_514;
}
V_20 -> V_16 = V_425 -> V_16 ;
F_81 ( V_10 , V_425 -> V_16 , V_515 , V_185 , V_150 ) ;
V_20 -> V_455 ++ ;
V_20 -> V_470 = 0 ;
if ( ! F_68 ( V_493 , & V_20 -> V_82 ) )
goto V_514;
if ( F_68 ( V_521 , & V_20 -> V_82 ) ) {
F_240 ( V_20 ) ;
if ( V_20 -> V_138 == V_141 ||
V_20 -> V_138 == V_145 )
V_21 = F_218 ( V_20 ) ;
if ( V_21 < 0 )
F_84 ( V_20 , - V_21 ) ;
else
F_128 ( V_20 ) ;
goto V_514;
}
if ( ! F_130 ( V_324 , & V_20 -> V_82 ) ) {
T_3 V_318 [ 64 ] ;
F_81 ( V_10 , F_89 ( V_10 ) , V_325 ,
F_140 ( V_20 , V_318 ) , V_318 ) ;
V_20 -> V_326 ++ ;
}
if ( F_68 ( V_522 , & V_20 -> V_82 ) &&
F_68 ( V_485 , & V_20 -> V_82 ) ) {
if ( ! V_20 -> V_198 )
F_241 ( V_20 , V_150 , V_425 -> V_16 , V_100 ) ;
else
V_20 -> V_16 = V_425 -> V_16 ;
}
V_514:
F_46 ( V_20 ) ;
return V_21 ;
}
static inline int F_245 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
struct V_468 * V_150 = (struct V_468 * ) V_186 ;
T_2 V_14 , V_100 , V_151 ;
struct V_8 * V_20 ;
int V_185 = V_497 - sizeof( * V_150 ) ;
int V_21 = 0 ;
if ( V_497 < sizeof( * V_150 ) )
return - V_500 ;
V_14 = F_67 ( V_150 -> V_14 ) ;
V_100 = F_67 ( V_150 -> V_100 ) ;
V_151 = F_67 ( V_150 -> V_151 ) ;
F_21 ( L_47 , V_14 , V_100 ,
V_151 , V_185 ) ;
V_20 = F_5 ( V_10 , V_14 ) ;
if ( ! V_20 )
return 0 ;
switch ( V_151 ) {
case V_473 :
F_232 ( V_20 , V_150 -> V_186 , V_185 ) ;
F_115 ( V_522 , & V_20 -> V_82 ) ;
break;
case V_484 :
F_55 ( V_522 , & V_20 -> V_82 ) ;
if ( F_68 ( V_485 , & V_20 -> V_82 ) ) {
char V_318 [ 64 ] ;
V_185 = F_228 ( V_20 , V_150 -> V_186 , V_185 ,
V_318 , & V_151 ) ;
if ( V_185 < 0 ) {
F_84 ( V_20 , V_317 ) ;
goto V_24;
}
if ( ! V_20 -> V_198 ) {
F_241 ( V_20 , V_318 , V_425 -> V_16 ,
0 ) ;
} else {
if ( F_122 ( V_20 ) ) {
F_246 ( V_20 ) ;
V_20 -> V_16 = V_425 -> V_16 ;
}
}
}
goto V_24;
case V_480 :
if ( V_20 -> V_455 <= V_523 ) {
char V_270 [ 64 ] ;
if ( V_185 > sizeof( V_270 ) - sizeof( struct V_454 ) ) {
F_84 ( V_20 , V_317 ) ;
goto V_24;
}
V_151 = V_473 ;
V_185 = F_228 ( V_20 , V_150 -> V_186 , V_185 ,
V_270 , & V_151 ) ;
if ( V_185 < 0 ) {
F_84 ( V_20 , V_317 ) ;
goto V_24;
}
F_81 ( V_10 , F_89 ( V_10 ) ,
V_325 , V_185 , V_270 ) ;
V_20 -> V_326 ++ ;
if ( V_151 != V_473 )
goto V_24;
break;
}
default:
F_24 ( V_20 , V_317 ) ;
F_83 ( V_20 , V_524 ) ;
F_84 ( V_20 , V_317 ) ;
goto V_24;
}
if ( V_100 & V_520 )
goto V_24;
F_55 ( V_521 , & V_20 -> V_82 ) ;
if ( F_68 ( V_493 , & V_20 -> V_82 ) ) {
F_240 ( V_20 ) ;
if ( V_20 -> V_138 == V_141 ||
V_20 -> V_138 == V_145 )
V_21 = F_218 ( V_20 ) ;
if ( V_21 < 0 )
F_84 ( V_20 , - V_21 ) ;
else
F_128 ( V_20 ) ;
}
V_24:
F_46 ( V_20 ) ;
return V_21 ;
}
static inline int F_247 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
struct V_312 * V_270 = (struct V_312 * ) V_186 ;
struct V_525 V_150 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_497 != sizeof( * V_270 ) )
return - V_500 ;
V_14 = F_67 ( V_270 -> V_14 ) ;
V_13 = F_67 ( V_270 -> V_13 ) ;
F_21 ( L_48 , V_14 , V_13 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_4 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_8 ( & V_10 -> V_15 ) ;
F_242 ( V_10 , V_425 -> V_16 , V_13 , V_14 ) ;
return 0 ;
}
F_7 ( V_20 ) ;
V_150 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_150 . V_14 = F_16 ( V_20 -> V_13 ) ;
F_81 ( V_10 , V_425 -> V_16 , V_526 , sizeof( V_150 ) , & V_150 ) ;
V_20 -> V_36 -> V_527 ( V_20 ) ;
F_58 ( V_20 ) ;
F_71 ( V_20 , V_317 ) ;
F_46 ( V_20 ) ;
V_20 -> V_36 -> V_72 ( V_20 ) ;
F_47 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_248 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
struct V_525 * V_150 = (struct V_525 * ) V_186 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_497 != sizeof( * V_150 ) )
return - V_500 ;
V_14 = F_67 ( V_150 -> V_14 ) ;
V_13 = F_67 ( V_150 -> V_13 ) ;
F_21 ( L_49 , V_13 , V_14 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_4 ( V_10 , V_14 ) ;
if ( ! V_20 ) {
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
F_7 ( V_20 ) ;
F_58 ( V_20 ) ;
F_71 ( V_20 , 0 ) ;
F_46 ( V_20 ) ;
V_20 -> V_36 -> V_72 ( V_20 ) ;
F_47 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_249 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
struct V_297 * V_270 = (struct V_297 * ) V_186 ;
T_2 type ;
if ( V_497 != sizeof( * V_270 ) )
return - V_500 ;
type = F_67 ( V_270 -> type ) ;
F_21 ( L_50 , type ) ;
if ( type == V_300 ) {
T_3 V_318 [ 8 ] ;
T_8 V_306 = V_308 ;
struct V_528 * V_150 = (struct V_528 * ) V_318 ;
V_150 -> type = F_16 ( V_300 ) ;
V_150 -> V_151 = F_16 ( V_529 ) ;
if ( ! V_309 )
V_306 |= V_310 | V_311
| V_464 ;
if ( V_10 -> V_260 & V_261 )
V_306 |= V_448
| V_447 ;
F_105 ( V_306 , V_150 -> V_186 ) ;
F_81 ( V_10 , V_425 -> V_16 , V_530 , sizeof( V_318 ) ,
V_318 ) ;
} else if ( type == V_531 ) {
T_3 V_318 [ 12 ] ;
struct V_528 * V_150 = (struct V_528 * ) V_318 ;
V_150 -> type = F_16 ( V_531 ) ;
V_150 -> V_151 = F_16 ( V_529 ) ;
V_150 -> V_186 [ 0 ] = V_10 -> V_260 ;
memset ( V_150 -> V_186 + 1 , 0 , 7 ) ;
F_81 ( V_10 , V_425 -> V_16 , V_530 , sizeof( V_318 ) ,
V_318 ) ;
} else {
struct V_528 V_150 ;
V_150 . type = F_16 ( type ) ;
V_150 . V_151 = F_16 ( V_532 ) ;
F_81 ( V_10 , V_425 -> V_16 , V_530 , sizeof( V_150 ) ,
& V_150 ) ;
}
return 0 ;
}
static inline int F_250 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
struct V_528 * V_150 = (struct V_528 * ) V_186 ;
T_2 type , V_151 ;
if ( V_497 < sizeof( * V_150 ) )
return - V_500 ;
type = F_67 ( V_150 -> type ) ;
V_151 = F_67 ( V_150 -> V_151 ) ;
F_21 ( L_51 , type , V_151 ) ;
if ( V_425 -> V_16 != V_10 -> V_301 ||
V_10 -> V_298 & V_305 )
return 0 ;
F_234 ( & V_10 -> V_302 ) ;
if ( V_151 != V_529 ) {
V_10 -> V_298 |= V_305 ;
V_10 -> V_301 = 0 ;
F_138 ( V_10 ) ;
return 0 ;
}
switch ( type ) {
case V_300 :
V_10 -> V_306 = F_99 ( V_150 -> V_186 ) ;
if ( V_10 -> V_306 & V_533 ) {
struct V_297 V_270 ;
V_270 . type = F_16 ( V_531 ) ;
V_10 -> V_301 = F_89 ( V_10 ) ;
F_81 ( V_10 , V_10 -> V_301 ,
V_304 , sizeof( V_270 ) , & V_270 ) ;
} else {
V_10 -> V_298 |= V_305 ;
V_10 -> V_301 = 0 ;
F_138 ( V_10 ) ;
}
break;
case V_531 :
V_10 -> V_262 = V_150 -> V_186 [ 0 ] ;
V_10 -> V_298 |= V_305 ;
V_10 -> V_301 = 0 ;
F_138 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_251 ( struct V_9 * V_10 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_186 )
{
struct V_273 * V_270 = V_186 ;
struct V_534 V_150 ;
struct V_8 * V_20 ;
struct V_258 * V_187 ;
T_2 V_17 , V_14 ;
if ( V_497 != sizeof( * V_270 ) )
return - V_500 ;
if ( ! ( V_10 -> V_260 & V_261 ) )
return - V_26 ;
V_17 = F_226 ( V_270 -> V_17 ) ;
V_14 = F_226 ( V_270 -> V_14 ) ;
F_21 ( L_52 , V_17 , V_14 , V_270 -> V_272 ) ;
if ( V_270 -> V_272 == V_444 ) {
F_235 ( V_10 , V_425 , V_186 , V_495 ,
V_270 -> V_272 ) ;
return 0 ;
}
V_187 = F_252 ( V_270 -> V_272 ) ;
if ( ! V_187 )
goto error;
if ( V_187 -> V_535 != V_536 || ! F_68 ( V_266 , & V_187 -> V_100 ) ) {
F_253 ( V_187 ) ;
goto error;
}
V_20 = F_235 ( V_10 , V_425 , V_186 , V_495 ,
V_270 -> V_272 ) ;
if ( V_20 ) {
struct V_133 * V_134 = V_10 -> V_2 -> V_133 ;
struct V_1 * V_198 ;
V_198 = F_254 ( V_187 , V_537 ,
& V_10 -> V_2 -> V_147 ) ;
if ( ! V_198 ) {
F_253 ( V_187 ) ;
F_242 ( V_10 , V_425 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
return 0 ;
}
F_21 ( L_53 , V_134 , V_20 , V_198 ) ;
V_134 -> V_135 = V_20 ;
V_20 -> V_198 = V_198 ;
V_20 -> V_84 = V_465 ;
V_10 -> V_156 = V_187 -> V_538 ;
}
F_253 ( V_187 ) ;
return 0 ;
error:
V_150 . V_13 = 0 ;
V_150 . V_14 = F_16 ( V_14 ) ;
V_150 . V_151 = F_16 ( V_539 ) ;
V_150 . V_161 = F_16 ( V_162 ) ;
F_81 ( V_10 , V_425 -> V_16 , V_495 ,
sizeof( V_150 ) , & V_150 ) ;
return 0 ;
}
static void F_255 ( struct V_8 * V_20 , T_3 V_540 )
{
struct V_541 V_270 ;
T_3 V_16 ;
F_21 ( L_54 , V_20 , V_540 ) ;
V_16 = F_89 ( V_20 -> V_10 ) ;
V_20 -> V_16 = V_16 ;
V_270 . V_542 = F_16 ( V_20 -> V_14 ) ;
V_270 . V_540 = V_540 ;
F_81 ( V_20 -> V_10 , V_16 , V_543 , sizeof( V_270 ) ,
& V_270 ) ;
F_83 ( V_20 , V_544 ) ;
}
static void F_256 ( struct V_8 * V_20 , T_2 V_151 )
{
struct V_545 V_150 ;
F_21 ( L_55 , V_20 , V_151 ) ;
V_150 . V_542 = F_16 ( V_20 -> V_13 ) ;
V_150 . V_151 = F_16 ( V_151 ) ;
F_81 ( V_20 -> V_10 , V_20 -> V_16 , V_546 ,
sizeof( V_150 ) , & V_150 ) ;
}
static void F_257 ( struct V_8 * V_20 , T_2 V_151 )
{
struct V_547 V_548 ;
F_21 ( L_55 , V_20 , V_151 ) ;
V_20 -> V_16 = F_89 ( V_20 -> V_10 ) ;
V_548 . V_542 = F_16 ( V_20 -> V_14 ) ;
V_548 . V_151 = F_16 ( V_151 ) ;
F_81 ( V_20 -> V_10 , V_20 -> V_16 , V_549 ,
sizeof( V_548 ) , & V_548 ) ;
F_83 ( V_20 , V_544 ) ;
}
static void F_258 ( struct V_9 * V_10 , T_2 V_542 )
{
struct V_547 V_548 ;
F_21 ( L_56 , V_10 , V_542 ) ;
V_548 . V_542 = F_16 ( V_542 ) ;
V_548 . V_151 = F_16 ( V_550 ) ;
F_81 ( V_10 , F_89 ( V_10 ) , V_549 ,
sizeof( V_548 ) , & V_548 ) ;
}
static void F_259 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_542 )
{
struct V_551 V_150 ;
F_21 ( L_57 , V_542 ) ;
V_150 . V_542 = F_16 ( V_542 ) ;
F_81 ( V_10 , V_16 , V_552 , sizeof( V_150 ) , & V_150 ) ;
}
static void F_260 ( struct V_8 * V_20 )
{
V_20 -> V_136 = NULL ;
V_20 -> V_198 = NULL ;
}
static void F_261 ( struct V_8 * V_20 )
{
if ( V_20 -> V_35 != V_65 ) {
F_84 ( V_20 , V_317 ) ;
return;
}
switch ( V_20 -> V_285 ) {
case V_290 :
F_126 ( V_20 ) ;
F_256 ( V_20 , V_553 ) ;
break;
case V_287 :
if ( V_20 -> V_195 == V_554 ||
V_20 -> V_195 == V_555 ) {
F_126 ( V_20 ) ;
}
F_257 ( V_20 , V_550 ) ;
break;
}
}
static void F_262 ( struct V_8 * V_20 ,
struct V_137 * V_194 )
{
struct V_468 V_150 ;
V_20 -> V_136 = V_194 ;
V_20 -> V_198 -> V_355 = V_20 -> V_10 ;
F_241 ( V_20 , & V_150 , V_20 -> V_16 , 0 ) ;
if ( F_68 ( V_521 , & V_20 -> V_82 ) ) {
int V_21 ;
F_240 ( V_20 ) ;
V_21 = F_218 ( V_20 ) ;
if ( V_21 < 0 )
F_84 ( V_20 , - V_21 ) ;
else
F_128 ( V_20 ) ;
}
}
static void F_263 ( struct V_8 * V_20 ,
struct V_137 * V_194 )
{
V_20 -> V_198 = V_194 -> V_10 ;
V_20 -> V_198 -> V_355 = V_20 -> V_10 ;
F_21 ( L_58 , V_20 -> V_195 ) ;
switch ( V_20 -> V_195 ) {
case V_554 :
V_20 -> V_195 = V_556 ;
break;
case V_555 :
if ( F_68 ( V_255 , & V_20 -> V_249 ) ) {
V_20 -> V_195 = V_557 ;
} else if ( V_20 -> V_285 == V_287 ) {
V_20 -> V_195 = V_558 ;
F_257 ( V_20 , V_559 ) ;
} else if ( V_20 -> V_285 == V_290 ) {
V_20 -> V_195 = V_560 ;
F_256 ( V_20 , V_561 ) ;
}
break;
default:
F_260 ( V_20 ) ;
V_20 -> V_195 = V_196 ;
}
}
void F_264 ( struct V_8 * V_20 , struct V_137 * V_194 ,
T_3 V_161 )
{
F_21 ( L_59 , V_20 , V_194 , V_161 ) ;
if ( V_161 ) {
F_261 ( V_20 ) ;
F_260 ( V_20 ) ;
return;
}
if ( V_20 -> V_35 != V_65 ) {
if ( V_20 -> V_443 != V_444 )
F_262 ( V_20 , V_194 ) ;
} else {
F_263 ( V_20 , V_194 ) ;
}
}
void F_265 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_443 == V_444 ) {
if ( V_20 -> V_267 != V_268 )
return;
V_20 -> V_285 = V_287 ;
V_20 -> V_195 = V_197 ;
} else {
V_20 -> V_285 = V_287 ;
V_20 -> V_195 = V_556 ;
V_20 -> V_445 = 0 ;
F_125 ( V_20 ) ;
F_255 ( V_20 , 0 ) ;
}
}
static void F_266 ( struct V_8 * V_20 , int V_151 ,
T_3 V_443 , T_3 V_562 )
{
F_21 ( L_60 , V_20 , F_22 ( V_20 -> V_35 ) ,
V_443 , V_562 ) ;
V_20 -> V_84 = V_465 ;
if ( V_20 -> V_35 == V_68 ) {
if ( V_151 == V_322 ) {
V_20 -> V_443 = V_443 ;
F_124 ( V_20 , V_562 ) ;
} else {
F_123 ( V_20 ) ;
}
return;
}
if ( F_118 ( V_20 ) ) {
struct V_159 V_150 ;
char V_318 [ 128 ] ;
V_150 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_150 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( V_151 == V_322 ) {
V_150 . V_151 = F_16 ( V_322 ) ;
V_150 . V_161 = F_16 ( V_162 ) ;
} else {
V_150 . V_151 = F_16 ( V_506 ) ;
V_150 . V_161 = F_16 ( V_162 ) ;
}
F_81 ( V_20 -> V_10 , V_20 -> V_16 , V_495 ,
sizeof( V_150 ) , & V_150 ) ;
if ( V_151 == V_322 ) {
F_20 ( V_20 , V_66 ) ;
F_55 ( V_324 , & V_20 -> V_82 ) ;
F_81 ( V_20 -> V_10 , F_89 ( V_20 -> V_10 ) ,
V_325 ,
F_140 ( V_20 , V_318 ) , V_318 ) ;
V_20 -> V_326 ++ ;
}
}
}
static void F_267 ( struct V_8 * V_20 , T_3 V_443 ,
T_3 V_562 )
{
F_125 ( V_20 ) ;
V_20 -> V_445 = V_443 ;
V_20 -> V_195 = V_563 ;
F_255 ( V_20 , V_562 ) ;
}
static void F_268 ( struct V_8 * V_20 , int V_151 )
{
struct V_137 * V_194 = NULL ;
if ( V_194 ) {
if ( V_194 -> V_35 == V_65 ) {
V_20 -> V_198 = V_194 -> V_10 ;
V_20 -> V_198 -> V_355 = V_20 -> V_10 ;
V_20 -> V_195 = V_560 ;
F_256 ( V_20 , V_561 ) ;
F_264 ( V_20 , V_194 , V_561 ) ;
} else {
V_20 -> V_195 = V_555 ;
}
} else {
F_256 ( V_20 , V_564 ) ;
}
}
static void F_269 ( struct V_8 * V_20 , int V_151 )
{
if ( V_20 -> V_285 == V_290 ) {
T_3 V_565 ;
if ( V_151 == - V_26 )
V_565 = V_566 ;
else
V_565 = V_564 ;
F_256 ( V_20 , V_565 ) ;
}
V_20 -> V_285 = V_286 ;
V_20 -> V_195 = V_196 ;
F_170 ( V_20 ) ;
}
void F_270 ( struct V_8 * V_20 , int V_151 )
{
T_3 V_443 = V_20 -> V_443 ;
T_3 V_562 = V_20 -> V_562 ;
F_21 ( L_61 ,
V_20 , V_151 , V_443 , V_562 ) ;
if ( V_20 -> V_35 == V_155 || V_20 -> V_35 == V_567 ) {
F_46 ( V_20 ) ;
return;
}
if ( V_20 -> V_35 != V_65 ) {
F_266 ( V_20 , V_151 , V_443 , V_562 ) ;
} else if ( V_151 != V_561 ) {
F_269 ( V_20 , V_151 ) ;
} else {
switch ( V_20 -> V_285 ) {
case V_287 :
F_267 ( V_20 , V_443 ,
V_562 ) ;
break;
case V_290 :
F_268 ( V_20 , V_151 ) ;
break;
default:
F_269 ( V_20 , V_151 ) ;
break;
}
}
}
static inline int F_271 ( struct V_9 * V_10 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_186 )
{
struct V_541 * V_270 = V_186 ;
struct V_545 V_150 ;
struct V_8 * V_20 ;
T_2 V_542 = 0 ;
T_2 V_151 = V_564 ;
if ( V_497 != sizeof( * V_270 ) )
return - V_500 ;
V_542 = F_226 ( V_270 -> V_542 ) ;
F_21 ( L_62 , V_542 , V_270 -> V_540 ) ;
if ( ! ( V_10 -> V_260 & V_261 ) )
return - V_26 ;
V_20 = F_9 ( V_10 , V_542 ) ;
if ( ! V_20 ) {
V_150 . V_542 = F_16 ( V_542 ) ;
V_150 . V_151 = F_16 ( V_564 ) ;
F_81 ( V_10 , V_425 -> V_16 , V_546 ,
sizeof( V_150 ) , & V_150 ) ;
return 0 ;
}
V_20 -> V_16 = V_425 -> V_16 ;
if ( V_20 -> V_14 < V_34 ||
V_20 -> V_267 == V_568 ||
( V_20 -> V_138 != V_141 &&
V_20 -> V_138 != V_145 ) ) {
V_151 = V_564 ;
goto V_569;
}
if ( V_20 -> V_443 == V_270 -> V_540 ) {
V_151 = V_570 ;
goto V_569;
}
if ( V_270 -> V_540 != V_444 ) {
struct V_258 * V_187 ;
V_187 = F_252 ( V_270 -> V_540 ) ;
if ( ! V_187 || V_187 -> V_535 != V_536 ||
! F_68 ( V_266 , & V_187 -> V_100 ) ) {
if ( V_187 )
F_253 ( V_187 ) ;
V_151 = V_566 ;
goto V_569;
}
F_253 ( V_187 ) ;
}
if ( ( F_93 ( V_20 ) ||
V_20 -> V_285 != V_286 ) &&
F_13 ( & V_10 -> V_2 -> V_18 , & V_10 -> V_2 -> V_147 ) > 0 ) {
V_151 = V_571 ;
goto V_569;
}
V_20 -> V_285 = V_290 ;
F_125 ( V_20 ) ;
V_20 -> V_445 = V_270 -> V_540 ;
V_542 = V_20 -> V_13 ;
if ( V_270 -> V_540 == V_444 ) {
if ( F_68 ( V_255 , & V_20 -> V_249 ) ) {
V_20 -> V_195 = V_557 ;
V_151 = V_572 ;
} else {
V_20 -> V_195 = V_560 ;
V_151 = V_561 ;
}
} else {
V_20 -> V_195 = V_197 ;
V_151 = V_572 ;
}
V_569:
F_256 ( V_20 , V_151 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static void F_272 ( struct V_9 * V_10 , T_2 V_542 , T_2 V_151 )
{
struct V_8 * V_20 ;
struct V_137 * V_194 = NULL ;
V_20 = F_5 ( V_10 , V_542 ) ;
if ( ! V_20 ) {
F_258 ( V_10 , V_542 ) ;
return;
}
F_72 ( V_20 ) ;
if ( V_151 == V_572 )
F_83 ( V_20 , V_573 ) ;
switch ( V_20 -> V_195 ) {
case V_554 :
V_20 -> V_195 = V_555 ;
break;
case V_556 :
if ( V_151 == V_572 ) {
break;
} else if ( F_68 ( V_255 ,
& V_20 -> V_249 ) ) {
V_20 -> V_195 = V_557 ;
} else {
V_20 -> V_195 = V_558 ;
F_257 ( V_20 , V_559 ) ;
}
break;
case V_563 :
if ( V_151 == V_561 ) {
V_20 -> V_195 = V_555 ;
} else {
V_20 -> V_195 = V_554 ;
}
if ( ! V_194 ) {
F_257 ( V_20 , V_550 ) ;
break;
}
if ( V_194 -> V_35 != V_65 )
break;
V_20 -> V_198 = V_194 -> V_10 ;
V_20 -> V_198 -> V_355 = V_20 -> V_10 ;
if ( V_151 == V_561 ) {
F_257 ( V_20 , V_559 ) ;
} else {
V_20 -> V_195 = V_556 ;
}
F_264 ( V_20 , V_194 , V_561 ) ;
break;
default:
V_20 -> V_445 = V_20 -> V_443 ;
F_126 ( V_20 ) ;
F_257 ( V_20 , V_550 ) ;
}
F_46 ( V_20 ) ;
}
static void F_273 ( struct V_9 * V_10 , T_3 V_16 , T_2 V_542 ,
T_2 V_151 )
{
struct V_8 * V_20 ;
V_20 = F_11 ( V_10 , V_16 ) ;
if ( ! V_20 ) {
F_258 ( V_10 , V_542 ) ;
return;
}
F_72 ( V_20 ) ;
if ( V_20 -> V_285 == V_287 ) {
if ( V_151 == V_571 ) {
V_20 -> V_285 = V_290 ;
} else {
V_20 -> V_445 = V_20 -> V_443 ;
F_126 ( V_20 ) ;
}
}
F_257 ( V_20 , V_550 ) ;
F_46 ( V_20 ) ;
}
static int F_274 ( struct V_9 * V_10 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_186 )
{
struct V_545 * V_150 = V_186 ;
T_2 V_542 , V_151 ;
if ( V_497 != sizeof( * V_150 ) )
return - V_500 ;
V_542 = F_226 ( V_150 -> V_542 ) ;
V_151 = F_226 ( V_150 -> V_151 ) ;
F_21 ( L_63 , V_542 , V_151 ) ;
if ( V_151 == V_561 || V_151 == V_572 )
F_272 ( V_10 , V_542 , V_151 ) ;
else
F_273 ( V_10 , V_425 -> V_16 , V_542 , V_151 ) ;
return 0 ;
}
static int F_275 ( struct V_9 * V_10 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_186 )
{
struct V_547 * V_548 = V_186 ;
struct V_8 * V_20 ;
T_2 V_542 , V_151 ;
if ( V_497 != sizeof( * V_548 ) )
return - V_500 ;
V_542 = F_226 ( V_548 -> V_542 ) ;
V_151 = F_226 ( V_548 -> V_151 ) ;
F_21 ( L_63 , V_542 , V_151 ) ;
V_20 = F_9 ( V_10 , V_542 ) ;
if ( ! V_20 ) {
F_259 ( V_10 , V_425 -> V_16 , V_542 ) ;
return 0 ;
}
if ( V_20 -> V_195 == V_560 ) {
if ( V_151 == V_559 ) {
V_20 -> V_443 = V_20 -> V_445 ;
if ( V_20 -> V_443 == V_444 )
F_260 ( V_20 ) ;
} else {
V_20 -> V_445 = V_20 -> V_443 ;
}
F_126 ( V_20 ) ;
}
F_259 ( V_10 , V_425 -> V_16 , V_542 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static inline int F_276 ( struct V_9 * V_10 ,
struct V_424 * V_425 ,
T_2 V_497 , void * V_186 )
{
struct V_551 * V_150 = V_186 ;
struct V_8 * V_20 ;
T_2 V_542 ;
if ( V_497 != sizeof( * V_150 ) )
return - V_500 ;
V_542 = F_226 ( V_150 -> V_542 ) ;
F_21 ( L_57 , V_542 ) ;
V_20 = F_5 ( V_10 , V_542 ) ;
if ( ! V_20 )
return 0 ;
F_72 ( V_20 ) ;
if ( V_20 -> V_195 == V_558 ) {
V_20 -> V_443 = V_20 -> V_445 ;
if ( V_20 -> V_443 == V_444 && V_20 -> V_136 )
F_260 ( V_20 ) ;
F_126 ( V_20 ) ;
}
F_46 ( V_20 ) ;
return 0 ;
}
static inline int V_335 ( struct V_9 * V_10 ,
struct V_424 * V_425 ,
T_2 V_497 , T_3 * V_186 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_335 * V_270 ;
struct V_574 V_150 ;
T_2 V_336 , V_337 , V_338 , V_340 ;
int V_21 ;
if ( V_2 -> V_330 != V_575 )
return - V_26 ;
if ( V_497 != sizeof( struct V_335 ) )
return - V_500 ;
V_270 = (struct V_335 * ) V_186 ;
V_336 = F_67 ( V_270 -> V_336 ) ;
V_337 = F_67 ( V_270 -> V_337 ) ;
V_338 = F_67 ( V_270 -> V_338 ) ;
V_340 = F_67 ( V_270 -> V_340 ) ;
F_21 ( L_64 ,
V_336 , V_337 , V_338 , V_340 ) ;
memset ( & V_150 , 0 , sizeof( V_150 ) ) ;
V_21 = F_277 ( V_336 , V_337 , V_338 , V_340 ) ;
if ( V_21 )
V_150 . V_151 = F_16 ( V_576 ) ;
else
V_150 . V_151 = F_16 ( V_577 ) ;
F_81 ( V_10 , V_425 -> V_16 , V_578 ,
sizeof( V_150 ) , & V_150 ) ;
if ( ! V_21 ) {
T_3 V_579 ;
V_579 = F_278 ( V_2 , V_336 , V_337 , V_338 ,
V_340 ) ;
F_279 ( V_2 -> V_187 , & V_2 -> V_147 , V_2 -> V_148 ,
V_579 , V_336 , V_337 , V_338 ,
V_340 ) ;
}
return 0 ;
}
static int F_280 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
struct V_149 * V_150 = (struct V_149 * ) V_186 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_13 , V_156 , V_107 , V_157 , V_151 ;
struct V_8 * V_20 ;
int V_21 , V_69 ;
if ( V_497 < sizeof( * V_150 ) )
return - V_500 ;
V_13 = F_67 ( V_150 -> V_13 ) ;
V_156 = F_67 ( V_150 -> V_156 ) ;
V_107 = F_67 ( V_150 -> V_107 ) ;
V_157 = F_67 ( V_150 -> V_157 ) ;
V_151 = F_67 ( V_150 -> V_151 ) ;
if ( V_151 == V_322 && ( V_156 < 23 || V_107 < 23 ) )
return - V_500 ;
F_21 ( L_65 ,
V_13 , V_156 , V_107 , V_157 , V_151 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_10 ( V_10 , V_425 -> V_16 ) ;
if ( ! V_20 ) {
V_21 = - V_513 ;
goto V_514;
}
V_21 = 0 ;
F_7 ( V_20 ) ;
switch ( V_151 ) {
case V_322 :
V_20 -> V_16 = 0 ;
V_20 -> V_13 = V_13 ;
V_20 -> V_27 = V_156 ;
V_20 -> V_399 = V_107 ;
V_20 -> V_104 = V_157 ;
F_128 ( V_20 ) ;
break;
case V_580 :
case V_581 :
if ( V_2 -> V_69 > V_171 ) {
F_71 ( V_20 , V_67 ) ;
break;
}
V_69 = V_2 -> V_69 + 1 ;
if ( V_20 -> V_69 < V_69 )
V_20 -> V_69 = V_69 ;
F_115 ( V_295 , & V_20 -> V_100 ) ;
F_87 ( V_2 , V_20 -> V_69 ) ;
break;
default:
F_71 ( V_20 , V_67 ) ;
break;
}
F_46 ( V_20 ) ;
V_514:
F_8 ( & V_10 -> V_15 ) ;
return V_21 ;
}
static inline int F_281 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
int V_21 = 0 ;
switch ( V_425 -> V_184 ) {
case V_518 :
F_233 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_271 :
V_21 = F_237 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_163 :
case V_495 :
F_239 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_325 :
V_21 = F_244 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_515 :
F_245 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_314 :
V_21 = F_247 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_526 :
F_248 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_582 :
F_81 ( V_10 , V_425 -> V_16 , V_583 , V_497 , V_186 ) ;
break;
case V_583 :
break;
case V_304 :
V_21 = F_249 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_530 :
F_250 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_274 :
V_21 = F_251 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_543 :
V_21 = F_271 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_546 :
F_274 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_549 :
V_21 = F_275 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_552 :
F_276 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
default:
F_282 ( L_66 , V_425 -> V_184 ) ;
V_21 = - V_26 ;
break;
}
return V_21 ;
}
static int F_283 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
struct V_294 * V_270 = (struct V_294 * ) V_186 ;
struct V_149 V_150 ;
struct V_8 * V_20 , * V_502 ;
T_2 V_13 , V_14 , V_157 , V_156 , V_107 ;
T_4 V_17 ;
T_3 V_151 ;
if ( V_497 != sizeof( * V_270 ) )
return - V_500 ;
V_14 = F_67 ( V_270 -> V_14 ) ;
V_156 = F_67 ( V_270 -> V_156 ) ;
V_107 = F_67 ( V_270 -> V_107 ) ;
V_17 = V_270 -> V_17 ;
V_13 = 0 ;
V_157 = 0 ;
if ( V_156 < 23 || V_107 < 23 )
return - V_500 ;
F_21 ( L_67 , F_67 ( V_17 ) ,
V_14 , V_156 , V_107 ) ;
V_502 = F_162 ( V_164 , V_17 , & V_10 -> V_2 -> V_18 ,
& V_10 -> V_2 -> V_147 , V_3 ) ;
if ( ! V_502 ) {
V_151 = V_154 ;
V_20 = NULL ;
goto V_505;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_502 ) ;
if ( ! F_284 ( V_10 -> V_2 , V_502 -> V_69 ,
V_584 ) ) {
V_151 = V_580 ;
V_20 = NULL ;
goto V_585;
}
if ( F_2 ( V_10 , V_14 ) ) {
V_151 = V_506 ;
V_20 = NULL ;
goto V_585;
}
V_20 = V_502 -> V_36 -> V_507 ( V_502 ) ;
if ( ! V_20 ) {
V_151 = V_506 ;
goto V_585;
}
F_63 ( V_20 ) ;
F_79 ( & V_20 -> V_18 , & V_10 -> V_2 -> V_18 ) ;
F_79 ( & V_20 -> V_147 , & V_10 -> V_2 -> V_147 ) ;
V_20 -> V_363 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_363 ) ;
V_20 -> V_148 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_148 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_14 ;
V_20 -> V_27 = V_156 ;
V_20 -> V_399 = V_107 ;
V_20 -> V_104 = F_67 ( V_270 -> V_157 ) ;
F_66 ( V_10 , V_20 ) ;
V_13 = V_20 -> V_14 ;
V_157 = V_20 -> V_105 ;
F_83 ( V_20 , V_20 -> V_36 -> V_165 ( V_20 ) ) ;
V_20 -> V_16 = V_425 -> V_16 ;
if ( F_68 ( V_152 , & V_20 -> V_100 ) ) {
F_20 ( V_20 , V_166 ) ;
V_151 = V_319 ;
V_20 -> V_36 -> V_321 ( V_20 ) ;
} else {
F_128 ( V_20 ) ;
V_151 = V_322 ;
}
V_585:
F_46 ( V_502 ) ;
F_8 ( & V_10 -> V_15 ) ;
F_47 ( V_502 ) ;
if ( V_151 == V_319 )
return 0 ;
V_505:
if ( V_20 ) {
V_150 . V_156 = F_16 ( V_20 -> V_108 ) ;
V_150 . V_107 = F_16 ( V_20 -> V_107 ) ;
} else {
V_150 . V_156 = 0 ;
V_150 . V_107 = 0 ;
}
V_150 . V_13 = F_16 ( V_13 ) ;
V_150 . V_157 = F_16 ( V_157 ) ;
V_150 . V_151 = F_16 ( V_151 ) ;
F_81 ( V_10 , V_425 -> V_16 , V_158 , sizeof( V_150 ) , & V_150 ) ;
return 0 ;
}
static inline int F_285 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
struct F_285 * V_586 ;
struct V_8 * V_20 ;
T_2 V_11 , V_157 , V_587 ;
if ( V_497 != sizeof( * V_586 ) )
return - V_500 ;
V_586 = (struct F_285 * ) V_186 ;
V_11 = F_67 ( V_586 -> V_11 ) ;
V_157 = F_67 ( V_586 -> V_157 ) ;
F_21 ( L_68 , V_11 , V_157 ) ;
V_20 = F_9 ( V_10 , V_11 ) ;
if ( ! V_20 )
return - V_513 ;
V_587 = V_588 - V_20 -> V_104 ;
if ( V_157 > V_587 ) {
F_282 ( L_69 ) ;
F_84 ( V_20 , V_317 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
V_20 -> V_104 += V_157 ;
while ( V_20 -> V_104 && ! F_167 ( & V_20 -> V_110 ) ) {
F_94 ( V_20 , F_168 ( & V_20 -> V_110 ) ) ;
V_20 -> V_104 -- ;
}
if ( V_20 -> V_104 )
V_20 -> V_36 -> V_589 ( V_20 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static inline int F_286 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
struct V_498 * V_499 = (struct V_498 * ) V_186 ;
struct V_8 * V_20 ;
if ( V_497 < sizeof( * V_499 ) )
return - V_500 ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_10 ( V_10 , V_425 -> V_16 ) ;
if ( ! V_20 )
goto V_24;
F_7 ( V_20 ) ;
F_71 ( V_20 , V_67 ) ;
F_46 ( V_20 ) ;
V_24:
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_287 ( struct V_9 * V_10 ,
struct V_424 * V_425 , T_2 V_497 ,
T_3 * V_186 )
{
int V_21 = 0 ;
switch ( V_425 -> V_184 ) {
case V_518 :
F_286 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_342 :
V_21 = V_335 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_578 :
break;
case V_158 :
F_280 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_296 :
V_21 = F_283 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_590 :
V_21 = F_285 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_314 :
V_21 = F_247 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
case V_526 :
F_248 ( V_10 , V_425 , V_497 , V_186 ) ;
break;
default:
F_282 ( L_70 , V_425 -> V_184 ) ;
V_21 = - V_26 ;
break;
}
return V_21 ;
}
static inline void F_288 ( struct V_9 * V_10 ,
struct V_42 * V_46 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_424 * V_425 ;
T_2 V_185 ;
int V_21 ;
if ( V_2 -> type != V_3 )
goto V_591;
if ( V_46 -> V_185 < V_426 )
goto V_591;
V_425 = ( void * ) V_46 -> V_186 ;
F_100 ( V_46 , V_426 ) ;
V_185 = F_226 ( V_425 -> V_185 ) ;
F_21 ( L_71 , V_425 -> V_184 , V_185 , V_425 -> V_16 ) ;
if ( V_185 != V_46 -> V_185 || ! V_425 -> V_16 ) {
F_21 ( L_72 ) ;
goto V_591;
}
V_21 = F_287 ( V_10 , V_425 , V_185 , V_46 -> V_186 ) ;
if ( V_21 ) {
struct V_498 V_499 ;
F_282 ( L_73 , V_21 ) ;
V_499 . V_64 = F_16 ( V_501 ) ;
F_81 ( V_10 , V_425 -> V_16 , V_518 ,
sizeof( V_499 ) , & V_499 ) ;
}
V_591:
F_95 ( V_46 ) ;
}
static inline void F_289 ( struct V_9 * V_10 ,
struct V_42 * V_46 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 * V_186 = V_46 -> V_186 ;
int V_185 = V_46 -> V_185 ;
struct V_424 V_425 ;
int V_21 ;
F_212 ( V_10 , V_46 ) ;
if ( V_2 -> type != V_114 )
goto V_591;
while ( V_185 >= V_426 ) {
T_2 V_497 ;
memcpy ( & V_425 , V_186 , V_426 ) ;
V_186 += V_426 ;
V_185 -= V_426 ;
V_497 = F_226 ( V_425 . V_185 ) ;
F_21 ( L_71 , V_425 . V_184 , V_497 ,
V_425 . V_16 ) ;
if ( V_497 > V_185 || ! V_425 . V_16 ) {
F_21 ( L_72 ) ;
break;
}
V_21 = F_281 ( V_10 , & V_425 , V_497 , V_186 ) ;
if ( V_21 ) {
struct V_498 V_499 ;
F_282 ( L_73 , V_21 ) ;
V_499 . V_64 = F_16 ( V_501 ) ;
F_81 ( V_10 , V_425 . V_16 , V_518 ,
sizeof( V_499 ) , & V_499 ) ;
}
V_186 += V_497 ;
V_185 -= V_497 ;
}
V_591:
F_95 ( V_46 ) ;
}
static int F_290 ( struct V_8 * V_20 , struct V_42 * V_46 )
{
T_2 V_592 , V_593 ;
int V_594 ;
if ( F_68 ( V_236 , & V_20 -> V_100 ) )
V_594 = V_241 ;
else
V_594 = V_242 ;
if ( V_20 -> V_84 == V_85 ) {
F_291 ( V_46 , V_46 -> V_185 - V_246 ) ;
V_593 = F_101 ( V_46 -> V_186 + V_46 -> V_185 ) ;
V_592 = F_112 ( 0 , V_46 -> V_186 - V_594 , V_46 -> V_185 + V_594 ) ;
if ( V_592 != V_593 )
return - V_595 ;
}
return 0 ;
}
static void F_292 ( struct V_8 * V_20 )
{
struct V_202 V_47 ;
F_21 ( L_3 , V_20 ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_210 = 1 ;
V_47 . V_206 = 1 ;
V_47 . V_203 = V_20 -> V_256 ;
F_55 ( V_248 , & V_20 -> V_249 ) ;
if ( F_68 ( V_255 , & V_20 -> V_249 ) ) {
V_47 . V_214 = V_252 ;
F_113 ( V_20 , & V_47 ) ;
}
if ( F_114 ( V_284 , & V_20 -> V_249 ) &&
V_20 -> V_378 > 0 )
F_25 ( V_20 ) ;
F_170 ( V_20 ) ;
if ( ! F_68 ( V_255 , & V_20 -> V_249 ) &&
F_68 ( V_248 , & V_20 -> V_249 ) ) {
V_47 . V_214 = V_250 ;
F_113 ( V_20 , & V_47 ) ;
}
}
static void F_293 ( struct V_42 * V_46 , struct V_42 * V_596 ,
struct V_42 * * V_597 )
{
if ( ! F_294 ( V_46 ) )
F_187 ( V_46 ) -> V_388 = V_596 ;
V_596 -> V_349 = NULL ;
( * V_597 ) -> V_349 = V_596 ;
* V_597 = V_596 ;
V_46 -> V_185 += V_596 -> V_185 ;
V_46 -> V_392 += V_596 -> V_185 ;
V_46 -> V_598 += V_596 -> V_598 ;
}
static int F_295 ( struct V_8 * V_20 , struct V_42 * V_46 ,
struct V_202 * V_47 )
{
int V_21 = - V_26 ;
switch ( V_47 -> V_217 ) {
case V_400 :
if ( V_20 -> V_101 )
break;
V_21 = V_20 -> V_36 -> V_422 ( V_20 , V_46 ) ;
break;
case V_401 :
if ( V_20 -> V_101 )
break;
V_20 -> V_103 = F_101 ( V_46 -> V_186 ) ;
F_100 ( V_46 , V_395 ) ;
if ( V_20 -> V_103 > V_20 -> V_108 ) {
V_21 = - V_404 ;
break;
}
if ( V_46 -> V_185 >= V_20 -> V_103 )
break;
V_20 -> V_101 = V_46 ;
V_20 -> V_102 = V_46 ;
V_46 = NULL ;
V_21 = 0 ;
break;
case V_403 :
if ( ! V_20 -> V_101 )
break;
F_293 ( V_20 -> V_101 , V_46 ,
& V_20 -> V_102 ) ;
V_46 = NULL ;
if ( V_20 -> V_101 -> V_185 >= V_20 -> V_103 )
break;
V_21 = 0 ;
break;
case V_402 :
if ( ! V_20 -> V_101 )
break;
F_293 ( V_20 -> V_101 , V_46 ,
& V_20 -> V_102 ) ;
V_46 = NULL ;
if ( V_20 -> V_101 -> V_185 != V_20 -> V_103 )
break;
V_21 = V_20 -> V_36 -> V_422 ( V_20 , V_20 -> V_101 ) ;
if ( ! V_21 ) {
V_20 -> V_101 = NULL ;
V_20 -> V_102 = NULL ;
V_20 -> V_103 = 0 ;
}
break;
}
if ( V_21 ) {
F_95 ( V_46 ) ;
F_95 ( V_20 -> V_101 ) ;
V_20 -> V_101 = NULL ;
V_20 -> V_102 = NULL ;
V_20 -> V_103 = 0 ;
}
return V_21 ;
}
static int F_296 ( struct V_8 * V_20 )
{
return 0 ;
}
void F_297 ( struct V_8 * V_20 , int V_599 )
{
T_3 V_412 ;
if ( V_20 -> V_138 != V_141 )
return;
V_412 = V_599 ? V_413 : V_415 ;
F_127 ( V_20 , NULL , NULL , V_412 ) ;
}
static int F_298 ( struct V_8 * V_20 )
{
int V_21 = 0 ;
F_21 ( L_3 , V_20 ) ;
while ( ! F_68 ( V_255 , & V_20 -> V_249 ) ) {
struct V_42 * V_46 ;
F_21 ( L_74 ,
V_20 -> V_256 , F_174 ( & V_20 -> V_142 ) ) ;
V_46 = F_31 ( & V_20 -> V_142 , V_20 -> V_256 ) ;
if ( ! V_46 )
break;
F_205 ( V_46 , & V_20 -> V_142 ) ;
V_20 -> V_256 = F_169 ( V_20 , V_20 -> V_256 ) ;
V_21 = F_295 ( V_20 , V_46 , & F_33 ( V_46 ) -> V_47 ) ;
if ( V_21 )
break;
}
if ( F_167 ( & V_20 -> V_142 ) ) {
V_20 -> V_282 = V_381 ;
F_182 ( V_20 ) ;
}
return V_21 ;
}
static void F_299 ( struct V_8 * V_20 ,
struct V_202 * V_47 )
{
struct V_42 * V_46 ;
F_21 ( L_10 , V_20 , V_47 ) ;
if ( V_47 -> V_203 == V_20 -> V_372 ) {
F_21 ( L_75 , V_47 -> V_203 ) ;
F_84 ( V_20 , V_317 ) ;
return;
}
V_46 = F_31 ( & V_20 -> V_110 , V_47 -> V_203 ) ;
if ( V_46 == NULL ) {
F_21 ( L_76 ,
V_47 -> V_203 ) ;
return;
}
if ( V_20 -> V_86 != 0 && F_33 ( V_46 ) -> V_47 . V_276 >= V_20 -> V_86 ) {
F_21 ( L_21 , V_20 -> V_86 ) ;
F_84 ( V_20 , V_317 ) ;
return;
}
F_115 ( V_284 , & V_20 -> V_249 ) ;
if ( V_47 -> V_211 ) {
F_210 ( V_20 , V_47 ) ;
F_55 ( V_248 , & V_20 -> V_249 ) ;
F_179 ( V_20 , V_47 ) ;
F_170 ( V_20 ) ;
if ( V_20 -> V_280 == V_417 ) {
F_55 ( V_279 , & V_20 -> V_249 ) ;
V_20 -> V_600 = V_47 -> V_203 ;
}
} else {
F_211 ( V_20 , V_47 ) ;
if ( V_47 -> V_206 ) {
if ( V_20 -> V_600 != V_47 -> V_203 ||
! F_114 ( V_279 ,
& V_20 -> V_249 ) )
F_179 ( V_20 , V_47 ) ;
} else {
F_179 ( V_20 , V_47 ) ;
if ( V_20 -> V_280 == V_417 ) {
F_55 ( V_279 , & V_20 -> V_249 ) ;
V_20 -> V_600 = V_47 -> V_203 ;
}
}
}
}
static void F_300 ( struct V_8 * V_20 ,
struct V_202 * V_47 )
{
struct V_42 * V_46 ;
F_21 ( L_10 , V_20 , V_47 ) ;
if ( V_47 -> V_203 == V_20 -> V_372 ) {
F_21 ( L_75 , V_47 -> V_203 ) ;
F_84 ( V_20 , V_317 ) ;
return;
}
V_46 = F_31 ( & V_20 -> V_110 , V_47 -> V_203 ) ;
if ( V_20 -> V_86 && V_46 &&
F_33 ( V_46 ) -> V_47 . V_276 >= V_20 -> V_86 ) {
F_21 ( L_21 , V_20 -> V_86 ) ;
F_84 ( V_20 , V_317 ) ;
return;
}
F_115 ( V_284 , & V_20 -> V_249 ) ;
F_210 ( V_20 , V_47 ) ;
if ( V_47 -> V_206 ) {
if ( ! F_114 ( V_278 , & V_20 -> V_249 ) )
F_180 ( V_20 , V_47 ) ;
} else {
F_180 ( V_20 , V_47 ) ;
F_170 ( V_20 ) ;
if ( V_20 -> V_280 == V_417 )
F_55 ( V_278 , & V_20 -> V_249 ) ;
}
}
static T_3 F_301 ( struct V_8 * V_20 , T_2 V_48 )
{
F_21 ( L_77 , V_20 , V_48 ) ;
F_21 ( L_78 , V_20 -> V_254 ,
V_20 -> V_277 ) ;
if ( V_20 -> V_282 == V_414 ) {
if ( F_183 ( V_20 , V_48 , V_20 -> V_254 ) >=
V_20 -> V_88 ) {
if ( V_20 -> V_88 <= ( ( V_20 -> V_90 + 1 ) >> 1 ) ) {
F_21 ( L_79 ) ;
return V_601 ;
} else {
F_21 ( L_80 ) ;
return V_602 ;
}
}
if ( V_20 -> V_143 . V_44 == V_48 ) {
F_21 ( L_81 ) ;
return V_603 ;
}
if ( F_31 ( & V_20 -> V_142 , V_48 ) ) {
F_21 ( L_82 ) ;
return V_604 ;
}
if ( F_39 ( & V_20 -> V_143 , V_48 ) ) {
F_21 ( L_83 ) ;
return V_605 ;
}
}
if ( V_20 -> V_277 == V_48 ) {
if ( F_183 ( V_20 , V_48 , V_20 -> V_254 ) >=
V_20 -> V_88 ) {
F_21 ( L_84 ) ;
return V_602 ;
} else {
F_21 ( L_85 ) ;
return V_606 ;
}
}
if ( F_183 ( V_20 , V_48 , V_20 -> V_254 ) <
F_183 ( V_20 , V_20 -> V_277 , V_20 -> V_254 ) ) {
F_21 ( L_86 ) ;
return V_607 ;
}
if ( F_183 ( V_20 , V_48 , V_20 -> V_254 ) >= V_20 -> V_88 ) {
if ( V_20 -> V_88 <= ( ( V_20 -> V_90 + 1 ) >> 1 ) ) {
F_21 ( L_87 ) ;
return V_601 ;
} else {
F_21 ( L_84 ) ;
return V_602 ;
}
} else {
F_21 ( L_88 ) ;
return V_608 ;
}
}
static int F_302 ( struct V_8 * V_20 ,
struct V_202 * V_47 ,
struct V_42 * V_46 , T_3 V_412 )
{
int V_21 = 0 ;
bool V_609 = false ;
F_21 ( L_89 , V_20 , V_47 , V_46 ,
V_412 ) ;
switch ( V_412 ) {
case V_610 :
switch ( F_301 ( V_20 , V_47 -> V_48 ) ) {
case V_606 :
F_210 ( V_20 , V_47 ) ;
if ( F_68 ( V_255 , & V_20 -> V_249 ) ) {
F_21 ( L_90 ,
V_47 -> V_48 ) ;
break;
}
V_20 -> V_277 = F_169 ( V_20 ,
V_47 -> V_48 ) ;
V_20 -> V_256 = V_20 -> V_277 ;
V_609 = true ;
V_21 = F_295 ( V_20 , V_46 , V_47 ) ;
if ( V_21 )
break;
if ( V_47 -> V_206 ) {
if ( ! F_114 ( V_278 ,
& V_20 -> V_249 ) ) {
V_47 -> V_206 = 0 ;
F_180 ( V_20 , V_47 ) ;
F_170 ( V_20 ) ;
}
}
if ( ! F_68 ( V_255 , & V_20 -> V_249 ) )
F_182 ( V_20 ) ;
break;
case V_608 :
F_210 ( V_20 , V_47 ) ;
if ( F_68 ( V_255 , & V_20 -> V_249 ) ) {
F_21 ( L_91 ,
V_47 -> V_48 ) ;
break;
}
F_303 ( & V_20 -> V_142 , V_46 ) ;
V_609 = true ;
F_21 ( L_92 , V_46 ,
F_174 ( & V_20 -> V_142 ) ) ;
F_115 ( V_279 , & V_20 -> V_249 ) ;
F_41 ( & V_20 -> V_143 ) ;
F_201 ( V_20 , V_47 -> V_48 ) ;
V_20 -> V_282 = V_414 ;
break;
case V_607 :
F_210 ( V_20 , V_47 ) ;
break;
case V_601 :
break;
case V_602 :
default:
F_84 ( V_20 , V_317 ) ;
break;
}
break;
case V_611 :
F_210 ( V_20 , V_47 ) ;
if ( V_47 -> V_206 ) {
F_115 ( V_284 , & V_20 -> V_249 ) ;
if ( ! F_114 ( V_278 , & V_20 -> V_249 ) &&
! F_93 ( V_20 ) ) {
V_47 -> V_206 = 0 ;
F_180 ( V_20 , V_47 ) ;
}
F_170 ( V_20 ) ;
} else if ( V_47 -> V_211 ) {
F_292 ( V_20 ) ;
} else {
if ( F_114 ( V_284 ,
& V_20 -> V_249 ) &&
V_20 -> V_378 )
F_25 ( V_20 ) ;
F_170 ( V_20 ) ;
}
break;
case V_612 :
F_55 ( V_284 , & V_20 -> V_249 ) ;
F_210 ( V_20 , V_47 ) ;
if ( V_47 && V_47 -> V_211 ) {
F_55 ( V_248 , & V_20 -> V_249 ) ;
F_117 ( V_20 , 0 ) ;
}
F_30 ( V_20 ) ;
F_41 ( & V_20 -> V_144 ) ;
break;
case V_613 :
F_300 ( V_20 , V_47 ) ;
break;
case V_614 :
F_299 ( V_20 , V_47 ) ;
break;
default:
break;
}
if ( V_46 && ! V_609 ) {
F_21 ( L_93 , V_46 ) ;
F_95 ( V_46 ) ;
}
return V_21 ;
}
static int F_304 ( struct V_8 * V_20 ,
struct V_202 * V_47 ,
struct V_42 * V_46 , T_3 V_412 )
{
int V_21 = 0 ;
T_2 V_48 = V_47 -> V_48 ;
bool V_609 = false ;
F_21 ( L_89 , V_20 , V_47 , V_46 ,
V_412 ) ;
switch ( V_412 ) {
case V_610 :
switch ( F_301 ( V_20 , V_48 ) ) {
case V_606 :
F_210 ( V_20 , V_47 ) ;
F_303 ( & V_20 -> V_142 , V_46 ) ;
V_609 = true ;
F_21 ( L_92 , V_46 ,
F_174 ( & V_20 -> V_142 ) ) ;
V_20 -> V_277 = F_169 ( V_20 , V_48 ) ;
break;
case V_603 :
F_40 ( & V_20 -> V_143 ) ;
F_210 ( V_20 , V_47 ) ;
F_303 ( & V_20 -> V_142 , V_46 ) ;
V_609 = true ;
F_21 ( L_92 , V_46 ,
F_174 ( & V_20 -> V_142 ) ) ;
V_21 = F_298 ( V_20 ) ;
if ( V_21 )
break;
break;
case V_608 :
F_303 ( & V_20 -> V_142 , V_46 ) ;
V_609 = true ;
F_21 ( L_92 , V_46 ,
F_174 ( & V_20 -> V_142 ) ) ;
F_210 ( V_20 , V_47 ) ;
F_201 ( V_20 , V_47 -> V_48 ) ;
break;
case V_605 :
F_303 ( & V_20 -> V_142 , V_46 ) ;
V_609 = true ;
F_21 ( L_92 , V_46 ,
F_174 ( & V_20 -> V_142 ) ) ;
F_210 ( V_20 , V_47 ) ;
F_203 ( V_20 , V_47 -> V_48 ) ;
break;
case V_604 :
F_210 ( V_20 , V_47 ) ;
break;
case V_607 :
break;
case V_601 :
break;
case V_602 :
default:
F_84 ( V_20 , V_317 ) ;
break;
}
break;
case V_611 :
F_210 ( V_20 , V_47 ) ;
if ( V_47 -> V_206 ) {
F_115 ( V_284 , & V_20 -> V_249 ) ;
if ( ! F_114 ( V_278 ,
& V_20 -> V_249 ) ) {
V_47 -> V_206 = 0 ;
F_180 ( V_20 , V_47 ) ;
}
F_170 ( V_20 ) ;
} else if ( V_47 -> V_211 ) {
if ( F_114 ( V_284 ,
& V_20 -> V_249 ) &&
V_20 -> V_378 ) {
F_25 ( V_20 ) ;
}
F_55 ( V_248 , & V_20 -> V_249 ) ;
F_202 ( V_20 ) ;
} else {
if ( F_114 ( V_284 ,
& V_20 -> V_249 ) &&
V_20 -> V_378 )
F_25 ( V_20 ) ;
F_182 ( V_20 ) ;
}
break;
case V_612 :
F_55 ( V_284 , & V_20 -> V_249 ) ;
F_210 ( V_20 , V_47 ) ;
if ( V_47 -> V_211 ) {
F_202 ( V_20 ) ;
} else {
struct V_202 V_615 ;
memset ( & V_615 , 0 , sizeof( V_615 ) ) ;
V_615 . V_210 = 1 ;
V_615 . V_214 = V_250 ;
V_615 . V_203 = V_20 -> V_256 ;
F_113 ( V_20 , & V_615 ) ;
}
break;
case V_613 :
F_300 ( V_20 , V_47 ) ;
break;
case V_614 :
F_299 ( V_20 , V_47 ) ;
break;
}
if ( V_46 && ! V_609 ) {
F_21 ( L_93 , V_46 ) ;
F_95 ( V_46 ) ;
}
return V_21 ;
}
static int F_305 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_282 = V_381 ;
if ( V_20 -> V_198 )
V_20 -> V_10 -> V_156 = V_20 -> V_198 -> V_187 -> V_538 ;
else
V_20 -> V_10 -> V_156 = V_20 -> V_10 -> V_2 -> V_187 -> V_616 ;
return F_296 ( V_20 ) ;
}
static int F_306 ( struct V_8 * V_20 ,
struct V_202 * V_47 ,
struct V_42 * V_46 , T_3 V_412 )
{
int V_21 ;
F_21 ( L_89 , V_20 , V_47 , V_46 ,
V_412 ) ;
if ( ! V_47 -> V_211 )
return - V_500 ;
F_204 ( V_20 , V_47 -> V_203 ) ;
if ( ! F_167 ( & V_20 -> V_110 ) )
V_20 -> V_377 = F_208 ( & V_20 -> V_110 ) ;
else
V_20 -> V_377 = NULL ;
V_20 -> V_372 = V_47 -> V_203 ;
V_20 -> V_378 = 0 ;
V_21 = F_305 ( V_20 ) ;
if ( V_21 )
return V_21 ;
F_55 ( V_248 , & V_20 -> V_249 ) ;
F_292 ( V_20 ) ;
if ( V_412 == V_610 )
return - V_500 ;
return F_302 ( V_20 , V_47 , NULL , V_412 ) ;
}
static int F_307 ( struct V_8 * V_20 ,
struct V_202 * V_47 ,
struct V_42 * V_46 , T_3 V_412 )
{
int V_21 ;
if ( ! V_47 -> V_206 )
return - V_500 ;
F_115 ( V_284 , & V_20 -> V_249 ) ;
V_20 -> V_282 = V_381 ;
F_204 ( V_20 , V_47 -> V_203 ) ;
if ( ! F_167 ( & V_20 -> V_110 ) )
V_20 -> V_377 = F_208 ( & V_20 -> V_110 ) ;
else
V_20 -> V_377 = NULL ;
V_20 -> V_372 = V_47 -> V_203 ;
V_20 -> V_378 = 0 ;
if ( V_20 -> V_198 )
V_20 -> V_10 -> V_156 = V_20 -> V_198 -> V_187 -> V_538 ;
else
V_20 -> V_10 -> V_156 = V_20 -> V_10 -> V_2 -> V_187 -> V_616 ;
V_21 = F_296 ( V_20 ) ;
if ( ! V_21 )
V_21 = F_302 ( V_20 , V_47 , V_46 , V_412 ) ;
return V_21 ;
}
static bool F_308 ( struct V_8 * V_20 , T_2 V_203 )
{
T_2 V_617 ;
V_617 = F_183 ( V_20 , V_20 -> V_372 , V_20 -> V_411 ) ;
return F_183 ( V_20 , V_20 -> V_372 , V_203 ) <= V_617 ;
}
static int F_309 ( struct V_8 * V_20 , struct V_202 * V_47 ,
struct V_42 * V_46 , T_3 V_412 )
{
int V_21 = 0 ;
F_21 ( L_94 , V_20 ,
V_47 , V_46 , V_412 , V_20 -> V_282 ) ;
if ( F_308 ( V_20 , V_47 -> V_203 ) ) {
switch ( V_20 -> V_282 ) {
case V_381 :
V_21 = F_302 ( V_20 , V_47 , V_46 , V_412 ) ;
break;
case V_414 :
V_21 = F_304 ( V_20 , V_47 , V_46 ,
V_412 ) ;
break;
case V_291 :
V_21 = F_306 ( V_20 , V_47 , V_46 , V_412 ) ;
break;
case V_289 :
V_21 = F_307 ( V_20 , V_47 , V_46 , V_412 ) ;
break;
default:
break;
}
} else {
F_21 ( L_95 ,
V_47 -> V_203 , V_20 -> V_372 ,
V_20 -> V_411 ) ;
F_84 ( V_20 , V_317 ) ;
}
return V_21 ;
}
static int F_310 ( struct V_8 * V_20 , struct V_202 * V_47 ,
struct V_42 * V_46 )
{
int V_21 = 0 ;
F_21 ( L_96 , V_20 , V_47 , V_46 ,
V_20 -> V_282 ) ;
if ( F_301 ( V_20 , V_47 -> V_48 ) ==
V_606 ) {
F_210 ( V_20 , V_47 ) ;
F_21 ( L_97 , V_20 -> V_256 ,
F_169 ( V_20 , V_20 -> V_256 ) ) ;
V_20 -> V_256 = F_169 ( V_20 , V_20 -> V_256 ) ;
F_295 ( V_20 , V_46 , V_47 ) ;
} else {
if ( V_20 -> V_101 ) {
F_95 ( V_20 -> V_101 ) ;
V_20 -> V_101 = NULL ;
}
V_20 -> V_102 = NULL ;
V_20 -> V_103 = 0 ;
if ( V_46 ) {
F_21 ( L_93 , V_46 ) ;
F_95 ( V_46 ) ;
}
}
V_20 -> V_254 = V_47 -> V_48 ;
V_20 -> V_277 = F_169 ( V_20 , V_47 -> V_48 ) ;
return V_21 ;
}
static int F_311 ( struct V_8 * V_20 , struct V_42 * V_46 )
{
struct V_202 * V_47 = & F_33 ( V_46 ) -> V_47 ;
T_2 V_185 ;
T_3 V_412 ;
F_98 ( V_20 , V_46 ) ;
V_185 = V_46 -> V_185 ;
if ( F_290 ( V_20 , V_46 ) )
goto V_591;
if ( ! V_47 -> V_210 && V_47 -> V_217 == V_401 )
V_185 -= V_395 ;
if ( V_20 -> V_84 == V_85 )
V_185 -= V_246 ;
if ( V_185 > V_20 -> V_107 ) {
F_84 ( V_20 , V_317 ) ;
goto V_591;
}
if ( ! V_47 -> V_210 ) {
int V_21 ;
F_21 ( L_98 ,
V_47 -> V_217 , V_47 -> V_203 , V_47 -> V_206 ,
V_47 -> V_48 ) ;
if ( V_47 -> V_206 && V_20 -> V_280 != V_417 )
goto V_591;
if ( V_20 -> V_138 != V_145 ) {
V_412 = V_610 ;
V_21 = F_309 ( V_20 , V_47 , V_46 , V_412 ) ;
} else {
V_21 = F_310 ( V_20 , V_47 , V_46 ) ;
}
if ( V_21 )
F_84 ( V_20 , V_317 ) ;
} else {
const T_3 V_618 [ 4 ] = {
V_611 , V_613 ,
V_612 , V_614
} ;
if ( V_20 -> V_138 == V_145 )
goto V_591;
F_21 ( L_99 ,
V_47 -> V_203 , V_47 -> V_206 , V_47 -> V_211 ,
V_47 -> V_214 ) ;
if ( V_185 != 0 ) {
F_282 ( L_100 , V_185 ) ;
F_84 ( V_20 , V_317 ) ;
goto V_591;
}
if ( V_47 -> V_206 && ( V_47 -> V_211 ||
V_20 -> V_280 != V_417 ) )
goto V_591;
V_412 = V_618 [ V_47 -> V_214 ] ;
if ( F_309 ( V_20 , V_47 , V_46 , V_412 ) )
F_84 ( V_20 , V_317 ) ;
}
return 0 ;
V_591:
F_95 ( V_46 ) ;
return 0 ;
}
static void F_312 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct F_285 V_586 ;
T_2 V_619 ;
if ( V_20 -> V_105 >= ( V_106 + 1 ) / 2 )
return;
V_619 = V_106 - V_20 -> V_105 ;
F_21 ( L_101 , V_20 , V_619 ) ;
V_20 -> V_105 += V_619 ;
V_586 . V_11 = F_16 ( V_20 -> V_14 ) ;
V_586 . V_157 = F_16 ( V_619 ) ;
V_20 -> V_16 = F_89 ( V_10 ) ;
F_81 ( V_10 , V_20 -> V_16 , V_590 , sizeof( V_586 ) , & V_586 ) ;
}
static int F_313 ( struct V_8 * V_20 , struct V_42 * V_46 )
{
int V_21 ;
if ( ! V_20 -> V_105 ) {
F_282 ( L_102 ) ;
F_84 ( V_20 , V_317 ) ;
return - V_620 ;
}
if ( V_20 -> V_108 < V_46 -> V_185 ) {
F_282 ( L_103 ) ;
return - V_620 ;
}
V_20 -> V_105 -- ;
F_21 ( L_104 , V_20 -> V_105 + 1 , V_20 -> V_105 ) ;
F_312 ( V_20 ) ;
V_21 = 0 ;
if ( ! V_20 -> V_101 ) {
T_2 V_103 ;
V_103 = F_101 ( V_46 -> V_186 ) ;
F_100 ( V_46 , V_395 ) ;
F_21 ( L_105 ,
V_103 , V_46 -> V_185 , V_20 -> V_108 ) ;
if ( V_103 > V_20 -> V_108 ) {
F_282 ( L_106 ) ;
V_21 = - V_404 ;
goto V_621;
}
if ( V_46 -> V_185 > V_103 ) {
F_282 ( L_107 ) ;
V_21 = - V_26 ;
goto V_621;
}
if ( V_46 -> V_185 == V_103 )
return V_20 -> V_36 -> V_422 ( V_20 , V_46 ) ;
V_20 -> V_101 = V_46 ;
V_20 -> V_103 = V_103 ;
V_20 -> V_102 = V_46 ;
return 0 ;
}
F_21 ( L_108 ,
V_20 -> V_101 -> V_185 , V_46 -> V_185 , V_20 -> V_103 ) ;
if ( V_20 -> V_101 -> V_185 + V_46 -> V_185 > V_20 -> V_103 ) {
F_282 ( L_107 ) ;
V_21 = - V_26 ;
goto V_621;
}
F_293 ( V_20 -> V_101 , V_46 , & V_20 -> V_102 ) ;
V_46 = NULL ;
if ( V_20 -> V_101 -> V_185 == V_20 -> V_103 ) {
V_21 = V_20 -> V_36 -> V_422 ( V_20 , V_20 -> V_101 ) ;
if ( ! V_21 ) {
V_20 -> V_101 = NULL ;
V_20 -> V_102 = NULL ;
V_20 -> V_103 = 0 ;
}
}
V_621:
if ( V_21 ) {
F_95 ( V_46 ) ;
F_95 ( V_20 -> V_101 ) ;
V_20 -> V_101 = NULL ;
V_20 -> V_102 = NULL ;
V_20 -> V_103 = 0 ;
}
return 0 ;
}
static void F_314 ( struct V_9 * V_10 , T_2 V_11 ,
struct V_42 * V_46 )
{
struct V_8 * V_20 ;
V_20 = F_5 ( V_10 , V_11 ) ;
if ( ! V_20 ) {
if ( V_11 == V_313 ) {
V_20 = F_315 ( V_10 , V_46 ) ;
if ( ! V_20 ) {
F_95 ( V_46 ) ;
return;
}
F_7 ( V_20 ) ;
} else {
F_21 ( L_109 , V_11 ) ;
F_95 ( V_46 ) ;
return;
}
}
F_21 ( L_110 , V_20 , V_46 -> V_185 ) ;
if ( V_20 -> V_35 != V_65 )
goto V_591;
switch ( V_20 -> V_138 ) {
case V_140 :
if ( F_313 ( V_20 , V_46 ) < 0 )
goto V_591;
goto V_24;
case V_139 :
if ( V_20 -> V_108 < V_46 -> V_185 ) {
F_282 ( L_111 ) ;
goto V_591;
}
if ( ! V_20 -> V_36 -> V_422 ( V_20 , V_46 ) )
goto V_24;
break;
case V_141 :
case V_145 :
F_311 ( V_20 , V_46 ) ;
goto V_24;
default:
F_21 ( L_112 , V_20 , V_20 -> V_138 ) ;
break;
}
V_591:
F_95 ( V_46 ) ;
V_24:
F_46 ( V_20 ) ;
}
static void F_316 ( struct V_9 * V_10 , T_4 V_17 ,
struct V_42 * V_46 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 ;
if ( V_2 -> type != V_114 )
goto V_622;
V_20 = F_162 ( 0 , V_17 , & V_2 -> V_18 , & V_2 -> V_147 ,
V_114 ) ;
if ( ! V_20 )
goto V_622;
F_21 ( L_110 , V_20 , V_46 -> V_185 ) ;
if ( V_20 -> V_35 != V_623 && V_20 -> V_35 != V_65 )
goto V_591;
if ( V_20 -> V_108 < V_46 -> V_185 )
goto V_591;
F_79 ( & F_33 ( V_46 ) -> V_624 , & V_2 -> V_147 ) ;
F_33 ( V_46 ) -> V_17 = V_17 ;
if ( ! V_20 -> V_36 -> V_422 ( V_20 , V_46 ) ) {
F_47 ( V_20 ) ;
return;
}
V_591:
F_47 ( V_20 ) ;
V_622:
F_95 ( V_46 ) ;
}
static void F_317 ( struct V_9 * V_10 , struct V_42 * V_46 )
{
struct V_243 * V_244 = ( void * ) V_46 -> V_186 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_11 , V_185 ;
T_4 V_17 ;
if ( V_2 -> V_35 != V_65 ) {
F_21 ( L_113 ) ;
F_303 ( & V_10 -> V_358 , V_46 ) ;
return;
}
F_100 ( V_46 , V_240 ) ;
V_11 = F_67 ( V_244 -> V_11 ) ;
V_185 = F_67 ( V_244 -> V_185 ) ;
if ( V_185 != V_46 -> V_185 ) {
F_95 ( V_46 ) ;
return;
}
if ( V_2 -> type == V_3 &&
F_318 ( & V_2 -> V_187 -> V_625 , & V_2 -> V_147 ,
F_1 ( V_2 , V_2 -> V_148 ) ) ) {
F_95 ( V_46 ) ;
return;
}
F_21 ( L_114 , V_185 , V_11 ) ;
switch ( V_11 ) {
case V_117 :
F_289 ( V_10 , V_46 ) ;
break;
case V_116 :
V_17 = F_319 ( ( T_4 * ) V_46 -> V_186 ) ;
F_100 ( V_46 , V_393 ) ;
F_316 ( V_10 , V_17 , V_46 ) ;
break;
case V_427 :
F_288 ( V_10 , V_46 ) ;
break;
default:
F_314 ( V_10 , V_11 , V_46 ) ;
break;
}
}
static void F_320 ( struct V_61 * V_62 )
{
struct V_9 * V_10 = F_44 ( V_62 , struct V_9 ,
V_344 ) ;
struct V_42 * V_46 ;
F_21 ( L_115 ) ;
while ( ( V_46 = F_168 ( & V_10 -> V_358 ) ) )
F_317 ( V_10 , V_46 ) ;
}
static struct V_9 * F_321 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_355 ;
struct V_137 * V_194 ;
if ( V_10 )
return V_10 ;
V_194 = F_322 ( V_2 ) ;
if ( ! V_194 )
return NULL ;
V_10 = F_49 ( sizeof( * V_10 ) , V_55 ) ;
if ( ! V_10 ) {
F_156 ( V_194 ) ;
return NULL ;
}
F_54 ( & V_10 -> V_360 ) ;
V_2 -> V_355 = V_10 ;
V_10 -> V_2 = F_323 ( V_2 ) ;
V_10 -> V_194 = V_194 ;
F_21 ( L_116 , V_2 , V_10 , V_194 ) ;
switch ( V_2 -> type ) {
case V_3 :
if ( V_2 -> V_187 -> V_626 ) {
V_10 -> V_156 = V_2 -> V_187 -> V_626 ;
break;
}
default:
V_10 -> V_156 = V_2 -> V_187 -> V_616 ;
break;
}
V_10 -> V_306 = 0 ;
V_10 -> V_260 = V_627 | V_628 ;
if ( V_2 -> type == V_114 &&
F_68 ( V_629 , & V_2 -> V_187 -> V_511 ) )
V_10 -> V_260 |= V_261 ;
if ( F_68 ( V_630 , & V_2 -> V_187 -> V_511 ) &&
( F_324 ( V_2 -> V_187 ) ||
F_68 ( V_631 , & V_2 -> V_187 -> V_632 ) ) )
V_10 -> V_260 |= V_633 ;
F_50 ( & V_10 -> V_182 ) ;
F_50 ( & V_10 -> V_15 ) ;
F_325 ( & V_10 -> V_131 ) ;
F_325 ( & V_10 -> V_354 ) ;
F_53 ( & V_10 -> V_302 , F_145 ) ;
F_65 ( & V_10 -> V_358 ) ;
F_326 ( & V_10 -> V_344 , F_320 ) ;
F_326 ( & V_10 -> V_146 , F_78 ) ;
V_10 -> V_111 = V_112 ;
return V_10 ;
}
static bool F_327 ( T_2 V_17 , T_3 V_148 ) {
if ( ! V_17 )
return false ;
if ( F_328 ( V_148 ) )
return ( V_17 <= 0x00ff ) ;
return ( ( V_17 & 0x0101 ) == 0x0001 ) ;
}
int F_329 ( struct V_8 * V_20 , T_4 V_17 , T_2 V_11 ,
T_5 * V_147 , T_3 V_148 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_258 * V_187 ;
int V_21 ;
F_21 ( L_117 , & V_20 -> V_18 , V_147 ,
V_148 , F_67 ( V_17 ) ) ;
V_187 = F_330 ( V_147 , & V_20 -> V_18 ) ;
if ( ! V_187 )
return - V_634 ;
F_147 ( V_187 ) ;
if ( ! F_327 ( F_67 ( V_17 ) , V_148 ) && ! V_11 &&
V_20 -> V_29 != V_167 ) {
V_21 = - V_26 ;
goto V_24;
}
if ( V_20 -> V_29 == V_113 && ! V_17 ) {
V_21 = - V_26 ;
goto V_24;
}
if ( V_20 -> V_29 == V_30 && ! V_11 ) {
V_21 = - V_26 ;
goto V_24;
}
switch ( V_20 -> V_138 ) {
case V_139 :
break;
case V_140 :
F_63 ( V_20 ) ;
break;
case V_141 :
case V_145 :
if ( ! V_309 )
break;
default:
V_21 = - V_635 ;
goto V_24;
}
switch ( V_20 -> V_35 ) {
case V_68 :
case V_166 :
case V_66 :
V_21 = 0 ;
goto V_24;
case V_65 :
V_21 = - V_636 ;
goto V_24;
case V_79 :
case V_623 :
break;
default:
V_21 = - V_407 ;
goto V_24;
}
F_79 ( & V_20 -> V_147 , V_147 ) ;
V_20 -> V_148 = V_148 ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_11 ;
if ( F_328 ( V_148 ) ) {
T_3 V_330 ;
if ( V_148 == V_5 )
V_148 = V_4 ;
else
V_148 = V_637 ;
if ( F_68 ( V_638 , & V_187 -> V_511 ) )
V_330 = V_331 ;
else
V_330 = V_575 ;
V_2 = F_331 ( V_187 , V_147 , V_148 , V_20 -> V_69 ,
V_639 , V_330 ) ;
} else {
T_3 V_180 = F_85 ( V_20 ) ;
V_2 = F_332 ( V_187 , V_147 , V_20 -> V_69 , V_180 ) ;
}
if ( F_116 ( V_2 ) ) {
V_21 = F_188 ( V_2 ) ;
goto V_24;
}
V_10 = F_321 ( V_2 ) ;
if ( ! V_10 ) {
F_73 ( V_2 ) ;
V_21 = - V_56 ;
goto V_24;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_20 ) ;
if ( V_11 && F_2 ( V_10 , V_11 ) ) {
F_73 ( V_2 ) ;
V_21 = - V_640 ;
goto V_641;
}
F_79 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
V_20 -> V_363 = F_1 ( V_2 , V_2 -> V_363 ) ;
F_66 ( V_10 , V_20 ) ;
F_73 ( V_2 ) ;
F_20 ( V_20 , V_68 ) ;
F_83 ( V_20 , V_20 -> V_36 -> V_165 ( V_20 ) ) ;
F_15 ( & V_22 ) ;
V_20 -> V_19 = 0 ;
F_17 ( & V_22 ) ;
if ( V_2 -> V_35 == V_65 ) {
if ( V_20 -> V_29 != V_113 ) {
F_72 ( V_20 ) ;
if ( F_86 ( V_20 , true ) )
F_20 ( V_20 , V_65 ) ;
} else
F_136 ( V_20 ) ;
}
V_21 = 0 ;
V_641:
F_46 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
V_24:
F_148 ( V_187 ) ;
F_253 ( V_187 ) ;
return V_21 ;
}
int F_333 ( struct V_258 * V_187 , T_5 * V_624 )
{
int V_642 = 0 , V_643 = 0 , V_644 = 0 ;
struct V_8 * V_12 ;
F_21 ( L_118 , V_187 -> V_327 , V_624 ) ;
F_120 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_12 -> V_35 != V_164 )
continue;
if ( ! F_13 ( & V_12 -> V_18 , & V_187 -> V_624 ) ) {
V_643 |= V_645 ;
if ( F_68 ( V_646 , & V_12 -> V_100 ) )
V_643 |= V_647 ;
V_642 ++ ;
} else if ( ! F_13 ( & V_12 -> V_18 , V_368 ) ) {
V_644 |= V_645 ;
if ( F_68 ( V_646 , & V_12 -> V_100 ) )
V_644 |= V_647 ;
}
}
F_121 ( & V_22 ) ;
return V_642 ? V_643 : V_644 ;
}
static struct V_8 * F_334 ( struct V_8 * V_12 ,
T_5 * V_18 , T_3 V_361 )
{
F_120 ( & V_22 ) ;
if ( V_12 )
V_12 = F_335 ( V_12 , V_77 ) ;
else
V_12 = F_336 ( V_78 . V_349 , F_337 ( * V_12 ) , V_77 ) ;
F_338 (c, &chan_list, global_l) {
if ( V_12 -> V_29 != V_30 )
continue;
if ( V_12 -> V_35 != V_164 )
continue;
if ( F_13 ( & V_12 -> V_18 , V_18 ) && F_13 ( & V_12 -> V_18 , V_368 ) )
continue;
if ( V_361 == V_114 && V_12 -> V_363 != V_7 )
continue;
if ( V_361 == V_3 && V_12 -> V_363 == V_7 )
continue;
F_58 ( V_12 ) ;
F_121 ( & V_22 ) ;
return V_12 ;
}
F_121 ( & V_22 ) ;
return NULL ;
}
void F_339 ( struct V_1 * V_2 , T_3 V_161 )
{
struct V_258 * V_187 = V_2 -> V_187 ;
struct V_9 * V_10 ;
struct V_8 * V_502 ;
T_3 V_148 ;
F_21 ( L_119 , V_2 , & V_2 -> V_147 , V_161 ) ;
if ( V_161 ) {
F_153 ( V_2 , F_340 ( V_161 ) ) ;
return;
}
V_10 = F_321 ( V_2 ) ;
if ( ! V_10 )
return;
V_148 = F_1 ( V_2 , V_2 -> V_148 ) ;
if ( F_318 ( & V_187 -> V_625 , & V_2 -> V_147 , V_148 ) )
return;
V_502 = F_334 ( NULL , & V_187 -> V_624 , V_2 -> type ) ;
while ( V_502 ) {
struct V_8 * V_20 , * V_349 ;
if ( F_2 ( V_10 , V_502 -> V_14 ) )
goto V_349;
F_7 ( V_502 ) ;
V_20 = V_502 -> V_36 -> V_507 ( V_502 ) ;
if ( V_20 ) {
F_79 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
F_79 ( & V_20 -> V_147 , & V_2 -> V_147 ) ;
V_20 -> V_363 = F_1 ( V_2 , V_2 -> V_363 ) ;
V_20 -> V_148 = V_148 ;
F_66 ( V_10 , V_20 ) ;
}
F_46 ( V_502 ) ;
V_349:
V_349 = F_334 ( V_502 , & V_187 -> V_624 ,
V_2 -> type ) ;
F_47 ( V_502 ) ;
V_502 = V_349 ;
}
F_142 ( V_10 ) ;
}
int F_341 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_355 ;
F_21 ( L_120 , V_2 ) ;
if ( ! V_10 )
return V_112 ;
return V_10 -> V_111 ;
}
void F_342 ( struct V_1 * V_2 , T_3 V_64 )
{
F_21 ( L_121 , V_2 , V_64 ) ;
F_153 ( V_2 , F_340 ( V_64 ) ) ;
}
static inline void F_343 ( struct V_8 * V_20 , T_3 V_648 )
{
if ( V_20 -> V_29 != V_113 )
return;
if ( V_648 == 0x00 ) {
if ( V_20 -> V_69 == V_171 ) {
F_83 ( V_20 , V_649 ) ;
} else if ( V_20 -> V_69 == V_168 ||
V_20 -> V_69 == V_169 )
F_45 ( V_20 , V_67 ) ;
} else {
if ( V_20 -> V_69 == V_171 )
F_72 ( V_20 ) ;
}
}
int F_344 ( struct V_1 * V_2 , T_3 V_161 , T_3 V_648 )
{
struct V_9 * V_10 = V_2 -> V_355 ;
struct V_8 * V_20 ;
if ( ! V_10 )
return 0 ;
F_21 ( L_122 , V_10 , V_161 , V_648 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
F_21 ( L_123 , V_20 , V_20 -> V_14 ,
F_22 ( V_20 -> V_35 ) ) ;
if ( V_20 -> V_14 == V_313 ) {
F_46 ( V_20 ) ;
continue;
}
if ( ! V_161 && V_648 )
V_20 -> V_69 = V_2 -> V_69 ;
if ( ! F_118 ( V_20 ) ) {
F_46 ( V_20 ) ;
continue;
}
if ( ! V_161 && ( V_20 -> V_35 == V_65 ||
V_20 -> V_35 == V_66 ) ) {
V_20 -> V_36 -> V_589 ( V_20 ) ;
F_343 ( V_20 , V_648 ) ;
F_46 ( V_20 ) ;
continue;
}
if ( V_20 -> V_35 == V_68 ) {
if ( ! V_161 )
F_132 ( V_20 ) ;
else
F_83 ( V_20 , V_650 ) ;
} else if ( V_20 -> V_35 == V_166 &&
V_20 -> V_138 != V_140 ) {
struct V_159 V_150 ;
T_6 V_651 , V_652 ;
if ( ! V_161 ) {
if ( F_68 ( V_152 , & V_20 -> V_100 ) ) {
V_651 = V_319 ;
V_652 = V_320 ;
V_20 -> V_36 -> V_321 ( V_20 ) ;
} else {
F_20 ( V_20 , V_66 ) ;
V_651 = V_322 ;
V_652 = V_162 ;
}
} else {
F_20 ( V_20 , V_155 ) ;
F_83 ( V_20 , V_650 ) ;
V_651 = V_160 ;
V_652 = V_162 ;
}
V_150 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_150 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_150 . V_151 = F_16 ( V_651 ) ;
V_150 . V_161 = F_16 ( V_652 ) ;
F_81 ( V_10 , V_20 -> V_16 , V_163 ,
sizeof( V_150 ) , & V_150 ) ;
if ( ! F_68 ( V_324 , & V_20 -> V_82 ) &&
V_651 == V_322 ) {
char V_318 [ 128 ] ;
F_55 ( V_324 , & V_20 -> V_82 ) ;
F_81 ( V_10 , F_89 ( V_10 ) ,
V_325 ,
F_140 ( V_20 , V_318 ) ,
V_318 ) ;
V_20 -> V_326 ++ ;
}
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
int F_345 ( struct V_1 * V_2 , struct V_42 * V_46 , T_2 V_100 )
{
struct V_9 * V_10 = V_2 -> V_355 ;
struct V_243 * V_653 ;
int V_185 ;
if ( ! V_10 && V_2 -> V_187 -> V_535 != V_654 )
goto V_591;
if ( ! V_10 )
V_10 = F_321 ( V_2 ) ;
if ( ! V_10 )
goto V_591;
F_21 ( L_124 , V_10 , V_46 -> V_185 , V_100 ) ;
switch ( V_100 ) {
case V_189 :
case V_188 :
case V_199 :
if ( V_10 -> V_655 ) {
F_282 ( L_125 , V_46 -> V_185 ) ;
F_95 ( V_10 -> V_357 ) ;
V_10 -> V_357 = NULL ;
V_10 -> V_655 = 0 ;
F_144 ( V_10 , V_656 ) ;
}
if ( V_46 -> V_185 < V_240 ) {
F_282 ( L_126 , V_46 -> V_185 ) ;
F_144 ( V_10 , V_656 ) ;
goto V_591;
}
V_653 = (struct V_243 * ) V_46 -> V_186 ;
V_185 = F_67 ( V_653 -> V_185 ) + V_240 ;
if ( V_185 == V_46 -> V_185 ) {
F_317 ( V_10 , V_46 ) ;
return 0 ;
}
F_21 ( L_127 , V_185 , V_46 -> V_185 ) ;
if ( V_46 -> V_185 > V_185 ) {
F_282 ( L_128 ,
V_46 -> V_185 , V_185 ) ;
F_144 ( V_10 , V_656 ) ;
goto V_591;
}
V_10 -> V_357 = F_109 ( V_185 , V_55 ) ;
if ( ! V_10 -> V_357 )
goto V_591;
F_346 ( V_46 , F_111 ( V_10 -> V_357 , V_46 -> V_185 ) ,
V_46 -> V_185 ) ;
V_10 -> V_655 = V_185 - V_46 -> V_185 ;
break;
case V_657 :
F_21 ( L_129 , V_46 -> V_185 , V_10 -> V_655 ) ;
if ( ! V_10 -> V_655 ) {
F_282 ( L_130 , V_46 -> V_185 ) ;
F_144 ( V_10 , V_656 ) ;
goto V_591;
}
if ( V_46 -> V_185 > V_10 -> V_655 ) {
F_282 ( L_131 ,
V_46 -> V_185 , V_10 -> V_655 ) ;
F_95 ( V_10 -> V_357 ) ;
V_10 -> V_357 = NULL ;
V_10 -> V_655 = 0 ;
F_144 ( V_10 , V_656 ) ;
goto V_591;
}
F_346 ( V_46 , F_111 ( V_10 -> V_357 , V_46 -> V_185 ) ,
V_46 -> V_185 ) ;
V_10 -> V_655 -= V_46 -> V_185 ;
if ( ! V_10 -> V_655 ) {
struct V_42 * V_357 = V_10 -> V_357 ;
V_10 -> V_357 = NULL ;
F_317 ( V_10 , V_357 ) ;
}
break;
}
V_591:
F_95 ( V_46 ) ;
return 0 ;
}
static int F_347 ( struct V_658 * V_659 , void * V_25 )
{
struct V_8 * V_12 ;
F_120 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
F_348 ( V_659 , L_132 ,
& V_12 -> V_18 , & V_12 -> V_147 ,
V_12 -> V_35 , F_67 ( V_12 -> V_17 ) ,
V_12 -> V_14 , V_12 -> V_13 , V_12 -> V_108 , V_12 -> V_27 ,
V_12 -> V_69 , V_12 -> V_138 ) ;
}
F_121 ( & V_22 ) ;
return 0 ;
}
static int F_349 ( struct V_660 * V_660 , struct V_661 * V_661 )
{
return F_350 ( V_661 , F_347 , V_660 -> V_662 ) ;
}
int T_11 F_351 ( void )
{
int V_21 ;
V_21 = F_352 () ;
if ( V_21 < 0 )
return V_21 ;
if ( F_353 ( V_663 ) )
return 0 ;
V_664 = F_354 ( L_133 , 0444 , V_663 ,
NULL , & V_665 ) ;
F_355 ( L_134 , 0644 , V_663 ,
& V_106 ) ;
F_355 ( L_135 , 0644 , V_663 ,
& V_109 ) ;
return 0 ;
}
void F_356 ( void )
{
F_357 ( V_664 ) ;
F_358 () ;
}
