static bool F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_3 ( V_5 , L_1 ,
V_2 -> V_4 ) ;
return false ;
}
return true ;
}
static T_1 F_4 ( T_2 V_6 )
{
T_3 V_7 = 1 ;
int V_8 = V_6 - V_9 ;
if ( V_8 >= V_10 )
return 0xFFFF ;
while ( V_8 < 0 ) {
V_8 += 40 ;
V_7 *= 10 ;
}
return ( V_11 [ V_8 ] + V_7 / 2 ) / V_7 ;
}
static T_2 F_5 ( T_1 V_12 )
{
T_2 V_6 ;
int V_13 ;
T_3 V_14 = V_12 ;
T_3 V_15 ;
if ( V_14 <= 1 )
return 0 ;
V_13 = V_9 ;
while ( V_14 < V_16 ) {
V_14 *= 10 ;
V_13 -= 40 ;
}
for ( V_6 = 0 ; V_6 < V_10 - 1 ; V_6 ++ ) {
V_15 = V_11 [ V_6 ] + ( V_11 [ V_6 + 1 ] -
V_11 [ V_6 ] ) / 2 ;
if ( V_14 < V_15 )
break;
}
V_6 += ( T_2 ) V_13 ;
return V_6 ;
}
static T_1 F_6 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 V_22 ;
T_4 V_23 ;
F_3 ( V_24 , L_2 ,
V_20 -> V_25 -> V_26 , V_20 -> V_27 , V_20 -> V_28 ) ;
V_22 . V_29 = F_7 ( V_20 -> V_27 ) ;
V_23 = V_20 -> V_27 - V_20 -> V_25 -> V_26 ;
switch ( V_20 -> V_28 ) {
case V_30 :
case V_31 :
V_22 . V_32 = V_33 ;
F_8 ( V_23 != 0 ) ;
break;
case V_34 :
V_22 . V_32 = V_35 ;
if ( V_23 < 0 )
V_22 . V_36 = V_37 ;
else
V_22 . V_36 = V_38 ;
break;
case V_39 :
V_22 . V_32 = V_40 ;
if ( V_23 < 0 ) {
if ( V_23 < - V_41 )
V_22 . V_36 = V_42 ;
else
V_22 . V_36 = V_43 ;
} else {
if ( V_23 > V_41 )
V_22 . V_36 = V_44 ;
else
V_22 . V_36 = V_45 ;
}
break;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
default:
F_9 ( 1 ) ;
}
switch ( V_20 -> V_25 -> V_50 ) {
case V_51 :
V_22 . V_50 = V_52 ;
break;
case V_53 :
V_22 . V_50 = V_54 ;
break;
case V_55 :
default:
F_9 ( 1 ) ;
}
V_18 -> V_56 ( & V_22 ) ;
return V_22 . V_57 ;
}
T_1 F_10 ( struct V_17 * V_18 ,
struct V_58 * V_20 )
{
struct V_21 V_22 ;
V_22 . V_29 = F_7 ( V_20 -> V_26 ) ;
V_22 . V_32 = V_33 ;
V_18 -> V_56 ( & V_22 ) ;
return V_22 . V_57 ;
}
const struct V_59 *
F_11 ( const void * V_60 , int V_61 , T_3 V_62 )
{
const struct V_59 * V_63 = V_60 ;
int V_64 = V_61 ;
while ( V_64 >= V_65 ) {
int V_66 = V_63 -> V_66 ;
if ( ( V_63 -> V_67 == V_62 ) && ( V_64 >= ( V_66 + V_65 ) ) )
return V_63 ;
V_63 = (struct V_59 * ) ( ( T_2 * ) V_63 + ( V_66 + V_65 ) ) ;
V_64 -= ( V_66 + V_65 ) ;
}
return NULL ;
}
static bool
F_12 ( const T_2 * V_68 , const T_2 * * V_69 , T_5 * V_70 ,
const T_2 * V_71 , T_5 V_72 , T_2 type )
{
if ( V_68 [ V_73 ] >= V_72 + 1 &&
! memcmp ( & V_68 [ V_74 ] , V_71 , V_72 ) &&
type == V_68 [ V_74 + V_72 ] ) {
return true ;
}
if ( V_69 == NULL )
return false ;
V_68 += V_68 [ V_73 ] + V_65 ;
* V_70 -= ( int ) ( V_68 - * V_69 ) ;
* V_69 = V_68 ;
return false ;
}
static struct V_75 *
F_13 ( const T_2 * V_76 , T_5 V_66 )
{
const struct V_59 * V_68 ;
while ( ( V_68 = F_11 ( V_76 , V_66 , V_77 ) ) ) {
if ( F_12 ( ( const T_2 * ) V_68 , & V_76 , & V_66 ,
V_78 , V_79 , V_80 ) )
return (struct V_75 * ) V_68 ;
}
return NULL ;
}
static struct V_75 *
F_14 ( const T_2 * V_76 , T_5 V_66 )
{
const struct V_59 * V_68 ;
while ( ( V_68 = F_11 ( V_76 , V_66 , V_77 ) ) ) {
if ( F_12 ( ( T_2 * ) V_68 , & V_76 , & V_66 ,
V_78 , V_79 , V_81 ) )
return (struct V_75 * ) V_68 ;
}
return NULL ;
}
static void F_15 ( struct V_82 * V_62 ,
struct V_83 * V_84 )
{
V_84 -> V_85 = F_16 ( V_62 -> V_85 ) ;
V_84 -> V_66 = F_16 ( V_62 -> V_66 ) ;
V_84 -> V_86 = F_16 ( V_62 -> V_86 ) ;
V_84 -> V_87 = F_16 ( V_62 -> V_87 ) ;
V_84 -> V_88 . V_89 = F_16 ( V_62 -> V_88 . V_89 ) ;
V_84 -> V_88 . V_90 = F_17 ( V_62 -> V_88 . V_90 ) ;
V_84 -> V_91 = F_16 ( V_62 -> V_91 ) ;
memcpy ( V_84 -> V_92 , V_62 -> V_92 , sizeof( V_62 -> V_92 ) ) ;
memcpy ( V_84 -> V_93 , V_62 -> V_93 , sizeof( V_62 -> V_93 ) ) ;
}
static int
F_18 ( struct V_94 * V_95 , struct V_82 * V_62 )
{
int V_96 ;
struct V_83 V_84 ;
F_15 ( V_62 , & V_84 ) ;
F_19 ( V_95 ) ;
V_96 = F_20 ( F_21 ( V_95 ) , L_3 , & V_84 ,
sizeof( V_84 ) ) ;
if ( V_96 )
F_22 ( L_4 , V_96 ) ;
return V_96 ;
}
static T_4
F_23 ( struct V_97 * V_98 , bool V_99 )
{
T_4 V_96 ;
T_5 V_100 ;
if ( V_99 )
V_100 = V_101 | V_102 ;
else
V_100 = 0 ;
V_96 = F_24 ( V_98 , L_5 , V_100 ) ;
if ( V_96 ) {
F_3 ( V_24 , L_6 ,
V_100 , V_96 ) ;
V_96 = 0 ;
} else {
V_96 = F_24 ( V_98 , L_7 , V_99 ) ;
if ( V_96 ) {
F_3 ( V_24 , L_8 ,
V_99 , V_96 ) ;
V_96 = 0 ;
} else
F_3 ( V_24 , L_9 ,
V_99 , V_100 ) ;
}
return V_96 ;
}
static void
F_25 ( struct V_103 * V_104 )
{
struct V_1 * V_2 ;
struct V_97 * V_98 ;
V_2 = F_26 ( V_104 , struct V_1 , V_104 ) ;
V_98 = V_2 -> V_98 ;
if ( ( V_104 -> V_105 == V_106 ) ||
( V_104 -> V_105 == V_107 ) ||
( V_104 -> V_105 == V_108 ) )
F_27 ( V_98 -> V_109 , V_98 -> V_110 ,
V_111 ) ;
else
F_27 ( V_98 -> V_109 , V_98 -> V_110 ,
V_112 ) ;
}
static bool F_28 ( struct V_1 * V_2 )
{
enum V_113 V_105 ;
V_105 = V_2 -> V_104 . V_105 ;
return V_105 == V_107 || V_105 == V_108 ;
}
static bool F_29 ( struct V_1 * V_2 )
{
return V_2 -> V_104 . V_105 == V_106 ;
}
static struct V_103 * F_30 ( struct V_114 * V_114 ,
const char * V_115 ,
enum V_113 type ,
T_5 * V_87 ,
struct V_116 * V_117 )
{
struct V_103 * V_104 ;
F_3 ( V_24 , L_10 , V_115 , type ) ;
switch ( type ) {
case V_106 :
case V_118 :
case V_107 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
return F_31 ( - V_123 ) ;
case V_124 :
case V_108 :
case V_125 :
V_104 = F_32 ( V_114 , V_115 , type , V_87 , V_117 ) ;
if ( ! F_33 ( V_104 ) )
F_25 ( V_104 ) ;
return V_104 ;
case V_126 :
default:
return F_31 ( - V_127 ) ;
}
}
static void F_34 ( struct V_97 * V_98 , int V_128 )
{
if ( F_35 ( V_98 , V_129 ) )
F_36 ( V_98 , V_128 ) ;
}
void F_36 ( struct V_97 * V_98 , int V_128 )
{
T_4 V_96 = 0 ;
if ( F_1 ( V_98 -> V_2 ) ) {
V_96 = F_24 ( V_98 , L_11 , V_128 ) ;
if ( V_96 ) {
F_22 ( L_12 ) ;
return;
}
F_3 ( V_5 , L_13 , V_128 ) ;
}
}
T_4 F_37 ( struct V_130 * V_131 ,
struct V_97 * V_98 , bool V_132 ,
bool V_133 )
{
struct V_134 V_135 ;
struct V_136 * V_137 ;
T_4 V_96 = 0 ;
F_3 ( V_138 , L_14 ) ;
V_137 = V_131 -> V_137 ;
V_131 -> V_137 = NULL ;
if ( F_38 ( & V_131 -> V_139 ) )
F_39 ( & V_131 -> V_139 ) ;
if ( V_133 ) {
F_3 ( V_138 , L_15 ) ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
memset ( V_135 . V_140 , 0xFF , V_141 ) ;
V_135 . V_142 = V_143 ;
V_135 . V_144 = 0 ;
V_135 . V_145 = F_16 ( 1 ) ;
V_135 . V_146 = F_16 ( 1 ) ;
V_135 . V_147 = F_16 ( - 1 ) ;
V_135 . V_148 = F_16 ( - 1 ) ;
V_135 . V_149 = F_16 ( - 1 ) ;
V_135 . V_150 [ 0 ] = F_17 ( - 1 ) ;
V_96 = F_40 ( V_98 , V_151 ,
& V_135 , sizeof( V_135 ) ) ;
if ( V_96 )
F_22 ( L_16 ) ;
}
F_34 ( V_98 , 1 ) ;
if ( V_131 -> V_152 ) {
F_3 ( V_138 , L_17 ) ;
V_131 -> V_152 = false ;
if ( ! V_132 )
F_41 ( F_42 ( V_131 ) ) ;
} else if ( V_137 ) {
F_3 ( V_138 , L_18 ,
V_132 ? L_19 : L_20 ) ;
F_43 ( V_137 , V_132 ) ;
}
if ( ! F_44 ( V_153 , & V_131 -> V_154 ) )
F_3 ( V_138 , L_21 ) ;
return V_96 ;
}
static
int F_45 ( struct V_114 * V_114 , struct V_103 * V_104 )
{
struct V_130 * V_131 = F_46 ( V_114 ) ;
struct V_94 * V_95 = V_104 -> V_155 ;
if ( F_47 ( V_131 ) )
return - V_156 ;
if ( V_95 ) {
if ( F_2 ( V_153 , & V_131 -> V_154 ) &&
V_131 -> V_157 . V_98 == F_21 ( V_95 ) )
F_37 ( V_131 , F_21 ( V_95 ) ,
true , true ) ;
F_24 ( F_21 ( V_95 ) , L_11 , 1 ) ;
}
switch ( V_104 -> V_105 ) {
case V_106 :
case V_118 :
case V_107 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
return - V_123 ;
case V_124 :
case V_108 :
case V_125 :
return F_48 ( V_114 , V_104 ) ;
case V_126 :
default:
return - V_127 ;
}
return - V_123 ;
}
static T_4
F_49 ( struct V_114 * V_114 , struct V_94 * V_95 ,
enum V_113 type , T_5 * V_87 ,
struct V_116 * V_117 )
{
struct V_130 * V_131 = F_46 ( V_114 ) ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_1 * V_2 = V_98 -> V_2 ;
T_4 V_158 = 0 ;
T_4 V_159 = 0 ;
T_4 V_96 = 0 ;
F_3 ( V_24 , L_22 , V_95 , type ) ;
switch ( type ) {
case V_121 :
case V_120 :
F_22 ( L_23 ,
type ) ;
return - V_123 ;
case V_106 :
V_158 = 0 ;
break;
case V_118 :
if ( ( V_2 -> V_104 . V_105 == V_124 ) ||
( V_2 -> V_104 . V_105 == V_108 ) ) {
F_3 ( V_24 , L_24 ) ;
return 0 ;
}
V_158 = 1 ;
break;
case V_107 :
case V_108 :
V_159 = 1 ;
break;
default:
V_96 = - V_127 ;
goto V_160;
}
if ( V_159 ) {
if ( type == V_108 ) {
F_3 ( V_5 , L_25 ) ;
V_96 = F_50 ( V_131 , V_161 ) ;
}
if ( ! V_96 ) {
F_51 ( V_162 , & V_2 -> V_4 ) ;
F_3 ( V_5 , L_26 ) ;
}
} else {
V_96 = F_52 ( V_98 , V_163 , V_158 ) ;
if ( V_96 ) {
F_22 ( L_27 , V_96 ) ;
V_96 = - V_164 ;
goto V_160;
}
F_3 ( V_5 , L_28 , F_29 ( V_2 ) ?
L_29 : L_30 ) ;
}
V_95 -> V_165 -> V_105 = type ;
F_25 ( & V_2 -> V_104 ) ;
V_160:
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static void F_53 ( struct V_130 * V_131 ,
struct V_134 * V_135 ,
struct V_136 * V_166 )
{
T_5 V_167 ;
T_5 V_168 ;
T_4 V_169 ;
T_4 V_13 ;
T_1 V_170 ;
char * V_171 ;
struct V_172 V_173 ;
memset ( V_135 -> V_140 , 0xFF , V_141 ) ;
V_135 -> V_142 = V_143 ;
V_135 -> V_144 = 0 ;
V_135 -> V_145 = 0 ;
V_135 -> V_146 = F_16 ( - 1 ) ;
V_135 -> V_147 = F_16 ( - 1 ) ;
V_135 -> V_148 = F_16 ( - 1 ) ;
V_135 -> V_149 = F_16 ( - 1 ) ;
memset ( & V_135 -> V_173 , 0 , sizeof( V_135 -> V_173 ) ) ;
if ( ! V_166 )
return;
V_167 = V_166 -> V_167 ;
V_168 = V_166 -> V_168 ;
F_3 ( V_138 , L_32 ,
V_168 ) ;
if ( V_168 > 0 ) {
for ( V_169 = 0 ; V_169 < V_168 ; V_169 ++ ) {
V_170 = F_10 ( & V_131 -> V_18 ,
V_166 -> V_174 [ V_169 ] ) ;
F_3 ( V_138 , L_33 ,
V_166 -> V_174 [ V_169 ] -> V_175 , V_170 ) ;
V_135 -> V_150 [ V_169 ] = F_17 ( V_170 ) ;
}
} else {
F_3 ( V_138 , L_34 ) ;
}
F_3 ( V_138 , L_35 , V_167 ) ;
if ( V_167 > 0 ) {
V_13 = F_54 ( struct V_134 , V_150 ) +
V_168 * sizeof( T_1 ) ;
V_13 = F_55 ( V_13 , sizeof( T_5 ) ) ;
V_171 = ( char * ) V_135 + V_13 ;
for ( V_169 = 0 ; V_169 < V_167 ; V_169 ++ ) {
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_173 . V_176 =
F_16 ( V_166 -> V_177 [ V_169 ] . V_178 ) ;
memcpy ( V_173 . V_179 , V_166 -> V_177 [ V_169 ] . V_180 ,
V_166 -> V_177 [ V_169 ] . V_178 ) ;
if ( ! V_173 . V_176 )
F_3 ( V_138 , L_36 , V_169 ) ;
else
F_3 ( V_138 , L_37 ,
V_169 , V_173 . V_179 , V_173 . V_176 ) ;
memcpy ( V_171 , & V_173 , sizeof( V_173 ) ) ;
V_171 += sizeof( V_173 ) ;
}
} else {
F_3 ( V_138 , L_38 , V_166 -> V_177 ) ;
if ( ( V_166 -> V_177 ) && V_166 -> V_177 -> V_178 ) {
F_3 ( V_138 , L_39 ,
V_135 -> V_173 . V_179 ,
V_166 -> V_177 -> V_178 ) ;
V_135 -> V_173 . V_176 =
F_16 ( V_166 -> V_177 -> V_178 ) ;
memcpy ( & V_135 -> V_173 . V_179 , V_166 -> V_177 -> V_180 ,
V_166 -> V_177 -> V_178 ) ;
}
}
V_135 -> V_145 =
F_16 ( ( V_167 << V_181 ) |
( V_168 & V_182 ) ) ;
}
static T_4
F_56 ( struct V_130 * V_131 , struct V_97 * V_98 ,
struct V_136 * V_166 , T_1 V_183 )
{
T_4 V_184 = V_185 +
F_54 ( struct V_186 , V_135 ) ;
struct V_186 * V_117 ;
T_4 V_96 = 0 ;
F_3 ( V_138 , L_40 ) ;
if ( V_166 != NULL ) {
V_184 += sizeof( T_5 ) * ( ( V_166 -> V_168 + 1 ) / 2 ) ;
V_184 += sizeof( struct V_187 ) * V_166 -> V_167 ;
}
V_117 = F_57 ( V_184 , V_188 ) ;
if ( ! V_117 ) {
V_96 = - V_189 ;
goto exit;
}
F_58 ( V_184 + sizeof( L_41 ) >= V_190 ) ;
F_53 ( V_131 , & V_117 -> V_135 , V_166 ) ;
V_117 -> V_191 = F_16 ( V_192 ) ;
V_117 -> V_183 = F_17 ( V_183 ) ;
V_117 -> V_193 = F_17 ( 0x1234 ) ;
V_96 = F_59 ( V_98 , L_41 , V_117 , V_184 ) ;
if ( V_96 ) {
if ( V_96 == - V_156 )
F_3 ( V_5 , L_42 ) ;
else
F_22 ( L_43 , V_96 ) ;
}
F_60 ( V_117 ) ;
exit:
return V_96 ;
}
static T_4
F_61 ( struct V_130 * V_131 , struct V_114 * V_114 ,
struct V_97 * V_98 , struct V_136 * V_166 )
{
T_4 V_96 ;
T_5 V_194 ;
struct V_195 * V_196 ;
struct V_157 * V_197 = & V_131 -> V_157 ;
F_3 ( V_138 , L_14 ) ;
V_197 -> V_98 = V_98 ;
V_197 -> V_114 = V_114 ;
V_197 -> V_198 = V_199 ;
V_194 = V_131 -> V_200 ? 0 : 1 ;
V_96 = F_52 ( V_98 , V_201 ,
V_194 ) ;
if ( V_96 ) {
F_22 ( L_43 , V_96 ) ;
return V_96 ;
}
F_34 ( V_98 , 0 ) ;
V_196 = (struct V_195 * ) V_131 -> V_157 . V_202 ;
V_196 -> V_191 = 0 ;
V_196 -> V_203 = 0 ;
V_196 -> V_61 = V_204 ;
V_96 = V_197 -> V_205 ( V_131 , V_98 , V_166 , V_206 ) ;
if ( V_96 )
F_34 ( V_98 , 1 ) ;
return V_96 ;
}
static T_4
F_62 ( struct V_114 * V_114 , struct V_1 * V_2 ,
struct V_136 * V_166 ,
struct V_207 * V_208 )
{
struct V_97 * V_98 = V_2 -> V_98 ;
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_207 * V_177 ;
struct V_209 * V_210 = & V_131 -> V_211 ;
T_5 V_194 ;
bool V_212 ;
bool V_213 ;
T_4 V_96 ;
T_5 V_176 ;
F_3 ( V_138 , L_44 ) ;
if ( F_2 ( V_153 , & V_131 -> V_154 ) ) {
F_22 ( L_45 , V_131 -> V_154 ) ;
return - V_164 ;
}
if ( F_2 ( V_214 , & V_131 -> V_154 ) ) {
F_22 ( L_46 ,
V_131 -> V_154 ) ;
return - V_164 ;
}
if ( F_2 ( V_215 , & V_131 -> V_154 ) ) {
F_22 ( L_47 ,
V_131 -> V_154 ) ;
return - V_164 ;
}
if ( F_2 ( V_216 , & V_98 -> V_2 -> V_4 ) ) {
F_22 ( L_48 , V_98 -> V_2 -> V_4 ) ;
return - V_164 ;
}
if ( V_2 == V_131 -> V_217 . V_218 [ V_219 ] . V_2 )
V_2 = V_131 -> V_217 . V_218 [ V_220 ] . V_2 ;
F_64 ( & V_131 -> V_139 , V_221 +
V_222 * V_223 / 1000 ) ;
V_212 = false ;
if ( V_166 ) {
V_177 = V_166 -> V_177 ;
V_212 = true ;
} else {
V_177 = V_208 ;
}
V_131 -> V_137 = V_166 ;
F_51 ( V_153 , & V_131 -> V_154 ) ;
if ( V_212 ) {
V_131 -> V_157 . V_205 = F_56 ;
V_96 = F_65 ( V_114 , V_166 , V_2 ) ;
if ( V_96 )
goto V_224;
V_96 = F_61 ( V_131 , V_114 , V_2 -> V_98 , V_166 ) ;
if ( V_96 )
goto V_224;
} else {
F_3 ( V_138 , L_49 ,
V_177 -> V_180 , V_177 -> V_178 ) ;
memset ( & V_210 -> V_173 , 0 , sizeof( V_210 -> V_173 ) ) ;
V_176 = F_66 ( T_2 , sizeof( V_210 -> V_173 . V_179 ) , V_177 -> V_178 ) ;
V_210 -> V_173 . V_176 = F_16 ( 0 ) ;
V_213 = false ;
if ( V_176 ) {
memcpy ( V_210 -> V_173 . V_179 , V_177 -> V_180 , V_176 ) ;
V_210 -> V_173 . V_176 = F_16 ( V_176 ) ;
V_213 = true ;
} else
F_3 ( V_138 , L_50 ) ;
V_194 = V_131 -> V_200 ? 0 : 1 ;
V_96 = F_52 ( V_98 , V_201 ,
V_194 ) ;
if ( V_96 ) {
F_22 ( L_51 , V_96 ) ;
goto V_224;
}
F_34 ( V_98 , 0 ) ;
V_96 = F_40 ( V_98 , V_151 ,
& V_210 -> V_173 , sizeof( V_210 -> V_173 ) ) ;
if ( V_96 ) {
if ( V_96 == - V_156 )
F_3 ( V_5 , L_52 ,
V_210 -> V_173 . V_179 ) ;
else
F_22 ( L_53 , V_96 ) ;
F_34 ( V_98 , 1 ) ;
goto V_224;
}
}
return 0 ;
V_224:
F_67 ( V_153 , & V_131 -> V_154 ) ;
if ( F_38 ( & V_131 -> V_139 ) )
F_39 ( & V_131 -> V_139 ) ;
V_131 -> V_137 = NULL ;
return V_96 ;
}
static T_4
F_68 ( struct V_114 * V_114 , struct V_136 * V_166 )
{
struct V_1 * V_2 ;
T_4 V_96 = 0 ;
F_3 ( V_24 , L_14 ) ;
V_2 = F_26 ( V_166 -> V_104 , struct V_1 , V_104 ) ;
if ( ! F_1 ( V_2 ) )
return - V_225 ;
V_96 = F_62 ( V_114 , V_2 , V_166 , NULL ) ;
if ( V_96 )
F_22 ( L_54 , V_96 ) ;
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4 F_69 ( struct V_94 * V_95 , T_5 V_226 )
{
T_4 V_96 = 0 ;
V_96 = F_24 ( F_21 ( V_95 ) , L_55 ,
V_226 ) ;
if ( V_96 )
F_22 ( L_56 , V_96 ) ;
return V_96 ;
}
static T_4 F_70 ( struct V_94 * V_95 , T_5 V_227 )
{
T_4 V_96 = 0 ;
V_96 = F_24 ( F_21 ( V_95 ) , L_57 ,
V_227 ) ;
if ( V_96 )
F_22 ( L_56 , V_96 ) ;
return V_96 ;
}
static T_4 F_71 ( struct V_94 * V_95 , T_5 V_228 , bool V_229 )
{
T_4 V_96 = 0 ;
T_5 V_230 = ( V_229 ? V_231 : V_232 ) ;
V_96 = F_52 ( F_21 ( V_95 ) , V_230 , V_228 ) ;
if ( V_96 ) {
F_22 ( L_58 , V_230 , V_96 ) ;
return V_96 ;
}
return V_96 ;
}
static T_4 F_72 ( struct V_114 * V_114 , T_5 V_233 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_94 * V_95 = F_73 ( V_131 ) ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
T_4 V_96 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
if ( V_233 & V_234 &&
( V_131 -> V_235 -> V_226 != V_114 -> V_226 ) ) {
V_131 -> V_235 -> V_226 = V_114 -> V_226 ;
V_96 = F_69 ( V_95 , V_131 -> V_235 -> V_226 ) ;
if ( ! V_96 )
goto V_160;
}
if ( V_233 & V_236 &&
( V_131 -> V_235 -> V_227 != V_114 -> V_227 ) ) {
V_131 -> V_235 -> V_227 = V_114 -> V_227 ;
V_96 = F_70 ( V_95 , V_131 -> V_235 -> V_227 ) ;
if ( ! V_96 )
goto V_160;
}
if ( V_233 & V_237
&& ( V_131 -> V_235 -> V_238 != V_114 -> V_238 ) ) {
V_131 -> V_235 -> V_238 = V_114 -> V_238 ;
V_96 = F_71 ( V_95 , V_131 -> V_235 -> V_238 , true ) ;
if ( ! V_96 )
goto V_160;
}
if ( V_233 & V_239
&& ( V_131 -> V_235 -> V_240 != V_114 -> V_240 ) ) {
V_131 -> V_235 -> V_240 = V_114 -> V_240 ;
V_96 = F_71 ( V_95 , V_131 -> V_235 -> V_240 , false ) ;
if ( ! V_96 )
goto V_160;
}
V_160:
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static void F_74 ( struct V_241 * V_242 )
{
memset ( V_242 , 0 , sizeof( * V_242 ) ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_130 * V_131 = F_63 ( V_2 -> V_104 . V_114 ) ;
T_4 V_96 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( F_2 ( V_243 , & V_2 -> V_4 ) ) {
F_3 ( V_5 , L_59 ) ;
V_96 = F_40 ( V_2 -> V_98 ,
V_244 , NULL , 0 ) ;
if ( V_96 ) {
F_22 ( L_60 , V_96 ) ;
}
F_67 ( V_243 , & V_2 -> V_4 ) ;
F_76 ( V_2 -> V_104 . V_155 , 0 , NULL , 0 , V_188 ) ;
}
F_67 ( V_216 , & V_2 -> V_4 ) ;
F_67 ( V_215 , & V_131 -> V_154 ) ;
F_77 ( V_2 , V_245 , 0 ) ;
F_3 ( V_24 , L_31 ) ;
}
static T_4
F_78 ( struct V_114 * V_114 , struct V_94 * V_95 ,
struct V_246 * V_117 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_241 * V_247 = & V_98 -> V_2 -> V_247 ;
struct V_248 V_249 ;
T_6 V_250 = 0 ;
T_4 V_96 = 0 ;
T_4 V_251 = 0 ;
T_4 V_252 ;
T_1 V_170 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
if ( V_117 -> V_180 )
F_3 ( V_253 , L_61 , V_117 -> V_180 ) ;
else {
F_3 ( V_253 , L_62 ) ;
return - V_123 ;
}
F_51 ( V_216 , & V_98 -> V_2 -> V_4 ) ;
if ( V_117 -> V_140 )
F_3 ( V_253 , L_63 , V_117 -> V_140 ) ;
else
F_3 ( V_253 , L_64 ) ;
if ( V_117 -> V_254 . V_25 )
F_3 ( V_253 , L_65 ,
V_117 -> V_254 . V_25 -> V_26 ) ;
else
F_3 ( V_253 , L_66 ) ;
if ( V_117 -> V_255 )
F_3 ( V_253 , L_67 ) ;
else
F_3 ( V_253 , L_68 ) ;
if ( V_117 -> V_68 && V_117 -> V_256 )
F_3 ( V_253 , L_69 , V_117 -> V_256 ) ;
else
F_3 ( V_253 , L_70 ) ;
if ( V_117 -> V_257 )
F_3 ( V_253 , L_71 ,
V_117 -> V_257 ) ;
else
F_3 ( V_253 , L_72 ) ;
if ( V_117 -> V_258 )
F_3 ( V_253 , L_73 , V_117 -> V_258 ) ;
else
F_3 ( V_253 , L_74 ) ;
if ( V_117 -> V_259 )
F_3 ( V_253 , L_75 ) ;
else
F_3 ( V_253 , L_76 ) ;
if ( V_117 -> V_259 )
V_251 |= V_260 ;
V_96 = F_24 ( V_98 , L_77 , V_251 ) ;
if ( V_96 ) {
F_22 ( L_78 , V_96 ) ;
goto V_160;
}
if ( V_117 -> V_257 )
V_252 = V_117 -> V_257 ;
else
V_252 = 100 ;
V_96 = F_52 ( V_98 , V_261 , V_252 ) ;
if ( V_96 ) {
F_22 ( L_79 , V_96 ) ;
goto V_160;
}
memset ( & V_249 , 0 , sizeof( struct V_248 ) ) ;
V_247 -> V_180 . V_176 = F_66 ( T_5 , V_117 -> V_178 , 32 ) ;
memcpy ( V_247 -> V_180 . V_179 , V_117 -> V_180 , V_247 -> V_180 . V_176 ) ;
memcpy ( V_249 . V_173 . V_179 , V_117 -> V_180 , V_247 -> V_180 . V_176 ) ;
V_249 . V_173 . V_176 = F_16 ( V_247 -> V_180 . V_176 ) ;
V_250 = sizeof( V_249 . V_173 ) ;
if ( V_117 -> V_140 ) {
memcpy ( V_249 . V_135 . V_140 , V_117 -> V_140 , V_141 ) ;
V_250 = sizeof( V_249 . V_173 ) +
V_262 ;
memcpy ( V_247 -> V_140 , V_117 -> V_140 , V_141 ) ;
} else {
memset ( V_249 . V_135 . V_140 , 0xFF , V_141 ) ;
memset ( V_247 -> V_140 , 0 , V_141 ) ;
}
if ( V_117 -> V_254 . V_25 ) {
T_5 V_263 ;
V_131 -> V_264 =
F_7 (
V_117 -> V_254 . V_25 -> V_26 ) ;
if ( V_117 -> V_255 ) {
V_170 = F_6 ( & V_131 -> V_18 ,
& V_117 -> V_254 ) ;
V_249 . V_135 . V_265 [ 0 ] =
F_17 ( V_170 ) ;
V_249 . V_135 . V_266 = F_16 ( 1 ) ;
V_250 += sizeof( V_249 . V_135 ) ;
}
V_263 = V_131 -> V_264 ;
V_96 = F_52 ( V_98 , V_267 ,
V_263 ) ;
if ( V_96 ) {
F_22 ( L_80 , V_96 ) ;
goto V_160;
}
} else
V_131 -> V_264 = 0 ;
V_131 -> V_268 = false ;
V_96 = F_40 ( V_98 , V_269 ,
& V_249 , V_250 ) ;
if ( V_96 ) {
F_22 ( L_81 , V_96 ) ;
goto V_160;
}
V_160:
if ( V_96 )
F_67 ( V_216 , & V_98 -> V_2 -> V_4 ) ;
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4
F_79 ( struct V_114 * V_114 , struct V_94 * V_95 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
F_75 ( V_98 -> V_2 ) ;
F_3 ( V_24 , L_31 ) ;
return 0 ;
}
static T_4 F_80 ( struct V_94 * V_95 ,
struct V_270 * V_271 )
{
struct V_241 * V_247 = F_81 ( V_95 ) ;
struct V_272 * V_273 ;
T_4 V_274 = 0 ;
T_4 V_96 = 0 ;
if ( V_271 -> V_275 . V_276 & V_277 )
V_274 = V_278 | V_279 ;
else if ( V_271 -> V_275 . V_276 & V_280 )
V_274 = V_281 | V_282 ;
else
V_274 = V_283 ;
F_3 ( V_253 , L_82 , V_274 ) ;
V_96 = F_82 ( F_21 ( V_95 ) , L_83 , V_274 ) ;
if ( V_96 ) {
F_22 ( L_84 , V_96 ) ;
return V_96 ;
}
V_273 = & V_247 -> V_273 ;
V_273 -> V_276 = V_271 -> V_275 . V_276 ;
return V_96 ;
}
static T_4 F_83 ( struct V_94 * V_95 ,
struct V_270 * V_271 )
{
struct V_241 * V_247 = F_81 ( V_95 ) ;
struct V_272 * V_273 ;
T_4 V_274 = 0 ;
T_4 V_96 = 0 ;
switch ( V_271 -> V_284 ) {
case V_285 :
V_274 = 0 ;
F_3 ( V_253 , L_85 ) ;
break;
case V_286 :
V_274 = 1 ;
F_3 ( V_253 , L_86 ) ;
break;
case V_287 :
V_274 = 2 ;
F_3 ( V_253 , L_87 ) ;
break;
case V_288 :
F_3 ( V_253 , L_88 ) ;
default:
V_274 = 2 ;
F_22 ( L_89 , V_271 -> V_284 ) ;
break;
}
V_96 = F_82 ( F_21 ( V_95 ) , L_90 , V_274 ) ;
if ( V_96 ) {
F_22 ( L_91 , V_96 ) ;
return V_96 ;
}
V_273 = & V_247 -> V_273 ;
V_273 -> V_284 = V_271 -> V_284 ;
return V_96 ;
}
static T_4
F_84 ( struct V_94 * V_95 ,
struct V_270 * V_271 , bool V_289 )
{
struct V_241 * V_247 = F_81 ( V_95 ) ;
struct V_272 * V_273 ;
T_4 V_290 = 0 ;
T_4 V_291 = 0 ;
T_4 V_251 ;
T_4 V_96 = 0 ;
if ( V_271 -> V_275 . V_292 ) {
switch ( V_271 -> V_275 . V_293 [ 0 ] ) {
case V_294 :
case V_295 :
V_290 = V_260 ;
break;
case V_296 :
V_290 = V_297 ;
break;
case V_298 :
V_290 = V_299 ;
break;
case V_300 :
V_290 = V_299 ;
break;
default:
F_22 ( L_92 ,
V_271 -> V_275 . V_293 [ 0 ] ) ;
return - V_127 ;
}
}
if ( V_271 -> V_275 . V_301 ) {
switch ( V_271 -> V_275 . V_301 ) {
case V_294 :
case V_295 :
V_291 = V_260 ;
break;
case V_296 :
V_291 = V_297 ;
break;
case V_298 :
V_291 = V_299 ;
break;
case V_300 :
V_291 = V_299 ;
break;
default:
F_22 ( L_93 ,
V_271 -> V_275 . V_301 ) ;
return - V_127 ;
}
}
F_3 ( V_253 , L_94 , V_290 , V_291 ) ;
if ( F_14 ( V_271 -> V_68 , V_271 -> V_256 ) && ! V_290 && ! V_291 &&
V_271 -> V_259 )
V_290 = V_299 ;
if ( V_289 )
V_251 = V_290 | V_291 | V_302 ;
else
V_251 = V_290 | V_291 ;
V_96 = F_82 ( F_21 ( V_95 ) , L_77 , V_251 ) ;
if ( V_96 ) {
F_22 ( L_43 , V_96 ) ;
return V_96 ;
}
V_273 = & V_247 -> V_273 ;
V_273 -> V_303 = V_271 -> V_275 . V_293 [ 0 ] ;
V_273 -> V_301 = V_271 -> V_275 . V_301 ;
return V_96 ;
}
static T_4
F_85 ( struct V_94 * V_95 , struct V_270 * V_271 )
{
struct V_241 * V_247 = F_81 ( V_95 ) ;
struct V_272 * V_273 ;
T_4 V_274 = 0 ;
T_4 V_96 = 0 ;
if ( V_271 -> V_275 . V_304 ) {
V_96 = F_86 ( F_21 ( V_95 ) ,
L_83 , & V_274 ) ;
if ( V_96 ) {
F_22 ( L_95 , V_96 ) ;
return V_96 ;
}
if ( V_274 & ( V_278 | V_279 ) ) {
switch ( V_271 -> V_275 . V_305 [ 0 ] ) {
case V_306 :
V_274 = V_279 ;
break;
case V_307 :
V_274 = V_278 ;
break;
default:
F_22 ( L_93 ,
V_271 -> V_275 . V_301 ) ;
return - V_127 ;
}
} else if ( V_274 & ( V_281 | V_282 ) ) {
switch ( V_271 -> V_275 . V_305 [ 0 ] ) {
case V_306 :
V_274 = V_282 ;
break;
case V_307 :
V_274 = V_281 ;
break;
default:
F_22 ( L_93 ,
V_271 -> V_275 . V_301 ) ;
return - V_127 ;
}
}
F_3 ( V_253 , L_96 , V_274 ) ;
V_96 = F_82 ( F_21 ( V_95 ) ,
L_83 , V_274 ) ;
if ( V_96 ) {
F_22 ( L_97 , V_96 ) ;
return V_96 ;
}
}
V_273 = & V_247 -> V_273 ;
V_273 -> V_308 = V_271 -> V_275 . V_305 [ 0 ] ;
return V_96 ;
}
static T_4
F_87 ( struct V_94 * V_95 ,
struct V_270 * V_271 )
{
struct V_241 * V_247 = F_81 ( V_95 ) ;
struct V_272 * V_273 ;
struct V_82 V_62 ;
T_4 V_274 ;
T_4 V_96 = 0 ;
F_3 ( V_253 , L_98 , V_271 -> V_309 ) ;
if ( V_271 -> V_309 == 0 )
return 0 ;
V_273 = & V_247 -> V_273 ;
F_3 ( V_253 , L_99 ,
V_273 -> V_276 , V_273 -> V_303 ) ;
if ( V_273 -> V_276 & ( V_277 | V_280 ) )
return 0 ;
if ( ! ( V_273 -> V_303 &
( V_294 | V_295 ) ) )
return 0 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_66 = ( T_5 ) V_271 -> V_309 ;
V_62 . V_85 = ( T_5 ) V_271 -> V_310 ;
if ( V_62 . V_66 > sizeof( V_62 . V_92 ) ) {
F_22 ( L_100 , V_62 . V_66 ) ;
return - V_127 ;
}
memcpy ( V_62 . V_92 , V_271 -> V_62 , V_62 . V_66 ) ;
V_62 . V_87 = V_311 ;
switch ( V_273 -> V_303 ) {
case V_294 :
V_62 . V_86 = V_312 ;
break;
case V_295 :
V_62 . V_86 = V_313 ;
break;
default:
F_22 ( L_101 ,
V_271 -> V_275 . V_293 [ 0 ] ) ;
return - V_127 ;
}
F_3 ( V_253 , L_102 ,
V_62 . V_66 , V_62 . V_85 , V_62 . V_86 ) ;
F_3 ( V_253 , L_103 , V_62 . V_92 ) ;
V_96 = F_18 ( V_95 , & V_62 ) ;
if ( V_96 )
return V_96 ;
if ( V_273 -> V_284 == V_286 ) {
F_3 ( V_253 , L_104 ) ;
V_274 = V_314 ;
V_96 = F_82 ( F_21 ( V_95 ) , L_90 , V_274 ) ;
if ( V_96 )
F_22 ( L_91 , V_96 ) ;
}
return V_96 ;
}
static
enum V_315 F_88 ( struct V_97 * V_98 ,
enum V_315 type )
{
if ( type == V_287 &&
F_35 ( V_98 , V_316 ) ) {
F_3 ( V_253 , L_105 ) ;
type = V_285 ;
}
return type ;
}
static T_4
F_89 ( struct V_114 * V_114 , struct V_94 * V_95 ,
struct V_270 * V_271 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_241 * V_247 = & V_98 -> V_2 -> V_247 ;
struct V_58 * V_25 = V_271 -> V_264 ;
struct V_248 V_249 ;
T_6 V_250 ;
const struct V_59 * V_317 ;
const struct V_75 * V_318 ;
const void * V_68 ;
T_5 V_256 ;
struct V_319 * V_320 ;
T_1 V_170 ;
T_4 V_96 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
if ( ! V_271 -> V_180 ) {
F_22 ( L_106 ) ;
return - V_123 ;
}
if ( V_98 -> V_2 == V_131 -> V_217 . V_218 [ V_220 ] . V_2 ) {
V_68 = NULL ;
V_256 = 0 ;
V_318 = F_13 ( ( T_2 * ) V_271 -> V_68 , V_271 -> V_256 ) ;
if ( V_318 ) {
V_68 = V_318 ;
V_256 = V_318 -> V_66 + V_65 ;
} else {
V_317 = F_11 ( ( const T_2 * ) V_271 -> V_68 ,
V_271 -> V_256 ,
V_321 ) ;
if ( V_317 ) {
V_68 = V_317 ;
V_256 = V_317 -> V_66 + V_65 ;
}
}
F_59 ( V_98 , L_107 , V_68 , V_256 ) ;
}
V_96 = F_90 ( V_98 -> V_2 , V_322 ,
V_271 -> V_68 , V_271 -> V_256 ) ;
if ( V_96 )
F_22 ( L_108 ) ;
else
F_3 ( V_24 , L_109 ) ;
F_51 ( V_216 , & V_98 -> V_2 -> V_4 ) ;
if ( V_25 ) {
V_131 -> V_264 =
F_7 ( V_25 -> V_26 ) ;
V_170 = F_10 ( & V_131 -> V_18 , V_25 ) ;
F_3 ( V_253 , L_110 ,
V_131 -> V_264 , V_25 -> V_26 , V_170 ) ;
} else {
V_131 -> V_264 = 0 ;
V_170 = 0 ;
}
F_3 ( V_5 , L_111 , V_271 -> V_68 , V_271 -> V_256 ) ;
V_96 = F_80 ( V_95 , V_271 ) ;
if ( V_96 ) {
F_22 ( L_112 , V_96 ) ;
goto V_160;
}
V_271 -> V_284 = F_88 ( V_98 , V_271 -> V_284 ) ;
V_96 = F_83 ( V_95 , V_271 ) ;
if ( V_96 ) {
F_22 ( L_113 , V_96 ) ;
goto V_160;
}
V_96 = F_84 ( V_95 , V_271 , V_271 -> V_289 == V_323 ) ;
if ( V_96 ) {
F_22 ( L_114 , V_96 ) ;
goto V_160;
}
V_96 = F_85 ( V_95 , V_271 ) ;
if ( V_96 ) {
F_22 ( L_115 , V_96 ) ;
goto V_160;
}
V_96 = F_87 ( V_95 , V_271 ) ;
if ( V_96 ) {
F_22 ( L_116 , V_96 ) ;
goto V_160;
}
V_247 -> V_180 . V_176 = F_66 ( T_5 , ( T_5 ) sizeof( V_247 -> V_180 . V_179 ) ,
( T_5 ) V_271 -> V_178 ) ;
memcpy ( & V_247 -> V_180 . V_179 , V_271 -> V_180 , V_247 -> V_180 . V_176 ) ;
if ( V_247 -> V_180 . V_176 < V_324 ) {
V_247 -> V_180 . V_179 [ V_247 -> V_180 . V_176 ] = 0 ;
F_3 ( V_253 , L_117 , V_247 -> V_180 . V_179 ,
V_247 -> V_180 . V_176 ) ;
}
V_250 = F_54 ( struct V_319 , V_325 ) +
F_54 ( struct V_326 , V_265 ) ;
if ( V_131 -> V_264 )
V_250 += sizeof( T_1 ) ;
V_320 = F_57 ( V_250 , V_188 ) ;
if ( V_320 == NULL ) {
V_96 = - V_189 ;
goto V_160;
}
V_320 -> V_173 . V_176 = F_16 ( V_247 -> V_180 . V_176 ) ;
memcpy ( & V_320 -> V_173 . V_179 , V_271 -> V_180 ,
V_247 -> V_180 . V_176 ) ;
V_320 -> V_327 . V_144 = - 1 ;
V_320 -> V_327 . V_149 = F_16 ( - 1 ) ;
if ( V_271 -> V_140 )
memcpy ( & V_320 -> V_325 . V_140 , V_271 -> V_140 , V_141 ) ;
else
memset ( & V_320 -> V_325 . V_140 , 0xFF , V_141 ) ;
if ( V_131 -> V_264 ) {
V_320 -> V_325 . V_266 = F_16 ( 1 ) ;
V_320 -> V_325 . V_265 [ 0 ] =
F_17 ( V_170 ) ;
V_320 -> V_327 . V_147 =
F_16 ( V_328 ) ;
V_320 -> V_327 . V_148 =
F_16 ( V_329 ) ;
V_320 -> V_327 . V_146 =
F_16 ( V_328 /
V_330 ) ;
} else {
V_320 -> V_327 . V_147 = F_16 ( - 1 ) ;
V_320 -> V_327 . V_148 = F_16 ( - 1 ) ;
V_320 -> V_327 . V_146 = F_16 ( - 1 ) ;
}
V_96 = F_20 ( V_98 , L_118 , V_320 ,
V_250 ) ;
F_60 ( V_320 ) ;
if ( ! V_96 )
goto V_160;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
V_250 = sizeof( V_249 . V_173 ) ;
memcpy ( & V_249 . V_173 . V_179 , V_271 -> V_180 , V_247 -> V_180 . V_176 ) ;
V_249 . V_173 . V_176 = F_16 ( V_247 -> V_180 . V_176 ) ;
if ( V_271 -> V_140 )
memcpy ( V_249 . V_135 . V_140 , V_271 -> V_140 , V_141 ) ;
else
memset ( V_249 . V_135 . V_140 , 0xFF , V_141 ) ;
if ( V_131 -> V_264 ) {
V_249 . V_135 . V_265 [ 0 ] = F_17 ( V_170 ) ;
V_249 . V_135 . V_266 = F_16 ( 1 ) ;
V_250 += sizeof( V_249 . V_135 ) ;
}
V_96 = F_40 ( V_98 , V_269 ,
& V_249 , V_250 ) ;
if ( V_96 )
F_22 ( L_119 , V_96 ) ;
V_160:
if ( V_96 )
F_67 ( V_216 , & V_98 -> V_2 -> V_4 ) ;
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4
F_91 ( struct V_114 * V_114 , struct V_94 * V_95 ,
T_1 V_331 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_241 * V_247 = & V_98 -> V_2 -> V_247 ;
struct V_332 V_333 ;
T_4 V_96 = 0 ;
F_3 ( V_24 , L_120 , V_331 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
F_67 ( V_243 , & V_98 -> V_2 -> V_4 ) ;
F_76 ( V_95 , V_331 , NULL , 0 , V_188 ) ;
memcpy ( & V_333 . V_93 , & V_247 -> V_140 , V_141 ) ;
V_333 . V_274 = F_16 ( V_331 ) ;
V_96 = F_40 ( V_98 , V_244 ,
& V_333 , sizeof( V_333 ) ) ;
if ( V_96 )
F_22 ( L_43 , V_96 ) ;
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4
F_92 ( struct V_114 * V_114 , struct V_103 * V_104 ,
enum V_334 type , T_4 V_335 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_94 * V_95 = F_73 ( V_131 ) ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
T_1 V_336 ;
T_4 V_96 = 0 ;
T_4 V_337 = 0 ;
T_4 V_338 = F_93 ( V_335 ) ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
switch ( type ) {
case V_339 :
break;
case V_340 :
case V_341 :
if ( V_338 < 0 ) {
F_22 ( L_121 ) ;
V_96 = - V_127 ;
goto V_160;
}
break;
}
V_337 = V_342 << 16 ;
V_96 = F_52 ( V_98 , V_343 , V_337 ) ;
if ( V_96 )
F_22 ( L_122 , V_96 ) ;
if ( V_338 > 0xffff )
V_336 = 0xffff ;
else
V_336 = ( T_1 ) V_338 ;
V_96 = F_24 ( V_98 , L_123 ,
( T_4 ) F_5 ( V_336 ) ) ;
if ( V_96 )
F_22 ( L_124 , V_96 ) ;
V_131 -> V_235 -> V_344 = V_338 ;
V_160:
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4 F_94 ( struct V_114 * V_114 ,
struct V_103 * V_104 ,
T_4 * V_338 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_97 * V_98 = F_21 ( F_73 ( V_131 ) ) ;
T_4 V_345 ;
T_2 V_346 ;
T_4 V_96 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
V_96 = F_95 ( V_98 , L_123 , & V_345 ) ;
if ( V_96 ) {
F_22 ( L_43 , V_96 ) ;
goto V_160;
}
V_346 = ( T_2 ) ( V_345 & ~ V_347 ) ;
* V_338 = ( T_4 ) F_4 ( V_346 ) ;
V_160:
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4
F_96 ( struct V_114 * V_114 , struct V_94 * V_95 ,
T_2 V_310 , bool V_348 , bool V_349 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
T_5 V_85 ;
T_5 V_251 ;
T_4 V_96 = 0 ;
F_3 ( V_24 , L_14 ) ;
F_3 ( V_253 , L_125 , V_310 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
V_96 = F_86 ( V_98 , L_77 , & V_251 ) ;
if ( V_96 ) {
F_22 ( L_126 , V_96 ) ;
goto V_160;
}
if ( V_251 & V_260 ) {
V_85 = V_310 ;
V_96 = F_52 ( V_98 ,
V_350 , V_85 ) ;
if ( V_96 )
F_22 ( L_43 , V_96 ) ;
}
V_160:
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4
F_97 ( struct V_114 * V_114 , struct V_94 * V_95 ,
T_2 V_310 , const T_2 * V_351 , struct V_352 * V_117 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_82 V_62 ;
T_4 V_96 = 0 ;
T_2 V_353 [ 8 ] ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_85 = ( T_5 ) V_310 ;
if ( ! F_98 ( V_351 ) )
memcpy ( ( char * ) & V_62 . V_93 , ( void * ) V_351 , V_141 ) ;
V_62 . V_66 = ( T_5 ) V_117 -> V_309 ;
if ( V_62 . V_66 == 0 ) {
V_96 = F_18 ( V_95 , & V_62 ) ;
if ( V_96 )
F_22 ( L_127 , V_96 ) ;
} else {
if ( V_62 . V_66 > sizeof( V_62 . V_92 ) ) {
F_22 ( L_128 , V_62 . V_66 ) ;
return - V_127 ;
}
F_3 ( V_253 , L_129 , V_62 . V_85 ) ;
memcpy ( V_62 . V_92 , V_117 -> V_62 , V_62 . V_66 ) ;
if ( ! F_28 ( V_98 -> V_2 ) &&
( V_117 -> V_354 == V_296 ) ) {
F_3 ( V_253 , L_130 ) ;
memcpy ( V_353 , & V_62 . V_92 [ 24 ] , sizeof( V_353 ) ) ;
memcpy ( & V_62 . V_92 [ 24 ] , & V_62 . V_92 [ 16 ] , sizeof( V_353 ) ) ;
memcpy ( & V_62 . V_92 [ 16 ] , V_353 , sizeof( V_353 ) ) ;
}
if ( V_117 -> V_355 && V_117 -> V_356 == 6 ) {
T_2 * V_357 ;
V_357 = ( T_2 * ) V_117 -> V_355 ;
V_62 . V_88 . V_89 = ( V_357 [ 5 ] << 24 ) | ( V_357 [ 4 ] << 16 ) |
( V_357 [ 3 ] << 8 ) | V_357 [ 2 ] ;
V_62 . V_88 . V_90 = ( V_357 [ 1 ] << 8 ) | V_357 [ 0 ] ;
V_62 . V_91 = true ;
}
switch ( V_117 -> V_354 ) {
case V_294 :
V_62 . V_86 = V_312 ;
F_3 ( V_253 , L_131 ) ;
break;
case V_295 :
V_62 . V_86 = V_313 ;
F_3 ( V_253 , L_132 ) ;
break;
case V_296 :
V_62 . V_86 = V_358 ;
F_3 ( V_253 , L_133 ) ;
break;
case V_300 :
V_62 . V_86 = V_359 ;
F_3 ( V_253 , L_134 ) ;
break;
case V_298 :
V_62 . V_86 = V_359 ;
F_3 ( V_253 , L_135 ) ;
break;
default:
F_22 ( L_136 , V_117 -> V_354 ) ;
return - V_127 ;
}
V_96 = F_18 ( V_95 , & V_62 ) ;
if ( V_96 )
F_22 ( L_4 , V_96 ) ;
}
return V_96 ;
}
static T_4
F_99 ( struct V_114 * V_114 , struct V_94 * V_95 ,
T_2 V_310 , bool V_360 , const T_2 * V_351 ,
struct V_352 * V_117 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_82 V_62 ;
T_4 V_274 ;
T_4 V_251 ;
T_4 V_96 = 0 ;
T_2 V_353 [ 8 ] ;
F_3 ( V_24 , L_14 ) ;
F_3 ( V_253 , L_125 , V_310 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
if ( V_351 &&
( V_117 -> V_354 != V_294 ) &&
( V_117 -> V_354 != V_295 ) ) {
F_3 ( V_24 , L_137 ) ;
return F_97 ( V_114 , V_95 , V_310 , V_351 , V_117 ) ;
}
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_66 = ( T_5 ) V_117 -> V_309 ;
V_62 . V_85 = ( T_5 ) V_310 ;
if ( V_62 . V_66 > sizeof( V_62 . V_92 ) ) {
F_22 ( L_100 , V_62 . V_66 ) ;
V_96 = - V_127 ;
goto V_160;
}
memcpy ( V_62 . V_92 , V_117 -> V_62 , V_62 . V_66 ) ;
V_62 . V_87 = V_311 ;
switch ( V_117 -> V_354 ) {
case V_294 :
V_62 . V_86 = V_312 ;
V_274 = V_260 ;
F_3 ( V_253 , L_131 ) ;
break;
case V_295 :
V_62 . V_86 = V_313 ;
V_274 = V_260 ;
F_3 ( V_253 , L_132 ) ;
break;
case V_296 :
if ( ! F_28 ( V_98 -> V_2 ) ) {
F_3 ( V_253 , L_130 ) ;
memcpy ( V_353 , & V_62 . V_92 [ 24 ] , sizeof( V_353 ) ) ;
memcpy ( & V_62 . V_92 [ 24 ] , & V_62 . V_92 [ 16 ] , sizeof( V_353 ) ) ;
memcpy ( & V_62 . V_92 [ 16 ] , V_353 , sizeof( V_353 ) ) ;
}
V_62 . V_86 = V_358 ;
V_274 = V_297 ;
F_3 ( V_253 , L_133 ) ;
break;
case V_300 :
V_62 . V_86 = V_359 ;
V_274 = V_299 ;
F_3 ( V_253 , L_134 ) ;
break;
case V_298 :
V_62 . V_86 = V_359 ;
V_274 = V_299 ;
F_3 ( V_253 , L_135 ) ;
break;
default:
F_22 ( L_136 , V_117 -> V_354 ) ;
V_96 = - V_127 ;
goto V_160;
}
V_96 = F_18 ( V_95 , & V_62 ) ;
if ( V_96 )
goto V_160;
V_96 = F_86 ( V_98 , L_77 , & V_251 ) ;
if ( V_96 ) {
F_22 ( L_138 , V_96 ) ;
goto V_160;
}
V_251 |= V_274 ;
V_96 = F_82 ( V_98 , L_77 , V_251 ) ;
if ( V_96 ) {
F_22 ( L_139 , V_96 ) ;
goto V_160;
}
V_160:
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4
F_100 ( struct V_114 * V_114 , struct V_94 * V_95 ,
T_2 V_310 , bool V_360 , const T_2 * V_351 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_82 V_62 ;
T_4 V_96 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
if ( V_310 >= V_361 ) {
F_22 ( L_140 , V_310 ) ;
return - V_127 ;
}
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_85 = ( T_5 ) V_310 ;
V_62 . V_87 = V_311 ;
V_62 . V_86 = V_362 ;
F_3 ( V_253 , L_125 , V_310 ) ;
V_96 = F_18 ( V_95 , & V_62 ) ;
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4
F_101 ( struct V_114 * V_114 , struct V_94 * V_95 ,
T_2 V_310 , bool V_360 , const T_2 * V_351 , void * V_363 ,
void (* F_102) ( void * V_363 , struct V_352 * V_117 ) )
{
struct V_352 V_117 ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_241 * V_247 = & V_98 -> V_2 -> V_247 ;
struct V_272 * V_273 ;
T_4 V_251 ;
T_4 V_96 = 0 ;
F_3 ( V_24 , L_14 ) ;
F_3 ( V_253 , L_125 , V_310 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_96 = F_86 ( V_98 , L_77 , & V_251 ) ;
if ( V_96 ) {
F_22 ( L_126 , V_96 ) ;
V_96 = - V_164 ;
goto V_160;
}
if ( V_251 & V_260 ) {
V_273 = & V_247 -> V_273 ;
if ( V_273 -> V_303 & V_294 ) {
V_117 . V_354 = V_294 ;
F_3 ( V_253 , L_131 ) ;
} else if ( V_273 -> V_303 & V_295 ) {
V_117 . V_354 = V_295 ;
F_3 ( V_253 , L_132 ) ;
}
} else if ( V_251 & V_297 ) {
V_117 . V_354 = V_296 ;
F_3 ( V_253 , L_133 ) ;
} else if ( V_251 & V_299 ) {
V_117 . V_354 = V_300 ;
F_3 ( V_253 , L_134 ) ;
} else {
F_22 ( L_141 , V_251 ) ;
V_96 = - V_127 ;
goto V_160;
}
F_102 ( V_363 , & V_117 ) ;
V_160:
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4
F_103 ( struct V_114 * V_114 ,
struct V_94 * V_95 , T_2 V_310 )
{
F_3 ( V_5 , L_142 ) ;
return - V_123 ;
}
static T_4
F_104 ( struct V_114 * V_114 , struct V_94 * V_95 ,
const T_2 * V_364 , struct V_365 * V_366 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_241 * V_247 = & V_98 -> V_2 -> V_247 ;
struct V_332 V_367 ;
int V_368 ;
T_4 V_369 ;
T_4 V_96 = 0 ;
T_2 * V_140 = V_247 -> V_140 ;
struct V_370 V_371 ;
T_5 V_372 ;
T_5 V_373 ;
F_3 ( V_24 , L_143 , V_364 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
if ( F_28 ( V_98 -> V_2 ) ) {
memcpy ( & V_371 , V_364 , V_141 ) ;
V_96 = F_105 ( V_98 , L_144 ,
& V_371 ,
sizeof( V_371 ) ) ;
if ( V_96 < 0 ) {
F_22 ( L_145 , V_96 ) ;
goto V_160;
}
V_366 -> V_374 = V_375 ;
V_366 -> V_376 = F_106 ( V_371 . V_377 ) * 1000 ;
if ( F_106 ( V_371 . V_87 ) & V_378 ) {
V_366 -> V_374 |= V_379 ;
V_366 -> V_380 = F_106 ( V_371 . V_381 ) ;
}
F_3 ( V_24 , L_146 ,
V_366 -> V_376 , V_366 -> V_380 ) ;
} else if ( V_98 -> V_2 -> V_104 . V_105 == V_118 ) {
if ( memcmp ( V_364 , V_140 , V_141 ) ) {
F_22 ( L_147 ,
V_364 , V_140 ) ;
V_96 = - V_382 ;
goto V_160;
}
V_96 = F_107 ( V_98 , V_383 , & V_369 ) ;
if ( V_96 ) {
F_22 ( L_148 , V_96 ) ;
goto V_160;
} else {
V_366 -> V_374 |= V_384 ;
V_366 -> V_385 . V_386 = V_369 * 5 ;
F_3 ( V_253 , L_149 , V_369 / 2 ) ;
}
if ( F_2 ( V_243 ,
& V_98 -> V_2 -> V_4 ) ) {
memset ( & V_367 , 0 , sizeof( V_367 ) ) ;
V_96 = F_108 ( V_98 , V_387 ,
& V_367 , sizeof( V_367 ) ) ;
if ( V_96 ) {
F_22 ( L_150 , V_96 ) ;
goto V_160;
} else {
V_368 = F_106 ( V_367 . V_274 ) ;
V_366 -> V_374 |= V_388 ;
V_366 -> signal = V_368 ;
F_3 ( V_253 , L_151 , V_368 ) ;
}
V_96 = F_107 ( V_98 , V_389 ,
& V_372 ) ;
if ( V_96 ) {
F_22 ( L_152 ,
V_96 ) ;
goto V_160;
} else {
V_366 -> V_390 . V_257 =
V_372 ;
F_3 ( V_253 , L_153 ,
V_372 ) ;
}
V_96 = F_107 ( V_98 , V_391 ,
& V_373 ) ;
if ( V_96 ) {
F_22 ( L_154 ,
V_96 ) ;
goto V_160;
} else {
V_366 -> V_390 . V_373 = V_373 ;
F_3 ( V_253 , L_155 ,
V_373 ) ;
}
V_366 -> V_374 |= V_392 ;
}
} else
V_96 = - V_393 ;
V_160:
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4
F_109 ( struct V_114 * V_114 , struct V_94 * V_95 ,
bool V_394 , T_4 V_395 )
{
T_4 V_396 ;
T_4 V_96 = 0 ;
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
F_3 ( V_24 , L_14 ) ;
V_131 -> V_397 = V_394 ;
if ( ! F_1 ( V_98 -> V_2 ) ) {
F_3 ( V_5 , L_156 ) ;
goto V_160;
}
V_396 = V_394 ? V_398 : V_399 ;
if ( V_98 -> V_2 -> V_104 . V_105 == V_124 ) {
F_3 ( V_5 , L_157 ) ;
V_396 = V_399 ;
}
F_3 ( V_5 , L_158 , ( V_396 ? L_159 : L_160 ) ) ;
V_96 = F_52 ( V_98 , V_400 , V_396 ) ;
if ( V_96 ) {
if ( V_96 == - V_401 )
F_22 ( L_161 ) ;
else
F_22 ( L_43 , V_96 ) ;
}
V_160:
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4 F_110 ( struct V_130 * V_131 ,
struct V_402 * V_403 )
{
struct V_114 * V_114 = F_42 ( V_131 ) ;
struct V_58 * V_404 ;
struct V_405 * V_406 ;
struct V_407 * V_50 ;
struct V_21 V_20 ;
T_1 V_264 ;
T_5 V_408 ;
T_1 V_409 ;
T_1 V_410 ;
T_2 * V_411 ;
T_6 V_412 ;
T_4 V_413 ;
if ( F_106 ( V_403 -> V_414 ) > V_415 ) {
F_22 ( L_162 ) ;
return 0 ;
}
if ( ! V_403 -> V_416 ) {
V_20 . V_57 = F_111 ( V_403 -> V_170 ) ;
V_131 -> V_18 . V_417 ( & V_20 ) ;
V_403 -> V_416 = V_20 . V_29 ;
}
V_264 = V_403 -> V_416 ;
if ( V_264 <= V_418 )
V_50 = V_114 -> V_419 [ V_51 ] ;
else
V_50 = V_114 -> V_419 [ V_53 ] ;
V_408 = F_112 ( V_264 , V_50 -> V_50 ) ;
V_404 = F_113 ( V_114 , V_408 ) ;
V_409 = F_111 ( V_403 -> V_420 ) ;
V_410 = F_111 ( V_403 -> V_372 ) ;
V_411 = ( T_2 * ) V_403 + F_111 ( V_403 -> V_421 ) ;
V_412 = F_106 ( V_403 -> V_422 ) ;
V_413 = ( V_423 ) F_111 ( V_403 -> V_424 ) * 100 ;
F_3 ( V_253 , L_163 , V_403 -> V_425 ) ;
F_3 ( V_253 , L_164 , V_264 , V_408 ) ;
F_3 ( V_253 , L_165 , V_409 ) ;
F_3 ( V_253 , L_166 , V_410 ) ;
F_3 ( V_253 , L_167 , V_413 ) ;
V_406 = F_114 ( V_114 , V_404 ,
V_426 ,
( const T_2 * ) V_403 -> V_425 ,
0 , V_409 ,
V_410 , V_411 ,
V_412 , V_413 ,
V_188 ) ;
if ( ! V_406 )
return - V_189 ;
F_115 ( V_114 , V_406 ) ;
return 0 ;
}
static struct V_402 *
F_116 ( struct V_195 * V_427 , struct V_402 * V_406 )
{
if ( V_406 == NULL )
return V_427 -> V_428 ;
return (struct V_402 * ) ( ( unsigned long ) V_406 +
F_106 ( V_406 -> V_414 ) ) ;
}
static T_4 F_117 ( struct V_130 * V_131 )
{
struct V_195 * V_429 ;
struct V_402 * V_403 = NULL ;
T_4 V_96 = 0 ;
int V_169 ;
V_429 = (struct V_195 * ) V_131 -> V_157 . V_202 ;
if ( V_429 -> V_203 != 0 &&
V_429 -> V_191 != V_430 ) {
F_22 ( L_168 ,
V_429 -> V_191 ) ;
return - V_123 ;
}
F_3 ( V_138 , L_169 , V_429 -> V_203 ) ;
for ( V_169 = 0 ; V_169 < V_429 -> V_203 ; V_169 ++ ) {
V_403 = F_116 ( V_429 , V_403 ) ;
V_96 = F_110 ( V_131 , V_403 ) ;
if ( V_96 )
break;
}
return V_96 ;
}
static T_4 F_118 ( struct V_130 * V_131 ,
struct V_94 * V_95 , const T_2 * V_140 )
{
struct V_114 * V_114 = F_42 ( V_131 ) ;
struct V_58 * V_404 ;
struct V_402 * V_403 = NULL ;
struct V_407 * V_50 ;
struct V_405 * V_406 ;
struct V_21 V_20 ;
T_2 * V_60 = NULL ;
T_4 V_96 = 0 ;
T_5 V_408 ;
T_1 V_409 ;
T_1 V_410 ;
T_2 * V_411 ;
T_6 V_412 ;
T_4 V_413 ;
F_3 ( V_24 , L_14 ) ;
V_60 = F_57 ( V_415 , V_188 ) ;
if ( V_60 == NULL ) {
V_96 = - V_189 ;
goto V_431;
}
* ( V_432 * ) V_60 = F_16 ( V_415 ) ;
V_96 = F_108 ( F_21 ( V_95 ) , V_433 ,
V_60 , V_415 ) ;
if ( V_96 ) {
F_22 ( L_170 , V_96 ) ;
goto V_431;
}
V_403 = (struct V_402 * ) ( V_60 + 4 ) ;
V_20 . V_57 = F_111 ( V_403 -> V_170 ) ;
V_131 -> V_18 . V_417 ( & V_20 ) ;
if ( V_20 . V_50 == V_52 )
V_50 = V_114 -> V_419 [ V_51 ] ;
else
V_50 = V_114 -> V_419 [ V_53 ] ;
V_408 = F_112 ( V_20 . V_29 , V_50 -> V_50 ) ;
V_404 = F_113 ( V_114 , V_408 ) ;
V_409 = F_111 ( V_403 -> V_420 ) ;
V_410 = F_111 ( V_403 -> V_372 ) ;
V_411 = ( T_2 * ) V_403 + F_111 ( V_403 -> V_421 ) ;
V_412 = F_106 ( V_403 -> V_422 ) ;
V_413 = ( V_423 ) F_111 ( V_403 -> V_424 ) * 100 ;
F_3 ( V_253 , L_171 , V_20 . V_29 , V_408 ) ;
F_3 ( V_253 , L_172 , V_409 ) ;
F_3 ( V_253 , L_71 , V_410 ) ;
F_3 ( V_253 , L_173 , V_413 ) ;
V_406 = F_114 ( V_114 , V_404 ,
V_426 , V_140 , 0 ,
V_409 , V_410 ,
V_411 , V_412 , V_413 ,
V_188 ) ;
if ( ! V_406 ) {
V_96 = - V_189 ;
goto V_431;
}
F_115 ( V_114 , V_406 ) ;
V_431:
F_60 ( V_60 ) ;
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4 F_119 ( struct V_130 * V_131 ,
struct V_97 * V_98 )
{
struct V_241 * V_247 = F_81 ( V_98 -> V_95 ) ;
struct V_402 * V_403 ;
struct V_187 * V_180 ;
const struct V_59 * V_434 ;
T_1 V_257 ;
T_2 V_373 ;
T_6 V_256 ;
T_2 * V_68 ;
T_4 V_96 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( F_29 ( V_98 -> V_2 ) )
return V_96 ;
V_180 = & V_247 -> V_180 ;
* ( V_432 * ) V_131 -> V_435 = F_16 ( V_436 ) ;
V_96 = F_108 ( V_98 , V_433 ,
V_131 -> V_435 , V_436 ) ;
if ( V_96 ) {
F_22 ( L_174 , V_96 ) ;
goto V_437;
}
V_403 = (struct V_402 * ) ( V_131 -> V_435 + 4 ) ;
V_96 = F_110 ( V_131 , V_403 ) ;
if ( V_96 )
goto V_437;
V_68 = ( ( T_2 * ) V_403 ) + F_111 ( V_403 -> V_421 ) ;
V_256 = F_106 ( V_403 -> V_422 ) ;
V_257 = F_111 ( V_403 -> V_372 ) ;
V_434 = F_11 ( V_68 , V_256 , V_438 ) ;
if ( V_434 )
V_373 = V_434 -> V_92 [ 1 ] ;
else {
T_5 V_439 ;
V_96 = F_95 ( V_98 , L_175 , & V_439 ) ;
if ( V_96 ) {
F_22 ( L_176 , V_96 ) ;
goto V_437;
}
V_373 = ( T_2 ) V_439 ;
}
V_437:
F_3 ( V_24 , L_137 ) ;
return V_96 ;
}
void F_120 ( struct V_130 * V_131 )
{
struct V_157 * V_197 = & V_131 -> V_157 ;
F_51 ( V_214 , & V_131 -> V_154 ) ;
if ( V_131 -> V_137 ) {
V_197 -> V_198 = V_440 ;
F_37 ( V_131 , V_197 -> V_98 , true , true ) ;
}
F_67 ( V_153 , & V_131 -> V_154 ) ;
F_67 ( V_214 , & V_131 -> V_154 ) ;
}
static void F_121 ( struct V_441 * V_442 )
{
struct V_130 * V_131 =
F_26 ( V_442 , struct V_130 ,
V_443 ) ;
F_117 ( V_131 ) ;
F_37 ( V_131 , V_131 -> V_157 . V_98 , true , true ) ;
}
static void F_122 ( unsigned long V_92 )
{
struct V_130 * V_131 =
(struct V_130 * ) V_92 ;
if ( V_131 -> V_137 ) {
F_22 ( L_177 ) ;
F_123 ( & V_131 -> V_443 ) ;
}
}
static T_4
F_124 ( struct V_130 * V_131 ,
struct V_402 * V_406 ,
struct V_402 * V_428 )
{
struct V_21 V_444 , V_445 ;
V_444 . V_57 = F_111 ( V_406 -> V_170 ) ;
V_131 -> V_18 . V_417 ( & V_444 ) ;
V_445 . V_57 = F_111 ( V_428 -> V_170 ) ;
V_131 -> V_18 . V_417 ( & V_445 ) ;
if ( ! memcmp ( & V_428 -> V_425 , & V_406 -> V_425 , V_141 ) &&
V_444 . V_50 == V_445 . V_50 &&
V_428 -> V_176 == V_406 -> V_176 &&
! memcmp ( V_428 -> V_179 , V_406 -> V_179 , V_428 -> V_176 ) ) {
if ( ( V_406 -> V_87 & V_446 ) ==
( V_428 -> V_87 & V_446 ) ) {
V_423 V_447 = F_111 ( V_406 -> V_424 ) ;
V_423 V_448 = F_111 ( V_428 -> V_424 ) ;
if ( V_448 > V_447 )
V_406 -> V_424 = V_428 -> V_424 ;
} else if ( ( V_406 -> V_87 & V_446 ) &&
( V_428 -> V_87 & V_446 ) == 0 ) {
V_406 -> V_424 = V_428 -> V_424 ;
V_406 -> V_87 |= V_446 ;
}
return 1 ;
}
return 0 ;
}
static T_4
F_125 ( struct V_97 * V_98 ,
const struct V_449 * V_450 , void * V_92 )
{
struct V_130 * V_131 = V_98 -> V_109 -> V_451 ;
T_4 V_452 ;
struct V_453 * V_454 ;
struct V_402 * V_428 ;
struct V_402 * V_406 = NULL ;
T_5 V_455 ;
struct V_195 * V_427 ;
T_5 V_169 ;
bool V_132 ;
V_452 = V_450 -> V_452 ;
if ( ! F_2 ( V_153 , & V_131 -> V_154 ) ) {
F_22 ( L_178 , V_98 -> V_456 ) ;
return - V_393 ;
}
if ( V_452 == V_457 ) {
F_3 ( V_138 , L_179 ) ;
V_454 = (struct V_453 * ) V_92 ;
if ( ! V_454 ) {
F_22 ( L_180 ) ;
goto exit;
}
if ( F_111 ( V_454 -> V_458 ) != 1 ) {
F_22 ( L_181 ,
V_454 -> V_458 ) ;
goto exit;
}
V_428 = & V_454 -> V_428 ;
if ( F_126 ( V_131 , V_428 ) )
goto exit;
if ( ! V_131 -> V_137 ) {
F_3 ( V_138 , L_182 ) ;
goto exit;
}
V_455 = F_106 ( V_428 -> V_414 ) ;
if ( V_455 != ( F_106 ( V_454 -> V_61 ) -
V_204 ) ) {
F_22 ( L_183 ,
V_455 ) ;
goto exit;
}
if ( ! ( F_42 ( V_131 ) -> V_459 &
F_127 ( V_106 ) ) ) {
if ( F_111 ( V_428 -> V_420 ) &
V_460 ) {
F_22 ( L_184 ) ;
goto exit;
}
}
V_427 = (struct V_195 * )
V_131 -> V_157 . V_202 ;
if ( V_455 > V_461 - V_427 -> V_61 ) {
F_22 ( L_185 ) ;
goto exit;
}
for ( V_169 = 0 ; V_169 < V_427 -> V_203 ; V_169 ++ ) {
V_406 = V_406 ? (struct V_402 * )
( ( unsigned char * ) V_406 +
F_106 ( V_406 -> V_414 ) ) : V_427 -> V_428 ;
if ( F_124 ( V_131 , V_406 ,
V_428 ) )
goto exit;
}
memcpy ( & ( V_131 -> V_157 . V_202 [ V_427 -> V_61 ] ) ,
V_428 , V_455 ) ;
V_427 -> V_191 = F_106 ( V_428 -> V_191 ) ;
V_427 -> V_61 += V_455 ;
V_427 -> V_203 ++ ;
} else {
V_131 -> V_157 . V_198 = V_440 ;
if ( F_126 ( V_131 , NULL ) )
goto exit;
if ( V_131 -> V_137 ) {
F_117 ( V_131 ) ;
V_132 = V_452 != V_462 ;
F_37 ( V_131 , V_98 , V_132 , false ) ;
} else
F_3 ( V_138 , L_186 ,
V_452 ) ;
}
exit:
return 0 ;
}
static void F_128 ( struct V_130 * V_131 )
{
F_129 ( V_131 -> V_463 , V_464 ,
F_125 ) ;
V_131 -> V_157 . V_198 = V_440 ;
F_130 ( & V_131 -> V_139 ) ;
V_131 -> V_139 . V_92 = ( unsigned long ) V_131 ;
V_131 -> V_139 . V_465 = F_122 ;
F_131 ( & V_131 -> V_443 ,
F_121 ) ;
}
static T_7 void F_132 ( T_5 V_466 )
{
if ( V_466 < 1000 / V_223 ) {
F_133 () ;
F_134 ( V_466 ) ;
} else {
F_135 ( V_466 ) ;
}
}
static T_4 F_136 ( struct V_114 * V_114 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_94 * V_95 = F_73 ( V_131 ) ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
F_3 ( V_24 , L_14 ) ;
if ( V_131 -> V_467 ) {
F_52 ( V_98 , V_400 ,
V_131 -> V_468 ) ;
F_59 ( V_98 , L_187 , L_188 , 4 ) ;
F_24 ( V_98 , L_189 , 0 ) ;
V_131 -> V_467 = false ;
}
return 0 ;
}
static void F_137 ( struct V_130 * V_131 ,
struct V_97 * V_98 ,
struct V_469 * V_470 )
{
T_5 V_471 ;
F_3 ( V_24 , L_190 ) ;
F_107 ( V_98 , V_472 , & V_131 -> V_468 ) ;
F_52 ( V_98 , V_400 , V_473 ) ;
V_471 = 0 ;
if ( V_470 -> V_474 )
V_471 |= V_475 | V_476 | V_477 ;
if ( V_470 -> V_478 )
V_471 |= V_479 ;
F_24 ( V_98 , L_191 , V_471 ) ;
F_24 ( V_98 , L_192 , 1 ) ;
F_138 ( V_131 -> V_463 -> V_480 , true ) ;
V_131 -> V_467 = true ;
}
static T_4 F_139 ( struct V_114 * V_114 ,
struct V_469 * V_470 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_94 * V_95 = F_73 ( V_131 ) ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_1 * V_2 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
goto exit;
if ( F_2 ( V_153 , & V_131 -> V_154 ) )
F_120 ( V_131 ) ;
if ( V_470 == NULL ) {
F_138 ( V_131 -> V_463 -> V_480 , false ) ;
F_140 (vif, &cfg->vif_list, list) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
continue;
F_75 ( V_2 ) ;
F_132 ( 500 ) ;
}
F_36 ( V_98 , 1 ) ;
} else {
F_137 ( V_131 , V_98 , V_470 ) ;
}
exit:
F_3 ( V_24 , L_31 ) ;
V_131 -> V_154 = 0 ;
return 0 ;
}
static T_8 T_4
F_141 ( struct V_94 * V_95 ,
struct V_481 * V_482 , T_4 V_96 )
{
int V_169 , V_483 ;
int V_484 ;
V_484 = F_106 ( V_482 -> V_485 . V_486 ) ;
F_3 ( V_253 , L_193 , V_484 ) ;
for ( V_169 = 0 ; V_169 < V_484 ; V_169 ++ ) {
F_3 ( V_253 , L_194 , V_169 ,
& V_482 -> V_485 . V_487 [ V_169 ] . V_425 ) ;
for ( V_483 = 0 ; V_483 < V_488 ; V_483 ++ )
F_3 ( V_253 , L_195 ,
V_482 -> V_485 . V_487 [ V_169 ] . V_489 [ V_483 ] ) ;
}
if ( ! V_96 )
F_59 ( F_21 ( V_95 ) , L_196 ,
( char * ) V_482 , sizeof( * V_482 ) ) ;
return V_96 ;
}
static T_4
F_142 ( struct V_114 * V_114 , struct V_94 * V_95 ,
struct V_490 * V_491 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_492 * V_485 = & V_131 -> V_482 -> V_485 ;
T_4 V_96 = 0 ;
int V_169 ;
int V_484 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
V_484 = F_106 ( V_485 -> V_486 ) ;
for ( V_169 = 0 ; V_169 < V_484 ; V_169 ++ )
if ( ! memcmp ( V_491 -> V_140 , V_485 -> V_487 [ V_169 ] . V_425 , V_141 ) )
break;
if ( V_169 < V_493 ) {
memcpy ( V_485 -> V_487 [ V_169 ] . V_425 , V_491 -> V_140 , V_141 ) ;
memcpy ( V_485 -> V_487 [ V_169 ] . V_489 , V_491 -> V_487 , V_488 ) ;
if ( V_169 == V_484 ) {
V_484 ++ ;
V_485 -> V_486 = F_16 ( V_484 ) ;
}
} else
V_96 = - V_127 ;
F_3 ( V_253 , L_197 ,
V_485 -> V_487 [ V_484 ] . V_425 ) ;
for ( V_169 = 0 ; V_169 < V_488 ; V_169 ++ )
F_3 ( V_253 , L_195 , V_485 -> V_487 [ V_484 ] . V_489 [ V_169 ] ) ;
V_96 = F_141 ( V_95 , V_131 -> V_482 , V_96 ) ;
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4
F_143 ( struct V_114 * V_114 , struct V_94 * V_95 ,
struct V_490 * V_491 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_492 V_487 ;
T_4 V_96 = 0 ;
int V_169 , V_484 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
memcpy ( & V_487 . V_487 [ 0 ] . V_425 , V_491 -> V_140 , V_141 ) ;
memcpy ( & V_487 . V_487 [ 0 ] . V_489 , V_491 -> V_487 , V_488 ) ;
F_3 ( V_253 , L_198 ,
& V_487 . V_487 [ 0 ] . V_425 ) ;
for ( V_169 = 0 ; V_169 < V_488 ; V_169 ++ )
F_3 ( V_253 , L_195 , V_487 . V_487 [ 0 ] . V_489 [ V_169 ] ) ;
V_484 = F_106 ( V_131 -> V_482 -> V_485 . V_486 ) ;
for ( V_169 = 0 ; V_169 < V_484 ; V_169 ++ )
if ( ! memcmp
( V_491 -> V_140 , & V_131 -> V_482 -> V_485 . V_487 [ V_169 ] . V_425 ,
V_141 ) )
break;
if ( ( V_484 > 0 )
&& ( V_169 < V_484 ) ) {
memset ( & V_131 -> V_482 -> V_485 . V_487 [ V_169 ] , 0 ,
sizeof( struct V_487 ) ) ;
for (; V_169 < ( V_484 - 1 ) ; V_169 ++ ) {
memcpy ( & V_131 -> V_482 -> V_485 . V_487 [ V_169 ] . V_425 ,
& V_131 -> V_482 -> V_485 . V_487 [ V_169 + 1 ] . V_425 ,
V_141 ) ;
memcpy ( & V_131 -> V_482 -> V_485 . V_487 [ V_169 ] . V_489 ,
& V_131 -> V_482 -> V_485 . V_487 [ V_169 + 1 ] . V_489 ,
V_488 ) ;
}
V_131 -> V_482 -> V_485 . V_486 = F_16 ( V_484 - 1 ) ;
} else
V_96 = - V_127 ;
V_96 = F_141 ( V_95 , V_131 -> V_482 , V_96 ) ;
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4
F_144 ( struct V_114 * V_114 , struct V_94 * V_95 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
T_4 V_96 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
memset ( V_131 -> V_482 , 0 , sizeof( * V_131 -> V_482 ) ) ;
V_96 = F_141 ( V_95 , V_131 -> V_482 , V_96 ) ;
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4
F_145 ( struct V_97 * V_98 ,
const struct V_449 * V_450 , void * V_92 )
{
struct V_130 * V_131 = V_98 -> V_109 -> V_451 ;
struct V_494 * V_495 , * V_496 ;
struct V_136 * V_166 = NULL ;
struct V_207 * V_180 = NULL ;
struct V_58 * V_264 = NULL ;
struct V_114 * V_114 = F_42 ( V_131 ) ;
int V_96 = 0 ;
int V_497 = 0 ;
int V_50 = 0 ;
struct V_498 * V_499 ;
T_5 V_500 ;
T_5 V_452 ;
F_3 ( V_138 , L_14 ) ;
if ( V_450 -> V_501 == V_502 ) {
F_3 ( V_138 , L_199 ) ;
return 0 ;
}
V_499 = (struct V_498 * ) V_92 ;
V_500 = F_106 ( V_499 -> V_203 ) ;
V_452 = F_106 ( V_499 -> V_452 ) ;
F_8 ( V_452 != V_503 ) ;
F_3 ( V_138 , L_200 , V_500 ) ;
if ( V_500 > 0 ) {
int V_169 ;
V_166 = F_57 ( sizeof( * V_166 ) , V_188 ) ;
V_180 = F_146 ( V_500 , sizeof( * V_180 ) , V_188 ) ;
V_264 = F_146 ( V_500 , sizeof( * V_264 ) , V_188 ) ;
if ( ! V_166 || ! V_180 || ! V_264 ) {
V_96 = - V_189 ;
goto V_504;
}
V_166 -> V_114 = V_114 ;
V_92 += sizeof( struct V_498 ) ;
V_496 = (struct V_494 * ) V_92 ;
for ( V_169 = 0 ; V_169 < V_500 ; V_169 ++ ) {
V_495 = & V_496 [ V_169 ] ;
if ( ! V_495 ) {
F_22 ( L_201 ,
V_169 ) ;
V_96 = - V_127 ;
goto V_504;
}
F_3 ( V_138 , L_202 ,
V_495 -> V_179 , V_495 -> V_264 ) ;
memcpy ( V_180 [ V_169 ] . V_180 , V_495 -> V_179 , V_495 -> V_176 ) ;
V_180 [ V_169 ] . V_178 = V_495 -> V_176 ;
V_166 -> V_167 ++ ;
V_497 = V_495 -> V_264 ;
if ( V_497 <= V_418 )
V_50 = V_505 ;
else
V_50 = V_506 ;
V_264 [ V_169 ] . V_26 =
F_112 ( V_497 ,
V_50 ) ;
V_264 [ V_169 ] . V_50 = V_50 ;
V_264 [ V_169 ] . V_87 |= V_507 ;
V_166 -> V_174 [ V_169 ] = & V_264 [ V_169 ] ;
V_166 -> V_168 ++ ;
}
if ( V_166 -> V_167 )
V_166 -> V_177 = & V_180 [ 0 ] ;
if ( F_2 ( V_153 , & V_131 -> V_154 ) ) {
F_120 ( V_131 ) ;
}
F_51 ( V_153 , & V_131 -> V_154 ) ;
V_131 -> V_157 . V_205 = F_56 ;
V_96 = F_61 ( V_131 , V_114 , V_98 , V_166 ) ;
if ( V_96 ) {
F_67 ( V_153 , & V_131 -> V_154 ) ;
goto V_504;
}
V_131 -> V_152 = true ;
V_131 -> V_137 = V_166 ;
} else {
F_22 ( L_203 ) ;
goto V_504;
}
F_60 ( V_180 ) ;
F_60 ( V_264 ) ;
F_60 ( V_166 ) ;
return 0 ;
V_504:
F_60 ( V_180 ) ;
F_60 ( V_264 ) ;
F_60 ( V_166 ) ;
F_147 ( V_114 ) ;
return V_96 ;
}
static int F_148 ( struct V_94 * V_95 )
{
int V_508 ;
V_508 = F_24 ( F_21 ( V_95 ) , L_204 , 0 ) ;
if ( V_508 == 0 ) {
V_508 = F_59 ( F_21 ( V_95 ) , L_205 ,
NULL , 0 ) ;
}
if ( V_508 < 0 )
F_22 ( L_206 , V_508 ) ;
return V_508 ;
}
static int F_149 ( struct V_94 * V_95 )
{
struct V_509 V_510 ;
memset ( & V_510 , 0 , sizeof( V_510 ) ) ;
V_510 . V_191 = F_16 ( V_511 ) ;
V_510 . V_87 = F_17 ( 1 << V_512 ) ;
V_510 . V_513 = V_514 ;
V_510 . exp = V_515 ;
V_510 . V_516 = F_16 ( V_517 ) ;
return F_59 ( F_21 ( V_95 ) , L_207 ,
& V_510 , sizeof( V_510 ) ) ;
}
static int
F_150 ( struct V_114 * V_114 ,
struct V_94 * V_95 ,
struct V_518 * V_166 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_130 * V_131 = F_46 ( V_114 ) ;
struct V_519 V_520 ;
int V_169 ;
int V_508 = 0 ;
F_3 ( V_138 , L_208 ,
V_166 -> V_521 , V_166 -> V_167 ) ;
if ( F_2 ( V_153 , & V_131 -> V_154 ) ) {
F_22 ( L_45 , V_131 -> V_154 ) ;
return - V_164 ;
}
if ( F_2 ( V_215 , & V_131 -> V_154 ) ) {
F_22 ( L_47 ,
V_131 -> V_154 ) ;
return - V_164 ;
}
if ( ! V_166 -> V_167 || ! V_166 -> V_521 ) {
F_3 ( V_138 , L_209 ,
V_166 -> V_167 ) ;
return - V_127 ;
}
if ( V_166 -> V_167 > 0 ) {
for ( V_169 = 0 ; V_169 < V_166 -> V_167 ; V_169 ++ ) {
F_3 ( V_138 , L_210 ,
V_166 -> V_177 [ V_169 ] . V_180 ) ;
}
}
if ( V_166 -> V_521 > 0 ) {
V_508 = F_148 ( V_95 ) ;
if ( V_508 < 0 ) {
F_22 ( L_211 , V_508 ) ;
return V_508 ;
}
V_508 = F_149 ( V_95 ) ;
if ( V_508 < 0 ) {
F_22 ( L_212 , V_508 ) ;
return - V_127 ;
}
for ( V_169 = 0 ; V_169 < V_166 -> V_521 ; V_169 ++ ) {
struct V_207 * V_180 ;
T_5 V_178 ;
V_180 = & V_166 -> V_522 [ V_169 ] . V_180 ;
V_178 = V_180 -> V_178 ;
if ( ! V_178 ) {
F_22 ( L_213 ) ;
continue;
}
V_520 . V_523 = F_16 ( V_524 ) ;
V_520 . V_308 = F_16 ( V_525 ) ;
V_520 . V_251 = F_16 ( 0 ) ;
V_520 . V_158 = F_16 ( 1 ) ;
V_520 . V_87 = F_16 ( 1 << V_526 ) ;
V_520 . V_180 . V_176 = F_16 ( V_178 ) ;
memcpy ( V_520 . V_180 . V_179 , V_180 -> V_180 , V_178 ) ;
V_508 = F_59 ( V_98 , L_214 , & V_520 ,
sizeof( V_520 ) ) ;
F_3 ( V_138 , L_215 ,
V_508 == 0 ? L_216 : L_217 , V_180 -> V_180 ) ;
}
if ( F_24 ( V_98 , L_204 , 1 ) < 0 ) {
F_22 ( L_218 , V_508 ) ;
return - V_127 ;
}
} else {
return - V_127 ;
}
return 0 ;
}
static int F_151 ( struct V_114 * V_114 ,
struct V_94 * V_95 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
F_3 ( V_138 , L_219 ) ;
F_148 ( V_95 ) ;
if ( V_131 -> V_152 )
F_37 ( V_131 , F_21 ( V_95 ) , true , true ) ;
return 0 ;
}
static T_4 F_152 ( struct V_97 * V_98 )
{
T_4 V_96 ;
V_96 = F_82 ( V_98 , L_90 , 0 ) ;
if ( V_96 < 0 ) {
F_22 ( L_220 , V_96 ) ;
return V_96 ;
}
V_96 = F_82 ( V_98 , L_77 , 0 ) ;
if ( V_96 < 0 ) {
F_22 ( L_221 , V_96 ) ;
return V_96 ;
}
V_96 = F_82 ( V_98 , L_83 , V_527 ) ;
if ( V_96 < 0 ) {
F_22 ( L_222 , V_96 ) ;
return V_96 ;
}
return 0 ;
}
static bool F_153 ( T_2 * V_71 , bool V_528 )
{
if ( V_528 )
return ( memcmp ( V_71 , V_529 , V_79 ) == 0 ) ;
return ( memcmp ( V_71 , V_78 , V_79 ) == 0 ) ;
}
static T_4
F_154 ( struct V_94 * V_95 ,
const struct V_75 * V_318 ,
bool V_528 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
T_5 V_523 = 0 ;
T_1 V_203 ;
T_4 V_96 = 0 ;
T_4 V_66 = 0 ;
T_5 V_169 ;
T_5 V_251 ;
T_5 V_290 = 0 ;
T_5 V_291 = 0 ;
T_5 V_308 = 0 ;
T_5 V_13 ;
T_2 * V_92 ;
T_1 V_530 ;
T_5 V_531 ;
F_3 ( V_24 , L_14 ) ;
if ( V_318 == NULL )
goto exit;
V_66 = V_318 -> V_66 + V_65 ;
V_92 = ( T_2 * ) V_318 ;
V_13 = V_65 ;
if ( ! V_528 )
V_13 += V_532 ;
else
V_13 += V_533 ;
if ( V_13 + V_534 > V_66 ) {
V_96 = - V_127 ;
F_22 ( L_223 ) ;
goto exit;
}
if ( ! F_153 ( & V_92 [ V_13 ] , V_528 ) ) {
V_96 = - V_127 ;
F_22 ( L_224 ) ;
goto exit;
}
V_13 += V_79 ;
switch ( V_92 [ V_13 ] ) {
case V_535 :
V_291 = 0 ;
break;
case V_536 :
case V_537 :
V_291 = V_260 ;
break;
case V_538 :
V_291 = V_297 ;
break;
case V_539 :
V_291 = V_299 ;
break;
default:
V_96 = - V_127 ;
F_22 ( L_225 ) ;
goto exit;
}
V_13 ++ ;
V_203 = V_92 [ V_13 ] + ( V_92 [ V_13 + 1 ] << 8 ) ;
V_13 += V_540 ;
if ( V_13 + ( V_534 * V_203 ) > V_66 ) {
V_96 = - V_127 ;
F_22 ( L_226 ) ;
goto exit;
}
for ( V_169 = 0 ; V_169 < V_203 ; V_169 ++ ) {
if ( ! F_153 ( & V_92 [ V_13 ] , V_528 ) ) {
V_96 = - V_127 ;
F_22 ( L_224 ) ;
goto exit;
}
V_13 += V_79 ;
switch ( V_92 [ V_13 ] ) {
case V_535 :
break;
case V_536 :
case V_537 :
V_290 |= V_260 ;
break;
case V_538 :
V_290 |= V_297 ;
break;
case V_539 :
V_290 |= V_299 ;
break;
default:
F_22 ( L_227 ) ;
}
V_13 ++ ;
}
V_203 = V_92 [ V_13 ] + ( V_92 [ V_13 + 1 ] << 8 ) ;
V_13 += V_540 ;
if ( V_13 + ( V_534 * V_203 ) > V_66 ) {
V_96 = - V_127 ;
F_22 ( L_228 ) ;
goto exit;
}
for ( V_169 = 0 ; V_169 < V_203 ; V_169 ++ ) {
if ( ! F_153 ( & V_92 [ V_13 ] , V_528 ) ) {
V_96 = - V_127 ;
F_22 ( L_224 ) ;
goto exit;
}
V_13 += V_79 ;
switch ( V_92 [ V_13 ] ) {
case V_541 :
F_3 ( V_24 , L_229 ) ;
V_308 |= V_527 ;
break;
case V_542 :
F_3 ( V_24 , L_230 ) ;
V_528 ? ( V_308 |= V_282 ) :
( V_308 |= V_279 ) ;
break;
case V_543 :
F_3 ( V_24 , L_231 ) ;
V_528 ? ( V_308 |= V_281 ) :
( V_308 |= V_278 ) ;
break;
default:
F_22 ( L_232 ) ;
}
V_13 ++ ;
}
if ( V_528 ) {
V_531 = 1 ;
if ( ( V_13 + V_544 ) <= V_66 ) {
V_530 = V_92 [ V_13 ] + ( V_92 [ V_13 + 1 ] << 8 ) ;
if ( V_530 & V_545 )
V_531 = 0 ;
}
V_96 = F_82 ( V_98 , L_233 ,
V_531 ) ;
if ( V_96 < 0 ) {
F_22 ( L_234 , V_96 ) ;
goto exit;
}
}
V_251 = ( V_290 | V_291 | V_546 ) ;
V_96 = F_82 ( V_98 , L_90 , V_523 ) ;
if ( V_96 < 0 ) {
F_22 ( L_220 , V_96 ) ;
goto exit;
}
V_96 = F_82 ( V_98 , L_77 , V_251 ) ;
if ( V_96 < 0 ) {
F_22 ( L_221 , V_96 ) ;
goto exit;
}
V_96 = F_82 ( V_98 , L_83 , V_308 ) ;
if ( V_96 < 0 ) {
F_22 ( L_222 , V_96 ) ;
goto exit;
}
exit:
return V_96 ;
}
static T_4
F_155 ( const T_2 * V_547 , T_5 V_548 ,
struct V_549 * V_550 )
{
struct V_75 * V_551 ;
struct V_59 * V_68 ;
struct V_552 * V_553 ;
T_4 V_554 ;
V_554 = ( T_4 ) V_548 ;
memset ( V_550 , 0 , sizeof( * V_550 ) ) ;
V_68 = (struct V_59 * ) V_547 ;
while ( V_68 ) {
if ( V_68 -> V_67 != V_77 )
goto V_555;
V_551 = (struct V_75 * ) V_68 ;
if ( V_551 -> V_66 < ( V_532 - V_65 + 1 ) ) {
F_22 ( L_235 ,
V_551 -> V_66 ) ;
goto V_555;
}
if ( ! memcmp ( V_551 -> V_71 , ( T_2 * ) V_78 , V_79 ) &&
( ( V_551 -> V_556 == V_80 ) ||
( V_551 -> V_556 == V_557 ) ) ) {
F_3 ( V_24 , L_236 ) ;
goto V_555;
}
V_553 = & V_550 -> V_558 [ V_550 -> V_203 ] ;
V_553 -> V_559 = ( char * ) V_551 ;
V_553 -> V_256 = V_551 -> V_66 + V_65 ;
memcpy ( & V_553 -> V_551 , V_551 , sizeof( * V_551 ) ) ;
V_550 -> V_203 ++ ;
F_3 ( V_24 , L_237 ,
V_553 -> V_551 . V_71 [ 0 ] ,
V_553 -> V_551 . V_71 [ 1 ] ,
V_553 -> V_551 . V_71 [ 2 ] ,
V_553 -> V_551 . V_556 ) ;
if ( V_550 -> V_203 >= V_560 )
break;
V_555:
V_554 -= ( V_68 -> V_66 + V_65 ) ;
if ( V_554 <= V_65 )
V_68 = NULL ;
else
V_68 = (struct V_59 * ) ( ( ( T_2 * ) V_68 ) + V_68 -> V_66 +
V_65 ) ;
}
return 0 ;
}
static T_5
F_156 ( T_2 * V_561 , T_4 V_562 , T_2 * V_559 , T_5 V_256 , T_9 * V_563 )
{
V_432 V_564 ;
V_432 V_565 ;
strncpy ( V_561 , V_563 , V_566 - 1 ) ;
V_561 [ V_566 - 1 ] = '\0' ;
V_564 = F_16 ( 1 ) ;
memcpy ( & V_561 [ V_567 ] , & V_564 , sizeof( V_564 ) ) ;
V_565 = F_16 ( V_562 ) ;
memcpy ( & V_561 [ V_568 ] , & V_565 , sizeof( V_565 ) ) ;
memcpy ( & V_561 [ V_569 ] , V_559 , V_256 ) ;
return V_256 + V_570 ;
}
T_4 F_90 ( struct V_1 * V_2 , T_4 V_562 ,
const T_2 * V_547 , T_5 V_548 )
{
struct V_97 * V_98 ;
struct V_571 * V_572 ;
T_4 V_96 = 0 ;
T_2 * V_573 ;
T_2 * V_574 ;
T_2 * V_575 = NULL ;
int V_576 ;
T_5 * V_577 ;
T_5 V_578 = 0 ;
T_5 V_579 = 0 ;
T_5 V_580 = 0 ;
struct V_549 V_581 ;
struct V_549 V_582 ;
struct V_552 * V_583 ;
T_4 V_169 ;
T_2 * V_171 ;
int V_584 ;
if ( ! V_2 )
return - V_401 ;
V_98 = V_2 -> V_98 ;
V_572 = & V_2 -> V_572 ;
F_3 ( V_24 , L_238 , V_98 -> V_456 , V_562 ) ;
V_573 = F_57 ( V_436 , V_188 ) ;
if ( ! V_573 )
return - V_189 ;
V_574 = V_573 ;
switch ( V_562 ) {
case V_585 :
V_575 = V_572 -> V_586 ;
V_577 = & V_572 -> V_587 ;
V_576 = sizeof( V_572 -> V_586 ) ;
break;
case V_588 :
V_575 = V_572 -> V_589 ;
V_577 = & V_572 -> V_590 ;
V_576 = sizeof( V_572 -> V_589 ) ;
break;
case V_591 :
V_575 = V_572 -> V_592 ;
V_577 = & V_572 -> V_593 ;
V_576 = sizeof( V_572 -> V_592 ) ;
break;
case V_322 :
V_575 = V_572 -> V_594 ;
V_577 = & V_572 -> V_595 ;
V_576 = sizeof( V_572 -> V_594 ) ;
break;
default:
V_96 = - V_393 ;
F_22 ( L_239 ) ;
goto exit;
}
if ( V_548 > V_576 ) {
V_96 = - V_189 ;
F_22 ( L_240 ) ;
goto exit;
}
if ( V_547 && V_548 && V_574 ) {
V_171 = V_574 ;
F_155 ( V_547 , V_548 , & V_582 ) ;
for ( V_169 = 0 ; V_169 < V_582 . V_203 ; V_169 ++ ) {
V_583 = & V_582 . V_558 [ V_169 ] ;
memcpy ( V_171 + V_580 , V_583 -> V_559 ,
V_583 -> V_256 ) ;
V_580 += V_583 -> V_256 ;
}
}
if ( V_575 && * V_577 ) {
if ( V_580 && ( V_580 == * V_577 ) &&
( memcmp ( V_575 , V_574 ,
V_580 ) == 0 ) ) {
F_3 ( V_24 , L_241 ) ;
goto exit;
}
F_155 ( V_575 , * V_577 , & V_581 ) ;
for ( V_169 = 0 ; V_169 < V_581 . V_203 ; V_169 ++ ) {
V_583 = & V_581 . V_558 [ V_169 ] ;
F_3 ( V_24 , L_242 ,
V_583 -> V_551 . V_67 ,
V_583 -> V_551 . V_66 ,
V_583 -> V_551 . V_71 [ 0 ] ,
V_583 -> V_551 . V_71 [ 1 ] ,
V_583 -> V_551 . V_71 [ 2 ] ) ;
V_578 = F_156 ( V_574 , V_562 ,
V_583 -> V_559 ,
V_583 -> V_256 ,
L_243 ) ;
V_574 += V_578 ;
V_579 += V_578 ;
}
}
* V_577 = 0 ;
if ( V_575 && V_580 ) {
V_171 = V_575 ;
V_584 = V_576 ;
for ( V_169 = 0 ; V_169 < V_582 . V_203 ; V_169 ++ ) {
V_583 = & V_582 . V_558 [ V_169 ] ;
if ( V_584 < ( V_583 -> V_551 . V_66 +
V_569 ) ) {
F_22 ( L_244 ,
V_584 ) ;
break;
}
V_584 -= ( V_583 -> V_256 +
V_569 ) ;
F_3 ( V_24 , L_245 ,
V_583 -> V_551 . V_67 ,
V_583 -> V_551 . V_66 ,
V_583 -> V_551 . V_71 [ 0 ] ,
V_583 -> V_551 . V_71 [ 1 ] ,
V_583 -> V_551 . V_71 [ 2 ] ) ;
V_578 = F_156 ( V_574 , V_562 ,
V_583 -> V_559 ,
V_583 -> V_256 ,
L_246 ) ;
memcpy ( V_171 + ( * V_577 ) , V_583 -> V_559 ,
V_583 -> V_256 ) ;
* V_577 += V_583 -> V_256 ;
V_574 += V_578 ;
V_579 += V_578 ;
}
}
if ( V_579 ) {
V_96 = F_20 ( V_98 , L_247 , V_573 ,
V_579 ) ;
if ( V_96 )
F_22 ( L_248 , V_96 ) ;
}
exit:
F_60 ( V_573 ) ;
return V_96 ;
}
T_4 F_157 ( struct V_1 * V_2 )
{
T_4 V_596 [] = {
V_585 ,
V_588 ,
V_591
} ;
int V_169 ;
for ( V_169 = 0 ; V_169 < F_158 ( V_596 ) ; V_169 ++ )
F_90 ( V_2 , V_596 [ V_169 ] , NULL , 0 ) ;
memset ( & V_2 -> V_572 , 0 , sizeof( V_2 -> V_572 ) ) ;
return 0 ;
}
static T_4
F_159 ( struct V_1 * V_2 ,
struct V_597 * V_598 )
{
T_4 V_96 ;
V_96 = F_90 ( V_2 , V_591 ,
V_598 -> V_599 , V_598 -> V_600 ) ;
if ( V_96 ) {
F_22 ( L_249 ) ;
return V_96 ;
}
F_3 ( V_24 , L_250 ) ;
V_96 = F_90 ( V_2 , V_588 ,
V_598 -> V_601 ,
V_598 -> V_602 ) ;
if ( V_96 )
F_22 ( L_251 ) ;
else
F_3 ( V_24 , L_252 ) ;
return V_96 ;
}
static T_4
F_160 ( struct V_114 * V_114 , struct V_94 * V_95 ,
struct V_603 * V_604 )
{
T_4 V_421 ;
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
const struct V_59 * V_605 ;
struct V_172 V_173 ;
T_4 V_96 = - V_393 ;
const struct V_59 * V_317 ;
const struct V_75 * V_318 ;
struct V_248 V_249 ;
enum V_113 V_606 ;
struct V_607 V_608 ;
T_1 V_170 ;
F_3 ( V_24 , L_253 ,
V_604 -> V_254 . V_25 -> V_175 ,
V_604 -> V_254 . V_27 , V_604 -> V_254 . V_28 ,
V_604 -> V_257 , V_604 -> V_373 ) ;
F_3 ( V_24 , L_254 ,
V_604 -> V_180 , V_604 -> V_178 , V_604 -> V_284 ,
V_604 -> V_609 ) ;
V_606 = V_98 -> V_2 -> V_104 . V_105 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
if ( V_604 -> V_180 == NULL || V_604 -> V_178 == 0 ) {
V_421 = V_610 + V_611 ;
V_605 = F_11 (
( T_2 * ) & V_604 -> V_598 . V_612 [ V_421 ] ,
V_604 -> V_598 . V_613 - V_421 ,
V_614 ) ;
if ( ! V_605 )
return - V_127 ;
memcpy ( V_173 . V_179 , V_605 -> V_92 , V_605 -> V_66 ) ;
V_173 . V_176 = F_16 ( V_605 -> V_66 ) ;
F_3 ( V_24 , L_255 , V_173 . V_179 ) ;
} else {
memcpy ( V_173 . V_179 , V_604 -> V_180 , V_604 -> V_178 ) ;
V_173 . V_176 = F_16 ( ( T_5 ) V_604 -> V_178 ) ;
}
F_36 ( V_98 , 0 ) ;
F_23 ( V_98 , false ) ;
V_317 = F_11 ( ( T_2 * ) V_604 -> V_598 . V_599 ,
V_604 -> V_598 . V_600 , V_321 ) ;
V_318 = F_13 ( ( T_2 * ) V_604 -> V_598 . V_599 ,
V_604 -> V_598 . V_600 ) ;
if ( ( V_318 != NULL || V_317 != NULL ) ) {
F_3 ( V_24 , L_256 ) ;
if ( V_318 != NULL ) {
V_96 = F_154 ( V_95 , V_318 , false ) ;
if ( V_96 < 0 )
goto exit;
} else {
V_96 = F_154 ( V_95 ,
(struct V_75 * ) V_317 , true ) ;
if ( V_96 < 0 )
goto exit;
}
} else {
F_3 ( V_24 , L_257 ) ;
F_152 ( V_98 ) ;
}
F_159 ( V_98 -> V_2 , & V_604 -> V_598 ) ;
V_170 = F_6 ( & V_131 -> V_18 , & V_604 -> V_254 ) ;
V_96 = F_24 ( V_98 , L_258 , V_170 ) ;
if ( V_96 < 0 ) {
F_22 ( L_259 , V_170 , V_96 ) ;
goto exit;
}
if ( V_604 -> V_257 ) {
V_96 = F_52 ( V_98 , V_261 ,
V_604 -> V_257 ) ;
if ( V_96 < 0 ) {
F_22 ( L_260 , V_96 ) ;
goto exit;
}
}
if ( V_604 -> V_373 ) {
V_96 = F_52 ( V_98 , V_615 ,
V_604 -> V_373 ) ;
if ( V_96 < 0 ) {
F_22 ( L_261 , V_96 ) ;
goto exit;
}
}
if ( V_606 == V_107 ) {
V_96 = F_52 ( V_98 , V_616 , 1 ) ;
if ( V_96 < 0 ) {
F_22 ( L_262 , V_96 ) ;
goto exit;
}
F_24 ( V_98 , L_263 , 0 ) ;
}
V_96 = F_52 ( V_98 , V_163 , 1 ) ;
if ( V_96 < 0 ) {
F_22 ( L_264 , V_96 ) ;
goto exit;
}
if ( V_606 == V_107 ) {
V_96 = F_52 ( V_98 , V_617 , 1 ) ;
if ( V_96 < 0 ) {
F_22 ( L_265 , V_96 ) ;
goto exit;
}
V_96 = F_52 ( V_98 , V_618 , 1 ) ;
if ( V_96 < 0 ) {
F_22 ( L_266 , V_96 ) ;
goto exit;
}
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
memcpy ( & V_249 . V_173 , & V_173 , sizeof( V_173 ) ) ;
V_96 = F_40 ( V_98 , V_269 ,
& V_249 , sizeof( V_249 ) ) ;
if ( V_96 < 0 ) {
F_22 ( L_267 , V_96 ) ;
goto exit;
}
F_3 ( V_24 , L_268 ) ;
} else {
V_96 = F_20 ( V_98 , L_269 , & V_173 ,
sizeof( V_173 ) ) ;
if ( V_96 < 0 ) {
F_22 ( L_270 , V_96 ) ;
goto exit;
}
V_608 . V_619 = F_16 ( V_98 -> V_456 ) ;
V_608 . V_99 = F_16 ( 1 ) ;
V_96 = F_59 ( V_98 , L_271 , & V_608 ,
sizeof( V_608 ) ) ;
if ( V_96 < 0 ) {
F_22 ( L_272 , V_96 ) ;
goto exit;
}
F_3 ( V_24 , L_273 ) ;
}
F_67 ( V_162 , & V_98 -> V_2 -> V_4 ) ;
F_51 ( V_620 , & V_98 -> V_2 -> V_4 ) ;
exit:
if ( V_96 ) {
F_36 ( V_98 , 1 ) ;
F_23 ( V_98 , true ) ;
}
return V_96 ;
}
static int F_161 ( struct V_114 * V_114 , struct V_94 * V_95 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
T_4 V_96 ;
struct V_607 V_608 ;
struct V_248 V_249 ;
F_3 ( V_24 , L_14 ) ;
if ( V_98 -> V_2 -> V_104 . V_105 == V_107 ) {
F_135 ( 400 ) ;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
V_96 = F_40 ( V_98 , V_269 ,
& V_249 , sizeof( V_249 ) ) ;
if ( V_96 < 0 )
F_22 ( L_267 , V_96 ) ;
V_96 = F_52 ( V_98 , V_618 , 0 ) ;
if ( V_96 < 0 )
F_22 ( L_274 , V_96 ) ;
V_96 = F_52 ( V_98 , V_617 , 0 ) ;
if ( V_96 < 0 )
F_22 ( L_265 , V_96 ) ;
V_96 = F_52 ( V_98 , V_163 , 0 ) ;
if ( V_96 < 0 )
F_22 ( L_275 , V_96 ) ;
} else {
V_608 . V_619 = F_16 ( V_98 -> V_456 ) ;
V_608 . V_99 = F_16 ( 0 ) ;
V_96 = F_59 ( V_98 , L_271 , & V_608 ,
sizeof( V_608 ) ) ;
if ( V_96 < 0 )
F_22 ( L_272 , V_96 ) ;
}
F_36 ( V_98 , 1 ) ;
F_23 ( V_98 , true ) ;
F_51 ( V_162 , & V_98 -> V_2 -> V_4 ) ;
F_67 ( V_620 , & V_98 -> V_2 -> V_4 ) ;
return V_96 ;
}
static T_4
F_162 ( struct V_114 * V_114 , struct V_94 * V_95 ,
struct V_597 * V_621 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
T_4 V_96 ;
F_3 ( V_24 , L_14 ) ;
V_96 = F_159 ( V_98 -> V_2 , V_621 ) ;
return V_96 ;
}
static int
F_163 ( struct V_114 * V_114 , struct V_94 * V_95 ,
const T_2 * V_364 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_332 V_333 ;
struct V_97 * V_98 = F_21 ( V_95 ) ;
T_4 V_96 ;
if ( ! V_364 )
return - V_622 ;
F_3 ( V_24 , L_276 , V_364 ) ;
if ( V_98 -> V_2 == V_131 -> V_217 . V_218 [ V_219 ] . V_2 )
V_98 = V_131 -> V_217 . V_218 [ V_220 ] . V_2 -> V_98 ;
if ( ! F_1 ( V_98 -> V_2 ) )
return - V_225 ;
memcpy ( & V_333 . V_93 , V_364 , V_141 ) ;
V_333 . V_274 = F_16 ( V_623 ) ;
V_96 = F_40 ( V_98 , V_624 ,
& V_333 , sizeof( V_333 ) ) ;
if ( V_96 )
F_22 ( L_277 , V_96 ) ;
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static void
F_164 ( struct V_114 * V_114 ,
struct V_103 * V_104 ,
T_1 V_625 , bool V_626 )
{
struct V_1 * V_2 ;
T_1 V_627 ;
F_3 ( V_24 , L_278 , V_625 , V_626 ) ;
V_627 = ( V_625 & V_628 ) >> 4 ;
V_2 = F_26 ( V_104 , struct V_1 , V_104 ) ;
if ( V_626 )
V_2 -> V_629 |= F_127 ( V_627 ) ;
else
V_2 -> V_629 &= ~ F_127 ( V_627 ) ;
}
static int
F_165 ( struct V_114 * V_114 , struct V_103 * V_104 ,
struct V_630 * V_117 , T_10 * V_363 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_58 * V_25 = V_117 -> V_25 ;
const T_2 * V_60 = V_117 -> V_60 ;
T_6 V_66 = V_117 -> V_66 ;
const struct V_631 * V_632 ;
struct V_1 * V_2 ;
T_4 V_96 = 0 ;
T_4 V_421 ;
T_4 V_256 ;
struct V_633 * V_634 ;
struct V_635 * V_636 ;
bool V_637 ;
T_4 V_638 ;
T_5 V_408 ;
F_3 ( V_24 , L_14 ) ;
* V_363 = 0 ;
V_632 = ( const struct V_631 * ) V_60 ;
if ( ! F_166 ( V_632 -> V_639 ) ) {
F_22 ( L_279 ) ;
return - V_393 ;
}
V_2 = F_26 ( V_104 , struct V_1 , V_104 ) ;
if ( F_167 ( V_632 -> V_639 ) ) {
V_421 = V_610 +
V_611 ;
V_256 = V_66 - V_421 ;
if ( V_2 == V_131 -> V_217 . V_218 [ V_220 ] . V_2 )
V_2 = V_131 -> V_217 . V_218 [ V_219 ] . V_2 ;
V_96 = F_90 ( V_2 ,
V_588 ,
& V_60 [ V_421 ] ,
V_256 ) ;
F_168 ( V_104 , * V_363 , V_60 , V_66 , true ,
V_188 ) ;
} else if ( F_169 ( V_632 -> V_639 ) ) {
V_636 = F_57 ( sizeof( * V_636 ) , V_188 ) ;
if ( V_636 == NULL ) {
F_22 ( L_280 ) ;
V_96 = - V_189 ;
goto exit;
}
V_634 = & V_636 -> V_634 ;
V_634 -> V_640 = F_16 ( * V_363 ) ;
memcpy ( & V_634 -> V_641 [ 0 ] , & V_632 -> V_641 [ 0 ] , V_141 ) ;
memcpy ( & V_636 -> V_140 [ 0 ] , & V_632 -> V_140 [ 0 ] , V_141 ) ;
V_634 -> V_66 = F_17 ( V_66 - V_610 ) ;
if ( V_25 )
V_408 = V_25 -> V_26 ;
else
F_107 ( V_2 -> V_98 , V_642 ,
& V_408 ) ;
V_638 = F_7 ( V_408 ) ;
V_636 -> V_264 = F_16 ( V_638 ) ;
memcpy ( V_634 -> V_92 , & V_60 [ V_610 ] ,
F_111 ( V_634 -> V_66 ) ) ;
F_3 ( V_24 , L_281 ,
* V_363 , F_111 ( V_634 -> V_66 ) , V_408 ) ;
V_637 = F_170 ( V_131 , F_73 ( V_131 ) ,
V_636 ) ;
F_168 ( V_104 , * V_363 , V_60 , V_66 , V_637 ,
V_188 ) ;
F_60 ( V_636 ) ;
} else {
F_3 ( V_24 , L_282 , V_632 -> V_639 ) ;
F_171 ( true , V_60 , V_66 , L_283 , V_66 ) ;
}
exit:
return V_96 ;
}
static int
F_172 ( struct V_114 * V_114 ,
struct V_103 * V_104 ,
T_10 V_363 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_1 * V_2 ;
int V_96 = 0 ;
F_3 ( V_24 , L_284 ) ;
V_2 = V_131 -> V_217 . V_218 [ V_219 ] . V_2 ;
if ( V_2 == NULL ) {
F_22 ( L_285 ) ;
V_96 = - V_401 ;
goto exit;
}
F_173 ( V_2 -> V_98 ) ;
exit:
return V_96 ;
}
static int F_174 ( struct V_114 * V_114 ,
struct V_103 * V_104 ,
enum V_643 V_644 ,
T_1 V_645 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_1 * V_2 ;
V_2 = F_26 ( V_104 , struct V_1 , V_104 ) ;
if ( V_644 != V_646 )
return - V_127 ;
F_51 ( V_215 , & V_131 -> V_154 ) ;
F_120 ( V_131 ) ;
return F_77 ( V_2 , V_647 , V_645 ) ;
}
static void F_175 ( struct V_114 * V_114 ,
struct V_103 * V_104 )
{
struct V_130 * V_131 = F_63 ( V_114 ) ;
struct V_1 * V_2 ;
V_2 = F_26 ( V_104 , struct V_1 , V_104 ) ;
F_77 ( V_2 , V_245 , 0 ) ;
F_67 ( V_215 , & V_131 -> V_154 ) ;
}
static T_4
F_176 ( struct V_97 * V_98 ,
const struct V_449 * V_450 , void * V_92 )
{
switch ( V_450 -> V_648 ) {
case V_649 :
F_3 ( V_24 , L_286 ) ;
break;
case V_650 :
F_3 ( V_24 , L_287 ) ;
F_177 ( V_98 -> V_109 , V_98 -> V_110 , ( T_2 * ) V_450 -> V_651 ) ;
break;
case V_652 :
F_3 ( V_24 , L_288 ) ;
F_178 ( V_98 -> V_109 , V_98 -> V_110 , ( T_2 * ) V_450 -> V_651 ) ;
break;
}
return 0 ;
}
static int F_179 ( enum V_653 V_654 )
{
int V_508 ;
switch ( V_654 ) {
case V_655 :
V_508 = V_656 ;
break;
case V_657 :
V_508 = V_658 ;
break;
case V_659 :
V_508 = V_660 ;
break;
default:
F_22 ( L_289 , V_654 ) ;
V_508 = - V_123 ;
}
return V_508 ;
}
static int F_180 ( struct V_114 * V_114 ,
struct V_94 * V_95 , const T_2 * V_661 ,
enum V_653 V_654 )
{
struct V_97 * V_98 ;
struct V_662 V_621 ;
int V_508 = 0 ;
V_508 = F_179 ( V_654 ) ;
if ( V_508 < 0 )
return V_508 ;
V_98 = F_21 ( V_95 ) ;
memset ( & V_621 , 0 , sizeof( V_621 ) ) ;
V_621 . V_100 = ( T_2 ) V_508 ;
if ( V_661 )
memcpy ( V_621 . V_93 , V_661 , V_141 ) ;
V_508 = F_59 ( V_98 , L_290 ,
& V_621 , sizeof( V_621 ) ) ;
if ( V_508 < 0 )
F_22 ( L_291 , V_508 ) ;
return V_508 ;
}
struct V_1 * F_181 ( struct V_130 * V_131 ,
enum V_113 type ,
bool V_663 )
{
struct V_1 * V_2 ;
F_3 ( V_24 , L_292 ,
sizeof( * V_2 ) ) ;
V_2 = F_57 ( sizeof( * V_2 ) , V_188 ) ;
if ( ! V_2 )
return F_31 ( - V_189 ) ;
V_2 -> V_104 . V_114 = V_131 -> V_114 ;
V_2 -> V_104 . V_105 = type ;
V_2 -> V_663 = V_663 ;
V_2 -> V_664 = - 1 ;
F_74 ( & V_2 -> V_247 ) ;
F_182 ( & V_2 -> V_427 , & V_131 -> V_665 ) ;
return V_2 ;
}
void F_183 ( struct V_1 * V_2 )
{
F_184 ( & V_2 -> V_427 ) ;
F_60 ( V_2 ) ;
}
void F_185 ( struct V_94 * V_95 )
{
struct V_1 * V_2 ;
struct V_97 * V_98 ;
V_98 = F_21 ( V_95 ) ;
V_2 = V_98 -> V_2 ;
F_183 ( V_2 ) ;
F_186 ( V_95 ) ;
}
static bool F_187 ( const struct V_449 * V_450 )
{
T_5 V_666 = V_450 -> V_501 ;
T_5 V_452 = V_450 -> V_452 ;
if ( V_666 == V_667 && V_452 == V_462 ) {
F_3 ( V_253 , L_293 ) ;
return true ;
}
return false ;
}
static bool F_188 ( const struct V_449 * V_450 )
{
T_5 V_666 = V_450 -> V_501 ;
T_1 V_87 = V_450 -> V_87 ;
if ( ( V_666 == V_668 ) || ( V_666 == V_669 ) ||
( V_666 == V_670 ) ||
( ( V_666 == V_671 ) && ( ! ( V_87 & V_672 ) ) ) ) {
F_3 ( V_253 , L_294 ) ;
return true ;
}
return false ;
}
static bool F_189 ( struct V_130 * V_131 ,
const struct V_449 * V_450 )
{
T_5 V_666 = V_450 -> V_501 ;
T_5 V_452 = V_450 -> V_452 ;
if ( V_666 == V_671 && V_452 == V_673 ) {
F_3 ( V_253 , L_295 ,
V_450 -> V_87 & V_672 ? L_296 : L_297 ) ;
return true ;
}
if ( V_666 == V_667 && V_452 != V_462 ) {
F_3 ( V_253 , L_298 ) ;
return true ;
}
return false ;
}
static void F_190 ( struct V_130 * V_131 )
{
struct V_674 * V_675 = F_191 ( V_131 ) ;
F_60 ( V_675 -> V_676 ) ;
V_675 -> V_676 = NULL ;
V_675 -> V_677 = 0 ;
F_60 ( V_675 -> V_678 ) ;
V_675 -> V_678 = NULL ;
V_675 -> V_679 = 0 ;
}
static T_4 F_192 ( struct V_130 * V_131 ,
struct V_97 * V_98 )
{
struct V_680 * V_681 ;
struct V_674 * V_675 = F_191 ( V_131 ) ;
T_5 V_682 ;
T_5 V_683 ;
T_4 V_96 = 0 ;
F_190 ( V_131 ) ;
V_96 = F_105 ( V_98 , L_299 ,
V_131 -> V_435 , V_684 ) ;
if ( V_96 ) {
F_22 ( L_300 , V_96 ) ;
return V_96 ;
}
V_681 =
(struct V_680 * ) V_131 -> V_435 ;
V_682 = F_106 ( V_681 -> V_682 ) ;
V_683 = F_106 ( V_681 -> V_683 ) ;
if ( V_682 ) {
V_96 = F_105 ( V_98 , L_301 ,
V_131 -> V_435 ,
V_684 ) ;
if ( V_96 ) {
F_22 ( L_302 , V_96 ) ;
return V_96 ;
}
V_675 -> V_677 = V_682 ;
V_675 -> V_676 =
F_193 ( V_131 -> V_435 , V_675 -> V_677 ,
V_188 ) ;
} else {
V_675 -> V_677 = 0 ;
V_675 -> V_676 = NULL ;
}
if ( V_683 ) {
V_96 = F_105 ( V_98 , L_303 ,
V_131 -> V_435 ,
V_684 ) ;
if ( V_96 ) {
F_22 ( L_304 , V_96 ) ;
return V_96 ;
}
V_675 -> V_679 = V_683 ;
V_675 -> V_678 =
F_193 ( V_131 -> V_435 , V_675 -> V_679 ,
V_188 ) ;
} else {
V_675 -> V_679 = 0 ;
V_675 -> V_678 = NULL ;
}
F_3 ( V_253 , L_305 ,
V_675 -> V_677 , V_675 -> V_679 ) ;
return V_96 ;
}
static T_4
F_194 ( struct V_130 * V_131 ,
struct V_94 * V_95 ,
const struct V_449 * V_450 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_241 * V_247 = & V_98 -> V_2 -> V_247 ;
struct V_674 * V_675 = F_191 ( V_131 ) ;
struct V_114 * V_114 = F_42 ( V_131 ) ;
struct V_58 * V_404 = NULL ;
struct V_407 * V_50 ;
struct V_402 * V_403 ;
struct V_21 V_20 ;
T_5 V_408 ;
T_4 V_96 = 0 ;
T_2 * V_60 ;
F_3 ( V_24 , L_14 ) ;
F_192 ( V_131 , V_98 ) ;
memcpy ( V_247 -> V_140 , V_450 -> V_651 , V_141 ) ;
F_119 ( V_131 , V_98 ) ;
V_60 = F_57 ( V_415 , V_188 ) ;
if ( V_60 == NULL ) {
V_96 = - V_189 ;
goto V_160;
}
* ( V_432 * ) V_60 = F_16 ( V_415 ) ;
V_96 = F_108 ( V_98 , V_433 ,
V_60 , V_415 ) ;
if ( V_96 )
goto V_160;
V_403 = (struct V_402 * ) ( V_60 + 4 ) ;
V_20 . V_57 = F_111 ( V_403 -> V_170 ) ;
V_131 -> V_18 . V_417 ( & V_20 ) ;
if ( V_20 . V_50 == V_52 )
V_50 = V_114 -> V_419 [ V_51 ] ;
else
V_50 = V_114 -> V_419 [ V_53 ] ;
V_408 = F_112 ( V_20 . V_29 , V_50 -> V_50 ) ;
V_404 = F_113 ( V_114 , V_408 ) ;
V_160:
F_60 ( V_60 ) ;
F_195 ( V_95 , V_404 , ( T_2 * ) V_247 -> V_140 ,
V_675 -> V_676 , V_675 -> V_677 ,
V_675 -> V_678 , V_675 -> V_679 , V_188 ) ;
F_3 ( V_253 , L_306 ) ;
F_51 ( V_243 , & V_98 -> V_2 -> V_4 ) ;
F_3 ( V_24 , L_31 ) ;
return V_96 ;
}
static T_4
F_196 ( struct V_130 * V_131 ,
struct V_94 * V_95 , const struct V_449 * V_450 ,
bool V_685 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_241 * V_247 = & V_98 -> V_2 -> V_247 ;
struct V_674 * V_675 = F_191 ( V_131 ) ;
F_3 ( V_24 , L_14 ) ;
if ( F_44 ( V_216 ,
& V_98 -> V_2 -> V_4 ) ) {
if ( V_685 ) {
F_192 ( V_131 , V_98 ) ;
memcpy ( V_247 -> V_140 , V_450 -> V_651 , V_141 ) ;
F_119 ( V_131 , V_98 ) ;
F_51 ( V_243 ,
& V_98 -> V_2 -> V_4 ) ;
}
F_197 ( V_95 ,
( T_2 * ) V_247 -> V_140 ,
V_675 -> V_676 ,
V_675 -> V_677 ,
V_675 -> V_678 ,
V_675 -> V_679 ,
V_685 ? V_686 :
V_687 ,
V_188 ) ;
F_3 ( V_253 , L_307 ,
V_685 ? L_308 : L_217 ) ;
}
F_3 ( V_24 , L_31 ) ;
return 0 ;
}
static T_4
F_198 ( struct V_130 * V_131 ,
struct V_94 * V_95 ,
const struct V_449 * V_450 , void * V_92 )
{
static int V_688 ;
T_5 V_666 = V_450 -> V_501 ;
T_5 V_648 = V_450 -> V_648 ;
struct V_365 V_366 ;
F_3 ( V_253 , L_309 , V_666 , V_648 ) ;
if ( V_666 == V_671 && V_648 == V_689 &&
V_95 != F_73 ( V_131 ) ) {
F_3 ( V_253 , L_310 ) ;
F_199 ( & V_131 -> V_690 ) ;
return 0 ;
}
if ( ( ( V_666 == V_691 ) || ( V_666 == V_692 ) ) &&
( V_648 == V_462 ) ) {
memset ( & V_366 , 0 , sizeof( V_366 ) ) ;
V_366 . V_374 = V_693 ;
if ( ! V_92 ) {
F_22 ( L_311 ) ;
return - V_127 ;
}
V_366 . V_694 = V_92 ;
V_366 . V_695 = V_450 -> V_696 ;
V_688 ++ ;
V_366 . V_688 = V_688 ;
F_200 ( V_95 , V_450 -> V_651 , & V_366 , V_188 ) ;
} else if ( ( V_666 == V_670 ) ||
( V_666 == V_669 ) ||
( V_666 == V_668 ) ) {
F_201 ( V_95 , V_450 -> V_651 , V_188 ) ;
}
return 0 ;
}
static T_4
F_202 ( struct V_97 * V_98 ,
const struct V_449 * V_450 , void * V_92 )
{
struct V_130 * V_131 = V_98 -> V_109 -> V_451 ;
struct V_94 * V_95 = V_98 -> V_95 ;
struct V_241 * V_247 = & V_98 -> V_2 -> V_247 ;
struct V_58 * V_25 ;
T_4 V_96 = 0 ;
if ( ( V_450 -> V_501 == V_668 ) ||
( V_450 -> V_501 == V_669 ) ||
( V_450 -> V_501 == V_670 ) ||
( ( V_450 -> V_501 == V_671 ) && ( ! V_450 -> V_87 ) ) ) {
F_178 ( V_98 -> V_109 , V_98 -> V_110 , ( T_2 * ) V_450 -> V_651 ) ;
}
if ( F_28 ( V_98 -> V_2 ) ) {
V_96 = F_198 ( V_131 , V_95 , V_450 , V_92 ) ;
} else if ( F_187 ( V_450 ) ) {
F_3 ( V_253 , L_312 ) ;
if ( F_29 ( V_98 -> V_2 ) ) {
V_25 = F_113 ( V_131 -> V_114 , V_131 -> V_264 ) ;
memcpy ( V_247 -> V_140 , V_450 -> V_651 , V_141 ) ;
F_118 ( V_131 , V_95 , V_450 -> V_651 ) ;
F_203 ( V_95 , V_450 -> V_651 , V_25 , V_188 ) ;
F_67 ( V_216 ,
& V_98 -> V_2 -> V_4 ) ;
F_51 ( V_243 ,
& V_98 -> V_2 -> V_4 ) ;
} else
F_196 ( V_131 , V_95 , V_450 , true ) ;
} else if ( F_188 ( V_450 ) ) {
F_3 ( V_253 , L_313 ) ;
if ( ! F_29 ( V_98 -> V_2 ) ) {
F_196 ( V_131 , V_95 , V_450 , false ) ;
}
F_75 ( V_98 -> V_2 ) ;
F_74 ( F_81 ( V_95 ) ) ;
if ( V_95 != F_73 ( V_131 ) )
F_199 ( & V_131 -> V_690 ) ;
} else if ( F_189 ( V_131 , V_450 ) ) {
if ( F_29 ( V_98 -> V_2 ) )
F_67 ( V_216 ,
& V_98 -> V_2 -> V_4 ) ;
else
F_196 ( V_131 , V_95 , V_450 , false ) ;
}
return V_96 ;
}
static T_4
F_204 ( struct V_97 * V_98 ,
const struct V_449 * V_450 , void * V_92 )
{
struct V_130 * V_131 = V_98 -> V_109 -> V_451 ;
T_5 V_666 = V_450 -> V_501 ;
T_5 V_452 = V_450 -> V_452 ;
if ( V_666 == V_697 && V_452 == V_462 ) {
if ( F_2 ( V_243 , & V_98 -> V_2 -> V_4 ) )
F_194 ( V_131 , V_98 -> V_95 , V_450 ) ;
else
F_196 ( V_131 , V_98 -> V_95 , V_450 , true ) ;
}
return 0 ;
}
static T_4
F_205 ( struct V_97 * V_98 ,
const struct V_449 * V_450 , void * V_92 )
{
T_1 V_87 = V_450 -> V_87 ;
enum V_698 V_699 ;
if ( V_87 & V_700 )
V_699 = V_701 ;
else
V_699 = V_702 ;
F_206 ( V_98 -> V_95 , ( T_2 * ) & V_450 -> V_651 , V_699 , - 1 ,
NULL , V_188 ) ;
return 0 ;
}
static T_4 F_207 ( struct V_97 * V_98 ,
const struct V_449 * V_450 , void * V_92 )
{
struct V_130 * V_131 = V_98 -> V_109 -> V_451 ;
struct V_703 * V_704 = (struct V_703 * ) V_92 ;
struct V_705 * V_666 = & V_131 -> V_706 ;
struct V_1 * V_2 ;
F_3 ( V_24 , L_314 ,
V_704 -> V_183 , V_704 -> V_87 , V_704 -> V_110 ,
V_704 -> V_456 ) ;
F_208 ( & V_666 -> V_707 ) ;
V_666 -> V_183 = V_704 -> V_183 ;
V_2 = V_666 -> V_2 ;
switch ( V_704 -> V_183 ) {
case V_708 :
if ( ! V_131 -> V_706 . V_2 ) {
F_209 ( & V_666 -> V_707 ) ;
return - V_709 ;
}
V_98 -> V_2 = V_2 ;
V_2 -> V_98 = V_98 ;
if ( V_98 -> V_95 ) {
V_2 -> V_104 . V_155 = V_98 -> V_95 ;
V_98 -> V_95 -> V_165 = & V_2 -> V_104 ;
F_210 ( V_98 -> V_95 , F_211 ( V_131 -> V_114 ) ) ;
}
F_209 ( & V_666 -> V_707 ) ;
F_212 ( & V_666 -> V_710 ) ;
return 0 ;
case V_711 :
F_209 ( & V_666 -> V_707 ) ;
if ( F_47 ( V_131 ) )
F_212 ( & V_666 -> V_710 ) ;
return 0 ;
case V_712 :
F_209 ( & V_666 -> V_707 ) ;
F_212 ( & V_666 -> V_710 ) ;
return 0 ;
default:
F_209 ( & V_666 -> V_707 ) ;
break;
}
return - V_127 ;
}
static void F_213 ( struct V_713 * V_235 )
{
V_235 -> V_227 = ( T_5 ) - 1 ;
V_235 -> V_226 = ( T_5 ) - 1 ;
V_235 -> V_240 = ( T_5 ) - 1 ;
V_235 -> V_238 = ( T_5 ) - 1 ;
V_235 -> V_344 = - 1 ;
}
static void F_214 ( struct V_130 * V_131 )
{
F_129 ( V_131 -> V_463 , V_671 ,
F_202 ) ;
F_129 ( V_131 -> V_463 , V_669 ,
F_202 ) ;
F_129 ( V_131 -> V_463 , V_668 ,
F_202 ) ;
F_129 ( V_131 -> V_463 , V_670 ,
F_202 ) ;
F_129 ( V_131 -> V_463 , V_691 ,
F_202 ) ;
F_129 ( V_131 -> V_463 , V_692 ,
F_202 ) ;
F_129 ( V_131 -> V_463 , V_697 ,
F_204 ) ;
F_129 ( V_131 -> V_463 , V_714 ,
F_205 ) ;
F_129 ( V_131 -> V_463 , V_667 ,
F_202 ) ;
F_129 ( V_131 -> V_463 , V_715 ,
F_145 ) ;
F_129 ( V_131 -> V_463 , V_716 ,
F_207 ) ;
F_129 ( V_131 -> V_463 , V_717 ,
V_718 ) ;
F_129 ( V_131 -> V_463 , V_719 ,
V_720 ) ;
F_129 ( V_131 -> V_463 , V_721 ,
V_722 ) ;
F_129 ( V_131 -> V_463 , V_723 ,
V_724 ) ;
F_129 ( V_131 -> V_463 , V_725 ,
V_724 ) ;
}
static void F_215 ( struct V_130 * V_131 )
{
F_60 ( V_131 -> V_235 ) ;
V_131 -> V_235 = NULL ;
F_60 ( V_131 -> V_726 ) ;
V_131 -> V_726 = NULL ;
F_60 ( V_131 -> V_435 ) ;
V_131 -> V_435 = NULL ;
F_60 ( V_131 -> V_482 ) ;
V_131 -> V_482 = NULL ;
}
static T_4 F_216 ( struct V_130 * V_131 )
{
V_131 -> V_235 = F_57 ( sizeof( * V_131 -> V_235 ) , V_188 ) ;
if ( ! V_131 -> V_235 )
goto V_727;
V_131 -> V_726 = F_57 ( V_190 , V_188 ) ;
if ( ! V_131 -> V_726 )
goto V_727;
V_131 -> V_435 = F_57 ( V_436 , V_188 ) ;
if ( ! V_131 -> V_435 )
goto V_727;
V_131 -> V_482 = F_57 ( sizeof( * V_131 -> V_482 ) , V_188 ) ;
if ( ! V_131 -> V_482 )
goto V_727;
return 0 ;
V_727:
F_215 ( V_131 ) ;
return - V_189 ;
}
static T_4 F_217 ( struct V_130 * V_131 )
{
T_4 V_96 = 0 ;
V_131 -> V_137 = NULL ;
V_131 -> V_397 = true ;
V_131 -> V_200 = true ;
V_131 -> V_728 = false ;
V_96 = F_216 ( V_131 ) ;
if ( V_96 )
return V_96 ;
F_214 ( V_131 ) ;
F_218 ( & V_131 -> V_729 ) ;
F_128 ( V_131 ) ;
F_213 ( V_131 -> V_235 ) ;
F_219 ( & V_131 -> V_690 ) ;
return V_96 ;
}
static void F_220 ( struct V_130 * V_131 )
{
V_131 -> V_728 = false ;
F_120 ( V_131 ) ;
F_215 ( V_131 ) ;
}
static void F_221 ( struct V_705 * V_666 )
{
F_222 ( & V_666 -> V_710 ) ;
F_218 ( & V_666 -> V_707 ) ;
}
static T_4
F_223 ( struct V_97 * V_98 , T_5 V_730 )
{
T_4 V_96 = 0 ;
V_432 V_731 [ 2 ] ;
V_432 V_732 [ 2 ] ;
if ( V_733 ) {
V_96 = F_24 ( V_98 , L_315 , V_730 ) ;
if ( V_96 ) {
F_22 ( L_316 , V_96 ) ;
goto V_734;
}
}
F_3 ( V_5 , L_317 ,
V_733 ? L_318 : L_319 ) ;
V_96 = F_24 ( V_98 , L_320 , ! ! ( V_733 ) ) ;
if ( V_96 ) {
F_22 ( L_321 , V_96 ) ;
goto V_734;
}
V_731 [ 0 ] = F_16 ( V_735 ) ;
V_731 [ 1 ] = F_16 ( V_736 ) ;
V_96 = F_40 ( V_98 , V_737 ,
( void * ) V_731 , sizeof( V_731 ) ) ;
if ( V_96 ) {
F_22 ( L_322 , V_96 ) ;
goto V_734;
}
V_732 [ 0 ] = F_16 ( V_738 ) ;
V_732 [ 1 ] = F_16 ( V_736 ) ;
V_96 = F_40 ( V_98 , V_739 ,
( void * ) V_732 , sizeof( V_732 ) ) ;
if ( V_96 ) {
F_22 ( L_323 , V_96 ) ;
goto V_734;
}
V_734:
return V_96 ;
}
static T_4
F_224 ( struct V_97 * V_98 , T_4 V_740 ,
T_4 V_741 , T_4 V_742 )
{
T_4 V_96 = 0 ;
V_96 = F_52 ( V_98 , V_743 ,
V_740 ) ;
if ( V_96 ) {
if ( V_96 == - V_123 )
F_3 ( V_5 , L_324 ) ;
else
F_22 ( L_325 , V_96 ) ;
goto V_744;
}
V_96 = F_52 ( V_98 , V_745 ,
V_741 ) ;
if ( V_96 ) {
if ( V_96 == - V_123 )
F_3 ( V_5 , L_326 ) ;
else
F_22 ( L_327 , V_96 ) ;
goto V_744;
}
V_96 = F_52 ( V_98 , V_746 ,
V_742 ) ;
if ( V_96 ) {
if ( V_96 == - V_123 )
F_3 ( V_5 , L_328 ) ;
else
F_22 ( L_329 , V_96 ) ;
goto V_744;
}
V_744:
return V_96 ;
}
static void F_225 ( struct V_130 * V_131 ,
struct V_747 * V_748 ,
T_5 V_749 [] )
{
T_5 V_750 = F_106 ( V_748 -> V_203 ) ;
struct V_21 V_20 ;
int V_169 ;
for ( V_169 = 0 ; V_169 < V_750 ; V_169 ++ ) {
V_20 . V_57 = ( T_1 ) F_106 ( V_748 -> V_751 [ V_169 ] ) ;
V_131 -> V_18 . V_417 ( & V_20 ) ;
if ( V_20 . V_32 != V_33 ) {
if ( V_20 . V_50 == V_54 )
break;
else
continue;
}
if ( V_20 . V_50 == V_52 )
V_749 [ 0 ] += 1 ;
else if ( V_20 . V_50 == V_54 )
V_749 [ 1 ] += 1 ;
}
}
static void F_226 ( struct V_58 * V_264 ,
struct V_21 * V_20 )
{
T_5 V_752 ;
V_752 = V_264 -> V_87 & V_507 ;
if ( V_20 -> V_36 == V_37 ) {
if ( V_752 == V_507 )
V_264 -> V_87 &= ~ V_507 ;
V_264 -> V_87 |= V_753 ;
} else {
V_264 -> V_87 &= ~ V_507 ;
if ( V_752 == V_507 )
V_264 -> V_87 |= V_754 ;
}
}
static int F_227 ( struct V_130 * V_131 ,
T_5 V_755 [] )
{
struct V_97 * V_98 = F_21 ( F_73 ( V_131 ) ) ;
struct V_407 * V_50 ;
struct V_58 * V_264 ;
struct V_114 * V_114 ;
struct V_747 * V_427 ;
struct V_21 V_20 ;
int V_96 ;
T_2 * V_756 ;
T_5 V_169 , V_483 ;
T_5 V_750 ;
T_5 V_757 ;
T_5 V_749 [ 2 ] = { 0 , 0 } ;
T_5 V_85 ;
V_756 = F_57 ( V_190 , V_188 ) ;
if ( V_756 == NULL )
return - V_189 ;
V_427 = (struct V_747 * ) V_756 ;
V_96 = F_105 ( V_98 , L_330 , V_756 ,
V_190 ) ;
if ( V_96 ) {
F_22 ( L_331 , V_96 ) ;
goto V_758;
}
F_225 ( V_131 , V_427 , V_749 ) ;
V_114 = F_42 ( V_131 ) ;
if ( V_749 [ 0 ] ) {
V_50 = F_193 ( & V_759 , sizeof( V_759 ) ,
V_188 ) ;
if ( V_50 == NULL ) {
V_96 = - V_189 ;
goto V_758;
}
V_50 -> V_174 = F_146 ( V_749 [ 0 ] , sizeof( * V_264 ) ,
V_188 ) ;
if ( V_50 -> V_174 == NULL ) {
F_60 ( V_50 ) ;
V_96 = - V_189 ;
goto V_758;
}
V_50 -> V_168 = 0 ;
V_114 -> V_419 [ V_51 ] = V_50 ;
}
if ( V_749 [ 1 ] ) {
V_50 = F_193 ( & V_760 , sizeof( V_760 ) ,
V_188 ) ;
if ( V_50 == NULL ) {
V_96 = - V_189 ;
goto V_761;
}
V_50 -> V_174 = F_146 ( V_749 [ 1 ] , sizeof( * V_264 ) ,
V_188 ) ;
if ( V_50 -> V_174 == NULL ) {
F_60 ( V_50 ) ;
V_96 = - V_189 ;
goto V_761;
}
V_50 -> V_168 = 0 ;
V_114 -> V_419 [ V_53 ] = V_50 ;
}
V_750 = F_106 ( V_427 -> V_203 ) ;
for ( V_169 = 0 ; V_169 < V_750 ; V_169 ++ ) {
V_20 . V_57 = ( T_1 ) F_106 ( V_427 -> V_751 [ V_169 ] ) ;
V_131 -> V_18 . V_417 ( & V_20 ) ;
if ( V_20 . V_50 == V_52 ) {
V_50 = V_114 -> V_419 [ V_51 ] ;
} else if ( V_20 . V_50 == V_54 ) {
V_50 = V_114 -> V_419 [ V_53 ] ;
} else {
F_22 ( L_332 , V_20 . V_57 ) ;
continue;
}
if ( ! ( V_755 [ V_50 -> V_50 ] & V_762 ) &&
V_20 . V_32 == V_35 )
continue;
if ( ! ( V_755 [ V_50 -> V_50 ] & V_763 ) &&
V_20 . V_32 == V_40 )
continue;
V_264 = V_50 -> V_174 ;
V_85 = V_50 -> V_168 ;
for ( V_483 = 0 ; V_483 < V_50 -> V_168 ; V_483 ++ ) {
if ( V_264 [ V_483 ] . V_175 == V_20 . V_29 ) {
V_85 = V_483 ;
break;
}
}
V_264 [ V_85 ] . V_26 =
F_112 ( V_20 . V_29 , V_50 -> V_50 ) ;
V_264 [ V_85 ] . V_175 = V_20 . V_29 ;
if ( V_20 . V_32 == V_40 ) {
V_264 [ V_85 ] . V_87 &= ~ V_764 ;
} else if ( V_20 . V_32 == V_35 ) {
F_226 ( & V_264 [ V_85 ] , & V_20 ) ;
} else {
V_264 [ V_85 ] . V_87 = V_507 |
V_764 ;
V_20 . V_32 = V_33 ;
V_131 -> V_18 . V_56 ( & V_20 ) ;
V_757 = V_20 . V_57 ;
V_96 = F_86 ( V_98 , L_333 ,
& V_757 ) ;
if ( ! V_96 ) {
if ( V_757 & V_765 )
V_264 [ V_85 ] . V_87 |=
( V_766 |
V_767 ) ;
if ( V_757 & V_768 )
V_264 [ V_85 ] . V_87 |=
V_767 ;
}
}
if ( V_85 == V_50 -> V_168 )
V_50 -> V_168 ++ ;
}
F_60 ( V_756 ) ;
return 0 ;
V_761:
F_60 ( V_114 -> V_419 [ V_51 ] -> V_174 ) ;
F_60 ( V_114 -> V_419 [ V_51 ] ) ;
V_114 -> V_419 [ V_51 ] = NULL ;
V_758:
F_60 ( V_756 ) ;
return V_96 ;
}
static int F_228 ( struct V_130 * V_131 )
{
struct V_97 * V_98 = F_21 ( F_73 ( V_131 ) ) ;
struct V_407 * V_50 ;
struct V_769 V_770 ;
struct V_747 * V_427 ;
T_2 * V_756 ;
T_5 V_274 ;
int V_96 ;
struct V_21 V_20 ;
T_5 V_771 ;
int V_169 , V_483 ;
V_274 = V_772 ;
V_96 = F_95 ( V_98 , L_334 , & V_274 ) ;
if ( ! V_96 ) {
V_770 . V_50 = F_16 ( V_773 ) ;
V_770 . V_755 = F_16 ( V_774 ) ;
V_96 = F_59 ( V_98 , L_334 , & V_770 ,
sizeof( V_770 ) ) ;
} else {
F_3 ( V_5 , L_335 ) ;
V_274 = V_775 ;
V_96 = F_24 ( V_98 , L_336 , V_274 ) ;
}
if ( ! V_96 ) {
V_756 = F_57 ( V_190 , V_188 ) ;
if ( V_756 == NULL )
return - V_189 ;
V_20 . V_50 = V_52 ;
V_20 . V_32 = V_35 ;
V_20 . V_36 = V_776 ;
V_20 . V_29 = 0 ;
V_131 -> V_18 . V_56 ( & V_20 ) ;
* ( V_777 * ) V_756 = F_17 ( V_20 . V_57 ) ;
V_96 = F_105 ( V_98 , L_330 , V_756 ,
V_190 ) ;
if ( V_96 ) {
F_22 ( L_331 , V_96 ) ;
F_60 ( V_756 ) ;
return V_96 ;
}
V_50 = F_42 ( V_131 ) -> V_419 [ V_51 ] ;
V_427 = (struct V_747 * ) V_756 ;
V_771 = F_106 ( V_427 -> V_203 ) ;
for ( V_169 = 0 ; V_169 < V_771 ; V_169 ++ ) {
V_20 . V_57 = ( T_1 ) F_106 ( V_427 -> V_751 [ V_169 ] ) ;
V_131 -> V_18 . V_417 ( & V_20 ) ;
if ( F_8 ( V_20 . V_50 != V_52 ) )
continue;
if ( F_8 ( V_20 . V_32 != V_35 ) )
continue;
for ( V_483 = 0 ; V_483 < V_50 -> V_168 ; V_483 ++ ) {
if ( V_50 -> V_174 [ V_483 ] . V_175 == V_20 . V_29 )
break;
}
if ( F_8 ( V_483 == V_50 -> V_168 ) )
continue;
F_226 ( & V_50 -> V_174 [ V_483 ] , & V_20 ) ;
}
F_60 ( V_756 ) ;
}
return V_96 ;
}
static void F_229 ( struct V_97 * V_98 , T_5 V_755 [] )
{
T_5 V_50 , V_778 ;
int V_96 ;
V_50 = V_773 ;
V_96 = F_95 ( V_98 , L_334 , & V_50 ) ;
if ( ! V_96 ) {
V_755 [ V_51 ] = V_50 ;
V_50 = V_772 ;
V_96 = F_95 ( V_98 , L_334 , & V_50 ) ;
if ( ! V_96 ) {
V_755 [ V_53 ] = V_50 ;
return;
}
F_8 ( 1 ) ;
return;
}
F_3 ( V_5 , L_337 ) ;
V_778 = 0 ;
V_96 = F_95 ( V_98 , L_336 , & V_778 ) ;
if ( V_96 )
V_778 = V_779 ;
switch ( V_778 ) {
case V_775 :
V_755 [ V_51 ] |= V_762 ;
case V_780 :
V_755 [ V_53 ] |= V_762 ;
case V_779 :
V_755 [ V_51 ] |= V_781 ;
V_755 [ V_53 ] |= V_781 ;
break;
default:
F_22 ( L_338 ) ;
}
}
static void F_230 ( struct V_407 * V_50 ,
T_5 V_755 [ 2 ] , T_5 V_782 )
{
V_50 -> V_783 . V_784 = true ;
if ( V_755 [ V_50 -> V_50 ] & V_762 ) {
V_50 -> V_783 . V_785 |= V_786 ;
V_50 -> V_783 . V_785 |= V_787 ;
}
V_50 -> V_783 . V_785 |= V_788 ;
V_50 -> V_783 . V_785 |= V_789 ;
V_50 -> V_783 . V_790 = V_791 ;
V_50 -> V_783 . V_792 = V_793 ;
memset ( V_50 -> V_783 . V_794 . V_795 , 0xff , V_782 ) ;
V_50 -> V_783 . V_794 . V_796 = V_797 ;
}
static V_777 F_231 ( T_5 V_782 , enum V_798 V_799 )
{
T_1 V_800 ;
int V_169 ;
for ( V_169 = 0 , V_800 = 0xFFFF ; V_169 < V_782 ; V_169 ++ )
V_800 = ( V_800 << 2 ) | V_799 ;
return F_17 ( V_800 ) ;
}
static void F_232 ( struct V_407 * V_50 ,
T_5 V_755 [ 2 ] , T_5 V_782 )
{
V_777 V_800 ;
if ( V_50 -> V_50 == V_51 )
return;
V_50 -> V_801 . V_802 = true ;
V_50 -> V_801 . V_785 |= V_803 ;
if ( V_755 [ V_50 -> V_50 ] & V_804 ) {
V_50 -> V_801 . V_785 |= V_805 ;
V_50 -> V_801 . V_785 |= V_806 ;
}
V_800 = F_231 ( V_782 , V_807 ) ;
V_50 -> V_801 . V_808 . V_809 = V_800 ;
V_50 -> V_801 . V_808 . V_810 = V_800 ;
}
static int F_233 ( struct V_114 * V_114 )
{
struct V_130 * V_131 = F_46 ( V_114 ) ;
struct V_97 * V_98 = F_21 ( F_73 ( V_131 ) ) ;
T_5 V_811 = 0 ;
T_5 V_812 = 0 ;
T_5 V_755 [ 2 ] = { V_781 , V_781 } ;
T_5 V_813 ;
T_5 V_782 ;
int V_96 ;
T_4 V_169 ;
struct V_407 * V_50 ;
( void ) F_95 ( V_98 , L_339 , & V_812 ) ;
V_96 = F_95 ( V_98 , L_340 , & V_811 ) ;
if ( V_96 ) {
F_22 ( L_341 , V_96 ) ;
} else {
F_229 ( V_98 , V_755 ) ;
}
F_3 ( V_5 , L_342 ,
V_811 , V_812 , V_755 [ V_51 ] ,
V_755 [ V_53 ] ) ;
V_96 = F_95 ( V_98 , L_343 , & V_813 ) ;
if ( V_96 ) {
F_22 ( L_344 , V_96 ) ;
V_782 = 1 ;
} else {
for ( V_782 = 0 ; V_813 ; V_782 ++ )
V_813 = V_813 & ( V_813 - 1 ) ;
}
F_3 ( V_5 , L_345 , V_782 ) ;
V_96 = F_227 ( V_131 , V_755 ) ;
if ( V_96 ) {
F_22 ( L_346 , V_96 ) ;
return V_96 ;
}
V_114 = F_42 ( V_131 ) ;
for ( V_169 = 0 ; V_169 < F_158 ( V_114 -> V_419 ) ; V_169 ++ ) {
V_50 = V_114 -> V_419 [ V_169 ] ;
if ( V_50 == NULL )
continue;
if ( V_811 )
F_230 ( V_50 , V_755 , V_782 ) ;
if ( V_812 )
F_232 ( V_50 , V_755 , V_782 ) ;
}
return 0 ;
}
static void F_234 ( struct V_114 * V_114 )
{
V_114 -> V_814 = V_815 ;
V_114 -> V_816 = V_815 ;
V_114 -> V_817 = V_818 ;
V_114 -> V_87 |= V_819 ;
}
static void F_235 ( struct V_114 * V_114 )
{
#ifdef F_236
V_114 -> V_820 = & V_821 ;
#endif
}
static int F_237 ( struct V_114 * V_114 , struct V_97 * V_98 )
{
struct V_822 V_823 ;
V_114 -> V_824 = V_825 ;
V_114 -> V_826 = V_818 ;
V_114 -> V_827 = V_493 ;
V_114 -> V_459 = F_127 ( V_118 ) |
F_127 ( V_106 ) |
F_127 ( V_107 ) |
F_127 ( V_124 ) |
F_127 ( V_108 ) |
F_127 ( V_125 ) ;
V_823 = V_828 [ 0 ] ;
if ( F_238 ( V_98 , V_829 ) )
V_823 . V_830 = 2 ;
V_114 -> V_831 = F_193 ( & V_823 ,
sizeof( V_823 ) ,
V_188 ) ;
V_114 -> V_832 = F_158 ( V_828 ) ;
V_114 -> V_833 = V_834 ;
V_114 -> V_835 = V_836 ;
V_114 -> V_837 = F_158 ( V_836 ) ;
V_114 -> V_87 |= V_838 |
V_839 |
V_840 |
V_841 ;
if ( ! V_733 )
V_114 -> V_87 |= V_842 ;
V_114 -> V_843 = V_844 ;
V_114 -> V_845 = 5000 ;
F_234 ( V_114 ) ;
V_114 -> V_846 = V_847 ;
V_114 -> V_848 = V_849 - 1 ;
if ( F_238 ( V_98 , V_850 ) )
F_235 ( V_114 ) ;
return F_233 ( V_114 ) ;
}
static T_4 F_239 ( struct V_130 * V_131 )
{
struct V_94 * V_95 ;
struct V_103 * V_104 ;
struct V_97 * V_98 ;
T_4 V_851 ;
T_4 V_96 = 0 ;
if ( V_131 -> V_728 )
return V_96 ;
V_95 = F_73 ( V_131 ) ;
V_104 = V_95 -> V_165 ;
V_98 = F_21 ( V_95 ) ;
F_52 ( V_98 , V_618 , 0 ) ;
F_224 ( V_98 , V_852 ,
V_853 , V_854 ) ;
V_851 = V_131 -> V_397 ? V_398 : V_399 ;
V_96 = F_52 ( V_98 , V_400 , V_851 ) ;
if ( V_96 )
goto V_855;
F_3 ( V_5 , L_347 ,
( V_851 ? L_159 : L_160 ) ) ;
V_96 = F_223 ( V_98 , V_856 ) ;
if ( V_96 )
goto V_855;
V_96 = F_49 ( V_104 -> V_114 , V_95 , V_104 -> V_105 ,
NULL , NULL ) ;
if ( V_96 )
goto V_855;
F_23 ( V_98 , true ) ;
V_131 -> V_728 = true ;
V_855:
return V_96 ;
}
static T_4 F_240 ( struct V_97 * V_98 )
{
F_51 ( V_3 , & V_98 -> V_2 -> V_4 ) ;
return F_239 ( V_98 -> V_109 -> V_451 ) ;
}
static T_4 F_241 ( struct V_97 * V_98 )
{
struct V_130 * V_131 = V_98 -> V_109 -> V_451 ;
if ( F_1 ( V_98 -> V_2 ) ) {
F_75 ( V_98 -> V_2 ) ;
F_132 ( 500 ) ;
}
F_120 ( V_131 ) ;
F_67 ( V_3 , & V_98 -> V_2 -> V_4 ) ;
return 0 ;
}
T_4 F_242 ( struct V_94 * V_95 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_130 * V_131 = V_98 -> V_109 -> V_451 ;
T_4 V_96 = 0 ;
F_208 ( & V_131 -> V_729 ) ;
V_96 = F_240 ( V_98 ) ;
F_209 ( & V_131 -> V_729 ) ;
return V_96 ;
}
T_4 F_243 ( struct V_94 * V_95 )
{
struct V_97 * V_98 = F_21 ( V_95 ) ;
struct V_130 * V_131 = V_98 -> V_109 -> V_451 ;
T_4 V_96 = 0 ;
F_208 ( & V_131 -> V_729 ) ;
V_96 = F_241 ( V_98 ) ;
F_209 ( & V_131 -> V_729 ) ;
return V_96 ;
}
enum V_113 F_244 ( struct V_97 * V_98 )
{
struct V_103 * V_104 = & V_98 -> V_2 -> V_104 ;
return V_104 -> V_105 ;
}
bool F_245 ( struct V_130 * V_131 , unsigned long V_857 )
{
struct V_1 * V_2 ;
F_140 (vif, &cfg->vif_list, list) {
if ( F_2 ( V_857 , & V_2 -> V_4 ) )
return true ;
}
return false ;
}
static inline bool F_246 ( struct V_705 * V_666 ,
T_2 V_183 )
{
T_2 V_858 ;
F_208 ( & V_666 -> V_707 ) ;
V_858 = V_666 -> V_183 ;
F_209 ( & V_666 -> V_707 ) ;
return V_858 == V_183 ;
}
void F_247 ( struct V_130 * V_131 ,
struct V_1 * V_2 )
{
struct V_705 * V_666 = & V_131 -> V_706 ;
F_208 ( & V_666 -> V_707 ) ;
V_666 -> V_2 = V_2 ;
V_666 -> V_183 = 0 ;
F_209 ( & V_666 -> V_707 ) ;
}
bool F_47 ( struct V_130 * V_131 )
{
struct V_705 * V_666 = & V_131 -> V_706 ;
bool V_859 ;
F_208 ( & V_666 -> V_707 ) ;
V_859 = V_666 -> V_2 != NULL ;
F_209 ( & V_666 -> V_707 ) ;
return V_859 ;
}
int F_248 ( struct V_130 * V_131 ,
T_2 V_183 , T_11 V_395 )
{
struct V_705 * V_666 = & V_131 -> V_706 ;
return F_249 ( V_666 -> V_710 ,
F_246 ( V_666 , V_183 ) , V_395 ) ;
}
static void F_250 ( struct V_114 * V_114 )
{
F_60 ( V_114 -> V_831 ) ;
if ( V_114 -> V_419 [ V_51 ] ) {
F_60 ( V_114 -> V_419 [ V_51 ] -> V_174 ) ;
F_60 ( V_114 -> V_419 [ V_51 ] ) ;
}
if ( V_114 -> V_419 [ V_53 ] ) {
F_60 ( V_114 -> V_419 [ V_53 ] -> V_174 ) ;
F_60 ( V_114 -> V_419 [ V_53 ] ) ;
}
F_251 ( V_114 ) ;
}
struct V_130 * F_252 ( struct V_860 * V_109 ,
struct V_861 * V_862 )
{
struct V_94 * V_95 = V_109 -> V_863 [ 0 ] -> V_95 ;
struct V_130 * V_131 ;
struct V_114 * V_114 ;
struct V_1 * V_2 ;
struct V_97 * V_98 ;
T_4 V_96 = 0 ;
T_4 V_864 ;
T_1 * V_785 = NULL ;
if ( ! V_95 ) {
F_22 ( L_348 ) ;
return NULL ;
}
V_98 = F_21 ( V_95 ) ;
V_114 = F_253 ( & V_865 , sizeof( struct V_130 ) ) ;
if ( ! V_114 ) {
F_22 ( L_349 ) ;
return NULL ;
}
F_254 ( V_114 , V_862 ) ;
V_131 = F_46 ( V_114 ) ;
V_131 -> V_114 = V_114 ;
V_131 -> V_463 = V_109 ;
F_221 ( & V_131 -> V_706 ) ;
F_255 ( & V_131 -> V_665 ) ;
V_2 = F_181 ( V_131 , V_118 , false ) ;
if ( F_33 ( V_2 ) )
goto V_866;
V_2 -> V_98 = V_98 ;
V_2 -> V_104 . V_155 = V_95 ;
V_95 -> V_165 = & V_2 -> V_104 ;
F_210 ( V_95 , F_211 ( V_131 -> V_114 ) ) ;
V_96 = F_217 ( V_131 ) ;
if ( V_96 ) {
F_22 ( L_350 , V_96 ) ;
F_183 ( V_2 ) ;
goto V_866;
}
V_98 -> V_2 = V_2 ;
V_96 = F_107 ( V_98 , V_867 , & V_864 ) ;
if ( V_96 ) {
F_22 ( L_351 , V_96 ) ;
goto V_868;
}
V_131 -> V_18 . V_864 = ( T_2 ) V_864 ;
F_256 ( & V_131 -> V_18 ) ;
V_96 = F_237 ( V_114 , V_98 ) ;
if ( V_96 < 0 )
goto V_868;
F_3 ( V_5 , L_352 ) ;
V_114 -> V_869 |= V_870 ;
F_257 ( V_114 , & V_871 ) ;
if ( V_114 -> V_419 [ V_51 ] ) {
V_785 = & V_114 -> V_419 [ V_51 ] -> V_783 . V_785 ;
* V_785 |= V_787 ;
}
V_96 = F_258 ( V_114 ) ;
if ( V_96 < 0 ) {
F_22 ( L_353 , V_96 ) ;
goto V_868;
}
if ( V_785 && ( * V_785 & V_787 ) ) {
V_96 = F_228 ( V_131 ) ;
if ( ! V_96 )
V_96 = F_24 ( V_98 , L_354 ,
V_872 ) ;
else
* V_785 &= ~ V_787 ;
}
V_96 = F_259 ( V_131 ) ;
if ( V_96 ) {
F_22 ( L_355 , V_96 ) ;
goto V_873;
}
V_96 = F_260 ( V_131 ) ;
if ( V_96 ) {
F_22 ( L_356 , V_96 ) ;
F_261 ( & V_131 -> V_217 ) ;
goto V_873;
}
V_96 = F_24 ( V_98 , L_357 , 1 ) ;
if ( V_96 ) {
F_3 ( V_5 , L_358 , V_96 ) ;
V_114 -> V_87 &= ~ V_841 ;
} else {
F_129 ( V_131 -> V_463 , V_874 ,
F_176 ) ;
}
return V_131 ;
V_873:
F_262 ( V_131 -> V_114 ) ;
V_868:
F_220 ( V_131 ) ;
F_183 ( V_2 ) ;
V_866:
F_250 ( V_114 ) ;
return NULL ;
}
void F_263 ( struct V_130 * V_131 )
{
if ( ! V_131 )
return;
F_8 ( ! F_264 ( & V_131 -> V_665 ) ) ;
F_262 ( V_131 -> V_114 ) ;
F_265 ( V_131 ) ;
F_261 ( & V_131 -> V_217 ) ;
F_220 ( V_131 ) ;
F_250 ( V_131 -> V_114 ) ;
}
