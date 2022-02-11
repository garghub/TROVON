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
int V_29 ;
V_29 = F_9 ( V_10 ) ;
V_4 . V_28 . V_30 = sizeof( V_31 ) -
sizeof( V_4 . V_28 . V_30 ) ;
V_4 . V_28 . V_32 = 0 ;
V_4 . V_28 . V_33 = V_10 -> V_34 . V_35 ;
V_4 . V_28 . V_36 = V_10 -> V_37 ;
F_10 ( V_10 , V_29 ) ;
V_3 = F_11 ( V_4 ) ;
}
error = - V_38 ;
if ( F_12 ( V_2 -> V_39 , & V_4 , V_3 ) ||
F_12 ( V_2 -> V_40 , & V_3 , sizeof( V_41 ) ) )
goto V_21;
error = 0 ;
V_21:
if ( V_1 == V_11 )
F_13 ( V_7 ) ;
else
F_14 ( & V_8 ) ;
return error ;
}
STATIC int
F_15 (
void * V_42 ,
struct V_15 * V_15 )
{
return 1 ;
}
struct V_15 *
F_16 (
struct V_12 * V_43 ,
void V_14 * V_44 ,
T_3 V_45 )
{
T_2 V_4 ;
struct V_46 V_47 ;
if ( ! F_7 ( F_3 ( V_43 ) -> V_22 ) )
return F_17 ( - V_48 ) ;
if ( V_45 != sizeof( T_2 ) )
return F_17 ( - V_17 ) ;
if ( F_18 ( & V_4 , V_44 , V_45 ) )
return F_17 ( - V_38 ) ;
if ( V_4 . V_28 . V_30 !=
sizeof( V_4 . V_28 ) - sizeof( V_4 . V_28 . V_30 ) )
return F_17 ( - V_17 ) ;
memset ( & V_47 , 0 , sizeof( struct V_47 ) ) ;
V_47 . V_49 = V_4 . V_28 . V_36 ;
V_47 . V_50 = V_4 . V_28 . V_33 ;
return F_19 ( V_43 -> V_51 . V_52 , (struct V_47 * ) & V_47 , 3 ,
V_53 | V_54 ,
F_15 , NULL ) ;
}
STATIC struct V_15 *
F_20 (
struct V_12 * V_43 ,
T_1 * V_2 )
{
return F_16 ( V_43 , V_2 -> V_55 , V_2 -> V_56 ) ;
}
int
F_21 (
struct V_12 * V_43 ,
T_1 * V_2 )
{
const struct V_57 * V_57 = F_22 () ;
int error ;
int V_6 ;
int V_58 ;
struct V_12 * V_59 ;
struct V_5 * V_5 ;
struct V_15 * V_15 ;
T_4 V_60 ;
struct V_8 V_8 ;
if ( ! F_23 ( V_61 ) )
return - F_24 ( V_62 ) ;
V_15 = F_20 ( V_43 , V_2 ) ;
if ( F_25 ( V_15 ) )
return F_26 ( V_15 ) ;
V_5 = V_15 -> V_16 ;
if ( ! ( F_6 ( V_5 -> V_22 ) || F_7 ( V_5 -> V_22 ) ) ) {
error = - F_24 ( V_62 ) ;
goto V_63;
}
#if V_64 != 32
V_2 -> V_65 |= V_66 ;
#endif
V_58 = V_2 -> V_65 ;
V_60 = F_27 ( V_58 ) ;
if ( ( ! ( V_58 & V_67 ) || ( V_58 & V_68 ) ) &&
( V_60 & V_69 ) && F_28 ( V_5 ) ) {
error = - F_24 ( V_62 ) ;
goto V_63;
}
if ( ( V_60 & V_69 ) && F_29 ( V_5 ) ) {
error = - F_24 ( V_70 ) ;
goto V_63;
}
if ( F_7 ( V_5 -> V_22 ) && ( V_60 & V_69 ) ) {
error = - F_24 ( V_71 ) ;
goto V_63;
}
V_6 = F_30 ( 0 ) ;
if ( V_6 < 0 ) {
error = V_6 ;
goto V_63;
}
V_8 . V_52 = V_43 -> V_51 . V_52 ;
V_8 . V_15 = V_15 ;
V_59 = F_31 ( & V_8 , V_2 -> V_65 , V_57 ) ;
F_32 ( V_15 ) ;
if ( F_25 ( V_59 ) ) {
F_33 ( V_6 ) ;
return F_26 ( V_59 ) ;
}
if ( F_6 ( V_5 -> V_22 ) ) {
V_59 -> V_72 |= V_73 ;
V_59 -> V_74 |= V_75 ;
}
F_34 ( V_6 , V_59 ) ;
return V_6 ;
V_63:
F_32 ( V_15 ) ;
return error ;
}
STATIC int
F_35 (
char V_14 * V_76 ,
int V_77 ,
const char * V_78 )
{
int V_79 ;
V_79 = F_26 ( V_78 ) ;
if ( F_25 ( V_78 ) )
goto V_80;
V_79 = strlen ( V_78 ) ;
if ( V_79 > ( unsigned ) V_77 )
V_79 = V_77 ;
if ( F_12 ( V_76 , V_78 , V_79 ) )
V_79 = - V_38 ;
V_80:
return V_79 ;
}
int
F_36 (
struct V_12 * V_43 ,
T_1 * V_2 )
{
struct V_15 * V_15 ;
T_5 V_81 ;
void * V_78 ;
int error ;
if ( ! F_23 ( V_61 ) )
return - F_24 ( V_62 ) ;
V_15 = F_20 ( V_43 , V_2 ) ;
if ( F_25 ( V_15 ) )
return F_26 ( V_15 ) ;
if ( ! F_8 ( V_15 -> V_16 -> V_22 ) ) {
error = - F_24 ( V_17 ) ;
goto V_63;
}
if ( F_18 ( & V_81 , V_2 -> V_40 , sizeof( T_5 ) ) ) {
error = - F_24 ( V_38 ) ;
goto V_63;
}
V_78 = F_37 ( V_82 + 1 , V_83 ) ;
if ( ! V_78 ) {
error = - F_24 ( V_84 ) ;
goto V_63;
}
error = - F_38 ( F_5 ( V_15 -> V_16 ) , V_78 ) ;
if ( error )
goto V_85;
error = F_35 ( V_2 -> V_39 , V_81 , V_78 ) ;
if ( error )
goto V_85;
V_85:
F_39 ( V_78 ) ;
V_63:
F_32 ( V_15 ) ;
return error ;
}
int
F_40 (
T_6 * V_10 ,
T_7 V_86 ,
T_8 V_87 )
{
T_9 * V_88 = V_10 -> V_24 ;
T_10 * V_89 ;
int error ;
if ( ! F_23 ( V_61 ) )
return F_24 ( V_62 ) ;
if ( F_41 ( V_88 ) )
return F_24 ( V_90 ) ;
V_89 = F_42 ( V_88 , V_91 ) ;
error = F_43 ( V_89 , & F_44 ( V_88 ) -> V_92 , 0 , 0 ) ;
if ( error ) {
F_45 ( V_89 , 0 ) ;
return error ;
}
F_46 ( V_10 , V_93 ) ;
F_47 ( V_89 , V_10 , V_93 ) ;
V_10 -> V_34 . V_94 = V_86 ;
V_10 -> V_34 . V_95 = V_87 ;
F_48 ( V_89 , V_10 , V_96 ) ;
error = F_49 ( V_89 , 0 ) ;
return error ;
}
STATIC int
F_50 (
struct V_12 * V_43 ,
void V_14 * V_97 )
{
int error ;
struct V_98 V_99 ;
T_11 V_100 ;
struct V_15 * V_15 ;
if ( ! F_23 ( V_101 ) )
return - F_24 ( V_62 ) ;
if ( F_18 ( & V_100 , V_97 , sizeof( T_11 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_43 ) ;
if ( error )
return error ;
V_15 = F_20 ( V_43 , & V_100 . V_2 ) ;
if ( F_25 ( V_15 ) ) {
F_52 ( V_43 ) ;
return F_26 ( V_15 ) ;
}
if ( F_29 ( V_15 -> V_16 ) || F_28 ( V_15 -> V_16 ) ) {
error = - F_24 ( V_62 ) ;
goto V_80;
}
if ( F_18 ( & V_99 , V_100 . V_102 , sizeof( V_99 ) ) ) {
error = - F_24 ( V_38 ) ;
goto V_80;
}
error = - F_40 ( F_5 ( V_15 -> V_16 ) , V_99 . V_103 ,
V_99 . V_104 ) ;
V_80:
F_52 ( V_43 ) ;
F_32 ( V_15 ) ;
return error ;
}
STATIC int
F_53 (
struct V_12 * V_43 ,
void V_14 * V_97 )
{
int error = - V_84 ;
T_12 * V_105 ;
T_13 V_106 ;
struct V_15 * V_15 ;
char * V_107 ;
if ( ! F_23 ( V_61 ) )
return - F_24 ( V_62 ) ;
if ( F_18 ( & V_106 , V_97 , sizeof( T_13 ) ) )
return - F_24 ( V_38 ) ;
if ( V_106 . V_77 > V_108 )
return - F_24 ( V_17 ) ;
if ( V_106 . V_109 & ~ ( V_110 | V_111 ) )
return - F_24 ( V_17 ) ;
V_15 = F_20 ( V_43 , & V_106 . V_2 ) ;
if ( F_25 ( V_15 ) )
return F_26 ( V_15 ) ;
V_107 = F_54 ( V_106 . V_77 , V_112 ) ;
if ( ! V_107 )
goto V_63;
V_105 = ( T_12 * ) & V_106 . V_113 ;
error = - F_55 ( F_5 ( V_15 -> V_16 ) , V_107 , V_106 . V_77 ,
V_106 . V_109 , V_105 ) ;
if ( error )
goto V_85;
if ( F_12 ( V_106 . V_76 , V_107 , V_106 . V_77 ) )
error = - V_38 ;
V_85:
F_56 ( V_107 ) ;
V_63:
F_32 ( V_15 ) ;
return error ;
}
int
F_57 (
struct V_5 * V_5 ,
unsigned char * V_114 ,
unsigned char V_14 * V_115 ,
T_14 * V_79 ,
T_14 V_109 )
{
unsigned char * V_107 ;
int error = V_38 ;
if ( * V_79 > V_116 )
return V_17 ;
V_107 = F_54 ( * V_79 , V_112 ) ;
if ( ! V_107 )
return V_84 ;
error = F_58 ( F_5 ( V_5 ) , V_114 , V_107 , ( int * ) V_79 , V_109 ) ;
if ( error )
goto V_85;
if ( F_12 ( V_115 , V_107 , * V_79 ) )
error = V_38 ;
V_85:
F_56 ( V_107 ) ;
return error ;
}
int
F_59 (
struct V_5 * V_5 ,
unsigned char * V_114 ,
const unsigned char V_14 * V_115 ,
T_14 V_79 ,
T_14 V_109 )
{
unsigned char * V_107 ;
int error = V_38 ;
if ( F_29 ( V_5 ) || F_28 ( V_5 ) )
return V_62 ;
if ( V_79 > V_116 )
return V_17 ;
V_107 = F_60 ( V_115 , V_79 ) ;
if ( F_25 ( V_107 ) )
return F_26 ( V_107 ) ;
error = F_61 ( F_5 ( V_5 ) , V_114 , V_107 , V_79 , V_109 ) ;
return error ;
}
int
F_62 (
struct V_5 * V_5 ,
unsigned char * V_114 ,
T_14 V_109 )
{
if ( F_29 ( V_5 ) || F_28 ( V_5 ) )
return V_62 ;
return F_63 ( F_5 ( V_5 ) , V_114 , V_109 ) ;
}
STATIC int
F_64 (
struct V_12 * V_43 ,
void V_14 * V_97 )
{
int error ;
T_15 * V_117 ;
T_16 V_118 ;
struct V_15 * V_15 ;
unsigned int V_119 , V_120 ;
unsigned char * V_121 ;
if ( ! F_23 ( V_61 ) )
return - F_24 ( V_62 ) ;
if ( F_18 ( & V_118 , V_97 , sizeof( T_16 ) ) )
return - F_24 ( V_38 ) ;
if ( V_118 . V_122 >= V_123 / sizeof( T_15 ) )
return - V_124 ;
V_15 = F_20 ( V_43 , & V_118 . V_2 ) ;
if ( F_25 ( V_15 ) )
return F_26 ( V_15 ) ;
error = V_124 ;
V_120 = V_118 . V_122 * sizeof( T_15 ) ;
if ( ! V_120 || V_120 > 16 * V_125 )
goto V_63;
V_117 = F_60 ( V_118 . V_117 , V_120 ) ;
if ( F_25 ( V_117 ) ) {
error = F_26 ( V_117 ) ;
goto V_63;
}
V_121 = F_37 ( V_126 , V_83 ) ;
if ( ! V_121 )
goto V_127;
error = 0 ;
for ( V_119 = 0 ; V_119 < V_118 . V_122 ; V_119 ++ ) {
V_117 [ V_119 ] . V_128 = F_65 ( ( char * ) V_121 ,
V_117 [ V_119 ] . V_129 , V_126 ) ;
if ( V_117 [ V_119 ] . V_128 == 0 || V_117 [ V_119 ] . V_128 == V_126 )
error = - V_130 ;
if ( V_117 [ V_119 ] . V_128 < 0 )
break;
switch ( V_117 [ V_119 ] . V_131 ) {
case V_132 :
V_117 [ V_119 ] . V_128 = F_57 (
V_15 -> V_16 , V_121 ,
V_117 [ V_119 ] . V_133 , & V_117 [ V_119 ] . V_134 ,
V_117 [ V_119 ] . V_135 ) ;
break;
case V_136 :
V_117 [ V_119 ] . V_128 = F_51 ( V_43 ) ;
if ( V_117 [ V_119 ] . V_128 )
break;
V_117 [ V_119 ] . V_128 = F_59 (
V_15 -> V_16 , V_121 ,
V_117 [ V_119 ] . V_133 , V_117 [ V_119 ] . V_134 ,
V_117 [ V_119 ] . V_135 ) ;
F_52 ( V_43 ) ;
break;
case V_137 :
V_117 [ V_119 ] . V_128 = F_51 ( V_43 ) ;
if ( V_117 [ V_119 ] . V_128 )
break;
V_117 [ V_119 ] . V_128 = F_62 (
V_15 -> V_16 , V_121 ,
V_117 [ V_119 ] . V_135 ) ;
F_52 ( V_43 ) ;
break;
default:
V_117 [ V_119 ] . V_128 = V_17 ;
}
}
if ( F_12 ( V_118 . V_117 , V_117 , V_120 ) )
error = F_24 ( V_38 ) ;
F_39 ( V_121 ) ;
V_127:
F_39 ( V_117 ) ;
V_63:
F_32 ( V_15 ) ;
return - error ;
}
int
F_66 (
struct V_9 * V_10 ,
struct V_5 * V_5 ,
struct V_12 * V_59 ,
int V_138 ,
unsigned int V_1 ,
T_17 * V_139 )
{
int V_140 = 0 ;
int error ;
if ( ! F_67 ( & V_10 -> V_24 -> V_141 ) &&
! F_23 ( V_61 ) )
return - F_24 ( V_62 ) ;
if ( V_5 -> V_142 & ( V_143 | V_144 ) )
return - F_24 ( V_62 ) ;
if ( ! ( V_59 -> V_74 & V_69 ) )
return - F_24 ( V_13 ) ;
if ( ! F_6 ( V_5 -> V_22 ) )
return - F_24 ( V_17 ) ;
if ( V_59 -> V_72 & ( V_145 | V_146 ) )
V_140 |= V_147 ;
if ( V_59 -> V_72 & V_148 )
V_140 |= V_149 ;
if ( V_138 & V_150 )
V_140 |= V_151 ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_68 ( V_10 , V_1 , V_139 , V_59 -> V_152 , V_140 ) ;
F_52 ( V_59 ) ;
return - error ;
}
STATIC int
F_69 (
T_9 * V_88 ,
unsigned int V_1 ,
void V_14 * V_97 )
{
T_18 V_153 ;
int V_154 ;
T_19 V_155 ;
int V_156 ;
int error ;
if ( ! F_23 ( V_61 ) )
return - V_62 ;
if ( F_41 ( V_88 ) )
return - F_24 ( V_90 ) ;
if ( F_18 ( & V_153 , V_97 , sizeof( T_18 ) ) )
return - F_24 ( V_38 ) ;
if ( F_18 ( & V_155 , V_153 . V_157 , sizeof( V_158 ) ) )
return - F_24 ( V_38 ) ;
if ( ( V_154 = V_153 . V_159 ) <= 0 )
return - F_24 ( V_17 ) ;
if ( V_153 . V_160 == NULL )
return - F_24 ( V_17 ) ;
if ( V_1 == V_161 )
error = F_70 ( V_88 , & V_155 , & V_154 ,
V_153 . V_160 , V_162 ) ;
else if ( V_1 == V_163 )
error = F_71 ( V_88 , & V_155 ,
V_153 . V_160 , & V_156 ) ;
else
error = F_72 ( V_88 , & V_155 , & V_154 , V_164 ,
sizeof( V_165 ) , V_153 . V_160 ,
& V_156 ) ;
if ( error )
return - error ;
if ( V_153 . V_166 != NULL ) {
if ( F_12 ( V_153 . V_157 , & V_155 ,
sizeof( T_19 ) ) )
return - F_24 ( V_38 ) ;
if ( F_12 ( V_153 . V_166 , & V_154 , sizeof( V_154 ) ) )
return - F_24 ( V_38 ) ;
}
return 0 ;
}
STATIC int
F_73 (
T_9 * V_88 ,
void V_14 * V_97 )
{
T_20 V_167 ;
int error ;
error = F_74 ( V_88 , & V_167 , 3 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_167 , sizeof( V_168 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
STATIC int
F_75 (
T_9 * V_88 ,
void V_14 * V_97 )
{
T_20 V_167 ;
int error ;
error = F_74 ( V_88 , & V_167 , 4 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_167 , sizeof( V_167 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
STATIC unsigned int
F_76 (
unsigned int V_109 ,
unsigned int V_169 )
{
unsigned int V_170 = V_169 ;
if ( V_109 & V_171 )
V_170 |= V_172 ;
else
V_170 &= ~ V_172 ;
if ( V_109 & V_173 )
V_170 |= V_174 ;
else
V_170 &= ~ V_174 ;
if ( V_109 & V_175 )
V_170 |= V_176 ;
else
V_170 &= ~ V_176 ;
if ( V_109 & V_177 )
V_170 |= V_178 ;
else
V_170 &= ~ V_178 ;
if ( V_109 & V_179 )
V_170 |= V_180 ;
else
V_170 &= ~ V_180 ;
return V_170 ;
}
STATIC unsigned int
F_77 (
T_21 V_181 )
{
unsigned int V_109 = 0 ;
if ( V_181 & V_182 )
V_109 |= V_171 ;
if ( V_181 & V_183 )
V_109 |= V_173 ;
if ( V_181 & V_184 )
V_109 |= V_175 ;
if ( V_181 & V_185 )
V_109 |= V_177 ;
if ( V_181 & V_186 )
V_109 |= V_179 ;
return V_109 ;
}
STATIC int
F_78 (
T_6 * V_10 ,
int V_187 ,
void V_14 * V_97 )
{
struct V_188 V_189 ;
memset ( & V_189 , 0 , sizeof( struct V_188 ) ) ;
F_46 ( V_10 , V_190 ) ;
V_189 . V_191 = F_79 ( V_10 ) ;
V_189 . V_192 = V_10 -> V_34 . V_193 << V_10 -> V_24 -> V_141 . V_194 ;
V_189 . V_195 = F_80 ( V_10 ) ;
if ( V_187 ) {
if ( V_10 -> V_196 ) {
if ( V_10 -> V_196 -> V_197 & V_198 )
V_189 . V_199 = V_10 -> V_196 -> V_200 /
sizeof( V_201 ) ;
else
V_189 . V_199 = V_10 -> V_34 . V_202 ;
} else
V_189 . V_199 = 0 ;
} else {
if ( V_10 -> V_203 . V_197 & V_198 )
V_189 . V_199 = V_10 -> V_203 . V_200 /
sizeof( V_201 ) ;
else
V_189 . V_199 = V_10 -> V_34 . V_204 ;
}
F_81 ( V_10 , V_190 ) ;
if ( F_12 ( V_97 , & V_189 , sizeof( V_189 ) ) )
return - V_38 ;
return 0 ;
}
STATIC void
F_82 (
struct V_9 * V_10 ,
unsigned int V_170 )
{
unsigned int V_181 ;
V_181 = ( V_10 -> V_34 . V_181 & V_205 ) ;
if ( V_170 & V_172 )
V_181 |= V_182 ;
if ( V_170 & V_174 )
V_181 |= V_183 ;
if ( V_170 & V_176 )
V_181 |= V_184 ;
if ( V_170 & V_178 )
V_181 |= V_185 ;
if ( V_170 & V_180 )
V_181 |= V_186 ;
if ( V_170 & V_206 )
V_181 |= V_207 ;
if ( V_170 & V_208 )
V_181 |= V_209 ;
if ( V_170 & V_210 )
V_181 |= V_211 ;
if ( F_7 ( V_10 -> V_34 . V_212 ) ) {
if ( V_170 & V_213 )
V_181 |= V_214 ;
if ( V_170 & V_215 )
V_181 |= V_216 ;
if ( V_170 & V_217 )
V_181 |= V_218 ;
} else if ( F_6 ( V_10 -> V_34 . V_212 ) ) {
if ( V_170 & V_219 )
V_181 |= V_220 ;
if ( V_170 & V_221 )
V_181 |= V_222 ;
}
V_10 -> V_34 . V_181 = V_181 ;
}
STATIC void
F_83 (
struct V_9 * V_10 )
{
struct V_5 * V_5 = F_84 ( V_10 ) ;
unsigned int V_170 = F_79 ( V_10 ) ;
if ( V_170 & V_172 )
V_5 -> V_142 |= V_143 ;
else
V_5 -> V_142 &= ~ V_143 ;
if ( V_170 & V_174 )
V_5 -> V_142 |= V_144 ;
else
V_5 -> V_142 &= ~ V_144 ;
if ( V_170 & V_176 )
V_5 -> V_142 |= V_223 ;
else
V_5 -> V_142 &= ~ V_223 ;
if ( V_170 & V_178 )
V_5 -> V_142 |= V_224 ;
else
V_5 -> V_142 &= ~ V_224 ;
}
STATIC int
F_85 (
T_6 * V_10 ,
struct V_188 * V_189 ,
int V_225 )
{
struct V_226 * V_88 = V_10 -> V_24 ;
struct V_227 * V_89 ;
unsigned int V_228 = 0 ;
struct V_229 * V_230 = NULL ;
struct V_229 * V_231 = NULL ;
struct V_229 * V_232 = NULL ;
int V_233 ;
F_86 ( V_10 ) ;
if ( V_88 -> V_234 & V_235 )
return F_24 ( V_236 ) ;
if ( F_41 ( V_88 ) )
return F_24 ( V_90 ) ;
if ( ( V_225 & V_237 ) && ( V_189 -> V_195 > ( T_21 ) - 1 ) &&
! F_87 ( & V_10 -> V_24 -> V_141 ) )
return F_24 ( V_17 ) ;
if ( F_88 ( V_88 ) && ( V_225 & V_237 ) ) {
V_233 = F_89 ( V_10 , V_10 -> V_34 . V_238 ,
V_10 -> V_34 . V_239 , V_189 -> V_195 ,
V_240 , & V_230 , NULL , & V_231 ) ;
if ( V_233 )
return V_233 ;
}
V_89 = F_42 ( V_88 , V_241 ) ;
V_233 = F_43 ( V_89 , & F_44 ( V_88 ) -> V_92 , 0 , 0 ) ;
if ( V_233 )
goto V_242;
V_228 = V_93 ;
F_46 ( V_10 , V_228 ) ;
if ( ! F_90 ( F_84 ( V_10 ) ) ) {
V_233 = F_24 ( V_62 ) ;
goto V_242;
}
if ( V_225 & V_237 ) {
if ( F_91 () != & V_243 ) {
V_233 = F_24 ( V_17 ) ;
goto V_242;
}
if ( F_92 ( V_88 ) &&
F_93 ( V_88 ) &&
F_80 ( V_10 ) != V_189 -> V_195 ) {
ASSERT ( V_89 ) ;
V_233 = F_94 ( V_89 , V_10 , V_230 , NULL ,
V_231 , F_23 ( V_244 ) ?
V_245 : 0 ) ;
if ( V_233 )
goto V_242;
}
}
if ( V_225 & V_246 ) {
if ( V_10 -> V_34 . V_204 &&
( ( V_10 -> V_34 . V_193 << V_88 -> V_141 . V_194 ) !=
V_189 -> V_192 ) ) {
V_233 = F_24 ( V_17 ) ;
goto V_242;
}
if ( V_189 -> V_192 != 0 ) {
T_22 V_120 ;
T_23 V_247 ;
V_247 = F_95 ( V_88 , V_189 -> V_192 ) ;
if ( V_247 > V_248 ) {
V_233 = F_24 ( V_17 ) ;
goto V_242;
}
if ( F_96 ( V_10 ) ||
( ( V_225 & V_249 ) &&
( V_189 -> V_191 & V_219 ) ) ) {
V_120 = V_88 -> V_141 . V_250 <<
V_88 -> V_141 . V_194 ;
} else {
V_120 = V_88 -> V_141 . V_251 ;
if ( V_247 > V_88 -> V_141 . V_252 / 2 ) {
V_233 = F_24 ( V_17 ) ;
goto V_242;
}
}
if ( V_189 -> V_192 % V_120 ) {
V_233 = F_24 ( V_17 ) ;
goto V_242;
}
}
}
if ( V_225 & V_249 ) {
if ( ( V_10 -> V_34 . V_204 || V_10 -> V_253 ) &&
( F_96 ( V_10 ) ) !=
( V_189 -> V_191 & V_219 ) ) {
V_233 = F_24 ( V_17 ) ;
goto V_242;
}
if ( ( V_189 -> V_191 & V_219 ) ) {
if ( ( V_88 -> V_141 . V_254 == 0 ) ||
( V_88 -> V_141 . V_250 == 0 ) ||
( V_10 -> V_34 . V_193 % V_88 -> V_141 . V_250 ) ) {
V_233 = F_24 ( V_17 ) ;
goto V_242;
}
}
if ( ( V_10 -> V_34 . V_181 &
( V_182 | V_183 ) ||
( V_189 -> V_191 &
( V_172 | V_174 ) ) ) &&
! F_23 ( V_255 ) ) {
V_233 = F_24 ( V_62 ) ;
goto V_242;
}
}
F_47 ( V_89 , V_10 , 0 ) ;
if ( V_225 & V_237 ) {
if ( ( V_10 -> V_34 . V_212 & ( V_256 | V_257 ) ) &&
! F_97 ( F_84 ( V_10 ) , V_258 ) )
V_10 -> V_34 . V_212 &= ~ ( V_256 | V_257 ) ;
if ( F_80 ( V_10 ) != V_189 -> V_195 ) {
if ( F_92 ( V_88 ) && F_93 ( V_88 ) ) {
V_232 = F_98 ( V_89 , V_10 ,
& V_10 -> V_259 , V_231 ) ;
}
F_99 ( V_10 , V_189 -> V_195 ) ;
if ( V_10 -> V_34 . V_260 == 1 )
F_100 ( V_89 , V_10 ) ;
}
}
if ( V_225 & V_246 )
V_10 -> V_34 . V_193 = V_189 -> V_192 >> V_88 -> V_141 . V_194 ;
if ( V_225 & V_249 ) {
F_82 ( V_10 , V_189 -> V_191 ) ;
F_83 ( V_10 ) ;
}
F_101 ( V_89 , V_10 , V_261 ) ;
F_48 ( V_89 , V_10 , V_96 ) ;
F_102 ( V_262 ) ;
if ( V_88 -> V_234 & V_263 )
F_103 ( V_89 ) ;
V_233 = F_49 ( V_89 , 0 ) ;
F_81 ( V_10 , V_228 ) ;
F_104 ( V_232 ) ;
F_104 ( V_230 ) ;
F_104 ( V_231 ) ;
return V_233 ;
V_242:
F_104 ( V_230 ) ;
F_104 ( V_231 ) ;
F_45 ( V_89 , 0 ) ;
if ( V_228 )
F_81 ( V_10 , V_228 ) ;
return V_233 ;
}
STATIC int
F_105 (
T_6 * V_10 ,
struct V_12 * V_59 ,
void V_14 * V_97 )
{
struct V_188 V_189 ;
unsigned int V_225 ;
int error ;
if ( F_18 ( & V_189 , V_97 , sizeof( V_189 ) ) )
return - V_38 ;
V_225 = V_249 | V_246 | V_237 ;
if ( V_59 -> V_72 & ( V_145 | V_146 ) )
V_225 |= V_264 ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_85 ( V_10 , & V_189 , V_225 ) ;
F_52 ( V_59 ) ;
return - error ;
}
STATIC int
F_106 (
T_6 * V_10 ,
void V_14 * V_97 )
{
unsigned int V_109 ;
V_109 = F_77 ( V_10 -> V_34 . V_181 ) ;
if ( F_12 ( V_97 , & V_109 , sizeof( V_109 ) ) )
return - V_38 ;
return 0 ;
}
STATIC int
F_107 (
T_6 * V_10 ,
struct V_12 * V_59 ,
void V_14 * V_97 )
{
struct V_188 V_189 ;
unsigned int V_109 ;
unsigned int V_225 ;
int error ;
if ( F_18 ( & V_109 , V_97 , sizeof( V_109 ) ) )
return - V_38 ;
if ( V_109 & ~ ( V_171 | V_173 | \
V_177 | V_179 | \
V_175 ) )
return - V_265 ;
V_225 = V_249 ;
if ( V_59 -> V_72 & ( V_145 | V_146 ) )
V_225 |= V_264 ;
V_189 . V_191 = F_76 ( V_109 , F_79 ( V_10 ) ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_85 ( V_10 , & V_189 , V_225 ) ;
F_52 ( V_59 ) ;
return - error ;
}
STATIC int
F_108 ( void * * V_266 , struct V_267 * V_268 , int * V_269 )
{
struct V_270 V_14 * V_271 = * V_266 ;
if ( F_12 ( V_271 , V_268 , sizeof( struct V_270 ) ) )
return F_24 ( V_38 ) ;
* V_266 += sizeof( struct V_270 ) ;
return 0 ;
}
STATIC int
F_109 (
struct V_9 * V_10 ,
int V_138 ,
unsigned int V_1 ,
void V_14 * V_97 )
{
struct V_267 V_272 ;
int error ;
if ( F_18 ( & V_272 , V_97 , sizeof( struct V_267 ) ) )
return - F_24 ( V_38 ) ;
if ( V_272 . V_273 < 2 )
return - F_24 ( V_17 ) ;
V_272 . V_274 = ( V_1 == V_275 ? V_276 : 0 ) ;
if ( V_138 & V_150 )
V_272 . V_274 |= V_277 ;
error = F_110 ( V_10 , & V_272 , F_108 ,
(struct V_270 * ) V_97 + 1 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_272 , sizeof( struct V_270 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
STATIC int
F_111 ( void * * V_266 , struct V_267 * V_268 , int * V_269 )
{
struct V_267 V_14 * V_271 = * V_266 ;
if ( F_12 ( V_271 , V_268 , sizeof( struct V_267 ) ) )
return F_24 ( V_38 ) ;
* V_266 += sizeof( struct V_267 ) ;
return 0 ;
}
STATIC int
F_112 (
struct V_9 * V_10 ,
void V_14 * V_97 )
{
struct V_267 V_272 ;
int error ;
if ( F_18 ( & V_272 , V_97 , sizeof( V_272 ) ) )
return - F_24 ( V_38 ) ;
if ( V_272 . V_273 < 2 )
return - F_24 ( V_17 ) ;
if ( V_272 . V_274 & ( ~ V_278 ) )
return - F_24 ( V_17 ) ;
error = F_110 ( V_10 , & V_272 , F_111 ,
(struct V_267 * ) V_97 + 1 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_272 , sizeof( struct V_267 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
int
F_113 (
T_24 * V_279 )
{
T_6 * V_10 , * V_280 ;
struct V_6 V_7 , V_281 ;
int error = 0 ;
V_7 = F_2 ( ( int ) V_279 -> V_282 ) ;
if ( ! V_7 . V_12 ) {
error = F_24 ( V_17 ) ;
goto V_80;
}
if ( ! ( V_7 . V_12 -> V_74 & V_69 ) ||
! ( V_7 . V_12 -> V_74 & V_283 ) ||
( V_7 . V_12 -> V_72 & V_67 ) ) {
error = F_24 ( V_13 ) ;
goto V_284;
}
V_281 = F_2 ( ( int ) V_279 -> V_285 ) ;
if ( ! V_281 . V_12 ) {
error = F_24 ( V_17 ) ;
goto V_284;
}
if ( ! ( V_281 . V_12 -> V_74 & V_69 ) ||
! ( V_281 . V_12 -> V_74 & V_283 ) ||
( V_281 . V_12 -> V_72 & V_67 ) ) {
error = F_24 ( V_13 ) ;
goto V_286;
}
if ( F_114 ( F_3 ( V_7 . V_12 ) ) ||
F_114 ( F_3 ( V_281 . V_12 ) ) ) {
error = F_24 ( V_17 ) ;
goto V_286;
}
V_10 = F_5 ( F_3 ( V_7 . V_12 ) ) ;
V_280 = F_5 ( F_3 ( V_281 . V_12 ) ) ;
if ( V_10 -> V_24 != V_280 -> V_24 ) {
error = F_24 ( V_17 ) ;
goto V_286;
}
if ( V_10 -> V_37 == V_280 -> V_37 ) {
error = F_24 ( V_17 ) ;
goto V_286;
}
if ( F_41 ( V_10 -> V_24 ) ) {
error = F_24 ( V_90 ) ;
goto V_286;
}
error = F_115 ( V_10 , V_280 , V_279 ) ;
V_286:
F_13 ( V_281 ) ;
V_284:
F_13 ( V_7 ) ;
V_80:
return error ;
}
long
F_116 (
struct V_12 * V_59 ,
unsigned int V_1 ,
unsigned long V_287 )
{
struct V_5 * V_5 = F_3 ( V_59 ) ;
struct V_9 * V_10 = F_5 ( V_5 ) ;
struct V_226 * V_88 = V_10 -> V_24 ;
void V_14 * V_97 = ( void V_14 * ) V_287 ;
int V_138 = 0 ;
int error ;
if ( V_59 -> V_74 & V_75 )
V_138 |= V_150 ;
F_117 ( V_10 ) ;
switch ( V_1 ) {
case V_288 :
return F_118 ( V_88 , V_97 ) ;
case V_289 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
case V_297 : {
T_17 V_139 ;
if ( F_18 ( & V_139 , V_97 , sizeof( V_139 ) ) )
return - F_24 ( V_38 ) ;
return F_66 ( V_10 , V_5 , V_59 , V_138 , V_1 , & V_139 ) ;
}
case V_298 : {
struct V_299 V_300 ;
T_25 * V_301 =
F_96 ( V_10 ) ?
V_88 -> V_302 : V_88 -> V_303 ;
V_300 . V_304 = V_300 . V_305 = 1 << V_301 -> V_306 ;
V_300 . V_307 = V_123 & ~ ( V_300 . V_305 - 1 ) ;
if ( F_12 ( V_97 , & V_300 , sizeof( V_300 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
case V_163 :
case V_308 :
case V_161 :
return F_69 ( V_88 , V_1 , V_97 ) ;
case V_309 :
return F_73 ( V_88 , V_97 ) ;
case V_310 :
return F_75 ( V_88 , V_97 ) ;
case V_311 :
return F_119 ( V_5 -> V_312 , ( int V_14 * ) V_97 ) ;
case V_313 :
return F_78 ( V_10 , 0 , V_97 ) ;
case V_314 :
return F_78 ( V_10 , 1 , V_97 ) ;
case V_315 :
return F_105 ( V_10 , V_59 , V_97 ) ;
case V_316 :
return F_106 ( V_10 , V_97 ) ;
case V_317 :
return F_107 ( V_10 , V_59 , V_97 ) ;
case V_318 : {
struct V_98 V_319 ;
if ( F_18 ( & V_319 , V_97 , sizeof( V_319 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_40 ( V_10 , V_319 . V_103 ,
V_319 . V_104 ) ;
F_52 ( V_59 ) ;
return - error ;
}
case V_320 :
case V_275 :
return F_109 ( V_10 , V_138 , V_1 , V_97 ) ;
case V_321 :
return F_112 ( V_10 , V_97 ) ;
case V_11 :
case V_322 :
case V_27 : {
T_1 V_2 ;
if ( F_18 ( & V_2 , V_97 , sizeof( V_2 ) ) )
return - F_24 ( V_38 ) ;
return F_1 ( V_1 , & V_2 ) ;
}
case V_323 : {
T_1 V_2 ;
if ( F_18 ( & V_2 , V_97 , sizeof( T_1 ) ) )
return - F_24 ( V_38 ) ;
return F_21 ( V_59 , & V_2 ) ;
}
case V_324 :
return F_50 ( V_59 , V_97 ) ;
case V_325 : {
T_1 V_2 ;
if ( F_18 ( & V_2 , V_97 , sizeof( T_1 ) ) )
return - F_24 ( V_38 ) ;
return F_36 ( V_59 , & V_2 ) ;
}
case V_326 :
return F_53 ( V_59 , V_97 ) ;
case V_327 :
return F_64 ( V_59 , V_97 ) ;
case V_328 : {
struct V_329 V_279 ;
if ( F_18 ( & V_279 , V_97 , sizeof( T_24 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_113 ( & V_279 ) ;
F_52 ( V_59 ) ;
return - error ;
}
case V_330 : {
T_26 V_80 ;
error = F_120 ( V_88 , & V_80 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_80 , sizeof( V_80 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
case V_331 : {
T_27 V_332 ;
T_28 V_333 ;
if ( ! F_23 ( V_61 ) )
return - V_62 ;
if ( V_88 -> V_234 & V_235 )
return - F_24 ( V_236 ) ;
if ( F_18 ( & V_332 , V_97 , sizeof( V_332 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
V_333 = V_332 . V_334 ;
error = F_121 ( V_88 , & V_333 , & V_332 ) ;
F_52 ( V_59 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_332 , sizeof( V_332 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
case V_335 : {
T_27 V_80 ;
if ( ! F_23 ( V_61 ) )
return - V_62 ;
error = F_121 ( V_88 , NULL , & V_80 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_80 , sizeof( V_80 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
case V_336 : {
T_29 V_333 ;
if ( F_18 ( & V_333 , V_97 , sizeof( V_333 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_122 ( V_88 , & V_333 ) ;
F_52 ( V_59 ) ;
return - error ;
}
case V_337 : {
T_30 V_333 ;
if ( F_18 ( & V_333 , V_97 , sizeof( V_333 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_123 ( V_88 , & V_333 ) ;
F_52 ( V_59 ) ;
return - error ;
}
case V_338 : {
T_31 V_333 ;
if ( F_18 ( & V_333 , V_97 , sizeof( V_333 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_124 ( V_88 , & V_333 ) ;
F_52 ( V_59 ) ;
return - error ;
}
case V_339 : {
T_14 V_333 ;
if ( ! F_23 ( V_61 ) )
return - V_62 ;
if ( F_125 ( V_333 , ( T_14 V_14 * ) V_97 ) )
return - F_24 ( V_38 ) ;
error = F_126 ( V_88 , V_333 ) ;
return - error ;
}
case V_340 : {
T_32 V_333 ;
if ( ! F_23 ( V_61 ) )
return - V_62 ;
if ( F_18 ( & V_333 , V_97 , sizeof( V_333 ) ) )
return - F_24 ( V_38 ) ;
error = F_127 ( V_333 . V_341 , V_88 ) ;
return - error ;
}
case V_342 :
if ( ! F_23 ( V_61 ) )
return - V_62 ;
error = F_128 ( V_88 , 1 ) ;
return - error ;
case V_343 : {
struct V_344 V_345 ;
struct V_346 V_347 ;
if ( ! F_23 ( V_61 ) )
return - V_62 ;
if ( V_88 -> V_234 & V_235 )
return - F_24 ( V_236 ) ;
if ( F_18 ( & V_345 , V_97 , sizeof( V_345 ) ) )
return - F_24 ( V_38 ) ;
error = F_129 ( & V_345 , & V_347 ) ;
if ( error )
return - error ;
return - F_130 ( V_88 , & V_347 ) ;
}
default:
return - V_348 ;
}
}
