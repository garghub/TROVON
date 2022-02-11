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
F_18 ( V_6 ) +
F_19 ( V_80 ) +
F_19 ( V_81 ) ;
case V_82 :
return F_19 ( V_83 ) ;
case V_84 :
return F_20 ( V_6 ) ;
default:
return - V_85 ;
}
}
static void F_21 ( struct V_5 * V_6 , T_3 * V_86 )
{
int V_87 , V_88 , V_89 , V_90 , V_91 = 0 ;
unsigned long V_92 ;
for ( V_87 = 0 ; V_87 < V_77 ; V_87 ++ )
strcpy ( V_86 + ( V_91 ++ ) * V_93 , V_94 [ V_87 ] . V_95 ) ;
for ( V_87 = 0 ; V_87 < F_15 ( V_6 ) ; V_87 ++ )
strcpy ( V_86 + ( V_91 ++ ) * V_93 , V_96 [ V_87 ] . V_95 ) ;
for ( V_87 = 0 ; V_87 < V_78 ; V_87 ++ )
strcpy ( V_86 + ( V_91 ++ ) * V_93 ,
V_97 [ V_87 ] . V_95 ) ;
for ( V_87 = 0 ; V_87 < V_98 ; V_87 ++ )
strcpy ( V_86 + ( V_91 ++ ) * V_93 ,
V_99 [ V_87 ] . V_95 ) ;
for ( V_87 = 0 ; V_87 < V_100 ; V_87 ++ )
strcpy ( V_86 + ( V_91 ++ ) * V_93 ,
V_101 [ V_87 ] . V_95 ) ;
for ( V_87 = 0 ; V_87 < V_102 ; V_87 ++ )
strcpy ( V_86 + ( V_91 ++ ) * V_93 ,
V_103 [ V_87 ] . V_95 ) ;
for ( V_90 = 0 ; V_90 < V_104 ; V_90 ++ ) {
for ( V_87 = 0 ; V_87 < V_105 ; V_87 ++ )
sprintf ( V_86 + ( V_91 ++ ) * V_93 ,
V_106 [ V_87 ] . V_95 , V_90 ) ;
}
V_92 = F_10 ( V_6 ) ;
F_22 (prio, &pfc_combined, NUM_PPORT_PRIO) {
for ( V_87 = 0 ; V_87 < V_107 ; V_87 ++ ) {
char V_108 [ V_93 ] ;
snprintf ( V_108 , sizeof( V_108 ) , L_4 , V_90 ) ;
sprintf ( V_86 + ( V_91 ++ ) * V_93 ,
V_109 [ V_87 ] . V_95 , V_108 ) ;
}
}
if ( F_12 ( V_6 ) ) {
for ( V_87 = 0 ; V_87 < V_107 ; V_87 ++ ) {
sprintf ( V_86 + ( V_91 ++ ) * V_93 ,
V_109 [ V_87 ] . V_95 , L_5 ) ;
}
}
for ( V_87 = 0 ; V_87 < F_19 ( V_80 ) ; V_87 ++ )
strcpy ( V_86 + ( V_91 ++ ) * V_93 , V_80 [ V_87 ] . V_95 ) ;
for ( V_87 = 0 ; V_87 < F_19 ( V_81 ) ; V_87 ++ )
strcpy ( V_86 + ( V_91 ++ ) * V_93 , V_81 [ V_87 ] . V_95 ) ;
if ( ! F_23 ( V_110 , & V_6 -> V_111 ) )
return;
for ( V_87 = 0 ; V_87 < V_6 -> V_112 . V_113 ; V_87 ++ )
for ( V_88 = 0 ; V_88 < V_114 ; V_88 ++ )
sprintf ( V_86 + ( V_91 ++ ) * V_93 ,
V_115 [ V_88 ] . V_95 , V_87 ) ;
for ( V_89 = 0 ; V_89 < V_6 -> V_112 . V_116 ; V_89 ++ )
for ( V_87 = 0 ; V_87 < V_6 -> V_112 . V_113 ; V_87 ++ )
for ( V_88 = 0 ; V_88 < V_117 ; V_88 ++ )
sprintf ( V_86 + ( V_91 ++ ) * V_93 ,
V_118 [ V_88 ] . V_95 ,
V_6 -> V_119 [ V_87 ] [ V_89 ] ) ;
}
static void F_24 ( struct V_1 * V_2 ,
T_4 V_120 , T_3 * V_86 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_87 ;
switch ( V_120 ) {
case V_82 :
for ( V_87 = 0 ; V_87 < F_19 ( V_83 ) ; V_87 ++ )
strcpy ( V_86 + V_87 * V_93 , V_83 [ V_87 ] ) ;
break;
case V_84 :
for ( V_87 = 0 ; V_87 < F_20 ( V_6 ) ; V_87 ++ )
strcpy ( V_86 + V_87 * V_93 ,
V_121 [ V_87 ] ) ;
break;
case V_76 :
F_21 ( V_6 , V_86 ) ;
break;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_122 * V_123 , T_5 * V_86 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_124 * V_124 ;
int V_87 , V_88 , V_89 , V_90 , V_91 = 0 ;
unsigned long V_92 ;
if ( ! V_86 )
return;
F_26 ( & V_6 -> V_125 ) ;
if ( F_23 ( V_110 , & V_6 -> V_111 ) )
F_27 ( V_6 ) ;
F_28 ( & V_6 -> V_125 ) ;
for ( V_87 = 0 ; V_87 < V_77 ; V_87 ++ )
V_86 [ V_91 ++ ] = F_29 ( & V_6 -> V_123 . V_126 ,
V_94 , V_87 ) ;
for ( V_87 = 0 ; V_87 < F_15 ( V_6 ) ; V_87 ++ )
V_86 [ V_91 ++ ] = F_30 ( & V_6 -> V_123 . V_127 ,
V_96 , V_87 ) ;
for ( V_87 = 0 ; V_87 < V_78 ; V_87 ++ )
V_86 [ V_91 ++ ] = F_31 ( V_6 -> V_123 . V_128 . V_129 ,
V_97 , V_87 ) ;
for ( V_87 = 0 ; V_87 < V_98 ; V_87 ++ )
V_86 [ V_91 ++ ] = F_31 ( & V_6 -> V_123 . V_130 . V_131 ,
V_99 , V_87 ) ;
for ( V_87 = 0 ; V_87 < V_100 ; V_87 ++ )
V_86 [ V_91 ++ ] = F_31 ( & V_6 -> V_123 . V_130 . V_132 ,
V_101 , V_87 ) ;
for ( V_87 = 0 ; V_87 < V_102 ; V_87 ++ )
V_86 [ V_91 ++ ] = F_31 ( & V_6 -> V_123 . V_130 . V_133 ,
V_103 , V_87 ) ;
for ( V_90 = 0 ; V_90 < V_104 ; V_90 ++ ) {
for ( V_87 = 0 ; V_87 < V_105 ; V_87 ++ )
V_86 [ V_91 ++ ] = F_31 ( & V_6 -> V_123 . V_130 . V_134 [ V_90 ] ,
V_106 , V_87 ) ;
}
V_92 = F_10 ( V_6 ) ;
F_22 (prio, &pfc_combined, NUM_PPORT_PRIO) {
for ( V_87 = 0 ; V_87 < V_107 ; V_87 ++ ) {
V_86 [ V_91 ++ ] = F_31 ( & V_6 -> V_123 . V_130 . V_134 [ V_90 ] ,
V_109 , V_87 ) ;
}
}
if ( F_12 ( V_6 ) ) {
for ( V_87 = 0 ; V_87 < V_107 ; V_87 ++ ) {
V_86 [ V_91 ++ ] = F_31 ( & V_6 -> V_123 . V_130 . V_134 [ 0 ] ,
V_109 , V_87 ) ;
}
}
V_124 = & V_6 -> V_8 -> V_6 ;
for ( V_87 = 0 ; V_87 < F_19 ( V_80 ) ; V_87 ++ )
V_86 [ V_91 ++ ] = F_29 ( V_124 -> V_135 . V_136 ,
V_80 , V_87 ) ;
for ( V_87 = 0 ; V_87 < F_19 ( V_81 ) ; V_87 ++ )
V_86 [ V_91 ++ ] = F_29 ( V_124 -> V_135 . V_137 ,
V_81 , V_87 ) ;
if ( ! F_23 ( V_110 , & V_6 -> V_111 ) )
return;
for ( V_87 = 0 ; V_87 < V_6 -> V_112 . V_113 ; V_87 ++ )
for ( V_88 = 0 ; V_88 < V_114 ; V_88 ++ )
V_86 [ V_91 ++ ] =
F_29 ( & V_6 -> V_138 [ V_87 ] -> V_139 . V_123 ,
V_115 , V_88 ) ;
for ( V_89 = 0 ; V_89 < V_6 -> V_112 . V_116 ; V_89 ++ )
for ( V_87 = 0 ; V_87 < V_6 -> V_112 . V_113 ; V_87 ++ )
for ( V_88 = 0 ; V_88 < V_117 ; V_88 ++ )
V_86 [ V_91 ++ ] = F_29 ( & V_6 -> V_138 [ V_87 ] -> V_140 [ V_89 ] . V_123 ,
V_118 , V_88 ) ;
}
static T_2 F_32 ( struct V_5 * V_6 , int V_141 ,
int V_142 )
{
int V_143 ;
int V_144 ;
int V_145 ;
int V_146 ;
if ( V_141 != V_147 )
return V_142 ;
V_144 = 1 << V_6 -> V_112 . V_148 ;
V_145 = 1 << V_6 -> V_112 . V_149 ;
V_146 = V_144 * V_145 ;
V_143 = V_146 /
F_33 ( V_150 , V_144 ) ;
return ( 1 << ( F_34 ( V_142 * V_143 ) - 1 ) ) ;
}
static T_2 F_35 ( struct V_5 * V_6 , int V_141 ,
int V_151 )
{
int V_143 ;
int V_144 ;
int V_145 ;
int V_146 ;
int V_152 ;
if ( V_141 != V_147 )
return V_151 ;
V_144 = 1 << V_6 -> V_112 . V_148 ;
V_145 = 1 << V_6 -> V_112 . V_149 ;
V_146 = V_144 * V_145 ;
V_151 = ( 1 << F_34 ( V_151 ) ) ;
V_143 = V_146 /
F_33 ( V_150 , V_144 ) ;
V_152 = F_36 ( V_151 , V_143 ) ;
return 1 << ( F_34 ( V_152 ) ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_141 = V_6 -> V_112 . V_141 ;
V_154 -> V_155 = F_32 ( V_6 , V_141 ,
1 << F_38 ( V_141 ) ) ;
V_154 -> V_156 = 1 << V_157 ;
V_154 -> V_158 = F_32 ( V_6 , V_141 ,
1 << V_6 -> V_112 . V_159 ) ;
V_154 -> V_160 = 1 << V_6 -> V_112 . V_161 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
bool V_162 ;
int V_141 = V_6 -> V_112 . V_141 ;
T_2 V_163 ;
T_2 V_164 ;
T_2 V_165 ;
T_6 V_166 ;
T_1 V_159 ;
T_1 V_161 ;
T_2 V_167 ;
int V_72 = 0 ;
if ( V_154 -> V_168 ) {
F_40 ( V_2 , L_6 ,
V_169 ) ;
return - V_170 ;
}
if ( V_154 -> V_171 ) {
F_40 ( V_2 , L_7 ,
V_169 ) ;
return - V_170 ;
}
V_164 = F_32 ( V_6 , V_141 ,
1 << F_41 ( V_141 ) ) ;
V_165 = F_32 ( V_6 , V_141 ,
1 << F_38 ( V_141 ) ) ;
V_163 = F_35 ( V_6 , V_141 ,
V_154 -> V_158 ) ;
if ( V_154 -> V_158 < V_164 ) {
F_40 ( V_2 , L_8 ,
V_169 , V_154 -> V_158 ,
V_164 ) ;
return - V_170 ;
}
if ( V_154 -> V_158 > V_165 ) {
F_40 ( V_2 , L_9 ,
V_169 , V_154 -> V_158 ,
V_165 ) ;
return - V_170 ;
}
V_167 = F_42 ( V_163 ) ;
if ( V_6 -> V_112 . V_141 == V_147 &&
! F_43 ( V_167 ) ) {
F_40 ( V_2 , L_10 ,
V_169 , V_154 -> V_158 ) ;
return - V_170 ;
}
if ( V_154 -> V_160 < ( 1 << V_172 ) ) {
F_40 ( V_2 , L_11 ,
V_169 , V_154 -> V_160 ,
1 << V_172 ) ;
return - V_170 ;
}
if ( V_154 -> V_160 > ( 1 << V_157 ) ) {
F_40 ( V_2 , L_12 ,
V_169 , V_154 -> V_160 ,
1 << V_157 ) ;
return - V_170 ;
}
V_159 = F_34 ( V_163 ) ;
V_161 = F_34 ( V_154 -> V_160 ) ;
V_166 = F_44 ( V_141 , V_163 ) ;
if ( V_159 == V_6 -> V_112 . V_159 &&
V_161 == V_6 -> V_112 . V_161 &&
V_166 == V_6 -> V_112 . V_166 )
return 0 ;
F_26 ( & V_6 -> V_125 ) ;
V_162 = F_23 ( V_110 , & V_6 -> V_111 ) ;
if ( V_162 )
F_45 ( V_2 ) ;
V_6 -> V_112 . V_159 = V_159 ;
V_6 -> V_112 . V_161 = V_161 ;
V_6 -> V_112 . V_166 = V_166 ;
if ( V_162 )
V_72 = F_46 ( V_2 ) ;
F_28 ( & V_6 -> V_125 ) ;
return V_72 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_173 * V_174 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_174 -> V_175 = F_48 ( V_6 -> V_8 ) ;
V_174 -> V_176 = V_6 -> V_112 . V_113 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_173 * V_174 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_177 = V_174 -> V_176 ;
bool V_178 ;
bool V_162 ;
int V_72 = 0 ;
if ( ! V_177 ) {
F_40 ( V_2 , L_13 ,
V_169 ) ;
return - V_170 ;
}
if ( V_6 -> V_112 . V_113 == V_177 )
return 0 ;
F_26 ( & V_6 -> V_125 ) ;
V_162 = F_23 ( V_110 , & V_6 -> V_111 ) ;
if ( V_162 )
F_45 ( V_2 ) ;
V_178 = V_2 -> V_179 & V_180 ;
if ( V_178 )
F_50 ( V_6 ) ;
V_6 -> V_112 . V_113 = V_177 ;
F_51 ( V_6 -> V_8 , V_6 -> V_112 . V_181 ,
V_182 , V_177 ) ;
if ( V_162 )
V_72 = F_46 ( V_2 ) ;
if ( V_72 )
goto V_183;
if ( V_178 ) {
V_72 = F_52 ( V_6 ) ;
if ( V_72 )
F_53 ( V_2 , L_14 ,
V_169 , V_72 ) ;
}
V_183:
F_28 ( & V_6 -> V_125 ) ;
return V_72 ;
}
static int F_54 ( struct V_1 * V_184 ,
struct V_185 * V_186 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
if ( ! F_55 ( V_6 -> V_8 , V_187 ) )
return - V_85 ;
V_186 -> V_188 = V_6 -> V_112 . V_189 . V_190 ;
V_186 -> V_191 = V_6 -> V_112 . V_189 . V_192 ;
V_186 -> V_193 = V_6 -> V_112 . V_194 . V_190 ;
V_186 -> V_195 = V_6 -> V_112 . V_194 . V_192 ;
V_186 -> V_196 = V_6 -> V_112 . V_197 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_184 ,
struct V_185 * V_186 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_198 * V_199 ;
bool V_200 =
! ! V_186 -> V_196 != V_6 -> V_112 . V_197 ;
bool V_162 ;
int V_72 = 0 ;
int V_89 ;
int V_87 ;
if ( ! F_55 ( V_8 , V_187 ) )
return - V_85 ;
F_26 ( & V_6 -> V_125 ) ;
V_162 = F_23 ( V_110 , & V_6 -> V_111 ) ;
if ( V_162 && V_200 ) {
F_45 ( V_184 ) ;
V_6 -> V_112 . V_197 = ! ! V_186 -> V_196 ;
}
V_6 -> V_112 . V_194 . V_190 = V_186 -> V_193 ;
V_6 -> V_112 . V_194 . V_192 = V_186 -> V_195 ;
V_6 -> V_112 . V_189 . V_190 = V_186 -> V_188 ;
V_6 -> V_112 . V_189 . V_192 = V_186 -> V_191 ;
if ( ! V_162 || V_200 )
goto V_183;
for ( V_87 = 0 ; V_87 < V_6 -> V_112 . V_113 ; ++ V_87 ) {
V_199 = V_6 -> V_138 [ V_87 ] ;
for ( V_89 = 0 ; V_89 < V_199 -> V_116 ; V_89 ++ ) {
F_57 ( V_8 ,
& V_199 -> V_140 [ V_89 ] . V_201 . V_202 ,
V_186 -> V_193 ,
V_186 -> V_195 ) ;
}
F_57 ( V_8 , & V_199 -> V_139 . V_201 . V_202 ,
V_186 -> V_188 ,
V_186 -> V_191 ) ;
}
V_183:
if ( V_162 && V_200 )
V_72 = F_46 ( V_184 ) ;
F_28 ( & V_6 -> V_125 ) ;
return V_72 ;
}
static void F_58 ( unsigned long * V_203 ,
T_2 V_204 )
{
unsigned long V_205 = V_204 ;
int V_206 ;
F_22 (proto, &proto_cap, MLX5E_LINK_MODES_NUMBER)
F_59 ( V_203 , V_203 ,
V_207 [ V_206 ] . V_208 ,
V_209 ) ;
}
static void F_60 ( unsigned long * V_210 ,
T_2 V_204 )
{
unsigned long V_205 = V_204 ;
int V_206 ;
F_22 (proto, &proto_cap, MLX5E_LINK_MODES_NUMBER)
F_59 ( V_210 , V_210 ,
V_207 [ V_206 ] . V_211 ,
V_209 ) ;
}
static void F_61 ( struct V_212 * V_213 ,
T_2 V_204 )
{
if ( V_204 & ( F_62 ( V_38 )
| F_62 ( V_39 )
| F_62 ( V_30 )
| F_62 ( V_41 )
| F_62 ( V_51 )
| F_62 ( V_17 ) ) ) {
F_63 ( V_213 , V_208 , V_214 ) ;
}
if ( V_204 & ( F_62 ( V_53 )
| F_62 ( V_33 )
| F_62 ( V_25 )
| F_62 ( V_24 )
| F_62 ( V_20 ) ) ) {
F_63 ( V_213 , V_208 , V_215 ) ;
}
}
int F_64 ( struct V_7 * V_8 , T_2 * V_216 )
{
T_2 V_217 = 0 ;
T_2 V_205 ;
int V_72 ;
int V_87 ;
V_72 = F_65 ( V_8 , & V_205 , V_218 ) ;
if ( V_72 )
return V_72 ;
for ( V_87 = 0 ; V_87 < V_219 ; ++ V_87 )
if ( V_205 & F_62 ( V_87 ) )
V_217 = F_66 ( V_217 , V_207 [ V_87 ] . V_216 ) ;
* V_216 = V_217 ;
return 0 ;
}
static void F_67 ( struct V_1 * V_184 ,
T_2 V_220 ,
struct V_212 * V_213 )
{
int V_87 ;
T_2 V_216 = V_221 ;
T_1 V_222 = V_223 ;
if ( ! F_68 ( V_184 ) )
goto V_183;
for ( V_87 = 0 ; V_87 < V_219 ; ++ V_87 ) {
if ( V_220 & F_62 ( V_87 ) ) {
V_216 = V_207 [ V_87 ] . V_216 ;
V_222 = V_224 ;
break;
}
}
V_183:
V_213 -> V_225 . V_216 = V_216 ;
V_213 -> V_225 . V_222 = V_222 ;
}
static void F_69 ( T_2 V_204 ,
struct V_212 * V_213 )
{
unsigned long * V_208 = V_213 -> V_226 . V_208 ;
F_61 ( V_213 , V_204 ) ;
F_58 ( V_208 , V_204 ) ;
F_63 ( V_213 , V_208 , V_227 ) ;
F_63 ( V_213 , V_208 , V_228 ) ;
}
static void F_70 ( T_2 V_204 , T_1 V_74 ,
T_1 V_73 ,
struct V_212 * V_213 )
{
unsigned long * V_229 = V_213 -> V_226 . V_229 ;
F_60 ( V_229 , V_204 ) ;
if ( V_74 )
F_63 ( V_213 , V_229 , V_227 ) ;
if ( V_74 ^ V_73 )
F_63 ( V_213 , V_229 , V_228 ) ;
}
static T_1 F_71 ( T_2 V_230 )
{
if ( V_230 & ( F_62 ( V_39 )
| F_62 ( V_41 )
| F_62 ( V_51 )
| F_62 ( V_17 ) ) ) {
return V_231 ;
}
if ( V_230 & ( F_62 ( V_30 )
| F_62 ( V_38 )
| F_62 ( V_48 ) ) ) {
return V_232 ;
}
if ( V_230 & ( F_62 ( V_24 )
| F_62 ( V_25 )
| F_62 ( V_33 )
| F_62 ( V_53 ) ) ) {
return V_233 ;
}
return V_234 ;
}
static void F_72 ( T_2 V_235 ,
struct V_212 * V_213 )
{
unsigned long * V_236 = V_213 -> V_226 . V_236 ;
F_60 ( V_236 , V_235 ) ;
}
static int F_73 ( struct V_1 * V_184 ,
struct V_212 * V_213 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_183 [ F_74 ( V_237 ) ] = { 0 } ;
T_2 V_204 ;
T_2 V_238 ;
T_2 V_235 ;
T_2 V_220 ;
T_1 V_239 ;
T_1 V_240 ;
int V_72 ;
V_72 = F_75 ( V_8 , V_183 , sizeof( V_183 ) , V_218 , 1 ) ;
if ( V_72 ) {
F_53 ( V_184 , L_15 ,
V_169 , V_72 ) ;
goto V_241;
}
V_204 = F_76 ( V_237 , V_183 , V_242 ) ;
V_238 = F_76 ( V_237 , V_183 , V_238 ) ;
V_220 = F_76 ( V_237 , V_183 , V_220 ) ;
V_235 = F_76 ( V_237 , V_183 , V_243 ) ;
V_239 = F_76 ( V_237 , V_183 , V_239 ) ;
V_240 = F_76 ( V_237 , V_183 , V_240 ) ;
F_77 ( V_213 , V_208 ) ;
F_77 ( V_213 , V_229 ) ;
F_69 ( V_204 , V_213 ) ;
F_70 ( V_238 , 0 , 0 , V_213 ) ;
F_67 ( V_184 , V_220 , V_213 ) ;
V_220 = V_220 ? V_220 : V_204 ;
V_213 -> V_225 . V_244 = F_71 ( V_220 ) ;
F_72 ( V_235 , V_213 ) ;
if ( V_240 == V_245 )
F_63 ( V_213 ,
V_236 , V_246 ) ;
V_213 -> V_225 . V_247 = V_239 ? V_248 :
V_249 ;
F_63 ( V_213 , V_208 ,
V_246 ) ;
if ( ! V_239 )
F_63 ( V_213 ,
V_229 , V_246 ) ;
V_241:
return V_72 ;
}
static T_2 F_78 ( const unsigned long * V_226 )
{
T_2 V_87 , V_250 = 0 ;
for ( V_87 = 0 ; V_87 < V_219 ; ++ V_87 ) {
if ( F_79 ( V_207 [ V_87 ] . V_211 ,
V_226 ,
V_209 ) )
V_250 |= F_62 ( V_87 ) ;
}
return V_250 ;
}
static T_2 F_80 ( T_2 V_216 )
{
T_2 V_87 , V_251 = 0 ;
for ( V_87 = 0 ; V_87 < V_219 ; ++ V_87 ) {
if ( V_207 [ V_87 ] . V_216 == V_216 )
V_251 |= F_62 ( V_87 ) ;
}
return V_251 ;
}
static int F_81 ( struct V_1 * V_184 ,
const struct V_212 * V_213 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_204 , V_238 ;
bool V_252 = false ;
T_1 V_239 ;
T_1 V_253 ;
bool V_254 ;
T_2 V_226 ;
T_1 V_240 ;
T_2 V_216 ;
int V_72 ;
V_216 = V_213 -> V_225 . V_216 ;
V_226 = V_213 -> V_225 . V_247 == V_249 ?
F_78 ( V_213 -> V_226 . V_229 ) :
F_80 ( V_216 ) ;
V_72 = F_65 ( V_8 , & V_204 , V_218 ) ;
if ( V_72 ) {
F_53 ( V_184 , L_16 ,
V_169 , V_72 ) ;
goto V_183;
}
V_226 = V_226 & V_204 ;
if ( ! V_226 ) {
F_53 ( V_184 , L_17 ,
V_169 ) ;
V_72 = - V_170 ;
goto V_183;
}
V_72 = F_82 ( V_8 , & V_238 , V_218 ) ;
if ( V_72 ) {
F_53 ( V_184 , L_18 ,
V_169 , V_72 ) ;
goto V_183;
}
F_83 ( V_8 , V_218 , & V_240 ,
& V_253 , & V_239 ) ;
V_254 = V_213 -> V_225 . V_247 == V_248 ;
V_252 = ( ( ! V_254 && V_239 ) ||
( V_254 && ! V_239 ) ) ;
if ( ! V_252 && V_226 == V_238 )
goto V_183;
F_84 ( V_8 , V_254 , V_226 , V_218 ) ;
F_85 ( V_8 ) ;
V_183:
return V_72 ;
}
static T_2 F_86 ( struct V_1 * V_184 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
return sizeof( V_6 -> V_112 . V_255 ) ;
}
static T_2 F_87 ( struct V_1 * V_184 )
{
return V_182 ;
}
static int F_88 ( struct V_1 * V_184 , T_2 * V_256 , T_1 * V_257 ,
T_1 * V_258 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
if ( V_256 )
memcpy ( V_256 , V_6 -> V_112 . V_181 ,
sizeof( V_6 -> V_112 . V_181 ) ) ;
if ( V_257 )
memcpy ( V_257 , V_6 -> V_112 . V_255 ,
sizeof( V_6 -> V_112 . V_255 ) ) ;
if ( V_258 )
* V_258 = V_6 -> V_112 . V_259 ;
return 0 ;
}
static void F_89 ( struct V_5 * V_6 , void * V_260 , int V_261 )
{
void * V_262 = F_90 ( V_263 , V_260 , V_264 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_265 = F_91 ( V_262 ) ;
int V_266 ;
F_92 ( V_263 , V_260 , V_267 . V_268 , 1 ) ;
for ( V_266 = 0 ; V_266 < V_269 ; V_266 ++ ) {
memset ( V_262 , 0 , V_265 ) ;
F_93 ( V_6 , V_262 , V_266 ) ;
F_94 ( V_8 , V_6 -> V_270 [ V_266 ] . V_271 , V_260 , V_261 ) ;
}
}
static int F_95 ( struct V_1 * V_2 , const T_2 * V_256 ,
const T_1 * V_257 , const T_1 V_258 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_261 = F_91 ( V_263 ) ;
bool V_272 = false ;
void * V_260 ;
if ( ( V_258 != V_273 ) &&
( V_258 != V_274 ) &&
( V_258 != V_275 ) )
return - V_170 ;
V_260 = F_96 ( V_261 ) ;
if ( ! V_260 )
return - V_276 ;
F_26 ( & V_6 -> V_125 ) ;
if ( V_256 ) {
T_2 V_277 = V_6 -> V_278 . V_277 ;
memcpy ( V_6 -> V_112 . V_181 , V_256 ,
sizeof( V_6 -> V_112 . V_181 ) ) ;
F_97 ( V_6 , V_277 , V_182 , 0 ) ;
}
if ( V_258 != V_273 &&
V_258 != V_6 -> V_112 . V_259 ) {
V_6 -> V_112 . V_259 = V_258 ;
V_272 = true ;
}
if ( V_257 ) {
memcpy ( V_6 -> V_112 . V_255 , V_257 ,
sizeof( V_6 -> V_112 . V_255 ) ) ;
V_272 = V_272 ||
V_6 -> V_112 . V_259 == V_275 ;
}
if ( V_272 )
F_89 ( V_6 , V_260 , V_261 ) ;
F_28 ( & V_6 -> V_125 ) ;
F_98 ( V_260 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_184 ,
struct V_279 * V_280 , T_2 * V_281 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
int V_72 = 0 ;
switch ( V_280 -> V_282 ) {
case V_283 :
V_280 -> V_86 = V_6 -> V_112 . V_113 ;
break;
case V_284 :
V_280 -> V_285 = V_6 -> V_286 . V_287 . V_288 ;
break;
case V_289 :
V_72 = F_100 ( V_6 , V_280 , V_280 -> V_286 . V_290 ) ;
break;
case V_291 :
V_72 = F_101 ( V_6 , V_280 , V_281 ) ;
break;
default:
V_72 = - V_85 ;
break;
}
return V_72 ;
}
static int F_102 ( struct V_1 * V_2 ,
const struct V_292 * V_293 ,
void * V_86 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_72 = 0 ;
switch ( V_293 -> V_294 ) {
case V_295 :
* ( T_2 * ) V_86 = V_6 -> V_112 . V_296 ;
break;
default:
V_72 = - V_170 ;
break;
}
return V_72 ;
}
static int F_103 ( struct V_1 * V_2 ,
const struct V_292 * V_293 ,
const void * V_86 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
bool V_162 ;
T_2 V_297 ;
int V_72 = 0 ;
switch ( V_293 -> V_294 ) {
case V_295 :
V_297 = * ( T_2 * ) V_86 ;
if ( V_297 > F_104 ( V_8 ) ) {
V_72 = - V_170 ;
break;
}
F_26 ( & V_6 -> V_125 ) ;
V_162 = F_23 ( V_110 , & V_6 -> V_111 ) ;
if ( V_162 )
F_45 ( V_2 ) ;
V_6 -> V_112 . V_296 = V_297 ;
if ( V_162 )
V_72 = F_46 ( V_2 ) ;
F_28 ( & V_6 -> V_125 ) ;
break;
default:
V_72 = - V_170 ;
break;
}
return V_72 ;
}
static void F_105 ( struct V_1 * V_184 ,
struct V_298 * V_299 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_72 ;
V_72 = F_13 ( V_8 , & V_299 -> V_73 ,
& V_299 -> V_74 ) ;
if ( V_72 ) {
F_53 ( V_184 , L_19 ,
V_169 , V_72 ) ;
}
}
static int F_106 ( struct V_1 * V_184 ,
struct V_298 * V_299 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_72 ;
if ( V_299 -> V_247 )
return - V_170 ;
V_72 = F_107 ( V_8 ,
V_299 -> V_73 ? 1 : 0 ,
V_299 -> V_74 ? 1 : 0 ) ;
if ( V_72 ) {
F_53 ( V_184 , L_20 ,
V_169 , V_72 ) ;
}
return V_72 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_300 * V_280 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_301 ;
V_301 = F_109 ( V_2 , V_280 ) ;
if ( V_301 )
return V_301 ;
V_280 -> V_302 = V_6 -> V_303 . V_304 ?
F_110 ( V_6 -> V_303 . V_304 ) : - 1 ;
if ( ! F_55 ( V_6 -> V_8 , V_305 ) )
return 0 ;
V_280 -> V_306 |= V_307 |
V_308 |
V_309 ;
V_280 -> V_310 = ( F_111 ( 1 ) << V_311 ) |
( F_111 ( 1 ) << V_312 ) ;
V_280 -> V_313 = ( F_111 ( 1 ) << V_314 ) |
( F_111 ( 1 ) << V_315 ) ;
return 0 ;
}
static T_7 F_112 ( struct V_7 * V_8 )
{
T_7 V_301 = 0 ;
if ( F_55 ( V_8 , V_316 ) )
V_301 |= V_317 ;
if ( F_55 ( V_8 , V_318 ) )
V_301 |= V_319 ;
if ( F_55 ( V_8 , V_320 ) )
V_301 |= V_321 ;
if ( F_55 ( V_8 , V_322 ) )
V_301 |= V_323 ;
if ( F_55 ( V_8 , V_324 ) )
V_301 |= V_325 ;
if ( F_55 ( V_8 , V_326 ) )
V_301 |= V_327 ;
if ( F_55 ( V_8 , V_328 ) )
V_301 |= V_329 ;
return V_301 ;
}
static T_7 F_113 ( T_1 V_330 )
{
T_7 V_301 = 0 ;
if ( V_330 & V_331 )
V_301 |= V_317 ;
if ( V_330 & V_332 )
V_301 |= V_319 ;
if ( V_330 & V_333 )
V_301 |= V_321 ;
if ( V_330 & V_334 )
V_301 |= V_323 ;
if ( V_330 & V_335 )
V_301 |= V_325 ;
if ( V_330 & V_336 )
V_301 |= V_327 ;
if ( V_330 & V_337 )
V_301 |= V_329 ;
return V_301 ;
}
static T_1 F_114 ( T_7 V_330 )
{
T_1 V_301 = 0 ;
if ( V_330 & V_317 )
V_301 |= V_331 ;
if ( V_330 & V_319 )
V_301 |= V_332 ;
if ( V_330 & V_321 )
V_301 |= V_333 ;
if ( V_330 & V_323 )
V_301 |= V_334 ;
if ( V_330 & V_325 )
V_301 |= V_335 ;
if ( V_330 & V_327 )
V_301 |= V_336 ;
if ( V_330 & V_329 )
V_301 |= V_337 ;
return V_301 ;
}
static void F_115 ( struct V_1 * V_184 ,
struct V_338 * V_339 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_340 ;
int V_72 ;
memset ( V_339 , 0 , sizeof( * V_339 ) ) ;
V_339 -> V_208 = F_112 ( V_8 ) ;
if ( ! V_339 -> V_208 )
return;
V_72 = F_116 ( V_8 , & V_340 ) ;
if ( V_72 )
return;
V_339 -> V_341 = F_113 ( V_340 ) ;
}
static int F_117 ( struct V_1 * V_184 , struct V_338 * V_339 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_7 V_342 = F_112 ( V_8 ) ;
T_2 V_340 ;
if ( ! V_342 )
return - V_85 ;
if ( V_339 -> V_341 & ~ V_342 )
return - V_170 ;
V_340 = F_114 ( V_339 -> V_341 ) ;
return F_118 ( V_8 , V_340 ) ;
}
static int F_119 ( struct V_1 * V_2 ,
enum V_343 V_111 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_6 V_344 ;
if ( ! F_55 ( V_8 , V_345 ) )
return - V_85 ;
switch ( V_111 ) {
case V_346 :
V_344 = V_347 ;
break;
case V_348 :
V_344 = V_349 ;
break;
default:
return - V_85 ;
}
return F_120 ( V_8 , V_344 ) ;
}
static int F_121 ( struct V_1 * V_184 ,
struct V_350 * V_351 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
struct V_7 * V_2 = V_6 -> V_8 ;
int V_352 = 0 ;
T_1 V_86 [ 4 ] ;
V_352 = F_122 ( V_2 , 0 , 2 , V_86 ) ;
if ( V_352 < 2 )
return - V_353 ;
switch ( V_86 [ 0 ] ) {
case V_354 :
V_351 -> type = V_355 ;
V_351 -> V_356 = V_357 ;
break;
case V_358 :
case V_359 :
if ( V_86 [ 0 ] == V_359 || V_86 [ 1 ] >= 0x3 ) {
V_351 -> type = V_360 ;
V_351 -> V_356 = V_361 ;
} else {
V_351 -> type = V_355 ;
V_351 -> V_356 = V_357 ;
}
break;
case V_362 :
V_351 -> type = V_363 ;
V_351 -> V_356 = V_364 ;
break;
default:
F_53 ( V_6 -> V_184 , L_21 ,
V_169 , V_86 [ 0 ] ) ;
return - V_170 ;
}
return 0 ;
}
static int F_123 ( struct V_1 * V_184 ,
struct V_365 * V_366 ,
T_1 * V_86 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_367 = V_366 -> V_367 ;
int V_352 ;
int V_87 = 0 ;
if ( ! V_366 -> V_368 )
return - V_170 ;
memset ( V_86 , 0 , V_366 -> V_368 ) ;
while ( V_87 < V_366 -> V_368 ) {
V_352 = F_122 ( V_8 , V_367 , V_366 -> V_368 - V_87 ,
V_86 + V_87 ) ;
if ( ! V_352 )
return 0 ;
if ( V_352 < 0 ) {
F_53 ( V_6 -> V_184 , L_22 ,
V_169 , V_352 ) ;
return 0 ;
}
V_87 += V_352 ;
V_367 += V_352 ;
}
return 0 ;
}
static int F_124 ( struct V_1 * V_184 , bool V_369 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
bool V_370 ;
T_1 V_371 ;
int V_72 = 0 ;
bool V_372 ;
V_371 = V_369 ?
V_373 :
V_374 ;
V_370 = V_371 != V_6 -> V_112 . V_371 ;
if ( V_371 == V_373 &&
! F_55 ( V_8 , V_375 ) )
return - V_85 ;
if ( ! V_370 )
return 0 ;
V_372 = F_23 ( V_110 , & V_6 -> V_111 ) ;
if ( V_372 )
F_45 ( V_184 ) ;
F_125 ( & V_6 -> V_112 , V_371 ) ;
if ( V_372 )
V_72 = F_46 ( V_184 ) ;
return V_72 ;
}
static int F_126 ( struct V_1 * V_184 ,
bool V_369 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_72 = 0 ;
bool V_372 ;
if ( ! F_55 ( V_8 , V_376 ) )
return - V_85 ;
if ( V_369 && V_6 -> V_303 . V_377 . V_378 != V_314 ) {
F_53 ( V_184 , L_23 ) ;
return - V_170 ;
}
V_372 = F_23 ( V_110 , & V_6 -> V_111 ) ;
if ( V_372 )
F_45 ( V_184 ) ;
F_127 ( V_6 , V_379 , V_369 ) ;
V_6 -> V_112 . V_380 = V_369 ;
if ( V_372 )
V_72 = F_46 ( V_184 ) ;
return V_72 ;
}
static int F_128 ( struct V_1 * V_184 ,
T_2 V_381 ,
enum V_382 V_383 ,
T_8 V_384 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
bool V_369 = ! ! ( V_381 & V_383 ) ;
T_2 V_385 = V_381 ^ V_6 -> V_112 . V_386 ;
int V_72 ;
if ( ! ( V_385 & V_383 ) )
return 0 ;
V_72 = V_384 ( V_184 , V_369 ) ;
if ( V_72 ) {
F_53 ( V_184 , L_24 ,
V_369 ? L_25 : L_26 , V_383 , V_72 ) ;
return V_72 ;
}
F_127 ( V_6 , V_383 , V_369 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_184 , T_2 V_386 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
int V_72 ;
F_26 ( & V_6 -> V_125 ) ;
V_72 = F_128 ( V_184 , V_386 ,
V_387 ,
F_124 ) ;
if ( V_72 )
goto V_183;
V_72 = F_128 ( V_184 , V_386 ,
V_379 ,
F_126 ) ;
V_183:
F_28 ( & V_6 -> V_125 ) ;
return V_72 ;
}
static T_2 F_130 ( struct V_1 * V_184 )
{
struct V_5 * V_6 = F_2 ( V_184 ) ;
return V_6 -> V_112 . V_386 ;
}
static int F_131 ( struct V_1 * V_2 , struct V_279 * V_282 )
{
int V_72 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_282 -> V_282 ) {
case V_388 :
V_72 = F_132 ( V_6 , & V_282 -> V_286 ) ;
break;
case V_389 :
V_72 = F_133 ( V_6 , V_282 -> V_286 . V_290 ) ;
break;
default:
V_72 = - V_85 ;
break;
}
return V_72 ;
}
