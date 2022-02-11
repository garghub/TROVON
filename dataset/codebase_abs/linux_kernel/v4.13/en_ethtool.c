void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_2 ( V_4 -> V_7 , V_8 , sizeof( V_4 -> V_7 ) ) ;
F_2 ( V_4 -> V_9 , V_10 ,
sizeof( V_4 -> V_9 ) ) ;
snprintf ( V_4 -> V_11 , sizeof( V_4 -> V_11 ) ,
L_1 ,
F_3 ( V_6 ) , F_4 ( V_6 ) , F_5 ( V_6 ) ,
V_6 -> V_12 ) ;
F_2 ( V_4 -> V_13 , F_6 ( V_6 -> V_14 ) ,
sizeof( V_4 -> V_13 ) ) ;
}
static void F_7 ( struct V_15 * V_16 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_1 ( V_2 , V_4 ) ;
}
void F_9 ( void )
{
F_10 ( V_17 , V_18 ,
V_19 ) ;
F_10 ( V_20 , V_18 ,
V_19 ) ;
F_10 ( V_21 , V_22 ,
V_23 ) ;
F_10 ( V_24 , V_22 ,
V_23 ) ;
F_10 ( V_25 , V_22 ,
V_26 ) ;
F_10 ( V_27 , V_28 ,
V_29 ) ;
F_10 ( V_30 , V_31 ,
V_32 ) ;
F_10 ( V_33 , V_31 ,
V_34 ) ;
F_10 ( V_35 , V_36 ,
V_37 ) ;
F_10 ( V_38 , V_22 ,
V_26 ) ;
F_10 ( V_39 , V_22 ,
V_26 ) ;
F_10 ( V_40 , V_22 ,
V_26 ) ;
F_10 ( V_41 , V_31 ,
V_42 ) ;
F_10 ( V_43 , V_31 ,
V_44 ) ;
F_10 ( V_45 , V_46 ,
V_47 ) ;
F_10 ( V_48 , V_49 ,
V_50 ) ;
F_10 ( V_51 , V_49 ,
V_52 ) ;
F_10 ( V_53 , V_49 ,
V_54 ) ;
F_10 ( V_55 , V_49 ,
V_56 ) ;
F_10 ( V_57 , V_22 ,
V_58 ) ;
F_10 ( V_59 , V_60 ,
V_61 ) ;
F_10 ( V_62 , V_60 ,
V_63 ) ;
F_10 ( V_64 , V_60 ,
V_65 ) ;
F_10 ( V_66 , V_46 ,
V_67 ) ;
F_10 ( V_68 , V_46 ,
V_69 ) ;
}
static unsigned long F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_70 ;
T_1 V_71 ;
int V_72 ;
if ( F_12 ( V_6 , V_73 ) != V_74 )
return 0 ;
V_72 = F_13 ( V_6 , & V_70 , & V_71 ) ;
return V_72 ? 0 : V_70 | V_71 ;
}
static bool F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_75 ;
T_2 V_76 ;
int V_72 ;
if ( F_12 ( V_6 , V_73 ) != V_74 )
return false ;
V_72 = F_15 ( V_6 , & V_75 , & V_76 ) ;
return V_72 ? false : V_75 | V_76 ;
}
int F_16 ( struct V_1 * V_2 , int V_77 )
{
switch ( V_77 ) {
case V_78 :
return V_79 +
F_17 ( V_2 ) +
V_80 + F_18 ( V_2 ) +
F_19 ( V_2 ) +
F_20 ( V_2 ) +
F_21 ( V_2 ) +
F_22 ( V_2 ) +
F_23 ( V_81 ) +
F_23 ( V_82 ) +
F_24 ( V_2 ) ;
case V_83 :
return F_23 ( V_84 ) ;
case V_85 :
return F_25 ( V_2 ) ;
default:
return - V_86 ;
}
}
static int F_26 ( struct V_15 * V_16 , int V_77 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
return F_16 ( V_2 , V_77 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_3 * V_87 )
{
int V_88 , V_89 , V_90 , V_91 , V_92 = 0 ;
unsigned long V_93 ;
for ( V_88 = 0 ; V_88 < V_79 ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 , V_95 [ V_88 ] . V_96 ) ;
for ( V_88 = 0 ; V_88 < F_17 ( V_2 ) ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 , V_97 [ V_88 ] . V_96 ) ;
for ( V_88 = 0 ; V_88 < V_80 ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 ,
V_98 [ V_88 ] . V_96 ) ;
for ( V_88 = 0 ; V_88 < V_99 ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 ,
V_100 [ V_88 ] . V_96 ) ;
for ( V_88 = 0 ; V_88 < V_101 ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 ,
V_102 [ V_88 ] . V_96 ) ;
for ( V_88 = 0 ; V_88 < V_103 ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 ,
V_104 [ V_88 ] . V_96 ) ;
for ( V_88 = 0 ; V_88 < F_28 ( V_2 ) ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 ,
V_105 [ V_88 ] . V_96 ) ;
for ( V_88 = 0 ; V_88 < F_29 ( V_2 ) ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 ,
V_106 [ V_88 ] . V_96 ) ;
for ( V_91 = 0 ; V_91 < V_107 ; V_91 ++ ) {
for ( V_88 = 0 ; V_88 < V_108 ; V_88 ++ )
sprintf ( V_87 + ( V_92 ++ ) * V_94 ,
V_109 [ V_88 ] . V_96 , V_91 ) ;
}
V_93 = F_11 ( V_2 ) ;
F_30 (prio, &pfc_combined, NUM_PPORT_PRIO) {
for ( V_88 = 0 ; V_88 < V_110 ; V_88 ++ ) {
char V_111 [ V_94 ] ;
snprintf ( V_111 , sizeof( V_111 ) , L_2 , V_91 ) ;
sprintf ( V_87 + ( V_92 ++ ) * V_94 ,
V_112 [ V_88 ] . V_96 , V_111 ) ;
}
}
if ( F_14 ( V_2 ) ) {
for ( V_88 = 0 ; V_88 < V_110 ; V_88 ++ ) {
sprintf ( V_87 + ( V_92 ++ ) * V_94 ,
V_112 [ V_88 ] . V_96 , L_3 ) ;
}
}
for ( V_88 = 0 ; V_88 < F_23 ( V_81 ) ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 , V_81 [ V_88 ] . V_96 ) ;
for ( V_88 = 0 ; V_88 < F_23 ( V_82 ) ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 , V_82 [ V_88 ] . V_96 ) ;
V_92 += F_31 ( V_2 , V_87 + V_92 * V_94 ) ;
if ( ! F_32 ( V_113 , & V_2 -> V_114 ) )
return;
for ( V_88 = 0 ; V_88 < V_2 -> V_115 . V_116 ; V_88 ++ )
for ( V_89 = 0 ; V_89 < V_117 ; V_89 ++ )
sprintf ( V_87 + ( V_92 ++ ) * V_94 ,
V_118 [ V_89 ] . V_96 , V_88 ) ;
for ( V_90 = 0 ; V_90 < V_2 -> V_115 . V_119 . V_120 ; V_90 ++ )
for ( V_88 = 0 ; V_88 < V_2 -> V_115 . V_116 ; V_88 ++ )
for ( V_89 = 0 ; V_89 < V_121 ; V_89 ++ )
sprintf ( V_87 + ( V_92 ++ ) * V_94 ,
V_122 [ V_89 ] . V_96 ,
V_2 -> V_123 [ V_88 ] [ V_90 ] ) ;
}
void F_33 ( struct V_1 * V_2 ,
T_4 V_124 , T_3 * V_87 )
{
int V_88 ;
switch ( V_124 ) {
case V_83 :
for ( V_88 = 0 ; V_88 < F_23 ( V_84 ) ; V_88 ++ )
strcpy ( V_87 + V_88 * V_94 , V_84 [ V_88 ] ) ;
break;
case V_85 :
for ( V_88 = 0 ; V_88 < F_25 ( V_2 ) ; V_88 ++ )
strcpy ( V_87 + V_88 * V_94 ,
V_125 [ V_88 ] ) ;
break;
case V_78 :
F_27 ( V_2 , V_87 ) ;
break;
}
}
static void F_34 ( struct V_15 * V_16 ,
T_4 V_124 , T_3 * V_87 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_33 ( V_2 , V_124 , V_87 ) ;
}
void F_35 ( struct V_1 * V_2 ,
struct V_126 * V_127 , T_5 * V_87 )
{
struct V_128 * V_115 ;
struct V_129 * V_129 ;
int V_88 , V_89 , V_90 , V_91 , V_92 = 0 ;
unsigned long V_93 ;
if ( ! V_87 )
return;
F_36 ( & V_2 -> V_130 ) ;
if ( F_32 ( V_113 , & V_2 -> V_114 ) )
F_37 ( V_2 , true ) ;
V_115 = & V_2 -> V_115 ;
F_38 ( & V_2 -> V_130 ) ;
for ( V_88 = 0 ; V_88 < V_79 ; V_88 ++ )
V_87 [ V_92 ++ ] = F_39 ( & V_2 -> V_127 . V_131 ,
V_95 , V_88 ) ;
for ( V_88 = 0 ; V_88 < F_17 ( V_2 ) ; V_88 ++ )
V_87 [ V_92 ++ ] = F_40 ( & V_2 -> V_127 . V_132 ,
V_97 , V_88 ) ;
for ( V_88 = 0 ; V_88 < V_80 ; V_88 ++ )
V_87 [ V_92 ++ ] = F_41 ( V_2 -> V_127 . V_133 . V_134 ,
V_98 , V_88 ) ;
for ( V_88 = 0 ; V_88 < V_99 ; V_88 ++ )
V_87 [ V_92 ++ ] = F_41 ( & V_2 -> V_127 . V_135 . V_136 ,
V_100 , V_88 ) ;
for ( V_88 = 0 ; V_88 < V_101 ; V_88 ++ )
V_87 [ V_92 ++ ] = F_41 ( & V_2 -> V_127 . V_135 . V_137 ,
V_102 , V_88 ) ;
for ( V_88 = 0 ; V_88 < V_103 ; V_88 ++ )
V_87 [ V_92 ++ ] = F_41 ( & V_2 -> V_127 . V_135 . V_138 ,
V_104 , V_88 ) ;
for ( V_88 = 0 ; V_88 < F_28 ( V_2 ) ; V_88 ++ )
V_87 [ V_92 ++ ] = F_41 ( & V_2 -> V_127 . V_135 . V_139 ,
V_105 , V_88 ) ;
for ( V_88 = 0 ; V_88 < F_29 ( V_2 ) ; V_88 ++ )
V_87 [ V_92 ++ ] = F_42 ( & V_2 -> V_127 . V_140 . V_141 ,
V_106 , V_88 ) ;
for ( V_91 = 0 ; V_91 < V_107 ; V_91 ++ ) {
for ( V_88 = 0 ; V_88 < V_108 ; V_88 ++ )
V_87 [ V_92 ++ ] = F_41 ( & V_2 -> V_127 . V_135 . V_142 [ V_91 ] ,
V_109 , V_88 ) ;
}
V_93 = F_11 ( V_2 ) ;
F_30 (prio, &pfc_combined, NUM_PPORT_PRIO) {
for ( V_88 = 0 ; V_88 < V_110 ; V_88 ++ ) {
V_87 [ V_92 ++ ] = F_41 ( & V_2 -> V_127 . V_135 . V_142 [ V_91 ] ,
V_112 , V_88 ) ;
}
}
if ( F_14 ( V_2 ) ) {
for ( V_88 = 0 ; V_88 < V_110 ; V_88 ++ ) {
V_87 [ V_92 ++ ] = F_41 ( & V_2 -> V_127 . V_135 . V_142 [ 0 ] ,
V_112 , V_88 ) ;
}
}
V_129 = & V_2 -> V_6 -> V_2 ;
for ( V_88 = 0 ; V_88 < F_23 ( V_81 ) ; V_88 ++ )
V_87 [ V_92 ++ ] = F_39 ( V_129 -> V_143 . V_144 ,
V_81 , V_88 ) ;
for ( V_88 = 0 ; V_88 < F_23 ( V_82 ) ; V_88 ++ )
V_87 [ V_92 ++ ] = F_39 ( V_129 -> V_143 . V_145 ,
V_82 , V_88 ) ;
V_92 += F_43 ( V_2 , V_87 + V_92 ) ;
if ( ! F_32 ( V_113 , & V_2 -> V_114 ) )
return;
for ( V_88 = 0 ; V_88 < V_115 -> V_116 ; V_88 ++ )
for ( V_89 = 0 ; V_89 < V_117 ; V_89 ++ )
V_87 [ V_92 ++ ] =
F_39 ( & V_115 -> V_146 [ V_88 ] -> V_147 . V_127 ,
V_118 , V_89 ) ;
for ( V_90 = 0 ; V_90 < V_2 -> V_115 . V_119 . V_120 ; V_90 ++ )
for ( V_88 = 0 ; V_88 < V_115 -> V_116 ; V_88 ++ )
for ( V_89 = 0 ; V_89 < V_121 ; V_89 ++ )
V_87 [ V_92 ++ ] = F_39 ( & V_115 -> V_146 [ V_88 ] -> V_148 [ V_90 ] . V_127 ,
V_122 , V_89 ) ;
}
static void F_44 ( struct V_15 * V_16 ,
struct V_126 * V_127 ,
T_5 * V_87 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_35 ( V_2 , V_127 , V_87 ) ;
}
static T_2 F_45 ( struct V_1 * V_2 , int V_149 ,
int V_150 )
{
int V_151 ;
int V_152 ;
int V_153 ;
int V_154 ;
if ( V_149 != V_155 )
return V_150 ;
V_152 = 1 << V_2 -> V_115 . V_119 . V_156 ;
V_153 = 1 << V_2 -> V_115 . V_119 . V_157 ;
V_154 = V_152 * V_153 ;
V_151 = V_154 /
F_46 ( V_158 , V_152 ) ;
return ( 1 << ( F_47 ( V_150 * V_151 ) - 1 ) ) ;
}
static T_2 F_48 ( struct V_1 * V_2 , int V_149 ,
int V_159 )
{
int V_151 ;
int V_152 ;
int V_153 ;
int V_154 ;
int V_160 ;
if ( V_149 != V_155 )
return V_159 ;
V_152 = 1 << V_2 -> V_115 . V_119 . V_156 ;
V_153 = 1 << V_2 -> V_115 . V_119 . V_157 ;
V_154 = V_152 * V_153 ;
V_159 = ( 1 << F_47 ( V_159 ) ) ;
V_151 = V_154 /
F_46 ( V_158 , V_152 ) ;
V_160 = F_49 ( V_159 , V_151 ) ;
return 1 << ( F_47 ( V_160 ) ) ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_161 * V_162 )
{
int V_149 = V_2 -> V_115 . V_119 . V_149 ;
V_162 -> V_163 = F_45 ( V_2 , V_149 ,
1 << F_51 ( V_149 ) ) ;
V_162 -> V_164 = 1 << V_165 ;
V_162 -> V_166 = F_45 ( V_2 , V_149 ,
1 << V_2 -> V_115 . V_119 . V_167 ) ;
V_162 -> V_168 = 1 << V_2 -> V_115 . V_119 . V_169 ;
}
static void F_52 ( struct V_15 * V_16 ,
struct V_161 * V_162 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_50 ( V_2 , V_162 ) ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_161 * V_162 )
{
int V_149 = V_2 -> V_115 . V_119 . V_149 ;
struct V_128 V_170 = {} ;
T_2 V_171 ;
T_2 V_172 ;
T_2 V_173 ;
T_1 V_167 ;
T_1 V_169 ;
T_2 V_174 ;
int V_72 = 0 ;
if ( V_162 -> V_175 ) {
F_54 ( V_2 -> V_176 , L_4 ,
V_177 ) ;
return - V_178 ;
}
if ( V_162 -> V_179 ) {
F_54 ( V_2 -> V_176 , L_5 ,
V_177 ) ;
return - V_178 ;
}
V_172 = F_45 ( V_2 , V_149 ,
1 << F_55 ( V_149 ) ) ;
V_173 = F_45 ( V_2 , V_149 ,
1 << F_51 ( V_149 ) ) ;
V_171 = F_48 ( V_2 , V_149 ,
V_162 -> V_166 ) ;
if ( V_162 -> V_166 < V_172 ) {
F_54 ( V_2 -> V_176 , L_6 ,
V_177 , V_162 -> V_166 ,
V_172 ) ;
return - V_178 ;
}
if ( V_162 -> V_166 > V_173 ) {
F_54 ( V_2 -> V_176 , L_7 ,
V_177 , V_162 -> V_166 ,
V_173 ) ;
return - V_178 ;
}
V_174 = F_56 ( V_171 ) ;
if ( V_2 -> V_115 . V_119 . V_149 == V_155 &&
! F_57 ( V_174 ) ) {
F_54 ( V_2 -> V_176 , L_8 ,
V_177 , V_162 -> V_166 ) ;
return - V_178 ;
}
if ( V_162 -> V_168 < ( 1 << V_180 ) ) {
F_54 ( V_2 -> V_176 , L_9 ,
V_177 , V_162 -> V_168 ,
1 << V_180 ) ;
return - V_178 ;
}
if ( V_162 -> V_168 > ( 1 << V_165 ) ) {
F_54 ( V_2 -> V_176 , L_10 ,
V_177 , V_162 -> V_168 ,
1 << V_165 ) ;
return - V_178 ;
}
V_167 = F_47 ( V_171 ) ;
V_169 = F_47 ( V_162 -> V_168 ) ;
if ( V_167 == V_2 -> V_115 . V_119 . V_167 &&
V_169 == V_2 -> V_115 . V_119 . V_169 )
return 0 ;
F_36 ( & V_2 -> V_130 ) ;
V_170 . V_119 = V_2 -> V_115 . V_119 ;
V_170 . V_119 . V_167 = V_167 ;
V_170 . V_119 . V_169 = V_169 ;
if ( ! F_32 ( V_113 , & V_2 -> V_114 ) ) {
V_2 -> V_115 . V_119 = V_170 . V_119 ;
goto V_181;
}
V_72 = F_58 ( V_2 , & V_170 ) ;
if ( V_72 )
goto V_181;
F_59 ( V_2 , & V_170 , NULL ) ;
V_181:
F_38 ( & V_2 -> V_130 ) ;
return V_72 ;
}
static int F_60 ( struct V_15 * V_16 ,
struct V_161 * V_162 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
return F_53 ( V_2 , V_162 ) ;
}
void F_61 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
V_183 -> V_184 = V_2 -> V_185 -> V_186 ( V_2 -> V_6 ) ;
V_183 -> V_187 = V_2 -> V_115 . V_119 . V_188 ;
}
static void F_62 ( struct V_15 * V_16 ,
struct V_182 * V_183 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_61 ( V_2 , V_183 ) ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
unsigned int V_189 = V_183 -> V_187 ;
struct V_128 V_170 = {} ;
bool V_190 ;
int V_72 = 0 ;
if ( ! V_189 ) {
F_54 ( V_2 -> V_176 , L_11 ,
V_177 ) ;
return - V_178 ;
}
if ( V_2 -> V_115 . V_119 . V_188 == V_189 )
return 0 ;
F_36 ( & V_2 -> V_130 ) ;
V_170 . V_119 = V_2 -> V_115 . V_119 ;
V_170 . V_119 . V_188 = V_189 ;
if ( ! F_64 ( V_2 -> V_176 ) )
F_65 ( V_2 -> V_6 ,
V_170 . V_119 . V_191 ,
V_192 , V_189 ) ;
if ( ! F_32 ( V_113 , & V_2 -> V_114 ) ) {
V_2 -> V_115 . V_119 = V_170 . V_119 ;
goto V_193;
}
V_72 = F_58 ( V_2 , & V_170 ) ;
if ( V_72 )
goto V_193;
V_190 = V_2 -> V_176 -> V_194 & V_195 ;
if ( V_190 )
F_66 ( V_2 ) ;
F_59 ( V_2 , & V_170 , NULL ) ;
if ( V_190 ) {
V_72 = F_67 ( V_2 ) ;
if ( V_72 )
F_68 ( V_2 -> V_176 , L_12 ,
V_177 , V_72 ) ;
}
V_193:
F_38 ( & V_2 -> V_130 ) ;
return V_72 ;
}
static int F_69 ( struct V_15 * V_16 ,
struct V_182 * V_183 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
return F_63 ( V_2 , V_183 ) ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_196 * V_197 )
{
if ( ! F_12 ( V_2 -> V_6 , V_198 ) )
return - V_86 ;
V_197 -> V_199 = V_2 -> V_115 . V_119 . V_200 . V_201 ;
V_197 -> V_202 = V_2 -> V_115 . V_119 . V_200 . V_203 ;
V_197 -> V_204 = V_2 -> V_115 . V_119 . V_205 . V_201 ;
V_197 -> V_206 = V_2 -> V_115 . V_119 . V_205 . V_203 ;
V_197 -> V_207 = V_2 -> V_115 . V_119 . V_208 ;
return 0 ;
}
static int F_71 ( struct V_15 * V_176 ,
struct V_196 * V_197 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
return F_70 ( V_2 , V_197 ) ;
}
static void
F_72 ( struct V_1 * V_2 , struct V_196 * V_197 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_90 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_115 . V_116 ; ++ V_88 ) {
struct V_209 * V_146 = V_2 -> V_115 . V_146 [ V_88 ] ;
for ( V_90 = 0 ; V_90 < V_146 -> V_120 ; V_90 ++ ) {
F_73 ( V_6 ,
& V_146 -> V_148 [ V_90 ] . V_210 . V_211 ,
V_197 -> V_204 ,
V_197 -> V_206 ) ;
}
F_73 ( V_6 , & V_146 -> V_147 . V_210 . V_211 ,
V_197 -> V_199 ,
V_197 -> V_202 ) ;
}
}
int F_74 ( struct V_1 * V_2 ,
struct V_196 * V_197 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_128 V_170 = {} ;
int V_72 = 0 ;
bool V_212 ;
if ( ! F_12 ( V_6 , V_198 ) )
return - V_86 ;
F_36 ( & V_2 -> V_130 ) ;
V_170 . V_119 = V_2 -> V_115 . V_119 ;
V_170 . V_119 . V_205 . V_201 = V_197 -> V_204 ;
V_170 . V_119 . V_205 . V_203 = V_197 -> V_206 ;
V_170 . V_119 . V_200 . V_201 = V_197 -> V_199 ;
V_170 . V_119 . V_200 . V_203 = V_197 -> V_202 ;
V_170 . V_119 . V_208 = ! ! V_197 -> V_207 ;
if ( ! F_32 ( V_113 , & V_2 -> V_114 ) ) {
V_2 -> V_115 . V_119 = V_170 . V_119 ;
goto V_193;
}
V_212 = ! ! V_197 -> V_207 != V_2 -> V_115 . V_119 . V_208 ;
if ( ! V_212 ) {
F_72 ( V_2 , V_197 ) ;
V_2 -> V_115 . V_119 = V_170 . V_119 ;
goto V_193;
}
V_72 = F_58 ( V_2 , & V_170 ) ;
if ( V_72 )
goto V_193;
F_59 ( V_2 , & V_170 , NULL ) ;
V_193:
F_38 ( & V_2 -> V_130 ) ;
return V_72 ;
}
static int F_75 ( struct V_15 * V_176 ,
struct V_196 * V_197 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
return F_74 ( V_2 , V_197 ) ;
}
static void F_76 ( unsigned long * V_213 ,
T_2 V_214 )
{
unsigned long V_215 = V_214 ;
int V_216 ;
F_30 (proto, &proto_cap, MLX5E_LINK_MODES_NUMBER)
F_77 ( V_213 , V_213 ,
V_217 [ V_216 ] . V_218 ,
V_219 ) ;
}
static void F_78 ( unsigned long * V_220 ,
T_2 V_214 )
{
unsigned long V_215 = V_214 ;
int V_216 ;
F_30 (proto, &proto_cap, MLX5E_LINK_MODES_NUMBER)
F_77 ( V_220 , V_220 ,
V_217 [ V_216 ] . V_221 ,
V_219 ) ;
}
static void F_79 ( struct V_222 * V_223 ,
T_2 V_214 ,
T_1 V_224 )
{
if ( ! V_224 || V_224 >= V_225 ) {
if ( V_214 & ( F_80 ( V_38 )
| F_80 ( V_39 )
| F_80 ( V_30 )
| F_80 ( V_41 )
| F_80 ( V_51 )
| F_80 ( V_17 ) ) ) {
F_81 ( V_223 ,
V_218 ,
V_226 ) ;
F_81 ( V_223 ,
V_227 ,
V_226 ) ;
}
if ( V_214 & ( F_80 ( V_53 )
| F_80 ( V_33 )
| F_80 ( V_25 )
| F_80 ( V_24 )
| F_80 ( V_20 ) ) ) {
F_81 ( V_223 ,
V_218 ,
V_228 ) ;
F_81 ( V_223 ,
V_227 ,
V_228 ) ;
}
return;
}
switch ( V_224 ) {
case V_229 :
F_81 ( V_223 ,
V_218 , V_230 ) ;
F_81 ( V_223 ,
V_227 , V_230 ) ;
break;
case V_231 :
F_81 ( V_223 ,
V_218 , V_232 ) ;
F_81 ( V_223 ,
V_227 , V_232 ) ;
break;
case V_233 :
F_81 ( V_223 ,
V_218 , V_234 ) ;
F_81 ( V_223 ,
V_227 , V_234 ) ;
break;
case V_235 :
F_81 ( V_223 ,
V_218 , V_236 ) ;
F_81 ( V_223 ,
V_227 , V_236 ) ;
break;
case V_237 :
F_81 ( V_223 ,
V_218 , V_226 ) ;
F_81 ( V_223 ,
V_227 , V_226 ) ;
break;
case V_238 :
F_81 ( V_223 ,
V_218 , V_228 ) ;
F_81 ( V_223 ,
V_227 , V_228 ) ;
break;
case V_239 :
case V_240 :
default:
break;
}
}
int F_82 ( struct V_5 * V_6 , T_2 * V_241 )
{
T_2 V_242 = 0 ;
T_2 V_215 ;
int V_72 ;
int V_88 ;
V_72 = F_83 ( V_6 , & V_215 , V_243 ) ;
if ( V_72 )
return V_72 ;
for ( V_88 = 0 ; V_88 < V_244 ; ++ V_88 )
if ( V_215 & F_80 ( V_88 ) )
V_242 = F_84 ( V_242 , V_217 [ V_88 ] . V_241 ) ;
* V_241 = V_242 ;
return 0 ;
}
static void F_85 ( struct V_15 * V_176 ,
T_2 V_245 ,
struct V_222 * V_223 )
{
int V_88 ;
T_2 V_241 = V_246 ;
T_1 V_247 = V_248 ;
if ( ! F_86 ( V_176 ) )
goto V_193;
for ( V_88 = 0 ; V_88 < V_244 ; ++ V_88 ) {
if ( V_245 & F_80 ( V_88 ) ) {
V_241 = V_217 [ V_88 ] . V_241 ;
V_247 = V_249 ;
break;
}
}
V_193:
V_223 -> V_250 . V_241 = V_241 ;
V_223 -> V_250 . V_247 = V_247 ;
}
static void F_87 ( T_2 V_214 ,
struct V_222 * V_223 )
{
unsigned long * V_218 = V_223 -> V_251 . V_218 ;
F_76 ( V_218 , V_214 ) ;
F_81 ( V_223 , V_218 , V_252 ) ;
}
static void F_88 ( T_2 V_214 , T_1 V_76 ,
T_1 V_75 ,
struct V_222 * V_223 )
{
unsigned long * V_227 = V_223 -> V_251 . V_227 ;
F_78 ( V_227 , V_214 ) ;
if ( V_75 )
F_81 ( V_223 , V_227 , V_252 ) ;
if ( V_76 ^ V_75 )
F_81 ( V_223 , V_227 , V_253 ) ;
}
static T_1 F_89 ( T_2 V_254 , T_1 V_224 )
{
if ( V_224 && V_224 < V_225 )
return V_255 [ V_224 ] ;
if ( V_254 & ( F_80 ( V_39 )
| F_80 ( V_41 )
| F_80 ( V_51 )
| F_80 ( V_17 ) ) ) {
return V_256 ;
}
if ( V_254 & ( F_80 ( V_30 )
| F_80 ( V_38 )
| F_80 ( V_48 ) ) ) {
return V_257 ;
}
if ( V_254 & ( F_80 ( V_24 )
| F_80 ( V_25 )
| F_80 ( V_33 )
| F_80 ( V_53 ) ) ) {
return V_258 ;
}
return V_259 ;
}
static void F_90 ( T_2 V_260 ,
struct V_222 * V_223 )
{
unsigned long * V_261 = V_223 -> V_251 . V_261 ;
F_78 ( V_261 , V_260 ) ;
}
static int F_91 ( struct V_15 * V_176 ,
struct V_222 * V_223 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_193 [ F_92 ( V_262 ) ] = { 0 } ;
T_2 V_75 = 0 ;
T_2 V_76 = 0 ;
T_2 V_214 ;
T_2 V_263 ;
T_2 V_260 ;
T_2 V_245 ;
T_1 V_264 ;
T_1 V_265 ;
T_1 V_224 ;
int V_72 ;
V_72 = F_93 ( V_6 , V_193 , sizeof( V_193 ) , V_243 , 1 ) ;
if ( V_72 ) {
F_68 ( V_176 , L_13 ,
V_177 , V_72 ) ;
goto V_266;
}
V_214 = F_94 ( V_262 , V_193 , V_267 ) ;
V_263 = F_94 ( V_262 , V_193 , V_263 ) ;
V_245 = F_94 ( V_262 , V_193 , V_245 ) ;
V_260 = F_94 ( V_262 , V_193 , V_268 ) ;
V_264 = F_94 ( V_262 , V_193 , V_264 ) ;
V_265 = F_94 ( V_262 , V_193 , V_265 ) ;
V_224 = F_94 ( V_262 , V_193 , V_224 ) ;
F_15 ( V_6 , & V_75 , & V_76 ) ;
F_95 ( V_223 , V_218 ) ;
F_95 ( V_223 , V_227 ) ;
F_87 ( V_214 , V_223 ) ;
F_88 ( V_263 , V_76 , V_75 , V_223 ) ;
F_85 ( V_176 , V_245 , V_223 ) ;
V_245 = V_245 ? V_245 : V_214 ;
V_223 -> V_250 . V_269 = F_89 ( V_245 ,
V_224 ) ;
F_79 ( V_223 , V_263 ,
V_224 ) ;
F_90 ( V_260 , V_223 ) ;
if ( V_265 == V_270 )
F_81 ( V_223 ,
V_261 , V_271 ) ;
V_223 -> V_250 . V_272 = V_264 ? V_273 :
V_274 ;
F_81 ( V_223 , V_218 ,
V_271 ) ;
if ( ! V_264 )
F_81 ( V_223 ,
V_227 , V_271 ) ;
V_266:
return V_72 ;
}
static T_2 F_96 ( const unsigned long * V_251 )
{
T_2 V_88 , V_275 = 0 ;
for ( V_88 = 0 ; V_88 < V_244 ; ++ V_88 ) {
if ( F_97 ( V_217 [ V_88 ] . V_221 ,
V_251 ,
V_219 ) )
V_275 |= F_80 ( V_88 ) ;
}
return V_275 ;
}
static T_2 F_98 ( T_2 V_241 )
{
T_2 V_88 , V_276 = 0 ;
for ( V_88 = 0 ; V_88 < V_244 ; ++ V_88 ) {
if ( V_217 [ V_88 ] . V_241 == V_241 )
V_276 |= F_80 ( V_88 ) ;
}
return V_276 ;
}
static int F_99 ( struct V_15 * V_176 ,
const struct V_222 * V_223 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_214 , V_263 ;
bool V_277 = false ;
T_1 V_264 ;
T_1 V_278 ;
bool V_279 ;
T_2 V_251 ;
T_1 V_265 ;
T_2 V_241 ;
int V_72 ;
V_241 = V_223 -> V_250 . V_241 ;
V_251 = V_223 -> V_250 . V_272 == V_274 ?
F_96 ( V_223 -> V_251 . V_227 ) :
F_98 ( V_241 ) ;
V_72 = F_83 ( V_6 , & V_214 , V_243 ) ;
if ( V_72 ) {
F_68 ( V_176 , L_14 ,
V_177 , V_72 ) ;
goto V_193;
}
V_251 = V_251 & V_214 ;
if ( ! V_251 ) {
F_68 ( V_176 , L_15 ,
V_177 ) ;
V_72 = - V_178 ;
goto V_193;
}
V_72 = F_100 ( V_6 , & V_263 , V_243 ) ;
if ( V_72 ) {
F_68 ( V_176 , L_16 ,
V_177 , V_72 ) ;
goto V_193;
}
F_101 ( V_6 , V_243 , & V_265 ,
& V_278 , & V_264 ) ;
V_279 = V_223 -> V_250 . V_272 == V_273 ;
V_277 = ( ( ! V_279 && V_264 ) ||
( V_279 && ! V_264 ) ) ;
if ( ! V_277 && V_251 == V_263 )
goto V_193;
F_102 ( V_6 , V_279 , V_251 , V_243 ) ;
F_103 ( V_6 ) ;
V_193:
return V_72 ;
}
static T_2 F_104 ( struct V_15 * V_176 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
return sizeof( V_2 -> V_115 . V_119 . V_280 ) ;
}
static T_2 F_105 ( struct V_15 * V_176 )
{
return V_192 ;
}
static int F_106 ( struct V_15 * V_176 , T_2 * V_281 , T_1 * V_282 ,
T_1 * V_283 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
if ( V_281 )
memcpy ( V_281 , V_2 -> V_115 . V_119 . V_191 ,
sizeof( V_2 -> V_115 . V_119 . V_191 ) ) ;
if ( V_282 )
memcpy ( V_282 , V_2 -> V_115 . V_119 . V_280 ,
sizeof( V_2 -> V_115 . V_119 . V_280 ) ) ;
if ( V_283 )
* V_283 = V_2 -> V_115 . V_119 . V_284 ;
return 0 ;
}
static void F_107 ( struct V_1 * V_2 , void * V_285 , int V_286 )
{
void * V_287 = F_108 ( V_288 , V_285 , V_289 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_290 = F_109 ( V_287 ) ;
int V_291 ;
F_110 ( V_288 , V_285 , V_292 . V_293 , 1 ) ;
for ( V_291 = 0 ; V_291 < V_294 ; V_291 ++ ) {
memset ( V_287 , 0 , V_290 ) ;
F_111 ( & V_2 -> V_115 . V_119 , V_291 , V_287 ) ;
F_112 ( V_6 , V_2 -> V_295 [ V_291 ] . V_296 , V_285 , V_286 ) ;
}
}
static int F_113 ( struct V_15 * V_16 , const T_2 * V_281 ,
const T_1 * V_282 , const T_1 V_283 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
int V_286 = F_109 ( V_288 ) ;
bool V_297 = false ;
void * V_285 ;
if ( ( V_283 != V_298 ) &&
( V_283 != V_299 ) &&
( V_283 != V_300 ) )
return - V_178 ;
V_285 = F_114 ( V_286 , V_301 ) ;
if ( ! V_285 )
return - V_302 ;
F_36 ( & V_2 -> V_130 ) ;
if ( V_283 != V_298 &&
V_283 != V_2 -> V_115 . V_119 . V_284 ) {
V_2 -> V_115 . V_119 . V_284 = V_283 ;
V_297 = true ;
}
if ( V_281 ) {
memcpy ( V_2 -> V_115 . V_119 . V_191 , V_281 ,
sizeof( V_2 -> V_115 . V_119 . V_191 ) ) ;
if ( F_32 ( V_113 , & V_2 -> V_114 ) ) {
T_2 V_303 = V_2 -> V_304 . V_303 ;
struct V_305 V_306 = {
. V_307 = true ,
{
. V_308 = {
. V_283 = V_2 -> V_115 . V_119 . V_284 ,
. V_115 = & V_2 -> V_115 ,
} ,
} ,
} ;
F_115 ( V_2 , V_303 , V_192 , V_306 ) ;
}
}
if ( V_282 ) {
memcpy ( V_2 -> V_115 . V_119 . V_280 , V_282 ,
sizeof( V_2 -> V_115 . V_119 . V_280 ) ) ;
V_297 = V_297 ||
V_2 -> V_115 . V_119 . V_284 == V_300 ;
}
if ( V_297 )
F_107 ( V_2 , V_285 , V_286 ) ;
F_38 ( & V_2 -> V_130 ) ;
F_116 ( V_285 ) ;
return 0 ;
}
static int F_117 ( struct V_15 * V_176 ,
struct V_309 * V_310 , T_2 * V_311 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
int V_72 = 0 ;
switch ( V_310 -> V_312 ) {
case V_313 :
V_310 -> V_87 = V_2 -> V_115 . V_119 . V_188 ;
break;
case V_314 :
V_310 -> V_315 = V_2 -> V_316 . V_317 . V_318 ;
break;
case V_319 :
V_72 = F_118 ( V_2 , V_310 , V_310 -> V_316 . V_320 ) ;
break;
case V_321 :
V_72 = F_119 ( V_2 , V_310 , V_311 ) ;
break;
default:
V_72 = - V_86 ;
break;
}
return V_72 ;
}
static int F_120 ( struct V_15 * V_16 ,
const struct V_322 * V_323 ,
void * V_87 )
{
const struct V_1 * V_2 = F_8 ( V_16 ) ;
int V_72 = 0 ;
switch ( V_323 -> V_324 ) {
case V_325 :
* ( T_2 * ) V_87 = V_2 -> V_115 . V_119 . V_326 ;
break;
default:
V_72 = - V_178 ;
break;
}
return V_72 ;
}
static int F_121 ( struct V_15 * V_16 ,
const struct V_322 * V_323 ,
const void * V_87 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_128 V_170 = {} ;
int V_72 = 0 ;
T_2 V_327 ;
F_36 ( & V_2 -> V_130 ) ;
switch ( V_323 -> V_324 ) {
case V_325 :
V_327 = * ( T_2 * ) V_87 ;
if ( V_327 > F_122 ( V_6 ) ) {
V_72 = - V_178 ;
break;
}
V_170 . V_119 = V_2 -> V_115 . V_119 ;
V_170 . V_119 . V_326 = V_327 ;
if ( ! F_32 ( V_113 , & V_2 -> V_114 ) ) {
V_2 -> V_115 . V_119 = V_170 . V_119 ;
break;
}
V_72 = F_58 ( V_2 , & V_170 ) ;
if ( V_72 )
break;
F_59 ( V_2 , & V_170 , NULL ) ;
break;
default:
V_72 = - V_178 ;
break;
}
F_38 ( & V_2 -> V_130 ) ;
return V_72 ;
}
static void F_123 ( struct V_15 * V_176 ,
struct V_328 * V_329 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_72 ;
V_72 = F_15 ( V_6 , & V_329 -> V_75 ,
& V_329 -> V_76 ) ;
if ( V_72 ) {
F_68 ( V_176 , L_17 ,
V_177 , V_72 ) ;
}
}
static int F_124 ( struct V_15 * V_176 ,
struct V_328 * V_329 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_72 ;
if ( V_329 -> V_272 )
return - V_178 ;
V_72 = F_125 ( V_6 ,
V_329 -> V_75 ? 1 : 0 ,
V_329 -> V_76 ? 1 : 0 ) ;
if ( V_72 ) {
F_68 ( V_176 , L_18 ,
V_177 , V_72 ) ;
}
return V_72 ;
}
int F_126 ( struct V_1 * V_2 ,
struct V_330 * V_310 )
{
int V_331 ;
V_331 = F_127 ( V_2 -> V_176 , V_310 ) ;
if ( V_331 )
return V_331 ;
V_310 -> V_332 = V_2 -> V_333 . V_334 ?
F_128 ( V_2 -> V_333 . V_334 ) : - 1 ;
if ( ! F_12 ( V_2 -> V_6 , V_335 ) )
return 0 ;
V_310 -> V_336 |= V_337 |
V_338 |
V_339 ;
V_310 -> V_340 = F_129 ( V_341 ) |
F_129 ( V_342 ) ;
V_310 -> V_343 = F_129 ( V_344 ) |
F_129 ( V_345 ) ;
return 0 ;
}
static int F_130 ( struct V_15 * V_16 ,
struct V_330 * V_310 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
return F_126 ( V_2 , V_310 ) ;
}
static T_6 F_131 ( struct V_5 * V_6 )
{
T_6 V_331 = 0 ;
if ( F_12 ( V_6 , V_346 ) )
V_331 |= V_347 ;
if ( F_12 ( V_6 , V_348 ) )
V_331 |= V_349 ;
if ( F_12 ( V_6 , V_350 ) )
V_331 |= V_351 ;
if ( F_12 ( V_6 , V_352 ) )
V_331 |= V_353 ;
if ( F_12 ( V_6 , V_354 ) )
V_331 |= V_355 ;
if ( F_12 ( V_6 , V_356 ) )
V_331 |= V_357 ;
if ( F_12 ( V_6 , V_358 ) )
V_331 |= V_359 ;
return V_331 ;
}
static T_6 F_132 ( T_1 V_360 )
{
T_6 V_331 = 0 ;
if ( V_360 & V_361 )
V_331 |= V_347 ;
if ( V_360 & V_362 )
V_331 |= V_349 ;
if ( V_360 & V_363 )
V_331 |= V_351 ;
if ( V_360 & V_364 )
V_331 |= V_353 ;
if ( V_360 & V_365 )
V_331 |= V_355 ;
if ( V_360 & V_366 )
V_331 |= V_357 ;
if ( V_360 & V_367 )
V_331 |= V_359 ;
return V_331 ;
}
static T_1 F_133 ( T_6 V_360 )
{
T_1 V_331 = 0 ;
if ( V_360 & V_347 )
V_331 |= V_361 ;
if ( V_360 & V_349 )
V_331 |= V_362 ;
if ( V_360 & V_351 )
V_331 |= V_363 ;
if ( V_360 & V_353 )
V_331 |= V_364 ;
if ( V_360 & V_355 )
V_331 |= V_365 ;
if ( V_360 & V_357 )
V_331 |= V_366 ;
if ( V_360 & V_359 )
V_331 |= V_367 ;
return V_331 ;
}
static void F_134 ( struct V_15 * V_176 ,
struct V_368 * V_369 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_370 ;
int V_72 ;
memset ( V_369 , 0 , sizeof( * V_369 ) ) ;
V_369 -> V_218 = F_131 ( V_6 ) ;
if ( ! V_369 -> V_218 )
return;
V_72 = F_135 ( V_6 , & V_370 ) ;
if ( V_72 )
return;
V_369 -> V_371 = F_132 ( V_370 ) ;
}
static int F_136 ( struct V_15 * V_176 , struct V_368 * V_369 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_6 V_372 = F_131 ( V_6 ) ;
T_2 V_370 ;
if ( ! V_372 )
return - V_86 ;
if ( V_369 -> V_371 & ~ V_372 )
return - V_178 ;
V_370 = F_133 ( V_369 -> V_371 ) ;
return F_137 ( V_6 , V_370 ) ;
}
static int F_138 ( struct V_15 * V_16 ,
enum V_373 V_114 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_7 V_374 ;
if ( ! F_12 ( V_6 , V_375 ) )
return - V_86 ;
switch ( V_114 ) {
case V_376 :
V_374 = V_377 ;
break;
case V_378 :
V_374 = V_379 ;
break;
default:
return - V_86 ;
}
return F_139 ( V_6 , V_374 ) ;
}
static int F_140 ( struct V_15 * V_176 ,
struct V_380 * V_381 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
struct V_5 * V_16 = V_2 -> V_6 ;
int V_382 = 0 ;
T_1 V_87 [ 4 ] ;
V_382 = F_141 ( V_16 , 0 , 2 , V_87 ) ;
if ( V_382 < 2 )
return - V_383 ;
switch ( V_87 [ 0 ] ) {
case V_384 :
V_381 -> type = V_385 ;
V_381 -> V_386 = V_387 ;
break;
case V_388 :
case V_389 :
if ( V_87 [ 0 ] == V_389 || V_87 [ 1 ] >= 0x3 ) {
V_381 -> type = V_390 ;
V_381 -> V_386 = V_391 ;
} else {
V_381 -> type = V_385 ;
V_381 -> V_386 = V_387 ;
}
break;
case V_392 :
V_381 -> type = V_393 ;
V_381 -> V_386 = V_394 ;
break;
default:
F_68 ( V_2 -> V_176 , L_19 ,
V_177 , V_87 [ 0 ] ) ;
return - V_178 ;
}
return 0 ;
}
static int F_142 ( struct V_15 * V_176 ,
struct V_395 * V_396 ,
T_1 * V_87 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_397 = V_396 -> V_397 ;
int V_382 ;
int V_88 = 0 ;
if ( ! V_396 -> V_398 )
return - V_178 ;
memset ( V_87 , 0 , V_396 -> V_398 ) ;
while ( V_88 < V_396 -> V_398 ) {
V_382 = F_141 ( V_6 , V_397 , V_396 -> V_398 - V_88 ,
V_87 + V_88 ) ;
if ( ! V_382 )
return 0 ;
if ( V_382 < 0 ) {
F_68 ( V_2 -> V_176 , L_20 ,
V_177 , V_382 ) ;
return 0 ;
}
V_88 += V_382 ;
V_397 += V_382 ;
}
return 0 ;
}
static int F_143 ( struct V_15 * V_176 , bool V_399 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_128 V_170 = {} ;
bool V_400 ;
T_1 V_401 ;
int V_72 = 0 ;
V_401 = V_399 ?
V_402 :
V_403 ;
V_400 = V_401 != V_2 -> V_115 . V_119 . V_401 ;
if ( V_401 == V_402 &&
! F_12 ( V_6 , V_404 ) )
return - V_86 ;
if ( ! V_400 )
return 0 ;
V_170 . V_119 = V_2 -> V_115 . V_119 ;
F_144 ( & V_170 . V_119 , V_401 ) ;
if ( ! F_32 ( V_113 , & V_2 -> V_114 ) ) {
V_2 -> V_115 . V_119 = V_170 . V_119 ;
return 0 ;
}
V_72 = F_58 ( V_2 , & V_170 ) ;
if ( V_72 )
return V_72 ;
F_59 ( V_2 , & V_170 , NULL ) ;
return 0 ;
}
int F_145 ( struct V_1 * V_2 , bool V_405 )
{
bool V_406 = F_146 ( & V_2 -> V_115 . V_119 , V_407 ) ;
struct V_128 V_170 = {} ;
int V_72 = 0 ;
if ( ! F_12 ( V_2 -> V_6 , V_408 ) )
return V_405 ? - V_86 : 0 ;
if ( V_406 == V_405 )
return 0 ;
V_170 . V_119 = V_2 -> V_115 . V_119 ;
F_147 ( & V_170 . V_119 , V_407 , V_405 ) ;
F_148 ( V_2 -> V_6 , & V_170 . V_119 ,
V_170 . V_119 . V_149 ) ;
if ( ! F_32 ( V_113 , & V_2 -> V_114 ) ) {
V_2 -> V_115 . V_119 = V_170 . V_119 ;
return 0 ;
}
V_72 = F_58 ( V_2 , & V_170 ) ;
if ( V_72 )
return V_72 ;
F_59 ( V_2 , & V_170 , NULL ) ;
return 0 ;
}
static int F_149 ( struct V_15 * V_176 ,
bool V_399 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( ! F_12 ( V_6 , V_408 ) )
return - V_86 ;
if ( V_399 && V_2 -> V_333 . V_409 . V_410 != V_344 ) {
F_68 ( V_176 , L_21 ) ;
return - V_178 ;
}
F_145 ( V_2 , V_399 ) ;
V_2 -> V_115 . V_119 . V_411 = V_399 ;
return 0 ;
}
static int F_150 ( struct V_15 * V_176 ,
T_2 V_412 ,
enum V_413 V_414 ,
T_8 V_415 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
bool V_399 = ! ! ( V_412 & V_414 ) ;
T_2 V_416 = V_412 ^ V_2 -> V_115 . V_119 . V_417 ;
int V_72 ;
if ( ! ( V_416 & V_414 ) )
return 0 ;
V_72 = V_415 ( V_176 , V_399 ) ;
if ( V_72 ) {
F_68 ( V_176 , L_22 ,
V_399 ? L_23 : L_24 , V_414 , V_72 ) ;
return V_72 ;
}
F_147 ( & V_2 -> V_115 . V_119 , V_414 , V_399 ) ;
return 0 ;
}
static int F_151 ( struct V_15 * V_176 , T_2 V_417 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
int V_72 ;
F_36 ( & V_2 -> V_130 ) ;
V_72 = F_150 ( V_176 , V_417 ,
V_418 ,
F_143 ) ;
if ( V_72 )
goto V_193;
V_72 = F_150 ( V_176 , V_417 ,
V_407 ,
F_149 ) ;
V_193:
F_38 ( & V_2 -> V_130 ) ;
return V_72 ;
}
static T_2 F_152 ( struct V_15 * V_176 )
{
struct V_1 * V_2 = F_8 ( V_176 ) ;
return V_2 -> V_115 . V_119 . V_417 ;
}
static int F_153 ( struct V_15 * V_16 , struct V_309 * V_312 )
{
int V_72 = 0 ;
struct V_1 * V_2 = F_8 ( V_16 ) ;
switch ( V_312 -> V_312 ) {
case V_419 :
V_72 = F_154 ( V_2 , & V_312 -> V_316 ) ;
break;
case V_420 :
V_72 = F_155 ( V_2 , V_312 -> V_316 . V_320 ) ;
break;
default:
V_72 = - V_86 ;
break;
}
return V_72 ;
}
int F_156 ( struct V_1 * V_2 ,
struct V_421 * V_422 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_15 * V_16 = V_2 -> V_176 ;
const struct V_423 * V_424 ;
int V_72 ;
if ( V_422 -> V_425 != V_426 )
return - V_86 ;
V_72 = F_157 ( & V_424 , V_422 -> V_87 , & V_16 -> V_16 ) ;
if ( V_72 )
return V_72 ;
F_158 ( V_16 ) ;
F_159 () ;
V_72 = F_160 ( V_6 , V_424 ) ;
F_161 ( V_424 ) ;
F_162 () ;
F_163 ( V_16 ) ;
return V_72 ;
}
static int F_164 ( struct V_15 * V_16 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
return F_156 ( V_2 , V_422 ) ;
}
