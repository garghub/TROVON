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
V_4 . V_27 . V_31 = V_10 -> V_32 . V_33 ;
V_4 . V_27 . V_34 = V_10 -> V_35 ;
V_3 = F_10 ( V_4 ) ;
}
error = - V_36 ;
if ( F_11 ( V_2 -> V_37 , & V_4 , V_3 ) ||
F_11 ( V_2 -> V_38 , & V_3 , sizeof( V_39 ) ) )
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
void * V_40 ,
struct V_15 * V_15 )
{
return 1 ;
}
struct V_15 *
F_15 (
struct V_12 * V_41 ,
void V_14 * V_42 ,
T_3 V_43 )
{
T_2 V_4 ;
struct V_44 V_45 ;
if ( ! F_8 ( F_3 ( V_41 ) -> V_21 ) )
return F_16 ( - V_46 ) ;
if ( V_43 != sizeof( T_2 ) )
return F_16 ( - V_16 ) ;
if ( F_17 ( & V_4 , V_42 , V_43 ) )
return F_16 ( - V_36 ) ;
if ( V_4 . V_27 . V_28 !=
sizeof( V_4 . V_27 ) - sizeof( V_4 . V_27 . V_28 ) )
return F_16 ( - V_16 ) ;
memset ( & V_45 , 0 , sizeof( struct V_45 ) ) ;
V_45 . V_47 = V_4 . V_27 . V_34 ;
V_45 . V_48 = V_4 . V_27 . V_31 ;
return F_18 ( V_41 -> V_49 . V_50 , (struct V_45 * ) & V_45 , 3 ,
V_51 | V_52 ,
F_14 , NULL ) ;
}
STATIC struct V_15 *
F_19 (
struct V_12 * V_41 ,
T_1 * V_2 )
{
return F_15 ( V_41 , V_2 -> V_53 , V_2 -> V_54 ) ;
}
int
F_20 (
struct V_12 * V_41 ,
T_1 * V_2 )
{
const struct V_55 * V_55 = F_21 () ;
int error ;
int V_6 ;
int V_56 ;
struct V_12 * V_57 ;
struct V_5 * V_5 ;
struct V_15 * V_15 ;
T_4 V_58 ;
struct V_8 V_8 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
V_15 = F_19 ( V_41 , V_2 ) ;
if ( F_23 ( V_15 ) )
return F_24 ( V_15 ) ;
V_5 = F_5 ( V_15 ) ;
if ( ! ( F_7 ( V_5 -> V_21 ) || F_8 ( V_5 -> V_21 ) ) ) {
error = - V_60 ;
goto V_61;
}
#if V_62 != 32
V_2 -> V_63 |= V_64 ;
#endif
V_56 = V_2 -> V_63 ;
V_58 = F_25 ( V_56 ) ;
if ( ( ! ( V_56 & V_65 ) || ( V_56 & V_66 ) ) &&
( V_58 & V_67 ) && F_26 ( V_5 ) ) {
error = - V_60 ;
goto V_61;
}
if ( ( V_58 & V_67 ) && F_27 ( V_5 ) ) {
error = - V_68 ;
goto V_61;
}
if ( F_8 ( V_5 -> V_21 ) && ( V_58 & V_67 ) ) {
error = - V_69 ;
goto V_61;
}
V_6 = F_28 ( 0 ) ;
if ( V_6 < 0 ) {
error = V_6 ;
goto V_61;
}
V_8 . V_50 = V_41 -> V_49 . V_50 ;
V_8 . V_15 = V_15 ;
V_57 = F_29 ( & V_8 , V_2 -> V_63 , V_55 ) ;
F_30 ( V_15 ) ;
if ( F_23 ( V_57 ) ) {
F_31 ( V_6 ) ;
return F_24 ( V_57 ) ;
}
if ( F_7 ( V_5 -> V_21 ) ) {
V_57 -> V_70 |= V_71 ;
V_57 -> V_72 |= V_73 ;
}
F_32 ( V_6 , V_57 ) ;
return V_6 ;
V_61:
F_30 ( V_15 ) ;
return error ;
}
int
F_33 (
struct V_12 * V_41 ,
T_1 * V_2 )
{
struct V_15 * V_15 ;
T_5 V_74 ;
void * V_75 ;
int error ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
V_15 = F_19 ( V_41 , V_2 ) ;
if ( F_23 ( V_15 ) )
return F_24 ( V_15 ) ;
if ( ! F_34 ( V_15 ) ) {
error = - V_16 ;
goto V_61;
}
if ( F_17 ( & V_74 , V_2 -> V_38 , sizeof( T_5 ) ) ) {
error = - V_36 ;
goto V_61;
}
V_75 = F_35 ( V_76 + 1 , V_77 ) ;
if ( ! V_75 ) {
error = - V_78 ;
goto V_61;
}
error = F_36 ( F_6 ( F_5 ( V_15 ) ) , V_75 ) ;
if ( error )
goto V_79;
error = F_37 ( V_2 -> V_37 , V_74 , V_75 ) ;
if ( error )
goto V_79;
V_79:
F_38 ( V_75 ) ;
V_61:
F_30 ( V_15 ) ;
return error ;
}
int
F_39 (
T_6 * V_10 ,
T_7 V_80 ,
T_8 V_81 )
{
T_9 * V_82 = V_10 -> V_23 ;
T_10 * V_83 ;
int error ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( F_40 ( V_82 ) )
return - V_84 ;
V_83 = F_41 ( V_82 , V_85 ) ;
error = F_42 ( V_83 , & F_43 ( V_82 ) -> V_86 , 0 , 0 ) ;
if ( error ) {
F_44 ( V_83 , 0 ) ;
return error ;
}
F_45 ( V_10 , V_87 ) ;
F_46 ( V_83 , V_10 , V_87 ) ;
V_10 -> V_32 . V_88 = V_80 ;
V_10 -> V_32 . V_89 = V_81 ;
F_47 ( V_83 , V_10 , V_90 ) ;
error = F_48 ( V_83 , 0 ) ;
return error ;
}
STATIC int
F_49 (
struct V_12 * V_41 ,
void V_14 * V_91 )
{
int error ;
struct V_92 V_93 ;
T_11 V_94 ;
struct V_15 * V_15 ;
if ( ! F_22 ( V_95 ) )
return - V_60 ;
if ( F_17 ( & V_94 , V_91 , sizeof( T_11 ) ) )
return - V_36 ;
error = F_50 ( V_41 ) ;
if ( error )
return error ;
V_15 = F_19 ( V_41 , & V_94 . V_2 ) ;
if ( F_23 ( V_15 ) ) {
F_51 ( V_41 ) ;
return F_24 ( V_15 ) ;
}
if ( F_27 ( F_5 ( V_15 ) ) || F_26 ( F_5 ( V_15 ) ) ) {
error = - V_60 ;
goto V_96;
}
if ( F_17 ( & V_93 , V_94 . V_97 , sizeof( V_93 ) ) ) {
error = - V_36 ;
goto V_96;
}
error = F_39 ( F_6 ( F_5 ( V_15 ) ) , V_93 . V_98 ,
V_93 . V_99 ) ;
V_96:
F_51 ( V_41 ) ;
F_30 ( V_15 ) ;
return error ;
}
STATIC int
F_52 (
struct V_12 * V_41 ,
void V_14 * V_91 )
{
int error = - V_78 ;
T_12 * V_100 ;
T_13 V_101 ;
struct V_15 * V_15 ;
char * V_102 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( F_17 ( & V_101 , V_91 , sizeof( T_13 ) ) )
return - V_36 ;
if ( V_101 . V_103 < sizeof( struct V_104 ) ||
V_101 . V_103 > V_105 )
return - V_16 ;
if ( V_101 . V_106 & ~ ( V_107 | V_108 ) )
return - V_16 ;
V_15 = F_19 ( V_41 , & V_101 . V_2 ) ;
if ( F_23 ( V_15 ) )
return F_24 ( V_15 ) ;
V_102 = F_53 ( V_101 . V_103 , V_109 ) ;
if ( ! V_102 )
goto V_61;
V_100 = ( T_12 * ) & V_101 . V_110 ;
error = F_54 ( F_6 ( F_5 ( V_15 ) ) , V_102 , V_101 . V_103 ,
V_101 . V_106 , V_100 ) ;
if ( error )
goto V_79;
if ( F_11 ( V_101 . V_111 , V_102 , V_101 . V_103 ) )
error = - V_36 ;
V_79:
F_55 ( V_102 ) ;
V_61:
F_30 ( V_15 ) ;
return error ;
}
int
F_56 (
struct V_5 * V_5 ,
unsigned char * V_112 ,
unsigned char V_14 * V_113 ,
T_14 * V_114 ,
T_14 V_106 )
{
unsigned char * V_102 ;
int error = - V_36 ;
if ( * V_114 > V_115 )
return - V_16 ;
V_102 = F_53 ( * V_114 , V_109 ) ;
if ( ! V_102 )
return - V_78 ;
error = F_57 ( F_6 ( V_5 ) , V_112 , V_102 , ( int * ) V_114 , V_106 ) ;
if ( error )
goto V_79;
if ( F_11 ( V_113 , V_102 , * V_114 ) )
error = - V_36 ;
V_79:
F_55 ( V_102 ) ;
return error ;
}
int
F_58 (
struct V_5 * V_5 ,
unsigned char * V_112 ,
const unsigned char V_14 * V_113 ,
T_14 V_114 ,
T_14 V_106 )
{
unsigned char * V_102 ;
if ( F_27 ( V_5 ) || F_26 ( V_5 ) )
return - V_60 ;
if ( V_114 > V_115 )
return - V_16 ;
V_102 = F_59 ( V_113 , V_114 ) ;
if ( F_23 ( V_102 ) )
return F_24 ( V_102 ) ;
return F_60 ( F_6 ( V_5 ) , V_112 , V_102 , V_114 , V_106 ) ;
}
int
F_61 (
struct V_5 * V_5 ,
unsigned char * V_112 ,
T_14 V_106 )
{
if ( F_27 ( V_5 ) || F_26 ( V_5 ) )
return - V_60 ;
return F_62 ( F_6 ( V_5 ) , V_112 , V_106 ) ;
}
STATIC int
F_63 (
struct V_12 * V_41 ,
void V_14 * V_91 )
{
int error ;
T_15 * V_116 ;
T_16 V_117 ;
struct V_15 * V_15 ;
unsigned int V_118 , V_119 ;
unsigned char * V_120 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( F_17 ( & V_117 , V_91 , sizeof( T_16 ) ) )
return - V_36 ;
if ( V_117 . V_121 >= V_122 / sizeof( T_15 ) )
return - V_123 ;
V_15 = F_19 ( V_41 , & V_117 . V_2 ) ;
if ( F_23 ( V_15 ) )
return F_24 ( V_15 ) ;
error = - V_123 ;
V_119 = V_117 . V_121 * sizeof( T_15 ) ;
if ( ! V_119 || V_119 > 16 * V_124 )
goto V_61;
V_116 = F_59 ( V_117 . V_116 , V_119 ) ;
if ( F_23 ( V_116 ) ) {
error = F_24 ( V_116 ) ;
goto V_61;
}
error = - V_78 ;
V_120 = F_35 ( V_125 , V_77 ) ;
if ( ! V_120 )
goto V_126;
error = 0 ;
for ( V_118 = 0 ; V_118 < V_117 . V_121 ; V_118 ++ ) {
V_116 [ V_118 ] . V_127 = F_64 ( ( char * ) V_120 ,
V_116 [ V_118 ] . V_128 , V_125 ) ;
if ( V_116 [ V_118 ] . V_127 == 0 || V_116 [ V_118 ] . V_127 == V_125 )
error = - V_129 ;
if ( V_116 [ V_118 ] . V_127 < 0 )
break;
switch ( V_116 [ V_118 ] . V_130 ) {
case V_131 :
V_116 [ V_118 ] . V_127 = F_56 (
F_5 ( V_15 ) , V_120 ,
V_116 [ V_118 ] . V_132 , & V_116 [ V_118 ] . V_133 ,
V_116 [ V_118 ] . V_134 ) ;
break;
case V_135 :
V_116 [ V_118 ] . V_127 = F_50 ( V_41 ) ;
if ( V_116 [ V_118 ] . V_127 )
break;
V_116 [ V_118 ] . V_127 = F_58 (
F_5 ( V_15 ) , V_120 ,
V_116 [ V_118 ] . V_132 , V_116 [ V_118 ] . V_133 ,
V_116 [ V_118 ] . V_134 ) ;
F_51 ( V_41 ) ;
break;
case V_136 :
V_116 [ V_118 ] . V_127 = F_50 ( V_41 ) ;
if ( V_116 [ V_118 ] . V_127 )
break;
V_116 [ V_118 ] . V_127 = F_61 (
F_5 ( V_15 ) , V_120 ,
V_116 [ V_118 ] . V_134 ) ;
F_51 ( V_41 ) ;
break;
default:
V_116 [ V_118 ] . V_127 = - V_16 ;
}
}
if ( F_11 ( V_117 . V_116 , V_116 , V_119 ) )
error = - V_36 ;
F_38 ( V_120 ) ;
V_126:
F_38 ( V_116 ) ;
V_61:
F_30 ( V_15 ) ;
return error ;
}
int
F_65 (
struct V_9 * V_10 ,
struct V_5 * V_5 ,
struct V_12 * V_57 ,
int V_137 ,
unsigned int V_1 ,
T_17 * V_138 )
{
struct V_139 V_139 ;
enum V_140 V_106 = 0 ;
T_18 V_141 = V_142 ;
int error ;
if ( ! F_66 ( & V_10 -> V_23 -> V_143 ) &&
! F_22 ( V_59 ) )
return - V_60 ;
if ( V_5 -> V_144 & ( V_145 | V_146 ) )
return - V_60 ;
if ( ! ( V_57 -> V_72 & V_67 ) )
return - V_13 ;
if ( ! F_7 ( V_5 -> V_21 ) )
return - V_16 ;
if ( V_57 -> V_70 & V_147 )
V_106 |= V_148 ;
if ( V_137 & V_149 )
V_106 |= V_150 ;
error = F_50 ( V_57 ) ;
if ( error )
return error ;
F_45 ( V_10 , V_141 ) ;
error = F_67 ( V_5 , & V_141 , false ) ;
if ( error )
goto V_151;
F_45 ( V_10 , V_152 ) ;
V_141 |= V_152 ;
switch ( V_138 -> V_153 ) {
case 0 :
break;
case 1 :
V_138 -> V_154 += V_57 -> V_155 ;
break;
case 2 :
V_138 -> V_154 += F_68 ( V_10 ) ;
break;
default:
error = - V_16 ;
goto V_151;
}
switch ( V_1 ) {
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
if ( V_138 -> V_161 <= 0 ) {
error = - V_16 ;
goto V_151;
}
break;
default:
V_138 -> V_161 = 0 ;
break;
}
if ( V_138 -> V_154 < 0 ||
V_138 -> V_154 > V_5 -> V_17 -> V_162 ||
V_138 -> V_154 + V_138 -> V_161 < 0 ||
V_138 -> V_154 + V_138 -> V_161 >= V_5 -> V_17 -> V_162 ) {
error = - V_16 ;
goto V_151;
}
switch ( V_1 ) {
case V_156 :
V_106 |= V_163 ;
error = F_69 ( V_10 , V_138 -> V_154 , V_138 -> V_161 ) ;
break;
case V_157 :
case V_158 :
V_106 |= V_163 ;
error = F_70 ( V_10 , V_138 -> V_154 , V_138 -> V_161 ,
V_164 ) ;
break;
case V_159 :
case V_160 :
error = F_71 ( V_10 , V_138 -> V_154 , V_138 -> V_161 ) ;
break;
case V_165 :
case V_166 :
case V_167 :
case V_168 :
V_106 |= V_169 ;
if ( V_138 -> V_154 > F_68 ( V_10 ) ) {
error = F_70 ( V_10 , F_68 ( V_10 ) ,
V_138 -> V_154 - F_68 ( V_10 ) , 0 ) ;
if ( error )
goto V_151;
}
V_139 . V_170 = V_171 ;
V_139 . V_172 = V_138 -> V_154 ;
error = F_72 ( V_10 , & V_139 ) ;
break;
default:
ASSERT ( 0 ) ;
error = - V_16 ;
}
if ( error )
goto V_151;
error = F_73 ( V_10 , V_106 ) ;
V_151:
F_74 ( V_10 , V_141 ) ;
F_51 ( V_57 ) ;
return error ;
}
STATIC int
F_75 (
T_9 * V_82 ,
unsigned int V_1 ,
void V_14 * V_91 )
{
T_19 V_173 ;
int V_174 ;
T_20 V_175 ;
int V_176 ;
int error ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( F_40 ( V_82 ) )
return - V_84 ;
if ( F_17 ( & V_173 , V_91 , sizeof( T_19 ) ) )
return - V_36 ;
if ( F_17 ( & V_175 , V_173 . V_177 , sizeof( V_178 ) ) )
return - V_36 ;
if ( ( V_174 = V_173 . V_179 ) <= 0 )
return - V_16 ;
if ( V_173 . V_180 == NULL )
return - V_16 ;
if ( V_1 == V_181 )
error = F_76 ( V_82 , & V_175 , & V_174 ,
V_173 . V_180 , V_182 ) ;
else if ( V_1 == V_183 )
error = F_77 ( V_82 , V_175 , V_173 . V_180 ,
sizeof( V_184 ) , NULL , & V_176 ) ;
else
error = F_78 ( V_82 , & V_175 , & V_174 , F_77 ,
sizeof( V_184 ) , V_173 . V_180 ,
& V_176 ) ;
if ( error )
return error ;
if ( V_173 . V_185 != NULL ) {
if ( F_11 ( V_173 . V_177 , & V_175 ,
sizeof( T_20 ) ) )
return - V_36 ;
if ( F_11 ( V_173 . V_185 , & V_174 , sizeof( V_174 ) ) )
return - V_36 ;
}
return 0 ;
}
STATIC int
F_79 (
T_9 * V_82 ,
void V_14 * V_91 )
{
T_21 V_186 ;
int error ;
error = F_80 ( V_82 , & V_186 , 3 ) ;
if ( error )
return error ;
if ( F_11 ( V_91 , & V_186 , sizeof( V_187 ) ) )
return - V_36 ;
return 0 ;
}
STATIC int
F_81 (
T_9 * V_82 ,
void V_14 * V_91 )
{
T_21 V_186 ;
int error ;
error = F_80 ( V_82 , & V_186 , 4 ) ;
if ( error )
return error ;
if ( F_11 ( V_91 , & V_186 , sizeof( V_186 ) ) )
return - V_36 ;
return 0 ;
}
STATIC unsigned int
F_82 (
unsigned int V_106 ,
unsigned int V_188 )
{
unsigned int V_189 = V_188 ;
if ( V_106 & V_190 )
V_189 |= V_191 ;
else
V_189 &= ~ V_191 ;
if ( V_106 & V_192 )
V_189 |= V_193 ;
else
V_189 &= ~ V_193 ;
if ( V_106 & V_194 )
V_189 |= V_195 ;
else
V_189 &= ~ V_195 ;
if ( V_106 & V_196 )
V_189 |= V_197 ;
else
V_189 &= ~ V_197 ;
if ( V_106 & V_198 )
V_189 |= V_199 ;
else
V_189 &= ~ V_199 ;
return V_189 ;
}
STATIC unsigned int
F_83 (
T_22 V_200 )
{
unsigned int V_106 = 0 ;
if ( V_200 & V_201 )
V_106 |= V_190 ;
if ( V_200 & V_202 )
V_106 |= V_192 ;
if ( V_200 & V_203 )
V_106 |= V_194 ;
if ( V_200 & V_204 )
V_106 |= V_196 ;
if ( V_200 & V_205 )
V_106 |= V_198 ;
return V_106 ;
}
STATIC int
F_84 (
T_6 * V_10 ,
int V_206 ,
void V_14 * V_91 )
{
struct V_207 V_208 ;
memset ( & V_208 , 0 , sizeof( struct V_207 ) ) ;
F_45 ( V_10 , V_209 ) ;
V_208 . V_210 = F_85 ( V_10 ) ;
V_208 . V_211 = V_10 -> V_32 . V_212 << V_10 -> V_23 -> V_143 . V_213 ;
V_208 . V_214 = F_86 ( V_10 ) ;
if ( V_206 ) {
if ( V_10 -> V_215 ) {
if ( V_10 -> V_215 -> V_216 & V_217 )
V_208 . V_218 = V_10 -> V_215 -> V_219 /
sizeof( V_220 ) ;
else
V_208 . V_218 = V_10 -> V_32 . V_221 ;
} else
V_208 . V_218 = 0 ;
} else {
if ( V_10 -> V_222 . V_216 & V_217 )
V_208 . V_218 = V_10 -> V_222 . V_219 /
sizeof( V_220 ) ;
else
V_208 . V_218 = V_10 -> V_32 . V_223 ;
}
F_74 ( V_10 , V_209 ) ;
if ( F_11 ( V_91 , & V_208 , sizeof( V_208 ) ) )
return - V_36 ;
return 0 ;
}
STATIC void
F_87 (
struct V_9 * V_10 ,
unsigned int V_189 )
{
unsigned int V_200 ;
V_200 = ( V_10 -> V_32 . V_200 & V_224 ) ;
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
if ( F_8 ( V_10 -> V_32 . V_229 ) ) {
if ( V_189 & V_230 )
V_200 |= V_231 ;
if ( V_189 & V_232 )
V_200 |= V_233 ;
if ( V_189 & V_234 )
V_200 |= V_235 ;
if ( V_189 & V_236 )
V_200 |= V_237 ;
} else if ( F_7 ( V_10 -> V_32 . V_229 ) ) {
if ( V_189 & V_238 )
V_200 |= V_239 ;
if ( V_189 & V_240 )
V_200 |= V_241 ;
}
V_10 -> V_32 . V_200 = V_200 ;
}
STATIC void
F_88 (
struct V_9 * V_10 )
{
struct V_5 * V_5 = F_89 ( V_10 ) ;
unsigned int V_189 = F_85 ( V_10 ) ;
if ( V_189 & V_191 )
V_5 -> V_144 |= V_145 ;
else
V_5 -> V_144 &= ~ V_145 ;
if ( V_189 & V_193 )
V_5 -> V_144 |= V_146 ;
else
V_5 -> V_144 &= ~ V_146 ;
if ( V_189 & V_195 )
V_5 -> V_144 |= V_242 ;
else
V_5 -> V_144 &= ~ V_242 ;
if ( V_189 & V_197 )
V_5 -> V_144 |= V_243 ;
else
V_5 -> V_144 &= ~ V_243 ;
}
static int
F_90 (
struct V_244 * V_83 ,
struct V_9 * V_10 ,
struct V_207 * V_208 )
{
struct V_245 * V_82 = V_10 -> V_23 ;
if ( ( V_10 -> V_32 . V_223 || V_10 -> V_246 ) &&
F_91 ( V_10 ) != ( V_208 -> V_210 & V_238 ) )
return - V_16 ;
if ( V_208 -> V_210 & V_238 ) {
if ( V_82 -> V_143 . V_247 == 0 || V_82 -> V_143 . V_248 == 0 ||
( V_10 -> V_32 . V_212 % V_82 -> V_143 . V_248 ) )
return - V_16 ;
}
if ( ( ( V_10 -> V_32 . V_200 & ( V_201 | V_202 ) ) ||
( V_208 -> V_210 & ( V_191 | V_193 ) ) ) &&
! F_22 ( V_249 ) )
return - V_60 ;
F_87 ( V_10 , V_208 -> V_210 ) ;
F_88 ( V_10 ) ;
F_92 ( V_83 , V_10 , V_250 ) ;
F_47 ( V_83 , V_10 , V_90 ) ;
F_93 ( V_251 ) ;
return 0 ;
}
static struct V_244 *
F_94 (
struct V_9 * V_10 )
{
struct V_245 * V_82 = V_10 -> V_23 ;
struct V_244 * V_83 ;
int error ;
if ( V_82 -> V_252 & V_253 )
return F_16 ( - V_254 ) ;
if ( F_40 ( V_82 ) )
return F_16 ( - V_84 ) ;
V_83 = F_41 ( V_82 , V_255 ) ;
error = F_42 ( V_83 , & F_43 ( V_82 ) -> V_86 , 0 , 0 ) ;
if ( error )
goto V_256;
F_45 ( V_10 , V_87 ) ;
F_46 ( V_83 , V_10 , V_87 ) ;
if ( ! F_95 ( F_89 ( V_10 ) ) ) {
error = - V_60 ;
goto V_256;
}
if ( V_82 -> V_252 & V_257 )
F_96 ( V_83 ) ;
return V_83 ;
V_256:
F_44 ( V_83 , 0 ) ;
return F_16 ( error ) ;
}
static int
F_97 (
struct V_9 * V_10 ,
struct V_207 * V_208 )
{
struct V_245 * V_82 = V_10 -> V_23 ;
if ( ( V_208 -> V_210 & V_240 ) && ! F_7 ( V_10 -> V_32 . V_229 ) )
return - V_16 ;
if ( ( V_208 -> V_210 & V_234 ) &&
! F_8 ( V_10 -> V_32 . V_229 ) )
return - V_16 ;
if ( F_7 ( V_10 -> V_32 . V_229 ) && V_10 -> V_32 . V_223 &&
( ( V_10 -> V_32 . V_212 << V_82 -> V_143 . V_213 ) != V_208 -> V_211 ) )
return - V_16 ;
if ( V_208 -> V_211 != 0 ) {
T_23 V_119 ;
T_24 V_258 ;
V_258 = F_98 ( V_82 , V_208 -> V_211 ) ;
if ( V_258 > V_259 )
return - V_16 ;
if ( F_91 ( V_10 ) ||
( V_208 -> V_210 & V_238 ) ) {
V_119 = V_82 -> V_143 . V_248 << V_82 -> V_143 . V_213 ;
} else {
V_119 = V_82 -> V_143 . V_260 ;
if ( V_258 > V_82 -> V_143 . V_261 / 2 )
return - V_16 ;
}
if ( V_208 -> V_211 % V_119 )
return - V_16 ;
} else
V_208 -> V_210 &= ~ ( V_240 | V_234 ) ;
return 0 ;
}
static int
F_99 (
struct V_9 * V_10 ,
struct V_207 * V_208 )
{
if ( V_208 -> V_214 > ( T_22 ) - 1 &&
! F_100 ( & V_10 -> V_23 -> V_143 ) )
return - V_16 ;
if ( F_101 () == & V_262 )
return 0 ;
if ( F_86 ( V_10 ) != V_208 -> V_214 )
return - V_16 ;
if ( ( V_208 -> V_210 & V_236 ) !=
( V_10 -> V_32 . V_200 & V_237 ) )
return - V_16 ;
return 0 ;
}
STATIC int
F_102 (
T_6 * V_10 ,
struct V_207 * V_208 )
{
struct V_245 * V_82 = V_10 -> V_23 ;
struct V_244 * V_83 ;
struct V_263 * V_264 = NULL ;
struct V_263 * V_265 = NULL ;
struct V_263 * V_266 = NULL ;
int V_267 ;
F_103 ( V_10 ) ;
V_267 = F_99 ( V_10 , V_208 ) ;
if ( V_267 )
return V_267 ;
if ( F_104 ( V_82 ) ) {
V_267 = F_105 ( V_10 , V_10 -> V_32 . V_268 ,
V_10 -> V_32 . V_269 , V_208 -> V_214 ,
V_270 , & V_264 , NULL , & V_265 ) ;
if ( V_267 )
return V_267 ;
}
V_83 = F_94 ( V_10 ) ;
if ( F_23 ( V_83 ) ) {
V_267 = F_24 ( V_83 ) ;
goto V_271;
}
if ( F_106 ( V_82 ) && F_107 ( V_82 ) &&
F_86 ( V_10 ) != V_208 -> V_214 ) {
V_267 = F_108 ( V_83 , V_10 , V_264 , NULL , V_265 ,
F_22 ( V_272 ) ? V_273 : 0 ) ;
if ( V_267 )
goto V_274;
}
V_267 = F_97 ( V_10 , V_208 ) ;
if ( V_267 )
goto V_274;
V_267 = F_90 ( V_83 , V_10 , V_208 ) ;
if ( V_267 )
goto V_274;
if ( ( V_10 -> V_32 . V_229 & ( V_275 | V_276 ) ) &&
! F_109 ( F_89 ( V_10 ) , V_277 ) )
V_10 -> V_32 . V_229 &= ~ ( V_275 | V_276 ) ;
if ( F_86 ( V_10 ) != V_208 -> V_214 ) {
if ( F_106 ( V_82 ) && F_107 ( V_82 ) ) {
V_266 = F_110 ( V_83 , V_10 ,
& V_10 -> V_278 , V_265 ) ;
}
ASSERT ( V_10 -> V_32 . V_279 > 1 ) ;
F_111 ( V_10 , V_208 -> V_214 ) ;
}
if ( V_10 -> V_32 . V_200 & ( V_241 | V_235 ) )
V_10 -> V_32 . V_212 = V_208 -> V_211 >> V_82 -> V_143 . V_213 ;
else
V_10 -> V_32 . V_212 = 0 ;
V_267 = F_48 ( V_83 , 0 ) ;
F_112 ( V_266 ) ;
F_112 ( V_264 ) ;
F_112 ( V_265 ) ;
return V_267 ;
V_274:
F_44 ( V_83 , 0 ) ;
V_271:
F_112 ( V_264 ) ;
F_112 ( V_265 ) ;
return V_267 ;
}
STATIC int
F_113 (
T_6 * V_10 ,
struct V_12 * V_57 ,
void V_14 * V_91 )
{
struct V_207 V_208 ;
int error ;
if ( F_17 ( & V_208 , V_91 , sizeof( V_208 ) ) )
return - V_36 ;
error = F_50 ( V_57 ) ;
if ( error )
return error ;
error = F_102 ( V_10 , & V_208 ) ;
F_51 ( V_57 ) ;
return error ;
}
STATIC int
F_114 (
T_6 * V_10 ,
void V_14 * V_91 )
{
unsigned int V_106 ;
V_106 = F_83 ( V_10 -> V_32 . V_200 ) ;
if ( F_11 ( V_91 , & V_106 , sizeof( V_106 ) ) )
return - V_36 ;
return 0 ;
}
STATIC int
F_115 (
struct V_9 * V_10 ,
struct V_12 * V_57 ,
void V_14 * V_91 )
{
struct V_244 * V_83 ;
struct V_207 V_208 ;
unsigned int V_106 ;
int error ;
if ( F_17 ( & V_106 , V_91 , sizeof( V_106 ) ) )
return - V_36 ;
if ( V_106 & ~ ( V_190 | V_192 | \
V_196 | V_198 | \
V_194 ) )
return - V_280 ;
V_208 . V_210 = F_82 ( V_106 , F_85 ( V_10 ) ) ;
error = F_50 ( V_57 ) ;
if ( error )
return error ;
V_83 = F_94 ( V_10 ) ;
if ( F_23 ( V_83 ) ) {
error = F_24 ( V_83 ) ;
goto V_281;
}
error = F_90 ( V_83 , V_10 , & V_208 ) ;
if ( error ) {
F_44 ( V_83 , 0 ) ;
goto V_281;
}
error = F_48 ( V_83 , 0 ) ;
V_281:
F_51 ( V_57 ) ;
return error ;
}
STATIC int
F_116 ( void * * V_282 , struct V_283 * V_284 , int * V_285 )
{
struct V_286 V_14 * V_287 = (struct V_286 V_14 * ) * V_282 ;
if ( F_11 ( V_287 , V_284 , sizeof( struct V_286 ) ) )
return - V_36 ;
* V_282 += sizeof( struct V_286 ) ;
return 0 ;
}
STATIC int
F_117 (
struct V_9 * V_10 ,
int V_137 ,
unsigned int V_1 ,
void V_14 * V_91 )
{
struct V_283 V_288 ;
int error ;
if ( F_17 ( & V_288 , V_91 , sizeof( struct V_283 ) ) )
return - V_36 ;
if ( V_288 . V_289 < 2 )
return - V_16 ;
V_288 . V_290 = ( V_1 == V_291 ? V_292 : 0 ) ;
if ( V_137 & V_149 )
V_288 . V_290 |= V_293 ;
error = F_118 ( V_10 , & V_288 , F_116 ,
( V_294 struct V_286 * ) V_91 + 1 ) ;
if ( error )
return error ;
if ( F_11 ( V_91 , & V_288 , sizeof( struct V_286 ) ) )
return - V_36 ;
return 0 ;
}
STATIC int
F_119 ( void * * V_282 , struct V_283 * V_284 , int * V_285 )
{
struct V_283 V_14 * V_287 = (struct V_283 V_14 * ) * V_282 ;
if ( F_11 ( V_287 , V_284 , sizeof( struct V_283 ) ) )
return - V_36 ;
* V_282 += sizeof( struct V_283 ) ;
return 0 ;
}
STATIC int
F_120 (
struct V_9 * V_10 ,
void V_14 * V_91 )
{
struct V_283 V_288 ;
int error ;
if ( F_17 ( & V_288 , V_91 , sizeof( V_288 ) ) )
return - V_36 ;
if ( V_288 . V_289 < 2 )
return - V_16 ;
if ( V_288 . V_290 & ( ~ V_295 ) )
return - V_16 ;
error = F_118 ( V_10 , & V_288 , F_119 ,
( V_294 struct V_283 * ) V_91 + 1 ) ;
if ( error )
return error ;
if ( F_11 ( V_91 , & V_288 , sizeof( struct V_283 ) ) )
return - V_36 ;
return 0 ;
}
int
F_121 (
T_25 * V_296 )
{
T_6 * V_10 , * V_297 ;
struct V_6 V_7 , V_298 ;
int error = 0 ;
V_7 = F_2 ( ( int ) V_296 -> V_299 ) ;
if ( ! V_7 . V_12 ) {
error = - V_16 ;
goto V_96;
}
if ( ! ( V_7 . V_12 -> V_72 & V_67 ) ||
! ( V_7 . V_12 -> V_72 & V_300 ) ||
( V_7 . V_12 -> V_70 & V_65 ) ) {
error = - V_13 ;
goto V_301;
}
V_298 = F_2 ( ( int ) V_296 -> V_302 ) ;
if ( ! V_298 . V_12 ) {
error = - V_16 ;
goto V_301;
}
if ( ! ( V_298 . V_12 -> V_72 & V_67 ) ||
! ( V_298 . V_12 -> V_72 & V_300 ) ||
( V_298 . V_12 -> V_70 & V_65 ) ) {
error = - V_13 ;
goto V_303;
}
if ( F_122 ( F_3 ( V_7 . V_12 ) ) ||
F_122 ( F_3 ( V_298 . V_12 ) ) ) {
error = - V_16 ;
goto V_303;
}
V_10 = F_6 ( F_3 ( V_7 . V_12 ) ) ;
V_297 = F_6 ( F_3 ( V_298 . V_12 ) ) ;
if ( V_10 -> V_23 != V_297 -> V_23 ) {
error = - V_16 ;
goto V_303;
}
if ( V_10 -> V_35 == V_297 -> V_35 ) {
error = - V_16 ;
goto V_303;
}
if ( F_40 ( V_10 -> V_23 ) ) {
error = - V_84 ;
goto V_303;
}
error = F_123 ( V_10 , V_297 , V_296 ) ;
V_303:
F_12 ( V_298 ) ;
V_301:
F_12 ( V_7 ) ;
V_96:
return error ;
}
long
F_124 (
struct V_12 * V_57 ,
unsigned int V_1 ,
unsigned long V_304 )
{
struct V_5 * V_5 = F_3 ( V_57 ) ;
struct V_9 * V_10 = F_6 ( V_5 ) ;
struct V_245 * V_82 = V_10 -> V_23 ;
void V_14 * V_91 = ( void V_14 * ) V_304 ;
int V_137 = 0 ;
int error ;
if ( V_57 -> V_72 & V_73 )
V_137 |= V_149 ;
F_125 ( V_10 ) ;
switch ( V_1 ) {
case V_305 :
return F_126 ( V_82 , V_91 ) ;
case V_165 :
case V_167 :
case V_157 :
case V_159 :
case V_166 :
case V_168 :
case V_158 :
case V_160 :
case V_156 : {
T_17 V_138 ;
if ( F_17 ( & V_138 , V_91 , sizeof( V_138 ) ) )
return - V_36 ;
return F_65 ( V_10 , V_5 , V_57 , V_137 , V_1 , & V_138 ) ;
}
case V_306 : {
struct V_307 V_308 ;
T_26 * V_309 =
F_91 ( V_10 ) ?
V_82 -> V_310 : V_82 -> V_311 ;
V_308 . V_312 = V_308 . V_313 = V_309 -> V_314 ;
V_308 . V_315 = V_122 & ~ ( V_308 . V_313 - 1 ) ;
if ( F_11 ( V_91 , & V_308 , sizeof( V_308 ) ) )
return - V_36 ;
return 0 ;
}
case V_183 :
case V_316 :
case V_181 :
return F_75 ( V_82 , V_1 , V_91 ) ;
case V_317 :
return F_79 ( V_82 , V_91 ) ;
case V_318 :
return F_81 ( V_82 , V_91 ) ;
case V_319 :
return F_127 ( V_5 -> V_320 , ( int V_14 * ) V_91 ) ;
case V_321 :
return F_84 ( V_10 , 0 , V_91 ) ;
case V_322 :
return F_84 ( V_10 , 1 , V_91 ) ;
case V_323 :
return F_113 ( V_10 , V_57 , V_91 ) ;
case V_324 :
return F_114 ( V_10 , V_91 ) ;
case V_325 :
return F_115 ( V_10 , V_57 , V_91 ) ;
case V_326 : {
struct V_92 V_327 ;
if ( F_17 ( & V_327 , V_91 , sizeof( V_327 ) ) )
return - V_36 ;
error = F_50 ( V_57 ) ;
if ( error )
return error ;
error = F_39 ( V_10 , V_327 . V_98 ,
V_327 . V_99 ) ;
F_51 ( V_57 ) ;
return error ;
}
case V_328 :
case V_291 :
return F_117 ( V_10 , V_137 , V_1 , V_91 ) ;
case V_329 :
return F_120 ( V_10 , V_91 ) ;
case V_11 :
case V_330 :
case V_26 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_91 , sizeof( V_2 ) ) )
return - V_36 ;
return F_1 ( V_1 , & V_2 ) ;
}
case V_331 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_91 , sizeof( T_1 ) ) )
return - V_36 ;
return F_20 ( V_57 , & V_2 ) ;
}
case V_332 :
return F_49 ( V_57 , V_91 ) ;
case V_333 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_91 , sizeof( T_1 ) ) )
return - V_36 ;
return F_33 ( V_57 , & V_2 ) ;
}
case V_334 :
return F_52 ( V_57 , V_91 ) ;
case V_335 :
return F_63 ( V_57 , V_91 ) ;
case V_336 : {
struct V_337 V_296 ;
if ( F_17 ( & V_296 , V_91 , sizeof( T_25 ) ) )
return - V_36 ;
error = F_50 ( V_57 ) ;
if ( error )
return error ;
error = F_121 ( & V_296 ) ;
F_51 ( V_57 ) ;
return error ;
}
case V_338 : {
T_27 V_96 ;
error = F_128 ( V_82 , & V_96 ) ;
if ( error )
return error ;
if ( F_11 ( V_91 , & V_96 , sizeof( V_96 ) ) )
return - V_36 ;
return 0 ;
}
case V_339 : {
T_28 V_340 ;
T_29 V_341 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( V_82 -> V_252 & V_253 )
return - V_254 ;
if ( F_17 ( & V_340 , V_91 , sizeof( V_340 ) ) )
return - V_36 ;
error = F_50 ( V_57 ) ;
if ( error )
return error ;
V_341 = V_340 . V_342 ;
error = F_129 ( V_82 , & V_341 , & V_340 ) ;
F_51 ( V_57 ) ;
if ( error )
return error ;
if ( F_11 ( V_91 , & V_340 , sizeof( V_340 ) ) )
return - V_36 ;
return 0 ;
}
case V_343 : {
T_28 V_96 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
error = F_129 ( V_82 , NULL , & V_96 ) ;
if ( error )
return error ;
if ( F_11 ( V_91 , & V_96 , sizeof( V_96 ) ) )
return - V_36 ;
return 0 ;
}
case V_344 : {
T_30 V_341 ;
if ( F_17 ( & V_341 , V_91 , sizeof( V_341 ) ) )
return - V_36 ;
error = F_50 ( V_57 ) ;
if ( error )
return error ;
error = F_130 ( V_82 , & V_341 ) ;
F_51 ( V_57 ) ;
return error ;
}
case V_345 : {
T_31 V_341 ;
if ( F_17 ( & V_341 , V_91 , sizeof( V_341 ) ) )
return - V_36 ;
error = F_50 ( V_57 ) ;
if ( error )
return error ;
error = F_131 ( V_82 , & V_341 ) ;
F_51 ( V_57 ) ;
return error ;
}
case V_346 : {
T_32 V_341 ;
if ( F_17 ( & V_341 , V_91 , sizeof( V_341 ) ) )
return - V_36 ;
error = F_50 ( V_57 ) ;
if ( error )
return error ;
error = F_132 ( V_82 , & V_341 ) ;
F_51 ( V_57 ) ;
return error ;
}
case V_347 : {
T_14 V_341 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( F_133 ( V_341 , ( T_14 V_14 * ) V_91 ) )
return - V_36 ;
return F_134 ( V_82 , V_341 ) ;
}
case V_348 : {
T_33 V_341 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( F_17 ( & V_341 , V_91 , sizeof( V_341 ) ) )
return - V_36 ;
return F_135 ( V_341 . V_349 , V_82 ) ;
}
case V_350 :
if ( ! F_22 ( V_59 ) )
return - V_60 ;
return F_136 ( V_82 , 1 ) ;
case V_351 : {
struct V_352 V_353 ;
struct V_354 V_355 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( V_82 -> V_252 & V_253 )
return - V_254 ;
if ( F_17 ( & V_353 , V_91 , sizeof( V_353 ) ) )
return - V_36 ;
error = F_137 ( & V_353 , & V_355 ) ;
if ( error )
return error ;
return F_138 ( V_82 , & V_355 ) ;
}
default:
return - V_356 ;
}
}
