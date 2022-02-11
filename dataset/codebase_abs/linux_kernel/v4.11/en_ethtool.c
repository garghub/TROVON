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
V_78 + F_16 ( V_6 ) +
F_17 ( V_6 ) +
F_18 ( V_6 ) +
F_19 ( V_6 ) +
F_20 ( V_6 ) +
F_21 ( V_79 ) +
F_21 ( V_80 ) ;
case V_81 :
return F_21 ( V_82 ) ;
case V_83 :
return F_22 ( V_6 ) ;
default:
return - V_84 ;
}
}
static void F_23 ( struct V_5 * V_6 , T_3 * V_85 )
{
int V_86 , V_87 , V_88 , V_89 , V_90 = 0 ;
unsigned long V_91 ;
for ( V_86 = 0 ; V_86 < V_77 ; V_86 ++ )
strcpy ( V_85 + ( V_90 ++ ) * V_92 , V_93 [ V_86 ] . V_94 ) ;
for ( V_86 = 0 ; V_86 < F_15 ( V_6 ) ; V_86 ++ )
strcpy ( V_85 + ( V_90 ++ ) * V_92 , V_95 [ V_86 ] . V_94 ) ;
for ( V_86 = 0 ; V_86 < V_78 ; V_86 ++ )
strcpy ( V_85 + ( V_90 ++ ) * V_92 ,
V_96 [ V_86 ] . V_94 ) ;
for ( V_86 = 0 ; V_86 < V_97 ; V_86 ++ )
strcpy ( V_85 + ( V_90 ++ ) * V_92 ,
V_98 [ V_86 ] . V_94 ) ;
for ( V_86 = 0 ; V_86 < V_99 ; V_86 ++ )
strcpy ( V_85 + ( V_90 ++ ) * V_92 ,
V_100 [ V_86 ] . V_94 ) ;
for ( V_86 = 0 ; V_86 < V_101 ; V_86 ++ )
strcpy ( V_85 + ( V_90 ++ ) * V_92 ,
V_102 [ V_86 ] . V_94 ) ;
for ( V_86 = 0 ; V_86 < F_24 ( V_6 ) ; V_86 ++ )
strcpy ( V_85 + ( V_90 ++ ) * V_92 ,
V_103 [ V_86 ] . V_94 ) ;
for ( V_86 = 0 ; V_86 < F_25 ( V_6 ) ; V_86 ++ )
strcpy ( V_85 + ( V_90 ++ ) * V_92 ,
V_104 [ V_86 ] . V_94 ) ;
for ( V_89 = 0 ; V_89 < V_105 ; V_89 ++ ) {
for ( V_86 = 0 ; V_86 < V_106 ; V_86 ++ )
sprintf ( V_85 + ( V_90 ++ ) * V_92 ,
V_107 [ V_86 ] . V_94 , V_89 ) ;
}
V_91 = F_10 ( V_6 ) ;
F_26 (prio, &pfc_combined, NUM_PPORT_PRIO) {
for ( V_86 = 0 ; V_86 < V_108 ; V_86 ++ ) {
char V_109 [ V_92 ] ;
snprintf ( V_109 , sizeof( V_109 ) , L_4 , V_89 ) ;
sprintf ( V_85 + ( V_90 ++ ) * V_92 ,
V_110 [ V_86 ] . V_94 , V_109 ) ;
}
}
if ( F_12 ( V_6 ) ) {
for ( V_86 = 0 ; V_86 < V_108 ; V_86 ++ ) {
sprintf ( V_85 + ( V_90 ++ ) * V_92 ,
V_110 [ V_86 ] . V_94 , L_5 ) ;
}
}
for ( V_86 = 0 ; V_86 < F_21 ( V_79 ) ; V_86 ++ )
strcpy ( V_85 + ( V_90 ++ ) * V_92 , V_79 [ V_86 ] . V_94 ) ;
for ( V_86 = 0 ; V_86 < F_21 ( V_80 ) ; V_86 ++ )
strcpy ( V_85 + ( V_90 ++ ) * V_92 , V_80 [ V_86 ] . V_94 ) ;
if ( ! F_27 ( V_111 , & V_6 -> V_112 ) )
return;
for ( V_86 = 0 ; V_86 < V_6 -> V_113 . V_114 ; V_86 ++ )
for ( V_87 = 0 ; V_87 < V_115 ; V_87 ++ )
sprintf ( V_85 + ( V_90 ++ ) * V_92 ,
V_116 [ V_87 ] . V_94 , V_86 ) ;
for ( V_88 = 0 ; V_88 < V_6 -> V_113 . V_117 ; V_88 ++ )
for ( V_86 = 0 ; V_86 < V_6 -> V_113 . V_114 ; V_86 ++ )
for ( V_87 = 0 ; V_87 < V_118 ; V_87 ++ )
sprintf ( V_85 + ( V_90 ++ ) * V_92 ,
V_119 [ V_87 ] . V_94 ,
V_6 -> V_120 [ V_86 ] [ V_88 ] ) ;
}
static void F_28 ( struct V_1 * V_2 ,
T_4 V_121 , T_3 * V_85 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_86 ;
switch ( V_121 ) {
case V_81 :
for ( V_86 = 0 ; V_86 < F_21 ( V_82 ) ; V_86 ++ )
strcpy ( V_85 + V_86 * V_92 , V_82 [ V_86 ] ) ;
break;
case V_83 :
for ( V_86 = 0 ; V_86 < F_22 ( V_6 ) ; V_86 ++ )
strcpy ( V_85 + V_86 * V_92 ,
V_122 [ V_86 ] ) ;
break;
case V_76 :
F_23 ( V_6 , V_85 ) ;
break;
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_123 * V_124 , T_5 * V_85 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_125 * V_125 ;
int V_86 , V_87 , V_88 , V_89 , V_90 = 0 ;
unsigned long V_91 ;
if ( ! V_85 )
return;
F_30 ( & V_6 -> V_126 ) ;
if ( F_27 ( V_111 , & V_6 -> V_112 ) )
F_31 ( V_6 ) ;
F_32 ( & V_6 -> V_126 ) ;
for ( V_86 = 0 ; V_86 < V_77 ; V_86 ++ )
V_85 [ V_90 ++ ] = F_33 ( & V_6 -> V_124 . V_127 ,
V_93 , V_86 ) ;
for ( V_86 = 0 ; V_86 < F_15 ( V_6 ) ; V_86 ++ )
V_85 [ V_90 ++ ] = F_34 ( & V_6 -> V_124 . V_128 ,
V_95 , V_86 ) ;
for ( V_86 = 0 ; V_86 < V_78 ; V_86 ++ )
V_85 [ V_90 ++ ] = F_35 ( V_6 -> V_124 . V_129 . V_130 ,
V_96 , V_86 ) ;
for ( V_86 = 0 ; V_86 < V_97 ; V_86 ++ )
V_85 [ V_90 ++ ] = F_35 ( & V_6 -> V_124 . V_131 . V_132 ,
V_98 , V_86 ) ;
for ( V_86 = 0 ; V_86 < V_99 ; V_86 ++ )
V_85 [ V_90 ++ ] = F_35 ( & V_6 -> V_124 . V_131 . V_133 ,
V_100 , V_86 ) ;
for ( V_86 = 0 ; V_86 < V_101 ; V_86 ++ )
V_85 [ V_90 ++ ] = F_35 ( & V_6 -> V_124 . V_131 . V_134 ,
V_102 , V_86 ) ;
for ( V_86 = 0 ; V_86 < F_24 ( V_6 ) ; V_86 ++ )
V_85 [ V_90 ++ ] = F_35 ( & V_6 -> V_124 . V_131 . V_135 ,
V_103 , V_86 ) ;
for ( V_86 = 0 ; V_86 < F_25 ( V_6 ) ; V_86 ++ )
V_85 [ V_90 ++ ] = F_36 ( & V_6 -> V_124 . V_136 . V_137 ,
V_104 , V_86 ) ;
for ( V_89 = 0 ; V_89 < V_105 ; V_89 ++ ) {
for ( V_86 = 0 ; V_86 < V_106 ; V_86 ++ )
V_85 [ V_90 ++ ] = F_35 ( & V_6 -> V_124 . V_131 . V_138 [ V_89 ] ,
V_107 , V_86 ) ;
}
V_91 = F_10 ( V_6 ) ;
F_26 (prio, &pfc_combined, NUM_PPORT_PRIO) {
for ( V_86 = 0 ; V_86 < V_108 ; V_86 ++ ) {
V_85 [ V_90 ++ ] = F_35 ( & V_6 -> V_124 . V_131 . V_138 [ V_89 ] ,
V_110 , V_86 ) ;
}
}
if ( F_12 ( V_6 ) ) {
for ( V_86 = 0 ; V_86 < V_108 ; V_86 ++ ) {
V_85 [ V_90 ++ ] = F_35 ( & V_6 -> V_124 . V_131 . V_138 [ 0 ] ,
V_110 , V_86 ) ;
}
}
V_125 = & V_6 -> V_8 -> V_6 ;
for ( V_86 = 0 ; V_86 < F_21 ( V_79 ) ; V_86 ++ )
V_85 [ V_90 ++ ] = F_33 ( V_125 -> V_139 . V_140 ,
V_79 , V_86 ) ;
for ( V_86 = 0 ; V_86 < F_21 ( V_80 ) ; V_86 ++ )
V_85 [ V_90 ++ ] = F_33 ( V_125 -> V_139 . V_141 ,
V_80 , V_86 ) ;
if ( ! F_27 ( V_111 , & V_6 -> V_112 ) )
return;
for ( V_86 = 0 ; V_86 < V_6 -> V_113 . V_114 ; V_86 ++ )
for ( V_87 = 0 ; V_87 < V_115 ; V_87 ++ )
V_85 [ V_90 ++ ] =
F_33 ( & V_6 -> V_142 [ V_86 ] -> V_143 . V_124 ,
V_116 , V_87 ) ;
for ( V_88 = 0 ; V_88 < V_6 -> V_113 . V_117 ; V_88 ++ )
for ( V_86 = 0 ; V_86 < V_6 -> V_113 . V_114 ; V_86 ++ )
for ( V_87 = 0 ; V_87 < V_118 ; V_87 ++ )
V_85 [ V_90 ++ ] = F_33 ( & V_6 -> V_142 [ V_86 ] -> V_144 [ V_88 ] . V_124 ,
V_119 , V_87 ) ;
}
static T_2 F_37 ( struct V_5 * V_6 , int V_145 ,
int V_146 )
{
int V_147 ;
int V_148 ;
int V_149 ;
int V_150 ;
if ( V_145 != V_151 )
return V_146 ;
V_148 = 1 << V_6 -> V_113 . V_152 ;
V_149 = 1 << V_6 -> V_113 . V_153 ;
V_150 = V_148 * V_149 ;
V_147 = V_150 /
F_38 ( V_154 , V_148 ) ;
return ( 1 << ( F_39 ( V_146 * V_147 ) - 1 ) ) ;
}
static T_2 F_40 ( struct V_5 * V_6 , int V_145 ,
int V_155 )
{
int V_147 ;
int V_148 ;
int V_149 ;
int V_150 ;
int V_156 ;
if ( V_145 != V_151 )
return V_155 ;
V_148 = 1 << V_6 -> V_113 . V_152 ;
V_149 = 1 << V_6 -> V_113 . V_153 ;
V_150 = V_148 * V_149 ;
V_155 = ( 1 << F_39 ( V_155 ) ) ;
V_147 = V_150 /
F_38 ( V_154 , V_148 ) ;
V_156 = F_41 ( V_155 , V_147 ) ;
return 1 << ( F_39 ( V_156 ) ) ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_157 * V_158 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_145 = V_6 -> V_113 . V_145 ;
V_158 -> V_159 = F_37 ( V_6 , V_145 ,
1 << F_43 ( V_145 ) ) ;
V_158 -> V_160 = 1 << V_161 ;
V_158 -> V_162 = F_37 ( V_6 , V_145 ,
1 << V_6 -> V_113 . V_163 ) ;
V_158 -> V_164 = 1 << V_6 -> V_113 . V_165 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_157 * V_158 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
bool V_166 ;
int V_145 = V_6 -> V_113 . V_145 ;
T_2 V_167 ;
T_2 V_168 ;
T_2 V_169 ;
T_6 V_170 ;
T_1 V_163 ;
T_1 V_165 ;
T_2 V_171 ;
int V_72 = 0 ;
if ( V_158 -> V_172 ) {
F_45 ( V_2 , L_6 ,
V_173 ) ;
return - V_174 ;
}
if ( V_158 -> V_175 ) {
F_45 ( V_2 , L_7 ,
V_173 ) ;
return - V_174 ;
}
V_168 = F_37 ( V_6 , V_145 ,
1 << F_46 ( V_145 ) ) ;
V_169 = F_37 ( V_6 , V_145 ,
1 << F_43 ( V_145 ) ) ;
V_167 = F_40 ( V_6 , V_145 ,
V_158 -> V_162 ) ;
if ( V_158 -> V_162 < V_168 ) {
F_45 ( V_2 , L_8 ,
V_173 , V_158 -> V_162 ,
V_168 ) ;
return - V_174 ;
}
if ( V_158 -> V_162 > V_169 ) {
F_45 ( V_2 , L_9 ,
V_173 , V_158 -> V_162 ,
V_169 ) ;
return - V_174 ;
}
V_171 = F_47 ( V_167 ) ;
if ( V_6 -> V_113 . V_145 == V_151 &&
! F_48 ( V_171 ) ) {
F_45 ( V_2 , L_10 ,
V_173 , V_158 -> V_162 ) ;
return - V_174 ;
}
if ( V_158 -> V_164 < ( 1 << V_176 ) ) {
F_45 ( V_2 , L_11 ,
V_173 , V_158 -> V_164 ,
1 << V_176 ) ;
return - V_174 ;
}
if ( V_158 -> V_164 > ( 1 << V_161 ) ) {
F_45 ( V_2 , L_12 ,
V_173 , V_158 -> V_164 ,
1 << V_161 ) ;
return - V_174 ;
}
V_163 = F_39 ( V_167 ) ;
V_165 = F_39 ( V_158 -> V_164 ) ;
V_170 = F_49 ( V_145 , V_167 ) ;
if ( V_163 == V_6 -> V_113 . V_163 &&
V_165 == V_6 -> V_113 . V_165 &&
V_170 == V_6 -> V_113 . V_170 )
return 0 ;
F_30 ( & V_6 -> V_126 ) ;
V_166 = F_27 ( V_111 , & V_6 -> V_112 ) ;
if ( V_166 )
F_50 ( V_2 ) ;
V_6 -> V_113 . V_163 = V_163 ;
V_6 -> V_113 . V_165 = V_165 ;
V_6 -> V_113 . V_170 = V_170 ;
if ( V_166 )
V_72 = F_51 ( V_2 ) ;
F_32 ( & V_6 -> V_126 ) ;
return V_72 ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_177 * V_178 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_178 -> V_179 = V_6 -> V_180 -> V_181 ( V_6 -> V_8 ) ;
V_178 -> V_182 = V_6 -> V_113 . V_114 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_177 * V_178 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_183 = V_178 -> V_182 ;
bool V_184 ;
bool V_166 ;
int V_72 = 0 ;
if ( ! V_183 ) {
F_45 ( V_2 , L_13 ,
V_173 ) ;
return - V_174 ;
}
if ( V_6 -> V_113 . V_114 == V_183 )
return 0 ;
F_30 ( & V_6 -> V_126 ) ;
V_166 = F_27 ( V_111 , & V_6 -> V_112 ) ;
if ( V_166 )
F_50 ( V_2 ) ;
V_184 = V_2 -> V_185 & V_186 ;
if ( V_184 )
F_54 ( V_6 ) ;
V_6 -> V_113 . V_114 = V_183 ;
F_55 ( V_6 -> V_8 , V_6 -> V_113 . V_187 ,
V_188 , V_183 ) ;
if ( V_166 )
V_72 = F_51 ( V_2 ) ;
if ( V_72 )
goto V_189;
if ( V_184 ) {
V_72 = F_56 ( V_6 ) ;
if ( V_72 )
F_57 ( V_2 , L_14 ,
V_173 , V_72 ) ;
}
V_189:
F_32 ( & V_6 -> V_126 ) ;
return V_72 ;
}
static int F_58 ( struct V_1 * V_190 ,
struct V_191 * V_192 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
if ( ! F_59 ( V_6 -> V_8 , V_193 ) )
return - V_84 ;
V_192 -> V_194 = V_6 -> V_113 . V_195 . V_196 ;
V_192 -> V_197 = V_6 -> V_113 . V_195 . V_198 ;
V_192 -> V_199 = V_6 -> V_113 . V_200 . V_196 ;
V_192 -> V_201 = V_6 -> V_113 . V_200 . V_198 ;
V_192 -> V_202 = V_6 -> V_113 . V_203 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_190 ,
struct V_191 * V_192 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_204 * V_205 ;
bool V_206 =
! ! V_192 -> V_202 != V_6 -> V_113 . V_203 ;
bool V_166 ;
int V_72 = 0 ;
int V_88 ;
int V_86 ;
if ( ! F_59 ( V_8 , V_193 ) )
return - V_84 ;
F_30 ( & V_6 -> V_126 ) ;
V_166 = F_27 ( V_111 , & V_6 -> V_112 ) ;
if ( V_166 && V_206 ) {
F_50 ( V_190 ) ;
V_6 -> V_113 . V_203 = ! ! V_192 -> V_202 ;
}
V_6 -> V_113 . V_200 . V_196 = V_192 -> V_199 ;
V_6 -> V_113 . V_200 . V_198 = V_192 -> V_201 ;
V_6 -> V_113 . V_195 . V_196 = V_192 -> V_194 ;
V_6 -> V_113 . V_195 . V_198 = V_192 -> V_197 ;
if ( ! V_166 || V_206 )
goto V_189;
for ( V_86 = 0 ; V_86 < V_6 -> V_113 . V_114 ; ++ V_86 ) {
V_205 = V_6 -> V_142 [ V_86 ] ;
for ( V_88 = 0 ; V_88 < V_205 -> V_117 ; V_88 ++ ) {
F_61 ( V_8 ,
& V_205 -> V_144 [ V_88 ] . V_207 . V_208 ,
V_192 -> V_199 ,
V_192 -> V_201 ) ;
}
F_61 ( V_8 , & V_205 -> V_143 . V_207 . V_208 ,
V_192 -> V_194 ,
V_192 -> V_197 ) ;
}
V_189:
if ( V_166 && V_206 )
V_72 = F_51 ( V_190 ) ;
F_32 ( & V_6 -> V_126 ) ;
return V_72 ;
}
static void F_62 ( unsigned long * V_209 ,
T_2 V_210 )
{
unsigned long V_211 = V_210 ;
int V_212 ;
F_26 (proto, &proto_cap, MLX5E_LINK_MODES_NUMBER)
F_63 ( V_209 , V_209 ,
V_213 [ V_212 ] . V_214 ,
V_215 ) ;
}
static void F_64 ( unsigned long * V_216 ,
T_2 V_210 )
{
unsigned long V_211 = V_210 ;
int V_212 ;
F_26 (proto, &proto_cap, MLX5E_LINK_MODES_NUMBER)
F_63 ( V_216 , V_216 ,
V_213 [ V_212 ] . V_217 ,
V_215 ) ;
}
static void F_65 ( struct V_218 * V_219 ,
T_2 V_210 )
{
if ( V_210 & ( F_66 ( V_38 )
| F_66 ( V_39 )
| F_66 ( V_30 )
| F_66 ( V_41 )
| F_66 ( V_51 )
| F_66 ( V_17 ) ) ) {
F_67 ( V_219 , V_214 , V_220 ) ;
}
if ( V_210 & ( F_66 ( V_53 )
| F_66 ( V_33 )
| F_66 ( V_25 )
| F_66 ( V_24 )
| F_66 ( V_20 ) ) ) {
F_67 ( V_219 , V_214 , V_221 ) ;
}
}
int F_68 ( struct V_7 * V_8 , T_2 * V_222 )
{
T_2 V_223 = 0 ;
T_2 V_211 ;
int V_72 ;
int V_86 ;
V_72 = F_69 ( V_8 , & V_211 , V_224 ) ;
if ( V_72 )
return V_72 ;
for ( V_86 = 0 ; V_86 < V_225 ; ++ V_86 )
if ( V_211 & F_66 ( V_86 ) )
V_223 = F_70 ( V_223 , V_213 [ V_86 ] . V_222 ) ;
* V_222 = V_223 ;
return 0 ;
}
static void F_71 ( struct V_1 * V_190 ,
T_2 V_226 ,
struct V_218 * V_219 )
{
int V_86 ;
T_2 V_222 = V_227 ;
T_1 V_228 = V_229 ;
if ( ! F_72 ( V_190 ) )
goto V_189;
for ( V_86 = 0 ; V_86 < V_225 ; ++ V_86 ) {
if ( V_226 & F_66 ( V_86 ) ) {
V_222 = V_213 [ V_86 ] . V_222 ;
V_228 = V_230 ;
break;
}
}
V_189:
V_219 -> V_231 . V_222 = V_222 ;
V_219 -> V_231 . V_228 = V_228 ;
}
static void F_73 ( T_2 V_210 ,
struct V_218 * V_219 )
{
unsigned long * V_214 = V_219 -> V_232 . V_214 ;
F_65 ( V_219 , V_210 ) ;
F_62 ( V_214 , V_210 ) ;
F_67 ( V_219 , V_214 , V_233 ) ;
F_67 ( V_219 , V_214 , V_234 ) ;
}
static void F_74 ( T_2 V_210 , T_1 V_74 ,
T_1 V_73 ,
struct V_218 * V_219 )
{
unsigned long * V_235 = V_219 -> V_232 . V_235 ;
F_64 ( V_235 , V_210 ) ;
if ( V_74 )
F_67 ( V_219 , V_235 , V_233 ) ;
if ( V_74 ^ V_73 )
F_67 ( V_219 , V_235 , V_234 ) ;
}
static T_1 F_75 ( T_2 V_236 )
{
if ( V_236 & ( F_66 ( V_39 )
| F_66 ( V_41 )
| F_66 ( V_51 )
| F_66 ( V_17 ) ) ) {
return V_237 ;
}
if ( V_236 & ( F_66 ( V_30 )
| F_66 ( V_38 )
| F_66 ( V_48 ) ) ) {
return V_238 ;
}
if ( V_236 & ( F_66 ( V_24 )
| F_66 ( V_25 )
| F_66 ( V_33 )
| F_66 ( V_53 ) ) ) {
return V_239 ;
}
return V_240 ;
}
static void F_76 ( T_2 V_241 ,
struct V_218 * V_219 )
{
unsigned long * V_242 = V_219 -> V_232 . V_242 ;
F_64 ( V_242 , V_241 ) ;
}
static int F_77 ( struct V_1 * V_190 ,
struct V_218 * V_219 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_189 [ F_78 ( V_243 ) ] = { 0 } ;
T_2 V_210 ;
T_2 V_244 ;
T_2 V_241 ;
T_2 V_226 ;
T_1 V_245 ;
T_1 V_246 ;
int V_72 ;
V_72 = F_79 ( V_8 , V_189 , sizeof( V_189 ) , V_224 , 1 ) ;
if ( V_72 ) {
F_57 ( V_190 , L_15 ,
V_173 , V_72 ) ;
goto V_247;
}
V_210 = F_80 ( V_243 , V_189 , V_248 ) ;
V_244 = F_80 ( V_243 , V_189 , V_244 ) ;
V_226 = F_80 ( V_243 , V_189 , V_226 ) ;
V_241 = F_80 ( V_243 , V_189 , V_249 ) ;
V_245 = F_80 ( V_243 , V_189 , V_245 ) ;
V_246 = F_80 ( V_243 , V_189 , V_246 ) ;
F_81 ( V_219 , V_214 ) ;
F_81 ( V_219 , V_235 ) ;
F_73 ( V_210 , V_219 ) ;
F_74 ( V_244 , 0 , 0 , V_219 ) ;
F_71 ( V_190 , V_226 , V_219 ) ;
V_226 = V_226 ? V_226 : V_210 ;
V_219 -> V_231 . V_250 = F_75 ( V_226 ) ;
F_76 ( V_241 , V_219 ) ;
if ( V_246 == V_251 )
F_67 ( V_219 ,
V_242 , V_252 ) ;
V_219 -> V_231 . V_253 = V_245 ? V_254 :
V_255 ;
F_67 ( V_219 , V_214 ,
V_252 ) ;
if ( ! V_245 )
F_67 ( V_219 ,
V_235 , V_252 ) ;
V_247:
return V_72 ;
}
static T_2 F_82 ( const unsigned long * V_232 )
{
T_2 V_86 , V_256 = 0 ;
for ( V_86 = 0 ; V_86 < V_225 ; ++ V_86 ) {
if ( F_83 ( V_213 [ V_86 ] . V_217 ,
V_232 ,
V_215 ) )
V_256 |= F_66 ( V_86 ) ;
}
return V_256 ;
}
static T_2 F_84 ( T_2 V_222 )
{
T_2 V_86 , V_257 = 0 ;
for ( V_86 = 0 ; V_86 < V_225 ; ++ V_86 ) {
if ( V_213 [ V_86 ] . V_222 == V_222 )
V_257 |= F_66 ( V_86 ) ;
}
return V_257 ;
}
static int F_85 ( struct V_1 * V_190 ,
const struct V_218 * V_219 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_210 , V_244 ;
bool V_258 = false ;
T_1 V_245 ;
T_1 V_259 ;
bool V_260 ;
T_2 V_232 ;
T_1 V_246 ;
T_2 V_222 ;
int V_72 ;
V_222 = V_219 -> V_231 . V_222 ;
V_232 = V_219 -> V_231 . V_253 == V_255 ?
F_82 ( V_219 -> V_232 . V_235 ) :
F_84 ( V_222 ) ;
V_72 = F_69 ( V_8 , & V_210 , V_224 ) ;
if ( V_72 ) {
F_57 ( V_190 , L_16 ,
V_173 , V_72 ) ;
goto V_189;
}
V_232 = V_232 & V_210 ;
if ( ! V_232 ) {
F_57 ( V_190 , L_17 ,
V_173 ) ;
V_72 = - V_174 ;
goto V_189;
}
V_72 = F_86 ( V_8 , & V_244 , V_224 ) ;
if ( V_72 ) {
F_57 ( V_190 , L_18 ,
V_173 , V_72 ) ;
goto V_189;
}
F_87 ( V_8 , V_224 , & V_246 ,
& V_259 , & V_245 ) ;
V_260 = V_219 -> V_231 . V_253 == V_254 ;
V_258 = ( ( ! V_260 && V_245 ) ||
( V_260 && ! V_245 ) ) ;
if ( ! V_258 && V_232 == V_244 )
goto V_189;
F_88 ( V_8 , V_260 , V_232 , V_224 ) ;
F_89 ( V_8 ) ;
V_189:
return V_72 ;
}
static T_2 F_90 ( struct V_1 * V_190 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
return sizeof( V_6 -> V_113 . V_261 ) ;
}
static T_2 F_91 ( struct V_1 * V_190 )
{
return V_188 ;
}
static int F_92 ( struct V_1 * V_190 , T_2 * V_262 , T_1 * V_263 ,
T_1 * V_264 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
if ( V_262 )
memcpy ( V_262 , V_6 -> V_113 . V_187 ,
sizeof( V_6 -> V_113 . V_187 ) ) ;
if ( V_263 )
memcpy ( V_263 , V_6 -> V_113 . V_261 ,
sizeof( V_6 -> V_113 . V_261 ) ) ;
if ( V_264 )
* V_264 = V_6 -> V_113 . V_265 ;
return 0 ;
}
static void F_93 ( struct V_5 * V_6 , void * V_266 , int V_267 )
{
void * V_268 = F_94 ( V_269 , V_266 , V_270 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_271 = F_95 ( V_268 ) ;
int V_272 ;
F_96 ( V_269 , V_266 , V_273 . V_274 , 1 ) ;
for ( V_272 = 0 ; V_272 < V_275 ; V_272 ++ ) {
memset ( V_268 , 0 , V_271 ) ;
F_97 ( V_6 , V_268 , V_272 ) ;
F_98 ( V_8 , V_6 -> V_276 [ V_272 ] . V_277 , V_266 , V_267 ) ;
}
}
static int F_99 ( struct V_1 * V_2 , const T_2 * V_262 ,
const T_1 * V_263 , const T_1 V_264 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_267 = F_95 ( V_269 ) ;
bool V_278 = false ;
void * V_266 ;
if ( ( V_264 != V_279 ) &&
( V_264 != V_280 ) &&
( V_264 != V_281 ) )
return - V_174 ;
V_266 = F_100 ( V_267 ) ;
if ( ! V_266 )
return - V_282 ;
F_30 ( & V_6 -> V_126 ) ;
if ( V_262 ) {
T_2 V_283 = V_6 -> V_284 . V_283 ;
memcpy ( V_6 -> V_113 . V_187 , V_262 ,
sizeof( V_6 -> V_113 . V_187 ) ) ;
F_101 ( V_6 , V_283 , V_188 , 0 ) ;
}
if ( V_264 != V_279 &&
V_264 != V_6 -> V_113 . V_265 ) {
V_6 -> V_113 . V_265 = V_264 ;
V_278 = true ;
}
if ( V_263 ) {
memcpy ( V_6 -> V_113 . V_261 , V_263 ,
sizeof( V_6 -> V_113 . V_261 ) ) ;
V_278 = V_278 ||
V_6 -> V_113 . V_265 == V_281 ;
}
if ( V_278 )
F_93 ( V_6 , V_266 , V_267 ) ;
F_32 ( & V_6 -> V_126 ) ;
F_102 ( V_266 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_190 ,
struct V_285 * V_286 , T_2 * V_287 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
int V_72 = 0 ;
switch ( V_286 -> V_288 ) {
case V_289 :
V_286 -> V_85 = V_6 -> V_113 . V_114 ;
break;
case V_290 :
V_286 -> V_291 = V_6 -> V_292 . V_293 . V_294 ;
break;
case V_295 :
V_72 = F_104 ( V_6 , V_286 , V_286 -> V_292 . V_296 ) ;
break;
case V_297 :
V_72 = F_105 ( V_6 , V_286 , V_287 ) ;
break;
default:
V_72 = - V_84 ;
break;
}
return V_72 ;
}
static int F_106 ( struct V_1 * V_2 ,
const struct V_298 * V_299 ,
void * V_85 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_72 = 0 ;
switch ( V_299 -> V_300 ) {
case V_301 :
* ( T_2 * ) V_85 = V_6 -> V_113 . V_302 ;
break;
default:
V_72 = - V_174 ;
break;
}
return V_72 ;
}
static int F_107 ( struct V_1 * V_2 ,
const struct V_298 * V_299 ,
const void * V_85 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
bool V_166 ;
T_2 V_303 ;
int V_72 = 0 ;
switch ( V_299 -> V_300 ) {
case V_301 :
V_303 = * ( T_2 * ) V_85 ;
if ( V_303 > F_108 ( V_8 ) ) {
V_72 = - V_174 ;
break;
}
F_30 ( & V_6 -> V_126 ) ;
V_166 = F_27 ( V_111 , & V_6 -> V_112 ) ;
if ( V_166 )
F_50 ( V_2 ) ;
V_6 -> V_113 . V_302 = V_303 ;
if ( V_166 )
V_72 = F_51 ( V_2 ) ;
F_32 ( & V_6 -> V_126 ) ;
break;
default:
V_72 = - V_174 ;
break;
}
return V_72 ;
}
static void F_109 ( struct V_1 * V_190 ,
struct V_304 * V_305 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_72 ;
V_72 = F_13 ( V_8 , & V_305 -> V_73 ,
& V_305 -> V_74 ) ;
if ( V_72 ) {
F_57 ( V_190 , L_19 ,
V_173 , V_72 ) ;
}
}
static int F_110 ( struct V_1 * V_190 ,
struct V_304 * V_305 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_72 ;
if ( V_305 -> V_253 )
return - V_174 ;
V_72 = F_111 ( V_8 ,
V_305 -> V_73 ? 1 : 0 ,
V_305 -> V_74 ? 1 : 0 ) ;
if ( V_72 ) {
F_57 ( V_190 , L_20 ,
V_173 , V_72 ) ;
}
return V_72 ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_306 * V_286 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_307 ;
V_307 = F_113 ( V_2 , V_286 ) ;
if ( V_307 )
return V_307 ;
V_286 -> V_308 = V_6 -> V_309 . V_310 ?
F_114 ( V_6 -> V_309 . V_310 ) : - 1 ;
if ( ! F_59 ( V_6 -> V_8 , V_311 ) )
return 0 ;
V_286 -> V_312 |= V_313 |
V_314 |
V_315 ;
V_286 -> V_316 = ( F_115 ( 1 ) << V_317 ) |
( F_115 ( 1 ) << V_318 ) ;
V_286 -> V_319 = ( F_115 ( 1 ) << V_320 ) |
( F_115 ( 1 ) << V_321 ) ;
return 0 ;
}
static T_7 F_116 ( struct V_7 * V_8 )
{
T_7 V_307 = 0 ;
if ( F_59 ( V_8 , V_322 ) )
V_307 |= V_323 ;
if ( F_59 ( V_8 , V_324 ) )
V_307 |= V_325 ;
if ( F_59 ( V_8 , V_326 ) )
V_307 |= V_327 ;
if ( F_59 ( V_8 , V_328 ) )
V_307 |= V_329 ;
if ( F_59 ( V_8 , V_330 ) )
V_307 |= V_331 ;
if ( F_59 ( V_8 , V_332 ) )
V_307 |= V_333 ;
if ( F_59 ( V_8 , V_334 ) )
V_307 |= V_335 ;
return V_307 ;
}
static T_7 F_117 ( T_1 V_336 )
{
T_7 V_307 = 0 ;
if ( V_336 & V_337 )
V_307 |= V_323 ;
if ( V_336 & V_338 )
V_307 |= V_325 ;
if ( V_336 & V_339 )
V_307 |= V_327 ;
if ( V_336 & V_340 )
V_307 |= V_329 ;
if ( V_336 & V_341 )
V_307 |= V_331 ;
if ( V_336 & V_342 )
V_307 |= V_333 ;
if ( V_336 & V_343 )
V_307 |= V_335 ;
return V_307 ;
}
static T_1 F_118 ( T_7 V_336 )
{
T_1 V_307 = 0 ;
if ( V_336 & V_323 )
V_307 |= V_337 ;
if ( V_336 & V_325 )
V_307 |= V_338 ;
if ( V_336 & V_327 )
V_307 |= V_339 ;
if ( V_336 & V_329 )
V_307 |= V_340 ;
if ( V_336 & V_331 )
V_307 |= V_341 ;
if ( V_336 & V_333 )
V_307 |= V_342 ;
if ( V_336 & V_335 )
V_307 |= V_343 ;
return V_307 ;
}
static void F_119 ( struct V_1 * V_190 ,
struct V_344 * V_345 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_346 ;
int V_72 ;
memset ( V_345 , 0 , sizeof( * V_345 ) ) ;
V_345 -> V_214 = F_116 ( V_8 ) ;
if ( ! V_345 -> V_214 )
return;
V_72 = F_120 ( V_8 , & V_346 ) ;
if ( V_72 )
return;
V_345 -> V_347 = F_117 ( V_346 ) ;
}
static int F_121 ( struct V_1 * V_190 , struct V_344 * V_345 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_7 V_348 = F_116 ( V_8 ) ;
T_2 V_346 ;
if ( ! V_348 )
return - V_84 ;
if ( V_345 -> V_347 & ~ V_348 )
return - V_174 ;
V_346 = F_118 ( V_345 -> V_347 ) ;
return F_122 ( V_8 , V_346 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
enum V_349 V_112 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_6 V_350 ;
if ( ! F_59 ( V_8 , V_351 ) )
return - V_84 ;
switch ( V_112 ) {
case V_352 :
V_350 = V_353 ;
break;
case V_354 :
V_350 = V_355 ;
break;
default:
return - V_84 ;
}
return F_124 ( V_8 , V_350 ) ;
}
static int F_125 ( struct V_1 * V_190 ,
struct V_356 * V_357 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
struct V_7 * V_2 = V_6 -> V_8 ;
int V_358 = 0 ;
T_1 V_85 [ 4 ] ;
V_358 = F_126 ( V_2 , 0 , 2 , V_85 ) ;
if ( V_358 < 2 )
return - V_359 ;
switch ( V_85 [ 0 ] ) {
case V_360 :
V_357 -> type = V_361 ;
V_357 -> V_362 = V_363 ;
break;
case V_364 :
case V_365 :
if ( V_85 [ 0 ] == V_365 || V_85 [ 1 ] >= 0x3 ) {
V_357 -> type = V_366 ;
V_357 -> V_362 = V_367 ;
} else {
V_357 -> type = V_361 ;
V_357 -> V_362 = V_363 ;
}
break;
case V_368 :
V_357 -> type = V_369 ;
V_357 -> V_362 = V_370 ;
break;
default:
F_57 ( V_6 -> V_190 , L_21 ,
V_173 , V_85 [ 0 ] ) ;
return - V_174 ;
}
return 0 ;
}
static int F_127 ( struct V_1 * V_190 ,
struct V_371 * V_372 ,
T_1 * V_85 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_373 = V_372 -> V_373 ;
int V_358 ;
int V_86 = 0 ;
if ( ! V_372 -> V_374 )
return - V_174 ;
memset ( V_85 , 0 , V_372 -> V_374 ) ;
while ( V_86 < V_372 -> V_374 ) {
V_358 = F_126 ( V_8 , V_373 , V_372 -> V_374 - V_86 ,
V_85 + V_86 ) ;
if ( ! V_358 )
return 0 ;
if ( V_358 < 0 ) {
F_57 ( V_6 -> V_190 , L_22 ,
V_173 , V_358 ) ;
return 0 ;
}
V_86 += V_358 ;
V_373 += V_358 ;
}
return 0 ;
}
static int F_128 ( struct V_1 * V_190 , bool V_375 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
bool V_376 ;
T_1 V_377 ;
int V_72 = 0 ;
bool V_378 ;
V_377 = V_375 ?
V_379 :
V_380 ;
V_376 = V_377 != V_6 -> V_113 . V_377 ;
if ( V_377 == V_379 &&
! F_59 ( V_8 , V_381 ) )
return - V_84 ;
if ( ! V_376 )
return 0 ;
V_378 = F_27 ( V_111 , & V_6 -> V_112 ) ;
if ( V_378 )
F_50 ( V_190 ) ;
F_129 ( & V_6 -> V_113 , V_377 ) ;
if ( V_378 )
V_72 = F_51 ( V_190 ) ;
return V_72 ;
}
static int F_130 ( struct V_1 * V_190 ,
bool V_375 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! F_59 ( V_8 , V_382 ) )
return - V_84 ;
if ( V_375 && V_6 -> V_309 . V_383 . V_384 != V_320 ) {
F_57 ( V_190 , L_23 ) ;
return - V_174 ;
}
F_131 ( V_6 , V_375 ) ;
V_6 -> V_113 . V_385 = V_375 ;
F_132 ( V_6 , V_6 -> V_113 . V_145 ) ;
return 0 ;
}
static int F_133 ( struct V_1 * V_190 ,
T_2 V_386 ,
enum V_387 V_388 ,
T_8 V_389 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
bool V_375 = ! ! ( V_386 & V_388 ) ;
T_2 V_390 = V_386 ^ V_6 -> V_113 . V_391 ;
int V_72 ;
if ( ! ( V_390 & V_388 ) )
return 0 ;
V_72 = V_389 ( V_190 , V_375 ) ;
if ( V_72 ) {
F_57 ( V_190 , L_24 ,
V_375 ? L_25 : L_26 , V_388 , V_72 ) ;
return V_72 ;
}
F_134 ( V_6 , V_388 , V_375 ) ;
return 0 ;
}
static int F_135 ( struct V_1 * V_190 , T_2 V_391 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
int V_72 ;
F_30 ( & V_6 -> V_126 ) ;
V_72 = F_133 ( V_190 , V_391 ,
V_392 ,
F_128 ) ;
if ( V_72 )
goto V_189;
V_72 = F_133 ( V_190 , V_391 ,
V_393 ,
F_130 ) ;
V_189:
F_32 ( & V_6 -> V_126 ) ;
return V_72 ;
}
static T_2 F_136 ( struct V_1 * V_190 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
return V_6 -> V_113 . V_391 ;
}
static int F_137 ( struct V_1 * V_2 , struct V_285 * V_288 )
{
int V_72 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_288 -> V_288 ) {
case V_394 :
V_72 = F_138 ( V_6 , & V_288 -> V_292 ) ;
break;
case V_395 :
V_72 = F_139 ( V_6 , V_288 -> V_292 . V_296 ) ;
break;
default:
V_72 = - V_84 ;
break;
}
return V_72 ;
}
