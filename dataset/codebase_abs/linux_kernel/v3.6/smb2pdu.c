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
V_19:
V_7 -> V_29 = F_4 ( V_9 ) ;
return;
}
static int
F_6 ( T_1 V_30 , struct V_4 * V_5 )
{
int V_31 = 0 ;
struct V_32 * V_33 ;
struct V_34 * V_22 ;
struct V_35 * V_36 ;
if ( V_5 == NULL )
return V_31 ;
if ( V_30 == V_37 )
return V_31 ;
if ( V_5 -> V_38 == V_39 ) {
if ( ( V_30 != V_40 ) &&
( V_30 != V_41 ) &&
( V_30 != V_42 ) ) {
F_7 ( 1 , L_1 ,
V_30 ) ;
return - V_43 ;
}
}
if ( ( ! V_5 -> V_22 ) || ( V_5 -> V_22 -> V_44 == V_39 ) ||
( ! V_5 -> V_22 -> V_36 ) )
return - V_45 ;
V_22 = V_5 -> V_22 ;
V_36 = V_22 -> V_36 ;
while ( V_36 -> V_46 == V_47 ) {
switch ( V_30 ) {
case V_42 :
case V_48 :
case V_49 :
case V_50 :
return - V_51 ;
}
F_8 ( V_36 -> V_52 ,
( V_36 -> V_46 != V_47 ) , 10 * V_53 ) ;
if ( V_36 -> V_46 != V_47 )
break;
if ( ! V_5 -> V_54 ) {
F_7 ( 1 , L_2 ) ;
return - V_55 ;
}
}
if ( ! V_5 -> V_22 -> V_56 && ! V_5 -> V_56 )
return V_31 ;
V_33 = F_9 () ;
F_10 ( & V_5 -> V_22 -> V_57 ) ;
V_31 = F_11 ( 0 , V_5 -> V_22 ) ;
if ( ! V_31 && V_5 -> V_22 -> V_56 )
V_31 = F_12 ( 0 , V_5 -> V_22 , V_33 ) ;
if ( V_31 || ! V_5 -> V_56 ) {
F_13 ( & V_5 -> V_22 -> V_57 ) ;
goto V_19;
}
F_14 ( V_5 ) ;
V_31 = F_15 ( 0 , V_5 -> V_22 , V_5 -> V_58 , V_5 , V_33 ) ;
F_13 ( & V_5 -> V_22 -> V_57 ) ;
F_7 ( 1 , L_3 , V_31 ) ;
if ( V_31 )
goto V_19;
F_16 ( & V_59 ) ;
V_19:
switch ( V_30 ) {
case V_60 :
case V_61 :
case V_40 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
return - V_51 ;
}
F_17 ( V_33 ) ;
return V_31 ;
}
static int
F_18 ( T_1 V_30 , struct V_4 * V_5 ,
void * * V_68 )
{
int V_31 = 0 ;
V_31 = F_6 ( V_30 , V_5 ) ;
if ( V_31 )
return V_31 ;
* V_68 = F_19 () ;
if ( * V_68 == NULL ) {
return - V_69 ;
}
F_1 ( (struct V_1 * ) * V_68 , V_30 , V_5 ) ;
if ( V_5 != NULL ) {
#ifdef F_20
T_3 V_70 = F_2 ( V_30 ) ;
F_21 ( & V_5 -> V_71 . V_72 . V_73 [ V_70 ] ) ;
#endif
F_21 ( & V_5 -> V_74 ) ;
}
return V_31 ;
}
static void
F_22 ( int V_75 , void * V_76 )
{
if ( V_75 == V_77 )
F_23 ( V_76 ) ;
else if ( V_75 == V_78 )
F_24 ( V_76 ) ;
}
int
F_25 ( const unsigned int V_79 , struct V_34 * V_22 )
{
struct V_80 * V_81 ;
struct V_82 * V_76 ;
struct V_83 V_84 [ 1 ] ;
int V_31 = 0 ;
int V_75 ;
struct V_35 * V_36 ;
unsigned int V_85 ;
T_4 V_86 ;
T_4 V_8 = 0 ;
int V_87 , V_88 ;
char * V_89 ;
int V_90 = V_91 ;
F_7 ( 1 , L_4 ) ;
if ( V_22 -> V_36 )
V_36 = V_22 -> V_36 ;
else {
V_31 = - V_45 ;
return V_31 ;
}
V_31 = F_18 ( V_92 , NULL , ( void * * ) & V_81 ) ;
if ( V_31 )
return V_31 ;
if ( V_22 -> V_93 & ( ~ ( V_94 | V_95 ) ) )
V_85 = V_22 -> V_93 ;
else
V_85 = V_96 | V_22 -> V_93 ;
F_7 ( 1 , L_5 , V_85 ) ;
V_81 -> V_2 . V_23 = 0 ;
for ( V_86 = 0 ; V_86 < V_97 ; V_86 ++ )
V_81 -> V_98 [ V_86 ] = V_99 [ V_86 ] . V_100 ;
V_81 -> V_101 = F_4 ( V_86 ) ;
F_26 ( V_81 , V_86 * 2 ) ;
if ( ( V_85 & V_94 ) == V_94 )
V_8 = V_102 ;
else if ( V_85 & V_103 )
V_8 = V_104 ;
V_81 -> V_105 = F_4 ( V_8 ) ;
V_81 -> V_106 = F_5 ( V_107 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_81 ;
V_84 [ 0 ] . V_109 = F_27 ( V_81 ) + 4 ;
V_31 = F_28 ( V_79 , V_22 , V_84 , 1 , & V_75 , V_90 ) ;
V_76 = (struct V_82 * ) V_84 [ 0 ] . V_108 ;
if ( V_31 != 0 )
goto V_110;
if ( V_76 == NULL ) {
V_31 = - V_45 ;
goto V_110;
}
F_7 ( 1 , L_6 , V_76 -> V_105 ) ;
if ( V_76 -> V_111 == V_99 [ V_112 ] . V_100 )
F_7 ( 1 , L_7 ) ;
else if ( V_76 -> V_111 == V_99 [ V_113 ] . V_100 )
F_7 ( 1 , L_8 ) ;
else {
F_29 ( 1 , L_9 ,
F_2 ( V_76 -> V_111 ) ) ;
V_31 = - V_45 ;
goto V_110;
}
V_36 -> V_114 = F_2 ( V_76 -> V_111 ) ;
V_36 -> V_115 = F_30 ( V_76 -> V_116 ) ;
V_36 -> V_117 = F_30 ( V_76 -> V_118 ) ;
V_36 -> V_119 = F_30 ( V_76 -> V_120 ) ;
V_36 -> V_121 = F_2 ( V_76 -> V_105 ) ;
V_36 -> V_122 = F_30 ( V_76 -> V_106 ) ;
V_36 -> V_122 |= V_123 | V_124 ;
V_89 = F_31 ( & V_87 , & V_88 ,
& V_76 -> V_2 ) ;
if ( V_88 == 0 ) {
F_29 ( 1 , L_10 ) ;
V_31 = - V_45 ;
goto V_110;
}
#ifdef F_32
V_31 = F_33 ( V_89 , V_88 ,
& V_36 -> V_125 ) ;
if ( V_31 == 1 )
V_31 = 0 ;
else if ( V_31 == 0 ) {
V_31 = - V_45 ;
goto V_110;
}
#endif
V_110:
F_22 ( V_75 , V_76 ) ;
return V_31 ;
}
int
F_34 ( const unsigned int V_79 , struct V_34 * V_22 ,
const struct V_32 * V_126 )
{
struct V_127 * V_81 ;
struct V_128 * V_76 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_31 = 0 ;
int V_75 ;
T_5 V_129 = V_130 ;
struct V_35 * V_36 ;
unsigned int V_85 ;
T_6 V_8 = 0 ;
T_4 V_88 = 0 ;
char * V_89 ;
char * V_131 = NULL ;
bool V_132 = false ;
F_7 ( 1 , L_11 ) ;
if ( V_22 -> V_36 )
V_36 = V_22 -> V_36 ;
else {
V_31 = - V_45 ;
return V_31 ;
}
V_22 -> V_133 = F_35 ( sizeof( struct V_134 ) , V_135 ) ;
if ( ! V_22 -> V_133 )
return - V_69 ;
V_22 -> V_36 -> V_136 = V_137 ;
V_138:
if ( V_129 == V_139 )
V_129 = V_140 ;
V_31 = F_18 ( V_141 , NULL , ( void * * ) & V_81 ) ;
if ( V_31 )
return V_31 ;
if ( V_22 -> V_93 & ( ~ ( V_94 | V_95 ) ) )
V_85 = V_22 -> V_93 ;
else
V_85 = V_96 | V_22 -> V_93 ;
F_7 ( 1 , L_5 , V_85 ) ;
V_81 -> V_2 . V_23 = 0 ;
V_81 -> V_142 = 0 ;
V_81 -> V_2 . V_15 = F_4 ( 3 ) ;
if ( ( V_85 & V_94 ) == V_94 )
V_8 = V_102 ;
else if ( V_22 -> V_36 -> V_121 & V_102 )
V_8 = V_102 ;
else if ( V_85 & V_103 )
V_8 = V_104 ;
V_81 -> V_105 = V_8 ;
V_81 -> V_106 = 0 ;
V_81 -> V_143 = 0 ;
V_84 [ 0 ] . V_108 = ( char * ) V_81 ;
V_84 [ 0 ] . V_109 = F_27 ( V_81 ) + 4 - 1 ;
if ( V_129 == V_130 ) {
V_131 = F_35 ( sizeof( struct V_144 ) ,
V_135 ) ;
if ( V_131 == NULL ) {
V_31 = - V_69 ;
goto V_145;
}
F_36 ( V_131 , V_22 ) ;
if ( V_132 ) {
F_29 ( 1 , L_12 ) ;
V_31 = - V_146 ;
F_37 ( V_131 ) ;
goto V_145;
} else {
V_88 = sizeof( struct V_144 ) ;
V_89 = V_131 ;
}
} else if ( V_129 == V_140 ) {
V_81 -> V_2 . V_23 = V_22 -> V_24 ;
V_131 = F_38 ( sizeof( struct V_144 ) + 500 ,
V_135 ) ;
if ( V_131 == NULL ) {
F_29 ( 1 , L_13 ) ;
V_31 = - V_69 ;
goto V_145;
}
V_31 = F_39 ( V_131 , & V_88 , V_22 ,
V_126 ) ;
if ( V_31 ) {
F_7 ( 1 , L_14 , V_31 ) ;
goto V_145;
}
if ( V_132 ) {
F_29 ( 1 , L_12 ) ;
V_31 = - V_146 ;
F_37 ( V_131 ) ;
goto V_145;
} else {
V_89 = V_131 ;
}
} else {
F_29 ( 1 , L_15 ) ;
V_31 = - V_45 ;
goto V_145;
}
V_81 -> V_147 =
F_4 ( sizeof( struct V_127 ) -
1 - 4 ) ;
V_81 -> V_148 = F_4 ( V_88 ) ;
V_84 [ 1 ] . V_108 = V_89 ;
V_84 [ 1 ] . V_109 = V_88 ;
F_26 ( V_81 , V_88 - 1 ) ;
V_31 = F_28 ( V_79 , V_22 , V_84 , 2 , & V_75 , V_149 ) ;
F_37 ( V_89 ) ;
V_76 = (struct V_128 * ) V_84 [ 0 ] . V_108 ;
if ( V_76 -> V_2 . V_150 == V_151 ) {
if ( V_129 != V_130 ) {
F_29 ( 1 , L_16 ) ;
goto V_145;
}
if ( F_40 ( struct V_128 , V_152 ) - 4 !=
F_2 ( V_76 -> V_147 ) ) {
F_29 ( 1 , L_17 ,
F_2 ( V_76 -> V_147 ) ) ;
V_31 = - V_45 ;
goto V_145;
}
V_129 = V_139 ;
V_31 = 0 ;
V_22 -> V_24 = V_76 -> V_2 . V_23 ;
V_31 = F_41 ( V_76 -> V_152 ,
F_2 ( V_76 -> V_148 ) , V_22 ) ;
}
if ( V_31 != 0 )
goto V_145;
if ( V_76 == NULL ) {
V_31 = - V_45 ;
goto V_145;
}
V_22 -> V_153 = F_2 ( V_76 -> V_154 ) ;
V_145:
F_22 ( V_75 , V_76 ) ;
if ( ( V_129 == V_139 ) && ( V_31 == 0 ) )
goto V_138;
return V_31 ;
}
int
F_42 ( const unsigned int V_79 , struct V_34 * V_22 )
{
struct V_155 * V_81 ;
int V_31 = 0 ;
struct V_35 * V_36 ;
F_7 ( 1 , L_18 , V_22 ) ;
if ( V_22 && ( V_22 -> V_36 ) )
V_36 = V_22 -> V_36 ;
else
return - V_45 ;
V_31 = F_18 ( V_156 , NULL , ( void * * ) & V_81 ) ;
if ( V_31 )
return V_31 ;
V_81 -> V_2 . V_23 = V_22 -> V_24 ;
V_31 = F_43 ( V_79 , V_22 , ( char * ) & V_81 -> V_2 , 0 ) ;
return V_31 ;
}
static inline void F_44 ( struct V_4 * V_5 , T_3 V_157 )
{
F_21 ( & V_5 -> V_71 . V_72 . V_158 [ V_157 ] ) ;
}
int
F_15 ( const unsigned int V_79 , struct V_34 * V_22 , const char * V_159 ,
struct V_4 * V_5 , const struct V_32 * V_160 )
{
struct V_161 * V_81 ;
struct V_162 * V_76 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_31 = 0 ;
int V_75 ;
int V_163 ;
struct V_35 * V_36 ;
T_1 * V_164 = NULL ;
F_7 ( 1 , L_19 ) ;
if ( ( V_22 -> V_36 ) && V_159 )
V_36 = V_22 -> V_36 ;
else
return - V_45 ;
if ( V_5 && V_5 -> V_165 )
return - V_166 ;
V_164 = F_35 ( V_167 * 2 , V_135 ) ;
if ( V_164 == NULL )
return - V_69 ;
V_163 = F_45 ( V_164 , V_159 , strlen ( V_159 ) , V_160 ) + 1 ;
V_163 *= 2 ;
if ( V_163 < 2 ) {
F_37 ( V_164 ) ;
return - V_168 ;
}
V_31 = F_18 ( V_37 , V_5 , ( void * * ) & V_81 ) ;
if ( V_31 ) {
F_37 ( V_164 ) ;
return V_31 ;
}
if ( V_5 == NULL ) {
V_81 -> V_2 . V_23 = V_22 -> V_24 ;
}
V_84 [ 0 ] . V_108 = ( char * ) V_81 ;
V_84 [ 0 ] . V_109 = F_27 ( V_81 ) + 4 - 1 ;
V_81 -> V_169 = F_4 ( sizeof( struct V_161 )
- 1 - 4 ) ;
V_81 -> V_170 = F_4 ( V_163 - 2 ) ;
V_84 [ 1 ] . V_108 = V_164 ;
V_84 [ 1 ] . V_109 = V_163 ;
F_26 ( V_81 , V_163 - 1 ) ;
V_31 = F_28 ( V_79 , V_22 , V_84 , 2 , & V_75 , 0 ) ;
V_76 = (struct V_162 * ) V_84 [ 0 ] . V_108 ;
if ( V_31 != 0 ) {
if ( V_5 ) {
F_44 ( V_5 , V_171 ) ;
V_5 -> V_56 = true ;
}
goto V_172;
}
if ( V_76 == NULL ) {
V_31 = - V_45 ;
goto V_173;
}
if ( V_5 == NULL ) {
V_22 -> V_174 = V_76 -> V_2 . V_20 ;
goto V_173;
}
if ( V_76 -> V_175 & V_176 )
F_7 ( 1 , L_20 ) ;
else if ( V_76 -> V_175 & V_177 ) {
V_5 -> V_178 = true ;
F_7 ( 1 , L_21 ) ;
} else if ( V_76 -> V_175 & V_179 ) {
V_5 -> V_180 = true ;
F_7 ( 1 , L_22 ) ;
} else {
F_29 ( 1 , L_23 , V_76 -> V_175 ) ;
V_31 = - V_146 ;
goto V_172;
}
V_5 -> V_25 = F_30 ( V_76 -> V_181 ) ;
V_5 -> V_182 = F_30 ( V_76 -> V_183 ) ;
V_5 -> V_38 = V_184 ;
V_5 -> V_56 = false ;
V_5 -> V_21 = V_76 -> V_2 . V_20 ;
strncpy ( V_5 -> V_58 , V_159 , V_185 ) ;
if ( ( V_76 -> V_106 & V_186 ) &&
( ( V_5 -> V_25 & V_26 ) == 0 ) )
F_29 ( 1 , L_24 ) ;
V_173:
F_22 ( V_75 , V_76 ) ;
F_37 ( V_164 ) ;
return V_31 ;
V_172:
if ( V_76 -> V_2 . V_150 == V_187 ) {
F_29 ( 1 , L_25 , V_159 ) ;
V_5 -> V_165 = true ;
}
goto V_173;
}
int
F_46 ( const unsigned int V_79 , struct V_4 * V_5 )
{
struct V_188 * V_81 ;
int V_31 = 0 ;
struct V_35 * V_36 ;
struct V_34 * V_22 = V_5 -> V_22 ;
F_7 ( 1 , L_26 ) ;
if ( V_22 && ( V_22 -> V_36 ) )
V_36 = V_22 -> V_36 ;
else
return - V_45 ;
if ( ( V_5 -> V_56 ) || ( V_5 -> V_22 -> V_56 ) )
return 0 ;
V_31 = F_18 ( V_42 , V_5 , ( void * * ) & V_81 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_43 ( V_79 , V_22 , ( char * ) & V_81 -> V_2 , 0 ) ;
if ( V_31 )
F_44 ( V_5 , V_189 ) ;
return V_31 ;
}
int
F_47 ( const unsigned int V_79 , struct V_4 * V_5 , T_1 * V_190 ,
T_7 * V_191 , T_7 * V_192 , T_8 V_193 ,
T_8 V_194 , T_8 V_195 , T_8 V_196 )
{
struct V_197 * V_81 ;
struct V_198 * V_76 ;
struct V_35 * V_36 ;
struct V_34 * V_22 = V_5 -> V_22 ;
struct V_83 V_84 [ 2 ] ;
int V_75 ;
int V_199 ;
int V_31 = 0 ;
int V_200 = 2 ;
F_7 ( 1 , L_27 ) ;
if ( V_22 && ( V_22 -> V_36 ) )
V_36 = V_22 -> V_36 ;
else
return - V_45 ;
V_31 = F_18 ( V_41 , V_5 , ( void * * ) & V_81 ) ;
if ( V_31 )
return V_31 ;
if ( V_201 )
V_81 -> V_202 = V_203 ;
else
V_81 -> V_202 = V_204 ;
V_81 -> V_205 = V_206 ;
V_81 -> V_207 = F_5 ( V_193 ) ;
V_81 -> V_208 = F_5 ( V_195 ) ;
V_81 -> V_209 = V_210 ;
V_81 -> V_211 = F_5 ( V_194 ) ;
V_81 -> V_212 = F_5 ( V_196 ) ;
V_199 = ( 2 * F_48 ( ( V_213 * ) V_190 , V_214 ) ) + 2 ;
V_81 -> V_215 = F_4 ( sizeof( struct V_197 )
- 1 - 4 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_81 ;
V_84 [ 0 ] . V_109 = F_27 ( V_81 ) + 4 ;
if ( V_199 >= 4 ) {
V_81 -> V_216 = F_4 ( V_199 - 2 ) ;
V_84 [ 0 ] . V_109 -- ;
V_84 [ 1 ] . V_109 = V_199 ;
V_84 [ 1 ] . V_108 = V_190 ;
F_26 ( V_81 , V_199 - 1 ) ;
} else {
V_200 = 1 ;
V_81 -> V_216 = 0 ;
}
V_31 = F_28 ( V_79 , V_22 , V_84 , V_200 , & V_75 , 0 ) ;
V_76 = (struct V_198 * ) V_84 [ 0 ] . V_108 ;
if ( V_31 != 0 ) {
F_44 ( V_5 , V_217 ) ;
goto V_218;
}
if ( V_76 == NULL ) {
V_31 = - V_45 ;
goto V_218;
}
* V_191 = V_76 -> V_219 ;
* V_192 = V_76 -> V_220 ;
V_218:
F_22 ( V_75 , V_76 ) ;
return V_31 ;
}
int
F_49 ( const unsigned int V_79 , struct V_4 * V_5 ,
T_7 V_191 , T_7 V_192 )
{
struct V_221 * V_81 ;
struct V_222 * V_76 ;
struct V_35 * V_36 ;
struct V_34 * V_22 = V_5 -> V_22 ;
struct V_83 V_84 [ 1 ] ;
int V_75 ;
int V_31 = 0 ;
F_7 ( 1 , L_28 ) ;
if ( V_22 && ( V_22 -> V_36 ) )
V_36 = V_22 -> V_36 ;
else
return - V_45 ;
V_31 = F_18 ( V_49 , V_5 , ( void * * ) & V_81 ) ;
if ( V_31 )
return V_31 ;
V_81 -> V_219 = V_191 ;
V_81 -> V_220 = V_192 ;
V_84 [ 0 ] . V_108 = ( char * ) V_81 ;
V_84 [ 0 ] . V_109 = F_27 ( V_81 ) + 4 ;
V_31 = F_28 ( V_79 , V_22 , V_84 , 1 , & V_75 , 0 ) ;
V_76 = (struct V_222 * ) V_84 [ 0 ] . V_108 ;
if ( V_31 != 0 ) {
if ( V_5 )
F_44 ( V_5 , V_223 ) ;
goto V_224;
}
if ( V_76 == NULL ) {
V_31 = - V_45 ;
goto V_224;
}
V_224:
F_22 ( V_75 , V_76 ) ;
return V_31 ;
}
static int
F_50 ( unsigned int V_225 , unsigned int V_226 ,
struct V_1 * V_2 , unsigned int V_227 )
{
unsigned int V_228 = F_51 ( V_2 -> V_11 ) ;
char * V_229 = V_228 + 4 + ( char * ) V_2 ;
char * V_230 = 4 + V_225 + ( char * ) V_2 ;
char * V_231 = V_230 + V_226 ;
if ( V_226 < V_227 ) {
F_29 ( 1 , L_29 ,
V_226 , V_227 ) ;
return - V_168 ;
}
if ( ( V_228 > 0x7FFFFF ) || ( V_226 > 0x7FFFFF ) ) {
F_29 ( 1 , L_30 ,
V_226 , V_228 ) ;
return - V_168 ;
}
if ( ( V_230 > V_229 ) || ( V_231 > V_229 ) ) {
F_29 ( 1 , L_31 ) ;
return - V_168 ;
}
return 0 ;
}
static int
F_52 ( unsigned int V_225 , unsigned int V_226 ,
struct V_1 * V_2 , unsigned int V_232 ,
char * V_233 )
{
char * V_230 = 4 + V_225 + ( char * ) V_2 ;
int V_31 ;
if ( ! V_233 )
return - V_168 ;
V_31 = F_50 ( V_225 , V_226 , V_2 , V_232 ) ;
if ( V_31 )
return V_31 ;
memcpy ( V_233 , V_230 , V_226 ) ;
return 0 ;
}
int
F_53 ( const unsigned int V_79 , struct V_4 * V_5 ,
T_7 V_191 , T_7 V_192 ,
struct V_234 * V_233 )
{
struct V_235 * V_81 ;
struct V_236 * V_76 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_31 = 0 ;
int V_75 ;
struct V_35 * V_36 ;
struct V_34 * V_22 = V_5 -> V_22 ;
F_7 ( 1 , L_32 ) ;
if ( V_22 && ( V_22 -> V_36 ) )
V_36 = V_22 -> V_36 ;
else
return - V_45 ;
V_31 = F_18 ( V_66 , V_5 , ( void * * ) & V_81 ) ;
if ( V_31 )
return V_31 ;
V_81 -> V_237 = V_238 ;
V_81 -> V_239 = V_240 ;
V_81 -> V_219 = V_191 ;
V_81 -> V_220 = V_192 ;
V_81 -> V_241 =
F_4 ( sizeof( struct V_235 ) - 1 - 4 ) ;
V_81 -> V_242 =
F_5 ( sizeof( struct V_234 ) + V_243 * 2 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_81 ;
V_84 [ 0 ] . V_109 = F_27 ( V_81 ) + 4 ;
V_31 = F_28 ( V_79 , V_22 , V_84 , 1 , & V_75 , 0 ) ;
if ( V_31 ) {
F_44 ( V_5 , V_244 ) ;
goto V_245;
}
V_76 = (struct V_236 * ) V_84 [ 0 ] . V_108 ;
V_31 = F_52 ( F_2 ( V_76 -> V_246 ) ,
F_30 ( V_76 -> V_242 ) ,
& V_76 -> V_2 , sizeof( struct V_234 ) ,
( char * ) V_233 ) ;
V_245:
F_22 ( V_75 , V_76 ) ;
return V_31 ;
}
static void
F_54 ( struct V_247 * V_248 )
{
struct V_35 * V_36 = V_248 -> V_249 ;
struct V_250 * V_251 = (struct V_250 * ) V_248 -> V_252 ;
unsigned int V_253 = 1 ;
if ( V_248 -> V_254 == V_255 )
V_253 = F_2 ( V_251 -> V_2 . V_15 ) ;
F_55 ( V_248 ) ;
F_56 ( V_36 , V_253 , V_256 ) ;
}
int
F_57 ( struct V_35 * V_36 )
{
struct V_257 * V_81 ;
int V_31 = 0 ;
struct V_83 V_84 ;
F_7 ( 1 , L_33 ) ;
V_31 = F_18 ( V_258 , NULL , ( void * * ) & V_81 ) ;
if ( V_31 )
return V_31 ;
V_81 -> V_2 . V_15 = F_4 ( 1 ) ;
V_84 . V_108 = ( char * ) V_81 ;
V_84 . V_109 = F_27 ( V_81 ) + 4 ;
V_31 = F_58 ( V_36 , & V_84 , 1 , NULL , F_54 , V_36 ,
V_256 ) ;
if ( V_31 )
F_7 ( 1 , L_34 , V_31 ) ;
F_23 ( V_81 ) ;
return V_31 ;
}
