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
V_2 -> V_20 = V_5 -> V_21 ;
if ( V_5 -> V_22 )
V_2 -> V_23 = V_5 -> V_22 -> V_24 ;
if ( V_5 -> V_25 & V_26 )
V_2 -> V_27 |= V_28 ;
if ( V_5 -> V_22 && V_5 -> V_22 -> V_29 &&
( V_5 -> V_22 -> V_29 -> V_30 & V_31 ) )
V_2 -> V_27 |= V_32 ;
V_19:
V_7 -> V_33 = F_4 ( V_9 ) ;
return;
}
static int
F_6 ( T_1 V_34 , struct V_4 * V_5 )
{
int V_35 = 0 ;
struct V_36 * V_37 ;
struct V_38 * V_22 ;
struct V_39 * V_29 ;
if ( V_5 == NULL )
return V_35 ;
if ( V_34 == V_40 )
return V_35 ;
if ( V_5 -> V_41 == V_42 ) {
if ( ( V_34 != V_43 ) &&
( V_34 != V_44 ) &&
( V_34 != V_45 ) ) {
F_7 ( 1 , L_1 ,
V_34 ) ;
return - V_46 ;
}
}
if ( ( ! V_5 -> V_22 ) || ( V_5 -> V_22 -> V_47 == V_42 ) ||
( ! V_5 -> V_22 -> V_29 ) )
return - V_48 ;
V_22 = V_5 -> V_22 ;
V_29 = V_22 -> V_29 ;
while ( V_29 -> V_49 == V_50 ) {
switch ( V_34 ) {
case V_45 :
case V_51 :
case V_52 :
case V_53 :
return - V_54 ;
}
F_8 ( V_29 -> V_55 ,
( V_29 -> V_49 != V_50 ) , 10 * V_56 ) ;
if ( V_29 -> V_49 != V_50 )
break;
if ( ! V_5 -> V_57 ) {
F_7 ( 1 , L_2 ) ;
return - V_58 ;
}
}
if ( ! V_5 -> V_22 -> V_59 && ! V_5 -> V_59 )
return V_35 ;
V_37 = F_9 () ;
F_10 ( & V_5 -> V_22 -> V_60 ) ;
V_35 = F_11 ( 0 , V_5 -> V_22 ) ;
if ( ! V_35 && V_5 -> V_22 -> V_59 )
V_35 = F_12 ( 0 , V_5 -> V_22 , V_37 ) ;
if ( V_35 || ! V_5 -> V_59 ) {
F_13 ( & V_5 -> V_22 -> V_60 ) ;
goto V_19;
}
F_14 ( V_5 ) ;
V_35 = F_15 ( 0 , V_5 -> V_22 , V_5 -> V_61 , V_5 , V_37 ) ;
F_13 ( & V_5 -> V_22 -> V_60 ) ;
F_7 ( 1 , L_3 , V_35 ) ;
if ( V_35 )
goto V_19;
F_16 ( & V_62 ) ;
V_19:
switch ( V_34 ) {
case V_63 :
case V_64 :
case V_43 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
return - V_54 ;
}
F_17 ( V_37 ) ;
return V_35 ;
}
static int
F_18 ( T_1 V_34 , struct V_4 * V_5 ,
void * * V_71 )
{
int V_35 = 0 ;
V_35 = F_6 ( V_34 , V_5 ) ;
if ( V_35 )
return V_35 ;
* V_71 = F_19 () ;
if ( * V_71 == NULL ) {
return - V_72 ;
}
F_1 ( (struct V_1 * ) * V_71 , V_34 , V_5 ) ;
if ( V_5 != NULL ) {
#ifdef F_20
T_3 V_73 = F_2 ( V_34 ) ;
F_21 ( & V_5 -> V_74 . V_75 . V_76 [ V_73 ] ) ;
#endif
F_21 ( & V_5 -> V_77 ) ;
}
return V_35 ;
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
F_25 ( const unsigned int V_82 , struct V_38 * V_22 )
{
struct V_83 * V_84 ;
struct V_85 * V_79 ;
struct V_86 V_87 [ 1 ] ;
int V_35 = 0 ;
int V_78 ;
struct V_39 * V_29 ;
unsigned int V_88 ;
T_4 V_8 = 0 ;
int V_89 , V_90 ;
char * V_91 ;
int V_92 = V_93 ;
F_7 ( 1 , L_4 ) ;
if ( V_22 -> V_29 )
V_29 = V_22 -> V_29 ;
else {
V_35 = - V_48 ;
return V_35 ;
}
V_35 = F_18 ( V_94 , NULL , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
if ( V_22 -> V_95 & ( ~ ( V_96 | V_97 ) ) )
V_88 = V_22 -> V_95 ;
else
V_88 = V_98 | V_22 -> V_95 ;
F_7 ( 1 , L_5 , V_88 ) ;
V_84 -> V_2 . V_23 = 0 ;
V_84 -> V_99 [ 0 ] = F_4 ( V_22 -> V_29 -> V_100 -> V_101 ) ;
V_84 -> V_102 = F_4 ( 1 ) ;
F_26 ( V_84 , 2 ) ;
if ( ( V_88 & V_96 ) == V_96 )
V_8 = V_103 ;
else if ( V_88 & V_104 )
V_8 = V_105 ;
V_84 -> V_106 = F_4 ( V_8 ) ;
V_84 -> V_107 = F_5 ( V_22 -> V_29 -> V_100 -> V_108 ) ;
memcpy ( V_84 -> V_109 , V_110 , V_111 ) ;
V_87 [ 0 ] . V_112 = ( char * ) V_84 ;
V_87 [ 0 ] . V_113 = F_27 ( V_84 ) + 4 ;
V_35 = F_28 ( V_82 , V_22 , V_87 , 1 , & V_78 , V_92 ) ;
V_79 = (struct V_85 * ) V_87 [ 0 ] . V_112 ;
if ( V_35 != 0 )
goto V_114;
F_7 ( 1 , L_6 , V_79 -> V_106 ) ;
if ( V_79 -> V_115 == F_4 ( V_116 ) )
F_7 ( 1 , L_7 ) ;
else if ( V_79 -> V_115 == F_4 ( V_117 ) )
F_7 ( 1 , L_8 ) ;
else if ( V_79 -> V_115 == F_4 ( V_118 ) )
F_7 ( 1 , L_9 ) ;
else {
F_29 ( 1 , L_10 ,
F_2 ( V_79 -> V_115 ) ) ;
V_35 = - V_48 ;
goto V_114;
}
V_29 -> V_119 = F_2 ( V_79 -> V_115 ) ;
V_29 -> V_120 = F_30 ( V_79 -> V_121 ) ;
V_29 -> V_122 = F_30 ( V_79 -> V_123 ) ;
V_29 -> V_124 = F_30 ( V_79 -> V_125 ) ;
V_29 -> V_30 = F_2 ( V_79 -> V_106 ) ;
V_29 -> V_126 = F_30 ( V_79 -> V_107 ) ;
V_29 -> V_126 |= V_127 | V_128 ;
V_91 = F_31 ( & V_89 , & V_90 ,
& V_79 -> V_2 ) ;
if ( V_90 == 0 ) {
F_29 ( 1 , L_11 ) ;
V_35 = - V_48 ;
goto V_114;
}
F_7 ( 1 , L_5 , V_88 ) ;
if ( V_88 & V_96 ) {
F_7 ( 1 , L_12 ) ;
if ( ! ( V_29 -> V_30 & ( V_103 |
V_105 ) ) ) {
F_29 ( 1 , L_13 ) ;
V_35 = - V_129 ;
goto V_114;
}
V_29 -> V_30 |= V_31 ;
} else if ( V_88 & V_104 ) {
F_7 ( 1 , L_14 ) ;
if ( V_29 -> V_30 & V_103 ) {
F_7 ( 1 , L_15 ) ;
V_29 -> V_30 |= V_31 ;
} else {
V_29 -> V_30 &=
~ ( V_130 | V_31 ) ;
}
} else {
F_7 ( 1 , L_16 ) ;
if ( V_29 -> V_30 & V_103 ) {
F_29 ( 1 , L_17
L_18 ) ;
V_35 = - V_129 ;
goto V_114;
}
V_29 -> V_30 &=
~ ( V_130 | V_31 ) ;
}
#ifdef F_32
V_35 = F_33 ( V_91 , V_90 ,
& V_29 -> V_131 ) ;
if ( V_35 == 1 )
V_35 = 0 ;
else if ( V_35 == 0 ) {
V_35 = - V_48 ;
goto V_114;
}
#endif
V_114:
F_22 ( V_78 , V_79 ) ;
return V_35 ;
}
int
F_34 ( const unsigned int V_82 , struct V_38 * V_22 ,
const struct V_36 * V_132 )
{
struct V_133 * V_84 ;
struct V_134 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_35 = 0 ;
int V_78 ;
T_5 V_135 = V_136 ;
struct V_39 * V_29 ;
unsigned int V_88 ;
T_6 V_8 = 0 ;
T_4 V_90 = 0 ;
char * V_91 ;
char * V_137 = NULL ;
bool V_138 = false ;
F_7 ( 1 , L_19 ) ;
if ( V_22 -> V_29 )
V_29 = V_22 -> V_29 ;
else {
V_35 = - V_48 ;
return V_35 ;
}
V_22 -> V_139 = F_35 ( sizeof( struct V_140 ) , V_141 ) ;
if ( ! V_22 -> V_139 )
return - V_72 ;
V_22 -> V_29 -> V_142 = V_143 ;
V_144:
if ( V_135 == V_145 )
V_135 = V_146 ;
V_35 = F_18 ( V_147 , NULL , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
if ( V_22 -> V_95 & ( ~ ( V_96 | V_97 ) ) )
V_88 = V_22 -> V_95 ;
else
V_88 = V_98 | V_22 -> V_95 ;
F_7 ( 1 , L_5 , V_88 ) ;
V_84 -> V_2 . V_23 = 0 ;
V_84 -> V_148 = 0 ;
V_84 -> V_2 . V_15 = F_4 ( 3 ) ;
if ( ( V_88 & V_96 ) == V_96 )
V_8 = V_103 ;
else if ( V_22 -> V_29 -> V_30 & V_103 )
V_8 = V_103 ;
else if ( V_88 & V_104 )
V_8 = V_105 ;
V_84 -> V_106 = V_8 ;
V_84 -> V_107 = 0 ;
V_84 -> V_149 = 0 ;
V_87 [ 0 ] . V_112 = ( char * ) V_84 ;
V_87 [ 0 ] . V_113 = F_27 ( V_84 ) + 4 - 1 ;
if ( V_135 == V_136 ) {
V_137 = F_35 ( sizeof( struct V_150 ) ,
V_141 ) ;
if ( V_137 == NULL ) {
V_35 = - V_72 ;
goto V_151;
}
F_36 ( V_137 , V_22 ) ;
if ( V_138 ) {
F_29 ( 1 , L_20 ) ;
V_35 = - V_129 ;
F_37 ( V_137 ) ;
goto V_151;
} else {
V_90 = sizeof( struct V_150 ) ;
V_91 = V_137 ;
}
} else if ( V_135 == V_146 ) {
V_84 -> V_2 . V_23 = V_22 -> V_24 ;
V_137 = F_38 ( sizeof( struct V_150 ) + 500 ,
V_141 ) ;
if ( V_137 == NULL ) {
F_29 ( 1 , L_21 ) ;
V_35 = - V_72 ;
goto V_151;
}
V_35 = F_39 ( V_137 , & V_90 , V_22 ,
V_132 ) ;
if ( V_35 ) {
F_7 ( 1 , L_22 , V_35 ) ;
goto V_151;
}
if ( V_138 ) {
F_29 ( 1 , L_20 ) ;
V_35 = - V_129 ;
F_37 ( V_137 ) ;
goto V_151;
} else {
V_91 = V_137 ;
}
} else {
F_29 ( 1 , L_23 ) ;
V_35 = - V_48 ;
goto V_151;
}
V_84 -> V_152 =
F_4 ( sizeof( struct V_133 ) -
1 - 4 ) ;
V_84 -> V_153 = F_4 ( V_90 ) ;
V_87 [ 1 ] . V_112 = V_91 ;
V_87 [ 1 ] . V_113 = V_90 ;
F_26 ( V_84 , V_90 - 1 ) ;
V_35 = F_28 ( V_82 , V_22 , V_87 , 2 , & V_78 , V_154 ) ;
F_37 ( V_91 ) ;
V_79 = (struct V_134 * ) V_87 [ 0 ] . V_112 ;
if ( V_78 != V_155 &&
V_79 -> V_2 . V_156 == V_157 ) {
if ( V_135 != V_136 ) {
F_29 ( 1 , L_24 ) ;
goto V_151;
}
if ( F_40 ( struct V_134 , V_158 ) - 4 !=
F_2 ( V_79 -> V_152 ) ) {
F_29 ( 1 , L_25 ,
F_2 ( V_79 -> V_152 ) ) ;
V_35 = - V_48 ;
goto V_151;
}
V_135 = V_145 ;
V_35 = 0 ;
V_22 -> V_24 = V_79 -> V_2 . V_23 ;
V_35 = F_41 ( V_79 -> V_158 ,
F_2 ( V_79 -> V_153 ) , V_22 ) ;
}
if ( V_35 != 0 )
goto V_151;
V_22 -> V_159 = F_2 ( V_79 -> V_160 ) ;
V_151:
F_22 ( V_78 , V_79 ) ;
if ( ( V_135 == V_145 ) && ( V_35 == 0 ) )
goto V_144;
return V_35 ;
}
int
F_42 ( const unsigned int V_82 , struct V_38 * V_22 )
{
struct V_161 * V_84 ;
int V_35 = 0 ;
struct V_39 * V_29 ;
F_7 ( 1 , L_26 , V_22 ) ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_48 ;
V_35 = F_18 ( V_162 , NULL , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
V_84 -> V_2 . V_23 = V_22 -> V_24 ;
if ( V_29 -> V_30 & V_31 )
V_84 -> V_2 . V_27 |= V_32 ;
V_35 = F_43 ( V_82 , V_22 , ( char * ) & V_84 -> V_2 , 0 ) ;
return V_35 ;
}
static inline void F_44 ( struct V_4 * V_5 , T_3 V_163 )
{
F_21 ( & V_5 -> V_74 . V_75 . V_164 [ V_163 ] ) ;
}
int
F_15 ( const unsigned int V_82 , struct V_38 * V_22 , const char * V_165 ,
struct V_4 * V_5 , const struct V_36 * V_166 )
{
struct V_167 * V_84 ;
struct V_168 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_35 = 0 ;
int V_78 ;
int V_169 ;
struct V_39 * V_29 ;
T_1 * V_170 = NULL ;
F_7 ( 1 , L_27 ) ;
if ( ( V_22 -> V_29 ) && V_165 )
V_29 = V_22 -> V_29 ;
else
return - V_48 ;
if ( V_5 && V_5 -> V_171 )
return - V_172 ;
V_170 = F_35 ( V_173 * 2 , V_141 ) ;
if ( V_170 == NULL )
return - V_72 ;
V_169 = F_45 ( V_170 , V_165 , strlen ( V_165 ) , V_166 ) + 1 ;
V_169 *= 2 ;
if ( V_169 < 2 ) {
F_37 ( V_170 ) ;
return - V_174 ;
}
V_35 = F_18 ( V_40 , V_5 , ( void * * ) & V_84 ) ;
if ( V_35 ) {
F_37 ( V_170 ) ;
return V_35 ;
}
if ( V_5 == NULL ) {
V_84 -> V_2 . V_23 = V_22 -> V_24 ;
}
V_87 [ 0 ] . V_112 = ( char * ) V_84 ;
V_87 [ 0 ] . V_113 = F_27 ( V_84 ) + 4 - 1 ;
V_84 -> V_175 = F_4 ( sizeof( struct V_167 )
- 1 - 4 ) ;
V_84 -> V_176 = F_4 ( V_169 - 2 ) ;
V_87 [ 1 ] . V_112 = V_170 ;
V_87 [ 1 ] . V_113 = V_169 ;
F_26 ( V_84 , V_169 - 1 ) ;
V_35 = F_28 ( V_82 , V_22 , V_87 , 2 , & V_78 , 0 ) ;
V_79 = (struct V_168 * ) V_87 [ 0 ] . V_112 ;
if ( V_35 != 0 ) {
if ( V_5 ) {
F_44 ( V_5 , V_177 ) ;
V_5 -> V_59 = true ;
}
goto V_178;
}
if ( V_5 == NULL ) {
V_22 -> V_179 = V_79 -> V_2 . V_20 ;
goto V_180;
}
if ( V_79 -> V_181 & V_182 )
F_7 ( 1 , L_28 ) ;
else if ( V_79 -> V_181 & V_183 ) {
V_5 -> V_184 = true ;
F_7 ( 1 , L_29 ) ;
} else if ( V_79 -> V_181 & V_185 ) {
V_5 -> V_186 = true ;
F_7 ( 1 , L_30 ) ;
} else {
F_29 ( 1 , L_31 , V_79 -> V_181 ) ;
V_35 = - V_129 ;
goto V_178;
}
V_5 -> V_25 = F_30 ( V_79 -> V_187 ) ;
V_5 -> V_188 = F_30 ( V_79 -> V_189 ) ;
V_5 -> V_41 = V_190 ;
V_5 -> V_59 = false ;
V_5 -> V_21 = V_79 -> V_2 . V_20 ;
strncpy ( V_5 -> V_61 , V_165 , V_191 ) ;
if ( ( V_79 -> V_107 & V_192 ) &&
( ( V_5 -> V_25 & V_26 ) == 0 ) )
F_29 ( 1 , L_32 ) ;
V_180:
F_22 ( V_78 , V_79 ) ;
F_37 ( V_170 ) ;
return V_35 ;
V_178:
if ( V_79 -> V_2 . V_156 == V_193 ) {
F_29 ( 1 , L_33 , V_165 ) ;
V_5 -> V_171 = true ;
}
goto V_180;
}
int
F_46 ( const unsigned int V_82 , struct V_4 * V_5 )
{
struct V_194 * V_84 ;
int V_35 = 0 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
F_7 ( 1 , L_34 ) ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_48 ;
if ( ( V_5 -> V_59 ) || ( V_5 -> V_22 -> V_59 ) )
return 0 ;
V_35 = F_18 ( V_45 , V_5 , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_43 ( V_82 , V_22 , ( char * ) & V_84 -> V_2 , 0 ) ;
if ( V_35 )
F_44 ( V_5 , V_195 ) ;
return V_35 ;
}
static struct V_196 *
F_47 ( T_6 * V_197 , T_6 V_198 )
{
struct V_196 * V_199 ;
V_199 = F_35 ( sizeof( struct V_196 ) , V_141 ) ;
if ( ! V_199 )
return NULL ;
memset ( V_199 , 0 , sizeof( struct V_196 ) ) ;
V_199 -> V_200 . V_201 = F_48 ( * ( ( V_202 * ) V_197 ) ) ;
V_199 -> V_200 . V_203 = F_48 ( * ( ( V_202 * ) ( V_197 + 8 ) ) ) ;
if ( V_198 == V_204 )
V_199 -> V_200 . V_205 = V_206 |
V_207 ;
else if ( V_198 == V_208 )
V_199 -> V_200 . V_205 = V_207 ;
else if ( V_198 == V_209 )
V_199 -> V_200 . V_205 = V_210 |
V_207 |
V_206 ;
V_199 -> V_211 . V_212 = F_4 ( F_40
( struct V_196 , V_200 ) ) ;
V_199 -> V_211 . V_213 = F_5 ( sizeof( struct V_214 ) ) ;
V_199 -> V_211 . V_215 = F_4 ( F_40
( struct V_196 , V_216 ) ) ;
V_199 -> V_211 . V_217 = F_4 ( 4 ) ;
V_199 -> V_216 [ 0 ] = 'R' ;
V_199 -> V_216 [ 1 ] = 'q' ;
V_199 -> V_216 [ 2 ] = 'L' ;
V_199 -> V_216 [ 3 ] = 's' ;
return V_199 ;
}
static T_7
F_49 ( struct V_218 * V_79 )
{
char * V_219 ;
struct V_196 * V_220 ;
bool V_221 = false ;
V_219 = ( char * ) V_79 ;
V_219 += 4 + F_30 ( V_79 -> V_222 ) ;
V_220 = (struct V_196 * ) V_219 ;
do {
char * V_223 = F_2 ( V_220 -> V_211 . V_215 ) + ( char * ) V_220 ;
if ( F_2 ( V_220 -> V_211 . V_217 ) != 4 ||
strncmp ( V_223 , L_35 , 4 ) ) {
V_220 = (struct V_196 * ) ( ( char * ) V_220
+ F_30 ( V_220 -> V_211 . V_224 ) ) ;
continue;
}
if ( V_220 -> V_200 . V_225 & V_226 )
return V_227 ;
V_221 = true ;
break;
} while ( F_30 ( V_220 -> V_211 . V_224 ) != 0 );
if ( ! V_221 )
return 0 ;
return F_50 ( V_220 -> V_200 . V_205 ) ;
}
int
F_51 ( const unsigned int V_82 , struct V_4 * V_5 , T_1 * V_228 ,
V_202 * V_229 , V_202 * V_230 , T_8 V_231 ,
T_8 V_232 , T_8 V_233 , T_8 V_234 ,
T_7 * V_198 , struct V_235 * V_199 )
{
struct V_236 * V_84 ;
struct V_218 * V_79 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
struct V_86 V_87 [ 3 ] ;
int V_78 ;
int V_237 ;
T_1 * V_238 = NULL ;
int V_239 ;
int V_35 = 0 ;
int V_240 = 2 ;
F_7 ( 1 , L_36 ) ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_48 ;
V_35 = F_18 ( V_44 , V_5 , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
V_84 -> V_241 = V_242 ;
V_84 -> V_243 = F_5 ( V_231 ) ;
V_84 -> V_244 = F_5 ( V_233 ) ;
V_84 -> V_245 = V_246 ;
V_84 -> V_247 = F_5 ( V_232 ) ;
V_84 -> V_248 = F_5 ( V_234 ) ;
V_237 = ( 2 * F_52 ( ( V_249 * ) V_228 , V_250 ) ) + 2 ;
V_84 -> V_215 = F_4 ( sizeof( struct V_236 )
- 8 - 4 ) ;
V_87 [ 0 ] . V_112 = ( char * ) V_84 ;
V_87 [ 0 ] . V_113 = F_27 ( V_84 ) + 4 ;
if ( V_237 >= 4 ) {
V_84 -> V_217 = F_4 ( V_237 - 2 ) ;
V_87 [ 0 ] . V_113 -- ;
if ( V_237 % 8 != 0 ) {
V_239 = V_237 / 8 * 8 ;
if ( V_239 < V_237 )
V_239 += 8 ;
V_238 = F_38 ( V_239 , V_141 ) ;
if ( ! V_238 )
return - V_72 ;
memcpy ( ( char * ) V_238 , ( const char * ) V_228 ,
V_237 ) ;
V_237 = V_239 ;
V_228 = V_238 ;
}
V_87 [ 1 ] . V_113 = V_237 ;
V_87 [ 1 ] . V_112 = V_228 ;
F_26 ( V_84 , V_237 - 1 ) ;
} else {
V_87 [ 0 ] . V_113 += 7 ;
V_84 -> V_2 . V_11 = F_3 ( F_53 (
V_84 -> V_2 . V_11 ) + 8 - 1 ) ;
V_240 = 1 ;
V_84 -> V_217 = 0 ;
}
if ( ! V_29 -> V_251 )
* V_198 = V_252 ;
if ( ! ( V_5 -> V_22 -> V_29 -> V_126 & V_253 ) ||
* V_198 == V_252 )
V_84 -> V_254 = * V_198 ;
else {
V_87 [ V_240 ] . V_112 = F_47 ( V_198 + 1 , * V_198 ) ;
if ( V_87 [ V_240 ] . V_112 == NULL ) {
F_23 ( V_84 ) ;
F_37 ( V_238 ) ;
return - V_72 ;
}
V_87 [ V_240 ] . V_113 = sizeof( struct V_196 ) ;
V_84 -> V_254 = V_255 ;
V_84 -> V_222 = F_5 (
sizeof( struct V_236 ) - 4 - 8 +
V_87 [ V_240 - 1 ] . V_113 ) ;
V_84 -> V_256 = F_5 (
sizeof( struct V_196 ) ) ;
F_26 ( & V_84 -> V_2 , sizeof( struct V_196 ) ) ;
V_240 ++ ;
}
V_35 = F_28 ( V_82 , V_22 , V_87 , V_240 , & V_78 , 0 ) ;
V_79 = (struct V_218 * ) V_87 [ 0 ] . V_112 ;
if ( V_35 != 0 ) {
F_44 ( V_5 , V_257 ) ;
goto V_258;
}
* V_229 = V_79 -> V_259 ;
* V_230 = V_79 -> V_260 ;
if ( V_199 ) {
memcpy ( V_199 , & V_79 -> V_261 , 32 ) ;
V_199 -> V_262 = V_79 -> V_262 ;
V_199 -> V_263 = V_79 -> V_264 ;
V_199 -> V_265 = V_79 -> V_244 ;
V_199 -> V_266 = F_5 ( 1 ) ;
V_199 -> V_267 = 0 ;
}
if ( V_79 -> V_268 == V_255 )
* V_198 = F_49 ( V_79 ) ;
else
* V_198 = V_79 -> V_268 ;
V_258:
F_37 ( V_238 ) ;
F_22 ( V_78 , V_79 ) ;
return V_35 ;
}
int
F_54 ( const unsigned int V_82 , struct V_4 * V_5 ,
V_202 V_229 , V_202 V_230 )
{
struct V_269 * V_84 ;
struct V_270 * V_79 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
struct V_86 V_87 [ 1 ] ;
int V_78 ;
int V_35 = 0 ;
F_7 ( 1 , L_37 ) ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_48 ;
V_35 = F_18 ( V_52 , V_5 , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
V_84 -> V_259 = V_229 ;
V_84 -> V_260 = V_230 ;
V_87 [ 0 ] . V_112 = ( char * ) V_84 ;
V_87 [ 0 ] . V_113 = F_27 ( V_84 ) + 4 ;
V_35 = F_28 ( V_82 , V_22 , V_87 , 1 , & V_78 , 0 ) ;
V_79 = (struct V_270 * ) V_87 [ 0 ] . V_112 ;
if ( V_35 != 0 ) {
if ( V_5 )
F_44 ( V_5 , V_271 ) ;
goto V_272;
}
V_272:
F_22 ( V_78 , V_79 ) ;
return V_35 ;
}
static int
F_55 ( unsigned int V_273 , unsigned int V_274 ,
struct V_1 * V_2 , unsigned int V_275 )
{
unsigned int V_276 = F_53 ( V_2 -> V_11 ) ;
char * V_277 = V_276 + 4 + ( char * ) V_2 ;
char * V_278 = 4 + V_273 + ( char * ) V_2 ;
char * V_279 = V_278 + V_274 ;
if ( V_274 < V_275 ) {
F_29 ( 1 , L_38 ,
V_274 , V_275 ) ;
return - V_174 ;
}
if ( ( V_276 > 0x7FFFFF ) || ( V_274 > 0x7FFFFF ) ) {
F_29 ( 1 , L_39 ,
V_274 , V_276 ) ;
return - V_174 ;
}
if ( ( V_278 > V_277 ) || ( V_279 > V_277 ) ) {
F_29 ( 1 , L_40 ) ;
return - V_174 ;
}
return 0 ;
}
static int
F_56 ( unsigned int V_273 , unsigned int V_274 ,
struct V_1 * V_2 , unsigned int V_280 ,
char * V_281 )
{
char * V_278 = 4 + V_273 + ( char * ) V_2 ;
int V_35 ;
if ( ! V_281 )
return - V_174 ;
V_35 = F_55 ( V_273 , V_274 , V_2 , V_280 ) ;
if ( V_35 )
return V_35 ;
memcpy ( V_281 , V_278 , V_274 ) ;
return 0 ;
}
static int
F_57 ( const unsigned int V_82 , struct V_4 * V_5 ,
V_202 V_229 , V_202 V_230 , T_6 V_282 ,
T_9 V_283 , T_9 V_284 , void * V_281 )
{
struct V_285 * V_84 ;
struct V_286 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_35 = 0 ;
int V_78 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
F_7 ( 1 , L_41 ) ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_48 ;
V_35 = F_18 ( V_69 , V_5 , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
V_84 -> V_287 = V_288 ;
V_84 -> V_289 = V_282 ;
V_84 -> V_259 = V_229 ;
V_84 -> V_260 = V_230 ;
V_84 -> V_290 =
F_4 ( sizeof( struct V_285 ) - 1 - 4 ) ;
V_84 -> V_291 = F_5 ( V_283 ) ;
V_87 [ 0 ] . V_112 = ( char * ) V_84 ;
V_87 [ 0 ] . V_113 = F_27 ( V_84 ) + 4 ;
V_35 = F_28 ( V_82 , V_22 , V_87 , 1 , & V_78 , 0 ) ;
V_79 = (struct V_286 * ) V_87 [ 0 ] . V_112 ;
if ( V_35 ) {
F_44 ( V_5 , V_292 ) ;
goto V_293;
}
V_35 = F_56 ( F_2 ( V_79 -> V_294 ) ,
F_30 ( V_79 -> V_291 ) ,
& V_79 -> V_2 , V_284 , V_281 ) ;
V_293:
F_22 ( V_78 , V_79 ) ;
return V_35 ;
}
int
F_58 ( const unsigned int V_82 , struct V_4 * V_5 ,
V_202 V_229 , V_202 V_230 ,
struct V_235 * V_281 )
{
return F_57 ( V_82 , V_5 , V_229 , V_230 ,
V_295 ,
sizeof( struct V_235 ) + V_296 * 2 ,
sizeof( struct V_235 ) , V_281 ) ;
}
int
F_59 ( const unsigned int V_82 , struct V_4 * V_5 ,
V_202 V_229 , V_202 V_230 , T_10 * V_297 )
{
return F_57 ( V_82 , V_5 , V_229 , V_230 ,
V_298 ,
sizeof( struct V_299 ) ,
sizeof( struct V_299 ) , V_297 ) ;
}
static void
F_60 ( struct V_300 * V_301 )
{
struct V_39 * V_29 = V_301 -> V_302 ;
struct V_303 * V_304 = (struct V_303 * ) V_301 -> V_305 ;
unsigned int V_306 = 1 ;
if ( V_301 -> V_307 == V_308 )
V_306 = F_2 ( V_304 -> V_2 . V_15 ) ;
F_61 ( V_301 ) ;
F_62 ( V_29 , V_306 , V_309 ) ;
}
int
F_63 ( struct V_39 * V_29 )
{
struct V_310 * V_84 ;
int V_35 = 0 ;
struct V_86 V_87 ;
struct V_311 V_312 = { . V_313 = & V_87 ,
. V_314 = 1 } ;
F_7 ( 1 , L_42 ) ;
V_35 = F_18 ( V_315 , NULL , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
V_84 -> V_2 . V_15 = F_4 ( 1 ) ;
V_87 . V_112 = ( char * ) V_84 ;
V_87 . V_113 = F_27 ( V_84 ) + 4 ;
V_35 = F_64 ( V_29 , & V_312 , NULL , F_60 , V_29 ,
V_309 ) ;
if ( V_35 )
F_7 ( 1 , L_43 , V_35 ) ;
F_23 ( V_84 ) ;
return V_35 ;
}
int
F_65 ( const unsigned int V_82 , struct V_4 * V_5 , V_202 V_229 ,
V_202 V_230 )
{
struct V_316 * V_84 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
struct V_86 V_87 [ 1 ] ;
int V_78 ;
int V_35 = 0 ;
F_7 ( 1 , L_44 ) ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_48 ;
V_35 = F_18 ( V_63 , V_5 , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
V_84 -> V_259 = V_229 ;
V_84 -> V_260 = V_230 ;
V_87 [ 0 ] . V_112 = ( char * ) V_84 ;
V_87 [ 0 ] . V_113 = F_27 ( V_84 ) + 4 ;
V_35 = F_28 ( V_82 , V_22 , V_87 , 1 , & V_78 , 0 ) ;
if ( ( V_35 != 0 ) && V_5 )
F_44 ( V_5 , V_317 ) ;
F_22 ( V_78 , V_87 [ 0 ] . V_112 ) ;
return V_35 ;
}
static int
F_66 ( struct V_86 * V_87 , struct V_318 * V_319 ,
unsigned int V_320 , int V_321 )
{
int V_35 = - V_322 ;
struct V_323 * V_84 = NULL ;
V_35 = F_18 ( V_64 , V_319 -> V_5 , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
if ( V_319 -> V_5 -> V_22 -> V_29 == NULL )
return - V_324 ;
V_84 -> V_2 . V_16 = F_5 ( V_319 -> V_325 ) ;
V_84 -> V_259 = V_319 -> V_229 ;
V_84 -> V_260 = V_319 -> V_230 ;
V_84 -> V_326 = 0 ;
V_84 -> V_327 = 0 ;
V_84 -> V_149 = 0 ;
V_84 -> V_328 = 0 ;
V_84 -> V_329 = F_5 ( V_319 -> V_330 ) ;
V_84 -> V_331 = F_48 ( V_319 -> V_273 ) ;
if ( V_321 & V_332 ) {
if ( ! ( V_321 & V_333 ) ) {
V_84 -> V_2 . V_334 =
F_5 ( F_27 ( V_84 ) + 4 ) ;
} else
V_84 -> V_2 . V_334 = 0 ;
if ( V_321 & V_335 ) {
V_84 -> V_2 . V_27 |= V_336 ;
V_84 -> V_2 . V_23 = 0xFFFFFFFF ;
V_84 -> V_2 . V_20 = 0xFFFFFFFF ;
V_84 -> V_259 = 0xFFFFFFFF ;
V_84 -> V_260 = 0xFFFFFFFF ;
}
}
if ( V_320 > V_319 -> V_330 )
V_84 -> V_337 = F_5 ( V_320 ) ;
else
V_84 -> V_337 = 0 ;
V_87 [ 0 ] . V_112 = ( char * ) V_84 ;
V_87 [ 0 ] . V_113 = F_27 ( V_84 ) + 4 ;
return V_35 ;
}
static void
F_67 ( struct V_300 * V_301 )
{
struct V_338 * V_339 = V_301 -> V_302 ;
struct V_4 * V_5 = F_68 ( V_339 -> V_340 -> V_341 ) ;
struct V_39 * V_29 = V_5 -> V_22 -> V_29 ;
struct V_1 * V_199 = (struct V_1 * ) V_339 -> V_87 . V_112 ;
unsigned int V_306 = 1 ;
struct V_311 V_312 = { . V_313 = & V_339 -> V_87 ,
. V_314 = 1 ,
. V_342 = V_339 -> V_343 ,
. V_344 = V_339 -> V_345 ,
. V_346 = V_339 -> V_347 ,
. V_348 = V_339 -> V_349 } ;
F_7 ( 1 , L_45 , V_350 ,
V_301 -> V_301 , V_301 -> V_307 , V_339 -> V_351 , V_339 -> V_352 ) ;
switch ( V_301 -> V_307 ) {
case V_308 :
V_306 = F_2 ( V_199 -> V_15 ) ;
if ( V_29 -> V_30 &
( V_31 | V_130 ) ) {
int V_35 ;
V_35 = F_69 ( & V_312 , V_29 ) ;
if ( V_35 )
F_29 ( 1 , L_46
L_47 , V_35 ) ;
}
F_70 ( V_339 -> V_352 ) ;
F_71 ( V_5 , V_339 -> V_352 ) ;
break;
case V_353 :
case V_354 :
V_339 -> V_351 = - V_54 ;
break;
default:
if ( V_339 -> V_351 != - V_355 )
V_339 -> V_351 = - V_48 ;
}
if ( V_339 -> V_351 )
F_44 ( V_5 , V_356 ) ;
F_72 ( V_357 , & V_339 -> V_358 ) ;
F_61 ( V_301 ) ;
F_62 ( V_29 , V_306 , 0 ) ;
}
int
F_73 ( struct V_338 * V_339 )
{
int V_35 ;
struct V_1 * V_199 ;
struct V_318 V_319 ;
struct V_311 V_312 = { . V_313 = & V_339 -> V_87 ,
. V_314 = 1 } ;
F_7 ( 1 , L_48 , V_350 ,
V_339 -> V_273 , V_339 -> V_352 ) ;
V_319 . V_5 = F_68 ( V_339 -> V_340 -> V_341 ) ;
V_319 . V_273 = V_339 -> V_273 ;
V_319 . V_330 = V_339 -> V_352 ;
V_319 . V_229 = V_339 -> V_340 -> V_359 . V_229 ;
V_319 . V_230 = V_339 -> V_340 -> V_359 . V_230 ;
V_319 . V_325 = V_339 -> V_325 ;
V_35 = F_66 ( & V_339 -> V_87 , & V_319 , 0 , 0 ) ;
if ( V_35 )
return V_35 ;
V_199 = (struct V_1 * ) V_339 -> V_87 . V_112 ;
V_339 -> V_87 . V_113 = F_27 ( V_339 -> V_87 . V_112 ) + 4 ;
F_74 ( & V_339 -> V_360 ) ;
V_35 = F_64 ( V_319 . V_5 -> V_22 -> V_29 , & V_312 ,
V_361 , F_67 ,
V_339 , 0 ) ;
if ( V_35 ) {
F_75 ( & V_339 -> V_360 , V_362 ) ;
F_44 ( V_319 . V_5 , V_356 ) ;
}
F_23 ( V_199 ) ;
return V_35 ;
}
int
F_76 ( const unsigned int V_82 , struct V_318 * V_319 ,
unsigned int * V_363 , char * * V_199 , int * V_364 )
{
int V_78 , V_35 = - V_322 ;
struct V_365 * V_79 = NULL ;
struct V_86 V_87 [ 1 ] ;
* V_363 = 0 ;
V_35 = F_66 ( V_87 , V_319 , 0 , 0 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_28 ( V_82 , V_319 -> V_5 -> V_22 , V_87 , 1 ,
& V_78 , V_154 ) ;
V_79 = (struct V_365 * ) V_87 [ 0 ] . V_112 ;
if ( V_79 -> V_2 . V_156 == V_366 ) {
F_22 ( V_78 , V_87 [ 0 ] . V_112 ) ;
return 0 ;
}
if ( V_35 ) {
F_44 ( V_319 -> V_5 , V_356 ) ;
F_29 ( 1 , L_49 , V_35 ) ;
} else {
* V_363 = F_30 ( V_79 -> V_213 ) ;
if ( ( * V_363 > V_367 ) ||
( * V_363 > V_319 -> V_330 ) ) {
F_7 ( 1 , L_50 , * V_363 ,
V_319 -> V_330 ) ;
V_35 = - V_48 ;
* V_363 = 0 ;
}
}
if ( * V_199 ) {
memcpy ( * V_199 , ( char * ) V_79 -> V_2 . V_12 + V_79 -> V_212 ,
* V_363 ) ;
F_22 ( V_78 , V_87 [ 0 ] . V_112 ) ;
} else if ( V_78 != V_155 ) {
* V_199 = V_87 [ 0 ] . V_112 ;
if ( V_78 == V_80 )
* V_364 = V_80 ;
else if ( V_78 == V_81 )
* V_364 = V_81 ;
}
return V_35 ;
}
static void
F_77 ( struct V_300 * V_301 )
{
struct V_368 * V_369 = V_301 -> V_302 ;
struct V_4 * V_5 = F_68 ( V_369 -> V_340 -> V_341 ) ;
unsigned int V_370 ;
struct V_371 * V_79 = (struct V_371 * ) V_301 -> V_305 ;
unsigned int V_306 = 1 ;
switch ( V_301 -> V_307 ) {
case V_308 :
V_306 = F_2 ( V_79 -> V_2 . V_15 ) ;
V_369 -> V_351 = F_78 ( V_301 , V_5 -> V_22 -> V_29 , 0 ) ;
if ( V_369 -> V_351 != 0 )
break;
V_370 = F_30 ( V_79 -> V_213 ) ;
if ( V_370 > V_369 -> V_352 )
V_370 &= 0xFFFF ;
if ( V_370 < V_369 -> V_352 )
V_369 -> V_351 = - V_372 ;
else
V_369 -> V_352 = V_370 ;
break;
case V_353 :
case V_354 :
V_369 -> V_351 = - V_54 ;
break;
default:
V_369 -> V_351 = - V_48 ;
break;
}
if ( V_369 -> V_351 )
F_44 ( V_5 , V_373 ) ;
F_72 ( V_357 , & V_369 -> V_358 ) ;
F_61 ( V_301 ) ;
F_62 ( V_5 -> V_22 -> V_29 , V_306 , 0 ) ;
}
int
F_79 ( struct V_368 * V_369 )
{
int V_35 = - V_322 ;
struct V_374 * V_84 = NULL ;
struct V_4 * V_5 = F_68 ( V_369 -> V_340 -> V_341 ) ;
struct V_86 V_87 ;
struct V_311 V_312 ;
V_35 = F_18 ( V_43 , V_5 , ( void * * ) & V_84 ) ;
if ( V_35 )
goto V_375;
V_84 -> V_2 . V_16 = F_5 ( V_369 -> V_340 -> V_325 ) ;
V_84 -> V_259 = V_369 -> V_340 -> V_359 . V_229 ;
V_84 -> V_260 = V_369 -> V_340 -> V_359 . V_230 ;
V_84 -> V_376 = 0 ;
V_84 -> V_377 = 0 ;
V_84 -> V_149 = 0 ;
V_84 -> V_331 = F_48 ( V_369 -> V_273 ) ;
V_84 -> V_212 = F_4 (
F_40 ( struct V_374 , V_158 ) - 4 ) ;
V_84 -> V_337 = 0 ;
V_87 . V_113 = F_27 ( V_84 ) + 4 - 1 ;
V_87 . V_112 = V_84 ;
V_312 . V_313 = & V_87 ;
V_312 . V_314 = 1 ;
V_312 . V_342 = V_369 -> V_343 ;
V_312 . V_344 = V_369 -> V_345 ;
V_312 . V_346 = V_369 -> V_347 ;
V_312 . V_348 = V_369 -> V_349 ;
F_7 ( 1 , L_51 , V_369 -> V_273 , V_369 -> V_352 ) ;
V_84 -> V_329 = F_5 ( V_369 -> V_352 ) ;
F_26 ( & V_84 -> V_2 , V_369 -> V_352 - 1 ) ;
F_74 ( & V_369 -> V_360 ) ;
V_35 = F_64 ( V_5 -> V_22 -> V_29 , & V_312 , NULL ,
F_77 , V_369 , 0 ) ;
if ( V_35 ) {
F_75 ( & V_369 -> V_360 , V_378 ) ;
F_44 ( V_5 , V_373 ) ;
}
V_375:
F_23 ( V_84 ) ;
return V_35 ;
}
int
F_80 ( const unsigned int V_82 , struct V_318 * V_319 ,
unsigned int * V_363 , struct V_86 * V_87 , int V_379 )
{
int V_35 = 0 ;
struct V_374 * V_84 = NULL ;
struct V_371 * V_79 = NULL ;
int V_78 ;
* V_363 = 0 ;
if ( V_379 < 1 )
return V_35 ;
V_35 = F_18 ( V_43 , V_319 -> V_5 , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
if ( V_319 -> V_5 -> V_22 -> V_29 == NULL )
return - V_324 ;
V_84 -> V_2 . V_16 = F_5 ( V_319 -> V_325 ) ;
V_84 -> V_259 = V_319 -> V_229 ;
V_84 -> V_260 = V_319 -> V_230 ;
V_84 -> V_376 = 0 ;
V_84 -> V_377 = 0 ;
V_84 -> V_149 = 0 ;
V_84 -> V_329 = F_5 ( V_319 -> V_330 ) ;
V_84 -> V_331 = F_48 ( V_319 -> V_273 ) ;
V_84 -> V_212 = F_4 (
F_40 ( struct V_374 , V_158 ) - 4 ) ;
V_84 -> V_337 = 0 ;
V_87 [ 0 ] . V_112 = ( char * ) V_84 ;
V_87 [ 0 ] . V_113 = F_27 ( V_84 ) + 4 - 1 ;
F_26 ( V_84 , V_319 -> V_330 - 1 ) ;
V_35 = F_28 ( V_82 , V_319 -> V_5 -> V_22 , V_87 , V_379 + 1 ,
& V_78 , 0 ) ;
V_79 = (struct V_371 * ) V_87 [ 0 ] . V_112 ;
if ( V_35 ) {
F_44 ( V_319 -> V_5 , V_373 ) ;
F_29 ( 1 , L_52 , V_35 ) ;
} else
* V_363 = F_30 ( V_79 -> V_213 ) ;
F_22 ( V_78 , V_79 ) ;
return V_35 ;
}
static unsigned int
F_81 ( char * V_380 , char * V_279 , char * * V_381 , T_9 V_382 )
{
int V_383 ;
unsigned int V_384 = 0 ;
unsigned int V_385 = 0 ;
T_11 * V_386 ;
if ( V_380 == NULL )
return 0 ;
V_386 = ( T_11 * ) V_380 ;
while ( 1 ) {
V_386 = ( T_11 * )
( ( char * ) V_386 + V_385 ) ;
if ( ( char * ) V_386 + V_382 > V_279 ) {
F_29 ( 1 , L_53 ) ;
break;
}
V_383 = F_30 ( V_386 -> V_387 ) ;
if ( ( char * ) V_386 + V_383 + V_382 > V_279 ) {
F_29 ( 1 , L_54
L_55 , V_279 ) ;
break;
}
* V_381 = ( char * ) V_386 ;
V_384 ++ ;
V_385 = F_30 ( V_386 -> V_388 ) ;
if ( ! V_385 )
break;
}
return V_384 ;
}
int
F_82 ( const unsigned int V_82 , struct V_4 * V_5 ,
V_202 V_229 , V_202 V_230 , int V_389 ,
struct V_390 * V_391 )
{
struct V_392 * V_84 ;
struct V_393 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_35 = 0 ;
int V_383 ;
int V_78 ;
unsigned char * V_394 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
T_1 V_395 = F_4 ( '*' ) ;
char * V_277 ;
unsigned int V_396 = V_397 ;
T_9 V_398 ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_48 ;
V_35 = F_18 ( V_67 , V_5 , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
switch ( V_391 -> V_399 ) {
case V_400 :
V_84 -> V_401 = V_402 ;
V_398 = sizeof( T_11 ) - 1 ;
break;
case V_403 :
V_84 -> V_401 = V_404 ;
V_398 = sizeof( V_405 ) - 1 ;
break;
default:
F_29 ( 1 , L_56 ,
V_391 -> V_399 ) ;
V_35 = - V_174 ;
goto V_406;
}
V_84 -> V_407 = F_5 ( V_389 ) ;
V_84 -> V_259 = V_229 ;
V_84 -> V_260 = V_230 ;
V_383 = 0x2 ;
V_394 = V_84 -> V_158 ;
memcpy ( V_394 , & V_395 , V_383 ) ;
V_84 -> V_408 =
F_4 ( sizeof( struct V_392 ) - 1 - 4 ) ;
V_84 -> V_387 = F_4 ( V_383 ) ;
V_396 = F_83 (unsigned int, output_size, server->maxBuf) ;
V_396 = F_83 (unsigned int, output_size, 2 << 15 ) ;
V_84 -> V_291 = F_5 ( V_396 ) ;
V_87 [ 0 ] . V_112 = ( char * ) V_84 ;
V_87 [ 0 ] . V_113 = F_27 ( V_84 ) + 4 - 1 ;
V_87 [ 1 ] . V_112 = ( char * ) ( V_84 -> V_158 ) ;
V_87 [ 1 ] . V_113 = V_383 ;
F_26 ( V_84 , V_383 - 1 ) ;
V_35 = F_28 ( V_82 , V_22 , V_87 , 2 , & V_78 , 0 ) ;
V_79 = (struct V_393 * ) V_87 [ 0 ] . V_112 ;
if ( V_35 ) {
F_44 ( V_5 , V_409 ) ;
goto V_406;
}
V_35 = F_55 ( F_2 ( V_79 -> V_294 ) ,
F_30 ( V_79 -> V_291 ) , & V_79 -> V_2 ,
V_398 ) ;
if ( V_35 )
goto V_406;
V_391 -> V_410 = true ;
if ( V_391 -> V_411 ) {
if ( V_391 -> V_412 )
F_23 ( V_391 -> V_411 ) ;
else
F_24 ( V_391 -> V_411 ) ;
}
V_391 -> V_411 = ( char * ) V_79 ;
V_391 -> V_413 = V_391 -> V_414 = 4 +
( char * ) & V_79 -> V_2 + F_2 ( V_79 -> V_294 ) ;
V_277 = F_27 ( V_79 ) + 4 + ( char * ) & V_79 -> V_2 ;
V_391 -> V_415 =
F_81 ( V_391 -> V_413 , V_277 ,
& V_391 -> V_414 , V_398 ) ;
V_391 -> V_416 += V_391 -> V_415 ;
F_7 ( 1 , L_57 ,
V_391 -> V_415 , V_391 -> V_416 ,
V_391 -> V_413 , V_391 -> V_414 ) ;
if ( V_78 == V_81 )
V_391 -> V_412 = false ;
else if ( V_78 == V_80 )
V_391 -> V_412 = true ;
else
F_29 ( 1 , L_58 ) ;
if ( V_79 -> V_2 . V_156 == V_417 )
V_391 -> V_418 = 1 ;
else
V_391 -> V_418 = 0 ;
return V_35 ;
V_406:
F_22 ( V_78 , V_79 ) ;
return V_35 ;
}
static int
F_84 ( const unsigned int V_82 , struct V_4 * V_5 ,
V_202 V_229 , V_202 V_230 , T_12 V_325 , int V_282 ,
unsigned int V_419 , void * * V_281 , unsigned int * V_382 )
{
struct V_420 * V_84 ;
struct V_421 * V_79 = NULL ;
struct V_86 * V_87 ;
int V_35 = 0 ;
int V_78 ;
unsigned int V_422 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_48 ;
if ( ! V_419 )
return - V_174 ;
V_87 = F_35 ( sizeof( struct V_86 ) * V_419 , V_141 ) ;
if ( ! V_87 )
return - V_72 ;
V_35 = F_18 ( V_70 , V_5 , ( void * * ) & V_84 ) ;
if ( V_35 ) {
F_37 ( V_87 ) ;
return V_35 ;
}
V_84 -> V_2 . V_16 = F_5 ( V_325 ) ;
V_84 -> V_287 = V_288 ;
V_84 -> V_289 = V_282 ;
V_84 -> V_259 = V_229 ;
V_84 -> V_260 = V_230 ;
V_84 -> V_423 =
F_4 ( sizeof( struct V_420 ) - 1 - 4 ) ;
V_84 -> V_424 = F_5 ( * V_382 ) ;
F_26 ( V_84 , * V_382 - 1 ) ;
memcpy ( V_84 -> V_158 , * V_281 , * V_382 ) ;
V_87 [ 0 ] . V_112 = ( char * ) V_84 ;
V_87 [ 0 ] . V_113 = F_27 ( V_84 ) + 4 ;
for ( V_422 = 1 ; V_422 < V_419 ; V_422 ++ ) {
F_26 ( V_84 , V_382 [ V_422 ] ) ;
F_85 ( & V_84 -> V_424 , V_382 [ V_422 ] ) ;
V_87 [ V_422 ] . V_112 = ( char * ) V_281 [ V_422 ] ;
V_87 [ V_422 ] . V_113 = V_382 [ V_422 ] ;
}
V_35 = F_28 ( V_82 , V_22 , V_87 , V_419 , & V_78 , 0 ) ;
V_79 = (struct V_421 * ) V_87 [ 0 ] . V_112 ;
if ( V_35 != 0 ) {
F_44 ( V_5 , V_425 ) ;
goto V_19;
}
V_19:
F_22 ( V_78 , V_79 ) ;
F_37 ( V_87 ) ;
return V_35 ;
}
int
F_86 ( const unsigned int V_82 , struct V_4 * V_5 ,
V_202 V_229 , V_202 V_230 , T_1 * V_426 )
{
struct V_427 V_428 ;
void * * V_281 ;
unsigned int V_382 [ 2 ] ;
int V_35 ;
int V_383 = ( 2 * F_52 ( ( V_249 * ) V_426 , V_250 ) ) ;
V_281 = F_35 ( sizeof( void * ) * 2 , V_141 ) ;
if ( ! V_281 )
return - V_72 ;
V_428 . V_429 = 1 ;
V_428 . V_430 = 0 ;
V_428 . V_387 = F_5 ( V_383 ) ;
V_281 [ 0 ] = & V_428 ;
V_382 [ 0 ] = sizeof( struct V_427 ) ;
V_281 [ 1 ] = V_426 ;
V_382 [ 1 ] = V_383 + 2 ;
V_35 = F_84 ( V_82 , V_5 , V_229 , V_230 ,
V_17 -> V_18 , V_431 , 2 , V_281 ,
V_382 ) ;
F_37 ( V_281 ) ;
return V_35 ;
}
int
F_87 ( const unsigned int V_82 , struct V_4 * V_5 ,
V_202 V_229 , V_202 V_230 , T_1 * V_426 )
{
struct V_432 V_428 ;
void * * V_281 ;
unsigned int V_382 [ 2 ] ;
int V_35 ;
int V_383 = ( 2 * F_52 ( ( V_249 * ) V_426 , V_250 ) ) ;
V_281 = F_35 ( sizeof( void * ) * 2 , V_141 ) ;
if ( ! V_281 )
return - V_72 ;
V_428 . V_429 = 0 ;
V_428 . V_430 = 0 ;
V_428 . V_387 = F_5 ( V_383 ) ;
V_281 [ 0 ] = & V_428 ;
V_382 [ 0 ] = sizeof( struct V_432 ) ;
V_281 [ 1 ] = V_426 ;
V_382 [ 1 ] = V_383 + 2 ;
V_35 = F_84 ( V_82 , V_5 , V_229 , V_230 ,
V_17 -> V_18 , V_433 , 2 , V_281 , V_382 ) ;
F_37 ( V_281 ) ;
return V_35 ;
}
int
F_88 ( const unsigned int V_82 , struct V_4 * V_5 , V_202 V_229 ,
V_202 V_230 , T_12 V_325 , T_10 * V_434 )
{
struct V_435 V_428 ;
void * V_281 ;
unsigned int V_382 ;
V_428 . V_263 = * V_434 ;
V_281 = & V_428 ;
V_382 = sizeof( struct V_435 ) ;
return F_84 ( V_82 , V_5 , V_229 , V_230 , V_325 ,
V_436 , 1 , & V_281 , & V_382 ) ;
}
int
F_89 ( const unsigned int V_82 , struct V_4 * V_5 ,
V_202 V_229 , V_202 V_230 , T_13 * V_199 )
{
unsigned int V_382 ;
V_382 = sizeof( T_13 ) ;
return F_84 ( V_82 , V_5 , V_229 , V_230 ,
V_17 -> V_18 , V_437 , 1 ,
( void * * ) & V_199 , & V_382 ) ;
}
int
F_90 ( const unsigned int V_82 , struct V_4 * V_5 ,
const V_202 V_229 , const V_202 V_230 ,
T_7 V_438 )
{
int V_35 ;
struct V_439 * V_84 = NULL ;
F_7 ( 1 , L_59 ) ;
V_35 = F_18 ( V_53 , V_5 , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
V_84 -> V_440 = V_230 ;
V_84 -> V_441 = V_229 ;
V_84 -> V_268 = V_438 ;
V_84 -> V_2 . V_15 = F_4 ( 1 ) ;
V_35 = F_43 ( V_82 , V_5 -> V_22 , ( char * ) V_84 , V_442 ) ;
if ( V_35 ) {
F_44 ( V_5 , V_443 ) ;
F_7 ( 1 , L_60 , V_35 ) ;
}
return V_35 ;
}
static void
F_91 ( struct V_444 * V_445 ,
struct V_446 * V_447 )
{
V_447 -> V_448 = F_30 ( V_445 -> V_449 ) *
F_30 ( V_445 -> V_450 ) ;
V_447 -> V_451 = F_92 ( V_445 -> V_452 ) ;
V_447 -> V_453 = F_92 ( V_445 -> V_454 ) ;
V_447 -> V_455 = F_92 ( V_445 -> V_456 ) ;
return;
}
static int
F_93 ( struct V_86 * V_87 , struct V_4 * V_5 , int V_457 ,
int V_458 , V_202 V_229 , V_202 V_230 )
{
int V_35 ;
struct V_285 * V_84 ;
F_7 ( 1 , L_61 , V_457 ) ;
if ( ( V_5 -> V_22 == NULL ) || ( V_5 -> V_22 -> V_29 == NULL ) )
return - V_48 ;
V_35 = F_18 ( V_69 , V_5 , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
V_84 -> V_287 = V_459 ;
V_84 -> V_289 = V_457 ;
V_84 -> V_259 = V_229 ;
V_84 -> V_260 = V_230 ;
V_84 -> V_290 =
F_4 ( sizeof( struct V_285 ) - 1 - 4 ) ;
V_84 -> V_291 = F_5 (
V_458 + sizeof( struct V_286 ) - 1 - 4 ) ;
V_87 -> V_112 = ( char * ) V_84 ;
V_87 -> V_113 = F_27 ( V_84 ) + 4 ;
return 0 ;
}
int
F_94 ( const unsigned int V_82 , struct V_4 * V_5 ,
V_202 V_229 , V_202 V_230 , struct V_446 * V_460 )
{
struct V_286 * V_79 = NULL ;
struct V_86 V_87 ;
int V_35 = 0 ;
int V_78 ;
struct V_38 * V_22 = V_5 -> V_22 ;
struct V_444 * V_428 = NULL ;
V_35 = F_93 ( & V_87 , V_5 , V_461 ,
sizeof( struct V_444 ) ,
V_229 , V_230 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_28 ( V_82 , V_22 , & V_87 , 1 , & V_78 , 0 ) ;
if ( V_35 ) {
F_44 ( V_5 , V_292 ) ;
goto V_293;
}
V_79 = (struct V_286 * ) V_87 . V_112 ;
V_428 = (struct V_444 * ) ( 4 +
F_2 ( V_79 -> V_294 ) + ( char * ) & V_79 -> V_2 ) ;
V_35 = F_55 ( F_2 ( V_79 -> V_294 ) ,
F_30 ( V_79 -> V_291 ) , & V_79 -> V_2 ,
sizeof( struct V_444 ) ) ;
if ( ! V_35 )
F_91 ( V_428 , V_460 ) ;
V_293:
F_22 ( V_78 , V_87 . V_112 ) ;
return V_35 ;
}
int
F_95 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_14 V_462 , const T_14 V_230 , const T_8 V_325 ,
const T_8 V_463 , struct V_464 * V_199 )
{
int V_35 = 0 ;
struct V_465 * V_84 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_466 ;
unsigned int V_467 ;
F_7 ( 1 , L_62 , V_463 ) ;
V_35 = F_18 ( V_65 , V_5 , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
V_84 -> V_2 . V_16 = F_5 ( V_325 ) ;
V_84 -> V_468 = F_4 ( V_463 ) ;
V_84 -> V_259 = V_462 ;
V_84 -> V_260 = V_230 ;
V_467 = V_463 * sizeof( struct V_464 ) ;
F_26 ( V_84 , V_467 - sizeof( struct V_464 ) ) ;
V_87 [ 0 ] . V_112 = ( char * ) V_84 ;
V_87 [ 0 ] . V_113 = F_27 ( V_84 ) + 4 - V_467 ;
V_87 [ 1 ] . V_112 = ( char * ) V_199 ;
V_87 [ 1 ] . V_113 = V_467 ;
F_21 ( & V_5 -> V_74 . V_469 . V_470 ) ;
V_35 = F_28 ( V_82 , V_5 -> V_22 , V_87 , 2 , & V_466 , V_471 ) ;
if ( V_35 ) {
F_7 ( 1 , L_63 , V_35 ) ;
F_44 ( V_5 , V_472 ) ;
}
return V_35 ;
}
int
F_96 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_14 V_462 , const T_14 V_230 , const T_8 V_325 ,
const T_14 V_330 , const T_14 V_273 , const T_8 V_473 ,
const bool V_474 )
{
struct V_464 V_475 ;
V_475 . V_331 = F_48 ( V_273 ) ;
V_475 . V_329 = F_48 ( V_330 ) ;
V_475 . V_27 = F_5 ( V_473 ) ;
if ( ! V_474 && V_473 != V_476 )
V_475 . V_27 |= F_5 ( V_477 ) ;
return F_95 ( V_82 , V_5 , V_462 , V_230 , V_325 , 1 , & V_475 ) ;
}
int
F_97 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_7 * V_197 , const T_5 V_478 )
{
int V_35 ;
struct V_479 * V_84 = NULL ;
F_7 ( 1 , L_64 ) ;
V_35 = F_18 ( V_53 , V_5 , ( void * * ) & V_84 ) ;
if ( V_35 )
return V_35 ;
V_84 -> V_2 . V_15 = F_4 ( 1 ) ;
V_84 -> V_13 = F_4 ( 36 ) ;
F_26 ( V_84 , 12 ) ;
memcpy ( V_84 -> V_480 , V_197 , 16 ) ;
V_84 -> V_205 = V_478 ;
V_35 = F_43 ( V_82 , V_5 -> V_22 , ( char * ) V_84 , V_442 ) ;
if ( V_35 ) {
F_44 ( V_5 , V_443 ) ;
F_7 ( 1 , L_65 , V_35 ) ;
}
return V_35 ;
}
