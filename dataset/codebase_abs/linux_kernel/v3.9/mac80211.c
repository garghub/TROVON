int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 , V_6 ;
V_4 -> V_7 = V_8 |
V_9 |
V_10 |
V_11 |
V_12 |
V_13 |
V_14 |
V_15 |
V_16 ;
V_4 -> V_17 = V_18 ;
V_4 -> V_19 = V_20 ;
V_4 -> V_21 = L_1 ;
if ( V_2 -> V_22 -> V_23 . V_7 & V_24 &&
! V_25 . V_26 )
V_4 -> V_7 |= V_27 ;
V_4 -> V_28 = sizeof( struct V_29 ) ;
V_4 -> V_30 = sizeof( struct V_31 ) ;
V_4 -> V_32 = sizeof( struct V_33 ) ;
V_4 -> V_34 -> V_35 = F_2 ( V_36 ) |
F_2 ( V_37 ) |
F_2 ( V_38 ) |
F_2 ( V_39 ) |
F_2 ( V_40 ) ;
V_4 -> V_34 -> V_7 |= V_41 |
V_42 |
V_43 ;
V_4 -> V_34 -> V_44 = V_45 ;
V_4 -> V_34 -> V_46 =
F_3 ( V_45 ) ;
V_4 -> V_34 -> V_47 = 500 ;
V_4 -> V_48 = V_49 ;
memcpy ( V_2 -> V_50 [ 0 ] . V_51 , V_2 -> V_52 -> V_53 , V_54 ) ;
V_4 -> V_34 -> V_50 = V_2 -> V_50 ;
V_4 -> V_34 -> V_55 = 1 ;
V_5 = V_2 -> V_52 -> V_56 ;
if ( V_5 > 1 ) {
memcpy ( V_2 -> V_50 [ 1 ] . V_51 , V_2 -> V_50 [ 0 ] . V_51 ,
V_54 ) ;
V_2 -> V_50 [ 1 ] . V_51 [ 5 ] ++ ;
V_4 -> V_34 -> V_55 ++ ;
}
V_4 -> V_34 -> V_57 =
V_2 -> V_22 -> V_23 . V_58 - 24 - 34 ;
V_4 -> V_34 -> V_59 = V_60 ;
if ( V_2 -> V_52 -> V_61 [ V_62 ] . V_63 )
V_4 -> V_34 -> V_61 [ V_62 ] =
& V_2 -> V_52 -> V_61 [ V_62 ] ;
if ( V_2 -> V_52 -> V_61 [ V_64 ] . V_63 )
V_4 -> V_34 -> V_61 [ V_64 ] =
& V_2 -> V_52 -> V_61 [ V_64 ] ;
V_4 -> V_34 -> V_65 = V_2 -> V_66 -> V_67 ;
if ( V_25 . V_68 )
V_4 -> V_34 -> V_7 |= V_69 ;
else
V_4 -> V_34 -> V_7 &= ~ V_69 ;
V_4 -> V_34 -> V_70 |= V_71 |
V_72 ;
V_2 -> V_73 = V_74 ;
#ifdef F_4
if ( V_2 -> V_22 -> V_75 [ V_76 ] . V_77 [ 0 ] . V_78 &&
V_2 -> V_66 -> V_79 -> V_80 &&
V_2 -> V_66 -> V_79 -> V_81 &&
F_5 ( V_2 -> V_66 -> V_82 ) ) {
V_4 -> V_34 -> V_83 . V_7 = V_84 |
V_85 |
V_86 |
V_87 ;
if ( ! V_25 . V_26 )
V_4 -> V_34 -> V_83 . V_7 |=
V_88 |
V_89 |
V_90 ;
V_4 -> V_34 -> V_83 . V_91 = V_92 ;
V_4 -> V_34 -> V_83 . V_93 = V_94 ;
V_4 -> V_34 -> V_83 . V_95 = V_96 ;
}
#endif
V_6 = F_6 ( V_2 ) ;
if ( V_6 )
return V_6 ;
return F_7 ( V_2 -> V_4 ) ;
}
static void F_8 ( struct V_3 * V_4 ,
struct V_97 * V_98 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
if ( F_10 ( V_101 , & V_2 -> V_102 ) ) {
F_11 ( V_2 , L_2 ) ;
goto V_103;
}
if ( F_12 ( V_100 ) -> V_104 == V_20 &&
! F_10 ( V_105 , & V_2 -> V_102 ) )
goto V_103;
if ( V_98 -> V_106 ) {
if ( F_13 ( V_2 , V_100 , V_98 -> V_106 ) )
goto V_103;
return;
}
if ( F_14 ( V_2 , V_100 ) )
goto V_103;
return;
V_103:
F_15 ( V_4 , V_100 ) ;
}
static int F_16 ( struct V_3 * V_4 ,
struct V_107 * V_108 ,
enum V_109 V_110 ,
struct V_111 * V_106 , T_1 V_112 ,
T_1 * V_113 , T_2 V_114 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
int V_6 ;
F_17 ( V_2 , L_3 ,
V_106 -> V_51 , V_112 , V_110 ) ;
if ( ! ( V_2 -> V_52 -> V_115 ) )
return - V_116 ;
F_18 ( & V_2 -> V_117 ) ;
switch ( V_110 ) {
case V_118 :
if ( V_25 . V_119 & V_120 ) {
V_6 = - V_121 ;
break;
}
V_6 = F_19 ( V_2 , V_106 , V_112 , * V_113 , true ) ;
break;
case V_122 :
V_6 = F_19 ( V_2 , V_106 , V_112 , 0 , false ) ;
break;
case V_123 :
V_6 = F_20 ( V_2 , V_108 , V_106 , V_112 , V_113 ) ;
break;
case V_124 :
case V_125 :
case V_126 :
V_6 = F_21 ( V_2 , V_108 , V_106 , V_112 ) ;
break;
case V_127 :
V_6 = F_22 ( V_2 , V_108 , V_106 , V_112 , V_114 ) ;
break;
default:
F_23 ( 1 ) ;
V_6 = - V_121 ;
break;
}
F_24 ( & V_2 -> V_117 ) ;
return V_6 ;
}
static void F_25 ( void * V_128 , T_2 * V_129 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 = V_128 ;
struct V_31 * V_130 = F_26 ( V_108 ) ;
V_130 -> V_131 = false ;
V_130 -> V_132 = V_133 ;
V_130 -> V_134 ++ ;
F_27 ( & V_2 -> V_135 ) ;
F_28 ( V_2 , & V_130 -> V_136 ) ;
F_29 ( & V_2 -> V_135 ) ;
if ( V_108 -> type != V_40 )
V_130 -> V_137 = NULL ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 ( V_2 -> V_66 ) ;
F_32 ( V_2 -> V_66 , false ) ;
V_2 -> V_138 = V_139 ;
F_33 ( V_2 -> V_4 ) ;
F_34 (
V_2 -> V_4 , V_140 ,
F_25 , V_2 ) ;
memset ( V_2 -> V_141 , 0 , sizeof( V_2 -> V_141 ) ) ;
memset ( V_2 -> V_142 , 0 , sizeof( V_2 -> V_142 ) ) ;
F_35 ( V_2 -> V_4 ) ;
V_2 -> V_143 = 0 ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
int V_6 ;
F_18 ( & V_2 -> V_117 ) ;
if ( F_10 ( V_144 , & V_2 -> V_102 ) )
F_30 ( V_2 ) ;
V_6 = F_37 ( V_2 ) ;
F_24 ( & V_2 -> V_117 ) ;
return V_6 ;
}
static void F_38 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
int V_6 ;
F_18 ( & V_2 -> V_117 ) ;
F_39 ( V_144 , & V_2 -> V_102 ) ;
V_6 = F_40 ( V_2 , NULL ) ;
if ( V_6 )
F_41 ( V_2 , L_4 ,
V_6 ) ;
F_24 ( & V_2 -> V_117 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
F_43 ( & V_2 -> V_145 ) ;
F_18 ( & V_2 -> V_117 ) ;
F_44 ( & V_2 -> V_146 ) ;
F_31 ( V_2 -> V_66 ) ;
F_32 ( V_2 -> V_66 , false ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 , & V_2 -> V_147 ) ;
F_24 ( & V_2 -> V_117 ) ;
F_44 ( & V_2 -> V_145 ) ;
}
static void F_47 ( void * V_128 , T_2 * V_129 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 = V_128 ;
int V_6 ;
V_6 = F_48 ( V_2 , V_108 ) ;
if ( V_6 )
F_41 ( V_2 , L_5 ) ;
}
static void F_49 ( void * V_128 , T_2 * V_129 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 = V_128 ;
F_50 ( V_2 , V_108 ) ;
}
static int F_51 ( struct V_3 * V_4 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_31 * V_130 = F_26 ( V_108 ) ;
int V_6 ;
F_18 ( & V_2 -> V_117 ) ;
V_6 = F_52 ( V_2 , V_108 ) ;
if ( V_6 )
goto V_148;
if ( V_108 -> type == V_38 ) {
T_3 V_149 = F_53 ( V_2 , V_108 ) ;
V_6 = F_54 ( V_2 , & V_130 -> V_150 ,
V_149 ) ;
if ( V_6 ) {
F_41 ( V_2 , L_6 ) ;
goto V_151;
}
goto V_148;
}
V_2 -> V_143 ++ ;
if ( V_2 -> V_143 > 1 ) {
F_55 ( V_2 ,
L_7 ) ;
F_34 (
V_2 -> V_4 ,
V_152 ,
F_47 , V_2 ) ;
}
V_6 = F_56 ( V_2 , V_108 ) ;
if ( V_6 )
goto V_151;
F_50 ( V_2 , V_108 ) ;
if ( V_108 -> type == V_40 ) {
struct V_153 * V_154 ;
struct V_155 V_156 ;
V_130 -> V_137 = & V_2 -> V_157 ;
V_154 = & V_2 -> V_4 -> V_34 -> V_61 [ V_62 ] -> V_158 [ 0 ] ;
F_57 ( & V_156 , V_154 , V_159 ) ;
V_6 = F_58 ( V_2 , V_130 -> V_137 ,
& V_156 , 1 , 1 ) ;
if ( V_6 )
goto V_160;
V_6 = F_59 ( V_2 , V_108 ) ;
if ( V_6 )
goto V_161;
V_6 = F_60 ( V_2 , V_108 , & V_130 -> V_150 ) ;
if ( V_6 )
goto V_162;
V_2 -> V_163 = V_108 ;
}
goto V_148;
V_162:
F_61 ( V_2 , V_108 ) ;
V_161:
F_62 ( V_2 , V_130 -> V_137 ) ;
V_160:
V_130 -> V_137 = NULL ;
F_63 ( V_2 , V_108 ) ;
V_151:
V_2 -> V_143 -- ;
F_55 ( V_2 , L_8 ,
V_2 -> V_143 ) ;
if ( V_2 -> V_143 == 1 ) {
F_64 (
V_2 -> V_4 , V_152 ,
F_49 , V_2 ) ;
}
F_65 ( V_2 , V_108 ) ;
V_148:
F_24 ( & V_2 -> V_117 ) ;
return V_6 ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
T_3 V_164 = 0 , V_165 ;
for ( V_165 = 0 ; V_165 < V_166 ; V_165 ++ )
if ( V_108 -> V_104 [ V_165 ] != V_167 )
V_164 |= F_2 ( V_108 -> V_104 [ V_165 ] ) ;
if ( V_108 -> V_168 != V_167 )
V_164 |= F_2 ( V_108 -> V_168 ) ;
if ( V_164 ) {
F_18 ( & V_2 -> V_117 ) ;
F_67 ( V_2 , V_164 , true ) ;
F_24 ( & V_2 -> V_117 ) ;
}
if ( V_108 -> type == V_40 ) {
F_43 ( & V_2 -> V_146 ) ;
} else {
F_43 ( & V_2 -> V_169 ) ;
}
}
static void F_68 ( struct V_3 * V_4 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_31 * V_130 = F_26 ( V_108 ) ;
F_66 ( V_2 , V_108 ) ;
F_18 ( & V_2 -> V_117 ) ;
if ( V_108 -> type == V_38 ) {
F_46 ( V_2 , & V_130 -> V_150 ) ;
goto V_151;
}
if ( V_108 -> type == V_40 ) {
V_2 -> V_163 = NULL ;
F_69 ( V_2 , & V_130 -> V_150 ) ;
F_61 ( V_2 , V_108 ) ;
F_62 ( V_2 , V_130 -> V_137 ) ;
V_130 -> V_137 = NULL ;
}
if ( V_2 -> V_143 )
V_2 -> V_143 -- ;
F_55 ( V_2 , L_8 ,
V_2 -> V_143 ) ;
if ( V_2 -> V_143 == 1 ) {
F_64 (
V_2 -> V_4 , V_152 ,
F_49 , V_2 ) ;
}
F_63 ( V_2 , V_108 ) ;
V_151:
F_65 ( V_2 , V_108 ) ;
F_24 ( & V_2 -> V_117 ) ;
}
static int F_70 ( struct V_3 * V_4 , T_3 V_170 )
{
return 0 ;
}
static void F_71 ( struct V_3 * V_4 ,
unsigned int V_171 ,
unsigned int * V_172 ,
T_4 V_173 )
{
* V_172 = 0 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_107 * V_108 ,
struct V_174 * V_175 ,
T_3 V_176 )
{
struct V_31 * V_130 = F_26 ( V_108 ) ;
int V_6 ;
V_6 = F_73 ( V_2 , V_108 ) ;
if ( V_6 )
F_41 ( V_2 , L_9 , V_108 -> V_51 ) ;
if ( V_176 & V_177 ) {
if ( V_175 -> V_178 ) {
V_6 = F_40 ( V_2 , V_108 ) ;
if ( V_6 ) {
F_41 ( V_2 , L_10 ) ;
return;
}
} else if ( V_130 -> V_132 != V_133 ) {
V_6 = F_74 ( V_2 , V_108 , V_130 -> V_132 ) ;
if ( V_6 )
F_41 ( V_2 , L_11 ) ;
V_130 -> V_132 = V_133 ;
V_6 = F_40 ( V_2 , NULL ) ;
if ( V_6 )
F_41 ( V_2 , L_10 ) ;
}
} else if ( V_176 & V_179 ) {
F_75 ( V_2 , V_130 ,
& V_130 -> V_136 ) ;
} else if ( V_176 & V_180 ) {
F_55 ( V_2 , L_8 ,
V_2 -> V_143 ) ;
if ( V_2 -> V_143 == 1 ) {
V_6 = F_50 ( V_2 , V_108 ) ;
if ( V_6 )
F_41 ( V_2 , L_12 ) ;
}
}
}
static int F_76 ( struct V_3 * V_4 , struct V_107 * V_108 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_31 * V_130 = F_26 ( V_108 ) ;
int V_6 ;
F_18 ( & V_2 -> V_117 ) ;
V_6 = F_77 ( V_2 , V_108 ) ;
if ( V_6 )
goto V_148;
V_6 = F_56 ( V_2 , V_108 ) ;
if ( V_6 )
goto V_148;
V_6 = F_59 ( V_2 , V_108 ) ;
if ( V_6 )
goto V_181;
V_130 -> V_182 = true ;
V_6 = F_78 ( V_2 , V_108 , & V_130 -> V_150 ) ;
if ( V_6 )
goto V_162;
V_6 = F_40 ( V_2 , V_108 ) ;
if ( V_6 )
goto V_183;
if ( V_108 -> V_184 && V_2 -> V_163 )
F_73 ( V_2 , V_2 -> V_163 ) ;
F_24 ( & V_2 -> V_117 ) ;
return 0 ;
V_183:
F_79 ( V_2 , & V_130 -> V_150 ) ;
V_162:
F_61 ( V_2 , V_108 ) ;
V_181:
F_63 ( V_2 , V_108 ) ;
V_148:
F_24 ( & V_2 -> V_117 ) ;
return V_6 ;
}
static void F_80 ( struct V_3 * V_4 , struct V_107 * V_108 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_31 * V_130 = F_26 ( V_108 ) ;
F_66 ( V_2 , V_108 ) ;
F_18 ( & V_2 -> V_117 ) ;
V_130 -> V_182 = false ;
if ( V_108 -> V_184 && V_2 -> V_163 )
F_73 ( V_2 , V_2 -> V_163 ) ;
F_40 ( V_2 , NULL ) ;
F_79 ( V_2 , & V_130 -> V_150 ) ;
F_61 ( V_2 , V_108 ) ;
F_63 ( V_2 , V_108 ) ;
F_24 ( & V_2 -> V_117 ) ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_107 * V_108 ,
struct V_174 * V_175 ,
T_3 V_176 )
{
if ( V_176 & V_185 ) {
if ( F_77 ( V_2 , V_108 ) )
F_82 ( V_2 , L_13 ) ;
}
}
static void F_83 ( struct V_3 * V_4 ,
struct V_107 * V_108 ,
struct V_174 * V_175 ,
T_3 V_176 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
F_18 ( & V_2 -> V_117 ) ;
switch ( V_108 -> type ) {
case V_36 :
F_72 ( V_2 , V_108 , V_175 , V_176 ) ;
break;
case V_38 :
F_81 ( V_2 , V_108 , V_175 , V_176 ) ;
break;
default:
F_23 ( 1 ) ;
}
F_24 ( & V_2 -> V_117 ) ;
}
static int F_84 ( struct V_3 * V_4 ,
struct V_107 * V_108 ,
struct V_186 * V_187 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
int V_6 ;
if ( V_187 -> V_63 == 0 || V_187 -> V_63 > V_188 )
return - V_121 ;
F_18 ( & V_2 -> V_117 ) ;
if ( V_2 -> V_138 == V_139 )
V_6 = F_85 ( V_2 , V_108 , V_187 ) ;
else
V_6 = - V_189 ;
F_24 ( & V_2 -> V_117 ) ;
return V_6 ;
}
static void F_86 ( struct V_3 * V_4 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
F_18 ( & V_2 -> V_117 ) ;
F_87 ( V_2 ) ;
F_24 ( & V_2 -> V_117 ) ;
}
static void
F_88 ( struct V_3 * V_4 ,
struct V_111 * V_106 , T_1 V_112 ,
int V_190 ,
enum V_191 V_192 ,
bool V_193 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
F_89 ( V_2 , V_106 , V_192 , V_190 ) ;
}
static void F_90 ( struct V_3 * V_4 ,
struct V_107 * V_108 ,
enum V_194 V_195 ,
struct V_111 * V_106 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_29 * V_196 = ( void * ) V_106 -> V_197 ;
switch ( V_195 ) {
case V_198 :
if ( F_91 ( & V_196 -> V_199 ) > 0 )
F_92 ( V_4 , V_106 , true ) ;
break;
case V_200 :
if ( F_93 ( V_196 -> V_201 == V_202 ) )
break;
F_94 ( V_2 , V_106 ) ;
break;
default:
break;
}
}
static int F_95 ( struct V_3 * V_4 ,
struct V_107 * V_108 ,
struct V_111 * V_106 ,
enum V_203 V_204 ,
enum V_203 V_205 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_31 * V_130 = F_26 ( V_108 ) ;
int V_6 ;
F_55 ( V_2 , L_14 ,
V_106 -> V_51 , V_204 , V_205 ) ;
if ( F_23 ( ! V_130 -> V_137 ) )
return - V_121 ;
F_43 ( & V_2 -> V_169 ) ;
F_18 ( & V_2 -> V_117 ) ;
if ( V_204 == V_206 &&
V_205 == V_207 ) {
V_6 = F_96 ( V_2 , V_108 , V_106 ) ;
} else if ( V_204 == V_207 &&
V_205 == V_208 ) {
V_6 = 0 ;
} else if ( V_204 == V_208 &&
V_205 == V_209 ) {
V_6 = F_97 ( V_2 , V_108 , V_106 ) ;
if ( V_6 == 0 )
F_98 ( V_2 , V_106 ,
V_130 -> V_137 -> V_210 -> V_211 ) ;
} else if ( V_204 == V_209 &&
V_205 == V_212 ) {
V_6 = 0 ;
} else if ( V_204 == V_212 &&
V_205 == V_209 ) {
V_6 = 0 ;
} else if ( V_204 == V_209 &&
V_205 == V_208 ) {
V_6 = 0 ;
} else if ( V_204 == V_208 &&
V_205 == V_207 ) {
V_6 = 0 ;
} else if ( V_204 == V_207 &&
V_205 == V_206 ) {
V_6 = F_99 ( V_2 , V_108 , V_106 ) ;
} else {
V_6 = - V_213 ;
}
F_24 ( & V_2 -> V_117 ) ;
return V_6 ;
}
static int F_100 ( struct V_3 * V_4 , T_3 V_214 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
V_2 -> V_73 = V_214 ;
return 0 ;
}
static int F_101 ( struct V_3 * V_4 ,
struct V_107 * V_108 , T_1 V_165 ,
const struct V_215 * V_216 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_31 * V_130 = F_26 ( V_108 ) ;
V_130 -> V_217 [ V_165 ] = * V_216 ;
if ( V_108 -> type == V_40 ) {
int V_6 ;
F_18 ( & V_2 -> V_117 ) ;
V_6 = F_73 ( V_2 , V_108 ) ;
F_24 ( & V_2 -> V_117 ) ;
return V_6 ;
}
return 0 ;
}
static void F_102 ( struct V_3 * V_4 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
T_3 V_218 = F_103 ( V_219 ,
200 + V_108 -> V_175 . V_220 ) ;
T_3 V_221 = F_103 ( V_222 ,
100 + V_108 -> V_175 . V_220 ) ;
if ( F_23 ( V_108 -> V_175 . V_178 ) )
return;
F_18 ( & V_2 -> V_117 ) ;
F_104 ( V_2 , V_108 , V_218 , V_221 ) ;
F_24 ( & V_2 -> V_117 ) ;
}
static int F_105 ( struct V_3 * V_4 ,
enum V_223 V_195 ,
struct V_107 * V_108 ,
struct V_111 * V_106 ,
struct V_224 * V_225 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
int V_6 ;
if ( V_25 . V_26 ) {
F_55 ( V_2 , L_15 ) ;
return - V_226 ;
}
switch ( V_225 -> V_227 ) {
case V_228 :
V_225 -> V_7 |= V_229 ;
case V_230 :
V_225 -> V_7 |= V_231 ;
break;
case V_232 :
F_23 ( ! ( V_4 -> V_7 & V_27 ) ) ;
break;
case V_233 :
case V_234 :
return 0 ;
default:
return - V_226 ;
}
F_18 ( & V_2 -> V_117 ) ;
switch ( V_195 ) {
case V_235 :
F_55 ( V_2 , L_16 ) ;
V_6 = F_106 ( V_2 , V_108 , V_106 , V_225 , false ) ;
if ( V_6 ) {
F_82 ( V_2 , L_17 ) ;
V_6 = 0 ;
}
break;
case V_236 :
F_55 ( V_2 , L_18 ) ;
V_6 = F_107 ( V_2 , V_108 , V_106 , V_225 ) ;
break;
default:
V_6 = - V_121 ;
}
F_24 ( & V_2 -> V_117 ) ;
return V_6 ;
}
static void F_108 ( struct V_3 * V_4 ,
struct V_107 * V_108 ,
struct V_224 * V_237 ,
struct V_111 * V_106 ,
T_3 V_238 , T_1 * V_239 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
F_109 ( V_2 , V_108 , V_237 , V_106 , V_238 , V_239 ) ;
}
static int F_110 ( struct V_3 * V_4 ,
struct V_107 * V_108 ,
struct V_153 * V_210 ,
int V_218 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_155 V_156 ;
int V_6 ;
if ( V_108 -> type != V_40 ) {
F_41 ( V_2 , L_19 , V_108 -> type ) ;
return - V_121 ;
}
F_55 ( V_2 , L_20 , V_210 -> V_240 ,
V_218 ) ;
F_18 ( & V_2 -> V_117 ) ;
F_57 ( & V_156 , V_210 , V_159 ) ;
V_6 = F_111 ( V_2 , & V_2 -> V_157 ,
& V_156 , 1 , 1 ) ;
V_6 = F_112 ( V_2 , V_108 , V_218 ) ;
F_24 ( & V_2 -> V_117 ) ;
F_55 ( V_2 , L_21 ) ;
return V_6 ;
}
static int F_113 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
F_55 ( V_2 , L_22 ) ;
F_18 ( & V_2 -> V_117 ) ;
F_114 ( V_2 ) ;
F_24 ( & V_2 -> V_117 ) ;
F_55 ( V_2 , L_21 ) ;
return 0 ;
}
static int F_115 ( struct V_3 * V_4 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_33 * V_137 = ( void * ) V_242 -> V_197 ;
int V_6 ;
F_18 ( & V_2 -> V_117 ) ;
F_55 ( V_2 , L_23 ) ;
V_6 = F_58 ( V_2 , V_137 , & V_242 -> V_243 ,
V_242 -> V_244 ,
V_242 -> V_245 ) ;
F_24 ( & V_2 -> V_117 ) ;
return V_6 ;
}
static void F_116 ( struct V_3 * V_4 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_33 * V_137 = ( void * ) V_242 -> V_197 ;
F_18 ( & V_2 -> V_117 ) ;
F_62 ( V_2 , V_137 ) ;
F_24 ( & V_2 -> V_117 ) ;
}
static void F_117 ( struct V_3 * V_4 ,
struct V_241 * V_242 ,
T_3 V_170 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_33 * V_137 = ( void * ) V_242 -> V_197 ;
F_18 ( & V_2 -> V_117 ) ;
F_111 ( V_2 , V_137 , & V_242 -> V_243 ,
V_242 -> V_244 ,
V_242 -> V_245 ) ;
F_24 ( & V_2 -> V_117 ) ;
}
static int F_118 ( struct V_3 * V_4 ,
struct V_107 * V_108 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_33 * V_246 = ( void * ) V_242 -> V_197 ;
struct V_31 * V_130 = F_26 ( V_108 ) ;
int V_6 ;
F_18 ( & V_2 -> V_117 ) ;
V_130 -> V_137 = V_246 ;
switch ( V_108 -> type ) {
case V_38 :
V_6 = 0 ;
goto V_148;
case V_36 :
case V_247 :
case V_248 :
break;
default:
V_6 = - V_121 ;
goto V_148;
}
V_6 = F_59 ( V_2 , V_108 ) ;
if ( V_6 )
goto V_148;
if ( V_108 -> type == V_248 ) {
V_6 = F_40 ( V_2 , V_108 ) ;
if ( V_6 )
goto V_249;
}
goto V_148;
V_249:
F_61 ( V_2 , V_108 ) ;
V_148:
F_24 ( & V_2 -> V_117 ) ;
if ( V_6 )
V_130 -> V_137 = NULL ;
return V_6 ;
}
static void F_119 ( struct V_3 * V_4 ,
struct V_107 * V_108 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_31 * V_130 = F_26 ( V_108 ) ;
F_18 ( & V_2 -> V_117 ) ;
F_75 ( V_2 , V_130 , & V_130 -> V_136 ) ;
if ( V_108 -> type == V_38 )
goto V_148;
F_61 ( V_2 , V_108 ) ;
switch ( V_108 -> type ) {
case V_248 :
F_40 ( V_2 , V_108 ) ;
break;
default:
break;
}
V_148:
V_130 -> V_137 = NULL ;
F_24 ( & V_2 -> V_117 ) ;
}
static int F_120 ( struct V_3 * V_4 ,
struct V_111 * V_106 ,
bool V_250 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_29 * V_251 = ( void * ) V_106 -> V_197 ;
if ( ! V_251 || ! V_251 -> V_108 ) {
F_41 ( V_2 , L_24 ) ;
return - V_121 ;
}
return F_77 ( V_2 , V_251 -> V_108 ) ;
}
