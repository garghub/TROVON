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
if ( V_256 -> V_269 & V_272 )
V_266 |= V_273 ;
V_80 -> V_274 = V_275 ;
V_80 -> V_276 = F_5 ( V_256 -> V_277 ) ;
V_80 -> V_278 = F_5 ( V_266 ) ;
V_80 -> V_279 = V_280 ;
V_80 -> V_281 = F_5 ( V_256 -> V_282 ) ;
V_80 -> V_283 = F_5 ( V_256 -> V_269 & V_284 ) ;
V_262 = ( 2 * F_60 ( ( V_285 * ) V_258 , V_286 ) ) + 2 ;
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
if ( ! V_21 -> V_287 )
* V_247 = V_288 ;
if ( ! ( V_21 -> V_22 & V_289 ) ||
* V_247 == V_288 )
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
if ( * V_247 == V_290 ) {
if ( V_21 -> V_22 & V_289 ) {
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
F_48 ( V_5 , V_291 ) ;
if ( V_261 )
* V_261 = F_62 ( V_82 , F_25 ( V_82 ) + 4 ,
V_150 ) ;
goto V_292;
}
V_256 -> V_230 -> V_233 = V_82 -> V_232 ;
V_256 -> V_230 -> V_235 = V_82 -> V_234 ;
if ( V_221 ) {
memcpy ( V_221 , & V_82 -> V_293 , 32 ) ;
V_221 -> V_294 = V_82 -> V_294 ;
V_221 -> V_295 = V_82 -> V_296 ;
V_221 -> V_297 = V_82 -> V_278 ;
V_221 -> V_298 = F_5 ( 1 ) ;
V_221 -> V_299 = 0 ;
}
if ( V_82 -> V_300 == V_253 )
* V_247 = F_55 ( V_21 , V_82 , & V_256 -> V_230 -> V_237 ) ;
else
* V_247 = V_82 -> V_300 ;
V_292:
F_37 ( V_263 ) ;
F_37 ( V_268 ) ;
F_37 ( V_267 ) ;
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
int
F_35 ( const unsigned int V_78 , struct V_4 * V_5 , T_9 V_233 ,
T_9 V_235 , T_4 V_301 , bool V_302 , char * V_303 ,
T_4 V_304 , char * * V_305 , T_4 * V_306 )
{
struct V_307 * V_80 ;
struct V_308 * V_82 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_83 V_84 [ 2 ] ;
int V_85 ;
int V_265 ;
int V_34 = 0 ;
F_7 ( V_45 , L_38 ) ;
if ( V_305 != NULL )
* V_305 = NULL ;
if ( V_306 )
* V_306 = 0 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_66 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_309 = F_5 ( V_301 ) ;
V_80 -> V_232 = V_233 ;
V_80 -> V_234 = V_235 ;
if ( V_304 ) {
V_80 -> V_310 = F_5 ( V_304 ) ;
V_80 -> V_311 =
F_5 ( F_42 ( struct V_307 , V_168 ) - 4 ) ;
V_84 [ 1 ] . V_108 = V_303 ;
V_84 [ 1 ] . V_109 = V_304 ;
V_265 = 2 ;
} else
V_265 = 1 ;
V_80 -> V_312 = 0 ;
V_80 -> V_313 = 0 ;
V_80 -> V_314 = F_5 ( 0xFF00 ) ;
if ( V_302 )
V_80 -> V_30 = F_5 ( V_315 ) ;
else
V_80 -> V_30 = 0 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
if ( V_304 ) {
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - 1 ;
F_24 ( V_80 , V_304 - 1 ) ;
} else
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_26 ( V_78 , V_20 , V_84 , V_265 , & V_85 , 0 ) ;
V_82 = (struct V_308 * ) V_84 [ 0 ] . V_108 ;
if ( ( V_34 != 0 ) && ( V_34 != - V_197 ) ) {
if ( V_5 )
F_48 ( V_5 , V_316 ) ;
goto V_317;
} else if ( V_34 == - V_197 ) {
if ( ( V_301 != V_318 ) &&
( V_301 != V_319 ) ) {
if ( V_5 )
F_48 ( V_5 , V_316 ) ;
goto V_317;
}
}
if ( ( V_306 == NULL ) || ( V_305 == NULL ) )
goto V_317;
* V_306 = F_28 ( V_82 -> V_313 ) ;
if ( * V_306 == 0 )
goto V_317;
else if ( * V_306 > 0xFF00 ) {
F_7 ( V_115 , L_39 , * V_306 ) ;
* V_306 = 0 ;
V_34 = - V_48 ;
goto V_317;
}
if ( F_25 ( V_82 ) < F_28 ( V_82 -> V_312 ) + * V_306 ) {
F_7 ( V_115 , L_40 , * V_306 ,
F_28 ( V_82 -> V_312 ) ) ;
* V_306 = 0 ;
V_34 = - V_48 ;
goto V_317;
}
* V_305 = F_38 ( * V_306 , V_150 ) ;
if ( * V_305 == NULL ) {
V_34 = - V_72 ;
goto V_317;
}
memcpy ( * V_305 , V_82 -> V_2 . V_12 + F_28 ( V_82 -> V_312 ) ,
* V_306 ) ;
V_317:
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
int
F_63 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 )
{
int V_34 ;
struct V_320 V_321 ;
char * V_322 = NULL ;
V_321 . V_323 =
F_64 ( V_324 ) ;
V_34 = F_35 ( V_78 , V_5 , V_233 , V_235 ,
V_325 , true ,
( char * ) & V_321 ,
2 , & V_322 , NULL ) ;
F_7 ( V_45 , L_41 , V_34 ) ;
return V_34 ;
}
int
F_65 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 )
{
struct V_326 * V_80 ;
struct V_327 * V_82 ;
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
V_82 = (struct V_327 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 != 0 ) {
F_48 ( V_5 , V_328 ) ;
goto V_329;
}
V_329:
F_33 ( V_85 , V_82 ) ;
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
F_7 ( V_115 , L_43 ,
V_331 , V_332 ) ;
return - V_197 ;
}
if ( ( V_333 > 0x7FFFFF ) || ( V_331 > 0x7FFFFF ) ) {
F_7 ( V_115 , L_44 ,
V_331 , V_333 ) ;
return - V_197 ;
}
if ( ( V_335 > V_334 ) || ( V_336 > V_334 ) ) {
F_7 ( V_115 , L_45 ) ;
return - V_197 ;
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
return - V_197 ;
V_34 = F_66 ( V_330 , V_331 , V_2 , V_337 ) ;
if ( V_34 )
return V_34 ;
memcpy ( V_338 , V_335 , V_331 ) ;
return 0 ;
}
static int
F_69 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , T_10 V_339 ,
T_11 V_340 , T_11 V_341 , void * V_338 )
{
struct V_342 * V_80 ;
struct V_343 * V_82 = NULL ;
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
V_80 -> V_344 = V_345 ;
V_80 -> V_346 = V_339 ;
V_80 -> V_232 = V_233 ;
V_80 -> V_234 = V_235 ;
V_80 -> V_347 =
F_4 ( sizeof( struct V_342 ) - 1 - 4 ) ;
V_80 -> V_348 = F_5 ( V_340 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 1 , & V_85 , 0 ) ;
V_82 = (struct V_343 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 ) {
F_48 ( V_5 , V_349 ) ;
goto V_350;
}
V_34 = F_68 ( F_2 ( V_82 -> V_351 ) ,
F_28 ( V_82 -> V_348 ) ,
& V_82 -> V_2 , V_341 , V_338 ) ;
V_350:
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
int
F_70 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 ,
struct V_259 * V_338 )
{
return F_69 ( V_78 , V_5 , V_233 , V_235 ,
V_352 ,
sizeof( struct V_259 ) + V_286 * 2 ,
sizeof( struct V_259 ) , V_338 ) ;
}
int
F_71 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , T_12 * V_353 )
{
return F_69 ( V_78 , V_5 , V_233 , V_235 ,
V_354 ,
sizeof( struct V_355 ) ,
sizeof( struct V_355 ) , V_353 ) ;
}
static void
F_72 ( struct V_356 * V_357 )
{
struct V_38 * V_21 = V_357 -> V_358 ;
struct V_359 * V_360 = (struct V_359 * ) V_357 -> V_361 ;
unsigned int V_362 = 1 ;
if ( V_357 -> V_363 == V_364 )
V_362 = F_2 ( V_360 -> V_2 . V_15 ) ;
F_73 ( V_357 ) ;
F_74 ( V_21 , V_362 , V_365 ) ;
}
int
F_75 ( struct V_38 * V_21 )
{
struct V_366 * V_80 ;
int V_34 = 0 ;
struct V_83 V_84 ;
struct V_367 V_368 = { . V_369 = & V_84 ,
. V_370 = 1 } ;
F_7 ( V_45 , L_47 ) ;
V_34 = F_18 ( V_371 , NULL , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_15 = F_4 ( 1 ) ;
V_84 . V_108 = ( char * ) V_80 ;
V_84 . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_76 ( V_21 , & V_368 , NULL , F_72 , V_21 ,
V_365 ) ;
if ( V_34 )
F_7 ( V_45 , L_48 , V_34 ) ;
F_61 ( V_80 ) ;
return V_34 ;
}
int
F_77 ( const unsigned int V_78 , struct V_4 * V_5 , T_9 V_233 ,
T_9 V_235 )
{
struct V_372 * V_80 ;
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
F_48 ( V_5 , V_373 ) ;
F_33 ( V_85 , V_84 [ 0 ] . V_108 ) ;
return V_34 ;
}
static int
F_78 ( struct V_83 * V_84 , struct V_374 * V_375 ,
unsigned int V_376 , int V_377 )
{
int V_34 = - V_378 ;
struct V_379 * V_80 = NULL ;
V_34 = F_18 ( V_64 , V_375 -> V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
if ( V_375 -> V_5 -> V_20 -> V_21 == NULL )
return - V_380 ;
V_80 -> V_2 . V_16 = F_5 ( V_375 -> V_381 ) ;
V_80 -> V_232 = V_375 -> V_233 ;
V_80 -> V_234 = V_375 -> V_235 ;
V_80 -> V_382 = 0 ;
V_80 -> V_383 = 0 ;
V_80 -> V_159 = 0 ;
V_80 -> V_384 = 0 ;
V_80 -> V_385 = F_5 ( V_375 -> V_386 ) ;
V_80 -> V_387 = F_79 ( V_375 -> V_330 ) ;
if ( V_377 & V_388 ) {
if ( ! ( V_377 & V_389 ) ) {
V_80 -> V_2 . V_390 =
F_5 ( F_25 ( V_80 ) + 4 ) ;
} else
V_80 -> V_2 . V_390 = 0 ;
if ( V_377 & V_391 ) {
V_80 -> V_2 . V_30 |= V_392 ;
V_80 -> V_2 . V_27 = 0xFFFFFFFF ;
V_80 -> V_2 . V_25 = 0xFFFFFFFF ;
V_80 -> V_232 = 0xFFFFFFFF ;
V_80 -> V_234 = 0xFFFFFFFF ;
}
}
if ( V_376 > V_375 -> V_386 )
V_80 -> V_393 = F_5 ( V_376 ) ;
else
V_80 -> V_393 = 0 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
return V_34 ;
}
static void
F_80 ( struct V_356 * V_357 )
{
struct V_394 * V_395 = V_357 -> V_358 ;
struct V_4 * V_5 = F_81 ( V_395 -> V_396 -> V_397 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_1 * V_221 = (struct V_1 * ) V_395 -> V_84 . V_108 ;
unsigned int V_362 = 1 ;
struct V_367 V_368 = { . V_369 = & V_395 -> V_84 ,
. V_370 = 1 ,
. V_398 = V_395 -> V_399 ,
. V_400 = V_395 -> V_401 ,
. V_402 = V_395 -> V_403 ,
. V_404 = V_395 -> V_405 } ;
F_7 ( V_45 , L_50 ,
V_91 , V_357 -> V_357 , V_357 -> V_363 , V_395 -> V_406 ,
V_395 -> V_407 ) ;
switch ( V_357 -> V_363 ) {
case V_364 :
V_362 = F_2 ( V_221 -> V_15 ) ;
if ( V_21 -> V_29 ) {
int V_34 ;
V_34 = F_82 ( & V_368 , V_21 ) ;
if ( V_34 )
F_7 ( V_115 , L_51 ,
V_34 ) ;
}
F_83 ( V_395 -> V_408 ) ;
F_84 ( V_5 , V_395 -> V_408 ) ;
break;
case V_409 :
case V_410 :
V_395 -> V_406 = - V_54 ;
if ( V_21 -> V_29 && V_395 -> V_408 )
V_395 -> V_408 = 0 ;
F_83 ( V_395 -> V_408 ) ;
F_84 ( V_5 , V_395 -> V_408 ) ;
break;
default:
if ( V_395 -> V_406 != - V_411 )
V_395 -> V_406 = - V_48 ;
}
if ( V_395 -> V_406 )
F_48 ( V_5 , V_412 ) ;
F_85 ( V_413 , & V_395 -> V_414 ) ;
F_73 ( V_357 ) ;
F_74 ( V_21 , V_362 , 0 ) ;
}
int
F_86 ( struct V_394 * V_395 )
{
int V_34 , V_89 = 0 ;
struct V_1 * V_221 ;
struct V_374 V_375 ;
struct V_367 V_368 = { . V_369 = & V_395 -> V_84 ,
. V_370 = 1 } ;
struct V_38 * V_21 ;
F_7 ( V_45 , L_52 ,
V_91 , V_395 -> V_330 , V_395 -> V_407 ) ;
V_375 . V_5 = F_81 ( V_395 -> V_396 -> V_397 ) ;
V_375 . V_330 = V_395 -> V_330 ;
V_375 . V_386 = V_395 -> V_407 ;
V_375 . V_233 = V_395 -> V_396 -> V_230 . V_233 ;
V_375 . V_235 = V_395 -> V_396 -> V_230 . V_235 ;
V_375 . V_381 = V_395 -> V_381 ;
V_21 = V_375 . V_5 -> V_20 -> V_21 ;
V_34 = F_78 ( & V_395 -> V_84 , & V_375 , 0 , 0 ) ;
if ( V_34 ) {
if ( V_34 == - V_54 && V_395 -> V_415 ) {
V_395 -> V_415 = 0 ;
F_44 ( & V_21 -> V_416 ) ;
V_21 -> V_417 -- ;
F_45 ( & V_21 -> V_416 ) ;
}
return V_34 ;
}
V_221 = (struct V_1 * ) V_395 -> V_84 . V_108 ;
V_395 -> V_84 . V_109 = F_25 ( V_395 -> V_84 . V_108 ) + 4 ;
if ( V_395 -> V_415 ) {
V_221 -> V_24 = F_4 ( F_87 ( V_395 -> V_407 ,
V_418 ) ) ;
F_44 ( & V_21 -> V_416 ) ;
V_21 -> V_415 += V_395 -> V_415 -
F_2 ( V_221 -> V_24 ) ;
F_45 ( & V_21 -> V_416 ) ;
F_88 ( & V_21 -> V_419 ) ;
V_89 = V_420 ;
}
F_89 ( & V_395 -> V_421 ) ;
V_34 = F_76 ( V_375 . V_5 -> V_20 -> V_21 , & V_368 ,
V_422 , F_80 ,
V_395 , V_89 ) ;
if ( V_34 ) {
F_90 ( & V_395 -> V_421 , V_423 ) ;
F_48 ( V_375 . V_5 , V_412 ) ;
}
F_61 ( V_221 ) ;
return V_34 ;
}
int
F_91 ( const unsigned int V_78 , struct V_374 * V_375 ,
unsigned int * V_424 , char * * V_221 , int * V_425 )
{
int V_85 , V_34 = - V_378 ;
struct V_426 * V_82 = NULL ;
struct V_83 V_84 [ 1 ] ;
* V_424 = 0 ;
V_34 = F_78 ( V_84 , V_375 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_26 ( V_78 , V_375 -> V_5 -> V_20 , V_84 , 1 ,
& V_85 , V_165 ) ;
V_82 = (struct V_426 * ) V_84 [ 0 ] . V_108 ;
if ( V_82 -> V_2 . V_166 == V_427 ) {
F_33 ( V_85 , V_84 [ 0 ] . V_108 ) ;
return 0 ;
}
if ( V_34 ) {
F_48 ( V_375 -> V_5 , V_412 ) ;
F_7 ( V_115 , L_53 , V_34 ) ;
} else {
* V_424 = F_28 ( V_82 -> V_225 ) ;
if ( ( * V_424 > V_428 ) ||
( * V_424 > V_375 -> V_386 ) ) {
F_7 ( V_45 , L_54 ,
* V_424 , V_375 -> V_386 ) ;
V_34 = - V_48 ;
* V_424 = 0 ;
}
}
if ( * V_221 ) {
memcpy ( * V_221 , ( char * ) V_82 -> V_2 . V_12 + V_82 -> V_223 ,
* V_424 ) ;
F_33 ( V_85 , V_84 [ 0 ] . V_108 ) ;
} else if ( V_85 != V_141 ) {
* V_221 = V_84 [ 0 ] . V_108 ;
if ( V_85 == V_429 )
* V_425 = V_429 ;
else if ( V_85 == V_430 )
* V_425 = V_430 ;
}
return V_34 ;
}
static void
F_92 ( struct V_356 * V_357 )
{
struct V_431 * V_432 = V_357 -> V_358 ;
struct V_4 * V_5 = F_81 ( V_432 -> V_396 -> V_397 ) ;
unsigned int V_433 ;
struct V_434 * V_82 = (struct V_434 * ) V_357 -> V_361 ;
unsigned int V_362 = 1 ;
switch ( V_357 -> V_363 ) {
case V_364 :
V_362 = F_2 ( V_82 -> V_2 . V_15 ) ;
V_432 -> V_406 = F_93 ( V_357 , V_5 -> V_20 -> V_21 , 0 ) ;
if ( V_432 -> V_406 != 0 )
break;
V_433 = F_28 ( V_82 -> V_225 ) ;
if ( V_433 > V_432 -> V_407 )
V_433 &= 0xFFFF ;
if ( V_433 < V_432 -> V_407 )
V_432 -> V_406 = - V_435 ;
else
V_432 -> V_407 = V_433 ;
break;
case V_409 :
case V_410 :
V_432 -> V_406 = - V_54 ;
break;
default:
V_432 -> V_406 = - V_48 ;
break;
}
if ( V_432 -> V_406 )
F_48 ( V_5 , V_436 ) ;
F_85 ( V_413 , & V_432 -> V_414 ) ;
F_73 ( V_357 ) ;
F_74 ( V_5 -> V_20 -> V_21 , V_362 , 0 ) ;
}
int
F_94 ( struct V_431 * V_432 ,
void (* F_95)( struct V_437 * V_437 ) )
{
int V_34 = - V_378 , V_89 = 0 ;
struct V_438 * V_80 = NULL ;
struct V_4 * V_5 = F_81 ( V_432 -> V_396 -> V_397 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_83 V_84 ;
struct V_367 V_368 ;
V_34 = F_18 ( V_42 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 ) {
if ( V_34 == - V_54 && V_432 -> V_415 ) {
V_432 -> V_415 = 0 ;
F_44 ( & V_21 -> V_416 ) ;
V_21 -> V_417 -- ;
F_45 ( & V_21 -> V_416 ) ;
}
goto V_439;
}
V_80 -> V_2 . V_16 = F_5 ( V_432 -> V_396 -> V_381 ) ;
V_80 -> V_232 = V_432 -> V_396 -> V_230 . V_233 ;
V_80 -> V_234 = V_432 -> V_396 -> V_230 . V_235 ;
V_80 -> V_440 = 0 ;
V_80 -> V_441 = 0 ;
V_80 -> V_159 = 0 ;
V_80 -> V_387 = F_79 ( V_432 -> V_330 ) ;
V_80 -> V_223 = F_4 (
F_42 ( struct V_438 , V_168 ) - 4 ) ;
V_80 -> V_393 = 0 ;
V_84 . V_109 = F_25 ( V_80 ) + 4 - 1 ;
V_84 . V_108 = V_80 ;
V_368 . V_369 = & V_84 ;
V_368 . V_370 = 1 ;
V_368 . V_398 = V_432 -> V_399 ;
V_368 . V_400 = V_432 -> V_401 ;
V_368 . V_402 = V_432 -> V_403 ;
V_368 . V_404 = V_432 -> V_405 ;
F_7 ( V_45 , L_55 ,
V_432 -> V_330 , V_432 -> V_407 ) ;
V_80 -> V_385 = F_5 ( V_432 -> V_407 ) ;
F_24 ( & V_80 -> V_2 , V_432 -> V_407 - 1 ) ;
if ( V_432 -> V_415 ) {
V_80 -> V_2 . V_24 = F_4 ( F_87 ( V_432 -> V_407 ,
V_418 ) ) ;
F_44 ( & V_21 -> V_416 ) ;
V_21 -> V_415 += V_432 -> V_415 -
F_2 ( V_80 -> V_2 . V_24 ) ;
F_45 ( & V_21 -> V_416 ) ;
F_88 ( & V_21 -> V_419 ) ;
V_89 = V_420 ;
}
F_89 ( & V_432 -> V_421 ) ;
V_34 = F_76 ( V_21 , & V_368 , NULL , F_92 , V_432 ,
V_89 ) ;
if ( V_34 ) {
F_90 ( & V_432 -> V_421 , F_95 ) ;
F_48 ( V_5 , V_436 ) ;
}
V_439:
F_61 ( V_80 ) ;
return V_34 ;
}
int
F_96 ( const unsigned int V_78 , struct V_374 * V_375 ,
unsigned int * V_424 , struct V_83 * V_84 , int V_442 )
{
int V_34 = 0 ;
struct V_438 * V_80 = NULL ;
struct V_434 * V_82 = NULL ;
int V_85 ;
* V_424 = 0 ;
if ( V_442 < 1 )
return V_34 ;
V_34 = F_18 ( V_42 , V_375 -> V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
if ( V_375 -> V_5 -> V_20 -> V_21 == NULL )
return - V_380 ;
V_80 -> V_2 . V_16 = F_5 ( V_375 -> V_381 ) ;
V_80 -> V_232 = V_375 -> V_233 ;
V_80 -> V_234 = V_375 -> V_235 ;
V_80 -> V_440 = 0 ;
V_80 -> V_441 = 0 ;
V_80 -> V_159 = 0 ;
V_80 -> V_385 = F_5 ( V_375 -> V_386 ) ;
V_80 -> V_387 = F_79 ( V_375 -> V_330 ) ;
V_80 -> V_223 = F_4 (
F_42 ( struct V_438 , V_168 ) - 4 ) ;
V_80 -> V_393 = 0 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - 1 ;
F_24 ( V_80 , V_375 -> V_386 - 1 ) ;
V_34 = F_26 ( V_78 , V_375 -> V_5 -> V_20 , V_84 , V_442 + 1 ,
& V_85 , 0 ) ;
V_82 = (struct V_434 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 ) {
F_48 ( V_375 -> V_5 , V_436 ) ;
F_7 ( V_115 , L_56 , V_34 ) ;
} else
* V_424 = F_28 ( V_82 -> V_225 ) ;
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
static unsigned int
F_97 ( char * V_443 , char * V_336 , char * * V_444 , T_11 V_445 )
{
int V_446 ;
unsigned int V_447 = 0 ;
unsigned int V_448 = 0 ;
T_13 * V_449 ;
if ( V_443 == NULL )
return 0 ;
V_449 = ( T_13 * ) V_443 ;
while ( 1 ) {
V_449 = ( T_13 * )
( ( char * ) V_449 + V_448 ) ;
if ( ( char * ) V_449 + V_445 > V_336 ) {
F_7 ( V_115 , L_57 ) ;
break;
}
V_446 = F_28 ( V_449 -> V_450 ) ;
if ( ( char * ) V_449 + V_446 + V_445 > V_336 ) {
F_7 ( V_115 , L_58 ,
V_336 ) ;
break;
}
* V_444 = ( char * ) V_449 ;
V_447 ++ ;
V_448 = F_28 ( V_449 -> V_451 ) ;
if ( ! V_448 )
break;
}
return V_447 ;
}
int
F_98 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , int V_452 ,
struct V_453 * V_454 )
{
struct V_455 * V_80 ;
struct V_456 * V_82 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_34 = 0 ;
int V_446 ;
int V_85 ;
unsigned char * V_457 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
T_1 V_458 = F_4 ( '*' ) ;
char * V_334 ;
unsigned int V_459 = V_460 ;
T_11 V_461 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_67 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
switch ( V_454 -> V_462 ) {
case V_463 :
V_80 -> V_464 = V_465 ;
V_461 = sizeof( T_13 ) - 1 ;
break;
case V_466 :
V_80 -> V_464 = V_467 ;
V_461 = sizeof( V_468 ) - 1 ;
break;
default:
F_7 ( V_115 , L_59 ,
V_454 -> V_462 ) ;
V_34 = - V_197 ;
goto V_469;
}
V_80 -> V_470 = F_5 ( V_452 ) ;
V_80 -> V_232 = V_233 ;
V_80 -> V_234 = V_235 ;
V_446 = 0x2 ;
V_457 = V_80 -> V_168 ;
memcpy ( V_457 , & V_458 , V_446 ) ;
V_80 -> V_471 =
F_4 ( sizeof( struct V_455 ) - 1 - 4 ) ;
V_80 -> V_450 = F_4 ( V_446 ) ;
V_459 = F_27 (unsigned int, output_size, server->maxBuf) ;
V_459 = F_27 (unsigned int, output_size, 2 << 15 ) ;
V_80 -> V_348 = F_5 ( V_459 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - 1 ;
V_84 [ 1 ] . V_108 = ( char * ) ( V_80 -> V_168 ) ;
V_84 [ 1 ] . V_109 = V_446 ;
F_24 ( V_80 , V_446 - 1 ) ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 2 , & V_85 , 0 ) ;
V_82 = (struct V_456 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 ) {
if ( V_34 == - V_411 && V_82 -> V_2 . V_166 == V_472 ) {
V_454 -> V_473 = true ;
V_34 = 0 ;
}
F_48 ( V_5 , V_474 ) ;
goto V_469;
}
V_34 = F_66 ( F_2 ( V_82 -> V_351 ) ,
F_28 ( V_82 -> V_348 ) , & V_82 -> V_2 ,
V_461 ) ;
if ( V_34 )
goto V_469;
V_454 -> V_475 = true ;
if ( V_454 -> V_476 ) {
if ( V_454 -> V_477 )
F_61 ( V_454 -> V_476 ) ;
else
F_99 ( V_454 -> V_476 ) ;
}
V_454 -> V_476 = ( char * ) V_82 ;
V_454 -> V_478 = V_454 -> V_479 = 4 +
( char * ) & V_82 -> V_2 + F_2 ( V_82 -> V_351 ) ;
V_334 = F_25 ( V_82 ) + 4 + ( char * ) & V_82 -> V_2 ;
V_454 -> V_480 =
F_97 ( V_454 -> V_478 , V_334 ,
& V_454 -> V_479 , V_461 ) ;
V_454 -> V_481 += V_454 -> V_480 ;
F_7 ( V_45 , L_60 ,
V_454 -> V_480 , V_454 -> V_481 ,
V_454 -> V_478 , V_454 -> V_479 ) ;
if ( V_85 == V_430 )
V_454 -> V_477 = false ;
else if ( V_85 == V_429 )
V_454 -> V_477 = true ;
else
F_7 ( V_115 , L_61 ) ;
return V_34 ;
V_469:
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
static int
F_100 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , T_4 V_381 , int V_339 ,
unsigned int V_249 , void * * V_338 , unsigned int * V_445 )
{
struct V_482 * V_80 ;
struct V_483 * V_82 = NULL ;
struct V_83 * V_84 ;
int V_34 = 0 ;
int V_85 ;
unsigned int V_484 ;
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
V_80 -> V_2 . V_16 = F_5 ( V_381 ) ;
V_80 -> V_344 = V_345 ;
V_80 -> V_346 = V_339 ;
V_80 -> V_232 = V_233 ;
V_80 -> V_234 = V_235 ;
V_80 -> V_485 =
F_4 ( sizeof( struct V_482 ) - 1 - 4 ) ;
V_80 -> V_486 = F_5 ( * V_445 ) ;
F_24 ( V_80 , * V_445 - 1 ) ;
memcpy ( V_80 -> V_168 , * V_338 , * V_445 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
for ( V_484 = 1 ; V_484 < V_249 ; V_484 ++ ) {
F_24 ( V_80 , V_445 [ V_484 ] ) ;
F_57 ( & V_80 -> V_486 , V_445 [ V_484 ] ) ;
V_84 [ V_484 ] . V_108 = ( char * ) V_338 [ V_484 ] ;
V_84 [ V_484 ] . V_109 = V_445 [ V_484 ] ;
}
V_34 = F_26 ( V_78 , V_20 , V_84 , V_249 , & V_85 , 0 ) ;
V_82 = (struct V_483 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 != 0 )
F_48 ( V_5 , V_487 ) ;
F_33 ( V_85 , V_82 ) ;
F_37 ( V_84 ) ;
return V_34 ;
}
int
F_101 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , T_1 * V_488 )
{
struct V_489 V_490 ;
void * * V_338 ;
unsigned int V_445 [ 2 ] ;
int V_34 ;
int V_446 = ( 2 * F_60 ( ( V_285 * ) V_488 , V_286 ) ) ;
V_338 = F_38 ( sizeof( void * ) * 2 , V_150 ) ;
if ( ! V_338 )
return - V_72 ;
V_490 . V_491 = 1 ;
V_490 . V_492 = 0 ;
V_490 . V_450 = F_5 ( V_446 ) ;
V_338 [ 0 ] = & V_490 ;
V_445 [ 0 ] = sizeof( struct V_489 ) ;
V_338 [ 1 ] = V_488 ;
V_445 [ 1 ] = V_446 + 2 ;
V_34 = F_100 ( V_78 , V_5 , V_233 , V_235 ,
V_17 -> V_18 , V_493 , 2 , V_338 ,
V_445 ) ;
F_37 ( V_338 ) ;
return V_34 ;
}
int
F_102 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , T_1 * V_488 )
{
struct V_494 V_490 ;
void * * V_338 ;
unsigned int V_445 [ 2 ] ;
int V_34 ;
int V_446 = ( 2 * F_60 ( ( V_285 * ) V_488 , V_286 ) ) ;
V_338 = F_38 ( sizeof( void * ) * 2 , V_150 ) ;
if ( ! V_338 )
return - V_72 ;
V_490 . V_491 = 0 ;
V_490 . V_492 = 0 ;
V_490 . V_450 = F_5 ( V_446 ) ;
V_338 [ 0 ] = & V_490 ;
V_445 [ 0 ] = sizeof( struct V_494 ) ;
V_338 [ 1 ] = V_488 ;
V_445 [ 1 ] = V_446 + 2 ;
V_34 = F_100 ( V_78 , V_5 , V_233 , V_235 ,
V_17 -> V_18 , V_495 , 2 , V_338 , V_445 ) ;
F_37 ( V_338 ) ;
return V_34 ;
}
int
F_103 ( const unsigned int V_78 , struct V_4 * V_5 , T_9 V_233 ,
T_9 V_235 , T_4 V_381 , T_12 * V_496 , bool V_497 )
{
struct V_498 V_490 ;
void * V_338 ;
unsigned int V_445 ;
V_490 . V_295 = * V_496 ;
V_338 = & V_490 ;
V_445 = sizeof( struct V_498 ) ;
if ( V_497 )
return F_100 ( V_78 , V_5 , V_233 , V_235 ,
V_381 , V_499 , 1 , & V_338 , & V_445 ) ;
else
return F_100 ( V_78 , V_5 , V_233 , V_235 ,
V_381 , V_500 , 1 , & V_338 , & V_445 ) ;
}
int
F_104 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , T_14 * V_221 )
{
unsigned int V_445 ;
V_445 = sizeof( T_14 ) ;
return F_100 ( V_78 , V_5 , V_233 , V_235 ,
V_17 -> V_18 , V_501 , 1 ,
( void * * ) & V_221 , & V_445 ) ;
}
int
F_105 ( const unsigned int V_78 , struct V_4 * V_5 ,
const T_9 V_233 , const T_9 V_235 ,
T_7 V_502 )
{
int V_34 ;
struct V_503 * V_80 = NULL ;
F_7 ( V_45 , L_62 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_504 = V_235 ;
V_80 -> V_505 = V_233 ;
V_80 -> V_300 = V_502 ;
V_80 -> V_2 . V_15 = F_4 ( 1 ) ;
V_34 = F_47 ( V_78 , V_5 -> V_20 , ( char * ) V_80 , V_506 ) ;
if ( V_34 ) {
F_48 ( V_5 , V_507 ) ;
F_7 ( V_45 , L_63 , V_34 ) ;
}
return V_34 ;
}
static void
F_106 ( struct V_508 * V_509 ,
struct V_510 * V_511 )
{
V_511 -> V_512 = F_28 ( V_509 -> V_513 ) *
F_28 ( V_509 -> V_514 ) ;
V_511 -> V_515 = F_107 ( V_509 -> V_516 ) ;
V_511 -> V_517 = F_107 ( V_509 -> V_518 ) ;
V_511 -> V_519 = F_107 ( V_509 -> V_520 ) ;
return;
}
static int
F_108 ( struct V_83 * V_84 , struct V_4 * V_5 , int V_521 ,
int V_522 , T_9 V_233 , T_9 V_235 )
{
int V_34 ;
struct V_342 * V_80 ;
F_7 ( V_45 , L_64 , V_521 ) ;
if ( ( V_5 -> V_20 == NULL ) || ( V_5 -> V_20 -> V_21 == NULL ) )
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_344 = V_523 ;
V_80 -> V_346 = V_521 ;
V_80 -> V_232 = V_233 ;
V_80 -> V_234 = V_235 ;
V_80 -> V_347 =
F_4 ( sizeof( struct V_342 ) - 1 - 4 ) ;
V_80 -> V_348 = F_5 (
V_522 + sizeof( struct V_343 ) - 1 - 4 ) ;
V_84 -> V_108 = ( char * ) V_80 ;
V_84 -> V_109 = F_25 ( V_80 ) + 4 ;
return 0 ;
}
int
F_109 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , struct V_510 * V_524 )
{
struct V_343 * V_82 = NULL ;
struct V_83 V_84 ;
int V_34 = 0 ;
int V_85 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_508 * V_490 = NULL ;
V_34 = F_108 ( & V_84 , V_5 , V_525 ,
sizeof( struct V_508 ) ,
V_233 , V_235 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_26 ( V_78 , V_20 , & V_84 , 1 , & V_85 , 0 ) ;
if ( V_34 ) {
F_48 ( V_5 , V_349 ) ;
goto V_526;
}
V_82 = (struct V_343 * ) V_84 . V_108 ;
V_490 = (struct V_508 * ) ( 4 +
F_2 ( V_82 -> V_351 ) + ( char * ) & V_82 -> V_2 ) ;
V_34 = F_66 ( F_2 ( V_82 -> V_351 ) ,
F_28 ( V_82 -> V_348 ) , & V_82 -> V_2 ,
sizeof( struct V_508 ) ) ;
if ( ! V_34 )
F_106 ( V_490 , V_524 ) ;
V_526:
F_33 ( V_85 , V_84 . V_108 ) ;
return V_34 ;
}
int
F_110 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_233 , T_9 V_235 , int V_521 )
{
struct V_343 * V_82 = NULL ;
struct V_83 V_84 ;
int V_34 = 0 ;
int V_85 , V_527 , V_341 ;
struct V_37 * V_20 = V_5 -> V_20 ;
unsigned int V_528 , V_330 ;
if ( V_521 == V_529 ) {
V_527 = sizeof( V_530 ) ;
V_341 = sizeof( V_530 ) ;
} else if ( V_521 == V_531 ) {
V_527 = sizeof( V_532 ) ;
V_341 = V_533 ;
} else if ( V_521 == V_534 ) {
V_527 = sizeof( struct V_535 ) ;
V_341 = sizeof( struct V_535 ) ;
} else {
F_7 ( V_45 , L_65 , V_521 ) ;
return - V_197 ;
}
V_34 = F_108 ( & V_84 , V_5 , V_521 , V_527 ,
V_233 , V_235 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_26 ( V_78 , V_20 , & V_84 , 1 , & V_85 , 0 ) ;
if ( V_34 ) {
F_48 ( V_5 , V_349 ) ;
goto V_536;
}
V_82 = (struct V_343 * ) V_84 . V_108 ;
V_528 = F_28 ( V_82 -> V_348 ) ;
V_330 = F_2 ( V_82 -> V_351 ) ;
V_34 = F_66 ( V_330 , V_528 , & V_82 -> V_2 , V_341 ) ;
if ( V_34 )
goto V_536;
if ( V_521 == V_531 )
memcpy ( & V_5 -> V_537 , 4 + V_330
+ ( char * ) & V_82 -> V_2 , F_27 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_521 == V_529 )
memcpy ( & V_5 -> V_538 , 4 + V_330
+ ( char * ) & V_82 -> V_2 , sizeof( V_530 ) ) ;
else if ( V_521 == V_534 ) {
struct V_535 * V_539 = (struct V_535 * )
( 4 + V_330 + ( char * ) & V_82 -> V_2 ) ;
V_5 -> V_540 = F_28 ( V_539 -> V_30 ) ;
V_5 -> V_541 =
F_28 ( V_539 -> V_542 ) ;
}
V_536:
F_33 ( V_85 , V_84 . V_108 ) ;
return V_34 ;
}
int
F_111 ( const unsigned int V_78 , struct V_4 * V_5 ,
const T_15 V_543 , const T_15 V_235 , const T_8 V_381 ,
const T_8 V_544 , struct V_545 * V_221 )
{
int V_34 = 0 ;
struct V_546 * V_80 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_547 ;
unsigned int V_548 ;
F_7 ( V_45 , L_66 , V_544 ) ;
V_34 = F_18 ( V_65 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_16 = F_5 ( V_381 ) ;
V_80 -> V_549 = F_4 ( V_544 ) ;
V_80 -> V_232 = V_543 ;
V_80 -> V_234 = V_235 ;
V_548 = V_544 * sizeof( struct V_545 ) ;
F_24 ( V_80 , V_548 - sizeof( struct V_545 ) ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - V_548 ;
V_84 [ 1 ] . V_108 = ( char * ) V_221 ;
V_84 [ 1 ] . V_109 = V_548 ;
F_21 ( & V_5 -> V_74 . V_550 . V_551 ) ;
V_34 = F_26 ( V_78 , V_5 -> V_20 , V_84 , 2 , & V_547 , V_552 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_67 , V_34 ) ;
F_48 ( V_5 , V_553 ) ;
}
return V_34 ;
}
int
F_112 ( const unsigned int V_78 , struct V_4 * V_5 ,
const T_15 V_543 , const T_15 V_235 , const T_8 V_381 ,
const T_15 V_386 , const T_15 V_330 , const T_8 V_554 ,
const bool V_555 )
{
struct V_545 V_556 ;
V_556 . V_387 = F_79 ( V_330 ) ;
V_556 . V_385 = F_79 ( V_386 ) ;
V_556 . V_30 = F_5 ( V_554 ) ;
if ( ! V_555 && V_554 != V_557 )
V_556 . V_30 |= F_5 ( V_558 ) ;
return F_111 ( V_78 , V_5 , V_543 , V_235 , V_381 , 1 , & V_556 ) ;
}
int
F_113 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_7 * V_559 , const T_5 V_560 )
{
int V_34 ;
struct V_561 * V_80 = NULL ;
F_7 ( V_45 , L_68 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_15 = F_4 ( 1 ) ;
V_80 -> V_13 = F_4 ( 36 ) ;
F_24 ( V_80 , 12 ) ;
memcpy ( V_80 -> V_562 , V_559 , 16 ) ;
V_80 -> V_563 = V_560 ;
V_34 = F_47 ( V_78 , V_5 -> V_20 , ( char * ) V_80 , V_506 ) ;
if ( V_34 ) {
F_48 ( V_5 , V_507 ) ;
F_7 ( V_45 , L_69 , V_34 ) ;
}
return V_34 ;
}
