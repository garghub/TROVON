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
T_4 V_59 ;
if ( ! F_22 ( V_60 ) )
return - F_23 ( V_61 ) ;
V_14 = F_19 ( V_43 , V_2 ) ;
if ( F_24 ( V_14 ) )
return F_25 ( V_14 ) ;
V_5 = V_14 -> V_15 ;
if ( ! ( F_5 ( V_5 -> V_22 ) || F_6 ( V_5 -> V_22 ) ) ) {
error = - F_23 ( V_61 ) ;
goto V_62;
}
#if V_63 != 32
V_2 -> V_64 |= V_65 ;
#endif
V_57 = V_2 -> V_64 ;
V_59 = F_26 ( V_57 ) ;
if ( ( ! ( V_57 & V_66 ) || ( V_57 & V_67 ) ) &&
( V_59 & V_68 ) && F_27 ( V_5 ) ) {
error = - F_23 ( V_61 ) ;
goto V_62;
}
if ( ( V_59 & V_68 ) && F_28 ( V_5 ) ) {
error = - F_23 ( V_69 ) ;
goto V_62;
}
if ( F_6 ( V_5 -> V_22 ) && ( V_59 & V_68 ) ) {
error = - F_23 ( V_70 ) ;
goto V_62;
}
V_11 = F_29 () ;
if ( V_11 < 0 ) {
error = V_11 ;
goto V_62;
}
V_58 = F_30 ( V_14 , F_31 ( V_43 -> V_13 . V_51 ) ,
V_2 -> V_64 , V_56 ) ;
if ( F_24 ( V_58 ) ) {
F_32 ( V_11 ) ;
return F_25 ( V_58 ) ;
}
if ( F_5 ( V_5 -> V_22 ) ) {
V_58 -> V_71 |= V_72 ;
V_58 -> V_73 |= V_74 ;
}
F_33 ( V_11 , V_58 ) ;
return V_11 ;
V_62:
F_34 ( V_14 ) ;
return error ;
}
STATIC int
F_35 (
char V_16 * V_75 ,
int V_76 ,
const char * V_77 )
{
int V_78 ;
V_78 = F_25 ( V_77 ) ;
if ( F_24 ( V_77 ) )
goto V_79;
V_78 = strlen ( V_77 ) ;
if ( V_78 > ( unsigned ) V_76 )
V_78 = V_76 ;
if ( F_11 ( V_75 , V_77 , V_78 ) )
V_78 = - V_38 ;
V_79:
return V_78 ;
}
int
F_36 (
struct V_6 * V_43 ,
T_1 * V_2 )
{
struct V_14 * V_14 ;
T_5 V_80 ;
void * V_77 ;
int error ;
if ( ! F_22 ( V_60 ) )
return - F_23 ( V_61 ) ;
V_14 = F_19 ( V_43 , V_2 ) ;
if ( F_24 ( V_14 ) )
return F_25 ( V_14 ) ;
if ( ! F_7 ( V_14 -> V_15 -> V_22 ) ) {
error = - F_23 ( V_17 ) ;
goto V_62;
}
if ( F_17 ( & V_80 , V_2 -> V_40 , sizeof( T_5 ) ) ) {
error = - F_23 ( V_38 ) ;
goto V_62;
}
V_77 = F_37 ( V_81 + 1 , V_82 ) ;
if ( ! V_77 ) {
error = - F_23 ( V_83 ) ;
goto V_62;
}
error = - F_38 ( F_4 ( V_14 -> V_15 ) , V_77 ) ;
if ( error )
goto V_84;
error = F_35 ( V_2 -> V_39 , V_80 , V_77 ) ;
if ( error )
goto V_84;
V_84:
F_39 ( V_77 ) ;
V_62:
F_34 ( V_14 ) ;
return error ;
}
STATIC int
F_40 (
struct V_6 * V_43 ,
void V_16 * V_85 )
{
int error ;
struct V_86 V_87 ;
T_6 V_88 ;
struct V_14 * V_14 ;
if ( ! F_22 ( V_89 ) )
return - F_23 ( V_61 ) ;
if ( F_17 ( & V_88 , V_85 , sizeof( T_6 ) ) )
return - F_23 ( V_38 ) ;
V_14 = F_19 ( V_43 , & V_88 . V_2 ) ;
if ( F_24 ( V_14 ) )
return F_25 ( V_14 ) ;
if ( F_28 ( V_14 -> V_15 ) || F_27 ( V_14 -> V_15 ) ) {
error = - F_23 ( V_61 ) ;
goto V_79;
}
if ( F_17 ( & V_87 , V_88 . V_90 , sizeof( V_87 ) ) ) {
error = - F_23 ( V_38 ) ;
goto V_79;
}
error = - F_41 ( F_4 ( V_14 -> V_15 ) , V_87 . V_91 ,
V_87 . V_92 ) ;
V_79:
F_34 ( V_14 ) ;
return error ;
}
STATIC int
F_42 (
struct V_6 * V_43 ,
void V_16 * V_85 )
{
int error = - V_83 ;
T_7 * V_93 ;
T_8 V_94 ;
struct V_14 * V_14 ;
char * V_95 ;
if ( ! F_22 ( V_60 ) )
return - F_23 ( V_61 ) ;
if ( F_17 ( & V_94 , V_85 , sizeof( T_8 ) ) )
return - F_23 ( V_38 ) ;
if ( V_94 . V_76 > V_96 )
return - F_23 ( V_17 ) ;
if ( V_94 . V_97 & ~ ( V_98 | V_99 ) )
return - F_23 ( V_17 ) ;
V_14 = F_19 ( V_43 , & V_94 . V_2 ) ;
if ( F_24 ( V_14 ) )
return F_25 ( V_14 ) ;
V_95 = F_43 ( V_94 . V_76 , V_82 ) ;
if ( ! V_95 )
goto V_62;
V_93 = ( T_7 * ) & V_94 . V_100 ;
error = - F_44 ( F_4 ( V_14 -> V_15 ) , V_95 , V_94 . V_76 ,
V_94 . V_97 , V_93 ) ;
if ( error )
goto V_84;
if ( F_11 ( V_94 . V_75 , V_95 , V_94 . V_76 ) )
error = - V_38 ;
V_84:
F_39 ( V_95 ) ;
V_62:
F_34 ( V_14 ) ;
return error ;
}
int
F_45 (
struct V_5 * V_5 ,
unsigned char * V_101 ,
unsigned char V_16 * V_102 ,
T_9 * V_78 ,
T_9 V_97 )
{
unsigned char * V_95 ;
int error = V_38 ;
if ( * V_78 > V_103 )
return V_17 ;
V_95 = F_46 ( * V_78 , V_104 | V_105 ) ;
if ( ! V_95 ) {
V_95 = F_47 ( * V_78 ) ;
if ( ! V_95 )
return V_83 ;
}
error = F_48 ( F_4 ( V_5 ) , V_101 , V_95 , ( int * ) V_78 , V_97 ) ;
if ( error )
goto V_84;
if ( F_11 ( V_102 , V_95 , * V_78 ) )
error = V_38 ;
V_84:
if ( F_49 ( V_95 ) )
F_50 ( V_95 ) ;
else
F_51 ( V_95 ) ;
return error ;
}
int
F_52 (
struct V_5 * V_5 ,
unsigned char * V_101 ,
const unsigned char V_16 * V_102 ,
T_9 V_78 ,
T_9 V_97 )
{
unsigned char * V_95 ;
int error = V_38 ;
if ( F_28 ( V_5 ) || F_27 ( V_5 ) )
return V_61 ;
if ( V_78 > V_103 )
return V_17 ;
V_95 = F_53 ( V_102 , V_78 ) ;
if ( F_24 ( V_95 ) )
return F_25 ( V_95 ) ;
error = F_54 ( F_4 ( V_5 ) , V_101 , V_95 , V_78 , V_97 ) ;
return error ;
}
int
F_55 (
struct V_5 * V_5 ,
unsigned char * V_101 ,
T_9 V_97 )
{
if ( F_28 ( V_5 ) || F_27 ( V_5 ) )
return V_61 ;
return F_56 ( F_4 ( V_5 ) , V_101 , V_97 ) ;
}
STATIC int
F_57 (
struct V_6 * V_43 ,
void V_16 * V_85 )
{
int error ;
T_10 * V_106 ;
T_11 V_107 ;
struct V_14 * V_14 ;
unsigned int V_108 , V_109 ;
unsigned char * V_110 ;
if ( ! F_22 ( V_60 ) )
return - F_23 ( V_61 ) ;
if ( F_17 ( & V_107 , V_85 , sizeof( T_11 ) ) )
return - F_23 ( V_38 ) ;
if ( V_107 . V_111 >= V_112 / sizeof( T_10 ) )
return - V_113 ;
V_14 = F_19 ( V_43 , & V_107 . V_2 ) ;
if ( F_24 ( V_14 ) )
return F_25 ( V_14 ) ;
error = V_113 ;
V_109 = V_107 . V_111 * sizeof( T_10 ) ;
if ( ! V_109 || V_109 > 16 * V_114 )
goto V_62;
V_106 = F_53 ( V_107 . V_106 , V_109 ) ;
if ( F_24 ( V_106 ) ) {
error = F_25 ( V_106 ) ;
goto V_62;
}
V_110 = F_37 ( V_115 , V_82 ) ;
if ( ! V_110 )
goto V_116;
error = 0 ;
for ( V_108 = 0 ; V_108 < V_107 . V_111 ; V_108 ++ ) {
V_106 [ V_108 ] . V_117 = F_58 ( ( char * ) V_110 ,
V_106 [ V_108 ] . V_118 , V_115 ) ;
if ( V_106 [ V_108 ] . V_117 == 0 || V_106 [ V_108 ] . V_117 == V_115 )
error = - V_119 ;
if ( V_106 [ V_108 ] . V_117 < 0 )
break;
switch ( V_106 [ V_108 ] . V_120 ) {
case V_121 :
V_106 [ V_108 ] . V_117 = F_45 (
V_14 -> V_15 , V_110 ,
V_106 [ V_108 ] . V_122 , & V_106 [ V_108 ] . V_123 ,
V_106 [ V_108 ] . V_124 ) ;
break;
case V_125 :
V_106 [ V_108 ] . V_117 = F_59 ( V_43 ) ;
if ( V_106 [ V_108 ] . V_117 )
break;
V_106 [ V_108 ] . V_117 = F_52 (
V_14 -> V_15 , V_110 ,
V_106 [ V_108 ] . V_122 , V_106 [ V_108 ] . V_123 ,
V_106 [ V_108 ] . V_124 ) ;
F_60 ( V_43 ) ;
break;
case V_126 :
V_106 [ V_108 ] . V_117 = F_59 ( V_43 ) ;
if ( V_106 [ V_108 ] . V_117 )
break;
V_106 [ V_108 ] . V_117 = F_55 (
V_14 -> V_15 , V_110 ,
V_106 [ V_108 ] . V_124 ) ;
F_60 ( V_43 ) ;
break;
default:
V_106 [ V_108 ] . V_117 = V_17 ;
}
}
if ( F_11 ( V_107 . V_106 , V_106 , V_109 ) )
error = F_23 ( V_38 ) ;
F_39 ( V_110 ) ;
V_116:
F_39 ( V_106 ) ;
V_62:
F_34 ( V_14 ) ;
return - error ;
}
int
F_61 (
struct V_8 * V_9 ,
struct V_5 * V_5 ,
struct V_6 * V_58 ,
int V_127 ,
unsigned int V_1 ,
T_12 * V_128 )
{
int V_129 = 0 ;
int error ;
if ( ! F_62 ( & V_9 -> V_24 -> V_130 ) &&
! F_22 ( V_60 ) )
return - F_23 ( V_61 ) ;
if ( V_5 -> V_131 & ( V_132 | V_133 ) )
return - F_23 ( V_61 ) ;
if ( ! ( V_58 -> V_73 & V_68 ) )
return - F_23 ( V_12 ) ;
if ( ! F_5 ( V_5 -> V_22 ) )
return - F_23 ( V_17 ) ;
if ( V_58 -> V_71 & ( V_134 | V_135 ) )
V_129 |= V_136 ;
if ( V_58 -> V_71 & V_137 )
V_129 |= V_138 ;
if ( V_127 & V_139 )
V_129 |= V_140 ;
error = F_63 ( V_9 , V_1 , V_128 , V_58 -> V_141 , V_129 ) ;
return - error ;
}
STATIC int
F_64 (
T_13 * V_142 ,
unsigned int V_1 ,
void V_16 * V_85 )
{
T_14 V_143 ;
int V_144 ;
T_15 V_145 ;
int V_146 ;
int error ;
if ( ! F_22 ( V_60 ) )
return - V_61 ;
if ( F_65 ( V_142 ) )
return - F_23 ( V_147 ) ;
if ( F_17 ( & V_143 , V_85 , sizeof( T_14 ) ) )
return - F_23 ( V_38 ) ;
if ( F_17 ( & V_145 , V_143 . V_148 , sizeof( V_149 ) ) )
return - F_23 ( V_38 ) ;
if ( ( V_144 = V_143 . V_150 ) <= 0 )
return - F_23 ( V_17 ) ;
if ( V_143 . V_151 == NULL )
return - F_23 ( V_17 ) ;
if ( V_1 == V_152 )
error = F_66 ( V_142 , & V_145 , & V_144 ,
V_143 . V_151 , V_153 ) ;
else if ( V_1 == V_154 )
error = F_67 ( V_142 , & V_145 ,
V_143 . V_151 , & V_146 ) ;
else
error = F_68 ( V_142 , & V_145 , & V_144 , V_155 ,
sizeof( V_156 ) , V_143 . V_151 ,
& V_146 ) ;
if ( error )
return - error ;
if ( V_143 . V_157 != NULL ) {
if ( F_11 ( V_143 . V_148 , & V_145 ,
sizeof( T_15 ) ) )
return - F_23 ( V_38 ) ;
if ( F_11 ( V_143 . V_157 , & V_144 , sizeof( V_144 ) ) )
return - F_23 ( V_38 ) ;
}
return 0 ;
}
STATIC int
F_69 (
T_13 * V_142 ,
void V_16 * V_85 )
{
T_16 V_158 ;
int error ;
error = F_70 ( V_142 , & V_158 , 3 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_158 , sizeof( V_159 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
STATIC int
F_71 (
T_13 * V_142 ,
void V_16 * V_85 )
{
T_16 V_158 ;
int error ;
error = F_70 ( V_142 , & V_158 , 4 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_158 , sizeof( V_158 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
STATIC unsigned int
F_72 (
unsigned int V_97 ,
unsigned int V_160 )
{
unsigned int V_161 = V_160 ;
if ( V_97 & V_162 )
V_161 |= V_163 ;
else
V_161 &= ~ V_163 ;
if ( V_97 & V_164 )
V_161 |= V_165 ;
else
V_161 &= ~ V_165 ;
if ( V_97 & V_166 )
V_161 |= V_167 ;
else
V_161 &= ~ V_167 ;
if ( V_97 & V_168 )
V_161 |= V_169 ;
else
V_161 &= ~ V_169 ;
if ( V_97 & V_170 )
V_161 |= V_171 ;
else
V_161 &= ~ V_171 ;
return V_161 ;
}
STATIC unsigned int
F_73 (
T_17 V_172 )
{
unsigned int V_97 = 0 ;
if ( V_172 & V_173 )
V_97 |= V_162 ;
if ( V_172 & V_174 )
V_97 |= V_164 ;
if ( V_172 & V_175 )
V_97 |= V_166 ;
if ( V_172 & V_176 )
V_97 |= V_168 ;
if ( V_172 & V_177 )
V_97 |= V_170 ;
return V_97 ;
}
STATIC int
F_74 (
T_18 * V_9 ,
int V_178 ,
void V_16 * V_85 )
{
struct V_179 V_180 ;
memset ( & V_180 , 0 , sizeof( struct V_179 ) ) ;
F_75 ( V_9 , V_181 ) ;
V_180 . V_182 = F_76 ( V_9 ) ;
V_180 . V_183 = V_9 -> V_34 . V_184 << V_9 -> V_24 -> V_130 . V_185 ;
V_180 . V_186 = F_77 ( V_9 ) ;
if ( V_178 ) {
if ( V_9 -> V_187 ) {
if ( V_9 -> V_187 -> V_188 & V_189 )
V_180 . V_190 = V_9 -> V_187 -> V_191 /
sizeof( V_192 ) ;
else
V_180 . V_190 = V_9 -> V_34 . V_193 ;
} else
V_180 . V_190 = 0 ;
} else {
if ( V_9 -> V_194 . V_188 & V_189 )
V_180 . V_190 = V_9 -> V_194 . V_191 /
sizeof( V_192 ) ;
else
V_180 . V_190 = V_9 -> V_34 . V_195 ;
}
F_78 ( V_9 , V_181 ) ;
if ( F_11 ( V_85 , & V_180 , sizeof( V_180 ) ) )
return - V_38 ;
return 0 ;
}
STATIC void
F_79 (
struct V_8 * V_9 ,
unsigned int V_161 )
{
unsigned int V_172 ;
V_172 = ( V_9 -> V_34 . V_172 & V_196 ) ;
if ( V_161 & V_163 )
V_172 |= V_173 ;
if ( V_161 & V_165 )
V_172 |= V_174 ;
if ( V_161 & V_167 )
V_172 |= V_175 ;
if ( V_161 & V_169 )
V_172 |= V_176 ;
if ( V_161 & V_171 )
V_172 |= V_177 ;
if ( V_161 & V_197 )
V_172 |= V_198 ;
if ( V_161 & V_199 )
V_172 |= V_200 ;
if ( V_161 & V_201 )
V_172 |= V_202 ;
if ( F_6 ( V_9 -> V_34 . V_203 ) ) {
if ( V_161 & V_204 )
V_172 |= V_205 ;
if ( V_161 & V_206 )
V_172 |= V_207 ;
if ( V_161 & V_208 )
V_172 |= V_209 ;
} else if ( F_5 ( V_9 -> V_34 . V_203 ) ) {
if ( V_161 & V_210 )
V_172 |= V_211 ;
if ( V_161 & V_212 )
V_172 |= V_213 ;
}
V_9 -> V_34 . V_172 = V_172 ;
}
STATIC void
F_80 (
struct V_8 * V_9 )
{
struct V_5 * V_5 = F_81 ( V_9 ) ;
unsigned int V_161 = F_76 ( V_9 ) ;
if ( V_161 & V_163 )
V_5 -> V_131 |= V_132 ;
else
V_5 -> V_131 &= ~ V_132 ;
if ( V_161 & V_165 )
V_5 -> V_131 |= V_133 ;
else
V_5 -> V_131 &= ~ V_133 ;
if ( V_161 & V_167 )
V_5 -> V_131 |= V_214 ;
else
V_5 -> V_131 &= ~ V_214 ;
if ( V_161 & V_169 )
V_5 -> V_131 |= V_215 ;
else
V_5 -> V_131 &= ~ V_215 ;
}
STATIC int
F_82 (
T_18 * V_9 ,
struct V_179 * V_180 ,
int V_216 )
{
struct V_217 * V_142 = V_9 -> V_24 ;
struct V_218 * V_219 ;
unsigned int V_220 = 0 ;
struct V_221 * V_222 = NULL ;
struct V_221 * V_223 = NULL ;
struct V_221 * V_224 = NULL ;
int V_225 ;
F_83 ( V_9 ) ;
if ( V_142 -> V_226 & V_227 )
return F_23 ( V_228 ) ;
if ( F_65 ( V_142 ) )
return F_23 ( V_147 ) ;
if ( ( V_216 & V_229 ) && ( V_180 -> V_186 > ( T_17 ) - 1 ) &&
! F_84 ( & V_9 -> V_24 -> V_130 ) )
return F_23 ( V_17 ) ;
if ( F_85 ( V_142 ) && ( V_216 & V_229 ) ) {
V_225 = F_86 ( V_9 , V_9 -> V_34 . V_230 ,
V_9 -> V_34 . V_231 , V_180 -> V_186 ,
V_232 , & V_222 , & V_223 ) ;
if ( V_225 )
return V_225 ;
}
V_219 = F_87 ( V_142 , V_233 ) ;
V_225 = F_88 ( V_219 , 0 , F_89 ( V_142 ) , 0 , 0 , 0 ) ;
if ( V_225 )
goto V_234;
V_220 = V_235 ;
F_75 ( V_9 , V_220 ) ;
if ( F_90 () != V_9 -> V_34 . V_230 && ! F_22 ( V_236 ) ) {
V_225 = F_23 ( V_61 ) ;
goto V_234;
}
if ( V_216 & V_229 ) {
if ( F_91 ( V_142 ) &&
F_92 ( V_142 ) &&
F_77 ( V_9 ) != V_180 -> V_186 ) {
ASSERT ( V_219 ) ;
V_225 = F_93 ( V_219 , V_9 , V_222 , V_223 ,
F_22 ( V_236 ) ?
V_237 : 0 ) ;
if ( V_225 )
goto V_234;
}
}
if ( V_216 & V_238 ) {
if ( V_9 -> V_34 . V_195 &&
( ( V_9 -> V_34 . V_184 << V_142 -> V_130 . V_185 ) !=
V_180 -> V_183 ) ) {
V_225 = F_23 ( V_17 ) ;
goto V_234;
}
if ( V_180 -> V_183 != 0 ) {
T_19 V_109 ;
T_20 V_239 ;
V_239 = F_94 ( V_142 , V_180 -> V_183 ) ;
if ( V_239 > V_240 ) {
V_225 = F_23 ( V_17 ) ;
goto V_234;
}
if ( F_95 ( V_9 ) ||
( ( V_216 & V_241 ) &&
( V_180 -> V_182 & V_210 ) ) ) {
V_109 = V_142 -> V_130 . V_242 <<
V_142 -> V_130 . V_185 ;
} else {
V_109 = V_142 -> V_130 . V_243 ;
if ( V_239 > V_142 -> V_130 . V_244 / 2 ) {
V_225 = F_23 ( V_17 ) ;
goto V_234;
}
}
if ( V_180 -> V_183 % V_109 ) {
V_225 = F_23 ( V_17 ) ;
goto V_234;
}
}
}
if ( V_216 & V_241 ) {
if ( ( V_9 -> V_34 . V_195 || V_9 -> V_245 ) &&
( F_95 ( V_9 ) ) !=
( V_180 -> V_182 & V_210 ) ) {
V_225 = F_23 ( V_17 ) ;
goto V_234;
}
if ( ( V_180 -> V_182 & V_210 ) ) {
if ( ( V_142 -> V_130 . V_246 == 0 ) ||
( V_142 -> V_130 . V_242 == 0 ) ||
( V_9 -> V_34 . V_184 % V_142 -> V_130 . V_242 ) ) {
V_225 = F_23 ( V_17 ) ;
goto V_234;
}
}
if ( ( V_9 -> V_34 . V_172 &
( V_173 | V_174 ) ||
( V_180 -> V_182 &
( V_163 | V_165 ) ) ) &&
! F_22 ( V_247 ) ) {
V_225 = F_23 ( V_61 ) ;
goto V_234;
}
}
F_96 ( V_219 , V_9 , 0 ) ;
if ( V_216 & V_229 ) {
if ( ( V_9 -> V_34 . V_203 & ( V_248 | V_249 ) ) &&
! F_22 ( V_250 ) )
V_9 -> V_34 . V_203 &= ~ ( V_248 | V_249 ) ;
if ( F_77 ( V_9 ) != V_180 -> V_186 ) {
if ( F_91 ( V_142 ) && F_92 ( V_142 ) ) {
V_224 = F_97 ( V_219 , V_9 ,
& V_9 -> V_251 , V_223 ) ;
}
F_98 ( V_9 , V_180 -> V_186 ) ;
if ( V_9 -> V_34 . V_252 == 1 )
F_99 ( V_219 , V_9 ) ;
}
}
if ( V_216 & V_238 )
V_9 -> V_34 . V_184 = V_180 -> V_183 >> V_142 -> V_130 . V_185 ;
if ( V_216 & V_241 ) {
F_79 ( V_9 , V_180 -> V_182 ) ;
F_80 ( V_9 ) ;
}
F_100 ( V_219 , V_9 , V_253 ) ;
F_101 ( V_219 , V_9 , V_254 ) ;
F_102 ( V_255 ) ;
if ( V_142 -> V_226 & V_256 )
F_103 ( V_219 ) ;
V_225 = F_104 ( V_219 , 0 ) ;
F_78 ( V_9 , V_220 ) ;
F_105 ( V_224 ) ;
F_105 ( V_222 ) ;
F_105 ( V_223 ) ;
return V_225 ;
V_234:
F_105 ( V_222 ) ;
F_105 ( V_223 ) ;
F_106 ( V_219 , 0 ) ;
if ( V_220 )
F_78 ( V_9 , V_220 ) ;
return V_225 ;
}
STATIC int
F_107 (
T_18 * V_9 ,
struct V_6 * V_58 ,
void V_16 * V_85 )
{
struct V_179 V_180 ;
unsigned int V_216 ;
if ( F_17 ( & V_180 , V_85 , sizeof( V_180 ) ) )
return - V_38 ;
V_216 = V_241 | V_238 | V_229 ;
if ( V_58 -> V_71 & ( V_134 | V_135 ) )
V_216 |= V_257 ;
return - F_82 ( V_9 , & V_180 , V_216 ) ;
}
STATIC int
F_108 (
T_18 * V_9 ,
void V_16 * V_85 )
{
unsigned int V_97 ;
V_97 = F_73 ( V_9 -> V_34 . V_172 ) ;
if ( F_11 ( V_85 , & V_97 , sizeof( V_97 ) ) )
return - V_38 ;
return 0 ;
}
STATIC int
F_109 (
T_18 * V_9 ,
struct V_6 * V_58 ,
void V_16 * V_85 )
{
struct V_179 V_180 ;
unsigned int V_97 ;
unsigned int V_216 ;
if ( F_17 ( & V_97 , V_85 , sizeof( V_97 ) ) )
return - V_38 ;
if ( V_97 & ~ ( V_162 | V_164 | \
V_168 | V_170 | \
V_166 ) )
return - V_258 ;
V_216 = V_241 ;
if ( V_58 -> V_71 & ( V_134 | V_135 ) )
V_216 |= V_257 ;
V_180 . V_182 = F_72 ( V_97 , F_76 ( V_9 ) ) ;
return - F_82 ( V_9 , & V_180 , V_216 ) ;
}
STATIC int
F_110 ( void * * V_259 , struct V_260 * V_261 , int * V_262 )
{
struct V_263 V_16 * V_264 = * V_259 ;
if ( F_11 ( V_264 , V_261 , sizeof( struct V_263 ) ) )
return F_23 ( V_38 ) ;
* V_259 += sizeof( struct V_263 ) ;
return 0 ;
}
STATIC int
F_111 (
struct V_8 * V_9 ,
int V_127 ,
unsigned int V_1 ,
void V_16 * V_85 )
{
struct V_260 V_265 ;
int error ;
if ( F_17 ( & V_265 , V_85 , sizeof( struct V_260 ) ) )
return - F_23 ( V_38 ) ;
if ( V_265 . V_266 < 2 )
return - F_23 ( V_17 ) ;
V_265 . V_267 = ( V_1 == V_268 ? V_269 : 0 ) ;
if ( V_127 & V_139 )
V_265 . V_267 |= V_270 ;
error = F_112 ( V_9 , & V_265 , F_110 ,
(struct V_263 * ) V_85 + 1 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_265 , sizeof( struct V_263 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
STATIC int
F_113 ( void * * V_259 , struct V_260 * V_261 , int * V_262 )
{
struct V_260 V_16 * V_264 = * V_259 ;
if ( F_11 ( V_264 , V_261 , sizeof( struct V_260 ) ) )
return F_23 ( V_38 ) ;
* V_259 += sizeof( struct V_260 ) ;
return 0 ;
}
STATIC int
F_114 (
struct V_8 * V_9 ,
void V_16 * V_85 )
{
struct V_260 V_265 ;
int error ;
if ( F_17 ( & V_265 , V_85 , sizeof( V_265 ) ) )
return - F_23 ( V_38 ) ;
if ( V_265 . V_266 < 2 )
return - F_23 ( V_17 ) ;
if ( V_265 . V_267 & ( ~ V_271 ) )
return - F_23 ( V_17 ) ;
error = F_112 ( V_9 , & V_265 , F_113 ,
(struct V_260 * ) V_85 + 1 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_265 , sizeof( struct V_260 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
long
F_115 (
struct V_6 * V_58 ,
unsigned int V_1 ,
unsigned long V_272 )
{
struct V_5 * V_5 = V_58 -> V_13 . V_14 -> V_15 ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_217 * V_142 = V_9 -> V_24 ;
void V_16 * V_85 = ( void V_16 * ) V_272 ;
int V_127 = 0 ;
int error ;
if ( V_58 -> V_73 & V_74 )
V_127 |= V_139 ;
F_116 ( V_9 ) ;
switch ( V_1 ) {
case V_273 :
return F_117 ( V_142 , V_85 ) ;
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 : {
T_12 V_128 ;
if ( F_17 ( & V_128 , V_85 , sizeof( V_128 ) ) )
return - F_23 ( V_38 ) ;
return F_61 ( V_9 , V_5 , V_58 , V_127 , V_1 , & V_128 ) ;
}
case V_283 : {
struct V_284 V_285 ;
T_21 * V_286 =
F_95 ( V_9 ) ?
V_142 -> V_287 : V_142 -> V_288 ;
V_285 . V_289 = V_285 . V_290 = 1 << V_286 -> V_291 ;
V_285 . V_292 = V_112 & ~ ( V_285 . V_290 - 1 ) ;
if ( F_11 ( V_85 , & V_285 , sizeof( V_285 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
case V_154 :
case V_293 :
case V_152 :
return F_64 ( V_142 , V_1 , V_85 ) ;
case V_294 :
return F_69 ( V_142 , V_85 ) ;
case V_295 :
return F_71 ( V_142 , V_85 ) ;
case V_296 :
return F_118 ( V_5 -> V_297 , ( int V_16 * ) V_85 ) ;
case V_298 :
return F_74 ( V_9 , 0 , V_85 ) ;
case V_299 :
return F_74 ( V_9 , 1 , V_85 ) ;
case V_300 :
return F_107 ( V_9 , V_58 , V_85 ) ;
case V_301 :
return F_108 ( V_9 , V_85 ) ;
case V_302 :
return F_109 ( V_9 , V_58 , V_85 ) ;
case V_303 : {
struct V_86 V_304 ;
if ( F_17 ( & V_304 , V_85 , sizeof( V_304 ) ) )
return - F_23 ( V_38 ) ;
error = F_41 ( V_9 , V_304 . V_91 ,
V_304 . V_92 ) ;
return - error ;
}
case V_305 :
case V_268 :
return F_111 ( V_9 , V_127 , V_1 , V_85 ) ;
case V_306 :
return F_114 ( V_9 , V_85 ) ;
case V_10 :
case V_307 :
case V_27 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_85 , sizeof( V_2 ) ) )
return - F_23 ( V_38 ) ;
return F_1 ( V_1 , & V_2 ) ;
}
case V_308 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_85 , sizeof( T_1 ) ) )
return - F_23 ( V_38 ) ;
return F_20 ( V_58 , & V_2 ) ;
}
case V_309 :
return F_40 ( V_58 , V_85 ) ;
case V_310 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_85 , sizeof( T_1 ) ) )
return - F_23 ( V_38 ) ;
return F_36 ( V_58 , & V_2 ) ;
}
case V_311 :
return F_42 ( V_58 , V_85 ) ;
case V_312 :
return F_57 ( V_58 , V_85 ) ;
case V_313 : {
struct V_314 V_315 ;
if ( F_17 ( & V_315 , V_85 , sizeof( V_316 ) ) )
return - F_23 ( V_38 ) ;
error = V_314 ( & V_315 ) ;
return - error ;
}
case V_317 : {
T_22 V_79 ;
error = F_119 ( V_142 , & V_79 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_79 , sizeof( V_79 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
case V_318 : {
T_23 V_319 ;
T_24 V_320 ;
if ( ! F_22 ( V_60 ) )
return - V_61 ;
if ( V_142 -> V_226 & V_227 )
return - F_23 ( V_228 ) ;
if ( F_17 ( & V_319 , V_85 , sizeof( V_319 ) ) )
return - F_23 ( V_38 ) ;
V_320 = V_319 . V_321 ;
error = F_120 ( V_142 , & V_320 , & V_319 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_319 , sizeof( V_319 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
case V_322 : {
T_23 V_79 ;
if ( ! F_22 ( V_60 ) )
return - V_61 ;
error = F_120 ( V_142 , NULL , & V_79 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_79 , sizeof( V_79 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
case V_323 : {
T_25 V_320 ;
if ( F_17 ( & V_320 , V_85 , sizeof( V_320 ) ) )
return - F_23 ( V_38 ) ;
error = F_121 ( V_142 , & V_320 ) ;
return - error ;
}
case V_324 : {
T_26 V_320 ;
if ( F_17 ( & V_320 , V_85 , sizeof( V_320 ) ) )
return - F_23 ( V_38 ) ;
error = F_122 ( V_142 , & V_320 ) ;
return - error ;
}
case V_325 : {
T_27 V_320 ;
if ( F_17 ( & V_320 , V_85 , sizeof( V_320 ) ) )
return - F_23 ( V_38 ) ;
error = F_123 ( V_142 , & V_320 ) ;
return - error ;
}
case V_326 : {
T_9 V_320 ;
if ( ! F_22 ( V_60 ) )
return - V_61 ;
if ( F_124 ( V_320 , ( T_9 V_16 * ) V_85 ) )
return - F_23 ( V_38 ) ;
error = F_125 ( V_142 , V_320 ) ;
return - error ;
}
case V_327 : {
T_28 V_320 ;
if ( ! F_22 ( V_60 ) )
return - V_61 ;
if ( F_17 ( & V_320 , V_85 , sizeof( V_320 ) ) )
return - F_23 ( V_38 ) ;
error = F_126 ( V_320 . V_328 , V_142 ) ;
return - error ;
}
case V_329 :
if ( ! F_22 ( V_60 ) )
return - V_61 ;
error = F_127 ( V_142 , 1 ) ;
return - error ;
default:
return - V_330 ;
}
}
