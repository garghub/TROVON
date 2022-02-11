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
V_3 = F_10 ( V_4 ) ;
}
error = - V_35 ;
if ( F_11 ( V_2 -> V_36 , & V_4 , V_3 ) ||
F_11 ( V_2 -> V_37 , & V_3 , sizeof( V_38 ) ) )
goto V_20;
error = 0 ;
V_20:
if ( V_1 == V_11 )
F_12 ( V_7 ) ;
else
F_13 ( & V_8 ) ;
return error ;
}
STATIC int
F_14 (
void * V_39 ,
struct V_15 * V_15 )
{
return 1 ;
}
struct V_15 *
F_15 (
struct V_12 * V_40 ,
void V_14 * V_41 ,
T_3 V_42 )
{
T_2 V_4 ;
struct V_43 V_44 ;
if ( ! F_8 ( F_3 ( V_40 ) -> V_21 ) )
return F_16 ( - V_45 ) ;
if ( V_42 != sizeof( T_2 ) )
return F_16 ( - V_16 ) ;
if ( F_17 ( & V_4 , V_41 , V_42 ) )
return F_16 ( - V_35 ) ;
if ( V_4 . V_27 . V_28 !=
sizeof( V_4 . V_27 ) - sizeof( V_4 . V_27 . V_28 ) )
return F_16 ( - V_16 ) ;
memset ( & V_44 , 0 , sizeof( struct V_44 ) ) ;
V_44 . V_46 = V_4 . V_27 . V_33 ;
V_44 . V_47 = V_4 . V_27 . V_31 ;
return F_18 ( V_40 -> V_48 . V_49 , (struct V_44 * ) & V_44 , 3 ,
V_50 | V_51 ,
F_14 , NULL ) ;
}
STATIC struct V_15 *
F_19 (
struct V_12 * V_40 ,
T_1 * V_2 )
{
return F_15 ( V_40 , V_2 -> V_52 , V_2 -> V_53 ) ;
}
int
F_20 (
struct V_12 * V_40 ,
T_1 * V_2 )
{
const struct V_54 * V_54 = F_21 () ;
int error ;
int V_6 ;
int V_55 ;
struct V_12 * V_56 ;
struct V_5 * V_5 ;
struct V_15 * V_15 ;
T_4 V_57 ;
struct V_8 V_8 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
V_15 = F_19 ( V_40 , V_2 ) ;
if ( F_23 ( V_15 ) )
return F_24 ( V_15 ) ;
V_5 = F_5 ( V_15 ) ;
if ( ! ( F_7 ( V_5 -> V_21 ) || F_8 ( V_5 -> V_21 ) ) ) {
error = - V_59 ;
goto V_60;
}
#if V_61 != 32
V_2 -> V_62 |= V_63 ;
#endif
V_55 = V_2 -> V_62 ;
V_57 = F_25 ( V_55 ) ;
if ( ( ! ( V_55 & V_64 ) || ( V_55 & V_65 ) ) &&
( V_57 & V_66 ) && F_26 ( V_5 ) ) {
error = - V_59 ;
goto V_60;
}
if ( ( V_57 & V_66 ) && F_27 ( V_5 ) ) {
error = - V_67 ;
goto V_60;
}
if ( F_8 ( V_5 -> V_21 ) && ( V_57 & V_66 ) ) {
error = - V_68 ;
goto V_60;
}
V_6 = F_28 ( 0 ) ;
if ( V_6 < 0 ) {
error = V_6 ;
goto V_60;
}
V_8 . V_49 = V_40 -> V_48 . V_49 ;
V_8 . V_15 = V_15 ;
V_56 = F_29 ( & V_8 , V_2 -> V_62 , V_54 ) ;
F_30 ( V_15 ) ;
if ( F_23 ( V_56 ) ) {
F_31 ( V_6 ) ;
return F_24 ( V_56 ) ;
}
if ( F_7 ( V_5 -> V_21 ) ) {
V_56 -> V_69 |= V_70 ;
V_56 -> V_71 |= V_72 ;
}
F_32 ( V_6 , V_56 ) ;
return V_6 ;
V_60:
F_30 ( V_15 ) ;
return error ;
}
int
F_33 (
struct V_12 * V_40 ,
T_1 * V_2 )
{
struct V_15 * V_15 ;
T_5 V_73 ;
int error ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
V_15 = F_19 ( V_40 , V_2 ) ;
if ( F_23 ( V_15 ) )
return F_24 ( V_15 ) ;
if ( ! F_5 ( V_15 ) -> V_74 -> V_75 ) {
error = - V_16 ;
goto V_60;
}
if ( F_17 ( & V_73 , V_2 -> V_37 , sizeof( T_5 ) ) ) {
error = - V_35 ;
goto V_60;
}
error = F_5 ( V_15 ) -> V_74 -> V_75 ( V_15 , V_2 -> V_36 , V_73 ) ;
V_60:
F_30 ( V_15 ) ;
return error ;
}
int
F_34 (
T_6 * V_10 ,
T_7 V_76 ,
T_8 V_77 )
{
T_9 * V_78 = V_10 -> V_23 ;
T_10 * V_79 ;
int error ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_35 ( V_78 ) )
return - V_80 ;
error = F_36 ( V_78 , & F_37 ( V_78 ) -> V_81 , 0 , 0 , 0 , & V_79 ) ;
if ( error )
return error ;
F_38 ( V_10 , V_82 ) ;
F_39 ( V_79 , V_10 , V_82 ) ;
V_10 -> V_83 . V_84 = V_76 ;
V_10 -> V_83 . V_85 = V_77 ;
F_40 ( V_79 , V_10 , V_86 ) ;
error = F_41 ( V_79 ) ;
return error ;
}
STATIC int
F_42 (
struct V_12 * V_40 ,
void V_14 * V_87 )
{
int error ;
struct V_88 V_89 ;
T_11 V_90 ;
struct V_15 * V_15 ;
if ( ! F_22 ( V_91 ) )
return - V_59 ;
if ( F_17 ( & V_90 , V_87 , sizeof( T_11 ) ) )
return - V_35 ;
error = F_43 ( V_40 ) ;
if ( error )
return error ;
V_15 = F_19 ( V_40 , & V_90 . V_2 ) ;
if ( F_23 ( V_15 ) ) {
F_44 ( V_40 ) ;
return F_24 ( V_15 ) ;
}
if ( F_27 ( F_5 ( V_15 ) ) || F_26 ( F_5 ( V_15 ) ) ) {
error = - V_59 ;
goto V_92;
}
if ( F_17 ( & V_89 , V_90 . V_93 , sizeof( V_89 ) ) ) {
error = - V_35 ;
goto V_92;
}
error = F_34 ( F_6 ( F_5 ( V_15 ) ) , V_89 . V_94 ,
V_89 . V_95 ) ;
V_92:
F_44 ( V_40 ) ;
F_30 ( V_15 ) ;
return error ;
}
STATIC int
F_45 (
struct V_12 * V_40 ,
void V_14 * V_87 )
{
int error = - V_96 ;
T_12 * V_97 ;
T_13 V_98 ;
struct V_15 * V_15 ;
char * V_99 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_17 ( & V_98 , V_87 , sizeof( T_13 ) ) )
return - V_35 ;
if ( V_98 . V_100 < sizeof( struct V_101 ) ||
V_98 . V_100 > V_102 )
return - V_16 ;
if ( V_98 . V_103 & ~ ( V_104 | V_105 ) )
return - V_16 ;
V_15 = F_19 ( V_40 , & V_98 . V_2 ) ;
if ( F_23 ( V_15 ) )
return F_24 ( V_15 ) ;
V_99 = F_46 ( V_98 . V_100 , V_106 ) ;
if ( ! V_99 )
goto V_60;
V_97 = ( T_12 * ) & V_98 . V_107 ;
error = F_47 ( F_6 ( F_5 ( V_15 ) ) , V_99 , V_98 . V_100 ,
V_98 . V_103 , V_97 ) ;
if ( error )
goto V_108;
if ( F_11 ( V_98 . V_109 , V_99 , V_98 . V_100 ) )
error = - V_35 ;
V_108:
F_48 ( V_99 ) ;
V_60:
F_30 ( V_15 ) ;
return error ;
}
int
F_49 (
struct V_5 * V_5 ,
unsigned char * V_110 ,
unsigned char V_14 * V_111 ,
T_14 * V_112 ,
T_14 V_103 )
{
unsigned char * V_99 ;
int error = - V_35 ;
if ( * V_112 > V_113 )
return - V_16 ;
V_99 = F_46 ( * V_112 , V_106 ) ;
if ( ! V_99 )
return - V_96 ;
error = F_50 ( F_6 ( V_5 ) , V_110 , V_99 , ( int * ) V_112 , V_103 ) ;
if ( error )
goto V_108;
if ( F_11 ( V_111 , V_99 , * V_112 ) )
error = - V_35 ;
V_108:
F_48 ( V_99 ) ;
return error ;
}
int
F_51 (
struct V_5 * V_5 ,
unsigned char * V_110 ,
const unsigned char V_14 * V_111 ,
T_14 V_112 ,
T_14 V_103 )
{
unsigned char * V_99 ;
int error ;
if ( F_27 ( V_5 ) || F_26 ( V_5 ) )
return - V_59 ;
if ( V_112 > V_113 )
return - V_16 ;
V_99 = F_52 ( V_111 , V_112 ) ;
if ( F_23 ( V_99 ) )
return F_24 ( V_99 ) ;
error = F_53 ( F_6 ( V_5 ) , V_110 , V_99 , V_112 , V_103 ) ;
if ( ! error )
F_54 ( V_5 , V_110 , V_103 ) ;
F_55 ( V_99 ) ;
return error ;
}
int
F_56 (
struct V_5 * V_5 ,
unsigned char * V_110 ,
T_14 V_103 )
{
int error ;
if ( F_27 ( V_5 ) || F_26 ( V_5 ) )
return - V_59 ;
error = F_57 ( F_6 ( V_5 ) , V_110 , V_103 ) ;
if ( ! error )
F_54 ( V_5 , V_110 , V_103 ) ;
return error ;
}
STATIC int
F_58 (
struct V_12 * V_40 ,
void V_14 * V_87 )
{
int error ;
T_15 * V_114 ;
T_16 V_115 ;
struct V_15 * V_15 ;
unsigned int V_116 , V_117 ;
unsigned char * V_118 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_17 ( & V_115 , V_87 , sizeof( T_16 ) ) )
return - V_35 ;
if ( V_115 . V_119 >= V_120 / sizeof( T_15 ) )
return - V_121 ;
V_15 = F_19 ( V_40 , & V_115 . V_2 ) ;
if ( F_23 ( V_15 ) )
return F_24 ( V_15 ) ;
error = - V_121 ;
V_117 = V_115 . V_119 * sizeof( T_15 ) ;
if ( ! V_117 || V_117 > 16 * V_122 )
goto V_60;
V_114 = F_52 ( V_115 . V_114 , V_117 ) ;
if ( F_23 ( V_114 ) ) {
error = F_24 ( V_114 ) ;
goto V_60;
}
error = - V_96 ;
V_118 = F_59 ( V_123 , V_124 ) ;
if ( ! V_118 )
goto V_125;
error = 0 ;
for ( V_116 = 0 ; V_116 < V_115 . V_119 ; V_116 ++ ) {
V_114 [ V_116 ] . V_126 = F_60 ( ( char * ) V_118 ,
V_114 [ V_116 ] . V_127 , V_123 ) ;
if ( V_114 [ V_116 ] . V_126 == 0 || V_114 [ V_116 ] . V_126 == V_123 )
error = - V_128 ;
if ( V_114 [ V_116 ] . V_126 < 0 )
break;
switch ( V_114 [ V_116 ] . V_129 ) {
case V_130 :
V_114 [ V_116 ] . V_126 = F_49 (
F_5 ( V_15 ) , V_118 ,
V_114 [ V_116 ] . V_131 , & V_114 [ V_116 ] . V_132 ,
V_114 [ V_116 ] . V_133 ) ;
break;
case V_134 :
V_114 [ V_116 ] . V_126 = F_43 ( V_40 ) ;
if ( V_114 [ V_116 ] . V_126 )
break;
V_114 [ V_116 ] . V_126 = F_51 (
F_5 ( V_15 ) , V_118 ,
V_114 [ V_116 ] . V_131 , V_114 [ V_116 ] . V_132 ,
V_114 [ V_116 ] . V_133 ) ;
F_44 ( V_40 ) ;
break;
case V_135 :
V_114 [ V_116 ] . V_126 = F_43 ( V_40 ) ;
if ( V_114 [ V_116 ] . V_126 )
break;
V_114 [ V_116 ] . V_126 = F_56 (
F_5 ( V_15 ) , V_118 ,
V_114 [ V_116 ] . V_133 ) ;
F_44 ( V_40 ) ;
break;
default:
V_114 [ V_116 ] . V_126 = - V_16 ;
}
}
if ( F_11 ( V_115 . V_114 , V_114 , V_117 ) )
error = - V_35 ;
F_55 ( V_118 ) ;
V_125:
F_55 ( V_114 ) ;
V_60:
F_30 ( V_15 ) ;
return error ;
}
int
F_61 (
struct V_9 * V_10 ,
struct V_5 * V_5 ,
struct V_12 * V_56 ,
int V_136 ,
unsigned int V_1 ,
T_17 * V_137 )
{
struct V_138 V_138 ;
enum V_139 V_103 = 0 ;
T_18 V_140 = V_141 ;
int error ;
if ( ! F_62 ( & V_10 -> V_23 -> V_142 ) &&
! F_22 ( V_58 ) )
return - V_59 ;
if ( V_5 -> V_143 & ( V_144 | V_145 ) )
return - V_59 ;
if ( ! ( V_56 -> V_71 & V_66 ) )
return - V_13 ;
if ( ! F_7 ( V_5 -> V_21 ) )
return - V_16 ;
if ( V_56 -> V_69 & V_146 )
V_103 |= V_147 ;
if ( V_136 & V_148 )
V_103 |= V_149 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
F_38 ( V_10 , V_140 ) ;
error = F_63 ( V_5 , & V_140 , false ) ;
if ( error )
goto V_150;
F_38 ( V_10 , V_151 ) ;
V_140 |= V_151 ;
switch ( V_137 -> V_152 ) {
case 0 :
break;
case 1 :
V_137 -> V_153 += V_56 -> V_154 ;
break;
case 2 :
V_137 -> V_153 += F_64 ( V_10 ) ;
break;
default:
error = - V_16 ;
goto V_150;
}
switch ( V_1 ) {
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
if ( V_137 -> V_160 <= 0 ) {
error = - V_16 ;
goto V_150;
}
break;
default:
V_137 -> V_160 = 0 ;
break;
}
if ( V_137 -> V_153 < 0 ||
V_137 -> V_153 > V_5 -> V_17 -> V_161 ||
V_137 -> V_153 + V_137 -> V_160 < 0 ||
V_137 -> V_153 + V_137 -> V_160 >= V_5 -> V_17 -> V_161 ) {
error = - V_16 ;
goto V_150;
}
switch ( V_1 ) {
case V_155 :
V_103 |= V_162 ;
error = F_65 ( V_10 , V_137 -> V_153 , V_137 -> V_160 ) ;
break;
case V_156 :
case V_157 :
V_103 |= V_162 ;
error = F_66 ( V_10 , V_137 -> V_153 , V_137 -> V_160 ,
V_163 ) ;
break;
case V_158 :
case V_159 :
error = F_67 ( V_10 , V_137 -> V_153 , V_137 -> V_160 ) ;
break;
case V_164 :
case V_165 :
case V_166 :
case V_167 :
V_103 |= V_168 ;
if ( V_137 -> V_153 > F_64 ( V_10 ) ) {
error = F_66 ( V_10 , F_64 ( V_10 ) ,
V_137 -> V_153 - F_64 ( V_10 ) , 0 ) ;
if ( error )
goto V_150;
}
V_138 . V_169 = V_170 ;
V_138 . V_171 = V_137 -> V_153 ;
error = F_68 ( V_10 , & V_138 ) ;
break;
default:
ASSERT ( 0 ) ;
error = - V_16 ;
}
if ( error )
goto V_150;
error = F_69 ( V_10 , V_103 ) ;
V_150:
F_70 ( V_10 , V_140 ) ;
F_44 ( V_56 ) ;
return error ;
}
STATIC int
F_71 (
T_9 * V_78 ,
unsigned int V_1 ,
void V_14 * V_87 )
{
T_19 V_172 ;
int V_173 ;
T_20 V_174 ;
int V_175 ;
int error ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_35 ( V_78 ) )
return - V_80 ;
if ( F_17 ( & V_172 , V_87 , sizeof( T_19 ) ) )
return - V_35 ;
if ( F_17 ( & V_174 , V_172 . V_176 , sizeof( V_177 ) ) )
return - V_35 ;
if ( ( V_173 = V_172 . V_178 ) <= 0 )
return - V_16 ;
if ( V_172 . V_179 == NULL )
return - V_16 ;
if ( V_1 == V_180 )
error = F_72 ( V_78 , & V_174 , & V_173 ,
V_172 . V_179 , V_181 ) ;
else if ( V_1 == V_182 )
error = F_73 ( V_78 , V_174 , V_172 . V_179 ,
sizeof( V_183 ) , NULL , & V_175 ) ;
else
error = F_74 ( V_78 , & V_174 , & V_173 , F_73 ,
sizeof( V_183 ) , V_172 . V_179 ,
& V_175 ) ;
if ( error )
return error ;
if ( V_172 . V_184 != NULL ) {
if ( F_11 ( V_172 . V_176 , & V_174 ,
sizeof( T_20 ) ) )
return - V_35 ;
if ( F_11 ( V_172 . V_184 , & V_173 , sizeof( V_173 ) ) )
return - V_35 ;
}
return 0 ;
}
STATIC int
F_75 (
T_9 * V_78 ,
void V_14 * V_87 )
{
T_21 V_185 ;
int error ;
error = F_76 ( V_78 , & V_185 , 3 ) ;
if ( error )
return error ;
if ( F_11 ( V_87 , & V_185 , sizeof( V_186 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_77 (
T_9 * V_78 ,
void V_14 * V_87 )
{
T_21 V_185 ;
int error ;
error = F_76 ( V_78 , & V_185 , 4 ) ;
if ( error )
return error ;
if ( F_11 ( V_87 , & V_185 , sizeof( V_185 ) ) )
return - V_35 ;
return 0 ;
}
STATIC unsigned int
F_78 (
unsigned int V_103 ,
unsigned int V_187 )
{
unsigned int V_188 = V_187 ;
if ( V_103 & V_189 )
V_188 |= V_190 ;
else
V_188 &= ~ V_190 ;
if ( V_103 & V_191 )
V_188 |= V_192 ;
else
V_188 &= ~ V_192 ;
if ( V_103 & V_193 )
V_188 |= V_194 ;
else
V_188 &= ~ V_194 ;
if ( V_103 & V_195 )
V_188 |= V_196 ;
else
V_188 &= ~ V_196 ;
if ( V_103 & V_197 )
V_188 |= V_198 ;
else
V_188 &= ~ V_198 ;
return V_188 ;
}
STATIC unsigned int
F_79 (
T_22 V_199 )
{
unsigned int V_103 = 0 ;
if ( V_199 & V_200 )
V_103 |= V_189 ;
if ( V_199 & V_201 )
V_103 |= V_191 ;
if ( V_199 & V_202 )
V_103 |= V_193 ;
if ( V_199 & V_203 )
V_103 |= V_195 ;
if ( V_199 & V_204 )
V_103 |= V_197 ;
return V_103 ;
}
STATIC int
F_80 (
T_6 * V_10 ,
int V_205 ,
void V_14 * V_87 )
{
struct V_206 V_207 ;
memset ( & V_207 , 0 , sizeof( struct V_206 ) ) ;
F_38 ( V_10 , V_208 ) ;
V_207 . V_209 = F_81 ( V_10 ) ;
V_207 . V_210 = V_10 -> V_83 . V_211 << V_10 -> V_23 -> V_142 . V_212 ;
V_207 . V_213 = F_82 ( V_10 ) ;
if ( V_205 ) {
if ( V_10 -> V_214 ) {
if ( V_10 -> V_214 -> V_215 & V_216 )
V_207 . V_217 = V_10 -> V_214 -> V_218 /
sizeof( V_219 ) ;
else
V_207 . V_217 = V_10 -> V_83 . V_220 ;
} else
V_207 . V_217 = 0 ;
} else {
if ( V_10 -> V_221 . V_215 & V_216 )
V_207 . V_217 = V_10 -> V_221 . V_218 /
sizeof( V_219 ) ;
else
V_207 . V_217 = V_10 -> V_83 . V_222 ;
}
F_70 ( V_10 , V_208 ) ;
if ( F_11 ( V_87 , & V_207 , sizeof( V_207 ) ) )
return - V_35 ;
return 0 ;
}
STATIC void
F_83 (
struct V_9 * V_10 ,
unsigned int V_188 )
{
unsigned int V_199 ;
T_23 V_223 ;
V_199 = ( V_10 -> V_83 . V_199 & V_224 ) ;
if ( V_188 & V_190 )
V_199 |= V_200 ;
if ( V_188 & V_192 )
V_199 |= V_201 ;
if ( V_188 & V_194 )
V_199 |= V_202 ;
if ( V_188 & V_196 )
V_199 |= V_203 ;
if ( V_188 & V_198 )
V_199 |= V_204 ;
if ( V_188 & V_225 )
V_199 |= V_226 ;
if ( V_188 & V_227 )
V_199 |= V_228 ;
if ( F_8 ( F_84 ( V_10 ) -> V_21 ) ) {
if ( V_188 & V_229 )
V_199 |= V_230 ;
if ( V_188 & V_231 )
V_199 |= V_232 ;
if ( V_188 & V_233 )
V_199 |= V_234 ;
if ( V_188 & V_235 )
V_199 |= V_236 ;
} else if ( F_7 ( F_84 ( V_10 ) -> V_21 ) ) {
if ( V_188 & V_237 )
V_199 |= V_238 ;
if ( V_188 & V_239 )
V_199 |= V_240 ;
}
V_10 -> V_83 . V_199 = V_199 ;
if ( V_10 -> V_83 . V_241 < 3 )
return;
V_223 = 0 ;
if ( V_188 & V_242 )
V_223 |= V_243 ;
V_10 -> V_83 . V_223 = V_223 ;
}
STATIC void
F_85 (
struct V_9 * V_10 )
{
struct V_5 * V_5 = F_84 ( V_10 ) ;
unsigned int V_188 = F_81 ( V_10 ) ;
if ( V_188 & V_190 )
V_5 -> V_143 |= V_144 ;
else
V_5 -> V_143 &= ~ V_144 ;
if ( V_188 & V_192 )
V_5 -> V_143 |= V_145 ;
else
V_5 -> V_143 &= ~ V_145 ;
if ( V_188 & V_194 )
V_5 -> V_143 |= V_244 ;
else
V_5 -> V_143 &= ~ V_244 ;
if ( V_188 & V_196 )
V_5 -> V_143 |= V_245 ;
else
V_5 -> V_143 &= ~ V_245 ;
if ( V_188 & V_242 )
V_5 -> V_143 |= V_246 ;
else
V_5 -> V_143 &= ~ V_246 ;
}
static int
F_86 (
struct V_247 * V_79 ,
struct V_9 * V_10 ,
struct V_206 * V_207 )
{
struct V_248 * V_78 = V_10 -> V_23 ;
if ( ( V_10 -> V_83 . V_222 || V_10 -> V_249 ) &&
F_87 ( V_10 ) != ( V_207 -> V_209 & V_237 ) )
return - V_16 ;
if ( V_207 -> V_209 & V_237 ) {
if ( V_78 -> V_142 . V_250 == 0 || V_78 -> V_142 . V_251 == 0 ||
( V_10 -> V_83 . V_211 % V_78 -> V_142 . V_251 ) )
return - V_16 ;
}
if ( ( ( V_10 -> V_83 . V_199 & ( V_200 | V_201 ) ) ||
( V_207 -> V_209 & ( V_190 | V_192 ) ) ) &&
! F_22 ( V_252 ) )
return - V_59 ;
F_83 ( V_10 , V_207 -> V_209 ) ;
F_85 ( V_10 ) ;
F_88 ( V_79 , V_10 , V_253 ) ;
F_40 ( V_79 , V_10 , V_86 ) ;
F_89 ( V_78 , V_254 ) ;
return 0 ;
}
static int
F_90 (
struct V_9 * V_10 ,
struct V_206 * V_207 ,
int * V_255 )
{
struct V_5 * V_5 = F_84 ( V_10 ) ;
int error ;
* V_255 = 0 ;
if ( V_207 -> V_209 & V_242 ) {
if ( ! ( F_7 ( V_5 -> V_21 ) || F_8 ( V_5 -> V_21 ) ) )
return - V_16 ;
if ( V_10 -> V_23 -> V_142 . V_256 != V_122 )
return - V_16 ;
}
if ( ( V_207 -> V_209 & V_242 ) && F_91 ( V_5 ) )
return 0 ;
if ( ! ( V_207 -> V_209 & V_242 ) && ! F_91 ( V_5 ) )
return 0 ;
F_38 ( V_10 , V_151 | V_141 ) ;
error = F_92 ( V_5 -> V_257 ) ;
if ( error )
goto V_150;
error = F_93 ( V_5 -> V_257 ) ;
if ( error )
goto V_150;
* V_255 = V_151 | V_141 ;
return 0 ;
V_150:
F_70 ( V_10 , V_151 | V_141 ) ;
return error ;
}
static struct V_247 *
F_94 (
struct V_9 * V_10 ,
int V_255 )
{
struct V_248 * V_78 = V_10 -> V_23 ;
struct V_247 * V_79 ;
int error = - V_258 ;
if ( V_78 -> V_259 & V_260 )
goto V_150;
error = - V_80 ;
if ( F_35 ( V_78 ) )
goto V_150;
error = F_36 ( V_78 , & F_37 ( V_78 ) -> V_81 , 0 , 0 , 0 , & V_79 ) ;
if ( error )
return F_16 ( error ) ;
F_38 ( V_10 , V_82 ) ;
F_39 ( V_79 , V_10 , V_82 | V_255 ) ;
V_255 = 0 ;
if ( ! F_95 ( F_84 ( V_10 ) ) ) {
error = - V_59 ;
goto V_261;
}
if ( V_78 -> V_259 & V_262 )
F_96 ( V_79 ) ;
return V_79 ;
V_261:
F_97 ( V_79 ) ;
V_150:
if ( V_255 )
F_70 ( V_10 , V_255 ) ;
return F_16 ( error ) ;
}
static int
F_98 (
struct V_9 * V_10 ,
struct V_206 * V_207 )
{
struct V_248 * V_78 = V_10 -> V_23 ;
if ( ( V_207 -> V_209 & V_239 ) && ! F_7 ( F_84 ( V_10 ) -> V_21 ) )
return - V_16 ;
if ( ( V_207 -> V_209 & V_233 ) &&
! F_8 ( F_84 ( V_10 ) -> V_21 ) )
return - V_16 ;
if ( F_7 ( F_84 ( V_10 ) -> V_21 ) && V_10 -> V_83 . V_222 &&
( ( V_10 -> V_83 . V_211 << V_78 -> V_142 . V_212 ) != V_207 -> V_210 ) )
return - V_16 ;
if ( V_207 -> V_210 != 0 ) {
T_24 V_117 ;
T_25 V_263 ;
V_263 = F_99 ( V_78 , V_207 -> V_210 ) ;
if ( V_263 > V_264 )
return - V_16 ;
if ( F_87 ( V_10 ) ||
( V_207 -> V_209 & V_237 ) ) {
V_117 = V_78 -> V_142 . V_251 << V_78 -> V_142 . V_212 ;
} else {
V_117 = V_78 -> V_142 . V_256 ;
if ( V_263 > V_78 -> V_142 . V_265 / 2 )
return - V_16 ;
}
if ( V_207 -> V_210 % V_117 )
return - V_16 ;
} else
V_207 -> V_209 &= ~ ( V_239 | V_233 ) ;
return 0 ;
}
static int
F_100 (
struct V_9 * V_10 ,
struct V_206 * V_207 )
{
if ( V_207 -> V_213 > ( T_22 ) - 1 &&
! F_101 ( & V_10 -> V_23 -> V_142 ) )
return - V_16 ;
if ( F_102 () == & V_266 )
return 0 ;
if ( F_82 ( V_10 ) != V_207 -> V_213 )
return - V_16 ;
if ( ( V_207 -> V_209 & V_235 ) !=
( V_10 -> V_83 . V_199 & V_236 ) )
return - V_16 ;
return 0 ;
}
STATIC int
F_103 (
T_6 * V_10 ,
struct V_206 * V_207 )
{
struct V_248 * V_78 = V_10 -> V_23 ;
struct V_247 * V_79 ;
struct V_267 * V_268 = NULL ;
struct V_267 * V_269 = NULL ;
struct V_267 * V_270 = NULL ;
int V_271 ;
int V_255 = 0 ;
F_104 ( V_10 ) ;
V_271 = F_100 ( V_10 , V_207 ) ;
if ( V_271 )
return V_271 ;
if ( F_105 ( V_78 ) ) {
V_271 = F_106 ( V_10 , V_10 -> V_83 . V_272 ,
V_10 -> V_83 . V_273 , V_207 -> V_213 ,
V_274 , & V_268 , NULL , & V_269 ) ;
if ( V_271 )
return V_271 ;
}
V_271 = F_90 ( V_10 , V_207 , & V_255 ) ;
if ( V_271 )
goto V_275;
V_79 = F_94 ( V_10 , V_255 ) ;
if ( F_23 ( V_79 ) ) {
V_271 = F_24 ( V_79 ) ;
goto V_275;
}
if ( F_107 ( V_78 ) && F_108 ( V_78 ) &&
F_82 ( V_10 ) != V_207 -> V_213 ) {
V_271 = F_109 ( V_79 , V_10 , V_268 , NULL , V_269 ,
F_22 ( V_276 ) ? V_277 : 0 ) ;
if ( V_271 )
goto V_278;
}
V_271 = F_98 ( V_10 , V_207 ) ;
if ( V_271 )
goto V_278;
V_271 = F_86 ( V_79 , V_10 , V_207 ) ;
if ( V_271 )
goto V_278;
if ( ( F_84 ( V_10 ) -> V_21 & ( V_279 | V_280 ) ) &&
! F_110 ( F_84 ( V_10 ) , V_281 ) )
F_84 ( V_10 ) -> V_21 &= ~ ( V_279 | V_280 ) ;
if ( F_82 ( V_10 ) != V_207 -> V_213 ) {
if ( F_107 ( V_78 ) && F_108 ( V_78 ) ) {
V_270 = F_111 ( V_79 , V_10 ,
& V_10 -> V_282 , V_269 ) ;
}
ASSERT ( V_10 -> V_83 . V_241 > 1 ) ;
F_112 ( V_10 , V_207 -> V_213 ) ;
}
if ( V_10 -> V_83 . V_199 & ( V_240 | V_234 ) )
V_10 -> V_83 . V_211 = V_207 -> V_210 >> V_78 -> V_142 . V_212 ;
else
V_10 -> V_83 . V_211 = 0 ;
V_271 = F_41 ( V_79 ) ;
F_113 ( V_270 ) ;
F_113 ( V_268 ) ;
F_113 ( V_269 ) ;
return V_271 ;
V_278:
F_97 ( V_79 ) ;
V_275:
F_113 ( V_268 ) ;
F_113 ( V_269 ) ;
return V_271 ;
}
STATIC int
F_114 (
T_6 * V_10 ,
struct V_12 * V_56 ,
void V_14 * V_87 )
{
struct V_206 V_207 ;
int error ;
if ( F_17 ( & V_207 , V_87 , sizeof( V_207 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_103 ( V_10 , & V_207 ) ;
F_44 ( V_56 ) ;
return error ;
}
STATIC int
F_115 (
T_6 * V_10 ,
void V_14 * V_87 )
{
unsigned int V_103 ;
V_103 = F_79 ( V_10 -> V_83 . V_199 ) ;
if ( F_11 ( V_87 , & V_103 , sizeof( V_103 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_116 (
struct V_9 * V_10 ,
struct V_12 * V_56 ,
void V_14 * V_87 )
{
struct V_247 * V_79 ;
struct V_206 V_207 ;
unsigned int V_103 ;
int V_255 = 0 ;
int error ;
if ( F_17 ( & V_103 , V_87 , sizeof( V_103 ) ) )
return - V_35 ;
if ( V_103 & ~ ( V_189 | V_191 | \
V_195 | V_197 | \
V_193 ) )
return - V_283 ;
V_207 . V_209 = F_78 ( V_103 , F_81 ( V_10 ) ) ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_90 ( V_10 , & V_207 , & V_255 ) ;
if ( error )
goto V_284;
V_79 = F_94 ( V_10 , V_255 ) ;
if ( F_23 ( V_79 ) ) {
error = F_24 ( V_79 ) ;
goto V_284;
}
error = F_86 ( V_79 , V_10 , & V_207 ) ;
if ( error ) {
F_97 ( V_79 ) ;
goto V_284;
}
error = F_41 ( V_79 ) ;
V_284:
F_44 ( V_56 ) ;
return error ;
}
STATIC int
F_117 ( void * * V_285 , struct V_286 * V_287 , int * V_288 )
{
struct V_289 V_14 * V_290 = (struct V_289 V_14 * ) * V_285 ;
if ( F_11 ( V_290 , V_287 , sizeof( struct V_289 ) ) )
return - V_35 ;
* V_285 += sizeof( struct V_289 ) ;
return 0 ;
}
STATIC int
F_118 (
struct V_9 * V_10 ,
int V_136 ,
unsigned int V_1 ,
void V_14 * V_87 )
{
struct V_286 V_291 ;
int error ;
if ( F_17 ( & V_291 , V_87 , sizeof( struct V_286 ) ) )
return - V_35 ;
if ( V_291 . V_292 < 2 )
return - V_16 ;
V_291 . V_293 = ( V_1 == V_294 ? V_295 : 0 ) ;
if ( V_136 & V_148 )
V_291 . V_293 |= V_296 ;
error = F_119 ( V_10 , & V_291 , F_117 ,
( V_297 struct V_289 * ) V_87 + 1 ) ;
if ( error )
return error ;
if ( F_11 ( V_87 , & V_291 , sizeof( struct V_289 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_120 ( void * * V_285 , struct V_286 * V_287 , int * V_288 )
{
struct V_286 V_14 * V_290 = (struct V_286 V_14 * ) * V_285 ;
if ( F_11 ( V_290 , V_287 , sizeof( struct V_286 ) ) )
return - V_35 ;
* V_285 += sizeof( struct V_286 ) ;
return 0 ;
}
STATIC int
F_121 (
struct V_9 * V_10 ,
void V_14 * V_87 )
{
struct V_286 V_291 ;
int error ;
if ( F_17 ( & V_291 , V_87 , sizeof( V_291 ) ) )
return - V_35 ;
if ( V_291 . V_292 < 2 )
return - V_16 ;
if ( V_291 . V_293 & ( ~ V_298 ) )
return - V_16 ;
error = F_119 ( V_10 , & V_291 , F_120 ,
( V_297 struct V_286 * ) V_87 + 1 ) ;
if ( error )
return error ;
if ( F_11 ( V_87 , & V_291 , sizeof( struct V_286 ) ) )
return - V_35 ;
return 0 ;
}
int
F_122 (
T_26 * V_299 )
{
T_6 * V_10 , * V_300 ;
struct V_6 V_7 , V_301 ;
int error = 0 ;
V_7 = F_2 ( ( int ) V_299 -> V_302 ) ;
if ( ! V_7 . V_12 ) {
error = - V_16 ;
goto V_92;
}
if ( ! ( V_7 . V_12 -> V_71 & V_66 ) ||
! ( V_7 . V_12 -> V_71 & V_303 ) ||
( V_7 . V_12 -> V_69 & V_64 ) ) {
error = - V_13 ;
goto V_304;
}
V_301 = F_2 ( ( int ) V_299 -> V_305 ) ;
if ( ! V_301 . V_12 ) {
error = - V_16 ;
goto V_304;
}
if ( ! ( V_301 . V_12 -> V_71 & V_66 ) ||
! ( V_301 . V_12 -> V_71 & V_303 ) ||
( V_301 . V_12 -> V_69 & V_64 ) ) {
error = - V_13 ;
goto V_306;
}
if ( F_123 ( F_3 ( V_7 . V_12 ) ) ||
F_123 ( F_3 ( V_301 . V_12 ) ) ) {
error = - V_16 ;
goto V_306;
}
if ( V_7 . V_12 -> V_307 != & V_308 ||
V_301 . V_12 -> V_307 != & V_308 ) {
error = - V_16 ;
goto V_306;
}
V_10 = F_6 ( F_3 ( V_7 . V_12 ) ) ;
V_300 = F_6 ( F_3 ( V_301 . V_12 ) ) ;
if ( V_10 -> V_23 != V_300 -> V_23 ) {
error = - V_16 ;
goto V_306;
}
if ( V_10 -> V_34 == V_300 -> V_34 ) {
error = - V_16 ;
goto V_306;
}
if ( F_35 ( V_10 -> V_23 ) ) {
error = - V_80 ;
goto V_306;
}
error = F_124 ( V_10 , V_300 , V_299 ) ;
V_306:
F_12 ( V_301 ) ;
V_304:
F_12 ( V_7 ) ;
V_92:
return error ;
}
long
F_125 (
struct V_12 * V_56 ,
unsigned int V_1 ,
unsigned long V_309 )
{
struct V_5 * V_5 = F_3 ( V_56 ) ;
struct V_9 * V_10 = F_6 ( V_5 ) ;
struct V_248 * V_78 = V_10 -> V_23 ;
void V_14 * V_87 = ( void V_14 * ) V_309 ;
int V_136 = 0 ;
int error ;
if ( V_56 -> V_71 & V_72 )
V_136 |= V_148 ;
F_126 ( V_10 ) ;
switch ( V_1 ) {
case V_310 :
return F_127 ( V_78 , V_87 ) ;
case V_164 :
case V_166 :
case V_156 :
case V_158 :
case V_165 :
case V_167 :
case V_157 :
case V_159 :
case V_155 : {
T_17 V_137 ;
if ( F_17 ( & V_137 , V_87 , sizeof( V_137 ) ) )
return - V_35 ;
return F_61 ( V_10 , V_5 , V_56 , V_136 , V_1 , & V_137 ) ;
}
case V_311 : {
struct V_312 V_313 ;
T_27 * V_314 =
F_87 ( V_10 ) ?
V_78 -> V_315 : V_78 -> V_316 ;
V_313 . V_317 = V_313 . V_318 = V_314 -> V_319 ;
V_313 . V_320 = V_120 & ~ ( V_313 . V_318 - 1 ) ;
if ( F_11 ( V_87 , & V_313 , sizeof( V_313 ) ) )
return - V_35 ;
return 0 ;
}
case V_182 :
case V_321 :
case V_180 :
return F_71 ( V_78 , V_1 , V_87 ) ;
case V_322 :
return F_75 ( V_78 , V_87 ) ;
case V_323 :
return F_77 ( V_78 , V_87 ) ;
case V_324 :
return F_128 ( V_5 -> V_32 , ( int V_14 * ) V_87 ) ;
case V_325 :
return F_80 ( V_10 , 0 , V_87 ) ;
case V_326 :
return F_80 ( V_10 , 1 , V_87 ) ;
case V_327 :
return F_114 ( V_10 , V_56 , V_87 ) ;
case V_328 :
return F_115 ( V_10 , V_87 ) ;
case V_329 :
return F_116 ( V_10 , V_56 , V_87 ) ;
case V_330 : {
struct V_88 V_331 ;
if ( F_17 ( & V_331 , V_87 , sizeof( V_331 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_34 ( V_10 , V_331 . V_94 ,
V_331 . V_95 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_332 :
case V_294 :
return F_118 ( V_10 , V_136 , V_1 , V_87 ) ;
case V_333 :
return F_121 ( V_10 , V_87 ) ;
case V_11 :
case V_334 :
case V_26 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_87 , sizeof( V_2 ) ) )
return - V_35 ;
return F_1 ( V_1 , & V_2 ) ;
}
case V_335 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_87 , sizeof( T_1 ) ) )
return - V_35 ;
return F_20 ( V_56 , & V_2 ) ;
}
case V_336 :
return F_42 ( V_56 , V_87 ) ;
case V_337 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_87 , sizeof( T_1 ) ) )
return - V_35 ;
return F_33 ( V_56 , & V_2 ) ;
}
case V_338 :
return F_45 ( V_56 , V_87 ) ;
case V_339 :
return F_58 ( V_56 , V_87 ) ;
case V_340 : {
struct V_341 V_299 ;
if ( F_17 ( & V_299 , V_87 , sizeof( T_26 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_122 ( & V_299 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_342 : {
T_28 V_92 ;
error = F_129 ( V_78 , & V_92 ) ;
if ( error )
return error ;
if ( F_11 ( V_87 , & V_92 , sizeof( V_92 ) ) )
return - V_35 ;
return 0 ;
}
case V_343 : {
T_29 V_344 ;
T_30 V_345 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( V_78 -> V_259 & V_260 )
return - V_258 ;
if ( F_17 ( & V_344 , V_87 , sizeof( V_344 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
V_345 = V_344 . V_346 ;
error = F_130 ( V_78 , & V_345 , & V_344 ) ;
F_44 ( V_56 ) ;
if ( error )
return error ;
if ( F_11 ( V_87 , & V_344 , sizeof( V_344 ) ) )
return - V_35 ;
return 0 ;
}
case V_347 : {
T_29 V_92 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
error = F_130 ( V_78 , NULL , & V_92 ) ;
if ( error )
return error ;
if ( F_11 ( V_87 , & V_92 , sizeof( V_92 ) ) )
return - V_35 ;
return 0 ;
}
case V_348 : {
T_31 V_345 ;
if ( F_17 ( & V_345 , V_87 , sizeof( V_345 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_131 ( V_78 , & V_345 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_349 : {
T_32 V_345 ;
if ( F_17 ( & V_345 , V_87 , sizeof( V_345 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_132 ( V_78 , & V_345 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_350 : {
T_33 V_345 ;
if ( F_17 ( & V_345 , V_87 , sizeof( V_345 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_133 ( V_78 , & V_345 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_351 : {
T_14 V_345 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_134 ( V_345 , ( T_14 V_14 * ) V_87 ) )
return - V_35 ;
return F_135 ( V_78 , V_345 ) ;
}
case V_352 : {
T_34 V_345 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_17 ( & V_345 , V_87 , sizeof( V_345 ) ) )
return - V_35 ;
return F_136 ( V_345 . V_353 , V_78 ) ;
}
case V_354 :
if ( ! F_22 ( V_58 ) )
return - V_59 ;
return F_137 ( V_78 , 1 ) ;
case V_355 : {
struct V_356 V_357 ;
struct V_358 V_359 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( V_78 -> V_259 & V_260 )
return - V_258 ;
if ( F_17 ( & V_357 , V_87 , sizeof( V_357 ) ) )
return - V_35 ;
error = F_138 ( & V_357 , & V_359 ) ;
if ( error )
return error ;
return F_139 ( V_78 , & V_359 ) ;
}
default:
return - V_360 ;
}
}
