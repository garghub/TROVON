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
static void F_27 ( struct V_1 * V_2 , T_1 * V_87 )
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
for ( V_88 = 0 ; V_88 < F_30 ( V_2 ) ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 ,
V_107 [ V_88 ] . V_96 ) ;
for ( V_88 = 0 ; V_88 < F_31 ( V_2 ) ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 ,
V_108 [ V_88 ] . V_96 ) ;
for ( V_88 = 0 ; V_88 < F_32 ( V_2 ) ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 ,
V_109 [ V_88 ] . V_96 ) ;
for ( V_91 = 0 ; V_91 < V_110 ; V_91 ++ ) {
for ( V_88 = 0 ; V_88 < V_111 ; V_88 ++ )
sprintf ( V_87 + ( V_92 ++ ) * V_94 ,
V_112 [ V_88 ] . V_96 , V_91 ) ;
}
V_93 = F_11 ( V_2 ) ;
F_33 (prio, &pfc_combined, NUM_PPORT_PRIO) {
for ( V_88 = 0 ; V_88 < V_113 ; V_88 ++ ) {
char V_114 [ V_94 ] ;
snprintf ( V_114 , sizeof( V_114 ) , L_2 , V_91 ) ;
sprintf ( V_87 + ( V_92 ++ ) * V_94 ,
V_115 [ V_88 ] . V_96 , V_114 ) ;
}
}
if ( F_14 ( V_2 ) ) {
for ( V_88 = 0 ; V_88 < V_113 ; V_88 ++ ) {
sprintf ( V_87 + ( V_92 ++ ) * V_94 ,
V_115 [ V_88 ] . V_96 , L_3 ) ;
}
}
for ( V_88 = 0 ; V_88 < F_23 ( V_81 ) ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 , V_81 [ V_88 ] . V_96 ) ;
for ( V_88 = 0 ; V_88 < F_23 ( V_82 ) ; V_88 ++ )
strcpy ( V_87 + ( V_92 ++ ) * V_94 , V_82 [ V_88 ] . V_96 ) ;
V_92 += F_34 ( V_2 , V_87 + V_92 * V_94 ) ;
if ( ! F_35 ( V_116 , & V_2 -> V_117 ) )
return;
for ( V_88 = 0 ; V_88 < V_2 -> V_118 . V_119 ; V_88 ++ )
for ( V_89 = 0 ; V_89 < V_120 ; V_89 ++ )
sprintf ( V_87 + ( V_92 ++ ) * V_94 ,
V_121 [ V_89 ] . V_96 , V_88 ) ;
for ( V_90 = 0 ; V_90 < V_2 -> V_118 . V_122 . V_123 ; V_90 ++ )
for ( V_88 = 0 ; V_88 < V_2 -> V_118 . V_119 ; V_88 ++ )
for ( V_89 = 0 ; V_89 < V_124 ; V_89 ++ )
sprintf ( V_87 + ( V_92 ++ ) * V_94 ,
V_125 [ V_89 ] . V_96 ,
V_2 -> V_126 [ V_88 ] [ V_90 ] ) ;
}
void F_36 ( struct V_1 * V_2 , T_2 V_127 , T_1 * V_87 )
{
int V_88 ;
switch ( V_127 ) {
case V_83 :
for ( V_88 = 0 ; V_88 < F_23 ( V_84 ) ; V_88 ++ )
strcpy ( V_87 + V_88 * V_94 , V_84 [ V_88 ] ) ;
break;
case V_85 :
for ( V_88 = 0 ; V_88 < F_25 ( V_2 ) ; V_88 ++ )
strcpy ( V_87 + V_88 * V_94 ,
V_128 [ V_88 ] ) ;
break;
case V_78 :
F_27 ( V_2 , V_87 ) ;
break;
}
}
static void F_37 ( struct V_15 * V_16 , T_2 V_127 , T_1 * V_87 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_36 ( V_2 , V_127 , V_87 ) ;
}
void F_38 ( struct V_1 * V_2 ,
struct V_129 * V_130 , T_3 * V_87 )
{
struct V_131 * V_118 ;
struct V_132 * V_132 ;
int V_88 , V_89 , V_90 , V_91 , V_92 = 0 ;
unsigned long V_93 ;
if ( ! V_87 )
return;
F_39 ( & V_2 -> V_133 ) ;
if ( F_35 ( V_116 , & V_2 -> V_117 ) )
F_40 ( V_2 , true ) ;
V_118 = & V_2 -> V_118 ;
F_41 ( & V_2 -> V_133 ) ;
for ( V_88 = 0 ; V_88 < V_79 ; V_88 ++ )
V_87 [ V_92 ++ ] = F_42 ( & V_2 -> V_130 . V_134 ,
V_95 , V_88 ) ;
for ( V_88 = 0 ; V_88 < F_17 ( V_2 ) ; V_88 ++ )
V_87 [ V_92 ++ ] = F_43 ( & V_2 -> V_130 . V_135 ,
V_97 , V_88 ) ;
for ( V_88 = 0 ; V_88 < V_80 ; V_88 ++ )
V_87 [ V_92 ++ ] = F_44 ( V_2 -> V_130 . V_136 . V_137 ,
V_98 , V_88 ) ;
for ( V_88 = 0 ; V_88 < V_99 ; V_88 ++ )
V_87 [ V_92 ++ ] = F_44 ( & V_2 -> V_130 . V_138 . V_139 ,
V_100 , V_88 ) ;
for ( V_88 = 0 ; V_88 < V_101 ; V_88 ++ )
V_87 [ V_92 ++ ] = F_44 ( & V_2 -> V_130 . V_138 . V_140 ,
V_102 , V_88 ) ;
for ( V_88 = 0 ; V_88 < V_103 ; V_88 ++ )
V_87 [ V_92 ++ ] = F_44 ( & V_2 -> V_130 . V_138 . V_141 ,
V_104 , V_88 ) ;
for ( V_88 = 0 ; V_88 < F_28 ( V_2 ) ; V_88 ++ )
V_87 [ V_92 ++ ] = F_44 ( & V_2 -> V_130 . V_138 . V_142 ,
V_105 , V_88 ) ;
for ( V_88 = 0 ; V_88 < F_29 ( V_2 ) ; V_88 ++ )
V_87 [ V_92 ++ ] = F_44 ( & V_2 -> V_130 . V_138 . V_143 ,
V_106 , V_88 ) ;
for ( V_88 = 0 ; V_88 < F_30 ( V_2 ) ; V_88 ++ )
V_87 [ V_92 ++ ] = F_45 ( & V_2 -> V_130 . V_144 . V_145 ,
V_107 , V_88 ) ;
for ( V_88 = 0 ; V_88 < F_31 ( V_2 ) ; V_88 ++ )
V_87 [ V_92 ++ ] = F_44 ( & V_2 -> V_130 . V_144 . V_145 ,
V_108 , V_88 ) ;
for ( V_88 = 0 ; V_88 < F_32 ( V_2 ) ; V_88 ++ )
V_87 [ V_92 ++ ] = F_45 ( & V_2 -> V_130 . V_144 . V_145 ,
V_109 , V_88 ) ;
for ( V_91 = 0 ; V_91 < V_110 ; V_91 ++ ) {
for ( V_88 = 0 ; V_88 < V_111 ; V_88 ++ )
V_87 [ V_92 ++ ] = F_44 ( & V_2 -> V_130 . V_138 . V_146 [ V_91 ] ,
V_112 , V_88 ) ;
}
V_93 = F_11 ( V_2 ) ;
F_33 (prio, &pfc_combined, NUM_PPORT_PRIO) {
for ( V_88 = 0 ; V_88 < V_113 ; V_88 ++ ) {
V_87 [ V_92 ++ ] = F_44 ( & V_2 -> V_130 . V_138 . V_146 [ V_91 ] ,
V_115 , V_88 ) ;
}
}
if ( F_14 ( V_2 ) ) {
for ( V_88 = 0 ; V_88 < V_113 ; V_88 ++ ) {
V_87 [ V_92 ++ ] = F_44 ( & V_2 -> V_130 . V_138 . V_146 [ 0 ] ,
V_115 , V_88 ) ;
}
}
V_132 = & V_2 -> V_6 -> V_2 ;
for ( V_88 = 0 ; V_88 < F_23 ( V_81 ) ; V_88 ++ )
V_87 [ V_92 ++ ] = F_42 ( V_132 -> V_147 . V_148 ,
V_81 , V_88 ) ;
for ( V_88 = 0 ; V_88 < F_23 ( V_82 ) ; V_88 ++ )
V_87 [ V_92 ++ ] = F_42 ( V_132 -> V_147 . V_149 ,
V_82 , V_88 ) ;
V_92 += F_46 ( V_2 , V_87 + V_92 ) ;
if ( ! F_35 ( V_116 , & V_2 -> V_117 ) )
return;
for ( V_88 = 0 ; V_88 < V_118 -> V_119 ; V_88 ++ )
for ( V_89 = 0 ; V_89 < V_120 ; V_89 ++ )
V_87 [ V_92 ++ ] =
F_42 ( & V_118 -> V_150 [ V_88 ] -> V_151 . V_130 ,
V_121 , V_89 ) ;
for ( V_90 = 0 ; V_90 < V_2 -> V_118 . V_122 . V_123 ; V_90 ++ )
for ( V_88 = 0 ; V_88 < V_118 -> V_119 ; V_88 ++ )
for ( V_89 = 0 ; V_89 < V_124 ; V_89 ++ )
V_87 [ V_92 ++ ] = F_42 ( & V_118 -> V_150 [ V_88 ] -> V_152 [ V_90 ] . V_130 ,
V_125 , V_89 ) ;
}
static void F_47 ( struct V_15 * V_16 ,
struct V_129 * V_130 ,
T_3 * V_87 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_38 ( V_2 , V_130 , V_87 ) ;
}
static T_2 F_48 ( struct V_1 * V_2 , int V_153 ,
int V_154 )
{
int V_155 ;
int V_156 ;
int V_157 ;
int V_158 ;
if ( V_153 != V_159 )
return V_154 ;
V_156 = 1 << V_2 -> V_118 . V_122 . V_160 ;
V_157 = 1 << V_2 -> V_118 . V_122 . V_161 ;
V_158 = V_156 * V_157 ;
V_155 = V_158 /
F_49 ( V_162 , V_156 ) ;
return ( 1 << ( F_50 ( V_154 * V_155 ) - 1 ) ) ;
}
static T_2 F_51 ( struct V_1 * V_2 , int V_153 ,
int V_163 )
{
int V_155 ;
int V_156 ;
int V_157 ;
int V_158 ;
int V_164 ;
if ( V_153 != V_159 )
return V_163 ;
V_156 = 1 << V_2 -> V_118 . V_122 . V_160 ;
V_157 = 1 << V_2 -> V_118 . V_122 . V_161 ;
V_158 = V_156 * V_157 ;
V_163 = ( 1 << F_50 ( V_163 ) ) ;
V_155 = V_158 /
F_49 ( V_162 , V_156 ) ;
V_164 = F_52 ( V_163 , V_155 ) ;
return 1 << ( F_50 ( V_164 ) ) ;
}
void F_53 ( struct V_1 * V_2 ,
struct V_165 * V_166 )
{
int V_153 = V_2 -> V_118 . V_122 . V_153 ;
V_166 -> V_167 = F_48 ( V_2 , V_153 ,
1 << F_54 ( V_153 ) ) ;
V_166 -> V_168 = 1 << V_169 ;
V_166 -> V_170 = F_48 ( V_2 , V_153 ,
1 << V_2 -> V_118 . V_122 . V_171 ) ;
V_166 -> V_172 = 1 << V_2 -> V_118 . V_122 . V_173 ;
}
static void F_55 ( struct V_15 * V_16 ,
struct V_165 * V_166 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_53 ( V_2 , V_166 ) ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_165 * V_166 )
{
int V_153 = V_2 -> V_118 . V_122 . V_153 ;
struct V_131 V_174 = {} ;
T_2 V_175 ;
T_2 V_176 ;
T_2 V_177 ;
T_1 V_171 ;
T_1 V_173 ;
T_2 V_178 ;
int V_72 = 0 ;
if ( V_166 -> V_179 ) {
F_57 ( V_2 -> V_180 , L_4 ,
V_181 ) ;
return - V_182 ;
}
if ( V_166 -> V_183 ) {
F_57 ( V_2 -> V_180 , L_5 ,
V_181 ) ;
return - V_182 ;
}
V_176 = F_48 ( V_2 , V_153 ,
1 << F_58 ( V_153 ) ) ;
V_177 = F_48 ( V_2 , V_153 ,
1 << F_54 ( V_153 ) ) ;
V_175 = F_51 ( V_2 , V_153 ,
V_166 -> V_170 ) ;
if ( V_166 -> V_170 < V_176 ) {
F_57 ( V_2 -> V_180 , L_6 ,
V_181 , V_166 -> V_170 ,
V_176 ) ;
return - V_182 ;
}
if ( V_166 -> V_170 > V_177 ) {
F_57 ( V_2 -> V_180 , L_7 ,
V_181 , V_166 -> V_170 ,
V_177 ) ;
return - V_182 ;
}
V_178 = F_59 ( V_175 ) ;
if ( V_2 -> V_118 . V_122 . V_153 == V_159 &&
! F_60 ( V_178 ) ) {
F_57 ( V_2 -> V_180 , L_8 ,
V_181 , V_166 -> V_170 ) ;
return - V_182 ;
}
if ( V_166 -> V_172 < ( 1 << V_184 ) ) {
F_57 ( V_2 -> V_180 , L_9 ,
V_181 , V_166 -> V_172 ,
1 << V_184 ) ;
return - V_182 ;
}
if ( V_166 -> V_172 > ( 1 << V_169 ) ) {
F_57 ( V_2 -> V_180 , L_10 ,
V_181 , V_166 -> V_172 ,
1 << V_169 ) ;
return - V_182 ;
}
V_171 = F_50 ( V_175 ) ;
V_173 = F_50 ( V_166 -> V_172 ) ;
if ( V_171 == V_2 -> V_118 . V_122 . V_171 &&
V_173 == V_2 -> V_118 . V_122 . V_173 )
return 0 ;
F_39 ( & V_2 -> V_133 ) ;
V_174 . V_122 = V_2 -> V_118 . V_122 ;
V_174 . V_122 . V_171 = V_171 ;
V_174 . V_122 . V_173 = V_173 ;
if ( ! F_35 ( V_116 , & V_2 -> V_117 ) ) {
V_2 -> V_118 . V_122 = V_174 . V_122 ;
goto V_185;
}
V_72 = F_61 ( V_2 , & V_174 ) ;
if ( V_72 )
goto V_185;
F_62 ( V_2 , & V_174 , NULL ) ;
V_185:
F_41 ( & V_2 -> V_133 ) ;
return V_72 ;
}
static int F_63 ( struct V_15 * V_16 ,
struct V_165 * V_166 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
return F_56 ( V_2 , V_166 ) ;
}
void F_64 ( struct V_1 * V_2 ,
struct V_186 * V_187 )
{
V_187 -> V_188 = V_2 -> V_189 -> V_190 ( V_2 -> V_6 ) ;
V_187 -> V_191 = V_2 -> V_118 . V_122 . V_192 ;
}
static void F_65 ( struct V_15 * V_16 ,
struct V_186 * V_187 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_64 ( V_2 , V_187 ) ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_186 * V_187 )
{
unsigned int V_193 = V_187 -> V_191 ;
struct V_131 V_174 = {} ;
bool V_194 ;
int V_72 = 0 ;
if ( ! V_193 ) {
F_57 ( V_2 -> V_180 , L_11 ,
V_181 ) ;
return - V_182 ;
}
if ( V_2 -> V_118 . V_122 . V_192 == V_193 )
return 0 ;
F_39 ( & V_2 -> V_133 ) ;
V_174 . V_122 = V_2 -> V_118 . V_122 ;
V_174 . V_122 . V_192 = V_193 ;
if ( ! F_67 ( V_2 -> V_180 ) )
F_68 ( V_174 . V_122 . V_195 ,
V_196 , V_193 ) ;
if ( ! F_35 ( V_116 , & V_2 -> V_117 ) ) {
V_2 -> V_118 . V_122 = V_174 . V_122 ;
goto V_197;
}
V_72 = F_61 ( V_2 , & V_174 ) ;
if ( V_72 )
goto V_197;
V_194 = V_2 -> V_180 -> V_198 & V_199 ;
if ( V_194 )
F_69 ( V_2 ) ;
F_62 ( V_2 , & V_174 , NULL ) ;
if ( V_194 ) {
V_72 = F_70 ( V_2 ) ;
if ( V_72 )
F_71 ( V_2 -> V_180 , L_12 ,
V_181 , V_72 ) ;
}
V_197:
F_41 ( & V_2 -> V_133 ) ;
return V_72 ;
}
static int F_72 ( struct V_15 * V_16 ,
struct V_186 * V_187 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
return F_66 ( V_2 , V_187 ) ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_200 * V_201 )
{
if ( ! F_12 ( V_2 -> V_6 , V_202 ) )
return - V_86 ;
V_201 -> V_203 = V_2 -> V_118 . V_122 . V_204 . V_205 ;
V_201 -> V_206 = V_2 -> V_118 . V_122 . V_204 . V_207 ;
V_201 -> V_208 = V_2 -> V_118 . V_122 . V_209 . V_205 ;
V_201 -> V_210 = V_2 -> V_118 . V_122 . V_209 . V_207 ;
V_201 -> V_211 = V_2 -> V_118 . V_122 . V_212 ;
return 0 ;
}
static int F_74 ( struct V_15 * V_180 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
return F_73 ( V_2 , V_201 ) ;
}
static void
F_75 ( struct V_1 * V_2 , struct V_200 * V_201 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_90 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_118 . V_119 ; ++ V_88 ) {
struct V_213 * V_150 = V_2 -> V_118 . V_150 [ V_88 ] ;
for ( V_90 = 0 ; V_90 < V_150 -> V_123 ; V_90 ++ ) {
F_76 ( V_6 ,
& V_150 -> V_152 [ V_90 ] . V_214 . V_215 ,
V_201 -> V_208 ,
V_201 -> V_210 ) ;
}
F_76 ( V_6 , & V_150 -> V_151 . V_214 . V_215 ,
V_201 -> V_203 ,
V_201 -> V_206 ) ;
}
}
int F_77 ( struct V_1 * V_2 ,
struct V_200 * V_201 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_131 V_174 = {} ;
int V_72 = 0 ;
bool V_216 ;
if ( ! F_12 ( V_6 , V_202 ) )
return - V_86 ;
F_39 ( & V_2 -> V_133 ) ;
V_174 . V_122 = V_2 -> V_118 . V_122 ;
V_174 . V_122 . V_209 . V_205 = V_201 -> V_208 ;
V_174 . V_122 . V_209 . V_207 = V_201 -> V_210 ;
V_174 . V_122 . V_204 . V_205 = V_201 -> V_203 ;
V_174 . V_122 . V_204 . V_207 = V_201 -> V_206 ;
V_174 . V_122 . V_212 = ! ! V_201 -> V_211 ;
if ( ! F_35 ( V_116 , & V_2 -> V_117 ) ) {
V_2 -> V_118 . V_122 = V_174 . V_122 ;
goto V_197;
}
V_216 = ! ! V_201 -> V_211 != V_2 -> V_118 . V_122 . V_212 ;
if ( ! V_216 ) {
F_75 ( V_2 , V_201 ) ;
V_2 -> V_118 . V_122 = V_174 . V_122 ;
goto V_197;
}
V_72 = F_61 ( V_2 , & V_174 ) ;
if ( V_72 )
goto V_197;
F_62 ( V_2 , & V_174 , NULL ) ;
V_197:
F_41 ( & V_2 -> V_133 ) ;
return V_72 ;
}
static int F_78 ( struct V_15 * V_180 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
return F_77 ( V_2 , V_201 ) ;
}
static void F_79 ( unsigned long * V_217 ,
T_2 V_218 )
{
unsigned long V_219 = V_218 ;
int V_220 ;
F_33 (proto, &proto_cap, MLX5E_LINK_MODES_NUMBER)
F_80 ( V_217 , V_217 ,
V_221 [ V_220 ] . V_222 ,
V_223 ) ;
}
static void F_81 ( unsigned long * V_224 ,
T_2 V_218 )
{
unsigned long V_219 = V_218 ;
int V_220 ;
F_33 (proto, &proto_cap, MLX5E_LINK_MODES_NUMBER)
F_80 ( V_224 , V_224 ,
V_221 [ V_220 ] . V_225 ,
V_223 ) ;
}
static void F_82 ( struct V_226 * V_227 ,
T_2 V_218 ,
T_1 V_228 )
{
if ( ! V_228 || V_228 >= V_229 ) {
if ( V_218 & ( F_83 ( V_38 )
| F_83 ( V_39 )
| F_83 ( V_30 )
| F_83 ( V_41 )
| F_83 ( V_51 )
| F_83 ( V_17 ) ) ) {
F_84 ( V_227 ,
V_222 ,
V_230 ) ;
F_84 ( V_227 ,
V_231 ,
V_230 ) ;
}
if ( V_218 & ( F_83 ( V_53 )
| F_83 ( V_33 )
| F_83 ( V_25 )
| F_83 ( V_24 )
| F_83 ( V_20 ) ) ) {
F_84 ( V_227 ,
V_222 ,
V_232 ) ;
F_84 ( V_227 ,
V_231 ,
V_232 ) ;
}
return;
}
switch ( V_228 ) {
case V_233 :
F_84 ( V_227 ,
V_222 , V_234 ) ;
F_84 ( V_227 ,
V_231 , V_234 ) ;
break;
case V_235 :
F_84 ( V_227 ,
V_222 , V_236 ) ;
F_84 ( V_227 ,
V_231 , V_236 ) ;
break;
case V_237 :
F_84 ( V_227 ,
V_222 , V_238 ) ;
F_84 ( V_227 ,
V_231 , V_238 ) ;
break;
case V_239 :
F_84 ( V_227 ,
V_222 , V_240 ) ;
F_84 ( V_227 ,
V_231 , V_240 ) ;
break;
case V_241 :
F_84 ( V_227 ,
V_222 , V_230 ) ;
F_84 ( V_227 ,
V_231 , V_230 ) ;
break;
case V_242 :
F_84 ( V_227 ,
V_222 , V_232 ) ;
F_84 ( V_227 ,
V_231 , V_232 ) ;
break;
case V_243 :
case V_244 :
default:
break;
}
}
int F_85 ( struct V_5 * V_6 , T_2 * V_245 )
{
T_2 V_246 = 0 ;
T_2 V_219 ;
int V_72 ;
int V_88 ;
V_72 = F_86 ( V_6 , & V_219 , V_247 ) ;
if ( V_72 )
return V_72 ;
for ( V_88 = 0 ; V_88 < V_248 ; ++ V_88 )
if ( V_219 & F_83 ( V_88 ) )
V_246 = F_87 ( V_246 , V_221 [ V_88 ] . V_245 ) ;
* V_245 = V_246 ;
return 0 ;
}
static void F_88 ( struct V_15 * V_180 ,
T_2 V_249 ,
struct V_226 * V_227 )
{
int V_88 ;
T_2 V_245 = V_250 ;
T_1 V_251 = V_252 ;
if ( ! F_89 ( V_180 ) )
goto V_197;
for ( V_88 = 0 ; V_88 < V_248 ; ++ V_88 ) {
if ( V_249 & F_83 ( V_88 ) ) {
V_245 = V_221 [ V_88 ] . V_245 ;
V_251 = V_253 ;
break;
}
}
V_197:
V_227 -> V_254 . V_245 = V_245 ;
V_227 -> V_254 . V_251 = V_251 ;
}
static void F_90 ( T_2 V_218 ,
struct V_226 * V_227 )
{
unsigned long * V_222 = V_227 -> V_255 . V_222 ;
F_79 ( V_222 , V_218 ) ;
F_84 ( V_227 , V_222 , V_256 ) ;
}
static void F_91 ( T_2 V_218 , T_1 V_76 ,
T_1 V_75 ,
struct V_226 * V_227 )
{
unsigned long * V_231 = V_227 -> V_255 . V_231 ;
F_81 ( V_231 , V_218 ) ;
if ( V_75 )
F_84 ( V_227 , V_231 , V_256 ) ;
if ( V_76 ^ V_75 )
F_84 ( V_227 , V_231 , V_257 ) ;
}
static T_1 F_92 ( T_2 V_258 , T_1 V_228 )
{
if ( V_228 && V_228 < V_229 )
return V_259 [ V_228 ] ;
if ( V_258 &
( F_83 ( V_39 ) |
F_83 ( V_41 ) |
F_83 ( V_51 ) |
F_83 ( V_17 ) ) ) {
return V_260 ;
}
if ( V_258 &
( F_83 ( V_30 ) |
F_83 ( V_38 ) |
F_83 ( V_48 ) ) ) {
return V_261 ;
}
if ( V_258 &
( F_83 ( V_24 ) |
F_83 ( V_25 ) |
F_83 ( V_33 ) |
F_83 ( V_53 ) ) ) {
return V_262 ;
}
return V_263 ;
}
static void F_93 ( T_2 V_264 ,
struct V_226 * V_227 )
{
unsigned long * V_265 = V_227 -> V_255 . V_265 ;
F_81 ( V_265 , V_264 ) ;
}
static int F_94 ( struct V_15 * V_180 ,
struct V_226 * V_227 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_197 [ F_95 ( V_266 ) ] = { 0 } ;
T_2 V_75 = 0 ;
T_2 V_76 = 0 ;
T_2 V_218 ;
T_2 V_267 ;
T_2 V_264 ;
T_2 V_249 ;
T_1 V_268 ;
T_1 V_269 ;
T_1 V_228 ;
int V_72 ;
V_72 = F_96 ( V_6 , V_197 , sizeof( V_197 ) , V_247 , 1 ) ;
if ( V_72 ) {
F_71 ( V_180 , L_13 ,
V_181 , V_72 ) ;
goto V_270;
}
V_218 = F_97 ( V_266 , V_197 , V_271 ) ;
V_267 = F_97 ( V_266 , V_197 , V_267 ) ;
V_249 = F_97 ( V_266 , V_197 , V_249 ) ;
V_264 = F_97 ( V_266 , V_197 , V_272 ) ;
V_268 = F_97 ( V_266 , V_197 , V_268 ) ;
V_269 = F_97 ( V_266 , V_197 , V_269 ) ;
V_228 = F_97 ( V_266 , V_197 , V_228 ) ;
F_15 ( V_6 , & V_75 , & V_76 ) ;
F_98 ( V_227 , V_222 ) ;
F_98 ( V_227 , V_231 ) ;
F_90 ( V_218 , V_227 ) ;
F_91 ( V_267 , V_76 , V_75 , V_227 ) ;
F_88 ( V_180 , V_249 , V_227 ) ;
V_249 = V_249 ? V_249 : V_218 ;
V_227 -> V_254 . V_273 = F_92 ( V_249 ,
V_228 ) ;
F_82 ( V_227 , V_267 ,
V_228 ) ;
F_93 ( V_264 , V_227 ) ;
if ( V_269 == V_274 )
F_84 ( V_227 ,
V_265 , V_275 ) ;
V_227 -> V_254 . V_276 = V_268 ? V_277 :
V_278 ;
F_84 ( V_227 , V_222 ,
V_275 ) ;
if ( ! V_268 )
F_84 ( V_227 ,
V_231 , V_275 ) ;
V_270:
return V_72 ;
}
static T_2 F_99 ( const unsigned long * V_255 )
{
T_2 V_88 , V_279 = 0 ;
for ( V_88 = 0 ; V_88 < V_248 ; ++ V_88 ) {
if ( F_100 ( V_221 [ V_88 ] . V_225 ,
V_255 ,
V_223 ) )
V_279 |= F_83 ( V_88 ) ;
}
return V_279 ;
}
static T_2 F_101 ( T_2 V_245 )
{
T_2 V_88 , V_280 = 0 ;
for ( V_88 = 0 ; V_88 < V_248 ; ++ V_88 ) {
if ( V_221 [ V_88 ] . V_245 == V_245 )
V_280 |= F_83 ( V_88 ) ;
}
return V_280 ;
}
static int F_102 ( struct V_15 * V_180 ,
const struct V_226 * V_227 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_218 , V_267 ;
bool V_281 = false ;
T_1 V_268 ;
T_1 V_282 ;
bool V_283 ;
T_2 V_255 ;
T_1 V_269 ;
T_2 V_245 ;
int V_72 ;
V_245 = V_227 -> V_254 . V_245 ;
V_255 = V_227 -> V_254 . V_276 == V_278 ?
F_99 ( V_227 -> V_255 . V_231 ) :
F_101 ( V_245 ) ;
V_72 = F_86 ( V_6 , & V_218 , V_247 ) ;
if ( V_72 ) {
F_71 ( V_180 , L_14 ,
V_181 , V_72 ) ;
goto V_197;
}
V_255 = V_255 & V_218 ;
if ( ! V_255 ) {
F_71 ( V_180 , L_15 ,
V_181 ) ;
V_72 = - V_182 ;
goto V_197;
}
V_72 = F_103 ( V_6 , & V_267 , V_247 ) ;
if ( V_72 ) {
F_71 ( V_180 , L_16 ,
V_181 , V_72 ) ;
goto V_197;
}
F_104 ( V_6 , V_247 , & V_269 ,
& V_282 , & V_268 ) ;
V_283 = V_227 -> V_254 . V_276 == V_277 ;
V_281 = ( ( ! V_283 && V_268 ) ||
( V_283 && ! V_268 ) ) ;
if ( ! V_281 && V_255 == V_267 )
goto V_197;
F_105 ( V_6 , V_283 , V_255 , V_247 ) ;
F_106 ( V_6 ) ;
V_197:
return V_72 ;
}
static T_2 F_107 ( struct V_15 * V_180 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
return sizeof( V_2 -> V_118 . V_122 . V_284 ) ;
}
static T_2 F_108 ( struct V_15 * V_180 )
{
return V_196 ;
}
static int F_109 ( struct V_15 * V_180 , T_2 * V_285 , T_1 * V_286 ,
T_1 * V_287 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
if ( V_285 )
memcpy ( V_285 , V_2 -> V_118 . V_122 . V_195 ,
sizeof( V_2 -> V_118 . V_122 . V_195 ) ) ;
if ( V_286 )
memcpy ( V_286 , V_2 -> V_118 . V_122 . V_284 ,
sizeof( V_2 -> V_118 . V_122 . V_284 ) ) ;
if ( V_287 )
* V_287 = V_2 -> V_118 . V_122 . V_288 ;
return 0 ;
}
static void F_110 ( struct V_1 * V_2 , void * V_289 , int V_290 )
{
void * V_291 = F_111 ( V_292 , V_289 , V_293 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_294 = F_112 ( V_291 ) ;
int V_295 ;
F_113 ( V_292 , V_289 , V_296 . V_297 , 1 ) ;
for ( V_295 = 0 ; V_295 < V_298 ; V_295 ++ ) {
memset ( V_291 , 0 , V_294 ) ;
F_114 ( & V_2 -> V_118 . V_122 , V_295 , V_291 , false ) ;
F_115 ( V_6 , V_2 -> V_299 [ V_295 ] . V_300 , V_289 , V_290 ) ;
}
if ( ! F_116 ( V_2 -> V_6 ) )
return;
for ( V_295 = 0 ; V_295 < V_298 ; V_295 ++ ) {
memset ( V_291 , 0 , V_294 ) ;
F_114 ( & V_2 -> V_118 . V_122 , V_295 , V_291 , true ) ;
F_115 ( V_6 , V_2 -> V_301 [ V_295 ] . V_300 , V_289 , V_290 ) ;
}
}
static int F_117 ( struct V_15 * V_16 , const T_2 * V_285 ,
const T_1 * V_286 , const T_1 V_287 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
int V_290 = F_112 ( V_292 ) ;
bool V_302 = false ;
void * V_289 ;
if ( ( V_287 != V_303 ) &&
( V_287 != V_304 ) &&
( V_287 != V_305 ) )
return - V_182 ;
V_289 = F_118 ( V_290 , V_306 ) ;
if ( ! V_289 )
return - V_307 ;
F_39 ( & V_2 -> V_133 ) ;
if ( V_287 != V_303 &&
V_287 != V_2 -> V_118 . V_122 . V_288 ) {
V_2 -> V_118 . V_122 . V_288 = V_287 ;
V_302 = true ;
}
if ( V_285 ) {
memcpy ( V_2 -> V_118 . V_122 . V_195 , V_285 ,
sizeof( V_2 -> V_118 . V_122 . V_195 ) ) ;
if ( F_35 ( V_116 , & V_2 -> V_117 ) ) {
T_2 V_308 = V_2 -> V_309 . V_308 ;
struct V_310 V_311 = {
. V_312 = true ,
{
. V_313 = {
. V_287 = V_2 -> V_118 . V_122 . V_288 ,
. V_118 = & V_2 -> V_118 ,
} ,
} ,
} ;
F_119 ( V_2 , V_308 , V_196 , V_311 ) ;
}
}
if ( V_286 ) {
memcpy ( V_2 -> V_118 . V_122 . V_284 , V_286 ,
sizeof( V_2 -> V_118 . V_122 . V_284 ) ) ;
V_302 = V_302 ||
V_2 -> V_118 . V_122 . V_288 == V_305 ;
}
if ( V_302 )
F_110 ( V_2 , V_289 , V_290 ) ;
F_41 ( & V_2 -> V_133 ) ;
F_120 ( V_289 ) ;
return 0 ;
}
static int F_121 ( struct V_15 * V_180 ,
struct V_314 * V_315 , T_2 * V_316 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
int V_72 = 0 ;
switch ( V_315 -> V_317 ) {
case V_318 :
V_315 -> V_87 = V_2 -> V_118 . V_122 . V_192 ;
break;
case V_319 :
V_315 -> V_320 = V_2 -> V_321 . V_322 . V_323 ;
break;
case V_324 :
V_72 = F_122 ( V_2 , V_315 , V_315 -> V_321 . V_325 ) ;
break;
case V_326 :
V_72 = F_123 ( V_2 , V_315 , V_316 ) ;
break;
default:
V_72 = - V_86 ;
break;
}
return V_72 ;
}
static int F_124 ( struct V_15 * V_16 ,
const struct V_327 * V_328 ,
void * V_87 )
{
const struct V_1 * V_2 = F_8 ( V_16 ) ;
int V_72 = 0 ;
switch ( V_328 -> V_329 ) {
case V_330 :
* ( T_2 * ) V_87 = V_2 -> V_118 . V_122 . V_331 ;
break;
default:
V_72 = - V_182 ;
break;
}
return V_72 ;
}
static int F_125 ( struct V_15 * V_16 ,
const struct V_327 * V_328 ,
const void * V_87 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_131 V_174 = {} ;
int V_72 = 0 ;
T_2 V_332 ;
F_39 ( & V_2 -> V_133 ) ;
switch ( V_328 -> V_329 ) {
case V_330 :
V_332 = * ( T_2 * ) V_87 ;
if ( V_332 > F_126 ( V_6 ) ) {
V_72 = - V_182 ;
break;
}
V_174 . V_122 = V_2 -> V_118 . V_122 ;
V_174 . V_122 . V_331 = V_332 ;
if ( ! F_35 ( V_116 , & V_2 -> V_117 ) ) {
V_2 -> V_118 . V_122 = V_174 . V_122 ;
break;
}
V_72 = F_61 ( V_2 , & V_174 ) ;
if ( V_72 )
break;
F_62 ( V_2 , & V_174 , NULL ) ;
break;
default:
V_72 = - V_182 ;
break;
}
F_41 ( & V_2 -> V_133 ) ;
return V_72 ;
}
static void F_127 ( struct V_15 * V_180 ,
struct V_333 * V_334 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_72 ;
V_72 = F_15 ( V_6 , & V_334 -> V_75 ,
& V_334 -> V_76 ) ;
if ( V_72 ) {
F_71 ( V_180 , L_17 ,
V_181 , V_72 ) ;
}
}
static int F_128 ( struct V_15 * V_180 ,
struct V_333 * V_334 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_72 ;
if ( V_334 -> V_276 )
return - V_182 ;
V_72 = F_129 ( V_6 ,
V_334 -> V_75 ? 1 : 0 ,
V_334 -> V_76 ? 1 : 0 ) ;
if ( V_72 ) {
F_71 ( V_180 , L_18 ,
V_181 , V_72 ) ;
}
return V_72 ;
}
int F_130 ( struct V_1 * V_2 ,
struct V_335 * V_315 )
{
int V_336 ;
V_336 = F_131 ( V_2 -> V_180 , V_315 ) ;
if ( V_336 )
return V_336 ;
V_315 -> V_337 = V_2 -> V_338 . V_339 ?
F_132 ( V_2 -> V_338 . V_339 ) : - 1 ;
if ( ! F_12 ( V_2 -> V_6 , V_340 ) )
return 0 ;
V_315 -> V_341 |= V_342 |
V_343 |
V_344 ;
V_315 -> V_345 = F_133 ( V_346 ) |
F_133 ( V_347 ) ;
V_315 -> V_348 = F_133 ( V_349 ) |
F_133 ( V_350 ) ;
return 0 ;
}
static int F_134 ( struct V_15 * V_16 ,
struct V_335 * V_315 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
return F_130 ( V_2 , V_315 ) ;
}
static T_4 F_135 ( struct V_5 * V_6 )
{
T_4 V_336 = 0 ;
if ( F_12 ( V_6 , V_351 ) )
V_336 |= V_352 ;
if ( F_12 ( V_6 , V_353 ) )
V_336 |= V_354 ;
if ( F_12 ( V_6 , V_355 ) )
V_336 |= V_356 ;
if ( F_12 ( V_6 , V_357 ) )
V_336 |= V_358 ;
if ( F_12 ( V_6 , V_359 ) )
V_336 |= V_360 ;
if ( F_12 ( V_6 , V_361 ) )
V_336 |= V_362 ;
if ( F_12 ( V_6 , V_363 ) )
V_336 |= V_364 ;
return V_336 ;
}
static T_4 F_136 ( T_1 V_365 )
{
T_4 V_336 = 0 ;
if ( V_365 & V_366 )
V_336 |= V_352 ;
if ( V_365 & V_367 )
V_336 |= V_354 ;
if ( V_365 & V_368 )
V_336 |= V_356 ;
if ( V_365 & V_369 )
V_336 |= V_358 ;
if ( V_365 & V_370 )
V_336 |= V_360 ;
if ( V_365 & V_371 )
V_336 |= V_362 ;
if ( V_365 & V_372 )
V_336 |= V_364 ;
return V_336 ;
}
static T_1 F_137 ( T_4 V_365 )
{
T_1 V_336 = 0 ;
if ( V_365 & V_352 )
V_336 |= V_366 ;
if ( V_365 & V_354 )
V_336 |= V_367 ;
if ( V_365 & V_356 )
V_336 |= V_368 ;
if ( V_365 & V_358 )
V_336 |= V_369 ;
if ( V_365 & V_360 )
V_336 |= V_370 ;
if ( V_365 & V_362 )
V_336 |= V_371 ;
if ( V_365 & V_364 )
V_336 |= V_372 ;
return V_336 ;
}
static void F_138 ( struct V_15 * V_180 ,
struct V_373 * V_374 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_375 ;
int V_72 ;
memset ( V_374 , 0 , sizeof( * V_374 ) ) ;
V_374 -> V_222 = F_135 ( V_6 ) ;
if ( ! V_374 -> V_222 )
return;
V_72 = F_139 ( V_6 , & V_375 ) ;
if ( V_72 )
return;
V_374 -> V_376 = F_136 ( V_375 ) ;
}
static int F_140 ( struct V_15 * V_180 , struct V_373 * V_374 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_4 V_377 = F_135 ( V_6 ) ;
T_2 V_375 ;
if ( ! V_377 )
return - V_86 ;
if ( V_374 -> V_376 & ~ V_377 )
return - V_182 ;
V_375 = F_137 ( V_374 -> V_376 ) ;
return F_141 ( V_6 , V_375 ) ;
}
static int F_142 ( struct V_15 * V_16 ,
enum V_378 V_117 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_5 V_379 ;
if ( ! F_12 ( V_6 , V_380 ) )
return - V_86 ;
switch ( V_117 ) {
case V_381 :
V_379 = V_382 ;
break;
case V_383 :
V_379 = V_384 ;
break;
default:
return - V_86 ;
}
return F_143 ( V_6 , V_379 ) ;
}
static int F_144 ( struct V_15 * V_180 ,
struct V_385 * V_386 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
struct V_5 * V_16 = V_2 -> V_6 ;
int V_387 = 0 ;
T_1 V_87 [ 4 ] ;
V_387 = F_145 ( V_16 , 0 , 2 , V_87 ) ;
if ( V_387 < 2 )
return - V_388 ;
switch ( V_87 [ 0 ] ) {
case V_389 :
V_386 -> type = V_390 ;
V_386 -> V_391 = V_392 ;
break;
case V_393 :
case V_394 :
if ( V_87 [ 0 ] == V_394 || V_87 [ 1 ] >= 0x3 ) {
V_386 -> type = V_395 ;
V_386 -> V_391 = V_396 ;
} else {
V_386 -> type = V_390 ;
V_386 -> V_391 = V_392 ;
}
break;
case V_397 :
V_386 -> type = V_398 ;
V_386 -> V_391 = V_399 ;
break;
default:
F_71 ( V_2 -> V_180 , L_19 ,
V_181 , V_87 [ 0 ] ) ;
return - V_182 ;
}
return 0 ;
}
static int F_146 ( struct V_15 * V_180 ,
struct V_400 * V_401 ,
T_1 * V_87 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_402 = V_401 -> V_402 ;
int V_387 ;
int V_88 = 0 ;
if ( ! V_401 -> V_403 )
return - V_182 ;
memset ( V_87 , 0 , V_401 -> V_403 ) ;
while ( V_88 < V_401 -> V_403 ) {
V_387 = F_145 ( V_6 , V_402 , V_401 -> V_403 - V_88 ,
V_87 + V_88 ) ;
if ( ! V_387 )
return 0 ;
if ( V_387 < 0 ) {
F_71 ( V_2 -> V_180 , L_20 ,
V_181 , V_387 ) ;
return 0 ;
}
V_88 += V_387 ;
V_402 += V_387 ;
}
return 0 ;
}
static int F_147 ( struct V_15 * V_180 , bool V_404 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_131 V_174 = {} ;
bool V_405 ;
T_1 V_406 ;
int V_72 = 0 ;
V_406 = V_404 ?
V_407 :
V_408 ;
V_405 = V_406 != V_2 -> V_118 . V_122 . V_406 ;
if ( V_406 == V_407 &&
! F_12 ( V_6 , V_409 ) )
return - V_86 ;
if ( ! V_405 )
return 0 ;
V_174 . V_122 = V_2 -> V_118 . V_122 ;
F_148 ( & V_174 . V_122 , V_406 ) ;
if ( ! F_35 ( V_116 , & V_2 -> V_117 ) ) {
V_2 -> V_118 . V_122 = V_174 . V_122 ;
return 0 ;
}
V_72 = F_61 ( V_2 , & V_174 ) ;
if ( V_72 )
return V_72 ;
F_62 ( V_2 , & V_174 , NULL ) ;
return 0 ;
}
int F_149 ( struct V_1 * V_2 , bool V_410 )
{
bool V_411 = F_150 ( & V_2 -> V_118 . V_122 , V_412 ) ;
struct V_131 V_174 = {} ;
int V_72 = 0 ;
if ( ! F_12 ( V_2 -> V_6 , V_413 ) )
return V_410 ? - V_86 : 0 ;
if ( V_411 == V_410 )
return 0 ;
V_174 . V_122 = V_2 -> V_118 . V_122 ;
F_151 ( & V_174 . V_122 , V_412 , V_410 ) ;
F_152 ( V_2 -> V_6 , & V_174 . V_122 ,
V_174 . V_122 . V_153 ) ;
if ( ! F_35 ( V_116 , & V_2 -> V_117 ) ) {
V_2 -> V_118 . V_122 = V_174 . V_122 ;
return 0 ;
}
V_72 = F_61 ( V_2 , & V_174 ) ;
if ( V_72 )
return V_72 ;
F_62 ( V_2 , & V_174 , NULL ) ;
return 0 ;
}
static int F_153 ( struct V_15 * V_180 ,
bool V_404 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( ! F_12 ( V_6 , V_413 ) )
return - V_86 ;
if ( V_404 && V_2 -> V_338 . V_414 . V_415 != V_349 ) {
F_71 ( V_180 , L_21 ) ;
return - V_182 ;
}
F_149 ( V_2 , V_404 ) ;
V_2 -> V_118 . V_122 . V_416 = V_404 ;
return 0 ;
}
static int F_154 ( struct V_15 * V_180 ,
T_2 V_417 ,
enum V_418 V_419 ,
T_6 V_420 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
bool V_404 = ! ! ( V_417 & V_419 ) ;
T_2 V_421 = V_417 ^ V_2 -> V_118 . V_122 . V_422 ;
int V_72 ;
if ( ! ( V_421 & V_419 ) )
return 0 ;
V_72 = V_420 ( V_180 , V_404 ) ;
if ( V_72 ) {
F_71 ( V_180 , L_22 ,
V_404 ? L_23 : L_24 , V_419 , V_72 ) ;
return V_72 ;
}
F_151 ( & V_2 -> V_118 . V_122 , V_419 , V_404 ) ;
return 0 ;
}
static int F_155 ( struct V_15 * V_180 , T_2 V_422 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
int V_72 ;
F_39 ( & V_2 -> V_133 ) ;
V_72 = F_154 ( V_180 , V_422 ,
V_423 ,
F_147 ) ;
if ( V_72 )
goto V_197;
V_72 = F_154 ( V_180 , V_422 ,
V_412 ,
F_153 ) ;
V_197:
F_41 ( & V_2 -> V_133 ) ;
return V_72 ;
}
static T_2 F_156 ( struct V_15 * V_180 )
{
struct V_1 * V_2 = F_8 ( V_180 ) ;
return V_2 -> V_118 . V_122 . V_422 ;
}
static int F_157 ( struct V_15 * V_16 , struct V_314 * V_317 )
{
int V_72 = 0 ;
struct V_1 * V_2 = F_8 ( V_16 ) ;
switch ( V_317 -> V_317 ) {
case V_424 :
V_72 = F_158 ( V_2 , & V_317 -> V_321 ) ;
break;
case V_425 :
V_72 = F_159 ( V_2 , V_317 -> V_321 . V_325 ) ;
break;
default:
V_72 = - V_86 ;
break;
}
return V_72 ;
}
int F_160 ( struct V_1 * V_2 ,
struct V_426 * V_427 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_15 * V_16 = V_2 -> V_180 ;
const struct V_428 * V_429 ;
int V_72 ;
if ( V_427 -> V_430 != V_431 )
return - V_86 ;
V_72 = F_161 ( & V_429 , V_427 -> V_87 , & V_16 -> V_16 ) ;
if ( V_72 )
return V_72 ;
F_162 ( V_16 ) ;
F_163 () ;
V_72 = F_164 ( V_6 , V_429 ) ;
F_165 ( V_429 ) ;
F_166 () ;
F_167 ( V_16 ) ;
return V_72 ;
}
static int F_168 ( struct V_15 * V_16 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
return F_160 ( V_2 , V_427 ) ;
}
