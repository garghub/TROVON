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
V_5 = V_8 . V_15 -> V_16 ;
}
V_10 = F_5 ( V_5 ) ;
error = - V_17 ;
if ( V_5 -> V_18 -> V_19 != V_20 )
goto V_21;
error = - V_13 ;
if ( ! F_6 ( V_5 -> V_22 ) &&
! F_7 ( V_5 -> V_22 ) &&
! F_8 ( V_5 -> V_22 ) )
goto V_21;
memcpy ( & V_4 . V_23 , V_10 -> V_24 -> V_25 , sizeof( V_26 ) ) ;
if ( V_1 == V_27 ) {
memset ( & V_4 . V_28 , 0 , sizeof( V_4 . V_28 ) ) ;
V_3 = sizeof( V_26 ) ;
} else {
V_4 . V_28 . V_29 = sizeof( V_30 ) -
sizeof( V_4 . V_28 . V_29 ) ;
V_4 . V_28 . V_31 = 0 ;
V_4 . V_28 . V_32 = V_10 -> V_33 . V_34 ;
V_4 . V_28 . V_35 = V_10 -> V_36 ;
V_3 = F_9 ( V_4 ) ;
}
error = - V_37 ;
if ( F_10 ( V_2 -> V_38 , & V_4 , V_3 ) ||
F_10 ( V_2 -> V_39 , & V_3 , sizeof( V_40 ) ) )
goto V_21;
error = 0 ;
V_21:
if ( V_1 == V_11 )
F_11 ( V_7 ) ;
else
F_12 ( & V_8 ) ;
return error ;
}
STATIC int
F_13 (
void * V_41 ,
struct V_15 * V_15 )
{
return 1 ;
}
struct V_15 *
F_14 (
struct V_12 * V_42 ,
void V_14 * V_43 ,
T_3 V_44 )
{
T_2 V_4 ;
struct V_45 V_46 ;
if ( ! F_7 ( F_3 ( V_42 ) -> V_22 ) )
return F_15 ( - V_47 ) ;
if ( V_44 != sizeof( T_2 ) )
return F_15 ( - V_17 ) ;
if ( F_16 ( & V_4 , V_43 , V_44 ) )
return F_15 ( - V_37 ) ;
if ( V_4 . V_28 . V_29 !=
sizeof( V_4 . V_28 ) - sizeof( V_4 . V_28 . V_29 ) )
return F_15 ( - V_17 ) ;
memset ( & V_46 , 0 , sizeof( struct V_46 ) ) ;
V_46 . V_48 = V_4 . V_28 . V_35 ;
V_46 . V_49 = V_4 . V_28 . V_32 ;
return F_17 ( V_42 -> V_50 . V_51 , (struct V_46 * ) & V_46 , 3 ,
V_52 | V_53 ,
F_13 , NULL ) ;
}
STATIC struct V_15 *
F_18 (
struct V_12 * V_42 ,
T_1 * V_2 )
{
return F_14 ( V_42 , V_2 -> V_54 , V_2 -> V_55 ) ;
}
int
F_19 (
struct V_12 * V_42 ,
T_1 * V_2 )
{
const struct V_56 * V_56 = F_20 () ;
int error ;
int V_6 ;
int V_57 ;
struct V_12 * V_58 ;
struct V_5 * V_5 ;
struct V_15 * V_15 ;
T_4 V_59 ;
struct V_8 V_8 ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
V_15 = F_18 ( V_42 , V_2 ) ;
if ( F_22 ( V_15 ) )
return F_23 ( V_15 ) ;
V_5 = V_15 -> V_16 ;
if ( ! ( F_6 ( V_5 -> V_22 ) || F_7 ( V_5 -> V_22 ) ) ) {
error = - V_61 ;
goto V_62;
}
#if V_63 != 32
V_2 -> V_64 |= V_65 ;
#endif
V_57 = V_2 -> V_64 ;
V_59 = F_24 ( V_57 ) ;
if ( ( ! ( V_57 & V_66 ) || ( V_57 & V_67 ) ) &&
( V_59 & V_68 ) && F_25 ( V_5 ) ) {
error = - V_61 ;
goto V_62;
}
if ( ( V_59 & V_68 ) && F_26 ( V_5 ) ) {
error = - V_69 ;
goto V_62;
}
if ( F_7 ( V_5 -> V_22 ) && ( V_59 & V_68 ) ) {
error = - V_70 ;
goto V_62;
}
V_6 = F_27 ( 0 ) ;
if ( V_6 < 0 ) {
error = V_6 ;
goto V_62;
}
V_8 . V_51 = V_42 -> V_50 . V_51 ;
V_8 . V_15 = V_15 ;
V_58 = F_28 ( & V_8 , V_2 -> V_64 , V_56 ) ;
F_29 ( V_15 ) ;
if ( F_22 ( V_58 ) ) {
F_30 ( V_6 ) ;
return F_23 ( V_58 ) ;
}
if ( F_6 ( V_5 -> V_22 ) ) {
V_58 -> V_71 |= V_72 ;
V_58 -> V_73 |= V_74 ;
}
F_31 ( V_6 , V_58 ) ;
return V_6 ;
V_62:
F_29 ( V_15 ) ;
return error ;
}
int
F_32 (
struct V_12 * V_42 ,
T_1 * V_2 )
{
struct V_15 * V_15 ;
T_5 V_75 ;
void * V_76 ;
int error ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
V_15 = F_18 ( V_42 , V_2 ) ;
if ( F_22 ( V_15 ) )
return F_23 ( V_15 ) ;
if ( ! F_8 ( V_15 -> V_16 -> V_22 ) ) {
error = - V_17 ;
goto V_62;
}
if ( F_16 ( & V_75 , V_2 -> V_39 , sizeof( T_5 ) ) ) {
error = - V_37 ;
goto V_62;
}
V_76 = F_33 ( V_77 + 1 , V_78 ) ;
if ( ! V_76 ) {
error = - V_79 ;
goto V_62;
}
error = F_34 ( F_5 ( V_15 -> V_16 ) , V_76 ) ;
if ( error )
goto V_80;
error = F_35 ( V_2 -> V_38 , V_75 , V_76 ) ;
if ( error )
goto V_80;
V_80:
F_36 ( V_76 ) ;
V_62:
F_29 ( V_15 ) ;
return error ;
}
int
F_37 (
T_6 * V_10 ,
T_7 V_81 ,
T_8 V_82 )
{
T_9 * V_83 = V_10 -> V_24 ;
T_10 * V_84 ;
int error ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( F_38 ( V_83 ) )
return - V_85 ;
V_84 = F_39 ( V_83 , V_86 ) ;
error = F_40 ( V_84 , & F_41 ( V_83 ) -> V_87 , 0 , 0 ) ;
if ( error ) {
F_42 ( V_84 , 0 ) ;
return error ;
}
F_43 ( V_10 , V_88 ) ;
F_44 ( V_84 , V_10 , V_88 ) ;
V_10 -> V_33 . V_89 = V_81 ;
V_10 -> V_33 . V_90 = V_82 ;
F_45 ( V_84 , V_10 , V_91 ) ;
error = F_46 ( V_84 , 0 ) ;
return error ;
}
STATIC int
F_47 (
struct V_12 * V_42 ,
void V_14 * V_92 )
{
int error ;
struct V_93 V_94 ;
T_11 V_95 ;
struct V_15 * V_15 ;
if ( ! F_21 ( V_96 ) )
return - V_61 ;
if ( F_16 ( & V_95 , V_92 , sizeof( T_11 ) ) )
return - V_37 ;
error = F_48 ( V_42 ) ;
if ( error )
return error ;
V_15 = F_18 ( V_42 , & V_95 . V_2 ) ;
if ( F_22 ( V_15 ) ) {
F_49 ( V_42 ) ;
return F_23 ( V_15 ) ;
}
if ( F_26 ( V_15 -> V_16 ) || F_25 ( V_15 -> V_16 ) ) {
error = - V_61 ;
goto V_97;
}
if ( F_16 ( & V_94 , V_95 . V_98 , sizeof( V_94 ) ) ) {
error = - V_37 ;
goto V_97;
}
error = F_37 ( F_5 ( V_15 -> V_16 ) , V_94 . V_99 ,
V_94 . V_100 ) ;
V_97:
F_49 ( V_42 ) ;
F_29 ( V_15 ) ;
return error ;
}
STATIC int
F_50 (
struct V_12 * V_42 ,
void V_14 * V_92 )
{
int error = - V_79 ;
T_12 * V_101 ;
T_13 V_102 ;
struct V_15 * V_15 ;
char * V_103 ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( F_16 ( & V_102 , V_92 , sizeof( T_13 ) ) )
return - V_37 ;
if ( V_102 . V_104 < sizeof( struct V_105 ) ||
V_102 . V_104 > V_106 )
return - V_17 ;
if ( V_102 . V_107 & ~ ( V_108 | V_109 ) )
return - V_17 ;
V_15 = F_18 ( V_42 , & V_102 . V_2 ) ;
if ( F_22 ( V_15 ) )
return F_23 ( V_15 ) ;
V_103 = F_51 ( V_102 . V_104 , V_110 ) ;
if ( ! V_103 )
goto V_62;
V_101 = ( T_12 * ) & V_102 . V_111 ;
error = F_52 ( F_5 ( V_15 -> V_16 ) , V_103 , V_102 . V_104 ,
V_102 . V_107 , V_101 ) ;
if ( error )
goto V_80;
if ( F_10 ( V_102 . V_112 , V_103 , V_102 . V_104 ) )
error = - V_37 ;
V_80:
F_53 ( V_103 ) ;
V_62:
F_29 ( V_15 ) ;
return error ;
}
int
F_54 (
struct V_5 * V_5 ,
unsigned char * V_113 ,
unsigned char V_14 * V_114 ,
T_14 * V_115 ,
T_14 V_107 )
{
unsigned char * V_103 ;
int error = - V_37 ;
if ( * V_115 > V_116 )
return - V_17 ;
V_103 = F_51 ( * V_115 , V_110 ) ;
if ( ! V_103 )
return - V_79 ;
error = F_55 ( F_5 ( V_5 ) , V_113 , V_103 , ( int * ) V_115 , V_107 ) ;
if ( error )
goto V_80;
if ( F_10 ( V_114 , V_103 , * V_115 ) )
error = - V_37 ;
V_80:
F_53 ( V_103 ) ;
return error ;
}
int
F_56 (
struct V_5 * V_5 ,
unsigned char * V_113 ,
const unsigned char V_14 * V_114 ,
T_14 V_115 ,
T_14 V_107 )
{
unsigned char * V_103 ;
if ( F_26 ( V_5 ) || F_25 ( V_5 ) )
return - V_61 ;
if ( V_115 > V_116 )
return - V_17 ;
V_103 = F_57 ( V_114 , V_115 ) ;
if ( F_22 ( V_103 ) )
return F_23 ( V_103 ) ;
return F_58 ( F_5 ( V_5 ) , V_113 , V_103 , V_115 , V_107 ) ;
}
int
F_59 (
struct V_5 * V_5 ,
unsigned char * V_113 ,
T_14 V_107 )
{
if ( F_26 ( V_5 ) || F_25 ( V_5 ) )
return - V_61 ;
return F_60 ( F_5 ( V_5 ) , V_113 , V_107 ) ;
}
STATIC int
F_61 (
struct V_12 * V_42 ,
void V_14 * V_92 )
{
int error ;
T_15 * V_117 ;
T_16 V_118 ;
struct V_15 * V_15 ;
unsigned int V_119 , V_120 ;
unsigned char * V_121 ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( F_16 ( & V_118 , V_92 , sizeof( T_16 ) ) )
return - V_37 ;
if ( V_118 . V_122 >= V_123 / sizeof( T_15 ) )
return - V_124 ;
V_15 = F_18 ( V_42 , & V_118 . V_2 ) ;
if ( F_22 ( V_15 ) )
return F_23 ( V_15 ) ;
error = - V_124 ;
V_120 = V_118 . V_122 * sizeof( T_15 ) ;
if ( ! V_120 || V_120 > 16 * V_125 )
goto V_62;
V_117 = F_57 ( V_118 . V_117 , V_120 ) ;
if ( F_22 ( V_117 ) ) {
error = F_23 ( V_117 ) ;
goto V_62;
}
error = - V_79 ;
V_121 = F_33 ( V_126 , V_78 ) ;
if ( ! V_121 )
goto V_127;
error = 0 ;
for ( V_119 = 0 ; V_119 < V_118 . V_122 ; V_119 ++ ) {
V_117 [ V_119 ] . V_128 = F_62 ( ( char * ) V_121 ,
V_117 [ V_119 ] . V_129 , V_126 ) ;
if ( V_117 [ V_119 ] . V_128 == 0 || V_117 [ V_119 ] . V_128 == V_126 )
error = - V_130 ;
if ( V_117 [ V_119 ] . V_128 < 0 )
break;
switch ( V_117 [ V_119 ] . V_131 ) {
case V_132 :
V_117 [ V_119 ] . V_128 = F_54 (
V_15 -> V_16 , V_121 ,
V_117 [ V_119 ] . V_133 , & V_117 [ V_119 ] . V_134 ,
V_117 [ V_119 ] . V_135 ) ;
break;
case V_136 :
V_117 [ V_119 ] . V_128 = F_48 ( V_42 ) ;
if ( V_117 [ V_119 ] . V_128 )
break;
V_117 [ V_119 ] . V_128 = F_56 (
V_15 -> V_16 , V_121 ,
V_117 [ V_119 ] . V_133 , V_117 [ V_119 ] . V_134 ,
V_117 [ V_119 ] . V_135 ) ;
F_49 ( V_42 ) ;
break;
case V_137 :
V_117 [ V_119 ] . V_128 = F_48 ( V_42 ) ;
if ( V_117 [ V_119 ] . V_128 )
break;
V_117 [ V_119 ] . V_128 = F_59 (
V_15 -> V_16 , V_121 ,
V_117 [ V_119 ] . V_135 ) ;
F_49 ( V_42 ) ;
break;
default:
V_117 [ V_119 ] . V_128 = - V_17 ;
}
}
if ( F_10 ( V_118 . V_117 , V_117 , V_120 ) )
error = - V_37 ;
F_36 ( V_121 ) ;
V_127:
F_36 ( V_117 ) ;
V_62:
F_29 ( V_15 ) ;
return error ;
}
int
F_63 (
struct V_9 * V_10 ,
struct V_5 * V_5 ,
struct V_12 * V_58 ,
int V_138 ,
unsigned int V_1 ,
T_17 * V_139 )
{
struct V_140 * V_83 = V_10 -> V_24 ;
struct V_141 * V_84 ;
struct V_142 V_142 ;
bool V_143 = false ;
bool V_144 = false ;
int error ;
if ( ! F_64 ( & V_10 -> V_24 -> V_145 ) &&
! F_21 ( V_60 ) )
return - V_61 ;
if ( V_5 -> V_146 & ( V_147 | V_148 ) )
return - V_61 ;
if ( ! ( V_58 -> V_73 & V_68 ) )
return - V_13 ;
if ( ! F_6 ( V_5 -> V_22 ) )
return - V_17 ;
error = F_48 ( V_58 ) ;
if ( error )
return error ;
F_43 ( V_10 , V_149 ) ;
switch ( V_139 -> V_150 ) {
case 0 :
break;
case 1 :
V_139 -> V_151 += V_58 -> V_152 ;
break;
case 2 :
V_139 -> V_151 += F_65 ( V_10 ) ;
break;
default:
error = - V_17 ;
goto V_153;
}
switch ( V_1 ) {
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
if ( V_139 -> V_159 <= 0 ) {
error = - V_17 ;
goto V_153;
}
break;
default:
V_139 -> V_159 = 0 ;
break;
}
if ( V_139 -> V_151 < 0 ||
V_139 -> V_151 > V_83 -> V_160 -> V_161 ||
V_139 -> V_151 + V_139 -> V_159 < 0 ||
V_139 -> V_151 + V_139 -> V_159 >= V_83 -> V_160 -> V_161 ) {
error = - V_17 ;
goto V_153;
}
switch ( V_1 ) {
case V_154 :
error = F_66 ( V_10 , V_139 -> V_151 , V_139 -> V_159 ) ;
if ( ! error )
V_143 = true ;
break;
case V_155 :
case V_156 :
error = F_67 ( V_10 , V_139 -> V_151 , V_139 -> V_159 ,
V_162 ) ;
if ( ! error )
V_143 = true ;
break;
case V_157 :
case V_158 :
error = F_68 ( V_10 , V_139 -> V_151 , V_139 -> V_159 ) ;
break;
case V_163 :
case V_164 :
case V_165 :
case V_166 :
if ( V_139 -> V_151 > F_65 ( V_10 ) ) {
error = F_67 ( V_10 , F_65 ( V_10 ) ,
V_139 -> V_151 - F_65 ( V_10 ) , 0 ) ;
if ( error )
goto V_153;
}
V_142 . V_167 = V_168 ;
V_142 . V_169 = V_139 -> V_151 ;
error = F_69 ( V_10 , & V_142 ) ;
if ( ! error )
V_144 = true ;
break;
default:
ASSERT ( 0 ) ;
error = - V_17 ;
}
if ( error )
goto V_153;
V_84 = F_39 ( V_83 , V_170 ) ;
error = F_40 ( V_84 , & F_41 ( V_83 ) -> V_171 , 0 , 0 ) ;
if ( error ) {
F_42 ( V_84 , 0 ) ;
goto V_153;
}
F_43 ( V_10 , V_88 ) ;
F_44 ( V_84 , V_10 , V_88 ) ;
if ( ! ( V_138 & V_172 ) ) {
V_10 -> V_33 . V_173 &= ~ V_174 ;
if ( V_10 -> V_33 . V_173 & V_175 )
V_10 -> V_33 . V_173 &= ~ V_176 ;
F_70 ( V_84 , V_10 , V_177 | V_178 ) ;
}
if ( V_143 )
V_10 -> V_33 . V_179 |= V_180 ;
else if ( V_144 )
V_10 -> V_33 . V_179 &= ~ V_180 ;
F_45 ( V_84 , V_10 , V_91 ) ;
if ( V_58 -> V_71 & V_181 )
F_71 ( V_84 ) ;
error = F_46 ( V_84 , 0 ) ;
V_153:
F_72 ( V_10 , V_149 ) ;
F_49 ( V_58 ) ;
return error ;
}
STATIC int
F_73 (
T_9 * V_83 ,
unsigned int V_1 ,
void V_14 * V_92 )
{
T_18 V_182 ;
int V_183 ;
T_19 V_184 ;
int V_185 ;
int error ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( F_38 ( V_83 ) )
return - V_85 ;
if ( F_16 ( & V_182 , V_92 , sizeof( T_18 ) ) )
return - V_37 ;
if ( F_16 ( & V_184 , V_182 . V_186 , sizeof( V_187 ) ) )
return - V_37 ;
if ( ( V_183 = V_182 . V_188 ) <= 0 )
return - V_17 ;
if ( V_182 . V_189 == NULL )
return - V_17 ;
if ( V_1 == V_190 )
error = F_74 ( V_83 , & V_184 , & V_183 ,
V_182 . V_189 , V_191 ) ;
else if ( V_1 == V_192 )
error = F_75 ( V_83 , V_184 , V_182 . V_189 ,
sizeof( V_193 ) , NULL , & V_185 ) ;
else
error = F_76 ( V_83 , & V_184 , & V_183 , F_75 ,
sizeof( V_193 ) , V_182 . V_189 ,
& V_185 ) ;
if ( error )
return error ;
if ( V_182 . V_194 != NULL ) {
if ( F_10 ( V_182 . V_186 , & V_184 ,
sizeof( T_19 ) ) )
return - V_37 ;
if ( F_10 ( V_182 . V_194 , & V_183 , sizeof( V_183 ) ) )
return - V_37 ;
}
return 0 ;
}
STATIC int
F_77 (
T_9 * V_83 ,
void V_14 * V_92 )
{
T_20 V_195 ;
int error ;
error = F_78 ( V_83 , & V_195 , 3 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_195 , sizeof( V_196 ) ) )
return - V_37 ;
return 0 ;
}
STATIC int
F_79 (
T_9 * V_83 ,
void V_14 * V_92 )
{
T_20 V_195 ;
int error ;
error = F_78 ( V_83 , & V_195 , 4 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_195 , sizeof( V_195 ) ) )
return - V_37 ;
return 0 ;
}
STATIC unsigned int
F_80 (
unsigned int V_107 ,
unsigned int V_197 )
{
unsigned int V_198 = V_197 ;
if ( V_107 & V_199 )
V_198 |= V_200 ;
else
V_198 &= ~ V_200 ;
if ( V_107 & V_201 )
V_198 |= V_202 ;
else
V_198 &= ~ V_202 ;
if ( V_107 & V_203 )
V_198 |= V_204 ;
else
V_198 &= ~ V_204 ;
if ( V_107 & V_205 )
V_198 |= V_206 ;
else
V_198 &= ~ V_206 ;
if ( V_107 & V_207 )
V_198 |= V_208 ;
else
V_198 &= ~ V_208 ;
return V_198 ;
}
STATIC unsigned int
F_81 (
T_21 V_179 )
{
unsigned int V_107 = 0 ;
if ( V_179 & V_209 )
V_107 |= V_199 ;
if ( V_179 & V_210 )
V_107 |= V_201 ;
if ( V_179 & V_211 )
V_107 |= V_203 ;
if ( V_179 & V_212 )
V_107 |= V_205 ;
if ( V_179 & V_213 )
V_107 |= V_207 ;
return V_107 ;
}
STATIC int
F_82 (
T_6 * V_10 ,
int V_214 ,
void V_14 * V_92 )
{
struct V_215 V_216 ;
memset ( & V_216 , 0 , sizeof( struct V_215 ) ) ;
F_43 ( V_10 , V_217 ) ;
V_216 . V_218 = F_83 ( V_10 ) ;
V_216 . V_219 = V_10 -> V_33 . V_220 << V_10 -> V_24 -> V_145 . V_221 ;
V_216 . V_222 = F_84 ( V_10 ) ;
if ( V_214 ) {
if ( V_10 -> V_223 ) {
if ( V_10 -> V_223 -> V_224 & V_225 )
V_216 . V_226 = V_10 -> V_223 -> V_227 /
sizeof( V_228 ) ;
else
V_216 . V_226 = V_10 -> V_33 . V_229 ;
} else
V_216 . V_226 = 0 ;
} else {
if ( V_10 -> V_230 . V_224 & V_225 )
V_216 . V_226 = V_10 -> V_230 . V_227 /
sizeof( V_228 ) ;
else
V_216 . V_226 = V_10 -> V_33 . V_231 ;
}
F_72 ( V_10 , V_217 ) ;
if ( F_10 ( V_92 , & V_216 , sizeof( V_216 ) ) )
return - V_37 ;
return 0 ;
}
STATIC void
F_85 (
struct V_9 * V_10 ,
unsigned int V_198 )
{
unsigned int V_179 ;
V_179 = ( V_10 -> V_33 . V_179 & V_180 ) ;
if ( V_198 & V_200 )
V_179 |= V_209 ;
if ( V_198 & V_202 )
V_179 |= V_210 ;
if ( V_198 & V_204 )
V_179 |= V_211 ;
if ( V_198 & V_206 )
V_179 |= V_212 ;
if ( V_198 & V_208 )
V_179 |= V_213 ;
if ( V_198 & V_232 )
V_179 |= V_233 ;
if ( V_198 & V_234 )
V_179 |= V_235 ;
if ( V_198 & V_236 )
V_179 |= V_237 ;
if ( F_7 ( V_10 -> V_33 . V_173 ) ) {
if ( V_198 & V_238 )
V_179 |= V_239 ;
if ( V_198 & V_240 )
V_179 |= V_241 ;
if ( V_198 & V_242 )
V_179 |= V_243 ;
} else if ( F_6 ( V_10 -> V_33 . V_173 ) ) {
if ( V_198 & V_244 )
V_179 |= V_245 ;
if ( V_198 & V_246 )
V_179 |= V_247 ;
}
V_10 -> V_33 . V_179 = V_179 ;
}
STATIC void
F_86 (
struct V_9 * V_10 )
{
struct V_5 * V_5 = F_87 ( V_10 ) ;
unsigned int V_198 = F_83 ( V_10 ) ;
if ( V_198 & V_200 )
V_5 -> V_146 |= V_147 ;
else
V_5 -> V_146 &= ~ V_147 ;
if ( V_198 & V_202 )
V_5 -> V_146 |= V_148 ;
else
V_5 -> V_146 &= ~ V_148 ;
if ( V_198 & V_204 )
V_5 -> V_146 |= V_248 ;
else
V_5 -> V_146 &= ~ V_248 ;
if ( V_198 & V_206 )
V_5 -> V_146 |= V_249 ;
else
V_5 -> V_146 &= ~ V_249 ;
}
STATIC int
F_88 (
T_6 * V_10 ,
struct V_215 * V_216 ,
int V_250 )
{
struct V_140 * V_83 = V_10 -> V_24 ;
struct V_141 * V_84 ;
unsigned int V_251 = 0 ;
struct V_252 * V_253 = NULL ;
struct V_252 * V_254 = NULL ;
struct V_252 * V_255 = NULL ;
int V_256 ;
F_89 ( V_10 ) ;
if ( V_83 -> V_257 & V_258 )
return - V_259 ;
if ( F_38 ( V_83 ) )
return - V_85 ;
if ( ( V_250 & V_260 ) && ( V_216 -> V_222 > ( T_21 ) - 1 ) &&
! F_90 ( & V_10 -> V_24 -> V_145 ) )
return - V_17 ;
if ( F_91 ( V_83 ) && ( V_250 & V_260 ) ) {
V_256 = F_92 ( V_10 , V_10 -> V_33 . V_261 ,
V_10 -> V_33 . V_262 , V_216 -> V_222 ,
V_263 , & V_253 , NULL , & V_254 ) ;
if ( V_256 )
return V_256 ;
}
V_84 = F_39 ( V_83 , V_264 ) ;
V_256 = F_40 ( V_84 , & F_41 ( V_83 ) -> V_87 , 0 , 0 ) ;
if ( V_256 )
goto V_265;
V_251 = V_88 ;
F_43 ( V_10 , V_251 ) ;
if ( ! F_93 ( F_87 ( V_10 ) ) ) {
V_256 = - V_61 ;
goto V_265;
}
if ( V_250 & V_260 ) {
if ( F_94 () != & V_266 ) {
V_256 = - V_17 ;
goto V_265;
}
if ( F_95 ( V_83 ) &&
F_96 ( V_83 ) &&
F_84 ( V_10 ) != V_216 -> V_222 ) {
ASSERT ( V_84 ) ;
V_256 = F_97 ( V_84 , V_10 , V_253 , NULL ,
V_254 , F_21 ( V_267 ) ?
V_268 : 0 ) ;
if ( V_256 )
goto V_265;
}
}
if ( V_250 & V_269 ) {
if ( V_10 -> V_33 . V_231 &&
( ( V_10 -> V_33 . V_220 << V_83 -> V_145 . V_221 ) !=
V_216 -> V_219 ) ) {
V_256 = - V_17 ;
goto V_265;
}
if ( V_216 -> V_219 != 0 ) {
T_22 V_120 ;
T_23 V_270 ;
V_270 = F_98 ( V_83 , V_216 -> V_219 ) ;
if ( V_270 > V_271 ) {
V_256 = - V_17 ;
goto V_265;
}
if ( F_99 ( V_10 ) ||
( ( V_250 & V_272 ) &&
( V_216 -> V_218 & V_244 ) ) ) {
V_120 = V_83 -> V_145 . V_273 <<
V_83 -> V_145 . V_221 ;
} else {
V_120 = V_83 -> V_145 . V_274 ;
if ( V_270 > V_83 -> V_145 . V_275 / 2 ) {
V_256 = - V_17 ;
goto V_265;
}
}
if ( V_216 -> V_219 % V_120 ) {
V_256 = - V_17 ;
goto V_265;
}
}
}
if ( V_250 & V_272 ) {
if ( ( V_10 -> V_33 . V_231 || V_10 -> V_276 ) &&
( F_99 ( V_10 ) ) !=
( V_216 -> V_218 & V_244 ) ) {
V_256 = - V_17 ;
goto V_265;
}
if ( ( V_216 -> V_218 & V_244 ) ) {
if ( ( V_83 -> V_145 . V_277 == 0 ) ||
( V_83 -> V_145 . V_273 == 0 ) ||
( V_10 -> V_33 . V_220 % V_83 -> V_145 . V_273 ) ) {
V_256 = - V_17 ;
goto V_265;
}
}
if ( ( V_10 -> V_33 . V_179 &
( V_209 | V_210 ) ||
( V_216 -> V_218 &
( V_200 | V_202 ) ) ) &&
! F_21 ( V_278 ) ) {
V_256 = - V_61 ;
goto V_265;
}
}
F_44 ( V_84 , V_10 , 0 ) ;
if ( V_250 & V_260 ) {
if ( ( V_10 -> V_33 . V_173 & ( V_174 | V_176 ) ) &&
! F_100 ( F_87 ( V_10 ) , V_279 ) )
V_10 -> V_33 . V_173 &= ~ ( V_174 | V_176 ) ;
if ( F_84 ( V_10 ) != V_216 -> V_222 ) {
if ( F_95 ( V_83 ) && F_96 ( V_83 ) ) {
V_255 = F_101 ( V_84 , V_10 ,
& V_10 -> V_280 , V_254 ) ;
}
ASSERT ( V_10 -> V_33 . V_281 > 1 ) ;
F_102 ( V_10 , V_216 -> V_222 ) ;
}
}
if ( V_250 & V_269 )
V_10 -> V_33 . V_220 = V_216 -> V_219 >> V_83 -> V_145 . V_221 ;
if ( V_250 & V_272 ) {
F_85 ( V_10 , V_216 -> V_218 ) ;
F_86 ( V_10 ) ;
}
F_70 ( V_84 , V_10 , V_178 ) ;
F_45 ( V_84 , V_10 , V_91 ) ;
F_103 ( V_282 ) ;
if ( V_83 -> V_257 & V_283 )
F_71 ( V_84 ) ;
V_256 = F_46 ( V_84 , 0 ) ;
F_72 ( V_10 , V_251 ) ;
F_104 ( V_255 ) ;
F_104 ( V_253 ) ;
F_104 ( V_254 ) ;
return V_256 ;
V_265:
F_104 ( V_253 ) ;
F_104 ( V_254 ) ;
F_42 ( V_84 , 0 ) ;
if ( V_251 )
F_72 ( V_10 , V_251 ) ;
return V_256 ;
}
STATIC int
F_105 (
T_6 * V_10 ,
struct V_12 * V_58 ,
void V_14 * V_92 )
{
struct V_215 V_216 ;
unsigned int V_250 ;
int error ;
if ( F_16 ( & V_216 , V_92 , sizeof( V_216 ) ) )
return - V_37 ;
V_250 = V_272 | V_269 | V_260 ;
if ( V_58 -> V_71 & ( V_284 | V_285 ) )
V_250 |= V_286 ;
error = F_48 ( V_58 ) ;
if ( error )
return error ;
error = F_88 ( V_10 , & V_216 , V_250 ) ;
F_49 ( V_58 ) ;
return error ;
}
STATIC int
F_106 (
T_6 * V_10 ,
void V_14 * V_92 )
{
unsigned int V_107 ;
V_107 = F_81 ( V_10 -> V_33 . V_179 ) ;
if ( F_10 ( V_92 , & V_107 , sizeof( V_107 ) ) )
return - V_37 ;
return 0 ;
}
STATIC int
F_107 (
T_6 * V_10 ,
struct V_12 * V_58 ,
void V_14 * V_92 )
{
struct V_215 V_216 ;
unsigned int V_107 ;
unsigned int V_250 ;
int error ;
if ( F_16 ( & V_107 , V_92 , sizeof( V_107 ) ) )
return - V_37 ;
if ( V_107 & ~ ( V_199 | V_201 | \
V_205 | V_207 | \
V_203 ) )
return - V_287 ;
V_250 = V_272 ;
if ( V_58 -> V_71 & ( V_284 | V_285 ) )
V_250 |= V_286 ;
V_216 . V_218 = F_80 ( V_107 , F_83 ( V_10 ) ) ;
error = F_48 ( V_58 ) ;
if ( error )
return error ;
error = F_88 ( V_10 , & V_216 , V_250 ) ;
F_49 ( V_58 ) ;
return error ;
}
STATIC int
F_108 ( void * * V_288 , struct V_289 * V_290 , int * V_291 )
{
struct V_292 V_14 * V_293 = * V_288 ;
if ( F_10 ( V_293 , V_290 , sizeof( struct V_292 ) ) )
return - V_37 ;
* V_288 += sizeof( struct V_292 ) ;
return 0 ;
}
STATIC int
F_109 (
struct V_9 * V_10 ,
int V_138 ,
unsigned int V_1 ,
void V_14 * V_92 )
{
struct V_289 V_294 ;
int error ;
if ( F_16 ( & V_294 , V_92 , sizeof( struct V_289 ) ) )
return - V_37 ;
if ( V_294 . V_295 < 2 )
return - V_17 ;
V_294 . V_296 = ( V_1 == V_297 ? V_298 : 0 ) ;
if ( V_138 & V_172 )
V_294 . V_296 |= V_299 ;
error = F_110 ( V_10 , & V_294 , F_108 ,
(struct V_292 * ) V_92 + 1 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_294 , sizeof( struct V_292 ) ) )
return - V_37 ;
return 0 ;
}
STATIC int
F_111 ( void * * V_288 , struct V_289 * V_290 , int * V_291 )
{
struct V_289 V_14 * V_293 = * V_288 ;
if ( F_10 ( V_293 , V_290 , sizeof( struct V_289 ) ) )
return - V_37 ;
* V_288 += sizeof( struct V_289 ) ;
return 0 ;
}
STATIC int
F_112 (
struct V_9 * V_10 ,
void V_14 * V_92 )
{
struct V_289 V_294 ;
int error ;
if ( F_16 ( & V_294 , V_92 , sizeof( V_294 ) ) )
return - V_37 ;
if ( V_294 . V_295 < 2 )
return - V_17 ;
if ( V_294 . V_296 & ( ~ V_300 ) )
return - V_17 ;
error = F_110 ( V_10 , & V_294 , F_111 ,
(struct V_289 * ) V_92 + 1 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_294 , sizeof( struct V_289 ) ) )
return - V_37 ;
return 0 ;
}
int
F_113 (
T_24 * V_301 )
{
T_6 * V_10 , * V_302 ;
struct V_6 V_7 , V_303 ;
int error = 0 ;
V_7 = F_2 ( ( int ) V_301 -> V_304 ) ;
if ( ! V_7 . V_12 ) {
error = - V_17 ;
goto V_97;
}
if ( ! ( V_7 . V_12 -> V_73 & V_68 ) ||
! ( V_7 . V_12 -> V_73 & V_305 ) ||
( V_7 . V_12 -> V_71 & V_66 ) ) {
error = - V_13 ;
goto V_306;
}
V_303 = F_2 ( ( int ) V_301 -> V_307 ) ;
if ( ! V_303 . V_12 ) {
error = - V_17 ;
goto V_306;
}
if ( ! ( V_303 . V_12 -> V_73 & V_68 ) ||
! ( V_303 . V_12 -> V_73 & V_305 ) ||
( V_303 . V_12 -> V_71 & V_66 ) ) {
error = - V_13 ;
goto V_308;
}
if ( F_114 ( F_3 ( V_7 . V_12 ) ) ||
F_114 ( F_3 ( V_303 . V_12 ) ) ) {
error = - V_17 ;
goto V_308;
}
V_10 = F_5 ( F_3 ( V_7 . V_12 ) ) ;
V_302 = F_5 ( F_3 ( V_303 . V_12 ) ) ;
if ( V_10 -> V_24 != V_302 -> V_24 ) {
error = - V_17 ;
goto V_308;
}
if ( V_10 -> V_36 == V_302 -> V_36 ) {
error = - V_17 ;
goto V_308;
}
if ( F_38 ( V_10 -> V_24 ) ) {
error = - V_85 ;
goto V_308;
}
error = F_115 ( V_10 , V_302 , V_301 ) ;
V_308:
F_11 ( V_303 ) ;
V_306:
F_11 ( V_7 ) ;
V_97:
return error ;
}
long
F_116 (
struct V_12 * V_58 ,
unsigned int V_1 ,
unsigned long V_309 )
{
struct V_5 * V_5 = F_3 ( V_58 ) ;
struct V_9 * V_10 = F_5 ( V_5 ) ;
struct V_140 * V_83 = V_10 -> V_24 ;
void V_14 * V_92 = ( void V_14 * ) V_309 ;
int V_138 = 0 ;
int error ;
if ( V_58 -> V_73 & V_74 )
V_138 |= V_172 ;
F_117 ( V_10 ) ;
switch ( V_1 ) {
case V_310 :
return F_118 ( V_83 , V_92 ) ;
case V_163 :
case V_165 :
case V_155 :
case V_157 :
case V_164 :
case V_166 :
case V_156 :
case V_158 :
case V_154 : {
T_17 V_139 ;
if ( F_16 ( & V_139 , V_92 , sizeof( V_139 ) ) )
return - V_37 ;
return F_63 ( V_10 , V_5 , V_58 , V_138 , V_1 , & V_139 ) ;
}
case V_311 : {
struct V_312 V_313 ;
T_25 * V_314 =
F_99 ( V_10 ) ?
V_83 -> V_315 : V_83 -> V_316 ;
V_313 . V_317 = V_313 . V_318 = V_314 -> V_319 ;
V_313 . V_320 = V_123 & ~ ( V_313 . V_318 - 1 ) ;
if ( F_10 ( V_92 , & V_313 , sizeof( V_313 ) ) )
return - V_37 ;
return 0 ;
}
case V_192 :
case V_321 :
case V_190 :
return F_73 ( V_83 , V_1 , V_92 ) ;
case V_322 :
return F_77 ( V_83 , V_92 ) ;
case V_323 :
return F_79 ( V_83 , V_92 ) ;
case V_324 :
return F_119 ( V_5 -> V_325 , ( int V_14 * ) V_92 ) ;
case V_326 :
return F_82 ( V_10 , 0 , V_92 ) ;
case V_327 :
return F_82 ( V_10 , 1 , V_92 ) ;
case V_328 :
return F_105 ( V_10 , V_58 , V_92 ) ;
case V_329 :
return F_106 ( V_10 , V_92 ) ;
case V_330 :
return F_107 ( V_10 , V_58 , V_92 ) ;
case V_331 : {
struct V_93 V_332 ;
if ( F_16 ( & V_332 , V_92 , sizeof( V_332 ) ) )
return - V_37 ;
error = F_48 ( V_58 ) ;
if ( error )
return error ;
error = F_37 ( V_10 , V_332 . V_99 ,
V_332 . V_100 ) ;
F_49 ( V_58 ) ;
return error ;
}
case V_333 :
case V_297 :
return F_109 ( V_10 , V_138 , V_1 , V_92 ) ;
case V_334 :
return F_112 ( V_10 , V_92 ) ;
case V_11 :
case V_335 :
case V_27 : {
T_1 V_2 ;
if ( F_16 ( & V_2 , V_92 , sizeof( V_2 ) ) )
return - V_37 ;
return F_1 ( V_1 , & V_2 ) ;
}
case V_336 : {
T_1 V_2 ;
if ( F_16 ( & V_2 , V_92 , sizeof( T_1 ) ) )
return - V_37 ;
return F_19 ( V_58 , & V_2 ) ;
}
case V_337 :
return F_47 ( V_58 , V_92 ) ;
case V_338 : {
T_1 V_2 ;
if ( F_16 ( & V_2 , V_92 , sizeof( T_1 ) ) )
return - V_37 ;
return F_32 ( V_58 , & V_2 ) ;
}
case V_339 :
return F_50 ( V_58 , V_92 ) ;
case V_340 :
return F_61 ( V_58 , V_92 ) ;
case V_341 : {
struct V_342 V_301 ;
if ( F_16 ( & V_301 , V_92 , sizeof( T_24 ) ) )
return - V_37 ;
error = F_48 ( V_58 ) ;
if ( error )
return error ;
error = F_113 ( & V_301 ) ;
F_49 ( V_58 ) ;
return error ;
}
case V_343 : {
T_26 V_97 ;
error = F_120 ( V_83 , & V_97 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_97 , sizeof( V_97 ) ) )
return - V_37 ;
return 0 ;
}
case V_344 : {
T_27 V_345 ;
T_28 V_346 ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( V_83 -> V_257 & V_258 )
return - V_259 ;
if ( F_16 ( & V_345 , V_92 , sizeof( V_345 ) ) )
return - V_37 ;
error = F_48 ( V_58 ) ;
if ( error )
return error ;
V_346 = V_345 . V_347 ;
error = F_121 ( V_83 , & V_346 , & V_345 ) ;
F_49 ( V_58 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_345 , sizeof( V_345 ) ) )
return - V_37 ;
return 0 ;
}
case V_348 : {
T_27 V_97 ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
error = F_121 ( V_83 , NULL , & V_97 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_97 , sizeof( V_97 ) ) )
return - V_37 ;
return 0 ;
}
case V_349 : {
T_29 V_346 ;
if ( F_16 ( & V_346 , V_92 , sizeof( V_346 ) ) )
return - V_37 ;
error = F_48 ( V_58 ) ;
if ( error )
return error ;
error = F_122 ( V_83 , & V_346 ) ;
F_49 ( V_58 ) ;
return error ;
}
case V_350 : {
T_30 V_346 ;
if ( F_16 ( & V_346 , V_92 , sizeof( V_346 ) ) )
return - V_37 ;
error = F_48 ( V_58 ) ;
if ( error )
return error ;
error = F_123 ( V_83 , & V_346 ) ;
F_49 ( V_58 ) ;
return error ;
}
case V_351 : {
T_31 V_346 ;
if ( F_16 ( & V_346 , V_92 , sizeof( V_346 ) ) )
return - V_37 ;
error = F_48 ( V_58 ) ;
if ( error )
return error ;
error = F_124 ( V_83 , & V_346 ) ;
F_49 ( V_58 ) ;
return error ;
}
case V_352 : {
T_14 V_346 ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( F_125 ( V_346 , ( T_14 V_14 * ) V_92 ) )
return - V_37 ;
return F_126 ( V_83 , V_346 ) ;
}
case V_353 : {
T_32 V_346 ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( F_16 ( & V_346 , V_92 , sizeof( V_346 ) ) )
return - V_37 ;
return F_127 ( V_346 . V_354 , V_83 ) ;
}
case V_355 :
if ( ! F_21 ( V_60 ) )
return - V_61 ;
return F_128 ( V_83 , 1 ) ;
case V_356 : {
struct V_357 V_358 ;
struct V_359 V_360 ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( V_83 -> V_257 & V_258 )
return - V_259 ;
if ( F_16 ( & V_358 , V_92 , sizeof( V_358 ) ) )
return - V_37 ;
error = F_129 ( & V_358 , & V_360 ) ;
if ( error )
return error ;
return F_130 ( V_83 , & V_360 ) ;
}
default:
return - V_361 ;
}
}
