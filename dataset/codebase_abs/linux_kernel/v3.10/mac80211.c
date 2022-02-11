int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 , V_6 , V_7 ;
V_4 -> V_8 = V_9 |
V_10 |
V_11 |
V_12 |
V_13 |
V_14 |
V_15 |
V_16 |
V_17 ;
V_4 -> V_18 = V_19 ;
V_4 -> V_20 = V_21 ;
V_4 -> V_22 = L_1 ;
if ( V_2 -> V_23 -> V_24 . V_8 & V_25 &&
! V_26 . V_27 )
V_4 -> V_8 |= V_28 ;
V_4 -> V_29 = sizeof( struct V_30 ) ;
V_4 -> V_31 = sizeof( struct V_32 ) ;
V_4 -> V_33 = sizeof( struct V_34 ) ;
V_4 -> V_35 -> V_36 = F_2 ( V_37 ) |
F_2 ( V_38 ) |
F_2 ( V_39 ) |
F_2 ( V_40 ) |
F_2 ( V_41 ) ;
V_4 -> V_35 -> V_8 |= V_42 |
V_43 |
V_44 ;
V_4 -> V_35 -> V_45 = V_46 ;
V_4 -> V_35 -> V_47 =
F_3 ( V_46 ) ;
V_4 -> V_35 -> V_48 = 10000 ;
V_4 -> V_49 = V_50 ;
memcpy ( V_2 -> V_51 [ 0 ] . V_52 , V_2 -> V_53 -> V_54 , V_55 ) ;
V_4 -> V_35 -> V_51 = V_2 -> V_51 ;
V_4 -> V_35 -> V_56 = 1 ;
V_5 = ( V_2 -> V_53 -> V_57 > 1 ) ?
F_4 ( V_58 , V_2 -> V_53 -> V_57 ) : 1 ;
for ( V_7 = 1 ; V_7 < V_5 ; V_7 ++ ) {
memcpy ( V_2 -> V_51 [ V_7 ] . V_52 , V_2 -> V_51 [ V_7 - 1 ] . V_52 ,
V_55 ) ;
V_2 -> V_51 [ V_7 ] . V_52 [ 5 ] ++ ;
V_4 -> V_35 -> V_56 ++ ;
}
V_4 -> V_35 -> V_59 =
V_2 -> V_23 -> V_24 . V_60 - 24 - 34 ;
V_4 -> V_35 -> V_61 = V_62 ;
if ( V_2 -> V_53 -> V_63 [ V_64 ] . V_65 )
V_4 -> V_35 -> V_63 [ V_64 ] =
& V_2 -> V_53 -> V_63 [ V_64 ] ;
if ( V_2 -> V_53 -> V_63 [ V_66 ] . V_65 )
V_4 -> V_35 -> V_63 [ V_66 ] =
& V_2 -> V_53 -> V_63 [ V_66 ] ;
V_4 -> V_35 -> V_67 = V_2 -> V_68 -> V_69 ;
if ( V_70 . V_71 != V_72 )
V_4 -> V_35 -> V_8 |= V_73 ;
else
V_4 -> V_35 -> V_8 &= ~ V_73 ;
V_4 -> V_35 -> V_74 |= V_75 |
V_76 ;
V_2 -> V_77 = V_78 ;
#ifdef F_5
if ( V_2 -> V_23 -> V_79 [ V_80 ] . V_81 [ 0 ] . V_82 &&
V_2 -> V_68 -> V_83 -> V_84 &&
V_2 -> V_68 -> V_83 -> V_85 &&
F_6 ( V_2 -> V_68 -> V_86 ) ) {
V_4 -> V_35 -> V_87 . V_8 = V_88 |
V_89 |
V_90 |
V_91 ;
if ( ! V_26 . V_27 )
V_4 -> V_35 -> V_87 . V_8 |=
V_92 |
V_93 |
V_94 ;
V_4 -> V_35 -> V_87 . V_95 = V_96 ;
V_4 -> V_35 -> V_87 . V_97 = V_98 ;
V_4 -> V_35 -> V_87 . V_99 = V_100 ;
V_4 -> V_35 -> V_87 . V_101 = & V_102 ;
}
#endif
V_6 = F_7 ( V_2 ) ;
if ( V_6 )
return V_6 ;
return F_8 ( V_2 -> V_4 ) ;
}
static void F_9 ( struct V_3 * V_4 ,
struct V_103 * V_104 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
if ( F_11 ( V_107 , & V_2 -> V_108 ) ) {
F_12 ( V_2 , L_2 ) ;
goto V_109;
}
if ( F_13 ( V_106 ) -> V_110 == V_21 &&
! F_11 ( V_111 , & V_2 -> V_108 ) )
goto V_109;
if ( V_104 -> V_112 ) {
if ( F_14 ( V_2 , V_106 , V_104 -> V_112 ) )
goto V_109;
return;
}
if ( F_15 ( V_2 , V_106 ) )
goto V_109;
return;
V_109:
F_16 ( V_4 , V_106 ) ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_113 * V_114 ,
enum V_115 V_116 ,
struct V_117 * V_112 , T_1 V_118 ,
T_1 * V_119 , T_2 V_120 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
int V_6 ;
F_18 ( V_2 , L_3 ,
V_112 -> V_52 , V_118 , V_116 ) ;
if ( ! ( V_2 -> V_53 -> V_121 ) )
return - V_122 ;
F_19 ( & V_2 -> V_123 ) ;
switch ( V_116 ) {
case V_124 :
if ( V_26 . V_125 & V_126 ) {
V_6 = - V_127 ;
break;
}
V_6 = F_20 ( V_2 , V_112 , V_118 , * V_119 , true ) ;
break;
case V_128 :
V_6 = F_20 ( V_2 , V_112 , V_118 , 0 , false ) ;
break;
case V_129 :
if ( V_26 . V_125 & V_130 ) {
V_6 = - V_127 ;
break;
}
V_6 = F_21 ( V_2 , V_114 , V_112 , V_118 , V_119 ) ;
break;
case V_131 :
V_6 = F_22 ( V_2 , V_114 , V_112 , V_118 ) ;
break;
case V_132 :
case V_133 :
V_6 = F_23 ( V_2 , V_114 , V_112 , V_118 ) ;
break;
case V_134 :
V_6 = F_24 ( V_2 , V_114 , V_112 , V_118 , V_120 ) ;
break;
default:
F_25 ( 1 ) ;
V_6 = - V_127 ;
break;
}
F_26 ( & V_2 -> V_123 ) ;
return V_6 ;
}
static void F_27 ( void * V_135 , T_2 * V_136 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = V_135 ;
struct V_32 * V_137 = F_28 ( V_114 ) ;
V_137 -> V_138 = false ;
V_137 -> V_139 = V_140 ;
V_137 -> V_141 ++ ;
F_29 ( & V_2 -> V_142 ) ;
F_30 ( V_2 , & V_137 -> V_143 ) ;
F_31 ( & V_2 -> V_142 ) ;
if ( V_114 -> type != V_41 )
V_137 -> V_144 = NULL ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_33 ( V_2 -> V_68 ) ;
F_34 ( V_2 -> V_68 , false ) ;
V_2 -> V_145 = V_146 ;
F_35 ( V_2 -> V_4 ) ;
F_36 (
V_2 -> V_4 , V_147 ,
F_27 , V_2 ) ;
memset ( V_2 -> V_148 , 0 , sizeof( V_2 -> V_148 ) ) ;
memset ( V_2 -> V_149 , 0 , sizeof( V_2 -> V_149 ) ) ;
F_37 ( V_2 -> V_4 ) ;
V_2 -> V_150 = 0 ;
}
static int F_38 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
int V_6 ;
F_19 ( & V_2 -> V_123 ) ;
if ( F_11 ( V_151 , & V_2 -> V_108 ) )
F_32 ( V_2 ) ;
V_6 = F_39 ( V_2 ) ;
F_26 ( & V_2 -> V_123 ) ;
return V_6 ;
}
static void F_40 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
int V_6 ;
F_19 ( & V_2 -> V_123 ) ;
F_41 ( V_151 , & V_2 -> V_108 ) ;
V_6 = F_42 ( V_2 , NULL ) ;
if ( V_6 )
F_43 ( V_2 , L_4 ,
V_6 ) ;
F_26 ( & V_2 -> V_123 ) ;
}
static void F_44 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
F_45 ( & V_2 -> V_152 ) ;
F_19 ( & V_2 -> V_123 ) ;
F_46 ( & V_2 -> V_153 ) ;
F_33 ( V_2 -> V_68 ) ;
F_34 ( V_2 -> V_68 , false ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 , & V_2 -> V_154 ) ;
F_26 ( & V_2 -> V_123 ) ;
F_46 ( & V_2 -> V_152 ) ;
}
static void F_49 ( void * V_135 , T_2 * V_136 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = V_135 ;
int V_6 ;
V_6 = F_50 ( V_2 , V_114 ) ;
if ( V_6 )
F_43 ( V_2 , L_5 ) ;
}
static void F_51 ( void * V_135 , T_2 * V_136 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = V_135 ;
F_52 ( V_2 , V_114 ) ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_32 * V_137 = F_28 ( V_114 ) ;
int V_6 ;
F_19 ( & V_2 -> V_123 ) ;
V_6 = F_54 ( V_2 , V_114 ) ;
if ( V_6 )
goto V_155;
if ( V_114 -> type == V_39 ) {
T_3 V_156 = F_55 ( V_2 , V_114 ) ;
V_6 = F_56 ( V_2 , & V_137 -> V_157 ,
V_156 ) ;
if ( V_6 ) {
F_43 ( V_2 , L_6 ) ;
goto V_158;
}
goto V_155;
}
if ( V_114 -> type != V_41 )
V_2 -> V_150 ++ ;
if ( V_2 -> V_150 > 1 ) {
F_57 ( V_2 ,
L_7 ) ;
F_36 (
V_2 -> V_4 ,
V_159 ,
F_49 , V_2 ) ;
}
V_6 = F_58 ( V_2 , V_114 ) ;
if ( V_6 )
goto V_158;
F_52 ( V_2 , V_114 ) ;
if ( V_114 -> type == V_41 ) {
struct V_160 * V_161 ;
struct V_162 V_163 ;
V_137 -> V_144 = & V_2 -> V_164 ;
V_161 = & V_2 -> V_4 -> V_35 -> V_63 [ V_64 ] -> V_165 [ 0 ] ;
F_59 ( & V_163 , V_161 , V_166 ) ;
V_6 = F_60 ( V_2 , V_137 -> V_144 ,
& V_163 , 1 , 1 ) ;
if ( V_6 )
goto V_167;
V_6 = F_61 ( V_2 , V_114 ) ;
if ( V_6 )
goto V_168;
V_6 = F_62 ( V_2 , V_114 , & V_137 -> V_157 ) ;
if ( V_6 )
goto V_169;
V_2 -> V_170 = V_114 ;
}
F_63 ( V_2 , V_114 ) ;
goto V_155;
V_169:
F_64 ( V_2 , V_114 ) ;
V_168:
F_65 ( V_2 , V_137 -> V_144 ) ;
V_167:
V_137 -> V_144 = NULL ;
F_66 ( V_2 , V_114 ) ;
V_158:
if ( V_114 -> type != V_41 )
V_2 -> V_150 -- ;
F_57 ( V_2 , L_8 ,
V_2 -> V_150 ) ;
if ( V_2 -> V_150 == 1 ) {
F_67 (
V_2 -> V_4 , V_159 ,
F_51 , V_2 ) ;
}
F_68 ( V_2 , V_114 ) ;
V_155:
F_26 ( & V_2 -> V_123 ) ;
return V_6 ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_113 * V_114 )
{
T_3 V_171 = 0 , V_172 ;
for ( V_172 = 0 ; V_172 < V_173 ; V_172 ++ )
if ( V_114 -> V_110 [ V_172 ] != V_174 )
V_171 |= F_2 ( V_114 -> V_110 [ V_172 ] ) ;
if ( V_114 -> V_175 != V_174 )
V_171 |= F_2 ( V_114 -> V_175 ) ;
if ( V_171 ) {
F_19 ( & V_2 -> V_123 ) ;
F_70 ( V_2 , V_171 , true ) ;
F_26 ( & V_2 -> V_123 ) ;
}
if ( V_114 -> type == V_41 ) {
F_45 ( & V_2 -> V_153 ) ;
} else {
F_45 ( & V_2 -> V_176 ) ;
}
}
static void F_71 ( struct V_3 * V_4 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_32 * V_137 = F_28 ( V_114 ) ;
F_69 ( V_2 , V_114 ) ;
F_19 ( & V_2 -> V_123 ) ;
F_72 ( V_2 , V_114 ) ;
if ( V_114 -> type == V_39 ) {
F_48 ( V_2 , & V_137 -> V_157 ) ;
goto V_158;
}
if ( V_114 -> type == V_41 ) {
V_2 -> V_170 = NULL ;
F_73 ( V_2 , & V_137 -> V_157 ) ;
F_64 ( V_2 , V_114 ) ;
F_65 ( V_2 , V_137 -> V_144 ) ;
V_137 -> V_144 = NULL ;
}
if ( V_2 -> V_150 && V_114 -> type != V_41 )
V_2 -> V_150 -- ;
F_57 ( V_2 , L_8 ,
V_2 -> V_150 ) ;
if ( V_2 -> V_150 == 1 ) {
F_67 (
V_2 -> V_4 , V_159 ,
F_51 , V_2 ) ;
}
F_66 ( V_2 , V_114 ) ;
V_158:
F_68 ( V_2 , V_114 ) ;
F_26 ( & V_2 -> V_123 ) ;
}
static int F_74 ( struct V_3 * V_4 , T_3 V_177 )
{
return 0 ;
}
static void F_75 ( struct V_3 * V_4 ,
unsigned int V_178 ,
unsigned int * V_179 ,
T_4 V_180 )
{
* V_179 = 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_113 * V_114 )
{
struct V_181 V_182 = {
. V_183 = 1 ,
} ;
memcpy ( V_182 . V_184 , V_114 -> V_185 . V_184 , V_55 ) ;
return F_77 ( V_2 , V_186 , V_187 ,
sizeof( V_182 ) ,
& V_182 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_113 * V_114 ,
struct V_188 * V_185 ,
T_3 V_189 )
{
struct V_32 * V_137 = F_28 ( V_114 ) ;
int V_6 ;
V_6 = F_79 ( V_2 , V_114 ) ;
if ( V_6 )
F_43 ( V_2 , L_9 , V_114 -> V_52 ) ;
if ( V_189 & V_190 ) {
if ( V_185 -> V_191 ) {
V_6 = F_42 ( V_2 , V_114 ) ;
if ( V_6 ) {
F_43 ( V_2 , L_10 ) ;
return;
}
F_80 ( V_2 , V_114 ) ;
F_76 ( V_2 , V_114 ) ;
} else if ( V_137 -> V_139 != V_140 ) {
V_6 = F_81 ( V_2 , V_114 , V_137 -> V_139 ) ;
if ( V_6 )
F_43 ( V_2 , L_11 ) ;
V_137 -> V_139 = V_140 ;
V_6 = F_42 ( V_2 , NULL ) ;
if ( V_6 )
F_43 ( V_2 , L_10 ) ;
}
} else if ( V_189 & V_192 ) {
F_82 ( V_2 , V_137 ,
& V_137 -> V_143 ) ;
} else if ( V_189 & V_193 ) {
F_57 ( V_2 , L_8 ,
V_2 -> V_150 ) ;
if ( V_2 -> V_150 == 1 ) {
V_6 = F_52 ( V_2 , V_114 ) ;
if ( V_6 )
F_43 ( V_2 , L_12 ) ;
}
}
}
static int F_83 ( struct V_3 * V_4 , struct V_113 * V_114 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_32 * V_137 = F_28 ( V_114 ) ;
int V_6 ;
F_19 ( & V_2 -> V_123 ) ;
V_6 = F_84 ( V_2 , V_114 ) ;
if ( V_6 )
goto V_155;
V_6 = F_58 ( V_2 , V_114 ) ;
if ( V_6 )
goto V_155;
V_6 = F_61 ( V_2 , V_114 ) ;
if ( V_6 )
goto V_194;
V_137 -> V_195 = true ;
V_6 = F_85 ( V_2 , V_114 , & V_137 -> V_157 ) ;
if ( V_6 )
goto V_169;
V_6 = F_42 ( V_2 , V_114 ) ;
if ( V_6 )
goto V_196;
if ( V_114 -> V_197 && V_2 -> V_170 )
F_79 ( V_2 , V_2 -> V_170 ) ;
F_26 ( & V_2 -> V_123 ) ;
return 0 ;
V_196:
F_86 ( V_2 , & V_137 -> V_157 ) ;
V_169:
F_64 ( V_2 , V_114 ) ;
V_194:
F_66 ( V_2 , V_114 ) ;
V_155:
F_26 ( & V_2 -> V_123 ) ;
return V_6 ;
}
static void F_87 ( struct V_3 * V_4 , struct V_113 * V_114 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_32 * V_137 = F_28 ( V_114 ) ;
F_69 ( V_2 , V_114 ) ;
F_19 ( & V_2 -> V_123 ) ;
V_137 -> V_195 = false ;
if ( V_114 -> V_197 && V_2 -> V_170 )
F_79 ( V_2 , V_2 -> V_170 ) ;
F_42 ( V_2 , NULL ) ;
F_86 ( V_2 , & V_137 -> V_157 ) ;
F_64 ( V_2 , V_114 ) ;
F_66 ( V_2 , V_114 ) ;
F_26 ( & V_2 -> V_123 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_113 * V_114 ,
struct V_188 * V_185 ,
T_3 V_189 )
{
if ( V_189 & V_198 ) {
if ( F_84 ( V_2 , V_114 ) )
F_89 ( V_2 , L_13 ) ;
}
}
static void F_90 ( struct V_3 * V_4 ,
struct V_113 * V_114 ,
struct V_188 * V_185 ,
T_3 V_189 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
F_19 ( & V_2 -> V_123 ) ;
switch ( V_114 -> type ) {
case V_37 :
F_78 ( V_2 , V_114 , V_185 , V_189 ) ;
break;
case V_39 :
F_88 ( V_2 , V_114 , V_185 , V_189 ) ;
break;
default:
F_25 ( 1 ) ;
}
F_26 ( & V_2 -> V_123 ) ;
}
static int F_91 ( struct V_3 * V_4 ,
struct V_113 * V_114 ,
struct V_199 * V_200 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
int V_6 ;
if ( V_200 -> V_65 == 0 || V_200 -> V_65 > V_201 )
return - V_127 ;
F_19 ( & V_2 -> V_123 ) ;
if ( V_2 -> V_145 == V_146 )
V_6 = F_92 ( V_2 , V_114 , V_200 ) ;
else
V_6 = - V_202 ;
F_26 ( & V_2 -> V_123 ) ;
return V_6 ;
}
static void F_93 ( struct V_3 * V_4 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
F_19 ( & V_2 -> V_123 ) ;
F_94 ( V_2 ) ;
F_26 ( & V_2 -> V_123 ) ;
}
static void
F_95 ( struct V_3 * V_4 ,
struct V_117 * V_112 , T_1 V_118 ,
int V_203 ,
enum V_204 V_205 ,
bool V_206 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
F_96 ( V_2 , V_112 , V_205 , V_203 ) ;
}
static void F_97 ( struct V_3 * V_4 ,
struct V_113 * V_114 ,
enum V_207 V_208 ,
struct V_117 * V_112 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_30 * V_209 = ( void * ) V_112 -> V_210 ;
switch ( V_208 ) {
case V_211 :
if ( F_98 ( & V_2 -> V_212 [ V_209 -> V_213 ] ) > 0 )
F_99 ( V_4 , V_112 , true ) ;
break;
case V_214 :
if ( F_100 ( V_209 -> V_213 == V_140 ) )
break;
F_101 ( V_2 , V_112 ) ;
break;
default:
break;
}
}
static int F_102 ( struct V_3 * V_4 ,
struct V_113 * V_114 ,
struct V_117 * V_112 ,
enum V_215 V_216 ,
enum V_215 V_217 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_32 * V_137 = F_28 ( V_114 ) ;
int V_6 ;
F_57 ( V_2 , L_14 ,
V_112 -> V_52 , V_216 , V_217 ) ;
if ( F_25 ( ! V_137 -> V_144 ) )
return - V_127 ;
F_45 ( & V_2 -> V_176 ) ;
F_19 ( & V_2 -> V_123 ) ;
if ( V_216 == V_218 &&
V_217 == V_219 ) {
V_6 = F_103 ( V_2 , V_114 , V_112 ) ;
} else if ( V_216 == V_219 &&
V_217 == V_220 ) {
V_6 = 0 ;
} else if ( V_216 == V_220 &&
V_217 == V_221 ) {
V_6 = F_104 ( V_2 , V_114 , V_112 ) ;
if ( V_6 == 0 )
F_105 ( V_2 , V_112 ,
V_137 -> V_144 -> V_222 -> V_223 ) ;
} else if ( V_216 == V_221 &&
V_217 == V_224 ) {
V_6 = 0 ;
} else if ( V_216 == V_224 &&
V_217 == V_221 ) {
V_6 = 0 ;
} else if ( V_216 == V_221 &&
V_217 == V_220 ) {
V_6 = 0 ;
} else if ( V_216 == V_220 &&
V_217 == V_219 ) {
V_6 = 0 ;
} else if ( V_216 == V_219 &&
V_217 == V_218 ) {
V_6 = F_106 ( V_2 , V_114 , V_112 ) ;
} else {
V_6 = - V_225 ;
}
F_26 ( & V_2 -> V_123 ) ;
return V_6 ;
}
static int F_107 ( struct V_3 * V_4 , T_3 V_226 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
V_2 -> V_77 = V_226 ;
return 0 ;
}
static int F_108 ( struct V_3 * V_4 ,
struct V_113 * V_114 , T_1 V_172 ,
const struct V_227 * V_228 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_32 * V_137 = F_28 ( V_114 ) ;
V_137 -> V_229 [ V_172 ] = * V_228 ;
if ( V_114 -> type == V_41 ) {
int V_6 ;
F_19 ( & V_2 -> V_123 ) ;
V_6 = F_79 ( V_2 , V_114 ) ;
F_26 ( & V_2 -> V_123 ) ;
return V_6 ;
}
return 0 ;
}
static void F_109 ( struct V_3 * V_4 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
T_3 V_230 = F_4 ( V_231 ,
200 + V_114 -> V_185 . V_232 ) ;
T_3 V_233 = F_4 ( V_234 ,
100 + V_114 -> V_185 . V_232 ) ;
if ( F_25 ( V_114 -> V_185 . V_191 ) )
return;
F_19 ( & V_2 -> V_123 ) ;
F_110 ( V_2 , V_114 , V_230 , V_233 ) ;
F_26 ( & V_2 -> V_123 ) ;
}
static int F_111 ( struct V_3 * V_4 ,
enum V_235 V_208 ,
struct V_113 * V_114 ,
struct V_117 * V_112 ,
struct V_236 * V_237 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
int V_6 ;
if ( V_26 . V_27 ) {
F_57 ( V_2 , L_15 ) ;
return - V_238 ;
}
switch ( V_237 -> V_239 ) {
case V_240 :
V_237 -> V_8 |= V_241 ;
case V_242 :
V_237 -> V_8 |= V_243 ;
break;
case V_244 :
F_25 ( ! ( V_4 -> V_8 & V_28 ) ) ;
break;
case V_245 :
case V_246 :
return 0 ;
default:
return - V_238 ;
}
F_19 ( & V_2 -> V_123 ) ;
switch ( V_208 ) {
case V_247 :
if ( V_114 -> type == V_39 && ! V_112 ) {
V_6 = 0 ;
V_237 -> V_248 = V_249 ;
break;
}
F_57 ( V_2 , L_16 ) ;
V_6 = F_112 ( V_2 , V_114 , V_112 , V_237 , false ) ;
if ( V_6 ) {
F_89 ( V_2 , L_17 ) ;
V_237 -> V_248 = V_249 ;
V_6 = 0 ;
}
break;
case V_250 :
if ( V_237 -> V_248 == V_249 ) {
V_6 = 0 ;
break;
}
F_57 ( V_2 , L_18 ) ;
V_6 = F_113 ( V_2 , V_114 , V_112 , V_237 ) ;
break;
default:
V_6 = - V_127 ;
}
F_26 ( & V_2 -> V_123 ) ;
return V_6 ;
}
static void F_114 ( struct V_3 * V_4 ,
struct V_113 * V_114 ,
struct V_236 * V_251 ,
struct V_117 * V_112 ,
T_3 V_252 , T_1 * V_253 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
F_115 ( V_2 , V_114 , V_251 , V_112 , V_252 , V_253 ) ;
}
static int F_116 ( struct V_3 * V_4 ,
struct V_113 * V_114 ,
struct V_160 * V_222 ,
int V_230 ,
enum V_254 type )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_162 V_163 ;
int V_6 ;
if ( V_114 -> type != V_41 ) {
F_43 ( V_2 , L_19 , V_114 -> type ) ;
return - V_127 ;
}
F_57 ( V_2 , L_20 , V_222 -> V_255 ,
V_230 , type ) ;
F_19 ( & V_2 -> V_123 ) ;
F_59 ( & V_163 , V_222 , V_166 ) ;
V_6 = F_117 ( V_2 , & V_2 -> V_164 ,
& V_163 , 1 , 1 ) ;
V_6 = F_118 ( V_2 , V_114 , V_230 , type ) ;
F_26 ( & V_2 -> V_123 ) ;
F_57 ( V_2 , L_21 ) ;
return V_6 ;
}
static int F_119 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
F_57 ( V_2 , L_22 ) ;
F_19 ( & V_2 -> V_123 ) ;
F_120 ( V_2 ) ;
F_26 ( & V_2 -> V_123 ) ;
F_57 ( V_2 , L_21 ) ;
return 0 ;
}
static int F_121 ( struct V_3 * V_4 ,
struct V_256 * V_257 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_34 * V_144 = ( void * ) V_257 -> V_210 ;
int V_6 ;
F_19 ( & V_2 -> V_123 ) ;
F_57 ( V_2 , L_23 ) ;
V_6 = F_60 ( V_2 , V_144 , & V_257 -> V_258 ,
V_257 -> V_259 ,
V_257 -> V_260 ) ;
F_26 ( & V_2 -> V_123 ) ;
return V_6 ;
}
static void F_122 ( struct V_3 * V_4 ,
struct V_256 * V_257 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_34 * V_144 = ( void * ) V_257 -> V_210 ;
F_19 ( & V_2 -> V_123 ) ;
F_65 ( V_2 , V_144 ) ;
F_26 ( & V_2 -> V_123 ) ;
}
static void F_123 ( struct V_3 * V_4 ,
struct V_256 * V_257 ,
T_3 V_177 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_34 * V_144 = ( void * ) V_257 -> V_210 ;
F_19 ( & V_2 -> V_123 ) ;
F_117 ( V_2 , V_144 , & V_257 -> V_258 ,
V_257 -> V_259 ,
V_257 -> V_260 ) ;
F_26 ( & V_2 -> V_123 ) ;
}
static int F_124 ( struct V_3 * V_4 ,
struct V_113 * V_114 ,
struct V_256 * V_257 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_34 * V_261 = ( void * ) V_257 -> V_210 ;
struct V_32 * V_137 = F_28 ( V_114 ) ;
int V_6 ;
F_19 ( & V_2 -> V_123 ) ;
V_137 -> V_144 = V_261 ;
switch ( V_114 -> type ) {
case V_39 :
V_6 = 0 ;
goto V_155;
case V_37 :
case V_262 :
case V_263 :
break;
default:
V_6 = - V_127 ;
goto V_155;
}
V_6 = F_61 ( V_2 , V_114 ) ;
if ( V_6 )
goto V_155;
if ( V_114 -> type == V_263 ) {
V_137 -> V_264 = true ;
V_6 = F_42 ( V_2 , V_114 ) ;
if ( V_6 )
goto V_265;
}
goto V_155;
V_265:
F_64 ( V_2 , V_114 ) ;
V_155:
F_26 ( & V_2 -> V_123 ) ;
if ( V_6 )
V_137 -> V_144 = NULL ;
return V_6 ;
}
static void F_125 ( struct V_3 * V_4 ,
struct V_113 * V_114 ,
struct V_256 * V_257 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_32 * V_137 = F_28 ( V_114 ) ;
F_19 ( & V_2 -> V_123 ) ;
F_82 ( V_2 , V_137 , & V_137 -> V_143 ) ;
if ( V_114 -> type == V_39 )
goto V_155;
switch ( V_114 -> type ) {
case V_263 :
V_137 -> V_264 = false ;
F_42 ( V_2 , NULL ) ;
break;
default:
break;
}
F_64 ( V_2 , V_114 ) ;
V_155:
V_137 -> V_144 = NULL ;
F_26 ( & V_2 -> V_123 ) ;
}
static int F_126 ( struct V_3 * V_4 ,
struct V_117 * V_112 ,
bool V_266 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
struct V_30 * V_267 = ( void * ) V_112 -> V_210 ;
if ( ! V_267 || ! V_267 -> V_114 ) {
F_43 ( V_2 , L_24 ) ;
return - V_127 ;
}
return F_84 ( V_2 , V_267 -> V_114 ) ;
}
static void F_127 ( struct V_3 * V_4 ,
struct V_113 * V_114 ,
enum V_268 V_269 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
F_128 ( V_2 , V_114 , V_269 ) ;
}
