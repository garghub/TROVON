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
if ( V_20 -> V_21 -> V_96 -> V_97 == V_106 )
memset ( V_84 -> V_107 , 0 , V_108 ) ;
else
memcpy ( V_84 -> V_107 , V_21 -> V_109 ,
V_108 ) ;
V_87 [ 0 ] . V_110 = ( char * ) V_84 ;
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , V_91 ) ;
V_79 = (struct V_85 * ) V_87 [ 0 ] . V_110 ;
if ( V_34 != 0 )
goto V_112;
F_7 ( V_45 , L_6 , V_79 -> V_99 ) ;
if ( V_79 -> V_113 == F_4 ( V_106 ) )
F_7 ( V_45 , L_7 ) ;
else if ( V_79 -> V_113 == F_4 ( V_114 ) )
F_7 ( V_45 , L_8 ) ;
else if ( V_79 -> V_113 == F_4 ( V_115 ) )
F_7 ( V_45 , L_9 ) ;
else if ( V_79 -> V_113 == F_4 ( V_116 ) )
F_7 ( V_45 , L_10 ) ;
else {
F_7 ( V_117 , L_11 ,
F_2 ( V_79 -> V_113 ) ) ;
V_34 = - V_48 ;
goto V_112;
}
V_21 -> V_118 = F_2 ( V_79 -> V_113 ) ;
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
goto V_112;
if ( V_89 )
V_34 = F_35 ( V_90 , V_89 ,
& V_21 -> V_129 ) ;
if ( V_34 == 1 )
V_34 = 0 ;
else if ( V_34 == 0 ) {
V_34 = - V_48 ;
goto V_112;
}
#endif
V_112:
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
memcpy ( V_131 . V_135 , V_5 -> V_20 -> V_21 -> V_109 ,
V_108 ) ;
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
V_87 [ 0 ] . V_110 = ( char * ) V_84 ;
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 - 1 ;
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
V_87 [ 1 ] . V_110 = V_90 ;
V_87 [ 1 ] . V_111 = V_89 ;
F_27 ( V_84 , V_89 - 1 ) ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 2 , & V_78 ,
V_166 | V_92 ) ;
F_39 ( V_90 ) ;
V_79 = (struct V_142 * ) V_87 [ 0 ] . V_110 ;
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
V_87 [ 0 ] . V_110 = ( char * ) V_84 ;
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 - 1 ;
V_84 -> V_200 = F_4 ( sizeof( struct V_192 )
- 1 - 4 ) ;
V_84 -> V_201 = F_4 ( V_194 - 2 ) ;
V_87 [ 1 ] . V_110 = V_195 ;
V_87 [ 1 ] . V_111 = V_194 ;
F_27 ( V_84 , V_194 - 1 ) ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 2 , & V_78 , 0 ) ;
V_79 = (struct V_193 * ) V_87 [ 0 ] . V_110 ;
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
struct V_250 * V_84 = V_87 [ 0 ] . V_110 ;
unsigned int V_251 = * V_248 ;
V_87 [ V_251 ] . V_110 = V_21 -> V_175 -> V_252 ( V_249 + 1 , * V_249 ) ;
if ( V_87 [ V_251 ] . V_110 == NULL )
return - V_72 ;
V_87 [ V_251 ] . V_111 = V_21 -> V_96 -> V_253 ;
V_84 -> V_254 = V_255 ;
if ( ! V_84 -> V_245 )
V_84 -> V_245 = F_5 (
sizeof( struct V_250 ) - 4 +
V_87 [ V_251 - 1 ] . V_111 ) ;
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
struct V_250 * V_84 = V_87 [ 0 ] . V_110 ;
unsigned int V_251 = * V_248 ;
if ( V_258 -> V_259 ) {
V_87 [ V_251 ] . V_110 = F_56 ( V_258 -> V_232 ) ;
V_258 -> V_259 = false ;
} else
V_87 [ V_251 ] . V_110 = F_55 () ;
if ( V_87 [ V_251 ] . V_110 == NULL )
return - V_72 ;
V_87 [ V_251 ] . V_111 = sizeof( struct V_222 ) ;
if ( ! V_84 -> V_245 )
V_84 -> V_245 =
F_5 ( sizeof( struct V_250 ) - 4 +
V_87 [ 1 ] . V_111 ) ;
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
char * V_269 = NULL , * V_270 = NULL ;
F_7 ( V_45 , L_37 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_43 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
if ( V_258 -> V_271 & V_272 )
V_268 |= V_273 ;
V_84 -> V_274 = V_275 ;
V_84 -> V_276 = F_5 ( V_258 -> V_277 ) ;
V_84 -> V_278 = F_5 ( V_268 ) ;
V_84 -> V_279 = V_280 ;
V_84 -> V_281 = F_5 ( V_258 -> V_282 ) ;
V_84 -> V_283 = F_5 ( V_258 -> V_271 & V_284 ) ;
V_264 = ( 2 * F_62 ( ( V_285 * ) V_260 , V_286 ) ) + 2 ;
V_84 -> V_228 = F_4 ( sizeof( struct V_250 ) - 4 ) ;
V_87 [ 0 ] . V_110 = ( char * ) V_84 ;
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 ;
V_84 -> V_230 = F_4 ( V_264 - 2 ) ;
V_87 [ 0 ] . V_111 -- ;
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
V_87 [ 1 ] . V_111 = V_264 ;
V_87 [ 1 ] . V_110 = V_260 ;
F_27 ( V_84 , V_264 - 1 ) ;
if ( ! V_21 -> V_287 )
* V_249 = V_288 ;
if ( ! ( V_21 -> V_22 & V_289 ) ||
* V_249 == V_288 )
V_84 -> V_254 = * V_249 ;
else {
V_34 = F_58 ( V_21 , V_87 , & V_267 , V_249 ) ;
if ( V_34 ) {
F_23 ( V_84 ) ;
F_39 ( V_265 ) ;
return V_34 ;
}
V_270 = V_87 [ V_267 - 1 ] . V_110 ;
}
if ( * V_249 == V_290 ) {
if ( V_21 -> V_22 & V_289 ) {
struct V_241 * V_224 =
(struct V_241 * ) V_87 [ V_267 - 1 ] . V_110 ;
V_224 -> V_246 =
F_5 ( V_21 -> V_96 -> V_253 ) ;
}
V_34 = F_60 ( V_87 , & V_267 , V_258 ) ;
if ( V_34 ) {
F_23 ( V_84 ) ;
F_39 ( V_265 ) ;
F_39 ( V_270 ) ;
return V_34 ;
}
V_269 = V_87 [ V_267 - 1 ] . V_110 ;
}
V_34 = F_29 ( V_82 , V_20 , V_87 , V_267 , & V_78 , 0 ) ;
V_79 = (struct V_238 * ) V_87 [ 0 ] . V_110 ;
if ( V_34 != 0 ) {
F_50 ( V_5 , V_291 ) ;
if ( V_263 )
* V_263 = F_63 ( V_79 , F_28 ( V_79 ) + 4 ,
V_151 ) ;
goto V_292;
}
V_258 -> V_232 -> V_235 = V_79 -> V_234 ;
V_258 -> V_232 -> V_237 = V_79 -> V_236 ;
if ( V_223 ) {
memcpy ( V_223 , & V_79 -> V_293 , 32 ) ;
V_223 -> V_294 = V_79 -> V_294 ;
V_223 -> V_295 = V_79 -> V_296 ;
V_223 -> V_297 = V_79 -> V_278 ;
V_223 -> V_298 = F_5 ( 1 ) ;
V_223 -> V_299 = 0 ;
}
if ( V_79 -> V_300 == V_255 )
* V_249 = F_57 ( V_21 , V_79 , & V_258 -> V_232 -> V_239 ) ;
else
* V_249 = V_79 -> V_300 ;
V_292:
F_39 ( V_265 ) ;
F_39 ( V_270 ) ;
F_39 ( V_269 ) ;
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
int
F_37 ( const unsigned int V_82 , struct V_4 * V_5 , T_9 V_235 ,
T_9 V_237 , T_4 V_301 , bool V_302 , char * V_303 ,
T_4 V_304 , char * * V_305 , T_4 * V_306 )
{
struct V_307 * V_84 ;
struct V_308 * V_79 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_86 V_87 [ 2 ] ;
int V_78 ;
int V_267 ;
int V_34 = 0 ;
F_7 ( V_45 , L_38 ) ;
* V_305 = NULL ;
if ( V_306 )
* V_306 = 0 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_66 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_309 = F_5 ( V_301 ) ;
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
if ( V_304 ) {
V_84 -> V_310 = F_5 ( V_304 ) ;
V_84 -> V_311 =
F_5 ( F_44 ( struct V_307 , V_170 ) - 4 ) ;
V_87 [ 1 ] . V_110 = V_303 ;
V_87 [ 1 ] . V_111 = V_304 ;
V_267 = 2 ;
} else
V_267 = 1 ;
V_84 -> V_312 = 0 ;
V_84 -> V_313 = 0 ;
V_84 -> V_314 = F_5 ( 0xFF00 ) ;
if ( V_302 )
V_84 -> V_30 = F_5 ( V_315 ) ;
else
V_84 -> V_30 = 0 ;
V_87 [ 0 ] . V_110 = ( char * ) V_84 ;
if ( V_304 ) {
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 - 1 ;
F_27 ( V_84 , V_304 - 1 ) ;
} else
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , V_267 , & V_78 , 0 ) ;
V_79 = (struct V_308 * ) V_87 [ 0 ] . V_110 ;
if ( ( V_34 != 0 ) && ( V_34 != - V_199 ) ) {
if ( V_5 )
F_50 ( V_5 , V_316 ) ;
goto V_317;
} else if ( V_34 == - V_199 ) {
if ( ( V_301 != V_318 ) &&
( V_301 != V_319 ) ) {
if ( V_5 )
F_50 ( V_5 , V_316 ) ;
goto V_317;
}
}
if ( ( V_306 == NULL ) || ( V_305 == NULL ) )
goto V_317;
* V_306 = F_31 ( V_79 -> V_313 ) ;
if ( * V_306 == 0 )
goto V_317;
else if ( * V_306 > 0xFF00 ) {
F_7 ( V_117 , L_39 , * V_306 ) ;
* V_306 = 0 ;
V_34 = - V_48 ;
goto V_317;
}
if ( F_28 ( V_79 ) < F_31 ( V_79 -> V_312 ) + * V_306 ) {
F_7 ( V_117 , L_40 , * V_306 ,
F_31 ( V_79 -> V_312 ) ) ;
* V_306 = 0 ;
V_34 = - V_48 ;
goto V_317;
}
* V_305 = F_40 ( * V_306 , V_151 ) ;
if ( * V_305 == NULL ) {
V_34 = - V_72 ;
goto V_317;
}
memcpy ( * V_305 , V_79 -> V_2 . V_12 + F_31 ( V_79 -> V_312 ) ,
* V_306 ) ;
V_317:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
int
F_64 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 )
{
int V_34 ;
struct V_320 V_321 ;
char * V_322 = NULL ;
V_321 . V_323 =
F_65 ( V_324 ) ;
V_34 = F_37 ( V_82 , V_5 , V_235 , V_237 ,
V_325 , true ,
( char * ) & V_321 ,
2 , & V_322 , NULL ) ;
F_7 ( V_45 , L_41 , V_34 ) ;
return V_34 ;
}
int
F_66 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 )
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
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
V_87 [ 0 ] . V_110 = ( char * ) V_84 ;
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , 0 ) ;
V_79 = (struct V_327 * ) V_87 [ 0 ] . V_110 ;
if ( V_34 != 0 ) {
if ( V_5 )
F_50 ( V_5 , V_328 ) ;
goto V_329;
}
V_329:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
static int
F_67 ( unsigned int V_330 , unsigned int V_331 ,
struct V_1 * V_2 , unsigned int V_332 )
{
unsigned int V_333 = F_68 ( V_2 -> V_11 ) ;
char * V_334 = V_333 + 4 + ( char * ) V_2 ;
char * V_335 = 4 + V_330 + ( char * ) V_2 ;
char * V_336 = V_335 + V_331 ;
if ( V_331 < V_332 ) {
F_7 ( V_117 , L_43 ,
V_331 , V_332 ) ;
return - V_199 ;
}
if ( ( V_333 > 0x7FFFFF ) || ( V_331 > 0x7FFFFF ) ) {
F_7 ( V_117 , L_44 ,
V_331 , V_333 ) ;
return - V_199 ;
}
if ( ( V_335 > V_334 ) || ( V_336 > V_334 ) ) {
F_7 ( V_117 , L_45 ) ;
return - V_199 ;
}
return 0 ;
}
static int
F_69 ( unsigned int V_330 , unsigned int V_331 ,
struct V_1 * V_2 , unsigned int V_337 ,
char * V_338 )
{
char * V_335 = 4 + V_330 + ( char * ) V_2 ;
int V_34 ;
if ( ! V_338 )
return - V_199 ;
V_34 = F_67 ( V_330 , V_331 , V_2 , V_337 ) ;
if ( V_34 )
return V_34 ;
memcpy ( V_338 , V_335 , V_331 ) ;
return 0 ;
}
static int
F_70 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , T_10 V_339 ,
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
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
V_84 -> V_347 =
F_4 ( sizeof( struct V_342 ) - 1 - 4 ) ;
V_84 -> V_348 = F_5 ( V_340 ) ;
V_87 [ 0 ] . V_110 = ( char * ) V_84 ;
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , 0 ) ;
V_79 = (struct V_343 * ) V_87 [ 0 ] . V_110 ;
if ( V_34 ) {
F_50 ( V_5 , V_349 ) ;
goto V_350;
}
V_34 = F_69 ( F_2 ( V_79 -> V_351 ) ,
F_31 ( V_79 -> V_348 ) ,
& V_79 -> V_2 , V_341 , V_338 ) ;
V_350:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
int
F_71 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 ,
struct V_261 * V_338 )
{
return F_70 ( V_82 , V_5 , V_235 , V_237 ,
V_352 ,
sizeof( struct V_261 ) + V_353 * 2 ,
sizeof( struct V_261 ) , V_338 ) ;
}
int
F_72 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , T_12 * V_354 )
{
return F_70 ( V_82 , V_5 , V_235 , V_237 ,
V_355 ,
sizeof( struct V_356 ) ,
sizeof( struct V_356 ) , V_354 ) ;
}
static void
F_73 ( struct V_357 * V_358 )
{
struct V_38 * V_21 = V_358 -> V_359 ;
struct V_360 * V_361 = (struct V_360 * ) V_358 -> V_362 ;
unsigned int V_363 = 1 ;
if ( V_358 -> V_364 == V_365 )
V_363 = F_2 ( V_361 -> V_2 . V_15 ) ;
F_74 ( V_358 ) ;
F_75 ( V_21 , V_363 , V_366 ) ;
}
int
F_76 ( struct V_38 * V_21 )
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
V_87 . V_110 = ( char * ) V_84 ;
V_87 . V_111 = F_28 ( V_84 ) + 4 ;
V_34 = F_77 ( V_21 , & V_369 , NULL , F_73 , V_21 ,
V_366 ) ;
if ( V_34 )
F_7 ( V_45 , L_48 , V_34 ) ;
F_23 ( V_84 ) ;
return V_34 ;
}
int
F_78 ( const unsigned int V_82 , struct V_4 * V_5 , T_9 V_235 ,
T_9 V_237 )
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
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
V_87 [ 0 ] . V_110 = ( char * ) V_84 ;
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 1 , & V_78 , 0 ) ;
if ( ( V_34 != 0 ) && V_5 )
F_50 ( V_5 , V_374 ) ;
F_22 ( V_78 , V_87 [ 0 ] . V_110 ) ;
return V_34 ;
}
static int
F_79 ( struct V_86 * V_87 , struct V_375 * V_376 ,
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
V_84 -> V_234 = V_376 -> V_235 ;
V_84 -> V_236 = V_376 -> V_237 ;
V_84 -> V_383 = 0 ;
V_84 -> V_384 = 0 ;
V_84 -> V_160 = 0 ;
V_84 -> V_385 = 0 ;
V_84 -> V_386 = F_5 ( V_376 -> V_387 ) ;
V_84 -> V_388 = F_80 ( V_376 -> V_330 ) ;
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
V_84 -> V_234 = 0xFFFFFFFF ;
V_84 -> V_236 = 0xFFFFFFFF ;
}
}
if ( V_377 > V_376 -> V_387 )
V_84 -> V_394 = F_5 ( V_377 ) ;
else
V_84 -> V_394 = 0 ;
V_87 [ 0 ] . V_110 = ( char * ) V_84 ;
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 ;
return V_34 ;
}
static void
F_81 ( struct V_357 * V_358 )
{
struct V_395 * V_396 = V_358 -> V_359 ;
struct V_4 * V_5 = F_82 ( V_396 -> V_397 -> V_398 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_1 * V_223 = (struct V_1 * ) V_396 -> V_87 . V_110 ;
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
V_363 = F_2 ( V_223 -> V_15 ) ;
if ( V_21 -> V_29 ) {
int V_34 ;
V_34 = F_83 ( & V_369 , V_21 ) ;
if ( V_34 )
F_7 ( V_117 , L_51 ,
V_34 ) ;
}
F_84 ( V_396 -> V_408 ) ;
F_85 ( V_5 , V_396 -> V_408 ) ;
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
F_50 ( V_5 , V_412 ) ;
F_86 ( V_413 , & V_396 -> V_414 ) ;
F_74 ( V_358 ) ;
F_75 ( V_21 , V_363 , 0 ) ;
}
int
F_87 ( struct V_395 * V_396 )
{
int V_34 ;
struct V_1 * V_223 ;
struct V_375 V_376 ;
struct V_368 V_369 = { . V_370 = & V_396 -> V_87 ,
. V_371 = 1 } ;
F_7 ( V_45 , L_52 ,
V_93 , V_396 -> V_330 , V_396 -> V_408 ) ;
V_376 . V_5 = F_82 ( V_396 -> V_397 -> V_398 ) ;
V_376 . V_330 = V_396 -> V_330 ;
V_376 . V_387 = V_396 -> V_408 ;
V_376 . V_235 = V_396 -> V_397 -> V_232 . V_235 ;
V_376 . V_237 = V_396 -> V_397 -> V_232 . V_237 ;
V_376 . V_382 = V_396 -> V_382 ;
V_34 = F_79 ( & V_396 -> V_87 , & V_376 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_223 = (struct V_1 * ) V_396 -> V_87 . V_110 ;
V_396 -> V_87 . V_111 = F_28 ( V_396 -> V_87 . V_110 ) + 4 ;
F_88 ( & V_396 -> V_415 ) ;
V_34 = F_77 ( V_376 . V_5 -> V_20 -> V_21 , & V_369 ,
V_416 , F_81 ,
V_396 , 0 ) ;
if ( V_34 ) {
F_89 ( & V_396 -> V_415 , V_417 ) ;
F_50 ( V_376 . V_5 , V_412 ) ;
}
F_23 ( V_223 ) ;
return V_34 ;
}
int
F_90 ( const unsigned int V_82 , struct V_375 * V_376 ,
unsigned int * V_418 , char * * V_223 , int * V_419 )
{
int V_78 , V_34 = - V_379 ;
struct V_420 * V_79 = NULL ;
struct V_86 V_87 [ 1 ] ;
* V_418 = 0 ;
V_34 = F_79 ( V_87 , V_376 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_29 ( V_82 , V_376 -> V_5 -> V_20 , V_87 , 1 ,
& V_78 , V_166 ) ;
V_79 = (struct V_420 * ) V_87 [ 0 ] . V_110 ;
if ( V_79 -> V_2 . V_168 == V_421 ) {
F_22 ( V_78 , V_87 [ 0 ] . V_110 ) ;
return 0 ;
}
if ( V_34 ) {
F_50 ( V_376 -> V_5 , V_412 ) ;
F_7 ( V_117 , L_53 , V_34 ) ;
} else {
* V_418 = F_31 ( V_79 -> V_227 ) ;
if ( ( * V_418 > V_422 ) ||
( * V_418 > V_376 -> V_387 ) ) {
F_7 ( V_45 , L_54 ,
* V_418 , V_376 -> V_387 ) ;
V_34 = - V_48 ;
* V_418 = 0 ;
}
}
if ( * V_223 ) {
memcpy ( * V_223 , ( char * ) V_79 -> V_2 . V_12 + V_79 -> V_225 ,
* V_418 ) ;
F_22 ( V_78 , V_87 [ 0 ] . V_110 ) ;
} else if ( V_78 != V_167 ) {
* V_223 = V_87 [ 0 ] . V_110 ;
if ( V_78 == V_80 )
* V_419 = V_80 ;
else if ( V_78 == V_81 )
* V_419 = V_81 ;
}
return V_34 ;
}
static void
F_91 ( struct V_357 * V_358 )
{
struct V_423 * V_424 = V_358 -> V_359 ;
struct V_4 * V_5 = F_82 ( V_424 -> V_397 -> V_398 ) ;
unsigned int V_425 ;
struct V_426 * V_79 = (struct V_426 * ) V_358 -> V_362 ;
unsigned int V_363 = 1 ;
switch ( V_358 -> V_364 ) {
case V_365 :
V_363 = F_2 ( V_79 -> V_2 . V_15 ) ;
V_424 -> V_407 = F_92 ( V_358 , V_5 -> V_20 -> V_21 , 0 ) ;
if ( V_424 -> V_407 != 0 )
break;
V_425 = F_31 ( V_79 -> V_227 ) ;
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
F_50 ( V_5 , V_428 ) ;
F_86 ( V_413 , & V_424 -> V_414 ) ;
F_74 ( V_358 ) ;
F_75 ( V_5 -> V_20 -> V_21 , V_363 , 0 ) ;
}
int
F_93 ( struct V_423 * V_424 ,
void (* F_94)( struct V_429 * V_429 ) )
{
int V_34 = - V_379 ;
struct V_430 * V_84 = NULL ;
struct V_4 * V_5 = F_82 ( V_424 -> V_397 -> V_398 ) ;
struct V_86 V_87 ;
struct V_368 V_369 ;
V_34 = F_18 ( V_42 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
goto V_431;
V_84 -> V_2 . V_16 = F_5 ( V_424 -> V_397 -> V_382 ) ;
V_84 -> V_234 = V_424 -> V_397 -> V_232 . V_235 ;
V_84 -> V_236 = V_424 -> V_397 -> V_232 . V_237 ;
V_84 -> V_432 = 0 ;
V_84 -> V_433 = 0 ;
V_84 -> V_160 = 0 ;
V_84 -> V_388 = F_80 ( V_424 -> V_330 ) ;
V_84 -> V_225 = F_4 (
F_44 ( struct V_430 , V_170 ) - 4 ) ;
V_84 -> V_394 = 0 ;
V_87 . V_111 = F_28 ( V_84 ) + 4 - 1 ;
V_87 . V_110 = V_84 ;
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
F_88 ( & V_424 -> V_415 ) ;
V_34 = F_77 ( V_5 -> V_20 -> V_21 , & V_369 , NULL ,
F_91 , V_424 , 0 ) ;
if ( V_34 ) {
F_89 ( & V_424 -> V_415 , F_94 ) ;
F_50 ( V_5 , V_428 ) ;
}
V_431:
F_23 ( V_84 ) ;
return V_34 ;
}
int
F_95 ( const unsigned int V_82 , struct V_375 * V_376 ,
unsigned int * V_418 , struct V_86 * V_87 , int V_434 )
{
int V_34 = 0 ;
struct V_430 * V_84 = NULL ;
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
V_84 -> V_234 = V_376 -> V_235 ;
V_84 -> V_236 = V_376 -> V_237 ;
V_84 -> V_432 = 0 ;
V_84 -> V_433 = 0 ;
V_84 -> V_160 = 0 ;
V_84 -> V_386 = F_5 ( V_376 -> V_387 ) ;
V_84 -> V_388 = F_80 ( V_376 -> V_330 ) ;
V_84 -> V_225 = F_4 (
F_44 ( struct V_430 , V_170 ) - 4 ) ;
V_84 -> V_394 = 0 ;
V_87 [ 0 ] . V_110 = ( char * ) V_84 ;
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 - 1 ;
F_27 ( V_84 , V_376 -> V_387 - 1 ) ;
V_34 = F_29 ( V_82 , V_376 -> V_5 -> V_20 , V_87 , V_434 + 1 ,
& V_78 , 0 ) ;
V_79 = (struct V_426 * ) V_87 [ 0 ] . V_110 ;
if ( V_34 ) {
F_50 ( V_376 -> V_5 , V_428 ) ;
F_7 ( V_117 , L_56 , V_34 ) ;
} else
* V_418 = F_31 ( V_79 -> V_227 ) ;
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
static unsigned int
F_96 ( char * V_435 , char * V_336 , char * * V_436 , T_11 V_437 )
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
V_438 = F_31 ( V_441 -> V_442 ) ;
if ( ( char * ) V_441 + V_438 + V_437 > V_336 ) {
F_7 ( V_117 , L_58 ,
V_336 ) ;
break;
}
* V_436 = ( char * ) V_441 ;
V_439 ++ ;
V_440 = F_31 ( V_441 -> V_443 ) ;
if ( ! V_440 )
break;
}
return V_439 ;
}
int
F_97 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , int V_444 ,
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
V_34 = - V_199 ;
goto V_461;
}
V_84 -> V_462 = F_5 ( V_444 ) ;
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
V_438 = 0x2 ;
V_449 = V_84 -> V_170 ;
memcpy ( V_449 , & V_450 , V_438 ) ;
V_84 -> V_463 =
F_4 ( sizeof( struct V_447 ) - 1 - 4 ) ;
V_84 -> V_442 = F_4 ( V_438 ) ;
V_451 = F_30 (unsigned int, output_size, server->maxBuf) ;
V_451 = F_30 (unsigned int, output_size, 2 << 15 ) ;
V_84 -> V_348 = F_5 ( V_451 ) ;
V_87 [ 0 ] . V_110 = ( char * ) V_84 ;
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 - 1 ;
V_87 [ 1 ] . V_110 = ( char * ) ( V_84 -> V_170 ) ;
V_87 [ 1 ] . V_111 = V_438 ;
F_27 ( V_84 , V_438 - 1 ) ;
V_34 = F_29 ( V_82 , V_20 , V_87 , 2 , & V_78 , 0 ) ;
V_79 = (struct V_448 * ) V_87 [ 0 ] . V_110 ;
if ( V_34 ) {
F_50 ( V_5 , V_464 ) ;
goto V_461;
}
V_34 = F_67 ( F_2 ( V_79 -> V_351 ) ,
F_31 ( V_79 -> V_348 ) , & V_79 -> V_2 ,
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
F_96 ( V_446 -> V_468 , V_334 ,
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
if ( V_79 -> V_2 . V_168 == V_472 )
V_446 -> V_473 = 1 ;
else
V_446 -> V_473 = 0 ;
return V_34 ;
V_461:
F_22 ( V_78 , V_79 ) ;
return V_34 ;
}
static int
F_98 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , T_4 V_382 , int V_339 ,
unsigned int V_251 , void * * V_338 , unsigned int * V_437 )
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
V_84 -> V_2 . V_16 = F_5 ( V_382 ) ;
V_84 -> V_344 = V_345 ;
V_84 -> V_346 = V_339 ;
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
V_84 -> V_477 =
F_4 ( sizeof( struct V_474 ) - 1 - 4 ) ;
V_84 -> V_478 = F_5 ( * V_437 ) ;
F_27 ( V_84 , * V_437 - 1 ) ;
memcpy ( V_84 -> V_170 , * V_338 , * V_437 ) ;
V_87 [ 0 ] . V_110 = ( char * ) V_84 ;
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 ;
for ( V_476 = 1 ; V_476 < V_251 ; V_476 ++ ) {
F_27 ( V_84 , V_437 [ V_476 ] ) ;
F_59 ( & V_84 -> V_478 , V_437 [ V_476 ] ) ;
V_87 [ V_476 ] . V_110 = ( char * ) V_338 [ V_476 ] ;
V_87 [ V_476 ] . V_111 = V_437 [ V_476 ] ;
}
V_34 = F_29 ( V_82 , V_20 , V_87 , V_251 , & V_78 , 0 ) ;
V_79 = (struct V_475 * ) V_87 [ 0 ] . V_110 ;
if ( V_34 != 0 )
F_50 ( V_5 , V_479 ) ;
F_22 ( V_78 , V_79 ) ;
F_39 ( V_87 ) ;
return V_34 ;
}
int
F_99 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , T_1 * V_480 )
{
struct V_481 V_482 ;
void * * V_338 ;
unsigned int V_437 [ 2 ] ;
int V_34 ;
int V_438 = ( 2 * F_62 ( ( V_285 * ) V_480 , V_286 ) ) ;
V_338 = F_40 ( sizeof( void * ) * 2 , V_151 ) ;
if ( ! V_338 )
return - V_72 ;
V_482 . V_483 = 1 ;
V_482 . V_484 = 0 ;
V_482 . V_442 = F_5 ( V_438 ) ;
V_338 [ 0 ] = & V_482 ;
V_437 [ 0 ] = sizeof( struct V_481 ) ;
V_338 [ 1 ] = V_480 ;
V_437 [ 1 ] = V_438 + 2 ;
V_34 = F_98 ( V_82 , V_5 , V_235 , V_237 ,
V_17 -> V_18 , V_485 , 2 , V_338 ,
V_437 ) ;
F_39 ( V_338 ) ;
return V_34 ;
}
int
F_100 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , T_1 * V_480 )
{
struct V_486 V_482 ;
void * * V_338 ;
unsigned int V_437 [ 2 ] ;
int V_34 ;
int V_438 = ( 2 * F_62 ( ( V_285 * ) V_480 , V_286 ) ) ;
V_338 = F_40 ( sizeof( void * ) * 2 , V_151 ) ;
if ( ! V_338 )
return - V_72 ;
V_482 . V_483 = 0 ;
V_482 . V_484 = 0 ;
V_482 . V_442 = F_5 ( V_438 ) ;
V_338 [ 0 ] = & V_482 ;
V_437 [ 0 ] = sizeof( struct V_486 ) ;
V_338 [ 1 ] = V_480 ;
V_437 [ 1 ] = V_438 + 2 ;
V_34 = F_98 ( V_82 , V_5 , V_235 , V_237 ,
V_17 -> V_18 , V_487 , 2 , V_338 , V_437 ) ;
F_39 ( V_338 ) ;
return V_34 ;
}
int
F_101 ( const unsigned int V_82 , struct V_4 * V_5 , T_9 V_235 ,
T_9 V_237 , T_4 V_382 , T_12 * V_488 )
{
struct V_489 V_482 ;
void * V_338 ;
unsigned int V_437 ;
V_482 . V_295 = * V_488 ;
V_338 = & V_482 ;
V_437 = sizeof( struct V_489 ) ;
return F_98 ( V_82 , V_5 , V_235 , V_237 , V_382 ,
V_490 , 1 , & V_338 , & V_437 ) ;
}
int
F_102 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , T_14 * V_223 )
{
unsigned int V_437 ;
V_437 = sizeof( T_14 ) ;
return F_98 ( V_82 , V_5 , V_235 , V_237 ,
V_17 -> V_18 , V_491 , 1 ,
( void * * ) & V_223 , & V_437 ) ;
}
int
F_103 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_9 V_235 , const T_9 V_237 ,
T_7 V_492 )
{
int V_34 ;
struct V_493 * V_84 = NULL ;
F_7 ( V_45 , L_62 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_84 ) ;
if ( V_34 )
return V_34 ;
V_84 -> V_494 = V_237 ;
V_84 -> V_495 = V_235 ;
V_84 -> V_300 = V_492 ;
V_84 -> V_2 . V_15 = F_4 ( 1 ) ;
V_34 = F_49 ( V_82 , V_5 -> V_20 , ( char * ) V_84 , V_496 ) ;
if ( V_34 ) {
F_50 ( V_5 , V_497 ) ;
F_7 ( V_45 , L_63 , V_34 ) ;
}
return V_34 ;
}
static void
F_104 ( struct V_498 * V_499 ,
struct V_500 * V_501 )
{
V_501 -> V_502 = F_31 ( V_499 -> V_503 ) *
F_31 ( V_499 -> V_504 ) ;
V_501 -> V_505 = F_105 ( V_499 -> V_506 ) ;
V_501 -> V_507 = F_105 ( V_499 -> V_508 ) ;
V_501 -> V_509 = F_105 ( V_499 -> V_510 ) ;
return;
}
static int
F_106 ( struct V_86 * V_87 , struct V_4 * V_5 , int V_511 ,
int V_512 , T_9 V_235 , T_9 V_237 )
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
V_84 -> V_234 = V_235 ;
V_84 -> V_236 = V_237 ;
V_84 -> V_347 =
F_4 ( sizeof( struct V_342 ) - 1 - 4 ) ;
V_84 -> V_348 = F_5 (
V_512 + sizeof( struct V_343 ) - 1 - 4 ) ;
V_87 -> V_110 = ( char * ) V_84 ;
V_87 -> V_111 = F_28 ( V_84 ) + 4 ;
return 0 ;
}
int
F_107 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , struct V_500 * V_514 )
{
struct V_343 * V_79 = NULL ;
struct V_86 V_87 ;
int V_34 = 0 ;
int V_78 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_498 * V_482 = NULL ;
V_34 = F_106 ( & V_87 , V_5 , V_515 ,
sizeof( struct V_498 ) ,
V_235 , V_237 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_29 ( V_82 , V_20 , & V_87 , 1 , & V_78 , 0 ) ;
if ( V_34 ) {
F_50 ( V_5 , V_349 ) ;
goto V_516;
}
V_79 = (struct V_343 * ) V_87 . V_110 ;
V_482 = (struct V_498 * ) ( 4 +
F_2 ( V_79 -> V_351 ) + ( char * ) & V_79 -> V_2 ) ;
V_34 = F_67 ( F_2 ( V_79 -> V_351 ) ,
F_31 ( V_79 -> V_348 ) , & V_79 -> V_2 ,
sizeof( struct V_498 ) ) ;
if ( ! V_34 )
F_104 ( V_482 , V_514 ) ;
V_516:
F_22 ( V_78 , V_87 . V_110 ) ;
return V_34 ;
}
int
F_108 ( const unsigned int V_82 , struct V_4 * V_5 ,
T_9 V_235 , T_9 V_237 , int V_511 )
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
return - V_199 ;
}
V_34 = F_106 ( & V_87 , V_5 , V_511 , V_517 ,
V_235 , V_237 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_29 ( V_82 , V_20 , & V_87 , 1 , & V_78 , 0 ) ;
if ( V_34 ) {
F_50 ( V_5 , V_349 ) ;
goto V_526;
}
V_79 = (struct V_343 * ) V_87 . V_110 ;
V_518 = F_31 ( V_79 -> V_348 ) ;
V_330 = F_2 ( V_79 -> V_351 ) ;
V_34 = F_67 ( V_330 , V_518 , & V_79 -> V_2 , V_341 ) ;
if ( V_34 )
goto V_526;
if ( V_511 == V_521 )
memcpy ( & V_5 -> V_527 , 4 + V_330
+ ( char * ) & V_79 -> V_2 , F_30 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_511 == V_519 )
memcpy ( & V_5 -> V_528 , 4 + V_330
+ ( char * ) & V_79 -> V_2 , sizeof( V_520 ) ) ;
else if ( V_511 == V_524 ) {
struct V_525 * V_529 = (struct V_525 * )
( 4 + V_330 + ( char * ) & V_79 -> V_2 ) ;
V_5 -> V_530 = F_31 ( V_529 -> V_30 ) ;
V_5 -> V_531 =
F_31 ( V_529 -> V_532 ) ;
}
V_526:
F_22 ( V_78 , V_87 . V_110 ) ;
return V_34 ;
}
int
F_109 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_15 V_533 , const T_15 V_237 , const T_8 V_382 ,
const T_8 V_534 , struct V_535 * V_223 )
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
V_84 -> V_234 = V_533 ;
V_84 -> V_236 = V_237 ;
V_538 = V_534 * sizeof( struct V_535 ) ;
F_27 ( V_84 , V_538 - sizeof( struct V_535 ) ) ;
V_87 [ 0 ] . V_110 = ( char * ) V_84 ;
V_87 [ 0 ] . V_111 = F_28 ( V_84 ) + 4 - V_538 ;
V_87 [ 1 ] . V_110 = ( char * ) V_223 ;
V_87 [ 1 ] . V_111 = V_538 ;
F_21 ( & V_5 -> V_74 . V_540 . V_541 ) ;
V_34 = F_29 ( V_82 , V_5 -> V_20 , V_87 , 2 , & V_537 , V_542 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_67 , V_34 ) ;
F_50 ( V_5 , V_543 ) ;
}
return V_34 ;
}
int
F_110 ( const unsigned int V_82 , struct V_4 * V_5 ,
const T_15 V_533 , const T_15 V_237 , const T_8 V_382 ,
const T_15 V_387 , const T_15 V_330 , const T_8 V_544 ,
const bool V_545 )
{
struct V_535 V_546 ;
V_546 . V_388 = F_80 ( V_330 ) ;
V_546 . V_386 = F_80 ( V_387 ) ;
V_546 . V_30 = F_5 ( V_544 ) ;
if ( ! V_545 && V_544 != V_547 )
V_546 . V_30 |= F_5 ( V_548 ) ;
return F_109 ( V_82 , V_5 , V_533 , V_237 , V_382 , 1 , & V_546 ) ;
}
int
F_111 ( const unsigned int V_82 , struct V_4 * V_5 ,
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
V_34 = F_49 ( V_82 , V_5 -> V_20 , ( char * ) V_84 , V_496 ) ;
if ( V_34 ) {
F_50 ( V_5 , V_497 ) ;
F_7 ( V_45 , L_69 , V_34 ) ;
}
return V_34 ;
}
