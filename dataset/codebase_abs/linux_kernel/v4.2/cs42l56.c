static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_13 :
return true ;
default:
return false ;
}
}
static int F_3 ( int V_50 , int V_51 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < F_4 ( V_53 ) ; V_52 ++ ) {
if ( V_53 [ V_52 ] . V_50 == V_50 &&
V_53 [ V_52 ] . V_54 == V_51 )
return V_53 [ V_52 ] . V_55 ;
}
return - V_56 ;
}
static int F_5 ( struct V_57 * V_58 ,
int V_59 , unsigned int V_60 , int V_61 )
{
struct V_62 * V_63 = V_58 -> V_63 ;
struct V_64 * V_65 = F_6 ( V_63 ) ;
switch ( V_60 ) {
case V_66 :
case V_67 :
case V_68 :
V_65 -> V_69 = 0 ;
V_65 -> V_70 = 0 ;
break;
case V_71 :
case V_72 :
case V_73 :
V_65 -> V_69 = V_74 ;
V_65 -> V_70 = 0 ;
break;
case V_75 :
case V_76 :
case V_77 :
V_65 -> V_69 = V_74 ;
V_65 -> V_70 = V_78 ;
break;
default:
return - V_56 ;
}
V_65 -> V_50 = V_60 ;
F_7 ( V_63 , V_8 ,
V_79 ,
V_65 -> V_70 ) ;
F_7 ( V_63 , V_8 ,
V_80 ,
V_65 -> V_69 ) ;
return 0 ;
}
static int F_8 ( struct V_57 * V_58 , unsigned int V_81 )
{
struct V_62 * V_63 = V_58 -> V_63 ;
struct V_64 * V_65 = F_6 ( V_63 ) ;
switch ( V_81 & V_82 ) {
case V_83 :
V_65 -> V_84 = V_85 ;
break;
case V_86 :
V_65 -> V_84 = V_87 ;
break;
default:
return - V_56 ;
}
switch ( V_81 & V_88 ) {
case V_89 :
V_65 -> V_90 = V_91 ;
break;
case V_92 :
V_65 -> V_90 = V_93 ;
break;
default:
return - V_56 ;
}
switch ( V_81 & V_94 ) {
case V_95 :
V_65 -> V_96 = 0 ;
break;
case V_97 :
V_65 -> V_96 = V_98 ;
break;
default:
return - V_56 ;
}
F_7 ( V_63 , V_8 ,
V_99 , V_65 -> V_84 ) ;
F_7 ( V_63 , V_10 ,
V_100 , V_65 -> V_90 ) ;
F_7 ( V_63 , V_8 ,
V_101 , V_65 -> V_96 ) ;
return 0 ;
}
static int F_9 ( struct V_57 * V_102 , int V_103 )
{
struct V_62 * V_63 = V_102 -> V_63 ;
if ( V_103 ) {
F_7 ( V_63 , V_15 ,
V_104 |
V_105 |
V_106 |
V_107 |
V_108 |
V_109 ,
V_110 ) ;
F_7 ( V_63 , V_31 ,
V_111 |
V_112 ,
V_110 ) ;
F_7 ( V_63 , V_43 ,
V_113 , V_110 ) ;
F_7 ( V_63 , V_44 ,
V_113 , V_110 ) ;
F_7 ( V_63 , V_45 ,
V_114 , V_110 ) ;
F_7 ( V_63 , V_46 ,
V_114 , V_110 ) ;
} else {
F_7 ( V_63 , V_15 ,
V_104 |
V_105 |
V_106 |
V_107 |
V_108 |
V_109 ,
V_115 ) ;
F_7 ( V_63 , V_31 ,
V_111 |
V_112 ,
V_115 ) ;
F_7 ( V_63 , V_43 ,
V_113 , V_115 ) ;
F_7 ( V_63 , V_44 ,
V_113 , V_115 ) ;
F_7 ( V_63 , V_45 ,
V_114 , V_115 ) ;
F_7 ( V_63 , V_46 ,
V_114 , V_115 ) ;
}
return 0 ;
}
static int F_10 ( struct V_116 * V_117 ,
struct V_118 * V_119 ,
struct V_57 * V_102 )
{
struct V_62 * V_63 = V_102 -> V_63 ;
struct V_64 * V_65 = F_6 ( V_63 ) ;
int V_55 ;
V_55 = F_3 ( V_65 -> V_50 , F_11 ( V_119 ) ) ;
if ( V_55 >= 0 ) {
F_7 ( V_63 , V_9 ,
V_120 , V_55 ) ;
} else {
F_12 ( V_63 -> V_2 , L_1 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_13 ( struct V_62 * V_63 ,
enum V_121 V_122 )
{
struct V_64 * V_65 = F_6 ( V_63 ) ;
int V_123 ;
switch ( V_122 ) {
case V_124 :
break;
case V_125 :
F_7 ( V_63 , V_8 ,
V_126 , 0 ) ;
F_7 ( V_63 , V_6 ,
V_127 , 0 ) ;
break;
case V_128 :
if ( F_14 ( V_63 ) == V_129 ) {
F_15 ( V_65 -> V_130 , false ) ;
F_16 ( V_65 -> V_130 ) ;
V_123 = F_17 ( F_4 ( V_65 -> V_131 ) ,
V_65 -> V_131 ) ;
if ( V_123 != 0 ) {
F_12 ( V_65 -> V_2 ,
L_2 ,
V_123 ) ;
return V_123 ;
}
}
F_7 ( V_63 , V_6 ,
V_127 , 1 ) ;
break;
case V_129 :
F_7 ( V_63 , V_6 ,
V_127 , 1 ) ;
F_7 ( V_63 , V_8 ,
V_126 , 1 ) ;
F_15 ( V_65 -> V_130 , true ) ;
F_18 ( F_4 ( V_65 -> V_131 ) ,
V_65 -> V_131 ) ;
break;
}
return 0 ;
}
static void F_19 ( struct V_132 * V_133 )
{
struct V_64 * V_65 =
F_20 ( V_133 , struct V_64 , V_134 ) ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_135 * V_136 = F_21 ( V_63 ) ;
int V_52 ;
int V_137 = 0 ;
int V_138 = 0 ;
if ( V_65 -> V_139 ) {
for ( V_52 = 0 ; V_52 < F_4 ( V_140 ) ; V_52 ++ ) {
if ( abs ( V_65 -> V_139 - V_140 [ V_52 ] ) <
abs ( V_65 -> V_139 - V_140 [ V_138 ] ) )
V_138 = V_52 ;
}
F_22 ( V_63 -> V_2 , L_3 ,
V_140 [ V_138 ] , V_65 -> V_139 ) ;
V_137 = ( V_138 << V_141 ) ;
F_23 ( V_136 , L_4 ) ;
} else {
F_22 ( V_63 -> V_2 , L_5 ) ;
F_24 ( V_136 , L_4 ) ;
}
F_7 ( V_63 , V_24 ,
V_142 , V_137 ) ;
F_25 ( V_136 ) ;
}
static int F_26 ( struct V_143 * V_2 , unsigned int type ,
unsigned int V_144 , int V_145 )
{
struct V_62 * V_63 = F_27 ( V_2 ) ;
struct V_64 * V_65 = F_6 ( V_63 ) ;
F_22 ( V_63 -> V_2 , L_6 , V_144 , V_145 ) ;
switch ( V_144 ) {
case V_146 :
if ( V_145 )
V_145 = 261 ;
case V_147 :
break;
default:
return - 1 ;
}
V_65 -> V_139 = V_145 ;
F_28 ( & V_65 -> V_134 ) ;
return 0 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_148 * V_149 ,
const char * V_150 , T_2 V_151 )
{
struct V_64 * V_65 = F_30 ( V_2 ) ;
long int time ;
int V_123 ;
V_123 = F_31 ( V_150 , 10 , & time ) ;
if ( V_123 != 0 )
return V_123 ;
F_32 ( V_65 -> V_152 , V_153 , V_147 , time ) ;
return V_151 ;
}
static void F_33 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = F_6 ( V_63 ) ;
int V_123 ;
V_65 -> V_152 = F_34 ( V_63 -> V_2 ) ;
if ( ! V_65 -> V_152 ) {
F_12 ( V_63 -> V_2 , L_7 ) ;
return;
}
F_35 ( & V_65 -> V_134 , F_19 ) ;
V_65 -> V_139 = 0 ;
V_65 -> V_152 -> V_154 = L_8 ;
V_65 -> V_152 -> V_155 = F_36 ( V_63 -> V_2 ) ;
V_65 -> V_152 -> V_156 . V_157 = V_158 ;
V_65 -> V_152 -> V_159 [ 0 ] = F_37 ( V_153 ) ;
V_65 -> V_152 -> V_160 [ 0 ] = F_37 ( V_146 ) | F_37 ( V_147 ) ;
V_65 -> V_152 -> V_161 = F_26 ;
V_65 -> V_152 -> V_2 . V_162 = V_63 -> V_2 ;
F_38 ( V_65 -> V_152 , V_63 ) ;
V_123 = F_39 ( V_65 -> V_152 ) ;
if ( V_123 != 0 ) {
V_65 -> V_152 = NULL ;
F_12 ( V_63 -> V_2 , L_9 ) ;
}
V_123 = F_40 ( V_63 -> V_2 , & V_163 ) ;
if ( V_123 != 0 ) {
F_12 ( V_63 -> V_2 , L_10 ,
V_123 ) ;
}
}
static void F_41 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = F_6 ( V_63 ) ;
F_42 ( V_63 -> V_2 , & V_163 ) ;
F_43 ( & V_65 -> V_134 ) ;
V_65 -> V_152 = NULL ;
F_7 ( V_63 , V_26 ,
V_164 , 0 ) ;
}
static int F_44 ( struct V_62 * V_63 )
{
F_33 ( V_63 ) ;
return 0 ;
}
static int F_45 ( struct V_62 * V_63 )
{
F_41 ( V_63 ) ;
return 0 ;
}
static int F_46 ( struct V_165 * V_165 ,
struct V_166 * V_167 )
{
struct V_168 * V_169 = V_165 -> V_2 . V_170 ;
T_3 V_171 ;
if ( F_47 ( V_169 , L_11 ) )
V_167 -> V_172 = true ;
if ( F_47 ( V_169 , L_12 ) )
V_167 -> V_173 = true ;
if ( F_47 ( V_169 , L_13 ) )
V_167 -> V_174 = true ;
if ( F_47 ( V_169 , L_14 ) )
V_167 -> V_175 = true ;
if ( F_48 ( V_169 , L_15 , & V_171 ) >= 0 )
V_167 -> V_176 = V_171 ;
if ( F_48 ( V_169 , L_16 , & V_171 ) >= 0 )
V_167 -> V_177 = V_171 ;
if ( F_48 ( V_169 , L_17 , & V_171 ) >= 0 )
V_167 -> V_178 = V_171 ;
if ( F_48 ( V_169 , L_18 , & V_171 ) >= 0 )
V_167 -> V_179 = V_171 ;
if ( F_48 ( V_169 , L_18 , & V_171 ) >= 0 )
V_167 -> V_180 = V_171 ;
V_167 -> V_181 = F_49 ( V_169 , L_19 , 0 ) ;
return 0 ;
}
static int F_50 ( struct V_165 * V_165 ,
const struct V_182 * V_156 )
{
struct V_64 * V_65 ;
struct V_166 * V_167 =
F_51 ( & V_165 -> V_2 ) ;
int V_123 , V_52 ;
unsigned int V_183 = 0 ;
unsigned int V_184 , V_185 ;
unsigned int V_3 ;
V_65 = F_52 ( & V_165 -> V_2 ,
sizeof( struct V_64 ) ,
V_186 ) ;
if ( V_65 == NULL )
return - V_187 ;
V_65 -> V_2 = & V_165 -> V_2 ;
V_65 -> V_130 = F_53 ( V_165 , & V_188 ) ;
if ( F_54 ( V_65 -> V_130 ) ) {
V_123 = F_55 ( V_65 -> V_130 ) ;
F_12 ( & V_165 -> V_2 , L_20 , V_123 ) ;
return V_123 ;
}
if ( V_167 ) {
V_65 -> V_167 = * V_167 ;
} else {
V_167 = F_52 ( & V_165 -> V_2 ,
sizeof( struct V_166 ) ,
V_186 ) ;
if ( ! V_167 ) {
F_12 ( & V_165 -> V_2 ,
L_21 ) ;
return - V_187 ;
}
if ( V_165 -> V_2 . V_170 ) {
V_123 = F_46 ( V_165 ,
& V_65 -> V_167 ) ;
if ( V_123 != 0 )
return V_123 ;
}
V_65 -> V_167 = * V_167 ;
}
if ( V_65 -> V_167 . V_181 ) {
V_123 = F_56 ( V_65 -> V_167 . V_181 ,
V_189 , L_22 ) ;
if ( V_123 < 0 ) {
F_12 ( & V_165 -> V_2 ,
L_23 ,
V_65 -> V_167 . V_181 , V_123 ) ;
return V_123 ;
}
F_57 ( V_65 -> V_167 . V_181 , 0 ) ;
F_57 ( V_65 -> V_167 . V_181 , 1 ) ;
}
F_58 ( V_165 , V_65 ) ;
for ( V_52 = 0 ; V_52 < F_4 ( V_65 -> V_131 ) ; V_52 ++ )
V_65 -> V_131 [ V_52 ] . V_190 = V_191 [ V_52 ] ;
V_123 = F_59 ( & V_165 -> V_2 ,
F_4 ( V_65 -> V_131 ) ,
V_65 -> V_131 ) ;
if ( V_123 != 0 ) {
F_12 ( & V_165 -> V_2 ,
L_24 , V_123 ) ;
return V_123 ;
}
V_123 = F_17 ( F_4 ( V_65 -> V_131 ) ,
V_65 -> V_131 ) ;
if ( V_123 != 0 ) {
F_12 ( & V_165 -> V_2 ,
L_25 , V_123 ) ;
return V_123 ;
}
F_60 ( V_65 -> V_130 , true ) ;
V_123 = F_61 ( V_65 -> V_130 , V_4 , & V_3 ) ;
V_183 = V_3 & V_192 ;
if ( V_183 != V_193 ) {
F_12 ( & V_165 -> V_2 ,
L_26 ,
V_183 , V_193 ) ;
goto V_194;
}
V_184 = V_3 & V_195 ;
V_185 = V_3 & V_196 ;
F_62 ( & V_165 -> V_2 , L_27 ) ;
F_62 ( & V_165 -> V_2 , L_28 ,
V_184 , V_185 ) ;
F_60 ( V_65 -> V_130 , false ) ;
if ( V_65 -> V_167 . V_172 )
F_63 ( V_65 -> V_130 , V_29 ,
V_197 , 1 ) ;
if ( V_65 -> V_167 . V_174 )
F_63 ( V_65 -> V_130 , V_29 ,
V_198 , 1 ) ;
if ( V_65 -> V_167 . V_173 )
F_63 ( V_65 -> V_130 , V_29 ,
V_199 , 1 ) ;
if ( V_65 -> V_167 . V_175 )
F_63 ( V_65 -> V_130 , V_29 ,
V_200 , 1 ) ;
if ( V_65 -> V_167 . V_176 )
F_63 ( V_65 -> V_130 , V_32 ,
V_201 ,
V_65 -> V_167 . V_176 ) ;
if ( V_65 -> V_167 . V_177 )
F_63 ( V_65 -> V_130 , V_11 ,
V_202 ,
V_65 -> V_167 . V_177 ) ;
if ( V_65 -> V_167 . V_180 )
F_63 ( V_65 -> V_130 , V_30 ,
V_203 ,
V_65 -> V_167 . V_180 ) ;
if ( V_65 -> V_167 . V_179 )
F_63 ( V_65 -> V_130 , V_30 ,
V_204 ,
V_65 -> V_167 . V_179 ) ;
if ( V_65 -> V_167 . V_178 )
F_63 ( V_65 -> V_130 , V_11 ,
V_205 ,
V_65 -> V_167 . V_178 ) ;
V_123 = F_64 ( & V_165 -> V_2 ,
& V_206 , & V_207 , 1 ) ;
if ( V_123 < 0 )
return V_123 ;
return 0 ;
V_194:
F_18 ( F_4 ( V_65 -> V_131 ) ,
V_65 -> V_131 ) ;
return V_123 ;
}
static int F_65 ( struct V_165 * V_208 )
{
struct V_64 * V_65 = F_66 ( V_208 ) ;
F_67 ( & V_208 -> V_2 ) ;
F_18 ( F_4 ( V_65 -> V_131 ) ,
V_65 -> V_131 ) ;
return 0 ;
}
