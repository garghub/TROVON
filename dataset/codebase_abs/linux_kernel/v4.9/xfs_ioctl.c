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
error = - V_59 ;
goto V_60;
}
if ( F_8 ( V_5 -> V_21 ) && ( V_57 & V_66 ) ) {
error = - V_67 ;
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
V_56 -> V_68 |= V_69 ;
V_56 -> V_70 |= V_71 ;
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
T_5 V_72 ;
int error ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
V_15 = F_19 ( V_40 , V_2 ) ;
if ( F_23 ( V_15 ) )
return F_24 ( V_15 ) ;
if ( ! F_5 ( V_15 ) -> V_73 -> V_74 ) {
error = - V_16 ;
goto V_60;
}
if ( F_17 ( & V_72 , V_2 -> V_37 , sizeof( T_5 ) ) ) {
error = - V_35 ;
goto V_60;
}
error = F_5 ( V_15 ) -> V_73 -> V_74 ( V_15 , V_2 -> V_36 , V_72 ) ;
V_60:
F_30 ( V_15 ) ;
return error ;
}
int
F_34 (
T_6 * V_10 ,
T_7 V_75 ,
T_8 V_76 )
{
T_9 * V_77 = V_10 -> V_23 ;
T_10 * V_78 ;
int error ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_35 ( V_77 ) )
return - V_79 ;
error = F_36 ( V_77 , & F_37 ( V_77 ) -> V_80 , 0 , 0 , 0 , & V_78 ) ;
if ( error )
return error ;
F_38 ( V_10 , V_81 ) ;
F_39 ( V_78 , V_10 , V_81 ) ;
V_10 -> V_82 . V_83 = V_75 ;
V_10 -> V_82 . V_84 = V_76 ;
F_40 ( V_78 , V_10 , V_85 ) ;
error = F_41 ( V_78 ) ;
return error ;
}
STATIC int
F_42 (
struct V_12 * V_40 ,
void V_14 * V_86 )
{
int error ;
struct V_87 V_88 ;
T_11 V_89 ;
struct V_15 * V_15 ;
if ( ! F_22 ( V_90 ) )
return - V_59 ;
if ( F_17 ( & V_89 , V_86 , sizeof( T_11 ) ) )
return - V_35 ;
error = F_43 ( V_40 ) ;
if ( error )
return error ;
V_15 = F_19 ( V_40 , & V_89 . V_2 ) ;
if ( F_23 ( V_15 ) ) {
F_44 ( V_40 ) ;
return F_24 ( V_15 ) ;
}
if ( F_27 ( F_5 ( V_15 ) ) || F_26 ( F_5 ( V_15 ) ) ) {
error = - V_59 ;
goto V_91;
}
if ( F_17 ( & V_88 , V_89 . V_92 , sizeof( V_88 ) ) ) {
error = - V_35 ;
goto V_91;
}
error = F_34 ( F_6 ( F_5 ( V_15 ) ) , V_88 . V_93 ,
V_88 . V_94 ) ;
V_91:
F_44 ( V_40 ) ;
F_30 ( V_15 ) ;
return error ;
}
STATIC int
F_45 (
struct V_12 * V_40 ,
void V_14 * V_86 )
{
int error = - V_95 ;
T_12 * V_96 ;
struct V_97 V_14 * V_98 = V_86 ;
T_13 V_99 ;
struct V_15 * V_15 ;
char * V_100 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_17 ( & V_99 , V_86 , sizeof( T_13 ) ) )
return - V_35 ;
if ( V_99 . V_101 < sizeof( struct V_102 ) ||
V_99 . V_101 > V_103 )
return - V_16 ;
if ( V_99 . V_104 & ~ ( V_105 | V_106 ) )
return - V_16 ;
V_15 = F_19 ( V_40 , & V_99 . V_2 ) ;
if ( F_23 ( V_15 ) )
return F_24 ( V_15 ) ;
V_100 = F_46 ( V_99 . V_101 , V_107 ) ;
if ( ! V_100 )
goto V_60;
V_96 = ( T_12 * ) & V_99 . V_108 ;
error = F_47 ( F_6 ( F_5 ( V_15 ) ) , V_100 , V_99 . V_101 ,
V_99 . V_104 , V_96 ) ;
if ( error )
goto V_109;
if ( F_11 ( & V_98 -> V_108 , V_96 , sizeof( T_12 ) ) ) {
error = - V_35 ;
goto V_109;
}
if ( F_11 ( V_99 . V_110 , V_100 , V_99 . V_101 ) )
error = - V_35 ;
V_109:
F_48 ( V_100 ) ;
V_60:
F_30 ( V_15 ) ;
return error ;
}
int
F_49 (
struct V_5 * V_5 ,
unsigned char * V_111 ,
unsigned char V_14 * V_112 ,
T_14 * V_113 ,
T_14 V_104 )
{
unsigned char * V_100 ;
int error = - V_35 ;
if ( * V_113 > V_114 )
return - V_16 ;
V_100 = F_46 ( * V_113 , V_107 ) ;
if ( ! V_100 )
return - V_95 ;
error = F_50 ( F_6 ( V_5 ) , V_111 , V_100 , ( int * ) V_113 , V_104 ) ;
if ( error )
goto V_109;
if ( F_11 ( V_112 , V_100 , * V_113 ) )
error = - V_35 ;
V_109:
F_48 ( V_100 ) ;
return error ;
}
int
F_51 (
struct V_5 * V_5 ,
unsigned char * V_111 ,
const unsigned char V_14 * V_112 ,
T_14 V_113 ,
T_14 V_104 )
{
unsigned char * V_100 ;
int error ;
if ( F_27 ( V_5 ) || F_26 ( V_5 ) )
return - V_59 ;
if ( V_113 > V_114 )
return - V_16 ;
V_100 = F_52 ( V_112 , V_113 ) ;
if ( F_23 ( V_100 ) )
return F_24 ( V_100 ) ;
error = F_53 ( F_6 ( V_5 ) , V_111 , V_100 , V_113 , V_104 ) ;
if ( ! error )
F_54 ( V_5 , V_111 , V_104 ) ;
F_55 ( V_100 ) ;
return error ;
}
int
F_56 (
struct V_5 * V_5 ,
unsigned char * V_111 ,
T_14 V_104 )
{
int error ;
if ( F_27 ( V_5 ) || F_26 ( V_5 ) )
return - V_59 ;
error = F_57 ( F_6 ( V_5 ) , V_111 , V_104 ) ;
if ( ! error )
F_54 ( V_5 , V_111 , V_104 ) ;
return error ;
}
STATIC int
F_58 (
struct V_12 * V_40 ,
void V_14 * V_86 )
{
int error ;
T_15 * V_115 ;
T_16 V_116 ;
struct V_15 * V_15 ;
unsigned int V_117 , V_118 ;
unsigned char * V_119 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_17 ( & V_116 , V_86 , sizeof( T_16 ) ) )
return - V_35 ;
if ( V_116 . V_120 >= V_121 / sizeof( T_15 ) )
return - V_122 ;
V_15 = F_19 ( V_40 , & V_116 . V_2 ) ;
if ( F_23 ( V_15 ) )
return F_24 ( V_15 ) ;
error = - V_122 ;
V_118 = V_116 . V_120 * sizeof( T_15 ) ;
if ( ! V_118 || V_118 > 16 * V_123 )
goto V_60;
V_115 = F_52 ( V_116 . V_115 , V_118 ) ;
if ( F_23 ( V_115 ) ) {
error = F_24 ( V_115 ) ;
goto V_60;
}
error = - V_95 ;
V_119 = F_59 ( V_124 , V_125 ) ;
if ( ! V_119 )
goto V_126;
error = 0 ;
for ( V_117 = 0 ; V_117 < V_116 . V_120 ; V_117 ++ ) {
V_115 [ V_117 ] . V_127 = F_60 ( ( char * ) V_119 ,
V_115 [ V_117 ] . V_128 , V_124 ) ;
if ( V_115 [ V_117 ] . V_127 == 0 || V_115 [ V_117 ] . V_127 == V_124 )
error = - V_129 ;
if ( V_115 [ V_117 ] . V_127 < 0 )
break;
switch ( V_115 [ V_117 ] . V_130 ) {
case V_131 :
V_115 [ V_117 ] . V_127 = F_49 (
F_5 ( V_15 ) , V_119 ,
V_115 [ V_117 ] . V_132 , & V_115 [ V_117 ] . V_133 ,
V_115 [ V_117 ] . V_134 ) ;
break;
case V_135 :
V_115 [ V_117 ] . V_127 = F_43 ( V_40 ) ;
if ( V_115 [ V_117 ] . V_127 )
break;
V_115 [ V_117 ] . V_127 = F_51 (
F_5 ( V_15 ) , V_119 ,
V_115 [ V_117 ] . V_132 , V_115 [ V_117 ] . V_133 ,
V_115 [ V_117 ] . V_134 ) ;
F_44 ( V_40 ) ;
break;
case V_136 :
V_115 [ V_117 ] . V_127 = F_43 ( V_40 ) ;
if ( V_115 [ V_117 ] . V_127 )
break;
V_115 [ V_117 ] . V_127 = F_56 (
F_5 ( V_15 ) , V_119 ,
V_115 [ V_117 ] . V_134 ) ;
F_44 ( V_40 ) ;
break;
default:
V_115 [ V_117 ] . V_127 = - V_16 ;
}
}
if ( F_11 ( V_116 . V_115 , V_115 , V_118 ) )
error = - V_35 ;
F_55 ( V_119 ) ;
V_126:
F_55 ( V_115 ) ;
V_60:
F_30 ( V_15 ) ;
return error ;
}
int
F_61 (
struct V_12 * V_56 ,
unsigned int V_1 ,
T_17 * V_137 )
{
struct V_5 * V_5 = F_3 ( V_56 ) ;
struct V_9 * V_10 = F_6 ( V_5 ) ;
struct V_138 V_138 ;
enum V_139 V_104 = 0 ;
T_18 V_140 = V_141 ;
int error ;
if ( ! F_62 ( & V_10 -> V_23 -> V_142 ) &&
! F_22 ( V_58 ) )
return - V_59 ;
if ( V_5 -> V_143 & ( V_144 | V_145 ) )
return - V_59 ;
if ( ! ( V_56 -> V_70 & V_66 ) )
return - V_13 ;
if ( ! F_7 ( V_5 -> V_21 ) )
return - V_16 ;
if ( V_56 -> V_68 & V_146 )
V_104 |= V_147 ;
if ( V_56 -> V_70 & V_71 )
V_104 |= V_148 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
F_38 ( V_10 , V_140 ) ;
error = F_63 ( V_5 , & V_140 , false ) ;
if ( error )
goto V_149;
F_38 ( V_10 , V_150 ) ;
V_140 |= V_150 ;
switch ( V_137 -> V_151 ) {
case 0 :
break;
case 1 :
V_137 -> V_152 += V_56 -> V_153 ;
break;
case 2 :
V_137 -> V_152 += F_64 ( V_10 ) ;
break;
default:
error = - V_16 ;
goto V_149;
}
switch ( V_1 ) {
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
if ( V_137 -> V_159 <= 0 ) {
error = - V_16 ;
goto V_149;
}
break;
default:
V_137 -> V_159 = 0 ;
break;
}
if ( V_137 -> V_152 < 0 ||
V_137 -> V_152 > V_5 -> V_17 -> V_160 ||
V_137 -> V_152 + V_137 -> V_159 < 0 ||
V_137 -> V_152 + V_137 -> V_159 >= V_5 -> V_17 -> V_160 ) {
error = - V_16 ;
goto V_149;
}
switch ( V_1 ) {
case V_154 :
V_104 |= V_161 ;
error = F_65 ( V_10 , V_137 -> V_152 , V_137 -> V_159 ) ;
break;
case V_155 :
case V_156 :
V_104 |= V_161 ;
error = F_66 ( V_10 , V_137 -> V_152 , V_137 -> V_159 ,
V_162 ) ;
break;
case V_157 :
case V_158 :
error = F_67 ( V_10 , V_137 -> V_152 , V_137 -> V_159 ) ;
break;
case V_163 :
case V_164 :
case V_165 :
case V_166 :
V_104 |= V_167 ;
if ( V_137 -> V_152 > F_64 ( V_10 ) ) {
error = F_66 ( V_10 , F_64 ( V_10 ) ,
V_137 -> V_152 - F_64 ( V_10 ) , 0 ) ;
if ( error )
goto V_149;
}
V_138 . V_168 = V_169 ;
V_138 . V_170 = V_137 -> V_152 ;
error = F_68 ( F_69 ( V_56 ) , & V_138 ) ;
break;
default:
ASSERT ( 0 ) ;
error = - V_16 ;
}
if ( error )
goto V_149;
error = F_70 ( V_10 , V_104 ) ;
V_149:
F_71 ( V_10 , V_140 ) ;
F_44 ( V_56 ) ;
return error ;
}
STATIC int
F_72 (
T_9 * V_77 ,
unsigned int V_1 ,
void V_14 * V_86 )
{
T_19 V_171 ;
int V_172 ;
T_20 V_173 ;
int V_174 ;
int error ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_35 ( V_77 ) )
return - V_79 ;
if ( F_17 ( & V_171 , V_86 , sizeof( T_19 ) ) )
return - V_35 ;
if ( F_17 ( & V_173 , V_171 . V_175 , sizeof( V_176 ) ) )
return - V_35 ;
if ( ( V_172 = V_171 . V_177 ) <= 0 )
return - V_16 ;
if ( V_171 . V_178 == NULL )
return - V_16 ;
if ( V_1 == V_179 )
error = F_73 ( V_77 , & V_173 , & V_172 ,
V_171 . V_178 , V_180 ) ;
else if ( V_1 == V_181 )
error = F_74 ( V_77 , V_173 , V_171 . V_178 ,
sizeof( V_182 ) , NULL , & V_174 ) ;
else
error = F_75 ( V_77 , & V_173 , & V_172 , F_74 ,
sizeof( V_182 ) , V_171 . V_178 ,
& V_174 ) ;
if ( error )
return error ;
if ( V_171 . V_183 != NULL ) {
if ( F_11 ( V_171 . V_175 , & V_173 ,
sizeof( T_20 ) ) )
return - V_35 ;
if ( F_11 ( V_171 . V_183 , & V_172 , sizeof( V_172 ) ) )
return - V_35 ;
}
return 0 ;
}
STATIC int
F_76 (
T_9 * V_77 ,
void V_14 * V_86 )
{
T_21 V_184 ;
int error ;
error = F_77 ( V_77 , & V_184 , 3 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_184 , sizeof( V_185 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_78 (
T_9 * V_77 ,
void V_14 * V_86 )
{
T_21 V_184 ;
int error ;
error = F_77 ( V_77 , & V_184 , 4 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_184 , sizeof( V_184 ) ) )
return - V_35 ;
return 0 ;
}
STATIC unsigned int
F_79 (
unsigned int V_104 ,
unsigned int V_186 )
{
unsigned int V_187 = V_186 ;
if ( V_104 & V_188 )
V_187 |= V_189 ;
else
V_187 &= ~ V_189 ;
if ( V_104 & V_190 )
V_187 |= V_191 ;
else
V_187 &= ~ V_191 ;
if ( V_104 & V_192 )
V_187 |= V_193 ;
else
V_187 &= ~ V_193 ;
if ( V_104 & V_194 )
V_187 |= V_195 ;
else
V_187 &= ~ V_195 ;
if ( V_104 & V_196 )
V_187 |= V_197 ;
else
V_187 &= ~ V_197 ;
return V_187 ;
}
STATIC unsigned int
F_80 (
T_22 V_198 )
{
unsigned int V_104 = 0 ;
if ( V_198 & V_199 )
V_104 |= V_188 ;
if ( V_198 & V_200 )
V_104 |= V_190 ;
if ( V_198 & V_201 )
V_104 |= V_192 ;
if ( V_198 & V_202 )
V_104 |= V_194 ;
if ( V_198 & V_203 )
V_104 |= V_196 ;
return V_104 ;
}
STATIC int
F_81 (
T_6 * V_10 ,
int V_204 ,
void V_14 * V_86 )
{
struct V_205 V_206 ;
memset ( & V_206 , 0 , sizeof( struct V_205 ) ) ;
F_38 ( V_10 , V_207 ) ;
V_206 . V_208 = F_82 ( V_10 ) ;
V_206 . V_209 = V_10 -> V_82 . V_210 << V_10 -> V_23 -> V_142 . V_211 ;
V_206 . V_212 = V_10 -> V_82 . V_213 <<
V_10 -> V_23 -> V_142 . V_211 ;
V_206 . V_214 = F_83 ( V_10 ) ;
if ( V_204 ) {
if ( V_10 -> V_215 ) {
if ( V_10 -> V_215 -> V_216 & V_217 )
V_206 . V_218 = V_10 -> V_215 -> V_219 /
sizeof( V_220 ) ;
else
V_206 . V_218 = V_10 -> V_82 . V_221 ;
} else
V_206 . V_218 = 0 ;
} else {
if ( V_10 -> V_222 . V_216 & V_217 )
V_206 . V_218 = V_10 -> V_222 . V_219 /
sizeof( V_220 ) ;
else
V_206 . V_218 = V_10 -> V_82 . V_223 ;
}
F_71 ( V_10 , V_207 ) ;
if ( F_11 ( V_86 , & V_206 , sizeof( V_206 ) ) )
return - V_35 ;
return 0 ;
}
STATIC void
F_84 (
struct V_9 * V_10 ,
unsigned int V_187 )
{
unsigned int V_198 ;
T_23 V_224 ;
V_198 = ( V_10 -> V_82 . V_198 & V_225 ) ;
if ( V_187 & V_189 )
V_198 |= V_199 ;
if ( V_187 & V_191 )
V_198 |= V_200 ;
if ( V_187 & V_193 )
V_198 |= V_201 ;
if ( V_187 & V_195 )
V_198 |= V_202 ;
if ( V_187 & V_197 )
V_198 |= V_203 ;
if ( V_187 & V_226 )
V_198 |= V_227 ;
if ( V_187 & V_228 )
V_198 |= V_229 ;
if ( F_8 ( F_85 ( V_10 ) -> V_21 ) ) {
if ( V_187 & V_230 )
V_198 |= V_231 ;
if ( V_187 & V_232 )
V_198 |= V_233 ;
if ( V_187 & V_234 )
V_198 |= V_235 ;
if ( V_187 & V_236 )
V_198 |= V_237 ;
} else if ( F_7 ( F_85 ( V_10 ) -> V_21 ) ) {
if ( V_187 & V_238 )
V_198 |= V_239 ;
if ( V_187 & V_240 )
V_198 |= V_241 ;
}
V_10 -> V_82 . V_198 = V_198 ;
if ( V_10 -> V_82 . V_242 < 3 )
return;
V_224 = ( V_10 -> V_82 . V_224 & V_243 ) ;
if ( V_187 & V_244 )
V_224 |= V_245 ;
if ( V_187 & V_246 )
V_224 |= V_247 ;
V_10 -> V_82 . V_224 = V_224 ;
}
STATIC void
F_86 (
struct V_9 * V_10 )
{
struct V_5 * V_5 = F_85 ( V_10 ) ;
unsigned int V_187 = F_82 ( V_10 ) ;
if ( V_187 & V_189 )
V_5 -> V_143 |= V_144 ;
else
V_5 -> V_143 &= ~ V_144 ;
if ( V_187 & V_191 )
V_5 -> V_143 |= V_145 ;
else
V_5 -> V_143 &= ~ V_145 ;
if ( V_187 & V_193 )
V_5 -> V_143 |= V_248 ;
else
V_5 -> V_143 &= ~ V_248 ;
if ( V_187 & V_195 )
V_5 -> V_143 |= V_249 ;
else
V_5 -> V_143 &= ~ V_249 ;
if ( V_187 & V_244 )
V_5 -> V_143 |= V_250 ;
else
V_5 -> V_143 &= ~ V_250 ;
}
static int
F_87 (
struct V_251 * V_78 ,
struct V_9 * V_10 ,
struct V_205 * V_206 )
{
struct V_252 * V_77 = V_10 -> V_23 ;
if ( ( V_10 -> V_82 . V_223 || V_10 -> V_253 ) &&
F_88 ( V_10 ) != ( V_206 -> V_208 & V_238 ) )
return - V_16 ;
if ( V_206 -> V_208 & V_238 ) {
if ( V_77 -> V_142 . V_254 == 0 || V_77 -> V_142 . V_255 == 0 ||
( V_10 -> V_82 . V_210 % V_77 -> V_142 . V_255 ) )
return - V_16 ;
}
if ( ( V_206 -> V_208 & V_238 ) && F_89 ( V_10 ) )
V_10 -> V_82 . V_224 &= ~ V_243 ;
if ( ( V_206 -> V_208 & V_244 ) && F_89 ( V_10 ) )
return - V_16 ;
if ( ( ( V_10 -> V_82 . V_198 & ( V_199 | V_200 ) ) ||
( V_206 -> V_208 & ( V_189 | V_191 ) ) ) &&
! F_22 ( V_256 ) )
return - V_59 ;
F_84 ( V_10 , V_206 -> V_208 ) ;
F_86 ( V_10 ) ;
F_90 ( V_78 , V_10 , V_257 ) ;
F_40 ( V_78 , V_10 , V_85 ) ;
F_91 ( V_77 , V_258 ) ;
return 0 ;
}
static int
F_92 (
struct V_9 * V_10 ,
struct V_205 * V_206 ,
int * V_259 )
{
struct V_5 * V_5 = F_85 ( V_10 ) ;
int error ;
* V_259 = 0 ;
if ( V_206 -> V_208 & V_244 ) {
if ( ! ( F_7 ( V_5 -> V_21 ) || F_8 ( V_5 -> V_21 ) ) )
return - V_16 ;
if ( V_10 -> V_23 -> V_142 . V_260 != V_123 )
return - V_16 ;
}
if ( ( V_206 -> V_208 & V_244 ) && F_93 ( V_5 ) )
return 0 ;
if ( ! ( V_206 -> V_208 & V_244 ) && ! F_93 ( V_5 ) )
return 0 ;
F_38 ( V_10 , V_150 | V_141 ) ;
error = F_94 ( V_5 -> V_261 ) ;
if ( error )
goto V_149;
error = F_95 ( V_5 -> V_261 ) ;
if ( error )
goto V_149;
* V_259 = V_150 | V_141 ;
return 0 ;
V_149:
F_71 ( V_10 , V_150 | V_141 ) ;
return error ;
}
static struct V_251 *
F_96 (
struct V_9 * V_10 ,
int V_259 )
{
struct V_252 * V_77 = V_10 -> V_23 ;
struct V_251 * V_78 ;
int error = - V_262 ;
if ( V_77 -> V_263 & V_264 )
goto V_149;
error = - V_79 ;
if ( F_35 ( V_77 ) )
goto V_149;
error = F_36 ( V_77 , & F_37 ( V_77 ) -> V_80 , 0 , 0 , 0 , & V_78 ) ;
if ( error )
return F_16 ( error ) ;
F_38 ( V_10 , V_81 ) ;
F_39 ( V_78 , V_10 , V_81 | V_259 ) ;
V_259 = 0 ;
if ( ! F_97 ( F_85 ( V_10 ) ) ) {
error = - V_59 ;
goto V_265;
}
if ( V_77 -> V_263 & V_266 )
F_98 ( V_78 ) ;
return V_78 ;
V_265:
F_99 ( V_78 ) ;
V_149:
if ( V_259 )
F_71 ( V_10 , V_259 ) ;
return F_16 ( error ) ;
}
static int
F_100 (
struct V_9 * V_10 ,
struct V_205 * V_206 )
{
struct V_252 * V_77 = V_10 -> V_23 ;
if ( ( V_206 -> V_208 & V_240 ) && ! F_7 ( F_85 ( V_10 ) -> V_21 ) )
return - V_16 ;
if ( ( V_206 -> V_208 & V_234 ) &&
! F_8 ( F_85 ( V_10 ) -> V_21 ) )
return - V_16 ;
if ( F_7 ( F_85 ( V_10 ) -> V_21 ) && V_10 -> V_82 . V_223 &&
( ( V_10 -> V_82 . V_210 << V_77 -> V_142 . V_211 ) != V_206 -> V_209 ) )
return - V_16 ;
if ( V_206 -> V_209 != 0 ) {
T_24 V_118 ;
T_25 V_267 ;
V_267 = F_101 ( V_77 , V_206 -> V_209 ) ;
if ( V_267 > V_268 )
return - V_16 ;
if ( F_88 ( V_10 ) ||
( V_206 -> V_208 & V_238 ) ) {
V_118 = V_77 -> V_142 . V_255 << V_77 -> V_142 . V_211 ;
} else {
V_118 = V_77 -> V_142 . V_260 ;
if ( V_267 > V_77 -> V_142 . V_269 / 2 )
return - V_16 ;
}
if ( V_206 -> V_209 % V_118 )
return - V_16 ;
} else
V_206 -> V_208 &= ~ ( V_240 | V_234 ) ;
return 0 ;
}
static int
F_102 (
struct V_9 * V_10 ,
struct V_205 * V_206 )
{
struct V_252 * V_77 = V_10 -> V_23 ;
if ( ! ( V_206 -> V_208 & V_246 ) )
return 0 ;
if ( ! F_103 ( & V_10 -> V_23 -> V_142 ) ||
V_10 -> V_82 . V_242 != 3 )
return - V_16 ;
if ( ! F_7 ( F_85 ( V_10 ) -> V_21 ) && ! F_8 ( F_85 ( V_10 ) -> V_21 ) )
return - V_16 ;
if ( V_206 -> V_212 != 0 ) {
T_24 V_118 ;
T_25 V_270 ;
V_270 = F_101 ( V_77 , V_206 -> V_212 ) ;
if ( V_270 > V_268 )
return - V_16 ;
V_118 = V_77 -> V_142 . V_260 ;
if ( V_270 > V_77 -> V_142 . V_269 / 2 )
return - V_16 ;
if ( V_206 -> V_212 % V_118 )
return - V_16 ;
} else
V_206 -> V_208 &= ~ V_246 ;
return 0 ;
}
static int
F_104 (
struct V_9 * V_10 ,
struct V_205 * V_206 )
{
if ( V_206 -> V_214 > ( T_22 ) - 1 &&
! F_105 ( & V_10 -> V_23 -> V_142 ) )
return - V_16 ;
if ( F_106 () == & V_271 )
return 0 ;
if ( F_83 ( V_10 ) != V_206 -> V_214 )
return - V_16 ;
if ( ( V_206 -> V_208 & V_236 ) !=
( V_10 -> V_82 . V_198 & V_237 ) )
return - V_16 ;
return 0 ;
}
STATIC int
F_107 (
T_6 * V_10 ,
struct V_205 * V_206 )
{
struct V_252 * V_77 = V_10 -> V_23 ;
struct V_251 * V_78 ;
struct V_272 * V_273 = NULL ;
struct V_272 * V_274 = NULL ;
struct V_272 * V_275 = NULL ;
int V_276 ;
int V_259 = 0 ;
F_108 ( V_10 ) ;
V_276 = F_104 ( V_10 , V_206 ) ;
if ( V_276 )
return V_276 ;
if ( F_109 ( V_77 ) ) {
V_276 = F_110 ( V_10 , V_10 -> V_82 . V_277 ,
V_10 -> V_82 . V_278 , V_206 -> V_214 ,
V_279 , & V_273 , NULL , & V_274 ) ;
if ( V_276 )
return V_276 ;
}
V_276 = F_92 ( V_10 , V_206 , & V_259 ) ;
if ( V_276 )
goto V_280;
V_78 = F_96 ( V_10 , V_259 ) ;
if ( F_23 ( V_78 ) ) {
V_276 = F_24 ( V_78 ) ;
goto V_280;
}
if ( F_111 ( V_77 ) && F_112 ( V_77 ) &&
F_83 ( V_10 ) != V_206 -> V_214 ) {
V_276 = F_113 ( V_78 , V_10 , V_273 , NULL , V_274 ,
F_22 ( V_281 ) ? V_282 : 0 ) ;
if ( V_276 )
goto V_283;
}
V_276 = F_100 ( V_10 , V_206 ) ;
if ( V_276 )
goto V_283;
V_276 = F_102 ( V_10 , V_206 ) ;
if ( V_276 )
goto V_283;
V_276 = F_87 ( V_78 , V_10 , V_206 ) ;
if ( V_276 )
goto V_283;
if ( ( F_85 ( V_10 ) -> V_21 & ( V_284 | V_285 ) ) &&
! F_114 ( F_85 ( V_10 ) , V_286 ) )
F_85 ( V_10 ) -> V_21 &= ~ ( V_284 | V_285 ) ;
if ( F_83 ( V_10 ) != V_206 -> V_214 ) {
if ( F_111 ( V_77 ) && F_112 ( V_77 ) ) {
V_275 = F_115 ( V_78 , V_10 ,
& V_10 -> V_287 , V_274 ) ;
}
ASSERT ( V_10 -> V_82 . V_242 > 1 ) ;
F_116 ( V_10 , V_206 -> V_214 ) ;
}
if ( V_10 -> V_82 . V_198 & ( V_241 | V_235 ) )
V_10 -> V_82 . V_210 = V_206 -> V_209 >> V_77 -> V_142 . V_211 ;
else
V_10 -> V_82 . V_210 = 0 ;
if ( V_10 -> V_82 . V_242 == 3 &&
( V_10 -> V_82 . V_224 & V_247 ) )
V_10 -> V_82 . V_213 = V_206 -> V_212 >>
V_77 -> V_142 . V_211 ;
else
V_10 -> V_82 . V_213 = 0 ;
V_276 = F_41 ( V_78 ) ;
F_117 ( V_275 ) ;
F_117 ( V_273 ) ;
F_117 ( V_274 ) ;
return V_276 ;
V_283:
F_99 ( V_78 ) ;
V_280:
F_117 ( V_273 ) ;
F_117 ( V_274 ) ;
return V_276 ;
}
STATIC int
F_118 (
T_6 * V_10 ,
struct V_12 * V_56 ,
void V_14 * V_86 )
{
struct V_205 V_206 ;
int error ;
if ( F_17 ( & V_206 , V_86 , sizeof( V_206 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_107 ( V_10 , & V_206 ) ;
F_44 ( V_56 ) ;
return error ;
}
STATIC int
F_119 (
T_6 * V_10 ,
void V_14 * V_86 )
{
unsigned int V_104 ;
V_104 = F_80 ( V_10 -> V_82 . V_198 ) ;
if ( F_11 ( V_86 , & V_104 , sizeof( V_104 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_120 (
struct V_9 * V_10 ,
struct V_12 * V_56 ,
void V_14 * V_86 )
{
struct V_251 * V_78 ;
struct V_205 V_206 ;
unsigned int V_104 ;
int V_259 = 0 ;
int error ;
if ( F_17 ( & V_104 , V_86 , sizeof( V_104 ) ) )
return - V_35 ;
if ( V_104 & ~ ( V_188 | V_190 | \
V_194 | V_196 | \
V_192 ) )
return - V_288 ;
V_206 . V_208 = F_79 ( V_104 , F_82 ( V_10 ) ) ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_92 ( V_10 , & V_206 , & V_259 ) ;
if ( error )
goto V_289;
V_78 = F_96 ( V_10 , V_259 ) ;
if ( F_23 ( V_78 ) ) {
error = F_24 ( V_78 ) ;
goto V_289;
}
error = F_87 ( V_78 , V_10 , & V_206 ) ;
if ( error ) {
F_99 ( V_78 ) ;
goto V_289;
}
error = F_41 ( V_78 ) ;
V_289:
F_44 ( V_56 ) ;
return error ;
}
STATIC int
F_121 ( void * * V_290 , struct V_291 * V_292 , int * V_293 )
{
struct V_294 V_14 * V_295 = (struct V_294 V_14 * ) * V_290 ;
if ( F_11 ( V_295 , V_292 , sizeof( struct V_294 ) ) )
return - V_35 ;
* V_290 += sizeof( struct V_294 ) ;
return 0 ;
}
STATIC int
F_122 (
struct V_12 * V_12 ,
unsigned int V_1 ,
void V_14 * V_86 )
{
struct V_291 V_296 ;
int error ;
if ( F_17 ( & V_296 , V_86 , sizeof( struct V_291 ) ) )
return - V_35 ;
if ( V_296 . V_297 < 2 )
return - V_16 ;
V_296 . V_298 = ( V_1 == V_299 ? V_300 : 0 ) ;
if ( V_12 -> V_70 & V_71 )
V_296 . V_298 |= V_301 ;
error = F_123 ( F_6 ( F_3 ( V_12 ) ) , & V_296 , F_121 ,
( V_302 struct V_294 * ) V_86 + 1 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_296 , sizeof( struct V_294 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_124 ( void * * V_290 , struct V_291 * V_292 , int * V_293 )
{
struct V_291 V_14 * V_295 = (struct V_291 V_14 * ) * V_290 ;
if ( F_11 ( V_295 , V_292 , sizeof( struct V_291 ) ) )
return - V_35 ;
* V_290 += sizeof( struct V_291 ) ;
return 0 ;
}
STATIC int
F_125 (
struct V_9 * V_10 ,
void V_14 * V_86 )
{
struct V_291 V_296 ;
int error ;
if ( F_17 ( & V_296 , V_86 , sizeof( V_296 ) ) )
return - V_35 ;
if ( V_296 . V_297 < 2 )
return - V_16 ;
if ( V_296 . V_298 & ( ~ V_303 ) )
return - V_16 ;
error = F_123 ( V_10 , & V_296 , F_124 ,
( V_302 struct V_291 * ) V_86 + 1 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_296 , sizeof( struct V_291 ) ) )
return - V_35 ;
return 0 ;
}
int
F_126 (
T_26 * V_304 )
{
T_6 * V_10 , * V_305 ;
struct V_6 V_7 , V_306 ;
int error = 0 ;
V_7 = F_2 ( ( int ) V_304 -> V_307 ) ;
if ( ! V_7 . V_12 ) {
error = - V_16 ;
goto V_91;
}
if ( ! ( V_7 . V_12 -> V_70 & V_66 ) ||
! ( V_7 . V_12 -> V_70 & V_308 ) ||
( V_7 . V_12 -> V_68 & V_64 ) ) {
error = - V_13 ;
goto V_309;
}
V_306 = F_2 ( ( int ) V_304 -> V_310 ) ;
if ( ! V_306 . V_12 ) {
error = - V_16 ;
goto V_309;
}
if ( ! ( V_306 . V_12 -> V_70 & V_66 ) ||
! ( V_306 . V_12 -> V_70 & V_308 ) ||
( V_306 . V_12 -> V_68 & V_64 ) ) {
error = - V_13 ;
goto V_311;
}
if ( F_127 ( F_3 ( V_7 . V_12 ) ) ||
F_127 ( F_3 ( V_306 . V_12 ) ) ) {
error = - V_16 ;
goto V_311;
}
if ( V_7 . V_12 -> V_312 != & V_313 ||
V_306 . V_12 -> V_312 != & V_313 ) {
error = - V_16 ;
goto V_311;
}
V_10 = F_6 ( F_3 ( V_7 . V_12 ) ) ;
V_305 = F_6 ( F_3 ( V_306 . V_12 ) ) ;
if ( V_10 -> V_23 != V_305 -> V_23 ) {
error = - V_16 ;
goto V_311;
}
if ( V_10 -> V_34 == V_305 -> V_34 ) {
error = - V_16 ;
goto V_311;
}
if ( F_35 ( V_10 -> V_23 ) ) {
error = - V_79 ;
goto V_311;
}
error = F_128 ( V_10 , V_305 , V_304 ) ;
V_311:
F_12 ( V_306 ) ;
V_309:
F_12 ( V_7 ) ;
V_91:
return error ;
}
long
F_129 (
struct V_12 * V_56 ,
unsigned int V_1 ,
unsigned long V_98 )
{
struct V_5 * V_5 = F_3 ( V_56 ) ;
struct V_9 * V_10 = F_6 ( V_5 ) ;
struct V_252 * V_77 = V_10 -> V_23 ;
void V_14 * V_86 = ( void V_14 * ) V_98 ;
int error ;
F_130 ( V_10 ) ;
switch ( V_1 ) {
case V_314 :
return F_131 ( V_77 , V_86 ) ;
case V_163 :
case V_165 :
case V_155 :
case V_157 :
case V_164 :
case V_166 :
case V_156 :
case V_158 :
case V_154 : {
T_17 V_137 ;
if ( F_17 ( & V_137 , V_86 , sizeof( V_137 ) ) )
return - V_35 ;
return F_61 ( V_56 , V_1 , & V_137 ) ;
}
case V_315 : {
struct V_316 V_317 ;
T_27 * V_318 =
F_88 ( V_10 ) ?
V_77 -> V_319 : V_77 -> V_320 ;
V_317 . V_321 = V_317 . V_322 = V_318 -> V_323 ;
V_317 . V_324 = V_121 & ~ ( V_317 . V_322 - 1 ) ;
if ( F_11 ( V_86 , & V_317 , sizeof( V_317 ) ) )
return - V_35 ;
return 0 ;
}
case V_181 :
case V_325 :
case V_179 :
return F_72 ( V_77 , V_1 , V_86 ) ;
case V_326 :
return F_76 ( V_77 , V_86 ) ;
case V_327 :
return F_78 ( V_77 , V_86 ) ;
case V_328 :
return F_132 ( V_5 -> V_32 , ( int V_14 * ) V_86 ) ;
case V_329 :
return F_81 ( V_10 , 0 , V_86 ) ;
case V_330 :
return F_81 ( V_10 , 1 , V_86 ) ;
case V_331 :
return F_118 ( V_10 , V_56 , V_86 ) ;
case V_332 :
return F_119 ( V_10 , V_86 ) ;
case V_333 :
return F_120 ( V_10 , V_56 , V_86 ) ;
case V_334 : {
struct V_87 V_335 ;
if ( F_17 ( & V_335 , V_86 , sizeof( V_335 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_34 ( V_10 , V_335 . V_93 ,
V_335 . V_94 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_336 :
case V_299 :
return F_122 ( V_56 , V_1 , V_86 ) ;
case V_337 :
return F_125 ( V_10 , V_86 ) ;
case V_11 :
case V_338 :
case V_26 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_86 , sizeof( V_2 ) ) )
return - V_35 ;
return F_1 ( V_1 , & V_2 ) ;
}
case V_339 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_86 , sizeof( T_1 ) ) )
return - V_35 ;
return F_20 ( V_56 , & V_2 ) ;
}
case V_340 :
return F_42 ( V_56 , V_86 ) ;
case V_341 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_86 , sizeof( T_1 ) ) )
return - V_35 ;
return F_33 ( V_56 , & V_2 ) ;
}
case V_342 :
return F_45 ( V_56 , V_86 ) ;
case V_343 :
return F_58 ( V_56 , V_86 ) ;
case V_344 : {
struct V_345 V_304 ;
if ( F_17 ( & V_304 , V_86 , sizeof( T_26 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_126 ( & V_304 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_346 : {
T_28 V_91 ;
error = F_133 ( V_77 , & V_91 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_91 , sizeof( V_91 ) ) )
return - V_35 ;
return 0 ;
}
case V_347 : {
T_29 V_348 ;
T_30 V_349 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( V_77 -> V_263 & V_264 )
return - V_262 ;
if ( F_17 ( & V_348 , V_86 , sizeof( V_348 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
V_349 = V_348 . V_350 ;
error = F_134 ( V_77 , & V_349 , & V_348 ) ;
F_44 ( V_56 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_348 , sizeof( V_348 ) ) )
return - V_35 ;
return 0 ;
}
case V_351 : {
T_29 V_91 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
error = F_134 ( V_77 , NULL , & V_91 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_91 , sizeof( V_91 ) ) )
return - V_35 ;
return 0 ;
}
case V_352 : {
T_31 V_349 ;
if ( F_17 ( & V_349 , V_86 , sizeof( V_349 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_135 ( V_77 , & V_349 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_353 : {
T_32 V_349 ;
if ( F_17 ( & V_349 , V_86 , sizeof( V_349 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_136 ( V_77 , & V_349 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_354 : {
T_33 V_349 ;
if ( F_17 ( & V_349 , V_86 , sizeof( V_349 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_137 ( V_77 , & V_349 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_355 : {
T_14 V_349 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_138 ( V_349 , ( T_14 V_14 * ) V_86 ) )
return - V_35 ;
return F_139 ( V_77 , V_349 ) ;
}
case V_356 : {
T_34 V_349 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_17 ( & V_349 , V_86 , sizeof( V_349 ) ) )
return - V_35 ;
return F_140 ( V_349 . V_357 , V_77 ) ;
}
case V_358 :
if ( ! F_22 ( V_58 ) )
return - V_59 ;
return F_141 ( V_77 , 1 ) ;
case V_359 : {
struct V_360 V_361 ;
struct V_362 V_363 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( V_77 -> V_263 & V_264 )
return - V_262 ;
if ( F_17 ( & V_361 , V_86 , sizeof( V_361 ) ) )
return - V_35 ;
error = F_142 ( & V_361 , & V_363 ) ;
if ( error )
return error ;
return F_143 ( V_77 , & V_363 ) ;
}
default:
return - V_364 ;
}
}
