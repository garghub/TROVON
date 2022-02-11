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
V_20 -> V_14 = V_14 ;
F_17 ( & V_22 ) ;
return 0 ;
}
static T_2 F_19 ( struct V_9 * V_10 )
{
T_2 V_11 , V_27 ;
if ( V_10 -> V_2 -> type == V_3 )
V_27 = V_28 ;
else
V_27 = V_29 ;
for ( V_11 = V_30 ; V_11 < V_27 ; V_11 ++ ) {
if ( ! F_4 ( V_10 , V_11 ) )
return V_11 ;
}
return 0 ;
}
static void F_20 ( struct V_8 * V_20 , int V_31 )
{
F_21 ( L_1 , V_20 , F_22 ( V_20 -> V_31 ) ,
F_22 ( V_31 ) ) ;
V_20 -> V_31 = V_31 ;
V_20 -> V_32 -> V_33 ( V_20 , V_31 , 0 ) ;
}
static inline void F_23 ( struct V_8 * V_20 ,
int V_31 , int V_21 )
{
V_20 -> V_31 = V_31 ;
V_20 -> V_32 -> V_33 ( V_20 , V_20 -> V_31 , V_21 ) ;
}
static inline void F_24 ( struct V_8 * V_20 , int V_21 )
{
V_20 -> V_32 -> V_33 ( V_20 , V_20 -> V_31 , V_21 ) ;
}
static void F_25 ( struct V_8 * V_20 )
{
if ( ! F_26 ( & V_20 -> V_34 ) &&
V_20 -> V_35 ) {
F_27 ( V_20 , & V_20 -> V_36 ,
F_28 ( V_20 -> V_35 ) ) ;
}
}
static void F_29 ( struct V_8 * V_20 )
{
F_30 ( V_20 ) ;
if ( V_20 -> V_37 ) {
F_27 ( V_20 , & V_20 -> V_34 ,
F_28 ( V_20 -> V_37 ) ) ;
}
}
static struct V_38 * F_31 ( struct V_39 * V_40 ,
T_2 V_41 )
{
struct V_38 * V_42 ;
F_32 (head, skb) {
if ( F_33 ( V_42 ) -> V_43 . V_44 == V_41 )
return V_42 ;
}
return NULL ;
}
static int F_34 ( struct V_45 * V_46 , T_2 V_47 )
{
T_7 V_48 , V_49 ;
V_48 = F_35 ( V_47 ) ;
V_46 -> V_50 = F_36 ( sizeof( T_2 ) * V_48 , V_51 ) ;
if ( ! V_46 -> V_50 )
return - V_52 ;
V_46 -> V_53 = V_48 - 1 ;
V_46 -> V_40 = V_54 ;
V_46 -> V_55 = V_54 ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ )
V_46 -> V_50 [ V_49 ] = V_54 ;
return 0 ;
}
static inline void F_37 ( struct V_45 * V_46 )
{
F_38 ( V_46 -> V_50 ) ;
}
static inline bool F_39 ( struct V_45 * V_46 ,
T_2 V_41 )
{
return V_46 -> V_50 [ V_41 & V_46 -> V_53 ] != V_54 ;
}
static T_2 F_40 ( struct V_45 * V_46 , T_2 V_41 )
{
T_2 V_53 = V_46 -> V_53 ;
if ( V_46 -> V_40 == V_54 ) {
return V_54 ;
} else if ( V_46 -> V_40 == V_41 ) {
V_46 -> V_40 = V_46 -> V_50 [ V_41 & V_53 ] ;
V_46 -> V_50 [ V_41 & V_53 ] = V_54 ;
if ( V_46 -> V_40 == V_56 ) {
V_46 -> V_40 = V_54 ;
V_46 -> V_55 = V_54 ;
}
} else {
T_2 V_57 = V_46 -> V_40 ;
while ( V_46 -> V_50 [ V_57 & V_53 ] != V_41 ) {
V_57 = V_46 -> V_50 [ V_57 & V_53 ] ;
if ( V_57 == V_56 )
return V_54 ;
}
V_46 -> V_50 [ V_57 & V_53 ] = V_46 -> V_50 [ V_41 & V_53 ] ;
V_46 -> V_50 [ V_41 & V_53 ] = V_54 ;
if ( V_46 -> V_55 == V_41 )
V_46 -> V_55 = V_57 ;
}
return V_41 ;
}
static inline T_2 F_41 ( struct V_45 * V_46 )
{
return F_40 ( V_46 , V_46 -> V_40 ) ;
}
static void F_42 ( struct V_45 * V_46 )
{
T_2 V_49 ;
if ( V_46 -> V_40 == V_54 )
return;
for ( V_49 = 0 ; V_49 <= V_46 -> V_53 ; V_49 ++ )
V_46 -> V_50 [ V_49 ] = V_54 ;
V_46 -> V_40 = V_54 ;
V_46 -> V_55 = V_54 ;
}
static void F_43 ( struct V_45 * V_46 , T_2 V_41 )
{
T_2 V_53 = V_46 -> V_53 ;
if ( V_46 -> V_50 [ V_41 & V_53 ] != V_54 )
return;
if ( V_46 -> V_55 == V_54 )
V_46 -> V_40 = V_41 ;
else
V_46 -> V_50 [ V_46 -> V_55 & V_53 ] = V_41 ;
V_46 -> V_55 = V_41 ;
V_46 -> V_50 [ V_41 & V_53 ] = V_56 ;
}
static void F_44 ( struct V_58 * V_59 )
{
struct V_8 * V_20 = F_45 ( V_59 , struct V_8 ,
V_60 . V_59 ) ;
struct V_9 * V_10 = V_20 -> V_10 ;
int V_61 ;
F_21 ( L_2 , V_20 , F_22 ( V_20 -> V_31 ) ) ;
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_20 ) ;
if ( V_20 -> V_31 == V_62 || V_20 -> V_31 == V_63 )
V_61 = V_64 ;
else if ( V_20 -> V_31 == V_65 &&
V_20 -> V_66 != V_67 )
V_61 = V_64 ;
else
V_61 = V_68 ;
F_46 ( V_20 , V_61 ) ;
F_47 ( V_20 ) ;
V_20 -> V_32 -> V_69 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
F_48 ( V_20 ) ;
}
struct V_8 * F_49 ( void )
{
struct V_8 * V_20 ;
V_20 = F_50 ( sizeof( * V_20 ) , V_70 ) ;
if ( ! V_20 )
return NULL ;
F_51 ( & V_20 -> V_71 ) ;
F_15 ( & V_22 ) ;
F_52 ( & V_20 -> V_72 , & V_73 ) ;
F_17 ( & V_22 ) ;
F_53 ( & V_20 -> V_60 , F_44 ) ;
V_20 -> V_31 = V_74 ;
F_54 ( & V_20 -> V_75 ) ;
F_55 ( V_76 , & V_20 -> V_77 ) ;
F_21 ( L_3 , V_20 ) ;
return V_20 ;
}
static void F_56 ( struct V_75 * V_75 )
{
struct V_8 * V_20 = F_45 ( V_75 , struct V_8 , V_75 ) ;
F_21 ( L_3 , V_20 ) ;
F_15 ( & V_22 ) ;
F_57 ( & V_20 -> V_72 ) ;
F_17 ( & V_22 ) ;
F_38 ( V_20 ) ;
}
void F_58 ( struct V_8 * V_12 )
{
F_21 ( L_4 , V_12 , F_59 ( & V_12 -> V_75 . V_78 ) ) ;
F_60 ( & V_12 -> V_75 ) ;
}
void F_48 ( struct V_8 * V_12 )
{
F_21 ( L_4 , V_12 , F_59 ( & V_12 -> V_75 . V_78 ) ) ;
F_61 ( & V_12 -> V_75 , F_56 ) ;
}
void F_62 ( struct V_8 * V_20 )
{
V_20 -> V_79 = V_80 ;
V_20 -> V_81 = V_82 ;
V_20 -> V_83 = V_84 ;
V_20 -> V_85 = V_84 ;
V_20 -> V_86 = V_84 ;
V_20 -> V_66 = V_87 ;
F_55 ( V_88 , & V_20 -> V_89 ) ;
}
static void F_63 ( struct V_8 * V_20 )
{
V_20 -> V_90 = NULL ;
V_20 -> V_91 = NULL ;
V_20 -> V_92 = 0 ;
V_20 -> V_93 = 0 ;
V_20 -> V_94 = V_95 ;
V_20 -> V_96 = F_64 ( T_2 , V_20 -> V_97 , V_98 ) ;
F_65 ( & V_20 -> V_99 ) ;
}
void F_66 ( struct V_9 * V_10 , struct V_8 * V_20 )
{
F_21 ( L_5 , V_10 ,
F_67 ( V_20 -> V_17 ) , V_20 -> V_13 ) ;
V_10 -> V_100 = V_101 ;
V_20 -> V_10 = V_10 ;
switch ( V_20 -> V_102 ) {
case V_103 :
if ( V_10 -> V_2 -> type == V_3 ) {
if ( V_20 -> V_13 == V_104 ) {
V_20 -> V_105 = V_106 ;
V_20 -> V_14 = V_104 ;
} else {
V_20 -> V_14 = F_19 ( V_10 ) ;
}
} else {
V_20 -> V_14 = F_19 ( V_10 ) ;
V_20 -> V_105 = V_106 ;
}
break;
case V_107 :
V_20 -> V_14 = V_108 ;
V_20 -> V_13 = V_108 ;
V_20 -> V_105 = V_106 ;
break;
case V_109 :
V_20 -> V_14 = V_110 ;
V_20 -> V_13 = V_110 ;
V_20 -> V_105 = V_111 ;
V_20 -> V_97 = V_111 ;
break;
default:
V_20 -> V_14 = V_112 ;
V_20 -> V_13 = V_112 ;
V_20 -> V_105 = V_106 ;
}
V_20 -> V_113 = V_114 ;
V_20 -> V_115 = V_116 ;
V_20 -> V_117 = V_118 ;
V_20 -> V_119 = V_120 ;
V_20 -> V_121 = V_122 ;
V_20 -> V_123 = V_124 ;
F_58 ( V_20 ) ;
F_68 ( V_10 -> V_2 ) ;
F_52 ( & V_20 -> V_50 , & V_10 -> V_125 ) ;
}
void F_69 ( struct V_9 * V_10 , struct V_8 * V_20 )
{
F_6 ( & V_10 -> V_15 ) ;
F_66 ( V_10 , V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
}
void F_70 ( struct V_8 * V_20 , int V_21 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_71 ( V_20 ) ;
F_21 ( L_6 , V_20 , V_10 , V_21 ) ;
if ( V_10 ) {
struct V_126 * V_127 = V_10 -> V_2 -> V_126 ;
F_57 ( & V_20 -> V_50 ) ;
F_48 ( V_20 ) ;
V_20 -> V_10 = NULL ;
if ( V_20 -> V_102 != V_109 )
F_72 ( V_10 -> V_2 ) ;
if ( V_127 && V_127 -> V_128 == V_20 )
V_127 -> V_128 = NULL ;
}
if ( V_20 -> V_129 ) {
struct V_130 * V_129 = V_20 -> V_129 ;
F_21 ( L_7 , V_20 , V_129 ) ;
F_73 ( V_129 ) ;
}
V_20 -> V_32 -> V_131 ( V_20 , V_21 ) ;
if ( F_74 ( V_76 , & V_20 -> V_77 ) )
return;
switch( V_20 -> V_132 ) {
case V_133 :
break;
case V_134 :
F_75 ( & V_20 -> V_99 ) ;
break;
case V_135 :
F_30 ( V_20 ) ;
F_76 ( V_20 ) ;
F_77 ( V_20 ) ;
F_75 ( & V_20 -> V_136 ) ;
F_37 ( & V_20 -> V_137 ) ;
F_37 ( & V_20 -> V_138 ) ;
case V_139 :
F_75 ( & V_20 -> V_99 ) ;
break;
}
return;
}
static void F_78 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_140 V_141 ;
T_2 V_142 ;
if ( F_74 ( V_143 , & V_20 -> V_89 ) )
V_142 = V_144 ;
else
V_142 = V_145 ;
F_20 ( V_20 , V_146 ) ;
V_141 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_141 . V_147 = F_16 ( V_20 -> V_97 ) ;
V_141 . V_96 = F_16 ( V_20 -> V_96 ) ;
V_141 . V_148 = F_16 ( V_20 -> V_94 ) ;
V_141 . V_142 = F_16 ( V_142 ) ;
F_79 ( V_10 , V_20 -> V_16 , V_149 , sizeof( V_141 ) ,
& V_141 ) ;
}
static void F_80 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_150 V_141 ;
T_2 V_142 ;
if ( F_74 ( V_143 , & V_20 -> V_89 ) )
V_142 = V_151 ;
else
V_142 = V_145 ;
F_20 ( V_20 , V_146 ) ;
V_141 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_141 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_141 . V_142 = F_16 ( V_142 ) ;
V_141 . V_152 = F_81 ( V_153 ) ;
F_79 ( V_10 , V_20 -> V_16 , V_154 , sizeof( V_141 ) , & V_141 ) ;
}
void F_46 ( struct V_8 * V_20 , int V_61 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_2 , V_20 , F_22 ( V_20 -> V_31 ) ) ;
switch ( V_20 -> V_31 ) {
case V_155 :
V_20 -> V_32 -> V_131 ( V_20 , 0 ) ;
break;
case V_62 :
case V_63 :
if ( V_20 -> V_102 == V_103 && V_20 -> V_17 ) {
F_82 ( V_20 , V_20 -> V_32 -> V_156 ( V_20 ) ) ;
F_83 ( V_20 , V_61 ) ;
} else
F_70 ( V_20 , V_61 ) ;
break;
case V_157 :
if ( V_20 -> V_102 == V_103 ) {
if ( V_10 -> V_2 -> type == V_158 )
F_80 ( V_20 ) ;
else if ( V_10 -> V_2 -> type == V_3 )
F_78 ( V_20 ) ;
}
F_70 ( V_20 , V_61 ) ;
break;
case V_65 :
case V_146 :
F_70 ( V_20 , V_61 ) ;
break;
default:
V_20 -> V_32 -> V_131 ( V_20 , 0 ) ;
break;
}
}
static inline T_3 F_84 ( struct V_8 * V_20 )
{
switch ( V_20 -> V_102 ) {
case V_159 :
switch ( V_20 -> V_66 ) {
case V_160 :
return V_161 ;
case V_162 :
return V_163 ;
default:
return V_164 ;
}
break;
case V_107 :
if ( V_20 -> V_17 == F_81 ( V_165 ) ) {
if ( V_20 -> V_66 == V_87 )
V_20 -> V_66 = V_67 ;
}
if ( V_20 -> V_66 == V_160 )
return V_166 ;
else
return V_164 ;
break;
case V_103 :
if ( V_20 -> V_17 == F_81 ( V_167 ) ) {
if ( V_20 -> V_66 == V_87 )
V_20 -> V_66 = V_67 ;
if ( V_20 -> V_66 == V_160 )
return V_166 ;
else
return V_164 ;
}
default:
switch ( V_20 -> V_66 ) {
case V_160 :
return V_168 ;
case V_162 :
return V_169 ;
default:
return V_164 ;
}
break;
}
}
int F_85 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
T_1 V_170 ;
if ( V_10 -> V_2 -> type == V_3 )
return F_86 ( V_10 -> V_2 , V_20 -> V_66 ) ;
V_170 = F_84 ( V_20 ) ;
return F_87 ( V_10 -> V_2 , V_20 -> V_66 , V_170 ) ;
}
static T_3 F_88 ( struct V_9 * V_10 )
{
T_3 V_171 ;
F_89 ( & V_10 -> V_71 ) ;
if ( ++ V_10 -> V_172 > 128 )
V_10 -> V_172 = 1 ;
V_171 = V_10 -> V_172 ;
F_90 ( & V_10 -> V_71 ) ;
return V_171 ;
}
static void F_79 ( struct V_9 * V_10 , T_3 V_16 , T_3 V_173 , T_2 V_174 ,
void * V_175 )
{
struct V_38 * V_42 = F_91 ( V_10 , V_173 , V_16 , V_174 , V_175 ) ;
T_3 V_89 ;
F_21 ( L_8 , V_173 ) ;
if ( ! V_42 )
return;
if ( F_92 ( V_10 -> V_2 -> V_176 ) )
V_89 = V_177 ;
else
V_89 = V_178 ;
F_33 ( V_42 ) -> V_179 = V_180 ;
V_42 -> V_181 = V_182 ;
F_93 ( V_10 -> V_183 , V_42 , V_89 ) ;
}
static bool F_94 ( struct V_8 * V_20 )
{
return V_20 -> V_184 != V_185 &&
V_20 -> V_184 != V_186 ;
}
static void F_95 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
struct V_1 * V_2 = V_20 -> V_10 -> V_2 ;
T_2 V_89 ;
F_21 ( L_9 , V_20 , V_42 , V_42 -> V_174 ,
V_42 -> V_181 ) ;
if ( V_20 -> V_187 && ! F_94 ( V_20 ) ) {
if ( V_20 -> V_129 )
F_93 ( V_20 -> V_129 , V_42 , V_188 ) ;
else
F_96 ( V_42 ) ;
return;
}
if ( ! F_74 ( V_189 , & V_20 -> V_89 ) &&
F_92 ( V_2 -> V_176 ) )
V_89 = V_177 ;
else
V_89 = V_178 ;
F_33 ( V_42 ) -> V_179 = F_74 ( V_88 , & V_20 -> V_89 ) ;
F_93 ( V_20 -> V_10 -> V_183 , V_42 , V_89 ) ;
}
static void F_97 ( T_2 V_190 , struct V_191 * V_43 )
{
V_43 -> V_192 = ( V_190 & V_193 ) >> V_194 ;
V_43 -> V_195 = ( V_190 & V_196 ) >> V_197 ;
if ( V_190 & V_198 ) {
V_43 -> V_199 = 1 ;
V_43 -> V_200 = ( V_190 & V_201 ) >> V_202 ;
V_43 -> V_203 = ( V_190 & V_204 ) >> V_205 ;
V_43 -> V_206 = 0 ;
V_43 -> V_44 = 0 ;
} else {
V_43 -> V_199 = 0 ;
V_43 -> V_206 = ( V_190 & V_207 ) >> V_208 ;
V_43 -> V_44 = ( V_190 & V_209 ) >> V_210 ;
V_43 -> V_200 = 0 ;
V_43 -> V_203 = 0 ;
}
}
static void F_98 ( T_8 V_211 , struct V_191 * V_43 )
{
V_43 -> V_192 = ( V_211 & V_212 ) >> V_213 ;
V_43 -> V_195 = ( V_211 & V_214 ) >> V_215 ;
if ( V_211 & V_216 ) {
V_43 -> V_199 = 1 ;
V_43 -> V_200 = ( V_211 & V_217 ) >> V_218 ;
V_43 -> V_203 = ( V_211 & V_219 ) >> V_220 ;
V_43 -> V_206 = 0 ;
V_43 -> V_44 = 0 ;
} else {
V_43 -> V_199 = 0 ;
V_43 -> V_206 = ( V_211 & V_221 ) >> V_222 ;
V_43 -> V_44 = ( V_211 & V_223 ) >> V_224 ;
V_43 -> V_200 = 0 ;
V_43 -> V_203 = 0 ;
}
}
static inline void F_99 ( struct V_8 * V_20 ,
struct V_38 * V_42 )
{
if ( F_74 ( V_225 , & V_20 -> V_89 ) ) {
F_98 ( F_100 ( V_42 -> V_175 ) ,
& F_33 ( V_42 ) -> V_43 ) ;
F_101 ( V_42 , V_226 ) ;
} else {
F_97 ( F_102 ( V_42 -> V_175 ) ,
& F_33 ( V_42 ) -> V_43 ) ;
F_101 ( V_42 , V_227 ) ;
}
}
static T_8 F_103 ( struct V_191 * V_43 )
{
T_8 V_228 ;
V_228 = V_43 -> V_192 << V_213 ;
V_228 |= V_43 -> V_195 << V_215 ;
if ( V_43 -> V_199 ) {
V_228 |= V_43 -> V_200 << V_218 ;
V_228 |= V_43 -> V_203 << V_220 ;
V_228 |= V_216 ;
} else {
V_228 |= V_43 -> V_206 << V_222 ;
V_228 |= V_43 -> V_44 << V_224 ;
}
return V_228 ;
}
static T_2 F_104 ( struct V_191 * V_43 )
{
T_2 V_228 ;
V_228 = V_43 -> V_192 << V_194 ;
V_228 |= V_43 -> V_195 << V_197 ;
if ( V_43 -> V_199 ) {
V_228 |= V_43 -> V_200 << V_202 ;
V_228 |= V_43 -> V_203 << V_205 ;
V_228 |= V_198 ;
} else {
V_228 |= V_43 -> V_206 << V_208 ;
V_228 |= V_43 -> V_44 << V_210 ;
}
return V_228 ;
}
static inline void F_105 ( struct V_8 * V_20 ,
struct V_191 * V_43 ,
struct V_38 * V_42 )
{
if ( F_74 ( V_225 , & V_20 -> V_89 ) ) {
F_106 ( F_103 ( V_43 ) ,
V_42 -> V_175 + V_229 ) ;
} else {
F_107 ( F_104 ( V_43 ) ,
V_42 -> V_175 + V_229 ) ;
}
}
static inline unsigned int F_108 ( struct V_8 * V_20 )
{
if ( F_74 ( V_225 , & V_20 -> V_89 ) )
return V_230 ;
else
return V_231 ;
}
static struct V_38 * F_109 ( struct V_8 * V_20 ,
T_8 V_43 )
{
struct V_38 * V_42 ;
struct V_232 * V_233 ;
int V_234 = F_108 ( V_20 ) ;
if ( V_20 -> V_79 == V_80 )
V_234 += V_235 ;
V_42 = F_110 ( V_234 , V_51 ) ;
if ( ! V_42 )
return F_111 ( - V_52 ) ;
V_233 = (struct V_232 * ) F_112 ( V_42 , V_229 ) ;
V_233 -> V_174 = F_16 ( V_234 - V_229 ) ;
V_233 -> V_11 = F_16 ( V_20 -> V_13 ) ;
if ( F_74 ( V_225 , & V_20 -> V_89 ) )
F_106 ( V_43 , F_112 ( V_42 , V_226 ) ) ;
else
F_107 ( V_43 , F_112 ( V_42 , V_227 ) ) ;
if ( V_20 -> V_79 == V_80 ) {
T_2 V_79 = F_113 ( 0 , ( T_3 * ) V_42 -> V_175 , V_42 -> V_174 ) ;
F_107 ( V_79 , F_112 ( V_42 , V_235 ) ) ;
}
V_42 -> V_181 = V_182 ;
return V_42 ;
}
static void F_114 ( struct V_8 * V_20 ,
struct V_191 * V_43 )
{
struct V_38 * V_42 ;
T_8 V_236 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( ! V_43 -> V_199 )
return;
if ( F_94 ( V_20 ) )
return;
if ( F_115 ( V_237 , & V_20 -> V_238 ) &&
! V_43 -> V_200 )
V_43 -> V_195 = 1 ;
if ( V_43 -> V_203 == V_239 )
F_116 ( V_240 , & V_20 -> V_238 ) ;
else if ( V_43 -> V_203 == V_241 )
F_55 ( V_240 , & V_20 -> V_238 ) ;
if ( V_43 -> V_203 != V_242 ) {
V_20 -> V_243 = V_43 -> V_192 ;
F_77 ( V_20 ) ;
}
F_21 ( L_11 , V_43 -> V_192 ,
V_43 -> V_195 , V_43 -> V_200 , V_43 -> V_203 ) ;
if ( F_74 ( V_225 , & V_20 -> V_89 ) )
V_236 = F_103 ( V_43 ) ;
else
V_236 = F_104 ( V_43 ) ;
V_42 = F_109 ( V_20 , V_236 ) ;
if ( ! F_117 ( V_42 ) )
F_95 ( V_20 , V_42 ) ;
}
static void F_118 ( struct V_8 * V_20 , bool V_200 )
{
struct V_191 V_43 ;
F_21 ( L_12 , V_20 , V_200 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_199 = 1 ;
V_43 . V_200 = V_200 ;
if ( F_74 ( V_244 , & V_20 -> V_238 ) )
V_43 . V_203 = V_241 ;
else
V_43 . V_203 = V_239 ;
V_43 . V_192 = V_20 -> V_245 ;
F_114 ( V_20 , & V_43 ) ;
}
static inline int F_119 ( struct V_8 * V_20 )
{
return ! F_74 ( V_246 , & V_20 -> V_77 ) ;
}
static bool F_120 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_247 * V_176 ;
bool V_248 = false ;
if ( ! V_10 -> V_249 )
return false ;
if ( ! ( V_10 -> V_250 & V_251 ) )
return false ;
F_121 ( & V_252 ) ;
F_3 (hdev, &hci_dev_list, list) {
if ( V_176 -> V_253 != V_254 &&
F_74 ( V_255 , & V_176 -> V_89 ) ) {
V_248 = true ;
break;
}
}
F_122 ( & V_252 ) ;
if ( V_20 -> V_256 == V_257 )
return V_248 ;
return false ;
}
static bool F_123 ( struct V_8 * V_20 )
{
return true ;
}
void F_124 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_258 V_259 ;
V_259 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_259 . V_17 = V_20 -> V_17 ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_55 ( V_246 , & V_20 -> V_77 ) ;
F_79 ( V_10 , V_20 -> V_16 , V_260 , sizeof( V_259 ) , & V_259 ) ;
}
static void F_125 ( struct V_8 * V_20 , T_3 V_261 )
{
struct V_262 V_259 ;
V_259 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_259 . V_17 = V_20 -> V_17 ;
V_259 . V_261 = V_261 ;
V_20 -> V_16 = F_88 ( V_20 -> V_10 ) ;
F_79 ( V_20 -> V_10 , V_20 -> V_16 , V_263 ,
sizeof( V_259 ) , & V_259 ) ;
}
static void F_126 ( struct V_8 * V_20 )
{
struct V_38 * V_42 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_132 != V_135 )
return;
F_30 ( V_20 ) ;
F_76 ( V_20 ) ;
F_77 ( V_20 ) ;
V_20 -> V_264 = 0 ;
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_42 ) -> V_43 . V_265 )
F_33 ( V_42 ) -> V_43 . V_265 = 1 ;
else
break;
}
V_20 -> V_266 = V_20 -> V_245 ;
F_116 ( V_267 , & V_20 -> V_238 ) ;
F_116 ( V_268 , & V_20 -> V_238 ) ;
F_42 ( & V_20 -> V_138 ) ;
F_42 ( & V_20 -> V_137 ) ;
F_75 ( & V_20 -> V_136 ) ;
V_20 -> V_269 = V_270 ;
V_20 -> V_271 = V_272 ;
F_55 ( V_273 , & V_20 -> V_238 ) ;
}
static void F_127 ( struct V_8 * V_20 )
{
T_3 V_274 = V_20 -> V_274 ;
F_21 ( L_3 , V_20 ) ;
V_20 -> V_184 = V_185 ;
V_20 -> V_274 = V_275 ;
if ( V_20 -> V_132 != V_135 )
return;
switch ( V_274 ) {
case V_276 :
F_128 ( V_20 , NULL , NULL , V_277 ) ;
V_20 -> V_271 = V_278 ;
break;
case V_279 :
V_20 -> V_271 = V_280 ;
break;
}
}
static void F_129 ( struct V_8 * V_20 )
{
V_20 -> V_77 = 0 ;
F_71 ( V_20 ) ;
if ( V_20 -> V_132 == V_134 && ! V_20 -> V_93 )
V_20 -> V_32 -> V_281 ( V_20 ) ;
V_20 -> V_31 = V_62 ;
V_20 -> V_32 -> V_282 ( V_20 ) ;
}
static void F_130 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_283 V_259 ;
if ( F_131 ( V_284 , & V_20 -> V_89 ) )
return;
V_259 . V_17 = V_20 -> V_17 ;
V_259 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_259 . V_147 = F_16 ( V_20 -> V_97 ) ;
V_259 . V_96 = F_16 ( V_20 -> V_96 ) ;
V_259 . V_148 = F_16 ( V_20 -> V_94 ) ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_79 ( V_10 , V_20 -> V_16 , V_285 ,
sizeof( V_259 ) , & V_259 ) ;
}
static void F_132 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
if ( ! F_86 ( V_10 -> V_2 , V_20 -> V_66 ) )
return;
if ( ! V_20 -> V_17 ) {
F_129 ( V_20 ) ;
return;
}
if ( V_20 -> V_31 == V_65 )
F_130 ( V_20 ) ;
}
static void F_133 ( struct V_8 * V_20 )
{
if ( F_120 ( V_20 ) ) {
F_21 ( L_13 , V_20 ) ;
F_134 ( V_20 ) ;
} else if ( V_20 -> V_10 -> V_2 -> type == V_3 ) {
F_132 ( V_20 ) ;
} else {
F_124 ( V_20 ) ;
}
}
static void F_135 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
if ( V_10 -> V_2 -> type == V_3 ) {
F_132 ( V_20 ) ;
return;
}
if ( V_10 -> V_286 & V_287 ) {
if ( ! ( V_10 -> V_286 & V_288 ) )
return;
if ( F_85 ( V_20 ) &&
F_119 ( V_20 ) ) {
F_133 ( V_20 ) ;
}
} else {
struct V_289 V_259 ;
V_259 . type = F_81 ( V_290 ) ;
V_10 -> V_286 |= V_287 ;
V_10 -> V_291 = F_88 ( V_10 ) ;
F_136 ( & V_10 -> V_292 , V_293 ) ;
F_79 ( V_10 , V_10 -> V_291 , V_294 ,
sizeof( V_259 ) , & V_259 ) ;
}
}
static inline int F_137 ( T_1 V_132 , T_9 V_295 )
{
T_8 V_296 = V_297 ;
if ( ! V_298 )
V_296 |= V_299 | V_300 ;
switch ( V_132 ) {
case V_135 :
return V_299 & V_295 & V_296 ;
case V_139 :
return V_300 & V_295 & V_296 ;
default:
return 0x00 ;
}
}
static void F_83 ( struct V_8 * V_20 , int V_21 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_301 V_259 ;
if ( ! V_10 )
return;
if ( V_20 -> V_132 == V_135 && V_20 -> V_31 == V_62 ) {
F_30 ( V_20 ) ;
F_76 ( V_20 ) ;
F_77 ( V_20 ) ;
}
if ( V_20 -> V_102 == V_109 ) {
F_20 ( V_20 , V_146 ) ;
return;
}
V_259 . V_13 = F_16 ( V_20 -> V_13 ) ;
V_259 . V_14 = F_16 ( V_20 -> V_14 ) ;
F_79 ( V_10 , F_88 ( V_10 ) , V_302 ,
sizeof( V_259 ) , & V_259 ) ;
F_23 ( V_20 , V_146 , V_21 ) ;
}
static void F_138 ( struct V_9 * V_10 )
{
struct V_8 * V_20 , * V_303 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_139 (chan, tmp, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_102 != V_103 ) {
F_47 ( V_20 ) ;
continue;
}
if ( V_20 -> V_31 == V_65 ) {
if ( ! F_85 ( V_20 ) ||
! F_119 ( V_20 ) ) {
F_47 ( V_20 ) ;
continue;
}
if ( ! F_137 ( V_20 -> V_132 , V_10 -> V_295 )
&& F_74 ( V_304 ,
& V_20 -> V_77 ) ) {
F_46 ( V_20 , V_305 ) ;
F_47 ( V_20 ) ;
continue;
}
F_133 ( V_20 ) ;
} else if ( V_20 -> V_31 == V_157 ) {
struct V_150 V_141 ;
char V_306 [ 128 ] ;
V_141 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_141 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( F_85 ( V_20 ) ) {
if ( F_74 ( V_143 , & V_20 -> V_89 ) ) {
V_141 . V_142 = F_81 ( V_307 ) ;
V_141 . V_152 = F_81 ( V_308 ) ;
V_20 -> V_32 -> V_309 ( V_20 ) ;
} else {
F_20 ( V_20 , V_63 ) ;
V_141 . V_142 = F_81 ( V_310 ) ;
V_141 . V_152 = F_81 ( V_153 ) ;
}
} else {
V_141 . V_142 = F_81 ( V_307 ) ;
V_141 . V_152 = F_81 ( V_311 ) ;
}
F_79 ( V_10 , V_20 -> V_16 , V_154 ,
sizeof( V_141 ) , & V_141 ) ;
if ( F_74 ( V_312 , & V_20 -> V_77 ) ||
V_141 . V_142 != V_310 ) {
F_47 ( V_20 ) ;
continue;
}
F_55 ( V_312 , & V_20 -> V_77 ) ;
F_79 ( V_10 , F_88 ( V_10 ) , V_313 ,
F_140 ( V_20 , V_306 ) , V_306 ) ;
V_20 -> V_314 ++ ;
}
F_47 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static struct V_8 * F_141 ( int V_31 , T_2 V_11 ,
T_5 * V_18 ,
T_5 * V_315 )
{
struct V_8 * V_12 , * V_316 = NULL ;
F_121 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_31 && V_12 -> V_31 != V_31 )
continue;
if ( V_12 -> V_14 == V_11 ) {
int V_317 , V_318 ;
int V_319 , V_320 ;
V_317 = ! F_13 ( & V_12 -> V_18 , V_18 ) ;
V_318 = ! F_13 ( & V_12 -> V_315 , V_315 ) ;
if ( V_317 && V_318 ) {
F_122 ( & V_22 ) ;
return V_12 ;
}
V_319 = ! F_13 ( & V_12 -> V_18 , V_321 ) ;
V_320 = ! F_13 ( & V_12 -> V_315 , V_321 ) ;
if ( ( V_317 && V_320 ) || ( V_319 && V_318 ) ||
( V_319 && V_320 ) )
V_316 = V_12 ;
}
}
F_122 ( & V_22 ) ;
return V_316 ;
}
static void F_142 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 , * V_322 ;
T_3 V_323 ;
F_21 ( L_15 ) ;
F_143 ( V_10 ) ;
V_322 = F_141 ( V_155 , V_104 ,
& V_2 -> V_18 , & V_2 -> V_315 ) ;
if ( ! V_322 )
return;
if ( F_2 ( V_10 , V_104 ) )
return;
V_323 = F_1 ( V_2 , V_2 -> V_323 ) ;
if ( F_144 ( V_2 -> V_176 , & V_2 -> V_315 , V_323 ) )
return;
F_7 ( V_322 ) ;
V_20 = V_322 -> V_32 -> V_324 ( V_322 ) ;
if ( ! V_20 )
goto V_325;
V_20 -> V_13 = V_104 ;
F_145 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
F_145 ( & V_20 -> V_315 , & V_2 -> V_315 ) ;
V_20 -> V_326 = F_1 ( V_2 , V_2 -> V_326 ) ;
V_20 -> V_323 = V_323 ;
F_66 ( V_10 , V_20 ) ;
V_325:
F_47 ( V_322 ) ;
}
static void F_146 ( struct V_9 * V_10 )
{
struct V_8 * V_20 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_21 ( L_14 , V_10 ) ;
if ( V_2 -> V_327 && V_2 -> type == V_3 )
F_86 ( V_2 , V_2 -> V_328 ) ;
F_6 ( & V_10 -> V_15 ) ;
if ( V_2 -> type == V_3 )
F_142 ( V_10 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_102 == V_109 ) {
F_47 ( V_20 ) ;
continue;
}
if ( V_2 -> type == V_3 ) {
F_132 ( V_20 ) ;
} else if ( V_20 -> V_102 != V_103 ) {
F_129 ( V_20 ) ;
} else if ( V_20 -> V_31 == V_65 ) {
F_135 ( V_20 ) ;
}
F_47 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_147 ( struct V_9 * V_10 , int V_21 )
{
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( F_74 ( V_329 , & V_20 -> V_89 ) )
F_24 ( V_20 , V_21 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_148 ( struct V_58 * V_59 )
{
struct V_9 * V_10 = F_45 ( V_59 , struct V_9 ,
V_292 . V_59 ) ;
V_10 -> V_286 |= V_288 ;
V_10 -> V_291 = 0 ;
F_138 ( V_10 ) ;
}
int F_149 ( struct V_9 * V_10 , struct V_330 * V_331 )
{
struct V_247 * V_176 = V_10 -> V_2 -> V_176 ;
int V_332 ;
F_150 ( V_176 ) ;
if ( V_331 -> V_50 . V_333 || V_331 -> V_50 . V_57 ) {
V_332 = - V_26 ;
goto V_334;
}
if ( ! V_10 -> V_183 ) {
V_332 = - V_335 ;
goto V_334;
}
V_332 = V_331 -> V_336 ( V_10 , V_331 ) ;
if ( V_332 )
goto V_334;
F_52 ( & V_331 -> V_50 , & V_10 -> V_337 ) ;
V_332 = 0 ;
V_334:
F_151 ( V_176 ) ;
return V_332 ;
}
void F_152 ( struct V_9 * V_10 , struct V_330 * V_331 )
{
struct V_247 * V_176 = V_10 -> V_2 -> V_176 ;
F_150 ( V_176 ) ;
if ( ! V_331 -> V_50 . V_333 || ! V_331 -> V_50 . V_57 )
goto V_334;
F_57 ( & V_331 -> V_50 ) ;
V_331 -> V_50 . V_333 = NULL ;
V_331 -> V_50 . V_57 = NULL ;
V_331 -> remove ( V_10 , V_331 ) ;
V_334:
F_151 ( V_176 ) ;
}
static void F_153 ( struct V_9 * V_10 )
{
struct V_330 * V_331 ;
while ( ! F_154 ( & V_10 -> V_337 ) ) {
V_331 = F_155 ( & V_10 -> V_337 , struct V_330 , V_50 ) ;
F_57 ( & V_331 -> V_50 ) ;
V_331 -> V_50 . V_333 = NULL ;
V_331 -> V_50 . V_57 = NULL ;
V_331 -> remove ( V_10 , V_331 ) ;
}
}
static void F_156 ( struct V_1 * V_2 , int V_21 )
{
struct V_9 * V_10 = V_2 -> V_338 ;
struct V_8 * V_20 , * V_339 ;
if ( ! V_10 )
return;
F_21 ( L_16 , V_2 , V_10 , V_21 ) ;
F_96 ( V_10 -> V_340 ) ;
F_153 ( V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_139 (chan, l, &conn->chan_l, list) {
F_58 ( V_20 ) ;
F_7 ( V_20 ) ;
F_70 ( V_20 , V_21 ) ;
F_47 ( V_20 ) ;
V_20 -> V_32 -> V_69 ( V_20 ) ;
F_48 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
F_157 ( V_10 -> V_183 ) ;
if ( V_10 -> V_286 & V_287 )
F_158 ( & V_10 -> V_292 ) ;
if ( F_115 ( V_341 , & V_2 -> V_89 ) ) {
F_158 ( & V_10 -> V_342 ) ;
F_159 ( V_10 ) ;
}
V_2 -> V_338 = NULL ;
V_10 -> V_183 = NULL ;
F_160 ( V_10 ) ;
}
static void F_161 ( struct V_58 * V_59 )
{
struct V_9 * V_10 = F_45 ( V_59 , struct V_9 ,
V_342 . V_59 ) ;
F_21 ( L_14 , V_10 ) ;
if ( F_115 ( V_341 , & V_10 -> V_2 -> V_89 ) ) {
F_159 ( V_10 ) ;
F_156 ( V_10 -> V_2 , V_68 ) ;
}
}
static struct V_9 * F_162 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_338 ;
struct V_130 * V_183 ;
if ( V_10 )
return V_10 ;
V_183 = F_163 ( V_2 ) ;
if ( ! V_183 )
return NULL ;
V_10 = F_50 ( sizeof( struct V_9 ) , V_51 ) ;
if ( ! V_10 ) {
F_157 ( V_183 ) ;
return NULL ;
}
F_54 ( & V_10 -> V_343 ) ;
V_2 -> V_338 = V_10 ;
V_10 -> V_2 = V_2 ;
F_164 ( V_10 -> V_2 ) ;
V_10 -> V_183 = V_183 ;
F_21 ( L_17 , V_2 , V_10 , V_183 ) ;
switch ( V_2 -> type ) {
case V_3 :
if ( V_2 -> V_176 -> V_344 ) {
V_10 -> V_147 = V_2 -> V_176 -> V_344 ;
break;
}
default:
V_10 -> V_147 = V_2 -> V_176 -> V_345 ;
break;
}
V_10 -> V_295 = 0 ;
if ( V_2 -> type == V_158 )
V_10 -> V_249 = F_74 ( V_346 ,
& V_2 -> V_176 -> V_347 ) ;
F_165 ( & V_10 -> V_71 ) ;
F_51 ( & V_10 -> V_15 ) ;
F_166 ( & V_10 -> V_125 ) ;
F_166 ( & V_10 -> V_337 ) ;
if ( V_2 -> type == V_3 )
F_53 ( & V_10 -> V_342 , F_161 ) ;
else
F_53 ( & V_10 -> V_292 , F_148 ) ;
V_10 -> V_100 = V_101 ;
return V_10 ;
}
static void F_167 ( struct V_75 * V_343 )
{
struct V_9 * V_10 = F_45 ( V_343 , struct V_9 , V_343 ) ;
F_168 ( V_10 -> V_2 ) ;
F_38 ( V_10 ) ;
}
void F_169 ( struct V_9 * V_10 )
{
F_60 ( & V_10 -> V_343 ) ;
}
void F_160 ( struct V_9 * V_10 )
{
F_61 ( & V_10 -> V_343 , F_167 ) ;
}
static struct V_8 * F_170 ( int V_31 , T_4 V_17 ,
T_5 * V_18 ,
T_5 * V_315 ,
T_3 V_348 )
{
struct V_8 * V_12 , * V_316 = NULL ;
F_121 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_31 && V_12 -> V_31 != V_31 )
continue;
if ( V_348 == V_158 && V_12 -> V_326 != V_7 )
continue;
if ( V_348 == V_3 && V_12 -> V_326 == V_7 )
continue;
if ( V_12 -> V_17 == V_17 ) {
int V_317 , V_318 ;
int V_319 , V_320 ;
V_317 = ! F_13 ( & V_12 -> V_18 , V_18 ) ;
V_318 = ! F_13 ( & V_12 -> V_315 , V_315 ) ;
if ( V_317 && V_318 ) {
F_122 ( & V_22 ) ;
return V_12 ;
}
V_319 = ! F_13 ( & V_12 -> V_18 , V_321 ) ;
V_320 = ! F_13 ( & V_12 -> V_315 , V_321 ) ;
if ( ( V_317 && V_320 ) || ( V_319 && V_318 ) ||
( V_319 && V_320 ) )
V_316 = V_12 ;
}
}
F_122 ( & V_22 ) ;
return V_316 ;
}
static bool F_171 ( T_2 V_17 , T_3 V_323 )
{
if ( ! V_17 )
return false ;
if ( F_172 ( V_323 ) )
return ( V_17 <= 0x00ff ) ;
return ( ( V_17 & 0x0101 ) == 0x0001 ) ;
}
int F_173 ( struct V_8 * V_20 , T_4 V_17 , T_2 V_11 ,
T_5 * V_315 , T_3 V_323 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_247 * V_176 ;
T_1 V_170 ;
int V_21 ;
F_21 ( L_18 , & V_20 -> V_18 , V_315 ,
V_323 , F_67 ( V_17 ) ) ;
V_176 = F_174 ( V_315 , & V_20 -> V_18 ) ;
if ( ! V_176 )
return - V_349 ;
F_150 ( V_176 ) ;
F_7 ( V_20 ) ;
if ( ! F_171 ( F_67 ( V_17 ) , V_323 ) && ! V_11 &&
V_20 -> V_102 != V_159 ) {
V_21 = - V_26 ;
goto V_24;
}
if ( V_20 -> V_102 == V_103 && ! ( V_17 || V_11 ) ) {
V_21 = - V_26 ;
goto V_24;
}
switch ( V_20 -> V_132 ) {
case V_133 :
break;
case V_134 :
F_63 ( V_20 ) ;
break;
case V_135 :
case V_139 :
if ( ! V_298 )
break;
default:
V_21 = - V_350 ;
goto V_24;
}
switch ( V_20 -> V_31 ) {
case V_65 :
case V_157 :
case V_63 :
V_21 = 0 ;
goto V_24;
case V_62 :
V_21 = - V_351 ;
goto V_24;
case V_74 :
case V_352 :
break;
default:
V_21 = - V_353 ;
goto V_24;
}
F_145 ( & V_20 -> V_315 , V_315 ) ;
V_20 -> V_323 = V_323 ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_11 ;
V_170 = F_84 ( V_20 ) ;
if ( F_172 ( V_323 ) )
V_2 = F_175 ( V_176 , V_3 , V_315 , V_323 ,
V_20 -> V_66 , V_170 ) ;
else
V_2 = F_175 ( V_176 , V_158 , V_315 , V_323 ,
V_20 -> V_66 , V_170 ) ;
if ( F_117 ( V_2 ) ) {
V_21 = F_176 ( V_2 ) ;
goto V_24;
}
V_10 = F_162 ( V_2 ) ;
if ( ! V_10 ) {
F_72 ( V_2 ) ;
V_21 = - V_52 ;
goto V_24;
}
if ( V_11 && F_2 ( V_10 , V_11 ) ) {
F_72 ( V_2 ) ;
V_21 = - V_354 ;
goto V_24;
}
F_145 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
V_20 -> V_326 = F_1 ( V_2 , V_2 -> V_326 ) ;
F_47 ( V_20 ) ;
F_69 ( V_10 , V_20 ) ;
F_7 ( V_20 ) ;
F_72 ( V_2 ) ;
F_20 ( V_20 , V_65 ) ;
F_82 ( V_20 , V_20 -> V_32 -> V_156 ( V_20 ) ) ;
if ( V_2 -> V_31 == V_62 ) {
if ( V_20 -> V_102 != V_103 ) {
F_71 ( V_20 ) ;
if ( F_85 ( V_20 ) )
F_20 ( V_20 , V_62 ) ;
} else
F_135 ( V_20 ) ;
}
V_21 = 0 ;
V_24:
F_47 ( V_20 ) ;
F_151 ( V_176 ) ;
F_177 ( V_176 ) ;
return V_21 ;
}
static void F_178 ( struct V_58 * V_59 )
{
struct V_8 * V_20 = F_45 ( V_59 , struct V_8 ,
V_34 . V_59 ) ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
if ( ! V_20 -> V_10 ) {
F_47 ( V_20 ) ;
F_48 ( V_20 ) ;
return;
}
F_128 ( V_20 , NULL , NULL , V_355 ) ;
F_47 ( V_20 ) ;
F_48 ( V_20 ) ;
}
static void F_179 ( struct V_58 * V_59 )
{
struct V_8 * V_20 = F_45 ( V_59 , struct V_8 ,
V_36 . V_59 ) ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
if ( ! V_20 -> V_10 ) {
F_47 ( V_20 ) ;
F_48 ( V_20 ) ;
return;
}
F_128 ( V_20 , NULL , NULL , V_356 ) ;
F_47 ( V_20 ) ;
F_48 ( V_20 ) ;
}
static void F_180 ( struct V_8 * V_20 ,
struct V_39 * V_357 )
{
struct V_38 * V_42 ;
struct V_191 * V_43 ;
F_21 ( L_19 , V_20 , V_357 ) ;
if ( F_94 ( V_20 ) )
return;
F_181 ( V_357 , & V_20 -> V_99 ) ;
while ( ! F_182 ( & V_20 -> V_99 ) ) {
V_42 = F_183 ( & V_20 -> V_99 ) ;
F_33 ( V_42 ) -> V_43 . V_265 = 1 ;
V_43 = & F_33 ( V_42 ) -> V_43 ;
V_43 -> V_192 = 0 ;
V_43 -> V_44 = V_20 -> V_358 ;
F_105 ( V_20 , V_43 , V_42 ) ;
if ( V_20 -> V_79 == V_80 ) {
T_2 V_79 = F_113 ( 0 , ( T_3 * ) V_42 -> V_175 , V_42 -> V_174 ) ;
F_107 ( V_79 , F_112 ( V_42 , V_235 ) ) ;
}
F_95 ( V_20 , V_42 ) ;
F_21 ( L_20 , V_43 -> V_44 ) ;
V_20 -> V_358 = F_184 ( V_20 , V_20 -> V_358 ) ;
V_20 -> V_359 ++ ;
}
}
static int F_185 ( struct V_8 * V_20 )
{
struct V_38 * V_42 , * V_360 ;
struct V_191 * V_43 ;
int V_361 = 0 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_31 != V_62 )
return - V_362 ;
if ( F_74 ( V_273 , & V_20 -> V_238 ) )
return 0 ;
if ( F_94 ( V_20 ) )
return 0 ;
while ( V_20 -> V_363 &&
V_20 -> V_364 < V_20 -> V_365 &&
V_20 -> V_269 == V_270 ) {
V_42 = V_20 -> V_363 ;
F_33 ( V_42 ) -> V_43 . V_265 = 1 ;
V_43 = & F_33 ( V_42 ) -> V_43 ;
if ( F_115 ( V_237 , & V_20 -> V_238 ) )
V_43 -> V_195 = 1 ;
V_43 -> V_192 = V_20 -> V_245 ;
V_20 -> V_243 = V_20 -> V_245 ;
V_43 -> V_44 = V_20 -> V_358 ;
F_105 ( V_20 , V_43 , V_42 ) ;
if ( V_20 -> V_79 == V_80 ) {
T_2 V_79 = F_113 ( 0 , ( T_3 * ) V_42 -> V_175 , V_42 -> V_174 ) ;
F_107 ( V_79 , F_112 ( V_42 , V_235 ) ) ;
}
V_360 = F_186 ( V_42 , V_51 ) ;
if ( ! V_360 )
break;
F_25 ( V_20 ) ;
V_20 -> V_358 = F_184 ( V_20 , V_20 -> V_358 ) ;
V_20 -> V_364 ++ ;
V_20 -> V_359 ++ ;
V_361 ++ ;
if ( F_187 ( & V_20 -> V_99 , V_42 ) )
V_20 -> V_363 = NULL ;
else
V_20 -> V_363 = F_188 ( & V_20 -> V_99 , V_42 ) ;
F_95 ( V_20 , V_360 ) ;
F_21 ( L_20 , V_43 -> V_44 ) ;
}
F_21 ( L_21 , V_361 ,
V_20 -> V_364 , F_189 ( & V_20 -> V_99 ) ) ;
return V_361 ;
}
static void F_190 ( struct V_8 * V_20 )
{
struct V_191 V_43 ;
struct V_38 * V_42 ;
struct V_38 * V_360 ;
T_2 V_41 ;
F_21 ( L_3 , V_20 ) ;
if ( F_74 ( V_273 , & V_20 -> V_238 ) )
return;
if ( F_94 ( V_20 ) )
return;
while ( V_20 -> V_138 . V_40 != V_54 ) {
V_41 = F_41 ( & V_20 -> V_138 ) ;
V_42 = F_31 ( & V_20 -> V_99 , V_41 ) ;
if ( ! V_42 ) {
F_21 ( L_22 ,
V_41 ) ;
continue;
}
F_33 ( V_42 ) -> V_43 . V_265 ++ ;
V_43 = F_33 ( V_42 ) -> V_43 ;
if ( V_20 -> V_81 != 0 &&
F_33 ( V_42 ) -> V_43 . V_265 > V_20 -> V_81 ) {
F_21 ( L_23 , V_20 -> V_81 ) ;
F_83 ( V_20 , V_305 ) ;
F_42 ( & V_20 -> V_138 ) ;
break;
}
V_43 . V_192 = V_20 -> V_245 ;
if ( F_115 ( V_237 , & V_20 -> V_238 ) )
V_43 . V_195 = 1 ;
else
V_43 . V_195 = 0 ;
if ( F_191 ( V_42 ) ) {
V_360 = F_192 ( V_42 , V_51 ) ;
} else {
V_360 = F_186 ( V_42 , V_51 ) ;
}
if ( ! V_360 ) {
F_42 ( & V_20 -> V_138 ) ;
break;
}
if ( F_74 ( V_225 , & V_20 -> V_89 ) ) {
F_106 ( F_103 ( & V_43 ) ,
V_360 -> V_175 + V_229 ) ;
} else {
F_107 ( F_104 ( & V_43 ) ,
V_360 -> V_175 + V_229 ) ;
}
if ( V_20 -> V_79 == V_80 ) {
T_2 V_79 = F_113 ( 0 , ( T_3 * ) V_360 -> V_175 , V_360 -> V_174 ) ;
F_107 ( V_79 , F_112 ( V_360 ,
V_235 ) ) ;
}
F_95 ( V_20 , V_360 ) ;
F_21 ( L_24 , V_43 . V_44 ) ;
V_20 -> V_243 = V_20 -> V_245 ;
}
}
static void F_193 ( struct V_8 * V_20 ,
struct V_191 * V_43 )
{
F_21 ( L_10 , V_20 , V_43 ) ;
F_43 ( & V_20 -> V_138 , V_43 -> V_192 ) ;
F_190 ( V_20 ) ;
}
static void F_194 ( struct V_8 * V_20 ,
struct V_191 * V_43 )
{
struct V_38 * V_42 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( V_43 -> V_200 )
F_55 ( V_237 , & V_20 -> V_238 ) ;
F_42 ( & V_20 -> V_138 ) ;
if ( F_74 ( V_273 , & V_20 -> V_238 ) )
return;
if ( V_20 -> V_364 ) {
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_42 ) -> V_43 . V_44 == V_43 -> V_192 ||
V_42 == V_20 -> V_363 )
break;
}
F_195 (&chan->tx_q, skb) {
if ( V_42 == V_20 -> V_363 )
break;
F_43 ( & V_20 -> V_138 ,
F_33 ( V_42 ) -> V_43 . V_44 ) ;
}
F_190 ( V_20 ) ;
}
}
static void F_196 ( struct V_8 * V_20 )
{
struct V_191 V_43 ;
T_2 V_366 = F_197 ( V_20 , V_20 -> V_245 ,
V_20 -> V_243 ) ;
int V_367 ;
F_21 ( L_25 ,
V_20 , V_20 -> V_243 , V_20 -> V_245 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_199 = 1 ;
if ( F_74 ( V_244 , & V_20 -> V_238 ) &&
V_20 -> V_271 == V_368 ) {
F_77 ( V_20 ) ;
V_43 . V_203 = V_241 ;
V_43 . V_192 = V_20 -> V_245 ;
F_114 ( V_20 , & V_43 ) ;
} else {
if ( ! F_74 ( V_273 , & V_20 -> V_238 ) ) {
F_185 ( V_20 ) ;
if ( V_20 -> V_245 == V_20 -> V_243 )
V_366 = 0 ;
}
V_367 = V_20 -> V_86 ;
V_367 += V_367 << 1 ;
V_367 >>= 2 ;
F_21 ( L_26 , V_366 ,
V_367 ) ;
if ( V_366 >= V_367 ) {
F_77 ( V_20 ) ;
V_43 . V_203 = V_239 ;
V_43 . V_192 = V_20 -> V_245 ;
F_114 ( V_20 , & V_43 ) ;
V_366 = 0 ;
}
if ( V_366 )
F_198 ( V_20 ) ;
}
}
static inline int F_199 ( struct V_8 * V_20 ,
struct V_369 * V_370 , int V_174 ,
int V_371 , struct V_38 * V_42 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * * V_372 ;
int V_361 = 0 ;
if ( F_200 ( F_112 ( V_42 , V_371 ) , V_370 -> V_373 , V_371 ) )
return - V_374 ;
V_361 += V_371 ;
V_174 -= V_371 ;
V_372 = & F_201 ( V_42 ) -> V_375 ;
while ( V_174 ) {
struct V_38 * V_303 ;
V_371 = F_64 (unsigned int, conn->mtu, len) ;
V_303 = V_20 -> V_32 -> V_376 ( V_20 , V_371 ,
V_370 -> V_377 & V_378 ) ;
if ( F_117 ( V_303 ) )
return F_176 ( V_303 ) ;
* V_372 = V_303 ;
if ( F_200 ( F_112 ( * V_372 , V_371 ) , V_370 -> V_373 , V_371 ) )
return - V_374 ;
( * V_372 ) -> V_181 = V_42 -> V_181 ;
V_361 += V_371 ;
V_174 -= V_371 ;
V_42 -> V_174 += ( * V_372 ) -> V_174 ;
V_42 -> V_379 += ( * V_372 ) -> V_174 ;
V_372 = & ( * V_372 ) -> V_333 ;
}
return V_361 ;
}
static struct V_38 * F_202 ( struct V_8 * V_20 ,
struct V_369 * V_370 , T_7 V_174 ,
T_8 V_181 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_371 , V_234 = V_229 + V_380 ;
struct V_232 * V_233 ;
F_21 ( L_27 , V_20 ,
F_67 ( V_20 -> V_17 ) , V_174 , V_181 ) ;
V_371 = F_64 (unsigned int, (conn->mtu - hlen), len) ;
V_42 = V_20 -> V_32 -> V_376 ( V_20 , V_371 + V_234 ,
V_370 -> V_377 & V_378 ) ;
if ( F_117 ( V_42 ) )
return V_42 ;
V_42 -> V_181 = V_181 ;
V_233 = (struct V_232 * ) F_112 ( V_42 , V_229 ) ;
V_233 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_233 -> V_174 = F_16 ( V_174 + V_380 ) ;
F_203 ( V_20 -> V_17 , ( T_4 * ) F_112 ( V_42 , V_380 ) ) ;
V_21 = F_199 ( V_20 , V_370 , V_174 , V_371 , V_42 ) ;
if ( F_204 ( V_21 < 0 ) ) {
F_96 ( V_42 ) ;
return F_111 ( V_21 ) ;
}
return V_42 ;
}
static struct V_38 * F_205 ( struct V_8 * V_20 ,
struct V_369 * V_370 , T_7 V_174 ,
T_8 V_181 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_371 ;
struct V_232 * V_233 ;
F_21 ( L_28 , V_20 , V_174 ) ;
V_371 = F_64 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_42 = V_20 -> V_32 -> V_376 ( V_20 , V_371 + V_229 ,
V_370 -> V_377 & V_378 ) ;
if ( F_117 ( V_42 ) )
return V_42 ;
V_42 -> V_181 = V_181 ;
V_233 = (struct V_232 * ) F_112 ( V_42 , V_229 ) ;
V_233 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_233 -> V_174 = F_16 ( V_174 ) ;
V_21 = F_199 ( V_20 , V_370 , V_174 , V_371 , V_42 ) ;
if ( F_204 ( V_21 < 0 ) ) {
F_96 ( V_42 ) ;
return F_111 ( V_21 ) ;
}
return V_42 ;
}
static struct V_38 * F_206 ( struct V_8 * V_20 ,
struct V_369 * V_370 , T_7 V_174 ,
T_2 V_381 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_371 , V_234 ;
struct V_232 * V_233 ;
F_21 ( L_28 , V_20 , V_174 ) ;
if ( ! V_10 )
return F_111 ( - V_362 ) ;
V_234 = F_108 ( V_20 ) ;
if ( V_381 )
V_234 += V_382 ;
if ( V_20 -> V_79 == V_80 )
V_234 += V_235 ;
V_371 = F_64 (unsigned int, (conn->mtu - hlen), len) ;
V_42 = V_20 -> V_32 -> V_376 ( V_20 , V_371 + V_234 ,
V_370 -> V_377 & V_378 ) ;
if ( F_117 ( V_42 ) )
return V_42 ;
V_233 = (struct V_232 * ) F_112 ( V_42 , V_229 ) ;
V_233 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_233 -> V_174 = F_16 ( V_174 + ( V_234 - V_229 ) ) ;
if ( F_74 ( V_225 , & V_20 -> V_89 ) )
F_106 ( 0 , F_112 ( V_42 , V_226 ) ) ;
else
F_107 ( 0 , F_112 ( V_42 , V_227 ) ) ;
if ( V_381 )
F_107 ( V_381 , F_112 ( V_42 , V_382 ) ) ;
V_21 = F_199 ( V_20 , V_370 , V_174 , V_371 , V_42 ) ;
if ( F_204 ( V_21 < 0 ) ) {
F_96 ( V_42 ) ;
return F_111 ( V_21 ) ;
}
F_33 ( V_42 ) -> V_43 . V_79 = V_20 -> V_79 ;
F_33 ( V_42 ) -> V_43 . V_265 = 0 ;
return V_42 ;
}
static int F_207 ( struct V_8 * V_20 ,
struct V_39 * V_383 ,
struct V_369 * V_370 , T_7 V_174 )
{
struct V_38 * V_42 ;
T_2 V_92 ;
T_7 V_384 ;
T_3 V_206 ;
F_21 ( L_29 , V_20 , V_370 , V_174 ) ;
V_384 = V_20 -> V_10 -> V_147 ;
if ( ! V_20 -> V_187 )
V_384 = F_64 ( T_7 , V_384 , V_385 ) ;
if ( V_20 -> V_79 )
V_384 -= V_235 ;
V_384 -= F_108 ( V_20 ) ;
V_384 = F_64 ( T_7 , V_384 , V_20 -> V_386 ) ;
if ( V_174 <= V_384 ) {
V_206 = V_387 ;
V_92 = 0 ;
V_384 = V_174 ;
} else {
V_206 = V_388 ;
V_92 = V_174 ;
V_384 -= V_382 ;
}
while ( V_174 > 0 ) {
V_42 = F_206 ( V_20 , V_370 , V_384 , V_92 ) ;
if ( F_117 ( V_42 ) ) {
F_208 ( V_383 ) ;
return F_176 ( V_42 ) ;
}
F_33 ( V_42 ) -> V_43 . V_206 = V_206 ;
F_209 ( V_383 , V_42 ) ;
V_174 -= V_384 ;
if ( V_92 ) {
V_92 = 0 ;
V_384 += V_382 ;
}
if ( V_174 <= V_384 ) {
V_206 = V_389 ;
V_384 = V_174 ;
} else {
V_206 = V_390 ;
}
}
return 0 ;
}
static struct V_38 * F_210 ( struct V_8 * V_20 ,
struct V_369 * V_370 ,
T_7 V_174 , T_2 V_381 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_38 * V_42 ;
int V_21 , V_371 , V_234 ;
struct V_232 * V_233 ;
F_21 ( L_28 , V_20 , V_174 ) ;
if ( ! V_10 )
return F_111 ( - V_362 ) ;
V_234 = V_229 ;
if ( V_381 )
V_234 += V_382 ;
V_371 = F_64 (unsigned int, (conn->mtu - hlen), len) ;
V_42 = V_20 -> V_32 -> V_376 ( V_20 , V_371 + V_234 ,
V_370 -> V_377 & V_378 ) ;
if ( F_117 ( V_42 ) )
return V_42 ;
V_233 = (struct V_232 * ) F_112 ( V_42 , V_229 ) ;
V_233 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_233 -> V_174 = F_16 ( V_174 + ( V_234 - V_229 ) ) ;
if ( V_381 )
F_107 ( V_381 , F_112 ( V_42 , V_382 ) ) ;
V_21 = F_199 ( V_20 , V_370 , V_174 , V_371 , V_42 ) ;
if ( F_204 ( V_21 < 0 ) ) {
F_96 ( V_42 ) ;
return F_111 ( V_21 ) ;
}
return V_42 ;
}
static int F_211 ( struct V_8 * V_20 ,
struct V_39 * V_383 ,
struct V_369 * V_370 , T_7 V_174 )
{
struct V_38 * V_42 ;
T_7 V_384 ;
T_2 V_92 ;
F_21 ( L_29 , V_20 , V_370 , V_174 ) ;
V_384 = V_20 -> V_10 -> V_147 - V_229 ;
V_384 = F_64 ( T_7 , V_384 , V_20 -> V_386 ) ;
V_92 = V_174 ;
V_384 -= V_382 ;
while ( V_174 > 0 ) {
if ( V_174 <= V_384 )
V_384 = V_174 ;
V_42 = F_210 ( V_20 , V_370 , V_384 , V_92 ) ;
if ( F_117 ( V_42 ) ) {
F_208 ( V_383 ) ;
return F_176 ( V_42 ) ;
}
F_209 ( V_383 , V_42 ) ;
V_174 -= V_384 ;
if ( V_92 ) {
V_92 = 0 ;
V_384 += V_382 ;
}
}
return 0 ;
}
int F_212 ( struct V_8 * V_20 , struct V_369 * V_370 , T_7 V_174 ,
T_8 V_181 )
{
struct V_38 * V_42 ;
int V_21 ;
struct V_39 V_383 ;
if ( ! V_20 -> V_10 )
return - V_362 ;
if ( V_20 -> V_102 == V_107 ) {
V_42 = F_202 ( V_20 , V_370 , V_174 , V_181 ) ;
if ( F_117 ( V_42 ) )
return F_176 ( V_42 ) ;
F_95 ( V_20 , V_42 ) ;
return V_174 ;
}
switch ( V_20 -> V_132 ) {
case V_134 :
if ( V_174 > V_20 -> V_105 )
return - V_391 ;
if ( ! V_20 -> V_93 )
return - V_392 ;
F_213 ( & V_383 ) ;
V_21 = F_211 ( V_20 , & V_383 , V_370 , V_174 ) ;
if ( V_20 -> V_31 != V_62 ) {
F_208 ( & V_383 ) ;
V_21 = - V_362 ;
}
if ( V_21 )
return V_21 ;
F_181 ( & V_383 , & V_20 -> V_99 ) ;
while ( V_20 -> V_93 && ! F_182 ( & V_20 -> V_99 ) ) {
F_95 ( V_20 , F_183 ( & V_20 -> V_99 ) ) ;
V_20 -> V_93 -- ;
}
if ( ! V_20 -> V_93 )
V_20 -> V_32 -> V_281 ( V_20 ) ;
V_21 = V_174 ;
break;
case V_133 :
if ( V_174 > V_20 -> V_105 )
return - V_391 ;
V_42 = F_205 ( V_20 , V_370 , V_174 , V_181 ) ;
if ( F_117 ( V_42 ) )
return F_176 ( V_42 ) ;
F_95 ( V_20 , V_42 ) ;
V_21 = V_174 ;
break;
case V_135 :
case V_139 :
if ( V_174 > V_20 -> V_105 ) {
V_21 = - V_391 ;
break;
}
F_213 ( & V_383 ) ;
V_21 = F_207 ( V_20 , & V_383 , V_370 , V_174 ) ;
if ( V_20 -> V_31 != V_62 ) {
F_208 ( & V_383 ) ;
V_21 = - V_362 ;
}
if ( V_21 )
break;
if ( V_20 -> V_132 == V_135 )
F_128 ( V_20 , NULL , & V_383 , V_393 ) ;
else
F_180 ( V_20 , & V_383 ) ;
V_21 = V_174 ;
F_208 ( & V_383 ) ;
break;
default:
F_21 ( L_30 , V_20 -> V_132 ) ;
V_21 = - V_353 ;
}
return V_21 ;
}
static void F_214 ( struct V_8 * V_20 , T_2 V_44 )
{
struct V_191 V_43 ;
T_2 V_41 ;
F_21 ( L_31 , V_20 , V_44 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_199 = 1 ;
V_43 . V_203 = V_242 ;
for ( V_41 = V_20 -> V_266 ; V_41 != V_44 ;
V_41 = F_184 ( V_20 , V_41 ) ) {
if ( ! F_31 ( & V_20 -> V_136 , V_41 ) ) {
V_43 . V_192 = V_41 ;
F_114 ( V_20 , & V_43 ) ;
F_43 ( & V_20 -> V_137 , V_41 ) ;
}
}
V_20 -> V_266 = F_184 ( V_20 , V_44 ) ;
}
static void F_215 ( struct V_8 * V_20 )
{
struct V_191 V_43 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_137 . V_55 == V_54 )
return;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_199 = 1 ;
V_43 . V_203 = V_242 ;
V_43 . V_192 = V_20 -> V_137 . V_55 ;
F_114 ( V_20 , & V_43 ) ;
}
static void F_216 ( struct V_8 * V_20 , T_2 V_44 )
{
struct V_191 V_43 ;
T_2 V_394 ;
T_2 V_41 ;
F_21 ( L_31 , V_20 , V_44 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_199 = 1 ;
V_43 . V_203 = V_242 ;
V_394 = V_20 -> V_137 . V_40 ;
do {
V_41 = F_41 ( & V_20 -> V_137 ) ;
if ( V_41 == V_44 || V_41 == V_54 )
break;
V_43 . V_192 = V_41 ;
F_114 ( V_20 , & V_43 ) ;
F_43 ( & V_20 -> V_137 , V_41 ) ;
} while ( V_20 -> V_137 . V_40 != V_394 );
}
static void F_217 ( struct V_8 * V_20 , T_2 V_192 )
{
struct V_38 * V_395 ;
T_2 V_396 ;
F_21 ( L_32 , V_20 , V_192 ) ;
if ( V_20 -> V_364 == 0 || V_192 == V_20 -> V_397 )
return;
F_21 ( L_33 ,
V_20 -> V_397 , V_20 -> V_364 ) ;
for ( V_396 = V_20 -> V_397 ; V_396 != V_192 ;
V_396 = F_184 ( V_20 , V_396 ) ) {
V_395 = F_31 ( & V_20 -> V_99 , V_396 ) ;
if ( V_395 ) {
F_218 ( V_395 , & V_20 -> V_99 ) ;
F_96 ( V_395 ) ;
V_20 -> V_364 -- ;
}
}
V_20 -> V_397 = V_192 ;
if ( V_20 -> V_364 == 0 )
F_30 ( V_20 ) ;
F_21 ( L_34 , V_20 -> V_364 ) ;
}
static void F_219 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_266 = V_20 -> V_245 ;
F_42 ( & V_20 -> V_137 ) ;
F_75 ( & V_20 -> V_136 ) ;
V_20 -> V_271 = V_368 ;
}
static void F_220 ( struct V_8 * V_20 ,
struct V_191 * V_43 ,
struct V_39 * V_357 , T_3 V_398 )
{
F_21 ( L_35 , V_20 , V_43 , V_357 ,
V_398 ) ;
switch ( V_398 ) {
case V_393 :
if ( V_20 -> V_363 == NULL )
V_20 -> V_363 = F_221 ( V_357 ) ;
F_181 ( V_357 , & V_20 -> V_99 ) ;
F_185 ( V_20 ) ;
break;
case V_399 :
F_21 ( L_36 ) ;
F_55 ( V_244 , & V_20 -> V_238 ) ;
if ( V_20 -> V_271 == V_400 ) {
F_219 ( V_20 ) ;
}
F_196 ( V_20 ) ;
break;
case V_401 :
F_21 ( L_37 ) ;
F_116 ( V_244 , & V_20 -> V_238 ) ;
if ( F_74 ( V_240 , & V_20 -> V_238 ) ) {
struct V_191 V_402 ;
memset ( & V_402 , 0 , sizeof( V_402 ) ) ;
V_402 . V_199 = 1 ;
V_402 . V_203 = V_239 ;
V_402 . V_200 = 1 ;
V_402 . V_192 = V_20 -> V_245 ;
F_114 ( V_20 , & V_402 ) ;
V_20 -> V_264 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_269 = V_403 ;
}
break;
case V_404 :
F_217 ( V_20 , V_43 -> V_192 ) ;
break;
case V_277 :
F_118 ( V_20 , 1 ) ;
V_20 -> V_264 = 1 ;
F_29 ( V_20 ) ;
F_77 ( V_20 ) ;
V_20 -> V_269 = V_403 ;
break;
case V_356 :
F_118 ( V_20 , 1 ) ;
V_20 -> V_264 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_269 = V_403 ;
break;
case V_405 :
break;
default:
break;
}
}
static void F_222 ( struct V_8 * V_20 ,
struct V_191 * V_43 ,
struct V_39 * V_357 , T_3 V_398 )
{
F_21 ( L_35 , V_20 , V_43 , V_357 ,
V_398 ) ;
switch ( V_398 ) {
case V_393 :
if ( V_20 -> V_363 == NULL )
V_20 -> V_363 = F_221 ( V_357 ) ;
F_181 ( V_357 , & V_20 -> V_99 ) ;
break;
case V_399 :
F_21 ( L_36 ) ;
F_55 ( V_244 , & V_20 -> V_238 ) ;
if ( V_20 -> V_271 == V_400 ) {
F_219 ( V_20 ) ;
}
F_196 ( V_20 ) ;
break;
case V_401 :
F_21 ( L_37 ) ;
F_116 ( V_244 , & V_20 -> V_238 ) ;
if ( F_74 ( V_240 , & V_20 -> V_238 ) ) {
struct V_191 V_402 ;
memset ( & V_402 , 0 , sizeof( V_402 ) ) ;
V_402 . V_199 = 1 ;
V_402 . V_203 = V_239 ;
V_402 . V_200 = 1 ;
V_402 . V_192 = V_20 -> V_245 ;
F_114 ( V_20 , & V_402 ) ;
V_20 -> V_264 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_269 = V_403 ;
}
break;
case V_404 :
F_217 ( V_20 , V_43 -> V_192 ) ;
case V_405 :
if ( V_43 && V_43 -> V_195 ) {
F_76 ( V_20 ) ;
if ( V_20 -> V_364 > 0 )
F_25 ( V_20 ) ;
V_20 -> V_264 = 0 ;
V_20 -> V_269 = V_270 ;
F_21 ( L_38 , V_20 -> V_269 ) ;
}
break;
case V_277 :
break;
case V_355 :
if ( V_20 -> V_81 == 0 || V_20 -> V_264 < V_20 -> V_81 ) {
F_118 ( V_20 , 1 ) ;
F_29 ( V_20 ) ;
V_20 -> V_264 ++ ;
} else {
F_83 ( V_20 , V_406 ) ;
}
break;
default:
break;
}
}
static void F_128 ( struct V_8 * V_20 , struct V_191 * V_43 ,
struct V_39 * V_357 , T_3 V_398 )
{
F_21 ( L_39 ,
V_20 , V_43 , V_357 , V_398 , V_20 -> V_269 ) ;
switch ( V_20 -> V_269 ) {
case V_270 :
F_220 ( V_20 , V_43 , V_357 , V_398 ) ;
break;
case V_403 :
F_222 ( V_20 , V_43 , V_357 , V_398 ) ;
break;
default:
break;
}
}
static void F_223 ( struct V_8 * V_20 ,
struct V_191 * V_43 )
{
F_21 ( L_10 , V_20 , V_43 ) ;
F_128 ( V_20 , V_43 , NULL , V_404 ) ;
}
static void F_224 ( struct V_8 * V_20 ,
struct V_191 * V_43 )
{
F_21 ( L_10 , V_20 , V_43 ) ;
F_128 ( V_20 , V_43 , NULL , V_405 ) ;
}
static void F_225 ( struct V_9 * V_10 , struct V_38 * V_42 )
{
struct V_38 * V_407 ;
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( V_20 -> V_102 != V_159 )
continue;
if ( F_33 ( V_42 ) -> V_20 == V_20 )
continue;
V_407 = F_186 ( V_42 , V_51 ) ;
if ( ! V_407 )
continue;
if ( V_20 -> V_32 -> V_408 ( V_20 , V_407 ) )
F_96 ( V_407 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static struct V_38 * F_91 ( struct V_9 * V_10 , T_3 V_173 ,
T_3 V_16 , T_2 V_409 , void * V_175 )
{
struct V_38 * V_42 , * * V_372 ;
struct V_410 * V_411 ;
struct V_232 * V_233 ;
int V_174 , V_371 ;
F_21 ( L_40 ,
V_10 , V_173 , V_16 , V_409 ) ;
if ( V_10 -> V_147 < V_229 + V_412 )
return NULL ;
V_174 = V_229 + V_412 + V_409 ;
V_371 = F_64 (unsigned int, conn->mtu, len) ;
V_42 = F_110 ( V_371 , V_51 ) ;
if ( ! V_42 )
return NULL ;
V_233 = (struct V_232 * ) F_112 ( V_42 , V_229 ) ;
V_233 -> V_174 = F_16 ( V_412 + V_409 ) ;
if ( V_10 -> V_2 -> type == V_3 )
V_233 -> V_11 = F_81 ( V_413 ) ;
else
V_233 -> V_11 = F_81 ( V_112 ) ;
V_411 = (struct V_410 * ) F_112 ( V_42 , V_412 ) ;
V_411 -> V_173 = V_173 ;
V_411 -> V_16 = V_16 ;
V_411 -> V_174 = F_16 ( V_409 ) ;
if ( V_409 ) {
V_371 -= V_229 + V_412 ;
memcpy ( F_112 ( V_42 , V_371 ) , V_175 , V_371 ) ;
V_175 += V_371 ;
}
V_174 -= V_42 -> V_174 ;
V_372 = & F_201 ( V_42 ) -> V_375 ;
while ( V_174 ) {
V_371 = F_64 (unsigned int, conn->mtu, len) ;
* V_372 = F_110 ( V_371 , V_51 ) ;
if ( ! * V_372 )
goto V_414;
memcpy ( F_112 ( * V_372 , V_371 ) , V_175 , V_371 ) ;
V_174 -= V_371 ;
V_175 += V_371 ;
V_372 = & ( * V_372 ) -> V_333 ;
}
return V_42 ;
V_414:
F_96 ( V_42 ) ;
return NULL ;
}
static inline int F_226 ( void * * V_415 , int * type , int * V_416 ,
unsigned long * V_417 )
{
struct V_418 * V_419 = * V_415 ;
int V_174 ;
V_174 = V_420 + V_419 -> V_174 ;
* V_415 += V_174 ;
* type = V_419 -> type ;
* V_416 = V_419 -> V_174 ;
switch ( V_419 -> V_174 ) {
case 1 :
* V_417 = * ( ( T_3 * ) V_419 -> V_417 ) ;
break;
case 2 :
* V_417 = F_102 ( V_419 -> V_417 ) ;
break;
case 4 :
* V_417 = F_100 ( V_419 -> V_417 ) ;
break;
default:
* V_417 = ( unsigned long ) V_419 -> V_417 ;
break;
}
F_21 ( L_41 , * type , V_419 -> V_174 , * V_417 ) ;
return V_174 ;
}
static void F_227 ( void * * V_415 , T_3 type , T_3 V_174 , unsigned long V_417 )
{
struct V_418 * V_419 = * V_415 ;
F_21 ( L_41 , type , V_174 , V_417 ) ;
V_419 -> type = type ;
V_419 -> V_174 = V_174 ;
switch ( V_174 ) {
case 1 :
* ( ( T_3 * ) V_419 -> V_417 ) = V_417 ;
break;
case 2 :
F_107 ( V_417 , V_419 -> V_417 ) ;
break;
case 4 :
F_106 ( V_417 , V_419 -> V_417 ) ;
break;
default:
memcpy ( V_419 -> V_417 , ( void * ) V_417 , V_174 ) ;
break;
}
* V_415 += V_420 + V_174 ;
}
static void F_228 ( void * * V_415 , struct V_8 * V_20 )
{
struct V_421 V_422 ;
switch ( V_20 -> V_132 ) {
case V_135 :
V_422 . V_171 = V_20 -> V_113 ;
V_422 . V_423 = V_20 -> V_115 ;
V_422 . V_424 = F_16 ( V_20 -> V_117 ) ;
V_422 . V_425 = F_229 ( V_20 -> V_119 ) ;
V_422 . V_426 = F_230 ( V_122 ) ;
V_422 . V_427 = F_230 ( V_124 ) ;
break;
case V_139 :
V_422 . V_171 = 1 ;
V_422 . V_423 = V_116 ;
V_422 . V_424 = F_16 ( V_20 -> V_117 ) ;
V_422 . V_425 = F_229 ( V_20 -> V_119 ) ;
V_422 . V_426 = 0 ;
V_422 . V_427 = 0 ;
break;
default:
return;
}
F_227 ( V_415 , V_428 , sizeof( V_422 ) ,
( unsigned long ) & V_422 ) ;
}
static void F_231 ( struct V_58 * V_59 )
{
struct V_8 * V_20 = F_45 ( V_59 , struct V_8 ,
V_429 . V_59 ) ;
T_2 V_366 ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
V_366 = F_197 ( V_20 , V_20 -> V_245 ,
V_20 -> V_243 ) ;
if ( V_366 )
F_118 ( V_20 , 0 ) ;
F_47 ( V_20 ) ;
F_48 ( V_20 ) ;
}
int F_232 ( struct V_8 * V_20 )
{
int V_21 ;
V_20 -> V_358 = 0 ;
V_20 -> V_266 = 0 ;
V_20 -> V_397 = 0 ;
V_20 -> V_364 = 0 ;
V_20 -> V_245 = 0 ;
V_20 -> V_359 = 0 ;
V_20 -> V_243 = 0 ;
V_20 -> V_90 = NULL ;
V_20 -> V_91 = NULL ;
V_20 -> V_92 = 0 ;
F_65 ( & V_20 -> V_99 ) ;
V_20 -> V_430 = V_431 ;
V_20 -> V_432 = V_431 ;
V_20 -> V_184 = V_185 ;
V_20 -> V_274 = V_275 ;
if ( V_20 -> V_132 != V_135 )
return 0 ;
V_20 -> V_271 = V_368 ;
V_20 -> V_269 = V_270 ;
F_53 ( & V_20 -> V_36 , F_179 ) ;
F_53 ( & V_20 -> V_34 , F_178 ) ;
F_53 ( & V_20 -> V_429 , F_231 ) ;
F_65 ( & V_20 -> V_136 ) ;
V_21 = F_34 ( & V_20 -> V_137 , V_20 -> V_83 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_34 ( & V_20 -> V_138 , V_20 -> V_365 ) ;
if ( V_21 < 0 )
F_37 ( & V_20 -> V_137 ) ;
return V_21 ;
}
static inline T_1 F_233 ( T_1 V_132 , T_6 V_433 )
{
switch ( V_132 ) {
case V_139 :
case V_135 :
if ( F_137 ( V_132 , V_433 ) )
return V_132 ;
default:
return V_133 ;
}
}
static inline bool F_234 ( struct V_9 * V_10 )
{
return V_10 -> V_249 && V_10 -> V_295 & V_434 ;
}
static inline bool F_235 ( struct V_9 * V_10 )
{
return V_10 -> V_249 && V_10 -> V_295 & V_435 ;
}
static void F_236 ( struct V_8 * V_20 ,
struct V_436 * V_437 )
{
if ( V_20 -> V_430 != V_431 && V_20 -> V_187 ) {
T_10 V_438 = V_20 -> V_187 -> V_176 -> V_439 ;
V_438 = F_237 ( V_438 , 1000 ) ;
V_438 = 3 * V_438 + 500 ;
if ( V_438 > 0xffff )
V_438 = 0xffff ;
V_437 -> V_35 = F_16 ( ( T_2 ) V_438 ) ;
V_437 -> V_37 = V_437 -> V_35 ;
} else {
V_437 -> V_35 = F_81 ( V_440 ) ;
V_437 -> V_37 = F_81 ( V_441 ) ;
}
}
static inline void F_238 ( struct V_8 * V_20 )
{
if ( V_20 -> V_83 > V_84 &&
F_234 ( V_20 -> V_10 ) ) {
F_55 ( V_225 , & V_20 -> V_89 ) ;
V_20 -> V_85 = V_442 ;
} else {
V_20 -> V_83 = F_64 ( T_2 , V_20 -> V_83 ,
V_84 ) ;
V_20 -> V_85 = V_84 ;
}
V_20 -> V_86 = V_20 -> V_83 ;
}
static int F_140 ( struct V_8 * V_20 , void * V_175 )
{
struct V_443 * V_259 = V_175 ;
struct V_436 V_437 = { . V_132 = V_20 -> V_132 } ;
void * V_415 = V_259 -> V_175 ;
T_2 V_47 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_314 || V_20 -> V_444 )
goto V_24;
switch ( V_20 -> V_132 ) {
case V_139 :
case V_135 :
if ( F_74 ( V_304 , & V_20 -> V_77 ) )
break;
if ( F_235 ( V_20 -> V_10 ) )
F_55 ( V_445 , & V_20 -> V_89 ) ;
default:
V_20 -> V_132 = F_233 ( V_437 . V_132 , V_20 -> V_10 -> V_295 ) ;
break;
}
V_24:
if ( V_20 -> V_97 != V_106 )
F_227 ( & V_415 , V_446 , 2 , V_20 -> V_97 ) ;
switch ( V_20 -> V_132 ) {
case V_133 :
if ( ! ( V_20 -> V_10 -> V_295 & V_299 ) &&
! ( V_20 -> V_10 -> V_295 & V_300 ) )
break;
V_437 . V_132 = V_133 ;
V_437 . V_447 = 0 ;
V_437 . V_448 = 0 ;
V_437 . V_35 = 0 ;
V_437 . V_37 = 0 ;
V_437 . V_449 = 0 ;
F_227 ( & V_415 , V_450 , sizeof( V_437 ) ,
( unsigned long ) & V_437 ) ;
break;
case V_135 :
V_437 . V_132 = V_135 ;
V_437 . V_448 = V_20 -> V_81 ;
F_236 ( V_20 , & V_437 ) ;
V_47 = F_64 ( T_2 , V_451 , V_20 -> V_10 -> V_147 -
V_230 - V_382 -
V_235 ) ;
V_437 . V_449 = F_16 ( V_47 ) ;
F_238 ( V_20 ) ;
V_437 . V_447 = F_64 ( T_2 , V_20 -> V_83 ,
V_84 ) ;
F_227 ( & V_415 , V_450 , sizeof( V_437 ) ,
( unsigned long ) & V_437 ) ;
if ( F_74 ( V_445 , & V_20 -> V_89 ) )
F_228 ( & V_415 , V_20 ) ;
if ( F_74 ( V_225 , & V_20 -> V_89 ) )
F_227 ( & V_415 , V_452 , 2 ,
V_20 -> V_83 ) ;
if ( V_20 -> V_10 -> V_295 & V_453 )
if ( V_20 -> V_79 == V_454 ||
F_74 ( V_455 , & V_20 -> V_77 ) ) {
V_20 -> V_79 = V_454 ;
F_227 ( & V_415 , V_456 , 1 ,
V_20 -> V_79 ) ;
}
break;
case V_139 :
F_238 ( V_20 ) ;
V_437 . V_132 = V_139 ;
V_437 . V_447 = 0 ;
V_437 . V_448 = 0 ;
V_437 . V_35 = 0 ;
V_437 . V_37 = 0 ;
V_47 = F_64 ( T_2 , V_451 , V_20 -> V_10 -> V_147 -
V_230 - V_382 -
V_235 ) ;
V_437 . V_449 = F_16 ( V_47 ) ;
F_227 ( & V_415 , V_450 , sizeof( V_437 ) ,
( unsigned long ) & V_437 ) ;
if ( F_74 ( V_445 , & V_20 -> V_89 ) )
F_228 ( & V_415 , V_20 ) ;
if ( V_20 -> V_10 -> V_295 & V_453 )
if ( V_20 -> V_79 == V_454 ||
F_74 ( V_455 , & V_20 -> V_77 ) ) {
V_20 -> V_79 = V_454 ;
F_227 ( & V_415 , V_456 , 1 ,
V_20 -> V_79 ) ;
}
break;
}
V_259 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_259 -> V_89 = F_81 ( 0 ) ;
return V_415 - V_175 ;
}
static int F_239 ( struct V_8 * V_20 , void * V_175 )
{
struct V_457 * V_141 = V_175 ;
void * V_415 = V_141 -> V_175 ;
void * V_259 = V_20 -> V_458 ;
int V_174 = V_20 -> V_459 ;
int type , V_460 , V_416 ;
unsigned long V_417 ;
struct V_436 V_437 = { . V_132 = V_133 } ;
struct V_421 V_422 ;
T_3 V_461 = 0 ;
T_2 V_147 = V_106 ;
T_2 V_142 = V_462 ;
T_2 V_47 ;
F_21 ( L_3 , V_20 ) ;
while ( V_174 >= V_420 ) {
V_174 -= F_226 ( & V_259 , & type , & V_416 , & V_417 ) ;
V_460 = type & V_463 ;
type &= V_464 ;
switch ( type ) {
case V_446 :
V_147 = V_417 ;
break;
case V_465 :
V_20 -> V_427 = V_417 ;
break;
case V_466 :
break;
case V_450 :
if ( V_416 == sizeof( V_437 ) )
memcpy ( & V_437 , ( void * ) V_417 , V_416 ) ;
break;
case V_456 :
if ( V_417 == V_454 )
F_55 ( V_455 , & V_20 -> V_77 ) ;
break;
case V_428 :
V_461 = 1 ;
if ( V_416 == sizeof( V_422 ) )
memcpy ( & V_422 , ( void * ) V_417 , V_416 ) ;
break;
case V_452 :
if ( ! V_20 -> V_10 -> V_249 )
return - V_64 ;
F_55 ( V_225 , & V_20 -> V_89 ) ;
F_55 ( V_467 , & V_20 -> V_77 ) ;
V_20 -> V_85 = V_442 ;
V_20 -> V_365 = V_417 ;
break;
default:
if ( V_460 )
break;
V_142 = V_468 ;
* ( ( T_3 * ) V_415 ++ ) = type ;
break;
}
}
if ( V_20 -> V_444 || V_20 -> V_314 > 1 )
goto V_24;
switch ( V_20 -> V_132 ) {
case V_139 :
case V_135 :
if ( ! F_74 ( V_304 , & V_20 -> V_77 ) ) {
V_20 -> V_132 = F_233 ( V_437 . V_132 ,
V_20 -> V_10 -> V_295 ) ;
break;
}
if ( V_461 ) {
if ( F_235 ( V_20 -> V_10 ) )
F_55 ( V_445 , & V_20 -> V_89 ) ;
else
return - V_64 ;
}
if ( V_20 -> V_132 != V_437 . V_132 )
return - V_64 ;
break;
}
V_24:
if ( V_20 -> V_132 != V_437 . V_132 ) {
V_142 = V_469 ;
V_437 . V_132 = V_20 -> V_132 ;
if ( V_20 -> V_444 == 1 )
return - V_64 ;
F_227 ( & V_415 , V_450 , sizeof( V_437 ) ,
( unsigned long ) & V_437 ) ;
}
if ( V_142 == V_462 ) {
if ( V_147 < V_470 )
V_142 = V_469 ;
else {
V_20 -> V_105 = V_147 ;
F_55 ( V_471 , & V_20 -> V_77 ) ;
}
F_227 ( & V_415 , V_446 , 2 , V_20 -> V_105 ) ;
if ( V_461 ) {
if ( V_20 -> V_115 != V_472 &&
V_422 . V_423 != V_472 &&
V_422 . V_423 != V_20 -> V_115 ) {
V_142 = V_469 ;
if ( V_20 -> V_314 >= 1 )
return - V_64 ;
F_227 ( & V_415 , V_428 ,
sizeof( V_422 ) ,
( unsigned long ) & V_422 ) ;
} else {
V_142 = V_473 ;
F_55 ( V_474 , & V_20 -> V_77 ) ;
}
}
switch ( V_437 . V_132 ) {
case V_133 :
V_20 -> V_79 = V_454 ;
F_55 ( V_475 , & V_20 -> V_77 ) ;
break;
case V_135 :
if ( ! F_74 ( V_467 , & V_20 -> V_77 ) )
V_20 -> V_365 = V_437 . V_447 ;
else
V_437 . V_447 = V_84 ;
V_20 -> V_476 = V_437 . V_448 ;
V_47 = F_64 ( T_2 , F_240 ( V_437 . V_449 ) ,
V_20 -> V_10 -> V_147 - V_230 -
V_382 - V_235 ) ;
V_437 . V_449 = F_16 ( V_47 ) ;
V_20 -> V_386 = V_47 ;
F_236 ( V_20 , & V_437 ) ;
F_55 ( V_475 , & V_20 -> V_77 ) ;
F_227 ( & V_415 , V_450 ,
sizeof( V_437 ) , ( unsigned long ) & V_437 ) ;
if ( F_74 ( V_445 , & V_20 -> V_89 ) ) {
V_20 -> V_477 = V_422 . V_171 ;
V_20 -> V_478 = V_422 . V_423 ;
V_20 -> V_479 = F_240 ( V_422 . V_424 ) ;
V_20 -> V_480 =
F_241 ( V_422 . V_427 ) ;
V_20 -> V_481 =
F_241 ( V_422 . V_426 ) ;
V_20 -> V_482 =
F_241 ( V_422 . V_425 ) ;
F_227 ( & V_415 , V_428 ,
sizeof( V_422 ) ,
( unsigned long ) & V_422 ) ;
}
break;
case V_139 :
V_47 = F_64 ( T_2 , F_240 ( V_437 . V_449 ) ,
V_20 -> V_10 -> V_147 - V_230 -
V_382 - V_235 ) ;
V_437 . V_449 = F_16 ( V_47 ) ;
V_20 -> V_386 = V_47 ;
F_55 ( V_475 , & V_20 -> V_77 ) ;
F_227 ( & V_415 , V_450 , sizeof( V_437 ) ,
( unsigned long ) & V_437 ) ;
break;
default:
V_142 = V_469 ;
memset ( & V_437 , 0 , sizeof( V_437 ) ) ;
V_437 . V_132 = V_20 -> V_132 ;
}
if ( V_142 == V_462 )
F_55 ( V_483 , & V_20 -> V_77 ) ;
}
V_141 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_141 -> V_142 = F_16 ( V_142 ) ;
V_141 -> V_89 = F_81 ( 0 ) ;
return V_415 - V_175 ;
}
static int F_242 ( struct V_8 * V_20 , void * V_141 , int V_174 ,
void * V_175 , T_2 * V_142 )
{
struct V_443 * V_259 = V_175 ;
void * V_415 = V_259 -> V_175 ;
int type , V_416 ;
unsigned long V_417 ;
struct V_436 V_437 = { . V_132 = V_133 } ;
struct V_421 V_422 ;
F_21 ( L_42 , V_20 , V_141 , V_174 , V_175 ) ;
while ( V_174 >= V_420 ) {
V_174 -= F_226 ( & V_141 , & type , & V_416 , & V_417 ) ;
switch ( type ) {
case V_446 :
if ( V_417 < V_470 ) {
* V_142 = V_469 ;
V_20 -> V_97 = V_470 ;
} else
V_20 -> V_97 = V_417 ;
F_227 ( & V_415 , V_446 , 2 , V_20 -> V_97 ) ;
break;
case V_465 :
V_20 -> V_427 = V_417 ;
F_227 ( & V_415 , V_465 ,
2 , V_20 -> V_427 ) ;
break;
case V_450 :
if ( V_416 == sizeof( V_437 ) )
memcpy ( & V_437 , ( void * ) V_417 , V_416 ) ;
if ( F_74 ( V_304 , & V_20 -> V_77 ) &&
V_437 . V_132 != V_20 -> V_132 )
return - V_64 ;
V_20 -> V_79 = 0 ;
F_227 ( & V_415 , V_450 ,
sizeof( V_437 ) , ( unsigned long ) & V_437 ) ;
break;
case V_452 :
V_20 -> V_86 = F_64 ( T_2 , V_417 , V_20 -> V_86 ) ;
F_227 ( & V_415 , V_452 , 2 ,
V_20 -> V_83 ) ;
break;
case V_428 :
if ( V_416 == sizeof( V_422 ) )
memcpy ( & V_422 , ( void * ) V_417 , V_416 ) ;
if ( V_20 -> V_115 != V_472 &&
V_422 . V_423 != V_472 &&
V_422 . V_423 != V_20 -> V_115 )
return - V_64 ;
F_227 ( & V_415 , V_428 , sizeof( V_422 ) ,
( unsigned long ) & V_422 ) ;
break;
case V_456 :
if ( * V_142 == V_473 )
if ( V_417 == V_454 )
F_55 ( V_455 ,
& V_20 -> V_77 ) ;
break;
}
}
if ( V_20 -> V_132 == V_133 && V_20 -> V_132 != V_437 . V_132 )
return - V_64 ;
V_20 -> V_132 = V_437 . V_132 ;
if ( * V_142 == V_462 || * V_142 == V_473 ) {
switch ( V_437 . V_132 ) {
case V_135 :
V_20 -> V_35 = F_240 ( V_437 . V_35 ) ;
V_20 -> V_37 = F_240 ( V_437 . V_37 ) ;
V_20 -> V_96 = F_240 ( V_437 . V_449 ) ;
if ( ! F_74 ( V_225 , & V_20 -> V_89 ) )
V_20 -> V_86 = F_64 ( T_2 , V_20 -> V_86 ,
V_437 . V_447 ) ;
if ( F_74 ( V_445 , & V_20 -> V_89 ) ) {
V_20 -> V_117 = F_240 ( V_422 . V_424 ) ;
V_20 -> V_119 =
F_241 ( V_422 . V_425 ) ;
V_20 -> V_121 = F_241 ( V_422 . V_426 ) ;
V_20 -> V_123 =
F_241 ( V_422 . V_427 ) ;
}
break;
case V_139 :
V_20 -> V_96 = F_240 ( V_437 . V_449 ) ;
}
}
V_259 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_259 -> V_89 = F_81 ( 0 ) ;
return V_415 - V_175 ;
}
static int F_243 ( struct V_8 * V_20 , void * V_175 ,
T_2 V_142 , T_2 V_89 )
{
struct V_457 * V_141 = V_175 ;
void * V_415 = V_141 -> V_175 ;
F_21 ( L_3 , V_20 ) ;
V_141 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_141 -> V_142 = F_16 ( V_142 ) ;
V_141 -> V_89 = F_16 ( V_89 ) ;
return V_415 - V_175 ;
}
void F_244 ( struct V_8 * V_20 )
{
struct V_140 V_141 ;
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_3 , V_20 ) ;
V_141 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_141 . V_147 = F_16 ( V_20 -> V_97 ) ;
V_141 . V_96 = F_16 ( V_20 -> V_96 ) ;
V_141 . V_148 = F_16 ( V_20 -> V_94 ) ;
V_141 . V_142 = F_81 ( V_310 ) ;
F_79 ( V_10 , V_20 -> V_16 , V_149 , sizeof( V_141 ) ,
& V_141 ) ;
}
void F_245 ( struct V_8 * V_20 )
{
struct V_150 V_141 ;
struct V_9 * V_10 = V_20 -> V_10 ;
T_3 V_306 [ 128 ] ;
T_3 V_484 ;
V_141 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_141 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_141 . V_142 = F_81 ( V_310 ) ;
V_141 . V_152 = F_81 ( V_153 ) ;
if ( V_20 -> V_187 )
V_484 = V_485 ;
else
V_484 = V_154 ;
F_21 ( L_43 , V_20 , V_484 ) ;
F_79 ( V_10 , V_20 -> V_16 , V_484 , sizeof( V_141 ) , & V_141 ) ;
if ( F_131 ( V_312 , & V_20 -> V_77 ) )
return;
F_79 ( V_10 , F_88 ( V_10 ) , V_313 ,
F_140 ( V_20 , V_306 ) , V_306 ) ;
V_20 -> V_314 ++ ;
}
static void F_246 ( struct V_8 * V_20 , void * V_141 , int V_174 )
{
int type , V_416 ;
unsigned long V_417 ;
T_2 V_486 = V_20 -> V_86 ;
struct V_436 V_437 = {
. V_132 = V_20 -> V_132 ,
. V_35 = F_81 ( V_440 ) ,
. V_37 = F_81 ( V_441 ) ,
. V_449 = F_16 ( V_20 -> V_97 ) ,
. V_447 = F_64 ( T_2 , V_20 -> V_86 , V_84 ) ,
} ;
F_21 ( L_44 , V_20 , V_141 , V_174 ) ;
if ( ( V_20 -> V_132 != V_135 ) && ( V_20 -> V_132 != V_139 ) )
return;
while ( V_174 >= V_420 ) {
V_174 -= F_226 ( & V_141 , & type , & V_416 , & V_417 ) ;
switch ( type ) {
case V_450 :
if ( V_416 == sizeof( V_437 ) )
memcpy ( & V_437 , ( void * ) V_417 , V_416 ) ;
break;
case V_452 :
V_486 = V_417 ;
break;
}
}
switch ( V_437 . V_132 ) {
case V_135 :
V_20 -> V_35 = F_240 ( V_437 . V_35 ) ;
V_20 -> V_37 = F_240 ( V_437 . V_37 ) ;
V_20 -> V_96 = F_240 ( V_437 . V_449 ) ;
if ( F_74 ( V_225 , & V_20 -> V_89 ) )
V_20 -> V_86 = F_64 ( T_2 , V_20 -> V_86 , V_486 ) ;
else
V_20 -> V_86 = F_64 ( T_2 , V_20 -> V_86 ,
V_437 . V_447 ) ;
break;
case V_139 :
V_20 -> V_96 = F_240 ( V_437 . V_449 ) ;
}
}
static inline int F_247 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
struct V_488 * V_489 = (struct V_488 * ) V_175 ;
if ( V_487 < sizeof( * V_489 ) )
return - V_490 ;
if ( V_489 -> V_61 != V_491 )
return 0 ;
if ( ( V_10 -> V_286 & V_287 ) &&
V_411 -> V_16 == V_10 -> V_291 ) {
F_248 ( & V_10 -> V_292 ) ;
V_10 -> V_286 |= V_288 ;
V_10 -> V_291 = 0 ;
F_138 ( V_10 ) ;
}
return 0 ;
}
static struct V_8 * F_249 ( struct V_9 * V_10 ,
struct V_410 * V_411 ,
T_3 * V_175 , T_3 V_484 , T_3 V_261 )
{
struct V_258 * V_259 = (struct V_258 * ) V_175 ;
struct V_150 V_141 ;
struct V_8 * V_20 = NULL , * V_322 ;
int V_142 , V_152 = V_153 ;
T_2 V_13 = 0 , V_14 = F_67 ( V_259 -> V_14 ) ;
T_4 V_17 = V_259 -> V_17 ;
F_21 ( L_45 , F_67 ( V_17 ) , V_14 ) ;
V_322 = F_170 ( V_155 , V_17 , & V_10 -> V_2 -> V_18 ,
& V_10 -> V_2 -> V_315 , V_158 ) ;
if ( ! V_322 ) {
V_142 = V_145 ;
goto V_492;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_322 ) ;
if ( V_17 != F_81 ( V_167 ) &&
! F_250 ( V_10 -> V_2 ) ) {
V_10 -> V_100 = V_493 ;
V_142 = V_151 ;
goto V_494;
}
V_142 = V_495 ;
if ( F_2 ( V_10 , V_14 ) )
goto V_494;
V_20 = V_322 -> V_32 -> V_324 ( V_322 ) ;
if ( ! V_20 )
goto V_494;
V_10 -> V_2 -> V_496 = V_497 ;
F_145 ( & V_20 -> V_18 , & V_10 -> V_2 -> V_18 ) ;
F_145 ( & V_20 -> V_315 , & V_10 -> V_2 -> V_315 ) ;
V_20 -> V_326 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_326 ) ;
V_20 -> V_323 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_323 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_14 ;
V_20 -> V_430 = V_261 ;
F_66 ( V_10 , V_20 ) ;
V_13 = V_20 -> V_14 ;
F_82 ( V_20 , V_20 -> V_32 -> V_156 ( V_20 ) ) ;
V_20 -> V_16 = V_411 -> V_16 ;
if ( V_10 -> V_286 & V_288 ) {
if ( F_85 ( V_20 ) ) {
if ( F_74 ( V_143 , & V_20 -> V_89 ) ) {
F_20 ( V_20 , V_157 ) ;
V_142 = V_307 ;
V_152 = V_308 ;
V_20 -> V_32 -> V_309 ( V_20 ) ;
} else {
if ( V_261 == V_431 ) {
F_20 ( V_20 , V_63 ) ;
V_142 = V_310 ;
} else {
F_20 ( V_20 , V_157 ) ;
V_142 = V_307 ;
}
V_152 = V_153 ;
}
} else {
F_20 ( V_20 , V_157 ) ;
V_142 = V_307 ;
V_152 = V_311 ;
}
} else {
F_20 ( V_20 , V_157 ) ;
V_142 = V_307 ;
V_152 = V_153 ;
}
V_494:
F_47 ( V_322 ) ;
F_8 ( & V_10 -> V_15 ) ;
V_492:
V_141 . V_14 = F_16 ( V_14 ) ;
V_141 . V_13 = F_16 ( V_13 ) ;
V_141 . V_142 = F_16 ( V_142 ) ;
V_141 . V_152 = F_16 ( V_152 ) ;
F_79 ( V_10 , V_411 -> V_16 , V_484 , sizeof( V_141 ) , & V_141 ) ;
if ( V_142 == V_307 && V_152 == V_153 ) {
struct V_289 V_498 ;
V_498 . type = F_81 ( V_290 ) ;
V_10 -> V_286 |= V_287 ;
V_10 -> V_291 = F_88 ( V_10 ) ;
F_136 ( & V_10 -> V_292 , V_293 ) ;
F_79 ( V_10 , V_10 -> V_291 , V_294 ,
sizeof( V_498 ) , & V_498 ) ;
}
if ( V_20 && ! F_74 ( V_312 , & V_20 -> V_77 ) &&
V_142 == V_310 ) {
T_3 V_306 [ 128 ] ;
F_55 ( V_312 , & V_20 -> V_77 ) ;
F_79 ( V_10 , F_88 ( V_10 ) , V_313 ,
F_140 ( V_20 , V_306 ) , V_306 ) ;
V_20 -> V_314 ++ ;
}
return V_20 ;
}
static int F_251 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 , T_3 * V_175 )
{
struct V_247 * V_176 = V_10 -> V_2 -> V_176 ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_487 < sizeof( struct V_258 ) )
return - V_490 ;
F_150 ( V_176 ) ;
if ( F_74 ( V_499 , & V_176 -> V_347 ) &&
! F_131 ( V_500 , & V_2 -> V_89 ) )
F_252 ( V_176 , & V_2 -> V_315 , V_2 -> type ,
V_2 -> V_323 , 0 , NULL , 0 ,
V_2 -> V_501 ) ;
F_151 ( V_176 ) ;
F_249 ( V_10 , V_411 , V_175 , V_154 , 0 ) ;
return 0 ;
}
static int F_253 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
struct V_150 * V_141 = (struct V_150 * ) V_175 ;
T_2 V_14 , V_13 , V_142 , V_152 ;
struct V_8 * V_20 ;
T_3 V_259 [ 128 ] ;
int V_21 ;
if ( V_487 < sizeof( * V_141 ) )
return - V_490 ;
V_14 = F_67 ( V_141 -> V_14 ) ;
V_13 = F_67 ( V_141 -> V_13 ) ;
V_142 = F_67 ( V_141 -> V_142 ) ;
V_152 = F_67 ( V_141 -> V_152 ) ;
F_21 ( L_46 ,
V_13 , V_14 , V_142 , V_152 ) ;
F_6 ( & V_10 -> V_15 ) ;
if ( V_14 ) {
V_20 = F_4 ( V_10 , V_14 ) ;
if ( ! V_20 ) {
V_21 = - V_502 ;
goto V_503;
}
} else {
V_20 = F_10 ( V_10 , V_411 -> V_16 ) ;
if ( ! V_20 ) {
V_21 = - V_502 ;
goto V_503;
}
}
V_21 = 0 ;
F_7 ( V_20 ) ;
switch ( V_142 ) {
case V_310 :
F_20 ( V_20 , V_63 ) ;
V_20 -> V_16 = 0 ;
V_20 -> V_13 = V_13 ;
F_116 ( V_246 , & V_20 -> V_77 ) ;
if ( F_131 ( V_312 , & V_20 -> V_77 ) )
break;
F_79 ( V_10 , F_88 ( V_10 ) , V_313 ,
F_140 ( V_20 , V_259 ) , V_259 ) ;
V_20 -> V_314 ++ ;
break;
case V_307 :
F_55 ( V_246 , & V_20 -> V_77 ) ;
break;
default:
F_70 ( V_20 , V_64 ) ;
break;
}
F_47 ( V_20 ) ;
V_503:
F_8 ( & V_10 -> V_15 ) ;
return V_21 ;
}
static inline void F_254 ( struct V_8 * V_20 )
{
if ( V_20 -> V_132 != V_135 && V_20 -> V_132 != V_139 )
V_20 -> V_79 = V_454 ;
else if ( ! F_74 ( V_455 , & V_20 -> V_77 ) )
V_20 -> V_79 = V_80 ;
}
static void F_255 ( struct V_8 * V_20 , void * V_175 ,
T_3 V_16 , T_2 V_89 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_47 , V_10 , V_20 , V_16 ,
V_89 ) ;
F_116 ( V_474 , & V_20 -> V_77 ) ;
F_55 ( V_483 , & V_20 -> V_77 ) ;
F_79 ( V_10 , V_16 , V_504 ,
F_243 ( V_20 , V_175 ,
V_462 , V_89 ) , V_175 ) ;
}
static void F_256 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_14 , T_2 V_13 )
{
struct V_505 V_489 ;
V_489 . V_61 = F_81 ( V_506 ) ;
V_489 . V_14 = F_257 ( V_14 ) ;
V_489 . V_13 = F_257 ( V_13 ) ;
F_79 ( V_10 , V_16 , V_507 , sizeof( V_489 ) , & V_489 ) ;
}
static inline int F_258 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
struct V_443 * V_259 = (struct V_443 * ) V_175 ;
T_2 V_13 , V_89 ;
T_3 V_141 [ 64 ] ;
struct V_8 * V_20 ;
int V_174 , V_21 = 0 ;
if ( V_487 < sizeof( * V_259 ) )
return - V_490 ;
V_13 = F_67 ( V_259 -> V_13 ) ;
V_89 = F_67 ( V_259 -> V_89 ) ;
F_21 ( L_48 , V_13 , V_89 ) ;
V_20 = F_5 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_256 ( V_10 , V_411 -> V_16 , V_13 , 0 ) ;
return 0 ;
}
if ( V_20 -> V_31 != V_63 && V_20 -> V_31 != V_157 ) {
F_256 ( V_10 , V_411 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
goto V_503;
}
V_174 = V_487 - sizeof( * V_259 ) ;
if ( V_20 -> V_459 + V_174 > sizeof( V_20 -> V_458 ) ) {
F_79 ( V_10 , V_411 -> V_16 , V_504 ,
F_243 ( V_20 , V_141 ,
V_508 , V_89 ) , V_141 ) ;
goto V_503;
}
memcpy ( V_20 -> V_458 + V_20 -> V_459 , V_259 -> V_175 , V_174 ) ;
V_20 -> V_459 += V_174 ;
if ( V_89 & V_509 ) {
F_79 ( V_10 , V_411 -> V_16 , V_504 ,
F_243 ( V_20 , V_141 ,
V_462 , V_89 ) , V_141 ) ;
goto V_503;
}
V_174 = F_239 ( V_20 , V_141 ) ;
if ( V_174 < 0 ) {
F_83 ( V_20 , V_305 ) ;
goto V_503;
}
V_20 -> V_16 = V_411 -> V_16 ;
F_79 ( V_10 , V_411 -> V_16 , V_504 , V_174 , V_141 ) ;
V_20 -> V_444 ++ ;
V_20 -> V_459 = 0 ;
if ( ! F_74 ( V_483 , & V_20 -> V_77 ) )
goto V_503;
if ( F_74 ( V_510 , & V_20 -> V_77 ) ) {
F_254 ( V_20 ) ;
if ( V_20 -> V_132 == V_135 ||
V_20 -> V_132 == V_139 )
V_21 = F_232 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_129 ( V_20 ) ;
goto V_503;
}
if ( ! F_131 ( V_312 , & V_20 -> V_77 ) ) {
T_3 V_306 [ 64 ] ;
F_79 ( V_10 , F_88 ( V_10 ) , V_313 ,
F_140 ( V_20 , V_306 ) , V_306 ) ;
V_20 -> V_314 ++ ;
}
if ( F_74 ( V_511 , & V_20 -> V_77 ) &&
F_74 ( V_474 , & V_20 -> V_77 ) ) {
if ( ! V_20 -> V_187 )
F_255 ( V_20 , V_141 , V_411 -> V_16 , V_89 ) ;
else
V_20 -> V_16 = V_411 -> V_16 ;
}
V_503:
F_47 ( V_20 ) ;
return V_21 ;
}
static inline int F_259 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
struct V_457 * V_141 = (struct V_457 * ) V_175 ;
T_2 V_14 , V_89 , V_142 ;
struct V_8 * V_20 ;
int V_174 = V_487 - sizeof( * V_141 ) ;
int V_21 = 0 ;
if ( V_487 < sizeof( * V_141 ) )
return - V_490 ;
V_14 = F_67 ( V_141 -> V_14 ) ;
V_89 = F_67 ( V_141 -> V_89 ) ;
V_142 = F_67 ( V_141 -> V_142 ) ;
F_21 ( L_49 , V_14 , V_89 ,
V_142 , V_174 ) ;
V_20 = F_5 ( V_10 , V_14 ) ;
if ( ! V_20 )
return 0 ;
switch ( V_142 ) {
case V_462 :
F_246 ( V_20 , V_141 -> V_175 , V_174 ) ;
F_116 ( V_511 , & V_20 -> V_77 ) ;
break;
case V_473 :
F_55 ( V_511 , & V_20 -> V_77 ) ;
if ( F_74 ( V_474 , & V_20 -> V_77 ) ) {
char V_306 [ 64 ] ;
V_174 = F_242 ( V_20 , V_141 -> V_175 , V_174 ,
V_306 , & V_142 ) ;
if ( V_174 < 0 ) {
F_83 ( V_20 , V_305 ) ;
goto V_24;
}
if ( ! V_20 -> V_187 ) {
F_255 ( V_20 , V_306 , V_411 -> V_16 ,
0 ) ;
} else {
if ( F_123 ( V_20 ) ) {
F_260 ( V_20 ) ;
V_20 -> V_16 = V_411 -> V_16 ;
}
}
}
goto V_24;
case V_469 :
if ( V_20 -> V_444 <= V_512 ) {
char V_259 [ 64 ] ;
if ( V_174 > sizeof( V_259 ) - sizeof( struct V_443 ) ) {
F_83 ( V_20 , V_305 ) ;
goto V_24;
}
V_142 = V_462 ;
V_174 = F_242 ( V_20 , V_141 -> V_175 , V_174 ,
V_259 , & V_142 ) ;
if ( V_174 < 0 ) {
F_83 ( V_20 , V_305 ) ;
goto V_24;
}
F_79 ( V_10 , F_88 ( V_10 ) ,
V_313 , V_174 , V_259 ) ;
V_20 -> V_314 ++ ;
if ( V_142 != V_462 )
goto V_24;
break;
}
default:
F_24 ( V_20 , V_305 ) ;
F_82 ( V_20 , V_513 ) ;
F_83 ( V_20 , V_305 ) ;
goto V_24;
}
if ( V_89 & V_509 )
goto V_24;
F_55 ( V_510 , & V_20 -> V_77 ) ;
if ( F_74 ( V_483 , & V_20 -> V_77 ) ) {
F_254 ( V_20 ) ;
if ( V_20 -> V_132 == V_135 ||
V_20 -> V_132 == V_139 )
V_21 = F_232 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_129 ( V_20 ) ;
}
V_24:
F_47 ( V_20 ) ;
return V_21 ;
}
static inline int F_261 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
struct V_301 * V_259 = (struct V_301 * ) V_175 ;
struct V_514 V_141 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_487 != sizeof( * V_259 ) )
return - V_490 ;
V_14 = F_67 ( V_259 -> V_14 ) ;
V_13 = F_67 ( V_259 -> V_13 ) ;
F_21 ( L_50 , V_14 , V_13 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_4 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_8 ( & V_10 -> V_15 ) ;
F_256 ( V_10 , V_411 -> V_16 , V_13 , V_14 ) ;
return 0 ;
}
F_7 ( V_20 ) ;
V_141 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_141 . V_14 = F_16 ( V_20 -> V_13 ) ;
F_79 ( V_10 , V_411 -> V_16 , V_515 , sizeof( V_141 ) , & V_141 ) ;
V_20 -> V_32 -> V_516 ( V_20 ) ;
F_58 ( V_20 ) ;
F_70 ( V_20 , V_305 ) ;
F_47 ( V_20 ) ;
V_20 -> V_32 -> V_69 ( V_20 ) ;
F_48 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_262 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
struct V_514 * V_141 = (struct V_514 * ) V_175 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_487 != sizeof( * V_141 ) )
return - V_490 ;
V_14 = F_67 ( V_141 -> V_14 ) ;
V_13 = F_67 ( V_141 -> V_13 ) ;
F_21 ( L_51 , V_13 , V_14 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_4 ( V_10 , V_14 ) ;
if ( ! V_20 ) {
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
F_7 ( V_20 ) ;
F_58 ( V_20 ) ;
F_70 ( V_20 , 0 ) ;
F_47 ( V_20 ) ;
V_20 -> V_32 -> V_69 ( V_20 ) ;
F_48 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_263 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
struct V_289 * V_259 = (struct V_289 * ) V_175 ;
T_2 type ;
if ( V_487 != sizeof( * V_259 ) )
return - V_490 ;
type = F_67 ( V_259 -> type ) ;
F_21 ( L_52 , type ) ;
if ( type == V_290 ) {
T_3 V_306 [ 8 ] ;
T_8 V_295 = V_297 ;
struct V_517 * V_141 = (struct V_517 * ) V_306 ;
V_141 -> type = F_81 ( V_290 ) ;
V_141 -> V_142 = F_81 ( V_518 ) ;
if ( ! V_298 )
V_295 |= V_299 | V_300
| V_453 ;
if ( V_10 -> V_249 )
V_295 |= V_435
| V_434 ;
F_106 ( V_295 , V_141 -> V_175 ) ;
F_79 ( V_10 , V_411 -> V_16 , V_519 , sizeof( V_306 ) ,
V_306 ) ;
} else if ( type == V_520 ) {
T_3 V_306 [ 12 ] ;
struct V_517 * V_141 = (struct V_517 * ) V_306 ;
if ( V_10 -> V_249 )
V_521 [ 0 ] |= V_251 ;
else
V_521 [ 0 ] &= ~ V_251 ;
V_141 -> type = F_81 ( V_520 ) ;
V_141 -> V_142 = F_81 ( V_518 ) ;
memcpy ( V_141 -> V_175 , V_521 , sizeof( V_521 ) ) ;
F_79 ( V_10 , V_411 -> V_16 , V_519 , sizeof( V_306 ) ,
V_306 ) ;
} else {
struct V_517 V_141 ;
V_141 . type = F_16 ( type ) ;
V_141 . V_142 = F_81 ( V_522 ) ;
F_79 ( V_10 , V_411 -> V_16 , V_519 , sizeof( V_141 ) ,
& V_141 ) ;
}
return 0 ;
}
static inline int F_264 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
struct V_517 * V_141 = (struct V_517 * ) V_175 ;
T_2 type , V_142 ;
if ( V_487 < sizeof( * V_141 ) )
return - V_490 ;
type = F_67 ( V_141 -> type ) ;
V_142 = F_67 ( V_141 -> V_142 ) ;
F_21 ( L_53 , type , V_142 ) ;
if ( V_411 -> V_16 != V_10 -> V_291 ||
V_10 -> V_286 & V_288 )
return 0 ;
F_248 ( & V_10 -> V_292 ) ;
if ( V_142 != V_518 ) {
V_10 -> V_286 |= V_288 ;
V_10 -> V_291 = 0 ;
F_138 ( V_10 ) ;
return 0 ;
}
switch ( type ) {
case V_290 :
V_10 -> V_295 = F_100 ( V_141 -> V_175 ) ;
if ( V_10 -> V_295 & V_523 ) {
struct V_289 V_259 ;
V_259 . type = F_81 ( V_520 ) ;
V_10 -> V_291 = F_88 ( V_10 ) ;
F_79 ( V_10 , V_10 -> V_291 ,
V_294 , sizeof( V_259 ) , & V_259 ) ;
} else {
V_10 -> V_286 |= V_288 ;
V_10 -> V_291 = 0 ;
F_138 ( V_10 ) ;
}
break;
case V_520 :
V_10 -> V_250 = V_141 -> V_175 [ 0 ] ;
V_10 -> V_286 |= V_288 ;
V_10 -> V_291 = 0 ;
F_138 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_265 ( struct V_9 * V_10 ,
struct V_410 * V_411 ,
T_2 V_487 , void * V_175 )
{
struct V_262 * V_259 = V_175 ;
struct V_524 V_141 ;
struct V_8 * V_20 ;
struct V_247 * V_176 ;
T_2 V_17 , V_14 ;
if ( V_487 != sizeof( * V_259 ) )
return - V_490 ;
if ( ! V_10 -> V_249 )
return - V_26 ;
V_17 = F_240 ( V_259 -> V_17 ) ;
V_14 = F_240 ( V_259 -> V_14 ) ;
F_21 ( L_54 , V_17 , V_14 , V_259 -> V_261 ) ;
if ( V_259 -> V_261 == V_431 ) {
F_249 ( V_10 , V_411 , V_175 , V_485 ,
V_259 -> V_261 ) ;
return 0 ;
}
V_176 = F_266 ( V_259 -> V_261 ) ;
if ( ! V_176 )
goto error;
if ( V_176 -> V_525 != V_526 || ! F_74 ( V_255 , & V_176 -> V_89 ) ) {
F_177 ( V_176 ) ;
goto error;
}
V_20 = F_249 ( V_10 , V_411 , V_175 , V_485 ,
V_259 -> V_261 ) ;
if ( V_20 ) {
struct V_126 * V_127 = V_10 -> V_2 -> V_126 ;
struct V_1 * V_187 ;
V_187 = F_267 ( V_176 , V_527 ,
& V_10 -> V_2 -> V_315 ) ;
if ( ! V_187 ) {
F_177 ( V_176 ) ;
F_256 ( V_10 , V_411 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
return 0 ;
}
F_21 ( L_55 , V_127 , V_20 , V_187 ) ;
V_127 -> V_128 = V_20 ;
V_20 -> V_187 = V_187 ;
V_20 -> V_79 = V_454 ;
V_10 -> V_147 = V_176 -> V_528 ;
}
F_177 ( V_176 ) ;
return 0 ;
error:
V_141 . V_13 = 0 ;
V_141 . V_14 = F_16 ( V_14 ) ;
V_141 . V_142 = F_81 ( V_529 ) ;
V_141 . V_152 = F_81 ( V_153 ) ;
F_79 ( V_10 , V_411 -> V_16 , V_485 ,
sizeof( V_141 ) , & V_141 ) ;
return 0 ;
}
static void F_268 ( struct V_8 * V_20 , T_3 V_530 )
{
struct V_531 V_259 ;
T_3 V_16 ;
F_21 ( L_56 , V_20 , V_530 ) ;
V_16 = F_88 ( V_20 -> V_10 ) ;
V_20 -> V_16 = V_16 ;
V_259 . V_532 = F_16 ( V_20 -> V_14 ) ;
V_259 . V_530 = V_530 ;
F_79 ( V_20 -> V_10 , V_16 , V_533 , sizeof( V_259 ) ,
& V_259 ) ;
F_82 ( V_20 , V_534 ) ;
}
static void F_269 ( struct V_8 * V_20 , T_2 V_142 )
{
struct V_535 V_141 ;
F_21 ( L_57 , V_20 , V_142 ) ;
V_141 . V_532 = F_16 ( V_20 -> V_13 ) ;
V_141 . V_142 = F_16 ( V_142 ) ;
F_79 ( V_20 -> V_10 , V_20 -> V_16 , V_536 ,
sizeof( V_141 ) , & V_141 ) ;
}
static void F_270 ( struct V_8 * V_20 , T_2 V_142 )
{
struct V_537 V_538 ;
F_21 ( L_57 , V_20 , V_142 ) ;
V_20 -> V_16 = F_88 ( V_20 -> V_10 ) ;
V_538 . V_532 = F_16 ( V_20 -> V_14 ) ;
V_538 . V_142 = F_16 ( V_142 ) ;
F_79 ( V_20 -> V_10 , V_20 -> V_16 , V_539 ,
sizeof( V_538 ) , & V_538 ) ;
F_82 ( V_20 , V_534 ) ;
}
static void F_271 ( struct V_9 * V_10 , T_2 V_532 )
{
struct V_537 V_538 ;
F_21 ( L_58 , V_10 , V_532 ) ;
V_538 . V_532 = F_16 ( V_532 ) ;
V_538 . V_142 = F_81 ( V_540 ) ;
F_79 ( V_10 , F_88 ( V_10 ) , V_539 ,
sizeof( V_538 ) , & V_538 ) ;
}
static void F_272 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_532 )
{
struct V_541 V_141 ;
F_21 ( L_59 , V_532 ) ;
V_141 . V_532 = F_16 ( V_532 ) ;
F_79 ( V_10 , V_16 , V_542 , sizeof( V_141 ) , & V_141 ) ;
}
static void F_273 ( struct V_8 * V_20 )
{
V_20 -> V_129 = NULL ;
V_20 -> V_187 = NULL ;
}
static void F_274 ( struct V_8 * V_20 )
{
if ( V_20 -> V_31 != V_62 ) {
F_83 ( V_20 , V_305 ) ;
return;
}
switch ( V_20 -> V_274 ) {
case V_279 :
F_127 ( V_20 ) ;
F_269 ( V_20 , V_543 ) ;
break;
case V_276 :
if ( V_20 -> V_184 == V_544 ||
V_20 -> V_184 == V_545 ) {
F_127 ( V_20 ) ;
}
F_270 ( V_20 , V_540 ) ;
break;
}
}
static void F_275 ( struct V_8 * V_20 ,
struct V_130 * V_183 )
{
struct V_457 V_141 ;
V_20 -> V_129 = V_183 ;
V_20 -> V_187 -> V_338 = V_20 -> V_10 ;
F_255 ( V_20 , & V_141 , V_20 -> V_16 , 0 ) ;
if ( F_74 ( V_510 , & V_20 -> V_77 ) ) {
int V_21 ;
F_254 ( V_20 ) ;
V_21 = F_232 ( V_20 ) ;
if ( V_21 < 0 )
F_83 ( V_20 , - V_21 ) ;
else
F_129 ( V_20 ) ;
}
}
static void F_276 ( struct V_8 * V_20 ,
struct V_130 * V_183 )
{
V_20 -> V_187 = V_183 -> V_10 ;
V_20 -> V_187 -> V_338 = V_20 -> V_10 ;
F_21 ( L_60 , V_20 -> V_184 ) ;
switch ( V_20 -> V_184 ) {
case V_544 :
V_20 -> V_184 = V_546 ;
break;
case V_545 :
if ( F_74 ( V_244 , & V_20 -> V_238 ) ) {
V_20 -> V_184 = V_547 ;
} else if ( V_20 -> V_274 == V_276 ) {
V_20 -> V_184 = V_548 ;
F_270 ( V_20 , V_549 ) ;
} else if ( V_20 -> V_274 == V_279 ) {
V_20 -> V_184 = V_550 ;
F_269 ( V_20 , V_551 ) ;
}
break;
default:
F_273 ( V_20 ) ;
V_20 -> V_184 = V_185 ;
}
}
void F_277 ( struct V_8 * V_20 , struct V_130 * V_183 ,
T_3 V_152 )
{
F_21 ( L_61 , V_20 , V_183 , V_152 ) ;
if ( V_152 ) {
F_274 ( V_20 ) ;
F_273 ( V_20 ) ;
return;
}
if ( V_20 -> V_31 != V_62 ) {
if ( V_20 -> V_430 != V_431 )
F_275 ( V_20 , V_183 ) ;
} else {
F_276 ( V_20 , V_183 ) ;
}
}
void F_278 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_430 == V_431 ) {
if ( V_20 -> V_256 != V_257 )
return;
V_20 -> V_274 = V_276 ;
V_20 -> V_184 = V_186 ;
} else {
V_20 -> V_274 = V_276 ;
V_20 -> V_184 = V_546 ;
V_20 -> V_432 = 0 ;
F_126 ( V_20 ) ;
F_268 ( V_20 , 0 ) ;
}
}
static void F_279 ( struct V_8 * V_20 , int V_142 ,
T_3 V_430 , T_3 V_552 )
{
F_21 ( L_62 , V_20 , F_22 ( V_20 -> V_31 ) ,
V_430 , V_552 ) ;
V_20 -> V_79 = V_454 ;
if ( V_20 -> V_31 == V_65 ) {
if ( V_142 == V_310 ) {
V_20 -> V_430 = V_430 ;
F_125 ( V_20 , V_552 ) ;
} else {
F_124 ( V_20 ) ;
}
return;
}
if ( F_119 ( V_20 ) ) {
struct V_150 V_141 ;
char V_306 [ 128 ] ;
V_141 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_141 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( V_142 == V_310 ) {
V_141 . V_142 = F_81 ( V_310 ) ;
V_141 . V_152 = F_81 ( V_153 ) ;
} else {
V_141 . V_142 = F_81 ( V_495 ) ;
V_141 . V_152 = F_81 ( V_153 ) ;
}
F_79 ( V_20 -> V_10 , V_20 -> V_16 , V_485 ,
sizeof( V_141 ) , & V_141 ) ;
if ( V_142 == V_310 ) {
F_20 ( V_20 , V_63 ) ;
F_55 ( V_312 , & V_20 -> V_77 ) ;
F_79 ( V_20 -> V_10 , F_88 ( V_20 -> V_10 ) ,
V_313 ,
F_140 ( V_20 , V_306 ) , V_306 ) ;
V_20 -> V_314 ++ ;
}
}
}
static void F_280 ( struct V_8 * V_20 , T_3 V_430 ,
T_3 V_552 )
{
F_126 ( V_20 ) ;
V_20 -> V_432 = V_430 ;
V_20 -> V_184 = V_553 ;
F_268 ( V_20 , V_552 ) ;
}
static void F_281 ( struct V_8 * V_20 , int V_142 )
{
struct V_130 * V_183 = NULL ;
if ( V_183 ) {
if ( V_183 -> V_31 == V_62 ) {
V_20 -> V_187 = V_183 -> V_10 ;
V_20 -> V_187 -> V_338 = V_20 -> V_10 ;
V_20 -> V_184 = V_550 ;
F_269 ( V_20 , V_551 ) ;
F_277 ( V_20 , V_183 , V_551 ) ;
} else {
V_20 -> V_184 = V_545 ;
}
} else {
F_269 ( V_20 , V_554 ) ;
}
}
static void F_282 ( struct V_8 * V_20 , int V_142 )
{
if ( V_20 -> V_274 == V_279 ) {
T_3 V_555 ;
if ( V_142 == - V_26 )
V_555 = V_556 ;
else
V_555 = V_554 ;
F_269 ( V_20 , V_555 ) ;
}
V_20 -> V_274 = V_275 ;
V_20 -> V_184 = V_185 ;
F_185 ( V_20 ) ;
}
void F_283 ( struct V_8 * V_20 , int V_142 )
{
T_3 V_430 = V_20 -> V_430 ;
T_3 V_552 = V_20 -> V_552 ;
F_21 ( L_63 ,
V_20 , V_142 , V_430 , V_552 ) ;
if ( V_20 -> V_31 == V_146 || V_20 -> V_31 == V_557 ) {
F_47 ( V_20 ) ;
return;
}
if ( V_20 -> V_31 != V_62 ) {
F_279 ( V_20 , V_142 , V_430 , V_552 ) ;
} else if ( V_142 != V_551 ) {
F_282 ( V_20 , V_142 ) ;
} else {
switch ( V_20 -> V_274 ) {
case V_276 :
F_280 ( V_20 , V_430 ,
V_552 ) ;
break;
case V_279 :
F_281 ( V_20 , V_142 ) ;
break;
default:
F_282 ( V_20 , V_142 ) ;
break;
}
}
}
static inline int F_284 ( struct V_9 * V_10 ,
struct V_410 * V_411 ,
T_2 V_487 , void * V_175 )
{
struct V_531 * V_259 = V_175 ;
struct V_535 V_141 ;
struct V_8 * V_20 ;
T_2 V_532 = 0 ;
T_2 V_142 = V_554 ;
if ( V_487 != sizeof( * V_259 ) )
return - V_490 ;
V_532 = F_240 ( V_259 -> V_532 ) ;
F_21 ( L_64 , V_532 , V_259 -> V_530 ) ;
if ( ! V_10 -> V_249 )
return - V_26 ;
V_20 = F_9 ( V_10 , V_532 ) ;
if ( ! V_20 ) {
V_141 . V_532 = F_16 ( V_532 ) ;
V_141 . V_142 = F_81 ( V_554 ) ;
F_79 ( V_10 , V_411 -> V_16 , V_536 ,
sizeof( V_141 ) , & V_141 ) ;
return 0 ;
}
V_20 -> V_16 = V_411 -> V_16 ;
if ( V_20 -> V_14 < V_30 ||
V_20 -> V_256 == V_558 ||
( V_20 -> V_132 != V_135 &&
V_20 -> V_132 != V_139 ) ) {
V_142 = V_554 ;
goto V_559;
}
if ( V_20 -> V_430 == V_259 -> V_530 ) {
V_142 = V_560 ;
goto V_559;
}
if ( V_259 -> V_530 != V_431 ) {
struct V_247 * V_176 ;
V_176 = F_266 ( V_259 -> V_530 ) ;
if ( ! V_176 || V_176 -> V_525 != V_526 ||
! F_74 ( V_255 , & V_176 -> V_89 ) ) {
if ( V_176 )
F_177 ( V_176 ) ;
V_142 = V_556 ;
goto V_559;
}
F_177 ( V_176 ) ;
}
if ( ( F_94 ( V_20 ) ||
V_20 -> V_274 != V_275 ) &&
F_13 ( & V_10 -> V_2 -> V_18 , & V_10 -> V_2 -> V_315 ) > 0 ) {
V_142 = V_561 ;
goto V_559;
}
V_20 -> V_274 = V_279 ;
F_126 ( V_20 ) ;
V_20 -> V_432 = V_259 -> V_530 ;
V_532 = V_20 -> V_13 ;
if ( V_259 -> V_530 == V_431 ) {
if ( F_74 ( V_244 , & V_20 -> V_238 ) ) {
V_20 -> V_184 = V_547 ;
V_142 = V_562 ;
} else {
V_20 -> V_184 = V_550 ;
V_142 = V_551 ;
}
} else {
V_20 -> V_184 = V_186 ;
V_142 = V_562 ;
}
V_559:
F_269 ( V_20 , V_142 ) ;
F_47 ( V_20 ) ;
return 0 ;
}
static void F_285 ( struct V_9 * V_10 , T_2 V_532 , T_2 V_142 )
{
struct V_8 * V_20 ;
struct V_130 * V_183 = NULL ;
V_20 = F_5 ( V_10 , V_532 ) ;
if ( ! V_20 ) {
F_271 ( V_10 , V_532 ) ;
return;
}
F_71 ( V_20 ) ;
if ( V_142 == V_562 )
F_82 ( V_20 , V_563 ) ;
switch ( V_20 -> V_184 ) {
case V_544 :
V_20 -> V_184 = V_545 ;
break;
case V_546 :
if ( V_142 == V_562 ) {
break;
} else if ( F_74 ( V_244 ,
& V_20 -> V_238 ) ) {
V_20 -> V_184 = V_547 ;
} else {
V_20 -> V_184 = V_548 ;
F_270 ( V_20 , V_549 ) ;
}
break;
case V_553 :
if ( V_142 == V_551 ) {
V_20 -> V_184 = V_545 ;
} else {
V_20 -> V_184 = V_544 ;
}
if ( ! V_183 ) {
F_270 ( V_20 , V_540 ) ;
break;
}
if ( V_183 -> V_31 != V_62 )
break;
V_20 -> V_187 = V_183 -> V_10 ;
V_20 -> V_187 -> V_338 = V_20 -> V_10 ;
if ( V_142 == V_551 ) {
F_270 ( V_20 , V_549 ) ;
} else {
V_20 -> V_184 = V_546 ;
}
F_277 ( V_20 , V_183 , V_551 ) ;
break;
default:
V_20 -> V_432 = V_20 -> V_430 ;
F_127 ( V_20 ) ;
F_270 ( V_20 , V_540 ) ;
}
F_47 ( V_20 ) ;
}
static void F_286 ( struct V_9 * V_10 , T_3 V_16 , T_2 V_532 ,
T_2 V_142 )
{
struct V_8 * V_20 ;
V_20 = F_11 ( V_10 , V_16 ) ;
if ( ! V_20 ) {
F_271 ( V_10 , V_532 ) ;
return;
}
F_71 ( V_20 ) ;
if ( V_20 -> V_274 == V_276 ) {
if ( V_142 == V_561 ) {
V_20 -> V_274 = V_279 ;
} else {
V_20 -> V_432 = V_20 -> V_430 ;
F_127 ( V_20 ) ;
}
}
F_270 ( V_20 , V_540 ) ;
F_47 ( V_20 ) ;
}
static int F_287 ( struct V_9 * V_10 ,
struct V_410 * V_411 ,
T_2 V_487 , void * V_175 )
{
struct V_535 * V_141 = V_175 ;
T_2 V_532 , V_142 ;
if ( V_487 != sizeof( * V_141 ) )
return - V_490 ;
V_532 = F_240 ( V_141 -> V_532 ) ;
V_142 = F_240 ( V_141 -> V_142 ) ;
F_21 ( L_65 , V_532 , V_142 ) ;
if ( V_142 == V_551 || V_142 == V_562 )
F_285 ( V_10 , V_532 , V_142 ) ;
else
F_286 ( V_10 , V_411 -> V_16 , V_532 , V_142 ) ;
return 0 ;
}
static int F_288 ( struct V_9 * V_10 ,
struct V_410 * V_411 ,
T_2 V_487 , void * V_175 )
{
struct V_537 * V_538 = V_175 ;
struct V_8 * V_20 ;
T_2 V_532 , V_142 ;
if ( V_487 != sizeof( * V_538 ) )
return - V_490 ;
V_532 = F_240 ( V_538 -> V_532 ) ;
V_142 = F_240 ( V_538 -> V_142 ) ;
F_21 ( L_65 , V_532 , V_142 ) ;
V_20 = F_9 ( V_10 , V_532 ) ;
if ( ! V_20 ) {
F_272 ( V_10 , V_411 -> V_16 , V_532 ) ;
return 0 ;
}
if ( V_20 -> V_184 == V_550 ) {
if ( V_142 == V_549 ) {
V_20 -> V_430 = V_20 -> V_432 ;
if ( V_20 -> V_430 == V_431 )
F_273 ( V_20 ) ;
} else {
V_20 -> V_432 = V_20 -> V_430 ;
}
F_127 ( V_20 ) ;
}
F_272 ( V_10 , V_411 -> V_16 , V_532 ) ;
F_47 ( V_20 ) ;
return 0 ;
}
static inline int F_289 ( struct V_9 * V_10 ,
struct V_410 * V_411 ,
T_2 V_487 , void * V_175 )
{
struct V_541 * V_141 = V_175 ;
struct V_8 * V_20 ;
T_2 V_532 ;
if ( V_487 != sizeof( * V_141 ) )
return - V_490 ;
V_532 = F_240 ( V_141 -> V_532 ) ;
F_21 ( L_59 , V_532 ) ;
V_20 = F_5 ( V_10 , V_532 ) ;
if ( ! V_20 )
return 0 ;
F_71 ( V_20 ) ;
if ( V_20 -> V_184 == V_548 ) {
V_20 -> V_430 = V_20 -> V_432 ;
if ( V_20 -> V_430 == V_431 && V_20 -> V_129 )
F_273 ( V_20 ) ;
F_127 ( V_20 ) ;
}
F_47 ( V_20 ) ;
return 0 ;
}
static inline int F_290 ( T_2 V_564 , T_2 V_565 , T_2 V_566 ,
T_2 V_567 )
{
T_2 V_568 ;
if ( V_564 > V_565 || V_564 < 6 || V_565 > 3200 )
return - V_26 ;
if ( V_567 < 10 || V_567 > 3200 )
return - V_26 ;
if ( V_565 >= V_567 * 8 )
return - V_26 ;
V_568 = ( V_567 * 8 / V_565 ) - 1 ;
if ( V_566 > 499 || V_566 > V_568 )
return - V_26 ;
return 0 ;
}
static inline int F_291 ( struct V_9 * V_10 ,
struct V_410 * V_411 ,
T_2 V_487 , T_3 * V_175 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct F_291 * V_259 ;
struct V_569 V_141 ;
T_2 V_564 , V_565 , V_566 , V_567 ;
int V_21 ;
if ( ! ( V_2 -> V_570 & V_571 ) )
return - V_26 ;
if ( V_487 != sizeof( struct F_291 ) )
return - V_490 ;
V_259 = (struct F_291 * ) V_175 ;
V_564 = F_67 ( V_259 -> V_564 ) ;
V_565 = F_67 ( V_259 -> V_565 ) ;
V_566 = F_67 ( V_259 -> V_566 ) ;
V_567 = F_67 ( V_259 -> V_567 ) ;
F_21 ( L_66 ,
V_564 , V_565 , V_566 , V_567 ) ;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_21 = F_290 ( V_564 , V_565 , V_566 , V_567 ) ;
if ( V_21 )
V_141 . V_142 = F_81 ( V_572 ) ;
else
V_141 . V_142 = F_81 ( V_573 ) ;
F_79 ( V_10 , V_411 -> V_16 , V_574 ,
sizeof( V_141 ) , & V_141 ) ;
if ( ! V_21 )
F_292 ( V_2 , V_564 , V_565 , V_566 , V_567 ) ;
return 0 ;
}
static int F_293 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
struct V_140 * V_141 = (struct V_140 * ) V_175 ;
T_2 V_13 , V_147 , V_96 , V_148 , V_142 ;
struct V_8 * V_20 ;
int V_21 ;
if ( V_487 < sizeof( * V_141 ) )
return - V_490 ;
V_13 = F_67 ( V_141 -> V_13 ) ;
V_147 = F_67 ( V_141 -> V_147 ) ;
V_96 = F_67 ( V_141 -> V_96 ) ;
V_148 = F_67 ( V_141 -> V_148 ) ;
V_142 = F_67 ( V_141 -> V_142 ) ;
if ( V_142 == V_310 && ( V_147 < 23 || V_96 < 23 ) )
return - V_490 ;
F_21 ( L_67 ,
V_13 , V_147 , V_96 , V_148 , V_142 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_10 ( V_10 , V_411 -> V_16 ) ;
if ( ! V_20 ) {
V_21 = - V_502 ;
goto V_503;
}
V_21 = 0 ;
F_7 ( V_20 ) ;
switch ( V_142 ) {
case V_310 :
V_20 -> V_16 = 0 ;
V_20 -> V_13 = V_13 ;
V_20 -> V_105 = V_147 ;
V_20 -> V_386 = V_96 ;
V_20 -> V_93 = V_148 ;
F_129 ( V_20 ) ;
break;
default:
F_70 ( V_20 , V_64 ) ;
break;
}
F_47 ( V_20 ) ;
V_503:
F_8 ( & V_10 -> V_15 ) ;
return V_21 ;
}
static inline int F_294 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
int V_21 = 0 ;
switch ( V_411 -> V_173 ) {
case V_507 :
F_247 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_260 :
V_21 = F_251 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_154 :
case V_485 :
F_253 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_313 :
V_21 = F_258 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_504 :
F_259 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_302 :
V_21 = F_261 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_515 :
F_262 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_575 :
F_79 ( V_10 , V_411 -> V_16 , V_576 , V_487 , V_175 ) ;
break;
case V_576 :
break;
case V_294 :
V_21 = F_263 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_519 :
F_264 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_263 :
V_21 = F_265 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_533 :
V_21 = F_284 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_536 :
F_287 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_539 :
V_21 = F_288 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_542 :
F_289 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
default:
F_295 ( L_68 , V_411 -> V_173 ) ;
V_21 = - V_26 ;
break;
}
return V_21 ;
}
static int F_296 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
struct V_283 * V_259 = (struct V_283 * ) V_175 ;
struct V_140 V_141 ;
struct V_8 * V_20 , * V_322 ;
T_2 V_13 , V_14 , V_148 , V_147 , V_96 ;
T_4 V_17 ;
T_3 V_142 ;
if ( V_487 != sizeof( * V_259 ) )
return - V_490 ;
V_14 = F_67 ( V_259 -> V_14 ) ;
V_147 = F_67 ( V_259 -> V_147 ) ;
V_96 = F_67 ( V_259 -> V_96 ) ;
V_17 = V_259 -> V_17 ;
V_13 = 0 ;
V_148 = 0 ;
if ( V_147 < 23 || V_96 < 23 )
return - V_490 ;
F_21 ( L_69 , F_67 ( V_17 ) ,
V_14 , V_147 , V_96 ) ;
V_322 = F_170 ( V_155 , V_17 , & V_10 -> V_2 -> V_18 ,
& V_10 -> V_2 -> V_315 , V_3 ) ;
if ( ! V_322 ) {
V_142 = V_145 ;
V_20 = NULL ;
goto V_494;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_322 ) ;
if ( ! F_297 ( V_10 -> V_2 , V_322 -> V_66 ) ) {
V_142 = V_577 ;
V_20 = NULL ;
goto V_578;
}
if ( F_2 ( V_10 , V_14 ) ) {
V_142 = V_495 ;
V_20 = NULL ;
goto V_578;
}
V_20 = V_322 -> V_32 -> V_324 ( V_322 ) ;
if ( ! V_20 ) {
V_142 = V_495 ;
goto V_578;
}
F_63 ( V_20 ) ;
F_145 ( & V_20 -> V_18 , & V_10 -> V_2 -> V_18 ) ;
F_145 ( & V_20 -> V_315 , & V_10 -> V_2 -> V_315 ) ;
V_20 -> V_326 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_326 ) ;
V_20 -> V_323 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_323 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_14 ;
V_20 -> V_105 = V_147 ;
V_20 -> V_386 = V_96 ;
V_20 -> V_93 = F_67 ( V_259 -> V_148 ) ;
F_66 ( V_10 , V_20 ) ;
V_13 = V_20 -> V_14 ;
V_148 = V_20 -> V_94 ;
F_82 ( V_20 , V_20 -> V_32 -> V_156 ( V_20 ) ) ;
V_20 -> V_16 = V_411 -> V_16 ;
if ( F_74 ( V_143 , & V_20 -> V_89 ) ) {
F_20 ( V_20 , V_157 ) ;
V_142 = V_307 ;
V_20 -> V_32 -> V_309 ( V_20 ) ;
} else {
F_129 ( V_20 ) ;
V_142 = V_310 ;
}
V_578:
F_47 ( V_322 ) ;
F_8 ( & V_10 -> V_15 ) ;
if ( V_142 == V_307 )
return 0 ;
V_494:
if ( V_20 ) {
V_141 . V_147 = F_16 ( V_20 -> V_97 ) ;
V_141 . V_96 = F_16 ( V_20 -> V_96 ) ;
} else {
V_141 . V_147 = 0 ;
V_141 . V_96 = 0 ;
}
V_141 . V_13 = F_16 ( V_13 ) ;
V_141 . V_148 = F_16 ( V_148 ) ;
V_141 . V_142 = F_16 ( V_142 ) ;
F_79 ( V_10 , V_411 -> V_16 , V_149 , sizeof( V_141 ) , & V_141 ) ;
return 0 ;
}
static inline int F_298 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
struct F_298 * V_579 ;
struct V_8 * V_20 ;
T_2 V_11 , V_148 ;
if ( V_487 != sizeof( * V_579 ) )
return - V_490 ;
V_579 = (struct F_298 * ) V_175 ;
V_11 = F_67 ( V_579 -> V_11 ) ;
V_148 = F_67 ( V_579 -> V_148 ) ;
F_21 ( L_70 , V_11 , V_148 ) ;
V_20 = F_9 ( V_10 , V_11 ) ;
if ( ! V_20 )
return - V_502 ;
V_20 -> V_93 += V_148 ;
while ( V_20 -> V_93 && ! F_182 ( & V_20 -> V_99 ) ) {
F_95 ( V_20 , F_183 ( & V_20 -> V_99 ) ) ;
V_20 -> V_93 -- ;
}
if ( V_20 -> V_93 )
V_20 -> V_32 -> V_580 ( V_20 ) ;
F_47 ( V_20 ) ;
return 0 ;
}
static inline int F_299 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
struct V_488 * V_489 = (struct V_488 * ) V_175 ;
struct V_8 * V_20 ;
if ( V_487 < sizeof( * V_489 ) )
return - V_490 ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_10 ( V_10 , V_411 -> V_16 ) ;
if ( ! V_20 )
goto V_24;
F_7 ( V_20 ) ;
F_70 ( V_20 , V_64 ) ;
F_47 ( V_20 ) ;
V_24:
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_300 ( struct V_9 * V_10 ,
struct V_410 * V_411 , T_2 V_487 ,
T_3 * V_175 )
{
int V_21 = 0 ;
if ( ! V_581 ) {
switch ( V_411 -> V_173 ) {
case V_285 :
case V_149 :
case V_582 :
case V_302 :
case V_515 :
return - V_26 ;
}
}
switch ( V_411 -> V_173 ) {
case V_507 :
F_299 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_583 :
V_21 = F_291 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_574 :
break;
case V_149 :
F_293 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_285 :
V_21 = F_296 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_582 :
V_21 = F_298 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_302 :
V_21 = F_261 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
case V_515 :
F_262 ( V_10 , V_411 , V_487 , V_175 ) ;
break;
default:
F_295 ( L_71 , V_411 -> V_173 ) ;
V_21 = - V_26 ;
break;
}
return V_21 ;
}
static inline void F_301 ( struct V_9 * V_10 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_410 * V_411 ;
T_2 V_174 ;
int V_21 ;
if ( V_2 -> type != V_3 )
goto V_584;
if ( V_42 -> V_174 < V_412 )
goto V_584;
V_411 = ( void * ) V_42 -> V_175 ;
F_101 ( V_42 , V_412 ) ;
V_174 = F_240 ( V_411 -> V_174 ) ;
F_21 ( L_72 , V_411 -> V_173 , V_174 , V_411 -> V_16 ) ;
if ( V_174 != V_42 -> V_174 || ! V_411 -> V_16 ) {
F_21 ( L_73 ) ;
goto V_584;
}
V_21 = F_300 ( V_10 , V_411 , V_174 , V_42 -> V_175 ) ;
if ( V_21 ) {
struct V_488 V_489 ;
F_295 ( L_74 , V_21 ) ;
V_489 . V_61 = F_81 ( V_491 ) ;
F_79 ( V_10 , V_411 -> V_16 , V_507 ,
sizeof( V_489 ) , & V_489 ) ;
}
V_584:
F_96 ( V_42 ) ;
}
static inline void F_302 ( struct V_9 * V_10 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 * V_175 = V_42 -> V_175 ;
int V_174 = V_42 -> V_174 ;
struct V_410 V_411 ;
int V_21 ;
F_225 ( V_10 , V_42 ) ;
if ( V_2 -> type != V_158 )
goto V_584;
while ( V_174 >= V_412 ) {
T_2 V_487 ;
memcpy ( & V_411 , V_175 , V_412 ) ;
V_175 += V_412 ;
V_174 -= V_412 ;
V_487 = F_240 ( V_411 . V_174 ) ;
F_21 ( L_72 , V_411 . V_173 , V_487 ,
V_411 . V_16 ) ;
if ( V_487 > V_174 || ! V_411 . V_16 ) {
F_21 ( L_73 ) ;
break;
}
V_21 = F_294 ( V_10 , & V_411 , V_487 , V_175 ) ;
if ( V_21 ) {
struct V_488 V_489 ;
F_295 ( L_74 , V_21 ) ;
V_489 . V_61 = F_81 ( V_491 ) ;
F_79 ( V_10 , V_411 . V_16 , V_507 ,
sizeof( V_489 ) , & V_489 ) ;
}
V_175 += V_487 ;
V_174 -= V_487 ;
}
V_584:
F_96 ( V_42 ) ;
}
static int F_303 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
T_2 V_585 , V_586 ;
int V_587 ;
if ( F_74 ( V_225 , & V_20 -> V_89 ) )
V_587 = V_230 ;
else
V_587 = V_231 ;
if ( V_20 -> V_79 == V_80 ) {
F_304 ( V_42 , V_42 -> V_174 - V_235 ) ;
V_586 = F_102 ( V_42 -> V_175 + V_42 -> V_174 ) ;
V_585 = F_113 ( 0 , V_42 -> V_175 - V_587 , V_42 -> V_174 + V_587 ) ;
if ( V_585 != V_586 )
return - V_588 ;
}
return 0 ;
}
static void F_305 ( struct V_8 * V_20 )
{
struct V_191 V_43 ;
F_21 ( L_3 , V_20 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_199 = 1 ;
V_43 . V_195 = 1 ;
V_43 . V_192 = V_20 -> V_245 ;
F_55 ( V_237 , & V_20 -> V_238 ) ;
if ( F_74 ( V_244 , & V_20 -> V_238 ) ) {
V_43 . V_203 = V_241 ;
F_114 ( V_20 , & V_43 ) ;
}
if ( F_115 ( V_273 , & V_20 -> V_238 ) &&
V_20 -> V_364 > 0 )
F_25 ( V_20 ) ;
F_185 ( V_20 ) ;
if ( ! F_74 ( V_244 , & V_20 -> V_238 ) &&
F_74 ( V_237 , & V_20 -> V_238 ) ) {
V_43 . V_203 = V_239 ;
F_114 ( V_20 , & V_43 ) ;
}
}
static void F_306 ( struct V_38 * V_42 , struct V_38 * V_589 ,
struct V_38 * * V_590 )
{
if ( ! F_307 ( V_42 ) )
F_201 ( V_42 ) -> V_375 = V_589 ;
V_589 -> V_333 = NULL ;
( * V_590 ) -> V_333 = V_589 ;
* V_590 = V_589 ;
V_42 -> V_174 += V_589 -> V_174 ;
V_42 -> V_379 += V_589 -> V_174 ;
V_42 -> V_591 += V_589 -> V_591 ;
}
static int F_308 ( struct V_8 * V_20 , struct V_38 * V_42 ,
struct V_191 * V_43 )
{
int V_21 = - V_26 ;
switch ( V_43 -> V_206 ) {
case V_387 :
if ( V_20 -> V_90 )
break;
V_21 = V_20 -> V_32 -> V_408 ( V_20 , V_42 ) ;
break;
case V_388 :
if ( V_20 -> V_90 )
break;
V_20 -> V_92 = F_102 ( V_42 -> V_175 ) ;
F_101 ( V_42 , V_382 ) ;
if ( V_20 -> V_92 > V_20 -> V_97 ) {
V_21 = - V_391 ;
break;
}
if ( V_42 -> V_174 >= V_20 -> V_92 )
break;
V_20 -> V_90 = V_42 ;
V_20 -> V_91 = V_42 ;
V_42 = NULL ;
V_21 = 0 ;
break;
case V_390 :
if ( ! V_20 -> V_90 )
break;
F_306 ( V_20 -> V_90 , V_42 ,
& V_20 -> V_91 ) ;
V_42 = NULL ;
if ( V_20 -> V_90 -> V_174 >= V_20 -> V_92 )
break;
V_21 = 0 ;
break;
case V_389 :
if ( ! V_20 -> V_90 )
break;
F_306 ( V_20 -> V_90 , V_42 ,
& V_20 -> V_91 ) ;
V_42 = NULL ;
if ( V_20 -> V_90 -> V_174 != V_20 -> V_92 )
break;
V_21 = V_20 -> V_32 -> V_408 ( V_20 , V_20 -> V_90 ) ;
if ( ! V_21 ) {
V_20 -> V_90 = NULL ;
V_20 -> V_91 = NULL ;
V_20 -> V_92 = 0 ;
}
break;
}
if ( V_21 ) {
F_96 ( V_42 ) ;
F_96 ( V_20 -> V_90 ) ;
V_20 -> V_90 = NULL ;
V_20 -> V_91 = NULL ;
V_20 -> V_92 = 0 ;
}
return V_21 ;
}
static int F_309 ( struct V_8 * V_20 )
{
return 0 ;
}
void F_310 ( struct V_8 * V_20 , int V_592 )
{
T_3 V_398 ;
if ( V_20 -> V_132 != V_135 )
return;
V_398 = V_592 ? V_399 : V_401 ;
F_128 ( V_20 , NULL , NULL , V_398 ) ;
}
static int F_311 ( struct V_8 * V_20 )
{
int V_21 = 0 ;
F_21 ( L_3 , V_20 ) ;
while ( ! F_74 ( V_244 , & V_20 -> V_238 ) ) {
struct V_38 * V_42 ;
F_21 ( L_75 ,
V_20 -> V_245 , F_189 ( & V_20 -> V_136 ) ) ;
V_42 = F_31 ( & V_20 -> V_136 , V_20 -> V_245 ) ;
if ( ! V_42 )
break;
F_218 ( V_42 , & V_20 -> V_136 ) ;
V_20 -> V_245 = F_184 ( V_20 , V_20 -> V_245 ) ;
V_21 = F_308 ( V_20 , V_42 , & F_33 ( V_42 ) -> V_43 ) ;
if ( V_21 )
break;
}
if ( F_182 ( & V_20 -> V_136 ) ) {
V_20 -> V_271 = V_368 ;
F_196 ( V_20 ) ;
}
return V_21 ;
}
static void F_312 ( struct V_8 * V_20 ,
struct V_191 * V_43 )
{
struct V_38 * V_42 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( V_43 -> V_192 == V_20 -> V_358 ) {
F_21 ( L_76 , V_43 -> V_192 ) ;
F_83 ( V_20 , V_305 ) ;
return;
}
V_42 = F_31 ( & V_20 -> V_99 , V_43 -> V_192 ) ;
if ( V_42 == NULL ) {
F_21 ( L_77 ,
V_43 -> V_192 ) ;
return;
}
if ( V_20 -> V_81 != 0 && F_33 ( V_42 ) -> V_43 . V_265 >= V_20 -> V_81 ) {
F_21 ( L_23 , V_20 -> V_81 ) ;
F_83 ( V_20 , V_305 ) ;
return;
}
F_116 ( V_273 , & V_20 -> V_238 ) ;
if ( V_43 -> V_200 ) {
F_223 ( V_20 , V_43 ) ;
F_55 ( V_237 , & V_20 -> V_238 ) ;
F_193 ( V_20 , V_43 ) ;
F_185 ( V_20 ) ;
if ( V_20 -> V_269 == V_403 ) {
F_55 ( V_268 , & V_20 -> V_238 ) ;
V_20 -> V_593 = V_43 -> V_192 ;
}
} else {
F_224 ( V_20 , V_43 ) ;
if ( V_43 -> V_195 ) {
if ( V_20 -> V_593 != V_43 -> V_192 ||
! F_115 ( V_268 ,
& V_20 -> V_238 ) )
F_193 ( V_20 , V_43 ) ;
} else {
F_193 ( V_20 , V_43 ) ;
if ( V_20 -> V_269 == V_403 ) {
F_55 ( V_268 , & V_20 -> V_238 ) ;
V_20 -> V_593 = V_43 -> V_192 ;
}
}
}
}
static void F_313 ( struct V_8 * V_20 ,
struct V_191 * V_43 )
{
struct V_38 * V_42 ;
F_21 ( L_10 , V_20 , V_43 ) ;
if ( V_43 -> V_192 == V_20 -> V_358 ) {
F_21 ( L_76 , V_43 -> V_192 ) ;
F_83 ( V_20 , V_305 ) ;
return;
}
V_42 = F_31 ( & V_20 -> V_99 , V_43 -> V_192 ) ;
if ( V_20 -> V_81 && V_42 &&
F_33 ( V_42 ) -> V_43 . V_265 >= V_20 -> V_81 ) {
F_21 ( L_23 , V_20 -> V_81 ) ;
F_83 ( V_20 , V_305 ) ;
return;
}
F_116 ( V_273 , & V_20 -> V_238 ) ;
F_223 ( V_20 , V_43 ) ;
if ( V_43 -> V_195 ) {
if ( ! F_115 ( V_267 , & V_20 -> V_238 ) )
F_194 ( V_20 , V_43 ) ;
} else {
F_194 ( V_20 , V_43 ) ;
F_185 ( V_20 ) ;
if ( V_20 -> V_269 == V_403 )
F_55 ( V_267 , & V_20 -> V_238 ) ;
}
}
static T_3 F_314 ( struct V_8 * V_20 , T_2 V_44 )
{
F_21 ( L_78 , V_20 , V_44 ) ;
F_21 ( L_79 , V_20 -> V_243 ,
V_20 -> V_266 ) ;
if ( V_20 -> V_271 == V_400 ) {
if ( F_197 ( V_20 , V_44 , V_20 -> V_243 ) >=
V_20 -> V_83 ) {
if ( V_20 -> V_83 <= ( ( V_20 -> V_85 + 1 ) >> 1 ) ) {
F_21 ( L_80 ) ;
return V_594 ;
} else {
F_21 ( L_81 ) ;
return V_595 ;
}
}
if ( V_20 -> V_137 . V_40 == V_44 ) {
F_21 ( L_82 ) ;
return V_596 ;
}
if ( F_31 ( & V_20 -> V_136 , V_44 ) ) {
F_21 ( L_83 ) ;
return V_597 ;
}
if ( F_39 ( & V_20 -> V_137 , V_44 ) ) {
F_21 ( L_84 ) ;
return V_598 ;
}
}
if ( V_20 -> V_266 == V_44 ) {
if ( F_197 ( V_20 , V_44 , V_20 -> V_243 ) >=
V_20 -> V_83 ) {
F_21 ( L_85 ) ;
return V_595 ;
} else {
F_21 ( L_86 ) ;
return V_599 ;
}
}
if ( F_197 ( V_20 , V_44 , V_20 -> V_243 ) <
F_197 ( V_20 , V_20 -> V_266 , V_20 -> V_243 ) ) {
F_21 ( L_87 ) ;
return V_600 ;
}
if ( F_197 ( V_20 , V_44 , V_20 -> V_243 ) >= V_20 -> V_83 ) {
if ( V_20 -> V_83 <= ( ( V_20 -> V_85 + 1 ) >> 1 ) ) {
F_21 ( L_88 ) ;
return V_594 ;
} else {
F_21 ( L_85 ) ;
return V_595 ;
}
} else {
F_21 ( L_89 ) ;
return V_601 ;
}
}
static int F_315 ( struct V_8 * V_20 ,
struct V_191 * V_43 ,
struct V_38 * V_42 , T_3 V_398 )
{
int V_21 = 0 ;
bool V_602 = false ;
F_21 ( L_90 , V_20 , V_43 , V_42 ,
V_398 ) ;
switch ( V_398 ) {
case V_603 :
switch ( F_314 ( V_20 , V_43 -> V_44 ) ) {
case V_599 :
F_223 ( V_20 , V_43 ) ;
if ( F_74 ( V_244 , & V_20 -> V_238 ) ) {
F_21 ( L_91 ,
V_43 -> V_44 ) ;
break;
}
V_20 -> V_266 = F_184 ( V_20 ,
V_43 -> V_44 ) ;
V_20 -> V_245 = V_20 -> V_266 ;
V_602 = true ;
V_21 = F_308 ( V_20 , V_42 , V_43 ) ;
if ( V_21 )
break;
if ( V_43 -> V_195 ) {
if ( ! F_115 ( V_267 ,
& V_20 -> V_238 ) ) {
V_43 -> V_195 = 0 ;
F_194 ( V_20 , V_43 ) ;
F_185 ( V_20 ) ;
}
}
if ( ! F_74 ( V_244 , & V_20 -> V_238 ) )
F_196 ( V_20 ) ;
break;
case V_601 :
F_223 ( V_20 , V_43 ) ;
if ( F_74 ( V_244 , & V_20 -> V_238 ) ) {
F_21 ( L_92 ,
V_43 -> V_44 ) ;
break;
}
F_316 ( & V_20 -> V_136 , V_42 ) ;
V_602 = true ;
F_21 ( L_93 , V_42 ,
F_189 ( & V_20 -> V_136 ) ) ;
F_116 ( V_268 , & V_20 -> V_238 ) ;
F_42 ( & V_20 -> V_137 ) ;
F_214 ( V_20 , V_43 -> V_44 ) ;
V_20 -> V_271 = V_400 ;
break;
case V_600 :
F_223 ( V_20 , V_43 ) ;
break;
case V_594 :
break;
case V_595 :
default:
F_83 ( V_20 , V_305 ) ;
break;
}
break;
case V_604 :
F_223 ( V_20 , V_43 ) ;
if ( V_43 -> V_195 ) {
F_116 ( V_273 , & V_20 -> V_238 ) ;
if ( ! F_115 ( V_267 , & V_20 -> V_238 ) &&
! F_94 ( V_20 ) ) {
V_43 -> V_195 = 0 ;
F_194 ( V_20 , V_43 ) ;
}
F_185 ( V_20 ) ;
} else if ( V_43 -> V_200 ) {
F_305 ( V_20 ) ;
} else {
if ( F_115 ( V_273 ,
& V_20 -> V_238 ) &&
V_20 -> V_364 )
F_25 ( V_20 ) ;
F_185 ( V_20 ) ;
}
break;
case V_605 :
F_55 ( V_273 , & V_20 -> V_238 ) ;
F_223 ( V_20 , V_43 ) ;
if ( V_43 && V_43 -> V_200 ) {
F_55 ( V_237 , & V_20 -> V_238 ) ;
F_118 ( V_20 , 0 ) ;
}
F_30 ( V_20 ) ;
F_42 ( & V_20 -> V_138 ) ;
break;
case V_606 :
F_313 ( V_20 , V_43 ) ;
break;
case V_607 :
F_312 ( V_20 , V_43 ) ;
break;
default:
break;
}
if ( V_42 && ! V_602 ) {
F_21 ( L_94 , V_42 ) ;
F_96 ( V_42 ) ;
}
return V_21 ;
}
static int F_317 ( struct V_8 * V_20 ,
struct V_191 * V_43 ,
struct V_38 * V_42 , T_3 V_398 )
{
int V_21 = 0 ;
T_2 V_44 = V_43 -> V_44 ;
bool V_602 = false ;
F_21 ( L_90 , V_20 , V_43 , V_42 ,
V_398 ) ;
switch ( V_398 ) {
case V_603 :
switch ( F_314 ( V_20 , V_44 ) ) {
case V_599 :
F_223 ( V_20 , V_43 ) ;
F_316 ( & V_20 -> V_136 , V_42 ) ;
V_602 = true ;
F_21 ( L_93 , V_42 ,
F_189 ( & V_20 -> V_136 ) ) ;
V_20 -> V_266 = F_184 ( V_20 , V_44 ) ;
break;
case V_596 :
F_41 ( & V_20 -> V_137 ) ;
F_223 ( V_20 , V_43 ) ;
F_316 ( & V_20 -> V_136 , V_42 ) ;
V_602 = true ;
F_21 ( L_93 , V_42 ,
F_189 ( & V_20 -> V_136 ) ) ;
V_21 = F_311 ( V_20 ) ;
if ( V_21 )
break;
break;
case V_601 :
F_316 ( & V_20 -> V_136 , V_42 ) ;
V_602 = true ;
F_21 ( L_93 , V_42 ,
F_189 ( & V_20 -> V_136 ) ) ;
F_223 ( V_20 , V_43 ) ;
F_214 ( V_20 , V_43 -> V_44 ) ;
break;
case V_598 :
F_316 ( & V_20 -> V_136 , V_42 ) ;
V_602 = true ;
F_21 ( L_93 , V_42 ,
F_189 ( & V_20 -> V_136 ) ) ;
F_223 ( V_20 , V_43 ) ;
F_216 ( V_20 , V_43 -> V_44 ) ;
break;
case V_597 :
F_223 ( V_20 , V_43 ) ;
break;
case V_600 :
break;
case V_594 :
break;
case V_595 :
default:
F_83 ( V_20 , V_305 ) ;
break;
}
break;
case V_604 :
F_223 ( V_20 , V_43 ) ;
if ( V_43 -> V_195 ) {
F_116 ( V_273 , & V_20 -> V_238 ) ;
if ( ! F_115 ( V_267 ,
& V_20 -> V_238 ) ) {
V_43 -> V_195 = 0 ;
F_194 ( V_20 , V_43 ) ;
}
F_185 ( V_20 ) ;
} else if ( V_43 -> V_200 ) {
if ( F_115 ( V_273 ,
& V_20 -> V_238 ) &&
V_20 -> V_364 ) {
F_25 ( V_20 ) ;
}
F_55 ( V_237 , & V_20 -> V_238 ) ;
F_215 ( V_20 ) ;
} else {
if ( F_115 ( V_273 ,
& V_20 -> V_238 ) &&
V_20 -> V_364 )
F_25 ( V_20 ) ;
F_196 ( V_20 ) ;
}
break;
case V_605 :
F_55 ( V_273 , & V_20 -> V_238 ) ;
F_223 ( V_20 , V_43 ) ;
if ( V_43 -> V_200 ) {
F_215 ( V_20 ) ;
} else {
struct V_191 V_608 ;
memset ( & V_608 , 0 , sizeof( V_608 ) ) ;
V_608 . V_199 = 1 ;
V_608 . V_203 = V_239 ;
V_608 . V_192 = V_20 -> V_245 ;
F_114 ( V_20 , & V_608 ) ;
}
break;
case V_606 :
F_313 ( V_20 , V_43 ) ;
break;
case V_607 :
F_312 ( V_20 , V_43 ) ;
break;
}
if ( V_42 && ! V_602 ) {
F_21 ( L_94 , V_42 ) ;
F_96 ( V_42 ) ;
}
return V_21 ;
}
static int F_318 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_271 = V_368 ;
if ( V_20 -> V_187 )
V_20 -> V_10 -> V_147 = V_20 -> V_187 -> V_176 -> V_528 ;
else
V_20 -> V_10 -> V_147 = V_20 -> V_10 -> V_2 -> V_176 -> V_345 ;
return F_309 ( V_20 ) ;
}
static int F_319 ( struct V_8 * V_20 ,
struct V_191 * V_43 ,
struct V_38 * V_42 , T_3 V_398 )
{
int V_21 ;
F_21 ( L_90 , V_20 , V_43 , V_42 ,
V_398 ) ;
if ( ! V_43 -> V_200 )
return - V_490 ;
F_217 ( V_20 , V_43 -> V_192 ) ;
if ( ! F_182 ( & V_20 -> V_99 ) )
V_20 -> V_363 = F_221 ( & V_20 -> V_99 ) ;
else
V_20 -> V_363 = NULL ;
V_20 -> V_358 = V_43 -> V_192 ;
V_20 -> V_364 = 0 ;
V_21 = F_318 ( V_20 ) ;
if ( V_21 )
return V_21 ;
F_55 ( V_237 , & V_20 -> V_238 ) ;
F_305 ( V_20 ) ;
if ( V_398 == V_603 )
return - V_490 ;
return F_315 ( V_20 , V_43 , NULL , V_398 ) ;
}
static int F_320 ( struct V_8 * V_20 ,
struct V_191 * V_43 ,
struct V_38 * V_42 , T_3 V_398 )
{
int V_21 ;
if ( ! V_43 -> V_195 )
return - V_490 ;
F_116 ( V_273 , & V_20 -> V_238 ) ;
V_20 -> V_271 = V_368 ;
F_217 ( V_20 , V_43 -> V_192 ) ;
if ( ! F_182 ( & V_20 -> V_99 ) )
V_20 -> V_363 = F_221 ( & V_20 -> V_99 ) ;
else
V_20 -> V_363 = NULL ;
V_20 -> V_358 = V_43 -> V_192 ;
V_20 -> V_364 = 0 ;
if ( V_20 -> V_187 )
V_20 -> V_10 -> V_147 = V_20 -> V_187 -> V_176 -> V_528 ;
else
V_20 -> V_10 -> V_147 = V_20 -> V_10 -> V_2 -> V_176 -> V_345 ;
V_21 = F_309 ( V_20 ) ;
if ( ! V_21 )
V_21 = F_315 ( V_20 , V_43 , V_42 , V_398 ) ;
return V_21 ;
}
static bool F_321 ( struct V_8 * V_20 , T_2 V_192 )
{
T_2 V_609 ;
V_609 = F_197 ( V_20 , V_20 -> V_358 , V_20 -> V_397 ) ;
return F_197 ( V_20 , V_20 -> V_358 , V_192 ) <= V_609 ;
}
static int F_322 ( struct V_8 * V_20 , struct V_191 * V_43 ,
struct V_38 * V_42 , T_3 V_398 )
{
int V_21 = 0 ;
F_21 ( L_95 , V_20 ,
V_43 , V_42 , V_398 , V_20 -> V_271 ) ;
if ( F_321 ( V_20 , V_43 -> V_192 ) ) {
switch ( V_20 -> V_271 ) {
case V_368 :
V_21 = F_315 ( V_20 , V_43 , V_42 , V_398 ) ;
break;
case V_400 :
V_21 = F_317 ( V_20 , V_43 , V_42 ,
V_398 ) ;
break;
case V_280 :
V_21 = F_319 ( V_20 , V_43 , V_42 , V_398 ) ;
break;
case V_278 :
V_21 = F_320 ( V_20 , V_43 , V_42 , V_398 ) ;
break;
default:
break;
}
} else {
F_21 ( L_96 ,
V_43 -> V_192 , V_20 -> V_358 ,
V_20 -> V_397 ) ;
F_83 ( V_20 , V_305 ) ;
}
return V_21 ;
}
static int F_323 ( struct V_8 * V_20 , struct V_191 * V_43 ,
struct V_38 * V_42 )
{
int V_21 = 0 ;
F_21 ( L_97 , V_20 , V_43 , V_42 ,
V_20 -> V_271 ) ;
if ( F_314 ( V_20 , V_43 -> V_44 ) ==
V_599 ) {
F_223 ( V_20 , V_43 ) ;
F_21 ( L_98 , V_20 -> V_245 ,
F_184 ( V_20 , V_20 -> V_245 ) ) ;
V_20 -> V_245 = F_184 ( V_20 , V_20 -> V_245 ) ;
F_308 ( V_20 , V_42 , V_43 ) ;
} else {
if ( V_20 -> V_90 ) {
F_96 ( V_20 -> V_90 ) ;
V_20 -> V_90 = NULL ;
}
V_20 -> V_91 = NULL ;
V_20 -> V_92 = 0 ;
if ( V_42 ) {
F_21 ( L_94 , V_42 ) ;
F_96 ( V_42 ) ;
}
}
V_20 -> V_243 = V_43 -> V_44 ;
V_20 -> V_266 = F_184 ( V_20 , V_43 -> V_44 ) ;
return V_21 ;
}
static int F_324 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
struct V_191 * V_43 = & F_33 ( V_42 ) -> V_43 ;
T_2 V_174 ;
T_3 V_398 ;
F_99 ( V_20 , V_42 ) ;
V_174 = V_42 -> V_174 ;
if ( F_303 ( V_20 , V_42 ) )
goto V_584;
if ( ! V_43 -> V_199 && V_43 -> V_206 == V_388 )
V_174 -= V_382 ;
if ( V_20 -> V_79 == V_80 )
V_174 -= V_235 ;
if ( V_174 > V_20 -> V_96 ) {
F_83 ( V_20 , V_305 ) ;
goto V_584;
}
if ( ! V_43 -> V_199 ) {
int V_21 ;
F_21 ( L_99 ,
V_43 -> V_206 , V_43 -> V_192 , V_43 -> V_195 ,
V_43 -> V_44 ) ;
if ( V_43 -> V_195 && V_20 -> V_269 != V_403 )
goto V_584;
if ( V_20 -> V_132 != V_139 ) {
V_398 = V_603 ;
V_21 = F_322 ( V_20 , V_43 , V_42 , V_398 ) ;
} else {
V_21 = F_323 ( V_20 , V_43 , V_42 ) ;
}
if ( V_21 )
F_83 ( V_20 , V_305 ) ;
} else {
const T_3 V_610 [ 4 ] = {
V_604 , V_606 ,
V_605 , V_607
} ;
if ( V_20 -> V_132 == V_139 )
goto V_584;
F_21 ( L_100 ,
V_43 -> V_192 , V_43 -> V_195 , V_43 -> V_200 ,
V_43 -> V_203 ) ;
if ( V_174 != 0 ) {
F_295 ( L_101 , V_174 ) ;
F_83 ( V_20 , V_305 ) ;
goto V_584;
}
if ( V_43 -> V_195 && ( V_43 -> V_200 ||
V_20 -> V_269 != V_403 ) )
goto V_584;
V_398 = V_610 [ V_43 -> V_203 ] ;
if ( F_322 ( V_20 , V_43 , V_42 , V_398 ) )
F_83 ( V_20 , V_305 ) ;
}
return 0 ;
V_584:
F_96 ( V_42 ) ;
return 0 ;
}
static void F_325 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct F_298 V_579 ;
T_2 V_611 ;
if ( V_20 -> V_94 >= ( V_95 + 1 ) / 2 )
return;
V_611 = V_95 - V_20 -> V_94 ;
F_21 ( L_102 , V_20 , V_611 ) ;
V_20 -> V_94 += V_611 ;
V_579 . V_11 = F_16 ( V_20 -> V_14 ) ;
V_579 . V_148 = F_16 ( V_611 ) ;
V_20 -> V_16 = F_88 ( V_10 ) ;
F_79 ( V_10 , V_20 -> V_16 , V_582 , sizeof( V_579 ) , & V_579 ) ;
}
static int F_326 ( struct V_8 * V_20 , struct V_38 * V_42 )
{
int V_21 ;
if ( ! V_20 -> V_94 ) {
F_295 ( L_103 ) ;
return - V_612 ;
}
if ( V_20 -> V_97 < V_42 -> V_174 ) {
F_295 ( L_104 ) ;
return - V_612 ;
}
V_20 -> V_94 -- ;
F_21 ( L_105 , V_20 -> V_94 + 1 , V_20 -> V_94 ) ;
F_325 ( V_20 ) ;
V_21 = 0 ;
if ( ! V_20 -> V_90 ) {
T_2 V_92 ;
V_92 = F_102 ( V_42 -> V_175 ) ;
F_101 ( V_42 , V_382 ) ;
F_21 ( L_106 ,
V_92 , V_42 -> V_174 , V_20 -> V_97 ) ;
if ( V_92 > V_20 -> V_97 ) {
F_295 ( L_107 ) ;
V_21 = - V_391 ;
goto V_613;
}
if ( V_42 -> V_174 > V_92 ) {
F_295 ( L_108 ) ;
V_21 = - V_26 ;
goto V_613;
}
if ( V_42 -> V_174 == V_92 )
return V_20 -> V_32 -> V_408 ( V_20 , V_42 ) ;
V_20 -> V_90 = V_42 ;
V_20 -> V_92 = V_92 ;
V_20 -> V_91 = V_42 ;
return 0 ;
}
F_21 ( L_109 ,
V_20 -> V_90 -> V_174 , V_42 -> V_174 , V_20 -> V_92 ) ;
if ( V_20 -> V_90 -> V_174 + V_42 -> V_174 > V_20 -> V_92 ) {
F_295 ( L_108 ) ;
V_21 = - V_26 ;
goto V_613;
}
F_306 ( V_20 -> V_90 , V_42 , & V_20 -> V_91 ) ;
V_42 = NULL ;
if ( V_20 -> V_90 -> V_174 == V_20 -> V_92 ) {
V_21 = V_20 -> V_32 -> V_408 ( V_20 , V_20 -> V_90 ) ;
if ( ! V_21 ) {
V_20 -> V_90 = NULL ;
V_20 -> V_91 = NULL ;
V_20 -> V_92 = 0 ;
}
}
V_613:
if ( V_21 ) {
F_96 ( V_42 ) ;
F_96 ( V_20 -> V_90 ) ;
V_20 -> V_90 = NULL ;
V_20 -> V_91 = NULL ;
V_20 -> V_92 = 0 ;
}
return 0 ;
}
static void F_327 ( struct V_9 * V_10 , T_2 V_11 ,
struct V_38 * V_42 )
{
struct V_8 * V_20 ;
V_20 = F_5 ( V_10 , V_11 ) ;
if ( ! V_20 ) {
if ( V_11 == V_110 ) {
V_20 = F_328 ( V_10 , V_42 ) ;
if ( ! V_20 ) {
F_96 ( V_42 ) ;
return;
}
F_7 ( V_20 ) ;
} else {
F_21 ( L_110 , V_11 ) ;
F_96 ( V_42 ) ;
return;
}
}
F_21 ( L_111 , V_20 , V_42 -> V_174 ) ;
if ( V_20 -> V_31 != V_62 )
goto V_584;
switch ( V_20 -> V_132 ) {
case V_134 :
if ( F_326 ( V_20 , V_42 ) < 0 )
goto V_584;
goto V_24;
case V_133 :
if ( V_20 -> V_97 < V_42 -> V_174 )
goto V_584;
if ( ! V_20 -> V_32 -> V_408 ( V_20 , V_42 ) )
goto V_24;
break;
case V_135 :
case V_139 :
F_324 ( V_20 , V_42 ) ;
goto V_24;
default:
F_21 ( L_112 , V_20 , V_20 -> V_132 ) ;
break;
}
V_584:
F_96 ( V_42 ) ;
V_24:
F_47 ( V_20 ) ;
}
static void F_329 ( struct V_9 * V_10 , T_4 V_17 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 ;
if ( V_2 -> type != V_158 )
goto V_584;
V_20 = F_170 ( 0 , V_17 , & V_2 -> V_18 , & V_2 -> V_315 ,
V_158 ) ;
if ( ! V_20 )
goto V_584;
F_21 ( L_111 , V_20 , V_42 -> V_174 ) ;
if ( V_20 -> V_31 != V_352 && V_20 -> V_31 != V_62 )
goto V_584;
if ( V_20 -> V_97 < V_42 -> V_174 )
goto V_584;
F_145 ( & F_33 ( V_42 ) -> V_614 , & V_2 -> V_315 ) ;
F_33 ( V_42 ) -> V_17 = V_17 ;
if ( ! V_20 -> V_32 -> V_408 ( V_20 , V_42 ) )
return;
V_584:
F_96 ( V_42 ) ;
}
static void F_330 ( struct V_9 * V_10 ,
struct V_38 * V_42 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 ;
if ( V_2 -> type != V_3 )
goto V_584;
V_20 = F_141 ( V_62 , V_104 ,
& V_2 -> V_18 , & V_2 -> V_315 ) ;
if ( ! V_20 )
goto V_584;
F_21 ( L_111 , V_20 , V_42 -> V_174 ) ;
if ( F_144 ( V_2 -> V_176 , & V_2 -> V_315 , V_2 -> V_323 ) )
goto V_584;
if ( V_20 -> V_97 < V_42 -> V_174 )
goto V_584;
if ( ! V_20 -> V_32 -> V_408 ( V_20 , V_42 ) )
return;
V_584:
F_96 ( V_42 ) ;
}
static void F_331 ( struct V_9 * V_10 , struct V_38 * V_42 )
{
struct V_232 * V_233 = ( void * ) V_42 -> V_175 ;
T_2 V_11 , V_174 ;
T_4 V_17 ;
F_101 ( V_42 , V_229 ) ;
V_11 = F_67 ( V_233 -> V_11 ) ;
V_174 = F_67 ( V_233 -> V_174 ) ;
if ( V_174 != V_42 -> V_174 ) {
F_96 ( V_42 ) ;
return;
}
F_21 ( L_113 , V_174 , V_11 ) ;
switch ( V_11 ) {
case V_112 :
F_302 ( V_10 , V_42 ) ;
break;
case V_108 :
V_17 = F_332 ( ( T_4 * ) V_42 -> V_175 ) ;
F_101 ( V_42 , V_380 ) ;
F_329 ( V_10 , V_17 , V_42 ) ;
break;
case V_104 :
F_330 ( V_10 , V_42 ) ;
break;
case V_413 :
F_301 ( V_10 , V_42 ) ;
break;
case V_615 :
if ( F_333 ( V_10 , V_42 ) )
F_156 ( V_10 -> V_2 , V_616 ) ;
break;
case V_617 :
F_334 ( V_10 , V_42 ) ;
break;
default:
F_327 ( V_10 , V_11 , V_42 ) ;
break;
}
}
int F_335 ( struct V_247 * V_176 , T_5 * V_614 )
{
int V_618 = 0 , V_619 = 0 , V_620 = 0 ;
struct V_8 * V_12 ;
F_21 ( L_114 , V_176 -> V_621 , V_614 ) ;
F_121 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_12 -> V_31 != V_155 )
continue;
if ( ! F_13 ( & V_12 -> V_18 , & V_176 -> V_614 ) ) {
V_619 |= V_622 ;
if ( F_74 ( V_623 , & V_12 -> V_89 ) )
V_619 |= V_571 ;
V_618 ++ ;
} else if ( ! F_13 ( & V_12 -> V_18 , V_321 ) ) {
V_620 |= V_622 ;
if ( F_74 ( V_623 , & V_12 -> V_89 ) )
V_620 |= V_571 ;
}
}
F_122 ( & V_22 ) ;
return V_618 ? V_619 : V_620 ;
}
void F_336 ( struct V_1 * V_2 , T_3 V_152 )
{
struct V_9 * V_10 ;
F_21 ( L_115 , V_2 , & V_2 -> V_315 , V_152 ) ;
if ( ! V_152 ) {
V_10 = F_162 ( V_2 ) ;
if ( V_10 )
F_146 ( V_10 ) ;
} else {
F_156 ( V_2 , F_337 ( V_152 ) ) ;
}
}
int F_338 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_338 ;
F_21 ( L_116 , V_2 ) ;
if ( ! V_10 )
return V_101 ;
return V_10 -> V_100 ;
}
void F_339 ( struct V_1 * V_2 , T_3 V_61 )
{
F_21 ( L_117 , V_2 , V_61 ) ;
F_340 ( V_2 -> V_338 ) ;
F_156 ( V_2 , F_337 ( V_61 ) ) ;
}
static inline void F_341 ( struct V_8 * V_20 , T_3 V_624 )
{
if ( V_20 -> V_102 != V_103 )
return;
if ( V_624 == 0x00 ) {
if ( V_20 -> V_66 == V_162 ) {
F_82 ( V_20 , V_625 ) ;
} else if ( V_20 -> V_66 == V_160 )
F_46 ( V_20 , V_64 ) ;
} else {
if ( V_20 -> V_66 == V_162 )
F_71 ( V_20 ) ;
}
}
int F_342 ( struct V_1 * V_2 , T_3 V_152 , T_3 V_624 )
{
struct V_9 * V_10 = V_2 -> V_338 ;
struct V_8 * V_20 ;
if ( ! V_10 )
return 0 ;
F_21 ( L_118 , V_10 , V_152 , V_624 ) ;
if ( V_2 -> type == V_3 ) {
if ( ! V_152 && V_624 )
F_343 ( V_10 , 0 ) ;
F_248 ( & V_10 -> V_342 ) ;
}
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
F_21 ( L_119 , V_20 , V_20 -> V_14 ,
F_22 ( V_20 -> V_31 ) ) ;
if ( V_20 -> V_102 == V_109 ) {
F_47 ( V_20 ) ;
continue;
}
if ( V_20 -> V_14 == V_104 ) {
if ( ! V_152 && V_624 ) {
V_20 -> V_66 = V_2 -> V_66 ;
F_129 ( V_20 ) ;
}
F_47 ( V_20 ) ;
continue;
}
if ( ! F_119 ( V_20 ) ) {
F_47 ( V_20 ) ;
continue;
}
if ( ! V_152 && ( V_20 -> V_31 == V_62 ||
V_20 -> V_31 == V_63 ) ) {
V_20 -> V_32 -> V_580 ( V_20 ) ;
F_341 ( V_20 , V_624 ) ;
F_47 ( V_20 ) ;
continue;
}
if ( V_20 -> V_31 == V_65 ) {
if ( ! V_152 )
F_133 ( V_20 ) ;
else
F_82 ( V_20 , V_626 ) ;
} else if ( V_20 -> V_31 == V_157 ) {
struct V_150 V_141 ;
T_6 V_627 , V_628 ;
if ( ! V_152 ) {
if ( F_74 ( V_143 , & V_20 -> V_89 ) ) {
V_627 = V_307 ;
V_628 = V_308 ;
V_20 -> V_32 -> V_309 ( V_20 ) ;
} else {
F_20 ( V_20 , V_63 ) ;
V_627 = V_310 ;
V_628 = V_153 ;
}
} else {
F_20 ( V_20 , V_146 ) ;
F_82 ( V_20 , V_626 ) ;
V_627 = V_151 ;
V_628 = V_153 ;
}
V_141 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_141 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_141 . V_142 = F_16 ( V_627 ) ;
V_141 . V_152 = F_16 ( V_628 ) ;
F_79 ( V_10 , V_20 -> V_16 , V_154 ,
sizeof( V_141 ) , & V_141 ) ;
if ( ! F_74 ( V_312 , & V_20 -> V_77 ) &&
V_627 == V_310 ) {
char V_306 [ 128 ] ;
F_55 ( V_312 , & V_20 -> V_77 ) ;
F_79 ( V_10 , F_88 ( V_10 ) ,
V_313 ,
F_140 ( V_20 , V_306 ) ,
V_306 ) ;
V_20 -> V_314 ++ ;
}
}
F_47 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
int F_344 ( struct V_1 * V_2 , struct V_38 * V_42 , T_2 V_89 )
{
struct V_9 * V_10 = V_2 -> V_338 ;
struct V_232 * V_629 ;
int V_174 ;
if ( ! V_10 && V_2 -> V_176 -> V_525 != V_630 )
goto V_584;
if ( ! V_10 )
V_10 = F_162 ( V_2 ) ;
if ( ! V_10 )
goto V_584;
F_21 ( L_120 , V_10 , V_42 -> V_174 , V_89 ) ;
switch ( V_89 ) {
case V_178 :
case V_177 :
case V_188 :
if ( V_10 -> V_631 ) {
F_295 ( L_121 , V_42 -> V_174 ) ;
F_96 ( V_10 -> V_340 ) ;
V_10 -> V_340 = NULL ;
V_10 -> V_631 = 0 ;
F_147 ( V_10 , V_632 ) ;
}
if ( V_42 -> V_174 < V_229 ) {
F_295 ( L_122 , V_42 -> V_174 ) ;
F_147 ( V_10 , V_632 ) ;
goto V_584;
}
V_629 = (struct V_232 * ) V_42 -> V_175 ;
V_174 = F_67 ( V_629 -> V_174 ) + V_229 ;
if ( V_174 == V_42 -> V_174 ) {
F_331 ( V_10 , V_42 ) ;
return 0 ;
}
F_21 ( L_123 , V_174 , V_42 -> V_174 ) ;
if ( V_42 -> V_174 > V_174 ) {
F_295 ( L_124 ,
V_42 -> V_174 , V_174 ) ;
F_147 ( V_10 , V_632 ) ;
goto V_584;
}
V_10 -> V_340 = F_110 ( V_174 , V_51 ) ;
if ( ! V_10 -> V_340 )
goto V_584;
F_345 ( V_42 , F_112 ( V_10 -> V_340 , V_42 -> V_174 ) ,
V_42 -> V_174 ) ;
V_10 -> V_631 = V_174 - V_42 -> V_174 ;
break;
case V_633 :
F_21 ( L_125 , V_42 -> V_174 , V_10 -> V_631 ) ;
if ( ! V_10 -> V_631 ) {
F_295 ( L_126 , V_42 -> V_174 ) ;
F_147 ( V_10 , V_632 ) ;
goto V_584;
}
if ( V_42 -> V_174 > V_10 -> V_631 ) {
F_295 ( L_127 ,
V_42 -> V_174 , V_10 -> V_631 ) ;
F_96 ( V_10 -> V_340 ) ;
V_10 -> V_340 = NULL ;
V_10 -> V_631 = 0 ;
F_147 ( V_10 , V_632 ) ;
goto V_584;
}
F_345 ( V_42 , F_112 ( V_10 -> V_340 , V_42 -> V_174 ) ,
V_42 -> V_174 ) ;
V_10 -> V_631 -= V_42 -> V_174 ;
if ( ! V_10 -> V_631 ) {
struct V_38 * V_340 = V_10 -> V_340 ;
V_10 -> V_340 = NULL ;
F_331 ( V_10 , V_340 ) ;
}
break;
}
V_584:
F_96 ( V_42 ) ;
return 0 ;
}
static int F_346 ( struct V_634 * V_635 , void * V_25 )
{
struct V_8 * V_12 ;
F_121 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
F_347 ( V_635 , L_128 ,
& V_12 -> V_18 , & V_12 -> V_315 ,
V_12 -> V_31 , F_67 ( V_12 -> V_17 ) ,
V_12 -> V_14 , V_12 -> V_13 , V_12 -> V_97 , V_12 -> V_105 ,
V_12 -> V_66 , V_12 -> V_132 ) ;
}
F_122 ( & V_22 ) ;
return 0 ;
}
static int F_348 ( struct V_636 * V_636 , struct V_637 * V_637 )
{
return F_349 ( V_637 , F_346 , V_636 -> V_638 ) ;
}
int T_11 F_350 ( void )
{
int V_21 ;
V_21 = F_351 () ;
if ( V_21 < 0 )
return V_21 ;
if ( F_352 ( V_639 ) )
return 0 ;
V_640 = F_353 ( L_129 , 0444 , V_639 ,
NULL , & V_641 ) ;
F_354 ( L_130 , 0466 , V_639 ,
& V_95 ) ;
F_354 ( L_131 , 0466 , V_639 ,
& V_642 ) ;
F_355 () ;
return 0 ;
}
void F_356 ( void )
{
F_357 () ;
F_358 ( V_640 ) ;
F_359 () ;
}
