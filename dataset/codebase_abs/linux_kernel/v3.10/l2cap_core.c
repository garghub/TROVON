static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
F_2 (c, &conn->chan_l, list) {
if ( V_5 -> V_6 == V_4 )
return V_5 ;
}
return NULL ;
}
static struct V_1 * F_3 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
F_2 (c, &conn->chan_l, list) {
if ( V_5 -> V_7 == V_4 )
return V_5 ;
}
return NULL ;
}
static struct V_1 * F_4 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
F_5 ( & V_3 -> V_8 ) ;
V_5 = F_3 ( V_3 , V_4 ) ;
if ( V_5 )
F_6 ( V_5 ) ;
F_7 ( & V_3 -> V_8 ) ;
return V_5 ;
}
static struct V_1 * F_8 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
F_5 ( & V_3 -> V_8 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 )
F_6 ( V_5 ) ;
F_7 ( & V_3 -> V_8 ) ;
return V_5 ;
}
static struct V_1 * F_9 ( struct V_2 * V_3 ,
T_2 V_9 )
{
struct V_1 * V_5 ;
F_2 (c, &conn->chan_l, list) {
if ( V_5 -> V_9 == V_9 )
return V_5 ;
}
return NULL ;
}
static struct V_1 * F_10 ( struct V_2 * V_3 ,
T_2 V_9 )
{
struct V_1 * V_5 ;
F_5 ( & V_3 -> V_8 ) ;
V_5 = F_9 ( V_3 , V_9 ) ;
if ( V_5 )
F_6 ( V_5 ) ;
F_7 ( & V_3 -> V_8 ) ;
return V_5 ;
}
static struct V_1 * F_11 ( T_3 V_10 , T_4 * V_11 )
{
struct V_1 * V_5 ;
F_2 (c, &chan_list, global_l) {
if ( V_5 -> V_12 == V_10 && ! F_12 ( & F_13 ( V_5 -> V_13 ) -> V_11 , V_11 ) )
return V_5 ;
}
return NULL ;
}
int F_14 ( struct V_1 * V_14 , T_4 * V_11 , T_3 V_10 )
{
int V_15 ;
F_15 ( & V_16 ) ;
if ( V_10 && F_11 ( V_10 , V_11 ) ) {
V_15 = - V_17 ;
goto V_18;
}
if ( V_10 ) {
V_14 -> V_10 = V_10 ;
V_14 -> V_12 = V_10 ;
V_15 = 0 ;
} else {
T_1 V_19 ;
V_15 = - V_20 ;
for ( V_19 = 0x1001 ; V_19 < 0x1100 ; V_19 += 2 )
if ( ! F_11 ( F_16 ( V_19 ) , V_11 ) ) {
V_14 -> V_10 = F_16 ( V_19 ) ;
V_14 -> V_12 = F_16 ( V_19 ) ;
V_15 = 0 ;
break;
}
}
V_18:
F_17 ( & V_16 ) ;
return V_15 ;
}
int F_18 ( struct V_1 * V_14 , T_5 V_7 )
{
F_15 ( & V_16 ) ;
V_14 -> V_7 = V_7 ;
F_17 ( & V_16 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_2 * V_3 )
{
T_1 V_4 = V_21 ;
for (; V_4 < V_22 ; V_4 ++ ) {
if ( ! F_3 ( V_3 , V_4 ) )
return V_4 ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_14 , int V_23 )
{
F_21 ( L_1 , V_14 , F_22 ( V_14 -> V_23 ) ,
F_22 ( V_23 ) ) ;
V_14 -> V_23 = V_23 ;
V_14 -> V_24 -> V_25 ( V_14 , V_23 ) ;
}
static void F_23 ( struct V_1 * V_14 , int V_23 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
F_24 ( V_13 ) ;
F_20 ( V_14 , V_23 ) ;
F_25 ( V_13 ) ;
}
static inline void F_26 ( struct V_1 * V_14 , int V_15 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
V_13 -> V_27 = V_15 ;
}
static inline void F_27 ( struct V_1 * V_14 , int V_15 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
F_24 ( V_13 ) ;
F_26 ( V_14 , V_15 ) ;
F_25 ( V_13 ) ;
}
static void F_28 ( struct V_1 * V_14 )
{
if ( ! F_29 ( & V_14 -> V_28 ) &&
V_14 -> V_29 ) {
F_30 ( V_14 , & V_14 -> V_30 ,
F_31 ( V_14 -> V_29 ) ) ;
}
}
static void F_32 ( struct V_1 * V_14 )
{
F_33 ( V_14 ) ;
if ( V_14 -> V_31 ) {
F_30 ( V_14 , & V_14 -> V_28 ,
F_31 ( V_14 -> V_31 ) ) ;
}
}
static struct V_32 * F_34 ( struct V_33 * V_34 ,
T_1 V_35 )
{
struct V_32 * V_36 ;
F_35 (head, skb) {
if ( F_36 ( V_36 ) -> V_37 . V_38 == V_35 )
return V_36 ;
}
return NULL ;
}
static int F_37 ( struct V_39 * V_40 , T_1 V_41 )
{
T_6 V_42 , V_43 ;
V_42 = F_38 ( V_41 ) ;
V_40 -> V_44 = F_39 ( sizeof( T_1 ) * V_42 , V_45 ) ;
if ( ! V_40 -> V_44 )
return - V_46 ;
V_40 -> V_47 = V_42 - 1 ;
V_40 -> V_34 = V_48 ;
V_40 -> V_49 = V_48 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
V_40 -> V_44 [ V_43 ] = V_48 ;
return 0 ;
}
static inline void F_40 ( struct V_39 * V_40 )
{
F_41 ( V_40 -> V_44 ) ;
}
static inline bool F_42 ( struct V_39 * V_40 ,
T_1 V_35 )
{
return V_40 -> V_44 [ V_35 & V_40 -> V_47 ] != V_48 ;
}
static T_1 F_43 ( struct V_39 * V_40 , T_1 V_35 )
{
T_1 V_47 = V_40 -> V_47 ;
if ( V_40 -> V_34 == V_48 ) {
return V_48 ;
} else if ( V_40 -> V_34 == V_35 ) {
V_40 -> V_34 = V_40 -> V_44 [ V_35 & V_47 ] ;
V_40 -> V_44 [ V_35 & V_47 ] = V_48 ;
if ( V_40 -> V_34 == V_50 ) {
V_40 -> V_34 = V_48 ;
V_40 -> V_49 = V_48 ;
}
} else {
T_1 V_51 = V_40 -> V_34 ;
while ( V_40 -> V_44 [ V_51 & V_47 ] != V_35 ) {
V_51 = V_40 -> V_44 [ V_51 & V_47 ] ;
if ( V_51 == V_50 )
return V_48 ;
}
V_40 -> V_44 [ V_51 & V_47 ] = V_40 -> V_44 [ V_35 & V_47 ] ;
V_40 -> V_44 [ V_35 & V_47 ] = V_48 ;
if ( V_40 -> V_49 == V_35 )
V_40 -> V_49 = V_51 ;
}
return V_35 ;
}
static inline T_1 F_44 ( struct V_39 * V_40 )
{
return F_43 ( V_40 , V_40 -> V_34 ) ;
}
static void F_45 ( struct V_39 * V_40 )
{
T_1 V_43 ;
if ( V_40 -> V_34 == V_48 )
return;
for ( V_43 = 0 ; V_43 <= V_40 -> V_47 ; V_43 ++ )
V_40 -> V_44 [ V_43 ] = V_48 ;
V_40 -> V_34 = V_48 ;
V_40 -> V_49 = V_48 ;
}
static void F_46 ( struct V_39 * V_40 , T_1 V_35 )
{
T_1 V_47 = V_40 -> V_47 ;
if ( V_40 -> V_44 [ V_35 & V_47 ] != V_48 )
return;
if ( V_40 -> V_49 == V_48 )
V_40 -> V_34 = V_35 ;
else
V_40 -> V_44 [ V_40 -> V_49 & V_47 ] = V_35 ;
V_40 -> V_49 = V_35 ;
V_40 -> V_44 [ V_35 & V_47 ] = V_50 ;
}
static void F_47 ( struct V_52 * V_53 )
{
struct V_1 * V_14 = F_48 ( V_53 , struct V_1 ,
V_54 . V_53 ) ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_55 ;
F_21 ( L_2 , V_14 , F_22 ( V_14 -> V_23 ) ) ;
F_5 ( & V_3 -> V_8 ) ;
F_6 ( V_14 ) ;
if ( V_14 -> V_23 == V_56 || V_14 -> V_23 == V_57 )
V_55 = V_58 ;
else if ( V_14 -> V_23 == V_59 &&
V_14 -> V_60 != V_61 )
V_55 = V_58 ;
else
V_55 = V_62 ;
F_49 ( V_14 , V_55 ) ;
F_50 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
F_51 ( V_14 ) ;
}
struct V_1 * F_52 ( void )
{
struct V_1 * V_14 ;
V_14 = F_53 ( sizeof( * V_14 ) , V_64 ) ;
if ( ! V_14 )
return NULL ;
F_54 ( & V_14 -> V_65 ) ;
F_15 ( & V_16 ) ;
F_55 ( & V_14 -> V_66 , & V_67 ) ;
F_17 ( & V_16 ) ;
F_56 ( & V_14 -> V_54 , F_47 ) ;
V_14 -> V_23 = V_68 ;
F_57 ( & V_14 -> V_69 ) ;
F_58 ( V_70 , & V_14 -> V_71 ) ;
F_21 ( L_3 , V_14 ) ;
return V_14 ;
}
static void F_59 ( struct V_69 * V_69 )
{
struct V_1 * V_14 = F_48 ( V_69 , struct V_1 , V_69 ) ;
F_21 ( L_3 , V_14 ) ;
F_15 ( & V_16 ) ;
F_60 ( & V_14 -> V_66 ) ;
F_17 ( & V_16 ) ;
F_41 ( V_14 ) ;
}
void F_61 ( struct V_1 * V_5 )
{
F_21 ( L_4 , V_5 , F_62 ( & V_5 -> V_69 . V_72 ) ) ;
F_63 ( & V_5 -> V_69 ) ;
}
void F_51 ( struct V_1 * V_5 )
{
F_21 ( L_4 , V_5 , F_62 ( & V_5 -> V_69 . V_72 ) ) ;
F_64 ( & V_5 -> V_69 , F_59 ) ;
}
void F_65 ( struct V_1 * V_14 )
{
V_14 -> V_73 = V_74 ;
V_14 -> V_75 = V_76 ;
V_14 -> V_77 = V_78 ;
V_14 -> V_79 = V_78 ;
V_14 -> V_80 = V_78 ;
V_14 -> V_60 = V_81 ;
F_58 ( V_82 , & V_14 -> V_83 ) ;
}
void F_66 ( struct V_2 * V_3 , struct V_1 * V_14 )
{
F_21 ( L_5 , V_3 ,
F_67 ( V_14 -> V_10 ) , V_14 -> V_6 ) ;
V_3 -> V_84 = V_85 ;
V_14 -> V_3 = V_3 ;
switch ( V_14 -> V_86 ) {
case V_87 :
if ( V_3 -> V_88 -> type == V_89 ) {
V_14 -> V_90 = V_91 ;
V_14 -> V_7 = V_92 ;
V_14 -> V_6 = V_92 ;
} else {
V_14 -> V_7 = F_19 ( V_3 ) ;
V_14 -> V_90 = V_91 ;
}
break;
case V_93 :
V_14 -> V_7 = V_94 ;
V_14 -> V_6 = V_94 ;
V_14 -> V_90 = V_91 ;
break;
case V_95 :
V_14 -> V_7 = V_96 ;
V_14 -> V_6 = V_96 ;
V_14 -> V_90 = V_97 ;
V_14 -> V_98 = V_97 ;
break;
default:
V_14 -> V_7 = V_99 ;
V_14 -> V_6 = V_99 ;
V_14 -> V_90 = V_91 ;
}
V_14 -> V_100 = V_101 ;
V_14 -> V_102 = V_103 ;
V_14 -> V_104 = V_105 ;
V_14 -> V_106 = V_107 ;
V_14 -> V_108 = V_109 ;
V_14 -> V_110 = V_111 ;
F_61 ( V_14 ) ;
F_55 ( & V_14 -> V_44 , & V_3 -> V_112 ) ;
}
void F_68 ( struct V_2 * V_3 , struct V_1 * V_14 )
{
F_5 ( & V_3 -> V_8 ) ;
F_66 ( V_3 , V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
}
void F_69 ( struct V_1 * V_14 , int V_15 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
F_70 ( V_14 ) ;
F_21 ( L_6 , V_14 , V_3 , V_15 ) ;
if ( V_3 ) {
struct V_113 * V_114 = V_3 -> V_88 -> V_113 ;
F_60 ( & V_14 -> V_44 ) ;
F_51 ( V_14 ) ;
V_14 -> V_3 = NULL ;
if ( V_14 -> V_86 != V_95 )
F_71 ( V_3 -> V_88 ) ;
if ( V_114 && V_114 -> V_115 == V_14 )
V_114 -> V_115 = NULL ;
}
if ( V_14 -> V_116 ) {
struct V_117 * V_116 = V_14 -> V_116 ;
F_21 ( L_7 , V_14 , V_116 ) ;
F_72 ( V_116 ) ;
}
V_14 -> V_24 -> V_118 ( V_14 , V_15 ) ;
if ( F_73 ( V_70 , & V_14 -> V_71 ) )
return;
switch( V_14 -> V_119 ) {
case V_120 :
break;
case V_121 :
F_33 ( V_14 ) ;
F_74 ( V_14 ) ;
F_75 ( V_14 ) ;
F_76 ( & V_14 -> V_122 ) ;
F_40 ( & V_14 -> V_123 ) ;
F_40 ( & V_14 -> V_124 ) ;
case V_125 :
F_76 ( & V_14 -> V_126 ) ;
break;
}
return;
}
void F_49 ( struct V_1 * V_14 , int V_55 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_26 * V_13 = V_14 -> V_13 ;
F_21 ( L_8 , V_14 , F_22 ( V_14 -> V_23 ) ,
V_13 ) ;
switch ( V_14 -> V_23 ) {
case V_127 :
V_14 -> V_24 -> V_118 ( V_14 , 0 ) ;
break;
case V_56 :
case V_57 :
if ( V_14 -> V_86 == V_87 &&
V_3 -> V_88 -> type == V_128 ) {
F_77 ( V_14 , V_13 -> V_129 ) ;
F_78 ( V_14 , V_55 ) ;
} else
F_69 ( V_14 , V_55 ) ;
break;
case V_130 :
if ( V_14 -> V_86 == V_87 &&
V_3 -> V_88 -> type == V_128 ) {
struct V_131 V_132 ;
T_5 V_133 ;
if ( F_73 ( V_134 , & F_13 ( V_13 ) -> V_83 ) )
V_133 = V_135 ;
else
V_133 = V_136 ;
F_23 ( V_14 , V_137 ) ;
V_132 . V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_6 = F_16 ( V_14 -> V_7 ) ;
V_132 . V_133 = F_16 ( V_133 ) ;
V_132 . V_138 = F_79 ( V_139 ) ;
F_80 ( V_3 , V_14 -> V_9 , V_140 ,
sizeof( V_132 ) , & V_132 ) ;
}
F_69 ( V_14 , V_55 ) ;
break;
case V_59 :
case V_137 :
F_69 ( V_14 , V_55 ) ;
break;
default:
V_14 -> V_24 -> V_118 ( V_14 , 0 ) ;
break;
}
}
static inline T_2 F_81 ( struct V_1 * V_14 )
{
if ( V_14 -> V_86 == V_141 ) {
switch ( V_14 -> V_60 ) {
case V_142 :
return V_143 ;
case V_144 :
return V_145 ;
default:
return V_146 ;
}
} else if ( V_14 -> V_10 == F_79 ( V_147 ) ) {
if ( V_14 -> V_60 == V_81 )
V_14 -> V_60 = V_61 ;
if ( V_14 -> V_60 == V_142 )
return V_148 ;
else
return V_146 ;
} else {
switch ( V_14 -> V_60 ) {
case V_142 :
return V_149 ;
case V_144 :
return V_150 ;
default:
return V_146 ;
}
}
}
int F_82 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
T_7 V_151 ;
V_151 = F_81 ( V_14 ) ;
return F_83 ( V_3 -> V_88 , V_14 -> V_60 , V_151 ) ;
}
static T_2 F_84 ( struct V_2 * V_3 )
{
T_2 V_152 ;
F_85 ( & V_3 -> V_65 ) ;
if ( ++ V_3 -> V_153 > 128 )
V_3 -> V_153 = 1 ;
V_152 = V_3 -> V_153 ;
F_86 ( & V_3 -> V_65 ) ;
return V_152 ;
}
static void F_80 ( struct V_2 * V_3 , T_2 V_9 , T_2 V_154 , T_1 V_155 ,
void * V_156 )
{
struct V_32 * V_36 = F_87 ( V_3 , V_154 , V_9 , V_155 , V_156 ) ;
T_2 V_83 ;
F_21 ( L_9 , V_154 ) ;
if ( ! V_36 )
return;
if ( F_88 ( V_3 -> V_88 -> V_157 ) )
V_83 = V_158 ;
else
V_83 = V_159 ;
F_36 ( V_36 ) -> V_160 = V_161 ;
V_36 -> V_162 = V_163 ;
F_89 ( V_3 -> V_164 , V_36 , V_83 ) ;
}
static bool F_90 ( struct V_1 * V_14 )
{
return V_14 -> V_165 != V_166 &&
V_14 -> V_165 != V_167 ;
}
static void F_91 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
struct V_168 * V_88 = V_14 -> V_3 -> V_88 ;
T_1 V_83 ;
F_21 ( L_10 , V_14 , V_36 , V_36 -> V_155 ,
V_36 -> V_162 ) ;
if ( V_14 -> V_169 && ! F_90 ( V_14 ) ) {
if ( V_14 -> V_116 )
F_89 ( V_14 -> V_116 , V_36 , V_170 ) ;
else
F_92 ( V_36 ) ;
return;
}
if ( ! F_73 ( V_171 , & V_14 -> V_83 ) &&
F_88 ( V_88 -> V_157 ) )
V_83 = V_158 ;
else
V_83 = V_159 ;
F_36 ( V_36 ) -> V_160 = F_73 ( V_82 , & V_14 -> V_83 ) ;
F_89 ( V_14 -> V_3 -> V_164 , V_36 , V_83 ) ;
}
static void F_93 ( T_1 V_172 , struct V_173 * V_37 )
{
V_37 -> V_174 = ( V_172 & V_175 ) >> V_176 ;
V_37 -> V_177 = ( V_172 & V_178 ) >> V_179 ;
if ( V_172 & V_180 ) {
V_37 -> V_181 = 1 ;
V_37 -> V_182 = ( V_172 & V_183 ) >> V_184 ;
V_37 -> V_185 = ( V_172 & V_186 ) >> V_187 ;
V_37 -> V_188 = 0 ;
V_37 -> V_38 = 0 ;
} else {
V_37 -> V_181 = 0 ;
V_37 -> V_188 = ( V_172 & V_189 ) >> V_190 ;
V_37 -> V_38 = ( V_172 & V_191 ) >> V_192 ;
V_37 -> V_182 = 0 ;
V_37 -> V_185 = 0 ;
}
}
static void F_94 ( T_8 V_193 , struct V_173 * V_37 )
{
V_37 -> V_174 = ( V_193 & V_194 ) >> V_195 ;
V_37 -> V_177 = ( V_193 & V_196 ) >> V_197 ;
if ( V_193 & V_198 ) {
V_37 -> V_181 = 1 ;
V_37 -> V_182 = ( V_193 & V_199 ) >> V_200 ;
V_37 -> V_185 = ( V_193 & V_201 ) >> V_202 ;
V_37 -> V_188 = 0 ;
V_37 -> V_38 = 0 ;
} else {
V_37 -> V_181 = 0 ;
V_37 -> V_188 = ( V_193 & V_203 ) >> V_204 ;
V_37 -> V_38 = ( V_193 & V_205 ) >> V_206 ;
V_37 -> V_182 = 0 ;
V_37 -> V_185 = 0 ;
}
}
static inline void F_95 ( struct V_1 * V_14 ,
struct V_32 * V_36 )
{
if ( F_73 ( V_207 , & V_14 -> V_83 ) ) {
F_94 ( F_96 ( V_36 -> V_156 ) ,
& F_36 ( V_36 ) -> V_37 ) ;
F_97 ( V_36 , V_208 ) ;
} else {
F_93 ( F_98 ( V_36 -> V_156 ) ,
& F_36 ( V_36 ) -> V_37 ) ;
F_97 ( V_36 , V_209 ) ;
}
}
static T_8 F_99 ( struct V_173 * V_37 )
{
T_8 V_210 ;
V_210 = V_37 -> V_174 << V_195 ;
V_210 |= V_37 -> V_177 << V_197 ;
if ( V_37 -> V_181 ) {
V_210 |= V_37 -> V_182 << V_200 ;
V_210 |= V_37 -> V_185 << V_202 ;
V_210 |= V_198 ;
} else {
V_210 |= V_37 -> V_188 << V_204 ;
V_210 |= V_37 -> V_38 << V_206 ;
}
return V_210 ;
}
static T_1 F_100 ( struct V_173 * V_37 )
{
T_1 V_210 ;
V_210 = V_37 -> V_174 << V_176 ;
V_210 |= V_37 -> V_177 << V_179 ;
if ( V_37 -> V_181 ) {
V_210 |= V_37 -> V_182 << V_184 ;
V_210 |= V_37 -> V_185 << V_187 ;
V_210 |= V_180 ;
} else {
V_210 |= V_37 -> V_188 << V_190 ;
V_210 |= V_37 -> V_38 << V_192 ;
}
return V_210 ;
}
static inline void F_101 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 )
{
if ( F_73 ( V_207 , & V_14 -> V_83 ) ) {
F_102 ( F_99 ( V_37 ) ,
V_36 -> V_156 + V_211 ) ;
} else {
F_103 ( F_100 ( V_37 ) ,
V_36 -> V_156 + V_211 ) ;
}
}
static inline unsigned int F_104 ( struct V_1 * V_14 )
{
if ( F_73 ( V_207 , & V_14 -> V_83 ) )
return V_212 ;
else
return V_213 ;
}
static struct V_32 * F_105 ( struct V_1 * V_14 ,
T_8 V_37 )
{
struct V_32 * V_36 ;
struct V_214 * V_215 ;
int V_216 = F_104 ( V_14 ) ;
if ( V_14 -> V_73 == V_74 )
V_216 += V_217 ;
V_36 = F_106 ( V_216 , V_45 ) ;
if ( ! V_36 )
return F_107 ( - V_46 ) ;
V_215 = (struct V_214 * ) F_108 ( V_36 , V_211 ) ;
V_215 -> V_155 = F_16 ( V_216 - V_211 ) ;
V_215 -> V_4 = F_16 ( V_14 -> V_6 ) ;
if ( F_73 ( V_207 , & V_14 -> V_83 ) )
F_102 ( V_37 , F_108 ( V_36 , V_208 ) ) ;
else
F_103 ( V_37 , F_108 ( V_36 , V_209 ) ) ;
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_109 ( 0 , ( T_2 * ) V_36 -> V_156 , V_36 -> V_155 ) ;
F_103 ( V_73 , F_108 ( V_36 , V_217 ) ) ;
}
V_36 -> V_162 = V_163 ;
return V_36 ;
}
static void F_110 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
struct V_32 * V_36 ;
T_8 V_218 ;
F_21 ( L_11 , V_14 , V_37 ) ;
if ( ! V_37 -> V_181 )
return;
if ( F_90 ( V_14 ) )
return;
if ( F_111 ( V_219 , & V_14 -> V_220 ) &&
! V_37 -> V_182 )
V_37 -> V_177 = 1 ;
if ( V_37 -> V_185 == V_221 )
F_112 ( V_222 , & V_14 -> V_220 ) ;
else if ( V_37 -> V_185 == V_223 )
F_58 ( V_222 , & V_14 -> V_220 ) ;
if ( V_37 -> V_185 != V_224 ) {
V_14 -> V_225 = V_37 -> V_174 ;
F_75 ( V_14 ) ;
}
F_21 ( L_12 , V_37 -> V_174 ,
V_37 -> V_177 , V_37 -> V_182 , V_37 -> V_185 ) ;
if ( F_73 ( V_207 , & V_14 -> V_83 ) )
V_218 = F_99 ( V_37 ) ;
else
V_218 = F_100 ( V_37 ) ;
V_36 = F_105 ( V_14 , V_218 ) ;
if ( ! F_113 ( V_36 ) )
F_91 ( V_14 , V_36 ) ;
}
static void F_114 ( struct V_1 * V_14 , bool V_182 )
{
struct V_173 V_37 ;
F_21 ( L_13 , V_14 , V_182 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
V_37 . V_182 = V_182 ;
if ( F_73 ( V_226 , & V_14 -> V_220 ) )
V_37 . V_185 = V_223 ;
else
V_37 . V_185 = V_221 ;
V_37 . V_174 = V_14 -> V_227 ;
F_110 ( V_14 , & V_37 ) ;
}
static inline int F_115 ( struct V_1 * V_14 )
{
return ! F_73 ( V_228 , & V_14 -> V_71 ) ;
}
static bool F_116 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
if ( V_229 &&
F_117 () &&
V_14 -> V_230 == V_231 &&
V_3 -> V_232 & V_233 )
return true ;
else
return false ;
}
static bool F_118 ( struct V_1 * V_14 )
{
return true ;
}
void F_119 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_234 V_235 ;
V_235 . V_7 = F_16 ( V_14 -> V_7 ) ;
V_235 . V_10 = V_14 -> V_10 ;
V_14 -> V_9 = F_84 ( V_3 ) ;
F_58 ( V_228 , & V_14 -> V_71 ) ;
F_80 ( V_3 , V_14 -> V_9 , V_236 , sizeof( V_235 ) , & V_235 ) ;
}
static void F_120 ( struct V_1 * V_14 , T_2 V_237 )
{
struct V_238 V_235 ;
V_235 . V_7 = F_16 ( V_14 -> V_7 ) ;
V_235 . V_10 = V_14 -> V_10 ;
V_235 . V_237 = V_237 ;
V_14 -> V_9 = F_84 ( V_14 -> V_3 ) ;
F_80 ( V_14 -> V_3 , V_14 -> V_9 , V_239 ,
sizeof( V_235 ) , & V_235 ) ;
}
static void F_121 ( struct V_1 * V_14 )
{
struct V_32 * V_36 ;
F_21 ( L_3 , V_14 ) ;
if ( V_14 -> V_119 != V_121 )
return;
F_33 ( V_14 ) ;
F_74 ( V_14 ) ;
F_75 ( V_14 ) ;
V_14 -> V_240 = 0 ;
F_35 (&chan->tx_q, skb) {
if ( F_36 ( V_36 ) -> V_37 . V_241 )
F_36 ( V_36 ) -> V_37 . V_241 = 1 ;
else
break;
}
V_14 -> V_242 = V_14 -> V_227 ;
F_112 ( V_243 , & V_14 -> V_220 ) ;
F_112 ( V_244 , & V_14 -> V_220 ) ;
F_45 ( & V_14 -> V_124 ) ;
F_45 ( & V_14 -> V_123 ) ;
F_76 ( & V_14 -> V_122 ) ;
V_14 -> V_245 = V_246 ;
V_14 -> V_247 = V_248 ;
F_58 ( V_249 , & V_14 -> V_220 ) ;
}
static void F_122 ( struct V_1 * V_14 )
{
T_2 V_250 = V_14 -> V_250 ;
F_21 ( L_3 , V_14 ) ;
V_14 -> V_165 = V_166 ;
V_14 -> V_250 = V_251 ;
if ( V_14 -> V_119 != V_121 )
return;
switch ( V_250 ) {
case V_252 :
F_123 ( V_14 , NULL , NULL , V_253 ) ;
V_14 -> V_247 = V_254 ;
break;
case V_255 :
V_14 -> V_247 = V_256 ;
break;
}
}
static void F_124 ( struct V_1 * V_14 )
{
V_14 -> V_71 = 0 ;
F_70 ( V_14 ) ;
V_14 -> V_23 = V_56 ;
V_14 -> V_24 -> V_257 ( V_14 ) ;
}
static void F_125 ( struct V_1 * V_14 )
{
if ( F_116 ( V_14 ) ) {
F_21 ( L_14 , V_14 ) ;
F_126 ( V_14 ) ;
} else {
F_119 ( V_14 ) ;
}
}
static void F_127 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
if ( V_3 -> V_88 -> type == V_89 ) {
F_124 ( V_14 ) ;
return;
}
if ( V_3 -> V_258 & V_259 ) {
if ( ! ( V_3 -> V_258 & V_260 ) )
return;
if ( F_82 ( V_14 ) &&
F_115 ( V_14 ) ) {
F_125 ( V_14 ) ;
}
} else {
struct V_261 V_235 ;
V_235 . type = F_79 ( V_262 ) ;
V_3 -> V_258 |= V_259 ;
V_3 -> V_263 = F_84 ( V_3 ) ;
F_128 ( & V_3 -> V_264 , V_265 ) ;
F_80 ( V_3 , V_3 -> V_263 , V_266 ,
sizeof( V_235 ) , & V_235 ) ;
}
}
static inline int F_129 ( T_7 V_119 , T_9 V_267 )
{
T_8 V_268 = V_269 ;
if ( ! V_270 )
V_268 |= V_271 | V_272 ;
switch ( V_119 ) {
case V_121 :
return V_271 & V_267 & V_268 ;
case V_125 :
return V_272 & V_267 & V_268 ;
default:
return 0x00 ;
}
}
static void F_78 ( struct V_1 * V_14 , int V_15 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_273 V_235 ;
if ( ! V_3 )
return;
if ( V_14 -> V_119 == V_121 && V_14 -> V_23 == V_56 ) {
F_33 ( V_14 ) ;
F_74 ( V_14 ) ;
F_75 ( V_14 ) ;
}
if ( V_14 -> V_86 == V_95 ) {
F_23 ( V_14 , V_137 ) ;
return;
}
V_235 . V_6 = F_16 ( V_14 -> V_6 ) ;
V_235 . V_7 = F_16 ( V_14 -> V_7 ) ;
F_80 ( V_3 , F_84 ( V_3 ) , V_274 ,
sizeof( V_235 ) , & V_235 ) ;
F_24 ( V_13 ) ;
F_20 ( V_14 , V_137 ) ;
F_26 ( V_14 , V_15 ) ;
F_25 ( V_13 ) ;
}
static void F_130 ( struct V_2 * V_3 )
{
struct V_1 * V_14 , * V_275 ;
F_21 ( L_15 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_131 (chan, tmp, &conn->chan_l, list) {
struct V_26 * V_13 = V_14 -> V_13 ;
F_6 ( V_14 ) ;
if ( V_14 -> V_86 != V_87 ) {
F_50 ( V_14 ) ;
continue;
}
if ( V_14 -> V_23 == V_59 ) {
if ( ! F_82 ( V_14 ) ||
! F_115 ( V_14 ) ) {
F_50 ( V_14 ) ;
continue;
}
if ( ! F_129 ( V_14 -> V_119 , V_3 -> V_267 )
&& F_73 ( V_276 ,
& V_14 -> V_71 ) ) {
F_49 ( V_14 , V_277 ) ;
F_50 ( V_14 ) ;
continue;
}
F_125 ( V_14 ) ;
} else if ( V_14 -> V_23 == V_130 ) {
struct V_131 V_132 ;
char V_278 [ 128 ] ;
V_132 . V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_6 = F_16 ( V_14 -> V_7 ) ;
if ( F_82 ( V_14 ) ) {
F_24 ( V_13 ) ;
if ( F_73 ( V_134 ,
& F_13 ( V_13 ) -> V_83 ) ) {
V_132 . V_133 = F_79 ( V_279 ) ;
V_132 . V_138 = F_79 ( V_280 ) ;
V_14 -> V_24 -> V_281 ( V_14 ) ;
} else {
F_20 ( V_14 , V_57 ) ;
V_132 . V_133 = F_79 ( V_282 ) ;
V_132 . V_138 = F_79 ( V_139 ) ;
}
F_25 ( V_13 ) ;
} else {
V_132 . V_133 = F_79 ( V_279 ) ;
V_132 . V_138 = F_79 ( V_283 ) ;
}
F_80 ( V_3 , V_14 -> V_9 , V_140 ,
sizeof( V_132 ) , & V_132 ) ;
if ( F_73 ( V_284 , & V_14 -> V_71 ) ||
V_132 . V_133 != V_282 ) {
F_50 ( V_14 ) ;
continue;
}
F_58 ( V_284 , & V_14 -> V_71 ) ;
F_80 ( V_3 , F_84 ( V_3 ) , V_285 ,
F_132 ( V_14 , V_278 ) , V_278 ) ;
V_14 -> V_286 ++ ;
}
F_50 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static struct V_1 * F_133 ( int V_23 , T_1 V_4 ,
T_4 * V_11 ,
T_4 * V_287 )
{
struct V_1 * V_5 , * V_288 = NULL ;
F_134 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
if ( V_23 && V_5 -> V_23 != V_23 )
continue;
if ( V_5 -> V_7 == V_4 ) {
int V_289 , V_290 ;
int V_291 , V_292 ;
V_289 = ! F_12 ( & F_13 ( V_13 ) -> V_11 , V_11 ) ;
V_290 = ! F_12 ( & F_13 ( V_13 ) -> V_287 , V_287 ) ;
if ( V_289 && V_290 ) {
F_135 ( & V_16 ) ;
return V_5 ;
}
V_291 = ! F_12 ( & F_13 ( V_13 ) -> V_11 , V_293 ) ;
V_292 = ! F_12 ( & F_13 ( V_13 ) -> V_287 , V_293 ) ;
if ( ( V_289 && V_292 ) || ( V_291 && V_290 ) ||
( V_291 && V_292 ) )
V_288 = V_5 ;
}
}
F_135 ( & V_16 ) ;
return V_288 ;
}
static void F_136 ( struct V_2 * V_3 )
{
struct V_26 * V_294 , * V_13 ;
struct V_1 * V_14 , * V_295 ;
F_21 ( L_16 ) ;
V_295 = F_133 ( V_127 , V_92 ,
V_3 -> V_11 , V_3 -> V_287 ) ;
if ( ! V_295 )
return;
V_294 = V_295 -> V_13 ;
F_24 ( V_294 ) ;
V_14 = V_295 -> V_24 -> V_296 ( V_295 ) ;
if ( ! V_14 )
goto V_297;
V_13 = V_14 -> V_13 ;
F_137 ( V_3 -> V_88 ) ;
V_3 -> V_88 -> V_298 = V_299 ;
F_138 ( & F_13 ( V_13 ) -> V_11 , V_3 -> V_11 ) ;
F_138 ( & F_13 ( V_13 ) -> V_287 , V_3 -> V_287 ) ;
F_68 ( V_3 , V_14 ) ;
F_124 ( V_14 ) ;
V_297:
F_25 ( V_294 ) ;
}
static void F_139 ( struct V_2 * V_3 )
{
struct V_1 * V_14 ;
struct V_168 * V_88 = V_3 -> V_88 ;
F_21 ( L_15 , V_3 ) ;
if ( ! V_88 -> V_300 && V_88 -> type == V_89 )
F_136 ( V_3 ) ;
if ( V_88 -> V_300 && V_88 -> type == V_89 )
F_140 ( V_88 , V_88 -> V_301 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
F_6 ( V_14 ) ;
if ( V_14 -> V_86 == V_95 ) {
F_50 ( V_14 ) ;
continue;
}
if ( V_88 -> type == V_89 ) {
if ( F_140 ( V_88 , V_14 -> V_60 ) )
F_124 ( V_14 ) ;
} else if ( V_14 -> V_86 != V_87 ) {
struct V_26 * V_13 = V_14 -> V_13 ;
F_70 ( V_14 ) ;
F_24 ( V_13 ) ;
F_20 ( V_14 , V_56 ) ;
V_13 -> V_302 ( V_13 ) ;
F_25 ( V_13 ) ;
} else if ( V_14 -> V_23 == V_59 )
F_127 ( V_14 ) ;
F_50 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static void F_141 ( struct V_2 * V_3 , int V_15 )
{
struct V_1 * V_14 ;
F_21 ( L_15 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
if ( F_73 ( V_303 , & V_14 -> V_83 ) )
F_27 ( V_14 , V_15 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static void F_142 ( struct V_52 * V_53 )
{
struct V_2 * V_3 = F_48 ( V_53 , struct V_2 ,
V_264 . V_53 ) ;
V_3 -> V_258 |= V_260 ;
V_3 -> V_263 = 0 ;
F_130 ( V_3 ) ;
}
int F_143 ( struct V_2 * V_3 , struct V_304 * V_305 )
{
struct V_306 * V_157 = V_3 -> V_88 -> V_157 ;
int V_307 ;
F_144 ( V_157 ) ;
if ( V_305 -> V_44 . V_308 || V_305 -> V_44 . V_51 ) {
V_307 = - V_20 ;
goto V_309;
}
if ( ! V_3 -> V_164 ) {
V_307 = - V_310 ;
goto V_309;
}
V_307 = V_305 -> V_311 ( V_3 , V_305 ) ;
if ( V_307 )
goto V_309;
F_55 ( & V_305 -> V_44 , & V_3 -> V_312 ) ;
V_307 = 0 ;
V_309:
F_145 ( V_157 ) ;
return V_307 ;
}
void F_146 ( struct V_2 * V_3 , struct V_304 * V_305 )
{
struct V_306 * V_157 = V_3 -> V_88 -> V_157 ;
F_144 ( V_157 ) ;
if ( ! V_305 -> V_44 . V_308 || ! V_305 -> V_44 . V_51 )
goto V_309;
F_60 ( & V_305 -> V_44 ) ;
V_305 -> V_44 . V_308 = NULL ;
V_305 -> V_44 . V_51 = NULL ;
V_305 -> remove ( V_3 , V_305 ) ;
V_309:
F_145 ( V_157 ) ;
}
static void F_147 ( struct V_2 * V_3 )
{
struct V_304 * V_305 ;
while ( ! F_148 ( & V_3 -> V_312 ) ) {
V_305 = F_149 ( & V_3 -> V_312 , struct V_304 , V_44 ) ;
F_60 ( & V_305 -> V_44 ) ;
V_305 -> V_44 . V_308 = NULL ;
V_305 -> V_44 . V_51 = NULL ;
V_305 -> remove ( V_3 , V_305 ) ;
}
}
static void F_150 ( struct V_168 * V_88 , int V_15 )
{
struct V_2 * V_3 = V_88 -> V_313 ;
struct V_1 * V_14 , * V_314 ;
if ( ! V_3 )
return;
F_21 ( L_17 , V_88 , V_3 , V_15 ) ;
F_92 ( V_3 -> V_315 ) ;
F_147 ( V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_131 (chan, l, &conn->chan_l, list) {
F_61 ( V_14 ) ;
F_6 ( V_14 ) ;
F_69 ( V_14 , V_15 ) ;
F_50 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_51 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
F_151 ( V_3 -> V_164 ) ;
if ( V_3 -> V_258 & V_259 )
F_152 ( & V_3 -> V_264 ) ;
if ( F_111 ( V_316 , & V_88 -> V_83 ) ) {
F_152 ( & V_3 -> V_317 ) ;
F_153 ( V_3 ) ;
}
V_88 -> V_313 = NULL ;
V_3 -> V_164 = NULL ;
F_154 ( V_3 ) ;
}
static void F_155 ( struct V_52 * V_53 )
{
struct V_2 * V_3 = F_48 ( V_53 , struct V_2 ,
V_317 . V_53 ) ;
F_21 ( L_15 , V_3 ) ;
if ( F_111 ( V_316 , & V_3 -> V_88 -> V_83 ) ) {
F_153 ( V_3 ) ;
F_150 ( V_3 -> V_88 , V_62 ) ;
}
}
static struct V_2 * F_156 ( struct V_168 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_313 ;
struct V_117 * V_164 ;
if ( V_3 )
return V_3 ;
V_164 = F_157 ( V_88 ) ;
if ( ! V_164 )
return NULL ;
V_3 = F_53 ( sizeof( struct V_2 ) , V_45 ) ;
if ( ! V_3 ) {
F_151 ( V_164 ) ;
return NULL ;
}
F_57 ( & V_3 -> V_318 ) ;
V_88 -> V_313 = V_3 ;
V_3 -> V_88 = V_88 ;
F_158 ( V_3 -> V_88 ) ;
V_3 -> V_164 = V_164 ;
F_21 ( L_18 , V_88 , V_3 , V_164 ) ;
switch ( V_88 -> type ) {
case V_89 :
if ( V_88 -> V_157 -> V_319 ) {
V_3 -> V_320 = V_88 -> V_157 -> V_319 ;
break;
}
default:
V_3 -> V_320 = V_88 -> V_157 -> V_321 ;
break;
}
V_3 -> V_11 = & V_88 -> V_157 -> V_322 ;
V_3 -> V_287 = & V_88 -> V_287 ;
V_3 -> V_267 = 0 ;
F_159 ( & V_3 -> V_65 ) ;
F_54 ( & V_3 -> V_8 ) ;
F_160 ( & V_3 -> V_112 ) ;
F_160 ( & V_3 -> V_312 ) ;
if ( V_88 -> type == V_89 )
F_56 ( & V_3 -> V_317 , F_155 ) ;
else
F_56 ( & V_3 -> V_264 , F_142 ) ;
V_3 -> V_84 = V_85 ;
return V_3 ;
}
static void F_161 ( struct V_69 * V_318 )
{
struct V_2 * V_3 = F_48 ( V_318 , struct V_2 , V_318 ) ;
F_162 ( V_3 -> V_88 ) ;
F_41 ( V_3 ) ;
}
void F_163 ( struct V_2 * V_3 )
{
F_63 ( & V_3 -> V_318 ) ;
}
void F_154 ( struct V_2 * V_3 )
{
F_64 ( & V_3 -> V_318 , F_161 ) ;
}
static struct V_1 * F_164 ( int V_23 , T_3 V_10 ,
T_4 * V_11 ,
T_4 * V_287 )
{
struct V_1 * V_5 , * V_288 = NULL ;
F_134 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
if ( V_23 && V_5 -> V_23 != V_23 )
continue;
if ( V_5 -> V_10 == V_10 ) {
int V_289 , V_290 ;
int V_291 , V_292 ;
V_289 = ! F_12 ( & F_13 ( V_13 ) -> V_11 , V_11 ) ;
V_290 = ! F_12 ( & F_13 ( V_13 ) -> V_287 , V_287 ) ;
if ( V_289 && V_290 ) {
F_135 ( & V_16 ) ;
return V_5 ;
}
V_291 = ! F_12 ( & F_13 ( V_13 ) -> V_11 , V_293 ) ;
V_292 = ! F_12 ( & F_13 ( V_13 ) -> V_287 , V_293 ) ;
if ( ( V_289 && V_292 ) || ( V_291 && V_290 ) ||
( V_291 && V_292 ) )
V_288 = V_5 ;
}
}
F_135 ( & V_16 ) ;
return V_288 ;
}
int F_165 ( struct V_1 * V_14 , T_3 V_10 , T_1 V_4 ,
T_4 * V_287 , T_2 V_323 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
T_4 * V_11 = & F_13 ( V_13 ) -> V_11 ;
struct V_2 * V_3 ;
struct V_168 * V_88 ;
struct V_306 * V_157 ;
T_7 V_151 ;
int V_15 ;
F_21 ( L_19 , V_11 , V_287 ,
V_323 , F_67 ( V_10 ) ) ;
V_157 = F_166 ( V_287 , V_11 ) ;
if ( ! V_157 )
return - V_324 ;
F_144 ( V_157 ) ;
F_6 ( V_14 ) ;
if ( ( F_67 ( V_10 ) & 0x0101 ) != 0x0001 && ! V_4 &&
V_14 -> V_86 != V_141 ) {
V_15 = - V_20 ;
goto V_18;
}
if ( V_14 -> V_86 == V_87 && ! ( V_10 || V_4 ) ) {
V_15 = - V_20 ;
goto V_18;
}
switch ( V_14 -> V_119 ) {
case V_120 :
break;
case V_121 :
case V_125 :
if ( ! V_270 )
break;
default:
V_15 = - V_325 ;
goto V_18;
}
switch ( V_14 -> V_23 ) {
case V_59 :
case V_130 :
case V_57 :
V_15 = 0 ;
goto V_18;
case V_56 :
V_15 = - V_326 ;
goto V_18;
case V_68 :
case V_327 :
break;
default:
V_15 = - V_328 ;
goto V_18;
}
F_24 ( V_13 ) ;
F_138 ( & F_13 ( V_13 ) -> V_287 , V_287 ) ;
F_25 ( V_13 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_4 ;
V_151 = F_81 ( V_14 ) ;
if ( V_14 -> V_6 == V_92 )
V_88 = F_167 ( V_157 , V_89 , V_287 , V_323 ,
V_14 -> V_60 , V_151 ) ;
else
V_88 = F_167 ( V_157 , V_128 , V_287 , V_323 ,
V_14 -> V_60 , V_151 ) ;
if ( F_113 ( V_88 ) ) {
V_15 = F_168 ( V_88 ) ;
goto V_18;
}
V_3 = F_156 ( V_88 ) ;
if ( ! V_3 ) {
F_71 ( V_88 ) ;
V_15 = - V_46 ;
goto V_18;
}
if ( V_88 -> type == V_89 ) {
V_15 = 0 ;
if ( ! F_148 ( & V_3 -> V_112 ) ) {
V_15 = - V_329 ;
F_71 ( V_88 ) ;
}
if ( V_15 )
goto V_18;
}
F_138 ( V_11 , V_3 -> V_11 ) ;
F_50 ( V_14 ) ;
F_68 ( V_3 , V_14 ) ;
F_6 ( V_14 ) ;
F_23 ( V_14 , V_59 ) ;
F_77 ( V_14 , V_13 -> V_129 ) ;
if ( V_88 -> V_23 == V_56 ) {
if ( V_14 -> V_86 != V_87 ) {
F_70 ( V_14 ) ;
if ( F_82 ( V_14 ) )
F_23 ( V_14 , V_56 ) ;
} else
F_127 ( V_14 ) ;
}
V_15 = 0 ;
V_18:
F_50 ( V_14 ) ;
F_145 ( V_157 ) ;
F_169 ( V_157 ) ;
return V_15 ;
}
int F_170 ( struct V_26 * V_13 )
{
struct V_1 * V_14 = F_171 ( V_13 ) -> V_14 ;
F_172 ( V_330 , V_331 ) ;
int V_15 = 0 ;
int V_332 = V_333 / 5 ;
F_173 ( F_174 ( V_13 ) , & V_330 ) ;
F_175 ( V_334 ) ;
while ( V_14 -> V_335 > 0 && V_14 -> V_3 ) {
if ( ! V_332 )
V_332 = V_333 / 5 ;
if ( F_176 ( V_331 ) ) {
V_15 = F_177 ( V_332 ) ;
break;
}
F_25 ( V_13 ) ;
V_332 = F_178 ( V_332 ) ;
F_24 ( V_13 ) ;
F_175 ( V_334 ) ;
V_15 = F_179 ( V_13 ) ;
if ( V_15 )
break;
}
F_175 ( V_336 ) ;
F_180 ( F_174 ( V_13 ) , & V_330 ) ;
return V_15 ;
}
static void F_181 ( struct V_52 * V_53 )
{
struct V_1 * V_14 = F_48 ( V_53 , struct V_1 ,
V_28 . V_53 ) ;
F_21 ( L_3 , V_14 ) ;
F_6 ( V_14 ) ;
if ( ! V_14 -> V_3 ) {
F_50 ( V_14 ) ;
F_51 ( V_14 ) ;
return;
}
F_123 ( V_14 , NULL , NULL , V_337 ) ;
F_50 ( V_14 ) ;
F_51 ( V_14 ) ;
}
static void F_182 ( struct V_52 * V_53 )
{
struct V_1 * V_14 = F_48 ( V_53 , struct V_1 ,
V_30 . V_53 ) ;
F_21 ( L_3 , V_14 ) ;
F_6 ( V_14 ) ;
if ( ! V_14 -> V_3 ) {
F_50 ( V_14 ) ;
F_51 ( V_14 ) ;
return;
}
F_123 ( V_14 , NULL , NULL , V_338 ) ;
F_50 ( V_14 ) ;
F_51 ( V_14 ) ;
}
static void F_183 ( struct V_1 * V_14 ,
struct V_33 * V_339 )
{
struct V_32 * V_36 ;
struct V_173 * V_37 ;
F_21 ( L_20 , V_14 , V_339 ) ;
if ( F_90 ( V_14 ) )
return;
F_184 ( V_339 , & V_14 -> V_126 ) ;
while ( ! F_185 ( & V_14 -> V_126 ) ) {
V_36 = F_186 ( & V_14 -> V_126 ) ;
F_36 ( V_36 ) -> V_37 . V_241 = 1 ;
V_37 = & F_36 ( V_36 ) -> V_37 ;
V_37 -> V_174 = 0 ;
V_37 -> V_38 = V_14 -> V_340 ;
F_101 ( V_14 , V_37 , V_36 ) ;
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_109 ( 0 , ( T_2 * ) V_36 -> V_156 , V_36 -> V_155 ) ;
F_103 ( V_73 , F_108 ( V_36 , V_217 ) ) ;
}
F_91 ( V_14 , V_36 ) ;
F_21 ( L_21 , V_37 -> V_38 ) ;
V_14 -> V_340 = F_187 ( V_14 , V_14 -> V_340 ) ;
V_14 -> V_341 ++ ;
}
}
static int F_188 ( struct V_1 * V_14 )
{
struct V_32 * V_36 , * V_342 ;
struct V_173 * V_37 ;
int V_343 = 0 ;
F_21 ( L_3 , V_14 ) ;
if ( V_14 -> V_23 != V_56 )
return - V_344 ;
if ( F_73 ( V_249 , & V_14 -> V_220 ) )
return 0 ;
if ( F_90 ( V_14 ) )
return 0 ;
while ( V_14 -> V_345 &&
V_14 -> V_335 < V_14 -> V_346 &&
V_14 -> V_245 == V_246 ) {
V_36 = V_14 -> V_345 ;
F_36 ( V_36 ) -> V_37 . V_241 = 1 ;
V_37 = & F_36 ( V_36 ) -> V_37 ;
if ( F_111 ( V_219 , & V_14 -> V_220 ) )
V_37 -> V_177 = 1 ;
V_37 -> V_174 = V_14 -> V_227 ;
V_14 -> V_225 = V_14 -> V_227 ;
V_37 -> V_38 = V_14 -> V_340 ;
F_101 ( V_14 , V_37 , V_36 ) ;
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_109 ( 0 , ( T_2 * ) V_36 -> V_156 , V_36 -> V_155 ) ;
F_103 ( V_73 , F_108 ( V_36 , V_217 ) ) ;
}
V_342 = F_189 ( V_36 , V_45 ) ;
if ( ! V_342 )
break;
F_28 ( V_14 ) ;
V_14 -> V_340 = F_187 ( V_14 , V_14 -> V_340 ) ;
V_14 -> V_335 ++ ;
V_14 -> V_341 ++ ;
V_343 ++ ;
if ( F_190 ( & V_14 -> V_126 , V_36 ) )
V_14 -> V_345 = NULL ;
else
V_14 -> V_345 = F_191 ( & V_14 -> V_126 , V_36 ) ;
F_91 ( V_14 , V_342 ) ;
F_21 ( L_21 , V_37 -> V_38 ) ;
}
F_21 ( L_22 , V_343 ,
V_14 -> V_335 , F_192 ( & V_14 -> V_126 ) ) ;
return V_343 ;
}
static void F_193 ( struct V_1 * V_14 )
{
struct V_173 V_37 ;
struct V_32 * V_36 ;
struct V_32 * V_342 ;
T_1 V_35 ;
F_21 ( L_3 , V_14 ) ;
if ( F_73 ( V_249 , & V_14 -> V_220 ) )
return;
if ( F_90 ( V_14 ) )
return;
while ( V_14 -> V_124 . V_34 != V_48 ) {
V_35 = F_44 ( & V_14 -> V_124 ) ;
V_36 = F_34 ( & V_14 -> V_126 , V_35 ) ;
if ( ! V_36 ) {
F_21 ( L_23 ,
V_35 ) ;
continue;
}
F_36 ( V_36 ) -> V_37 . V_241 ++ ;
V_37 = F_36 ( V_36 ) -> V_37 ;
if ( V_14 -> V_75 != 0 &&
F_36 ( V_36 ) -> V_37 . V_241 > V_14 -> V_75 ) {
F_21 ( L_24 , V_14 -> V_75 ) ;
F_78 ( V_14 , V_277 ) ;
F_45 ( & V_14 -> V_124 ) ;
break;
}
V_37 . V_174 = V_14 -> V_227 ;
if ( F_111 ( V_219 , & V_14 -> V_220 ) )
V_37 . V_177 = 1 ;
else
V_37 . V_177 = 0 ;
if ( F_194 ( V_36 ) ) {
V_342 = F_195 ( V_36 , V_45 ) ;
} else {
V_342 = F_189 ( V_36 , V_45 ) ;
}
if ( ! V_342 ) {
F_45 ( & V_14 -> V_124 ) ;
break;
}
if ( F_73 ( V_207 , & V_14 -> V_83 ) ) {
F_102 ( F_99 ( & V_37 ) ,
V_342 -> V_156 + V_211 ) ;
} else {
F_103 ( F_100 ( & V_37 ) ,
V_342 -> V_156 + V_211 ) ;
}
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_109 ( 0 , ( T_2 * ) V_342 -> V_156 , V_342 -> V_155 ) ;
F_103 ( V_73 , F_108 ( V_342 ,
V_217 ) ) ;
}
F_91 ( V_14 , V_342 ) ;
F_21 ( L_25 , V_37 . V_38 ) ;
V_14 -> V_225 = V_14 -> V_227 ;
}
}
static void F_196 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
F_21 ( L_11 , V_14 , V_37 ) ;
F_46 ( & V_14 -> V_124 , V_37 -> V_174 ) ;
F_193 ( V_14 ) ;
}
static void F_197 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
struct V_32 * V_36 ;
F_21 ( L_11 , V_14 , V_37 ) ;
if ( V_37 -> V_182 )
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_45 ( & V_14 -> V_124 ) ;
if ( F_73 ( V_249 , & V_14 -> V_220 ) )
return;
if ( V_14 -> V_335 ) {
F_35 (&chan->tx_q, skb) {
if ( F_36 ( V_36 ) -> V_37 . V_38 == V_37 -> V_174 ||
V_36 == V_14 -> V_345 )
break;
}
F_198 (&chan->tx_q, skb) {
if ( V_36 == V_14 -> V_345 )
break;
F_46 ( & V_14 -> V_124 ,
F_36 ( V_36 ) -> V_37 . V_38 ) ;
}
F_193 ( V_14 ) ;
}
}
static void F_199 ( struct V_1 * V_14 )
{
struct V_173 V_37 ;
T_1 V_347 = F_200 ( V_14 , V_14 -> V_227 ,
V_14 -> V_225 ) ;
int V_348 ;
F_21 ( L_26 ,
V_14 , V_14 -> V_225 , V_14 -> V_227 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
if ( F_73 ( V_226 , & V_14 -> V_220 ) &&
V_14 -> V_247 == V_349 ) {
F_75 ( V_14 ) ;
V_37 . V_185 = V_223 ;
V_37 . V_174 = V_14 -> V_227 ;
F_110 ( V_14 , & V_37 ) ;
} else {
if ( ! F_73 ( V_249 , & V_14 -> V_220 ) ) {
F_188 ( V_14 ) ;
if ( V_14 -> V_227 == V_14 -> V_225 )
V_347 = 0 ;
}
V_348 = V_14 -> V_80 ;
V_348 += V_348 << 1 ;
V_348 >>= 2 ;
F_21 ( L_27 , V_347 ,
V_348 ) ;
if ( V_347 >= V_348 ) {
F_75 ( V_14 ) ;
V_37 . V_185 = V_221 ;
V_37 . V_174 = V_14 -> V_227 ;
F_110 ( V_14 , & V_37 ) ;
V_347 = 0 ;
}
if ( V_347 )
F_201 ( V_14 ) ;
}
}
static inline int F_202 ( struct V_1 * V_14 ,
struct V_350 * V_351 , int V_155 ,
int V_352 , struct V_32 * V_36 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * * V_353 ;
int V_343 = 0 ;
if ( F_203 ( F_108 ( V_36 , V_352 ) , V_351 -> V_354 , V_352 ) )
return - V_355 ;
V_343 += V_352 ;
V_155 -= V_352 ;
V_353 = & F_204 ( V_36 ) -> V_356 ;
while ( V_155 ) {
struct V_32 * V_275 ;
V_352 = F_205 (unsigned int, conn->mtu, len) ;
V_275 = V_14 -> V_24 -> V_357 ( V_14 , V_352 ,
V_351 -> V_358 & V_359 ) ;
if ( F_113 ( V_275 ) )
return F_168 ( V_275 ) ;
* V_353 = V_275 ;
if ( F_203 ( F_108 ( * V_353 , V_352 ) , V_351 -> V_354 , V_352 ) )
return - V_355 ;
( * V_353 ) -> V_162 = V_36 -> V_162 ;
V_343 += V_352 ;
V_155 -= V_352 ;
V_36 -> V_155 += ( * V_353 ) -> V_155 ;
V_36 -> V_360 += ( * V_353 ) -> V_155 ;
V_353 = & ( * V_353 ) -> V_308 ;
}
return V_343 ;
}
static struct V_32 * F_206 ( struct V_1 * V_14 ,
struct V_350 * V_351 , T_6 V_155 ,
T_8 V_162 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_352 , V_216 = V_211 + V_361 ;
struct V_214 * V_215 ;
F_21 ( L_28 , V_14 , V_155 , V_162 ) ;
V_352 = F_205 (unsigned int, (conn->mtu - hlen), len) ;
V_36 = V_14 -> V_24 -> V_357 ( V_14 , V_352 + V_216 ,
V_351 -> V_358 & V_359 ) ;
if ( F_113 ( V_36 ) )
return V_36 ;
V_36 -> V_162 = V_162 ;
V_215 = (struct V_214 * ) F_108 ( V_36 , V_211 ) ;
V_215 -> V_4 = F_16 ( V_14 -> V_6 ) ;
V_215 -> V_155 = F_16 ( V_155 + V_361 ) ;
F_207 ( V_14 -> V_10 , F_108 ( V_36 , V_361 ) ) ;
V_15 = F_202 ( V_14 , V_351 , V_155 , V_352 , V_36 ) ;
if ( F_208 ( V_15 < 0 ) ) {
F_92 ( V_36 ) ;
return F_107 ( V_15 ) ;
}
return V_36 ;
}
static struct V_32 * F_209 ( struct V_1 * V_14 ,
struct V_350 * V_351 , T_6 V_155 ,
T_8 V_162 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_352 ;
struct V_214 * V_215 ;
F_21 ( L_29 , V_14 , V_155 ) ;
V_352 = F_205 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_36 = V_14 -> V_24 -> V_357 ( V_14 , V_352 + V_211 ,
V_351 -> V_358 & V_359 ) ;
if ( F_113 ( V_36 ) )
return V_36 ;
V_36 -> V_162 = V_162 ;
V_215 = (struct V_214 * ) F_108 ( V_36 , V_211 ) ;
V_215 -> V_4 = F_16 ( V_14 -> V_6 ) ;
V_215 -> V_155 = F_16 ( V_155 ) ;
V_15 = F_202 ( V_14 , V_351 , V_155 , V_352 , V_36 ) ;
if ( F_208 ( V_15 < 0 ) ) {
F_92 ( V_36 ) ;
return F_107 ( V_15 ) ;
}
return V_36 ;
}
static struct V_32 * F_210 ( struct V_1 * V_14 ,
struct V_350 * V_351 , T_6 V_155 ,
T_1 V_362 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_352 , V_216 ;
struct V_214 * V_215 ;
F_21 ( L_29 , V_14 , V_155 ) ;
if ( ! V_3 )
return F_107 ( - V_344 ) ;
V_216 = F_104 ( V_14 ) ;
if ( V_362 )
V_216 += V_363 ;
if ( V_14 -> V_73 == V_74 )
V_216 += V_217 ;
V_352 = F_205 (unsigned int, (conn->mtu - hlen), len) ;
V_36 = V_14 -> V_24 -> V_357 ( V_14 , V_352 + V_216 ,
V_351 -> V_358 & V_359 ) ;
if ( F_113 ( V_36 ) )
return V_36 ;
V_215 = (struct V_214 * ) F_108 ( V_36 , V_211 ) ;
V_215 -> V_4 = F_16 ( V_14 -> V_6 ) ;
V_215 -> V_155 = F_16 ( V_155 + ( V_216 - V_211 ) ) ;
if ( F_73 ( V_207 , & V_14 -> V_83 ) )
F_102 ( 0 , F_108 ( V_36 , V_208 ) ) ;
else
F_103 ( 0 , F_108 ( V_36 , V_209 ) ) ;
if ( V_362 )
F_103 ( V_362 , F_108 ( V_36 , V_363 ) ) ;
V_15 = F_202 ( V_14 , V_351 , V_155 , V_352 , V_36 ) ;
if ( F_208 ( V_15 < 0 ) ) {
F_92 ( V_36 ) ;
return F_107 ( V_15 ) ;
}
F_36 ( V_36 ) -> V_37 . V_73 = V_14 -> V_73 ;
F_36 ( V_36 ) -> V_37 . V_241 = 0 ;
return V_36 ;
}
static int F_211 ( struct V_1 * V_14 ,
struct V_33 * V_364 ,
struct V_350 * V_351 , T_6 V_155 )
{
struct V_32 * V_36 ;
T_1 V_365 ;
T_6 V_366 ;
T_2 V_188 ;
F_21 ( L_30 , V_14 , V_351 , V_155 ) ;
V_366 = V_14 -> V_3 -> V_320 ;
if ( ! V_14 -> V_169 )
V_366 = F_205 ( T_6 , V_366 , V_367 ) ;
if ( V_14 -> V_73 )
V_366 -= V_217 ;
V_366 -= F_104 ( V_14 ) ;
V_366 = F_205 ( T_6 , V_366 , V_14 -> V_368 ) ;
if ( V_155 <= V_366 ) {
V_188 = V_369 ;
V_365 = 0 ;
V_366 = V_155 ;
} else {
V_188 = V_370 ;
V_365 = V_155 ;
V_366 -= V_363 ;
}
while ( V_155 > 0 ) {
V_36 = F_210 ( V_14 , V_351 , V_366 , V_365 ) ;
if ( F_113 ( V_36 ) ) {
F_212 ( V_364 ) ;
return F_168 ( V_36 ) ;
}
F_36 ( V_36 ) -> V_37 . V_188 = V_188 ;
F_213 ( V_364 , V_36 ) ;
V_155 -= V_366 ;
if ( V_365 ) {
V_365 = 0 ;
V_366 += V_363 ;
}
if ( V_155 <= V_366 ) {
V_188 = V_371 ;
V_366 = V_155 ;
} else {
V_188 = V_372 ;
}
}
return 0 ;
}
int F_214 ( struct V_1 * V_14 , struct V_350 * V_351 , T_6 V_155 ,
T_8 V_162 )
{
struct V_32 * V_36 ;
int V_15 ;
struct V_33 V_364 ;
if ( V_14 -> V_86 == V_93 ) {
V_36 = F_206 ( V_14 , V_351 , V_155 , V_162 ) ;
if ( F_113 ( V_36 ) )
return F_168 ( V_36 ) ;
F_91 ( V_14 , V_36 ) ;
return V_155 ;
}
switch ( V_14 -> V_119 ) {
case V_120 :
if ( V_155 > V_14 -> V_90 )
return - V_373 ;
V_36 = F_209 ( V_14 , V_351 , V_155 , V_162 ) ;
if ( F_113 ( V_36 ) )
return F_168 ( V_36 ) ;
F_91 ( V_14 , V_36 ) ;
V_15 = V_155 ;
break;
case V_121 :
case V_125 :
if ( V_155 > V_14 -> V_90 ) {
V_15 = - V_373 ;
break;
}
F_215 ( & V_364 ) ;
V_15 = F_211 ( V_14 , & V_364 , V_351 , V_155 ) ;
if ( V_14 -> V_23 != V_56 ) {
F_212 ( & V_364 ) ;
V_15 = - V_344 ;
}
if ( V_15 )
break;
if ( V_14 -> V_119 == V_121 )
F_123 ( V_14 , NULL , & V_364 , V_374 ) ;
else
F_183 ( V_14 , & V_364 ) ;
V_15 = V_155 ;
F_212 ( & V_364 ) ;
break;
default:
F_21 ( L_31 , V_14 -> V_119 ) ;
V_15 = - V_328 ;
}
return V_15 ;
}
static void F_216 ( struct V_1 * V_14 , T_1 V_38 )
{
struct V_173 V_37 ;
T_1 V_35 ;
F_21 ( L_32 , V_14 , V_38 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
V_37 . V_185 = V_224 ;
for ( V_35 = V_14 -> V_242 ; V_35 != V_38 ;
V_35 = F_187 ( V_14 , V_35 ) ) {
if ( ! F_34 ( & V_14 -> V_122 , V_35 ) ) {
V_37 . V_174 = V_35 ;
F_110 ( V_14 , & V_37 ) ;
F_46 ( & V_14 -> V_123 , V_35 ) ;
}
}
V_14 -> V_242 = F_187 ( V_14 , V_38 ) ;
}
static void F_217 ( struct V_1 * V_14 )
{
struct V_173 V_37 ;
F_21 ( L_3 , V_14 ) ;
if ( V_14 -> V_123 . V_49 == V_48 )
return;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
V_37 . V_185 = V_224 ;
V_37 . V_174 = V_14 -> V_123 . V_49 ;
F_110 ( V_14 , & V_37 ) ;
}
static void F_218 ( struct V_1 * V_14 , T_1 V_38 )
{
struct V_173 V_37 ;
T_1 V_375 ;
T_1 V_35 ;
F_21 ( L_32 , V_14 , V_38 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
V_37 . V_185 = V_224 ;
V_375 = V_14 -> V_123 . V_34 ;
do {
V_35 = F_44 ( & V_14 -> V_123 ) ;
if ( V_35 == V_38 || V_35 == V_48 )
break;
V_37 . V_174 = V_35 ;
F_110 ( V_14 , & V_37 ) ;
F_46 ( & V_14 -> V_123 , V_35 ) ;
} while ( V_14 -> V_123 . V_34 != V_375 );
}
static void F_219 ( struct V_1 * V_14 , T_1 V_174 )
{
struct V_32 * V_376 ;
T_1 V_377 ;
F_21 ( L_33 , V_14 , V_174 ) ;
if ( V_14 -> V_335 == 0 || V_174 == V_14 -> V_378 )
return;
F_21 ( L_34 ,
V_14 -> V_378 , V_14 -> V_335 ) ;
for ( V_377 = V_14 -> V_378 ; V_377 != V_174 ;
V_377 = F_187 ( V_14 , V_377 ) ) {
V_376 = F_34 ( & V_14 -> V_126 , V_377 ) ;
if ( V_376 ) {
F_220 ( V_376 , & V_14 -> V_126 ) ;
F_92 ( V_376 ) ;
V_14 -> V_335 -- ;
}
}
V_14 -> V_378 = V_174 ;
if ( V_14 -> V_335 == 0 )
F_33 ( V_14 ) ;
F_21 ( L_35 , V_14 -> V_335 ) ;
}
static void F_221 ( struct V_1 * V_14 )
{
F_21 ( L_3 , V_14 ) ;
V_14 -> V_242 = V_14 -> V_227 ;
F_45 ( & V_14 -> V_123 ) ;
F_76 ( & V_14 -> V_122 ) ;
V_14 -> V_247 = V_349 ;
}
static void F_222 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_33 * V_339 , T_2 V_379 )
{
F_21 ( L_36 , V_14 , V_37 , V_339 ,
V_379 ) ;
switch ( V_379 ) {
case V_374 :
if ( V_14 -> V_345 == NULL )
V_14 -> V_345 = F_223 ( V_339 ) ;
F_184 ( V_339 , & V_14 -> V_126 ) ;
F_188 ( V_14 ) ;
break;
case V_380 :
F_21 ( L_37 ) ;
F_58 ( V_226 , & V_14 -> V_220 ) ;
if ( V_14 -> V_247 == V_381 ) {
F_221 ( V_14 ) ;
}
F_199 ( V_14 ) ;
break;
case V_382 :
F_21 ( L_38 ) ;
F_112 ( V_226 , & V_14 -> V_220 ) ;
if ( F_73 ( V_222 , & V_14 -> V_220 ) ) {
struct V_173 V_383 ;
memset ( & V_383 , 0 , sizeof( V_383 ) ) ;
V_383 . V_181 = 1 ;
V_383 . V_185 = V_221 ;
V_383 . V_182 = 1 ;
V_383 . V_174 = V_14 -> V_227 ;
F_110 ( V_14 , & V_383 ) ;
V_14 -> V_240 = 1 ;
F_32 ( V_14 ) ;
V_14 -> V_245 = V_384 ;
}
break;
case V_385 :
F_219 ( V_14 , V_37 -> V_174 ) ;
break;
case V_253 :
F_114 ( V_14 , 1 ) ;
V_14 -> V_240 = 1 ;
F_32 ( V_14 ) ;
F_75 ( V_14 ) ;
V_14 -> V_245 = V_384 ;
break;
case V_338 :
F_114 ( V_14 , 1 ) ;
V_14 -> V_240 = 1 ;
F_32 ( V_14 ) ;
V_14 -> V_245 = V_384 ;
break;
case V_386 :
break;
default:
break;
}
}
static void F_224 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_33 * V_339 , T_2 V_379 )
{
F_21 ( L_36 , V_14 , V_37 , V_339 ,
V_379 ) ;
switch ( V_379 ) {
case V_374 :
if ( V_14 -> V_345 == NULL )
V_14 -> V_345 = F_223 ( V_339 ) ;
F_184 ( V_339 , & V_14 -> V_126 ) ;
break;
case V_380 :
F_21 ( L_37 ) ;
F_58 ( V_226 , & V_14 -> V_220 ) ;
if ( V_14 -> V_247 == V_381 ) {
F_221 ( V_14 ) ;
}
F_199 ( V_14 ) ;
break;
case V_382 :
F_21 ( L_38 ) ;
F_112 ( V_226 , & V_14 -> V_220 ) ;
if ( F_73 ( V_222 , & V_14 -> V_220 ) ) {
struct V_173 V_383 ;
memset ( & V_383 , 0 , sizeof( V_383 ) ) ;
V_383 . V_181 = 1 ;
V_383 . V_185 = V_221 ;
V_383 . V_182 = 1 ;
V_383 . V_174 = V_14 -> V_227 ;
F_110 ( V_14 , & V_383 ) ;
V_14 -> V_240 = 1 ;
F_32 ( V_14 ) ;
V_14 -> V_245 = V_384 ;
}
break;
case V_385 :
F_219 ( V_14 , V_37 -> V_174 ) ;
case V_386 :
if ( V_37 && V_37 -> V_177 ) {
F_74 ( V_14 ) ;
if ( V_14 -> V_335 > 0 )
F_28 ( V_14 ) ;
V_14 -> V_240 = 0 ;
V_14 -> V_245 = V_246 ;
F_21 ( L_39 , V_14 -> V_245 ) ;
}
break;
case V_253 :
break;
case V_337 :
if ( V_14 -> V_75 == 0 || V_14 -> V_240 < V_14 -> V_75 ) {
F_114 ( V_14 , 1 ) ;
F_32 ( V_14 ) ;
V_14 -> V_240 ++ ;
} else {
F_78 ( V_14 , V_387 ) ;
}
break;
default:
break;
}
}
static void F_123 ( struct V_1 * V_14 , struct V_173 * V_37 ,
struct V_33 * V_339 , T_2 V_379 )
{
F_21 ( L_40 ,
V_14 , V_37 , V_339 , V_379 , V_14 -> V_245 ) ;
switch ( V_14 -> V_245 ) {
case V_246 :
F_222 ( V_14 , V_37 , V_339 , V_379 ) ;
break;
case V_384 :
F_224 ( V_14 , V_37 , V_339 , V_379 ) ;
break;
default:
break;
}
}
static void F_225 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
F_21 ( L_11 , V_14 , V_37 ) ;
F_123 ( V_14 , V_37 , NULL , V_385 ) ;
}
static void F_226 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
F_21 ( L_11 , V_14 , V_37 ) ;
F_123 ( V_14 , V_37 , NULL , V_386 ) ;
}
static void F_227 ( struct V_2 * V_3 , struct V_32 * V_36 )
{
struct V_32 * V_388 ;
struct V_1 * V_14 ;
F_21 ( L_15 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
struct V_26 * V_13 = V_14 -> V_13 ;
if ( V_14 -> V_86 != V_141 )
continue;
if ( V_36 -> V_13 == V_13 )
continue;
V_388 = F_189 ( V_36 , V_45 ) ;
if ( ! V_388 )
continue;
if ( V_14 -> V_24 -> V_389 ( V_14 , V_388 ) )
F_92 ( V_388 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static struct V_32 * F_87 ( struct V_2 * V_3 , T_2 V_154 ,
T_2 V_9 , T_1 V_390 , void * V_156 )
{
struct V_32 * V_36 , * * V_353 ;
struct V_391 * V_392 ;
struct V_214 * V_215 ;
int V_155 , V_352 ;
F_21 ( L_41 ,
V_3 , V_154 , V_9 , V_390 ) ;
if ( V_3 -> V_320 < V_211 + V_393 )
return NULL ;
V_155 = V_211 + V_393 + V_390 ;
V_352 = F_205 (unsigned int, conn->mtu, len) ;
V_36 = F_106 ( V_352 , V_45 ) ;
if ( ! V_36 )
return NULL ;
V_215 = (struct V_214 * ) F_108 ( V_36 , V_211 ) ;
V_215 -> V_155 = F_16 ( V_393 + V_390 ) ;
if ( V_3 -> V_88 -> type == V_89 )
V_215 -> V_4 = F_79 ( V_394 ) ;
else
V_215 -> V_4 = F_79 ( V_99 ) ;
V_392 = (struct V_391 * ) F_108 ( V_36 , V_393 ) ;
V_392 -> V_154 = V_154 ;
V_392 -> V_9 = V_9 ;
V_392 -> V_155 = F_16 ( V_390 ) ;
if ( V_390 ) {
V_352 -= V_211 + V_393 ;
memcpy ( F_108 ( V_36 , V_352 ) , V_156 , V_352 ) ;
V_156 += V_352 ;
}
V_155 -= V_36 -> V_155 ;
V_353 = & F_204 ( V_36 ) -> V_356 ;
while ( V_155 ) {
V_352 = F_205 (unsigned int, conn->mtu, len) ;
* V_353 = F_106 ( V_352 , V_45 ) ;
if ( ! * V_353 )
goto V_395;
memcpy ( F_108 ( * V_353 , V_352 ) , V_156 , V_352 ) ;
V_155 -= V_352 ;
V_156 += V_352 ;
V_353 = & ( * V_353 ) -> V_308 ;
}
return V_36 ;
V_395:
F_92 ( V_36 ) ;
return NULL ;
}
static inline int F_228 ( void * * V_396 , int * type , int * V_397 ,
unsigned long * V_398 )
{
struct V_399 * V_400 = * V_396 ;
int V_155 ;
V_155 = V_401 + V_400 -> V_155 ;
* V_396 += V_155 ;
* type = V_400 -> type ;
* V_397 = V_400 -> V_155 ;
switch ( V_400 -> V_155 ) {
case 1 :
* V_398 = * ( ( T_2 * ) V_400 -> V_398 ) ;
break;
case 2 :
* V_398 = F_98 ( V_400 -> V_398 ) ;
break;
case 4 :
* V_398 = F_96 ( V_400 -> V_398 ) ;
break;
default:
* V_398 = ( unsigned long ) V_400 -> V_398 ;
break;
}
F_21 ( L_42 , * type , V_400 -> V_155 , * V_398 ) ;
return V_155 ;
}
static void F_229 ( void * * V_396 , T_2 type , T_2 V_155 , unsigned long V_398 )
{
struct V_399 * V_400 = * V_396 ;
F_21 ( L_42 , type , V_155 , V_398 ) ;
V_400 -> type = type ;
V_400 -> V_155 = V_155 ;
switch ( V_155 ) {
case 1 :
* ( ( T_2 * ) V_400 -> V_398 ) = V_398 ;
break;
case 2 :
F_103 ( V_398 , V_400 -> V_398 ) ;
break;
case 4 :
F_102 ( V_398 , V_400 -> V_398 ) ;
break;
default:
memcpy ( V_400 -> V_398 , ( void * ) V_398 , V_155 ) ;
break;
}
* V_396 += V_401 + V_155 ;
}
static void F_230 ( void * * V_396 , struct V_1 * V_14 )
{
struct V_402 V_403 ;
switch ( V_14 -> V_119 ) {
case V_121 :
V_403 . V_152 = V_14 -> V_100 ;
V_403 . V_404 = V_14 -> V_102 ;
V_403 . V_405 = F_16 ( V_14 -> V_104 ) ;
V_403 . V_406 = F_231 ( V_14 -> V_106 ) ;
V_403 . V_407 = F_232 ( V_109 ) ;
V_403 . V_408 = F_232 ( V_111 ) ;
break;
case V_125 :
V_403 . V_152 = 1 ;
V_403 . V_404 = V_103 ;
V_403 . V_405 = F_16 ( V_14 -> V_104 ) ;
V_403 . V_406 = F_231 ( V_14 -> V_106 ) ;
V_403 . V_407 = 0 ;
V_403 . V_408 = 0 ;
break;
default:
return;
}
F_229 ( V_396 , V_409 , sizeof( V_403 ) ,
( unsigned long ) & V_403 ) ;
}
static void F_233 ( struct V_52 * V_53 )
{
struct V_1 * V_14 = F_48 ( V_53 , struct V_1 ,
V_410 . V_53 ) ;
T_1 V_347 ;
F_21 ( L_3 , V_14 ) ;
F_6 ( V_14 ) ;
V_347 = F_200 ( V_14 , V_14 -> V_227 ,
V_14 -> V_225 ) ;
if ( V_347 )
F_114 ( V_14 , 0 ) ;
F_50 ( V_14 ) ;
F_51 ( V_14 ) ;
}
int F_234 ( struct V_1 * V_14 )
{
int V_15 ;
V_14 -> V_340 = 0 ;
V_14 -> V_242 = 0 ;
V_14 -> V_378 = 0 ;
V_14 -> V_335 = 0 ;
V_14 -> V_227 = 0 ;
V_14 -> V_341 = 0 ;
V_14 -> V_225 = 0 ;
V_14 -> V_411 = NULL ;
V_14 -> V_412 = NULL ;
V_14 -> V_365 = 0 ;
F_235 ( & V_14 -> V_126 ) ;
V_14 -> V_413 = 0 ;
V_14 -> V_414 = 0 ;
V_14 -> V_165 = V_166 ;
V_14 -> V_250 = V_251 ;
if ( V_14 -> V_119 != V_121 )
return 0 ;
V_14 -> V_247 = V_349 ;
V_14 -> V_245 = V_246 ;
F_56 ( & V_14 -> V_30 , F_182 ) ;
F_56 ( & V_14 -> V_28 , F_181 ) ;
F_56 ( & V_14 -> V_410 , F_233 ) ;
F_235 ( & V_14 -> V_122 ) ;
V_15 = F_37 ( & V_14 -> V_123 , V_14 -> V_77 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_37 ( & V_14 -> V_124 , V_14 -> V_346 ) ;
if ( V_15 < 0 )
F_40 ( & V_14 -> V_123 ) ;
return V_15 ;
}
static inline T_7 F_236 ( T_7 V_119 , T_5 V_415 )
{
switch ( V_119 ) {
case V_125 :
case V_121 :
if ( F_129 ( V_119 , V_415 ) )
return V_119 ;
default:
return V_120 ;
}
}
static inline bool F_237 ( struct V_1 * V_14 )
{
return V_229 && V_14 -> V_3 -> V_267 & V_416 ;
}
static inline bool F_238 ( struct V_1 * V_14 )
{
return V_229 && V_14 -> V_3 -> V_267 & V_417 ;
}
static void F_239 ( struct V_1 * V_14 ,
struct V_418 * V_419 )
{
if ( V_14 -> V_413 && V_14 -> V_169 ) {
T_10 V_420 = V_14 -> V_169 -> V_157 -> V_421 ;
V_420 = F_240 ( V_420 , 1000 ) ;
V_420 = 3 * V_420 + 500 ;
if ( V_420 > 0xffff )
V_420 = 0xffff ;
V_419 -> V_29 = F_16 ( ( T_1 ) V_420 ) ;
V_419 -> V_31 = V_419 -> V_29 ;
} else {
V_419 -> V_29 = F_79 ( V_422 ) ;
V_419 -> V_31 = F_79 ( V_423 ) ;
}
}
static inline void F_241 ( struct V_1 * V_14 )
{
if ( V_14 -> V_77 > V_78 &&
F_237 ( V_14 ) ) {
F_58 ( V_207 , & V_14 -> V_83 ) ;
V_14 -> V_79 = V_424 ;
} else {
V_14 -> V_77 = F_205 ( T_1 , V_14 -> V_77 ,
V_78 ) ;
V_14 -> V_79 = V_78 ;
}
V_14 -> V_80 = V_14 -> V_77 ;
}
static int F_132 ( struct V_1 * V_14 , void * V_156 )
{
struct V_425 * V_235 = V_156 ;
struct V_418 V_419 = { . V_119 = V_14 -> V_119 } ;
void * V_396 = V_235 -> V_156 ;
T_1 V_41 ;
F_21 ( L_3 , V_14 ) ;
if ( V_14 -> V_286 || V_14 -> V_426 )
goto V_18;
switch ( V_14 -> V_119 ) {
case V_125 :
case V_121 :
if ( F_73 ( V_276 , & V_14 -> V_71 ) )
break;
if ( F_238 ( V_14 ) )
F_58 ( V_427 , & V_14 -> V_83 ) ;
default:
V_14 -> V_119 = F_236 ( V_419 . V_119 , V_14 -> V_3 -> V_267 ) ;
break;
}
V_18:
if ( V_14 -> V_98 != V_91 )
F_229 ( & V_396 , V_428 , 2 , V_14 -> V_98 ) ;
switch ( V_14 -> V_119 ) {
case V_120 :
if ( ! ( V_14 -> V_3 -> V_267 & V_271 ) &&
! ( V_14 -> V_3 -> V_267 & V_272 ) )
break;
V_419 . V_119 = V_120 ;
V_419 . V_429 = 0 ;
V_419 . V_430 = 0 ;
V_419 . V_29 = 0 ;
V_419 . V_31 = 0 ;
V_419 . V_431 = 0 ;
F_229 ( & V_396 , V_432 , sizeof( V_419 ) ,
( unsigned long ) & V_419 ) ;
break;
case V_121 :
V_419 . V_119 = V_121 ;
V_419 . V_430 = V_14 -> V_75 ;
F_239 ( V_14 , & V_419 ) ;
V_41 = F_205 ( T_1 , V_433 , V_14 -> V_3 -> V_320 -
V_212 - V_363 -
V_217 ) ;
V_419 . V_431 = F_16 ( V_41 ) ;
F_241 ( V_14 ) ;
V_419 . V_429 = F_205 ( T_1 , V_14 -> V_77 ,
V_78 ) ;
F_229 ( & V_396 , V_432 , sizeof( V_419 ) ,
( unsigned long ) & V_419 ) ;
if ( F_73 ( V_427 , & V_14 -> V_83 ) )
F_230 ( & V_396 , V_14 ) ;
if ( F_73 ( V_207 , & V_14 -> V_83 ) )
F_229 ( & V_396 , V_434 , 2 ,
V_14 -> V_77 ) ;
if ( V_14 -> V_3 -> V_267 & V_435 )
if ( V_14 -> V_73 == V_436 ||
F_73 ( V_437 , & V_14 -> V_71 ) ) {
V_14 -> V_73 = V_436 ;
F_229 ( & V_396 , V_438 , 1 ,
V_14 -> V_73 ) ;
}
break;
case V_125 :
F_241 ( V_14 ) ;
V_419 . V_119 = V_125 ;
V_419 . V_429 = 0 ;
V_419 . V_430 = 0 ;
V_419 . V_29 = 0 ;
V_419 . V_31 = 0 ;
V_41 = F_205 ( T_1 , V_433 , V_14 -> V_3 -> V_320 -
V_212 - V_363 -
V_217 ) ;
V_419 . V_431 = F_16 ( V_41 ) ;
F_229 ( & V_396 , V_432 , sizeof( V_419 ) ,
( unsigned long ) & V_419 ) ;
if ( F_73 ( V_427 , & V_14 -> V_83 ) )
F_230 ( & V_396 , V_14 ) ;
if ( V_14 -> V_3 -> V_267 & V_435 )
if ( V_14 -> V_73 == V_436 ||
F_73 ( V_437 , & V_14 -> V_71 ) ) {
V_14 -> V_73 = V_436 ;
F_229 ( & V_396 , V_438 , 1 ,
V_14 -> V_73 ) ;
}
break;
}
V_235 -> V_6 = F_16 ( V_14 -> V_6 ) ;
V_235 -> V_83 = F_79 ( 0 ) ;
return V_396 - V_156 ;
}
static int F_242 ( struct V_1 * V_14 , void * V_156 )
{
struct V_439 * V_132 = V_156 ;
void * V_396 = V_132 -> V_156 ;
void * V_235 = V_14 -> V_440 ;
int V_155 = V_14 -> V_441 ;
int type , V_442 , V_397 ;
unsigned long V_398 ;
struct V_418 V_419 = { . V_119 = V_120 } ;
struct V_402 V_403 ;
T_2 V_443 = 0 ;
T_1 V_320 = V_91 ;
T_1 V_133 = V_444 ;
T_1 V_41 ;
F_21 ( L_3 , V_14 ) ;
while ( V_155 >= V_401 ) {
V_155 -= F_228 ( & V_235 , & type , & V_397 , & V_398 ) ;
V_442 = type & V_445 ;
type &= V_446 ;
switch ( type ) {
case V_428 :
V_320 = V_398 ;
break;
case V_447 :
V_14 -> V_408 = V_398 ;
break;
case V_448 :
break;
case V_432 :
if ( V_397 == sizeof( V_419 ) )
memcpy ( & V_419 , ( void * ) V_398 , V_397 ) ;
break;
case V_438 :
if ( V_398 == V_436 )
F_58 ( V_437 , & V_14 -> V_71 ) ;
break;
case V_409 :
V_443 = 1 ;
if ( V_397 == sizeof( V_403 ) )
memcpy ( & V_403 , ( void * ) V_398 , V_397 ) ;
break;
case V_434 :
if ( ! V_229 )
return - V_58 ;
F_58 ( V_207 , & V_14 -> V_83 ) ;
F_58 ( V_449 , & V_14 -> V_71 ) ;
V_14 -> V_79 = V_424 ;
V_14 -> V_346 = V_398 ;
break;
default:
if ( V_442 )
break;
V_133 = V_450 ;
* ( ( T_2 * ) V_396 ++ ) = type ;
break;
}
}
if ( V_14 -> V_426 || V_14 -> V_286 > 1 )
goto V_18;
switch ( V_14 -> V_119 ) {
case V_125 :
case V_121 :
if ( ! F_73 ( V_276 , & V_14 -> V_71 ) ) {
V_14 -> V_119 = F_236 ( V_419 . V_119 ,
V_14 -> V_3 -> V_267 ) ;
break;
}
if ( V_443 ) {
if ( F_238 ( V_14 ) )
F_58 ( V_427 , & V_14 -> V_83 ) ;
else
return - V_58 ;
}
if ( V_14 -> V_119 != V_419 . V_119 )
return - V_58 ;
break;
}
V_18:
if ( V_14 -> V_119 != V_419 . V_119 ) {
V_133 = V_451 ;
V_419 . V_119 = V_14 -> V_119 ;
if ( V_14 -> V_426 == 1 )
return - V_58 ;
F_229 ( & V_396 , V_432 , sizeof( V_419 ) ,
( unsigned long ) & V_419 ) ;
}
if ( V_133 == V_444 ) {
if ( V_320 < V_452 )
V_133 = V_451 ;
else {
V_14 -> V_90 = V_320 ;
F_58 ( V_453 , & V_14 -> V_71 ) ;
}
F_229 ( & V_396 , V_428 , 2 , V_14 -> V_90 ) ;
if ( V_443 ) {
if ( V_14 -> V_102 != V_454 &&
V_403 . V_404 != V_454 &&
V_403 . V_404 != V_14 -> V_102 ) {
V_133 = V_451 ;
if ( V_14 -> V_286 >= 1 )
return - V_58 ;
F_229 ( & V_396 , V_409 ,
sizeof( V_403 ) ,
( unsigned long ) & V_403 ) ;
} else {
V_133 = V_455 ;
F_58 ( V_456 , & V_14 -> V_71 ) ;
}
}
switch ( V_419 . V_119 ) {
case V_120 :
V_14 -> V_73 = V_436 ;
F_58 ( V_457 , & V_14 -> V_71 ) ;
break;
case V_121 :
if ( ! F_73 ( V_449 , & V_14 -> V_71 ) )
V_14 -> V_346 = V_419 . V_429 ;
else
V_419 . V_429 = V_78 ;
V_14 -> V_458 = V_419 . V_430 ;
V_41 = F_205 ( T_1 , F_243 ( V_419 . V_431 ) ,
V_14 -> V_3 -> V_320 - V_212 -
V_363 - V_217 ) ;
V_419 . V_431 = F_16 ( V_41 ) ;
V_14 -> V_368 = V_41 ;
F_239 ( V_14 , & V_419 ) ;
F_58 ( V_457 , & V_14 -> V_71 ) ;
F_229 ( & V_396 , V_432 ,
sizeof( V_419 ) , ( unsigned long ) & V_419 ) ;
if ( F_73 ( V_427 , & V_14 -> V_83 ) ) {
V_14 -> V_459 = V_403 . V_152 ;
V_14 -> V_460 = V_403 . V_404 ;
V_14 -> V_461 = F_243 ( V_403 . V_405 ) ;
V_14 -> V_462 =
F_244 ( V_403 . V_408 ) ;
V_14 -> V_463 =
F_244 ( V_403 . V_407 ) ;
V_14 -> V_464 =
F_244 ( V_403 . V_406 ) ;
F_229 ( & V_396 , V_409 ,
sizeof( V_403 ) ,
( unsigned long ) & V_403 ) ;
}
break;
case V_125 :
V_41 = F_205 ( T_1 , F_243 ( V_419 . V_431 ) ,
V_14 -> V_3 -> V_320 - V_212 -
V_363 - V_217 ) ;
V_419 . V_431 = F_16 ( V_41 ) ;
V_14 -> V_368 = V_41 ;
F_58 ( V_457 , & V_14 -> V_71 ) ;
F_229 ( & V_396 , V_432 , sizeof( V_419 ) ,
( unsigned long ) & V_419 ) ;
break;
default:
V_133 = V_451 ;
memset ( & V_419 , 0 , sizeof( V_419 ) ) ;
V_419 . V_119 = V_14 -> V_119 ;
}
if ( V_133 == V_444 )
F_58 ( V_465 , & V_14 -> V_71 ) ;
}
V_132 -> V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 -> V_133 = F_16 ( V_133 ) ;
V_132 -> V_83 = F_79 ( 0 ) ;
return V_396 - V_156 ;
}
static int F_245 ( struct V_1 * V_14 , void * V_132 , int V_155 ,
void * V_156 , T_1 * V_133 )
{
struct V_425 * V_235 = V_156 ;
void * V_396 = V_235 -> V_156 ;
int type , V_397 ;
unsigned long V_398 ;
struct V_418 V_419 = { . V_119 = V_120 } ;
struct V_402 V_403 ;
F_21 ( L_43 , V_14 , V_132 , V_155 , V_156 ) ;
while ( V_155 >= V_401 ) {
V_155 -= F_228 ( & V_132 , & type , & V_397 , & V_398 ) ;
switch ( type ) {
case V_428 :
if ( V_398 < V_452 ) {
* V_133 = V_451 ;
V_14 -> V_98 = V_452 ;
} else
V_14 -> V_98 = V_398 ;
F_229 ( & V_396 , V_428 , 2 , V_14 -> V_98 ) ;
break;
case V_447 :
V_14 -> V_408 = V_398 ;
F_229 ( & V_396 , V_447 ,
2 , V_14 -> V_408 ) ;
break;
case V_432 :
if ( V_397 == sizeof( V_419 ) )
memcpy ( & V_419 , ( void * ) V_398 , V_397 ) ;
if ( F_73 ( V_276 , & V_14 -> V_71 ) &&
V_419 . V_119 != V_14 -> V_119 )
return - V_58 ;
V_14 -> V_73 = 0 ;
F_229 ( & V_396 , V_432 ,
sizeof( V_419 ) , ( unsigned long ) & V_419 ) ;
break;
case V_434 :
V_14 -> V_80 = F_205 ( T_1 , V_398 , V_14 -> V_80 ) ;
F_229 ( & V_396 , V_434 , 2 ,
V_14 -> V_77 ) ;
break;
case V_409 :
if ( V_397 == sizeof( V_403 ) )
memcpy ( & V_403 , ( void * ) V_398 , V_397 ) ;
if ( V_14 -> V_102 != V_454 &&
V_403 . V_404 != V_454 &&
V_403 . V_404 != V_14 -> V_102 )
return - V_58 ;
F_229 ( & V_396 , V_409 , sizeof( V_403 ) ,
( unsigned long ) & V_403 ) ;
break;
case V_438 :
if ( * V_133 == V_455 )
if ( V_398 == V_436 )
F_58 ( V_437 ,
& V_14 -> V_71 ) ;
break;
}
}
if ( V_14 -> V_119 == V_120 && V_14 -> V_119 != V_419 . V_119 )
return - V_58 ;
V_14 -> V_119 = V_419 . V_119 ;
if ( * V_133 == V_444 || * V_133 == V_455 ) {
switch ( V_419 . V_119 ) {
case V_121 :
V_14 -> V_29 = F_243 ( V_419 . V_29 ) ;
V_14 -> V_31 = F_243 ( V_419 . V_31 ) ;
V_14 -> V_466 = F_243 ( V_419 . V_431 ) ;
if ( ! F_73 ( V_207 , & V_14 -> V_83 ) )
V_14 -> V_80 = F_205 ( T_1 , V_14 -> V_80 ,
V_419 . V_429 ) ;
if ( F_73 ( V_427 , & V_14 -> V_83 ) ) {
V_14 -> V_104 = F_243 ( V_403 . V_405 ) ;
V_14 -> V_106 =
F_244 ( V_403 . V_406 ) ;
V_14 -> V_108 = F_244 ( V_403 . V_407 ) ;
V_14 -> V_110 =
F_244 ( V_403 . V_408 ) ;
}
break;
case V_125 :
V_14 -> V_466 = F_243 ( V_419 . V_431 ) ;
}
}
V_235 -> V_6 = F_16 ( V_14 -> V_6 ) ;
V_235 -> V_83 = F_79 ( 0 ) ;
return V_396 - V_156 ;
}
static int F_246 ( struct V_1 * V_14 , void * V_156 ,
T_1 V_133 , T_1 V_83 )
{
struct V_439 * V_132 = V_156 ;
void * V_396 = V_132 -> V_156 ;
F_21 ( L_3 , V_14 ) ;
V_132 -> V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 -> V_133 = F_16 ( V_133 ) ;
V_132 -> V_83 = F_16 ( V_83 ) ;
return V_396 - V_156 ;
}
void F_247 ( struct V_1 * V_14 )
{
struct V_131 V_132 ;
struct V_2 * V_3 = V_14 -> V_3 ;
T_2 V_278 [ 128 ] ;
T_2 V_467 ;
V_132 . V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_6 = F_16 ( V_14 -> V_7 ) ;
V_132 . V_133 = F_79 ( V_282 ) ;
V_132 . V_138 = F_79 ( V_139 ) ;
if ( V_14 -> V_169 )
V_467 = V_468 ;
else
V_467 = V_140 ;
F_21 ( L_44 , V_14 , V_467 ) ;
F_80 ( V_3 , V_14 -> V_9 , V_467 , sizeof( V_132 ) , & V_132 ) ;
if ( F_248 ( V_284 , & V_14 -> V_71 ) )
return;
F_80 ( V_3 , F_84 ( V_3 ) , V_285 ,
F_132 ( V_14 , V_278 ) , V_278 ) ;
V_14 -> V_286 ++ ;
}
static void F_249 ( struct V_1 * V_14 , void * V_132 , int V_155 )
{
int type , V_397 ;
unsigned long V_398 ;
T_1 V_469 = V_14 -> V_80 ;
struct V_418 V_419 = {
. V_119 = V_14 -> V_119 ,
. V_29 = F_79 ( V_422 ) ,
. V_31 = F_79 ( V_423 ) ,
. V_431 = F_16 ( V_14 -> V_98 ) ,
. V_429 = F_205 ( T_1 , V_14 -> V_80 , V_78 ) ,
} ;
F_21 ( L_45 , V_14 , V_132 , V_155 ) ;
if ( ( V_14 -> V_119 != V_121 ) && ( V_14 -> V_119 != V_125 ) )
return;
while ( V_155 >= V_401 ) {
V_155 -= F_228 ( & V_132 , & type , & V_397 , & V_398 ) ;
switch ( type ) {
case V_432 :
if ( V_397 == sizeof( V_419 ) )
memcpy ( & V_419 , ( void * ) V_398 , V_397 ) ;
break;
case V_434 :
V_469 = V_398 ;
break;
}
}
switch ( V_419 . V_119 ) {
case V_121 :
V_14 -> V_29 = F_243 ( V_419 . V_29 ) ;
V_14 -> V_31 = F_243 ( V_419 . V_31 ) ;
V_14 -> V_466 = F_243 ( V_419 . V_431 ) ;
if ( F_73 ( V_207 , & V_14 -> V_83 ) )
V_14 -> V_80 = F_205 ( T_1 , V_14 -> V_80 , V_469 ) ;
else
V_14 -> V_80 = F_205 ( T_1 , V_14 -> V_80 ,
V_419 . V_429 ) ;
break;
case V_125 :
V_14 -> V_466 = F_243 ( V_419 . V_431 ) ;
}
}
static inline int F_250 ( struct V_2 * V_3 ,
struct V_391 * V_392 , T_1 V_470 ,
T_2 * V_156 )
{
struct V_471 * V_472 = (struct V_471 * ) V_156 ;
if ( V_470 < sizeof( * V_472 ) )
return - V_473 ;
if ( V_472 -> V_55 != V_474 )
return 0 ;
if ( ( V_3 -> V_258 & V_259 ) &&
V_392 -> V_9 == V_3 -> V_263 ) {
F_251 ( & V_3 -> V_264 ) ;
V_3 -> V_258 |= V_260 ;
V_3 -> V_263 = 0 ;
F_130 ( V_3 ) ;
}
return 0 ;
}
static struct V_1 * F_252 ( struct V_2 * V_3 ,
struct V_391 * V_392 ,
T_2 * V_156 , T_2 V_467 , T_2 V_237 )
{
struct V_234 * V_235 = (struct V_234 * ) V_156 ;
struct V_131 V_132 ;
struct V_1 * V_14 = NULL , * V_295 ;
struct V_26 * V_294 , * V_13 = NULL ;
int V_133 , V_138 = V_139 ;
T_1 V_6 = 0 , V_7 = F_67 ( V_235 -> V_7 ) ;
T_3 V_10 = V_235 -> V_10 ;
F_21 ( L_46 , F_67 ( V_10 ) , V_7 ) ;
V_295 = F_164 ( V_127 , V_10 , V_3 -> V_11 , V_3 -> V_287 ) ;
if ( ! V_295 ) {
V_133 = V_136 ;
goto V_475;
}
V_294 = V_295 -> V_13 ;
F_5 ( & V_3 -> V_8 ) ;
F_24 ( V_294 ) ;
if ( V_10 != F_79 ( V_147 ) &&
! F_253 ( V_3 -> V_88 ) ) {
V_3 -> V_84 = V_476 ;
V_133 = V_135 ;
goto V_477;
}
V_133 = V_478 ;
if ( F_1 ( V_3 , V_7 ) )
goto V_477;
V_14 = V_295 -> V_24 -> V_296 ( V_295 ) ;
if ( ! V_14 )
goto V_477;
V_13 = V_14 -> V_13 ;
F_137 ( V_3 -> V_88 ) ;
F_138 ( & F_13 ( V_13 ) -> V_11 , V_3 -> V_11 ) ;
F_138 ( & F_13 ( V_13 ) -> V_287 , V_3 -> V_287 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_7 ;
V_14 -> V_413 = V_237 ;
F_66 ( V_3 , V_14 ) ;
V_6 = V_14 -> V_7 ;
F_77 ( V_14 , V_13 -> V_129 ) ;
V_14 -> V_9 = V_392 -> V_9 ;
if ( V_3 -> V_258 & V_260 ) {
if ( F_82 ( V_14 ) ) {
if ( F_73 ( V_134 , & F_13 ( V_13 ) -> V_83 ) ) {
F_20 ( V_14 , V_130 ) ;
V_133 = V_279 ;
V_138 = V_280 ;
V_14 -> V_24 -> V_281 ( V_14 ) ;
} else {
if ( V_237 ) {
F_20 ( V_14 , V_130 ) ;
V_133 = V_279 ;
} else {
F_20 ( V_14 , V_57 ) ;
V_133 = V_282 ;
}
V_138 = V_139 ;
}
} else {
F_20 ( V_14 , V_130 ) ;
V_133 = V_279 ;
V_138 = V_283 ;
}
} else {
F_20 ( V_14 , V_130 ) ;
V_133 = V_279 ;
V_138 = V_139 ;
}
V_477:
F_25 ( V_294 ) ;
F_7 ( & V_3 -> V_8 ) ;
V_475:
V_132 . V_7 = F_16 ( V_7 ) ;
V_132 . V_6 = F_16 ( V_6 ) ;
V_132 . V_133 = F_16 ( V_133 ) ;
V_132 . V_138 = F_16 ( V_138 ) ;
F_80 ( V_3 , V_392 -> V_9 , V_467 , sizeof( V_132 ) , & V_132 ) ;
if ( V_133 == V_279 && V_138 == V_139 ) {
struct V_261 V_479 ;
V_479 . type = F_79 ( V_262 ) ;
V_3 -> V_258 |= V_259 ;
V_3 -> V_263 = F_84 ( V_3 ) ;
F_128 ( & V_3 -> V_264 , V_265 ) ;
F_80 ( V_3 , V_3 -> V_263 , V_266 ,
sizeof( V_479 ) , & V_479 ) ;
}
if ( V_14 && ! F_73 ( V_284 , & V_14 -> V_71 ) &&
V_133 == V_282 ) {
T_2 V_278 [ 128 ] ;
F_58 ( V_284 , & V_14 -> V_71 ) ;
F_80 ( V_3 , F_84 ( V_3 ) , V_285 ,
F_132 ( V_14 , V_278 ) , V_278 ) ;
V_14 -> V_286 ++ ;
}
return V_14 ;
}
static int F_254 ( struct V_2 * V_3 ,
struct V_391 * V_392 , T_1 V_470 , T_2 * V_156 )
{
struct V_306 * V_157 = V_3 -> V_88 -> V_157 ;
struct V_168 * V_88 = V_3 -> V_88 ;
if ( V_470 < sizeof( struct V_234 ) )
return - V_473 ;
F_144 ( V_157 ) ;
if ( F_73 ( V_480 , & V_157 -> V_481 ) &&
! F_248 ( V_482 , & V_88 -> V_83 ) )
F_255 ( V_157 , & V_88 -> V_287 , V_88 -> type ,
V_88 -> V_323 , 0 , NULL , 0 ,
V_88 -> V_483 ) ;
F_145 ( V_157 ) ;
F_252 ( V_3 , V_392 , V_156 , V_140 , 0 ) ;
return 0 ;
}
static int F_256 ( struct V_2 * V_3 ,
struct V_391 * V_392 , T_1 V_470 ,
T_2 * V_156 )
{
struct V_131 * V_132 = (struct V_131 * ) V_156 ;
T_1 V_7 , V_6 , V_133 , V_138 ;
struct V_1 * V_14 ;
T_2 V_235 [ 128 ] ;
int V_15 ;
if ( V_470 < sizeof( * V_132 ) )
return - V_473 ;
V_7 = F_67 ( V_132 -> V_7 ) ;
V_6 = F_67 ( V_132 -> V_6 ) ;
V_133 = F_67 ( V_132 -> V_133 ) ;
V_138 = F_67 ( V_132 -> V_138 ) ;
F_21 ( L_47 ,
V_6 , V_7 , V_133 , V_138 ) ;
F_5 ( & V_3 -> V_8 ) ;
if ( V_7 ) {
V_14 = F_3 ( V_3 , V_7 ) ;
if ( ! V_14 ) {
V_15 = - V_355 ;
goto V_484;
}
} else {
V_14 = F_9 ( V_3 , V_392 -> V_9 ) ;
if ( ! V_14 ) {
V_15 = - V_355 ;
goto V_484;
}
}
V_15 = 0 ;
F_6 ( V_14 ) ;
switch ( V_133 ) {
case V_282 :
F_23 ( V_14 , V_57 ) ;
V_14 -> V_9 = 0 ;
V_14 -> V_6 = V_6 ;
F_112 ( V_228 , & V_14 -> V_71 ) ;
if ( F_248 ( V_284 , & V_14 -> V_71 ) )
break;
F_80 ( V_3 , F_84 ( V_3 ) , V_285 ,
F_132 ( V_14 , V_235 ) , V_235 ) ;
V_14 -> V_286 ++ ;
break;
case V_279 :
F_58 ( V_228 , & V_14 -> V_71 ) ;
break;
default:
F_69 ( V_14 , V_58 ) ;
break;
}
F_50 ( V_14 ) ;
V_484:
F_7 ( & V_3 -> V_8 ) ;
return V_15 ;
}
static inline void F_257 ( struct V_1 * V_14 )
{
if ( V_14 -> V_119 != V_121 && V_14 -> V_119 != V_125 )
V_14 -> V_73 = V_436 ;
else if ( ! F_73 ( V_437 , & V_14 -> V_71 ) )
V_14 -> V_73 = V_74 ;
}
static void F_258 ( struct V_1 * V_14 , void * V_156 ,
T_2 V_9 , T_1 V_83 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
F_21 ( L_48 , V_3 , V_14 , V_9 ,
V_83 ) ;
F_112 ( V_456 , & V_14 -> V_71 ) ;
F_58 ( V_465 , & V_14 -> V_71 ) ;
F_80 ( V_3 , V_9 , V_485 ,
F_246 ( V_14 , V_156 ,
V_444 , V_83 ) , V_156 ) ;
}
static inline int F_259 ( struct V_2 * V_3 ,
struct V_391 * V_392 , T_1 V_470 ,
T_2 * V_156 )
{
struct V_425 * V_235 = (struct V_425 * ) V_156 ;
T_1 V_6 , V_83 ;
T_2 V_132 [ 64 ] ;
struct V_1 * V_14 ;
int V_155 , V_15 = 0 ;
if ( V_470 < sizeof( * V_235 ) )
return - V_473 ;
V_6 = F_67 ( V_235 -> V_6 ) ;
V_83 = F_67 ( V_235 -> V_83 ) ;
F_21 ( L_49 , V_6 , V_83 ) ;
V_14 = F_4 ( V_3 , V_6 ) ;
if ( ! V_14 )
return - V_486 ;
if ( V_14 -> V_23 != V_57 && V_14 -> V_23 != V_130 ) {
struct V_487 V_472 ;
V_472 . V_55 = F_79 ( V_488 ) ;
V_472 . V_7 = F_16 ( V_14 -> V_7 ) ;
V_472 . V_6 = F_16 ( V_14 -> V_6 ) ;
F_80 ( V_3 , V_392 -> V_9 , V_489 ,
sizeof( V_472 ) , & V_472 ) ;
goto V_484;
}
V_155 = V_470 - sizeof( * V_235 ) ;
if ( V_14 -> V_441 + V_155 > sizeof( V_14 -> V_440 ) ) {
F_80 ( V_3 , V_392 -> V_9 , V_485 ,
F_246 ( V_14 , V_132 ,
V_490 , V_83 ) , V_132 ) ;
goto V_484;
}
memcpy ( V_14 -> V_440 + V_14 -> V_441 , V_235 -> V_156 , V_155 ) ;
V_14 -> V_441 += V_155 ;
if ( V_83 & V_491 ) {
F_80 ( V_3 , V_392 -> V_9 , V_485 ,
F_246 ( V_14 , V_132 ,
V_444 , V_83 ) , V_132 ) ;
goto V_484;
}
V_155 = F_242 ( V_14 , V_132 ) ;
if ( V_155 < 0 ) {
F_78 ( V_14 , V_277 ) ;
goto V_484;
}
V_14 -> V_9 = V_392 -> V_9 ;
F_80 ( V_3 , V_392 -> V_9 , V_485 , V_155 , V_132 ) ;
V_14 -> V_426 ++ ;
V_14 -> V_441 = 0 ;
if ( ! F_73 ( V_465 , & V_14 -> V_71 ) )
goto V_484;
if ( F_73 ( V_492 , & V_14 -> V_71 ) ) {
F_257 ( V_14 ) ;
if ( V_14 -> V_119 == V_121 ||
V_14 -> V_119 == V_125 )
V_15 = F_234 ( V_14 ) ;
if ( V_15 < 0 )
F_78 ( V_14 , - V_15 ) ;
else
F_124 ( V_14 ) ;
goto V_484;
}
if ( ! F_248 ( V_284 , & V_14 -> V_71 ) ) {
T_2 V_278 [ 64 ] ;
F_80 ( V_3 , F_84 ( V_3 ) , V_285 ,
F_132 ( V_14 , V_278 ) , V_278 ) ;
V_14 -> V_286 ++ ;
}
if ( F_73 ( V_493 , & V_14 -> V_71 ) &&
F_73 ( V_456 , & V_14 -> V_71 ) ) {
if ( ! V_14 -> V_169 )
F_258 ( V_14 , V_132 , V_392 -> V_9 , V_83 ) ;
else
V_14 -> V_9 = V_392 -> V_9 ;
}
V_484:
F_50 ( V_14 ) ;
return V_15 ;
}
static inline int F_260 ( struct V_2 * V_3 ,
struct V_391 * V_392 , T_1 V_470 ,
T_2 * V_156 )
{
struct V_439 * V_132 = (struct V_439 * ) V_156 ;
T_1 V_7 , V_83 , V_133 ;
struct V_1 * V_14 ;
int V_155 = V_470 - sizeof( * V_132 ) ;
int V_15 = 0 ;
if ( V_470 < sizeof( * V_132 ) )
return - V_473 ;
V_7 = F_67 ( V_132 -> V_7 ) ;
V_83 = F_67 ( V_132 -> V_83 ) ;
V_133 = F_67 ( V_132 -> V_133 ) ;
F_21 ( L_50 , V_7 , V_83 ,
V_133 , V_155 ) ;
V_14 = F_4 ( V_3 , V_7 ) ;
if ( ! V_14 )
return 0 ;
switch ( V_133 ) {
case V_444 :
F_249 ( V_14 , V_132 -> V_156 , V_155 ) ;
F_112 ( V_493 , & V_14 -> V_71 ) ;
break;
case V_455 :
F_58 ( V_493 , & V_14 -> V_71 ) ;
if ( F_73 ( V_456 , & V_14 -> V_71 ) ) {
char V_278 [ 64 ] ;
V_155 = F_245 ( V_14 , V_132 -> V_156 , V_155 ,
V_278 , & V_133 ) ;
if ( V_155 < 0 ) {
F_78 ( V_14 , V_277 ) ;
goto V_18;
}
if ( ! V_14 -> V_169 ) {
F_258 ( V_14 , V_278 , V_392 -> V_9 ,
0 ) ;
} else {
if ( F_118 ( V_14 ) ) {
F_261 ( V_14 ) ;
V_14 -> V_9 = V_392 -> V_9 ;
}
}
}
goto V_18;
case V_451 :
if ( V_14 -> V_426 <= V_494 ) {
char V_235 [ 64 ] ;
if ( V_155 > sizeof( V_235 ) - sizeof( struct V_425 ) ) {
F_78 ( V_14 , V_277 ) ;
goto V_18;
}
V_133 = V_444 ;
V_155 = F_245 ( V_14 , V_132 -> V_156 , V_155 ,
V_235 , & V_133 ) ;
if ( V_155 < 0 ) {
F_78 ( V_14 , V_277 ) ;
goto V_18;
}
F_80 ( V_3 , F_84 ( V_3 ) ,
V_285 , V_155 , V_235 ) ;
V_14 -> V_286 ++ ;
if ( V_133 != V_444 )
goto V_18;
break;
}
default:
F_27 ( V_14 , V_277 ) ;
F_77 ( V_14 , V_495 ) ;
F_78 ( V_14 , V_277 ) ;
goto V_18;
}
if ( V_83 & V_491 )
goto V_18;
F_58 ( V_492 , & V_14 -> V_71 ) ;
if ( F_73 ( V_465 , & V_14 -> V_71 ) ) {
F_257 ( V_14 ) ;
if ( V_14 -> V_119 == V_121 ||
V_14 -> V_119 == V_125 )
V_15 = F_234 ( V_14 ) ;
if ( V_15 < 0 )
F_78 ( V_14 , - V_15 ) ;
else
F_124 ( V_14 ) ;
}
V_18:
F_50 ( V_14 ) ;
return V_15 ;
}
static inline int F_262 ( struct V_2 * V_3 ,
struct V_391 * V_392 , T_1 V_470 ,
T_2 * V_156 )
{
struct V_273 * V_235 = (struct V_273 * ) V_156 ;
struct V_496 V_132 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
struct V_26 * V_13 ;
if ( V_470 != sizeof( * V_235 ) )
return - V_473 ;
V_7 = F_67 ( V_235 -> V_7 ) ;
V_6 = F_67 ( V_235 -> V_6 ) ;
F_21 ( L_51 , V_7 , V_6 ) ;
F_5 ( & V_3 -> V_8 ) ;
V_14 = F_3 ( V_3 , V_6 ) ;
if ( ! V_14 ) {
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
F_6 ( V_14 ) ;
V_13 = V_14 -> V_13 ;
V_132 . V_6 = F_16 ( V_14 -> V_7 ) ;
V_132 . V_7 = F_16 ( V_14 -> V_6 ) ;
F_80 ( V_3 , V_392 -> V_9 , V_497 , sizeof( V_132 ) , & V_132 ) ;
F_24 ( V_13 ) ;
V_13 -> V_498 = V_499 ;
F_25 ( V_13 ) ;
F_61 ( V_14 ) ;
F_69 ( V_14 , V_277 ) ;
F_50 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_51 ( V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
static inline int F_263 ( struct V_2 * V_3 ,
struct V_391 * V_392 , T_1 V_470 ,
T_2 * V_156 )
{
struct V_496 * V_132 = (struct V_496 * ) V_156 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
if ( V_470 != sizeof( * V_132 ) )
return - V_473 ;
V_7 = F_67 ( V_132 -> V_7 ) ;
V_6 = F_67 ( V_132 -> V_6 ) ;
F_21 ( L_52 , V_6 , V_7 ) ;
F_5 ( & V_3 -> V_8 ) ;
V_14 = F_3 ( V_3 , V_7 ) ;
if ( ! V_14 ) {
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
F_6 ( V_14 ) ;
F_61 ( V_14 ) ;
F_69 ( V_14 , 0 ) ;
F_50 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_51 ( V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
static inline int F_264 ( struct V_2 * V_3 ,
struct V_391 * V_392 , T_1 V_470 ,
T_2 * V_156 )
{
struct V_261 * V_235 = (struct V_261 * ) V_156 ;
T_1 type ;
if ( V_470 != sizeof( * V_235 ) )
return - V_473 ;
type = F_67 ( V_235 -> type ) ;
F_21 ( L_53 , type ) ;
if ( type == V_262 ) {
T_2 V_278 [ 8 ] ;
T_8 V_267 = V_269 ;
struct V_500 * V_132 = (struct V_500 * ) V_278 ;
V_132 -> type = F_79 ( V_262 ) ;
V_132 -> V_133 = F_79 ( V_501 ) ;
if ( ! V_270 )
V_267 |= V_271 | V_272
| V_435 ;
if ( V_229 )
V_267 |= V_417
| V_416 ;
F_102 ( V_267 , V_132 -> V_156 ) ;
F_80 ( V_3 , V_392 -> V_9 , V_502 , sizeof( V_278 ) ,
V_278 ) ;
} else if ( type == V_503 ) {
T_2 V_278 [ 12 ] ;
struct V_500 * V_132 = (struct V_500 * ) V_278 ;
if ( V_229 )
V_504 [ 0 ] |= V_233 ;
else
V_504 [ 0 ] &= ~ V_233 ;
V_132 -> type = F_79 ( V_503 ) ;
V_132 -> V_133 = F_79 ( V_501 ) ;
memcpy ( V_132 -> V_156 , V_504 , sizeof( V_504 ) ) ;
F_80 ( V_3 , V_392 -> V_9 , V_502 , sizeof( V_278 ) ,
V_278 ) ;
} else {
struct V_500 V_132 ;
V_132 . type = F_16 ( type ) ;
V_132 . V_133 = F_79 ( V_505 ) ;
F_80 ( V_3 , V_392 -> V_9 , V_502 , sizeof( V_132 ) ,
& V_132 ) ;
}
return 0 ;
}
static inline int F_265 ( struct V_2 * V_3 ,
struct V_391 * V_392 , T_1 V_470 ,
T_2 * V_156 )
{
struct V_500 * V_132 = (struct V_500 * ) V_156 ;
T_1 type , V_133 ;
if ( V_470 < sizeof( * V_132 ) )
return - V_473 ;
type = F_67 ( V_132 -> type ) ;
V_133 = F_67 ( V_132 -> V_133 ) ;
F_21 ( L_54 , type , V_133 ) ;
if ( V_392 -> V_9 != V_3 -> V_263 ||
V_3 -> V_258 & V_260 )
return 0 ;
F_251 ( & V_3 -> V_264 ) ;
if ( V_133 != V_501 ) {
V_3 -> V_258 |= V_260 ;
V_3 -> V_263 = 0 ;
F_130 ( V_3 ) ;
return 0 ;
}
switch ( type ) {
case V_262 :
V_3 -> V_267 = F_96 ( V_132 -> V_156 ) ;
if ( V_3 -> V_267 & V_506 ) {
struct V_261 V_235 ;
V_235 . type = F_79 ( V_503 ) ;
V_3 -> V_263 = F_84 ( V_3 ) ;
F_80 ( V_3 , V_3 -> V_263 ,
V_266 , sizeof( V_235 ) , & V_235 ) ;
} else {
V_3 -> V_258 |= V_260 ;
V_3 -> V_263 = 0 ;
F_130 ( V_3 ) ;
}
break;
case V_503 :
V_3 -> V_232 = V_132 -> V_156 [ 0 ] ;
V_3 -> V_258 |= V_260 ;
V_3 -> V_263 = 0 ;
F_130 ( V_3 ) ;
break;
}
return 0 ;
}
static int F_266 ( struct V_2 * V_3 ,
struct V_391 * V_392 ,
T_1 V_470 , void * V_156 )
{
struct V_238 * V_235 = V_156 ;
struct V_507 V_132 ;
struct V_1 * V_14 ;
struct V_306 * V_157 ;
T_1 V_10 , V_7 ;
if ( V_470 != sizeof( * V_235 ) )
return - V_473 ;
if ( ! V_229 )
return - V_20 ;
V_10 = F_243 ( V_235 -> V_10 ) ;
V_7 = F_243 ( V_235 -> V_7 ) ;
F_21 ( L_55 , V_10 , V_7 , V_235 -> V_237 ) ;
if ( V_235 -> V_237 == V_508 ) {
F_252 ( V_3 , V_392 , V_156 , V_468 ,
V_235 -> V_237 ) ;
return 0 ;
}
V_157 = F_267 ( V_235 -> V_237 ) ;
if ( ! V_157 )
goto error;
if ( V_157 -> V_509 != V_510 || ! F_73 ( V_511 , & V_157 -> V_83 ) ) {
F_169 ( V_157 ) ;
goto error;
}
V_14 = F_252 ( V_3 , V_392 , V_156 , V_468 ,
V_235 -> V_237 ) ;
if ( V_14 ) {
struct V_113 * V_114 = V_3 -> V_88 -> V_113 ;
struct V_168 * V_169 ;
V_169 = F_268 ( V_157 , V_512 , V_3 -> V_287 ) ;
if ( ! V_169 ) {
F_169 ( V_157 ) ;
return - V_355 ;
}
F_21 ( L_56 , V_114 , V_14 , V_169 ) ;
V_114 -> V_115 = V_14 ;
V_14 -> V_169 = V_169 ;
V_14 -> V_73 = V_436 ;
V_3 -> V_320 = V_157 -> V_513 ;
}
F_169 ( V_157 ) ;
return 0 ;
error:
V_132 . V_6 = 0 ;
V_132 . V_7 = F_16 ( V_7 ) ;
V_132 . V_133 = F_79 ( V_514 ) ;
V_132 . V_138 = F_79 ( V_139 ) ;
F_80 ( V_3 , V_392 -> V_9 , V_468 ,
sizeof( V_132 ) , & V_132 ) ;
return - V_355 ;
}
static void F_269 ( struct V_1 * V_14 , T_2 V_515 )
{
struct V_516 V_235 ;
T_2 V_9 ;
F_21 ( L_57 , V_14 , V_515 ) ;
V_9 = F_84 ( V_14 -> V_3 ) ;
V_14 -> V_9 = V_9 ;
V_235 . V_517 = F_16 ( V_14 -> V_7 ) ;
V_235 . V_515 = V_515 ;
F_80 ( V_14 -> V_3 , V_9 , V_518 , sizeof( V_235 ) ,
& V_235 ) ;
F_77 ( V_14 , V_519 ) ;
}
static void F_270 ( struct V_1 * V_14 , T_1 V_133 )
{
struct V_520 V_132 ;
F_21 ( L_58 , V_14 , V_133 ) ;
V_132 . V_517 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_133 = F_16 ( V_133 ) ;
F_80 ( V_14 -> V_3 , V_14 -> V_9 , V_521 ,
sizeof( V_132 ) , & V_132 ) ;
}
static void F_271 ( struct V_1 * V_14 , T_1 V_133 )
{
struct V_522 V_523 ;
F_21 ( L_58 , V_14 , V_133 ) ;
V_14 -> V_9 = F_84 ( V_14 -> V_3 ) ;
V_523 . V_517 = F_16 ( V_14 -> V_7 ) ;
V_523 . V_133 = F_16 ( V_133 ) ;
F_80 ( V_14 -> V_3 , V_14 -> V_9 , V_524 ,
sizeof( V_523 ) , & V_523 ) ;
F_77 ( V_14 , V_519 ) ;
}
static void F_272 ( struct V_2 * V_3 , T_1 V_517 )
{
struct V_522 V_523 ;
F_21 ( L_59 , V_3 , V_517 ) ;
V_523 . V_517 = F_16 ( V_517 ) ;
V_523 . V_133 = F_79 ( V_525 ) ;
F_80 ( V_3 , F_84 ( V_3 ) , V_524 ,
sizeof( V_523 ) , & V_523 ) ;
}
static void F_273 ( struct V_2 * V_3 , T_2 V_9 ,
T_1 V_517 )
{
struct V_526 V_132 ;
F_21 ( L_60 , V_517 ) ;
V_132 . V_517 = F_16 ( V_517 ) ;
F_80 ( V_3 , V_9 , V_527 , sizeof( V_132 ) , & V_132 ) ;
}
static void F_274 ( struct V_1 * V_14 )
{
V_14 -> V_116 = NULL ;
V_14 -> V_169 = NULL ;
}
static void F_275 ( struct V_1 * V_14 )
{
if ( V_14 -> V_23 != V_56 ) {
F_78 ( V_14 , V_277 ) ;
return;
}
switch ( V_14 -> V_250 ) {
case V_255 :
F_122 ( V_14 ) ;
F_270 ( V_14 , V_528 ) ;
break;
case V_252 :
if ( V_14 -> V_165 == V_529 ||
V_14 -> V_165 == V_530 ) {
F_122 ( V_14 ) ;
}
F_271 ( V_14 , V_525 ) ;
break;
}
}
static void F_276 ( struct V_1 * V_14 ,
struct V_117 * V_164 )
{
struct V_439 V_132 ;
V_14 -> V_116 = V_164 ;
V_14 -> V_169 -> V_313 = V_14 -> V_3 ;
F_258 ( V_14 , & V_132 , V_14 -> V_9 , 0 ) ;
if ( F_73 ( V_492 , & V_14 -> V_71 ) ) {
int V_15 ;
F_257 ( V_14 ) ;
V_15 = F_234 ( V_14 ) ;
if ( V_15 < 0 )
F_78 ( V_14 , - V_15 ) ;
else
F_124 ( V_14 ) ;
}
}
static void F_277 ( struct V_1 * V_14 ,
struct V_117 * V_164 )
{
V_14 -> V_169 = V_164 -> V_3 ;
V_14 -> V_169 -> V_313 = V_14 -> V_3 ;
F_21 ( L_61 , V_14 -> V_165 ) ;
switch ( V_14 -> V_165 ) {
case V_529 :
V_14 -> V_165 = V_531 ;
break;
case V_530 :
if ( F_73 ( V_226 , & V_14 -> V_220 ) ) {
V_14 -> V_165 = V_532 ;
} else if ( V_14 -> V_250 == V_252 ) {
V_14 -> V_165 = V_533 ;
F_271 ( V_14 , V_534 ) ;
} else if ( V_14 -> V_250 == V_255 ) {
V_14 -> V_165 = V_535 ;
F_270 ( V_14 , V_536 ) ;
}
break;
default:
F_274 ( V_14 ) ;
V_14 -> V_165 = V_166 ;
}
}
void F_278 ( struct V_1 * V_14 , struct V_117 * V_164 ,
T_2 V_138 )
{
F_21 ( L_62 , V_14 , V_164 , V_138 ) ;
if ( V_138 ) {
F_275 ( V_14 ) ;
F_274 ( V_14 ) ;
return;
}
if ( V_14 -> V_23 != V_56 ) {
if ( V_14 -> V_413 )
F_276 ( V_14 , V_164 ) ;
} else {
F_277 ( V_14 , V_164 ) ;
}
}
void F_279 ( struct V_1 * V_14 )
{
F_21 ( L_3 , V_14 ) ;
if ( V_14 -> V_413 == V_508 ) {
if ( V_14 -> V_230 != V_231 )
return;
V_14 -> V_250 = V_252 ;
V_14 -> V_165 = V_167 ;
} else {
V_14 -> V_250 = V_252 ;
V_14 -> V_165 = V_531 ;
V_14 -> V_414 = 0 ;
F_121 ( V_14 ) ;
F_269 ( V_14 , 0 ) ;
}
}
static void F_280 ( struct V_1 * V_14 , int V_133 ,
T_2 V_413 , T_2 V_537 )
{
F_21 ( L_63 , V_14 , F_22 ( V_14 -> V_23 ) ,
V_413 , V_537 ) ;
V_14 -> V_73 = V_436 ;
if ( V_14 -> V_23 == V_59 ) {
if ( V_133 == V_282 ) {
V_14 -> V_413 = V_413 ;
F_120 ( V_14 , V_537 ) ;
} else {
F_119 ( V_14 ) ;
}
return;
}
if ( F_115 ( V_14 ) ) {
struct V_131 V_132 ;
char V_278 [ 128 ] ;
V_132 . V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_6 = F_16 ( V_14 -> V_7 ) ;
if ( V_133 == V_282 ) {
V_132 . V_133 = F_79 ( V_282 ) ;
V_132 . V_138 = F_79 ( V_139 ) ;
} else {
V_132 . V_133 = F_79 ( V_478 ) ;
V_132 . V_138 = F_79 ( V_139 ) ;
}
F_80 ( V_14 -> V_3 , V_14 -> V_9 , V_468 ,
sizeof( V_132 ) , & V_132 ) ;
if ( V_133 == V_282 ) {
F_20 ( V_14 , V_57 ) ;
F_58 ( V_284 , & V_14 -> V_71 ) ;
F_80 ( V_14 -> V_3 , F_84 ( V_14 -> V_3 ) ,
V_285 ,
F_132 ( V_14 , V_278 ) , V_278 ) ;
V_14 -> V_286 ++ ;
}
}
}
static void F_281 ( struct V_1 * V_14 , T_2 V_413 ,
T_2 V_537 )
{
F_121 ( V_14 ) ;
V_14 -> V_414 = V_413 ;
V_14 -> V_165 = V_538 ;
F_269 ( V_14 , V_537 ) ;
}
static void F_282 ( struct V_1 * V_14 , int V_133 )
{
struct V_117 * V_164 = NULL ;
if ( V_164 ) {
if ( V_164 -> V_23 == V_56 ) {
V_14 -> V_169 = V_164 -> V_3 ;
V_14 -> V_169 -> V_313 = V_14 -> V_3 ;
V_14 -> V_165 = V_535 ;
F_270 ( V_14 , V_536 ) ;
F_278 ( V_14 , V_164 , V_536 ) ;
} else {
V_14 -> V_165 = V_530 ;
}
} else {
F_270 ( V_14 , V_539 ) ;
}
}
static void F_283 ( struct V_1 * V_14 , int V_133 )
{
if ( V_14 -> V_250 == V_255 ) {
T_2 V_540 ;
if ( V_133 == - V_20 )
V_540 = V_541 ;
else
V_540 = V_539 ;
F_270 ( V_14 , V_540 ) ;
}
V_14 -> V_250 = V_251 ;
V_14 -> V_165 = V_166 ;
F_188 ( V_14 ) ;
}
void F_284 ( struct V_1 * V_14 , int V_133 )
{
T_2 V_413 = V_14 -> V_413 ;
T_2 V_537 = V_14 -> V_537 ;
F_21 ( L_64 ,
V_14 , V_133 , V_413 , V_537 ) ;
if ( V_14 -> V_23 == V_137 || V_14 -> V_23 == V_542 ) {
F_50 ( V_14 ) ;
return;
}
if ( V_14 -> V_23 != V_56 ) {
F_280 ( V_14 , V_133 , V_413 , V_537 ) ;
} else if ( V_133 != V_536 ) {
F_283 ( V_14 , V_133 ) ;
} else {
switch ( V_14 -> V_250 ) {
case V_252 :
F_281 ( V_14 , V_413 ,
V_537 ) ;
break;
case V_255 :
F_282 ( V_14 , V_133 ) ;
break;
default:
F_283 ( V_14 , V_133 ) ;
break;
}
}
}
static inline int F_285 ( struct V_2 * V_3 ,
struct V_391 * V_392 ,
T_1 V_470 , void * V_156 )
{
struct V_516 * V_235 = V_156 ;
struct V_520 V_132 ;
struct V_1 * V_14 ;
T_1 V_517 = 0 ;
T_1 V_133 = V_539 ;
if ( V_470 != sizeof( * V_235 ) )
return - V_473 ;
V_517 = F_243 ( V_235 -> V_517 ) ;
F_21 ( L_65 , V_517 , V_235 -> V_515 ) ;
if ( ! V_229 )
return - V_20 ;
V_14 = F_8 ( V_3 , V_517 ) ;
if ( ! V_14 ) {
V_132 . V_517 = F_16 ( V_517 ) ;
V_132 . V_133 = F_79 ( V_539 ) ;
F_80 ( V_3 , V_392 -> V_9 , V_521 ,
sizeof( V_132 ) , & V_132 ) ;
return 0 ;
}
V_14 -> V_9 = V_392 -> V_9 ;
if ( V_14 -> V_7 < V_21 ||
V_14 -> V_230 == V_543 ||
( V_14 -> V_119 != V_121 &&
V_14 -> V_119 != V_125 ) ) {
V_133 = V_539 ;
goto V_544;
}
if ( V_14 -> V_413 == V_235 -> V_515 ) {
V_133 = V_545 ;
goto V_544;
}
if ( V_235 -> V_515 ) {
struct V_306 * V_157 ;
V_157 = F_267 ( V_235 -> V_515 ) ;
if ( ! V_157 || V_157 -> V_509 != V_510 ||
! F_73 ( V_511 , & V_157 -> V_83 ) ) {
if ( V_157 )
F_169 ( V_157 ) ;
V_133 = V_541 ;
goto V_544;
}
F_169 ( V_157 ) ;
}
if ( ( F_90 ( V_14 ) ||
V_14 -> V_250 != V_251 ) &&
F_12 ( V_3 -> V_11 , V_3 -> V_287 ) > 0 ) {
V_133 = V_546 ;
goto V_544;
}
V_14 -> V_250 = V_255 ;
F_121 ( V_14 ) ;
V_14 -> V_414 = V_235 -> V_515 ;
V_517 = V_14 -> V_6 ;
if ( ! V_235 -> V_515 ) {
if ( F_73 ( V_226 , & V_14 -> V_220 ) ) {
V_14 -> V_165 = V_532 ;
V_133 = V_547 ;
} else {
V_14 -> V_165 = V_535 ;
V_133 = V_536 ;
}
} else {
V_14 -> V_165 = V_167 ;
V_133 = V_547 ;
}
V_544:
F_270 ( V_14 , V_133 ) ;
F_50 ( V_14 ) ;
return 0 ;
}
static void F_286 ( struct V_2 * V_3 , T_1 V_517 , T_1 V_133 )
{
struct V_1 * V_14 ;
struct V_117 * V_164 = NULL ;
V_14 = F_4 ( V_3 , V_517 ) ;
if ( ! V_14 ) {
F_272 ( V_3 , V_517 ) ;
return;
}
F_70 ( V_14 ) ;
if ( V_133 == V_547 )
F_77 ( V_14 , V_548 ) ;
switch ( V_14 -> V_165 ) {
case V_529 :
V_14 -> V_165 = V_530 ;
break;
case V_531 :
if ( V_133 == V_547 ) {
break;
} else if ( F_73 ( V_226 ,
& V_14 -> V_220 ) ) {
V_14 -> V_165 = V_532 ;
} else {
V_14 -> V_165 = V_533 ;
F_271 ( V_14 , V_534 ) ;
}
break;
case V_538 :
if ( V_133 == V_536 ) {
V_14 -> V_165 = V_530 ;
} else {
V_14 -> V_165 = V_529 ;
}
if ( ! V_164 ) {
F_271 ( V_14 , V_525 ) ;
break;
}
if ( V_164 -> V_23 != V_56 )
break;
V_14 -> V_169 = V_164 -> V_3 ;
V_14 -> V_169 -> V_313 = V_14 -> V_3 ;
if ( V_133 == V_536 ) {
F_271 ( V_14 , V_534 ) ;
} else {
V_14 -> V_165 = V_531 ;
}
F_278 ( V_14 , V_164 , V_536 ) ;
break;
default:
V_14 -> V_414 = V_14 -> V_413 ;
F_122 ( V_14 ) ;
F_271 ( V_14 , V_525 ) ;
}
F_50 ( V_14 ) ;
}
static void F_287 ( struct V_2 * V_3 , T_2 V_9 , T_1 V_517 ,
T_1 V_133 )
{
struct V_1 * V_14 ;
V_14 = F_10 ( V_3 , V_9 ) ;
if ( ! V_14 ) {
F_272 ( V_3 , V_517 ) ;
return;
}
F_70 ( V_14 ) ;
if ( V_14 -> V_250 == V_252 ) {
if ( V_133 == V_546 ) {
V_14 -> V_250 = V_255 ;
} else {
V_14 -> V_414 = V_14 -> V_413 ;
F_122 ( V_14 ) ;
}
}
F_271 ( V_14 , V_525 ) ;
F_50 ( V_14 ) ;
}
static int F_288 ( struct V_2 * V_3 ,
struct V_391 * V_392 ,
T_1 V_470 , void * V_156 )
{
struct V_520 * V_132 = V_156 ;
T_1 V_517 , V_133 ;
if ( V_470 != sizeof( * V_132 ) )
return - V_473 ;
V_517 = F_243 ( V_132 -> V_517 ) ;
V_133 = F_243 ( V_132 -> V_133 ) ;
F_21 ( L_66 , V_517 , V_133 ) ;
if ( V_133 == V_536 || V_133 == V_547 )
F_286 ( V_3 , V_517 , V_133 ) ;
else
F_287 ( V_3 , V_392 -> V_9 , V_517 , V_133 ) ;
return 0 ;
}
static int F_289 ( struct V_2 * V_3 ,
struct V_391 * V_392 ,
T_1 V_470 , void * V_156 )
{
struct V_522 * V_523 = V_156 ;
struct V_1 * V_14 ;
T_1 V_517 , V_133 ;
if ( V_470 != sizeof( * V_523 ) )
return - V_473 ;
V_517 = F_243 ( V_523 -> V_517 ) ;
V_133 = F_243 ( V_523 -> V_133 ) ;
F_21 ( L_66 , V_517 , V_133 ) ;
V_14 = F_8 ( V_3 , V_517 ) ;
if ( ! V_14 ) {
F_273 ( V_3 , V_392 -> V_9 , V_517 ) ;
return 0 ;
}
if ( V_14 -> V_165 == V_535 ) {
if ( V_133 == V_534 ) {
V_14 -> V_413 = V_14 -> V_414 ;
if ( ! V_14 -> V_413 )
F_274 ( V_14 ) ;
} else {
V_14 -> V_414 = V_14 -> V_413 ;
}
F_122 ( V_14 ) ;
}
F_273 ( V_3 , V_392 -> V_9 , V_517 ) ;
F_50 ( V_14 ) ;
return 0 ;
}
static inline int F_290 ( struct V_2 * V_3 ,
struct V_391 * V_392 ,
T_1 V_470 , void * V_156 )
{
struct V_526 * V_132 = V_156 ;
struct V_1 * V_14 ;
T_1 V_517 ;
if ( V_470 != sizeof( * V_132 ) )
return - V_473 ;
V_517 = F_243 ( V_132 -> V_517 ) ;
F_21 ( L_60 , V_517 ) ;
V_14 = F_4 ( V_3 , V_517 ) ;
if ( ! V_14 )
return 0 ;
F_70 ( V_14 ) ;
if ( V_14 -> V_165 == V_533 ) {
V_14 -> V_413 = V_14 -> V_414 ;
if ( ! V_14 -> V_413 && V_14 -> V_116 )
F_274 ( V_14 ) ;
F_122 ( V_14 ) ;
}
F_50 ( V_14 ) ;
return 0 ;
}
static inline int F_291 ( T_1 V_549 , T_1 V_550 , T_1 V_551 ,
T_1 V_552 )
{
T_1 V_553 ;
if ( V_549 > V_550 || V_549 < 6 || V_550 > 3200 )
return - V_20 ;
if ( V_552 < 10 || V_552 > 3200 )
return - V_20 ;
if ( V_550 >= V_552 * 8 )
return - V_20 ;
V_553 = ( V_552 * 8 / V_550 ) - 1 ;
if ( V_551 > 499 || V_551 > V_553 )
return - V_20 ;
return 0 ;
}
static inline int F_292 ( struct V_2 * V_3 ,
struct V_391 * V_392 ,
T_2 * V_156 )
{
struct V_168 * V_88 = V_3 -> V_88 ;
struct F_292 * V_235 ;
struct V_554 V_132 ;
T_1 V_549 , V_550 , V_551 , V_552 , V_470 ;
int V_15 ;
if ( ! ( V_88 -> V_555 & V_556 ) )
return - V_20 ;
V_470 = F_67 ( V_392 -> V_155 ) ;
if ( V_470 != sizeof( struct F_292 ) )
return - V_473 ;
V_235 = (struct F_292 * ) V_156 ;
V_549 = F_67 ( V_235 -> V_549 ) ;
V_550 = F_67 ( V_235 -> V_550 ) ;
V_551 = F_67 ( V_235 -> V_551 ) ;
V_552 = F_67 ( V_235 -> V_552 ) ;
F_21 ( L_67 ,
V_549 , V_550 , V_551 , V_552 ) ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_15 = F_291 ( V_549 , V_550 , V_551 , V_552 ) ;
if ( V_15 )
V_132 . V_133 = F_79 ( V_557 ) ;
else
V_132 . V_133 = F_79 ( V_558 ) ;
F_80 ( V_3 , V_392 -> V_9 , V_559 ,
sizeof( V_132 ) , & V_132 ) ;
if ( ! V_15 )
F_293 ( V_88 , V_549 , V_550 , V_551 , V_552 ) ;
return 0 ;
}
static inline int F_294 ( struct V_2 * V_3 ,
struct V_391 * V_392 , T_1 V_470 ,
T_2 * V_156 )
{
int V_15 = 0 ;
switch ( V_392 -> V_154 ) {
case V_489 :
F_250 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
case V_236 :
V_15 = F_254 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
case V_140 :
case V_468 :
V_15 = F_256 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
case V_285 :
V_15 = F_259 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
case V_485 :
V_15 = F_260 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
case V_274 :
V_15 = F_262 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
case V_497 :
V_15 = F_263 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
case V_560 :
F_80 ( V_3 , V_392 -> V_9 , V_561 , V_470 , V_156 ) ;
break;
case V_561 :
break;
case V_266 :
V_15 = F_264 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
case V_502 :
V_15 = F_265 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
case V_239 :
V_15 = F_266 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
case V_518 :
V_15 = F_285 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
case V_521 :
V_15 = F_288 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
case V_524 :
V_15 = F_289 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
case V_527 :
V_15 = F_290 ( V_3 , V_392 , V_470 , V_156 ) ;
break;
default:
F_295 ( L_68 , V_392 -> V_154 ) ;
V_15 = - V_20 ;
break;
}
return V_15 ;
}
static inline int F_296 ( struct V_2 * V_3 ,
struct V_391 * V_392 , T_2 * V_156 )
{
switch ( V_392 -> V_154 ) {
case V_489 :
return 0 ;
case V_562 :
return F_292 ( V_3 , V_392 , V_156 ) ;
case V_559 :
return 0 ;
default:
F_295 ( L_69 , V_392 -> V_154 ) ;
return - V_20 ;
}
}
static inline void F_297 ( struct V_2 * V_3 ,
struct V_32 * V_36 )
{
T_2 * V_156 = V_36 -> V_156 ;
int V_155 = V_36 -> V_155 ;
struct V_391 V_392 ;
int V_15 ;
F_227 ( V_3 , V_36 ) ;
while ( V_155 >= V_393 ) {
T_1 V_470 ;
memcpy ( & V_392 , V_156 , V_393 ) ;
V_156 += V_393 ;
V_155 -= V_393 ;
V_470 = F_243 ( V_392 . V_155 ) ;
F_21 ( L_70 , V_392 . V_154 , V_470 ,
V_392 . V_9 ) ;
if ( V_470 > V_155 || ! V_392 . V_9 ) {
F_21 ( L_71 ) ;
break;
}
if ( V_3 -> V_88 -> type == V_89 )
V_15 = F_296 ( V_3 , & V_392 , V_156 ) ;
else
V_15 = F_294 ( V_3 , & V_392 , V_470 , V_156 ) ;
if ( V_15 ) {
struct V_471 V_472 ;
F_295 ( L_72 , V_15 ) ;
V_472 . V_55 = F_79 ( V_474 ) ;
F_80 ( V_3 , V_392 . V_9 , V_489 ,
sizeof( V_472 ) , & V_472 ) ;
}
V_156 += V_470 ;
V_155 -= V_470 ;
}
F_92 ( V_36 ) ;
}
static int F_298 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
T_1 V_563 , V_564 ;
int V_565 ;
if ( F_73 ( V_207 , & V_14 -> V_83 ) )
V_565 = V_212 ;
else
V_565 = V_213 ;
if ( V_14 -> V_73 == V_74 ) {
F_299 ( V_36 , V_36 -> V_155 - V_217 ) ;
V_564 = F_98 ( V_36 -> V_156 + V_36 -> V_155 ) ;
V_563 = F_109 ( 0 , V_36 -> V_156 - V_565 , V_36 -> V_155 + V_565 ) ;
if ( V_563 != V_564 )
return - V_566 ;
}
return 0 ;
}
static void F_300 ( struct V_1 * V_14 )
{
struct V_173 V_37 ;
F_21 ( L_3 , V_14 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
V_37 . V_177 = 1 ;
V_37 . V_174 = V_14 -> V_227 ;
F_58 ( V_219 , & V_14 -> V_220 ) ;
if ( F_73 ( V_226 , & V_14 -> V_220 ) ) {
V_37 . V_185 = V_223 ;
F_110 ( V_14 , & V_37 ) ;
}
if ( F_111 ( V_249 , & V_14 -> V_220 ) &&
V_14 -> V_335 > 0 )
F_28 ( V_14 ) ;
F_188 ( V_14 ) ;
if ( ! F_73 ( V_226 , & V_14 -> V_220 ) &&
F_73 ( V_219 , & V_14 -> V_220 ) ) {
V_37 . V_185 = V_221 ;
F_110 ( V_14 , & V_37 ) ;
}
}
static void F_301 ( struct V_32 * V_36 , struct V_32 * V_567 ,
struct V_32 * * V_568 )
{
if ( ! F_302 ( V_36 ) )
F_204 ( V_36 ) -> V_356 = V_567 ;
V_567 -> V_308 = NULL ;
( * V_568 ) -> V_308 = V_567 ;
* V_568 = V_567 ;
V_36 -> V_155 += V_567 -> V_155 ;
V_36 -> V_360 += V_567 -> V_155 ;
V_36 -> V_569 += V_567 -> V_569 ;
}
static int F_303 ( struct V_1 * V_14 , struct V_32 * V_36 ,
struct V_173 * V_37 )
{
int V_15 = - V_20 ;
switch ( V_37 -> V_188 ) {
case V_369 :
if ( V_14 -> V_411 )
break;
V_15 = V_14 -> V_24 -> V_389 ( V_14 , V_36 ) ;
break;
case V_370 :
if ( V_14 -> V_411 )
break;
V_14 -> V_365 = F_98 ( V_36 -> V_156 ) ;
F_97 ( V_36 , V_363 ) ;
if ( V_14 -> V_365 > V_14 -> V_98 ) {
V_15 = - V_373 ;
break;
}
if ( V_36 -> V_155 >= V_14 -> V_365 )
break;
V_14 -> V_411 = V_36 ;
V_14 -> V_412 = V_36 ;
V_36 = NULL ;
V_15 = 0 ;
break;
case V_372 :
if ( ! V_14 -> V_411 )
break;
F_301 ( V_14 -> V_411 , V_36 ,
& V_14 -> V_412 ) ;
V_36 = NULL ;
if ( V_14 -> V_411 -> V_155 >= V_14 -> V_365 )
break;
V_15 = 0 ;
break;
case V_371 :
if ( ! V_14 -> V_411 )
break;
F_301 ( V_14 -> V_411 , V_36 ,
& V_14 -> V_412 ) ;
V_36 = NULL ;
if ( V_14 -> V_411 -> V_155 != V_14 -> V_365 )
break;
V_15 = V_14 -> V_24 -> V_389 ( V_14 , V_14 -> V_411 ) ;
if ( ! V_15 ) {
V_14 -> V_411 = NULL ;
V_14 -> V_412 = NULL ;
V_14 -> V_365 = 0 ;
}
break;
}
if ( V_15 ) {
F_92 ( V_36 ) ;
F_92 ( V_14 -> V_411 ) ;
V_14 -> V_411 = NULL ;
V_14 -> V_412 = NULL ;
V_14 -> V_365 = 0 ;
}
return V_15 ;
}
static int F_304 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_305 ( struct V_1 * V_14 , int V_570 )
{
T_2 V_379 ;
if ( V_14 -> V_119 != V_121 )
return;
V_379 = V_570 ? V_380 : V_382 ;
F_123 ( V_14 , NULL , NULL , V_379 ) ;
}
static int F_306 ( struct V_1 * V_14 )
{
int V_15 = 0 ;
F_21 ( L_3 , V_14 ) ;
while ( ! F_73 ( V_226 , & V_14 -> V_220 ) ) {
struct V_32 * V_36 ;
F_21 ( L_73 ,
V_14 -> V_227 , F_192 ( & V_14 -> V_122 ) ) ;
V_36 = F_34 ( & V_14 -> V_122 , V_14 -> V_227 ) ;
if ( ! V_36 )
break;
F_220 ( V_36 , & V_14 -> V_122 ) ;
V_14 -> V_227 = F_187 ( V_14 , V_14 -> V_227 ) ;
V_15 = F_303 ( V_14 , V_36 , & F_36 ( V_36 ) -> V_37 ) ;
if ( V_15 )
break;
}
if ( F_185 ( & V_14 -> V_122 ) ) {
V_14 -> V_247 = V_349 ;
F_199 ( V_14 ) ;
}
return V_15 ;
}
static void F_307 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
struct V_32 * V_36 ;
F_21 ( L_11 , V_14 , V_37 ) ;
if ( V_37 -> V_174 == V_14 -> V_340 ) {
F_21 ( L_74 , V_37 -> V_174 ) ;
F_78 ( V_14 , V_277 ) ;
return;
}
V_36 = F_34 ( & V_14 -> V_126 , V_37 -> V_174 ) ;
if ( V_36 == NULL ) {
F_21 ( L_75 ,
V_37 -> V_174 ) ;
return;
}
if ( V_14 -> V_75 != 0 && F_36 ( V_36 ) -> V_37 . V_241 >= V_14 -> V_75 ) {
F_21 ( L_24 , V_14 -> V_75 ) ;
F_78 ( V_14 , V_277 ) ;
return;
}
F_112 ( V_249 , & V_14 -> V_220 ) ;
if ( V_37 -> V_182 ) {
F_225 ( V_14 , V_37 ) ;
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_196 ( V_14 , V_37 ) ;
F_188 ( V_14 ) ;
if ( V_14 -> V_245 == V_384 ) {
F_58 ( V_244 , & V_14 -> V_220 ) ;
V_14 -> V_571 = V_37 -> V_174 ;
}
} else {
F_226 ( V_14 , V_37 ) ;
if ( V_37 -> V_177 ) {
if ( V_14 -> V_571 != V_37 -> V_174 ||
! F_111 ( V_244 ,
& V_14 -> V_220 ) )
F_196 ( V_14 , V_37 ) ;
} else {
F_196 ( V_14 , V_37 ) ;
if ( V_14 -> V_245 == V_384 ) {
F_58 ( V_244 , & V_14 -> V_220 ) ;
V_14 -> V_571 = V_37 -> V_174 ;
}
}
}
}
static void F_308 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
struct V_32 * V_36 ;
F_21 ( L_11 , V_14 , V_37 ) ;
if ( V_37 -> V_174 == V_14 -> V_340 ) {
F_21 ( L_74 , V_37 -> V_174 ) ;
F_78 ( V_14 , V_277 ) ;
return;
}
V_36 = F_34 ( & V_14 -> V_126 , V_37 -> V_174 ) ;
if ( V_14 -> V_75 && V_36 &&
F_36 ( V_36 ) -> V_37 . V_241 >= V_14 -> V_75 ) {
F_21 ( L_24 , V_14 -> V_75 ) ;
F_78 ( V_14 , V_277 ) ;
return;
}
F_112 ( V_249 , & V_14 -> V_220 ) ;
F_225 ( V_14 , V_37 ) ;
if ( V_37 -> V_177 ) {
if ( ! F_111 ( V_243 , & V_14 -> V_220 ) )
F_197 ( V_14 , V_37 ) ;
} else {
F_197 ( V_14 , V_37 ) ;
F_188 ( V_14 ) ;
if ( V_14 -> V_245 == V_384 )
F_58 ( V_243 , & V_14 -> V_220 ) ;
}
}
static T_2 F_309 ( struct V_1 * V_14 , T_1 V_38 )
{
F_21 ( L_76 , V_14 , V_38 ) ;
F_21 ( L_77 , V_14 -> V_225 ,
V_14 -> V_242 ) ;
if ( V_14 -> V_247 == V_381 ) {
if ( F_200 ( V_14 , V_38 , V_14 -> V_225 ) >=
V_14 -> V_77 ) {
if ( V_14 -> V_77 <= ( ( V_14 -> V_79 + 1 ) >> 1 ) ) {
F_21 ( L_78 ) ;
return V_572 ;
} else {
F_21 ( L_79 ) ;
return V_573 ;
}
}
if ( V_14 -> V_123 . V_34 == V_38 ) {
F_21 ( L_80 ) ;
return V_574 ;
}
if ( F_34 ( & V_14 -> V_122 , V_38 ) ) {
F_21 ( L_81 ) ;
return V_575 ;
}
if ( F_42 ( & V_14 -> V_123 , V_38 ) ) {
F_21 ( L_82 ) ;
return V_576 ;
}
}
if ( V_14 -> V_242 == V_38 ) {
if ( F_200 ( V_14 , V_38 , V_14 -> V_225 ) >=
V_14 -> V_77 ) {
F_21 ( L_83 ) ;
return V_573 ;
} else {
F_21 ( L_84 ) ;
return V_577 ;
}
}
if ( F_200 ( V_14 , V_38 , V_14 -> V_225 ) <
F_200 ( V_14 , V_14 -> V_242 , V_14 -> V_225 ) ) {
F_21 ( L_85 ) ;
return V_578 ;
}
if ( F_200 ( V_14 , V_38 , V_14 -> V_225 ) >= V_14 -> V_77 ) {
if ( V_14 -> V_77 <= ( ( V_14 -> V_79 + 1 ) >> 1 ) ) {
F_21 ( L_86 ) ;
return V_572 ;
} else {
F_21 ( L_83 ) ;
return V_573 ;
}
} else {
F_21 ( L_87 ) ;
return V_579 ;
}
}
static int F_310 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_379 )
{
int V_15 = 0 ;
bool V_580 = 0 ;
F_21 ( L_88 , V_14 , V_37 , V_36 ,
V_379 ) ;
switch ( V_379 ) {
case V_581 :
switch ( F_309 ( V_14 , V_37 -> V_38 ) ) {
case V_577 :
F_225 ( V_14 , V_37 ) ;
if ( F_73 ( V_226 , & V_14 -> V_220 ) ) {
F_21 ( L_89 ,
V_37 -> V_38 ) ;
break;
}
V_14 -> V_242 = F_187 ( V_14 ,
V_37 -> V_38 ) ;
V_14 -> V_227 = V_14 -> V_242 ;
V_580 = 1 ;
V_15 = F_303 ( V_14 , V_36 , V_37 ) ;
if ( V_15 )
break;
if ( V_37 -> V_177 ) {
if ( ! F_111 ( V_243 ,
& V_14 -> V_220 ) ) {
V_37 -> V_177 = 0 ;
F_197 ( V_14 , V_37 ) ;
F_188 ( V_14 ) ;
}
}
if ( ! F_73 ( V_226 , & V_14 -> V_220 ) )
F_199 ( V_14 ) ;
break;
case V_579 :
F_225 ( V_14 , V_37 ) ;
if ( F_73 ( V_226 , & V_14 -> V_220 ) ) {
F_21 ( L_90 ,
V_37 -> V_38 ) ;
break;
}
F_311 ( & V_14 -> V_122 , V_36 ) ;
V_580 = 1 ;
F_21 ( L_91 , V_36 ,
F_192 ( & V_14 -> V_122 ) ) ;
F_112 ( V_244 , & V_14 -> V_220 ) ;
F_45 ( & V_14 -> V_123 ) ;
F_216 ( V_14 , V_37 -> V_38 ) ;
V_14 -> V_247 = V_381 ;
break;
case V_578 :
F_225 ( V_14 , V_37 ) ;
break;
case V_572 :
break;
case V_573 :
default:
F_78 ( V_14 , V_277 ) ;
break;
}
break;
case V_582 :
F_225 ( V_14 , V_37 ) ;
if ( V_37 -> V_177 ) {
F_112 ( V_249 , & V_14 -> V_220 ) ;
if ( ! F_111 ( V_243 , & V_14 -> V_220 ) &&
! F_90 ( V_14 ) ) {
V_37 -> V_177 = 0 ;
F_197 ( V_14 , V_37 ) ;
}
F_188 ( V_14 ) ;
} else if ( V_37 -> V_182 ) {
F_300 ( V_14 ) ;
} else {
if ( F_111 ( V_249 ,
& V_14 -> V_220 ) &&
V_14 -> V_335 )
F_28 ( V_14 ) ;
F_188 ( V_14 ) ;
}
break;
case V_583 :
F_58 ( V_249 , & V_14 -> V_220 ) ;
F_225 ( V_14 , V_37 ) ;
if ( V_37 && V_37 -> V_182 ) {
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_114 ( V_14 , 0 ) ;
}
F_33 ( V_14 ) ;
F_45 ( & V_14 -> V_124 ) ;
break;
case V_584 :
F_308 ( V_14 , V_37 ) ;
break;
case V_585 :
F_307 ( V_14 , V_37 ) ;
break;
default:
break;
}
if ( V_36 && ! V_580 ) {
F_21 ( L_92 , V_36 ) ;
F_92 ( V_36 ) ;
}
return V_15 ;
}
static int F_312 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_379 )
{
int V_15 = 0 ;
T_1 V_38 = V_37 -> V_38 ;
bool V_580 = 0 ;
F_21 ( L_88 , V_14 , V_37 , V_36 ,
V_379 ) ;
switch ( V_379 ) {
case V_581 :
switch ( F_309 ( V_14 , V_38 ) ) {
case V_577 :
F_225 ( V_14 , V_37 ) ;
F_311 ( & V_14 -> V_122 , V_36 ) ;
V_580 = 1 ;
F_21 ( L_91 , V_36 ,
F_192 ( & V_14 -> V_122 ) ) ;
V_14 -> V_242 = F_187 ( V_14 , V_38 ) ;
break;
case V_574 :
F_44 ( & V_14 -> V_123 ) ;
F_225 ( V_14 , V_37 ) ;
F_311 ( & V_14 -> V_122 , V_36 ) ;
V_580 = 1 ;
F_21 ( L_91 , V_36 ,
F_192 ( & V_14 -> V_122 ) ) ;
V_15 = F_306 ( V_14 ) ;
if ( V_15 )
break;
break;
case V_579 :
F_311 ( & V_14 -> V_122 , V_36 ) ;
V_580 = 1 ;
F_21 ( L_91 , V_36 ,
F_192 ( & V_14 -> V_122 ) ) ;
F_225 ( V_14 , V_37 ) ;
F_216 ( V_14 , V_37 -> V_38 ) ;
break;
case V_576 :
F_311 ( & V_14 -> V_122 , V_36 ) ;
V_580 = 1 ;
F_21 ( L_91 , V_36 ,
F_192 ( & V_14 -> V_122 ) ) ;
F_225 ( V_14 , V_37 ) ;
F_218 ( V_14 , V_37 -> V_38 ) ;
break;
case V_575 :
F_225 ( V_14 , V_37 ) ;
break;
case V_578 :
break;
case V_572 :
break;
case V_573 :
default:
F_78 ( V_14 , V_277 ) ;
break;
}
break;
case V_582 :
F_225 ( V_14 , V_37 ) ;
if ( V_37 -> V_177 ) {
F_112 ( V_249 , & V_14 -> V_220 ) ;
if ( ! F_111 ( V_243 ,
& V_14 -> V_220 ) ) {
V_37 -> V_177 = 0 ;
F_197 ( V_14 , V_37 ) ;
}
F_188 ( V_14 ) ;
} else if ( V_37 -> V_182 ) {
if ( F_111 ( V_249 ,
& V_14 -> V_220 ) &&
V_14 -> V_335 ) {
F_28 ( V_14 ) ;
}
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_217 ( V_14 ) ;
} else {
if ( F_111 ( V_249 ,
& V_14 -> V_220 ) &&
V_14 -> V_335 )
F_28 ( V_14 ) ;
F_199 ( V_14 ) ;
}
break;
case V_583 :
F_58 ( V_249 , & V_14 -> V_220 ) ;
F_225 ( V_14 , V_37 ) ;
if ( V_37 -> V_182 ) {
F_217 ( V_14 ) ;
} else {
struct V_173 V_586 ;
memset ( & V_586 , 0 , sizeof( V_586 ) ) ;
V_586 . V_181 = 1 ;
V_586 . V_185 = V_221 ;
V_586 . V_174 = V_14 -> V_227 ;
F_110 ( V_14 , & V_586 ) ;
}
break;
case V_584 :
F_308 ( V_14 , V_37 ) ;
break;
case V_585 :
F_307 ( V_14 , V_37 ) ;
break;
}
if ( V_36 && ! V_580 ) {
F_21 ( L_92 , V_36 ) ;
F_92 ( V_36 ) ;
}
return V_15 ;
}
static int F_313 ( struct V_1 * V_14 )
{
F_21 ( L_3 , V_14 ) ;
V_14 -> V_247 = V_349 ;
if ( V_14 -> V_169 )
V_14 -> V_3 -> V_320 = V_14 -> V_169 -> V_157 -> V_513 ;
else
V_14 -> V_3 -> V_320 = V_14 -> V_3 -> V_88 -> V_157 -> V_321 ;
return F_304 ( V_14 ) ;
}
static int F_314 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_379 )
{
int V_15 ;
F_21 ( L_88 , V_14 , V_37 , V_36 ,
V_379 ) ;
if ( ! V_37 -> V_182 )
return - V_473 ;
F_219 ( V_14 , V_37 -> V_174 ) ;
if ( ! F_185 ( & V_14 -> V_126 ) )
V_14 -> V_345 = F_223 ( & V_14 -> V_126 ) ;
else
V_14 -> V_345 = NULL ;
V_14 -> V_340 = V_37 -> V_174 ;
V_14 -> V_335 = 0 ;
V_15 = F_313 ( V_14 ) ;
if ( V_15 )
return V_15 ;
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_300 ( V_14 ) ;
if ( V_379 == V_581 )
return - V_473 ;
return F_310 ( V_14 , V_37 , NULL , V_379 ) ;
}
static int F_315 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_379 )
{
int V_15 ;
if ( ! V_37 -> V_177 )
return - V_473 ;
F_112 ( V_249 , & V_14 -> V_220 ) ;
V_14 -> V_247 = V_349 ;
F_219 ( V_14 , V_37 -> V_174 ) ;
if ( ! F_185 ( & V_14 -> V_126 ) )
V_14 -> V_345 = F_223 ( & V_14 -> V_126 ) ;
else
V_14 -> V_345 = NULL ;
V_14 -> V_340 = V_37 -> V_174 ;
V_14 -> V_335 = 0 ;
if ( V_14 -> V_169 )
V_14 -> V_3 -> V_320 = V_14 -> V_169 -> V_157 -> V_513 ;
else
V_14 -> V_3 -> V_320 = V_14 -> V_3 -> V_88 -> V_157 -> V_321 ;
V_15 = F_304 ( V_14 ) ;
if ( ! V_15 )
V_15 = F_310 ( V_14 , V_37 , V_36 , V_379 ) ;
return V_15 ;
}
static bool F_316 ( struct V_1 * V_14 , T_1 V_174 )
{
T_1 V_587 ;
V_587 = F_200 ( V_14 , V_14 -> V_340 , V_14 -> V_378 ) ;
return F_200 ( V_14 , V_14 -> V_340 , V_174 ) <= V_587 ;
}
static int F_317 ( struct V_1 * V_14 , struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_379 )
{
int V_15 = 0 ;
F_21 ( L_93 , V_14 ,
V_37 , V_36 , V_379 , V_14 -> V_247 ) ;
if ( F_316 ( V_14 , V_37 -> V_174 ) ) {
switch ( V_14 -> V_247 ) {
case V_349 :
V_15 = F_310 ( V_14 , V_37 , V_36 , V_379 ) ;
break;
case V_381 :
V_15 = F_312 ( V_14 , V_37 , V_36 ,
V_379 ) ;
break;
case V_256 :
V_15 = F_314 ( V_14 , V_37 , V_36 , V_379 ) ;
break;
case V_254 :
V_15 = F_315 ( V_14 , V_37 , V_36 , V_379 ) ;
break;
default:
break;
}
} else {
F_21 ( L_94 ,
V_37 -> V_174 , V_14 -> V_340 ,
V_14 -> V_378 ) ;
F_78 ( V_14 , V_277 ) ;
}
return V_15 ;
}
static int F_318 ( struct V_1 * V_14 , struct V_173 * V_37 ,
struct V_32 * V_36 )
{
int V_15 = 0 ;
F_21 ( L_95 , V_14 , V_37 , V_36 ,
V_14 -> V_247 ) ;
if ( F_309 ( V_14 , V_37 -> V_38 ) ==
V_577 ) {
F_225 ( V_14 , V_37 ) ;
F_21 ( L_96 , V_14 -> V_227 ,
F_187 ( V_14 , V_14 -> V_227 ) ) ;
V_14 -> V_227 = F_187 ( V_14 , V_14 -> V_227 ) ;
F_303 ( V_14 , V_36 , V_37 ) ;
} else {
if ( V_14 -> V_411 ) {
F_92 ( V_14 -> V_411 ) ;
V_14 -> V_411 = NULL ;
}
V_14 -> V_412 = NULL ;
V_14 -> V_365 = 0 ;
if ( V_36 ) {
F_21 ( L_92 , V_36 ) ;
F_92 ( V_36 ) ;
}
}
V_14 -> V_225 = V_37 -> V_38 ;
V_14 -> V_242 = F_187 ( V_14 , V_37 -> V_38 ) ;
return V_15 ;
}
static int F_319 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
struct V_173 * V_37 = & F_36 ( V_36 ) -> V_37 ;
T_1 V_155 ;
T_2 V_379 ;
F_95 ( V_14 , V_36 ) ;
V_155 = V_36 -> V_155 ;
if ( F_298 ( V_14 , V_36 ) )
goto V_588;
if ( ! V_37 -> V_181 && V_37 -> V_188 == V_370 )
V_155 -= V_363 ;
if ( V_14 -> V_73 == V_74 )
V_155 -= V_217 ;
if ( V_155 > V_14 -> V_466 ) {
F_78 ( V_14 , V_277 ) ;
goto V_588;
}
if ( ! V_37 -> V_181 ) {
int V_15 ;
F_21 ( L_97 ,
V_37 -> V_188 , V_37 -> V_174 , V_37 -> V_177 ,
V_37 -> V_38 ) ;
if ( V_37 -> V_177 && V_14 -> V_245 != V_384 )
goto V_588;
if ( V_14 -> V_119 != V_125 ) {
V_379 = V_581 ;
V_15 = F_317 ( V_14 , V_37 , V_36 , V_379 ) ;
} else {
V_15 = F_318 ( V_14 , V_37 , V_36 ) ;
}
if ( V_15 )
F_78 ( V_14 , V_277 ) ;
} else {
const T_2 V_589 [ 4 ] = {
V_582 , V_584 ,
V_583 , V_585
} ;
if ( V_14 -> V_119 == V_125 )
goto V_588;
F_21 ( L_98 ,
V_37 -> V_174 , V_37 -> V_177 , V_37 -> V_182 ,
V_37 -> V_185 ) ;
if ( V_155 != 0 ) {
F_295 ( L_99 , V_155 ) ;
F_78 ( V_14 , V_277 ) ;
goto V_588;
}
if ( V_37 -> V_177 && ( V_37 -> V_182 ||
V_14 -> V_245 != V_384 ) )
goto V_588;
V_379 = V_589 [ V_37 -> V_185 ] ;
if ( F_317 ( V_14 , V_37 , V_36 , V_379 ) )
F_78 ( V_14 , V_277 ) ;
}
return 0 ;
V_588:
F_92 ( V_36 ) ;
return 0 ;
}
static void F_320 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_4 ( V_3 , V_4 ) ;
if ( ! V_14 ) {
if ( V_4 == V_96 ) {
V_14 = F_321 ( V_3 , V_36 ) ;
if ( ! V_14 ) {
F_92 ( V_36 ) ;
return;
}
F_6 ( V_14 ) ;
} else {
F_21 ( L_100 , V_4 ) ;
F_92 ( V_36 ) ;
return;
}
}
F_21 ( L_101 , V_14 , V_36 -> V_155 ) ;
if ( V_14 -> V_23 != V_56 )
goto V_588;
switch ( V_14 -> V_119 ) {
case V_120 :
if ( V_14 -> V_98 < V_36 -> V_155 )
goto V_588;
if ( ! V_14 -> V_24 -> V_389 ( V_14 , V_36 ) )
goto V_18;
break;
case V_121 :
case V_125 :
F_319 ( V_14 , V_36 ) ;
goto V_18;
default:
F_21 ( L_102 , V_14 , V_14 -> V_119 ) ;
break;
}
V_588:
F_92 ( V_36 ) ;
V_18:
F_50 ( V_14 ) ;
}
static void F_322 ( struct V_2 * V_3 , T_3 V_10 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_164 ( 0 , V_10 , V_3 -> V_11 , V_3 -> V_287 ) ;
if ( ! V_14 )
goto V_588;
F_21 ( L_101 , V_14 , V_36 -> V_155 ) ;
if ( V_14 -> V_23 != V_327 && V_14 -> V_23 != V_56 )
goto V_588;
if ( V_14 -> V_98 < V_36 -> V_155 )
goto V_588;
if ( ! V_14 -> V_24 -> V_389 ( V_14 , V_36 ) )
return;
V_588:
F_92 ( V_36 ) ;
}
static void F_323 ( struct V_2 * V_3 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_133 ( 0 , V_92 ,
V_3 -> V_11 , V_3 -> V_287 ) ;
if ( ! V_14 )
goto V_588;
F_21 ( L_101 , V_14 , V_36 -> V_155 ) ;
if ( V_14 -> V_23 != V_327 && V_14 -> V_23 != V_56 )
goto V_588;
if ( V_14 -> V_98 < V_36 -> V_155 )
goto V_588;
if ( ! V_14 -> V_24 -> V_389 ( V_14 , V_36 ) )
return;
V_588:
F_92 ( V_36 ) ;
}
static void F_324 ( struct V_2 * V_3 , struct V_32 * V_36 )
{
struct V_214 * V_215 = ( void * ) V_36 -> V_156 ;
T_1 V_4 , V_155 ;
T_3 V_10 ;
F_97 ( V_36 , V_211 ) ;
V_4 = F_67 ( V_215 -> V_4 ) ;
V_155 = F_67 ( V_215 -> V_155 ) ;
if ( V_155 != V_36 -> V_155 ) {
F_92 ( V_36 ) ;
return;
}
F_21 ( L_103 , V_155 , V_4 ) ;
switch ( V_4 ) {
case V_394 :
case V_99 :
F_297 ( V_3 , V_36 ) ;
break;
case V_94 :
V_10 = F_325 ( ( T_3 * ) V_36 -> V_156 ) ;
F_97 ( V_36 , V_361 ) ;
F_322 ( V_3 , V_10 , V_36 ) ;
break;
case V_92 :
F_323 ( V_3 , V_36 ) ;
break;
case V_590 :
if ( F_326 ( V_3 , V_36 ) )
F_150 ( V_3 -> V_88 , V_591 ) ;
break;
default:
F_320 ( V_3 , V_4 , V_36 ) ;
break;
}
}
int F_327 ( struct V_306 * V_157 , T_4 * V_322 )
{
int V_592 = 0 , V_593 = 0 , V_594 = 0 ;
struct V_1 * V_5 ;
F_21 ( L_104 , V_157 -> V_595 , V_322 ) ;
F_134 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
if ( V_5 -> V_23 != V_127 )
continue;
if ( ! F_12 ( & F_13 ( V_13 ) -> V_11 , & V_157 -> V_322 ) ) {
V_593 |= V_596 ;
if ( F_73 ( V_597 , & V_5 -> V_83 ) )
V_593 |= V_556 ;
V_592 ++ ;
} else if ( ! F_12 ( & F_13 ( V_13 ) -> V_11 , V_293 ) ) {
V_594 |= V_596 ;
if ( F_73 ( V_597 , & V_5 -> V_83 ) )
V_594 |= V_556 ;
}
}
F_135 ( & V_16 ) ;
return V_592 ? V_593 : V_594 ;
}
void F_328 ( struct V_168 * V_88 , T_2 V_138 )
{
struct V_2 * V_3 ;
F_21 ( L_105 , V_88 , & V_88 -> V_287 , V_138 ) ;
if ( ! V_138 ) {
V_3 = F_156 ( V_88 ) ;
if ( V_3 )
F_139 ( V_3 ) ;
} else {
F_150 ( V_88 , F_329 ( V_138 ) ) ;
}
}
int F_330 ( struct V_168 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_313 ;
F_21 ( L_106 , V_88 ) ;
if ( ! V_3 )
return V_85 ;
return V_3 -> V_84 ;
}
void F_331 ( struct V_168 * V_88 , T_2 V_55 )
{
F_21 ( L_107 , V_88 , V_55 ) ;
F_150 ( V_88 , F_329 ( V_55 ) ) ;
}
static inline void F_332 ( struct V_1 * V_14 , T_2 V_598 )
{
if ( V_14 -> V_86 != V_87 )
return;
if ( V_598 == 0x00 ) {
if ( V_14 -> V_60 == V_144 ) {
F_77 ( V_14 , V_599 ) ;
} else if ( V_14 -> V_60 == V_142 )
F_49 ( V_14 , V_58 ) ;
} else {
if ( V_14 -> V_60 == V_144 )
F_70 ( V_14 ) ;
}
}
int F_333 ( struct V_168 * V_88 , T_2 V_138 , T_2 V_598 )
{
struct V_2 * V_3 = V_88 -> V_313 ;
struct V_1 * V_14 ;
if ( ! V_3 )
return 0 ;
F_21 ( L_108 , V_3 , V_138 , V_598 ) ;
if ( V_88 -> type == V_89 ) {
if ( ! V_138 && V_598 )
F_334 ( V_3 , 0 ) ;
F_251 ( & V_3 -> V_317 ) ;
}
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
F_6 ( V_14 ) ;
F_21 ( L_109 , V_14 , V_14 -> V_7 ,
F_22 ( V_14 -> V_23 ) ) ;
if ( V_14 -> V_86 == V_95 ) {
F_50 ( V_14 ) ;
continue;
}
if ( V_14 -> V_7 == V_92 ) {
if ( ! V_138 && V_598 ) {
V_14 -> V_60 = V_88 -> V_60 ;
F_124 ( V_14 ) ;
}
F_50 ( V_14 ) ;
continue;
}
if ( ! F_115 ( V_14 ) ) {
F_50 ( V_14 ) ;
continue;
}
if ( ! V_138 && ( V_14 -> V_23 == V_56 ||
V_14 -> V_23 == V_57 ) ) {
struct V_26 * V_13 = V_14 -> V_13 ;
F_112 ( V_600 , & F_13 ( V_13 ) -> V_83 ) ;
V_13 -> V_302 ( V_13 ) ;
F_332 ( V_14 , V_598 ) ;
F_50 ( V_14 ) ;
continue;
}
if ( V_14 -> V_23 == V_59 ) {
if ( ! V_138 ) {
F_125 ( V_14 ) ;
} else {
F_77 ( V_14 , V_601 ) ;
}
} else if ( V_14 -> V_23 == V_130 ) {
struct V_26 * V_13 = V_14 -> V_13 ;
struct V_131 V_132 ;
T_5 V_602 , V_603 ;
F_24 ( V_13 ) ;
if ( ! V_138 ) {
if ( F_73 ( V_134 ,
& F_13 ( V_13 ) -> V_83 ) ) {
V_602 = V_279 ;
V_603 = V_280 ;
V_14 -> V_24 -> V_281 ( V_14 ) ;
} else {
F_20 ( V_14 , V_57 ) ;
V_602 = V_282 ;
V_603 = V_139 ;
}
} else {
F_20 ( V_14 , V_137 ) ;
F_77 ( V_14 , V_601 ) ;
V_602 = V_135 ;
V_603 = V_139 ;
}
F_25 ( V_13 ) ;
V_132 . V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_6 = F_16 ( V_14 -> V_7 ) ;
V_132 . V_133 = F_16 ( V_602 ) ;
V_132 . V_138 = F_16 ( V_603 ) ;
F_80 ( V_3 , V_14 -> V_9 , V_140 ,
sizeof( V_132 ) , & V_132 ) ;
if ( ! F_73 ( V_284 , & V_14 -> V_71 ) &&
V_602 == V_282 ) {
char V_278 [ 128 ] ;
F_58 ( V_284 , & V_14 -> V_71 ) ;
F_80 ( V_3 , F_84 ( V_3 ) ,
V_285 ,
F_132 ( V_14 , V_278 ) ,
V_278 ) ;
V_14 -> V_286 ++ ;
}
}
F_50 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
int F_335 ( struct V_168 * V_88 , struct V_32 * V_36 , T_1 V_83 )
{
struct V_2 * V_3 = V_88 -> V_313 ;
struct V_214 * V_604 ;
int V_155 ;
if ( ! V_3 && V_88 -> V_157 -> V_509 != V_605 )
goto V_588;
if ( ! V_3 )
V_3 = F_156 ( V_88 ) ;
if ( ! V_3 )
goto V_588;
F_21 ( L_110 , V_3 , V_36 -> V_155 , V_83 ) ;
switch ( V_83 ) {
case V_159 :
case V_158 :
case V_170 :
if ( V_3 -> V_606 ) {
F_295 ( L_111 , V_36 -> V_155 ) ;
F_92 ( V_3 -> V_315 ) ;
V_3 -> V_315 = NULL ;
V_3 -> V_606 = 0 ;
F_141 ( V_3 , V_607 ) ;
}
if ( V_36 -> V_155 < V_211 ) {
F_295 ( L_112 , V_36 -> V_155 ) ;
F_141 ( V_3 , V_607 ) ;
goto V_588;
}
V_604 = (struct V_214 * ) V_36 -> V_156 ;
V_155 = F_67 ( V_604 -> V_155 ) + V_211 ;
if ( V_155 == V_36 -> V_155 ) {
F_324 ( V_3 , V_36 ) ;
return 0 ;
}
F_21 ( L_113 , V_155 , V_36 -> V_155 ) ;
if ( V_36 -> V_155 > V_155 ) {
F_295 ( L_114 ,
V_36 -> V_155 , V_155 ) ;
F_141 ( V_3 , V_607 ) ;
goto V_588;
}
V_3 -> V_315 = F_106 ( V_155 , V_45 ) ;
if ( ! V_3 -> V_315 )
goto V_588;
F_336 ( V_36 , F_108 ( V_3 -> V_315 , V_36 -> V_155 ) ,
V_36 -> V_155 ) ;
V_3 -> V_606 = V_155 - V_36 -> V_155 ;
break;
case V_608 :
F_21 ( L_115 , V_36 -> V_155 , V_3 -> V_606 ) ;
if ( ! V_3 -> V_606 ) {
F_295 ( L_116 , V_36 -> V_155 ) ;
F_141 ( V_3 , V_607 ) ;
goto V_588;
}
if ( V_36 -> V_155 > V_3 -> V_606 ) {
F_295 ( L_117 ,
V_36 -> V_155 , V_3 -> V_606 ) ;
F_92 ( V_3 -> V_315 ) ;
V_3 -> V_315 = NULL ;
V_3 -> V_606 = 0 ;
F_141 ( V_3 , V_607 ) ;
goto V_588;
}
F_336 ( V_36 , F_108 ( V_3 -> V_315 , V_36 -> V_155 ) ,
V_36 -> V_155 ) ;
V_3 -> V_606 -= V_36 -> V_155 ;
if ( ! V_3 -> V_606 ) {
F_324 ( V_3 , V_3 -> V_315 ) ;
V_3 -> V_315 = NULL ;
}
break;
}
V_588:
F_92 ( V_36 ) ;
return 0 ;
}
static int F_337 ( struct V_609 * V_610 , void * V_19 )
{
struct V_1 * V_5 ;
F_134 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
F_338 ( V_610 , L_118 ,
& F_13 ( V_13 ) -> V_11 , & F_13 ( V_13 ) -> V_287 ,
V_5 -> V_23 , F_67 ( V_5 -> V_10 ) ,
V_5 -> V_7 , V_5 -> V_6 , V_5 -> V_98 , V_5 -> V_90 ,
V_5 -> V_60 , V_5 -> V_119 ) ;
}
F_135 ( & V_16 ) ;
return 0 ;
}
static int F_339 ( struct V_611 * V_611 , struct V_612 * V_612 )
{
return F_340 ( V_612 , F_337 , V_611 -> V_613 ) ;
}
int T_11 F_341 ( void )
{
int V_15 ;
V_15 = F_342 () ;
if ( V_15 < 0 )
return V_15 ;
if ( V_614 ) {
V_615 = F_343 ( L_119 , 0444 , V_614 ,
NULL , & V_616 ) ;
if ( ! V_615 )
F_295 ( L_120 ) ;
}
return 0 ;
}
void F_344 ( void )
{
F_345 ( V_615 ) ;
F_346 () ;
}
