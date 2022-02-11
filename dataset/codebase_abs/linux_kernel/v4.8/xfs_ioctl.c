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
error = F_68 ( V_10 , & V_138 ) ;
break;
default:
ASSERT ( 0 ) ;
error = - V_16 ;
}
if ( error )
goto V_149;
error = F_69 ( V_10 , V_104 ) ;
V_149:
F_70 ( V_10 , V_140 ) ;
F_44 ( V_56 ) ;
return error ;
}
STATIC int
F_71 (
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
error = F_72 ( V_77 , & V_173 , & V_172 ,
V_171 . V_178 , V_180 ) ;
else if ( V_1 == V_181 )
error = F_73 ( V_77 , V_173 , V_171 . V_178 ,
sizeof( V_182 ) , NULL , & V_174 ) ;
else
error = F_74 ( V_77 , & V_173 , & V_172 , F_73 ,
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
F_75 (
T_9 * V_77 ,
void V_14 * V_86 )
{
T_21 V_184 ;
int error ;
error = F_76 ( V_77 , & V_184 , 3 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_184 , sizeof( V_185 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_77 (
T_9 * V_77 ,
void V_14 * V_86 )
{
T_21 V_184 ;
int error ;
error = F_76 ( V_77 , & V_184 , 4 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_184 , sizeof( V_184 ) ) )
return - V_35 ;
return 0 ;
}
STATIC unsigned int
F_78 (
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
F_79 (
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
F_80 (
T_6 * V_10 ,
int V_204 ,
void V_14 * V_86 )
{
struct V_205 V_206 ;
memset ( & V_206 , 0 , sizeof( struct V_205 ) ) ;
F_38 ( V_10 , V_207 ) ;
V_206 . V_208 = F_81 ( V_10 ) ;
V_206 . V_209 = V_10 -> V_82 . V_210 << V_10 -> V_23 -> V_142 . V_211 ;
V_206 . V_212 = F_82 ( V_10 ) ;
if ( V_204 ) {
if ( V_10 -> V_213 ) {
if ( V_10 -> V_213 -> V_214 & V_215 )
V_206 . V_216 = V_10 -> V_213 -> V_217 /
sizeof( V_218 ) ;
else
V_206 . V_216 = V_10 -> V_82 . V_219 ;
} else
V_206 . V_216 = 0 ;
} else {
if ( V_10 -> V_220 . V_214 & V_215 )
V_206 . V_216 = V_10 -> V_220 . V_217 /
sizeof( V_218 ) ;
else
V_206 . V_216 = V_10 -> V_82 . V_221 ;
}
F_70 ( V_10 , V_207 ) ;
if ( F_11 ( V_86 , & V_206 , sizeof( V_206 ) ) )
return - V_35 ;
return 0 ;
}
STATIC void
F_83 (
struct V_9 * V_10 ,
unsigned int V_187 )
{
unsigned int V_198 ;
T_23 V_222 ;
V_198 = ( V_10 -> V_82 . V_198 & V_223 ) ;
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
if ( V_187 & V_224 )
V_198 |= V_225 ;
if ( V_187 & V_226 )
V_198 |= V_227 ;
if ( F_8 ( F_84 ( V_10 ) -> V_21 ) ) {
if ( V_187 & V_228 )
V_198 |= V_229 ;
if ( V_187 & V_230 )
V_198 |= V_231 ;
if ( V_187 & V_232 )
V_198 |= V_233 ;
if ( V_187 & V_234 )
V_198 |= V_235 ;
} else if ( F_7 ( F_84 ( V_10 ) -> V_21 ) ) {
if ( V_187 & V_236 )
V_198 |= V_237 ;
if ( V_187 & V_238 )
V_198 |= V_239 ;
}
V_10 -> V_82 . V_198 = V_198 ;
if ( V_10 -> V_82 . V_240 < 3 )
return;
V_222 = 0 ;
if ( V_187 & V_241 )
V_222 |= V_242 ;
V_10 -> V_82 . V_222 = V_222 ;
}
STATIC void
F_85 (
struct V_9 * V_10 )
{
struct V_5 * V_5 = F_84 ( V_10 ) ;
unsigned int V_187 = F_81 ( V_10 ) ;
if ( V_187 & V_189 )
V_5 -> V_143 |= V_144 ;
else
V_5 -> V_143 &= ~ V_144 ;
if ( V_187 & V_191 )
V_5 -> V_143 |= V_145 ;
else
V_5 -> V_143 &= ~ V_145 ;
if ( V_187 & V_193 )
V_5 -> V_143 |= V_243 ;
else
V_5 -> V_143 &= ~ V_243 ;
if ( V_187 & V_195 )
V_5 -> V_143 |= V_244 ;
else
V_5 -> V_143 &= ~ V_244 ;
if ( V_187 & V_241 )
V_5 -> V_143 |= V_245 ;
else
V_5 -> V_143 &= ~ V_245 ;
}
static int
F_86 (
struct V_246 * V_78 ,
struct V_9 * V_10 ,
struct V_205 * V_206 )
{
struct V_247 * V_77 = V_10 -> V_23 ;
if ( ( V_10 -> V_82 . V_221 || V_10 -> V_248 ) &&
F_87 ( V_10 ) != ( V_206 -> V_208 & V_236 ) )
return - V_16 ;
if ( V_206 -> V_208 & V_236 ) {
if ( V_77 -> V_142 . V_249 == 0 || V_77 -> V_142 . V_250 == 0 ||
( V_10 -> V_82 . V_210 % V_77 -> V_142 . V_250 ) )
return - V_16 ;
}
if ( ( ( V_10 -> V_82 . V_198 & ( V_199 | V_200 ) ) ||
( V_206 -> V_208 & ( V_189 | V_191 ) ) ) &&
! F_22 ( V_251 ) )
return - V_59 ;
F_83 ( V_10 , V_206 -> V_208 ) ;
F_85 ( V_10 ) ;
F_88 ( V_78 , V_10 , V_252 ) ;
F_40 ( V_78 , V_10 , V_85 ) ;
F_89 ( V_77 , V_253 ) ;
return 0 ;
}
static int
F_90 (
struct V_9 * V_10 ,
struct V_205 * V_206 ,
int * V_254 )
{
struct V_5 * V_5 = F_84 ( V_10 ) ;
int error ;
* V_254 = 0 ;
if ( V_206 -> V_208 & V_241 ) {
if ( ! ( F_7 ( V_5 -> V_21 ) || F_8 ( V_5 -> V_21 ) ) )
return - V_16 ;
if ( V_10 -> V_23 -> V_142 . V_255 != V_123 )
return - V_16 ;
}
if ( ( V_206 -> V_208 & V_241 ) && F_91 ( V_5 ) )
return 0 ;
if ( ! ( V_206 -> V_208 & V_241 ) && ! F_91 ( V_5 ) )
return 0 ;
F_38 ( V_10 , V_150 | V_141 ) ;
error = F_92 ( V_5 -> V_256 ) ;
if ( error )
goto V_149;
error = F_93 ( V_5 -> V_256 ) ;
if ( error )
goto V_149;
* V_254 = V_150 | V_141 ;
return 0 ;
V_149:
F_70 ( V_10 , V_150 | V_141 ) ;
return error ;
}
static struct V_246 *
F_94 (
struct V_9 * V_10 ,
int V_254 )
{
struct V_247 * V_77 = V_10 -> V_23 ;
struct V_246 * V_78 ;
int error = - V_257 ;
if ( V_77 -> V_258 & V_259 )
goto V_149;
error = - V_79 ;
if ( F_35 ( V_77 ) )
goto V_149;
error = F_36 ( V_77 , & F_37 ( V_77 ) -> V_80 , 0 , 0 , 0 , & V_78 ) ;
if ( error )
return F_16 ( error ) ;
F_38 ( V_10 , V_81 ) ;
F_39 ( V_78 , V_10 , V_81 | V_254 ) ;
V_254 = 0 ;
if ( ! F_95 ( F_84 ( V_10 ) ) ) {
error = - V_59 ;
goto V_260;
}
if ( V_77 -> V_258 & V_261 )
F_96 ( V_78 ) ;
return V_78 ;
V_260:
F_97 ( V_78 ) ;
V_149:
if ( V_254 )
F_70 ( V_10 , V_254 ) ;
return F_16 ( error ) ;
}
static int
F_98 (
struct V_9 * V_10 ,
struct V_205 * V_206 )
{
struct V_247 * V_77 = V_10 -> V_23 ;
if ( ( V_206 -> V_208 & V_238 ) && ! F_7 ( F_84 ( V_10 ) -> V_21 ) )
return - V_16 ;
if ( ( V_206 -> V_208 & V_232 ) &&
! F_8 ( F_84 ( V_10 ) -> V_21 ) )
return - V_16 ;
if ( F_7 ( F_84 ( V_10 ) -> V_21 ) && V_10 -> V_82 . V_221 &&
( ( V_10 -> V_82 . V_210 << V_77 -> V_142 . V_211 ) != V_206 -> V_209 ) )
return - V_16 ;
if ( V_206 -> V_209 != 0 ) {
T_24 V_118 ;
T_25 V_262 ;
V_262 = F_99 ( V_77 , V_206 -> V_209 ) ;
if ( V_262 > V_263 )
return - V_16 ;
if ( F_87 ( V_10 ) ||
( V_206 -> V_208 & V_236 ) ) {
V_118 = V_77 -> V_142 . V_250 << V_77 -> V_142 . V_211 ;
} else {
V_118 = V_77 -> V_142 . V_255 ;
if ( V_262 > V_77 -> V_142 . V_264 / 2 )
return - V_16 ;
}
if ( V_206 -> V_209 % V_118 )
return - V_16 ;
} else
V_206 -> V_208 &= ~ ( V_238 | V_232 ) ;
return 0 ;
}
static int
F_100 (
struct V_9 * V_10 ,
struct V_205 * V_206 )
{
if ( V_206 -> V_212 > ( T_22 ) - 1 &&
! F_101 ( & V_10 -> V_23 -> V_142 ) )
return - V_16 ;
if ( F_102 () == & V_265 )
return 0 ;
if ( F_82 ( V_10 ) != V_206 -> V_212 )
return - V_16 ;
if ( ( V_206 -> V_208 & V_234 ) !=
( V_10 -> V_82 . V_198 & V_235 ) )
return - V_16 ;
return 0 ;
}
STATIC int
F_103 (
T_6 * V_10 ,
struct V_205 * V_206 )
{
struct V_247 * V_77 = V_10 -> V_23 ;
struct V_246 * V_78 ;
struct V_266 * V_267 = NULL ;
struct V_266 * V_268 = NULL ;
struct V_266 * V_269 = NULL ;
int V_270 ;
int V_254 = 0 ;
F_104 ( V_10 ) ;
V_270 = F_100 ( V_10 , V_206 ) ;
if ( V_270 )
return V_270 ;
if ( F_105 ( V_77 ) ) {
V_270 = F_106 ( V_10 , V_10 -> V_82 . V_271 ,
V_10 -> V_82 . V_272 , V_206 -> V_212 ,
V_273 , & V_267 , NULL , & V_268 ) ;
if ( V_270 )
return V_270 ;
}
V_270 = F_90 ( V_10 , V_206 , & V_254 ) ;
if ( V_270 )
goto V_274;
V_78 = F_94 ( V_10 , V_254 ) ;
if ( F_23 ( V_78 ) ) {
V_270 = F_24 ( V_78 ) ;
goto V_274;
}
if ( F_107 ( V_77 ) && F_108 ( V_77 ) &&
F_82 ( V_10 ) != V_206 -> V_212 ) {
V_270 = F_109 ( V_78 , V_10 , V_267 , NULL , V_268 ,
F_22 ( V_275 ) ? V_276 : 0 ) ;
if ( V_270 )
goto V_277;
}
V_270 = F_98 ( V_10 , V_206 ) ;
if ( V_270 )
goto V_277;
V_270 = F_86 ( V_78 , V_10 , V_206 ) ;
if ( V_270 )
goto V_277;
if ( ( F_84 ( V_10 ) -> V_21 & ( V_278 | V_279 ) ) &&
! F_110 ( F_84 ( V_10 ) , V_280 ) )
F_84 ( V_10 ) -> V_21 &= ~ ( V_278 | V_279 ) ;
if ( F_82 ( V_10 ) != V_206 -> V_212 ) {
if ( F_107 ( V_77 ) && F_108 ( V_77 ) ) {
V_269 = F_111 ( V_78 , V_10 ,
& V_10 -> V_281 , V_268 ) ;
}
ASSERT ( V_10 -> V_82 . V_240 > 1 ) ;
F_112 ( V_10 , V_206 -> V_212 ) ;
}
if ( V_10 -> V_82 . V_198 & ( V_239 | V_233 ) )
V_10 -> V_82 . V_210 = V_206 -> V_209 >> V_77 -> V_142 . V_211 ;
else
V_10 -> V_82 . V_210 = 0 ;
V_270 = F_41 ( V_78 ) ;
F_113 ( V_269 ) ;
F_113 ( V_267 ) ;
F_113 ( V_268 ) ;
return V_270 ;
V_277:
F_97 ( V_78 ) ;
V_274:
F_113 ( V_267 ) ;
F_113 ( V_268 ) ;
return V_270 ;
}
STATIC int
F_114 (
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
error = F_103 ( V_10 , & V_206 ) ;
F_44 ( V_56 ) ;
return error ;
}
STATIC int
F_115 (
T_6 * V_10 ,
void V_14 * V_86 )
{
unsigned int V_104 ;
V_104 = F_79 ( V_10 -> V_82 . V_198 ) ;
if ( F_11 ( V_86 , & V_104 , sizeof( V_104 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_116 (
struct V_9 * V_10 ,
struct V_12 * V_56 ,
void V_14 * V_86 )
{
struct V_246 * V_78 ;
struct V_205 V_206 ;
unsigned int V_104 ;
int V_254 = 0 ;
int error ;
if ( F_17 ( & V_104 , V_86 , sizeof( V_104 ) ) )
return - V_35 ;
if ( V_104 & ~ ( V_188 | V_190 | \
V_194 | V_196 | \
V_192 ) )
return - V_282 ;
V_206 . V_208 = F_78 ( V_104 , F_81 ( V_10 ) ) ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_90 ( V_10 , & V_206 , & V_254 ) ;
if ( error )
goto V_283;
V_78 = F_94 ( V_10 , V_254 ) ;
if ( F_23 ( V_78 ) ) {
error = F_24 ( V_78 ) ;
goto V_283;
}
error = F_86 ( V_78 , V_10 , & V_206 ) ;
if ( error ) {
F_97 ( V_78 ) ;
goto V_283;
}
error = F_41 ( V_78 ) ;
V_283:
F_44 ( V_56 ) ;
return error ;
}
STATIC int
F_117 ( void * * V_284 , struct V_285 * V_286 , int * V_287 )
{
struct V_288 V_14 * V_289 = (struct V_288 V_14 * ) * V_284 ;
if ( F_11 ( V_289 , V_286 , sizeof( struct V_288 ) ) )
return - V_35 ;
* V_284 += sizeof( struct V_288 ) ;
return 0 ;
}
STATIC int
F_118 (
struct V_12 * V_12 ,
unsigned int V_1 ,
void V_14 * V_86 )
{
struct V_285 V_290 ;
int error ;
if ( F_17 ( & V_290 , V_86 , sizeof( struct V_285 ) ) )
return - V_35 ;
if ( V_290 . V_291 < 2 )
return - V_16 ;
V_290 . V_292 = ( V_1 == V_293 ? V_294 : 0 ) ;
if ( V_12 -> V_70 & V_71 )
V_290 . V_292 |= V_295 ;
error = F_119 ( F_6 ( F_3 ( V_12 ) ) , & V_290 , F_117 ,
( V_296 struct V_288 * ) V_86 + 1 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_290 , sizeof( struct V_288 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_120 ( void * * V_284 , struct V_285 * V_286 , int * V_287 )
{
struct V_285 V_14 * V_289 = (struct V_285 V_14 * ) * V_284 ;
if ( F_11 ( V_289 , V_286 , sizeof( struct V_285 ) ) )
return - V_35 ;
* V_284 += sizeof( struct V_285 ) ;
return 0 ;
}
STATIC int
F_121 (
struct V_9 * V_10 ,
void V_14 * V_86 )
{
struct V_285 V_290 ;
int error ;
if ( F_17 ( & V_290 , V_86 , sizeof( V_290 ) ) )
return - V_35 ;
if ( V_290 . V_291 < 2 )
return - V_16 ;
if ( V_290 . V_292 & ( ~ V_297 ) )
return - V_16 ;
error = F_119 ( V_10 , & V_290 , F_120 ,
( V_296 struct V_285 * ) V_86 + 1 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_290 , sizeof( struct V_285 ) ) )
return - V_35 ;
return 0 ;
}
int
F_122 (
T_26 * V_298 )
{
T_6 * V_10 , * V_299 ;
struct V_6 V_7 , V_300 ;
int error = 0 ;
V_7 = F_2 ( ( int ) V_298 -> V_301 ) ;
if ( ! V_7 . V_12 ) {
error = - V_16 ;
goto V_91;
}
if ( ! ( V_7 . V_12 -> V_70 & V_66 ) ||
! ( V_7 . V_12 -> V_70 & V_302 ) ||
( V_7 . V_12 -> V_68 & V_64 ) ) {
error = - V_13 ;
goto V_303;
}
V_300 = F_2 ( ( int ) V_298 -> V_304 ) ;
if ( ! V_300 . V_12 ) {
error = - V_16 ;
goto V_303;
}
if ( ! ( V_300 . V_12 -> V_70 & V_66 ) ||
! ( V_300 . V_12 -> V_70 & V_302 ) ||
( V_300 . V_12 -> V_68 & V_64 ) ) {
error = - V_13 ;
goto V_305;
}
if ( F_123 ( F_3 ( V_7 . V_12 ) ) ||
F_123 ( F_3 ( V_300 . V_12 ) ) ) {
error = - V_16 ;
goto V_305;
}
if ( V_7 . V_12 -> V_306 != & V_307 ||
V_300 . V_12 -> V_306 != & V_307 ) {
error = - V_16 ;
goto V_305;
}
V_10 = F_6 ( F_3 ( V_7 . V_12 ) ) ;
V_299 = F_6 ( F_3 ( V_300 . V_12 ) ) ;
if ( V_10 -> V_23 != V_299 -> V_23 ) {
error = - V_16 ;
goto V_305;
}
if ( V_10 -> V_34 == V_299 -> V_34 ) {
error = - V_16 ;
goto V_305;
}
if ( F_35 ( V_10 -> V_23 ) ) {
error = - V_79 ;
goto V_305;
}
error = F_124 ( V_10 , V_299 , V_298 ) ;
V_305:
F_12 ( V_300 ) ;
V_303:
F_12 ( V_7 ) ;
V_91:
return error ;
}
long
F_125 (
struct V_12 * V_56 ,
unsigned int V_1 ,
unsigned long V_98 )
{
struct V_5 * V_5 = F_3 ( V_56 ) ;
struct V_9 * V_10 = F_6 ( V_5 ) ;
struct V_247 * V_77 = V_10 -> V_23 ;
void V_14 * V_86 = ( void V_14 * ) V_98 ;
int error ;
F_126 ( V_10 ) ;
switch ( V_1 ) {
case V_308 :
return F_127 ( V_77 , V_86 ) ;
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
case V_309 : {
struct V_310 V_311 ;
T_27 * V_312 =
F_87 ( V_10 ) ?
V_77 -> V_313 : V_77 -> V_314 ;
V_311 . V_315 = V_311 . V_316 = V_312 -> V_317 ;
V_311 . V_318 = V_121 & ~ ( V_311 . V_316 - 1 ) ;
if ( F_11 ( V_86 , & V_311 , sizeof( V_311 ) ) )
return - V_35 ;
return 0 ;
}
case V_181 :
case V_319 :
case V_179 :
return F_71 ( V_77 , V_1 , V_86 ) ;
case V_320 :
return F_75 ( V_77 , V_86 ) ;
case V_321 :
return F_77 ( V_77 , V_86 ) ;
case V_322 :
return F_128 ( V_5 -> V_32 , ( int V_14 * ) V_86 ) ;
case V_323 :
return F_80 ( V_10 , 0 , V_86 ) ;
case V_324 :
return F_80 ( V_10 , 1 , V_86 ) ;
case V_325 :
return F_114 ( V_10 , V_56 , V_86 ) ;
case V_326 :
return F_115 ( V_10 , V_86 ) ;
case V_327 :
return F_116 ( V_10 , V_56 , V_86 ) ;
case V_328 : {
struct V_87 V_329 ;
if ( F_17 ( & V_329 , V_86 , sizeof( V_329 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_34 ( V_10 , V_329 . V_93 ,
V_329 . V_94 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_330 :
case V_293 :
return F_118 ( V_56 , V_1 , V_86 ) ;
case V_331 :
return F_121 ( V_10 , V_86 ) ;
case V_11 :
case V_332 :
case V_26 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_86 , sizeof( V_2 ) ) )
return - V_35 ;
return F_1 ( V_1 , & V_2 ) ;
}
case V_333 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_86 , sizeof( T_1 ) ) )
return - V_35 ;
return F_20 ( V_56 , & V_2 ) ;
}
case V_334 :
return F_42 ( V_56 , V_86 ) ;
case V_335 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_86 , sizeof( T_1 ) ) )
return - V_35 ;
return F_33 ( V_56 , & V_2 ) ;
}
case V_336 :
return F_45 ( V_56 , V_86 ) ;
case V_337 :
return F_58 ( V_56 , V_86 ) ;
case V_338 : {
struct V_339 V_298 ;
if ( F_17 ( & V_298 , V_86 , sizeof( T_26 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_122 ( & V_298 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_340 : {
T_28 V_91 ;
error = F_129 ( V_77 , & V_91 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_91 , sizeof( V_91 ) ) )
return - V_35 ;
return 0 ;
}
case V_341 : {
T_29 V_342 ;
T_30 V_343 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( V_77 -> V_258 & V_259 )
return - V_257 ;
if ( F_17 ( & V_342 , V_86 , sizeof( V_342 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
V_343 = V_342 . V_344 ;
error = F_130 ( V_77 , & V_343 , & V_342 ) ;
F_44 ( V_56 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_342 , sizeof( V_342 ) ) )
return - V_35 ;
return 0 ;
}
case V_345 : {
T_29 V_91 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
error = F_130 ( V_77 , NULL , & V_91 ) ;
if ( error )
return error ;
if ( F_11 ( V_86 , & V_91 , sizeof( V_91 ) ) )
return - V_35 ;
return 0 ;
}
case V_346 : {
T_31 V_343 ;
if ( F_17 ( & V_343 , V_86 , sizeof( V_343 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_131 ( V_77 , & V_343 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_347 : {
T_32 V_343 ;
if ( F_17 ( & V_343 , V_86 , sizeof( V_343 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_132 ( V_77 , & V_343 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_348 : {
T_33 V_343 ;
if ( F_17 ( & V_343 , V_86 , sizeof( V_343 ) ) )
return - V_35 ;
error = F_43 ( V_56 ) ;
if ( error )
return error ;
error = F_133 ( V_77 , & V_343 ) ;
F_44 ( V_56 ) ;
return error ;
}
case V_349 : {
T_14 V_343 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_134 ( V_343 , ( T_14 V_14 * ) V_86 ) )
return - V_35 ;
return F_135 ( V_77 , V_343 ) ;
}
case V_350 : {
T_34 V_343 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( F_17 ( & V_343 , V_86 , sizeof( V_343 ) ) )
return - V_35 ;
return F_136 ( V_343 . V_351 , V_77 ) ;
}
case V_352 :
if ( ! F_22 ( V_58 ) )
return - V_59 ;
return F_137 ( V_77 , 1 ) ;
case V_353 : {
struct V_354 V_355 ;
struct V_356 V_357 ;
if ( ! F_22 ( V_58 ) )
return - V_59 ;
if ( V_77 -> V_258 & V_259 )
return - V_257 ;
if ( F_17 ( & V_355 , V_86 , sizeof( V_355 ) ) )
return - V_35 ;
error = F_138 ( & V_355 , & V_357 ) ;
if ( error )
return error ;
return F_139 ( V_77 , & V_357 ) ;
}
default:
return - V_358 ;
}
}
