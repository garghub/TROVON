int
F_1 (
unsigned int V_1 ,
T_1 * V_2 )
{
int V_3 ;
T_2 V_4 ;
struct V_5 * V_5 ;
struct V_6 V_7 = { 0 } ;
struct V_8 V_8 ;
int error ;
struct V_9 * V_10 ;
if ( V_1 == V_11 ) {
V_7 = F_2 ( V_2 -> V_6 ) ;
if ( ! V_7 . V_12 )
return - V_13 ;
V_5 = V_7 . V_12 -> V_14 . V_15 -> V_16 ;
} else {
error = F_3 ( ( const char V_17 * ) V_2 -> V_8 , & V_8 ) ;
if ( error )
return error ;
V_5 = V_8 . V_15 -> V_16 ;
}
V_10 = F_4 ( V_5 ) ;
error = - V_18 ;
if ( V_5 -> V_19 -> V_20 != V_21 )
goto V_22;
error = - V_13 ;
if ( ! F_5 ( V_5 -> V_23 ) &&
! F_6 ( V_5 -> V_23 ) &&
! F_7 ( V_5 -> V_23 ) )
goto V_22;
memcpy ( & V_4 . V_24 , V_10 -> V_25 -> V_26 , sizeof( V_27 ) ) ;
if ( V_1 == V_28 ) {
memset ( & V_4 . V_29 , 0 , sizeof( V_4 . V_29 ) ) ;
V_3 = sizeof( V_27 ) ;
} else {
int V_30 ;
V_30 = F_8 ( V_10 ) ;
V_4 . V_29 . V_31 = sizeof( V_32 ) -
sizeof( V_4 . V_29 . V_31 ) ;
V_4 . V_29 . V_33 = 0 ;
V_4 . V_29 . V_34 = V_10 -> V_35 . V_36 ;
V_4 . V_29 . V_37 = V_10 -> V_38 ;
F_9 ( V_10 , V_30 ) ;
V_3 = F_10 ( V_4 ) ;
}
error = - V_39 ;
if ( F_11 ( V_2 -> V_40 , & V_4 , V_3 ) ||
F_11 ( V_2 -> V_41 , & V_3 , sizeof( V_42 ) ) )
goto V_22;
error = 0 ;
V_22:
if ( V_1 == V_11 )
F_12 ( V_7 ) ;
else
F_13 ( & V_8 ) ;
return error ;
}
STATIC int
F_14 (
void * V_43 ,
struct V_15 * V_15 )
{
return 1 ;
}
struct V_15 *
F_15 (
struct V_12 * V_44 ,
void V_17 * V_45 ,
T_3 V_46 )
{
T_2 V_4 ;
struct V_47 V_48 ;
if ( ! F_6 ( V_44 -> V_14 . V_15 -> V_16 -> V_23 ) )
return F_16 ( - V_49 ) ;
if ( V_46 != sizeof( T_2 ) )
return F_16 ( - V_18 ) ;
if ( F_17 ( & V_4 , V_45 , V_46 ) )
return F_16 ( - V_39 ) ;
if ( V_4 . V_29 . V_31 !=
sizeof( V_4 . V_29 ) - sizeof( V_4 . V_29 . V_31 ) )
return F_16 ( - V_18 ) ;
memset ( & V_48 , 0 , sizeof( struct V_48 ) ) ;
V_48 . V_50 = V_4 . V_29 . V_37 ;
V_48 . V_51 = V_4 . V_29 . V_34 ;
return F_18 ( V_44 -> V_14 . V_52 , (struct V_48 * ) & V_48 , 3 ,
V_53 | V_54 ,
F_14 , NULL ) ;
}
STATIC struct V_15 *
F_19 (
struct V_12 * V_44 ,
T_1 * V_2 )
{
return F_15 ( V_44 , V_2 -> V_55 , V_2 -> V_56 ) ;
}
int
F_20 (
struct V_12 * V_44 ,
T_1 * V_2 )
{
const struct V_57 * V_57 = F_21 () ;
int error ;
int V_6 ;
int V_58 ;
struct V_12 * V_59 ;
struct V_5 * V_5 ;
struct V_15 * V_15 ;
T_4 V_60 ;
struct V_8 V_8 ;
if ( ! F_22 ( V_61 ) )
return - F_23 ( V_62 ) ;
V_15 = F_19 ( V_44 , V_2 ) ;
if ( F_24 ( V_15 ) )
return F_25 ( V_15 ) ;
V_5 = V_15 -> V_16 ;
if ( ! ( F_5 ( V_5 -> V_23 ) || F_6 ( V_5 -> V_23 ) ) ) {
error = - F_23 ( V_62 ) ;
goto V_63;
}
#if V_64 != 32
V_2 -> V_65 |= V_66 ;
#endif
V_58 = V_2 -> V_65 ;
V_60 = F_26 ( V_58 ) ;
if ( ( ! ( V_58 & V_67 ) || ( V_58 & V_68 ) ) &&
( V_60 & V_69 ) && F_27 ( V_5 ) ) {
error = - F_23 ( V_62 ) ;
goto V_63;
}
if ( ( V_60 & V_69 ) && F_28 ( V_5 ) ) {
error = - F_23 ( V_70 ) ;
goto V_63;
}
if ( F_6 ( V_5 -> V_23 ) && ( V_60 & V_69 ) ) {
error = - F_23 ( V_71 ) ;
goto V_63;
}
V_6 = F_29 () ;
if ( V_6 < 0 ) {
error = V_6 ;
goto V_63;
}
V_8 . V_52 = V_44 -> V_14 . V_52 ;
V_8 . V_15 = V_15 ;
V_59 = F_30 ( & V_8 , V_2 -> V_65 , V_57 ) ;
F_31 ( V_15 ) ;
if ( F_24 ( V_59 ) ) {
F_32 ( V_6 ) ;
return F_25 ( V_59 ) ;
}
if ( F_5 ( V_5 -> V_23 ) ) {
V_59 -> V_72 |= V_73 ;
V_59 -> V_74 |= V_75 ;
}
F_33 ( V_6 , V_59 ) ;
return V_6 ;
V_63:
F_31 ( V_15 ) ;
return error ;
}
STATIC int
F_34 (
char V_17 * V_76 ,
int V_77 ,
const char * V_78 )
{
int V_79 ;
V_79 = F_25 ( V_78 ) ;
if ( F_24 ( V_78 ) )
goto V_80;
V_79 = strlen ( V_78 ) ;
if ( V_79 > ( unsigned ) V_77 )
V_79 = V_77 ;
if ( F_11 ( V_76 , V_78 , V_79 ) )
V_79 = - V_39 ;
V_80:
return V_79 ;
}
int
F_35 (
struct V_12 * V_44 ,
T_1 * V_2 )
{
struct V_15 * V_15 ;
T_5 V_81 ;
void * V_78 ;
int error ;
if ( ! F_22 ( V_61 ) )
return - F_23 ( V_62 ) ;
V_15 = F_19 ( V_44 , V_2 ) ;
if ( F_24 ( V_15 ) )
return F_25 ( V_15 ) ;
if ( ! F_7 ( V_15 -> V_16 -> V_23 ) ) {
error = - F_23 ( V_18 ) ;
goto V_63;
}
if ( F_17 ( & V_81 , V_2 -> V_41 , sizeof( T_5 ) ) ) {
error = - F_23 ( V_39 ) ;
goto V_63;
}
V_78 = F_36 ( V_82 + 1 , V_83 ) ;
if ( ! V_78 ) {
error = - F_23 ( V_84 ) ;
goto V_63;
}
error = - F_37 ( F_4 ( V_15 -> V_16 ) , V_78 ) ;
if ( error )
goto V_85;
error = F_34 ( V_2 -> V_40 , V_81 , V_78 ) ;
if ( error )
goto V_85;
V_85:
F_38 ( V_78 ) ;
V_63:
F_31 ( V_15 ) ;
return error ;
}
STATIC int
F_39 (
struct V_12 * V_44 ,
void V_17 * V_86 )
{
int error ;
struct V_87 V_88 ;
T_6 V_89 ;
struct V_15 * V_15 ;
if ( ! F_22 ( V_90 ) )
return - F_23 ( V_62 ) ;
if ( F_17 ( & V_89 , V_86 , sizeof( T_6 ) ) )
return - F_23 ( V_39 ) ;
error = F_40 ( V_44 ) ;
if ( error )
return error ;
V_15 = F_19 ( V_44 , & V_89 . V_2 ) ;
if ( F_24 ( V_15 ) ) {
F_41 ( V_44 ) ;
return F_25 ( V_15 ) ;
}
if ( F_28 ( V_15 -> V_16 ) || F_27 ( V_15 -> V_16 ) ) {
error = - F_23 ( V_62 ) ;
goto V_80;
}
if ( F_17 ( & V_88 , V_89 . V_91 , sizeof( V_88 ) ) ) {
error = - F_23 ( V_39 ) ;
goto V_80;
}
error = - F_42 ( F_4 ( V_15 -> V_16 ) , V_88 . V_92 ,
V_88 . V_93 ) ;
V_80:
F_41 ( V_44 ) ;
F_31 ( V_15 ) ;
return error ;
}
STATIC int
F_43 (
struct V_12 * V_44 ,
void V_17 * V_86 )
{
int error = - V_84 ;
T_7 * V_94 ;
T_8 V_95 ;
struct V_15 * V_15 ;
char * V_96 ;
if ( ! F_22 ( V_61 ) )
return - F_23 ( V_62 ) ;
if ( F_17 ( & V_95 , V_86 , sizeof( T_8 ) ) )
return - F_23 ( V_39 ) ;
if ( V_95 . V_77 > V_97 )
return - F_23 ( V_18 ) ;
if ( V_95 . V_98 & ~ ( V_99 | V_100 ) )
return - F_23 ( V_18 ) ;
V_15 = F_19 ( V_44 , & V_95 . V_2 ) ;
if ( F_24 ( V_15 ) )
return F_25 ( V_15 ) ;
V_96 = F_44 ( V_95 . V_77 , V_83 ) ;
if ( ! V_96 )
goto V_63;
V_94 = ( T_7 * ) & V_95 . V_101 ;
error = - F_45 ( F_4 ( V_15 -> V_16 ) , V_96 , V_95 . V_77 ,
V_95 . V_98 , V_94 ) ;
if ( error )
goto V_85;
if ( F_11 ( V_95 . V_76 , V_96 , V_95 . V_77 ) )
error = - V_39 ;
V_85:
F_38 ( V_96 ) ;
V_63:
F_31 ( V_15 ) ;
return error ;
}
int
F_46 (
struct V_5 * V_5 ,
unsigned char * V_102 ,
unsigned char V_17 * V_103 ,
T_9 * V_79 ,
T_9 V_98 )
{
unsigned char * V_96 ;
int error = V_39 ;
if ( * V_79 > V_104 )
return V_18 ;
V_96 = F_47 ( * V_79 , V_105 | V_106 ) ;
if ( ! V_96 ) {
V_96 = F_48 ( * V_79 ) ;
if ( ! V_96 )
return V_84 ;
}
error = F_49 ( F_4 ( V_5 ) , V_102 , V_96 , ( int * ) V_79 , V_98 ) ;
if ( error )
goto V_85;
if ( F_11 ( V_103 , V_96 , * V_79 ) )
error = V_39 ;
V_85:
if ( F_50 ( V_96 ) )
F_51 ( V_96 ) ;
else
F_52 ( V_96 ) ;
return error ;
}
int
F_53 (
struct V_5 * V_5 ,
unsigned char * V_102 ,
const unsigned char V_17 * V_103 ,
T_9 V_79 ,
T_9 V_98 )
{
unsigned char * V_96 ;
int error = V_39 ;
if ( F_28 ( V_5 ) || F_27 ( V_5 ) )
return V_62 ;
if ( V_79 > V_104 )
return V_18 ;
V_96 = F_54 ( V_103 , V_79 ) ;
if ( F_24 ( V_96 ) )
return F_25 ( V_96 ) ;
error = F_55 ( F_4 ( V_5 ) , V_102 , V_96 , V_79 , V_98 ) ;
return error ;
}
int
F_56 (
struct V_5 * V_5 ,
unsigned char * V_102 ,
T_9 V_98 )
{
if ( F_28 ( V_5 ) || F_27 ( V_5 ) )
return V_62 ;
return F_57 ( F_4 ( V_5 ) , V_102 , V_98 ) ;
}
STATIC int
F_58 (
struct V_12 * V_44 ,
void V_17 * V_86 )
{
int error ;
T_10 * V_107 ;
T_11 V_108 ;
struct V_15 * V_15 ;
unsigned int V_109 , V_110 ;
unsigned char * V_111 ;
if ( ! F_22 ( V_61 ) )
return - F_23 ( V_62 ) ;
if ( F_17 ( & V_108 , V_86 , sizeof( T_11 ) ) )
return - F_23 ( V_39 ) ;
if ( V_108 . V_112 >= V_113 / sizeof( T_10 ) )
return - V_114 ;
V_15 = F_19 ( V_44 , & V_108 . V_2 ) ;
if ( F_24 ( V_15 ) )
return F_25 ( V_15 ) ;
error = V_114 ;
V_110 = V_108 . V_112 * sizeof( T_10 ) ;
if ( ! V_110 || V_110 > 16 * V_115 )
goto V_63;
V_107 = F_54 ( V_108 . V_107 , V_110 ) ;
if ( F_24 ( V_107 ) ) {
error = F_25 ( V_107 ) ;
goto V_63;
}
V_111 = F_36 ( V_116 , V_83 ) ;
if ( ! V_111 )
goto V_117;
error = 0 ;
for ( V_109 = 0 ; V_109 < V_108 . V_112 ; V_109 ++ ) {
V_107 [ V_109 ] . V_118 = F_59 ( ( char * ) V_111 ,
V_107 [ V_109 ] . V_119 , V_116 ) ;
if ( V_107 [ V_109 ] . V_118 == 0 || V_107 [ V_109 ] . V_118 == V_116 )
error = - V_120 ;
if ( V_107 [ V_109 ] . V_118 < 0 )
break;
switch ( V_107 [ V_109 ] . V_121 ) {
case V_122 :
V_107 [ V_109 ] . V_118 = F_46 (
V_15 -> V_16 , V_111 ,
V_107 [ V_109 ] . V_123 , & V_107 [ V_109 ] . V_124 ,
V_107 [ V_109 ] . V_125 ) ;
break;
case V_126 :
V_107 [ V_109 ] . V_118 = F_40 ( V_44 ) ;
if ( V_107 [ V_109 ] . V_118 )
break;
V_107 [ V_109 ] . V_118 = F_53 (
V_15 -> V_16 , V_111 ,
V_107 [ V_109 ] . V_123 , V_107 [ V_109 ] . V_124 ,
V_107 [ V_109 ] . V_125 ) ;
F_41 ( V_44 ) ;
break;
case V_127 :
V_107 [ V_109 ] . V_118 = F_40 ( V_44 ) ;
if ( V_107 [ V_109 ] . V_118 )
break;
V_107 [ V_109 ] . V_118 = F_56 (
V_15 -> V_16 , V_111 ,
V_107 [ V_109 ] . V_125 ) ;
F_41 ( V_44 ) ;
break;
default:
V_107 [ V_109 ] . V_118 = V_18 ;
}
}
if ( F_11 ( V_108 . V_107 , V_107 , V_110 ) )
error = F_23 ( V_39 ) ;
F_38 ( V_111 ) ;
V_117:
F_38 ( V_107 ) ;
V_63:
F_31 ( V_15 ) ;
return - error ;
}
int
F_60 (
struct V_9 * V_10 ,
struct V_5 * V_5 ,
struct V_12 * V_59 ,
int V_128 ,
unsigned int V_1 ,
T_12 * V_129 )
{
int V_130 = 0 ;
int error ;
if ( ! F_61 ( & V_10 -> V_25 -> V_131 ) &&
! F_22 ( V_61 ) )
return - F_23 ( V_62 ) ;
if ( V_5 -> V_132 & ( V_133 | V_134 ) )
return - F_23 ( V_62 ) ;
if ( ! ( V_59 -> V_74 & V_69 ) )
return - F_23 ( V_13 ) ;
if ( ! F_5 ( V_5 -> V_23 ) )
return - F_23 ( V_18 ) ;
if ( V_59 -> V_72 & ( V_135 | V_136 ) )
V_130 |= V_137 ;
if ( V_59 -> V_72 & V_138 )
V_130 |= V_139 ;
if ( V_128 & V_140 )
V_130 |= V_141 ;
error = F_40 ( V_59 ) ;
if ( error )
return error ;
error = F_62 ( V_10 , V_1 , V_129 , V_59 -> V_142 , V_130 ) ;
F_41 ( V_59 ) ;
return - error ;
}
STATIC int
F_63 (
T_13 * V_143 ,
unsigned int V_1 ,
void V_17 * V_86 )
{
T_14 V_144 ;
int V_145 ;
T_15 V_146 ;
int V_147 ;
int error ;
if ( ! F_22 ( V_61 ) )
return - V_62 ;
if ( F_64 ( V_143 ) )
return - F_23 ( V_148 ) ;
if ( F_17 ( & V_144 , V_86 , sizeof( T_14 ) ) )
return - F_23 ( V_39 ) ;
if ( F_17 ( & V_146 , V_144 . V_149 , sizeof( V_150 ) ) )
return - F_23 ( V_39 ) ;
if ( ( V_145 = V_144 . V_151 ) <= 0 )
return - F_23 ( V_18 ) ;
if ( V_144 . V_152 == NULL )
return - F_23 ( V_18 ) ;
if ( V_1 == V_153 )
error = F_65 ( V_143 , & V_146 , & V_145 ,
V_144 . V_152 , V_154 ) ;
else if ( V_1 == V_155 )
error = F_66 ( V_143 , & V_146 ,
V_144 . V_152 , & V_147 ) ;
else
error = F_67 ( V_143 , & V_146 , & V_145 , V_156 ,
sizeof( V_157 ) , V_144 . V_152 ,
& V_147 ) ;
if ( error )
return - error ;
if ( V_144 . V_158 != NULL ) {
if ( F_11 ( V_144 . V_149 , & V_146 ,
sizeof( T_15 ) ) )
return - F_23 ( V_39 ) ;
if ( F_11 ( V_144 . V_158 , & V_145 , sizeof( V_145 ) ) )
return - F_23 ( V_39 ) ;
}
return 0 ;
}
STATIC int
F_68 (
T_13 * V_143 ,
void V_17 * V_86 )
{
T_16 V_159 ;
int error ;
error = F_69 ( V_143 , & V_159 , 3 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_159 , sizeof( V_160 ) ) )
return - F_23 ( V_39 ) ;
return 0 ;
}
STATIC int
F_70 (
T_13 * V_143 ,
void V_17 * V_86 )
{
T_16 V_159 ;
int error ;
error = F_69 ( V_143 , & V_159 , 4 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_159 , sizeof( V_159 ) ) )
return - F_23 ( V_39 ) ;
return 0 ;
}
STATIC unsigned int
F_71 (
unsigned int V_98 ,
unsigned int V_161 )
{
unsigned int V_162 = V_161 ;
if ( V_98 & V_163 )
V_162 |= V_164 ;
else
V_162 &= ~ V_164 ;
if ( V_98 & V_165 )
V_162 |= V_166 ;
else
V_162 &= ~ V_166 ;
if ( V_98 & V_167 )
V_162 |= V_168 ;
else
V_162 &= ~ V_168 ;
if ( V_98 & V_169 )
V_162 |= V_170 ;
else
V_162 &= ~ V_170 ;
if ( V_98 & V_171 )
V_162 |= V_172 ;
else
V_162 &= ~ V_172 ;
return V_162 ;
}
STATIC unsigned int
F_72 (
T_17 V_173 )
{
unsigned int V_98 = 0 ;
if ( V_173 & V_174 )
V_98 |= V_163 ;
if ( V_173 & V_175 )
V_98 |= V_165 ;
if ( V_173 & V_176 )
V_98 |= V_167 ;
if ( V_173 & V_177 )
V_98 |= V_169 ;
if ( V_173 & V_178 )
V_98 |= V_171 ;
return V_98 ;
}
STATIC int
F_73 (
T_18 * V_10 ,
int V_179 ,
void V_17 * V_86 )
{
struct V_180 V_181 ;
memset ( & V_181 , 0 , sizeof( struct V_180 ) ) ;
F_74 ( V_10 , V_182 ) ;
V_181 . V_183 = F_75 ( V_10 ) ;
V_181 . V_184 = V_10 -> V_35 . V_185 << V_10 -> V_25 -> V_131 . V_186 ;
V_181 . V_187 = F_76 ( V_10 ) ;
if ( V_179 ) {
if ( V_10 -> V_188 ) {
if ( V_10 -> V_188 -> V_189 & V_190 )
V_181 . V_191 = V_10 -> V_188 -> V_192 /
sizeof( V_193 ) ;
else
V_181 . V_191 = V_10 -> V_35 . V_194 ;
} else
V_181 . V_191 = 0 ;
} else {
if ( V_10 -> V_195 . V_189 & V_190 )
V_181 . V_191 = V_10 -> V_195 . V_192 /
sizeof( V_193 ) ;
else
V_181 . V_191 = V_10 -> V_35 . V_196 ;
}
F_77 ( V_10 , V_182 ) ;
if ( F_11 ( V_86 , & V_181 , sizeof( V_181 ) ) )
return - V_39 ;
return 0 ;
}
STATIC void
F_78 (
struct V_9 * V_10 ,
unsigned int V_162 )
{
unsigned int V_173 ;
V_173 = ( V_10 -> V_35 . V_173 & V_197 ) ;
if ( V_162 & V_164 )
V_173 |= V_174 ;
if ( V_162 & V_166 )
V_173 |= V_175 ;
if ( V_162 & V_168 )
V_173 |= V_176 ;
if ( V_162 & V_170 )
V_173 |= V_177 ;
if ( V_162 & V_172 )
V_173 |= V_178 ;
if ( V_162 & V_198 )
V_173 |= V_199 ;
if ( V_162 & V_200 )
V_173 |= V_201 ;
if ( V_162 & V_202 )
V_173 |= V_203 ;
if ( F_6 ( V_10 -> V_35 . V_204 ) ) {
if ( V_162 & V_205 )
V_173 |= V_206 ;
if ( V_162 & V_207 )
V_173 |= V_208 ;
if ( V_162 & V_209 )
V_173 |= V_210 ;
} else if ( F_5 ( V_10 -> V_35 . V_204 ) ) {
if ( V_162 & V_211 )
V_173 |= V_212 ;
if ( V_162 & V_213 )
V_173 |= V_214 ;
}
V_10 -> V_35 . V_173 = V_173 ;
}
STATIC void
F_79 (
struct V_9 * V_10 )
{
struct V_5 * V_5 = F_80 ( V_10 ) ;
unsigned int V_162 = F_75 ( V_10 ) ;
if ( V_162 & V_164 )
V_5 -> V_132 |= V_133 ;
else
V_5 -> V_132 &= ~ V_133 ;
if ( V_162 & V_166 )
V_5 -> V_132 |= V_134 ;
else
V_5 -> V_132 &= ~ V_134 ;
if ( V_162 & V_168 )
V_5 -> V_132 |= V_215 ;
else
V_5 -> V_132 &= ~ V_215 ;
if ( V_162 & V_170 )
V_5 -> V_132 |= V_216 ;
else
V_5 -> V_132 &= ~ V_216 ;
}
STATIC int
F_81 (
T_18 * V_10 ,
struct V_180 * V_181 ,
int V_217 )
{
struct V_218 * V_143 = V_10 -> V_25 ;
struct V_219 * V_220 ;
unsigned int V_221 = 0 ;
struct V_222 * V_223 = NULL ;
struct V_222 * V_224 = NULL ;
struct V_222 * V_225 = NULL ;
int V_226 ;
F_82 ( V_10 ) ;
if ( V_143 -> V_227 & V_228 )
return F_23 ( V_229 ) ;
if ( F_64 ( V_143 ) )
return F_23 ( V_148 ) ;
if ( ( V_217 & V_230 ) && ( V_181 -> V_187 > ( T_17 ) - 1 ) &&
! F_83 ( & V_10 -> V_25 -> V_131 ) )
return F_23 ( V_18 ) ;
if ( F_84 ( V_143 ) && ( V_217 & V_230 ) ) {
V_226 = F_85 ( V_10 , V_10 -> V_35 . V_231 ,
V_10 -> V_35 . V_232 , V_181 -> V_187 ,
V_233 , & V_223 , & V_224 ) ;
if ( V_226 )
return V_226 ;
}
V_220 = F_86 ( V_143 , V_234 ) ;
V_226 = F_87 ( V_220 , 0 , F_88 ( V_143 ) , 0 , 0 , 0 ) ;
if ( V_226 )
goto V_235;
V_221 = V_236 ;
F_74 ( V_10 , V_221 ) ;
if ( F_89 () != V_10 -> V_35 . V_231 && ! F_22 ( V_237 ) ) {
V_226 = F_23 ( V_62 ) ;
goto V_235;
}
if ( V_217 & V_230 ) {
if ( F_90 ( V_143 ) &&
F_91 ( V_143 ) &&
F_76 ( V_10 ) != V_181 -> V_187 ) {
ASSERT ( V_220 ) ;
V_226 = F_92 ( V_220 , V_10 , V_223 , V_224 ,
F_22 ( V_237 ) ?
V_238 : 0 ) ;
if ( V_226 )
goto V_235;
}
}
if ( V_217 & V_239 ) {
if ( V_10 -> V_35 . V_196 &&
( ( V_10 -> V_35 . V_185 << V_143 -> V_131 . V_186 ) !=
V_181 -> V_184 ) ) {
V_226 = F_23 ( V_18 ) ;
goto V_235;
}
if ( V_181 -> V_184 != 0 ) {
T_19 V_110 ;
T_20 V_240 ;
V_240 = F_93 ( V_143 , V_181 -> V_184 ) ;
if ( V_240 > V_241 ) {
V_226 = F_23 ( V_18 ) ;
goto V_235;
}
if ( F_94 ( V_10 ) ||
( ( V_217 & V_242 ) &&
( V_181 -> V_183 & V_211 ) ) ) {
V_110 = V_143 -> V_131 . V_243 <<
V_143 -> V_131 . V_186 ;
} else {
V_110 = V_143 -> V_131 . V_244 ;
if ( V_240 > V_143 -> V_131 . V_245 / 2 ) {
V_226 = F_23 ( V_18 ) ;
goto V_235;
}
}
if ( V_181 -> V_184 % V_110 ) {
V_226 = F_23 ( V_18 ) ;
goto V_235;
}
}
}
if ( V_217 & V_242 ) {
if ( ( V_10 -> V_35 . V_196 || V_10 -> V_246 ) &&
( F_94 ( V_10 ) ) !=
( V_181 -> V_183 & V_211 ) ) {
V_226 = F_23 ( V_18 ) ;
goto V_235;
}
if ( ( V_181 -> V_183 & V_211 ) ) {
if ( ( V_143 -> V_131 . V_247 == 0 ) ||
( V_143 -> V_131 . V_243 == 0 ) ||
( V_10 -> V_35 . V_185 % V_143 -> V_131 . V_243 ) ) {
V_226 = F_23 ( V_18 ) ;
goto V_235;
}
}
if ( ( V_10 -> V_35 . V_173 &
( V_174 | V_175 ) ||
( V_181 -> V_183 &
( V_164 | V_166 ) ) ) &&
! F_22 ( V_248 ) ) {
V_226 = F_23 ( V_62 ) ;
goto V_235;
}
}
F_95 ( V_220 , V_10 , 0 ) ;
if ( V_217 & V_230 ) {
if ( ( V_10 -> V_35 . V_204 & ( V_249 | V_250 ) ) &&
! F_22 ( V_251 ) )
V_10 -> V_35 . V_204 &= ~ ( V_249 | V_250 ) ;
if ( F_76 ( V_10 ) != V_181 -> V_187 ) {
if ( F_90 ( V_143 ) && F_91 ( V_143 ) ) {
V_225 = F_96 ( V_220 , V_10 ,
& V_10 -> V_252 , V_224 ) ;
}
F_97 ( V_10 , V_181 -> V_187 ) ;
if ( V_10 -> V_35 . V_253 == 1 )
F_98 ( V_220 , V_10 ) ;
}
}
if ( V_217 & V_239 )
V_10 -> V_35 . V_185 = V_181 -> V_184 >> V_143 -> V_131 . V_186 ;
if ( V_217 & V_242 ) {
F_78 ( V_10 , V_181 -> V_183 ) ;
F_79 ( V_10 ) ;
}
F_99 ( V_220 , V_10 , V_254 ) ;
F_100 ( V_220 , V_10 , V_255 ) ;
F_101 ( V_256 ) ;
if ( V_143 -> V_227 & V_257 )
F_102 ( V_220 ) ;
V_226 = F_103 ( V_220 , 0 ) ;
F_77 ( V_10 , V_221 ) ;
F_104 ( V_225 ) ;
F_104 ( V_223 ) ;
F_104 ( V_224 ) ;
return V_226 ;
V_235:
F_104 ( V_223 ) ;
F_104 ( V_224 ) ;
F_105 ( V_220 , 0 ) ;
if ( V_221 )
F_77 ( V_10 , V_221 ) ;
return V_226 ;
}
STATIC int
F_106 (
T_18 * V_10 ,
struct V_12 * V_59 ,
void V_17 * V_86 )
{
struct V_180 V_181 ;
unsigned int V_217 ;
int error ;
if ( F_17 ( & V_181 , V_86 , sizeof( V_181 ) ) )
return - V_39 ;
V_217 = V_242 | V_239 | V_230 ;
if ( V_59 -> V_72 & ( V_135 | V_136 ) )
V_217 |= V_258 ;
error = F_40 ( V_59 ) ;
if ( error )
return error ;
error = F_81 ( V_10 , & V_181 , V_217 ) ;
F_41 ( V_59 ) ;
return - error ;
}
STATIC int
F_107 (
T_18 * V_10 ,
void V_17 * V_86 )
{
unsigned int V_98 ;
V_98 = F_72 ( V_10 -> V_35 . V_173 ) ;
if ( F_11 ( V_86 , & V_98 , sizeof( V_98 ) ) )
return - V_39 ;
return 0 ;
}
STATIC int
F_108 (
T_18 * V_10 ,
struct V_12 * V_59 ,
void V_17 * V_86 )
{
struct V_180 V_181 ;
unsigned int V_98 ;
unsigned int V_217 ;
int error ;
if ( F_17 ( & V_98 , V_86 , sizeof( V_98 ) ) )
return - V_39 ;
if ( V_98 & ~ ( V_163 | V_165 | \
V_169 | V_171 | \
V_167 ) )
return - V_259 ;
V_217 = V_242 ;
if ( V_59 -> V_72 & ( V_135 | V_136 ) )
V_217 |= V_258 ;
V_181 . V_183 = F_71 ( V_98 , F_75 ( V_10 ) ) ;
error = F_40 ( V_59 ) ;
if ( error )
return error ;
error = F_81 ( V_10 , & V_181 , V_217 ) ;
F_41 ( V_59 ) ;
return - error ;
}
STATIC int
F_109 ( void * * V_260 , struct V_261 * V_262 , int * V_263 )
{
struct V_264 V_17 * V_265 = * V_260 ;
if ( F_11 ( V_265 , V_262 , sizeof( struct V_264 ) ) )
return F_23 ( V_39 ) ;
* V_260 += sizeof( struct V_264 ) ;
return 0 ;
}
STATIC int
F_110 (
struct V_9 * V_10 ,
int V_128 ,
unsigned int V_1 ,
void V_17 * V_86 )
{
struct V_261 V_266 ;
int error ;
if ( F_17 ( & V_266 , V_86 , sizeof( struct V_261 ) ) )
return - F_23 ( V_39 ) ;
if ( V_266 . V_267 < 2 )
return - F_23 ( V_18 ) ;
V_266 . V_268 = ( V_1 == V_269 ? V_270 : 0 ) ;
if ( V_128 & V_140 )
V_266 . V_268 |= V_271 ;
error = F_111 ( V_10 , & V_266 , F_109 ,
(struct V_264 * ) V_86 + 1 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_266 , sizeof( struct V_264 ) ) )
return - F_23 ( V_39 ) ;
return 0 ;
}
STATIC int
F_112 ( void * * V_260 , struct V_261 * V_262 , int * V_263 )
{
struct V_261 V_17 * V_265 = * V_260 ;
if ( F_11 ( V_265 , V_262 , sizeof( struct V_261 ) ) )
return F_23 ( V_39 ) ;
* V_260 += sizeof( struct V_261 ) ;
return 0 ;
}
STATIC int
F_113 (
struct V_9 * V_10 ,
void V_17 * V_86 )
{
struct V_261 V_266 ;
int error ;
if ( F_17 ( & V_266 , V_86 , sizeof( V_266 ) ) )
return - F_23 ( V_39 ) ;
if ( V_266 . V_267 < 2 )
return - F_23 ( V_18 ) ;
if ( V_266 . V_268 & ( ~ V_272 ) )
return - F_23 ( V_18 ) ;
error = F_111 ( V_10 , & V_266 , F_112 ,
(struct V_261 * ) V_86 + 1 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_266 , sizeof( struct V_261 ) ) )
return - F_23 ( V_39 ) ;
return 0 ;
}
long
F_114 (
struct V_12 * V_59 ,
unsigned int V_1 ,
unsigned long V_273 )
{
struct V_5 * V_5 = V_59 -> V_14 . V_15 -> V_16 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_218 * V_143 = V_10 -> V_25 ;
void V_17 * V_86 = ( void V_17 * ) V_273 ;
int V_128 = 0 ;
int error ;
if ( V_59 -> V_74 & V_75 )
V_128 |= V_140 ;
F_115 ( V_10 ) ;
switch ( V_1 ) {
case V_274 :
return F_116 ( V_143 , V_86 ) ;
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 : {
T_12 V_129 ;
if ( F_17 ( & V_129 , V_86 , sizeof( V_129 ) ) )
return - F_23 ( V_39 ) ;
return F_60 ( V_10 , V_5 , V_59 , V_128 , V_1 , & V_129 ) ;
}
case V_284 : {
struct V_285 V_286 ;
T_21 * V_287 =
F_94 ( V_10 ) ?
V_143 -> V_288 : V_143 -> V_289 ;
V_286 . V_290 = V_286 . V_291 = 1 << V_287 -> V_292 ;
V_286 . V_293 = V_113 & ~ ( V_286 . V_291 - 1 ) ;
if ( F_11 ( V_86 , & V_286 , sizeof( V_286 ) ) )
return - F_23 ( V_39 ) ;
return 0 ;
}
case V_155 :
case V_294 :
case V_153 :
return F_63 ( V_143 , V_1 , V_86 ) ;
case V_295 :
return F_68 ( V_143 , V_86 ) ;
case V_296 :
return F_70 ( V_143 , V_86 ) ;
case V_297 :
return F_117 ( V_5 -> V_298 , ( int V_17 * ) V_86 ) ;
case V_299 :
return F_73 ( V_10 , 0 , V_86 ) ;
case V_300 :
return F_73 ( V_10 , 1 , V_86 ) ;
case V_301 :
return F_106 ( V_10 , V_59 , V_86 ) ;
case V_302 :
return F_107 ( V_10 , V_86 ) ;
case V_303 :
return F_108 ( V_10 , V_59 , V_86 ) ;
case V_304 : {
struct V_87 V_305 ;
if ( F_17 ( & V_305 , V_86 , sizeof( V_305 ) ) )
return - F_23 ( V_39 ) ;
error = F_40 ( V_59 ) ;
if ( error )
return error ;
error = F_42 ( V_10 , V_305 . V_92 ,
V_305 . V_93 ) ;
F_41 ( V_59 ) ;
return - error ;
}
case V_306 :
case V_269 :
return F_110 ( V_10 , V_128 , V_1 , V_86 ) ;
case V_307 :
return F_113 ( V_10 , V_86 ) ;
case V_11 :
case V_308 :
case V_28 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_86 , sizeof( V_2 ) ) )
return - F_23 ( V_39 ) ;
return F_1 ( V_1 , & V_2 ) ;
}
case V_309 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_86 , sizeof( T_1 ) ) )
return - F_23 ( V_39 ) ;
return F_20 ( V_59 , & V_2 ) ;
}
case V_310 :
return F_39 ( V_59 , V_86 ) ;
case V_311 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_86 , sizeof( T_1 ) ) )
return - F_23 ( V_39 ) ;
return F_35 ( V_59 , & V_2 ) ;
}
case V_312 :
return F_43 ( V_59 , V_86 ) ;
case V_313 :
return F_58 ( V_59 , V_86 ) ;
case V_314 : {
struct V_315 V_316 ;
if ( F_17 ( & V_316 , V_86 , sizeof( V_317 ) ) )
return - F_23 ( V_39 ) ;
error = F_40 ( V_59 ) ;
if ( error )
return error ;
error = V_315 ( & V_316 ) ;
F_41 ( V_59 ) ;
return - error ;
}
case V_318 : {
T_22 V_80 ;
error = F_118 ( V_143 , & V_80 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_80 , sizeof( V_80 ) ) )
return - F_23 ( V_39 ) ;
return 0 ;
}
case V_319 : {
T_23 V_320 ;
T_24 V_321 ;
if ( ! F_22 ( V_61 ) )
return - V_62 ;
if ( V_143 -> V_227 & V_228 )
return - F_23 ( V_229 ) ;
if ( F_17 ( & V_320 , V_86 , sizeof( V_320 ) ) )
return - F_23 ( V_39 ) ;
error = F_40 ( V_59 ) ;
if ( error )
return error ;
V_321 = V_320 . V_322 ;
error = F_119 ( V_143 , & V_321 , & V_320 ) ;
F_41 ( V_59 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_320 , sizeof( V_320 ) ) )
return - F_23 ( V_39 ) ;
return 0 ;
}
case V_323 : {
T_23 V_80 ;
if ( ! F_22 ( V_61 ) )
return - V_62 ;
error = F_119 ( V_143 , NULL , & V_80 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_80 , sizeof( V_80 ) ) )
return - F_23 ( V_39 ) ;
return 0 ;
}
case V_324 : {
T_25 V_321 ;
if ( F_17 ( & V_321 , V_86 , sizeof( V_321 ) ) )
return - F_23 ( V_39 ) ;
error = F_40 ( V_59 ) ;
if ( error )
return error ;
error = F_120 ( V_143 , & V_321 ) ;
F_41 ( V_59 ) ;
return - error ;
}
case V_325 : {
T_26 V_321 ;
if ( F_17 ( & V_321 , V_86 , sizeof( V_321 ) ) )
return - F_23 ( V_39 ) ;
error = F_40 ( V_59 ) ;
if ( error )
return error ;
error = F_121 ( V_143 , & V_321 ) ;
F_41 ( V_59 ) ;
return - error ;
}
case V_326 : {
T_27 V_321 ;
if ( F_17 ( & V_321 , V_86 , sizeof( V_321 ) ) )
return - F_23 ( V_39 ) ;
error = F_40 ( V_59 ) ;
if ( error )
return error ;
error = F_122 ( V_143 , & V_321 ) ;
F_41 ( V_59 ) ;
return - error ;
}
case V_327 : {
T_9 V_321 ;
if ( ! F_22 ( V_61 ) )
return - V_62 ;
if ( F_123 ( V_321 , ( T_9 V_17 * ) V_86 ) )
return - F_23 ( V_39 ) ;
error = F_124 ( V_143 , V_321 ) ;
return - error ;
}
case V_328 : {
T_28 V_321 ;
if ( ! F_22 ( V_61 ) )
return - V_62 ;
if ( F_17 ( & V_321 , V_86 , sizeof( V_321 ) ) )
return - F_23 ( V_39 ) ;
error = F_125 ( V_321 . V_329 , V_143 ) ;
return - error ;
}
case V_330 :
if ( ! F_22 ( V_61 ) )
return - V_62 ;
error = F_126 ( V_143 , 1 ) ;
return - error ;
case V_331 : {
struct V_332 V_333 ;
if ( F_17 ( & V_333 , V_86 , sizeof( V_333 ) ) )
return - F_23 ( V_39 ) ;
if ( V_333 . V_334 != V_335 )
return - F_23 ( V_18 ) ;
if ( V_333 . V_336 & ~ V_337 )
return - F_23 ( V_18 ) ;
if ( F_127 ( & V_333 . V_338 , 0 , sizeof( V_333 . V_338 ) ) ||
F_127 ( V_333 . V_339 , 0 , sizeof( V_333 . V_339 ) ) )
return - F_23 ( V_18 ) ;
error = F_128 ( V_143 , & V_333 ) ;
return - error ;
}
default:
return - V_340 ;
}
}
