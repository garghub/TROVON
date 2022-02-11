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
if ( F_5 ( V_5 -> V_22 ) ) {
V_58 -> V_71 |= V_72 ;
V_58 -> V_73 |= V_74 ;
}
F_32 ( V_11 , V_58 ) ;
return V_11 ;
V_61:
F_33 ( V_14 ) ;
return error ;
}
STATIC int
F_34 (
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
F_35 (
struct V_6 * V_43 ,
T_1 * V_2 )
{
struct V_14 * V_14 ;
T_4 V_80 ;
void * V_77 ;
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
if ( F_17 ( & V_80 , V_2 -> V_40 , sizeof( T_4 ) ) ) {
error = - F_23 ( V_38 ) ;
goto V_61;
}
V_77 = F_36 ( V_81 + 1 , V_82 ) ;
if ( ! V_77 ) {
error = - F_23 ( V_83 ) ;
goto V_61;
}
error = - F_37 ( F_4 ( V_14 -> V_15 ) , V_77 ) ;
if ( error )
goto V_84;
error = F_34 ( V_2 -> V_39 , V_80 , V_77 ) ;
if ( error )
goto V_84;
V_84:
F_38 ( V_77 ) ;
V_61:
F_33 ( V_14 ) ;
return error ;
}
STATIC int
F_39 (
struct V_6 * V_43 ,
void V_16 * V_85 )
{
int error ;
struct V_86 V_87 ;
T_5 V_88 ;
struct V_14 * V_14 ;
if ( ! F_22 ( V_89 ) )
return - F_23 ( V_60 ) ;
if ( F_17 ( & V_88 , V_85 , sizeof( T_5 ) ) )
return - F_23 ( V_38 ) ;
V_14 = F_19 ( V_43 , & V_88 . V_2 ) ;
if ( F_24 ( V_14 ) )
return F_25 ( V_14 ) ;
if ( F_27 ( V_14 -> V_15 ) || F_26 ( V_14 -> V_15 ) ) {
error = - F_23 ( V_60 ) ;
goto V_79;
}
if ( F_17 ( & V_87 , V_88 . V_90 , sizeof( V_87 ) ) ) {
error = - F_23 ( V_38 ) ;
goto V_79;
}
error = - F_40 ( F_4 ( V_14 -> V_15 ) , V_87 . V_91 ,
V_87 . V_92 ) ;
V_79:
F_33 ( V_14 ) ;
return error ;
}
STATIC int
F_41 (
struct V_6 * V_43 ,
void V_16 * V_85 )
{
int error = - V_83 ;
T_6 * V_93 ;
T_7 V_94 ;
struct V_14 * V_14 ;
char * V_95 ;
if ( ! F_22 ( V_59 ) )
return - F_23 ( V_60 ) ;
if ( F_17 ( & V_94 , V_85 , sizeof( T_7 ) ) )
return - F_23 ( V_38 ) ;
if ( V_94 . V_76 > V_96 )
return - F_23 ( V_17 ) ;
if ( V_94 . V_97 & ~ ( V_98 | V_99 ) )
return - F_23 ( V_17 ) ;
V_14 = F_19 ( V_43 , & V_94 . V_2 ) ;
if ( F_24 ( V_14 ) )
return F_25 ( V_14 ) ;
V_95 = F_42 ( V_94 . V_76 , V_82 ) ;
if ( ! V_95 )
goto V_61;
V_93 = ( T_6 * ) & V_94 . V_100 ;
error = - F_43 ( F_4 ( V_14 -> V_15 ) , V_95 , V_94 . V_76 ,
V_94 . V_97 , V_93 ) ;
if ( error )
goto V_84;
if ( F_11 ( V_94 . V_75 , V_95 , V_94 . V_76 ) )
error = - V_38 ;
V_84:
F_38 ( V_95 ) ;
V_61:
F_33 ( V_14 ) ;
return error ;
}
int
F_44 (
struct V_5 * V_5 ,
unsigned char * V_101 ,
unsigned char V_16 * V_102 ,
T_8 * V_78 ,
T_8 V_97 )
{
unsigned char * V_95 ;
int error = V_38 ;
if ( * V_78 > V_103 )
return V_17 ;
V_95 = F_36 ( * V_78 , V_82 ) ;
if ( ! V_95 )
return V_83 ;
error = F_45 ( F_4 ( V_5 ) , V_101 , V_95 , ( int * ) V_78 , V_97 ) ;
if ( error )
goto V_84;
if ( F_11 ( V_102 , V_95 , * V_78 ) )
error = V_38 ;
V_84:
F_38 ( V_95 ) ;
return error ;
}
int
F_46 (
struct V_5 * V_5 ,
unsigned char * V_101 ,
const unsigned char V_16 * V_102 ,
T_8 V_78 ,
T_8 V_97 )
{
unsigned char * V_95 ;
int error = V_38 ;
if ( F_27 ( V_5 ) || F_26 ( V_5 ) )
return V_60 ;
if ( V_78 > V_103 )
return V_17 ;
V_95 = F_47 ( V_102 , V_78 ) ;
if ( F_24 ( V_95 ) )
return F_25 ( V_95 ) ;
error = F_48 ( F_4 ( V_5 ) , V_101 , V_95 , V_78 , V_97 ) ;
return error ;
}
int
F_49 (
struct V_5 * V_5 ,
unsigned char * V_101 ,
T_8 V_97 )
{
if ( F_27 ( V_5 ) || F_26 ( V_5 ) )
return V_60 ;
return F_50 ( F_4 ( V_5 ) , V_101 , V_97 ) ;
}
STATIC int
F_51 (
struct V_6 * V_43 ,
void V_16 * V_85 )
{
int error ;
T_9 * V_104 ;
T_10 V_105 ;
struct V_14 * V_14 ;
unsigned int V_106 , V_107 ;
unsigned char * V_108 ;
if ( ! F_22 ( V_59 ) )
return - F_23 ( V_60 ) ;
if ( F_17 ( & V_105 , V_85 , sizeof( T_10 ) ) )
return - F_23 ( V_38 ) ;
if ( V_105 . V_109 >= V_110 / sizeof( T_9 ) )
return - V_111 ;
V_14 = F_19 ( V_43 , & V_105 . V_2 ) ;
if ( F_24 ( V_14 ) )
return F_25 ( V_14 ) ;
error = V_111 ;
V_107 = V_105 . V_109 * sizeof( T_9 ) ;
if ( ! V_107 || V_107 > 16 * V_112 )
goto V_61;
V_104 = F_47 ( V_105 . V_104 , V_107 ) ;
if ( F_24 ( V_104 ) ) {
error = F_25 ( V_104 ) ;
goto V_61;
}
V_108 = F_36 ( V_113 , V_82 ) ;
if ( ! V_108 )
goto V_114;
error = 0 ;
for ( V_106 = 0 ; V_106 < V_105 . V_109 ; V_106 ++ ) {
V_104 [ V_106 ] . V_115 = F_52 ( ( char * ) V_108 ,
V_104 [ V_106 ] . V_116 , V_113 ) ;
if ( V_104 [ V_106 ] . V_115 == 0 || V_104 [ V_106 ] . V_115 == V_113 )
error = - V_117 ;
if ( V_104 [ V_106 ] . V_115 < 0 )
break;
switch ( V_104 [ V_106 ] . V_118 ) {
case V_119 :
V_104 [ V_106 ] . V_115 = F_44 (
V_14 -> V_15 , V_108 ,
V_104 [ V_106 ] . V_120 , & V_104 [ V_106 ] . V_121 ,
V_104 [ V_106 ] . V_122 ) ;
break;
case V_123 :
V_104 [ V_106 ] . V_115 = F_53 ( V_43 -> V_13 . V_51 ) ;
if ( V_104 [ V_106 ] . V_115 )
break;
V_104 [ V_106 ] . V_115 = F_46 (
V_14 -> V_15 , V_108 ,
V_104 [ V_106 ] . V_120 , V_104 [ V_106 ] . V_121 ,
V_104 [ V_106 ] . V_122 ) ;
F_54 ( V_43 -> V_13 . V_51 ) ;
break;
case V_124 :
V_104 [ V_106 ] . V_115 = F_53 ( V_43 -> V_13 . V_51 ) ;
if ( V_104 [ V_106 ] . V_115 )
break;
V_104 [ V_106 ] . V_115 = F_49 (
V_14 -> V_15 , V_108 ,
V_104 [ V_106 ] . V_122 ) ;
F_54 ( V_43 -> V_13 . V_51 ) ;
break;
default:
V_104 [ V_106 ] . V_115 = V_17 ;
}
}
if ( F_11 ( V_105 . V_104 , V_104 , V_107 ) )
error = F_23 ( V_38 ) ;
F_38 ( V_108 ) ;
V_114:
F_38 ( V_104 ) ;
V_61:
F_33 ( V_14 ) ;
return - error ;
}
int
F_55 (
struct V_8 * V_9 ,
struct V_5 * V_5 ,
struct V_6 * V_58 ,
int V_125 ,
unsigned int V_1 ,
T_11 * V_126 )
{
int V_127 = 0 ;
int error ;
if ( ! F_56 ( & V_9 -> V_24 -> V_128 ) &&
! F_22 ( V_59 ) )
return - F_23 ( V_60 ) ;
if ( V_5 -> V_129 & ( V_130 | V_131 ) )
return - F_23 ( V_60 ) ;
if ( ! ( V_58 -> V_73 & V_68 ) )
return - F_23 ( V_12 ) ;
if ( ! F_5 ( V_5 -> V_22 ) )
return - F_23 ( V_17 ) ;
if ( V_58 -> V_71 & ( V_132 | V_133 ) )
V_127 |= V_134 ;
if ( V_58 -> V_71 & V_135 )
V_127 |= V_136 ;
if ( V_125 & V_137 )
V_127 |= V_138 ;
error = F_57 ( V_9 , V_1 , V_126 , V_58 -> V_139 , V_127 ) ;
return - error ;
}
STATIC int
F_58 (
T_12 * V_140 ,
unsigned int V_1 ,
void V_16 * V_85 )
{
T_13 V_141 ;
int V_142 ;
T_14 V_143 ;
int V_144 ;
int error ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( F_59 ( V_140 ) )
return - F_23 ( V_145 ) ;
if ( F_17 ( & V_141 , V_85 , sizeof( T_13 ) ) )
return - F_23 ( V_38 ) ;
if ( F_17 ( & V_143 , V_141 . V_146 , sizeof( V_147 ) ) )
return - F_23 ( V_38 ) ;
if ( ( V_142 = V_141 . V_148 ) <= 0 )
return - F_23 ( V_17 ) ;
if ( V_141 . V_149 == NULL )
return - F_23 ( V_17 ) ;
if ( V_1 == V_150 )
error = F_60 ( V_140 , & V_143 , & V_142 ,
V_141 . V_149 , V_151 ) ;
else if ( V_1 == V_152 )
error = F_61 ( V_140 , & V_143 ,
V_141 . V_149 , & V_144 ) ;
else
error = F_62 ( V_140 , & V_143 , & V_142 , V_153 ,
sizeof( V_154 ) , V_141 . V_149 ,
& V_144 ) ;
if ( error )
return - error ;
if ( V_141 . V_155 != NULL ) {
if ( F_11 ( V_141 . V_146 , & V_143 ,
sizeof( T_14 ) ) )
return - F_23 ( V_38 ) ;
if ( F_11 ( V_141 . V_155 , & V_142 , sizeof( V_142 ) ) )
return - F_23 ( V_38 ) ;
}
return 0 ;
}
STATIC int
F_63 (
T_12 * V_140 ,
void V_16 * V_85 )
{
T_15 V_156 ;
int error ;
error = F_64 ( V_140 , & V_156 , 3 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_156 , sizeof( V_157 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
STATIC int
F_65 (
T_12 * V_140 ,
void V_16 * V_85 )
{
T_15 V_156 ;
int error ;
error = F_64 ( V_140 , & V_156 , 4 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_156 , sizeof( V_156 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
STATIC unsigned int
F_66 (
unsigned int V_97 ,
unsigned int V_158 )
{
unsigned int V_159 = V_158 ;
if ( V_97 & V_160 )
V_159 |= V_161 ;
else
V_159 &= ~ V_161 ;
if ( V_97 & V_162 )
V_159 |= V_163 ;
else
V_159 &= ~ V_163 ;
if ( V_97 & V_164 )
V_159 |= V_165 ;
else
V_159 &= ~ V_165 ;
if ( V_97 & V_166 )
V_159 |= V_167 ;
else
V_159 &= ~ V_167 ;
if ( V_97 & V_168 )
V_159 |= V_169 ;
else
V_159 &= ~ V_169 ;
return V_159 ;
}
STATIC unsigned int
F_67 (
T_16 V_170 )
{
unsigned int V_97 = 0 ;
if ( V_170 & V_171 )
V_97 |= V_160 ;
if ( V_170 & V_172 )
V_97 |= V_162 ;
if ( V_170 & V_173 )
V_97 |= V_164 ;
if ( V_170 & V_174 )
V_97 |= V_166 ;
if ( V_170 & V_175 )
V_97 |= V_168 ;
return V_97 ;
}
STATIC int
F_68 (
T_17 * V_9 ,
int V_176 ,
void V_16 * V_85 )
{
struct V_177 V_178 ;
memset ( & V_178 , 0 , sizeof( struct V_177 ) ) ;
F_69 ( V_9 , V_179 ) ;
V_178 . V_180 = F_70 ( V_9 ) ;
V_178 . V_181 = V_9 -> V_34 . V_182 << V_9 -> V_24 -> V_128 . V_183 ;
V_178 . V_184 = F_71 ( V_9 ) ;
if ( V_176 ) {
if ( V_9 -> V_185 ) {
if ( V_9 -> V_185 -> V_186 & V_187 )
V_178 . V_188 = V_9 -> V_185 -> V_189 /
sizeof( V_190 ) ;
else
V_178 . V_188 = V_9 -> V_34 . V_191 ;
} else
V_178 . V_188 = 0 ;
} else {
if ( V_9 -> V_192 . V_186 & V_187 )
V_178 . V_188 = V_9 -> V_192 . V_189 /
sizeof( V_190 ) ;
else
V_178 . V_188 = V_9 -> V_34 . V_193 ;
}
F_72 ( V_9 , V_179 ) ;
if ( F_11 ( V_85 , & V_178 , sizeof( V_178 ) ) )
return - V_38 ;
return 0 ;
}
STATIC void
F_73 (
struct V_8 * V_9 ,
unsigned int V_159 )
{
unsigned int V_170 ;
V_170 = ( V_9 -> V_34 . V_170 & V_194 ) ;
if ( V_159 & V_161 )
V_170 |= V_171 ;
if ( V_159 & V_163 )
V_170 |= V_172 ;
if ( V_159 & V_165 )
V_170 |= V_173 ;
if ( V_159 & V_167 )
V_170 |= V_174 ;
if ( V_159 & V_169 )
V_170 |= V_175 ;
if ( V_159 & V_195 )
V_170 |= V_196 ;
if ( V_159 & V_197 )
V_170 |= V_198 ;
if ( V_159 & V_199 )
V_170 |= V_200 ;
if ( F_6 ( V_9 -> V_34 . V_201 ) ) {
if ( V_159 & V_202 )
V_170 |= V_203 ;
if ( V_159 & V_204 )
V_170 |= V_205 ;
if ( V_159 & V_206 )
V_170 |= V_207 ;
} else if ( F_5 ( V_9 -> V_34 . V_201 ) ) {
if ( V_159 & V_208 )
V_170 |= V_209 ;
if ( V_159 & V_210 )
V_170 |= V_211 ;
}
V_9 -> V_34 . V_170 = V_170 ;
}
STATIC void
F_74 (
struct V_8 * V_9 )
{
struct V_5 * V_5 = F_75 ( V_9 ) ;
unsigned int V_159 = F_70 ( V_9 ) ;
if ( V_159 & V_161 )
V_5 -> V_129 |= V_130 ;
else
V_5 -> V_129 &= ~ V_130 ;
if ( V_159 & V_163 )
V_5 -> V_129 |= V_131 ;
else
V_5 -> V_129 &= ~ V_131 ;
if ( V_159 & V_165 )
V_5 -> V_129 |= V_212 ;
else
V_5 -> V_129 &= ~ V_212 ;
if ( V_159 & V_167 )
V_5 -> V_129 |= V_213 ;
else
V_5 -> V_129 &= ~ V_213 ;
}
STATIC int
F_76 (
T_17 * V_9 ,
struct V_177 * V_178 ,
int V_214 )
{
struct V_215 * V_140 = V_9 -> V_24 ;
struct V_216 * V_217 ;
unsigned int V_218 = 0 ;
struct V_219 * V_220 = NULL ;
struct V_219 * V_221 = NULL ;
struct V_219 * V_222 = NULL ;
int V_223 ;
F_77 ( V_9 ) ;
if ( V_140 -> V_224 & V_225 )
return F_23 ( V_226 ) ;
if ( F_59 ( V_140 ) )
return F_23 ( V_145 ) ;
if ( ( V_214 & V_227 ) && ( V_178 -> V_184 > ( T_16 ) - 1 ) &&
! F_78 ( & V_9 -> V_24 -> V_128 ) )
return F_23 ( V_17 ) ;
if ( F_79 ( V_140 ) && ( V_214 & V_227 ) ) {
V_223 = F_80 ( V_9 , V_9 -> V_34 . V_228 ,
V_9 -> V_34 . V_229 , V_178 -> V_184 ,
V_230 , & V_220 , & V_221 ) ;
if ( V_223 )
return V_223 ;
}
V_217 = F_81 ( V_140 , V_231 ) ;
V_223 = F_82 ( V_217 , 0 , F_83 ( V_140 ) , 0 , 0 , 0 ) ;
if ( V_223 )
goto V_232;
V_218 = V_233 ;
F_69 ( V_9 , V_218 ) ;
if ( F_84 () != V_9 -> V_34 . V_228 && ! F_22 ( V_234 ) ) {
V_223 = F_23 ( V_60 ) ;
goto V_232;
}
if ( V_214 & V_227 ) {
if ( F_85 ( V_140 ) &&
F_86 ( V_140 ) &&
F_71 ( V_9 ) != V_178 -> V_184 ) {
ASSERT ( V_217 ) ;
V_223 = F_87 ( V_217 , V_9 , V_220 , V_221 ,
F_22 ( V_234 ) ?
V_235 : 0 ) ;
if ( V_223 )
goto V_232;
}
}
if ( V_214 & V_236 ) {
if ( V_9 -> V_34 . V_193 &&
( ( V_9 -> V_34 . V_182 << V_140 -> V_128 . V_183 ) !=
V_178 -> V_181 ) ) {
V_223 = F_23 ( V_17 ) ;
goto V_232;
}
if ( V_178 -> V_181 != 0 ) {
T_18 V_107 ;
T_19 V_237 ;
V_237 = F_88 ( V_140 , V_178 -> V_181 ) ;
if ( V_237 > V_238 ) {
V_223 = F_23 ( V_17 ) ;
goto V_232;
}
if ( F_89 ( V_9 ) ||
( ( V_214 & V_239 ) &&
( V_178 -> V_180 & V_208 ) ) ) {
V_107 = V_140 -> V_128 . V_240 <<
V_140 -> V_128 . V_183 ;
} else {
V_107 = V_140 -> V_128 . V_241 ;
if ( V_237 > V_140 -> V_128 . V_242 / 2 ) {
V_223 = F_23 ( V_17 ) ;
goto V_232;
}
}
if ( V_178 -> V_181 % V_107 ) {
V_223 = F_23 ( V_17 ) ;
goto V_232;
}
}
}
if ( V_214 & V_239 ) {
if ( ( V_9 -> V_34 . V_193 || V_9 -> V_243 ) &&
( F_89 ( V_9 ) ) !=
( V_178 -> V_180 & V_208 ) ) {
V_223 = F_23 ( V_17 ) ;
goto V_232;
}
if ( ( V_178 -> V_180 & V_208 ) ) {
if ( ( V_140 -> V_128 . V_244 == 0 ) ||
( V_140 -> V_128 . V_240 == 0 ) ||
( V_9 -> V_34 . V_182 % V_140 -> V_128 . V_240 ) ) {
V_223 = F_23 ( V_17 ) ;
goto V_232;
}
}
if ( ( V_9 -> V_34 . V_170 &
( V_171 | V_172 ) ||
( V_178 -> V_180 &
( V_161 | V_163 ) ) ) &&
! F_22 ( V_245 ) ) {
V_223 = F_23 ( V_60 ) ;
goto V_232;
}
}
F_90 ( V_217 , V_9 , 0 ) ;
if ( V_214 & V_227 ) {
if ( ( V_9 -> V_34 . V_201 & ( V_246 | V_247 ) ) &&
! F_22 ( V_248 ) )
V_9 -> V_34 . V_201 &= ~ ( V_246 | V_247 ) ;
if ( F_71 ( V_9 ) != V_178 -> V_184 ) {
if ( F_85 ( V_140 ) && F_86 ( V_140 ) ) {
V_222 = F_91 ( V_217 , V_9 ,
& V_9 -> V_249 , V_221 ) ;
}
F_92 ( V_9 , V_178 -> V_184 ) ;
if ( V_9 -> V_34 . V_250 == 1 )
F_93 ( V_217 , V_9 ) ;
}
}
if ( V_214 & V_236 )
V_9 -> V_34 . V_182 = V_178 -> V_181 >> V_140 -> V_128 . V_183 ;
if ( V_214 & V_239 ) {
F_73 ( V_9 , V_178 -> V_180 ) ;
F_74 ( V_9 ) ;
}
F_94 ( V_217 , V_9 , V_251 ) ;
F_95 ( V_217 , V_9 , V_252 ) ;
F_96 ( V_253 ) ;
if ( V_140 -> V_224 & V_254 )
F_97 ( V_217 ) ;
V_223 = F_98 ( V_217 , 0 ) ;
F_72 ( V_9 , V_218 ) ;
F_99 ( V_222 ) ;
F_99 ( V_220 ) ;
F_99 ( V_221 ) ;
return V_223 ;
V_232:
F_99 ( V_220 ) ;
F_99 ( V_221 ) ;
F_100 ( V_217 , 0 ) ;
if ( V_218 )
F_72 ( V_9 , V_218 ) ;
return V_223 ;
}
STATIC int
F_101 (
T_17 * V_9 ,
struct V_6 * V_58 ,
void V_16 * V_85 )
{
struct V_177 V_178 ;
unsigned int V_214 ;
if ( F_17 ( & V_178 , V_85 , sizeof( V_178 ) ) )
return - V_38 ;
V_214 = V_239 | V_236 | V_227 ;
if ( V_58 -> V_71 & ( V_132 | V_133 ) )
V_214 |= V_255 ;
return - F_76 ( V_9 , & V_178 , V_214 ) ;
}
STATIC int
F_102 (
T_17 * V_9 ,
void V_16 * V_85 )
{
unsigned int V_97 ;
V_97 = F_67 ( V_9 -> V_34 . V_170 ) ;
if ( F_11 ( V_85 , & V_97 , sizeof( V_97 ) ) )
return - V_38 ;
return 0 ;
}
STATIC int
F_103 (
T_17 * V_9 ,
struct V_6 * V_58 ,
void V_16 * V_85 )
{
struct V_177 V_178 ;
unsigned int V_97 ;
unsigned int V_214 ;
if ( F_17 ( & V_97 , V_85 , sizeof( V_97 ) ) )
return - V_38 ;
if ( V_97 & ~ ( V_160 | V_162 | \
V_166 | V_168 | \
V_164 ) )
return - V_256 ;
V_214 = V_239 ;
if ( V_58 -> V_71 & ( V_132 | V_133 ) )
V_214 |= V_255 ;
V_178 . V_180 = F_66 ( V_97 , F_70 ( V_9 ) ) ;
return - F_76 ( V_9 , & V_178 , V_214 ) ;
}
STATIC int
F_104 ( void * * V_257 , struct V_258 * V_259 , int * V_260 )
{
struct V_261 V_16 * V_262 = * V_257 ;
if ( F_11 ( V_262 , V_259 , sizeof( struct V_261 ) ) )
return F_23 ( V_38 ) ;
* V_257 += sizeof( struct V_261 ) ;
return 0 ;
}
STATIC int
F_105 (
struct V_8 * V_9 ,
int V_125 ,
unsigned int V_1 ,
void V_16 * V_85 )
{
struct V_258 V_263 ;
int error ;
if ( F_17 ( & V_263 , V_85 , sizeof( struct V_258 ) ) )
return - F_23 ( V_38 ) ;
if ( V_263 . V_264 < 2 )
return - F_23 ( V_17 ) ;
V_263 . V_265 = ( V_1 == V_266 ? V_267 : 0 ) ;
if ( V_125 & V_137 )
V_263 . V_265 |= V_268 ;
error = F_106 ( V_9 , & V_263 , F_104 ,
(struct V_261 * ) V_85 + 1 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_263 , sizeof( struct V_261 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
STATIC int
F_107 ( void * * V_257 , struct V_258 * V_259 , int * V_260 )
{
struct V_258 V_16 * V_262 = * V_257 ;
if ( F_11 ( V_262 , V_259 , sizeof( struct V_258 ) ) )
return F_23 ( V_38 ) ;
* V_257 += sizeof( struct V_258 ) ;
return 0 ;
}
STATIC int
F_108 (
struct V_8 * V_9 ,
void V_16 * V_85 )
{
struct V_258 V_263 ;
int error ;
if ( F_17 ( & V_263 , V_85 , sizeof( V_263 ) ) )
return - F_23 ( V_38 ) ;
if ( V_263 . V_264 < 2 )
return - F_23 ( V_17 ) ;
if ( V_263 . V_265 & ( ~ V_269 ) )
return - F_23 ( V_17 ) ;
error = F_106 ( V_9 , & V_263 , F_107 ,
(struct V_258 * ) V_85 + 1 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_263 , sizeof( struct V_258 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
long
F_109 (
struct V_6 * V_58 ,
unsigned int V_1 ,
unsigned long V_270 )
{
struct V_5 * V_5 = V_58 -> V_13 . V_14 -> V_15 ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_215 * V_140 = V_9 -> V_24 ;
void V_16 * V_85 = ( void V_16 * ) V_270 ;
int V_125 = 0 ;
int error ;
if ( V_58 -> V_73 & V_74 )
V_125 |= V_137 ;
F_110 ( V_9 ) ;
switch ( V_1 ) {
case V_271 :
return F_111 ( V_140 , V_85 ) ;
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 : {
T_11 V_126 ;
if ( F_17 ( & V_126 , V_85 , sizeof( V_126 ) ) )
return - F_23 ( V_38 ) ;
return F_55 ( V_9 , V_5 , V_58 , V_125 , V_1 , & V_126 ) ;
}
case V_281 : {
struct V_282 V_283 ;
T_20 * V_284 =
F_89 ( V_9 ) ?
V_140 -> V_285 : V_140 -> V_286 ;
V_283 . V_287 = V_283 . V_288 = 1 << V_284 -> V_289 ;
V_283 . V_290 = V_110 & ~ ( V_283 . V_288 - 1 ) ;
if ( F_11 ( V_85 , & V_283 , sizeof( V_283 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
case V_152 :
case V_291 :
case V_150 :
return F_58 ( V_140 , V_1 , V_85 ) ;
case V_292 :
return F_63 ( V_140 , V_85 ) ;
case V_293 :
return F_65 ( V_140 , V_85 ) ;
case V_294 :
return F_112 ( V_5 -> V_295 , ( int V_16 * ) V_85 ) ;
case V_296 :
return F_68 ( V_9 , 0 , V_85 ) ;
case V_297 :
return F_68 ( V_9 , 1 , V_85 ) ;
case V_298 :
return F_101 ( V_9 , V_58 , V_85 ) ;
case V_299 :
return F_102 ( V_9 , V_85 ) ;
case V_300 :
return F_103 ( V_9 , V_58 , V_85 ) ;
case V_301 : {
struct V_86 V_302 ;
if ( F_17 ( & V_302 , V_85 , sizeof( V_302 ) ) )
return - F_23 ( V_38 ) ;
error = F_40 ( V_9 , V_302 . V_91 ,
V_302 . V_92 ) ;
return - error ;
}
case V_303 :
case V_266 :
return F_105 ( V_9 , V_125 , V_1 , V_85 ) ;
case V_304 :
return F_108 ( V_9 , V_85 ) ;
case V_10 :
case V_305 :
case V_27 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_85 , sizeof( V_2 ) ) )
return - F_23 ( V_38 ) ;
return F_1 ( V_1 , & V_2 ) ;
}
case V_306 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_85 , sizeof( T_1 ) ) )
return - F_23 ( V_38 ) ;
return F_20 ( V_58 , & V_2 ) ;
}
case V_307 :
return F_39 ( V_58 , V_85 ) ;
case V_308 : {
T_1 V_2 ;
if ( F_17 ( & V_2 , V_85 , sizeof( T_1 ) ) )
return - F_23 ( V_38 ) ;
return F_35 ( V_58 , & V_2 ) ;
}
case V_309 :
return F_41 ( V_58 , V_85 ) ;
case V_310 :
return F_51 ( V_58 , V_85 ) ;
case V_311 : {
struct V_312 V_313 ;
if ( F_17 ( & V_313 , V_85 , sizeof( V_314 ) ) )
return - F_23 ( V_38 ) ;
error = V_312 ( & V_313 ) ;
return - error ;
}
case V_315 : {
T_21 V_79 ;
error = F_113 ( V_140 , & V_79 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_79 , sizeof( V_79 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
case V_316 : {
T_22 V_317 ;
T_23 V_318 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( V_140 -> V_224 & V_225 )
return - F_23 ( V_226 ) ;
if ( F_17 ( & V_317 , V_85 , sizeof( V_317 ) ) )
return - F_23 ( V_38 ) ;
V_318 = V_317 . V_319 ;
error = F_114 ( V_140 , & V_318 , & V_317 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_317 , sizeof( V_317 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
case V_320 : {
T_22 V_79 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
error = F_114 ( V_140 , NULL , & V_79 ) ;
if ( error )
return - error ;
if ( F_11 ( V_85 , & V_79 , sizeof( V_79 ) ) )
return - F_23 ( V_38 ) ;
return 0 ;
}
case V_321 : {
T_24 V_318 ;
if ( F_17 ( & V_318 , V_85 , sizeof( V_318 ) ) )
return - F_23 ( V_38 ) ;
error = F_115 ( V_140 , & V_318 ) ;
return - error ;
}
case V_322 : {
T_25 V_318 ;
if ( F_17 ( & V_318 , V_85 , sizeof( V_318 ) ) )
return - F_23 ( V_38 ) ;
error = F_116 ( V_140 , & V_318 ) ;
return - error ;
}
case V_323 : {
T_26 V_318 ;
if ( F_17 ( & V_318 , V_85 , sizeof( V_318 ) ) )
return - F_23 ( V_38 ) ;
error = F_117 ( V_140 , & V_318 ) ;
return - error ;
}
case V_324 : {
T_8 V_318 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( F_118 ( V_318 , ( T_8 V_16 * ) V_85 ) )
return - F_23 ( V_38 ) ;
error = F_119 ( V_140 , V_318 ) ;
return - error ;
}
case V_325 : {
T_27 V_318 ;
if ( ! F_22 ( V_59 ) )
return - V_60 ;
if ( F_17 ( & V_318 , V_85 , sizeof( V_318 ) ) )
return - F_23 ( V_38 ) ;
error = F_120 ( V_318 . V_326 , V_140 ) ;
return - error ;
}
case V_327 :
if ( ! F_22 ( V_59 ) )
return - V_60 ;
error = F_121 ( V_140 , 1 ) ;
return - error ;
default:
return - V_328 ;
}
}
