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
V_22 ;
V_9 -> V_23 = V_24 ;
V_9 -> V_25 = V_26 ;
V_9 -> V_27 = L_1 ;
if ( V_2 -> V_28 -> V_29 . V_12 & V_30 &&
! V_31 . V_32 )
V_9 -> V_12 |= V_33 ;
V_9 -> V_34 = sizeof( struct V_35 ) ;
V_9 -> V_36 = sizeof( struct V_37 ) ;
V_9 -> V_38 = sizeof( V_39 ) ;
V_9 -> V_40 -> V_41 = F_3 ( V_42 ) |
F_3 ( V_43 ) |
F_3 ( V_44 ) |
F_3 ( V_45 ) |
F_3 ( V_46 ) ;
V_9 -> V_40 -> V_12 |= V_47 |
V_48 |
V_49 ;
V_9 -> V_40 -> V_50 = V_51 ;
V_9 -> V_40 -> V_52 =
F_4 ( V_51 ) ;
V_9 -> V_40 -> V_53 = 10000 ;
V_9 -> V_54 = V_55 ;
memcpy ( V_2 -> V_56 [ 0 ] . V_57 , V_2 -> V_58 -> V_59 , V_60 ) ;
V_9 -> V_40 -> V_56 = V_2 -> V_56 ;
V_9 -> V_40 -> V_61 = 1 ;
V_10 = ( V_2 -> V_58 -> V_62 > 1 ) ?
F_5 ( V_63 , V_2 -> V_58 -> V_62 ) : 1 ;
for ( V_3 = 1 ; V_3 < V_10 ; V_3 ++ ) {
memcpy ( V_2 -> V_56 [ V_3 ] . V_57 , V_2 -> V_56 [ V_3 - 1 ] . V_57 ,
V_60 ) ;
V_2 -> V_56 [ V_3 ] . V_57 [ 5 ] ++ ;
V_9 -> V_40 -> V_61 ++ ;
}
F_1 ( V_2 ) ;
V_9 -> V_40 -> V_64 =
V_2 -> V_28 -> V_29 . V_65 - 24 - 34 ;
V_9 -> V_40 -> V_66 = V_67 ;
if ( V_2 -> V_58 -> V_68 [ V_69 ] . V_70 )
V_9 -> V_40 -> V_68 [ V_69 ] =
& V_2 -> V_58 -> V_68 [ V_69 ] ;
if ( V_2 -> V_58 -> V_68 [ V_71 ] . V_70 )
V_9 -> V_40 -> V_68 [ V_71 ] =
& V_2 -> V_58 -> V_68 [ V_71 ] ;
V_9 -> V_40 -> V_72 = V_2 -> V_73 -> V_74 ;
if ( V_75 . V_76 != V_77 )
V_9 -> V_40 -> V_12 |= V_78 ;
else
V_9 -> V_40 -> V_12 &= ~ V_78 ;
V_9 -> V_40 -> V_79 |= V_80 |
V_81 ;
V_2 -> V_82 = V_83 ;
#ifdef F_6
if ( V_2 -> V_28 -> V_84 [ V_85 ] . V_86 [ 0 ] . V_87 &&
V_2 -> V_73 -> V_88 -> V_89 &&
V_2 -> V_73 -> V_88 -> V_90 &&
F_7 ( V_2 -> V_73 -> V_91 ) ) {
V_2 -> V_92 . V_12 = V_93 |
V_94 |
V_95 |
V_96 ;
if ( ! V_31 . V_32 )
V_2 -> V_92 . V_12 |= V_97 |
V_98 |
V_99 ;
V_2 -> V_92 . V_100 = V_101 ;
V_2 -> V_92 . V_102 = V_103 ;
V_2 -> V_92 . V_104 = V_105 ;
V_2 -> V_92 . V_106 = & V_107 ;
V_9 -> V_40 -> V_92 = & V_2 -> V_92 ;
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
struct V_108 * V_109 ,
struct V_110 * V_111 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
if ( F_13 ( V_2 ) ) {
F_14 ( V_2 , L_2 ) ;
goto V_112;
}
if ( F_15 ( V_111 ) -> V_113 == V_26 &&
! F_16 ( V_114 , & V_2 -> V_115 ) )
goto V_112;
if ( V_109 -> V_116 ) {
if ( F_17 ( V_2 , V_111 , V_109 -> V_116 ) )
goto V_112;
return;
}
if ( F_18 ( V_2 , V_111 ) )
goto V_112;
return;
V_112:
F_19 ( V_9 , V_111 ) ;
}
static int F_20 ( struct V_8 * V_9 ,
struct V_117 * V_118 ,
enum V_119 V_120 ,
struct V_121 * V_116 , V_39 V_122 ,
V_39 * V_123 , T_1 V_124 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
int V_11 ;
F_21 ( V_2 , L_3 ,
V_116 -> V_57 , V_122 , V_120 ) ;
if ( ! ( V_2 -> V_58 -> V_125 ) )
return - V_126 ;
F_22 ( & V_2 -> V_127 ) ;
switch ( V_120 ) {
case V_128 :
if ( V_31 . V_129 & V_130 ) {
V_11 = - V_131 ;
break;
}
V_11 = F_23 ( V_2 , V_116 , V_122 , * V_123 , true ) ;
break;
case V_132 :
V_11 = F_23 ( V_2 , V_116 , V_122 , 0 , false ) ;
break;
case V_133 :
if ( V_31 . V_129 & V_134 ) {
V_11 = - V_131 ;
break;
}
V_11 = F_24 ( V_2 , V_118 , V_116 , V_122 , V_123 ) ;
break;
case V_135 :
V_11 = F_25 ( V_2 , V_118 , V_116 , V_122 ) ;
break;
case V_136 :
case V_137 :
V_11 = F_26 ( V_2 , V_118 , V_116 , V_122 ) ;
break;
case V_138 :
V_11 = F_27 ( V_2 , V_118 , V_116 , V_122 , V_124 ) ;
break;
default:
F_28 ( 1 ) ;
V_11 = - V_131 ;
break;
}
F_29 ( & V_2 -> V_127 ) ;
return V_11 ;
}
static void F_30 ( void * V_139 , T_1 * V_140 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = V_139 ;
struct V_37 * V_141 = F_31 ( V_118 ) ;
V_141 -> V_142 = false ;
V_141 -> V_143 = V_144 ;
V_141 -> V_145 ++ ;
F_32 ( & V_2 -> V_146 ) ;
F_33 ( V_2 , & V_141 -> V_147 ) ;
F_34 ( & V_2 -> V_146 ) ;
V_141 -> V_148 = NULL ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_36 ( V_2 -> V_73 ) ;
F_37 ( V_2 -> V_73 , false ) ;
V_2 -> V_149 = V_150 ;
F_38 ( V_2 -> V_9 ) ;
F_39 (
V_2 -> V_9 , V_151 ,
F_30 , V_2 ) ;
V_2 -> V_152 = NULL ;
F_1 ( V_2 ) ;
memset ( V_2 -> V_153 , 0 , sizeof( V_2 -> V_153 ) ) ;
memset ( V_2 -> V_154 , 0 , sizeof( V_2 -> V_154 ) ) ;
F_40 ( V_2 -> V_9 ) ;
V_2 -> V_155 = 0 ;
V_2 -> V_156 = 0 ;
}
static int F_41 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
int V_11 ;
F_22 ( & V_2 -> V_127 ) ;
if ( F_16 ( V_157 , & V_2 -> V_115 ) )
F_35 ( V_2 ) ;
V_11 = F_42 ( V_2 ) ;
F_29 ( & V_2 -> V_127 ) ;
return V_11 ;
}
static void F_43 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
int V_11 ;
F_22 ( & V_2 -> V_127 ) ;
F_44 ( V_157 , & V_2 -> V_115 ) ;
V_11 = F_45 ( V_2 , NULL ) ;
if ( V_11 )
F_46 ( V_2 , L_4 ,
V_11 ) ;
F_29 ( & V_2 -> V_127 ) ;
}
static void F_47 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_48 ( & V_2 -> V_158 ) ;
F_22 ( & V_2 -> V_127 ) ;
F_49 ( & V_2 -> V_159 ) ;
F_36 ( V_2 -> V_73 ) ;
F_37 ( V_2 -> V_73 , false ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 , & V_2 -> V_160 ) ;
F_29 ( & V_2 -> V_127 ) ;
F_49 ( & V_2 -> V_158 ) ;
}
static void F_52 ( void * V_139 , T_1 * V_140 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = V_139 ;
int V_11 ;
V_11 = F_53 ( V_2 , V_118 ) ;
if ( V_11 )
F_46 ( V_2 , L_5 ) ;
}
static void F_54 ( void * V_139 , T_1 * V_140 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = V_139 ;
F_55 ( V_2 , V_118 ) ;
}
static struct V_161 * F_56 ( struct V_1 * V_2 )
{
V_39 V_3 ;
F_57 ( & V_2 -> V_127 ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ )
if ( ! V_2 -> V_4 [ V_3 ] . V_7 )
return & V_2 -> V_4 [ V_3 ] ;
F_46 ( V_2 , L_6 ) ;
return NULL ;
}
static int F_58 ( struct V_8 * V_9 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_37 * V_141 = F_31 ( V_118 ) ;
int V_11 ;
F_22 ( & V_2 -> V_127 ) ;
V_11 = F_59 ( V_2 , V_118 ) ;
if ( V_11 )
goto V_162;
if ( V_118 -> type != V_46 )
V_2 -> V_155 ++ ;
if ( V_2 -> V_155 > 1 ) {
F_60 ( V_2 ,
L_7 ) ;
F_39 (
V_2 -> V_9 ,
V_163 ,
F_52 , V_2 ) ;
}
if ( V_118 -> type == V_44 ) {
T_2 V_164 = F_61 ( V_2 , V_118 ) ;
V_11 = F_62 ( V_2 , & V_141 -> V_165 ,
V_164 ) ;
if ( V_11 ) {
F_46 ( V_2 , L_8 ) ;
goto V_166;
}
goto V_162;
}
V_11 = F_63 ( V_2 , V_118 ) ;
if ( V_11 )
goto V_166;
F_55 ( V_2 , V_118 ) ;
if ( ! V_2 -> V_167 &&
V_118 -> type == V_42 && ! V_118 -> V_168 ) {
V_2 -> V_167 = V_141 ;
V_118 -> V_169 |= V_170 ;
}
V_11 = F_64 ( V_2 , V_118 ) ;
if ( V_11 )
goto V_166;
if ( V_118 -> type == V_46 ) {
V_141 -> V_148 = F_56 ( V_2 ) ;
if ( ! V_141 -> V_148 ) {
V_11 = - V_171 ;
goto V_172;
}
F_65 ( V_2 , V_141 -> V_148 ) ;
V_11 = F_66 ( V_2 , V_118 ) ;
if ( V_11 )
goto V_173;
V_11 = F_67 ( V_2 , V_118 , & V_141 -> V_165 ) ;
if ( V_11 )
goto V_174;
V_2 -> V_152 = V_118 ;
}
F_68 ( V_2 , V_118 ) ;
goto V_162;
V_174:
F_69 ( V_2 , V_118 ) ;
V_173:
F_70 ( V_2 , V_141 -> V_148 ) ;
V_172:
V_141 -> V_148 = NULL ;
F_71 ( V_2 , V_118 ) ;
V_166:
if ( V_118 -> type != V_46 )
V_2 -> V_155 -- ;
F_72 (
V_2 -> V_9 , V_163 ,
F_54 , V_2 ) ;
F_73 ( V_2 , V_118 ) ;
V_162:
F_29 ( & V_2 -> V_127 ) ;
return V_11 ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
T_2 V_175 = 0 , V_176 ;
for ( V_176 = 0 ; V_176 < V_177 ; V_176 ++ )
if ( V_118 -> V_113 [ V_176 ] != V_178 )
V_175 |= F_3 ( V_118 -> V_113 [ V_176 ] ) ;
if ( V_118 -> V_179 != V_178 )
V_175 |= F_3 ( V_118 -> V_179 ) ;
if ( V_175 ) {
F_22 ( & V_2 -> V_127 ) ;
F_75 ( V_2 , V_175 , true ) ;
F_29 ( & V_2 -> V_127 ) ;
}
if ( V_118 -> type == V_46 ) {
F_48 ( & V_2 -> V_159 ) ;
} else {
F_48 ( & V_2 -> V_180 ) ;
}
}
static void F_76 ( struct V_8 * V_9 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_37 * V_141 = F_31 ( V_118 ) ;
F_74 ( V_2 , V_118 ) ;
F_22 ( & V_2 -> V_127 ) ;
if ( V_2 -> V_167 == V_141 ) {
V_2 -> V_167 = NULL ;
V_118 -> V_169 &= ~ V_170 ;
}
F_77 ( V_2 , V_118 ) ;
if ( V_118 -> type == V_44 ) {
F_51 ( V_2 , & V_141 -> V_165 ) ;
goto V_166;
}
if ( V_118 -> type == V_46 ) {
V_2 -> V_152 = NULL ;
F_78 ( V_2 , & V_141 -> V_165 ) ;
F_69 ( V_2 , V_118 ) ;
F_70 ( V_2 , V_141 -> V_148 ) ;
V_141 -> V_148 = NULL ;
}
if ( V_2 -> V_155 && V_118 -> type != V_46 )
V_2 -> V_155 -- ;
F_60 ( V_2 , L_9 ,
V_2 -> V_155 ) ;
if ( V_2 -> V_155 == 1 ) {
F_72 (
V_2 -> V_9 , V_163 ,
F_54 , V_2 ) ;
}
F_71 ( V_2 , V_118 ) ;
V_166:
F_73 ( V_2 , V_118 ) ;
F_29 ( & V_2 -> V_127 ) ;
}
static int F_79 ( struct V_8 * V_9 , T_2 V_181 )
{
return 0 ;
}
static void F_80 ( struct V_8 * V_9 ,
unsigned int V_182 ,
unsigned int * V_183 ,
T_3 V_184 )
{
* V_183 = 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
struct V_185 V_186 = {
. V_187 = 1 ,
} ;
memcpy ( V_186 . V_188 , V_118 -> V_189 . V_188 , V_60 ) ;
return F_82 ( V_2 , V_190 , V_191 ,
sizeof( V_186 ) ,
& V_186 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_117 * V_118 ,
struct V_192 * V_189 ,
T_2 V_193 )
{
struct V_37 * V_141 = F_31 ( V_118 ) ;
int V_11 ;
V_11 = F_84 ( V_2 , V_118 ) ;
if ( V_11 )
F_46 ( V_2 , L_10 , V_118 -> V_57 ) ;
if ( V_193 & V_194 ) {
if ( V_189 -> V_195 ) {
V_11 = F_45 ( V_2 , V_118 ) ;
if ( V_11 ) {
F_46 ( V_2 , L_11 ) ;
return;
}
F_85 ( V_2 , V_118 ) ;
F_81 ( V_2 , V_118 ) ;
} else if ( V_141 -> V_143 != V_144 ) {
V_11 = F_86 ( V_2 , V_118 , V_141 -> V_143 ) ;
if ( V_11 )
F_46 ( V_2 , L_12 ) ;
V_141 -> V_143 = V_144 ;
V_11 = F_45 ( V_2 , NULL ) ;
if ( V_11 )
F_46 ( V_2 , L_11 ) ;
}
V_11 = F_55 ( V_2 , V_118 ) ;
if ( V_11 )
F_46 ( V_2 , L_13 ) ;
} else if ( V_193 & V_196 ) {
F_87 ( V_2 , V_141 ,
& V_141 -> V_147 ) ;
} else if ( V_193 & V_197 ) {
V_11 = F_55 ( V_2 , V_118 ) ;
if ( V_11 )
F_46 ( V_2 , L_13 ) ;
}
}
static int F_88 ( struct V_8 * V_9 , struct V_117 * V_118 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_37 * V_141 = F_31 ( V_118 ) ;
int V_11 ;
F_22 ( & V_2 -> V_127 ) ;
V_11 = F_89 ( V_2 , V_118 ) ;
if ( V_11 )
goto V_162;
V_11 = F_63 ( V_2 , V_118 ) ;
if ( V_11 )
goto V_162;
V_11 = F_66 ( V_2 , V_118 ) ;
if ( V_11 )
goto V_198;
V_141 -> V_199 = true ;
V_11 = F_90 ( V_2 , V_118 , & V_141 -> V_165 ) ;
if ( V_11 )
goto V_174;
V_11 = F_45 ( V_2 , V_118 ) ;
if ( V_11 )
goto V_200;
if ( V_118 -> V_168 && V_2 -> V_152 )
F_84 ( V_2 , V_2 -> V_152 ) ;
F_29 ( & V_2 -> V_127 ) ;
return 0 ;
V_200:
F_91 ( V_2 , & V_141 -> V_165 ) ;
V_174:
F_69 ( V_2 , V_118 ) ;
V_198:
F_71 ( V_2 , V_118 ) ;
V_162:
F_29 ( & V_2 -> V_127 ) ;
return V_11 ;
}
static void F_92 ( struct V_8 * V_9 , struct V_117 * V_118 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_37 * V_141 = F_31 ( V_118 ) ;
F_74 ( V_2 , V_118 ) ;
F_22 ( & V_2 -> V_127 ) ;
V_141 -> V_199 = false ;
if ( V_118 -> V_168 && V_2 -> V_152 )
F_84 ( V_2 , V_2 -> V_152 ) ;
F_45 ( V_2 , NULL ) ;
F_91 ( V_2 , & V_141 -> V_165 ) ;
F_69 ( V_2 , V_118 ) ;
F_71 ( V_2 , V_118 ) ;
F_29 ( & V_2 -> V_127 ) ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_117 * V_118 ,
struct V_192 * V_189 ,
T_2 V_193 )
{
if ( V_193 & V_201 ) {
if ( F_89 ( V_2 , V_118 ) )
F_94 ( V_2 , L_14 ) ;
}
}
static void F_95 ( struct V_8 * V_9 ,
struct V_117 * V_118 ,
struct V_192 * V_189 ,
T_2 V_193 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_22 ( & V_2 -> V_127 ) ;
switch ( V_118 -> type ) {
case V_42 :
F_83 ( V_2 , V_118 , V_189 , V_193 ) ;
break;
case V_44 :
F_93 ( V_2 , V_118 , V_189 , V_193 ) ;
break;
default:
F_28 ( 1 ) ;
}
F_29 ( & V_2 -> V_127 ) ;
}
static int F_96 ( struct V_8 * V_9 ,
struct V_117 * V_118 ,
struct V_202 * V_203 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
int V_11 ;
if ( V_203 -> V_70 == 0 || V_203 -> V_70 > V_204 )
return - V_131 ;
F_22 ( & V_2 -> V_127 ) ;
if ( V_2 -> V_149 == V_150 )
V_11 = F_97 ( V_2 , V_118 , V_203 ) ;
else
V_11 = - V_205 ;
F_29 ( & V_2 -> V_127 ) ;
return V_11 ;
}
static void F_98 ( struct V_8 * V_9 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_22 ( & V_2 -> V_127 ) ;
F_99 ( V_2 ) ;
F_29 ( & V_2 -> V_127 ) ;
}
static void
F_100 ( struct V_8 * V_9 ,
struct V_121 * V_116 , V_39 V_122 ,
int V_206 ,
enum V_207 V_208 ,
bool V_209 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_101 ( V_2 , V_116 , V_208 , V_206 ) ;
}
static void F_102 ( struct V_8 * V_9 ,
struct V_117 * V_118 ,
enum V_210 V_211 ,
struct V_121 * V_116 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_35 * V_212 = ( void * ) V_116 -> V_213 ;
switch ( V_211 ) {
case V_214 :
if ( F_103 ( & V_2 -> V_215 [ V_212 -> V_216 ] ) > 0 )
F_104 ( V_9 , V_116 , true ) ;
break;
case V_217 :
if ( F_105 ( V_212 -> V_216 == V_144 ) )
break;
F_106 ( V_2 , V_116 ) ;
break;
default:
break;
}
}
static int F_107 ( struct V_8 * V_9 ,
struct V_117 * V_118 ,
struct V_121 * V_116 ,
enum V_218 V_219 ,
enum V_218 V_220 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_37 * V_141 = F_31 ( V_118 ) ;
int V_11 ;
F_60 ( V_2 , L_15 ,
V_116 -> V_57 , V_219 , V_220 ) ;
if ( F_28 ( ! V_141 -> V_148 ) )
return - V_131 ;
F_48 ( & V_2 -> V_180 ) ;
F_22 ( & V_2 -> V_127 ) ;
if ( V_219 == V_221 &&
V_220 == V_222 ) {
if ( V_118 -> type == V_42 &&
V_118 -> V_189 . V_223 < 16 ) {
F_46 ( V_2 ,
L_16 ,
V_116 -> V_57 , V_118 -> V_189 . V_223 ) ;
V_11 = - V_131 ;
goto V_162;
}
V_11 = F_108 ( V_2 , V_118 , V_116 ) ;
} else if ( V_219 == V_222 &&
V_220 == V_224 ) {
V_11 = 0 ;
} else if ( V_219 == V_224 &&
V_220 == V_225 ) {
V_11 = F_109 ( V_2 , V_118 , V_116 ) ;
if ( V_11 == 0 )
F_110 ( V_2 , V_116 ,
V_141 -> V_148 -> V_226 -> V_227 ) ;
} else if ( V_219 == V_225 &&
V_220 == V_228 ) {
F_105 ( F_111 ( V_2 , V_118 ) ) ;
V_11 = 0 ;
} else if ( V_219 == V_228 &&
V_220 == V_225 ) {
F_105 ( F_64 ( V_2 , V_118 ) ) ;
V_11 = 0 ;
} else if ( V_219 == V_225 &&
V_220 == V_224 ) {
V_11 = 0 ;
} else if ( V_219 == V_224 &&
V_220 == V_222 ) {
V_11 = 0 ;
} else if ( V_219 == V_222 &&
V_220 == V_221 ) {
V_11 = F_112 ( V_2 , V_118 , V_116 ) ;
} else {
V_11 = - V_229 ;
}
V_162:
F_29 ( & V_2 -> V_127 ) ;
return V_11 ;
}
static int F_113 ( struct V_8 * V_9 , T_2 V_230 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
V_2 -> V_82 = V_230 ;
return 0 ;
}
static int F_114 ( struct V_8 * V_9 ,
struct V_117 * V_118 , V_39 V_176 ,
const struct V_231 * V_232 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_37 * V_141 = F_31 ( V_118 ) ;
V_141 -> V_233 [ V_176 ] = * V_232 ;
if ( V_118 -> type == V_46 ) {
int V_11 ;
F_22 ( & V_2 -> V_127 ) ;
V_11 = F_84 ( V_2 , V_118 ) ;
F_29 ( & V_2 -> V_127 ) ;
return V_11 ;
}
return 0 ;
}
static void F_115 ( struct V_8 * V_9 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
T_2 V_234 = F_5 ( V_235 ,
200 + V_118 -> V_189 . V_223 ) ;
T_2 V_236 = F_5 ( V_237 ,
100 + V_118 -> V_189 . V_223 ) ;
if ( F_28 ( V_118 -> V_189 . V_195 ) )
return;
F_22 ( & V_2 -> V_127 ) ;
F_116 ( V_2 , V_118 , V_234 , V_236 ) ;
F_29 ( & V_2 -> V_127 ) ;
}
static int F_117 ( struct V_8 * V_9 ,
enum V_238 V_211 ,
struct V_117 * V_118 ,
struct V_121 * V_116 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
int V_11 ;
if ( V_31 . V_32 ) {
F_60 ( V_2 , L_17 ) ;
return - V_241 ;
}
switch ( V_240 -> V_242 ) {
case V_243 :
V_240 -> V_12 |= V_244 ;
case V_245 :
V_240 -> V_12 |= V_246 ;
break;
case V_247 :
F_28 ( ! ( V_9 -> V_12 & V_33 ) ) ;
break;
case V_248 :
case V_249 :
return 0 ;
default:
return - V_241 ;
}
F_22 ( & V_2 -> V_127 ) ;
switch ( V_211 ) {
case V_250 :
if ( V_118 -> type == V_44 && ! V_116 ) {
V_11 = 0 ;
V_240 -> V_251 = V_252 ;
break;
}
F_60 ( V_2 , L_18 ) ;
V_11 = F_118 ( V_2 , V_118 , V_116 , V_240 , false ) ;
if ( V_11 ) {
F_94 ( V_2 , L_19 ) ;
V_240 -> V_251 = V_252 ;
V_11 = 0 ;
}
break;
case V_253 :
if ( V_240 -> V_251 == V_252 ) {
V_11 = 0 ;
break;
}
F_60 ( V_2 , L_20 ) ;
V_11 = F_119 ( V_2 , V_118 , V_116 , V_240 ) ;
break;
default:
V_11 = - V_131 ;
}
F_29 ( & V_2 -> V_127 ) ;
return V_11 ;
}
static void F_120 ( struct V_8 * V_9 ,
struct V_117 * V_118 ,
struct V_239 * V_254 ,
struct V_121 * V_116 ,
T_2 V_255 , V_39 * V_256 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_121 ( V_2 , V_118 , V_254 , V_116 , V_255 , V_256 ) ;
}
static int F_122 ( struct V_8 * V_9 ,
struct V_117 * V_118 ,
struct V_257 * V_226 ,
int V_234 ,
enum V_258 type )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_37 * V_141 = F_31 ( V_118 ) ;
struct V_259 V_260 ;
struct V_161 * V_148 ;
int V_11 , V_3 ;
F_60 ( V_2 , L_21 , V_226 -> V_261 ,
V_234 , type ) ;
if ( V_118 -> type != V_46 ) {
F_46 ( V_2 , L_22 , V_118 -> type ) ;
return - V_131 ;
}
F_22 ( & V_2 -> V_127 ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_148 = & V_2 -> V_4 [ V_3 ] ;
if ( V_148 -> V_7 == 0 || V_141 -> V_148 == V_148 )
continue;
if ( V_148 -> V_7 && V_226 == V_148 -> V_226 ) {
V_11 = F_69 ( V_2 , V_118 ) ;
if ( F_123 ( V_11 , L_23 ) )
goto V_162;
F_70 ( V_2 , V_141 -> V_148 ) ;
V_141 -> V_148 = V_148 ;
V_11 = F_66 ( V_2 , V_118 ) ;
if ( F_123 ( V_11 , L_24 ) )
goto V_162;
F_65 ( V_2 , V_141 -> V_148 ) ;
goto V_262;
}
}
if ( V_226 == V_141 -> V_148 -> V_226 )
goto V_262;
F_124 ( & V_260 , V_226 , V_263 ) ;
if ( V_141 -> V_148 -> V_7 == 1 ) {
V_11 = F_125 ( V_2 , V_141 -> V_148 ,
& V_260 , 1 , 1 ) ;
if ( V_11 )
goto V_162;
} else {
V_148 = F_56 ( V_2 ) ;
if ( ! V_148 ) {
V_11 = - V_171 ;
goto V_162;
}
V_11 = F_125 ( V_2 , V_148 , & V_260 ,
1 , 1 ) ;
if ( V_11 ) {
F_46 ( V_2 , L_25 ) ;
goto V_162;
}
V_11 = F_69 ( V_2 , V_118 ) ;
if ( F_123 ( V_11 , L_23 ) )
goto V_162;
F_70 ( V_2 , V_141 -> V_148 ) ;
V_141 -> V_148 = V_148 ;
V_11 = F_66 ( V_2 , V_118 ) ;
if ( F_123 ( V_11 , L_24 ) )
goto V_162;
F_65 ( V_2 , V_141 -> V_148 ) ;
}
V_262:
V_11 = F_126 ( V_2 , V_118 , V_234 , type ) ;
V_162:
F_29 ( & V_2 -> V_127 ) ;
F_60 ( V_2 , L_26 ) ;
return V_11 ;
}
static int F_127 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_60 ( V_2 , L_27 ) ;
F_22 ( & V_2 -> V_127 ) ;
F_128 ( V_2 ) ;
F_29 ( & V_2 -> V_127 ) ;
F_60 ( V_2 , L_26 ) ;
return 0 ;
}
static int F_129 ( struct V_8 * V_9 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
V_39 * V_266 = ( V_39 * ) V_265 -> V_213 ;
struct V_161 * V_148 ;
int V_11 ;
F_60 ( V_2 , L_28 ) ;
F_22 ( & V_2 -> V_127 ) ;
V_148 = F_56 ( V_2 ) ;
if ( ! V_148 ) {
V_11 = - V_171 ;
goto V_267;
}
V_11 = F_125 ( V_2 , V_148 , & V_265 -> V_268 ,
V_265 -> V_269 ,
V_265 -> V_270 ) ;
if ( V_11 ) {
F_46 ( V_2 , L_29 ) ;
goto V_267;
}
F_65 ( V_2 , V_148 ) ;
* V_266 = V_148 -> V_6 ;
V_267:
F_29 ( & V_2 -> V_127 ) ;
return V_11 ;
}
static void F_130 ( struct V_8 * V_9 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
V_39 * V_266 = ( V_39 * ) V_265 -> V_213 ;
struct V_161 * V_148 = & V_2 -> V_4 [ * V_266 ] ;
F_22 ( & V_2 -> V_127 ) ;
F_70 ( V_2 , V_148 ) ;
F_29 ( & V_2 -> V_127 ) ;
}
static void F_131 ( struct V_8 * V_9 ,
struct V_264 * V_265 ,
T_2 V_181 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
V_39 * V_266 = ( V_39 * ) V_265 -> V_213 ;
struct V_161 * V_148 = & V_2 -> V_4 [ * V_266 ] ;
if ( F_132 ( ( V_148 -> V_7 > 1 ) &&
( V_181 & ~ ( V_271 |
V_272 |
V_273 ) ) ,
L_30 ,
V_148 -> V_7 , V_181 ) )
return;
F_22 ( & V_2 -> V_127 ) ;
F_125 ( V_2 , V_148 , & V_265 -> V_268 ,
V_265 -> V_269 ,
V_265 -> V_270 ) ;
F_29 ( & V_2 -> V_127 ) ;
}
static int F_133 ( struct V_8 * V_9 ,
struct V_117 * V_118 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
V_39 * V_266 = ( V_39 * ) V_265 -> V_213 ;
struct V_161 * V_148 = & V_2 -> V_4 [ * V_266 ] ;
struct V_37 * V_141 = F_31 ( V_118 ) ;
int V_11 ;
F_22 ( & V_2 -> V_127 ) ;
V_141 -> V_148 = V_148 ;
switch ( V_118 -> type ) {
case V_44 :
V_11 = 0 ;
goto V_162;
case V_42 :
case V_274 :
case V_275 :
break;
default:
V_11 = - V_131 ;
goto V_162;
}
V_11 = F_66 ( V_2 , V_118 ) ;
if ( V_11 )
goto V_162;
if ( V_118 -> type == V_275 ) {
V_141 -> V_276 = true ;
V_11 = F_45 ( V_2 , V_118 ) ;
if ( V_11 )
goto V_277;
}
goto V_162;
V_277:
F_69 ( V_2 , V_118 ) ;
V_162:
F_29 ( & V_2 -> V_127 ) ;
if ( V_11 )
V_141 -> V_148 = NULL ;
return V_11 ;
}
static void F_134 ( struct V_8 * V_9 ,
struct V_117 * V_118 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_37 * V_141 = F_31 ( V_118 ) ;
F_22 ( & V_2 -> V_127 ) ;
F_87 ( V_2 , V_141 , & V_141 -> V_147 ) ;
if ( V_118 -> type == V_44 )
goto V_162;
switch ( V_118 -> type ) {
case V_275 :
V_141 -> V_276 = false ;
F_45 ( V_2 , NULL ) ;
break;
default:
break;
}
F_69 ( V_2 , V_118 ) ;
V_162:
V_141 -> V_148 = NULL ;
F_29 ( & V_2 -> V_127 ) ;
}
static int F_135 ( struct V_8 * V_9 ,
struct V_121 * V_116 ,
bool V_278 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_35 * V_279 = ( void * ) V_116 -> V_213 ;
if ( ! V_279 || ! V_279 -> V_118 ) {
F_46 ( V_2 , L_31 ) ;
return - V_131 ;
}
return F_89 ( V_2 , V_279 -> V_118 ) ;
}
static void F_136 ( struct V_8 * V_9 ,
struct V_117 * V_118 ,
enum V_280 V_281 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_137 ( V_2 , V_118 , V_281 ) ;
}
