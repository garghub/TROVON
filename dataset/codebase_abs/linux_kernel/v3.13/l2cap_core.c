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
T_2 V_11 = V_27 ;
for (; V_11 < V_28 ; V_11 ++ ) {
if ( ! F_4 ( V_10 , V_11 ) )
return V_11 ;
}
return 0 ;
}
static void F_20 ( struct V_8 * V_20 , int V_29 )
{
F_21 ( L_1 , V_20 , F_22 ( V_20 -> V_29 ) ,
F_22 ( V_29 ) ) ;
V_20 -> V_29 = V_29 ;
V_20 -> V_30 -> V_31 ( V_20 , V_29 , 0 ) ;
}
static inline void F_23 ( struct V_8 * V_20 ,
int V_29 , int V_21 )
{
V_20 -> V_29 = V_29 ;
V_20 -> V_30 -> V_31 ( V_20 , V_20 -> V_29 , V_21 ) ;
}
static inline void F_24 ( struct V_8 * V_20 , int V_21 )
{
V_20 -> V_30 -> V_31 ( V_20 , V_20 -> V_29 , V_21 ) ;
}
static void F_25 ( struct V_8 * V_20 )
{
if ( ! F_26 ( & V_20 -> V_32 ) &&
V_20 -> V_33 ) {
F_27 ( V_20 , & V_20 -> V_34 ,
F_28 ( V_20 -> V_33 ) ) ;
}
}
static void F_29 ( struct V_8 * V_20 )
{
F_30 ( V_20 ) ;
if ( V_20 -> V_35 ) {
F_27 ( V_20 , & V_20 -> V_32 ,
F_28 ( V_20 -> V_35 ) ) ;
}
}
static struct V_36 * F_31 ( struct V_37 * V_38 ,
T_2 V_39 )
{
struct V_36 * V_40 ;
F_32 (head, skb) {
if ( F_33 ( V_40 ) -> V_41 . V_42 == V_39 )
return V_40 ;
}
return NULL ;
}
static int F_34 ( struct V_43 * V_44 , T_2 V_45 )
{
T_7 V_46 , V_47 ;
V_46 = F_35 ( V_45 ) ;
V_44 -> V_48 = F_36 ( sizeof( T_2 ) * V_46 , V_49 ) ;
if ( ! V_44 -> V_48 )
return - V_50 ;
V_44 -> V_51 = V_46 - 1 ;
V_44 -> V_38 = V_52 ;
V_44 -> V_53 = V_52 ;
for ( V_47 = 0 ; V_47 < V_46 ; V_47 ++ )
V_44 -> V_48 [ V_47 ] = V_52 ;
return 0 ;
}
static inline void F_37 ( struct V_43 * V_44 )
{
F_38 ( V_44 -> V_48 ) ;
}
static inline bool F_39 ( struct V_43 * V_44 ,
T_2 V_39 )
{
return V_44 -> V_48 [ V_39 & V_44 -> V_51 ] != V_52 ;
}
static T_2 F_40 ( struct V_43 * V_44 , T_2 V_39 )
{
T_2 V_51 = V_44 -> V_51 ;
if ( V_44 -> V_38 == V_52 ) {
return V_52 ;
} else if ( V_44 -> V_38 == V_39 ) {
V_44 -> V_38 = V_44 -> V_48 [ V_39 & V_51 ] ;
V_44 -> V_48 [ V_39 & V_51 ] = V_52 ;
if ( V_44 -> V_38 == V_54 ) {
V_44 -> V_38 = V_52 ;
V_44 -> V_53 = V_52 ;
}
} else {
T_2 V_55 = V_44 -> V_38 ;
while ( V_44 -> V_48 [ V_55 & V_51 ] != V_39 ) {
V_55 = V_44 -> V_48 [ V_55 & V_51 ] ;
if ( V_55 == V_54 )
return V_52 ;
}
V_44 -> V_48 [ V_55 & V_51 ] = V_44 -> V_48 [ V_39 & V_51 ] ;
V_44 -> V_48 [ V_39 & V_51 ] = V_52 ;
if ( V_44 -> V_53 == V_39 )
V_44 -> V_53 = V_55 ;
}
return V_39 ;
}
static inline T_2 F_41 ( struct V_43 * V_44 )
{
return F_40 ( V_44 , V_44 -> V_38 ) ;
}
static void F_42 ( struct V_43 * V_44 )
{
T_2 V_47 ;
if ( V_44 -> V_38 == V_52 )
return;
for ( V_47 = 0 ; V_47 <= V_44 -> V_51 ; V_47 ++ )
V_44 -> V_48 [ V_47 ] = V_52 ;
V_44 -> V_38 = V_52 ;
V_44 -> V_53 = V_52 ;
}
static void F_43 ( struct V_43 * V_44 , T_2 V_39 )
{
T_2 V_51 = V_44 -> V_51 ;
if ( V_44 -> V_48 [ V_39 & V_51 ] != V_52 )
return;
if ( V_44 -> V_53 == V_52 )
V_44 -> V_38 = V_39 ;
else
V_44 -> V_48 [ V_44 -> V_53 & V_51 ] = V_39 ;
V_44 -> V_53 = V_39 ;
V_44 -> V_48 [ V_39 & V_51 ] = V_54 ;
}
static void F_44 ( struct V_56 * V_57 )
{
struct V_8 * V_20 = F_45 ( V_57 , struct V_8 ,
V_58 . V_57 ) ;
struct V_9 * V_10 = V_20 -> V_10 ;
int V_59 ;
F_21 ( L_2 , V_20 , F_22 ( V_20 -> V_29 ) ) ;
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_20 ) ;
if ( V_20 -> V_29 == V_60 || V_20 -> V_29 == V_61 )
V_59 = V_62 ;
else if ( V_20 -> V_29 == V_63 &&
V_20 -> V_64 != V_65 )
V_59 = V_62 ;
else
V_59 = V_66 ;
F_46 ( V_20 , V_59 ) ;
F_47 ( V_20 ) ;
V_20 -> V_30 -> V_67 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
F_48 ( V_20 ) ;
}
struct V_8 * F_49 ( void )
{
struct V_8 * V_20 ;
V_20 = F_50 ( sizeof( * V_20 ) , V_68 ) ;
if ( ! V_20 )
return NULL ;
F_51 ( & V_20 -> V_69 ) ;
F_15 ( & V_22 ) ;
F_52 ( & V_20 -> V_70 , & V_71 ) ;
F_17 ( & V_22 ) ;
F_53 ( & V_20 -> V_58 , F_44 ) ;
V_20 -> V_29 = V_72 ;
F_54 ( & V_20 -> V_73 ) ;
F_55 ( V_74 , & V_20 -> V_75 ) ;
F_21 ( L_3 , V_20 ) ;
return V_20 ;
}
static void F_56 ( struct V_73 * V_73 )
{
struct V_8 * V_20 = F_45 ( V_73 , struct V_8 , V_73 ) ;
F_21 ( L_3 , V_20 ) ;
F_15 ( & V_22 ) ;
F_57 ( & V_20 -> V_70 ) ;
F_17 ( & V_22 ) ;
F_38 ( V_20 ) ;
}
void F_58 ( struct V_8 * V_12 )
{
F_21 ( L_4 , V_12 , F_59 ( & V_12 -> V_73 . V_76 ) ) ;
F_60 ( & V_12 -> V_73 ) ;
}
void F_48 ( struct V_8 * V_12 )
{
F_21 ( L_4 , V_12 , F_59 ( & V_12 -> V_73 . V_76 ) ) ;
F_61 ( & V_12 -> V_73 , F_56 ) ;
}
void F_62 ( struct V_8 * V_20 )
{
V_20 -> V_77 = V_78 ;
V_20 -> V_79 = V_80 ;
V_20 -> V_81 = V_82 ;
V_20 -> V_83 = V_82 ;
V_20 -> V_84 = V_82 ;
V_20 -> V_64 = V_85 ;
F_55 ( V_86 , & V_20 -> V_87 ) ;
}
void F_63 ( struct V_9 * V_10 , struct V_8 * V_20 )
{
F_21 ( L_5 , V_10 ,
F_64 ( V_20 -> V_17 ) , V_20 -> V_13 ) ;
V_10 -> V_88 = V_89 ;
V_20 -> V_10 = V_10 ;
switch ( V_20 -> V_90 ) {
case V_91 :
if ( V_10 -> V_2 -> type == V_3 ) {
V_20 -> V_92 = V_93 ;
if ( V_20 -> V_13 == V_94 )
V_20 -> V_14 = V_94 ;
else
V_20 -> V_14 = F_19 ( V_10 ) ;
} else {
V_20 -> V_14 = F_19 ( V_10 ) ;
V_20 -> V_92 = V_93 ;
}
break;
case V_95 :
V_20 -> V_14 = V_96 ;
V_20 -> V_13 = V_96 ;
V_20 -> V_92 = V_93 ;
break;
case V_97 :
V_20 -> V_14 = V_98 ;
V_20 -> V_13 = V_98 ;
V_20 -> V_92 = V_99 ;
V_20 -> V_100 = V_99 ;
break;
default:
V_20 -> V_14 = V_101 ;
V_20 -> V_13 = V_101 ;
V_20 -> V_92 = V_93 ;
}
V_20 -> V_102 = V_103 ;
V_20 -> V_104 = V_105 ;
V_20 -> V_106 = V_107 ;
V_20 -> V_108 = V_109 ;
V_20 -> V_110 = V_111 ;
V_20 -> V_112 = V_113 ;
F_58 ( V_20 ) ;
F_65 ( V_10 -> V_2 ) ;
F_52 ( & V_20 -> V_48 , & V_10 -> V_114 ) ;
}
void F_66 ( struct V_9 * V_10 , struct V_8 * V_20 )
{
F_6 ( & V_10 -> V_15 ) ;
F_63 ( V_10 , V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
}
void F_67 ( struct V_8 * V_20 , int V_21 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_68 ( V_20 ) ;
F_21 ( L_6 , V_20 , V_10 , V_21 ) ;
if ( V_10 ) {
struct V_115 * V_116 = V_10 -> V_2 -> V_115 ;
F_57 ( & V_20 -> V_48 ) ;
F_48 ( V_20 ) ;
V_20 -> V_10 = NULL ;
if ( V_20 -> V_90 != V_97 )
F_69 ( V_10 -> V_2 ) ;
if ( V_116 && V_116 -> V_117 == V_20 )
V_116 -> V_117 = NULL ;
}
if ( V_20 -> V_118 ) {
struct V_119 * V_118 = V_20 -> V_118 ;
F_21 ( L_7 , V_20 , V_118 ) ;
F_70 ( V_118 ) ;
}
V_20 -> V_30 -> V_120 ( V_20 , V_21 ) ;
if ( F_71 ( V_74 , & V_20 -> V_75 ) )
return;
switch( V_20 -> V_121 ) {
case V_122 :
break;
case V_123 :
F_30 ( V_20 ) ;
F_72 ( V_20 ) ;
F_73 ( V_20 ) ;
F_74 ( & V_20 -> V_124 ) ;
F_37 ( & V_20 -> V_125 ) ;
F_37 ( & V_20 -> V_126 ) ;
case V_127 :
F_74 ( & V_20 -> V_128 ) ;
break;
}
return;
}
void F_46 ( struct V_8 * V_20 , int V_59 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_2 , V_20 , F_22 ( V_20 -> V_29 ) ) ;
switch ( V_20 -> V_29 ) {
case V_129 :
V_20 -> V_30 -> V_120 ( V_20 , 0 ) ;
break;
case V_60 :
case V_61 :
if ( V_20 -> V_90 == V_91 &&
V_10 -> V_2 -> type == V_130 ) {
F_75 ( V_20 , V_20 -> V_30 -> V_131 ( V_20 ) ) ;
F_76 ( V_20 , V_59 ) ;
} else
F_67 ( V_20 , V_59 ) ;
break;
case V_132 :
if ( V_20 -> V_90 == V_91 &&
V_10 -> V_2 -> type == V_130 ) {
struct V_133 V_134 ;
T_6 V_135 ;
if ( F_71 ( V_136 , & V_20 -> V_87 ) )
V_135 = V_137 ;
else
V_135 = V_138 ;
F_20 ( V_20 , V_139 ) ;
V_134 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_134 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_134 . V_135 = F_16 ( V_135 ) ;
V_134 . V_140 = F_77 ( V_141 ) ;
F_78 ( V_10 , V_20 -> V_16 , V_142 ,
sizeof( V_134 ) , & V_134 ) ;
}
F_67 ( V_20 , V_59 ) ;
break;
case V_63 :
case V_139 :
F_67 ( V_20 , V_59 ) ;
break;
default:
V_20 -> V_30 -> V_120 ( V_20 , 0 ) ;
break;
}
}
static inline T_3 F_79 ( struct V_8 * V_20 )
{
switch ( V_20 -> V_90 ) {
case V_143 :
switch ( V_20 -> V_64 ) {
case V_144 :
return V_145 ;
case V_146 :
return V_147 ;
default:
return V_148 ;
}
break;
case V_95 :
if ( V_20 -> V_17 == F_77 ( V_149 ) ) {
if ( V_20 -> V_64 == V_85 )
V_20 -> V_64 = V_65 ;
}
if ( V_20 -> V_64 == V_144 )
return V_150 ;
else
return V_148 ;
break;
case V_91 :
if ( V_20 -> V_17 == F_77 ( V_151 ) ) {
if ( V_20 -> V_64 == V_85 )
V_20 -> V_64 = V_65 ;
if ( V_20 -> V_64 == V_144 )
return V_150 ;
else
return V_148 ;
}
default:
switch ( V_20 -> V_64 ) {
case V_144 :
return V_152 ;
case V_146 :
return V_153 ;
default:
return V_148 ;
}
break;
}
}
int F_80 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
T_1 V_154 ;
V_154 = F_79 ( V_20 ) ;
return F_81 ( V_10 -> V_2 , V_20 -> V_64 , V_154 ) ;
}
static T_3 F_82 ( struct V_9 * V_10 )
{
T_3 V_155 ;
F_83 ( & V_10 -> V_69 ) ;
if ( ++ V_10 -> V_156 > 128 )
V_10 -> V_156 = 1 ;
V_155 = V_10 -> V_156 ;
F_84 ( & V_10 -> V_69 ) ;
return V_155 ;
}
static void F_78 ( struct V_9 * V_10 , T_3 V_16 , T_3 V_157 , T_2 V_158 ,
void * V_159 )
{
struct V_36 * V_40 = F_85 ( V_10 , V_157 , V_16 , V_158 , V_159 ) ;
T_3 V_87 ;
F_21 ( L_8 , V_157 ) ;
if ( ! V_40 )
return;
if ( F_86 ( V_10 -> V_2 -> V_160 ) )
V_87 = V_161 ;
else
V_87 = V_162 ;
F_33 ( V_40 ) -> V_163 = V_164 ;
V_40 -> V_165 = V_166 ;
F_87 ( V_10 -> V_167 , V_40 , V_87 ) ;
}
static bool F_88 ( struct V_8 * V_20 )
{
return V_20 -> V_168 != V_169 &&
V_20 -> V_168 != V_170 ;
}
static void F_89 ( struct V_8 * V_20 , struct V_36 * V_40 )
{
struct V_1 * V_2 = V_20 -> V_10 -> V_2 ;
T_2 V_87 ;
F_21 ( L_9 , V_20 , V_40 , V_40 -> V_158 ,
V_40 -> V_165 ) ;
if ( V_20 -> V_171 && ! F_88 ( V_20 ) ) {
if ( V_20 -> V_118 )
F_87 ( V_20 -> V_118 , V_40 , V_172 ) ;
else
F_90 ( V_40 ) ;
return;
}
if ( ! F_71 ( V_173 , & V_20 -> V_87 ) &&
F_86 ( V_2 -> V_160 ) )
V_87 = V_161 ;
else
V_87 = V_162 ;
F_33 ( V_40 ) -> V_163 = F_71 ( V_86 , & V_20 -> V_87 ) ;
F_87 ( V_20 -> V_10 -> V_167 , V_40 , V_87 ) ;
}
static void F_91 ( T_2 V_174 , struct V_175 * V_41 )
{
V_41 -> V_176 = ( V_174 & V_177 ) >> V_178 ;
V_41 -> V_179 = ( V_174 & V_180 ) >> V_181 ;
if ( V_174 & V_182 ) {
V_41 -> V_183 = 1 ;
V_41 -> V_184 = ( V_174 & V_185 ) >> V_186 ;
V_41 -> V_187 = ( V_174 & V_188 ) >> V_189 ;
V_41 -> V_190 = 0 ;
V_41 -> V_42 = 0 ;
} else {
V_41 -> V_183 = 0 ;
V_41 -> V_190 = ( V_174 & V_191 ) >> V_192 ;
V_41 -> V_42 = ( V_174 & V_193 ) >> V_194 ;
V_41 -> V_184 = 0 ;
V_41 -> V_187 = 0 ;
}
}
static void F_92 ( T_8 V_195 , struct V_175 * V_41 )
{
V_41 -> V_176 = ( V_195 & V_196 ) >> V_197 ;
V_41 -> V_179 = ( V_195 & V_198 ) >> V_199 ;
if ( V_195 & V_200 ) {
V_41 -> V_183 = 1 ;
V_41 -> V_184 = ( V_195 & V_201 ) >> V_202 ;
V_41 -> V_187 = ( V_195 & V_203 ) >> V_204 ;
V_41 -> V_190 = 0 ;
V_41 -> V_42 = 0 ;
} else {
V_41 -> V_183 = 0 ;
V_41 -> V_190 = ( V_195 & V_205 ) >> V_206 ;
V_41 -> V_42 = ( V_195 & V_207 ) >> V_208 ;
V_41 -> V_184 = 0 ;
V_41 -> V_187 = 0 ;
}
}
static inline void F_93 ( struct V_8 * V_20 ,
struct V_36 * V_40 )
{
if ( F_71 ( V_209 , & V_20 -> V_87 ) ) {
F_92 ( F_94 ( V_40 -> V_159 ) ,
& F_33 ( V_40 ) -> V_41 ) ;
F_95 ( V_40 , V_210 ) ;
} else {
F_91 ( F_96 ( V_40 -> V_159 ) ,
& F_33 ( V_40 ) -> V_41 ) ;
F_95 ( V_40 , V_211 ) ;
}
}
static T_8 F_97 ( struct V_175 * V_41 )
{
T_8 V_212 ;
V_212 = V_41 -> V_176 << V_197 ;
V_212 |= V_41 -> V_179 << V_199 ;
if ( V_41 -> V_183 ) {
V_212 |= V_41 -> V_184 << V_202 ;
V_212 |= V_41 -> V_187 << V_204 ;
V_212 |= V_200 ;
} else {
V_212 |= V_41 -> V_190 << V_206 ;
V_212 |= V_41 -> V_42 << V_208 ;
}
return V_212 ;
}
static T_2 F_98 ( struct V_175 * V_41 )
{
T_2 V_212 ;
V_212 = V_41 -> V_176 << V_178 ;
V_212 |= V_41 -> V_179 << V_181 ;
if ( V_41 -> V_183 ) {
V_212 |= V_41 -> V_184 << V_186 ;
V_212 |= V_41 -> V_187 << V_189 ;
V_212 |= V_182 ;
} else {
V_212 |= V_41 -> V_190 << V_192 ;
V_212 |= V_41 -> V_42 << V_194 ;
}
return V_212 ;
}
static inline void F_99 ( struct V_8 * V_20 ,
struct V_175 * V_41 ,
struct V_36 * V_40 )
{
if ( F_71 ( V_209 , & V_20 -> V_87 ) ) {
F_100 ( F_97 ( V_41 ) ,
V_40 -> V_159 + V_213 ) ;
} else {
F_101 ( F_98 ( V_41 ) ,
V_40 -> V_159 + V_213 ) ;
}
}
static inline unsigned int F_102 ( struct V_8 * V_20 )
{
if ( F_71 ( V_209 , & V_20 -> V_87 ) )
return V_214 ;
else
return V_215 ;
}
static struct V_36 * F_103 ( struct V_8 * V_20 ,
T_8 V_41 )
{
struct V_36 * V_40 ;
struct V_216 * V_217 ;
int V_218 = F_102 ( V_20 ) ;
if ( V_20 -> V_77 == V_78 )
V_218 += V_219 ;
V_40 = F_104 ( V_218 , V_49 ) ;
if ( ! V_40 )
return F_105 ( - V_50 ) ;
V_217 = (struct V_216 * ) F_106 ( V_40 , V_213 ) ;
V_217 -> V_158 = F_16 ( V_218 - V_213 ) ;
V_217 -> V_11 = F_16 ( V_20 -> V_13 ) ;
if ( F_71 ( V_209 , & V_20 -> V_87 ) )
F_100 ( V_41 , F_106 ( V_40 , V_210 ) ) ;
else
F_101 ( V_41 , F_106 ( V_40 , V_211 ) ) ;
if ( V_20 -> V_77 == V_78 ) {
T_2 V_77 = F_107 ( 0 , ( T_3 * ) V_40 -> V_159 , V_40 -> V_158 ) ;
F_101 ( V_77 , F_106 ( V_40 , V_219 ) ) ;
}
V_40 -> V_165 = V_166 ;
return V_40 ;
}
static void F_108 ( struct V_8 * V_20 ,
struct V_175 * V_41 )
{
struct V_36 * V_40 ;
T_8 V_220 ;
F_21 ( L_10 , V_20 , V_41 ) ;
if ( ! V_41 -> V_183 )
return;
if ( F_88 ( V_20 ) )
return;
if ( F_109 ( V_221 , & V_20 -> V_222 ) &&
! V_41 -> V_184 )
V_41 -> V_179 = 1 ;
if ( V_41 -> V_187 == V_223 )
F_110 ( V_224 , & V_20 -> V_222 ) ;
else if ( V_41 -> V_187 == V_225 )
F_55 ( V_224 , & V_20 -> V_222 ) ;
if ( V_41 -> V_187 != V_226 ) {
V_20 -> V_227 = V_41 -> V_176 ;
F_73 ( V_20 ) ;
}
F_21 ( L_11 , V_41 -> V_176 ,
V_41 -> V_179 , V_41 -> V_184 , V_41 -> V_187 ) ;
if ( F_71 ( V_209 , & V_20 -> V_87 ) )
V_220 = F_97 ( V_41 ) ;
else
V_220 = F_98 ( V_41 ) ;
V_40 = F_103 ( V_20 , V_220 ) ;
if ( ! F_111 ( V_40 ) )
F_89 ( V_20 , V_40 ) ;
}
static void F_112 ( struct V_8 * V_20 , bool V_184 )
{
struct V_175 V_41 ;
F_21 ( L_12 , V_20 , V_184 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_183 = 1 ;
V_41 . V_184 = V_184 ;
if ( F_71 ( V_228 , & V_20 -> V_222 ) )
V_41 . V_187 = V_225 ;
else
V_41 . V_187 = V_223 ;
V_41 . V_176 = V_20 -> V_229 ;
F_108 ( V_20 , & V_41 ) ;
}
static inline int F_113 ( struct V_8 * V_20 )
{
return ! F_71 ( V_230 , & V_20 -> V_75 ) ;
}
static bool F_114 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_231 * V_160 ;
bool V_232 = false ;
if ( ! V_10 -> V_233 )
return false ;
if ( ! ( V_10 -> V_234 & V_235 ) )
return false ;
F_115 ( & V_236 ) ;
F_3 (hdev, &hci_dev_list, list) {
if ( V_160 -> V_237 != V_238 &&
F_71 ( V_239 , & V_160 -> V_87 ) ) {
V_232 = true ;
break;
}
}
F_116 ( & V_236 ) ;
if ( V_20 -> V_240 == V_241 )
return V_232 ;
return false ;
}
static bool F_117 ( struct V_8 * V_20 )
{
return true ;
}
void F_118 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_242 V_243 ;
V_243 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_243 . V_17 = V_20 -> V_17 ;
V_20 -> V_16 = F_82 ( V_10 ) ;
F_55 ( V_230 , & V_20 -> V_75 ) ;
F_78 ( V_10 , V_20 -> V_16 , V_244 , sizeof( V_243 ) , & V_243 ) ;
}
static void F_119 ( struct V_8 * V_20 , T_3 V_245 )
{
struct V_246 V_243 ;
V_243 . V_14 = F_16 ( V_20 -> V_14 ) ;
V_243 . V_17 = V_20 -> V_17 ;
V_243 . V_245 = V_245 ;
V_20 -> V_16 = F_82 ( V_20 -> V_10 ) ;
F_78 ( V_20 -> V_10 , V_20 -> V_16 , V_247 ,
sizeof( V_243 ) , & V_243 ) ;
}
static void F_120 ( struct V_8 * V_20 )
{
struct V_36 * V_40 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_121 != V_123 )
return;
F_30 ( V_20 ) ;
F_72 ( V_20 ) ;
F_73 ( V_20 ) ;
V_20 -> V_248 = 0 ;
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_40 ) -> V_41 . V_249 )
F_33 ( V_40 ) -> V_41 . V_249 = 1 ;
else
break;
}
V_20 -> V_250 = V_20 -> V_229 ;
F_110 ( V_251 , & V_20 -> V_222 ) ;
F_110 ( V_252 , & V_20 -> V_222 ) ;
F_42 ( & V_20 -> V_126 ) ;
F_42 ( & V_20 -> V_125 ) ;
F_74 ( & V_20 -> V_124 ) ;
V_20 -> V_253 = V_254 ;
V_20 -> V_255 = V_256 ;
F_55 ( V_257 , & V_20 -> V_222 ) ;
}
static void F_121 ( struct V_8 * V_20 )
{
T_3 V_258 = V_20 -> V_258 ;
F_21 ( L_3 , V_20 ) ;
V_20 -> V_168 = V_169 ;
V_20 -> V_258 = V_259 ;
if ( V_20 -> V_121 != V_123 )
return;
switch ( V_258 ) {
case V_260 :
F_122 ( V_20 , NULL , NULL , V_261 ) ;
V_20 -> V_255 = V_262 ;
break;
case V_263 :
V_20 -> V_255 = V_264 ;
break;
}
}
static void F_123 ( struct V_8 * V_20 )
{
V_20 -> V_75 = 0 ;
F_68 ( V_20 ) ;
V_20 -> V_29 = V_60 ;
V_20 -> V_30 -> V_265 ( V_20 ) ;
}
static void F_124 ( struct V_8 * V_20 )
{
if ( F_114 ( V_20 ) ) {
F_21 ( L_13 , V_20 ) ;
F_125 ( V_20 ) ;
} else {
F_118 ( V_20 ) ;
}
}
static void F_126 ( struct V_8 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
if ( V_10 -> V_2 -> type == V_3 ) {
F_123 ( V_20 ) ;
return;
}
if ( V_10 -> V_266 & V_267 ) {
if ( ! ( V_10 -> V_266 & V_268 ) )
return;
if ( F_80 ( V_20 ) &&
F_113 ( V_20 ) ) {
F_124 ( V_20 ) ;
}
} else {
struct V_269 V_243 ;
V_243 . type = F_77 ( V_270 ) ;
V_10 -> V_266 |= V_267 ;
V_10 -> V_271 = F_82 ( V_10 ) ;
F_127 ( & V_10 -> V_272 , V_273 ) ;
F_78 ( V_10 , V_10 -> V_271 , V_274 ,
sizeof( V_243 ) , & V_243 ) ;
}
}
static inline int F_128 ( T_1 V_121 , T_9 V_275 )
{
T_8 V_276 = V_277 ;
if ( ! V_278 )
V_276 |= V_279 | V_280 ;
switch ( V_121 ) {
case V_123 :
return V_279 & V_275 & V_276 ;
case V_127 :
return V_280 & V_275 & V_276 ;
default:
return 0x00 ;
}
}
static void F_76 ( struct V_8 * V_20 , int V_21 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_281 V_243 ;
if ( ! V_10 )
return;
if ( V_20 -> V_121 == V_123 && V_20 -> V_29 == V_60 ) {
F_30 ( V_20 ) ;
F_72 ( V_20 ) ;
F_73 ( V_20 ) ;
}
if ( V_20 -> V_90 == V_97 ) {
F_20 ( V_20 , V_139 ) ;
return;
}
V_243 . V_13 = F_16 ( V_20 -> V_13 ) ;
V_243 . V_14 = F_16 ( V_20 -> V_14 ) ;
F_78 ( V_10 , F_82 ( V_10 ) , V_282 ,
sizeof( V_243 ) , & V_243 ) ;
F_23 ( V_20 , V_139 , V_21 ) ;
}
static void F_129 ( struct V_9 * V_10 )
{
struct V_8 * V_20 , * V_283 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_130 (chan, tmp, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_90 != V_91 ) {
F_47 ( V_20 ) ;
continue;
}
if ( V_20 -> V_29 == V_63 ) {
if ( ! F_80 ( V_20 ) ||
! F_113 ( V_20 ) ) {
F_47 ( V_20 ) ;
continue;
}
if ( ! F_128 ( V_20 -> V_121 , V_10 -> V_275 )
&& F_71 ( V_284 ,
& V_20 -> V_75 ) ) {
F_46 ( V_20 , V_285 ) ;
F_47 ( V_20 ) ;
continue;
}
F_124 ( V_20 ) ;
} else if ( V_20 -> V_29 == V_132 ) {
struct V_133 V_134 ;
char V_286 [ 128 ] ;
V_134 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_134 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( F_80 ( V_20 ) ) {
if ( F_71 ( V_136 , & V_20 -> V_87 ) ) {
V_134 . V_135 = F_77 ( V_287 ) ;
V_134 . V_140 = F_77 ( V_288 ) ;
V_20 -> V_30 -> V_289 ( V_20 ) ;
} else {
F_20 ( V_20 , V_61 ) ;
V_134 . V_135 = F_77 ( V_290 ) ;
V_134 . V_140 = F_77 ( V_141 ) ;
}
} else {
V_134 . V_135 = F_77 ( V_287 ) ;
V_134 . V_140 = F_77 ( V_291 ) ;
}
F_78 ( V_10 , V_20 -> V_16 , V_142 ,
sizeof( V_134 ) , & V_134 ) ;
if ( F_71 ( V_292 , & V_20 -> V_75 ) ||
V_134 . V_135 != V_290 ) {
F_47 ( V_20 ) ;
continue;
}
F_55 ( V_292 , & V_20 -> V_75 ) ;
F_78 ( V_10 , F_82 ( V_10 ) , V_293 ,
F_131 ( V_20 , V_286 ) , V_286 ) ;
V_20 -> V_294 ++ ;
}
F_47 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static struct V_8 * F_132 ( int V_29 , T_2 V_11 ,
T_5 * V_18 ,
T_5 * V_295 )
{
struct V_8 * V_12 , * V_296 = NULL ;
F_115 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_29 && V_12 -> V_29 != V_29 )
continue;
if ( V_12 -> V_14 == V_11 ) {
int V_297 , V_298 ;
int V_299 , V_300 ;
V_297 = ! F_13 ( & V_12 -> V_18 , V_18 ) ;
V_298 = ! F_13 ( & V_12 -> V_295 , V_295 ) ;
if ( V_297 && V_298 ) {
F_116 ( & V_22 ) ;
return V_12 ;
}
V_299 = ! F_13 ( & V_12 -> V_18 , V_301 ) ;
V_300 = ! F_13 ( & V_12 -> V_295 , V_301 ) ;
if ( ( V_297 && V_300 ) || ( V_299 && V_298 ) ||
( V_299 && V_300 ) )
V_296 = V_12 ;
}
}
F_116 ( & V_22 ) ;
return V_296 ;
}
static void F_133 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 , * V_302 ;
T_3 V_303 ;
F_21 ( L_15 ) ;
V_302 = F_132 ( V_129 , V_94 ,
& V_2 -> V_18 , & V_2 -> V_295 ) ;
if ( ! V_302 )
return;
if ( F_2 ( V_10 , V_94 ) )
return;
V_303 = F_1 ( V_2 , V_2 -> V_303 ) ;
if ( F_134 ( V_2 -> V_160 , & V_2 -> V_295 , V_303 ) )
return;
F_7 ( V_302 ) ;
V_20 = V_302 -> V_30 -> V_304 ( V_302 ) ;
if ( ! V_20 )
goto V_305;
V_20 -> V_13 = V_94 ;
F_135 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
F_135 ( & V_20 -> V_295 , & V_2 -> V_295 ) ;
V_20 -> V_306 = F_1 ( V_2 , V_2 -> V_306 ) ;
V_20 -> V_303 = V_303 ;
F_63 ( V_10 , V_20 ) ;
V_305:
F_47 ( V_302 ) ;
}
static void F_136 ( struct V_9 * V_10 )
{
struct V_8 * V_20 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_21 ( L_14 , V_10 ) ;
if ( V_2 -> V_307 && V_2 -> type == V_3 )
F_137 ( V_2 , V_2 -> V_308 ) ;
F_6 ( & V_10 -> V_15 ) ;
if ( V_2 -> type == V_3 )
F_133 ( V_10 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
if ( V_20 -> V_90 == V_97 ) {
F_47 ( V_20 ) ;
continue;
}
if ( V_2 -> type == V_3 ) {
if ( F_137 ( V_2 , V_20 -> V_64 ) )
F_123 ( V_20 ) ;
} else if ( V_20 -> V_90 != V_91 ) {
F_123 ( V_20 ) ;
} else if ( V_20 -> V_29 == V_63 ) {
F_126 ( V_20 ) ;
}
F_47 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_138 ( struct V_9 * V_10 , int V_21 )
{
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( F_71 ( V_309 , & V_20 -> V_87 ) )
F_24 ( V_20 , V_21 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static void F_139 ( struct V_56 * V_57 )
{
struct V_9 * V_10 = F_45 ( V_57 , struct V_9 ,
V_272 . V_57 ) ;
V_10 -> V_266 |= V_268 ;
V_10 -> V_271 = 0 ;
F_129 ( V_10 ) ;
}
int F_140 ( struct V_9 * V_10 , struct V_310 * V_311 )
{
struct V_231 * V_160 = V_10 -> V_2 -> V_160 ;
int V_312 ;
F_141 ( V_160 ) ;
if ( V_311 -> V_48 . V_313 || V_311 -> V_48 . V_55 ) {
V_312 = - V_26 ;
goto V_314;
}
if ( ! V_10 -> V_167 ) {
V_312 = - V_315 ;
goto V_314;
}
V_312 = V_311 -> V_316 ( V_10 , V_311 ) ;
if ( V_312 )
goto V_314;
F_52 ( & V_311 -> V_48 , & V_10 -> V_317 ) ;
V_312 = 0 ;
V_314:
F_142 ( V_160 ) ;
return V_312 ;
}
void F_143 ( struct V_9 * V_10 , struct V_310 * V_311 )
{
struct V_231 * V_160 = V_10 -> V_2 -> V_160 ;
F_141 ( V_160 ) ;
if ( ! V_311 -> V_48 . V_313 || ! V_311 -> V_48 . V_55 )
goto V_314;
F_57 ( & V_311 -> V_48 ) ;
V_311 -> V_48 . V_313 = NULL ;
V_311 -> V_48 . V_55 = NULL ;
V_311 -> remove ( V_10 , V_311 ) ;
V_314:
F_142 ( V_160 ) ;
}
static void F_144 ( struct V_9 * V_10 )
{
struct V_310 * V_311 ;
while ( ! F_145 ( & V_10 -> V_317 ) ) {
V_311 = F_146 ( & V_10 -> V_317 , struct V_310 , V_48 ) ;
F_57 ( & V_311 -> V_48 ) ;
V_311 -> V_48 . V_313 = NULL ;
V_311 -> V_48 . V_55 = NULL ;
V_311 -> remove ( V_10 , V_311 ) ;
}
}
static void F_147 ( struct V_1 * V_2 , int V_21 )
{
struct V_9 * V_10 = V_2 -> V_318 ;
struct V_8 * V_20 , * V_319 ;
if ( ! V_10 )
return;
F_21 ( L_16 , V_2 , V_10 , V_21 ) ;
F_90 ( V_10 -> V_320 ) ;
F_144 ( V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_130 (chan, l, &conn->chan_l, list) {
F_58 ( V_20 ) ;
F_7 ( V_20 ) ;
F_67 ( V_20 , V_21 ) ;
F_47 ( V_20 ) ;
V_20 -> V_30 -> V_67 ( V_20 ) ;
F_48 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
F_148 ( V_10 -> V_167 ) ;
if ( V_10 -> V_266 & V_267 )
F_149 ( & V_10 -> V_272 ) ;
if ( F_109 ( V_321 , & V_2 -> V_87 ) ) {
F_149 ( & V_10 -> V_322 ) ;
F_150 ( V_10 ) ;
}
V_2 -> V_318 = NULL ;
V_10 -> V_167 = NULL ;
F_151 ( V_10 ) ;
}
static void F_152 ( struct V_56 * V_57 )
{
struct V_9 * V_10 = F_45 ( V_57 , struct V_9 ,
V_322 . V_57 ) ;
F_21 ( L_14 , V_10 ) ;
if ( F_109 ( V_321 , & V_10 -> V_2 -> V_87 ) ) {
F_150 ( V_10 ) ;
F_147 ( V_10 -> V_2 , V_66 ) ;
}
}
static struct V_9 * F_153 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_318 ;
struct V_119 * V_167 ;
if ( V_10 )
return V_10 ;
V_167 = F_154 ( V_2 ) ;
if ( ! V_167 )
return NULL ;
V_10 = F_50 ( sizeof( struct V_9 ) , V_49 ) ;
if ( ! V_10 ) {
F_148 ( V_167 ) ;
return NULL ;
}
F_54 ( & V_10 -> V_323 ) ;
V_2 -> V_318 = V_10 ;
V_10 -> V_2 = V_2 ;
F_155 ( V_10 -> V_2 ) ;
V_10 -> V_167 = V_167 ;
F_21 ( L_17 , V_2 , V_10 , V_167 ) ;
switch ( V_2 -> type ) {
case V_3 :
if ( V_2 -> V_160 -> V_324 ) {
V_10 -> V_325 = V_2 -> V_160 -> V_324 ;
break;
}
default:
V_10 -> V_325 = V_2 -> V_160 -> V_326 ;
break;
}
V_10 -> V_275 = 0 ;
if ( V_2 -> type == V_130 )
V_10 -> V_233 = F_71 ( V_327 ,
& V_2 -> V_160 -> V_328 ) ;
F_156 ( & V_10 -> V_69 ) ;
F_51 ( & V_10 -> V_15 ) ;
F_157 ( & V_10 -> V_114 ) ;
F_157 ( & V_10 -> V_317 ) ;
if ( V_2 -> type == V_3 )
F_53 ( & V_10 -> V_322 , F_152 ) ;
else
F_53 ( & V_10 -> V_272 , F_139 ) ;
V_10 -> V_88 = V_89 ;
return V_10 ;
}
static void F_158 ( struct V_73 * V_323 )
{
struct V_9 * V_10 = F_45 ( V_323 , struct V_9 , V_323 ) ;
F_159 ( V_10 -> V_2 ) ;
F_38 ( V_10 ) ;
}
void F_160 ( struct V_9 * V_10 )
{
F_60 ( & V_10 -> V_323 ) ;
}
void F_151 ( struct V_9 * V_10 )
{
F_61 ( & V_10 -> V_323 , F_158 ) ;
}
static struct V_8 * F_161 ( int V_29 , T_4 V_17 ,
T_5 * V_18 ,
T_5 * V_295 )
{
struct V_8 * V_12 , * V_296 = NULL ;
F_115 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_29 && V_12 -> V_29 != V_29 )
continue;
if ( V_12 -> V_17 == V_17 ) {
int V_297 , V_298 ;
int V_299 , V_300 ;
V_297 = ! F_13 ( & V_12 -> V_18 , V_18 ) ;
V_298 = ! F_13 ( & V_12 -> V_295 , V_295 ) ;
if ( V_297 && V_298 ) {
F_116 ( & V_22 ) ;
return V_12 ;
}
V_299 = ! F_13 ( & V_12 -> V_18 , V_301 ) ;
V_300 = ! F_13 ( & V_12 -> V_295 , V_301 ) ;
if ( ( V_297 && V_300 ) || ( V_299 && V_298 ) ||
( V_299 && V_300 ) )
V_296 = V_12 ;
}
}
F_116 ( & V_22 ) ;
return V_296 ;
}
int F_162 ( struct V_8 * V_20 , T_4 V_17 , T_2 V_11 ,
T_5 * V_295 , T_3 V_303 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_231 * V_160 ;
T_1 V_154 ;
int V_21 ;
F_21 ( L_18 , & V_20 -> V_18 , V_295 ,
V_303 , F_64 ( V_17 ) ) ;
V_160 = F_163 ( V_295 , & V_20 -> V_18 ) ;
if ( ! V_160 )
return - V_329 ;
F_141 ( V_160 ) ;
F_7 ( V_20 ) ;
if ( ( F_64 ( V_17 ) & 0x0101 ) != 0x0001 && ! V_11 &&
V_20 -> V_90 != V_143 ) {
V_21 = - V_26 ;
goto V_24;
}
if ( V_20 -> V_90 == V_91 && ! ( V_17 || V_11 ) ) {
V_21 = - V_26 ;
goto V_24;
}
switch ( V_20 -> V_121 ) {
case V_122 :
break;
case V_123 :
case V_127 :
if ( ! V_278 )
break;
default:
V_21 = - V_330 ;
goto V_24;
}
switch ( V_20 -> V_29 ) {
case V_63 :
case V_132 :
case V_61 :
V_21 = 0 ;
goto V_24;
case V_60 :
V_21 = - V_331 ;
goto V_24;
case V_72 :
case V_332 :
break;
default:
V_21 = - V_333 ;
goto V_24;
}
F_135 ( & V_20 -> V_295 , V_295 ) ;
V_20 -> V_303 = V_303 ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_11 ;
V_154 = F_79 ( V_20 ) ;
if ( F_164 ( V_303 ) )
V_2 = F_165 ( V_160 , V_3 , V_295 , V_303 ,
V_20 -> V_64 , V_154 ) ;
else
V_2 = F_165 ( V_160 , V_130 , V_295 , V_303 ,
V_20 -> V_64 , V_154 ) ;
if ( F_111 ( V_2 ) ) {
V_21 = F_166 ( V_2 ) ;
goto V_24;
}
V_10 = F_153 ( V_2 ) ;
if ( ! V_10 ) {
F_69 ( V_2 ) ;
V_21 = - V_50 ;
goto V_24;
}
if ( V_11 && F_2 ( V_10 , V_11 ) ) {
F_69 ( V_2 ) ;
V_21 = - V_334 ;
goto V_24;
}
F_135 ( & V_20 -> V_18 , & V_2 -> V_18 ) ;
V_20 -> V_306 = F_1 ( V_2 , V_2 -> V_306 ) ;
F_47 ( V_20 ) ;
F_66 ( V_10 , V_20 ) ;
F_7 ( V_20 ) ;
F_69 ( V_2 ) ;
F_20 ( V_20 , V_63 ) ;
F_75 ( V_20 , V_20 -> V_30 -> V_131 ( V_20 ) ) ;
if ( V_2 -> V_29 == V_60 ) {
if ( V_20 -> V_90 != V_91 ) {
F_68 ( V_20 ) ;
if ( F_80 ( V_20 ) )
F_20 ( V_20 , V_60 ) ;
} else
F_126 ( V_20 ) ;
}
V_21 = 0 ;
V_24:
F_47 ( V_20 ) ;
F_142 ( V_160 ) ;
F_167 ( V_160 ) ;
return V_21 ;
}
static void F_168 ( struct V_56 * V_57 )
{
struct V_8 * V_20 = F_45 ( V_57 , struct V_8 ,
V_32 . V_57 ) ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
if ( ! V_20 -> V_10 ) {
F_47 ( V_20 ) ;
F_48 ( V_20 ) ;
return;
}
F_122 ( V_20 , NULL , NULL , V_335 ) ;
F_47 ( V_20 ) ;
F_48 ( V_20 ) ;
}
static void F_169 ( struct V_56 * V_57 )
{
struct V_8 * V_20 = F_45 ( V_57 , struct V_8 ,
V_34 . V_57 ) ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
if ( ! V_20 -> V_10 ) {
F_47 ( V_20 ) ;
F_48 ( V_20 ) ;
return;
}
F_122 ( V_20 , NULL , NULL , V_336 ) ;
F_47 ( V_20 ) ;
F_48 ( V_20 ) ;
}
static void F_170 ( struct V_8 * V_20 ,
struct V_37 * V_337 )
{
struct V_36 * V_40 ;
struct V_175 * V_41 ;
F_21 ( L_19 , V_20 , V_337 ) ;
if ( F_88 ( V_20 ) )
return;
F_171 ( V_337 , & V_20 -> V_128 ) ;
while ( ! F_172 ( & V_20 -> V_128 ) ) {
V_40 = F_173 ( & V_20 -> V_128 ) ;
F_33 ( V_40 ) -> V_41 . V_249 = 1 ;
V_41 = & F_33 ( V_40 ) -> V_41 ;
V_41 -> V_176 = 0 ;
V_41 -> V_42 = V_20 -> V_338 ;
F_99 ( V_20 , V_41 , V_40 ) ;
if ( V_20 -> V_77 == V_78 ) {
T_2 V_77 = F_107 ( 0 , ( T_3 * ) V_40 -> V_159 , V_40 -> V_158 ) ;
F_101 ( V_77 , F_106 ( V_40 , V_219 ) ) ;
}
F_89 ( V_20 , V_40 ) ;
F_21 ( L_20 , V_41 -> V_42 ) ;
V_20 -> V_338 = F_174 ( V_20 , V_20 -> V_338 ) ;
V_20 -> V_339 ++ ;
}
}
static int F_175 ( struct V_8 * V_20 )
{
struct V_36 * V_40 , * V_340 ;
struct V_175 * V_41 ;
int V_341 = 0 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_29 != V_60 )
return - V_342 ;
if ( F_71 ( V_257 , & V_20 -> V_222 ) )
return 0 ;
if ( F_88 ( V_20 ) )
return 0 ;
while ( V_20 -> V_343 &&
V_20 -> V_344 < V_20 -> V_345 &&
V_20 -> V_253 == V_254 ) {
V_40 = V_20 -> V_343 ;
F_33 ( V_40 ) -> V_41 . V_249 = 1 ;
V_41 = & F_33 ( V_40 ) -> V_41 ;
if ( F_109 ( V_221 , & V_20 -> V_222 ) )
V_41 -> V_179 = 1 ;
V_41 -> V_176 = V_20 -> V_229 ;
V_20 -> V_227 = V_20 -> V_229 ;
V_41 -> V_42 = V_20 -> V_338 ;
F_99 ( V_20 , V_41 , V_40 ) ;
if ( V_20 -> V_77 == V_78 ) {
T_2 V_77 = F_107 ( 0 , ( T_3 * ) V_40 -> V_159 , V_40 -> V_158 ) ;
F_101 ( V_77 , F_106 ( V_40 , V_219 ) ) ;
}
V_340 = F_176 ( V_40 , V_49 ) ;
if ( ! V_340 )
break;
F_25 ( V_20 ) ;
V_20 -> V_338 = F_174 ( V_20 , V_20 -> V_338 ) ;
V_20 -> V_344 ++ ;
V_20 -> V_339 ++ ;
V_341 ++ ;
if ( F_177 ( & V_20 -> V_128 , V_40 ) )
V_20 -> V_343 = NULL ;
else
V_20 -> V_343 = F_178 ( & V_20 -> V_128 , V_40 ) ;
F_89 ( V_20 , V_340 ) ;
F_21 ( L_20 , V_41 -> V_42 ) ;
}
F_21 ( L_21 , V_341 ,
V_20 -> V_344 , F_179 ( & V_20 -> V_128 ) ) ;
return V_341 ;
}
static void F_180 ( struct V_8 * V_20 )
{
struct V_175 V_41 ;
struct V_36 * V_40 ;
struct V_36 * V_340 ;
T_2 V_39 ;
F_21 ( L_3 , V_20 ) ;
if ( F_71 ( V_257 , & V_20 -> V_222 ) )
return;
if ( F_88 ( V_20 ) )
return;
while ( V_20 -> V_126 . V_38 != V_52 ) {
V_39 = F_41 ( & V_20 -> V_126 ) ;
V_40 = F_31 ( & V_20 -> V_128 , V_39 ) ;
if ( ! V_40 ) {
F_21 ( L_22 ,
V_39 ) ;
continue;
}
F_33 ( V_40 ) -> V_41 . V_249 ++ ;
V_41 = F_33 ( V_40 ) -> V_41 ;
if ( V_20 -> V_79 != 0 &&
F_33 ( V_40 ) -> V_41 . V_249 > V_20 -> V_79 ) {
F_21 ( L_23 , V_20 -> V_79 ) ;
F_76 ( V_20 , V_285 ) ;
F_42 ( & V_20 -> V_126 ) ;
break;
}
V_41 . V_176 = V_20 -> V_229 ;
if ( F_109 ( V_221 , & V_20 -> V_222 ) )
V_41 . V_179 = 1 ;
else
V_41 . V_179 = 0 ;
if ( F_181 ( V_40 ) ) {
V_340 = F_182 ( V_40 , V_49 ) ;
} else {
V_340 = F_176 ( V_40 , V_49 ) ;
}
if ( ! V_340 ) {
F_42 ( & V_20 -> V_126 ) ;
break;
}
if ( F_71 ( V_209 , & V_20 -> V_87 ) ) {
F_100 ( F_97 ( & V_41 ) ,
V_340 -> V_159 + V_213 ) ;
} else {
F_101 ( F_98 ( & V_41 ) ,
V_340 -> V_159 + V_213 ) ;
}
if ( V_20 -> V_77 == V_78 ) {
T_2 V_77 = F_107 ( 0 , ( T_3 * ) V_340 -> V_159 , V_340 -> V_158 ) ;
F_101 ( V_77 , F_106 ( V_340 ,
V_219 ) ) ;
}
F_89 ( V_20 , V_340 ) ;
F_21 ( L_24 , V_41 . V_42 ) ;
V_20 -> V_227 = V_20 -> V_229 ;
}
}
static void F_183 ( struct V_8 * V_20 ,
struct V_175 * V_41 )
{
F_21 ( L_10 , V_20 , V_41 ) ;
F_43 ( & V_20 -> V_126 , V_41 -> V_176 ) ;
F_180 ( V_20 ) ;
}
static void F_184 ( struct V_8 * V_20 ,
struct V_175 * V_41 )
{
struct V_36 * V_40 ;
F_21 ( L_10 , V_20 , V_41 ) ;
if ( V_41 -> V_184 )
F_55 ( V_221 , & V_20 -> V_222 ) ;
F_42 ( & V_20 -> V_126 ) ;
if ( F_71 ( V_257 , & V_20 -> V_222 ) )
return;
if ( V_20 -> V_344 ) {
F_32 (&chan->tx_q, skb) {
if ( F_33 ( V_40 ) -> V_41 . V_42 == V_41 -> V_176 ||
V_40 == V_20 -> V_343 )
break;
}
F_185 (&chan->tx_q, skb) {
if ( V_40 == V_20 -> V_343 )
break;
F_43 ( & V_20 -> V_126 ,
F_33 ( V_40 ) -> V_41 . V_42 ) ;
}
F_180 ( V_20 ) ;
}
}
static void F_186 ( struct V_8 * V_20 )
{
struct V_175 V_41 ;
T_2 V_346 = F_187 ( V_20 , V_20 -> V_229 ,
V_20 -> V_227 ) ;
int V_347 ;
F_21 ( L_25 ,
V_20 , V_20 -> V_227 , V_20 -> V_229 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_183 = 1 ;
if ( F_71 ( V_228 , & V_20 -> V_222 ) &&
V_20 -> V_255 == V_348 ) {
F_73 ( V_20 ) ;
V_41 . V_187 = V_225 ;
V_41 . V_176 = V_20 -> V_229 ;
F_108 ( V_20 , & V_41 ) ;
} else {
if ( ! F_71 ( V_257 , & V_20 -> V_222 ) ) {
F_175 ( V_20 ) ;
if ( V_20 -> V_229 == V_20 -> V_227 )
V_346 = 0 ;
}
V_347 = V_20 -> V_84 ;
V_347 += V_347 << 1 ;
V_347 >>= 2 ;
F_21 ( L_26 , V_346 ,
V_347 ) ;
if ( V_346 >= V_347 ) {
F_73 ( V_20 ) ;
V_41 . V_187 = V_223 ;
V_41 . V_176 = V_20 -> V_229 ;
F_108 ( V_20 , & V_41 ) ;
V_346 = 0 ;
}
if ( V_346 )
F_188 ( V_20 ) ;
}
}
static inline int F_189 ( struct V_8 * V_20 ,
struct V_349 * V_350 , int V_158 ,
int V_351 , struct V_36 * V_40 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_36 * * V_352 ;
int V_341 = 0 ;
if ( F_190 ( F_106 ( V_40 , V_351 ) , V_350 -> V_353 , V_351 ) )
return - V_354 ;
V_341 += V_351 ;
V_158 -= V_351 ;
V_352 = & F_191 ( V_40 ) -> V_355 ;
while ( V_158 ) {
struct V_36 * V_283 ;
V_351 = F_192 (unsigned int, conn->mtu, len) ;
V_283 = V_20 -> V_30 -> V_356 ( V_20 , V_351 ,
V_350 -> V_357 & V_358 ) ;
if ( F_111 ( V_283 ) )
return F_166 ( V_283 ) ;
* V_352 = V_283 ;
if ( F_190 ( F_106 ( * V_352 , V_351 ) , V_350 -> V_353 , V_351 ) )
return - V_354 ;
( * V_352 ) -> V_165 = V_40 -> V_165 ;
V_341 += V_351 ;
V_158 -= V_351 ;
V_40 -> V_158 += ( * V_352 ) -> V_158 ;
V_40 -> V_359 += ( * V_352 ) -> V_158 ;
V_352 = & ( * V_352 ) -> V_313 ;
}
return V_341 ;
}
static struct V_36 * F_193 ( struct V_8 * V_20 ,
struct V_349 * V_350 , T_7 V_158 ,
T_8 V_165 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_36 * V_40 ;
int V_21 , V_351 , V_218 = V_213 + V_360 ;
struct V_216 * V_217 ;
F_21 ( L_27 , V_20 ,
F_64 ( V_20 -> V_17 ) , V_158 , V_165 ) ;
V_351 = F_192 (unsigned int, (conn->mtu - hlen), len) ;
V_40 = V_20 -> V_30 -> V_356 ( V_20 , V_351 + V_218 ,
V_350 -> V_357 & V_358 ) ;
if ( F_111 ( V_40 ) )
return V_40 ;
V_40 -> V_165 = V_165 ;
V_217 = (struct V_216 * ) F_106 ( V_40 , V_213 ) ;
V_217 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_217 -> V_158 = F_16 ( V_158 + V_360 ) ;
F_194 ( V_20 -> V_17 , ( T_4 * ) F_106 ( V_40 , V_360 ) ) ;
V_21 = F_189 ( V_20 , V_350 , V_158 , V_351 , V_40 ) ;
if ( F_195 ( V_21 < 0 ) ) {
F_90 ( V_40 ) ;
return F_105 ( V_21 ) ;
}
return V_40 ;
}
static struct V_36 * F_196 ( struct V_8 * V_20 ,
struct V_349 * V_350 , T_7 V_158 ,
T_8 V_165 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_36 * V_40 ;
int V_21 , V_351 ;
struct V_216 * V_217 ;
F_21 ( L_28 , V_20 , V_158 ) ;
V_351 = F_192 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_40 = V_20 -> V_30 -> V_356 ( V_20 , V_351 + V_213 ,
V_350 -> V_357 & V_358 ) ;
if ( F_111 ( V_40 ) )
return V_40 ;
V_40 -> V_165 = V_165 ;
V_217 = (struct V_216 * ) F_106 ( V_40 , V_213 ) ;
V_217 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_217 -> V_158 = F_16 ( V_158 ) ;
V_21 = F_189 ( V_20 , V_350 , V_158 , V_351 , V_40 ) ;
if ( F_195 ( V_21 < 0 ) ) {
F_90 ( V_40 ) ;
return F_105 ( V_21 ) ;
}
return V_40 ;
}
static struct V_36 * F_197 ( struct V_8 * V_20 ,
struct V_349 * V_350 , T_7 V_158 ,
T_2 V_361 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_36 * V_40 ;
int V_21 , V_351 , V_218 ;
struct V_216 * V_217 ;
F_21 ( L_28 , V_20 , V_158 ) ;
if ( ! V_10 )
return F_105 ( - V_342 ) ;
V_218 = F_102 ( V_20 ) ;
if ( V_361 )
V_218 += V_362 ;
if ( V_20 -> V_77 == V_78 )
V_218 += V_219 ;
V_351 = F_192 (unsigned int, (conn->mtu - hlen), len) ;
V_40 = V_20 -> V_30 -> V_356 ( V_20 , V_351 + V_218 ,
V_350 -> V_357 & V_358 ) ;
if ( F_111 ( V_40 ) )
return V_40 ;
V_217 = (struct V_216 * ) F_106 ( V_40 , V_213 ) ;
V_217 -> V_11 = F_16 ( V_20 -> V_13 ) ;
V_217 -> V_158 = F_16 ( V_158 + ( V_218 - V_213 ) ) ;
if ( F_71 ( V_209 , & V_20 -> V_87 ) )
F_100 ( 0 , F_106 ( V_40 , V_210 ) ) ;
else
F_101 ( 0 , F_106 ( V_40 , V_211 ) ) ;
if ( V_361 )
F_101 ( V_361 , F_106 ( V_40 , V_362 ) ) ;
V_21 = F_189 ( V_20 , V_350 , V_158 , V_351 , V_40 ) ;
if ( F_195 ( V_21 < 0 ) ) {
F_90 ( V_40 ) ;
return F_105 ( V_21 ) ;
}
F_33 ( V_40 ) -> V_41 . V_77 = V_20 -> V_77 ;
F_33 ( V_40 ) -> V_41 . V_249 = 0 ;
return V_40 ;
}
static int F_198 ( struct V_8 * V_20 ,
struct V_37 * V_363 ,
struct V_349 * V_350 , T_7 V_158 )
{
struct V_36 * V_40 ;
T_2 V_364 ;
T_7 V_365 ;
T_3 V_190 ;
F_21 ( L_29 , V_20 , V_350 , V_158 ) ;
V_365 = V_20 -> V_10 -> V_325 ;
if ( ! V_20 -> V_171 )
V_365 = F_192 ( T_7 , V_365 , V_366 ) ;
if ( V_20 -> V_77 )
V_365 -= V_219 ;
V_365 -= F_102 ( V_20 ) ;
V_365 = F_192 ( T_7 , V_365 , V_20 -> V_367 ) ;
if ( V_158 <= V_365 ) {
V_190 = V_368 ;
V_364 = 0 ;
V_365 = V_158 ;
} else {
V_190 = V_369 ;
V_364 = V_158 ;
V_365 -= V_362 ;
}
while ( V_158 > 0 ) {
V_40 = F_197 ( V_20 , V_350 , V_365 , V_364 ) ;
if ( F_111 ( V_40 ) ) {
F_199 ( V_363 ) ;
return F_166 ( V_40 ) ;
}
F_33 ( V_40 ) -> V_41 . V_190 = V_190 ;
F_200 ( V_363 , V_40 ) ;
V_158 -= V_365 ;
if ( V_364 ) {
V_364 = 0 ;
V_365 += V_362 ;
}
if ( V_158 <= V_365 ) {
V_190 = V_370 ;
V_365 = V_158 ;
} else {
V_190 = V_371 ;
}
}
return 0 ;
}
int F_201 ( struct V_8 * V_20 , struct V_349 * V_350 , T_7 V_158 ,
T_8 V_165 )
{
struct V_36 * V_40 ;
int V_21 ;
struct V_37 V_363 ;
if ( ! V_20 -> V_10 )
return - V_342 ;
if ( V_20 -> V_90 == V_95 ) {
V_40 = F_193 ( V_20 , V_350 , V_158 , V_165 ) ;
if ( F_111 ( V_40 ) )
return F_166 ( V_40 ) ;
F_89 ( V_20 , V_40 ) ;
return V_158 ;
}
switch ( V_20 -> V_121 ) {
case V_122 :
if ( V_158 > V_20 -> V_92 )
return - V_372 ;
V_40 = F_196 ( V_20 , V_350 , V_158 , V_165 ) ;
if ( F_111 ( V_40 ) )
return F_166 ( V_40 ) ;
F_89 ( V_20 , V_40 ) ;
V_21 = V_158 ;
break;
case V_123 :
case V_127 :
if ( V_158 > V_20 -> V_92 ) {
V_21 = - V_372 ;
break;
}
F_202 ( & V_363 ) ;
V_21 = F_198 ( V_20 , & V_363 , V_350 , V_158 ) ;
if ( V_20 -> V_29 != V_60 ) {
F_199 ( & V_363 ) ;
V_21 = - V_342 ;
}
if ( V_21 )
break;
if ( V_20 -> V_121 == V_123 )
F_122 ( V_20 , NULL , & V_363 , V_373 ) ;
else
F_170 ( V_20 , & V_363 ) ;
V_21 = V_158 ;
F_199 ( & V_363 ) ;
break;
default:
F_21 ( L_30 , V_20 -> V_121 ) ;
V_21 = - V_333 ;
}
return V_21 ;
}
static void F_203 ( struct V_8 * V_20 , T_2 V_42 )
{
struct V_175 V_41 ;
T_2 V_39 ;
F_21 ( L_31 , V_20 , V_42 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_183 = 1 ;
V_41 . V_187 = V_226 ;
for ( V_39 = V_20 -> V_250 ; V_39 != V_42 ;
V_39 = F_174 ( V_20 , V_39 ) ) {
if ( ! F_31 ( & V_20 -> V_124 , V_39 ) ) {
V_41 . V_176 = V_39 ;
F_108 ( V_20 , & V_41 ) ;
F_43 ( & V_20 -> V_125 , V_39 ) ;
}
}
V_20 -> V_250 = F_174 ( V_20 , V_42 ) ;
}
static void F_204 ( struct V_8 * V_20 )
{
struct V_175 V_41 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_125 . V_53 == V_52 )
return;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_183 = 1 ;
V_41 . V_187 = V_226 ;
V_41 . V_176 = V_20 -> V_125 . V_53 ;
F_108 ( V_20 , & V_41 ) ;
}
static void F_205 ( struct V_8 * V_20 , T_2 V_42 )
{
struct V_175 V_41 ;
T_2 V_374 ;
T_2 V_39 ;
F_21 ( L_31 , V_20 , V_42 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_183 = 1 ;
V_41 . V_187 = V_226 ;
V_374 = V_20 -> V_125 . V_38 ;
do {
V_39 = F_41 ( & V_20 -> V_125 ) ;
if ( V_39 == V_42 || V_39 == V_52 )
break;
V_41 . V_176 = V_39 ;
F_108 ( V_20 , & V_41 ) ;
F_43 ( & V_20 -> V_125 , V_39 ) ;
} while ( V_20 -> V_125 . V_38 != V_374 );
}
static void F_206 ( struct V_8 * V_20 , T_2 V_176 )
{
struct V_36 * V_375 ;
T_2 V_376 ;
F_21 ( L_32 , V_20 , V_176 ) ;
if ( V_20 -> V_344 == 0 || V_176 == V_20 -> V_377 )
return;
F_21 ( L_33 ,
V_20 -> V_377 , V_20 -> V_344 ) ;
for ( V_376 = V_20 -> V_377 ; V_376 != V_176 ;
V_376 = F_174 ( V_20 , V_376 ) ) {
V_375 = F_31 ( & V_20 -> V_128 , V_376 ) ;
if ( V_375 ) {
F_207 ( V_375 , & V_20 -> V_128 ) ;
F_90 ( V_375 ) ;
V_20 -> V_344 -- ;
}
}
V_20 -> V_377 = V_176 ;
if ( V_20 -> V_344 == 0 )
F_30 ( V_20 ) ;
F_21 ( L_34 , V_20 -> V_344 ) ;
}
static void F_208 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_250 = V_20 -> V_229 ;
F_42 ( & V_20 -> V_125 ) ;
F_74 ( & V_20 -> V_124 ) ;
V_20 -> V_255 = V_348 ;
}
static void F_209 ( struct V_8 * V_20 ,
struct V_175 * V_41 ,
struct V_37 * V_337 , T_3 V_378 )
{
F_21 ( L_35 , V_20 , V_41 , V_337 ,
V_378 ) ;
switch ( V_378 ) {
case V_373 :
if ( V_20 -> V_343 == NULL )
V_20 -> V_343 = F_210 ( V_337 ) ;
F_171 ( V_337 , & V_20 -> V_128 ) ;
F_175 ( V_20 ) ;
break;
case V_379 :
F_21 ( L_36 ) ;
F_55 ( V_228 , & V_20 -> V_222 ) ;
if ( V_20 -> V_255 == V_380 ) {
F_208 ( V_20 ) ;
}
F_186 ( V_20 ) ;
break;
case V_381 :
F_21 ( L_37 ) ;
F_110 ( V_228 , & V_20 -> V_222 ) ;
if ( F_71 ( V_224 , & V_20 -> V_222 ) ) {
struct V_175 V_382 ;
memset ( & V_382 , 0 , sizeof( V_382 ) ) ;
V_382 . V_183 = 1 ;
V_382 . V_187 = V_223 ;
V_382 . V_184 = 1 ;
V_382 . V_176 = V_20 -> V_229 ;
F_108 ( V_20 , & V_382 ) ;
V_20 -> V_248 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_253 = V_383 ;
}
break;
case V_384 :
F_206 ( V_20 , V_41 -> V_176 ) ;
break;
case V_261 :
F_112 ( V_20 , 1 ) ;
V_20 -> V_248 = 1 ;
F_29 ( V_20 ) ;
F_73 ( V_20 ) ;
V_20 -> V_253 = V_383 ;
break;
case V_336 :
F_112 ( V_20 , 1 ) ;
V_20 -> V_248 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_253 = V_383 ;
break;
case V_385 :
break;
default:
break;
}
}
static void F_211 ( struct V_8 * V_20 ,
struct V_175 * V_41 ,
struct V_37 * V_337 , T_3 V_378 )
{
F_21 ( L_35 , V_20 , V_41 , V_337 ,
V_378 ) ;
switch ( V_378 ) {
case V_373 :
if ( V_20 -> V_343 == NULL )
V_20 -> V_343 = F_210 ( V_337 ) ;
F_171 ( V_337 , & V_20 -> V_128 ) ;
break;
case V_379 :
F_21 ( L_36 ) ;
F_55 ( V_228 , & V_20 -> V_222 ) ;
if ( V_20 -> V_255 == V_380 ) {
F_208 ( V_20 ) ;
}
F_186 ( V_20 ) ;
break;
case V_381 :
F_21 ( L_37 ) ;
F_110 ( V_228 , & V_20 -> V_222 ) ;
if ( F_71 ( V_224 , & V_20 -> V_222 ) ) {
struct V_175 V_382 ;
memset ( & V_382 , 0 , sizeof( V_382 ) ) ;
V_382 . V_183 = 1 ;
V_382 . V_187 = V_223 ;
V_382 . V_184 = 1 ;
V_382 . V_176 = V_20 -> V_229 ;
F_108 ( V_20 , & V_382 ) ;
V_20 -> V_248 = 1 ;
F_29 ( V_20 ) ;
V_20 -> V_253 = V_383 ;
}
break;
case V_384 :
F_206 ( V_20 , V_41 -> V_176 ) ;
case V_385 :
if ( V_41 && V_41 -> V_179 ) {
F_72 ( V_20 ) ;
if ( V_20 -> V_344 > 0 )
F_25 ( V_20 ) ;
V_20 -> V_248 = 0 ;
V_20 -> V_253 = V_254 ;
F_21 ( L_38 , V_20 -> V_253 ) ;
}
break;
case V_261 :
break;
case V_335 :
if ( V_20 -> V_79 == 0 || V_20 -> V_248 < V_20 -> V_79 ) {
F_112 ( V_20 , 1 ) ;
F_29 ( V_20 ) ;
V_20 -> V_248 ++ ;
} else {
F_76 ( V_20 , V_386 ) ;
}
break;
default:
break;
}
}
static void F_122 ( struct V_8 * V_20 , struct V_175 * V_41 ,
struct V_37 * V_337 , T_3 V_378 )
{
F_21 ( L_39 ,
V_20 , V_41 , V_337 , V_378 , V_20 -> V_253 ) ;
switch ( V_20 -> V_253 ) {
case V_254 :
F_209 ( V_20 , V_41 , V_337 , V_378 ) ;
break;
case V_383 :
F_211 ( V_20 , V_41 , V_337 , V_378 ) ;
break;
default:
break;
}
}
static void F_212 ( struct V_8 * V_20 ,
struct V_175 * V_41 )
{
F_21 ( L_10 , V_20 , V_41 ) ;
F_122 ( V_20 , V_41 , NULL , V_384 ) ;
}
static void F_213 ( struct V_8 * V_20 ,
struct V_175 * V_41 )
{
F_21 ( L_10 , V_20 , V_41 ) ;
F_122 ( V_20 , V_41 , NULL , V_385 ) ;
}
static void F_214 ( struct V_9 * V_10 , struct V_36 * V_40 )
{
struct V_36 * V_387 ;
struct V_8 * V_20 ;
F_21 ( L_14 , V_10 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
if ( V_20 -> V_90 != V_143 )
continue;
if ( F_33 ( V_40 ) -> V_20 == V_20 )
continue;
V_387 = F_176 ( V_40 , V_49 ) ;
if ( ! V_387 )
continue;
if ( V_20 -> V_30 -> V_388 ( V_20 , V_387 ) )
F_90 ( V_387 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static struct V_36 * F_85 ( struct V_9 * V_10 , T_3 V_157 ,
T_3 V_16 , T_2 V_389 , void * V_159 )
{
struct V_36 * V_40 , * * V_352 ;
struct V_390 * V_391 ;
struct V_216 * V_217 ;
int V_158 , V_351 ;
F_21 ( L_40 ,
V_10 , V_157 , V_16 , V_389 ) ;
if ( V_10 -> V_325 < V_213 + V_392 )
return NULL ;
V_158 = V_213 + V_392 + V_389 ;
V_351 = F_192 (unsigned int, conn->mtu, len) ;
V_40 = F_104 ( V_351 , V_49 ) ;
if ( ! V_40 )
return NULL ;
V_217 = (struct V_216 * ) F_106 ( V_40 , V_213 ) ;
V_217 -> V_158 = F_16 ( V_392 + V_389 ) ;
if ( V_10 -> V_2 -> type == V_3 )
V_217 -> V_11 = F_77 ( V_393 ) ;
else
V_217 -> V_11 = F_77 ( V_101 ) ;
V_391 = (struct V_390 * ) F_106 ( V_40 , V_392 ) ;
V_391 -> V_157 = V_157 ;
V_391 -> V_16 = V_16 ;
V_391 -> V_158 = F_16 ( V_389 ) ;
if ( V_389 ) {
V_351 -= V_213 + V_392 ;
memcpy ( F_106 ( V_40 , V_351 ) , V_159 , V_351 ) ;
V_159 += V_351 ;
}
V_158 -= V_40 -> V_158 ;
V_352 = & F_191 ( V_40 ) -> V_355 ;
while ( V_158 ) {
V_351 = F_192 (unsigned int, conn->mtu, len) ;
* V_352 = F_104 ( V_351 , V_49 ) ;
if ( ! * V_352 )
goto V_394;
memcpy ( F_106 ( * V_352 , V_351 ) , V_159 , V_351 ) ;
V_158 -= V_351 ;
V_159 += V_351 ;
V_352 = & ( * V_352 ) -> V_313 ;
}
return V_40 ;
V_394:
F_90 ( V_40 ) ;
return NULL ;
}
static inline int F_215 ( void * * V_395 , int * type , int * V_396 ,
unsigned long * V_397 )
{
struct V_398 * V_399 = * V_395 ;
int V_158 ;
V_158 = V_400 + V_399 -> V_158 ;
* V_395 += V_158 ;
* type = V_399 -> type ;
* V_396 = V_399 -> V_158 ;
switch ( V_399 -> V_158 ) {
case 1 :
* V_397 = * ( ( T_3 * ) V_399 -> V_397 ) ;
break;
case 2 :
* V_397 = F_96 ( V_399 -> V_397 ) ;
break;
case 4 :
* V_397 = F_94 ( V_399 -> V_397 ) ;
break;
default:
* V_397 = ( unsigned long ) V_399 -> V_397 ;
break;
}
F_21 ( L_41 , * type , V_399 -> V_158 , * V_397 ) ;
return V_158 ;
}
static void F_216 ( void * * V_395 , T_3 type , T_3 V_158 , unsigned long V_397 )
{
struct V_398 * V_399 = * V_395 ;
F_21 ( L_41 , type , V_158 , V_397 ) ;
V_399 -> type = type ;
V_399 -> V_158 = V_158 ;
switch ( V_158 ) {
case 1 :
* ( ( T_3 * ) V_399 -> V_397 ) = V_397 ;
break;
case 2 :
F_101 ( V_397 , V_399 -> V_397 ) ;
break;
case 4 :
F_100 ( V_397 , V_399 -> V_397 ) ;
break;
default:
memcpy ( V_399 -> V_397 , ( void * ) V_397 , V_158 ) ;
break;
}
* V_395 += V_400 + V_158 ;
}
static void F_217 ( void * * V_395 , struct V_8 * V_20 )
{
struct V_401 V_402 ;
switch ( V_20 -> V_121 ) {
case V_123 :
V_402 . V_155 = V_20 -> V_102 ;
V_402 . V_403 = V_20 -> V_104 ;
V_402 . V_404 = F_16 ( V_20 -> V_106 ) ;
V_402 . V_405 = F_218 ( V_20 -> V_108 ) ;
V_402 . V_406 = F_219 ( V_111 ) ;
V_402 . V_407 = F_219 ( V_113 ) ;
break;
case V_127 :
V_402 . V_155 = 1 ;
V_402 . V_403 = V_105 ;
V_402 . V_404 = F_16 ( V_20 -> V_106 ) ;
V_402 . V_405 = F_218 ( V_20 -> V_108 ) ;
V_402 . V_406 = 0 ;
V_402 . V_407 = 0 ;
break;
default:
return;
}
F_216 ( V_395 , V_408 , sizeof( V_402 ) ,
( unsigned long ) & V_402 ) ;
}
static void F_220 ( struct V_56 * V_57 )
{
struct V_8 * V_20 = F_45 ( V_57 , struct V_8 ,
V_409 . V_57 ) ;
T_2 V_346 ;
F_21 ( L_3 , V_20 ) ;
F_7 ( V_20 ) ;
V_346 = F_187 ( V_20 , V_20 -> V_229 ,
V_20 -> V_227 ) ;
if ( V_346 )
F_112 ( V_20 , 0 ) ;
F_47 ( V_20 ) ;
F_48 ( V_20 ) ;
}
int F_221 ( struct V_8 * V_20 )
{
int V_21 ;
V_20 -> V_338 = 0 ;
V_20 -> V_250 = 0 ;
V_20 -> V_377 = 0 ;
V_20 -> V_344 = 0 ;
V_20 -> V_229 = 0 ;
V_20 -> V_339 = 0 ;
V_20 -> V_227 = 0 ;
V_20 -> V_410 = NULL ;
V_20 -> V_411 = NULL ;
V_20 -> V_364 = 0 ;
F_222 ( & V_20 -> V_128 ) ;
V_20 -> V_412 = V_413 ;
V_20 -> V_414 = V_413 ;
V_20 -> V_168 = V_169 ;
V_20 -> V_258 = V_259 ;
if ( V_20 -> V_121 != V_123 )
return 0 ;
V_20 -> V_255 = V_348 ;
V_20 -> V_253 = V_254 ;
F_53 ( & V_20 -> V_34 , F_169 ) ;
F_53 ( & V_20 -> V_32 , F_168 ) ;
F_53 ( & V_20 -> V_409 , F_220 ) ;
F_222 ( & V_20 -> V_124 ) ;
V_21 = F_34 ( & V_20 -> V_125 , V_20 -> V_81 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_34 ( & V_20 -> V_126 , V_20 -> V_345 ) ;
if ( V_21 < 0 )
F_37 ( & V_20 -> V_125 ) ;
return V_21 ;
}
static inline T_1 F_223 ( T_1 V_121 , T_6 V_415 )
{
switch ( V_121 ) {
case V_127 :
case V_123 :
if ( F_128 ( V_121 , V_415 ) )
return V_121 ;
default:
return V_122 ;
}
}
static inline bool F_224 ( struct V_9 * V_10 )
{
return V_10 -> V_233 && V_10 -> V_275 & V_416 ;
}
static inline bool F_225 ( struct V_9 * V_10 )
{
return V_10 -> V_233 && V_10 -> V_275 & V_417 ;
}
static void F_226 ( struct V_8 * V_20 ,
struct V_418 * V_419 )
{
if ( V_20 -> V_412 != V_413 && V_20 -> V_171 ) {
T_10 V_420 = V_20 -> V_171 -> V_160 -> V_421 ;
V_420 = F_227 ( V_420 , 1000 ) ;
V_420 = 3 * V_420 + 500 ;
if ( V_420 > 0xffff )
V_420 = 0xffff ;
V_419 -> V_33 = F_16 ( ( T_2 ) V_420 ) ;
V_419 -> V_35 = V_419 -> V_33 ;
} else {
V_419 -> V_33 = F_77 ( V_422 ) ;
V_419 -> V_35 = F_77 ( V_423 ) ;
}
}
static inline void F_228 ( struct V_8 * V_20 )
{
if ( V_20 -> V_81 > V_82 &&
F_224 ( V_20 -> V_10 ) ) {
F_55 ( V_209 , & V_20 -> V_87 ) ;
V_20 -> V_83 = V_424 ;
} else {
V_20 -> V_81 = F_192 ( T_2 , V_20 -> V_81 ,
V_82 ) ;
V_20 -> V_83 = V_82 ;
}
V_20 -> V_84 = V_20 -> V_81 ;
}
static int F_131 ( struct V_8 * V_20 , void * V_159 )
{
struct V_425 * V_243 = V_159 ;
struct V_418 V_419 = { . V_121 = V_20 -> V_121 } ;
void * V_395 = V_243 -> V_159 ;
T_2 V_45 ;
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_294 || V_20 -> V_426 )
goto V_24;
switch ( V_20 -> V_121 ) {
case V_127 :
case V_123 :
if ( F_71 ( V_284 , & V_20 -> V_75 ) )
break;
if ( F_225 ( V_20 -> V_10 ) )
F_55 ( V_427 , & V_20 -> V_87 ) ;
default:
V_20 -> V_121 = F_223 ( V_419 . V_121 , V_20 -> V_10 -> V_275 ) ;
break;
}
V_24:
if ( V_20 -> V_100 != V_93 )
F_216 ( & V_395 , V_428 , 2 , V_20 -> V_100 ) ;
switch ( V_20 -> V_121 ) {
case V_122 :
if ( ! ( V_20 -> V_10 -> V_275 & V_279 ) &&
! ( V_20 -> V_10 -> V_275 & V_280 ) )
break;
V_419 . V_121 = V_122 ;
V_419 . V_429 = 0 ;
V_419 . V_430 = 0 ;
V_419 . V_33 = 0 ;
V_419 . V_35 = 0 ;
V_419 . V_431 = 0 ;
F_216 ( & V_395 , V_432 , sizeof( V_419 ) ,
( unsigned long ) & V_419 ) ;
break;
case V_123 :
V_419 . V_121 = V_123 ;
V_419 . V_430 = V_20 -> V_79 ;
F_226 ( V_20 , & V_419 ) ;
V_45 = F_192 ( T_2 , V_433 , V_20 -> V_10 -> V_325 -
V_214 - V_362 -
V_219 ) ;
V_419 . V_431 = F_16 ( V_45 ) ;
F_228 ( V_20 ) ;
V_419 . V_429 = F_192 ( T_2 , V_20 -> V_81 ,
V_82 ) ;
F_216 ( & V_395 , V_432 , sizeof( V_419 ) ,
( unsigned long ) & V_419 ) ;
if ( F_71 ( V_427 , & V_20 -> V_87 ) )
F_217 ( & V_395 , V_20 ) ;
if ( F_71 ( V_209 , & V_20 -> V_87 ) )
F_216 ( & V_395 , V_434 , 2 ,
V_20 -> V_81 ) ;
if ( V_20 -> V_10 -> V_275 & V_435 )
if ( V_20 -> V_77 == V_436 ||
F_71 ( V_437 , & V_20 -> V_75 ) ) {
V_20 -> V_77 = V_436 ;
F_216 ( & V_395 , V_438 , 1 ,
V_20 -> V_77 ) ;
}
break;
case V_127 :
F_228 ( V_20 ) ;
V_419 . V_121 = V_127 ;
V_419 . V_429 = 0 ;
V_419 . V_430 = 0 ;
V_419 . V_33 = 0 ;
V_419 . V_35 = 0 ;
V_45 = F_192 ( T_2 , V_433 , V_20 -> V_10 -> V_325 -
V_214 - V_362 -
V_219 ) ;
V_419 . V_431 = F_16 ( V_45 ) ;
F_216 ( & V_395 , V_432 , sizeof( V_419 ) ,
( unsigned long ) & V_419 ) ;
if ( F_71 ( V_427 , & V_20 -> V_87 ) )
F_217 ( & V_395 , V_20 ) ;
if ( V_20 -> V_10 -> V_275 & V_435 )
if ( V_20 -> V_77 == V_436 ||
F_71 ( V_437 , & V_20 -> V_75 ) ) {
V_20 -> V_77 = V_436 ;
F_216 ( & V_395 , V_438 , 1 ,
V_20 -> V_77 ) ;
}
break;
}
V_243 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_243 -> V_87 = F_77 ( 0 ) ;
return V_395 - V_159 ;
}
static int F_229 ( struct V_8 * V_20 , void * V_159 )
{
struct V_439 * V_134 = V_159 ;
void * V_395 = V_134 -> V_159 ;
void * V_243 = V_20 -> V_440 ;
int V_158 = V_20 -> V_441 ;
int type , V_442 , V_396 ;
unsigned long V_397 ;
struct V_418 V_419 = { . V_121 = V_122 } ;
struct V_401 V_402 ;
T_3 V_443 = 0 ;
T_2 V_325 = V_93 ;
T_2 V_135 = V_444 ;
T_2 V_45 ;
F_21 ( L_3 , V_20 ) ;
while ( V_158 >= V_400 ) {
V_158 -= F_215 ( & V_243 , & type , & V_396 , & V_397 ) ;
V_442 = type & V_445 ;
type &= V_446 ;
switch ( type ) {
case V_428 :
V_325 = V_397 ;
break;
case V_447 :
V_20 -> V_407 = V_397 ;
break;
case V_448 :
break;
case V_432 :
if ( V_396 == sizeof( V_419 ) )
memcpy ( & V_419 , ( void * ) V_397 , V_396 ) ;
break;
case V_438 :
if ( V_397 == V_436 )
F_55 ( V_437 , & V_20 -> V_75 ) ;
break;
case V_408 :
V_443 = 1 ;
if ( V_396 == sizeof( V_402 ) )
memcpy ( & V_402 , ( void * ) V_397 , V_396 ) ;
break;
case V_434 :
if ( ! V_20 -> V_10 -> V_233 )
return - V_62 ;
F_55 ( V_209 , & V_20 -> V_87 ) ;
F_55 ( V_449 , & V_20 -> V_75 ) ;
V_20 -> V_83 = V_424 ;
V_20 -> V_345 = V_397 ;
break;
default:
if ( V_442 )
break;
V_135 = V_450 ;
* ( ( T_3 * ) V_395 ++ ) = type ;
break;
}
}
if ( V_20 -> V_426 || V_20 -> V_294 > 1 )
goto V_24;
switch ( V_20 -> V_121 ) {
case V_127 :
case V_123 :
if ( ! F_71 ( V_284 , & V_20 -> V_75 ) ) {
V_20 -> V_121 = F_223 ( V_419 . V_121 ,
V_20 -> V_10 -> V_275 ) ;
break;
}
if ( V_443 ) {
if ( F_225 ( V_20 -> V_10 ) )
F_55 ( V_427 , & V_20 -> V_87 ) ;
else
return - V_62 ;
}
if ( V_20 -> V_121 != V_419 . V_121 )
return - V_62 ;
break;
}
V_24:
if ( V_20 -> V_121 != V_419 . V_121 ) {
V_135 = V_451 ;
V_419 . V_121 = V_20 -> V_121 ;
if ( V_20 -> V_426 == 1 )
return - V_62 ;
F_216 ( & V_395 , V_432 , sizeof( V_419 ) ,
( unsigned long ) & V_419 ) ;
}
if ( V_135 == V_444 ) {
if ( V_325 < V_452 )
V_135 = V_451 ;
else {
V_20 -> V_92 = V_325 ;
F_55 ( V_453 , & V_20 -> V_75 ) ;
}
F_216 ( & V_395 , V_428 , 2 , V_20 -> V_92 ) ;
if ( V_443 ) {
if ( V_20 -> V_104 != V_454 &&
V_402 . V_403 != V_454 &&
V_402 . V_403 != V_20 -> V_104 ) {
V_135 = V_451 ;
if ( V_20 -> V_294 >= 1 )
return - V_62 ;
F_216 ( & V_395 , V_408 ,
sizeof( V_402 ) ,
( unsigned long ) & V_402 ) ;
} else {
V_135 = V_455 ;
F_55 ( V_456 , & V_20 -> V_75 ) ;
}
}
switch ( V_419 . V_121 ) {
case V_122 :
V_20 -> V_77 = V_436 ;
F_55 ( V_457 , & V_20 -> V_75 ) ;
break;
case V_123 :
if ( ! F_71 ( V_449 , & V_20 -> V_75 ) )
V_20 -> V_345 = V_419 . V_429 ;
else
V_419 . V_429 = V_82 ;
V_20 -> V_458 = V_419 . V_430 ;
V_45 = F_192 ( T_2 , F_230 ( V_419 . V_431 ) ,
V_20 -> V_10 -> V_325 - V_214 -
V_362 - V_219 ) ;
V_419 . V_431 = F_16 ( V_45 ) ;
V_20 -> V_367 = V_45 ;
F_226 ( V_20 , & V_419 ) ;
F_55 ( V_457 , & V_20 -> V_75 ) ;
F_216 ( & V_395 , V_432 ,
sizeof( V_419 ) , ( unsigned long ) & V_419 ) ;
if ( F_71 ( V_427 , & V_20 -> V_87 ) ) {
V_20 -> V_459 = V_402 . V_155 ;
V_20 -> V_460 = V_402 . V_403 ;
V_20 -> V_461 = F_230 ( V_402 . V_404 ) ;
V_20 -> V_462 =
F_231 ( V_402 . V_407 ) ;
V_20 -> V_463 =
F_231 ( V_402 . V_406 ) ;
V_20 -> V_464 =
F_231 ( V_402 . V_405 ) ;
F_216 ( & V_395 , V_408 ,
sizeof( V_402 ) ,
( unsigned long ) & V_402 ) ;
}
break;
case V_127 :
V_45 = F_192 ( T_2 , F_230 ( V_419 . V_431 ) ,
V_20 -> V_10 -> V_325 - V_214 -
V_362 - V_219 ) ;
V_419 . V_431 = F_16 ( V_45 ) ;
V_20 -> V_367 = V_45 ;
F_55 ( V_457 , & V_20 -> V_75 ) ;
F_216 ( & V_395 , V_432 , sizeof( V_419 ) ,
( unsigned long ) & V_419 ) ;
break;
default:
V_135 = V_451 ;
memset ( & V_419 , 0 , sizeof( V_419 ) ) ;
V_419 . V_121 = V_20 -> V_121 ;
}
if ( V_135 == V_444 )
F_55 ( V_465 , & V_20 -> V_75 ) ;
}
V_134 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_134 -> V_135 = F_16 ( V_135 ) ;
V_134 -> V_87 = F_77 ( 0 ) ;
return V_395 - V_159 ;
}
static int F_232 ( struct V_8 * V_20 , void * V_134 , int V_158 ,
void * V_159 , T_2 * V_135 )
{
struct V_425 * V_243 = V_159 ;
void * V_395 = V_243 -> V_159 ;
int type , V_396 ;
unsigned long V_397 ;
struct V_418 V_419 = { . V_121 = V_122 } ;
struct V_401 V_402 ;
F_21 ( L_42 , V_20 , V_134 , V_158 , V_159 ) ;
while ( V_158 >= V_400 ) {
V_158 -= F_215 ( & V_134 , & type , & V_396 , & V_397 ) ;
switch ( type ) {
case V_428 :
if ( V_397 < V_452 ) {
* V_135 = V_451 ;
V_20 -> V_100 = V_452 ;
} else
V_20 -> V_100 = V_397 ;
F_216 ( & V_395 , V_428 , 2 , V_20 -> V_100 ) ;
break;
case V_447 :
V_20 -> V_407 = V_397 ;
F_216 ( & V_395 , V_447 ,
2 , V_20 -> V_407 ) ;
break;
case V_432 :
if ( V_396 == sizeof( V_419 ) )
memcpy ( & V_419 , ( void * ) V_397 , V_396 ) ;
if ( F_71 ( V_284 , & V_20 -> V_75 ) &&
V_419 . V_121 != V_20 -> V_121 )
return - V_62 ;
V_20 -> V_77 = 0 ;
F_216 ( & V_395 , V_432 ,
sizeof( V_419 ) , ( unsigned long ) & V_419 ) ;
break;
case V_434 :
V_20 -> V_84 = F_192 ( T_2 , V_397 , V_20 -> V_84 ) ;
F_216 ( & V_395 , V_434 , 2 ,
V_20 -> V_81 ) ;
break;
case V_408 :
if ( V_396 == sizeof( V_402 ) )
memcpy ( & V_402 , ( void * ) V_397 , V_396 ) ;
if ( V_20 -> V_104 != V_454 &&
V_402 . V_403 != V_454 &&
V_402 . V_403 != V_20 -> V_104 )
return - V_62 ;
F_216 ( & V_395 , V_408 , sizeof( V_402 ) ,
( unsigned long ) & V_402 ) ;
break;
case V_438 :
if ( * V_135 == V_455 )
if ( V_397 == V_436 )
F_55 ( V_437 ,
& V_20 -> V_75 ) ;
break;
}
}
if ( V_20 -> V_121 == V_122 && V_20 -> V_121 != V_419 . V_121 )
return - V_62 ;
V_20 -> V_121 = V_419 . V_121 ;
if ( * V_135 == V_444 || * V_135 == V_455 ) {
switch ( V_419 . V_121 ) {
case V_123 :
V_20 -> V_33 = F_230 ( V_419 . V_33 ) ;
V_20 -> V_35 = F_230 ( V_419 . V_35 ) ;
V_20 -> V_466 = F_230 ( V_419 . V_431 ) ;
if ( ! F_71 ( V_209 , & V_20 -> V_87 ) )
V_20 -> V_84 = F_192 ( T_2 , V_20 -> V_84 ,
V_419 . V_429 ) ;
if ( F_71 ( V_427 , & V_20 -> V_87 ) ) {
V_20 -> V_106 = F_230 ( V_402 . V_404 ) ;
V_20 -> V_108 =
F_231 ( V_402 . V_405 ) ;
V_20 -> V_110 = F_231 ( V_402 . V_406 ) ;
V_20 -> V_112 =
F_231 ( V_402 . V_407 ) ;
}
break;
case V_127 :
V_20 -> V_466 = F_230 ( V_419 . V_431 ) ;
}
}
V_243 -> V_13 = F_16 ( V_20 -> V_13 ) ;
V_243 -> V_87 = F_77 ( 0 ) ;
return V_395 - V_159 ;
}
static int F_233 ( struct V_8 * V_20 , void * V_159 ,
T_2 V_135 , T_2 V_87 )
{
struct V_439 * V_134 = V_159 ;
void * V_395 = V_134 -> V_159 ;
F_21 ( L_3 , V_20 ) ;
V_134 -> V_14 = F_16 ( V_20 -> V_13 ) ;
V_134 -> V_135 = F_16 ( V_135 ) ;
V_134 -> V_87 = F_16 ( V_87 ) ;
return V_395 - V_159 ;
}
void F_234 ( struct V_8 * V_20 )
{
struct V_133 V_134 ;
struct V_9 * V_10 = V_20 -> V_10 ;
T_3 V_286 [ 128 ] ;
T_3 V_467 ;
V_134 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_134 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_134 . V_135 = F_77 ( V_290 ) ;
V_134 . V_140 = F_77 ( V_141 ) ;
if ( V_20 -> V_171 )
V_467 = V_468 ;
else
V_467 = V_142 ;
F_21 ( L_43 , V_20 , V_467 ) ;
F_78 ( V_10 , V_20 -> V_16 , V_467 , sizeof( V_134 ) , & V_134 ) ;
if ( F_235 ( V_292 , & V_20 -> V_75 ) )
return;
F_78 ( V_10 , F_82 ( V_10 ) , V_293 ,
F_131 ( V_20 , V_286 ) , V_286 ) ;
V_20 -> V_294 ++ ;
}
static void F_236 ( struct V_8 * V_20 , void * V_134 , int V_158 )
{
int type , V_396 ;
unsigned long V_397 ;
T_2 V_469 = V_20 -> V_84 ;
struct V_418 V_419 = {
. V_121 = V_20 -> V_121 ,
. V_33 = F_77 ( V_422 ) ,
. V_35 = F_77 ( V_423 ) ,
. V_431 = F_16 ( V_20 -> V_100 ) ,
. V_429 = F_192 ( T_2 , V_20 -> V_84 , V_82 ) ,
} ;
F_21 ( L_44 , V_20 , V_134 , V_158 ) ;
if ( ( V_20 -> V_121 != V_123 ) && ( V_20 -> V_121 != V_127 ) )
return;
while ( V_158 >= V_400 ) {
V_158 -= F_215 ( & V_134 , & type , & V_396 , & V_397 ) ;
switch ( type ) {
case V_432 :
if ( V_396 == sizeof( V_419 ) )
memcpy ( & V_419 , ( void * ) V_397 , V_396 ) ;
break;
case V_434 :
V_469 = V_397 ;
break;
}
}
switch ( V_419 . V_121 ) {
case V_123 :
V_20 -> V_33 = F_230 ( V_419 . V_33 ) ;
V_20 -> V_35 = F_230 ( V_419 . V_35 ) ;
V_20 -> V_466 = F_230 ( V_419 . V_431 ) ;
if ( F_71 ( V_209 , & V_20 -> V_87 ) )
V_20 -> V_84 = F_192 ( T_2 , V_20 -> V_84 , V_469 ) ;
else
V_20 -> V_84 = F_192 ( T_2 , V_20 -> V_84 ,
V_419 . V_429 ) ;
break;
case V_127 :
V_20 -> V_466 = F_230 ( V_419 . V_431 ) ;
}
}
static inline int F_237 ( struct V_9 * V_10 ,
struct V_390 * V_391 , T_2 V_470 ,
T_3 * V_159 )
{
struct V_471 * V_472 = (struct V_471 * ) V_159 ;
if ( V_470 < sizeof( * V_472 ) )
return - V_473 ;
if ( V_472 -> V_59 != V_474 )
return 0 ;
if ( ( V_10 -> V_266 & V_267 ) &&
V_391 -> V_16 == V_10 -> V_271 ) {
F_238 ( & V_10 -> V_272 ) ;
V_10 -> V_266 |= V_268 ;
V_10 -> V_271 = 0 ;
F_129 ( V_10 ) ;
}
return 0 ;
}
static struct V_8 * F_239 ( struct V_9 * V_10 ,
struct V_390 * V_391 ,
T_3 * V_159 , T_3 V_467 , T_3 V_245 )
{
struct V_242 * V_243 = (struct V_242 * ) V_159 ;
struct V_133 V_134 ;
struct V_8 * V_20 = NULL , * V_302 ;
int V_135 , V_140 = V_141 ;
T_2 V_13 = 0 , V_14 = F_64 ( V_243 -> V_14 ) ;
T_4 V_17 = V_243 -> V_17 ;
F_21 ( L_45 , F_64 ( V_17 ) , V_14 ) ;
V_302 = F_161 ( V_129 , V_17 , & V_10 -> V_2 -> V_18 ,
& V_10 -> V_2 -> V_295 ) ;
if ( ! V_302 ) {
V_135 = V_138 ;
goto V_475;
}
F_6 ( & V_10 -> V_15 ) ;
F_7 ( V_302 ) ;
if ( V_17 != F_77 ( V_151 ) &&
! F_240 ( V_10 -> V_2 ) ) {
V_10 -> V_88 = V_476 ;
V_135 = V_137 ;
goto V_477;
}
V_135 = V_478 ;
if ( F_2 ( V_10 , V_14 ) )
goto V_477;
V_20 = V_302 -> V_30 -> V_304 ( V_302 ) ;
if ( ! V_20 )
goto V_477;
V_10 -> V_2 -> V_479 = V_480 ;
F_135 ( & V_20 -> V_18 , & V_10 -> V_2 -> V_18 ) ;
F_135 ( & V_20 -> V_295 , & V_10 -> V_2 -> V_295 ) ;
V_20 -> V_306 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_306 ) ;
V_20 -> V_303 = F_1 ( V_10 -> V_2 , V_10 -> V_2 -> V_303 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_13 = V_14 ;
V_20 -> V_412 = V_245 ;
F_63 ( V_10 , V_20 ) ;
V_13 = V_20 -> V_14 ;
F_75 ( V_20 , V_20 -> V_30 -> V_131 ( V_20 ) ) ;
V_20 -> V_16 = V_391 -> V_16 ;
if ( V_10 -> V_266 & V_268 ) {
if ( F_80 ( V_20 ) ) {
if ( F_71 ( V_136 , & V_20 -> V_87 ) ) {
F_20 ( V_20 , V_132 ) ;
V_135 = V_287 ;
V_140 = V_288 ;
V_20 -> V_30 -> V_289 ( V_20 ) ;
} else {
if ( V_245 == V_413 ) {
F_20 ( V_20 , V_61 ) ;
V_135 = V_290 ;
} else {
F_20 ( V_20 , V_132 ) ;
V_135 = V_287 ;
}
V_140 = V_141 ;
}
} else {
F_20 ( V_20 , V_132 ) ;
V_135 = V_287 ;
V_140 = V_291 ;
}
} else {
F_20 ( V_20 , V_132 ) ;
V_135 = V_287 ;
V_140 = V_141 ;
}
V_477:
F_47 ( V_302 ) ;
F_8 ( & V_10 -> V_15 ) ;
V_475:
V_134 . V_14 = F_16 ( V_14 ) ;
V_134 . V_13 = F_16 ( V_13 ) ;
V_134 . V_135 = F_16 ( V_135 ) ;
V_134 . V_140 = F_16 ( V_140 ) ;
F_78 ( V_10 , V_391 -> V_16 , V_467 , sizeof( V_134 ) , & V_134 ) ;
if ( V_135 == V_287 && V_140 == V_141 ) {
struct V_269 V_481 ;
V_481 . type = F_77 ( V_270 ) ;
V_10 -> V_266 |= V_267 ;
V_10 -> V_271 = F_82 ( V_10 ) ;
F_127 ( & V_10 -> V_272 , V_273 ) ;
F_78 ( V_10 , V_10 -> V_271 , V_274 ,
sizeof( V_481 ) , & V_481 ) ;
}
if ( V_20 && ! F_71 ( V_292 , & V_20 -> V_75 ) &&
V_135 == V_290 ) {
T_3 V_286 [ 128 ] ;
F_55 ( V_292 , & V_20 -> V_75 ) ;
F_78 ( V_10 , F_82 ( V_10 ) , V_293 ,
F_131 ( V_20 , V_286 ) , V_286 ) ;
V_20 -> V_294 ++ ;
}
return V_20 ;
}
static int F_241 ( struct V_9 * V_10 ,
struct V_390 * V_391 , T_2 V_470 , T_3 * V_159 )
{
struct V_231 * V_160 = V_10 -> V_2 -> V_160 ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_470 < sizeof( struct V_242 ) )
return - V_473 ;
F_141 ( V_160 ) ;
if ( F_71 ( V_482 , & V_160 -> V_328 ) &&
! F_235 ( V_483 , & V_2 -> V_87 ) )
F_242 ( V_160 , & V_2 -> V_295 , V_2 -> type ,
V_2 -> V_303 , 0 , NULL , 0 ,
V_2 -> V_484 ) ;
F_142 ( V_160 ) ;
F_239 ( V_10 , V_391 , V_159 , V_142 , 0 ) ;
return 0 ;
}
static int F_243 ( struct V_9 * V_10 ,
struct V_390 * V_391 , T_2 V_470 ,
T_3 * V_159 )
{
struct V_133 * V_134 = (struct V_133 * ) V_159 ;
T_2 V_14 , V_13 , V_135 , V_140 ;
struct V_8 * V_20 ;
T_3 V_243 [ 128 ] ;
int V_21 ;
if ( V_470 < sizeof( * V_134 ) )
return - V_473 ;
V_14 = F_64 ( V_134 -> V_14 ) ;
V_13 = F_64 ( V_134 -> V_13 ) ;
V_135 = F_64 ( V_134 -> V_135 ) ;
V_140 = F_64 ( V_134 -> V_140 ) ;
F_21 ( L_46 ,
V_13 , V_14 , V_135 , V_140 ) ;
F_6 ( & V_10 -> V_15 ) ;
if ( V_14 ) {
V_20 = F_4 ( V_10 , V_14 ) ;
if ( ! V_20 ) {
V_21 = - V_485 ;
goto V_486;
}
} else {
V_20 = F_10 ( V_10 , V_391 -> V_16 ) ;
if ( ! V_20 ) {
V_21 = - V_485 ;
goto V_486;
}
}
V_21 = 0 ;
F_7 ( V_20 ) ;
switch ( V_135 ) {
case V_290 :
F_20 ( V_20 , V_61 ) ;
V_20 -> V_16 = 0 ;
V_20 -> V_13 = V_13 ;
F_110 ( V_230 , & V_20 -> V_75 ) ;
if ( F_235 ( V_292 , & V_20 -> V_75 ) )
break;
F_78 ( V_10 , F_82 ( V_10 ) , V_293 ,
F_131 ( V_20 , V_243 ) , V_243 ) ;
V_20 -> V_294 ++ ;
break;
case V_287 :
F_55 ( V_230 , & V_20 -> V_75 ) ;
break;
default:
F_67 ( V_20 , V_62 ) ;
break;
}
F_47 ( V_20 ) ;
V_486:
F_8 ( & V_10 -> V_15 ) ;
return V_21 ;
}
static inline void F_244 ( struct V_8 * V_20 )
{
if ( V_20 -> V_121 != V_123 && V_20 -> V_121 != V_127 )
V_20 -> V_77 = V_436 ;
else if ( ! F_71 ( V_437 , & V_20 -> V_75 ) )
V_20 -> V_77 = V_78 ;
}
static void F_245 ( struct V_8 * V_20 , void * V_159 ,
T_3 V_16 , T_2 V_87 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
F_21 ( L_47 , V_10 , V_20 , V_16 ,
V_87 ) ;
F_110 ( V_456 , & V_20 -> V_75 ) ;
F_55 ( V_465 , & V_20 -> V_75 ) ;
F_78 ( V_10 , V_16 , V_487 ,
F_233 ( V_20 , V_159 ,
V_444 , V_87 ) , V_159 ) ;
}
static void F_246 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_14 , T_2 V_13 )
{
struct V_488 V_472 ;
V_472 . V_59 = F_77 ( V_489 ) ;
V_472 . V_14 = F_247 ( V_14 ) ;
V_472 . V_13 = F_247 ( V_13 ) ;
F_78 ( V_10 , V_16 , V_490 , sizeof( V_472 ) , & V_472 ) ;
}
static inline int F_248 ( struct V_9 * V_10 ,
struct V_390 * V_391 , T_2 V_470 ,
T_3 * V_159 )
{
struct V_425 * V_243 = (struct V_425 * ) V_159 ;
T_2 V_13 , V_87 ;
T_3 V_134 [ 64 ] ;
struct V_8 * V_20 ;
int V_158 , V_21 = 0 ;
if ( V_470 < sizeof( * V_243 ) )
return - V_473 ;
V_13 = F_64 ( V_243 -> V_13 ) ;
V_87 = F_64 ( V_243 -> V_87 ) ;
F_21 ( L_48 , V_13 , V_87 ) ;
V_20 = F_5 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_246 ( V_10 , V_391 -> V_16 , V_13 , 0 ) ;
return 0 ;
}
if ( V_20 -> V_29 != V_61 && V_20 -> V_29 != V_132 ) {
F_246 ( V_10 , V_391 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
goto V_486;
}
V_158 = V_470 - sizeof( * V_243 ) ;
if ( V_20 -> V_441 + V_158 > sizeof( V_20 -> V_440 ) ) {
F_78 ( V_10 , V_391 -> V_16 , V_487 ,
F_233 ( V_20 , V_134 ,
V_491 , V_87 ) , V_134 ) ;
goto V_486;
}
memcpy ( V_20 -> V_440 + V_20 -> V_441 , V_243 -> V_159 , V_158 ) ;
V_20 -> V_441 += V_158 ;
if ( V_87 & V_492 ) {
F_78 ( V_10 , V_391 -> V_16 , V_487 ,
F_233 ( V_20 , V_134 ,
V_444 , V_87 ) , V_134 ) ;
goto V_486;
}
V_158 = F_229 ( V_20 , V_134 ) ;
if ( V_158 < 0 ) {
F_76 ( V_20 , V_285 ) ;
goto V_486;
}
V_20 -> V_16 = V_391 -> V_16 ;
F_78 ( V_10 , V_391 -> V_16 , V_487 , V_158 , V_134 ) ;
V_20 -> V_426 ++ ;
V_20 -> V_441 = 0 ;
if ( ! F_71 ( V_465 , & V_20 -> V_75 ) )
goto V_486;
if ( F_71 ( V_493 , & V_20 -> V_75 ) ) {
F_244 ( V_20 ) ;
if ( V_20 -> V_121 == V_123 ||
V_20 -> V_121 == V_127 )
V_21 = F_221 ( V_20 ) ;
if ( V_21 < 0 )
F_76 ( V_20 , - V_21 ) ;
else
F_123 ( V_20 ) ;
goto V_486;
}
if ( ! F_235 ( V_292 , & V_20 -> V_75 ) ) {
T_3 V_286 [ 64 ] ;
F_78 ( V_10 , F_82 ( V_10 ) , V_293 ,
F_131 ( V_20 , V_286 ) , V_286 ) ;
V_20 -> V_294 ++ ;
}
if ( F_71 ( V_494 , & V_20 -> V_75 ) &&
F_71 ( V_456 , & V_20 -> V_75 ) ) {
if ( ! V_20 -> V_171 )
F_245 ( V_20 , V_134 , V_391 -> V_16 , V_87 ) ;
else
V_20 -> V_16 = V_391 -> V_16 ;
}
V_486:
F_47 ( V_20 ) ;
return V_21 ;
}
static inline int F_249 ( struct V_9 * V_10 ,
struct V_390 * V_391 , T_2 V_470 ,
T_3 * V_159 )
{
struct V_439 * V_134 = (struct V_439 * ) V_159 ;
T_2 V_14 , V_87 , V_135 ;
struct V_8 * V_20 ;
int V_158 = V_470 - sizeof( * V_134 ) ;
int V_21 = 0 ;
if ( V_470 < sizeof( * V_134 ) )
return - V_473 ;
V_14 = F_64 ( V_134 -> V_14 ) ;
V_87 = F_64 ( V_134 -> V_87 ) ;
V_135 = F_64 ( V_134 -> V_135 ) ;
F_21 ( L_49 , V_14 , V_87 ,
V_135 , V_158 ) ;
V_20 = F_5 ( V_10 , V_14 ) ;
if ( ! V_20 )
return 0 ;
switch ( V_135 ) {
case V_444 :
F_236 ( V_20 , V_134 -> V_159 , V_158 ) ;
F_110 ( V_494 , & V_20 -> V_75 ) ;
break;
case V_455 :
F_55 ( V_494 , & V_20 -> V_75 ) ;
if ( F_71 ( V_456 , & V_20 -> V_75 ) ) {
char V_286 [ 64 ] ;
V_158 = F_232 ( V_20 , V_134 -> V_159 , V_158 ,
V_286 , & V_135 ) ;
if ( V_158 < 0 ) {
F_76 ( V_20 , V_285 ) ;
goto V_24;
}
if ( ! V_20 -> V_171 ) {
F_245 ( V_20 , V_286 , V_391 -> V_16 ,
0 ) ;
} else {
if ( F_117 ( V_20 ) ) {
F_250 ( V_20 ) ;
V_20 -> V_16 = V_391 -> V_16 ;
}
}
}
goto V_24;
case V_451 :
if ( V_20 -> V_426 <= V_495 ) {
char V_243 [ 64 ] ;
if ( V_158 > sizeof( V_243 ) - sizeof( struct V_425 ) ) {
F_76 ( V_20 , V_285 ) ;
goto V_24;
}
V_135 = V_444 ;
V_158 = F_232 ( V_20 , V_134 -> V_159 , V_158 ,
V_243 , & V_135 ) ;
if ( V_158 < 0 ) {
F_76 ( V_20 , V_285 ) ;
goto V_24;
}
F_78 ( V_10 , F_82 ( V_10 ) ,
V_293 , V_158 , V_243 ) ;
V_20 -> V_294 ++ ;
if ( V_135 != V_444 )
goto V_24;
break;
}
default:
F_24 ( V_20 , V_285 ) ;
F_75 ( V_20 , V_496 ) ;
F_76 ( V_20 , V_285 ) ;
goto V_24;
}
if ( V_87 & V_492 )
goto V_24;
F_55 ( V_493 , & V_20 -> V_75 ) ;
if ( F_71 ( V_465 , & V_20 -> V_75 ) ) {
F_244 ( V_20 ) ;
if ( V_20 -> V_121 == V_123 ||
V_20 -> V_121 == V_127 )
V_21 = F_221 ( V_20 ) ;
if ( V_21 < 0 )
F_76 ( V_20 , - V_21 ) ;
else
F_123 ( V_20 ) ;
}
V_24:
F_47 ( V_20 ) ;
return V_21 ;
}
static inline int F_251 ( struct V_9 * V_10 ,
struct V_390 * V_391 , T_2 V_470 ,
T_3 * V_159 )
{
struct V_281 * V_243 = (struct V_281 * ) V_159 ;
struct V_497 V_134 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_470 != sizeof( * V_243 ) )
return - V_473 ;
V_14 = F_64 ( V_243 -> V_14 ) ;
V_13 = F_64 ( V_243 -> V_13 ) ;
F_21 ( L_50 , V_14 , V_13 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_4 ( V_10 , V_13 ) ;
if ( ! V_20 ) {
F_8 ( & V_10 -> V_15 ) ;
F_246 ( V_10 , V_391 -> V_16 , V_13 , V_14 ) ;
return 0 ;
}
F_7 ( V_20 ) ;
V_134 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_134 . V_14 = F_16 ( V_20 -> V_13 ) ;
F_78 ( V_10 , V_391 -> V_16 , V_498 , sizeof( V_134 ) , & V_134 ) ;
V_20 -> V_30 -> V_499 ( V_20 ) ;
F_58 ( V_20 ) ;
F_67 ( V_20 , V_285 ) ;
F_47 ( V_20 ) ;
V_20 -> V_30 -> V_67 ( V_20 ) ;
F_48 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_252 ( struct V_9 * V_10 ,
struct V_390 * V_391 , T_2 V_470 ,
T_3 * V_159 )
{
struct V_497 * V_134 = (struct V_497 * ) V_159 ;
T_2 V_13 , V_14 ;
struct V_8 * V_20 ;
if ( V_470 != sizeof( * V_134 ) )
return - V_473 ;
V_14 = F_64 ( V_134 -> V_14 ) ;
V_13 = F_64 ( V_134 -> V_13 ) ;
F_21 ( L_51 , V_13 , V_14 ) ;
F_6 ( & V_10 -> V_15 ) ;
V_20 = F_4 ( V_10 , V_14 ) ;
if ( ! V_20 ) {
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
F_7 ( V_20 ) ;
F_58 ( V_20 ) ;
F_67 ( V_20 , 0 ) ;
F_47 ( V_20 ) ;
V_20 -> V_30 -> V_67 ( V_20 ) ;
F_48 ( V_20 ) ;
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static inline int F_253 ( struct V_9 * V_10 ,
struct V_390 * V_391 , T_2 V_470 ,
T_3 * V_159 )
{
struct V_269 * V_243 = (struct V_269 * ) V_159 ;
T_2 type ;
if ( V_470 != sizeof( * V_243 ) )
return - V_473 ;
type = F_64 ( V_243 -> type ) ;
F_21 ( L_52 , type ) ;
if ( type == V_270 ) {
T_3 V_286 [ 8 ] ;
T_8 V_275 = V_277 ;
struct V_500 * V_134 = (struct V_500 * ) V_286 ;
V_134 -> type = F_77 ( V_270 ) ;
V_134 -> V_135 = F_77 ( V_501 ) ;
if ( ! V_278 )
V_275 |= V_279 | V_280
| V_435 ;
if ( V_10 -> V_233 )
V_275 |= V_417
| V_416 ;
F_100 ( V_275 , V_134 -> V_159 ) ;
F_78 ( V_10 , V_391 -> V_16 , V_502 , sizeof( V_286 ) ,
V_286 ) ;
} else if ( type == V_503 ) {
T_3 V_286 [ 12 ] ;
struct V_500 * V_134 = (struct V_500 * ) V_286 ;
if ( V_10 -> V_233 )
V_504 [ 0 ] |= V_235 ;
else
V_504 [ 0 ] &= ~ V_235 ;
V_134 -> type = F_77 ( V_503 ) ;
V_134 -> V_135 = F_77 ( V_501 ) ;
memcpy ( V_134 -> V_159 , V_504 , sizeof( V_504 ) ) ;
F_78 ( V_10 , V_391 -> V_16 , V_502 , sizeof( V_286 ) ,
V_286 ) ;
} else {
struct V_500 V_134 ;
V_134 . type = F_16 ( type ) ;
V_134 . V_135 = F_77 ( V_505 ) ;
F_78 ( V_10 , V_391 -> V_16 , V_502 , sizeof( V_134 ) ,
& V_134 ) ;
}
return 0 ;
}
static inline int F_254 ( struct V_9 * V_10 ,
struct V_390 * V_391 , T_2 V_470 ,
T_3 * V_159 )
{
struct V_500 * V_134 = (struct V_500 * ) V_159 ;
T_2 type , V_135 ;
if ( V_470 < sizeof( * V_134 ) )
return - V_473 ;
type = F_64 ( V_134 -> type ) ;
V_135 = F_64 ( V_134 -> V_135 ) ;
F_21 ( L_53 , type , V_135 ) ;
if ( V_391 -> V_16 != V_10 -> V_271 ||
V_10 -> V_266 & V_268 )
return 0 ;
F_238 ( & V_10 -> V_272 ) ;
if ( V_135 != V_501 ) {
V_10 -> V_266 |= V_268 ;
V_10 -> V_271 = 0 ;
F_129 ( V_10 ) ;
return 0 ;
}
switch ( type ) {
case V_270 :
V_10 -> V_275 = F_94 ( V_134 -> V_159 ) ;
if ( V_10 -> V_275 & V_506 ) {
struct V_269 V_243 ;
V_243 . type = F_77 ( V_503 ) ;
V_10 -> V_271 = F_82 ( V_10 ) ;
F_78 ( V_10 , V_10 -> V_271 ,
V_274 , sizeof( V_243 ) , & V_243 ) ;
} else {
V_10 -> V_266 |= V_268 ;
V_10 -> V_271 = 0 ;
F_129 ( V_10 ) ;
}
break;
case V_503 :
V_10 -> V_234 = V_134 -> V_159 [ 0 ] ;
V_10 -> V_266 |= V_268 ;
V_10 -> V_271 = 0 ;
F_129 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_255 ( struct V_9 * V_10 ,
struct V_390 * V_391 ,
T_2 V_470 , void * V_159 )
{
struct V_246 * V_243 = V_159 ;
struct V_507 V_134 ;
struct V_8 * V_20 ;
struct V_231 * V_160 ;
T_2 V_17 , V_14 ;
if ( V_470 != sizeof( * V_243 ) )
return - V_473 ;
if ( ! V_10 -> V_233 )
return - V_26 ;
V_17 = F_230 ( V_243 -> V_17 ) ;
V_14 = F_230 ( V_243 -> V_14 ) ;
F_21 ( L_54 , V_17 , V_14 , V_243 -> V_245 ) ;
if ( V_243 -> V_245 == V_413 ) {
F_239 ( V_10 , V_391 , V_159 , V_468 ,
V_243 -> V_245 ) ;
return 0 ;
}
V_160 = F_256 ( V_243 -> V_245 ) ;
if ( ! V_160 )
goto error;
if ( V_160 -> V_508 != V_509 || ! F_71 ( V_239 , & V_160 -> V_87 ) ) {
F_167 ( V_160 ) ;
goto error;
}
V_20 = F_239 ( V_10 , V_391 , V_159 , V_468 ,
V_243 -> V_245 ) ;
if ( V_20 ) {
struct V_115 * V_116 = V_10 -> V_2 -> V_115 ;
struct V_1 * V_171 ;
V_171 = F_257 ( V_160 , V_510 ,
& V_10 -> V_2 -> V_295 ) ;
if ( ! V_171 ) {
F_167 ( V_160 ) ;
F_246 ( V_10 , V_391 -> V_16 , V_20 -> V_14 ,
V_20 -> V_13 ) ;
return 0 ;
}
F_21 ( L_55 , V_116 , V_20 , V_171 ) ;
V_116 -> V_117 = V_20 ;
V_20 -> V_171 = V_171 ;
V_20 -> V_77 = V_436 ;
V_10 -> V_325 = V_160 -> V_511 ;
}
F_167 ( V_160 ) ;
return 0 ;
error:
V_134 . V_13 = 0 ;
V_134 . V_14 = F_16 ( V_14 ) ;
V_134 . V_135 = F_77 ( V_512 ) ;
V_134 . V_140 = F_77 ( V_141 ) ;
F_78 ( V_10 , V_391 -> V_16 , V_468 ,
sizeof( V_134 ) , & V_134 ) ;
return 0 ;
}
static void F_258 ( struct V_8 * V_20 , T_3 V_513 )
{
struct V_514 V_243 ;
T_3 V_16 ;
F_21 ( L_56 , V_20 , V_513 ) ;
V_16 = F_82 ( V_20 -> V_10 ) ;
V_20 -> V_16 = V_16 ;
V_243 . V_515 = F_16 ( V_20 -> V_14 ) ;
V_243 . V_513 = V_513 ;
F_78 ( V_20 -> V_10 , V_16 , V_516 , sizeof( V_243 ) ,
& V_243 ) ;
F_75 ( V_20 , V_517 ) ;
}
static void F_259 ( struct V_8 * V_20 , T_2 V_135 )
{
struct V_518 V_134 ;
F_21 ( L_57 , V_20 , V_135 ) ;
V_134 . V_515 = F_16 ( V_20 -> V_13 ) ;
V_134 . V_135 = F_16 ( V_135 ) ;
F_78 ( V_20 -> V_10 , V_20 -> V_16 , V_519 ,
sizeof( V_134 ) , & V_134 ) ;
}
static void F_260 ( struct V_8 * V_20 , T_2 V_135 )
{
struct V_520 V_521 ;
F_21 ( L_57 , V_20 , V_135 ) ;
V_20 -> V_16 = F_82 ( V_20 -> V_10 ) ;
V_521 . V_515 = F_16 ( V_20 -> V_14 ) ;
V_521 . V_135 = F_16 ( V_135 ) ;
F_78 ( V_20 -> V_10 , V_20 -> V_16 , V_522 ,
sizeof( V_521 ) , & V_521 ) ;
F_75 ( V_20 , V_517 ) ;
}
static void F_261 ( struct V_9 * V_10 , T_2 V_515 )
{
struct V_520 V_521 ;
F_21 ( L_58 , V_10 , V_515 ) ;
V_521 . V_515 = F_16 ( V_515 ) ;
V_521 . V_135 = F_77 ( V_523 ) ;
F_78 ( V_10 , F_82 ( V_10 ) , V_522 ,
sizeof( V_521 ) , & V_521 ) ;
}
static void F_262 ( struct V_9 * V_10 , T_3 V_16 ,
T_2 V_515 )
{
struct V_524 V_134 ;
F_21 ( L_59 , V_515 ) ;
V_134 . V_515 = F_16 ( V_515 ) ;
F_78 ( V_10 , V_16 , V_525 , sizeof( V_134 ) , & V_134 ) ;
}
static void F_263 ( struct V_8 * V_20 )
{
V_20 -> V_118 = NULL ;
V_20 -> V_171 = NULL ;
}
static void F_264 ( struct V_8 * V_20 )
{
if ( V_20 -> V_29 != V_60 ) {
F_76 ( V_20 , V_285 ) ;
return;
}
switch ( V_20 -> V_258 ) {
case V_263 :
F_121 ( V_20 ) ;
F_259 ( V_20 , V_526 ) ;
break;
case V_260 :
if ( V_20 -> V_168 == V_527 ||
V_20 -> V_168 == V_528 ) {
F_121 ( V_20 ) ;
}
F_260 ( V_20 , V_523 ) ;
break;
}
}
static void F_265 ( struct V_8 * V_20 ,
struct V_119 * V_167 )
{
struct V_439 V_134 ;
V_20 -> V_118 = V_167 ;
V_20 -> V_171 -> V_318 = V_20 -> V_10 ;
F_245 ( V_20 , & V_134 , V_20 -> V_16 , 0 ) ;
if ( F_71 ( V_493 , & V_20 -> V_75 ) ) {
int V_21 ;
F_244 ( V_20 ) ;
V_21 = F_221 ( V_20 ) ;
if ( V_21 < 0 )
F_76 ( V_20 , - V_21 ) ;
else
F_123 ( V_20 ) ;
}
}
static void F_266 ( struct V_8 * V_20 ,
struct V_119 * V_167 )
{
V_20 -> V_171 = V_167 -> V_10 ;
V_20 -> V_171 -> V_318 = V_20 -> V_10 ;
F_21 ( L_60 , V_20 -> V_168 ) ;
switch ( V_20 -> V_168 ) {
case V_527 :
V_20 -> V_168 = V_529 ;
break;
case V_528 :
if ( F_71 ( V_228 , & V_20 -> V_222 ) ) {
V_20 -> V_168 = V_530 ;
} else if ( V_20 -> V_258 == V_260 ) {
V_20 -> V_168 = V_531 ;
F_260 ( V_20 , V_532 ) ;
} else if ( V_20 -> V_258 == V_263 ) {
V_20 -> V_168 = V_533 ;
F_259 ( V_20 , V_534 ) ;
}
break;
default:
F_263 ( V_20 ) ;
V_20 -> V_168 = V_169 ;
}
}
void F_267 ( struct V_8 * V_20 , struct V_119 * V_167 ,
T_3 V_140 )
{
F_21 ( L_61 , V_20 , V_167 , V_140 ) ;
if ( V_140 ) {
F_264 ( V_20 ) ;
F_263 ( V_20 ) ;
return;
}
if ( V_20 -> V_29 != V_60 ) {
if ( V_20 -> V_412 != V_413 )
F_265 ( V_20 , V_167 ) ;
} else {
F_266 ( V_20 , V_167 ) ;
}
}
void F_268 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
if ( V_20 -> V_412 == V_413 ) {
if ( V_20 -> V_240 != V_241 )
return;
V_20 -> V_258 = V_260 ;
V_20 -> V_168 = V_170 ;
} else {
V_20 -> V_258 = V_260 ;
V_20 -> V_168 = V_529 ;
V_20 -> V_414 = 0 ;
F_120 ( V_20 ) ;
F_258 ( V_20 , 0 ) ;
}
}
static void F_269 ( struct V_8 * V_20 , int V_135 ,
T_3 V_412 , T_3 V_535 )
{
F_21 ( L_62 , V_20 , F_22 ( V_20 -> V_29 ) ,
V_412 , V_535 ) ;
V_20 -> V_77 = V_436 ;
if ( V_20 -> V_29 == V_63 ) {
if ( V_135 == V_290 ) {
V_20 -> V_412 = V_412 ;
F_119 ( V_20 , V_535 ) ;
} else {
F_118 ( V_20 ) ;
}
return;
}
if ( F_113 ( V_20 ) ) {
struct V_133 V_134 ;
char V_286 [ 128 ] ;
V_134 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_134 . V_13 = F_16 ( V_20 -> V_14 ) ;
if ( V_135 == V_290 ) {
V_134 . V_135 = F_77 ( V_290 ) ;
V_134 . V_140 = F_77 ( V_141 ) ;
} else {
V_134 . V_135 = F_77 ( V_478 ) ;
V_134 . V_140 = F_77 ( V_141 ) ;
}
F_78 ( V_20 -> V_10 , V_20 -> V_16 , V_468 ,
sizeof( V_134 ) , & V_134 ) ;
if ( V_135 == V_290 ) {
F_20 ( V_20 , V_61 ) ;
F_55 ( V_292 , & V_20 -> V_75 ) ;
F_78 ( V_20 -> V_10 , F_82 ( V_20 -> V_10 ) ,
V_293 ,
F_131 ( V_20 , V_286 ) , V_286 ) ;
V_20 -> V_294 ++ ;
}
}
}
static void F_270 ( struct V_8 * V_20 , T_3 V_412 ,
T_3 V_535 )
{
F_120 ( V_20 ) ;
V_20 -> V_414 = V_412 ;
V_20 -> V_168 = V_536 ;
F_258 ( V_20 , V_535 ) ;
}
static void F_271 ( struct V_8 * V_20 , int V_135 )
{
struct V_119 * V_167 = NULL ;
if ( V_167 ) {
if ( V_167 -> V_29 == V_60 ) {
V_20 -> V_171 = V_167 -> V_10 ;
V_20 -> V_171 -> V_318 = V_20 -> V_10 ;
V_20 -> V_168 = V_533 ;
F_259 ( V_20 , V_534 ) ;
F_267 ( V_20 , V_167 , V_534 ) ;
} else {
V_20 -> V_168 = V_528 ;
}
} else {
F_259 ( V_20 , V_537 ) ;
}
}
static void F_272 ( struct V_8 * V_20 , int V_135 )
{
if ( V_20 -> V_258 == V_263 ) {
T_3 V_538 ;
if ( V_135 == - V_26 )
V_538 = V_539 ;
else
V_538 = V_537 ;
F_259 ( V_20 , V_538 ) ;
}
V_20 -> V_258 = V_259 ;
V_20 -> V_168 = V_169 ;
F_175 ( V_20 ) ;
}
void F_273 ( struct V_8 * V_20 , int V_135 )
{
T_3 V_412 = V_20 -> V_412 ;
T_3 V_535 = V_20 -> V_535 ;
F_21 ( L_63 ,
V_20 , V_135 , V_412 , V_535 ) ;
if ( V_20 -> V_29 == V_139 || V_20 -> V_29 == V_540 ) {
F_47 ( V_20 ) ;
return;
}
if ( V_20 -> V_29 != V_60 ) {
F_269 ( V_20 , V_135 , V_412 , V_535 ) ;
} else if ( V_135 != V_534 ) {
F_272 ( V_20 , V_135 ) ;
} else {
switch ( V_20 -> V_258 ) {
case V_260 :
F_270 ( V_20 , V_412 ,
V_535 ) ;
break;
case V_263 :
F_271 ( V_20 , V_135 ) ;
break;
default:
F_272 ( V_20 , V_135 ) ;
break;
}
}
}
static inline int F_274 ( struct V_9 * V_10 ,
struct V_390 * V_391 ,
T_2 V_470 , void * V_159 )
{
struct V_514 * V_243 = V_159 ;
struct V_518 V_134 ;
struct V_8 * V_20 ;
T_2 V_515 = 0 ;
T_2 V_135 = V_537 ;
if ( V_470 != sizeof( * V_243 ) )
return - V_473 ;
V_515 = F_230 ( V_243 -> V_515 ) ;
F_21 ( L_64 , V_515 , V_243 -> V_513 ) ;
if ( ! V_10 -> V_233 )
return - V_26 ;
V_20 = F_9 ( V_10 , V_515 ) ;
if ( ! V_20 ) {
V_134 . V_515 = F_16 ( V_515 ) ;
V_134 . V_135 = F_77 ( V_537 ) ;
F_78 ( V_10 , V_391 -> V_16 , V_519 ,
sizeof( V_134 ) , & V_134 ) ;
return 0 ;
}
V_20 -> V_16 = V_391 -> V_16 ;
if ( V_20 -> V_14 < V_27 ||
V_20 -> V_240 == V_541 ||
( V_20 -> V_121 != V_123 &&
V_20 -> V_121 != V_127 ) ) {
V_135 = V_537 ;
goto V_542;
}
if ( V_20 -> V_412 == V_243 -> V_513 ) {
V_135 = V_543 ;
goto V_542;
}
if ( V_243 -> V_513 != V_413 ) {
struct V_231 * V_160 ;
V_160 = F_256 ( V_243 -> V_513 ) ;
if ( ! V_160 || V_160 -> V_508 != V_509 ||
! F_71 ( V_239 , & V_160 -> V_87 ) ) {
if ( V_160 )
F_167 ( V_160 ) ;
V_135 = V_539 ;
goto V_542;
}
F_167 ( V_160 ) ;
}
if ( ( F_88 ( V_20 ) ||
V_20 -> V_258 != V_259 ) &&
F_13 ( & V_10 -> V_2 -> V_18 , & V_10 -> V_2 -> V_295 ) > 0 ) {
V_135 = V_544 ;
goto V_542;
}
V_20 -> V_258 = V_263 ;
F_120 ( V_20 ) ;
V_20 -> V_414 = V_243 -> V_513 ;
V_515 = V_20 -> V_13 ;
if ( V_243 -> V_513 == V_413 ) {
if ( F_71 ( V_228 , & V_20 -> V_222 ) ) {
V_20 -> V_168 = V_530 ;
V_135 = V_545 ;
} else {
V_20 -> V_168 = V_533 ;
V_135 = V_534 ;
}
} else {
V_20 -> V_168 = V_170 ;
V_135 = V_545 ;
}
V_542:
F_259 ( V_20 , V_135 ) ;
F_47 ( V_20 ) ;
return 0 ;
}
static void F_275 ( struct V_9 * V_10 , T_2 V_515 , T_2 V_135 )
{
struct V_8 * V_20 ;
struct V_119 * V_167 = NULL ;
V_20 = F_5 ( V_10 , V_515 ) ;
if ( ! V_20 ) {
F_261 ( V_10 , V_515 ) ;
return;
}
F_68 ( V_20 ) ;
if ( V_135 == V_545 )
F_75 ( V_20 , V_546 ) ;
switch ( V_20 -> V_168 ) {
case V_527 :
V_20 -> V_168 = V_528 ;
break;
case V_529 :
if ( V_135 == V_545 ) {
break;
} else if ( F_71 ( V_228 ,
& V_20 -> V_222 ) ) {
V_20 -> V_168 = V_530 ;
} else {
V_20 -> V_168 = V_531 ;
F_260 ( V_20 , V_532 ) ;
}
break;
case V_536 :
if ( V_135 == V_534 ) {
V_20 -> V_168 = V_528 ;
} else {
V_20 -> V_168 = V_527 ;
}
if ( ! V_167 ) {
F_260 ( V_20 , V_523 ) ;
break;
}
if ( V_167 -> V_29 != V_60 )
break;
V_20 -> V_171 = V_167 -> V_10 ;
V_20 -> V_171 -> V_318 = V_20 -> V_10 ;
if ( V_135 == V_534 ) {
F_260 ( V_20 , V_532 ) ;
} else {
V_20 -> V_168 = V_529 ;
}
F_267 ( V_20 , V_167 , V_534 ) ;
break;
default:
V_20 -> V_414 = V_20 -> V_412 ;
F_121 ( V_20 ) ;
F_260 ( V_20 , V_523 ) ;
}
F_47 ( V_20 ) ;
}
static void F_276 ( struct V_9 * V_10 , T_3 V_16 , T_2 V_515 ,
T_2 V_135 )
{
struct V_8 * V_20 ;
V_20 = F_11 ( V_10 , V_16 ) ;
if ( ! V_20 ) {
F_261 ( V_10 , V_515 ) ;
return;
}
F_68 ( V_20 ) ;
if ( V_20 -> V_258 == V_260 ) {
if ( V_135 == V_544 ) {
V_20 -> V_258 = V_263 ;
} else {
V_20 -> V_414 = V_20 -> V_412 ;
F_121 ( V_20 ) ;
}
}
F_260 ( V_20 , V_523 ) ;
F_47 ( V_20 ) ;
}
static int F_277 ( struct V_9 * V_10 ,
struct V_390 * V_391 ,
T_2 V_470 , void * V_159 )
{
struct V_518 * V_134 = V_159 ;
T_2 V_515 , V_135 ;
if ( V_470 != sizeof( * V_134 ) )
return - V_473 ;
V_515 = F_230 ( V_134 -> V_515 ) ;
V_135 = F_230 ( V_134 -> V_135 ) ;
F_21 ( L_65 , V_515 , V_135 ) ;
if ( V_135 == V_534 || V_135 == V_545 )
F_275 ( V_10 , V_515 , V_135 ) ;
else
F_276 ( V_10 , V_391 -> V_16 , V_515 , V_135 ) ;
return 0 ;
}
static int F_278 ( struct V_9 * V_10 ,
struct V_390 * V_391 ,
T_2 V_470 , void * V_159 )
{
struct V_520 * V_521 = V_159 ;
struct V_8 * V_20 ;
T_2 V_515 , V_135 ;
if ( V_470 != sizeof( * V_521 ) )
return - V_473 ;
V_515 = F_230 ( V_521 -> V_515 ) ;
V_135 = F_230 ( V_521 -> V_135 ) ;
F_21 ( L_65 , V_515 , V_135 ) ;
V_20 = F_9 ( V_10 , V_515 ) ;
if ( ! V_20 ) {
F_262 ( V_10 , V_391 -> V_16 , V_515 ) ;
return 0 ;
}
if ( V_20 -> V_168 == V_533 ) {
if ( V_135 == V_532 ) {
V_20 -> V_412 = V_20 -> V_414 ;
if ( V_20 -> V_412 == V_413 )
F_263 ( V_20 ) ;
} else {
V_20 -> V_414 = V_20 -> V_412 ;
}
F_121 ( V_20 ) ;
}
F_262 ( V_10 , V_391 -> V_16 , V_515 ) ;
F_47 ( V_20 ) ;
return 0 ;
}
static inline int F_279 ( struct V_9 * V_10 ,
struct V_390 * V_391 ,
T_2 V_470 , void * V_159 )
{
struct V_524 * V_134 = V_159 ;
struct V_8 * V_20 ;
T_2 V_515 ;
if ( V_470 != sizeof( * V_134 ) )
return - V_473 ;
V_515 = F_230 ( V_134 -> V_515 ) ;
F_21 ( L_59 , V_515 ) ;
V_20 = F_5 ( V_10 , V_515 ) ;
if ( ! V_20 )
return 0 ;
F_68 ( V_20 ) ;
if ( V_20 -> V_168 == V_531 ) {
V_20 -> V_412 = V_20 -> V_414 ;
if ( V_20 -> V_412 == V_413 && V_20 -> V_118 )
F_263 ( V_20 ) ;
F_121 ( V_20 ) ;
}
F_47 ( V_20 ) ;
return 0 ;
}
static inline int F_280 ( T_2 V_547 , T_2 V_548 , T_2 V_549 ,
T_2 V_550 )
{
T_2 V_551 ;
if ( V_547 > V_548 || V_547 < 6 || V_548 > 3200 )
return - V_26 ;
if ( V_550 < 10 || V_550 > 3200 )
return - V_26 ;
if ( V_548 >= V_550 * 8 )
return - V_26 ;
V_551 = ( V_550 * 8 / V_548 ) - 1 ;
if ( V_549 > 499 || V_549 > V_551 )
return - V_26 ;
return 0 ;
}
static inline int F_281 ( struct V_9 * V_10 ,
struct V_390 * V_391 ,
T_3 * V_159 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct F_281 * V_243 ;
struct V_552 V_134 ;
T_2 V_547 , V_548 , V_549 , V_550 , V_470 ;
int V_21 ;
if ( ! ( V_2 -> V_553 & V_554 ) )
return - V_26 ;
V_470 = F_64 ( V_391 -> V_158 ) ;
if ( V_470 != sizeof( struct F_281 ) )
return - V_473 ;
V_243 = (struct F_281 * ) V_159 ;
V_547 = F_64 ( V_243 -> V_547 ) ;
V_548 = F_64 ( V_243 -> V_548 ) ;
V_549 = F_64 ( V_243 -> V_549 ) ;
V_550 = F_64 ( V_243 -> V_550 ) ;
F_21 ( L_66 ,
V_547 , V_548 , V_549 , V_550 ) ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_21 = F_280 ( V_547 , V_548 , V_549 , V_550 ) ;
if ( V_21 )
V_134 . V_135 = F_77 ( V_555 ) ;
else
V_134 . V_135 = F_77 ( V_556 ) ;
F_78 ( V_10 , V_391 -> V_16 , V_557 ,
sizeof( V_134 ) , & V_134 ) ;
if ( ! V_21 )
F_282 ( V_2 , V_547 , V_548 , V_549 , V_550 ) ;
return 0 ;
}
static inline int F_283 ( struct V_9 * V_10 ,
struct V_390 * V_391 , T_2 V_470 ,
T_3 * V_159 )
{
int V_21 = 0 ;
switch ( V_391 -> V_157 ) {
case V_490 :
F_237 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
case V_244 :
V_21 = F_241 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
case V_142 :
case V_468 :
F_243 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
case V_293 :
V_21 = F_248 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
case V_487 :
F_249 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
case V_282 :
V_21 = F_251 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
case V_498 :
F_252 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
case V_558 :
F_78 ( V_10 , V_391 -> V_16 , V_559 , V_470 , V_159 ) ;
break;
case V_559 :
break;
case V_274 :
V_21 = F_253 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
case V_502 :
F_254 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
case V_247 :
V_21 = F_255 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
case V_516 :
V_21 = F_274 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
case V_519 :
F_277 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
case V_522 :
V_21 = F_278 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
case V_525 :
F_279 ( V_10 , V_391 , V_470 , V_159 ) ;
break;
default:
F_284 ( L_67 , V_391 -> V_157 ) ;
V_21 = - V_26 ;
break;
}
return V_21 ;
}
static inline int F_285 ( struct V_9 * V_10 ,
struct V_390 * V_391 , T_3 * V_159 )
{
switch ( V_391 -> V_157 ) {
case V_490 :
return 0 ;
case V_560 :
return F_281 ( V_10 , V_391 , V_159 ) ;
case V_557 :
return 0 ;
default:
F_284 ( L_68 , V_391 -> V_157 ) ;
return - V_26 ;
}
}
static inline void F_286 ( struct V_9 * V_10 ,
struct V_36 * V_40 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_390 * V_391 ;
T_2 V_158 ;
int V_21 ;
if ( V_2 -> type != V_3 )
goto V_561;
if ( V_40 -> V_158 < V_392 )
goto V_561;
V_391 = ( void * ) V_40 -> V_159 ;
F_95 ( V_40 , V_392 ) ;
V_158 = F_230 ( V_391 -> V_158 ) ;
F_21 ( L_69 , V_391 -> V_157 , V_158 , V_391 -> V_16 ) ;
if ( V_158 != V_40 -> V_158 || ! V_391 -> V_16 ) {
F_21 ( L_70 ) ;
goto V_561;
}
V_21 = F_285 ( V_10 , V_391 , V_40 -> V_159 ) ;
if ( V_21 ) {
struct V_471 V_472 ;
F_284 ( L_71 , V_21 ) ;
V_472 . V_59 = F_77 ( V_474 ) ;
F_78 ( V_10 , V_391 -> V_16 , V_490 ,
sizeof( V_472 ) , & V_472 ) ;
}
V_561:
F_90 ( V_40 ) ;
}
static inline void F_287 ( struct V_9 * V_10 ,
struct V_36 * V_40 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 * V_159 = V_40 -> V_159 ;
int V_158 = V_40 -> V_158 ;
struct V_390 V_391 ;
int V_21 ;
F_214 ( V_10 , V_40 ) ;
if ( V_2 -> type != V_130 )
goto V_561;
while ( V_158 >= V_392 ) {
T_2 V_470 ;
memcpy ( & V_391 , V_159 , V_392 ) ;
V_159 += V_392 ;
V_158 -= V_392 ;
V_470 = F_230 ( V_391 . V_158 ) ;
F_21 ( L_69 , V_391 . V_157 , V_470 ,
V_391 . V_16 ) ;
if ( V_470 > V_158 || ! V_391 . V_16 ) {
F_21 ( L_70 ) ;
break;
}
V_21 = F_283 ( V_10 , & V_391 , V_470 , V_159 ) ;
if ( V_21 ) {
struct V_471 V_472 ;
F_284 ( L_71 , V_21 ) ;
V_472 . V_59 = F_77 ( V_474 ) ;
F_78 ( V_10 , V_391 . V_16 , V_490 ,
sizeof( V_472 ) , & V_472 ) ;
}
V_159 += V_470 ;
V_158 -= V_470 ;
}
V_561:
F_90 ( V_40 ) ;
}
static int F_288 ( struct V_8 * V_20 , struct V_36 * V_40 )
{
T_2 V_562 , V_563 ;
int V_564 ;
if ( F_71 ( V_209 , & V_20 -> V_87 ) )
V_564 = V_214 ;
else
V_564 = V_215 ;
if ( V_20 -> V_77 == V_78 ) {
F_289 ( V_40 , V_40 -> V_158 - V_219 ) ;
V_563 = F_96 ( V_40 -> V_159 + V_40 -> V_158 ) ;
V_562 = F_107 ( 0 , V_40 -> V_159 - V_564 , V_40 -> V_158 + V_564 ) ;
if ( V_562 != V_563 )
return - V_565 ;
}
return 0 ;
}
static void F_290 ( struct V_8 * V_20 )
{
struct V_175 V_41 ;
F_21 ( L_3 , V_20 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_183 = 1 ;
V_41 . V_179 = 1 ;
V_41 . V_176 = V_20 -> V_229 ;
F_55 ( V_221 , & V_20 -> V_222 ) ;
if ( F_71 ( V_228 , & V_20 -> V_222 ) ) {
V_41 . V_187 = V_225 ;
F_108 ( V_20 , & V_41 ) ;
}
if ( F_109 ( V_257 , & V_20 -> V_222 ) &&
V_20 -> V_344 > 0 )
F_25 ( V_20 ) ;
F_175 ( V_20 ) ;
if ( ! F_71 ( V_228 , & V_20 -> V_222 ) &&
F_71 ( V_221 , & V_20 -> V_222 ) ) {
V_41 . V_187 = V_223 ;
F_108 ( V_20 , & V_41 ) ;
}
}
static void F_291 ( struct V_36 * V_40 , struct V_36 * V_566 ,
struct V_36 * * V_567 )
{
if ( ! F_292 ( V_40 ) )
F_191 ( V_40 ) -> V_355 = V_566 ;
V_566 -> V_313 = NULL ;
( * V_567 ) -> V_313 = V_566 ;
* V_567 = V_566 ;
V_40 -> V_158 += V_566 -> V_158 ;
V_40 -> V_359 += V_566 -> V_158 ;
V_40 -> V_568 += V_566 -> V_568 ;
}
static int F_293 ( struct V_8 * V_20 , struct V_36 * V_40 ,
struct V_175 * V_41 )
{
int V_21 = - V_26 ;
switch ( V_41 -> V_190 ) {
case V_368 :
if ( V_20 -> V_410 )
break;
V_21 = V_20 -> V_30 -> V_388 ( V_20 , V_40 ) ;
break;
case V_369 :
if ( V_20 -> V_410 )
break;
V_20 -> V_364 = F_96 ( V_40 -> V_159 ) ;
F_95 ( V_40 , V_362 ) ;
if ( V_20 -> V_364 > V_20 -> V_100 ) {
V_21 = - V_372 ;
break;
}
if ( V_40 -> V_158 >= V_20 -> V_364 )
break;
V_20 -> V_410 = V_40 ;
V_20 -> V_411 = V_40 ;
V_40 = NULL ;
V_21 = 0 ;
break;
case V_371 :
if ( ! V_20 -> V_410 )
break;
F_291 ( V_20 -> V_410 , V_40 ,
& V_20 -> V_411 ) ;
V_40 = NULL ;
if ( V_20 -> V_410 -> V_158 >= V_20 -> V_364 )
break;
V_21 = 0 ;
break;
case V_370 :
if ( ! V_20 -> V_410 )
break;
F_291 ( V_20 -> V_410 , V_40 ,
& V_20 -> V_411 ) ;
V_40 = NULL ;
if ( V_20 -> V_410 -> V_158 != V_20 -> V_364 )
break;
V_21 = V_20 -> V_30 -> V_388 ( V_20 , V_20 -> V_410 ) ;
if ( ! V_21 ) {
V_20 -> V_410 = NULL ;
V_20 -> V_411 = NULL ;
V_20 -> V_364 = 0 ;
}
break;
}
if ( V_21 ) {
F_90 ( V_40 ) ;
F_90 ( V_20 -> V_410 ) ;
V_20 -> V_410 = NULL ;
V_20 -> V_411 = NULL ;
V_20 -> V_364 = 0 ;
}
return V_21 ;
}
static int F_294 ( struct V_8 * V_20 )
{
return 0 ;
}
void F_295 ( struct V_8 * V_20 , int V_569 )
{
T_3 V_378 ;
if ( V_20 -> V_121 != V_123 )
return;
V_378 = V_569 ? V_379 : V_381 ;
F_122 ( V_20 , NULL , NULL , V_378 ) ;
}
static int F_296 ( struct V_8 * V_20 )
{
int V_21 = 0 ;
F_21 ( L_3 , V_20 ) ;
while ( ! F_71 ( V_228 , & V_20 -> V_222 ) ) {
struct V_36 * V_40 ;
F_21 ( L_72 ,
V_20 -> V_229 , F_179 ( & V_20 -> V_124 ) ) ;
V_40 = F_31 ( & V_20 -> V_124 , V_20 -> V_229 ) ;
if ( ! V_40 )
break;
F_207 ( V_40 , & V_20 -> V_124 ) ;
V_20 -> V_229 = F_174 ( V_20 , V_20 -> V_229 ) ;
V_21 = F_293 ( V_20 , V_40 , & F_33 ( V_40 ) -> V_41 ) ;
if ( V_21 )
break;
}
if ( F_172 ( & V_20 -> V_124 ) ) {
V_20 -> V_255 = V_348 ;
F_186 ( V_20 ) ;
}
return V_21 ;
}
static void F_297 ( struct V_8 * V_20 ,
struct V_175 * V_41 )
{
struct V_36 * V_40 ;
F_21 ( L_10 , V_20 , V_41 ) ;
if ( V_41 -> V_176 == V_20 -> V_338 ) {
F_21 ( L_73 , V_41 -> V_176 ) ;
F_76 ( V_20 , V_285 ) ;
return;
}
V_40 = F_31 ( & V_20 -> V_128 , V_41 -> V_176 ) ;
if ( V_40 == NULL ) {
F_21 ( L_74 ,
V_41 -> V_176 ) ;
return;
}
if ( V_20 -> V_79 != 0 && F_33 ( V_40 ) -> V_41 . V_249 >= V_20 -> V_79 ) {
F_21 ( L_23 , V_20 -> V_79 ) ;
F_76 ( V_20 , V_285 ) ;
return;
}
F_110 ( V_257 , & V_20 -> V_222 ) ;
if ( V_41 -> V_184 ) {
F_212 ( V_20 , V_41 ) ;
F_55 ( V_221 , & V_20 -> V_222 ) ;
F_183 ( V_20 , V_41 ) ;
F_175 ( V_20 ) ;
if ( V_20 -> V_253 == V_383 ) {
F_55 ( V_252 , & V_20 -> V_222 ) ;
V_20 -> V_570 = V_41 -> V_176 ;
}
} else {
F_213 ( V_20 , V_41 ) ;
if ( V_41 -> V_179 ) {
if ( V_20 -> V_570 != V_41 -> V_176 ||
! F_109 ( V_252 ,
& V_20 -> V_222 ) )
F_183 ( V_20 , V_41 ) ;
} else {
F_183 ( V_20 , V_41 ) ;
if ( V_20 -> V_253 == V_383 ) {
F_55 ( V_252 , & V_20 -> V_222 ) ;
V_20 -> V_570 = V_41 -> V_176 ;
}
}
}
}
static void F_298 ( struct V_8 * V_20 ,
struct V_175 * V_41 )
{
struct V_36 * V_40 ;
F_21 ( L_10 , V_20 , V_41 ) ;
if ( V_41 -> V_176 == V_20 -> V_338 ) {
F_21 ( L_73 , V_41 -> V_176 ) ;
F_76 ( V_20 , V_285 ) ;
return;
}
V_40 = F_31 ( & V_20 -> V_128 , V_41 -> V_176 ) ;
if ( V_20 -> V_79 && V_40 &&
F_33 ( V_40 ) -> V_41 . V_249 >= V_20 -> V_79 ) {
F_21 ( L_23 , V_20 -> V_79 ) ;
F_76 ( V_20 , V_285 ) ;
return;
}
F_110 ( V_257 , & V_20 -> V_222 ) ;
F_212 ( V_20 , V_41 ) ;
if ( V_41 -> V_179 ) {
if ( ! F_109 ( V_251 , & V_20 -> V_222 ) )
F_184 ( V_20 , V_41 ) ;
} else {
F_184 ( V_20 , V_41 ) ;
F_175 ( V_20 ) ;
if ( V_20 -> V_253 == V_383 )
F_55 ( V_251 , & V_20 -> V_222 ) ;
}
}
static T_3 F_299 ( struct V_8 * V_20 , T_2 V_42 )
{
F_21 ( L_75 , V_20 , V_42 ) ;
F_21 ( L_76 , V_20 -> V_227 ,
V_20 -> V_250 ) ;
if ( V_20 -> V_255 == V_380 ) {
if ( F_187 ( V_20 , V_42 , V_20 -> V_227 ) >=
V_20 -> V_81 ) {
if ( V_20 -> V_81 <= ( ( V_20 -> V_83 + 1 ) >> 1 ) ) {
F_21 ( L_77 ) ;
return V_571 ;
} else {
F_21 ( L_78 ) ;
return V_572 ;
}
}
if ( V_20 -> V_125 . V_38 == V_42 ) {
F_21 ( L_79 ) ;
return V_573 ;
}
if ( F_31 ( & V_20 -> V_124 , V_42 ) ) {
F_21 ( L_80 ) ;
return V_574 ;
}
if ( F_39 ( & V_20 -> V_125 , V_42 ) ) {
F_21 ( L_81 ) ;
return V_575 ;
}
}
if ( V_20 -> V_250 == V_42 ) {
if ( F_187 ( V_20 , V_42 , V_20 -> V_227 ) >=
V_20 -> V_81 ) {
F_21 ( L_82 ) ;
return V_572 ;
} else {
F_21 ( L_83 ) ;
return V_576 ;
}
}
if ( F_187 ( V_20 , V_42 , V_20 -> V_227 ) <
F_187 ( V_20 , V_20 -> V_250 , V_20 -> V_227 ) ) {
F_21 ( L_84 ) ;
return V_577 ;
}
if ( F_187 ( V_20 , V_42 , V_20 -> V_227 ) >= V_20 -> V_81 ) {
if ( V_20 -> V_81 <= ( ( V_20 -> V_83 + 1 ) >> 1 ) ) {
F_21 ( L_85 ) ;
return V_571 ;
} else {
F_21 ( L_82 ) ;
return V_572 ;
}
} else {
F_21 ( L_86 ) ;
return V_578 ;
}
}
static int F_300 ( struct V_8 * V_20 ,
struct V_175 * V_41 ,
struct V_36 * V_40 , T_3 V_378 )
{
int V_21 = 0 ;
bool V_579 = false ;
F_21 ( L_87 , V_20 , V_41 , V_40 ,
V_378 ) ;
switch ( V_378 ) {
case V_580 :
switch ( F_299 ( V_20 , V_41 -> V_42 ) ) {
case V_576 :
F_212 ( V_20 , V_41 ) ;
if ( F_71 ( V_228 , & V_20 -> V_222 ) ) {
F_21 ( L_88 ,
V_41 -> V_42 ) ;
break;
}
V_20 -> V_250 = F_174 ( V_20 ,
V_41 -> V_42 ) ;
V_20 -> V_229 = V_20 -> V_250 ;
V_579 = true ;
V_21 = F_293 ( V_20 , V_40 , V_41 ) ;
if ( V_21 )
break;
if ( V_41 -> V_179 ) {
if ( ! F_109 ( V_251 ,
& V_20 -> V_222 ) ) {
V_41 -> V_179 = 0 ;
F_184 ( V_20 , V_41 ) ;
F_175 ( V_20 ) ;
}
}
if ( ! F_71 ( V_228 , & V_20 -> V_222 ) )
F_186 ( V_20 ) ;
break;
case V_578 :
F_212 ( V_20 , V_41 ) ;
if ( F_71 ( V_228 , & V_20 -> V_222 ) ) {
F_21 ( L_89 ,
V_41 -> V_42 ) ;
break;
}
F_301 ( & V_20 -> V_124 , V_40 ) ;
V_579 = true ;
F_21 ( L_90 , V_40 ,
F_179 ( & V_20 -> V_124 ) ) ;
F_110 ( V_252 , & V_20 -> V_222 ) ;
F_42 ( & V_20 -> V_125 ) ;
F_203 ( V_20 , V_41 -> V_42 ) ;
V_20 -> V_255 = V_380 ;
break;
case V_577 :
F_212 ( V_20 , V_41 ) ;
break;
case V_571 :
break;
case V_572 :
default:
F_76 ( V_20 , V_285 ) ;
break;
}
break;
case V_581 :
F_212 ( V_20 , V_41 ) ;
if ( V_41 -> V_179 ) {
F_110 ( V_257 , & V_20 -> V_222 ) ;
if ( ! F_109 ( V_251 , & V_20 -> V_222 ) &&
! F_88 ( V_20 ) ) {
V_41 -> V_179 = 0 ;
F_184 ( V_20 , V_41 ) ;
}
F_175 ( V_20 ) ;
} else if ( V_41 -> V_184 ) {
F_290 ( V_20 ) ;
} else {
if ( F_109 ( V_257 ,
& V_20 -> V_222 ) &&
V_20 -> V_344 )
F_25 ( V_20 ) ;
F_175 ( V_20 ) ;
}
break;
case V_582 :
F_55 ( V_257 , & V_20 -> V_222 ) ;
F_212 ( V_20 , V_41 ) ;
if ( V_41 && V_41 -> V_184 ) {
F_55 ( V_221 , & V_20 -> V_222 ) ;
F_112 ( V_20 , 0 ) ;
}
F_30 ( V_20 ) ;
F_42 ( & V_20 -> V_126 ) ;
break;
case V_583 :
F_298 ( V_20 , V_41 ) ;
break;
case V_584 :
F_297 ( V_20 , V_41 ) ;
break;
default:
break;
}
if ( V_40 && ! V_579 ) {
F_21 ( L_91 , V_40 ) ;
F_90 ( V_40 ) ;
}
return V_21 ;
}
static int F_302 ( struct V_8 * V_20 ,
struct V_175 * V_41 ,
struct V_36 * V_40 , T_3 V_378 )
{
int V_21 = 0 ;
T_2 V_42 = V_41 -> V_42 ;
bool V_579 = false ;
F_21 ( L_87 , V_20 , V_41 , V_40 ,
V_378 ) ;
switch ( V_378 ) {
case V_580 :
switch ( F_299 ( V_20 , V_42 ) ) {
case V_576 :
F_212 ( V_20 , V_41 ) ;
F_301 ( & V_20 -> V_124 , V_40 ) ;
V_579 = true ;
F_21 ( L_90 , V_40 ,
F_179 ( & V_20 -> V_124 ) ) ;
V_20 -> V_250 = F_174 ( V_20 , V_42 ) ;
break;
case V_573 :
F_41 ( & V_20 -> V_125 ) ;
F_212 ( V_20 , V_41 ) ;
F_301 ( & V_20 -> V_124 , V_40 ) ;
V_579 = true ;
F_21 ( L_90 , V_40 ,
F_179 ( & V_20 -> V_124 ) ) ;
V_21 = F_296 ( V_20 ) ;
if ( V_21 )
break;
break;
case V_578 :
F_301 ( & V_20 -> V_124 , V_40 ) ;
V_579 = true ;
F_21 ( L_90 , V_40 ,
F_179 ( & V_20 -> V_124 ) ) ;
F_212 ( V_20 , V_41 ) ;
F_203 ( V_20 , V_41 -> V_42 ) ;
break;
case V_575 :
F_301 ( & V_20 -> V_124 , V_40 ) ;
V_579 = true ;
F_21 ( L_90 , V_40 ,
F_179 ( & V_20 -> V_124 ) ) ;
F_212 ( V_20 , V_41 ) ;
F_205 ( V_20 , V_41 -> V_42 ) ;
break;
case V_574 :
F_212 ( V_20 , V_41 ) ;
break;
case V_577 :
break;
case V_571 :
break;
case V_572 :
default:
F_76 ( V_20 , V_285 ) ;
break;
}
break;
case V_581 :
F_212 ( V_20 , V_41 ) ;
if ( V_41 -> V_179 ) {
F_110 ( V_257 , & V_20 -> V_222 ) ;
if ( ! F_109 ( V_251 ,
& V_20 -> V_222 ) ) {
V_41 -> V_179 = 0 ;
F_184 ( V_20 , V_41 ) ;
}
F_175 ( V_20 ) ;
} else if ( V_41 -> V_184 ) {
if ( F_109 ( V_257 ,
& V_20 -> V_222 ) &&
V_20 -> V_344 ) {
F_25 ( V_20 ) ;
}
F_55 ( V_221 , & V_20 -> V_222 ) ;
F_204 ( V_20 ) ;
} else {
if ( F_109 ( V_257 ,
& V_20 -> V_222 ) &&
V_20 -> V_344 )
F_25 ( V_20 ) ;
F_186 ( V_20 ) ;
}
break;
case V_582 :
F_55 ( V_257 , & V_20 -> V_222 ) ;
F_212 ( V_20 , V_41 ) ;
if ( V_41 -> V_184 ) {
F_204 ( V_20 ) ;
} else {
struct V_175 V_585 ;
memset ( & V_585 , 0 , sizeof( V_585 ) ) ;
V_585 . V_183 = 1 ;
V_585 . V_187 = V_223 ;
V_585 . V_176 = V_20 -> V_229 ;
F_108 ( V_20 , & V_585 ) ;
}
break;
case V_583 :
F_298 ( V_20 , V_41 ) ;
break;
case V_584 :
F_297 ( V_20 , V_41 ) ;
break;
}
if ( V_40 && ! V_579 ) {
F_21 ( L_91 , V_40 ) ;
F_90 ( V_40 ) ;
}
return V_21 ;
}
static int F_303 ( struct V_8 * V_20 )
{
F_21 ( L_3 , V_20 ) ;
V_20 -> V_255 = V_348 ;
if ( V_20 -> V_171 )
V_20 -> V_10 -> V_325 = V_20 -> V_171 -> V_160 -> V_511 ;
else
V_20 -> V_10 -> V_325 = V_20 -> V_10 -> V_2 -> V_160 -> V_326 ;
return F_294 ( V_20 ) ;
}
static int F_304 ( struct V_8 * V_20 ,
struct V_175 * V_41 ,
struct V_36 * V_40 , T_3 V_378 )
{
int V_21 ;
F_21 ( L_87 , V_20 , V_41 , V_40 ,
V_378 ) ;
if ( ! V_41 -> V_184 )
return - V_473 ;
F_206 ( V_20 , V_41 -> V_176 ) ;
if ( ! F_172 ( & V_20 -> V_128 ) )
V_20 -> V_343 = F_210 ( & V_20 -> V_128 ) ;
else
V_20 -> V_343 = NULL ;
V_20 -> V_338 = V_41 -> V_176 ;
V_20 -> V_344 = 0 ;
V_21 = F_303 ( V_20 ) ;
if ( V_21 )
return V_21 ;
F_55 ( V_221 , & V_20 -> V_222 ) ;
F_290 ( V_20 ) ;
if ( V_378 == V_580 )
return - V_473 ;
return F_300 ( V_20 , V_41 , NULL , V_378 ) ;
}
static int F_305 ( struct V_8 * V_20 ,
struct V_175 * V_41 ,
struct V_36 * V_40 , T_3 V_378 )
{
int V_21 ;
if ( ! V_41 -> V_179 )
return - V_473 ;
F_110 ( V_257 , & V_20 -> V_222 ) ;
V_20 -> V_255 = V_348 ;
F_206 ( V_20 , V_41 -> V_176 ) ;
if ( ! F_172 ( & V_20 -> V_128 ) )
V_20 -> V_343 = F_210 ( & V_20 -> V_128 ) ;
else
V_20 -> V_343 = NULL ;
V_20 -> V_338 = V_41 -> V_176 ;
V_20 -> V_344 = 0 ;
if ( V_20 -> V_171 )
V_20 -> V_10 -> V_325 = V_20 -> V_171 -> V_160 -> V_511 ;
else
V_20 -> V_10 -> V_325 = V_20 -> V_10 -> V_2 -> V_160 -> V_326 ;
V_21 = F_294 ( V_20 ) ;
if ( ! V_21 )
V_21 = F_300 ( V_20 , V_41 , V_40 , V_378 ) ;
return V_21 ;
}
static bool F_306 ( struct V_8 * V_20 , T_2 V_176 )
{
T_2 V_586 ;
V_586 = F_187 ( V_20 , V_20 -> V_338 , V_20 -> V_377 ) ;
return F_187 ( V_20 , V_20 -> V_338 , V_176 ) <= V_586 ;
}
static int F_307 ( struct V_8 * V_20 , struct V_175 * V_41 ,
struct V_36 * V_40 , T_3 V_378 )
{
int V_21 = 0 ;
F_21 ( L_92 , V_20 ,
V_41 , V_40 , V_378 , V_20 -> V_255 ) ;
if ( F_306 ( V_20 , V_41 -> V_176 ) ) {
switch ( V_20 -> V_255 ) {
case V_348 :
V_21 = F_300 ( V_20 , V_41 , V_40 , V_378 ) ;
break;
case V_380 :
V_21 = F_302 ( V_20 , V_41 , V_40 ,
V_378 ) ;
break;
case V_264 :
V_21 = F_304 ( V_20 , V_41 , V_40 , V_378 ) ;
break;
case V_262 :
V_21 = F_305 ( V_20 , V_41 , V_40 , V_378 ) ;
break;
default:
break;
}
} else {
F_21 ( L_93 ,
V_41 -> V_176 , V_20 -> V_338 ,
V_20 -> V_377 ) ;
F_76 ( V_20 , V_285 ) ;
}
return V_21 ;
}
static int F_308 ( struct V_8 * V_20 , struct V_175 * V_41 ,
struct V_36 * V_40 )
{
int V_21 = 0 ;
F_21 ( L_94 , V_20 , V_41 , V_40 ,
V_20 -> V_255 ) ;
if ( F_299 ( V_20 , V_41 -> V_42 ) ==
V_576 ) {
F_212 ( V_20 , V_41 ) ;
F_21 ( L_95 , V_20 -> V_229 ,
F_174 ( V_20 , V_20 -> V_229 ) ) ;
V_20 -> V_229 = F_174 ( V_20 , V_20 -> V_229 ) ;
F_293 ( V_20 , V_40 , V_41 ) ;
} else {
if ( V_20 -> V_410 ) {
F_90 ( V_20 -> V_410 ) ;
V_20 -> V_410 = NULL ;
}
V_20 -> V_411 = NULL ;
V_20 -> V_364 = 0 ;
if ( V_40 ) {
F_21 ( L_91 , V_40 ) ;
F_90 ( V_40 ) ;
}
}
V_20 -> V_227 = V_41 -> V_42 ;
V_20 -> V_250 = F_174 ( V_20 , V_41 -> V_42 ) ;
return V_21 ;
}
static int F_309 ( struct V_8 * V_20 , struct V_36 * V_40 )
{
struct V_175 * V_41 = & F_33 ( V_40 ) -> V_41 ;
T_2 V_158 ;
T_3 V_378 ;
F_93 ( V_20 , V_40 ) ;
V_158 = V_40 -> V_158 ;
if ( F_288 ( V_20 , V_40 ) )
goto V_561;
if ( ! V_41 -> V_183 && V_41 -> V_190 == V_369 )
V_158 -= V_362 ;
if ( V_20 -> V_77 == V_78 )
V_158 -= V_219 ;
if ( V_158 > V_20 -> V_466 ) {
F_76 ( V_20 , V_285 ) ;
goto V_561;
}
if ( ! V_41 -> V_183 ) {
int V_21 ;
F_21 ( L_96 ,
V_41 -> V_190 , V_41 -> V_176 , V_41 -> V_179 ,
V_41 -> V_42 ) ;
if ( V_41 -> V_179 && V_20 -> V_253 != V_383 )
goto V_561;
if ( V_20 -> V_121 != V_127 ) {
V_378 = V_580 ;
V_21 = F_307 ( V_20 , V_41 , V_40 , V_378 ) ;
} else {
V_21 = F_308 ( V_20 , V_41 , V_40 ) ;
}
if ( V_21 )
F_76 ( V_20 , V_285 ) ;
} else {
const T_3 V_587 [ 4 ] = {
V_581 , V_583 ,
V_582 , V_584
} ;
if ( V_20 -> V_121 == V_127 )
goto V_561;
F_21 ( L_97 ,
V_41 -> V_176 , V_41 -> V_179 , V_41 -> V_184 ,
V_41 -> V_187 ) ;
if ( V_158 != 0 ) {
F_284 ( L_98 , V_158 ) ;
F_76 ( V_20 , V_285 ) ;
goto V_561;
}
if ( V_41 -> V_179 && ( V_41 -> V_184 ||
V_20 -> V_253 != V_383 ) )
goto V_561;
V_378 = V_587 [ V_41 -> V_187 ] ;
if ( F_307 ( V_20 , V_41 , V_40 , V_378 ) )
F_76 ( V_20 , V_285 ) ;
}
return 0 ;
V_561:
F_90 ( V_40 ) ;
return 0 ;
}
static void F_310 ( struct V_9 * V_10 , T_2 V_11 ,
struct V_36 * V_40 )
{
struct V_8 * V_20 ;
V_20 = F_5 ( V_10 , V_11 ) ;
if ( ! V_20 ) {
if ( V_11 == V_98 ) {
V_20 = F_311 ( V_10 , V_40 ) ;
if ( ! V_20 ) {
F_90 ( V_40 ) ;
return;
}
F_7 ( V_20 ) ;
} else {
F_21 ( L_99 , V_11 ) ;
F_90 ( V_40 ) ;
return;
}
}
F_21 ( L_100 , V_20 , V_40 -> V_158 ) ;
if ( V_20 -> V_29 != V_60 )
goto V_561;
switch ( V_20 -> V_121 ) {
case V_122 :
if ( V_20 -> V_100 < V_40 -> V_158 )
goto V_561;
if ( ! V_20 -> V_30 -> V_388 ( V_20 , V_40 ) )
goto V_24;
break;
case V_123 :
case V_127 :
F_309 ( V_20 , V_40 ) ;
goto V_24;
default:
F_21 ( L_101 , V_20 , V_20 -> V_121 ) ;
break;
}
V_561:
F_90 ( V_40 ) ;
V_24:
F_47 ( V_20 ) ;
}
static void F_312 ( struct V_9 * V_10 , T_4 V_17 ,
struct V_36 * V_40 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 ;
if ( V_2 -> type != V_130 )
goto V_561;
V_20 = F_161 ( 0 , V_17 , & V_2 -> V_18 , & V_2 -> V_295 ) ;
if ( ! V_20 )
goto V_561;
F_21 ( L_100 , V_20 , V_40 -> V_158 ) ;
if ( V_20 -> V_29 != V_332 && V_20 -> V_29 != V_60 )
goto V_561;
if ( V_20 -> V_100 < V_40 -> V_158 )
goto V_561;
F_135 ( & F_33 ( V_40 ) -> V_588 , & V_2 -> V_295 ) ;
F_33 ( V_40 ) -> V_17 = V_17 ;
if ( ! V_20 -> V_30 -> V_388 ( V_20 , V_40 ) )
return;
V_561:
F_90 ( V_40 ) ;
}
static void F_313 ( struct V_9 * V_10 ,
struct V_36 * V_40 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_8 * V_20 ;
if ( V_2 -> type != V_3 )
goto V_561;
V_20 = F_132 ( V_60 , V_94 ,
& V_2 -> V_18 , & V_2 -> V_295 ) ;
if ( ! V_20 )
goto V_561;
F_21 ( L_100 , V_20 , V_40 -> V_158 ) ;
if ( F_134 ( V_2 -> V_160 , & V_2 -> V_295 , V_2 -> V_303 ) )
goto V_561;
if ( V_20 -> V_100 < V_40 -> V_158 )
goto V_561;
if ( ! V_20 -> V_30 -> V_388 ( V_20 , V_40 ) )
return;
V_561:
F_90 ( V_40 ) ;
}
static void F_314 ( struct V_9 * V_10 , struct V_36 * V_40 )
{
struct V_216 * V_217 = ( void * ) V_40 -> V_159 ;
T_2 V_11 , V_158 ;
T_4 V_17 ;
F_95 ( V_40 , V_213 ) ;
V_11 = F_64 ( V_217 -> V_11 ) ;
V_158 = F_64 ( V_217 -> V_158 ) ;
if ( V_158 != V_40 -> V_158 ) {
F_90 ( V_40 ) ;
return;
}
F_21 ( L_102 , V_158 , V_11 ) ;
switch ( V_11 ) {
case V_101 :
F_287 ( V_10 , V_40 ) ;
break;
case V_96 :
V_17 = F_315 ( ( T_4 * ) V_40 -> V_159 ) ;
F_95 ( V_40 , V_360 ) ;
F_312 ( V_10 , V_17 , V_40 ) ;
break;
case V_94 :
F_313 ( V_10 , V_40 ) ;
break;
case V_393 :
F_286 ( V_10 , V_40 ) ;
break;
case V_589 :
if ( F_316 ( V_10 , V_40 ) )
F_147 ( V_10 -> V_2 , V_590 ) ;
break;
default:
F_310 ( V_10 , V_11 , V_40 ) ;
break;
}
}
int F_317 ( struct V_231 * V_160 , T_5 * V_588 )
{
int V_591 = 0 , V_592 = 0 , V_593 = 0 ;
struct V_8 * V_12 ;
F_21 ( L_103 , V_160 -> V_594 , V_588 ) ;
F_115 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
if ( V_12 -> V_29 != V_129 )
continue;
if ( ! F_13 ( & V_12 -> V_18 , & V_160 -> V_588 ) ) {
V_592 |= V_595 ;
if ( F_71 ( V_596 , & V_12 -> V_87 ) )
V_592 |= V_554 ;
V_591 ++ ;
} else if ( ! F_13 ( & V_12 -> V_18 , V_301 ) ) {
V_593 |= V_595 ;
if ( F_71 ( V_596 , & V_12 -> V_87 ) )
V_593 |= V_554 ;
}
}
F_116 ( & V_22 ) ;
return V_591 ? V_592 : V_593 ;
}
void F_318 ( struct V_1 * V_2 , T_3 V_140 )
{
struct V_9 * V_10 ;
F_21 ( L_104 , V_2 , & V_2 -> V_295 , V_140 ) ;
if ( ! V_140 ) {
V_10 = F_153 ( V_2 ) ;
if ( V_10 )
F_136 ( V_10 ) ;
} else {
F_147 ( V_2 , F_319 ( V_140 ) ) ;
}
}
int F_320 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_318 ;
F_21 ( L_105 , V_2 ) ;
if ( ! V_10 )
return V_89 ;
return V_10 -> V_88 ;
}
void F_321 ( struct V_1 * V_2 , T_3 V_59 )
{
F_21 ( L_106 , V_2 , V_59 ) ;
F_147 ( V_2 , F_319 ( V_59 ) ) ;
}
static inline void F_322 ( struct V_8 * V_20 , T_3 V_597 )
{
if ( V_20 -> V_90 != V_91 )
return;
if ( V_597 == 0x00 ) {
if ( V_20 -> V_64 == V_146 ) {
F_75 ( V_20 , V_598 ) ;
} else if ( V_20 -> V_64 == V_144 )
F_46 ( V_20 , V_62 ) ;
} else {
if ( V_20 -> V_64 == V_146 )
F_68 ( V_20 ) ;
}
}
int F_323 ( struct V_1 * V_2 , T_3 V_140 , T_3 V_597 )
{
struct V_9 * V_10 = V_2 -> V_318 ;
struct V_8 * V_20 ;
if ( ! V_10 )
return 0 ;
F_21 ( L_107 , V_10 , V_140 , V_597 ) ;
if ( V_2 -> type == V_3 ) {
if ( ! V_140 && V_597 )
F_324 ( V_10 , 0 ) ;
F_238 ( & V_10 -> V_322 ) ;
}
F_6 ( & V_10 -> V_15 ) ;
F_3 (chan, &conn->chan_l, list) {
F_7 ( V_20 ) ;
F_21 ( L_108 , V_20 , V_20 -> V_14 ,
F_22 ( V_20 -> V_29 ) ) ;
if ( V_20 -> V_90 == V_97 ) {
F_47 ( V_20 ) ;
continue;
}
if ( V_20 -> V_14 == V_94 ) {
if ( ! V_140 && V_597 ) {
V_20 -> V_64 = V_2 -> V_64 ;
F_123 ( V_20 ) ;
}
F_47 ( V_20 ) ;
continue;
}
if ( ! F_113 ( V_20 ) ) {
F_47 ( V_20 ) ;
continue;
}
if ( ! V_140 && ( V_20 -> V_29 == V_60 ||
V_20 -> V_29 == V_61 ) ) {
V_20 -> V_30 -> V_599 ( V_20 ) ;
F_322 ( V_20 , V_597 ) ;
F_47 ( V_20 ) ;
continue;
}
if ( V_20 -> V_29 == V_63 ) {
if ( ! V_140 ) {
F_124 ( V_20 ) ;
} else {
F_75 ( V_20 , V_600 ) ;
}
} else if ( V_20 -> V_29 == V_132 ) {
struct V_133 V_134 ;
T_6 V_601 , V_602 ;
if ( ! V_140 ) {
if ( F_71 ( V_136 , & V_20 -> V_87 ) ) {
V_601 = V_287 ;
V_602 = V_288 ;
V_20 -> V_30 -> V_289 ( V_20 ) ;
} else {
F_20 ( V_20 , V_61 ) ;
V_601 = V_290 ;
V_602 = V_141 ;
}
} else {
F_20 ( V_20 , V_139 ) ;
F_75 ( V_20 , V_600 ) ;
V_601 = V_137 ;
V_602 = V_141 ;
}
V_134 . V_14 = F_16 ( V_20 -> V_13 ) ;
V_134 . V_13 = F_16 ( V_20 -> V_14 ) ;
V_134 . V_135 = F_16 ( V_601 ) ;
V_134 . V_140 = F_16 ( V_602 ) ;
F_78 ( V_10 , V_20 -> V_16 , V_142 ,
sizeof( V_134 ) , & V_134 ) ;
if ( ! F_71 ( V_292 , & V_20 -> V_75 ) &&
V_601 == V_290 ) {
char V_286 [ 128 ] ;
F_55 ( V_292 , & V_20 -> V_75 ) ;
F_78 ( V_10 , F_82 ( V_10 ) ,
V_293 ,
F_131 ( V_20 , V_286 ) ,
V_286 ) ;
V_20 -> V_294 ++ ;
}
}
F_47 ( V_20 ) ;
}
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
int F_325 ( struct V_1 * V_2 , struct V_36 * V_40 , T_2 V_87 )
{
struct V_9 * V_10 = V_2 -> V_318 ;
struct V_216 * V_603 ;
int V_158 ;
if ( ! V_10 && V_2 -> V_160 -> V_508 != V_604 )
goto V_561;
if ( ! V_10 )
V_10 = F_153 ( V_2 ) ;
if ( ! V_10 )
goto V_561;
F_21 ( L_109 , V_10 , V_40 -> V_158 , V_87 ) ;
switch ( V_87 ) {
case V_162 :
case V_161 :
case V_172 :
if ( V_10 -> V_605 ) {
F_284 ( L_110 , V_40 -> V_158 ) ;
F_90 ( V_10 -> V_320 ) ;
V_10 -> V_320 = NULL ;
V_10 -> V_605 = 0 ;
F_138 ( V_10 , V_606 ) ;
}
if ( V_40 -> V_158 < V_213 ) {
F_284 ( L_111 , V_40 -> V_158 ) ;
F_138 ( V_10 , V_606 ) ;
goto V_561;
}
V_603 = (struct V_216 * ) V_40 -> V_159 ;
V_158 = F_64 ( V_603 -> V_158 ) + V_213 ;
if ( V_158 == V_40 -> V_158 ) {
F_314 ( V_10 , V_40 ) ;
return 0 ;
}
F_21 ( L_112 , V_158 , V_40 -> V_158 ) ;
if ( V_40 -> V_158 > V_158 ) {
F_284 ( L_113 ,
V_40 -> V_158 , V_158 ) ;
F_138 ( V_10 , V_606 ) ;
goto V_561;
}
V_10 -> V_320 = F_104 ( V_158 , V_49 ) ;
if ( ! V_10 -> V_320 )
goto V_561;
F_326 ( V_40 , F_106 ( V_10 -> V_320 , V_40 -> V_158 ) ,
V_40 -> V_158 ) ;
V_10 -> V_605 = V_158 - V_40 -> V_158 ;
break;
case V_607 :
F_21 ( L_114 , V_40 -> V_158 , V_10 -> V_605 ) ;
if ( ! V_10 -> V_605 ) {
F_284 ( L_115 , V_40 -> V_158 ) ;
F_138 ( V_10 , V_606 ) ;
goto V_561;
}
if ( V_40 -> V_158 > V_10 -> V_605 ) {
F_284 ( L_116 ,
V_40 -> V_158 , V_10 -> V_605 ) ;
F_90 ( V_10 -> V_320 ) ;
V_10 -> V_320 = NULL ;
V_10 -> V_605 = 0 ;
F_138 ( V_10 , V_606 ) ;
goto V_561;
}
F_326 ( V_40 , F_106 ( V_10 -> V_320 , V_40 -> V_158 ) ,
V_40 -> V_158 ) ;
V_10 -> V_605 -= V_40 -> V_158 ;
if ( ! V_10 -> V_605 ) {
struct V_36 * V_320 = V_10 -> V_320 ;
V_10 -> V_320 = NULL ;
F_314 ( V_10 , V_320 ) ;
}
break;
}
V_561:
F_90 ( V_40 ) ;
return 0 ;
}
static int F_327 ( struct V_608 * V_609 , void * V_25 )
{
struct V_8 * V_12 ;
F_115 ( & V_22 ) ;
F_3 (c, &chan_list, global_l) {
F_328 ( V_609 , L_117 ,
& V_12 -> V_18 , & V_12 -> V_295 ,
V_12 -> V_29 , F_64 ( V_12 -> V_17 ) ,
V_12 -> V_14 , V_12 -> V_13 , V_12 -> V_100 , V_12 -> V_92 ,
V_12 -> V_64 , V_12 -> V_121 ) ;
}
F_116 ( & V_22 ) ;
return 0 ;
}
static int F_329 ( struct V_610 * V_610 , struct V_611 * V_611 )
{
return F_330 ( V_611 , F_327 , V_610 -> V_612 ) ;
}
int T_11 F_331 ( void )
{
int V_21 ;
V_21 = F_332 () ;
if ( V_21 < 0 )
return V_21 ;
if ( F_333 ( V_613 ) )
return 0 ;
V_614 = F_334 ( L_118 , 0444 , V_613 ,
NULL , & V_615 ) ;
return 0 ;
}
void F_335 ( void )
{
F_336 ( V_614 ) ;
F_337 () ;
}
