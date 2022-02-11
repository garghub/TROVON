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
V_21 -> V_121 = F_30 (unsigned int, le32_to_cpu(rsp->MaxTransactSize),
SMB2_MAX_BUFFER_SIZE) ;
V_21 -> V_122 = F_31 ( V_79 -> V_123 ) ;
V_21 -> V_124 = F_31 ( V_79 -> V_125 ) ;
V_21 -> V_126 = F_2 ( V_79 -> V_99 ) ;
V_21 -> V_22 = F_31 ( V_79 -> V_104 ) ;
V_21 -> V_22 |= V_127 | V_128 ;
V_90 = F_32 ( & V_88 , & V_89 ,
& V_79 -> V_2 ) ;
if ( V_89 == 0 )
F_7 ( V_45 , L_12 ) ;
V_34 = F_33 ( V_21 , V_20 -> V_29 ) ;
#ifdef F_34
if ( V_34 )
goto V_111;
if ( V_89 )
V_34 = F_35 ( V_90 , V_89 ,
& V_21 -> V_129 ) ;
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
int F_36 ( const unsigned int V_82 , struct V_4 * V_5 )
{
int V_34 = 0 ;
struct V_130 V_131 ;
struct V_132 * V_133 ;
T_4 V_134 ;
F_7 ( V_45 , L_13 ) ;
if ( V_5 -> V_20 -> V_21 -> V_29 == false )
return 0 ;
V_131 . V_104 =
F_5 ( V_5 -> V_20 -> V_21 -> V_96 -> V_105 ) ;
memcpy ( V_131 . V_135 , V_107 , V_108 ) ;
if ( V_5 -> V_20 -> V_29 )
V_131 . V_99 =
F_4 ( V_100 ) ;
else if ( V_101 & V_102 )
V_131 . V_99 =
F_4 ( V_103 ) ;
else
V_131 . V_99 = 0 ;
V_131 . V_98 = F_4 ( 1 ) ;
V_131 . V_95 [ 0 ] =
F_4 ( V_5 -> V_20 -> V_21 -> V_96 -> V_97 ) ;
V_34 = F_37 ( V_82 , V_5 , V_136 , V_136 ,
V_137 , true ,
( char * ) & V_131 , sizeof( struct V_130 ) ,
( char * * ) & V_133 , & V_134 ) ;
if ( V_34 != 0 ) {
F_7 ( V_117 , L_14 , V_34 ) ;
return - V_48 ;
}
if ( V_134 != sizeof( struct V_132 ) ) {
F_7 ( V_117 , L_15 ) ;
return - V_48 ;
}
if ( V_133 -> V_138 !=
F_4 ( V_5 -> V_20 -> V_21 -> V_96 -> V_97 ) )
goto V_139;
if ( V_133 -> V_99 != F_4 ( V_5 -> V_20 -> V_21 -> V_126 ) )
goto V_139;
if ( ( F_31 ( V_133 -> V_104 ) | V_127 |
V_128 ) != V_5 -> V_20 -> V_21 -> V_22 )
goto V_139;
F_7 ( V_45 , L_16 ) ;
return 0 ;
V_139:
F_7 ( V_117 , L_17 ) ;
return - V_48 ;
}
int
F_38 ( const unsigned int V_82 , struct V_37 * V_20 ,
const struct V_35 * V_140 )
{
struct V_141 * V_84 ;
struct V_142 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_34 = 0 ;
int V_78 ;
T_5 V_143 = V_144 ;
struct V_38 * V_21 = V_20 -> V_21 ;
T_6 V_89 = 0 ;
char * V_90 ;
char * V_145 = NULL ;
bool V_146 = false ;
F_7 ( V_45 , L_18 ) ;
if ( ! V_21 ) {
F_26 ( 1 , L_5 , V_93 ) ;
return - V_48 ;
}
F_39 ( V_20 -> V_147 . V_148 ) ;
V_20 -> V_147 . V_148 = NULL ;
V_20 -> V_149 = F_40 ( sizeof( struct V_150 ) , V_151 ) ;
if ( ! V_20 -> V_149 )
return - V_72 ;
V_20 -> V_149 -> V_152 = true ;
V_20 -> V_153 = V_154 ;
V_155:
if ( V_143 == V_156 )
V_143 = V_157 ;
V_34 = F_18 ( V_158 , NULL , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_27 = 0 ;
V_84 -> V_159 = 0 ;
V_84 -> V_2 . V_15 = F_4 ( 3 ) ;
if ( V_21 -> V_29 )
V_84 -> V_99 = V_100 ;
else if ( V_101 & V_102 )
V_84 -> V_99 = V_103 ;
else
V_84 -> V_99 = 0 ;
V_84 -> V_104 = 0 ;
V_84 -> V_160 = 0 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
if ( V_143 == V_144 ) {
V_145 = F_40 ( sizeof( struct V_161 ) ,
V_151 ) ;
if ( V_145 == NULL ) {
V_34 = - V_72 ;
goto V_162;
}
F_41 ( V_145 , V_20 ) ;
if ( V_146 ) {
F_7 ( V_117 , L_19 ) ;
V_34 = - V_163 ;
F_39 ( V_145 ) ;
goto V_162;
} else {
V_89 = sizeof( struct V_161 ) ;
V_90 = V_145 ;
}
} else if ( V_143 == V_157 ) {
V_84 -> V_2 . V_27 = V_20 -> V_28 ;
V_145 = F_42 ( sizeof( struct V_161 ) + 500 ,
V_151 ) ;
if ( V_145 == NULL ) {
V_34 = - V_72 ;
goto V_162;
}
V_34 = F_43 ( V_145 , & V_89 , V_20 ,
V_140 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_20 ,
V_34 ) ;
goto V_162;
}
if ( V_146 ) {
F_7 ( V_117 , L_19 ) ;
V_34 = - V_163 ;
F_39 ( V_145 ) ;
goto V_162;
} else {
V_90 = V_145 ;
}
} else {
F_7 ( V_117 , L_21 ) ;
V_34 = - V_48 ;
goto V_162;
}
V_84 -> V_164 =
F_4 ( sizeof( struct V_141 ) -
1 - 4 ) ;
V_84 -> V_165 = F_4 ( V_89 ) ;
V_87 [ 1 ] . V_109 = V_90 ;
V_87 [ 1 ] . V_110 = V_89 ;
F_27 ( V_84 , V_89 - 1 ) ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 2 , & V_78 ,
V_166 | V_92 ) ;
F_39 ( V_90 ) ;
V_79 = (struct V_142 * ) V_87 [ 0 ] . V_109 ;
if ( V_78 != V_167 &&
V_79 -> V_2 . V_168 == V_169 ) {
if ( V_143 != V_144 ) {
F_7 ( V_117 , L_22 ) ;
goto V_162;
}
if ( F_44 ( struct V_142 , V_170 ) - 4 !=
F_2 ( V_79 -> V_164 ) ) {
F_7 ( V_117 , L_23 ,
F_2 ( V_79 -> V_164 ) ) ;
V_34 = - V_48 ;
goto V_162;
}
V_143 = V_156 ;
V_34 = 0 ;
V_20 -> V_28 = V_79 -> V_2 . V_27 ;
V_34 = F_45 ( V_79 -> V_170 ,
F_2 ( V_79 -> V_165 ) , V_20 ) ;
}
if ( V_34 != 0 )
goto V_162;
V_20 -> V_171 = F_2 ( V_79 -> V_172 ) ;
if ( V_20 -> V_171 & V_173 )
F_7 ( V_117 , L_24 ) ;
V_162:
F_22 ( V_78 , V_79 ) ;
if ( ( V_143 == V_156 ) && ( V_34 == 0 ) )
goto V_155;
if ( ! V_34 ) {
F_10 ( & V_21 -> V_174 ) ;
if ( V_21 -> V_29 && V_21 -> V_175 -> V_176 ) {
V_34 = V_21 -> V_175 -> V_176 ( V_20 ) ;
F_39 ( V_20 -> V_147 . V_148 ) ;
V_20 -> V_147 . V_148 = NULL ;
if ( V_34 ) {
F_7 ( V_45 ,
L_25 ) ;
F_13 ( & V_21 -> V_174 ) ;
goto V_177;
}
}
if ( ! V_21 -> V_178 ) {
V_21 -> V_179 = 0x2 ;
V_21 -> V_178 = true ;
}
F_13 ( & V_21 -> V_174 ) ;
F_7 ( V_45 , L_26 ) ;
F_46 ( & V_180 ) ;
V_20 -> V_47 = V_181 ;
V_20 -> V_59 = false ;
F_47 ( & V_180 ) ;
}
V_177:
if ( ! V_21 -> V_29 ) {
F_39 ( V_20 -> V_147 . V_148 ) ;
V_20 -> V_147 . V_148 = NULL ;
}
F_39 ( V_20 -> V_149 ) ;
return V_34 ;
}
int
F_48 ( const unsigned int V_82 , struct V_37 * V_20 )
{
struct V_182 * V_84 ;
int V_34 = 0 ;
struct V_38 * V_21 ;
F_7 ( V_45 , L_27 , V_20 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_20 -> V_59 )
goto V_183;
V_34 = F_18 ( V_184 , NULL , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_27 = V_20 -> V_28 ;
if ( V_21 -> V_29 )
V_84 -> V_2 . V_30 |= V_31 ;
V_34 = F_49 ( V_82 , V_20 , ( char * ) & V_84 -> V_2 , 0 ) ;
V_183:
return V_34 ;
}
static inline void F_50 ( struct V_4 * V_5 , T_3 V_185 )
{
F_21 ( & V_5 -> V_74 . V_75 . V_186 [ V_185 ] ) ;
}
static inline void F_51 ( struct V_4 * V_5 )
{
V_5 -> V_187 = 256 ;
V_5 -> V_188 = 1048576 ;
V_5 -> V_189 = 16777216 ;
}
int
F_15 ( const unsigned int V_82 , struct V_37 * V_20 , const char * V_190 ,
struct V_4 * V_5 , const struct V_35 * V_191 )
{
struct V_192 * V_84 ;
struct V_193 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_34 = 0 ;
int V_78 ;
int V_194 ;
struct V_38 * V_21 ;
T_1 * V_195 = NULL ;
F_7 ( V_45 , L_28 ) ;
if ( ( V_20 -> V_21 ) && V_190 )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_5 && V_5 -> V_196 )
return - V_197 ;
V_195 = F_40 ( V_198 * 2 , V_151 ) ;
if ( V_195 == NULL )
return - V_72 ;
V_194 = F_52 ( V_195 , V_190 , strlen ( V_190 ) , V_191 ) + 1 ;
V_194 *= 2 ;
if ( V_194 < 2 ) {
F_39 ( V_195 ) ;
return - V_199 ;
}
V_34 = F_18 ( V_39 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 ) {
F_39 ( V_195 ) ;
return V_34 ;
}
if ( V_5 == NULL ) {
V_84 -> V_2 . V_27 = V_20 -> V_28 ;
}
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
V_84 -> V_200 = F_4 ( sizeof( struct V_192 )
- 1 - 4 ) ;
V_84 -> V_201 = F_4 ( V_194 - 2 ) ;
V_87 [ 1 ] . V_109 = V_195 ;
V_87 [ 1 ] . V_110 = V_194 ;
F_27 ( V_84 , V_194 - 1 ) ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 2 , & V_78 , 0 ) ;
V_79 = (struct V_193 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 ) {
if ( V_5 ) {
F_50 ( V_5 , V_202 ) ;
V_5 -> V_59 = true ;
}
goto V_203;
}
if ( V_5 == NULL ) {
V_20 -> V_204 = V_79 -> V_2 . V_25 ;
goto V_205;
}
if ( V_79 -> V_206 & V_207 )
F_7 ( V_45 , L_29 ) ;
else if ( V_79 -> V_206 & V_208 ) {
V_5 -> V_209 = true ;
F_7 ( V_45 , L_30 ) ;
} else if ( V_79 -> V_206 & V_210 ) {
V_5 -> V_211 = true ;
F_7 ( V_45 , L_31 ) ;
} else {
F_7 ( V_117 , L_32 , V_79 -> V_206 ) ;
V_34 = - V_163 ;
goto V_203;
}
V_5 -> V_212 = F_31 ( V_79 -> V_213 ) ;
V_5 -> V_22 = V_79 -> V_104 ;
V_5 -> V_214 = F_31 ( V_79 -> V_215 ) ;
V_5 -> V_40 = V_181 ;
V_5 -> V_59 = false ;
V_5 -> V_26 = V_79 -> V_2 . V_25 ;
F_53 ( V_5 -> V_61 , V_190 , sizeof( V_5 -> V_61 ) ) ;
if ( ( V_79 -> V_104 & V_216 ) &&
( ( V_5 -> V_212 & V_217 ) == 0 ) )
F_7 ( V_117 , L_33 ) ;
F_51 ( V_5 ) ;
if ( V_5 -> V_20 -> V_21 -> V_175 -> V_218 )
V_34 = V_5 -> V_20 -> V_21 -> V_175 -> V_218 ( V_82 , V_5 ) ;
V_205:
F_22 ( V_78 , V_79 ) ;
F_39 ( V_195 ) ;
return V_34 ;
V_203:
if ( V_79 -> V_2 . V_168 == V_219 ) {
F_7 ( V_117 , L_34 , V_190 ) ;
V_5 -> V_196 = true ;
}
goto V_205;
}
int
F_54 ( const unsigned int V_82 , struct V_4 * V_5 )
{
struct V_220 * V_84 ;
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
V_34 = F_49 ( V_82 , V_20 , ( char * ) & V_84 -> V_2 , 0 ) ;
if ( V_34 )
F_50 ( V_5 , V_221 ) ;
return V_34 ;
}
static struct V_222 *
F_55 ( void )
{
struct V_222 * V_223 ;
V_223 = F_42 ( sizeof( struct V_222 ) , V_151 ) ;
if ( ! V_223 )
return NULL ;
V_223 -> V_224 . V_225 = F_4 ( F_44
( struct V_222 , V_226 ) ) ;
V_223 -> V_224 . V_227 = F_5 ( 16 ) ;
V_223 -> V_224 . V_228 = F_4 ( F_44
( struct V_222 , V_229 ) ) ;
V_223 -> V_224 . V_230 = F_4 ( 4 ) ;
V_223 -> V_229 [ 0 ] = 'D' ;
V_223 -> V_229 [ 1 ] = 'H' ;
V_223 -> V_229 [ 2 ] = 'n' ;
V_223 -> V_229 [ 3 ] = 'Q' ;
return V_223 ;
}
static struct V_222 *
F_56 ( struct V_231 * V_232 )
{
struct V_222 * V_223 ;
V_223 = F_42 ( sizeof( struct V_222 ) , V_151 ) ;
if ( ! V_223 )
return NULL ;
V_223 -> V_224 . V_225 = F_4 ( F_44
( struct V_222 , V_226 ) ) ;
V_223 -> V_224 . V_227 = F_5 ( 16 ) ;
V_223 -> V_224 . V_228 = F_4 ( F_44
( struct V_222 , V_229 ) ) ;
V_223 -> V_224 . V_230 = F_4 ( 4 ) ;
V_223 -> V_226 . V_233 . V_234 = V_232 -> V_235 ;
V_223 -> V_226 . V_233 . V_236 = V_232 -> V_237 ;
V_223 -> V_229 [ 0 ] = 'D' ;
V_223 -> V_229 [ 1 ] = 'H' ;
V_223 -> V_229 [ 2 ] = 'n' ;
V_223 -> V_229 [ 3 ] = 'C' ;
return V_223 ;
}
static T_7
F_57 ( struct V_38 * V_21 , struct V_238 * V_79 ,
unsigned int * V_239 )
{
char * V_240 ;
struct V_241 * V_242 ;
unsigned int V_243 = 0 ;
char * V_244 ;
V_240 = ( char * ) V_79 + 4 + F_31 ( V_79 -> V_245 ) ;
V_242 = (struct V_241 * ) V_240 ;
do {
V_242 = (struct V_241 * ) ( ( char * ) V_242 + V_243 ) ;
V_244 = F_2 ( V_242 -> V_228 ) + ( char * ) V_242 ;
if ( F_2 ( V_242 -> V_230 ) != 4 ||
strncmp ( V_244 , L_36 , 4 ) ) {
V_243 = F_31 ( V_242 -> V_246 ) ;
continue;
}
return V_21 -> V_175 -> V_247 ( V_242 , V_239 ) ;
} while ( V_243 != 0 );
return 0 ;
}
static int
F_58 ( struct V_38 * V_21 , struct V_86 * V_87 ,
unsigned int * V_248 , T_7 * V_249 )
{
struct V_250 * V_84 = V_87 [ 0 ] . V_109 ;
unsigned int V_251 = * V_248 ;
V_87 [ V_251 ] . V_109 = V_21 -> V_175 -> V_252 ( V_249 + 1 , * V_249 ) ;
if ( V_87 [ V_251 ] . V_109 == NULL )
return - V_72 ;
V_87 [ V_251 ] . V_110 = V_21 -> V_96 -> V_253 ;
V_84 -> V_254 = V_255 ;
if ( ! V_84 -> V_245 )
V_84 -> V_245 = F_5 (
sizeof( struct V_250 ) - 4 +
V_87 [ V_251 - 1 ] . V_110 ) ;
F_59 ( & V_84 -> V_256 ,
V_21 -> V_96 -> V_253 ) ;
F_27 ( & V_84 -> V_2 , V_21 -> V_96 -> V_253 ) ;
* V_248 = V_251 + 1 ;
return 0 ;
}
static int
F_60 ( struct V_86 * V_87 , unsigned int * V_248 ,
struct V_257 * V_258 )
{
struct V_250 * V_84 = V_87 [ 0 ] . V_109 ;
unsigned int V_251 = * V_248 ;
if ( V_258 -> V_259 ) {
V_87 [ V_251 ] . V_109 = F_56 ( V_258 -> V_232 ) ;
V_258 -> V_259 = false ;
} else
V_87 [ V_251 ] . V_109 = F_55 () ;
if ( V_87 [ V_251 ] . V_109 == NULL )
return - V_72 ;
V_87 [ V_251 ] . V_110 = sizeof( struct V_222 ) ;
if ( ! V_84 -> V_245 )
V_84 -> V_245 =
F_5 ( sizeof( struct V_250 ) - 4 +
V_87 [ 1 ] . V_110 ) ;
F_59 ( & V_84 -> V_256 , sizeof( struct V_222 ) ) ;
F_27 ( & V_84 -> V_2 , sizeof( struct V_222 ) ) ;
* V_248 = V_251 + 1 ;
return 0 ;
}
int
F_61 ( const unsigned int V_82 , struct V_257 * V_258 , T_1 * V_260 ,
T_7 * V_249 , struct V_261 * V_223 ,
struct V_262 * * V_263 )
{
struct V_250 * V_84 ;
struct V_238 * V_79 ;
struct V_38 * V_21 ;
struct V_4 * V_5 = V_258 -> V_5 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_86 V_87 [ 4 ] ;
int V_78 ;
int V_264 ;
T_1 * V_265 = NULL ;
int V_266 ;
int V_34 = 0 ;
unsigned int V_267 = 2 ;
T_8 V_268 = 0 ;
F_7 ( V_45 , L_37 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_43 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
if ( V_258 -> V_269 & V_270 )
V_268 |= V_271 ;
V_84 -> V_272 = V_273 ;
V_84 -> V_274 = F_5 ( V_258 -> V_275 ) ;
V_84 -> V_276 = F_5 ( V_268 ) ;
V_84 -> V_277 = V_278 ;
V_84 -> V_279 = F_5 ( V_258 -> V_280 ) ;
V_84 -> V_281 = F_5 ( V_258 -> V_269 & V_282 ) ;
V_264 = ( 2 * F_62 ( ( V_283 * ) V_260 , V_284 ) ) + 2 ;
V_84 -> V_228 = F_4 ( sizeof( struct V_250 ) - 4 ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_84 -> V_230 = F_4 ( V_264 - 2 ) ;
V_87 [ 0 ] . V_110 -- ;
if ( V_264 % 8 != 0 ) {
V_266 = V_264 / 8 * 8 ;
if ( V_266 < V_264 )
V_266 += 8 ;
V_265 = F_42 ( V_266 , V_151 ) ;
if ( ! V_265 )
return - V_72 ;
memcpy ( ( char * ) V_265 , ( const char * ) V_260 ,
V_264 ) ;
V_264 = V_266 ;
V_260 = V_265 ;
}
V_87 [ 1 ] . V_110 = V_264 ;
V_87 [ 1 ] . V_109 = V_260 ;
F_27 ( V_84 , V_264 - 1 ) ;
if ( ! V_21 -> V_285 )
* V_249 = V_286 ;
if ( ! ( V_21 -> V_22 & V_287 ) ||
* V_249 == V_286 )
V_84 -> V_254 = * V_249 ;
else {
V_34 = F_58 ( V_21 , V_87 , & V_267 , V_249 ) ;
if ( V_34 ) {
F_23 ( V_84 ) ;
F_39 ( V_265 ) ;
return V_34 ;
}
}
if ( * V_249 == V_288 ) {
if ( V_21 -> V_22 & V_287 ) {
struct V_241 * V_224 =
(struct V_241 * ) V_87 [ V_267 - 1 ] . V_109 ;
V_224 -> V_246 =
F_5 ( V_21 -> V_96 -> V_253 ) ;
}
V_34 = F_60 ( V_87 , & V_267 , V_258 ) ;
if ( V_34 ) {
F_23 ( V_84 ) ;
F_39 ( V_265 ) ;
F_39 ( V_87 [ V_267 - 1 ] . V_109 ) ;
return V_34 ;
}
}
V_34 = F_29 ( V_82 , V_20 , V_87 , V_267 , & V_78 , 0 ) ;
V_79 = (struct V_238 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 ) {
F_50 ( V_5 , V_289 ) ;
if ( V_263 )
* V_263 = F_63 ( V_79 , F_28 ( V_79 ) + 4 ,
V_151 ) ;
goto V_290;
}
V_258 -> V_232 -> V_235 = V_79 -> V_234 ;
V_258 -> V_232 -> V_237 = V_79 -> V_236 ;
if ( V_223 ) {
memcpy ( V_223 , & V_79 -> V_291 , 32 ) ;
V_223 -> V_292 = V_79 -> V_292 ;
V_223 -> V_293 = V_79 -> V_294 ;
V_223 -> V_295 = V_79 -> V_276 ;
V_223 -> V_296 = F_5 ( 1 ) ;
V_223 -> V_297 = 0 ;
}
if ( V_79 -> V_298 == V_255 )
* V_249 = F_57 ( V_21 , V_79 , & V_258 -> V_232 -> V_239 ) ;
else
* V_249 = V_79 -> V_298 ;
V_290:
F_39 ( V_265 ) ;
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
int
F_37 ( const unsigned int V_82 , struct V_4 * V_5 , T_9 V_235 ,
T_9 V_237 , T_4 V_299 , bool V_300 , char * V_301 ,
T_4 V_302 , char * * V_303 , T_4 * V_304 )
{
struct V_305 * V_84 ;
struct V_306 * V_79 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_86 V_87 [ 2 ] ;
int V_78 ;
int V_267 ;
int V_34 = 0 ;
F_7 ( V_45 , L_38 ) ;
* V_303 = NULL ;
if ( V_304 )
* V_304 = 0 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_66 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_307 = F_5 ( V_299 ) ;
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
if ( V_302 ) {
V_84 -> V_308 = F_5 ( V_302 ) ;
V_84 -> V_309 =
F_5 ( F_44 ( struct V_305 , V_170 ) - 4 ) ;
V_87 [ 1 ] . V_109 = V_301 ;
V_87 [ 1 ] . V_110 = V_302 ;
V_267 = 2 ;
} else
V_267 = 1 ;
V_84 -> V_310 = 0 ;
V_84 -> V_311 = 0 ;
V_84 -> V_312 = F_5 ( 0xFF00 ) ;
if ( V_300 )
V_84 -> V_30 = F_5 ( V_313 ) ;
else
V_84 -> V_30 = 0 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
if ( V_302 ) {
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
F_27 ( V_84 , V_302 - 1 ) ;
} else
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , V_267 , & V_78 , 0 ) ;
V_79 = (struct V_306 * ) V_87 [ 0 ] . V_109 ;
if ( ( V_34 != 0 ) && ( V_34 != - V_199 ) ) {
if ( V_5 )
F_50 ( V_5 , V_314 ) ;
goto V_315;
} else if ( V_34 == - V_199 ) {
if ( ( V_299 != V_316 ) &&
( V_299 != V_317 ) ) {
if ( V_5 )
F_50 ( V_5 , V_314 ) ;
goto V_315;
}
}
if ( ( V_304 == NULL ) || ( V_303 == NULL ) )
goto V_315;
* V_304 = F_31 ( V_79 -> V_311 ) ;
if ( * V_304 == 0 )
goto V_315;
else if ( * V_304 > 0xFF00 ) {
F_7 ( V_117 , L_39 , * V_304 ) ;
* V_304 = 0 ;
V_34 = - V_48 ;
goto V_315;
}
if ( F_28 ( V_79 ) < F_31 ( V_79 -> V_310 ) + * V_304 ) {
F_7 ( V_117 , L_40 , * V_304 ,
F_31 ( V_79 -> V_310 ) ) ;
* V_304 = 0 ;
V_34 = - V_48 ;
goto V_315;
}
* V_303 = F_40 ( * V_304 , V_151 ) ;
if ( * V_303 == NULL ) {
V_34 = - V_72 ;
goto V_315;
}
memcpy ( * V_303 , V_79 -> V_2 . V_12 + F_31 ( V_79 -> V_310 ) ,
* V_304 ) ;
V_315:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
int
F_64 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 )
{
int V_34 ;
char * V_318 = NULL ;
struct V_319 V_320 ;
char * V_321 = NULL ;
V_320 . V_322 =
F_65 ( V_323 ) ;
V_34 = F_37 ( V_82 , V_5 , V_235 , V_237 ,
V_324 , true ,
( char * ) & V_320 ,
2 , & V_321 , NULL ) ;
F_7 ( V_45 , L_41 , V_34 ) ;
F_39 ( V_318 ) ;
return V_34 ;
}
int
F_66 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 )
{
struct V_325 * V_84 ;
struct V_326 * V_79 ;
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
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , 0 ) ;
V_79 = (struct V_326 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 ) {
if ( V_5 )
F_50 ( V_5 , V_327 ) ;
goto V_328;
}
V_328:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
static int
F_67 ( unsigned int V_329 , unsigned int V_330 ,
struct V_1 * V_2 , unsigned int V_331 )
{
unsigned int V_332 = F_68 ( V_2 -> V_11 ) ;
char * V_333 = V_332 + 4 + ( char * ) V_2 ;
char * V_334 = 4 + V_329 + ( char * ) V_2 ;
char * V_335 = V_334 + V_330 ;
if ( V_330 < V_331 ) {
F_7 ( V_117 , L_43 ,
V_330 , V_331 ) ;
return - V_199 ;
}
if ( ( V_332 > 0x7FFFFF ) || ( V_330 > 0x7FFFFF ) ) {
F_7 ( V_117 , L_44 ,
V_330 , V_332 ) ;
return - V_199 ;
}
if ( ( V_334 > V_333 ) || ( V_335 > V_333 ) ) {
F_7 ( V_117 , L_45 ) ;
return - V_199 ;
}
return 0 ;
}
static int
F_69 ( unsigned int V_329 , unsigned int V_330 ,
struct V_1 * V_2 , unsigned int V_336 ,
char * V_337 )
{
char * V_334 = 4 + V_329 + ( char * ) V_2 ;
int V_34 ;
if ( ! V_337 )
return - V_199 ;
V_34 = F_67 ( V_329 , V_330 , V_2 , V_336 ) ;
if ( V_34 )
return V_34 ;
memcpy ( V_337 , V_334 , V_330 ) ;
return 0 ;
}
static int
F_70 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , T_10 V_338 ,
T_11 V_339 , T_11 V_340 , void * V_337 )
{
struct V_341 * V_84 ;
struct V_342 * V_79 = NULL ;
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
V_84 -> V_343 = V_344 ;
V_84 -> V_345 = V_338 ;
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
V_84 -> V_346 =
F_4 ( sizeof( struct V_341 ) - 1 - 4 ) ;
V_84 -> V_347 = F_5 ( V_339 ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , 0 ) ;
V_79 = (struct V_342 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 ) {
F_50 ( V_5 , V_348 ) ;
goto V_349;
}
V_34 = F_69 ( F_2 ( V_79 -> V_350 ) ,
F_31 ( V_79 -> V_347 ) ,
& V_79 -> V_2 , V_340 , V_337 ) ;
V_349:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
int
F_71 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 ,
struct V_261 * V_337 )
{
return F_70 ( V_82 , V_5 , V_235 , V_237 ,
V_351 ,
sizeof( struct V_261 ) + V_352 * 2 ,
sizeof( struct V_261 ) , V_337 ) ;
}
int
F_72 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , T_12 * V_353 )
{
return F_70 ( V_82 , V_5 , V_235 , V_237 ,
V_354 ,
sizeof( struct V_355 ) ,
sizeof( struct V_355 ) , V_353 ) ;
}
static void
F_73 ( struct V_356 * V_357 )
{
struct V_38 * V_21 = V_357 -> V_358 ;
struct V_359 * V_360 = (struct V_359 * ) V_357 -> V_361 ;
unsigned int V_362 = 1 ;
if ( V_357 -> V_363 == V_364 )
V_362 = F_2 ( V_360 -> V_2 . V_15 ) ;
F_74 ( V_357 ) ;
F_75 ( V_21 , V_362 , V_365 ) ;
}
int
F_76 ( struct V_38 * V_21 )
{
struct V_366 * V_84 ;
int V_34 = 0 ;
struct V_86 V_87 ;
struct V_367 V_368 = { . V_369 = & V_87 ,
. V_370 = 1 } ;
F_7 ( V_45 , L_47 ) ;
V_34 = F_18 ( V_371 , NULL , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_15 = F_4 ( 1 ) ;
V_87 . V_109 = ( char * ) V_84 ;
V_87 . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_77 ( V_21 , & V_368 , NULL , F_73 , V_21 ,
V_365 ) ;
if ( V_34 )
F_7 ( V_45 , L_48 , V_34 ) ;
F_23 ( V_84 ) ;
return V_34 ;
}
int
F_78 ( const unsigned int V_82 , struct V_4 * V_5 , T_9 V_235 ,
T_9 V_237 )
{
struct V_372 * V_84 ;
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
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , 0 ) ;
if ( ( V_34 != 0 ) && V_5 )
F_50 ( V_5 , V_373 ) ;
F_22 ( V_78 , V_87 [ 0 ] . V_109 ) ;
return V_34 ;
}
static int
F_79 ( struct V_86 * V_87 , struct V_374 * V_375 ,
unsigned int V_376 , int V_377 )
{
int V_34 = - V_378 ;
struct V_379 * V_84 = NULL ;
V_34 = F_18 ( V_64 , V_375 -> V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
if ( V_375 -> V_5 -> V_20 -> V_21 == NULL )
return - V_380 ;
V_84 -> V_2 . V_16 = F_5 ( V_375 -> V_381 ) ;
V_84 -> V_234 = V_375 -> V_235 ;
V_84 -> V_236 = V_375 -> V_237 ;
V_84 -> V_382 = 0 ;
V_84 -> V_383 = 0 ;
V_84 -> V_160 = 0 ;
V_84 -> V_384 = 0 ;
V_84 -> V_385 = F_5 ( V_375 -> V_386 ) ;
V_84 -> V_387 = F_80 ( V_375 -> V_329 ) ;
if ( V_377 & V_388 ) {
if ( ! ( V_377 & V_389 ) ) {
V_84 -> V_2 . V_390 =
F_5 ( F_28 ( V_84 ) + 4 ) ;
} else
V_84 -> V_2 . V_390 = 0 ;
if ( V_377 & V_391 ) {
V_84 -> V_2 . V_30 |= V_392 ;
V_84 -> V_2 . V_27 = 0xFFFFFFFF ;
V_84 -> V_2 . V_25 = 0xFFFFFFFF ;
V_84 -> V_234 = 0xFFFFFFFF ;
V_84 -> V_236 = 0xFFFFFFFF ;
}
}
if ( V_376 > V_375 -> V_386 )
V_84 -> V_393 = F_5 ( V_376 ) ;
else
V_84 -> V_393 = 0 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
return V_34 ;
}
static void
F_81 ( struct V_356 * V_357 )
{
struct V_394 * V_395 = V_357 -> V_358 ;
struct V_4 * V_5 = F_82 ( V_395 -> V_396 -> V_397 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_1 * V_223 = (struct V_1 * ) V_395 -> V_87 . V_109 ;
unsigned int V_362 = 1 ;
struct V_367 V_368 = { . V_369 = & V_395 -> V_87 ,
. V_370 = 1 ,
. V_398 = V_395 -> V_399 ,
. V_400 = V_395 -> V_401 ,
. V_402 = V_395 -> V_403 ,
. V_404 = V_395 -> V_405 } ;
F_7 ( V_45 , L_50 ,
V_93 , V_357 -> V_357 , V_357 -> V_363 , V_395 -> V_406 ,
V_395 -> V_407 ) ;
switch ( V_357 -> V_363 ) {
case V_364 :
V_362 = F_2 ( V_223 -> V_15 ) ;
if ( V_21 -> V_29 ) {
int V_34 ;
V_34 = F_83 ( & V_368 , V_21 ) ;
if ( V_34 )
F_7 ( V_117 , L_51 ,
V_34 ) ;
}
F_84 ( V_395 -> V_407 ) ;
F_85 ( V_5 , V_395 -> V_407 ) ;
break;
case V_408 :
case V_409 :
V_395 -> V_406 = - V_54 ;
break;
default:
if ( V_395 -> V_406 != - V_410 )
V_395 -> V_406 = - V_48 ;
}
if ( V_395 -> V_406 )
F_50 ( V_5 , V_411 ) ;
F_86 ( V_412 , & V_395 -> V_413 ) ;
F_74 ( V_357 ) ;
F_75 ( V_21 , V_362 , 0 ) ;
}
int
F_87 ( struct V_394 * V_395 )
{
int V_34 ;
struct V_1 * V_223 ;
struct V_374 V_375 ;
struct V_367 V_368 = { . V_369 = & V_395 -> V_87 ,
. V_370 = 1 } ;
F_7 ( V_45 , L_52 ,
V_93 , V_395 -> V_329 , V_395 -> V_407 ) ;
V_375 . V_5 = F_82 ( V_395 -> V_396 -> V_397 ) ;
V_375 . V_329 = V_395 -> V_329 ;
V_375 . V_386 = V_395 -> V_407 ;
V_375 . V_235 = V_395 -> V_396 -> V_232 . V_235 ;
V_375 . V_237 = V_395 -> V_396 -> V_232 . V_237 ;
V_375 . V_381 = V_395 -> V_381 ;
V_34 = F_79 ( & V_395 -> V_87 , & V_375 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_223 = (struct V_1 * ) V_395 -> V_87 . V_109 ;
V_395 -> V_87 . V_110 = F_28 ( V_395 -> V_87 . V_109 ) + 4 ;
F_88 ( & V_395 -> V_414 ) ;
V_34 = F_77 ( V_375 . V_5 -> V_20 -> V_21 , & V_368 ,
V_415 , F_81 ,
V_395 , 0 ) ;
if ( V_34 ) {
F_89 ( & V_395 -> V_414 , V_416 ) ;
F_50 ( V_375 . V_5 , V_411 ) ;
}
F_23 ( V_223 ) ;
return V_34 ;
}
int
F_90 ( const unsigned int V_82 , struct V_374 * V_375 ,
unsigned int * V_417 , char * * V_223 , int * V_418 )
{
int V_78 , V_34 = - V_378 ;
struct V_419 * V_79 = NULL ;
struct V_86 V_87 [ 1 ] ;
* V_417 = 0 ;
V_34 = F_79 ( V_87 , V_375 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_29 ( V_82 , V_375 -> V_5 -> V_20 , V_87 , 1 ,
& V_78 , V_166 ) ;
V_79 = (struct V_419 * ) V_87 [ 0 ] . V_109 ;
if ( V_79 -> V_2 . V_168 == V_420 ) {
F_22 ( V_78 , V_87 [ 0 ] . V_109 ) ;
return 0 ;
}
if ( V_34 ) {
F_50 ( V_375 -> V_5 , V_411 ) ;
F_7 ( V_117 , L_53 , V_34 ) ;
} else {
* V_417 = F_31 ( V_79 -> V_227 ) ;
if ( ( * V_417 > V_421 ) ||
( * V_417 > V_375 -> V_386 ) ) {
F_7 ( V_45 , L_54 ,
* V_417 , V_375 -> V_386 ) ;
V_34 = - V_48 ;
* V_417 = 0 ;
}
}
if ( * V_223 ) {
memcpy ( * V_223 , ( char * ) V_79 -> V_2 . V_12 + V_79 -> V_225 ,
* V_417 ) ;
F_22 ( V_78 , V_87 [ 0 ] . V_109 ) ;
} else if ( V_78 != V_167 ) {
* V_223 = V_87 [ 0 ] . V_109 ;
if ( V_78 == V_80 )
* V_418 = V_80 ;
else if ( V_78 == V_81 )
* V_418 = V_81 ;
}
return V_34 ;
}
static void
F_91 ( struct V_356 * V_357 )
{
struct V_422 * V_423 = V_357 -> V_358 ;
struct V_4 * V_5 = F_82 ( V_423 -> V_396 -> V_397 ) ;
unsigned int V_424 ;
struct V_425 * V_79 = (struct V_425 * ) V_357 -> V_361 ;
unsigned int V_362 = 1 ;
switch ( V_357 -> V_363 ) {
case V_364 :
V_362 = F_2 ( V_79 -> V_2 . V_15 ) ;
V_423 -> V_406 = F_92 ( V_357 , V_5 -> V_20 -> V_21 , 0 ) ;
if ( V_423 -> V_406 != 0 )
break;
V_424 = F_31 ( V_79 -> V_227 ) ;
if ( V_424 > V_423 -> V_407 )
V_424 &= 0xFFFF ;
if ( V_424 < V_423 -> V_407 )
V_423 -> V_406 = - V_426 ;
else
V_423 -> V_407 = V_424 ;
break;
case V_408 :
case V_409 :
V_423 -> V_406 = - V_54 ;
break;
default:
V_423 -> V_406 = - V_48 ;
break;
}
if ( V_423 -> V_406 )
F_50 ( V_5 , V_427 ) ;
F_86 ( V_412 , & V_423 -> V_413 ) ;
F_74 ( V_357 ) ;
F_75 ( V_5 -> V_20 -> V_21 , V_362 , 0 ) ;
}
int
F_93 ( struct V_422 * V_423 ,
void (* F_94)( struct V_428 * V_428 ) )
{
int V_34 = - V_378 ;
struct V_429 * V_84 = NULL ;
struct V_4 * V_5 = F_82 ( V_423 -> V_396 -> V_397 ) ;
struct V_86 V_87 ;
struct V_367 V_368 ;
V_34 = F_18 ( V_42 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
goto V_430;
V_84 -> V_2 . V_16 = F_5 ( V_423 -> V_396 -> V_381 ) ;
V_84 -> V_234 = V_423 -> V_396 -> V_232 . V_235 ;
V_84 -> V_236 = V_423 -> V_396 -> V_232 . V_237 ;
V_84 -> V_431 = 0 ;
V_84 -> V_432 = 0 ;
V_84 -> V_160 = 0 ;
V_84 -> V_387 = F_80 ( V_423 -> V_329 ) ;
V_84 -> V_225 = F_4 (
F_44 ( struct V_429 , V_170 ) - 4 ) ;
V_84 -> V_393 = 0 ;
V_87 . V_110 = F_28 ( V_84 ) + 4 - 1 ;
V_87 . V_109 = V_84 ;
V_368 . V_369 = & V_87 ;
V_368 . V_370 = 1 ;
V_368 . V_398 = V_423 -> V_399 ;
V_368 . V_400 = V_423 -> V_401 ;
V_368 . V_402 = V_423 -> V_403 ;
V_368 . V_404 = V_423 -> V_405 ;
F_7 ( V_45 , L_55 ,
V_423 -> V_329 , V_423 -> V_407 ) ;
V_84 -> V_385 = F_5 ( V_423 -> V_407 ) ;
F_27 ( & V_84 -> V_2 , V_423 -> V_407 - 1 ) ;
F_88 ( & V_423 -> V_414 ) ;
V_34 = F_77 ( V_5 -> V_20 -> V_21 , & V_368 , NULL ,
F_91 , V_423 , 0 ) ;
if ( V_34 ) {
F_89 ( & V_423 -> V_414 , F_94 ) ;
F_50 ( V_5 , V_427 ) ;
}
V_430:
F_23 ( V_84 ) ;
return V_34 ;
}
int
F_95 ( const unsigned int V_82 , struct V_374 * V_375 ,
unsigned int * V_417 , struct V_86 * V_87 , int V_433 )
{
int V_34 = 0 ;
struct V_429 * V_84 = NULL ;
struct V_425 * V_79 = NULL ;
int V_78 ;
* V_417 = 0 ;
if ( V_433 < 1 )
return V_34 ;
V_34 = F_18 ( V_42 , V_375 -> V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
if ( V_375 -> V_5 -> V_20 -> V_21 == NULL )
return - V_380 ;
V_84 -> V_2 . V_16 = F_5 ( V_375 -> V_381 ) ;
V_84 -> V_234 = V_375 -> V_235 ;
V_84 -> V_236 = V_375 -> V_237 ;
V_84 -> V_431 = 0 ;
V_84 -> V_432 = 0 ;
V_84 -> V_160 = 0 ;
V_84 -> V_385 = F_5 ( V_375 -> V_386 ) ;
V_84 -> V_387 = F_80 ( V_375 -> V_329 ) ;
V_84 -> V_225 = F_4 (
F_44 ( struct V_429 , V_170 ) - 4 ) ;
V_84 -> V_393 = 0 ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
F_27 ( V_84 , V_375 -> V_386 - 1 ) ;
V_34 = F_29 ( V_82 , V_375 -> V_5 -> V_20 , V_87 , V_433 + 1 ,
& V_78 , 0 ) ;
V_79 = (struct V_425 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 ) {
F_50 ( V_375 -> V_5 , V_427 ) ;
F_7 ( V_117 , L_56 , V_34 ) ;
} else
* V_417 = F_31 ( V_79 -> V_227 ) ;
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
static unsigned int
F_96 ( char * V_434 , char * V_335 , char * * V_435 , T_11 V_436 )
{
int V_437 ;
unsigned int V_438 = 0 ;
unsigned int V_439 = 0 ;
T_13 * V_440 ;
if ( V_434 == NULL )
return 0 ;
V_440 = ( T_13 * ) V_434 ;
while ( 1 ) {
V_440 = ( T_13 * )
( ( char * ) V_440 + V_439 ) ;
if ( ( char * ) V_440 + V_436 > V_335 ) {
F_7 ( V_117 , L_57 ) ;
break;
}
V_437 = F_31 ( V_440 -> V_441 ) ;
if ( ( char * ) V_440 + V_437 + V_436 > V_335 ) {
F_7 ( V_117 , L_58 ,
V_335 ) ;
break;
}
* V_435 = ( char * ) V_440 ;
V_438 ++ ;
V_439 = F_31 ( V_440 -> V_442 ) ;
if ( ! V_439 )
break;
}
return V_438 ;
}
int
F_97 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , int V_443 ,
struct V_444 * V_445 )
{
struct V_446 * V_84 ;
struct V_447 * V_79 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_34 = 0 ;
int V_437 ;
int V_78 ;
unsigned char * V_448 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
T_1 V_449 = F_4 ( '*' ) ;
char * V_333 ;
unsigned int V_450 = V_451 ;
T_11 V_452 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_67 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
switch ( V_445 -> V_453 ) {
case V_454 :
V_84 -> V_455 = V_456 ;
V_452 = sizeof( T_13 ) - 1 ;
break;
case V_457 :
V_84 -> V_455 = V_458 ;
V_452 = sizeof( V_459 ) - 1 ;
break;
default:
F_7 ( V_117 , L_59 ,
V_445 -> V_453 ) ;
V_34 = - V_199 ;
goto V_460;
}
V_84 -> V_461 = F_5 ( V_443 ) ;
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
V_437 = 0x2 ;
V_448 = V_84 -> V_170 ;
memcpy ( V_448 , & V_449 , V_437 ) ;
V_84 -> V_462 =
F_4 ( sizeof( struct V_446 ) - 1 - 4 ) ;
V_84 -> V_441 = F_4 ( V_437 ) ;
V_450 = F_30 (unsigned int, output_size, server->maxBuf) ;
V_450 = F_30 (unsigned int, output_size, 2 << 15 ) ;
V_84 -> V_347 = F_5 ( V_450 ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - 1 ;
V_87 [ 1 ] . V_109 = ( char * ) ( V_84 -> V_170 ) ;
V_87 [ 1 ] . V_110 = V_437 ;
F_27 ( V_84 , V_437 - 1 ) ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 2 , & V_78 , 0 ) ;
V_79 = (struct V_447 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 ) {
F_50 ( V_5 , V_463 ) ;
goto V_460;
}
V_34 = F_67 ( F_2 ( V_79 -> V_350 ) ,
F_31 ( V_79 -> V_347 ) , & V_79 -> V_2 ,
V_452 ) ;
if ( V_34 )
goto V_460;
V_445 -> V_464 = true ;
if ( V_445 -> V_465 ) {
if ( V_445 -> V_466 )
F_23 ( V_445 -> V_465 ) ;
else
F_24 ( V_445 -> V_465 ) ;
}
V_445 -> V_465 = ( char * ) V_79 ;
V_445 -> V_467 = V_445 -> V_468 = 4 +
( char * ) & V_79 -> V_2 + F_2 ( V_79 -> V_350 ) ;
V_333 = F_28 ( V_79 ) + 4 + ( char * ) & V_79 -> V_2 ;
V_445 -> V_469 =
F_96 ( V_445 -> V_467 , V_333 ,
& V_445 -> V_468 , V_452 ) ;
V_445 -> V_470 += V_445 -> V_469 ;
F_7 ( V_45 , L_60 ,
V_445 -> V_469 , V_445 -> V_470 ,
V_445 -> V_467 , V_445 -> V_468 ) ;
if ( V_78 == V_81 )
V_445 -> V_466 = false ;
else if ( V_78 == V_80 )
V_445 -> V_466 = true ;
else
F_7 ( V_117 , L_61 ) ;
if ( V_79 -> V_2 . V_168 == V_471 )
V_445 -> V_472 = 1 ;
else
V_445 -> V_472 = 0 ;
return V_34 ;
V_460:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
static int
F_98 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , T_4 V_381 , int V_338 ,
unsigned int V_251 , void * * V_337 , unsigned int * V_436 )
{
struct V_473 * V_84 ;
struct V_474 * V_79 = NULL ;
struct V_86 * V_87 ;
int V_34 = 0 ;
int V_78 ;
unsigned int V_475 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( ! V_251 )
return - V_199 ;
V_87 = F_40 ( sizeof( struct V_86 ) * V_251 , V_151 ) ;
if ( ! V_87 )
return - V_72 ;
V_34 = F_18 ( V_70 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 ) {
F_39 ( V_87 ) ;
return V_34 ;
}
V_84 -> V_2 . V_16 = F_5 ( V_381 ) ;
V_84 -> V_343 = V_344 ;
V_84 -> V_345 = V_338 ;
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
V_84 -> V_476 =
F_4 ( sizeof( struct V_473 ) - 1 - 4 ) ;
V_84 -> V_477 = F_5 ( * V_436 ) ;
F_27 ( V_84 , * V_436 - 1 ) ;
memcpy ( V_84 -> V_170 , * V_337 , * V_436 ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 ;
for ( V_475 = 1 ; V_475 < V_251 ; V_475 ++ ) {
F_27 ( V_84 , V_436 [ V_475 ] ) ;
F_59 ( & V_84 -> V_477 , V_436 [ V_475 ] ) ;
V_87 [ V_475 ] . V_109 = ( char * ) V_337 [ V_475 ] ;
V_87 [ V_475 ] . V_110 = V_436 [ V_475 ] ;
}
V_34 = F_29 ( V_82 , V_20 , V_87 , V_251 , & V_78 , 0 ) ;
V_79 = (struct V_474 * ) V_87 [ 0 ] . V_109 ;
if ( V_34 != 0 )
F_50 ( V_5 , V_478 ) ;
F_22 ( V_78 , V_79 ) ;
F_39 ( V_87 ) ;
return V_34 ;
}
int
F_99 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , T_1 * V_479 )
{
struct V_480 V_481 ;
void * * V_337 ;
unsigned int V_436 [ 2 ] ;
int V_34 ;
int V_437 = ( 2 * F_62 ( ( V_283 * ) V_479 , V_284 ) ) ;
V_337 = F_40 ( sizeof( void * ) * 2 , V_151 ) ;
if ( ! V_337 )
return - V_72 ;
V_481 . V_482 = 1 ;
V_481 . V_483 = 0 ;
V_481 . V_441 = F_5 ( V_437 ) ;
V_337 [ 0 ] = & V_481 ;
V_436 [ 0 ] = sizeof( struct V_480 ) ;
V_337 [ 1 ] = V_479 ;
V_436 [ 1 ] = V_437 + 2 ;
V_34 = F_98 ( V_82 , V_5 , V_235 , V_237 ,
V_17 -> V_18 , V_484 , 2 , V_337 ,
V_436 ) ;
F_39 ( V_337 ) ;
return V_34 ;
}
int
F_100 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , T_1 * V_479 )
{
struct V_485 V_481 ;
void * * V_337 ;
unsigned int V_436 [ 2 ] ;
int V_34 ;
int V_437 = ( 2 * F_62 ( ( V_283 * ) V_479 , V_284 ) ) ;
V_337 = F_40 ( sizeof( void * ) * 2 , V_151 ) ;
if ( ! V_337 )
return - V_72 ;
V_481 . V_482 = 0 ;
V_481 . V_483 = 0 ;
V_481 . V_441 = F_5 ( V_437 ) ;
V_337 [ 0 ] = & V_481 ;
V_436 [ 0 ] = sizeof( struct V_485 ) ;
V_337 [ 1 ] = V_479 ;
V_436 [ 1 ] = V_437 + 2 ;
V_34 = F_98 ( V_82 , V_5 , V_235 , V_237 ,
V_17 -> V_18 , V_486 , 2 , V_337 , V_436 ) ;
F_39 ( V_337 ) ;
return V_34 ;
}
int
F_101 ( const unsigned int V_82 , struct V_4 * V_5 , T_9 V_235 ,
T_9 V_237 , T_4 V_381 , T_12 * V_487 )
{
struct V_488 V_481 ;
void * V_337 ;
unsigned int V_436 ;
V_481 . V_293 = * V_487 ;
V_337 = & V_481 ;
V_436 = sizeof( struct V_488 ) ;
return F_98 ( V_82 , V_5 , V_235 , V_237 , V_381 ,
V_489 , 1 , & V_337 , & V_436 ) ;
}
int
F_102 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , T_14 * V_223 )
{
unsigned int V_436 ;
V_436 = sizeof( T_14 ) ;
return F_98 ( V_82 , V_5 , V_235 , V_237 ,
V_17 -> V_18 , V_490 , 1 ,
( void * * ) & V_223 , & V_436 ) ;
}
int
F_103 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_9 V_235 , const T_9 V_237 ,
T_7 V_491 )
{
int V_34 ;
struct V_492 * V_84 = NULL ;
F_7 ( V_45 , L_62 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_493 = V_237 ;
V_84 -> V_494 = V_235 ;
V_84 -> V_298 = V_491 ;
V_84 -> V_2 . V_15 = F_4 ( 1 ) ;
V_34 = F_49 ( V_82 , V_5 -> V_20 , ( char * ) V_84 , V_495 ) ;
if ( V_34 ) {
F_50 ( V_5 , V_496 ) ;
F_7 ( V_45 , L_63 , V_34 ) ;
}
return V_34 ;
}
static void
F_104 ( struct V_497 * V_498 ,
struct V_499 * V_500 )
{
V_500 -> V_501 = F_31 ( V_498 -> V_502 ) *
F_31 ( V_498 -> V_503 ) ;
V_500 -> V_504 = F_105 ( V_498 -> V_505 ) ;
V_500 -> V_506 = F_105 ( V_498 -> V_507 ) ;
V_500 -> V_508 = F_105 ( V_498 -> V_509 ) ;
return;
}
static int
F_106 ( struct V_86 * V_87 , struct V_4 * V_5 , int V_510 ,
int V_511 , T_9 V_235 , T_9 V_237 )
{
int V_34 ;
struct V_341 * V_84 ;
F_7 ( V_45 , L_64 , V_510 ) ;
if ( ( V_5 -> V_20 == NULL ) || ( V_5 -> V_20 -> V_21 == NULL ) )
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_343 = V_512 ;
V_84 -> V_345 = V_510 ;
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
V_84 -> V_346 =
F_4 ( sizeof( struct V_341 ) - 1 - 4 ) ;
V_84 -> V_347 = F_5 (
V_511 + sizeof( struct V_342 ) - 1 - 4 ) ;
V_87 -> V_109 = ( char * ) V_84 ;
V_87 -> V_110 = F_28 ( V_84 ) + 4 ;
return 0 ;
}
int
F_107 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , struct V_499 * V_513 )
{
struct V_342 * V_79 = NULL ;
struct V_86 V_87 ;
int V_34 = 0 ;
int V_78 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_497 * V_481 = NULL ;
V_34 = F_106 ( & V_87 , V_5 , V_514 ,
sizeof( struct V_497 ) ,
V_235 , V_237 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_29 ( V_82 , V_20 , & V_87 , 1 , & V_78 , 0 ) ;
if ( V_34 ) {
F_50 ( V_5 , V_348 ) ;
goto V_515;
}
V_79 = (struct V_342 * ) V_87 . V_109 ;
V_481 = (struct V_497 * ) ( 4 +
F_2 ( V_79 -> V_350 ) + ( char * ) & V_79 -> V_2 ) ;
V_34 = F_67 ( F_2 ( V_79 -> V_350 ) ,
F_31 ( V_79 -> V_347 ) , & V_79 -> V_2 ,
sizeof( struct V_497 ) ) ;
if ( ! V_34 )
F_104 ( V_481 , V_513 ) ;
V_515:
F_22 ( V_78 , V_87 . V_109 ) ;
return V_34 ;
}
int
F_108 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , int V_510 )
{
struct V_342 * V_79 = NULL ;
struct V_86 V_87 ;
int V_34 = 0 ;
int V_78 , V_516 , V_340 ;
struct V_37 * V_20 = V_5 -> V_20 ;
unsigned int V_517 , V_329 ;
if ( V_510 == V_518 ) {
V_516 = sizeof( V_519 ) ;
V_340 = sizeof( V_519 ) ;
} else if ( V_510 == V_520 ) {
V_516 = sizeof( V_521 ) ;
V_340 = V_522 ;
} else if ( V_510 == V_523 ) {
V_516 = sizeof( struct V_524 ) ;
V_340 = sizeof( struct V_524 ) ;
} else {
F_7 ( V_45 , L_65 , V_510 ) ;
return - V_199 ;
}
V_34 = F_106 ( & V_87 , V_5 , V_510 , V_516 ,
V_235 , V_237 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_29 ( V_82 , V_20 , & V_87 , 1 , & V_78 , 0 ) ;
if ( V_34 ) {
F_50 ( V_5 , V_348 ) ;
goto V_525;
}
V_79 = (struct V_342 * ) V_87 . V_109 ;
V_517 = F_31 ( V_79 -> V_347 ) ;
V_329 = F_2 ( V_79 -> V_350 ) ;
V_34 = F_67 ( V_329 , V_517 , & V_79 -> V_2 , V_340 ) ;
if ( V_34 )
goto V_525;
if ( V_510 == V_520 )
memcpy ( & V_5 -> V_526 , 4 + V_329
+ ( char * ) & V_79 -> V_2 , F_30 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_510 == V_518 )
memcpy ( & V_5 -> V_527 , 4 + V_329
+ ( char * ) & V_79 -> V_2 , sizeof( V_519 ) ) ;
else if ( V_510 == V_523 ) {
struct V_524 * V_528 = (struct V_524 * )
( 4 + V_329 + ( char * ) & V_79 -> V_2 ) ;
V_5 -> V_529 = F_31 ( V_528 -> V_30 ) ;
V_5 -> V_530 =
F_31 ( V_528 -> V_531 ) ;
}
V_525:
F_22 ( V_78 , V_87 . V_109 ) ;
return V_34 ;
}
int
F_109 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_15 V_532 , const T_15 V_237 , const T_8 V_381 ,
const T_8 V_533 , struct V_534 * V_223 )
{
int V_34 = 0 ;
struct V_535 * V_84 = NULL ;
struct V_86 V_87 [ 2 ] ;
int V_536 ;
unsigned int V_537 ;
F_7 ( V_45 , L_66 , V_533 ) ;
V_34 = F_18 ( V_65 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_16 = F_5 ( V_381 ) ;
V_84 -> V_538 = F_4 ( V_533 ) ;
V_84 -> V_234 = V_532 ;
V_84 -> V_236 = V_237 ;
V_537 = V_533 * sizeof( struct V_534 ) ;
F_27 ( V_84 , V_537 - sizeof( struct V_534 ) ) ;
V_87 [ 0 ] . V_109 = ( char * ) V_84 ;
V_87 [ 0 ] . V_110 = F_28 ( V_84 ) + 4 - V_537 ;
V_87 [ 1 ] . V_109 = ( char * ) V_223 ;
V_87 [ 1 ] . V_110 = V_537 ;
F_21 ( & V_5 -> V_74 . V_539 . V_540 ) ;
V_34 = F_29 ( V_82 , V_5 -> V_20 , V_87 , 2 , & V_536 , V_541 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_67 , V_34 ) ;
F_50 ( V_5 , V_542 ) ;
}
return V_34 ;
}
int
F_110 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_15 V_532 , const T_15 V_237 , const T_8 V_381 ,
const T_15 V_386 , const T_15 V_329 , const T_8 V_543 ,
const bool V_544 )
{
struct V_534 V_545 ;
V_545 . V_387 = F_80 ( V_329 ) ;
V_545 . V_385 = F_80 ( V_386 ) ;
V_545 . V_30 = F_5 ( V_543 ) ;
if ( ! V_544 && V_543 != V_546 )
V_545 . V_30 |= F_5 ( V_547 ) ;
return F_109 ( V_82 , V_5 , V_532 , V_237 , V_381 , 1 , & V_545 ) ;
}
int
F_111 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_7 * V_548 , const T_5 V_549 )
{
int V_34 ;
struct V_550 * V_84 = NULL ;
F_7 ( V_45 , L_68 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_2 . V_15 = F_4 ( 1 ) ;
V_84 -> V_13 = F_4 ( 36 ) ;
F_27 ( V_84 , 12 ) ;
memcpy ( V_84 -> V_551 , V_548 , 16 ) ;
V_84 -> V_552 = V_549 ;
V_34 = F_49 ( V_82 , V_5 -> V_20 , ( char * ) V_84 , V_495 ) ;
if ( V_34 ) {
F_50 ( V_5 , V_496 ) ;
F_7 ( V_45 , L_69 , V_34 ) ;
}
return V_34 ;
}
