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
int
F_22 ( const unsigned int V_78 , struct V_37 * V_20 )
{
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_83 V_84 [ 1 ] ;
int V_34 = 0 ;
int V_85 ;
struct V_38 * V_21 = V_20 -> V_21 ;
int V_86 , V_87 ;
char * V_88 ;
int V_89 = V_90 ;
F_7 ( V_45 , L_4 ) ;
if ( ! V_21 ) {
F_23 ( 1 , L_5 , V_91 ) ;
return - V_48 ;
}
V_34 = F_18 ( V_92 , NULL , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_27 = 0 ;
V_80 -> V_93 [ 0 ] = F_4 ( V_20 -> V_21 -> V_94 -> V_95 ) ;
V_80 -> V_96 = F_4 ( 1 ) ;
F_24 ( V_80 , 2 ) ;
if ( V_20 -> V_29 )
V_80 -> V_97 = F_4 ( V_98 ) ;
else if ( V_99 & V_100 )
V_80 -> V_97 = F_4 ( V_101 ) ;
else
V_80 -> V_97 = 0 ;
V_80 -> V_102 = F_5 ( V_20 -> V_21 -> V_94 -> V_103 ) ;
if ( V_20 -> V_21 -> V_94 -> V_95 == V_104 )
memset ( V_80 -> V_105 , 0 , V_106 ) ;
else
memcpy ( V_80 -> V_105 , V_21 -> V_107 ,
V_106 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 1 , & V_85 , V_89 ) ;
V_82 = (struct V_81 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 != 0 )
goto V_110;
F_7 ( V_45 , L_6 , V_82 -> V_97 ) ;
if ( V_82 -> V_111 == F_4 ( V_104 ) )
F_7 ( V_45 , L_7 ) ;
else if ( V_82 -> V_111 == F_4 ( V_112 ) )
F_7 ( V_45 , L_8 ) ;
else if ( V_82 -> V_111 == F_4 ( V_113 ) )
F_7 ( V_45 , L_9 ) ;
else if ( V_82 -> V_111 == F_4 ( V_114 ) )
F_7 ( V_45 , L_10 ) ;
else {
F_7 ( V_115 , L_11 ,
F_2 ( V_82 -> V_111 ) ) ;
V_34 = - V_48 ;
goto V_110;
}
V_21 -> V_116 = F_2 ( V_82 -> V_111 ) ;
V_21 -> V_117 = V_118 ;
V_21 -> V_119 = F_27 (unsigned int, le32_to_cpu(rsp->MaxTransactSize),
SMB2_MAX_BUFFER_SIZE) ;
V_21 -> V_120 = F_28 ( V_82 -> V_121 ) ;
V_21 -> V_122 = F_28 ( V_82 -> V_123 ) ;
V_21 -> V_124 = F_2 ( V_82 -> V_97 ) ;
V_21 -> V_22 = F_28 ( V_82 -> V_102 ) ;
V_21 -> V_22 |= V_125 | V_126 ;
V_88 = F_29 ( & V_86 , & V_87 ,
& V_82 -> V_2 ) ;
if ( V_87 == 0 )
F_7 ( V_45 , L_12 ) ;
V_34 = F_30 ( V_21 , V_20 -> V_29 ) ;
#ifdef F_31
if ( V_34 )
goto V_110;
if ( V_87 )
V_34 = F_32 ( V_88 , V_87 ,
& V_21 -> V_127 ) ;
if ( V_34 == 1 )
V_34 = 0 ;
else if ( V_34 == 0 ) {
V_34 = - V_48 ;
goto V_110;
}
#endif
V_110:
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
int F_34 ( const unsigned int V_78 , struct V_4 * V_5 )
{
int V_34 = 0 ;
struct V_128 V_129 ;
struct V_130 * V_131 ;
T_4 V_132 ;
F_7 ( V_45 , L_13 ) ;
if ( V_5 -> V_20 -> V_21 -> V_29 == false )
return 0 ;
V_129 . V_102 =
F_5 ( V_5 -> V_20 -> V_21 -> V_94 -> V_103 ) ;
memcpy ( V_129 . V_133 , V_5 -> V_20 -> V_21 -> V_107 ,
V_106 ) ;
if ( V_5 -> V_20 -> V_29 )
V_129 . V_97 =
F_4 ( V_98 ) ;
else if ( V_99 & V_100 )
V_129 . V_97 =
F_4 ( V_101 ) ;
else
V_129 . V_97 = 0 ;
V_129 . V_96 = F_4 ( 1 ) ;
V_129 . V_93 [ 0 ] =
F_4 ( V_5 -> V_20 -> V_21 -> V_94 -> V_95 ) ;
V_34 = F_35 ( V_78 , V_5 , V_134 , V_134 ,
V_135 , true ,
( char * ) & V_129 , sizeof( struct V_128 ) ,
( char * * ) & V_131 , & V_132 ) ;
if ( V_34 != 0 ) {
F_7 ( V_115 , L_14 , V_34 ) ;
return - V_48 ;
}
if ( V_132 != sizeof( struct V_130 ) ) {
F_7 ( V_115 , L_15 ) ;
return - V_48 ;
}
if ( V_131 -> V_136 !=
F_4 ( V_5 -> V_20 -> V_21 -> V_94 -> V_95 ) )
goto V_137;
if ( V_131 -> V_97 != F_4 ( V_5 -> V_20 -> V_21 -> V_124 ) )
goto V_137;
if ( ( F_28 ( V_131 -> V_102 ) | V_125 |
V_126 ) != V_5 -> V_20 -> V_21 -> V_22 )
goto V_137;
F_7 ( V_45 , L_16 ) ;
return 0 ;
V_137:
F_7 ( V_115 , L_17 ) ;
return - V_48 ;
}
int
F_36 ( const unsigned int V_78 , struct V_37 * V_20 ,
const struct V_35 * V_138 )
{
struct V_139 * V_80 ;
struct V_140 * V_82 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_34 = 0 ;
int V_85 = V_141 ;
T_5 V_142 = V_143 ;
struct V_38 * V_21 = V_20 -> V_21 ;
T_6 V_87 = 0 ;
char * V_88 ;
char * V_144 = NULL ;
bool V_145 = false ;
F_7 ( V_45 , L_18 ) ;
if ( ! V_21 ) {
F_23 ( 1 , L_5 , V_91 ) ;
return - V_48 ;
}
F_37 ( V_20 -> V_146 . V_147 ) ;
V_20 -> V_146 . V_147 = NULL ;
V_20 -> V_148 = F_38 ( sizeof( struct V_149 ) , V_150 ) ;
if ( ! V_20 -> V_148 )
return - V_72 ;
V_20 -> V_148 -> V_151 = true ;
V_20 -> V_152 = V_153 ;
V_154:
if ( V_142 == V_155 )
V_142 = V_156 ;
V_34 = F_18 ( V_157 , NULL , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_27 = 0 ;
V_80 -> V_158 = 0 ;
V_80 -> V_2 . V_15 = F_4 ( 3 ) ;
if ( V_21 -> V_29 )
V_80 -> V_97 = V_98 ;
else if ( V_99 & V_100 )
V_80 -> V_97 = V_101 ;
else
V_80 -> V_97 = 0 ;
V_80 -> V_102 = 0 ;
V_80 -> V_159 = 0 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - 1 ;
if ( V_142 == V_143 ) {
V_144 = F_38 ( sizeof( struct V_160 ) ,
V_150 ) ;
if ( V_144 == NULL ) {
V_34 = - V_72 ;
goto V_161;
}
F_39 ( V_144 , V_20 ) ;
if ( V_145 ) {
F_7 ( V_115 , L_19 ) ;
V_34 = - V_162 ;
F_37 ( V_144 ) ;
goto V_161;
} else {
V_87 = sizeof( struct V_160 ) ;
V_88 = V_144 ;
}
} else if ( V_142 == V_156 ) {
V_80 -> V_2 . V_27 = V_20 -> V_28 ;
V_144 = F_40 ( sizeof( struct V_160 ) + 500 ,
V_150 ) ;
if ( V_144 == NULL ) {
V_34 = - V_72 ;
goto V_161;
}
V_34 = F_41 ( V_144 , & V_87 , V_20 ,
V_138 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_20 ,
V_34 ) ;
goto V_161;
}
if ( V_145 ) {
F_7 ( V_115 , L_19 ) ;
V_34 = - V_162 ;
F_37 ( V_144 ) ;
goto V_161;
} else {
V_88 = V_144 ;
}
} else {
F_7 ( V_115 , L_21 ) ;
V_34 = - V_48 ;
goto V_161;
}
V_80 -> V_163 =
F_4 ( sizeof( struct V_139 ) -
1 - 4 ) ;
V_80 -> V_164 = F_4 ( V_87 ) ;
V_84 [ 1 ] . V_108 = V_88 ;
V_84 [ 1 ] . V_109 = V_87 ;
F_24 ( V_80 , V_87 - 1 ) ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 2 , & V_85 ,
V_165 | V_90 ) ;
F_37 ( V_88 ) ;
V_82 = (struct V_140 * ) V_84 [ 0 ] . V_108 ;
if ( V_85 != V_141 &&
V_82 -> V_2 . V_166 == V_167 ) {
if ( V_142 != V_143 ) {
F_7 ( V_115 , L_22 ) ;
goto V_161;
}
if ( F_42 ( struct V_140 , V_168 ) - 4 !=
F_2 ( V_82 -> V_163 ) ) {
F_7 ( V_115 , L_23 ,
F_2 ( V_82 -> V_163 ) ) ;
V_34 = - V_48 ;
goto V_161;
}
V_142 = V_155 ;
V_34 = 0 ;
V_20 -> V_28 = V_82 -> V_2 . V_27 ;
V_34 = F_43 ( V_82 -> V_168 ,
F_2 ( V_82 -> V_164 ) , V_20 ) ;
}
if ( V_34 != 0 )
goto V_161;
V_20 -> V_169 = F_2 ( V_82 -> V_170 ) ;
if ( V_20 -> V_169 & V_171 )
F_7 ( V_115 , L_24 ) ;
V_161:
F_33 ( V_85 , V_82 ) ;
if ( ( V_142 == V_155 ) && ( V_34 == 0 ) )
goto V_154;
if ( ! V_34 ) {
F_10 ( & V_21 -> V_172 ) ;
if ( V_21 -> V_29 && V_21 -> V_173 -> V_174 ) {
V_34 = V_21 -> V_173 -> V_174 ( V_20 ) ;
F_37 ( V_20 -> V_146 . V_147 ) ;
V_20 -> V_146 . V_147 = NULL ;
if ( V_34 ) {
F_7 ( V_45 ,
L_25 ) ;
F_13 ( & V_21 -> V_172 ) ;
goto V_175;
}
}
if ( ! V_21 -> V_176 ) {
V_21 -> V_177 = 0x2 ;
V_21 -> V_176 = true ;
}
F_13 ( & V_21 -> V_172 ) ;
F_7 ( V_45 , L_26 ) ;
F_44 ( & V_178 ) ;
V_20 -> V_47 = V_179 ;
V_20 -> V_59 = false ;
F_45 ( & V_178 ) ;
}
V_175:
if ( ! V_21 -> V_29 ) {
F_37 ( V_20 -> V_146 . V_147 ) ;
V_20 -> V_146 . V_147 = NULL ;
}
F_37 ( V_20 -> V_148 ) ;
return V_34 ;
}
int
F_46 ( const unsigned int V_78 , struct V_37 * V_20 )
{
struct V_180 * V_80 ;
int V_34 = 0 ;
struct V_38 * V_21 ;
F_7 ( V_45 , L_27 , V_20 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_20 -> V_59 )
goto V_181;
V_34 = F_18 ( V_182 , NULL , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_27 = V_20 -> V_28 ;
if ( V_21 -> V_29 )
V_80 -> V_2 . V_30 |= V_31 ;
V_34 = F_47 ( V_78 , V_20 , ( char * ) & V_80 -> V_2 , 0 ) ;
V_181:
return V_34 ;
}
static inline void F_48 ( struct V_4 * V_5 , T_3 V_183 )
{
F_21 ( & V_5 -> V_74 . V_75 . V_184 [ V_183 ] ) ;
}
static inline void F_49 ( struct V_4 * V_5 )
{
V_5 -> V_185 = 256 ;
V_5 -> V_186 = 1048576 ;
V_5 -> V_187 = 16777216 ;
}
int
F_15 ( const unsigned int V_78 , struct V_37 * V_20 , const char * V_188 ,
struct V_4 * V_5 , const struct V_35 * V_189 )
{
struct V_190 * V_80 ;
struct V_191 * V_82 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_34 = 0 ;
int V_85 ;
int V_192 ;
struct V_38 * V_21 ;
T_1 * V_193 = NULL ;
F_7 ( V_45 , L_28 ) ;
if ( ( V_20 -> V_21 ) && V_188 )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_5 && V_5 -> V_194 )
return - V_195 ;
V_193 = F_38 ( V_196 * 2 , V_150 ) ;
if ( V_193 == NULL )
return - V_72 ;
V_192 = F_50 ( V_193 , V_188 , strlen ( V_188 ) , V_189 ) + 1 ;
V_192 *= 2 ;
if ( V_192 < 2 ) {
F_37 ( V_193 ) ;
return - V_197 ;
}
V_34 = F_18 ( V_39 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 ) {
F_37 ( V_193 ) ;
return V_34 ;
}
if ( V_5 == NULL ) {
V_80 -> V_2 . V_27 = V_20 -> V_28 ;
}
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - 1 ;
V_80 -> V_198 = F_4 ( sizeof( struct V_190 )
- 1 - 4 ) ;
V_80 -> V_199 = F_4 ( V_192 - 2 ) ;
V_84 [ 1 ] . V_108 = V_193 ;
V_84 [ 1 ] . V_109 = V_192 ;
F_24 ( V_80 , V_192 - 1 ) ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 2 , & V_85 , 0 ) ;
V_82 = (struct V_191 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 != 0 ) {
if ( V_5 ) {
F_48 ( V_5 , V_200 ) ;
V_5 -> V_59 = true ;
}
goto V_201;
}
if ( V_5 == NULL ) {
V_20 -> V_202 = V_82 -> V_2 . V_25 ;
goto V_203;
}
if ( V_82 -> V_204 & V_205 )
F_7 ( V_45 , L_29 ) ;
else if ( V_82 -> V_204 & V_206 ) {
V_5 -> V_207 = true ;
F_7 ( V_45 , L_30 ) ;
} else if ( V_82 -> V_204 & V_208 ) {
V_5 -> V_209 = true ;
F_7 ( V_45 , L_31 ) ;
} else {
F_7 ( V_115 , L_32 , V_82 -> V_204 ) ;
V_34 = - V_162 ;
goto V_201;
}
V_5 -> V_210 = F_28 ( V_82 -> V_211 ) ;
V_5 -> V_22 = V_82 -> V_102 ;
V_5 -> V_212 = F_28 ( V_82 -> V_213 ) ;
V_5 -> V_40 = V_179 ;
V_5 -> V_59 = false ;
V_5 -> V_26 = V_82 -> V_2 . V_25 ;
F_51 ( V_5 -> V_61 , V_188 , sizeof( V_5 -> V_61 ) ) ;
if ( ( V_82 -> V_102 & V_214 ) &&
( ( V_5 -> V_210 & V_215 ) == 0 ) )
F_7 ( V_115 , L_33 ) ;
F_49 ( V_5 ) ;
if ( V_5 -> V_20 -> V_21 -> V_173 -> V_216 )
V_34 = V_5 -> V_20 -> V_21 -> V_173 -> V_216 ( V_78 , V_5 ) ;
V_203:
F_33 ( V_85 , V_82 ) ;
F_37 ( V_193 ) ;
return V_34 ;
V_201:
if ( V_82 -> V_2 . V_166 == V_217 ) {
F_7 ( V_115 , L_34 , V_188 ) ;
if ( V_5 )
V_5 -> V_194 = true ;
}
goto V_203;
}
int
F_52 ( const unsigned int V_78 , struct V_4 * V_5 )
{
struct V_218 * V_80 ;
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
V_34 = F_18 ( V_44 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_47 ( V_78 , V_20 , ( char * ) & V_80 -> V_2 , 0 ) ;
if ( V_34 )
F_48 ( V_5 , V_219 ) ;
return V_34 ;
}
static struct V_220 *
F_53 ( void )
{
struct V_220 * V_221 ;
V_221 = F_40 ( sizeof( struct V_220 ) , V_150 ) ;
if ( ! V_221 )
return NULL ;
V_221 -> V_222 . V_223 = F_4 ( F_42
( struct V_220 , V_224 ) ) ;
V_221 -> V_222 . V_225 = F_5 ( 16 ) ;
V_221 -> V_222 . V_226 = F_4 ( F_42
( struct V_220 , V_227 ) ) ;
V_221 -> V_222 . V_228 = F_4 ( 4 ) ;
V_221 -> V_227 [ 0 ] = 'D' ;
V_221 -> V_227 [ 1 ] = 'H' ;
V_221 -> V_227 [ 2 ] = 'n' ;
V_221 -> V_227 [ 3 ] = 'Q' ;
return V_221 ;
}
static struct V_220 *
F_54 ( struct V_229 * V_230 )
{
struct V_220 * V_221 ;
V_221 = F_40 ( sizeof( struct V_220 ) , V_150 ) ;
if ( ! V_221 )
return NULL ;
V_221 -> V_222 . V_223 = F_4 ( F_42
( struct V_220 , V_224 ) ) ;
V_221 -> V_222 . V_225 = F_5 ( 16 ) ;
V_221 -> V_222 . V_226 = F_4 ( F_42
( struct V_220 , V_227 ) ) ;
V_221 -> V_222 . V_228 = F_4 ( 4 ) ;
V_221 -> V_224 . V_231 . V_232 = V_230 -> V_233 ;
V_221 -> V_224 . V_231 . V_234 = V_230 -> V_235 ;
V_221 -> V_227 [ 0 ] = 'D' ;
V_221 -> V_227 [ 1 ] = 'H' ;
V_221 -> V_227 [ 2 ] = 'n' ;
V_221 -> V_227 [ 3 ] = 'C' ;
return V_221 ;
}
static T_7
F_55 ( struct V_38 * V_21 , struct V_236 * V_82 ,
unsigned int * V_237 )
{
char * V_238 ;
struct V_239 * V_240 ;
unsigned int V_241 = 0 ;
char * V_242 ;
V_238 = ( char * ) V_82 + 4 + F_28 ( V_82 -> V_243 ) ;
V_240 = (struct V_239 * ) V_238 ;
do {
V_240 = (struct V_239 * ) ( ( char * ) V_240 + V_241 ) ;
V_242 = F_2 ( V_240 -> V_226 ) + ( char * ) V_240 ;
if ( F_2 ( V_240 -> V_228 ) != 4 ||
strncmp ( V_242 , L_36 , 4 ) ) {
V_241 = F_28 ( V_240 -> V_244 ) ;
continue;
}
return V_21 -> V_173 -> V_245 ( V_240 , V_237 ) ;
} while ( V_241 != 0 );
return 0 ;
}
static int
F_56 ( struct V_38 * V_21 , struct V_83 * V_84 ,
unsigned int * V_246 , T_7 * V_247 )
{
struct V_248 * V_80 = V_84 [ 0 ] . V_108 ;
unsigned int V_249 = * V_246 ;
V_84 [ V_249 ] . V_108 = V_21 -> V_173 -> V_250 ( V_247 + 1 , * V_247 ) ;
if ( V_84 [ V_249 ] . V_108 == NULL )
return - V_72 ;
V_84 [ V_249 ] . V_109 = V_21 -> V_94 -> V_251 ;
V_80 -> V_252 = V_253 ;
if ( ! V_80 -> V_243 )
V_80 -> V_243 = F_5 (
sizeof( struct V_248 ) - 4 +
V_84 [ V_249 - 1 ] . V_109 ) ;
F_57 ( & V_80 -> V_254 ,
V_21 -> V_94 -> V_251 ) ;
F_24 ( & V_80 -> V_2 , V_21 -> V_94 -> V_251 ) ;
* V_246 = V_249 + 1 ;
return 0 ;
}
static int
F_58 ( struct V_83 * V_84 , unsigned int * V_246 ,
struct V_255 * V_256 )
{
struct V_248 * V_80 = V_84 [ 0 ] . V_108 ;
unsigned int V_249 = * V_246 ;
if ( V_256 -> V_257 ) {
V_84 [ V_249 ] . V_108 = F_54 ( V_256 -> V_230 ) ;
V_256 -> V_257 = false ;
} else
V_84 [ V_249 ] . V_108 = F_53 () ;
if ( V_84 [ V_249 ] . V_108 == NULL )
return - V_72 ;
V_84 [ V_249 ] . V_109 = sizeof( struct V_220 ) ;
if ( ! V_80 -> V_243 )
V_80 -> V_243 =
F_5 ( sizeof( struct V_248 ) - 4 +
V_84 [ 1 ] . V_109 ) ;
F_57 ( & V_80 -> V_254 , sizeof( struct V_220 ) ) ;
F_24 ( & V_80 -> V_2 , sizeof( struct V_220 ) ) ;
* V_246 = V_249 + 1 ;
return 0 ;
}
int
F_59 ( const unsigned int V_78 , struct V_255 * V_256 , T_1 * V_258 ,
T_7 * V_247 , struct V_259 * V_221 ,
struct V_260 * * V_261 )
{
struct V_248 * V_80 ;
struct V_236 * V_82 ;
struct V_38 * V_21 ;
struct V_4 * V_5 = V_256 -> V_5 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_83 V_84 [ 4 ] ;
int V_85 ;
int V_262 ;
T_1 * V_263 = NULL ;
int V_264 ;
int V_34 = 0 ;
unsigned int V_265 = 2 ;
T_8 V_266 = 0 ;
char * V_267 = NULL , * V_268 = NULL ;
F_7 ( V_45 , L_37 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_43 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
if ( V_256 -> V_269 & V_270 )
V_266 |= V_271 ;
V_80 -> V_272 = V_273 ;
V_80 -> V_274 = F_5 ( V_256 -> V_275 ) ;
V_80 -> V_276 = F_5 ( V_266 ) ;
V_80 -> V_277 = V_278 ;
V_80 -> V_279 = F_5 ( V_256 -> V_280 ) ;
V_80 -> V_281 = F_5 ( V_256 -> V_269 & V_282 ) ;
V_262 = ( 2 * F_60 ( ( V_283 * ) V_258 , V_284 ) ) + 2 ;
V_80 -> V_226 = F_4 ( sizeof( struct V_248 ) - 4 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
V_80 -> V_228 = F_4 ( V_262 - 2 ) ;
V_84 [ 0 ] . V_109 -- ;
if ( V_262 % 8 != 0 ) {
V_264 = V_262 / 8 * 8 ;
if ( V_264 < V_262 )
V_264 += 8 ;
V_263 = F_40 ( V_264 , V_150 ) ;
if ( ! V_263 )
return - V_72 ;
memcpy ( ( char * ) V_263 , ( const char * ) V_258 ,
V_262 ) ;
V_262 = V_264 ;
V_258 = V_263 ;
}
V_84 [ 1 ] . V_109 = V_262 ;
V_84 [ 1 ] . V_108 = V_258 ;
F_24 ( V_80 , V_262 - 1 ) ;
if ( ! V_21 -> V_285 )
* V_247 = V_286 ;
if ( ! ( V_21 -> V_22 & V_287 ) ||
* V_247 == V_286 )
V_80 -> V_252 = * V_247 ;
else {
V_34 = F_56 ( V_21 , V_84 , & V_265 , V_247 ) ;
if ( V_34 ) {
F_61 ( V_80 ) ;
F_37 ( V_263 ) ;
return V_34 ;
}
V_268 = V_84 [ V_265 - 1 ] . V_108 ;
}
if ( * V_247 == V_288 ) {
if ( V_21 -> V_22 & V_287 ) {
struct V_239 * V_222 =
(struct V_239 * ) V_84 [ V_265 - 1 ] . V_108 ;
V_222 -> V_244 =
F_5 ( V_21 -> V_94 -> V_251 ) ;
}
V_34 = F_58 ( V_84 , & V_265 , V_256 ) ;
if ( V_34 ) {
F_61 ( V_80 ) ;
F_37 ( V_263 ) ;
F_37 ( V_268 ) ;
return V_34 ;
}
V_267 = V_84 [ V_265 - 1 ] . V_108 ;
}
V_34 = F_26 ( V_78 , V_20 , V_84 , V_265 , & V_85 , 0 ) ;
V_82 = (struct V_236 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 != 0 ) {
F_48 ( V_5 , V_289 ) ;
if ( V_261 )
* V_261 = F_62 ( V_82 , F_25 ( V_82 ) + 4 ,
V_150 ) ;
goto V_290;
}
V_256 -> V_230 -> V_233 = V_82 -> V_232 ;
V_256 -> V_230 -> V_235 = V_82 -> V_234 ;
if ( V_221 ) {
memcpy ( V_221 , & V_82 -> V_291 , 32 ) ;
V_221 -> V_292 = V_82 -> V_292 ;
V_221 -> V_293 = V_82 -> V_294 ;
V_221 -> V_295 = V_82 -> V_276 ;
V_221 -> V_296 = F_5 ( 1 ) ;
V_221 -> V_297 = 0 ;
}
if ( V_82 -> V_298 == V_253 )
* V_247 = F_55 ( V_21 , V_82 , & V_256 -> V_230 -> V_237 ) ;
else
* V_247 = V_82 -> V_298 ;
V_290:
F_37 ( V_263 ) ;
F_37 ( V_268 ) ;
F_37 ( V_267 ) ;
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
int
F_35 ( const unsigned int V_78 , struct V_4 * V_5 , T_9 V_233 ,
T_9 V_235 , T_4 V_299 , bool V_300 , char * V_301 ,
T_4 V_302 , char * * V_303 , T_4 * V_304 )
{
struct V_305 * V_80 ;
struct V_306 * V_82 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_83 V_84 [ 2 ] ;
int V_85 ;
int V_265 ;
int V_34 = 0 ;
F_7 ( V_45 , L_38 ) ;
if ( V_303 != NULL )
* V_303 = NULL ;
if ( V_304 )
* V_304 = 0 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_66 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_307 = F_5 ( V_299 ) ;
V_80 -> V_232 = V_233 ;
V_80 -> V_234 = V_235 ;
if ( V_302 ) {
V_80 -> V_308 = F_5 ( V_302 ) ;
V_80 -> V_309 =
F_5 ( F_42 ( struct V_305 , V_168 ) - 4 ) ;
V_84 [ 1 ] . V_108 = V_301 ;
V_84 [ 1 ] . V_109 = V_302 ;
V_265 = 2 ;
} else
V_265 = 1 ;
V_80 -> V_310 = 0 ;
V_80 -> V_311 = 0 ;
V_80 -> V_312 = F_5 ( 0xFF00 ) ;
if ( V_300 )
V_80 -> V_30 = F_5 ( V_313 ) ;
else
V_80 -> V_30 = 0 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
if ( V_302 ) {
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - 1 ;
F_24 ( V_80 , V_302 - 1 ) ;
} else
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_26 ( V_78 , V_20 , V_84 , V_265 , & V_85 , 0 ) ;
V_82 = (struct V_306 * ) V_84 [ 0 ] . V_108 ;
if ( ( V_34 != 0 ) && ( V_34 != - V_197 ) ) {
if ( V_5 )
F_48 ( V_5 , V_314 ) ;
goto V_315;
} else if ( V_34 == - V_197 ) {
if ( ( V_299 != V_316 ) &&
( V_299 != V_317 ) ) {
if ( V_5 )
F_48 ( V_5 , V_314 ) ;
goto V_315;
}
}
if ( ( V_304 == NULL ) || ( V_303 == NULL ) )
goto V_315;
* V_304 = F_28 ( V_82 -> V_311 ) ;
if ( * V_304 == 0 )
goto V_315;
else if ( * V_304 > 0xFF00 ) {
F_7 ( V_115 , L_39 , * V_304 ) ;
* V_304 = 0 ;
V_34 = - V_48 ;
goto V_315;
}
if ( F_25 ( V_82 ) < F_28 ( V_82 -> V_310 ) + * V_304 ) {
F_7 ( V_115 , L_40 , * V_304 ,
F_28 ( V_82 -> V_310 ) ) ;
* V_304 = 0 ;
V_34 = - V_48 ;
goto V_315;
}
* V_303 = F_38 ( * V_304 , V_150 ) ;
if ( * V_303 == NULL ) {
V_34 = - V_72 ;
goto V_315;
}
memcpy ( * V_303 , V_82 -> V_2 . V_12 + F_28 ( V_82 -> V_310 ) ,
* V_304 ) ;
V_315:
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
int
F_63 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 )
{
int V_34 ;
struct V_318 V_319 ;
char * V_320 = NULL ;
V_319 . V_321 =
F_64 ( V_322 ) ;
V_34 = F_35 ( V_78 , V_5 , V_233 , V_235 ,
V_323 , true ,
( char * ) & V_319 ,
2 , & V_320 , NULL ) ;
F_7 ( V_45 , L_41 , V_34 ) ;
return V_34 ;
}
int
F_65 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 )
{
struct V_324 * V_80 ;
struct V_325 * V_82 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_83 V_84 [ 1 ] ;
int V_85 ;
int V_34 = 0 ;
F_7 ( V_45 , L_42 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_52 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_232 = V_233 ;
V_80 -> V_234 = V_235 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 1 , & V_85 , 0 ) ;
V_82 = (struct V_325 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 != 0 ) {
F_48 ( V_5 , V_326 ) ;
goto V_327;
}
V_327:
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
static int
F_66 ( unsigned int V_328 , unsigned int V_329 ,
struct V_1 * V_2 , unsigned int V_330 )
{
unsigned int V_331 = F_67 ( V_2 -> V_11 ) ;
char * V_332 = V_331 + 4 + ( char * ) V_2 ;
char * V_333 = 4 + V_328 + ( char * ) V_2 ;
char * V_334 = V_333 + V_329 ;
if ( V_329 < V_330 ) {
F_7 ( V_115 , L_43 ,
V_329 , V_330 ) ;
return - V_197 ;
}
if ( ( V_331 > 0x7FFFFF ) || ( V_329 > 0x7FFFFF ) ) {
F_7 ( V_115 , L_44 ,
V_329 , V_331 ) ;
return - V_197 ;
}
if ( ( V_333 > V_332 ) || ( V_334 > V_332 ) ) {
F_7 ( V_115 , L_45 ) ;
return - V_197 ;
}
return 0 ;
}
static int
F_68 ( unsigned int V_328 , unsigned int V_329 ,
struct V_1 * V_2 , unsigned int V_335 ,
char * V_336 )
{
char * V_333 = 4 + V_328 + ( char * ) V_2 ;
int V_34 ;
if ( ! V_336 )
return - V_197 ;
V_34 = F_66 ( V_328 , V_329 , V_2 , V_335 ) ;
if ( V_34 )
return V_34 ;
memcpy ( V_336 , V_333 , V_329 ) ;
return 0 ;
}
static int
F_69 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , T_10 V_337 ,
T_11 V_338 , T_11 V_339 , void * V_336 )
{
struct V_340 * V_80 ;
struct V_341 * V_82 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_34 = 0 ;
int V_85 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
F_7 ( V_45 , L_46 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_342 = V_343 ;
V_80 -> V_344 = V_337 ;
V_80 -> V_232 = V_233 ;
V_80 -> V_234 = V_235 ;
V_80 -> V_345 =
F_4 ( sizeof( struct V_340 ) - 1 - 4 ) ;
V_80 -> V_346 = F_5 ( V_338 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 1 , & V_85 , 0 ) ;
V_82 = (struct V_341 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 ) {
F_48 ( V_5 , V_347 ) ;
goto V_348;
}
V_34 = F_68 ( F_2 ( V_82 -> V_349 ) ,
F_28 ( V_82 -> V_346 ) ,
& V_82 -> V_2 , V_339 , V_336 ) ;
V_348:
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
int
F_70 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 ,
struct V_259 * V_336 )
{
return F_69 ( V_78 , V_5 , V_233 , V_235 ,
V_350 ,
sizeof( struct V_259 ) + V_284 * 2 ,
sizeof( struct V_259 ) , V_336 ) ;
}
int
F_71 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , T_12 * V_351 )
{
return F_69 ( V_78 , V_5 , V_233 , V_235 ,
V_352 ,
sizeof( struct V_353 ) ,
sizeof( struct V_353 ) , V_351 ) ;
}
static void
F_72 ( struct V_354 * V_355 )
{
struct V_38 * V_21 = V_355 -> V_356 ;
struct V_357 * V_358 = (struct V_357 * ) V_355 -> V_359 ;
unsigned int V_360 = 1 ;
if ( V_355 -> V_361 == V_362 )
V_360 = F_2 ( V_358 -> V_2 . V_15 ) ;
F_73 ( V_355 ) ;
F_74 ( V_21 , V_360 , V_363 ) ;
}
int
F_75 ( struct V_38 * V_21 )
{
struct V_364 * V_80 ;
int V_34 = 0 ;
struct V_83 V_84 ;
struct V_365 V_366 = { . V_367 = & V_84 ,
. V_368 = 1 } ;
F_7 ( V_45 , L_47 ) ;
V_34 = F_18 ( V_369 , NULL , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_15 = F_4 ( 1 ) ;
V_84 . V_108 = ( char * ) V_80 ;
V_84 . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_76 ( V_21 , & V_366 , NULL , F_72 , V_21 ,
V_363 ) ;
if ( V_34 )
F_7 ( V_45 , L_48 , V_34 ) ;
F_61 ( V_80 ) ;
return V_34 ;
}
int
F_77 ( const unsigned int V_78 , struct V_4 * V_5 , T_9 V_233 ,
T_9 V_235 )
{
struct V_370 * V_80 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_83 V_84 [ 1 ] ;
int V_85 ;
int V_34 = 0 ;
F_7 ( V_45 , L_49 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_63 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_232 = V_233 ;
V_80 -> V_234 = V_235 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 1 , & V_85 , 0 ) ;
if ( ( V_34 != 0 ) && V_5 )
F_48 ( V_5 , V_371 ) ;
F_33 ( V_85 , V_84 [ 0 ] . V_108 ) ;
return V_34 ;
}
static int
F_78 ( struct V_83 * V_84 , struct V_372 * V_373 ,
unsigned int V_374 , int V_375 )
{
int V_34 = - V_376 ;
struct V_377 * V_80 = NULL ;
V_34 = F_18 ( V_64 , V_373 -> V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
if ( V_373 -> V_5 -> V_20 -> V_21 == NULL )
return - V_378 ;
V_80 -> V_2 . V_16 = F_5 ( V_373 -> V_379 ) ;
V_80 -> V_232 = V_373 -> V_233 ;
V_80 -> V_234 = V_373 -> V_235 ;
V_80 -> V_380 = 0 ;
V_80 -> V_381 = 0 ;
V_80 -> V_159 = 0 ;
V_80 -> V_382 = 0 ;
V_80 -> V_383 = F_5 ( V_373 -> V_384 ) ;
V_80 -> V_385 = F_79 ( V_373 -> V_328 ) ;
if ( V_375 & V_386 ) {
if ( ! ( V_375 & V_387 ) ) {
V_80 -> V_2 . V_388 =
F_5 ( F_25 ( V_80 ) + 4 ) ;
} else
V_80 -> V_2 . V_388 = 0 ;
if ( V_375 & V_389 ) {
V_80 -> V_2 . V_30 |= V_390 ;
V_80 -> V_2 . V_27 = 0xFFFFFFFF ;
V_80 -> V_2 . V_25 = 0xFFFFFFFF ;
V_80 -> V_232 = 0xFFFFFFFF ;
V_80 -> V_234 = 0xFFFFFFFF ;
}
}
if ( V_374 > V_373 -> V_384 )
V_80 -> V_391 = F_5 ( V_374 ) ;
else
V_80 -> V_391 = 0 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
return V_34 ;
}
static void
F_80 ( struct V_354 * V_355 )
{
struct V_392 * V_393 = V_355 -> V_356 ;
struct V_4 * V_5 = F_81 ( V_393 -> V_394 -> V_395 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_1 * V_221 = (struct V_1 * ) V_393 -> V_84 . V_108 ;
unsigned int V_360 = 1 ;
struct V_365 V_366 = { . V_367 = & V_393 -> V_84 ,
. V_368 = 1 ,
. V_396 = V_393 -> V_397 ,
. V_398 = V_393 -> V_399 ,
. V_400 = V_393 -> V_401 ,
. V_402 = V_393 -> V_403 } ;
F_7 ( V_45 , L_50 ,
V_91 , V_355 -> V_355 , V_355 -> V_361 , V_393 -> V_404 ,
V_393 -> V_405 ) ;
switch ( V_355 -> V_361 ) {
case V_362 :
V_360 = F_2 ( V_221 -> V_15 ) ;
if ( V_21 -> V_29 ) {
int V_34 ;
V_34 = F_82 ( & V_366 , V_21 ) ;
if ( V_34 )
F_7 ( V_115 , L_51 ,
V_34 ) ;
}
F_83 ( V_393 -> V_406 ) ;
F_84 ( V_5 , V_393 -> V_406 ) ;
break;
case V_407 :
case V_408 :
V_393 -> V_404 = - V_54 ;
if ( V_21 -> V_29 && V_393 -> V_406 )
V_393 -> V_406 = 0 ;
F_83 ( V_393 -> V_406 ) ;
F_84 ( V_5 , V_393 -> V_406 ) ;
break;
default:
if ( V_393 -> V_404 != - V_409 )
V_393 -> V_404 = - V_48 ;
}
if ( V_393 -> V_404 )
F_48 ( V_5 , V_410 ) ;
F_85 ( V_411 , & V_393 -> V_412 ) ;
F_73 ( V_355 ) ;
F_74 ( V_21 , V_360 , 0 ) ;
}
int
F_86 ( struct V_392 * V_393 )
{
int V_34 , V_89 = 0 ;
struct V_1 * V_221 ;
struct V_372 V_373 ;
struct V_365 V_366 = { . V_367 = & V_393 -> V_84 ,
. V_368 = 1 } ;
struct V_38 * V_21 ;
F_7 ( V_45 , L_52 ,
V_91 , V_393 -> V_328 , V_393 -> V_405 ) ;
V_373 . V_5 = F_81 ( V_393 -> V_394 -> V_395 ) ;
V_373 . V_328 = V_393 -> V_328 ;
V_373 . V_384 = V_393 -> V_405 ;
V_373 . V_233 = V_393 -> V_394 -> V_230 . V_233 ;
V_373 . V_235 = V_393 -> V_394 -> V_230 . V_235 ;
V_373 . V_379 = V_393 -> V_379 ;
V_21 = V_373 . V_5 -> V_20 -> V_21 ;
V_34 = F_78 ( & V_393 -> V_84 , & V_373 , 0 , 0 ) ;
if ( V_34 ) {
if ( V_34 == - V_54 && V_393 -> V_413 ) {
V_393 -> V_413 = 0 ;
F_44 ( & V_21 -> V_414 ) ;
V_21 -> V_415 -- ;
F_45 ( & V_21 -> V_414 ) ;
}
return V_34 ;
}
V_221 = (struct V_1 * ) V_393 -> V_84 . V_108 ;
V_393 -> V_84 . V_109 = F_25 ( V_393 -> V_84 . V_108 ) + 4 ;
if ( V_393 -> V_413 ) {
V_221 -> V_24 = F_4 ( F_87 ( V_393 -> V_405 ,
V_416 ) ) ;
F_44 ( & V_21 -> V_414 ) ;
V_21 -> V_413 += V_393 -> V_413 -
F_2 ( V_221 -> V_24 ) ;
F_45 ( & V_21 -> V_414 ) ;
F_88 ( & V_21 -> V_417 ) ;
V_89 = V_418 ;
}
F_89 ( & V_393 -> V_419 ) ;
V_34 = F_76 ( V_373 . V_5 -> V_20 -> V_21 , & V_366 ,
V_420 , F_80 ,
V_393 , V_89 ) ;
if ( V_34 ) {
F_90 ( & V_393 -> V_419 , V_421 ) ;
F_48 ( V_373 . V_5 , V_410 ) ;
}
F_61 ( V_221 ) ;
return V_34 ;
}
int
F_91 ( const unsigned int V_78 , struct V_372 * V_373 ,
unsigned int * V_422 , char * * V_221 , int * V_423 )
{
int V_85 , V_34 = - V_376 ;
struct V_424 * V_82 = NULL ;
struct V_83 V_84 [ 1 ] ;
* V_422 = 0 ;
V_34 = F_78 ( V_84 , V_373 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_26 ( V_78 , V_373 -> V_5 -> V_20 , V_84 , 1 ,
& V_85 , V_165 ) ;
V_82 = (struct V_424 * ) V_84 [ 0 ] . V_108 ;
if ( V_82 -> V_2 . V_166 == V_425 ) {
F_33 ( V_85 , V_84 [ 0 ] . V_108 ) ;
return 0 ;
}
if ( V_34 ) {
F_48 ( V_373 -> V_5 , V_410 ) ;
F_7 ( V_115 , L_53 , V_34 ) ;
} else {
* V_422 = F_28 ( V_82 -> V_225 ) ;
if ( ( * V_422 > V_426 ) ||
( * V_422 > V_373 -> V_384 ) ) {
F_7 ( V_45 , L_54 ,
* V_422 , V_373 -> V_384 ) ;
V_34 = - V_48 ;
* V_422 = 0 ;
}
}
if ( * V_221 ) {
memcpy ( * V_221 , ( char * ) V_82 -> V_2 . V_12 + V_82 -> V_223 ,
* V_422 ) ;
F_33 ( V_85 , V_84 [ 0 ] . V_108 ) ;
} else if ( V_85 != V_141 ) {
* V_221 = V_84 [ 0 ] . V_108 ;
if ( V_85 == V_427 )
* V_423 = V_427 ;
else if ( V_85 == V_428 )
* V_423 = V_428 ;
}
return V_34 ;
}
static void
F_92 ( struct V_354 * V_355 )
{
struct V_429 * V_430 = V_355 -> V_356 ;
struct V_4 * V_5 = F_81 ( V_430 -> V_394 -> V_395 ) ;
unsigned int V_431 ;
struct V_432 * V_82 = (struct V_432 * ) V_355 -> V_359 ;
unsigned int V_360 = 1 ;
switch ( V_355 -> V_361 ) {
case V_362 :
V_360 = F_2 ( V_82 -> V_2 . V_15 ) ;
V_430 -> V_404 = F_93 ( V_355 , V_5 -> V_20 -> V_21 , 0 ) ;
if ( V_430 -> V_404 != 0 )
break;
V_431 = F_28 ( V_82 -> V_225 ) ;
if ( V_431 > V_430 -> V_405 )
V_431 &= 0xFFFF ;
if ( V_431 < V_430 -> V_405 )
V_430 -> V_404 = - V_433 ;
else
V_430 -> V_405 = V_431 ;
break;
case V_407 :
case V_408 :
V_430 -> V_404 = - V_54 ;
break;
default:
V_430 -> V_404 = - V_48 ;
break;
}
if ( V_430 -> V_404 )
F_48 ( V_5 , V_434 ) ;
F_85 ( V_411 , & V_430 -> V_412 ) ;
F_73 ( V_355 ) ;
F_74 ( V_5 -> V_20 -> V_21 , V_360 , 0 ) ;
}
int
F_94 ( struct V_429 * V_430 ,
void (* F_95)( struct V_435 * V_435 ) )
{
int V_34 = - V_376 , V_89 = 0 ;
struct V_436 * V_80 = NULL ;
struct V_4 * V_5 = F_81 ( V_430 -> V_394 -> V_395 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_83 V_84 ;
struct V_365 V_366 ;
V_34 = F_18 ( V_42 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 ) {
if ( V_34 == - V_54 && V_430 -> V_413 ) {
V_430 -> V_413 = 0 ;
F_44 ( & V_21 -> V_414 ) ;
V_21 -> V_415 -- ;
F_45 ( & V_21 -> V_414 ) ;
}
goto V_437;
}
V_80 -> V_2 . V_16 = F_5 ( V_430 -> V_394 -> V_379 ) ;
V_80 -> V_232 = V_430 -> V_394 -> V_230 . V_233 ;
V_80 -> V_234 = V_430 -> V_394 -> V_230 . V_235 ;
V_80 -> V_438 = 0 ;
V_80 -> V_439 = 0 ;
V_80 -> V_159 = 0 ;
V_80 -> V_385 = F_79 ( V_430 -> V_328 ) ;
V_80 -> V_223 = F_4 (
F_42 ( struct V_436 , V_168 ) - 4 ) ;
V_80 -> V_391 = 0 ;
V_84 . V_109 = F_25 ( V_80 ) + 4 - 1 ;
V_84 . V_108 = V_80 ;
V_366 . V_367 = & V_84 ;
V_366 . V_368 = 1 ;
V_366 . V_396 = V_430 -> V_397 ;
V_366 . V_398 = V_430 -> V_399 ;
V_366 . V_400 = V_430 -> V_401 ;
V_366 . V_402 = V_430 -> V_403 ;
F_7 ( V_45 , L_55 ,
V_430 -> V_328 , V_430 -> V_405 ) ;
V_80 -> V_383 = F_5 ( V_430 -> V_405 ) ;
F_24 ( & V_80 -> V_2 , V_430 -> V_405 - 1 ) ;
if ( V_430 -> V_413 ) {
V_80 -> V_2 . V_24 = F_4 ( F_87 ( V_430 -> V_405 ,
V_416 ) ) ;
F_44 ( & V_21 -> V_414 ) ;
V_21 -> V_413 += V_430 -> V_413 -
F_2 ( V_80 -> V_2 . V_24 ) ;
F_45 ( & V_21 -> V_414 ) ;
F_88 ( & V_21 -> V_417 ) ;
V_89 = V_418 ;
}
F_89 ( & V_430 -> V_419 ) ;
V_34 = F_76 ( V_21 , & V_366 , NULL , F_92 , V_430 ,
V_89 ) ;
if ( V_34 ) {
F_90 ( & V_430 -> V_419 , F_95 ) ;
F_48 ( V_5 , V_434 ) ;
}
V_437:
F_61 ( V_80 ) ;
return V_34 ;
}
int
F_96 ( const unsigned int V_78 , struct V_372 * V_373 ,
unsigned int * V_422 , struct V_83 * V_84 , int V_440 )
{
int V_34 = 0 ;
struct V_436 * V_80 = NULL ;
struct V_432 * V_82 = NULL ;
int V_85 ;
* V_422 = 0 ;
if ( V_440 < 1 )
return V_34 ;
V_34 = F_18 ( V_42 , V_373 -> V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
if ( V_373 -> V_5 -> V_20 -> V_21 == NULL )
return - V_378 ;
V_80 -> V_2 . V_16 = F_5 ( V_373 -> V_379 ) ;
V_80 -> V_232 = V_373 -> V_233 ;
V_80 -> V_234 = V_373 -> V_235 ;
V_80 -> V_438 = 0 ;
V_80 -> V_439 = 0 ;
V_80 -> V_159 = 0 ;
V_80 -> V_383 = F_5 ( V_373 -> V_384 ) ;
V_80 -> V_385 = F_79 ( V_373 -> V_328 ) ;
V_80 -> V_223 = F_4 (
F_42 ( struct V_436 , V_168 ) - 4 ) ;
V_80 -> V_391 = 0 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - 1 ;
F_24 ( V_80 , V_373 -> V_384 - 1 ) ;
V_34 = F_26 ( V_78 , V_373 -> V_5 -> V_20 , V_84 , V_440 + 1 ,
& V_85 , 0 ) ;
V_82 = (struct V_432 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 ) {
F_48 ( V_373 -> V_5 , V_434 ) ;
F_7 ( V_115 , L_56 , V_34 ) ;
} else
* V_422 = F_28 ( V_82 -> V_225 ) ;
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
static unsigned int
F_97 ( char * V_441 , char * V_334 , char * * V_442 , T_11 V_443 )
{
int V_444 ;
unsigned int V_445 = 0 ;
unsigned int V_446 = 0 ;
T_13 * V_447 ;
if ( V_441 == NULL )
return 0 ;
V_447 = ( T_13 * ) V_441 ;
while ( 1 ) {
V_447 = ( T_13 * )
( ( char * ) V_447 + V_446 ) ;
if ( ( char * ) V_447 + V_443 > V_334 ) {
F_7 ( V_115 , L_57 ) ;
break;
}
V_444 = F_28 ( V_447 -> V_448 ) ;
if ( ( char * ) V_447 + V_444 + V_443 > V_334 ) {
F_7 ( V_115 , L_58 ,
V_334 ) ;
break;
}
* V_442 = ( char * ) V_447 ;
V_445 ++ ;
V_446 = F_28 ( V_447 -> V_449 ) ;
if ( ! V_446 )
break;
}
return V_445 ;
}
int
F_98 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , int V_450 ,
struct V_451 * V_452 )
{
struct V_453 * V_80 ;
struct V_454 * V_82 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_34 = 0 ;
int V_444 ;
int V_85 ;
unsigned char * V_455 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
T_1 V_456 = F_4 ( '*' ) ;
char * V_332 ;
unsigned int V_457 = V_458 ;
T_11 V_459 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_67 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
switch ( V_452 -> V_460 ) {
case V_461 :
V_80 -> V_462 = V_463 ;
V_459 = sizeof( T_13 ) - 1 ;
break;
case V_464 :
V_80 -> V_462 = V_465 ;
V_459 = sizeof( V_466 ) - 1 ;
break;
default:
F_7 ( V_115 , L_59 ,
V_452 -> V_460 ) ;
V_34 = - V_197 ;
goto V_467;
}
V_80 -> V_468 = F_5 ( V_450 ) ;
V_80 -> V_232 = V_233 ;
V_80 -> V_234 = V_235 ;
V_444 = 0x2 ;
V_455 = V_80 -> V_168 ;
memcpy ( V_455 , & V_456 , V_444 ) ;
V_80 -> V_469 =
F_4 ( sizeof( struct V_453 ) - 1 - 4 ) ;
V_80 -> V_448 = F_4 ( V_444 ) ;
V_457 = F_27 (unsigned int, output_size, server->maxBuf) ;
V_457 = F_27 (unsigned int, output_size, 2 << 15 ) ;
V_80 -> V_346 = F_5 ( V_457 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - 1 ;
V_84 [ 1 ] . V_108 = ( char * ) ( V_80 -> V_168 ) ;
V_84 [ 1 ] . V_109 = V_444 ;
F_24 ( V_80 , V_444 - 1 ) ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 2 , & V_85 , 0 ) ;
V_82 = (struct V_454 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 ) {
if ( V_34 == - V_409 && V_82 -> V_2 . V_166 == V_470 ) {
V_452 -> V_471 = true ;
V_34 = 0 ;
}
F_48 ( V_5 , V_472 ) ;
goto V_467;
}
V_34 = F_66 ( F_2 ( V_82 -> V_349 ) ,
F_28 ( V_82 -> V_346 ) , & V_82 -> V_2 ,
V_459 ) ;
if ( V_34 )
goto V_467;
V_452 -> V_473 = true ;
if ( V_452 -> V_474 ) {
if ( V_452 -> V_475 )
F_61 ( V_452 -> V_474 ) ;
else
F_99 ( V_452 -> V_474 ) ;
}
V_452 -> V_474 = ( char * ) V_82 ;
V_452 -> V_476 = V_452 -> V_477 = 4 +
( char * ) & V_82 -> V_2 + F_2 ( V_82 -> V_349 ) ;
V_332 = F_25 ( V_82 ) + 4 + ( char * ) & V_82 -> V_2 ;
V_452 -> V_478 =
F_97 ( V_452 -> V_476 , V_332 ,
& V_452 -> V_477 , V_459 ) ;
V_452 -> V_479 += V_452 -> V_478 ;
F_7 ( V_45 , L_60 ,
V_452 -> V_478 , V_452 -> V_479 ,
V_452 -> V_476 , V_452 -> V_477 ) ;
if ( V_85 == V_428 )
V_452 -> V_475 = false ;
else if ( V_85 == V_427 )
V_452 -> V_475 = true ;
else
F_7 ( V_115 , L_61 ) ;
return V_34 ;
V_467:
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
static int
F_100 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , T_4 V_379 , int V_337 ,
unsigned int V_249 , void * * V_336 , unsigned int * V_443 )
{
struct V_480 * V_80 ;
struct V_481 * V_82 = NULL ;
struct V_83 * V_84 ;
int V_34 = 0 ;
int V_85 ;
unsigned int V_482 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( ! V_249 )
return - V_197 ;
V_84 = F_38 ( sizeof( struct V_83 ) * V_249 , V_150 ) ;
if ( ! V_84 )
return - V_72 ;
V_34 = F_18 ( V_70 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 ) {
F_37 ( V_84 ) ;
return V_34 ;
}
V_80 -> V_2 . V_16 = F_5 ( V_379 ) ;
V_80 -> V_342 = V_343 ;
V_80 -> V_344 = V_337 ;
V_80 -> V_232 = V_233 ;
V_80 -> V_234 = V_235 ;
V_80 -> V_483 =
F_4 ( sizeof( struct V_480 ) - 1 - 4 ) ;
V_80 -> V_484 = F_5 ( * V_443 ) ;
F_24 ( V_80 , * V_443 - 1 ) ;
memcpy ( V_80 -> V_168 , * V_336 , * V_443 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
for ( V_482 = 1 ; V_482 < V_249 ; V_482 ++ ) {
F_24 ( V_80 , V_443 [ V_482 ] ) ;
F_57 ( & V_80 -> V_484 , V_443 [ V_482 ] ) ;
V_84 [ V_482 ] . V_108 = ( char * ) V_336 [ V_482 ] ;
V_84 [ V_482 ] . V_109 = V_443 [ V_482 ] ;
}
V_34 = F_26 ( V_78 , V_20 , V_84 , V_249 , & V_85 , 0 ) ;
V_82 = (struct V_481 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 != 0 )
F_48 ( V_5 , V_485 ) ;
F_33 ( V_85 , V_82 ) ;
F_37 ( V_84 ) ;
return V_34 ;
}
int
F_101 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , T_1 * V_486 )
{
struct V_487 V_488 ;
void * * V_336 ;
unsigned int V_443 [ 2 ] ;
int V_34 ;
int V_444 = ( 2 * F_60 ( ( V_283 * ) V_486 , V_284 ) ) ;
V_336 = F_38 ( sizeof( void * ) * 2 , V_150 ) ;
if ( ! V_336 )
return - V_72 ;
V_488 . V_489 = 1 ;
V_488 . V_490 = 0 ;
V_488 . V_448 = F_5 ( V_444 ) ;
V_336 [ 0 ] = & V_488 ;
V_443 [ 0 ] = sizeof( struct V_487 ) ;
V_336 [ 1 ] = V_486 ;
V_443 [ 1 ] = V_444 + 2 ;
V_34 = F_100 ( V_78 , V_5 , V_233 , V_235 ,
V_17 -> V_18 , V_491 , 2 , V_336 ,
V_443 ) ;
F_37 ( V_336 ) ;
return V_34 ;
}
int
F_102 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , T_1 * V_486 )
{
struct V_492 V_488 ;
void * * V_336 ;
unsigned int V_443 [ 2 ] ;
int V_34 ;
int V_444 = ( 2 * F_60 ( ( V_283 * ) V_486 , V_284 ) ) ;
V_336 = F_38 ( sizeof( void * ) * 2 , V_150 ) ;
if ( ! V_336 )
return - V_72 ;
V_488 . V_489 = 0 ;
V_488 . V_490 = 0 ;
V_488 . V_448 = F_5 ( V_444 ) ;
V_336 [ 0 ] = & V_488 ;
V_443 [ 0 ] = sizeof( struct V_492 ) ;
V_336 [ 1 ] = V_486 ;
V_443 [ 1 ] = V_444 + 2 ;
V_34 = F_100 ( V_78 , V_5 , V_233 , V_235 ,
V_17 -> V_18 , V_493 , 2 , V_336 , V_443 ) ;
F_37 ( V_336 ) ;
return V_34 ;
}
int
F_103 ( const unsigned int V_78 , struct V_4 * V_5 , T_9 V_233 ,
T_9 V_235 , T_4 V_379 , T_12 * V_494 , bool V_495 )
{
struct V_496 V_488 ;
void * V_336 ;
unsigned int V_443 ;
V_488 . V_293 = * V_494 ;
V_336 = & V_488 ;
V_443 = sizeof( struct V_496 ) ;
if ( V_495 )
return F_100 ( V_78 , V_5 , V_233 , V_235 ,
V_379 , V_497 , 1 , & V_336 , & V_443 ) ;
else
return F_100 ( V_78 , V_5 , V_233 , V_235 ,
V_379 , V_498 , 1 , & V_336 , & V_443 ) ;
}
int
F_104 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , T_14 * V_221 )
{
unsigned int V_443 ;
V_443 = sizeof( T_14 ) ;
return F_100 ( V_78 , V_5 , V_233 , V_235 ,
V_17 -> V_18 , V_499 , 1 ,
( void * * ) & V_221 , & V_443 ) ;
}
int
F_105 ( const unsigned int V_78 , struct V_4 * V_5 ,
const T_9 V_233 , const T_9 V_235 ,
T_7 V_500 )
{
int V_34 ;
struct V_501 * V_80 = NULL ;
F_7 ( V_45 , L_62 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_502 = V_235 ;
V_80 -> V_503 = V_233 ;
V_80 -> V_298 = V_500 ;
V_80 -> V_2 . V_15 = F_4 ( 1 ) ;
V_34 = F_47 ( V_78 , V_5 -> V_20 , ( char * ) V_80 , V_504 ) ;
if ( V_34 ) {
F_48 ( V_5 , V_505 ) ;
F_7 ( V_45 , L_63 , V_34 ) ;
}
return V_34 ;
}
static void
F_106 ( struct V_506 * V_507 ,
struct V_508 * V_509 )
{
V_509 -> V_510 = F_28 ( V_507 -> V_511 ) *
F_28 ( V_507 -> V_512 ) ;
V_509 -> V_513 = F_107 ( V_507 -> V_514 ) ;
V_509 -> V_515 = F_107 ( V_507 -> V_516 ) ;
V_509 -> V_517 = F_107 ( V_507 -> V_518 ) ;
return;
}
static int
F_108 ( struct V_83 * V_84 , struct V_4 * V_5 , int V_519 ,
int V_520 , T_9 V_233 , T_9 V_235 )
{
int V_34 ;
struct V_340 * V_80 ;
F_7 ( V_45 , L_64 , V_519 ) ;
if ( ( V_5 -> V_20 == NULL ) || ( V_5 -> V_20 -> V_21 == NULL ) )
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_342 = V_521 ;
V_80 -> V_344 = V_519 ;
V_80 -> V_232 = V_233 ;
V_80 -> V_234 = V_235 ;
V_80 -> V_345 =
F_4 ( sizeof( struct V_340 ) - 1 - 4 ) ;
V_80 -> V_346 = F_5 (
V_520 + sizeof( struct V_341 ) - 1 - 4 ) ;
V_84 -> V_108 = ( char * ) V_80 ;
V_84 -> V_109 = F_25 ( V_80 ) + 4 ;
return 0 ;
}
int
F_109 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , struct V_508 * V_522 )
{
struct V_341 * V_82 = NULL ;
struct V_83 V_84 ;
int V_34 = 0 ;
int V_85 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_506 * V_488 = NULL ;
V_34 = F_108 ( & V_84 , V_5 , V_523 ,
sizeof( struct V_506 ) ,
V_233 , V_235 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_26 ( V_78 , V_20 , & V_84 , 1 , & V_85 , 0 ) ;
if ( V_34 ) {
F_48 ( V_5 , V_347 ) ;
goto V_524;
}
V_82 = (struct V_341 * ) V_84 . V_108 ;
V_488 = (struct V_506 * ) ( 4 +
F_2 ( V_82 -> V_349 ) + ( char * ) & V_82 -> V_2 ) ;
V_34 = F_66 ( F_2 ( V_82 -> V_349 ) ,
F_28 ( V_82 -> V_346 ) , & V_82 -> V_2 ,
sizeof( struct V_506 ) ) ;
if ( ! V_34 )
F_106 ( V_488 , V_522 ) ;
V_524:
F_33 ( V_85 , V_84 . V_108 ) ;
return V_34 ;
}
int
F_110 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , int V_519 )
{
struct V_341 * V_82 = NULL ;
struct V_83 V_84 ;
int V_34 = 0 ;
int V_85 , V_525 , V_339 ;
struct V_37 * V_20 = V_5 -> V_20 ;
unsigned int V_526 , V_328 ;
if ( V_519 == V_527 ) {
V_525 = sizeof( V_528 ) ;
V_339 = sizeof( V_528 ) ;
} else if ( V_519 == V_529 ) {
V_525 = sizeof( V_530 ) ;
V_339 = V_531 ;
} else if ( V_519 == V_532 ) {
V_525 = sizeof( struct V_533 ) ;
V_339 = sizeof( struct V_533 ) ;
} else {
F_7 ( V_45 , L_65 , V_519 ) ;
return - V_197 ;
}
V_34 = F_108 ( & V_84 , V_5 , V_519 , V_525 ,
V_233 , V_235 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_26 ( V_78 , V_20 , & V_84 , 1 , & V_85 , 0 ) ;
if ( V_34 ) {
F_48 ( V_5 , V_347 ) ;
goto V_534;
}
V_82 = (struct V_341 * ) V_84 . V_108 ;
V_526 = F_28 ( V_82 -> V_346 ) ;
V_328 = F_2 ( V_82 -> V_349 ) ;
V_34 = F_66 ( V_328 , V_526 , & V_82 -> V_2 , V_339 ) ;
if ( V_34 )
goto V_534;
if ( V_519 == V_529 )
memcpy ( & V_5 -> V_535 , 4 + V_328
+ ( char * ) & V_82 -> V_2 , F_27 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_519 == V_527 )
memcpy ( & V_5 -> V_536 , 4 + V_328
+ ( char * ) & V_82 -> V_2 , sizeof( V_528 ) ) ;
else if ( V_519 == V_532 ) {
struct V_533 * V_537 = (struct V_533 * )
( 4 + V_328 + ( char * ) & V_82 -> V_2 ) ;
V_5 -> V_538 = F_28 ( V_537 -> V_30 ) ;
V_5 -> V_539 =
F_28 ( V_537 -> V_540 ) ;
}
V_534:
F_33 ( V_85 , V_84 . V_108 ) ;
return V_34 ;
}
int
F_111 ( const unsigned int V_78 , struct V_4 * V_5 ,
const T_15 V_541 , const T_15 V_235 , const T_8 V_379 ,
const T_8 V_542 , struct V_543 * V_221 )
{
int V_34 = 0 ;
struct V_544 * V_80 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_545 ;
unsigned int V_546 ;
F_7 ( V_45 , L_66 , V_542 ) ;
V_34 = F_18 ( V_65 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_16 = F_5 ( V_379 ) ;
V_80 -> V_547 = F_4 ( V_542 ) ;
V_80 -> V_232 = V_541 ;
V_80 -> V_234 = V_235 ;
V_546 = V_542 * sizeof( struct V_543 ) ;
F_24 ( V_80 , V_546 - sizeof( struct V_543 ) ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - V_546 ;
V_84 [ 1 ] . V_108 = ( char * ) V_221 ;
V_84 [ 1 ] . V_109 = V_546 ;
F_21 ( & V_5 -> V_74 . V_548 . V_549 ) ;
V_34 = F_26 ( V_78 , V_5 -> V_20 , V_84 , 2 , & V_545 , V_550 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_67 , V_34 ) ;
F_48 ( V_5 , V_551 ) ;
}
return V_34 ;
}
int
F_112 ( const unsigned int V_78 , struct V_4 * V_5 ,
const T_15 V_541 , const T_15 V_235 , const T_8 V_379 ,
const T_15 V_384 , const T_15 V_328 , const T_8 V_552 ,
const bool V_553 )
{
struct V_543 V_554 ;
V_554 . V_385 = F_79 ( V_328 ) ;
V_554 . V_383 = F_79 ( V_384 ) ;
V_554 . V_30 = F_5 ( V_552 ) ;
if ( ! V_553 && V_552 != V_555 )
V_554 . V_30 |= F_5 ( V_556 ) ;
return F_111 ( V_78 , V_5 , V_541 , V_235 , V_379 , 1 , & V_554 ) ;
}
int
F_113 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_7 * V_557 , const T_5 V_558 )
{
int V_34 ;
struct V_559 * V_80 = NULL ;
F_7 ( V_45 , L_68 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_15 = F_4 ( 1 ) ;
V_80 -> V_13 = F_4 ( 36 ) ;
F_24 ( V_80 , 12 ) ;
memcpy ( V_80 -> V_560 , V_557 , 16 ) ;
V_80 -> V_561 = V_558 ;
V_34 = F_47 ( V_78 , V_5 -> V_20 , ( char * ) V_80 , V_504 ) ;
if ( V_34 ) {
F_48 ( V_5 , V_505 ) ;
F_7 ( V_45 , L_69 , V_34 ) ;
}
return V_34 ;
}
