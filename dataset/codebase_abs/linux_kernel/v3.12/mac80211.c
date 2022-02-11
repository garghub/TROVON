static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
memset ( V_2 -> V_4 , 0 , sizeof( V_2 -> V_4 ) ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_2 -> V_4 [ V_3 ] . V_6 = V_3 ;
V_2 -> V_4 [ V_3 ] . V_7 = 0 ;
}
}
int F_2 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_10 , V_11 , V_3 ;
V_9 -> V_12 = V_13 |
V_14 |
V_15 |
V_16 |
V_17 |
V_18 |
V_19 |
V_20 |
V_21 |
V_22 |
V_23 |
V_24 |
V_25 ;
V_9 -> V_26 = V_27 ;
V_9 -> V_28 = V_29 ;
V_9 -> V_30 = L_1 ;
if ( V_2 -> V_31 -> V_32 . V_12 & V_33 &&
! V_34 . V_35 )
V_9 -> V_12 |= V_36 ;
V_9 -> V_37 = sizeof( struct V_38 ) ;
V_9 -> V_39 = sizeof( struct V_40 ) ;
V_9 -> V_41 = sizeof( V_42 ) ;
V_9 -> V_43 -> V_44 = F_3 ( V_45 ) |
F_3 ( V_46 ) |
F_3 ( V_47 ) |
F_3 ( V_48 ) |
F_3 ( V_49 ) ;
V_9 -> V_43 -> V_12 |= V_50 |
V_51 |
V_52 ;
V_9 -> V_43 -> V_53 = V_54 ;
V_9 -> V_43 -> V_55 =
F_4 ( V_54 ) ;
V_9 -> V_43 -> V_56 = 10000 ;
V_9 -> V_57 = V_58 ;
V_9 -> V_59 = V_60 ;
V_9 -> V_61 = V_62 ;
memcpy ( V_2 -> V_63 [ 0 ] . V_64 , V_2 -> V_65 -> V_66 , V_67 ) ;
V_9 -> V_43 -> V_63 = V_2 -> V_63 ;
V_9 -> V_43 -> V_68 = 1 ;
V_10 = ( V_2 -> V_65 -> V_69 > 1 ) ?
F_5 ( V_70 , V_2 -> V_65 -> V_69 ) : 1 ;
for ( V_3 = 1 ; V_3 < V_10 ; V_3 ++ ) {
memcpy ( V_2 -> V_63 [ V_3 ] . V_64 , V_2 -> V_63 [ V_3 - 1 ] . V_64 ,
V_67 ) ;
V_2 -> V_63 [ V_3 ] . V_64 [ 5 ] ++ ;
V_9 -> V_43 -> V_68 ++ ;
}
F_1 ( V_2 ) ;
V_9 -> V_43 -> V_71 =
V_2 -> V_31 -> V_32 . V_72 - 24 - 34 ;
V_9 -> V_43 -> V_73 = V_74 ;
if ( V_2 -> V_65 -> V_75 [ V_76 ] . V_77 )
V_9 -> V_43 -> V_75 [ V_76 ] =
& V_2 -> V_65 -> V_75 [ V_76 ] ;
if ( V_2 -> V_65 -> V_75 [ V_78 ] . V_77 )
V_9 -> V_43 -> V_75 [ V_78 ] =
& V_2 -> V_65 -> V_75 [ V_78 ] ;
V_9 -> V_43 -> V_79 = V_2 -> V_80 -> V_81 ;
if ( V_82 . V_83 != V_84 )
V_9 -> V_43 -> V_12 |= V_85 ;
else
V_9 -> V_43 -> V_12 &= ~ V_85 ;
V_9 -> V_43 -> V_86 |= V_87 |
V_88 ;
V_2 -> V_89 = V_90 ;
#ifdef F_6
if ( V_2 -> V_31 -> V_91 [ V_92 ] . V_93 [ 0 ] . V_94 &&
V_2 -> V_80 -> V_95 -> V_96 &&
V_2 -> V_80 -> V_95 -> V_97 &&
F_7 ( V_2 -> V_80 -> V_98 ) ) {
V_2 -> V_99 . V_12 = V_100 |
V_101 |
V_102 |
V_103 ;
if ( ! V_34 . V_35 )
V_2 -> V_99 . V_12 |= V_104 |
V_105 |
V_106 ;
V_2 -> V_99 . V_107 = V_108 ;
V_2 -> V_99 . V_109 = V_110 ;
V_2 -> V_99 . V_111 = V_112 ;
V_2 -> V_99 . V_113 = & V_114 ;
V_9 -> V_43 -> V_99 = & V_2 -> V_99 ;
}
#endif
V_11 = F_8 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_9 ( V_2 -> V_9 ) ;
if ( V_11 )
F_10 ( V_2 ) ;
return V_11 ;
}
static void F_11 ( struct V_8 * V_9 ,
struct V_115 * V_116 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
if ( F_13 ( V_2 ) ) {
F_14 ( V_2 , L_2 ) ;
goto V_119;
}
if ( F_15 ( V_118 ) -> V_120 == V_29 &&
! F_16 ( V_121 , & V_2 -> V_122 ) )
goto V_119;
if ( V_116 -> V_123 ) {
if ( F_17 ( V_2 , V_118 , V_116 -> V_123 ) )
goto V_119;
return;
}
if ( F_18 ( V_2 , V_118 ) )
goto V_119;
return;
V_119:
F_19 ( V_9 , V_118 ) ;
}
static int F_20 ( struct V_8 * V_9 ,
struct V_124 * V_125 ,
enum V_126 V_127 ,
struct V_128 * V_123 , V_42 V_129 ,
V_42 * V_130 , T_1 V_131 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
int V_11 ;
F_21 ( V_2 , L_3 ,
V_123 -> V_64 , V_129 , V_127 ) ;
if ( ! ( V_2 -> V_65 -> V_132 ) )
return - V_133 ;
F_22 ( & V_2 -> V_134 ) ;
switch ( V_127 ) {
case V_135 :
if ( V_34 . V_136 & V_137 ) {
V_11 = - V_138 ;
break;
}
V_11 = F_23 ( V_2 , V_123 , V_129 , * V_130 , true ) ;
break;
case V_139 :
V_11 = F_23 ( V_2 , V_123 , V_129 , 0 , false ) ;
break;
case V_140 :
if ( V_34 . V_136 & V_141 ) {
V_11 = - V_138 ;
break;
}
V_11 = F_24 ( V_2 , V_125 , V_123 , V_129 , V_130 ) ;
break;
case V_142 :
V_11 = F_25 ( V_2 , V_125 , V_123 , V_129 ) ;
break;
case V_143 :
case V_144 :
V_11 = F_26 ( V_2 , V_125 , V_123 , V_129 ) ;
break;
case V_145 :
V_11 = F_27 ( V_2 , V_125 , V_123 , V_129 , V_131 ) ;
break;
default:
F_28 ( 1 ) ;
V_11 = - V_138 ;
break;
}
F_29 ( & V_2 -> V_134 ) ;
return V_11 ;
}
static void F_30 ( void * V_146 , T_1 * V_147 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = V_146 ;
struct V_40 * V_148 = F_31 ( V_125 ) ;
V_148 -> V_149 = false ;
V_148 -> V_150 = V_151 ;
V_148 -> V_152 ++ ;
F_32 ( & V_2 -> V_153 ) ;
F_33 ( V_2 , & V_148 -> V_154 ) ;
F_34 ( & V_2 -> V_153 ) ;
V_148 -> V_155 = NULL ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_36 ( V_2 -> V_80 ) ;
F_37 ( V_2 -> V_80 , false ) ;
V_2 -> V_156 = V_157 ;
F_38 ( V_2 -> V_9 ) ;
F_39 (
V_2 -> V_9 , V_158 ,
F_30 , V_2 ) ;
V_2 -> V_159 = NULL ;
F_1 ( V_2 ) ;
memset ( V_2 -> V_160 , 0 , sizeof( V_2 -> V_160 ) ) ;
memset ( V_2 -> V_161 , 0 , sizeof( V_2 -> V_161 ) ) ;
F_40 ( V_2 -> V_9 ) ;
V_2 -> V_162 = 0 ;
V_2 -> V_163 = 0 ;
}
static int F_41 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
int V_11 ;
F_22 ( & V_2 -> V_134 ) ;
if ( F_16 ( V_164 , & V_2 -> V_122 ) )
F_35 ( V_2 ) ;
V_11 = F_42 ( V_2 ) ;
F_29 ( & V_2 -> V_134 ) ;
return V_11 ;
}
static void F_43 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
int V_11 ;
F_22 ( & V_2 -> V_134 ) ;
F_44 ( V_164 , & V_2 -> V_122 ) ;
V_11 = F_45 ( V_2 , NULL ) ;
if ( V_11 )
F_46 ( V_2 , L_4 ,
V_11 ) ;
F_29 ( & V_2 -> V_134 ) ;
}
static void F_47 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_48 ( & V_2 -> V_165 ) ;
F_22 ( & V_2 -> V_134 ) ;
F_49 ( & V_2 -> V_166 ) ;
F_36 ( V_2 -> V_80 ) ;
F_37 ( V_2 -> V_80 , false ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 , & V_2 -> V_167 ) ;
F_29 ( & V_2 -> V_134 ) ;
F_49 ( & V_2 -> V_165 ) ;
}
static void F_52 ( void * V_146 , T_1 * V_147 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = V_146 ;
int V_11 ;
V_11 = F_53 ( V_2 , V_125 ) ;
if ( V_11 )
F_46 ( V_2 , L_5 ) ;
}
static void F_54 ( void * V_146 , T_1 * V_147 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = V_146 ;
F_55 ( V_2 , V_125 ) ;
}
static struct V_168 * F_56 ( struct V_1 * V_2 )
{
V_42 V_3 ;
F_57 ( & V_2 -> V_134 ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ )
if ( ! V_2 -> V_4 [ V_3 ] . V_7 )
return & V_2 -> V_4 [ V_3 ] ;
F_46 ( V_2 , L_6 ) ;
return NULL ;
}
static int F_58 ( struct V_8 * V_9 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_40 * V_148 = F_31 ( V_125 ) ;
int V_11 ;
F_22 ( & V_2 -> V_134 ) ;
V_11 = F_59 ( V_2 , V_125 ) ;
if ( V_11 )
goto V_169;
if ( V_125 -> type != V_49 )
V_2 -> V_162 ++ ;
if ( V_2 -> V_162 > 1 ) {
F_60 ( V_2 ,
L_7 ) ;
F_39 (
V_2 -> V_9 ,
V_170 ,
F_52 , V_2 ) ;
}
if ( V_125 -> type == V_47 ) {
T_2 V_171 = F_61 ( V_2 , V_125 ) ;
V_11 = F_62 ( V_2 , & V_148 -> V_172 ,
V_171 ) ;
if ( V_11 ) {
F_46 ( V_2 , L_8 ) ;
goto V_173;
}
F_63 ( V_2 , V_125 ) ;
goto V_169;
}
V_11 = F_64 ( V_2 , V_125 ) ;
if ( V_11 )
goto V_173;
F_55 ( V_2 , V_125 ) ;
V_11 = F_65 ( V_2 , V_125 ) ;
if ( V_11 )
goto V_174;
if ( ! V_2 -> V_175 &&
V_125 -> type == V_45 && ! V_125 -> V_176 &&
V_2 -> V_31 -> V_32 . V_12 & V_177 ) {
V_2 -> V_175 = V_148 ;
V_125 -> V_178 |= V_179 |
V_180 ;
}
if ( V_125 -> type == V_49 ) {
V_148 -> V_155 = F_56 ( V_2 ) ;
if ( ! V_148 -> V_155 ) {
V_11 = - V_181 ;
goto V_182;
}
F_66 ( V_2 , V_148 -> V_155 ) ;
V_11 = F_67 ( V_2 , V_125 ) ;
if ( V_11 )
goto V_183;
V_11 = F_68 ( V_2 , V_125 , & V_148 -> V_172 ) ;
if ( V_11 )
goto V_184;
V_2 -> V_159 = V_125 ;
}
F_63 ( V_2 , V_125 ) ;
goto V_169;
V_184:
F_69 ( V_2 , V_125 ) ;
V_183:
F_70 ( V_2 , V_148 -> V_155 ) ;
V_182:
if ( V_2 -> V_175 == V_148 ) {
V_2 -> V_175 = NULL ;
V_125 -> V_178 &= ~ ( V_179 |
V_180 ) ;
}
V_174:
V_148 -> V_155 = NULL ;
F_71 ( V_2 , V_125 ) ;
V_173:
if ( V_125 -> type != V_49 )
V_2 -> V_162 -- ;
F_72 (
V_2 -> V_9 , V_170 ,
F_54 , V_2 ) ;
F_73 ( V_2 , V_125 ) ;
V_169:
F_29 ( & V_2 -> V_134 ) ;
return V_11 ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
T_2 V_185 = 0 , V_186 ;
for ( V_186 = 0 ; V_186 < V_187 ; V_186 ++ )
if ( V_125 -> V_120 [ V_186 ] != V_188 )
V_185 |= F_3 ( V_125 -> V_120 [ V_186 ] ) ;
if ( V_125 -> V_189 != V_188 )
V_185 |= F_3 ( V_125 -> V_189 ) ;
if ( V_185 ) {
F_22 ( & V_2 -> V_134 ) ;
F_75 ( V_2 , V_185 , true ) ;
F_29 ( & V_2 -> V_134 ) ;
}
if ( V_125 -> type == V_49 ) {
F_48 ( & V_2 -> V_166 ) ;
} else {
F_48 ( & V_2 -> V_190 ) ;
}
}
static void F_76 ( struct V_8 * V_9 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_40 * V_148 = F_31 ( V_125 ) ;
F_74 ( V_2 , V_125 ) ;
F_22 ( & V_2 -> V_134 ) ;
if ( V_2 -> V_175 == V_148 ) {
V_2 -> V_175 = NULL ;
V_125 -> V_178 &= ~ ( V_179 |
V_180 ) ;
}
F_77 ( V_2 , V_125 ) ;
if ( V_125 -> type == V_47 ) {
F_51 ( V_2 , & V_148 -> V_172 ) ;
goto V_173;
}
if ( V_125 -> type == V_49 ) {
V_2 -> V_159 = NULL ;
F_78 ( V_2 , & V_148 -> V_172 ) ;
F_69 ( V_2 , V_125 ) ;
F_70 ( V_2 , V_148 -> V_155 ) ;
V_148 -> V_155 = NULL ;
}
if ( V_2 -> V_162 && V_125 -> type != V_49 )
V_2 -> V_162 -- ;
F_60 ( V_2 , L_9 ,
V_2 -> V_162 ) ;
if ( V_2 -> V_162 == 1 ) {
F_72 (
V_2 -> V_9 , V_170 ,
F_54 , V_2 ) ;
}
F_71 ( V_2 , V_125 ) ;
V_173:
F_73 ( V_2 , V_125 ) ;
F_29 ( & V_2 -> V_134 ) ;
}
static int F_79 ( struct V_1 * V_2 , struct V_124 * V_125 ,
T_3 V_191 )
{
struct V_192 V_193 = {
. V_194 = F_31 ( V_125 ) -> V_6 ,
. V_195 = F_80 ( V_191 ) ,
} ;
return F_81 ( V_2 , V_196 , V_197 ,
sizeof( V_193 ) ,
& V_193 ) ;
}
static int F_82 ( struct V_8 * V_9 , T_2 V_198 )
{
return 0 ;
}
static void F_83 ( struct V_8 * V_9 ,
unsigned int V_199 ,
unsigned int * V_200 ,
T_4 V_201 )
{
* V_200 = 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
struct V_202 V_203 = {
. V_204 = 1 ,
} ;
memcpy ( V_203 . V_205 , V_125 -> V_206 . V_205 , V_67 ) ;
return F_81 ( V_2 , V_207 , V_197 ,
sizeof( V_203 ) ,
& V_203 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
struct V_208 * V_206 ,
T_2 V_209 )
{
struct V_40 * V_148 = F_31 ( V_125 ) ;
int V_11 ;
V_11 = F_86 ( V_2 , V_125 ) ;
if ( V_11 )
F_46 ( V_2 , L_10 , V_125 -> V_64 ) ;
if ( V_209 & V_210 ) {
if ( V_206 -> V_211 ) {
V_11 = F_45 ( V_2 , V_125 ) ;
if ( V_11 ) {
F_46 ( V_2 , L_11 ) ;
return;
}
F_84 ( V_2 , V_125 ) ;
} else if ( V_148 -> V_150 != V_151 ) {
V_11 = F_87 ( V_2 , V_125 , V_148 -> V_150 ) ;
if ( V_11 )
F_46 ( V_2 , L_12 ) ;
V_148 -> V_150 = V_151 ;
V_11 = F_45 ( V_2 , NULL ) ;
if ( V_11 )
F_46 ( V_2 , L_11 ) ;
}
V_148 -> V_212 . V_213 = 0 ;
if ( ! ( V_2 -> V_31 -> V_32 . V_12 & V_214 ) ) {
V_11 = F_55 ( V_2 , V_125 ) ;
if ( V_11 )
F_46 ( V_2 , L_13 ) ;
}
F_88 ( V_2 , V_125 ) ;
} else if ( V_209 & V_215 ) {
F_89 ( V_2 , V_148 ,
& V_148 -> V_154 ) ;
} else if ( V_209 & ( V_216 | V_217 ) ) {
V_11 = F_55 ( V_2 , V_125 ) ;
if ( V_11 )
F_46 ( V_2 , L_13 ) ;
}
if ( V_209 & V_218 ) {
F_90 ( V_2 , L_14 ,
V_206 -> V_219 ) ;
F_79 ( V_2 , V_125 , V_206 -> V_219 ) ;
}
if ( V_209 & V_220 ) {
F_60 ( V_2 , L_15 ) ;
V_148 -> V_212 . V_221 = 0 ;
V_11 = F_91 ( V_2 , V_125 ) ;
if ( V_11 )
F_46 ( V_2 , L_16 ) ;
}
}
static int F_92 ( struct V_8 * V_9 , struct V_124 * V_125 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_40 * V_148 = F_31 ( V_125 ) ;
int V_11 ;
F_22 ( & V_2 -> V_134 ) ;
V_11 = F_93 ( V_2 , V_125 ) ;
if ( V_11 )
goto V_169;
V_11 = F_64 ( V_2 , V_125 ) ;
if ( V_11 )
goto V_169;
V_11 = F_67 ( V_2 , V_125 ) ;
if ( V_11 )
goto V_222;
V_148 -> V_223 = true ;
V_11 = F_94 ( V_2 , V_125 , & V_148 -> V_172 ) ;
if ( V_11 )
goto V_184;
V_11 = F_45 ( V_2 , V_125 ) ;
if ( V_11 )
goto V_224;
if ( V_125 -> V_176 && V_2 -> V_159 )
F_86 ( V_2 , V_2 -> V_159 ) ;
F_29 ( & V_2 -> V_134 ) ;
return 0 ;
V_224:
F_95 ( V_2 , & V_148 -> V_172 ) ;
V_184:
F_69 ( V_2 , V_125 ) ;
V_222:
F_71 ( V_2 , V_125 ) ;
V_169:
F_29 ( & V_2 -> V_134 ) ;
return V_11 ;
}
static void F_96 ( struct V_8 * V_9 , struct V_124 * V_125 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_40 * V_148 = F_31 ( V_125 ) ;
F_74 ( V_2 , V_125 ) ;
F_22 ( & V_2 -> V_134 ) ;
V_148 -> V_223 = false ;
if ( V_125 -> V_176 && V_2 -> V_159 )
F_86 ( V_2 , V_2 -> V_159 ) ;
F_45 ( V_2 , NULL ) ;
F_95 ( V_2 , & V_148 -> V_172 ) ;
F_69 ( V_2 , V_125 ) ;
F_71 ( V_2 , V_125 ) ;
F_29 ( & V_2 -> V_134 ) ;
}
static void F_97 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
struct V_208 * V_206 ,
T_2 V_209 )
{
if ( V_209 & V_225 ) {
if ( F_93 ( V_2 , V_125 ) )
F_98 ( V_2 , L_17 ) ;
}
}
static void F_99 ( struct V_8 * V_9 ,
struct V_124 * V_125 ,
struct V_208 * V_206 ,
T_2 V_209 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_22 ( & V_2 -> V_134 ) ;
switch ( V_125 -> type ) {
case V_45 :
F_85 ( V_2 , V_125 , V_206 , V_209 ) ;
break;
case V_47 :
F_97 ( V_2 , V_125 , V_206 , V_209 ) ;
break;
default:
F_28 ( 1 ) ;
}
F_29 ( & V_2 -> V_134 ) ;
}
static int F_100 ( struct V_8 * V_9 ,
struct V_124 * V_125 ,
struct V_226 * V_227 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
int V_11 ;
if ( V_227 -> V_77 == 0 || V_227 -> V_77 > V_228 )
return - V_138 ;
F_22 ( & V_2 -> V_134 ) ;
if ( V_2 -> V_156 == V_157 )
V_11 = F_101 ( V_2 , V_125 , V_227 ) ;
else
V_11 = - V_229 ;
F_29 ( & V_2 -> V_134 ) ;
return V_11 ;
}
static void F_102 ( struct V_8 * V_9 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_22 ( & V_2 -> V_134 ) ;
F_103 ( V_2 ) ;
F_29 ( & V_2 -> V_134 ) ;
}
static void
F_104 ( struct V_8 * V_9 ,
struct V_128 * V_123 , V_42 V_129 ,
int V_230 ,
enum V_231 V_232 ,
bool V_233 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_105 ( V_2 , V_123 , V_232 , V_230 ) ;
}
static void F_106 ( struct V_8 * V_9 ,
struct V_124 * V_125 ,
enum V_234 V_235 ,
struct V_128 * V_123 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_38 * V_236 = ( void * ) V_123 -> V_237 ;
switch ( V_235 ) {
case V_238 :
if ( F_107 ( & V_2 -> V_239 [ V_236 -> V_240 ] ) > 0 )
F_108 ( V_9 , V_123 , true ) ;
break;
case V_241 :
if ( F_109 ( V_236 -> V_240 == V_151 ) )
break;
F_110 ( V_2 , V_123 ) ;
break;
default:
break;
}
}
static int F_111 ( struct V_8 * V_9 ,
struct V_124 * V_125 ,
struct V_128 * V_123 ,
enum V_242 V_243 ,
enum V_242 V_244 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_40 * V_148 = F_31 ( V_125 ) ;
int V_11 ;
F_60 ( V_2 , L_18 ,
V_123 -> V_64 , V_243 , V_244 ) ;
if ( F_28 ( ! V_148 -> V_155 ) )
return - V_138 ;
F_48 ( & V_2 -> V_190 ) ;
F_22 ( & V_2 -> V_134 ) ;
if ( V_243 == V_245 &&
V_244 == V_246 ) {
if ( V_125 -> type == V_45 &&
V_125 -> V_206 . V_247 < 16 ) {
F_46 ( V_2 ,
L_19 ,
V_123 -> V_64 , V_125 -> V_206 . V_247 ) ;
V_11 = - V_138 ;
goto V_169;
}
V_11 = F_112 ( V_2 , V_125 , V_123 ) ;
} else if ( V_243 == V_246 &&
V_244 == V_248 ) {
V_11 = 0 ;
} else if ( V_243 == V_248 &&
V_244 == V_249 ) {
V_11 = F_113 ( V_2 , V_125 , V_123 ) ;
if ( V_11 == 0 )
F_114 ( V_2 , V_123 ,
V_148 -> V_155 -> V_250 -> V_251 ) ;
} else if ( V_243 == V_249 &&
V_244 == V_252 ) {
F_109 ( F_115 ( V_2 , V_125 ) ) ;
V_11 = 0 ;
} else if ( V_243 == V_252 &&
V_244 == V_249 ) {
F_109 ( F_65 ( V_2 , V_125 ) ) ;
V_11 = 0 ;
} else if ( V_243 == V_249 &&
V_244 == V_248 ) {
V_11 = 0 ;
} else if ( V_243 == V_248 &&
V_244 == V_246 ) {
V_11 = 0 ;
} else if ( V_243 == V_246 &&
V_244 == V_245 ) {
V_11 = F_116 ( V_2 , V_125 , V_123 ) ;
} else {
V_11 = - V_253 ;
}
V_169:
F_29 ( & V_2 -> V_134 ) ;
return V_11 ;
}
static int F_117 ( struct V_8 * V_9 , T_2 V_254 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
V_2 -> V_89 = V_254 ;
return 0 ;
}
static int F_118 ( struct V_8 * V_9 ,
struct V_124 * V_125 , V_42 V_186 ,
const struct V_255 * V_256 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_40 * V_148 = F_31 ( V_125 ) ;
V_148 -> V_257 [ V_186 ] = * V_256 ;
if ( V_125 -> type == V_49 ) {
int V_11 ;
F_22 ( & V_2 -> V_134 ) ;
V_11 = F_86 ( V_2 , V_125 ) ;
F_29 ( & V_2 -> V_134 ) ;
return V_11 ;
}
return 0 ;
}
static void F_119 ( struct V_8 * V_9 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
T_2 V_258 = F_5 ( V_259 ,
200 + V_125 -> V_206 . V_247 ) ;
T_2 V_260 = F_5 ( V_261 ,
100 + V_125 -> V_206 . V_247 ) ;
if ( F_28 ( V_125 -> V_206 . V_211 ) )
return;
F_22 ( & V_2 -> V_134 ) ;
F_120 ( V_2 , V_125 , V_258 , V_260 ) ;
F_29 ( & V_2 -> V_134 ) ;
}
static int F_121 ( struct V_8 * V_9 ,
enum V_262 V_235 ,
struct V_124 * V_125 ,
struct V_128 * V_123 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
int V_11 ;
if ( V_34 . V_35 ) {
F_60 ( V_2 , L_20 ) ;
return - V_265 ;
}
switch ( V_264 -> V_266 ) {
case V_267 :
V_264 -> V_12 |= V_268 ;
case V_269 :
V_264 -> V_12 |= V_270 ;
break;
case V_271 :
F_28 ( ! ( V_9 -> V_12 & V_36 ) ) ;
break;
case V_272 :
case V_273 :
return 0 ;
default:
return - V_265 ;
}
F_22 ( & V_2 -> V_134 ) ;
switch ( V_235 ) {
case V_274 :
if ( V_125 -> type == V_47 && ! V_123 ) {
V_11 = 0 ;
V_264 -> V_275 = V_276 ;
break;
}
F_60 ( V_2 , L_21 ) ;
V_11 = F_122 ( V_2 , V_125 , V_123 , V_264 , false ) ;
if ( V_11 ) {
F_98 ( V_2 , L_22 ) ;
V_264 -> V_275 = V_276 ;
V_11 = 0 ;
}
break;
case V_277 :
if ( V_264 -> V_275 == V_276 ) {
V_11 = 0 ;
break;
}
F_60 ( V_2 , L_23 ) ;
V_11 = F_123 ( V_2 , V_125 , V_123 , V_264 ) ;
break;
default:
V_11 = - V_138 ;
}
F_29 ( & V_2 -> V_134 ) ;
return V_11 ;
}
static void F_124 ( struct V_8 * V_9 ,
struct V_124 * V_125 ,
struct V_263 * V_278 ,
struct V_128 * V_123 ,
T_2 V_279 , V_42 * V_280 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_125 ( V_2 , V_125 , V_278 , V_123 , V_279 , V_280 ) ;
}
static int F_126 ( struct V_8 * V_9 ,
struct V_124 * V_125 ,
struct V_281 * V_250 ,
int V_258 ,
enum V_282 type )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_40 * V_148 = F_31 ( V_125 ) ;
struct V_283 V_284 ;
struct V_168 * V_155 ;
int V_11 , V_3 ;
F_60 ( V_2 , L_24 , V_250 -> V_285 ,
V_258 , type ) ;
if ( V_125 -> type != V_49 ) {
F_46 ( V_2 , L_25 , V_125 -> type ) ;
return - V_138 ;
}
F_22 ( & V_2 -> V_134 ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_155 = & V_2 -> V_4 [ V_3 ] ;
if ( V_155 -> V_7 == 0 || V_148 -> V_155 == V_155 )
continue;
if ( V_155 -> V_7 && V_250 == V_155 -> V_250 ) {
V_11 = F_69 ( V_2 , V_125 ) ;
if ( F_127 ( V_11 , L_26 ) )
goto V_169;
F_70 ( V_2 , V_148 -> V_155 ) ;
V_148 -> V_155 = V_155 ;
V_11 = F_67 ( V_2 , V_125 ) ;
if ( F_127 ( V_11 , L_27 ) )
goto V_169;
F_66 ( V_2 , V_148 -> V_155 ) ;
goto V_286;
}
}
if ( V_250 == V_148 -> V_155 -> V_250 )
goto V_286;
F_128 ( & V_284 , V_250 , V_287 ) ;
if ( V_148 -> V_155 -> V_7 == 1 ) {
V_11 = F_129 ( V_2 , V_148 -> V_155 ,
& V_284 , 1 , 1 ) ;
if ( V_11 )
goto V_169;
} else {
V_155 = F_56 ( V_2 ) ;
if ( ! V_155 ) {
V_11 = - V_181 ;
goto V_169;
}
V_11 = F_129 ( V_2 , V_155 , & V_284 ,
1 , 1 ) ;
if ( V_11 ) {
F_46 ( V_2 , L_28 ) ;
goto V_169;
}
V_11 = F_69 ( V_2 , V_125 ) ;
if ( F_127 ( V_11 , L_26 ) )
goto V_169;
F_70 ( V_2 , V_148 -> V_155 ) ;
V_148 -> V_155 = V_155 ;
V_11 = F_67 ( V_2 , V_125 ) ;
if ( F_127 ( V_11 , L_27 ) )
goto V_169;
F_66 ( V_2 , V_148 -> V_155 ) ;
}
V_286:
V_11 = F_130 ( V_2 , V_125 , V_258 , type ) ;
V_169:
F_29 ( & V_2 -> V_134 ) ;
F_60 ( V_2 , L_29 ) ;
return V_11 ;
}
static int F_131 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_60 ( V_2 , L_30 ) ;
F_22 ( & V_2 -> V_134 ) ;
F_132 ( V_2 ) ;
F_29 ( & V_2 -> V_134 ) ;
F_60 ( V_2 , L_29 ) ;
return 0 ;
}
static int F_133 ( struct V_8 * V_9 ,
struct V_288 * V_289 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
V_42 * V_290 = ( V_42 * ) V_289 -> V_237 ;
struct V_168 * V_155 ;
int V_11 ;
F_60 ( V_2 , L_31 ) ;
F_22 ( & V_2 -> V_134 ) ;
V_155 = F_56 ( V_2 ) ;
if ( ! V_155 ) {
V_11 = - V_181 ;
goto V_291;
}
V_11 = F_129 ( V_2 , V_155 , & V_289 -> V_292 ,
V_289 -> V_293 ,
V_289 -> V_294 ) ;
if ( V_11 ) {
F_46 ( V_2 , L_32 ) ;
goto V_291;
}
F_66 ( V_2 , V_155 ) ;
* V_290 = V_155 -> V_6 ;
V_291:
F_29 ( & V_2 -> V_134 ) ;
return V_11 ;
}
static void F_134 ( struct V_8 * V_9 ,
struct V_288 * V_289 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
V_42 * V_290 = ( V_42 * ) V_289 -> V_237 ;
struct V_168 * V_155 = & V_2 -> V_4 [ * V_290 ] ;
F_22 ( & V_2 -> V_134 ) ;
F_70 ( V_2 , V_155 ) ;
F_29 ( & V_2 -> V_134 ) ;
}
static void F_135 ( struct V_8 * V_9 ,
struct V_288 * V_289 ,
T_2 V_198 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
V_42 * V_290 = ( V_42 * ) V_289 -> V_237 ;
struct V_168 * V_155 = & V_2 -> V_4 [ * V_290 ] ;
if ( F_136 ( ( V_155 -> V_7 > 1 ) &&
( V_198 & ~ ( V_295 |
V_296 |
V_297 ) ) ,
L_33 ,
V_155 -> V_7 , V_198 ) )
return;
F_22 ( & V_2 -> V_134 ) ;
F_129 ( V_2 , V_155 , & V_289 -> V_292 ,
V_289 -> V_293 ,
V_289 -> V_294 ) ;
F_29 ( & V_2 -> V_134 ) ;
}
static int F_137 ( struct V_8 * V_9 ,
struct V_124 * V_125 ,
struct V_288 * V_289 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
V_42 * V_290 = ( V_42 * ) V_289 -> V_237 ;
struct V_168 * V_155 = & V_2 -> V_4 [ * V_290 ] ;
struct V_40 * V_148 = F_31 ( V_125 ) ;
int V_11 ;
F_22 ( & V_2 -> V_134 ) ;
V_148 -> V_155 = V_155 ;
switch ( V_125 -> type ) {
case V_47 :
V_11 = 0 ;
goto V_169;
case V_45 :
case V_298 :
case V_299 :
break;
default:
V_11 = - V_138 ;
goto V_169;
}
V_11 = F_67 ( V_2 , V_125 ) ;
if ( V_11 )
goto V_169;
if ( V_125 -> type == V_299 ) {
V_148 -> V_300 = true ;
V_11 = F_45 ( V_2 , V_125 ) ;
if ( V_11 )
goto V_301;
}
goto V_169;
V_301:
F_69 ( V_2 , V_125 ) ;
V_169:
F_29 ( & V_2 -> V_134 ) ;
if ( V_11 )
V_148 -> V_155 = NULL ;
return V_11 ;
}
static void F_138 ( struct V_8 * V_9 ,
struct V_124 * V_125 ,
struct V_288 * V_289 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_40 * V_148 = F_31 ( V_125 ) ;
F_22 ( & V_2 -> V_134 ) ;
F_89 ( V_2 , V_148 , & V_148 -> V_154 ) ;
if ( V_125 -> type == V_47 )
goto V_169;
switch ( V_125 -> type ) {
case V_299 :
V_148 -> V_300 = false ;
F_45 ( V_2 , NULL ) ;
break;
default:
break;
}
F_69 ( V_2 , V_125 ) ;
V_169:
V_148 -> V_155 = NULL ;
F_29 ( & V_2 -> V_134 ) ;
}
static int F_139 ( struct V_8 * V_9 ,
struct V_128 * V_123 ,
bool V_302 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_38 * V_303 = ( void * ) V_123 -> V_237 ;
if ( ! V_303 || ! V_303 -> V_125 ) {
F_46 ( V_2 , L_34 ) ;
return - V_138 ;
}
return F_93 ( V_2 , V_303 -> V_125 ) ;
}
static void F_140 ( struct V_8 * V_9 ,
struct V_124 * V_125 ,
enum V_304 V_305 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_141 ( V_2 , V_125 , V_305 ) ;
}
