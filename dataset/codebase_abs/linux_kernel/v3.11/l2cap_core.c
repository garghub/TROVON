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
if ( V_14 -> V_6 == V_92 )
V_14 -> V_7 = V_92 ;
else
V_14 -> V_7 = F_19 ( V_3 ) ;
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
F_68 ( V_3 -> V_88 ) ;
F_55 ( & V_14 -> V_44 , & V_3 -> V_112 ) ;
}
void F_69 ( struct V_2 * V_3 , struct V_1 * V_14 )
{
F_5 ( & V_3 -> V_8 ) ;
F_66 ( V_3 , V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
}
void F_70 ( struct V_1 * V_14 , int V_15 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
F_71 ( V_14 ) ;
F_21 ( L_6 , V_14 , V_3 , V_15 ) ;
if ( V_3 ) {
struct V_113 * V_114 = V_3 -> V_88 -> V_113 ;
F_60 ( & V_14 -> V_44 ) ;
F_51 ( V_14 ) ;
V_14 -> V_3 = NULL ;
if ( V_14 -> V_86 != V_95 )
F_72 ( V_3 -> V_88 ) ;
if ( V_114 && V_114 -> V_115 == V_14 )
V_114 -> V_115 = NULL ;
}
if ( V_14 -> V_116 ) {
struct V_117 * V_116 = V_14 -> V_116 ;
F_21 ( L_7 , V_14 , V_116 ) ;
F_73 ( V_116 ) ;
}
V_14 -> V_24 -> V_118 ( V_14 , V_15 ) ;
if ( F_74 ( V_70 , & V_14 -> V_71 ) )
return;
switch( V_14 -> V_119 ) {
case V_120 :
break;
case V_121 :
F_33 ( V_14 ) ;
F_75 ( V_14 ) ;
F_76 ( V_14 ) ;
F_77 ( & V_14 -> V_122 ) ;
F_40 ( & V_14 -> V_123 ) ;
F_40 ( & V_14 -> V_124 ) ;
case V_125 :
F_77 ( & V_14 -> V_126 ) ;
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
F_78 ( V_14 , V_13 -> V_129 ) ;
F_79 ( V_14 , V_55 ) ;
} else
F_70 ( V_14 , V_55 ) ;
break;
case V_130 :
if ( V_14 -> V_86 == V_87 &&
V_3 -> V_88 -> type == V_128 ) {
struct V_131 V_132 ;
T_5 V_133 ;
if ( F_74 ( V_134 , & F_13 ( V_13 ) -> V_83 ) )
V_133 = V_135 ;
else
V_133 = V_136 ;
F_23 ( V_14 , V_137 ) ;
V_132 . V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_6 = F_16 ( V_14 -> V_7 ) ;
V_132 . V_133 = F_16 ( V_133 ) ;
V_132 . V_138 = F_80 ( V_139 ) ;
F_81 ( V_3 , V_14 -> V_9 , V_140 ,
sizeof( V_132 ) , & V_132 ) ;
}
F_70 ( V_14 , V_55 ) ;
break;
case V_59 :
case V_137 :
F_70 ( V_14 , V_55 ) ;
break;
default:
V_14 -> V_24 -> V_118 ( V_14 , 0 ) ;
break;
}
}
static inline T_2 F_82 ( struct V_1 * V_14 )
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
} else if ( V_14 -> V_10 == F_80 ( V_147 ) ) {
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
int F_83 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
T_7 V_151 ;
V_151 = F_82 ( V_14 ) ;
return F_84 ( V_3 -> V_88 , V_14 -> V_60 , V_151 ) ;
}
static T_2 F_85 ( struct V_2 * V_3 )
{
T_2 V_152 ;
F_86 ( & V_3 -> V_65 ) ;
if ( ++ V_3 -> V_153 > 128 )
V_3 -> V_153 = 1 ;
V_152 = V_3 -> V_153 ;
F_87 ( & V_3 -> V_65 ) ;
return V_152 ;
}
static void F_81 ( struct V_2 * V_3 , T_2 V_9 , T_2 V_154 , T_1 V_155 ,
void * V_156 )
{
struct V_32 * V_36 = F_88 ( V_3 , V_154 , V_9 , V_155 , V_156 ) ;
T_2 V_83 ;
F_21 ( L_9 , V_154 ) ;
if ( ! V_36 )
return;
if ( F_89 ( V_3 -> V_88 -> V_157 ) )
V_83 = V_158 ;
else
V_83 = V_159 ;
F_36 ( V_36 ) -> V_160 = V_161 ;
V_36 -> V_162 = V_163 ;
F_90 ( V_3 -> V_164 , V_36 , V_83 ) ;
}
static bool F_91 ( struct V_1 * V_14 )
{
return V_14 -> V_165 != V_166 &&
V_14 -> V_165 != V_167 ;
}
static void F_92 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
struct V_168 * V_88 = V_14 -> V_3 -> V_88 ;
T_1 V_83 ;
F_21 ( L_10 , V_14 , V_36 , V_36 -> V_155 ,
V_36 -> V_162 ) ;
if ( V_14 -> V_169 && ! F_91 ( V_14 ) ) {
if ( V_14 -> V_116 )
F_90 ( V_14 -> V_116 , V_36 , V_170 ) ;
else
F_93 ( V_36 ) ;
return;
}
if ( ! F_74 ( V_171 , & V_14 -> V_83 ) &&
F_89 ( V_88 -> V_157 ) )
V_83 = V_158 ;
else
V_83 = V_159 ;
F_36 ( V_36 ) -> V_160 = F_74 ( V_82 , & V_14 -> V_83 ) ;
F_90 ( V_14 -> V_3 -> V_164 , V_36 , V_83 ) ;
}
static void F_94 ( T_1 V_172 , struct V_173 * V_37 )
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
static void F_95 ( T_8 V_193 , struct V_173 * V_37 )
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
static inline void F_96 ( struct V_1 * V_14 ,
struct V_32 * V_36 )
{
if ( F_74 ( V_207 , & V_14 -> V_83 ) ) {
F_95 ( F_97 ( V_36 -> V_156 ) ,
& F_36 ( V_36 ) -> V_37 ) ;
F_98 ( V_36 , V_208 ) ;
} else {
F_94 ( F_99 ( V_36 -> V_156 ) ,
& F_36 ( V_36 ) -> V_37 ) ;
F_98 ( V_36 , V_209 ) ;
}
}
static T_8 F_100 ( struct V_173 * V_37 )
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
static T_1 F_101 ( struct V_173 * V_37 )
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
static inline void F_102 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 )
{
if ( F_74 ( V_207 , & V_14 -> V_83 ) ) {
F_103 ( F_100 ( V_37 ) ,
V_36 -> V_156 + V_211 ) ;
} else {
F_104 ( F_101 ( V_37 ) ,
V_36 -> V_156 + V_211 ) ;
}
}
static inline unsigned int F_105 ( struct V_1 * V_14 )
{
if ( F_74 ( V_207 , & V_14 -> V_83 ) )
return V_212 ;
else
return V_213 ;
}
static struct V_32 * F_106 ( struct V_1 * V_14 ,
T_8 V_37 )
{
struct V_32 * V_36 ;
struct V_214 * V_215 ;
int V_216 = F_105 ( V_14 ) ;
if ( V_14 -> V_73 == V_74 )
V_216 += V_217 ;
V_36 = F_107 ( V_216 , V_45 ) ;
if ( ! V_36 )
return F_108 ( - V_46 ) ;
V_215 = (struct V_214 * ) F_109 ( V_36 , V_211 ) ;
V_215 -> V_155 = F_16 ( V_216 - V_211 ) ;
V_215 -> V_4 = F_16 ( V_14 -> V_6 ) ;
if ( F_74 ( V_207 , & V_14 -> V_83 ) )
F_103 ( V_37 , F_109 ( V_36 , V_208 ) ) ;
else
F_104 ( V_37 , F_109 ( V_36 , V_209 ) ) ;
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_110 ( 0 , ( T_2 * ) V_36 -> V_156 , V_36 -> V_155 ) ;
F_104 ( V_73 , F_109 ( V_36 , V_217 ) ) ;
}
V_36 -> V_162 = V_163 ;
return V_36 ;
}
static void F_111 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
struct V_32 * V_36 ;
T_8 V_218 ;
F_21 ( L_11 , V_14 , V_37 ) ;
if ( ! V_37 -> V_181 )
return;
if ( F_91 ( V_14 ) )
return;
if ( F_112 ( V_219 , & V_14 -> V_220 ) &&
! V_37 -> V_182 )
V_37 -> V_177 = 1 ;
if ( V_37 -> V_185 == V_221 )
F_113 ( V_222 , & V_14 -> V_220 ) ;
else if ( V_37 -> V_185 == V_223 )
F_58 ( V_222 , & V_14 -> V_220 ) ;
if ( V_37 -> V_185 != V_224 ) {
V_14 -> V_225 = V_37 -> V_174 ;
F_76 ( V_14 ) ;
}
F_21 ( L_12 , V_37 -> V_174 ,
V_37 -> V_177 , V_37 -> V_182 , V_37 -> V_185 ) ;
if ( F_74 ( V_207 , & V_14 -> V_83 ) )
V_218 = F_100 ( V_37 ) ;
else
V_218 = F_101 ( V_37 ) ;
V_36 = F_106 ( V_14 , V_218 ) ;
if ( ! F_114 ( V_36 ) )
F_92 ( V_14 , V_36 ) ;
}
static void F_115 ( struct V_1 * V_14 , bool V_182 )
{
struct V_173 V_37 ;
F_21 ( L_13 , V_14 , V_182 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
V_37 . V_182 = V_182 ;
if ( F_74 ( V_226 , & V_14 -> V_220 ) )
V_37 . V_185 = V_223 ;
else
V_37 . V_185 = V_221 ;
V_37 . V_174 = V_14 -> V_227 ;
F_111 ( V_14 , & V_37 ) ;
}
static inline int F_116 ( struct V_1 * V_14 )
{
return ! F_74 ( V_228 , & V_14 -> V_71 ) ;
}
static bool F_117 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
if ( V_229 &&
F_118 () &&
V_14 -> V_230 == V_231 &&
V_3 -> V_232 & V_233 )
return true ;
else
return false ;
}
static bool F_119 ( struct V_1 * V_14 )
{
return true ;
}
void F_120 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_234 V_235 ;
V_235 . V_7 = F_16 ( V_14 -> V_7 ) ;
V_235 . V_10 = V_14 -> V_10 ;
V_14 -> V_9 = F_85 ( V_3 ) ;
F_58 ( V_228 , & V_14 -> V_71 ) ;
F_81 ( V_3 , V_14 -> V_9 , V_236 , sizeof( V_235 ) , & V_235 ) ;
}
static void F_121 ( struct V_1 * V_14 , T_2 V_237 )
{
struct V_238 V_235 ;
V_235 . V_7 = F_16 ( V_14 -> V_7 ) ;
V_235 . V_10 = V_14 -> V_10 ;
V_235 . V_237 = V_237 ;
V_14 -> V_9 = F_85 ( V_14 -> V_3 ) ;
F_81 ( V_14 -> V_3 , V_14 -> V_9 , V_239 ,
sizeof( V_235 ) , & V_235 ) ;
}
static void F_122 ( struct V_1 * V_14 )
{
struct V_32 * V_36 ;
F_21 ( L_3 , V_14 ) ;
if ( V_14 -> V_119 != V_121 )
return;
F_33 ( V_14 ) ;
F_75 ( V_14 ) ;
F_76 ( V_14 ) ;
V_14 -> V_240 = 0 ;
F_35 (&chan->tx_q, skb) {
if ( F_36 ( V_36 ) -> V_37 . V_241 )
F_36 ( V_36 ) -> V_37 . V_241 = 1 ;
else
break;
}
V_14 -> V_242 = V_14 -> V_227 ;
F_113 ( V_243 , & V_14 -> V_220 ) ;
F_113 ( V_244 , & V_14 -> V_220 ) ;
F_45 ( & V_14 -> V_124 ) ;
F_45 ( & V_14 -> V_123 ) ;
F_77 ( & V_14 -> V_122 ) ;
V_14 -> V_245 = V_246 ;
V_14 -> V_247 = V_248 ;
F_58 ( V_249 , & V_14 -> V_220 ) ;
}
static void F_123 ( struct V_1 * V_14 )
{
T_2 V_250 = V_14 -> V_250 ;
F_21 ( L_3 , V_14 ) ;
V_14 -> V_165 = V_166 ;
V_14 -> V_250 = V_251 ;
if ( V_14 -> V_119 != V_121 )
return;
switch ( V_250 ) {
case V_252 :
F_124 ( V_14 , NULL , NULL , V_253 ) ;
V_14 -> V_247 = V_254 ;
break;
case V_255 :
V_14 -> V_247 = V_256 ;
break;
}
}
static void F_125 ( struct V_1 * V_14 )
{
V_14 -> V_71 = 0 ;
F_71 ( V_14 ) ;
V_14 -> V_23 = V_56 ;
V_14 -> V_24 -> V_257 ( V_14 ) ;
}
static void F_126 ( struct V_1 * V_14 )
{
if ( F_117 ( V_14 ) ) {
F_21 ( L_14 , V_14 ) ;
F_127 ( V_14 ) ;
} else {
F_120 ( V_14 ) ;
}
}
static void F_128 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
if ( V_3 -> V_88 -> type == V_89 ) {
F_125 ( V_14 ) ;
return;
}
if ( V_3 -> V_258 & V_259 ) {
if ( ! ( V_3 -> V_258 & V_260 ) )
return;
if ( F_83 ( V_14 ) &&
F_116 ( V_14 ) ) {
F_126 ( V_14 ) ;
}
} else {
struct V_261 V_235 ;
V_235 . type = F_80 ( V_262 ) ;
V_3 -> V_258 |= V_259 ;
V_3 -> V_263 = F_85 ( V_3 ) ;
F_129 ( & V_3 -> V_264 , V_265 ) ;
F_81 ( V_3 , V_3 -> V_263 , V_266 ,
sizeof( V_235 ) , & V_235 ) ;
}
}
static inline int F_130 ( T_7 V_119 , T_9 V_267 )
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
static void F_79 ( struct V_1 * V_14 , int V_15 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_273 V_235 ;
if ( ! V_3 )
return;
if ( V_14 -> V_119 == V_121 && V_14 -> V_23 == V_56 ) {
F_33 ( V_14 ) ;
F_75 ( V_14 ) ;
F_76 ( V_14 ) ;
}
if ( V_14 -> V_86 == V_95 ) {
F_23 ( V_14 , V_137 ) ;
return;
}
V_235 . V_6 = F_16 ( V_14 -> V_6 ) ;
V_235 . V_7 = F_16 ( V_14 -> V_7 ) ;
F_81 ( V_3 , F_85 ( V_3 ) , V_274 ,
sizeof( V_235 ) , & V_235 ) ;
F_24 ( V_13 ) ;
F_20 ( V_14 , V_137 ) ;
F_26 ( V_14 , V_15 ) ;
F_25 ( V_13 ) ;
}
static void F_131 ( struct V_2 * V_3 )
{
struct V_1 * V_14 , * V_275 ;
F_21 ( L_15 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_132 (chan, tmp, &conn->chan_l, list) {
struct V_26 * V_13 = V_14 -> V_13 ;
F_6 ( V_14 ) ;
if ( V_14 -> V_86 != V_87 ) {
F_50 ( V_14 ) ;
continue;
}
if ( V_14 -> V_23 == V_59 ) {
if ( ! F_83 ( V_14 ) ||
! F_116 ( V_14 ) ) {
F_50 ( V_14 ) ;
continue;
}
if ( ! F_130 ( V_14 -> V_119 , V_3 -> V_267 )
&& F_74 ( V_276 ,
& V_14 -> V_71 ) ) {
F_49 ( V_14 , V_277 ) ;
F_50 ( V_14 ) ;
continue;
}
F_126 ( V_14 ) ;
} else if ( V_14 -> V_23 == V_130 ) {
struct V_131 V_132 ;
char V_278 [ 128 ] ;
V_132 . V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_6 = F_16 ( V_14 -> V_7 ) ;
if ( F_83 ( V_14 ) ) {
F_24 ( V_13 ) ;
if ( F_74 ( V_134 ,
& F_13 ( V_13 ) -> V_83 ) ) {
V_132 . V_133 = F_80 ( V_279 ) ;
V_132 . V_138 = F_80 ( V_280 ) ;
V_14 -> V_24 -> V_281 ( V_14 ) ;
} else {
F_20 ( V_14 , V_57 ) ;
V_132 . V_133 = F_80 ( V_282 ) ;
V_132 . V_138 = F_80 ( V_139 ) ;
}
F_25 ( V_13 ) ;
} else {
V_132 . V_133 = F_80 ( V_279 ) ;
V_132 . V_138 = F_80 ( V_283 ) ;
}
F_81 ( V_3 , V_14 -> V_9 , V_140 ,
sizeof( V_132 ) , & V_132 ) ;
if ( F_74 ( V_284 , & V_14 -> V_71 ) ||
V_132 . V_133 != V_282 ) {
F_50 ( V_14 ) ;
continue;
}
F_58 ( V_284 , & V_14 -> V_71 ) ;
F_81 ( V_3 , F_85 ( V_3 ) , V_285 ,
F_133 ( V_14 , V_278 ) , V_278 ) ;
V_14 -> V_286 ++ ;
}
F_50 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static struct V_1 * F_134 ( int V_23 , T_1 V_4 ,
T_4 * V_11 ,
T_4 * V_287 )
{
struct V_1 * V_5 , * V_288 = NULL ;
F_135 ( & V_16 ) ;
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
F_136 ( & V_16 ) ;
return V_5 ;
}
V_291 = ! F_12 ( & F_13 ( V_13 ) -> V_11 , V_293 ) ;
V_292 = ! F_12 ( & F_13 ( V_13 ) -> V_287 , V_293 ) ;
if ( ( V_289 && V_292 ) || ( V_291 && V_290 ) ||
( V_291 && V_292 ) )
V_288 = V_5 ;
}
}
F_136 ( & V_16 ) ;
return V_288 ;
}
static void F_137 ( struct V_2 * V_3 )
{
struct V_26 * V_294 ;
struct V_1 * V_14 , * V_295 ;
F_21 ( L_16 ) ;
V_295 = F_134 ( V_127 , V_92 ,
V_3 -> V_11 , V_3 -> V_287 ) ;
if ( ! V_295 )
return;
if ( F_1 ( V_3 , V_92 ) )
return;
V_294 = V_295 -> V_13 ;
F_24 ( V_294 ) ;
V_14 = V_295 -> V_24 -> V_296 ( V_295 ) ;
if ( ! V_14 )
goto V_297;
V_14 -> V_6 = V_92 ;
F_138 ( & F_13 ( V_14 -> V_13 ) -> V_11 , V_3 -> V_11 ) ;
F_138 ( & F_13 ( V_14 -> V_13 ) -> V_287 , V_3 -> V_287 ) ;
F_66 ( V_3 , V_14 ) ;
V_297:
F_25 ( V_294 ) ;
}
static void F_139 ( struct V_2 * V_3 )
{
struct V_1 * V_14 ;
struct V_168 * V_88 = V_3 -> V_88 ;
F_21 ( L_15 , V_3 ) ;
if ( V_88 -> V_298 && V_88 -> type == V_89 )
F_140 ( V_88 , V_88 -> V_299 ) ;
F_5 ( & V_3 -> V_8 ) ;
if ( V_88 -> type == V_89 )
F_137 ( V_3 ) ;
F_2 (chan, &conn->chan_l, list) {
F_6 ( V_14 ) ;
if ( V_14 -> V_86 == V_95 ) {
F_50 ( V_14 ) ;
continue;
}
if ( V_88 -> type == V_89 ) {
if ( F_140 ( V_88 , V_14 -> V_60 ) )
F_125 ( V_14 ) ;
} else if ( V_14 -> V_86 != V_87 ) {
struct V_26 * V_13 = V_14 -> V_13 ;
F_71 ( V_14 ) ;
F_24 ( V_13 ) ;
F_20 ( V_14 , V_56 ) ;
V_13 -> V_300 ( V_13 ) ;
F_25 ( V_13 ) ;
} else if ( V_14 -> V_23 == V_59 )
F_128 ( V_14 ) ;
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
if ( F_74 ( V_301 , & V_14 -> V_83 ) )
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
F_131 ( V_3 ) ;
}
int F_143 ( struct V_2 * V_3 , struct V_302 * V_303 )
{
struct V_304 * V_157 = V_3 -> V_88 -> V_157 ;
int V_305 ;
F_144 ( V_157 ) ;
if ( V_303 -> V_44 . V_306 || V_303 -> V_44 . V_51 ) {
V_305 = - V_20 ;
goto V_307;
}
if ( ! V_3 -> V_164 ) {
V_305 = - V_308 ;
goto V_307;
}
V_305 = V_303 -> V_309 ( V_3 , V_303 ) ;
if ( V_305 )
goto V_307;
F_55 ( & V_303 -> V_44 , & V_3 -> V_310 ) ;
V_305 = 0 ;
V_307:
F_145 ( V_157 ) ;
return V_305 ;
}
void F_146 ( struct V_2 * V_3 , struct V_302 * V_303 )
{
struct V_304 * V_157 = V_3 -> V_88 -> V_157 ;
F_144 ( V_157 ) ;
if ( ! V_303 -> V_44 . V_306 || ! V_303 -> V_44 . V_51 )
goto V_307;
F_60 ( & V_303 -> V_44 ) ;
V_303 -> V_44 . V_306 = NULL ;
V_303 -> V_44 . V_51 = NULL ;
V_303 -> remove ( V_3 , V_303 ) ;
V_307:
F_145 ( V_157 ) ;
}
static void F_147 ( struct V_2 * V_3 )
{
struct V_302 * V_303 ;
while ( ! F_148 ( & V_3 -> V_310 ) ) {
V_303 = F_149 ( & V_3 -> V_310 , struct V_302 , V_44 ) ;
F_60 ( & V_303 -> V_44 ) ;
V_303 -> V_44 . V_306 = NULL ;
V_303 -> V_44 . V_51 = NULL ;
V_303 -> remove ( V_3 , V_303 ) ;
}
}
static void F_150 ( struct V_168 * V_88 , int V_15 )
{
struct V_2 * V_3 = V_88 -> V_311 ;
struct V_1 * V_14 , * V_312 ;
if ( ! V_3 )
return;
F_21 ( L_17 , V_88 , V_3 , V_15 ) ;
F_93 ( V_3 -> V_313 ) ;
F_147 ( V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_132 (chan, l, &conn->chan_l, list) {
F_61 ( V_14 ) ;
F_6 ( V_14 ) ;
F_70 ( V_14 , V_15 ) ;
F_50 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_51 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
F_151 ( V_3 -> V_164 ) ;
if ( V_3 -> V_258 & V_259 )
F_152 ( & V_3 -> V_264 ) ;
if ( F_112 ( V_314 , & V_88 -> V_83 ) ) {
F_152 ( & V_3 -> V_315 ) ;
F_153 ( V_3 ) ;
}
V_88 -> V_311 = NULL ;
V_3 -> V_164 = NULL ;
F_154 ( V_3 ) ;
}
static void F_155 ( struct V_52 * V_53 )
{
struct V_2 * V_3 = F_48 ( V_53 , struct V_2 ,
V_315 . V_53 ) ;
F_21 ( L_15 , V_3 ) ;
if ( F_112 ( V_314 , & V_3 -> V_88 -> V_83 ) ) {
F_153 ( V_3 ) ;
F_150 ( V_3 -> V_88 , V_62 ) ;
}
}
static struct V_2 * F_156 ( struct V_168 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_311 ;
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
F_57 ( & V_3 -> V_316 ) ;
V_88 -> V_311 = V_3 ;
V_3 -> V_88 = V_88 ;
F_158 ( V_3 -> V_88 ) ;
V_3 -> V_164 = V_164 ;
F_21 ( L_18 , V_88 , V_3 , V_164 ) ;
switch ( V_88 -> type ) {
case V_89 :
if ( V_88 -> V_157 -> V_317 ) {
V_3 -> V_318 = V_88 -> V_157 -> V_317 ;
break;
}
default:
V_3 -> V_318 = V_88 -> V_157 -> V_319 ;
break;
}
V_3 -> V_11 = & V_88 -> V_157 -> V_320 ;
V_3 -> V_287 = & V_88 -> V_287 ;
V_3 -> V_267 = 0 ;
F_159 ( & V_3 -> V_65 ) ;
F_54 ( & V_3 -> V_8 ) ;
F_160 ( & V_3 -> V_112 ) ;
F_160 ( & V_3 -> V_310 ) ;
if ( V_88 -> type == V_89 )
F_56 ( & V_3 -> V_315 , F_155 ) ;
else
F_56 ( & V_3 -> V_264 , F_142 ) ;
V_3 -> V_84 = V_85 ;
return V_3 ;
}
static void F_161 ( struct V_69 * V_316 )
{
struct V_2 * V_3 = F_48 ( V_316 , struct V_2 , V_316 ) ;
F_162 ( V_3 -> V_88 ) ;
F_41 ( V_3 ) ;
}
void F_163 ( struct V_2 * V_3 )
{
F_63 ( & V_3 -> V_316 ) ;
}
void F_154 ( struct V_2 * V_3 )
{
F_64 ( & V_3 -> V_316 , F_161 ) ;
}
static struct V_1 * F_164 ( int V_23 , T_3 V_10 ,
T_4 * V_11 ,
T_4 * V_287 )
{
struct V_1 * V_5 , * V_288 = NULL ;
F_135 ( & V_16 ) ;
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
F_136 ( & V_16 ) ;
return V_5 ;
}
V_291 = ! F_12 ( & F_13 ( V_13 ) -> V_11 , V_293 ) ;
V_292 = ! F_12 ( & F_13 ( V_13 ) -> V_287 , V_293 ) ;
if ( ( V_289 && V_292 ) || ( V_291 && V_290 ) ||
( V_291 && V_292 ) )
V_288 = V_5 ;
}
}
F_136 ( & V_16 ) ;
return V_288 ;
}
int F_165 ( struct V_1 * V_14 , T_3 V_10 , T_1 V_4 ,
T_4 * V_287 , T_2 V_321 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
T_4 * V_11 = & F_13 ( V_13 ) -> V_11 ;
struct V_2 * V_3 ;
struct V_168 * V_88 ;
struct V_304 * V_157 ;
T_7 V_151 ;
int V_15 ;
F_21 ( L_19 , V_11 , V_287 ,
V_321 , F_67 ( V_10 ) ) ;
V_157 = F_166 ( V_287 , V_11 ) ;
if ( ! V_157 )
return - V_322 ;
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
V_15 = - V_323 ;
goto V_18;
}
switch ( V_14 -> V_23 ) {
case V_59 :
case V_130 :
case V_57 :
V_15 = 0 ;
goto V_18;
case V_56 :
V_15 = - V_324 ;
goto V_18;
case V_68 :
case V_325 :
break;
default:
V_15 = - V_326 ;
goto V_18;
}
F_24 ( V_13 ) ;
F_138 ( & F_13 ( V_13 ) -> V_287 , V_287 ) ;
F_25 ( V_13 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_4 ;
V_151 = F_82 ( V_14 ) ;
if ( F_167 ( V_321 ) )
V_88 = F_168 ( V_157 , V_89 , V_287 , V_321 ,
V_14 -> V_60 , V_151 ) ;
else
V_88 = F_168 ( V_157 , V_128 , V_287 , V_321 ,
V_14 -> V_60 , V_151 ) ;
if ( F_114 ( V_88 ) ) {
V_15 = F_169 ( V_88 ) ;
goto V_18;
}
V_3 = F_156 ( V_88 ) ;
if ( ! V_3 ) {
F_72 ( V_88 ) ;
V_15 = - V_46 ;
goto V_18;
}
if ( V_4 && F_1 ( V_3 , V_4 ) ) {
F_72 ( V_88 ) ;
V_15 = - V_327 ;
goto V_18;
}
F_138 ( V_11 , V_3 -> V_11 ) ;
F_50 ( V_14 ) ;
F_69 ( V_3 , V_14 ) ;
F_6 ( V_14 ) ;
F_72 ( V_88 ) ;
F_23 ( V_14 , V_59 ) ;
F_78 ( V_14 , V_13 -> V_129 ) ;
if ( V_88 -> V_23 == V_56 ) {
if ( V_14 -> V_86 != V_87 ) {
F_71 ( V_14 ) ;
if ( F_83 ( V_14 ) )
F_23 ( V_14 , V_56 ) ;
} else
F_128 ( V_14 ) ;
}
V_15 = 0 ;
V_18:
F_50 ( V_14 ) ;
F_145 ( V_157 ) ;
F_170 ( V_157 ) ;
return V_15 ;
}
int F_171 ( struct V_26 * V_13 )
{
struct V_1 * V_14 = F_172 ( V_13 ) -> V_14 ;
F_173 ( V_328 , V_329 ) ;
int V_15 = 0 ;
int V_330 = V_331 / 5 ;
F_174 ( F_175 ( V_13 ) , & V_328 ) ;
F_176 ( V_332 ) ;
while ( V_14 -> V_333 > 0 && V_14 -> V_3 ) {
if ( ! V_330 )
V_330 = V_331 / 5 ;
if ( F_177 ( V_329 ) ) {
V_15 = F_178 ( V_330 ) ;
break;
}
F_25 ( V_13 ) ;
V_330 = F_179 ( V_330 ) ;
F_24 ( V_13 ) ;
F_176 ( V_332 ) ;
V_15 = F_180 ( V_13 ) ;
if ( V_15 )
break;
}
F_176 ( V_334 ) ;
F_181 ( F_175 ( V_13 ) , & V_328 ) ;
return V_15 ;
}
static void F_182 ( struct V_52 * V_53 )
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
F_124 ( V_14 , NULL , NULL , V_335 ) ;
F_50 ( V_14 ) ;
F_51 ( V_14 ) ;
}
static void F_183 ( struct V_52 * V_53 )
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
F_124 ( V_14 , NULL , NULL , V_336 ) ;
F_50 ( V_14 ) ;
F_51 ( V_14 ) ;
}
static void F_184 ( struct V_1 * V_14 ,
struct V_33 * V_337 )
{
struct V_32 * V_36 ;
struct V_173 * V_37 ;
F_21 ( L_20 , V_14 , V_337 ) ;
if ( F_91 ( V_14 ) )
return;
F_185 ( V_337 , & V_14 -> V_126 ) ;
while ( ! F_186 ( & V_14 -> V_126 ) ) {
V_36 = F_187 ( & V_14 -> V_126 ) ;
F_36 ( V_36 ) -> V_37 . V_241 = 1 ;
V_37 = & F_36 ( V_36 ) -> V_37 ;
V_37 -> V_174 = 0 ;
V_37 -> V_38 = V_14 -> V_338 ;
F_102 ( V_14 , V_37 , V_36 ) ;
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_110 ( 0 , ( T_2 * ) V_36 -> V_156 , V_36 -> V_155 ) ;
F_104 ( V_73 , F_109 ( V_36 , V_217 ) ) ;
}
F_92 ( V_14 , V_36 ) ;
F_21 ( L_21 , V_37 -> V_38 ) ;
V_14 -> V_338 = F_188 ( V_14 , V_14 -> V_338 ) ;
V_14 -> V_339 ++ ;
}
}
static int F_189 ( struct V_1 * V_14 )
{
struct V_32 * V_36 , * V_340 ;
struct V_173 * V_37 ;
int V_341 = 0 ;
F_21 ( L_3 , V_14 ) ;
if ( V_14 -> V_23 != V_56 )
return - V_342 ;
if ( F_74 ( V_249 , & V_14 -> V_220 ) )
return 0 ;
if ( F_91 ( V_14 ) )
return 0 ;
while ( V_14 -> V_343 &&
V_14 -> V_333 < V_14 -> V_344 &&
V_14 -> V_245 == V_246 ) {
V_36 = V_14 -> V_343 ;
F_36 ( V_36 ) -> V_37 . V_241 = 1 ;
V_37 = & F_36 ( V_36 ) -> V_37 ;
if ( F_112 ( V_219 , & V_14 -> V_220 ) )
V_37 -> V_177 = 1 ;
V_37 -> V_174 = V_14 -> V_227 ;
V_14 -> V_225 = V_14 -> V_227 ;
V_37 -> V_38 = V_14 -> V_338 ;
F_102 ( V_14 , V_37 , V_36 ) ;
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_110 ( 0 , ( T_2 * ) V_36 -> V_156 , V_36 -> V_155 ) ;
F_104 ( V_73 , F_109 ( V_36 , V_217 ) ) ;
}
V_340 = F_190 ( V_36 , V_45 ) ;
if ( ! V_340 )
break;
F_28 ( V_14 ) ;
V_14 -> V_338 = F_188 ( V_14 , V_14 -> V_338 ) ;
V_14 -> V_333 ++ ;
V_14 -> V_339 ++ ;
V_341 ++ ;
if ( F_191 ( & V_14 -> V_126 , V_36 ) )
V_14 -> V_343 = NULL ;
else
V_14 -> V_343 = F_192 ( & V_14 -> V_126 , V_36 ) ;
F_92 ( V_14 , V_340 ) ;
F_21 ( L_21 , V_37 -> V_38 ) ;
}
F_21 ( L_22 , V_341 ,
V_14 -> V_333 , F_193 ( & V_14 -> V_126 ) ) ;
return V_341 ;
}
static void F_194 ( struct V_1 * V_14 )
{
struct V_173 V_37 ;
struct V_32 * V_36 ;
struct V_32 * V_340 ;
T_1 V_35 ;
F_21 ( L_3 , V_14 ) ;
if ( F_74 ( V_249 , & V_14 -> V_220 ) )
return;
if ( F_91 ( V_14 ) )
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
F_79 ( V_14 , V_277 ) ;
F_45 ( & V_14 -> V_124 ) ;
break;
}
V_37 . V_174 = V_14 -> V_227 ;
if ( F_112 ( V_219 , & V_14 -> V_220 ) )
V_37 . V_177 = 1 ;
else
V_37 . V_177 = 0 ;
if ( F_195 ( V_36 ) ) {
V_340 = F_196 ( V_36 , V_45 ) ;
} else {
V_340 = F_190 ( V_36 , V_45 ) ;
}
if ( ! V_340 ) {
F_45 ( & V_14 -> V_124 ) ;
break;
}
if ( F_74 ( V_207 , & V_14 -> V_83 ) ) {
F_103 ( F_100 ( & V_37 ) ,
V_340 -> V_156 + V_211 ) ;
} else {
F_104 ( F_101 ( & V_37 ) ,
V_340 -> V_156 + V_211 ) ;
}
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_110 ( 0 , ( T_2 * ) V_340 -> V_156 , V_340 -> V_155 ) ;
F_104 ( V_73 , F_109 ( V_340 ,
V_217 ) ) ;
}
F_92 ( V_14 , V_340 ) ;
F_21 ( L_25 , V_37 . V_38 ) ;
V_14 -> V_225 = V_14 -> V_227 ;
}
}
static void F_197 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
F_21 ( L_11 , V_14 , V_37 ) ;
F_46 ( & V_14 -> V_124 , V_37 -> V_174 ) ;
F_194 ( V_14 ) ;
}
static void F_198 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
struct V_32 * V_36 ;
F_21 ( L_11 , V_14 , V_37 ) ;
if ( V_37 -> V_182 )
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_45 ( & V_14 -> V_124 ) ;
if ( F_74 ( V_249 , & V_14 -> V_220 ) )
return;
if ( V_14 -> V_333 ) {
F_35 (&chan->tx_q, skb) {
if ( F_36 ( V_36 ) -> V_37 . V_38 == V_37 -> V_174 ||
V_36 == V_14 -> V_343 )
break;
}
F_199 (&chan->tx_q, skb) {
if ( V_36 == V_14 -> V_343 )
break;
F_46 ( & V_14 -> V_124 ,
F_36 ( V_36 ) -> V_37 . V_38 ) ;
}
F_194 ( V_14 ) ;
}
}
static void F_200 ( struct V_1 * V_14 )
{
struct V_173 V_37 ;
T_1 V_345 = F_201 ( V_14 , V_14 -> V_227 ,
V_14 -> V_225 ) ;
int V_346 ;
F_21 ( L_26 ,
V_14 , V_14 -> V_225 , V_14 -> V_227 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
if ( F_74 ( V_226 , & V_14 -> V_220 ) &&
V_14 -> V_247 == V_347 ) {
F_76 ( V_14 ) ;
V_37 . V_185 = V_223 ;
V_37 . V_174 = V_14 -> V_227 ;
F_111 ( V_14 , & V_37 ) ;
} else {
if ( ! F_74 ( V_249 , & V_14 -> V_220 ) ) {
F_189 ( V_14 ) ;
if ( V_14 -> V_227 == V_14 -> V_225 )
V_345 = 0 ;
}
V_346 = V_14 -> V_80 ;
V_346 += V_346 << 1 ;
V_346 >>= 2 ;
F_21 ( L_27 , V_345 ,
V_346 ) ;
if ( V_345 >= V_346 ) {
F_76 ( V_14 ) ;
V_37 . V_185 = V_221 ;
V_37 . V_174 = V_14 -> V_227 ;
F_111 ( V_14 , & V_37 ) ;
V_345 = 0 ;
}
if ( V_345 )
F_202 ( V_14 ) ;
}
}
static inline int F_203 ( struct V_1 * V_14 ,
struct V_348 * V_349 , int V_155 ,
int V_350 , struct V_32 * V_36 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * * V_351 ;
int V_341 = 0 ;
if ( F_204 ( F_109 ( V_36 , V_350 ) , V_349 -> V_352 , V_350 ) )
return - V_353 ;
V_341 += V_350 ;
V_155 -= V_350 ;
V_351 = & F_205 ( V_36 ) -> V_354 ;
while ( V_155 ) {
struct V_32 * V_275 ;
V_350 = F_206 (unsigned int, conn->mtu, len) ;
V_275 = V_14 -> V_24 -> V_355 ( V_14 , V_350 ,
V_349 -> V_356 & V_357 ) ;
if ( F_114 ( V_275 ) )
return F_169 ( V_275 ) ;
* V_351 = V_275 ;
if ( F_204 ( F_109 ( * V_351 , V_350 ) , V_349 -> V_352 , V_350 ) )
return - V_353 ;
( * V_351 ) -> V_162 = V_36 -> V_162 ;
V_341 += V_350 ;
V_155 -= V_350 ;
V_36 -> V_155 += ( * V_351 ) -> V_155 ;
V_36 -> V_358 += ( * V_351 ) -> V_155 ;
V_351 = & ( * V_351 ) -> V_306 ;
}
return V_341 ;
}
static struct V_32 * F_207 ( struct V_1 * V_14 ,
struct V_348 * V_349 , T_6 V_155 ,
T_8 V_162 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_350 , V_216 = V_211 + V_359 ;
struct V_214 * V_215 ;
F_21 ( L_28 , V_14 , V_155 , V_162 ) ;
V_350 = F_206 (unsigned int, (conn->mtu - hlen), len) ;
V_36 = V_14 -> V_24 -> V_355 ( V_14 , V_350 + V_216 ,
V_349 -> V_356 & V_357 ) ;
if ( F_114 ( V_36 ) )
return V_36 ;
V_36 -> V_162 = V_162 ;
V_215 = (struct V_214 * ) F_109 ( V_36 , V_211 ) ;
V_215 -> V_4 = F_16 ( V_14 -> V_6 ) ;
V_215 -> V_155 = F_16 ( V_155 + V_359 ) ;
F_208 ( V_14 -> V_10 , F_109 ( V_36 , V_359 ) ) ;
V_15 = F_203 ( V_14 , V_349 , V_155 , V_350 , V_36 ) ;
if ( F_209 ( V_15 < 0 ) ) {
F_93 ( V_36 ) ;
return F_108 ( V_15 ) ;
}
return V_36 ;
}
static struct V_32 * F_210 ( struct V_1 * V_14 ,
struct V_348 * V_349 , T_6 V_155 ,
T_8 V_162 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_350 ;
struct V_214 * V_215 ;
F_21 ( L_29 , V_14 , V_155 ) ;
V_350 = F_206 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_36 = V_14 -> V_24 -> V_355 ( V_14 , V_350 + V_211 ,
V_349 -> V_356 & V_357 ) ;
if ( F_114 ( V_36 ) )
return V_36 ;
V_36 -> V_162 = V_162 ;
V_215 = (struct V_214 * ) F_109 ( V_36 , V_211 ) ;
V_215 -> V_4 = F_16 ( V_14 -> V_6 ) ;
V_215 -> V_155 = F_16 ( V_155 ) ;
V_15 = F_203 ( V_14 , V_349 , V_155 , V_350 , V_36 ) ;
if ( F_209 ( V_15 < 0 ) ) {
F_93 ( V_36 ) ;
return F_108 ( V_15 ) ;
}
return V_36 ;
}
static struct V_32 * F_211 ( struct V_1 * V_14 ,
struct V_348 * V_349 , T_6 V_155 ,
T_1 V_360 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_350 , V_216 ;
struct V_214 * V_215 ;
F_21 ( L_29 , V_14 , V_155 ) ;
if ( ! V_3 )
return F_108 ( - V_342 ) ;
V_216 = F_105 ( V_14 ) ;
if ( V_360 )
V_216 += V_361 ;
if ( V_14 -> V_73 == V_74 )
V_216 += V_217 ;
V_350 = F_206 (unsigned int, (conn->mtu - hlen), len) ;
V_36 = V_14 -> V_24 -> V_355 ( V_14 , V_350 + V_216 ,
V_349 -> V_356 & V_357 ) ;
if ( F_114 ( V_36 ) )
return V_36 ;
V_215 = (struct V_214 * ) F_109 ( V_36 , V_211 ) ;
V_215 -> V_4 = F_16 ( V_14 -> V_6 ) ;
V_215 -> V_155 = F_16 ( V_155 + ( V_216 - V_211 ) ) ;
if ( F_74 ( V_207 , & V_14 -> V_83 ) )
F_103 ( 0 , F_109 ( V_36 , V_208 ) ) ;
else
F_104 ( 0 , F_109 ( V_36 , V_209 ) ) ;
if ( V_360 )
F_104 ( V_360 , F_109 ( V_36 , V_361 ) ) ;
V_15 = F_203 ( V_14 , V_349 , V_155 , V_350 , V_36 ) ;
if ( F_209 ( V_15 < 0 ) ) {
F_93 ( V_36 ) ;
return F_108 ( V_15 ) ;
}
F_36 ( V_36 ) -> V_37 . V_73 = V_14 -> V_73 ;
F_36 ( V_36 ) -> V_37 . V_241 = 0 ;
return V_36 ;
}
static int F_212 ( struct V_1 * V_14 ,
struct V_33 * V_362 ,
struct V_348 * V_349 , T_6 V_155 )
{
struct V_32 * V_36 ;
T_1 V_363 ;
T_6 V_364 ;
T_2 V_188 ;
F_21 ( L_30 , V_14 , V_349 , V_155 ) ;
V_364 = V_14 -> V_3 -> V_318 ;
if ( ! V_14 -> V_169 )
V_364 = F_206 ( T_6 , V_364 , V_365 ) ;
if ( V_14 -> V_73 )
V_364 -= V_217 ;
V_364 -= F_105 ( V_14 ) ;
V_364 = F_206 ( T_6 , V_364 , V_14 -> V_366 ) ;
if ( V_155 <= V_364 ) {
V_188 = V_367 ;
V_363 = 0 ;
V_364 = V_155 ;
} else {
V_188 = V_368 ;
V_363 = V_155 ;
V_364 -= V_361 ;
}
while ( V_155 > 0 ) {
V_36 = F_211 ( V_14 , V_349 , V_364 , V_363 ) ;
if ( F_114 ( V_36 ) ) {
F_213 ( V_362 ) ;
return F_169 ( V_36 ) ;
}
F_36 ( V_36 ) -> V_37 . V_188 = V_188 ;
F_214 ( V_362 , V_36 ) ;
V_155 -= V_364 ;
if ( V_363 ) {
V_363 = 0 ;
V_364 += V_361 ;
}
if ( V_155 <= V_364 ) {
V_188 = V_369 ;
V_364 = V_155 ;
} else {
V_188 = V_370 ;
}
}
return 0 ;
}
int F_215 ( struct V_1 * V_14 , struct V_348 * V_349 , T_6 V_155 ,
T_8 V_162 )
{
struct V_32 * V_36 ;
int V_15 ;
struct V_33 V_362 ;
if ( V_14 -> V_86 == V_93 ) {
V_36 = F_207 ( V_14 , V_349 , V_155 , V_162 ) ;
if ( F_114 ( V_36 ) )
return F_169 ( V_36 ) ;
F_92 ( V_14 , V_36 ) ;
return V_155 ;
}
switch ( V_14 -> V_119 ) {
case V_120 :
if ( V_155 > V_14 -> V_90 )
return - V_371 ;
V_36 = F_210 ( V_14 , V_349 , V_155 , V_162 ) ;
if ( F_114 ( V_36 ) )
return F_169 ( V_36 ) ;
F_92 ( V_14 , V_36 ) ;
V_15 = V_155 ;
break;
case V_121 :
case V_125 :
if ( V_155 > V_14 -> V_90 ) {
V_15 = - V_371 ;
break;
}
F_216 ( & V_362 ) ;
V_15 = F_212 ( V_14 , & V_362 , V_349 , V_155 ) ;
if ( V_14 -> V_23 != V_56 ) {
F_213 ( & V_362 ) ;
V_15 = - V_342 ;
}
if ( V_15 )
break;
if ( V_14 -> V_119 == V_121 )
F_124 ( V_14 , NULL , & V_362 , V_372 ) ;
else
F_184 ( V_14 , & V_362 ) ;
V_15 = V_155 ;
F_213 ( & V_362 ) ;
break;
default:
F_21 ( L_31 , V_14 -> V_119 ) ;
V_15 = - V_326 ;
}
return V_15 ;
}
static void F_217 ( struct V_1 * V_14 , T_1 V_38 )
{
struct V_173 V_37 ;
T_1 V_35 ;
F_21 ( L_32 , V_14 , V_38 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
V_37 . V_185 = V_224 ;
for ( V_35 = V_14 -> V_242 ; V_35 != V_38 ;
V_35 = F_188 ( V_14 , V_35 ) ) {
if ( ! F_34 ( & V_14 -> V_122 , V_35 ) ) {
V_37 . V_174 = V_35 ;
F_111 ( V_14 , & V_37 ) ;
F_46 ( & V_14 -> V_123 , V_35 ) ;
}
}
V_14 -> V_242 = F_188 ( V_14 , V_38 ) ;
}
static void F_218 ( struct V_1 * V_14 )
{
struct V_173 V_37 ;
F_21 ( L_3 , V_14 ) ;
if ( V_14 -> V_123 . V_49 == V_48 )
return;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
V_37 . V_185 = V_224 ;
V_37 . V_174 = V_14 -> V_123 . V_49 ;
F_111 ( V_14 , & V_37 ) ;
}
static void F_219 ( struct V_1 * V_14 , T_1 V_38 )
{
struct V_173 V_37 ;
T_1 V_373 ;
T_1 V_35 ;
F_21 ( L_32 , V_14 , V_38 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
V_37 . V_185 = V_224 ;
V_373 = V_14 -> V_123 . V_34 ;
do {
V_35 = F_44 ( & V_14 -> V_123 ) ;
if ( V_35 == V_38 || V_35 == V_48 )
break;
V_37 . V_174 = V_35 ;
F_111 ( V_14 , & V_37 ) ;
F_46 ( & V_14 -> V_123 , V_35 ) ;
} while ( V_14 -> V_123 . V_34 != V_373 );
}
static void F_220 ( struct V_1 * V_14 , T_1 V_174 )
{
struct V_32 * V_374 ;
T_1 V_375 ;
F_21 ( L_33 , V_14 , V_174 ) ;
if ( V_14 -> V_333 == 0 || V_174 == V_14 -> V_376 )
return;
F_21 ( L_34 ,
V_14 -> V_376 , V_14 -> V_333 ) ;
for ( V_375 = V_14 -> V_376 ; V_375 != V_174 ;
V_375 = F_188 ( V_14 , V_375 ) ) {
V_374 = F_34 ( & V_14 -> V_126 , V_375 ) ;
if ( V_374 ) {
F_221 ( V_374 , & V_14 -> V_126 ) ;
F_93 ( V_374 ) ;
V_14 -> V_333 -- ;
}
}
V_14 -> V_376 = V_174 ;
if ( V_14 -> V_333 == 0 )
F_33 ( V_14 ) ;
F_21 ( L_35 , V_14 -> V_333 ) ;
}
static void F_222 ( struct V_1 * V_14 )
{
F_21 ( L_3 , V_14 ) ;
V_14 -> V_242 = V_14 -> V_227 ;
F_45 ( & V_14 -> V_123 ) ;
F_77 ( & V_14 -> V_122 ) ;
V_14 -> V_247 = V_347 ;
}
static void F_223 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_33 * V_337 , T_2 V_377 )
{
F_21 ( L_36 , V_14 , V_37 , V_337 ,
V_377 ) ;
switch ( V_377 ) {
case V_372 :
if ( V_14 -> V_343 == NULL )
V_14 -> V_343 = F_224 ( V_337 ) ;
F_185 ( V_337 , & V_14 -> V_126 ) ;
F_189 ( V_14 ) ;
break;
case V_378 :
F_21 ( L_37 ) ;
F_58 ( V_226 , & V_14 -> V_220 ) ;
if ( V_14 -> V_247 == V_379 ) {
F_222 ( V_14 ) ;
}
F_200 ( V_14 ) ;
break;
case V_380 :
F_21 ( L_38 ) ;
F_113 ( V_226 , & V_14 -> V_220 ) ;
if ( F_74 ( V_222 , & V_14 -> V_220 ) ) {
struct V_173 V_381 ;
memset ( & V_381 , 0 , sizeof( V_381 ) ) ;
V_381 . V_181 = 1 ;
V_381 . V_185 = V_221 ;
V_381 . V_182 = 1 ;
V_381 . V_174 = V_14 -> V_227 ;
F_111 ( V_14 , & V_381 ) ;
V_14 -> V_240 = 1 ;
F_32 ( V_14 ) ;
V_14 -> V_245 = V_382 ;
}
break;
case V_383 :
F_220 ( V_14 , V_37 -> V_174 ) ;
break;
case V_253 :
F_115 ( V_14 , 1 ) ;
V_14 -> V_240 = 1 ;
F_32 ( V_14 ) ;
F_76 ( V_14 ) ;
V_14 -> V_245 = V_382 ;
break;
case V_336 :
F_115 ( V_14 , 1 ) ;
V_14 -> V_240 = 1 ;
F_32 ( V_14 ) ;
V_14 -> V_245 = V_382 ;
break;
case V_384 :
break;
default:
break;
}
}
static void F_225 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_33 * V_337 , T_2 V_377 )
{
F_21 ( L_36 , V_14 , V_37 , V_337 ,
V_377 ) ;
switch ( V_377 ) {
case V_372 :
if ( V_14 -> V_343 == NULL )
V_14 -> V_343 = F_224 ( V_337 ) ;
F_185 ( V_337 , & V_14 -> V_126 ) ;
break;
case V_378 :
F_21 ( L_37 ) ;
F_58 ( V_226 , & V_14 -> V_220 ) ;
if ( V_14 -> V_247 == V_379 ) {
F_222 ( V_14 ) ;
}
F_200 ( V_14 ) ;
break;
case V_380 :
F_21 ( L_38 ) ;
F_113 ( V_226 , & V_14 -> V_220 ) ;
if ( F_74 ( V_222 , & V_14 -> V_220 ) ) {
struct V_173 V_381 ;
memset ( & V_381 , 0 , sizeof( V_381 ) ) ;
V_381 . V_181 = 1 ;
V_381 . V_185 = V_221 ;
V_381 . V_182 = 1 ;
V_381 . V_174 = V_14 -> V_227 ;
F_111 ( V_14 , & V_381 ) ;
V_14 -> V_240 = 1 ;
F_32 ( V_14 ) ;
V_14 -> V_245 = V_382 ;
}
break;
case V_383 :
F_220 ( V_14 , V_37 -> V_174 ) ;
case V_384 :
if ( V_37 && V_37 -> V_177 ) {
F_75 ( V_14 ) ;
if ( V_14 -> V_333 > 0 )
F_28 ( V_14 ) ;
V_14 -> V_240 = 0 ;
V_14 -> V_245 = V_246 ;
F_21 ( L_39 , V_14 -> V_245 ) ;
}
break;
case V_253 :
break;
case V_335 :
if ( V_14 -> V_75 == 0 || V_14 -> V_240 < V_14 -> V_75 ) {
F_115 ( V_14 , 1 ) ;
F_32 ( V_14 ) ;
V_14 -> V_240 ++ ;
} else {
F_79 ( V_14 , V_385 ) ;
}
break;
default:
break;
}
}
static void F_124 ( struct V_1 * V_14 , struct V_173 * V_37 ,
struct V_33 * V_337 , T_2 V_377 )
{
F_21 ( L_40 ,
V_14 , V_37 , V_337 , V_377 , V_14 -> V_245 ) ;
switch ( V_14 -> V_245 ) {
case V_246 :
F_223 ( V_14 , V_37 , V_337 , V_377 ) ;
break;
case V_382 :
F_225 ( V_14 , V_37 , V_337 , V_377 ) ;
break;
default:
break;
}
}
static void F_226 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
F_21 ( L_11 , V_14 , V_37 ) ;
F_124 ( V_14 , V_37 , NULL , V_383 ) ;
}
static void F_227 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
F_21 ( L_11 , V_14 , V_37 ) ;
F_124 ( V_14 , V_37 , NULL , V_384 ) ;
}
static void F_228 ( struct V_2 * V_3 , struct V_32 * V_36 )
{
struct V_32 * V_386 ;
struct V_1 * V_14 ;
F_21 ( L_15 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
struct V_26 * V_13 = V_14 -> V_13 ;
if ( V_14 -> V_86 != V_141 )
continue;
if ( V_36 -> V_13 == V_13 )
continue;
V_386 = F_190 ( V_36 , V_45 ) ;
if ( ! V_386 )
continue;
if ( V_14 -> V_24 -> V_387 ( V_14 , V_386 ) )
F_93 ( V_386 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static struct V_32 * F_88 ( struct V_2 * V_3 , T_2 V_154 ,
T_2 V_9 , T_1 V_388 , void * V_156 )
{
struct V_32 * V_36 , * * V_351 ;
struct V_389 * V_390 ;
struct V_214 * V_215 ;
int V_155 , V_350 ;
F_21 ( L_41 ,
V_3 , V_154 , V_9 , V_388 ) ;
if ( V_3 -> V_318 < V_211 + V_391 )
return NULL ;
V_155 = V_211 + V_391 + V_388 ;
V_350 = F_206 (unsigned int, conn->mtu, len) ;
V_36 = F_107 ( V_350 , V_45 ) ;
if ( ! V_36 )
return NULL ;
V_215 = (struct V_214 * ) F_109 ( V_36 , V_211 ) ;
V_215 -> V_155 = F_16 ( V_391 + V_388 ) ;
if ( V_3 -> V_88 -> type == V_89 )
V_215 -> V_4 = F_80 ( V_392 ) ;
else
V_215 -> V_4 = F_80 ( V_99 ) ;
V_390 = (struct V_389 * ) F_109 ( V_36 , V_391 ) ;
V_390 -> V_154 = V_154 ;
V_390 -> V_9 = V_9 ;
V_390 -> V_155 = F_16 ( V_388 ) ;
if ( V_388 ) {
V_350 -= V_211 + V_391 ;
memcpy ( F_109 ( V_36 , V_350 ) , V_156 , V_350 ) ;
V_156 += V_350 ;
}
V_155 -= V_36 -> V_155 ;
V_351 = & F_205 ( V_36 ) -> V_354 ;
while ( V_155 ) {
V_350 = F_206 (unsigned int, conn->mtu, len) ;
* V_351 = F_107 ( V_350 , V_45 ) ;
if ( ! * V_351 )
goto V_393;
memcpy ( F_109 ( * V_351 , V_350 ) , V_156 , V_350 ) ;
V_155 -= V_350 ;
V_156 += V_350 ;
V_351 = & ( * V_351 ) -> V_306 ;
}
return V_36 ;
V_393:
F_93 ( V_36 ) ;
return NULL ;
}
static inline int F_229 ( void * * V_394 , int * type , int * V_395 ,
unsigned long * V_396 )
{
struct V_397 * V_398 = * V_394 ;
int V_155 ;
V_155 = V_399 + V_398 -> V_155 ;
* V_394 += V_155 ;
* type = V_398 -> type ;
* V_395 = V_398 -> V_155 ;
switch ( V_398 -> V_155 ) {
case 1 :
* V_396 = * ( ( T_2 * ) V_398 -> V_396 ) ;
break;
case 2 :
* V_396 = F_99 ( V_398 -> V_396 ) ;
break;
case 4 :
* V_396 = F_97 ( V_398 -> V_396 ) ;
break;
default:
* V_396 = ( unsigned long ) V_398 -> V_396 ;
break;
}
F_21 ( L_42 , * type , V_398 -> V_155 , * V_396 ) ;
return V_155 ;
}
static void F_230 ( void * * V_394 , T_2 type , T_2 V_155 , unsigned long V_396 )
{
struct V_397 * V_398 = * V_394 ;
F_21 ( L_42 , type , V_155 , V_396 ) ;
V_398 -> type = type ;
V_398 -> V_155 = V_155 ;
switch ( V_155 ) {
case 1 :
* ( ( T_2 * ) V_398 -> V_396 ) = V_396 ;
break;
case 2 :
F_104 ( V_396 , V_398 -> V_396 ) ;
break;
case 4 :
F_103 ( V_396 , V_398 -> V_396 ) ;
break;
default:
memcpy ( V_398 -> V_396 , ( void * ) V_396 , V_155 ) ;
break;
}
* V_394 += V_399 + V_155 ;
}
static void F_231 ( void * * V_394 , struct V_1 * V_14 )
{
struct V_400 V_401 ;
switch ( V_14 -> V_119 ) {
case V_121 :
V_401 . V_152 = V_14 -> V_100 ;
V_401 . V_402 = V_14 -> V_102 ;
V_401 . V_403 = F_16 ( V_14 -> V_104 ) ;
V_401 . V_404 = F_232 ( V_14 -> V_106 ) ;
V_401 . V_405 = F_233 ( V_109 ) ;
V_401 . V_406 = F_233 ( V_111 ) ;
break;
case V_125 :
V_401 . V_152 = 1 ;
V_401 . V_402 = V_103 ;
V_401 . V_403 = F_16 ( V_14 -> V_104 ) ;
V_401 . V_404 = F_232 ( V_14 -> V_106 ) ;
V_401 . V_405 = 0 ;
V_401 . V_406 = 0 ;
break;
default:
return;
}
F_230 ( V_394 , V_407 , sizeof( V_401 ) ,
( unsigned long ) & V_401 ) ;
}
static void F_234 ( struct V_52 * V_53 )
{
struct V_1 * V_14 = F_48 ( V_53 , struct V_1 ,
V_408 . V_53 ) ;
T_1 V_345 ;
F_21 ( L_3 , V_14 ) ;
F_6 ( V_14 ) ;
V_345 = F_201 ( V_14 , V_14 -> V_227 ,
V_14 -> V_225 ) ;
if ( V_345 )
F_115 ( V_14 , 0 ) ;
F_50 ( V_14 ) ;
F_51 ( V_14 ) ;
}
int F_235 ( struct V_1 * V_14 )
{
int V_15 ;
V_14 -> V_338 = 0 ;
V_14 -> V_242 = 0 ;
V_14 -> V_376 = 0 ;
V_14 -> V_333 = 0 ;
V_14 -> V_227 = 0 ;
V_14 -> V_339 = 0 ;
V_14 -> V_225 = 0 ;
V_14 -> V_409 = NULL ;
V_14 -> V_410 = NULL ;
V_14 -> V_363 = 0 ;
F_236 ( & V_14 -> V_126 ) ;
V_14 -> V_411 = 0 ;
V_14 -> V_412 = 0 ;
V_14 -> V_165 = V_166 ;
V_14 -> V_250 = V_251 ;
if ( V_14 -> V_119 != V_121 )
return 0 ;
V_14 -> V_247 = V_347 ;
V_14 -> V_245 = V_246 ;
F_56 ( & V_14 -> V_30 , F_183 ) ;
F_56 ( & V_14 -> V_28 , F_182 ) ;
F_56 ( & V_14 -> V_408 , F_234 ) ;
F_236 ( & V_14 -> V_122 ) ;
V_15 = F_37 ( & V_14 -> V_123 , V_14 -> V_77 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_37 ( & V_14 -> V_124 , V_14 -> V_344 ) ;
if ( V_15 < 0 )
F_40 ( & V_14 -> V_123 ) ;
return V_15 ;
}
static inline T_7 F_237 ( T_7 V_119 , T_5 V_413 )
{
switch ( V_119 ) {
case V_125 :
case V_121 :
if ( F_130 ( V_119 , V_413 ) )
return V_119 ;
default:
return V_120 ;
}
}
static inline bool F_238 ( struct V_1 * V_14 )
{
return V_229 && V_14 -> V_3 -> V_267 & V_414 ;
}
static inline bool F_239 ( struct V_1 * V_14 )
{
return V_229 && V_14 -> V_3 -> V_267 & V_415 ;
}
static void F_240 ( struct V_1 * V_14 ,
struct V_416 * V_417 )
{
if ( V_14 -> V_411 && V_14 -> V_169 ) {
T_10 V_418 = V_14 -> V_169 -> V_157 -> V_419 ;
V_418 = F_241 ( V_418 , 1000 ) ;
V_418 = 3 * V_418 + 500 ;
if ( V_418 > 0xffff )
V_418 = 0xffff ;
V_417 -> V_29 = F_16 ( ( T_1 ) V_418 ) ;
V_417 -> V_31 = V_417 -> V_29 ;
} else {
V_417 -> V_29 = F_80 ( V_420 ) ;
V_417 -> V_31 = F_80 ( V_421 ) ;
}
}
static inline void F_242 ( struct V_1 * V_14 )
{
if ( V_14 -> V_77 > V_78 &&
F_238 ( V_14 ) ) {
F_58 ( V_207 , & V_14 -> V_83 ) ;
V_14 -> V_79 = V_422 ;
} else {
V_14 -> V_77 = F_206 ( T_1 , V_14 -> V_77 ,
V_78 ) ;
V_14 -> V_79 = V_78 ;
}
V_14 -> V_80 = V_14 -> V_77 ;
}
static int F_133 ( struct V_1 * V_14 , void * V_156 )
{
struct V_423 * V_235 = V_156 ;
struct V_416 V_417 = { . V_119 = V_14 -> V_119 } ;
void * V_394 = V_235 -> V_156 ;
T_1 V_41 ;
F_21 ( L_3 , V_14 ) ;
if ( V_14 -> V_286 || V_14 -> V_424 )
goto V_18;
switch ( V_14 -> V_119 ) {
case V_125 :
case V_121 :
if ( F_74 ( V_276 , & V_14 -> V_71 ) )
break;
if ( F_239 ( V_14 ) )
F_58 ( V_425 , & V_14 -> V_83 ) ;
default:
V_14 -> V_119 = F_237 ( V_417 . V_119 , V_14 -> V_3 -> V_267 ) ;
break;
}
V_18:
if ( V_14 -> V_98 != V_91 )
F_230 ( & V_394 , V_426 , 2 , V_14 -> V_98 ) ;
switch ( V_14 -> V_119 ) {
case V_120 :
if ( ! ( V_14 -> V_3 -> V_267 & V_271 ) &&
! ( V_14 -> V_3 -> V_267 & V_272 ) )
break;
V_417 . V_119 = V_120 ;
V_417 . V_427 = 0 ;
V_417 . V_428 = 0 ;
V_417 . V_29 = 0 ;
V_417 . V_31 = 0 ;
V_417 . V_429 = 0 ;
F_230 ( & V_394 , V_430 , sizeof( V_417 ) ,
( unsigned long ) & V_417 ) ;
break;
case V_121 :
V_417 . V_119 = V_121 ;
V_417 . V_428 = V_14 -> V_75 ;
F_240 ( V_14 , & V_417 ) ;
V_41 = F_206 ( T_1 , V_431 , V_14 -> V_3 -> V_318 -
V_212 - V_361 -
V_217 ) ;
V_417 . V_429 = F_16 ( V_41 ) ;
F_242 ( V_14 ) ;
V_417 . V_427 = F_206 ( T_1 , V_14 -> V_77 ,
V_78 ) ;
F_230 ( & V_394 , V_430 , sizeof( V_417 ) ,
( unsigned long ) & V_417 ) ;
if ( F_74 ( V_425 , & V_14 -> V_83 ) )
F_231 ( & V_394 , V_14 ) ;
if ( F_74 ( V_207 , & V_14 -> V_83 ) )
F_230 ( & V_394 , V_432 , 2 ,
V_14 -> V_77 ) ;
if ( V_14 -> V_3 -> V_267 & V_433 )
if ( V_14 -> V_73 == V_434 ||
F_74 ( V_435 , & V_14 -> V_71 ) ) {
V_14 -> V_73 = V_434 ;
F_230 ( & V_394 , V_436 , 1 ,
V_14 -> V_73 ) ;
}
break;
case V_125 :
F_242 ( V_14 ) ;
V_417 . V_119 = V_125 ;
V_417 . V_427 = 0 ;
V_417 . V_428 = 0 ;
V_417 . V_29 = 0 ;
V_417 . V_31 = 0 ;
V_41 = F_206 ( T_1 , V_431 , V_14 -> V_3 -> V_318 -
V_212 - V_361 -
V_217 ) ;
V_417 . V_429 = F_16 ( V_41 ) ;
F_230 ( & V_394 , V_430 , sizeof( V_417 ) ,
( unsigned long ) & V_417 ) ;
if ( F_74 ( V_425 , & V_14 -> V_83 ) )
F_231 ( & V_394 , V_14 ) ;
if ( V_14 -> V_3 -> V_267 & V_433 )
if ( V_14 -> V_73 == V_434 ||
F_74 ( V_435 , & V_14 -> V_71 ) ) {
V_14 -> V_73 = V_434 ;
F_230 ( & V_394 , V_436 , 1 ,
V_14 -> V_73 ) ;
}
break;
}
V_235 -> V_6 = F_16 ( V_14 -> V_6 ) ;
V_235 -> V_83 = F_80 ( 0 ) ;
return V_394 - V_156 ;
}
static int F_243 ( struct V_1 * V_14 , void * V_156 )
{
struct V_437 * V_132 = V_156 ;
void * V_394 = V_132 -> V_156 ;
void * V_235 = V_14 -> V_438 ;
int V_155 = V_14 -> V_439 ;
int type , V_440 , V_395 ;
unsigned long V_396 ;
struct V_416 V_417 = { . V_119 = V_120 } ;
struct V_400 V_401 ;
T_2 V_441 = 0 ;
T_1 V_318 = V_91 ;
T_1 V_133 = V_442 ;
T_1 V_41 ;
F_21 ( L_3 , V_14 ) ;
while ( V_155 >= V_399 ) {
V_155 -= F_229 ( & V_235 , & type , & V_395 , & V_396 ) ;
V_440 = type & V_443 ;
type &= V_444 ;
switch ( type ) {
case V_426 :
V_318 = V_396 ;
break;
case V_445 :
V_14 -> V_406 = V_396 ;
break;
case V_446 :
break;
case V_430 :
if ( V_395 == sizeof( V_417 ) )
memcpy ( & V_417 , ( void * ) V_396 , V_395 ) ;
break;
case V_436 :
if ( V_396 == V_434 )
F_58 ( V_435 , & V_14 -> V_71 ) ;
break;
case V_407 :
V_441 = 1 ;
if ( V_395 == sizeof( V_401 ) )
memcpy ( & V_401 , ( void * ) V_396 , V_395 ) ;
break;
case V_432 :
if ( ! V_229 )
return - V_58 ;
F_58 ( V_207 , & V_14 -> V_83 ) ;
F_58 ( V_447 , & V_14 -> V_71 ) ;
V_14 -> V_79 = V_422 ;
V_14 -> V_344 = V_396 ;
break;
default:
if ( V_440 )
break;
V_133 = V_448 ;
* ( ( T_2 * ) V_394 ++ ) = type ;
break;
}
}
if ( V_14 -> V_424 || V_14 -> V_286 > 1 )
goto V_18;
switch ( V_14 -> V_119 ) {
case V_125 :
case V_121 :
if ( ! F_74 ( V_276 , & V_14 -> V_71 ) ) {
V_14 -> V_119 = F_237 ( V_417 . V_119 ,
V_14 -> V_3 -> V_267 ) ;
break;
}
if ( V_441 ) {
if ( F_239 ( V_14 ) )
F_58 ( V_425 , & V_14 -> V_83 ) ;
else
return - V_58 ;
}
if ( V_14 -> V_119 != V_417 . V_119 )
return - V_58 ;
break;
}
V_18:
if ( V_14 -> V_119 != V_417 . V_119 ) {
V_133 = V_449 ;
V_417 . V_119 = V_14 -> V_119 ;
if ( V_14 -> V_424 == 1 )
return - V_58 ;
F_230 ( & V_394 , V_430 , sizeof( V_417 ) ,
( unsigned long ) & V_417 ) ;
}
if ( V_133 == V_442 ) {
if ( V_318 < V_450 )
V_133 = V_449 ;
else {
V_14 -> V_90 = V_318 ;
F_58 ( V_451 , & V_14 -> V_71 ) ;
}
F_230 ( & V_394 , V_426 , 2 , V_14 -> V_90 ) ;
if ( V_441 ) {
if ( V_14 -> V_102 != V_452 &&
V_401 . V_402 != V_452 &&
V_401 . V_402 != V_14 -> V_102 ) {
V_133 = V_449 ;
if ( V_14 -> V_286 >= 1 )
return - V_58 ;
F_230 ( & V_394 , V_407 ,
sizeof( V_401 ) ,
( unsigned long ) & V_401 ) ;
} else {
V_133 = V_453 ;
F_58 ( V_454 , & V_14 -> V_71 ) ;
}
}
switch ( V_417 . V_119 ) {
case V_120 :
V_14 -> V_73 = V_434 ;
F_58 ( V_455 , & V_14 -> V_71 ) ;
break;
case V_121 :
if ( ! F_74 ( V_447 , & V_14 -> V_71 ) )
V_14 -> V_344 = V_417 . V_427 ;
else
V_417 . V_427 = V_78 ;
V_14 -> V_456 = V_417 . V_428 ;
V_41 = F_206 ( T_1 , F_244 ( V_417 . V_429 ) ,
V_14 -> V_3 -> V_318 - V_212 -
V_361 - V_217 ) ;
V_417 . V_429 = F_16 ( V_41 ) ;
V_14 -> V_366 = V_41 ;
F_240 ( V_14 , & V_417 ) ;
F_58 ( V_455 , & V_14 -> V_71 ) ;
F_230 ( & V_394 , V_430 ,
sizeof( V_417 ) , ( unsigned long ) & V_417 ) ;
if ( F_74 ( V_425 , & V_14 -> V_83 ) ) {
V_14 -> V_457 = V_401 . V_152 ;
V_14 -> V_458 = V_401 . V_402 ;
V_14 -> V_459 = F_244 ( V_401 . V_403 ) ;
V_14 -> V_460 =
F_245 ( V_401 . V_406 ) ;
V_14 -> V_461 =
F_245 ( V_401 . V_405 ) ;
V_14 -> V_462 =
F_245 ( V_401 . V_404 ) ;
F_230 ( & V_394 , V_407 ,
sizeof( V_401 ) ,
( unsigned long ) & V_401 ) ;
}
break;
case V_125 :
V_41 = F_206 ( T_1 , F_244 ( V_417 . V_429 ) ,
V_14 -> V_3 -> V_318 - V_212 -
V_361 - V_217 ) ;
V_417 . V_429 = F_16 ( V_41 ) ;
V_14 -> V_366 = V_41 ;
F_58 ( V_455 , & V_14 -> V_71 ) ;
F_230 ( & V_394 , V_430 , sizeof( V_417 ) ,
( unsigned long ) & V_417 ) ;
break;
default:
V_133 = V_449 ;
memset ( & V_417 , 0 , sizeof( V_417 ) ) ;
V_417 . V_119 = V_14 -> V_119 ;
}
if ( V_133 == V_442 )
F_58 ( V_463 , & V_14 -> V_71 ) ;
}
V_132 -> V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 -> V_133 = F_16 ( V_133 ) ;
V_132 -> V_83 = F_80 ( 0 ) ;
return V_394 - V_156 ;
}
static int F_246 ( struct V_1 * V_14 , void * V_132 , int V_155 ,
void * V_156 , T_1 * V_133 )
{
struct V_423 * V_235 = V_156 ;
void * V_394 = V_235 -> V_156 ;
int type , V_395 ;
unsigned long V_396 ;
struct V_416 V_417 = { . V_119 = V_120 } ;
struct V_400 V_401 ;
F_21 ( L_43 , V_14 , V_132 , V_155 , V_156 ) ;
while ( V_155 >= V_399 ) {
V_155 -= F_229 ( & V_132 , & type , & V_395 , & V_396 ) ;
switch ( type ) {
case V_426 :
if ( V_396 < V_450 ) {
* V_133 = V_449 ;
V_14 -> V_98 = V_450 ;
} else
V_14 -> V_98 = V_396 ;
F_230 ( & V_394 , V_426 , 2 , V_14 -> V_98 ) ;
break;
case V_445 :
V_14 -> V_406 = V_396 ;
F_230 ( & V_394 , V_445 ,
2 , V_14 -> V_406 ) ;
break;
case V_430 :
if ( V_395 == sizeof( V_417 ) )
memcpy ( & V_417 , ( void * ) V_396 , V_395 ) ;
if ( F_74 ( V_276 , & V_14 -> V_71 ) &&
V_417 . V_119 != V_14 -> V_119 )
return - V_58 ;
V_14 -> V_73 = 0 ;
F_230 ( & V_394 , V_430 ,
sizeof( V_417 ) , ( unsigned long ) & V_417 ) ;
break;
case V_432 :
V_14 -> V_80 = F_206 ( T_1 , V_396 , V_14 -> V_80 ) ;
F_230 ( & V_394 , V_432 , 2 ,
V_14 -> V_77 ) ;
break;
case V_407 :
if ( V_395 == sizeof( V_401 ) )
memcpy ( & V_401 , ( void * ) V_396 , V_395 ) ;
if ( V_14 -> V_102 != V_452 &&
V_401 . V_402 != V_452 &&
V_401 . V_402 != V_14 -> V_102 )
return - V_58 ;
F_230 ( & V_394 , V_407 , sizeof( V_401 ) ,
( unsigned long ) & V_401 ) ;
break;
case V_436 :
if ( * V_133 == V_453 )
if ( V_396 == V_434 )
F_58 ( V_435 ,
& V_14 -> V_71 ) ;
break;
}
}
if ( V_14 -> V_119 == V_120 && V_14 -> V_119 != V_417 . V_119 )
return - V_58 ;
V_14 -> V_119 = V_417 . V_119 ;
if ( * V_133 == V_442 || * V_133 == V_453 ) {
switch ( V_417 . V_119 ) {
case V_121 :
V_14 -> V_29 = F_244 ( V_417 . V_29 ) ;
V_14 -> V_31 = F_244 ( V_417 . V_31 ) ;
V_14 -> V_464 = F_244 ( V_417 . V_429 ) ;
if ( ! F_74 ( V_207 , & V_14 -> V_83 ) )
V_14 -> V_80 = F_206 ( T_1 , V_14 -> V_80 ,
V_417 . V_427 ) ;
if ( F_74 ( V_425 , & V_14 -> V_83 ) ) {
V_14 -> V_104 = F_244 ( V_401 . V_403 ) ;
V_14 -> V_106 =
F_245 ( V_401 . V_404 ) ;
V_14 -> V_108 = F_245 ( V_401 . V_405 ) ;
V_14 -> V_110 =
F_245 ( V_401 . V_406 ) ;
}
break;
case V_125 :
V_14 -> V_464 = F_244 ( V_417 . V_429 ) ;
}
}
V_235 -> V_6 = F_16 ( V_14 -> V_6 ) ;
V_235 -> V_83 = F_80 ( 0 ) ;
return V_394 - V_156 ;
}
static int F_247 ( struct V_1 * V_14 , void * V_156 ,
T_1 V_133 , T_1 V_83 )
{
struct V_437 * V_132 = V_156 ;
void * V_394 = V_132 -> V_156 ;
F_21 ( L_3 , V_14 ) ;
V_132 -> V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 -> V_133 = F_16 ( V_133 ) ;
V_132 -> V_83 = F_16 ( V_83 ) ;
return V_394 - V_156 ;
}
void F_248 ( struct V_1 * V_14 )
{
struct V_131 V_132 ;
struct V_2 * V_3 = V_14 -> V_3 ;
T_2 V_278 [ 128 ] ;
T_2 V_465 ;
V_132 . V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_6 = F_16 ( V_14 -> V_7 ) ;
V_132 . V_133 = F_80 ( V_282 ) ;
V_132 . V_138 = F_80 ( V_139 ) ;
if ( V_14 -> V_169 )
V_465 = V_466 ;
else
V_465 = V_140 ;
F_21 ( L_44 , V_14 , V_465 ) ;
F_81 ( V_3 , V_14 -> V_9 , V_465 , sizeof( V_132 ) , & V_132 ) ;
if ( F_249 ( V_284 , & V_14 -> V_71 ) )
return;
F_81 ( V_3 , F_85 ( V_3 ) , V_285 ,
F_133 ( V_14 , V_278 ) , V_278 ) ;
V_14 -> V_286 ++ ;
}
static void F_250 ( struct V_1 * V_14 , void * V_132 , int V_155 )
{
int type , V_395 ;
unsigned long V_396 ;
T_1 V_467 = V_14 -> V_80 ;
struct V_416 V_417 = {
. V_119 = V_14 -> V_119 ,
. V_29 = F_80 ( V_420 ) ,
. V_31 = F_80 ( V_421 ) ,
. V_429 = F_16 ( V_14 -> V_98 ) ,
. V_427 = F_206 ( T_1 , V_14 -> V_80 , V_78 ) ,
} ;
F_21 ( L_45 , V_14 , V_132 , V_155 ) ;
if ( ( V_14 -> V_119 != V_121 ) && ( V_14 -> V_119 != V_125 ) )
return;
while ( V_155 >= V_399 ) {
V_155 -= F_229 ( & V_132 , & type , & V_395 , & V_396 ) ;
switch ( type ) {
case V_430 :
if ( V_395 == sizeof( V_417 ) )
memcpy ( & V_417 , ( void * ) V_396 , V_395 ) ;
break;
case V_432 :
V_467 = V_396 ;
break;
}
}
switch ( V_417 . V_119 ) {
case V_121 :
V_14 -> V_29 = F_244 ( V_417 . V_29 ) ;
V_14 -> V_31 = F_244 ( V_417 . V_31 ) ;
V_14 -> V_464 = F_244 ( V_417 . V_429 ) ;
if ( F_74 ( V_207 , & V_14 -> V_83 ) )
V_14 -> V_80 = F_206 ( T_1 , V_14 -> V_80 , V_467 ) ;
else
V_14 -> V_80 = F_206 ( T_1 , V_14 -> V_80 ,
V_417 . V_427 ) ;
break;
case V_125 :
V_14 -> V_464 = F_244 ( V_417 . V_429 ) ;
}
}
static inline int F_251 ( struct V_2 * V_3 ,
struct V_389 * V_390 , T_1 V_468 ,
T_2 * V_156 )
{
struct V_469 * V_470 = (struct V_469 * ) V_156 ;
if ( V_468 < sizeof( * V_470 ) )
return - V_471 ;
if ( V_470 -> V_55 != V_472 )
return 0 ;
if ( ( V_3 -> V_258 & V_259 ) &&
V_390 -> V_9 == V_3 -> V_263 ) {
F_252 ( & V_3 -> V_264 ) ;
V_3 -> V_258 |= V_260 ;
V_3 -> V_263 = 0 ;
F_131 ( V_3 ) ;
}
return 0 ;
}
static struct V_1 * F_253 ( struct V_2 * V_3 ,
struct V_389 * V_390 ,
T_2 * V_156 , T_2 V_465 , T_2 V_237 )
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
goto V_473;
}
V_294 = V_295 -> V_13 ;
F_5 ( & V_3 -> V_8 ) ;
F_24 ( V_294 ) ;
if ( V_10 != F_80 ( V_147 ) &&
! F_254 ( V_3 -> V_88 ) ) {
V_3 -> V_84 = V_474 ;
V_133 = V_135 ;
goto V_475;
}
V_133 = V_476 ;
if ( F_1 ( V_3 , V_7 ) )
goto V_475;
V_14 = V_295 -> V_24 -> V_296 ( V_295 ) ;
if ( ! V_14 )
goto V_475;
V_13 = V_14 -> V_13 ;
F_138 ( & F_13 ( V_13 ) -> V_11 , V_3 -> V_11 ) ;
F_138 ( & F_13 ( V_13 ) -> V_287 , V_3 -> V_287 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_7 ;
V_14 -> V_411 = V_237 ;
F_66 ( V_3 , V_14 ) ;
V_6 = V_14 -> V_7 ;
F_78 ( V_14 , V_13 -> V_129 ) ;
V_14 -> V_9 = V_390 -> V_9 ;
if ( V_3 -> V_258 & V_260 ) {
if ( F_83 ( V_14 ) ) {
if ( F_74 ( V_134 , & F_13 ( V_13 ) -> V_83 ) ) {
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
V_475:
F_25 ( V_294 ) ;
F_7 ( & V_3 -> V_8 ) ;
V_473:
V_132 . V_7 = F_16 ( V_7 ) ;
V_132 . V_6 = F_16 ( V_6 ) ;
V_132 . V_133 = F_16 ( V_133 ) ;
V_132 . V_138 = F_16 ( V_138 ) ;
F_81 ( V_3 , V_390 -> V_9 , V_465 , sizeof( V_132 ) , & V_132 ) ;
if ( V_133 == V_279 && V_138 == V_139 ) {
struct V_261 V_477 ;
V_477 . type = F_80 ( V_262 ) ;
V_3 -> V_258 |= V_259 ;
V_3 -> V_263 = F_85 ( V_3 ) ;
F_129 ( & V_3 -> V_264 , V_265 ) ;
F_81 ( V_3 , V_3 -> V_263 , V_266 ,
sizeof( V_477 ) , & V_477 ) ;
}
if ( V_14 && ! F_74 ( V_284 , & V_14 -> V_71 ) &&
V_133 == V_282 ) {
T_2 V_278 [ 128 ] ;
F_58 ( V_284 , & V_14 -> V_71 ) ;
F_81 ( V_3 , F_85 ( V_3 ) , V_285 ,
F_133 ( V_14 , V_278 ) , V_278 ) ;
V_14 -> V_286 ++ ;
}
return V_14 ;
}
static int F_255 ( struct V_2 * V_3 ,
struct V_389 * V_390 , T_1 V_468 , T_2 * V_156 )
{
struct V_304 * V_157 = V_3 -> V_88 -> V_157 ;
struct V_168 * V_88 = V_3 -> V_88 ;
if ( V_468 < sizeof( struct V_234 ) )
return - V_471 ;
F_144 ( V_157 ) ;
if ( F_74 ( V_478 , & V_157 -> V_479 ) &&
! F_249 ( V_480 , & V_88 -> V_83 ) )
F_256 ( V_157 , & V_88 -> V_287 , V_88 -> type ,
V_88 -> V_321 , 0 , NULL , 0 ,
V_88 -> V_481 ) ;
F_145 ( V_157 ) ;
F_253 ( V_3 , V_390 , V_156 , V_140 , 0 ) ;
return 0 ;
}
static int F_257 ( struct V_2 * V_3 ,
struct V_389 * V_390 , T_1 V_468 ,
T_2 * V_156 )
{
struct V_131 * V_132 = (struct V_131 * ) V_156 ;
T_1 V_7 , V_6 , V_133 , V_138 ;
struct V_1 * V_14 ;
T_2 V_235 [ 128 ] ;
int V_15 ;
if ( V_468 < sizeof( * V_132 ) )
return - V_471 ;
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
V_15 = - V_353 ;
goto V_482;
}
} else {
V_14 = F_9 ( V_3 , V_390 -> V_9 ) ;
if ( ! V_14 ) {
V_15 = - V_353 ;
goto V_482;
}
}
V_15 = 0 ;
F_6 ( V_14 ) ;
switch ( V_133 ) {
case V_282 :
F_23 ( V_14 , V_57 ) ;
V_14 -> V_9 = 0 ;
V_14 -> V_6 = V_6 ;
F_113 ( V_228 , & V_14 -> V_71 ) ;
if ( F_249 ( V_284 , & V_14 -> V_71 ) )
break;
F_81 ( V_3 , F_85 ( V_3 ) , V_285 ,
F_133 ( V_14 , V_235 ) , V_235 ) ;
V_14 -> V_286 ++ ;
break;
case V_279 :
F_58 ( V_228 , & V_14 -> V_71 ) ;
break;
default:
F_70 ( V_14 , V_58 ) ;
break;
}
F_50 ( V_14 ) ;
V_482:
F_7 ( & V_3 -> V_8 ) ;
return V_15 ;
}
static inline void F_258 ( struct V_1 * V_14 )
{
if ( V_14 -> V_119 != V_121 && V_14 -> V_119 != V_125 )
V_14 -> V_73 = V_434 ;
else if ( ! F_74 ( V_435 , & V_14 -> V_71 ) )
V_14 -> V_73 = V_74 ;
}
static void F_259 ( struct V_1 * V_14 , void * V_156 ,
T_2 V_9 , T_1 V_83 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
F_21 ( L_48 , V_3 , V_14 , V_9 ,
V_83 ) ;
F_113 ( V_454 , & V_14 -> V_71 ) ;
F_58 ( V_463 , & V_14 -> V_71 ) ;
F_81 ( V_3 , V_9 , V_483 ,
F_247 ( V_14 , V_156 ,
V_442 , V_83 ) , V_156 ) ;
}
static inline int F_260 ( struct V_2 * V_3 ,
struct V_389 * V_390 , T_1 V_468 ,
T_2 * V_156 )
{
struct V_423 * V_235 = (struct V_423 * ) V_156 ;
T_1 V_6 , V_83 ;
T_2 V_132 [ 64 ] ;
struct V_1 * V_14 ;
int V_155 , V_15 = 0 ;
if ( V_468 < sizeof( * V_235 ) )
return - V_471 ;
V_6 = F_67 ( V_235 -> V_6 ) ;
V_83 = F_67 ( V_235 -> V_83 ) ;
F_21 ( L_49 , V_6 , V_83 ) ;
V_14 = F_4 ( V_3 , V_6 ) ;
if ( ! V_14 )
return - V_484 ;
if ( V_14 -> V_23 != V_57 && V_14 -> V_23 != V_130 ) {
struct V_485 V_470 ;
V_470 . V_55 = F_80 ( V_486 ) ;
V_470 . V_7 = F_16 ( V_14 -> V_7 ) ;
V_470 . V_6 = F_16 ( V_14 -> V_6 ) ;
F_81 ( V_3 , V_390 -> V_9 , V_487 ,
sizeof( V_470 ) , & V_470 ) ;
goto V_482;
}
V_155 = V_468 - sizeof( * V_235 ) ;
if ( V_14 -> V_439 + V_155 > sizeof( V_14 -> V_438 ) ) {
F_81 ( V_3 , V_390 -> V_9 , V_483 ,
F_247 ( V_14 , V_132 ,
V_488 , V_83 ) , V_132 ) ;
goto V_482;
}
memcpy ( V_14 -> V_438 + V_14 -> V_439 , V_235 -> V_156 , V_155 ) ;
V_14 -> V_439 += V_155 ;
if ( V_83 & V_489 ) {
F_81 ( V_3 , V_390 -> V_9 , V_483 ,
F_247 ( V_14 , V_132 ,
V_442 , V_83 ) , V_132 ) ;
goto V_482;
}
V_155 = F_243 ( V_14 , V_132 ) ;
if ( V_155 < 0 ) {
F_79 ( V_14 , V_277 ) ;
goto V_482;
}
V_14 -> V_9 = V_390 -> V_9 ;
F_81 ( V_3 , V_390 -> V_9 , V_483 , V_155 , V_132 ) ;
V_14 -> V_424 ++ ;
V_14 -> V_439 = 0 ;
if ( ! F_74 ( V_463 , & V_14 -> V_71 ) )
goto V_482;
if ( F_74 ( V_490 , & V_14 -> V_71 ) ) {
F_258 ( V_14 ) ;
if ( V_14 -> V_119 == V_121 ||
V_14 -> V_119 == V_125 )
V_15 = F_235 ( V_14 ) ;
if ( V_15 < 0 )
F_79 ( V_14 , - V_15 ) ;
else
F_125 ( V_14 ) ;
goto V_482;
}
if ( ! F_249 ( V_284 , & V_14 -> V_71 ) ) {
T_2 V_278 [ 64 ] ;
F_81 ( V_3 , F_85 ( V_3 ) , V_285 ,
F_133 ( V_14 , V_278 ) , V_278 ) ;
V_14 -> V_286 ++ ;
}
if ( F_74 ( V_491 , & V_14 -> V_71 ) &&
F_74 ( V_454 , & V_14 -> V_71 ) ) {
if ( ! V_14 -> V_169 )
F_259 ( V_14 , V_132 , V_390 -> V_9 , V_83 ) ;
else
V_14 -> V_9 = V_390 -> V_9 ;
}
V_482:
F_50 ( V_14 ) ;
return V_15 ;
}
static inline int F_261 ( struct V_2 * V_3 ,
struct V_389 * V_390 , T_1 V_468 ,
T_2 * V_156 )
{
struct V_437 * V_132 = (struct V_437 * ) V_156 ;
T_1 V_7 , V_83 , V_133 ;
struct V_1 * V_14 ;
int V_155 = V_468 - sizeof( * V_132 ) ;
int V_15 = 0 ;
if ( V_468 < sizeof( * V_132 ) )
return - V_471 ;
V_7 = F_67 ( V_132 -> V_7 ) ;
V_83 = F_67 ( V_132 -> V_83 ) ;
V_133 = F_67 ( V_132 -> V_133 ) ;
F_21 ( L_50 , V_7 , V_83 ,
V_133 , V_155 ) ;
V_14 = F_4 ( V_3 , V_7 ) ;
if ( ! V_14 )
return 0 ;
switch ( V_133 ) {
case V_442 :
F_250 ( V_14 , V_132 -> V_156 , V_155 ) ;
F_113 ( V_491 , & V_14 -> V_71 ) ;
break;
case V_453 :
F_58 ( V_491 , & V_14 -> V_71 ) ;
if ( F_74 ( V_454 , & V_14 -> V_71 ) ) {
char V_278 [ 64 ] ;
V_155 = F_246 ( V_14 , V_132 -> V_156 , V_155 ,
V_278 , & V_133 ) ;
if ( V_155 < 0 ) {
F_79 ( V_14 , V_277 ) ;
goto V_18;
}
if ( ! V_14 -> V_169 ) {
F_259 ( V_14 , V_278 , V_390 -> V_9 ,
0 ) ;
} else {
if ( F_119 ( V_14 ) ) {
F_262 ( V_14 ) ;
V_14 -> V_9 = V_390 -> V_9 ;
}
}
}
goto V_18;
case V_449 :
if ( V_14 -> V_424 <= V_492 ) {
char V_235 [ 64 ] ;
if ( V_155 > sizeof( V_235 ) - sizeof( struct V_423 ) ) {
F_79 ( V_14 , V_277 ) ;
goto V_18;
}
V_133 = V_442 ;
V_155 = F_246 ( V_14 , V_132 -> V_156 , V_155 ,
V_235 , & V_133 ) ;
if ( V_155 < 0 ) {
F_79 ( V_14 , V_277 ) ;
goto V_18;
}
F_81 ( V_3 , F_85 ( V_3 ) ,
V_285 , V_155 , V_235 ) ;
V_14 -> V_286 ++ ;
if ( V_133 != V_442 )
goto V_18;
break;
}
default:
F_27 ( V_14 , V_277 ) ;
F_78 ( V_14 , V_493 ) ;
F_79 ( V_14 , V_277 ) ;
goto V_18;
}
if ( V_83 & V_489 )
goto V_18;
F_58 ( V_490 , & V_14 -> V_71 ) ;
if ( F_74 ( V_463 , & V_14 -> V_71 ) ) {
F_258 ( V_14 ) ;
if ( V_14 -> V_119 == V_121 ||
V_14 -> V_119 == V_125 )
V_15 = F_235 ( V_14 ) ;
if ( V_15 < 0 )
F_79 ( V_14 , - V_15 ) ;
else
F_125 ( V_14 ) ;
}
V_18:
F_50 ( V_14 ) ;
return V_15 ;
}
static inline int F_263 ( struct V_2 * V_3 ,
struct V_389 * V_390 , T_1 V_468 ,
T_2 * V_156 )
{
struct V_273 * V_235 = (struct V_273 * ) V_156 ;
struct V_494 V_132 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
struct V_26 * V_13 ;
if ( V_468 != sizeof( * V_235 ) )
return - V_471 ;
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
F_81 ( V_3 , V_390 -> V_9 , V_495 , sizeof( V_132 ) , & V_132 ) ;
F_24 ( V_13 ) ;
V_13 -> V_496 = V_497 ;
F_25 ( V_13 ) ;
F_61 ( V_14 ) ;
F_70 ( V_14 , V_277 ) ;
F_50 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_51 ( V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
static inline int F_264 ( struct V_2 * V_3 ,
struct V_389 * V_390 , T_1 V_468 ,
T_2 * V_156 )
{
struct V_494 * V_132 = (struct V_494 * ) V_156 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
if ( V_468 != sizeof( * V_132 ) )
return - V_471 ;
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
F_70 ( V_14 , 0 ) ;
F_50 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_51 ( V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
static inline int F_265 ( struct V_2 * V_3 ,
struct V_389 * V_390 , T_1 V_468 ,
T_2 * V_156 )
{
struct V_261 * V_235 = (struct V_261 * ) V_156 ;
T_1 type ;
if ( V_468 != sizeof( * V_235 ) )
return - V_471 ;
type = F_67 ( V_235 -> type ) ;
F_21 ( L_53 , type ) ;
if ( type == V_262 ) {
T_2 V_278 [ 8 ] ;
T_8 V_267 = V_269 ;
struct V_498 * V_132 = (struct V_498 * ) V_278 ;
V_132 -> type = F_80 ( V_262 ) ;
V_132 -> V_133 = F_80 ( V_499 ) ;
if ( ! V_270 )
V_267 |= V_271 | V_272
| V_433 ;
if ( V_229 )
V_267 |= V_415
| V_414 ;
F_103 ( V_267 , V_132 -> V_156 ) ;
F_81 ( V_3 , V_390 -> V_9 , V_500 , sizeof( V_278 ) ,
V_278 ) ;
} else if ( type == V_501 ) {
T_2 V_278 [ 12 ] ;
struct V_498 * V_132 = (struct V_498 * ) V_278 ;
if ( V_229 )
V_502 [ 0 ] |= V_233 ;
else
V_502 [ 0 ] &= ~ V_233 ;
V_132 -> type = F_80 ( V_501 ) ;
V_132 -> V_133 = F_80 ( V_499 ) ;
memcpy ( V_132 -> V_156 , V_502 , sizeof( V_502 ) ) ;
F_81 ( V_3 , V_390 -> V_9 , V_500 , sizeof( V_278 ) ,
V_278 ) ;
} else {
struct V_498 V_132 ;
V_132 . type = F_16 ( type ) ;
V_132 . V_133 = F_80 ( V_503 ) ;
F_81 ( V_3 , V_390 -> V_9 , V_500 , sizeof( V_132 ) ,
& V_132 ) ;
}
return 0 ;
}
static inline int F_266 ( struct V_2 * V_3 ,
struct V_389 * V_390 , T_1 V_468 ,
T_2 * V_156 )
{
struct V_498 * V_132 = (struct V_498 * ) V_156 ;
T_1 type , V_133 ;
if ( V_468 < sizeof( * V_132 ) )
return - V_471 ;
type = F_67 ( V_132 -> type ) ;
V_133 = F_67 ( V_132 -> V_133 ) ;
F_21 ( L_54 , type , V_133 ) ;
if ( V_390 -> V_9 != V_3 -> V_263 ||
V_3 -> V_258 & V_260 )
return 0 ;
F_252 ( & V_3 -> V_264 ) ;
if ( V_133 != V_499 ) {
V_3 -> V_258 |= V_260 ;
V_3 -> V_263 = 0 ;
F_131 ( V_3 ) ;
return 0 ;
}
switch ( type ) {
case V_262 :
V_3 -> V_267 = F_97 ( V_132 -> V_156 ) ;
if ( V_3 -> V_267 & V_504 ) {
struct V_261 V_235 ;
V_235 . type = F_80 ( V_501 ) ;
V_3 -> V_263 = F_85 ( V_3 ) ;
F_81 ( V_3 , V_3 -> V_263 ,
V_266 , sizeof( V_235 ) , & V_235 ) ;
} else {
V_3 -> V_258 |= V_260 ;
V_3 -> V_263 = 0 ;
F_131 ( V_3 ) ;
}
break;
case V_501 :
V_3 -> V_232 = V_132 -> V_156 [ 0 ] ;
V_3 -> V_258 |= V_260 ;
V_3 -> V_263 = 0 ;
F_131 ( V_3 ) ;
break;
}
return 0 ;
}
static int F_267 ( struct V_2 * V_3 ,
struct V_389 * V_390 ,
T_1 V_468 , void * V_156 )
{
struct V_238 * V_235 = V_156 ;
struct V_505 V_132 ;
struct V_1 * V_14 ;
struct V_304 * V_157 ;
T_1 V_10 , V_7 ;
if ( V_468 != sizeof( * V_235 ) )
return - V_471 ;
if ( ! V_229 )
return - V_20 ;
V_10 = F_244 ( V_235 -> V_10 ) ;
V_7 = F_244 ( V_235 -> V_7 ) ;
F_21 ( L_55 , V_10 , V_7 , V_235 -> V_237 ) ;
if ( V_235 -> V_237 == V_506 ) {
F_253 ( V_3 , V_390 , V_156 , V_466 ,
V_235 -> V_237 ) ;
return 0 ;
}
V_157 = F_268 ( V_235 -> V_237 ) ;
if ( ! V_157 )
goto error;
if ( V_157 -> V_507 != V_508 || ! F_74 ( V_509 , & V_157 -> V_83 ) ) {
F_170 ( V_157 ) ;
goto error;
}
V_14 = F_253 ( V_3 , V_390 , V_156 , V_466 ,
V_235 -> V_237 ) ;
if ( V_14 ) {
struct V_113 * V_114 = V_3 -> V_88 -> V_113 ;
struct V_168 * V_169 ;
V_169 = F_269 ( V_157 , V_510 , V_3 -> V_287 ) ;
if ( ! V_169 ) {
F_170 ( V_157 ) ;
return - V_353 ;
}
F_21 ( L_56 , V_114 , V_14 , V_169 ) ;
V_114 -> V_115 = V_14 ;
V_14 -> V_169 = V_169 ;
V_14 -> V_73 = V_434 ;
V_3 -> V_318 = V_157 -> V_511 ;
}
F_170 ( V_157 ) ;
return 0 ;
error:
V_132 . V_6 = 0 ;
V_132 . V_7 = F_16 ( V_7 ) ;
V_132 . V_133 = F_80 ( V_512 ) ;
V_132 . V_138 = F_80 ( V_139 ) ;
F_81 ( V_3 , V_390 -> V_9 , V_466 ,
sizeof( V_132 ) , & V_132 ) ;
return - V_353 ;
}
static void F_270 ( struct V_1 * V_14 , T_2 V_513 )
{
struct V_514 V_235 ;
T_2 V_9 ;
F_21 ( L_57 , V_14 , V_513 ) ;
V_9 = F_85 ( V_14 -> V_3 ) ;
V_14 -> V_9 = V_9 ;
V_235 . V_515 = F_16 ( V_14 -> V_7 ) ;
V_235 . V_513 = V_513 ;
F_81 ( V_14 -> V_3 , V_9 , V_516 , sizeof( V_235 ) ,
& V_235 ) ;
F_78 ( V_14 , V_517 ) ;
}
static void F_271 ( struct V_1 * V_14 , T_1 V_133 )
{
struct V_518 V_132 ;
F_21 ( L_58 , V_14 , V_133 ) ;
V_132 . V_515 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_133 = F_16 ( V_133 ) ;
F_81 ( V_14 -> V_3 , V_14 -> V_9 , V_519 ,
sizeof( V_132 ) , & V_132 ) ;
}
static void F_272 ( struct V_1 * V_14 , T_1 V_133 )
{
struct V_520 V_521 ;
F_21 ( L_58 , V_14 , V_133 ) ;
V_14 -> V_9 = F_85 ( V_14 -> V_3 ) ;
V_521 . V_515 = F_16 ( V_14 -> V_7 ) ;
V_521 . V_133 = F_16 ( V_133 ) ;
F_81 ( V_14 -> V_3 , V_14 -> V_9 , V_522 ,
sizeof( V_521 ) , & V_521 ) ;
F_78 ( V_14 , V_517 ) ;
}
static void F_273 ( struct V_2 * V_3 , T_1 V_515 )
{
struct V_520 V_521 ;
F_21 ( L_59 , V_3 , V_515 ) ;
V_521 . V_515 = F_16 ( V_515 ) ;
V_521 . V_133 = F_80 ( V_523 ) ;
F_81 ( V_3 , F_85 ( V_3 ) , V_522 ,
sizeof( V_521 ) , & V_521 ) ;
}
static void F_274 ( struct V_2 * V_3 , T_2 V_9 ,
T_1 V_515 )
{
struct V_524 V_132 ;
F_21 ( L_60 , V_515 ) ;
V_132 . V_515 = F_16 ( V_515 ) ;
F_81 ( V_3 , V_9 , V_525 , sizeof( V_132 ) , & V_132 ) ;
}
static void F_275 ( struct V_1 * V_14 )
{
V_14 -> V_116 = NULL ;
V_14 -> V_169 = NULL ;
}
static void F_276 ( struct V_1 * V_14 )
{
if ( V_14 -> V_23 != V_56 ) {
F_79 ( V_14 , V_277 ) ;
return;
}
switch ( V_14 -> V_250 ) {
case V_255 :
F_123 ( V_14 ) ;
F_271 ( V_14 , V_526 ) ;
break;
case V_252 :
if ( V_14 -> V_165 == V_527 ||
V_14 -> V_165 == V_528 ) {
F_123 ( V_14 ) ;
}
F_272 ( V_14 , V_523 ) ;
break;
}
}
static void F_277 ( struct V_1 * V_14 ,
struct V_117 * V_164 )
{
struct V_437 V_132 ;
V_14 -> V_116 = V_164 ;
V_14 -> V_169 -> V_311 = V_14 -> V_3 ;
F_259 ( V_14 , & V_132 , V_14 -> V_9 , 0 ) ;
if ( F_74 ( V_490 , & V_14 -> V_71 ) ) {
int V_15 ;
F_258 ( V_14 ) ;
V_15 = F_235 ( V_14 ) ;
if ( V_15 < 0 )
F_79 ( V_14 , - V_15 ) ;
else
F_125 ( V_14 ) ;
}
}
static void F_278 ( struct V_1 * V_14 ,
struct V_117 * V_164 )
{
V_14 -> V_169 = V_164 -> V_3 ;
V_14 -> V_169 -> V_311 = V_14 -> V_3 ;
F_21 ( L_61 , V_14 -> V_165 ) ;
switch ( V_14 -> V_165 ) {
case V_527 :
V_14 -> V_165 = V_529 ;
break;
case V_528 :
if ( F_74 ( V_226 , & V_14 -> V_220 ) ) {
V_14 -> V_165 = V_530 ;
} else if ( V_14 -> V_250 == V_252 ) {
V_14 -> V_165 = V_531 ;
F_272 ( V_14 , V_532 ) ;
} else if ( V_14 -> V_250 == V_255 ) {
V_14 -> V_165 = V_533 ;
F_271 ( V_14 , V_534 ) ;
}
break;
default:
F_275 ( V_14 ) ;
V_14 -> V_165 = V_166 ;
}
}
void F_279 ( struct V_1 * V_14 , struct V_117 * V_164 ,
T_2 V_138 )
{
F_21 ( L_62 , V_14 , V_164 , V_138 ) ;
if ( V_138 ) {
F_276 ( V_14 ) ;
F_275 ( V_14 ) ;
return;
}
if ( V_14 -> V_23 != V_56 ) {
if ( V_14 -> V_411 )
F_277 ( V_14 , V_164 ) ;
} else {
F_278 ( V_14 , V_164 ) ;
}
}
void F_280 ( struct V_1 * V_14 )
{
F_21 ( L_3 , V_14 ) ;
if ( V_14 -> V_411 == V_506 ) {
if ( V_14 -> V_230 != V_231 )
return;
V_14 -> V_250 = V_252 ;
V_14 -> V_165 = V_167 ;
} else {
V_14 -> V_250 = V_252 ;
V_14 -> V_165 = V_529 ;
V_14 -> V_412 = 0 ;
F_122 ( V_14 ) ;
F_270 ( V_14 , 0 ) ;
}
}
static void F_281 ( struct V_1 * V_14 , int V_133 ,
T_2 V_411 , T_2 V_535 )
{
F_21 ( L_63 , V_14 , F_22 ( V_14 -> V_23 ) ,
V_411 , V_535 ) ;
V_14 -> V_73 = V_434 ;
if ( V_14 -> V_23 == V_59 ) {
if ( V_133 == V_282 ) {
V_14 -> V_411 = V_411 ;
F_121 ( V_14 , V_535 ) ;
} else {
F_120 ( V_14 ) ;
}
return;
}
if ( F_116 ( V_14 ) ) {
struct V_131 V_132 ;
char V_278 [ 128 ] ;
V_132 . V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_6 = F_16 ( V_14 -> V_7 ) ;
if ( V_133 == V_282 ) {
V_132 . V_133 = F_80 ( V_282 ) ;
V_132 . V_138 = F_80 ( V_139 ) ;
} else {
V_132 . V_133 = F_80 ( V_476 ) ;
V_132 . V_138 = F_80 ( V_139 ) ;
}
F_81 ( V_14 -> V_3 , V_14 -> V_9 , V_466 ,
sizeof( V_132 ) , & V_132 ) ;
if ( V_133 == V_282 ) {
F_20 ( V_14 , V_57 ) ;
F_58 ( V_284 , & V_14 -> V_71 ) ;
F_81 ( V_14 -> V_3 , F_85 ( V_14 -> V_3 ) ,
V_285 ,
F_133 ( V_14 , V_278 ) , V_278 ) ;
V_14 -> V_286 ++ ;
}
}
}
static void F_282 ( struct V_1 * V_14 , T_2 V_411 ,
T_2 V_535 )
{
F_122 ( V_14 ) ;
V_14 -> V_412 = V_411 ;
V_14 -> V_165 = V_536 ;
F_270 ( V_14 , V_535 ) ;
}
static void F_283 ( struct V_1 * V_14 , int V_133 )
{
struct V_117 * V_164 = NULL ;
if ( V_164 ) {
if ( V_164 -> V_23 == V_56 ) {
V_14 -> V_169 = V_164 -> V_3 ;
V_14 -> V_169 -> V_311 = V_14 -> V_3 ;
V_14 -> V_165 = V_533 ;
F_271 ( V_14 , V_534 ) ;
F_279 ( V_14 , V_164 , V_534 ) ;
} else {
V_14 -> V_165 = V_528 ;
}
} else {
F_271 ( V_14 , V_537 ) ;
}
}
static void F_284 ( struct V_1 * V_14 , int V_133 )
{
if ( V_14 -> V_250 == V_255 ) {
T_2 V_538 ;
if ( V_133 == - V_20 )
V_538 = V_539 ;
else
V_538 = V_537 ;
F_271 ( V_14 , V_538 ) ;
}
V_14 -> V_250 = V_251 ;
V_14 -> V_165 = V_166 ;
F_189 ( V_14 ) ;
}
void F_285 ( struct V_1 * V_14 , int V_133 )
{
T_2 V_411 = V_14 -> V_411 ;
T_2 V_535 = V_14 -> V_535 ;
F_21 ( L_64 ,
V_14 , V_133 , V_411 , V_535 ) ;
if ( V_14 -> V_23 == V_137 || V_14 -> V_23 == V_540 ) {
F_50 ( V_14 ) ;
return;
}
if ( V_14 -> V_23 != V_56 ) {
F_281 ( V_14 , V_133 , V_411 , V_535 ) ;
} else if ( V_133 != V_534 ) {
F_284 ( V_14 , V_133 ) ;
} else {
switch ( V_14 -> V_250 ) {
case V_252 :
F_282 ( V_14 , V_411 ,
V_535 ) ;
break;
case V_255 :
F_283 ( V_14 , V_133 ) ;
break;
default:
F_284 ( V_14 , V_133 ) ;
break;
}
}
}
static inline int F_286 ( struct V_2 * V_3 ,
struct V_389 * V_390 ,
T_1 V_468 , void * V_156 )
{
struct V_514 * V_235 = V_156 ;
struct V_518 V_132 ;
struct V_1 * V_14 ;
T_1 V_515 = 0 ;
T_1 V_133 = V_537 ;
if ( V_468 != sizeof( * V_235 ) )
return - V_471 ;
V_515 = F_244 ( V_235 -> V_515 ) ;
F_21 ( L_65 , V_515 , V_235 -> V_513 ) ;
if ( ! V_229 )
return - V_20 ;
V_14 = F_8 ( V_3 , V_515 ) ;
if ( ! V_14 ) {
V_132 . V_515 = F_16 ( V_515 ) ;
V_132 . V_133 = F_80 ( V_537 ) ;
F_81 ( V_3 , V_390 -> V_9 , V_519 ,
sizeof( V_132 ) , & V_132 ) ;
return 0 ;
}
V_14 -> V_9 = V_390 -> V_9 ;
if ( V_14 -> V_7 < V_21 ||
V_14 -> V_230 == V_541 ||
( V_14 -> V_119 != V_121 &&
V_14 -> V_119 != V_125 ) ) {
V_133 = V_537 ;
goto V_542;
}
if ( V_14 -> V_411 == V_235 -> V_513 ) {
V_133 = V_543 ;
goto V_542;
}
if ( V_235 -> V_513 ) {
struct V_304 * V_157 ;
V_157 = F_268 ( V_235 -> V_513 ) ;
if ( ! V_157 || V_157 -> V_507 != V_508 ||
! F_74 ( V_509 , & V_157 -> V_83 ) ) {
if ( V_157 )
F_170 ( V_157 ) ;
V_133 = V_539 ;
goto V_542;
}
F_170 ( V_157 ) ;
}
if ( ( F_91 ( V_14 ) ||
V_14 -> V_250 != V_251 ) &&
F_12 ( V_3 -> V_11 , V_3 -> V_287 ) > 0 ) {
V_133 = V_544 ;
goto V_542;
}
V_14 -> V_250 = V_255 ;
F_122 ( V_14 ) ;
V_14 -> V_412 = V_235 -> V_513 ;
V_515 = V_14 -> V_6 ;
if ( ! V_235 -> V_513 ) {
if ( F_74 ( V_226 , & V_14 -> V_220 ) ) {
V_14 -> V_165 = V_530 ;
V_133 = V_545 ;
} else {
V_14 -> V_165 = V_533 ;
V_133 = V_534 ;
}
} else {
V_14 -> V_165 = V_167 ;
V_133 = V_545 ;
}
V_542:
F_271 ( V_14 , V_133 ) ;
F_50 ( V_14 ) ;
return 0 ;
}
static void F_287 ( struct V_2 * V_3 , T_1 V_515 , T_1 V_133 )
{
struct V_1 * V_14 ;
struct V_117 * V_164 = NULL ;
V_14 = F_4 ( V_3 , V_515 ) ;
if ( ! V_14 ) {
F_273 ( V_3 , V_515 ) ;
return;
}
F_71 ( V_14 ) ;
if ( V_133 == V_545 )
F_78 ( V_14 , V_546 ) ;
switch ( V_14 -> V_165 ) {
case V_527 :
V_14 -> V_165 = V_528 ;
break;
case V_529 :
if ( V_133 == V_545 ) {
break;
} else if ( F_74 ( V_226 ,
& V_14 -> V_220 ) ) {
V_14 -> V_165 = V_530 ;
} else {
V_14 -> V_165 = V_531 ;
F_272 ( V_14 , V_532 ) ;
}
break;
case V_536 :
if ( V_133 == V_534 ) {
V_14 -> V_165 = V_528 ;
} else {
V_14 -> V_165 = V_527 ;
}
if ( ! V_164 ) {
F_272 ( V_14 , V_523 ) ;
break;
}
if ( V_164 -> V_23 != V_56 )
break;
V_14 -> V_169 = V_164 -> V_3 ;
V_14 -> V_169 -> V_311 = V_14 -> V_3 ;
if ( V_133 == V_534 ) {
F_272 ( V_14 , V_532 ) ;
} else {
V_14 -> V_165 = V_529 ;
}
F_279 ( V_14 , V_164 , V_534 ) ;
break;
default:
V_14 -> V_412 = V_14 -> V_411 ;
F_123 ( V_14 ) ;
F_272 ( V_14 , V_523 ) ;
}
F_50 ( V_14 ) ;
}
static void F_288 ( struct V_2 * V_3 , T_2 V_9 , T_1 V_515 ,
T_1 V_133 )
{
struct V_1 * V_14 ;
V_14 = F_10 ( V_3 , V_9 ) ;
if ( ! V_14 ) {
F_273 ( V_3 , V_515 ) ;
return;
}
F_71 ( V_14 ) ;
if ( V_14 -> V_250 == V_252 ) {
if ( V_133 == V_544 ) {
V_14 -> V_250 = V_255 ;
} else {
V_14 -> V_412 = V_14 -> V_411 ;
F_123 ( V_14 ) ;
}
}
F_272 ( V_14 , V_523 ) ;
F_50 ( V_14 ) ;
}
static int F_289 ( struct V_2 * V_3 ,
struct V_389 * V_390 ,
T_1 V_468 , void * V_156 )
{
struct V_518 * V_132 = V_156 ;
T_1 V_515 , V_133 ;
if ( V_468 != sizeof( * V_132 ) )
return - V_471 ;
V_515 = F_244 ( V_132 -> V_515 ) ;
V_133 = F_244 ( V_132 -> V_133 ) ;
F_21 ( L_66 , V_515 , V_133 ) ;
if ( V_133 == V_534 || V_133 == V_545 )
F_287 ( V_3 , V_515 , V_133 ) ;
else
F_288 ( V_3 , V_390 -> V_9 , V_515 , V_133 ) ;
return 0 ;
}
static int F_290 ( struct V_2 * V_3 ,
struct V_389 * V_390 ,
T_1 V_468 , void * V_156 )
{
struct V_520 * V_521 = V_156 ;
struct V_1 * V_14 ;
T_1 V_515 , V_133 ;
if ( V_468 != sizeof( * V_521 ) )
return - V_471 ;
V_515 = F_244 ( V_521 -> V_515 ) ;
V_133 = F_244 ( V_521 -> V_133 ) ;
F_21 ( L_66 , V_515 , V_133 ) ;
V_14 = F_8 ( V_3 , V_515 ) ;
if ( ! V_14 ) {
F_274 ( V_3 , V_390 -> V_9 , V_515 ) ;
return 0 ;
}
if ( V_14 -> V_165 == V_533 ) {
if ( V_133 == V_532 ) {
V_14 -> V_411 = V_14 -> V_412 ;
if ( ! V_14 -> V_411 )
F_275 ( V_14 ) ;
} else {
V_14 -> V_412 = V_14 -> V_411 ;
}
F_123 ( V_14 ) ;
}
F_274 ( V_3 , V_390 -> V_9 , V_515 ) ;
F_50 ( V_14 ) ;
return 0 ;
}
static inline int F_291 ( struct V_2 * V_3 ,
struct V_389 * V_390 ,
T_1 V_468 , void * V_156 )
{
struct V_524 * V_132 = V_156 ;
struct V_1 * V_14 ;
T_1 V_515 ;
if ( V_468 != sizeof( * V_132 ) )
return - V_471 ;
V_515 = F_244 ( V_132 -> V_515 ) ;
F_21 ( L_60 , V_515 ) ;
V_14 = F_4 ( V_3 , V_515 ) ;
if ( ! V_14 )
return 0 ;
F_71 ( V_14 ) ;
if ( V_14 -> V_165 == V_531 ) {
V_14 -> V_411 = V_14 -> V_412 ;
if ( ! V_14 -> V_411 && V_14 -> V_116 )
F_275 ( V_14 ) ;
F_123 ( V_14 ) ;
}
F_50 ( V_14 ) ;
return 0 ;
}
static inline int F_292 ( T_1 V_547 , T_1 V_548 , T_1 V_549 ,
T_1 V_550 )
{
T_1 V_551 ;
if ( V_547 > V_548 || V_547 < 6 || V_548 > 3200 )
return - V_20 ;
if ( V_550 < 10 || V_550 > 3200 )
return - V_20 ;
if ( V_548 >= V_550 * 8 )
return - V_20 ;
V_551 = ( V_550 * 8 / V_548 ) - 1 ;
if ( V_549 > 499 || V_549 > V_551 )
return - V_20 ;
return 0 ;
}
static inline int F_293 ( struct V_2 * V_3 ,
struct V_389 * V_390 ,
T_2 * V_156 )
{
struct V_168 * V_88 = V_3 -> V_88 ;
struct F_293 * V_235 ;
struct V_552 V_132 ;
T_1 V_547 , V_548 , V_549 , V_550 , V_468 ;
int V_15 ;
if ( ! ( V_88 -> V_553 & V_554 ) )
return - V_20 ;
V_468 = F_67 ( V_390 -> V_155 ) ;
if ( V_468 != sizeof( struct F_293 ) )
return - V_471 ;
V_235 = (struct F_293 * ) V_156 ;
V_547 = F_67 ( V_235 -> V_547 ) ;
V_548 = F_67 ( V_235 -> V_548 ) ;
V_549 = F_67 ( V_235 -> V_549 ) ;
V_550 = F_67 ( V_235 -> V_550 ) ;
F_21 ( L_67 ,
V_547 , V_548 , V_549 , V_550 ) ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_15 = F_292 ( V_547 , V_548 , V_549 , V_550 ) ;
if ( V_15 )
V_132 . V_133 = F_80 ( V_555 ) ;
else
V_132 . V_133 = F_80 ( V_556 ) ;
F_81 ( V_3 , V_390 -> V_9 , V_557 ,
sizeof( V_132 ) , & V_132 ) ;
if ( ! V_15 )
F_294 ( V_88 , V_547 , V_548 , V_549 , V_550 ) ;
return 0 ;
}
static inline int F_295 ( struct V_2 * V_3 ,
struct V_389 * V_390 , T_1 V_468 ,
T_2 * V_156 )
{
int V_15 = 0 ;
switch ( V_390 -> V_154 ) {
case V_487 :
F_251 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
case V_236 :
V_15 = F_255 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
case V_140 :
case V_466 :
V_15 = F_257 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
case V_285 :
V_15 = F_260 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
case V_483 :
V_15 = F_261 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
case V_274 :
V_15 = F_263 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
case V_495 :
V_15 = F_264 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
case V_558 :
F_81 ( V_3 , V_390 -> V_9 , V_559 , V_468 , V_156 ) ;
break;
case V_559 :
break;
case V_266 :
V_15 = F_265 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
case V_500 :
V_15 = F_266 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
case V_239 :
V_15 = F_267 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
case V_516 :
V_15 = F_286 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
case V_519 :
V_15 = F_289 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
case V_522 :
V_15 = F_290 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
case V_525 :
V_15 = F_291 ( V_3 , V_390 , V_468 , V_156 ) ;
break;
default:
F_296 ( L_68 , V_390 -> V_154 ) ;
V_15 = - V_20 ;
break;
}
return V_15 ;
}
static inline int F_297 ( struct V_2 * V_3 ,
struct V_389 * V_390 , T_2 * V_156 )
{
switch ( V_390 -> V_154 ) {
case V_487 :
return 0 ;
case V_560 :
return F_293 ( V_3 , V_390 , V_156 ) ;
case V_557 :
return 0 ;
default:
F_296 ( L_69 , V_390 -> V_154 ) ;
return - V_20 ;
}
}
static inline void F_298 ( struct V_2 * V_3 ,
struct V_32 * V_36 )
{
T_2 * V_156 = V_36 -> V_156 ;
int V_155 = V_36 -> V_155 ;
struct V_389 V_390 ;
int V_15 ;
F_228 ( V_3 , V_36 ) ;
while ( V_155 >= V_391 ) {
T_1 V_468 ;
memcpy ( & V_390 , V_156 , V_391 ) ;
V_156 += V_391 ;
V_155 -= V_391 ;
V_468 = F_244 ( V_390 . V_155 ) ;
F_21 ( L_70 , V_390 . V_154 , V_468 ,
V_390 . V_9 ) ;
if ( V_468 > V_155 || ! V_390 . V_9 ) {
F_21 ( L_71 ) ;
break;
}
V_15 = F_297 ( V_3 , & V_390 , V_156 ) ;
if ( V_15 ) {
struct V_469 V_470 ;
F_296 ( L_72 , V_15 ) ;
V_470 . V_55 = F_80 ( V_472 ) ;
F_81 ( V_3 , V_390 . V_9 , V_487 ,
sizeof( V_470 ) , & V_470 ) ;
}
V_156 += V_468 ;
V_155 -= V_468 ;
}
F_93 ( V_36 ) ;
}
static inline void F_299 ( struct V_2 * V_3 ,
struct V_32 * V_36 )
{
T_2 * V_156 = V_36 -> V_156 ;
int V_155 = V_36 -> V_155 ;
struct V_389 V_390 ;
int V_15 ;
F_228 ( V_3 , V_36 ) ;
while ( V_155 >= V_391 ) {
T_1 V_468 ;
memcpy ( & V_390 , V_156 , V_391 ) ;
V_156 += V_391 ;
V_155 -= V_391 ;
V_468 = F_244 ( V_390 . V_155 ) ;
F_21 ( L_70 , V_390 . V_154 , V_468 ,
V_390 . V_9 ) ;
if ( V_468 > V_155 || ! V_390 . V_9 ) {
F_21 ( L_71 ) ;
break;
}
V_15 = F_295 ( V_3 , & V_390 , V_468 , V_156 ) ;
if ( V_15 ) {
struct V_469 V_470 ;
F_296 ( L_72 , V_15 ) ;
V_470 . V_55 = F_80 ( V_472 ) ;
F_81 ( V_3 , V_390 . V_9 , V_487 ,
sizeof( V_470 ) , & V_470 ) ;
}
V_156 += V_468 ;
V_155 -= V_468 ;
}
F_93 ( V_36 ) ;
}
static int F_300 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
T_1 V_561 , V_562 ;
int V_563 ;
if ( F_74 ( V_207 , & V_14 -> V_83 ) )
V_563 = V_212 ;
else
V_563 = V_213 ;
if ( V_14 -> V_73 == V_74 ) {
F_301 ( V_36 , V_36 -> V_155 - V_217 ) ;
V_562 = F_99 ( V_36 -> V_156 + V_36 -> V_155 ) ;
V_561 = F_110 ( 0 , V_36 -> V_156 - V_563 , V_36 -> V_155 + V_563 ) ;
if ( V_561 != V_562 )
return - V_564 ;
}
return 0 ;
}
static void F_302 ( struct V_1 * V_14 )
{
struct V_173 V_37 ;
F_21 ( L_3 , V_14 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_181 = 1 ;
V_37 . V_177 = 1 ;
V_37 . V_174 = V_14 -> V_227 ;
F_58 ( V_219 , & V_14 -> V_220 ) ;
if ( F_74 ( V_226 , & V_14 -> V_220 ) ) {
V_37 . V_185 = V_223 ;
F_111 ( V_14 , & V_37 ) ;
}
if ( F_112 ( V_249 , & V_14 -> V_220 ) &&
V_14 -> V_333 > 0 )
F_28 ( V_14 ) ;
F_189 ( V_14 ) ;
if ( ! F_74 ( V_226 , & V_14 -> V_220 ) &&
F_74 ( V_219 , & V_14 -> V_220 ) ) {
V_37 . V_185 = V_221 ;
F_111 ( V_14 , & V_37 ) ;
}
}
static void F_303 ( struct V_32 * V_36 , struct V_32 * V_565 ,
struct V_32 * * V_566 )
{
if ( ! F_304 ( V_36 ) )
F_205 ( V_36 ) -> V_354 = V_565 ;
V_565 -> V_306 = NULL ;
( * V_566 ) -> V_306 = V_565 ;
* V_566 = V_565 ;
V_36 -> V_155 += V_565 -> V_155 ;
V_36 -> V_358 += V_565 -> V_155 ;
V_36 -> V_567 += V_565 -> V_567 ;
}
static int F_305 ( struct V_1 * V_14 , struct V_32 * V_36 ,
struct V_173 * V_37 )
{
int V_15 = - V_20 ;
switch ( V_37 -> V_188 ) {
case V_367 :
if ( V_14 -> V_409 )
break;
V_15 = V_14 -> V_24 -> V_387 ( V_14 , V_36 ) ;
break;
case V_368 :
if ( V_14 -> V_409 )
break;
V_14 -> V_363 = F_99 ( V_36 -> V_156 ) ;
F_98 ( V_36 , V_361 ) ;
if ( V_14 -> V_363 > V_14 -> V_98 ) {
V_15 = - V_371 ;
break;
}
if ( V_36 -> V_155 >= V_14 -> V_363 )
break;
V_14 -> V_409 = V_36 ;
V_14 -> V_410 = V_36 ;
V_36 = NULL ;
V_15 = 0 ;
break;
case V_370 :
if ( ! V_14 -> V_409 )
break;
F_303 ( V_14 -> V_409 , V_36 ,
& V_14 -> V_410 ) ;
V_36 = NULL ;
if ( V_14 -> V_409 -> V_155 >= V_14 -> V_363 )
break;
V_15 = 0 ;
break;
case V_369 :
if ( ! V_14 -> V_409 )
break;
F_303 ( V_14 -> V_409 , V_36 ,
& V_14 -> V_410 ) ;
V_36 = NULL ;
if ( V_14 -> V_409 -> V_155 != V_14 -> V_363 )
break;
V_15 = V_14 -> V_24 -> V_387 ( V_14 , V_14 -> V_409 ) ;
if ( ! V_15 ) {
V_14 -> V_409 = NULL ;
V_14 -> V_410 = NULL ;
V_14 -> V_363 = 0 ;
}
break;
}
if ( V_15 ) {
F_93 ( V_36 ) ;
F_93 ( V_14 -> V_409 ) ;
V_14 -> V_409 = NULL ;
V_14 -> V_410 = NULL ;
V_14 -> V_363 = 0 ;
}
return V_15 ;
}
static int F_306 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_307 ( struct V_1 * V_14 , int V_568 )
{
T_2 V_377 ;
if ( V_14 -> V_119 != V_121 )
return;
V_377 = V_568 ? V_378 : V_380 ;
F_124 ( V_14 , NULL , NULL , V_377 ) ;
}
static int F_308 ( struct V_1 * V_14 )
{
int V_15 = 0 ;
F_21 ( L_3 , V_14 ) ;
while ( ! F_74 ( V_226 , & V_14 -> V_220 ) ) {
struct V_32 * V_36 ;
F_21 ( L_73 ,
V_14 -> V_227 , F_193 ( & V_14 -> V_122 ) ) ;
V_36 = F_34 ( & V_14 -> V_122 , V_14 -> V_227 ) ;
if ( ! V_36 )
break;
F_221 ( V_36 , & V_14 -> V_122 ) ;
V_14 -> V_227 = F_188 ( V_14 , V_14 -> V_227 ) ;
V_15 = F_305 ( V_14 , V_36 , & F_36 ( V_36 ) -> V_37 ) ;
if ( V_15 )
break;
}
if ( F_186 ( & V_14 -> V_122 ) ) {
V_14 -> V_247 = V_347 ;
F_200 ( V_14 ) ;
}
return V_15 ;
}
static void F_309 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
struct V_32 * V_36 ;
F_21 ( L_11 , V_14 , V_37 ) ;
if ( V_37 -> V_174 == V_14 -> V_338 ) {
F_21 ( L_74 , V_37 -> V_174 ) ;
F_79 ( V_14 , V_277 ) ;
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
F_79 ( V_14 , V_277 ) ;
return;
}
F_113 ( V_249 , & V_14 -> V_220 ) ;
if ( V_37 -> V_182 ) {
F_226 ( V_14 , V_37 ) ;
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_197 ( V_14 , V_37 ) ;
F_189 ( V_14 ) ;
if ( V_14 -> V_245 == V_382 ) {
F_58 ( V_244 , & V_14 -> V_220 ) ;
V_14 -> V_569 = V_37 -> V_174 ;
}
} else {
F_227 ( V_14 , V_37 ) ;
if ( V_37 -> V_177 ) {
if ( V_14 -> V_569 != V_37 -> V_174 ||
! F_112 ( V_244 ,
& V_14 -> V_220 ) )
F_197 ( V_14 , V_37 ) ;
} else {
F_197 ( V_14 , V_37 ) ;
if ( V_14 -> V_245 == V_382 ) {
F_58 ( V_244 , & V_14 -> V_220 ) ;
V_14 -> V_569 = V_37 -> V_174 ;
}
}
}
}
static void F_310 ( struct V_1 * V_14 ,
struct V_173 * V_37 )
{
struct V_32 * V_36 ;
F_21 ( L_11 , V_14 , V_37 ) ;
if ( V_37 -> V_174 == V_14 -> V_338 ) {
F_21 ( L_74 , V_37 -> V_174 ) ;
F_79 ( V_14 , V_277 ) ;
return;
}
V_36 = F_34 ( & V_14 -> V_126 , V_37 -> V_174 ) ;
if ( V_14 -> V_75 && V_36 &&
F_36 ( V_36 ) -> V_37 . V_241 >= V_14 -> V_75 ) {
F_21 ( L_24 , V_14 -> V_75 ) ;
F_79 ( V_14 , V_277 ) ;
return;
}
F_113 ( V_249 , & V_14 -> V_220 ) ;
F_226 ( V_14 , V_37 ) ;
if ( V_37 -> V_177 ) {
if ( ! F_112 ( V_243 , & V_14 -> V_220 ) )
F_198 ( V_14 , V_37 ) ;
} else {
F_198 ( V_14 , V_37 ) ;
F_189 ( V_14 ) ;
if ( V_14 -> V_245 == V_382 )
F_58 ( V_243 , & V_14 -> V_220 ) ;
}
}
static T_2 F_311 ( struct V_1 * V_14 , T_1 V_38 )
{
F_21 ( L_76 , V_14 , V_38 ) ;
F_21 ( L_77 , V_14 -> V_225 ,
V_14 -> V_242 ) ;
if ( V_14 -> V_247 == V_379 ) {
if ( F_201 ( V_14 , V_38 , V_14 -> V_225 ) >=
V_14 -> V_77 ) {
if ( V_14 -> V_77 <= ( ( V_14 -> V_79 + 1 ) >> 1 ) ) {
F_21 ( L_78 ) ;
return V_570 ;
} else {
F_21 ( L_79 ) ;
return V_571 ;
}
}
if ( V_14 -> V_123 . V_34 == V_38 ) {
F_21 ( L_80 ) ;
return V_572 ;
}
if ( F_34 ( & V_14 -> V_122 , V_38 ) ) {
F_21 ( L_81 ) ;
return V_573 ;
}
if ( F_42 ( & V_14 -> V_123 , V_38 ) ) {
F_21 ( L_82 ) ;
return V_574 ;
}
}
if ( V_14 -> V_242 == V_38 ) {
if ( F_201 ( V_14 , V_38 , V_14 -> V_225 ) >=
V_14 -> V_77 ) {
F_21 ( L_83 ) ;
return V_571 ;
} else {
F_21 ( L_84 ) ;
return V_575 ;
}
}
if ( F_201 ( V_14 , V_38 , V_14 -> V_225 ) <
F_201 ( V_14 , V_14 -> V_242 , V_14 -> V_225 ) ) {
F_21 ( L_85 ) ;
return V_576 ;
}
if ( F_201 ( V_14 , V_38 , V_14 -> V_225 ) >= V_14 -> V_77 ) {
if ( V_14 -> V_77 <= ( ( V_14 -> V_79 + 1 ) >> 1 ) ) {
F_21 ( L_86 ) ;
return V_570 ;
} else {
F_21 ( L_83 ) ;
return V_571 ;
}
} else {
F_21 ( L_87 ) ;
return V_577 ;
}
}
static int F_312 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_377 )
{
int V_15 = 0 ;
bool V_578 = 0 ;
F_21 ( L_88 , V_14 , V_37 , V_36 ,
V_377 ) ;
switch ( V_377 ) {
case V_579 :
switch ( F_311 ( V_14 , V_37 -> V_38 ) ) {
case V_575 :
F_226 ( V_14 , V_37 ) ;
if ( F_74 ( V_226 , & V_14 -> V_220 ) ) {
F_21 ( L_89 ,
V_37 -> V_38 ) ;
break;
}
V_14 -> V_242 = F_188 ( V_14 ,
V_37 -> V_38 ) ;
V_14 -> V_227 = V_14 -> V_242 ;
V_578 = 1 ;
V_15 = F_305 ( V_14 , V_36 , V_37 ) ;
if ( V_15 )
break;
if ( V_37 -> V_177 ) {
if ( ! F_112 ( V_243 ,
& V_14 -> V_220 ) ) {
V_37 -> V_177 = 0 ;
F_198 ( V_14 , V_37 ) ;
F_189 ( V_14 ) ;
}
}
if ( ! F_74 ( V_226 , & V_14 -> V_220 ) )
F_200 ( V_14 ) ;
break;
case V_577 :
F_226 ( V_14 , V_37 ) ;
if ( F_74 ( V_226 , & V_14 -> V_220 ) ) {
F_21 ( L_90 ,
V_37 -> V_38 ) ;
break;
}
F_313 ( & V_14 -> V_122 , V_36 ) ;
V_578 = 1 ;
F_21 ( L_91 , V_36 ,
F_193 ( & V_14 -> V_122 ) ) ;
F_113 ( V_244 , & V_14 -> V_220 ) ;
F_45 ( & V_14 -> V_123 ) ;
F_217 ( V_14 , V_37 -> V_38 ) ;
V_14 -> V_247 = V_379 ;
break;
case V_576 :
F_226 ( V_14 , V_37 ) ;
break;
case V_570 :
break;
case V_571 :
default:
F_79 ( V_14 , V_277 ) ;
break;
}
break;
case V_580 :
F_226 ( V_14 , V_37 ) ;
if ( V_37 -> V_177 ) {
F_113 ( V_249 , & V_14 -> V_220 ) ;
if ( ! F_112 ( V_243 , & V_14 -> V_220 ) &&
! F_91 ( V_14 ) ) {
V_37 -> V_177 = 0 ;
F_198 ( V_14 , V_37 ) ;
}
F_189 ( V_14 ) ;
} else if ( V_37 -> V_182 ) {
F_302 ( V_14 ) ;
} else {
if ( F_112 ( V_249 ,
& V_14 -> V_220 ) &&
V_14 -> V_333 )
F_28 ( V_14 ) ;
F_189 ( V_14 ) ;
}
break;
case V_581 :
F_58 ( V_249 , & V_14 -> V_220 ) ;
F_226 ( V_14 , V_37 ) ;
if ( V_37 && V_37 -> V_182 ) {
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_115 ( V_14 , 0 ) ;
}
F_33 ( V_14 ) ;
F_45 ( & V_14 -> V_124 ) ;
break;
case V_582 :
F_310 ( V_14 , V_37 ) ;
break;
case V_583 :
F_309 ( V_14 , V_37 ) ;
break;
default:
break;
}
if ( V_36 && ! V_578 ) {
F_21 ( L_92 , V_36 ) ;
F_93 ( V_36 ) ;
}
return V_15 ;
}
static int F_314 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_377 )
{
int V_15 = 0 ;
T_1 V_38 = V_37 -> V_38 ;
bool V_578 = 0 ;
F_21 ( L_88 , V_14 , V_37 , V_36 ,
V_377 ) ;
switch ( V_377 ) {
case V_579 :
switch ( F_311 ( V_14 , V_38 ) ) {
case V_575 :
F_226 ( V_14 , V_37 ) ;
F_313 ( & V_14 -> V_122 , V_36 ) ;
V_578 = 1 ;
F_21 ( L_91 , V_36 ,
F_193 ( & V_14 -> V_122 ) ) ;
V_14 -> V_242 = F_188 ( V_14 , V_38 ) ;
break;
case V_572 :
F_44 ( & V_14 -> V_123 ) ;
F_226 ( V_14 , V_37 ) ;
F_313 ( & V_14 -> V_122 , V_36 ) ;
V_578 = 1 ;
F_21 ( L_91 , V_36 ,
F_193 ( & V_14 -> V_122 ) ) ;
V_15 = F_308 ( V_14 ) ;
if ( V_15 )
break;
break;
case V_577 :
F_313 ( & V_14 -> V_122 , V_36 ) ;
V_578 = 1 ;
F_21 ( L_91 , V_36 ,
F_193 ( & V_14 -> V_122 ) ) ;
F_226 ( V_14 , V_37 ) ;
F_217 ( V_14 , V_37 -> V_38 ) ;
break;
case V_574 :
F_313 ( & V_14 -> V_122 , V_36 ) ;
V_578 = 1 ;
F_21 ( L_91 , V_36 ,
F_193 ( & V_14 -> V_122 ) ) ;
F_226 ( V_14 , V_37 ) ;
F_219 ( V_14 , V_37 -> V_38 ) ;
break;
case V_573 :
F_226 ( V_14 , V_37 ) ;
break;
case V_576 :
break;
case V_570 :
break;
case V_571 :
default:
F_79 ( V_14 , V_277 ) ;
break;
}
break;
case V_580 :
F_226 ( V_14 , V_37 ) ;
if ( V_37 -> V_177 ) {
F_113 ( V_249 , & V_14 -> V_220 ) ;
if ( ! F_112 ( V_243 ,
& V_14 -> V_220 ) ) {
V_37 -> V_177 = 0 ;
F_198 ( V_14 , V_37 ) ;
}
F_189 ( V_14 ) ;
} else if ( V_37 -> V_182 ) {
if ( F_112 ( V_249 ,
& V_14 -> V_220 ) &&
V_14 -> V_333 ) {
F_28 ( V_14 ) ;
}
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_218 ( V_14 ) ;
} else {
if ( F_112 ( V_249 ,
& V_14 -> V_220 ) &&
V_14 -> V_333 )
F_28 ( V_14 ) ;
F_200 ( V_14 ) ;
}
break;
case V_581 :
F_58 ( V_249 , & V_14 -> V_220 ) ;
F_226 ( V_14 , V_37 ) ;
if ( V_37 -> V_182 ) {
F_218 ( V_14 ) ;
} else {
struct V_173 V_584 ;
memset ( & V_584 , 0 , sizeof( V_584 ) ) ;
V_584 . V_181 = 1 ;
V_584 . V_185 = V_221 ;
V_584 . V_174 = V_14 -> V_227 ;
F_111 ( V_14 , & V_584 ) ;
}
break;
case V_582 :
F_310 ( V_14 , V_37 ) ;
break;
case V_583 :
F_309 ( V_14 , V_37 ) ;
break;
}
if ( V_36 && ! V_578 ) {
F_21 ( L_92 , V_36 ) ;
F_93 ( V_36 ) ;
}
return V_15 ;
}
static int F_315 ( struct V_1 * V_14 )
{
F_21 ( L_3 , V_14 ) ;
V_14 -> V_247 = V_347 ;
if ( V_14 -> V_169 )
V_14 -> V_3 -> V_318 = V_14 -> V_169 -> V_157 -> V_511 ;
else
V_14 -> V_3 -> V_318 = V_14 -> V_3 -> V_88 -> V_157 -> V_319 ;
return F_306 ( V_14 ) ;
}
static int F_316 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_377 )
{
int V_15 ;
F_21 ( L_88 , V_14 , V_37 , V_36 ,
V_377 ) ;
if ( ! V_37 -> V_182 )
return - V_471 ;
F_220 ( V_14 , V_37 -> V_174 ) ;
if ( ! F_186 ( & V_14 -> V_126 ) )
V_14 -> V_343 = F_224 ( & V_14 -> V_126 ) ;
else
V_14 -> V_343 = NULL ;
V_14 -> V_338 = V_37 -> V_174 ;
V_14 -> V_333 = 0 ;
V_15 = F_315 ( V_14 ) ;
if ( V_15 )
return V_15 ;
F_58 ( V_219 , & V_14 -> V_220 ) ;
F_302 ( V_14 ) ;
if ( V_377 == V_579 )
return - V_471 ;
return F_312 ( V_14 , V_37 , NULL , V_377 ) ;
}
static int F_317 ( struct V_1 * V_14 ,
struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_377 )
{
int V_15 ;
if ( ! V_37 -> V_177 )
return - V_471 ;
F_113 ( V_249 , & V_14 -> V_220 ) ;
V_14 -> V_247 = V_347 ;
F_220 ( V_14 , V_37 -> V_174 ) ;
if ( ! F_186 ( & V_14 -> V_126 ) )
V_14 -> V_343 = F_224 ( & V_14 -> V_126 ) ;
else
V_14 -> V_343 = NULL ;
V_14 -> V_338 = V_37 -> V_174 ;
V_14 -> V_333 = 0 ;
if ( V_14 -> V_169 )
V_14 -> V_3 -> V_318 = V_14 -> V_169 -> V_157 -> V_511 ;
else
V_14 -> V_3 -> V_318 = V_14 -> V_3 -> V_88 -> V_157 -> V_319 ;
V_15 = F_306 ( V_14 ) ;
if ( ! V_15 )
V_15 = F_312 ( V_14 , V_37 , V_36 , V_377 ) ;
return V_15 ;
}
static bool F_318 ( struct V_1 * V_14 , T_1 V_174 )
{
T_1 V_585 ;
V_585 = F_201 ( V_14 , V_14 -> V_338 , V_14 -> V_376 ) ;
return F_201 ( V_14 , V_14 -> V_338 , V_174 ) <= V_585 ;
}
static int F_319 ( struct V_1 * V_14 , struct V_173 * V_37 ,
struct V_32 * V_36 , T_2 V_377 )
{
int V_15 = 0 ;
F_21 ( L_93 , V_14 ,
V_37 , V_36 , V_377 , V_14 -> V_247 ) ;
if ( F_318 ( V_14 , V_37 -> V_174 ) ) {
switch ( V_14 -> V_247 ) {
case V_347 :
V_15 = F_312 ( V_14 , V_37 , V_36 , V_377 ) ;
break;
case V_379 :
V_15 = F_314 ( V_14 , V_37 , V_36 ,
V_377 ) ;
break;
case V_256 :
V_15 = F_316 ( V_14 , V_37 , V_36 , V_377 ) ;
break;
case V_254 :
V_15 = F_317 ( V_14 , V_37 , V_36 , V_377 ) ;
break;
default:
break;
}
} else {
F_21 ( L_94 ,
V_37 -> V_174 , V_14 -> V_338 ,
V_14 -> V_376 ) ;
F_79 ( V_14 , V_277 ) ;
}
return V_15 ;
}
static int F_320 ( struct V_1 * V_14 , struct V_173 * V_37 ,
struct V_32 * V_36 )
{
int V_15 = 0 ;
F_21 ( L_95 , V_14 , V_37 , V_36 ,
V_14 -> V_247 ) ;
if ( F_311 ( V_14 , V_37 -> V_38 ) ==
V_575 ) {
F_226 ( V_14 , V_37 ) ;
F_21 ( L_96 , V_14 -> V_227 ,
F_188 ( V_14 , V_14 -> V_227 ) ) ;
V_14 -> V_227 = F_188 ( V_14 , V_14 -> V_227 ) ;
F_305 ( V_14 , V_36 , V_37 ) ;
} else {
if ( V_14 -> V_409 ) {
F_93 ( V_14 -> V_409 ) ;
V_14 -> V_409 = NULL ;
}
V_14 -> V_410 = NULL ;
V_14 -> V_363 = 0 ;
if ( V_36 ) {
F_21 ( L_92 , V_36 ) ;
F_93 ( V_36 ) ;
}
}
V_14 -> V_225 = V_37 -> V_38 ;
V_14 -> V_242 = F_188 ( V_14 , V_37 -> V_38 ) ;
return V_15 ;
}
static int F_321 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
struct V_173 * V_37 = & F_36 ( V_36 ) -> V_37 ;
T_1 V_155 ;
T_2 V_377 ;
F_96 ( V_14 , V_36 ) ;
V_155 = V_36 -> V_155 ;
if ( F_300 ( V_14 , V_36 ) )
goto V_586;
if ( ! V_37 -> V_181 && V_37 -> V_188 == V_368 )
V_155 -= V_361 ;
if ( V_14 -> V_73 == V_74 )
V_155 -= V_217 ;
if ( V_155 > V_14 -> V_464 ) {
F_79 ( V_14 , V_277 ) ;
goto V_586;
}
if ( ! V_37 -> V_181 ) {
int V_15 ;
F_21 ( L_97 ,
V_37 -> V_188 , V_37 -> V_174 , V_37 -> V_177 ,
V_37 -> V_38 ) ;
if ( V_37 -> V_177 && V_14 -> V_245 != V_382 )
goto V_586;
if ( V_14 -> V_119 != V_125 ) {
V_377 = V_579 ;
V_15 = F_319 ( V_14 , V_37 , V_36 , V_377 ) ;
} else {
V_15 = F_320 ( V_14 , V_37 , V_36 ) ;
}
if ( V_15 )
F_79 ( V_14 , V_277 ) ;
} else {
const T_2 V_587 [ 4 ] = {
V_580 , V_582 ,
V_581 , V_583
} ;
if ( V_14 -> V_119 == V_125 )
goto V_586;
F_21 ( L_98 ,
V_37 -> V_174 , V_37 -> V_177 , V_37 -> V_182 ,
V_37 -> V_185 ) ;
if ( V_155 != 0 ) {
F_296 ( L_99 , V_155 ) ;
F_79 ( V_14 , V_277 ) ;
goto V_586;
}
if ( V_37 -> V_177 && ( V_37 -> V_182 ||
V_14 -> V_245 != V_382 ) )
goto V_586;
V_377 = V_587 [ V_37 -> V_185 ] ;
if ( F_319 ( V_14 , V_37 , V_36 , V_377 ) )
F_79 ( V_14 , V_277 ) ;
}
return 0 ;
V_586:
F_93 ( V_36 ) ;
return 0 ;
}
static void F_322 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_4 ( V_3 , V_4 ) ;
if ( ! V_14 ) {
if ( V_4 == V_96 ) {
V_14 = F_323 ( V_3 , V_36 ) ;
if ( ! V_14 ) {
F_93 ( V_36 ) ;
return;
}
F_6 ( V_14 ) ;
} else {
F_21 ( L_100 , V_4 ) ;
F_93 ( V_36 ) ;
return;
}
}
F_21 ( L_101 , V_14 , V_36 -> V_155 ) ;
if ( V_14 -> V_23 != V_56 )
goto V_586;
switch ( V_14 -> V_119 ) {
case V_120 :
if ( V_14 -> V_98 < V_36 -> V_155 )
goto V_586;
if ( ! V_14 -> V_24 -> V_387 ( V_14 , V_36 ) )
goto V_18;
break;
case V_121 :
case V_125 :
F_321 ( V_14 , V_36 ) ;
goto V_18;
default:
F_21 ( L_102 , V_14 , V_14 -> V_119 ) ;
break;
}
V_586:
F_93 ( V_36 ) ;
V_18:
F_50 ( V_14 ) ;
}
static void F_324 ( struct V_2 * V_3 , T_3 V_10 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_164 ( 0 , V_10 , V_3 -> V_11 , V_3 -> V_287 ) ;
if ( ! V_14 )
goto V_586;
F_21 ( L_101 , V_14 , V_36 -> V_155 ) ;
if ( V_14 -> V_23 != V_325 && V_14 -> V_23 != V_56 )
goto V_586;
if ( V_14 -> V_98 < V_36 -> V_155 )
goto V_586;
if ( ! V_14 -> V_24 -> V_387 ( V_14 , V_36 ) )
return;
V_586:
F_93 ( V_36 ) ;
}
static void F_325 ( struct V_2 * V_3 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_134 ( V_56 , V_92 ,
V_3 -> V_11 , V_3 -> V_287 ) ;
if ( ! V_14 )
goto V_586;
F_21 ( L_101 , V_14 , V_36 -> V_155 ) ;
if ( V_14 -> V_98 < V_36 -> V_155 )
goto V_586;
if ( ! V_14 -> V_24 -> V_387 ( V_14 , V_36 ) )
return;
V_586:
F_93 ( V_36 ) ;
}
static void F_326 ( struct V_2 * V_3 , struct V_32 * V_36 )
{
struct V_214 * V_215 = ( void * ) V_36 -> V_156 ;
T_1 V_4 , V_155 ;
T_3 V_10 ;
F_98 ( V_36 , V_211 ) ;
V_4 = F_67 ( V_215 -> V_4 ) ;
V_155 = F_67 ( V_215 -> V_155 ) ;
if ( V_155 != V_36 -> V_155 ) {
F_93 ( V_36 ) ;
return;
}
F_21 ( L_103 , V_155 , V_4 ) ;
switch ( V_4 ) {
case V_392 :
F_298 ( V_3 , V_36 ) ;
break;
case V_99 :
F_299 ( V_3 , V_36 ) ;
break;
case V_94 :
V_10 = F_327 ( ( T_3 * ) V_36 -> V_156 ) ;
F_98 ( V_36 , V_359 ) ;
F_324 ( V_3 , V_10 , V_36 ) ;
break;
case V_92 :
F_325 ( V_3 , V_36 ) ;
break;
case V_588 :
if ( F_328 ( V_3 , V_36 ) )
F_150 ( V_3 -> V_88 , V_589 ) ;
break;
default:
F_322 ( V_3 , V_4 , V_36 ) ;
break;
}
}
int F_329 ( struct V_304 * V_157 , T_4 * V_320 )
{
int V_590 = 0 , V_591 = 0 , V_592 = 0 ;
struct V_1 * V_5 ;
F_21 ( L_104 , V_157 -> V_593 , V_320 ) ;
F_135 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
if ( V_5 -> V_23 != V_127 )
continue;
if ( ! F_12 ( & F_13 ( V_13 ) -> V_11 , & V_157 -> V_320 ) ) {
V_591 |= V_594 ;
if ( F_74 ( V_595 , & V_5 -> V_83 ) )
V_591 |= V_554 ;
V_590 ++ ;
} else if ( ! F_12 ( & F_13 ( V_13 ) -> V_11 , V_293 ) ) {
V_592 |= V_594 ;
if ( F_74 ( V_595 , & V_5 -> V_83 ) )
V_592 |= V_554 ;
}
}
F_136 ( & V_16 ) ;
return V_590 ? V_591 : V_592 ;
}
void F_330 ( struct V_168 * V_88 , T_2 V_138 )
{
struct V_2 * V_3 ;
F_21 ( L_105 , V_88 , & V_88 -> V_287 , V_138 ) ;
if ( ! V_138 ) {
V_3 = F_156 ( V_88 ) ;
if ( V_3 )
F_139 ( V_3 ) ;
} else {
F_150 ( V_88 , F_331 ( V_138 ) ) ;
}
}
int F_332 ( struct V_168 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_311 ;
F_21 ( L_106 , V_88 ) ;
if ( ! V_3 )
return V_85 ;
return V_3 -> V_84 ;
}
void F_333 ( struct V_168 * V_88 , T_2 V_55 )
{
F_21 ( L_107 , V_88 , V_55 ) ;
F_150 ( V_88 , F_331 ( V_55 ) ) ;
}
static inline void F_334 ( struct V_1 * V_14 , T_2 V_596 )
{
if ( V_14 -> V_86 != V_87 )
return;
if ( V_596 == 0x00 ) {
if ( V_14 -> V_60 == V_144 ) {
F_78 ( V_14 , V_597 ) ;
} else if ( V_14 -> V_60 == V_142 )
F_49 ( V_14 , V_58 ) ;
} else {
if ( V_14 -> V_60 == V_144 )
F_71 ( V_14 ) ;
}
}
int F_335 ( struct V_168 * V_88 , T_2 V_138 , T_2 V_596 )
{
struct V_2 * V_3 = V_88 -> V_311 ;
struct V_1 * V_14 ;
if ( ! V_3 )
return 0 ;
F_21 ( L_108 , V_3 , V_138 , V_596 ) ;
if ( V_88 -> type == V_89 ) {
if ( ! V_138 && V_596 )
F_336 ( V_3 , 0 ) ;
F_252 ( & V_3 -> V_315 ) ;
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
if ( ! V_138 && V_596 ) {
V_14 -> V_60 = V_88 -> V_60 ;
F_125 ( V_14 ) ;
}
F_50 ( V_14 ) ;
continue;
}
if ( ! F_116 ( V_14 ) ) {
F_50 ( V_14 ) ;
continue;
}
if ( ! V_138 && ( V_14 -> V_23 == V_56 ||
V_14 -> V_23 == V_57 ) ) {
struct V_26 * V_13 = V_14 -> V_13 ;
F_113 ( V_598 , & F_13 ( V_13 ) -> V_83 ) ;
V_13 -> V_300 ( V_13 ) ;
F_334 ( V_14 , V_596 ) ;
F_50 ( V_14 ) ;
continue;
}
if ( V_14 -> V_23 == V_59 ) {
if ( ! V_138 ) {
F_126 ( V_14 ) ;
} else {
F_78 ( V_14 , V_599 ) ;
}
} else if ( V_14 -> V_23 == V_130 ) {
struct V_26 * V_13 = V_14 -> V_13 ;
struct V_131 V_132 ;
T_5 V_600 , V_601 ;
F_24 ( V_13 ) ;
if ( ! V_138 ) {
if ( F_74 ( V_134 ,
& F_13 ( V_13 ) -> V_83 ) ) {
V_600 = V_279 ;
V_601 = V_280 ;
V_14 -> V_24 -> V_281 ( V_14 ) ;
} else {
F_20 ( V_14 , V_57 ) ;
V_600 = V_282 ;
V_601 = V_139 ;
}
} else {
F_20 ( V_14 , V_137 ) ;
F_78 ( V_14 , V_599 ) ;
V_600 = V_135 ;
V_601 = V_139 ;
}
F_25 ( V_13 ) ;
V_132 . V_7 = F_16 ( V_14 -> V_6 ) ;
V_132 . V_6 = F_16 ( V_14 -> V_7 ) ;
V_132 . V_133 = F_16 ( V_600 ) ;
V_132 . V_138 = F_16 ( V_601 ) ;
F_81 ( V_3 , V_14 -> V_9 , V_140 ,
sizeof( V_132 ) , & V_132 ) ;
if ( ! F_74 ( V_284 , & V_14 -> V_71 ) &&
V_600 == V_282 ) {
char V_278 [ 128 ] ;
F_58 ( V_284 , & V_14 -> V_71 ) ;
F_81 ( V_3 , F_85 ( V_3 ) ,
V_285 ,
F_133 ( V_14 , V_278 ) ,
V_278 ) ;
V_14 -> V_286 ++ ;
}
}
F_50 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
int F_337 ( struct V_168 * V_88 , struct V_32 * V_36 , T_1 V_83 )
{
struct V_2 * V_3 = V_88 -> V_311 ;
struct V_214 * V_602 ;
int V_155 ;
if ( ! V_3 && V_88 -> V_157 -> V_507 != V_603 )
goto V_586;
if ( ! V_3 )
V_3 = F_156 ( V_88 ) ;
if ( ! V_3 )
goto V_586;
F_21 ( L_110 , V_3 , V_36 -> V_155 , V_83 ) ;
switch ( V_83 ) {
case V_159 :
case V_158 :
case V_170 :
if ( V_3 -> V_604 ) {
F_296 ( L_111 , V_36 -> V_155 ) ;
F_93 ( V_3 -> V_313 ) ;
V_3 -> V_313 = NULL ;
V_3 -> V_604 = 0 ;
F_141 ( V_3 , V_605 ) ;
}
if ( V_36 -> V_155 < V_211 ) {
F_296 ( L_112 , V_36 -> V_155 ) ;
F_141 ( V_3 , V_605 ) ;
goto V_586;
}
V_602 = (struct V_214 * ) V_36 -> V_156 ;
V_155 = F_67 ( V_602 -> V_155 ) + V_211 ;
if ( V_155 == V_36 -> V_155 ) {
F_326 ( V_3 , V_36 ) ;
return 0 ;
}
F_21 ( L_113 , V_155 , V_36 -> V_155 ) ;
if ( V_36 -> V_155 > V_155 ) {
F_296 ( L_114 ,
V_36 -> V_155 , V_155 ) ;
F_141 ( V_3 , V_605 ) ;
goto V_586;
}
V_3 -> V_313 = F_107 ( V_155 , V_45 ) ;
if ( ! V_3 -> V_313 )
goto V_586;
F_338 ( V_36 , F_109 ( V_3 -> V_313 , V_36 -> V_155 ) ,
V_36 -> V_155 ) ;
V_3 -> V_604 = V_155 - V_36 -> V_155 ;
break;
case V_606 :
F_21 ( L_115 , V_36 -> V_155 , V_3 -> V_604 ) ;
if ( ! V_3 -> V_604 ) {
F_296 ( L_116 , V_36 -> V_155 ) ;
F_141 ( V_3 , V_605 ) ;
goto V_586;
}
if ( V_36 -> V_155 > V_3 -> V_604 ) {
F_296 ( L_117 ,
V_36 -> V_155 , V_3 -> V_604 ) ;
F_93 ( V_3 -> V_313 ) ;
V_3 -> V_313 = NULL ;
V_3 -> V_604 = 0 ;
F_141 ( V_3 , V_605 ) ;
goto V_586;
}
F_338 ( V_36 , F_109 ( V_3 -> V_313 , V_36 -> V_155 ) ,
V_36 -> V_155 ) ;
V_3 -> V_604 -= V_36 -> V_155 ;
if ( ! V_3 -> V_604 ) {
F_326 ( V_3 , V_3 -> V_313 ) ;
V_3 -> V_313 = NULL ;
}
break;
}
V_586:
F_93 ( V_36 ) ;
return 0 ;
}
static int F_339 ( struct V_607 * V_608 , void * V_19 )
{
struct V_1 * V_5 ;
F_135 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
F_340 ( V_608 , L_118 ,
& F_13 ( V_13 ) -> V_11 , & F_13 ( V_13 ) -> V_287 ,
V_5 -> V_23 , F_67 ( V_5 -> V_10 ) ,
V_5 -> V_7 , V_5 -> V_6 , V_5 -> V_98 , V_5 -> V_90 ,
V_5 -> V_60 , V_5 -> V_119 ) ;
}
F_136 ( & V_16 ) ;
return 0 ;
}
static int F_341 ( struct V_609 * V_609 , struct V_610 * V_610 )
{
return F_342 ( V_610 , F_339 , V_609 -> V_611 ) ;
}
int T_11 F_343 ( void )
{
int V_15 ;
V_15 = F_344 () ;
if ( V_15 < 0 )
return V_15 ;
if ( V_612 ) {
V_613 = F_345 ( L_119 , 0444 , V_612 ,
NULL , & V_614 ) ;
if ( ! V_613 )
F_296 ( L_120 ) ;
}
return 0 ;
}
void F_346 ( void )
{
F_347 ( V_613 ) ;
F_348 () ;
}
