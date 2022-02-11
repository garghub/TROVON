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
V_22 . V_31 = V_32 ;
F_8 ( V_23 != 0 ) ;
break;
case V_33 :
V_22 . V_31 = V_34 ;
if ( V_23 < 0 )
V_22 . V_35 = V_36 ;
else
V_22 . V_35 = V_37 ;
break;
case V_38 :
V_22 . V_31 = V_39 ;
if ( V_23 < 0 ) {
if ( V_23 < - V_40 )
V_22 . V_35 = V_41 ;
else
V_22 . V_35 = V_42 ;
} else {
if ( V_23 > V_40 )
V_22 . V_35 = V_43 ;
else
V_22 . V_35 = V_44 ;
}
break;
default:
F_9 ( 1 ) ;
}
switch ( V_20 -> V_25 -> V_45 ) {
case V_46 :
V_22 . V_45 = V_47 ;
break;
case V_48 :
V_22 . V_45 = V_49 ;
break;
default:
F_9 ( 1 ) ;
}
V_18 -> V_50 ( & V_22 ) ;
return V_22 . V_51 ;
}
T_1 F_10 ( struct V_17 * V_18 ,
struct V_52 * V_20 )
{
struct V_21 V_22 ;
V_22 . V_29 = F_7 ( V_20 -> V_26 ) ;
V_22 . V_31 = V_32 ;
V_18 -> V_50 ( & V_22 ) ;
return V_22 . V_51 ;
}
const struct V_53 *
F_11 ( const void * V_54 , int V_55 , T_3 V_56 )
{
const struct V_53 * V_57 = V_54 ;
int V_58 = V_55 ;
while ( V_58 >= V_59 ) {
int V_60 = V_57 -> V_60 ;
if ( ( V_57 -> V_61 == V_56 ) && ( V_58 >= ( V_60 + V_59 ) ) )
return V_57 ;
V_57 = (struct V_53 * ) ( ( T_2 * ) V_57 + ( V_60 + V_59 ) ) ;
V_58 -= ( V_60 + V_59 ) ;
}
return NULL ;
}
static bool
F_12 ( const T_2 * V_62 , const T_2 * * V_63 , T_5 * V_64 ,
const T_2 * V_65 , T_5 V_66 , T_2 type )
{
if ( V_62 [ V_67 ] >= V_66 + 1 &&
! memcmp ( & V_62 [ V_68 ] , V_65 , V_66 ) &&
type == V_62 [ V_68 + V_66 ] ) {
return true ;
}
if ( V_63 == NULL )
return false ;
V_62 += V_62 [ V_67 ] + V_59 ;
* V_64 -= ( int ) ( V_62 - * V_63 ) ;
* V_63 = V_62 ;
return false ;
}
static struct V_69 *
F_13 ( const T_2 * V_70 , T_5 V_60 )
{
const struct V_53 * V_62 ;
while ( ( V_62 = F_11 ( V_70 , V_60 , V_71 ) ) ) {
if ( F_12 ( ( const T_2 * ) V_62 , & V_70 , & V_60 ,
V_72 , V_73 , V_74 ) )
return (struct V_69 * ) V_62 ;
}
return NULL ;
}
static struct V_69 *
F_14 ( const T_2 * V_70 , T_5 V_60 )
{
const struct V_53 * V_62 ;
while ( ( V_62 = F_11 ( V_70 , V_60 , V_71 ) ) ) {
if ( F_12 ( ( T_2 * ) V_62 , & V_70 , & V_60 ,
V_72 , V_73 , V_75 ) )
return (struct V_69 * ) V_62 ;
}
return NULL ;
}
static void F_15 ( struct V_76 * V_56 ,
struct V_77 * V_78 )
{
V_78 -> V_79 = F_16 ( V_56 -> V_79 ) ;
V_78 -> V_60 = F_16 ( V_56 -> V_60 ) ;
V_78 -> V_80 = F_16 ( V_56 -> V_80 ) ;
V_78 -> V_81 = F_16 ( V_56 -> V_81 ) ;
V_78 -> V_82 . V_83 = F_16 ( V_56 -> V_82 . V_83 ) ;
V_78 -> V_82 . V_84 = F_17 ( V_56 -> V_82 . V_84 ) ;
V_78 -> V_85 = F_16 ( V_56 -> V_85 ) ;
memcpy ( V_78 -> V_86 , V_56 -> V_86 , sizeof( V_56 -> V_86 ) ) ;
memcpy ( V_78 -> V_87 , V_56 -> V_87 , sizeof( V_56 -> V_87 ) ) ;
}
static int
F_18 ( struct V_88 * V_89 , struct V_76 * V_56 )
{
int V_90 ;
struct V_77 V_78 ;
F_15 ( V_56 , & V_78 ) ;
F_19 ( V_89 ) ;
V_90 = F_20 ( F_21 ( V_89 ) , L_3 , & V_78 ,
sizeof( V_78 ) ) ;
if ( V_90 )
F_22 ( L_4 , V_90 ) ;
return V_90 ;
}
static T_4
F_23 ( struct V_91 * V_92 , bool V_93 )
{
T_4 V_90 ;
T_5 V_94 ;
if ( V_93 )
V_94 = V_95 | V_96 ;
else
V_94 = 0 ;
V_90 = F_24 ( V_92 , L_5 , V_94 ) ;
if ( V_90 ) {
F_3 ( V_24 , L_6 ,
V_94 , V_90 ) ;
V_90 = 0 ;
} else {
V_90 = F_24 ( V_92 , L_7 , V_93 ) ;
if ( V_90 ) {
F_3 ( V_24 , L_8 ,
V_93 , V_90 ) ;
V_90 = 0 ;
} else
F_3 ( V_24 , L_9 ,
V_93 , V_94 ) ;
}
return V_90 ;
}
static void
F_25 ( struct V_97 * V_98 )
{
struct V_1 * V_2 ;
struct V_91 * V_92 ;
V_2 = F_26 ( V_98 , struct V_1 , V_98 ) ;
V_92 = V_2 -> V_92 ;
if ( ( V_98 -> V_99 == V_100 ) ||
( V_98 -> V_99 == V_101 ) ||
( V_98 -> V_99 == V_102 ) )
F_27 ( V_92 -> V_103 , V_92 -> V_104 ,
V_105 ) ;
else
F_27 ( V_92 -> V_103 , V_92 -> V_104 ,
V_106 ) ;
}
static bool F_28 ( struct V_1 * V_2 )
{
enum V_107 V_99 ;
V_99 = V_2 -> V_98 . V_99 ;
return V_99 == V_101 || V_99 == V_102 ;
}
static bool F_29 ( struct V_1 * V_2 )
{
return V_2 -> V_98 . V_99 == V_100 ;
}
static struct V_97 * F_30 ( struct V_108 * V_108 ,
const char * V_109 ,
enum V_107 type ,
T_5 * V_81 ,
struct V_110 * V_111 )
{
struct V_97 * V_98 ;
F_3 ( V_24 , L_10 , V_109 , type ) ;
switch ( type ) {
case V_100 :
case V_112 :
case V_101 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
return F_31 ( - V_117 ) ;
case V_118 :
case V_102 :
case V_119 :
V_98 = F_32 ( V_108 , V_109 , type , V_81 , V_111 ) ;
if ( ! F_33 ( V_98 ) )
F_25 ( V_98 ) ;
return V_98 ;
case V_120 :
default:
return F_31 ( - V_121 ) ;
}
}
static void F_34 ( struct V_91 * V_92 , int V_122 )
{
if ( F_35 ( V_92 , V_123 ) )
F_36 ( V_92 , V_122 ) ;
}
void F_36 ( struct V_91 * V_92 , int V_122 )
{
T_4 V_90 = 0 ;
if ( F_1 ( V_92 -> V_2 ) ) {
V_90 = F_24 ( V_92 , L_11 , V_122 ) ;
if ( V_90 ) {
F_22 ( L_12 ) ;
return;
}
F_3 ( V_5 , L_13 , V_122 ) ;
}
}
T_4 F_37 ( struct V_124 * V_125 ,
struct V_91 * V_92 , bool V_126 ,
bool V_127 )
{
struct V_128 V_129 ;
struct V_130 * V_131 ;
T_4 V_90 = 0 ;
F_3 ( V_132 , L_14 ) ;
V_131 = V_125 -> V_131 ;
V_125 -> V_131 = NULL ;
if ( F_38 ( & V_125 -> V_133 ) )
F_39 ( & V_125 -> V_133 ) ;
if ( V_127 ) {
F_3 ( V_132 , L_15 ) ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
memset ( V_129 . V_134 , 0xFF , V_135 ) ;
V_129 . V_136 = V_137 ;
V_129 . V_138 = 0 ;
V_129 . V_139 = F_16 ( 1 ) ;
V_129 . V_140 = F_16 ( 1 ) ;
V_129 . V_141 = F_16 ( - 1 ) ;
V_129 . V_142 = F_16 ( - 1 ) ;
V_129 . V_143 = F_16 ( - 1 ) ;
V_129 . V_144 [ 0 ] = F_17 ( - 1 ) ;
V_90 = F_40 ( V_92 , V_145 ,
& V_129 , sizeof( V_129 ) ) ;
if ( V_90 )
F_22 ( L_16 ) ;
}
F_34 ( V_92 , 1 ) ;
if ( V_125 -> V_146 ) {
F_3 ( V_132 , L_17 ) ;
V_125 -> V_146 = false ;
if ( ! V_126 )
F_41 ( F_42 ( V_125 ) ) ;
} else if ( V_131 ) {
F_3 ( V_132 , L_18 ,
V_126 ? L_19 : L_20 ) ;
F_43 ( V_131 , V_126 ) ;
}
if ( ! F_44 ( V_147 , & V_125 -> V_148 ) )
F_3 ( V_132 , L_21 ) ;
return V_90 ;
}
static
int F_45 ( struct V_108 * V_108 , struct V_97 * V_98 )
{
struct V_124 * V_125 = F_46 ( V_108 ) ;
struct V_88 * V_89 = V_98 -> V_149 ;
if ( F_47 ( V_125 ) )
return - V_150 ;
if ( V_89 ) {
if ( F_2 ( V_147 , & V_125 -> V_148 ) &&
V_125 -> V_151 . V_92 == F_21 ( V_89 ) )
F_37 ( V_125 , F_21 ( V_89 ) ,
true , true ) ;
F_24 ( F_21 ( V_89 ) , L_11 , 1 ) ;
}
switch ( V_98 -> V_99 ) {
case V_100 :
case V_112 :
case V_101 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
return - V_117 ;
case V_118 :
case V_102 :
case V_119 :
return F_48 ( V_108 , V_98 ) ;
case V_120 :
default:
return - V_121 ;
}
return - V_117 ;
}
static T_4
F_49 ( struct V_108 * V_108 , struct V_88 * V_89 ,
enum V_107 type , T_5 * V_81 ,
struct V_110 * V_111 )
{
struct V_124 * V_125 = F_46 ( V_108 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_1 * V_2 = V_92 -> V_2 ;
T_4 V_152 = 0 ;
T_4 V_153 = 0 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_22 , V_89 , type ) ;
switch ( type ) {
case V_115 :
case V_114 :
F_22 ( L_23 ,
type ) ;
return - V_117 ;
case V_100 :
V_152 = 0 ;
break;
case V_112 :
if ( ( V_2 -> V_98 . V_99 == V_118 ) ||
( V_2 -> V_98 . V_99 == V_102 ) ) {
F_3 ( V_24 , L_24 ) ;
return 0 ;
}
V_152 = 1 ;
break;
case V_101 :
case V_102 :
V_153 = 1 ;
break;
default:
V_90 = - V_121 ;
goto V_154;
}
if ( V_153 ) {
if ( type == V_102 ) {
F_3 ( V_5 , L_25 ) ;
V_90 = F_50 ( V_125 , V_155 ) ;
}
if ( ! V_90 ) {
F_51 ( V_156 , & V_2 -> V_4 ) ;
F_3 ( V_5 , L_26 ) ;
}
} else {
V_90 = F_52 ( V_92 , V_157 , V_152 ) ;
if ( V_90 ) {
F_22 ( L_27 , V_90 ) ;
V_90 = - V_158 ;
goto V_154;
}
F_3 ( V_5 , L_28 , F_29 ( V_2 ) ?
L_29 : L_30 ) ;
}
V_89 -> V_159 -> V_99 = type ;
F_25 ( & V_2 -> V_98 ) ;
V_154:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static void F_53 ( struct V_124 * V_125 ,
struct V_128 * V_129 ,
struct V_130 * V_160 )
{
T_5 V_161 ;
T_5 V_162 ;
T_4 V_163 ;
T_4 V_13 ;
T_1 V_164 ;
char * V_165 ;
struct V_166 V_167 ;
memset ( V_129 -> V_134 , 0xFF , V_135 ) ;
V_129 -> V_136 = V_137 ;
V_129 -> V_138 = 0 ;
V_129 -> V_139 = 0 ;
V_129 -> V_140 = F_16 ( - 1 ) ;
V_129 -> V_141 = F_16 ( - 1 ) ;
V_129 -> V_142 = F_16 ( - 1 ) ;
V_129 -> V_143 = F_16 ( - 1 ) ;
memset ( & V_129 -> V_167 , 0 , sizeof( V_129 -> V_167 ) ) ;
if ( ! V_160 )
return;
V_161 = V_160 -> V_161 ;
V_162 = V_160 -> V_162 ;
F_3 ( V_132 , L_32 ,
V_162 ) ;
if ( V_162 > 0 ) {
for ( V_163 = 0 ; V_163 < V_162 ; V_163 ++ ) {
V_164 = F_10 ( & V_125 -> V_18 ,
V_160 -> V_168 [ V_163 ] ) ;
F_3 ( V_132 , L_33 ,
V_160 -> V_168 [ V_163 ] -> V_169 , V_164 ) ;
V_129 -> V_144 [ V_163 ] = F_17 ( V_164 ) ;
}
} else {
F_3 ( V_132 , L_34 ) ;
}
F_3 ( V_132 , L_35 , V_161 ) ;
if ( V_161 > 0 ) {
V_13 = F_54 ( struct V_128 , V_144 ) +
V_162 * sizeof( T_1 ) ;
V_13 = F_55 ( V_13 , sizeof( T_5 ) ) ;
V_165 = ( char * ) V_129 + V_13 ;
for ( V_163 = 0 ; V_163 < V_161 ; V_163 ++ ) {
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_170 =
F_16 ( V_160 -> V_171 [ V_163 ] . V_172 ) ;
memcpy ( V_167 . V_173 , V_160 -> V_171 [ V_163 ] . V_174 ,
V_160 -> V_171 [ V_163 ] . V_172 ) ;
if ( ! V_167 . V_170 )
F_3 ( V_132 , L_36 , V_163 ) ;
else
F_3 ( V_132 , L_37 ,
V_163 , V_167 . V_173 , V_167 . V_170 ) ;
memcpy ( V_165 , & V_167 , sizeof( V_167 ) ) ;
V_165 += sizeof( V_167 ) ;
}
} else {
F_3 ( V_132 , L_38 , V_160 -> V_171 ) ;
if ( ( V_160 -> V_171 ) && V_160 -> V_171 -> V_172 ) {
F_3 ( V_132 , L_39 ,
V_129 -> V_167 . V_173 ,
V_160 -> V_171 -> V_172 ) ;
V_129 -> V_167 . V_170 =
F_16 ( V_160 -> V_171 -> V_172 ) ;
memcpy ( & V_129 -> V_167 . V_173 , V_160 -> V_171 -> V_174 ,
V_160 -> V_171 -> V_172 ) ;
}
}
V_129 -> V_139 =
F_16 ( ( V_161 << V_175 ) |
( V_162 & V_176 ) ) ;
}
static T_4
F_56 ( struct V_124 * V_125 , struct V_91 * V_92 ,
struct V_130 * V_160 , T_1 V_177 )
{
T_4 V_178 = V_179 +
F_54 ( struct V_180 , V_129 ) ;
struct V_180 * V_111 ;
T_4 V_90 = 0 ;
F_3 ( V_132 , L_40 ) ;
if ( V_160 != NULL ) {
V_178 += sizeof( T_5 ) * ( ( V_160 -> V_162 + 1 ) / 2 ) ;
V_178 += sizeof( struct V_181 ) * V_160 -> V_161 ;
}
V_111 = F_57 ( V_178 , V_182 ) ;
if ( ! V_111 ) {
V_90 = - V_183 ;
goto exit;
}
F_58 ( V_178 + sizeof( L_41 ) >= V_184 ) ;
F_53 ( V_125 , & V_111 -> V_129 , V_160 ) ;
V_111 -> V_185 = F_16 ( V_186 ) ;
V_111 -> V_177 = F_17 ( V_177 ) ;
V_111 -> V_187 = F_17 ( 0x1234 ) ;
V_90 = F_59 ( V_92 , L_41 , V_111 , V_178 ) ;
if ( V_90 ) {
if ( V_90 == - V_150 )
F_3 ( V_5 , L_42 ) ;
else
F_22 ( L_43 , V_90 ) ;
}
F_60 ( V_111 ) ;
exit:
return V_90 ;
}
static T_4
F_61 ( struct V_124 * V_125 , struct V_108 * V_108 ,
struct V_91 * V_92 , struct V_130 * V_160 )
{
T_4 V_90 ;
T_5 V_188 ;
struct V_189 * V_190 ;
struct V_151 * V_191 = & V_125 -> V_151 ;
F_3 ( V_132 , L_14 ) ;
V_191 -> V_92 = V_92 ;
V_191 -> V_108 = V_108 ;
V_191 -> V_192 = V_193 ;
V_188 = V_125 -> V_194 ? 0 : 1 ;
V_90 = F_52 ( V_92 , V_195 ,
V_188 ) ;
if ( V_90 ) {
F_22 ( L_43 , V_90 ) ;
return V_90 ;
}
F_34 ( V_92 , 0 ) ;
V_190 = (struct V_189 * ) V_125 -> V_151 . V_196 ;
V_190 -> V_185 = 0 ;
V_190 -> V_197 = 0 ;
V_190 -> V_55 = V_198 ;
V_90 = V_191 -> V_199 ( V_125 , V_92 , V_160 , V_200 ) ;
if ( V_90 )
F_34 ( V_92 , 1 ) ;
return V_90 ;
}
static T_4
F_62 ( struct V_108 * V_108 , struct V_1 * V_2 ,
struct V_130 * V_160 ,
struct V_201 * V_202 )
{
struct V_91 * V_92 = V_2 -> V_92 ;
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_201 * V_171 ;
struct V_203 * V_204 = & V_125 -> V_205 ;
T_5 V_188 ;
bool V_206 ;
bool V_207 ;
T_4 V_90 ;
T_5 V_170 ;
F_3 ( V_132 , L_44 ) ;
if ( F_2 ( V_147 , & V_125 -> V_148 ) ) {
F_22 ( L_45 , V_125 -> V_148 ) ;
return - V_158 ;
}
if ( F_2 ( V_208 , & V_125 -> V_148 ) ) {
F_22 ( L_46 ,
V_125 -> V_148 ) ;
return - V_158 ;
}
if ( F_2 ( V_209 , & V_125 -> V_148 ) ) {
F_22 ( L_47 ,
V_125 -> V_148 ) ;
return - V_158 ;
}
if ( F_2 ( V_210 , & V_92 -> V_2 -> V_4 ) ) {
F_22 ( L_48 , V_92 -> V_2 -> V_4 ) ;
return - V_158 ;
}
if ( V_2 == V_125 -> V_211 . V_212 [ V_213 ] . V_2 )
V_2 = V_125 -> V_211 . V_212 [ V_214 ] . V_2 ;
F_64 ( & V_125 -> V_133 , V_215 +
V_216 * V_217 / 1000 ) ;
V_206 = false ;
if ( V_160 ) {
V_171 = V_160 -> V_171 ;
V_206 = true ;
} else {
V_171 = V_202 ;
}
V_125 -> V_131 = V_160 ;
F_51 ( V_147 , & V_125 -> V_148 ) ;
if ( V_206 ) {
V_125 -> V_151 . V_199 = F_56 ;
V_90 = F_65 ( V_108 , V_160 , V_2 ) ;
if ( V_90 )
goto V_218;
V_90 = F_61 ( V_125 , V_108 , V_2 -> V_92 , V_160 ) ;
if ( V_90 )
goto V_218;
} else {
F_3 ( V_132 , L_49 ,
V_171 -> V_174 , V_171 -> V_172 ) ;
memset ( & V_204 -> V_167 , 0 , sizeof( V_204 -> V_167 ) ) ;
V_170 = F_66 ( T_2 , sizeof( V_204 -> V_167 . V_173 ) , V_171 -> V_172 ) ;
V_204 -> V_167 . V_170 = F_16 ( 0 ) ;
V_207 = false ;
if ( V_170 ) {
memcpy ( V_204 -> V_167 . V_173 , V_171 -> V_174 , V_170 ) ;
V_204 -> V_167 . V_170 = F_16 ( V_170 ) ;
V_207 = true ;
} else
F_3 ( V_132 , L_50 ) ;
V_188 = V_125 -> V_194 ? 0 : 1 ;
V_90 = F_52 ( V_92 , V_195 ,
V_188 ) ;
if ( V_90 ) {
F_22 ( L_51 , V_90 ) ;
goto V_218;
}
F_34 ( V_92 , 0 ) ;
V_90 = F_40 ( V_92 , V_145 ,
& V_204 -> V_167 , sizeof( V_204 -> V_167 ) ) ;
if ( V_90 ) {
if ( V_90 == - V_150 )
F_3 ( V_5 , L_52 ,
V_204 -> V_167 . V_173 ) ;
else
F_22 ( L_53 , V_90 ) ;
F_34 ( V_92 , 1 ) ;
goto V_218;
}
}
return 0 ;
V_218:
F_67 ( V_147 , & V_125 -> V_148 ) ;
if ( F_38 ( & V_125 -> V_133 ) )
F_39 ( & V_125 -> V_133 ) ;
V_125 -> V_131 = NULL ;
return V_90 ;
}
static T_4
F_68 ( struct V_108 * V_108 , struct V_130 * V_160 )
{
struct V_1 * V_2 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
V_2 = F_26 ( V_160 -> V_98 , struct V_1 , V_98 ) ;
if ( ! F_1 ( V_2 ) )
return - V_219 ;
V_90 = F_62 ( V_108 , V_2 , V_160 , NULL ) ;
if ( V_90 )
F_22 ( L_54 , V_90 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4 F_69 ( struct V_88 * V_89 , T_5 V_220 )
{
T_4 V_90 = 0 ;
V_90 = F_24 ( F_21 ( V_89 ) , L_55 ,
V_220 ) ;
if ( V_90 )
F_22 ( L_56 , V_90 ) ;
return V_90 ;
}
static T_4 F_70 ( struct V_88 * V_89 , T_5 V_221 )
{
T_4 V_90 = 0 ;
V_90 = F_24 ( F_21 ( V_89 ) , L_57 ,
V_221 ) ;
if ( V_90 )
F_22 ( L_56 , V_90 ) ;
return V_90 ;
}
static T_4 F_71 ( struct V_88 * V_89 , T_5 V_222 , bool V_223 )
{
T_4 V_90 = 0 ;
T_5 V_224 = ( V_223 ? V_225 : V_226 ) ;
V_90 = F_52 ( F_21 ( V_89 ) , V_224 , V_222 ) ;
if ( V_90 ) {
F_22 ( L_58 , V_224 , V_90 ) ;
return V_90 ;
}
return V_90 ;
}
static T_4 F_72 ( struct V_108 * V_108 , T_5 V_227 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_88 * V_89 = F_73 ( V_125 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
if ( V_227 & V_228 &&
( V_125 -> V_229 -> V_220 != V_108 -> V_220 ) ) {
V_125 -> V_229 -> V_220 = V_108 -> V_220 ;
V_90 = F_69 ( V_89 , V_125 -> V_229 -> V_220 ) ;
if ( ! V_90 )
goto V_154;
}
if ( V_227 & V_230 &&
( V_125 -> V_229 -> V_221 != V_108 -> V_221 ) ) {
V_125 -> V_229 -> V_221 = V_108 -> V_221 ;
V_90 = F_70 ( V_89 , V_125 -> V_229 -> V_221 ) ;
if ( ! V_90 )
goto V_154;
}
if ( V_227 & V_231
&& ( V_125 -> V_229 -> V_232 != V_108 -> V_232 ) ) {
V_125 -> V_229 -> V_232 = V_108 -> V_232 ;
V_90 = F_71 ( V_89 , V_125 -> V_229 -> V_232 , true ) ;
if ( ! V_90 )
goto V_154;
}
if ( V_227 & V_233
&& ( V_125 -> V_229 -> V_234 != V_108 -> V_234 ) ) {
V_125 -> V_229 -> V_234 = V_108 -> V_234 ;
V_90 = F_71 ( V_89 , V_125 -> V_229 -> V_234 , false ) ;
if ( ! V_90 )
goto V_154;
}
V_154:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static void F_74 ( struct V_235 * V_236 )
{
memset ( V_236 , 0 , sizeof( * V_236 ) ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_124 * V_125 = F_63 ( V_2 -> V_98 . V_108 ) ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( F_2 ( V_237 , & V_2 -> V_4 ) ) {
F_3 ( V_5 , L_59 ) ;
V_90 = F_40 ( V_2 -> V_92 ,
V_238 , NULL , 0 ) ;
if ( V_90 ) {
F_22 ( L_60 , V_90 ) ;
}
F_67 ( V_237 , & V_2 -> V_4 ) ;
F_76 ( V_2 -> V_98 . V_149 , 0 , NULL , 0 , V_182 ) ;
}
F_67 ( V_210 , & V_2 -> V_4 ) ;
F_67 ( V_209 , & V_125 -> V_148 ) ;
F_77 ( V_2 , V_239 , 0 ) ;
F_3 ( V_24 , L_31 ) ;
}
static T_4
F_78 ( struct V_108 * V_108 , struct V_88 * V_89 ,
struct V_240 * V_111 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_235 * V_241 = & V_92 -> V_2 -> V_241 ;
struct V_242 V_243 ;
T_6 V_244 = 0 ;
T_4 V_90 = 0 ;
T_4 V_245 = 0 ;
T_4 V_246 ;
T_1 V_164 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
if ( V_111 -> V_174 )
F_3 ( V_247 , L_61 , V_111 -> V_174 ) ;
else {
F_3 ( V_247 , L_62 ) ;
return - V_117 ;
}
F_51 ( V_210 , & V_92 -> V_2 -> V_4 ) ;
if ( V_111 -> V_134 )
F_3 ( V_247 , L_63 , V_111 -> V_134 ) ;
else
F_3 ( V_247 , L_64 ) ;
if ( V_111 -> V_248 . V_25 )
F_3 ( V_247 , L_65 ,
V_111 -> V_248 . V_25 -> V_26 ) ;
else
F_3 ( V_247 , L_66 ) ;
if ( V_111 -> V_249 )
F_3 ( V_247 , L_67 ) ;
else
F_3 ( V_247 , L_68 ) ;
if ( V_111 -> V_62 && V_111 -> V_250 )
F_3 ( V_247 , L_69 , V_111 -> V_250 ) ;
else
F_3 ( V_247 , L_70 ) ;
if ( V_111 -> V_251 )
F_3 ( V_247 , L_71 ,
V_111 -> V_251 ) ;
else
F_3 ( V_247 , L_72 ) ;
if ( V_111 -> V_252 )
F_3 ( V_247 , L_73 , V_111 -> V_252 ) ;
else
F_3 ( V_247 , L_74 ) ;
if ( V_111 -> V_253 )
F_3 ( V_247 , L_75 ) ;
else
F_3 ( V_247 , L_76 ) ;
if ( V_111 -> V_253 )
V_245 |= V_254 ;
V_90 = F_24 ( V_92 , L_77 , V_245 ) ;
if ( V_90 ) {
F_22 ( L_78 , V_90 ) ;
goto V_154;
}
if ( V_111 -> V_251 )
V_246 = V_111 -> V_251 ;
else
V_246 = 100 ;
V_90 = F_52 ( V_92 , V_255 , V_246 ) ;
if ( V_90 ) {
F_22 ( L_79 , V_90 ) ;
goto V_154;
}
memset ( & V_243 , 0 , sizeof( struct V_242 ) ) ;
V_241 -> V_174 . V_170 = F_66 ( T_5 , V_111 -> V_172 , 32 ) ;
memcpy ( V_241 -> V_174 . V_173 , V_111 -> V_174 , V_241 -> V_174 . V_170 ) ;
memcpy ( V_243 . V_167 . V_173 , V_111 -> V_174 , V_241 -> V_174 . V_170 ) ;
V_243 . V_167 . V_170 = F_16 ( V_241 -> V_174 . V_170 ) ;
V_244 = sizeof( V_243 . V_167 ) ;
if ( V_111 -> V_134 ) {
memcpy ( V_243 . V_129 . V_134 , V_111 -> V_134 , V_135 ) ;
V_244 = sizeof( V_243 . V_167 ) +
V_256 ;
memcpy ( V_241 -> V_134 , V_111 -> V_134 , V_135 ) ;
} else {
memset ( V_243 . V_129 . V_134 , 0xFF , V_135 ) ;
memset ( V_241 -> V_134 , 0 , V_135 ) ;
}
if ( V_111 -> V_248 . V_25 ) {
T_5 V_257 ;
V_125 -> V_258 =
F_7 (
V_111 -> V_248 . V_25 -> V_26 ) ;
if ( V_111 -> V_249 ) {
V_164 = F_6 ( & V_125 -> V_18 ,
& V_111 -> V_248 ) ;
V_243 . V_129 . V_259 [ 0 ] =
F_17 ( V_164 ) ;
V_243 . V_129 . V_260 = F_16 ( 1 ) ;
V_244 += sizeof( V_243 . V_129 ) ;
}
V_257 = V_125 -> V_258 ;
V_90 = F_52 ( V_92 , V_261 ,
V_257 ) ;
if ( V_90 ) {
F_22 ( L_80 , V_90 ) ;
goto V_154;
}
} else
V_125 -> V_258 = 0 ;
V_125 -> V_262 = false ;
V_90 = F_40 ( V_92 , V_263 ,
& V_243 , V_244 ) ;
if ( V_90 ) {
F_22 ( L_81 , V_90 ) ;
goto V_154;
}
V_154:
if ( V_90 )
F_67 ( V_210 , & V_92 -> V_2 -> V_4 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_79 ( struct V_108 * V_108 , struct V_88 * V_89 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
F_75 ( V_92 -> V_2 ) ;
F_3 ( V_24 , L_31 ) ;
return 0 ;
}
static T_4 F_80 ( struct V_88 * V_89 ,
struct V_264 * V_265 )
{
struct V_235 * V_241 = F_81 ( V_89 ) ;
struct V_266 * V_267 ;
T_4 V_268 = 0 ;
T_4 V_90 = 0 ;
if ( V_265 -> V_269 . V_270 & V_271 )
V_268 = V_272 | V_273 ;
else if ( V_265 -> V_269 . V_270 & V_274 )
V_268 = V_275 | V_276 ;
else
V_268 = V_277 ;
F_3 ( V_247 , L_82 , V_268 ) ;
V_90 = F_82 ( F_21 ( V_89 ) , L_83 , V_268 ) ;
if ( V_90 ) {
F_22 ( L_84 , V_90 ) ;
return V_90 ;
}
V_267 = & V_241 -> V_267 ;
V_267 -> V_270 = V_265 -> V_269 . V_270 ;
return V_90 ;
}
static T_4 F_83 ( struct V_88 * V_89 ,
struct V_264 * V_265 )
{
struct V_235 * V_241 = F_81 ( V_89 ) ;
struct V_266 * V_267 ;
T_4 V_268 = 0 ;
T_4 V_90 = 0 ;
switch ( V_265 -> V_278 ) {
case V_279 :
V_268 = 0 ;
F_3 ( V_247 , L_85 ) ;
break;
case V_280 :
V_268 = 1 ;
F_3 ( V_247 , L_86 ) ;
break;
case V_281 :
V_268 = 2 ;
F_3 ( V_247 , L_87 ) ;
break;
case V_282 :
F_3 ( V_247 , L_88 ) ;
default:
V_268 = 2 ;
F_22 ( L_89 , V_265 -> V_278 ) ;
break;
}
V_90 = F_82 ( F_21 ( V_89 ) , L_90 , V_268 ) ;
if ( V_90 ) {
F_22 ( L_91 , V_90 ) ;
return V_90 ;
}
V_267 = & V_241 -> V_267 ;
V_267 -> V_278 = V_265 -> V_278 ;
return V_90 ;
}
static T_4
F_84 ( struct V_88 * V_89 ,
struct V_264 * V_265 , bool V_283 )
{
struct V_235 * V_241 = F_81 ( V_89 ) ;
struct V_266 * V_267 ;
T_4 V_284 = 0 ;
T_4 V_285 = 0 ;
T_4 V_245 ;
T_4 V_90 = 0 ;
if ( V_265 -> V_269 . V_286 ) {
switch ( V_265 -> V_269 . V_287 [ 0 ] ) {
case V_288 :
case V_289 :
V_284 = V_254 ;
break;
case V_290 :
V_284 = V_291 ;
break;
case V_292 :
V_284 = V_293 ;
break;
case V_294 :
V_284 = V_293 ;
break;
default:
F_22 ( L_92 ,
V_265 -> V_269 . V_287 [ 0 ] ) ;
return - V_121 ;
}
}
if ( V_265 -> V_269 . V_295 ) {
switch ( V_265 -> V_269 . V_295 ) {
case V_288 :
case V_289 :
V_285 = V_254 ;
break;
case V_290 :
V_285 = V_291 ;
break;
case V_292 :
V_285 = V_293 ;
break;
case V_294 :
V_285 = V_293 ;
break;
default:
F_22 ( L_93 ,
V_265 -> V_269 . V_295 ) ;
return - V_121 ;
}
}
F_3 ( V_247 , L_94 , V_284 , V_285 ) ;
if ( F_14 ( V_265 -> V_62 , V_265 -> V_250 ) && ! V_284 && ! V_285 &&
V_265 -> V_253 )
V_284 = V_293 ;
if ( V_283 )
V_245 = V_284 | V_285 | V_296 ;
else
V_245 = V_284 | V_285 ;
V_90 = F_82 ( F_21 ( V_89 ) , L_77 , V_245 ) ;
if ( V_90 ) {
F_22 ( L_43 , V_90 ) ;
return V_90 ;
}
V_267 = & V_241 -> V_267 ;
V_267 -> V_297 = V_265 -> V_269 . V_287 [ 0 ] ;
V_267 -> V_295 = V_265 -> V_269 . V_295 ;
return V_90 ;
}
static T_4
F_85 ( struct V_88 * V_89 , struct V_264 * V_265 )
{
struct V_235 * V_241 = F_81 ( V_89 ) ;
struct V_266 * V_267 ;
T_4 V_268 = 0 ;
T_4 V_90 = 0 ;
if ( V_265 -> V_269 . V_298 ) {
V_90 = F_86 ( F_21 ( V_89 ) ,
L_83 , & V_268 ) ;
if ( V_90 ) {
F_22 ( L_95 , V_90 ) ;
return V_90 ;
}
if ( V_268 & ( V_272 | V_273 ) ) {
switch ( V_265 -> V_269 . V_299 [ 0 ] ) {
case V_300 :
V_268 = V_273 ;
break;
case V_301 :
V_268 = V_272 ;
break;
default:
F_22 ( L_93 ,
V_265 -> V_269 . V_295 ) ;
return - V_121 ;
}
} else if ( V_268 & ( V_275 | V_276 ) ) {
switch ( V_265 -> V_269 . V_299 [ 0 ] ) {
case V_300 :
V_268 = V_276 ;
break;
case V_301 :
V_268 = V_275 ;
break;
default:
F_22 ( L_93 ,
V_265 -> V_269 . V_295 ) ;
return - V_121 ;
}
}
F_3 ( V_247 , L_96 , V_268 ) ;
V_90 = F_82 ( F_21 ( V_89 ) ,
L_83 , V_268 ) ;
if ( V_90 ) {
F_22 ( L_97 , V_90 ) ;
return V_90 ;
}
}
V_267 = & V_241 -> V_267 ;
V_267 -> V_302 = V_265 -> V_269 . V_299 [ 0 ] ;
return V_90 ;
}
static T_4
F_87 ( struct V_88 * V_89 ,
struct V_264 * V_265 )
{
struct V_235 * V_241 = F_81 ( V_89 ) ;
struct V_266 * V_267 ;
struct V_76 V_56 ;
T_4 V_268 ;
T_4 V_90 = 0 ;
F_3 ( V_247 , L_98 , V_265 -> V_303 ) ;
if ( V_265 -> V_303 == 0 )
return 0 ;
V_267 = & V_241 -> V_267 ;
F_3 ( V_247 , L_99 ,
V_267 -> V_270 , V_267 -> V_297 ) ;
if ( V_267 -> V_270 & ( V_271 | V_274 ) )
return 0 ;
if ( ! ( V_267 -> V_297 &
( V_288 | V_289 ) ) )
return 0 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_60 = ( T_5 ) V_265 -> V_303 ;
V_56 . V_79 = ( T_5 ) V_265 -> V_304 ;
if ( V_56 . V_60 > sizeof( V_56 . V_86 ) ) {
F_22 ( L_100 , V_56 . V_60 ) ;
return - V_121 ;
}
memcpy ( V_56 . V_86 , V_265 -> V_56 , V_56 . V_60 ) ;
V_56 . V_81 = V_305 ;
switch ( V_267 -> V_297 ) {
case V_288 :
V_56 . V_80 = V_306 ;
break;
case V_289 :
V_56 . V_80 = V_307 ;
break;
default:
F_22 ( L_101 ,
V_265 -> V_269 . V_287 [ 0 ] ) ;
return - V_121 ;
}
F_3 ( V_247 , L_102 ,
V_56 . V_60 , V_56 . V_79 , V_56 . V_80 ) ;
F_3 ( V_247 , L_103 , V_56 . V_86 ) ;
V_90 = F_18 ( V_89 , & V_56 ) ;
if ( V_90 )
return V_90 ;
if ( V_267 -> V_278 == V_280 ) {
F_3 ( V_247 , L_104 ) ;
V_268 = V_308 ;
V_90 = F_82 ( F_21 ( V_89 ) , L_90 , V_268 ) ;
if ( V_90 )
F_22 ( L_91 , V_90 ) ;
}
return V_90 ;
}
static
enum V_309 F_88 ( struct V_91 * V_92 ,
enum V_309 type )
{
if ( type == V_281 &&
F_35 ( V_92 , V_310 ) ) {
F_3 ( V_247 , L_105 ) ;
type = V_279 ;
}
return type ;
}
static T_4
F_89 ( struct V_108 * V_108 , struct V_88 * V_89 ,
struct V_264 * V_265 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_235 * V_241 = & V_92 -> V_2 -> V_241 ;
struct V_52 * V_25 = V_265 -> V_258 ;
struct V_242 V_243 ;
T_6 V_244 ;
const struct V_53 * V_311 ;
const struct V_69 * V_312 ;
const void * V_62 ;
T_5 V_250 ;
struct V_313 * V_314 ;
T_1 V_164 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
if ( ! V_265 -> V_174 ) {
F_22 ( L_106 ) ;
return - V_117 ;
}
if ( V_92 -> V_2 == V_125 -> V_211 . V_212 [ V_214 ] . V_2 ) {
V_62 = NULL ;
V_250 = 0 ;
V_312 = F_13 ( ( T_2 * ) V_265 -> V_62 , V_265 -> V_250 ) ;
if ( V_312 ) {
V_62 = V_312 ;
V_250 = V_312 -> V_60 + V_59 ;
} else {
V_311 = F_11 ( ( const T_2 * ) V_265 -> V_62 ,
V_265 -> V_250 ,
V_315 ) ;
if ( V_311 ) {
V_62 = V_311 ;
V_250 = V_311 -> V_60 + V_59 ;
}
}
F_59 ( V_92 , L_107 , V_62 , V_250 ) ;
}
V_90 = F_90 ( V_92 -> V_2 , V_316 ,
V_265 -> V_62 , V_265 -> V_250 ) ;
if ( V_90 )
F_22 ( L_108 ) ;
else
F_3 ( V_24 , L_109 ) ;
F_51 ( V_210 , & V_92 -> V_2 -> V_4 ) ;
if ( V_25 ) {
V_125 -> V_258 =
F_7 ( V_25 -> V_26 ) ;
V_164 = F_10 ( & V_125 -> V_18 , V_25 ) ;
F_3 ( V_247 , L_110 ,
V_125 -> V_258 , V_25 -> V_26 , V_164 ) ;
} else {
V_125 -> V_258 = 0 ;
V_164 = 0 ;
}
F_3 ( V_5 , L_111 , V_265 -> V_62 , V_265 -> V_250 ) ;
V_90 = F_80 ( V_89 , V_265 ) ;
if ( V_90 ) {
F_22 ( L_112 , V_90 ) ;
goto V_154;
}
V_265 -> V_278 = F_88 ( V_92 , V_265 -> V_278 ) ;
V_90 = F_83 ( V_89 , V_265 ) ;
if ( V_90 ) {
F_22 ( L_113 , V_90 ) ;
goto V_154;
}
V_90 = F_84 ( V_89 , V_265 , V_265 -> V_283 == V_317 ) ;
if ( V_90 ) {
F_22 ( L_114 , V_90 ) ;
goto V_154;
}
V_90 = F_85 ( V_89 , V_265 ) ;
if ( V_90 ) {
F_22 ( L_115 , V_90 ) ;
goto V_154;
}
V_90 = F_87 ( V_89 , V_265 ) ;
if ( V_90 ) {
F_22 ( L_116 , V_90 ) ;
goto V_154;
}
V_241 -> V_174 . V_170 = F_66 ( T_5 , ( T_5 ) sizeof( V_241 -> V_174 . V_173 ) ,
( T_5 ) V_265 -> V_172 ) ;
memcpy ( & V_241 -> V_174 . V_173 , V_265 -> V_174 , V_241 -> V_174 . V_170 ) ;
if ( V_241 -> V_174 . V_170 < V_318 ) {
V_241 -> V_174 . V_173 [ V_241 -> V_174 . V_170 ] = 0 ;
F_3 ( V_247 , L_117 , V_241 -> V_174 . V_173 ,
V_241 -> V_174 . V_170 ) ;
}
V_244 = F_54 ( struct V_313 , V_319 ) +
F_54 ( struct V_320 , V_259 ) ;
if ( V_125 -> V_258 )
V_244 += sizeof( T_1 ) ;
V_314 = F_57 ( V_244 , V_182 ) ;
if ( V_314 == NULL ) {
V_90 = - V_183 ;
goto V_154;
}
V_314 -> V_167 . V_170 = F_16 ( V_241 -> V_174 . V_170 ) ;
memcpy ( & V_314 -> V_167 . V_173 , V_265 -> V_174 ,
V_241 -> V_174 . V_170 ) ;
V_314 -> V_321 . V_138 = - 1 ;
V_314 -> V_321 . V_143 = F_16 ( - 1 ) ;
if ( V_265 -> V_134 )
memcpy ( & V_314 -> V_319 . V_134 , V_265 -> V_134 , V_135 ) ;
else
memset ( & V_314 -> V_319 . V_134 , 0xFF , V_135 ) ;
if ( V_125 -> V_258 ) {
V_314 -> V_319 . V_260 = F_16 ( 1 ) ;
V_314 -> V_319 . V_259 [ 0 ] =
F_17 ( V_164 ) ;
V_314 -> V_321 . V_141 =
F_16 ( V_322 ) ;
V_314 -> V_321 . V_142 =
F_16 ( V_323 ) ;
V_314 -> V_321 . V_140 =
F_16 ( V_322 /
V_324 ) ;
} else {
V_314 -> V_321 . V_141 = F_16 ( - 1 ) ;
V_314 -> V_321 . V_142 = F_16 ( - 1 ) ;
V_314 -> V_321 . V_140 = F_16 ( - 1 ) ;
}
V_90 = F_20 ( V_92 , L_118 , V_314 ,
V_244 ) ;
F_60 ( V_314 ) ;
if ( ! V_90 )
goto V_154;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_244 = sizeof( V_243 . V_167 ) ;
memcpy ( & V_243 . V_167 . V_173 , V_265 -> V_174 , V_241 -> V_174 . V_170 ) ;
V_243 . V_167 . V_170 = F_16 ( V_241 -> V_174 . V_170 ) ;
if ( V_265 -> V_134 )
memcpy ( V_243 . V_129 . V_134 , V_265 -> V_134 , V_135 ) ;
else
memset ( V_243 . V_129 . V_134 , 0xFF , V_135 ) ;
if ( V_125 -> V_258 ) {
V_243 . V_129 . V_259 [ 0 ] = F_17 ( V_164 ) ;
V_243 . V_129 . V_260 = F_16 ( 1 ) ;
V_244 += sizeof( V_243 . V_129 ) ;
}
V_90 = F_40 ( V_92 , V_263 ,
& V_243 , V_244 ) ;
if ( V_90 )
F_22 ( L_119 , V_90 ) ;
V_154:
if ( V_90 )
F_67 ( V_210 , & V_92 -> V_2 -> V_4 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_91 ( struct V_108 * V_108 , struct V_88 * V_89 ,
T_1 V_325 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_235 * V_241 = & V_92 -> V_2 -> V_241 ;
struct V_326 V_327 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_120 , V_325 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
F_67 ( V_237 , & V_92 -> V_2 -> V_4 ) ;
F_76 ( V_89 , V_325 , NULL , 0 , V_182 ) ;
memcpy ( & V_327 . V_87 , & V_241 -> V_134 , V_135 ) ;
V_327 . V_268 = F_16 ( V_325 ) ;
V_90 = F_40 ( V_92 , V_238 ,
& V_327 , sizeof( V_327 ) ) ;
if ( V_90 )
F_22 ( L_43 , V_90 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_92 ( struct V_108 * V_108 , struct V_97 * V_98 ,
enum V_328 type , T_4 V_329 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_88 * V_89 = F_73 ( V_125 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_1 V_330 ;
T_4 V_90 = 0 ;
T_4 V_331 = 0 ;
T_4 V_332 = F_93 ( V_329 ) ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
switch ( type ) {
case V_333 :
break;
case V_334 :
case V_335 :
if ( V_332 < 0 ) {
F_22 ( L_121 ) ;
V_90 = - V_121 ;
goto V_154;
}
break;
}
V_331 = V_336 << 16 ;
V_90 = F_52 ( V_92 , V_337 , V_331 ) ;
if ( V_90 )
F_22 ( L_122 , V_90 ) ;
if ( V_332 > 0xffff )
V_330 = 0xffff ;
else
V_330 = ( T_1 ) V_332 ;
V_90 = F_24 ( V_92 , L_123 ,
( T_4 ) F_5 ( V_330 ) ) ;
if ( V_90 )
F_22 ( L_124 , V_90 ) ;
V_125 -> V_229 -> V_338 = V_332 ;
V_154:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4 F_94 ( struct V_108 * V_108 ,
struct V_97 * V_98 ,
T_4 * V_332 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_91 * V_92 = F_21 ( F_73 ( V_125 ) ) ;
T_4 V_339 ;
T_2 V_340 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
V_90 = F_95 ( V_92 , L_123 , & V_339 ) ;
if ( V_90 ) {
F_22 ( L_43 , V_90 ) ;
goto V_154;
}
V_340 = ( T_2 ) ( V_339 & ~ V_341 ) ;
* V_332 = ( T_4 ) F_4 ( V_340 ) ;
V_154:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_96 ( struct V_108 * V_108 , struct V_88 * V_89 ,
T_2 V_304 , bool V_342 , bool V_343 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_5 V_79 ;
T_5 V_245 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
F_3 ( V_247 , L_125 , V_304 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
V_90 = F_86 ( V_92 , L_77 , & V_245 ) ;
if ( V_90 ) {
F_22 ( L_126 , V_90 ) ;
goto V_154;
}
if ( V_245 & V_254 ) {
V_79 = V_304 ;
V_90 = F_52 ( V_92 ,
V_344 , V_79 ) ;
if ( V_90 )
F_22 ( L_43 , V_90 ) ;
}
V_154:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_97 ( struct V_108 * V_108 , struct V_88 * V_89 ,
T_2 V_304 , const T_2 * V_345 , struct V_346 * V_111 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_76 V_56 ;
T_4 V_90 = 0 ;
T_2 V_347 [ 8 ] ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_79 = ( T_5 ) V_304 ;
if ( ! F_98 ( V_345 ) )
memcpy ( ( char * ) & V_56 . V_87 , ( void * ) V_345 , V_135 ) ;
V_56 . V_60 = ( T_5 ) V_111 -> V_303 ;
if ( V_56 . V_60 == 0 ) {
V_90 = F_18 ( V_89 , & V_56 ) ;
if ( V_90 )
F_22 ( L_127 , V_90 ) ;
} else {
if ( V_56 . V_60 > sizeof( V_56 . V_86 ) ) {
F_22 ( L_128 , V_56 . V_60 ) ;
return - V_121 ;
}
F_3 ( V_247 , L_129 , V_56 . V_79 ) ;
memcpy ( V_56 . V_86 , V_111 -> V_56 , V_56 . V_60 ) ;
if ( ! F_28 ( V_92 -> V_2 ) &&
( V_111 -> V_348 == V_290 ) ) {
F_3 ( V_247 , L_130 ) ;
memcpy ( V_347 , & V_56 . V_86 [ 24 ] , sizeof( V_347 ) ) ;
memcpy ( & V_56 . V_86 [ 24 ] , & V_56 . V_86 [ 16 ] , sizeof( V_347 ) ) ;
memcpy ( & V_56 . V_86 [ 16 ] , V_347 , sizeof( V_347 ) ) ;
}
if ( V_111 -> V_349 && V_111 -> V_350 == 6 ) {
T_2 * V_351 ;
V_351 = ( T_2 * ) V_111 -> V_349 ;
V_56 . V_82 . V_83 = ( V_351 [ 5 ] << 24 ) | ( V_351 [ 4 ] << 16 ) |
( V_351 [ 3 ] << 8 ) | V_351 [ 2 ] ;
V_56 . V_82 . V_84 = ( V_351 [ 1 ] << 8 ) | V_351 [ 0 ] ;
V_56 . V_85 = true ;
}
switch ( V_111 -> V_348 ) {
case V_288 :
V_56 . V_80 = V_306 ;
F_3 ( V_247 , L_131 ) ;
break;
case V_289 :
V_56 . V_80 = V_307 ;
F_3 ( V_247 , L_132 ) ;
break;
case V_290 :
V_56 . V_80 = V_352 ;
F_3 ( V_247 , L_133 ) ;
break;
case V_294 :
V_56 . V_80 = V_353 ;
F_3 ( V_247 , L_134 ) ;
break;
case V_292 :
V_56 . V_80 = V_353 ;
F_3 ( V_247 , L_135 ) ;
break;
default:
F_22 ( L_136 , V_111 -> V_348 ) ;
return - V_121 ;
}
V_90 = F_18 ( V_89 , & V_56 ) ;
if ( V_90 )
F_22 ( L_4 , V_90 ) ;
}
return V_90 ;
}
static T_4
F_99 ( struct V_108 * V_108 , struct V_88 * V_89 ,
T_2 V_304 , bool V_354 , const T_2 * V_345 ,
struct V_346 * V_111 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_76 V_56 ;
T_4 V_268 ;
T_4 V_245 ;
T_4 V_90 = 0 ;
T_2 V_347 [ 8 ] ;
F_3 ( V_24 , L_14 ) ;
F_3 ( V_247 , L_125 , V_304 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
if ( V_345 &&
( V_111 -> V_348 != V_288 ) &&
( V_111 -> V_348 != V_289 ) ) {
F_3 ( V_24 , L_137 ) ;
return F_97 ( V_108 , V_89 , V_304 , V_345 , V_111 ) ;
}
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_60 = ( T_5 ) V_111 -> V_303 ;
V_56 . V_79 = ( T_5 ) V_304 ;
if ( V_56 . V_60 > sizeof( V_56 . V_86 ) ) {
F_22 ( L_100 , V_56 . V_60 ) ;
V_90 = - V_121 ;
goto V_154;
}
memcpy ( V_56 . V_86 , V_111 -> V_56 , V_56 . V_60 ) ;
V_56 . V_81 = V_305 ;
switch ( V_111 -> V_348 ) {
case V_288 :
V_56 . V_80 = V_306 ;
V_268 = V_254 ;
F_3 ( V_247 , L_131 ) ;
break;
case V_289 :
V_56 . V_80 = V_307 ;
V_268 = V_254 ;
F_3 ( V_247 , L_132 ) ;
break;
case V_290 :
if ( ! F_28 ( V_92 -> V_2 ) ) {
F_3 ( V_247 , L_130 ) ;
memcpy ( V_347 , & V_56 . V_86 [ 24 ] , sizeof( V_347 ) ) ;
memcpy ( & V_56 . V_86 [ 24 ] , & V_56 . V_86 [ 16 ] , sizeof( V_347 ) ) ;
memcpy ( & V_56 . V_86 [ 16 ] , V_347 , sizeof( V_347 ) ) ;
}
V_56 . V_80 = V_352 ;
V_268 = V_291 ;
F_3 ( V_247 , L_133 ) ;
break;
case V_294 :
V_56 . V_80 = V_353 ;
V_268 = V_293 ;
F_3 ( V_247 , L_134 ) ;
break;
case V_292 :
V_56 . V_80 = V_353 ;
V_268 = V_293 ;
F_3 ( V_247 , L_135 ) ;
break;
default:
F_22 ( L_136 , V_111 -> V_348 ) ;
V_90 = - V_121 ;
goto V_154;
}
V_90 = F_18 ( V_89 , & V_56 ) ;
if ( V_90 )
goto V_154;
V_90 = F_86 ( V_92 , L_77 , & V_245 ) ;
if ( V_90 ) {
F_22 ( L_138 , V_90 ) ;
goto V_154;
}
V_245 |= V_268 ;
V_90 = F_82 ( V_92 , L_77 , V_245 ) ;
if ( V_90 ) {
F_22 ( L_139 , V_90 ) ;
goto V_154;
}
V_154:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_100 ( struct V_108 * V_108 , struct V_88 * V_89 ,
T_2 V_304 , bool V_354 , const T_2 * V_345 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_76 V_56 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
if ( V_304 >= V_355 ) {
F_22 ( L_140 , V_304 ) ;
return - V_121 ;
}
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_79 = ( T_5 ) V_304 ;
V_56 . V_81 = V_305 ;
V_56 . V_80 = V_356 ;
F_3 ( V_247 , L_125 , V_304 ) ;
V_90 = F_18 ( V_89 , & V_56 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_101 ( struct V_108 * V_108 , struct V_88 * V_89 ,
T_2 V_304 , bool V_354 , const T_2 * V_345 , void * V_357 ,
void (* F_102) ( void * V_357 , struct V_346 * V_111 ) )
{
struct V_346 V_111 ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_235 * V_241 = & V_92 -> V_2 -> V_241 ;
struct V_266 * V_267 ;
T_4 V_245 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
F_3 ( V_247 , L_125 , V_304 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_90 = F_86 ( V_92 , L_77 , & V_245 ) ;
if ( V_90 ) {
F_22 ( L_126 , V_90 ) ;
V_90 = - V_158 ;
goto V_154;
}
if ( V_245 & V_254 ) {
V_267 = & V_241 -> V_267 ;
if ( V_267 -> V_297 & V_288 ) {
V_111 . V_348 = V_288 ;
F_3 ( V_247 , L_131 ) ;
} else if ( V_267 -> V_297 & V_289 ) {
V_111 . V_348 = V_289 ;
F_3 ( V_247 , L_132 ) ;
}
} else if ( V_245 & V_291 ) {
V_111 . V_348 = V_290 ;
F_3 ( V_247 , L_133 ) ;
} else if ( V_245 & V_293 ) {
V_111 . V_348 = V_294 ;
F_3 ( V_247 , L_134 ) ;
} else {
F_22 ( L_141 , V_245 ) ;
V_90 = - V_121 ;
goto V_154;
}
F_102 ( V_357 , & V_111 ) ;
V_154:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_103 ( struct V_108 * V_108 ,
struct V_88 * V_89 , T_2 V_304 )
{
F_3 ( V_5 , L_142 ) ;
return - V_117 ;
}
static T_4
F_104 ( struct V_108 * V_108 , struct V_88 * V_89 ,
const T_2 * V_358 , struct V_359 * V_360 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_235 * V_241 = & V_92 -> V_2 -> V_241 ;
struct V_326 V_361 ;
int V_362 ;
T_4 V_363 ;
T_4 V_90 = 0 ;
T_2 * V_134 = V_241 -> V_134 ;
struct V_364 V_365 ;
T_5 V_366 ;
T_5 V_367 ;
F_3 ( V_24 , L_143 , V_358 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
if ( F_28 ( V_92 -> V_2 ) ) {
memcpy ( & V_365 , V_358 , V_135 ) ;
V_90 = F_105 ( V_92 , L_144 ,
& V_365 ,
sizeof( V_365 ) ) ;
if ( V_90 < 0 ) {
F_22 ( L_145 , V_90 ) ;
goto V_154;
}
V_360 -> V_368 = V_369 ;
V_360 -> V_370 = F_106 ( V_365 . V_371 ) * 1000 ;
if ( F_106 ( V_365 . V_81 ) & V_372 ) {
V_360 -> V_368 |= V_373 ;
V_360 -> V_374 = F_106 ( V_365 . V_375 ) ;
}
F_3 ( V_24 , L_146 ,
V_360 -> V_370 , V_360 -> V_374 ) ;
} else if ( V_92 -> V_2 -> V_98 . V_99 == V_112 ) {
if ( memcmp ( V_358 , V_134 , V_135 ) ) {
F_22 ( L_147 ,
V_358 , V_134 ) ;
V_90 = - V_376 ;
goto V_154;
}
V_90 = F_107 ( V_92 , V_377 , & V_363 ) ;
if ( V_90 ) {
F_22 ( L_148 , V_90 ) ;
goto V_154;
} else {
V_360 -> V_368 |= V_378 ;
V_360 -> V_379 . V_380 = V_363 * 5 ;
F_3 ( V_247 , L_149 , V_363 / 2 ) ;
}
if ( F_2 ( V_237 ,
& V_92 -> V_2 -> V_4 ) ) {
memset ( & V_361 , 0 , sizeof( V_361 ) ) ;
V_90 = F_108 ( V_92 , V_381 ,
& V_361 , sizeof( V_361 ) ) ;
if ( V_90 ) {
F_22 ( L_150 , V_90 ) ;
goto V_154;
} else {
V_362 = F_106 ( V_361 . V_268 ) ;
V_360 -> V_368 |= V_382 ;
V_360 -> signal = V_362 ;
F_3 ( V_247 , L_151 , V_362 ) ;
}
V_90 = F_107 ( V_92 , V_383 ,
& V_366 ) ;
if ( V_90 ) {
F_22 ( L_152 ,
V_90 ) ;
goto V_154;
} else {
V_360 -> V_384 . V_251 =
V_366 ;
F_3 ( V_247 , L_153 ,
V_366 ) ;
}
V_90 = F_107 ( V_92 , V_385 ,
& V_367 ) ;
if ( V_90 ) {
F_22 ( L_154 ,
V_90 ) ;
goto V_154;
} else {
V_360 -> V_384 . V_367 = V_367 ;
F_3 ( V_247 , L_155 ,
V_367 ) ;
}
V_360 -> V_368 |= V_386 ;
}
} else
V_90 = - V_387 ;
V_154:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_109 ( struct V_108 * V_108 , struct V_88 * V_89 ,
bool V_388 , T_4 V_389 )
{
T_4 V_390 ;
T_4 V_90 = 0 ;
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
F_3 ( V_24 , L_14 ) ;
V_125 -> V_391 = V_388 ;
if ( ! F_1 ( V_92 -> V_2 ) ) {
F_3 ( V_5 , L_156 ) ;
goto V_154;
}
V_390 = V_388 ? V_392 : V_393 ;
if ( V_92 -> V_2 -> V_98 . V_99 == V_118 ) {
F_3 ( V_5 , L_157 ) ;
V_390 = V_393 ;
}
F_3 ( V_5 , L_158 , ( V_390 ? L_159 : L_160 ) ) ;
V_90 = F_52 ( V_92 , V_394 , V_390 ) ;
if ( V_90 ) {
if ( V_90 == - V_395 )
F_22 ( L_161 ) ;
else
F_22 ( L_43 , V_90 ) ;
}
V_154:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4 F_110 ( struct V_124 * V_125 ,
struct V_396 * V_397 )
{
struct V_108 * V_108 = F_42 ( V_125 ) ;
struct V_52 * V_398 ;
struct V_399 * V_400 ;
struct V_401 * V_45 ;
struct V_21 V_20 ;
T_1 V_258 ;
T_5 V_402 ;
T_1 V_403 ;
T_1 V_404 ;
T_2 * V_405 ;
T_6 V_406 ;
T_4 V_407 ;
if ( F_106 ( V_397 -> V_408 ) > V_409 ) {
F_22 ( L_162 ) ;
return 0 ;
}
if ( ! V_397 -> V_410 ) {
V_20 . V_51 = F_111 ( V_397 -> V_164 ) ;
V_125 -> V_18 . V_411 ( & V_20 ) ;
V_397 -> V_410 = V_20 . V_29 ;
}
V_258 = V_397 -> V_410 ;
if ( V_258 <= V_412 )
V_45 = V_108 -> V_413 [ V_46 ] ;
else
V_45 = V_108 -> V_413 [ V_48 ] ;
V_402 = F_112 ( V_258 , V_45 -> V_45 ) ;
V_398 = F_113 ( V_108 , V_402 ) ;
V_403 = F_111 ( V_397 -> V_414 ) ;
V_404 = F_111 ( V_397 -> V_366 ) ;
V_405 = ( T_2 * ) V_397 + F_111 ( V_397 -> V_415 ) ;
V_406 = F_106 ( V_397 -> V_416 ) ;
V_407 = ( V_417 ) F_111 ( V_397 -> V_418 ) * 100 ;
F_3 ( V_247 , L_163 , V_397 -> V_419 ) ;
F_3 ( V_247 , L_164 , V_258 , V_402 ) ;
F_3 ( V_247 , L_165 , V_403 ) ;
F_3 ( V_247 , L_166 , V_404 ) ;
F_3 ( V_247 , L_167 , V_407 ) ;
V_400 = F_114 ( V_108 , V_398 , ( const T_2 * ) V_397 -> V_419 ,
0 , V_403 , V_404 , V_405 ,
V_406 , V_407 , V_182 ) ;
if ( ! V_400 )
return - V_183 ;
F_115 ( V_108 , V_400 ) ;
return 0 ;
}
static struct V_396 *
F_116 ( struct V_189 * V_420 , struct V_396 * V_400 )
{
if ( V_400 == NULL )
return V_420 -> V_421 ;
return (struct V_396 * ) ( ( unsigned long ) V_400 +
F_106 ( V_400 -> V_408 ) ) ;
}
static T_4 F_117 ( struct V_124 * V_125 )
{
struct V_189 * V_422 ;
struct V_396 * V_397 = NULL ;
T_4 V_90 = 0 ;
int V_163 ;
V_422 = V_125 -> V_422 ;
if ( V_422 -> V_197 != 0 &&
V_422 -> V_185 != V_423 ) {
F_22 ( L_168 ,
V_422 -> V_185 ) ;
return - V_117 ;
}
F_3 ( V_132 , L_169 , V_422 -> V_197 ) ;
for ( V_163 = 0 ; V_163 < V_422 -> V_197 ; V_163 ++ ) {
V_397 = F_116 ( V_422 , V_397 ) ;
V_90 = F_110 ( V_125 , V_397 ) ;
if ( V_90 )
break;
}
return V_90 ;
}
static T_4 F_118 ( struct V_124 * V_125 ,
struct V_88 * V_89 , const T_2 * V_134 )
{
struct V_108 * V_108 = F_42 ( V_125 ) ;
struct V_52 * V_398 ;
struct V_396 * V_397 = NULL ;
struct V_401 * V_45 ;
struct V_399 * V_400 ;
struct V_21 V_20 ;
T_2 * V_54 = NULL ;
T_4 V_90 = 0 ;
T_5 V_402 ;
T_1 V_403 ;
T_1 V_404 ;
T_2 * V_405 ;
T_6 V_406 ;
T_4 V_407 ;
F_3 ( V_24 , L_14 ) ;
V_54 = F_57 ( V_409 , V_182 ) ;
if ( V_54 == NULL ) {
V_90 = - V_183 ;
goto V_424;
}
* ( V_425 * ) V_54 = F_16 ( V_409 ) ;
V_90 = F_108 ( F_21 ( V_89 ) , V_426 ,
V_54 , V_409 ) ;
if ( V_90 ) {
F_22 ( L_170 , V_90 ) ;
goto V_424;
}
V_397 = (struct V_396 * ) ( V_54 + 4 ) ;
V_20 . V_51 = F_111 ( V_397 -> V_164 ) ;
V_125 -> V_18 . V_411 ( & V_20 ) ;
if ( V_20 . V_45 == V_47 )
V_45 = V_108 -> V_413 [ V_46 ] ;
else
V_45 = V_108 -> V_413 [ V_48 ] ;
V_402 = F_112 ( V_20 . V_29 , V_45 -> V_45 ) ;
V_398 = F_113 ( V_108 , V_402 ) ;
V_403 = F_111 ( V_397 -> V_414 ) ;
V_404 = F_111 ( V_397 -> V_366 ) ;
V_405 = ( T_2 * ) V_397 + F_111 ( V_397 -> V_415 ) ;
V_406 = F_106 ( V_397 -> V_416 ) ;
V_407 = ( V_417 ) F_111 ( V_397 -> V_418 ) * 100 ;
F_3 ( V_247 , L_171 , V_20 . V_29 , V_402 ) ;
F_3 ( V_247 , L_172 , V_403 ) ;
F_3 ( V_247 , L_71 , V_404 ) ;
F_3 ( V_247 , L_173 , V_407 ) ;
V_400 = F_114 ( V_108 , V_398 , V_134 ,
0 , V_403 , V_404 ,
V_405 , V_406 , V_407 , V_182 ) ;
if ( ! V_400 ) {
V_90 = - V_183 ;
goto V_424;
}
F_115 ( V_108 , V_400 ) ;
V_424:
F_60 ( V_54 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4 F_119 ( struct V_124 * V_125 ,
struct V_91 * V_92 )
{
struct V_235 * V_241 = F_81 ( V_92 -> V_89 ) ;
struct V_396 * V_397 ;
struct V_181 * V_174 ;
const struct V_53 * V_427 ;
T_1 V_251 ;
T_2 V_367 ;
T_6 V_250 ;
T_2 * V_62 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( F_29 ( V_92 -> V_2 ) )
return V_90 ;
V_174 = & V_241 -> V_174 ;
* ( V_425 * ) V_125 -> V_428 = F_16 ( V_429 ) ;
V_90 = F_108 ( V_92 , V_426 ,
V_125 -> V_428 , V_429 ) ;
if ( V_90 ) {
F_22 ( L_174 , V_90 ) ;
goto V_430;
}
V_397 = (struct V_396 * ) ( V_125 -> V_428 + 4 ) ;
V_90 = F_110 ( V_125 , V_397 ) ;
if ( V_90 )
goto V_430;
V_62 = ( ( T_2 * ) V_397 ) + F_111 ( V_397 -> V_415 ) ;
V_250 = F_106 ( V_397 -> V_416 ) ;
V_251 = F_111 ( V_397 -> V_366 ) ;
V_427 = F_11 ( V_62 , V_250 , V_431 ) ;
if ( V_427 )
V_367 = V_427 -> V_86 [ 1 ] ;
else {
T_5 V_432 ;
V_90 = F_95 ( V_92 , L_175 , & V_432 ) ;
if ( V_90 ) {
F_22 ( L_176 , V_90 ) ;
goto V_430;
}
V_367 = ( T_2 ) V_432 ;
}
V_430:
F_3 ( V_24 , L_137 ) ;
return V_90 ;
}
void F_120 ( struct V_124 * V_125 )
{
struct V_151 * V_191 = & V_125 -> V_151 ;
F_51 ( V_208 , & V_125 -> V_148 ) ;
if ( V_125 -> V_131 ) {
V_191 -> V_192 = V_433 ;
F_37 ( V_125 , V_191 -> V_92 , true , true ) ;
}
F_67 ( V_147 , & V_125 -> V_148 ) ;
F_67 ( V_208 , & V_125 -> V_148 ) ;
}
static void F_121 ( struct V_434 * V_435 )
{
struct V_124 * V_125 =
F_26 ( V_435 , struct V_124 ,
V_436 ) ;
F_37 ( V_125 , V_125 -> V_151 . V_92 , true , true ) ;
}
static void F_122 ( unsigned long V_86 )
{
struct V_124 * V_125 =
(struct V_124 * ) V_86 ;
if ( V_125 -> V_131 ) {
F_22 ( L_177 ) ;
F_123 ( & V_125 -> V_436 ) ;
}
}
static T_4
F_124 ( struct V_124 * V_125 ,
struct V_396 * V_400 ,
struct V_396 * V_421 )
{
struct V_21 V_437 , V_438 ;
V_437 . V_51 = F_111 ( V_400 -> V_164 ) ;
V_125 -> V_18 . V_411 ( & V_437 ) ;
V_438 . V_51 = F_111 ( V_421 -> V_164 ) ;
V_125 -> V_18 . V_411 ( & V_438 ) ;
if ( ! memcmp ( & V_421 -> V_419 , & V_400 -> V_419 , V_135 ) &&
V_437 . V_45 == V_438 . V_45 &&
V_421 -> V_170 == V_400 -> V_170 &&
! memcmp ( V_421 -> V_173 , V_400 -> V_173 , V_421 -> V_170 ) ) {
if ( ( V_400 -> V_81 & V_439 ) ==
( V_421 -> V_81 & V_439 ) ) {
V_417 V_440 = F_111 ( V_400 -> V_418 ) ;
V_417 V_441 = F_111 ( V_421 -> V_418 ) ;
if ( V_441 > V_440 )
V_400 -> V_418 = V_421 -> V_418 ;
} else if ( ( V_400 -> V_81 & V_439 ) &&
( V_421 -> V_81 & V_439 ) == 0 ) {
V_400 -> V_418 = V_421 -> V_418 ;
V_400 -> V_81 |= V_439 ;
}
return 1 ;
}
return 0 ;
}
static T_4
F_125 ( struct V_91 * V_92 ,
const struct V_442 * V_443 , void * V_86 )
{
struct V_124 * V_125 = V_92 -> V_103 -> V_444 ;
T_4 V_445 ;
struct V_446 * V_447 ;
struct V_396 * V_421 ;
struct V_396 * V_400 = NULL ;
T_5 V_448 ;
struct V_189 * V_420 ;
T_5 V_163 ;
bool V_126 ;
V_445 = V_443 -> V_445 ;
if ( ! F_2 ( V_147 , & V_125 -> V_148 ) ) {
F_22 ( L_178 , V_92 -> V_449 ) ;
return - V_387 ;
}
if ( V_445 == V_450 ) {
F_3 ( V_132 , L_179 ) ;
V_447 = (struct V_446 * ) V_86 ;
if ( ! V_447 ) {
F_22 ( L_180 ) ;
goto exit;
}
if ( F_111 ( V_447 -> V_451 ) != 1 ) {
F_22 ( L_181 ,
V_447 -> V_451 ) ;
goto exit;
}
V_421 = & V_447 -> V_421 ;
if ( F_126 ( V_125 , V_421 ) )
goto exit;
if ( ! V_125 -> V_131 ) {
F_3 ( V_132 , L_182 ) ;
goto exit;
}
V_448 = F_106 ( V_421 -> V_408 ) ;
if ( V_448 != ( F_106 ( V_447 -> V_55 ) -
V_198 ) ) {
F_22 ( L_183 ,
V_448 ) ;
goto exit;
}
if ( ! ( F_42 ( V_125 ) -> V_452 &
F_127 ( V_100 ) ) ) {
if ( F_111 ( V_421 -> V_414 ) &
V_453 ) {
F_22 ( L_184 ) ;
goto exit;
}
}
V_420 = (struct V_189 * )
V_125 -> V_151 . V_196 ;
if ( V_448 > V_454 - V_420 -> V_55 ) {
F_22 ( L_185 ) ;
goto exit;
}
for ( V_163 = 0 ; V_163 < V_420 -> V_197 ; V_163 ++ ) {
V_400 = V_400 ? (struct V_396 * )
( ( unsigned char * ) V_400 +
F_106 ( V_400 -> V_408 ) ) : V_420 -> V_421 ;
if ( F_124 ( V_125 , V_400 ,
V_421 ) )
goto exit;
}
memcpy ( & ( V_125 -> V_151 . V_196 [ V_420 -> V_55 ] ) ,
V_421 , V_448 ) ;
V_420 -> V_185 = F_106 ( V_421 -> V_185 ) ;
V_420 -> V_55 += V_448 ;
V_420 -> V_197 ++ ;
} else {
V_125 -> V_151 . V_192 = V_433 ;
if ( F_126 ( V_125 , NULL ) )
goto exit;
if ( V_125 -> V_131 ) {
V_125 -> V_422 = (struct V_189 * )
V_125 -> V_151 . V_196 ;
F_117 ( V_125 ) ;
V_126 = V_445 != V_455 ;
F_37 ( V_125 , V_92 , V_126 ,
false ) ;
} else
F_3 ( V_132 , L_186 ,
V_445 ) ;
}
exit:
return 0 ;
}
static void F_128 ( struct V_124 * V_125 )
{
F_129 ( V_125 -> V_456 , V_457 ,
F_125 ) ;
V_125 -> V_151 . V_192 = V_433 ;
F_130 ( & V_125 -> V_133 ) ;
V_125 -> V_133 . V_86 = ( unsigned long ) V_125 ;
V_125 -> V_133 . V_458 = F_122 ;
F_131 ( & V_125 -> V_436 ,
F_121 ) ;
}
static T_7 void F_132 ( T_5 V_459 )
{
if ( V_459 < 1000 / V_217 ) {
F_133 () ;
F_134 ( V_459 ) ;
} else {
F_135 ( V_459 ) ;
}
}
static T_4 F_136 ( struct V_108 * V_108 )
{
F_3 ( V_24 , L_14 ) ;
return 0 ;
}
static T_4 F_137 ( struct V_108 * V_108 ,
struct V_460 * V_461 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_88 * V_89 = F_73 ( V_125 ) ;
struct V_1 * V_2 ;
F_3 ( V_24 , L_14 ) ;
V_2 = ( (struct V_91 * ) F_21 ( V_89 ) ) -> V_2 ;
if ( ! F_1 ( V_2 ) )
goto exit;
F_138 (vif, &cfg->vif_list, list) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
continue;
F_75 ( V_2 ) ;
F_132 ( 500 ) ;
}
if ( F_2 ( V_147 , & V_125 -> V_148 ) )
F_120 ( V_125 ) ;
F_36 ( F_21 ( V_89 ) , 1 ) ;
exit:
F_3 ( V_24 , L_31 ) ;
V_125 -> V_148 = 0 ;
return 0 ;
}
static T_8 T_4
F_139 ( struct V_88 * V_89 ,
struct V_462 * V_463 , T_4 V_90 )
{
int V_163 , V_464 ;
int V_465 ;
V_465 = F_106 ( V_463 -> V_466 . V_467 ) ;
F_3 ( V_247 , L_187 , V_465 ) ;
for ( V_163 = 0 ; V_163 < V_465 ; V_163 ++ ) {
F_3 ( V_247 , L_188 , V_163 ,
& V_463 -> V_466 . V_468 [ V_163 ] . V_419 ) ;
for ( V_464 = 0 ; V_464 < V_469 ; V_464 ++ )
F_3 ( V_247 , L_189 ,
V_463 -> V_466 . V_468 [ V_163 ] . V_470 [ V_464 ] ) ;
}
if ( ! V_90 )
F_59 ( F_21 ( V_89 ) , L_190 ,
( char * ) V_463 , sizeof( * V_463 ) ) ;
return V_90 ;
}
static T_4
F_140 ( struct V_108 * V_108 , struct V_88 * V_89 ,
struct V_471 * V_472 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_473 * V_466 = & V_125 -> V_463 -> V_466 ;
T_4 V_90 = 0 ;
int V_163 ;
int V_465 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
V_465 = F_106 ( V_466 -> V_467 ) ;
for ( V_163 = 0 ; V_163 < V_465 ; V_163 ++ )
if ( ! memcmp ( V_472 -> V_134 , V_466 -> V_468 [ V_163 ] . V_419 , V_135 ) )
break;
if ( V_163 < V_474 ) {
memcpy ( V_466 -> V_468 [ V_163 ] . V_419 , V_472 -> V_134 , V_135 ) ;
memcpy ( V_466 -> V_468 [ V_163 ] . V_470 , V_472 -> V_468 , V_469 ) ;
if ( V_163 == V_465 ) {
V_465 ++ ;
V_466 -> V_467 = F_16 ( V_465 ) ;
}
} else
V_90 = - V_121 ;
F_3 ( V_247 , L_191 ,
V_466 -> V_468 [ V_465 ] . V_419 ) ;
for ( V_163 = 0 ; V_163 < V_469 ; V_163 ++ )
F_3 ( V_247 , L_189 , V_466 -> V_468 [ V_465 ] . V_470 [ V_163 ] ) ;
V_90 = F_139 ( V_89 , V_125 -> V_463 , V_90 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_141 ( struct V_108 * V_108 , struct V_88 * V_89 ,
struct V_471 * V_472 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_473 V_468 ;
T_4 V_90 = 0 ;
int V_163 , V_465 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
memcpy ( & V_468 . V_468 [ 0 ] . V_419 , V_472 -> V_134 , V_135 ) ;
memcpy ( & V_468 . V_468 [ 0 ] . V_470 , V_472 -> V_468 , V_469 ) ;
F_3 ( V_247 , L_192 ,
& V_468 . V_468 [ 0 ] . V_419 ) ;
for ( V_163 = 0 ; V_163 < V_469 ; V_163 ++ )
F_3 ( V_247 , L_189 , V_468 . V_468 [ 0 ] . V_470 [ V_163 ] ) ;
V_465 = F_106 ( V_125 -> V_463 -> V_466 . V_467 ) ;
for ( V_163 = 0 ; V_163 < V_465 ; V_163 ++ )
if ( ! memcmp
( V_472 -> V_134 , & V_125 -> V_463 -> V_466 . V_468 [ V_163 ] . V_419 ,
V_135 ) )
break;
if ( ( V_465 > 0 )
&& ( V_163 < V_465 ) ) {
memset ( & V_125 -> V_463 -> V_466 . V_468 [ V_163 ] , 0 ,
sizeof( struct V_468 ) ) ;
for (; V_163 < ( V_465 - 1 ) ; V_163 ++ ) {
memcpy ( & V_125 -> V_463 -> V_466 . V_468 [ V_163 ] . V_419 ,
& V_125 -> V_463 -> V_466 . V_468 [ V_163 + 1 ] . V_419 ,
V_135 ) ;
memcpy ( & V_125 -> V_463 -> V_466 . V_468 [ V_163 ] . V_470 ,
& V_125 -> V_463 -> V_466 . V_468 [ V_163 + 1 ] . V_470 ,
V_469 ) ;
}
V_125 -> V_463 -> V_466 . V_467 = F_16 ( V_465 - 1 ) ;
} else
V_90 = - V_121 ;
V_90 = F_139 ( V_89 , V_125 -> V_463 , V_90 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_142 ( struct V_108 * V_108 , struct V_88 * V_89 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
memset ( V_125 -> V_463 , 0 , sizeof( * V_125 -> V_463 ) ) ;
V_90 = F_139 ( V_89 , V_125 -> V_463 , V_90 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_143 ( struct V_91 * V_92 ,
const struct V_442 * V_443 , void * V_86 )
{
struct V_124 * V_125 = V_92 -> V_103 -> V_444 ;
struct V_475 * V_476 , * V_477 ;
struct V_130 * V_160 = NULL ;
struct V_201 * V_174 = NULL ;
struct V_52 * V_258 = NULL ;
struct V_108 * V_108 = F_42 ( V_125 ) ;
int V_90 = 0 ;
int V_478 = 0 ;
int V_45 = 0 ;
struct V_479 * V_480 ;
T_5 V_481 ;
T_5 V_445 ;
F_3 ( V_132 , L_14 ) ;
if ( V_443 -> V_482 == V_483 ) {
F_3 ( V_132 , L_193 ) ;
return 0 ;
}
V_480 = (struct V_479 * ) V_86 ;
V_481 = F_106 ( V_480 -> V_197 ) ;
V_445 = F_106 ( V_480 -> V_445 ) ;
F_8 ( V_445 != V_484 ) ;
F_3 ( V_132 , L_194 , V_481 ) ;
if ( V_481 > 0 ) {
int V_163 ;
V_160 = F_57 ( sizeof( * V_160 ) , V_182 ) ;
V_174 = F_144 ( V_481 , sizeof( * V_174 ) , V_182 ) ;
V_258 = F_144 ( V_481 , sizeof( * V_258 ) , V_182 ) ;
if ( ! V_160 || ! V_174 || ! V_258 ) {
V_90 = - V_183 ;
goto V_485;
}
V_160 -> V_108 = V_108 ;
V_86 += sizeof( struct V_479 ) ;
V_477 = (struct V_475 * ) V_86 ;
for ( V_163 = 0 ; V_163 < V_481 ; V_163 ++ ) {
V_476 = & V_477 [ V_163 ] ;
if ( ! V_476 ) {
F_22 ( L_195 ,
V_163 ) ;
V_90 = - V_121 ;
goto V_485;
}
F_3 ( V_132 , L_196 ,
V_476 -> V_173 , V_476 -> V_258 ) ;
memcpy ( V_174 [ V_163 ] . V_174 , V_476 -> V_173 , V_476 -> V_170 ) ;
V_174 [ V_163 ] . V_172 = V_476 -> V_170 ;
V_160 -> V_161 ++ ;
V_478 = V_476 -> V_258 ;
if ( V_478 <= V_412 )
V_45 = V_486 ;
else
V_45 = V_487 ;
V_258 [ V_163 ] . V_26 =
F_112 ( V_478 ,
V_45 ) ;
V_258 [ V_163 ] . V_45 = V_45 ;
V_258 [ V_163 ] . V_81 |= V_488 ;
V_160 -> V_168 [ V_163 ] = & V_258 [ V_163 ] ;
V_160 -> V_162 ++ ;
}
if ( V_160 -> V_161 )
V_160 -> V_171 = & V_174 [ 0 ] ;
if ( F_2 ( V_147 , & V_125 -> V_148 ) ) {
F_120 ( V_125 ) ;
}
F_51 ( V_147 , & V_125 -> V_148 ) ;
V_125 -> V_151 . V_199 = F_56 ;
V_90 = F_61 ( V_125 , V_108 , V_92 , V_160 ) ;
if ( V_90 ) {
F_67 ( V_147 , & V_125 -> V_148 ) ;
goto V_485;
}
V_125 -> V_146 = true ;
V_125 -> V_131 = V_160 ;
} else {
F_22 ( L_197 ) ;
goto V_485;
}
F_60 ( V_174 ) ;
F_60 ( V_258 ) ;
F_60 ( V_160 ) ;
return 0 ;
V_485:
F_60 ( V_174 ) ;
F_60 ( V_258 ) ;
F_60 ( V_160 ) ;
F_145 ( V_108 ) ;
return V_90 ;
}
static int F_146 ( struct V_88 * V_89 )
{
int V_489 ;
V_489 = F_24 ( F_21 ( V_89 ) , L_198 , 0 ) ;
if ( V_489 == 0 ) {
V_489 = F_59 ( F_21 ( V_89 ) , L_199 ,
NULL , 0 ) ;
}
if ( V_489 < 0 )
F_22 ( L_200 , V_489 ) ;
return V_489 ;
}
static int F_147 ( struct V_88 * V_89 )
{
struct V_490 V_491 ;
memset ( & V_491 , 0 , sizeof( V_491 ) ) ;
V_491 . V_185 = F_16 ( V_492 ) ;
V_491 . V_81 = F_17 ( 1 << V_493 ) ;
V_491 . V_494 = V_495 ;
V_491 . exp = V_496 ;
V_491 . V_497 = F_16 ( V_498 ) ;
return F_59 ( F_21 ( V_89 ) , L_201 ,
& V_491 , sizeof( V_491 ) ) ;
}
static int
F_148 ( struct V_108 * V_108 ,
struct V_88 * V_89 ,
struct V_499 * V_160 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_124 * V_125 = F_46 ( V_108 ) ;
struct V_500 V_501 ;
int V_163 ;
int V_489 = 0 ;
F_3 ( V_132 , L_202 ,
V_160 -> V_502 , V_160 -> V_161 ) ;
if ( F_2 ( V_147 , & V_125 -> V_148 ) ) {
F_22 ( L_45 , V_125 -> V_148 ) ;
return - V_158 ;
}
if ( F_2 ( V_209 , & V_125 -> V_148 ) ) {
F_22 ( L_47 ,
V_125 -> V_148 ) ;
return - V_158 ;
}
if ( ! V_160 -> V_161 || ! V_160 -> V_502 ) {
F_3 ( V_132 , L_203 ,
V_160 -> V_161 ) ;
return - V_121 ;
}
if ( V_160 -> V_161 > 0 ) {
for ( V_163 = 0 ; V_163 < V_160 -> V_161 ; V_163 ++ ) {
F_3 ( V_132 , L_204 ,
V_160 -> V_171 [ V_163 ] . V_174 ) ;
}
}
if ( V_160 -> V_502 > 0 ) {
V_489 = F_146 ( V_89 ) ;
if ( V_489 < 0 ) {
F_22 ( L_205 , V_489 ) ;
return V_489 ;
}
V_489 = F_147 ( V_89 ) ;
if ( V_489 < 0 ) {
F_22 ( L_206 , V_489 ) ;
return - V_121 ;
}
for ( V_163 = 0 ; V_163 < V_160 -> V_502 ; V_163 ++ ) {
struct V_201 * V_174 ;
T_5 V_172 ;
V_174 = & V_160 -> V_503 [ V_163 ] . V_174 ;
V_172 = V_174 -> V_172 ;
if ( ! V_172 ) {
F_22 ( L_207 ) ;
continue;
}
V_501 . V_504 = F_16 ( V_505 ) ;
V_501 . V_302 = F_16 ( V_506 ) ;
V_501 . V_245 = F_16 ( 0 ) ;
V_501 . V_152 = F_16 ( 1 ) ;
V_501 . V_81 = F_16 ( 1 << V_507 ) ;
V_501 . V_174 . V_170 = F_16 ( V_172 ) ;
memcpy ( V_501 . V_174 . V_173 , V_174 -> V_174 , V_172 ) ;
V_489 = F_59 ( V_92 , L_208 , & V_501 ,
sizeof( V_501 ) ) ;
F_3 ( V_132 , L_209 ,
V_489 == 0 ? L_210 : L_211 , V_174 -> V_174 ) ;
}
if ( F_24 ( V_92 , L_198 , 1 ) < 0 ) {
F_22 ( L_212 , V_489 ) ;
return - V_121 ;
}
} else {
return - V_121 ;
}
return 0 ;
}
static int F_149 ( struct V_108 * V_108 ,
struct V_88 * V_89 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
F_3 ( V_132 , L_213 ) ;
F_146 ( V_89 ) ;
if ( V_125 -> V_146 )
F_37 ( V_125 , F_21 ( V_89 ) , true , true ) ;
return 0 ;
}
static T_4 F_150 ( struct V_91 * V_92 )
{
T_4 V_90 ;
V_90 = F_82 ( V_92 , L_90 , 0 ) ;
if ( V_90 < 0 ) {
F_22 ( L_214 , V_90 ) ;
return V_90 ;
}
V_90 = F_82 ( V_92 , L_77 , 0 ) ;
if ( V_90 < 0 ) {
F_22 ( L_215 , V_90 ) ;
return V_90 ;
}
V_90 = F_82 ( V_92 , L_83 , V_508 ) ;
if ( V_90 < 0 ) {
F_22 ( L_216 , V_90 ) ;
return V_90 ;
}
return 0 ;
}
static bool F_151 ( T_2 * V_65 , bool V_509 )
{
if ( V_509 )
return ( memcmp ( V_65 , V_510 , V_73 ) == 0 ) ;
return ( memcmp ( V_65 , V_72 , V_73 ) == 0 ) ;
}
static T_4
F_152 ( struct V_88 * V_89 ,
const struct V_69 * V_312 ,
bool V_509 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_5 V_504 = 0 ;
T_1 V_197 ;
T_4 V_90 = 0 ;
T_4 V_60 = 0 ;
T_5 V_163 ;
T_5 V_245 ;
T_5 V_284 = 0 ;
T_5 V_285 = 0 ;
T_5 V_302 = 0 ;
T_5 V_13 ;
T_2 * V_86 ;
T_1 V_511 ;
T_5 V_512 ;
F_3 ( V_24 , L_14 ) ;
if ( V_312 == NULL )
goto exit;
V_60 = V_312 -> V_60 + V_59 ;
V_86 = ( T_2 * ) V_312 ;
V_13 = V_59 ;
if ( ! V_509 )
V_13 += V_513 ;
else
V_13 += V_514 ;
if ( V_13 + V_515 > V_60 ) {
V_90 = - V_121 ;
F_22 ( L_217 ) ;
goto exit;
}
if ( ! F_151 ( & V_86 [ V_13 ] , V_509 ) ) {
V_90 = - V_121 ;
F_22 ( L_218 ) ;
goto exit;
}
V_13 += V_73 ;
switch ( V_86 [ V_13 ] ) {
case V_516 :
V_285 = 0 ;
break;
case V_517 :
case V_518 :
V_285 = V_254 ;
break;
case V_519 :
V_285 = V_291 ;
break;
case V_520 :
V_285 = V_293 ;
break;
default:
V_90 = - V_121 ;
F_22 ( L_219 ) ;
goto exit;
}
V_13 ++ ;
V_197 = V_86 [ V_13 ] + ( V_86 [ V_13 + 1 ] << 8 ) ;
V_13 += V_521 ;
if ( V_13 + ( V_515 * V_197 ) > V_60 ) {
V_90 = - V_121 ;
F_22 ( L_220 ) ;
goto exit;
}
for ( V_163 = 0 ; V_163 < V_197 ; V_163 ++ ) {
if ( ! F_151 ( & V_86 [ V_13 ] , V_509 ) ) {
V_90 = - V_121 ;
F_22 ( L_218 ) ;
goto exit;
}
V_13 += V_73 ;
switch ( V_86 [ V_13 ] ) {
case V_516 :
break;
case V_517 :
case V_518 :
V_284 |= V_254 ;
break;
case V_519 :
V_284 |= V_291 ;
break;
case V_520 :
V_284 |= V_293 ;
break;
default:
F_22 ( L_221 ) ;
}
V_13 ++ ;
}
V_197 = V_86 [ V_13 ] + ( V_86 [ V_13 + 1 ] << 8 ) ;
V_13 += V_521 ;
if ( V_13 + ( V_515 * V_197 ) > V_60 ) {
V_90 = - V_121 ;
F_22 ( L_222 ) ;
goto exit;
}
for ( V_163 = 0 ; V_163 < V_197 ; V_163 ++ ) {
if ( ! F_151 ( & V_86 [ V_13 ] , V_509 ) ) {
V_90 = - V_121 ;
F_22 ( L_218 ) ;
goto exit;
}
V_13 += V_73 ;
switch ( V_86 [ V_13 ] ) {
case V_522 :
F_3 ( V_24 , L_223 ) ;
V_302 |= V_508 ;
break;
case V_523 :
F_3 ( V_24 , L_224 ) ;
V_509 ? ( V_302 |= V_276 ) :
( V_302 |= V_273 ) ;
break;
case V_524 :
F_3 ( V_24 , L_225 ) ;
V_509 ? ( V_302 |= V_275 ) :
( V_302 |= V_272 ) ;
break;
default:
F_22 ( L_226 ) ;
}
V_13 ++ ;
}
if ( V_509 ) {
V_512 = 1 ;
if ( ( V_13 + V_525 ) <= V_60 ) {
V_511 = V_86 [ V_13 ] + ( V_86 [ V_13 + 1 ] << 8 ) ;
if ( V_511 & V_526 )
V_512 = 0 ;
}
V_90 = F_82 ( V_92 , L_227 ,
V_512 ) ;
if ( V_90 < 0 ) {
F_22 ( L_228 , V_90 ) ;
goto exit;
}
}
V_245 = ( V_284 | V_285 | V_527 ) ;
V_90 = F_82 ( V_92 , L_90 , V_504 ) ;
if ( V_90 < 0 ) {
F_22 ( L_214 , V_90 ) ;
goto exit;
}
V_90 = F_82 ( V_92 , L_77 , V_245 ) ;
if ( V_90 < 0 ) {
F_22 ( L_215 , V_90 ) ;
goto exit;
}
V_90 = F_82 ( V_92 , L_83 , V_302 ) ;
if ( V_90 < 0 ) {
F_22 ( L_216 , V_90 ) ;
goto exit;
}
exit:
return V_90 ;
}
static T_4
F_153 ( const T_2 * V_528 , T_5 V_529 ,
struct V_530 * V_531 )
{
struct V_69 * V_532 ;
struct V_53 * V_62 ;
struct V_533 * V_534 ;
T_4 V_535 ;
V_535 = ( T_4 ) V_529 ;
memset ( V_531 , 0 , sizeof( * V_531 ) ) ;
V_62 = (struct V_53 * ) V_528 ;
while ( V_62 ) {
if ( V_62 -> V_61 != V_71 )
goto V_536;
V_532 = (struct V_69 * ) V_62 ;
if ( V_532 -> V_60 < ( V_513 - V_59 + 1 ) ) {
F_22 ( L_229 ,
V_532 -> V_60 ) ;
goto V_536;
}
if ( ! memcmp ( V_532 -> V_65 , ( T_2 * ) V_72 , V_73 ) &&
( ( V_532 -> V_537 == V_74 ) ||
( V_532 -> V_537 == V_538 ) ) ) {
F_3 ( V_24 , L_230 ) ;
goto V_536;
}
V_534 = & V_531 -> V_539 [ V_531 -> V_197 ] ;
V_534 -> V_540 = ( char * ) V_532 ;
V_534 -> V_250 = V_532 -> V_60 + V_59 ;
memcpy ( & V_534 -> V_532 , V_532 , sizeof( * V_532 ) ) ;
V_531 -> V_197 ++ ;
F_3 ( V_24 , L_231 ,
V_534 -> V_532 . V_65 [ 0 ] ,
V_534 -> V_532 . V_65 [ 1 ] ,
V_534 -> V_532 . V_65 [ 2 ] ,
V_534 -> V_532 . V_537 ) ;
if ( V_531 -> V_197 >= V_541 )
break;
V_536:
V_535 -= ( V_62 -> V_60 + V_59 ) ;
if ( V_535 <= V_59 )
V_62 = NULL ;
else
V_62 = (struct V_53 * ) ( ( ( T_2 * ) V_62 ) + V_62 -> V_60 +
V_59 ) ;
}
return 0 ;
}
static T_5
F_154 ( T_2 * V_542 , T_4 V_543 , T_2 * V_540 , T_5 V_250 , T_9 * V_544 )
{
V_425 V_545 ;
V_425 V_546 ;
strncpy ( V_542 , V_544 , V_547 - 1 ) ;
V_542 [ V_547 - 1 ] = '\0' ;
V_545 = F_16 ( 1 ) ;
memcpy ( & V_542 [ V_548 ] , & V_545 , sizeof( V_545 ) ) ;
V_546 = F_16 ( V_543 ) ;
memcpy ( & V_542 [ V_549 ] , & V_546 , sizeof( V_546 ) ) ;
memcpy ( & V_542 [ V_550 ] , V_540 , V_250 ) ;
return V_250 + V_551 ;
}
T_4 F_90 ( struct V_1 * V_2 , T_4 V_543 ,
const T_2 * V_528 , T_5 V_529 )
{
struct V_91 * V_92 ;
struct V_552 * V_553 ;
T_4 V_90 = 0 ;
T_2 * V_554 ;
T_2 * V_555 ;
T_2 * V_556 = NULL ;
int V_557 ;
T_5 * V_558 ;
T_5 V_559 = 0 ;
T_5 V_560 = 0 ;
T_5 V_561 = 0 ;
struct V_530 V_562 ;
struct V_530 V_563 ;
struct V_533 * V_564 ;
T_4 V_163 ;
T_2 * V_165 ;
int V_565 ;
if ( ! V_2 )
return - V_395 ;
V_92 = V_2 -> V_92 ;
V_553 = & V_2 -> V_553 ;
F_3 ( V_24 , L_232 , V_92 -> V_449 , V_543 ) ;
V_554 = F_57 ( V_429 , V_182 ) ;
if ( ! V_554 )
return - V_183 ;
V_555 = V_554 ;
switch ( V_543 ) {
case V_566 :
V_556 = V_553 -> V_567 ;
V_558 = & V_553 -> V_568 ;
V_557 = sizeof( V_553 -> V_567 ) ;
break;
case V_569 :
V_556 = V_553 -> V_570 ;
V_558 = & V_553 -> V_571 ;
V_557 = sizeof( V_553 -> V_570 ) ;
break;
case V_572 :
V_556 = V_553 -> V_573 ;
V_558 = & V_553 -> V_574 ;
V_557 = sizeof( V_553 -> V_573 ) ;
break;
case V_316 :
V_556 = V_553 -> V_575 ;
V_558 = & V_553 -> V_576 ;
V_557 = sizeof( V_553 -> V_575 ) ;
break;
default:
V_90 = - V_387 ;
F_22 ( L_233 ) ;
goto exit;
}
if ( V_529 > V_557 ) {
V_90 = - V_183 ;
F_22 ( L_234 ) ;
goto exit;
}
if ( V_528 && V_529 && V_555 ) {
V_165 = V_555 ;
F_153 ( V_528 , V_529 , & V_563 ) ;
for ( V_163 = 0 ; V_163 < V_563 . V_197 ; V_163 ++ ) {
V_564 = & V_563 . V_539 [ V_163 ] ;
memcpy ( V_165 + V_561 , V_564 -> V_540 ,
V_564 -> V_250 ) ;
V_561 += V_564 -> V_250 ;
}
}
if ( V_556 && * V_558 ) {
if ( V_561 && ( V_561 == * V_558 ) &&
( memcmp ( V_556 , V_555 ,
V_561 ) == 0 ) ) {
F_3 ( V_24 , L_235 ) ;
goto exit;
}
F_153 ( V_556 , * V_558 , & V_562 ) ;
for ( V_163 = 0 ; V_163 < V_562 . V_197 ; V_163 ++ ) {
V_564 = & V_562 . V_539 [ V_163 ] ;
F_3 ( V_24 , L_236 ,
V_564 -> V_532 . V_61 ,
V_564 -> V_532 . V_60 ,
V_564 -> V_532 . V_65 [ 0 ] ,
V_564 -> V_532 . V_65 [ 1 ] ,
V_564 -> V_532 . V_65 [ 2 ] ) ;
V_559 = F_154 ( V_555 , V_543 ,
V_564 -> V_540 ,
V_564 -> V_250 ,
L_237 ) ;
V_555 += V_559 ;
V_560 += V_559 ;
}
}
* V_558 = 0 ;
if ( V_556 && V_561 ) {
V_165 = V_556 ;
V_565 = V_557 ;
for ( V_163 = 0 ; V_163 < V_563 . V_197 ; V_163 ++ ) {
V_564 = & V_563 . V_539 [ V_163 ] ;
if ( V_565 < ( V_564 -> V_532 . V_60 +
V_550 ) ) {
F_22 ( L_238 ,
V_565 ) ;
break;
}
V_565 -= ( V_564 -> V_250 +
V_550 ) ;
F_3 ( V_24 , L_239 ,
V_564 -> V_532 . V_61 ,
V_564 -> V_532 . V_60 ,
V_564 -> V_532 . V_65 [ 0 ] ,
V_564 -> V_532 . V_65 [ 1 ] ,
V_564 -> V_532 . V_65 [ 2 ] ) ;
V_559 = F_154 ( V_555 , V_543 ,
V_564 -> V_540 ,
V_564 -> V_250 ,
L_240 ) ;
memcpy ( V_165 + ( * V_558 ) , V_564 -> V_540 ,
V_564 -> V_250 ) ;
* V_558 += V_564 -> V_250 ;
V_555 += V_559 ;
V_560 += V_559 ;
}
}
if ( V_560 ) {
V_90 = F_20 ( V_92 , L_241 , V_554 ,
V_560 ) ;
if ( V_90 )
F_22 ( L_242 , V_90 ) ;
}
exit:
F_60 ( V_554 ) ;
return V_90 ;
}
T_4 F_155 ( struct V_1 * V_2 )
{
T_4 V_577 [] = {
V_566 ,
V_569 ,
V_572
} ;
int V_163 ;
for ( V_163 = 0 ; V_163 < F_156 ( V_577 ) ; V_163 ++ )
F_90 ( V_2 , V_577 [ V_163 ] , NULL , 0 ) ;
memset ( & V_2 -> V_553 , 0 , sizeof( V_2 -> V_553 ) ) ;
return 0 ;
}
static T_4
F_157 ( struct V_1 * V_2 ,
struct V_578 * V_579 )
{
T_4 V_90 ;
V_90 = F_90 ( V_2 , V_572 ,
V_579 -> V_580 , V_579 -> V_581 ) ;
if ( V_90 ) {
F_22 ( L_243 ) ;
return V_90 ;
}
F_3 ( V_24 , L_244 ) ;
V_90 = F_90 ( V_2 , V_569 ,
V_579 -> V_582 ,
V_579 -> V_583 ) ;
if ( V_90 )
F_22 ( L_245 ) ;
else
F_3 ( V_24 , L_246 ) ;
return V_90 ;
}
static T_4
F_158 ( struct V_108 * V_108 , struct V_88 * V_89 ,
struct V_584 * V_585 )
{
T_4 V_415 ;
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
const struct V_53 * V_586 ;
struct V_166 V_167 ;
T_4 V_90 = - V_387 ;
const struct V_53 * V_311 ;
const struct V_69 * V_312 ;
struct V_242 V_243 ;
enum V_107 V_587 ;
struct V_588 V_589 ;
T_1 V_164 ;
F_3 ( V_24 , L_247 ,
V_585 -> V_248 . V_25 -> V_169 ,
V_585 -> V_248 . V_27 , V_585 -> V_248 . V_28 ,
V_585 -> V_251 , V_585 -> V_367 ) ;
F_3 ( V_24 , L_248 ,
V_585 -> V_174 , V_585 -> V_172 , V_585 -> V_278 ,
V_585 -> V_590 ) ;
V_587 = V_92 -> V_2 -> V_98 . V_99 ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
if ( V_585 -> V_174 == NULL || V_585 -> V_172 == 0 ) {
V_415 = V_591 + V_592 ;
V_586 = F_11 (
( T_2 * ) & V_585 -> V_579 . V_593 [ V_415 ] ,
V_585 -> V_579 . V_594 - V_415 ,
V_595 ) ;
if ( ! V_586 )
return - V_121 ;
memcpy ( V_167 . V_173 , V_586 -> V_86 , V_586 -> V_60 ) ;
V_167 . V_170 = F_16 ( V_586 -> V_60 ) ;
F_3 ( V_24 , L_249 , V_167 . V_173 ) ;
} else {
memcpy ( V_167 . V_173 , V_585 -> V_174 , V_585 -> V_172 ) ;
V_167 . V_170 = F_16 ( ( T_5 ) V_585 -> V_172 ) ;
}
F_36 ( V_92 , 0 ) ;
F_23 ( V_92 , false ) ;
V_311 = F_11 ( ( T_2 * ) V_585 -> V_579 . V_580 ,
V_585 -> V_579 . V_581 , V_315 ) ;
V_312 = F_13 ( ( T_2 * ) V_585 -> V_579 . V_580 ,
V_585 -> V_579 . V_581 ) ;
if ( ( V_312 != NULL || V_311 != NULL ) ) {
F_3 ( V_24 , L_250 ) ;
if ( V_312 != NULL ) {
V_90 = F_152 ( V_89 , V_312 , false ) ;
if ( V_90 < 0 )
goto exit;
} else {
V_90 = F_152 ( V_89 ,
(struct V_69 * ) V_311 , true ) ;
if ( V_90 < 0 )
goto exit;
}
} else {
F_3 ( V_24 , L_251 ) ;
F_150 ( V_92 ) ;
}
F_157 ( V_92 -> V_2 , & V_585 -> V_579 ) ;
V_164 = F_6 ( & V_125 -> V_18 , & V_585 -> V_248 ) ;
V_90 = F_24 ( V_92 , L_252 , V_164 ) ;
if ( V_90 < 0 ) {
F_22 ( L_253 , V_164 , V_90 ) ;
goto exit;
}
if ( V_585 -> V_251 ) {
V_90 = F_52 ( V_92 , V_255 ,
V_585 -> V_251 ) ;
if ( V_90 < 0 ) {
F_22 ( L_254 , V_90 ) ;
goto exit;
}
}
if ( V_585 -> V_367 ) {
V_90 = F_52 ( V_92 , V_596 ,
V_585 -> V_367 ) ;
if ( V_90 < 0 ) {
F_22 ( L_255 , V_90 ) ;
goto exit;
}
}
if ( V_587 == V_101 ) {
V_90 = F_52 ( V_92 , V_597 , 1 ) ;
if ( V_90 < 0 ) {
F_22 ( L_256 , V_90 ) ;
goto exit;
}
F_24 ( V_92 , L_257 , 0 ) ;
}
V_90 = F_52 ( V_92 , V_157 , 1 ) ;
if ( V_90 < 0 ) {
F_22 ( L_258 , V_90 ) ;
goto exit;
}
if ( V_587 == V_101 ) {
V_90 = F_52 ( V_92 , V_598 , 1 ) ;
if ( V_90 < 0 ) {
F_22 ( L_259 , V_90 ) ;
goto exit;
}
V_90 = F_52 ( V_92 , V_599 , 1 ) ;
if ( V_90 < 0 ) {
F_22 ( L_260 , V_90 ) ;
goto exit;
}
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
memcpy ( & V_243 . V_167 , & V_167 , sizeof( V_167 ) ) ;
V_90 = F_40 ( V_92 , V_263 ,
& V_243 , sizeof( V_243 ) ) ;
if ( V_90 < 0 ) {
F_22 ( L_261 , V_90 ) ;
goto exit;
}
F_3 ( V_24 , L_262 ) ;
} else {
V_90 = F_20 ( V_92 , L_263 , & V_167 ,
sizeof( V_167 ) ) ;
if ( V_90 < 0 ) {
F_22 ( L_264 , V_90 ) ;
goto exit;
}
V_589 . V_600 = F_16 ( V_92 -> V_449 ) ;
V_589 . V_93 = F_16 ( 1 ) ;
V_90 = F_59 ( V_92 , L_265 , & V_589 ,
sizeof( V_589 ) ) ;
if ( V_90 < 0 ) {
F_22 ( L_266 , V_90 ) ;
goto exit;
}
F_3 ( V_24 , L_267 ) ;
}
F_67 ( V_156 , & V_92 -> V_2 -> V_4 ) ;
F_51 ( V_601 , & V_92 -> V_2 -> V_4 ) ;
exit:
if ( V_90 ) {
F_36 ( V_92 , 1 ) ;
F_23 ( V_92 , true ) ;
}
return V_90 ;
}
static int F_159 ( struct V_108 * V_108 , struct V_88 * V_89 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_4 V_90 ;
struct V_588 V_589 ;
struct V_242 V_243 ;
F_3 ( V_24 , L_14 ) ;
if ( V_92 -> V_2 -> V_98 . V_99 == V_101 ) {
F_135 ( 400 ) ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_90 = F_40 ( V_92 , V_263 ,
& V_243 , sizeof( V_243 ) ) ;
if ( V_90 < 0 )
F_22 ( L_261 , V_90 ) ;
V_90 = F_52 ( V_92 , V_599 , 0 ) ;
if ( V_90 < 0 )
F_22 ( L_268 , V_90 ) ;
V_90 = F_52 ( V_92 , V_598 , 0 ) ;
if ( V_90 < 0 )
F_22 ( L_259 , V_90 ) ;
V_90 = F_52 ( V_92 , V_157 , 0 ) ;
if ( V_90 < 0 )
F_22 ( L_269 , V_90 ) ;
} else {
V_589 . V_600 = F_16 ( V_92 -> V_449 ) ;
V_589 . V_93 = F_16 ( 0 ) ;
V_90 = F_59 ( V_92 , L_265 , & V_589 ,
sizeof( V_589 ) ) ;
if ( V_90 < 0 )
F_22 ( L_266 , V_90 ) ;
}
F_36 ( V_92 , 1 ) ;
F_23 ( V_92 , true ) ;
F_51 ( V_156 , & V_92 -> V_2 -> V_4 ) ;
F_67 ( V_601 , & V_92 -> V_2 -> V_4 ) ;
return V_90 ;
}
static T_4
F_160 ( struct V_108 * V_108 , struct V_88 * V_89 ,
struct V_578 * V_602 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_4 V_90 ;
F_3 ( V_24 , L_14 ) ;
V_90 = F_157 ( V_92 -> V_2 , V_602 ) ;
return V_90 ;
}
static int
F_161 ( struct V_108 * V_108 , struct V_88 * V_89 ,
const T_2 * V_358 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_326 V_327 ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_4 V_90 ;
if ( ! V_358 )
return - V_603 ;
F_3 ( V_24 , L_270 , V_358 ) ;
if ( V_92 -> V_2 == V_125 -> V_211 . V_212 [ V_213 ] . V_2 )
V_92 = V_125 -> V_211 . V_212 [ V_214 ] . V_2 -> V_92 ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_219 ;
memcpy ( & V_327 . V_87 , V_358 , V_135 ) ;
V_327 . V_268 = F_16 ( V_604 ) ;
V_90 = F_40 ( V_92 , V_605 ,
& V_327 , sizeof( V_327 ) ) ;
if ( V_90 )
F_22 ( L_271 , V_90 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static void
F_162 ( struct V_108 * V_108 ,
struct V_97 * V_98 ,
T_1 V_606 , bool V_607 )
{
struct V_1 * V_2 ;
T_1 V_608 ;
F_3 ( V_24 , L_272 , V_606 , V_607 ) ;
V_608 = ( V_606 & V_609 ) >> 4 ;
V_2 = F_26 ( V_98 , struct V_1 , V_98 ) ;
if ( V_607 )
V_2 -> V_610 |= F_127 ( V_608 ) ;
else
V_2 -> V_610 &= ~ F_127 ( V_608 ) ;
}
static int
F_163 ( struct V_108 * V_108 , struct V_97 * V_98 ,
struct V_611 * V_111 , T_10 * V_357 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_52 * V_25 = V_111 -> V_25 ;
const T_2 * V_54 = V_111 -> V_54 ;
T_6 V_60 = V_111 -> V_60 ;
const struct V_612 * V_613 ;
struct V_1 * V_2 ;
T_4 V_90 = 0 ;
T_4 V_415 ;
T_4 V_250 ;
struct V_614 * V_615 ;
struct V_616 * V_617 ;
bool V_618 ;
T_4 V_619 ;
T_5 V_402 ;
F_3 ( V_24 , L_14 ) ;
* V_357 = 0 ;
V_613 = ( const struct V_612 * ) V_54 ;
if ( ! F_164 ( V_613 -> V_620 ) ) {
F_22 ( L_273 ) ;
return - V_387 ;
}
V_2 = F_26 ( V_98 , struct V_1 , V_98 ) ;
if ( F_165 ( V_613 -> V_620 ) ) {
V_415 = V_591 +
V_592 ;
V_250 = V_60 - V_415 ;
if ( V_2 == V_125 -> V_211 . V_212 [ V_214 ] . V_2 )
V_2 = V_125 -> V_211 . V_212 [ V_213 ] . V_2 ;
V_90 = F_90 ( V_2 ,
V_569 ,
& V_54 [ V_415 ] ,
V_250 ) ;
F_166 ( V_98 , * V_357 , V_54 , V_60 , true ,
V_182 ) ;
} else if ( F_167 ( V_613 -> V_620 ) ) {
V_617 = F_57 ( sizeof( * V_617 ) , V_182 ) ;
if ( V_617 == NULL ) {
F_22 ( L_274 ) ;
V_90 = - V_183 ;
goto exit;
}
V_615 = & V_617 -> V_615 ;
V_615 -> V_621 = F_16 ( * V_357 ) ;
memcpy ( & V_615 -> V_622 [ 0 ] , & V_613 -> V_622 [ 0 ] , V_135 ) ;
memcpy ( & V_617 -> V_134 [ 0 ] , & V_613 -> V_134 [ 0 ] , V_135 ) ;
V_615 -> V_60 = F_17 ( V_60 - V_591 ) ;
if ( V_25 )
V_402 = V_25 -> V_26 ;
else
F_107 ( V_2 -> V_92 , V_623 ,
& V_402 ) ;
V_619 = F_7 ( V_402 ) ;
V_617 -> V_258 = F_16 ( V_619 ) ;
memcpy ( V_615 -> V_86 , & V_54 [ V_591 ] ,
F_111 ( V_615 -> V_60 ) ) ;
F_3 ( V_24 , L_275 ,
* V_357 , F_111 ( V_615 -> V_60 ) , V_402 ) ;
V_618 = F_168 ( V_125 , F_73 ( V_125 ) ,
V_617 ) ;
F_166 ( V_98 , * V_357 , V_54 , V_60 , V_618 ,
V_182 ) ;
F_60 ( V_617 ) ;
} else {
F_3 ( V_24 , L_276 , V_613 -> V_620 ) ;
F_169 ( true , V_54 , V_60 , L_277 , V_60 ) ;
}
exit:
return V_90 ;
}
static int
F_170 ( struct V_108 * V_108 ,
struct V_97 * V_98 ,
T_10 V_357 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_1 * V_2 ;
int V_90 = 0 ;
F_3 ( V_24 , L_278 ) ;
V_2 = V_125 -> V_211 . V_212 [ V_213 ] . V_2 ;
if ( V_2 == NULL ) {
F_22 ( L_279 ) ;
V_90 = - V_395 ;
goto exit;
}
F_171 ( V_2 -> V_92 ) ;
exit:
return V_90 ;
}
static int F_172 ( struct V_108 * V_108 ,
struct V_97 * V_98 ,
enum V_624 V_625 ,
T_1 V_626 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_1 * V_2 ;
V_2 = F_26 ( V_98 , struct V_1 , V_98 ) ;
if ( V_625 != V_627 )
return - V_121 ;
F_51 ( V_209 , & V_125 -> V_148 ) ;
F_120 ( V_125 ) ;
return F_77 ( V_2 , V_628 , V_626 ) ;
}
static void F_173 ( struct V_108 * V_108 ,
struct V_97 * V_98 )
{
struct V_124 * V_125 = F_63 ( V_108 ) ;
struct V_1 * V_2 ;
V_2 = F_26 ( V_98 , struct V_1 , V_98 ) ;
F_77 ( V_2 , V_239 , 0 ) ;
F_67 ( V_209 , & V_125 -> V_148 ) ;
}
static T_4
F_174 ( struct V_91 * V_92 ,
const struct V_442 * V_443 , void * V_86 )
{
switch ( V_443 -> V_629 ) {
case V_630 :
F_3 ( V_24 , L_280 ) ;
break;
case V_631 :
F_3 ( V_24 , L_281 ) ;
F_175 ( V_92 -> V_103 , V_92 -> V_104 , ( T_2 * ) V_443 -> V_632 ) ;
break;
case V_633 :
F_3 ( V_24 , L_282 ) ;
F_176 ( V_92 -> V_103 , V_92 -> V_104 , ( T_2 * ) V_443 -> V_632 ) ;
break;
}
return 0 ;
}
static int F_177 ( enum V_634 V_635 )
{
int V_489 ;
switch ( V_635 ) {
case V_636 :
V_489 = V_637 ;
break;
case V_638 :
V_489 = V_639 ;
break;
case V_640 :
V_489 = V_641 ;
break;
default:
F_22 ( L_283 , V_635 ) ;
V_489 = - V_117 ;
}
return V_489 ;
}
static int F_178 ( struct V_108 * V_108 ,
struct V_88 * V_89 , const T_2 * V_642 ,
enum V_634 V_635 )
{
struct V_91 * V_92 ;
struct V_643 V_602 ;
int V_489 = 0 ;
V_489 = F_177 ( V_635 ) ;
if ( V_489 < 0 )
return V_489 ;
V_92 = F_21 ( V_89 ) ;
memset ( & V_602 , 0 , sizeof( V_602 ) ) ;
V_602 . V_94 = ( T_2 ) V_489 ;
if ( V_642 )
memcpy ( V_602 . V_87 , V_642 , V_135 ) ;
V_489 = F_59 ( V_92 , L_284 ,
& V_602 , sizeof( V_602 ) ) ;
if ( V_489 < 0 )
F_22 ( L_285 , V_489 ) ;
return V_489 ;
}
struct V_1 * F_179 ( struct V_124 * V_125 ,
enum V_107 type ,
bool V_644 )
{
struct V_1 * V_2 ;
F_3 ( V_24 , L_286 ,
sizeof( * V_2 ) ) ;
V_2 = F_57 ( sizeof( * V_2 ) , V_182 ) ;
if ( ! V_2 )
return F_31 ( - V_183 ) ;
V_2 -> V_98 . V_108 = V_125 -> V_108 ;
V_2 -> V_98 . V_99 = type ;
V_2 -> V_644 = V_644 ;
V_2 -> V_645 = - 1 ;
F_74 ( & V_2 -> V_241 ) ;
F_180 ( & V_2 -> V_420 , & V_125 -> V_646 ) ;
return V_2 ;
}
void F_181 ( struct V_1 * V_2 )
{
F_182 ( & V_2 -> V_420 ) ;
F_60 ( V_2 ) ;
}
void F_183 ( struct V_88 * V_89 )
{
struct V_1 * V_2 ;
struct V_91 * V_92 ;
V_92 = F_21 ( V_89 ) ;
V_2 = V_92 -> V_2 ;
F_181 ( V_2 ) ;
F_184 ( V_89 ) ;
}
static bool F_185 ( const struct V_442 * V_443 )
{
T_5 V_647 = V_443 -> V_482 ;
T_5 V_445 = V_443 -> V_445 ;
if ( V_647 == V_648 && V_445 == V_455 ) {
F_3 ( V_247 , L_287 ) ;
return true ;
}
return false ;
}
static bool F_186 ( const struct V_442 * V_443 )
{
T_5 V_647 = V_443 -> V_482 ;
T_1 V_81 = V_443 -> V_81 ;
if ( ( V_647 == V_649 ) || ( V_647 == V_650 ) ||
( V_647 == V_651 ) ||
( ( V_647 == V_652 ) && ( ! ( V_81 & V_653 ) ) ) ) {
F_3 ( V_247 , L_288 ) ;
return true ;
}
return false ;
}
static bool F_187 ( struct V_124 * V_125 ,
const struct V_442 * V_443 )
{
T_5 V_647 = V_443 -> V_482 ;
T_5 V_445 = V_443 -> V_445 ;
if ( V_647 == V_652 && V_445 == V_654 ) {
F_3 ( V_247 , L_289 ,
V_443 -> V_81 & V_653 ? L_290 : L_291 ) ;
return true ;
}
if ( V_647 == V_648 && V_445 != V_455 ) {
F_3 ( V_247 , L_292 ) ;
return true ;
}
return false ;
}
static void F_188 ( struct V_124 * V_125 )
{
struct V_655 * V_656 = F_189 ( V_125 ) ;
F_60 ( V_656 -> V_657 ) ;
V_656 -> V_657 = NULL ;
V_656 -> V_658 = 0 ;
F_60 ( V_656 -> V_659 ) ;
V_656 -> V_659 = NULL ;
V_656 -> V_660 = 0 ;
}
static T_4 F_190 ( struct V_124 * V_125 ,
struct V_91 * V_92 )
{
struct V_661 * V_662 ;
struct V_655 * V_656 = F_189 ( V_125 ) ;
T_5 V_663 ;
T_5 V_664 ;
T_4 V_90 = 0 ;
F_188 ( V_125 ) ;
V_90 = F_105 ( V_92 , L_293 ,
V_125 -> V_428 , V_665 ) ;
if ( V_90 ) {
F_22 ( L_294 , V_90 ) ;
return V_90 ;
}
V_662 =
(struct V_661 * ) V_125 -> V_428 ;
V_663 = F_106 ( V_662 -> V_663 ) ;
V_664 = F_106 ( V_662 -> V_664 ) ;
if ( V_663 ) {
V_90 = F_105 ( V_92 , L_295 ,
V_125 -> V_428 ,
V_665 ) ;
if ( V_90 ) {
F_22 ( L_296 , V_90 ) ;
return V_90 ;
}
V_656 -> V_658 = V_663 ;
V_656 -> V_657 =
F_191 ( V_125 -> V_428 , V_656 -> V_658 ,
V_182 ) ;
} else {
V_656 -> V_658 = 0 ;
V_656 -> V_657 = NULL ;
}
if ( V_664 ) {
V_90 = F_105 ( V_92 , L_297 ,
V_125 -> V_428 ,
V_665 ) ;
if ( V_90 ) {
F_22 ( L_298 , V_90 ) ;
return V_90 ;
}
V_656 -> V_660 = V_664 ;
V_656 -> V_659 =
F_191 ( V_125 -> V_428 , V_656 -> V_660 ,
V_182 ) ;
} else {
V_656 -> V_660 = 0 ;
V_656 -> V_659 = NULL ;
}
F_3 ( V_247 , L_299 ,
V_656 -> V_658 , V_656 -> V_660 ) ;
return V_90 ;
}
static T_4
F_192 ( struct V_124 * V_125 ,
struct V_88 * V_89 ,
const struct V_442 * V_443 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_235 * V_241 = & V_92 -> V_2 -> V_241 ;
struct V_655 * V_656 = F_189 ( V_125 ) ;
struct V_108 * V_108 = F_42 ( V_125 ) ;
struct V_52 * V_398 = NULL ;
struct V_401 * V_45 ;
struct V_396 * V_397 ;
struct V_21 V_20 ;
T_5 V_402 ;
T_4 V_90 = 0 ;
T_2 * V_54 ;
F_3 ( V_24 , L_14 ) ;
F_190 ( V_125 , V_92 ) ;
memcpy ( V_241 -> V_134 , V_443 -> V_632 , V_135 ) ;
F_119 ( V_125 , V_92 ) ;
V_54 = F_57 ( V_409 , V_182 ) ;
if ( V_54 == NULL ) {
V_90 = - V_183 ;
goto V_154;
}
* ( V_425 * ) V_54 = F_16 ( V_409 ) ;
V_90 = F_108 ( V_92 , V_426 ,
V_54 , V_409 ) ;
if ( V_90 )
goto V_154;
V_397 = (struct V_396 * ) ( V_54 + 4 ) ;
V_20 . V_51 = F_111 ( V_397 -> V_164 ) ;
V_125 -> V_18 . V_411 ( & V_20 ) ;
if ( V_20 . V_45 == V_47 )
V_45 = V_108 -> V_413 [ V_46 ] ;
else
V_45 = V_108 -> V_413 [ V_48 ] ;
V_402 = F_112 ( V_20 . V_29 , V_45 -> V_45 ) ;
V_398 = F_113 ( V_108 , V_402 ) ;
V_154:
F_60 ( V_54 ) ;
F_193 ( V_89 , V_398 , ( T_2 * ) V_241 -> V_134 ,
V_656 -> V_657 , V_656 -> V_658 ,
V_656 -> V_659 , V_656 -> V_660 , V_182 ) ;
F_3 ( V_247 , L_300 ) ;
F_51 ( V_237 , & V_92 -> V_2 -> V_4 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_194 ( struct V_124 * V_125 ,
struct V_88 * V_89 , const struct V_442 * V_443 ,
bool V_666 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_235 * V_241 = & V_92 -> V_2 -> V_241 ;
struct V_655 * V_656 = F_189 ( V_125 ) ;
F_3 ( V_24 , L_14 ) ;
if ( F_44 ( V_210 ,
& V_92 -> V_2 -> V_4 ) ) {
if ( V_666 ) {
F_190 ( V_125 , V_92 ) ;
memcpy ( V_241 -> V_134 , V_443 -> V_632 , V_135 ) ;
F_119 ( V_125 , V_92 ) ;
F_51 ( V_237 ,
& V_92 -> V_2 -> V_4 ) ;
}
F_195 ( V_89 ,
( T_2 * ) V_241 -> V_134 ,
V_656 -> V_657 ,
V_656 -> V_658 ,
V_656 -> V_659 ,
V_656 -> V_660 ,
V_666 ? V_667 :
V_668 ,
V_182 ) ;
F_3 ( V_247 , L_301 ,
V_666 ? L_302 : L_211 ) ;
}
F_3 ( V_24 , L_31 ) ;
return 0 ;
}
static T_4
F_196 ( struct V_124 * V_125 ,
struct V_88 * V_89 ,
const struct V_442 * V_443 , void * V_86 )
{
static int V_669 ;
T_5 V_647 = V_443 -> V_482 ;
T_5 V_629 = V_443 -> V_629 ;
struct V_359 V_360 ;
F_3 ( V_247 , L_303 , V_647 , V_629 ) ;
if ( V_647 == V_652 && V_629 == V_670 &&
V_89 != F_73 ( V_125 ) ) {
F_3 ( V_247 , L_304 ) ;
F_197 ( & V_125 -> V_671 ) ;
return 0 ;
}
if ( ( ( V_647 == V_672 ) || ( V_647 == V_673 ) ) &&
( V_629 == V_455 ) ) {
memset ( & V_360 , 0 , sizeof( V_360 ) ) ;
V_360 . V_368 = V_674 ;
if ( ! V_86 ) {
F_22 ( L_305 ) ;
return - V_121 ;
}
V_360 . V_675 = V_86 ;
V_360 . V_676 = V_443 -> V_677 ;
V_669 ++ ;
V_360 . V_669 = V_669 ;
F_198 ( V_89 , V_443 -> V_632 , & V_360 , V_182 ) ;
} else if ( ( V_647 == V_651 ) ||
( V_647 == V_650 ) ||
( V_647 == V_649 ) ) {
F_199 ( V_89 , V_443 -> V_632 , V_182 ) ;
}
return 0 ;
}
static T_4
F_200 ( struct V_91 * V_92 ,
const struct V_442 * V_443 , void * V_86 )
{
struct V_124 * V_125 = V_92 -> V_103 -> V_444 ;
struct V_88 * V_89 = V_92 -> V_89 ;
struct V_235 * V_241 = & V_92 -> V_2 -> V_241 ;
struct V_52 * V_25 ;
T_4 V_90 = 0 ;
if ( ( V_443 -> V_482 == V_649 ) ||
( V_443 -> V_482 == V_650 ) ||
( V_443 -> V_482 == V_651 ) ||
( ( V_443 -> V_482 == V_652 ) && ( ! V_443 -> V_81 ) ) ) {
F_176 ( V_92 -> V_103 , V_92 -> V_104 , ( T_2 * ) V_443 -> V_632 ) ;
}
if ( F_28 ( V_92 -> V_2 ) ) {
V_90 = F_196 ( V_125 , V_89 , V_443 , V_86 ) ;
} else if ( F_185 ( V_443 ) ) {
F_3 ( V_247 , L_306 ) ;
if ( F_29 ( V_92 -> V_2 ) ) {
V_25 = F_113 ( V_125 -> V_108 , V_125 -> V_258 ) ;
memcpy ( V_241 -> V_134 , V_443 -> V_632 , V_135 ) ;
F_118 ( V_125 , V_89 , V_443 -> V_632 ) ;
F_201 ( V_89 , V_443 -> V_632 , V_25 , V_182 ) ;
F_67 ( V_210 ,
& V_92 -> V_2 -> V_4 ) ;
F_51 ( V_237 ,
& V_92 -> V_2 -> V_4 ) ;
} else
F_194 ( V_125 , V_89 , V_443 , true ) ;
} else if ( F_186 ( V_443 ) ) {
F_3 ( V_247 , L_307 ) ;
if ( ! F_29 ( V_92 -> V_2 ) ) {
F_194 ( V_125 , V_89 , V_443 , false ) ;
}
F_75 ( V_92 -> V_2 ) ;
F_74 ( F_81 ( V_89 ) ) ;
if ( V_89 != F_73 ( V_125 ) )
F_197 ( & V_125 -> V_671 ) ;
} else if ( F_187 ( V_125 , V_443 ) ) {
if ( F_29 ( V_92 -> V_2 ) )
F_67 ( V_210 ,
& V_92 -> V_2 -> V_4 ) ;
else
F_194 ( V_125 , V_89 , V_443 , false ) ;
}
return V_90 ;
}
static T_4
F_202 ( struct V_91 * V_92 ,
const struct V_442 * V_443 , void * V_86 )
{
struct V_124 * V_125 = V_92 -> V_103 -> V_444 ;
T_5 V_647 = V_443 -> V_482 ;
T_5 V_445 = V_443 -> V_445 ;
if ( V_647 == V_678 && V_445 == V_455 ) {
if ( F_2 ( V_237 , & V_92 -> V_2 -> V_4 ) )
F_192 ( V_125 , V_92 -> V_89 , V_443 ) ;
else
F_194 ( V_125 , V_92 -> V_89 , V_443 , true ) ;
}
return 0 ;
}
static T_4
F_203 ( struct V_91 * V_92 ,
const struct V_442 * V_443 , void * V_86 )
{
T_1 V_81 = V_443 -> V_81 ;
enum V_679 V_680 ;
if ( V_81 & V_681 )
V_680 = V_682 ;
else
V_680 = V_683 ;
F_204 ( V_92 -> V_89 , ( T_2 * ) & V_443 -> V_632 , V_680 , - 1 ,
NULL , V_182 ) ;
return 0 ;
}
static T_4 F_205 ( struct V_91 * V_92 ,
const struct V_442 * V_443 , void * V_86 )
{
struct V_124 * V_125 = V_92 -> V_103 -> V_444 ;
struct V_684 * V_685 = (struct V_684 * ) V_86 ;
struct V_686 * V_647 = & V_125 -> V_687 ;
struct V_1 * V_2 ;
F_3 ( V_24 , L_308 ,
V_685 -> V_177 , V_685 -> V_81 , V_685 -> V_104 ,
V_685 -> V_449 ) ;
F_206 ( & V_647 -> V_688 ) ;
V_647 -> V_177 = V_685 -> V_177 ;
V_2 = V_647 -> V_2 ;
switch ( V_685 -> V_177 ) {
case V_689 :
if ( ! V_125 -> V_687 . V_2 ) {
F_207 ( & V_647 -> V_688 ) ;
return - V_690 ;
}
V_92 -> V_2 = V_2 ;
V_2 -> V_92 = V_92 ;
if ( V_92 -> V_89 ) {
V_2 -> V_98 . V_149 = V_92 -> V_89 ;
V_92 -> V_89 -> V_159 = & V_2 -> V_98 ;
F_208 ( V_92 -> V_89 , F_209 ( V_125 -> V_108 ) ) ;
}
F_207 ( & V_647 -> V_688 ) ;
F_210 ( & V_647 -> V_691 ) ;
return 0 ;
case V_692 :
F_207 ( & V_647 -> V_688 ) ;
if ( F_47 ( V_125 ) )
F_210 ( & V_647 -> V_691 ) ;
return 0 ;
case V_693 :
F_207 ( & V_647 -> V_688 ) ;
F_210 ( & V_647 -> V_691 ) ;
return 0 ;
default:
F_207 ( & V_647 -> V_688 ) ;
break;
}
return - V_121 ;
}
static void F_211 ( struct V_694 * V_229 )
{
V_229 -> V_221 = ( T_5 ) - 1 ;
V_229 -> V_220 = ( T_5 ) - 1 ;
V_229 -> V_234 = ( T_5 ) - 1 ;
V_229 -> V_232 = ( T_5 ) - 1 ;
V_229 -> V_338 = - 1 ;
}
static void F_212 ( struct V_124 * V_125 )
{
F_129 ( V_125 -> V_456 , V_652 ,
F_200 ) ;
F_129 ( V_125 -> V_456 , V_650 ,
F_200 ) ;
F_129 ( V_125 -> V_456 , V_649 ,
F_200 ) ;
F_129 ( V_125 -> V_456 , V_651 ,
F_200 ) ;
F_129 ( V_125 -> V_456 , V_672 ,
F_200 ) ;
F_129 ( V_125 -> V_456 , V_673 ,
F_200 ) ;
F_129 ( V_125 -> V_456 , V_678 ,
F_202 ) ;
F_129 ( V_125 -> V_456 , V_695 ,
F_203 ) ;
F_129 ( V_125 -> V_456 , V_648 ,
F_200 ) ;
F_129 ( V_125 -> V_456 , V_696 ,
F_143 ) ;
F_129 ( V_125 -> V_456 , V_697 ,
F_205 ) ;
F_129 ( V_125 -> V_456 , V_698 ,
V_699 ) ;
F_129 ( V_125 -> V_456 , V_700 ,
V_701 ) ;
F_129 ( V_125 -> V_456 , V_702 ,
V_703 ) ;
F_129 ( V_125 -> V_456 , V_704 ,
V_705 ) ;
F_129 ( V_125 -> V_456 , V_706 ,
V_705 ) ;
}
static void F_213 ( struct V_124 * V_125 )
{
F_60 ( V_125 -> V_229 ) ;
V_125 -> V_229 = NULL ;
F_60 ( V_125 -> V_707 ) ;
V_125 -> V_707 = NULL ;
F_60 ( V_125 -> V_428 ) ;
V_125 -> V_428 = NULL ;
F_60 ( V_125 -> V_463 ) ;
V_125 -> V_463 = NULL ;
}
static T_4 F_214 ( struct V_124 * V_125 )
{
V_125 -> V_229 = F_57 ( sizeof( * V_125 -> V_229 ) , V_182 ) ;
if ( ! V_125 -> V_229 )
goto V_708;
V_125 -> V_707 = F_57 ( V_184 , V_182 ) ;
if ( ! V_125 -> V_707 )
goto V_708;
V_125 -> V_428 = F_57 ( V_429 , V_182 ) ;
if ( ! V_125 -> V_428 )
goto V_708;
V_125 -> V_463 = F_57 ( sizeof( * V_125 -> V_463 ) , V_182 ) ;
if ( ! V_125 -> V_463 )
goto V_708;
return 0 ;
V_708:
F_213 ( V_125 ) ;
return - V_183 ;
}
static T_4 F_215 ( struct V_124 * V_125 )
{
T_4 V_90 = 0 ;
V_125 -> V_131 = NULL ;
V_125 -> V_391 = true ;
V_125 -> V_194 = true ;
V_125 -> V_709 = false ;
V_90 = F_214 ( V_125 ) ;
if ( V_90 )
return V_90 ;
F_212 ( V_125 ) ;
F_216 ( & V_125 -> V_710 ) ;
F_128 ( V_125 ) ;
F_211 ( V_125 -> V_229 ) ;
F_217 ( & V_125 -> V_671 ) ;
return V_90 ;
}
static void F_218 ( struct V_124 * V_125 )
{
V_125 -> V_709 = false ;
F_120 ( V_125 ) ;
F_213 ( V_125 ) ;
}
static void F_219 ( struct V_686 * V_647 )
{
F_220 ( & V_647 -> V_691 ) ;
F_216 ( & V_647 -> V_688 ) ;
}
static T_4
F_221 ( struct V_91 * V_92 , T_5 V_711 )
{
T_4 V_90 = 0 ;
V_425 V_712 [ 2 ] ;
V_425 V_713 [ 2 ] ;
if ( V_714 ) {
V_90 = F_24 ( V_92 , L_309 , V_711 ) ;
if ( V_90 ) {
F_22 ( L_310 , V_90 ) ;
goto V_715;
}
}
F_3 ( V_5 , L_311 ,
V_714 ? L_312 : L_313 ) ;
V_90 = F_24 ( V_92 , L_314 , ! ! ( V_714 ) ) ;
if ( V_90 ) {
F_22 ( L_315 , V_90 ) ;
goto V_715;
}
V_712 [ 0 ] = F_16 ( V_716 ) ;
V_712 [ 1 ] = F_16 ( V_717 ) ;
V_90 = F_40 ( V_92 , V_718 ,
( void * ) V_712 , sizeof( V_712 ) ) ;
if ( V_90 ) {
F_22 ( L_316 , V_90 ) ;
goto V_715;
}
V_713 [ 0 ] = F_16 ( V_719 ) ;
V_713 [ 1 ] = F_16 ( V_717 ) ;
V_90 = F_40 ( V_92 , V_720 ,
( void * ) V_713 , sizeof( V_713 ) ) ;
if ( V_90 ) {
F_22 ( L_317 , V_90 ) ;
goto V_715;
}
V_715:
return V_90 ;
}
static T_4
F_222 ( struct V_91 * V_92 , T_4 V_721 ,
T_4 V_722 , T_4 V_723 )
{
T_4 V_90 = 0 ;
V_90 = F_52 ( V_92 , V_724 ,
V_721 ) ;
if ( V_90 ) {
if ( V_90 == - V_117 )
F_3 ( V_5 , L_318 ) ;
else
F_22 ( L_319 , V_90 ) ;
goto V_725;
}
V_90 = F_52 ( V_92 , V_726 ,
V_722 ) ;
if ( V_90 ) {
if ( V_90 == - V_117 )
F_3 ( V_5 , L_320 ) ;
else
F_22 ( L_321 , V_90 ) ;
goto V_725;
}
V_90 = F_52 ( V_92 , V_727 ,
V_723 ) ;
if ( V_90 ) {
if ( V_90 == - V_117 )
F_3 ( V_5 , L_322 ) ;
else
F_22 ( L_323 , V_90 ) ;
goto V_725;
}
V_725:
return V_90 ;
}
static void F_223 ( struct V_124 * V_125 ,
struct V_728 * V_729 ,
T_5 V_730 [] )
{
T_5 V_731 = F_106 ( V_729 -> V_197 ) ;
struct V_21 V_20 ;
int V_163 ;
for ( V_163 = 0 ; V_163 < V_731 ; V_163 ++ ) {
V_20 . V_51 = ( T_1 ) F_106 ( V_729 -> V_732 [ V_163 ] ) ;
V_125 -> V_18 . V_411 ( & V_20 ) ;
if ( V_20 . V_31 != V_32 ) {
if ( V_20 . V_45 == V_49 )
break;
else
continue;
}
if ( V_20 . V_45 == V_47 )
V_730 [ 0 ] += 1 ;
else if ( V_20 . V_45 == V_49 )
V_730 [ 1 ] += 1 ;
}
}
static void F_224 ( struct V_52 * V_258 ,
struct V_21 * V_20 )
{
T_5 V_733 ;
V_733 = V_258 -> V_81 & V_488 ;
if ( V_20 -> V_35 == V_36 ) {
if ( V_733 == V_488 )
V_258 -> V_81 &= ~ V_488 ;
V_258 -> V_81 |= V_734 ;
} else {
V_258 -> V_81 &= ~ V_488 ;
if ( V_733 == V_488 )
V_258 -> V_81 |= V_735 ;
}
}
static int F_225 ( struct V_124 * V_125 ,
T_5 V_736 [] )
{
struct V_91 * V_92 = F_21 ( F_73 ( V_125 ) ) ;
struct V_401 * V_45 ;
struct V_52 * V_258 ;
struct V_108 * V_108 ;
struct V_728 * V_420 ;
struct V_21 V_20 ;
int V_90 ;
T_2 * V_737 ;
T_5 V_163 , V_464 ;
T_5 V_731 ;
T_5 V_738 ;
T_5 V_730 [ 2 ] = { 0 , 0 } ;
T_5 V_79 ;
V_737 = F_57 ( V_184 , V_182 ) ;
if ( V_737 == NULL )
return - V_183 ;
V_420 = (struct V_728 * ) V_737 ;
V_90 = F_105 ( V_92 , L_324 , V_737 ,
V_184 ) ;
if ( V_90 ) {
F_22 ( L_325 , V_90 ) ;
goto V_739;
}
F_223 ( V_125 , V_420 , V_730 ) ;
V_108 = F_42 ( V_125 ) ;
if ( V_730 [ 0 ] ) {
V_45 = F_191 ( & V_740 , sizeof( V_740 ) ,
V_182 ) ;
if ( V_45 == NULL ) {
V_90 = - V_183 ;
goto V_739;
}
V_45 -> V_168 = F_144 ( V_730 [ 0 ] , sizeof( * V_258 ) ,
V_182 ) ;
if ( V_45 -> V_168 == NULL ) {
F_60 ( V_45 ) ;
V_90 = - V_183 ;
goto V_739;
}
V_45 -> V_162 = 0 ;
V_108 -> V_413 [ V_46 ] = V_45 ;
}
if ( V_730 [ 1 ] ) {
V_45 = F_191 ( & V_741 , sizeof( V_741 ) ,
V_182 ) ;
if ( V_45 == NULL ) {
V_90 = - V_183 ;
goto V_742;
}
V_45 -> V_168 = F_144 ( V_730 [ 1 ] , sizeof( * V_258 ) ,
V_182 ) ;
if ( V_45 -> V_168 == NULL ) {
F_60 ( V_45 ) ;
V_90 = - V_183 ;
goto V_742;
}
V_45 -> V_162 = 0 ;
V_108 -> V_413 [ V_48 ] = V_45 ;
}
V_731 = F_106 ( V_420 -> V_197 ) ;
for ( V_163 = 0 ; V_163 < V_731 ; V_163 ++ ) {
V_20 . V_51 = ( T_1 ) F_106 ( V_420 -> V_732 [ V_163 ] ) ;
V_125 -> V_18 . V_411 ( & V_20 ) ;
if ( V_20 . V_45 == V_47 ) {
V_45 = V_108 -> V_413 [ V_46 ] ;
} else if ( V_20 . V_45 == V_49 ) {
V_45 = V_108 -> V_413 [ V_48 ] ;
} else {
F_22 ( L_326 , V_20 . V_51 ) ;
continue;
}
if ( ! ( V_736 [ V_45 -> V_45 ] & V_743 ) &&
V_20 . V_31 == V_34 )
continue;
if ( ! ( V_736 [ V_45 -> V_45 ] & V_744 ) &&
V_20 . V_31 == V_39 )
continue;
V_258 = V_45 -> V_168 ;
V_79 = V_45 -> V_162 ;
for ( V_464 = 0 ; V_464 < V_45 -> V_162 ; V_464 ++ ) {
if ( V_258 [ V_464 ] . V_169 == V_20 . V_29 ) {
V_79 = V_464 ;
break;
}
}
V_258 [ V_79 ] . V_26 =
F_112 ( V_20 . V_29 , V_45 -> V_45 ) ;
V_258 [ V_79 ] . V_169 = V_20 . V_29 ;
if ( V_20 . V_31 == V_39 ) {
V_258 [ V_79 ] . V_81 &= ~ V_745 ;
} else if ( V_20 . V_31 == V_34 ) {
F_224 ( & V_258 [ V_79 ] , & V_20 ) ;
} else {
V_258 [ V_79 ] . V_81 = V_488 |
V_745 ;
V_20 . V_31 = V_32 ;
V_125 -> V_18 . V_50 ( & V_20 ) ;
V_738 = V_20 . V_51 ;
V_90 = F_86 ( V_92 , L_327 ,
& V_738 ) ;
if ( ! V_90 ) {
if ( V_738 & V_746 )
V_258 [ V_79 ] . V_81 |=
( V_747 |
V_748 ) ;
if ( V_738 & V_749 )
V_258 [ V_79 ] . V_81 |=
V_748 ;
}
}
if ( V_79 == V_45 -> V_162 )
V_45 -> V_162 ++ ;
}
F_60 ( V_737 ) ;
return 0 ;
V_742:
F_60 ( V_108 -> V_413 [ V_46 ] -> V_168 ) ;
F_60 ( V_108 -> V_413 [ V_46 ] ) ;
V_108 -> V_413 [ V_46 ] = NULL ;
V_739:
F_60 ( V_737 ) ;
return V_90 ;
}
static int F_226 ( struct V_124 * V_125 )
{
struct V_91 * V_92 = F_21 ( F_73 ( V_125 ) ) ;
struct V_401 * V_45 ;
struct V_750 V_751 ;
struct V_728 * V_420 ;
T_2 * V_737 ;
T_5 V_268 ;
int V_90 ;
struct V_21 V_20 ;
T_5 V_752 ;
int V_163 , V_464 ;
V_268 = V_753 ;
V_90 = F_95 ( V_92 , L_328 , & V_268 ) ;
if ( ! V_90 ) {
V_751 . V_45 = F_16 ( V_754 ) ;
V_751 . V_736 = F_16 ( V_755 ) ;
V_90 = F_59 ( V_92 , L_328 , & V_751 ,
sizeof( V_751 ) ) ;
} else {
F_3 ( V_5 , L_329 ) ;
V_268 = V_756 ;
V_90 = F_24 ( V_92 , L_330 , V_268 ) ;
}
if ( ! V_90 ) {
V_737 = F_57 ( V_184 , V_182 ) ;
if ( V_737 == NULL )
return - V_183 ;
V_20 . V_45 = V_47 ;
V_20 . V_31 = V_34 ;
V_20 . V_35 = V_757 ;
V_20 . V_29 = 0 ;
V_125 -> V_18 . V_50 ( & V_20 ) ;
* ( V_758 * ) V_737 = F_17 ( V_20 . V_51 ) ;
V_90 = F_105 ( V_92 , L_324 , V_737 ,
V_184 ) ;
if ( V_90 ) {
F_22 ( L_325 , V_90 ) ;
F_60 ( V_737 ) ;
return V_90 ;
}
V_45 = F_42 ( V_125 ) -> V_413 [ V_46 ] ;
V_420 = (struct V_728 * ) V_737 ;
V_752 = F_106 ( V_420 -> V_197 ) ;
for ( V_163 = 0 ; V_163 < V_752 ; V_163 ++ ) {
V_20 . V_51 = ( T_1 ) F_106 ( V_420 -> V_732 [ V_163 ] ) ;
V_125 -> V_18 . V_411 ( & V_20 ) ;
if ( F_8 ( V_20 . V_45 != V_47 ) )
continue;
if ( F_8 ( V_20 . V_31 != V_34 ) )
continue;
for ( V_464 = 0 ; V_464 < V_45 -> V_162 ; V_464 ++ ) {
if ( V_45 -> V_168 [ V_464 ] . V_169 == V_20 . V_29 )
break;
}
if ( F_8 ( V_464 == V_45 -> V_162 ) )
continue;
F_224 ( & V_45 -> V_168 [ V_464 ] , & V_20 ) ;
}
F_60 ( V_737 ) ;
}
return V_90 ;
}
static void F_227 ( struct V_91 * V_92 , T_5 V_736 [] )
{
T_5 V_45 , V_759 ;
int V_90 ;
V_45 = V_754 ;
V_90 = F_95 ( V_92 , L_328 , & V_45 ) ;
if ( ! V_90 ) {
V_736 [ V_46 ] = V_45 ;
V_45 = V_753 ;
V_90 = F_95 ( V_92 , L_328 , & V_45 ) ;
if ( ! V_90 ) {
V_736 [ V_48 ] = V_45 ;
return;
}
F_8 ( 1 ) ;
return;
}
F_3 ( V_5 , L_331 ) ;
V_759 = 0 ;
V_90 = F_95 ( V_92 , L_330 , & V_759 ) ;
if ( V_90 )
V_759 = V_760 ;
switch ( V_759 ) {
case V_756 :
V_736 [ V_46 ] |= V_743 ;
case V_761 :
V_736 [ V_48 ] |= V_743 ;
case V_760 :
V_736 [ V_46 ] |= V_762 ;
V_736 [ V_48 ] |= V_762 ;
break;
default:
F_22 ( L_332 ) ;
}
}
static void F_228 ( struct V_401 * V_45 ,
T_5 V_736 [ 2 ] , T_5 V_763 )
{
V_45 -> V_764 . V_765 = true ;
if ( V_736 [ V_45 -> V_45 ] & V_743 ) {
V_45 -> V_764 . V_766 |= V_767 ;
V_45 -> V_764 . V_766 |= V_768 ;
}
V_45 -> V_764 . V_766 |= V_769 ;
V_45 -> V_764 . V_766 |= V_770 ;
V_45 -> V_764 . V_771 = V_772 ;
V_45 -> V_764 . V_773 = V_774 ;
memset ( V_45 -> V_764 . V_775 . V_776 , 0xff , V_763 ) ;
V_45 -> V_764 . V_775 . V_777 = V_778 ;
}
static V_758 F_229 ( T_5 V_763 , enum V_779 V_780 )
{
T_1 V_781 ;
int V_163 ;
for ( V_163 = 0 , V_781 = 0xFFFF ; V_163 < V_763 ; V_163 ++ )
V_781 = ( V_781 << 2 ) | V_780 ;
return F_17 ( V_781 ) ;
}
static void F_230 ( struct V_401 * V_45 ,
T_5 V_736 [ 2 ] , T_5 V_763 )
{
V_758 V_781 ;
if ( V_45 -> V_45 == V_46 )
return;
V_45 -> V_782 . V_783 = true ;
V_45 -> V_782 . V_766 |= V_784 ;
if ( V_736 [ V_45 -> V_45 ] & V_785 ) {
V_45 -> V_782 . V_766 |= V_786 ;
V_45 -> V_782 . V_766 |= V_787 ;
}
V_781 = F_229 ( V_763 , V_788 ) ;
V_45 -> V_782 . V_789 . V_790 = V_781 ;
V_45 -> V_782 . V_789 . V_791 = V_781 ;
}
static int F_231 ( struct V_108 * V_108 )
{
struct V_124 * V_125 = F_46 ( V_108 ) ;
struct V_91 * V_92 = F_21 ( F_73 ( V_125 ) ) ;
T_5 V_792 = 0 ;
T_5 V_793 = 0 ;
T_5 V_736 [ 2 ] = { V_762 , V_762 } ;
T_5 V_794 ;
T_5 V_763 ;
int V_90 ;
T_4 V_163 ;
struct V_401 * V_45 ;
( void ) F_95 ( V_92 , L_333 , & V_793 ) ;
V_90 = F_95 ( V_92 , L_334 , & V_792 ) ;
if ( V_90 ) {
F_22 ( L_335 , V_90 ) ;
} else {
F_227 ( V_92 , V_736 ) ;
}
F_3 ( V_5 , L_336 ,
V_792 , V_793 , V_736 [ V_46 ] ,
V_736 [ V_48 ] ) ;
V_90 = F_95 ( V_92 , L_337 , & V_794 ) ;
if ( V_90 ) {
F_22 ( L_338 , V_90 ) ;
V_763 = 1 ;
} else {
for ( V_763 = 0 ; V_794 ; V_763 ++ )
V_794 = V_794 & ( V_794 - 1 ) ;
}
F_3 ( V_5 , L_339 , V_763 ) ;
V_90 = F_225 ( V_125 , V_736 ) ;
if ( V_90 ) {
F_22 ( L_340 , V_90 ) ;
return V_90 ;
}
V_108 = F_42 ( V_125 ) ;
for ( V_163 = 0 ; V_163 < F_156 ( V_108 -> V_413 ) ; V_163 ++ ) {
V_45 = V_108 -> V_413 [ V_163 ] ;
if ( V_45 == NULL )
continue;
if ( V_792 )
F_228 ( V_45 , V_736 , V_763 ) ;
if ( V_793 )
F_230 ( V_45 , V_736 , V_763 ) ;
}
return 0 ;
}
static void F_232 ( struct V_108 * V_108 )
{
V_108 -> V_795 = V_796 ;
V_108 -> V_797 = V_796 ;
V_108 -> V_798 = V_799 ;
V_108 -> V_81 |= V_800 ;
}
static int F_233 ( struct V_108 * V_108 , struct V_91 * V_92 )
{
struct V_801 V_802 ;
V_108 -> V_803 = V_804 ;
V_108 -> V_805 = V_799 ;
V_108 -> V_806 = V_474 ;
V_108 -> V_452 = F_127 ( V_112 ) |
F_127 ( V_100 ) |
F_127 ( V_101 ) |
F_127 ( V_118 ) |
F_127 ( V_102 ) |
F_127 ( V_119 ) ;
V_802 = V_807 [ 0 ] ;
if ( F_234 ( V_92 , V_808 ) )
V_802 . V_809 = 2 ;
V_108 -> V_810 = F_191 ( & V_802 ,
sizeof( V_802 ) ,
V_182 ) ;
V_108 -> V_811 = F_156 ( V_807 ) ;
V_108 -> V_812 = V_813 ;
V_108 -> V_814 = V_815 ;
V_108 -> V_816 = F_156 ( V_815 ) ;
V_108 -> V_81 |= V_817 |
V_818 |
V_819 |
V_820 ;
if ( ! V_714 )
V_108 -> V_81 |= V_821 ;
V_108 -> V_822 = V_823 ;
V_108 -> V_824 = 5000 ;
F_232 ( V_108 ) ;
V_108 -> V_825 = V_826 ;
V_108 -> V_827 = V_828 - 1 ;
return F_231 ( V_108 ) ;
}
static T_4 F_235 ( struct V_124 * V_125 )
{
struct V_88 * V_89 ;
struct V_97 * V_98 ;
struct V_91 * V_92 ;
T_4 V_829 ;
T_4 V_90 = 0 ;
if ( V_125 -> V_709 )
return V_90 ;
V_89 = F_73 ( V_125 ) ;
V_98 = V_89 -> V_159 ;
V_92 = F_21 ( V_89 ) ;
F_52 ( V_92 , V_599 , 0 ) ;
F_222 ( V_92 , V_830 ,
V_831 , V_832 ) ;
V_829 = V_125 -> V_391 ? V_392 : V_393 ;
V_90 = F_52 ( V_92 , V_394 , V_829 ) ;
if ( V_90 )
goto V_833;
F_3 ( V_5 , L_341 ,
( V_829 ? L_159 : L_160 ) ) ;
V_90 = F_221 ( V_92 , V_834 ) ;
if ( V_90 )
goto V_833;
V_90 = F_49 ( V_98 -> V_108 , V_89 , V_98 -> V_99 ,
NULL , NULL ) ;
if ( V_90 )
goto V_833;
F_23 ( V_92 , true ) ;
V_125 -> V_709 = true ;
V_833:
return V_90 ;
}
static T_4 F_236 ( struct V_91 * V_92 )
{
F_51 ( V_3 , & V_92 -> V_2 -> V_4 ) ;
return F_235 ( V_92 -> V_103 -> V_444 ) ;
}
static T_4 F_237 ( struct V_91 * V_92 )
{
struct V_124 * V_125 = V_92 -> V_103 -> V_444 ;
if ( F_1 ( V_92 -> V_2 ) ) {
F_75 ( V_92 -> V_2 ) ;
F_132 ( 500 ) ;
}
F_120 ( V_125 ) ;
F_67 ( V_3 , & V_92 -> V_2 -> V_4 ) ;
return 0 ;
}
T_4 F_238 ( struct V_88 * V_89 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_124 * V_125 = V_92 -> V_103 -> V_444 ;
T_4 V_90 = 0 ;
F_206 ( & V_125 -> V_710 ) ;
V_90 = F_236 ( V_92 ) ;
F_207 ( & V_125 -> V_710 ) ;
return V_90 ;
}
T_4 F_239 ( struct V_88 * V_89 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_124 * V_125 = V_92 -> V_103 -> V_444 ;
T_4 V_90 = 0 ;
F_206 ( & V_125 -> V_710 ) ;
V_90 = F_237 ( V_92 ) ;
F_207 ( & V_125 -> V_710 ) ;
return V_90 ;
}
enum V_107 F_240 ( struct V_91 * V_92 )
{
struct V_97 * V_98 = & V_92 -> V_2 -> V_98 ;
return V_98 -> V_99 ;
}
bool F_241 ( struct V_124 * V_125 , unsigned long V_835 )
{
struct V_1 * V_2 ;
F_138 (vif, &cfg->vif_list, list) {
if ( F_2 ( V_835 , & V_2 -> V_4 ) )
return true ;
}
return false ;
}
static inline bool F_242 ( struct V_686 * V_647 ,
T_2 V_177 )
{
T_2 V_836 ;
F_206 ( & V_647 -> V_688 ) ;
V_836 = V_647 -> V_177 ;
F_207 ( & V_647 -> V_688 ) ;
return V_836 == V_177 ;
}
void F_243 ( struct V_124 * V_125 ,
struct V_1 * V_2 )
{
struct V_686 * V_647 = & V_125 -> V_687 ;
F_206 ( & V_647 -> V_688 ) ;
V_647 -> V_2 = V_2 ;
V_647 -> V_177 = 0 ;
F_207 ( & V_647 -> V_688 ) ;
}
bool F_47 ( struct V_124 * V_125 )
{
struct V_686 * V_647 = & V_125 -> V_687 ;
bool V_837 ;
F_206 ( & V_647 -> V_688 ) ;
V_837 = V_647 -> V_2 != NULL ;
F_207 ( & V_647 -> V_688 ) ;
return V_837 ;
}
int F_244 ( struct V_124 * V_125 ,
T_2 V_177 , T_11 V_389 )
{
struct V_686 * V_647 = & V_125 -> V_687 ;
return F_245 ( V_647 -> V_691 ,
F_242 ( V_647 , V_177 ) , V_389 ) ;
}
static void F_246 ( struct V_108 * V_108 )
{
F_60 ( V_108 -> V_810 ) ;
if ( V_108 -> V_413 [ V_46 ] ) {
F_60 ( V_108 -> V_413 [ V_46 ] -> V_168 ) ;
F_60 ( V_108 -> V_413 [ V_46 ] ) ;
}
if ( V_108 -> V_413 [ V_48 ] ) {
F_60 ( V_108 -> V_413 [ V_48 ] -> V_168 ) ;
F_60 ( V_108 -> V_413 [ V_48 ] ) ;
}
F_247 ( V_108 ) ;
}
struct V_124 * F_248 ( struct V_838 * V_103 ,
struct V_839 * V_840 )
{
struct V_88 * V_89 = V_103 -> V_841 [ 0 ] -> V_89 ;
struct V_124 * V_125 ;
struct V_108 * V_108 ;
struct V_1 * V_2 ;
struct V_91 * V_92 ;
T_4 V_90 = 0 ;
T_4 V_842 ;
T_1 * V_766 = NULL ;
if ( ! V_89 ) {
F_22 ( L_342 ) ;
return NULL ;
}
V_92 = F_21 ( V_89 ) ;
V_108 = F_249 ( & V_843 , sizeof( struct V_124 ) ) ;
if ( ! V_108 ) {
F_22 ( L_343 ) ;
return NULL ;
}
F_250 ( V_108 , V_840 ) ;
V_125 = F_46 ( V_108 ) ;
V_125 -> V_108 = V_108 ;
V_125 -> V_456 = V_103 ;
F_219 ( & V_125 -> V_687 ) ;
F_251 ( & V_125 -> V_646 ) ;
V_2 = F_179 ( V_125 , V_112 , false ) ;
if ( F_33 ( V_2 ) )
goto V_844;
V_2 -> V_92 = V_92 ;
V_2 -> V_98 . V_149 = V_89 ;
V_89 -> V_159 = & V_2 -> V_98 ;
F_208 ( V_89 , F_209 ( V_125 -> V_108 ) ) ;
V_90 = F_215 ( V_125 ) ;
if ( V_90 ) {
F_22 ( L_344 , V_90 ) ;
F_181 ( V_2 ) ;
goto V_844;
}
V_92 -> V_2 = V_2 ;
V_90 = F_107 ( V_92 , V_845 , & V_842 ) ;
if ( V_90 ) {
F_22 ( L_345 , V_90 ) ;
goto V_846;
}
V_125 -> V_18 . V_842 = ( T_2 ) V_842 ;
F_252 ( & V_125 -> V_18 ) ;
V_90 = F_233 ( V_108 , V_92 ) ;
if ( V_90 < 0 )
goto V_846;
F_3 ( V_5 , L_346 ) ;
V_108 -> V_847 |= V_848 ;
F_253 ( V_108 , & V_849 ) ;
if ( V_108 -> V_413 [ V_46 ] ) {
V_766 = & V_108 -> V_413 [ V_46 ] -> V_764 . V_766 ;
* V_766 |= V_768 ;
}
V_90 = F_254 ( V_108 ) ;
if ( V_90 < 0 ) {
F_22 ( L_347 , V_90 ) ;
goto V_846;
}
if ( V_766 && ( * V_766 & V_768 ) ) {
V_90 = F_226 ( V_125 ) ;
if ( ! V_90 )
V_90 = F_24 ( V_92 , L_348 ,
V_850 ) ;
else
* V_766 &= ~ V_768 ;
}
V_90 = F_255 ( V_125 ) ;
if ( V_90 ) {
F_22 ( L_349 , V_90 ) ;
goto V_851;
}
V_90 = F_256 ( V_125 ) ;
if ( V_90 ) {
F_22 ( L_350 , V_90 ) ;
F_257 ( & V_125 -> V_211 ) ;
goto V_851;
}
V_90 = F_24 ( V_92 , L_351 , 1 ) ;
if ( V_90 ) {
F_3 ( V_5 , L_352 , V_90 ) ;
V_108 -> V_81 &= ~ V_820 ;
} else {
F_129 ( V_125 -> V_456 , V_852 ,
F_174 ) ;
}
return V_125 ;
V_851:
F_258 ( V_125 -> V_108 ) ;
V_846:
F_218 ( V_125 ) ;
F_181 ( V_2 ) ;
V_844:
F_246 ( V_108 ) ;
return NULL ;
}
void F_259 ( struct V_124 * V_125 )
{
if ( ! V_125 )
return;
F_8 ( ! F_260 ( & V_125 -> V_646 ) ) ;
F_258 ( V_125 -> V_108 ) ;
F_261 ( V_125 ) ;
F_257 ( & V_125 -> V_211 ) ;
F_218 ( V_125 ) ;
F_246 ( V_125 -> V_108 ) ;
}
