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
V_34 = F_32 ( V_88 , V_87 , V_21 ) ;
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
struct V_127 V_128 ;
struct V_129 * V_130 ;
T_4 V_131 ;
F_7 ( V_45 , L_13 ) ;
if ( V_5 -> V_20 -> V_21 -> V_29 == false )
return 0 ;
V_128 . V_102 =
F_5 ( V_5 -> V_20 -> V_21 -> V_94 -> V_103 ) ;
memcpy ( V_128 . V_132 , V_5 -> V_20 -> V_21 -> V_107 ,
V_106 ) ;
if ( V_5 -> V_20 -> V_29 )
V_128 . V_97 =
F_4 ( V_98 ) ;
else if ( V_99 & V_100 )
V_128 . V_97 =
F_4 ( V_101 ) ;
else
V_128 . V_97 = 0 ;
V_128 . V_96 = F_4 ( 1 ) ;
V_128 . V_93 [ 0 ] =
F_4 ( V_5 -> V_20 -> V_21 -> V_94 -> V_95 ) ;
V_34 = F_35 ( V_78 , V_5 , V_133 , V_133 ,
V_134 , true ,
( char * ) & V_128 , sizeof( struct V_127 ) ,
( char * * ) & V_130 , & V_131 ) ;
if ( V_34 != 0 ) {
F_7 ( V_115 , L_14 , V_34 ) ;
return - V_48 ;
}
if ( V_131 != sizeof( struct V_129 ) ) {
F_7 ( V_115 , L_15 ) ;
return - V_48 ;
}
if ( V_130 -> V_135 !=
F_4 ( V_5 -> V_20 -> V_21 -> V_94 -> V_95 ) )
goto V_136;
if ( V_130 -> V_97 != F_4 ( V_5 -> V_20 -> V_21 -> V_124 ) )
goto V_136;
if ( ( F_28 ( V_130 -> V_102 ) | V_125 |
V_126 ) != V_5 -> V_20 -> V_21 -> V_22 )
goto V_136;
F_7 ( V_45 , L_16 ) ;
return 0 ;
V_136:
F_7 ( V_115 , L_17 ) ;
return - V_48 ;
}
int
F_36 ( const unsigned int V_78 , struct V_37 * V_20 ,
const struct V_35 * V_137 )
{
struct V_138 * V_80 ;
struct V_139 * V_82 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_34 = 0 ;
int V_85 = V_140 ;
T_5 V_141 = V_142 ;
struct V_38 * V_21 = V_20 -> V_21 ;
T_6 V_87 = 0 ;
char * V_88 ;
char * V_143 = NULL ;
bool V_144 = false ;
F_7 ( V_45 , L_18 ) ;
if ( ! V_21 ) {
F_23 ( 1 , L_5 , V_91 ) ;
return - V_48 ;
}
F_37 ( V_20 -> V_145 . V_146 ) ;
V_20 -> V_145 . V_146 = NULL ;
V_20 -> V_147 = F_38 ( sizeof( struct V_148 ) , V_149 ) ;
if ( ! V_20 -> V_147 )
return - V_72 ;
V_20 -> V_147 -> V_150 = true ;
V_20 -> V_151 = V_152 ;
V_153:
if ( V_141 == V_154 )
V_141 = V_155 ;
V_34 = F_18 ( V_156 , NULL , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_27 = 0 ;
V_80 -> V_157 = 0 ;
V_80 -> V_2 . V_15 = F_4 ( 3 ) ;
if ( V_21 -> V_29 )
V_80 -> V_97 = V_98 ;
else if ( V_99 & V_100 )
V_80 -> V_97 = V_101 ;
else
V_80 -> V_97 = 0 ;
V_80 -> V_102 = 0 ;
V_80 -> V_158 = 0 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - 1 ;
if ( V_141 == V_142 ) {
V_143 = F_38 ( sizeof( struct V_159 ) ,
V_149 ) ;
if ( V_143 == NULL ) {
V_34 = - V_72 ;
goto V_160;
}
F_39 ( V_143 , V_20 ) ;
if ( V_144 ) {
F_7 ( V_115 , L_19 ) ;
V_34 = - V_161 ;
F_37 ( V_143 ) ;
goto V_160;
} else {
V_87 = sizeof( struct V_159 ) ;
V_88 = V_143 ;
}
} else if ( V_141 == V_155 ) {
V_80 -> V_2 . V_27 = V_20 -> V_28 ;
V_143 = F_40 ( sizeof( struct V_159 ) + 500 ,
V_149 ) ;
if ( V_143 == NULL ) {
V_34 = - V_72 ;
goto V_160;
}
V_34 = F_41 ( V_143 , & V_87 , V_20 ,
V_137 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_20 ,
V_34 ) ;
goto V_160;
}
if ( V_144 ) {
F_7 ( V_115 , L_19 ) ;
V_34 = - V_161 ;
F_37 ( V_143 ) ;
goto V_160;
} else {
V_88 = V_143 ;
}
} else {
F_7 ( V_115 , L_21 ) ;
V_34 = - V_48 ;
goto V_160;
}
V_80 -> V_162 =
F_4 ( sizeof( struct V_138 ) -
1 - 4 ) ;
V_80 -> V_163 = F_4 ( V_87 ) ;
V_84 [ 1 ] . V_108 = V_88 ;
V_84 [ 1 ] . V_109 = V_87 ;
F_24 ( V_80 , V_87 - 1 ) ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 2 , & V_85 ,
V_164 | V_90 ) ;
F_37 ( V_88 ) ;
V_82 = (struct V_139 * ) V_84 [ 0 ] . V_108 ;
if ( V_85 != V_140 &&
V_82 -> V_2 . V_165 == V_166 ) {
if ( V_141 != V_142 ) {
F_7 ( V_115 , L_22 ) ;
goto V_160;
}
if ( F_42 ( struct V_139 , V_167 ) - 4 !=
F_2 ( V_82 -> V_162 ) ) {
F_7 ( V_115 , L_23 ,
F_2 ( V_82 -> V_162 ) ) ;
V_34 = - V_48 ;
goto V_160;
}
V_141 = V_154 ;
V_34 = 0 ;
V_20 -> V_28 = V_82 -> V_2 . V_27 ;
V_34 = F_43 ( V_82 -> V_167 ,
F_2 ( V_82 -> V_163 ) , V_20 ) ;
}
if ( V_34 != 0 )
goto V_160;
V_20 -> V_168 = F_2 ( V_82 -> V_169 ) ;
if ( V_20 -> V_168 & V_170 )
F_7 ( V_115 , L_24 ) ;
V_160:
F_33 ( V_85 , V_82 ) ;
if ( ( V_141 == V_154 ) && ( V_34 == 0 ) )
goto V_153;
if ( ! V_34 ) {
F_10 ( & V_21 -> V_171 ) ;
if ( V_21 -> V_29 && V_21 -> V_172 -> V_173 ) {
V_34 = V_21 -> V_172 -> V_173 ( V_20 ) ;
F_37 ( V_20 -> V_145 . V_146 ) ;
V_20 -> V_145 . V_146 = NULL ;
if ( V_34 ) {
F_7 ( V_45 ,
L_25 ) ;
F_13 ( & V_21 -> V_171 ) ;
goto V_174;
}
}
if ( ! V_21 -> V_175 ) {
V_21 -> V_176 = 0x2 ;
V_21 -> V_175 = true ;
}
F_13 ( & V_21 -> V_171 ) ;
F_7 ( V_45 , L_26 ) ;
F_44 ( & V_177 ) ;
V_20 -> V_47 = V_178 ;
V_20 -> V_59 = false ;
F_45 ( & V_177 ) ;
}
V_174:
if ( ! V_21 -> V_29 ) {
F_37 ( V_20 -> V_145 . V_146 ) ;
V_20 -> V_145 . V_146 = NULL ;
}
F_37 ( V_20 -> V_147 ) ;
return V_34 ;
}
int
F_46 ( const unsigned int V_78 , struct V_37 * V_20 )
{
struct V_179 * V_80 ;
int V_34 = 0 ;
struct V_38 * V_21 ;
F_7 ( V_45 , L_27 , V_20 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_20 -> V_59 )
goto V_180;
V_34 = F_18 ( V_181 , NULL , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_27 = V_20 -> V_28 ;
if ( V_21 -> V_29 )
V_80 -> V_2 . V_30 |= V_31 ;
V_34 = F_47 ( V_78 , V_20 , ( char * ) & V_80 -> V_2 , 0 ) ;
V_180:
return V_34 ;
}
static inline void F_48 ( struct V_4 * V_5 , T_3 V_182 )
{
F_21 ( & V_5 -> V_74 . V_75 . V_183 [ V_182 ] ) ;
}
static inline void F_49 ( struct V_4 * V_5 )
{
V_5 -> V_184 = 256 ;
V_5 -> V_185 = 1048576 ;
V_5 -> V_186 = 16777216 ;
}
int
F_15 ( const unsigned int V_78 , struct V_37 * V_20 , const char * V_187 ,
struct V_4 * V_5 , const struct V_35 * V_188 )
{
struct V_189 * V_80 ;
struct V_190 * V_82 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_34 = 0 ;
int V_85 ;
int V_191 ;
struct V_38 * V_21 ;
T_1 * V_192 = NULL ;
F_7 ( V_45 , L_28 ) ;
if ( ( V_20 -> V_21 ) && V_187 )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_5 && V_5 -> V_193 )
return - V_194 ;
V_192 = F_38 ( V_195 * 2 , V_149 ) ;
if ( V_192 == NULL )
return - V_72 ;
V_191 = F_50 ( V_192 , V_187 , strlen ( V_187 ) , V_188 ) + 1 ;
V_191 *= 2 ;
if ( V_191 < 2 ) {
F_37 ( V_192 ) ;
return - V_196 ;
}
V_34 = F_18 ( V_39 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 ) {
F_37 ( V_192 ) ;
return V_34 ;
}
if ( V_5 == NULL ) {
V_80 -> V_2 . V_27 = V_20 -> V_28 ;
}
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - 1 ;
V_80 -> V_197 = F_4 ( sizeof( struct V_189 )
- 1 - 4 ) ;
V_80 -> V_198 = F_4 ( V_191 - 2 ) ;
V_84 [ 1 ] . V_108 = V_192 ;
V_84 [ 1 ] . V_109 = V_191 ;
F_24 ( V_80 , V_191 - 1 ) ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 2 , & V_85 , 0 ) ;
V_82 = (struct V_190 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 != 0 ) {
if ( V_5 ) {
F_48 ( V_5 , V_199 ) ;
V_5 -> V_59 = true ;
}
goto V_200;
}
if ( V_5 == NULL ) {
V_20 -> V_201 = V_82 -> V_2 . V_25 ;
goto V_202;
}
if ( V_82 -> V_203 & V_204 )
F_7 ( V_45 , L_29 ) ;
else if ( V_82 -> V_203 & V_205 ) {
V_5 -> V_206 = true ;
F_7 ( V_45 , L_30 ) ;
} else if ( V_82 -> V_203 & V_207 ) {
V_5 -> V_208 = true ;
F_7 ( V_45 , L_31 ) ;
} else {
F_7 ( V_115 , L_32 , V_82 -> V_203 ) ;
V_34 = - V_161 ;
goto V_200;
}
V_5 -> V_209 = F_28 ( V_82 -> V_210 ) ;
V_5 -> V_22 = V_82 -> V_102 ;
V_5 -> V_211 = F_28 ( V_82 -> V_212 ) ;
V_5 -> V_40 = V_178 ;
V_5 -> V_59 = false ;
V_5 -> V_26 = V_82 -> V_2 . V_25 ;
F_51 ( V_5 -> V_61 , V_187 , sizeof( V_5 -> V_61 ) ) ;
if ( ( V_82 -> V_102 & V_213 ) &&
( ( V_5 -> V_209 & V_214 ) == 0 ) )
F_7 ( V_115 , L_33 ) ;
F_49 ( V_5 ) ;
if ( V_5 -> V_20 -> V_21 -> V_172 -> V_215 )
V_34 = V_5 -> V_20 -> V_21 -> V_172 -> V_215 ( V_78 , V_5 ) ;
V_202:
F_33 ( V_85 , V_82 ) ;
F_37 ( V_192 ) ;
return V_34 ;
V_200:
if ( V_82 -> V_2 . V_165 == V_216 ) {
F_7 ( V_115 , L_34 , V_187 ) ;
if ( V_5 )
V_5 -> V_193 = true ;
}
goto V_202;
}
int
F_52 ( const unsigned int V_78 , struct V_4 * V_5 )
{
struct V_217 * V_80 ;
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
F_48 ( V_5 , V_218 ) ;
return V_34 ;
}
static struct V_219 *
F_53 ( void )
{
struct V_219 * V_220 ;
V_220 = F_40 ( sizeof( struct V_219 ) , V_149 ) ;
if ( ! V_220 )
return NULL ;
V_220 -> V_221 . V_222 = F_4 ( F_42
( struct V_219 , V_223 ) ) ;
V_220 -> V_221 . V_224 = F_5 ( 16 ) ;
V_220 -> V_221 . V_225 = F_4 ( F_42
( struct V_219 , V_226 ) ) ;
V_220 -> V_221 . V_227 = F_4 ( 4 ) ;
V_220 -> V_226 [ 0 ] = 'D' ;
V_220 -> V_226 [ 1 ] = 'H' ;
V_220 -> V_226 [ 2 ] = 'n' ;
V_220 -> V_226 [ 3 ] = 'Q' ;
return V_220 ;
}
static struct V_219 *
F_54 ( struct V_228 * V_229 )
{
struct V_219 * V_220 ;
V_220 = F_40 ( sizeof( struct V_219 ) , V_149 ) ;
if ( ! V_220 )
return NULL ;
V_220 -> V_221 . V_222 = F_4 ( F_42
( struct V_219 , V_223 ) ) ;
V_220 -> V_221 . V_224 = F_5 ( 16 ) ;
V_220 -> V_221 . V_225 = F_4 ( F_42
( struct V_219 , V_226 ) ) ;
V_220 -> V_221 . V_227 = F_4 ( 4 ) ;
V_220 -> V_223 . V_230 . V_231 = V_229 -> V_232 ;
V_220 -> V_223 . V_230 . V_233 = V_229 -> V_234 ;
V_220 -> V_226 [ 0 ] = 'D' ;
V_220 -> V_226 [ 1 ] = 'H' ;
V_220 -> V_226 [ 2 ] = 'n' ;
V_220 -> V_226 [ 3 ] = 'C' ;
return V_220 ;
}
static T_7
F_55 ( struct V_38 * V_21 , struct V_235 * V_82 ,
unsigned int * V_236 )
{
char * V_237 ;
struct V_238 * V_239 ;
unsigned int V_240 = 0 ;
char * V_241 ;
V_237 = ( char * ) V_82 + 4 + F_28 ( V_82 -> V_242 ) ;
V_239 = (struct V_238 * ) V_237 ;
do {
V_239 = (struct V_238 * ) ( ( char * ) V_239 + V_240 ) ;
V_241 = F_2 ( V_239 -> V_225 ) + ( char * ) V_239 ;
if ( F_2 ( V_239 -> V_227 ) != 4 ||
strncmp ( V_241 , L_36 , 4 ) ) {
V_240 = F_28 ( V_239 -> V_243 ) ;
continue;
}
return V_21 -> V_172 -> V_244 ( V_239 , V_236 ) ;
} while ( V_240 != 0 );
return 0 ;
}
static int
F_56 ( struct V_38 * V_21 , struct V_83 * V_84 ,
unsigned int * V_245 , T_7 * V_246 )
{
struct V_247 * V_80 = V_84 [ 0 ] . V_108 ;
unsigned int V_248 = * V_245 ;
V_84 [ V_248 ] . V_108 = V_21 -> V_172 -> V_249 ( V_246 + 1 , * V_246 ) ;
if ( V_84 [ V_248 ] . V_108 == NULL )
return - V_72 ;
V_84 [ V_248 ] . V_109 = V_21 -> V_94 -> V_250 ;
V_80 -> V_251 = V_252 ;
if ( ! V_80 -> V_242 )
V_80 -> V_242 = F_5 (
sizeof( struct V_247 ) - 4 +
V_84 [ V_248 - 1 ] . V_109 ) ;
F_57 ( & V_80 -> V_253 ,
V_21 -> V_94 -> V_250 ) ;
F_24 ( & V_80 -> V_2 , V_21 -> V_94 -> V_250 ) ;
* V_245 = V_248 + 1 ;
return 0 ;
}
static int
F_58 ( struct V_83 * V_84 , unsigned int * V_245 ,
struct V_254 * V_255 )
{
struct V_247 * V_80 = V_84 [ 0 ] . V_108 ;
unsigned int V_248 = * V_245 ;
if ( V_255 -> V_256 ) {
V_84 [ V_248 ] . V_108 = F_54 ( V_255 -> V_229 ) ;
V_255 -> V_256 = false ;
} else
V_84 [ V_248 ] . V_108 = F_53 () ;
if ( V_84 [ V_248 ] . V_108 == NULL )
return - V_72 ;
V_84 [ V_248 ] . V_109 = sizeof( struct V_219 ) ;
if ( ! V_80 -> V_242 )
V_80 -> V_242 =
F_5 ( sizeof( struct V_247 ) - 4 +
V_84 [ 1 ] . V_109 ) ;
F_57 ( & V_80 -> V_253 , sizeof( struct V_219 ) ) ;
F_24 ( & V_80 -> V_2 , sizeof( struct V_219 ) ) ;
* V_245 = V_248 + 1 ;
return 0 ;
}
int
F_59 ( const unsigned int V_78 , struct V_254 * V_255 , T_1 * V_257 ,
T_7 * V_246 , struct V_258 * V_220 ,
struct V_259 * * V_260 )
{
struct V_247 * V_80 ;
struct V_235 * V_82 ;
struct V_38 * V_21 ;
struct V_4 * V_5 = V_255 -> V_5 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_83 V_84 [ 4 ] ;
int V_85 ;
int V_261 ;
T_1 * V_262 = NULL ;
int V_263 ;
int V_34 = 0 ;
unsigned int V_264 = 2 ;
T_8 V_265 = 0 ;
char * V_266 = NULL , * V_267 = NULL ;
F_7 ( V_45 , L_37 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_43 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
if ( V_255 -> V_268 & V_269 )
V_265 |= V_270 ;
if ( V_255 -> V_268 & V_271 )
V_265 |= V_272 ;
V_80 -> V_273 = V_274 ;
V_80 -> V_275 = F_5 ( V_255 -> V_276 ) ;
V_80 -> V_277 = F_5 ( V_265 ) ;
V_80 -> V_278 = V_279 ;
V_80 -> V_280 = F_5 ( V_255 -> V_281 ) ;
V_80 -> V_282 = F_5 ( V_255 -> V_268 & V_283 ) ;
V_261 = ( 2 * F_60 ( ( V_284 * ) V_257 , V_285 ) ) + 2 ;
V_80 -> V_225 = F_4 ( sizeof( struct V_247 ) - 4 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
V_80 -> V_227 = F_4 ( V_261 - 2 ) ;
V_84 [ 0 ] . V_109 -- ;
if ( V_261 % 8 != 0 ) {
V_263 = V_261 / 8 * 8 ;
if ( V_263 < V_261 )
V_263 += 8 ;
V_262 = F_40 ( V_263 , V_149 ) ;
if ( ! V_262 )
return - V_72 ;
memcpy ( ( char * ) V_262 , ( const char * ) V_257 ,
V_261 ) ;
V_261 = V_263 ;
V_257 = V_262 ;
}
V_84 [ 1 ] . V_109 = V_261 ;
V_84 [ 1 ] . V_108 = V_257 ;
F_24 ( V_80 , V_261 - 1 ) ;
if ( ! V_21 -> V_286 )
* V_246 = V_287 ;
if ( ! ( V_21 -> V_22 & V_288 ) ||
* V_246 == V_287 )
V_80 -> V_251 = * V_246 ;
else {
V_34 = F_56 ( V_21 , V_84 , & V_264 , V_246 ) ;
if ( V_34 ) {
F_61 ( V_80 ) ;
F_37 ( V_262 ) ;
return V_34 ;
}
V_267 = V_84 [ V_264 - 1 ] . V_108 ;
}
if ( * V_246 == V_289 ) {
if ( V_21 -> V_22 & V_288 ) {
struct V_238 * V_221 =
(struct V_238 * ) V_84 [ V_264 - 1 ] . V_108 ;
V_221 -> V_243 =
F_5 ( V_21 -> V_94 -> V_250 ) ;
}
V_34 = F_58 ( V_84 , & V_264 , V_255 ) ;
if ( V_34 ) {
F_61 ( V_80 ) ;
F_37 ( V_262 ) ;
F_37 ( V_267 ) ;
return V_34 ;
}
V_266 = V_84 [ V_264 - 1 ] . V_108 ;
}
V_34 = F_26 ( V_78 , V_20 , V_84 , V_264 , & V_85 , 0 ) ;
V_82 = (struct V_235 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 != 0 ) {
F_48 ( V_5 , V_290 ) ;
if ( V_260 )
* V_260 = F_62 ( V_82 , F_25 ( V_82 ) + 4 ,
V_149 ) ;
goto V_291;
}
V_255 -> V_229 -> V_232 = V_82 -> V_231 ;
V_255 -> V_229 -> V_234 = V_82 -> V_233 ;
if ( V_220 ) {
memcpy ( V_220 , & V_82 -> V_292 , 32 ) ;
V_220 -> V_293 = V_82 -> V_293 ;
V_220 -> V_294 = V_82 -> V_295 ;
V_220 -> V_296 = V_82 -> V_277 ;
V_220 -> V_297 = F_5 ( 1 ) ;
V_220 -> V_298 = 0 ;
}
if ( V_82 -> V_299 == V_252 )
* V_246 = F_55 ( V_21 , V_82 , & V_255 -> V_229 -> V_236 ) ;
else
* V_246 = V_82 -> V_299 ;
V_291:
F_37 ( V_262 ) ;
F_37 ( V_267 ) ;
F_37 ( V_266 ) ;
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
int
F_35 ( const unsigned int V_78 , struct V_4 * V_5 , T_9 V_232 ,
T_9 V_234 , T_4 V_300 , bool V_301 , char * V_302 ,
T_4 V_303 , char * * V_304 , T_4 * V_305 )
{
struct V_306 * V_80 ;
struct V_307 * V_82 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_83 V_84 [ 2 ] ;
int V_85 ;
int V_264 ;
int V_34 = 0 ;
F_7 ( V_45 , L_38 ) ;
if ( V_304 != NULL )
* V_304 = NULL ;
if ( V_305 )
* V_305 = 0 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_66 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_308 = F_5 ( V_300 ) ;
V_80 -> V_231 = V_232 ;
V_80 -> V_233 = V_234 ;
if ( V_303 ) {
V_80 -> V_309 = F_5 ( V_303 ) ;
V_80 -> V_310 =
F_5 ( F_42 ( struct V_306 , V_167 ) - 4 ) ;
V_84 [ 1 ] . V_108 = V_302 ;
V_84 [ 1 ] . V_109 = V_303 ;
V_264 = 2 ;
} else
V_264 = 1 ;
V_80 -> V_311 = 0 ;
V_80 -> V_312 = 0 ;
V_80 -> V_313 = F_5 ( 0xFF00 ) ;
if ( V_301 )
V_80 -> V_30 = F_5 ( V_314 ) ;
else
V_80 -> V_30 = 0 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
if ( V_303 ) {
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - 1 ;
F_24 ( V_80 , V_303 - 1 ) ;
} else
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_26 ( V_78 , V_20 , V_84 , V_264 , & V_85 , 0 ) ;
V_82 = (struct V_307 * ) V_84 [ 0 ] . V_108 ;
if ( ( V_34 != 0 ) && ( V_34 != - V_196 ) ) {
if ( V_5 )
F_48 ( V_5 , V_315 ) ;
goto V_316;
} else if ( V_34 == - V_196 ) {
if ( ( V_300 != V_317 ) &&
( V_300 != V_318 ) ) {
if ( V_5 )
F_48 ( V_5 , V_315 ) ;
goto V_316;
}
}
if ( ( V_305 == NULL ) || ( V_304 == NULL ) )
goto V_316;
* V_305 = F_28 ( V_82 -> V_312 ) ;
if ( * V_305 == 0 )
goto V_316;
else if ( * V_305 > 0xFF00 ) {
F_7 ( V_115 , L_39 , * V_305 ) ;
* V_305 = 0 ;
V_34 = - V_48 ;
goto V_316;
}
if ( F_25 ( V_82 ) < F_28 ( V_82 -> V_311 ) + * V_305 ) {
F_7 ( V_115 , L_40 , * V_305 ,
F_28 ( V_82 -> V_311 ) ) ;
* V_305 = 0 ;
V_34 = - V_48 ;
goto V_316;
}
* V_304 = F_38 ( * V_305 , V_149 ) ;
if ( * V_304 == NULL ) {
V_34 = - V_72 ;
goto V_316;
}
memcpy ( * V_304 , V_82 -> V_2 . V_12 + F_28 ( V_82 -> V_311 ) ,
* V_305 ) ;
V_316:
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
int
F_63 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_232 , T_9 V_234 )
{
int V_34 ;
struct V_319 V_320 ;
char * V_321 = NULL ;
V_320 . V_322 =
F_4 ( V_323 ) ;
V_34 = F_35 ( V_78 , V_5 , V_232 , V_234 ,
V_324 , true ,
( char * ) & V_320 ,
2 , & V_321 , NULL ) ;
F_7 ( V_45 , L_41 , V_34 ) ;
return V_34 ;
}
int
F_64 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_232 , T_9 V_234 )
{
struct V_325 * V_80 ;
struct V_326 * V_82 ;
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
V_80 -> V_231 = V_232 ;
V_80 -> V_233 = V_234 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 1 , & V_85 , 0 ) ;
V_82 = (struct V_326 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 != 0 ) {
F_48 ( V_5 , V_327 ) ;
goto V_328;
}
V_328:
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
static int
F_65 ( unsigned int V_329 , unsigned int V_330 ,
struct V_1 * V_2 , unsigned int V_331 )
{
unsigned int V_332 = F_66 ( V_2 -> V_11 ) ;
char * V_333 = V_332 + 4 + ( char * ) V_2 ;
char * V_334 = 4 + V_329 + ( char * ) V_2 ;
char * V_335 = V_334 + V_330 ;
if ( V_330 < V_331 ) {
F_7 ( V_115 , L_43 ,
V_330 , V_331 ) ;
return - V_196 ;
}
if ( ( V_332 > 0x7FFFFF ) || ( V_330 > 0x7FFFFF ) ) {
F_7 ( V_115 , L_44 ,
V_330 , V_332 ) ;
return - V_196 ;
}
if ( ( V_334 > V_333 ) || ( V_335 > V_333 ) ) {
F_7 ( V_115 , L_45 ) ;
return - V_196 ;
}
return 0 ;
}
static int
F_67 ( unsigned int V_329 , unsigned int V_330 ,
struct V_1 * V_2 , unsigned int V_336 ,
char * V_337 )
{
char * V_334 = 4 + V_329 + ( char * ) V_2 ;
int V_34 ;
if ( ! V_337 )
return - V_196 ;
V_34 = F_65 ( V_329 , V_330 , V_2 , V_336 ) ;
if ( V_34 )
return V_34 ;
memcpy ( V_337 , V_334 , V_330 ) ;
return 0 ;
}
static int
F_68 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_232 , T_9 V_234 , T_10 V_338 ,
T_11 V_339 , T_11 V_340 , void * V_337 )
{
struct V_341 * V_80 ;
struct V_342 * V_82 = NULL ;
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
V_80 -> V_343 = V_344 ;
V_80 -> V_345 = V_338 ;
V_80 -> V_231 = V_232 ;
V_80 -> V_233 = V_234 ;
V_80 -> V_346 =
F_4 ( sizeof( struct V_341 ) - 1 - 4 ) ;
V_80 -> V_347 = F_5 ( V_339 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 1 , & V_85 , 0 ) ;
V_82 = (struct V_342 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 ) {
F_48 ( V_5 , V_348 ) ;
goto V_349;
}
V_34 = F_67 ( F_2 ( V_82 -> V_350 ) ,
F_28 ( V_82 -> V_347 ) ,
& V_82 -> V_2 , V_340 , V_337 ) ;
V_349:
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
int
F_69 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_232 , T_9 V_234 ,
struct V_258 * V_337 )
{
return F_68 ( V_78 , V_5 , V_232 , V_234 ,
V_351 ,
sizeof( struct V_258 ) + V_285 * 2 ,
sizeof( struct V_258 ) , V_337 ) ;
}
int
F_70 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_232 , T_9 V_234 , T_12 * V_352 )
{
return F_68 ( V_78 , V_5 , V_232 , V_234 ,
V_353 ,
sizeof( struct V_354 ) ,
sizeof( struct V_354 ) , V_352 ) ;
}
static void
F_71 ( struct V_355 * V_356 )
{
struct V_38 * V_21 = V_356 -> V_357 ;
struct V_358 * V_359 = (struct V_358 * ) V_356 -> V_360 ;
unsigned int V_361 = 1 ;
if ( V_356 -> V_362 == V_363 )
V_361 = F_2 ( V_359 -> V_2 . V_15 ) ;
F_72 ( V_356 ) ;
F_73 ( V_21 , V_361 , V_364 ) ;
}
int
F_74 ( struct V_38 * V_21 )
{
struct V_365 * V_80 ;
int V_34 = 0 ;
struct V_83 V_84 ;
struct V_366 V_367 = { . V_368 = & V_84 ,
. V_369 = 1 } ;
F_7 ( V_45 , L_47 ) ;
V_34 = F_18 ( V_370 , NULL , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_15 = F_4 ( 1 ) ;
V_84 . V_108 = ( char * ) V_80 ;
V_84 . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_75 ( V_21 , & V_367 , NULL , F_71 , V_21 ,
V_364 ) ;
if ( V_34 )
F_7 ( V_45 , L_48 , V_34 ) ;
F_61 ( V_80 ) ;
return V_34 ;
}
int
F_76 ( const unsigned int V_78 , struct V_4 * V_5 , T_9 V_232 ,
T_9 V_234 )
{
struct V_371 * V_80 ;
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
V_80 -> V_231 = V_232 ;
V_80 -> V_233 = V_234 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 1 , & V_85 , 0 ) ;
if ( ( V_34 != 0 ) && V_5 )
F_48 ( V_5 , V_372 ) ;
F_33 ( V_85 , V_84 [ 0 ] . V_108 ) ;
return V_34 ;
}
static int
F_77 ( struct V_83 * V_84 , struct V_373 * V_374 ,
unsigned int V_375 , int V_376 )
{
int V_34 = - V_377 ;
struct V_378 * V_80 = NULL ;
V_34 = F_18 ( V_64 , V_374 -> V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
if ( V_374 -> V_5 -> V_20 -> V_21 == NULL )
return - V_379 ;
V_80 -> V_2 . V_16 = F_5 ( V_374 -> V_380 ) ;
V_80 -> V_231 = V_374 -> V_232 ;
V_80 -> V_233 = V_374 -> V_234 ;
V_80 -> V_381 = 0 ;
V_80 -> V_382 = 0 ;
V_80 -> V_158 = 0 ;
V_80 -> V_383 = 0 ;
V_80 -> V_384 = F_5 ( V_374 -> V_385 ) ;
V_80 -> V_386 = F_78 ( V_374 -> V_329 ) ;
if ( V_376 & V_387 ) {
if ( ! ( V_376 & V_388 ) ) {
V_80 -> V_2 . V_389 =
F_5 ( F_25 ( V_80 ) + 4 ) ;
} else
V_80 -> V_2 . V_389 = 0 ;
if ( V_376 & V_390 ) {
V_80 -> V_2 . V_30 |= V_391 ;
V_80 -> V_2 . V_27 = 0xFFFFFFFF ;
V_80 -> V_2 . V_25 = 0xFFFFFFFF ;
V_80 -> V_231 = 0xFFFFFFFF ;
V_80 -> V_233 = 0xFFFFFFFF ;
}
}
if ( V_375 > V_374 -> V_385 )
V_80 -> V_392 = F_5 ( V_375 ) ;
else
V_80 -> V_392 = 0 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
return V_34 ;
}
static void
F_79 ( struct V_355 * V_356 )
{
struct V_393 * V_394 = V_356 -> V_357 ;
struct V_4 * V_5 = F_80 ( V_394 -> V_395 -> V_396 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_1 * V_220 = (struct V_1 * ) V_394 -> V_84 . V_108 ;
unsigned int V_361 = 1 ;
struct V_366 V_367 = { . V_368 = & V_394 -> V_84 ,
. V_369 = 1 ,
. V_397 = V_394 -> V_398 ,
. V_399 = V_394 -> V_400 ,
. V_401 = V_394 -> V_402 ,
. V_403 = V_394 -> V_404 } ;
F_7 ( V_45 , L_50 ,
V_91 , V_356 -> V_356 , V_356 -> V_362 , V_394 -> V_405 ,
V_394 -> V_406 ) ;
switch ( V_356 -> V_362 ) {
case V_363 :
V_361 = F_2 ( V_220 -> V_15 ) ;
if ( V_21 -> V_29 ) {
int V_34 ;
V_34 = F_81 ( & V_367 , V_21 ) ;
if ( V_34 )
F_7 ( V_115 , L_51 ,
V_34 ) ;
}
F_82 ( V_394 -> V_407 ) ;
F_83 ( V_5 , V_394 -> V_407 ) ;
break;
case V_408 :
case V_409 :
V_394 -> V_405 = - V_54 ;
if ( V_21 -> V_29 && V_394 -> V_407 )
V_394 -> V_407 = 0 ;
F_82 ( V_394 -> V_407 ) ;
F_83 ( V_5 , V_394 -> V_407 ) ;
break;
default:
if ( V_394 -> V_405 != - V_410 )
V_394 -> V_405 = - V_48 ;
}
if ( V_394 -> V_405 )
F_48 ( V_5 , V_411 ) ;
F_84 ( V_412 , & V_394 -> V_413 ) ;
F_72 ( V_356 ) ;
F_73 ( V_21 , V_361 , 0 ) ;
}
int
F_85 ( struct V_393 * V_394 )
{
int V_34 , V_89 = 0 ;
struct V_1 * V_220 ;
struct V_373 V_374 ;
struct V_366 V_367 = { . V_368 = & V_394 -> V_84 ,
. V_369 = 1 } ;
struct V_38 * V_21 ;
F_7 ( V_45 , L_52 ,
V_91 , V_394 -> V_329 , V_394 -> V_406 ) ;
V_374 . V_5 = F_80 ( V_394 -> V_395 -> V_396 ) ;
V_374 . V_329 = V_394 -> V_329 ;
V_374 . V_385 = V_394 -> V_406 ;
V_374 . V_232 = V_394 -> V_395 -> V_229 . V_232 ;
V_374 . V_234 = V_394 -> V_395 -> V_229 . V_234 ;
V_374 . V_380 = V_394 -> V_380 ;
V_21 = V_374 . V_5 -> V_20 -> V_21 ;
V_34 = F_77 ( & V_394 -> V_84 , & V_374 , 0 , 0 ) ;
if ( V_34 ) {
if ( V_34 == - V_54 && V_394 -> V_414 ) {
V_394 -> V_414 = 0 ;
F_44 ( & V_21 -> V_415 ) ;
V_21 -> V_416 -- ;
F_45 ( & V_21 -> V_415 ) ;
}
return V_34 ;
}
V_220 = (struct V_1 * ) V_394 -> V_84 . V_108 ;
V_394 -> V_84 . V_109 = F_25 ( V_394 -> V_84 . V_108 ) + 4 ;
if ( V_394 -> V_414 ) {
V_220 -> V_24 = F_4 ( F_86 ( V_394 -> V_406 ,
V_417 ) ) ;
F_44 ( & V_21 -> V_415 ) ;
V_21 -> V_414 += V_394 -> V_414 -
F_2 ( V_220 -> V_24 ) ;
F_45 ( & V_21 -> V_415 ) ;
F_87 ( & V_21 -> V_418 ) ;
V_89 = V_419 ;
}
F_88 ( & V_394 -> V_420 ) ;
V_34 = F_75 ( V_374 . V_5 -> V_20 -> V_21 , & V_367 ,
V_421 , F_79 ,
V_394 , V_89 ) ;
if ( V_34 ) {
F_89 ( & V_394 -> V_420 , V_422 ) ;
F_48 ( V_374 . V_5 , V_411 ) ;
}
F_61 ( V_220 ) ;
return V_34 ;
}
int
F_90 ( const unsigned int V_78 , struct V_373 * V_374 ,
unsigned int * V_423 , char * * V_220 , int * V_424 )
{
int V_85 , V_34 = - V_377 ;
struct V_425 * V_82 = NULL ;
struct V_83 V_84 [ 1 ] ;
* V_423 = 0 ;
V_34 = F_77 ( V_84 , V_374 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_26 ( V_78 , V_374 -> V_5 -> V_20 , V_84 , 1 ,
& V_85 , V_164 ) ;
V_82 = (struct V_425 * ) V_84 [ 0 ] . V_108 ;
if ( V_82 -> V_2 . V_165 == V_426 ) {
F_33 ( V_85 , V_84 [ 0 ] . V_108 ) ;
return 0 ;
}
if ( V_34 ) {
F_48 ( V_374 -> V_5 , V_411 ) ;
F_7 ( V_115 , L_53 , V_34 ) ;
} else {
* V_423 = F_28 ( V_82 -> V_224 ) ;
if ( ( * V_423 > V_427 ) ||
( * V_423 > V_374 -> V_385 ) ) {
F_7 ( V_45 , L_54 ,
* V_423 , V_374 -> V_385 ) ;
V_34 = - V_48 ;
* V_423 = 0 ;
}
}
if ( * V_220 ) {
memcpy ( * V_220 , ( char * ) V_82 -> V_2 . V_12 + V_82 -> V_222 ,
* V_423 ) ;
F_33 ( V_85 , V_84 [ 0 ] . V_108 ) ;
} else if ( V_85 != V_140 ) {
* V_220 = V_84 [ 0 ] . V_108 ;
if ( V_85 == V_428 )
* V_424 = V_428 ;
else if ( V_85 == V_429 )
* V_424 = V_429 ;
}
return V_34 ;
}
static void
F_91 ( struct V_355 * V_356 )
{
struct V_430 * V_431 = V_356 -> V_357 ;
struct V_4 * V_5 = F_80 ( V_431 -> V_395 -> V_396 ) ;
unsigned int V_432 ;
struct V_433 * V_82 = (struct V_433 * ) V_356 -> V_360 ;
unsigned int V_361 = 1 ;
switch ( V_356 -> V_362 ) {
case V_363 :
V_361 = F_2 ( V_82 -> V_2 . V_15 ) ;
V_431 -> V_405 = F_92 ( V_356 , V_5 -> V_20 -> V_21 , 0 ) ;
if ( V_431 -> V_405 != 0 )
break;
V_432 = F_28 ( V_82 -> V_224 ) ;
if ( V_432 > V_431 -> V_406 )
V_432 &= 0xFFFF ;
if ( V_432 < V_431 -> V_406 )
V_431 -> V_405 = - V_434 ;
else
V_431 -> V_406 = V_432 ;
break;
case V_408 :
case V_409 :
V_431 -> V_405 = - V_54 ;
break;
default:
V_431 -> V_405 = - V_48 ;
break;
}
if ( V_431 -> V_405 )
F_48 ( V_5 , V_435 ) ;
F_84 ( V_412 , & V_431 -> V_413 ) ;
F_72 ( V_356 ) ;
F_73 ( V_5 -> V_20 -> V_21 , V_361 , 0 ) ;
}
int
F_93 ( struct V_430 * V_431 ,
void (* F_94)( struct V_436 * V_436 ) )
{
int V_34 = - V_377 , V_89 = 0 ;
struct V_437 * V_80 = NULL ;
struct V_4 * V_5 = F_80 ( V_431 -> V_395 -> V_396 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_83 V_84 ;
struct V_366 V_367 ;
V_34 = F_18 ( V_42 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 ) {
if ( V_34 == - V_54 && V_431 -> V_414 ) {
V_431 -> V_414 = 0 ;
F_44 ( & V_21 -> V_415 ) ;
V_21 -> V_416 -- ;
F_45 ( & V_21 -> V_415 ) ;
}
goto V_438;
}
V_80 -> V_2 . V_16 = F_5 ( V_431 -> V_395 -> V_380 ) ;
V_80 -> V_231 = V_431 -> V_395 -> V_229 . V_232 ;
V_80 -> V_233 = V_431 -> V_395 -> V_229 . V_234 ;
V_80 -> V_439 = 0 ;
V_80 -> V_440 = 0 ;
V_80 -> V_158 = 0 ;
V_80 -> V_386 = F_78 ( V_431 -> V_329 ) ;
V_80 -> V_222 = F_4 (
F_42 ( struct V_437 , V_167 ) - 4 ) ;
V_80 -> V_392 = 0 ;
V_84 . V_109 = F_25 ( V_80 ) + 4 - 1 ;
V_84 . V_108 = V_80 ;
V_367 . V_368 = & V_84 ;
V_367 . V_369 = 1 ;
V_367 . V_397 = V_431 -> V_398 ;
V_367 . V_399 = V_431 -> V_400 ;
V_367 . V_401 = V_431 -> V_402 ;
V_367 . V_403 = V_431 -> V_404 ;
F_7 ( V_45 , L_55 ,
V_431 -> V_329 , V_431 -> V_406 ) ;
V_80 -> V_384 = F_5 ( V_431 -> V_406 ) ;
F_24 ( & V_80 -> V_2 , V_431 -> V_406 - 1 ) ;
if ( V_431 -> V_414 ) {
V_80 -> V_2 . V_24 = F_4 ( F_86 ( V_431 -> V_406 ,
V_417 ) ) ;
F_44 ( & V_21 -> V_415 ) ;
V_21 -> V_414 += V_431 -> V_414 -
F_2 ( V_80 -> V_2 . V_24 ) ;
F_45 ( & V_21 -> V_415 ) ;
F_87 ( & V_21 -> V_418 ) ;
V_89 = V_419 ;
}
F_88 ( & V_431 -> V_420 ) ;
V_34 = F_75 ( V_21 , & V_367 , NULL , F_91 , V_431 ,
V_89 ) ;
if ( V_34 ) {
F_89 ( & V_431 -> V_420 , F_94 ) ;
F_48 ( V_5 , V_435 ) ;
}
V_438:
F_61 ( V_80 ) ;
return V_34 ;
}
int
F_95 ( const unsigned int V_78 , struct V_373 * V_374 ,
unsigned int * V_423 , struct V_83 * V_84 , int V_441 )
{
int V_34 = 0 ;
struct V_437 * V_80 = NULL ;
struct V_433 * V_82 = NULL ;
int V_85 ;
* V_423 = 0 ;
if ( V_441 < 1 )
return V_34 ;
V_34 = F_18 ( V_42 , V_374 -> V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
if ( V_374 -> V_5 -> V_20 -> V_21 == NULL )
return - V_379 ;
V_80 -> V_2 . V_16 = F_5 ( V_374 -> V_380 ) ;
V_80 -> V_231 = V_374 -> V_232 ;
V_80 -> V_233 = V_374 -> V_234 ;
V_80 -> V_439 = 0 ;
V_80 -> V_440 = 0 ;
V_80 -> V_158 = 0 ;
V_80 -> V_384 = F_5 ( V_374 -> V_385 ) ;
V_80 -> V_386 = F_78 ( V_374 -> V_329 ) ;
V_80 -> V_222 = F_4 (
F_42 ( struct V_437 , V_167 ) - 4 ) ;
V_80 -> V_392 = 0 ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - 1 ;
F_24 ( V_80 , V_374 -> V_385 - 1 ) ;
V_34 = F_26 ( V_78 , V_374 -> V_5 -> V_20 , V_84 , V_441 + 1 ,
& V_85 , 0 ) ;
V_82 = (struct V_433 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 ) {
F_48 ( V_374 -> V_5 , V_435 ) ;
F_7 ( V_115 , L_56 , V_34 ) ;
} else
* V_423 = F_28 ( V_82 -> V_224 ) ;
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
static unsigned int
F_96 ( char * V_442 , char * V_335 , char * * V_443 , T_11 V_444 )
{
int V_445 ;
unsigned int V_446 = 0 ;
unsigned int V_447 = 0 ;
T_13 * V_448 ;
if ( V_442 == NULL )
return 0 ;
V_448 = ( T_13 * ) V_442 ;
while ( 1 ) {
V_448 = ( T_13 * )
( ( char * ) V_448 + V_447 ) ;
if ( ( char * ) V_448 + V_444 > V_335 ) {
F_7 ( V_115 , L_57 ) ;
break;
}
V_445 = F_28 ( V_448 -> V_449 ) ;
if ( ( char * ) V_448 + V_445 + V_444 > V_335 ) {
F_7 ( V_115 , L_58 ,
V_335 ) ;
break;
}
* V_443 = ( char * ) V_448 ;
V_446 ++ ;
V_447 = F_28 ( V_448 -> V_450 ) ;
if ( ! V_447 )
break;
}
return V_446 ;
}
int
F_97 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_232 , T_9 V_234 , int V_451 ,
struct V_452 * V_453 )
{
struct V_454 * V_80 ;
struct V_455 * V_82 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_34 = 0 ;
int V_445 ;
int V_85 ;
unsigned char * V_456 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
T_1 V_457 = F_4 ( '*' ) ;
char * V_333 ;
unsigned int V_458 = V_459 ;
T_11 V_460 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_67 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
switch ( V_453 -> V_461 ) {
case V_462 :
V_80 -> V_463 = V_464 ;
V_460 = sizeof( T_13 ) - 1 ;
break;
case V_465 :
V_80 -> V_463 = V_466 ;
V_460 = sizeof( V_467 ) - 1 ;
break;
default:
F_7 ( V_115 , L_59 ,
V_453 -> V_461 ) ;
V_34 = - V_196 ;
goto V_468;
}
V_80 -> V_469 = F_5 ( V_451 ) ;
V_80 -> V_231 = V_232 ;
V_80 -> V_233 = V_234 ;
V_445 = 0x2 ;
V_456 = V_80 -> V_167 ;
memcpy ( V_456 , & V_457 , V_445 ) ;
V_80 -> V_470 =
F_4 ( sizeof( struct V_454 ) - 1 - 4 ) ;
V_80 -> V_449 = F_4 ( V_445 ) ;
V_458 = F_27 (unsigned int, output_size, server->maxBuf) ;
V_458 = F_27 (unsigned int, output_size, 2 << 15 ) ;
V_80 -> V_347 = F_5 ( V_458 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - 1 ;
V_84 [ 1 ] . V_108 = ( char * ) ( V_80 -> V_167 ) ;
V_84 [ 1 ] . V_109 = V_445 ;
F_24 ( V_80 , V_445 - 1 ) ;
V_34 = F_26 ( V_78 , V_20 , V_84 , 2 , & V_85 , 0 ) ;
V_82 = (struct V_455 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 ) {
if ( V_34 == - V_410 && V_82 -> V_2 . V_165 == V_471 ) {
V_453 -> V_472 = true ;
V_34 = 0 ;
}
F_48 ( V_5 , V_473 ) ;
goto V_468;
}
V_34 = F_65 ( F_2 ( V_82 -> V_350 ) ,
F_28 ( V_82 -> V_347 ) , & V_82 -> V_2 ,
V_460 ) ;
if ( V_34 )
goto V_468;
V_453 -> V_474 = true ;
if ( V_453 -> V_475 ) {
if ( V_453 -> V_476 )
F_61 ( V_453 -> V_475 ) ;
else
F_98 ( V_453 -> V_475 ) ;
}
V_453 -> V_475 = ( char * ) V_82 ;
V_453 -> V_477 = V_453 -> V_478 = 4 +
( char * ) & V_82 -> V_2 + F_2 ( V_82 -> V_350 ) ;
V_333 = F_25 ( V_82 ) + 4 + ( char * ) & V_82 -> V_2 ;
V_453 -> V_479 =
F_96 ( V_453 -> V_477 , V_333 ,
& V_453 -> V_478 , V_460 ) ;
V_453 -> V_480 += V_453 -> V_479 ;
F_7 ( V_45 , L_60 ,
V_453 -> V_479 , V_453 -> V_480 ,
V_453 -> V_477 , V_453 -> V_478 ) ;
if ( V_85 == V_429 )
V_453 -> V_476 = false ;
else if ( V_85 == V_428 )
V_453 -> V_476 = true ;
else
F_7 ( V_115 , L_61 ) ;
return V_34 ;
V_468:
F_33 ( V_85 , V_82 ) ;
return V_34 ;
}
static int
F_99 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_232 , T_9 V_234 , T_4 V_380 , int V_338 ,
unsigned int V_248 , void * * V_337 , unsigned int * V_444 )
{
struct V_481 * V_80 ;
struct V_482 * V_82 = NULL ;
struct V_83 * V_84 ;
int V_34 = 0 ;
int V_85 ;
unsigned int V_483 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( ! V_248 )
return - V_196 ;
V_84 = F_38 ( sizeof( struct V_83 ) * V_248 , V_149 ) ;
if ( ! V_84 )
return - V_72 ;
V_34 = F_18 ( V_70 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 ) {
F_37 ( V_84 ) ;
return V_34 ;
}
V_80 -> V_2 . V_16 = F_5 ( V_380 ) ;
V_80 -> V_343 = V_344 ;
V_80 -> V_345 = V_338 ;
V_80 -> V_231 = V_232 ;
V_80 -> V_233 = V_234 ;
V_80 -> V_484 =
F_4 ( sizeof( struct V_481 ) - 1 - 4 ) ;
V_80 -> V_485 = F_5 ( * V_444 ) ;
F_24 ( V_80 , * V_444 - 1 ) ;
memcpy ( V_80 -> V_167 , * V_337 , * V_444 ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 ;
for ( V_483 = 1 ; V_483 < V_248 ; V_483 ++ ) {
F_24 ( V_80 , V_444 [ V_483 ] ) ;
F_57 ( & V_80 -> V_485 , V_444 [ V_483 ] ) ;
V_84 [ V_483 ] . V_108 = ( char * ) V_337 [ V_483 ] ;
V_84 [ V_483 ] . V_109 = V_444 [ V_483 ] ;
}
V_34 = F_26 ( V_78 , V_20 , V_84 , V_248 , & V_85 , 0 ) ;
V_82 = (struct V_482 * ) V_84 [ 0 ] . V_108 ;
if ( V_34 != 0 )
F_48 ( V_5 , V_486 ) ;
F_33 ( V_85 , V_82 ) ;
F_37 ( V_84 ) ;
return V_34 ;
}
int
F_100 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_232 , T_9 V_234 , T_1 * V_487 )
{
struct V_488 V_489 ;
void * * V_337 ;
unsigned int V_444 [ 2 ] ;
int V_34 ;
int V_445 = ( 2 * F_60 ( ( V_284 * ) V_487 , V_285 ) ) ;
V_337 = F_38 ( sizeof( void * ) * 2 , V_149 ) ;
if ( ! V_337 )
return - V_72 ;
V_489 . V_490 = 1 ;
V_489 . V_491 = 0 ;
V_489 . V_449 = F_5 ( V_445 ) ;
V_337 [ 0 ] = & V_489 ;
V_444 [ 0 ] = sizeof( struct V_488 ) ;
V_337 [ 1 ] = V_487 ;
V_444 [ 1 ] = V_445 + 2 ;
V_34 = F_99 ( V_78 , V_5 , V_232 , V_234 ,
V_17 -> V_18 , V_492 , 2 , V_337 ,
V_444 ) ;
F_37 ( V_337 ) ;
return V_34 ;
}
int
F_101 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_232 , T_9 V_234 , T_1 * V_487 )
{
struct V_493 V_489 ;
void * * V_337 ;
unsigned int V_444 [ 2 ] ;
int V_34 ;
int V_445 = ( 2 * F_60 ( ( V_284 * ) V_487 , V_285 ) ) ;
V_337 = F_38 ( sizeof( void * ) * 2 , V_149 ) ;
if ( ! V_337 )
return - V_72 ;
V_489 . V_490 = 0 ;
V_489 . V_491 = 0 ;
V_489 . V_449 = F_5 ( V_445 ) ;
V_337 [ 0 ] = & V_489 ;
V_444 [ 0 ] = sizeof( struct V_493 ) ;
V_337 [ 1 ] = V_487 ;
V_444 [ 1 ] = V_445 + 2 ;
V_34 = F_99 ( V_78 , V_5 , V_232 , V_234 ,
V_17 -> V_18 , V_494 , 2 , V_337 , V_444 ) ;
F_37 ( V_337 ) ;
return V_34 ;
}
int
F_102 ( const unsigned int V_78 , struct V_4 * V_5 , T_9 V_232 ,
T_9 V_234 , T_4 V_380 , T_12 * V_495 , bool V_496 )
{
struct V_497 V_489 ;
void * V_337 ;
unsigned int V_444 ;
V_489 . V_294 = * V_495 ;
V_337 = & V_489 ;
V_444 = sizeof( struct V_497 ) ;
if ( V_496 )
return F_99 ( V_78 , V_5 , V_232 , V_234 ,
V_380 , V_498 , 1 , & V_337 , & V_444 ) ;
else
return F_99 ( V_78 , V_5 , V_232 , V_234 ,
V_380 , V_499 , 1 , & V_337 , & V_444 ) ;
}
int
F_103 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_232 , T_9 V_234 , T_14 * V_220 )
{
unsigned int V_444 ;
V_444 = sizeof( T_14 ) ;
return F_99 ( V_78 , V_5 , V_232 , V_234 ,
V_17 -> V_18 , V_500 , 1 ,
( void * * ) & V_220 , & V_444 ) ;
}
int
F_104 ( const unsigned int V_78 , struct V_4 * V_5 ,
const T_9 V_232 , const T_9 V_234 ,
T_7 V_501 )
{
int V_34 ;
struct V_502 * V_80 = NULL ;
F_7 ( V_45 , L_62 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_503 = V_234 ;
V_80 -> V_504 = V_232 ;
V_80 -> V_299 = V_501 ;
V_80 -> V_2 . V_15 = F_4 ( 1 ) ;
V_34 = F_47 ( V_78 , V_5 -> V_20 , ( char * ) V_80 , V_505 ) ;
if ( V_34 ) {
F_48 ( V_5 , V_506 ) ;
F_7 ( V_45 , L_63 , V_34 ) ;
}
return V_34 ;
}
static void
F_105 ( struct V_507 * V_508 ,
struct V_509 * V_510 )
{
V_510 -> V_511 = F_28 ( V_508 -> V_512 ) *
F_28 ( V_508 -> V_513 ) ;
V_510 -> V_514 = F_106 ( V_508 -> V_515 ) ;
V_510 -> V_516 = F_106 ( V_508 -> V_517 ) ;
V_510 -> V_518 = F_106 ( V_508 -> V_519 ) ;
return;
}
static int
F_107 ( struct V_83 * V_84 , struct V_4 * V_5 , int V_520 ,
int V_521 , T_9 V_232 , T_9 V_234 )
{
int V_34 ;
struct V_341 * V_80 ;
F_7 ( V_45 , L_64 , V_520 ) ;
if ( ( V_5 -> V_20 == NULL ) || ( V_5 -> V_20 -> V_21 == NULL ) )
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_343 = V_522 ;
V_80 -> V_345 = V_520 ;
V_80 -> V_231 = V_232 ;
V_80 -> V_233 = V_234 ;
V_80 -> V_346 =
F_4 ( sizeof( struct V_341 ) - 1 - 4 ) ;
V_80 -> V_347 = F_5 (
V_521 + sizeof( struct V_342 ) - 1 - 4 ) ;
V_84 -> V_108 = ( char * ) V_80 ;
V_84 -> V_109 = F_25 ( V_80 ) + 4 ;
return 0 ;
}
int
F_108 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_232 , T_9 V_234 , struct V_509 * V_523 )
{
struct V_342 * V_82 = NULL ;
struct V_83 V_84 ;
int V_34 = 0 ;
int V_85 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_507 * V_489 = NULL ;
V_34 = F_107 ( & V_84 , V_5 , V_524 ,
sizeof( struct V_507 ) ,
V_232 , V_234 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_26 ( V_78 , V_20 , & V_84 , 1 , & V_85 , 0 ) ;
if ( V_34 ) {
F_48 ( V_5 , V_348 ) ;
goto V_525;
}
V_82 = (struct V_342 * ) V_84 . V_108 ;
V_489 = (struct V_507 * ) ( 4 +
F_2 ( V_82 -> V_350 ) + ( char * ) & V_82 -> V_2 ) ;
V_34 = F_65 ( F_2 ( V_82 -> V_350 ) ,
F_28 ( V_82 -> V_347 ) , & V_82 -> V_2 ,
sizeof( struct V_507 ) ) ;
if ( ! V_34 )
F_105 ( V_489 , V_523 ) ;
V_525:
F_33 ( V_85 , V_84 . V_108 ) ;
return V_34 ;
}
int
F_109 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_9 V_232 , T_9 V_234 , int V_520 )
{
struct V_342 * V_82 = NULL ;
struct V_83 V_84 ;
int V_34 = 0 ;
int V_85 , V_526 , V_340 ;
struct V_37 * V_20 = V_5 -> V_20 ;
unsigned int V_527 , V_329 ;
if ( V_520 == V_528 ) {
V_526 = sizeof( V_529 ) ;
V_340 = sizeof( V_529 ) ;
} else if ( V_520 == V_530 ) {
V_526 = sizeof( V_531 ) ;
V_340 = V_532 ;
} else if ( V_520 == V_533 ) {
V_526 = sizeof( struct V_534 ) ;
V_340 = sizeof( struct V_534 ) ;
} else {
F_7 ( V_45 , L_65 , V_520 ) ;
return - V_196 ;
}
V_34 = F_107 ( & V_84 , V_5 , V_520 , V_526 ,
V_232 , V_234 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_26 ( V_78 , V_20 , & V_84 , 1 , & V_85 , 0 ) ;
if ( V_34 ) {
F_48 ( V_5 , V_348 ) ;
goto V_535;
}
V_82 = (struct V_342 * ) V_84 . V_108 ;
V_527 = F_28 ( V_82 -> V_347 ) ;
V_329 = F_2 ( V_82 -> V_350 ) ;
V_34 = F_65 ( V_329 , V_527 , & V_82 -> V_2 , V_340 ) ;
if ( V_34 )
goto V_535;
if ( V_520 == V_530 )
memcpy ( & V_5 -> V_536 , 4 + V_329
+ ( char * ) & V_82 -> V_2 , F_27 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_520 == V_528 )
memcpy ( & V_5 -> V_537 , 4 + V_329
+ ( char * ) & V_82 -> V_2 , sizeof( V_529 ) ) ;
else if ( V_520 == V_533 ) {
struct V_534 * V_538 = (struct V_534 * )
( 4 + V_329 + ( char * ) & V_82 -> V_2 ) ;
V_5 -> V_539 = F_28 ( V_538 -> V_30 ) ;
V_5 -> V_540 =
F_28 ( V_538 -> V_541 ) ;
}
V_535:
F_33 ( V_85 , V_84 . V_108 ) ;
return V_34 ;
}
int
F_110 ( const unsigned int V_78 , struct V_4 * V_5 ,
const T_15 V_542 , const T_15 V_234 , const T_8 V_380 ,
const T_8 V_543 , struct V_544 * V_220 )
{
int V_34 = 0 ;
struct V_545 * V_80 = NULL ;
struct V_83 V_84 [ 2 ] ;
int V_546 ;
unsigned int V_547 ;
F_7 ( V_45 , L_66 , V_543 ) ;
V_34 = F_18 ( V_65 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_16 = F_5 ( V_380 ) ;
V_80 -> V_548 = F_4 ( V_543 ) ;
V_80 -> V_231 = V_542 ;
V_80 -> V_233 = V_234 ;
V_547 = V_543 * sizeof( struct V_544 ) ;
F_24 ( V_80 , V_547 - sizeof( struct V_544 ) ) ;
V_84 [ 0 ] . V_108 = ( char * ) V_80 ;
V_84 [ 0 ] . V_109 = F_25 ( V_80 ) + 4 - V_547 ;
V_84 [ 1 ] . V_108 = ( char * ) V_220 ;
V_84 [ 1 ] . V_109 = V_547 ;
F_21 ( & V_5 -> V_74 . V_549 . V_550 ) ;
V_34 = F_26 ( V_78 , V_5 -> V_20 , V_84 , 2 , & V_546 , V_551 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_67 , V_34 ) ;
F_48 ( V_5 , V_552 ) ;
}
return V_34 ;
}
int
F_111 ( const unsigned int V_78 , struct V_4 * V_5 ,
const T_15 V_542 , const T_15 V_234 , const T_8 V_380 ,
const T_15 V_385 , const T_15 V_329 , const T_8 V_553 ,
const bool V_554 )
{
struct V_544 V_555 ;
V_555 . V_386 = F_78 ( V_329 ) ;
V_555 . V_384 = F_78 ( V_385 ) ;
V_555 . V_30 = F_5 ( V_553 ) ;
if ( ! V_554 && V_553 != V_556 )
V_555 . V_30 |= F_5 ( V_557 ) ;
return F_110 ( V_78 , V_5 , V_542 , V_234 , V_380 , 1 , & V_555 ) ;
}
int
F_112 ( const unsigned int V_78 , struct V_4 * V_5 ,
T_7 * V_558 , const T_5 V_559 )
{
int V_34 ;
struct V_560 * V_80 = NULL ;
F_7 ( V_45 , L_68 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_80 ) ;
if ( V_34 )
return V_34 ;
V_80 -> V_2 . V_15 = F_4 ( 1 ) ;
V_80 -> V_13 = F_4 ( 36 ) ;
F_24 ( V_80 , 12 ) ;
memcpy ( V_80 -> V_561 , V_558 , 16 ) ;
V_80 -> V_562 = V_559 ;
V_34 = F_47 ( V_78 , V_5 -> V_20 , ( char * ) V_80 , V_505 ) ;
if ( V_34 ) {
F_48 ( V_5 , V_506 ) ;
F_7 ( V_45 , L_69 , V_34 ) ;
}
return V_34 ;
}
