static void
F_1 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_4 * V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 ;
char * V_8 = ( char * ) V_2 ;
T_2 V_9 = V_10 [ F_2 ( V_3 ) ] ;
memset ( V_8 , 0 , 256 ) ;
V_2 -> V_11 = F_3 ( V_9 + sizeof( struct V_1 )
- 4 ) ;
V_2 -> V_12 [ 0 ] = 0xFE ;
V_2 -> V_12 [ 1 ] = 'S' ;
V_2 -> V_12 [ 2 ] = 'M' ;
V_2 -> V_12 [ 3 ] = 'B' ;
V_2 -> V_13 = F_4 ( 64 ) ;
V_2 -> V_14 = V_3 ;
V_2 -> V_15 = F_4 ( 2 ) ;
V_2 -> V_16 = F_5 ( ( T_2 ) V_17 -> V_18 ) ;
if ( ! V_5 )
goto V_19;
if ( ( V_5 -> V_20 ) &&
( V_5 -> V_20 -> V_21 -> V_22 & V_23 ) )
V_2 -> V_24 = F_4 ( 1 ) ;
V_2 -> V_25 = V_5 -> V_26 ;
if ( V_5 -> V_20 )
V_2 -> V_27 = V_5 -> V_20 -> V_28 ;
if ( V_5 -> V_20 && V_5 -> V_20 -> V_21 && V_5 -> V_20 -> V_21 -> V_29 )
V_2 -> V_30 |= V_31 ;
V_19:
V_7 -> V_32 = F_4 ( V_9 ) ;
return;
}
static int
F_6 ( T_1 V_33 , struct V_4 * V_5 )
{
int V_34 = 0 ;
struct V_35 * V_36 ;
struct V_37 * V_20 ;
struct V_38 * V_21 ;
if ( V_5 == NULL )
return V_34 ;
if ( V_33 == V_39 )
return V_34 ;
if ( V_5 -> V_40 == V_41 ) {
if ( ( V_33 != V_42 ) &&
( V_33 != V_43 ) &&
( V_33 != V_44 ) ) {
F_7 ( V_45 , L_1 ,
V_33 ) ;
return - V_46 ;
}
}
if ( ( ! V_5 -> V_20 ) || ( V_5 -> V_20 -> V_47 == V_41 ) ||
( ! V_5 -> V_20 -> V_21 ) )
return - V_48 ;
V_20 = V_5 -> V_20 ;
V_21 = V_20 -> V_21 ;
while ( V_21 -> V_49 == V_50 ) {
switch ( V_33 ) {
case V_44 :
case V_51 :
case V_52 :
case V_53 :
return - V_54 ;
}
F_8 ( V_21 -> V_55 ,
( V_21 -> V_49 != V_50 ) , 10 * V_56 ) ;
if ( V_21 -> V_49 != V_50 )
break;
if ( ! V_5 -> V_57 ) {
F_7 ( V_45 , L_2 ) ;
return - V_58 ;
}
}
if ( ! V_5 -> V_20 -> V_59 && ! V_5 -> V_59 )
return V_34 ;
V_36 = F_9 () ;
F_10 ( & V_5 -> V_20 -> V_60 ) ;
V_34 = F_11 ( 0 , V_5 -> V_20 ) ;
if ( ! V_34 && V_5 -> V_20 -> V_59 )
V_34 = F_12 ( 0 , V_5 -> V_20 , V_36 ) ;
if ( V_34 || ! V_5 -> V_59 ) {
F_13 ( & V_5 -> V_20 -> V_60 ) ;
goto V_19;
}
F_14 ( V_5 ) ;
V_34 = F_15 ( 0 , V_5 -> V_20 , V_5 -> V_61 , V_5 , V_36 ) ;
F_13 ( & V_5 -> V_20 -> V_60 ) ;
F_7 ( V_45 , L_3 , V_34 ) ;
if ( V_34 )
goto V_19;
F_16 ( & V_62 ) ;
V_19:
switch ( V_33 ) {
case V_63 :
case V_64 :
case V_42 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
return - V_54 ;
}
F_17 ( V_36 ) ;
return V_34 ;
}
static int
F_18 ( T_1 V_33 , struct V_4 * V_5 ,
void * * V_71 )
{
int V_34 = 0 ;
V_34 = F_6 ( V_33 , V_5 ) ;
if ( V_34 )
return V_34 ;
* V_71 = F_19 () ;
if ( * V_71 == NULL ) {
return - V_72 ;
}
F_1 ( (struct V_1 * ) * V_71 , V_33 , V_5 ) ;
if ( V_5 != NULL ) {
#ifdef F_20
T_3 V_73 = F_2 ( V_33 ) ;
F_21 ( & V_5 -> V_74 . V_75 . V_76 [ V_73 ] ) ;
#endif
F_21 ( & V_5 -> V_77 ) ;
}
return V_34 ;
}
static void
F_22 ( int V_78 , void * V_79 )
{
if ( V_78 == V_80 )
F_23 ( V_79 ) ;
else if ( V_78 == V_81 )
F_24 ( V_79 ) ;
}
int
F_25 ( const unsigned int V_82 , struct V_37 * V_20 )
{
struct V_83 * V_84 ;
struct V_85 * V_79 ;
struct V_86 V_87 [ 1 ] ;
int V_34 = 0 ;
int V_78 ;
struct V_38 * V_21 = V_20 -> V_21 ;
int V_88 , V_89 ;
char * V_90 ;
int V_91 = V_92 ;
F_7 ( V_45 , L_4 ) ;
if ( ! V_21 ) {
F_26 ( 1 , L_5 , V_93 ) ;
return - V_48 ;
}
V_34 = F_18 ( V_94 , NULL , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_27 = 0 ;
V_84 -> V_95 [ 0 ] = F_4 ( V_20 -> V_21 -> V_96 -> V_97 ) ;
V_84 -> V_98 = F_4 ( 1 ) ;
F_27 ( V_84 , 2 ) ;
if ( V_20 -> V_29 )
V_84 -> V_99 = F_4 ( V_100 ) ;
else if ( V_101 & V_102 )
V_84 -> V_99 = F_4 ( V_103 ) ;
else
V_84 -> V_99 = 0 ;
V_84 -> V_104 = F_5 ( V_20 -> V_21 -> V_96 -> V_105 ) ;
memcpy ( V_84 -> V_106 , V_107 , V_108 ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , V_91 ) ;
V_79 = (struct V_85 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 )
goto V_111;
F_7 ( V_45 , L_6 , V_79 -> V_99 ) ;
if ( V_79 -> V_112 == F_4 ( V_113 ) )
F_7 ( V_45 , L_7 ) ;
else if ( V_79 -> V_112 == F_4 ( V_114 ) )
F_7 ( V_45 , L_8 ) ;
else if ( V_79 -> V_112 == F_4 ( V_115 ) )
F_7 ( V_45 , L_9 ) ;
else if ( V_79 -> V_112 == F_4 ( V_116 ) )
F_7 ( V_45 , L_10 ) ;
else {
F_7 ( V_117 , L_11 ,
F_2 ( V_79 -> V_112 ) ) ;
V_34 = - V_48 ;
goto V_111;
}
V_21 -> V_118 = F_2 ( V_79 -> V_112 ) ;
V_21 -> V_119 = V_120 ;
V_21 -> V_121 = F_30 ( V_79 -> V_122 ) ;
V_21 -> V_123 = F_30 ( V_79 -> V_124 ) ;
V_21 -> V_125 = F_30 ( V_79 -> V_126 ) ;
V_21 -> V_127 = F_2 ( V_79 -> V_99 ) ;
V_21 -> V_22 = F_30 ( V_79 -> V_104 ) ;
V_21 -> V_22 |= V_128 | V_129 ;
V_90 = F_31 ( & V_88 , & V_89 ,
& V_79 -> V_2 ) ;
if ( V_89 == 0 )
F_7 ( V_45 , L_12 ) ;
V_34 = F_32 ( V_21 , V_20 -> V_29 ) ;
#ifdef F_33
if ( V_34 )
goto V_111;
if ( V_89 )
V_34 = F_34 ( V_90 , V_89 ,
& V_21 -> V_130 ) ;
if ( V_34 == 1 )
V_34 = 0 ;
else if ( V_34 == 0 ) {
V_34 = - V_48 ;
goto V_111;
}
#endif
V_111:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
int
F_35 ( const unsigned int V_82 , struct V_37 * V_20 ,
const struct V_35 * V_131 )
{
struct V_132 * V_84 ;
struct V_133 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_34 = 0 ;
int V_78 ;
T_4 V_134 = V_135 ;
struct V_38 * V_21 = V_20 -> V_21 ;
T_5 V_89 = 0 ;
char * V_90 ;
char * V_136 = NULL ;
bool V_137 = false ;
F_7 ( V_45 , L_13 ) ;
if ( ! V_21 ) {
F_26 ( 1 , L_5 , V_93 ) ;
return - V_48 ;
}
F_36 ( V_20 -> V_138 . V_139 ) ;
V_20 -> V_138 . V_139 = NULL ;
V_20 -> V_140 = F_37 ( sizeof( struct V_141 ) , V_142 ) ;
if ( ! V_20 -> V_140 )
return - V_72 ;
V_20 -> V_140 -> V_143 = true ;
V_20 -> V_144 = V_145 ;
V_146:
if ( V_134 == V_147 )
V_134 = V_148 ;
V_34 = F_18 ( V_149 , NULL , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_27 = 0 ;
V_84 -> V_150 = 0 ;
V_84 -> V_2 . V_15 = F_4 ( 3 ) ;
if ( V_21 -> V_29 )
V_84 -> V_99 = V_100 ;
else if ( V_101 & V_102 )
V_84 -> V_99 = V_103 ;
else
V_84 -> V_99 = 0 ;
V_84 -> V_104 = 0 ;
V_84 -> V_151 = 0 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
if ( V_134 == V_135 ) {
V_136 = F_37 ( sizeof( struct V_152 ) ,
V_142 ) ;
if ( V_136 == NULL ) {
V_34 = - V_72 ;
goto V_153;
}
F_38 ( V_136 , V_20 ) ;
if ( V_137 ) {
F_7 ( V_117 , L_14 ) ;
V_34 = - V_154 ;
F_36 ( V_136 ) ;
goto V_153;
} else {
V_89 = sizeof( struct V_152 ) ;
V_90 = V_136 ;
}
} else if ( V_134 == V_148 ) {
V_84 -> V_2 . V_27 = V_20 -> V_28 ;
V_136 = F_39 ( sizeof( struct V_152 ) + 500 ,
V_142 ) ;
if ( V_136 == NULL ) {
V_34 = - V_72 ;
goto V_153;
}
V_34 = F_40 ( V_136 , & V_89 , V_20 ,
V_131 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_15 ,
V_34 ) ;
goto V_153;
}
if ( V_137 ) {
F_7 ( V_117 , L_14 ) ;
V_34 = - V_154 ;
F_36 ( V_136 ) ;
goto V_153;
} else {
V_90 = V_136 ;
}
} else {
F_7 ( V_117 , L_16 ) ;
V_34 = - V_48 ;
goto V_153;
}
V_84 -> V_155 =
F_4 ( sizeof( struct V_132 ) -
1 - 4 ) ;
V_84 -> V_156 = F_4 ( V_89 ) ;
V_87 [ 1 ] . V_109 = V_90 ;
V_87 [ 1 ] . V_110 = V_89 ;
F_27 ( V_84 , V_89 - 1 ) ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 2 , & V_78 ,
V_157 | V_92 ) ;
F_36 ( V_90 ) ;
V_79 = (struct V_133 * ) V_87 [ 0 ] . V_109 ;
if ( V_78 != V_158 &&
V_79 -> V_2 . V_159 == V_160 ) {
if ( V_134 != V_135 ) {
F_7 ( V_117 , L_17 ) ;
goto V_153;
}
if ( F_41 ( struct V_133 , V_161 ) - 4 !=
F_2 ( V_79 -> V_155 ) ) {
F_7 ( V_117 , L_18 ,
F_2 ( V_79 -> V_155 ) ) ;
V_34 = - V_48 ;
goto V_153;
}
V_134 = V_147 ;
V_34 = 0 ;
V_20 -> V_28 = V_79 -> V_2 . V_27 ;
V_34 = F_42 ( V_79 -> V_161 ,
F_2 ( V_79 -> V_156 ) , V_20 ) ;
}
if ( V_34 != 0 )
goto V_153;
V_20 -> V_162 = F_2 ( V_79 -> V_163 ) ;
V_153:
F_22 ( V_78 , V_79 ) ;
if ( ( V_134 == V_147 ) && ( V_34 == 0 ) )
goto V_146;
if ( ! V_34 ) {
F_10 ( & V_21 -> V_164 ) ;
if ( V_21 -> V_29 && V_21 -> V_165 -> V_166 ) {
V_34 = V_21 -> V_165 -> V_166 ( V_20 ) ;
F_36 ( V_20 -> V_138 . V_139 ) ;
V_20 -> V_138 . V_139 = NULL ;
if ( V_34 ) {
F_7 ( V_45 ,
L_19 ) ;
F_13 ( & V_21 -> V_164 ) ;
goto V_167;
}
}
if ( ! V_21 -> V_168 ) {
V_21 -> V_169 = 0x2 ;
V_21 -> V_168 = true ;
}
F_13 ( & V_21 -> V_164 ) ;
F_7 ( V_45 , L_20 ) ;
F_43 ( & V_170 ) ;
V_20 -> V_47 = V_171 ;
V_20 -> V_59 = false ;
F_44 ( & V_170 ) ;
}
V_167:
if ( ! V_21 -> V_29 ) {
F_36 ( V_20 -> V_138 . V_139 ) ;
V_20 -> V_138 . V_139 = NULL ;
}
F_36 ( V_20 -> V_140 ) ;
return V_34 ;
}
int
F_45 ( const unsigned int V_82 , struct V_37 * V_20 )
{
struct V_172 * V_84 ;
int V_34 = 0 ;
struct V_38 * V_21 ;
F_7 ( V_45 , L_21 , V_20 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_20 -> V_59 )
goto V_173;
V_34 = F_18 ( V_174 , NULL , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_27 = V_20 -> V_28 ;
if ( V_21 -> V_29 )
V_84 -> V_2 . V_30 |= V_31 ;
V_34 = F_46 ( V_82 , V_20 , ( char * ) & V_84 -> V_2 , 0 ) ;
V_173:
return V_34 ;
}
static inline void F_47 ( struct V_4 * V_5 , T_3 V_175 )
{
F_21 ( & V_5 -> V_74 . V_75 . V_176 [ V_175 ] ) ;
}
int
F_15 ( const unsigned int V_82 , struct V_37 * V_20 , const char * V_177 ,
struct V_4 * V_5 , const struct V_35 * V_178 )
{
struct V_179 * V_84 ;
struct V_180 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_34 = 0 ;
int V_78 ;
int V_181 ;
struct V_38 * V_21 ;
T_1 * V_182 = NULL ;
F_7 ( V_45 , L_22 ) ;
if ( ( V_20 -> V_21 ) && V_177 )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_5 && V_5 -> V_183 )
return - V_184 ;
V_182 = F_37 ( V_185 * 2 , V_142 ) ;
if ( V_182 == NULL )
return - V_72 ;
V_181 = F_48 ( V_182 , V_177 , strlen ( V_177 ) , V_178 ) + 1 ;
V_181 *= 2 ;
if ( V_181 < 2 ) {
F_36 ( V_182 ) ;
return - V_186 ;
}
V_34 = F_18 ( V_39 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 ) {
F_36 ( V_182 ) ;
return V_34 ;
}
if ( V_5 == NULL ) {
V_84 -> V_2 . V_27 = V_20 -> V_28 ;
}
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
V_84 -> V_187 = F_4 ( sizeof( struct V_179 )
- 1 - 4 ) ;
V_84 -> V_188 = F_4 ( V_181 - 2 ) ;
V_87 [ 1 ] . V_109 = V_182 ;
V_87 [ 1 ] . V_110 = V_181 ;
F_27 ( V_84 , V_181 - 1 ) ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 2 , & V_78 , 0 ) ;
V_79 = (struct V_180 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 ) {
if ( V_5 ) {
F_47 ( V_5 , V_189 ) ;
V_5 -> V_59 = true ;
}
goto V_190;
}
if ( V_5 == NULL ) {
V_20 -> V_191 = V_79 -> V_2 . V_25 ;
goto V_192;
}
if ( V_79 -> V_193 & V_194 )
F_7 ( V_45 , L_23 ) ;
else if ( V_79 -> V_193 & V_195 ) {
V_5 -> V_196 = true ;
F_7 ( V_45 , L_24 ) ;
} else if ( V_79 -> V_193 & V_197 ) {
V_5 -> V_198 = true ;
F_7 ( V_45 , L_25 ) ;
} else {
F_7 ( V_117 , L_26 , V_79 -> V_193 ) ;
V_34 = - V_154 ;
goto V_190;
}
V_5 -> V_199 = F_30 ( V_79 -> V_200 ) ;
V_5 -> V_22 = V_79 -> V_104 ;
V_5 -> V_201 = F_30 ( V_79 -> V_202 ) ;
V_5 -> V_40 = V_171 ;
V_5 -> V_59 = false ;
V_5 -> V_26 = V_79 -> V_2 . V_25 ;
F_49 ( V_5 -> V_61 , V_177 , sizeof( V_5 -> V_61 ) ) ;
if ( ( V_79 -> V_104 & V_203 ) &&
( ( V_5 -> V_199 & V_204 ) == 0 ) )
F_7 ( V_117 , L_27 ) ;
V_192:
F_22 ( V_78 , V_79 ) ;
F_36 ( V_182 ) ;
return V_34 ;
V_190:
if ( V_79 -> V_2 . V_159 == V_205 ) {
F_7 ( V_117 , L_28 , V_177 ) ;
V_5 -> V_183 = true ;
}
goto V_192;
}
int
F_50 ( const unsigned int V_82 , struct V_4 * V_5 )
{
struct V_206 * V_84 ;
int V_34 = 0 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
F_7 ( V_45 , L_29 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( ( V_5 -> V_59 ) || ( V_5 -> V_20 -> V_59 ) )
return 0 ;
V_34 = F_18 ( V_44 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_46 ( V_82 , V_20 , ( char * ) & V_84 -> V_2 , 0 ) ;
if ( V_34 )
F_47 ( V_5 , V_207 ) ;
return V_34 ;
}
static struct V_208 *
F_51 ( void )
{
struct V_208 * V_209 ;
V_209 = F_39 ( sizeof( struct V_208 ) , V_142 ) ;
if ( ! V_209 )
return NULL ;
V_209 -> V_210 . V_211 = F_4 ( F_41
( struct V_208 , V_212 ) ) ;
V_209 -> V_210 . V_213 = F_5 ( 16 ) ;
V_209 -> V_210 . V_214 = F_4 ( F_41
( struct V_208 , V_215 ) ) ;
V_209 -> V_210 . V_216 = F_4 ( 4 ) ;
V_209 -> V_215 [ 0 ] = 'D' ;
V_209 -> V_215 [ 1 ] = 'H' ;
V_209 -> V_215 [ 2 ] = 'n' ;
V_209 -> V_215 [ 3 ] = 'Q' ;
return V_209 ;
}
static struct V_208 *
F_52 ( struct V_217 * V_218 )
{
struct V_208 * V_209 ;
V_209 = F_39 ( sizeof( struct V_208 ) , V_142 ) ;
if ( ! V_209 )
return NULL ;
V_209 -> V_210 . V_211 = F_4 ( F_41
( struct V_208 , V_212 ) ) ;
V_209 -> V_210 . V_213 = F_5 ( 16 ) ;
V_209 -> V_210 . V_214 = F_4 ( F_41
( struct V_208 , V_215 ) ) ;
V_209 -> V_210 . V_216 = F_4 ( 4 ) ;
V_209 -> V_212 . V_219 . V_220 = V_218 -> V_221 ;
V_209 -> V_212 . V_219 . V_222 = V_218 -> V_223 ;
V_209 -> V_215 [ 0 ] = 'D' ;
V_209 -> V_215 [ 1 ] = 'H' ;
V_209 -> V_215 [ 2 ] = 'n' ;
V_209 -> V_215 [ 3 ] = 'C' ;
return V_209 ;
}
static T_6
F_53 ( struct V_38 * V_21 , struct V_224 * V_79 ,
unsigned int * V_225 )
{
char * V_226 ;
struct V_227 * V_228 ;
unsigned int V_229 = 0 ;
char * V_230 ;
V_226 = ( char * ) V_79 + 4 + F_30 ( V_79 -> V_231 ) ;
V_228 = (struct V_227 * ) V_226 ;
do {
V_228 = (struct V_227 * ) ( ( char * ) V_228 + V_229 ) ;
V_230 = F_2 ( V_228 -> V_214 ) + ( char * ) V_228 ;
if ( F_2 ( V_228 -> V_216 ) != 4 ||
strncmp ( V_230 , L_30 , 4 ) ) {
V_229 = F_30 ( V_228 -> V_232 ) ;
continue;
}
return V_21 -> V_165 -> V_233 ( V_228 , V_225 ) ;
} while ( V_229 != 0 );
return 0 ;
}
static int
F_54 ( struct V_38 * V_21 , struct V_86 * V_87 ,
unsigned int * V_234 , T_6 * V_235 )
{
struct V_236 * V_84 = V_87 [ 0 ] . V_109 ;
unsigned int V_237 = * V_234 ;
V_87 [ V_237 ] . V_109 = V_21 -> V_165 -> V_238 ( V_235 + 1 , * V_235 ) ;
if ( V_87 [ V_237 ] . V_109 == NULL )
return - V_72 ;
V_87 [ V_237 ] . V_110 = V_21 -> V_96 -> V_239 ;
V_84 -> V_240 = V_241 ;
if ( ! V_84 -> V_231 )
V_84 -> V_231 = F_5 (
sizeof( struct V_236 ) - 4 +
V_87 [ V_237 - 1 ] . V_110 ) ;
F_55 ( & V_84 -> V_242 ,
V_21 -> V_96 -> V_239 ) ;
F_27 ( & V_84 -> V_2 , V_21 -> V_96 -> V_239 ) ;
* V_234 = V_237 + 1 ;
return 0 ;
}
static int
F_56 ( struct V_86 * V_87 , unsigned int * V_234 ,
struct V_243 * V_244 )
{
struct V_236 * V_84 = V_87 [ 0 ] . V_109 ;
unsigned int V_237 = * V_234 ;
if ( V_244 -> V_245 ) {
V_87 [ V_237 ] . V_109 = F_52 ( V_244 -> V_218 ) ;
V_244 -> V_245 = false ;
} else
V_87 [ V_237 ] . V_109 = F_51 () ;
if ( V_87 [ V_237 ] . V_109 == NULL )
return - V_72 ;
V_87 [ V_237 ] . V_110 = sizeof( struct V_208 ) ;
if ( ! V_84 -> V_231 )
V_84 -> V_231 =
F_5 ( sizeof( struct V_236 ) - 4 +
V_87 [ 1 ] . V_110 ) ;
F_55 ( & V_84 -> V_242 , sizeof( struct V_208 ) ) ;
F_27 ( & V_84 -> V_2 , sizeof( struct V_208 ) ) ;
* V_234 = V_237 + 1 ;
return 0 ;
}
int
F_57 ( const unsigned int V_82 , struct V_243 * V_244 , T_1 * V_246 ,
T_6 * V_235 , struct V_247 * V_209 ,
struct V_248 * * V_249 )
{
struct V_236 * V_84 ;
struct V_224 * V_79 ;
struct V_38 * V_21 ;
struct V_4 * V_5 = V_244 -> V_5 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_86 V_87 [ 4 ] ;
int V_78 ;
int V_250 ;
T_1 * V_251 = NULL ;
int V_252 ;
int V_34 = 0 ;
unsigned int V_253 = 2 ;
T_7 V_254 = 0 ;
F_7 ( V_45 , L_31 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_43 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
if ( V_244 -> V_255 & V_256 )
V_254 |= V_257 ;
V_84 -> V_258 = V_259 ;
V_84 -> V_260 = F_5 ( V_244 -> V_261 ) ;
V_84 -> V_262 = F_5 ( V_254 ) ;
V_84 -> V_263 = V_264 ;
V_84 -> V_265 = F_5 ( V_244 -> V_266 ) ;
V_84 -> V_267 = F_5 ( V_244 -> V_255 & V_268 ) ;
V_250 = ( 2 * F_58 ( ( V_269 * ) V_246 , V_270 ) ) + 2 ;
V_84 -> V_214 = F_4 ( sizeof( struct V_236 ) - 4 ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_84 -> V_216 = F_4 ( V_250 - 2 ) ;
V_87 [ 0 ] . V_110 -- ;
if ( V_250 % 8 != 0 ) {
V_252 = V_250 / 8 * 8 ;
if ( V_252 < V_250 )
V_252 += 8 ;
V_251 = F_39 ( V_252 , V_142 ) ;
if ( ! V_251 )
return - V_72 ;
memcpy ( ( char * ) V_251 , ( const char * ) V_246 ,
V_250 ) ;
V_250 = V_252 ;
V_246 = V_251 ;
}
V_87 [ 1 ] . V_110 = V_250 ;
V_87 [ 1 ] . V_109 = V_246 ;
F_27 ( V_84 , V_250 - 1 ) ;
if ( ! V_21 -> V_271 )
* V_235 = V_272 ;
if ( ! ( V_21 -> V_22 & V_273 ) ||
* V_235 == V_272 )
V_84 -> V_240 = * V_235 ;
else {
V_34 = F_54 ( V_21 , V_87 , & V_253 , V_235 ) ;
if ( V_34 ) {
F_23 ( V_84 ) ;
F_36 ( V_251 ) ;
return V_34 ;
}
}
if ( * V_235 == V_274 ) {
if ( V_21 -> V_22 & V_273 ) {
struct V_227 * V_210 =
(struct V_227 * ) V_87 [ V_253 - 1 ] . V_109 ;
V_210 -> V_232 =
F_5 ( V_21 -> V_96 -> V_239 ) ;
}
V_34 = F_56 ( V_87 , & V_253 , V_244 ) ;
if ( V_34 ) {
F_23 ( V_84 ) ;
F_36 ( V_251 ) ;
F_36 ( V_87 [ V_253 - 1 ] . V_109 ) ;
return V_34 ;
}
}
V_34 = F_29 ( V_82 , V_20 , V_87 , V_253 , & V_78 , 0 ) ;
V_79 = (struct V_224 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 ) {
F_47 ( V_5 , V_275 ) ;
if ( V_249 )
* V_249 = F_59 ( V_79 , F_28 ( V_79 ) + 4 ,
V_142 ) ;
goto V_276;
}
V_244 -> V_218 -> V_221 = V_79 -> V_220 ;
V_244 -> V_218 -> V_223 = V_79 -> V_222 ;
if ( V_209 ) {
memcpy ( V_209 , & V_79 -> V_277 , 32 ) ;
V_209 -> V_278 = V_79 -> V_278 ;
V_209 -> V_279 = V_79 -> V_280 ;
V_209 -> V_281 = V_79 -> V_262 ;
V_209 -> V_282 = F_5 ( 1 ) ;
V_209 -> V_283 = 0 ;
}
if ( V_79 -> V_284 == V_241 )
* V_235 = F_53 ( V_21 , V_79 , & V_244 -> V_218 -> V_225 ) ;
else
* V_235 = V_79 -> V_284 ;
V_276:
F_36 ( V_251 ) ;
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
int
F_60 ( const unsigned int V_82 , struct V_4 * V_5 , T_8 V_221 ,
T_8 V_223 , T_9 V_285 , bool V_286 , char * V_287 ,
T_9 V_288 , char * * V_289 , T_9 * V_290 )
{
struct V_291 * V_84 ;
struct V_292 * V_79 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_86 V_87 [ 2 ] ;
int V_78 ;
int V_253 ;
int V_34 = 0 ;
F_7 ( V_45 , L_32 ) ;
if ( V_290 )
* V_290 = 0 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_66 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_293 = F_5 ( V_285 ) ;
V_84 -> V_220 = V_221 ;
V_84 -> V_222 = V_223 ;
if ( V_288 ) {
V_84 -> V_294 = F_5 ( V_288 ) ;
V_84 -> V_295 =
F_5 ( F_41 ( struct V_291 , V_161 ) - 4 ) ;
V_87 [ 1 ] . V_109 = V_287 ;
V_87 [ 1 ] . V_110 = V_288 ;
V_253 = 2 ;
} else
V_253 = 1 ;
V_84 -> V_296 = 0 ;
V_84 -> V_297 = 0 ;
V_84 -> V_298 = F_5 ( 0xFF00 ) ;
if ( V_286 )
V_84 -> V_30 = F_5 ( V_299 ) ;
else
V_84 -> V_30 = 0 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
if ( V_288 )
F_27 ( V_84 , V_288 ) ;
V_34 = F_29 ( V_82 , V_20 , V_87 , V_253 , & V_78 , 0 ) ;
V_79 = (struct V_292 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 ) {
if ( V_5 )
F_47 ( V_5 , V_300 ) ;
goto V_301;
}
if ( ( V_290 == NULL ) || ( V_289 == NULL ) )
goto V_301;
* V_290 = F_30 ( V_79 -> V_297 ) ;
if ( * V_290 == 0 )
goto V_301;
else if ( * V_290 > 0xFF00 ) {
F_7 ( V_117 , L_33 , * V_290 ) ;
* V_290 = 0 ;
V_34 = - V_48 ;
goto V_301;
}
if ( F_28 ( V_79 ) < F_30 ( V_79 -> V_296 ) + * V_290 ) {
F_7 ( V_117 , L_34 , * V_290 ,
F_30 ( V_79 -> V_296 ) ) ;
* V_290 = 0 ;
V_34 = - V_48 ;
goto V_301;
}
* V_289 = F_37 ( * V_290 , V_142 ) ;
if ( * V_289 == NULL ) {
V_34 = - V_72 ;
goto V_301;
}
memcpy ( * V_289 , V_79 -> V_2 . V_12 + F_30 ( V_79 -> V_296 ) ,
* V_290 ) ;
V_301:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
int
F_61 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_8 V_221 , T_8 V_223 )
{
struct V_302 * V_84 ;
struct V_303 * V_79 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_86 V_87 [ 1 ] ;
int V_78 ;
int V_34 = 0 ;
F_7 ( V_45 , L_35 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_52 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_220 = V_221 ;
V_84 -> V_222 = V_223 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , 0 ) ;
V_79 = (struct V_303 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 ) {
if ( V_5 )
F_47 ( V_5 , V_304 ) ;
goto V_305;
}
V_305:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
static int
F_62 ( unsigned int V_306 , unsigned int V_307 ,
struct V_1 * V_2 , unsigned int V_308 )
{
unsigned int V_309 = F_63 ( V_2 -> V_11 ) ;
char * V_310 = V_309 + 4 + ( char * ) V_2 ;
char * V_311 = 4 + V_306 + ( char * ) V_2 ;
char * V_312 = V_311 + V_307 ;
if ( V_307 < V_308 ) {
F_7 ( V_117 , L_36 ,
V_307 , V_308 ) ;
return - V_186 ;
}
if ( ( V_309 > 0x7FFFFF ) || ( V_307 > 0x7FFFFF ) ) {
F_7 ( V_117 , L_37 ,
V_307 , V_309 ) ;
return - V_186 ;
}
if ( ( V_311 > V_310 ) || ( V_312 > V_310 ) ) {
F_7 ( V_117 , L_38 ) ;
return - V_186 ;
}
return 0 ;
}
static int
F_64 ( unsigned int V_306 , unsigned int V_307 ,
struct V_1 * V_2 , unsigned int V_313 ,
char * V_314 )
{
char * V_311 = 4 + V_306 + ( char * ) V_2 ;
int V_34 ;
if ( ! V_314 )
return - V_186 ;
V_34 = F_62 ( V_306 , V_307 , V_2 , V_313 ) ;
if ( V_34 )
return V_34 ;
memcpy ( V_314 , V_311 , V_307 ) ;
return 0 ;
}
static int
F_65 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_8 V_221 , T_8 V_223 , T_10 V_315 ,
T_11 V_316 , T_11 V_317 , void * V_314 )
{
struct V_318 * V_84 ;
struct V_319 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_34 = 0 ;
int V_78 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
F_7 ( V_45 , L_39 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_320 = V_321 ;
V_84 -> V_322 = V_315 ;
V_84 -> V_220 = V_221 ;
V_84 -> V_222 = V_223 ;
V_84 -> V_323 =
F_4 ( sizeof( struct V_318 ) - 1 - 4 ) ;
V_84 -> V_324 = F_5 ( V_316 ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , 0 ) ;
V_79 = (struct V_319 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 ) {
F_47 ( V_5 , V_325 ) ;
goto V_326;
}
V_34 = F_64 ( F_2 ( V_79 -> V_327 ) ,
F_30 ( V_79 -> V_324 ) ,
& V_79 -> V_2 , V_317 , V_314 ) ;
V_326:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
int
F_66 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_8 V_221 , T_8 V_223 ,
struct V_247 * V_314 )
{
return F_65 ( V_82 , V_5 , V_221 , V_223 ,
V_328 ,
sizeof( struct V_247 ) + V_329 * 2 ,
sizeof( struct V_247 ) , V_314 ) ;
}
int
F_67 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_8 V_221 , T_8 V_223 , T_12 * V_330 )
{
return F_65 ( V_82 , V_5 , V_221 , V_223 ,
V_331 ,
sizeof( struct V_332 ) ,
sizeof( struct V_332 ) , V_330 ) ;
}
static void
F_68 ( struct V_333 * V_334 )
{
struct V_38 * V_21 = V_334 -> V_335 ;
struct V_336 * V_337 = (struct V_336 * ) V_334 -> V_338 ;
unsigned int V_339 = 1 ;
if ( V_334 -> V_340 == V_341 )
V_339 = F_2 ( V_337 -> V_2 . V_15 ) ;
F_69 ( V_334 ) ;
F_70 ( V_21 , V_339 , V_342 ) ;
}
int
F_71 ( struct V_38 * V_21 )
{
struct V_343 * V_84 ;
int V_34 = 0 ;
struct V_86 V_87 ;
struct V_344 V_345 = { . V_346 = & V_87 ,
. V_347 = 1 } ;
F_7 ( V_45 , L_40 ) ;
V_34 = F_18 ( V_348 , NULL , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_15 = F_4 ( 1 ) ;
V_87 . V_109 = ( char * ) V_84 ;
V_87 . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_72 ( V_21 , & V_345 , NULL , F_68 , V_21 ,
V_342 ) ;
if ( V_34 )
F_7 ( V_45 , L_41 , V_34 ) ;
F_23 ( V_84 ) ;
return V_34 ;
}
int
F_73 ( const unsigned int V_82 , struct V_4 * V_5 , T_8 V_221 ,
T_8 V_223 )
{
struct V_349 * V_84 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_86 V_87 [ 1 ] ;
int V_78 ;
int V_34 = 0 ;
F_7 ( V_45 , L_42 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_63 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_220 = V_221 ;
V_84 -> V_222 = V_223 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , 0 ) ;
if ( ( V_34 != 0 ) && V_5 )
F_47 ( V_5 , V_350 ) ;
F_22 ( V_78 , V_87 [ 0 ] . V_109 ) ;
return V_34 ;
}
static int
F_74 ( struct V_86 * V_87 , struct V_351 * V_352 ,
unsigned int V_353 , int V_354 )
{
int V_34 = - V_355 ;
struct V_356 * V_84 = NULL ;
V_34 = F_18 ( V_64 , V_352 -> V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
if ( V_352 -> V_5 -> V_20 -> V_21 == NULL )
return - V_357 ;
V_84 -> V_2 . V_16 = F_5 ( V_352 -> V_358 ) ;
V_84 -> V_220 = V_352 -> V_221 ;
V_84 -> V_222 = V_352 -> V_223 ;
V_84 -> V_359 = 0 ;
V_84 -> V_360 = 0 ;
V_84 -> V_151 = 0 ;
V_84 -> V_361 = 0 ;
V_84 -> V_362 = F_5 ( V_352 -> V_363 ) ;
V_84 -> V_364 = F_75 ( V_352 -> V_306 ) ;
if ( V_354 & V_365 ) {
if ( ! ( V_354 & V_366 ) ) {
V_84 -> V_2 . V_367 =
F_5 ( F_28 ( V_84 ) + 4 ) ;
} else
V_84 -> V_2 . V_367 = 0 ;
if ( V_354 & V_368 ) {
V_84 -> V_2 . V_30 |= V_369 ;
V_84 -> V_2 . V_27 = 0xFFFFFFFF ;
V_84 -> V_2 . V_25 = 0xFFFFFFFF ;
V_84 -> V_220 = 0xFFFFFFFF ;
V_84 -> V_222 = 0xFFFFFFFF ;
}
}
if ( V_353 > V_352 -> V_363 )
V_84 -> V_370 = F_5 ( V_353 ) ;
else
V_84 -> V_370 = 0 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
return V_34 ;
}
static void
F_76 ( struct V_333 * V_334 )
{
struct V_371 * V_372 = V_334 -> V_335 ;
struct V_4 * V_5 = F_77 ( V_372 -> V_373 -> V_374 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_1 * V_209 = (struct V_1 * ) V_372 -> V_87 . V_109 ;
unsigned int V_339 = 1 ;
struct V_344 V_345 = { . V_346 = & V_372 -> V_87 ,
. V_347 = 1 ,
. V_375 = V_372 -> V_376 ,
. V_377 = V_372 -> V_378 ,
. V_379 = V_372 -> V_380 ,
. V_381 = V_372 -> V_382 } ;
F_7 ( V_45 , L_43 ,
V_93 , V_334 -> V_334 , V_334 -> V_340 , V_372 -> V_383 ,
V_372 -> V_384 ) ;
switch ( V_334 -> V_340 ) {
case V_341 :
V_339 = F_2 ( V_209 -> V_15 ) ;
if ( V_21 -> V_29 ) {
int V_34 ;
V_34 = F_78 ( & V_345 , V_21 ) ;
if ( V_34 )
F_7 ( V_117 , L_44 ,
V_34 ) ;
}
F_79 ( V_372 -> V_384 ) ;
F_80 ( V_5 , V_372 -> V_384 ) ;
break;
case V_385 :
case V_386 :
V_372 -> V_383 = - V_54 ;
break;
default:
if ( V_372 -> V_383 != - V_387 )
V_372 -> V_383 = - V_48 ;
}
if ( V_372 -> V_383 )
F_47 ( V_5 , V_388 ) ;
F_81 ( V_389 , & V_372 -> V_390 ) ;
F_69 ( V_334 ) ;
F_70 ( V_21 , V_339 , 0 ) ;
}
int
F_82 ( struct V_371 * V_372 )
{
int V_34 ;
struct V_1 * V_209 ;
struct V_351 V_352 ;
struct V_344 V_345 = { . V_346 = & V_372 -> V_87 ,
. V_347 = 1 } ;
F_7 ( V_45 , L_45 ,
V_93 , V_372 -> V_306 , V_372 -> V_384 ) ;
V_352 . V_5 = F_77 ( V_372 -> V_373 -> V_374 ) ;
V_352 . V_306 = V_372 -> V_306 ;
V_352 . V_363 = V_372 -> V_384 ;
V_352 . V_221 = V_372 -> V_373 -> V_218 . V_221 ;
V_352 . V_223 = V_372 -> V_373 -> V_218 . V_223 ;
V_352 . V_358 = V_372 -> V_358 ;
V_34 = F_74 ( & V_372 -> V_87 , & V_352 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_209 = (struct V_1 * ) V_372 -> V_87 . V_109 ;
V_372 -> V_87 . V_110 = F_28 ( V_372 -> V_87 . V_109 ) + 4 ;
F_83 ( & V_372 -> V_391 ) ;
V_34 = F_72 ( V_352 . V_5 -> V_20 -> V_21 , & V_345 ,
V_392 , F_76 ,
V_372 , 0 ) ;
if ( V_34 ) {
F_84 ( & V_372 -> V_391 , V_393 ) ;
F_47 ( V_352 . V_5 , V_388 ) ;
}
F_23 ( V_209 ) ;
return V_34 ;
}
int
F_85 ( const unsigned int V_82 , struct V_351 * V_352 ,
unsigned int * V_394 , char * * V_209 , int * V_395 )
{
int V_78 , V_34 = - V_355 ;
struct V_396 * V_79 = NULL ;
struct V_86 V_87 [ 1 ] ;
* V_394 = 0 ;
V_34 = F_74 ( V_87 , V_352 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_29 ( V_82 , V_352 -> V_5 -> V_20 , V_87 , 1 ,
& V_78 , V_157 ) ;
V_79 = (struct V_396 * ) V_87 [ 0 ] . V_109 ;
if ( V_79 -> V_2 . V_159 == V_397 ) {
F_22 ( V_78 , V_87 [ 0 ] . V_109 ) ;
return 0 ;
}
if ( V_34 ) {
F_47 ( V_352 -> V_5 , V_388 ) ;
F_7 ( V_117 , L_46 , V_34 ) ;
} else {
* V_394 = F_30 ( V_79 -> V_213 ) ;
if ( ( * V_394 > V_398 ) ||
( * V_394 > V_352 -> V_363 ) ) {
F_7 ( V_45 , L_47 ,
* V_394 , V_352 -> V_363 ) ;
V_34 = - V_48 ;
* V_394 = 0 ;
}
}
if ( * V_209 ) {
memcpy ( * V_209 , ( char * ) V_79 -> V_2 . V_12 + V_79 -> V_211 ,
* V_394 ) ;
F_22 ( V_78 , V_87 [ 0 ] . V_109 ) ;
} else if ( V_78 != V_158 ) {
* V_209 = V_87 [ 0 ] . V_109 ;
if ( V_78 == V_80 )
* V_395 = V_80 ;
else if ( V_78 == V_81 )
* V_395 = V_81 ;
}
return V_34 ;
}
static void
F_86 ( struct V_333 * V_334 )
{
struct V_399 * V_400 = V_334 -> V_335 ;
struct V_4 * V_5 = F_77 ( V_400 -> V_373 -> V_374 ) ;
unsigned int V_401 ;
struct V_402 * V_79 = (struct V_402 * ) V_334 -> V_338 ;
unsigned int V_339 = 1 ;
switch ( V_334 -> V_340 ) {
case V_341 :
V_339 = F_2 ( V_79 -> V_2 . V_15 ) ;
V_400 -> V_383 = F_87 ( V_334 , V_5 -> V_20 -> V_21 , 0 ) ;
if ( V_400 -> V_383 != 0 )
break;
V_401 = F_30 ( V_79 -> V_213 ) ;
if ( V_401 > V_400 -> V_384 )
V_401 &= 0xFFFF ;
if ( V_401 < V_400 -> V_384 )
V_400 -> V_383 = - V_403 ;
else
V_400 -> V_384 = V_401 ;
break;
case V_385 :
case V_386 :
V_400 -> V_383 = - V_54 ;
break;
default:
V_400 -> V_383 = - V_48 ;
break;
}
if ( V_400 -> V_383 )
F_47 ( V_5 , V_404 ) ;
F_81 ( V_389 , & V_400 -> V_390 ) ;
F_69 ( V_334 ) ;
F_70 ( V_5 -> V_20 -> V_21 , V_339 , 0 ) ;
}
int
F_88 ( struct V_399 * V_400 )
{
int V_34 = - V_355 ;
struct V_405 * V_84 = NULL ;
struct V_4 * V_5 = F_77 ( V_400 -> V_373 -> V_374 ) ;
struct V_86 V_87 ;
struct V_344 V_345 ;
V_34 = F_18 ( V_42 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
goto V_406;
V_84 -> V_2 . V_16 = F_5 ( V_400 -> V_373 -> V_358 ) ;
V_84 -> V_220 = V_400 -> V_373 -> V_218 . V_221 ;
V_84 -> V_222 = V_400 -> V_373 -> V_218 . V_223 ;
V_84 -> V_407 = 0 ;
V_84 -> V_408 = 0 ;
V_84 -> V_151 = 0 ;
V_84 -> V_364 = F_75 ( V_400 -> V_306 ) ;
V_84 -> V_211 = F_4 (
F_41 ( struct V_405 , V_161 ) - 4 ) ;
V_84 -> V_370 = 0 ;
V_87 . V_110 = F_28 ( V_84 ) + 4 - 1 ;
V_87 . V_109 = V_84 ;
V_345 . V_346 = & V_87 ;
V_345 . V_347 = 1 ;
V_345 . V_375 = V_400 -> V_376 ;
V_345 . V_377 = V_400 -> V_378 ;
V_345 . V_379 = V_400 -> V_380 ;
V_345 . V_381 = V_400 -> V_382 ;
F_7 ( V_45 , L_48 ,
V_400 -> V_306 , V_400 -> V_384 ) ;
V_84 -> V_362 = F_5 ( V_400 -> V_384 ) ;
F_27 ( & V_84 -> V_2 , V_400 -> V_384 - 1 ) ;
F_83 ( & V_400 -> V_391 ) ;
V_34 = F_72 ( V_5 -> V_20 -> V_21 , & V_345 , NULL ,
F_86 , V_400 , 0 ) ;
if ( V_34 ) {
F_84 ( & V_400 -> V_391 , V_409 ) ;
F_47 ( V_5 , V_404 ) ;
}
V_406:
F_23 ( V_84 ) ;
return V_34 ;
}
int
F_89 ( const unsigned int V_82 , struct V_351 * V_352 ,
unsigned int * V_394 , struct V_86 * V_87 , int V_410 )
{
int V_34 = 0 ;
struct V_405 * V_84 = NULL ;
struct V_402 * V_79 = NULL ;
int V_78 ;
* V_394 = 0 ;
if ( V_410 < 1 )
return V_34 ;
V_34 = F_18 ( V_42 , V_352 -> V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
if ( V_352 -> V_5 -> V_20 -> V_21 == NULL )
return - V_357 ;
V_84 -> V_2 . V_16 = F_5 ( V_352 -> V_358 ) ;
V_84 -> V_220 = V_352 -> V_221 ;
V_84 -> V_222 = V_352 -> V_223 ;
V_84 -> V_407 = 0 ;
V_84 -> V_408 = 0 ;
V_84 -> V_151 = 0 ;
V_84 -> V_362 = F_5 ( V_352 -> V_363 ) ;
V_84 -> V_364 = F_75 ( V_352 -> V_306 ) ;
V_84 -> V_211 = F_4 (
F_41 ( struct V_405 , V_161 ) - 4 ) ;
V_84 -> V_370 = 0 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
F_27 ( V_84 , V_352 -> V_363 - 1 ) ;
V_34 = F_29 ( V_82 , V_352 -> V_5 -> V_20 , V_87 , V_410 + 1 ,
& V_78 , 0 ) ;
V_79 = (struct V_402 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 ) {
F_47 ( V_352 -> V_5 , V_404 ) ;
F_7 ( V_117 , L_49 , V_34 ) ;
} else
* V_394 = F_30 ( V_79 -> V_213 ) ;
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
static unsigned int
F_90 ( char * V_411 , char * V_312 , char * * V_412 , T_11 V_413 )
{
int V_414 ;
unsigned int V_415 = 0 ;
unsigned int V_416 = 0 ;
T_13 * V_417 ;
if ( V_411 == NULL )
return 0 ;
V_417 = ( T_13 * ) V_411 ;
while ( 1 ) {
V_417 = ( T_13 * )
( ( char * ) V_417 + V_416 ) ;
if ( ( char * ) V_417 + V_413 > V_312 ) {
F_7 ( V_117 , L_50 ) ;
break;
}
V_414 = F_30 ( V_417 -> V_418 ) ;
if ( ( char * ) V_417 + V_414 + V_413 > V_312 ) {
F_7 ( V_117 , L_51 ,
V_312 ) ;
break;
}
* V_412 = ( char * ) V_417 ;
V_415 ++ ;
V_416 = F_30 ( V_417 -> V_419 ) ;
if ( ! V_416 )
break;
}
return V_415 ;
}
int
F_91 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_8 V_221 , T_8 V_223 , int V_420 ,
struct V_421 * V_422 )
{
struct V_423 * V_84 ;
struct V_424 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_34 = 0 ;
int V_414 ;
int V_78 ;
unsigned char * V_425 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
T_1 V_426 = F_4 ( '*' ) ;
char * V_310 ;
unsigned int V_427 = V_428 ;
T_11 V_429 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_67 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
switch ( V_422 -> V_430 ) {
case V_431 :
V_84 -> V_432 = V_433 ;
V_429 = sizeof( T_13 ) - 1 ;
break;
case V_434 :
V_84 -> V_432 = V_435 ;
V_429 = sizeof( V_436 ) - 1 ;
break;
default:
F_7 ( V_117 , L_52 ,
V_422 -> V_430 ) ;
V_34 = - V_186 ;
goto V_437;
}
V_84 -> V_438 = F_5 ( V_420 ) ;
V_84 -> V_220 = V_221 ;
V_84 -> V_222 = V_223 ;
V_414 = 0x2 ;
V_425 = V_84 -> V_161 ;
memcpy ( V_425 , & V_426 , V_414 ) ;
V_84 -> V_439 =
F_4 ( sizeof( struct V_423 ) - 1 - 4 ) ;
V_84 -> V_418 = F_4 ( V_414 ) ;
V_427 = F_92 (unsigned int, output_size, server->maxBuf) ;
V_427 = F_92 (unsigned int, output_size, 2 << 15 ) ;
V_84 -> V_324 = F_5 ( V_427 ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
V_87 [ 1 ] . V_109 = ( char * ) ( V_84 -> V_161 ) ;
V_87 [ 1 ] . V_110 = V_414 ;
F_27 ( V_84 , V_414 - 1 ) ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 2 , & V_78 , 0 ) ;
V_79 = (struct V_424 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 ) {
F_47 ( V_5 , V_440 ) ;
goto V_437;
}
V_34 = F_62 ( F_2 ( V_79 -> V_327 ) ,
F_30 ( V_79 -> V_324 ) , & V_79 -> V_2 ,
V_429 ) ;
if ( V_34 )
goto V_437;
V_422 -> V_441 = true ;
if ( V_422 -> V_442 ) {
if ( V_422 -> V_443 )
F_23 ( V_422 -> V_442 ) ;
else
F_24 ( V_422 -> V_442 ) ;
}
V_422 -> V_442 = ( char * ) V_79 ;
V_422 -> V_444 = V_422 -> V_445 = 4 +
( char * ) & V_79 -> V_2 + F_2 ( V_79 -> V_327 ) ;
V_310 = F_28 ( V_79 ) + 4 + ( char * ) & V_79 -> V_2 ;
V_422 -> V_446 =
F_90 ( V_422 -> V_444 , V_310 ,
& V_422 -> V_445 , V_429 ) ;
V_422 -> V_447 += V_422 -> V_446 ;
F_7 ( V_45 , L_53 ,
V_422 -> V_446 , V_422 -> V_447 ,
V_422 -> V_444 , V_422 -> V_445 ) ;
if ( V_78 == V_81 )
V_422 -> V_443 = false ;
else if ( V_78 == V_80 )
V_422 -> V_443 = true ;
else
F_7 ( V_117 , L_54 ) ;
if ( V_79 -> V_2 . V_159 == V_448 )
V_422 -> V_449 = 1 ;
else
V_422 -> V_449 = 0 ;
return V_34 ;
V_437:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
static int
F_93 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_8 V_221 , T_8 V_223 , T_9 V_358 , int V_315 ,
unsigned int V_237 , void * * V_314 , unsigned int * V_413 )
{
struct V_450 * V_84 ;
struct V_451 * V_79 = NULL ;
struct V_86 * V_87 ;
int V_34 = 0 ;
int V_78 ;
unsigned int V_452 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( ! V_237 )
return - V_186 ;
V_87 = F_37 ( sizeof( struct V_86 ) * V_237 , V_142 ) ;
if ( ! V_87 )
return - V_72 ;
V_34 = F_18 ( V_70 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 ) {
F_36 ( V_87 ) ;
return V_34 ;
}
V_84 -> V_2 . V_16 = F_5 ( V_358 ) ;
V_84 -> V_320 = V_321 ;
V_84 -> V_322 = V_315 ;
V_84 -> V_220 = V_221 ;
V_84 -> V_222 = V_223 ;
V_84 -> V_453 =
F_4 ( sizeof( struct V_450 ) - 1 - 4 ) ;
V_84 -> V_454 = F_5 ( * V_413 ) ;
F_27 ( V_84 , * V_413 - 1 ) ;
memcpy ( V_84 -> V_161 , * V_314 , * V_413 ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
for ( V_452 = 1 ; V_452 < V_237 ; V_452 ++ ) {
F_27 ( V_84 , V_413 [ V_452 ] ) ;
F_55 ( & V_84 -> V_454 , V_413 [ V_452 ] ) ;
V_87 [ V_452 ] . V_109 = ( char * ) V_314 [ V_452 ] ;
V_87 [ V_452 ] . V_110 = V_413 [ V_452 ] ;
}
V_34 = F_29 ( V_82 , V_20 , V_87 , V_237 , & V_78 , 0 ) ;
V_79 = (struct V_451 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 ) {
F_47 ( V_5 , V_455 ) ;
goto V_19;
}
V_19:
F_22 ( V_78 , V_79 ) ;
F_36 ( V_87 ) ;
return V_34 ;
}
int
F_94 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_8 V_221 , T_8 V_223 , T_1 * V_456 )
{
struct V_457 V_458 ;
void * * V_314 ;
unsigned int V_413 [ 2 ] ;
int V_34 ;
int V_414 = ( 2 * F_58 ( ( V_269 * ) V_456 , V_270 ) ) ;
V_314 = F_37 ( sizeof( void * ) * 2 , V_142 ) ;
if ( ! V_314 )
return - V_72 ;
V_458 . V_459 = 1 ;
V_458 . V_460 = 0 ;
V_458 . V_418 = F_5 ( V_414 ) ;
V_314 [ 0 ] = & V_458 ;
V_413 [ 0 ] = sizeof( struct V_457 ) ;
V_314 [ 1 ] = V_456 ;
V_413 [ 1 ] = V_414 + 2 ;
V_34 = F_93 ( V_82 , V_5 , V_221 , V_223 ,
V_17 -> V_18 , V_461 , 2 , V_314 ,
V_413 ) ;
F_36 ( V_314 ) ;
return V_34 ;
}
int
F_95 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_8 V_221 , T_8 V_223 , T_1 * V_456 )
{
struct V_462 V_458 ;
void * * V_314 ;
unsigned int V_413 [ 2 ] ;
int V_34 ;
int V_414 = ( 2 * F_58 ( ( V_269 * ) V_456 , V_270 ) ) ;
V_314 = F_37 ( sizeof( void * ) * 2 , V_142 ) ;
if ( ! V_314 )
return - V_72 ;
V_458 . V_459 = 0 ;
V_458 . V_460 = 0 ;
V_458 . V_418 = F_5 ( V_414 ) ;
V_314 [ 0 ] = & V_458 ;
V_413 [ 0 ] = sizeof( struct V_462 ) ;
V_314 [ 1 ] = V_456 ;
V_413 [ 1 ] = V_414 + 2 ;
V_34 = F_93 ( V_82 , V_5 , V_221 , V_223 ,
V_17 -> V_18 , V_463 , 2 , V_314 , V_413 ) ;
F_36 ( V_314 ) ;
return V_34 ;
}
int
F_96 ( const unsigned int V_82 , struct V_4 * V_5 , T_8 V_221 ,
T_8 V_223 , T_9 V_358 , T_12 * V_464 )
{
struct V_465 V_458 ;
void * V_314 ;
unsigned int V_413 ;
V_458 . V_279 = * V_464 ;
V_314 = & V_458 ;
V_413 = sizeof( struct V_465 ) ;
return F_93 ( V_82 , V_5 , V_221 , V_223 , V_358 ,
V_466 , 1 , & V_314 , & V_413 ) ;
}
int
F_97 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_8 V_221 , T_8 V_223 , T_14 * V_209 )
{
unsigned int V_413 ;
V_413 = sizeof( T_14 ) ;
return F_93 ( V_82 , V_5 , V_221 , V_223 ,
V_17 -> V_18 , V_467 , 1 ,
( void * * ) & V_209 , & V_413 ) ;
}
int
F_98 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_8 V_221 , const T_8 V_223 ,
T_6 V_468 )
{
int V_34 ;
struct V_469 * V_84 = NULL ;
F_7 ( V_45 , L_55 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_470 = V_223 ;
V_84 -> V_471 = V_221 ;
V_84 -> V_284 = V_468 ;
V_84 -> V_2 . V_15 = F_4 ( 1 ) ;
V_34 = F_46 ( V_82 , V_5 -> V_20 , ( char * ) V_84 , V_472 ) ;
if ( V_34 ) {
F_47 ( V_5 , V_473 ) ;
F_7 ( V_45 , L_56 , V_34 ) ;
}
return V_34 ;
}
static void
F_99 ( struct V_474 * V_475 ,
struct V_476 * V_477 )
{
V_477 -> V_478 = F_30 ( V_475 -> V_479 ) *
F_30 ( V_475 -> V_480 ) ;
V_477 -> V_481 = F_100 ( V_475 -> V_482 ) ;
V_477 -> V_483 = F_100 ( V_475 -> V_484 ) ;
V_477 -> V_485 = F_100 ( V_475 -> V_486 ) ;
return;
}
static int
F_101 ( struct V_86 * V_87 , struct V_4 * V_5 , int V_487 ,
int V_488 , T_8 V_221 , T_8 V_223 )
{
int V_34 ;
struct V_318 * V_84 ;
F_7 ( V_45 , L_57 , V_487 ) ;
if ( ( V_5 -> V_20 == NULL ) || ( V_5 -> V_20 -> V_21 == NULL ) )
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_320 = V_489 ;
V_84 -> V_322 = V_487 ;
V_84 -> V_220 = V_221 ;
V_84 -> V_222 = V_223 ;
V_84 -> V_323 =
F_4 ( sizeof( struct V_318 ) - 1 - 4 ) ;
V_84 -> V_324 = F_5 (
V_488 + sizeof( struct V_319 ) - 1 - 4 ) ;
V_87 -> V_109 = ( char * ) V_84 ;
V_87 -> V_110 = F_28 ( V_84 ) + 4 ;
return 0 ;
}
int
F_102 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_8 V_221 , T_8 V_223 , struct V_476 * V_490 )
{
struct V_319 * V_79 = NULL ;
struct V_86 V_87 ;
int V_34 = 0 ;
int V_78 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_474 * V_458 = NULL ;
V_34 = F_101 ( & V_87 , V_5 , V_491 ,
sizeof( struct V_474 ) ,
V_221 , V_223 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_29 ( V_82 , V_20 , & V_87 , 1 , & V_78 , 0 ) ;
if ( V_34 ) {
F_47 ( V_5 , V_325 ) ;
goto V_326;
}
V_79 = (struct V_319 * ) V_87 . V_109 ;
V_458 = (struct V_474 * ) ( 4 +
F_2 ( V_79 -> V_327 ) + ( char * ) & V_79 -> V_2 ) ;
V_34 = F_62 ( F_2 ( V_79 -> V_327 ) ,
F_30 ( V_79 -> V_324 ) , & V_79 -> V_2 ,
sizeof( struct V_474 ) ) ;
if ( ! V_34 )
F_99 ( V_458 , V_490 ) ;
V_326:
F_22 ( V_78 , V_87 . V_109 ) ;
return V_34 ;
}
int
F_103 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_15 V_492 , const T_15 V_223 , const T_7 V_358 ,
const T_7 V_493 , struct V_494 * V_209 )
{
int V_34 = 0 ;
struct V_495 * V_84 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_496 ;
unsigned int V_497 ;
F_7 ( V_45 , L_58 , V_493 ) ;
V_34 = F_18 ( V_65 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_16 = F_5 ( V_358 ) ;
V_84 -> V_498 = F_4 ( V_493 ) ;
V_84 -> V_220 = V_492 ;
V_84 -> V_222 = V_223 ;
V_497 = V_493 * sizeof( struct V_494 ) ;
F_27 ( V_84 , V_497 - sizeof( struct V_494 ) ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - V_497 ;
V_87 [ 1 ] . V_109 = ( char * ) V_209 ;
V_87 [ 1 ] . V_110 = V_497 ;
F_21 ( & V_5 -> V_74 . V_499 . V_500 ) ;
V_34 = F_29 ( V_82 , V_5 -> V_20 , V_87 , 2 , & V_496 , V_501 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_59 , V_34 ) ;
F_47 ( V_5 , V_502 ) ;
}
return V_34 ;
}
int
F_104 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_15 V_492 , const T_15 V_223 , const T_7 V_358 ,
const T_15 V_363 , const T_15 V_306 , const T_7 V_503 ,
const bool V_504 )
{
struct V_494 V_505 ;
V_505 . V_364 = F_75 ( V_306 ) ;
V_505 . V_362 = F_75 ( V_363 ) ;
V_505 . V_30 = F_5 ( V_503 ) ;
if ( ! V_504 && V_503 != V_506 )
V_505 . V_30 |= F_5 ( V_507 ) ;
return F_103 ( V_82 , V_5 , V_492 , V_223 , V_358 , 1 , & V_505 ) ;
}
int
F_105 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_6 * V_508 , const T_4 V_509 )
{
int V_34 ;
struct V_510 * V_84 = NULL ;
F_7 ( V_45 , L_60 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_15 = F_4 ( 1 ) ;
V_84 -> V_13 = F_4 ( 36 ) ;
F_27 ( V_84 , 12 ) ;
memcpy ( V_84 -> V_511 , V_508 , 16 ) ;
V_84 -> V_512 = V_509 ;
V_34 = F_46 ( V_82 , V_5 -> V_20 , ( char * ) V_84 , V_472 ) ;
if ( V_34 ) {
F_47 ( V_5 , V_473 ) ;
F_7 ( V_45 , L_61 , V_34 ) ;
}
return V_34 ;
}
