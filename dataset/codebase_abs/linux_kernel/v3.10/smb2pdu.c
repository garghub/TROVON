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
F_7 ( V_46 , L_1 ,
V_34 ) ;
return - V_47 ;
}
}
if ( ( ! V_5 -> V_22 ) || ( V_5 -> V_22 -> V_48 == V_42 ) ||
( ! V_5 -> V_22 -> V_29 ) )
return - V_49 ;
V_22 = V_5 -> V_22 ;
V_29 = V_22 -> V_29 ;
while ( V_29 -> V_50 == V_51 ) {
switch ( V_34 ) {
case V_45 :
case V_52 :
case V_53 :
case V_54 :
return - V_55 ;
}
F_8 ( V_29 -> V_56 ,
( V_29 -> V_50 != V_51 ) , 10 * V_57 ) ;
if ( V_29 -> V_50 != V_51 )
break;
if ( ! V_5 -> V_58 ) {
F_7 ( V_46 , L_2 ) ;
return - V_59 ;
}
}
if ( ! V_5 -> V_22 -> V_60 && ! V_5 -> V_60 )
return V_35 ;
V_37 = F_9 () ;
F_10 ( & V_5 -> V_22 -> V_61 ) ;
V_35 = F_11 ( 0 , V_5 -> V_22 ) ;
if ( ! V_35 && V_5 -> V_22 -> V_60 )
V_35 = F_12 ( 0 , V_5 -> V_22 , V_37 ) ;
if ( V_35 || ! V_5 -> V_60 ) {
F_13 ( & V_5 -> V_22 -> V_61 ) ;
goto V_19;
}
F_14 ( V_5 ) ;
V_35 = F_15 ( 0 , V_5 -> V_22 , V_5 -> V_62 , V_5 , V_37 ) ;
F_13 ( & V_5 -> V_22 -> V_61 ) ;
F_7 ( V_46 , L_3 , V_35 ) ;
if ( V_35 )
goto V_19;
F_16 ( & V_63 ) ;
V_19:
switch ( V_34 ) {
case V_64 :
case V_65 :
case V_43 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
return - V_55 ;
}
F_17 ( V_37 ) ;
return V_35 ;
}
static int
F_18 ( T_1 V_34 , struct V_4 * V_5 ,
void * * V_72 )
{
int V_35 = 0 ;
V_35 = F_6 ( V_34 , V_5 ) ;
if ( V_35 )
return V_35 ;
* V_72 = F_19 () ;
if ( * V_72 == NULL ) {
return - V_73 ;
}
F_1 ( (struct V_1 * ) * V_72 , V_34 , V_5 ) ;
if ( V_5 != NULL ) {
#ifdef F_20
T_3 V_74 = F_2 ( V_34 ) ;
F_21 ( & V_5 -> V_75 . V_76 . V_77 [ V_74 ] ) ;
#endif
F_21 ( & V_5 -> V_78 ) ;
}
return V_35 ;
}
static void
F_22 ( int V_79 , void * V_80 )
{
if ( V_79 == V_81 )
F_23 ( V_80 ) ;
else if ( V_79 == V_82 )
F_24 ( V_80 ) ;
}
int
F_25 ( const unsigned int V_83 , struct V_38 * V_22 )
{
struct V_84 * V_85 ;
struct V_86 * V_80 ;
struct V_87 V_88 [ 1 ] ;
int V_35 = 0 ;
int V_79 ;
struct V_39 * V_29 ;
unsigned int V_89 ;
T_4 V_8 = 0 ;
int V_90 , V_91 ;
char * V_92 ;
int V_93 = V_94 ;
F_7 ( V_46 , L_4 ) ;
if ( V_22 -> V_29 )
V_29 = V_22 -> V_29 ;
else {
V_35 = - V_49 ;
return V_35 ;
}
V_35 = F_18 ( V_95 , NULL , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
if ( V_22 -> V_96 & ( ~ ( V_97 | V_98 ) ) )
V_89 = V_22 -> V_96 ;
else
V_89 = V_99 | V_22 -> V_96 ;
F_7 ( V_46 , L_5 , V_89 ) ;
V_85 -> V_2 . V_23 = 0 ;
V_85 -> V_100 [ 0 ] = F_4 ( V_22 -> V_29 -> V_101 -> V_102 ) ;
V_85 -> V_103 = F_4 ( 1 ) ;
F_26 ( V_85 , 2 ) ;
if ( ( V_89 & V_97 ) == V_97 )
V_8 = V_104 ;
else if ( V_89 & V_105 )
V_8 = V_106 ;
V_85 -> V_107 = F_4 ( V_8 ) ;
V_85 -> V_108 = F_5 ( V_22 -> V_29 -> V_101 -> V_109 ) ;
memcpy ( V_85 -> V_110 , V_111 , V_112 ) ;
V_88 [ 0 ] . V_113 = ( char * ) V_85 ;
V_88 [ 0 ] . V_114 = F_27 ( V_85 ) + 4 ;
V_35 = F_28 ( V_83 , V_22 , V_88 , 1 , & V_79 , V_93 ) ;
V_80 = (struct V_86 * ) V_88 [ 0 ] . V_113 ;
if ( V_35 != 0 )
goto V_115;
F_7 ( V_46 , L_6 , V_80 -> V_107 ) ;
if ( V_80 -> V_116 == F_4 ( V_117 ) )
F_7 ( V_46 , L_7 ) ;
else if ( V_80 -> V_116 == F_4 ( V_118 ) )
F_7 ( V_46 , L_8 ) ;
else if ( V_80 -> V_116 == F_4 ( V_119 ) )
F_7 ( V_46 , L_9 ) ;
else {
F_7 ( V_120 , L_10 ,
F_2 ( V_80 -> V_116 ) ) ;
V_35 = - V_49 ;
goto V_115;
}
V_29 -> V_121 = F_2 ( V_80 -> V_116 ) ;
V_29 -> V_122 = F_29 ( V_80 -> V_123 ) ;
V_29 -> V_124 = F_29 ( V_80 -> V_125 ) ;
V_29 -> V_126 = F_29 ( V_80 -> V_127 ) ;
V_29 -> V_30 = F_2 ( V_80 -> V_107 ) ;
V_29 -> V_128 = F_29 ( V_80 -> V_108 ) ;
V_29 -> V_128 |= V_129 | V_130 ;
V_92 = F_30 ( & V_90 , & V_91 ,
& V_80 -> V_2 ) ;
if ( V_91 == 0 ) {
F_7 ( V_120 , L_11 ) ;
V_35 = - V_49 ;
goto V_115;
}
F_7 ( V_46 , L_5 , V_89 ) ;
if ( ( V_89 & V_97 ) == V_97 ) {
F_7 ( V_46 , L_12 ) ;
if ( ! ( V_29 -> V_30 & ( V_104 |
V_106 ) ) ) {
F_7 ( V_120 , L_13 ) ;
V_35 = - V_131 ;
goto V_115;
}
V_29 -> V_30 |= V_31 ;
} else if ( V_89 & V_105 ) {
F_7 ( V_46 , L_14 ) ;
if ( V_29 -> V_30 & V_104 ) {
F_7 ( V_46 , L_15 ) ;
V_29 -> V_30 |= V_31 ;
} else {
V_29 -> V_30 &=
~ ( V_132 | V_31 ) ;
}
} else {
F_7 ( V_46 , L_16 ) ;
if ( V_29 -> V_30 & V_104 ) {
F_7 ( V_120 , L_17 ) ;
V_35 = - V_131 ;
goto V_115;
}
V_29 -> V_30 &=
~ ( V_132 | V_31 ) ;
}
#ifdef F_31
V_35 = F_32 ( V_92 , V_91 ,
& V_29 -> V_133 ) ;
if ( V_35 == 1 )
V_35 = 0 ;
else if ( V_35 == 0 ) {
V_35 = - V_49 ;
goto V_115;
}
#endif
V_115:
F_22 ( V_79 , V_80 ) ;
return V_35 ;
}
int
F_33 ( const unsigned int V_83 , struct V_38 * V_22 ,
const struct V_36 * V_134 )
{
struct V_135 * V_85 ;
struct V_136 * V_80 = NULL ;
struct V_87 V_88 [ 2 ] ;
int V_35 = 0 ;
int V_79 ;
T_5 V_137 = V_138 ;
struct V_39 * V_29 ;
unsigned int V_89 ;
T_6 V_8 = 0 ;
T_4 V_91 = 0 ;
char * V_92 ;
char * V_139 = NULL ;
bool V_140 = false ;
F_7 ( V_46 , L_18 ) ;
if ( V_22 -> V_29 )
V_29 = V_22 -> V_29 ;
else {
V_35 = - V_49 ;
return V_35 ;
}
V_22 -> V_141 = F_34 ( sizeof( struct V_142 ) , V_143 ) ;
if ( ! V_22 -> V_141 )
return - V_73 ;
V_22 -> V_29 -> V_144 = V_145 ;
V_146:
if ( V_137 == V_147 )
V_137 = V_148 ;
V_35 = F_18 ( V_149 , NULL , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
if ( V_22 -> V_96 & ( ~ ( V_97 | V_98 ) ) )
V_89 = V_22 -> V_96 ;
else
V_89 = V_99 | V_22 -> V_96 ;
F_7 ( V_46 , L_5 , V_89 ) ;
V_85 -> V_2 . V_23 = 0 ;
V_85 -> V_150 = 0 ;
V_85 -> V_2 . V_15 = F_4 ( 3 ) ;
if ( ( V_89 & V_97 ) == V_97 )
V_8 = V_104 ;
else if ( V_22 -> V_29 -> V_30 & V_104 )
V_8 = V_104 ;
else if ( V_89 & V_105 )
V_8 = V_106 ;
V_85 -> V_107 = V_8 ;
V_85 -> V_108 = 0 ;
V_85 -> V_151 = 0 ;
V_88 [ 0 ] . V_113 = ( char * ) V_85 ;
V_88 [ 0 ] . V_114 = F_27 ( V_85 ) + 4 - 1 ;
if ( V_137 == V_138 ) {
V_139 = F_34 ( sizeof( struct V_152 ) ,
V_143 ) ;
if ( V_139 == NULL ) {
V_35 = - V_73 ;
goto V_153;
}
F_35 ( V_139 , V_22 ) ;
if ( V_140 ) {
F_7 ( V_120 , L_19 ) ;
V_35 = - V_131 ;
F_36 ( V_139 ) ;
goto V_153;
} else {
V_91 = sizeof( struct V_152 ) ;
V_92 = V_139 ;
}
} else if ( V_137 == V_148 ) {
V_85 -> V_2 . V_23 = V_22 -> V_24 ;
V_139 = F_37 ( sizeof( struct V_152 ) + 500 ,
V_143 ) ;
if ( V_139 == NULL ) {
V_35 = - V_73 ;
goto V_153;
}
V_35 = F_38 ( V_139 , & V_91 , V_22 ,
V_134 ) ;
if ( V_35 ) {
F_7 ( V_46 , L_20 ,
V_35 ) ;
goto V_153;
}
if ( V_140 ) {
F_7 ( V_120 , L_19 ) ;
V_35 = - V_131 ;
F_36 ( V_139 ) ;
goto V_153;
} else {
V_92 = V_139 ;
}
} else {
F_7 ( V_120 , L_21 ) ;
V_35 = - V_49 ;
goto V_153;
}
V_85 -> V_154 =
F_4 ( sizeof( struct V_135 ) -
1 - 4 ) ;
V_85 -> V_155 = F_4 ( V_91 ) ;
V_88 [ 1 ] . V_113 = V_92 ;
V_88 [ 1 ] . V_114 = V_91 ;
F_26 ( V_85 , V_91 - 1 ) ;
V_35 = F_28 ( V_83 , V_22 , V_88 , 2 , & V_79 ,
V_156 | V_94 ) ;
F_36 ( V_92 ) ;
V_80 = (struct V_136 * ) V_88 [ 0 ] . V_113 ;
if ( V_79 != V_157 &&
V_80 -> V_2 . V_158 == V_159 ) {
if ( V_137 != V_138 ) {
F_7 ( V_120 , L_22 ) ;
goto V_153;
}
if ( F_39 ( struct V_136 , V_160 ) - 4 !=
F_2 ( V_80 -> V_154 ) ) {
F_7 ( V_120 , L_23 ,
F_2 ( V_80 -> V_154 ) ) ;
V_35 = - V_49 ;
goto V_153;
}
V_137 = V_147 ;
V_35 = 0 ;
V_22 -> V_24 = V_80 -> V_2 . V_23 ;
V_35 = F_40 ( V_80 -> V_160 ,
F_2 ( V_80 -> V_155 ) , V_22 ) ;
}
if ( V_35 != 0 )
goto V_153;
V_22 -> V_161 = F_2 ( V_80 -> V_162 ) ;
V_153:
F_22 ( V_79 , V_80 ) ;
if ( ( V_137 == V_147 ) && ( V_35 == 0 ) )
goto V_146;
return V_35 ;
}
int
F_41 ( const unsigned int V_83 , struct V_38 * V_22 )
{
struct V_163 * V_85 ;
int V_35 = 0 ;
struct V_39 * V_29 ;
F_7 ( V_46 , L_24 , V_22 ) ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_49 ;
V_35 = F_18 ( V_164 , NULL , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
V_85 -> V_2 . V_23 = V_22 -> V_24 ;
if ( V_29 -> V_30 & V_31 )
V_85 -> V_2 . V_27 |= V_32 ;
V_35 = F_42 ( V_83 , V_22 , ( char * ) & V_85 -> V_2 , 0 ) ;
return V_35 ;
}
static inline void F_43 ( struct V_4 * V_5 , T_3 V_165 )
{
F_21 ( & V_5 -> V_75 . V_76 . V_166 [ V_165 ] ) ;
}
int
F_15 ( const unsigned int V_83 , struct V_38 * V_22 , const char * V_167 ,
struct V_4 * V_5 , const struct V_36 * V_168 )
{
struct V_169 * V_85 ;
struct V_170 * V_80 = NULL ;
struct V_87 V_88 [ 2 ] ;
int V_35 = 0 ;
int V_79 ;
int V_171 ;
struct V_39 * V_29 ;
T_1 * V_172 = NULL ;
F_7 ( V_46 , L_25 ) ;
if ( ( V_22 -> V_29 ) && V_167 )
V_29 = V_22 -> V_29 ;
else
return - V_49 ;
if ( V_5 && V_5 -> V_173 )
return - V_174 ;
V_172 = F_34 ( V_175 * 2 , V_143 ) ;
if ( V_172 == NULL )
return - V_73 ;
V_171 = F_44 ( V_172 , V_167 , strlen ( V_167 ) , V_168 ) + 1 ;
V_171 *= 2 ;
if ( V_171 < 2 ) {
F_36 ( V_172 ) ;
return - V_176 ;
}
V_35 = F_18 ( V_40 , V_5 , ( void * * ) & V_85 ) ;
if ( V_35 ) {
F_36 ( V_172 ) ;
return V_35 ;
}
if ( V_5 == NULL ) {
V_85 -> V_2 . V_23 = V_22 -> V_24 ;
}
V_88 [ 0 ] . V_113 = ( char * ) V_85 ;
V_88 [ 0 ] . V_114 = F_27 ( V_85 ) + 4 - 1 ;
V_85 -> V_177 = F_4 ( sizeof( struct V_169 )
- 1 - 4 ) ;
V_85 -> V_178 = F_4 ( V_171 - 2 ) ;
V_88 [ 1 ] . V_113 = V_172 ;
V_88 [ 1 ] . V_114 = V_171 ;
F_26 ( V_85 , V_171 - 1 ) ;
V_35 = F_28 ( V_83 , V_22 , V_88 , 2 , & V_79 , 0 ) ;
V_80 = (struct V_170 * ) V_88 [ 0 ] . V_113 ;
if ( V_35 != 0 ) {
if ( V_5 ) {
F_43 ( V_5 , V_179 ) ;
V_5 -> V_60 = true ;
}
goto V_180;
}
if ( V_5 == NULL ) {
V_22 -> V_181 = V_80 -> V_2 . V_20 ;
goto V_182;
}
if ( V_80 -> V_183 & V_184 )
F_7 ( V_46 , L_26 ) ;
else if ( V_80 -> V_183 & V_185 ) {
V_5 -> V_186 = true ;
F_7 ( V_46 , L_27 ) ;
} else if ( V_80 -> V_183 & V_187 ) {
V_5 -> V_188 = true ;
F_7 ( V_46 , L_28 ) ;
} else {
F_7 ( V_120 , L_29 , V_80 -> V_183 ) ;
V_35 = - V_131 ;
goto V_180;
}
V_5 -> V_25 = F_29 ( V_80 -> V_189 ) ;
V_5 -> V_190 = F_29 ( V_80 -> V_191 ) ;
V_5 -> V_41 = V_192 ;
V_5 -> V_60 = false ;
V_5 -> V_21 = V_80 -> V_2 . V_20 ;
strncpy ( V_5 -> V_62 , V_167 , V_193 ) ;
if ( ( V_80 -> V_108 & V_194 ) &&
( ( V_5 -> V_25 & V_26 ) == 0 ) )
F_7 ( V_120 , L_30 ) ;
V_182:
F_22 ( V_79 , V_80 ) ;
F_36 ( V_172 ) ;
return V_35 ;
V_180:
if ( V_80 -> V_2 . V_158 == V_195 ) {
F_7 ( V_120 , L_31 , V_167 ) ;
V_5 -> V_173 = true ;
}
goto V_182;
}
int
F_45 ( const unsigned int V_83 , struct V_4 * V_5 )
{
struct V_196 * V_85 ;
int V_35 = 0 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
F_7 ( V_46 , L_32 ) ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_49 ;
if ( ( V_5 -> V_60 ) || ( V_5 -> V_22 -> V_60 ) )
return 0 ;
V_35 = F_18 ( V_45 , V_5 , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_42 ( V_83 , V_22 , ( char * ) & V_85 -> V_2 , 0 ) ;
if ( V_35 )
F_43 ( V_5 , V_197 ) ;
return V_35 ;
}
static struct V_198 *
F_46 ( T_6 * V_199 , T_6 V_200 )
{
struct V_198 * V_201 ;
V_201 = F_37 ( sizeof( struct V_198 ) , V_143 ) ;
if ( ! V_201 )
return NULL ;
V_201 -> V_202 . V_203 = F_47 ( * ( ( V_204 * ) V_199 ) ) ;
V_201 -> V_202 . V_205 = F_47 ( * ( ( V_204 * ) ( V_199 + 8 ) ) ) ;
if ( V_200 == V_206 )
V_201 -> V_202 . V_207 = V_208 |
V_209 ;
else if ( V_200 == V_210 )
V_201 -> V_202 . V_207 = V_209 ;
else if ( V_200 == V_211 )
V_201 -> V_202 . V_207 = V_212 |
V_209 |
V_208 ;
V_201 -> V_213 . V_214 = F_4 ( F_39
( struct V_198 , V_202 ) ) ;
V_201 -> V_213 . V_215 = F_5 ( sizeof( struct V_216 ) ) ;
V_201 -> V_213 . V_217 = F_4 ( F_39
( struct V_198 , V_218 ) ) ;
V_201 -> V_213 . V_219 = F_4 ( 4 ) ;
V_201 -> V_218 [ 0 ] = 'R' ;
V_201 -> V_218 [ 1 ] = 'q' ;
V_201 -> V_218 [ 2 ] = 'L' ;
V_201 -> V_218 [ 3 ] = 's' ;
return V_201 ;
}
static T_7
F_48 ( struct V_220 * V_80 )
{
char * V_221 ;
struct V_198 * V_222 ;
bool V_223 = false ;
V_221 = ( char * ) V_80 ;
V_221 += 4 + F_29 ( V_80 -> V_224 ) ;
V_222 = (struct V_198 * ) V_221 ;
do {
char * V_225 = F_2 ( V_222 -> V_213 . V_217 ) + ( char * ) V_222 ;
if ( F_2 ( V_222 -> V_213 . V_219 ) != 4 ||
strncmp ( V_225 , L_33 , 4 ) ) {
V_222 = (struct V_198 * ) ( ( char * ) V_222
+ F_29 ( V_222 -> V_213 . V_226 ) ) ;
continue;
}
if ( V_222 -> V_202 . V_227 & V_228 )
return V_229 ;
V_223 = true ;
break;
} while ( F_29 ( V_222 -> V_213 . V_226 ) != 0 );
if ( ! V_223 )
return 0 ;
return F_49 ( V_222 -> V_202 . V_207 ) ;
}
int
F_50 ( const unsigned int V_83 , struct V_4 * V_5 , T_1 * V_230 ,
V_204 * V_231 , V_204 * V_232 , T_8 V_233 ,
T_8 V_234 , T_8 V_235 , T_8 V_236 ,
T_7 * V_200 , struct V_237 * V_201 )
{
struct V_238 * V_85 ;
struct V_220 * V_80 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
struct V_87 V_88 [ 3 ] ;
int V_79 ;
int V_239 ;
T_1 * V_240 = NULL ;
int V_241 ;
int V_35 = 0 ;
int V_242 = 2 ;
F_7 ( V_46 , L_34 ) ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_49 ;
V_35 = F_18 ( V_44 , V_5 , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
V_85 -> V_243 = V_244 ;
V_85 -> V_245 = F_5 ( V_233 ) ;
V_85 -> V_246 = F_5 ( V_235 ) ;
V_85 -> V_247 = V_248 ;
V_85 -> V_249 = F_5 ( V_234 ) ;
V_85 -> V_250 = F_5 ( V_236 ) ;
V_239 = ( 2 * F_51 ( ( V_251 * ) V_230 , V_252 ) ) + 2 ;
V_85 -> V_217 = F_4 ( sizeof( struct V_238 )
- 8 - 4 ) ;
V_88 [ 0 ] . V_113 = ( char * ) V_85 ;
V_88 [ 0 ] . V_114 = F_27 ( V_85 ) + 4 ;
if ( V_239 >= 4 ) {
V_85 -> V_219 = F_4 ( V_239 - 2 ) ;
V_88 [ 0 ] . V_114 -- ;
if ( V_239 % 8 != 0 ) {
V_241 = V_239 / 8 * 8 ;
if ( V_241 < V_239 )
V_241 += 8 ;
V_240 = F_37 ( V_241 , V_143 ) ;
if ( ! V_240 )
return - V_73 ;
memcpy ( ( char * ) V_240 , ( const char * ) V_230 ,
V_239 ) ;
V_239 = V_241 ;
V_230 = V_240 ;
}
V_88 [ 1 ] . V_114 = V_239 ;
V_88 [ 1 ] . V_113 = V_230 ;
F_26 ( V_85 , V_239 - 1 ) ;
} else {
V_88 [ 0 ] . V_114 += 7 ;
V_85 -> V_2 . V_11 = F_3 ( F_52 (
V_85 -> V_2 . V_11 ) + 8 - 1 ) ;
V_242 = 1 ;
V_85 -> V_219 = 0 ;
}
if ( ! V_29 -> V_253 )
* V_200 = V_254 ;
if ( ! ( V_5 -> V_22 -> V_29 -> V_128 & V_255 ) ||
* V_200 == V_254 )
V_85 -> V_256 = * V_200 ;
else {
V_88 [ V_242 ] . V_113 = F_46 ( V_200 + 1 , * V_200 ) ;
if ( V_88 [ V_242 ] . V_113 == NULL ) {
F_23 ( V_85 ) ;
F_36 ( V_240 ) ;
return - V_73 ;
}
V_88 [ V_242 ] . V_114 = sizeof( struct V_198 ) ;
V_85 -> V_256 = V_257 ;
V_85 -> V_224 = F_5 (
sizeof( struct V_238 ) - 4 - 8 +
V_88 [ V_242 - 1 ] . V_114 ) ;
V_85 -> V_258 = F_5 (
sizeof( struct V_198 ) ) ;
F_26 ( & V_85 -> V_2 , sizeof( struct V_198 ) ) ;
V_242 ++ ;
}
V_35 = F_28 ( V_83 , V_22 , V_88 , V_242 , & V_79 , 0 ) ;
V_80 = (struct V_220 * ) V_88 [ 0 ] . V_113 ;
if ( V_35 != 0 ) {
F_43 ( V_5 , V_259 ) ;
goto V_260;
}
* V_231 = V_80 -> V_261 ;
* V_232 = V_80 -> V_262 ;
if ( V_201 ) {
memcpy ( V_201 , & V_80 -> V_263 , 32 ) ;
V_201 -> V_264 = V_80 -> V_264 ;
V_201 -> V_265 = V_80 -> V_266 ;
V_201 -> V_267 = V_80 -> V_246 ;
V_201 -> V_268 = F_5 ( 1 ) ;
V_201 -> V_269 = 0 ;
}
if ( V_80 -> V_270 == V_257 )
* V_200 = F_48 ( V_80 ) ;
else
* V_200 = V_80 -> V_270 ;
V_260:
F_36 ( V_240 ) ;
F_22 ( V_79 , V_80 ) ;
return V_35 ;
}
int
F_53 ( const unsigned int V_83 , struct V_4 * V_5 ,
V_204 V_231 , V_204 V_232 )
{
struct V_271 * V_85 ;
struct V_272 * V_80 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
struct V_87 V_88 [ 1 ] ;
int V_79 ;
int V_35 = 0 ;
F_7 ( V_46 , L_35 ) ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_49 ;
V_35 = F_18 ( V_53 , V_5 , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
V_85 -> V_261 = V_231 ;
V_85 -> V_262 = V_232 ;
V_88 [ 0 ] . V_113 = ( char * ) V_85 ;
V_88 [ 0 ] . V_114 = F_27 ( V_85 ) + 4 ;
V_35 = F_28 ( V_83 , V_22 , V_88 , 1 , & V_79 , 0 ) ;
V_80 = (struct V_272 * ) V_88 [ 0 ] . V_113 ;
if ( V_35 != 0 ) {
if ( V_5 )
F_43 ( V_5 , V_273 ) ;
goto V_274;
}
V_274:
F_22 ( V_79 , V_80 ) ;
return V_35 ;
}
static int
F_54 ( unsigned int V_275 , unsigned int V_276 ,
struct V_1 * V_2 , unsigned int V_277 )
{
unsigned int V_278 = F_52 ( V_2 -> V_11 ) ;
char * V_279 = V_278 + 4 + ( char * ) V_2 ;
char * V_280 = 4 + V_275 + ( char * ) V_2 ;
char * V_281 = V_280 + V_276 ;
if ( V_276 < V_277 ) {
F_7 ( V_120 , L_36 ,
V_276 , V_277 ) ;
return - V_176 ;
}
if ( ( V_278 > 0x7FFFFF ) || ( V_276 > 0x7FFFFF ) ) {
F_7 ( V_120 , L_37 ,
V_276 , V_278 ) ;
return - V_176 ;
}
if ( ( V_280 > V_279 ) || ( V_281 > V_279 ) ) {
F_7 ( V_120 , L_38 ) ;
return - V_176 ;
}
return 0 ;
}
static int
F_55 ( unsigned int V_275 , unsigned int V_276 ,
struct V_1 * V_2 , unsigned int V_282 ,
char * V_283 )
{
char * V_280 = 4 + V_275 + ( char * ) V_2 ;
int V_35 ;
if ( ! V_283 )
return - V_176 ;
V_35 = F_54 ( V_275 , V_276 , V_2 , V_282 ) ;
if ( V_35 )
return V_35 ;
memcpy ( V_283 , V_280 , V_276 ) ;
return 0 ;
}
static int
F_56 ( const unsigned int V_83 , struct V_4 * V_5 ,
V_204 V_231 , V_204 V_232 , T_6 V_284 ,
T_9 V_285 , T_9 V_286 , void * V_283 )
{
struct V_287 * V_85 ;
struct V_288 * V_80 = NULL ;
struct V_87 V_88 [ 2 ] ;
int V_35 = 0 ;
int V_79 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
F_7 ( V_46 , L_39 ) ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_49 ;
V_35 = F_18 ( V_70 , V_5 , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
V_85 -> V_289 = V_290 ;
V_85 -> V_291 = V_284 ;
V_85 -> V_261 = V_231 ;
V_85 -> V_262 = V_232 ;
V_85 -> V_292 =
F_4 ( sizeof( struct V_287 ) - 1 - 4 ) ;
V_85 -> V_293 = F_5 ( V_285 ) ;
V_88 [ 0 ] . V_113 = ( char * ) V_85 ;
V_88 [ 0 ] . V_114 = F_27 ( V_85 ) + 4 ;
V_35 = F_28 ( V_83 , V_22 , V_88 , 1 , & V_79 , 0 ) ;
V_80 = (struct V_288 * ) V_88 [ 0 ] . V_113 ;
if ( V_35 ) {
F_43 ( V_5 , V_294 ) ;
goto V_295;
}
V_35 = F_55 ( F_2 ( V_80 -> V_296 ) ,
F_29 ( V_80 -> V_293 ) ,
& V_80 -> V_2 , V_286 , V_283 ) ;
V_295:
F_22 ( V_79 , V_80 ) ;
return V_35 ;
}
int
F_57 ( const unsigned int V_83 , struct V_4 * V_5 ,
V_204 V_231 , V_204 V_232 ,
struct V_237 * V_283 )
{
return F_56 ( V_83 , V_5 , V_231 , V_232 ,
V_297 ,
sizeof( struct V_237 ) + V_298 * 2 ,
sizeof( struct V_237 ) , V_283 ) ;
}
int
F_58 ( const unsigned int V_83 , struct V_4 * V_5 ,
V_204 V_231 , V_204 V_232 , T_10 * V_299 )
{
return F_56 ( V_83 , V_5 , V_231 , V_232 ,
V_300 ,
sizeof( struct V_301 ) ,
sizeof( struct V_301 ) , V_299 ) ;
}
static void
F_59 ( struct V_302 * V_303 )
{
struct V_39 * V_29 = V_303 -> V_304 ;
struct V_305 * V_306 = (struct V_305 * ) V_303 -> V_307 ;
unsigned int V_308 = 1 ;
if ( V_303 -> V_309 == V_310 )
V_308 = F_2 ( V_306 -> V_2 . V_15 ) ;
F_60 ( V_303 ) ;
F_61 ( V_29 , V_308 , V_311 ) ;
}
int
F_62 ( struct V_39 * V_29 )
{
struct V_312 * V_85 ;
int V_35 = 0 ;
struct V_87 V_88 ;
struct V_313 V_314 = { . V_315 = & V_88 ,
. V_316 = 1 } ;
F_7 ( V_46 , L_40 ) ;
V_35 = F_18 ( V_317 , NULL , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
V_85 -> V_2 . V_15 = F_4 ( 1 ) ;
V_88 . V_113 = ( char * ) V_85 ;
V_88 . V_114 = F_27 ( V_85 ) + 4 ;
V_35 = F_63 ( V_29 , & V_314 , NULL , F_59 , V_29 ,
V_311 ) ;
if ( V_35 )
F_7 ( V_46 , L_41 , V_35 ) ;
F_23 ( V_85 ) ;
return V_35 ;
}
int
F_64 ( const unsigned int V_83 , struct V_4 * V_5 , V_204 V_231 ,
V_204 V_232 )
{
struct V_318 * V_85 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
struct V_87 V_88 [ 1 ] ;
int V_79 ;
int V_35 = 0 ;
F_7 ( V_46 , L_42 ) ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_49 ;
V_35 = F_18 ( V_64 , V_5 , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
V_85 -> V_261 = V_231 ;
V_85 -> V_262 = V_232 ;
V_88 [ 0 ] . V_113 = ( char * ) V_85 ;
V_88 [ 0 ] . V_114 = F_27 ( V_85 ) + 4 ;
V_35 = F_28 ( V_83 , V_22 , V_88 , 1 , & V_79 , 0 ) ;
if ( ( V_35 != 0 ) && V_5 )
F_43 ( V_5 , V_319 ) ;
F_22 ( V_79 , V_88 [ 0 ] . V_113 ) ;
return V_35 ;
}
static int
F_65 ( struct V_87 * V_88 , struct V_320 * V_321 ,
unsigned int V_322 , int V_323 )
{
int V_35 = - V_324 ;
struct V_325 * V_85 = NULL ;
V_35 = F_18 ( V_65 , V_321 -> V_5 , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
if ( V_321 -> V_5 -> V_22 -> V_29 == NULL )
return - V_326 ;
V_85 -> V_2 . V_16 = F_5 ( V_321 -> V_327 ) ;
V_85 -> V_261 = V_321 -> V_231 ;
V_85 -> V_262 = V_321 -> V_232 ;
V_85 -> V_328 = 0 ;
V_85 -> V_329 = 0 ;
V_85 -> V_151 = 0 ;
V_85 -> V_330 = 0 ;
V_85 -> V_331 = F_5 ( V_321 -> V_332 ) ;
V_85 -> V_333 = F_47 ( V_321 -> V_275 ) ;
if ( V_323 & V_334 ) {
if ( ! ( V_323 & V_335 ) ) {
V_85 -> V_2 . V_336 =
F_5 ( F_27 ( V_85 ) + 4 ) ;
} else
V_85 -> V_2 . V_336 = 0 ;
if ( V_323 & V_337 ) {
V_85 -> V_2 . V_27 |= V_338 ;
V_85 -> V_2 . V_23 = 0xFFFFFFFF ;
V_85 -> V_2 . V_20 = 0xFFFFFFFF ;
V_85 -> V_261 = 0xFFFFFFFF ;
V_85 -> V_262 = 0xFFFFFFFF ;
}
}
if ( V_322 > V_321 -> V_332 )
V_85 -> V_339 = F_5 ( V_322 ) ;
else
V_85 -> V_339 = 0 ;
V_88 [ 0 ] . V_113 = ( char * ) V_85 ;
V_88 [ 0 ] . V_114 = F_27 ( V_85 ) + 4 ;
return V_35 ;
}
static void
F_66 ( struct V_302 * V_303 )
{
struct V_340 * V_341 = V_303 -> V_304 ;
struct V_4 * V_5 = F_67 ( V_341 -> V_342 -> V_343 ) ;
struct V_39 * V_29 = V_5 -> V_22 -> V_29 ;
struct V_1 * V_201 = (struct V_1 * ) V_341 -> V_88 . V_113 ;
unsigned int V_308 = 1 ;
struct V_313 V_314 = { . V_315 = & V_341 -> V_88 ,
. V_316 = 1 ,
. V_344 = V_341 -> V_345 ,
. V_346 = V_341 -> V_347 ,
. V_348 = V_341 -> V_349 ,
. V_350 = V_341 -> V_351 } ;
F_7 ( V_46 , L_43 ,
V_352 , V_303 -> V_303 , V_303 -> V_309 , V_341 -> V_353 ,
V_341 -> V_354 ) ;
switch ( V_303 -> V_309 ) {
case V_310 :
V_308 = F_2 ( V_201 -> V_15 ) ;
if ( V_29 -> V_30 &
( V_31 | V_132 ) ) {
int V_35 ;
V_35 = F_68 ( & V_314 , V_29 ) ;
if ( V_35 )
F_7 ( V_120 , L_44 ,
V_35 ) ;
}
F_69 ( V_341 -> V_354 ) ;
F_70 ( V_5 , V_341 -> V_354 ) ;
break;
case V_355 :
case V_356 :
V_341 -> V_353 = - V_55 ;
break;
default:
if ( V_341 -> V_353 != - V_357 )
V_341 -> V_353 = - V_49 ;
}
if ( V_341 -> V_353 )
F_43 ( V_5 , V_358 ) ;
F_71 ( V_359 , & V_341 -> V_360 ) ;
F_60 ( V_303 ) ;
F_61 ( V_29 , V_308 , 0 ) ;
}
int
F_72 ( struct V_340 * V_341 )
{
int V_35 ;
struct V_1 * V_201 ;
struct V_320 V_321 ;
struct V_313 V_314 = { . V_315 = & V_341 -> V_88 ,
. V_316 = 1 } ;
F_7 ( V_46 , L_45 ,
V_352 , V_341 -> V_275 , V_341 -> V_354 ) ;
V_321 . V_5 = F_67 ( V_341 -> V_342 -> V_343 ) ;
V_321 . V_275 = V_341 -> V_275 ;
V_321 . V_332 = V_341 -> V_354 ;
V_321 . V_231 = V_341 -> V_342 -> V_361 . V_231 ;
V_321 . V_232 = V_341 -> V_342 -> V_361 . V_232 ;
V_321 . V_327 = V_341 -> V_327 ;
V_35 = F_65 ( & V_341 -> V_88 , & V_321 , 0 , 0 ) ;
if ( V_35 )
return V_35 ;
V_201 = (struct V_1 * ) V_341 -> V_88 . V_113 ;
V_341 -> V_88 . V_114 = F_27 ( V_341 -> V_88 . V_113 ) + 4 ;
F_73 ( & V_341 -> V_362 ) ;
V_35 = F_63 ( V_321 . V_5 -> V_22 -> V_29 , & V_314 ,
V_363 , F_66 ,
V_341 , 0 ) ;
if ( V_35 ) {
F_74 ( & V_341 -> V_362 , V_364 ) ;
F_43 ( V_321 . V_5 , V_358 ) ;
}
F_23 ( V_201 ) ;
return V_35 ;
}
int
F_75 ( const unsigned int V_83 , struct V_320 * V_321 ,
unsigned int * V_365 , char * * V_201 , int * V_366 )
{
int V_79 , V_35 = - V_324 ;
struct V_367 * V_80 = NULL ;
struct V_87 V_88 [ 1 ] ;
* V_365 = 0 ;
V_35 = F_65 ( V_88 , V_321 , 0 , 0 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_28 ( V_83 , V_321 -> V_5 -> V_22 , V_88 , 1 ,
& V_79 , V_156 ) ;
V_80 = (struct V_367 * ) V_88 [ 0 ] . V_113 ;
if ( V_80 -> V_2 . V_158 == V_368 ) {
F_22 ( V_79 , V_88 [ 0 ] . V_113 ) ;
return 0 ;
}
if ( V_35 ) {
F_43 ( V_321 -> V_5 , V_358 ) ;
F_7 ( V_120 , L_46 , V_35 ) ;
} else {
* V_365 = F_29 ( V_80 -> V_215 ) ;
if ( ( * V_365 > V_369 ) ||
( * V_365 > V_321 -> V_332 ) ) {
F_7 ( V_46 , L_47 ,
* V_365 , V_321 -> V_332 ) ;
V_35 = - V_49 ;
* V_365 = 0 ;
}
}
if ( * V_201 ) {
memcpy ( * V_201 , ( char * ) V_80 -> V_2 . V_12 + V_80 -> V_214 ,
* V_365 ) ;
F_22 ( V_79 , V_88 [ 0 ] . V_113 ) ;
} else if ( V_79 != V_157 ) {
* V_201 = V_88 [ 0 ] . V_113 ;
if ( V_79 == V_81 )
* V_366 = V_81 ;
else if ( V_79 == V_82 )
* V_366 = V_82 ;
}
return V_35 ;
}
static void
F_76 ( struct V_302 * V_303 )
{
struct V_370 * V_371 = V_303 -> V_304 ;
struct V_4 * V_5 = F_67 ( V_371 -> V_342 -> V_343 ) ;
unsigned int V_372 ;
struct V_373 * V_80 = (struct V_373 * ) V_303 -> V_307 ;
unsigned int V_308 = 1 ;
switch ( V_303 -> V_309 ) {
case V_310 :
V_308 = F_2 ( V_80 -> V_2 . V_15 ) ;
V_371 -> V_353 = F_77 ( V_303 , V_5 -> V_22 -> V_29 , 0 ) ;
if ( V_371 -> V_353 != 0 )
break;
V_372 = F_29 ( V_80 -> V_215 ) ;
if ( V_372 > V_371 -> V_354 )
V_372 &= 0xFFFF ;
if ( V_372 < V_371 -> V_354 )
V_371 -> V_353 = - V_374 ;
else
V_371 -> V_354 = V_372 ;
break;
case V_355 :
case V_356 :
V_371 -> V_353 = - V_55 ;
break;
default:
V_371 -> V_353 = - V_49 ;
break;
}
if ( V_371 -> V_353 )
F_43 ( V_5 , V_375 ) ;
F_71 ( V_359 , & V_371 -> V_360 ) ;
F_60 ( V_303 ) ;
F_61 ( V_5 -> V_22 -> V_29 , V_308 , 0 ) ;
}
int
F_78 ( struct V_370 * V_371 )
{
int V_35 = - V_324 ;
struct V_376 * V_85 = NULL ;
struct V_4 * V_5 = F_67 ( V_371 -> V_342 -> V_343 ) ;
struct V_87 V_88 ;
struct V_313 V_314 ;
V_35 = F_18 ( V_43 , V_5 , ( void * * ) & V_85 ) ;
if ( V_35 )
goto V_377;
V_85 -> V_2 . V_16 = F_5 ( V_371 -> V_342 -> V_327 ) ;
V_85 -> V_261 = V_371 -> V_342 -> V_361 . V_231 ;
V_85 -> V_262 = V_371 -> V_342 -> V_361 . V_232 ;
V_85 -> V_378 = 0 ;
V_85 -> V_379 = 0 ;
V_85 -> V_151 = 0 ;
V_85 -> V_333 = F_47 ( V_371 -> V_275 ) ;
V_85 -> V_214 = F_4 (
F_39 ( struct V_376 , V_160 ) - 4 ) ;
V_85 -> V_339 = 0 ;
V_88 . V_114 = F_27 ( V_85 ) + 4 - 1 ;
V_88 . V_113 = V_85 ;
V_314 . V_315 = & V_88 ;
V_314 . V_316 = 1 ;
V_314 . V_344 = V_371 -> V_345 ;
V_314 . V_346 = V_371 -> V_347 ;
V_314 . V_348 = V_371 -> V_349 ;
V_314 . V_350 = V_371 -> V_351 ;
F_7 ( V_46 , L_48 ,
V_371 -> V_275 , V_371 -> V_354 ) ;
V_85 -> V_331 = F_5 ( V_371 -> V_354 ) ;
F_26 ( & V_85 -> V_2 , V_371 -> V_354 - 1 ) ;
F_73 ( & V_371 -> V_362 ) ;
V_35 = F_63 ( V_5 -> V_22 -> V_29 , & V_314 , NULL ,
F_76 , V_371 , 0 ) ;
if ( V_35 ) {
F_74 ( & V_371 -> V_362 , V_380 ) ;
F_43 ( V_5 , V_375 ) ;
}
V_377:
F_23 ( V_85 ) ;
return V_35 ;
}
int
F_79 ( const unsigned int V_83 , struct V_320 * V_321 ,
unsigned int * V_365 , struct V_87 * V_88 , int V_381 )
{
int V_35 = 0 ;
struct V_376 * V_85 = NULL ;
struct V_373 * V_80 = NULL ;
int V_79 ;
* V_365 = 0 ;
if ( V_381 < 1 )
return V_35 ;
V_35 = F_18 ( V_43 , V_321 -> V_5 , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
if ( V_321 -> V_5 -> V_22 -> V_29 == NULL )
return - V_326 ;
V_85 -> V_2 . V_16 = F_5 ( V_321 -> V_327 ) ;
V_85 -> V_261 = V_321 -> V_231 ;
V_85 -> V_262 = V_321 -> V_232 ;
V_85 -> V_378 = 0 ;
V_85 -> V_379 = 0 ;
V_85 -> V_151 = 0 ;
V_85 -> V_331 = F_5 ( V_321 -> V_332 ) ;
V_85 -> V_333 = F_47 ( V_321 -> V_275 ) ;
V_85 -> V_214 = F_4 (
F_39 ( struct V_376 , V_160 ) - 4 ) ;
V_85 -> V_339 = 0 ;
V_88 [ 0 ] . V_113 = ( char * ) V_85 ;
V_88 [ 0 ] . V_114 = F_27 ( V_85 ) + 4 - 1 ;
F_26 ( V_85 , V_321 -> V_332 - 1 ) ;
V_35 = F_28 ( V_83 , V_321 -> V_5 -> V_22 , V_88 , V_381 + 1 ,
& V_79 , 0 ) ;
V_80 = (struct V_373 * ) V_88 [ 0 ] . V_113 ;
if ( V_35 ) {
F_43 ( V_321 -> V_5 , V_375 ) ;
F_7 ( V_120 , L_49 , V_35 ) ;
} else
* V_365 = F_29 ( V_80 -> V_215 ) ;
F_22 ( V_79 , V_80 ) ;
return V_35 ;
}
static unsigned int
F_80 ( char * V_382 , char * V_281 , char * * V_383 , T_9 V_384 )
{
int V_385 ;
unsigned int V_386 = 0 ;
unsigned int V_387 = 0 ;
T_11 * V_388 ;
if ( V_382 == NULL )
return 0 ;
V_388 = ( T_11 * ) V_382 ;
while ( 1 ) {
V_388 = ( T_11 * )
( ( char * ) V_388 + V_387 ) ;
if ( ( char * ) V_388 + V_384 > V_281 ) {
F_7 ( V_120 , L_50 ) ;
break;
}
V_385 = F_29 ( V_388 -> V_389 ) ;
if ( ( char * ) V_388 + V_385 + V_384 > V_281 ) {
F_7 ( V_120 , L_51 ,
V_281 ) ;
break;
}
* V_383 = ( char * ) V_388 ;
V_386 ++ ;
V_387 = F_29 ( V_388 -> V_390 ) ;
if ( ! V_387 )
break;
}
return V_386 ;
}
int
F_81 ( const unsigned int V_83 , struct V_4 * V_5 ,
V_204 V_231 , V_204 V_232 , int V_391 ,
struct V_392 * V_393 )
{
struct V_394 * V_85 ;
struct V_395 * V_80 = NULL ;
struct V_87 V_88 [ 2 ] ;
int V_35 = 0 ;
int V_385 ;
int V_79 ;
unsigned char * V_396 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
T_1 V_397 = F_4 ( '*' ) ;
char * V_279 ;
unsigned int V_398 = V_399 ;
T_9 V_400 ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_49 ;
V_35 = F_18 ( V_68 , V_5 , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
switch ( V_393 -> V_401 ) {
case V_402 :
V_85 -> V_403 = V_404 ;
V_400 = sizeof( T_11 ) - 1 ;
break;
case V_405 :
V_85 -> V_403 = V_406 ;
V_400 = sizeof( V_407 ) - 1 ;
break;
default:
F_7 ( V_120 , L_52 ,
V_393 -> V_401 ) ;
V_35 = - V_176 ;
goto V_408;
}
V_85 -> V_409 = F_5 ( V_391 ) ;
V_85 -> V_261 = V_231 ;
V_85 -> V_262 = V_232 ;
V_385 = 0x2 ;
V_396 = V_85 -> V_160 ;
memcpy ( V_396 , & V_397 , V_385 ) ;
V_85 -> V_410 =
F_4 ( sizeof( struct V_394 ) - 1 - 4 ) ;
V_85 -> V_389 = F_4 ( V_385 ) ;
V_398 = F_82 (unsigned int, output_size, server->maxBuf) ;
V_398 = F_82 (unsigned int, output_size, 2 << 15 ) ;
V_85 -> V_293 = F_5 ( V_398 ) ;
V_88 [ 0 ] . V_113 = ( char * ) V_85 ;
V_88 [ 0 ] . V_114 = F_27 ( V_85 ) + 4 - 1 ;
V_88 [ 1 ] . V_113 = ( char * ) ( V_85 -> V_160 ) ;
V_88 [ 1 ] . V_114 = V_385 ;
F_26 ( V_85 , V_385 - 1 ) ;
V_35 = F_28 ( V_83 , V_22 , V_88 , 2 , & V_79 , 0 ) ;
V_80 = (struct V_395 * ) V_88 [ 0 ] . V_113 ;
if ( V_35 ) {
F_43 ( V_5 , V_411 ) ;
goto V_408;
}
V_35 = F_54 ( F_2 ( V_80 -> V_296 ) ,
F_29 ( V_80 -> V_293 ) , & V_80 -> V_2 ,
V_400 ) ;
if ( V_35 )
goto V_408;
V_393 -> V_412 = true ;
if ( V_393 -> V_413 ) {
if ( V_393 -> V_414 )
F_23 ( V_393 -> V_413 ) ;
else
F_24 ( V_393 -> V_413 ) ;
}
V_393 -> V_413 = ( char * ) V_80 ;
V_393 -> V_415 = V_393 -> V_416 = 4 +
( char * ) & V_80 -> V_2 + F_2 ( V_80 -> V_296 ) ;
V_279 = F_27 ( V_80 ) + 4 + ( char * ) & V_80 -> V_2 ;
V_393 -> V_417 =
F_80 ( V_393 -> V_415 , V_279 ,
& V_393 -> V_416 , V_400 ) ;
V_393 -> V_418 += V_393 -> V_417 ;
F_7 ( V_46 , L_53 ,
V_393 -> V_417 , V_393 -> V_418 ,
V_393 -> V_415 , V_393 -> V_416 ) ;
if ( V_79 == V_82 )
V_393 -> V_414 = false ;
else if ( V_79 == V_81 )
V_393 -> V_414 = true ;
else
F_7 ( V_120 , L_54 ) ;
if ( V_80 -> V_2 . V_158 == V_419 )
V_393 -> V_420 = 1 ;
else
V_393 -> V_420 = 0 ;
return V_35 ;
V_408:
F_22 ( V_79 , V_80 ) ;
return V_35 ;
}
static int
F_83 ( const unsigned int V_83 , struct V_4 * V_5 ,
V_204 V_231 , V_204 V_232 , T_12 V_327 , int V_284 ,
unsigned int V_421 , void * * V_283 , unsigned int * V_384 )
{
struct V_422 * V_85 ;
struct V_423 * V_80 = NULL ;
struct V_87 * V_88 ;
int V_35 = 0 ;
int V_79 ;
unsigned int V_424 ;
struct V_39 * V_29 ;
struct V_38 * V_22 = V_5 -> V_22 ;
if ( V_22 && ( V_22 -> V_29 ) )
V_29 = V_22 -> V_29 ;
else
return - V_49 ;
if ( ! V_421 )
return - V_176 ;
V_88 = F_34 ( sizeof( struct V_87 ) * V_421 , V_143 ) ;
if ( ! V_88 )
return - V_73 ;
V_35 = F_18 ( V_71 , V_5 , ( void * * ) & V_85 ) ;
if ( V_35 ) {
F_36 ( V_88 ) ;
return V_35 ;
}
V_85 -> V_2 . V_16 = F_5 ( V_327 ) ;
V_85 -> V_289 = V_290 ;
V_85 -> V_291 = V_284 ;
V_85 -> V_261 = V_231 ;
V_85 -> V_262 = V_232 ;
V_85 -> V_425 =
F_4 ( sizeof( struct V_422 ) - 1 - 4 ) ;
V_85 -> V_426 = F_5 ( * V_384 ) ;
F_26 ( V_85 , * V_384 - 1 ) ;
memcpy ( V_85 -> V_160 , * V_283 , * V_384 ) ;
V_88 [ 0 ] . V_113 = ( char * ) V_85 ;
V_88 [ 0 ] . V_114 = F_27 ( V_85 ) + 4 ;
for ( V_424 = 1 ; V_424 < V_421 ; V_424 ++ ) {
F_26 ( V_85 , V_384 [ V_424 ] ) ;
F_84 ( & V_85 -> V_426 , V_384 [ V_424 ] ) ;
V_88 [ V_424 ] . V_113 = ( char * ) V_283 [ V_424 ] ;
V_88 [ V_424 ] . V_114 = V_384 [ V_424 ] ;
}
V_35 = F_28 ( V_83 , V_22 , V_88 , V_421 , & V_79 , 0 ) ;
V_80 = (struct V_423 * ) V_88 [ 0 ] . V_113 ;
if ( V_35 != 0 ) {
F_43 ( V_5 , V_427 ) ;
goto V_19;
}
V_19:
F_22 ( V_79 , V_80 ) ;
F_36 ( V_88 ) ;
return V_35 ;
}
int
F_85 ( const unsigned int V_83 , struct V_4 * V_5 ,
V_204 V_231 , V_204 V_232 , T_1 * V_428 )
{
struct V_429 V_430 ;
void * * V_283 ;
unsigned int V_384 [ 2 ] ;
int V_35 ;
int V_385 = ( 2 * F_51 ( ( V_251 * ) V_428 , V_252 ) ) ;
V_283 = F_34 ( sizeof( void * ) * 2 , V_143 ) ;
if ( ! V_283 )
return - V_73 ;
V_430 . V_431 = 1 ;
V_430 . V_432 = 0 ;
V_430 . V_389 = F_5 ( V_385 ) ;
V_283 [ 0 ] = & V_430 ;
V_384 [ 0 ] = sizeof( struct V_429 ) ;
V_283 [ 1 ] = V_428 ;
V_384 [ 1 ] = V_385 + 2 ;
V_35 = F_83 ( V_83 , V_5 , V_231 , V_232 ,
V_17 -> V_18 , V_433 , 2 , V_283 ,
V_384 ) ;
F_36 ( V_283 ) ;
return V_35 ;
}
int
F_86 ( const unsigned int V_83 , struct V_4 * V_5 ,
V_204 V_231 , V_204 V_232 , T_1 * V_428 )
{
struct V_434 V_430 ;
void * * V_283 ;
unsigned int V_384 [ 2 ] ;
int V_35 ;
int V_385 = ( 2 * F_51 ( ( V_251 * ) V_428 , V_252 ) ) ;
V_283 = F_34 ( sizeof( void * ) * 2 , V_143 ) ;
if ( ! V_283 )
return - V_73 ;
V_430 . V_431 = 0 ;
V_430 . V_432 = 0 ;
V_430 . V_389 = F_5 ( V_385 ) ;
V_283 [ 0 ] = & V_430 ;
V_384 [ 0 ] = sizeof( struct V_434 ) ;
V_283 [ 1 ] = V_428 ;
V_384 [ 1 ] = V_385 + 2 ;
V_35 = F_83 ( V_83 , V_5 , V_231 , V_232 ,
V_17 -> V_18 , V_435 , 2 , V_283 , V_384 ) ;
F_36 ( V_283 ) ;
return V_35 ;
}
int
F_87 ( const unsigned int V_83 , struct V_4 * V_5 , V_204 V_231 ,
V_204 V_232 , T_12 V_327 , T_10 * V_436 )
{
struct V_437 V_430 ;
void * V_283 ;
unsigned int V_384 ;
V_430 . V_265 = * V_436 ;
V_283 = & V_430 ;
V_384 = sizeof( struct V_437 ) ;
return F_83 ( V_83 , V_5 , V_231 , V_232 , V_327 ,
V_438 , 1 , & V_283 , & V_384 ) ;
}
int
F_88 ( const unsigned int V_83 , struct V_4 * V_5 ,
V_204 V_231 , V_204 V_232 , T_13 * V_201 )
{
unsigned int V_384 ;
V_384 = sizeof( T_13 ) ;
return F_83 ( V_83 , V_5 , V_231 , V_232 ,
V_17 -> V_18 , V_439 , 1 ,
( void * * ) & V_201 , & V_384 ) ;
}
int
F_89 ( const unsigned int V_83 , struct V_4 * V_5 ,
const V_204 V_231 , const V_204 V_232 ,
T_7 V_440 )
{
int V_35 ;
struct V_441 * V_85 = NULL ;
F_7 ( V_46 , L_55 ) ;
V_35 = F_18 ( V_54 , V_5 , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
V_85 -> V_442 = V_232 ;
V_85 -> V_443 = V_231 ;
V_85 -> V_270 = V_440 ;
V_85 -> V_2 . V_15 = F_4 ( 1 ) ;
V_35 = F_42 ( V_83 , V_5 -> V_22 , ( char * ) V_85 , V_444 ) ;
if ( V_35 ) {
F_43 ( V_5 , V_445 ) ;
F_7 ( V_46 , L_56 , V_35 ) ;
}
return V_35 ;
}
static void
F_90 ( struct V_446 * V_447 ,
struct V_448 * V_449 )
{
V_449 -> V_450 = F_29 ( V_447 -> V_451 ) *
F_29 ( V_447 -> V_452 ) ;
V_449 -> V_453 = F_91 ( V_447 -> V_454 ) ;
V_449 -> V_455 = F_91 ( V_447 -> V_456 ) ;
V_449 -> V_457 = F_91 ( V_447 -> V_458 ) ;
return;
}
static int
F_92 ( struct V_87 * V_88 , struct V_4 * V_5 , int V_459 ,
int V_460 , V_204 V_231 , V_204 V_232 )
{
int V_35 ;
struct V_287 * V_85 ;
F_7 ( V_46 , L_57 , V_459 ) ;
if ( ( V_5 -> V_22 == NULL ) || ( V_5 -> V_22 -> V_29 == NULL ) )
return - V_49 ;
V_35 = F_18 ( V_70 , V_5 , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
V_85 -> V_289 = V_461 ;
V_85 -> V_291 = V_459 ;
V_85 -> V_261 = V_231 ;
V_85 -> V_262 = V_232 ;
V_85 -> V_292 =
F_4 ( sizeof( struct V_287 ) - 1 - 4 ) ;
V_85 -> V_293 = F_5 (
V_460 + sizeof( struct V_288 ) - 1 - 4 ) ;
V_88 -> V_113 = ( char * ) V_85 ;
V_88 -> V_114 = F_27 ( V_85 ) + 4 ;
return 0 ;
}
int
F_93 ( const unsigned int V_83 , struct V_4 * V_5 ,
V_204 V_231 , V_204 V_232 , struct V_448 * V_462 )
{
struct V_288 * V_80 = NULL ;
struct V_87 V_88 ;
int V_35 = 0 ;
int V_79 ;
struct V_38 * V_22 = V_5 -> V_22 ;
struct V_446 * V_430 = NULL ;
V_35 = F_92 ( & V_88 , V_5 , V_463 ,
sizeof( struct V_446 ) ,
V_231 , V_232 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_28 ( V_83 , V_22 , & V_88 , 1 , & V_79 , 0 ) ;
if ( V_35 ) {
F_43 ( V_5 , V_294 ) ;
goto V_295;
}
V_80 = (struct V_288 * ) V_88 . V_113 ;
V_430 = (struct V_446 * ) ( 4 +
F_2 ( V_80 -> V_296 ) + ( char * ) & V_80 -> V_2 ) ;
V_35 = F_54 ( F_2 ( V_80 -> V_296 ) ,
F_29 ( V_80 -> V_293 ) , & V_80 -> V_2 ,
sizeof( struct V_446 ) ) ;
if ( ! V_35 )
F_90 ( V_430 , V_462 ) ;
V_295:
F_22 ( V_79 , V_88 . V_113 ) ;
return V_35 ;
}
int
F_94 ( const unsigned int V_83 , struct V_4 * V_5 ,
const T_14 V_464 , const T_14 V_232 , const T_8 V_327 ,
const T_8 V_465 , struct V_466 * V_201 )
{
int V_35 = 0 ;
struct V_467 * V_85 = NULL ;
struct V_87 V_88 [ 2 ] ;
int V_468 ;
unsigned int V_469 ;
F_7 ( V_46 , L_58 , V_465 ) ;
V_35 = F_18 ( V_66 , V_5 , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
V_85 -> V_2 . V_16 = F_5 ( V_327 ) ;
V_85 -> V_470 = F_4 ( V_465 ) ;
V_85 -> V_261 = V_464 ;
V_85 -> V_262 = V_232 ;
V_469 = V_465 * sizeof( struct V_466 ) ;
F_26 ( V_85 , V_469 - sizeof( struct V_466 ) ) ;
V_88 [ 0 ] . V_113 = ( char * ) V_85 ;
V_88 [ 0 ] . V_114 = F_27 ( V_85 ) + 4 - V_469 ;
V_88 [ 1 ] . V_113 = ( char * ) V_201 ;
V_88 [ 1 ] . V_114 = V_469 ;
F_21 ( & V_5 -> V_75 . V_471 . V_472 ) ;
V_35 = F_28 ( V_83 , V_5 -> V_22 , V_88 , 2 , & V_468 , V_473 ) ;
if ( V_35 ) {
F_7 ( V_46 , L_59 , V_35 ) ;
F_43 ( V_5 , V_474 ) ;
}
return V_35 ;
}
int
F_95 ( const unsigned int V_83 , struct V_4 * V_5 ,
const T_14 V_464 , const T_14 V_232 , const T_8 V_327 ,
const T_14 V_332 , const T_14 V_275 , const T_8 V_475 ,
const bool V_476 )
{
struct V_466 V_477 ;
V_477 . V_333 = F_47 ( V_275 ) ;
V_477 . V_331 = F_47 ( V_332 ) ;
V_477 . V_27 = F_5 ( V_475 ) ;
if ( ! V_476 && V_475 != V_478 )
V_477 . V_27 |= F_5 ( V_479 ) ;
return F_94 ( V_83 , V_5 , V_464 , V_232 , V_327 , 1 , & V_477 ) ;
}
int
F_96 ( const unsigned int V_83 , struct V_4 * V_5 ,
T_7 * V_199 , const T_5 V_480 )
{
int V_35 ;
struct V_481 * V_85 = NULL ;
F_7 ( V_46 , L_60 ) ;
V_35 = F_18 ( V_54 , V_5 , ( void * * ) & V_85 ) ;
if ( V_35 )
return V_35 ;
V_85 -> V_2 . V_15 = F_4 ( 1 ) ;
V_85 -> V_13 = F_4 ( 36 ) ;
F_26 ( V_85 , 12 ) ;
memcpy ( V_85 -> V_482 , V_199 , 16 ) ;
V_85 -> V_207 = V_480 ;
V_35 = F_42 ( V_83 , V_5 -> V_22 , ( char * ) V_85 , V_444 ) ;
if ( V_35 ) {
F_43 ( V_5 , V_445 ) ;
F_7 ( V_46 , L_61 , V_35 ) ;
}
return V_35 ;
}
