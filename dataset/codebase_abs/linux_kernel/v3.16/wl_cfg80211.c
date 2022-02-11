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
static bool F_25 ( struct V_1 * V_2 )
{
enum V_97 V_98 ;
V_98 = V_2 -> V_99 . V_98 ;
return V_98 == V_100 || V_98 == V_101 ;
}
static bool F_26 ( struct V_1 * V_2 )
{
return V_2 -> V_99 . V_98 == V_102 ;
}
static struct V_103 * F_27 ( struct V_104 * V_104 ,
const char * V_105 ,
enum V_97 type ,
T_5 * V_81 ,
struct V_106 * V_107 )
{
F_3 ( V_24 , L_10 , V_105 , type ) ;
switch ( type ) {
case V_102 :
case V_108 :
case V_100 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
return F_28 ( - V_113 ) ;
case V_114 :
case V_101 :
case V_115 :
return F_29 ( V_104 , V_105 , type , V_81 , V_107 ) ;
case V_116 :
default:
return F_28 ( - V_117 ) ;
}
}
void F_30 ( struct V_91 * V_92 , int V_118 )
{
T_4 V_90 = 0 ;
if ( F_1 ( V_92 -> V_2 ) ) {
V_90 = F_24 ( V_92 , L_11 , V_118 ) ;
if ( V_90 ) {
F_22 ( L_12 ) ;
return;
}
F_3 ( V_5 , L_13 , V_118 ) ;
}
}
T_4 F_31 ( struct V_119 * V_120 ,
struct V_91 * V_92 , bool V_121 ,
bool V_122 )
{
struct V_123 V_124 ;
struct V_125 * V_126 ;
T_4 V_90 = 0 ;
F_3 ( V_127 , L_14 ) ;
V_126 = V_120 -> V_126 ;
V_120 -> V_126 = NULL ;
if ( F_32 ( & V_120 -> V_128 ) )
F_33 ( & V_120 -> V_128 ) ;
if ( V_122 ) {
F_3 ( V_127 , L_15 ) ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
memset ( V_124 . V_129 , 0xFF , V_130 ) ;
V_124 . V_131 = V_132 ;
V_124 . V_133 = 0 ;
V_124 . V_134 = F_16 ( 1 ) ;
V_124 . V_135 = F_16 ( 1 ) ;
V_124 . V_136 = F_16 ( - 1 ) ;
V_124 . V_137 = F_16 ( - 1 ) ;
V_124 . V_138 = F_16 ( - 1 ) ;
V_124 . V_139 [ 0 ] = F_17 ( - 1 ) ;
V_90 = F_34 ( V_92 , V_140 ,
& V_124 , sizeof( V_124 ) ) ;
if ( V_90 )
F_22 ( L_16 ) ;
}
F_30 ( V_92 , 1 ) ;
if ( V_120 -> V_141 ) {
F_3 ( V_127 , L_17 ) ;
V_120 -> V_141 = false ;
if ( ! V_121 )
F_35 ( F_36 ( V_120 ) ) ;
} else if ( V_126 ) {
F_3 ( V_127 , L_18 ,
V_121 ? L_19 : L_20 ) ;
F_37 ( V_126 , V_121 ) ;
}
if ( ! F_38 ( V_142 , & V_120 -> V_143 ) )
F_3 ( V_127 , L_21 ) ;
return V_90 ;
}
static
int F_39 ( struct V_104 * V_104 , struct V_103 * V_99 )
{
struct V_119 * V_120 = F_40 ( V_104 ) ;
struct V_88 * V_89 = V_99 -> V_144 ;
if ( F_41 ( V_120 ) )
return - V_145 ;
if ( V_89 ) {
if ( F_2 ( V_142 , & V_120 -> V_143 ) &&
V_120 -> V_146 . V_92 == F_21 ( V_89 ) )
F_31 ( V_120 , F_21 ( V_89 ) ,
true , true ) ;
F_24 ( F_21 ( V_89 ) , L_11 , 1 ) ;
}
switch ( V_99 -> V_98 ) {
case V_102 :
case V_108 :
case V_100 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
return - V_113 ;
case V_114 :
case V_101 :
case V_115 :
return F_42 ( V_104 , V_99 ) ;
case V_116 :
default:
return - V_117 ;
}
return - V_113 ;
}
static T_4
F_43 ( struct V_104 * V_104 , struct V_88 * V_89 ,
enum V_97 type , T_5 * V_81 ,
struct V_106 * V_107 )
{
struct V_119 * V_120 = F_40 ( V_104 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_1 * V_2 = V_92 -> V_2 ;
T_4 V_147 = 0 ;
T_4 V_148 = 0 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_22 , V_89 , type ) ;
switch ( type ) {
case V_111 :
case V_110 :
F_22 ( L_23 ,
type ) ;
return - V_113 ;
case V_102 :
V_147 = 0 ;
break;
case V_108 :
if ( ( V_2 -> V_99 . V_98 == V_114 ) ||
( V_2 -> V_99 . V_98 == V_101 ) ) {
F_3 ( V_24 , L_24 ) ;
return 0 ;
}
V_147 = 1 ;
break;
case V_100 :
case V_101 :
V_148 = 1 ;
break;
default:
V_90 = - V_117 ;
goto V_149;
}
if ( V_148 ) {
if ( type == V_101 ) {
F_3 ( V_5 , L_25 ) ;
V_90 = F_44 ( V_120 , V_150 ) ;
}
if ( ! V_90 ) {
F_45 ( V_151 , & V_2 -> V_4 ) ;
F_3 ( V_5 , L_26 ) ;
}
} else {
V_90 = F_46 ( V_92 , V_152 , V_147 ) ;
if ( V_90 ) {
F_22 ( L_27 , V_90 ) ;
V_90 = - V_153 ;
goto V_149;
}
F_3 ( V_5 , L_28 , F_26 ( V_2 ) ?
L_29 : L_30 ) ;
}
V_89 -> V_154 -> V_98 = type ;
V_149:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static void F_47 ( struct V_119 * V_120 ,
struct V_123 * V_124 ,
struct V_125 * V_155 )
{
T_5 V_156 ;
T_5 V_157 ;
T_4 V_158 ;
T_4 V_13 ;
T_1 V_159 ;
char * V_160 ;
struct V_161 V_162 ;
memset ( V_124 -> V_129 , 0xFF , V_130 ) ;
V_124 -> V_131 = V_132 ;
V_124 -> V_133 = 0 ;
V_124 -> V_134 = 0 ;
V_124 -> V_135 = F_16 ( - 1 ) ;
V_124 -> V_136 = F_16 ( - 1 ) ;
V_124 -> V_137 = F_16 ( - 1 ) ;
V_124 -> V_138 = F_16 ( - 1 ) ;
memset ( & V_124 -> V_162 , 0 , sizeof( V_124 -> V_162 ) ) ;
if ( ! V_155 )
return;
V_156 = V_155 -> V_156 ;
V_157 = V_155 -> V_157 ;
F_3 ( V_127 , L_32 ,
V_157 ) ;
if ( V_157 > 0 ) {
for ( V_158 = 0 ; V_158 < V_157 ; V_158 ++ ) {
V_159 = F_10 ( & V_120 -> V_18 ,
V_155 -> V_163 [ V_158 ] ) ;
F_3 ( V_127 , L_33 ,
V_155 -> V_163 [ V_158 ] -> V_164 , V_159 ) ;
V_124 -> V_139 [ V_158 ] = F_17 ( V_159 ) ;
}
} else {
F_3 ( V_127 , L_34 ) ;
}
F_3 ( V_127 , L_35 , V_156 ) ;
if ( V_156 > 0 ) {
V_13 = F_48 ( struct V_123 , V_139 ) +
V_157 * sizeof( T_1 ) ;
V_13 = F_49 ( V_13 , sizeof( T_5 ) ) ;
V_160 = ( char * ) V_124 + V_13 ;
for ( V_158 = 0 ; V_158 < V_156 ; V_158 ++ ) {
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
V_162 . V_165 =
F_16 ( V_155 -> V_166 [ V_158 ] . V_167 ) ;
memcpy ( V_162 . V_168 , V_155 -> V_166 [ V_158 ] . V_169 ,
V_155 -> V_166 [ V_158 ] . V_167 ) ;
if ( ! V_162 . V_165 )
F_3 ( V_127 , L_36 , V_158 ) ;
else
F_3 ( V_127 , L_37 ,
V_158 , V_162 . V_168 , V_162 . V_165 ) ;
memcpy ( V_160 , & V_162 , sizeof( V_162 ) ) ;
V_160 += sizeof( V_162 ) ;
}
} else {
F_3 ( V_127 , L_38 , V_155 -> V_166 ) ;
if ( ( V_155 -> V_166 ) && V_155 -> V_166 -> V_167 ) {
F_3 ( V_127 , L_39 ,
V_124 -> V_162 . V_168 ,
V_155 -> V_166 -> V_167 ) ;
V_124 -> V_162 . V_165 =
F_16 ( V_155 -> V_166 -> V_167 ) ;
memcpy ( & V_124 -> V_162 . V_168 , V_155 -> V_166 -> V_169 ,
V_155 -> V_166 -> V_167 ) ;
}
}
V_124 -> V_134 =
F_16 ( ( V_156 << V_170 ) |
( V_157 & V_171 ) ) ;
}
static T_4
F_50 ( struct V_119 * V_120 , struct V_91 * V_92 ,
struct V_125 * V_155 , T_1 V_172 )
{
T_4 V_173 = V_174 +
F_48 ( struct V_175 , V_124 ) ;
struct V_175 * V_107 ;
T_4 V_90 = 0 ;
F_3 ( V_127 , L_40 ) ;
if ( V_155 != NULL ) {
V_173 += sizeof( T_5 ) * ( ( V_155 -> V_157 + 1 ) / 2 ) ;
V_173 += sizeof( struct V_176 ) * V_155 -> V_156 ;
}
V_107 = F_51 ( V_173 , V_177 ) ;
if ( ! V_107 ) {
V_90 = - V_178 ;
goto exit;
}
F_52 ( V_173 + sizeof( L_41 ) >= V_179 ) ;
F_47 ( V_120 , & V_107 -> V_124 , V_155 ) ;
V_107 -> V_180 = F_16 ( V_181 ) ;
V_107 -> V_172 = F_17 ( V_172 ) ;
V_107 -> V_182 = F_17 ( 0x1234 ) ;
V_90 = F_53 ( V_92 , L_41 , V_107 , V_173 ) ;
if ( V_90 ) {
if ( V_90 == - V_145 )
F_3 ( V_5 , L_42 ) ;
else
F_22 ( L_43 , V_90 ) ;
}
F_54 ( V_107 ) ;
exit:
return V_90 ;
}
static T_4
F_55 ( struct V_119 * V_120 , struct V_104 * V_104 ,
struct V_91 * V_92 , struct V_125 * V_155 )
{
T_4 V_90 ;
T_5 V_183 ;
struct V_184 * V_185 ;
struct V_146 * V_186 = & V_120 -> V_146 ;
F_3 ( V_127 , L_14 ) ;
V_186 -> V_92 = V_92 ;
V_186 -> V_104 = V_104 ;
V_186 -> V_187 = V_188 ;
V_183 = V_120 -> V_189 ? 0 : 1 ;
V_90 = F_46 ( V_92 , V_190 ,
V_183 ) ;
if ( V_90 ) {
F_22 ( L_43 , V_90 ) ;
return V_90 ;
}
F_30 ( V_92 , 0 ) ;
V_185 = (struct V_184 * ) V_120 -> V_146 . V_191 ;
V_185 -> V_180 = 0 ;
V_185 -> V_192 = 0 ;
V_185 -> V_55 = V_193 ;
V_90 = V_186 -> V_194 ( V_120 , V_92 , V_155 , V_195 ) ;
if ( V_90 )
F_30 ( V_92 , 1 ) ;
return V_90 ;
}
static T_4
F_56 ( struct V_104 * V_104 , struct V_1 * V_2 ,
struct V_125 * V_155 ,
struct V_196 * V_197 )
{
struct V_91 * V_92 = V_2 -> V_92 ;
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_196 * V_166 ;
struct V_198 * V_199 = & V_120 -> V_200 ;
T_5 V_183 ;
bool V_201 ;
bool V_202 ;
T_4 V_90 ;
T_5 V_165 ;
F_3 ( V_127 , L_44 ) ;
if ( F_2 ( V_142 , & V_120 -> V_143 ) ) {
F_22 ( L_45 , V_120 -> V_143 ) ;
return - V_153 ;
}
if ( F_2 ( V_203 , & V_120 -> V_143 ) ) {
F_22 ( L_46 ,
V_120 -> V_143 ) ;
return - V_153 ;
}
if ( F_2 ( V_204 , & V_120 -> V_143 ) ) {
F_22 ( L_47 ,
V_120 -> V_143 ) ;
return - V_153 ;
}
if ( F_2 ( V_205 , & V_92 -> V_2 -> V_4 ) ) {
F_22 ( L_48 , V_92 -> V_2 -> V_4 ) ;
return - V_153 ;
}
if ( V_2 == V_120 -> V_206 . V_207 [ V_208 ] . V_2 )
V_2 = V_120 -> V_206 . V_207 [ V_209 ] . V_2 ;
F_58 ( & V_120 -> V_128 , V_210 +
V_211 * V_212 / 1000 ) ;
V_201 = false ;
if ( V_155 ) {
V_166 = V_155 -> V_166 ;
V_201 = true ;
} else {
V_166 = V_197 ;
}
V_120 -> V_126 = V_155 ;
F_45 ( V_142 , & V_120 -> V_143 ) ;
if ( V_201 ) {
V_120 -> V_146 . V_194 = F_50 ;
V_90 = F_59 ( V_104 , V_155 , V_2 ) ;
if ( V_90 )
goto V_213;
V_90 = F_55 ( V_120 , V_104 , V_2 -> V_92 , V_155 ) ;
if ( V_90 )
goto V_213;
} else {
F_3 ( V_127 , L_49 ,
V_166 -> V_169 , V_166 -> V_167 ) ;
memset ( & V_199 -> V_162 , 0 , sizeof( V_199 -> V_162 ) ) ;
V_165 = F_60 ( T_2 , sizeof( V_199 -> V_162 . V_168 ) , V_166 -> V_167 ) ;
V_199 -> V_162 . V_165 = F_16 ( 0 ) ;
V_202 = false ;
if ( V_165 ) {
memcpy ( V_199 -> V_162 . V_168 , V_166 -> V_169 , V_165 ) ;
V_199 -> V_162 . V_165 = F_16 ( V_165 ) ;
V_202 = true ;
} else
F_3 ( V_127 , L_50 ) ;
V_183 = V_120 -> V_189 ? 0 : 1 ;
V_90 = F_46 ( V_92 , V_190 ,
V_183 ) ;
if ( V_90 ) {
F_22 ( L_51 , V_90 ) ;
goto V_213;
}
F_30 ( V_92 , 0 ) ;
V_90 = F_34 ( V_92 , V_140 ,
& V_199 -> V_162 , sizeof( V_199 -> V_162 ) ) ;
if ( V_90 ) {
if ( V_90 == - V_145 )
F_3 ( V_5 , L_52 ,
V_199 -> V_162 . V_168 ) ;
else
F_22 ( L_53 , V_90 ) ;
F_30 ( V_92 , 1 ) ;
goto V_213;
}
}
return 0 ;
V_213:
F_61 ( V_142 , & V_120 -> V_143 ) ;
if ( F_32 ( & V_120 -> V_128 ) )
F_33 ( & V_120 -> V_128 ) ;
V_120 -> V_126 = NULL ;
return V_90 ;
}
static T_4
F_62 ( struct V_104 * V_104 , struct V_125 * V_155 )
{
struct V_1 * V_2 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
V_2 = F_63 ( V_155 -> V_99 , struct V_1 , V_99 ) ;
if ( ! F_1 ( V_2 ) )
return - V_214 ;
V_90 = F_56 ( V_104 , V_2 , V_155 , NULL ) ;
if ( V_90 )
F_22 ( L_54 , V_90 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4 F_64 ( struct V_88 * V_89 , T_5 V_215 )
{
T_4 V_90 = 0 ;
V_90 = F_24 ( F_21 ( V_89 ) , L_55 ,
V_215 ) ;
if ( V_90 )
F_22 ( L_56 , V_90 ) ;
return V_90 ;
}
static T_4 F_65 ( struct V_88 * V_89 , T_5 V_216 )
{
T_4 V_90 = 0 ;
V_90 = F_24 ( F_21 ( V_89 ) , L_57 ,
V_216 ) ;
if ( V_90 )
F_22 ( L_56 , V_90 ) ;
return V_90 ;
}
static T_4 F_66 ( struct V_88 * V_89 , T_5 V_217 , bool V_218 )
{
T_4 V_90 = 0 ;
T_5 V_219 = ( V_218 ? V_220 : V_221 ) ;
V_90 = F_46 ( F_21 ( V_89 ) , V_219 , V_217 ) ;
if ( V_90 ) {
F_22 ( L_58 , V_219 , V_90 ) ;
return V_90 ;
}
return V_90 ;
}
static T_4 F_67 ( struct V_104 * V_104 , T_5 V_222 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_88 * V_89 = F_68 ( V_120 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
if ( V_222 & V_223 &&
( V_120 -> V_224 -> V_215 != V_104 -> V_215 ) ) {
V_120 -> V_224 -> V_215 = V_104 -> V_215 ;
V_90 = F_64 ( V_89 , V_120 -> V_224 -> V_215 ) ;
if ( ! V_90 )
goto V_149;
}
if ( V_222 & V_225 &&
( V_120 -> V_224 -> V_216 != V_104 -> V_216 ) ) {
V_120 -> V_224 -> V_216 = V_104 -> V_216 ;
V_90 = F_65 ( V_89 , V_120 -> V_224 -> V_216 ) ;
if ( ! V_90 )
goto V_149;
}
if ( V_222 & V_226
&& ( V_120 -> V_224 -> V_227 != V_104 -> V_227 ) ) {
V_120 -> V_224 -> V_227 = V_104 -> V_227 ;
V_90 = F_66 ( V_89 , V_120 -> V_224 -> V_227 , true ) ;
if ( ! V_90 )
goto V_149;
}
if ( V_222 & V_228
&& ( V_120 -> V_224 -> V_229 != V_104 -> V_229 ) ) {
V_120 -> V_224 -> V_229 = V_104 -> V_229 ;
V_90 = F_66 ( V_89 , V_120 -> V_224 -> V_229 , false ) ;
if ( ! V_90 )
goto V_149;
}
V_149:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static void F_69 ( struct V_230 * V_231 )
{
memset ( V_231 , 0 , sizeof( * V_231 ) ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_119 * V_120 = F_57 ( V_2 -> V_99 . V_104 ) ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( F_2 ( V_232 , & V_2 -> V_4 ) ) {
F_3 ( V_5 , L_59 ) ;
V_90 = F_34 ( V_2 -> V_92 ,
V_233 , NULL , 0 ) ;
if ( V_90 ) {
F_22 ( L_60 , V_90 ) ;
}
F_61 ( V_232 , & V_2 -> V_4 ) ;
F_71 ( V_2 -> V_99 . V_144 , 0 , NULL , 0 , V_177 ) ;
}
F_61 ( V_205 , & V_2 -> V_4 ) ;
F_61 ( V_204 , & V_120 -> V_143 ) ;
F_72 ( V_2 , V_234 , 0 ) ;
F_3 ( V_24 , L_31 ) ;
}
static T_4
F_73 ( struct V_104 * V_104 , struct V_88 * V_89 ,
struct V_235 * V_107 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_230 * V_236 = & V_92 -> V_2 -> V_236 ;
struct V_237 V_238 ;
T_6 V_239 = 0 ;
T_4 V_90 = 0 ;
T_4 V_240 = 0 ;
T_4 V_241 ;
T_1 V_159 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
if ( V_107 -> V_169 )
F_3 ( V_242 , L_61 , V_107 -> V_169 ) ;
else {
F_3 ( V_242 , L_62 ) ;
return - V_113 ;
}
F_45 ( V_205 , & V_92 -> V_2 -> V_4 ) ;
if ( V_107 -> V_129 )
F_3 ( V_242 , L_63 , V_107 -> V_129 ) ;
else
F_3 ( V_242 , L_64 ) ;
if ( V_107 -> V_243 . V_25 )
F_3 ( V_242 , L_65 ,
V_107 -> V_243 . V_25 -> V_26 ) ;
else
F_3 ( V_242 , L_66 ) ;
if ( V_107 -> V_244 )
F_3 ( V_242 , L_67 ) ;
else
F_3 ( V_242 , L_68 ) ;
if ( V_107 -> V_62 && V_107 -> V_245 )
F_3 ( V_242 , L_69 , V_107 -> V_245 ) ;
else
F_3 ( V_242 , L_70 ) ;
if ( V_107 -> V_246 )
F_3 ( V_242 , L_71 ,
V_107 -> V_246 ) ;
else
F_3 ( V_242 , L_72 ) ;
if ( V_107 -> V_247 )
F_3 ( V_242 , L_73 , V_107 -> V_247 ) ;
else
F_3 ( V_242 , L_74 ) ;
if ( V_107 -> V_248 )
F_3 ( V_242 , L_75 ) ;
else
F_3 ( V_242 , L_76 ) ;
if ( V_107 -> V_248 )
V_240 |= V_249 ;
V_90 = F_24 ( V_92 , L_77 , V_240 ) ;
if ( V_90 ) {
F_22 ( L_78 , V_90 ) ;
goto V_149;
}
if ( V_107 -> V_246 )
V_241 = V_107 -> V_246 ;
else
V_241 = 100 ;
V_90 = F_46 ( V_92 , V_250 , V_241 ) ;
if ( V_90 ) {
F_22 ( L_79 , V_90 ) ;
goto V_149;
}
memset ( & V_238 , 0 , sizeof( struct V_237 ) ) ;
V_236 -> V_169 . V_165 = F_60 ( T_5 , V_107 -> V_167 , 32 ) ;
memcpy ( V_236 -> V_169 . V_168 , V_107 -> V_169 , V_236 -> V_169 . V_165 ) ;
memcpy ( V_238 . V_162 . V_168 , V_107 -> V_169 , V_236 -> V_169 . V_165 ) ;
V_238 . V_162 . V_165 = F_16 ( V_236 -> V_169 . V_165 ) ;
V_239 = sizeof( V_238 . V_162 ) ;
if ( V_107 -> V_129 ) {
memcpy ( V_238 . V_124 . V_129 , V_107 -> V_129 , V_130 ) ;
V_239 = sizeof( V_238 . V_162 ) +
V_251 ;
memcpy ( V_236 -> V_129 , V_107 -> V_129 , V_130 ) ;
} else {
memset ( V_238 . V_124 . V_129 , 0xFF , V_130 ) ;
memset ( V_236 -> V_129 , 0 , V_130 ) ;
}
if ( V_107 -> V_243 . V_25 ) {
T_5 V_252 ;
V_120 -> V_253 =
F_7 (
V_107 -> V_243 . V_25 -> V_26 ) ;
if ( V_107 -> V_244 ) {
V_159 = F_6 ( & V_120 -> V_18 ,
& V_107 -> V_243 ) ;
V_238 . V_124 . V_254 [ 0 ] =
F_17 ( V_159 ) ;
V_238 . V_124 . V_255 = F_16 ( 1 ) ;
V_239 += sizeof( V_238 . V_124 ) ;
}
V_252 = V_120 -> V_253 ;
V_90 = F_46 ( V_92 , V_256 ,
V_252 ) ;
if ( V_90 ) {
F_22 ( L_80 , V_90 ) ;
goto V_149;
}
} else
V_120 -> V_253 = 0 ;
V_120 -> V_257 = false ;
V_90 = F_34 ( V_92 , V_258 ,
& V_238 , V_239 ) ;
if ( V_90 ) {
F_22 ( L_81 , V_90 ) ;
goto V_149;
}
V_149:
if ( V_90 )
F_61 ( V_205 , & V_92 -> V_2 -> V_4 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_74 ( struct V_104 * V_104 , struct V_88 * V_89 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
F_70 ( V_92 -> V_2 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4 F_75 ( struct V_88 * V_89 ,
struct V_259 * V_260 )
{
struct V_230 * V_236 = F_76 ( V_89 ) ;
struct V_261 * V_262 ;
T_4 V_263 = 0 ;
T_4 V_90 = 0 ;
if ( V_260 -> V_264 . V_265 & V_266 )
V_263 = V_267 | V_268 ;
else if ( V_260 -> V_264 . V_265 & V_269 )
V_263 = V_270 | V_271 ;
else
V_263 = V_272 ;
F_3 ( V_242 , L_82 , V_263 ) ;
V_90 = F_77 ( F_21 ( V_89 ) , L_83 , V_263 ) ;
if ( V_90 ) {
F_22 ( L_84 , V_90 ) ;
return V_90 ;
}
V_262 = & V_236 -> V_262 ;
V_262 -> V_265 = V_260 -> V_264 . V_265 ;
return V_90 ;
}
static T_4 F_78 ( struct V_88 * V_89 ,
struct V_259 * V_260 )
{
struct V_230 * V_236 = F_76 ( V_89 ) ;
struct V_261 * V_262 ;
T_4 V_263 = 0 ;
T_4 V_90 = 0 ;
switch ( V_260 -> V_273 ) {
case V_274 :
V_263 = 0 ;
F_3 ( V_242 , L_85 ) ;
break;
case V_275 :
V_263 = 1 ;
F_3 ( V_242 , L_86 ) ;
break;
case V_276 :
V_263 = 2 ;
F_3 ( V_242 , L_87 ) ;
break;
case V_277 :
F_3 ( V_242 , L_88 ) ;
default:
V_263 = 2 ;
F_22 ( L_89 , V_260 -> V_273 ) ;
break;
}
V_90 = F_77 ( F_21 ( V_89 ) , L_90 , V_263 ) ;
if ( V_90 ) {
F_22 ( L_91 , V_90 ) ;
return V_90 ;
}
V_262 = & V_236 -> V_262 ;
V_262 -> V_273 = V_260 -> V_273 ;
return V_90 ;
}
static T_4
F_79 ( struct V_88 * V_89 ,
struct V_259 * V_260 , bool V_278 )
{
struct V_230 * V_236 = F_76 ( V_89 ) ;
struct V_261 * V_262 ;
T_4 V_279 = 0 ;
T_4 V_280 = 0 ;
T_4 V_240 ;
T_4 V_90 = 0 ;
if ( V_260 -> V_264 . V_281 ) {
switch ( V_260 -> V_264 . V_282 [ 0 ] ) {
case V_283 :
case V_284 :
V_279 = V_249 ;
break;
case V_285 :
V_279 = V_286 ;
break;
case V_287 :
V_279 = V_288 ;
break;
case V_289 :
V_279 = V_288 ;
break;
default:
F_22 ( L_92 ,
V_260 -> V_264 . V_282 [ 0 ] ) ;
return - V_117 ;
}
}
if ( V_260 -> V_264 . V_290 ) {
switch ( V_260 -> V_264 . V_290 ) {
case V_283 :
case V_284 :
V_280 = V_249 ;
break;
case V_285 :
V_280 = V_286 ;
break;
case V_287 :
V_280 = V_288 ;
break;
case V_289 :
V_280 = V_288 ;
break;
default:
F_22 ( L_93 ,
V_260 -> V_264 . V_290 ) ;
return - V_117 ;
}
}
F_3 ( V_242 , L_94 , V_279 , V_280 ) ;
if ( F_14 ( V_260 -> V_62 , V_260 -> V_245 ) && ! V_279 && ! V_280 &&
V_260 -> V_248 )
V_279 = V_288 ;
if ( V_278 )
V_240 = V_279 | V_280 | V_291 ;
else
V_240 = V_279 | V_280 ;
V_90 = F_77 ( F_21 ( V_89 ) , L_77 , V_240 ) ;
if ( V_90 ) {
F_22 ( L_43 , V_90 ) ;
return V_90 ;
}
V_262 = & V_236 -> V_262 ;
V_262 -> V_292 = V_260 -> V_264 . V_282 [ 0 ] ;
V_262 -> V_290 = V_260 -> V_264 . V_290 ;
return V_90 ;
}
static T_4
F_80 ( struct V_88 * V_89 , struct V_259 * V_260 )
{
struct V_230 * V_236 = F_76 ( V_89 ) ;
struct V_261 * V_262 ;
T_4 V_263 = 0 ;
T_4 V_90 = 0 ;
if ( V_260 -> V_264 . V_293 ) {
V_90 = F_81 ( F_21 ( V_89 ) ,
L_83 , & V_263 ) ;
if ( V_90 ) {
F_22 ( L_95 , V_90 ) ;
return V_90 ;
}
if ( V_263 & ( V_267 | V_268 ) ) {
switch ( V_260 -> V_264 . V_294 [ 0 ] ) {
case V_295 :
V_263 = V_268 ;
break;
case V_296 :
V_263 = V_267 ;
break;
default:
F_22 ( L_93 ,
V_260 -> V_264 . V_290 ) ;
return - V_117 ;
}
} else if ( V_263 & ( V_270 | V_271 ) ) {
switch ( V_260 -> V_264 . V_294 [ 0 ] ) {
case V_295 :
V_263 = V_271 ;
break;
case V_296 :
V_263 = V_270 ;
break;
default:
F_22 ( L_93 ,
V_260 -> V_264 . V_290 ) ;
return - V_117 ;
}
}
F_3 ( V_242 , L_96 , V_263 ) ;
V_90 = F_77 ( F_21 ( V_89 ) ,
L_83 , V_263 ) ;
if ( V_90 ) {
F_22 ( L_97 , V_90 ) ;
return V_90 ;
}
}
V_262 = & V_236 -> V_262 ;
V_262 -> V_297 = V_260 -> V_264 . V_294 [ 0 ] ;
return V_90 ;
}
static T_4
F_82 ( struct V_88 * V_89 ,
struct V_259 * V_260 )
{
struct V_230 * V_236 = F_76 ( V_89 ) ;
struct V_261 * V_262 ;
struct V_76 V_56 ;
T_4 V_263 ;
T_4 V_90 = 0 ;
F_3 ( V_242 , L_98 , V_260 -> V_298 ) ;
if ( V_260 -> V_298 == 0 )
return 0 ;
V_262 = & V_236 -> V_262 ;
F_3 ( V_242 , L_99 ,
V_262 -> V_265 , V_262 -> V_292 ) ;
if ( V_262 -> V_265 & ( V_266 | V_269 ) )
return 0 ;
if ( ! ( V_262 -> V_292 &
( V_283 | V_284 ) ) )
return 0 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_60 = ( T_5 ) V_260 -> V_298 ;
V_56 . V_79 = ( T_5 ) V_260 -> V_299 ;
if ( V_56 . V_60 > sizeof( V_56 . V_86 ) ) {
F_22 ( L_100 , V_56 . V_60 ) ;
return - V_117 ;
}
memcpy ( V_56 . V_86 , V_260 -> V_56 , V_56 . V_60 ) ;
V_56 . V_81 = V_300 ;
switch ( V_262 -> V_292 ) {
case V_283 :
V_56 . V_80 = V_301 ;
break;
case V_284 :
V_56 . V_80 = V_302 ;
break;
default:
F_22 ( L_101 ,
V_260 -> V_264 . V_282 [ 0 ] ) ;
return - V_117 ;
}
F_3 ( V_242 , L_102 ,
V_56 . V_60 , V_56 . V_79 , V_56 . V_80 ) ;
F_3 ( V_242 , L_103 , V_56 . V_86 ) ;
V_90 = F_18 ( V_89 , & V_56 ) ;
if ( V_90 )
return V_90 ;
if ( V_262 -> V_273 == V_275 ) {
F_3 ( V_242 , L_104 ) ;
V_263 = V_303 ;
V_90 = F_77 ( F_21 ( V_89 ) , L_90 , V_263 ) ;
if ( V_90 )
F_22 ( L_91 , V_90 ) ;
}
return V_90 ;
}
static
enum V_304 F_83 ( struct V_91 * V_92 ,
enum V_304 type )
{
T_5 V_305 ;
if ( type == V_276 ) {
V_305 = F_84 ( V_92 ) >> 4 ;
switch ( V_305 ) {
case 43236 :
F_3 ( V_242 , L_105 ) ;
return V_274 ;
default:
break;
}
}
return type ;
}
static T_4
F_85 ( struct V_104 * V_104 , struct V_88 * V_89 ,
struct V_259 * V_260 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_230 * V_236 = & V_92 -> V_2 -> V_236 ;
struct V_52 * V_25 = V_260 -> V_253 ;
struct V_237 V_238 ;
T_6 V_239 ;
const struct V_53 * V_306 ;
const struct V_69 * V_307 ;
const void * V_62 ;
T_5 V_245 ;
struct V_308 * V_309 ;
T_1 V_159 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
if ( ! V_260 -> V_169 ) {
F_22 ( L_106 ) ;
return - V_113 ;
}
if ( V_92 -> V_2 == V_120 -> V_206 . V_207 [ V_209 ] . V_2 ) {
V_62 = NULL ;
V_245 = 0 ;
V_307 = F_13 ( ( T_2 * ) V_260 -> V_62 , V_260 -> V_245 ) ;
if ( V_307 ) {
V_62 = V_307 ;
V_245 = V_307 -> V_60 + V_59 ;
} else {
V_306 = F_11 ( ( const T_2 * ) V_260 -> V_62 ,
V_260 -> V_245 ,
V_310 ) ;
if ( V_306 ) {
V_62 = V_306 ;
V_245 = V_306 -> V_60 + V_59 ;
}
}
F_53 ( V_92 , L_107 , V_62 , V_245 ) ;
}
V_90 = F_86 ( V_92 -> V_2 , V_311 ,
V_260 -> V_62 , V_260 -> V_245 ) ;
if ( V_90 )
F_22 ( L_108 ) ;
else
F_3 ( V_24 , L_109 ) ;
F_45 ( V_205 , & V_92 -> V_2 -> V_4 ) ;
if ( V_25 ) {
V_120 -> V_253 =
F_7 ( V_25 -> V_26 ) ;
V_159 = F_10 ( & V_120 -> V_18 , V_25 ) ;
F_3 ( V_242 , L_110 ,
V_120 -> V_253 , V_25 -> V_26 , V_159 ) ;
} else {
V_120 -> V_253 = 0 ;
V_159 = 0 ;
}
F_3 ( V_5 , L_111 , V_260 -> V_62 , V_260 -> V_245 ) ;
V_90 = F_75 ( V_89 , V_260 ) ;
if ( V_90 ) {
F_22 ( L_112 , V_90 ) ;
goto V_149;
}
V_260 -> V_273 = F_83 ( V_92 , V_260 -> V_273 ) ;
V_90 = F_78 ( V_89 , V_260 ) ;
if ( V_90 ) {
F_22 ( L_113 , V_90 ) ;
goto V_149;
}
V_90 = F_79 ( V_89 , V_260 , V_260 -> V_278 == V_312 ) ;
if ( V_90 ) {
F_22 ( L_114 , V_90 ) ;
goto V_149;
}
V_90 = F_80 ( V_89 , V_260 ) ;
if ( V_90 ) {
F_22 ( L_115 , V_90 ) ;
goto V_149;
}
V_90 = F_82 ( V_89 , V_260 ) ;
if ( V_90 ) {
F_22 ( L_116 , V_90 ) ;
goto V_149;
}
V_236 -> V_169 . V_165 = F_60 ( T_5 , ( T_5 ) sizeof( V_236 -> V_169 . V_168 ) ,
( T_5 ) V_260 -> V_167 ) ;
memcpy ( & V_236 -> V_169 . V_168 , V_260 -> V_169 , V_236 -> V_169 . V_165 ) ;
if ( V_236 -> V_169 . V_165 < V_313 ) {
V_236 -> V_169 . V_168 [ V_236 -> V_169 . V_165 ] = 0 ;
F_3 ( V_242 , L_117 , V_236 -> V_169 . V_168 ,
V_236 -> V_169 . V_165 ) ;
}
V_239 = F_48 ( struct V_308 , V_314 ) +
F_48 ( struct V_315 , V_254 ) ;
if ( V_120 -> V_253 )
V_239 += sizeof( T_1 ) ;
V_309 = F_51 ( V_239 , V_177 ) ;
if ( V_309 == NULL ) {
V_90 = - V_178 ;
goto V_149;
}
V_309 -> V_162 . V_165 = F_16 ( V_236 -> V_169 . V_165 ) ;
memcpy ( & V_309 -> V_162 . V_168 , V_260 -> V_169 ,
V_236 -> V_169 . V_165 ) ;
V_309 -> V_316 . V_133 = - 1 ;
V_309 -> V_316 . V_138 = F_16 ( - 1 ) ;
if ( V_260 -> V_129 )
memcpy ( & V_309 -> V_314 . V_129 , V_260 -> V_129 , V_130 ) ;
else
memset ( & V_309 -> V_314 . V_129 , 0xFF , V_130 ) ;
if ( V_120 -> V_253 ) {
V_309 -> V_314 . V_255 = F_16 ( 1 ) ;
V_309 -> V_314 . V_254 [ 0 ] =
F_17 ( V_159 ) ;
V_309 -> V_316 . V_136 =
F_16 ( V_317 ) ;
V_309 -> V_316 . V_137 =
F_16 ( V_318 ) ;
V_309 -> V_316 . V_135 =
F_16 ( V_317 /
V_319 ) ;
} else {
V_309 -> V_316 . V_136 = F_16 ( - 1 ) ;
V_309 -> V_316 . V_137 = F_16 ( - 1 ) ;
V_309 -> V_316 . V_135 = F_16 ( - 1 ) ;
}
V_90 = F_20 ( V_92 , L_118 , V_309 ,
V_239 ) ;
F_54 ( V_309 ) ;
if ( ! V_90 )
goto V_149;
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_239 = sizeof( V_238 . V_162 ) ;
memcpy ( & V_238 . V_162 . V_168 , V_260 -> V_169 , V_236 -> V_169 . V_165 ) ;
V_238 . V_162 . V_165 = F_16 ( V_236 -> V_169 . V_165 ) ;
if ( V_260 -> V_129 )
memcpy ( V_238 . V_124 . V_129 , V_260 -> V_129 , V_130 ) ;
else
memset ( V_238 . V_124 . V_129 , 0xFF , V_130 ) ;
if ( V_120 -> V_253 ) {
V_238 . V_124 . V_254 [ 0 ] = F_17 ( V_159 ) ;
V_238 . V_124 . V_255 = F_16 ( 1 ) ;
V_239 += sizeof( V_238 . V_124 ) ;
}
V_90 = F_34 ( V_92 , V_258 ,
& V_238 , V_239 ) ;
if ( V_90 )
F_22 ( L_119 , V_90 ) ;
V_149:
if ( V_90 )
F_61 ( V_205 , & V_92 -> V_2 -> V_4 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_87 ( struct V_104 * V_104 , struct V_88 * V_89 ,
T_1 V_320 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_230 * V_236 = & V_92 -> V_2 -> V_236 ;
struct V_321 V_322 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_120 , V_320 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
F_61 ( V_232 , & V_92 -> V_2 -> V_4 ) ;
F_71 ( V_89 , V_320 , NULL , 0 , V_177 ) ;
memcpy ( & V_322 . V_87 , & V_236 -> V_129 , V_130 ) ;
V_322 . V_263 = F_16 ( V_320 ) ;
V_90 = F_34 ( V_92 , V_233 ,
& V_322 , sizeof( V_322 ) ) ;
if ( V_90 )
F_22 ( L_43 , V_90 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_88 ( struct V_104 * V_104 , struct V_103 * V_99 ,
enum V_323 type , T_4 V_324 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_88 * V_89 = F_68 ( V_120 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_1 V_325 ;
T_4 V_90 = 0 ;
T_4 V_326 = 0 ;
T_4 V_327 = F_89 ( V_324 ) ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
switch ( type ) {
case V_328 :
break;
case V_329 :
case V_330 :
if ( V_327 < 0 ) {
F_22 ( L_121 ) ;
V_90 = - V_117 ;
goto V_149;
}
break;
}
V_326 = V_331 << 16 ;
V_90 = F_46 ( V_92 , V_332 , V_326 ) ;
if ( V_90 )
F_22 ( L_122 , V_90 ) ;
if ( V_327 > 0xffff )
V_325 = 0xffff ;
else
V_325 = ( T_1 ) V_327 ;
V_90 = F_24 ( V_92 , L_123 ,
( T_4 ) F_5 ( V_325 ) ) ;
if ( V_90 )
F_22 ( L_124 , V_90 ) ;
V_120 -> V_224 -> V_333 = V_327 ;
V_149:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4 F_90 ( struct V_104 * V_104 ,
struct V_103 * V_99 ,
T_4 * V_327 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_91 * V_92 = F_21 ( F_68 ( V_120 ) ) ;
T_4 V_334 ;
T_2 V_335 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
V_90 = F_91 ( V_92 , L_123 , & V_334 ) ;
if ( V_90 ) {
F_22 ( L_43 , V_90 ) ;
goto V_149;
}
V_335 = ( T_2 ) ( V_334 & ~ V_336 ) ;
* V_327 = ( T_4 ) F_4 ( V_335 ) ;
V_149:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_92 ( struct V_104 * V_104 , struct V_88 * V_89 ,
T_2 V_299 , bool V_337 , bool V_338 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_5 V_79 ;
T_5 V_240 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
F_3 ( V_242 , L_125 , V_299 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
V_90 = F_81 ( V_92 , L_77 , & V_240 ) ;
if ( V_90 ) {
F_22 ( L_126 , V_90 ) ;
goto V_149;
}
if ( V_240 & V_249 ) {
V_79 = V_299 ;
V_90 = F_46 ( V_92 ,
V_339 , V_79 ) ;
if ( V_90 )
F_22 ( L_43 , V_90 ) ;
}
V_149:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_93 ( struct V_104 * V_104 , struct V_88 * V_89 ,
T_2 V_299 , const T_2 * V_340 , struct V_341 * V_107 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_76 V_56 ;
T_4 V_90 = 0 ;
T_2 V_342 [ 8 ] ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_79 = ( T_5 ) V_299 ;
if ( ! F_94 ( V_340 ) )
memcpy ( ( char * ) & V_56 . V_87 , ( void * ) V_340 , V_130 ) ;
V_56 . V_60 = ( T_5 ) V_107 -> V_298 ;
if ( V_56 . V_60 == 0 ) {
V_90 = F_18 ( V_89 , & V_56 ) ;
if ( V_90 )
F_22 ( L_127 , V_90 ) ;
} else {
if ( V_56 . V_60 > sizeof( V_56 . V_86 ) ) {
F_22 ( L_128 , V_56 . V_60 ) ;
return - V_117 ;
}
F_3 ( V_242 , L_129 , V_56 . V_79 ) ;
memcpy ( V_56 . V_86 , V_107 -> V_56 , V_56 . V_60 ) ;
if ( ! F_25 ( V_92 -> V_2 ) &&
( V_107 -> V_343 == V_285 ) ) {
F_3 ( V_242 , L_130 ) ;
memcpy ( V_342 , & V_56 . V_86 [ 24 ] , sizeof( V_342 ) ) ;
memcpy ( & V_56 . V_86 [ 24 ] , & V_56 . V_86 [ 16 ] , sizeof( V_342 ) ) ;
memcpy ( & V_56 . V_86 [ 16 ] , V_342 , sizeof( V_342 ) ) ;
}
if ( V_107 -> V_344 && V_107 -> V_345 == 6 ) {
T_2 * V_346 ;
V_346 = ( T_2 * ) V_107 -> V_344 ;
V_56 . V_82 . V_83 = ( V_346 [ 5 ] << 24 ) | ( V_346 [ 4 ] << 16 ) |
( V_346 [ 3 ] << 8 ) | V_346 [ 2 ] ;
V_56 . V_82 . V_84 = ( V_346 [ 1 ] << 8 ) | V_346 [ 0 ] ;
V_56 . V_85 = true ;
}
switch ( V_107 -> V_343 ) {
case V_283 :
V_56 . V_80 = V_301 ;
F_3 ( V_242 , L_131 ) ;
break;
case V_284 :
V_56 . V_80 = V_302 ;
F_3 ( V_242 , L_132 ) ;
break;
case V_285 :
V_56 . V_80 = V_347 ;
F_3 ( V_242 , L_133 ) ;
break;
case V_289 :
V_56 . V_80 = V_348 ;
F_3 ( V_242 , L_134 ) ;
break;
case V_287 :
V_56 . V_80 = V_348 ;
F_3 ( V_242 , L_135 ) ;
break;
default:
F_22 ( L_136 , V_107 -> V_343 ) ;
return - V_117 ;
}
V_90 = F_18 ( V_89 , & V_56 ) ;
if ( V_90 )
F_22 ( L_4 , V_90 ) ;
}
return V_90 ;
}
static T_4
F_95 ( struct V_104 * V_104 , struct V_88 * V_89 ,
T_2 V_299 , bool V_349 , const T_2 * V_340 ,
struct V_341 * V_107 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_76 V_56 ;
T_4 V_263 ;
T_4 V_240 ;
T_4 V_90 = 0 ;
T_2 V_342 [ 8 ] ;
F_3 ( V_24 , L_14 ) ;
F_3 ( V_242 , L_125 , V_299 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
if ( V_340 &&
( V_107 -> V_343 != V_283 ) &&
( V_107 -> V_343 != V_284 ) ) {
F_3 ( V_24 , L_137 ) ;
return F_93 ( V_104 , V_89 , V_299 , V_340 , V_107 ) ;
}
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_60 = ( T_5 ) V_107 -> V_298 ;
V_56 . V_79 = ( T_5 ) V_299 ;
if ( V_56 . V_60 > sizeof( V_56 . V_86 ) ) {
F_22 ( L_100 , V_56 . V_60 ) ;
V_90 = - V_117 ;
goto V_149;
}
memcpy ( V_56 . V_86 , V_107 -> V_56 , V_56 . V_60 ) ;
V_56 . V_81 = V_300 ;
switch ( V_107 -> V_343 ) {
case V_283 :
V_56 . V_80 = V_301 ;
V_263 = V_249 ;
F_3 ( V_242 , L_131 ) ;
break;
case V_284 :
V_56 . V_80 = V_302 ;
V_263 = V_249 ;
F_3 ( V_242 , L_132 ) ;
break;
case V_285 :
if ( ! F_25 ( V_92 -> V_2 ) ) {
F_3 ( V_242 , L_130 ) ;
memcpy ( V_342 , & V_56 . V_86 [ 24 ] , sizeof( V_342 ) ) ;
memcpy ( & V_56 . V_86 [ 24 ] , & V_56 . V_86 [ 16 ] , sizeof( V_342 ) ) ;
memcpy ( & V_56 . V_86 [ 16 ] , V_342 , sizeof( V_342 ) ) ;
}
V_56 . V_80 = V_347 ;
V_263 = V_286 ;
F_3 ( V_242 , L_133 ) ;
break;
case V_289 :
V_56 . V_80 = V_348 ;
V_263 = V_288 ;
F_3 ( V_242 , L_134 ) ;
break;
case V_287 :
V_56 . V_80 = V_348 ;
V_263 = V_288 ;
F_3 ( V_242 , L_135 ) ;
break;
default:
F_22 ( L_136 , V_107 -> V_343 ) ;
V_90 = - V_117 ;
goto V_149;
}
V_90 = F_18 ( V_89 , & V_56 ) ;
if ( V_90 )
goto V_149;
V_90 = F_81 ( V_92 , L_77 , & V_240 ) ;
if ( V_90 ) {
F_22 ( L_138 , V_90 ) ;
goto V_149;
}
V_240 |= V_263 ;
V_90 = F_77 ( V_92 , L_77 , V_240 ) ;
if ( V_90 ) {
F_22 ( L_139 , V_90 ) ;
goto V_149;
}
V_149:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_96 ( struct V_104 * V_104 , struct V_88 * V_89 ,
T_2 V_299 , bool V_349 , const T_2 * V_340 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_76 V_56 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
if ( V_299 >= V_350 ) {
F_22 ( L_140 , V_299 ) ;
return - V_117 ;
}
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_79 = ( T_5 ) V_299 ;
V_56 . V_81 = V_300 ;
V_56 . V_80 = V_351 ;
F_3 ( V_242 , L_125 , V_299 ) ;
V_90 = F_18 ( V_89 , & V_56 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_97 ( struct V_104 * V_104 , struct V_88 * V_89 ,
T_2 V_299 , bool V_349 , const T_2 * V_340 , void * V_352 ,
void (* F_98) ( void * V_352 , struct V_341 * V_107 ) )
{
struct V_341 V_107 ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_230 * V_236 = & V_92 -> V_2 -> V_236 ;
struct V_261 * V_262 ;
T_4 V_240 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
F_3 ( V_242 , L_125 , V_299 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
V_90 = F_81 ( V_92 , L_77 , & V_240 ) ;
if ( V_90 ) {
F_22 ( L_126 , V_90 ) ;
V_90 = - V_153 ;
goto V_149;
}
if ( V_240 & V_249 ) {
V_262 = & V_236 -> V_262 ;
if ( V_262 -> V_292 & V_283 ) {
V_107 . V_343 = V_283 ;
F_3 ( V_242 , L_131 ) ;
} else if ( V_262 -> V_292 & V_284 ) {
V_107 . V_343 = V_284 ;
F_3 ( V_242 , L_132 ) ;
}
} else if ( V_240 & V_286 ) {
V_107 . V_343 = V_285 ;
F_3 ( V_242 , L_133 ) ;
} else if ( V_240 & V_288 ) {
V_107 . V_343 = V_289 ;
F_3 ( V_242 , L_134 ) ;
} else {
F_22 ( L_141 , V_240 ) ;
V_90 = - V_117 ;
goto V_149;
}
F_98 ( V_352 , & V_107 ) ;
V_149:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_99 ( struct V_104 * V_104 ,
struct V_88 * V_89 , T_2 V_299 )
{
F_3 ( V_5 , L_142 ) ;
return - V_113 ;
}
static T_4
F_100 ( struct V_104 * V_104 , struct V_88 * V_89 ,
const T_2 * V_353 , struct V_354 * V_355 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_230 * V_236 = & V_92 -> V_2 -> V_236 ;
struct V_321 V_356 ;
int V_357 ;
T_4 V_358 ;
T_4 V_90 = 0 ;
T_2 * V_129 = V_236 -> V_129 ;
struct V_359 V_360 ;
T_5 V_361 ;
T_5 V_362 ;
F_3 ( V_24 , L_143 , V_353 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
if ( F_25 ( V_92 -> V_2 ) ) {
memcpy ( & V_360 , V_353 , V_130 ) ;
V_90 = F_101 ( V_92 , L_144 ,
& V_360 ,
sizeof( V_360 ) ) ;
if ( V_90 < 0 ) {
F_22 ( L_145 , V_90 ) ;
goto V_149;
}
V_355 -> V_363 = V_364 ;
V_355 -> V_365 = F_102 ( V_360 . V_366 ) * 1000 ;
if ( F_102 ( V_360 . V_81 ) & V_367 ) {
V_355 -> V_363 |= V_368 ;
V_355 -> V_369 = F_102 ( V_360 . V_370 ) ;
}
F_3 ( V_24 , L_146 ,
V_355 -> V_365 , V_355 -> V_369 ) ;
} else if ( V_92 -> V_2 -> V_99 . V_98 == V_108 ) {
if ( memcmp ( V_353 , V_129 , V_130 ) ) {
F_22 ( L_147 ,
V_353 , V_129 ) ;
V_90 = - V_371 ;
goto V_149;
}
V_90 = F_103 ( V_92 , V_372 , & V_358 ) ;
if ( V_90 ) {
F_22 ( L_148 , V_90 ) ;
goto V_149;
} else {
V_355 -> V_363 |= V_373 ;
V_355 -> V_374 . V_375 = V_358 * 5 ;
F_3 ( V_242 , L_149 , V_358 / 2 ) ;
}
if ( F_2 ( V_232 ,
& V_92 -> V_2 -> V_4 ) ) {
memset ( & V_356 , 0 , sizeof( V_356 ) ) ;
V_90 = F_104 ( V_92 , V_376 ,
& V_356 , sizeof( V_356 ) ) ;
if ( V_90 ) {
F_22 ( L_150 , V_90 ) ;
goto V_149;
} else {
V_357 = F_102 ( V_356 . V_263 ) ;
V_355 -> V_363 |= V_377 ;
V_355 -> signal = V_357 ;
F_3 ( V_242 , L_151 , V_357 ) ;
}
V_90 = F_103 ( V_92 , V_378 ,
& V_361 ) ;
if ( V_90 ) {
F_22 ( L_152 ,
V_90 ) ;
goto V_149;
} else {
V_355 -> V_379 . V_246 =
V_361 ;
F_3 ( V_242 , L_153 ,
V_361 ) ;
}
V_90 = F_103 ( V_92 , V_380 ,
& V_362 ) ;
if ( V_90 ) {
F_22 ( L_154 ,
V_90 ) ;
goto V_149;
} else {
V_355 -> V_379 . V_362 = V_362 ;
F_3 ( V_242 , L_155 ,
V_362 ) ;
}
V_355 -> V_363 |= V_381 ;
}
} else
V_90 = - V_382 ;
V_149:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_105 ( struct V_104 * V_104 , struct V_88 * V_89 ,
bool V_383 , T_4 V_384 )
{
T_4 V_385 ;
T_4 V_90 = 0 ;
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
F_3 ( V_24 , L_14 ) ;
V_120 -> V_386 = V_383 ;
if ( ! F_1 ( V_92 -> V_2 ) ) {
F_3 ( V_5 , L_156 ) ;
goto V_149;
}
V_385 = V_383 ? V_387 : V_388 ;
if ( V_92 -> V_2 -> V_99 . V_98 == V_114 ) {
F_3 ( V_5 , L_157 ) ;
V_385 = V_388 ;
}
F_3 ( V_5 , L_158 , ( V_385 ? L_159 : L_160 ) ) ;
V_90 = F_46 ( V_92 , V_389 , V_385 ) ;
if ( V_90 ) {
if ( V_90 == - V_390 )
F_22 ( L_161 ) ;
else
F_22 ( L_43 , V_90 ) ;
}
V_149:
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4 F_106 ( struct V_119 * V_120 ,
struct V_391 * V_392 )
{
struct V_104 * V_104 = F_36 ( V_120 ) ;
struct V_52 * V_393 ;
struct V_394 * V_395 ;
struct V_396 * V_45 ;
struct V_21 V_20 ;
T_4 V_90 = 0 ;
T_1 V_253 ;
T_5 V_397 ;
T_1 V_398 ;
T_1 V_399 ;
T_2 * V_400 ;
T_6 V_401 ;
T_4 V_402 ;
if ( F_102 ( V_392 -> V_403 ) > V_404 ) {
F_22 ( L_162 ) ;
return 0 ;
}
if ( ! V_392 -> V_405 ) {
V_20 . V_51 = F_107 ( V_392 -> V_159 ) ;
V_120 -> V_18 . V_406 ( & V_20 ) ;
V_392 -> V_405 = V_20 . V_29 ;
}
V_253 = V_392 -> V_405 ;
if ( V_253 <= V_407 )
V_45 = V_104 -> V_408 [ V_46 ] ;
else
V_45 = V_104 -> V_408 [ V_48 ] ;
V_397 = F_108 ( V_253 , V_45 -> V_45 ) ;
V_393 = F_109 ( V_104 , V_397 ) ;
V_398 = F_107 ( V_392 -> V_409 ) ;
V_399 = F_107 ( V_392 -> V_361 ) ;
V_400 = ( T_2 * ) V_392 + F_107 ( V_392 -> V_410 ) ;
V_401 = F_102 ( V_392 -> V_411 ) ;
V_402 = ( V_412 ) F_107 ( V_392 -> V_413 ) * 100 ;
F_3 ( V_242 , L_163 , V_392 -> V_414 ) ;
F_3 ( V_242 , L_164 , V_253 , V_397 ) ;
F_3 ( V_242 , L_165 , V_398 ) ;
F_3 ( V_242 , L_166 , V_399 ) ;
F_3 ( V_242 , L_167 , V_402 ) ;
V_395 = F_110 ( V_104 , V_393 , ( const T_2 * ) V_392 -> V_414 ,
0 , V_398 , V_399 , V_400 ,
V_401 , V_402 , V_177 ) ;
if ( ! V_395 )
return - V_178 ;
F_111 ( V_104 , V_395 ) ;
return V_90 ;
}
static struct V_391 *
F_112 ( struct V_184 * V_415 , struct V_391 * V_395 )
{
if ( V_395 == NULL )
return V_415 -> V_416 ;
return (struct V_391 * ) ( ( unsigned long ) V_395 +
F_102 ( V_395 -> V_403 ) ) ;
}
static T_4 F_113 ( struct V_119 * V_120 )
{
struct V_184 * V_417 ;
struct V_391 * V_392 = NULL ;
T_4 V_90 = 0 ;
int V_158 ;
V_417 = V_120 -> V_417 ;
if ( V_417 -> V_192 != 0 &&
V_417 -> V_180 != V_418 ) {
F_22 ( L_168 ,
V_417 -> V_180 ) ;
return - V_113 ;
}
F_3 ( V_127 , L_169 , V_417 -> V_192 ) ;
for ( V_158 = 0 ; V_158 < V_417 -> V_192 ; V_158 ++ ) {
V_392 = F_112 ( V_417 , V_392 ) ;
V_90 = F_106 ( V_120 , V_392 ) ;
if ( V_90 )
break;
}
return V_90 ;
}
static T_4 F_114 ( struct V_119 * V_120 ,
struct V_88 * V_89 , const T_2 * V_129 )
{
struct V_104 * V_104 = F_36 ( V_120 ) ;
struct V_52 * V_393 ;
struct V_391 * V_392 = NULL ;
struct V_396 * V_45 ;
struct V_394 * V_395 ;
struct V_21 V_20 ;
T_2 * V_54 = NULL ;
T_4 V_90 = 0 ;
T_5 V_397 ;
T_1 V_398 ;
T_1 V_399 ;
T_2 * V_400 ;
T_6 V_401 ;
T_4 V_402 ;
F_3 ( V_24 , L_14 ) ;
V_54 = F_51 ( V_404 , V_177 ) ;
if ( V_54 == NULL ) {
V_90 = - V_178 ;
goto V_419;
}
* ( V_420 * ) V_54 = F_16 ( V_404 ) ;
V_90 = F_104 ( F_21 ( V_89 ) , V_421 ,
V_54 , V_404 ) ;
if ( V_90 ) {
F_22 ( L_170 , V_90 ) ;
goto V_419;
}
V_392 = (struct V_391 * ) ( V_54 + 4 ) ;
V_20 . V_51 = F_107 ( V_392 -> V_159 ) ;
V_120 -> V_18 . V_406 ( & V_20 ) ;
if ( V_20 . V_45 == V_47 )
V_45 = V_104 -> V_408 [ V_46 ] ;
else
V_45 = V_104 -> V_408 [ V_48 ] ;
V_397 = F_108 ( V_20 . V_29 , V_45 -> V_45 ) ;
V_393 = F_109 ( V_104 , V_397 ) ;
V_398 = F_107 ( V_392 -> V_409 ) ;
V_399 = F_107 ( V_392 -> V_361 ) ;
V_400 = ( T_2 * ) V_392 + F_107 ( V_392 -> V_410 ) ;
V_401 = F_102 ( V_392 -> V_411 ) ;
V_402 = ( V_412 ) F_107 ( V_392 -> V_413 ) * 100 ;
F_3 ( V_242 , L_171 , V_20 . V_29 , V_397 ) ;
F_3 ( V_242 , L_172 , V_398 ) ;
F_3 ( V_242 , L_71 , V_399 ) ;
F_3 ( V_242 , L_173 , V_402 ) ;
V_395 = F_110 ( V_104 , V_393 , V_129 ,
0 , V_398 , V_399 ,
V_400 , V_401 , V_402 , V_177 ) ;
if ( ! V_395 ) {
V_90 = - V_178 ;
goto V_419;
}
F_111 ( V_104 , V_395 ) ;
V_419:
F_54 ( V_54 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4 F_115 ( struct V_119 * V_120 ,
struct V_91 * V_92 )
{
struct V_230 * V_236 = F_76 ( V_92 -> V_89 ) ;
struct V_391 * V_392 ;
struct V_176 * V_169 ;
const struct V_53 * V_422 ;
T_1 V_246 ;
T_2 V_362 ;
T_6 V_245 ;
T_2 * V_62 ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( F_26 ( V_92 -> V_2 ) )
return V_90 ;
V_169 = & V_236 -> V_169 ;
* ( V_420 * ) V_120 -> V_423 = F_16 ( V_424 ) ;
V_90 = F_104 ( V_92 , V_421 ,
V_120 -> V_423 , V_424 ) ;
if ( V_90 ) {
F_22 ( L_174 , V_90 ) ;
goto V_425;
}
V_392 = (struct V_391 * ) ( V_120 -> V_423 + 4 ) ;
V_90 = F_106 ( V_120 , V_392 ) ;
if ( V_90 )
goto V_425;
V_62 = ( ( T_2 * ) V_392 ) + F_107 ( V_392 -> V_410 ) ;
V_245 = F_102 ( V_392 -> V_411 ) ;
V_246 = F_107 ( V_392 -> V_361 ) ;
V_422 = F_11 ( V_62 , V_245 , V_426 ) ;
if ( V_422 )
V_362 = V_422 -> V_86 [ 1 ] ;
else {
T_5 V_427 ;
V_90 = F_91 ( V_92 , L_175 , & V_427 ) ;
if ( V_90 ) {
F_22 ( L_176 , V_90 ) ;
goto V_425;
}
V_362 = ( T_2 ) V_427 ;
}
V_425:
F_3 ( V_24 , L_137 ) ;
return V_90 ;
}
void F_116 ( struct V_119 * V_120 )
{
struct V_146 * V_186 = & V_120 -> V_146 ;
F_45 ( V_203 , & V_120 -> V_143 ) ;
if ( V_120 -> V_126 ) {
V_186 -> V_187 = V_428 ;
F_31 ( V_120 , V_186 -> V_92 , true , true ) ;
}
F_61 ( V_142 , & V_120 -> V_143 ) ;
F_61 ( V_203 , & V_120 -> V_143 ) ;
}
static void F_117 ( struct V_429 * V_430 )
{
struct V_119 * V_120 =
F_63 ( V_430 , struct V_119 ,
V_431 ) ;
F_31 ( V_120 , V_120 -> V_146 . V_92 , true , true ) ;
}
static void F_118 ( unsigned long V_86 )
{
struct V_119 * V_120 =
(struct V_119 * ) V_86 ;
if ( V_120 -> V_126 ) {
F_22 ( L_177 ) ;
F_119 ( & V_120 -> V_431 ) ;
}
}
static T_4
F_120 ( struct V_119 * V_120 ,
struct V_391 * V_395 ,
struct V_391 * V_416 )
{
struct V_21 V_432 , V_433 ;
V_432 . V_51 = F_107 ( V_395 -> V_159 ) ;
V_120 -> V_18 . V_406 ( & V_432 ) ;
V_433 . V_51 = F_107 ( V_416 -> V_159 ) ;
V_120 -> V_18 . V_406 ( & V_433 ) ;
if ( ! memcmp ( & V_416 -> V_414 , & V_395 -> V_414 , V_130 ) &&
V_432 . V_45 == V_433 . V_45 &&
V_416 -> V_165 == V_395 -> V_165 &&
! memcmp ( V_416 -> V_168 , V_395 -> V_168 , V_416 -> V_165 ) ) {
if ( ( V_395 -> V_81 & V_434 ) ==
( V_416 -> V_81 & V_434 ) ) {
V_412 V_435 = F_107 ( V_395 -> V_413 ) ;
V_412 V_436 = F_107 ( V_416 -> V_413 ) ;
if ( V_436 > V_435 )
V_395 -> V_413 = V_416 -> V_413 ;
} else if ( ( V_395 -> V_81 & V_434 ) &&
( V_416 -> V_81 & V_434 ) == 0 ) {
V_395 -> V_413 = V_416 -> V_413 ;
V_395 -> V_81 |= V_434 ;
}
return 1 ;
}
return 0 ;
}
static T_4
F_121 ( struct V_91 * V_92 ,
const struct V_437 * V_438 , void * V_86 )
{
struct V_119 * V_120 = V_92 -> V_439 -> V_440 ;
T_4 V_441 ;
T_4 V_90 = 0 ;
struct V_442 * V_443 ;
struct V_391 * V_416 ;
struct V_391 * V_395 = NULL ;
T_5 V_444 ;
struct V_184 * V_415 ;
T_5 V_158 ;
bool V_121 ;
V_441 = V_438 -> V_441 ;
if ( ! F_2 ( V_142 , & V_120 -> V_143 ) ) {
F_22 ( L_178 , V_92 -> V_445 ) ;
return - V_382 ;
}
if ( V_441 == V_446 ) {
F_3 ( V_127 , L_179 ) ;
V_443 = (struct V_442 * ) V_86 ;
if ( ! V_443 ) {
F_22 ( L_180 ) ;
goto exit;
}
if ( F_107 ( V_443 -> V_447 ) != 1 ) {
F_22 ( L_181 ,
V_443 -> V_447 ) ;
goto exit;
}
V_416 = & V_443 -> V_416 ;
if ( F_122 ( V_120 , V_416 ) )
goto exit;
if ( ! V_120 -> V_126 ) {
F_3 ( V_127 , L_182 ) ;
goto exit;
}
V_444 = F_102 ( V_416 -> V_403 ) ;
if ( V_444 != ( F_102 ( V_443 -> V_55 ) -
V_193 ) ) {
F_22 ( L_183 ,
V_444 ) ;
goto exit;
}
if ( ! ( F_36 ( V_120 ) -> V_448 &
F_123 ( V_102 ) ) ) {
if ( F_107 ( V_416 -> V_409 ) &
V_449 ) {
F_22 ( L_184 ) ;
goto exit;
}
}
V_415 = (struct V_184 * )
V_120 -> V_146 . V_191 ;
if ( V_444 > V_450 - V_415 -> V_55 ) {
F_22 ( L_185 ) ;
goto exit;
}
for ( V_158 = 0 ; V_158 < V_415 -> V_192 ; V_158 ++ ) {
V_395 = V_395 ? (struct V_391 * )
( ( unsigned char * ) V_395 +
F_102 ( V_395 -> V_403 ) ) : V_415 -> V_416 ;
if ( F_120 ( V_120 , V_395 ,
V_416 ) )
goto exit;
}
memcpy ( & ( V_120 -> V_146 . V_191 [ V_415 -> V_55 ] ) ,
V_416 , V_444 ) ;
V_415 -> V_180 = F_102 ( V_416 -> V_180 ) ;
V_415 -> V_55 += V_444 ;
V_415 -> V_192 ++ ;
} else {
V_120 -> V_146 . V_187 = V_428 ;
if ( F_122 ( V_120 , NULL ) )
goto exit;
if ( V_120 -> V_126 ) {
V_120 -> V_417 = (struct V_184 * )
V_120 -> V_146 . V_191 ;
F_113 ( V_120 ) ;
V_121 = V_441 != V_451 ;
F_31 ( V_120 , V_92 , V_121 ,
false ) ;
} else
F_3 ( V_127 , L_186 ,
V_441 ) ;
}
exit:
return V_90 ;
}
static void F_124 ( struct V_119 * V_120 )
{
F_125 ( V_120 -> V_452 , V_453 ,
F_121 ) ;
V_120 -> V_146 . V_187 = V_428 ;
F_126 ( & V_120 -> V_128 ) ;
V_120 -> V_128 . V_86 = ( unsigned long ) V_120 ;
V_120 -> V_128 . V_454 = F_118 ;
F_127 ( & V_120 -> V_431 ,
F_117 ) ;
}
static T_7 void F_128 ( T_5 V_455 )
{
if ( V_455 < 1000 / V_212 ) {
F_129 () ;
F_130 ( V_455 ) ;
} else {
F_131 ( V_455 ) ;
}
}
static T_4 F_132 ( struct V_104 * V_104 )
{
F_3 ( V_24 , L_14 ) ;
return 0 ;
}
static T_4 F_133 ( struct V_104 * V_104 ,
struct V_456 * V_457 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_88 * V_89 = F_68 ( V_120 ) ;
struct V_1 * V_2 ;
F_3 ( V_24 , L_14 ) ;
V_2 = ( (struct V_91 * ) F_21 ( V_89 ) ) -> V_2 ;
if ( ! F_1 ( V_2 ) )
goto exit;
F_134 (vif, &cfg->vif_list, list) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
continue;
F_70 ( V_2 ) ;
F_128 ( 500 ) ;
}
if ( F_2 ( V_142 , & V_120 -> V_143 ) )
F_116 ( V_120 ) ;
F_30 ( F_21 ( V_89 ) , 1 ) ;
exit:
F_3 ( V_24 , L_31 ) ;
V_120 -> V_143 = 0 ;
return 0 ;
}
static T_8 T_4
F_135 ( struct V_88 * V_89 ,
struct V_458 * V_459 , T_4 V_90 )
{
int V_158 , V_460 ;
int V_461 ;
V_461 = F_102 ( V_459 -> V_462 . V_463 ) ;
F_3 ( V_242 , L_187 , V_461 ) ;
for ( V_158 = 0 ; V_158 < V_461 ; V_158 ++ ) {
F_3 ( V_242 , L_188 , V_158 ,
& V_459 -> V_462 . V_464 [ V_158 ] . V_414 ) ;
for ( V_460 = 0 ; V_460 < V_465 ; V_460 ++ )
F_3 ( V_242 , L_189 ,
V_459 -> V_462 . V_464 [ V_158 ] . V_466 [ V_460 ] ) ;
}
if ( ! V_90 )
F_53 ( F_21 ( V_89 ) , L_190 ,
( char * ) V_459 , sizeof( * V_459 ) ) ;
return V_90 ;
}
static T_4
F_136 ( struct V_104 * V_104 , struct V_88 * V_89 ,
struct V_467 * V_468 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_469 * V_462 = & V_120 -> V_459 -> V_462 ;
T_4 V_90 = 0 ;
int V_158 ;
int V_461 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
V_461 = F_102 ( V_462 -> V_463 ) ;
for ( V_158 = 0 ; V_158 < V_461 ; V_158 ++ )
if ( ! memcmp ( V_468 -> V_129 , V_462 -> V_464 [ V_158 ] . V_414 , V_130 ) )
break;
if ( V_158 < V_470 ) {
memcpy ( V_462 -> V_464 [ V_158 ] . V_414 , V_468 -> V_129 , V_130 ) ;
memcpy ( V_462 -> V_464 [ V_158 ] . V_466 , V_468 -> V_464 , V_465 ) ;
if ( V_158 == V_461 ) {
V_461 ++ ;
V_462 -> V_463 = F_16 ( V_461 ) ;
}
} else
V_90 = - V_117 ;
F_3 ( V_242 , L_191 ,
V_462 -> V_464 [ V_461 ] . V_414 ) ;
for ( V_158 = 0 ; V_158 < V_465 ; V_158 ++ )
F_3 ( V_242 , L_189 , V_462 -> V_464 [ V_461 ] . V_466 [ V_158 ] ) ;
V_90 = F_135 ( V_89 , V_120 -> V_459 , V_90 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_137 ( struct V_104 * V_104 , struct V_88 * V_89 ,
struct V_467 * V_468 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_469 V_464 ;
T_4 V_90 = 0 ;
int V_158 , V_461 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
memcpy ( & V_464 . V_464 [ 0 ] . V_414 , V_468 -> V_129 , V_130 ) ;
memcpy ( & V_464 . V_464 [ 0 ] . V_466 , V_468 -> V_464 , V_465 ) ;
F_3 ( V_242 , L_192 ,
& V_464 . V_464 [ 0 ] . V_414 ) ;
for ( V_158 = 0 ; V_158 < V_465 ; V_158 ++ )
F_3 ( V_242 , L_189 , V_464 . V_464 [ 0 ] . V_466 [ V_158 ] ) ;
V_461 = F_102 ( V_120 -> V_459 -> V_462 . V_463 ) ;
for ( V_158 = 0 ; V_158 < V_461 ; V_158 ++ )
if ( ! memcmp
( V_468 -> V_129 , & V_120 -> V_459 -> V_462 . V_464 [ V_158 ] . V_414 ,
V_130 ) )
break;
if ( ( V_461 > 0 )
&& ( V_158 < V_461 ) ) {
memset ( & V_120 -> V_459 -> V_462 . V_464 [ V_158 ] , 0 ,
sizeof( struct V_464 ) ) ;
for (; V_158 < ( V_461 - 1 ) ; V_158 ++ ) {
memcpy ( & V_120 -> V_459 -> V_462 . V_464 [ V_158 ] . V_414 ,
& V_120 -> V_459 -> V_462 . V_464 [ V_158 + 1 ] . V_414 ,
V_130 ) ;
memcpy ( & V_120 -> V_459 -> V_462 . V_464 [ V_158 ] . V_466 ,
& V_120 -> V_459 -> V_462 . V_464 [ V_158 + 1 ] . V_466 ,
V_465 ) ;
}
V_120 -> V_459 -> V_462 . V_463 = F_16 ( V_461 - 1 ) ;
} else
V_90 = - V_117 ;
V_90 = F_135 ( V_89 , V_120 -> V_459 , V_90 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_138 ( struct V_104 * V_104 , struct V_88 * V_89 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
memset ( V_120 -> V_459 , 0 , sizeof( * V_120 -> V_459 ) ) ;
V_90 = F_135 ( V_89 , V_120 -> V_459 , V_90 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_139 ( struct V_91 * V_92 ,
const struct V_437 * V_438 , void * V_86 )
{
struct V_119 * V_120 = V_92 -> V_439 -> V_440 ;
struct V_471 * V_472 , * V_473 ;
struct V_125 * V_155 = NULL ;
struct V_196 * V_169 = NULL ;
struct V_52 * V_253 = NULL ;
struct V_104 * V_104 = F_36 ( V_120 ) ;
int V_90 = 0 ;
int V_474 = 0 ;
int V_45 = 0 ;
struct V_475 * V_476 ;
T_5 V_477 ;
T_5 V_441 ;
F_3 ( V_127 , L_14 ) ;
if ( V_438 -> V_478 == V_479 ) {
F_3 ( V_127 , L_193 ) ;
return 0 ;
}
V_476 = (struct V_475 * ) V_86 ;
V_477 = F_102 ( V_476 -> V_192 ) ;
V_441 = F_102 ( V_476 -> V_441 ) ;
F_8 ( V_441 != V_480 ) ;
F_3 ( V_127 , L_194 , V_477 ) ;
if ( V_477 > 0 ) {
int V_158 ;
V_155 = F_51 ( sizeof( * V_155 ) , V_177 ) ;
V_169 = F_140 ( V_477 , sizeof( * V_169 ) , V_177 ) ;
V_253 = F_140 ( V_477 , sizeof( * V_253 ) , V_177 ) ;
if ( ! V_155 || ! V_169 || ! V_253 ) {
V_90 = - V_178 ;
goto V_481;
}
V_155 -> V_104 = V_104 ;
V_86 += sizeof( struct V_475 ) ;
V_473 = (struct V_471 * ) V_86 ;
for ( V_158 = 0 ; V_158 < V_477 ; V_158 ++ ) {
V_472 = & V_473 [ V_158 ] ;
if ( ! V_472 ) {
F_22 ( L_195 ,
V_158 ) ;
V_90 = - V_117 ;
goto V_481;
}
F_3 ( V_127 , L_196 ,
V_472 -> V_168 , V_472 -> V_253 ) ;
memcpy ( V_169 [ V_158 ] . V_169 , V_472 -> V_168 , V_472 -> V_165 ) ;
V_169 [ V_158 ] . V_167 = V_472 -> V_165 ;
V_155 -> V_156 ++ ;
V_474 = V_472 -> V_253 ;
if ( V_474 <= V_407 )
V_45 = V_482 ;
else
V_45 = V_483 ;
V_253 [ V_158 ] . V_26 =
F_108 ( V_474 ,
V_45 ) ;
V_253 [ V_158 ] . V_45 = V_45 ;
V_253 [ V_158 ] . V_81 |= V_484 ;
V_155 -> V_163 [ V_158 ] = & V_253 [ V_158 ] ;
V_155 -> V_157 ++ ;
}
if ( V_155 -> V_156 )
V_155 -> V_166 = & V_169 [ 0 ] ;
if ( F_2 ( V_142 , & V_120 -> V_143 ) ) {
F_116 ( V_120 ) ;
}
F_45 ( V_142 , & V_120 -> V_143 ) ;
V_120 -> V_146 . V_194 = F_50 ;
V_90 = F_55 ( V_120 , V_104 , V_92 , V_155 ) ;
if ( V_90 ) {
F_61 ( V_142 , & V_120 -> V_143 ) ;
goto V_481;
}
V_120 -> V_141 = true ;
V_120 -> V_126 = V_155 ;
} else {
F_22 ( L_197 ) ;
goto V_481;
}
F_54 ( V_169 ) ;
F_54 ( V_253 ) ;
F_54 ( V_155 ) ;
return 0 ;
V_481:
F_54 ( V_169 ) ;
F_54 ( V_253 ) ;
F_54 ( V_155 ) ;
F_141 ( V_104 ) ;
return V_90 ;
}
static int F_142 ( struct V_88 * V_89 )
{
int V_485 ;
V_485 = F_24 ( F_21 ( V_89 ) , L_198 , 0 ) ;
if ( V_485 == 0 ) {
V_485 = F_53 ( F_21 ( V_89 ) , L_199 ,
NULL , 0 ) ;
}
if ( V_485 < 0 )
F_22 ( L_200 , V_485 ) ;
return V_485 ;
}
static int F_143 ( struct V_88 * V_89 )
{
struct V_486 V_487 ;
memset ( & V_487 , 0 , sizeof( V_487 ) ) ;
V_487 . V_180 = F_16 ( V_488 ) ;
V_487 . V_81 = F_17 ( 1 << V_489 ) ;
V_487 . V_490 = V_491 ;
V_487 . exp = V_492 ;
V_487 . V_493 = F_16 ( V_494 ) ;
return F_53 ( F_21 ( V_89 ) , L_201 ,
& V_487 , sizeof( V_487 ) ) ;
}
static int
F_144 ( struct V_104 * V_104 ,
struct V_88 * V_89 ,
struct V_495 * V_155 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_119 * V_120 = F_40 ( V_104 ) ;
struct V_496 V_497 ;
int V_158 ;
int V_485 = 0 ;
F_3 ( V_127 , L_202 ,
V_155 -> V_498 , V_155 -> V_156 ) ;
if ( F_2 ( V_142 , & V_120 -> V_143 ) ) {
F_22 ( L_45 , V_120 -> V_143 ) ;
return - V_153 ;
}
if ( F_2 ( V_204 , & V_120 -> V_143 ) ) {
F_22 ( L_47 ,
V_120 -> V_143 ) ;
return - V_153 ;
}
if ( ! V_155 -> V_156 || ! V_155 -> V_498 ) {
F_3 ( V_127 , L_203 ,
V_155 -> V_156 ) ;
return - V_117 ;
}
if ( V_155 -> V_156 > 0 ) {
for ( V_158 = 0 ; V_158 < V_155 -> V_156 ; V_158 ++ ) {
F_3 ( V_127 , L_204 ,
V_155 -> V_166 [ V_158 ] . V_169 ) ;
}
}
if ( V_155 -> V_498 > 0 ) {
V_485 = F_142 ( V_89 ) ;
if ( V_485 < 0 ) {
F_22 ( L_205 , V_485 ) ;
return V_485 ;
}
V_485 = F_143 ( V_89 ) ;
if ( V_485 < 0 ) {
F_22 ( L_206 , V_485 ) ;
return - V_117 ;
}
for ( V_158 = 0 ; V_158 < V_155 -> V_498 ; V_158 ++ ) {
struct V_196 * V_169 ;
T_5 V_167 ;
V_169 = & V_155 -> V_499 [ V_158 ] . V_169 ;
V_167 = V_169 -> V_167 ;
if ( ! V_167 ) {
F_22 ( L_207 ) ;
continue;
}
V_497 . V_500 = F_16 ( V_501 ) ;
V_497 . V_297 = F_16 ( V_502 ) ;
V_497 . V_240 = F_16 ( 0 ) ;
V_497 . V_147 = F_16 ( 1 ) ;
V_497 . V_81 = F_16 ( 1 << V_503 ) ;
V_497 . V_169 . V_165 = F_16 ( V_167 ) ;
memcpy ( V_497 . V_169 . V_168 , V_169 -> V_169 , V_167 ) ;
V_485 = F_53 ( V_92 , L_208 , & V_497 ,
sizeof( V_497 ) ) ;
F_3 ( V_127 , L_209 ,
V_485 == 0 ? L_210 : L_211 , V_169 -> V_169 ) ;
}
if ( F_24 ( V_92 , L_198 , 1 ) < 0 ) {
F_22 ( L_212 , V_485 ) ;
return - V_117 ;
}
} else {
return - V_117 ;
}
return 0 ;
}
static int F_145 ( struct V_104 * V_104 ,
struct V_88 * V_89 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
F_3 ( V_127 , L_213 ) ;
F_142 ( V_89 ) ;
if ( V_120 -> V_141 )
F_31 ( V_120 , F_21 ( V_89 ) , true , true ) ;
return 0 ;
}
static int F_146 ( struct V_104 * V_104 ,
struct V_103 * V_99 ,
void * V_86 , int V_60 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_88 * V_89 = F_68 ( V_120 ) ;
struct V_504 * V_505 = V_86 ;
struct V_506 * V_507 ;
int V_485 ;
F_3 ( V_24 , L_214 , V_505 -> V_219 , V_505 -> V_508 ,
V_505 -> V_54 , V_505 -> V_60 ) ;
if ( V_505 -> V_508 )
V_485 = F_34 ( F_21 ( V_89 ) , V_505 -> V_219 ,
V_505 -> V_54 , V_505 -> V_60 ) ;
else
V_485 = F_104 ( F_21 ( V_89 ) , V_505 -> V_219 ,
V_505 -> V_54 , V_505 -> V_60 ) ;
if ( V_485 == 0 ) {
V_507 = F_147 ( V_104 , sizeof( * V_505 ) ) ;
F_148 ( V_507 , V_509 , sizeof( * V_505 ) , V_505 ) ;
V_485 = F_149 ( V_507 ) ;
}
return V_485 ;
}
static T_4 F_150 ( struct V_91 * V_92 )
{
T_4 V_90 ;
V_90 = F_77 ( V_92 , L_90 , 0 ) ;
if ( V_90 < 0 ) {
F_22 ( L_215 , V_90 ) ;
return V_90 ;
}
V_90 = F_77 ( V_92 , L_77 , 0 ) ;
if ( V_90 < 0 ) {
F_22 ( L_216 , V_90 ) ;
return V_90 ;
}
V_90 = F_77 ( V_92 , L_83 , V_510 ) ;
if ( V_90 < 0 ) {
F_22 ( L_217 , V_90 ) ;
return V_90 ;
}
return 0 ;
}
static bool F_151 ( T_2 * V_65 , bool V_511 )
{
if ( V_511 )
return ( memcmp ( V_65 , V_512 , V_73 ) == 0 ) ;
return ( memcmp ( V_65 , V_72 , V_73 ) == 0 ) ;
}
static T_4
F_152 ( struct V_88 * V_89 ,
const struct V_69 * V_307 ,
bool V_511 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_5 V_500 = 0 ;
T_1 V_192 ;
T_4 V_90 = 0 ;
T_4 V_60 = 0 ;
T_5 V_158 ;
T_5 V_240 ;
T_5 V_279 = 0 ;
T_5 V_280 = 0 ;
T_5 V_297 = 0 ;
T_5 V_13 ;
T_2 * V_86 ;
T_1 V_513 ;
T_5 V_514 ;
F_3 ( V_24 , L_14 ) ;
if ( V_307 == NULL )
goto exit;
V_60 = V_307 -> V_60 + V_59 ;
V_86 = ( T_2 * ) V_307 ;
V_13 = V_59 ;
if ( ! V_511 )
V_13 += V_515 ;
else
V_13 += V_516 ;
if ( V_13 + V_517 > V_60 ) {
V_90 = - V_117 ;
F_22 ( L_218 ) ;
goto exit;
}
if ( ! F_151 ( & V_86 [ V_13 ] , V_511 ) ) {
V_90 = - V_117 ;
F_22 ( L_219 ) ;
goto exit;
}
V_13 += V_73 ;
switch ( V_86 [ V_13 ] ) {
case V_518 :
V_280 = 0 ;
break;
case V_519 :
case V_520 :
V_280 = V_249 ;
break;
case V_521 :
V_280 = V_286 ;
break;
case V_522 :
V_280 = V_288 ;
break;
default:
V_90 = - V_117 ;
F_22 ( L_220 ) ;
goto exit;
}
V_13 ++ ;
V_192 = V_86 [ V_13 ] + ( V_86 [ V_13 + 1 ] << 8 ) ;
V_13 += V_523 ;
if ( V_13 + ( V_517 * V_192 ) > V_60 ) {
V_90 = - V_117 ;
F_22 ( L_221 ) ;
goto exit;
}
for ( V_158 = 0 ; V_158 < V_192 ; V_158 ++ ) {
if ( ! F_151 ( & V_86 [ V_13 ] , V_511 ) ) {
V_90 = - V_117 ;
F_22 ( L_219 ) ;
goto exit;
}
V_13 += V_73 ;
switch ( V_86 [ V_13 ] ) {
case V_518 :
break;
case V_519 :
case V_520 :
V_279 |= V_249 ;
break;
case V_521 :
V_279 |= V_286 ;
break;
case V_522 :
V_279 |= V_288 ;
break;
default:
F_22 ( L_222 ) ;
}
V_13 ++ ;
}
V_192 = V_86 [ V_13 ] + ( V_86 [ V_13 + 1 ] << 8 ) ;
V_13 += V_523 ;
if ( V_13 + ( V_517 * V_192 ) > V_60 ) {
V_90 = - V_117 ;
F_22 ( L_223 ) ;
goto exit;
}
for ( V_158 = 0 ; V_158 < V_192 ; V_158 ++ ) {
if ( ! F_151 ( & V_86 [ V_13 ] , V_511 ) ) {
V_90 = - V_117 ;
F_22 ( L_219 ) ;
goto exit;
}
V_13 += V_73 ;
switch ( V_86 [ V_13 ] ) {
case V_524 :
F_3 ( V_24 , L_224 ) ;
V_297 |= V_510 ;
break;
case V_525 :
F_3 ( V_24 , L_225 ) ;
V_511 ? ( V_297 |= V_271 ) :
( V_297 |= V_268 ) ;
break;
case V_526 :
F_3 ( V_24 , L_226 ) ;
V_511 ? ( V_297 |= V_270 ) :
( V_297 |= V_267 ) ;
break;
default:
F_22 ( L_227 ) ;
}
V_13 ++ ;
}
if ( V_511 ) {
V_514 = 1 ;
if ( ( V_13 + V_527 ) <= V_60 ) {
V_513 = V_86 [ V_13 ] + ( V_86 [ V_13 + 1 ] << 8 ) ;
if ( V_513 & V_528 )
V_514 = 0 ;
}
V_90 = F_77 ( V_92 , L_228 ,
V_514 ) ;
if ( V_90 < 0 ) {
F_22 ( L_229 , V_90 ) ;
goto exit;
}
}
V_240 = ( V_279 | V_280 | V_529 ) ;
V_90 = F_77 ( V_92 , L_90 , V_500 ) ;
if ( V_90 < 0 ) {
F_22 ( L_215 , V_90 ) ;
goto exit;
}
V_90 = F_77 ( V_92 , L_77 , V_240 ) ;
if ( V_90 < 0 ) {
F_22 ( L_216 , V_90 ) ;
goto exit;
}
V_90 = F_77 ( V_92 , L_83 , V_297 ) ;
if ( V_90 < 0 ) {
F_22 ( L_217 , V_90 ) ;
goto exit;
}
exit:
return V_90 ;
}
static T_4
F_153 ( const T_2 * V_530 , T_5 V_531 ,
struct V_532 * V_533 )
{
T_4 V_90 = 0 ;
struct V_69 * V_534 ;
struct V_53 * V_62 ;
struct V_535 * V_536 ;
T_4 V_537 ;
V_537 = ( T_4 ) V_531 ;
memset ( V_533 , 0 , sizeof( * V_533 ) ) ;
V_62 = (struct V_53 * ) V_530 ;
while ( V_62 ) {
if ( V_62 -> V_61 != V_71 )
goto V_538;
V_534 = (struct V_69 * ) V_62 ;
if ( V_534 -> V_60 < ( V_515 - V_59 + 1 ) ) {
F_22 ( L_230 ,
V_534 -> V_60 ) ;
goto V_538;
}
if ( ! memcmp ( V_534 -> V_65 , ( T_2 * ) V_72 , V_73 ) &&
( ( V_534 -> V_539 == V_74 ) ||
( V_534 -> V_539 == V_540 ) ) ) {
F_3 ( V_24 , L_231 ) ;
goto V_538;
}
V_536 = & V_533 -> V_541 [ V_533 -> V_192 ] ;
V_536 -> V_542 = ( char * ) V_534 ;
V_536 -> V_245 = V_534 -> V_60 + V_59 ;
memcpy ( & V_536 -> V_534 , V_534 , sizeof( * V_534 ) ) ;
V_533 -> V_192 ++ ;
F_3 ( V_24 , L_232 ,
V_536 -> V_534 . V_65 [ 0 ] ,
V_536 -> V_534 . V_65 [ 1 ] ,
V_536 -> V_534 . V_65 [ 2 ] ,
V_536 -> V_534 . V_539 ) ;
if ( V_533 -> V_192 >= V_543 )
break;
V_538:
V_537 -= ( V_62 -> V_60 + V_59 ) ;
if ( V_537 <= V_59 )
V_62 = NULL ;
else
V_62 = (struct V_53 * ) ( ( ( T_2 * ) V_62 ) + V_62 -> V_60 +
V_59 ) ;
}
return V_90 ;
}
static T_5
F_154 ( T_2 * V_544 , T_4 V_545 , T_2 * V_542 , T_5 V_245 , T_9 * V_546 )
{
V_420 V_547 ;
V_420 V_548 ;
strncpy ( V_544 , V_546 , V_549 - 1 ) ;
V_544 [ V_549 - 1 ] = '\0' ;
V_547 = F_16 ( 1 ) ;
memcpy ( & V_544 [ V_550 ] , & V_547 , sizeof( V_547 ) ) ;
V_548 = F_16 ( V_545 ) ;
memcpy ( & V_544 [ V_551 ] , & V_548 , sizeof( V_548 ) ) ;
memcpy ( & V_544 [ V_552 ] , V_542 , V_245 ) ;
return V_245 + V_553 ;
}
T_4 F_86 ( struct V_1 * V_2 , T_4 V_545 ,
const T_2 * V_530 , T_5 V_531 )
{
struct V_91 * V_92 ;
struct V_554 * V_555 ;
T_4 V_90 = 0 ;
T_2 * V_556 ;
T_2 * V_557 ;
T_2 * V_558 = NULL ;
int V_559 ;
T_5 * V_560 ;
T_5 V_561 = 0 ;
T_5 V_562 = 0 ;
T_5 V_563 = 0 ;
struct V_532 V_564 ;
struct V_532 V_565 ;
struct V_535 * V_566 ;
T_4 V_158 ;
T_2 * V_160 ;
int V_567 ;
if ( ! V_2 )
return - V_390 ;
V_92 = V_2 -> V_92 ;
V_555 = & V_2 -> V_555 ;
F_3 ( V_24 , L_233 , V_92 -> V_445 , V_545 ) ;
V_556 = F_51 ( V_424 , V_177 ) ;
if ( ! V_556 )
return - V_178 ;
V_557 = V_556 ;
switch ( V_545 ) {
case V_568 :
V_558 = V_555 -> V_569 ;
V_560 = & V_555 -> V_570 ;
V_559 = sizeof( V_555 -> V_569 ) ;
break;
case V_571 :
V_558 = V_555 -> V_572 ;
V_560 = & V_555 -> V_573 ;
V_559 = sizeof( V_555 -> V_572 ) ;
break;
case V_574 :
V_558 = V_555 -> V_575 ;
V_560 = & V_555 -> V_576 ;
V_559 = sizeof( V_555 -> V_575 ) ;
break;
case V_311 :
V_558 = V_555 -> V_577 ;
V_560 = & V_555 -> V_578 ;
V_559 = sizeof( V_555 -> V_577 ) ;
break;
default:
V_90 = - V_382 ;
F_22 ( L_234 ) ;
goto exit;
}
if ( V_531 > V_559 ) {
V_90 = - V_178 ;
F_22 ( L_235 ) ;
goto exit;
}
if ( V_530 && V_531 && V_557 ) {
V_160 = V_557 ;
F_153 ( V_530 , V_531 , & V_565 ) ;
for ( V_158 = 0 ; V_158 < V_565 . V_192 ; V_158 ++ ) {
V_566 = & V_565 . V_541 [ V_158 ] ;
memcpy ( V_160 + V_563 , V_566 -> V_542 ,
V_566 -> V_245 ) ;
V_563 += V_566 -> V_245 ;
}
}
if ( V_558 && * V_560 ) {
if ( V_563 && ( V_563 == * V_560 ) &&
( memcmp ( V_558 , V_557 ,
V_563 ) == 0 ) ) {
F_3 ( V_24 , L_236 ) ;
goto exit;
}
F_153 ( V_558 , * V_560 , & V_564 ) ;
for ( V_158 = 0 ; V_158 < V_564 . V_192 ; V_158 ++ ) {
V_566 = & V_564 . V_541 [ V_158 ] ;
F_3 ( V_24 , L_237 ,
V_566 -> V_534 . V_61 ,
V_566 -> V_534 . V_60 ,
V_566 -> V_534 . V_65 [ 0 ] ,
V_566 -> V_534 . V_65 [ 1 ] ,
V_566 -> V_534 . V_65 [ 2 ] ) ;
V_561 = F_154 ( V_557 , V_545 ,
V_566 -> V_542 ,
V_566 -> V_245 ,
L_238 ) ;
V_557 += V_561 ;
V_562 += V_561 ;
}
}
* V_560 = 0 ;
if ( V_558 && V_563 ) {
V_160 = V_558 ;
V_567 = V_559 ;
for ( V_158 = 0 ; V_158 < V_565 . V_192 ; V_158 ++ ) {
V_566 = & V_565 . V_541 [ V_158 ] ;
if ( V_567 < ( V_566 -> V_534 . V_60 +
V_552 ) ) {
F_22 ( L_239 ,
V_567 ) ;
break;
}
V_567 -= ( V_566 -> V_245 +
V_552 ) ;
F_3 ( V_24 , L_240 ,
V_566 -> V_534 . V_61 ,
V_566 -> V_534 . V_60 ,
V_566 -> V_534 . V_65 [ 0 ] ,
V_566 -> V_534 . V_65 [ 1 ] ,
V_566 -> V_534 . V_65 [ 2 ] ) ;
V_561 = F_154 ( V_557 , V_545 ,
V_566 -> V_542 ,
V_566 -> V_245 ,
L_241 ) ;
memcpy ( V_160 + ( * V_560 ) , V_566 -> V_542 ,
V_566 -> V_245 ) ;
* V_560 += V_566 -> V_245 ;
V_557 += V_561 ;
V_562 += V_561 ;
}
}
if ( V_562 ) {
V_90 = F_20 ( V_92 , L_242 , V_556 ,
V_562 ) ;
if ( V_90 )
F_22 ( L_243 , V_90 ) ;
}
exit:
F_54 ( V_556 ) ;
return V_90 ;
}
T_4 F_155 ( struct V_1 * V_2 )
{
T_4 V_579 [] = {
V_568 ,
V_571 ,
V_574
} ;
int V_158 ;
for ( V_158 = 0 ; V_158 < F_156 ( V_579 ) ; V_158 ++ )
F_86 ( V_2 , V_579 [ V_158 ] , NULL , 0 ) ;
memset ( & V_2 -> V_555 , 0 , sizeof( V_2 -> V_555 ) ) ;
return 0 ;
}
static T_4
F_157 ( struct V_1 * V_2 ,
struct V_580 * V_581 )
{
T_4 V_90 ;
V_90 = F_86 ( V_2 , V_574 ,
V_581 -> V_582 , V_581 -> V_583 ) ;
if ( V_90 ) {
F_22 ( L_244 ) ;
return V_90 ;
}
F_3 ( V_24 , L_245 ) ;
V_90 = F_86 ( V_2 , V_571 ,
V_581 -> V_584 ,
V_581 -> V_585 ) ;
if ( V_90 )
F_22 ( L_246 ) ;
else
F_3 ( V_24 , L_247 ) ;
return V_90 ;
}
static T_4
F_158 ( struct V_104 * V_104 , struct V_88 * V_89 ,
struct V_586 * V_587 )
{
T_4 V_410 ;
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
const struct V_53 * V_588 ;
struct V_161 V_162 ;
T_4 V_90 = - V_382 ;
const struct V_53 * V_306 ;
const struct V_69 * V_307 ;
struct V_237 V_238 ;
enum V_97 V_589 ;
struct V_590 V_591 ;
T_1 V_159 ;
F_3 ( V_24 , L_248 ,
V_587 -> V_243 . V_25 -> V_164 ,
V_587 -> V_243 . V_27 , V_587 -> V_243 . V_28 ,
V_587 -> V_246 , V_587 -> V_362 ) ;
F_3 ( V_24 , L_249 ,
V_587 -> V_169 , V_587 -> V_167 , V_587 -> V_273 ,
V_587 -> V_592 ) ;
V_589 = V_92 -> V_2 -> V_99 . V_98 ;
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
if ( V_587 -> V_169 == NULL || V_587 -> V_167 == 0 ) {
V_410 = V_593 + V_594 ;
V_588 = F_11 (
( T_2 * ) & V_587 -> V_581 . V_595 [ V_410 ] ,
V_587 -> V_581 . V_596 - V_410 ,
V_597 ) ;
if ( ! V_588 )
return - V_117 ;
memcpy ( V_162 . V_168 , V_588 -> V_86 , V_588 -> V_60 ) ;
V_162 . V_165 = F_16 ( V_588 -> V_60 ) ;
F_3 ( V_24 , L_250 , V_162 . V_168 ) ;
} else {
memcpy ( V_162 . V_168 , V_587 -> V_169 , V_587 -> V_167 ) ;
V_162 . V_165 = F_16 ( ( T_5 ) V_587 -> V_167 ) ;
}
F_30 ( V_92 , 0 ) ;
F_23 ( V_92 , false ) ;
V_306 = F_11 ( ( T_2 * ) V_587 -> V_581 . V_582 ,
V_587 -> V_581 . V_583 , V_310 ) ;
V_307 = F_13 ( ( T_2 * ) V_587 -> V_581 . V_582 ,
V_587 -> V_581 . V_583 ) ;
if ( ( V_307 != NULL || V_306 != NULL ) ) {
F_3 ( V_24 , L_251 ) ;
if ( V_307 != NULL ) {
V_90 = F_152 ( V_89 , V_307 , false ) ;
if ( V_90 < 0 )
goto exit;
} else {
V_90 = F_152 ( V_89 ,
(struct V_69 * ) V_306 , true ) ;
if ( V_90 < 0 )
goto exit;
}
} else {
F_3 ( V_24 , L_252 ) ;
F_150 ( V_92 ) ;
}
F_157 ( V_92 -> V_2 , & V_587 -> V_581 ) ;
V_159 = F_6 ( & V_120 -> V_18 , & V_587 -> V_243 ) ;
V_90 = F_24 ( V_92 , L_253 , V_159 ) ;
if ( V_90 < 0 ) {
F_22 ( L_254 , V_159 , V_90 ) ;
goto exit;
}
if ( V_587 -> V_246 ) {
V_90 = F_46 ( V_92 , V_250 ,
V_587 -> V_246 ) ;
if ( V_90 < 0 ) {
F_22 ( L_255 , V_90 ) ;
goto exit;
}
}
if ( V_587 -> V_362 ) {
V_90 = F_46 ( V_92 , V_598 ,
V_587 -> V_362 ) ;
if ( V_90 < 0 ) {
F_22 ( L_256 , V_90 ) ;
goto exit;
}
}
if ( V_589 == V_100 ) {
V_90 = F_46 ( V_92 , V_599 , 1 ) ;
if ( V_90 < 0 ) {
F_22 ( L_257 , V_90 ) ;
goto exit;
}
F_24 ( V_92 , L_258 , 0 ) ;
}
V_90 = F_46 ( V_92 , V_152 , 1 ) ;
if ( V_90 < 0 ) {
F_22 ( L_259 , V_90 ) ;
goto exit;
}
if ( V_589 == V_100 ) {
V_90 = F_46 ( V_92 , V_600 , 1 ) ;
if ( V_90 < 0 ) {
F_22 ( L_260 , V_90 ) ;
goto exit;
}
V_90 = F_46 ( V_92 , V_601 , 1 ) ;
if ( V_90 < 0 ) {
F_22 ( L_261 , V_90 ) ;
goto exit;
}
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
memcpy ( & V_238 . V_162 , & V_162 , sizeof( V_162 ) ) ;
V_90 = F_34 ( V_92 , V_258 ,
& V_238 , sizeof( V_238 ) ) ;
if ( V_90 < 0 ) {
F_22 ( L_262 , V_90 ) ;
goto exit;
}
F_3 ( V_24 , L_263 ) ;
} else {
V_90 = F_20 ( V_92 , L_264 , & V_162 ,
sizeof( V_162 ) ) ;
if ( V_90 < 0 ) {
F_22 ( L_265 , V_90 ) ;
goto exit;
}
V_591 . V_602 = F_16 ( V_92 -> V_445 ) ;
V_591 . V_93 = F_16 ( 1 ) ;
V_90 = F_53 ( V_92 , L_266 , & V_591 ,
sizeof( V_591 ) ) ;
if ( V_90 < 0 ) {
F_22 ( L_267 , V_90 ) ;
goto exit;
}
F_3 ( V_24 , L_268 ) ;
}
F_61 ( V_151 , & V_92 -> V_2 -> V_4 ) ;
F_45 ( V_603 , & V_92 -> V_2 -> V_4 ) ;
exit:
if ( V_90 ) {
F_30 ( V_92 , 1 ) ;
F_23 ( V_92 , true ) ;
}
return V_90 ;
}
static int F_159 ( struct V_104 * V_104 , struct V_88 * V_89 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_4 V_90 ;
struct V_590 V_591 ;
struct V_237 V_238 ;
F_3 ( V_24 , L_14 ) ;
if ( V_92 -> V_2 -> V_99 . V_98 == V_100 ) {
F_131 ( 400 ) ;
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_90 = F_34 ( V_92 , V_258 ,
& V_238 , sizeof( V_238 ) ) ;
if ( V_90 < 0 )
F_22 ( L_262 , V_90 ) ;
V_90 = F_46 ( V_92 , V_601 , 0 ) ;
if ( V_90 < 0 )
F_22 ( L_269 , V_90 ) ;
V_90 = F_46 ( V_92 , V_600 , 0 ) ;
if ( V_90 < 0 )
F_22 ( L_260 , V_90 ) ;
V_90 = F_46 ( V_92 , V_152 , 0 ) ;
if ( V_90 < 0 )
F_22 ( L_270 , V_90 ) ;
} else {
V_591 . V_602 = F_16 ( V_92 -> V_445 ) ;
V_591 . V_93 = F_16 ( 0 ) ;
V_90 = F_53 ( V_92 , L_266 , & V_591 ,
sizeof( V_591 ) ) ;
if ( V_90 < 0 )
F_22 ( L_267 , V_90 ) ;
}
F_30 ( V_92 , 1 ) ;
F_23 ( V_92 , true ) ;
F_45 ( V_151 , & V_92 -> V_2 -> V_4 ) ;
F_61 ( V_603 , & V_92 -> V_2 -> V_4 ) ;
return V_90 ;
}
static T_4
F_160 ( struct V_104 * V_104 , struct V_88 * V_89 ,
struct V_580 * V_604 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_4 V_90 ;
F_3 ( V_24 , L_14 ) ;
V_90 = F_157 ( V_92 -> V_2 , V_604 ) ;
return V_90 ;
}
static int
F_161 ( struct V_104 * V_104 , struct V_88 * V_89 ,
const T_2 * V_353 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_321 V_322 ;
struct V_91 * V_92 = F_21 ( V_89 ) ;
T_4 V_90 ;
if ( ! V_353 )
return - V_605 ;
F_3 ( V_24 , L_271 , V_353 ) ;
if ( V_92 -> V_2 == V_120 -> V_206 . V_207 [ V_208 ] . V_2 )
V_92 = V_120 -> V_206 . V_207 [ V_209 ] . V_2 -> V_92 ;
if ( ! F_1 ( V_92 -> V_2 ) )
return - V_214 ;
memcpy ( & V_322 . V_87 , V_353 , V_130 ) ;
V_322 . V_263 = F_16 ( V_606 ) ;
V_90 = F_34 ( V_92 , V_607 ,
& V_322 , sizeof( V_322 ) ) ;
if ( V_90 )
F_22 ( L_272 , V_90 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static void
F_162 ( struct V_104 * V_104 ,
struct V_103 * V_99 ,
T_1 V_608 , bool V_609 )
{
struct V_1 * V_2 ;
T_1 V_610 ;
F_3 ( V_24 , L_273 , V_608 , V_609 ) ;
V_610 = ( V_608 & V_611 ) >> 4 ;
V_2 = F_63 ( V_99 , struct V_1 , V_99 ) ;
if ( V_609 )
V_2 -> V_612 |= F_123 ( V_610 ) ;
else
V_2 -> V_612 &= ~ F_123 ( V_610 ) ;
}
static int
F_163 ( struct V_104 * V_104 , struct V_103 * V_99 ,
struct V_613 * V_107 , T_10 * V_352 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_52 * V_25 = V_107 -> V_25 ;
const T_2 * V_54 = V_107 -> V_54 ;
T_6 V_60 = V_107 -> V_60 ;
const struct V_614 * V_615 ;
struct V_1 * V_2 ;
T_4 V_90 = 0 ;
T_4 V_410 ;
T_4 V_245 ;
struct V_616 * V_617 ;
struct V_618 * V_619 ;
bool V_620 ;
T_4 V_621 ;
T_5 V_397 ;
F_3 ( V_24 , L_14 ) ;
* V_352 = 0 ;
V_615 = ( const struct V_614 * ) V_54 ;
if ( ! F_164 ( V_615 -> V_622 ) ) {
F_22 ( L_274 ) ;
return - V_382 ;
}
V_2 = F_63 ( V_99 , struct V_1 , V_99 ) ;
if ( F_165 ( V_615 -> V_622 ) ) {
V_410 = V_593 +
V_594 ;
V_245 = V_60 - V_410 ;
if ( V_2 == V_120 -> V_206 . V_207 [ V_209 ] . V_2 )
V_2 = V_120 -> V_206 . V_207 [ V_208 ] . V_2 ;
V_90 = F_86 ( V_2 ,
V_571 ,
& V_54 [ V_410 ] ,
V_245 ) ;
F_166 ( V_99 , * V_352 , V_54 , V_60 , true ,
V_177 ) ;
} else if ( F_167 ( V_615 -> V_622 ) ) {
V_619 = F_51 ( sizeof( * V_619 ) , V_177 ) ;
if ( V_619 == NULL ) {
F_22 ( L_275 ) ;
V_90 = - V_178 ;
goto exit;
}
V_617 = & V_619 -> V_617 ;
V_617 -> V_623 = F_16 ( * V_352 ) ;
memcpy ( & V_617 -> V_624 [ 0 ] , & V_615 -> V_624 [ 0 ] , V_130 ) ;
memcpy ( & V_619 -> V_129 [ 0 ] , & V_615 -> V_129 [ 0 ] , V_130 ) ;
V_617 -> V_60 = F_17 ( V_60 - V_593 ) ;
if ( V_25 )
V_397 = V_25 -> V_26 ;
else
F_103 ( V_2 -> V_92 , V_625 ,
& V_397 ) ;
V_621 = F_7 ( V_397 ) ;
V_619 -> V_253 = F_16 ( V_621 ) ;
memcpy ( V_617 -> V_86 , & V_54 [ V_593 ] ,
F_107 ( V_617 -> V_60 ) ) ;
F_3 ( V_24 , L_276 ,
* V_352 , F_107 ( V_617 -> V_60 ) , V_397 ) ;
V_620 = F_168 ( V_120 , F_68 ( V_120 ) ,
V_619 ) ;
F_166 ( V_99 , * V_352 , V_54 , V_60 , V_620 ,
V_177 ) ;
F_54 ( V_619 ) ;
} else {
F_3 ( V_24 , L_277 , V_615 -> V_622 ) ;
F_169 ( true , V_54 , V_60 , L_278 , V_60 ) ;
}
exit:
return V_90 ;
}
static int
F_170 ( struct V_104 * V_104 ,
struct V_103 * V_99 ,
T_10 V_352 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_1 * V_2 ;
int V_90 = 0 ;
F_3 ( V_24 , L_279 ) ;
V_2 = V_120 -> V_206 . V_207 [ V_208 ] . V_2 ;
if ( V_2 == NULL ) {
F_22 ( L_280 ) ;
V_90 = - V_390 ;
goto exit;
}
F_171 ( V_2 -> V_92 ) ;
exit:
return V_90 ;
}
static int F_172 ( struct V_104 * V_104 ,
struct V_103 * V_99 ,
enum V_626 V_627 ,
T_1 V_628 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_1 * V_2 ;
V_2 = F_63 ( V_99 , struct V_1 , V_99 ) ;
if ( V_627 != V_629 )
return - V_117 ;
F_45 ( V_204 , & V_120 -> V_143 ) ;
F_116 ( V_120 ) ;
return F_72 ( V_2 , V_630 , V_628 ) ;
}
static void F_173 ( struct V_104 * V_104 ,
struct V_103 * V_99 )
{
struct V_119 * V_120 = F_57 ( V_104 ) ;
struct V_1 * V_2 ;
V_2 = F_63 ( V_99 , struct V_1 , V_99 ) ;
F_72 ( V_2 , V_234 , 0 ) ;
F_61 ( V_204 , & V_120 -> V_143 ) ;
}
static int F_174 ( enum V_631 V_632 )
{
int V_485 ;
switch ( V_632 ) {
case V_633 :
V_485 = V_634 ;
break;
case V_635 :
V_485 = V_636 ;
break;
case V_637 :
V_485 = V_638 ;
break;
default:
F_22 ( L_281 , V_632 ) ;
V_485 = - V_113 ;
}
return V_485 ;
}
static int F_175 ( struct V_104 * V_104 ,
struct V_88 * V_89 , const T_2 * V_639 ,
enum V_631 V_632 )
{
struct V_91 * V_92 ;
struct V_640 V_604 ;
int V_485 = 0 ;
V_485 = F_174 ( V_632 ) ;
if ( V_485 < 0 )
return V_485 ;
V_92 = F_21 ( V_89 ) ;
memset ( & V_604 , 0 , sizeof( V_604 ) ) ;
V_604 . V_94 = ( T_2 ) V_485 ;
if ( V_639 )
memcpy ( V_604 . V_87 , V_639 , V_130 ) ;
V_485 = F_53 ( V_92 , L_282 ,
& V_604 , sizeof( V_604 ) ) ;
if ( V_485 < 0 )
F_22 ( L_283 , V_485 ) ;
return V_485 ;
}
static void F_176 ( struct V_104 * V_104 )
{
V_104 -> V_641 = V_642 ;
V_104 -> V_643 = V_642 ;
V_104 -> V_644 = V_645 ;
V_104 -> V_81 |= V_646 ;
}
static struct V_104 * F_177 ( struct V_647 * V_648 )
{
struct V_104 * V_104 ;
T_4 V_90 = 0 ;
V_104 = F_178 ( & V_649 , sizeof( struct V_119 ) ) ;
if ( ! V_104 ) {
F_22 ( L_284 ) ;
return F_28 ( - V_178 ) ;
}
F_179 ( V_104 , V_648 ) ;
V_104 -> V_650 = V_651 ;
V_104 -> V_652 = V_645 ;
V_104 -> V_653 = V_470 ;
V_104 -> V_448 = F_123 ( V_108 ) |
F_123 ( V_102 ) |
F_123 ( V_100 ) |
F_123 ( V_114 ) |
F_123 ( V_101 ) |
F_123 ( V_115 ) ;
V_104 -> V_654 = V_655 ;
V_104 -> V_656 = F_156 ( V_655 ) ;
V_104 -> V_408 [ V_46 ] = & V_657 ;
V_104 -> V_658 = V_659 ;
V_104 -> V_660 = V_661 ;
V_104 -> V_662 = F_156 ( V_661 ) ;
V_104 -> V_81 |= V_663 |
V_664 |
V_665 |
V_666 ;
if ( ! V_667 )
V_104 -> V_81 |= V_668 ;
V_104 -> V_669 = V_670 ;
V_104 -> V_671 = 5000 ;
F_176 ( V_104 ) ;
F_3 ( V_5 , L_285 ) ;
V_104 -> V_672 |= V_673 ;
F_180 ( V_104 , & V_674 ) ;
V_90 = F_181 ( V_104 ) ;
if ( V_90 < 0 ) {
F_22 ( L_286 , V_90 ) ;
F_182 ( V_104 ) ;
return F_28 ( V_90 ) ;
}
return V_104 ;
}
struct V_1 * F_183 ( struct V_119 * V_120 ,
enum V_97 type ,
bool V_675 )
{
struct V_1 * V_2 ;
F_3 ( V_24 , L_287 ,
sizeof( * V_2 ) ) ;
V_2 = F_51 ( sizeof( * V_2 ) , V_177 ) ;
if ( ! V_2 )
return F_28 ( - V_178 ) ;
V_2 -> V_99 . V_104 = V_120 -> V_104 ;
V_2 -> V_99 . V_98 = type ;
V_2 -> V_675 = V_675 ;
V_2 -> V_676 = - 1 ;
F_69 ( & V_2 -> V_236 ) ;
F_184 ( & V_2 -> V_415 , & V_120 -> V_677 ) ;
return V_2 ;
}
void F_185 ( struct V_1 * V_2 )
{
F_186 ( & V_2 -> V_415 ) ;
F_54 ( V_2 ) ;
}
void F_187 ( struct V_88 * V_89 )
{
struct V_1 * V_2 ;
struct V_91 * V_92 ;
V_92 = F_21 ( V_89 ) ;
V_2 = V_92 -> V_2 ;
F_185 ( V_2 ) ;
F_188 ( V_89 ) ;
}
static bool F_189 ( const struct V_437 * V_438 )
{
T_5 V_678 = V_438 -> V_478 ;
T_5 V_441 = V_438 -> V_441 ;
if ( V_678 == V_679 && V_441 == V_451 ) {
F_3 ( V_242 , L_288 ) ;
return true ;
}
return false ;
}
static bool F_190 ( const struct V_437 * V_438 )
{
T_5 V_678 = V_438 -> V_478 ;
T_1 V_81 = V_438 -> V_81 ;
if ( ( V_678 == V_680 ) || ( V_678 == V_681 ) ||
( V_678 == V_682 ) ||
( ( V_678 == V_683 ) && ( ! ( V_81 & V_684 ) ) ) ) {
F_3 ( V_242 , L_289 ) ;
return true ;
}
return false ;
}
static bool F_191 ( struct V_119 * V_120 ,
const struct V_437 * V_438 )
{
T_5 V_678 = V_438 -> V_478 ;
T_5 V_441 = V_438 -> V_441 ;
if ( V_678 == V_683 && V_441 == V_685 ) {
F_3 ( V_242 , L_290 ,
V_438 -> V_81 & V_684 ? L_291 : L_292 ) ;
return true ;
}
if ( V_678 == V_679 && V_441 != V_451 ) {
F_3 ( V_242 , L_293 ) ;
return true ;
}
return false ;
}
static void F_192 ( struct V_119 * V_120 )
{
struct V_686 * V_687 = F_193 ( V_120 ) ;
F_54 ( V_687 -> V_688 ) ;
V_687 -> V_688 = NULL ;
V_687 -> V_689 = 0 ;
F_54 ( V_687 -> V_690 ) ;
V_687 -> V_690 = NULL ;
V_687 -> V_691 = 0 ;
}
static T_4 F_194 ( struct V_119 * V_120 ,
struct V_91 * V_92 )
{
struct V_692 * V_693 ;
struct V_686 * V_687 = F_193 ( V_120 ) ;
T_5 V_694 ;
T_5 V_695 ;
T_4 V_90 = 0 ;
F_192 ( V_120 ) ;
V_90 = F_101 ( V_92 , L_294 ,
V_120 -> V_423 , V_696 ) ;
if ( V_90 ) {
F_22 ( L_295 , V_90 ) ;
return V_90 ;
}
V_693 =
(struct V_692 * ) V_120 -> V_423 ;
V_694 = F_102 ( V_693 -> V_694 ) ;
V_695 = F_102 ( V_693 -> V_695 ) ;
if ( V_694 ) {
V_90 = F_101 ( V_92 , L_296 ,
V_120 -> V_423 ,
V_696 ) ;
if ( V_90 ) {
F_22 ( L_297 , V_90 ) ;
return V_90 ;
}
V_687 -> V_689 = V_694 ;
V_687 -> V_688 =
F_195 ( V_120 -> V_423 , V_687 -> V_689 ,
V_177 ) ;
} else {
V_687 -> V_689 = 0 ;
V_687 -> V_688 = NULL ;
}
if ( V_695 ) {
V_90 = F_101 ( V_92 , L_298 ,
V_120 -> V_423 ,
V_696 ) ;
if ( V_90 ) {
F_22 ( L_299 , V_90 ) ;
return V_90 ;
}
V_687 -> V_691 = V_695 ;
V_687 -> V_690 =
F_195 ( V_120 -> V_423 , V_687 -> V_691 ,
V_177 ) ;
} else {
V_687 -> V_691 = 0 ;
V_687 -> V_690 = NULL ;
}
F_3 ( V_242 , L_300 ,
V_687 -> V_689 , V_687 -> V_691 ) ;
return V_90 ;
}
static T_4
F_196 ( struct V_119 * V_120 ,
struct V_88 * V_89 ,
const struct V_437 * V_438 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_230 * V_236 = & V_92 -> V_2 -> V_236 ;
struct V_686 * V_687 = F_193 ( V_120 ) ;
struct V_104 * V_104 = F_36 ( V_120 ) ;
struct V_52 * V_393 = NULL ;
struct V_396 * V_45 ;
struct V_391 * V_392 ;
struct V_21 V_20 ;
T_5 V_397 ;
T_4 V_90 = 0 ;
T_2 * V_54 ;
F_3 ( V_24 , L_14 ) ;
F_194 ( V_120 , V_92 ) ;
memcpy ( V_236 -> V_129 , V_438 -> V_697 , V_130 ) ;
F_115 ( V_120 , V_92 ) ;
V_54 = F_51 ( V_404 , V_177 ) ;
if ( V_54 == NULL ) {
V_90 = - V_178 ;
goto V_149;
}
* ( V_420 * ) V_54 = F_16 ( V_404 ) ;
V_90 = F_104 ( V_92 , V_421 ,
V_54 , V_404 ) ;
if ( V_90 )
goto V_149;
V_392 = (struct V_391 * ) ( V_54 + 4 ) ;
V_20 . V_51 = F_107 ( V_392 -> V_159 ) ;
V_120 -> V_18 . V_406 ( & V_20 ) ;
if ( V_20 . V_45 == V_47 )
V_45 = V_104 -> V_408 [ V_46 ] ;
else
V_45 = V_104 -> V_408 [ V_48 ] ;
V_397 = F_108 ( V_20 . V_29 , V_45 -> V_45 ) ;
V_393 = F_109 ( V_104 , V_397 ) ;
V_149:
F_54 ( V_54 ) ;
F_197 ( V_89 , V_393 , ( T_2 * ) V_236 -> V_129 ,
V_687 -> V_688 , V_687 -> V_689 ,
V_687 -> V_690 , V_687 -> V_691 , V_177 ) ;
F_3 ( V_242 , L_301 ) ;
F_45 ( V_232 , & V_92 -> V_2 -> V_4 ) ;
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_198 ( struct V_119 * V_120 ,
struct V_88 * V_89 , const struct V_437 * V_438 ,
bool V_698 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_230 * V_236 = & V_92 -> V_2 -> V_236 ;
struct V_686 * V_687 = F_193 ( V_120 ) ;
T_4 V_90 = 0 ;
F_3 ( V_24 , L_14 ) ;
if ( F_38 ( V_205 ,
& V_92 -> V_2 -> V_4 ) ) {
if ( V_698 ) {
F_194 ( V_120 , V_92 ) ;
memcpy ( V_236 -> V_129 , V_438 -> V_697 , V_130 ) ;
F_115 ( V_120 , V_92 ) ;
F_45 ( V_232 ,
& V_92 -> V_2 -> V_4 ) ;
}
F_199 ( V_89 ,
( T_2 * ) V_236 -> V_129 ,
V_687 -> V_688 ,
V_687 -> V_689 ,
V_687 -> V_690 ,
V_687 -> V_691 ,
V_698 ? V_699 :
V_700 ,
V_177 ) ;
F_3 ( V_242 , L_302 ,
V_698 ? L_303 : L_211 ) ;
}
F_3 ( V_24 , L_31 ) ;
return V_90 ;
}
static T_4
F_200 ( struct V_119 * V_120 ,
struct V_88 * V_89 ,
const struct V_437 * V_438 , void * V_86 )
{
static int V_701 ;
T_5 V_678 = V_438 -> V_478 ;
T_5 V_702 = V_438 -> V_702 ;
struct V_354 V_355 ;
F_3 ( V_242 , L_304 , V_678 , V_702 ) ;
if ( V_678 == V_683 && V_702 == V_703 &&
V_89 != F_68 ( V_120 ) ) {
F_3 ( V_242 , L_305 ) ;
F_201 ( & V_120 -> V_704 ) ;
return 0 ;
}
if ( ( ( V_678 == V_705 ) || ( V_678 == V_706 ) ) &&
( V_702 == V_451 ) ) {
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
V_355 . V_363 = V_707 ;
if ( ! V_86 ) {
F_22 ( L_306 ) ;
return - V_117 ;
}
V_355 . V_708 = V_86 ;
V_355 . V_709 = V_438 -> V_710 ;
V_701 ++ ;
V_355 . V_701 = V_701 ;
F_202 ( V_89 , V_438 -> V_697 , & V_355 , V_177 ) ;
} else if ( ( V_678 == V_682 ) ||
( V_678 == V_681 ) ||
( V_678 == V_680 ) ) {
F_203 ( V_89 , V_438 -> V_697 , V_177 ) ;
}
return 0 ;
}
static T_4
F_204 ( struct V_91 * V_92 ,
const struct V_437 * V_438 , void * V_86 )
{
struct V_119 * V_120 = V_92 -> V_439 -> V_440 ;
struct V_88 * V_89 = V_92 -> V_89 ;
struct V_230 * V_236 = & V_92 -> V_2 -> V_236 ;
struct V_52 * V_25 ;
T_4 V_90 = 0 ;
if ( F_25 ( V_92 -> V_2 ) ) {
V_90 = F_200 ( V_120 , V_89 , V_438 , V_86 ) ;
} else if ( F_189 ( V_438 ) ) {
F_3 ( V_242 , L_307 ) ;
if ( F_26 ( V_92 -> V_2 ) ) {
V_25 = F_109 ( V_120 -> V_104 , V_120 -> V_253 ) ;
memcpy ( V_236 -> V_129 , V_438 -> V_697 , V_130 ) ;
F_114 ( V_120 , V_89 , V_438 -> V_697 ) ;
F_205 ( V_89 , V_438 -> V_697 , V_25 , V_177 ) ;
F_61 ( V_205 ,
& V_92 -> V_2 -> V_4 ) ;
F_45 ( V_232 ,
& V_92 -> V_2 -> V_4 ) ;
} else
F_198 ( V_120 , V_89 , V_438 , true ) ;
} else if ( F_190 ( V_438 ) ) {
F_3 ( V_242 , L_308 ) ;
if ( ! F_26 ( V_92 -> V_2 ) ) {
F_198 ( V_120 , V_89 , V_438 , false ) ;
}
F_70 ( V_92 -> V_2 ) ;
F_69 ( F_76 ( V_89 ) ) ;
if ( V_89 != F_68 ( V_120 ) )
F_201 ( & V_120 -> V_704 ) ;
} else if ( F_191 ( V_120 , V_438 ) ) {
if ( F_26 ( V_92 -> V_2 ) )
F_61 ( V_205 ,
& V_92 -> V_2 -> V_4 ) ;
else
F_198 ( V_120 , V_89 , V_438 , false ) ;
}
return V_90 ;
}
static T_4
F_206 ( struct V_91 * V_92 ,
const struct V_437 * V_438 , void * V_86 )
{
struct V_119 * V_120 = V_92 -> V_439 -> V_440 ;
T_4 V_90 = 0 ;
T_5 V_678 = V_438 -> V_478 ;
T_5 V_441 = V_438 -> V_441 ;
if ( V_678 == V_711 && V_441 == V_451 ) {
if ( F_2 ( V_232 , & V_92 -> V_2 -> V_4 ) )
F_196 ( V_120 , V_92 -> V_89 , V_438 ) ;
else
F_198 ( V_120 , V_92 -> V_89 , V_438 , true ) ;
}
return V_90 ;
}
static T_4
F_207 ( struct V_91 * V_92 ,
const struct V_437 * V_438 , void * V_86 )
{
T_1 V_81 = V_438 -> V_81 ;
enum V_712 V_713 ;
if ( V_81 & V_714 )
V_713 = V_715 ;
else
V_713 = V_716 ;
F_208 ( V_92 -> V_89 , ( T_2 * ) & V_438 -> V_697 , V_713 , - 1 ,
NULL , V_177 ) ;
return 0 ;
}
static T_4 F_209 ( struct V_91 * V_92 ,
const struct V_437 * V_438 , void * V_86 )
{
struct V_119 * V_120 = V_92 -> V_439 -> V_440 ;
struct V_717 * V_718 = (struct V_717 * ) V_86 ;
struct V_719 * V_678 = & V_120 -> V_720 ;
struct V_1 * V_2 ;
F_3 ( V_24 , L_309 ,
V_718 -> V_172 , V_718 -> V_81 , V_718 -> V_721 ,
V_718 -> V_445 ) ;
F_210 ( & V_678 -> V_722 ) ;
V_678 -> V_172 = V_718 -> V_172 ;
V_2 = V_678 -> V_2 ;
switch ( V_718 -> V_172 ) {
case V_723 :
if ( ! V_120 -> V_720 . V_2 ) {
F_211 ( & V_678 -> V_722 ) ;
return - V_724 ;
}
V_92 -> V_2 = V_2 ;
V_2 -> V_92 = V_92 ;
if ( V_92 -> V_89 ) {
V_2 -> V_99 . V_144 = V_92 -> V_89 ;
V_92 -> V_89 -> V_154 = & V_2 -> V_99 ;
F_212 ( V_92 -> V_89 , F_213 ( V_120 -> V_104 ) ) ;
}
F_211 ( & V_678 -> V_722 ) ;
F_214 ( & V_678 -> V_725 ) ;
return 0 ;
case V_726 :
F_211 ( & V_678 -> V_722 ) ;
if ( F_41 ( V_120 ) )
F_214 ( & V_678 -> V_725 ) ;
return 0 ;
case V_727 :
F_211 ( & V_678 -> V_722 ) ;
F_214 ( & V_678 -> V_725 ) ;
return 0 ;
default:
F_211 ( & V_678 -> V_722 ) ;
break;
}
return - V_117 ;
}
static void F_215 ( struct V_728 * V_224 )
{
V_224 -> V_216 = ( T_5 ) - 1 ;
V_224 -> V_215 = ( T_5 ) - 1 ;
V_224 -> V_229 = ( T_5 ) - 1 ;
V_224 -> V_227 = ( T_5 ) - 1 ;
V_224 -> V_333 = - 1 ;
}
static void F_216 ( struct V_119 * V_120 )
{
F_125 ( V_120 -> V_452 , V_683 ,
F_204 ) ;
F_125 ( V_120 -> V_452 , V_681 ,
F_204 ) ;
F_125 ( V_120 -> V_452 , V_680 ,
F_204 ) ;
F_125 ( V_120 -> V_452 , V_682 ,
F_204 ) ;
F_125 ( V_120 -> V_452 , V_705 ,
F_204 ) ;
F_125 ( V_120 -> V_452 , V_706 ,
F_204 ) ;
F_125 ( V_120 -> V_452 , V_711 ,
F_206 ) ;
F_125 ( V_120 -> V_452 , V_729 ,
F_207 ) ;
F_125 ( V_120 -> V_452 , V_679 ,
F_204 ) ;
F_125 ( V_120 -> V_452 , V_730 ,
F_139 ) ;
F_125 ( V_120 -> V_452 , V_731 ,
F_209 ) ;
F_125 ( V_120 -> V_452 , V_732 ,
V_733 ) ;
F_125 ( V_120 -> V_452 , V_734 ,
V_735 ) ;
F_125 ( V_120 -> V_452 , V_736 ,
V_737 ) ;
F_125 ( V_120 -> V_452 , V_738 ,
V_739 ) ;
F_125 ( V_120 -> V_452 , V_740 ,
V_739 ) ;
}
static void F_217 ( struct V_119 * V_120 )
{
F_54 ( V_120 -> V_224 ) ;
V_120 -> V_224 = NULL ;
F_54 ( V_120 -> V_741 ) ;
V_120 -> V_741 = NULL ;
F_54 ( V_120 -> V_423 ) ;
V_120 -> V_423 = NULL ;
F_54 ( V_120 -> V_459 ) ;
V_120 -> V_459 = NULL ;
}
static T_4 F_218 ( struct V_119 * V_120 )
{
V_120 -> V_224 = F_51 ( sizeof( * V_120 -> V_224 ) , V_177 ) ;
if ( ! V_120 -> V_224 )
goto V_742;
V_120 -> V_741 = F_51 ( V_179 , V_177 ) ;
if ( ! V_120 -> V_741 )
goto V_742;
V_120 -> V_423 = F_51 ( V_424 , V_177 ) ;
if ( ! V_120 -> V_423 )
goto V_742;
V_120 -> V_459 = F_51 ( sizeof( * V_120 -> V_459 ) , V_177 ) ;
if ( ! V_120 -> V_459 )
goto V_742;
return 0 ;
V_742:
F_217 ( V_120 ) ;
return - V_178 ;
}
static T_4 F_219 ( struct V_119 * V_120 )
{
T_4 V_90 = 0 ;
V_120 -> V_126 = NULL ;
V_120 -> V_386 = true ;
V_120 -> V_189 = true ;
V_120 -> V_743 = false ;
V_90 = F_218 ( V_120 ) ;
if ( V_90 )
return V_90 ;
F_216 ( V_120 ) ;
F_220 ( & V_120 -> V_744 ) ;
F_124 ( V_120 ) ;
F_215 ( V_120 -> V_224 ) ;
F_221 ( & V_120 -> V_704 ) ;
return V_90 ;
}
static void F_222 ( struct V_119 * V_120 )
{
V_120 -> V_743 = false ;
F_116 ( V_120 ) ;
F_217 ( V_120 ) ;
}
static void F_223 ( struct V_719 * V_678 )
{
F_224 ( & V_678 -> V_725 ) ;
F_220 ( & V_678 -> V_722 ) ;
}
static int F_225 ( struct V_91 * V_92 )
{
struct V_745 V_746 ;
T_5 V_263 ;
int V_90 ;
V_263 = V_747 ;
V_90 = F_91 ( V_92 , L_310 , & V_263 ) ;
if ( ! V_90 ) {
V_746 . V_45 = F_16 ( V_748 ) ;
V_746 . V_749 = F_16 ( V_750 ) ;
V_90 = F_53 ( V_92 , L_310 , & V_746 ,
sizeof( V_746 ) ) ;
} else {
F_3 ( V_5 , L_311 ) ;
V_263 = V_751 ;
V_90 = F_24 ( V_92 , L_312 , V_263 ) ;
}
return V_90 ;
}
struct V_119 * F_226 ( struct V_752 * V_439 ,
struct V_647 * V_753 )
{
struct V_88 * V_89 = V_439 -> V_754 [ 0 ] -> V_89 ;
struct V_119 * V_120 ;
struct V_104 * V_104 ;
struct V_1 * V_2 ;
struct V_91 * V_92 ;
T_4 V_90 = 0 ;
T_4 V_755 ;
if ( ! V_89 ) {
F_22 ( L_313 ) ;
return NULL ;
}
V_92 = F_21 ( V_89 ) ;
V_104 = F_177 ( V_753 ) ;
if ( F_227 ( V_104 ) )
return NULL ;
V_120 = F_40 ( V_104 ) ;
V_120 -> V_104 = V_104 ;
V_120 -> V_452 = V_439 ;
F_223 ( & V_120 -> V_720 ) ;
F_228 ( & V_120 -> V_677 ) ;
V_2 = F_183 ( V_120 , V_108 , false ) ;
if ( F_227 ( V_2 ) ) {
F_182 ( V_104 ) ;
return NULL ;
}
V_2 -> V_92 = V_92 ;
V_2 -> V_99 . V_144 = V_89 ;
V_89 -> V_154 = & V_2 -> V_99 ;
F_212 ( V_89 , F_213 ( V_120 -> V_104 ) ) ;
V_90 = F_219 ( V_120 ) ;
if ( V_90 ) {
F_22 ( L_314 , V_90 ) ;
goto V_756;
}
V_92 -> V_2 = V_2 ;
V_90 = F_229 ( V_120 ) ;
if ( V_90 ) {
F_22 ( L_315 , V_90 ) ;
goto V_757;
}
V_90 = F_230 ( V_120 ) ;
if ( V_90 ) {
F_22 ( L_316 , V_90 ) ;
F_231 ( & V_120 -> V_206 ) ;
goto V_757;
}
if ( V_104 -> V_408 [ V_46 ] -> V_758 . V_759 &
V_760 ) {
V_90 = F_225 ( V_92 ) ;
if ( ! V_90 )
V_90 = F_24 ( V_92 , L_317 ,
V_761 ) ;
}
V_90 = F_24 ( V_92 , L_318 , 1 ) ;
if ( V_90 ) {
F_3 ( V_5 , L_319 , V_90 ) ;
V_104 -> V_81 &= ~ V_666 ;
}
V_90 = F_103 ( V_92 , V_762 ,
& V_755 ) ;
if ( V_90 ) {
F_22 ( L_320 , V_90 ) ;
goto V_757;
}
V_120 -> V_18 . V_755 = ( T_2 ) V_755 ;
F_232 ( & V_120 -> V_18 ) ;
return V_120 ;
V_757:
F_222 ( V_120 ) ;
V_756:
F_185 ( V_2 ) ;
return NULL ;
}
void F_233 ( struct V_119 * V_120 )
{
if ( ! V_120 )
return;
F_8 ( ! F_234 ( & V_120 -> V_677 ) ) ;
F_235 ( V_120 -> V_104 ) ;
F_236 ( V_120 ) ;
F_222 ( V_120 ) ;
F_182 ( V_120 -> V_104 ) ;
}
static T_4
F_237 ( struct V_91 * V_92 , T_5 V_763 )
{
T_4 V_90 = 0 ;
V_420 V_764 [ 2 ] ;
V_420 V_765 [ 2 ] ;
if ( V_667 ) {
V_90 = F_24 ( V_92 , L_321 , V_763 ) ;
if ( V_90 ) {
F_22 ( L_322 , V_90 ) ;
goto V_766;
}
}
F_3 ( V_5 , L_323 ,
V_667 ? L_324 : L_325 ) ;
V_90 = F_24 ( V_92 , L_326 , ! ! ( V_667 ) ) ;
if ( V_90 ) {
F_22 ( L_327 , V_90 ) ;
goto V_766;
}
V_764 [ 0 ] = F_16 ( V_767 ) ;
V_764 [ 1 ] = F_16 ( V_768 ) ;
V_90 = F_34 ( V_92 , V_769 ,
( void * ) V_764 , sizeof( V_764 ) ) ;
if ( V_90 ) {
F_22 ( L_328 , V_90 ) ;
goto V_766;
}
V_765 [ 0 ] = F_16 ( V_770 ) ;
V_765 [ 1 ] = F_16 ( V_768 ) ;
V_90 = F_34 ( V_92 , V_771 ,
( void * ) V_765 , sizeof( V_765 ) ) ;
if ( V_90 ) {
F_22 ( L_329 , V_90 ) ;
goto V_766;
}
V_766:
return V_90 ;
}
static T_4
F_238 ( struct V_91 * V_92 , T_4 V_772 ,
T_4 V_773 , T_4 V_774 )
{
T_4 V_90 = 0 ;
V_90 = F_46 ( V_92 , V_775 ,
V_772 ) ;
if ( V_90 ) {
if ( V_90 == - V_113 )
F_3 ( V_5 , L_330 ) ;
else
F_22 ( L_331 , V_90 ) ;
goto V_776;
}
V_90 = F_46 ( V_92 , V_777 ,
V_773 ) ;
if ( V_90 ) {
if ( V_90 == - V_113 )
F_3 ( V_5 , L_332 ) ;
else
F_22 ( L_333 , V_90 ) ;
goto V_776;
}
V_90 = F_46 ( V_92 , V_778 ,
V_774 ) ;
if ( V_90 ) {
if ( V_90 == - V_113 )
F_3 ( V_5 , L_334 ) ;
else
F_22 ( L_335 , V_90 ) ;
goto V_776;
}
V_776:
return V_90 ;
}
static T_4 F_239 ( struct V_119 * V_120 ,
T_5 V_749 [] )
{
struct V_91 * V_92 = F_21 ( F_68 ( V_120 ) ) ;
struct V_52 * V_779 ;
struct V_780 * V_415 ;
struct V_21 V_20 ;
T_4 V_90 ;
T_2 * V_781 ;
T_5 V_158 , V_460 ;
T_5 V_782 ;
enum V_783 V_45 ;
T_5 V_253 ;
T_5 * V_784 ;
T_5 V_79 ;
T_5 V_785 ;
bool V_786 ;
T_5 V_787 ;
V_781 = F_51 ( V_179 , V_177 ) ;
if ( V_781 == NULL )
return - V_178 ;
V_415 = (struct V_780 * ) V_781 ;
V_90 = F_101 ( V_92 , L_336 , V_781 ,
V_179 ) ;
if ( V_90 ) {
F_22 ( L_337 , V_90 ) ;
goto exit;
}
V_657 . V_157 = 0 ;
V_788 . V_157 = 0 ;
V_782 = F_102 ( V_415 -> V_192 ) ;
for ( V_158 = 0 ; V_158 < V_782 ; V_158 ++ ) {
V_20 . V_51 = ( T_1 ) F_102 ( V_415 -> V_789 [ V_158 ] ) ;
V_120 -> V_18 . V_406 ( & V_20 ) ;
if ( V_20 . V_45 == V_47 ) {
V_779 = V_790 ;
V_787 = F_156 ( V_790 ) ;
V_784 = & V_657 . V_157 ;
V_45 = V_46 ;
} else if ( V_20 . V_45 == V_49 ) {
V_779 = V_791 ;
V_787 = F_156 ( V_791 ) ;
V_784 = & V_788 . V_157 ;
V_45 = V_48 ;
} else {
F_22 ( L_338 , V_20 . V_51 ) ;
continue;
}
if ( ! ( V_749 [ V_45 ] & V_792 ) &&
V_20 . V_31 == V_34 )
continue;
if ( ! ( V_749 [ V_45 ] & V_793 ) &&
V_20 . V_31 == V_39 )
continue;
V_786 = false ;
for ( V_460 = 0 ; ( V_460 < * V_784 && ( * V_784 < V_787 ) ) ; V_460 ++ ) {
if ( V_779 [ V_460 ] . V_164 == V_20 . V_29 ) {
V_786 = true ;
break;
}
}
if ( V_786 )
V_79 = V_460 ;
else
V_79 = * V_784 ;
if ( V_79 < V_787 ) {
V_779 [ V_79 ] . V_26 =
F_108 ( V_20 . V_29 , V_45 ) ;
V_779 [ V_79 ] . V_164 = V_20 . V_29 ;
if ( V_20 . V_31 == V_39 ) {
V_779 [ V_79 ] . V_81 &=
~ V_794 ;
} else if ( V_20 . V_31 == V_34 ) {
V_785 = V_779 [ V_79 ] . V_81 &
V_484 ;
if ( V_20 . V_35 == V_36 ) {
if ( V_785 == V_484 )
V_779 [ V_79 ] . V_81 &=
~ V_484 ;
V_779 [ V_79 ] . V_81 |=
V_795 ;
} else {
V_779 [ V_79 ] . V_81 &=
~ V_484 ;
if ( V_785 == V_484 )
V_779 [ V_79 ] . V_81 |=
V_796 ;
}
} else {
V_779 [ V_79 ] . V_81 =
V_484 |
V_794 ;
V_20 . V_31 = V_32 ;
V_120 -> V_18 . V_50 ( & V_20 ) ;
V_253 = V_20 . V_51 ;
V_90 = F_81 ( V_92 ,
L_339 ,
& V_253 ) ;
if ( ! V_90 ) {
if ( V_253 & V_797 )
V_779 [ V_79 ] . V_81 |=
( V_798 |
V_799 ) ;
if ( V_253 & V_800 )
V_779 [ V_79 ] . V_81 |=
V_799 ;
}
}
if ( ! V_786 )
( * V_784 ) ++ ;
}
}
exit:
F_54 ( V_781 ) ;
return V_90 ;
}
static void F_240 ( struct V_91 * V_92 , T_5 V_749 [] )
{
T_5 V_45 , V_801 ;
int V_90 ;
V_45 = V_748 ;
V_90 = F_91 ( V_92 , L_310 , & V_45 ) ;
if ( ! V_90 ) {
V_749 [ V_46 ] = V_45 ;
V_45 = V_747 ;
V_90 = F_91 ( V_92 , L_310 , & V_45 ) ;
if ( ! V_90 ) {
V_749 [ V_48 ] = V_45 ;
return;
}
F_8 ( 1 ) ;
return;
}
F_3 ( V_5 , L_340 ) ;
V_801 = 0 ;
V_90 = F_91 ( V_92 , L_312 , & V_801 ) ;
if ( V_90 )
V_801 = V_802 ;
switch ( V_801 ) {
case V_751 :
V_749 [ V_46 ] |= V_792 ;
case V_803 :
V_749 [ V_48 ] |= V_792 ;
case V_802 :
V_749 [ V_46 ] |= V_804 ;
V_749 [ V_48 ] |= V_804 ;
break;
default:
F_22 ( L_341 ) ;
}
}
static void F_241 ( struct V_396 * V_45 ,
T_5 V_749 [ 2 ] , T_5 V_805 )
{
V_45 -> V_758 . V_806 = true ;
if ( V_749 [ V_45 -> V_45 ] & V_792 ) {
V_45 -> V_758 . V_759 |= V_807 ;
V_45 -> V_758 . V_759 |= V_760 ;
}
V_45 -> V_758 . V_759 |= V_808 ;
V_45 -> V_758 . V_759 |= V_809 ;
V_45 -> V_758 . V_810 = V_811 ;
V_45 -> V_758 . V_812 = V_813 ;
memset ( V_45 -> V_758 . V_814 . V_815 , 0xff , V_805 ) ;
V_45 -> V_758 . V_814 . V_816 = V_817 ;
}
static T_11 F_242 ( T_5 V_805 , enum V_818 V_819 )
{
T_1 V_820 ;
int V_158 ;
for ( V_158 = 0 , V_820 = 0xFFFF ; V_158 < V_805 ; V_158 ++ )
V_820 = ( V_820 << 2 ) | V_819 ;
return F_17 ( V_820 ) ;
}
static void F_243 ( struct V_396 * V_45 ,
T_5 V_749 [ 2 ] , T_5 V_805 )
{
T_11 V_820 ;
if ( V_45 -> V_45 == V_46 )
return;
V_45 -> V_821 . V_822 = true ;
V_45 -> V_821 . V_759 |= V_823 ;
if ( V_749 [ V_45 -> V_45 ] & V_824 ) {
V_45 -> V_821 . V_759 |= V_825 ;
V_45 -> V_821 . V_759 |= V_826 ;
}
V_820 = F_242 ( V_805 , V_827 ) ;
V_45 -> V_821 . V_828 . V_829 = V_820 ;
V_45 -> V_821 . V_828 . V_830 = V_820 ;
}
static T_4 F_244 ( struct V_119 * V_120 )
{
struct V_91 * V_92 = F_21 ( F_68 ( V_120 ) ) ;
struct V_104 * V_104 ;
T_4 V_831 ;
T_5 V_832 [ 3 ] ;
T_5 V_833 = 0 ;
T_5 V_834 = 0 ;
T_5 V_749 [ 2 ] = { 0 , 0 } ;
T_5 V_835 ;
T_5 V_805 ;
T_9 V_836 ;
T_4 V_90 ;
T_5 V_837 ;
T_4 V_158 ;
struct V_396 * V_408 [ 2 ] = { NULL , NULL } ;
struct V_396 * V_45 ;
V_90 = F_104 ( V_92 , V_838 ,
& V_831 , sizeof( V_831 ) ) ;
if ( V_90 ) {
F_22 ( L_342 , V_90 ) ;
return V_90 ;
}
V_836 = ( ( char * ) & V_831 ) [ 0 ] ;
F_3 ( V_5 , L_343 , V_836 ) ;
V_90 = F_104 ( V_92 , V_839 ,
& V_832 , sizeof( V_832 ) ) ;
if ( V_90 ) {
F_22 ( L_344 , V_90 ) ;
return V_90 ;
}
F_3 ( V_5 , L_345 ,
V_832 [ 0 ] , V_832 [ 1 ] , V_832 [ 2 ] ) ;
( void ) F_91 ( V_92 , L_346 , & V_834 ) ;
V_90 = F_91 ( V_92 , L_347 , & V_833 ) ;
if ( V_90 ) {
F_22 ( L_348 , V_90 ) ;
} else {
F_240 ( V_92 , V_749 ) ;
}
F_3 ( V_5 , L_349 ,
V_833 , V_834 , V_749 [ V_46 ] ,
V_749 [ V_48 ] ) ;
V_90 = F_91 ( V_92 , L_350 , & V_835 ) ;
if ( V_90 ) {
F_22 ( L_351 , V_90 ) ;
V_805 = 1 ;
} else {
for ( V_805 = 0 ; V_835 ; V_805 ++ )
V_835 = V_835 & ( V_835 - 1 ) ;
}
F_3 ( V_5 , L_352 , V_805 ) ;
V_90 = F_239 ( V_120 , V_749 ) ;
if ( V_90 ) {
F_22 ( L_353 , V_90 ) ;
return V_90 ;
}
V_837 = V_832 [ 0 ] ;
for ( V_158 = 1 ; V_158 <= V_837 && V_158 < F_156 ( V_832 ) ; V_158 ++ ) {
V_45 = NULL ;
if ( ( V_832 [ V_158 ] == V_747 ) &&
( V_788 . V_157 > 0 ) )
V_45 = & V_788 ;
else if ( ( V_832 [ V_158 ] == V_748 ) &&
( V_657 . V_157 > 0 ) )
V_45 = & V_657 ;
else
continue;
if ( V_833 )
F_241 ( V_45 , V_749 , V_805 ) ;
if ( V_834 )
F_243 ( V_45 , V_749 , V_805 ) ;
V_408 [ V_45 -> V_45 ] = V_45 ;
}
V_104 = F_36 ( V_120 ) ;
V_104 -> V_408 [ V_46 ] = V_408 [ V_46 ] ;
V_104 -> V_408 [ V_48 ] = V_408 [ V_48 ] ;
F_180 ( V_104 , & V_674 ) ;
return V_90 ;
}
static T_4 F_245 ( struct V_119 * V_120 )
{
return F_244 ( V_120 ) ;
}
static T_4 F_246 ( struct V_119 * V_120 )
{
struct V_88 * V_89 ;
struct V_103 * V_99 ;
struct V_91 * V_92 ;
T_4 V_840 ;
T_4 V_90 = 0 ;
if ( V_120 -> V_743 )
return V_90 ;
V_89 = F_68 ( V_120 ) ;
V_99 = V_89 -> V_154 ;
V_92 = F_21 ( V_89 ) ;
F_46 ( V_92 , V_601 , 0 ) ;
F_238 ( V_92 , V_841 ,
V_842 , V_843 ) ;
V_840 = V_120 -> V_386 ? V_387 : V_388 ;
V_90 = F_46 ( V_92 , V_389 , V_840 ) ;
if ( V_90 )
goto V_844;
F_3 ( V_5 , L_354 ,
( V_840 ? L_159 : L_160 ) ) ;
V_90 = F_237 ( V_92 , V_845 ) ;
if ( V_90 )
goto V_844;
V_90 = F_43 ( V_99 -> V_104 , V_89 , V_99 -> V_98 ,
NULL , NULL ) ;
if ( V_90 )
goto V_844;
V_90 = F_245 ( V_120 ) ;
if ( V_90 )
goto V_844;
F_23 ( V_92 , true ) ;
V_120 -> V_743 = true ;
V_844:
return V_90 ;
}
static T_4 F_247 ( struct V_91 * V_92 )
{
F_45 ( V_3 , & V_92 -> V_2 -> V_4 ) ;
return F_246 ( V_92 -> V_439 -> V_440 ) ;
}
static T_4 F_248 ( struct V_91 * V_92 )
{
struct V_119 * V_120 = V_92 -> V_439 -> V_440 ;
if ( F_1 ( V_92 -> V_2 ) ) {
F_70 ( V_92 -> V_2 ) ;
F_128 ( 500 ) ;
}
F_116 ( V_120 ) ;
F_61 ( V_3 , & V_92 -> V_2 -> V_4 ) ;
return 0 ;
}
T_4 F_249 ( struct V_88 * V_89 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_119 * V_120 = V_92 -> V_439 -> V_440 ;
T_4 V_90 = 0 ;
F_210 ( & V_120 -> V_744 ) ;
V_90 = F_247 ( V_92 ) ;
F_211 ( & V_120 -> V_744 ) ;
return V_90 ;
}
T_4 F_250 ( struct V_88 * V_89 )
{
struct V_91 * V_92 = F_21 ( V_89 ) ;
struct V_119 * V_120 = V_92 -> V_439 -> V_440 ;
T_4 V_90 = 0 ;
F_210 ( & V_120 -> V_744 ) ;
V_90 = F_248 ( V_92 ) ;
F_211 ( & V_120 -> V_744 ) ;
return V_90 ;
}
enum V_97 F_251 ( struct V_91 * V_92 )
{
struct V_103 * V_99 = & V_92 -> V_2 -> V_99 ;
return V_99 -> V_98 ;
}
T_5 F_252 ( struct V_119 * V_120 , unsigned long V_846 )
{
struct V_1 * V_2 ;
bool V_335 = 0 ;
F_134 (vif, &cfg->vif_list, list) {
if ( F_2 ( V_846 , & V_2 -> V_4 ) )
V_335 ++ ;
}
return V_335 ;
}
static inline bool F_253 ( struct V_719 * V_678 ,
T_2 V_172 )
{
T_2 V_847 ;
F_210 ( & V_678 -> V_722 ) ;
V_847 = V_678 -> V_172 ;
F_211 ( & V_678 -> V_722 ) ;
return V_847 == V_172 ;
}
void F_254 ( struct V_119 * V_120 ,
struct V_1 * V_2 )
{
struct V_719 * V_678 = & V_120 -> V_720 ;
F_210 ( & V_678 -> V_722 ) ;
V_678 -> V_2 = V_2 ;
V_678 -> V_172 = 0 ;
F_211 ( & V_678 -> V_722 ) ;
}
bool F_41 ( struct V_119 * V_120 )
{
struct V_719 * V_678 = & V_120 -> V_720 ;
bool V_848 ;
F_210 ( & V_678 -> V_722 ) ;
V_848 = V_678 -> V_2 != NULL ;
F_211 ( & V_678 -> V_722 ) ;
return V_848 ;
}
int F_255 ( struct V_119 * V_120 ,
T_2 V_172 , T_12 V_384 )
{
struct V_719 * V_678 = & V_120 -> V_720 ;
return F_256 ( V_678 -> V_725 ,
F_253 ( V_678 , V_172 ) , V_384 ) ;
}
