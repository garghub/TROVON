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
static void F_143 ( struct V_168 * V_88 , int V_15 )
{
struct V_2 * V_3 = V_88 -> V_304 ;
struct V_1 * V_14 , * V_305 ;
if ( ! V_3 )
return;
F_21 ( L_17 , V_88 , V_3 , V_15 ) ;
F_92 ( V_3 -> V_306 ) ;
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
F_144 ( V_3 -> V_164 ) ;
if ( V_3 -> V_258 & V_259 )
F_145 ( & V_3 -> V_264 ) ;
if ( F_111 ( V_307 , & V_88 -> V_83 ) ) {
F_145 ( & V_3 -> V_308 ) ;
F_146 ( V_3 ) ;
}
V_88 -> V_304 = NULL ;
F_41 ( V_3 ) ;
}
static void F_147 ( struct V_52 * V_53 )
{
struct V_2 * V_3 = F_48 ( V_53 , struct V_2 ,
V_308 . V_53 ) ;
F_21 ( L_15 , V_3 ) ;
if ( F_111 ( V_307 , & V_3 -> V_88 -> V_83 ) ) {
F_146 ( V_3 ) ;
F_143 ( V_3 -> V_88 , V_62 ) ;
}
}
static struct V_2 * F_148 ( struct V_168 * V_88 , T_2 V_138 )
{
struct V_2 * V_3 = V_88 -> V_304 ;
struct V_117 * V_164 ;
if ( V_3 || V_138 )
return V_3 ;
V_164 = F_149 ( V_88 ) ;
if ( ! V_164 )
return NULL ;
V_3 = F_53 ( sizeof( struct V_2 ) , V_45 ) ;
if ( ! V_3 ) {
F_144 ( V_164 ) ;
return NULL ;
}
V_88 -> V_304 = V_3 ;
V_3 -> V_88 = V_88 ;
V_3 -> V_164 = V_164 ;
F_21 ( L_18 , V_88 , V_3 , V_164 ) ;
switch ( V_88 -> type ) {
case V_309 :
V_3 -> V_310 = V_88 -> V_157 -> V_311 ;
break;
case V_89 :
if ( V_88 -> V_157 -> V_312 ) {
V_3 -> V_310 = V_88 -> V_157 -> V_312 ;
break;
}
default:
V_3 -> V_310 = V_88 -> V_157 -> V_313 ;
break;
}
V_3 -> V_11 = & V_88 -> V_157 -> V_314 ;
V_3 -> V_287 = & V_88 -> V_287 ;
V_3 -> V_267 = 0 ;
F_150 ( & V_3 -> V_65 ) ;
F_54 ( & V_3 -> V_8 ) ;
F_151 ( & V_3 -> V_112 ) ;
if ( V_88 -> type == V_89 )
F_56 ( & V_3 -> V_308 , F_147 ) ;
else
F_56 ( & V_3 -> V_264 , F_142 ) ;
V_3 -> V_84 = V_85 ;
return V_3 ;
}
static struct V_1 * F_152 ( int V_23 , T_3 V_10 ,
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
int F_153 ( struct V_1 * V_14 , T_3 V_10 , T_1 V_4 ,
T_4 * V_287 , T_2 V_315 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
T_4 * V_11 = & F_13 ( V_13 ) -> V_11 ;
struct V_2 * V_3 ;
struct V_168 * V_88 ;
struct V_316 * V_157 ;
T_7 V_151 ;
int V_15 ;
F_21 ( L_19 , V_11 , V_287 ,
V_315 , F_67 ( V_10 ) ) ;
V_157 = F_154 ( V_287 , V_11 ) ;
if ( ! V_157 )
return - V_317 ;
F_155 ( V_157 ) ;
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
V_15 = - V_318 ;
goto V_18;
}
switch ( V_14 -> V_23 ) {
case V_59 :
case V_130 :
case V_57 :
V_15 = 0 ;
goto V_18;
case V_56 :
V_15 = - V_319 ;
goto V_18;
case V_68 :
case V_320 :
break;
default:
V_15 = - V_321 ;
goto V_18;
}
F_24 ( V_13 ) ;
F_138 ( & F_13 ( V_13 ) -> V_287 , V_287 ) ;
F_25 ( V_13 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_4 ;
V_151 = F_81 ( V_14 ) ;
if ( V_14 -> V_6 == V_92 )
V_88 = F_156 ( V_157 , V_89 , V_287 , V_315 ,
V_14 -> V_60 , V_151 ) ;
else
V_88 = F_156 ( V_157 , V_128 , V_287 , V_315 ,
V_14 -> V_60 , V_151 ) ;
if ( F_113 ( V_88 ) ) {
V_15 = F_157 ( V_88 ) ;
goto V_18;
}
V_3 = F_148 ( V_88 , 0 ) ;
if ( ! V_3 ) {
F_71 ( V_88 ) ;
V_15 = - V_46 ;
goto V_18;
}
if ( V_88 -> type == V_89 ) {
V_15 = 0 ;
if ( ! F_158 ( & V_3 -> V_112 ) ) {
V_15 = - V_322 ;
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
F_159 ( V_157 ) ;
F_160 ( V_157 ) ;
return V_15 ;
}
int F_161 ( struct V_26 * V_13 )
{
struct V_1 * V_14 = F_162 ( V_13 ) -> V_14 ;
F_163 ( V_323 , V_324 ) ;
int V_15 = 0 ;
int V_325 = V_326 / 5 ;
F_164 ( F_165 ( V_13 ) , & V_323 ) ;
F_166 ( V_327 ) ;
while ( V_14 -> V_328 > 0 && V_14 -> V_3 ) {
if ( ! V_325 )
V_325 = V_326 / 5 ;
if ( F_167 ( V_324 ) ) {
V_15 = F_168 ( V_325 ) ;
break;
}
F_25 ( V_13 ) ;
V_325 = F_169 ( V_325 ) ;
F_24 ( V_13 ) ;
F_166 ( V_327 ) ;
V_15 = F_170 ( V_13 ) ;
if ( V_15 )
break;
}
F_166 ( V_329 ) ;
F_171 ( F_165 ( V_13 ) , & V_323 ) ;
return V_15 ;
}
static void F_172 ( struct V_52 * V_53 )
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
F_123 ( V_14 , NULL , NULL , V_330 ) ;
F_50 ( V_14 ) ;
F_51 ( V_14 ) ;
}
static void F_173 ( struct V_52 * V_53 )
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
F_123 ( V_14 , NULL , NULL , V_331 ) ;
F_50 ( V_14 ) ;
F_51 ( V_14 ) ;
}
static void F_174 ( struct V_1 * V_14 ,
struct V_33 * V_332 )
{
struct V_32 * V_36 ;
struct V_173 * V_37 ;
F_21 ( L_20 , V_14 , V_332 ) ;
if ( F_90 ( V_14 ) )
return;
F_175 ( V_332 , & V_14 -> V_126 ) ;
while ( ! F_176 ( & V_14 -> V_126 ) ) {
V_36 = F_177 ( & V_14 -> V_126 ) ;
F_36 ( V_36 ) -> V_37 . V_241 = 1 ;
V_37 = & F_36 ( V_36 ) -> V_37 ;
V_37 -> V_174 = 0 ;
V_37 -> V_38 = V_14 -> V_333 ;
F_101 ( V_14 , V_37 , V_36 ) ;
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_109 ( 0 , ( T_2 * ) V_36 -> V_156 , V_36 -> V_155 ) ;
F_103 ( V_73 , F_108 ( V_36 , V_217 ) ) ;
}
F_91 ( V_14 , V_36 ) ;
F_21 ( L_21 , V_37 -> V_38 ) ;
V_14 -> V_333 = F_178 ( V_14 , V_14 -> V_333 ) ;
V_14 -> V_334 ++ ;
}
}
static int F_179 ( struct V_1 * V_14 )
{
struct V_32 * V_36 , * V_335 ;
struct V_173 * V_37 ;
int V_336 = 0 ;
F_21 ( L_3 , V_14 ) ;
if ( V_14 -> V_23 != V_56 )
return - V_337 ;
if ( F_73 ( V_249 , & V_14 -> V_220 ) )
return 0 ;
if ( F_90 ( V_14 ) )
return 0 ;
while ( V_14 -> V_338 &&
V_14 -> V_328 < V_14 -> V_339 &&
V_14 -> V_245 == V_246 ) {
V_36 = V_14 -> V_338 ;
F_36 ( V_36 ) -> V_37 . V_241 = 1 ;
V_37 = & F_36 ( V_36 ) -> V_37 ;
if ( F_111 ( V_219 , & V_14 -> V_220 ) )
V_37 -> V_177 = 1 ;
V_37 -> V_174 = V_14 -> V_227 ;
V_14 -> V_225 = V_14 -> V_227 ;
V_37 -> V_38 = V_14 -> V_333 ;
F_101 ( V_14 , V_37 , V_36 ) ;
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_109 ( 0 , ( T_2 * ) V_36 -> V_156 , V_36 -> V_155 ) ;
F_103 ( V_73 , F_108 ( V_36 , V_217 ) ) ;
}
V_335 = F_180 ( V_36 , V_45 ) ;
if ( ! V_335 )
break;
F_28 ( V_14 ) ;
V_14 -> V_333 = F_178 ( V_14 , V_14 -> V_333 ) ;
V_14 -> V_328 ++ ;
V_14 -> V_334 ++ ;
V_336 ++ ;
if ( F_181 ( & V_14 -> V_126 , V_36 ) )
V_14 -> V_338 = NULL ;
else
V_14 -> V_338 = F_182 ( & V_14 -> V_126 , V_36 ) ;
F_91 ( V_14 , V_335 ) ;
F_21 ( L_21 , V_37 -> V_38 ) ;
}
F_21 ( L_22 , V_336 ,
V_14 -> V_328 , F_183 ( & V_14 -> V_126 ) ) ;
return V_336 ;
}
static void F_184 ( struct V_1 * V_14 )
{
struct V_173 V_37 ;
struct V_32 * V_36 ;
struct V_32 * V_335 ;
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
if ( F_185 ( V_36 ) ) {
V_335 = F_186 ( V_36 , V_45 ) ;
} else {
V_335 = F_180 ( V_36 , V_45 ) ;
}
if ( ! V_335 ) {
F_45 ( & V_14 -> V_124 ) ;
break;
}
if ( F_73 ( V_207 , & V_14 -> V_83 ) ) {
F_102 ( F_99 ( & V_37 ) ,
V_335 -> V_156 + V_211 ) ;
} else {
F_103 ( F_100 ( & V_37 ) ,
V_335 -> V_156 + V_211 ) ;
}
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_109 ( 0 , ( T_2 * ) V_335 -> V_156 , V_335 -> V_155 ) ;
F_103 ( V_73 , F_108 ( V_335 ,
V_217 ) ) ;
}
F_91 ( V_14 , V_335 ) ;
F_21 ( L_25 , V_37 . V_38 ) ;
V_14 -> V_225 = V_14 -> V_227 ;
}
}
static void F_187 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
F_21 ( L_11 , V_14 , V_37 ) ;
F_46 ( & V_14 -> V_124 , V_37 -> V_174 ) ;
F_184 ( V_14 ) ;
}
static void F_188 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
struct V_32 * V_36 ;
F_21 ( L_11 , V_14 , V_37 ) ;
if ( V_37 -> V_182 )
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_45 ( & V_14 -> V_124 ) ;
if ( F_73 ( V_249 , & V_14 -> V_220 ) )
return;
if ( V_14 -> V_328 ) {
F_35 (&chan->tx_q, skb) {
if ( F_36 ( V_36 ) -> V_37 . V_38 == V_37 -> V_174 ||
V_36 == V_14 -> V_338 )
break;
}
F_189 (&chan->tx_q, skb) {
if ( V_36 == V_14 -> V_338 )
break;
F_46 ( & V_14 -> V_124 ,
F_36 ( V_36 ) -> V_37 . V_38 ) ;
}
F_184 ( V_14 ) ;
}
}
static void F_190 ( struct V_1 * V_14 )
{
struct V_173 V_37 ;
T_1 V_340 = F_191 ( V_14 , V_14 -> V_227 ,
V_14 -> V_225 ) ;
int V_341 ;
F_21 ( L_26 ,
V_14 , V_14 -> V_225 , V_14 -> V_227 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
if ( F_73 ( V_226 , & V_14 -> V_220 ) &&
V_14 -> V_247 == V_342 ) {
F_75 ( V_14 ) ;
V_37 . V_185 = V_223 ;
V_37 . V_174 = V_14 -> V_227 ;
F_110 ( V_14 , & V_37 ) ;
} else {
if ( ! F_73 ( V_249 , & V_14 -> V_220 ) ) {
F_179 ( V_14 ) ;
if ( V_14 -> V_227 == V_14 -> V_225 )
V_340 = 0 ;
}
V_341 = V_14 -> V_80 ;
V_341 += V_341 << 1 ;
V_341 >>= 2 ;
F_21 ( L_27 , V_340 ,
V_341 ) ;
if ( V_340 >= V_341 ) {
F_75 ( V_14 ) ;
V_37 . V_185 = V_221 ;
V_37 . V_174 = V_14 -> V_227 ;
F_110 ( V_14 , & V_37 ) ;
V_340 = 0 ;
}
if ( V_340 )
F_192 ( V_14 ) ;
}
}
static inline int F_193 ( struct V_1 * V_14 ,
struct V_343 * V_344 , int V_155 ,
int V_345 , struct V_32 * V_36 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * * V_346 ;
int V_336 = 0 ;
if ( F_194 ( F_108 ( V_36 , V_345 ) , V_344 -> V_347 , V_345 ) )
return - V_348 ;
V_336 += V_345 ;
V_155 -= V_345 ;
V_346 = & F_195 ( V_36 ) -> V_349 ;
while ( V_155 ) {
struct V_32 * V_275 ;
V_345 = F_196 (unsigned int, conn->mtu, len) ;
V_275 = V_14 -> V_24 -> V_350 ( V_14 , V_345 ,
V_344 -> V_351 & V_352 ) ;
if ( F_113 ( V_275 ) )
return F_157 ( V_275 ) ;
* V_346 = V_275 ;
if ( F_194 ( F_108 ( * V_346 , V_345 ) , V_344 -> V_347 , V_345 ) )
return - V_348 ;
( * V_346 ) -> V_162 = V_36 -> V_162 ;
V_336 += V_345 ;
V_155 -= V_345 ;
V_36 -> V_155 += ( * V_346 ) -> V_155 ;
V_36 -> V_353 += ( * V_346 ) -> V_155 ;
V_346 = & ( * V_346 ) -> V_354 ;
}
return V_336 ;
}
static struct V_32 * F_197 ( struct V_1 * V_14 ,
struct V_343 * V_344 , T_6 V_155 ,
T_8 V_162 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_345 , V_216 = V_211 + V_355 ;
struct V_214 * V_215 ;
F_21 ( L_28 , V_14 , V_155 , V_162 ) ;
V_345 = F_196 (unsigned int, (conn->mtu - hlen), len) ;
V_36 = V_14 -> V_24 -> V_350 ( V_14 , V_345 + V_216 ,
V_344 -> V_351 & V_352 ) ;
if ( F_113 ( V_36 ) )
return V_36 ;
V_36 -> V_162 = V_162 ;
V_215 = (struct V_214 * ) F_108 ( V_36 , V_211 ) ;
V_215 -> V_4 = F_16 ( V_14 -> V_6 ) ;
V_215 -> V_155 = F_16 ( V_155 + V_355 ) ;
F_198 ( V_14 -> V_10 , F_108 ( V_36 , V_355 ) ) ;
V_15 = F_193 ( V_14 , V_344 , V_155 , V_345 , V_36 ) ;
if ( F_199 ( V_15 < 0 ) ) {
F_92 ( V_36 ) ;
return F_107 ( V_15 ) ;
}
return V_36 ;
}
static struct V_32 * F_200 ( struct V_1 * V_14 ,
struct V_343 * V_344 , T_6 V_155 ,
T_8 V_162 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_345 ;
struct V_214 * V_215 ;
F_21 ( L_29 , V_14 , V_155 ) ;
V_345 = F_196 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_36 = V_14 -> V_24 -> V_350 ( V_14 , V_345 + V_211 ,
V_344 -> V_351 & V_352 ) ;
if ( F_113 ( V_36 ) )
return V_36 ;
V_36 -> V_162 = V_162 ;
V_215 = (struct V_214 * ) F_108 ( V_36 , V_211 ) ;
V_215 -> V_4 = F_16 ( V_14 -> V_6 ) ;
V_215 -> V_155 = F_16 ( V_155 ) ;
V_15 = F_193 ( V_14 , V_344 , V_155 , V_345 , V_36 ) ;
if ( F_199 ( V_15 < 0 ) ) {
F_92 ( V_36 ) ;
return F_107 ( V_15 ) ;
}
return V_36 ;
}
static struct V_32 * F_201 ( struct V_1 * V_14 ,
struct V_343 * V_344 , T_6 V_155 ,
T_1 V_356 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_345 , V_216 ;
struct V_214 * V_215 ;
F_21 ( L_29 , V_14 , V_155 ) ;
if ( ! V_3 )
return F_107 ( - V_337 ) ;
V_216 = F_104 ( V_14 ) ;
if ( V_356 )
V_216 += V_357 ;
if ( V_14 -> V_73 == V_74 )
V_216 += V_217 ;
V_345 = F_196 (unsigned int, (conn->mtu - hlen), len) ;
V_36 = V_14 -> V_24 -> V_350 ( V_14 , V_345 + V_216 ,
V_344 -> V_351 & V_352 ) ;
if ( F_113 ( V_36 ) )
return V_36 ;
V_215 = (struct V_214 * ) F_108 ( V_36 , V_211 ) ;
V_215 -> V_4 = F_16 ( V_14 -> V_6 ) ;
V_215 -> V_155 = F_16 ( V_155 + ( V_216 - V_211 ) ) ;
if ( F_73 ( V_207 , & V_14 -> V_83 ) )
F_102 ( 0 , F_108 ( V_36 , V_208 ) ) ;
else
F_103 ( 0 , F_108 ( V_36 , V_209 ) ) ;
if ( V_356 )
F_103 ( V_356 , F_108 ( V_36 , V_357 ) ) ;
V_15 = F_193 ( V_14 , V_344 , V_155 , V_345 , V_36 ) ;
if ( F_199 ( V_15 < 0 ) ) {
F_92 ( V_36 ) ;
return F_107 ( V_15 ) ;
}
F_36 ( V_36 ) -> V_37 . V_73 = V_14 -> V_73 ;
F_36 ( V_36 ) -> V_37 . V_241 = 0 ;
return V_36 ;
}
static int F_202 ( struct V_1 * V_14 ,
struct V_33 * V_358 ,
struct V_343 * V_344 , T_6 V_155 )
{
struct V_32 * V_36 ;
T_1 V_359 ;
T_6 V_360 ;
T_2 V_188 ;
F_21 ( L_30 , V_14 , V_344 , V_155 ) ;
V_360 = V_14 -> V_3 -> V_310 ;
if ( ! V_14 -> V_169 )
V_360 = F_196 ( T_6 , V_360 , V_361 ) ;
if ( V_14 -> V_73 )
V_360 -= V_217 ;
V_360 -= F_104 ( V_14 ) ;
V_360 = F_196 ( T_6 , V_360 , V_14 -> V_362 ) ;
if ( V_155 <= V_360 ) {
V_188 = V_363 ;
V_359 = 0 ;
V_360 = V_155 ;
} else {
V_188 = V_364 ;
V_359 = V_155 ;
V_360 -= V_357 ;
}
while ( V_155 > 0 ) {
V_36 = F_201 ( V_14 , V_344 , V_360 , V_359 ) ;
if ( F_113 ( V_36 ) ) {
F_203 ( V_358 ) ;
return F_157 ( V_36 ) ;
}
F_36 ( V_36 ) -> V_37 . V_188 = V_188 ;
F_204 ( V_358 , V_36 ) ;
V_155 -= V_360 ;
if ( V_359 ) {
V_359 = 0 ;
V_360 += V_357 ;
}
if ( V_155 <= V_360 ) {
V_188 = V_365 ;
V_360 = V_155 ;
} else {
V_188 = V_366 ;
}
}
return 0 ;
}
int F_205 ( struct V_1 * V_14 , struct V_343 * V_344 , T_6 V_155 ,
T_8 V_162 )
{
struct V_32 * V_36 ;
int V_15 ;
struct V_33 V_358 ;
if ( V_14 -> V_86 == V_93 ) {
V_36 = F_197 ( V_14 , V_344 , V_155 , V_162 ) ;
if ( F_113 ( V_36 ) )
return F_157 ( V_36 ) ;
F_91 ( V_14 , V_36 ) ;
return V_155 ;
}
switch ( V_14 -> V_119 ) {
case V_120 :
if ( V_155 > V_14 -> V_90 )
return - V_367 ;
V_36 = F_200 ( V_14 , V_344 , V_155 , V_162 ) ;
if ( F_113 ( V_36 ) )
return F_157 ( V_36 ) ;
F_91 ( V_14 , V_36 ) ;
V_15 = V_155 ;
break;
case V_121 :
case V_125 :
if ( V_155 > V_14 -> V_90 ) {
V_15 = - V_367 ;
break;
}
F_206 ( & V_358 ) ;
V_15 = F_202 ( V_14 , & V_358 , V_344 , V_155 ) ;
if ( V_14 -> V_23 != V_56 ) {
F_203 ( & V_358 ) ;
V_15 = - V_337 ;
}
if ( V_15 )
break;
if ( V_14 -> V_119 == V_121 )
F_123 ( V_14 , NULL , & V_358 , V_368 ) ;
else
F_174 ( V_14 , & V_358 ) ;
V_15 = V_155 ;
F_203 ( & V_358 ) ;
break;
default:
F_21 ( L_31 , V_14 -> V_119 ) ;
V_15 = - V_321 ;
}
return V_15 ;
}
static void F_207 ( struct V_1 * V_14 , T_1 V_38 )
{
struct V_173 V_37 ;
T_1 V_35 ;
F_21 ( L_32 , V_14 , V_38 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
V_37 . V_185 = V_224 ;
for ( V_35 = V_14 -> V_242 ; V_35 != V_38 ;
V_35 = F_178 ( V_14 , V_35 ) ) {
if ( ! F_34 ( & V_14 -> V_122 , V_35 ) ) {
V_37 . V_174 = V_35 ;
F_110 ( V_14 , & V_37 ) ;
F_46 ( & V_14 -> V_123 , V_35 ) ;
}
}
V_14 -> V_242 = F_178 ( V_14 , V_38 ) ;
}
static void F_208 ( struct V_1 * V_14 )
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
static void F_209 ( struct V_1 * V_14 , T_1 V_38 )
{
struct V_173 V_37 ;
T_1 V_369 ;
T_1 V_35 ;
F_21 ( L_32 , V_14 , V_38 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
V_37 . V_185 = V_224 ;
V_369 = V_14 -> V_123 . V_34 ;
do {
V_35 = F_44 ( & V_14 -> V_123 ) ;
if ( V_35 == V_38 || V_35 == V_48 )
break;
V_37 . V_174 = V_35 ;
F_110 ( V_14 , & V_37 ) ;
F_46 ( & V_14 -> V_123 , V_35 ) ;
} while ( V_14 -> V_123 . V_34 != V_369 );
}
static void F_210 ( struct V_1 * V_14 , T_1 V_174 )
{
struct V_32 * V_370 ;
T_1 V_371 ;
F_21 ( L_33 , V_14 , V_174 ) ;
if ( V_14 -> V_328 == 0 || V_174 == V_14 -> V_372 )
return;
F_21 ( L_34 ,
V_14 -> V_372 , V_14 -> V_328 ) ;
for ( V_371 = V_14 -> V_372 ; V_371 != V_174 ;
V_371 = F_178 ( V_14 , V_371 ) ) {
V_370 = F_34 ( & V_14 -> V_126 , V_371 ) ;
if ( V_370 ) {
F_211 ( V_370 , & V_14 -> V_126 ) ;
F_92 ( V_370 ) ;
V_14 -> V_328 -- ;
}
}
V_14 -> V_372 = V_174 ;
if ( V_14 -> V_328 == 0 )
F_33 ( V_14 ) ;
F_21 ( L_35 , V_14 -> V_328 ) ;
}
static void F_212 ( struct V_1 * V_14 )
{
F_21 ( L_3 , V_14 ) ;
V_14 -> V_242 = V_14 -> V_227 ;
F_45 ( & V_14 -> V_123 ) ;
F_76 ( & V_14 -> V_122 ) ;
V_14 -> V_247 = V_342 ;
}
static void F_213 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_33 * V_332 , T_2 V_373 )
{
F_21 ( L_36 , V_14 , V_37 , V_332 ,
V_373 ) ;
switch ( V_373 ) {
case V_368 :
if ( V_14 -> V_338 == NULL )
V_14 -> V_338 = F_214 ( V_332 ) ;
F_175 ( V_332 , & V_14 -> V_126 ) ;
F_179 ( V_14 ) ;
break;
case V_374 :
F_21 ( L_37 ) ;
F_58 ( V_226 , & V_14 -> V_220 ) ;
if ( V_14 -> V_247 == V_375 ) {
F_212 ( V_14 ) ;
}
F_190 ( V_14 ) ;
break;
case V_376 :
F_21 ( L_38 ) ;
F_112 ( V_226 , & V_14 -> V_220 ) ;
if ( F_73 ( V_222 , & V_14 -> V_220 ) ) {
struct V_173 V_377 ;
memset ( & V_377 , 0 , sizeof( V_377 ) ) ;
V_377 . V_181 = 1 ;
V_377 . V_185 = V_221 ;
V_377 . V_182 = 1 ;
V_377 . V_174 = V_14 -> V_227 ;
F_110 ( V_14 , & V_377 ) ;
V_14 -> V_240 = 1 ;
F_32 ( V_14 ) ;
V_14 -> V_245 = V_378 ;
}
break;
case V_379 :
F_210 ( V_14 , V_37 -> V_174 ) ;
break;
case V_253 :
F_114 ( V_14 , 1 ) ;
V_14 -> V_240 = 1 ;
F_32 ( V_14 ) ;
F_75 ( V_14 ) ;
V_14 -> V_245 = V_378 ;
break;
case V_331 :
F_114 ( V_14 , 1 ) ;
V_14 -> V_240 = 1 ;
F_32 ( V_14 ) ;
V_14 -> V_245 = V_378 ;
break;
case V_380 :
break;
default:
break;
}
}
static void F_215 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_33 * V_332 , T_2 V_373 )
{
F_21 ( L_36 , V_14 , V_37 , V_332 ,
V_373 ) ;
switch ( V_373 ) {
case V_368 :
if ( V_14 -> V_338 == NULL )
V_14 -> V_338 = F_214 ( V_332 ) ;
F_175 ( V_332 , & V_14 -> V_126 ) ;
break;
case V_374 :
F_21 ( L_37 ) ;
F_58 ( V_226 , & V_14 -> V_220 ) ;
if ( V_14 -> V_247 == V_375 ) {
F_212 ( V_14 ) ;
}
F_190 ( V_14 ) ;
break;
case V_376 :
F_21 ( L_38 ) ;
F_112 ( V_226 , & V_14 -> V_220 ) ;
if ( F_73 ( V_222 , & V_14 -> V_220 ) ) {
struct V_173 V_377 ;
memset ( & V_377 , 0 , sizeof( V_377 ) ) ;
V_377 . V_181 = 1 ;
V_377 . V_185 = V_221 ;
V_377 . V_182 = 1 ;
V_377 . V_174 = V_14 -> V_227 ;
F_110 ( V_14 , & V_377 ) ;
V_14 -> V_240 = 1 ;
F_32 ( V_14 ) ;
V_14 -> V_245 = V_378 ;
}
break;
case V_379 :
F_210 ( V_14 , V_37 -> V_174 ) ;
case V_380 :
if ( V_37 && V_37 -> V_177 ) {
F_74 ( V_14 ) ;
if ( V_14 -> V_328 > 0 )
F_28 ( V_14 ) ;
V_14 -> V_240 = 0 ;
V_14 -> V_245 = V_246 ;
F_21 ( L_39 , V_14 -> V_245 ) ;
}
break;
case V_253 :
break;
case V_330 :
if ( V_14 -> V_75 == 0 || V_14 -> V_240 < V_14 -> V_75 ) {
F_114 ( V_14 , 1 ) ;
F_32 ( V_14 ) ;
V_14 -> V_240 ++ ;
} else {
F_78 ( V_14 , V_381 ) ;
}
break;
default:
break;
}
}
static void F_123 ( struct V_1 * V_14 , struct V_173 * V_37 ,
struct V_33 * V_332 , T_2 V_373 )
{
F_21 ( L_40 ,
V_14 , V_37 , V_332 , V_373 , V_14 -> V_245 ) ;
switch ( V_14 -> V_245 ) {
case V_246 :
F_213 ( V_14 , V_37 , V_332 , V_373 ) ;
break;
case V_378 :
F_215 ( V_14 , V_37 , V_332 , V_373 ) ;
break;
default:
break;
}
}
static void F_216 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
F_21 ( L_11 , V_14 , V_37 ) ;
F_123 ( V_14 , V_37 , NULL , V_379 ) ;
}
static void F_217 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
F_21 ( L_11 , V_14 , V_37 ) ;
F_123 ( V_14 , V_37 , NULL , V_380 ) ;
}
static void F_218 ( struct V_2 * V_3 , struct V_32 * V_36 )
{
struct V_32 * V_382 ;
struct V_1 * V_14 ;
F_21 ( L_15 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
struct V_26 * V_13 = V_14 -> V_13 ;
if ( V_14 -> V_86 != V_141 )
continue;
if ( V_36 -> V_13 == V_13 )
continue;
V_382 = F_180 ( V_36 , V_45 ) ;
if ( ! V_382 )
continue;
if ( V_14 -> V_24 -> V_383 ( V_14 , V_382 ) )
F_92 ( V_382 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static struct V_32 * F_87 ( struct V_2 * V_3 , T_2 V_154 ,
T_2 V_9 , T_1 V_384 , void * V_156 )
{
struct V_32 * V_36 , * * V_346 ;
struct V_385 * V_386 ;
struct V_214 * V_215 ;
int V_155 , V_345 ;
F_21 ( L_41 ,
V_3 , V_154 , V_9 , V_384 ) ;
V_155 = V_211 + V_387 + V_384 ;
V_345 = F_196 (unsigned int, conn->mtu, len) ;
V_36 = F_106 ( V_345 , V_45 ) ;
if ( ! V_36 )
return NULL ;
V_215 = (struct V_214 * ) F_108 ( V_36 , V_211 ) ;
V_215 -> V_155 = F_16 ( V_387 + V_384 ) ;
if ( V_3 -> V_88 -> type == V_89 )
V_215 -> V_4 = F_79 ( V_388 ) ;
else
V_215 -> V_4 = F_79 ( V_99 ) ;
V_386 = (struct V_385 * ) F_108 ( V_36 , V_387 ) ;
V_386 -> V_154 = V_154 ;
V_386 -> V_9 = V_9 ;
V_386 -> V_155 = F_16 ( V_384 ) ;
if ( V_384 ) {
V_345 -= V_211 + V_387 ;
memcpy ( F_108 ( V_36 , V_345 ) , V_156 , V_345 ) ;
V_156 += V_345 ;
}
V_155 -= V_36 -> V_155 ;
V_346 = & F_195 ( V_36 ) -> V_349 ;
while ( V_155 ) {
V_345 = F_196 (unsigned int, conn->mtu, len) ;
* V_346 = F_106 ( V_345 , V_45 ) ;
if ( ! * V_346 )
goto V_389;
memcpy ( F_108 ( * V_346 , V_345 ) , V_156 , V_345 ) ;
V_155 -= V_345 ;
V_156 += V_345 ;
V_346 = & ( * V_346 ) -> V_354 ;
}
return V_36 ;
V_389:
F_92 ( V_36 ) ;
return NULL ;
}
static inline int F_219 ( void * * V_390 , int * type , int * V_391 ,
unsigned long * V_392 )
{
struct V_393 * V_394 = * V_390 ;
int V_155 ;
V_155 = V_395 + V_394 -> V_155 ;
* V_390 += V_155 ;
* type = V_394 -> type ;
* V_391 = V_394 -> V_155 ;
switch ( V_394 -> V_155 ) {
case 1 :
* V_392 = * ( ( T_2 * ) V_394 -> V_392 ) ;
break;
case 2 :
* V_392 = F_98 ( V_394 -> V_392 ) ;
break;
case 4 :
* V_392 = F_96 ( V_394 -> V_392 ) ;
break;
default:
* V_392 = ( unsigned long ) V_394 -> V_392 ;
break;
}
F_21 ( L_42 , * type , V_394 -> V_155 , * V_392 ) ;
return V_155 ;
}
static void F_220 ( void * * V_390 , T_2 type , T_2 V_155 , unsigned long V_392 )
{
struct V_393 * V_394 = * V_390 ;
F_21 ( L_42 , type , V_155 , V_392 ) ;
V_394 -> type = type ;
V_394 -> V_155 = V_155 ;
switch ( V_155 ) {
case 1 :
* ( ( T_2 * ) V_394 -> V_392 ) = V_392 ;
break;
case 2 :
F_103 ( V_392 , V_394 -> V_392 ) ;
break;
case 4 :
F_102 ( V_392 , V_394 -> V_392 ) ;
break;
default:
memcpy ( V_394 -> V_392 , ( void * ) V_392 , V_155 ) ;
break;
}
* V_390 += V_395 + V_155 ;
}
static void F_221 ( void * * V_390 , struct V_1 * V_14 )
{
struct V_396 V_397 ;
switch ( V_14 -> V_119 ) {
case V_121 :
V_397 . V_152 = V_14 -> V_100 ;
V_397 . V_398 = V_14 -> V_102 ;
V_397 . V_399 = F_16 ( V_14 -> V_104 ) ;
V_397 . V_400 = F_222 ( V_14 -> V_106 ) ;
V_397 . V_401 = F_223 ( V_109 ) ;
V_397 . V_402 = F_223 ( V_111 ) ;
break;
case V_125 :
V_397 . V_152 = 1 ;
V_397 . V_398 = V_103 ;
V_397 . V_399 = F_16 ( V_14 -> V_104 ) ;
V_397 . V_400 = F_222 ( V_14 -> V_106 ) ;
V_397 . V_401 = 0 ;
V_397 . V_402 = 0 ;
break;
default:
return;
}
F_220 ( V_390 , V_403 , sizeof( V_397 ) ,
( unsigned long ) & V_397 ) ;
}
static void F_224 ( struct V_52 * V_53 )
{
struct V_1 * V_14 = F_48 ( V_53 , struct V_1 ,
V_404 . V_53 ) ;
T_1 V_340 ;
F_21 ( L_3 , V_14 ) ;
F_6 ( V_14 ) ;
V_340 = F_191 ( V_14 , V_14 -> V_227 ,
V_14 -> V_225 ) ;
if ( V_340 )
F_114 ( V_14 , 0 ) ;
F_50 ( V_14 ) ;
F_51 ( V_14 ) ;
}
int F_225 ( struct V_1 * V_14 )
{
int V_15 ;
V_14 -> V_333 = 0 ;
V_14 -> V_242 = 0 ;
V_14 -> V_372 = 0 ;
V_14 -> V_328 = 0 ;
V_14 -> V_227 = 0 ;
V_14 -> V_334 = 0 ;
V_14 -> V_225 = 0 ;
V_14 -> V_405 = NULL ;
V_14 -> V_406 = NULL ;
V_14 -> V_359 = 0 ;
F_226 ( & V_14 -> V_126 ) ;
V_14 -> V_407 = 0 ;
V_14 -> V_408 = 0 ;
V_14 -> V_165 = V_166 ;
V_14 -> V_250 = V_251 ;
if ( V_14 -> V_119 != V_121 )
return 0 ;
V_14 -> V_247 = V_342 ;
V_14 -> V_245 = V_246 ;
F_56 ( & V_14 -> V_30 , F_173 ) ;
F_56 ( & V_14 -> V_28 , F_172 ) ;
F_56 ( & V_14 -> V_404 , F_224 ) ;
F_226 ( & V_14 -> V_122 ) ;
V_15 = F_37 ( & V_14 -> V_123 , V_14 -> V_77 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_37 ( & V_14 -> V_124 , V_14 -> V_339 ) ;
if ( V_15 < 0 )
F_40 ( & V_14 -> V_123 ) ;
return V_15 ;
}
static inline T_7 F_227 ( T_7 V_119 , T_5 V_409 )
{
switch ( V_119 ) {
case V_125 :
case V_121 :
if ( F_129 ( V_119 , V_409 ) )
return V_119 ;
default:
return V_120 ;
}
}
static inline bool F_228 ( struct V_1 * V_14 )
{
return V_229 && V_14 -> V_3 -> V_267 & V_410 ;
}
static inline bool F_229 ( struct V_1 * V_14 )
{
return V_229 && V_14 -> V_3 -> V_267 & V_411 ;
}
static void F_230 ( struct V_1 * V_14 ,
struct V_412 * V_413 )
{
if ( V_14 -> V_407 && V_14 -> V_169 ) {
T_10 V_414 = V_14 -> V_169 -> V_157 -> V_415 ;
V_414 = F_231 ( V_414 , 1000 ) ;
V_414 = 3 * V_414 + 500 ;
if ( V_414 > 0xffff )
V_414 = 0xffff ;
V_413 -> V_29 = F_16 ( ( T_1 ) V_414 ) ;
V_413 -> V_31 = V_413 -> V_29 ;
} else {
V_413 -> V_29 = F_79 ( V_416 ) ;
V_413 -> V_31 = F_79 ( V_417 ) ;
}
}
static inline void F_232 ( struct V_1 * V_14 )
{
if ( V_14 -> V_77 > V_78 &&
F_228 ( V_14 ) ) {
F_58 ( V_207 , & V_14 -> V_83 ) ;
V_14 -> V_79 = V_418 ;
} else {
V_14 -> V_77 = F_196 ( T_1 , V_14 -> V_77 ,
V_78 ) ;
V_14 -> V_79 = V_78 ;
}
V_14 -> V_80 = V_14 -> V_77 ;
}
static int F_132 ( struct V_1 * V_14 , void * V_156 )
{
struct V_419 * V_235 = V_156 ;
struct V_412 V_413 = { . V_119 = V_14 -> V_119 } ;
void * V_390 = V_235 -> V_156 ;
T_1 V_41 ;
F_21 ( L_3 , V_14 ) ;
if ( V_14 -> V_286 || V_14 -> V_420 )
goto V_18;
switch ( V_14 -> V_119 ) {
case V_125 :
case V_121 :
if ( F_73 ( V_276 , & V_14 -> V_71 ) )
break;
if ( F_229 ( V_14 ) )
F_58 ( V_421 , & V_14 -> V_83 ) ;
default:
V_14 -> V_119 = F_227 ( V_413 . V_119 , V_14 -> V_3 -> V_267 ) ;
break;
}
V_18:
if ( V_14 -> V_98 != V_91 )
F_220 ( & V_390 , V_422 , 2 , V_14 -> V_98 ) ;
switch ( V_14 -> V_119 ) {
case V_120 :
if ( ! ( V_14 -> V_3 -> V_267 & V_271 ) &&
! ( V_14 -> V_3 -> V_267 & V_272 ) )
break;
V_413 . V_119 = V_120 ;
V_413 . V_423 = 0 ;
V_413 . V_424 = 0 ;
V_413 . V_29 = 0 ;
V_413 . V_31 = 0 ;
V_413 . V_425 = 0 ;
F_220 ( & V_390 , V_426 , sizeof( V_413 ) ,
( unsigned long ) & V_413 ) ;
break;
case V_121 :
V_413 . V_119 = V_121 ;
V_413 . V_424 = V_14 -> V_75 ;
F_230 ( V_14 , & V_413 ) ;
V_41 = F_196 ( T_1 , V_427 , V_14 -> V_3 -> V_310 -
V_212 - V_357 -
V_217 ) ;
V_413 . V_425 = F_16 ( V_41 ) ;
F_232 ( V_14 ) ;
V_413 . V_423 = F_196 ( T_1 , V_14 -> V_77 ,
V_78 ) ;
F_220 ( & V_390 , V_426 , sizeof( V_413 ) ,
( unsigned long ) & V_413 ) ;
if ( F_73 ( V_421 , & V_14 -> V_83 ) )
F_221 ( & V_390 , V_14 ) ;
if ( F_73 ( V_207 , & V_14 -> V_83 ) )
F_220 ( & V_390 , V_428 , 2 ,
V_14 -> V_77 ) ;
if ( V_14 -> V_3 -> V_267 & V_429 )
if ( V_14 -> V_73 == V_430 ||
F_73 ( V_431 , & V_14 -> V_71 ) ) {
V_14 -> V_73 = V_430 ;
F_220 ( & V_390 , V_432 , 1 ,
V_14 -> V_73 ) ;
}
break;
case V_125 :
F_232 ( V_14 ) ;
V_413 . V_119 = V_125 ;
V_413 . V_423 = 0 ;
V_413 . V_424 = 0 ;
V_413 . V_29 = 0 ;
V_413 . V_31 = 0 ;
V_41 = F_196 ( T_1 , V_427 , V_14 -> V_3 -> V_310 -
V_212 - V_357 -
V_217 ) ;
V_413 . V_425 = F_16 ( V_41 ) ;
F_220 ( & V_390 , V_426 , sizeof( V_413 ) ,
( unsigned long ) & V_413 ) ;
if ( F_73 ( V_421 , & V_14 -> V_83 ) )
F_221 ( & V_390 , V_14 ) ;
if ( V_14 -> V_3 -> V_267 & V_429 )
if ( V_14 -> V_73 == V_430 ||
F_73 ( V_431 , & V_14 -> V_71 ) ) {
V_14 -> V_73 = V_430 ;
F_220 ( & V_390 , V_432 , 1 ,
V_14 -> V_73 ) ;
}
break;
}
V_235 -> V_6 = F_16 ( V_14 -> V_6 ) ;
V_235 -> V_83 = F_79 ( 0 ) ;
return V_390 - V_156 ;
}
static int F_233 ( struct V_1 * V_14 , void * V_156 )
{
struct V_433 * V_132 = V_156 ;
void * V_390 = V_132 -> V_156 ;
void * V_235 = V_14 -> V_434 ;
int V_155 = V_14 -> V_435 ;
int type , V_436 , V_391 ;
unsigned long V_392 ;
struct V_412 V_413 = { . V_119 = V_120 } ;
struct V_396 V_397 ;
T_2 V_437 = 0 ;
T_1 V_310 = V_91 ;
T_1 V_133 = V_438 ;
T_1 V_41 ;
F_21 ( L_3 , V_14 ) ;
while ( V_155 >= V_395 ) {
V_155 -= F_219 ( & V_235 , & type , & V_391 , & V_392 ) ;
V_436 = type & V_439 ;
type &= V_440 ;
switch ( type ) {
case V_422 :
V_310 = V_392 ;
break;
case V_441 :
V_14 -> V_402 = V_392 ;
break;
case V_442 :
break;
case V_426 :
if ( V_391 == sizeof( V_413 ) )
memcpy ( & V_413 , ( void * ) V_392 , V_391 ) ;
break;
case V_432 :
if ( V_392 == V_430 )
F_58 ( V_431 , & V_14 -> V_71 ) ;
break;
case V_403 :
V_437 = 1 ;
if ( V_391 == sizeof( V_397 ) )
memcpy ( & V_397 , ( void * ) V_392 , V_391 ) ;
break;
case V_428 :
if ( ! V_229 )
return - V_58 ;
F_58 ( V_207 , & V_14 -> V_83 ) ;
F_58 ( V_443 , & V_14 -> V_71 ) ;
V_14 -> V_79 = V_418 ;
V_14 -> V_339 = V_392 ;
break;
default:
if ( V_436 )
break;
V_133 = V_444 ;
* ( ( T_2 * ) V_390 ++ ) = type ;
break;
}
}
if ( V_14 -> V_420 || V_14 -> V_286 > 1 )
goto V_18;
switch ( V_14 -> V_119 ) {
case V_125 :
case V_121 :
if ( ! F_73 ( V_276 , & V_14 -> V_71 ) ) {
V_14 -> V_119 = F_227 ( V_413 . V_119 ,
V_14 -> V_3 -> V_267 ) ;
break;
}
if ( V_437 ) {
if ( F_229 ( V_14 ) )
F_58 ( V_421 , & V_14 -> V_83 ) ;
else
return - V_58 ;
}
if ( V_14 -> V_119 != V_413 . V_119 )
return - V_58 ;
break;
}
V_18:
if ( V_14 -> V_119 != V_413 . V_119 ) {
V_133 = V_445 ;
V_413 . V_119 = V_14 -> V_119 ;
if ( V_14 -> V_420 == 1 )
return - V_58 ;
F_220 ( & V_390 , V_426 , sizeof( V_413 ) ,
( unsigned long ) & V_413 ) ;
}
if ( V_133 == V_438 ) {
if ( V_310 < V_446 )
V_133 = V_445 ;
else {
V_14 -> V_90 = V_310 ;
F_58 ( V_447 , & V_14 -> V_71 ) ;
}
F_220 ( & V_390 , V_422 , 2 , V_14 -> V_90 ) ;
if ( V_437 ) {
if ( V_14 -> V_102 != V_448 &&
V_397 . V_398 != V_448 &&
V_397 . V_398 != V_14 -> V_102 ) {
V_133 = V_445 ;
if ( V_14 -> V_286 >= 1 )
return - V_58 ;
F_220 ( & V_390 , V_403 ,
sizeof( V_397 ) ,
( unsigned long ) & V_397 ) ;
} else {
V_133 = V_449 ;
F_58 ( V_450 , & V_14 -> V_71 ) ;
}
}
switch ( V_413 . V_119 ) {
case V_120 :
V_14 -> V_73 = V_430 ;
F_58 ( V_451 , & V_14 -> V_71 ) ;
break;
case V_121 :
if ( ! F_73 ( V_443 , & V_14 -> V_71 ) )
V_14 -> V_339 = V_413 . V_423 ;
else
V_413 . V_423 = V_78 ;
V_14 -> V_452 = V_413 . V_424 ;
V_41 = F_196 ( T_1 , F_234 ( V_413 . V_425 ) ,
V_14 -> V_3 -> V_310 - V_212 -
V_357 - V_217 ) ;
V_413 . V_425 = F_16 ( V_41 ) ;
V_14 -> V_362 = V_41 ;
F_230 ( V_14 , & V_413 ) ;
F_58 ( V_451 , & V_14 -> V_71 ) ;
F_220 ( & V_390 , V_426 ,
sizeof( V_413 ) , ( unsigned long ) & V_413 ) ;
if ( F_73 ( V_421 , & V_14 -> V_83 ) ) {
V_14 -> V_453 = V_397 . V_152 ;
V_14 -> V_454 = V_397 . V_398 ;
V_14 -> V_455 = F_234 ( V_397 . V_399 ) ;
V_14 -> V_456 =
F_235 ( V_397 . V_402 ) ;
V_14 -> V_457 =
F_235 ( V_397 . V_401 ) ;
V_14 -> V_458 =
F_235 ( V_397 . V_400 ) ;
F_220 ( & V_390 , V_403 ,
sizeof( V_397 ) ,
( unsigned long ) & V_397 ) ;
}
break;
case V_125 :
V_41 = F_196 ( T_1 , F_234 ( V_413 . V_425 ) ,
V_14 -> V_3 -> V_310 - V_212 -
V_357 - V_217 ) ;
V_413 . V_425 = F_16 ( V_41 ) ;
V_14 -> V_362 = V_41 ;
F_58 ( V_451 , & V_14 -> V_71 ) ;
F_220 ( & V_390 , V_426 , sizeof( V_413 ) ,
( unsigned long ) & V_413 ) ;
break;
default:
V_133 = V_445 ;
memset ( & V_413 , 0 , sizeof( V_413 ) ) ;
V_413 . V_119 = V_14 -> V_119 ;
}
if ( V_133 == V_438 )
F_58 ( V_459 , & V_14 -> V_71 ) ;
}
V_132 -> V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 -> V_133 = F_16 ( V_133 ) ;
V_132 -> V_83 = F_79 ( 0 ) ;
return V_390 - V_156 ;
}
static int F_236 ( struct V_1 * V_14 , void * V_132 , int V_155 ,
void * V_156 , T_1 * V_133 )
{
struct V_419 * V_235 = V_156 ;
void * V_390 = V_235 -> V_156 ;
int type , V_391 ;
unsigned long V_392 ;
struct V_412 V_413 = { . V_119 = V_120 } ;
struct V_396 V_397 ;
F_21 ( L_43 , V_14 , V_132 , V_155 , V_156 ) ;
while ( V_155 >= V_395 ) {
V_155 -= F_219 ( & V_132 , & type , & V_391 , & V_392 ) ;
switch ( type ) {
case V_422 :
if ( V_392 < V_446 ) {
* V_133 = V_445 ;
V_14 -> V_98 = V_446 ;
} else
V_14 -> V_98 = V_392 ;
F_220 ( & V_390 , V_422 , 2 , V_14 -> V_98 ) ;
break;
case V_441 :
V_14 -> V_402 = V_392 ;
F_220 ( & V_390 , V_441 ,
2 , V_14 -> V_402 ) ;
break;
case V_426 :
if ( V_391 == sizeof( V_413 ) )
memcpy ( & V_413 , ( void * ) V_392 , V_391 ) ;
if ( F_73 ( V_276 , & V_14 -> V_71 ) &&
V_413 . V_119 != V_14 -> V_119 )
return - V_58 ;
V_14 -> V_73 = 0 ;
F_220 ( & V_390 , V_426 ,
sizeof( V_413 ) , ( unsigned long ) & V_413 ) ;
break;
case V_428 :
V_14 -> V_80 = F_196 ( T_1 , V_392 , V_14 -> V_80 ) ;
F_220 ( & V_390 , V_428 , 2 ,
V_14 -> V_77 ) ;
break;
case V_403 :
if ( V_391 == sizeof( V_397 ) )
memcpy ( & V_397 , ( void * ) V_392 , V_391 ) ;
if ( V_14 -> V_102 != V_448 &&
V_397 . V_398 != V_448 &&
V_397 . V_398 != V_14 -> V_102 )
return - V_58 ;
F_220 ( & V_390 , V_403 , sizeof( V_397 ) ,
( unsigned long ) & V_397 ) ;
break;
case V_432 :
if ( * V_133 == V_449 )
if ( V_392 == V_430 )
F_58 ( V_431 ,
& V_14 -> V_71 ) ;
break;
}
}
if ( V_14 -> V_119 == V_120 && V_14 -> V_119 != V_413 . V_119 )
return - V_58 ;
V_14 -> V_119 = V_413 . V_119 ;
if ( * V_133 == V_438 || * V_133 == V_449 ) {
switch ( V_413 . V_119 ) {
case V_121 :
V_14 -> V_29 = F_234 ( V_413 . V_29 ) ;
V_14 -> V_31 = F_234 ( V_413 . V_31 ) ;
V_14 -> V_460 = F_234 ( V_413 . V_425 ) ;
if ( ! F_73 ( V_207 , & V_14 -> V_83 ) )
V_14 -> V_80 = F_196 ( T_1 , V_14 -> V_80 ,
V_413 . V_423 ) ;
if ( F_73 ( V_421 , & V_14 -> V_83 ) ) {
V_14 -> V_104 = F_234 ( V_397 . V_399 ) ;
V_14 -> V_106 =
F_235 ( V_397 . V_400 ) ;
V_14 -> V_108 = F_235 ( V_397 . V_401 ) ;
V_14 -> V_110 =
F_235 ( V_397 . V_402 ) ;
}
break;
case V_125 :
V_14 -> V_460 = F_234 ( V_413 . V_425 ) ;
}
}
V_235 -> V_6 = F_16 ( V_14 -> V_6 ) ;
V_235 -> V_83 = F_79 ( 0 ) ;
return V_390 - V_156 ;
}
static int F_237 ( struct V_1 * V_14 , void * V_156 ,
T_1 V_133 , T_1 V_83 )
{
struct V_433 * V_132 = V_156 ;
void * V_390 = V_132 -> V_156 ;
F_21 ( L_3 , V_14 ) ;
V_132 -> V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 -> V_133 = F_16 ( V_133 ) ;
V_132 -> V_83 = F_16 ( V_83 ) ;
return V_390 - V_156 ;
}
void F_238 ( struct V_1 * V_14 )
{
struct V_131 V_132 ;
struct V_2 * V_3 = V_14 -> V_3 ;
T_2 V_278 [ 128 ] ;
T_2 V_461 ;
V_132 . V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_6 = F_16 ( V_14 -> V_7 ) ;
V_132 . V_133 = F_79 ( V_282 ) ;
V_132 . V_138 = F_79 ( V_139 ) ;
if ( V_14 -> V_169 )
V_461 = V_462 ;
else
V_461 = V_140 ;
F_21 ( L_44 , V_14 , V_461 ) ;
F_80 ( V_3 , V_14 -> V_9 , V_461 , sizeof( V_132 ) , & V_132 ) ;
if ( F_239 ( V_284 , & V_14 -> V_71 ) )
return;
F_80 ( V_3 , F_84 ( V_3 ) , V_285 ,
F_132 ( V_14 , V_278 ) , V_278 ) ;
V_14 -> V_286 ++ ;
}
static void F_240 ( struct V_1 * V_14 , void * V_132 , int V_155 )
{
int type , V_391 ;
unsigned long V_392 ;
T_1 V_463 = V_14 -> V_80 ;
struct V_412 V_413 = {
. V_119 = V_14 -> V_119 ,
. V_29 = F_79 ( V_416 ) ,
. V_31 = F_79 ( V_417 ) ,
. V_425 = F_16 ( V_14 -> V_98 ) ,
. V_423 = F_196 ( T_1 , V_14 -> V_80 , V_78 ) ,
} ;
F_21 ( L_45 , V_14 , V_132 , V_155 ) ;
if ( ( V_14 -> V_119 != V_121 ) && ( V_14 -> V_119 != V_125 ) )
return;
while ( V_155 >= V_395 ) {
V_155 -= F_219 ( & V_132 , & type , & V_391 , & V_392 ) ;
switch ( type ) {
case V_426 :
if ( V_391 == sizeof( V_413 ) )
memcpy ( & V_413 , ( void * ) V_392 , V_391 ) ;
break;
case V_428 :
V_463 = V_392 ;
break;
}
}
switch ( V_413 . V_119 ) {
case V_121 :
V_14 -> V_29 = F_234 ( V_413 . V_29 ) ;
V_14 -> V_31 = F_234 ( V_413 . V_31 ) ;
V_14 -> V_460 = F_234 ( V_413 . V_425 ) ;
if ( F_73 ( V_207 , & V_14 -> V_83 ) )
V_14 -> V_80 = F_196 ( T_1 , V_14 -> V_80 , V_463 ) ;
else
V_14 -> V_80 = F_196 ( T_1 , V_14 -> V_80 ,
V_413 . V_423 ) ;
break;
case V_125 :
V_14 -> V_460 = F_234 ( V_413 . V_425 ) ;
}
}
static inline int F_241 ( struct V_2 * V_3 ,
struct V_385 * V_386 , T_2 * V_156 )
{
struct V_464 * V_465 = (struct V_464 * ) V_156 ;
if ( V_465 -> V_55 != V_466 )
return 0 ;
if ( ( V_3 -> V_258 & V_259 ) &&
V_386 -> V_9 == V_3 -> V_263 ) {
F_242 ( & V_3 -> V_264 ) ;
V_3 -> V_258 |= V_260 ;
V_3 -> V_263 = 0 ;
F_130 ( V_3 ) ;
}
return 0 ;
}
static struct V_1 * F_243 ( struct V_2 * V_3 ,
struct V_385 * V_386 ,
T_2 * V_156 , T_2 V_461 , T_2 V_237 )
{
struct V_234 * V_235 = (struct V_234 * ) V_156 ;
struct V_131 V_132 ;
struct V_1 * V_14 = NULL , * V_295 ;
struct V_26 * V_294 , * V_13 = NULL ;
int V_133 , V_138 = V_139 ;
T_1 V_6 = 0 , V_7 = F_67 ( V_235 -> V_7 ) ;
T_3 V_10 = V_235 -> V_10 ;
F_21 ( L_46 , F_67 ( V_10 ) , V_7 ) ;
V_295 = F_152 ( V_127 , V_10 , V_3 -> V_11 , V_3 -> V_287 ) ;
if ( ! V_295 ) {
V_133 = V_136 ;
goto V_467;
}
V_294 = V_295 -> V_13 ;
F_5 ( & V_3 -> V_8 ) ;
F_24 ( V_294 ) ;
if ( V_10 != F_79 ( V_147 ) &&
! F_244 ( V_3 -> V_88 ) ) {
V_3 -> V_84 = V_468 ;
V_133 = V_135 ;
goto V_469;
}
V_133 = V_470 ;
if ( F_1 ( V_3 , V_7 ) )
goto V_469;
V_14 = V_295 -> V_24 -> V_296 ( V_295 ) ;
if ( ! V_14 )
goto V_469;
V_13 = V_14 -> V_13 ;
F_137 ( V_3 -> V_88 ) ;
F_138 ( & F_13 ( V_13 ) -> V_11 , V_3 -> V_11 ) ;
F_138 ( & F_13 ( V_13 ) -> V_287 , V_3 -> V_287 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_7 ;
V_14 -> V_407 = V_237 ;
F_66 ( V_3 , V_14 ) ;
V_6 = V_14 -> V_7 ;
F_77 ( V_14 , V_13 -> V_129 ) ;
V_14 -> V_9 = V_386 -> V_9 ;
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
V_469:
F_25 ( V_294 ) ;
F_7 ( & V_3 -> V_8 ) ;
V_467:
V_132 . V_7 = F_16 ( V_7 ) ;
V_132 . V_6 = F_16 ( V_6 ) ;
V_132 . V_133 = F_16 ( V_133 ) ;
V_132 . V_138 = F_16 ( V_138 ) ;
F_80 ( V_3 , V_386 -> V_9 , V_461 , sizeof( V_132 ) , & V_132 ) ;
if ( V_133 == V_279 && V_138 == V_139 ) {
struct V_261 V_471 ;
V_471 . type = F_79 ( V_262 ) ;
V_3 -> V_258 |= V_259 ;
V_3 -> V_263 = F_84 ( V_3 ) ;
F_128 ( & V_3 -> V_264 , V_265 ) ;
F_80 ( V_3 , V_3 -> V_263 , V_266 ,
sizeof( V_471 ) , & V_471 ) ;
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
static int F_245 ( struct V_2 * V_3 ,
struct V_385 * V_386 , T_2 * V_156 )
{
struct V_316 * V_157 = V_3 -> V_88 -> V_157 ;
struct V_168 * V_88 = V_3 -> V_88 ;
F_155 ( V_157 ) ;
if ( F_73 ( V_472 , & V_157 -> V_473 ) &&
! F_239 ( V_474 , & V_88 -> V_83 ) )
F_246 ( V_157 , & V_88 -> V_287 , V_88 -> type ,
V_88 -> V_315 , 0 , NULL , 0 ,
V_88 -> V_475 ) ;
F_159 ( V_157 ) ;
F_243 ( V_3 , V_386 , V_156 , V_140 , 0 ) ;
return 0 ;
}
static int F_247 ( struct V_2 * V_3 ,
struct V_385 * V_386 , T_2 * V_156 )
{
struct V_131 * V_132 = (struct V_131 * ) V_156 ;
T_1 V_7 , V_6 , V_133 , V_138 ;
struct V_1 * V_14 ;
T_2 V_235 [ 128 ] ;
int V_15 ;
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
V_15 = - V_348 ;
goto V_476;
}
} else {
V_14 = F_9 ( V_3 , V_386 -> V_9 ) ;
if ( ! V_14 ) {
V_15 = - V_348 ;
goto V_476;
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
if ( F_239 ( V_284 , & V_14 -> V_71 ) )
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
V_476:
F_7 ( & V_3 -> V_8 ) ;
return V_15 ;
}
static inline void F_248 ( struct V_1 * V_14 )
{
if ( V_14 -> V_119 != V_121 && V_14 -> V_119 != V_125 )
V_14 -> V_73 = V_430 ;
else if ( ! F_73 ( V_431 , & V_14 -> V_71 ) )
V_14 -> V_73 = V_74 ;
}
static void F_249 ( struct V_1 * V_14 , void * V_156 ,
T_2 V_9 , T_1 V_83 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
F_21 ( L_48 , V_3 , V_14 , V_9 ,
V_83 ) ;
F_112 ( V_450 , & V_14 -> V_71 ) ;
F_58 ( V_459 , & V_14 -> V_71 ) ;
F_80 ( V_3 , V_9 , V_477 ,
F_237 ( V_14 , V_156 ,
V_438 , V_83 ) , V_156 ) ;
}
static inline int F_250 ( struct V_2 * V_3 ,
struct V_385 * V_386 , T_1 V_478 ,
T_2 * V_156 )
{
struct V_419 * V_235 = (struct V_419 * ) V_156 ;
T_1 V_6 , V_83 ;
T_2 V_132 [ 64 ] ;
struct V_1 * V_14 ;
int V_155 , V_15 = 0 ;
V_6 = F_67 ( V_235 -> V_6 ) ;
V_83 = F_67 ( V_235 -> V_83 ) ;
F_21 ( L_49 , V_6 , V_83 ) ;
V_14 = F_4 ( V_3 , V_6 ) ;
if ( ! V_14 )
return - V_479 ;
if ( V_14 -> V_23 != V_57 && V_14 -> V_23 != V_130 ) {
struct V_480 V_465 ;
V_465 . V_55 = F_79 ( V_481 ) ;
V_465 . V_7 = F_16 ( V_14 -> V_7 ) ;
V_465 . V_6 = F_16 ( V_14 -> V_6 ) ;
F_80 ( V_3 , V_386 -> V_9 , V_482 ,
sizeof( V_465 ) , & V_465 ) ;
goto V_476;
}
V_155 = V_478 - sizeof( * V_235 ) ;
if ( V_155 < 0 || V_14 -> V_435 + V_155 > sizeof( V_14 -> V_434 ) ) {
F_80 ( V_3 , V_386 -> V_9 , V_477 ,
F_237 ( V_14 , V_132 ,
V_483 , V_83 ) , V_132 ) ;
goto V_476;
}
memcpy ( V_14 -> V_434 + V_14 -> V_435 , V_235 -> V_156 , V_155 ) ;
V_14 -> V_435 += V_155 ;
if ( V_83 & V_484 ) {
F_80 ( V_3 , V_386 -> V_9 , V_477 ,
F_237 ( V_14 , V_132 ,
V_438 , V_83 ) , V_132 ) ;
goto V_476;
}
V_155 = F_233 ( V_14 , V_132 ) ;
if ( V_155 < 0 ) {
F_78 ( V_14 , V_277 ) ;
goto V_476;
}
V_14 -> V_9 = V_386 -> V_9 ;
F_80 ( V_3 , V_386 -> V_9 , V_477 , V_155 , V_132 ) ;
V_14 -> V_420 ++ ;
V_14 -> V_435 = 0 ;
if ( ! F_73 ( V_459 , & V_14 -> V_71 ) )
goto V_476;
if ( F_73 ( V_485 , & V_14 -> V_71 ) ) {
F_248 ( V_14 ) ;
if ( V_14 -> V_119 == V_121 ||
V_14 -> V_119 == V_125 )
V_15 = F_225 ( V_14 ) ;
if ( V_15 < 0 )
F_78 ( V_14 , - V_15 ) ;
else
F_124 ( V_14 ) ;
goto V_476;
}
if ( ! F_239 ( V_284 , & V_14 -> V_71 ) ) {
T_2 V_278 [ 64 ] ;
F_80 ( V_3 , F_84 ( V_3 ) , V_285 ,
F_132 ( V_14 , V_278 ) , V_278 ) ;
V_14 -> V_286 ++ ;
}
if ( F_73 ( V_486 , & V_14 -> V_71 ) &&
F_73 ( V_450 , & V_14 -> V_71 ) ) {
if ( ! V_14 -> V_169 )
F_249 ( V_14 , V_132 , V_386 -> V_9 , V_83 ) ;
else
V_14 -> V_9 = V_386 -> V_9 ;
}
V_476:
F_50 ( V_14 ) ;
return V_15 ;
}
static inline int F_251 ( struct V_2 * V_3 ,
struct V_385 * V_386 , T_2 * V_156 )
{
struct V_433 * V_132 = (struct V_433 * ) V_156 ;
T_1 V_7 , V_83 , V_133 ;
struct V_1 * V_14 ;
int V_155 = F_234 ( V_386 -> V_155 ) - sizeof( * V_132 ) ;
int V_15 = 0 ;
V_7 = F_67 ( V_132 -> V_7 ) ;
V_83 = F_67 ( V_132 -> V_83 ) ;
V_133 = F_67 ( V_132 -> V_133 ) ;
F_21 ( L_50 , V_7 , V_83 ,
V_133 , V_155 ) ;
V_14 = F_4 ( V_3 , V_7 ) ;
if ( ! V_14 )
return 0 ;
switch ( V_133 ) {
case V_438 :
F_240 ( V_14 , V_132 -> V_156 , V_155 ) ;
F_112 ( V_486 , & V_14 -> V_71 ) ;
break;
case V_449 :
F_58 ( V_486 , & V_14 -> V_71 ) ;
if ( F_73 ( V_450 , & V_14 -> V_71 ) ) {
char V_278 [ 64 ] ;
V_155 = F_236 ( V_14 , V_132 -> V_156 , V_155 ,
V_278 , & V_133 ) ;
if ( V_155 < 0 ) {
F_78 ( V_14 , V_277 ) ;
goto V_18;
}
if ( ! V_14 -> V_169 ) {
F_249 ( V_14 , V_278 , V_386 -> V_9 ,
0 ) ;
} else {
if ( F_118 ( V_14 ) ) {
F_252 ( V_14 ) ;
V_14 -> V_9 = V_386 -> V_9 ;
}
}
}
goto V_18;
case V_445 :
if ( V_14 -> V_420 <= V_487 ) {
char V_235 [ 64 ] ;
if ( V_155 > sizeof( V_235 ) - sizeof( struct V_419 ) ) {
F_78 ( V_14 , V_277 ) ;
goto V_18;
}
V_133 = V_438 ;
V_155 = F_236 ( V_14 , V_132 -> V_156 , V_155 ,
V_235 , & V_133 ) ;
if ( V_155 < 0 ) {
F_78 ( V_14 , V_277 ) ;
goto V_18;
}
F_80 ( V_3 , F_84 ( V_3 ) ,
V_285 , V_155 , V_235 ) ;
V_14 -> V_286 ++ ;
if ( V_133 != V_438 )
goto V_18;
break;
}
default:
F_27 ( V_14 , V_277 ) ;
F_77 ( V_14 , V_488 ) ;
F_78 ( V_14 , V_277 ) ;
goto V_18;
}
if ( V_83 & V_484 )
goto V_18;
F_58 ( V_485 , & V_14 -> V_71 ) ;
if ( F_73 ( V_459 , & V_14 -> V_71 ) ) {
F_248 ( V_14 ) ;
if ( V_14 -> V_119 == V_121 ||
V_14 -> V_119 == V_125 )
V_15 = F_225 ( V_14 ) ;
if ( V_15 < 0 )
F_78 ( V_14 , - V_15 ) ;
else
F_124 ( V_14 ) ;
}
V_18:
F_50 ( V_14 ) ;
return V_15 ;
}
static inline int F_253 ( struct V_2 * V_3 ,
struct V_385 * V_386 , T_2 * V_156 )
{
struct V_273 * V_235 = (struct V_273 * ) V_156 ;
struct V_489 V_132 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
struct V_26 * V_13 ;
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
F_80 ( V_3 , V_386 -> V_9 , V_490 , sizeof( V_132 ) , & V_132 ) ;
F_24 ( V_13 ) ;
V_13 -> V_491 = V_492 ;
F_25 ( V_13 ) ;
F_61 ( V_14 ) ;
F_69 ( V_14 , V_277 ) ;
F_50 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_51 ( V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
static inline int F_254 ( struct V_2 * V_3 ,
struct V_385 * V_386 , T_2 * V_156 )
{
struct V_489 * V_132 = (struct V_489 * ) V_156 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
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
static inline int F_255 ( struct V_2 * V_3 ,
struct V_385 * V_386 , T_2 * V_156 )
{
struct V_261 * V_235 = (struct V_261 * ) V_156 ;
T_1 type ;
type = F_67 ( V_235 -> type ) ;
F_21 ( L_53 , type ) ;
if ( type == V_262 ) {
T_2 V_278 [ 8 ] ;
T_8 V_267 = V_269 ;
struct V_493 * V_132 = (struct V_493 * ) V_278 ;
V_132 -> type = F_79 ( V_262 ) ;
V_132 -> V_133 = F_79 ( V_494 ) ;
if ( ! V_270 )
V_267 |= V_271 | V_272
| V_429 ;
if ( V_229 )
V_267 |= V_411
| V_410 ;
F_102 ( V_267 , V_132 -> V_156 ) ;
F_80 ( V_3 , V_386 -> V_9 , V_495 , sizeof( V_278 ) ,
V_278 ) ;
} else if ( type == V_496 ) {
T_2 V_278 [ 12 ] ;
struct V_493 * V_132 = (struct V_493 * ) V_278 ;
if ( V_229 )
V_497 [ 0 ] |= V_233 ;
else
V_497 [ 0 ] &= ~ V_233 ;
V_132 -> type = F_79 ( V_496 ) ;
V_132 -> V_133 = F_79 ( V_494 ) ;
memcpy ( V_132 -> V_156 , V_497 , sizeof( V_497 ) ) ;
F_80 ( V_3 , V_386 -> V_9 , V_495 , sizeof( V_278 ) ,
V_278 ) ;
} else {
struct V_493 V_132 ;
V_132 . type = F_16 ( type ) ;
V_132 . V_133 = F_79 ( V_498 ) ;
F_80 ( V_3 , V_386 -> V_9 , V_495 , sizeof( V_132 ) ,
& V_132 ) ;
}
return 0 ;
}
static inline int F_256 ( struct V_2 * V_3 ,
struct V_385 * V_386 , T_2 * V_156 )
{
struct V_493 * V_132 = (struct V_493 * ) V_156 ;
T_1 type , V_133 ;
type = F_67 ( V_132 -> type ) ;
V_133 = F_67 ( V_132 -> V_133 ) ;
F_21 ( L_54 , type , V_133 ) ;
if ( V_386 -> V_9 != V_3 -> V_263 ||
V_3 -> V_258 & V_260 )
return 0 ;
F_242 ( & V_3 -> V_264 ) ;
if ( V_133 != V_494 ) {
V_3 -> V_258 |= V_260 ;
V_3 -> V_263 = 0 ;
F_130 ( V_3 ) ;
return 0 ;
}
switch ( type ) {
case V_262 :
V_3 -> V_267 = F_96 ( V_132 -> V_156 ) ;
if ( V_3 -> V_267 & V_499 ) {
struct V_261 V_235 ;
V_235 . type = F_79 ( V_496 ) ;
V_3 -> V_263 = F_84 ( V_3 ) ;
F_80 ( V_3 , V_3 -> V_263 ,
V_266 , sizeof( V_235 ) , & V_235 ) ;
} else {
V_3 -> V_258 |= V_260 ;
V_3 -> V_263 = 0 ;
F_130 ( V_3 ) ;
}
break;
case V_496 :
V_3 -> V_232 = V_132 -> V_156 [ 0 ] ;
V_3 -> V_258 |= V_260 ;
V_3 -> V_263 = 0 ;
F_130 ( V_3 ) ;
break;
}
return 0 ;
}
static int F_257 ( struct V_2 * V_3 ,
struct V_385 * V_386 ,
T_1 V_478 , void * V_156 )
{
struct V_238 * V_235 = V_156 ;
struct V_500 V_132 ;
struct V_1 * V_14 ;
struct V_316 * V_157 ;
T_1 V_10 , V_7 ;
if ( V_478 != sizeof( * V_235 ) )
return - V_501 ;
if ( ! V_229 )
return - V_20 ;
V_10 = F_234 ( V_235 -> V_10 ) ;
V_7 = F_234 ( V_235 -> V_7 ) ;
F_21 ( L_55 , V_10 , V_7 , V_235 -> V_237 ) ;
if ( V_235 -> V_237 == V_502 ) {
F_243 ( V_3 , V_386 , V_156 , V_462 ,
V_235 -> V_237 ) ;
return 0 ;
}
V_157 = F_258 ( V_235 -> V_237 ) ;
if ( ! V_157 )
goto error;
if ( V_157 -> V_503 != V_504 || ! F_73 ( V_505 , & V_157 -> V_83 ) ) {
F_160 ( V_157 ) ;
goto error;
}
V_14 = F_243 ( V_3 , V_386 , V_156 , V_462 ,
V_235 -> V_237 ) ;
if ( V_14 ) {
struct V_113 * V_114 = V_3 -> V_88 -> V_113 ;
struct V_168 * V_169 ;
V_169 = F_259 ( V_157 , V_309 , V_3 -> V_287 ) ;
if ( ! V_169 ) {
F_160 ( V_157 ) ;
return - V_348 ;
}
F_21 ( L_56 , V_114 , V_14 , V_169 ) ;
V_114 -> V_115 = V_14 ;
V_14 -> V_169 = V_169 ;
V_14 -> V_73 = V_430 ;
V_3 -> V_310 = V_157 -> V_311 ;
}
F_160 ( V_157 ) ;
return 0 ;
error:
V_132 . V_6 = 0 ;
V_132 . V_7 = F_16 ( V_7 ) ;
V_132 . V_133 = F_79 ( V_506 ) ;
V_132 . V_138 = F_79 ( V_139 ) ;
F_80 ( V_3 , V_386 -> V_9 , V_462 ,
sizeof( V_132 ) , & V_132 ) ;
return - V_348 ;
}
static void F_260 ( struct V_1 * V_14 , T_2 V_507 )
{
struct V_508 V_235 ;
T_2 V_9 ;
F_21 ( L_57 , V_14 , V_507 ) ;
V_9 = F_84 ( V_14 -> V_3 ) ;
V_14 -> V_9 = V_9 ;
V_235 . V_509 = F_16 ( V_14 -> V_7 ) ;
V_235 . V_507 = V_507 ;
F_80 ( V_14 -> V_3 , V_9 , V_510 , sizeof( V_235 ) ,
& V_235 ) ;
F_77 ( V_14 , V_511 ) ;
}
static void F_261 ( struct V_1 * V_14 , T_1 V_133 )
{
struct V_512 V_132 ;
F_21 ( L_58 , V_14 , V_133 ) ;
V_132 . V_509 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_133 = F_16 ( V_133 ) ;
F_80 ( V_14 -> V_3 , V_14 -> V_9 , V_513 ,
sizeof( V_132 ) , & V_132 ) ;
}
static void F_262 ( struct V_1 * V_14 , T_1 V_133 )
{
struct V_514 V_515 ;
F_21 ( L_58 , V_14 , V_133 ) ;
V_14 -> V_9 = F_84 ( V_14 -> V_3 ) ;
V_515 . V_509 = F_16 ( V_14 -> V_7 ) ;
V_515 . V_133 = F_16 ( V_133 ) ;
F_80 ( V_14 -> V_3 , V_14 -> V_9 , V_516 ,
sizeof( V_515 ) , & V_515 ) ;
F_77 ( V_14 , V_511 ) ;
}
static void F_263 ( struct V_2 * V_3 , T_1 V_509 )
{
struct V_514 V_515 ;
F_21 ( L_59 , V_3 , V_509 ) ;
V_515 . V_509 = F_16 ( V_509 ) ;
V_515 . V_133 = F_79 ( V_517 ) ;
F_80 ( V_3 , F_84 ( V_3 ) , V_516 ,
sizeof( V_515 ) , & V_515 ) ;
}
static void F_264 ( struct V_2 * V_3 , T_2 V_9 ,
T_1 V_509 )
{
struct V_518 V_132 ;
F_21 ( L_60 , V_509 ) ;
V_132 . V_509 = F_16 ( V_509 ) ;
F_80 ( V_3 , V_9 , V_519 , sizeof( V_132 ) , & V_132 ) ;
}
static void F_265 ( struct V_1 * V_14 )
{
V_14 -> V_116 = NULL ;
V_14 -> V_169 = NULL ;
}
static void F_266 ( struct V_1 * V_14 )
{
if ( V_14 -> V_23 != V_56 ) {
F_78 ( V_14 , V_277 ) ;
return;
}
switch ( V_14 -> V_250 ) {
case V_255 :
F_122 ( V_14 ) ;
F_261 ( V_14 , V_520 ) ;
break;
case V_252 :
if ( V_14 -> V_165 == V_521 ||
V_14 -> V_165 == V_522 ) {
F_122 ( V_14 ) ;
}
F_262 ( V_14 , V_517 ) ;
break;
}
}
static void F_267 ( struct V_1 * V_14 ,
struct V_117 * V_164 )
{
struct V_433 V_132 ;
V_14 -> V_116 = V_164 ;
V_14 -> V_169 -> V_304 = V_14 -> V_3 ;
F_249 ( V_14 , & V_132 , V_14 -> V_9 , 0 ) ;
if ( F_73 ( V_485 , & V_14 -> V_71 ) ) {
int V_15 ;
F_248 ( V_14 ) ;
V_15 = F_225 ( V_14 ) ;
if ( V_15 < 0 )
F_78 ( V_14 , - V_15 ) ;
else
F_124 ( V_14 ) ;
}
}
static void F_268 ( struct V_1 * V_14 ,
struct V_117 * V_164 )
{
V_14 -> V_169 = V_164 -> V_3 ;
V_14 -> V_169 -> V_304 = V_14 -> V_3 ;
F_21 ( L_61 , V_14 -> V_165 ) ;
switch ( V_14 -> V_165 ) {
case V_521 :
V_14 -> V_165 = V_523 ;
break;
case V_522 :
if ( F_73 ( V_226 , & V_14 -> V_220 ) ) {
V_14 -> V_165 = V_524 ;
} else if ( V_14 -> V_250 == V_252 ) {
V_14 -> V_165 = V_525 ;
F_262 ( V_14 , V_526 ) ;
} else if ( V_14 -> V_250 == V_255 ) {
V_14 -> V_165 = V_527 ;
F_261 ( V_14 , V_528 ) ;
}
break;
default:
F_265 ( V_14 ) ;
V_14 -> V_165 = V_166 ;
}
}
void F_269 ( struct V_1 * V_14 , struct V_117 * V_164 ,
T_2 V_138 )
{
F_21 ( L_62 , V_14 , V_164 , V_138 ) ;
if ( V_138 ) {
F_266 ( V_14 ) ;
F_265 ( V_14 ) ;
return;
}
if ( V_14 -> V_23 != V_56 ) {
if ( V_14 -> V_407 )
F_267 ( V_14 , V_164 ) ;
} else {
F_268 ( V_14 , V_164 ) ;
}
}
void F_270 ( struct V_1 * V_14 )
{
F_21 ( L_3 , V_14 ) ;
if ( V_14 -> V_407 == V_502 ) {
if ( V_14 -> V_230 != V_231 )
return;
V_14 -> V_250 = V_252 ;
V_14 -> V_165 = V_167 ;
} else {
V_14 -> V_250 = V_252 ;
V_14 -> V_165 = V_523 ;
V_14 -> V_408 = 0 ;
F_121 ( V_14 ) ;
F_260 ( V_14 , 0 ) ;
}
}
static void F_271 ( struct V_1 * V_14 , int V_133 ,
T_2 V_407 , T_2 V_529 )
{
F_21 ( L_63 , V_14 , F_22 ( V_14 -> V_23 ) ,
V_407 , V_529 ) ;
V_14 -> V_73 = V_430 ;
if ( V_14 -> V_23 == V_59 ) {
if ( V_133 == V_282 ) {
V_14 -> V_407 = V_407 ;
F_120 ( V_14 , V_529 ) ;
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
V_132 . V_133 = F_79 ( V_470 ) ;
V_132 . V_138 = F_79 ( V_139 ) ;
}
F_80 ( V_14 -> V_3 , V_14 -> V_9 , V_462 ,
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
static void F_272 ( struct V_1 * V_14 , T_2 V_407 ,
T_2 V_529 )
{
F_121 ( V_14 ) ;
V_14 -> V_408 = V_407 ;
V_14 -> V_165 = V_530 ;
F_260 ( V_14 , V_529 ) ;
}
static void F_273 ( struct V_1 * V_14 , int V_133 )
{
struct V_117 * V_164 = NULL ;
if ( V_164 ) {
if ( V_164 -> V_23 == V_56 ) {
V_14 -> V_169 = V_164 -> V_3 ;
V_14 -> V_169 -> V_304 = V_14 -> V_3 ;
V_14 -> V_165 = V_527 ;
F_261 ( V_14 , V_528 ) ;
F_269 ( V_14 , V_164 , V_528 ) ;
} else {
V_14 -> V_165 = V_522 ;
}
} else {
F_261 ( V_14 , V_531 ) ;
}
}
static void F_274 ( struct V_1 * V_14 , int V_133 )
{
if ( V_14 -> V_250 == V_255 ) {
T_2 V_532 ;
if ( V_133 == - V_20 )
V_532 = V_533 ;
else
V_532 = V_531 ;
F_261 ( V_14 , V_532 ) ;
}
V_14 -> V_250 = V_251 ;
V_14 -> V_165 = V_166 ;
F_179 ( V_14 ) ;
}
void F_275 ( struct V_1 * V_14 , int V_133 )
{
T_2 V_407 = V_14 -> V_407 ;
T_2 V_529 = V_14 -> V_529 ;
F_21 ( L_64 ,
V_14 , V_133 , V_407 , V_529 ) ;
if ( V_14 -> V_23 == V_137 || V_14 -> V_23 == V_534 ) {
F_50 ( V_14 ) ;
return;
}
if ( V_14 -> V_23 != V_56 ) {
F_271 ( V_14 , V_133 , V_407 , V_529 ) ;
} else if ( V_133 != V_528 ) {
F_274 ( V_14 , V_133 ) ;
} else {
switch ( V_14 -> V_250 ) {
case V_252 :
F_272 ( V_14 , V_407 ,
V_529 ) ;
break;
case V_255 :
F_273 ( V_14 , V_133 ) ;
break;
default:
F_274 ( V_14 , V_133 ) ;
break;
}
}
}
static inline int F_276 ( struct V_2 * V_3 ,
struct V_385 * V_386 ,
T_1 V_478 , void * V_156 )
{
struct V_508 * V_235 = V_156 ;
struct V_512 V_132 ;
struct V_1 * V_14 ;
T_1 V_509 = 0 ;
T_1 V_133 = V_531 ;
if ( V_478 != sizeof( * V_235 ) )
return - V_501 ;
V_509 = F_234 ( V_235 -> V_509 ) ;
F_21 ( L_65 , V_509 , V_235 -> V_507 ) ;
if ( ! V_229 )
return - V_20 ;
V_14 = F_8 ( V_3 , V_509 ) ;
if ( ! V_14 ) {
V_132 . V_509 = F_16 ( V_509 ) ;
V_132 . V_133 = F_79 ( V_531 ) ;
F_80 ( V_3 , V_386 -> V_9 , V_513 ,
sizeof( V_132 ) , & V_132 ) ;
return 0 ;
}
V_14 -> V_9 = V_386 -> V_9 ;
if ( V_14 -> V_7 < V_21 ||
V_14 -> V_230 == V_535 ||
( V_14 -> V_119 != V_121 &&
V_14 -> V_119 != V_125 ) ) {
V_133 = V_531 ;
goto V_536;
}
if ( V_14 -> V_407 == V_235 -> V_507 ) {
V_133 = V_537 ;
goto V_536;
}
if ( V_235 -> V_507 ) {
struct V_316 * V_157 ;
V_157 = F_258 ( V_235 -> V_507 ) ;
if ( ! V_157 || V_157 -> V_503 != V_504 ||
! F_73 ( V_505 , & V_157 -> V_83 ) ) {
if ( V_157 )
F_160 ( V_157 ) ;
V_133 = V_533 ;
goto V_536;
}
F_160 ( V_157 ) ;
}
if ( ( F_90 ( V_14 ) ||
V_14 -> V_250 != V_251 ) &&
F_12 ( V_3 -> V_11 , V_3 -> V_287 ) > 0 ) {
V_133 = V_538 ;
goto V_536;
}
V_14 -> V_250 = V_255 ;
F_121 ( V_14 ) ;
V_14 -> V_408 = V_235 -> V_507 ;
V_509 = V_14 -> V_6 ;
if ( ! V_235 -> V_507 ) {
if ( F_73 ( V_226 , & V_14 -> V_220 ) ) {
V_14 -> V_165 = V_524 ;
V_133 = V_539 ;
} else {
V_14 -> V_165 = V_527 ;
V_133 = V_528 ;
}
} else {
V_14 -> V_165 = V_167 ;
V_133 = V_539 ;
}
V_536:
F_261 ( V_14 , V_133 ) ;
F_50 ( V_14 ) ;
return 0 ;
}
static void F_277 ( struct V_2 * V_3 , T_1 V_509 , T_1 V_133 )
{
struct V_1 * V_14 ;
struct V_117 * V_164 = NULL ;
V_14 = F_4 ( V_3 , V_509 ) ;
if ( ! V_14 ) {
F_263 ( V_3 , V_509 ) ;
return;
}
F_70 ( V_14 ) ;
if ( V_133 == V_539 )
F_77 ( V_14 , V_540 ) ;
switch ( V_14 -> V_165 ) {
case V_521 :
V_14 -> V_165 = V_522 ;
break;
case V_523 :
if ( V_133 == V_539 ) {
break;
} else if ( F_73 ( V_226 ,
& V_14 -> V_220 ) ) {
V_14 -> V_165 = V_524 ;
} else {
V_14 -> V_165 = V_525 ;
F_262 ( V_14 , V_526 ) ;
}
break;
case V_530 :
if ( V_133 == V_528 ) {
V_14 -> V_165 = V_522 ;
} else {
V_14 -> V_165 = V_521 ;
}
if ( ! V_164 ) {
F_262 ( V_14 , V_517 ) ;
break;
}
if ( V_164 -> V_23 != V_56 )
break;
V_14 -> V_169 = V_164 -> V_3 ;
V_14 -> V_169 -> V_304 = V_14 -> V_3 ;
if ( V_133 == V_528 ) {
F_262 ( V_14 , V_526 ) ;
} else {
V_14 -> V_165 = V_523 ;
}
F_269 ( V_14 , V_164 , V_528 ) ;
break;
default:
V_14 -> V_408 = V_14 -> V_407 ;
F_122 ( V_14 ) ;
F_262 ( V_14 , V_517 ) ;
}
F_50 ( V_14 ) ;
}
static void F_278 ( struct V_2 * V_3 , T_2 V_9 , T_1 V_509 ,
T_1 V_133 )
{
struct V_1 * V_14 ;
V_14 = F_10 ( V_3 , V_9 ) ;
if ( ! V_14 ) {
F_263 ( V_3 , V_509 ) ;
return;
}
F_70 ( V_14 ) ;
if ( V_14 -> V_250 == V_252 ) {
if ( V_133 == V_538 ) {
V_14 -> V_250 = V_255 ;
} else {
V_14 -> V_408 = V_14 -> V_407 ;
F_122 ( V_14 ) ;
}
}
F_262 ( V_14 , V_517 ) ;
F_50 ( V_14 ) ;
}
static int F_279 ( struct V_2 * V_3 ,
struct V_385 * V_386 ,
T_1 V_478 , void * V_156 )
{
struct V_512 * V_132 = V_156 ;
T_1 V_509 , V_133 ;
if ( V_478 != sizeof( * V_132 ) )
return - V_501 ;
V_509 = F_234 ( V_132 -> V_509 ) ;
V_133 = F_234 ( V_132 -> V_133 ) ;
F_21 ( L_66 , V_509 , V_133 ) ;
if ( V_133 == V_528 || V_133 == V_539 )
F_277 ( V_3 , V_509 , V_133 ) ;
else
F_278 ( V_3 , V_386 -> V_9 , V_509 , V_133 ) ;
return 0 ;
}
static int F_280 ( struct V_2 * V_3 ,
struct V_385 * V_386 ,
T_1 V_478 , void * V_156 )
{
struct V_514 * V_515 = V_156 ;
struct V_1 * V_14 ;
T_1 V_509 , V_133 ;
if ( V_478 != sizeof( * V_515 ) )
return - V_501 ;
V_509 = F_234 ( V_515 -> V_509 ) ;
V_133 = F_234 ( V_515 -> V_133 ) ;
F_21 ( L_66 , V_509 , V_133 ) ;
V_14 = F_8 ( V_3 , V_509 ) ;
if ( ! V_14 ) {
F_264 ( V_3 , V_386 -> V_9 , V_509 ) ;
return 0 ;
}
if ( V_14 -> V_165 == V_527 ) {
if ( V_133 == V_526 ) {
V_14 -> V_407 = V_14 -> V_408 ;
if ( ! V_14 -> V_407 )
F_265 ( V_14 ) ;
} else {
V_14 -> V_408 = V_14 -> V_407 ;
}
F_122 ( V_14 ) ;
}
F_264 ( V_3 , V_386 -> V_9 , V_509 ) ;
F_50 ( V_14 ) ;
return 0 ;
}
static inline int F_281 ( struct V_2 * V_3 ,
struct V_385 * V_386 ,
T_1 V_478 , void * V_156 )
{
struct V_518 * V_132 = V_156 ;
struct V_1 * V_14 ;
T_1 V_509 ;
if ( V_478 != sizeof( * V_132 ) )
return - V_501 ;
V_509 = F_234 ( V_132 -> V_509 ) ;
F_21 ( L_60 , V_509 ) ;
V_14 = F_4 ( V_3 , V_509 ) ;
if ( ! V_14 )
return 0 ;
F_70 ( V_14 ) ;
if ( V_14 -> V_165 == V_525 ) {
V_14 -> V_407 = V_14 -> V_408 ;
if ( ! V_14 -> V_407 && V_14 -> V_116 )
F_265 ( V_14 ) ;
F_122 ( V_14 ) ;
}
F_50 ( V_14 ) ;
return 0 ;
}
static inline int F_282 ( T_1 V_541 , T_1 V_542 , T_1 V_543 ,
T_1 V_544 )
{
T_1 V_545 ;
if ( V_541 > V_542 || V_541 < 6 || V_542 > 3200 )
return - V_20 ;
if ( V_544 < 10 || V_544 > 3200 )
return - V_20 ;
if ( V_542 >= V_544 * 8 )
return - V_20 ;
V_545 = ( V_544 * 8 / V_542 ) - 1 ;
if ( V_543 > 499 || V_543 > V_545 )
return - V_20 ;
return 0 ;
}
static inline int F_283 ( struct V_2 * V_3 ,
struct V_385 * V_386 ,
T_2 * V_156 )
{
struct V_168 * V_88 = V_3 -> V_88 ;
struct F_283 * V_235 ;
struct V_546 V_132 ;
T_1 V_541 , V_542 , V_543 , V_544 , V_478 ;
int V_15 ;
if ( ! ( V_88 -> V_547 & V_548 ) )
return - V_20 ;
V_478 = F_67 ( V_386 -> V_155 ) ;
if ( V_478 != sizeof( struct F_283 ) )
return - V_501 ;
V_235 = (struct F_283 * ) V_156 ;
V_541 = F_67 ( V_235 -> V_541 ) ;
V_542 = F_67 ( V_235 -> V_542 ) ;
V_543 = F_67 ( V_235 -> V_543 ) ;
V_544 = F_67 ( V_235 -> V_544 ) ;
F_21 ( L_67 ,
V_541 , V_542 , V_543 , V_544 ) ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_15 = F_282 ( V_541 , V_542 , V_543 , V_544 ) ;
if ( V_15 )
V_132 . V_133 = F_79 ( V_549 ) ;
else
V_132 . V_133 = F_79 ( V_550 ) ;
F_80 ( V_3 , V_386 -> V_9 , V_551 ,
sizeof( V_132 ) , & V_132 ) ;
if ( ! V_15 )
F_284 ( V_88 , V_541 , V_542 , V_543 , V_544 ) ;
return 0 ;
}
static inline int F_285 ( struct V_2 * V_3 ,
struct V_385 * V_386 , T_1 V_478 ,
T_2 * V_156 )
{
int V_15 = 0 ;
switch ( V_386 -> V_154 ) {
case V_482 :
F_241 ( V_3 , V_386 , V_156 ) ;
break;
case V_236 :
V_15 = F_245 ( V_3 , V_386 , V_156 ) ;
break;
case V_140 :
case V_462 :
V_15 = F_247 ( V_3 , V_386 , V_156 ) ;
break;
case V_285 :
V_15 = F_250 ( V_3 , V_386 , V_478 , V_156 ) ;
break;
case V_477 :
V_15 = F_251 ( V_3 , V_386 , V_156 ) ;
break;
case V_274 :
V_15 = F_253 ( V_3 , V_386 , V_156 ) ;
break;
case V_490 :
V_15 = F_254 ( V_3 , V_386 , V_156 ) ;
break;
case V_552 :
F_80 ( V_3 , V_386 -> V_9 , V_553 , V_478 , V_156 ) ;
break;
case V_553 :
break;
case V_266 :
V_15 = F_255 ( V_3 , V_386 , V_156 ) ;
break;
case V_495 :
V_15 = F_256 ( V_3 , V_386 , V_156 ) ;
break;
case V_239 :
V_15 = F_257 ( V_3 , V_386 , V_478 , V_156 ) ;
break;
case V_510 :
V_15 = F_276 ( V_3 , V_386 , V_478 , V_156 ) ;
break;
case V_513 :
V_15 = F_279 ( V_3 , V_386 , V_478 , V_156 ) ;
break;
case V_516 :
V_15 = F_280 ( V_3 , V_386 , V_478 , V_156 ) ;
break;
case V_519 :
V_15 = F_281 ( V_3 , V_386 , V_478 , V_156 ) ;
break;
default:
F_286 ( L_68 , V_386 -> V_154 ) ;
V_15 = - V_20 ;
break;
}
return V_15 ;
}
static inline int F_287 ( struct V_2 * V_3 ,
struct V_385 * V_386 , T_2 * V_156 )
{
switch ( V_386 -> V_154 ) {
case V_482 :
return 0 ;
case V_554 :
return F_283 ( V_3 , V_386 , V_156 ) ;
case V_551 :
return 0 ;
default:
F_286 ( L_69 , V_386 -> V_154 ) ;
return - V_20 ;
}
}
static inline void F_288 ( struct V_2 * V_3 ,
struct V_32 * V_36 )
{
T_2 * V_156 = V_36 -> V_156 ;
int V_155 = V_36 -> V_155 ;
struct V_385 V_386 ;
int V_15 ;
F_218 ( V_3 , V_36 ) ;
while ( V_155 >= V_387 ) {
T_1 V_478 ;
memcpy ( & V_386 , V_156 , V_387 ) ;
V_156 += V_387 ;
V_155 -= V_387 ;
V_478 = F_234 ( V_386 . V_155 ) ;
F_21 ( L_70 , V_386 . V_154 , V_478 ,
V_386 . V_9 ) ;
if ( V_478 > V_155 || ! V_386 . V_9 ) {
F_21 ( L_71 ) ;
break;
}
if ( V_3 -> V_88 -> type == V_89 )
V_15 = F_287 ( V_3 , & V_386 , V_156 ) ;
else
V_15 = F_285 ( V_3 , & V_386 , V_478 , V_156 ) ;
if ( V_15 ) {
struct V_464 V_465 ;
F_286 ( L_72 , V_15 ) ;
V_465 . V_55 = F_79 ( V_466 ) ;
F_80 ( V_3 , V_386 . V_9 , V_482 ,
sizeof( V_465 ) , & V_465 ) ;
}
V_156 += V_478 ;
V_155 -= V_478 ;
}
F_92 ( V_36 ) ;
}
static int F_289 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
T_1 V_555 , V_556 ;
int V_557 ;
if ( F_73 ( V_207 , & V_14 -> V_83 ) )
V_557 = V_212 ;
else
V_557 = V_213 ;
if ( V_14 -> V_73 == V_74 ) {
F_290 ( V_36 , V_36 -> V_155 - V_217 ) ;
V_556 = F_98 ( V_36 -> V_156 + V_36 -> V_155 ) ;
V_555 = F_109 ( 0 , V_36 -> V_156 - V_557 , V_36 -> V_155 + V_557 ) ;
if ( V_555 != V_556 )
return - V_558 ;
}
return 0 ;
}
static void F_291 ( struct V_1 * V_14 )
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
V_14 -> V_328 > 0 )
F_28 ( V_14 ) ;
F_179 ( V_14 ) ;
if ( ! F_73 ( V_226 , & V_14 -> V_220 ) &&
F_73 ( V_219 , & V_14 -> V_220 ) ) {
V_37 . V_185 = V_221 ;
F_110 ( V_14 , & V_37 ) ;
}
}
static void F_292 ( struct V_32 * V_36 , struct V_32 * V_559 ,
struct V_32 * * V_560 )
{
if ( ! F_293 ( V_36 ) )
F_195 ( V_36 ) -> V_349 = V_559 ;
V_559 -> V_354 = NULL ;
( * V_560 ) -> V_354 = V_559 ;
* V_560 = V_559 ;
V_36 -> V_155 += V_559 -> V_155 ;
V_36 -> V_353 += V_559 -> V_155 ;
V_36 -> V_561 += V_559 -> V_561 ;
}
static int F_294 ( struct V_1 * V_14 , struct V_32 * V_36 ,
struct V_173 * V_37 )
{
int V_15 = - V_20 ;
switch ( V_37 -> V_188 ) {
case V_363 :
if ( V_14 -> V_405 )
break;
V_15 = V_14 -> V_24 -> V_383 ( V_14 , V_36 ) ;
break;
case V_364 :
if ( V_14 -> V_405 )
break;
V_14 -> V_359 = F_98 ( V_36 -> V_156 ) ;
F_97 ( V_36 , V_357 ) ;
if ( V_14 -> V_359 > V_14 -> V_98 ) {
V_15 = - V_367 ;
break;
}
if ( V_36 -> V_155 >= V_14 -> V_359 )
break;
V_14 -> V_405 = V_36 ;
V_14 -> V_406 = V_36 ;
V_36 = NULL ;
V_15 = 0 ;
break;
case V_366 :
if ( ! V_14 -> V_405 )
break;
F_292 ( V_14 -> V_405 , V_36 ,
& V_14 -> V_406 ) ;
V_36 = NULL ;
if ( V_14 -> V_405 -> V_155 >= V_14 -> V_359 )
break;
V_15 = 0 ;
break;
case V_365 :
if ( ! V_14 -> V_405 )
break;
F_292 ( V_14 -> V_405 , V_36 ,
& V_14 -> V_406 ) ;
V_36 = NULL ;
if ( V_14 -> V_405 -> V_155 != V_14 -> V_359 )
break;
V_15 = V_14 -> V_24 -> V_383 ( V_14 , V_14 -> V_405 ) ;
if ( ! V_15 ) {
V_14 -> V_405 = NULL ;
V_14 -> V_406 = NULL ;
V_14 -> V_359 = 0 ;
}
break;
}
if ( V_15 ) {
F_92 ( V_36 ) ;
F_92 ( V_14 -> V_405 ) ;
V_14 -> V_405 = NULL ;
V_14 -> V_406 = NULL ;
V_14 -> V_359 = 0 ;
}
return V_15 ;
}
static int F_295 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_296 ( struct V_1 * V_14 , int V_562 )
{
T_2 V_373 ;
if ( V_14 -> V_119 != V_121 )
return;
V_373 = V_562 ? V_374 : V_376 ;
F_123 ( V_14 , NULL , NULL , V_373 ) ;
}
static int F_297 ( struct V_1 * V_14 )
{
int V_15 = 0 ;
F_21 ( L_3 , V_14 ) ;
while ( ! F_73 ( V_226 , & V_14 -> V_220 ) ) {
struct V_32 * V_36 ;
F_21 ( L_73 ,
V_14 -> V_227 , F_183 ( & V_14 -> V_122 ) ) ;
V_36 = F_34 ( & V_14 -> V_122 , V_14 -> V_227 ) ;
if ( ! V_36 )
break;
F_211 ( V_36 , & V_14 -> V_122 ) ;
V_14 -> V_227 = F_178 ( V_14 , V_14 -> V_227 ) ;
V_15 = F_294 ( V_14 , V_36 , & F_36 ( V_36 ) -> V_37 ) ;
if ( V_15 )
break;
}
if ( F_176 ( & V_14 -> V_122 ) ) {
V_14 -> V_247 = V_342 ;
F_190 ( V_14 ) ;
}
return V_15 ;
}
static void F_298 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
struct V_32 * V_36 ;
F_21 ( L_11 , V_14 , V_37 ) ;
if ( V_37 -> V_174 == V_14 -> V_333 ) {
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
F_216 ( V_14 , V_37 ) ;
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_187 ( V_14 , V_37 ) ;
F_179 ( V_14 ) ;
if ( V_14 -> V_245 == V_378 ) {
F_58 ( V_244 , & V_14 -> V_220 ) ;
V_14 -> V_563 = V_37 -> V_174 ;
}
} else {
F_217 ( V_14 , V_37 ) ;
if ( V_37 -> V_177 ) {
if ( V_14 -> V_563 != V_37 -> V_174 ||
! F_111 ( V_244 ,
& V_14 -> V_220 ) )
F_187 ( V_14 , V_37 ) ;
} else {
F_187 ( V_14 , V_37 ) ;
if ( V_14 -> V_245 == V_378 ) {
F_58 ( V_244 , & V_14 -> V_220 ) ;
V_14 -> V_563 = V_37 -> V_174 ;
}
}
}
}
static void F_299 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
struct V_32 * V_36 ;
F_21 ( L_11 , V_14 , V_37 ) ;
if ( V_37 -> V_174 == V_14 -> V_333 ) {
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
F_216 ( V_14 , V_37 ) ;
if ( V_37 -> V_177 ) {
if ( ! F_111 ( V_243 , & V_14 -> V_220 ) )
F_188 ( V_14 , V_37 ) ;
} else {
F_188 ( V_14 , V_37 ) ;
F_179 ( V_14 ) ;
if ( V_14 -> V_245 == V_378 )
F_58 ( V_243 , & V_14 -> V_220 ) ;
}
}
static T_2 F_300 ( struct V_1 * V_14 , T_1 V_38 )
{
F_21 ( L_76 , V_14 , V_38 ) ;
F_21 ( L_77 , V_14 -> V_225 ,
V_14 -> V_242 ) ;
if ( V_14 -> V_247 == V_375 ) {
if ( F_191 ( V_14 , V_38 , V_14 -> V_225 ) >=
V_14 -> V_77 ) {
if ( V_14 -> V_77 <= ( ( V_14 -> V_79 + 1 ) >> 1 ) ) {
F_21 ( L_78 ) ;
return V_564 ;
} else {
F_21 ( L_79 ) ;
return V_565 ;
}
}
if ( V_14 -> V_123 . V_34 == V_38 ) {
F_21 ( L_80 ) ;
return V_566 ;
}
if ( F_34 ( & V_14 -> V_122 , V_38 ) ) {
F_21 ( L_81 ) ;
return V_567 ;
}
if ( F_42 ( & V_14 -> V_123 , V_38 ) ) {
F_21 ( L_82 ) ;
return V_568 ;
}
}
if ( V_14 -> V_242 == V_38 ) {
if ( F_191 ( V_14 , V_38 , V_14 -> V_225 ) >=
V_14 -> V_77 ) {
F_21 ( L_83 ) ;
return V_565 ;
} else {
F_21 ( L_84 ) ;
return V_569 ;
}
}
if ( F_191 ( V_14 , V_38 , V_14 -> V_225 ) <
F_191 ( V_14 , V_14 -> V_242 , V_14 -> V_225 ) ) {
F_21 ( L_85 ) ;
return V_570 ;
}
if ( F_191 ( V_14 , V_38 , V_14 -> V_225 ) >= V_14 -> V_77 ) {
if ( V_14 -> V_77 <= ( ( V_14 -> V_79 + 1 ) >> 1 ) ) {
F_21 ( L_86 ) ;
return V_564 ;
} else {
F_21 ( L_83 ) ;
return V_565 ;
}
} else {
F_21 ( L_87 ) ;
return V_571 ;
}
}
static int F_301 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_373 )
{
int V_15 = 0 ;
bool V_572 = 0 ;
F_21 ( L_88 , V_14 , V_37 , V_36 ,
V_373 ) ;
switch ( V_373 ) {
case V_573 :
switch ( F_300 ( V_14 , V_37 -> V_38 ) ) {
case V_569 :
F_216 ( V_14 , V_37 ) ;
if ( F_73 ( V_226 , & V_14 -> V_220 ) ) {
F_21 ( L_89 ,
V_37 -> V_38 ) ;
break;
}
V_14 -> V_242 = F_178 ( V_14 ,
V_37 -> V_38 ) ;
V_14 -> V_227 = V_14 -> V_242 ;
V_572 = 1 ;
V_15 = F_294 ( V_14 , V_36 , V_37 ) ;
if ( V_15 )
break;
if ( V_37 -> V_177 ) {
if ( ! F_111 ( V_243 ,
& V_14 -> V_220 ) ) {
V_37 -> V_177 = 0 ;
F_188 ( V_14 , V_37 ) ;
F_179 ( V_14 ) ;
}
}
if ( ! F_73 ( V_226 , & V_14 -> V_220 ) )
F_190 ( V_14 ) ;
break;
case V_571 :
F_216 ( V_14 , V_37 ) ;
if ( F_73 ( V_226 , & V_14 -> V_220 ) ) {
F_21 ( L_90 ,
V_37 -> V_38 ) ;
break;
}
F_302 ( & V_14 -> V_122 , V_36 ) ;
V_572 = 1 ;
F_21 ( L_91 , V_36 ,
F_183 ( & V_14 -> V_122 ) ) ;
F_112 ( V_244 , & V_14 -> V_220 ) ;
F_45 ( & V_14 -> V_123 ) ;
F_207 ( V_14 , V_37 -> V_38 ) ;
V_14 -> V_247 = V_375 ;
break;
case V_570 :
F_216 ( V_14 , V_37 ) ;
break;
case V_564 :
break;
case V_565 :
default:
F_78 ( V_14 , V_277 ) ;
break;
}
break;
case V_574 :
F_216 ( V_14 , V_37 ) ;
if ( V_37 -> V_177 ) {
F_112 ( V_249 , & V_14 -> V_220 ) ;
if ( ! F_111 ( V_243 , & V_14 -> V_220 ) &&
! F_90 ( V_14 ) ) {
V_37 -> V_177 = 0 ;
F_188 ( V_14 , V_37 ) ;
}
F_179 ( V_14 ) ;
} else if ( V_37 -> V_182 ) {
F_291 ( V_14 ) ;
} else {
if ( F_111 ( V_249 ,
& V_14 -> V_220 ) &&
V_14 -> V_328 )
F_28 ( V_14 ) ;
F_179 ( V_14 ) ;
}
break;
case V_575 :
F_58 ( V_249 , & V_14 -> V_220 ) ;
F_216 ( V_14 , V_37 ) ;
if ( V_37 && V_37 -> V_182 ) {
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_114 ( V_14 , 0 ) ;
}
F_33 ( V_14 ) ;
F_45 ( & V_14 -> V_124 ) ;
break;
case V_576 :
F_299 ( V_14 , V_37 ) ;
break;
case V_577 :
F_298 ( V_14 , V_37 ) ;
break;
default:
break;
}
if ( V_36 && ! V_572 ) {
F_21 ( L_92 , V_36 ) ;
F_92 ( V_36 ) ;
}
return V_15 ;
}
static int F_303 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_373 )
{
int V_15 = 0 ;
T_1 V_38 = V_37 -> V_38 ;
bool V_572 = 0 ;
F_21 ( L_88 , V_14 , V_37 , V_36 ,
V_373 ) ;
switch ( V_373 ) {
case V_573 :
switch ( F_300 ( V_14 , V_38 ) ) {
case V_569 :
F_216 ( V_14 , V_37 ) ;
F_302 ( & V_14 -> V_122 , V_36 ) ;
V_572 = 1 ;
F_21 ( L_91 , V_36 ,
F_183 ( & V_14 -> V_122 ) ) ;
V_14 -> V_242 = F_178 ( V_14 , V_38 ) ;
break;
case V_566 :
F_44 ( & V_14 -> V_123 ) ;
F_216 ( V_14 , V_37 ) ;
F_302 ( & V_14 -> V_122 , V_36 ) ;
V_572 = 1 ;
F_21 ( L_91 , V_36 ,
F_183 ( & V_14 -> V_122 ) ) ;
V_15 = F_297 ( V_14 ) ;
if ( V_15 )
break;
break;
case V_571 :
F_302 ( & V_14 -> V_122 , V_36 ) ;
V_572 = 1 ;
F_21 ( L_91 , V_36 ,
F_183 ( & V_14 -> V_122 ) ) ;
F_216 ( V_14 , V_37 ) ;
F_207 ( V_14 , V_37 -> V_38 ) ;
break;
case V_568 :
F_302 ( & V_14 -> V_122 , V_36 ) ;
V_572 = 1 ;
F_21 ( L_91 , V_36 ,
F_183 ( & V_14 -> V_122 ) ) ;
F_216 ( V_14 , V_37 ) ;
F_209 ( V_14 , V_37 -> V_38 ) ;
break;
case V_567 :
F_216 ( V_14 , V_37 ) ;
break;
case V_570 :
break;
case V_564 :
break;
case V_565 :
default:
F_78 ( V_14 , V_277 ) ;
break;
}
break;
case V_574 :
F_216 ( V_14 , V_37 ) ;
if ( V_37 -> V_177 ) {
F_112 ( V_249 , & V_14 -> V_220 ) ;
if ( ! F_111 ( V_243 ,
& V_14 -> V_220 ) ) {
V_37 -> V_177 = 0 ;
F_188 ( V_14 , V_37 ) ;
}
F_179 ( V_14 ) ;
} else if ( V_37 -> V_182 ) {
if ( F_111 ( V_249 ,
& V_14 -> V_220 ) &&
V_14 -> V_328 ) {
F_28 ( V_14 ) ;
}
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_208 ( V_14 ) ;
} else {
if ( F_111 ( V_249 ,
& V_14 -> V_220 ) &&
V_14 -> V_328 )
F_28 ( V_14 ) ;
F_190 ( V_14 ) ;
}
break;
case V_575 :
F_58 ( V_249 , & V_14 -> V_220 ) ;
F_216 ( V_14 , V_37 ) ;
if ( V_37 -> V_182 ) {
F_208 ( V_14 ) ;
} else {
struct V_173 V_578 ;
memset ( & V_578 , 0 , sizeof( V_578 ) ) ;
V_578 . V_181 = 1 ;
V_578 . V_185 = V_221 ;
V_578 . V_174 = V_14 -> V_227 ;
F_110 ( V_14 , & V_578 ) ;
}
break;
case V_576 :
F_299 ( V_14 , V_37 ) ;
break;
case V_577 :
F_298 ( V_14 , V_37 ) ;
break;
}
if ( V_36 && ! V_572 ) {
F_21 ( L_92 , V_36 ) ;
F_92 ( V_36 ) ;
}
return V_15 ;
}
static int F_304 ( struct V_1 * V_14 )
{
F_21 ( L_3 , V_14 ) ;
V_14 -> V_247 = V_342 ;
if ( V_14 -> V_169 )
V_14 -> V_3 -> V_310 = V_14 -> V_169 -> V_157 -> V_311 ;
else
V_14 -> V_3 -> V_310 = V_14 -> V_3 -> V_88 -> V_157 -> V_313 ;
return F_295 ( V_14 ) ;
}
static int F_305 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_373 )
{
int V_15 ;
F_21 ( L_88 , V_14 , V_37 , V_36 ,
V_373 ) ;
if ( ! V_37 -> V_182 )
return - V_501 ;
F_210 ( V_14 , V_37 -> V_174 ) ;
if ( ! F_176 ( & V_14 -> V_126 ) )
V_14 -> V_338 = F_214 ( & V_14 -> V_126 ) ;
else
V_14 -> V_338 = NULL ;
V_14 -> V_333 = V_37 -> V_174 ;
V_14 -> V_328 = 0 ;
V_15 = F_304 ( V_14 ) ;
if ( V_15 )
return V_15 ;
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_291 ( V_14 ) ;
if ( V_373 == V_573 )
return - V_501 ;
return F_301 ( V_14 , V_37 , NULL , V_373 ) ;
}
static int F_306 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_373 )
{
int V_15 ;
if ( ! V_37 -> V_177 )
return - V_501 ;
F_112 ( V_249 , & V_14 -> V_220 ) ;
V_14 -> V_247 = V_342 ;
F_210 ( V_14 , V_37 -> V_174 ) ;
if ( ! F_176 ( & V_14 -> V_126 ) )
V_14 -> V_338 = F_214 ( & V_14 -> V_126 ) ;
else
V_14 -> V_338 = NULL ;
V_14 -> V_333 = V_37 -> V_174 ;
V_14 -> V_328 = 0 ;
if ( V_14 -> V_169 )
V_14 -> V_3 -> V_310 = V_14 -> V_169 -> V_157 -> V_311 ;
else
V_14 -> V_3 -> V_310 = V_14 -> V_3 -> V_88 -> V_157 -> V_313 ;
V_15 = F_295 ( V_14 ) ;
if ( ! V_15 )
V_15 = F_301 ( V_14 , V_37 , V_36 , V_373 ) ;
return V_15 ;
}
static bool F_307 ( struct V_1 * V_14 , T_1 V_174 )
{
T_1 V_579 ;
V_579 = F_191 ( V_14 , V_14 -> V_333 , V_14 -> V_372 ) ;
return F_191 ( V_14 , V_14 -> V_333 , V_174 ) <= V_579 ;
}
static int F_308 ( struct V_1 * V_14 , struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_373 )
{
int V_15 = 0 ;
F_21 ( L_93 , V_14 ,
V_37 , V_36 , V_373 , V_14 -> V_247 ) ;
if ( F_307 ( V_14 , V_37 -> V_174 ) ) {
switch ( V_14 -> V_247 ) {
case V_342 :
V_15 = F_301 ( V_14 , V_37 , V_36 , V_373 ) ;
break;
case V_375 :
V_15 = F_303 ( V_14 , V_37 , V_36 ,
V_373 ) ;
break;
case V_256 :
V_15 = F_305 ( V_14 , V_37 , V_36 , V_373 ) ;
break;
case V_254 :
V_15 = F_306 ( V_14 , V_37 , V_36 , V_373 ) ;
break;
default:
break;
}
} else {
F_21 ( L_94 ,
V_37 -> V_174 , V_14 -> V_333 ,
V_14 -> V_372 ) ;
F_78 ( V_14 , V_277 ) ;
}
return V_15 ;
}
static int F_309 ( struct V_1 * V_14 , struct V_173 * V_37 ,
struct V_32 * V_36 )
{
int V_15 = 0 ;
F_21 ( L_95 , V_14 , V_37 , V_36 ,
V_14 -> V_247 ) ;
if ( F_300 ( V_14 , V_37 -> V_38 ) ==
V_569 ) {
F_216 ( V_14 , V_37 ) ;
F_21 ( L_96 , V_14 -> V_227 ,
F_178 ( V_14 , V_14 -> V_227 ) ) ;
V_14 -> V_227 = F_178 ( V_14 , V_14 -> V_227 ) ;
F_294 ( V_14 , V_36 , V_37 ) ;
} else {
if ( V_14 -> V_405 ) {
F_92 ( V_14 -> V_405 ) ;
V_14 -> V_405 = NULL ;
}
V_14 -> V_406 = NULL ;
V_14 -> V_359 = 0 ;
if ( V_36 ) {
F_21 ( L_92 , V_36 ) ;
F_92 ( V_36 ) ;
}
}
V_14 -> V_225 = V_37 -> V_38 ;
V_14 -> V_242 = F_178 ( V_14 , V_37 -> V_38 ) ;
return V_15 ;
}
static int F_310 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
struct V_173 * V_37 = & F_36 ( V_36 ) -> V_37 ;
T_1 V_155 ;
T_2 V_373 ;
F_95 ( V_14 , V_36 ) ;
V_155 = V_36 -> V_155 ;
if ( F_289 ( V_14 , V_36 ) )
goto V_580;
if ( ! V_37 -> V_181 && V_37 -> V_188 == V_364 )
V_155 -= V_357 ;
if ( V_14 -> V_73 == V_74 )
V_155 -= V_217 ;
if ( V_155 > V_14 -> V_460 ) {
F_78 ( V_14 , V_277 ) ;
goto V_580;
}
if ( ! V_37 -> V_181 ) {
int V_15 ;
F_21 ( L_97 ,
V_37 -> V_188 , V_37 -> V_174 , V_37 -> V_177 ,
V_37 -> V_38 ) ;
if ( V_37 -> V_177 && V_14 -> V_245 != V_378 )
goto V_580;
if ( V_14 -> V_119 != V_125 ) {
V_373 = V_573 ;
V_15 = F_308 ( V_14 , V_37 , V_36 , V_373 ) ;
} else {
V_15 = F_309 ( V_14 , V_37 , V_36 ) ;
}
if ( V_15 )
F_78 ( V_14 , V_277 ) ;
} else {
const T_2 V_581 [ 4 ] = {
V_574 , V_576 ,
V_575 , V_577
} ;
if ( V_14 -> V_119 == V_125 )
goto V_580;
F_21 ( L_98 ,
V_37 -> V_174 , V_37 -> V_177 , V_37 -> V_182 ,
V_37 -> V_185 ) ;
if ( V_155 != 0 ) {
F_286 ( L_99 , V_155 ) ;
F_78 ( V_14 , V_277 ) ;
goto V_580;
}
if ( V_37 -> V_177 && ( V_37 -> V_182 ||
V_14 -> V_245 != V_378 ) )
goto V_580;
V_373 = V_581 [ V_37 -> V_185 ] ;
if ( F_308 ( V_14 , V_37 , V_36 , V_373 ) )
F_78 ( V_14 , V_277 ) ;
}
return 0 ;
V_580:
F_92 ( V_36 ) ;
return 0 ;
}
static void F_311 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_4 ( V_3 , V_4 ) ;
if ( ! V_14 ) {
if ( V_4 == V_96 ) {
V_14 = F_312 ( V_3 , V_36 ) ;
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
goto V_580;
switch ( V_14 -> V_119 ) {
case V_120 :
if ( V_14 -> V_98 < V_36 -> V_155 )
goto V_580;
if ( ! V_14 -> V_24 -> V_383 ( V_14 , V_36 ) )
goto V_18;
break;
case V_121 :
case V_125 :
F_310 ( V_14 , V_36 ) ;
goto V_18;
default:
F_21 ( L_102 , V_14 , V_14 -> V_119 ) ;
break;
}
V_580:
F_92 ( V_36 ) ;
V_18:
F_50 ( V_14 ) ;
}
static void F_313 ( struct V_2 * V_3 , T_3 V_10 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_152 ( 0 , V_10 , V_3 -> V_11 , V_3 -> V_287 ) ;
if ( ! V_14 )
goto V_580;
F_21 ( L_101 , V_14 , V_36 -> V_155 ) ;
if ( V_14 -> V_23 != V_320 && V_14 -> V_23 != V_56 )
goto V_580;
if ( V_14 -> V_98 < V_36 -> V_155 )
goto V_580;
if ( ! V_14 -> V_24 -> V_383 ( V_14 , V_36 ) )
return;
V_580:
F_92 ( V_36 ) ;
}
static void F_314 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_133 ( 0 , V_4 , V_3 -> V_11 , V_3 -> V_287 ) ;
if ( ! V_14 )
goto V_580;
F_21 ( L_101 , V_14 , V_36 -> V_155 ) ;
if ( V_14 -> V_23 != V_320 && V_14 -> V_23 != V_56 )
goto V_580;
if ( V_14 -> V_98 < V_36 -> V_155 )
goto V_580;
if ( ! V_14 -> V_24 -> V_383 ( V_14 , V_36 ) )
return;
V_580:
F_92 ( V_36 ) ;
}
static void F_315 ( struct V_2 * V_3 , struct V_32 * V_36 )
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
case V_388 :
case V_99 :
F_288 ( V_3 , V_36 ) ;
break;
case V_94 :
V_10 = F_316 ( ( T_3 * ) V_36 -> V_156 ) ;
F_97 ( V_36 , V_355 ) ;
F_313 ( V_3 , V_10 , V_36 ) ;
break;
case V_92 :
F_314 ( V_3 , V_4 , V_36 ) ;
break;
case V_582 :
if ( F_317 ( V_3 , V_36 ) )
F_143 ( V_3 -> V_88 , V_583 ) ;
break;
default:
F_311 ( V_3 , V_4 , V_36 ) ;
break;
}
}
int F_318 ( struct V_316 * V_157 , T_4 * V_314 )
{
int V_584 = 0 , V_585 = 0 , V_586 = 0 ;
struct V_1 * V_5 ;
F_21 ( L_104 , V_157 -> V_587 , V_314 ) ;
F_134 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
if ( V_5 -> V_23 != V_127 )
continue;
if ( ! F_12 ( & F_13 ( V_13 ) -> V_11 , & V_157 -> V_314 ) ) {
V_585 |= V_588 ;
if ( F_73 ( V_589 , & V_5 -> V_83 ) )
V_585 |= V_548 ;
V_584 ++ ;
} else if ( ! F_12 ( & F_13 ( V_13 ) -> V_11 , V_293 ) ) {
V_586 |= V_588 ;
if ( F_73 ( V_589 , & V_5 -> V_83 ) )
V_586 |= V_548 ;
}
}
F_135 ( & V_16 ) ;
return V_584 ? V_585 : V_586 ;
}
void F_319 ( struct V_168 * V_88 , T_2 V_138 )
{
struct V_2 * V_3 ;
F_21 ( L_105 , V_88 , & V_88 -> V_287 , V_138 ) ;
if ( ! V_138 ) {
V_3 = F_148 ( V_88 , V_138 ) ;
if ( V_3 )
F_139 ( V_3 ) ;
} else {
F_143 ( V_88 , F_320 ( V_138 ) ) ;
}
}
int F_321 ( struct V_168 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_304 ;
F_21 ( L_106 , V_88 ) ;
if ( ! V_3 )
return V_85 ;
return V_3 -> V_84 ;
}
void F_322 ( struct V_168 * V_88 , T_2 V_55 )
{
F_21 ( L_107 , V_88 , V_55 ) ;
F_143 ( V_88 , F_320 ( V_55 ) ) ;
}
static inline void F_323 ( struct V_1 * V_14 , T_2 V_590 )
{
if ( V_14 -> V_86 != V_87 )
return;
if ( V_590 == 0x00 ) {
if ( V_14 -> V_60 == V_144 ) {
F_77 ( V_14 , V_591 ) ;
} else if ( V_14 -> V_60 == V_142 )
F_49 ( V_14 , V_58 ) ;
} else {
if ( V_14 -> V_60 == V_144 )
F_70 ( V_14 ) ;
}
}
int F_324 ( struct V_168 * V_88 , T_2 V_138 , T_2 V_590 )
{
struct V_2 * V_3 = V_88 -> V_304 ;
struct V_1 * V_14 ;
if ( ! V_3 )
return 0 ;
F_21 ( L_108 , V_3 , V_138 , V_590 ) ;
if ( V_88 -> type == V_89 ) {
if ( ! V_138 && V_590 )
F_325 ( V_3 , 0 ) ;
F_242 ( & V_3 -> V_308 ) ;
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
if ( ! V_138 && V_590 ) {
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
F_112 ( V_592 , & F_13 ( V_13 ) -> V_83 ) ;
V_13 -> V_302 ( V_13 ) ;
F_323 ( V_14 , V_590 ) ;
F_50 ( V_14 ) ;
continue;
}
if ( V_14 -> V_23 == V_59 ) {
if ( ! V_138 ) {
F_125 ( V_14 ) ;
} else {
F_77 ( V_14 , V_593 ) ;
}
} else if ( V_14 -> V_23 == V_130 ) {
struct V_26 * V_13 = V_14 -> V_13 ;
struct V_131 V_132 ;
T_5 V_594 , V_595 ;
F_24 ( V_13 ) ;
if ( ! V_138 ) {
if ( F_73 ( V_134 ,
& F_13 ( V_13 ) -> V_83 ) ) {
V_594 = V_279 ;
V_595 = V_280 ;
V_14 -> V_24 -> V_281 ( V_14 ) ;
} else {
F_20 ( V_14 , V_57 ) ;
V_594 = V_282 ;
V_595 = V_139 ;
}
} else {
F_20 ( V_14 , V_137 ) ;
F_77 ( V_14 , V_593 ) ;
V_594 = V_135 ;
V_595 = V_139 ;
}
F_25 ( V_13 ) ;
V_132 . V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_6 = F_16 ( V_14 -> V_7 ) ;
V_132 . V_133 = F_16 ( V_594 ) ;
V_132 . V_138 = F_16 ( V_595 ) ;
F_80 ( V_3 , V_14 -> V_9 , V_140 ,
sizeof( V_132 ) , & V_132 ) ;
if ( ! F_73 ( V_284 , & V_14 -> V_71 ) &&
V_594 == V_282 ) {
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
int F_326 ( struct V_168 * V_88 , struct V_32 * V_36 , T_1 V_83 )
{
struct V_2 * V_3 = V_88 -> V_304 ;
struct V_214 * V_596 ;
int V_155 ;
if ( ! V_3 && V_88 -> V_157 -> V_503 != V_597 )
goto V_580;
if ( ! V_3 )
V_3 = F_148 ( V_88 , 0 ) ;
if ( ! V_3 )
goto V_580;
F_21 ( L_110 , V_3 , V_36 -> V_155 , V_83 ) ;
switch ( V_83 ) {
case V_159 :
case V_158 :
case V_170 :
if ( V_3 -> V_598 ) {
F_286 ( L_111 , V_36 -> V_155 ) ;
F_92 ( V_3 -> V_306 ) ;
V_3 -> V_306 = NULL ;
V_3 -> V_598 = 0 ;
F_141 ( V_3 , V_599 ) ;
}
if ( V_36 -> V_155 < V_211 ) {
F_286 ( L_112 , V_36 -> V_155 ) ;
F_141 ( V_3 , V_599 ) ;
goto V_580;
}
V_596 = (struct V_214 * ) V_36 -> V_156 ;
V_155 = F_67 ( V_596 -> V_155 ) + V_211 ;
if ( V_155 == V_36 -> V_155 ) {
F_315 ( V_3 , V_36 ) ;
return 0 ;
}
F_21 ( L_113 , V_155 , V_36 -> V_155 ) ;
if ( V_36 -> V_155 > V_155 ) {
F_286 ( L_114 ,
V_36 -> V_155 , V_155 ) ;
F_141 ( V_3 , V_599 ) ;
goto V_580;
}
V_3 -> V_306 = F_106 ( V_155 , V_45 ) ;
if ( ! V_3 -> V_306 )
goto V_580;
F_327 ( V_36 , F_108 ( V_3 -> V_306 , V_36 -> V_155 ) ,
V_36 -> V_155 ) ;
V_3 -> V_598 = V_155 - V_36 -> V_155 ;
break;
case V_600 :
F_21 ( L_115 , V_36 -> V_155 , V_3 -> V_598 ) ;
if ( ! V_3 -> V_598 ) {
F_286 ( L_116 , V_36 -> V_155 ) ;
F_141 ( V_3 , V_599 ) ;
goto V_580;
}
if ( V_36 -> V_155 > V_3 -> V_598 ) {
F_286 ( L_117 ,
V_36 -> V_155 , V_3 -> V_598 ) ;
F_92 ( V_3 -> V_306 ) ;
V_3 -> V_306 = NULL ;
V_3 -> V_598 = 0 ;
F_141 ( V_3 , V_599 ) ;
goto V_580;
}
F_327 ( V_36 , F_108 ( V_3 -> V_306 , V_36 -> V_155 ) ,
V_36 -> V_155 ) ;
V_3 -> V_598 -= V_36 -> V_155 ;
if ( ! V_3 -> V_598 ) {
F_315 ( V_3 , V_3 -> V_306 ) ;
V_3 -> V_306 = NULL ;
}
break;
}
V_580:
F_92 ( V_36 ) ;
return 0 ;
}
static int F_328 ( struct V_601 * V_602 , void * V_19 )
{
struct V_1 * V_5 ;
F_134 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
F_329 ( V_602 , L_118 ,
& F_13 ( V_13 ) -> V_11 , & F_13 ( V_13 ) -> V_287 ,
V_5 -> V_23 , F_67 ( V_5 -> V_10 ) ,
V_5 -> V_7 , V_5 -> V_6 , V_5 -> V_98 , V_5 -> V_90 ,
V_5 -> V_60 , V_5 -> V_119 ) ;
}
F_135 ( & V_16 ) ;
return 0 ;
}
static int F_330 ( struct V_603 * V_603 , struct V_604 * V_604 )
{
return F_331 ( V_604 , F_328 , V_603 -> V_605 ) ;
}
int T_11 F_332 ( void )
{
int V_15 ;
V_15 = F_333 () ;
if ( V_15 < 0 )
return V_15 ;
if ( V_606 ) {
V_607 = F_334 ( L_119 , 0444 , V_606 ,
NULL , & V_608 ) ;
if ( ! V_607 )
F_286 ( L_120 ) ;
}
return 0 ;
}
void F_335 ( void )
{
F_336 ( V_607 ) ;
F_337 () ;
}
