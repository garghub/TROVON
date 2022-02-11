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
int F_35 ( const unsigned int V_82 , struct V_4 * V_5 )
{
int V_34 = 0 ;
struct V_131 V_132 ;
struct V_133 * V_134 ;
T_4 V_135 ;
F_7 ( V_45 , L_13 ) ;
if ( V_5 -> V_20 -> V_21 -> V_29 == false )
return 0 ;
V_132 . V_104 =
F_5 ( V_5 -> V_20 -> V_21 -> V_96 -> V_105 ) ;
memcpy ( V_132 . V_136 , V_107 , V_108 ) ;
if ( V_5 -> V_20 -> V_29 )
V_132 . V_99 =
F_4 ( V_100 ) ;
else if ( V_101 & V_102 )
V_132 . V_99 =
F_4 ( V_103 ) ;
else
V_132 . V_99 = 0 ;
V_132 . V_98 = F_4 ( 1 ) ;
V_132 . V_95 [ 0 ] =
F_4 ( V_5 -> V_20 -> V_21 -> V_96 -> V_97 ) ;
V_34 = F_36 ( V_82 , V_5 , V_137 , V_137 ,
V_138 , true ,
( char * ) & V_132 , sizeof( struct V_131 ) ,
( char * * ) & V_134 , & V_135 ) ;
if ( V_34 != 0 ) {
F_7 ( V_117 , L_14 , V_34 ) ;
return - V_48 ;
}
if ( V_135 != sizeof( struct V_133 ) ) {
F_7 ( V_117 , L_15 ) ;
return - V_48 ;
}
if ( V_134 -> V_139 !=
F_4 ( V_5 -> V_20 -> V_21 -> V_96 -> V_97 ) )
goto V_140;
if ( V_134 -> V_99 != F_4 ( V_5 -> V_20 -> V_21 -> V_127 ) )
goto V_140;
if ( ( F_30 ( V_134 -> V_104 ) | V_128 |
V_129 ) != V_5 -> V_20 -> V_21 -> V_22 )
goto V_140;
F_7 ( V_45 , L_16 ) ;
return 0 ;
V_140:
F_7 ( V_117 , L_17 ) ;
return - V_48 ;
}
int
F_37 ( const unsigned int V_82 , struct V_37 * V_20 ,
const struct V_35 * V_141 )
{
struct V_142 * V_84 ;
struct V_143 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_34 = 0 ;
int V_78 ;
T_5 V_144 = V_145 ;
struct V_38 * V_21 = V_20 -> V_21 ;
T_6 V_89 = 0 ;
char * V_90 ;
char * V_146 = NULL ;
bool V_147 = false ;
F_7 ( V_45 , L_18 ) ;
if ( ! V_21 ) {
F_26 ( 1 , L_5 , V_93 ) ;
return - V_48 ;
}
F_38 ( V_20 -> V_148 . V_149 ) ;
V_20 -> V_148 . V_149 = NULL ;
V_20 -> V_150 = F_39 ( sizeof( struct V_151 ) , V_152 ) ;
if ( ! V_20 -> V_150 )
return - V_72 ;
V_20 -> V_150 -> V_153 = true ;
V_20 -> V_154 = V_155 ;
V_156:
if ( V_144 == V_157 )
V_144 = V_158 ;
V_34 = F_18 ( V_159 , NULL , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_27 = 0 ;
V_84 -> V_160 = 0 ;
V_84 -> V_2 . V_15 = F_4 ( 3 ) ;
if ( V_21 -> V_29 )
V_84 -> V_99 = V_100 ;
else if ( V_101 & V_102 )
V_84 -> V_99 = V_103 ;
else
V_84 -> V_99 = 0 ;
V_84 -> V_104 = 0 ;
V_84 -> V_161 = 0 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
if ( V_144 == V_145 ) {
V_146 = F_39 ( sizeof( struct V_162 ) ,
V_152 ) ;
if ( V_146 == NULL ) {
V_34 = - V_72 ;
goto V_163;
}
F_40 ( V_146 , V_20 ) ;
if ( V_147 ) {
F_7 ( V_117 , L_19 ) ;
V_34 = - V_164 ;
F_38 ( V_146 ) ;
goto V_163;
} else {
V_89 = sizeof( struct V_162 ) ;
V_90 = V_146 ;
}
} else if ( V_144 == V_158 ) {
V_84 -> V_2 . V_27 = V_20 -> V_28 ;
V_146 = F_41 ( sizeof( struct V_162 ) + 500 ,
V_152 ) ;
if ( V_146 == NULL ) {
V_34 = - V_72 ;
goto V_163;
}
V_34 = F_42 ( V_146 , & V_89 , V_20 ,
V_141 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_20 ,
V_34 ) ;
goto V_163;
}
if ( V_147 ) {
F_7 ( V_117 , L_19 ) ;
V_34 = - V_164 ;
F_38 ( V_146 ) ;
goto V_163;
} else {
V_90 = V_146 ;
}
} else {
F_7 ( V_117 , L_21 ) ;
V_34 = - V_48 ;
goto V_163;
}
V_84 -> V_165 =
F_4 ( sizeof( struct V_142 ) -
1 - 4 ) ;
V_84 -> V_166 = F_4 ( V_89 ) ;
V_87 [ 1 ] . V_109 = V_90 ;
V_87 [ 1 ] . V_110 = V_89 ;
F_27 ( V_84 , V_89 - 1 ) ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 2 , & V_78 ,
V_167 | V_92 ) ;
F_38 ( V_90 ) ;
V_79 = (struct V_143 * ) V_87 [ 0 ] . V_109 ;
if ( V_78 != V_168 &&
V_79 -> V_2 . V_169 == V_170 ) {
if ( V_144 != V_145 ) {
F_7 ( V_117 , L_22 ) ;
goto V_163;
}
if ( F_43 ( struct V_143 , V_171 ) - 4 !=
F_2 ( V_79 -> V_165 ) ) {
F_7 ( V_117 , L_23 ,
F_2 ( V_79 -> V_165 ) ) ;
V_34 = - V_48 ;
goto V_163;
}
V_144 = V_157 ;
V_34 = 0 ;
V_20 -> V_28 = V_79 -> V_2 . V_27 ;
V_34 = F_44 ( V_79 -> V_171 ,
F_2 ( V_79 -> V_166 ) , V_20 ) ;
}
if ( V_34 != 0 )
goto V_163;
V_20 -> V_172 = F_2 ( V_79 -> V_173 ) ;
if ( V_20 -> V_172 & V_174 )
F_7 ( V_117 , L_24 ) ;
V_163:
F_22 ( V_78 , V_79 ) ;
if ( ( V_144 == V_157 ) && ( V_34 == 0 ) )
goto V_156;
if ( ! V_34 ) {
F_10 ( & V_21 -> V_175 ) ;
if ( V_21 -> V_29 && V_21 -> V_176 -> V_177 ) {
V_34 = V_21 -> V_176 -> V_177 ( V_20 ) ;
F_38 ( V_20 -> V_148 . V_149 ) ;
V_20 -> V_148 . V_149 = NULL ;
if ( V_34 ) {
F_7 ( V_45 ,
L_25 ) ;
F_13 ( & V_21 -> V_175 ) ;
goto V_178;
}
}
if ( ! V_21 -> V_179 ) {
V_21 -> V_180 = 0x2 ;
V_21 -> V_179 = true ;
}
F_13 ( & V_21 -> V_175 ) ;
F_7 ( V_45 , L_26 ) ;
F_45 ( & V_181 ) ;
V_20 -> V_47 = V_182 ;
V_20 -> V_59 = false ;
F_46 ( & V_181 ) ;
}
V_178:
if ( ! V_21 -> V_29 ) {
F_38 ( V_20 -> V_148 . V_149 ) ;
V_20 -> V_148 . V_149 = NULL ;
}
F_38 ( V_20 -> V_150 ) ;
return V_34 ;
}
int
F_47 ( const unsigned int V_82 , struct V_37 * V_20 )
{
struct V_183 * V_84 ;
int V_34 = 0 ;
struct V_38 * V_21 ;
F_7 ( V_45 , L_27 , V_20 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_20 -> V_59 )
goto V_184;
V_34 = F_18 ( V_185 , NULL , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_27 = V_20 -> V_28 ;
if ( V_21 -> V_29 )
V_84 -> V_2 . V_30 |= V_31 ;
V_34 = F_48 ( V_82 , V_20 , ( char * ) & V_84 -> V_2 , 0 ) ;
V_184:
return V_34 ;
}
static inline void F_49 ( struct V_4 * V_5 , T_3 V_186 )
{
F_21 ( & V_5 -> V_74 . V_75 . V_187 [ V_186 ] ) ;
}
static inline void F_50 ( struct V_4 * V_5 )
{
V_5 -> V_188 = 256 ;
V_5 -> V_189 = 1048576 ;
V_5 -> V_190 = 16777216 ;
}
int
F_15 ( const unsigned int V_82 , struct V_37 * V_20 , const char * V_191 ,
struct V_4 * V_5 , const struct V_35 * V_192 )
{
struct V_193 * V_84 ;
struct V_194 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_34 = 0 ;
int V_78 ;
int V_195 ;
struct V_38 * V_21 ;
T_1 * V_196 = NULL ;
F_7 ( V_45 , L_28 ) ;
if ( ( V_20 -> V_21 ) && V_191 )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_5 && V_5 -> V_197 )
return - V_198 ;
V_196 = F_39 ( V_199 * 2 , V_152 ) ;
if ( V_196 == NULL )
return - V_72 ;
V_195 = F_51 ( V_196 , V_191 , strlen ( V_191 ) , V_192 ) + 1 ;
V_195 *= 2 ;
if ( V_195 < 2 ) {
F_38 ( V_196 ) ;
return - V_200 ;
}
V_34 = F_18 ( V_39 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 ) {
F_38 ( V_196 ) ;
return V_34 ;
}
if ( V_5 == NULL ) {
V_84 -> V_2 . V_27 = V_20 -> V_28 ;
}
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
V_84 -> V_201 = F_4 ( sizeof( struct V_193 )
- 1 - 4 ) ;
V_84 -> V_202 = F_4 ( V_195 - 2 ) ;
V_87 [ 1 ] . V_109 = V_196 ;
V_87 [ 1 ] . V_110 = V_195 ;
F_27 ( V_84 , V_195 - 1 ) ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 2 , & V_78 , 0 ) ;
V_79 = (struct V_194 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 ) {
if ( V_5 ) {
F_49 ( V_5 , V_203 ) ;
V_5 -> V_59 = true ;
}
goto V_204;
}
if ( V_5 == NULL ) {
V_20 -> V_205 = V_79 -> V_2 . V_25 ;
goto V_206;
}
if ( V_79 -> V_207 & V_208 )
F_7 ( V_45 , L_29 ) ;
else if ( V_79 -> V_207 & V_209 ) {
V_5 -> V_210 = true ;
F_7 ( V_45 , L_30 ) ;
} else if ( V_79 -> V_207 & V_211 ) {
V_5 -> V_212 = true ;
F_7 ( V_45 , L_31 ) ;
} else {
F_7 ( V_117 , L_32 , V_79 -> V_207 ) ;
V_34 = - V_164 ;
goto V_204;
}
V_5 -> V_213 = F_30 ( V_79 -> V_214 ) ;
V_5 -> V_22 = V_79 -> V_104 ;
V_5 -> V_215 = F_30 ( V_79 -> V_216 ) ;
V_5 -> V_40 = V_182 ;
V_5 -> V_59 = false ;
V_5 -> V_26 = V_79 -> V_2 . V_25 ;
F_52 ( V_5 -> V_61 , V_191 , sizeof( V_5 -> V_61 ) ) ;
if ( ( V_79 -> V_104 & V_217 ) &&
( ( V_5 -> V_213 & V_218 ) == 0 ) )
F_7 ( V_117 , L_33 ) ;
F_50 ( V_5 ) ;
if ( V_5 -> V_20 -> V_21 -> V_176 -> V_219 )
V_34 = V_5 -> V_20 -> V_21 -> V_176 -> V_219 ( V_82 , V_5 ) ;
V_206:
F_22 ( V_78 , V_79 ) ;
F_38 ( V_196 ) ;
return V_34 ;
V_204:
if ( V_79 -> V_2 . V_169 == V_220 ) {
F_7 ( V_117 , L_34 , V_191 ) ;
V_5 -> V_197 = true ;
}
goto V_206;
}
int
F_53 ( const unsigned int V_82 , struct V_4 * V_5 )
{
struct V_221 * V_84 ;
int V_34 = 0 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
F_7 ( V_45 , L_35 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( ( V_5 -> V_59 ) || ( V_5 -> V_20 -> V_59 ) )
return 0 ;
V_34 = F_18 ( V_44 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_48 ( V_82 , V_20 , ( char * ) & V_84 -> V_2 , 0 ) ;
if ( V_34 )
F_49 ( V_5 , V_222 ) ;
return V_34 ;
}
static struct V_223 *
F_54 ( void )
{
struct V_223 * V_224 ;
V_224 = F_41 ( sizeof( struct V_223 ) , V_152 ) ;
if ( ! V_224 )
return NULL ;
V_224 -> V_225 . V_226 = F_4 ( F_43
( struct V_223 , V_227 ) ) ;
V_224 -> V_225 . V_228 = F_5 ( 16 ) ;
V_224 -> V_225 . V_229 = F_4 ( F_43
( struct V_223 , V_230 ) ) ;
V_224 -> V_225 . V_231 = F_4 ( 4 ) ;
V_224 -> V_230 [ 0 ] = 'D' ;
V_224 -> V_230 [ 1 ] = 'H' ;
V_224 -> V_230 [ 2 ] = 'n' ;
V_224 -> V_230 [ 3 ] = 'Q' ;
return V_224 ;
}
static struct V_223 *
F_55 ( struct V_232 * V_233 )
{
struct V_223 * V_224 ;
V_224 = F_41 ( sizeof( struct V_223 ) , V_152 ) ;
if ( ! V_224 )
return NULL ;
V_224 -> V_225 . V_226 = F_4 ( F_43
( struct V_223 , V_227 ) ) ;
V_224 -> V_225 . V_228 = F_5 ( 16 ) ;
V_224 -> V_225 . V_229 = F_4 ( F_43
( struct V_223 , V_230 ) ) ;
V_224 -> V_225 . V_231 = F_4 ( 4 ) ;
V_224 -> V_227 . V_234 . V_235 = V_233 -> V_236 ;
V_224 -> V_227 . V_234 . V_237 = V_233 -> V_238 ;
V_224 -> V_230 [ 0 ] = 'D' ;
V_224 -> V_230 [ 1 ] = 'H' ;
V_224 -> V_230 [ 2 ] = 'n' ;
V_224 -> V_230 [ 3 ] = 'C' ;
return V_224 ;
}
static T_7
F_56 ( struct V_38 * V_21 , struct V_239 * V_79 ,
unsigned int * V_240 )
{
char * V_241 ;
struct V_242 * V_243 ;
unsigned int V_244 = 0 ;
char * V_245 ;
V_241 = ( char * ) V_79 + 4 + F_30 ( V_79 -> V_246 ) ;
V_243 = (struct V_242 * ) V_241 ;
do {
V_243 = (struct V_242 * ) ( ( char * ) V_243 + V_244 ) ;
V_245 = F_2 ( V_243 -> V_229 ) + ( char * ) V_243 ;
if ( F_2 ( V_243 -> V_231 ) != 4 ||
strncmp ( V_245 , L_36 , 4 ) ) {
V_244 = F_30 ( V_243 -> V_247 ) ;
continue;
}
return V_21 -> V_176 -> V_248 ( V_243 , V_240 ) ;
} while ( V_244 != 0 );
return 0 ;
}
static int
F_57 ( struct V_38 * V_21 , struct V_86 * V_87 ,
unsigned int * V_249 , T_7 * V_250 )
{
struct V_251 * V_84 = V_87 [ 0 ] . V_109 ;
unsigned int V_252 = * V_249 ;
V_87 [ V_252 ] . V_109 = V_21 -> V_176 -> V_253 ( V_250 + 1 , * V_250 ) ;
if ( V_87 [ V_252 ] . V_109 == NULL )
return - V_72 ;
V_87 [ V_252 ] . V_110 = V_21 -> V_96 -> V_254 ;
V_84 -> V_255 = V_256 ;
if ( ! V_84 -> V_246 )
V_84 -> V_246 = F_5 (
sizeof( struct V_251 ) - 4 +
V_87 [ V_252 - 1 ] . V_110 ) ;
F_58 ( & V_84 -> V_257 ,
V_21 -> V_96 -> V_254 ) ;
F_27 ( & V_84 -> V_2 , V_21 -> V_96 -> V_254 ) ;
* V_249 = V_252 + 1 ;
return 0 ;
}
static int
F_59 ( struct V_86 * V_87 , unsigned int * V_249 ,
struct V_258 * V_259 )
{
struct V_251 * V_84 = V_87 [ 0 ] . V_109 ;
unsigned int V_252 = * V_249 ;
if ( V_259 -> V_260 ) {
V_87 [ V_252 ] . V_109 = F_55 ( V_259 -> V_233 ) ;
V_259 -> V_260 = false ;
} else
V_87 [ V_252 ] . V_109 = F_54 () ;
if ( V_87 [ V_252 ] . V_109 == NULL )
return - V_72 ;
V_87 [ V_252 ] . V_110 = sizeof( struct V_223 ) ;
if ( ! V_84 -> V_246 )
V_84 -> V_246 =
F_5 ( sizeof( struct V_251 ) - 4 +
V_87 [ 1 ] . V_110 ) ;
F_58 ( & V_84 -> V_257 , sizeof( struct V_223 ) ) ;
F_27 ( & V_84 -> V_2 , sizeof( struct V_223 ) ) ;
* V_249 = V_252 + 1 ;
return 0 ;
}
int
F_60 ( const unsigned int V_82 , struct V_258 * V_259 , T_1 * V_261 ,
T_7 * V_250 , struct V_262 * V_224 ,
struct V_263 * * V_264 )
{
struct V_251 * V_84 ;
struct V_239 * V_79 ;
struct V_38 * V_21 ;
struct V_4 * V_5 = V_259 -> V_5 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_86 V_87 [ 4 ] ;
int V_78 ;
int V_265 ;
T_1 * V_266 = NULL ;
int V_267 ;
int V_34 = 0 ;
unsigned int V_268 = 2 ;
T_8 V_269 = 0 ;
F_7 ( V_45 , L_37 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_43 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
if ( V_259 -> V_270 & V_271 )
V_269 |= V_272 ;
V_84 -> V_273 = V_274 ;
V_84 -> V_275 = F_5 ( V_259 -> V_276 ) ;
V_84 -> V_277 = F_5 ( V_269 ) ;
V_84 -> V_278 = V_279 ;
V_84 -> V_280 = F_5 ( V_259 -> V_281 ) ;
V_84 -> V_282 = F_5 ( V_259 -> V_270 & V_283 ) ;
V_265 = ( 2 * F_61 ( ( V_284 * ) V_261 , V_285 ) ) + 2 ;
V_84 -> V_229 = F_4 ( sizeof( struct V_251 ) - 4 ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_84 -> V_231 = F_4 ( V_265 - 2 ) ;
V_87 [ 0 ] . V_110 -- ;
if ( V_265 % 8 != 0 ) {
V_267 = V_265 / 8 * 8 ;
if ( V_267 < V_265 )
V_267 += 8 ;
V_266 = F_41 ( V_267 , V_152 ) ;
if ( ! V_266 )
return - V_72 ;
memcpy ( ( char * ) V_266 , ( const char * ) V_261 ,
V_265 ) ;
V_265 = V_267 ;
V_261 = V_266 ;
}
V_87 [ 1 ] . V_110 = V_265 ;
V_87 [ 1 ] . V_109 = V_261 ;
F_27 ( V_84 , V_265 - 1 ) ;
if ( ! V_21 -> V_286 )
* V_250 = V_287 ;
if ( ! ( V_21 -> V_22 & V_288 ) ||
* V_250 == V_287 )
V_84 -> V_255 = * V_250 ;
else {
V_34 = F_57 ( V_21 , V_87 , & V_268 , V_250 ) ;
if ( V_34 ) {
F_23 ( V_84 ) ;
F_38 ( V_266 ) ;
return V_34 ;
}
}
if ( * V_250 == V_289 ) {
if ( V_21 -> V_22 & V_288 ) {
struct V_242 * V_225 =
(struct V_242 * ) V_87 [ V_268 - 1 ] . V_109 ;
V_225 -> V_247 =
F_5 ( V_21 -> V_96 -> V_254 ) ;
}
V_34 = F_59 ( V_87 , & V_268 , V_259 ) ;
if ( V_34 ) {
F_23 ( V_84 ) ;
F_38 ( V_266 ) ;
F_38 ( V_87 [ V_268 - 1 ] . V_109 ) ;
return V_34 ;
}
}
V_34 = F_29 ( V_82 , V_20 , V_87 , V_268 , & V_78 , 0 ) ;
V_79 = (struct V_239 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 ) {
F_49 ( V_5 , V_290 ) ;
if ( V_264 )
* V_264 = F_62 ( V_79 , F_28 ( V_79 ) + 4 ,
V_152 ) ;
goto V_291;
}
V_259 -> V_233 -> V_236 = V_79 -> V_235 ;
V_259 -> V_233 -> V_238 = V_79 -> V_237 ;
if ( V_224 ) {
memcpy ( V_224 , & V_79 -> V_292 , 32 ) ;
V_224 -> V_293 = V_79 -> V_293 ;
V_224 -> V_294 = V_79 -> V_295 ;
V_224 -> V_296 = V_79 -> V_277 ;
V_224 -> V_297 = F_5 ( 1 ) ;
V_224 -> V_298 = 0 ;
}
if ( V_79 -> V_299 == V_256 )
* V_250 = F_56 ( V_21 , V_79 , & V_259 -> V_233 -> V_240 ) ;
else
* V_250 = V_79 -> V_299 ;
V_291:
F_38 ( V_266 ) ;
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
int
F_36 ( const unsigned int V_82 , struct V_4 * V_5 , T_9 V_236 ,
T_9 V_238 , T_4 V_300 , bool V_301 , char * V_302 ,
T_4 V_303 , char * * V_304 , T_4 * V_305 )
{
struct V_306 * V_84 ;
struct V_307 * V_79 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_86 V_87 [ 2 ] ;
int V_78 ;
int V_268 ;
int V_34 = 0 ;
F_7 ( V_45 , L_38 ) ;
* V_304 = NULL ;
if ( V_305 )
* V_305 = 0 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_66 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_308 = F_5 ( V_300 ) ;
V_84 -> V_235 = V_236 ;
V_84 -> V_237 = V_238 ;
if ( V_303 ) {
V_84 -> V_309 = F_5 ( V_303 ) ;
V_84 -> V_310 =
F_5 ( F_43 ( struct V_306 , V_171 ) - 4 ) ;
V_87 [ 1 ] . V_109 = V_302 ;
V_87 [ 1 ] . V_110 = V_303 ;
V_268 = 2 ;
} else
V_268 = 1 ;
V_84 -> V_311 = 0 ;
V_84 -> V_312 = 0 ;
V_84 -> V_313 = F_5 ( 0xFF00 ) ;
if ( V_301 )
V_84 -> V_30 = F_5 ( V_314 ) ;
else
V_84 -> V_30 = 0 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
if ( V_303 ) {
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
F_27 ( V_84 , V_303 - 1 ) ;
} else
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , V_268 , & V_78 , 0 ) ;
V_79 = (struct V_307 * ) V_87 [ 0 ] . V_109 ;
if ( ( V_34 != 0 ) && ( V_34 != - V_200 ) ) {
if ( V_5 )
F_49 ( V_5 , V_315 ) ;
goto V_316;
} else if ( V_34 == - V_200 ) {
if ( ( V_300 != V_317 ) &&
( V_300 != V_318 ) ) {
if ( V_5 )
F_49 ( V_5 , V_315 ) ;
goto V_316;
}
}
if ( ( V_305 == NULL ) || ( V_304 == NULL ) )
goto V_316;
* V_305 = F_30 ( V_79 -> V_312 ) ;
if ( * V_305 == 0 )
goto V_316;
else if ( * V_305 > 0xFF00 ) {
F_7 ( V_117 , L_39 , * V_305 ) ;
* V_305 = 0 ;
V_34 = - V_48 ;
goto V_316;
}
if ( F_28 ( V_79 ) < F_30 ( V_79 -> V_311 ) + * V_305 ) {
F_7 ( V_117 , L_40 , * V_305 ,
F_30 ( V_79 -> V_311 ) ) ;
* V_305 = 0 ;
V_34 = - V_48 ;
goto V_316;
}
* V_304 = F_39 ( * V_305 , V_152 ) ;
if ( * V_304 == NULL ) {
V_34 = - V_72 ;
goto V_316;
}
memcpy ( * V_304 , V_79 -> V_2 . V_12 + F_30 ( V_79 -> V_311 ) ,
* V_305 ) ;
V_316:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
int
F_63 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_236 , T_9 V_238 )
{
int V_34 ;
char * V_319 = NULL ;
struct V_320 V_321 ;
char * V_322 = NULL ;
V_321 . V_323 =
F_64 ( V_324 ) ;
V_34 = F_36 ( V_82 , V_5 , V_236 , V_238 ,
V_325 , true ,
( char * ) & V_321 ,
2 , & V_322 , NULL ) ;
F_7 ( V_45 , L_41 , V_34 ) ;
F_38 ( V_319 ) ;
return V_34 ;
}
int
F_65 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_236 , T_9 V_238 )
{
struct V_326 * V_84 ;
struct V_327 * V_79 ;
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
V_34 = F_18 ( V_52 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_235 = V_236 ;
V_84 -> V_237 = V_238 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , 0 ) ;
V_79 = (struct V_327 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 ) {
if ( V_5 )
F_49 ( V_5 , V_328 ) ;
goto V_329;
}
V_329:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
static int
F_66 ( unsigned int V_330 , unsigned int V_331 ,
struct V_1 * V_2 , unsigned int V_332 )
{
unsigned int V_333 = F_67 ( V_2 -> V_11 ) ;
char * V_334 = V_333 + 4 + ( char * ) V_2 ;
char * V_335 = 4 + V_330 + ( char * ) V_2 ;
char * V_336 = V_335 + V_331 ;
if ( V_331 < V_332 ) {
F_7 ( V_117 , L_43 ,
V_331 , V_332 ) ;
return - V_200 ;
}
if ( ( V_333 > 0x7FFFFF ) || ( V_331 > 0x7FFFFF ) ) {
F_7 ( V_117 , L_44 ,
V_331 , V_333 ) ;
return - V_200 ;
}
if ( ( V_335 > V_334 ) || ( V_336 > V_334 ) ) {
F_7 ( V_117 , L_45 ) ;
return - V_200 ;
}
return 0 ;
}
static int
F_68 ( unsigned int V_330 , unsigned int V_331 ,
struct V_1 * V_2 , unsigned int V_337 ,
char * V_338 )
{
char * V_335 = 4 + V_330 + ( char * ) V_2 ;
int V_34 ;
if ( ! V_338 )
return - V_200 ;
V_34 = F_66 ( V_330 , V_331 , V_2 , V_337 ) ;
if ( V_34 )
return V_34 ;
memcpy ( V_338 , V_335 , V_331 ) ;
return 0 ;
}
static int
F_69 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_236 , T_9 V_238 , T_10 V_339 ,
T_11 V_340 , T_11 V_341 , void * V_338 )
{
struct V_342 * V_84 ;
struct V_343 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_34 = 0 ;
int V_78 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
F_7 ( V_45 , L_46 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_344 = V_345 ;
V_84 -> V_346 = V_339 ;
V_84 -> V_235 = V_236 ;
V_84 -> V_237 = V_238 ;
V_84 -> V_347 =
F_4 ( sizeof( struct V_342 ) - 1 - 4 ) ;
V_84 -> V_348 = F_5 ( V_340 ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , 0 ) ;
V_79 = (struct V_343 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 ) {
F_49 ( V_5 , V_349 ) ;
goto V_350;
}
V_34 = F_68 ( F_2 ( V_79 -> V_351 ) ,
F_30 ( V_79 -> V_348 ) ,
& V_79 -> V_2 , V_341 , V_338 ) ;
V_350:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
int
F_70 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_236 , T_9 V_238 ,
struct V_262 * V_338 )
{
return F_69 ( V_82 , V_5 , V_236 , V_238 ,
V_352 ,
sizeof( struct V_262 ) + V_353 * 2 ,
sizeof( struct V_262 ) , V_338 ) ;
}
int
F_71 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_236 , T_9 V_238 , T_12 * V_354 )
{
return F_69 ( V_82 , V_5 , V_236 , V_238 ,
V_355 ,
sizeof( struct V_356 ) ,
sizeof( struct V_356 ) , V_354 ) ;
}
static void
F_72 ( struct V_357 * V_358 )
{
struct V_38 * V_21 = V_358 -> V_359 ;
struct V_360 * V_361 = (struct V_360 * ) V_358 -> V_362 ;
unsigned int V_363 = 1 ;
if ( V_358 -> V_364 == V_365 )
V_363 = F_2 ( V_361 -> V_2 . V_15 ) ;
F_73 ( V_358 ) ;
F_74 ( V_21 , V_363 , V_366 ) ;
}
int
F_75 ( struct V_38 * V_21 )
{
struct V_367 * V_84 ;
int V_34 = 0 ;
struct V_86 V_87 ;
struct V_368 V_369 = { . V_370 = & V_87 ,
. V_371 = 1 } ;
F_7 ( V_45 , L_47 ) ;
V_34 = F_18 ( V_372 , NULL , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_15 = F_4 ( 1 ) ;
V_87 . V_109 = ( char * ) V_84 ;
V_87 . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_76 ( V_21 , & V_369 , NULL , F_72 , V_21 ,
V_366 ) ;
if ( V_34 )
F_7 ( V_45 , L_48 , V_34 ) ;
F_23 ( V_84 ) ;
return V_34 ;
}
int
F_77 ( const unsigned int V_82 , struct V_4 * V_5 , T_9 V_236 ,
T_9 V_238 )
{
struct V_373 * V_84 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_86 V_87 [ 1 ] ;
int V_78 ;
int V_34 = 0 ;
F_7 ( V_45 , L_49 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_63 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_235 = V_236 ;
V_84 -> V_237 = V_238 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , 0 ) ;
if ( ( V_34 != 0 ) && V_5 )
F_49 ( V_5 , V_374 ) ;
F_22 ( V_78 , V_87 [ 0 ] . V_109 ) ;
return V_34 ;
}
static int
F_78 ( struct V_86 * V_87 , struct V_375 * V_376 ,
unsigned int V_377 , int V_378 )
{
int V_34 = - V_379 ;
struct V_380 * V_84 = NULL ;
V_34 = F_18 ( V_64 , V_376 -> V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
if ( V_376 -> V_5 -> V_20 -> V_21 == NULL )
return - V_381 ;
V_84 -> V_2 . V_16 = F_5 ( V_376 -> V_382 ) ;
V_84 -> V_235 = V_376 -> V_236 ;
V_84 -> V_237 = V_376 -> V_238 ;
V_84 -> V_383 = 0 ;
V_84 -> V_384 = 0 ;
V_84 -> V_161 = 0 ;
V_84 -> V_385 = 0 ;
V_84 -> V_386 = F_5 ( V_376 -> V_387 ) ;
V_84 -> V_388 = F_79 ( V_376 -> V_330 ) ;
if ( V_378 & V_389 ) {
if ( ! ( V_378 & V_390 ) ) {
V_84 -> V_2 . V_391 =
F_5 ( F_28 ( V_84 ) + 4 ) ;
} else
V_84 -> V_2 . V_391 = 0 ;
if ( V_378 & V_392 ) {
V_84 -> V_2 . V_30 |= V_393 ;
V_84 -> V_2 . V_27 = 0xFFFFFFFF ;
V_84 -> V_2 . V_25 = 0xFFFFFFFF ;
V_84 -> V_235 = 0xFFFFFFFF ;
V_84 -> V_237 = 0xFFFFFFFF ;
}
}
if ( V_377 > V_376 -> V_387 )
V_84 -> V_394 = F_5 ( V_377 ) ;
else
V_84 -> V_394 = 0 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
return V_34 ;
}
static void
F_80 ( struct V_357 * V_358 )
{
struct V_395 * V_396 = V_358 -> V_359 ;
struct V_4 * V_5 = F_81 ( V_396 -> V_397 -> V_398 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_1 * V_224 = (struct V_1 * ) V_396 -> V_87 . V_109 ;
unsigned int V_363 = 1 ;
struct V_368 V_369 = { . V_370 = & V_396 -> V_87 ,
. V_371 = 1 ,
. V_399 = V_396 -> V_400 ,
. V_401 = V_396 -> V_402 ,
. V_403 = V_396 -> V_404 ,
. V_405 = V_396 -> V_406 } ;
F_7 ( V_45 , L_50 ,
V_93 , V_358 -> V_358 , V_358 -> V_364 , V_396 -> V_407 ,
V_396 -> V_408 ) ;
switch ( V_358 -> V_364 ) {
case V_365 :
V_363 = F_2 ( V_224 -> V_15 ) ;
if ( V_21 -> V_29 ) {
int V_34 ;
V_34 = F_82 ( & V_369 , V_21 ) ;
if ( V_34 )
F_7 ( V_117 , L_51 ,
V_34 ) ;
}
F_83 ( V_396 -> V_408 ) ;
F_84 ( V_5 , V_396 -> V_408 ) ;
break;
case V_409 :
case V_410 :
V_396 -> V_407 = - V_54 ;
break;
default:
if ( V_396 -> V_407 != - V_411 )
V_396 -> V_407 = - V_48 ;
}
if ( V_396 -> V_407 )
F_49 ( V_5 , V_412 ) ;
F_85 ( V_413 , & V_396 -> V_414 ) ;
F_73 ( V_358 ) ;
F_74 ( V_21 , V_363 , 0 ) ;
}
int
F_86 ( struct V_395 * V_396 )
{
int V_34 ;
struct V_1 * V_224 ;
struct V_375 V_376 ;
struct V_368 V_369 = { . V_370 = & V_396 -> V_87 ,
. V_371 = 1 } ;
F_7 ( V_45 , L_52 ,
V_93 , V_396 -> V_330 , V_396 -> V_408 ) ;
V_376 . V_5 = F_81 ( V_396 -> V_397 -> V_398 ) ;
V_376 . V_330 = V_396 -> V_330 ;
V_376 . V_387 = V_396 -> V_408 ;
V_376 . V_236 = V_396 -> V_397 -> V_233 . V_236 ;
V_376 . V_238 = V_396 -> V_397 -> V_233 . V_238 ;
V_376 . V_382 = V_396 -> V_382 ;
V_34 = F_78 ( & V_396 -> V_87 , & V_376 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_224 = (struct V_1 * ) V_396 -> V_87 . V_109 ;
V_396 -> V_87 . V_110 = F_28 ( V_396 -> V_87 . V_109 ) + 4 ;
F_87 ( & V_396 -> V_415 ) ;
V_34 = F_76 ( V_376 . V_5 -> V_20 -> V_21 , & V_369 ,
V_416 , F_80 ,
V_396 , 0 ) ;
if ( V_34 ) {
F_88 ( & V_396 -> V_415 , V_417 ) ;
F_49 ( V_376 . V_5 , V_412 ) ;
}
F_23 ( V_224 ) ;
return V_34 ;
}
int
F_89 ( const unsigned int V_82 , struct V_375 * V_376 ,
unsigned int * V_418 , char * * V_224 , int * V_419 )
{
int V_78 , V_34 = - V_379 ;
struct V_420 * V_79 = NULL ;
struct V_86 V_87 [ 1 ] ;
* V_418 = 0 ;
V_34 = F_78 ( V_87 , V_376 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_29 ( V_82 , V_376 -> V_5 -> V_20 , V_87 , 1 ,
& V_78 , V_167 ) ;
V_79 = (struct V_420 * ) V_87 [ 0 ] . V_109 ;
if ( V_79 -> V_2 . V_169 == V_421 ) {
F_22 ( V_78 , V_87 [ 0 ] . V_109 ) ;
return 0 ;
}
if ( V_34 ) {
F_49 ( V_376 -> V_5 , V_412 ) ;
F_7 ( V_117 , L_53 , V_34 ) ;
} else {
* V_418 = F_30 ( V_79 -> V_228 ) ;
if ( ( * V_418 > V_422 ) ||
( * V_418 > V_376 -> V_387 ) ) {
F_7 ( V_45 , L_54 ,
* V_418 , V_376 -> V_387 ) ;
V_34 = - V_48 ;
* V_418 = 0 ;
}
}
if ( * V_224 ) {
memcpy ( * V_224 , ( char * ) V_79 -> V_2 . V_12 + V_79 -> V_226 ,
* V_418 ) ;
F_22 ( V_78 , V_87 [ 0 ] . V_109 ) ;
} else if ( V_78 != V_168 ) {
* V_224 = V_87 [ 0 ] . V_109 ;
if ( V_78 == V_80 )
* V_419 = V_80 ;
else if ( V_78 == V_81 )
* V_419 = V_81 ;
}
return V_34 ;
}
static void
F_90 ( struct V_357 * V_358 )
{
struct V_423 * V_424 = V_358 -> V_359 ;
struct V_4 * V_5 = F_81 ( V_424 -> V_397 -> V_398 ) ;
unsigned int V_425 ;
struct V_426 * V_79 = (struct V_426 * ) V_358 -> V_362 ;
unsigned int V_363 = 1 ;
switch ( V_358 -> V_364 ) {
case V_365 :
V_363 = F_2 ( V_79 -> V_2 . V_15 ) ;
V_424 -> V_407 = F_91 ( V_358 , V_5 -> V_20 -> V_21 , 0 ) ;
if ( V_424 -> V_407 != 0 )
break;
V_425 = F_30 ( V_79 -> V_228 ) ;
if ( V_425 > V_424 -> V_408 )
V_425 &= 0xFFFF ;
if ( V_425 < V_424 -> V_408 )
V_424 -> V_407 = - V_427 ;
else
V_424 -> V_408 = V_425 ;
break;
case V_409 :
case V_410 :
V_424 -> V_407 = - V_54 ;
break;
default:
V_424 -> V_407 = - V_48 ;
break;
}
if ( V_424 -> V_407 )
F_49 ( V_5 , V_428 ) ;
F_85 ( V_413 , & V_424 -> V_414 ) ;
F_73 ( V_358 ) ;
F_74 ( V_5 -> V_20 -> V_21 , V_363 , 0 ) ;
}
int
F_92 ( struct V_423 * V_424 )
{
int V_34 = - V_379 ;
struct V_429 * V_84 = NULL ;
struct V_4 * V_5 = F_81 ( V_424 -> V_397 -> V_398 ) ;
struct V_86 V_87 ;
struct V_368 V_369 ;
V_34 = F_18 ( V_42 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
goto V_430;
V_84 -> V_2 . V_16 = F_5 ( V_424 -> V_397 -> V_382 ) ;
V_84 -> V_235 = V_424 -> V_397 -> V_233 . V_236 ;
V_84 -> V_237 = V_424 -> V_397 -> V_233 . V_238 ;
V_84 -> V_431 = 0 ;
V_84 -> V_432 = 0 ;
V_84 -> V_161 = 0 ;
V_84 -> V_388 = F_79 ( V_424 -> V_330 ) ;
V_84 -> V_226 = F_4 (
F_43 ( struct V_429 , V_171 ) - 4 ) ;
V_84 -> V_394 = 0 ;
V_87 . V_110 = F_28 ( V_84 ) + 4 - 1 ;
V_87 . V_109 = V_84 ;
V_369 . V_370 = & V_87 ;
V_369 . V_371 = 1 ;
V_369 . V_399 = V_424 -> V_400 ;
V_369 . V_401 = V_424 -> V_402 ;
V_369 . V_403 = V_424 -> V_404 ;
V_369 . V_405 = V_424 -> V_406 ;
F_7 ( V_45 , L_55 ,
V_424 -> V_330 , V_424 -> V_408 ) ;
V_84 -> V_386 = F_5 ( V_424 -> V_408 ) ;
F_27 ( & V_84 -> V_2 , V_424 -> V_408 - 1 ) ;
F_87 ( & V_424 -> V_415 ) ;
V_34 = F_76 ( V_5 -> V_20 -> V_21 , & V_369 , NULL ,
F_90 , V_424 , 0 ) ;
if ( V_34 ) {
F_88 ( & V_424 -> V_415 , V_433 ) ;
F_49 ( V_5 , V_428 ) ;
}
V_430:
F_23 ( V_84 ) ;
return V_34 ;
}
int
F_93 ( const unsigned int V_82 , struct V_375 * V_376 ,
unsigned int * V_418 , struct V_86 * V_87 , int V_434 )
{
int V_34 = 0 ;
struct V_429 * V_84 = NULL ;
struct V_426 * V_79 = NULL ;
int V_78 ;
* V_418 = 0 ;
if ( V_434 < 1 )
return V_34 ;
V_34 = F_18 ( V_42 , V_376 -> V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
if ( V_376 -> V_5 -> V_20 -> V_21 == NULL )
return - V_381 ;
V_84 -> V_2 . V_16 = F_5 ( V_376 -> V_382 ) ;
V_84 -> V_235 = V_376 -> V_236 ;
V_84 -> V_237 = V_376 -> V_238 ;
V_84 -> V_431 = 0 ;
V_84 -> V_432 = 0 ;
V_84 -> V_161 = 0 ;
V_84 -> V_386 = F_5 ( V_376 -> V_387 ) ;
V_84 -> V_388 = F_79 ( V_376 -> V_330 ) ;
V_84 -> V_226 = F_4 (
F_43 ( struct V_429 , V_171 ) - 4 ) ;
V_84 -> V_394 = 0 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
F_27 ( V_84 , V_376 -> V_387 - 1 ) ;
V_34 = F_29 ( V_82 , V_376 -> V_5 -> V_20 , V_87 , V_434 + 1 ,
& V_78 , 0 ) ;
V_79 = (struct V_426 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 ) {
F_49 ( V_376 -> V_5 , V_428 ) ;
F_7 ( V_117 , L_56 , V_34 ) ;
} else
* V_418 = F_30 ( V_79 -> V_228 ) ;
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
static unsigned int
F_94 ( char * V_435 , char * V_336 , char * * V_436 , T_11 V_437 )
{
int V_438 ;
unsigned int V_439 = 0 ;
unsigned int V_440 = 0 ;
T_13 * V_441 ;
if ( V_435 == NULL )
return 0 ;
V_441 = ( T_13 * ) V_435 ;
while ( 1 ) {
V_441 = ( T_13 * )
( ( char * ) V_441 + V_440 ) ;
if ( ( char * ) V_441 + V_437 > V_336 ) {
F_7 ( V_117 , L_57 ) ;
break;
}
V_438 = F_30 ( V_441 -> V_442 ) ;
if ( ( char * ) V_441 + V_438 + V_437 > V_336 ) {
F_7 ( V_117 , L_58 ,
V_336 ) ;
break;
}
* V_436 = ( char * ) V_441 ;
V_439 ++ ;
V_440 = F_30 ( V_441 -> V_443 ) ;
if ( ! V_440 )
break;
}
return V_439 ;
}
int
F_95 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_236 , T_9 V_238 , int V_444 ,
struct V_445 * V_446 )
{
struct V_447 * V_84 ;
struct V_448 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_34 = 0 ;
int V_438 ;
int V_78 ;
unsigned char * V_449 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
T_1 V_450 = F_4 ( '*' ) ;
char * V_334 ;
unsigned int V_451 = V_452 ;
T_11 V_453 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_67 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
switch ( V_446 -> V_454 ) {
case V_455 :
V_84 -> V_456 = V_457 ;
V_453 = sizeof( T_13 ) - 1 ;
break;
case V_458 :
V_84 -> V_456 = V_459 ;
V_453 = sizeof( V_460 ) - 1 ;
break;
default:
F_7 ( V_117 , L_59 ,
V_446 -> V_454 ) ;
V_34 = - V_200 ;
goto V_461;
}
V_84 -> V_462 = F_5 ( V_444 ) ;
V_84 -> V_235 = V_236 ;
V_84 -> V_237 = V_238 ;
V_438 = 0x2 ;
V_449 = V_84 -> V_171 ;
memcpy ( V_449 , & V_450 , V_438 ) ;
V_84 -> V_463 =
F_4 ( sizeof( struct V_447 ) - 1 - 4 ) ;
V_84 -> V_442 = F_4 ( V_438 ) ;
V_451 = F_96 (unsigned int, output_size, server->maxBuf) ;
V_451 = F_96 (unsigned int, output_size, 2 << 15 ) ;
V_84 -> V_348 = F_5 ( V_451 ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
V_87 [ 1 ] . V_109 = ( char * ) ( V_84 -> V_171 ) ;
V_87 [ 1 ] . V_110 = V_438 ;
F_27 ( V_84 , V_438 - 1 ) ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 2 , & V_78 , 0 ) ;
V_79 = (struct V_448 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 ) {
F_49 ( V_5 , V_464 ) ;
goto V_461;
}
V_34 = F_66 ( F_2 ( V_79 -> V_351 ) ,
F_30 ( V_79 -> V_348 ) , & V_79 -> V_2 ,
V_453 ) ;
if ( V_34 )
goto V_461;
V_446 -> V_465 = true ;
if ( V_446 -> V_466 ) {
if ( V_446 -> V_467 )
F_23 ( V_446 -> V_466 ) ;
else
F_24 ( V_446 -> V_466 ) ;
}
V_446 -> V_466 = ( char * ) V_79 ;
V_446 -> V_468 = V_446 -> V_469 = 4 +
( char * ) & V_79 -> V_2 + F_2 ( V_79 -> V_351 ) ;
V_334 = F_28 ( V_79 ) + 4 + ( char * ) & V_79 -> V_2 ;
V_446 -> V_470 =
F_94 ( V_446 -> V_468 , V_334 ,
& V_446 -> V_469 , V_453 ) ;
V_446 -> V_471 += V_446 -> V_470 ;
F_7 ( V_45 , L_60 ,
V_446 -> V_470 , V_446 -> V_471 ,
V_446 -> V_468 , V_446 -> V_469 ) ;
if ( V_78 == V_81 )
V_446 -> V_467 = false ;
else if ( V_78 == V_80 )
V_446 -> V_467 = true ;
else
F_7 ( V_117 , L_61 ) ;
if ( V_79 -> V_2 . V_169 == V_472 )
V_446 -> V_473 = 1 ;
else
V_446 -> V_473 = 0 ;
return V_34 ;
V_461:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
static int
F_97 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_236 , T_9 V_238 , T_4 V_382 , int V_339 ,
unsigned int V_252 , void * * V_338 , unsigned int * V_437 )
{
struct V_474 * V_84 ;
struct V_475 * V_79 = NULL ;
struct V_86 * V_87 ;
int V_34 = 0 ;
int V_78 ;
unsigned int V_476 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( ! V_252 )
return - V_200 ;
V_87 = F_39 ( sizeof( struct V_86 ) * V_252 , V_152 ) ;
if ( ! V_87 )
return - V_72 ;
V_34 = F_18 ( V_70 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 ) {
F_38 ( V_87 ) ;
return V_34 ;
}
V_84 -> V_2 . V_16 = F_5 ( V_382 ) ;
V_84 -> V_344 = V_345 ;
V_84 -> V_346 = V_339 ;
V_84 -> V_235 = V_236 ;
V_84 -> V_237 = V_238 ;
V_84 -> V_477 =
F_4 ( sizeof( struct V_474 ) - 1 - 4 ) ;
V_84 -> V_478 = F_5 ( * V_437 ) ;
F_27 ( V_84 , * V_437 - 1 ) ;
memcpy ( V_84 -> V_171 , * V_338 , * V_437 ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
for ( V_476 = 1 ; V_476 < V_252 ; V_476 ++ ) {
F_27 ( V_84 , V_437 [ V_476 ] ) ;
F_58 ( & V_84 -> V_478 , V_437 [ V_476 ] ) ;
V_87 [ V_476 ] . V_109 = ( char * ) V_338 [ V_476 ] ;
V_87 [ V_476 ] . V_110 = V_437 [ V_476 ] ;
}
V_34 = F_29 ( V_82 , V_20 , V_87 , V_252 , & V_78 , 0 ) ;
V_79 = (struct V_475 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 )
F_49 ( V_5 , V_479 ) ;
F_22 ( V_78 , V_79 ) ;
F_38 ( V_87 ) ;
return V_34 ;
}
int
F_98 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_236 , T_9 V_238 , T_1 * V_480 )
{
struct V_481 V_482 ;
void * * V_338 ;
unsigned int V_437 [ 2 ] ;
int V_34 ;
int V_438 = ( 2 * F_61 ( ( V_284 * ) V_480 , V_285 ) ) ;
V_338 = F_39 ( sizeof( void * ) * 2 , V_152 ) ;
if ( ! V_338 )
return - V_72 ;
V_482 . V_483 = 1 ;
V_482 . V_484 = 0 ;
V_482 . V_442 = F_5 ( V_438 ) ;
V_338 [ 0 ] = & V_482 ;
V_437 [ 0 ] = sizeof( struct V_481 ) ;
V_338 [ 1 ] = V_480 ;
V_437 [ 1 ] = V_438 + 2 ;
V_34 = F_97 ( V_82 , V_5 , V_236 , V_238 ,
V_17 -> V_18 , V_485 , 2 , V_338 ,
V_437 ) ;
F_38 ( V_338 ) ;
return V_34 ;
}
int
F_99 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_236 , T_9 V_238 , T_1 * V_480 )
{
struct V_486 V_482 ;
void * * V_338 ;
unsigned int V_437 [ 2 ] ;
int V_34 ;
int V_438 = ( 2 * F_61 ( ( V_284 * ) V_480 , V_285 ) ) ;
V_338 = F_39 ( sizeof( void * ) * 2 , V_152 ) ;
if ( ! V_338 )
return - V_72 ;
V_482 . V_483 = 0 ;
V_482 . V_484 = 0 ;
V_482 . V_442 = F_5 ( V_438 ) ;
V_338 [ 0 ] = & V_482 ;
V_437 [ 0 ] = sizeof( struct V_486 ) ;
V_338 [ 1 ] = V_480 ;
V_437 [ 1 ] = V_438 + 2 ;
V_34 = F_97 ( V_82 , V_5 , V_236 , V_238 ,
V_17 -> V_18 , V_487 , 2 , V_338 , V_437 ) ;
F_38 ( V_338 ) ;
return V_34 ;
}
int
F_100 ( const unsigned int V_82 , struct V_4 * V_5 , T_9 V_236 ,
T_9 V_238 , T_4 V_382 , T_12 * V_488 )
{
struct V_489 V_482 ;
void * V_338 ;
unsigned int V_437 ;
V_482 . V_294 = * V_488 ;
V_338 = & V_482 ;
V_437 = sizeof( struct V_489 ) ;
return F_97 ( V_82 , V_5 , V_236 , V_238 , V_382 ,
V_490 , 1 , & V_338 , & V_437 ) ;
}
int
F_101 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_236 , T_9 V_238 , T_14 * V_224 )
{
unsigned int V_437 ;
V_437 = sizeof( T_14 ) ;
return F_97 ( V_82 , V_5 , V_236 , V_238 ,
V_17 -> V_18 , V_491 , 1 ,
( void * * ) & V_224 , & V_437 ) ;
}
int
F_102 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_9 V_236 , const T_9 V_238 ,
T_7 V_492 )
{
int V_34 ;
struct V_493 * V_84 = NULL ;
F_7 ( V_45 , L_62 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_494 = V_238 ;
V_84 -> V_495 = V_236 ;
V_84 -> V_299 = V_492 ;
V_84 -> V_2 . V_15 = F_4 ( 1 ) ;
V_34 = F_48 ( V_82 , V_5 -> V_20 , ( char * ) V_84 , V_496 ) ;
if ( V_34 ) {
F_49 ( V_5 , V_497 ) ;
F_7 ( V_45 , L_63 , V_34 ) ;
}
return V_34 ;
}
static void
F_103 ( struct V_498 * V_499 ,
struct V_500 * V_501 )
{
V_501 -> V_502 = F_30 ( V_499 -> V_503 ) *
F_30 ( V_499 -> V_504 ) ;
V_501 -> V_505 = F_104 ( V_499 -> V_506 ) ;
V_501 -> V_507 = F_104 ( V_499 -> V_508 ) ;
V_501 -> V_509 = F_104 ( V_499 -> V_510 ) ;
return;
}
static int
F_105 ( struct V_86 * V_87 , struct V_4 * V_5 , int V_511 ,
int V_512 , T_9 V_236 , T_9 V_238 )
{
int V_34 ;
struct V_342 * V_84 ;
F_7 ( V_45 , L_64 , V_511 ) ;
if ( ( V_5 -> V_20 == NULL ) || ( V_5 -> V_20 -> V_21 == NULL ) )
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_344 = V_513 ;
V_84 -> V_346 = V_511 ;
V_84 -> V_235 = V_236 ;
V_84 -> V_237 = V_238 ;
V_84 -> V_347 =
F_4 ( sizeof( struct V_342 ) - 1 - 4 ) ;
V_84 -> V_348 = F_5 (
V_512 + sizeof( struct V_343 ) - 1 - 4 ) ;
V_87 -> V_109 = ( char * ) V_84 ;
V_87 -> V_110 = F_28 ( V_84 ) + 4 ;
return 0 ;
}
int
F_106 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_236 , T_9 V_238 , struct V_500 * V_514 )
{
struct V_343 * V_79 = NULL ;
struct V_86 V_87 ;
int V_34 = 0 ;
int V_78 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_498 * V_482 = NULL ;
V_34 = F_105 ( & V_87 , V_5 , V_515 ,
sizeof( struct V_498 ) ,
V_236 , V_238 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_29 ( V_82 , V_20 , & V_87 , 1 , & V_78 , 0 ) ;
if ( V_34 ) {
F_49 ( V_5 , V_349 ) ;
goto V_516;
}
V_79 = (struct V_343 * ) V_87 . V_109 ;
V_482 = (struct V_498 * ) ( 4 +
F_2 ( V_79 -> V_351 ) + ( char * ) & V_79 -> V_2 ) ;
V_34 = F_66 ( F_2 ( V_79 -> V_351 ) ,
F_30 ( V_79 -> V_348 ) , & V_79 -> V_2 ,
sizeof( struct V_498 ) ) ;
if ( ! V_34 )
F_103 ( V_482 , V_514 ) ;
V_516:
F_22 ( V_78 , V_87 . V_109 ) ;
return V_34 ;
}
int
F_107 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_236 , T_9 V_238 , int V_511 )
{
struct V_343 * V_79 = NULL ;
struct V_86 V_87 ;
int V_34 = 0 ;
int V_78 , V_517 , V_341 ;
struct V_37 * V_20 = V_5 -> V_20 ;
unsigned int V_518 , V_330 ;
if ( V_511 == V_519 ) {
V_517 = sizeof( V_520 ) ;
V_341 = sizeof( V_520 ) ;
} else if ( V_511 == V_521 ) {
V_517 = sizeof( V_522 ) ;
V_341 = V_523 ;
} else if ( V_511 == V_524 ) {
V_517 = sizeof( struct V_525 ) ;
V_341 = sizeof( struct V_525 ) ;
} else {
F_7 ( V_45 , L_65 , V_511 ) ;
return - V_200 ;
}
V_34 = F_105 ( & V_87 , V_5 , V_511 , V_517 ,
V_236 , V_238 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_29 ( V_82 , V_20 , & V_87 , 1 , & V_78 , 0 ) ;
if ( V_34 ) {
F_49 ( V_5 , V_349 ) ;
goto V_526;
}
V_79 = (struct V_343 * ) V_87 . V_109 ;
V_518 = F_30 ( V_79 -> V_348 ) ;
V_330 = F_2 ( V_79 -> V_351 ) ;
V_34 = F_66 ( V_330 , V_518 , & V_79 -> V_2 , V_341 ) ;
if ( V_34 )
goto V_526;
if ( V_511 == V_521 )
memcpy ( & V_5 -> V_527 , 4 + V_330
+ ( char * ) & V_79 -> V_2 , F_96 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_511 == V_519 )
memcpy ( & V_5 -> V_528 , 4 + V_330
+ ( char * ) & V_79 -> V_2 , sizeof( V_520 ) ) ;
else if ( V_511 == V_524 ) {
struct V_525 * V_529 = (struct V_525 * )
( 4 + V_330 + ( char * ) & V_79 -> V_2 ) ;
V_5 -> V_530 = F_30 ( V_529 -> V_30 ) ;
V_5 -> V_531 =
F_30 ( V_529 -> V_532 ) ;
}
V_526:
F_22 ( V_78 , V_87 . V_109 ) ;
return V_34 ;
}
int
F_108 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_15 V_533 , const T_15 V_238 , const T_8 V_382 ,
const T_8 V_534 , struct V_535 * V_224 )
{
int V_34 = 0 ;
struct V_536 * V_84 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_537 ;
unsigned int V_538 ;
F_7 ( V_45 , L_66 , V_534 ) ;
V_34 = F_18 ( V_65 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_16 = F_5 ( V_382 ) ;
V_84 -> V_539 = F_4 ( V_534 ) ;
V_84 -> V_235 = V_533 ;
V_84 -> V_237 = V_238 ;
V_538 = V_534 * sizeof( struct V_535 ) ;
F_27 ( V_84 , V_538 - sizeof( struct V_535 ) ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - V_538 ;
V_87 [ 1 ] . V_109 = ( char * ) V_224 ;
V_87 [ 1 ] . V_110 = V_538 ;
F_21 ( & V_5 -> V_74 . V_540 . V_541 ) ;
V_34 = F_29 ( V_82 , V_5 -> V_20 , V_87 , 2 , & V_537 , V_542 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_67 , V_34 ) ;
F_49 ( V_5 , V_543 ) ;
}
return V_34 ;
}
int
F_109 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_15 V_533 , const T_15 V_238 , const T_8 V_382 ,
const T_15 V_387 , const T_15 V_330 , const T_8 V_544 ,
const bool V_545 )
{
struct V_535 V_546 ;
V_546 . V_388 = F_79 ( V_330 ) ;
V_546 . V_386 = F_79 ( V_387 ) ;
V_546 . V_30 = F_5 ( V_544 ) ;
if ( ! V_545 && V_544 != V_547 )
V_546 . V_30 |= F_5 ( V_548 ) ;
return F_108 ( V_82 , V_5 , V_533 , V_238 , V_382 , 1 , & V_546 ) ;
}
int
F_110 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_7 * V_549 , const T_5 V_550 )
{
int V_34 ;
struct V_551 * V_84 = NULL ;
F_7 ( V_45 , L_68 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_15 = F_4 ( 1 ) ;
V_84 -> V_13 = F_4 ( 36 ) ;
F_27 ( V_84 , 12 ) ;
memcpy ( V_84 -> V_552 , V_549 , 16 ) ;
V_84 -> V_553 = V_550 ;
V_34 = F_48 ( V_82 , V_5 -> V_20 , ( char * ) V_84 , V_496 ) ;
if ( V_34 ) {
F_49 ( V_5 , V_497 ) ;
F_7 ( V_45 , L_69 , V_34 ) ;
}
return V_34 ;
}
