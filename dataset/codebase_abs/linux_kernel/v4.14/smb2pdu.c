static int F_1 ( const struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
if ( ( V_2 -> V_3 -> V_4 & V_5 ) ||
( V_2 -> V_6 & V_7 ) )
return 1 ;
if ( V_2 -> V_8 &&
( V_2 -> V_3 -> V_9 -> V_10 & V_11 ) )
return 1 ;
return 0 ;
}
static void
F_2 ( struct V_12 * V_13 , T_1 V_14 ,
const struct V_1 * V_2 )
{
V_13 -> V_15 = V_16 ;
V_13 -> V_17 = F_3 ( 64 ) ;
V_13 -> V_18 = V_14 ;
if ( V_2 && V_2 -> V_3 && V_2 -> V_3 -> V_9 ) {
struct V_19 * V_9 = V_2 -> V_3 -> V_9 ;
F_4 ( & V_9 -> V_20 ) ;
if ( V_9 -> V_21 >= V_9 -> V_22 )
V_13 -> V_23 = F_3 ( 0 ) ;
else
V_13 -> V_23 = F_3 (
F_5 ( int , V_9 -> V_22 -
V_9 -> V_21 , 2 ) ) ;
F_6 ( & V_9 -> V_20 ) ;
} else {
V_13 -> V_23 = F_3 ( 2 ) ;
}
V_13 -> V_24 = F_7 ( ( V_25 ) V_26 -> V_27 ) ;
if ( ! V_2 )
goto V_28;
if ( ( V_2 -> V_3 ) && ( V_2 -> V_3 -> V_9 ) &&
( V_2 -> V_3 -> V_9 -> V_10 & V_29 ) )
V_13 -> V_30 = F_3 ( 1 ) ;
V_13 -> V_31 = V_2 -> V_32 ;
if ( V_2 -> V_3 )
V_13 -> V_33 = V_2 -> V_3 -> V_34 ;
if ( V_2 -> V_3 && V_2 -> V_3 -> V_9 && V_2 -> V_3 -> V_9 -> V_35 &&
! F_1 ( V_2 ) )
V_13 -> V_36 |= V_37 ;
V_28:
return;
}
static int
F_8 ( T_1 V_38 , struct V_1 * V_2 )
{
int V_39 = 0 ;
struct V_40 * V_41 ;
struct V_42 * V_3 ;
struct V_19 * V_9 ;
if ( V_2 == NULL )
return V_39 ;
if ( V_38 == V_43 )
return V_39 ;
if ( V_2 -> V_44 == V_45 ) {
if ( ( V_38 != V_46 ) &&
( V_38 != V_47 ) &&
( V_38 != V_48 ) ) {
F_9 ( V_49 , L_1 ,
V_38 ) ;
return - V_50 ;
}
}
if ( ( ! V_2 -> V_3 ) || ( V_2 -> V_3 -> V_51 == V_45 ) ||
( ! V_2 -> V_3 -> V_9 ) )
return - V_52 ;
V_3 = V_2 -> V_3 ;
V_9 = V_3 -> V_9 ;
while ( V_9 -> V_53 == V_54 ) {
switch ( V_38 ) {
case V_48 :
case V_55 :
case V_56 :
case V_57 :
return - V_58 ;
}
F_10 ( V_9 -> V_59 ,
( V_9 -> V_53 != V_54 ) , 10 * V_60 ) ;
if ( V_9 -> V_53 != V_54 )
break;
if ( ! V_2 -> V_61 ) {
F_9 ( V_49 , L_2 ) ;
return - V_62 ;
}
}
if ( ! V_2 -> V_3 -> V_63 && ! V_2 -> V_63 )
return V_39 ;
V_41 = F_11 () ;
F_12 ( & V_2 -> V_3 -> V_64 ) ;
if ( V_9 -> V_53 == V_54 ) {
V_39 = - V_62 ;
F_13 ( & V_2 -> V_3 -> V_64 ) ;
goto V_28;
}
V_39 = F_14 ( 0 , V_2 -> V_3 ) ;
if ( ! V_39 && V_2 -> V_3 -> V_63 )
V_39 = F_15 ( 0 , V_2 -> V_3 , V_41 ) ;
if ( V_39 || ! V_2 -> V_63 ) {
F_13 ( & V_2 -> V_3 -> V_64 ) ;
goto V_28;
}
F_16 ( V_2 ) ;
if ( V_2 -> V_65 )
V_2 -> V_66 = true ;
V_39 = F_17 ( 0 , V_2 -> V_3 , V_2 -> V_67 , V_2 , V_41 ) ;
F_13 ( & V_2 -> V_3 -> V_64 ) ;
F_9 ( V_49 , L_3 , V_39 ) ;
if ( V_39 )
goto V_28;
if ( V_38 != V_68 )
F_18 ( V_69 , & V_9 -> V_70 , 0 ) ;
F_19 ( & V_71 ) ;
V_28:
switch ( V_38 ) {
case V_72 :
case V_73 :
case V_46 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
V_39 = - V_58 ;
}
F_20 ( V_41 ) ;
return V_39 ;
}
static void
F_21 ( T_1 V_38 , struct V_1 * V_2 , void * V_80 ,
unsigned int * V_81 )
{
struct V_82 * V_83 = (struct V_82 * ) V_80 ;
V_25 V_84 = V_85 [ F_22 ( V_38 ) ] ;
memset ( V_80 , 0 , 256 ) ;
F_2 ( & V_83 -> V_86 , V_38 , V_2 ) ;
V_83 -> V_87 = F_3 ( V_84 ) ;
* V_81 = V_84 + sizeof( struct V_12 ) ;
}
static int
F_23 ( T_1 V_38 , struct V_1 * V_2 ,
void * * V_88 , unsigned int * V_81 )
{
int V_39 ;
struct V_12 * V_13 ;
V_39 = F_8 ( V_38 , V_2 ) ;
if ( V_39 )
return V_39 ;
* V_88 = F_24 () ;
if ( * V_88 == NULL ) {
return - V_89 ;
}
V_13 = (struct V_12 * ) ( * V_88 ) ;
F_21 ( V_38 , V_2 , V_13 , V_81 ) ;
if ( V_2 != NULL ) {
#ifdef F_25
T_2 V_90 = F_22 ( V_38 ) ;
F_26 ( & V_2 -> V_91 . V_92 . V_93 [ V_90 ] ) ;
#endif
F_26 ( & V_2 -> V_94 ) ;
}
return V_39 ;
}
static int
F_27 ( T_1 V_38 , struct V_1 * V_2 ,
void * * V_88 )
{
int V_39 ;
unsigned int V_81 ;
struct V_95 * V_96 ;
V_39 = F_8 ( V_38 , V_2 ) ;
if ( V_39 )
return V_39 ;
* V_88 = F_24 () ;
if ( * V_88 == NULL ) {
return - V_89 ;
}
V_96 = (struct V_95 * ) ( * V_88 ) ;
F_21 ( V_38 , V_2 , F_28 ( V_96 ) , & V_81 ) ;
V_96 -> V_97 . V_98 = F_29 ( V_81 ) ;
if ( V_2 != NULL ) {
#ifdef F_25
T_2 V_90 = F_22 ( V_38 ) ;
F_26 ( & V_2 -> V_91 . V_92 . V_93 [ V_90 ] ) ;
#endif
F_26 ( & V_2 -> V_94 ) ;
}
return V_39 ;
}
static void
F_30 ( struct V_99 * V_100 )
{
V_100 -> V_101 = V_102 ;
V_100 -> V_103 = F_3 ( 38 ) ;
V_100 -> V_104 = F_3 ( 1 ) ;
V_100 -> V_105 = F_3 ( V_106 ) ;
F_31 ( V_100 -> V_107 , V_106 ) ;
V_100 -> V_108 = V_109 ;
}
static void
F_32 ( struct V_110 * V_100 )
{
V_100 -> V_101 = V_111 ;
V_100 -> V_103 = F_3 ( 6 ) ;
V_100 -> V_112 = F_3 ( 2 ) ;
V_100 -> V_113 [ 0 ] = V_114 ;
V_100 -> V_113 [ 1 ] = V_115 ;
}
static void
F_33 ( struct V_116 * V_117 )
{
char * V_100 = ( char * ) V_117 + V_118 + 4 ;
F_30 ( (struct V_99 * ) V_100 ) ;
V_100 += 2 + sizeof( struct V_99 ) ;
F_32 ( (struct V_110 * ) V_100 ) ;
V_117 -> V_119 = F_7 ( V_118 ) ;
V_117 -> V_120 = F_3 ( 2 ) ;
F_34 ( V_117 , 4 + sizeof( struct V_99 )
+ sizeof( struct V_110 ) ) ;
}
static void F_33 ( struct V_116 * V_117 )
{
return;
}
int
F_35 ( const unsigned int V_121 , struct V_42 * V_3 )
{
struct V_116 * V_117 ;
struct V_122 * V_123 ;
struct V_124 V_125 [ 1 ] ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 ;
struct V_19 * V_9 = V_3 -> V_9 ;
int V_128 , V_129 ;
char * V_130 ;
int V_131 = V_132 ;
F_9 ( V_49 , L_4 ) ;
if ( ! V_9 ) {
F_36 ( 1 , L_5 , V_133 ) ;
return - V_52 ;
}
V_39 = F_27 ( V_134 , NULL , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_97 . V_86 . V_33 = 0 ;
if ( strcmp ( V_3 -> V_9 -> V_135 -> V_136 ,
V_137 ) == 0 ) {
V_117 -> V_138 [ 0 ] = F_3 ( V_139 ) ;
V_117 -> V_138 [ 1 ] = F_3 ( V_140 ) ;
V_117 -> V_141 = F_3 ( 2 ) ;
F_34 ( V_117 , 4 ) ;
} else if ( strcmp ( V_3 -> V_9 -> V_135 -> V_136 ,
V_142 ) == 0 ) {
V_117 -> V_138 [ 0 ] = F_3 ( V_143 ) ;
V_117 -> V_138 [ 1 ] = F_3 ( V_139 ) ;
V_117 -> V_138 [ 2 ] = F_3 ( V_140 ) ;
V_117 -> V_141 = F_3 ( 3 ) ;
F_34 ( V_117 , 6 ) ;
} else {
V_117 -> V_138 [ 0 ] = F_3 ( V_3 -> V_9 -> V_135 -> V_144 ) ;
V_117 -> V_141 = F_3 ( 1 ) ;
F_34 ( V_117 , 2 ) ;
}
if ( V_3 -> V_35 )
V_117 -> V_145 = F_3 ( V_146 ) ;
else if ( V_147 & V_148 )
V_117 -> V_145 = F_3 ( V_149 ) ;
else
V_117 -> V_145 = 0 ;
V_117 -> V_150 = F_7 ( V_3 -> V_9 -> V_135 -> V_151 ) ;
if ( V_3 -> V_9 -> V_135 -> V_144 == V_152 )
memset ( V_117 -> V_153 , 0 , V_154 ) ;
else {
memcpy ( V_117 -> V_153 , V_9 -> V_155 ,
V_154 ) ;
if ( V_3 -> V_9 -> V_135 -> V_144 == V_156 )
F_33 ( V_117 ) ;
}
V_125 [ 0 ] . V_157 = ( char * ) V_117 ;
V_125 [ 0 ] . V_158 = F_37 ( V_117 ) + 4 ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_122 * ) V_126 . V_157 ;
if ( V_39 == - V_159 ) {
F_9 ( V_160 , L_6
L_7
L_8 ) ;
goto V_161;
} else if ( V_39 != 0 )
goto V_161;
if ( strcmp ( V_3 -> V_9 -> V_135 -> V_136 ,
V_137 ) == 0 ) {
if ( V_123 -> V_162 == F_3 ( V_152 ) ) {
F_9 ( V_160 ,
L_9 ) ;
return - V_52 ;
} else if ( V_123 -> V_162 == F_3 ( V_143 ) ) {
F_9 ( V_160 ,
L_10 ) ;
return - V_52 ;
}
} else if ( strcmp ( V_3 -> V_9 -> V_135 -> V_136 ,
V_142 ) == 0 ) {
if ( V_123 -> V_162 == F_3 ( V_152 ) ) {
F_9 ( V_160 ,
L_9 ) ;
return - V_52 ;
} else if ( V_123 -> V_162 == F_3 ( V_143 ) ) {
V_3 -> V_9 -> V_163 = & V_164 ;
}
} else if ( F_22 ( V_123 -> V_162 ) !=
V_3 -> V_9 -> V_135 -> V_144 ) {
F_9 ( V_160 , L_11 ,
F_22 ( V_123 -> V_162 ) ) ;
return - V_52 ;
}
F_9 ( V_49 , L_12 , V_123 -> V_145 ) ;
if ( V_123 -> V_162 == F_3 ( V_152 ) )
F_9 ( V_49 , L_13 ) ;
else if ( V_123 -> V_162 == F_3 ( V_143 ) )
F_9 ( V_49 , L_14 ) ;
else if ( V_123 -> V_162 == F_3 ( V_139 ) )
F_9 ( V_49 , L_15 ) ;
else if ( V_123 -> V_162 == F_3 ( V_140 ) )
F_9 ( V_49 , L_16 ) ;
#ifdef F_40
else if ( V_123 -> V_162 == F_3 ( V_156 ) )
F_9 ( V_49 , L_17 ) ;
#endif
else {
F_9 ( V_160 , L_18 ,
F_22 ( V_123 -> V_162 ) ) ;
V_39 = - V_52 ;
goto V_161;
}
V_9 -> V_165 = F_22 ( V_123 -> V_162 ) ;
V_9 -> V_166 = V_167 ;
V_9 -> V_168 = F_5 (unsigned int, le32_to_cpu(rsp->MaxTransactSize),
SMB2_MAX_BUFFER_SIZE) ;
V_9 -> V_169 = F_41 ( V_123 -> V_170 ) ;
V_9 -> V_171 = F_41 ( V_123 -> V_172 ) ;
V_9 -> V_173 = F_22 ( V_123 -> V_145 ) ;
V_9 -> V_10 = F_41 ( V_123 -> V_150 ) ;
V_9 -> V_10 |= V_174 | V_175 ;
V_130 = F_42 ( & V_128 , & V_129 ,
& V_123 -> V_97 ) ;
if ( V_129 == 0 ) {
F_9 ( V_49 , L_19 ) ;
V_9 -> V_176 = true ;
}
V_39 = F_43 ( V_9 , V_3 -> V_35 ) ;
if ( V_39 )
goto V_161;
if ( V_129 ) {
V_39 = F_44 ( V_130 , V_129 , V_9 ) ;
if ( V_39 == 1 )
V_39 = 0 ;
else if ( V_39 == 0 )
V_39 = - V_52 ;
}
V_161:
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
int F_46 ( const unsigned int V_121 , struct V_1 * V_2 )
{
int V_39 = 0 ;
struct V_177 V_178 ;
struct V_179 * V_180 = NULL ;
T_3 V_181 ;
T_3 V_182 ;
F_9 ( V_49 , L_20 ) ;
if ( V_2 -> V_3 -> V_4 & V_183 )
return 0 ;
if ( V_2 -> V_3 -> V_184 == NULL ) {
F_9 ( V_49 , L_21 ) ;
return 0 ;
}
if ( V_2 -> V_3 -> V_4 & V_185 )
F_9 ( V_160 , L_22 ) ;
V_178 . V_150 =
F_7 ( V_2 -> V_3 -> V_9 -> V_135 -> V_151 ) ;
memcpy ( V_178 . V_186 , V_2 -> V_3 -> V_9 -> V_155 ,
V_154 ) ;
if ( V_2 -> V_3 -> V_35 )
V_178 . V_145 =
F_3 ( V_146 ) ;
else if ( V_147 & V_148 )
V_178 . V_145 =
F_3 ( V_149 ) ;
else
V_178 . V_145 = 0 ;
if ( strcmp ( V_2 -> V_3 -> V_9 -> V_135 -> V_136 ,
V_137 ) == 0 ) {
V_178 . V_138 [ 0 ] = F_3 ( V_139 ) ;
V_178 . V_138 [ 1 ] = F_3 ( V_140 ) ;
V_178 . V_141 = F_3 ( 2 ) ;
V_182 = sizeof( struct V_177 ) - 2 ;
} else if ( strcmp ( V_2 -> V_3 -> V_9 -> V_135 -> V_136 ,
V_142 ) == 0 ) {
V_178 . V_138 [ 0 ] = F_3 ( V_143 ) ;
V_178 . V_138 [ 1 ] = F_3 ( V_139 ) ;
V_178 . V_138 [ 2 ] = F_3 ( V_140 ) ;
V_178 . V_141 = F_3 ( 3 ) ;
V_182 = sizeof( struct V_177 ) ;
} else {
V_178 . V_138 [ 0 ] =
F_3 ( V_2 -> V_3 -> V_9 -> V_135 -> V_144 ) ;
V_178 . V_141 = F_3 ( 1 ) ;
V_182 = sizeof( struct V_177 ) - 4 ;
}
V_39 = F_47 ( V_121 , V_2 , V_187 , V_187 ,
V_188 , true ,
false ,
( char * ) & V_178 , sizeof( struct V_177 ) ,
( char * * ) & V_180 , & V_181 ) ;
if ( V_39 != 0 ) {
F_9 ( V_160 , L_23 , V_39 ) ;
return - V_52 ;
}
if ( V_181 != sizeof( struct V_179 ) ) {
F_9 ( V_160 , L_24 ,
V_181 ) ;
if ( ( V_181 > V_189 )
|| ( V_181 < sizeof( struct V_179 ) ) )
goto V_190;
}
if ( V_180 -> V_191 !=
F_3 ( V_2 -> V_3 -> V_9 -> V_135 -> V_144 ) )
goto V_192;
if ( V_180 -> V_145 != F_3 ( V_2 -> V_3 -> V_9 -> V_173 ) )
goto V_192;
if ( ( F_41 ( V_180 -> V_150 ) | V_174 |
V_175 ) != V_2 -> V_3 -> V_9 -> V_10 )
goto V_192;
F_9 ( V_49 , L_25 ) ;
F_48 ( V_180 ) ;
return 0 ;
V_192:
F_9 ( V_160 , L_26 ) ;
V_190:
F_48 ( V_180 ) ;
return - V_52 ;
}
enum V_193
F_49 ( struct V_19 * V_9 , enum V_193 V_194 )
{
switch ( V_194 ) {
case V_195 :
case V_196 :
return V_194 ;
case V_197 :
return V_196 ;
case V_198 :
if ( V_9 -> V_176 &&
( V_147 & V_199 ) )
return V_196 ;
if ( ( V_9 -> V_200 || V_9 -> V_201 ) &&
( V_147 & V_202 ) )
return V_195 ;
default:
return V_198 ;
}
}
static int
F_50 ( struct V_203 * V_204 )
{
int V_39 ;
struct V_42 * V_3 = V_204 -> V_3 ;
struct V_205 * V_117 ;
struct V_19 * V_9 = V_3 -> V_9 ;
V_39 = F_27 ( V_206 , NULL , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_97 . V_86 . V_33 = 0 ;
V_117 -> V_207 = V_204 -> V_208 ;
V_117 -> V_36 = 0 ;
V_117 -> V_97 . V_86 . V_23 = F_3 ( 3 ) ;
if ( V_9 -> V_35 )
V_117 -> V_145 = V_146 ;
else if ( V_147 & V_148 )
V_117 -> V_145 = V_149 ;
else
V_117 -> V_145 = 0 ;
V_117 -> V_150 = 0 ;
V_117 -> V_209 = 0 ;
V_204 -> V_125 [ 0 ] . V_157 = ( char * ) V_117 ;
V_204 -> V_125 [ 0 ] . V_158 = F_37 ( V_117 ) + 4 - 1 ;
V_204 -> V_210 = V_211 ;
return 0 ;
}
static void
F_51 ( struct V_203 * V_204 )
{
F_45 ( V_204 -> V_210 , V_204 -> V_125 [ 0 ] . V_157 ) ;
V_204 -> V_210 = V_212 ;
}
static int
F_52 ( struct V_203 * V_204 )
{
int V_39 ;
struct V_205 * V_117 = V_204 -> V_125 [ 0 ] . V_157 ;
struct V_124 V_126 = { NULL , 0 } ;
V_117 -> V_213 =
F_3 ( sizeof( struct V_205 ) -
1 - 4 ) ;
V_117 -> V_214 = F_3 ( V_204 -> V_125 [ 1 ] . V_158 ) ;
F_34 ( V_117 , V_204 -> V_125 [ 1 ] . V_158 - 1 ) ;
V_39 = F_38 ( V_204 -> V_121 , V_204 -> V_3 ,
V_204 -> V_125 , 2 ,
& V_204 -> V_210 ,
V_215 | V_132 , & V_126 ) ;
F_39 ( V_204 -> V_125 [ 0 ] . V_157 ) ;
memcpy ( & V_204 -> V_125 [ 0 ] , & V_126 , sizeof( struct V_124 ) ) ;
return V_39 ;
}
static int
F_53 ( struct V_203 * V_204 )
{
int V_39 = 0 ;
struct V_42 * V_3 = V_204 -> V_3 ;
F_12 ( & V_3 -> V_9 -> V_216 ) ;
if ( V_3 -> V_9 -> V_163 -> V_217 ) {
V_39 = V_3 -> V_9 -> V_163 -> V_217 ( V_3 ) ;
if ( V_39 ) {
F_9 ( V_49 ,
L_27 ) ;
F_13 ( & V_3 -> V_9 -> V_216 ) ;
return V_39 ;
}
}
if ( ! V_3 -> V_9 -> V_218 ) {
V_3 -> V_9 -> V_219 = 0x2 ;
V_3 -> V_9 -> V_218 = true ;
}
F_13 ( & V_3 -> V_9 -> V_216 ) ;
F_9 ( V_49 , L_28 ) ;
F_4 ( & V_220 ) ;
V_3 -> V_51 = V_221 ;
V_3 -> V_63 = false ;
F_6 ( & V_220 ) ;
return V_39 ;
}
static void
F_54 ( struct V_203 * V_204 )
{
int V_39 ;
struct V_42 * V_3 = V_204 -> V_3 ;
struct V_222 * V_223 ;
struct V_224 * V_225 = NULL ;
struct V_226 * V_123 = NULL ;
V_39 = F_50 ( V_204 ) ;
if ( V_39 )
goto V_28;
V_225 = F_55 ( V_3 ) ;
if ( F_56 ( V_225 ) ) {
V_39 = F_57 ( V_225 ) ;
V_225 = NULL ;
goto V_28;
}
V_223 = V_225 -> V_227 . V_228 [ 0 ] ;
if ( V_223 -> V_229 != V_230 ) {
F_9 ( V_160 ,
L_29 ,
V_230 , V_223 -> V_229 ) ;
V_39 = - V_231 ;
goto V_232;
}
V_3 -> V_233 . V_234 = F_58 ( V_223 -> V_228 , V_223 -> V_235 ,
V_236 ) ;
if ( ! V_3 -> V_233 . V_234 ) {
F_9 ( V_160 ,
L_30 ,
V_223 -> V_235 ) ;
V_39 = - V_89 ;
goto V_232;
}
V_3 -> V_233 . V_237 = V_223 -> V_235 ;
V_204 -> V_125 [ 1 ] . V_157 = V_223 -> V_228 + V_223 -> V_235 ;
V_204 -> V_125 [ 1 ] . V_158 = V_223 -> V_238 ;
V_39 = F_52 ( V_204 ) ;
if ( V_39 )
goto V_232;
V_123 = (struct V_226 * ) V_204 -> V_125 [ 0 ] . V_157 ;
V_3 -> V_34 = V_123 -> V_97 . V_86 . V_33 ;
V_3 -> V_4 = F_22 ( V_123 -> V_239 ) ;
V_39 = F_53 ( V_204 ) ;
V_232:
F_59 ( V_225 ) ;
F_60 ( V_225 ) ;
V_28:
V_204 -> V_240 = V_39 ;
V_204 -> V_241 = NULL ;
F_51 ( V_204 ) ;
}
static void
F_54 ( struct V_203 * V_204 )
{
F_9 ( V_160 , L_31 ) ;
V_204 -> V_240 = - V_159 ;
V_204 -> V_241 = NULL ;
}
static void
F_61 ( struct V_203 * V_204 )
{
int V_39 ;
struct V_42 * V_3 = V_204 -> V_3 ;
struct V_226 * V_123 = NULL ;
char * V_242 = NULL ;
bool V_243 = false ;
T_4 V_129 = 0 ;
V_3 -> V_244 = F_62 ( sizeof( struct V_245 ) , V_236 ) ;
if ( ! V_3 -> V_244 ) {
V_39 = - V_89 ;
goto V_246;
}
V_3 -> V_244 -> V_247 = true ;
V_39 = F_50 ( V_204 ) ;
if ( V_39 )
goto V_246;
V_242 = F_62 ( sizeof( struct V_248 ) ,
V_236 ) ;
if ( V_242 == NULL ) {
V_39 = - V_89 ;
goto V_28;
}
F_63 ( V_242 , V_3 ) ;
if ( V_243 ) {
F_9 ( V_160 , L_32 ) ;
V_39 = - V_159 ;
goto V_28;
} else {
V_129 = sizeof( struct V_248 ) ;
}
V_204 -> V_125 [ 1 ] . V_157 = V_242 ;
V_204 -> V_125 [ 1 ] . V_158 = V_129 ;
V_39 = F_52 ( V_204 ) ;
V_123 = (struct V_226 * ) V_204 -> V_125 [ 0 ] . V_157 ;
if ( V_204 -> V_210 != V_212 &&
V_123 -> V_97 . V_86 . V_249 == V_250 )
V_39 = 0 ;
if ( V_39 )
goto V_28;
if ( F_64 ( struct V_226 , V_251 ) - 4 !=
F_22 ( V_123 -> V_213 ) ) {
F_9 ( V_160 , L_33 ,
F_22 ( V_123 -> V_213 ) ) ;
V_39 = - V_52 ;
goto V_28;
}
V_39 = F_65 ( V_123 -> V_251 ,
F_22 ( V_123 -> V_214 ) , V_3 ) ;
if ( V_39 )
goto V_28;
F_9 ( V_49 , L_34 ) ;
V_3 -> V_34 = V_123 -> V_97 . V_86 . V_33 ;
V_3 -> V_4 = F_22 ( V_123 -> V_239 ) ;
V_28:
F_48 ( V_242 ) ;
F_51 ( V_204 ) ;
if ( ! V_39 ) {
V_204 -> V_240 = 0 ;
V_204 -> V_241 = V_252 ;
return;
}
V_246:
F_48 ( V_3 -> V_244 ) ;
V_3 -> V_244 = NULL ;
V_204 -> V_240 = V_39 ;
V_204 -> V_241 = NULL ;
}
static void
V_252 ( struct V_203 * V_204 )
{
int V_39 ;
struct V_42 * V_3 = V_204 -> V_3 ;
struct V_205 * V_117 ;
struct V_226 * V_123 = NULL ;
unsigned char * V_242 = NULL ;
bool V_243 = false ;
T_4 V_129 = 0 ;
V_39 = F_50 ( V_204 ) ;
if ( V_39 )
goto V_28;
V_117 = (struct V_205 * ) V_204 -> V_125 [ 0 ] . V_157 ;
V_117 -> V_97 . V_86 . V_33 = V_3 -> V_34 ;
V_39 = F_66 ( & V_242 , & V_129 , V_3 ,
V_204 -> V_253 ) ;
if ( V_39 ) {
F_9 ( V_49 , L_35 , V_39 ) ;
goto V_28;
}
if ( V_243 ) {
F_9 ( V_160 , L_32 ) ;
V_39 = - V_159 ;
goto V_28;
}
V_204 -> V_125 [ 1 ] . V_157 = V_242 ;
V_204 -> V_125 [ 1 ] . V_158 = V_129 ;
V_39 = F_52 ( V_204 ) ;
if ( V_39 )
goto V_28;
V_123 = (struct V_226 * ) V_204 -> V_125 [ 0 ] . V_157 ;
V_3 -> V_34 = V_123 -> V_97 . V_86 . V_33 ;
V_3 -> V_4 = F_22 ( V_123 -> V_239 ) ;
V_39 = F_53 ( V_204 ) ;
V_28:
F_48 ( V_242 ) ;
F_51 ( V_204 ) ;
F_48 ( V_3 -> V_244 ) ;
V_3 -> V_244 = NULL ;
V_204 -> V_240 = V_39 ;
V_204 -> V_241 = NULL ;
}
static int
F_67 ( struct V_42 * V_3 , struct V_203 * V_204 )
{
int type ;
type = F_49 ( V_3 -> V_9 , V_3 -> V_254 ) ;
F_9 ( V_49 , L_36 , type ) ;
if ( type == V_198 ) {
F_9 ( V_160 ,
L_37 ) ;
return - V_255 ;
}
switch ( type ) {
case V_195 :
V_204 -> V_241 = F_54 ;
break;
case V_196 :
V_204 -> V_241 = F_61 ;
break;
default:
F_9 ( V_160 , L_38 , type ) ;
return - V_159 ;
}
return 0 ;
}
int
F_68 ( const unsigned int V_121 , struct V_42 * V_3 ,
const struct V_40 * V_253 )
{
int V_39 = 0 ;
struct V_19 * V_9 = V_3 -> V_9 ;
struct V_203 * V_204 ;
F_9 ( V_49 , L_39 ) ;
if ( ! V_9 ) {
F_36 ( 1 , L_5 , V_133 ) ;
return - V_52 ;
}
V_204 = F_69 ( sizeof( struct V_203 ) , V_236 ) ;
if ( ! V_204 )
return - V_89 ;
V_39 = F_67 ( V_3 , V_204 ) ;
if ( V_39 )
goto V_28;
V_204 -> V_121 = V_121 ;
V_204 -> V_3 = V_3 ;
V_204 -> V_210 = V_212 ;
V_204 -> V_253 = (struct V_40 * ) V_253 ;
while ( V_204 -> V_241 )
V_204 -> V_241 ( V_204 ) ;
if ( ( V_3 -> V_4 & V_183 ) && ( V_3 -> V_35 ) )
F_9 ( V_160 , L_40 ) ;
V_39 = V_204 -> V_240 ;
V_28:
F_48 ( V_204 ) ;
return V_39 ;
}
int
F_70 ( const unsigned int V_121 , struct V_42 * V_3 )
{
struct V_256 * V_117 ;
int V_39 = 0 ;
struct V_19 * V_9 ;
int V_131 = 0 ;
F_9 ( V_49 , L_41 , V_3 ) ;
if ( V_3 && ( V_3 -> V_9 ) )
V_9 = V_3 -> V_9 ;
else
return - V_52 ;
if ( V_3 -> V_63 )
goto V_257;
V_39 = F_27 ( V_258 , NULL , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_97 . V_86 . V_33 = V_3 -> V_34 ;
if ( V_3 -> V_4 & V_5 )
V_131 |= V_259 ;
else if ( V_9 -> V_35 )
V_117 -> V_97 . V_86 . V_36 |= V_37 ;
V_39 = F_71 ( V_121 , V_3 , ( char * ) V_117 , V_131 ) ;
F_39 ( V_117 ) ;
V_257:
return V_39 ;
}
static inline void F_72 ( struct V_1 * V_2 , T_2 V_260 )
{
F_26 ( & V_2 -> V_91 . V_92 . V_261 [ V_260 ] ) ;
}
static inline void F_73 ( struct V_1 * V_2 )
{
V_2 -> V_262 = 256 ;
V_2 -> V_263 = 1048576 ;
V_2 -> V_264 = 16777216 ;
}
int
F_17 ( const unsigned int V_121 , struct V_42 * V_3 , const char * V_265 ,
struct V_1 * V_2 , const struct V_40 * V_266 )
{
struct V_267 * V_117 ;
struct V_268 * V_123 = NULL ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 = { NULL , 0 } ;
int V_39 = 0 ;
int V_127 ;
int V_269 ;
T_1 * V_270 = NULL ;
int V_131 = 0 ;
F_9 ( V_49 , L_42 ) ;
if ( ! ( V_3 -> V_9 ) || ! V_265 )
return - V_52 ;
V_270 = F_62 ( V_271 * 2 , V_236 ) ;
if ( V_270 == NULL )
return - V_89 ;
V_269 = F_74 ( V_270 , V_265 , strlen ( V_265 ) , V_266 ) + 1 ;
V_269 *= 2 ;
if ( V_269 < 2 ) {
F_48 ( V_270 ) ;
return - V_255 ;
}
if ( V_2 )
V_2 -> V_32 = 0 ;
V_39 = F_27 ( V_43 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 ) {
F_48 ( V_270 ) ;
return V_39 ;
}
if ( V_2 == NULL ) {
if ( ( V_3 -> V_4 & V_5 ) )
V_131 |= V_259 ;
V_117 -> V_97 . V_86 . V_33 = V_3 -> V_34 ;
if ( V_3 -> V_9 -> V_35 )
V_117 -> V_97 . V_86 . V_36 |= V_37 ;
} else if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
V_125 [ 0 ] . V_157 = ( char * ) V_117 ;
V_125 [ 0 ] . V_158 = F_37 ( V_117 ) + 4 - 1 ;
V_117 -> V_272 = F_3 ( sizeof( struct V_267 )
- 1 - 4 ) ;
V_117 -> V_273 = F_3 ( V_269 - 2 ) ;
V_125 [ 1 ] . V_157 = V_270 ;
V_125 [ 1 ] . V_158 = V_269 ;
F_34 ( V_117 , V_269 - 1 ) ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 2 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_268 * ) V_126 . V_157 ;
if ( V_39 != 0 ) {
if ( V_2 ) {
F_72 ( V_2 , V_274 ) ;
V_2 -> V_63 = true ;
}
goto V_275;
}
if ( V_2 == NULL ) {
V_3 -> V_276 = V_123 -> V_97 . V_86 . V_31 ;
goto V_277;
}
switch ( V_123 -> V_278 ) {
case V_279 :
F_9 ( V_49 , L_43 ) ;
break;
case V_280 :
V_2 -> V_281 = true ;
F_9 ( V_49 , L_44 ) ;
break;
case V_282 :
V_2 -> V_281 = true ;
F_9 ( V_49 , L_45 ) ;
break;
default:
F_9 ( V_160 , L_46 , V_123 -> V_278 ) ;
V_39 = - V_159 ;
goto V_275;
}
V_2 -> V_6 = F_41 ( V_123 -> V_283 ) ;
V_2 -> V_10 = V_123 -> V_150 ;
V_2 -> V_284 = F_41 ( V_123 -> V_285 ) ;
V_2 -> V_44 = V_221 ;
V_2 -> V_63 = false ;
V_2 -> V_32 = V_123 -> V_97 . V_86 . V_31 ;
F_75 ( V_2 -> V_67 , V_265 , sizeof( V_2 -> V_67 ) ) ;
if ( ( V_123 -> V_150 & V_286 ) &&
( ( V_2 -> V_6 & V_287 ) == 0 ) )
F_9 ( V_160 , L_47 ) ;
if ( V_2 -> V_8 &&
! ( V_2 -> V_3 -> V_9 -> V_10 & V_11 ) )
F_9 ( V_160 , L_48 ) ;
F_73 ( V_2 ) ;
if ( V_2 -> V_3 -> V_9 -> V_163 -> V_288 )
V_39 = V_2 -> V_3 -> V_9 -> V_163 -> V_288 ( V_121 , V_2 ) ;
V_277:
F_45 ( V_127 , V_123 ) ;
F_48 ( V_270 ) ;
return V_39 ;
V_275:
if ( V_123 && V_123 -> V_97 . V_86 . V_249 == V_289 ) {
F_9 ( V_160 , L_49 , V_265 ) ;
}
goto V_277;
}
int
F_76 ( const unsigned int V_121 , struct V_1 * V_2 )
{
struct V_290 * V_117 ;
int V_39 = 0 ;
struct V_42 * V_3 = V_2 -> V_3 ;
int V_131 = 0 ;
F_9 ( V_49 , L_50 ) ;
if ( ! V_3 || ! ( V_3 -> V_9 ) )
return - V_52 ;
if ( ( V_2 -> V_63 ) || ( V_2 -> V_3 -> V_63 ) )
return 0 ;
V_39 = F_27 ( V_48 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
V_39 = F_71 ( V_121 , V_3 , ( char * ) V_117 , V_131 ) ;
F_39 ( V_117 ) ;
if ( V_39 )
F_72 ( V_2 , V_291 ) ;
return V_39 ;
}
static struct V_292 *
F_77 ( void )
{
struct V_292 * V_80 ;
V_80 = F_69 ( sizeof( struct V_292 ) , V_236 ) ;
if ( ! V_80 )
return NULL ;
V_80 -> V_293 . V_294 = F_3 ( F_64
( struct V_292 , V_295 ) ) ;
V_80 -> V_293 . V_103 = F_7 ( 16 ) ;
V_80 -> V_293 . V_296 = F_3 ( F_64
( struct V_292 , V_297 ) ) ;
V_80 -> V_293 . V_298 = F_3 ( 4 ) ;
V_80 -> V_297 [ 0 ] = 'D' ;
V_80 -> V_297 [ 1 ] = 'H' ;
V_80 -> V_297 [ 2 ] = 'n' ;
V_80 -> V_297 [ 3 ] = 'Q' ;
return V_80 ;
}
static struct V_292 *
F_78 ( struct V_299 * V_300 )
{
struct V_292 * V_80 ;
V_80 = F_69 ( sizeof( struct V_292 ) , V_236 ) ;
if ( ! V_80 )
return NULL ;
V_80 -> V_293 . V_294 = F_3 ( F_64
( struct V_292 , V_295 ) ) ;
V_80 -> V_293 . V_103 = F_7 ( 16 ) ;
V_80 -> V_293 . V_296 = F_3 ( F_64
( struct V_292 , V_297 ) ) ;
V_80 -> V_293 . V_298 = F_3 ( 4 ) ;
V_80 -> V_295 . V_301 . V_302 = V_300 -> V_303 ;
V_80 -> V_295 . V_301 . V_304 = V_300 -> V_305 ;
V_80 -> V_297 [ 0 ] = 'D' ;
V_80 -> V_297 [ 1 ] = 'H' ;
V_80 -> V_297 [ 2 ] = 'n' ;
V_80 -> V_297 [ 3 ] = 'C' ;
return V_80 ;
}
static T_5
F_79 ( struct V_19 * V_9 , struct V_306 * V_123 ,
unsigned int * V_307 )
{
char * V_308 ;
struct V_309 * V_310 ;
unsigned int V_311 ;
unsigned int V_312 ;
char * V_313 ;
V_308 = ( char * ) V_123 + 4 + F_41 ( V_123 -> V_314 ) ;
V_312 = F_41 ( V_123 -> V_315 ) ;
V_310 = (struct V_309 * ) V_308 ;
while ( V_312 >= sizeof( struct V_309 ) ) {
V_313 = F_22 ( V_310 -> V_296 ) + ( char * ) V_310 ;
if ( F_22 ( V_310 -> V_298 ) == 4 &&
strncmp ( V_313 , L_51 , 4 ) == 0 )
return V_9 -> V_163 -> V_316 ( V_310 , V_307 ) ;
V_311 = F_41 ( V_310 -> V_317 ) ;
if ( ! V_311 )
break;
V_312 -= V_311 ;
V_310 = (struct V_309 * ) ( ( char * ) V_310 + V_311 ) ;
}
return 0 ;
}
static int
F_80 ( struct V_19 * V_9 , struct V_124 * V_125 ,
unsigned int * V_318 , T_5 * V_319 )
{
struct V_320 * V_117 = V_125 [ 0 ] . V_157 ;
unsigned int V_321 = * V_318 ;
V_125 [ V_321 ] . V_157 = V_9 -> V_163 -> V_322 ( V_319 + 1 , * V_319 ) ;
if ( V_125 [ V_321 ] . V_157 == NULL )
return - V_89 ;
V_125 [ V_321 ] . V_158 = V_9 -> V_135 -> V_323 ;
V_117 -> V_324 = V_325 ;
if ( ! V_117 -> V_314 )
V_117 -> V_314 = F_7 (
sizeof( struct V_320 ) - 4 +
V_125 [ V_321 - 1 ] . V_158 ) ;
F_81 ( & V_117 -> V_315 ,
V_9 -> V_135 -> V_323 ) ;
F_34 ( & V_117 -> V_97 , V_9 -> V_135 -> V_323 ) ;
* V_318 = V_321 + 1 ;
return 0 ;
}
static struct V_326 *
F_82 ( struct V_299 * V_327 )
{
struct V_326 * V_80 ;
V_80 = F_69 ( sizeof( struct V_326 ) , V_236 ) ;
if ( ! V_80 )
return NULL ;
V_80 -> V_293 . V_294 = F_3 ( F_64
( struct V_326 , V_328 ) ) ;
V_80 -> V_293 . V_103 = F_7 ( sizeof( struct V_329 ) ) ;
V_80 -> V_293 . V_296 = F_3 ( F_64
( struct V_326 , V_297 ) ) ;
V_80 -> V_293 . V_298 = F_3 ( 4 ) ;
V_80 -> V_328 . V_330 = 0 ;
V_80 -> V_328 . V_36 = F_7 ( V_331 ) ;
F_83 ( V_80 -> V_328 . V_332 ) ;
memcpy ( V_327 -> V_333 , V_80 -> V_328 . V_332 , 16 ) ;
V_80 -> V_297 [ 0 ] = 'D' ;
V_80 -> V_297 [ 1 ] = 'H' ;
V_80 -> V_297 [ 2 ] = '2' ;
V_80 -> V_297 [ 3 ] = 'Q' ;
return V_80 ;
}
static struct V_334 *
F_84 ( struct V_299 * V_300 )
{
struct V_334 * V_80 ;
V_80 = F_69 ( sizeof( struct V_334 ) ,
V_236 ) ;
if ( ! V_80 )
return NULL ;
V_80 -> V_293 . V_294 =
F_3 ( F_64 ( struct V_334 ,
V_328 ) ) ;
V_80 -> V_293 . V_103 =
F_7 ( sizeof( struct V_335 ) ) ;
V_80 -> V_293 . V_296 =
F_3 ( F_64 ( struct V_334 ,
V_297 ) ) ;
V_80 -> V_293 . V_298 = F_3 ( 4 ) ;
V_80 -> V_328 . V_301 . V_302 = V_300 -> V_303 ;
V_80 -> V_328 . V_301 . V_304 = V_300 -> V_305 ;
V_80 -> V_328 . V_36 = F_7 ( V_331 ) ;
memcpy ( V_80 -> V_328 . V_332 , V_300 -> V_333 , 16 ) ;
V_80 -> V_297 [ 0 ] = 'D' ;
V_80 -> V_297 [ 1 ] = 'H' ;
V_80 -> V_297 [ 2 ] = '2' ;
V_80 -> V_297 [ 3 ] = 'C' ;
return V_80 ;
}
static int
F_85 ( struct V_124 * V_125 , unsigned int * V_318 ,
struct V_336 * V_337 )
{
struct V_320 * V_117 = V_125 [ 0 ] . V_157 ;
unsigned int V_321 = * V_318 ;
V_125 [ V_321 ] . V_157 = F_82 ( V_337 -> V_300 ) ;
if ( V_125 [ V_321 ] . V_157 == NULL )
return - V_89 ;
V_125 [ V_321 ] . V_158 = sizeof( struct V_326 ) ;
if ( ! V_117 -> V_314 )
V_117 -> V_314 =
F_7 ( sizeof( struct V_320 ) - 4 +
V_125 [ 1 ] . V_158 ) ;
F_81 ( & V_117 -> V_315 , sizeof( struct V_326 ) ) ;
F_34 ( & V_117 -> V_97 , sizeof( struct V_326 ) ) ;
* V_318 = V_321 + 1 ;
return 0 ;
}
static int
F_86 ( struct V_124 * V_125 , unsigned int * V_318 ,
struct V_336 * V_337 )
{
struct V_320 * V_117 = V_125 [ 0 ] . V_157 ;
unsigned int V_321 = * V_318 ;
V_337 -> V_70 = false ;
V_125 [ V_321 ] . V_157 = F_84 ( V_337 -> V_300 ) ;
if ( V_125 [ V_321 ] . V_157 == NULL )
return - V_89 ;
V_125 [ V_321 ] . V_158 = sizeof( struct V_334 ) ;
if ( ! V_117 -> V_314 )
V_117 -> V_314 =
F_7 ( sizeof( struct V_320 ) - 4 +
V_125 [ 1 ] . V_158 ) ;
F_81 ( & V_117 -> V_315 ,
sizeof( struct V_334 ) ) ;
F_34 ( & V_117 -> V_97 ,
sizeof( struct V_334 ) ) ;
* V_318 = V_321 + 1 ;
return 0 ;
}
static int
F_87 ( struct V_124 * V_125 , unsigned int * V_318 ,
struct V_336 * V_337 , bool V_65 )
{
struct V_320 * V_117 = V_125 [ 0 ] . V_157 ;
unsigned int V_321 = * V_318 ;
if ( V_65 ) {
if ( V_337 -> V_70 )
return F_86 ( V_125 , V_318 ,
V_337 ) ;
else
return F_85 ( V_125 , V_318 , V_337 ) ;
}
if ( V_337 -> V_70 ) {
V_125 [ V_321 ] . V_157 = F_78 ( V_337 -> V_300 ) ;
V_337 -> V_70 = false ;
} else
V_125 [ V_321 ] . V_157 = F_77 () ;
if ( V_125 [ V_321 ] . V_157 == NULL )
return - V_89 ;
V_125 [ V_321 ] . V_158 = sizeof( struct V_292 ) ;
if ( ! V_117 -> V_314 )
V_117 -> V_314 =
F_7 ( sizeof( struct V_320 ) - 4 +
V_125 [ 1 ] . V_158 ) ;
F_81 ( & V_117 -> V_315 , sizeof( struct V_292 ) ) ;
F_34 ( & V_117 -> V_97 , sizeof( struct V_292 ) ) ;
* V_318 = V_321 + 1 ;
return 0 ;
}
static int
F_88 ( T_1 * * V_338 , int * V_339 , int * V_340 ,
const char * V_341 , const T_1 * V_342 )
{
int V_343 , V_344 ;
struct V_40 * V_266 ;
const T_1 V_345 [] = { F_3 ( '\\' ) , F_3 ( 0x0000 ) } ;
V_343 = strlen ( V_341 ) ;
if ( V_343 < 2 || ! ( V_341 [ 0 ] == '\\' && V_341 [ 1 ] == '\\' ) )
return - V_255 ;
V_341 += 2 ;
V_343 -= 2 ;
V_344 = F_89 ( ( V_346 * ) V_342 , V_347 ) ;
* V_340 = V_343 + 1 + V_344 ;
* V_339 = F_90 ( ( * V_340 + 1 ) * 2 , 8 ) ;
* V_338 = F_69 ( * V_339 , V_236 ) ;
if ( ! * V_338 )
return - V_89 ;
V_266 = F_11 () ;
F_74 ( * V_338 , V_341 , V_343 , V_266 ) ;
F_91 ( * V_338 , V_345 ) ;
F_91 ( * V_338 , V_342 ) ;
F_20 ( V_266 ) ;
return 0 ;
}
int
F_92 ( const unsigned int V_121 , struct V_336 * V_337 , T_1 * V_342 ,
T_5 * V_319 , struct V_348 * V_80 ,
struct V_349 * * V_350 )
{
struct V_320 * V_117 ;
struct V_306 * V_123 ;
struct V_19 * V_9 ;
struct V_1 * V_2 = V_337 -> V_2 ;
struct V_42 * V_3 = V_2 -> V_3 ;
struct V_124 V_125 [ 4 ] ;
struct V_124 V_126 = { NULL , 0 } ;
int V_127 ;
int V_351 ;
T_1 * V_352 = NULL ;
int V_353 ;
int V_39 = 0 ;
unsigned int V_354 = 2 ;
T_6 V_355 = 0 ;
char * V_356 = NULL , * V_357 = NULL ;
int V_131 = 0 ;
F_9 ( V_49 , L_52 ) ;
if ( V_3 && ( V_3 -> V_9 ) )
V_9 = V_3 -> V_9 ;
else
return - V_52 ;
V_39 = F_27 ( V_47 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
if ( V_337 -> V_358 & V_359 )
V_355 |= V_360 ;
if ( V_337 -> V_358 & V_361 )
V_355 |= V_362 ;
V_117 -> V_363 = V_364 ;
V_117 -> V_365 = F_7 ( V_337 -> V_366 ) ;
V_117 -> V_367 = F_7 ( V_355 ) ;
V_117 -> V_368 = V_369 ;
V_117 -> V_370 = F_7 ( V_337 -> V_371 ) ;
V_117 -> V_372 = F_7 ( V_337 -> V_358 & V_373 ) ;
V_125 [ 0 ] . V_157 = ( char * ) V_117 ;
V_125 [ 0 ] . V_158 = F_37 ( V_117 ) + 4 ;
V_125 [ 0 ] . V_158 -- ;
V_117 -> V_296 = F_3 ( sizeof( struct V_320 ) - 4 ) ;
if ( V_2 -> V_6 & V_287 ) {
int V_374 ;
V_117 -> V_97 . V_86 . V_36 |= V_375 ;
V_39 = F_88 ( & V_352 , & V_353 ,
& V_374 ,
V_2 -> V_67 , V_342 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_298 = F_3 ( V_374 * 2 ) ;
V_351 = V_353 ;
V_342 = V_352 ;
} else {
V_351 = ( 2 * F_89 ( ( V_346 * ) V_342 , V_347 ) ) + 2 ;
V_117 -> V_298 = F_3 ( V_351 - 2 ) ;
if ( V_351 % 8 != 0 ) {
V_353 = F_90 ( V_351 , 8 ) ;
V_352 = F_69 ( V_353 , V_236 ) ;
if ( ! V_352 )
return - V_89 ;
memcpy ( ( char * ) V_352 , ( const char * ) V_342 ,
V_351 ) ;
V_351 = V_353 ;
V_342 = V_352 ;
}
}
V_125 [ 1 ] . V_158 = V_351 ;
V_125 [ 1 ] . V_157 = V_342 ;
F_34 ( V_117 , V_351 - 1 ) ;
if ( ! V_9 -> V_376 )
* V_319 = V_377 ;
if ( ! ( V_9 -> V_10 & V_378 ) ||
* V_319 == V_377 )
V_117 -> V_324 = * V_319 ;
else {
V_39 = F_80 ( V_9 , V_125 , & V_354 , V_319 ) ;
if ( V_39 ) {
F_39 ( V_117 ) ;
F_48 ( V_352 ) ;
return V_39 ;
}
V_357 = V_125 [ V_354 - 1 ] . V_157 ;
}
if ( * V_319 == V_379 ) {
if ( V_9 -> V_10 & V_378 ) {
struct V_309 * V_293 =
(struct V_309 * ) V_125 [ V_354 - 1 ] . V_157 ;
V_293 -> V_317 =
F_7 ( V_9 -> V_135 -> V_323 ) ;
}
V_39 = F_87 ( V_125 , & V_354 , V_337 ,
V_2 -> V_65 ) ;
if ( V_39 ) {
F_39 ( V_117 ) ;
F_48 ( V_352 ) ;
F_48 ( V_357 ) ;
return V_39 ;
}
V_356 = V_125 [ V_354 - 1 ] . V_157 ;
}
V_39 = F_38 ( V_121 , V_3 , V_125 , V_354 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_306 * ) V_126 . V_157 ;
if ( V_39 != 0 ) {
F_72 ( V_2 , V_380 ) ;
if ( V_350 && V_123 )
* V_350 = F_58 ( V_123 , F_37 ( V_123 ) + 4 ,
V_236 ) ;
goto V_381;
}
V_337 -> V_300 -> V_303 = V_123 -> V_302 ;
V_337 -> V_300 -> V_305 = V_123 -> V_304 ;
if ( V_80 ) {
memcpy ( V_80 , & V_123 -> V_382 , 32 ) ;
V_80 -> V_383 = V_123 -> V_383 ;
V_80 -> V_384 = V_123 -> V_385 ;
V_80 -> V_386 = V_123 -> V_367 ;
V_80 -> V_387 = F_7 ( 1 ) ;
V_80 -> V_388 = 0 ;
}
if ( V_123 -> V_389 == V_325 )
* V_319 = F_79 ( V_9 , V_123 , & V_337 -> V_300 -> V_307 ) ;
else
* V_319 = V_123 -> V_389 ;
V_381:
F_48 ( V_352 ) ;
F_48 ( V_357 ) ;
F_48 ( V_356 ) ;
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
int
F_47 ( const unsigned int V_121 , struct V_1 * V_2 , T_7 V_303 ,
T_7 V_305 , T_3 V_390 , bool V_391 , bool V_392 ,
char * V_393 , T_3 V_394 ,
char * * V_395 , T_3 * V_396 )
{
struct V_397 * V_117 ;
struct V_398 * V_123 ;
struct V_12 * V_13 ;
struct V_42 * V_3 ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
int V_127 ;
int V_354 ;
int V_39 = 0 ;
int V_131 = 0 ;
F_9 ( V_49 , L_53 ) ;
if ( V_395 != NULL )
* V_395 = NULL ;
if ( V_396 )
* V_396 = 0 ;
if ( V_2 )
V_3 = V_2 -> V_3 ;
else
return - V_52 ;
if ( ! V_3 || ! ( V_3 -> V_9 ) )
return - V_52 ;
V_39 = F_27 ( V_75 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( V_392 ) {
if ( V_3 -> V_276 == 0 ) {
F_39 ( V_117 ) ;
return - V_399 ;
}
F_9 ( V_49 , L_54 ,
V_117 -> V_97 . V_86 . V_31 , V_3 -> V_276 ) ;
V_117 -> V_97 . V_86 . V_31 = V_3 -> V_276 ;
}
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
V_117 -> V_400 = F_7 ( V_390 ) ;
V_117 -> V_302 = V_303 ;
V_117 -> V_304 = V_305 ;
if ( V_394 ) {
V_117 -> V_401 = F_7 ( V_394 ) ;
V_117 -> V_402 =
F_7 ( F_64 ( struct V_397 , V_251 ) - 4 ) ;
V_125 [ 1 ] . V_157 = V_393 ;
V_125 [ 1 ] . V_158 = V_394 ;
V_354 = 2 ;
} else
V_354 = 1 ;
V_117 -> V_403 = 0 ;
V_117 -> V_404 = 0 ;
V_117 -> V_405 = F_7 ( V_189 ) ;
if ( V_391 )
V_117 -> V_36 = F_7 ( V_406 ) ;
else
V_117 -> V_36 = 0 ;
V_125 [ 0 ] . V_157 = ( char * ) V_117 ;
if ( V_394 ) {
V_125 [ 0 ] . V_158 = F_37 ( V_117 ) + 4 - 1 ;
F_34 ( V_117 , V_394 - 1 ) ;
} else
V_125 [ 0 ] . V_158 = F_37 ( V_117 ) + 4 ;
if ( V_390 == V_188 )
V_117 -> V_97 . V_86 . V_36 |= V_37 ;
V_39 = F_38 ( V_121 , V_3 , V_125 , V_354 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_398 * ) V_126 . V_157 ;
if ( ( V_39 != 0 ) && ( V_39 != - V_255 ) ) {
F_72 ( V_2 , V_407 ) ;
goto V_408;
} else if ( V_39 == - V_255 ) {
if ( ( V_390 != V_409 ) &&
( V_390 != V_410 ) ) {
F_72 ( V_2 , V_407 ) ;
goto V_408;
}
}
if ( ( V_396 == NULL ) || ( V_395 == NULL ) )
goto V_408;
* V_396 = F_41 ( V_123 -> V_404 ) ;
if ( * V_396 == 0 )
goto V_408;
else if ( * V_396 > 0xFF00 ) {
F_9 ( V_160 , L_55 , * V_396 ) ;
* V_396 = 0 ;
V_39 = - V_52 ;
goto V_408;
}
if ( F_37 ( V_123 ) < F_41 ( V_123 -> V_403 ) + * V_396 ) {
F_9 ( V_160 , L_56 , * V_396 ,
F_41 ( V_123 -> V_403 ) ) ;
* V_396 = 0 ;
V_39 = - V_52 ;
goto V_408;
}
* V_395 = F_62 ( * V_396 , V_236 ) ;
if ( * V_395 == NULL ) {
V_39 = - V_89 ;
goto V_408;
}
V_13 = F_28 ( V_123 ) ;
memcpy ( * V_395 , ( char * ) V_13 + F_41 ( V_123 -> V_403 ) , * V_396 ) ;
V_408:
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
int
F_93 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 )
{
int V_39 ;
struct V_411 V_412 ;
char * V_413 = NULL ;
V_412 . V_414 =
F_3 ( V_415 ) ;
V_39 = F_47 ( V_121 , V_2 , V_303 , V_305 ,
V_416 , true ,
false ,
( char * ) & V_412 ,
2 , & V_413 , NULL ) ;
F_9 ( V_49 , L_57 , V_39 ) ;
return V_39 ;
}
int
F_94 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 )
{
struct V_417 * V_117 ;
struct V_418 * V_123 ;
struct V_42 * V_3 = V_2 -> V_3 ;
struct V_124 V_125 [ 1 ] ;
struct V_124 V_126 ;
int V_127 ;
int V_39 = 0 ;
int V_131 = 0 ;
F_9 ( V_49 , L_58 ) ;
if ( ! V_3 || ! ( V_3 -> V_9 ) )
return - V_52 ;
V_39 = F_27 ( V_56 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
V_117 -> V_302 = V_303 ;
V_117 -> V_304 = V_305 ;
V_125 [ 0 ] . V_157 = ( char * ) V_117 ;
V_125 [ 0 ] . V_158 = F_37 ( V_117 ) + 4 ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_418 * ) V_126 . V_157 ;
if ( V_39 != 0 ) {
F_72 ( V_2 , V_419 ) ;
goto V_420;
}
V_420:
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
static int
F_95 ( unsigned int V_421 , unsigned int V_422 ,
struct V_423 * V_97 , unsigned int V_424 )
{
unsigned int V_425 = F_96 ( V_97 -> V_98 ) ;
char * V_426 = V_425 + 4 + ( char * ) V_97 ;
char * V_427 = 4 + V_421 + ( char * ) V_97 ;
char * V_428 = V_427 + V_422 ;
if ( V_422 < V_424 ) {
F_9 ( V_160 , L_59 ,
V_422 , V_424 ) ;
return - V_255 ;
}
if ( ( V_425 > 0x7FFFFF ) || ( V_422 > 0x7FFFFF ) ) {
F_9 ( V_160 , L_60 ,
V_422 , V_425 ) ;
return - V_255 ;
}
if ( ( V_427 > V_426 ) || ( V_428 > V_426 ) ) {
F_9 ( V_160 , L_61 ) ;
return - V_255 ;
}
return 0 ;
}
static int
F_97 ( unsigned int V_421 , unsigned int V_422 ,
struct V_423 * V_97 , unsigned int V_429 ,
char * V_228 )
{
char * V_427 = 4 + V_421 + ( char * ) V_97 ;
int V_39 ;
if ( ! V_228 )
return - V_255 ;
V_39 = F_95 ( V_421 , V_422 , V_97 , V_429 ) ;
if ( V_39 )
return V_39 ;
memcpy ( V_228 , V_427 , V_422 ) ;
return 0 ;
}
static int
F_98 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 , T_8 V_430 , T_8 V_431 ,
T_3 V_432 , T_9 V_433 , T_9 V_434 , void * * V_228 ,
T_3 * V_435 )
{
struct V_436 * V_117 ;
struct V_437 * V_123 = NULL ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 ;
struct V_42 * V_3 = V_2 -> V_3 ;
int V_131 = 0 ;
F_9 ( V_49 , L_62 ) ;
if ( ! V_3 || ! ( V_3 -> V_9 ) )
return - V_52 ;
V_39 = F_27 ( V_78 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
V_117 -> V_438 = V_431 ;
V_117 -> V_439 = V_430 ;
V_117 -> V_302 = V_303 ;
V_117 -> V_304 = V_305 ;
V_117 -> V_440 = F_7 ( V_432 ) ;
V_117 -> V_441 = 0 ;
F_34 ( V_117 , - 1 ) ;
V_117 -> V_442 = F_7 ( V_433 ) ;
V_125 [ 0 ] . V_157 = ( char * ) V_117 ;
V_125 [ 0 ] . V_158 = F_37 ( V_117 ) + 4 ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_437 * ) V_126 . V_157 ;
if ( V_39 ) {
F_72 ( V_2 , V_443 ) ;
goto V_444;
}
if ( V_435 ) {
* V_435 = F_41 ( V_123 -> V_442 ) ;
if ( ! * V_228 ) {
* V_228 = F_62 ( * V_435 , V_236 ) ;
if ( ! * V_228 ) {
F_9 ( V_160 ,
L_63 ,
V_39 ) ;
* V_435 = 0 ;
goto V_444;
}
}
}
V_39 = F_97 ( F_22 ( V_123 -> V_445 ) ,
F_41 ( V_123 -> V_442 ) ,
& V_123 -> V_97 , V_434 , * V_228 ) ;
V_444:
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
int F_99 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 ,
int V_446 , struct V_447 * V_228 )
{
return F_98 ( V_121 , V_2 , V_303 , V_305 ,
V_448 , V_449 , 0 ,
V_446 ,
sizeof( struct V_447 ) ,
( void * * ) & V_228 ,
NULL ) ;
}
int F_100 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 , struct V_348 * V_228 )
{
return F_98 ( V_121 , V_2 , V_303 , V_305 ,
V_450 , V_449 , 0 ,
sizeof( struct V_348 ) + V_347 * 2 ,
sizeof( struct V_348 ) , ( void * * ) & V_228 ,
NULL ) ;
}
int
F_101 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 ,
void * * V_228 , T_3 * V_396 )
{
T_6 V_432 = V_451 | V_452 | V_453 ;
* V_396 = 0 ;
return F_98 ( V_121 , V_2 , V_303 , V_305 ,
0 , V_454 , V_432 ,
V_455 ,
sizeof( struct V_348 ) , V_228 , V_396 ) ;
}
int
F_102 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 , T_10 * V_456 )
{
return F_98 ( V_121 , V_2 , V_303 , V_305 ,
V_457 , V_449 , 0 ,
sizeof( struct V_458 ) ,
sizeof( struct V_458 ) ,
( void * * ) & V_456 , NULL ) ;
}
static void
F_103 ( struct V_459 * V_460 )
{
struct V_19 * V_9 = V_460 -> V_461 ;
struct V_462 * V_123 = (struct V_462 * ) V_460 -> V_463 ;
unsigned int V_464 = 1 ;
if ( V_460 -> V_465 == V_466 )
V_464 = F_22 ( V_123 -> V_97 . V_86 . V_23 ) ;
F_104 ( V_460 ) ;
F_105 ( V_9 , V_464 , V_467 ) ;
}
void F_106 ( struct V_468 * V_469 )
{
struct V_19 * V_9 = F_107 ( V_469 ,
struct V_19 , V_70 . V_469 ) ;
struct V_42 * V_3 ;
struct V_1 * V_2 , * V_470 ;
struct V_471 V_472 ;
int V_473 = false ;
int V_39 ;
int V_474 = false ;
F_12 ( & V_9 -> V_475 ) ;
F_108 ( & V_472 ) ;
F_9 ( V_49 , L_64 ) ;
F_4 ( & V_476 ) ;
F_109 (ses, &server->smb_ses_list, smb_ses_list) {
F_109 (tcon, &ses->tcon_list, tcon_list) {
if ( V_2 -> V_63 || V_2 -> V_66 ) {
V_2 -> V_477 ++ ;
F_110 ( & V_2 -> V_478 , & V_472 ) ;
V_473 = true ;
}
}
}
if ( V_473 )
V_9 -> V_479 ++ ;
F_6 ( & V_476 ) ;
F_111 (tcon, tcon2, &tmp_list, rlist) {
V_39 = F_8 ( V_68 , V_2 ) ;
if ( ! V_39 )
F_112 ( V_2 ) ;
else
V_474 = true ;
F_113 ( & V_2 -> V_478 ) ;
F_114 ( V_2 ) ;
}
F_9 ( V_49 , L_65 ) ;
if ( V_474 )
F_18 ( V_69 , & V_9 -> V_70 , 2 * V_60 ) ;
F_13 ( & V_9 -> V_475 ) ;
if ( V_473 )
F_115 ( V_9 , 1 ) ;
}
int
F_116 ( struct V_19 * V_9 )
{
struct V_480 * V_117 ;
int V_39 = 0 ;
struct V_124 V_125 [ 2 ] ;
struct V_481 V_482 = { . V_483 = V_125 ,
. V_484 = 2 } ;
F_9 ( V_49 , L_66 ) ;
if ( V_9 -> V_53 == V_485 ) {
F_18 ( V_69 , & V_9 -> V_70 , 0 ) ;
return V_39 ;
}
V_39 = F_27 ( V_486 , NULL , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_97 . V_86 . V_23 = F_3 ( 1 ) ;
V_125 [ 0 ] . V_158 = 4 ;
V_125 [ 0 ] . V_157 = ( char * ) V_117 ;
V_125 [ 1 ] . V_158 = F_37 ( V_117 ) ;
V_125 [ 1 ] . V_157 = ( char * ) V_117 + 4 ;
V_39 = F_117 ( V_9 , & V_482 , NULL , F_103 , NULL ,
V_9 , V_467 ) ;
if ( V_39 )
F_9 ( V_49 , L_67 , V_39 ) ;
F_39 ( V_117 ) ;
return V_39 ;
}
int
F_118 ( const unsigned int V_121 , struct V_1 * V_2 , T_7 V_303 ,
T_7 V_305 )
{
struct V_487 * V_117 ;
struct V_42 * V_3 = V_2 -> V_3 ;
struct V_124 V_125 [ 1 ] ;
struct V_124 V_126 ;
int V_127 ;
int V_39 = 0 ;
int V_131 = 0 ;
F_9 ( V_49 , L_68 ) ;
if ( ! V_3 || ! ( V_3 -> V_9 ) )
return - V_52 ;
V_39 = F_27 ( V_72 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
V_117 -> V_302 = V_303 ;
V_117 -> V_304 = V_305 ;
V_125 [ 0 ] . V_157 = ( char * ) V_117 ;
V_125 [ 0 ] . V_158 = F_37 ( V_117 ) + 4 ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
if ( V_39 != 0 )
F_72 ( V_2 , V_488 ) ;
F_45 ( V_127 , V_126 . V_157 ) ;
return V_39 ;
}
static int
F_119 ( void * * V_80 , unsigned int * V_81 ,
struct V_489 * V_490 , unsigned int V_491 ,
int V_492 )
{
int V_39 = - V_493 ;
struct V_494 * V_117 = NULL ;
struct V_12 * V_13 ;
V_39 = F_23 ( V_73 , V_490 -> V_2 , ( void * * ) & V_117 ,
V_81 ) ;
if ( V_39 )
return V_39 ;
if ( V_490 -> V_2 -> V_3 -> V_9 == NULL )
return - V_495 ;
V_13 = & V_117 -> V_86 ;
V_13 -> V_24 = F_7 ( V_490 -> V_496 ) ;
V_117 -> V_302 = V_490 -> V_303 ;
V_117 -> V_304 = V_490 -> V_305 ;
V_117 -> V_497 = 0 ;
V_117 -> V_498 = 0 ;
V_117 -> V_209 = 0 ;
V_117 -> V_499 = 0 ;
V_117 -> V_500 = F_7 ( V_490 -> V_501 ) ;
V_117 -> V_502 = F_120 ( V_490 -> V_421 ) ;
if ( V_492 & V_503 ) {
if ( ! ( V_492 & V_504 ) ) {
* V_81 = F_121 ( * V_81 , 8 ) * 8 ;
V_13 -> V_505 = F_7 ( * V_81 ) ;
} else
V_13 -> V_505 = 0 ;
if ( V_492 & V_506 ) {
V_13 -> V_36 |= V_507 ;
V_13 -> V_33 = 0xFFFFFFFF ;
V_13 -> V_31 = 0xFFFFFFFF ;
V_117 -> V_302 = 0xFFFFFFFF ;
V_117 -> V_304 = 0xFFFFFFFF ;
}
}
if ( V_491 > V_490 -> V_501 )
V_117 -> V_508 = F_7 ( V_491 ) ;
else
V_117 -> V_508 = 0 ;
* V_80 = V_117 ;
return V_39 ;
}
static void
F_122 ( struct V_459 * V_460 )
{
struct V_509 * V_510 = V_460 -> V_461 ;
struct V_1 * V_2 = F_123 ( V_510 -> V_511 -> V_512 ) ;
struct V_19 * V_9 = V_2 -> V_3 -> V_9 ;
struct V_12 * V_13 =
(struct V_12 * ) V_510 -> V_125 [ 1 ] . V_157 ;
unsigned int V_464 = 1 ;
struct V_481 V_482 = { . V_483 = V_510 -> V_125 ,
. V_484 = 2 ,
. V_513 = V_510 -> V_514 ,
. V_515 = V_510 -> V_516 ,
. V_517 = V_510 -> V_518 ,
. V_519 = V_510 -> V_520 } ;
F_9 ( V_49 , L_69 ,
V_133 , V_460 -> V_460 , V_460 -> V_465 , V_510 -> V_240 ,
V_510 -> V_521 ) ;
switch ( V_460 -> V_465 ) {
case V_466 :
V_464 = F_22 ( V_13 -> V_23 ) ;
if ( V_9 -> V_35 && ! V_460 -> V_522 ) {
int V_39 ;
V_39 = F_124 ( & V_482 , V_9 ) ;
if ( V_39 )
F_9 ( V_160 , L_70 ,
V_39 ) ;
}
F_125 ( V_510 -> V_523 ) ;
F_126 ( V_2 , V_510 -> V_523 ) ;
break;
case V_524 :
case V_525 :
V_510 -> V_240 = - V_58 ;
if ( V_9 -> V_35 && V_510 -> V_523 )
V_510 -> V_523 = 0 ;
F_125 ( V_510 -> V_523 ) ;
F_126 ( V_2 , V_510 -> V_523 ) ;
break;
default:
if ( V_510 -> V_240 != - V_526 )
V_510 -> V_240 = - V_52 ;
}
if ( V_510 -> V_240 )
F_72 ( V_2 , V_527 ) ;
F_127 ( V_69 , & V_510 -> V_469 ) ;
F_104 ( V_460 ) ;
F_105 ( V_9 , V_464 , 0 ) ;
}
int
F_128 ( struct V_509 * V_510 )
{
int V_39 , V_131 = 0 ;
char * V_80 ;
struct V_12 * V_13 ;
struct V_489 V_490 ;
struct V_481 V_482 = { . V_483 = V_510 -> V_125 ,
. V_484 = 2 } ;
struct V_19 * V_9 ;
unsigned int V_81 ;
T_11 V_528 ;
F_9 ( V_49 , L_71 ,
V_133 , V_510 -> V_421 , V_510 -> V_521 ) ;
V_490 . V_2 = F_123 ( V_510 -> V_511 -> V_512 ) ;
V_490 . V_421 = V_510 -> V_421 ;
V_490 . V_501 = V_510 -> V_521 ;
V_490 . V_303 = V_510 -> V_511 -> V_300 . V_303 ;
V_490 . V_305 = V_510 -> V_511 -> V_300 . V_305 ;
V_490 . V_496 = V_510 -> V_496 ;
V_9 = V_490 . V_2 -> V_3 -> V_9 ;
V_39 = F_119 ( ( void * * ) & V_80 , & V_81 , & V_490 , 0 , 0 ) ;
if ( V_39 ) {
if ( V_39 == - V_58 && V_510 -> V_21 ) {
V_510 -> V_21 = 0 ;
F_4 ( & V_9 -> V_20 ) ;
V_9 -> V_529 -- ;
F_6 ( & V_9 -> V_20 ) ;
}
return V_39 ;
}
if ( F_1 ( V_490 . V_2 ) )
V_131 |= V_259 ;
V_528 = F_29 ( V_81 ) ;
V_510 -> V_125 [ 0 ] . V_157 = & V_528 ;
V_510 -> V_125 [ 0 ] . V_158 = sizeof( T_11 ) ;
V_510 -> V_125 [ 1 ] . V_157 = V_80 ;
V_510 -> V_125 [ 1 ] . V_158 = V_81 ;
V_13 = (struct V_12 * ) V_80 ;
if ( V_510 -> V_21 ) {
V_13 -> V_30 = F_3 ( F_121 ( V_510 -> V_521 ,
V_455 ) ) ;
V_13 -> V_23 = V_13 -> V_30 ;
F_4 ( & V_9 -> V_20 ) ;
V_9 -> V_21 += V_510 -> V_21 -
F_22 ( V_13 -> V_30 ) ;
F_6 ( & V_9 -> V_20 ) ;
F_129 ( & V_9 -> V_530 ) ;
V_131 |= V_531 ;
}
F_130 ( & V_510 -> V_532 ) ;
V_39 = F_117 ( V_490 . V_2 -> V_3 -> V_9 , & V_482 ,
V_533 , F_122 ,
V_534 , V_510 , V_131 ) ;
if ( V_39 ) {
F_131 ( & V_510 -> V_532 , V_535 ) ;
F_72 ( V_490 . V_2 , V_527 ) ;
}
F_39 ( V_80 ) ;
return V_39 ;
}
int
F_132 ( const unsigned int V_121 , struct V_489 * V_490 ,
unsigned int * V_536 , char * * V_80 , int * V_537 )
{
int V_127 , V_39 = - V_493 ;
struct V_494 * V_117 = NULL ;
struct V_538 * V_123 = NULL ;
struct V_12 * V_13 ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
unsigned int V_81 ;
T_11 V_528 ;
struct V_481 V_482 = { . V_483 = V_125 ,
. V_484 = 2 } ;
int V_131 = V_215 ;
struct V_42 * V_3 = V_490 -> V_2 -> V_3 ;
* V_536 = 0 ;
V_39 = F_119 ( ( void * * ) & V_117 , & V_81 , V_490 , 0 , 0 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_490 -> V_2 ) )
V_131 |= V_259 ;
V_528 = F_29 ( V_81 ) ;
V_125 [ 0 ] . V_157 = & V_528 ;
V_125 [ 0 ] . V_158 = sizeof( T_11 ) ;
V_125 [ 1 ] . V_157 = V_117 ;
V_125 [ 1 ] . V_158 = V_81 ;
V_39 = F_133 ( V_121 , V_3 , & V_482 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_538 * ) V_126 . V_157 ;
V_13 = F_28 ( V_123 ) ;
if ( V_13 -> V_249 == V_539 ) {
F_45 ( V_127 , V_126 . V_157 ) ;
return 0 ;
}
if ( V_39 ) {
F_72 ( V_490 -> V_2 , V_527 ) ;
F_9 ( V_160 , L_72 , V_39 ) ;
} else {
* V_536 = F_41 ( V_123 -> V_103 ) ;
if ( ( * V_536 > V_540 ) ||
( * V_536 > V_490 -> V_501 ) ) {
F_9 ( V_49 , L_73 ,
* V_536 , V_490 -> V_501 ) ;
V_39 = - V_52 ;
* V_536 = 0 ;
}
}
if ( * V_80 ) {
memcpy ( * V_80 , ( char * ) V_13 + V_123 -> V_294 , * V_536 ) ;
F_45 ( V_127 , V_126 . V_157 ) ;
} else if ( V_127 != V_212 ) {
* V_80 = V_126 . V_157 ;
if ( V_127 == V_211 )
* V_537 = V_211 ;
else if ( V_127 == V_541 )
* V_537 = V_541 ;
}
return V_39 ;
}
static void
F_134 ( struct V_459 * V_460 )
{
struct V_542 * V_543 = V_460 -> V_461 ;
struct V_1 * V_2 = F_123 ( V_543 -> V_511 -> V_512 ) ;
unsigned int V_544 ;
struct V_545 * V_123 = (struct V_545 * ) V_460 -> V_463 ;
unsigned int V_464 = 1 ;
switch ( V_460 -> V_465 ) {
case V_466 :
V_464 = F_22 ( V_123 -> V_97 . V_86 . V_23 ) ;
V_543 -> V_240 = F_135 ( V_460 , V_2 -> V_3 -> V_9 , 0 ) ;
if ( V_543 -> V_240 != 0 )
break;
V_544 = F_41 ( V_123 -> V_103 ) ;
if ( V_544 > V_543 -> V_521 )
V_544 &= 0xFFFF ;
if ( V_544 < V_543 -> V_521 )
V_543 -> V_240 = - V_546 ;
else
V_543 -> V_521 = V_544 ;
break;
case V_524 :
case V_525 :
V_543 -> V_240 = - V_58 ;
break;
default:
V_543 -> V_240 = - V_52 ;
break;
}
if ( V_543 -> V_240 )
F_72 ( V_2 , V_547 ) ;
F_127 ( V_69 , & V_543 -> V_469 ) ;
F_104 ( V_460 ) ;
F_105 ( V_2 -> V_3 -> V_9 , V_464 , 0 ) ;
}
int
F_136 ( struct V_542 * V_543 ,
void (* F_137)( struct V_548 * V_548 ) )
{
int V_39 = - V_493 , V_131 = 0 ;
struct V_549 * V_117 = NULL ;
struct V_12 * V_13 ;
struct V_1 * V_2 = F_123 ( V_543 -> V_511 -> V_512 ) ;
struct V_19 * V_9 = V_2 -> V_3 -> V_9 ;
struct V_124 V_125 [ 2 ] ;
struct V_481 V_482 = { } ;
V_39 = F_27 ( V_46 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 ) {
if ( V_39 == - V_58 && V_543 -> V_21 ) {
V_543 -> V_21 = 0 ;
F_4 ( & V_9 -> V_20 ) ;
V_9 -> V_529 -- ;
F_6 ( & V_9 -> V_20 ) ;
}
goto V_550;
}
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
V_13 = F_28 ( V_117 ) ;
V_13 -> V_24 = F_7 ( V_543 -> V_511 -> V_496 ) ;
V_117 -> V_302 = V_543 -> V_511 -> V_300 . V_303 ;
V_117 -> V_304 = V_543 -> V_511 -> V_300 . V_305 ;
V_117 -> V_551 = 0 ;
V_117 -> V_552 = 0 ;
V_117 -> V_209 = 0 ;
V_117 -> V_502 = F_120 ( V_543 -> V_421 ) ;
V_117 -> V_294 = F_3 (
F_64 ( struct V_549 , V_251 ) - 4 ) ;
V_117 -> V_508 = 0 ;
V_125 [ 0 ] . V_158 = 4 ;
V_125 [ 0 ] . V_157 = V_117 ;
V_125 [ 1 ] . V_158 = F_37 ( V_117 ) - 1 ;
V_125 [ 1 ] . V_157 = ( char * ) V_117 + 4 ;
V_482 . V_483 = V_125 ;
V_482 . V_484 = 2 ;
V_482 . V_513 = V_543 -> V_514 ;
V_482 . V_515 = V_543 -> V_516 ;
V_482 . V_517 = V_543 -> V_518 ;
V_482 . V_519 = V_543 -> V_520 ;
F_9 ( V_49 , L_74 ,
V_543 -> V_421 , V_543 -> V_521 ) ;
V_117 -> V_500 = F_7 ( V_543 -> V_521 ) ;
F_34 ( & V_117 -> V_97 , V_543 -> V_521 - 1 ) ;
if ( V_543 -> V_21 ) {
V_13 -> V_30 = F_3 ( F_121 ( V_543 -> V_521 ,
V_455 ) ) ;
V_13 -> V_23 = V_13 -> V_30 ;
F_4 ( & V_9 -> V_20 ) ;
V_9 -> V_21 += V_543 -> V_21 -
F_22 ( V_13 -> V_30 ) ;
F_6 ( & V_9 -> V_20 ) ;
F_129 ( & V_9 -> V_530 ) ;
V_131 |= V_531 ;
}
F_130 ( & V_543 -> V_532 ) ;
V_39 = F_117 ( V_9 , & V_482 , NULL , F_134 , NULL ,
V_543 , V_131 ) ;
if ( V_39 ) {
F_131 ( & V_543 -> V_532 , F_137 ) ;
F_72 ( V_2 , V_547 ) ;
}
V_550:
F_39 ( V_117 ) ;
return V_39 ;
}
int
F_138 ( const unsigned int V_121 , struct V_489 * V_490 ,
unsigned int * V_536 , struct V_124 * V_125 , int V_553 )
{
int V_39 = 0 ;
struct V_549 * V_117 = NULL ;
struct V_545 * V_123 = NULL ;
int V_127 ;
struct V_124 V_126 ;
int V_131 = 0 ;
* V_536 = 0 ;
if ( V_553 < 1 )
return V_39 ;
V_39 = F_27 ( V_46 , V_490 -> V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( V_490 -> V_2 -> V_3 -> V_9 == NULL )
return - V_495 ;
if ( F_1 ( V_490 -> V_2 ) )
V_131 |= V_259 ;
V_117 -> V_97 . V_86 . V_24 = F_7 ( V_490 -> V_496 ) ;
V_117 -> V_302 = V_490 -> V_303 ;
V_117 -> V_304 = V_490 -> V_305 ;
V_117 -> V_551 = 0 ;
V_117 -> V_552 = 0 ;
V_117 -> V_209 = 0 ;
V_117 -> V_500 = F_7 ( V_490 -> V_501 ) ;
V_117 -> V_502 = F_120 ( V_490 -> V_421 ) ;
V_117 -> V_294 = F_3 (
F_64 ( struct V_549 , V_251 ) - 4 ) ;
V_117 -> V_508 = 0 ;
V_125 [ 0 ] . V_157 = ( char * ) V_117 ;
V_125 [ 0 ] . V_158 = F_37 ( V_117 ) + 4 - 1 ;
F_34 ( V_117 , V_490 -> V_501 - 1 ) ;
V_39 = F_38 ( V_121 , V_490 -> V_2 -> V_3 , V_125 , V_553 + 1 ,
& V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_545 * ) V_126 . V_157 ;
if ( V_39 ) {
F_72 ( V_490 -> V_2 , V_547 ) ;
F_9 ( V_160 , L_75 , V_39 ) ;
} else
* V_536 = F_41 ( V_123 -> V_103 ) ;
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
static unsigned int
F_139 ( char * V_554 , char * V_428 , char * * V_555 , T_9 V_556 )
{
int V_237 ;
unsigned int V_557 = 0 ;
unsigned int V_558 = 0 ;
T_12 * V_559 ;
if ( V_554 == NULL )
return 0 ;
V_559 = ( T_12 * ) V_554 ;
while ( 1 ) {
V_559 = ( T_12 * )
( ( char * ) V_559 + V_558 ) ;
if ( ( char * ) V_559 + V_556 > V_428 ) {
F_9 ( V_160 , L_76 ) ;
break;
}
V_237 = F_41 ( V_559 -> V_560 ) ;
if ( ( char * ) V_559 + V_237 + V_556 > V_428 ) {
F_9 ( V_160 , L_77 ,
V_428 ) ;
break;
}
* V_555 = ( char * ) V_559 ;
V_557 ++ ;
V_558 = F_41 ( V_559 -> V_561 ) ;
if ( ! V_558 )
break;
}
return V_557 ;
}
int
F_140 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 , int V_562 ,
struct V_563 * V_564 )
{
struct V_565 * V_117 ;
struct V_566 * V_123 = NULL ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_237 ;
int V_127 = V_212 ;
unsigned char * V_567 ;
struct V_19 * V_9 ;
struct V_42 * V_3 = V_2 -> V_3 ;
T_1 V_568 = F_3 ( '*' ) ;
char * V_426 ;
unsigned int V_569 = V_189 ;
T_9 V_570 ;
int V_131 = 0 ;
if ( V_3 && ( V_3 -> V_9 ) )
V_9 = V_3 -> V_9 ;
else
return - V_52 ;
V_39 = F_27 ( V_76 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
switch ( V_564 -> V_571 ) {
case V_572 :
V_117 -> V_573 = V_574 ;
V_570 = sizeof( T_12 ) - 1 ;
break;
case V_575 :
V_117 -> V_573 = V_576 ;
V_570 = sizeof( V_577 ) - 1 ;
break;
default:
F_9 ( V_160 , L_78 ,
V_564 -> V_571 ) ;
V_39 = - V_255 ;
goto V_578;
}
V_117 -> V_579 = F_7 ( V_562 ) ;
V_117 -> V_302 = V_303 ;
V_117 -> V_304 = V_305 ;
V_237 = 0x2 ;
V_567 = V_117 -> V_251 ;
memcpy ( V_567 , & V_568 , V_237 ) ;
V_117 -> V_580 =
F_3 ( sizeof( struct V_565 ) - 1 - 4 ) ;
V_117 -> V_560 = F_3 ( V_237 ) ;
V_569 = F_5 (unsigned int, output_size, server->maxBuf) ;
V_569 = F_5 (unsigned int, output_size, 2 << 15 ) ;
V_117 -> V_442 = F_7 ( V_569 ) ;
V_125 [ 0 ] . V_157 = ( char * ) V_117 ;
V_125 [ 0 ] . V_158 = F_37 ( V_117 ) + 4 - 1 ;
V_125 [ 1 ] . V_157 = ( char * ) ( V_117 -> V_251 ) ;
V_125 [ 1 ] . V_158 = V_237 ;
F_34 ( V_117 , V_237 - 1 ) ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 2 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_566 * ) V_126 . V_157 ;
if ( V_39 ) {
if ( V_39 == - V_526 &&
V_123 -> V_97 . V_86 . V_249 == V_581 ) {
V_564 -> V_582 = true ;
V_39 = 0 ;
}
F_72 ( V_2 , V_583 ) ;
goto V_578;
}
V_39 = F_95 ( F_22 ( V_123 -> V_445 ) ,
F_41 ( V_123 -> V_442 ) , & V_123 -> V_97 ,
V_570 ) ;
if ( V_39 )
goto V_578;
V_564 -> V_584 = true ;
if ( V_564 -> V_585 ) {
if ( V_564 -> V_586 )
F_39 ( V_564 -> V_585 ) ;
else
F_141 ( V_564 -> V_585 ) ;
}
V_564 -> V_585 = ( char * ) V_123 ;
V_564 -> V_587 = V_564 -> V_588 = 4 +
( char * ) & V_123 -> V_97 + F_22 ( V_123 -> V_445 ) ;
V_426 = F_37 ( V_123 ) + 4 + ( char * ) & V_123 -> V_97 ;
V_564 -> V_589 =
F_139 ( V_564 -> V_587 , V_426 ,
& V_564 -> V_588 , V_570 ) ;
V_564 -> V_590 += V_564 -> V_589 ;
F_9 ( V_49 , L_79 ,
V_564 -> V_589 , V_564 -> V_590 ,
V_564 -> V_587 , V_564 -> V_588 ) ;
if ( V_127 == V_541 )
V_564 -> V_586 = false ;
else if ( V_127 == V_211 )
V_564 -> V_586 = true ;
else
F_9 ( V_160 , L_80 ) ;
return V_39 ;
V_578:
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
static int
F_142 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 , T_3 V_496 , T_8 V_430 ,
T_8 V_431 , T_3 V_432 , unsigned int V_321 ,
void * * V_228 , unsigned int * V_556 )
{
struct V_591 * V_117 ;
struct V_592 * V_123 = NULL ;
struct V_124 * V_125 ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 ;
unsigned int V_593 ;
struct V_42 * V_3 = V_2 -> V_3 ;
int V_131 = 0 ;
if ( ! V_3 || ! ( V_3 -> V_9 ) )
return - V_52 ;
if ( ! V_321 )
return - V_255 ;
V_125 = F_62 ( sizeof( struct V_124 ) * V_321 , V_236 ) ;
if ( ! V_125 )
return - V_89 ;
V_39 = F_27 ( V_79 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 ) {
F_48 ( V_125 ) ;
return V_39 ;
}
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
V_117 -> V_97 . V_86 . V_24 = F_7 ( V_496 ) ;
V_117 -> V_438 = V_431 ;
V_117 -> V_439 = V_430 ;
V_117 -> V_302 = V_303 ;
V_117 -> V_304 = V_305 ;
V_117 -> V_440 = F_7 ( V_432 ) ;
V_117 -> V_594 =
F_3 ( sizeof( struct V_591 ) - 1 - 4 ) ;
V_117 -> V_595 = F_7 ( * V_556 ) ;
F_34 ( V_117 , * V_556 - 1 ) ;
memcpy ( V_117 -> V_251 , * V_228 , * V_556 ) ;
V_125 [ 0 ] . V_157 = ( char * ) V_117 ;
V_125 [ 0 ] . V_158 = F_37 ( V_117 ) + 4 ;
for ( V_593 = 1 ; V_593 < V_321 ; V_593 ++ ) {
F_34 ( V_117 , V_556 [ V_593 ] ) ;
F_81 ( & V_117 -> V_595 , V_556 [ V_593 ] ) ;
V_125 [ V_593 ] . V_157 = ( char * ) V_228 [ V_593 ] ;
V_125 [ V_593 ] . V_158 = V_556 [ V_593 ] ;
}
V_39 = F_38 ( V_121 , V_3 , V_125 , V_321 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_592 * ) V_126 . V_157 ;
if ( V_39 != 0 )
F_72 ( V_2 , V_596 ) ;
F_45 ( V_127 , V_123 ) ;
F_48 ( V_125 ) ;
return V_39 ;
}
int
F_143 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 , T_1 * V_597 )
{
struct V_598 V_599 ;
void * * V_228 ;
unsigned int V_556 [ 2 ] ;
int V_39 ;
int V_237 = ( 2 * F_89 ( ( V_346 * ) V_597 , V_347 ) ) ;
V_228 = F_62 ( sizeof( void * ) * 2 , V_236 ) ;
if ( ! V_228 )
return - V_89 ;
V_599 . V_600 = 1 ;
V_599 . V_601 = 0 ;
V_599 . V_560 = F_7 ( V_237 ) ;
V_228 [ 0 ] = & V_599 ;
V_556 [ 0 ] = sizeof( struct V_598 ) ;
V_228 [ 1 ] = V_597 ;
V_556 [ 1 ] = V_237 + 2 ;
V_39 = F_142 ( V_121 , V_2 , V_303 , V_305 ,
V_26 -> V_27 , V_602 , V_449 ,
0 , 2 , V_228 , V_556 ) ;
F_48 ( V_228 ) ;
return V_39 ;
}
int
F_144 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 )
{
T_5 V_603 = 1 ;
void * V_228 ;
unsigned int V_556 ;
V_228 = & V_603 ;
V_556 = 1 ;
return F_142 ( V_121 , V_2 , V_303 , V_305 ,
V_26 -> V_27 , V_604 , V_449 ,
0 , 1 , & V_228 , & V_556 ) ;
}
int
F_145 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 , T_1 * V_597 )
{
struct V_605 V_599 ;
void * * V_228 ;
unsigned int V_556 [ 2 ] ;
int V_39 ;
int V_237 = ( 2 * F_89 ( ( V_346 * ) V_597 , V_347 ) ) ;
V_228 = F_62 ( sizeof( void * ) * 2 , V_236 ) ;
if ( ! V_228 )
return - V_89 ;
V_599 . V_600 = 0 ;
V_599 . V_601 = 0 ;
V_599 . V_560 = F_7 ( V_237 ) ;
V_228 [ 0 ] = & V_599 ;
V_556 [ 0 ] = sizeof( struct V_605 ) ;
V_228 [ 1 ] = V_597 ;
V_556 [ 1 ] = V_237 + 2 ;
V_39 = F_142 ( V_121 , V_2 , V_303 , V_305 ,
V_26 -> V_27 , V_606 , V_449 ,
0 , 2 , V_228 , V_556 ) ;
F_48 ( V_228 ) ;
return V_39 ;
}
int
F_146 ( const unsigned int V_121 , struct V_1 * V_2 , T_7 V_303 ,
T_7 V_305 , T_3 V_496 , T_10 * V_607 , bool V_608 )
{
struct V_609 V_599 ;
void * V_228 ;
unsigned int V_556 ;
V_599 . V_384 = * V_607 ;
V_228 = & V_599 ;
V_556 = sizeof( struct V_609 ) ;
if ( V_608 )
return F_142 ( V_121 , V_2 , V_303 , V_305 ,
V_496 , V_610 , V_449 ,
0 , 1 , & V_228 , & V_556 ) ;
else
return F_142 ( V_121 , V_2 , V_303 , V_305 ,
V_496 , V_611 , V_449 ,
0 , 1 , & V_228 , & V_556 ) ;
}
int
F_147 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 , T_13 * V_80 )
{
unsigned int V_556 ;
V_556 = sizeof( T_13 ) ;
return F_142 ( V_121 , V_2 , V_303 , V_305 ,
V_26 -> V_27 , V_612 , V_449 ,
0 , 1 , ( void * * ) & V_80 , & V_556 ) ;
}
int
F_148 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 ,
struct V_613 * V_614 , int V_615 , int V_616 )
{
return F_142 ( V_121 , V_2 , V_303 , V_305 ,
V_26 -> V_27 , 0 , V_454 , V_616 ,
1 , ( void * * ) & V_614 , & V_615 ) ;
}
int
F_149 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 ,
struct V_447 * V_80 , int V_237 )
{
return F_142 ( V_121 , V_2 , V_303 , V_305 ,
V_26 -> V_27 , V_448 , V_449 ,
0 , 1 , ( void * * ) & V_80 , & V_237 ) ;
}
int
F_150 ( const unsigned int V_121 , struct V_1 * V_2 ,
const T_7 V_303 , const T_7 V_305 ,
T_5 V_617 )
{
int V_39 ;
struct V_618 * V_117 = NULL ;
int V_131 = V_619 ;
F_9 ( V_49 , L_81 ) ;
V_39 = F_27 ( V_57 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
V_117 -> V_620 = V_305 ;
V_117 -> V_621 = V_303 ;
V_117 -> V_389 = V_617 ;
V_117 -> V_97 . V_86 . V_23 = F_3 ( 1 ) ;
V_39 = F_71 ( V_121 , V_2 -> V_3 , ( char * ) V_117 , V_131 ) ;
F_39 ( V_117 ) ;
if ( V_39 ) {
F_72 ( V_2 , V_622 ) ;
F_9 ( V_49 , L_82 , V_39 ) ;
}
return V_39 ;
}
static void
F_151 ( struct V_623 * V_624 ,
struct V_625 * V_626 )
{
V_626 -> V_627 = F_41 ( V_624 -> V_628 ) *
F_41 ( V_624 -> V_629 ) ;
V_626 -> V_630 = F_152 ( V_624 -> V_631 ) ;
V_626 -> V_632 = V_626 -> V_633 =
F_152 ( V_624 -> V_634 ) ;
return;
}
static int
F_153 ( struct V_124 * V_125 , struct V_1 * V_2 , int V_635 ,
int V_636 , T_7 V_303 , T_7 V_305 )
{
int V_39 ;
struct V_436 * V_117 ;
F_9 ( V_49 , L_83 , V_635 ) ;
if ( ( V_2 -> V_3 == NULL ) || ( V_2 -> V_3 -> V_9 == NULL ) )
return - V_52 ;
V_39 = F_27 ( V_78 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_438 = V_637 ;
V_117 -> V_439 = V_635 ;
V_117 -> V_302 = V_303 ;
V_117 -> V_304 = V_305 ;
V_117 -> V_441 =
F_3 ( sizeof( struct V_436 ) - 1 - 4 ) ;
V_117 -> V_442 = F_7 (
V_636 + sizeof( struct V_437 ) - 1 - 4 ) ;
V_125 -> V_157 = ( char * ) V_117 ;
V_125 -> V_158 = F_37 ( V_117 ) + 4 ;
return 0 ;
}
int
F_154 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 , struct V_625 * V_638 )
{
struct V_437 * V_123 = NULL ;
struct V_124 V_125 ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 ;
struct V_42 * V_3 = V_2 -> V_3 ;
struct V_623 * V_599 = NULL ;
int V_131 = 0 ;
V_39 = F_153 ( & V_125 , V_2 , V_639 ,
sizeof( struct V_623 ) ,
V_303 , V_305 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
V_39 = F_38 ( V_121 , V_3 , & V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_125 . V_157 ) ;
if ( V_39 ) {
F_72 ( V_2 , V_443 ) ;
goto V_640;
}
V_123 = (struct V_437 * ) V_126 . V_157 ;
V_599 = (struct V_623 * ) ( 4 +
F_22 ( V_123 -> V_445 ) + ( char * ) & V_123 -> V_97 ) ;
V_39 = F_95 ( F_22 ( V_123 -> V_445 ) ,
F_41 ( V_123 -> V_442 ) , & V_123 -> V_97 ,
sizeof( struct V_623 ) ) ;
if ( ! V_39 )
F_151 ( V_599 , V_638 ) ;
V_640:
F_45 ( V_127 , V_126 . V_157 ) ;
return V_39 ;
}
int
F_155 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_303 , T_7 V_305 , int V_635 )
{
struct V_437 * V_123 = NULL ;
struct V_124 V_125 ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 , V_641 , V_434 ;
struct V_42 * V_3 = V_2 -> V_3 ;
unsigned int V_642 , V_421 ;
int V_131 = 0 ;
if ( V_635 == V_643 ) {
V_641 = sizeof( V_644 ) ;
V_434 = sizeof( V_644 ) ;
} else if ( V_635 == V_645 ) {
V_641 = sizeof( V_646 ) ;
V_434 = V_647 ;
} else if ( V_635 == V_648 ) {
V_641 = sizeof( struct V_649 ) ;
V_434 = sizeof( struct V_649 ) ;
} else {
F_9 ( V_49 , L_84 , V_635 ) ;
return - V_255 ;
}
V_39 = F_153 ( & V_125 , V_2 , V_635 , V_641 ,
V_303 , V_305 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
V_39 = F_38 ( V_121 , V_3 , & V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_125 . V_157 ) ;
if ( V_39 ) {
F_72 ( V_2 , V_443 ) ;
goto V_650;
}
V_123 = (struct V_437 * ) V_126 . V_157 ;
V_642 = F_41 ( V_123 -> V_442 ) ;
V_421 = F_22 ( V_123 -> V_445 ) ;
V_39 = F_95 ( V_421 , V_642 , & V_123 -> V_97 , V_434 ) ;
if ( V_39 )
goto V_650;
if ( V_635 == V_645 )
memcpy ( & V_2 -> V_651 , 4 + V_421
+ ( char * ) & V_123 -> V_97 , F_5 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_635 == V_643 )
memcpy ( & V_2 -> V_652 , 4 + V_421
+ ( char * ) & V_123 -> V_97 , sizeof( V_644 ) ) ;
else if ( V_635 == V_648 ) {
struct V_649 * V_653 = (struct V_649 * )
( 4 + V_421 + ( char * ) & V_123 -> V_97 ) ;
V_2 -> V_654 = F_41 ( V_653 -> V_36 ) ;
V_2 -> V_655 =
F_41 ( V_653 -> V_656 ) ;
}
V_650:
F_45 ( V_127 , V_126 . V_157 ) ;
return V_39 ;
}
int
F_156 ( const unsigned int V_121 , struct V_1 * V_2 ,
const T_14 V_657 , const T_14 V_305 , const T_6 V_496 ,
const T_6 V_658 , struct V_659 * V_80 )
{
int V_39 = 0 ;
struct V_660 * V_117 = NULL ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
int V_661 ;
unsigned int V_662 ;
int V_131 = V_663 ;
F_9 ( V_49 , L_85 , V_658 ) ;
V_39 = F_27 ( V_74 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
V_117 -> V_97 . V_86 . V_24 = F_7 ( V_496 ) ;
V_117 -> V_664 = F_3 ( V_658 ) ;
V_117 -> V_302 = V_657 ;
V_117 -> V_304 = V_305 ;
V_662 = V_658 * sizeof( struct V_659 ) ;
F_34 ( V_117 , V_662 - sizeof( struct V_659 ) ) ;
V_125 [ 0 ] . V_157 = ( char * ) V_117 ;
V_125 [ 0 ] . V_158 = F_37 ( V_117 ) + 4 - V_662 ;
V_125 [ 1 ] . V_157 = ( char * ) V_80 ;
V_125 [ 1 ] . V_158 = V_662 ;
F_26 ( & V_2 -> V_91 . V_665 . V_666 ) ;
V_39 = F_38 ( V_121 , V_2 -> V_3 , V_125 , 2 , & V_661 , V_131 ,
& V_126 ) ;
F_39 ( V_117 ) ;
if ( V_39 ) {
F_9 ( V_49 , L_86 , V_39 ) ;
F_72 ( V_2 , V_667 ) ;
}
return V_39 ;
}
int
F_157 ( const unsigned int V_121 , struct V_1 * V_2 ,
const T_14 V_657 , const T_14 V_305 , const T_6 V_496 ,
const T_14 V_501 , const T_14 V_421 , const T_6 V_668 ,
const bool V_669 )
{
struct V_659 V_670 ;
V_670 . V_502 = F_120 ( V_421 ) ;
V_670 . V_500 = F_120 ( V_501 ) ;
V_670 . V_36 = F_7 ( V_668 ) ;
if ( ! V_669 && V_668 != V_671 )
V_670 . V_36 |= F_7 ( V_672 ) ;
return F_156 ( V_121 , V_2 , V_657 , V_305 , V_496 , 1 , & V_670 ) ;
}
int
F_158 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_5 * V_673 , const T_15 V_674 )
{
int V_39 ;
struct V_675 * V_117 = NULL ;
int V_131 = V_619 ;
F_9 ( V_49 , L_87 ) ;
V_39 = F_27 ( V_57 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_259 ;
V_117 -> V_97 . V_86 . V_23 = F_3 ( 1 ) ;
V_117 -> V_17 = F_3 ( 36 ) ;
F_34 ( V_117 , 12 ) ;
memcpy ( V_117 -> V_676 , V_673 , 16 ) ;
V_117 -> V_677 = V_674 ;
V_39 = F_71 ( V_121 , V_2 -> V_3 , ( char * ) V_117 , V_131 ) ;
F_39 ( V_117 ) ;
if ( V_39 ) {
F_72 ( V_2 , V_622 ) ;
F_9 ( V_49 , L_88 , V_39 ) ;
}
return V_39 ;
}
