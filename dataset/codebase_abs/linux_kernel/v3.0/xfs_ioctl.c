int
F_1 (
unsigned int V_1 ,
T_1 * V_2 )
{
int V_3 ;
T_2 V_4 ;
struct V_5 * V_5 ;
struct V_6 * V_6 = NULL ;
struct V_7 V_7 ;
int error ;
struct V_8 * V_9 ;
if ( V_1 == V_10 ) {
V_6 = F_2 ( V_2 -> V_11 ) ;
if ( ! V_6 )
return - V_12 ;
V_5 = V_6 -> V_13 . V_14 -> V_15 ;
} else {
error = F_3 ( ( const char V_16 * ) V_2 -> V_7 , & V_7 ) ;
if ( error )
return error ;
V_5 = V_7 . V_14 -> V_15 ;
}
V_9 = F_4 ( V_5 ) ;
error = - V_17 ;
if ( V_5 -> V_18 -> V_19 != V_20 )
goto V_21;
error = - V_12 ;
if ( ! F_5 ( V_5 -> V_22 ) &&
! F_6 ( V_5 -> V_22 ) &&
! F_7 ( V_5 -> V_22 ) )
goto V_21;
memcpy ( & V_4 . V_23 , V_9 -> V_24 -> V_25 , sizeof( V_26 ) ) ;
if ( V_1 == V_27 ) {
memset ( & V_4 . V_28 , 0 , sizeof( V_4 . V_28 ) ) ;
V_3 = sizeof( V_26 ) ;
} else {
int V_29 ;
V_29 = F_8 ( V_9 ) ;
V_4 . V_28 . V_30 = sizeof( V_31 ) -
sizeof( V_4 . V_28 . V_30 ) ;
V_4 . V_28 . V_32 = 0 ;
V_4 . V_28 . V_33 = V_9 -> V_34 . V_35 ;
V_4 . V_28 . V_36 = V_9 -> V_37 ;
F_9 ( V_9 , V_29 ) ;
V_3 = F_10 ( V_4 ) ;
}
error = - V_38 ;
if ( F_11 ( V_2 -> V_39 , & V_4 , V_3 ) ||
F_11 ( V_2 -> V_40 , & V_3 , sizeof( V_41 ) ) )
goto V_21;
error = 0 ;
V_21:
if ( V_1 == V_10 )
F_12 ( V_6 ) ;
else
F_13 ( & V_7 ) ;
return error ;
}
STATIC int
F_14 (
void * V_42 ,
struct V_14 * V_14 )
{
return 1 ;
}
struct V_14 *
F_15 (
struct V_6 * V_43 ,
void V_16 * V_44 ,
T_3 V_45 )
{
T_2 V_4 ;
struct V_46 V_47 ;
if ( ! F_6 ( V_43 -> V_13 . V_14 -> V_15 -> V_22 ) )
return F_16 ( - V_48 ) ;
if ( V_45 != sizeof( T_2 ) )
return F_16 ( - V_17 ) ;
if ( F_17 ( & V_4 , V_44 , V_45 ) )
return F_16 ( - V_38 ) ;
if ( V_4 . V_28 . V_30 !=
sizeof( V_4 . V_28 ) - sizeof( V_4 . V_28 . V_30 ) )
return F_16 ( - V_17 ) ;
memset ( & V_47 , 0 , sizeof( struct V_47 ) ) ;
V_47 . V_49 = V_4 . V_28 . V_36 ;
V_47 . V_50 = V_4 . V_28 . V_33 ;
return F_18 ( V_43 -> V_13 . V_51 , (struct V_47 * ) & V_47 , 3 ,
V_52 | V_53 ,
F_14 , NULL ) ;
}
STATIC struct V_14 *
F_19 (
struct V_6 * V_43 ,
T_1 * V_2 )
{
return F_15 ( V_43 , V_2 -> V_54 , V_2 -> V_55 ) ;
}
int
F_20 (
struct V_6 * V_43 ,
T_1 * V_2 )
{
const struct V_56 * V_56 = F_21 () ;
int error ;
int V_11 ;
int V_57 ;
struct V_6 * V_58 ;
struct V_5 * V_5 ;
struct V_14 * V_14 ;
if ( ! F_22 ( V_59 ) )
return - F_23 ( V_60 ) ;
V_14 = F_19 ( V_43 , V_2 ) ;
if ( F_24 ( V_14 ) )
return F_25 ( V_14 ) ;
V_5 = V_14 -> V_15 ;
if ( ! ( F_5 ( V_5 -> V_22 ) || F_6 ( V_5 -> V_22 ) ) ) {
error = - F_23 ( V_60 ) ;
goto V_61;
}
#if V_62 != 32
V_2 -> V_63 |= V_64 ;
#endif
V_57 = V_2 -> V_63 ;
if ( ( V_57 + 1 ) & V_65 )
V_57 ++ ;
if ( V_57 & V_66 )
V_57 |= 2 ;
if ( ( ! ( V_57 & V_67 ) || ( V_57 & V_66 ) ) &&
( V_57 & V_68 ) && F_26 ( V_5 ) ) {
error = - F_23 ( V_60 ) ;
goto V_61;
}
if ( ( V_57 & V_68 ) && F_27 ( V_5 ) ) {
error = - F_23 ( V_69 ) ;
goto V_61;
}
if ( F_6 ( V_5 -> V_22 ) && ( V_57 & V_68 ) ) {
error = - F_23 ( V_70 ) ;
goto V_61;
}
V_11 = F_28 () ;
if ( V_11 < 0 ) {
error = V_11 ;
goto V_61;
}
V_58 = F_29 ( V_14 , F_30 ( V_43 -> V_13 . V_51 ) ,
V_2 -> V_63 , V_56 ) ;
if ( F_24 ( V_58 ) ) {
F_31 ( V_11 ) ;
return F_25 ( V_58 ) ;
}
if ( V_5 -> V_22 & V_71 ) {
V_58 -> V_72 |= V_73 ;
V_58 -> V_74 |= V_75 ;
}
F_32 ( V_11 , V_58 ) ;
return V_11 ;
V_61:
F_33 ( V_14 ) ;
return error ;
}
STATIC int
F_34 (
char V_16 * V_76 ,
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
V_79 = - V_38 ;
V_80:
return V_79 ;
}
int
F_35 (
struct V_6 * V_43 ,
T_1 * V_2 )
{
struct V_14 * V_14 ;
T_4 V_81 ;
void * V_78 ;
int error ;
if ( ! F_22 ( V_59 ) )
return - F_23 ( V_60 ) ;
V_14 = F_19 ( V_43 , V_2 ) ;
if ( F_24 ( V_14 ) )
return F_25 ( V_14 ) ;
if ( ! F_7 ( V_14 -> V_15 -> V_22 ) ) {
error = - F_23 ( V_17 ) ;
goto V_61;
}
if ( F_17 ( & V_81 , V_2 -> V_40 , sizeof( T_4 ) ) ) {
error = - F_23 ( V_38 ) ;
goto V_61;
}
V_78 = F_36 ( V_82 + 1 , V_83 ) ;
if ( ! V_78 ) {
error = - F_23 ( V_84 ) ;
goto V_61;
}
error = - F_37 ( F_4 ( V_14 -> V_15 ) , V_78 ) ;
if ( error )
goto V_85;
error = F_34 ( V_2 -> V_39 , V_81 , V_78 ) ;
if ( error )
goto V_85;
V_85:
F_38 ( V_78 ) ;
V_61:
F_33 ( V_14 ) ;
return error ;
}
STATIC int
F_39 (
struct V_6 * V_43 ,
void V_16 * V_86 )
{
int error ;
struct V_87 V_88 ;
T_5 V_89 ;
struct V_14 * V_14 ;
if ( ! F_22 ( V_90 ) )
return - F_23 ( V_60 ) ;
if ( F_17 ( & V_89 , V_86 , sizeof( T_5 ) ) )
return - F_23 ( V_38 ) ;
V_14 = F_19 ( V_43 , & V_89 . V_2 ) ;
if ( F_24 ( V_14 ) )
return F_25 ( V_14 ) ;
if ( F_27 ( V_14 -> V_15 ) || F_26 ( V_14 -> V_15 ) ) {
error = - F_23 ( V_60 ) ;
goto V_80;
}
if ( F_17 ( & V_88 , V_89 . V_91 , sizeof( V_88 ) ) ) {
error = - F_23 ( V_38 ) ;
goto V_80;
}
error = - F_40 ( F_4 ( V_14 -> V_15 ) , V_88 . V_92 ,
V_88 . V_93 ) ;
V_80:
F_33 ( V_14 ) ;
return error ;
}
STATIC int
F_41 (
struct V_6 * V_43 ,
void V_16 * V_86 )
{
int error = - V_84 ;
T_6 * V_94 ;
T_7 V_95 ;
struct V_14 * V_14 ;
char * V_96 ;
if ( ! F_22 ( V_59 ) )
return - F_23 ( V_60 ) ;
if ( F_17 ( & V_95 , V_86 , sizeof( T_7 ) ) )
return - F_23 ( V_38 ) ;
if ( V_95 . V_77 > V_97 )
return - F_23 ( V_17 ) ;
if ( V_95 . V_98 & ~ ( V_99 | V_100 ) )
return - F_23 ( V_17 ) ;
V_14 = F_19 ( V_43 , & V_95 . V_2 ) ;
if ( F_24 ( V_14 ) )
return F_25 ( V_14 ) ;
V_96 = F_42 ( V_95 . V_77 , V_83 ) ;
if ( ! V_96 )
goto V_61;
V_94 = ( T_6 * ) & V_95 . V_101 ;
error = - F_43 ( F_4 ( V_14 -> V_15 ) , V_96 , V_95 . V_77 ,
V_95 . V_98 , V_94 ) ;
if ( error )
goto V_85;
if ( F_11 ( V_95 . V_76 , V_96 , V_95 . V_77 ) )
error = - V_38 ;
V_85:
F_38 ( V_96 ) ;
V_61:
F_33 ( V_14 ) ;
return error ;
}
int
F_44 (
struct V_5 * V_5 ,
unsigned char * V_102 ,
unsigned char V_16 * V_103 ,
T_8 * V_79 ,
T_8 V_98 )
{
unsigned char * V_96 ;
int error = V_38 ;
if ( * V_79 > V_104 )
return V_17 ;
V_96 = F_36 ( * V_79 , V_83 ) ;
if ( ! V_96 )
return V_84 ;
error = F_45 ( F_4 ( V_5 ) , V_102 , V_96 , ( int * ) V_79 , V_98 ) ;
if ( error )
goto V_85;
if ( F_11 ( V_103 , V_96 , * V_79 ) )
error = V_38 ;
V_85:
F_38 ( V_96 ) ;
return error ;
}
int
F_46 (
struct V_5 * V_5 ,
unsigned char * V_102 ,
const unsigned char V_16 * V_103 ,
T_8 V_79 ,
T_8 V_98 )
{
unsigned char * V_96 ;
int error = V_38 ;
if ( F_27 ( V_5 ) || F_26 ( V_5 ) )
return V_60 ;
if ( V_79 > V_104 )
return V_17 ;
V_96 = F_47 ( V_103 , V_79 ) ;
if ( F_24 ( V_96 ) )
return F_25 ( V_96 ) ;
error = F_48 ( F_4 ( V_5 ) , V_102 , V_96 , V_79 , V_98 ) ;
return error ;
}
int
F_49 (
struct V_5 * V_5 ,
unsigned char * V_102 ,
T_8 V_98 )
{
if ( F_27 ( V_5 ) || F_26 ( V_5 ) )
return V_60 ;
return F_50 ( F_4 ( V_5 ) , V_102 , V_98 ) ;
}
STATIC int
F_51 (
struct V_6 * V_43 ,
void V_16 * V_86 )
{
int error ;
T_9 * V_105 ;
T_10 V_106 ;
struct V_14 * V_14 ;
unsigned int V_107 , V_108 ;
unsigned char * V_109 ;
if ( ! F_22 ( V_59 ) )
return - F_23 ( V_60 ) ;
if ( F_17 ( & V_106 , V_86 , sizeof( T_10 ) ) )
return - F_23 ( V_38 ) ;
if ( V_106 . V_110 >= V_111 / sizeof( T_9 ) )
return - V_112 ;
V_14 = F_19 ( V_43 , & V_106 . V_2 ) ;
if ( F_24 ( V_14 ) )
return F_25 ( V_14 ) ;
error = V_112 ;
V_108 = V_106 . V_110 * sizeof( T_9 ) ;
if ( ! V_108 || V_108 > 16 * V_113 )
goto V_61;
V_105 = F_47 ( V_106 . V_105 , V_108 ) ;
if ( F_24 ( V_105 ) ) {
error = F_25 ( V_105 ) ;
goto V_61;
}
V_109 = F_36 ( V_114 , V_83 ) ;
if ( ! V_109 )
goto V_115;
error = 0 ;
for ( V_107 = 0 ; V_107 < V_106 . V_110 ; V_107 ++ ) {
V_105 [ V_107 ] . V_116 = F_52 ( ( char * ) V_109 ,
V_105 [ V_107 ] . V_117 , V_114 ) ;
if ( V_105 [ V_107 ] . V_116 == 0 || V_105 [ V_107 ] . V_116 == V_114 )
error = - V_118 ;
if ( V_105 [ V_107 ] . V_116 < 0 )
break;
switch ( V_105 [ V_107 ] . V_119 ) {
case V_120 :
V_105 [ V_107 ] . V_116 = F_44 (
V_14 -> V_15 , V_109 ,
V_105 [ V_107 ] . V_121 , & V_105 [ V_107 ] . V_122 ,
V_105 [ V_107 ] . V_123 ) ;
break;
case V_124 :
V_105 [ V_107 ] . V_116 = F_53 ( V_43 -> V_13 . V_51 ) ;
if ( V_105 [ V_107 ] . V_116 )
break;
V_105 [ V_107 ] . V_116 = F_46 (
V_14 -> V_15 , V_109 ,
V_105 [ V_107 ] . V_121 , V_105 [ V_107 ] . V_122 ,
V_105 [ V_107 ] . V_123 ) ;
F_54 ( V_43 -> V_13 . V_51 ) ;
break;
case V_125 :
V_105 [ V_107 ] . V_116 = F_53 ( V_43 -> V_13 . V_51 ) ;
if ( V_105 [ V_107 ] . V_116 )
break;
V_105 [ V_107 ] . V_116 = F_49 (
V_14 -> V_15 , V_109 ,
V_105 [ V_107 ] . V_123 ) ;
F_54 ( V_43 -> V_13 . V_51 ) ;
break;
default:
V_105 [ V_107 ] . V_116 = V_17 ;
}
}
if ( F_11 ( V_106 . V_105 , V_105 , V_108 ) )
error = F_23 ( V_38 ) ;
F_38 ( V_109 ) ;
V_115:
F_38 ( V_105 ) ;
V_61:
F_33 ( V_14 ) ;
return - error ;
}
int
F_55 (
struct V_8 * V_9 ,
struct V_5 * V_5 ,
struct V_6 * V_58 ,
int V_126 ,
unsigned int V_1 ,
T_11 * V_127 )
{
int V_128 = 0 ;
int error ;
if ( ! F_56 ( & V_9 -> V_24 -> V_129 ) &&
! F_22 ( V_59 ) )
return - F_23 ( V_60 ) ;
if ( V_5 -> V_130 & ( V_131 | V_132 ) )
return - F_23 ( V_60 ) ;
if ( ! ( V_58 -> V_74 & V_68 ) )
return - F_23 ( V_12 ) ;
if ( ! F_5 ( V_5 -> V_22 ) )
return - F_23 ( V_17 ) ;
if ( V_58 -> V_72 & ( V_133 | V_134 ) )
V_128 |= V_135 ;
if ( V_58 -> V_72 & V_136 )
V_128 |= V_137 ;
if ( V_126 & V_138 )
V_128 |= V_139 ;
error = F_57 ( V_9 , V_1 , V_127 , V_58 -> V_140 , V_128 ) ;
return - error ;
}
STATIC int
F_58 (
T_12 * V_141 ,
unsigned int V_1 ,
void V_16 * V_86 )
{
T_13 V_142 ;
int V_143 ;
T_14 V_144 ;
int V_145 ;
int error ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( F_59 ( V_141 ) )
return - F_23 ( V_146 ) ;
if ( F_17 ( & V_142 , V_86 , sizeof( T_13 ) ) )
return - F_23 ( V_38 ) ;
if ( F_17 ( & V_144 , V_142 . V_147 , sizeof( V_148 ) ) )
return - F_23 ( V_38 ) ;
if ( ( V_143 = V_142 . V_149 ) <= 0 )
return - F_23 ( V_17 ) ;
if ( V_142 . V_150 == NULL )
return - F_23 ( V_17 ) ;
if ( V_1 == V_151 )
error = F_60 ( V_141 , & V_144 , & V_143 ,
V_142 . V_150 , V_152 ) ;
else if ( V_1 == V_153 )
error = F_61 ( V_141 , & V_144 ,
V_142 . V_150 , & V_145 ) ;
else
error = F_62 ( V_141 , & V_144 , & V_143 , V_154 ,
sizeof( V_155 ) , V_142 . V_150 ,
& V_145 ) ;
if ( error )
return - error ;
if ( V_142 . V_156 != NULL ) {
if ( F_11 ( V_142 . V_147 , & V_144 ,
sizeof( T_14 ) ) )
return - F_23 ( V_38 ) ;
if ( F_11 ( V_142 . V_156 , & V_143 , sizeof( V_143 ) ) )
return - F_23 ( V_38 ) ;
}
return 0 ;
}
STATIC int
F_63 (
T_12 * V_141 ,
void V_16 * V_86 )
{
T_15 V_157 ;
int error ;
error = F_64 ( V_141 , & V_157 , 3 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_157 , sizeof( V_158 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
STATIC int
F_65 (
T_12 * V_141 ,
void V_16 * V_86 )
{
T_15 V_157 ;
int error ;
error = F_64 ( V_141 , & V_157 , 4 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_157 , sizeof( V_157 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
STATIC unsigned int
F_66 (
unsigned int V_98 ,
unsigned int V_159 )
{
unsigned int V_160 = V_159 ;
if ( V_98 & V_161 )
V_160 |= V_162 ;
else
V_160 &= ~ V_162 ;
if ( V_98 & V_163 )
V_160 |= V_164 ;
else
V_160 &= ~ V_164 ;
if ( V_98 & V_165 )
V_160 |= V_166 ;
else
V_160 &= ~ V_166 ;
if ( V_98 & V_167 )
V_160 |= V_168 ;
else
V_160 &= ~ V_168 ;
if ( V_98 & V_169 )
V_160 |= V_170 ;
else
V_160 &= ~ V_170 ;
return V_160 ;
}
STATIC unsigned int
F_67 (
T_16 V_171 )
{
unsigned int V_98 = 0 ;
if ( V_171 & V_172 )
V_98 |= V_161 ;
if ( V_171 & V_173 )
V_98 |= V_163 ;
if ( V_171 & V_174 )
V_98 |= V_165 ;
if ( V_171 & V_175 )
V_98 |= V_167 ;
if ( V_171 & V_176 )
V_98 |= V_169 ;
return V_98 ;
}
STATIC int
F_68 (
T_17 * V_9 ,
int V_177 ,
void V_16 * V_86 )
{
struct V_178 V_179 ;
memset ( & V_179 , 0 , sizeof( struct V_178 ) ) ;
F_69 ( V_9 , V_180 ) ;
V_179 . V_181 = F_70 ( V_9 ) ;
V_179 . V_182 = V_9 -> V_34 . V_183 << V_9 -> V_24 -> V_129 . V_184 ;
V_179 . V_185 = F_71 ( V_9 ) ;
if ( V_177 ) {
if ( V_9 -> V_186 ) {
if ( V_9 -> V_186 -> V_187 & V_188 )
V_179 . V_189 = V_9 -> V_186 -> V_190 /
sizeof( V_191 ) ;
else
V_179 . V_189 = V_9 -> V_34 . V_192 ;
} else
V_179 . V_189 = 0 ;
} else {
if ( V_9 -> V_193 . V_187 & V_188 )
V_179 . V_189 = V_9 -> V_193 . V_190 /
sizeof( V_191 ) ;
else
V_179 . V_189 = V_9 -> V_34 . V_194 ;
}
F_72 ( V_9 , V_180 ) ;
if ( F_11 ( V_86 , & V_179 , sizeof( V_179 ) ) )
return - V_38 ;
return 0 ;
}
STATIC void
F_73 (
struct V_8 * V_9 ,
unsigned int V_160 )
{
unsigned int V_171 ;
V_171 = ( V_9 -> V_34 . V_171 & V_195 ) ;
if ( V_160 & V_162 )
V_171 |= V_172 ;
if ( V_160 & V_164 )
V_171 |= V_173 ;
if ( V_160 & V_166 )
V_171 |= V_174 ;
if ( V_160 & V_168 )
V_171 |= V_175 ;
if ( V_160 & V_170 )
V_171 |= V_176 ;
if ( V_160 & V_196 )
V_171 |= V_197 ;
if ( V_160 & V_198 )
V_171 |= V_199 ;
if ( V_160 & V_200 )
V_171 |= V_201 ;
if ( ( V_9 -> V_34 . V_202 & V_203 ) == V_204 ) {
if ( V_160 & V_205 )
V_171 |= V_206 ;
if ( V_160 & V_207 )
V_171 |= V_208 ;
if ( V_160 & V_209 )
V_171 |= V_210 ;
} else if ( ( V_9 -> V_34 . V_202 & V_203 ) == V_71 ) {
if ( V_160 & V_211 )
V_171 |= V_212 ;
if ( V_160 & V_213 )
V_171 |= V_214 ;
}
V_9 -> V_34 . V_171 = V_171 ;
}
STATIC void
F_74 (
struct V_8 * V_9 )
{
struct V_5 * V_5 = F_75 ( V_9 ) ;
unsigned int V_160 = F_70 ( V_9 ) ;
if ( V_160 & V_162 )
V_5 -> V_130 |= V_131 ;
else
V_5 -> V_130 &= ~ V_131 ;
if ( V_160 & V_164 )
V_5 -> V_130 |= V_132 ;
else
V_5 -> V_130 &= ~ V_132 ;
if ( V_160 & V_166 )
V_5 -> V_130 |= V_215 ;
else
V_5 -> V_130 &= ~ V_215 ;
if ( V_160 & V_168 )
V_5 -> V_130 |= V_216 ;
else
V_5 -> V_130 &= ~ V_216 ;
}
STATIC int
F_76 (
T_17 * V_9 ,
struct V_178 * V_179 ,
int V_217 )
{
struct V_218 * V_141 = V_9 -> V_24 ;
struct V_219 * V_220 ;
unsigned int V_221 = 0 ;
struct V_222 * V_223 = NULL ;
struct V_222 * V_224 = NULL ;
struct V_222 * V_225 = NULL ;
int V_226 ;
F_77 ( V_9 ) ;
if ( V_141 -> V_227 & V_228 )
return F_23 ( V_229 ) ;
if ( F_59 ( V_141 ) )
return F_23 ( V_146 ) ;
if ( ( V_217 & V_230 ) && ( V_179 -> V_185 > ( T_16 ) - 1 ) &&
! F_78 ( & V_9 -> V_24 -> V_129 ) )
return F_23 ( V_17 ) ;
if ( F_79 ( V_141 ) && ( V_217 & V_230 ) ) {
V_226 = F_80 ( V_9 , V_9 -> V_34 . V_231 ,
V_9 -> V_34 . V_232 , V_179 -> V_185 ,
V_233 , & V_223 , & V_224 ) ;
if ( V_226 )
return V_226 ;
}
V_220 = F_81 ( V_141 , V_234 ) ;
V_226 = F_82 ( V_220 , 0 , F_83 ( V_141 ) , 0 , 0 , 0 ) ;
if ( V_226 )
goto V_235;
V_221 = V_236 ;
F_69 ( V_9 , V_221 ) ;
if ( F_84 () != V_9 -> V_34 . V_231 && ! F_22 ( V_237 ) ) {
V_226 = F_23 ( V_60 ) ;
goto V_235;
}
if ( V_217 & V_230 ) {
if ( F_85 ( V_141 ) &&
F_86 ( V_141 ) &&
F_71 ( V_9 ) != V_179 -> V_185 ) {
ASSERT ( V_220 ) ;
V_226 = F_87 ( V_220 , V_9 , V_223 , V_224 ,
F_22 ( V_237 ) ?
V_238 : 0 ) ;
if ( V_226 )
goto V_235;
}
}
if ( V_217 & V_239 ) {
if ( V_9 -> V_34 . V_194 &&
( ( V_9 -> V_34 . V_183 << V_141 -> V_129 . V_184 ) !=
V_179 -> V_182 ) ) {
V_226 = F_23 ( V_17 ) ;
goto V_235;
}
if ( V_179 -> V_182 != 0 ) {
T_18 V_108 ;
T_19 V_240 ;
V_240 = F_88 ( V_141 , V_179 -> V_182 ) ;
if ( V_240 > V_241 ) {
V_226 = F_23 ( V_17 ) ;
goto V_235;
}
if ( F_89 ( V_9 ) ||
( ( V_217 & V_242 ) &&
( V_179 -> V_181 & V_211 ) ) ) {
V_108 = V_141 -> V_129 . V_243 <<
V_141 -> V_129 . V_184 ;
} else {
V_108 = V_141 -> V_129 . V_244 ;
if ( V_240 > V_141 -> V_129 . V_245 / 2 ) {
V_226 = F_23 ( V_17 ) ;
goto V_235;
}
}
if ( V_179 -> V_182 % V_108 ) {
V_226 = F_23 ( V_17 ) ;
goto V_235;
}
}
}
if ( V_217 & V_242 ) {
if ( ( V_9 -> V_34 . V_194 || V_9 -> V_246 ) &&
( F_89 ( V_9 ) ) !=
( V_179 -> V_181 & V_211 ) ) {
V_226 = F_23 ( V_17 ) ;
goto V_235;
}
if ( ( V_179 -> V_181 & V_211 ) ) {
if ( ( V_141 -> V_129 . V_247 == 0 ) ||
( V_141 -> V_129 . V_243 == 0 ) ||
( V_9 -> V_34 . V_183 % V_141 -> V_129 . V_243 ) ) {
V_226 = F_23 ( V_17 ) ;
goto V_235;
}
}
if ( ( V_9 -> V_34 . V_171 &
( V_172 | V_173 ) ||
( V_179 -> V_181 &
( V_162 | V_164 ) ) ) &&
! F_22 ( V_248 ) ) {
V_226 = F_23 ( V_60 ) ;
goto V_235;
}
}
F_90 ( V_220 , V_9 ) ;
if ( V_217 & V_230 ) {
if ( ( V_9 -> V_34 . V_202 & ( V_249 | V_250 ) ) &&
! F_22 ( V_251 ) )
V_9 -> V_34 . V_202 &= ~ ( V_249 | V_250 ) ;
if ( F_71 ( V_9 ) != V_179 -> V_185 ) {
if ( F_85 ( V_141 ) && F_86 ( V_141 ) ) {
V_225 = F_91 ( V_220 , V_9 ,
& V_9 -> V_252 , V_224 ) ;
}
F_92 ( V_9 , V_179 -> V_185 ) ;
if ( V_9 -> V_34 . V_253 == 1 )
F_93 ( V_220 , V_9 ) ;
}
}
if ( V_217 & V_239 )
V_9 -> V_34 . V_183 = V_179 -> V_182 >> V_141 -> V_129 . V_184 ;
if ( V_217 & V_242 ) {
F_73 ( V_9 , V_179 -> V_181 ) ;
F_74 ( V_9 ) ;
}
F_94 ( V_220 , V_9 , V_254 ) ;
F_95 ( V_220 , V_9 , V_255 ) ;
F_96 ( V_256 ) ;
if ( V_141 -> V_227 & V_257 )
F_97 ( V_220 ) ;
V_226 = F_98 ( V_220 , 0 ) ;
F_72 ( V_9 , V_221 ) ;
F_99 ( V_225 ) ;
F_99 ( V_223 ) ;
F_99 ( V_224 ) ;
return V_226 ;
V_235:
F_99 ( V_223 ) ;
F_99 ( V_224 ) ;
F_100 ( V_220 , 0 ) ;
if ( V_221 )
F_72 ( V_9 , V_221 ) ;
return V_226 ;
}
STATIC int
F_101 (
T_17 * V_9 ,
struct V_6 * V_58 ,
void V_16 * V_86 )
{
struct V_178 V_179 ;
unsigned int V_217 ;
if ( F_17 ( & V_179 , V_86 , sizeof( V_179 ) ) )
return - V_38 ;
V_217 = V_242 | V_239 | V_230 ;
if ( V_58 -> V_72 & ( V_133 | V_134 ) )
V_217 |= V_258 ;
return - F_76 ( V_9 , & V_179 , V_217 ) ;
}
STATIC int
F_102 (
T_17 * V_9 ,
void V_16 * V_86 )
{
unsigned int V_98 ;
V_98 = F_67 ( V_9 -> V_34 . V_171 ) ;
if ( F_11 ( V_86 , & V_98 , sizeof( V_98 ) ) )
return - V_38 ;
return 0 ;
}
STATIC int
F_103 (
T_17 * V_9 ,
struct V_6 * V_58 ,
void V_16 * V_86 )
{
struct V_178 V_179 ;
unsigned int V_98 ;
unsigned int V_217 ;
if ( F_17 ( & V_98 , V_86 , sizeof( V_98 ) ) )
return - V_38 ;
if ( V_98 & ~ ( V_161 | V_163 | \
V_167 | V_169 | \
V_165 ) )
return - V_259 ;
V_217 = V_242 ;
if ( V_58 -> V_72 & ( V_133 | V_134 ) )
V_217 |= V_258 ;
V_179 . V_181 = F_66 ( V_98 , F_70 ( V_9 ) ) ;
return - F_76 ( V_9 , & V_179 , V_217 ) ;
}
STATIC int
F_104 ( void * * V_260 , struct V_261 * V_262 , int * V_263 )
{
struct V_264 V_16 * V_265 = * V_260 ;
if ( F_11 ( V_265 , V_262 , sizeof( struct V_264 ) ) )
return F_23 ( V_38 ) ;
* V_260 += sizeof( struct V_264 ) ;
return 0 ;
}
STATIC int
F_105 (
struct V_8 * V_9 ,
int V_126 ,
unsigned int V_1 ,
void V_16 * V_86 )
{
struct V_261 V_266 ;
int error ;
if ( F_17 ( & V_266 , V_86 , sizeof( struct V_261 ) ) )
return - F_23 ( V_38 ) ;
if ( V_266 . V_267 < 2 )
return - F_23 ( V_17 ) ;
V_266 . V_268 = ( V_1 == V_269 ? V_270 : 0 ) ;
if ( V_126 & V_138 )
V_266 . V_268 |= V_271 ;
error = F_106 ( V_9 , & V_266 , F_104 ,
(struct V_264 * ) V_86 + 1 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_266 , sizeof( struct V_264 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
STATIC int
F_107 ( void * * V_260 , struct V_261 * V_262 , int * V_263 )
{
struct V_261 V_16 * V_265 = * V_260 ;
if ( F_11 ( V_265 , V_262 , sizeof( struct V_261 ) ) )
return F_23 ( V_38 ) ;
* V_260 += sizeof( struct V_261 ) ;
return 0 ;
}
STATIC int
F_108 (
struct V_8 * V_9 ,
void V_16 * V_86 )
{
struct V_261 V_266 ;
int error ;
if ( F_17 ( & V_266 , V_86 , sizeof( V_266 ) ) )
return - F_23 ( V_38 ) ;
if ( V_266 . V_267 < 2 )
return - F_23 ( V_17 ) ;
if ( V_266 . V_268 & ( ~ V_272 ) )
return - F_23 ( V_17 ) ;
error = F_106 ( V_9 , & V_266 , F_107 ,
(struct V_261 * ) V_86 + 1 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_266 , sizeof( struct V_261 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
long
F_109 (
struct V_6 * V_58 ,
unsigned int V_1 ,
unsigned long V_273 )
{
struct V_5 * V_5 = V_58 -> V_13 . V_14 -> V_15 ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_218 * V_141 = V_9 -> V_24 ;
void V_16 * V_86 = ( void V_16 * ) V_273 ;
int V_126 = 0 ;
int error ;
if ( V_58 -> V_74 & V_75 )
V_126 |= V_138 ;
F_110 ( V_9 ) ;
switch ( V_1 ) {
case V_274 :
return F_111 ( V_141 , V_86 ) ;
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 : {
T_11 V_127 ;
if ( F_17 ( & V_127 , V_86 , sizeof( V_127 ) ) )
return - F_23 ( V_38 ) ;
return F_55 ( V_9 , V_5 , V_58 , V_126 , V_1 , & V_127 ) ;
}
case V_284 : {
struct V_285 V_286 ;
T_20 * V_287 =
F_89 ( V_9 ) ?
V_141 -> V_288 : V_141 -> V_289 ;
V_286 . V_290 = V_286 . V_291 = 1 << V_287 -> V_292 ;
V_286 . V_293 = V_111 & ~ ( V_286 . V_291 - 1 ) ;
if ( F_11 ( V_86 , & V_286 , sizeof( V_286 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
case V_153 :
case V_294 :
case V_151 :
return F_58 ( V_141 , V_1 , V_86 ) ;
case V_295 :
return F_63 ( V_141 , V_86 ) ;
case V_296 :
return F_65 ( V_141 , V_86 ) ;
case V_297 :
return F_112 ( V_5 -> V_298 , ( int V_16 * ) V_86 ) ;
case V_299 :
return F_68 ( V_9 , 0 , V_86 ) ;
case V_300 :
return F_68 ( V_9 , 1 , V_86 ) ;
case V_301 :
return F_101 ( V_9 , V_58 , V_86 ) ;
case V_302 :
return F_102 ( V_9 , V_86 ) ;
case V_303 :
return F_103 ( V_9 , V_58 , V_86 ) ;
case V_304 : {
struct V_87 V_305 ;
if ( F_17 ( & V_305 , V_86 , sizeof( V_305 ) ) )
return - F_23 ( V_38 ) ;
error = F_40 ( V_9 , V_305 . V_92 ,
V_305 . V_93 ) ;
return - error ;
}
case V_306 :
case V_269 :
return F_105 ( V_9 , V_126 , V_1 , V_86 ) ;
case V_307 :
return F_108 ( V_9 , V_86 ) ;
case V_10 :
case V_308 :
case V_27 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_86 , sizeof( V_2 ) ) )
return - F_23 ( V_38 ) ;
return F_1 ( V_1 , & V_2 ) ;
}
case V_309 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_86 , sizeof( T_1 ) ) )
return - F_23 ( V_38 ) ;
return F_20 ( V_58 , & V_2 ) ;
}
case V_310 :
return F_39 ( V_58 , V_86 ) ;
case V_311 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_86 , sizeof( T_1 ) ) )
return - F_23 ( V_38 ) ;
return F_35 ( V_58 , & V_2 ) ;
}
case V_312 :
return F_41 ( V_58 , V_86 ) ;
case V_313 :
return F_51 ( V_58 , V_86 ) ;
case V_314 : {
struct V_315 V_316 ;
if ( F_17 ( & V_316 , V_86 , sizeof( V_317 ) ) )
return - F_23 ( V_38 ) ;
error = V_315 ( & V_316 ) ;
return - error ;
}
case V_318 : {
T_21 V_80 ;
error = F_113 ( V_141 , & V_80 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_80 , sizeof( V_80 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
case V_319 : {
T_22 V_320 ;
T_23 V_321 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( V_141 -> V_227 & V_228 )
return - F_23 ( V_229 ) ;
if ( F_17 ( & V_320 , V_86 , sizeof( V_320 ) ) )
return - F_23 ( V_38 ) ;
V_321 = V_320 . V_322 ;
error = F_114 ( V_141 , & V_321 , & V_320 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_320 , sizeof( V_320 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
case V_323 : {
T_22 V_80 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
error = F_114 ( V_141 , NULL , & V_80 ) ;
if ( error )
return - error ;
if ( F_11 ( V_86 , & V_80 , sizeof( V_80 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
case V_324 : {
T_24 V_321 ;
if ( F_17 ( & V_321 , V_86 , sizeof( V_321 ) ) )
return - F_23 ( V_38 ) ;
error = F_115 ( V_141 , & V_321 ) ;
return - error ;
}
case V_325 : {
T_25 V_321 ;
if ( F_17 ( & V_321 , V_86 , sizeof( V_321 ) ) )
return - F_23 ( V_38 ) ;
error = F_116 ( V_141 , & V_321 ) ;
return - error ;
}
case V_326 : {
T_26 V_321 ;
if ( F_17 ( & V_321 , V_86 , sizeof( V_321 ) ) )
return - F_23 ( V_38 ) ;
error = F_117 ( V_141 , & V_321 ) ;
return - error ;
}
case V_327 : {
T_8 V_321 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( F_118 ( V_321 , ( T_8 V_16 * ) V_86 ) )
return - F_23 ( V_38 ) ;
error = F_119 ( V_141 , V_321 ) ;
return - error ;
}
case V_328 : {
T_27 V_321 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( F_17 ( & V_321 , V_86 , sizeof( V_321 ) ) )
return - F_23 ( V_38 ) ;
error = F_120 ( V_321 . V_329 , V_141 ) ;
return - error ;
}
case V_330 :
if ( ! F_22 ( V_59 ) )
return - V_60 ;
error = F_121 ( V_141 , 1 ) ;
return - error ;
default:
return - V_331 ;
}
}
