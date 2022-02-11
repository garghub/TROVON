static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_3 ( V_4 -> V_9 , V_10 , sizeof( V_4 -> V_9 ) ) ;
F_3 ( V_4 -> V_11 , V_12 L_1 V_13 L_2 ,
sizeof( V_4 -> V_11 ) ) ;
snprintf ( V_4 -> V_14 , sizeof( V_4 -> V_14 ) ,
L_3 ,
F_4 ( V_8 ) , F_5 ( V_8 ) , F_6 ( V_8 ) ) ;
F_3 ( V_4 -> V_15 , F_7 ( V_8 -> V_16 ) ,
sizeof( V_4 -> V_15 ) ) ;
}
void F_8 ( void )
{
F_9 ( V_17 , V_18 ,
V_19 ) ;
F_9 ( V_20 , V_18 ,
V_19 ) ;
F_9 ( V_21 , V_22 ,
V_23 ) ;
F_9 ( V_24 , V_22 ,
V_23 ) ;
F_9 ( V_25 , V_22 ,
V_26 ) ;
F_9 ( V_27 , V_28 ,
V_29 ) ;
F_9 ( V_30 , V_31 ,
V_32 ) ;
F_9 ( V_33 , V_31 ,
V_34 ) ;
F_9 ( V_35 , V_36 ,
V_37 ) ;
F_9 ( V_38 , V_22 ,
V_26 ) ;
F_9 ( V_39 , V_22 ,
V_26 ) ;
F_9 ( V_40 , V_22 ,
V_26 ) ;
F_9 ( V_41 , V_31 ,
V_42 ) ;
F_9 ( V_43 , V_31 ,
V_44 ) ;
F_9 ( V_45 , V_46 ,
V_47 ) ;
F_9 ( V_48 , V_49 ,
V_50 ) ;
F_9 ( V_51 , V_49 ,
V_52 ) ;
F_9 ( V_53 , V_49 ,
V_54 ) ;
F_9 ( V_55 , V_49 ,
V_56 ) ;
F_9 ( V_57 , V_22 ,
V_58 ) ;
F_9 ( V_59 , V_60 ,
V_61 ) ;
F_9 ( V_62 , V_60 ,
V_63 ) ;
F_9 ( V_64 , V_60 ,
V_65 ) ;
F_9 ( V_66 , V_46 ,
V_67 ) ;
F_9 ( V_68 , V_46 ,
V_69 ) ;
}
static unsigned long F_10 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_70 ;
T_1 V_71 ;
int V_72 ;
V_72 = F_11 ( V_8 , & V_70 , & V_71 ) ;
return V_72 ? 0 : V_70 | V_71 ;
}
static bool F_12 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_73 ;
T_2 V_74 ;
int V_72 ;
V_72 = F_13 ( V_8 , & V_73 , & V_74 ) ;
return V_72 ? false : V_73 | V_74 ;
}
static int F_14 ( struct V_1 * V_2 , int V_75 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_75 ) {
case V_76 :
return V_77 +
F_15 ( V_6 ) +
V_78 + V_79 +
F_16 ( V_6 ) +
F_17 ( V_6 ) +
F_18 ( V_6 ) ;
case V_80 :
return F_19 ( V_81 ) ;
default:
return - V_82 ;
}
}
static void F_20 ( struct V_5 * V_6 , T_3 * V_83 )
{
int V_84 , V_85 , V_86 , V_87 , V_88 = 0 ;
unsigned long V_89 ;
for ( V_84 = 0 ; V_84 < V_77 ; V_84 ++ )
strcpy ( V_83 + ( V_88 ++ ) * V_90 , V_91 [ V_84 ] . V_92 ) ;
for ( V_84 = 0 ; V_84 < F_15 ( V_6 ) ; V_84 ++ )
strcpy ( V_83 + ( V_88 ++ ) * V_90 , V_93 [ V_84 ] . V_92 ) ;
for ( V_84 = 0 ; V_84 < V_78 ; V_84 ++ )
strcpy ( V_83 + ( V_88 ++ ) * V_90 ,
V_94 [ V_84 ] . V_92 ) ;
for ( V_84 = 0 ; V_84 < V_95 ; V_84 ++ )
strcpy ( V_83 + ( V_88 ++ ) * V_90 ,
V_96 [ V_84 ] . V_92 ) ;
for ( V_84 = 0 ; V_84 < V_97 ; V_84 ++ )
strcpy ( V_83 + ( V_88 ++ ) * V_90 ,
V_98 [ V_84 ] . V_92 ) ;
for ( V_84 = 0 ; V_84 < V_99 ; V_84 ++ )
strcpy ( V_83 + ( V_88 ++ ) * V_90 ,
V_100 [ V_84 ] . V_92 ) ;
for ( V_87 = 0 ; V_87 < V_101 ; V_87 ++ ) {
for ( V_84 = 0 ; V_84 < V_102 ; V_84 ++ )
sprintf ( V_83 + ( V_88 ++ ) * V_90 ,
V_103 [ V_84 ] . V_92 , V_87 ) ;
}
V_89 = F_10 ( V_6 ) ;
F_21 (prio, &pfc_combined, NUM_PPORT_PRIO) {
for ( V_84 = 0 ; V_84 < V_104 ; V_84 ++ ) {
char V_105 [ V_90 ] ;
snprintf ( V_105 , sizeof( V_105 ) , L_4 , V_87 ) ;
sprintf ( V_83 + ( V_88 ++ ) * V_90 ,
V_106 [ V_84 ] . V_92 , V_105 ) ;
}
}
if ( F_12 ( V_6 ) ) {
for ( V_84 = 0 ; V_84 < V_104 ; V_84 ++ ) {
sprintf ( V_83 + ( V_88 ++ ) * V_90 ,
V_106 [ V_84 ] . V_92 , L_5 ) ;
}
}
if ( ! F_22 ( V_107 , & V_6 -> V_108 ) )
return;
for ( V_84 = 0 ; V_84 < V_6 -> V_109 . V_110 ; V_84 ++ )
for ( V_85 = 0 ; V_85 < V_111 ; V_85 ++ )
sprintf ( V_83 + ( V_88 ++ ) * V_90 ,
V_112 [ V_85 ] . V_92 , V_84 ) ;
for ( V_86 = 0 ; V_86 < V_6 -> V_109 . V_113 ; V_86 ++ )
for ( V_84 = 0 ; V_84 < V_6 -> V_109 . V_110 ; V_84 ++ )
for ( V_85 = 0 ; V_85 < V_114 ; V_85 ++ )
sprintf ( V_83 + ( V_88 ++ ) * V_90 ,
V_115 [ V_85 ] . V_92 ,
V_6 -> V_116 [ V_84 ] [ V_86 ] ) ;
}
static void F_23 ( struct V_1 * V_2 ,
T_4 V_117 , T_3 * V_83 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_84 ;
switch ( V_117 ) {
case V_80 :
for ( V_84 = 0 ; V_84 < F_19 ( V_81 ) ; V_84 ++ )
strcpy ( V_83 + V_84 * V_90 , V_81 [ V_84 ] ) ;
break;
case V_118 :
break;
case V_76 :
F_20 ( V_6 , V_83 ) ;
break;
}
}
static void F_24 ( struct V_1 * V_2 ,
struct V_119 * V_120 , T_5 * V_83 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_84 , V_85 , V_86 , V_87 , V_88 = 0 ;
unsigned long V_89 ;
if ( ! V_83 )
return;
F_25 ( & V_6 -> V_121 ) ;
if ( F_22 ( V_107 , & V_6 -> V_108 ) )
F_26 ( V_6 ) ;
F_27 ( & V_6 -> V_121 ) ;
for ( V_84 = 0 ; V_84 < V_77 ; V_84 ++ )
V_83 [ V_88 ++ ] = F_28 ( & V_6 -> V_120 . V_122 ,
V_91 , V_84 ) ;
for ( V_84 = 0 ; V_84 < F_15 ( V_6 ) ; V_84 ++ )
V_83 [ V_88 ++ ] = F_29 ( & V_6 -> V_120 . V_123 ,
V_93 , V_84 ) ;
for ( V_84 = 0 ; V_84 < V_78 ; V_84 ++ )
V_83 [ V_88 ++ ] = F_30 ( V_6 -> V_120 . V_124 . V_125 ,
V_94 , V_84 ) ;
for ( V_84 = 0 ; V_84 < V_95 ; V_84 ++ )
V_83 [ V_88 ++ ] = F_30 ( & V_6 -> V_120 . V_126 . V_127 ,
V_96 , V_84 ) ;
for ( V_84 = 0 ; V_84 < V_97 ; V_84 ++ )
V_83 [ V_88 ++ ] = F_30 ( & V_6 -> V_120 . V_126 . V_128 ,
V_98 , V_84 ) ;
for ( V_84 = 0 ; V_84 < V_99 ; V_84 ++ )
V_83 [ V_88 ++ ] = F_30 ( & V_6 -> V_120 . V_126 . V_129 ,
V_100 , V_84 ) ;
for ( V_87 = 0 ; V_87 < V_101 ; V_87 ++ ) {
for ( V_84 = 0 ; V_84 < V_102 ; V_84 ++ )
V_83 [ V_88 ++ ] = F_30 ( & V_6 -> V_120 . V_126 . V_130 [ V_87 ] ,
V_103 , V_84 ) ;
}
V_89 = F_10 ( V_6 ) ;
F_21 (prio, &pfc_combined, NUM_PPORT_PRIO) {
for ( V_84 = 0 ; V_84 < V_104 ; V_84 ++ ) {
V_83 [ V_88 ++ ] = F_30 ( & V_6 -> V_120 . V_126 . V_130 [ V_87 ] ,
V_106 , V_84 ) ;
}
}
if ( F_12 ( V_6 ) ) {
for ( V_84 = 0 ; V_84 < V_104 ; V_84 ++ ) {
V_83 [ V_88 ++ ] = F_30 ( & V_6 -> V_120 . V_126 . V_130 [ 0 ] ,
V_106 , V_84 ) ;
}
}
if ( ! F_22 ( V_107 , & V_6 -> V_108 ) )
return;
for ( V_84 = 0 ; V_84 < V_6 -> V_109 . V_110 ; V_84 ++ )
for ( V_85 = 0 ; V_85 < V_111 ; V_85 ++ )
V_83 [ V_88 ++ ] =
F_28 ( & V_6 -> V_131 [ V_84 ] -> V_132 . V_120 ,
V_112 , V_85 ) ;
for ( V_86 = 0 ; V_86 < V_6 -> V_109 . V_113 ; V_86 ++ )
for ( V_84 = 0 ; V_84 < V_6 -> V_109 . V_110 ; V_84 ++ )
for ( V_85 = 0 ; V_85 < V_114 ; V_85 ++ )
V_83 [ V_88 ++ ] = F_28 ( & V_6 -> V_131 [ V_84 ] -> V_133 [ V_86 ] . V_120 ,
V_115 , V_85 ) ;
}
static T_2 F_31 ( struct V_5 * V_6 , int V_134 ,
int V_135 )
{
int V_136 ;
int V_137 ;
int V_138 ;
int V_139 ;
if ( V_134 != V_140 )
return V_135 ;
V_137 = 1 << V_6 -> V_109 . V_141 ;
V_138 = 1 << V_6 -> V_109 . V_142 ;
V_139 = V_137 * V_138 ;
V_136 = V_139 /
F_32 ( V_143 , V_137 ) ;
return ( 1 << ( F_33 ( V_135 * V_136 ) - 1 ) ) ;
}
static T_2 F_34 ( struct V_5 * V_6 , int V_134 ,
int V_144 )
{
int V_136 ;
int V_137 ;
int V_138 ;
int V_139 ;
int V_145 ;
if ( V_134 != V_140 )
return V_144 ;
V_137 = 1 << V_6 -> V_109 . V_141 ;
V_138 = 1 << V_6 -> V_109 . V_142 ;
V_139 = V_137 * V_138 ;
V_144 = ( 1 << F_33 ( V_144 ) ) ;
V_136 = V_139 /
F_32 ( V_143 , V_137 ) ;
V_145 = F_35 ( V_144 , V_136 ) ;
return 1 << ( F_33 ( V_145 ) ) ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_134 = V_6 -> V_109 . V_134 ;
V_147 -> V_148 = F_31 ( V_6 , V_134 ,
1 << F_37 ( V_134 ) ) ;
V_147 -> V_149 = 1 << V_150 ;
V_147 -> V_151 = F_31 ( V_6 , V_134 ,
1 << V_6 -> V_109 . V_152 ) ;
V_147 -> V_153 = 1 << V_6 -> V_109 . V_154 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
bool V_155 ;
int V_134 = V_6 -> V_109 . V_134 ;
T_2 V_156 ;
T_2 V_157 ;
T_2 V_158 ;
T_6 V_159 ;
T_1 V_152 ;
T_1 V_154 ;
T_2 V_160 ;
int V_72 = 0 ;
if ( V_147 -> V_161 ) {
F_39 ( V_2 , L_6 ,
V_162 ) ;
return - V_163 ;
}
if ( V_147 -> V_164 ) {
F_39 ( V_2 , L_7 ,
V_162 ) ;
return - V_163 ;
}
V_157 = F_31 ( V_6 , V_134 ,
1 << F_40 ( V_134 ) ) ;
V_158 = F_31 ( V_6 , V_134 ,
1 << F_37 ( V_134 ) ) ;
V_156 = F_34 ( V_6 , V_134 ,
V_147 -> V_151 ) ;
if ( V_147 -> V_151 < V_157 ) {
F_39 ( V_2 , L_8 ,
V_162 , V_147 -> V_151 ,
V_157 ) ;
return - V_163 ;
}
if ( V_147 -> V_151 > V_158 ) {
F_39 ( V_2 , L_9 ,
V_162 , V_147 -> V_151 ,
V_158 ) ;
return - V_163 ;
}
V_160 = F_41 ( V_6 -> V_109 . V_110 ,
V_156 ) ;
if ( V_6 -> V_109 . V_134 == V_140 &&
! F_42 ( V_160 ) ) {
F_39 ( V_2 , L_10 ,
V_162 , V_147 -> V_151 ) ;
return - V_163 ;
}
if ( V_147 -> V_153 < ( 1 << V_165 ) ) {
F_39 ( V_2 , L_11 ,
V_162 , V_147 -> V_153 ,
1 << V_165 ) ;
return - V_163 ;
}
if ( V_147 -> V_153 > ( 1 << V_150 ) ) {
F_39 ( V_2 , L_12 ,
V_162 , V_147 -> V_153 ,
1 << V_150 ) ;
return - V_163 ;
}
V_152 = F_33 ( V_156 ) ;
V_154 = F_33 ( V_147 -> V_153 ) ;
V_159 = F_43 ( V_134 , V_156 ) ;
if ( V_152 == V_6 -> V_109 . V_152 &&
V_154 == V_6 -> V_109 . V_154 &&
V_159 == V_6 -> V_109 . V_159 )
return 0 ;
F_25 ( & V_6 -> V_121 ) ;
V_155 = F_22 ( V_107 , & V_6 -> V_108 ) ;
if ( V_155 )
F_44 ( V_2 ) ;
V_6 -> V_109 . V_152 = V_152 ;
V_6 -> V_109 . V_154 = V_154 ;
V_6 -> V_109 . V_159 = V_159 ;
if ( V_155 )
V_72 = F_45 ( V_2 ) ;
F_27 ( & V_6 -> V_121 ) ;
return V_72 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_166 * V_167 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_167 -> V_168 = F_47 ( V_6 -> V_8 ) ;
V_167 -> V_169 = V_6 -> V_109 . V_110 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_166 * V_167 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_170 = F_47 ( V_6 -> V_8 ) ;
unsigned int V_171 = V_167 -> V_169 ;
bool V_172 ;
bool V_155 ;
T_2 V_160 ;
int V_72 = 0 ;
if ( ! V_171 ) {
F_39 ( V_2 , L_13 ,
V_162 ) ;
return - V_163 ;
}
if ( V_167 -> V_173 || V_167 -> V_174 ) {
F_39 ( V_2 , L_14 ,
V_162 ) ;
return - V_163 ;
}
if ( V_171 > V_170 ) {
F_39 ( V_2 , L_15 ,
V_162 , V_171 , V_170 ) ;
return - V_163 ;
}
V_160 = F_41 ( V_171 , F_49 ( V_6 -> V_109 . V_152 ) ) ;
if ( V_6 -> V_109 . V_134 == V_140 &&
! F_42 ( V_160 ) ) {
F_39 ( V_2 , L_16 ,
V_162 , V_171 ) ;
return - V_163 ;
}
if ( V_6 -> V_109 . V_110 == V_171 )
return 0 ;
F_25 ( & V_6 -> V_121 ) ;
V_155 = F_22 ( V_107 , & V_6 -> V_108 ) ;
if ( V_155 )
F_44 ( V_2 ) ;
V_172 = V_2 -> V_175 & V_176 ;
if ( V_172 )
F_50 ( V_6 ) ;
V_6 -> V_109 . V_110 = V_171 ;
F_51 ( V_6 -> V_8 , V_6 -> V_109 . V_177 ,
V_178 , V_171 ) ;
if ( V_155 )
V_72 = F_45 ( V_2 ) ;
if ( V_72 )
goto V_179;
if ( V_172 ) {
V_72 = F_52 ( V_6 ) ;
if ( V_72 )
F_53 ( V_2 , L_17 ,
V_162 , V_72 ) ;
}
V_179:
F_27 ( & V_6 -> V_121 ) ;
return V_72 ;
}
static int F_54 ( struct V_1 * V_180 ,
struct V_181 * V_182 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
if ( ! F_55 ( V_6 -> V_8 , V_183 ) )
return - V_184 ;
V_182 -> V_185 = V_6 -> V_109 . V_186 . V_187 ;
V_182 -> V_188 = V_6 -> V_109 . V_186 . V_189 ;
V_182 -> V_190 = V_6 -> V_109 . V_191 . V_187 ;
V_182 -> V_192 = V_6 -> V_109 . V_191 . V_189 ;
V_182 -> V_193 = V_6 -> V_109 . V_194 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_180 ,
struct V_181 * V_182 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_195 * V_196 ;
bool V_197 =
! ! V_182 -> V_193 != V_6 -> V_109 . V_194 ;
bool V_155 ;
int V_72 = 0 ;
int V_86 ;
int V_84 ;
if ( ! F_55 ( V_8 , V_183 ) )
return - V_184 ;
F_25 ( & V_6 -> V_121 ) ;
V_155 = F_22 ( V_107 , & V_6 -> V_108 ) ;
if ( V_155 && V_197 ) {
F_44 ( V_180 ) ;
V_6 -> V_109 . V_194 = ! ! V_182 -> V_193 ;
}
V_6 -> V_109 . V_191 . V_187 = V_182 -> V_190 ;
V_6 -> V_109 . V_191 . V_189 = V_182 -> V_192 ;
V_6 -> V_109 . V_186 . V_187 = V_182 -> V_185 ;
V_6 -> V_109 . V_186 . V_189 = V_182 -> V_188 ;
if ( ! V_155 || V_197 )
goto V_179;
for ( V_84 = 0 ; V_84 < V_6 -> V_109 . V_110 ; ++ V_84 ) {
V_196 = V_6 -> V_131 [ V_84 ] ;
for ( V_86 = 0 ; V_86 < V_196 -> V_113 ; V_86 ++ ) {
F_57 ( V_8 ,
& V_196 -> V_133 [ V_86 ] . V_198 . V_199 ,
V_182 -> V_190 ,
V_182 -> V_192 ) ;
}
F_57 ( V_8 , & V_196 -> V_132 . V_198 . V_199 ,
V_182 -> V_185 ,
V_182 -> V_188 ) ;
}
V_179:
if ( V_155 && V_197 )
V_72 = F_45 ( V_180 ) ;
F_27 ( & V_6 -> V_121 ) ;
return V_72 ;
}
static void F_58 ( unsigned long * V_200 ,
T_2 V_201 )
{
unsigned long V_202 = V_201 ;
int V_203 ;
F_21 (proto, &proto_cap, MLX5E_LINK_MODES_NUMBER)
F_59 ( V_200 , V_200 ,
V_204 [ V_203 ] . V_205 ,
V_206 ) ;
}
static void F_60 ( unsigned long * V_207 ,
T_2 V_201 )
{
unsigned long V_202 = V_201 ;
int V_203 ;
F_21 (proto, &proto_cap, MLX5E_LINK_MODES_NUMBER)
F_59 ( V_207 , V_207 ,
V_204 [ V_203 ] . V_208 ,
V_206 ) ;
}
static void F_61 ( struct V_209 * V_210 ,
T_2 V_201 )
{
if ( V_201 & ( F_62 ( V_38 )
| F_62 ( V_39 )
| F_62 ( V_30 )
| F_62 ( V_41 )
| F_62 ( V_51 )
| F_62 ( V_17 ) ) ) {
F_63 ( V_210 , V_205 , V_211 ) ;
}
if ( V_201 & ( F_62 ( V_53 )
| F_62 ( V_33 )
| F_62 ( V_25 )
| F_62 ( V_24 )
| F_62 ( V_20 ) ) ) {
F_63 ( V_210 , V_205 , V_212 ) ;
}
}
int F_64 ( struct V_7 * V_8 , T_2 * V_213 )
{
T_2 V_214 = 0 ;
T_2 V_202 ;
int V_72 ;
int V_84 ;
V_72 = F_65 ( V_8 , & V_202 , V_215 ) ;
if ( V_72 )
return V_72 ;
for ( V_84 = 0 ; V_84 < V_216 ; ++ V_84 )
if ( V_202 & F_62 ( V_84 ) )
V_214 = F_66 ( V_214 , V_204 [ V_84 ] . V_213 ) ;
* V_213 = V_214 ;
return 0 ;
}
static void F_67 ( struct V_1 * V_180 ,
T_2 V_217 ,
struct V_209 * V_210 )
{
int V_84 ;
T_2 V_213 = V_218 ;
T_1 V_219 = V_220 ;
if ( ! F_68 ( V_180 ) )
goto V_179;
for ( V_84 = 0 ; V_84 < V_216 ; ++ V_84 ) {
if ( V_217 & F_62 ( V_84 ) ) {
V_213 = V_204 [ V_84 ] . V_213 ;
V_219 = V_221 ;
break;
}
}
V_179:
V_210 -> V_222 . V_213 = V_213 ;
V_210 -> V_222 . V_219 = V_219 ;
}
static void F_69 ( T_2 V_201 ,
struct V_209 * V_210 )
{
unsigned long * V_205 = V_210 -> V_223 . V_205 ;
F_61 ( V_210 , V_201 ) ;
F_58 ( V_205 , V_201 ) ;
F_63 ( V_210 , V_205 , V_224 ) ;
F_63 ( V_210 , V_205 , V_225 ) ;
}
static void F_70 ( T_2 V_201 , T_1 V_74 ,
T_1 V_73 ,
struct V_209 * V_210 )
{
unsigned long * V_226 = V_210 -> V_223 . V_226 ;
F_60 ( V_226 , V_201 ) ;
if ( V_74 )
F_63 ( V_210 , V_226 , V_224 ) ;
if ( V_74 ^ V_73 )
F_63 ( V_210 , V_226 , V_225 ) ;
}
static T_1 F_71 ( T_2 V_227 )
{
if ( V_227 & ( F_62 ( V_39 )
| F_62 ( V_41 )
| F_62 ( V_51 )
| F_62 ( V_17 ) ) ) {
return V_228 ;
}
if ( V_227 & ( F_62 ( V_30 )
| F_62 ( V_38 )
| F_62 ( V_48 ) ) ) {
return V_229 ;
}
if ( V_227 & ( F_62 ( V_24 )
| F_62 ( V_25 )
| F_62 ( V_33 )
| F_62 ( V_53 ) ) ) {
return V_230 ;
}
return V_231 ;
}
static void F_72 ( T_2 V_232 ,
struct V_209 * V_210 )
{
unsigned long * V_233 = V_210 -> V_223 . V_233 ;
F_60 ( V_233 , V_232 ) ;
}
static int F_73 ( struct V_1 * V_180 ,
struct V_209 * V_210 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_179 [ F_74 ( V_234 ) ] ;
T_2 V_201 ;
T_2 V_235 ;
T_2 V_232 ;
T_2 V_217 ;
T_1 V_236 ;
T_1 V_237 ;
int V_72 ;
V_72 = F_75 ( V_8 , V_179 , sizeof( V_179 ) , V_215 , 1 ) ;
if ( V_72 ) {
F_53 ( V_180 , L_18 ,
V_162 , V_72 ) ;
goto V_238;
}
V_201 = F_76 ( V_234 , V_179 , V_239 ) ;
V_235 = F_76 ( V_234 , V_179 , V_235 ) ;
V_217 = F_76 ( V_234 , V_179 , V_217 ) ;
V_232 = F_76 ( V_234 , V_179 , V_240 ) ;
V_236 = F_76 ( V_234 , V_179 , V_236 ) ;
V_237 = F_76 ( V_234 , V_179 , V_237 ) ;
F_77 ( V_210 , V_205 ) ;
F_77 ( V_210 , V_226 ) ;
F_69 ( V_201 , V_210 ) ;
F_70 ( V_235 , 0 , 0 , V_210 ) ;
F_67 ( V_180 , V_217 , V_210 ) ;
V_217 = V_217 ? V_217 : V_201 ;
V_210 -> V_222 . V_241 = F_71 ( V_217 ) ;
F_72 ( V_232 , V_210 ) ;
if ( V_237 == V_242 )
F_63 ( V_210 ,
V_233 , V_243 ) ;
V_210 -> V_222 . V_244 = V_236 ? V_245 :
V_246 ;
F_63 ( V_210 , V_205 ,
V_243 ) ;
if ( ! V_236 )
F_63 ( V_210 ,
V_226 , V_243 ) ;
V_238:
return V_72 ;
}
static T_2 F_78 ( const unsigned long * V_223 )
{
T_2 V_84 , V_247 = 0 ;
for ( V_84 = 0 ; V_84 < V_216 ; ++ V_84 ) {
if ( F_79 ( V_204 [ V_84 ] . V_208 ,
V_223 ,
V_206 ) )
V_247 |= F_62 ( V_84 ) ;
}
return V_247 ;
}
static T_2 F_80 ( T_2 V_213 )
{
T_2 V_84 , V_248 = 0 ;
for ( V_84 = 0 ; V_84 < V_216 ; ++ V_84 ) {
if ( V_204 [ V_84 ] . V_213 == V_213 )
V_248 |= F_62 ( V_84 ) ;
}
return V_248 ;
}
static int F_81 ( struct V_1 * V_180 ,
const struct V_209 * V_210 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_201 , V_235 ;
bool V_249 = false ;
T_1 V_236 ;
T_1 V_250 ;
bool V_251 ;
T_2 V_223 ;
T_1 V_237 ;
T_2 V_213 ;
int V_72 ;
V_213 = V_210 -> V_222 . V_213 ;
V_223 = V_210 -> V_222 . V_244 == V_246 ?
F_78 ( V_210 -> V_223 . V_226 ) :
F_80 ( V_213 ) ;
V_72 = F_65 ( V_8 , & V_201 , V_215 ) ;
if ( V_72 ) {
F_53 ( V_180 , L_19 ,
V_162 , V_72 ) ;
goto V_179;
}
V_223 = V_223 & V_201 ;
if ( ! V_223 ) {
F_53 ( V_180 , L_20 ,
V_162 ) ;
V_72 = - V_163 ;
goto V_179;
}
V_72 = F_82 ( V_8 , & V_235 , V_215 ) ;
if ( V_72 ) {
F_53 ( V_180 , L_21 ,
V_162 , V_72 ) ;
goto V_179;
}
F_83 ( V_8 , V_215 , & V_237 ,
& V_250 , & V_236 ) ;
V_251 = V_210 -> V_222 . V_244 == V_245 ;
V_249 = ( ( ! V_251 && V_236 ) ||
( V_251 && ! V_236 ) ) ;
if ( ! V_249 && V_223 == V_235 )
goto V_179;
F_84 ( V_8 , V_251 , V_223 , V_215 ) ;
F_85 ( V_8 ) ;
V_179:
return V_72 ;
}
static T_2 F_86 ( struct V_1 * V_180 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
return sizeof( V_6 -> V_109 . V_252 ) ;
}
static T_2 F_87 ( struct V_1 * V_180 )
{
return V_178 ;
}
static int F_88 ( struct V_1 * V_180 , T_2 * V_253 , T_1 * V_254 ,
T_1 * V_255 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
if ( V_253 )
memcpy ( V_253 , V_6 -> V_109 . V_177 ,
sizeof( V_6 -> V_109 . V_177 ) ) ;
if ( V_254 )
memcpy ( V_254 , V_6 -> V_109 . V_252 ,
sizeof( V_6 -> V_109 . V_252 ) ) ;
if ( V_255 )
* V_255 = V_6 -> V_109 . V_256 ;
return 0 ;
}
static void F_89 ( struct V_5 * V_6 , void * V_257 , int V_258 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
void * V_259 = F_90 ( V_260 , V_257 , V_261 ) ;
int V_84 ;
F_91 ( V_260 , V_257 , V_262 . V_263 , 1 ) ;
F_92 ( V_259 , V_6 ) ;
for ( V_84 = 0 ; V_84 < V_264 ; V_84 ++ )
F_93 ( V_8 , V_6 -> V_265 [ V_84 ] . V_266 , V_257 , V_258 ) ;
}
static int F_94 ( struct V_1 * V_2 , const T_2 * V_253 ,
const T_1 * V_254 , const T_1 V_255 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_258 = F_95 ( V_260 ) ;
void * V_257 ;
if ( ( V_255 != V_267 ) &&
( V_255 != V_268 ) &&
( V_255 != V_269 ) )
return - V_163 ;
V_257 = F_96 ( V_258 ) ;
if ( ! V_257 )
return - V_270 ;
F_25 ( & V_6 -> V_121 ) ;
if ( V_253 ) {
T_2 V_271 = V_6 -> V_272 . V_271 ;
memcpy ( V_6 -> V_109 . V_177 , V_253 ,
sizeof( V_6 -> V_109 . V_177 ) ) ;
F_97 ( V_6 , V_271 , V_178 , 0 ) ;
}
if ( V_254 )
memcpy ( V_6 -> V_109 . V_252 , V_254 ,
sizeof( V_6 -> V_109 . V_252 ) ) ;
if ( V_255 != V_267 )
V_6 -> V_109 . V_256 = V_255 ;
F_89 ( V_6 , V_257 , V_258 ) ;
F_27 ( & V_6 -> V_121 ) ;
F_98 ( V_257 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_180 ,
struct V_273 * V_274 , T_2 * V_275 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
int V_72 = 0 ;
switch ( V_274 -> V_276 ) {
case V_277 :
V_274 -> V_83 = V_6 -> V_109 . V_110 ;
break;
case V_278 :
V_274 -> V_279 = V_6 -> V_280 . V_281 . V_282 ;
break;
case V_283 :
V_72 = F_100 ( V_6 , V_274 , V_274 -> V_280 . V_284 ) ;
break;
case V_285 :
V_72 = F_101 ( V_6 , V_274 , V_275 ) ;
break;
default:
V_72 = - V_82 ;
break;
}
return V_72 ;
}
static int F_102 ( struct V_1 * V_2 ,
const struct V_286 * V_287 ,
void * V_83 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_72 = 0 ;
switch ( V_287 -> V_288 ) {
case V_289 :
* ( T_2 * ) V_83 = V_6 -> V_109 . V_290 ;
break;
default:
V_72 = - V_163 ;
break;
}
return V_72 ;
}
static int F_103 ( struct V_1 * V_2 ,
const struct V_286 * V_287 ,
const void * V_83 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
bool V_155 ;
T_2 V_291 ;
int V_72 = 0 ;
switch ( V_287 -> V_288 ) {
case V_289 :
V_291 = * ( T_2 * ) V_83 ;
if ( V_291 > F_104 ( V_8 ) ) {
V_72 = - V_163 ;
break;
}
F_25 ( & V_6 -> V_121 ) ;
V_155 = F_22 ( V_107 , & V_6 -> V_108 ) ;
if ( V_155 )
F_44 ( V_2 ) ;
V_6 -> V_109 . V_290 = V_291 ;
if ( V_155 )
V_72 = F_45 ( V_2 ) ;
F_27 ( & V_6 -> V_121 ) ;
break;
default:
V_72 = - V_163 ;
break;
}
return V_72 ;
}
static void F_105 ( struct V_1 * V_180 ,
struct V_292 * V_293 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_72 ;
V_72 = F_13 ( V_8 , & V_293 -> V_73 ,
& V_293 -> V_74 ) ;
if ( V_72 ) {
F_53 ( V_180 , L_22 ,
V_162 , V_72 ) ;
}
}
static int F_106 ( struct V_1 * V_180 ,
struct V_292 * V_293 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_72 ;
if ( V_293 -> V_244 )
return - V_163 ;
V_72 = F_107 ( V_8 ,
V_293 -> V_73 ? 1 : 0 ,
V_293 -> V_74 ? 1 : 0 ) ;
if ( V_72 ) {
F_53 ( V_180 , L_23 ,
V_162 , V_72 ) ;
}
return V_72 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_294 * V_274 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_295 ;
V_295 = F_109 ( V_2 , V_274 ) ;
if ( V_295 )
return V_295 ;
V_274 -> V_296 = V_6 -> V_297 . V_298 ?
F_110 ( V_6 -> V_297 . V_298 ) : - 1 ;
if ( ! F_55 ( V_6 -> V_8 , V_299 ) )
return 0 ;
V_274 -> V_300 |= V_301 |
V_302 |
V_303 ;
V_274 -> V_304 = ( F_49 ( 1 ) << V_305 ) |
( F_49 ( 1 ) << V_306 ) ;
V_274 -> V_307 = ( F_49 ( 1 ) << V_308 ) |
( F_49 ( 1 ) << V_309 ) ;
return 0 ;
}
static T_7 F_111 ( struct V_7 * V_8 )
{
T_7 V_295 = 0 ;
if ( F_55 ( V_8 , V_310 ) )
V_295 |= V_311 ;
if ( F_55 ( V_8 , V_312 ) )
V_295 |= V_313 ;
if ( F_55 ( V_8 , V_314 ) )
V_295 |= V_315 ;
if ( F_55 ( V_8 , V_316 ) )
V_295 |= V_317 ;
if ( F_55 ( V_8 , V_318 ) )
V_295 |= V_319 ;
if ( F_55 ( V_8 , V_320 ) )
V_295 |= V_321 ;
if ( F_55 ( V_8 , V_322 ) )
V_295 |= V_323 ;
return V_295 ;
}
static T_7 F_112 ( T_1 V_324 )
{
T_7 V_295 = 0 ;
if ( V_324 & V_325 )
V_295 |= V_311 ;
if ( V_324 & V_326 )
V_295 |= V_313 ;
if ( V_324 & V_327 )
V_295 |= V_315 ;
if ( V_324 & V_328 )
V_295 |= V_317 ;
if ( V_324 & V_329 )
V_295 |= V_319 ;
if ( V_324 & V_330 )
V_295 |= V_321 ;
if ( V_324 & V_331 )
V_295 |= V_323 ;
return V_295 ;
}
static T_1 F_113 ( T_7 V_324 )
{
T_1 V_295 = 0 ;
if ( V_324 & V_311 )
V_295 |= V_325 ;
if ( V_324 & V_313 )
V_295 |= V_326 ;
if ( V_324 & V_315 )
V_295 |= V_327 ;
if ( V_324 & V_317 )
V_295 |= V_328 ;
if ( V_324 & V_319 )
V_295 |= V_329 ;
if ( V_324 & V_321 )
V_295 |= V_330 ;
if ( V_324 & V_323 )
V_295 |= V_331 ;
return V_295 ;
}
static void F_114 ( struct V_1 * V_180 ,
struct V_332 * V_333 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_334 ;
int V_72 ;
memset ( V_333 , 0 , sizeof( * V_333 ) ) ;
V_333 -> V_205 = F_111 ( V_8 ) ;
if ( ! V_333 -> V_205 )
return;
V_72 = F_115 ( V_8 , & V_334 ) ;
if ( V_72 )
return;
V_333 -> V_335 = F_112 ( V_334 ) ;
}
static int F_116 ( struct V_1 * V_180 , struct V_332 * V_333 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_7 V_336 = F_111 ( V_8 ) ;
T_2 V_334 ;
if ( ! V_336 )
return - V_184 ;
if ( V_333 -> V_335 & ~ V_336 )
return - V_163 ;
V_334 = F_113 ( V_333 -> V_335 ) ;
return F_117 ( V_8 , V_334 ) ;
}
static int F_118 ( struct V_1 * V_2 ,
enum V_337 V_108 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_6 V_338 ;
if ( ! F_55 ( V_8 , V_339 ) )
return - V_82 ;
switch ( V_108 ) {
case V_340 :
V_338 = V_341 ;
break;
case V_342 :
V_338 = V_343 ;
break;
default:
return - V_82 ;
}
return F_119 ( V_8 , V_338 ) ;
}
static int F_120 ( struct V_1 * V_180 ,
struct V_344 * V_345 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
struct V_7 * V_2 = V_6 -> V_8 ;
int V_346 = 0 ;
T_1 V_83 [ 4 ] ;
V_346 = F_121 ( V_2 , 0 , 2 , V_83 ) ;
if ( V_346 < 2 )
return - V_347 ;
switch ( V_83 [ 0 ] ) {
case V_348 :
V_345 -> type = V_349 ;
V_345 -> V_350 = V_351 ;
break;
case V_352 :
case V_353 :
if ( V_83 [ 0 ] == V_353 || V_83 [ 1 ] >= 0x3 ) {
V_345 -> type = V_354 ;
V_345 -> V_350 = V_355 ;
} else {
V_345 -> type = V_349 ;
V_345 -> V_350 = V_351 ;
}
break;
case V_356 :
V_345 -> type = V_357 ;
V_345 -> V_350 = V_358 ;
break;
default:
F_53 ( V_6 -> V_180 , L_24 ,
V_162 , V_83 [ 0 ] ) ;
return - V_163 ;
}
return 0 ;
}
static int F_122 ( struct V_1 * V_180 ,
struct V_359 * V_360 ,
T_1 * V_83 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_361 = V_360 -> V_361 ;
int V_346 ;
int V_84 = 0 ;
if ( ! V_360 -> V_362 )
return - V_163 ;
memset ( V_83 , 0 , V_360 -> V_362 ) ;
while ( V_84 < V_360 -> V_362 ) {
V_346 = F_121 ( V_8 , V_361 , V_360 -> V_362 - V_84 ,
V_83 + V_84 ) ;
if ( ! V_346 )
return 0 ;
if ( V_346 < 0 ) {
F_53 ( V_6 -> V_180 , L_25 ,
V_162 , V_346 ) ;
return 0 ;
}
V_84 += V_346 ;
V_361 += V_346 ;
}
return 0 ;
}
static int F_123 ( struct V_1 * V_180 , bool V_363 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
bool V_364 ;
T_1 V_365 ;
int V_72 = 0 ;
bool V_366 ;
V_365 = V_363 ?
V_367 :
V_368 ;
V_364 = V_365 != V_6 -> V_109 . V_365 ;
if ( V_365 == V_367 &&
! F_55 ( V_8 , V_369 ) )
return - V_184 ;
if ( ! V_364 )
return 0 ;
V_366 = F_22 ( V_107 , & V_6 -> V_108 ) ;
if ( V_366 )
F_44 ( V_180 ) ;
F_124 ( & V_6 -> V_109 , V_365 ) ;
if ( V_366 )
V_72 = F_45 ( V_180 ) ;
return V_72 ;
}
static int F_125 ( struct V_1 * V_180 ,
T_2 V_370 ,
enum V_371 V_372 ,
T_8 V_373 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
bool V_363 = ! ! ( V_370 & V_372 ) ;
T_2 V_374 = V_370 ^ V_6 -> V_375 ;
int V_72 ;
if ( ! ( V_374 & V_372 ) )
return 0 ;
V_72 = V_373 ( V_180 , V_363 ) ;
if ( V_72 ) {
F_53 ( V_180 , L_26 ,
V_363 ? L_27 : L_28 , V_372 , V_72 ) ;
return V_72 ;
}
F_126 ( V_6 , V_372 , V_363 ) ;
return 0 ;
}
static int F_127 ( struct V_1 * V_180 , T_2 V_375 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
int V_72 ;
F_25 ( & V_6 -> V_121 ) ;
V_72 = F_125 ( V_180 , V_375 ,
V_376 ,
F_123 ) ;
F_27 ( & V_6 -> V_121 ) ;
return V_72 ? - V_163 : 0 ;
}
static T_2 F_128 ( struct V_1 * V_180 )
{
struct V_5 * V_6 = F_2 ( V_180 ) ;
return V_6 -> V_375 ;
}
static int F_129 ( struct V_1 * V_2 , struct V_273 * V_276 )
{
int V_72 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_276 -> V_276 ) {
case V_377 :
V_72 = F_130 ( V_6 , & V_276 -> V_280 ) ;
break;
case V_378 :
V_72 = F_131 ( V_6 , V_276 -> V_280 . V_284 ) ;
break;
default:
V_72 = - V_82 ;
break;
}
return V_72 ;
}
