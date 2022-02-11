int
F_1 (
unsigned int V_1 ,
T_1 * V_2 )
{
int V_3 ;
T_2 V_4 ;
struct V_5 * V_5 ;
struct V_6 V_7 = { NULL } ;
struct V_8 V_8 ;
int error ;
struct V_9 * V_10 ;
if ( V_1 == V_11 ) {
V_7 = F_2 ( V_2 -> V_6 ) ;
if ( ! V_7 . V_12 )
return - V_13 ;
V_5 = F_3 ( V_7 . V_12 ) ;
} else {
error = F_4 ( ( const char V_14 * ) V_2 -> V_8 , & V_8 ) ;
if ( error )
return error ;
V_5 = F_5 ( V_8 . V_15 ) ;
}
V_10 = F_6 ( V_5 ) ;
error = - V_16 ;
if ( V_5 -> V_17 -> V_18 != V_19 )
goto V_20;
error = - V_13 ;
if ( ! F_7 ( V_5 -> V_21 ) &&
! F_8 ( V_5 -> V_21 ) &&
! F_9 ( V_5 -> V_21 ) )
goto V_20;
memcpy ( & V_4 . V_22 , V_10 -> V_23 -> V_24 , sizeof( V_25 ) ) ;
if ( V_1 == V_26 ) {
memset ( & V_4 . V_27 , 0 , sizeof( V_4 . V_27 ) ) ;
V_3 = sizeof( V_25 ) ;
} else {
V_4 . V_27 . V_28 = sizeof( V_29 ) -
sizeof( V_4 . V_27 . V_28 ) ;
V_4 . V_27 . V_30 = 0 ;
V_4 . V_27 . V_31 = V_5 -> V_32 ;
V_4 . V_27 . V_33 = V_10 -> V_34 ;
V_3 = sizeof( T_2 ) ;
}
error = - V_35 ;
if ( F_10 ( V_2 -> V_36 , & V_4 , V_3 ) ||
F_10 ( V_2 -> V_37 , & V_3 , sizeof( V_38 ) ) )
goto V_20;
error = 0 ;
V_20:
if ( V_1 == V_11 )
F_11 ( V_7 ) ;
else
F_12 ( & V_8 ) ;
return error ;
}
STATIC int
F_13 (
void * V_39 ,
struct V_15 * V_15 )
{
return 1 ;
}
struct V_15 *
F_14 (
struct V_12 * V_40 ,
void V_14 * V_41 ,
T_3 V_42 )
{
T_2 V_4 ;
struct V_43 V_44 ;
if ( ! F_8 ( F_3 ( V_40 ) -> V_21 ) )
return F_15 ( - V_45 ) ;
if ( V_42 != sizeof( T_2 ) )
return F_15 ( - V_16 ) ;
if ( F_16 ( & V_4 , V_41 , V_42 ) )
return F_15 ( - V_35 ) ;
if ( V_4 . V_27 . V_28 !=
sizeof( V_4 . V_27 ) - sizeof( V_4 . V_27 . V_28 ) )
return F_15 ( - V_16 ) ;
memset ( & V_44 , 0 , sizeof( struct V_44 ) ) ;
V_44 . V_46 = V_4 . V_27 . V_33 ;
V_44 . V_47 = V_4 . V_27 . V_31 ;
return F_17 ( V_40 -> V_48 . V_49 , (struct V_44 * ) & V_44 , 3 ,
V_50 | V_51 ,
F_13 , NULL ) ;
}
STATIC struct V_15 *
F_18 (
struct V_12 * V_40 ,
T_1 * V_2 )
{
return F_14 ( V_40 , V_2 -> V_52 , V_2 -> V_53 ) ;
}
int
F_19 (
struct V_12 * V_40 ,
T_1 * V_2 )
{
const struct V_54 * V_54 = F_20 () ;
int error ;
int V_6 ;
int V_55 ;
struct V_12 * V_56 ;
struct V_5 * V_5 ;
struct V_15 * V_15 ;
T_4 V_57 ;
struct V_8 V_8 ;
if ( ! F_21 ( V_58 ) )
return - V_59 ;
V_15 = F_18 ( V_40 , V_2 ) ;
if ( F_22 ( V_15 ) )
return F_23 ( V_15 ) ;
V_5 = F_5 ( V_15 ) ;
if ( ! ( F_7 ( V_5 -> V_21 ) || F_8 ( V_5 -> V_21 ) ) ) {
error = - V_59 ;
goto V_60;
}
#if V_61 != 32
V_2 -> V_62 |= V_63 ;
#endif
V_55 = V_2 -> V_62 ;
V_57 = F_24 ( V_55 ) ;
if ( ( ! ( V_55 & V_64 ) || ( V_55 & V_65 ) ) &&
( V_57 & V_66 ) && F_25 ( V_5 ) ) {
error = - V_59 ;
goto V_60;
}
if ( ( V_57 & V_66 ) && F_26 ( V_5 ) ) {
error = - V_59 ;
goto V_60;
}
if ( F_8 ( V_5 -> V_21 ) && ( V_57 & V_66 ) ) {
error = - V_67 ;
goto V_60;
}
V_6 = F_27 ( 0 ) ;
if ( V_6 < 0 ) {
error = V_6 ;
goto V_60;
}
V_8 . V_49 = V_40 -> V_48 . V_49 ;
V_8 . V_15 = V_15 ;
V_56 = F_28 ( & V_8 , V_2 -> V_62 , V_54 ) ;
F_29 ( V_15 ) ;
if ( F_22 ( V_56 ) ) {
F_30 ( V_6 ) ;
return F_23 ( V_56 ) ;
}
if ( F_7 ( V_5 -> V_21 ) ) {
V_56 -> V_68 |= V_69 ;
V_56 -> V_70 |= V_71 ;
}
F_31 ( V_6 , V_56 ) ;
return V_6 ;
V_60:
F_29 ( V_15 ) ;
return error ;
}
int
F_32 (
struct V_12 * V_40 ,
T_1 * V_2 )
{
struct V_15 * V_15 ;
T_5 V_72 ;
int error ;
if ( ! F_21 ( V_58 ) )
return - V_59 ;
V_15 = F_18 ( V_40 , V_2 ) ;
if ( F_22 ( V_15 ) )
return F_23 ( V_15 ) ;
if ( ! F_33 ( V_15 ) ) {
error = - V_16 ;
goto V_60;
}
if ( F_16 ( & V_72 , V_2 -> V_37 , sizeof( T_5 ) ) ) {
error = - V_35 ;
goto V_60;
}
error = F_34 ( V_15 , V_2 -> V_36 , V_72 ) ;
V_60:
F_29 ( V_15 ) ;
return error ;
}
int
F_35 (
T_6 * V_10 ,
T_7 V_73 ,
T_8 V_74 )
{
T_9 * V_75 = V_10 -> V_23 ;
T_10 * V_76 ;
int error ;
if ( ! F_21 ( V_58 ) )
return - V_59 ;
if ( F_36 ( V_75 ) )
return - V_77 ;
error = F_37 ( V_75 , & F_38 ( V_75 ) -> V_78 , 0 , 0 , 0 , & V_76 ) ;
if ( error )
return error ;
F_39 ( V_10 , V_79 ) ;
F_40 ( V_76 , V_10 , V_79 ) ;
V_10 -> V_80 . V_81 = V_73 ;
V_10 -> V_80 . V_82 = V_74 ;
F_41 ( V_76 , V_10 , V_83 ) ;
error = F_42 ( V_76 ) ;
return error ;
}
STATIC int
F_43 (
struct V_12 * V_40 ,
void V_14 * V_84 )
{
int error ;
struct V_85 V_86 ;
T_11 V_87 ;
struct V_15 * V_15 ;
if ( ! F_21 ( V_88 ) )
return - V_59 ;
if ( F_16 ( & V_87 , V_84 , sizeof( T_11 ) ) )
return - V_35 ;
error = F_44 ( V_40 ) ;
if ( error )
return error ;
V_15 = F_18 ( V_40 , & V_87 . V_2 ) ;
if ( F_22 ( V_15 ) ) {
F_45 ( V_40 ) ;
return F_23 ( V_15 ) ;
}
if ( F_26 ( F_5 ( V_15 ) ) || F_25 ( F_5 ( V_15 ) ) ) {
error = - V_59 ;
goto V_89;
}
if ( F_16 ( & V_86 , V_87 . V_90 , sizeof( V_86 ) ) ) {
error = - V_35 ;
goto V_89;
}
error = F_35 ( F_6 ( F_5 ( V_15 ) ) , V_86 . V_91 ,
V_86 . V_92 ) ;
V_89:
F_45 ( V_40 ) ;
F_29 ( V_15 ) ;
return error ;
}
STATIC int
F_46 (
struct V_12 * V_40 ,
void V_14 * V_84 )
{
int error = - V_93 ;
T_12 * V_94 ;
struct V_95 V_14 * V_96 = V_84 ;
T_13 V_97 ;
struct V_15 * V_15 ;
char * V_98 ;
if ( ! F_21 ( V_58 ) )
return - V_59 ;
if ( F_16 ( & V_97 , V_84 , sizeof( T_13 ) ) )
return - V_35 ;
if ( V_97 . V_99 < sizeof( struct V_100 ) ||
V_97 . V_99 > V_101 )
return - V_16 ;
if ( V_97 . V_102 & ~ ( V_103 | V_104 ) )
return - V_16 ;
V_15 = F_18 ( V_40 , & V_97 . V_2 ) ;
if ( F_22 ( V_15 ) )
return F_23 ( V_15 ) ;
V_98 = F_47 ( V_97 . V_99 , V_105 ) ;
if ( ! V_98 )
goto V_60;
V_94 = ( T_12 * ) & V_97 . V_106 ;
error = F_48 ( F_6 ( F_5 ( V_15 ) ) , V_98 , V_97 . V_99 ,
V_97 . V_102 , V_94 ) ;
if ( error )
goto V_107;
if ( F_10 ( & V_96 -> V_106 , V_94 , sizeof( T_12 ) ) ) {
error = - V_35 ;
goto V_107;
}
if ( F_10 ( V_97 . V_108 , V_98 , V_97 . V_99 ) )
error = - V_35 ;
V_107:
F_49 ( V_98 ) ;
V_60:
F_29 ( V_15 ) ;
return error ;
}
int
F_50 (
struct V_5 * V_5 ,
unsigned char * V_109 ,
unsigned char V_14 * V_110 ,
T_14 * V_111 ,
T_14 V_102 )
{
unsigned char * V_98 ;
int error = - V_35 ;
if ( * V_111 > V_112 )
return - V_16 ;
V_98 = F_47 ( * V_111 , V_105 ) ;
if ( ! V_98 )
return - V_93 ;
error = F_51 ( F_6 ( V_5 ) , V_109 , V_98 , ( int * ) V_111 , V_102 ) ;
if ( error )
goto V_107;
if ( F_10 ( V_110 , V_98 , * V_111 ) )
error = - V_35 ;
V_107:
F_49 ( V_98 ) ;
return error ;
}
int
F_52 (
struct V_5 * V_5 ,
unsigned char * V_109 ,
const unsigned char V_14 * V_110 ,
T_14 V_111 ,
T_14 V_102 )
{
unsigned char * V_98 ;
int error ;
if ( F_26 ( V_5 ) || F_25 ( V_5 ) )
return - V_59 ;
if ( V_111 > V_112 )
return - V_16 ;
V_98 = F_53 ( V_110 , V_111 ) ;
if ( F_22 ( V_98 ) )
return F_23 ( V_98 ) ;
error = F_54 ( F_6 ( V_5 ) , V_109 , V_98 , V_111 , V_102 ) ;
if ( ! error )
F_55 ( V_5 , V_109 , V_102 ) ;
F_56 ( V_98 ) ;
return error ;
}
int
F_57 (
struct V_5 * V_5 ,
unsigned char * V_109 ,
T_14 V_102 )
{
int error ;
if ( F_26 ( V_5 ) || F_25 ( V_5 ) )
return - V_59 ;
error = F_58 ( F_6 ( V_5 ) , V_109 , V_102 ) ;
if ( ! error )
F_55 ( V_5 , V_109 , V_102 ) ;
return error ;
}
STATIC int
F_59 (
struct V_12 * V_40 ,
void V_14 * V_84 )
{
int error ;
T_15 * V_113 ;
T_16 V_114 ;
struct V_15 * V_15 ;
unsigned int V_115 , V_116 ;
unsigned char * V_117 ;
if ( ! F_21 ( V_58 ) )
return - V_59 ;
if ( F_16 ( & V_114 , V_84 , sizeof( T_16 ) ) )
return - V_35 ;
if ( V_114 . V_118 >= V_119 / sizeof( T_15 ) )
return - V_120 ;
V_15 = F_18 ( V_40 , & V_114 . V_2 ) ;
if ( F_22 ( V_15 ) )
return F_23 ( V_15 ) ;
error = - V_120 ;
V_116 = V_114 . V_118 * sizeof( T_15 ) ;
if ( ! V_116 || V_116 > 16 * V_121 )
goto V_60;
V_113 = F_53 ( V_114 . V_113 , V_116 ) ;
if ( F_22 ( V_113 ) ) {
error = F_23 ( V_113 ) ;
goto V_60;
}
error = - V_93 ;
V_117 = F_60 ( V_122 , V_123 ) ;
if ( ! V_117 )
goto V_124;
error = 0 ;
for ( V_115 = 0 ; V_115 < V_114 . V_118 ; V_115 ++ ) {
V_113 [ V_115 ] . V_125 = F_61 ( ( char * ) V_117 ,
V_113 [ V_115 ] . V_126 , V_122 ) ;
if ( V_113 [ V_115 ] . V_125 == 0 || V_113 [ V_115 ] . V_125 == V_122 )
error = - V_127 ;
if ( V_113 [ V_115 ] . V_125 < 0 )
break;
switch ( V_113 [ V_115 ] . V_128 ) {
case V_129 :
V_113 [ V_115 ] . V_125 = F_50 (
F_5 ( V_15 ) , V_117 ,
V_113 [ V_115 ] . V_130 , & V_113 [ V_115 ] . V_131 ,
V_113 [ V_115 ] . V_132 ) ;
break;
case V_133 :
V_113 [ V_115 ] . V_125 = F_44 ( V_40 ) ;
if ( V_113 [ V_115 ] . V_125 )
break;
V_113 [ V_115 ] . V_125 = F_52 (
F_5 ( V_15 ) , V_117 ,
V_113 [ V_115 ] . V_130 , V_113 [ V_115 ] . V_131 ,
V_113 [ V_115 ] . V_132 ) ;
F_45 ( V_40 ) ;
break;
case V_134 :
V_113 [ V_115 ] . V_125 = F_44 ( V_40 ) ;
if ( V_113 [ V_115 ] . V_125 )
break;
V_113 [ V_115 ] . V_125 = F_57 (
F_5 ( V_15 ) , V_117 ,
V_113 [ V_115 ] . V_132 ) ;
F_45 ( V_40 ) ;
break;
default:
V_113 [ V_115 ] . V_125 = - V_16 ;
}
}
if ( F_10 ( V_114 . V_113 , V_113 , V_116 ) )
error = - V_35 ;
F_56 ( V_117 ) ;
V_124:
F_56 ( V_113 ) ;
V_60:
F_29 ( V_15 ) ;
return error ;
}
int
F_62 (
struct V_12 * V_56 ,
unsigned int V_1 ,
T_17 * V_135 )
{
struct V_5 * V_5 = F_3 ( V_56 ) ;
struct V_9 * V_10 = F_6 ( V_5 ) ;
struct V_136 V_136 ;
enum V_137 V_102 = 0 ;
T_18 V_138 = V_139 ;
int error ;
if ( ! F_63 ( & V_10 -> V_23 -> V_140 ) &&
! F_21 ( V_58 ) )
return - V_59 ;
if ( V_5 -> V_141 & ( V_142 | V_143 ) )
return - V_59 ;
if ( ! ( V_56 -> V_70 & V_66 ) )
return - V_13 ;
if ( ! F_7 ( V_5 -> V_21 ) )
return - V_16 ;
if ( V_56 -> V_68 & V_144 )
V_102 |= V_145 ;
if ( V_56 -> V_70 & V_71 )
V_102 |= V_146 ;
error = F_44 ( V_56 ) ;
if ( error )
return error ;
F_39 ( V_10 , V_138 ) ;
error = F_64 ( V_5 , & V_138 ) ;
if ( error )
goto V_147;
F_39 ( V_10 , V_148 ) ;
V_138 |= V_148 ;
switch ( V_135 -> V_149 ) {
case 0 :
break;
case 1 :
V_135 -> V_150 += V_56 -> V_151 ;
break;
case 2 :
V_135 -> V_150 += F_65 ( V_10 ) ;
break;
default:
error = - V_16 ;
goto V_147;
}
switch ( V_1 ) {
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
if ( V_135 -> V_157 <= 0 ) {
error = - V_16 ;
goto V_147;
}
break;
default:
V_135 -> V_157 = 0 ;
break;
}
if ( V_135 -> V_150 < 0 ||
V_135 -> V_150 > V_5 -> V_17 -> V_158 ||
V_135 -> V_150 + V_135 -> V_157 < 0 ||
V_135 -> V_150 + V_135 -> V_157 >= V_5 -> V_17 -> V_158 ) {
error = - V_16 ;
goto V_147;
}
switch ( V_1 ) {
case V_152 :
V_102 |= V_159 ;
error = F_66 ( V_10 , V_135 -> V_150 , V_135 -> V_157 ) ;
break;
case V_153 :
case V_154 :
V_102 |= V_159 ;
error = F_67 ( V_10 , V_135 -> V_150 , V_135 -> V_157 ,
V_160 ) ;
break;
case V_155 :
case V_156 :
error = F_68 ( V_10 , V_135 -> V_150 , V_135 -> V_157 ) ;
break;
case V_161 :
case V_162 :
case V_163 :
case V_164 :
V_102 |= V_165 ;
if ( V_135 -> V_150 > F_65 ( V_10 ) ) {
error = F_67 ( V_10 , F_65 ( V_10 ) ,
V_135 -> V_150 - F_65 ( V_10 ) , 0 ) ;
if ( error )
goto V_147;
}
V_136 . V_166 = V_167 ;
V_136 . V_168 = V_135 -> V_150 ;
error = F_69 ( F_70 ( V_56 ) , & V_136 ) ;
break;
default:
ASSERT ( 0 ) ;
error = - V_16 ;
}
if ( error )
goto V_147;
error = F_71 ( V_10 , V_102 ) ;
V_147:
F_72 ( V_10 , V_138 ) ;
F_45 ( V_56 ) ;
return error ;
}
STATIC int
F_73 (
T_9 * V_75 ,
unsigned int V_1 ,
void V_14 * V_84 )
{
T_19 V_169 ;
int V_170 ;
T_20 V_171 ;
int V_172 ;
int error ;
if ( ! F_21 ( V_58 ) )
return - V_59 ;
if ( F_36 ( V_75 ) )
return - V_77 ;
if ( F_16 ( & V_169 , V_84 , sizeof( T_19 ) ) )
return - V_35 ;
if ( F_16 ( & V_171 , V_169 . V_173 , sizeof( V_174 ) ) )
return - V_35 ;
if ( ( V_170 = V_169 . V_175 ) <= 0 )
return - V_16 ;
if ( V_169 . V_176 == NULL )
return - V_16 ;
if ( V_1 == V_177 )
error = F_74 ( V_75 , & V_171 , & V_170 ,
V_169 . V_176 , V_178 ) ;
else if ( V_1 == V_179 )
error = F_75 ( V_75 , V_171 , V_169 . V_176 ,
sizeof( V_180 ) , NULL , & V_172 ) ;
else
error = F_76 ( V_75 , & V_171 , & V_170 , F_75 ,
sizeof( V_180 ) , V_169 . V_176 ,
& V_172 ) ;
if ( error )
return error ;
if ( V_169 . V_181 != NULL ) {
if ( F_10 ( V_169 . V_173 , & V_171 ,
sizeof( T_20 ) ) )
return - V_35 ;
if ( F_10 ( V_169 . V_181 , & V_170 , sizeof( V_170 ) ) )
return - V_35 ;
}
return 0 ;
}
STATIC int
F_77 (
T_9 * V_75 ,
void V_14 * V_84 )
{
T_21 V_182 ;
int error ;
error = F_78 ( V_75 , & V_182 , 3 ) ;
if ( error )
return error ;
if ( F_10 ( V_84 , & V_182 , sizeof( V_183 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_79 (
T_9 * V_75 ,
void V_14 * V_84 )
{
T_21 V_182 ;
int error ;
error = F_78 ( V_75 , & V_182 , 4 ) ;
if ( error )
return error ;
if ( F_10 ( V_84 , & V_182 , sizeof( V_182 ) ) )
return - V_35 ;
return 0 ;
}
STATIC unsigned int
F_80 (
unsigned int V_102 ,
unsigned int V_184 )
{
unsigned int V_185 = V_184 ;
if ( V_102 & V_186 )
V_185 |= V_187 ;
else
V_185 &= ~ V_187 ;
if ( V_102 & V_188 )
V_185 |= V_189 ;
else
V_185 &= ~ V_189 ;
if ( V_102 & V_190 )
V_185 |= V_191 ;
else
V_185 &= ~ V_191 ;
if ( V_102 & V_192 )
V_185 |= V_193 ;
else
V_185 &= ~ V_193 ;
if ( V_102 & V_194 )
V_185 |= V_195 ;
else
V_185 &= ~ V_195 ;
return V_185 ;
}
STATIC unsigned int
F_81 (
T_22 V_196 )
{
unsigned int V_102 = 0 ;
if ( V_196 & V_197 )
V_102 |= V_186 ;
if ( V_196 & V_198 )
V_102 |= V_188 ;
if ( V_196 & V_199 )
V_102 |= V_190 ;
if ( V_196 & V_200 )
V_102 |= V_192 ;
if ( V_196 & V_201 )
V_102 |= V_194 ;
return V_102 ;
}
STATIC int
F_82 (
T_6 * V_10 ,
int V_202 ,
void V_14 * V_84 )
{
struct V_203 V_204 ;
memset ( & V_204 , 0 , sizeof( struct V_203 ) ) ;
F_39 ( V_10 , V_205 ) ;
V_204 . V_206 = F_83 ( V_10 ) ;
V_204 . V_207 = V_10 -> V_80 . V_208 << V_10 -> V_23 -> V_140 . V_209 ;
V_204 . V_210 = V_10 -> V_80 . V_211 <<
V_10 -> V_23 -> V_140 . V_209 ;
V_204 . V_212 = F_84 ( V_10 ) ;
if ( V_202 ) {
if ( V_10 -> V_213 ) {
if ( V_10 -> V_213 -> V_214 & V_215 )
V_204 . V_216 = F_85 ( V_10 -> V_213 ) ;
else
V_204 . V_216 = V_10 -> V_80 . V_217 ;
} else
V_204 . V_216 = 0 ;
} else {
if ( V_10 -> V_218 . V_214 & V_215 )
V_204 . V_216 = F_85 ( & V_10 -> V_218 ) ;
else
V_204 . V_216 = V_10 -> V_80 . V_219 ;
}
F_72 ( V_10 , V_205 ) ;
if ( F_10 ( V_84 , & V_204 , sizeof( V_204 ) ) )
return - V_35 ;
return 0 ;
}
STATIC void
F_86 (
struct V_9 * V_10 ,
unsigned int V_185 )
{
unsigned int V_196 ;
T_23 V_220 ;
V_196 = ( V_10 -> V_80 . V_196 & V_221 ) ;
if ( V_185 & V_187 )
V_196 |= V_197 ;
if ( V_185 & V_189 )
V_196 |= V_198 ;
if ( V_185 & V_191 )
V_196 |= V_199 ;
if ( V_185 & V_193 )
V_196 |= V_200 ;
if ( V_185 & V_195 )
V_196 |= V_201 ;
if ( V_185 & V_222 )
V_196 |= V_223 ;
if ( V_185 & V_224 )
V_196 |= V_225 ;
if ( F_8 ( F_87 ( V_10 ) -> V_21 ) ) {
if ( V_185 & V_226 )
V_196 |= V_227 ;
if ( V_185 & V_228 )
V_196 |= V_229 ;
if ( V_185 & V_230 )
V_196 |= V_231 ;
if ( V_185 & V_232 )
V_196 |= V_233 ;
} else if ( F_7 ( F_87 ( V_10 ) -> V_21 ) ) {
if ( V_185 & V_234 )
V_196 |= V_235 ;
if ( V_185 & V_236 )
V_196 |= V_237 ;
}
V_10 -> V_80 . V_196 = V_196 ;
if ( V_10 -> V_80 . V_238 < 3 )
return;
V_220 = ( V_10 -> V_80 . V_220 & V_239 ) ;
if ( V_185 & V_240 )
V_220 |= V_241 ;
if ( V_185 & V_242 )
V_220 |= V_243 ;
V_10 -> V_80 . V_220 = V_220 ;
}
STATIC void
F_88 (
struct V_9 * V_10 )
{
struct V_5 * V_5 = F_87 ( V_10 ) ;
unsigned int V_185 = F_83 ( V_10 ) ;
if ( V_185 & V_187 )
V_5 -> V_141 |= V_142 ;
else
V_5 -> V_141 &= ~ V_142 ;
if ( V_185 & V_189 )
V_5 -> V_141 |= V_143 ;
else
V_5 -> V_141 &= ~ V_143 ;
if ( V_185 & V_191 )
V_5 -> V_141 |= V_244 ;
else
V_5 -> V_141 &= ~ V_244 ;
if ( V_185 & V_193 )
V_5 -> V_141 |= V_245 ;
else
V_5 -> V_141 &= ~ V_245 ;
if ( V_185 & V_240 )
V_5 -> V_141 |= V_246 ;
else
V_5 -> V_141 &= ~ V_246 ;
}
static int
F_89 (
struct V_247 * V_76 ,
struct V_9 * V_10 ,
struct V_203 * V_204 )
{
struct V_248 * V_75 = V_10 -> V_23 ;
if ( ( V_10 -> V_80 . V_219 || V_10 -> V_249 ) &&
F_90 ( V_10 ) != ( V_204 -> V_206 & V_234 ) )
return - V_16 ;
if ( V_204 -> V_206 & V_234 ) {
if ( V_75 -> V_140 . V_250 == 0 || V_75 -> V_140 . V_251 == 0 ||
( V_10 -> V_80 . V_208 % V_75 -> V_140 . V_251 ) )
return - V_16 ;
}
if ( ( V_204 -> V_206 & V_234 ) && F_91 ( V_10 ) )
V_10 -> V_80 . V_220 &= ~ V_239 ;
if ( ( V_204 -> V_206 & V_240 ) && F_91 ( V_10 ) )
return - V_16 ;
if ( ( ( V_10 -> V_80 . V_196 & ( V_197 | V_198 ) ) ||
( V_204 -> V_206 & ( V_187 | V_189 ) ) ) &&
! F_21 ( V_252 ) )
return - V_59 ;
F_86 ( V_10 , V_204 -> V_206 ) ;
F_88 ( V_10 ) ;
F_92 ( V_76 , V_10 , V_253 ) ;
F_41 ( V_76 , V_10 , V_83 ) ;
F_93 ( V_75 , V_254 ) ;
return 0 ;
}
static int
F_94 (
struct V_9 * V_10 ,
struct V_203 * V_204 ,
int * V_255 )
{
struct V_5 * V_5 = F_87 ( V_10 ) ;
int error ;
* V_255 = 0 ;
if ( V_204 -> V_206 & V_240 ) {
if ( ! ( F_7 ( V_5 -> V_21 ) || F_8 ( V_5 -> V_21 ) ) )
return - V_16 ;
if ( V_10 -> V_23 -> V_140 . V_256 != V_121 )
return - V_16 ;
}
if ( ( V_204 -> V_206 & V_240 ) && F_95 ( V_5 ) )
return 0 ;
if ( ! ( V_204 -> V_206 & V_240 ) && ! F_95 ( V_5 ) )
return 0 ;
F_39 ( V_10 , V_148 | V_139 ) ;
error = F_96 ( V_5 -> V_257 ) ;
if ( error )
goto V_147;
error = F_97 ( V_5 -> V_257 ) ;
if ( error )
goto V_147;
* V_255 = V_148 | V_139 ;
return 0 ;
V_147:
F_72 ( V_10 , V_148 | V_139 ) ;
return error ;
}
static struct V_247 *
F_98 (
struct V_9 * V_10 ,
int V_255 )
{
struct V_248 * V_75 = V_10 -> V_23 ;
struct V_247 * V_76 ;
int error = - V_258 ;
if ( V_75 -> V_259 & V_260 )
goto V_147;
error = - V_77 ;
if ( F_36 ( V_75 ) )
goto V_147;
error = F_37 ( V_75 , & F_38 ( V_75 ) -> V_78 , 0 , 0 , 0 , & V_76 ) ;
if ( error )
return F_15 ( error ) ;
F_39 ( V_10 , V_79 ) ;
F_40 ( V_76 , V_10 , V_79 | V_255 ) ;
V_255 = 0 ;
if ( ! F_99 ( F_87 ( V_10 ) ) ) {
error = - V_59 ;
goto V_261;
}
if ( V_75 -> V_259 & V_262 )
F_100 ( V_76 ) ;
return V_76 ;
V_261:
F_101 ( V_76 ) ;
V_147:
if ( V_255 )
F_72 ( V_10 , V_255 ) ;
return F_15 ( error ) ;
}
static int
F_102 (
struct V_9 * V_10 ,
struct V_203 * V_204 )
{
struct V_248 * V_75 = V_10 -> V_23 ;
if ( ( V_204 -> V_206 & V_236 ) && ! F_7 ( F_87 ( V_10 ) -> V_21 ) )
return - V_16 ;
if ( ( V_204 -> V_206 & V_230 ) &&
! F_8 ( F_87 ( V_10 ) -> V_21 ) )
return - V_16 ;
if ( F_7 ( F_87 ( V_10 ) -> V_21 ) && V_10 -> V_80 . V_219 &&
( ( V_10 -> V_80 . V_208 << V_75 -> V_140 . V_209 ) != V_204 -> V_207 ) )
return - V_16 ;
if ( V_204 -> V_207 != 0 ) {
T_24 V_116 ;
T_25 V_263 ;
V_263 = F_103 ( V_75 , V_204 -> V_207 ) ;
if ( V_263 > V_264 )
return - V_16 ;
if ( F_90 ( V_10 ) ||
( V_204 -> V_206 & V_234 ) ) {
V_116 = V_75 -> V_140 . V_251 << V_75 -> V_140 . V_209 ;
} else {
V_116 = V_75 -> V_140 . V_256 ;
if ( V_263 > V_75 -> V_140 . V_265 / 2 )
return - V_16 ;
}
if ( V_204 -> V_207 % V_116 )
return - V_16 ;
} else
V_204 -> V_206 &= ~ ( V_236 | V_230 ) ;
return 0 ;
}
static int
F_104 (
struct V_9 * V_10 ,
struct V_203 * V_204 )
{
struct V_248 * V_75 = V_10 -> V_23 ;
if ( ! ( V_204 -> V_206 & V_242 ) )
return 0 ;
if ( ! F_105 ( & V_10 -> V_23 -> V_140 ) ||
V_10 -> V_80 . V_238 != 3 )
return - V_16 ;
if ( ! F_7 ( F_87 ( V_10 ) -> V_21 ) && ! F_8 ( F_87 ( V_10 ) -> V_21 ) )
return - V_16 ;
if ( V_204 -> V_210 != 0 ) {
T_24 V_116 ;
T_25 V_266 ;
V_266 = F_103 ( V_75 , V_204 -> V_210 ) ;
if ( V_266 > V_264 )
return - V_16 ;
V_116 = V_75 -> V_140 . V_256 ;
if ( V_266 > V_75 -> V_140 . V_265 / 2 )
return - V_16 ;
if ( V_204 -> V_210 % V_116 )
return - V_16 ;
} else
V_204 -> V_206 &= ~ V_242 ;
return 0 ;
}
static int
F_106 (
struct V_9 * V_10 ,
struct V_203 * V_204 )
{
if ( V_204 -> V_212 > ( T_22 ) - 1 &&
! F_107 ( & V_10 -> V_23 -> V_140 ) )
return - V_16 ;
if ( F_108 () == & V_267 )
return 0 ;
if ( F_84 ( V_10 ) != V_204 -> V_212 )
return - V_16 ;
if ( ( V_204 -> V_206 & V_232 ) !=
( V_10 -> V_80 . V_196 & V_233 ) )
return - V_16 ;
return 0 ;
}
STATIC int
F_109 (
T_6 * V_10 ,
struct V_203 * V_204 )
{
struct V_248 * V_75 = V_10 -> V_23 ;
struct V_247 * V_76 ;
struct V_268 * V_269 = NULL ;
struct V_268 * V_270 = NULL ;
struct V_268 * V_271 = NULL ;
int V_272 ;
int V_255 = 0 ;
F_110 ( V_10 ) ;
V_272 = F_106 ( V_10 , V_204 ) ;
if ( V_272 )
return V_272 ;
if ( F_111 ( V_75 ) ) {
V_272 = F_112 ( V_10 , V_10 -> V_80 . V_273 ,
V_10 -> V_80 . V_274 , V_204 -> V_212 ,
V_275 , & V_269 , NULL , & V_270 ) ;
if ( V_272 )
return V_272 ;
}
V_272 = F_94 ( V_10 , V_204 , & V_255 ) ;
if ( V_272 )
goto V_276;
V_76 = F_98 ( V_10 , V_255 ) ;
if ( F_22 ( V_76 ) ) {
V_272 = F_23 ( V_76 ) ;
goto V_276;
}
if ( F_113 ( V_75 ) && F_114 ( V_75 ) &&
F_84 ( V_10 ) != V_204 -> V_212 ) {
V_272 = F_115 ( V_76 , V_10 , V_269 , NULL , V_270 ,
F_21 ( V_277 ) ? V_278 : 0 ) ;
if ( V_272 )
goto V_279;
}
V_272 = F_102 ( V_10 , V_204 ) ;
if ( V_272 )
goto V_279;
V_272 = F_104 ( V_10 , V_204 ) ;
if ( V_272 )
goto V_279;
V_272 = F_89 ( V_76 , V_10 , V_204 ) ;
if ( V_272 )
goto V_279;
if ( ( F_87 ( V_10 ) -> V_21 & ( V_280 | V_281 ) ) &&
! F_116 ( F_87 ( V_10 ) , V_282 ) )
F_87 ( V_10 ) -> V_21 &= ~ ( V_280 | V_281 ) ;
if ( F_84 ( V_10 ) != V_204 -> V_212 ) {
if ( F_113 ( V_75 ) && F_114 ( V_75 ) ) {
V_271 = F_117 ( V_76 , V_10 ,
& V_10 -> V_283 , V_270 ) ;
}
ASSERT ( V_10 -> V_80 . V_238 > 1 ) ;
F_118 ( V_10 , V_204 -> V_212 ) ;
}
if ( V_10 -> V_80 . V_196 & ( V_237 | V_231 ) )
V_10 -> V_80 . V_208 = V_204 -> V_207 >> V_75 -> V_140 . V_209 ;
else
V_10 -> V_80 . V_208 = 0 ;
if ( V_10 -> V_80 . V_238 == 3 &&
( V_10 -> V_80 . V_220 & V_243 ) )
V_10 -> V_80 . V_211 = V_204 -> V_210 >>
V_75 -> V_140 . V_209 ;
else
V_10 -> V_80 . V_211 = 0 ;
V_272 = F_42 ( V_76 ) ;
F_119 ( V_271 ) ;
F_119 ( V_269 ) ;
F_119 ( V_270 ) ;
return V_272 ;
V_279:
F_101 ( V_76 ) ;
V_276:
F_119 ( V_269 ) ;
F_119 ( V_270 ) ;
return V_272 ;
}
STATIC int
F_120 (
T_6 * V_10 ,
struct V_12 * V_56 ,
void V_14 * V_84 )
{
struct V_203 V_204 ;
int error ;
if ( F_16 ( & V_204 , V_84 , sizeof( V_204 ) ) )
return - V_35 ;
error = F_44 ( V_56 ) ;
if ( error )
return error ;
error = F_109 ( V_10 , & V_204 ) ;
F_45 ( V_56 ) ;
return error ;
}
STATIC int
F_121 (
T_6 * V_10 ,
void V_14 * V_84 )
{
unsigned int V_102 ;
V_102 = F_81 ( V_10 -> V_80 . V_196 ) ;
if ( F_10 ( V_84 , & V_102 , sizeof( V_102 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_122 (
struct V_9 * V_10 ,
struct V_12 * V_56 ,
void V_14 * V_84 )
{
struct V_247 * V_76 ;
struct V_203 V_204 ;
unsigned int V_102 ;
int V_255 = 0 ;
int error ;
if ( F_16 ( & V_102 , V_84 , sizeof( V_102 ) ) )
return - V_35 ;
if ( V_102 & ~ ( V_186 | V_188 | \
V_192 | V_194 | \
V_190 ) )
return - V_284 ;
V_204 . V_206 = F_80 ( V_102 , F_83 ( V_10 ) ) ;
error = F_44 ( V_56 ) ;
if ( error )
return error ;
error = F_94 ( V_10 , & V_204 , & V_255 ) ;
if ( error )
goto V_285;
V_76 = F_98 ( V_10 , V_255 ) ;
if ( F_22 ( V_76 ) ) {
error = F_23 ( V_76 ) ;
goto V_285;
}
error = F_89 ( V_76 , V_10 , & V_204 ) ;
if ( error ) {
F_101 ( V_76 ) ;
goto V_285;
}
error = F_42 ( V_76 ) ;
V_285:
F_45 ( V_56 ) ;
return error ;
}
STATIC int
F_123 ( void * * V_286 , struct V_287 * V_288 )
{
struct V_289 V_14 * V_290 = (struct V_289 V_14 * ) * V_286 ;
if ( F_10 ( V_290 , V_288 , sizeof( struct V_289 ) ) )
return - V_35 ;
* V_286 += sizeof( struct V_289 ) ;
return 0 ;
}
STATIC int
F_124 (
struct V_12 * V_12 ,
unsigned int V_1 ,
void V_14 * V_84 )
{
struct V_287 V_291 = { 0 } ;
int error ;
if ( F_16 ( & V_291 , V_84 , F_125 ( struct V_287 , V_292 ) ) )
return - V_35 ;
if ( V_291 . V_293 < 2 )
return - V_16 ;
V_291 . V_292 = ( V_1 == V_294 ? V_295 : 0 ) ;
if ( V_12 -> V_70 & V_71 )
V_291 . V_292 |= V_296 ;
error = F_126 ( F_6 ( F_3 ( V_12 ) ) , & V_291 , F_123 ,
( V_297 struct V_289 * ) V_84 + 1 ) ;
if ( error )
return error ;
if ( F_10 ( V_84 , & V_291 , sizeof( struct V_289 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_127 ( void * * V_286 , struct V_287 * V_288 )
{
struct V_287 V_14 * V_290 = (struct V_287 V_14 * ) * V_286 ;
if ( F_10 ( V_290 , V_288 , sizeof( struct V_287 ) ) )
return - V_35 ;
* V_286 += sizeof( struct V_287 ) ;
return 0 ;
}
STATIC int
F_128 (
struct V_9 * V_10 ,
void V_14 * V_84 )
{
struct V_287 V_291 ;
int error ;
if ( F_16 ( & V_291 , V_84 , sizeof( V_291 ) ) )
return - V_35 ;
if ( V_291 . V_293 < 2 )
return - V_16 ;
if ( V_291 . V_292 & ( ~ V_298 ) )
return - V_16 ;
error = F_126 ( V_10 , & V_291 , F_127 ,
( V_297 struct V_287 * ) V_84 + 1 ) ;
if ( error )
return error ;
if ( F_10 ( V_84 , & V_291 , sizeof( struct V_287 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_129 ( struct V_299 * V_300 , void * V_301 )
{
struct V_302 * V_303 = V_301 ;
struct V_304 V_305 ;
F_130 ( V_303 -> V_75 , V_300 ) ;
V_303 -> V_306 = V_300 -> V_307 ;
F_131 ( & V_305 , V_300 ) ;
if ( F_10 ( & V_303 -> V_90 -> V_308 [ V_303 -> V_309 ++ ] , & V_305 ,
sizeof( struct V_304 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_132 (
struct V_9 * V_10 ,
struct V_310 V_14 * V_84 )
{
struct V_302 V_303 = { NULL } ;
struct V_311 V_312 = { 0 } ;
struct V_310 V_313 ;
bool V_314 = false ;
int error ;
if ( F_16 ( & V_313 , V_84 , sizeof( struct V_310 ) ) )
return - V_35 ;
if ( F_133 ( V_313 . V_315 , 0 , sizeof( V_313 . V_315 ) ) ||
F_133 ( V_313 . V_316 [ 0 ] . V_317 , 0 ,
sizeof( V_313 . V_316 [ 0 ] . V_317 ) ) ||
F_133 ( V_313 . V_316 [ 1 ] . V_317 , 0 ,
sizeof( V_313 . V_316 [ 1 ] . V_317 ) ) )
return - V_16 ;
V_312 . V_318 = V_313 . V_318 ;
V_312 . V_319 = V_313 . V_319 ;
F_134 ( & V_312 . V_316 [ 0 ] , & V_313 . V_316 [ 0 ] ) ;
F_134 ( & V_312 . V_316 [ 1 ] , & V_313 . V_316 [ 1 ] ) ;
F_135 ( V_10 -> V_23 , & V_312 . V_316 [ 0 ] ) ;
F_136 ( V_10 -> V_23 , & V_312 . V_316 [ 1 ] ) ;
V_303 . V_75 = V_10 -> V_23 ;
V_303 . V_90 = V_84 ;
error = F_137 ( V_10 -> V_23 , & V_312 , F_129 , & V_303 ) ;
if ( error == V_320 ) {
error = 0 ;
V_314 = true ;
} else if ( error )
return error ;
if ( ! V_314 && V_303 . V_309 ) {
V_303 . V_306 |= V_321 ;
if ( F_10 ( & V_303 . V_90 -> V_308 [ V_303 . V_309 - 1 ] . V_307 ,
& V_303 . V_306 , sizeof( V_303 . V_306 ) ) )
return - V_35 ;
}
V_313 . V_322 = V_312 . V_322 ;
V_313 . V_323 = V_312 . V_323 ;
if ( F_10 ( V_84 , & V_313 , sizeof( struct V_310 ) ) )
return - V_35 ;
return 0 ;
}
int
F_138 (
T_26 * V_324 )
{
T_6 * V_10 , * V_325 ;
struct V_6 V_7 , V_326 ;
int error = 0 ;
V_7 = F_2 ( ( int ) V_324 -> V_327 ) ;
if ( ! V_7 . V_12 ) {
error = - V_16 ;
goto V_89;
}
if ( ! ( V_7 . V_12 -> V_70 & V_66 ) ||
! ( V_7 . V_12 -> V_70 & V_328 ) ||
( V_7 . V_12 -> V_68 & V_64 ) ) {
error = - V_13 ;
goto V_329;
}
V_326 = F_2 ( ( int ) V_324 -> V_330 ) ;
if ( ! V_326 . V_12 ) {
error = - V_16 ;
goto V_329;
}
if ( ! ( V_326 . V_12 -> V_70 & V_66 ) ||
! ( V_326 . V_12 -> V_70 & V_328 ) ||
( V_326 . V_12 -> V_68 & V_64 ) ) {
error = - V_13 ;
goto V_331;
}
if ( F_139 ( F_3 ( V_7 . V_12 ) ) ||
F_139 ( F_3 ( V_326 . V_12 ) ) ) {
error = - V_16 ;
goto V_331;
}
if ( V_7 . V_12 -> V_332 != & V_333 ||
V_326 . V_12 -> V_332 != & V_333 ) {
error = - V_16 ;
goto V_331;
}
V_10 = F_6 ( F_3 ( V_7 . V_12 ) ) ;
V_325 = F_6 ( F_3 ( V_326 . V_12 ) ) ;
if ( V_10 -> V_23 != V_325 -> V_23 ) {
error = - V_16 ;
goto V_331;
}
if ( V_10 -> V_34 == V_325 -> V_34 ) {
error = - V_16 ;
goto V_331;
}
if ( F_36 ( V_10 -> V_23 ) ) {
error = - V_77 ;
goto V_331;
}
error = F_140 ( V_10 , V_325 , V_324 ) ;
V_331:
F_11 ( V_326 ) ;
V_329:
F_11 ( V_7 ) ;
V_89:
return error ;
}
long
F_141 (
struct V_12 * V_56 ,
unsigned int V_1 ,
unsigned long V_96 )
{
struct V_5 * V_5 = F_3 ( V_56 ) ;
struct V_9 * V_10 = F_6 ( V_5 ) ;
struct V_248 * V_75 = V_10 -> V_23 ;
void V_14 * V_84 = ( void V_14 * ) V_96 ;
int error ;
F_142 ( V_10 ) ;
switch ( V_1 ) {
case V_334 :
return F_143 ( V_75 , V_84 ) ;
case V_161 :
case V_163 :
case V_153 :
case V_155 :
case V_162 :
case V_164 :
case V_154 :
case V_156 :
case V_152 : {
T_17 V_135 ;
if ( F_16 ( & V_135 , V_84 , sizeof( V_135 ) ) )
return - V_35 ;
return F_62 ( V_56 , V_1 , & V_135 ) ;
}
case V_335 : {
struct V_336 V_337 ;
T_27 * V_338 =
F_90 ( V_10 ) ?
V_75 -> V_339 : V_75 -> V_340 ;
V_337 . V_341 = V_337 . V_342 = V_338 -> V_343 ;
V_337 . V_344 = V_119 & ~ ( V_337 . V_342 - 1 ) ;
if ( F_10 ( V_84 , & V_337 , sizeof( V_337 ) ) )
return - V_35 ;
return 0 ;
}
case V_179 :
case V_345 :
case V_177 :
return F_73 ( V_75 , V_1 , V_84 ) ;
case V_346 :
return F_77 ( V_75 , V_84 ) ;
case V_347 :
return F_79 ( V_75 , V_84 ) ;
case V_348 :
return F_144 ( V_5 -> V_32 , ( int V_14 * ) V_84 ) ;
case V_349 :
return F_82 ( V_10 , 0 , V_84 ) ;
case V_350 :
return F_82 ( V_10 , 1 , V_84 ) ;
case V_351 :
return F_120 ( V_10 , V_56 , V_84 ) ;
case V_352 :
return F_121 ( V_10 , V_84 ) ;
case V_353 :
return F_122 ( V_10 , V_56 , V_84 ) ;
case V_354 : {
struct V_85 V_355 ;
if ( F_16 ( & V_355 , V_84 , sizeof( V_355 ) ) )
return - V_35 ;
error = F_44 ( V_56 ) ;
if ( error )
return error ;
error = F_35 ( V_10 , V_355 . V_91 ,
V_355 . V_92 ) ;
F_45 ( V_56 ) ;
return error ;
}
case V_356 :
case V_294 :
return F_124 ( V_56 , V_1 , V_84 ) ;
case V_357 :
return F_128 ( V_10 , V_84 ) ;
case V_358 :
return F_132 ( V_10 , V_84 ) ;
case V_11 :
case V_359 :
case V_26 : {
T_1 V_2 ;
if ( F_16 ( & V_2 , V_84 , sizeof( V_2 ) ) )
return - V_35 ;
return F_1 ( V_1 , & V_2 ) ;
}
case V_360 : {
T_1 V_2 ;
if ( F_16 ( & V_2 , V_84 , sizeof( T_1 ) ) )
return - V_35 ;
return F_19 ( V_56 , & V_2 ) ;
}
case V_361 :
return F_43 ( V_56 , V_84 ) ;
case V_362 : {
T_1 V_2 ;
if ( F_16 ( & V_2 , V_84 , sizeof( T_1 ) ) )
return - V_35 ;
return F_32 ( V_56 , & V_2 ) ;
}
case V_363 :
return F_46 ( V_56 , V_84 ) ;
case V_364 :
return F_59 ( V_56 , V_84 ) ;
case V_365 : {
struct V_366 V_324 ;
if ( F_16 ( & V_324 , V_84 , sizeof( T_26 ) ) )
return - V_35 ;
error = F_44 ( V_56 ) ;
if ( error )
return error ;
error = F_138 ( & V_324 ) ;
F_45 ( V_56 ) ;
return error ;
}
case V_367 : {
T_28 V_89 ;
error = F_145 ( V_75 , & V_89 ) ;
if ( error )
return error ;
if ( F_10 ( V_84 , & V_89 , sizeof( V_89 ) ) )
return - V_35 ;
return 0 ;
}
case V_368 : {
T_29 V_369 ;
T_23 V_370 ;
if ( ! F_21 ( V_58 ) )
return - V_59 ;
if ( V_75 -> V_259 & V_260 )
return - V_258 ;
if ( F_16 ( & V_369 , V_84 , sizeof( V_369 ) ) )
return - V_35 ;
error = F_44 ( V_56 ) ;
if ( error )
return error ;
V_370 = V_369 . V_371 ;
error = F_146 ( V_75 , & V_370 , & V_369 ) ;
F_45 ( V_56 ) ;
if ( error )
return error ;
if ( F_10 ( V_84 , & V_369 , sizeof( V_369 ) ) )
return - V_35 ;
return 0 ;
}
case V_372 : {
T_29 V_89 ;
if ( ! F_21 ( V_58 ) )
return - V_59 ;
error = F_146 ( V_75 , NULL , & V_89 ) ;
if ( error )
return error ;
if ( F_10 ( V_84 , & V_89 , sizeof( V_89 ) ) )
return - V_35 ;
return 0 ;
}
case V_373 : {
T_30 V_370 ;
if ( F_16 ( & V_370 , V_84 , sizeof( V_370 ) ) )
return - V_35 ;
error = F_44 ( V_56 ) ;
if ( error )
return error ;
error = F_147 ( V_75 , & V_370 ) ;
F_45 ( V_56 ) ;
return error ;
}
case V_374 : {
T_31 V_370 ;
if ( F_16 ( & V_370 , V_84 , sizeof( V_370 ) ) )
return - V_35 ;
error = F_44 ( V_56 ) ;
if ( error )
return error ;
error = F_148 ( V_75 , & V_370 ) ;
F_45 ( V_56 ) ;
return error ;
}
case V_375 : {
T_32 V_370 ;
if ( F_16 ( & V_370 , V_84 , sizeof( V_370 ) ) )
return - V_35 ;
error = F_44 ( V_56 ) ;
if ( error )
return error ;
error = F_149 ( V_75 , & V_370 ) ;
F_45 ( V_56 ) ;
return error ;
}
case V_376 : {
T_14 V_370 ;
if ( ! F_21 ( V_58 ) )
return - V_59 ;
if ( F_150 ( V_370 , ( T_14 V_14 * ) V_84 ) )
return - V_35 ;
return F_151 ( V_75 , V_370 ) ;
}
case V_377 : {
T_33 V_370 ;
if ( ! F_21 ( V_58 ) )
return - V_59 ;
if ( F_16 ( & V_370 , V_84 , sizeof( V_370 ) ) )
return - V_35 ;
return F_152 ( V_75 , V_370 . V_378 ) ;
}
case V_379 :
if ( ! F_21 ( V_58 ) )
return - V_59 ;
return F_153 ( V_75 ) ;
case V_380 : {
struct V_381 V_382 ;
struct V_383 V_384 ;
if ( ! F_21 ( V_58 ) )
return - V_59 ;
if ( V_75 -> V_259 & V_260 )
return - V_258 ;
if ( F_16 ( & V_382 , V_84 , sizeof( V_382 ) ) )
return - V_35 ;
error = F_154 ( & V_382 , & V_384 ) ;
if ( error )
return error ;
return F_155 ( V_75 , & V_384 ) ;
}
default:
return - V_385 ;
}
}
