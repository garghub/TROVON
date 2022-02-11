void F_1 ( void )
{
V_1 = V_2 ;
}
static int F_2 ( struct V_3 * V_4 , char * V_5 , int V_6 )
{
struct V_7 V_8 ;
struct V_7 * V_9 = & V_8 ;
F_3 ( V_9 , V_5 , V_6 ) ;
F_4 ( V_9 , L_1 , V_10 ) ;
F_4 ( V_9 , L_2 ) ;
F_4 ( V_9 , L_3 ,
V_4 -> V_11 , V_4 -> V_12 , V_4 -> V_13 ) ;
F_4 ( V_9 , L_4 ,
V_4 -> V_14 , V_4 -> V_15 , V_4 -> V_16 ) ;
F_4 ( V_9 , L_5 ,
V_4 -> V_17 , V_4 -> V_18 , & V_4 -> V_19 ) ;
F_4 ( V_9 , L_6 , V_4 -> V_20 ,
V_4 -> V_21 ) ;
F_4 ( V_9 , L_7 ) ;
F_4 ( V_9 ,
L_8 ,
V_4 -> V_22 . V_23 , V_4 -> V_22 . V_24 ,
V_4 -> V_22 . V_25 , V_4 -> V_22 . V_26 ) ;
F_4 ( V_9 ,
L_9 ,
V_4 -> V_22 . V_27 , V_4 -> V_22 . V_28 ,
V_4 -> V_22 . V_29 , V_4 -> V_22 . V_30 ) ;
F_4 ( V_9 , L_10 , V_4 -> V_22 . V_31 ) ;
F_4 ( V_9 , L_11 ) ;
F_4 ( V_9 , L_12 ,
V_4 -> V_23 , V_4 -> V_32 , V_4 -> V_25 ) ;
F_4 ( V_9 , L_13 ,
V_4 -> V_33 , V_4 -> V_34 ) ;
F_4 ( V_9 , L_14 ,
V_4 -> V_27 , V_4 -> V_35 , V_4 -> V_29 ) ;
F_4 ( V_9 ,
L_15 ,
V_4 -> V_36 , V_4 -> V_37 , V_4 -> V_30 ,
V_4 -> V_38 ) ;
F_4 ( V_9 ,
L_16 ,
V_4 -> V_39 , V_4 -> V_40 , V_4 -> V_41 ) ;
F_4 ( V_9 , L_17 , V_4 -> V_42 ) ;
F_4 ( V_9 , L_2 ) ;
F_5 ( V_4 , V_9 ) ;
F_4 ( V_9 , L_2 ) ;
F_6 ( V_4 , V_9 ) ;
return ! V_9 -> V_43 ? - V_44 : 0 ;
}
static int
F_7 ( struct V_3 * V_4 , const struct V_45 * V_46 ,
T_1 V_47 , const char * V_48 , void * V_49 , int V_50 ,
void * V_51 , int V_52 , int V_53 )
{
int V_20 = 0 ;
T_2 V_54 = 0 ;
F_8 ( ( L_18 , V_55 ) ) ;
V_20 = F_9 ( V_46 , V_51 , V_52 , F_10 ( V_47 ) ) ;
if ( V_20 != 0 )
goto exit;
if ( V_50 >= ( int ) sizeof( V_54 ) )
memcpy ( & V_54 , V_49 , sizeof( V_54 ) ) ;
switch ( V_47 ) {
case F_11 ( V_56 ) :
strncpy ( ( char * ) V_51 , V_10 , V_52 ) ;
break;
case F_11 ( V_57 ) :
V_54 = ( T_2 ) V_1 ;
memcpy ( V_51 , & V_54 , V_53 ) ;
break;
case F_12 ( V_57 ) :
V_1 = V_54 ;
break;
case F_11 ( V_58 ) :
strncpy ( ( char * ) V_51 , L_19 ,
V_59 ) ;
( ( char * ) V_51 ) [ V_59 - 1 ] = 0x00 ;
break;
case F_11 ( V_60 ) :
V_54 = ( T_2 ) V_4 -> V_20 ;
memcpy ( V_51 , & V_54 , V_53 ) ;
break;
case F_11 ( V_61 ) :
V_20 = F_2 ( V_4 , V_51 , V_52 ) ;
break;
case F_12 ( V_62 ) :
V_4 -> V_23 = V_4 -> V_27 = 0 ;
V_4 -> V_25 = V_4 -> V_29 = 0 ;
V_4 -> V_33 = V_4 -> V_36 = 0 ;
V_4 -> V_34 = V_4 -> V_37 = 0 ;
V_4 -> V_30 = 0 ;
V_4 -> V_39 = 0 ;
V_4 -> V_40 = 0 ;
V_4 -> V_42 = 0 ;
memset ( & V_4 -> V_22 , 0 , sizeof( V_4 -> V_22 ) ) ;
F_13 ( V_4 ) ;
break;
case F_11 ( V_63 ) : {
V_54 = ( T_2 ) F_14 () ;
memcpy ( V_51 , & V_54 , sizeof( V_54 ) ) ;
break;
}
case F_12 ( V_63 ) : {
if ( V_54 <= 0 )
V_20 = - V_64 ;
else
F_15 ( ( unsigned int )
V_54 ) ;
break;
}
default:
V_20 = - V_65 ;
break;
}
exit:
return V_20 ;
}
bool F_16 ( struct V_3 * V_4 , struct V_66 * V_67 ,
struct V_68 * V_69 , int V_70 )
{
struct V_68 * V_71 ;
int V_72 = - 1 ;
bool V_73 ;
if ( ! F_17 ( V_67 , V_70 ) && ! F_18 ( V_67 ) ) {
F_19 ( V_67 , V_70 , V_69 ) ;
return true ;
}
if ( F_17 ( V_67 , V_70 ) )
V_72 = V_70 ;
else if ( F_18 ( V_67 ) ) {
V_71 = F_20 ( V_67 , & V_72 ) ;
if ( V_72 > V_70 )
return false ;
}
if ( V_72 >= 0 ) {
V_73 = F_21 ( V_4 -> V_74 , V_72 ) ;
if ( V_72 == V_70 && ! V_73 )
return false ;
V_71 = V_73 ? F_22 ( V_67 , V_72 ) :
F_23 ( V_67 , V_72 ) ;
if ( V_71 == NULL ) {
F_24 ( ( L_20 ,
V_55 , V_73 ) ) ;
}
F_25 ( V_71 ) ;
}
V_71 = F_19 ( V_67 , V_70 , V_69 ) ;
if ( V_71 == NULL ) {
F_24 ( ( L_21 , V_55 ) ) ;
}
return V_71 != NULL ;
}
static int
F_26 ( struct V_3 * V_4 , const char * V_48 ,
void * V_49 , int V_50 , void * V_51 , int V_52 , bool V_75 )
{
int V_20 = 0 ;
int V_53 ;
const struct V_45 * V_46 = NULL ;
T_1 V_47 ;
F_8 ( ( L_18 , V_55 ) ) ;
if ( V_48 == NULL || V_52 <= 0 )
return - V_64 ;
if ( V_75 && ( V_49 || V_50 ) )
return - V_64 ;
if ( ! V_75 && ! ( V_51 && V_52 ) )
return - V_64 ;
V_46 = F_27 ( V_76 , V_48 ) ;
if ( V_46 == NULL ) {
V_20 = - V_65 ;
goto exit;
}
F_28 ( ( L_22 , V_55 ,
V_48 , ( V_75 ? L_23 : L_24 ) , V_52 , V_50 ) ) ;
if ( V_49 == NULL ) {
V_49 = V_51 ;
V_50 = V_52 ;
}
if ( V_46 -> type == V_77 )
V_53 = 0 ;
else if ( V_46 -> type == V_78 )
V_53 = V_52 ;
else
V_53 = sizeof( int ) ;
V_47 = V_75 ? F_12 ( V_46 -> V_79 ) : F_11 ( V_46 -> V_79 ) ;
V_20 =
F_7 ( V_4 , V_46 , V_47 , V_48 , V_49 , V_50 , V_51 , V_52 ,
V_53 ) ;
exit:
return V_20 ;
}
int F_29 ( struct V_3 * V_4 , struct F_29 * V_80 , void * V_5 ,
T_3 V_6 )
{
int V_20 = 0 ;
F_8 ( ( L_18 , V_55 ) ) ;
if ( ! V_5 )
return - V_64 ;
switch ( V_80 -> V_81 ) {
case V_82 :
if ( V_6 < sizeof( int ) )
V_20 = - V_44 ;
else
* ( int * ) V_5 = V_83 ;
break;
case V_84 :
if ( V_6 < sizeof( int ) )
V_20 = - V_44 ;
else
* ( int * ) V_5 = V_85 ;
break;
case V_86 :
case V_87 : {
char * V_51 ;
T_3 V_88 ;
for ( V_51 = V_5 , V_88 = V_6 ; * V_51 && V_88 ;
V_51 ++ , V_88 -- )
;
if ( * V_51 ) {
V_20 = - V_44 ;
break;
}
V_51 ++ , V_88 -- ;
if ( V_80 -> V_81 == V_86 )
V_20 = F_26 ( V_4 , V_5 , V_51 ,
V_88 , V_5 , V_6 , V_89 ) ;
else
V_20 =
F_26 ( V_4 , V_5 , NULL , 0 , V_51 ,
V_88 , V_90 ) ;
if ( V_20 != - V_65 )
break;
if ( V_80 -> V_81 == V_86 )
V_20 = F_30 ( V_4 ,
V_5 , V_51 , V_88 , V_5 , V_6 ,
V_89 ) ;
else
V_20 = F_30 ( V_4 ,
V_5 , NULL , 0 , V_51 , V_88 ,
V_90 ) ;
break;
}
default:
V_20 = - V_65 ;
}
return V_20 ;
}
static void
F_31 ( struct V_91 * V_92 , void * V_93 )
{
T_3 V_94 , V_95 , V_96 ;
bool V_97 = false , V_98 = false , V_99 = false ;
char * V_100 , * V_101 ;
unsigned char * V_5 ;
char V_102 [ 256 ] , V_103 [ V_104 ] ;
static struct {
T_3 V_92 ;
char * V_101 ;
} V_105 [] = {
{
V_106 , L_25 } , {
V_107 , L_26 } , {
V_108 , L_27 } , {
V_109 , L_28 } , {
V_110 , L_29 } , {
V_111 , L_30 } , {
V_112 , L_31 } , {
V_113 , L_32 } , {
V_114 , L_33 } , {
V_115 , L_34 } , {
V_116 , L_35 } , {
V_117 , L_36 } , {
V_118 , L_37 } , {
V_119 , L_38 } , {
V_120 , L_39 } , {
V_121 , L_40 } , {
V_122 , L_41 } , {
V_123 , L_42 } , {
V_124 , L_43 } , {
V_125 , L_44 } , {
V_126 , L_45 } , {
V_127 , L_46 } , {
V_128 , L_47 } , {
V_129 , L_48 } , {
V_130 , L_49 } , {
V_131 , L_50 } , {
V_132 , L_51 } , {
V_133 , L_52 } , {
V_134 , L_53 } , {
V_135 , L_54 } , {
V_136 , L_55 } , {
V_137 , L_56 } , {
V_138 , L_57 } , {
V_139 , L_58 } , {
V_140 , L_59 } , {
V_141 , L_60 } , {
V_142 , L_61 } , {
V_143 , L_62 } , {
V_144 , L_63 } , {
V_145 , L_64 } , {
V_146 , L_65 } , {
V_147 , L_66 } , {
V_148 , L_67 } , {
V_149 , L_68 } , {
V_150 , L_69 } , {
V_151 , L_70 } , {
V_152 , L_71 } , {
V_153 , L_72 } , {
V_154 , L_73 } , {
V_155 , L_74 } , {
V_156 , L_75 } , {
V_157 , L_76 } , {
V_158 , L_77 } , {
V_159 , L_78 } , {
V_160 , L_79 } , {
V_161 , L_51 }
} ;
T_3 V_162 , V_163 , V_164 , V_165 ;
V_162 = F_32 ( V_92 -> V_162 ) ;
V_163 = F_33 ( V_92 -> V_163 ) ;
V_95 = F_32 ( V_92 -> V_95 ) ;
V_96 = F_32 ( V_92 -> V_96 ) ;
V_164 = F_32 ( V_92 -> V_164 ) ;
V_165 = F_32 ( V_92 -> V_165 ) ;
sprintf ( V_103 , L_80 , V_92 -> V_166 ) ;
V_101 = L_81 ;
for ( V_94 = 0 ; V_94 < F_34 ( V_105 ) ; V_94 ++ ) {
if ( V_105 [ V_94 ] . V_92 == V_162 )
V_101 = V_105 [ V_94 ] . V_101 ;
}
F_35 ( ( L_82 , V_101 , V_162 ) ) ;
F_35 ( ( L_83
L_84 , V_163 , V_95 , V_96 , V_164 , V_103 ) ) ;
if ( V_163 & V_167 )
V_99 = true ;
if ( V_163 & V_168 )
V_97 = true ;
if ( V_163 & V_169 )
V_98 = true ;
switch ( V_162 ) {
case V_108 :
case V_111 :
case V_117 :
F_35 ( ( L_85 , V_101 , V_103 ) ) ;
break;
case V_114 :
case V_116 :
F_35 ( ( L_85 , V_101 , V_103 ) ) ;
break;
case V_113 :
case V_115 :
if ( V_95 == V_170 ) {
F_35 ( ( L_86 ,
V_101 , V_103 ) ) ;
} else if ( V_95 == V_171 ) {
F_35 ( ( L_87 ,
V_101 , V_103 ) ) ;
} else if ( V_95 == V_172 ) {
F_35 ( ( L_88
L_89 , V_101 , V_103 ,
( int ) V_96 ) ) ;
} else {
F_35 ( ( L_90
L_91 , V_101 , V_103 , ( int ) V_95 ) ) ;
}
break;
case V_112 :
case V_118 :
F_35 ( ( L_92 , V_101 ,
V_103 , ( int ) V_96 ) ) ;
break;
case V_109 :
case V_110 :
if ( V_164 == V_173 )
V_100 = L_93 ;
else if ( V_164 == V_174 )
V_100 = L_94 ;
else {
sprintf ( V_102 , L_95 , ( int ) V_164 ) ;
V_100 = V_102 ;
}
if ( V_162 == V_110 ) {
F_35 ( ( L_96 , V_101 ,
V_103 , V_100 ) ) ;
} else if ( V_95 == V_170 ) {
F_35 ( ( L_97 ,
V_101 , V_103 , V_100 ) ) ;
} else if ( V_95 == V_171 ) {
F_35 ( ( L_98 ,
V_101 , V_103 , V_100 ) ) ;
} else if ( V_95 == V_172 ) {
F_35 ( ( L_99
L_100 ,
V_101 , V_103 , V_100 , ( int ) V_96 ) ) ;
}
break;
case V_107 :
case V_125 :
case V_106 :
if ( V_95 == V_170 ) {
F_35 ( ( L_85 , V_101 ,
V_103 ) ) ;
} else if ( V_95 == V_172 ) {
F_35 ( ( L_101 , V_101 ) ) ;
} else if ( V_95 == V_175 ) {
F_35 ( ( L_102 ,
V_101 ) ) ;
} else {
F_35 ( ( L_103 ,
V_101 , ( int ) V_95 ) ) ;
}
break;
case V_121 :
if ( V_95 == V_170 ) {
F_35 ( ( L_104 , V_101 ) ) ;
} else if ( V_95 == V_172 ) {
F_35 ( ( L_105 , V_101 ) ) ;
} else {
F_35 ( ( L_106 , V_101 ,
V_95 ) ) ;
}
break;
case V_122 :
F_35 ( ( L_107 , V_101 ,
V_99 ? L_108 : L_109 ) ) ;
break;
case V_123 :
F_35 ( ( L_110 ,
V_101 , V_103 , V_97 , V_98 ) ) ;
break;
case V_153 :
case V_154 :
case V_155 :
F_35 ( ( L_85 , V_101 , V_103 ) ) ;
break;
case V_126 :
F_35 ( ( L_111 , V_101 , V_103 ) ) ;
break;
case V_132 :
case V_127 :
F_35 ( ( L_112 , V_101 ) ) ;
break;
case V_139 :
case V_140 :
case V_161 :
F_35 ( ( L_113 , V_101 ) ) ;
break;
case V_150 :
case V_129 :
F_35 ( ( L_114 ,
V_101 , ( int ) V_95 , ( int ) V_96 ) ) ;
break;
case V_156 :
{
static T_1 V_176 ;
struct V_177 V_178 ;
T_1 V_179 ;
char * V_180 , * V_71 ;
V_5 = ( unsigned char * ) V_93 ;
memcpy ( & V_178 , V_5 , sizeof( struct V_177 ) ) ;
if ( V_178 . V_181 != V_182 ) {
F_24 (
( L_115
L_116 ,
V_101 , V_182 , V_178 . V_181 )
) ;
V_165 = 0 ;
break;
}
* ( V_5 + sizeof( struct V_177 )
+ F_33 ( V_178 . V_52 ) ) = '\0' ;
if ( F_32 ( V_178 . V_183 )
|| F_32 ( V_178 . V_184 ) ) {
F_24 (
( L_117
L_118 ,
F_32 ( V_178 . V_183 ) ,
F_32 ( V_178 . V_184 ) ) ) ;
}
V_179 = F_32 ( V_178 . V_185 ) - V_176 - 1 ;
if ( V_179 > 0 ) {
F_24 (
( L_119 ,
F_32 ( V_178 . V_185 ) , V_179 ) ) ;
}
V_176 = F_32 ( V_178 . V_185 ) ;
V_71 = ( char * ) & V_5 [ sizeof( struct V_177 ) ] ;
while ( ( V_180 = strstr ( V_71 , L_2 ) ) != NULL ) {
* V_180 = '\0' ;
F_36 ( V_186 L_1 , V_71 ) ;
V_71 = V_180 + 1 ;
}
F_36 ( V_186 L_1 , V_71 ) ;
V_165 = 0 ;
}
break;
case V_160 :
F_35 ( ( L_120 , V_101 ,
F_32 ( * ( ( int * ) V_93 ) ) ) ) ;
break;
default:
F_35 ( ( L_121
L_122 , V_101 , V_162 , V_103 ,
( int ) V_95 , ( int ) V_96 , ( int ) V_164 ) ) ;
break;
}
if ( V_165 ) {
V_5 = ( unsigned char * ) V_93 ;
F_35 ( ( L_123 , V_165 ) ) ;
for ( V_94 = 0 ; V_94 < V_165 ; V_94 ++ )
F_35 ( ( L_124 , * V_5 ++ ) ) ;
F_35 ( ( L_2 ) ) ;
}
}
int
F_37 ( struct V_187 * V_188 , int * V_189 , void * V_190 ,
struct V_91 * V_92 , void * * V_191 )
{
struct V_192 * V_193 = (struct V_192 * ) V_190 ;
char * V_93 ;
T_1 type , V_95 ;
T_4 V_163 ;
int V_194 ;
if ( memcmp ( V_195 , & V_193 -> V_178 . V_196 [ 0 ] , V_197 ) ) {
F_24 ( ( L_125 , V_55 ) ) ;
return - V_198 ;
}
if ( F_38 ( & V_193 -> V_178 . V_199 ) !=
V_200 ) {
F_24 ( ( L_126 , V_55 ) ) ;
return - V_198 ;
}
* V_191 = & V_193 [ 1 ] ;
V_93 = * V_191 ;
memcpy ( V_92 , & V_193 -> V_201 , sizeof( struct V_91 ) ) ;
type = F_39 ( & V_92 -> V_162 ) ;
V_163 = F_38 ( & V_92 -> V_163 ) ;
V_95 = F_39 ( & V_92 -> V_95 ) ;
V_194 = F_39 ( & V_92 -> V_165 ) +
sizeof( struct V_192 ) ;
switch ( type ) {
case V_159 :
{
struct V_202 * V_203 =
(struct V_202 * ) V_93 ;
F_8 ( ( L_127 , V_55 ) ) ;
if ( V_203 -> V_189 > 0 &&
V_203 -> V_189 < V_204 ) {
if ( V_203 -> V_205 == V_206 )
F_40 ( V_188 , V_203 -> V_189 ,
NULL , V_92 -> V_207 ,
V_193 -> V_208 . V_209 ,
V_203 -> V_163 ,
V_203 -> V_210 ) ;
else
F_41 ( V_188 , V_203 -> V_189 ) ;
} else {
F_24 ( ( L_128 ,
V_55 , V_203 -> V_189 ,
V_92 -> V_207 ) ) ;
}
}
* V_189 = F_42 ( V_188 , V_92 -> V_207 ) ;
break;
case V_122 :
case V_114 :
case V_116 :
case V_118 :
case V_123 :
default:
* V_189 = F_42 ( V_188 , V_92 -> V_207 ) ;
F_8 ( ( L_129 ,
V_55 , type , V_163 , V_95 ) ) ;
if ( type == V_124 ) {
T_1 V_211 ;
V_211 = F_39 ( & V_92 -> V_162 ) ;
F_8 ( ( L_130 ,
V_211 ) ) ;
V_211 = F_32 ( V_124 ) ;
memcpy ( ( void * ) ( & V_193 -> V_201 . V_162 ) , & V_211 ,
sizeof( V_193 -> V_201 . V_162 ) ) ;
}
break;
}
#ifdef F_43
F_31 ( V_92 , V_93 ) ;
#endif
return 0 ;
}
static int F_44 ( char * V_212 , char * V_213 )
{
int V_94 ;
if ( strncmp ( V_212 , L_131 , 2 ) != 0 && strncmp ( V_212 , L_132 , 2 ) != 0 ) {
F_24 ( ( L_133 ) ) ;
return - 1 ;
}
V_212 = V_212 + 2 ;
if ( strlen ( V_212 ) % 2 != 0 ) {
F_24 ( ( L_134 ) ) ;
return - 1 ;
}
for ( V_94 = 0 ; * V_212 != '\0' ; V_94 ++ ) {
char V_214 [ 3 ] ;
strncpy ( V_214 , V_212 , 2 ) ;
V_214 [ 2 ] = '\0' ;
V_213 [ V_94 ] = ( V_215 ) F_45 ( V_214 , NULL , 16 ) ;
V_212 += 2 ;
}
return V_94 ;
}
void
F_46 ( struct V_3 * V_4 , char * V_51 , int V_216 ,
int V_217 )
{
char * V_218 [ 8 ] ;
int V_94 = 0 ;
const char * V_219 ;
int V_220 ;
int V_221 ;
char * V_222 = 0 , * V_223 = 0 ;
int V_224 ;
char V_5 [ 128 ] ;
struct V_225 V_226 ;
struct V_225 * V_227 ;
V_222 = F_47 ( strlen ( V_51 ) + 1 , V_228 ) ;
if ( ! V_222 ) {
F_24 ( ( L_135 , V_55 ) ) ;
goto V_229;
}
V_223 = V_222 ;
memcpy ( V_222 , V_51 , strlen ( V_51 ) + 1 ) ;
V_218 [ V_94 ] = F_48 ( & V_222 , L_136 ) ;
V_94 = 0 ;
if ( NULL == V_218 [ V_94 ] ) {
F_24 ( ( L_137 ) ) ;
goto V_229;
}
V_219 = L_138 ;
V_221 = strlen ( V_219 ) ;
strncpy ( V_5 , V_219 , V_221 ) ;
V_5 [ V_221 ] = '\0' ;
V_220 = V_221 + 1 ;
V_227 = (struct V_225 * ) ( V_5 + V_221 + 1 ) ;
V_226 . V_230 = F_45 ( V_218 [ V_94 ] , NULL , 0 ) ;
V_226 . V_216 = V_216 ;
V_220 += sizeof( V_226 ) ;
memcpy ( ( char * ) V_227 , & V_226 , sizeof( V_226 ) ) ;
V_224 = F_49 ( V_4 , 0 , V_231 , V_5 , V_220 ) ;
V_224 = V_224 >= 0 ? 0 : V_224 ;
if ( V_224 )
F_8 ( ( L_139 ,
V_55 , V_51 , V_224 ) ) ;
else
F_8 ( ( L_140 ,
V_55 , V_51 ) ) ;
F_50 ( L_141 , ( char * ) & V_217 , 4 , V_5 ,
sizeof( V_5 ) ) ;
V_224 = F_49 ( V_4 , 0 , V_231 , V_5 ,
sizeof( V_5 ) ) ;
V_224 = V_224 >= 0 ? 0 : V_224 ;
if ( V_224 )
F_8 ( ( L_139 ,
V_55 , V_51 , V_224 ) ) ;
V_229:
F_51 ( V_223 ) ;
}
void F_52 ( struct V_3 * V_4 , char * V_51 )
{
const char * V_219 ;
struct V_232 V_233 ;
struct V_232 * V_227 ;
int V_220 ;
int V_221 ;
int V_224 ;
T_1 V_234 ;
T_1 V_235 ;
char * V_218 [ 8 ] , * V_5 = 0 ;
int V_94 = 0 ;
char * V_222 = 0 , * V_223 = 0 ;
V_222 = F_47 ( strlen ( V_51 ) + 1 , V_228 ) ;
if ( ! V_222 ) {
F_24 ( ( L_135 , V_55 ) ) ;
goto V_229;
}
V_223 = V_222 ;
V_5 = F_47 ( V_236 , V_228 ) ;
if ( ! V_5 ) {
F_24 ( ( L_135 , V_55 ) ) ;
goto V_229;
}
strcpy ( V_222 , V_51 ) ;
V_218 [ V_94 ] = F_48 ( & V_222 , L_136 ) ;
while ( V_218 [ V_94 ++ ] )
V_218 [ V_94 ] = F_48 ( & V_222 , L_136 ) ;
V_94 = 0 ;
if ( NULL == V_218 [ V_94 ] ) {
F_24 ( ( L_137 ) ) ;
goto V_229;
}
V_219 = L_142 ;
strcpy ( V_5 , V_219 ) ;
V_221 = strlen ( V_219 ) ;
V_220 = V_221 + 1 ;
V_227 = (struct V_232 * ) ( V_5 + V_221 + 1 ) ;
V_233 . V_230 = F_45 ( V_218 [ V_94 ] , NULL , 0 ) ;
if ( NULL == V_218 [ ++ V_94 ] ) {
F_24 ( ( L_143 ) ) ;
goto V_229;
}
V_233 . V_237 = F_45 ( V_218 [ V_94 ] , NULL , 0 ) ;
if ( NULL == V_218 [ ++ V_94 ] ) {
F_24 ( ( L_144 ) ) ;
goto V_229;
}
V_233 . type = F_45 ( V_218 [ V_94 ] , NULL , 0 ) ;
if ( NULL == V_218 [ ++ V_94 ] ) {
F_24 ( ( L_145 ) ) ;
goto V_229;
}
V_233 . V_238 . V_239 . V_240 = F_45 ( V_218 [ V_94 ] , NULL , 0 ) ;
if ( NULL == V_218 [ ++ V_94 ] ) {
F_24 ( ( L_146 ) ) ;
goto V_229;
}
V_234 =
F_44
( V_218 [ V_94 ] , ( char * ) V_227 -> V_238 . V_239 . V_241 ) ;
if ( NULL == V_218 [ ++ V_94 ] ) {
F_24 ( ( L_147 ) ) ;
goto V_229;
}
V_235 =
F_44 ( V_218 [ V_94 ] ,
( char * ) & V_227 -> V_238 . V_239 .
V_241 [ V_234 ] ) ;
if ( V_234 != V_235 ) {
F_24 ( ( L_148 ) ) ;
goto V_229;
}
V_233 . V_238 . V_239 . V_242 = V_234 ;
V_220 += V_243 ;
V_220 += ( V_244 + 2 * V_234 ) ;
memcpy ( ( char * ) V_227 ,
& V_233 ,
V_243 + V_244 ) ;
V_224 = F_49 ( V_4 , 0 , V_231 , V_5 , V_220 ) ;
V_224 = V_224 >= 0 ? 0 : V_224 ;
if ( V_224 )
F_8 ( ( L_139 ,
V_55 , V_51 , V_224 ) ) ;
else
F_8 ( ( L_140 ,
V_55 , V_51 ) ) ;
V_229:
F_51 ( V_223 ) ;
F_51 ( V_5 ) ;
}
void F_53 ( struct V_3 * V_4 , int V_245 )
{
char V_246 [ 32 ] ;
int V_247 ;
F_50 ( L_149 , ( char * ) & V_245 , 4 , V_246 , sizeof( V_246 ) ) ;
V_247 = F_49 ( V_4 , 0 , V_231 ,
V_246 , sizeof( V_246 ) ) ;
V_247 = V_247 >= 0 ? 0 : V_247 ;
if ( V_247 )
F_8 ( ( L_150
L_151 , V_55 , V_245 , V_247 ) ) ;
else
F_8 ( ( L_152 ,
V_55 , V_245 ) ) ;
}
void F_54 ( struct V_3 * V_4 , int V_248 )
{
char V_246 [ 32 ] ;
int V_247 ;
F_50 ( L_153 , ( char * ) & V_248 , 4 , V_246 , sizeof( V_246 ) ) ;
V_247 = F_49 ( V_4 , 0 , V_231 ,
V_246 , sizeof( V_246 ) ) ;
V_247 = V_247 >= 0 ? 0 : V_247 ;
if ( V_247 )
F_8 ( ( L_154
L_151 , V_55 , V_248 , V_247 ) ) ;
else
F_8 ( ( L_155 ,
V_55 , V_248 ) ) ;
}
int F_55 ( struct V_3 * V_4 )
{
char V_246 [ V_249 + 12 ] ;
T_3 V_11 = 0 ;
char V_5 [ 128 ] , * V_250 ;
T_3 V_251 = V_252 ;
T_1 V_253 = V_254 ;
T_1 V_255 = 0 ;
T_3 V_256 = 3 ;
int V_257 = 40 ;
int V_258 = 40 ;
int V_94 ;
F_56 ( V_4 ) ;
if ( V_4 -> V_259 [ 0 ] != 0 ) {
if ( F_49 ( V_4 , 0 , V_260 ,
V_4 -> V_259 ,
sizeof( V_4 -> V_259 ) ) < 0 ) {
F_24 ( ( L_156 ,
V_55 ) ) ;
}
}
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
V_250 = V_5 ;
F_50 ( L_157 , 0 , 0 , V_5 , sizeof( V_5 ) ) ;
F_57 ( V_4 , 0 , V_261 , V_5 , sizeof( V_5 ) ) ;
F_48 ( & V_250 , L_2 ) ;
F_24 ( ( L_158 , V_5 ) ) ;
F_49 ( V_4 , 0 , V_262 , ( char * ) & V_251 ,
sizeof( V_251 ) ) ;
F_50 ( L_159 , ( char * ) & V_253 , 4 , V_246 ,
sizeof( V_246 ) ) ;
F_49 ( V_4 , 0 , V_231 , V_246 ,
sizeof( V_246 ) ) ;
F_50 ( L_160 , ( char * ) & V_255 , 4 , V_246 , sizeof( V_246 ) ) ;
F_49 ( V_4 , 0 , V_231 , V_246 ,
sizeof( V_246 ) ) ;
F_50 ( L_161 , ( char * ) & V_256 , 4 , V_246 ,
sizeof( V_246 ) ) ;
F_49 ( V_4 , 0 , V_231 , V_246 ,
sizeof( V_246 ) ) ;
F_50 ( L_162 , ( char * ) & V_263 , 4 ,
V_246 , sizeof( V_246 ) ) ;
F_49 ( V_4 , 0 , V_231 , V_246 ,
sizeof( V_246 ) ) ;
if ( V_264 )
F_49 ( V_4 , 0 , V_265 , ( char * ) & V_11 ,
sizeof( V_11 ) ) ;
F_50 ( L_163 , V_4 -> V_266 , V_249 ,
V_246 , sizeof( V_246 ) ) ;
F_49 ( V_4 , 0 , V_231 , V_246 ,
sizeof( V_246 ) ) ;
F_49 ( V_4 , 0 , V_267 ,
( char * ) & V_257 , sizeof( V_257 ) ) ;
F_49 ( V_4 , 0 , V_268 ,
( char * ) & V_258 , sizeof( V_258 ) ) ;
if ( V_269 )
F_53 ( V_4 , V_270 ) ;
F_54 ( V_4 , V_269 ) ;
if ( V_225 ) {
for ( V_94 = 0 ; V_94 < V_4 -> V_271 ; V_94 ++ ) {
F_52 ( V_4 ,
V_4 -> V_272 [ V_94 ] ) ;
F_46 ( V_4 ,
V_4 -> V_272 [ V_94 ] ,
V_273 ,
V_274 ) ;
}
}
F_58 ( V_4 ) ;
return 0 ;
}
