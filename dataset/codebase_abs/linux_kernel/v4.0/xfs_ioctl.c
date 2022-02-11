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
if ( ! F_33 ( V_15 ) ) {
error = - V_17 ;
goto V_62;
}
if ( F_16 ( & V_75 , V_2 -> V_39 , sizeof( T_5 ) ) ) {
error = - V_37 ;
goto V_62;
}
V_76 = F_34 ( V_77 + 1 , V_78 ) ;
if ( ! V_76 ) {
error = - V_79 ;
goto V_62;
}
error = F_35 ( F_5 ( V_15 -> V_16 ) , V_76 ) ;
if ( error )
goto V_80;
error = F_36 ( V_2 -> V_38 , V_75 , V_76 ) ;
if ( error )
goto V_80;
V_80:
F_37 ( V_76 ) ;
V_62:
F_29 ( V_15 ) ;
return error ;
}
int
F_38 (
T_6 * V_10 ,
T_7 V_81 ,
T_8 V_82 )
{
T_9 * V_83 = V_10 -> V_24 ;
T_10 * V_84 ;
int error ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( F_39 ( V_83 ) )
return - V_85 ;
V_84 = F_40 ( V_83 , V_86 ) ;
error = F_41 ( V_84 , & F_42 ( V_83 ) -> V_87 , 0 , 0 ) ;
if ( error ) {
F_43 ( V_84 , 0 ) ;
return error ;
}
F_44 ( V_10 , V_88 ) ;
F_45 ( V_84 , V_10 , V_88 ) ;
V_10 -> V_33 . V_89 = V_81 ;
V_10 -> V_33 . V_90 = V_82 ;
F_46 ( V_84 , V_10 , V_91 ) ;
error = F_47 ( V_84 , 0 ) ;
return error ;
}
STATIC int
F_48 (
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
error = F_49 ( V_42 ) ;
if ( error )
return error ;
V_15 = F_18 ( V_42 , & V_95 . V_2 ) ;
if ( F_22 ( V_15 ) ) {
F_50 ( V_42 ) ;
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
error = F_38 ( F_5 ( V_15 -> V_16 ) , V_94 . V_99 ,
V_94 . V_100 ) ;
V_97:
F_50 ( V_42 ) ;
F_29 ( V_15 ) ;
return error ;
}
STATIC int
F_51 (
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
V_103 = F_52 ( V_102 . V_104 , V_110 ) ;
if ( ! V_103 )
goto V_62;
V_101 = ( T_12 * ) & V_102 . V_111 ;
error = F_53 ( F_5 ( V_15 -> V_16 ) , V_103 , V_102 . V_104 ,
V_102 . V_107 , V_101 ) ;
if ( error )
goto V_80;
if ( F_10 ( V_102 . V_112 , V_103 , V_102 . V_104 ) )
error = - V_37 ;
V_80:
F_54 ( V_103 ) ;
V_62:
F_29 ( V_15 ) ;
return error ;
}
int
F_55 (
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
V_103 = F_52 ( * V_115 , V_110 ) ;
if ( ! V_103 )
return - V_79 ;
error = F_56 ( F_5 ( V_5 ) , V_113 , V_103 , ( int * ) V_115 , V_107 ) ;
if ( error )
goto V_80;
if ( F_10 ( V_114 , V_103 , * V_115 ) )
error = - V_37 ;
V_80:
F_54 ( V_103 ) ;
return error ;
}
int
F_57 (
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
V_103 = F_58 ( V_114 , V_115 ) ;
if ( F_22 ( V_103 ) )
return F_23 ( V_103 ) ;
return F_59 ( F_5 ( V_5 ) , V_113 , V_103 , V_115 , V_107 ) ;
}
int
F_60 (
struct V_5 * V_5 ,
unsigned char * V_113 ,
T_14 V_107 )
{
if ( F_26 ( V_5 ) || F_25 ( V_5 ) )
return - V_61 ;
return F_61 ( F_5 ( V_5 ) , V_113 , V_107 ) ;
}
STATIC int
F_62 (
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
V_117 = F_58 ( V_118 . V_117 , V_120 ) ;
if ( F_22 ( V_117 ) ) {
error = F_23 ( V_117 ) ;
goto V_62;
}
error = - V_79 ;
V_121 = F_34 ( V_126 , V_78 ) ;
if ( ! V_121 )
goto V_127;
error = 0 ;
for ( V_119 = 0 ; V_119 < V_118 . V_122 ; V_119 ++ ) {
V_117 [ V_119 ] . V_128 = F_63 ( ( char * ) V_121 ,
V_117 [ V_119 ] . V_129 , V_126 ) ;
if ( V_117 [ V_119 ] . V_128 == 0 || V_117 [ V_119 ] . V_128 == V_126 )
error = - V_130 ;
if ( V_117 [ V_119 ] . V_128 < 0 )
break;
switch ( V_117 [ V_119 ] . V_131 ) {
case V_132 :
V_117 [ V_119 ] . V_128 = F_55 (
V_15 -> V_16 , V_121 ,
V_117 [ V_119 ] . V_133 , & V_117 [ V_119 ] . V_134 ,
V_117 [ V_119 ] . V_135 ) ;
break;
case V_136 :
V_117 [ V_119 ] . V_128 = F_49 ( V_42 ) ;
if ( V_117 [ V_119 ] . V_128 )
break;
V_117 [ V_119 ] . V_128 = F_57 (
V_15 -> V_16 , V_121 ,
V_117 [ V_119 ] . V_133 , V_117 [ V_119 ] . V_134 ,
V_117 [ V_119 ] . V_135 ) ;
F_50 ( V_42 ) ;
break;
case V_137 :
V_117 [ V_119 ] . V_128 = F_49 ( V_42 ) ;
if ( V_117 [ V_119 ] . V_128 )
break;
V_117 [ V_119 ] . V_128 = F_60 (
V_15 -> V_16 , V_121 ,
V_117 [ V_119 ] . V_135 ) ;
F_50 ( V_42 ) ;
break;
default:
V_117 [ V_119 ] . V_128 = - V_17 ;
}
}
if ( F_10 ( V_118 . V_117 , V_117 , V_120 ) )
error = - V_37 ;
F_37 ( V_121 ) ;
V_127:
F_37 ( V_117 ) ;
V_62:
F_29 ( V_15 ) ;
return error ;
}
int
F_64 (
struct V_9 * V_10 ,
struct V_5 * V_5 ,
struct V_12 * V_58 ,
int V_138 ,
unsigned int V_1 ,
T_17 * V_139 )
{
struct V_140 V_140 ;
enum V_141 V_107 = 0 ;
T_18 V_142 = V_143 ;
int error ;
if ( ! F_65 ( & V_10 -> V_24 -> V_144 ) &&
! F_21 ( V_60 ) )
return - V_61 ;
if ( V_5 -> V_145 & ( V_146 | V_147 ) )
return - V_61 ;
if ( ! ( V_58 -> V_73 & V_68 ) )
return - V_13 ;
if ( ! F_6 ( V_5 -> V_22 ) )
return - V_17 ;
if ( V_58 -> V_71 & V_148 )
V_107 |= V_149 ;
if ( V_138 & V_150 )
V_107 |= V_151 ;
error = F_49 ( V_58 ) ;
if ( error )
return error ;
F_44 ( V_10 , V_142 ) ;
error = F_66 ( V_5 , & V_142 ) ;
if ( error )
goto V_152;
switch ( V_139 -> V_153 ) {
case 0 :
break;
case 1 :
V_139 -> V_154 += V_58 -> V_155 ;
break;
case 2 :
V_139 -> V_154 += F_67 ( V_10 ) ;
break;
default:
error = - V_17 ;
goto V_152;
}
switch ( V_1 ) {
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
if ( V_139 -> V_161 <= 0 ) {
error = - V_17 ;
goto V_152;
}
break;
default:
V_139 -> V_161 = 0 ;
break;
}
if ( V_139 -> V_154 < 0 ||
V_139 -> V_154 > V_5 -> V_18 -> V_162 ||
V_139 -> V_154 + V_139 -> V_161 < 0 ||
V_139 -> V_154 + V_139 -> V_161 >= V_5 -> V_18 -> V_162 ) {
error = - V_17 ;
goto V_152;
}
switch ( V_1 ) {
case V_156 :
V_107 |= V_163 ;
error = F_68 ( V_10 , V_139 -> V_154 , V_139 -> V_161 ) ;
break;
case V_157 :
case V_158 :
V_107 |= V_163 ;
error = F_69 ( V_10 , V_139 -> V_154 , V_139 -> V_161 ,
V_164 ) ;
break;
case V_159 :
case V_160 :
error = F_70 ( V_10 , V_139 -> V_154 , V_139 -> V_161 ) ;
break;
case V_165 :
case V_166 :
case V_167 :
case V_168 :
V_107 |= V_169 ;
if ( V_139 -> V_154 > F_67 ( V_10 ) ) {
error = F_69 ( V_10 , F_67 ( V_10 ) ,
V_139 -> V_154 - F_67 ( V_10 ) , 0 ) ;
if ( error )
goto V_152;
}
V_140 . V_170 = V_171 ;
V_140 . V_172 = V_139 -> V_154 ;
error = F_71 ( V_10 , & V_140 ) ;
break;
default:
ASSERT ( 0 ) ;
error = - V_17 ;
}
if ( error )
goto V_152;
error = F_72 ( V_10 , V_107 ) ;
V_152:
F_73 ( V_10 , V_142 ) ;
F_50 ( V_58 ) ;
return error ;
}
STATIC int
F_74 (
T_9 * V_83 ,
unsigned int V_1 ,
void V_14 * V_92 )
{
T_19 V_173 ;
int V_174 ;
T_20 V_175 ;
int V_176 ;
int error ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( F_39 ( V_83 ) )
return - V_85 ;
if ( F_16 ( & V_173 , V_92 , sizeof( T_19 ) ) )
return - V_37 ;
if ( F_16 ( & V_175 , V_173 . V_177 , sizeof( V_178 ) ) )
return - V_37 ;
if ( ( V_174 = V_173 . V_179 ) <= 0 )
return - V_17 ;
if ( V_173 . V_180 == NULL )
return - V_17 ;
if ( V_1 == V_181 )
error = F_75 ( V_83 , & V_175 , & V_174 ,
V_173 . V_180 , V_182 ) ;
else if ( V_1 == V_183 )
error = F_76 ( V_83 , V_175 , V_173 . V_180 ,
sizeof( V_184 ) , NULL , & V_176 ) ;
else
error = F_77 ( V_83 , & V_175 , & V_174 , F_76 ,
sizeof( V_184 ) , V_173 . V_180 ,
& V_176 ) ;
if ( error )
return error ;
if ( V_173 . V_185 != NULL ) {
if ( F_10 ( V_173 . V_177 , & V_175 ,
sizeof( T_20 ) ) )
return - V_37 ;
if ( F_10 ( V_173 . V_185 , & V_174 , sizeof( V_174 ) ) )
return - V_37 ;
}
return 0 ;
}
STATIC int
F_78 (
T_9 * V_83 ,
void V_14 * V_92 )
{
T_21 V_186 ;
int error ;
error = F_79 ( V_83 , & V_186 , 3 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_186 , sizeof( V_187 ) ) )
return - V_37 ;
return 0 ;
}
STATIC int
F_80 (
T_9 * V_83 ,
void V_14 * V_92 )
{
T_21 V_186 ;
int error ;
error = F_79 ( V_83 , & V_186 , 4 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_186 , sizeof( V_186 ) ) )
return - V_37 ;
return 0 ;
}
STATIC unsigned int
F_81 (
unsigned int V_107 ,
unsigned int V_188 )
{
unsigned int V_189 = V_188 ;
if ( V_107 & V_190 )
V_189 |= V_191 ;
else
V_189 &= ~ V_191 ;
if ( V_107 & V_192 )
V_189 |= V_193 ;
else
V_189 &= ~ V_193 ;
if ( V_107 & V_194 )
V_189 |= V_195 ;
else
V_189 &= ~ V_195 ;
if ( V_107 & V_196 )
V_189 |= V_197 ;
else
V_189 &= ~ V_197 ;
if ( V_107 & V_198 )
V_189 |= V_199 ;
else
V_189 &= ~ V_199 ;
return V_189 ;
}
STATIC unsigned int
F_82 (
T_22 V_200 )
{
unsigned int V_107 = 0 ;
if ( V_200 & V_201 )
V_107 |= V_190 ;
if ( V_200 & V_202 )
V_107 |= V_192 ;
if ( V_200 & V_203 )
V_107 |= V_194 ;
if ( V_200 & V_204 )
V_107 |= V_196 ;
if ( V_200 & V_205 )
V_107 |= V_198 ;
return V_107 ;
}
STATIC int
F_83 (
T_6 * V_10 ,
int V_206 ,
void V_14 * V_92 )
{
struct V_207 V_208 ;
memset ( & V_208 , 0 , sizeof( struct V_207 ) ) ;
F_44 ( V_10 , V_209 ) ;
V_208 . V_210 = F_84 ( V_10 ) ;
V_208 . V_211 = V_10 -> V_33 . V_212 << V_10 -> V_24 -> V_144 . V_213 ;
V_208 . V_214 = F_85 ( V_10 ) ;
if ( V_206 ) {
if ( V_10 -> V_215 ) {
if ( V_10 -> V_215 -> V_216 & V_217 )
V_208 . V_218 = V_10 -> V_215 -> V_219 /
sizeof( V_220 ) ;
else
V_208 . V_218 = V_10 -> V_33 . V_221 ;
} else
V_208 . V_218 = 0 ;
} else {
if ( V_10 -> V_222 . V_216 & V_217 )
V_208 . V_218 = V_10 -> V_222 . V_219 /
sizeof( V_220 ) ;
else
V_208 . V_218 = V_10 -> V_33 . V_223 ;
}
F_73 ( V_10 , V_209 ) ;
if ( F_10 ( V_92 , & V_208 , sizeof( V_208 ) ) )
return - V_37 ;
return 0 ;
}
STATIC void
F_86 (
struct V_9 * V_10 ,
unsigned int V_189 )
{
unsigned int V_200 ;
V_200 = ( V_10 -> V_33 . V_200 & V_224 ) ;
if ( V_189 & V_191 )
V_200 |= V_201 ;
if ( V_189 & V_193 )
V_200 |= V_202 ;
if ( V_189 & V_195 )
V_200 |= V_203 ;
if ( V_189 & V_197 )
V_200 |= V_204 ;
if ( V_189 & V_199 )
V_200 |= V_205 ;
if ( V_189 & V_225 )
V_200 |= V_226 ;
if ( V_189 & V_227 )
V_200 |= V_228 ;
if ( F_7 ( V_10 -> V_33 . V_229 ) ) {
if ( V_189 & V_230 )
V_200 |= V_231 ;
if ( V_189 & V_232 )
V_200 |= V_233 ;
if ( V_189 & V_234 )
V_200 |= V_235 ;
if ( V_189 & V_236 )
V_200 |= V_237 ;
} else if ( F_6 ( V_10 -> V_33 . V_229 ) ) {
if ( V_189 & V_238 )
V_200 |= V_239 ;
if ( V_189 & V_240 )
V_200 |= V_241 ;
}
V_10 -> V_33 . V_200 = V_200 ;
}
STATIC void
F_87 (
struct V_9 * V_10 )
{
struct V_5 * V_5 = F_88 ( V_10 ) ;
unsigned int V_189 = F_84 ( V_10 ) ;
if ( V_189 & V_191 )
V_5 -> V_145 |= V_146 ;
else
V_5 -> V_145 &= ~ V_146 ;
if ( V_189 & V_193 )
V_5 -> V_145 |= V_147 ;
else
V_5 -> V_145 &= ~ V_147 ;
if ( V_189 & V_195 )
V_5 -> V_145 |= V_242 ;
else
V_5 -> V_145 &= ~ V_242 ;
if ( V_189 & V_197 )
V_5 -> V_145 |= V_243 ;
else
V_5 -> V_145 &= ~ V_243 ;
}
static int
F_89 (
struct V_244 * V_84 ,
struct V_9 * V_10 ,
struct V_207 * V_208 )
{
struct V_245 * V_83 = V_10 -> V_24 ;
if ( ( V_10 -> V_33 . V_223 || V_10 -> V_246 ) &&
F_90 ( V_10 ) != ( V_208 -> V_210 & V_238 ) )
return - V_17 ;
if ( V_208 -> V_210 & V_238 ) {
if ( V_83 -> V_144 . V_247 == 0 || V_83 -> V_144 . V_248 == 0 ||
( V_10 -> V_33 . V_212 % V_83 -> V_144 . V_248 ) )
return - V_17 ;
}
if ( ( ( V_10 -> V_33 . V_200 & ( V_201 | V_202 ) ) ||
( V_208 -> V_210 & ( V_191 | V_193 ) ) ) &&
! F_21 ( V_249 ) )
return - V_61 ;
F_86 ( V_10 , V_208 -> V_210 ) ;
F_87 ( V_10 ) ;
F_91 ( V_84 , V_10 , V_250 ) ;
F_46 ( V_84 , V_10 , V_91 ) ;
F_92 ( V_251 ) ;
return 0 ;
}
static struct V_244 *
F_93 (
struct V_9 * V_10 )
{
struct V_245 * V_83 = V_10 -> V_24 ;
struct V_244 * V_84 ;
int error ;
if ( V_83 -> V_252 & V_253 )
return F_15 ( - V_254 ) ;
if ( F_39 ( V_83 ) )
return F_15 ( - V_85 ) ;
V_84 = F_40 ( V_83 , V_255 ) ;
error = F_41 ( V_84 , & F_42 ( V_83 ) -> V_87 , 0 , 0 ) ;
if ( error )
goto V_256;
F_44 ( V_10 , V_88 ) ;
F_45 ( V_84 , V_10 , V_88 ) ;
if ( ! F_94 ( F_88 ( V_10 ) ) ) {
error = - V_61 ;
goto V_256;
}
if ( V_83 -> V_252 & V_257 )
F_95 ( V_84 ) ;
return V_84 ;
V_256:
F_43 ( V_84 , 0 ) ;
return F_15 ( error ) ;
}
static int
F_96 (
struct V_9 * V_10 ,
struct V_207 * V_208 )
{
struct V_245 * V_83 = V_10 -> V_24 ;
if ( ( V_208 -> V_210 & V_240 ) && ! F_6 ( V_10 -> V_33 . V_229 ) )
return - V_17 ;
if ( ( V_208 -> V_210 & V_234 ) &&
! F_7 ( V_10 -> V_33 . V_229 ) )
return - V_17 ;
if ( F_6 ( V_10 -> V_33 . V_229 ) && V_10 -> V_33 . V_223 &&
( ( V_10 -> V_33 . V_212 << V_83 -> V_144 . V_213 ) != V_208 -> V_211 ) )
return - V_17 ;
if ( V_208 -> V_211 != 0 ) {
T_23 V_120 ;
T_24 V_258 ;
V_258 = F_97 ( V_83 , V_208 -> V_211 ) ;
if ( V_258 > V_259 )
return - V_17 ;
if ( F_90 ( V_10 ) ||
( V_208 -> V_210 & V_238 ) ) {
V_120 = V_83 -> V_144 . V_248 << V_83 -> V_144 . V_213 ;
} else {
V_120 = V_83 -> V_144 . V_260 ;
if ( V_258 > V_83 -> V_144 . V_261 / 2 )
return - V_17 ;
}
if ( V_208 -> V_211 % V_120 )
return - V_17 ;
} else
V_208 -> V_210 &= ~ ( V_240 | V_234 ) ;
return 0 ;
}
static int
F_98 (
struct V_9 * V_10 ,
struct V_207 * V_208 )
{
if ( V_208 -> V_214 > ( T_22 ) - 1 &&
! F_99 ( & V_10 -> V_24 -> V_144 ) )
return - V_17 ;
if ( F_100 () == & V_262 )
return 0 ;
if ( F_85 ( V_10 ) != V_208 -> V_214 )
return - V_17 ;
if ( ( V_208 -> V_210 & V_236 ) !=
( V_10 -> V_33 . V_200 & V_237 ) )
return - V_17 ;
return 0 ;
}
STATIC int
F_101 (
T_6 * V_10 ,
struct V_207 * V_208 )
{
struct V_245 * V_83 = V_10 -> V_24 ;
struct V_244 * V_84 ;
struct V_263 * V_264 = NULL ;
struct V_263 * V_265 = NULL ;
struct V_263 * V_266 = NULL ;
int V_267 ;
F_102 ( V_10 ) ;
V_267 = F_98 ( V_10 , V_208 ) ;
if ( V_267 )
return V_267 ;
if ( F_103 ( V_83 ) ) {
V_267 = F_104 ( V_10 , V_10 -> V_33 . V_268 ,
V_10 -> V_33 . V_269 , V_208 -> V_214 ,
V_270 , & V_264 , NULL , & V_265 ) ;
if ( V_267 )
return V_267 ;
}
V_84 = F_93 ( V_10 ) ;
if ( F_22 ( V_84 ) ) {
V_267 = F_23 ( V_84 ) ;
goto V_271;
}
if ( F_105 ( V_83 ) && F_106 ( V_83 ) &&
F_85 ( V_10 ) != V_208 -> V_214 ) {
V_267 = F_107 ( V_84 , V_10 , V_264 , NULL , V_265 ,
F_21 ( V_272 ) ? V_273 : 0 ) ;
if ( V_267 )
goto V_274;
}
V_267 = F_96 ( V_10 , V_208 ) ;
if ( V_267 )
goto V_274;
V_267 = F_89 ( V_84 , V_10 , V_208 ) ;
if ( V_267 )
goto V_274;
if ( ( V_10 -> V_33 . V_229 & ( V_275 | V_276 ) ) &&
! F_108 ( F_88 ( V_10 ) , V_277 ) )
V_10 -> V_33 . V_229 &= ~ ( V_275 | V_276 ) ;
if ( F_85 ( V_10 ) != V_208 -> V_214 ) {
if ( F_105 ( V_83 ) && F_106 ( V_83 ) ) {
V_266 = F_109 ( V_84 , V_10 ,
& V_10 -> V_278 , V_265 ) ;
}
ASSERT ( V_10 -> V_33 . V_279 > 1 ) ;
F_110 ( V_10 , V_208 -> V_214 ) ;
}
if ( V_10 -> V_33 . V_200 & ( V_241 | V_235 ) )
V_10 -> V_33 . V_212 = V_208 -> V_211 >> V_83 -> V_144 . V_213 ;
else
V_10 -> V_33 . V_212 = 0 ;
V_267 = F_47 ( V_84 , 0 ) ;
F_111 ( V_266 ) ;
F_111 ( V_264 ) ;
F_111 ( V_265 ) ;
return V_267 ;
V_274:
F_43 ( V_84 , 0 ) ;
V_271:
F_111 ( V_264 ) ;
F_111 ( V_265 ) ;
return V_267 ;
}
STATIC int
F_112 (
T_6 * V_10 ,
struct V_12 * V_58 ,
void V_14 * V_92 )
{
struct V_207 V_208 ;
int error ;
if ( F_16 ( & V_208 , V_92 , sizeof( V_208 ) ) )
return - V_37 ;
error = F_49 ( V_58 ) ;
if ( error )
return error ;
error = F_101 ( V_10 , & V_208 ) ;
F_50 ( V_58 ) ;
return error ;
}
STATIC int
F_113 (
T_6 * V_10 ,
void V_14 * V_92 )
{
unsigned int V_107 ;
V_107 = F_82 ( V_10 -> V_33 . V_200 ) ;
if ( F_10 ( V_92 , & V_107 , sizeof( V_107 ) ) )
return - V_37 ;
return 0 ;
}
STATIC int
F_114 (
struct V_9 * V_10 ,
struct V_12 * V_58 ,
void V_14 * V_92 )
{
struct V_244 * V_84 ;
struct V_207 V_208 ;
unsigned int V_107 ;
int error ;
if ( F_16 ( & V_107 , V_92 , sizeof( V_107 ) ) )
return - V_37 ;
if ( V_107 & ~ ( V_190 | V_192 | \
V_196 | V_198 | \
V_194 ) )
return - V_280 ;
V_208 . V_210 = F_81 ( V_107 , F_84 ( V_10 ) ) ;
error = F_49 ( V_58 ) ;
if ( error )
return error ;
V_84 = F_93 ( V_10 ) ;
if ( F_22 ( V_84 ) ) {
error = F_23 ( V_84 ) ;
goto V_281;
}
error = F_89 ( V_84 , V_10 , & V_208 ) ;
if ( error ) {
F_43 ( V_84 , 0 ) ;
goto V_281;
}
error = F_47 ( V_84 , 0 ) ;
V_281:
F_50 ( V_58 ) ;
return error ;
}
STATIC int
F_115 ( void * * V_282 , struct V_283 * V_284 , int * V_285 )
{
struct V_286 V_14 * V_287 = (struct V_286 V_14 * ) * V_282 ;
if ( F_10 ( V_287 , V_284 , sizeof( struct V_286 ) ) )
return - V_37 ;
* V_282 += sizeof( struct V_286 ) ;
return 0 ;
}
STATIC int
F_116 (
struct V_9 * V_10 ,
int V_138 ,
unsigned int V_1 ,
void V_14 * V_92 )
{
struct V_283 V_288 ;
int error ;
if ( F_16 ( & V_288 , V_92 , sizeof( struct V_283 ) ) )
return - V_37 ;
if ( V_288 . V_289 < 2 )
return - V_17 ;
V_288 . V_290 = ( V_1 == V_291 ? V_292 : 0 ) ;
if ( V_138 & V_150 )
V_288 . V_290 |= V_293 ;
error = F_117 ( V_10 , & V_288 , F_115 ,
( V_294 struct V_286 * ) V_92 + 1 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_288 , sizeof( struct V_286 ) ) )
return - V_37 ;
return 0 ;
}
STATIC int
F_118 ( void * * V_282 , struct V_283 * V_284 , int * V_285 )
{
struct V_283 V_14 * V_287 = (struct V_283 V_14 * ) * V_282 ;
if ( F_10 ( V_287 , V_284 , sizeof( struct V_283 ) ) )
return - V_37 ;
* V_282 += sizeof( struct V_283 ) ;
return 0 ;
}
STATIC int
F_119 (
struct V_9 * V_10 ,
void V_14 * V_92 )
{
struct V_283 V_288 ;
int error ;
if ( F_16 ( & V_288 , V_92 , sizeof( V_288 ) ) )
return - V_37 ;
if ( V_288 . V_289 < 2 )
return - V_17 ;
if ( V_288 . V_290 & ( ~ V_295 ) )
return - V_17 ;
error = F_117 ( V_10 , & V_288 , F_118 ,
( V_294 struct V_283 * ) V_92 + 1 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_288 , sizeof( struct V_283 ) ) )
return - V_37 ;
return 0 ;
}
int
F_120 (
T_25 * V_296 )
{
T_6 * V_10 , * V_297 ;
struct V_6 V_7 , V_298 ;
int error = 0 ;
V_7 = F_2 ( ( int ) V_296 -> V_299 ) ;
if ( ! V_7 . V_12 ) {
error = - V_17 ;
goto V_97;
}
if ( ! ( V_7 . V_12 -> V_73 & V_68 ) ||
! ( V_7 . V_12 -> V_73 & V_300 ) ||
( V_7 . V_12 -> V_71 & V_66 ) ) {
error = - V_13 ;
goto V_301;
}
V_298 = F_2 ( ( int ) V_296 -> V_302 ) ;
if ( ! V_298 . V_12 ) {
error = - V_17 ;
goto V_301;
}
if ( ! ( V_298 . V_12 -> V_73 & V_68 ) ||
! ( V_298 . V_12 -> V_73 & V_300 ) ||
( V_298 . V_12 -> V_71 & V_66 ) ) {
error = - V_13 ;
goto V_303;
}
if ( F_121 ( F_3 ( V_7 . V_12 ) ) ||
F_121 ( F_3 ( V_298 . V_12 ) ) ) {
error = - V_17 ;
goto V_303;
}
V_10 = F_5 ( F_3 ( V_7 . V_12 ) ) ;
V_297 = F_5 ( F_3 ( V_298 . V_12 ) ) ;
if ( V_10 -> V_24 != V_297 -> V_24 ) {
error = - V_17 ;
goto V_303;
}
if ( V_10 -> V_36 == V_297 -> V_36 ) {
error = - V_17 ;
goto V_303;
}
if ( F_39 ( V_10 -> V_24 ) ) {
error = - V_85 ;
goto V_303;
}
error = F_122 ( V_10 , V_297 , V_296 ) ;
V_303:
F_11 ( V_298 ) ;
V_301:
F_11 ( V_7 ) ;
V_97:
return error ;
}
long
F_123 (
struct V_12 * V_58 ,
unsigned int V_1 ,
unsigned long V_304 )
{
struct V_5 * V_5 = F_3 ( V_58 ) ;
struct V_9 * V_10 = F_5 ( V_5 ) ;
struct V_245 * V_83 = V_10 -> V_24 ;
void V_14 * V_92 = ( void V_14 * ) V_304 ;
int V_138 = 0 ;
int error ;
if ( V_58 -> V_73 & V_74 )
V_138 |= V_150 ;
F_124 ( V_10 ) ;
switch ( V_1 ) {
case V_305 :
return F_125 ( V_83 , V_92 ) ;
case V_165 :
case V_167 :
case V_157 :
case V_159 :
case V_166 :
case V_168 :
case V_158 :
case V_160 :
case V_156 : {
T_17 V_139 ;
if ( F_16 ( & V_139 , V_92 , sizeof( V_139 ) ) )
return - V_37 ;
return F_64 ( V_10 , V_5 , V_58 , V_138 , V_1 , & V_139 ) ;
}
case V_306 : {
struct V_307 V_308 ;
T_26 * V_309 =
F_90 ( V_10 ) ?
V_83 -> V_310 : V_83 -> V_311 ;
V_308 . V_312 = V_308 . V_313 = V_309 -> V_314 ;
V_308 . V_315 = V_123 & ~ ( V_308 . V_313 - 1 ) ;
if ( F_10 ( V_92 , & V_308 , sizeof( V_308 ) ) )
return - V_37 ;
return 0 ;
}
case V_183 :
case V_316 :
case V_181 :
return F_74 ( V_83 , V_1 , V_92 ) ;
case V_317 :
return F_78 ( V_83 , V_92 ) ;
case V_318 :
return F_80 ( V_83 , V_92 ) ;
case V_319 :
return F_126 ( V_5 -> V_320 , ( int V_14 * ) V_92 ) ;
case V_321 :
return F_83 ( V_10 , 0 , V_92 ) ;
case V_322 :
return F_83 ( V_10 , 1 , V_92 ) ;
case V_323 :
return F_112 ( V_10 , V_58 , V_92 ) ;
case V_324 :
return F_113 ( V_10 , V_92 ) ;
case V_325 :
return F_114 ( V_10 , V_58 , V_92 ) ;
case V_326 : {
struct V_93 V_327 ;
if ( F_16 ( & V_327 , V_92 , sizeof( V_327 ) ) )
return - V_37 ;
error = F_49 ( V_58 ) ;
if ( error )
return error ;
error = F_38 ( V_10 , V_327 . V_99 ,
V_327 . V_100 ) ;
F_50 ( V_58 ) ;
return error ;
}
case V_328 :
case V_291 :
return F_116 ( V_10 , V_138 , V_1 , V_92 ) ;
case V_329 :
return F_119 ( V_10 , V_92 ) ;
case V_11 :
case V_330 :
case V_27 : {
T_1 V_2 ;
if ( F_16 ( & V_2 , V_92 , sizeof( V_2 ) ) )
return - V_37 ;
return F_1 ( V_1 , & V_2 ) ;
}
case V_331 : {
T_1 V_2 ;
if ( F_16 ( & V_2 , V_92 , sizeof( T_1 ) ) )
return - V_37 ;
return F_19 ( V_58 , & V_2 ) ;
}
case V_332 :
return F_48 ( V_58 , V_92 ) ;
case V_333 : {
T_1 V_2 ;
if ( F_16 ( & V_2 , V_92 , sizeof( T_1 ) ) )
return - V_37 ;
return F_32 ( V_58 , & V_2 ) ;
}
case V_334 :
return F_51 ( V_58 , V_92 ) ;
case V_335 :
return F_62 ( V_58 , V_92 ) ;
case V_336 : {
struct V_337 V_296 ;
if ( F_16 ( & V_296 , V_92 , sizeof( T_25 ) ) )
return - V_37 ;
error = F_49 ( V_58 ) ;
if ( error )
return error ;
error = F_120 ( & V_296 ) ;
F_50 ( V_58 ) ;
return error ;
}
case V_338 : {
T_27 V_97 ;
error = F_127 ( V_83 , & V_97 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_97 , sizeof( V_97 ) ) )
return - V_37 ;
return 0 ;
}
case V_339 : {
T_28 V_340 ;
T_29 V_341 ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( V_83 -> V_252 & V_253 )
return - V_254 ;
if ( F_16 ( & V_340 , V_92 , sizeof( V_340 ) ) )
return - V_37 ;
error = F_49 ( V_58 ) ;
if ( error )
return error ;
V_341 = V_340 . V_342 ;
error = F_128 ( V_83 , & V_341 , & V_340 ) ;
F_50 ( V_58 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_340 , sizeof( V_340 ) ) )
return - V_37 ;
return 0 ;
}
case V_343 : {
T_28 V_97 ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
error = F_128 ( V_83 , NULL , & V_97 ) ;
if ( error )
return error ;
if ( F_10 ( V_92 , & V_97 , sizeof( V_97 ) ) )
return - V_37 ;
return 0 ;
}
case V_344 : {
T_30 V_341 ;
if ( F_16 ( & V_341 , V_92 , sizeof( V_341 ) ) )
return - V_37 ;
error = F_49 ( V_58 ) ;
if ( error )
return error ;
error = F_129 ( V_83 , & V_341 ) ;
F_50 ( V_58 ) ;
return error ;
}
case V_345 : {
T_31 V_341 ;
if ( F_16 ( & V_341 , V_92 , sizeof( V_341 ) ) )
return - V_37 ;
error = F_49 ( V_58 ) ;
if ( error )
return error ;
error = F_130 ( V_83 , & V_341 ) ;
F_50 ( V_58 ) ;
return error ;
}
case V_346 : {
T_32 V_341 ;
if ( F_16 ( & V_341 , V_92 , sizeof( V_341 ) ) )
return - V_37 ;
error = F_49 ( V_58 ) ;
if ( error )
return error ;
error = F_131 ( V_83 , & V_341 ) ;
F_50 ( V_58 ) ;
return error ;
}
case V_347 : {
T_14 V_341 ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( F_132 ( V_341 , ( T_14 V_14 * ) V_92 ) )
return - V_37 ;
return F_133 ( V_83 , V_341 ) ;
}
case V_348 : {
T_33 V_341 ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( F_16 ( & V_341 , V_92 , sizeof( V_341 ) ) )
return - V_37 ;
return F_134 ( V_341 . V_349 , V_83 ) ;
}
case V_350 :
if ( ! F_21 ( V_60 ) )
return - V_61 ;
return F_135 ( V_83 , 1 ) ;
case V_351 : {
struct V_352 V_353 ;
struct V_354 V_355 ;
if ( ! F_21 ( V_60 ) )
return - V_61 ;
if ( V_83 -> V_252 & V_253 )
return - V_254 ;
if ( F_16 ( & V_353 , V_92 , sizeof( V_353 ) ) )
return - V_37 ;
error = F_136 ( & V_353 , & V_355 ) ;
if ( error )
return error ;
return F_137 ( V_83 , & V_355 ) ;
}
default:
return - V_356 ;
}
}
