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
F_15 ( & V_22 ) ;
F_51 ( & V_20 -> V_75 , & V_76 ) ;
F_17 ( & V_22 ) ;
F_52 ( & V_20 -> V_63 , F_43 ) ;
V_20 -> V_35 = V_77 ;
F_53 ( & V_20 -> V_78 ) ;
F_54 ( V_79 , & V_20 -> V_80 ) ;
F_21 ( L_3 , V_20 ) ;
return V_20 ;
}
static void F_55 ( struct V_78 * V_78 )
{
struct V_8 * V_20 = F_44 ( V_78 , struct V_8 , V_78 ) ;
F_21 ( L_3 , V_20 ) ;
F_15 ( & V_22 ) ;
F_56 ( & V_20 -> V_75 ) ;
F_17 ( & V_22 ) ;
F_38 ( V_20 ) ;
}
void F_57 ( struct V_8 * V_12 )
{
F_21 ( L_4 , V_12 , F_58 ( & V_12 -> V_78 . V_81 ) ) ;
F_59 ( & V_12 -> V_78 ) ;
}
void F_47 ( struct V_8 * V_12 )
{
F_21 ( L_4 , V_12 , F_58 ( & V_12 -> V_78 . V_81 ) ) ;
F_60 ( & V_12 -> V_78 , F_55 ) ;
}
void F_61 ( struct V_8 * V_20 )
{
V_20 -> V_82 = V_83 ;
V_20 -> V_84 = V_85 ;
V_20 -> V_86 = V_87 ;
V_20 -> V_88 = V_87 ;
V_20 -> V_89 = V_20 -> V_84 ;
V_20 -> V_90 = V_20 -> V_86 ;
V_20 -> V_91 = V_87 ;
V_20 -> V_69 = V_92 ;
V_20 -> V_93 = V_94 ;
V_20 -> V_39 = V_95 ;
V_20 -> V_41 = V_96 ;
V_20 -> V_80 = 0 ;
F_54 ( V_97 , & V_20 -> V_98 ) ;
}
static void F_62 ( struct V_8 * V_20 )
{
V_20 -> V_99 = NULL ;
V_20 -> V_100 = NULL ;
V_20 -> V_101 = 0 ;
V_20 -> V_102 = 0 ;
V_20 -> V_103 = V_104 ;
V_20 -> V_105 = F_63 ( T_2 , V_20 -> V_106 , V_107 ) ;
F_64 ( & V_20 -> V_108 ) ;
}
void F_65 ( struct V_9 * V_10 , struct V_8 * V_20 )
{
F_21 ( L_5 , V_10 ,
F_66 ( V_20 -> V_17 ) , V_20 -> V_13 ) ;
V_10 -> V_109 = V_110 ;
V_20 -> V_10 = V_10 ;
switch ( V_20 -> V_29 ) {
case V_111 :
V_20 -> V_14 = F_19 ( V_10 ) ;
if ( V_10 -> V_2 -> type == V_112 )
V_20 -> V_27 = V_28 ;
break;
case V_113 :
V_20 -> V_14 = V_114 ;
V_20 -> V_13 = V_114 ;
V_20 -> V_27 = V_28 ;
break;
case V_30 :
break;
default:
V_20 -> V_14 = V_115 ;
V_20 -> V_13 = V_115 ;
V_20 -> V_27 = V_28 ;
}
V_20 -> V_116 = V_117 ;
V_20 -> V_118 = V_119 ;
V_20 -> V_120 = V_121 ;
V_20 -> V_122 = V_123 ;
V_20 -> V_124 = V_125 ;
V_20 -> V_126 = V_127 ;
F_57 ( V_20 ) ;
if ( V_20 -> V_29 != V_30 ||
F_67 ( V_128 , & V_20 -> V_98 ) )
F_68 ( V_10 -> V_2 ) ;
F_51 ( & V_20 -> V_54 , & V_10 -> V_129 ) ;
}
void F_69 ( struct V_9 * V_10 , struct V_8 * V_20 )
{
F_6 ( & V_10 -> V_15 ) ;
F_65 ( V_10 , V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
}
void F_70 ( struct V_8 * V_20 , int V_21 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_71 ( V_20 ) ;
F_21 ( L_6 , V_20 , V_10 , V_21 ) ;
V_20 -> V_36 -> V_130 ( V_20 , V_21 ) ;
if ( V_10 ) {
struct V_131 * V_132 = V_10 -> V_2 -> V_131 ;
F_56 ( & V_20 -> V_54 ) ;
F_47 ( V_20 ) ;
V_20 -> V_10 = NULL ;
if ( V_20 -> V_29 != V_30 ||
F_67 ( V_128 , & V_20 -> V_98 ) )
F_72 ( V_10 -> V_2 ) ;
if ( V_132 && V_132 -> V_133 == V_20 )
V_132 -> V_133 = NULL ;
}
if ( V_20 -> V_134 ) {
struct V_135 * V_134 = V_20 -> V_134 ;
F_21 ( L_7 , V_20 , V_134 ) ;
F_73 ( V_134 ) ;
}
if ( F_67 ( V_79 , & V_20 -> V_80 ) )
return;
switch( V_20 -> V_136 ) {
case V_137 :
break;
case V_138 :
F_74 ( & V_20 -> V_108 ) ;
break;
case V_139 :
F_30 ( V_20 ) ;
F_75 ( V_20 ) ;
F_76 ( V_20 ) ;
F_74 ( & V_20 -> V_140 ) ;
F_37 ( & V_20 -> V_141 ) ;
F_37 ( & V_20 -> V_142 ) ;
case V_143 :
F_74 ( & V_20 -> V_108 ) ;
break;
}
return;
}
static void F_77 ( struct V_61 * V_62 )
{
struct V_9 * V_10 = F_44 ( V_62 , struct V_9 ,
V_144 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
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
if ( F_67 ( V_150 , & V_20 -> V_98 ) )
V_149 = V_151 ;
else
V_149 = V_152 ;
F_20 ( V_20 , V_153 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_154 = F_16 ( V_20 -> V_106 ) ;
V_148 . V_105 = F_16 ( V_20 -> V_105 ) ;
V_148 . V_155 = F_16 ( V_20 -> V_103 ) ;
V_148 . V_149 = F_16 ( V_149 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_156 , sizeof( V_148 ) ,
& V_148 ) ;
}
static void F_81 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_157 V_148 ;
T_2 V_149 ;
if ( F_67 ( V_150 , & V_20 -> V_98 ) )
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
void F_45 ( struct V_8 * V_20 , int V_64 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_2 , V_20 , F_22 ( V_20 -> V_35 ) ) ;
switch ( V_20 -> V_35 ) {
case V_162 :
V_20 -> V_36 -> V_130 ( V_20 , 0 ) ;
break;
case V_65 :
case V_66 :
if ( V_20 -> V_29 == V_111 ) {
F_82 ( V_20 , V_20 -> V_36 -> V_163 ( V_20 ) ) ;
F_83 ( V_20 , V_64 ) ;
} else
F_70 ( V_20 , V_64 ) ;
break;
case V_164 :
if ( V_20 -> V_29 == V_111 ) {
if ( V_10 -> V_2 -> type == V_112 )
F_81 ( V_20 ) ;
else if ( V_10 -> V_2 -> type == V_3 )
F_79 ( V_20 ) ;
}
F_70 ( V_20 , V_64 ) ;
break;
case V_68 :
case V_153 :
F_70 ( V_20 , V_64 ) ;
break;
default:
V_20 -> V_36 -> V_130 ( V_20 , 0 ) ;
break;
}
}
static inline T_3 F_84 ( struct V_8 * V_20 )
{
switch ( V_20 -> V_29 ) {
case V_165 :
switch ( V_20 -> V_69 ) {
case V_166 :
case V_167 :
return V_168 ;
case V_169 :
return V_170 ;
default:
return V_171 ;
}
break;
case V_113 :
if ( V_20 -> V_17 == F_16 ( V_172 ) ) {
if ( V_20 -> V_69 == V_92 )
V_20 -> V_69 = V_70 ;
}
if ( V_20 -> V_69 == V_166 ||
V_20 -> V_69 == V_167 )
return V_173 ;
else
return V_171 ;
break;
case V_111 :
if ( V_20 -> V_17 == F_16 ( V_174 ) ) {
if ( V_20 -> V_69 == V_92 )
V_20 -> V_69 = V_70 ;
if ( V_20 -> V_69 == V_166 ||
V_20 -> V_69 == V_167 )
return V_173 ;
else
return V_171 ;
}
default:
switch ( V_20 -> V_69 ) {
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
return F_86 ( V_10 -> V_2 , V_20 -> V_69 ) ;
V_178 = F_84 ( V_20 ) ;
return F_87 ( V_10 -> V_2 , V_20 -> V_69 , V_178 ,
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
struct V_42 * V_46 = F_89 ( V_10 , V_182 , V_16 , V_183 , V_184 ) ;
T_3 V_98 ;
F_21 ( L_8 , V_182 ) ;
if ( ! V_46 )
return;
if ( F_90 ( V_10 -> V_2 -> V_185 ) )
V_98 = V_186 ;
else
V_98 = V_187 ;
F_33 ( V_46 ) -> V_188 = V_189 ;
V_46 -> V_190 = V_191 ;
F_91 ( V_10 -> V_192 , V_46 , V_98 ) ;
}
static bool F_92 ( struct V_8 * V_20 )
{
return V_20 -> V_193 != V_194 &&
V_20 -> V_193 != V_195 ;
}
static void F_93 ( struct V_8 * V_20 , struct V_42 * V_46 )
{
struct V_1 * V_2 = V_20 -> V_10 -> V_2 ;
T_2 V_98 ;
F_21 ( L_9 , V_20 , V_46 , V_46 -> V_183 ,
V_46 -> V_190 ) ;
if ( V_20 -> V_196 && ! F_92 ( V_20 ) ) {
if ( V_20 -> V_134 )
F_91 ( V_20 -> V_134 , V_46 , V_197 ) ;
else
F_94 ( V_46 ) ;
return;
}
if ( ! F_67 ( V_198 , & V_20 -> V_98 ) &&
F_90 ( V_2 -> V_185 ) )
V_98 = V_186 ;
else
V_98 = V_187 ;
F_33 ( V_46 ) -> V_188 = F_67 ( V_97 , & V_20 -> V_98 ) ;
F_91 ( V_20 -> V_10 -> V_192 , V_46 , V_98 ) ;
}
static void F_95 ( T_2 V_199 , struct V_200 * V_47 )
{
V_47 -> V_201 = ( V_199 & V_202 ) >> V_203 ;
V_47 -> V_204 = ( V_199 & V_205 ) >> V_206 ;
if ( V_199 & V_207 ) {
V_47 -> V_208 = 1 ;
V_47 -> V_209 = ( V_199 & V_210 ) >> V_211 ;
V_47 -> V_212 = ( V_199 & V_213 ) >> V_214 ;
V_47 -> V_215 = 0 ;
V_47 -> V_48 = 0 ;
} else {
V_47 -> V_208 = 0 ;
V_47 -> V_215 = ( V_199 & V_216 ) >> V_217 ;
V_47 -> V_48 = ( V_199 & V_218 ) >> V_219 ;
V_47 -> V_209 = 0 ;
V_47 -> V_212 = 0 ;
}
}
static void F_96 ( T_8 V_220 , struct V_200 * V_47 )
{
V_47 -> V_201 = ( V_220 & V_221 ) >> V_222 ;
V_47 -> V_204 = ( V_220 & V_223 ) >> V_224 ;
if ( V_220 & V_225 ) {
V_47 -> V_208 = 1 ;
V_47 -> V_209 = ( V_220 & V_226 ) >> V_227 ;
V_47 -> V_212 = ( V_220 & V_228 ) >> V_229 ;
V_47 -> V_215 = 0 ;
V_47 -> V_48 = 0 ;
} else {
V_47 -> V_208 = 0 ;
V_47 -> V_215 = ( V_220 & V_230 ) >> V_231 ;
V_47 -> V_48 = ( V_220 & V_232 ) >> V_233 ;
V_47 -> V_209 = 0 ;
V_47 -> V_212 = 0 ;
}
}
static inline void F_97 ( struct V_8 * V_20 ,
struct V_42 * V_46 )
{
if ( F_67 ( V_234 , & V_20 -> V_98 ) ) {
F_96 ( F_98 ( V_46 -> V_184 ) ,
& F_33 ( V_46 ) -> V_47 ) ;
F_99 ( V_46 , V_235 ) ;
} else {
F_95 ( F_100 ( V_46 -> V_184 ) ,
& F_33 ( V_46 ) -> V_47 ) ;
F_99 ( V_46 , V_236 ) ;
}
}
static T_8 F_101 ( struct V_200 * V_47 )
{
T_8 V_237 ;
V_237 = V_47 -> V_201 << V_222 ;
V_237 |= V_47 -> V_204 << V_224 ;
if ( V_47 -> V_208 ) {
V_237 |= V_47 -> V_209 << V_227 ;
V_237 |= V_47 -> V_212 << V_229 ;
V_237 |= V_225 ;
} else {
V_237 |= V_47 -> V_215 << V_231 ;
V_237 |= V_47 -> V_48 << V_233 ;
}
return V_237 ;
}
static T_2 F_102 ( struct V_200 * V_47 )
{
T_2 V_237 ;
V_237 = V_47 -> V_201 << V_203 ;
V_237 |= V_47 -> V_204 << V_206 ;
if ( V_47 -> V_208 ) {
V_237 |= V_47 -> V_209 << V_211 ;
V_237 |= V_47 -> V_212 << V_214 ;
V_237 |= V_207 ;
} else {
V_237 |= V_47 -> V_215 << V_217 ;
V_237 |= V_47 -> V_48 << V_219 ;
}
return V_237 ;
}
static inline void F_103 ( struct V_8 * V_20 ,
struct V_200 * V_47 ,
struct V_42 * V_46 )
{
if ( F_67 ( V_234 , & V_20 -> V_98 ) ) {
F_104 ( F_101 ( V_47 ) ,
V_46 -> V_184 + V_238 ) ;
} else {
F_105 ( F_102 ( V_47 ) ,
V_46 -> V_184 + V_238 ) ;
}
}
static inline unsigned int F_106 ( struct V_8 * V_20 )
{
if ( F_67 ( V_234 , & V_20 -> V_98 ) )
return V_239 ;
else
return V_240 ;
}
static struct V_42 * F_107 ( struct V_8 * V_20 ,
T_8 V_47 )
{
struct V_42 * V_46 ;
struct V_241 * V_242 ;
int V_243 = F_106 ( V_20 ) ;
if ( V_20 -> V_82 == V_83 )
V_243 += V_244 ;
V_46 = F_108 ( V_243 , V_55 ) ;
if ( ! V_46 )
return F_109 ( - V_56 ) ;
V_242 = (struct V_241 * ) F_110 ( V_46 , V_238 ) ;
V_242 -> V_183 = F_16 ( V_243 - V_238 ) ;
V_242 -> V_11 = F_16 ( V_20 -> V_13 ) ;
if ( F_67 ( V_234 , & V_20 -> V_98 ) )
F_104 ( V_47 , F_110 ( V_46 , V_235 ) ) ;
else
F_105 ( V_47 , F_110 ( V_46 , V_236 ) ) ;
if ( V_20 -> V_82 == V_83 ) {
T_2 V_82 = F_111 ( 0 , ( T_3 * ) V_46 -> V_184 , V_46 -> V_183 ) ;
F_105 ( V_82 , F_110 ( V_46 , V_244 ) ) ;
}
V_46 -> V_190 = V_191 ;
return V_46 ;
}
static void F_112 ( struct V_8 * V_20 ,
struct V_200 * V_47 )
{
struct V_42 * V_46 ;
T_8 V_245 ;
F_21 ( L_10 , V_20 , V_47 ) ;
if ( ! V_47 -> V_208 )
return;
if ( F_92 ( V_20 ) )
return;
if ( F_113 ( V_246 , & V_20 -> V_247 ) &&
! V_47 -> V_209 )
V_47 -> V_204 = 1 ;
if ( V_47 -> V_212 == V_248 )
F_114 ( V_249 , & V_20 -> V_247 ) ;
else if ( V_47 -> V_212 == V_250 )
F_54 ( V_249 , & V_20 -> V_247 ) ;
if ( V_47 -> V_212 != V_251 ) {
V_20 -> V_252 = V_47 -> V_201 ;
F_76 ( V_20 ) ;
}
F_21 ( L_11 , V_47 -> V_201 ,
V_47 -> V_204 , V_47 -> V_209 , V_47 -> V_212 ) ;
if ( F_67 ( V_234 , & V_20 -> V_98 ) )
V_245 = F_101 ( V_47 ) ;
else
V_245 = F_102 ( V_47 ) ;
V_46 = F_107 ( V_20 , V_245 ) ;
if ( ! F_115 ( V_46 ) )
F_93 ( V_20 , V_46 ) ;
}
static void F_116 ( struct V_8 * V_20 , bool V_209 )
{
struct V_200 V_47 ;
F_21 ( L_12 , V_20 , V_209 ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_208 = 1 ;
V_47 . V_209 = V_209 ;
if ( F_67 ( V_253 , & V_20 -> V_247 ) )
V_47 . V_212 = V_250 ;
else
V_47 . V_212 = V_248 ;
V_47 . V_201 = V_20 -> V_254 ;
F_112 ( V_20 , & V_47 ) ;
}
static inline int F_117 ( struct V_8 * V_20 )
{
if ( V_20 -> V_29 != V_111 )
return true ;
return ! F_67 ( V_255 , & V_20 -> V_80 ) ;
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
F_67 ( V_264 , & V_185 -> V_98 ) ) {
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
F_54 ( V_255 , & V_20 -> V_80 ) ;
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
struct V_42 * V_46 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_136 != V_139 )
return;
F_30 ( V_20 ) ;
F_75 ( V_20 ) ;
F_76 ( V_20 ) ;
V_20 -> V_273 = 0 ;
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_46 ) -> V_47 . V_274 )
F_33 ( V_46 ) -> V_47 . V_274 = 1 ;
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
V_20 -> V_80 = 0 ;
F_71 ( V_20 ) ;
if ( V_20 -> V_136 == V_138 && ! V_20 -> V_102 )
V_20 -> V_36 -> V_290 ( V_20 ) ;
V_20 -> V_35 = V_65 ;
V_20 -> V_36 -> V_291 ( V_20 ) ;
}
static void F_128 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_292 V_268 ;
if ( F_129 ( V_293 , & V_20 -> V_98 ) )
return;
V_268 . V_17 = V_20 -> V_17 ;
V_268 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_268 . V_154 = F_16 ( V_20 -> V_106 ) ;
V_268 . V_105 = F_16 ( V_20 -> V_105 ) ;
V_268 . V_155 = F_16 ( V_20 -> V_103 ) ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_294 ,
sizeof( V_268 ) , & V_268 ) ;
}
static void F_130 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
if ( ! F_86 ( V_10 -> V_2 , V_20 -> V_69 ) )
return;
if ( ! V_20 -> V_17 ) {
F_127 ( V_20 ) ;
return;
}
if ( V_20 -> V_35 == V_68 )
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
static void F_133 ( struct V_9 * V_10 )
{
struct V_295 V_268 ;
if ( V_10 -> V_296 & V_297 )
return;
V_268 . type = F_16 ( V_298 ) ;
V_10 -> V_296 |= V_297 ;
V_10 -> V_299 = F_88 ( V_10 ) ;
F_134 ( & V_10 -> V_300 , V_301 ) ;
F_80 ( V_10 , V_10 -> V_299 , V_302 ,
sizeof( V_268 ) , & V_268 ) ;
}
static void F_135 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
if ( V_10 -> V_2 -> type == V_3 ) {
F_130 ( V_20 ) ;
return;
}
if ( ! ( V_10 -> V_296 & V_297 ) ) {
F_133 ( V_10 ) ;
return;
}
if ( ! ( V_10 -> V_296 & V_303 ) )
return;
if ( F_85 ( V_20 , true ) &&
F_117 ( V_20 ) )
F_131 ( V_20 ) ;
}
static inline int F_136 ( T_1 V_136 , T_9 V_304 )
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
if ( V_20 -> V_136 == V_139 && V_20 -> V_35 == V_65 ) {
F_30 ( V_20 ) ;
F_75 ( V_20 ) ;
F_76 ( V_20 ) ;
}
if ( V_20 -> V_14 == V_311 ) {
F_20 ( V_20 , V_153 ) ;
return;
}
V_268 . V_13 = F_16 ( V_20 -> V_13 ) ;
V_268 . V_14 = F_16 ( V_20 -> V_14 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_312 ,
sizeof( V_268 ) , & V_268 ) ;
F_23 ( V_20 , V_153 , V_21 ) ;
}
static void F_137 ( struct V_9 * V_10 )
{
struct V_8 * V_20 , * V_313 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_138 (chan, tmp, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_29 != V_111 ) {
F_127 ( V_20 ) ;
F_46 ( V_20 ) ;
continue;
}
if ( V_20 -> V_35 == V_68 ) {
if ( ! F_85 ( V_20 , true ) ||
! F_117 ( V_20 ) ) {
F_46 ( V_20 ) ;
continue;
}
if ( ! F_136 ( V_20 -> V_136 , V_10 -> V_304 )
&& F_67 ( V_314 ,
& V_20 -> V_80 ) ) {
F_45 ( V_20 , V_315 ) ;
F_46 ( V_20 ) ;
continue;
}
F_131 ( V_20 ) ;
} else if ( V_20 -> V_35 == V_164 ) {
struct V_157 V_148 ;
char V_316 [ 128 ] ;
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( F_85 ( V_20 , false ) ) {
if ( F_67 ( V_150 , & V_20 -> V_98 ) ) {
V_148 . V_149 = F_16 ( V_317 ) ;
V_148 . V_159 = F_16 ( V_318 ) ;
V_20 -> V_36 -> V_319 ( V_20 ) ;
} else {
F_20 ( V_20 , V_66 ) ;
V_148 . V_149 = F_16 ( V_320 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
}
} else {
V_148 . V_149 = F_16 ( V_317 ) ;
V_148 . V_159 = F_16 ( V_321 ) ;
}
F_80 ( V_10 , V_20 -> V_16 , V_161 ,
sizeof( V_148 ) , & V_148 ) ;
if ( F_67 ( V_322 , & V_20 -> V_80 ) ||
V_148 . V_149 != V_320 ) {
F_46 ( V_20 ) ;
continue;
}
F_54 ( V_322 , & V_20 -> V_80 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_323 ,
F_139 ( V_20 , V_316 ) , V_316 ) ;
V_20 -> V_324 ++ ;
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_140 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_256 * V_185 = V_2 -> V_185 ;
F_21 ( L_15 , V_185 -> V_325 , V_10 ) ;
if ( V_2 -> V_326 )
F_86 ( V_2 , V_2 -> V_327 ) ;
if ( V_2 -> V_328 == V_329 &&
( V_2 -> V_330 < V_2 -> V_331 ||
V_2 -> V_330 > V_2 -> V_332 ) ) {
struct V_333 V_268 ;
V_268 . V_334 = F_16 ( V_2 -> V_331 ) ;
V_268 . V_335 = F_16 ( V_2 -> V_332 ) ;
V_268 . V_336 = F_16 ( V_2 -> V_337 ) ;
V_268 . V_338 = F_16 ( V_2 -> V_339 ) ;
F_80 ( V_10 , F_88 ( V_10 ) ,
V_340 , sizeof( V_268 ) , & V_268 ) ;
}
}
static void F_141 ( struct V_9 * V_10 )
{
struct V_8 * V_20 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_21 ( L_14 , V_10 ) ;
if ( V_2 -> type == V_112 )
F_133 ( V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_14 == V_311 ) {
F_46 ( V_20 ) ;
continue;
}
if ( V_2 -> type == V_3 ) {
F_130 ( V_20 ) ;
} else if ( V_20 -> V_29 != V_111 ) {
if ( V_10 -> V_296 & V_303 )
F_127 ( V_20 ) ;
} else if ( V_20 -> V_35 == V_68 ) {
F_135 ( V_20 ) ;
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
if ( V_2 -> type == V_3 )
F_140 ( V_10 ) ;
F_142 ( V_2 -> V_185 -> V_341 , & V_10 -> V_342 ) ;
}
static void F_143 ( struct V_9 * V_10 , int V_21 )
{
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( F_67 ( V_343 , & V_20 -> V_98 ) )
F_24 ( V_20 , V_21 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_144 ( struct V_61 * V_62 )
{
struct V_9 * V_10 = F_44 ( V_62 , struct V_9 ,
V_300 . V_62 ) ;
V_10 -> V_296 |= V_303 ;
V_10 -> V_299 = 0 ;
F_137 ( V_10 ) ;
}
int F_145 ( struct V_9 * V_10 , struct V_344 * V_345 )
{
struct V_256 * V_185 = V_10 -> V_2 -> V_185 ;
int V_346 ;
F_146 ( V_185 ) ;
if ( V_345 -> V_54 . V_347 || V_345 -> V_54 . V_348 ) {
V_346 = - V_26 ;
goto V_349;
}
if ( ! V_10 -> V_192 ) {
V_346 = - V_350 ;
goto V_349;
}
V_346 = V_345 -> V_351 ( V_10 , V_345 ) ;
if ( V_346 )
goto V_349;
F_51 ( & V_345 -> V_54 , & V_10 -> V_352 ) ;
V_346 = 0 ;
V_349:
F_147 ( V_185 ) ;
return V_346 ;
}
void F_148 ( struct V_9 * V_10 , struct V_344 * V_345 )
{
struct V_256 * V_185 = V_10 -> V_2 -> V_185 ;
F_146 ( V_185 ) ;
if ( ! V_345 -> V_54 . V_347 || ! V_345 -> V_54 . V_348 )
goto V_349;
F_56 ( & V_345 -> V_54 ) ;
V_345 -> V_54 . V_347 = NULL ;
V_345 -> V_54 . V_348 = NULL ;
V_345 -> remove ( V_10 , V_345 ) ;
V_349:
F_147 ( V_185 ) ;
}
static void F_149 ( struct V_9 * V_10 )
{
struct V_344 * V_345 ;
while ( ! F_150 ( & V_10 -> V_352 ) ) {
V_345 = F_151 ( & V_10 -> V_352 , struct V_344 , V_54 ) ;
F_56 ( & V_345 -> V_54 ) ;
V_345 -> V_54 . V_347 = NULL ;
V_345 -> V_54 . V_348 = NULL ;
V_345 -> remove ( V_10 , V_345 ) ;
}
}
static void F_152 ( struct V_1 * V_2 , int V_21 )
{
struct V_9 * V_10 = V_2 -> V_353 ;
struct V_8 * V_20 , * V_354 ;
if ( ! V_10 )
return;
F_21 ( L_16 , V_2 , V_10 , V_21 ) ;
F_94 ( V_10 -> V_355 ) ;
F_74 ( & V_10 -> V_356 ) ;
if ( F_153 ( & V_10 -> V_342 ) )
F_154 ( & V_10 -> V_342 ) ;
if ( F_153 ( & V_10 -> V_144 ) )
F_154 ( & V_10 -> V_144 ) ;
F_149 ( V_10 ) ;
V_2 -> V_357 = 0 ;
F_6 ( & V_10 -> V_15 ) ;
F_138 (chan, l, &conn->chan_l, list) {
F_57 ( V_20 ) ;
F_7 ( V_20 ) ;
F_70 ( V_20 , V_21 ) ;
F_46 ( V_20 ) ;
V_20 -> V_36 -> V_72 ( V_20 ) ;
F_47 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
F_155 ( V_10 -> V_192 ) ;
if ( V_10 -> V_296 & V_297 )
F_156 ( & V_10 -> V_300 ) ;
V_2 -> V_353 = NULL ;
V_10 -> V_192 = NULL ;
F_157 ( V_10 ) ;
}
static void F_158 ( struct V_78 * V_358 )
{
struct V_9 * V_10 = F_44 ( V_358 , struct V_9 , V_358 ) ;
F_159 ( V_10 -> V_2 ) ;
F_38 ( V_10 ) ;
}
struct V_9 * F_160 ( struct V_9 * V_10 )
{
F_59 ( & V_10 -> V_358 ) ;
return V_10 ;
}
void F_157 ( struct V_9 * V_10 )
{
F_60 ( & V_10 -> V_358 , F_158 ) ;
}
static struct V_8 * F_161 ( int V_35 , T_4 V_17 ,
T_5 * V_18 ,
T_5 * V_145 ,
T_3 V_359 )
{
struct V_8 * V_12 , * V_360 = NULL ;
F_119 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_35 && V_12 -> V_35 != V_35 )
continue;
if ( V_359 == V_112 && V_12 -> V_361 != V_7 )
continue;
if ( V_359 == V_3 && V_12 -> V_361 == V_7 )
continue;
if ( V_12 -> V_17 == V_17 ) {
int V_362 , V_363 ;
int V_364 , V_365 ;
V_362 = ! F_13 ( & V_12 -> V_18 , V_18 ) ;
V_363 = ! F_13 ( & V_12 -> V_145 , V_145 ) ;
if ( V_362 && V_363 ) {
F_57 ( V_12 ) ;
F_120 ( & V_22 ) ;
return V_12 ;
}
V_364 = ! F_13 ( & V_12 -> V_18 , V_366 ) ;
V_365 = ! F_13 ( & V_12 -> V_145 , V_366 ) ;
if ( ( V_362 && V_365 ) || ( V_364 && V_363 ) ||
( V_364 && V_365 ) )
V_360 = V_12 ;
}
}
if ( V_360 )
F_57 ( V_360 ) ;
F_120 ( & V_22 ) ;
return V_360 ;
}
static void F_162 ( struct V_61 * V_62 )
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
F_126 ( V_20 , NULL , NULL , V_367 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
static void F_163 ( struct V_61 * V_62 )
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
F_126 ( V_20 , NULL , NULL , V_368 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
static void F_164 ( struct V_8 * V_20 ,
struct V_43 * V_369 )
{
struct V_42 * V_46 ;
struct V_200 * V_47 ;
F_21 ( L_17 , V_20 , V_369 ) ;
if ( F_92 ( V_20 ) )
return;
F_165 ( V_369 , & V_20 -> V_108 ) ;
while ( ! F_166 ( & V_20 -> V_108 ) ) {
V_46 = F_167 ( & V_20 -> V_108 ) ;
F_33 ( V_46 ) -> V_47 . V_274 = 1 ;
V_47 = & F_33 ( V_46 ) -> V_47 ;
V_47 -> V_201 = 0 ;
V_47 -> V_48 = V_20 -> V_370 ;
F_103 ( V_20 , V_47 , V_46 ) ;
if ( V_20 -> V_82 == V_83 ) {
T_2 V_82 = F_111 ( 0 , ( T_3 * ) V_46 -> V_184 , V_46 -> V_183 ) ;
F_105 ( V_82 , F_110 ( V_46 , V_244 ) ) ;
}
F_93 ( V_20 , V_46 ) ;
F_21 ( L_18 , V_47 -> V_48 ) ;
V_20 -> V_370 = F_168 ( V_20 , V_20 -> V_370 ) ;
V_20 -> V_371 ++ ;
}
}
static int F_169 ( struct V_8 * V_20 )
{
struct V_42 * V_46 , * V_372 ;
struct V_200 * V_47 ;
int V_373 = 0 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_35 != V_65 )
return - V_374 ;
if ( F_67 ( V_282 , & V_20 -> V_247 ) )
return 0 ;
if ( F_92 ( V_20 ) )
return 0 ;
while ( V_20 -> V_375 &&
V_20 -> V_376 < V_20 -> V_90 &&
V_20 -> V_278 == V_279 ) {
V_46 = V_20 -> V_375 ;
F_33 ( V_46 ) -> V_47 . V_274 = 1 ;
V_47 = & F_33 ( V_46 ) -> V_47 ;
if ( F_113 ( V_246 , & V_20 -> V_247 ) )
V_47 -> V_204 = 1 ;
V_47 -> V_201 = V_20 -> V_254 ;
V_20 -> V_252 = V_20 -> V_254 ;
V_47 -> V_48 = V_20 -> V_370 ;
F_103 ( V_20 , V_47 , V_46 ) ;
if ( V_20 -> V_82 == V_83 ) {
T_2 V_82 = F_111 ( 0 , ( T_3 * ) V_46 -> V_184 , V_46 -> V_183 ) ;
F_105 ( V_82 , F_110 ( V_46 , V_244 ) ) ;
}
V_372 = F_170 ( V_46 , V_55 ) ;
if ( ! V_372 )
break;
F_25 ( V_20 ) ;
V_20 -> V_370 = F_168 ( V_20 , V_20 -> V_370 ) ;
V_20 -> V_376 ++ ;
V_20 -> V_371 ++ ;
V_373 ++ ;
if ( F_171 ( & V_20 -> V_108 , V_46 ) )
V_20 -> V_375 = NULL ;
else
V_20 -> V_375 = F_172 ( & V_20 -> V_108 , V_46 ) ;
F_93 ( V_20 , V_372 ) ;
F_21 ( L_18 , V_47 -> V_48 ) ;
}
F_21 ( L_19 , V_373 ,
V_20 -> V_376 , F_173 ( & V_20 -> V_108 ) ) ;
return V_373 ;
}
static void F_174 ( struct V_8 * V_20 )
{
struct V_200 V_47 ;
struct V_42 * V_46 ;
struct V_42 * V_372 ;
T_2 V_45 ;
F_21 ( L_3 , V_20 ) ;
if ( F_67 ( V_282 , & V_20 -> V_247 ) )
return;
if ( F_92 ( V_20 ) )
return;
while ( V_20 -> V_142 . V_44 != V_58 ) {
V_45 = F_40 ( & V_20 -> V_142 ) ;
V_46 = F_31 ( & V_20 -> V_108 , V_45 ) ;
if ( ! V_46 ) {
F_21 ( L_20 ,
V_45 ) ;
continue;
}
F_33 ( V_46 ) -> V_47 . V_274 ++ ;
V_47 = F_33 ( V_46 ) -> V_47 ;
if ( V_20 -> V_84 != 0 &&
F_33 ( V_46 ) -> V_47 . V_274 > V_20 -> V_84 ) {
F_21 ( L_21 , V_20 -> V_84 ) ;
F_83 ( V_20 , V_315 ) ;
F_41 ( & V_20 -> V_142 ) ;
break;
}
V_47 . V_201 = V_20 -> V_254 ;
if ( F_113 ( V_246 , & V_20 -> V_247 ) )
V_47 . V_204 = 1 ;
else
V_47 . V_204 = 0 ;
if ( F_175 ( V_46 ) ) {
V_372 = F_176 ( V_46 , V_55 ) ;
} else {
V_372 = F_170 ( V_46 , V_55 ) ;
}
if ( ! V_372 ) {
F_41 ( & V_20 -> V_142 ) ;
break;
}
if ( F_67 ( V_234 , & V_20 -> V_98 ) ) {
F_104 ( F_101 ( & V_47 ) ,
V_372 -> V_184 + V_238 ) ;
} else {
F_105 ( F_102 ( & V_47 ) ,
V_372 -> V_184 + V_238 ) ;
}
if ( V_20 -> V_82 == V_83 ) {
T_2 V_82 = F_111 ( 0 , ( T_3 * ) V_372 -> V_184 ,
V_372 -> V_183 - V_244 ) ;
F_105 ( V_82 , F_177 ( V_372 ) -
V_244 ) ;
}
F_93 ( V_20 , V_372 ) ;
F_21 ( L_22 , V_47 . V_48 ) ;
V_20 -> V_252 = V_20 -> V_254 ;
}
}
static void F_178 ( struct V_8 * V_20 ,
struct V_200 * V_47 )
{
F_21 ( L_10 , V_20 , V_47 ) ;
F_42 ( & V_20 -> V_142 , V_47 -> V_201 ) ;
F_174 ( V_20 ) ;
}
static void F_179 ( struct V_8 * V_20 ,
struct V_200 * V_47 )
{
struct V_42 * V_46 ;
F_21 ( L_10 , V_20 , V_47 ) ;
if ( V_47 -> V_209 )
F_54 ( V_246 , & V_20 -> V_247 ) ;
F_41 ( & V_20 -> V_142 ) ;
if ( F_67 ( V_282 , & V_20 -> V_247 ) )
return;
if ( V_20 -> V_376 ) {
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_46 ) -> V_47 . V_48 == V_47 -> V_201 ||
V_46 == V_20 -> V_375 )
break;
}
F_180 (&chan->tx_q, skb) {
if ( V_46 == V_20 -> V_375 )
break;
F_42 ( & V_20 -> V_142 ,
F_33 ( V_46 ) -> V_47 . V_48 ) ;
}
F_174 ( V_20 ) ;
}
}
static void F_181 ( struct V_8 * V_20 )
{
struct V_200 V_47 ;
T_2 V_377 = F_182 ( V_20 , V_20 -> V_254 ,
V_20 -> V_252 ) ;
int V_378 ;
F_21 ( L_23 ,
V_20 , V_20 -> V_252 , V_20 -> V_254 ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_208 = 1 ;
if ( F_67 ( V_253 , & V_20 -> V_247 ) &&
V_20 -> V_280 == V_379 ) {
F_76 ( V_20 ) ;
V_47 . V_212 = V_250 ;
V_47 . V_201 = V_20 -> V_254 ;
F_112 ( V_20 , & V_47 ) ;
} else {
if ( ! F_67 ( V_282 , & V_20 -> V_247 ) ) {
F_169 ( V_20 ) ;
if ( V_20 -> V_254 == V_20 -> V_252 )
V_377 = 0 ;
}
V_378 = V_20 -> V_91 ;
V_378 += V_378 << 1 ;
V_378 >>= 2 ;
F_21 ( L_24 , V_377 ,
V_378 ) ;
if ( V_377 >= V_378 ) {
F_76 ( V_20 ) ;
V_47 . V_212 = V_248 ;
V_47 . V_201 = V_20 -> V_254 ;
F_112 ( V_20 , & V_47 ) ;
V_377 = 0 ;
}
if ( V_377 )
F_183 ( V_20 ) ;
}
}
static inline int F_184 ( struct V_8 * V_20 ,
struct V_380 * V_381 , int V_183 ,
int V_382 , struct V_42 * V_46 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_42 * * V_383 ;
int V_373 = 0 ;
if ( V_20 -> V_36 -> V_384 ( V_20 , F_110 ( V_46 , V_382 ) ,
V_381 -> V_385 , V_382 ) )
return - V_386 ;
V_373 += V_382 ;
V_183 -= V_382 ;
V_383 = & F_185 ( V_46 ) -> V_387 ;
while ( V_183 ) {
struct V_42 * V_313 ;
V_382 = F_63 (unsigned int, conn->mtu, len) ;
V_313 = V_20 -> V_36 -> V_388 ( V_20 , 0 , V_382 ,
V_381 -> V_389 & V_390 ) ;
if ( F_115 ( V_313 ) )
return F_186 ( V_313 ) ;
* V_383 = V_313 ;
if ( V_20 -> V_36 -> V_384 ( V_20 , F_110 ( * V_383 , V_382 ) ,
V_381 -> V_385 , V_382 ) )
return - V_386 ;
V_373 += V_382 ;
V_183 -= V_382 ;
V_46 -> V_183 += ( * V_383 ) -> V_183 ;
V_46 -> V_391 += ( * V_383 ) -> V_183 ;
V_383 = & ( * V_383 ) -> V_347 ;
}
return V_373 ;
}
static struct V_42 * F_187 ( struct V_8 * V_20 ,
struct V_380 * V_381 , T_7 V_183 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_42 * V_46 ;
int V_21 , V_382 , V_243 = V_238 + V_392 ;
struct V_241 * V_242 ;
F_21 ( L_25 , V_20 ,
F_66 ( V_20 -> V_17 ) , V_183 ) ;
V_382 = F_63 (unsigned int, (conn->mtu - hlen), len) ;
V_46 = V_20 -> V_36 -> V_388 ( V_20 , V_243 , V_382 ,
V_381 -> V_389 & V_390 ) ;
if ( F_115 ( V_46 ) )
return V_46 ;
V_242 = (struct V_241 * ) F_110 ( V_46 , V_238 ) ;
V_242 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_242 -> V_183 = F_16 ( V_183 + V_392 ) ;
F_188 ( V_20 -> V_17 , ( T_4 * ) F_110 ( V_46 , V_392 ) ) ;
V_21 = F_184 ( V_20 , V_381 , V_183 , V_382 , V_46 ) ;
if ( F_189 ( V_21 < 0 ) ) {
F_94 ( V_46 ) ;
return F_109 ( V_21 ) ;
}
return V_46 ;
}
static struct V_42 * F_190 ( struct V_8 * V_20 ,
struct V_380 * V_381 , T_7 V_183 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_42 * V_46 ;
int V_21 , V_382 ;
struct V_241 * V_242 ;
F_21 ( L_26 , V_20 , V_183 ) ;
V_382 = F_63 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_46 = V_20 -> V_36 -> V_388 ( V_20 , V_238 , V_382 ,
V_381 -> V_389 & V_390 ) ;
if ( F_115 ( V_46 ) )
return V_46 ;
V_242 = (struct V_241 * ) F_110 ( V_46 , V_238 ) ;
V_242 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_242 -> V_183 = F_16 ( V_183 ) ;
V_21 = F_184 ( V_20 , V_381 , V_183 , V_382 , V_46 ) ;
if ( F_189 ( V_21 < 0 ) ) {
F_94 ( V_46 ) ;
return F_109 ( V_21 ) ;
}
return V_46 ;
}
static struct V_42 * F_191 ( struct V_8 * V_20 ,
struct V_380 * V_381 , T_7 V_183 ,
T_2 V_393 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_42 * V_46 ;
int V_21 , V_382 , V_243 ;
struct V_241 * V_242 ;
F_21 ( L_26 , V_20 , V_183 ) ;
if ( ! V_10 )
return F_109 ( - V_374 ) ;
V_243 = F_106 ( V_20 ) ;
if ( V_393 )
V_243 += V_394 ;
if ( V_20 -> V_82 == V_83 )
V_243 += V_244 ;
V_382 = F_63 (unsigned int, (conn->mtu - hlen), len) ;
V_46 = V_20 -> V_36 -> V_388 ( V_20 , V_243 , V_382 ,
V_381 -> V_389 & V_390 ) ;
if ( F_115 ( V_46 ) )
return V_46 ;
V_242 = (struct V_241 * ) F_110 ( V_46 , V_238 ) ;
V_242 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_242 -> V_183 = F_16 ( V_183 + ( V_243 - V_238 ) ) ;
if ( F_67 ( V_234 , & V_20 -> V_98 ) )
F_104 ( 0 , F_110 ( V_46 , V_235 ) ) ;
else
F_105 ( 0 , F_110 ( V_46 , V_236 ) ) ;
if ( V_393 )
F_105 ( V_393 , F_110 ( V_46 , V_394 ) ) ;
V_21 = F_184 ( V_20 , V_381 , V_183 , V_382 , V_46 ) ;
if ( F_189 ( V_21 < 0 ) ) {
F_94 ( V_46 ) ;
return F_109 ( V_21 ) ;
}
F_33 ( V_46 ) -> V_47 . V_82 = V_20 -> V_82 ;
F_33 ( V_46 ) -> V_47 . V_274 = 0 ;
return V_46 ;
}
static int F_192 ( struct V_8 * V_20 ,
struct V_43 * V_395 ,
struct V_380 * V_381 , T_7 V_183 )
{
struct V_42 * V_46 ;
T_2 V_101 ;
T_7 V_396 ;
T_3 V_215 ;
F_21 ( L_27 , V_20 , V_381 , V_183 ) ;
V_396 = V_20 -> V_10 -> V_154 ;
if ( ! V_20 -> V_196 )
V_396 = F_63 ( T_7 , V_396 , V_397 ) ;
if ( V_20 -> V_82 )
V_396 -= V_244 ;
V_396 -= F_106 ( V_20 ) ;
V_396 = F_63 ( T_7 , V_396 , V_20 -> V_398 ) ;
if ( V_183 <= V_396 ) {
V_215 = V_399 ;
V_101 = 0 ;
V_396 = V_183 ;
} else {
V_215 = V_400 ;
V_101 = V_183 ;
}
while ( V_183 > 0 ) {
V_46 = F_191 ( V_20 , V_381 , V_396 , V_101 ) ;
if ( F_115 ( V_46 ) ) {
F_193 ( V_395 ) ;
return F_186 ( V_46 ) ;
}
F_33 ( V_46 ) -> V_47 . V_215 = V_215 ;
F_194 ( V_395 , V_46 ) ;
V_183 -= V_396 ;
if ( V_101 )
V_101 = 0 ;
if ( V_183 <= V_396 ) {
V_215 = V_401 ;
V_396 = V_183 ;
} else {
V_215 = V_402 ;
}
}
return 0 ;
}
static struct V_42 * F_195 ( struct V_8 * V_20 ,
struct V_380 * V_381 ,
T_7 V_183 , T_2 V_393 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_42 * V_46 ;
int V_21 , V_382 , V_243 ;
struct V_241 * V_242 ;
F_21 ( L_26 , V_20 , V_183 ) ;
if ( ! V_10 )
return F_109 ( - V_374 ) ;
V_243 = V_238 ;
if ( V_393 )
V_243 += V_394 ;
V_382 = F_63 (unsigned int, (conn->mtu - hlen), len) ;
V_46 = V_20 -> V_36 -> V_388 ( V_20 , V_243 , V_382 ,
V_381 -> V_389 & V_390 ) ;
if ( F_115 ( V_46 ) )
return V_46 ;
V_242 = (struct V_241 * ) F_110 ( V_46 , V_238 ) ;
V_242 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_242 -> V_183 = F_16 ( V_183 + ( V_243 - V_238 ) ) ;
if ( V_393 )
F_105 ( V_393 , F_110 ( V_46 , V_394 ) ) ;
V_21 = F_184 ( V_20 , V_381 , V_183 , V_382 , V_46 ) ;
if ( F_189 ( V_21 < 0 ) ) {
F_94 ( V_46 ) ;
return F_109 ( V_21 ) ;
}
return V_46 ;
}
static int F_196 ( struct V_8 * V_20 ,
struct V_43 * V_395 ,
struct V_380 * V_381 , T_7 V_183 )
{
struct V_42 * V_46 ;
T_7 V_396 ;
T_2 V_101 ;
F_21 ( L_27 , V_20 , V_381 , V_183 ) ;
V_101 = V_183 ;
V_396 = V_20 -> V_398 - V_394 ;
while ( V_183 > 0 ) {
if ( V_183 <= V_396 )
V_396 = V_183 ;
V_46 = F_195 ( V_20 , V_381 , V_396 , V_101 ) ;
if ( F_115 ( V_46 ) ) {
F_193 ( V_395 ) ;
return F_186 ( V_46 ) ;
}
F_194 ( V_395 , V_46 ) ;
V_183 -= V_396 ;
if ( V_101 ) {
V_101 = 0 ;
V_396 += V_394 ;
}
}
return 0 ;
}
int F_197 ( struct V_8 * V_20 , struct V_380 * V_381 , T_7 V_183 )
{
struct V_42 * V_46 ;
int V_21 ;
struct V_43 V_395 ;
if ( ! V_20 -> V_10 )
return - V_374 ;
if ( V_20 -> V_29 == V_113 ) {
V_46 = F_187 ( V_20 , V_381 , V_183 ) ;
if ( F_115 ( V_46 ) )
return F_186 ( V_46 ) ;
if ( V_20 -> V_35 != V_65 ) {
F_94 ( V_46 ) ;
return - V_374 ;
}
F_93 ( V_20 , V_46 ) ;
return V_183 ;
}
switch ( V_20 -> V_136 ) {
case V_138 :
if ( V_183 > V_20 -> V_27 )
return - V_403 ;
if ( ! V_20 -> V_102 )
return - V_404 ;
F_198 ( & V_395 ) ;
V_21 = F_196 ( V_20 , & V_395 , V_381 , V_183 ) ;
if ( V_20 -> V_35 != V_65 ) {
F_193 ( & V_395 ) ;
V_21 = - V_374 ;
}
if ( V_21 )
return V_21 ;
F_165 ( & V_395 , & V_20 -> V_108 ) ;
while ( V_20 -> V_102 && ! F_166 ( & V_20 -> V_108 ) ) {
F_93 ( V_20 , F_167 ( & V_20 -> V_108 ) ) ;
V_20 -> V_102 -- ;
}
if ( ! V_20 -> V_102 )
V_20 -> V_36 -> V_290 ( V_20 ) ;
V_21 = V_183 ;
break;
case V_137 :
if ( V_183 > V_20 -> V_27 )
return - V_403 ;
V_46 = F_190 ( V_20 , V_381 , V_183 ) ;
if ( F_115 ( V_46 ) )
return F_186 ( V_46 ) ;
if ( V_20 -> V_35 != V_65 ) {
F_94 ( V_46 ) ;
return - V_374 ;
}
F_93 ( V_20 , V_46 ) ;
V_21 = V_183 ;
break;
case V_139 :
case V_143 :
if ( V_183 > V_20 -> V_27 ) {
V_21 = - V_403 ;
break;
}
F_198 ( & V_395 ) ;
V_21 = F_192 ( V_20 , & V_395 , V_381 , V_183 ) ;
if ( V_20 -> V_35 != V_65 ) {
F_193 ( & V_395 ) ;
V_21 = - V_374 ;
}
if ( V_21 )
break;
if ( V_20 -> V_136 == V_139 )
F_126 ( V_20 , NULL , & V_395 , V_405 ) ;
else
F_164 ( V_20 , & V_395 ) ;
V_21 = V_183 ;
F_193 ( & V_395 ) ;
break;
default:
F_21 ( L_28 , V_20 -> V_136 ) ;
V_21 = - V_406 ;
}
return V_21 ;
}
static void F_199 ( struct V_8 * V_20 , T_2 V_48 )
{
struct V_200 V_47 ;
T_2 V_45 ;
F_21 ( L_29 , V_20 , V_48 ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_208 = 1 ;
V_47 . V_212 = V_251 ;
for ( V_45 = V_20 -> V_275 ; V_45 != V_48 ;
V_45 = F_168 ( V_20 , V_45 ) ) {
if ( ! F_31 ( & V_20 -> V_140 , V_45 ) ) {
V_47 . V_201 = V_45 ;
F_112 ( V_20 , & V_47 ) ;
F_42 ( & V_20 -> V_141 , V_45 ) ;
}
}
V_20 -> V_275 = F_168 ( V_20 , V_48 ) ;
}
static void F_200 ( struct V_8 * V_20 )
{
struct V_200 V_47 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_141 . V_59 == V_58 )
return;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_208 = 1 ;
V_47 . V_212 = V_251 ;
V_47 . V_201 = V_20 -> V_141 . V_59 ;
F_112 ( V_20 , & V_47 ) ;
}
static void F_201 ( struct V_8 * V_20 , T_2 V_48 )
{
struct V_200 V_47 ;
T_2 V_407 ;
T_2 V_45 ;
F_21 ( L_29 , V_20 , V_48 ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_208 = 1 ;
V_47 . V_212 = V_251 ;
V_407 = V_20 -> V_141 . V_44 ;
do {
V_45 = F_40 ( & V_20 -> V_141 ) ;
if ( V_45 == V_48 || V_45 == V_58 )
break;
V_47 . V_201 = V_45 ;
F_112 ( V_20 , & V_47 ) ;
F_42 ( & V_20 -> V_141 , V_45 ) ;
} while ( V_20 -> V_141 . V_44 != V_407 );
}
static void F_202 ( struct V_8 * V_20 , T_2 V_201 )
{
struct V_42 * V_408 ;
T_2 V_409 ;
F_21 ( L_30 , V_20 , V_201 ) ;
if ( V_20 -> V_376 == 0 || V_201 == V_20 -> V_410 )
return;
F_21 ( L_31 ,
V_20 -> V_410 , V_20 -> V_376 ) ;
for ( V_409 = V_20 -> V_410 ; V_409 != V_201 ;
V_409 = F_168 ( V_20 , V_409 ) ) {
V_408 = F_31 ( & V_20 -> V_108 , V_409 ) ;
if ( V_408 ) {
F_203 ( V_408 , & V_20 -> V_108 ) ;
F_94 ( V_408 ) ;
V_20 -> V_376 -- ;
}
}
V_20 -> V_410 = V_201 ;
if ( V_20 -> V_376 == 0 )
F_30 ( V_20 ) ;
F_21 ( L_32 , V_20 -> V_376 ) ;
}
static void F_204 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_275 = V_20 -> V_254 ;
F_41 ( & V_20 -> V_141 ) ;
F_74 ( & V_20 -> V_140 ) ;
V_20 -> V_280 = V_379 ;
}
static void F_205 ( struct V_8 * V_20 ,
struct V_200 * V_47 ,
struct V_43 * V_369 , T_3 V_411 )
{
F_21 ( L_33 , V_20 , V_47 , V_369 ,
V_411 ) ;
switch ( V_411 ) {
case V_405 :
if ( V_20 -> V_375 == NULL )
V_20 -> V_375 = F_206 ( V_369 ) ;
F_165 ( V_369 , & V_20 -> V_108 ) ;
F_169 ( V_20 ) ;
break;
case V_412 :
F_21 ( L_34 ) ;
F_54 ( V_253 , & V_20 -> V_247 ) ;
if ( V_20 -> V_280 == V_413 ) {
F_204 ( V_20 ) ;
}
F_181 ( V_20 ) ;
break;
case V_414 :
F_21 ( L_35 ) ;
F_114 ( V_253 , & V_20 -> V_247 ) ;
if ( F_67 ( V_249 , & V_20 -> V_247 ) ) {
struct V_200 V_415 ;
memset ( & V_415 , 0 , sizeof( V_415 ) ) ;
V_415 . V_208 = 1 ;
V_415 . V_212 = V_248 ;
V_415 . V_209 = 1 ;
V_415 . V_201 = V_20 -> V_254 ;
F_112 ( V_20 , & V_415 ) ;
V_20 -> V_273 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_278 = V_416 ;
}
break;
case V_417 :
F_202 ( V_20 , V_47 -> V_201 ) ;
break;
case V_286 :
F_116 ( V_20 , 1 ) ;
V_20 -> V_273 = 1 ;
F_29 ( V_20 ) ;
F_76 ( V_20 ) ;
V_20 -> V_278 = V_416 ;
break;
case V_368 :
F_116 ( V_20 , 1 ) ;
V_20 -> V_273 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_278 = V_416 ;
break;
case V_418 :
break;
default:
break;
}
}
static void F_207 ( struct V_8 * V_20 ,
struct V_200 * V_47 ,
struct V_43 * V_369 , T_3 V_411 )
{
F_21 ( L_33 , V_20 , V_47 , V_369 ,
V_411 ) ;
switch ( V_411 ) {
case V_405 :
if ( V_20 -> V_375 == NULL )
V_20 -> V_375 = F_206 ( V_369 ) ;
F_165 ( V_369 , & V_20 -> V_108 ) ;
break;
case V_412 :
F_21 ( L_34 ) ;
F_54 ( V_253 , & V_20 -> V_247 ) ;
if ( V_20 -> V_280 == V_413 ) {
F_204 ( V_20 ) ;
}
F_181 ( V_20 ) ;
break;
case V_414 :
F_21 ( L_35 ) ;
F_114 ( V_253 , & V_20 -> V_247 ) ;
if ( F_67 ( V_249 , & V_20 -> V_247 ) ) {
struct V_200 V_415 ;
memset ( & V_415 , 0 , sizeof( V_415 ) ) ;
V_415 . V_208 = 1 ;
V_415 . V_212 = V_248 ;
V_415 . V_209 = 1 ;
V_415 . V_201 = V_20 -> V_254 ;
F_112 ( V_20 , & V_415 ) ;
V_20 -> V_273 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_278 = V_416 ;
}
break;
case V_417 :
F_202 ( V_20 , V_47 -> V_201 ) ;
case V_418 :
if ( V_47 && V_47 -> V_204 ) {
F_75 ( V_20 ) ;
if ( V_20 -> V_376 > 0 )
F_25 ( V_20 ) ;
V_20 -> V_273 = 0 ;
V_20 -> V_278 = V_279 ;
F_21 ( L_36 , V_20 -> V_278 ) ;
}
break;
case V_286 :
break;
case V_367 :
if ( V_20 -> V_84 == 0 || V_20 -> V_273 < V_20 -> V_84 ) {
F_116 ( V_20 , 1 ) ;
F_29 ( V_20 ) ;
V_20 -> V_273 ++ ;
} else {
F_83 ( V_20 , V_419 ) ;
}
break;
default:
break;
}
}
static void F_126 ( struct V_8 * V_20 , struct V_200 * V_47 ,
struct V_43 * V_369 , T_3 V_411 )
{
F_21 ( L_37 ,
V_20 , V_47 , V_369 , V_411 , V_20 -> V_278 ) ;
switch ( V_20 -> V_278 ) {
case V_279 :
F_205 ( V_20 , V_47 , V_369 , V_411 ) ;
break;
case V_416 :
F_207 ( V_20 , V_47 , V_369 , V_411 ) ;
break;
default:
break;
}
}
static void F_208 ( struct V_8 * V_20 ,
struct V_200 * V_47 )
{
F_21 ( L_10 , V_20 , V_47 ) ;
F_126 ( V_20 , V_47 , NULL , V_417 ) ;
}
static void F_209 ( struct V_8 * V_20 ,
struct V_200 * V_47 )
{
F_21 ( L_10 , V_20 , V_47 ) ;
F_126 ( V_20 , V_47 , NULL , V_418 ) ;
}
static void F_210 ( struct V_9 * V_10 , struct V_42 * V_46 )
{
struct V_42 * V_420 ;
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( V_20 -> V_29 != V_165 )
continue;
if ( F_33 ( V_46 ) -> V_20 == V_20 )
continue;
V_420 = F_170 ( V_46 , V_55 ) ;
if ( ! V_420 )
continue;
if ( V_20 -> V_36 -> V_421 ( V_20 , V_420 ) )
F_94 ( V_420 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static struct V_42 * F_89 ( struct V_9 * V_10 , T_3 V_182 ,
T_3 V_16 , T_2 V_422 , void * V_184 )
{
struct V_42 * V_46 , * * V_383 ;
struct V_423 * V_424 ;
struct V_241 * V_242 ;
int V_183 , V_382 ;
F_21 ( L_38 ,
V_10 , V_182 , V_16 , V_422 ) ;
if ( V_10 -> V_154 < V_238 + V_425 )
return NULL ;
V_183 = V_238 + V_425 + V_422 ;
V_382 = F_63 (unsigned int, conn->mtu, len) ;
V_46 = F_108 ( V_382 , V_55 ) ;
if ( ! V_46 )
return NULL ;
V_242 = (struct V_241 * ) F_110 ( V_46 , V_238 ) ;
V_242 -> V_183 = F_16 ( V_425 + V_422 ) ;
if ( V_10 -> V_2 -> type == V_3 )
V_242 -> V_11 = F_16 ( V_426 ) ;
else
V_242 -> V_11 = F_16 ( V_115 ) ;
V_424 = (struct V_423 * ) F_110 ( V_46 , V_425 ) ;
V_424 -> V_182 = V_182 ;
V_424 -> V_16 = V_16 ;
V_424 -> V_183 = F_16 ( V_422 ) ;
if ( V_422 ) {
V_382 -= V_238 + V_425 ;
memcpy ( F_110 ( V_46 , V_382 ) , V_184 , V_382 ) ;
V_184 += V_382 ;
}
V_183 -= V_46 -> V_183 ;
V_383 = & F_185 ( V_46 ) -> V_387 ;
while ( V_183 ) {
V_382 = F_63 (unsigned int, conn->mtu, len) ;
* V_383 = F_108 ( V_382 , V_55 ) ;
if ( ! * V_383 )
goto V_427;
memcpy ( F_110 ( * V_383 , V_382 ) , V_184 , V_382 ) ;
V_183 -= V_382 ;
V_184 += V_382 ;
V_383 = & ( * V_383 ) -> V_347 ;
}
return V_46 ;
V_427:
F_94 ( V_46 ) ;
return NULL ;
}
static inline int F_211 ( void * * V_428 , int * type , int * V_429 ,
unsigned long * V_430 )
{
struct V_431 * V_432 = * V_428 ;
int V_183 ;
V_183 = V_433 + V_432 -> V_183 ;
* V_428 += V_183 ;
* type = V_432 -> type ;
* V_429 = V_432 -> V_183 ;
switch ( V_432 -> V_183 ) {
case 1 :
* V_430 = * ( ( T_3 * ) V_432 -> V_430 ) ;
break;
case 2 :
* V_430 = F_100 ( V_432 -> V_430 ) ;
break;
case 4 :
* V_430 = F_98 ( V_432 -> V_430 ) ;
break;
default:
* V_430 = ( unsigned long ) V_432 -> V_430 ;
break;
}
F_21 ( L_39 , * type , V_432 -> V_183 , * V_430 ) ;
return V_183 ;
}
static void F_212 ( void * * V_428 , T_3 type , T_3 V_183 , unsigned long V_430 )
{
struct V_431 * V_432 = * V_428 ;
F_21 ( L_39 , type , V_183 , V_430 ) ;
V_432 -> type = type ;
V_432 -> V_183 = V_183 ;
switch ( V_183 ) {
case 1 :
* ( ( T_3 * ) V_432 -> V_430 ) = V_430 ;
break;
case 2 :
F_105 ( V_430 , V_432 -> V_430 ) ;
break;
case 4 :
F_104 ( V_430 , V_432 -> V_430 ) ;
break;
default:
memcpy ( V_432 -> V_430 , ( void * ) V_430 , V_183 ) ;
break;
}
* V_428 += V_433 + V_183 ;
}
static void F_213 ( void * * V_428 , struct V_8 * V_20 )
{
struct V_434 V_435 ;
switch ( V_20 -> V_136 ) {
case V_139 :
V_435 . V_179 = V_20 -> V_116 ;
V_435 . V_436 = V_20 -> V_118 ;
V_435 . V_437 = F_16 ( V_20 -> V_120 ) ;
V_435 . V_438 = F_214 ( V_20 -> V_122 ) ;
V_435 . V_439 = F_214 ( V_125 ) ;
V_435 . V_93 = F_214 ( V_127 ) ;
break;
case V_143 :
V_435 . V_179 = 1 ;
V_435 . V_436 = V_119 ;
V_435 . V_437 = F_16 ( V_20 -> V_120 ) ;
V_435 . V_438 = F_214 ( V_20 -> V_122 ) ;
V_435 . V_439 = 0 ;
V_435 . V_93 = 0 ;
break;
default:
return;
}
F_212 ( V_428 , V_440 , sizeof( V_435 ) ,
( unsigned long ) & V_435 ) ;
}
static void F_215 ( struct V_61 * V_62 )
{
struct V_8 * V_20 = F_44 ( V_62 , struct V_8 ,
V_441 . V_62 ) ;
T_2 V_377 ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
V_377 = F_182 ( V_20 , V_20 -> V_254 ,
V_20 -> V_252 ) ;
if ( V_377 )
F_116 ( V_20 , 0 ) ;
F_46 ( V_20 ) ;
F_47 ( V_20 ) ;
}
int F_216 ( struct V_8 * V_20 )
{
int V_21 ;
V_20 -> V_370 = 0 ;
V_20 -> V_275 = 0 ;
V_20 -> V_410 = 0 ;
V_20 -> V_376 = 0 ;
V_20 -> V_254 = 0 ;
V_20 -> V_371 = 0 ;
V_20 -> V_252 = 0 ;
V_20 -> V_99 = NULL ;
V_20 -> V_100 = NULL ;
V_20 -> V_101 = 0 ;
F_64 ( & V_20 -> V_108 ) ;
V_20 -> V_442 = V_443 ;
V_20 -> V_444 = V_443 ;
V_20 -> V_193 = V_194 ;
V_20 -> V_283 = V_284 ;
if ( V_20 -> V_136 != V_139 )
return 0 ;
V_20 -> V_280 = V_379 ;
V_20 -> V_278 = V_279 ;
F_52 ( & V_20 -> V_40 , F_163 ) ;
F_52 ( & V_20 -> V_38 , F_162 ) ;
F_52 ( & V_20 -> V_441 , F_215 ) ;
F_64 ( & V_20 -> V_140 ) ;
V_21 = F_34 ( & V_20 -> V_141 , V_20 -> V_86 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_34 ( & V_20 -> V_142 , V_20 -> V_90 ) ;
if ( V_21 < 0 )
F_37 ( & V_20 -> V_141 ) ;
return V_21 ;
}
static inline T_1 F_217 ( T_1 V_136 , T_6 V_445 )
{
switch ( V_136 ) {
case V_143 :
case V_139 :
if ( F_136 ( V_136 , V_445 ) )
return V_136 ;
default:
return V_137 ;
}
}
static inline bool F_218 ( struct V_9 * V_10 )
{
return V_10 -> V_258 && V_10 -> V_304 & V_446 ;
}
static inline bool F_219 ( struct V_9 * V_10 )
{
return V_10 -> V_258 && V_10 -> V_304 & V_447 ;
}
static void F_220 ( struct V_8 * V_20 ,
struct V_448 * V_449 )
{
if ( V_20 -> V_442 != V_443 && V_20 -> V_196 ) {
T_10 V_450 = V_20 -> V_196 -> V_185 -> V_451 ;
V_450 = F_221 ( V_450 , 1000 ) ;
V_450 = 3 * V_450 + 500 ;
if ( V_450 > 0xffff )
V_450 = 0xffff ;
V_449 -> V_39 = F_16 ( ( T_2 ) V_450 ) ;
V_449 -> V_41 = V_449 -> V_39 ;
} else {
V_449 -> V_39 = F_16 ( V_95 ) ;
V_449 -> V_41 = F_16 ( V_96 ) ;
}
}
static inline void F_222 ( struct V_8 * V_20 )
{
if ( V_20 -> V_86 > V_87 &&
F_218 ( V_20 -> V_10 ) ) {
F_54 ( V_234 , & V_20 -> V_98 ) ;
V_20 -> V_88 = V_452 ;
} else {
V_20 -> V_86 = F_63 ( T_2 , V_20 -> V_86 ,
V_87 ) ;
V_20 -> V_88 = V_87 ;
}
V_20 -> V_91 = V_20 -> V_86 ;
}
static int F_139 ( struct V_8 * V_20 , void * V_184 )
{
struct V_453 * V_268 = V_184 ;
struct V_448 V_449 = { . V_136 = V_20 -> V_136 } ;
void * V_428 = V_268 -> V_184 ;
T_2 V_51 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_324 || V_20 -> V_454 )
goto V_24;
switch ( V_20 -> V_136 ) {
case V_143 :
case V_139 :
if ( F_67 ( V_314 , & V_20 -> V_80 ) )
break;
if ( F_219 ( V_20 -> V_10 ) )
F_54 ( V_455 , & V_20 -> V_98 ) ;
default:
V_20 -> V_136 = F_217 ( V_449 . V_136 , V_20 -> V_10 -> V_304 ) ;
break;
}
V_24:
if ( V_20 -> V_106 != V_28 )
F_212 ( & V_428 , V_456 , 2 , V_20 -> V_106 ) ;
switch ( V_20 -> V_136 ) {
case V_137 :
if ( V_307 )
break;
if ( ! ( V_20 -> V_10 -> V_304 & V_308 ) &&
! ( V_20 -> V_10 -> V_304 & V_309 ) )
break;
V_449 . V_136 = V_137 ;
V_449 . V_457 = 0 ;
V_449 . V_458 = 0 ;
V_449 . V_39 = 0 ;
V_449 . V_41 = 0 ;
V_449 . V_459 = 0 ;
F_212 ( & V_428 , V_460 , sizeof( V_449 ) ,
( unsigned long ) & V_449 ) ;
break;
case V_139 :
V_449 . V_136 = V_139 ;
V_449 . V_458 = V_20 -> V_84 ;
F_220 ( V_20 , & V_449 ) ;
V_51 = F_63 ( T_2 , V_461 , V_20 -> V_10 -> V_154 -
V_239 - V_394 -
V_244 ) ;
V_449 . V_459 = F_16 ( V_51 ) ;
F_222 ( V_20 ) ;
V_449 . V_457 = F_63 ( T_2 , V_20 -> V_86 ,
V_87 ) ;
F_212 ( & V_428 , V_460 , sizeof( V_449 ) ,
( unsigned long ) & V_449 ) ;
if ( F_67 ( V_455 , & V_20 -> V_98 ) )
F_213 ( & V_428 , V_20 ) ;
if ( F_67 ( V_234 , & V_20 -> V_98 ) )
F_212 ( & V_428 , V_462 , 2 ,
V_20 -> V_86 ) ;
if ( V_20 -> V_10 -> V_304 & V_463 )
if ( V_20 -> V_82 == V_464 ||
F_67 ( V_465 , & V_20 -> V_80 ) ) {
V_20 -> V_82 = V_464 ;
F_212 ( & V_428 , V_466 , 1 ,
V_20 -> V_82 ) ;
}
break;
case V_143 :
F_222 ( V_20 ) ;
V_449 . V_136 = V_143 ;
V_449 . V_457 = 0 ;
V_449 . V_458 = 0 ;
V_449 . V_39 = 0 ;
V_449 . V_41 = 0 ;
V_51 = F_63 ( T_2 , V_461 , V_20 -> V_10 -> V_154 -
V_239 - V_394 -
V_244 ) ;
V_449 . V_459 = F_16 ( V_51 ) ;
F_212 ( & V_428 , V_460 , sizeof( V_449 ) ,
( unsigned long ) & V_449 ) ;
if ( F_67 ( V_455 , & V_20 -> V_98 ) )
F_213 ( & V_428 , V_20 ) ;
if ( V_20 -> V_10 -> V_304 & V_463 )
if ( V_20 -> V_82 == V_464 ||
F_67 ( V_465 , & V_20 -> V_80 ) ) {
V_20 -> V_82 = V_464 ;
F_212 ( & V_428 , V_466 , 1 ,
V_20 -> V_82 ) ;
}
break;
}
V_268 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_268 -> V_98 = F_16 ( 0 ) ;
return V_428 - V_184 ;
}
static int F_223 ( struct V_8 * V_20 , void * V_184 )
{
struct V_467 * V_148 = V_184 ;
void * V_428 = V_148 -> V_184 ;
void * V_268 = V_20 -> V_468 ;
int V_183 = V_20 -> V_469 ;
int type , V_470 , V_429 ;
unsigned long V_430 ;
struct V_448 V_449 = { . V_136 = V_137 } ;
struct V_434 V_435 ;
T_3 V_471 = 0 ;
T_2 V_154 = V_28 ;
T_2 V_149 = V_472 ;
T_2 V_51 ;
F_21 ( L_3 , V_20 ) ;
while ( V_183 >= V_433 ) {
V_183 -= F_211 ( & V_268 , & type , & V_429 , & V_430 ) ;
V_470 = type & V_473 ;
type &= V_474 ;
switch ( type ) {
case V_456 :
V_154 = V_430 ;
break;
case V_475 :
V_20 -> V_93 = V_430 ;
break;
case V_476 :
break;
case V_460 :
if ( V_429 == sizeof( V_449 ) )
memcpy ( & V_449 , ( void * ) V_430 , V_429 ) ;
break;
case V_466 :
if ( V_430 == V_464 )
F_54 ( V_465 , & V_20 -> V_80 ) ;
break;
case V_440 :
V_471 = 1 ;
if ( V_429 == sizeof( V_435 ) )
memcpy ( & V_435 , ( void * ) V_430 , V_429 ) ;
break;
case V_462 :
if ( ! V_20 -> V_10 -> V_258 )
return - V_67 ;
F_54 ( V_234 , & V_20 -> V_98 ) ;
F_54 ( V_477 , & V_20 -> V_80 ) ;
V_20 -> V_88 = V_452 ;
V_20 -> V_90 = V_430 ;
break;
default:
if ( V_470 )
break;
V_149 = V_478 ;
* ( ( T_3 * ) V_428 ++ ) = type ;
break;
}
}
if ( V_20 -> V_454 || V_20 -> V_324 > 1 )
goto V_24;
switch ( V_20 -> V_136 ) {
case V_143 :
case V_139 :
if ( ! F_67 ( V_314 , & V_20 -> V_80 ) ) {
V_20 -> V_136 = F_217 ( V_449 . V_136 ,
V_20 -> V_10 -> V_304 ) ;
break;
}
if ( V_471 ) {
if ( F_219 ( V_20 -> V_10 ) )
F_54 ( V_455 , & V_20 -> V_98 ) ;
else
return - V_67 ;
}
if ( V_20 -> V_136 != V_449 . V_136 )
return - V_67 ;
break;
}
V_24:
if ( V_20 -> V_136 != V_449 . V_136 ) {
V_149 = V_479 ;
V_449 . V_136 = V_20 -> V_136 ;
if ( V_20 -> V_454 == 1 )
return - V_67 ;
F_212 ( & V_428 , V_460 , sizeof( V_449 ) ,
( unsigned long ) & V_449 ) ;
}
if ( V_149 == V_472 ) {
if ( V_154 < V_480 )
V_149 = V_479 ;
else {
V_20 -> V_27 = V_154 ;
F_54 ( V_481 , & V_20 -> V_80 ) ;
}
F_212 ( & V_428 , V_456 , 2 , V_20 -> V_27 ) ;
if ( V_471 ) {
if ( V_20 -> V_118 != V_482 &&
V_435 . V_436 != V_482 &&
V_435 . V_436 != V_20 -> V_118 ) {
V_149 = V_479 ;
if ( V_20 -> V_324 >= 1 )
return - V_67 ;
F_212 ( & V_428 , V_440 ,
sizeof( V_435 ) ,
( unsigned long ) & V_435 ) ;
} else {
V_149 = V_483 ;
F_54 ( V_484 , & V_20 -> V_80 ) ;
}
}
switch ( V_449 . V_136 ) {
case V_137 :
V_20 -> V_82 = V_464 ;
F_54 ( V_485 , & V_20 -> V_80 ) ;
break;
case V_139 :
if ( ! F_67 ( V_477 , & V_20 -> V_80 ) )
V_20 -> V_90 = V_449 . V_457 ;
else
V_449 . V_457 = V_87 ;
V_20 -> V_89 = V_449 . V_458 ;
V_51 = F_63 ( T_2 , F_224 ( V_449 . V_459 ) ,
V_20 -> V_10 -> V_154 - V_239 -
V_394 - V_244 ) ;
V_449 . V_459 = F_16 ( V_51 ) ;
V_20 -> V_398 = V_51 ;
F_220 ( V_20 , & V_449 ) ;
F_54 ( V_485 , & V_20 -> V_80 ) ;
F_212 ( & V_428 , V_460 ,
sizeof( V_449 ) , ( unsigned long ) & V_449 ) ;
if ( F_67 ( V_455 , & V_20 -> V_98 ) ) {
V_20 -> V_486 = V_435 . V_179 ;
V_20 -> V_487 = V_435 . V_436 ;
V_20 -> V_488 = F_224 ( V_435 . V_437 ) ;
V_20 -> V_489 =
F_225 ( V_435 . V_93 ) ;
V_20 -> V_490 =
F_225 ( V_435 . V_439 ) ;
V_20 -> V_491 =
F_225 ( V_435 . V_438 ) ;
F_212 ( & V_428 , V_440 ,
sizeof( V_435 ) ,
( unsigned long ) & V_435 ) ;
}
break;
case V_143 :
V_51 = F_63 ( T_2 , F_224 ( V_449 . V_459 ) ,
V_20 -> V_10 -> V_154 - V_239 -
V_394 - V_244 ) ;
V_449 . V_459 = F_16 ( V_51 ) ;
V_20 -> V_398 = V_51 ;
F_54 ( V_485 , & V_20 -> V_80 ) ;
F_212 ( & V_428 , V_460 , sizeof( V_449 ) ,
( unsigned long ) & V_449 ) ;
break;
default:
V_149 = V_479 ;
memset ( & V_449 , 0 , sizeof( V_449 ) ) ;
V_449 . V_136 = V_20 -> V_136 ;
}
if ( V_149 == V_472 )
F_54 ( V_492 , & V_20 -> V_80 ) ;
}
V_148 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 -> V_149 = F_16 ( V_149 ) ;
V_148 -> V_98 = F_16 ( 0 ) ;
return V_428 - V_184 ;
}
static int F_226 ( struct V_8 * V_20 , void * V_148 , int V_183 ,
void * V_184 , T_2 * V_149 )
{
struct V_453 * V_268 = V_184 ;
void * V_428 = V_268 -> V_184 ;
int type , V_429 ;
unsigned long V_430 ;
struct V_448 V_449 = { . V_136 = V_137 } ;
struct V_434 V_435 ;
F_21 ( L_40 , V_20 , V_148 , V_183 , V_184 ) ;
while ( V_183 >= V_433 ) {
V_183 -= F_211 ( & V_148 , & type , & V_429 , & V_430 ) ;
switch ( type ) {
case V_456 :
if ( V_430 < V_480 ) {
* V_149 = V_479 ;
V_20 -> V_106 = V_480 ;
} else
V_20 -> V_106 = V_430 ;
F_212 ( & V_428 , V_456 , 2 , V_20 -> V_106 ) ;
break;
case V_475 :
V_20 -> V_93 = V_430 ;
F_212 ( & V_428 , V_475 ,
2 , V_20 -> V_93 ) ;
break;
case V_460 :
if ( V_429 == sizeof( V_449 ) )
memcpy ( & V_449 , ( void * ) V_430 , V_429 ) ;
if ( F_67 ( V_314 , & V_20 -> V_80 ) &&
V_449 . V_136 != V_20 -> V_136 )
return - V_67 ;
V_20 -> V_82 = 0 ;
F_212 ( & V_428 , V_460 ,
sizeof( V_449 ) , ( unsigned long ) & V_449 ) ;
break;
case V_462 :
V_20 -> V_91 = F_63 ( T_2 , V_430 , V_20 -> V_91 ) ;
F_212 ( & V_428 , V_462 , 2 ,
V_20 -> V_86 ) ;
break;
case V_440 :
if ( V_429 == sizeof( V_435 ) )
memcpy ( & V_435 , ( void * ) V_430 , V_429 ) ;
if ( V_20 -> V_118 != V_482 &&
V_435 . V_436 != V_482 &&
V_435 . V_436 != V_20 -> V_118 )
return - V_67 ;
F_212 ( & V_428 , V_440 , sizeof( V_435 ) ,
( unsigned long ) & V_435 ) ;
break;
case V_466 :
if ( * V_149 == V_483 )
if ( V_430 == V_464 )
F_54 ( V_465 ,
& V_20 -> V_80 ) ;
break;
}
}
if ( V_20 -> V_136 == V_137 && V_20 -> V_136 != V_449 . V_136 )
return - V_67 ;
V_20 -> V_136 = V_449 . V_136 ;
if ( * V_149 == V_472 || * V_149 == V_483 ) {
switch ( V_449 . V_136 ) {
case V_139 :
V_20 -> V_39 = F_224 ( V_449 . V_39 ) ;
V_20 -> V_41 = F_224 ( V_449 . V_41 ) ;
V_20 -> V_105 = F_224 ( V_449 . V_459 ) ;
if ( ! F_67 ( V_234 , & V_20 -> V_98 ) )
V_20 -> V_91 = F_63 ( T_2 , V_20 -> V_91 ,
V_449 . V_457 ) ;
if ( F_67 ( V_455 , & V_20 -> V_98 ) ) {
V_20 -> V_120 = F_224 ( V_435 . V_437 ) ;
V_20 -> V_122 =
F_225 ( V_435 . V_438 ) ;
V_20 -> V_124 = F_225 ( V_435 . V_439 ) ;
V_20 -> V_126 =
F_225 ( V_435 . V_93 ) ;
}
break;
case V_143 :
V_20 -> V_105 = F_224 ( V_449 . V_459 ) ;
}
}
V_268 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_268 -> V_98 = F_16 ( 0 ) ;
return V_428 - V_184 ;
}
static int F_227 ( struct V_8 * V_20 , void * V_184 ,
T_2 V_149 , T_2 V_98 )
{
struct V_467 * V_148 = V_184 ;
void * V_428 = V_148 -> V_184 ;
F_21 ( L_3 , V_20 ) ;
V_148 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 -> V_149 = F_16 ( V_149 ) ;
V_148 -> V_98 = F_16 ( V_98 ) ;
return V_428 - V_184 ;
}
void F_228 ( struct V_8 * V_20 )
{
struct V_147 V_148 ;
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_3 , V_20 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_154 = F_16 ( V_20 -> V_106 ) ;
V_148 . V_105 = F_16 ( V_20 -> V_105 ) ;
V_148 . V_155 = F_16 ( V_20 -> V_103 ) ;
V_148 . V_149 = F_16 ( V_320 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_156 , sizeof( V_148 ) ,
& V_148 ) ;
}
void F_229 ( struct V_8 * V_20 )
{
struct V_157 V_148 ;
struct V_9 * V_10 = V_20 -> V_10 ;
T_3 V_316 [ 128 ] ;
T_3 V_493 ;
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_149 = F_16 ( V_320 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
if ( V_20 -> V_196 )
V_493 = V_494 ;
else
V_493 = V_161 ;
F_21 ( L_41 , V_20 , V_493 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_493 , sizeof( V_148 ) , & V_148 ) ;
if ( F_129 ( V_322 , & V_20 -> V_80 ) )
return;
F_80 ( V_10 , F_88 ( V_10 ) , V_323 ,
F_139 ( V_20 , V_316 ) , V_316 ) ;
V_20 -> V_324 ++ ;
}
static void F_230 ( struct V_8 * V_20 , void * V_148 , int V_183 )
{
int type , V_429 ;
unsigned long V_430 ;
T_2 V_495 = V_20 -> V_91 ;
struct V_448 V_449 = {
. V_136 = V_20 -> V_136 ,
. V_39 = F_16 ( V_95 ) ,
. V_41 = F_16 ( V_96 ) ,
. V_459 = F_16 ( V_20 -> V_106 ) ,
. V_457 = F_63 ( T_2 , V_20 -> V_91 , V_87 ) ,
} ;
F_21 ( L_42 , V_20 , V_148 , V_183 ) ;
if ( ( V_20 -> V_136 != V_139 ) && ( V_20 -> V_136 != V_143 ) )
return;
while ( V_183 >= V_433 ) {
V_183 -= F_211 ( & V_148 , & type , & V_429 , & V_430 ) ;
switch ( type ) {
case V_460 :
if ( V_429 == sizeof( V_449 ) )
memcpy ( & V_449 , ( void * ) V_430 , V_429 ) ;
break;
case V_462 :
V_495 = V_430 ;
break;
}
}
switch ( V_449 . V_136 ) {
case V_139 :
V_20 -> V_39 = F_224 ( V_449 . V_39 ) ;
V_20 -> V_41 = F_224 ( V_449 . V_41 ) ;
V_20 -> V_105 = F_224 ( V_449 . V_459 ) ;
if ( F_67 ( V_234 , & V_20 -> V_98 ) )
V_20 -> V_91 = F_63 ( T_2 , V_20 -> V_91 , V_495 ) ;
else
V_20 -> V_91 = F_63 ( T_2 , V_20 -> V_91 ,
V_449 . V_457 ) ;
break;
case V_143 :
V_20 -> V_105 = F_224 ( V_449 . V_459 ) ;
}
}
static inline int F_231 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
struct V_497 * V_498 = (struct V_497 * ) V_184 ;
if ( V_496 < sizeof( * V_498 ) )
return - V_499 ;
if ( V_498 -> V_64 != V_500 )
return 0 ;
if ( ( V_10 -> V_296 & V_297 ) &&
V_424 -> V_16 == V_10 -> V_299 ) {
F_232 ( & V_10 -> V_300 ) ;
V_10 -> V_296 |= V_303 ;
V_10 -> V_299 = 0 ;
F_137 ( V_10 ) ;
}
return 0 ;
}
static struct V_8 * F_233 ( struct V_9 * V_10 ,
struct V_423 * V_424 ,
T_3 * V_184 , T_3 V_493 , T_3 V_270 )
{
struct V_267 * V_268 = (struct V_267 * ) V_184 ;
struct V_157 V_148 ;
struct V_8 * V_20 = NULL , * V_501 ;
int V_149 , V_159 = V_160 ;
T_2 V_13 = 0 , V_14 = F_66 ( V_268 -> V_14 ) ;
T_4 V_17 = V_268 -> V_17 ;
F_21 ( L_43 , F_66 ( V_17 ) , V_14 ) ;
V_501 = F_161 ( V_162 , V_17 , & V_10 -> V_2 -> V_18 ,
& V_10 -> V_2 -> V_145 , V_112 ) ;
if ( ! V_501 ) {
V_149 = V_152 ;
goto V_502;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_501 ) ;
if ( V_17 != F_16 ( V_174 ) &&
! F_234 ( V_10 -> V_2 ) ) {
V_10 -> V_109 = V_503 ;
V_149 = V_158 ;
goto V_504;
}
V_149 = V_505 ;
if ( F_2 ( V_10 , V_14 ) )
goto V_504;
V_20 = V_501 -> V_36 -> V_506 ( V_501 ) ;
if ( ! V_20 )
goto V_504;
V_10 -> V_2 -> V_357 = V_507 ;
F_78 ( & V_20 -> V_18 , & V_10 -> V_2 -> V_18 ) ;
F_78 ( & V_20 -> V_145 , & V_10 -> V_2 -> V_145 ) ;
V_20 -> V_361 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_361 ) ;
V_20 -> V_146 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_146 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_14 ;
V_20 -> V_442 = V_270 ;
F_65 ( V_10 , V_20 ) ;
V_13 = V_20 -> V_14 ;
F_82 ( V_20 , V_20 -> V_36 -> V_163 ( V_20 ) ) ;
V_20 -> V_16 = V_424 -> V_16 ;
if ( V_10 -> V_296 & V_303 ) {
if ( F_85 ( V_20 , false ) ) {
if ( F_67 ( V_150 , & V_20 -> V_98 ) ) {
F_20 ( V_20 , V_164 ) ;
V_149 = V_317 ;
V_159 = V_318 ;
V_20 -> V_36 -> V_319 ( V_20 ) ;
} else {
if ( V_270 == V_443 ) {
F_20 ( V_20 , V_66 ) ;
V_149 = V_320 ;
} else {
F_20 ( V_20 , V_164 ) ;
V_149 = V_317 ;
}
V_159 = V_160 ;
}
} else {
F_20 ( V_20 , V_164 ) ;
V_149 = V_317 ;
V_159 = V_321 ;
}
} else {
F_20 ( V_20 , V_164 ) ;
V_149 = V_317 ;
V_159 = V_160 ;
}
V_504:
F_46 ( V_501 ) ;
F_8 ( & V_10 -> V_15 ) ;
F_47 ( V_501 ) ;
V_502:
V_148 . V_14 = F_16 ( V_14 ) ;
V_148 . V_13 = F_16 ( V_13 ) ;
V_148 . V_149 = F_16 ( V_149 ) ;
V_148 . V_159 = F_16 ( V_159 ) ;
F_80 ( V_10 , V_424 -> V_16 , V_493 , sizeof( V_148 ) , & V_148 ) ;
if ( V_149 == V_317 && V_159 == V_160 ) {
struct V_295 V_508 ;
V_508 . type = F_16 ( V_298 ) ;
V_10 -> V_296 |= V_297 ;
V_10 -> V_299 = F_88 ( V_10 ) ;
F_134 ( & V_10 -> V_300 , V_301 ) ;
F_80 ( V_10 , V_10 -> V_299 , V_302 ,
sizeof( V_508 ) , & V_508 ) ;
}
if ( V_20 && ! F_67 ( V_322 , & V_20 -> V_80 ) &&
V_149 == V_320 ) {
T_3 V_316 [ 128 ] ;
F_54 ( V_322 , & V_20 -> V_80 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_323 ,
F_139 ( V_20 , V_316 ) , V_316 ) ;
V_20 -> V_324 ++ ;
}
return V_20 ;
}
static int F_235 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 , T_3 * V_184 )
{
struct V_256 * V_185 = V_10 -> V_2 -> V_185 ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_496 < sizeof( struct V_267 ) )
return - V_499 ;
F_146 ( V_185 ) ;
if ( F_67 ( V_509 , & V_185 -> V_510 ) &&
! F_129 ( V_511 , & V_2 -> V_98 ) )
F_236 ( V_185 , & V_2 -> V_145 , V_2 -> type ,
V_2 -> V_146 , 0 , NULL , 0 ,
V_2 -> V_512 ) ;
F_147 ( V_185 ) ;
F_233 ( V_10 , V_424 , V_184 , V_161 , 0 ) ;
return 0 ;
}
static int F_237 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
struct V_157 * V_148 = (struct V_157 * ) V_184 ;
T_2 V_14 , V_13 , V_149 , V_159 ;
struct V_8 * V_20 ;
T_3 V_268 [ 128 ] ;
int V_21 ;
if ( V_496 < sizeof( * V_148 ) )
return - V_499 ;
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
V_21 = - V_513 ;
goto V_514;
}
} else {
V_20 = F_10 ( V_10 , V_424 -> V_16 ) ;
if ( ! V_20 ) {
V_21 = - V_513 ;
goto V_514;
}
}
V_21 = 0 ;
F_7 ( V_20 ) ;
switch ( V_149 ) {
case V_320 :
F_20 ( V_20 , V_66 ) ;
V_20 -> V_16 = 0 ;
V_20 -> V_13 = V_13 ;
F_114 ( V_255 , & V_20 -> V_80 ) ;
if ( F_129 ( V_322 , & V_20 -> V_80 ) )
break;
F_80 ( V_10 , F_88 ( V_10 ) , V_323 ,
F_139 ( V_20 , V_268 ) , V_268 ) ;
V_20 -> V_324 ++ ;
break;
case V_317 :
F_54 ( V_255 , & V_20 -> V_80 ) ;
break;
default:
F_70 ( V_20 , V_67 ) ;
break;
}
F_46 ( V_20 ) ;
V_514:
F_8 ( & V_10 -> V_15 ) ;
return V_21 ;
}
static inline void F_238 ( struct V_8 * V_20 )
{
if ( V_20 -> V_136 != V_139 && V_20 -> V_136 != V_143 )
V_20 -> V_82 = V_464 ;
else if ( ! F_67 ( V_465 , & V_20 -> V_80 ) )
V_20 -> V_82 = V_83 ;
}
static void F_239 ( struct V_8 * V_20 , void * V_184 ,
T_3 V_16 , T_2 V_98 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_45 , V_10 , V_20 , V_16 ,
V_98 ) ;
F_114 ( V_484 , & V_20 -> V_80 ) ;
F_54 ( V_492 , & V_20 -> V_80 ) ;
F_80 ( V_10 , V_16 , V_515 ,
F_227 ( V_20 , V_184 ,
V_472 , V_98 ) , V_184 ) ;
}
static void F_240 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_14 , T_2 V_13 )
{
struct V_516 V_498 ;
V_498 . V_64 = F_16 ( V_517 ) ;
V_498 . V_14 = F_241 ( V_14 ) ;
V_498 . V_13 = F_241 ( V_13 ) ;
F_80 ( V_10 , V_16 , V_518 , sizeof( V_498 ) , & V_498 ) ;
}
static inline int F_242 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
struct V_453 * V_268 = (struct V_453 * ) V_184 ;
T_2 V_13 , V_98 ;
T_3 V_148 [ 64 ] ;
struct V_8 * V_20 ;
int V_183 , V_21 = 0 ;
if ( V_496 < sizeof( * V_268 ) )
return - V_499 ;
V_13 = F_66 ( V_268 -> V_13 ) ;
V_98 = F_66 ( V_268 -> V_98 ) ;
F_21 ( L_46 , V_13 , V_98 ) ;
V_20 = F_5 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_240 ( V_10 , V_424 -> V_16 , V_13 , 0 ) ;
return 0 ;
}
if ( V_20 -> V_35 != V_66 && V_20 -> V_35 != V_164 ) {
F_240 ( V_10 , V_424 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
goto V_514;
}
V_183 = V_496 - sizeof( * V_268 ) ;
if ( V_20 -> V_469 + V_183 > sizeof( V_20 -> V_468 ) ) {
F_80 ( V_10 , V_424 -> V_16 , V_515 ,
F_227 ( V_20 , V_148 ,
V_519 , V_98 ) , V_148 ) ;
goto V_514;
}
memcpy ( V_20 -> V_468 + V_20 -> V_469 , V_268 -> V_184 , V_183 ) ;
V_20 -> V_469 += V_183 ;
if ( V_98 & V_520 ) {
F_80 ( V_10 , V_424 -> V_16 , V_515 ,
F_227 ( V_20 , V_148 ,
V_472 , V_98 ) , V_148 ) ;
goto V_514;
}
V_183 = F_223 ( V_20 , V_148 ) ;
if ( V_183 < 0 ) {
F_83 ( V_20 , V_315 ) ;
goto V_514;
}
V_20 -> V_16 = V_424 -> V_16 ;
F_80 ( V_10 , V_424 -> V_16 , V_515 , V_183 , V_148 ) ;
V_20 -> V_454 ++ ;
V_20 -> V_469 = 0 ;
if ( ! F_67 ( V_492 , & V_20 -> V_80 ) )
goto V_514;
if ( F_67 ( V_521 , & V_20 -> V_80 ) ) {
F_238 ( V_20 ) ;
if ( V_20 -> V_136 == V_139 ||
V_20 -> V_136 == V_143 )
V_21 = F_216 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_127 ( V_20 ) ;
goto V_514;
}
if ( ! F_129 ( V_322 , & V_20 -> V_80 ) ) {
T_3 V_316 [ 64 ] ;
F_80 ( V_10 , F_88 ( V_10 ) , V_323 ,
F_139 ( V_20 , V_316 ) , V_316 ) ;
V_20 -> V_324 ++ ;
}
if ( F_67 ( V_522 , & V_20 -> V_80 ) &&
F_67 ( V_484 , & V_20 -> V_80 ) ) {
if ( ! V_20 -> V_196 )
F_239 ( V_20 , V_148 , V_424 -> V_16 , V_98 ) ;
else
V_20 -> V_16 = V_424 -> V_16 ;
}
V_514:
F_46 ( V_20 ) ;
return V_21 ;
}
static inline int F_243 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
struct V_467 * V_148 = (struct V_467 * ) V_184 ;
T_2 V_14 , V_98 , V_149 ;
struct V_8 * V_20 ;
int V_183 = V_496 - sizeof( * V_148 ) ;
int V_21 = 0 ;
if ( V_496 < sizeof( * V_148 ) )
return - V_499 ;
V_14 = F_66 ( V_148 -> V_14 ) ;
V_98 = F_66 ( V_148 -> V_98 ) ;
V_149 = F_66 ( V_148 -> V_149 ) ;
F_21 ( L_47 , V_14 , V_98 ,
V_149 , V_183 ) ;
V_20 = F_5 ( V_10 , V_14 ) ;
if ( ! V_20 )
return 0 ;
switch ( V_149 ) {
case V_472 :
F_230 ( V_20 , V_148 -> V_184 , V_183 ) ;
F_114 ( V_522 , & V_20 -> V_80 ) ;
break;
case V_483 :
F_54 ( V_522 , & V_20 -> V_80 ) ;
if ( F_67 ( V_484 , & V_20 -> V_80 ) ) {
char V_316 [ 64 ] ;
V_183 = F_226 ( V_20 , V_148 -> V_184 , V_183 ,
V_316 , & V_149 ) ;
if ( V_183 < 0 ) {
F_83 ( V_20 , V_315 ) ;
goto V_24;
}
if ( ! V_20 -> V_196 ) {
F_239 ( V_20 , V_316 , V_424 -> V_16 ,
0 ) ;
} else {
if ( F_121 ( V_20 ) ) {
F_244 ( V_20 ) ;
V_20 -> V_16 = V_424 -> V_16 ;
}
}
}
goto V_24;
case V_479 :
if ( V_20 -> V_454 <= V_523 ) {
char V_268 [ 64 ] ;
if ( V_183 > sizeof( V_268 ) - sizeof( struct V_453 ) ) {
F_83 ( V_20 , V_315 ) ;
goto V_24;
}
V_149 = V_472 ;
V_183 = F_226 ( V_20 , V_148 -> V_184 , V_183 ,
V_268 , & V_149 ) ;
if ( V_183 < 0 ) {
F_83 ( V_20 , V_315 ) ;
goto V_24;
}
F_80 ( V_10 , F_88 ( V_10 ) ,
V_323 , V_183 , V_268 ) ;
V_20 -> V_324 ++ ;
if ( V_149 != V_472 )
goto V_24;
break;
}
default:
F_24 ( V_20 , V_315 ) ;
F_82 ( V_20 , V_524 ) ;
F_83 ( V_20 , V_315 ) ;
goto V_24;
}
if ( V_98 & V_520 )
goto V_24;
F_54 ( V_521 , & V_20 -> V_80 ) ;
if ( F_67 ( V_492 , & V_20 -> V_80 ) ) {
F_238 ( V_20 ) ;
if ( V_20 -> V_136 == V_139 ||
V_20 -> V_136 == V_143 )
V_21 = F_216 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_127 ( V_20 ) ;
}
V_24:
F_46 ( V_20 ) ;
return V_21 ;
}
static inline int F_245 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
struct V_310 * V_268 = (struct V_310 * ) V_184 ;
struct V_525 V_148 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_496 != sizeof( * V_268 ) )
return - V_499 ;
V_14 = F_66 ( V_268 -> V_14 ) ;
V_13 = F_66 ( V_268 -> V_13 ) ;
F_21 ( L_48 , V_14 , V_13 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_4 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_8 ( & V_10 -> V_15 ) ;
F_240 ( V_10 , V_424 -> V_16 , V_13 , V_14 ) ;
return 0 ;
}
F_7 ( V_20 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
F_80 ( V_10 , V_424 -> V_16 , V_526 , sizeof( V_148 ) , & V_148 ) ;
V_20 -> V_36 -> V_527 ( V_20 ) ;
F_57 ( V_20 ) ;
F_70 ( V_20 , V_315 ) ;
F_46 ( V_20 ) ;
V_20 -> V_36 -> V_72 ( V_20 ) ;
F_47 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_246 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
struct V_525 * V_148 = (struct V_525 * ) V_184 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_496 != sizeof( * V_148 ) )
return - V_499 ;
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
F_70 ( V_20 , 0 ) ;
F_46 ( V_20 ) ;
V_20 -> V_36 -> V_72 ( V_20 ) ;
F_47 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_247 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
struct V_295 * V_268 = (struct V_295 * ) V_184 ;
T_2 type ;
if ( V_496 != sizeof( * V_268 ) )
return - V_499 ;
type = F_66 ( V_268 -> type ) ;
F_21 ( L_50 , type ) ;
if ( type == V_298 ) {
T_3 V_316 [ 8 ] ;
T_8 V_304 = V_306 ;
struct V_528 * V_148 = (struct V_528 * ) V_316 ;
V_148 -> type = F_16 ( V_298 ) ;
V_148 -> V_149 = F_16 ( V_529 ) ;
if ( ! V_307 )
V_304 |= V_308 | V_309
| V_463 ;
if ( V_10 -> V_258 )
V_304 |= V_447
| V_446 ;
F_104 ( V_304 , V_148 -> V_184 ) ;
F_80 ( V_10 , V_424 -> V_16 , V_530 , sizeof( V_316 ) ,
V_316 ) ;
} else if ( type == V_531 ) {
T_3 V_316 [ 12 ] ;
struct V_528 * V_148 = (struct V_528 * ) V_316 ;
if ( V_10 -> V_258 )
V_532 [ 0 ] |= V_260 ;
else
V_532 [ 0 ] &= ~ V_260 ;
V_148 -> type = F_16 ( V_531 ) ;
V_148 -> V_149 = F_16 ( V_529 ) ;
memcpy ( V_148 -> V_184 , V_532 , sizeof( V_532 ) ) ;
F_80 ( V_10 , V_424 -> V_16 , V_530 , sizeof( V_316 ) ,
V_316 ) ;
} else {
struct V_528 V_148 ;
V_148 . type = F_16 ( type ) ;
V_148 . V_149 = F_16 ( V_533 ) ;
F_80 ( V_10 , V_424 -> V_16 , V_530 , sizeof( V_148 ) ,
& V_148 ) ;
}
return 0 ;
}
static inline int F_248 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
struct V_528 * V_148 = (struct V_528 * ) V_184 ;
T_2 type , V_149 ;
if ( V_496 < sizeof( * V_148 ) )
return - V_499 ;
type = F_66 ( V_148 -> type ) ;
V_149 = F_66 ( V_148 -> V_149 ) ;
F_21 ( L_51 , type , V_149 ) ;
if ( V_424 -> V_16 != V_10 -> V_299 ||
V_10 -> V_296 & V_303 )
return 0 ;
F_232 ( & V_10 -> V_300 ) ;
if ( V_149 != V_529 ) {
V_10 -> V_296 |= V_303 ;
V_10 -> V_299 = 0 ;
F_137 ( V_10 ) ;
return 0 ;
}
switch ( type ) {
case V_298 :
V_10 -> V_304 = F_98 ( V_148 -> V_184 ) ;
if ( V_10 -> V_304 & V_534 ) {
struct V_295 V_268 ;
V_268 . type = F_16 ( V_531 ) ;
V_10 -> V_299 = F_88 ( V_10 ) ;
F_80 ( V_10 , V_10 -> V_299 ,
V_302 , sizeof( V_268 ) , & V_268 ) ;
} else {
V_10 -> V_296 |= V_303 ;
V_10 -> V_299 = 0 ;
F_137 ( V_10 ) ;
}
break;
case V_531 :
V_10 -> V_259 = V_148 -> V_184 [ 0 ] ;
V_10 -> V_296 |= V_303 ;
V_10 -> V_299 = 0 ;
F_137 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_249 ( struct V_9 * V_10 ,
struct V_423 * V_424 ,
T_2 V_496 , void * V_184 )
{
struct V_271 * V_268 = V_184 ;
struct V_535 V_148 ;
struct V_8 * V_20 ;
struct V_256 * V_185 ;
T_2 V_17 , V_14 ;
if ( V_496 != sizeof( * V_268 ) )
return - V_499 ;
if ( ! V_10 -> V_258 )
return - V_26 ;
V_17 = F_224 ( V_268 -> V_17 ) ;
V_14 = F_224 ( V_268 -> V_14 ) ;
F_21 ( L_52 , V_17 , V_14 , V_268 -> V_270 ) ;
if ( V_268 -> V_270 == V_443 ) {
F_233 ( V_10 , V_424 , V_184 , V_494 ,
V_268 -> V_270 ) ;
return 0 ;
}
V_185 = F_250 ( V_268 -> V_270 ) ;
if ( ! V_185 )
goto error;
if ( V_185 -> V_536 != V_537 || ! F_67 ( V_264 , & V_185 -> V_98 ) ) {
F_251 ( V_185 ) ;
goto error;
}
V_20 = F_233 ( V_10 , V_424 , V_184 , V_494 ,
V_268 -> V_270 ) ;
if ( V_20 ) {
struct V_131 * V_132 = V_10 -> V_2 -> V_131 ;
struct V_1 * V_196 ;
V_196 = F_252 ( V_185 , V_538 ,
& V_10 -> V_2 -> V_145 ) ;
if ( ! V_196 ) {
F_251 ( V_185 ) ;
F_240 ( V_10 , V_424 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
return 0 ;
}
F_21 ( L_53 , V_132 , V_20 , V_196 ) ;
V_132 -> V_133 = V_20 ;
V_20 -> V_196 = V_196 ;
V_20 -> V_82 = V_464 ;
V_10 -> V_154 = V_185 -> V_539 ;
}
F_251 ( V_185 ) ;
return 0 ;
error:
V_148 . V_13 = 0 ;
V_148 . V_14 = F_16 ( V_14 ) ;
V_148 . V_149 = F_16 ( V_540 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
F_80 ( V_10 , V_424 -> V_16 , V_494 ,
sizeof( V_148 ) , & V_148 ) ;
return 0 ;
}
static void F_253 ( struct V_8 * V_20 , T_3 V_541 )
{
struct V_542 V_268 ;
T_3 V_16 ;
F_21 ( L_54 , V_20 , V_541 ) ;
V_16 = F_88 ( V_20 -> V_10 ) ;
V_20 -> V_16 = V_16 ;
V_268 . V_543 = F_16 ( V_20 -> V_14 ) ;
V_268 . V_541 = V_541 ;
F_80 ( V_20 -> V_10 , V_16 , V_544 , sizeof( V_268 ) ,
& V_268 ) ;
F_82 ( V_20 , V_545 ) ;
}
static void F_254 ( struct V_8 * V_20 , T_2 V_149 )
{
struct V_546 V_148 ;
F_21 ( L_55 , V_20 , V_149 ) ;
V_148 . V_543 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_149 = F_16 ( V_149 ) ;
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_547 ,
sizeof( V_148 ) , & V_148 ) ;
}
static void F_255 ( struct V_8 * V_20 , T_2 V_149 )
{
struct V_548 V_549 ;
F_21 ( L_55 , V_20 , V_149 ) ;
V_20 -> V_16 = F_88 ( V_20 -> V_10 ) ;
V_549 . V_543 = F_16 ( V_20 -> V_14 ) ;
V_549 . V_149 = F_16 ( V_149 ) ;
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_550 ,
sizeof( V_549 ) , & V_549 ) ;
F_82 ( V_20 , V_545 ) ;
}
static void F_256 ( struct V_9 * V_10 , T_2 V_543 )
{
struct V_548 V_549 ;
F_21 ( L_56 , V_10 , V_543 ) ;
V_549 . V_543 = F_16 ( V_543 ) ;
V_549 . V_149 = F_16 ( V_551 ) ;
F_80 ( V_10 , F_88 ( V_10 ) , V_550 ,
sizeof( V_549 ) , & V_549 ) ;
}
static void F_257 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_543 )
{
struct V_552 V_148 ;
F_21 ( L_57 , V_543 ) ;
V_148 . V_543 = F_16 ( V_543 ) ;
F_80 ( V_10 , V_16 , V_553 , sizeof( V_148 ) , & V_148 ) ;
}
static void F_258 ( struct V_8 * V_20 )
{
V_20 -> V_134 = NULL ;
V_20 -> V_196 = NULL ;
}
static void F_259 ( struct V_8 * V_20 )
{
if ( V_20 -> V_35 != V_65 ) {
F_83 ( V_20 , V_315 ) ;
return;
}
switch ( V_20 -> V_283 ) {
case V_288 :
F_125 ( V_20 ) ;
F_254 ( V_20 , V_554 ) ;
break;
case V_285 :
if ( V_20 -> V_193 == V_555 ||
V_20 -> V_193 == V_556 ) {
F_125 ( V_20 ) ;
}
F_255 ( V_20 , V_551 ) ;
break;
}
}
static void F_260 ( struct V_8 * V_20 ,
struct V_135 * V_192 )
{
struct V_467 V_148 ;
V_20 -> V_134 = V_192 ;
V_20 -> V_196 -> V_353 = V_20 -> V_10 ;
F_239 ( V_20 , & V_148 , V_20 -> V_16 , 0 ) ;
if ( F_67 ( V_521 , & V_20 -> V_80 ) ) {
int V_21 ;
F_238 ( V_20 ) ;
V_21 = F_216 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_127 ( V_20 ) ;
}
}
static void F_261 ( struct V_8 * V_20 ,
struct V_135 * V_192 )
{
V_20 -> V_196 = V_192 -> V_10 ;
V_20 -> V_196 -> V_353 = V_20 -> V_10 ;
F_21 ( L_58 , V_20 -> V_193 ) ;
switch ( V_20 -> V_193 ) {
case V_555 :
V_20 -> V_193 = V_557 ;
break;
case V_556 :
if ( F_67 ( V_253 , & V_20 -> V_247 ) ) {
V_20 -> V_193 = V_558 ;
} else if ( V_20 -> V_283 == V_285 ) {
V_20 -> V_193 = V_559 ;
F_255 ( V_20 , V_560 ) ;
} else if ( V_20 -> V_283 == V_288 ) {
V_20 -> V_193 = V_561 ;
F_254 ( V_20 , V_562 ) ;
}
break;
default:
F_258 ( V_20 ) ;
V_20 -> V_193 = V_194 ;
}
}
void F_262 ( struct V_8 * V_20 , struct V_135 * V_192 ,
T_3 V_159 )
{
F_21 ( L_59 , V_20 , V_192 , V_159 ) ;
if ( V_159 ) {
F_259 ( V_20 ) ;
F_258 ( V_20 ) ;
return;
}
if ( V_20 -> V_35 != V_65 ) {
if ( V_20 -> V_442 != V_443 )
F_260 ( V_20 , V_192 ) ;
} else {
F_261 ( V_20 , V_192 ) ;
}
}
void F_263 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_442 == V_443 ) {
if ( V_20 -> V_265 != V_266 )
return;
V_20 -> V_283 = V_285 ;
V_20 -> V_193 = V_195 ;
} else {
V_20 -> V_283 = V_285 ;
V_20 -> V_193 = V_557 ;
V_20 -> V_444 = 0 ;
F_124 ( V_20 ) ;
F_253 ( V_20 , 0 ) ;
}
}
static void F_264 ( struct V_8 * V_20 , int V_149 ,
T_3 V_442 , T_3 V_563 )
{
F_21 ( L_60 , V_20 , F_22 ( V_20 -> V_35 ) ,
V_442 , V_563 ) ;
V_20 -> V_82 = V_464 ;
if ( V_20 -> V_35 == V_68 ) {
if ( V_149 == V_320 ) {
V_20 -> V_442 = V_442 ;
F_123 ( V_20 , V_563 ) ;
} else {
F_122 ( V_20 ) ;
}
return;
}
if ( F_117 ( V_20 ) ) {
struct V_157 V_148 ;
char V_316 [ 128 ] ;
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( V_149 == V_320 ) {
V_148 . V_149 = F_16 ( V_320 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
} else {
V_148 . V_149 = F_16 ( V_505 ) ;
V_148 . V_159 = F_16 ( V_160 ) ;
}
F_80 ( V_20 -> V_10 , V_20 -> V_16 , V_494 ,
sizeof( V_148 ) , & V_148 ) ;
if ( V_149 == V_320 ) {
F_20 ( V_20 , V_66 ) ;
F_54 ( V_322 , & V_20 -> V_80 ) ;
F_80 ( V_20 -> V_10 , F_88 ( V_20 -> V_10 ) ,
V_323 ,
F_139 ( V_20 , V_316 ) , V_316 ) ;
V_20 -> V_324 ++ ;
}
}
}
static void F_265 ( struct V_8 * V_20 , T_3 V_442 ,
T_3 V_563 )
{
F_124 ( V_20 ) ;
V_20 -> V_444 = V_442 ;
V_20 -> V_193 = V_564 ;
F_253 ( V_20 , V_563 ) ;
}
static void F_266 ( struct V_8 * V_20 , int V_149 )
{
struct V_135 * V_192 = NULL ;
if ( V_192 ) {
if ( V_192 -> V_35 == V_65 ) {
V_20 -> V_196 = V_192 -> V_10 ;
V_20 -> V_196 -> V_353 = V_20 -> V_10 ;
V_20 -> V_193 = V_561 ;
F_254 ( V_20 , V_562 ) ;
F_262 ( V_20 , V_192 , V_562 ) ;
} else {
V_20 -> V_193 = V_556 ;
}
} else {
F_254 ( V_20 , V_565 ) ;
}
}
static void F_267 ( struct V_8 * V_20 , int V_149 )
{
if ( V_20 -> V_283 == V_288 ) {
T_3 V_566 ;
if ( V_149 == - V_26 )
V_566 = V_567 ;
else
V_566 = V_565 ;
F_254 ( V_20 , V_566 ) ;
}
V_20 -> V_283 = V_284 ;
V_20 -> V_193 = V_194 ;
F_169 ( V_20 ) ;
}
void F_268 ( struct V_8 * V_20 , int V_149 )
{
T_3 V_442 = V_20 -> V_442 ;
T_3 V_563 = V_20 -> V_563 ;
F_21 ( L_61 ,
V_20 , V_149 , V_442 , V_563 ) ;
if ( V_20 -> V_35 == V_153 || V_20 -> V_35 == V_568 ) {
F_46 ( V_20 ) ;
return;
}
if ( V_20 -> V_35 != V_65 ) {
F_264 ( V_20 , V_149 , V_442 , V_563 ) ;
} else if ( V_149 != V_562 ) {
F_267 ( V_20 , V_149 ) ;
} else {
switch ( V_20 -> V_283 ) {
case V_285 :
F_265 ( V_20 , V_442 ,
V_563 ) ;
break;
case V_288 :
F_266 ( V_20 , V_149 ) ;
break;
default:
F_267 ( V_20 , V_149 ) ;
break;
}
}
}
static inline int F_269 ( struct V_9 * V_10 ,
struct V_423 * V_424 ,
T_2 V_496 , void * V_184 )
{
struct V_542 * V_268 = V_184 ;
struct V_546 V_148 ;
struct V_8 * V_20 ;
T_2 V_543 = 0 ;
T_2 V_149 = V_565 ;
if ( V_496 != sizeof( * V_268 ) )
return - V_499 ;
V_543 = F_224 ( V_268 -> V_543 ) ;
F_21 ( L_62 , V_543 , V_268 -> V_541 ) ;
if ( ! V_10 -> V_258 )
return - V_26 ;
V_20 = F_9 ( V_10 , V_543 ) ;
if ( ! V_20 ) {
V_148 . V_543 = F_16 ( V_543 ) ;
V_148 . V_149 = F_16 ( V_565 ) ;
F_80 ( V_10 , V_424 -> V_16 , V_547 ,
sizeof( V_148 ) , & V_148 ) ;
return 0 ;
}
V_20 -> V_16 = V_424 -> V_16 ;
if ( V_20 -> V_14 < V_34 ||
V_20 -> V_265 == V_569 ||
( V_20 -> V_136 != V_139 &&
V_20 -> V_136 != V_143 ) ) {
V_149 = V_565 ;
goto V_570;
}
if ( V_20 -> V_442 == V_268 -> V_541 ) {
V_149 = V_571 ;
goto V_570;
}
if ( V_268 -> V_541 != V_443 ) {
struct V_256 * V_185 ;
V_185 = F_250 ( V_268 -> V_541 ) ;
if ( ! V_185 || V_185 -> V_536 != V_537 ||
! F_67 ( V_264 , & V_185 -> V_98 ) ) {
if ( V_185 )
F_251 ( V_185 ) ;
V_149 = V_567 ;
goto V_570;
}
F_251 ( V_185 ) ;
}
if ( ( F_92 ( V_20 ) ||
V_20 -> V_283 != V_284 ) &&
F_13 ( & V_10 -> V_2 -> V_18 , & V_10 -> V_2 -> V_145 ) > 0 ) {
V_149 = V_572 ;
goto V_570;
}
V_20 -> V_283 = V_288 ;
F_124 ( V_20 ) ;
V_20 -> V_444 = V_268 -> V_541 ;
V_543 = V_20 -> V_13 ;
if ( V_268 -> V_541 == V_443 ) {
if ( F_67 ( V_253 , & V_20 -> V_247 ) ) {
V_20 -> V_193 = V_558 ;
V_149 = V_573 ;
} else {
V_20 -> V_193 = V_561 ;
V_149 = V_562 ;
}
} else {
V_20 -> V_193 = V_195 ;
V_149 = V_573 ;
}
V_570:
F_254 ( V_20 , V_149 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static void F_270 ( struct V_9 * V_10 , T_2 V_543 , T_2 V_149 )
{
struct V_8 * V_20 ;
struct V_135 * V_192 = NULL ;
V_20 = F_5 ( V_10 , V_543 ) ;
if ( ! V_20 ) {
F_256 ( V_10 , V_543 ) ;
return;
}
F_71 ( V_20 ) ;
if ( V_149 == V_573 )
F_82 ( V_20 , V_574 ) ;
switch ( V_20 -> V_193 ) {
case V_555 :
V_20 -> V_193 = V_556 ;
break;
case V_557 :
if ( V_149 == V_573 ) {
break;
} else if ( F_67 ( V_253 ,
& V_20 -> V_247 ) ) {
V_20 -> V_193 = V_558 ;
} else {
V_20 -> V_193 = V_559 ;
F_255 ( V_20 , V_560 ) ;
}
break;
case V_564 :
if ( V_149 == V_562 ) {
V_20 -> V_193 = V_556 ;
} else {
V_20 -> V_193 = V_555 ;
}
if ( ! V_192 ) {
F_255 ( V_20 , V_551 ) ;
break;
}
if ( V_192 -> V_35 != V_65 )
break;
V_20 -> V_196 = V_192 -> V_10 ;
V_20 -> V_196 -> V_353 = V_20 -> V_10 ;
if ( V_149 == V_562 ) {
F_255 ( V_20 , V_560 ) ;
} else {
V_20 -> V_193 = V_557 ;
}
F_262 ( V_20 , V_192 , V_562 ) ;
break;
default:
V_20 -> V_444 = V_20 -> V_442 ;
F_125 ( V_20 ) ;
F_255 ( V_20 , V_551 ) ;
}
F_46 ( V_20 ) ;
}
static void F_271 ( struct V_9 * V_10 , T_3 V_16 , T_2 V_543 ,
T_2 V_149 )
{
struct V_8 * V_20 ;
V_20 = F_11 ( V_10 , V_16 ) ;
if ( ! V_20 ) {
F_256 ( V_10 , V_543 ) ;
return;
}
F_71 ( V_20 ) ;
if ( V_20 -> V_283 == V_285 ) {
if ( V_149 == V_572 ) {
V_20 -> V_283 = V_288 ;
} else {
V_20 -> V_444 = V_20 -> V_442 ;
F_125 ( V_20 ) ;
}
}
F_255 ( V_20 , V_551 ) ;
F_46 ( V_20 ) ;
}
static int F_272 ( struct V_9 * V_10 ,
struct V_423 * V_424 ,
T_2 V_496 , void * V_184 )
{
struct V_546 * V_148 = V_184 ;
T_2 V_543 , V_149 ;
if ( V_496 != sizeof( * V_148 ) )
return - V_499 ;
V_543 = F_224 ( V_148 -> V_543 ) ;
V_149 = F_224 ( V_148 -> V_149 ) ;
F_21 ( L_63 , V_543 , V_149 ) ;
if ( V_149 == V_562 || V_149 == V_573 )
F_270 ( V_10 , V_543 , V_149 ) ;
else
F_271 ( V_10 , V_424 -> V_16 , V_543 , V_149 ) ;
return 0 ;
}
static int F_273 ( struct V_9 * V_10 ,
struct V_423 * V_424 ,
T_2 V_496 , void * V_184 )
{
struct V_548 * V_549 = V_184 ;
struct V_8 * V_20 ;
T_2 V_543 , V_149 ;
if ( V_496 != sizeof( * V_549 ) )
return - V_499 ;
V_543 = F_224 ( V_549 -> V_543 ) ;
V_149 = F_224 ( V_549 -> V_149 ) ;
F_21 ( L_63 , V_543 , V_149 ) ;
V_20 = F_9 ( V_10 , V_543 ) ;
if ( ! V_20 ) {
F_257 ( V_10 , V_424 -> V_16 , V_543 ) ;
return 0 ;
}
if ( V_20 -> V_193 == V_561 ) {
if ( V_149 == V_560 ) {
V_20 -> V_442 = V_20 -> V_444 ;
if ( V_20 -> V_442 == V_443 )
F_258 ( V_20 ) ;
} else {
V_20 -> V_444 = V_20 -> V_442 ;
}
F_125 ( V_20 ) ;
}
F_257 ( V_10 , V_424 -> V_16 , V_543 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static inline int F_274 ( struct V_9 * V_10 ,
struct V_423 * V_424 ,
T_2 V_496 , void * V_184 )
{
struct V_552 * V_148 = V_184 ;
struct V_8 * V_20 ;
T_2 V_543 ;
if ( V_496 != sizeof( * V_148 ) )
return - V_499 ;
V_543 = F_224 ( V_148 -> V_543 ) ;
F_21 ( L_57 , V_543 ) ;
V_20 = F_5 ( V_10 , V_543 ) ;
if ( ! V_20 )
return 0 ;
F_71 ( V_20 ) ;
if ( V_20 -> V_193 == V_559 ) {
V_20 -> V_442 = V_20 -> V_444 ;
if ( V_20 -> V_442 == V_443 && V_20 -> V_134 )
F_258 ( V_20 ) ;
F_125 ( V_20 ) ;
}
F_46 ( V_20 ) ;
return 0 ;
}
static inline int V_333 ( struct V_9 * V_10 ,
struct V_423 * V_424 ,
T_2 V_496 , T_3 * V_184 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_333 * V_268 ;
struct V_575 V_148 ;
T_2 V_334 , V_335 , V_336 , V_338 ;
int V_21 ;
if ( V_2 -> V_328 != V_576 )
return - V_26 ;
if ( V_496 != sizeof( struct V_333 ) )
return - V_499 ;
V_268 = (struct V_333 * ) V_184 ;
V_334 = F_66 ( V_268 -> V_334 ) ;
V_335 = F_66 ( V_268 -> V_335 ) ;
V_336 = F_66 ( V_268 -> V_336 ) ;
V_338 = F_66 ( V_268 -> V_338 ) ;
F_21 ( L_64 ,
V_334 , V_335 , V_336 , V_338 ) ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_21 = F_275 ( V_334 , V_335 , V_336 , V_338 ) ;
if ( V_21 )
V_148 . V_149 = F_16 ( V_577 ) ;
else
V_148 . V_149 = F_16 ( V_578 ) ;
F_80 ( V_10 , V_424 -> V_16 , V_579 ,
sizeof( V_148 ) , & V_148 ) ;
if ( ! V_21 ) {
T_3 V_580 ;
V_580 = F_276 ( V_2 , V_334 , V_335 , V_336 ,
V_338 ) ;
F_277 ( V_2 -> V_185 , & V_2 -> V_145 , V_2 -> V_146 ,
V_580 , V_334 , V_335 , V_336 ,
V_338 ) ;
}
return 0 ;
}
static int F_278 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
struct V_147 * V_148 = (struct V_147 * ) V_184 ;
T_2 V_13 , V_154 , V_105 , V_155 , V_149 ;
struct V_8 * V_20 ;
int V_21 ;
if ( V_496 < sizeof( * V_148 ) )
return - V_499 ;
V_13 = F_66 ( V_148 -> V_13 ) ;
V_154 = F_66 ( V_148 -> V_154 ) ;
V_105 = F_66 ( V_148 -> V_105 ) ;
V_155 = F_66 ( V_148 -> V_155 ) ;
V_149 = F_66 ( V_148 -> V_149 ) ;
if ( V_149 == V_320 && ( V_154 < 23 || V_105 < 23 ) )
return - V_499 ;
F_21 ( L_65 ,
V_13 , V_154 , V_105 , V_155 , V_149 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_10 ( V_10 , V_424 -> V_16 ) ;
if ( ! V_20 ) {
V_21 = - V_513 ;
goto V_514;
}
V_21 = 0 ;
F_7 ( V_20 ) ;
switch ( V_149 ) {
case V_320 :
V_20 -> V_16 = 0 ;
V_20 -> V_13 = V_13 ;
V_20 -> V_27 = V_154 ;
V_20 -> V_398 = V_105 ;
V_20 -> V_102 = V_155 ;
F_127 ( V_20 ) ;
break;
default:
F_70 ( V_20 , V_67 ) ;
break;
}
F_46 ( V_20 ) ;
V_514:
F_8 ( & V_10 -> V_15 ) ;
return V_21 ;
}
static inline int F_279 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
int V_21 = 0 ;
switch ( V_424 -> V_182 ) {
case V_518 :
F_231 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_269 :
V_21 = F_235 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_161 :
case V_494 :
F_237 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_323 :
V_21 = F_242 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_515 :
F_243 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_312 :
V_21 = F_245 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_526 :
F_246 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_581 :
F_80 ( V_10 , V_424 -> V_16 , V_582 , V_496 , V_184 ) ;
break;
case V_582 :
break;
case V_302 :
V_21 = F_247 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_530 :
F_248 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_272 :
V_21 = F_249 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_544 :
V_21 = F_269 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_547 :
F_272 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_550 :
V_21 = F_273 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_553 :
F_274 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
default:
F_280 ( L_66 , V_424 -> V_182 ) ;
V_21 = - V_26 ;
break;
}
return V_21 ;
}
static int F_281 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
struct V_292 * V_268 = (struct V_292 * ) V_184 ;
struct V_147 V_148 ;
struct V_8 * V_20 , * V_501 ;
T_2 V_13 , V_14 , V_155 , V_154 , V_105 ;
T_4 V_17 ;
T_3 V_149 ;
if ( V_496 != sizeof( * V_268 ) )
return - V_499 ;
V_14 = F_66 ( V_268 -> V_14 ) ;
V_154 = F_66 ( V_268 -> V_154 ) ;
V_105 = F_66 ( V_268 -> V_105 ) ;
V_17 = V_268 -> V_17 ;
V_13 = 0 ;
V_155 = 0 ;
if ( V_154 < 23 || V_105 < 23 )
return - V_499 ;
F_21 ( L_67 , F_66 ( V_17 ) ,
V_14 , V_154 , V_105 ) ;
V_501 = F_161 ( V_162 , V_17 , & V_10 -> V_2 -> V_18 ,
& V_10 -> V_2 -> V_145 , V_3 ) ;
if ( ! V_501 ) {
V_149 = V_152 ;
V_20 = NULL ;
goto V_504;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_501 ) ;
if ( ! F_282 ( V_10 -> V_2 , V_501 -> V_69 ) ) {
V_149 = V_583 ;
V_20 = NULL ;
goto V_584;
}
if ( F_2 ( V_10 , V_14 ) ) {
V_149 = V_505 ;
V_20 = NULL ;
goto V_584;
}
V_20 = V_501 -> V_36 -> V_506 ( V_501 ) ;
if ( ! V_20 ) {
V_149 = V_505 ;
goto V_584;
}
F_62 ( V_20 ) ;
F_78 ( & V_20 -> V_18 , & V_10 -> V_2 -> V_18 ) ;
F_78 ( & V_20 -> V_145 , & V_10 -> V_2 -> V_145 ) ;
V_20 -> V_361 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_361 ) ;
V_20 -> V_146 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_146 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_14 ;
V_20 -> V_27 = V_154 ;
V_20 -> V_398 = V_105 ;
V_20 -> V_102 = F_66 ( V_268 -> V_155 ) ;
F_65 ( V_10 , V_20 ) ;
V_13 = V_20 -> V_14 ;
V_155 = V_20 -> V_103 ;
F_82 ( V_20 , V_20 -> V_36 -> V_163 ( V_20 ) ) ;
V_20 -> V_16 = V_424 -> V_16 ;
if ( F_67 ( V_150 , & V_20 -> V_98 ) ) {
F_20 ( V_20 , V_164 ) ;
V_149 = V_317 ;
V_20 -> V_36 -> V_319 ( V_20 ) ;
} else {
F_127 ( V_20 ) ;
V_149 = V_320 ;
}
V_584:
F_46 ( V_501 ) ;
F_8 ( & V_10 -> V_15 ) ;
F_47 ( V_501 ) ;
if ( V_149 == V_317 )
return 0 ;
V_504:
if ( V_20 ) {
V_148 . V_154 = F_16 ( V_20 -> V_106 ) ;
V_148 . V_105 = F_16 ( V_20 -> V_105 ) ;
} else {
V_148 . V_154 = 0 ;
V_148 . V_105 = 0 ;
}
V_148 . V_13 = F_16 ( V_13 ) ;
V_148 . V_155 = F_16 ( V_155 ) ;
V_148 . V_149 = F_16 ( V_149 ) ;
F_80 ( V_10 , V_424 -> V_16 , V_156 , sizeof( V_148 ) , & V_148 ) ;
return 0 ;
}
static inline int F_283 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
struct F_283 * V_585 ;
struct V_8 * V_20 ;
T_2 V_11 , V_155 , V_586 ;
if ( V_496 != sizeof( * V_585 ) )
return - V_499 ;
V_585 = (struct F_283 * ) V_184 ;
V_11 = F_66 ( V_585 -> V_11 ) ;
V_155 = F_66 ( V_585 -> V_155 ) ;
F_21 ( L_68 , V_11 , V_155 ) ;
V_20 = F_9 ( V_10 , V_11 ) ;
if ( ! V_20 )
return - V_513 ;
V_586 = V_587 - V_20 -> V_102 ;
if ( V_155 > V_586 ) {
F_280 ( L_69 ) ;
F_83 ( V_20 , V_315 ) ;
return 0 ;
}
V_20 -> V_102 += V_155 ;
while ( V_20 -> V_102 && ! F_166 ( & V_20 -> V_108 ) ) {
F_93 ( V_20 , F_167 ( & V_20 -> V_108 ) ) ;
V_20 -> V_102 -- ;
}
if ( V_20 -> V_102 )
V_20 -> V_36 -> V_588 ( V_20 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static inline int F_284 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
struct V_497 * V_498 = (struct V_497 * ) V_184 ;
struct V_8 * V_20 ;
if ( V_496 < sizeof( * V_498 ) )
return - V_499 ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_10 ( V_10 , V_424 -> V_16 ) ;
if ( ! V_20 )
goto V_24;
F_7 ( V_20 ) ;
F_70 ( V_20 , V_67 ) ;
F_46 ( V_20 ) ;
V_24:
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_285 ( struct V_9 * V_10 ,
struct V_423 * V_424 , T_2 V_496 ,
T_3 * V_184 )
{
int V_21 = 0 ;
switch ( V_424 -> V_182 ) {
case V_518 :
F_284 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_340 :
V_21 = V_333 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_579 :
break;
case V_156 :
F_278 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_294 :
V_21 = F_281 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_589 :
V_21 = F_283 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_312 :
V_21 = F_245 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
case V_526 :
F_246 ( V_10 , V_424 , V_496 , V_184 ) ;
break;
default:
F_280 ( L_70 , V_424 -> V_182 ) ;
V_21 = - V_26 ;
break;
}
return V_21 ;
}
static inline void F_286 ( struct V_9 * V_10 ,
struct V_42 * V_46 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_423 * V_424 ;
T_2 V_183 ;
int V_21 ;
if ( V_2 -> type != V_3 )
goto V_590;
if ( V_46 -> V_183 < V_425 )
goto V_590;
V_424 = ( void * ) V_46 -> V_184 ;
F_99 ( V_46 , V_425 ) ;
V_183 = F_224 ( V_424 -> V_183 ) ;
F_21 ( L_71 , V_424 -> V_182 , V_183 , V_424 -> V_16 ) ;
if ( V_183 != V_46 -> V_183 || ! V_424 -> V_16 ) {
F_21 ( L_72 ) ;
goto V_590;
}
V_21 = F_285 ( V_10 , V_424 , V_183 , V_46 -> V_184 ) ;
if ( V_21 ) {
struct V_497 V_498 ;
F_280 ( L_73 , V_21 ) ;
V_498 . V_64 = F_16 ( V_500 ) ;
F_80 ( V_10 , V_424 -> V_16 , V_518 ,
sizeof( V_498 ) , & V_498 ) ;
}
V_590:
F_94 ( V_46 ) ;
}
static inline void F_287 ( struct V_9 * V_10 ,
struct V_42 * V_46 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 * V_184 = V_46 -> V_184 ;
int V_183 = V_46 -> V_183 ;
struct V_423 V_424 ;
int V_21 ;
F_210 ( V_10 , V_46 ) ;
if ( V_2 -> type != V_112 )
goto V_590;
while ( V_183 >= V_425 ) {
T_2 V_496 ;
memcpy ( & V_424 , V_184 , V_425 ) ;
V_184 += V_425 ;
V_183 -= V_425 ;
V_496 = F_224 ( V_424 . V_183 ) ;
F_21 ( L_71 , V_424 . V_182 , V_496 ,
V_424 . V_16 ) ;
if ( V_496 > V_183 || ! V_424 . V_16 ) {
F_21 ( L_72 ) ;
break;
}
V_21 = F_279 ( V_10 , & V_424 , V_496 , V_184 ) ;
if ( V_21 ) {
struct V_497 V_498 ;
F_280 ( L_73 , V_21 ) ;
V_498 . V_64 = F_16 ( V_500 ) ;
F_80 ( V_10 , V_424 . V_16 , V_518 ,
sizeof( V_498 ) , & V_498 ) ;
}
V_184 += V_496 ;
V_183 -= V_496 ;
}
V_590:
F_94 ( V_46 ) ;
}
static int F_288 ( struct V_8 * V_20 , struct V_42 * V_46 )
{
T_2 V_591 , V_592 ;
int V_593 ;
if ( F_67 ( V_234 , & V_20 -> V_98 ) )
V_593 = V_239 ;
else
V_593 = V_240 ;
if ( V_20 -> V_82 == V_83 ) {
F_289 ( V_46 , V_46 -> V_183 - V_244 ) ;
V_592 = F_100 ( V_46 -> V_184 + V_46 -> V_183 ) ;
V_591 = F_111 ( 0 , V_46 -> V_184 - V_593 , V_46 -> V_183 + V_593 ) ;
if ( V_591 != V_592 )
return - V_594 ;
}
return 0 ;
}
static void F_290 ( struct V_8 * V_20 )
{
struct V_200 V_47 ;
F_21 ( L_3 , V_20 ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_208 = 1 ;
V_47 . V_204 = 1 ;
V_47 . V_201 = V_20 -> V_254 ;
F_54 ( V_246 , & V_20 -> V_247 ) ;
if ( F_67 ( V_253 , & V_20 -> V_247 ) ) {
V_47 . V_212 = V_250 ;
F_112 ( V_20 , & V_47 ) ;
}
if ( F_113 ( V_282 , & V_20 -> V_247 ) &&
V_20 -> V_376 > 0 )
F_25 ( V_20 ) ;
F_169 ( V_20 ) ;
if ( ! F_67 ( V_253 , & V_20 -> V_247 ) &&
F_67 ( V_246 , & V_20 -> V_247 ) ) {
V_47 . V_212 = V_248 ;
F_112 ( V_20 , & V_47 ) ;
}
}
static void F_291 ( struct V_42 * V_46 , struct V_42 * V_595 ,
struct V_42 * * V_596 )
{
if ( ! F_292 ( V_46 ) )
F_185 ( V_46 ) -> V_387 = V_595 ;
V_595 -> V_347 = NULL ;
( * V_596 ) -> V_347 = V_595 ;
* V_596 = V_595 ;
V_46 -> V_183 += V_595 -> V_183 ;
V_46 -> V_391 += V_595 -> V_183 ;
V_46 -> V_597 += V_595 -> V_597 ;
}
static int F_293 ( struct V_8 * V_20 , struct V_42 * V_46 ,
struct V_200 * V_47 )
{
int V_21 = - V_26 ;
switch ( V_47 -> V_215 ) {
case V_399 :
if ( V_20 -> V_99 )
break;
V_21 = V_20 -> V_36 -> V_421 ( V_20 , V_46 ) ;
break;
case V_400 :
if ( V_20 -> V_99 )
break;
V_20 -> V_101 = F_100 ( V_46 -> V_184 ) ;
F_99 ( V_46 , V_394 ) ;
if ( V_20 -> V_101 > V_20 -> V_106 ) {
V_21 = - V_403 ;
break;
}
if ( V_46 -> V_183 >= V_20 -> V_101 )
break;
V_20 -> V_99 = V_46 ;
V_20 -> V_100 = V_46 ;
V_46 = NULL ;
V_21 = 0 ;
break;
case V_402 :
if ( ! V_20 -> V_99 )
break;
F_291 ( V_20 -> V_99 , V_46 ,
& V_20 -> V_100 ) ;
V_46 = NULL ;
if ( V_20 -> V_99 -> V_183 >= V_20 -> V_101 )
break;
V_21 = 0 ;
break;
case V_401 :
if ( ! V_20 -> V_99 )
break;
F_291 ( V_20 -> V_99 , V_46 ,
& V_20 -> V_100 ) ;
V_46 = NULL ;
if ( V_20 -> V_99 -> V_183 != V_20 -> V_101 )
break;
V_21 = V_20 -> V_36 -> V_421 ( V_20 , V_20 -> V_99 ) ;
if ( ! V_21 ) {
V_20 -> V_99 = NULL ;
V_20 -> V_100 = NULL ;
V_20 -> V_101 = 0 ;
}
break;
}
if ( V_21 ) {
F_94 ( V_46 ) ;
F_94 ( V_20 -> V_99 ) ;
V_20 -> V_99 = NULL ;
V_20 -> V_100 = NULL ;
V_20 -> V_101 = 0 ;
}
return V_21 ;
}
static int F_294 ( struct V_8 * V_20 )
{
return 0 ;
}
void F_295 ( struct V_8 * V_20 , int V_598 )
{
T_3 V_411 ;
if ( V_20 -> V_136 != V_139 )
return;
V_411 = V_598 ? V_412 : V_414 ;
F_126 ( V_20 , NULL , NULL , V_411 ) ;
}
static int F_296 ( struct V_8 * V_20 )
{
int V_21 = 0 ;
F_21 ( L_3 , V_20 ) ;
while ( ! F_67 ( V_253 , & V_20 -> V_247 ) ) {
struct V_42 * V_46 ;
F_21 ( L_74 ,
V_20 -> V_254 , F_173 ( & V_20 -> V_140 ) ) ;
V_46 = F_31 ( & V_20 -> V_140 , V_20 -> V_254 ) ;
if ( ! V_46 )
break;
F_203 ( V_46 , & V_20 -> V_140 ) ;
V_20 -> V_254 = F_168 ( V_20 , V_20 -> V_254 ) ;
V_21 = F_293 ( V_20 , V_46 , & F_33 ( V_46 ) -> V_47 ) ;
if ( V_21 )
break;
}
if ( F_166 ( & V_20 -> V_140 ) ) {
V_20 -> V_280 = V_379 ;
F_181 ( V_20 ) ;
}
return V_21 ;
}
static void F_297 ( struct V_8 * V_20 ,
struct V_200 * V_47 )
{
struct V_42 * V_46 ;
F_21 ( L_10 , V_20 , V_47 ) ;
if ( V_47 -> V_201 == V_20 -> V_370 ) {
F_21 ( L_75 , V_47 -> V_201 ) ;
F_83 ( V_20 , V_315 ) ;
return;
}
V_46 = F_31 ( & V_20 -> V_108 , V_47 -> V_201 ) ;
if ( V_46 == NULL ) {
F_21 ( L_76 ,
V_47 -> V_201 ) ;
return;
}
if ( V_20 -> V_84 != 0 && F_33 ( V_46 ) -> V_47 . V_274 >= V_20 -> V_84 ) {
F_21 ( L_21 , V_20 -> V_84 ) ;
F_83 ( V_20 , V_315 ) ;
return;
}
F_114 ( V_282 , & V_20 -> V_247 ) ;
if ( V_47 -> V_209 ) {
F_208 ( V_20 , V_47 ) ;
F_54 ( V_246 , & V_20 -> V_247 ) ;
F_178 ( V_20 , V_47 ) ;
F_169 ( V_20 ) ;
if ( V_20 -> V_278 == V_416 ) {
F_54 ( V_277 , & V_20 -> V_247 ) ;
V_20 -> V_599 = V_47 -> V_201 ;
}
} else {
F_209 ( V_20 , V_47 ) ;
if ( V_47 -> V_204 ) {
if ( V_20 -> V_599 != V_47 -> V_201 ||
! F_113 ( V_277 ,
& V_20 -> V_247 ) )
F_178 ( V_20 , V_47 ) ;
} else {
F_178 ( V_20 , V_47 ) ;
if ( V_20 -> V_278 == V_416 ) {
F_54 ( V_277 , & V_20 -> V_247 ) ;
V_20 -> V_599 = V_47 -> V_201 ;
}
}
}
}
static void F_298 ( struct V_8 * V_20 ,
struct V_200 * V_47 )
{
struct V_42 * V_46 ;
F_21 ( L_10 , V_20 , V_47 ) ;
if ( V_47 -> V_201 == V_20 -> V_370 ) {
F_21 ( L_75 , V_47 -> V_201 ) ;
F_83 ( V_20 , V_315 ) ;
return;
}
V_46 = F_31 ( & V_20 -> V_108 , V_47 -> V_201 ) ;
if ( V_20 -> V_84 && V_46 &&
F_33 ( V_46 ) -> V_47 . V_274 >= V_20 -> V_84 ) {
F_21 ( L_21 , V_20 -> V_84 ) ;
F_83 ( V_20 , V_315 ) ;
return;
}
F_114 ( V_282 , & V_20 -> V_247 ) ;
F_208 ( V_20 , V_47 ) ;
if ( V_47 -> V_204 ) {
if ( ! F_113 ( V_276 , & V_20 -> V_247 ) )
F_179 ( V_20 , V_47 ) ;
} else {
F_179 ( V_20 , V_47 ) ;
F_169 ( V_20 ) ;
if ( V_20 -> V_278 == V_416 )
F_54 ( V_276 , & V_20 -> V_247 ) ;
}
}
static T_3 F_299 ( struct V_8 * V_20 , T_2 V_48 )
{
F_21 ( L_77 , V_20 , V_48 ) ;
F_21 ( L_78 , V_20 -> V_252 ,
V_20 -> V_275 ) ;
if ( V_20 -> V_280 == V_413 ) {
if ( F_182 ( V_20 , V_48 , V_20 -> V_252 ) >=
V_20 -> V_86 ) {
if ( V_20 -> V_86 <= ( ( V_20 -> V_88 + 1 ) >> 1 ) ) {
F_21 ( L_79 ) ;
return V_600 ;
} else {
F_21 ( L_80 ) ;
return V_601 ;
}
}
if ( V_20 -> V_141 . V_44 == V_48 ) {
F_21 ( L_81 ) ;
return V_602 ;
}
if ( F_31 ( & V_20 -> V_140 , V_48 ) ) {
F_21 ( L_82 ) ;
return V_603 ;
}
if ( F_39 ( & V_20 -> V_141 , V_48 ) ) {
F_21 ( L_83 ) ;
return V_604 ;
}
}
if ( V_20 -> V_275 == V_48 ) {
if ( F_182 ( V_20 , V_48 , V_20 -> V_252 ) >=
V_20 -> V_86 ) {
F_21 ( L_84 ) ;
return V_601 ;
} else {
F_21 ( L_85 ) ;
return V_605 ;
}
}
if ( F_182 ( V_20 , V_48 , V_20 -> V_252 ) <
F_182 ( V_20 , V_20 -> V_275 , V_20 -> V_252 ) ) {
F_21 ( L_86 ) ;
return V_606 ;
}
if ( F_182 ( V_20 , V_48 , V_20 -> V_252 ) >= V_20 -> V_86 ) {
if ( V_20 -> V_86 <= ( ( V_20 -> V_88 + 1 ) >> 1 ) ) {
F_21 ( L_87 ) ;
return V_600 ;
} else {
F_21 ( L_84 ) ;
return V_601 ;
}
} else {
F_21 ( L_88 ) ;
return V_607 ;
}
}
static int F_300 ( struct V_8 * V_20 ,
struct V_200 * V_47 ,
struct V_42 * V_46 , T_3 V_411 )
{
int V_21 = 0 ;
bool V_608 = false ;
F_21 ( L_89 , V_20 , V_47 , V_46 ,
V_411 ) ;
switch ( V_411 ) {
case V_609 :
switch ( F_299 ( V_20 , V_47 -> V_48 ) ) {
case V_605 :
F_208 ( V_20 , V_47 ) ;
if ( F_67 ( V_253 , & V_20 -> V_247 ) ) {
F_21 ( L_90 ,
V_47 -> V_48 ) ;
break;
}
V_20 -> V_275 = F_168 ( V_20 ,
V_47 -> V_48 ) ;
V_20 -> V_254 = V_20 -> V_275 ;
V_608 = true ;
V_21 = F_293 ( V_20 , V_46 , V_47 ) ;
if ( V_21 )
break;
if ( V_47 -> V_204 ) {
if ( ! F_113 ( V_276 ,
& V_20 -> V_247 ) ) {
V_47 -> V_204 = 0 ;
F_179 ( V_20 , V_47 ) ;
F_169 ( V_20 ) ;
}
}
if ( ! F_67 ( V_253 , & V_20 -> V_247 ) )
F_181 ( V_20 ) ;
break;
case V_607 :
F_208 ( V_20 , V_47 ) ;
if ( F_67 ( V_253 , & V_20 -> V_247 ) ) {
F_21 ( L_91 ,
V_47 -> V_48 ) ;
break;
}
F_301 ( & V_20 -> V_140 , V_46 ) ;
V_608 = true ;
F_21 ( L_92 , V_46 ,
F_173 ( & V_20 -> V_140 ) ) ;
F_114 ( V_277 , & V_20 -> V_247 ) ;
F_41 ( & V_20 -> V_141 ) ;
F_199 ( V_20 , V_47 -> V_48 ) ;
V_20 -> V_280 = V_413 ;
break;
case V_606 :
F_208 ( V_20 , V_47 ) ;
break;
case V_600 :
break;
case V_601 :
default:
F_83 ( V_20 , V_315 ) ;
break;
}
break;
case V_610 :
F_208 ( V_20 , V_47 ) ;
if ( V_47 -> V_204 ) {
F_114 ( V_282 , & V_20 -> V_247 ) ;
if ( ! F_113 ( V_276 , & V_20 -> V_247 ) &&
! F_92 ( V_20 ) ) {
V_47 -> V_204 = 0 ;
F_179 ( V_20 , V_47 ) ;
}
F_169 ( V_20 ) ;
} else if ( V_47 -> V_209 ) {
F_290 ( V_20 ) ;
} else {
if ( F_113 ( V_282 ,
& V_20 -> V_247 ) &&
V_20 -> V_376 )
F_25 ( V_20 ) ;
F_169 ( V_20 ) ;
}
break;
case V_611 :
F_54 ( V_282 , & V_20 -> V_247 ) ;
F_208 ( V_20 , V_47 ) ;
if ( V_47 && V_47 -> V_209 ) {
F_54 ( V_246 , & V_20 -> V_247 ) ;
F_116 ( V_20 , 0 ) ;
}
F_30 ( V_20 ) ;
F_41 ( & V_20 -> V_142 ) ;
break;
case V_612 :
F_298 ( V_20 , V_47 ) ;
break;
case V_613 :
F_297 ( V_20 , V_47 ) ;
break;
default:
break;
}
if ( V_46 && ! V_608 ) {
F_21 ( L_93 , V_46 ) ;
F_94 ( V_46 ) ;
}
return V_21 ;
}
static int F_302 ( struct V_8 * V_20 ,
struct V_200 * V_47 ,
struct V_42 * V_46 , T_3 V_411 )
{
int V_21 = 0 ;
T_2 V_48 = V_47 -> V_48 ;
bool V_608 = false ;
F_21 ( L_89 , V_20 , V_47 , V_46 ,
V_411 ) ;
switch ( V_411 ) {
case V_609 :
switch ( F_299 ( V_20 , V_48 ) ) {
case V_605 :
F_208 ( V_20 , V_47 ) ;
F_301 ( & V_20 -> V_140 , V_46 ) ;
V_608 = true ;
F_21 ( L_92 , V_46 ,
F_173 ( & V_20 -> V_140 ) ) ;
V_20 -> V_275 = F_168 ( V_20 , V_48 ) ;
break;
case V_602 :
F_40 ( & V_20 -> V_141 ) ;
F_208 ( V_20 , V_47 ) ;
F_301 ( & V_20 -> V_140 , V_46 ) ;
V_608 = true ;
F_21 ( L_92 , V_46 ,
F_173 ( & V_20 -> V_140 ) ) ;
V_21 = F_296 ( V_20 ) ;
if ( V_21 )
break;
break;
case V_607 :
F_301 ( & V_20 -> V_140 , V_46 ) ;
V_608 = true ;
F_21 ( L_92 , V_46 ,
F_173 ( & V_20 -> V_140 ) ) ;
F_208 ( V_20 , V_47 ) ;
F_199 ( V_20 , V_47 -> V_48 ) ;
break;
case V_604 :
F_301 ( & V_20 -> V_140 , V_46 ) ;
V_608 = true ;
F_21 ( L_92 , V_46 ,
F_173 ( & V_20 -> V_140 ) ) ;
F_208 ( V_20 , V_47 ) ;
F_201 ( V_20 , V_47 -> V_48 ) ;
break;
case V_603 :
F_208 ( V_20 , V_47 ) ;
break;
case V_606 :
break;
case V_600 :
break;
case V_601 :
default:
F_83 ( V_20 , V_315 ) ;
break;
}
break;
case V_610 :
F_208 ( V_20 , V_47 ) ;
if ( V_47 -> V_204 ) {
F_114 ( V_282 , & V_20 -> V_247 ) ;
if ( ! F_113 ( V_276 ,
& V_20 -> V_247 ) ) {
V_47 -> V_204 = 0 ;
F_179 ( V_20 , V_47 ) ;
}
F_169 ( V_20 ) ;
} else if ( V_47 -> V_209 ) {
if ( F_113 ( V_282 ,
& V_20 -> V_247 ) &&
V_20 -> V_376 ) {
F_25 ( V_20 ) ;
}
F_54 ( V_246 , & V_20 -> V_247 ) ;
F_200 ( V_20 ) ;
} else {
if ( F_113 ( V_282 ,
& V_20 -> V_247 ) &&
V_20 -> V_376 )
F_25 ( V_20 ) ;
F_181 ( V_20 ) ;
}
break;
case V_611 :
F_54 ( V_282 , & V_20 -> V_247 ) ;
F_208 ( V_20 , V_47 ) ;
if ( V_47 -> V_209 ) {
F_200 ( V_20 ) ;
} else {
struct V_200 V_614 ;
memset ( & V_614 , 0 , sizeof( V_614 ) ) ;
V_614 . V_208 = 1 ;
V_614 . V_212 = V_248 ;
V_614 . V_201 = V_20 -> V_254 ;
F_112 ( V_20 , & V_614 ) ;
}
break;
case V_612 :
F_298 ( V_20 , V_47 ) ;
break;
case V_613 :
F_297 ( V_20 , V_47 ) ;
break;
}
if ( V_46 && ! V_608 ) {
F_21 ( L_93 , V_46 ) ;
F_94 ( V_46 ) ;
}
return V_21 ;
}
static int F_303 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_280 = V_379 ;
if ( V_20 -> V_196 )
V_20 -> V_10 -> V_154 = V_20 -> V_196 -> V_185 -> V_539 ;
else
V_20 -> V_10 -> V_154 = V_20 -> V_10 -> V_2 -> V_185 -> V_615 ;
return F_294 ( V_20 ) ;
}
static int F_304 ( struct V_8 * V_20 ,
struct V_200 * V_47 ,
struct V_42 * V_46 , T_3 V_411 )
{
int V_21 ;
F_21 ( L_89 , V_20 , V_47 , V_46 ,
V_411 ) ;
if ( ! V_47 -> V_209 )
return - V_499 ;
F_202 ( V_20 , V_47 -> V_201 ) ;
if ( ! F_166 ( & V_20 -> V_108 ) )
V_20 -> V_375 = F_206 ( & V_20 -> V_108 ) ;
else
V_20 -> V_375 = NULL ;
V_20 -> V_370 = V_47 -> V_201 ;
V_20 -> V_376 = 0 ;
V_21 = F_303 ( V_20 ) ;
if ( V_21 )
return V_21 ;
F_54 ( V_246 , & V_20 -> V_247 ) ;
F_290 ( V_20 ) ;
if ( V_411 == V_609 )
return - V_499 ;
return F_300 ( V_20 , V_47 , NULL , V_411 ) ;
}
static int F_305 ( struct V_8 * V_20 ,
struct V_200 * V_47 ,
struct V_42 * V_46 , T_3 V_411 )
{
int V_21 ;
if ( ! V_47 -> V_204 )
return - V_499 ;
F_114 ( V_282 , & V_20 -> V_247 ) ;
V_20 -> V_280 = V_379 ;
F_202 ( V_20 , V_47 -> V_201 ) ;
if ( ! F_166 ( & V_20 -> V_108 ) )
V_20 -> V_375 = F_206 ( & V_20 -> V_108 ) ;
else
V_20 -> V_375 = NULL ;
V_20 -> V_370 = V_47 -> V_201 ;
V_20 -> V_376 = 0 ;
if ( V_20 -> V_196 )
V_20 -> V_10 -> V_154 = V_20 -> V_196 -> V_185 -> V_539 ;
else
V_20 -> V_10 -> V_154 = V_20 -> V_10 -> V_2 -> V_185 -> V_615 ;
V_21 = F_294 ( V_20 ) ;
if ( ! V_21 )
V_21 = F_300 ( V_20 , V_47 , V_46 , V_411 ) ;
return V_21 ;
}
static bool F_306 ( struct V_8 * V_20 , T_2 V_201 )
{
T_2 V_616 ;
V_616 = F_182 ( V_20 , V_20 -> V_370 , V_20 -> V_410 ) ;
return F_182 ( V_20 , V_20 -> V_370 , V_201 ) <= V_616 ;
}
static int F_307 ( struct V_8 * V_20 , struct V_200 * V_47 ,
struct V_42 * V_46 , T_3 V_411 )
{
int V_21 = 0 ;
F_21 ( L_94 , V_20 ,
V_47 , V_46 , V_411 , V_20 -> V_280 ) ;
if ( F_306 ( V_20 , V_47 -> V_201 ) ) {
switch ( V_20 -> V_280 ) {
case V_379 :
V_21 = F_300 ( V_20 , V_47 , V_46 , V_411 ) ;
break;
case V_413 :
V_21 = F_302 ( V_20 , V_47 , V_46 ,
V_411 ) ;
break;
case V_289 :
V_21 = F_304 ( V_20 , V_47 , V_46 , V_411 ) ;
break;
case V_287 :
V_21 = F_305 ( V_20 , V_47 , V_46 , V_411 ) ;
break;
default:
break;
}
} else {
F_21 ( L_95 ,
V_47 -> V_201 , V_20 -> V_370 ,
V_20 -> V_410 ) ;
F_83 ( V_20 , V_315 ) ;
}
return V_21 ;
}
static int F_308 ( struct V_8 * V_20 , struct V_200 * V_47 ,
struct V_42 * V_46 )
{
int V_21 = 0 ;
F_21 ( L_96 , V_20 , V_47 , V_46 ,
V_20 -> V_280 ) ;
if ( F_299 ( V_20 , V_47 -> V_48 ) ==
V_605 ) {
F_208 ( V_20 , V_47 ) ;
F_21 ( L_97 , V_20 -> V_254 ,
F_168 ( V_20 , V_20 -> V_254 ) ) ;
V_20 -> V_254 = F_168 ( V_20 , V_20 -> V_254 ) ;
F_293 ( V_20 , V_46 , V_47 ) ;
} else {
if ( V_20 -> V_99 ) {
F_94 ( V_20 -> V_99 ) ;
V_20 -> V_99 = NULL ;
}
V_20 -> V_100 = NULL ;
V_20 -> V_101 = 0 ;
if ( V_46 ) {
F_21 ( L_93 , V_46 ) ;
F_94 ( V_46 ) ;
}
}
V_20 -> V_252 = V_47 -> V_48 ;
V_20 -> V_275 = F_168 ( V_20 , V_47 -> V_48 ) ;
return V_21 ;
}
static int F_309 ( struct V_8 * V_20 , struct V_42 * V_46 )
{
struct V_200 * V_47 = & F_33 ( V_46 ) -> V_47 ;
T_2 V_183 ;
T_3 V_411 ;
F_97 ( V_20 , V_46 ) ;
V_183 = V_46 -> V_183 ;
if ( F_288 ( V_20 , V_46 ) )
goto V_590;
if ( ! V_47 -> V_208 && V_47 -> V_215 == V_400 )
V_183 -= V_394 ;
if ( V_20 -> V_82 == V_83 )
V_183 -= V_244 ;
if ( V_183 > V_20 -> V_105 ) {
F_83 ( V_20 , V_315 ) ;
goto V_590;
}
if ( ! V_47 -> V_208 ) {
int V_21 ;
F_21 ( L_98 ,
V_47 -> V_215 , V_47 -> V_201 , V_47 -> V_204 ,
V_47 -> V_48 ) ;
if ( V_47 -> V_204 && V_20 -> V_278 != V_416 )
goto V_590;
if ( V_20 -> V_136 != V_143 ) {
V_411 = V_609 ;
V_21 = F_307 ( V_20 , V_47 , V_46 , V_411 ) ;
} else {
V_21 = F_308 ( V_20 , V_47 , V_46 ) ;
}
if ( V_21 )
F_83 ( V_20 , V_315 ) ;
} else {
const T_3 V_617 [ 4 ] = {
V_610 , V_612 ,
V_611 , V_613
} ;
if ( V_20 -> V_136 == V_143 )
goto V_590;
F_21 ( L_99 ,
V_47 -> V_201 , V_47 -> V_204 , V_47 -> V_209 ,
V_47 -> V_212 ) ;
if ( V_183 != 0 ) {
F_280 ( L_100 , V_183 ) ;
F_83 ( V_20 , V_315 ) ;
goto V_590;
}
if ( V_47 -> V_204 && ( V_47 -> V_209 ||
V_20 -> V_278 != V_416 ) )
goto V_590;
V_411 = V_617 [ V_47 -> V_212 ] ;
if ( F_307 ( V_20 , V_47 , V_46 , V_411 ) )
F_83 ( V_20 , V_315 ) ;
}
return 0 ;
V_590:
F_94 ( V_46 ) ;
return 0 ;
}
static void F_310 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct F_283 V_585 ;
T_2 V_618 ;
if ( V_20 -> V_103 >= ( V_104 + 1 ) / 2 )
return;
V_618 = V_104 - V_20 -> V_103 ;
F_21 ( L_101 , V_20 , V_618 ) ;
V_20 -> V_103 += V_618 ;
V_585 . V_11 = F_16 ( V_20 -> V_14 ) ;
V_585 . V_155 = F_16 ( V_618 ) ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_589 , sizeof( V_585 ) , & V_585 ) ;
}
static int F_311 ( struct V_8 * V_20 , struct V_42 * V_46 )
{
int V_21 ;
if ( ! V_20 -> V_103 ) {
F_280 ( L_102 ) ;
F_83 ( V_20 , V_315 ) ;
return - V_619 ;
}
if ( V_20 -> V_106 < V_46 -> V_183 ) {
F_280 ( L_103 ) ;
return - V_619 ;
}
V_20 -> V_103 -- ;
F_21 ( L_104 , V_20 -> V_103 + 1 , V_20 -> V_103 ) ;
F_310 ( V_20 ) ;
V_21 = 0 ;
if ( ! V_20 -> V_99 ) {
T_2 V_101 ;
V_101 = F_100 ( V_46 -> V_184 ) ;
F_99 ( V_46 , V_394 ) ;
F_21 ( L_105 ,
V_101 , V_46 -> V_183 , V_20 -> V_106 ) ;
if ( V_101 > V_20 -> V_106 ) {
F_280 ( L_106 ) ;
V_21 = - V_403 ;
goto V_620;
}
if ( V_46 -> V_183 > V_101 ) {
F_280 ( L_107 ) ;
V_21 = - V_26 ;
goto V_620;
}
if ( V_46 -> V_183 == V_101 )
return V_20 -> V_36 -> V_421 ( V_20 , V_46 ) ;
V_20 -> V_99 = V_46 ;
V_20 -> V_101 = V_101 ;
V_20 -> V_100 = V_46 ;
return 0 ;
}
F_21 ( L_108 ,
V_20 -> V_99 -> V_183 , V_46 -> V_183 , V_20 -> V_101 ) ;
if ( V_20 -> V_99 -> V_183 + V_46 -> V_183 > V_20 -> V_101 ) {
F_280 ( L_107 ) ;
V_21 = - V_26 ;
goto V_620;
}
F_291 ( V_20 -> V_99 , V_46 , & V_20 -> V_100 ) ;
V_46 = NULL ;
if ( V_20 -> V_99 -> V_183 == V_20 -> V_101 ) {
V_21 = V_20 -> V_36 -> V_421 ( V_20 , V_20 -> V_99 ) ;
if ( ! V_21 ) {
V_20 -> V_99 = NULL ;
V_20 -> V_100 = NULL ;
V_20 -> V_101 = 0 ;
}
}
V_620:
if ( V_21 ) {
F_94 ( V_46 ) ;
F_94 ( V_20 -> V_99 ) ;
V_20 -> V_99 = NULL ;
V_20 -> V_100 = NULL ;
V_20 -> V_101 = 0 ;
}
return 0 ;
}
static void F_312 ( struct V_9 * V_10 , T_2 V_11 ,
struct V_42 * V_46 )
{
struct V_8 * V_20 ;
V_20 = F_5 ( V_10 , V_11 ) ;
if ( ! V_20 ) {
if ( V_11 == V_311 ) {
V_20 = F_313 ( V_10 , V_46 ) ;
if ( ! V_20 ) {
F_94 ( V_46 ) ;
return;
}
F_7 ( V_20 ) ;
} else {
F_21 ( L_109 , V_11 ) ;
F_94 ( V_46 ) ;
return;
}
}
F_21 ( L_110 , V_20 , V_46 -> V_183 ) ;
if ( V_20 -> V_35 != V_65 )
goto V_590;
switch ( V_20 -> V_136 ) {
case V_138 :
if ( F_311 ( V_20 , V_46 ) < 0 )
goto V_590;
goto V_24;
case V_137 :
if ( V_20 -> V_106 < V_46 -> V_183 ) {
F_280 ( L_111 ) ;
goto V_590;
}
if ( ! V_20 -> V_36 -> V_421 ( V_20 , V_46 ) )
goto V_24;
break;
case V_139 :
case V_143 :
F_309 ( V_20 , V_46 ) ;
goto V_24;
default:
F_21 ( L_112 , V_20 , V_20 -> V_136 ) ;
break;
}
V_590:
F_94 ( V_46 ) ;
V_24:
F_46 ( V_20 ) ;
}
static void F_314 ( struct V_9 * V_10 , T_4 V_17 ,
struct V_42 * V_46 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 ;
if ( V_2 -> type != V_112 )
goto V_621;
V_20 = F_161 ( 0 , V_17 , & V_2 -> V_18 , & V_2 -> V_145 ,
V_112 ) ;
if ( ! V_20 )
goto V_621;
F_21 ( L_110 , V_20 , V_46 -> V_183 ) ;
if ( V_20 -> V_35 != V_622 && V_20 -> V_35 != V_65 )
goto V_590;
if ( V_20 -> V_106 < V_46 -> V_183 )
goto V_590;
F_78 ( & F_33 ( V_46 ) -> V_623 , & V_2 -> V_145 ) ;
F_33 ( V_46 ) -> V_17 = V_17 ;
if ( ! V_20 -> V_36 -> V_421 ( V_20 , V_46 ) ) {
F_47 ( V_20 ) ;
return;
}
V_590:
F_47 ( V_20 ) ;
V_621:
F_94 ( V_46 ) ;
}
static void F_315 ( struct V_9 * V_10 , struct V_42 * V_46 )
{
struct V_241 * V_242 = ( void * ) V_46 -> V_184 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_11 , V_183 ;
T_4 V_17 ;
if ( V_2 -> V_35 != V_65 ) {
F_21 ( L_113 ) ;
F_301 ( & V_10 -> V_356 , V_46 ) ;
return;
}
F_99 ( V_46 , V_238 ) ;
V_11 = F_66 ( V_242 -> V_11 ) ;
V_183 = F_66 ( V_242 -> V_183 ) ;
if ( V_183 != V_46 -> V_183 ) {
F_94 ( V_46 ) ;
return;
}
if ( V_2 -> type == V_3 &&
F_316 ( & V_2 -> V_185 -> V_624 , & V_2 -> V_145 ,
F_1 ( V_2 , V_2 -> V_146 ) ) ) {
F_94 ( V_46 ) ;
return;
}
F_21 ( L_114 , V_183 , V_11 ) ;
switch ( V_11 ) {
case V_115 :
F_287 ( V_10 , V_46 ) ;
break;
case V_114 :
V_17 = F_317 ( ( T_4 * ) V_46 -> V_184 ) ;
F_99 ( V_46 , V_392 ) ;
F_314 ( V_10 , V_17 , V_46 ) ;
break;
case V_426 :
F_286 ( V_10 , V_46 ) ;
break;
default:
F_312 ( V_10 , V_11 , V_46 ) ;
break;
}
}
static void F_318 ( struct V_61 * V_62 )
{
struct V_9 * V_10 = F_44 ( V_62 , struct V_9 ,
V_342 ) ;
struct V_42 * V_46 ;
F_21 ( L_115 ) ;
while ( ( V_46 = F_167 ( & V_10 -> V_356 ) ) )
F_315 ( V_10 , V_46 ) ;
}
static struct V_9 * F_319 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_353 ;
struct V_135 * V_192 ;
if ( V_10 )
return V_10 ;
V_192 = F_320 ( V_2 ) ;
if ( ! V_192 )
return NULL ;
V_10 = F_49 ( sizeof( * V_10 ) , V_55 ) ;
if ( ! V_10 ) {
F_155 ( V_192 ) ;
return NULL ;
}
F_53 ( & V_10 -> V_358 ) ;
V_2 -> V_353 = V_10 ;
V_10 -> V_2 = F_321 ( V_2 ) ;
V_10 -> V_192 = V_192 ;
F_21 ( L_116 , V_2 , V_10 , V_192 ) ;
switch ( V_2 -> type ) {
case V_3 :
if ( V_2 -> V_185 -> V_625 ) {
V_10 -> V_154 = V_2 -> V_185 -> V_625 ;
break;
}
default:
V_10 -> V_154 = V_2 -> V_185 -> V_615 ;
break;
}
V_10 -> V_304 = 0 ;
if ( V_2 -> type == V_112 )
V_10 -> V_258 = F_67 ( V_626 ,
& V_2 -> V_185 -> V_510 ) ;
F_50 ( & V_10 -> V_180 ) ;
F_50 ( & V_10 -> V_15 ) ;
F_322 ( & V_10 -> V_129 ) ;
F_322 ( & V_10 -> V_352 ) ;
F_52 ( & V_10 -> V_300 , F_144 ) ;
F_64 ( & V_10 -> V_356 ) ;
F_323 ( & V_10 -> V_342 , F_318 ) ;
F_323 ( & V_10 -> V_144 , F_77 ) ;
V_10 -> V_109 = V_110 ;
return V_10 ;
}
static bool F_324 ( T_2 V_17 , T_3 V_146 ) {
if ( ! V_17 )
return false ;
if ( F_325 ( V_146 ) )
return ( V_17 <= 0x00ff ) ;
return ( ( V_17 & 0x0101 ) == 0x0001 ) ;
}
int F_326 ( struct V_8 * V_20 , T_4 V_17 , T_2 V_11 ,
T_5 * V_145 , T_3 V_146 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_256 * V_185 ;
int V_21 ;
F_21 ( L_117 , & V_20 -> V_18 , V_145 ,
V_146 , F_66 ( V_17 ) ) ;
V_185 = F_327 ( V_145 , & V_20 -> V_18 ) ;
if ( ! V_185 )
return - V_627 ;
F_146 ( V_185 ) ;
if ( ! F_324 ( F_66 ( V_17 ) , V_146 ) && ! V_11 &&
V_20 -> V_29 != V_165 ) {
V_21 = - V_26 ;
goto V_24;
}
if ( V_20 -> V_29 == V_111 && ! V_17 ) {
V_21 = - V_26 ;
goto V_24;
}
if ( V_20 -> V_29 == V_30 && ! V_11 ) {
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
V_21 = - V_628 ;
goto V_24;
}
switch ( V_20 -> V_35 ) {
case V_68 :
case V_164 :
case V_66 :
V_21 = 0 ;
goto V_24;
case V_65 :
V_21 = - V_629 ;
goto V_24;
case V_77 :
case V_622 :
break;
default:
V_21 = - V_406 ;
goto V_24;
}
F_78 ( & V_20 -> V_145 , V_145 ) ;
V_20 -> V_146 = V_146 ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_11 ;
if ( F_325 ( V_146 ) ) {
T_3 V_328 ;
if ( V_146 == V_5 )
V_146 = V_4 ;
else
V_146 = V_630 ;
if ( F_67 ( V_631 , & V_185 -> V_510 ) )
V_328 = V_329 ;
else
V_328 = V_576 ;
V_2 = F_328 ( V_185 , V_145 , V_146 , V_20 -> V_69 ,
V_632 , V_328 ) ;
} else {
T_3 V_178 = F_84 ( V_20 ) ;
V_2 = F_329 ( V_185 , V_145 , V_20 -> V_69 , V_178 ) ;
}
if ( F_115 ( V_2 ) ) {
V_21 = F_186 ( V_2 ) ;
goto V_24;
}
V_10 = F_319 ( V_2 ) ;
if ( ! V_10 ) {
F_72 ( V_2 ) ;
V_21 = - V_56 ;
goto V_24;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_20 ) ;
if ( V_11 && F_2 ( V_10 , V_11 ) ) {
F_72 ( V_2 ) ;
V_21 = - V_633 ;
goto V_634;
}
F_78 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
V_20 -> V_361 = F_1 ( V_2 , V_2 -> V_361 ) ;
F_65 ( V_10 , V_20 ) ;
F_72 ( V_2 ) ;
F_20 ( V_20 , V_68 ) ;
F_82 ( V_20 , V_20 -> V_36 -> V_163 ( V_20 ) ) ;
F_15 ( & V_22 ) ;
V_20 -> V_19 = 0 ;
F_17 ( & V_22 ) ;
if ( V_2 -> V_35 == V_65 ) {
if ( V_20 -> V_29 != V_111 ) {
F_71 ( V_20 ) ;
if ( F_85 ( V_20 , true ) )
F_20 ( V_20 , V_65 ) ;
} else
F_135 ( V_20 ) ;
}
V_21 = 0 ;
V_634:
F_46 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
V_24:
F_147 ( V_185 ) ;
F_251 ( V_185 ) ;
return V_21 ;
}
int F_330 ( struct V_256 * V_185 , T_5 * V_623 )
{
int V_635 = 0 , V_636 = 0 , V_637 = 0 ;
struct V_8 * V_12 ;
F_21 ( L_118 , V_185 -> V_325 , V_623 ) ;
F_119 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_12 -> V_35 != V_162 )
continue;
if ( ! F_13 ( & V_12 -> V_18 , & V_185 -> V_623 ) ) {
V_636 |= V_638 ;
if ( F_67 ( V_639 , & V_12 -> V_98 ) )
V_636 |= V_640 ;
V_635 ++ ;
} else if ( ! F_13 ( & V_12 -> V_18 , V_366 ) ) {
V_637 |= V_638 ;
if ( F_67 ( V_639 , & V_12 -> V_98 ) )
V_637 |= V_640 ;
}
}
F_120 ( & V_22 ) ;
return V_635 ? V_636 : V_637 ;
}
static struct V_8 * F_331 ( struct V_8 * V_12 ,
T_5 * V_18 , T_3 V_359 )
{
F_119 ( & V_22 ) ;
if ( V_12 )
V_12 = F_332 ( V_12 , V_75 ) ;
else
V_12 = F_333 ( V_76 . V_347 , F_334 ( * V_12 ) , V_75 ) ;
F_335 (c, &chan_list, global_l) {
if ( V_12 -> V_29 != V_30 )
continue;
if ( V_12 -> V_35 != V_162 )
continue;
if ( F_13 ( & V_12 -> V_18 , V_18 ) && F_13 ( & V_12 -> V_18 , V_366 ) )
continue;
if ( V_359 == V_112 && V_12 -> V_361 != V_7 )
continue;
if ( V_359 == V_3 && V_12 -> V_361 == V_7 )
continue;
F_57 ( V_12 ) ;
F_120 ( & V_22 ) ;
return V_12 ;
}
F_120 ( & V_22 ) ;
return NULL ;
}
void F_336 ( struct V_1 * V_2 , T_3 V_159 )
{
struct V_256 * V_185 = V_2 -> V_185 ;
struct V_9 * V_10 ;
struct V_8 * V_501 ;
T_3 V_146 ;
F_21 ( L_119 , V_2 , & V_2 -> V_145 , V_159 ) ;
if ( V_159 ) {
F_152 ( V_2 , F_337 ( V_159 ) ) ;
return;
}
V_10 = F_319 ( V_2 ) ;
if ( ! V_10 )
return;
V_146 = F_1 ( V_2 , V_2 -> V_146 ) ;
if ( F_316 ( & V_185 -> V_624 , & V_2 -> V_145 , V_146 ) )
return;
V_501 = F_331 ( NULL , & V_185 -> V_623 , V_2 -> type ) ;
while ( V_501 ) {
struct V_8 * V_20 , * V_347 ;
if ( F_2 ( V_10 , V_501 -> V_14 ) )
goto V_347;
F_7 ( V_501 ) ;
V_20 = V_501 -> V_36 -> V_506 ( V_501 ) ;
if ( V_20 ) {
F_78 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
F_78 ( & V_20 -> V_145 , & V_2 -> V_145 ) ;
V_20 -> V_361 = F_1 ( V_2 , V_2 -> V_361 ) ;
V_20 -> V_146 = V_146 ;
F_65 ( V_10 , V_20 ) ;
}
F_46 ( V_501 ) ;
V_347:
V_347 = F_331 ( V_501 , & V_185 -> V_623 ,
V_2 -> type ) ;
F_47 ( V_501 ) ;
V_501 = V_347 ;
}
F_141 ( V_10 ) ;
}
int F_338 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_353 ;
F_21 ( L_120 , V_2 ) ;
if ( ! V_10 )
return V_110 ;
return V_10 -> V_109 ;
}
void F_339 ( struct V_1 * V_2 , T_3 V_64 )
{
F_21 ( L_121 , V_2 , V_64 ) ;
F_152 ( V_2 , F_337 ( V_64 ) ) ;
}
static inline void F_340 ( struct V_8 * V_20 , T_3 V_641 )
{
if ( V_20 -> V_29 != V_111 )
return;
if ( V_641 == 0x00 ) {
if ( V_20 -> V_69 == V_169 ) {
F_82 ( V_20 , V_642 ) ;
} else if ( V_20 -> V_69 == V_166 ||
V_20 -> V_69 == V_167 )
F_45 ( V_20 , V_67 ) ;
} else {
if ( V_20 -> V_69 == V_169 )
F_71 ( V_20 ) ;
}
}
int F_341 ( struct V_1 * V_2 , T_3 V_159 , T_3 V_641 )
{
struct V_9 * V_10 = V_2 -> V_353 ;
struct V_8 * V_20 ;
if ( ! V_10 )
return 0 ;
F_21 ( L_122 , V_10 , V_159 , V_641 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
F_21 ( L_123 , V_20 , V_20 -> V_14 ,
F_22 ( V_20 -> V_35 ) ) ;
if ( V_20 -> V_14 == V_311 ) {
F_46 ( V_20 ) ;
continue;
}
if ( ! V_159 && V_641 )
V_20 -> V_69 = V_2 -> V_69 ;
if ( ! F_117 ( V_20 ) ) {
F_46 ( V_20 ) ;
continue;
}
if ( ! V_159 && ( V_20 -> V_35 == V_65 ||
V_20 -> V_35 == V_66 ) ) {
V_20 -> V_36 -> V_588 ( V_20 ) ;
F_340 ( V_20 , V_641 ) ;
F_46 ( V_20 ) ;
continue;
}
if ( V_20 -> V_35 == V_68 ) {
if ( ! V_159 )
F_131 ( V_20 ) ;
else
F_82 ( V_20 , V_643 ) ;
} else if ( V_20 -> V_35 == V_164 ) {
struct V_157 V_148 ;
T_6 V_644 , V_645 ;
if ( ! V_159 ) {
if ( F_67 ( V_150 , & V_20 -> V_98 ) ) {
V_644 = V_317 ;
V_645 = V_318 ;
V_20 -> V_36 -> V_319 ( V_20 ) ;
} else {
F_20 ( V_20 , V_66 ) ;
V_644 = V_320 ;
V_645 = V_160 ;
}
} else {
F_20 ( V_20 , V_153 ) ;
F_82 ( V_20 , V_643 ) ;
V_644 = V_158 ;
V_645 = V_160 ;
}
V_148 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_148 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_148 . V_149 = F_16 ( V_644 ) ;
V_148 . V_159 = F_16 ( V_645 ) ;
F_80 ( V_10 , V_20 -> V_16 , V_161 ,
sizeof( V_148 ) , & V_148 ) ;
if ( ! F_67 ( V_322 , & V_20 -> V_80 ) &&
V_644 == V_320 ) {
char V_316 [ 128 ] ;
F_54 ( V_322 , & V_20 -> V_80 ) ;
F_80 ( V_10 , F_88 ( V_10 ) ,
V_323 ,
F_139 ( V_20 , V_316 ) ,
V_316 ) ;
V_20 -> V_324 ++ ;
}
}
F_46 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
int F_342 ( struct V_1 * V_2 , struct V_42 * V_46 , T_2 V_98 )
{
struct V_9 * V_10 = V_2 -> V_353 ;
struct V_241 * V_646 ;
int V_183 ;
if ( ! V_10 && V_2 -> V_185 -> V_536 != V_647 )
goto V_590;
if ( ! V_10 )
V_10 = F_319 ( V_2 ) ;
if ( ! V_10 )
goto V_590;
F_21 ( L_124 , V_10 , V_46 -> V_183 , V_98 ) ;
switch ( V_98 ) {
case V_187 :
case V_186 :
case V_197 :
if ( V_10 -> V_648 ) {
F_280 ( L_125 , V_46 -> V_183 ) ;
F_94 ( V_10 -> V_355 ) ;
V_10 -> V_355 = NULL ;
V_10 -> V_648 = 0 ;
F_143 ( V_10 , V_649 ) ;
}
if ( V_46 -> V_183 < V_238 ) {
F_280 ( L_126 , V_46 -> V_183 ) ;
F_143 ( V_10 , V_649 ) ;
goto V_590;
}
V_646 = (struct V_241 * ) V_46 -> V_184 ;
V_183 = F_66 ( V_646 -> V_183 ) + V_238 ;
if ( V_183 == V_46 -> V_183 ) {
F_315 ( V_10 , V_46 ) ;
return 0 ;
}
F_21 ( L_127 , V_183 , V_46 -> V_183 ) ;
if ( V_46 -> V_183 > V_183 ) {
F_280 ( L_128 ,
V_46 -> V_183 , V_183 ) ;
F_143 ( V_10 , V_649 ) ;
goto V_590;
}
V_10 -> V_355 = F_108 ( V_183 , V_55 ) ;
if ( ! V_10 -> V_355 )
goto V_590;
F_343 ( V_46 , F_110 ( V_10 -> V_355 , V_46 -> V_183 ) ,
V_46 -> V_183 ) ;
V_10 -> V_648 = V_183 - V_46 -> V_183 ;
break;
case V_650 :
F_21 ( L_129 , V_46 -> V_183 , V_10 -> V_648 ) ;
if ( ! V_10 -> V_648 ) {
F_280 ( L_130 , V_46 -> V_183 ) ;
F_143 ( V_10 , V_649 ) ;
goto V_590;
}
if ( V_46 -> V_183 > V_10 -> V_648 ) {
F_280 ( L_131 ,
V_46 -> V_183 , V_10 -> V_648 ) ;
F_94 ( V_10 -> V_355 ) ;
V_10 -> V_355 = NULL ;
V_10 -> V_648 = 0 ;
F_143 ( V_10 , V_649 ) ;
goto V_590;
}
F_343 ( V_46 , F_110 ( V_10 -> V_355 , V_46 -> V_183 ) ,
V_46 -> V_183 ) ;
V_10 -> V_648 -= V_46 -> V_183 ;
if ( ! V_10 -> V_648 ) {
struct V_42 * V_355 = V_10 -> V_355 ;
V_10 -> V_355 = NULL ;
F_315 ( V_10 , V_355 ) ;
}
break;
}
V_590:
F_94 ( V_46 ) ;
return 0 ;
}
static int F_344 ( struct V_651 * V_652 , void * V_25 )
{
struct V_8 * V_12 ;
F_119 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
F_345 ( V_652 , L_132 ,
& V_12 -> V_18 , & V_12 -> V_145 ,
V_12 -> V_35 , F_66 ( V_12 -> V_17 ) ,
V_12 -> V_14 , V_12 -> V_13 , V_12 -> V_106 , V_12 -> V_27 ,
V_12 -> V_69 , V_12 -> V_136 ) ;
}
F_120 ( & V_22 ) ;
return 0 ;
}
static int F_346 ( struct V_653 * V_653 , struct V_654 * V_654 )
{
return F_347 ( V_654 , F_344 , V_653 -> V_655 ) ;
}
int T_11 F_348 ( void )
{
int V_21 ;
V_21 = F_349 () ;
if ( V_21 < 0 )
return V_21 ;
if ( F_350 ( V_656 ) )
return 0 ;
V_657 = F_351 ( L_133 , 0444 , V_656 ,
NULL , & V_658 ) ;
F_352 ( L_134 , 0644 , V_656 ,
& V_104 ) ;
F_352 ( L_135 , 0644 , V_656 ,
& V_107 ) ;
return 0 ;
}
void F_353 ( void )
{
F_354 ( V_657 ) ;
F_355 () ;
}
