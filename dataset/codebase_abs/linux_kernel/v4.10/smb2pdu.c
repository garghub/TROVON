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
V_2 -> V_12 = V_13 ;
V_2 -> V_14 = F_4 ( 64 ) ;
V_2 -> V_15 = V_3 ;
if ( V_5 && V_5 -> V_16 && V_5 -> V_16 -> V_17 ) {
struct V_18 * V_17 = V_5 -> V_16 -> V_17 ;
F_5 ( & V_17 -> V_19 ) ;
if ( V_17 -> V_20 >= V_17 -> V_21 )
V_2 -> V_22 = F_4 ( 0 ) ;
else
V_2 -> V_22 = F_4 (
F_6 ( int , V_17 -> V_21 -
V_17 -> V_20 , 2 ) ) ;
F_7 ( & V_17 -> V_19 ) ;
} else {
V_2 -> V_22 = F_4 ( 2 ) ;
}
V_2 -> V_23 = F_8 ( ( T_2 ) V_24 -> V_25 ) ;
if ( ! V_5 )
goto V_26;
if ( ( V_5 -> V_16 ) && ( V_5 -> V_16 -> V_17 ) &&
( V_5 -> V_16 -> V_17 -> V_27 & V_28 ) )
V_2 -> V_29 = F_4 ( 1 ) ;
V_2 -> V_30 = V_5 -> V_31 ;
if ( V_5 -> V_16 )
V_2 -> V_32 = V_5 -> V_16 -> V_33 ;
if ( V_5 -> V_16 && V_5 -> V_16 -> V_17 && V_5 -> V_16 -> V_17 -> V_34 )
V_2 -> V_35 |= V_36 ;
V_26:
V_7 -> V_37 = F_4 ( V_9 ) ;
return;
}
static int
F_9 ( T_1 V_38 , struct V_4 * V_5 )
{
int V_39 = 0 ;
struct V_40 * V_41 ;
struct V_42 * V_16 ;
struct V_18 * V_17 ;
if ( V_5 == NULL )
return V_39 ;
if ( V_38 == V_43 )
return V_39 ;
if ( V_5 -> V_44 == V_45 ) {
if ( ( V_38 != V_46 ) &&
( V_38 != V_47 ) &&
( V_38 != V_48 ) ) {
F_10 ( V_49 , L_1 ,
V_38 ) ;
return - V_50 ;
}
}
if ( ( ! V_5 -> V_16 ) || ( V_5 -> V_16 -> V_51 == V_45 ) ||
( ! V_5 -> V_16 -> V_17 ) )
return - V_52 ;
V_16 = V_5 -> V_16 ;
V_17 = V_16 -> V_17 ;
while ( V_17 -> V_53 == V_54 ) {
switch ( V_38 ) {
case V_48 :
case V_55 :
case V_56 :
case V_57 :
return - V_58 ;
}
F_11 ( V_17 -> V_59 ,
( V_17 -> V_53 != V_54 ) , 10 * V_60 ) ;
if ( V_17 -> V_53 != V_54 )
break;
if ( ! V_5 -> V_61 ) {
F_10 ( V_49 , L_2 ) ;
return - V_62 ;
}
}
if ( ! V_5 -> V_16 -> V_63 && ! V_5 -> V_63 )
return V_39 ;
V_41 = F_12 () ;
F_13 ( & V_5 -> V_16 -> V_64 ) ;
V_39 = F_14 ( 0 , V_5 -> V_16 ) ;
if ( ! V_39 && V_5 -> V_16 -> V_63 )
V_39 = F_15 ( 0 , V_5 -> V_16 , V_41 ) ;
if ( V_39 || ! V_5 -> V_63 ) {
F_16 ( & V_5 -> V_16 -> V_64 ) ;
goto V_26;
}
F_17 ( V_5 ) ;
if ( V_5 -> V_65 )
V_5 -> V_66 = true ;
V_39 = F_18 ( 0 , V_5 -> V_16 , V_5 -> V_67 , V_5 , V_41 ) ;
F_16 ( & V_5 -> V_16 -> V_64 ) ;
F_10 ( V_49 , L_3 , V_39 ) ;
if ( V_39 )
goto V_26;
if ( V_38 != V_68 )
F_19 ( V_69 , & V_17 -> V_70 , 0 ) ;
F_20 ( & V_71 ) ;
V_26:
switch ( V_38 ) {
case V_72 :
case V_73 :
case V_46 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
V_39 = - V_58 ;
}
F_21 ( V_41 ) ;
return V_39 ;
}
static int
F_22 ( T_1 V_38 , struct V_4 * V_5 ,
void * * V_80 )
{
int V_39 = 0 ;
V_39 = F_9 ( V_38 , V_5 ) ;
if ( V_39 )
return V_39 ;
* V_80 = F_23 () ;
if ( * V_80 == NULL ) {
return - V_81 ;
}
F_1 ( (struct V_1 * ) * V_80 , V_38 , V_5 ) ;
if ( V_5 != NULL ) {
#ifdef F_24
T_3 V_82 = F_2 ( V_38 ) ;
F_25 ( & V_5 -> V_83 . V_84 . V_85 [ V_82 ] ) ;
#endif
F_25 ( & V_5 -> V_86 ) ;
}
return V_39 ;
}
static void
F_26 ( struct V_87 * V_88 )
{
V_88 -> V_89 = V_90 ;
V_88 -> V_91 = F_4 ( 38 ) ;
V_88 -> V_92 = F_4 ( 1 ) ;
V_88 -> V_93 = F_4 ( V_94 ) ;
F_27 ( V_88 -> V_95 , V_94 ) ;
V_88 -> V_96 = V_97 ;
}
static void
F_28 ( struct V_98 * V_88 )
{
V_88 -> V_89 = V_99 ;
V_88 -> V_91 = F_4 ( 6 ) ;
V_88 -> V_100 = F_4 ( 2 ) ;
V_88 -> V_101 [ 0 ] = V_102 ;
V_88 -> V_101 [ 1 ] = V_103 ;
}
static void
F_29 ( struct V_104 * V_105 )
{
char * V_88 = ( char * ) V_105 + V_106 + 4 ;
F_26 ( (struct V_87 * ) V_88 ) ;
V_88 += 2 + sizeof( struct V_87 ) ;
F_28 ( (struct V_98 * ) V_88 ) ;
V_105 -> V_107 = F_8 ( V_106 ) ;
V_105 -> V_108 = F_4 ( 2 ) ;
F_30 ( V_105 , 4 + sizeof( struct V_87 ) + 2
+ sizeof( struct V_98 ) ) ;
}
static void F_29 ( struct V_104 * V_105 )
{
return;
}
int
F_31 ( const unsigned int V_109 , struct V_42 * V_16 )
{
struct V_104 * V_105 ;
struct V_110 * V_111 ;
struct V_112 V_113 [ 1 ] ;
int V_39 = 0 ;
int V_114 ;
struct V_18 * V_17 = V_16 -> V_17 ;
int V_115 , V_116 ;
char * V_117 ;
int V_118 = V_119 ;
F_10 ( V_49 , L_4 ) ;
if ( ! V_17 ) {
F_32 ( 1 , L_5 , V_120 ) ;
return - V_52 ;
}
V_39 = F_22 ( V_121 , NULL , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
V_105 -> V_2 . V_32 = 0 ;
V_105 -> V_122 [ 0 ] = F_4 ( V_16 -> V_17 -> V_123 -> V_124 ) ;
V_105 -> V_125 = F_4 ( 1 ) ;
F_30 ( V_105 , 2 ) ;
if ( V_16 -> V_34 )
V_105 -> V_126 = F_4 ( V_127 ) ;
else if ( V_128 & V_129 )
V_105 -> V_126 = F_4 ( V_130 ) ;
else
V_105 -> V_126 = 0 ;
V_105 -> V_131 = F_8 ( V_16 -> V_17 -> V_123 -> V_132 ) ;
if ( V_16 -> V_17 -> V_123 -> V_124 == V_133 )
memset ( V_105 -> V_134 , 0 , V_135 ) ;
else {
memcpy ( V_105 -> V_134 , V_17 -> V_136 ,
V_135 ) ;
if ( V_16 -> V_17 -> V_123 -> V_124 == V_137 )
F_29 ( V_105 ) ;
}
V_113 [ 0 ] . V_138 = ( char * ) V_105 ;
V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 ;
V_39 = F_34 ( V_109 , V_16 , V_113 , 1 , & V_114 , V_118 ) ;
V_111 = (struct V_110 * ) V_113 [ 0 ] . V_138 ;
if ( V_39 != 0 )
goto V_140;
F_10 ( V_49 , L_6 , V_111 -> V_126 ) ;
if ( V_111 -> V_141 == F_4 ( V_133 ) )
F_10 ( V_49 , L_7 ) ;
else if ( V_111 -> V_141 == F_4 ( V_142 ) )
F_10 ( V_49 , L_8 ) ;
else if ( V_111 -> V_141 == F_4 ( V_143 ) )
F_10 ( V_49 , L_9 ) ;
else if ( V_111 -> V_141 == F_4 ( V_144 ) )
F_10 ( V_49 , L_10 ) ;
#ifdef F_35
else if ( V_111 -> V_141 == F_4 ( V_137 ) )
F_10 ( V_49 , L_11 ) ;
#endif
else {
F_10 ( V_145 , L_12 ,
F_2 ( V_111 -> V_141 ) ) ;
V_39 = - V_52 ;
goto V_140;
}
V_17 -> V_146 = F_2 ( V_111 -> V_141 ) ;
V_17 -> V_147 = V_148 ;
V_17 -> V_149 = F_6 (unsigned int, le32_to_cpu(rsp->MaxTransactSize),
SMB2_MAX_BUFFER_SIZE) ;
V_17 -> V_150 = F_36 ( V_111 -> V_151 ) ;
V_17 -> V_152 = F_36 ( V_111 -> V_153 ) ;
V_17 -> V_154 = F_2 ( V_111 -> V_126 ) ;
V_17 -> V_27 = F_36 ( V_111 -> V_131 ) ;
V_17 -> V_27 |= V_155 | V_156 ;
V_117 = F_37 ( & V_115 , & V_116 ,
& V_111 -> V_2 ) ;
if ( V_116 == 0 )
F_10 ( V_49 , L_13 ) ;
V_39 = F_38 ( V_17 , V_16 -> V_34 ) ;
if ( V_39 )
goto V_140;
if ( V_116 ) {
V_39 = F_39 ( V_117 , V_116 , V_17 ) ;
if ( V_39 == 1 )
V_39 = 0 ;
else if ( V_39 == 0 )
V_39 = - V_52 ;
}
V_140:
F_40 ( V_114 , V_111 ) ;
return V_39 ;
}
int F_41 ( const unsigned int V_109 , struct V_4 * V_5 )
{
int V_39 = 0 ;
struct V_157 V_158 ;
struct V_159 * V_160 ;
T_4 V_161 ;
F_10 ( V_49 , L_14 ) ;
if ( V_5 -> V_16 -> V_17 -> V_34 == false )
return 0 ;
V_158 . V_131 =
F_8 ( V_5 -> V_16 -> V_17 -> V_123 -> V_132 ) ;
memcpy ( V_158 . V_162 , V_5 -> V_16 -> V_17 -> V_136 ,
V_135 ) ;
if ( V_5 -> V_16 -> V_34 )
V_158 . V_126 =
F_4 ( V_127 ) ;
else if ( V_128 & V_129 )
V_158 . V_126 =
F_4 ( V_130 ) ;
else
V_158 . V_126 = 0 ;
V_158 . V_125 = F_4 ( 1 ) ;
V_158 . V_122 [ 0 ] =
F_4 ( V_5 -> V_16 -> V_17 -> V_123 -> V_124 ) ;
V_39 = F_42 ( V_109 , V_5 , V_163 , V_163 ,
V_164 , true ,
( char * ) & V_158 , sizeof( struct V_157 ) ,
( char * * ) & V_160 , & V_161 ) ;
if ( V_39 != 0 ) {
F_10 ( V_145 , L_15 , V_39 ) ;
return - V_52 ;
}
if ( V_161 != sizeof( struct V_159 ) ) {
F_10 ( V_145 , L_16 ) ;
return - V_52 ;
}
if ( V_160 -> V_165 !=
F_4 ( V_5 -> V_16 -> V_17 -> V_123 -> V_124 ) )
goto V_166;
if ( V_160 -> V_126 != F_4 ( V_5 -> V_16 -> V_17 -> V_154 ) )
goto V_166;
if ( ( F_36 ( V_160 -> V_131 ) | V_155 |
V_156 ) != V_5 -> V_16 -> V_17 -> V_27 )
goto V_166;
F_10 ( V_49 , L_17 ) ;
return 0 ;
V_166:
F_10 ( V_145 , L_18 ) ;
return - V_52 ;
}
static int
F_43 ( struct V_167 * V_168 )
{
int V_39 ;
struct V_42 * V_16 = V_168 -> V_16 ;
struct V_169 * V_105 ;
struct V_18 * V_17 = V_16 -> V_17 ;
V_39 = F_22 ( V_170 , NULL , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
V_105 -> V_2 . V_32 = 0 ;
V_105 -> V_171 = V_168 -> V_172 ;
V_105 -> V_35 = 0 ;
V_105 -> V_2 . V_22 = F_4 ( 3 ) ;
if ( V_17 -> V_34 )
V_105 -> V_126 = V_127 ;
else if ( V_128 & V_129 )
V_105 -> V_126 = V_130 ;
else
V_105 -> V_126 = 0 ;
V_105 -> V_131 = 0 ;
V_105 -> V_173 = 0 ;
V_168 -> V_113 [ 0 ] . V_138 = ( char * ) V_105 ;
V_168 -> V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 - 1 ;
V_168 -> V_174 = V_175 ;
return 0 ;
}
static void
F_44 ( struct V_167 * V_168 )
{
F_40 ( V_168 -> V_174 , V_168 -> V_113 [ 0 ] . V_138 ) ;
V_168 -> V_174 = V_176 ;
}
static int
F_45 ( struct V_167 * V_168 )
{
int V_39 ;
struct V_169 * V_105 = V_168 -> V_113 [ 0 ] . V_138 ;
V_105 -> V_177 =
F_4 ( sizeof( struct V_169 ) -
1 - 4 ) ;
V_105 -> V_178 = F_4 ( V_168 -> V_113 [ 1 ] . V_139 ) ;
F_30 ( V_105 , V_168 -> V_113 [ 1 ] . V_139 - 1 ) ;
V_39 = F_34 ( V_168 -> V_109 , V_168 -> V_16 ,
V_168 -> V_113 , 2 ,
& V_168 -> V_174 ,
V_179 | V_119 ) ;
return V_39 ;
}
static int
F_46 ( struct V_167 * V_168 )
{
int V_39 = 0 ;
struct V_42 * V_16 = V_168 -> V_16 ;
F_13 ( & V_16 -> V_17 -> V_180 ) ;
if ( V_16 -> V_17 -> V_34 && V_16 -> V_17 -> V_181 -> V_182 ) {
V_39 = V_16 -> V_17 -> V_181 -> V_182 ( V_16 ) ;
F_47 ( V_16 -> V_183 . V_184 ) ;
V_16 -> V_183 . V_184 = NULL ;
if ( V_39 ) {
F_10 ( V_49 ,
L_19 ) ;
F_16 ( & V_16 -> V_17 -> V_180 ) ;
goto V_185;
}
}
if ( ! V_16 -> V_17 -> V_186 ) {
V_16 -> V_17 -> V_187 = 0x2 ;
V_16 -> V_17 -> V_186 = true ;
}
F_16 ( & V_16 -> V_17 -> V_180 ) ;
F_10 ( V_49 , L_20 ) ;
F_5 ( & V_188 ) ;
V_16 -> V_51 = V_189 ;
V_16 -> V_63 = false ;
F_7 ( & V_188 ) ;
V_185:
if ( ! V_16 -> V_17 -> V_34 ) {
F_47 ( V_16 -> V_183 . V_184 ) ;
V_16 -> V_183 . V_184 = NULL ;
}
return V_39 ;
}
static void
F_48 ( struct V_167 * V_168 )
{
int V_39 ;
struct V_42 * V_16 = V_168 -> V_16 ;
struct V_190 * V_191 ;
struct V_192 * V_193 = NULL ;
struct V_194 * V_111 = NULL ;
V_39 = F_43 ( V_168 ) ;
if ( V_39 )
goto V_26;
V_193 = F_49 ( V_16 ) ;
if ( F_50 ( V_193 ) ) {
V_39 = F_51 ( V_193 ) ;
V_193 = NULL ;
goto V_26;
}
V_191 = V_193 -> V_195 . V_196 [ 0 ] ;
if ( V_191 -> V_197 != V_198 ) {
F_10 ( V_145 ,
L_21 ,
V_198 , V_191 -> V_197 ) ;
V_39 = - V_199 ;
goto V_200;
}
V_16 -> V_183 . V_184 = F_52 ( V_191 -> V_196 , V_191 -> V_201 ,
V_202 ) ;
if ( ! V_16 -> V_183 . V_184 ) {
F_10 ( V_145 ,
L_22 ,
V_191 -> V_201 ) ;
V_39 = - V_81 ;
goto V_200;
}
V_16 -> V_183 . V_203 = V_191 -> V_201 ;
V_168 -> V_113 [ 1 ] . V_138 = V_191 -> V_196 + V_191 -> V_201 ;
V_168 -> V_113 [ 1 ] . V_139 = V_191 -> V_204 ;
V_39 = F_45 ( V_168 ) ;
if ( V_39 )
goto V_200;
V_111 = (struct V_194 * ) V_168 -> V_113 [ 0 ] . V_138 ;
V_16 -> V_33 = V_111 -> V_2 . V_32 ;
V_16 -> V_205 = F_2 ( V_111 -> V_206 ) ;
if ( V_16 -> V_205 & V_207 )
F_10 ( V_145 , L_23 ) ;
V_39 = F_46 ( V_168 ) ;
V_200:
F_53 ( V_193 ) ;
F_54 ( V_193 ) ;
V_26:
V_168 -> V_208 = V_39 ;
V_168 -> V_209 = NULL ;
F_44 ( V_168 ) ;
}
static void
F_48 ( struct V_167 * V_168 )
{
F_10 ( V_145 , L_24 ) ;
V_168 -> V_208 = - V_210 ;
V_168 -> V_209 = NULL ;
}
static void
F_55 ( struct V_167 * V_168 )
{
int V_39 ;
struct V_42 * V_16 = V_168 -> V_16 ;
struct V_194 * V_111 = NULL ;
char * V_211 = NULL ;
bool V_212 = false ;
T_5 V_116 = 0 ;
V_16 -> V_213 = F_56 ( sizeof( struct V_214 ) , V_202 ) ;
if ( ! V_16 -> V_213 ) {
V_39 = - V_81 ;
goto V_215;
}
V_16 -> V_213 -> V_216 = true ;
V_39 = F_43 ( V_168 ) ;
if ( V_39 )
goto V_215;
V_211 = F_56 ( sizeof( struct V_217 ) ,
V_202 ) ;
if ( V_211 == NULL ) {
V_39 = - V_81 ;
goto V_26;
}
F_57 ( V_211 , V_16 ) ;
if ( V_212 ) {
F_10 ( V_145 , L_25 ) ;
V_39 = - V_210 ;
goto V_26;
} else {
V_116 = sizeof( struct V_217 ) ;
}
V_168 -> V_113 [ 1 ] . V_138 = V_211 ;
V_168 -> V_113 [ 1 ] . V_139 = V_116 ;
V_39 = F_45 ( V_168 ) ;
V_111 = (struct V_194 * ) V_168 -> V_113 [ 0 ] . V_138 ;
if ( V_168 -> V_174 != V_176 &&
V_111 -> V_2 . V_218 == V_219 )
V_39 = 0 ;
if ( V_39 )
goto V_26;
if ( F_58 ( struct V_194 , V_220 ) - 4 !=
F_2 ( V_111 -> V_177 ) ) {
F_10 ( V_145 , L_26 ,
F_2 ( V_111 -> V_177 ) ) ;
V_39 = - V_52 ;
goto V_26;
}
V_39 = F_59 ( V_111 -> V_220 ,
F_2 ( V_111 -> V_178 ) , V_16 ) ;
if ( V_39 )
goto V_26;
F_10 ( V_49 , L_27 ) ;
V_16 -> V_33 = V_111 -> V_2 . V_32 ;
V_16 -> V_205 = F_2 ( V_111 -> V_206 ) ;
if ( V_16 -> V_205 & V_207 )
F_10 ( V_145 , L_23 ) ;
V_26:
F_47 ( V_211 ) ;
F_44 ( V_168 ) ;
if ( ! V_39 ) {
V_168 -> V_208 = 0 ;
V_168 -> V_209 = V_221 ;
return;
}
V_215:
F_47 ( V_16 -> V_213 ) ;
V_16 -> V_213 = NULL ;
V_168 -> V_208 = V_39 ;
V_168 -> V_209 = NULL ;
}
static void
V_221 ( struct V_167 * V_168 )
{
int V_39 ;
struct V_42 * V_16 = V_168 -> V_16 ;
struct V_169 * V_105 ;
struct V_194 * V_111 = NULL ;
unsigned char * V_211 = NULL ;
bool V_212 = false ;
T_5 V_116 = 0 ;
V_39 = F_43 ( V_168 ) ;
if ( V_39 )
goto V_26;
V_105 = (struct V_169 * ) V_168 -> V_113 [ 0 ] . V_138 ;
V_105 -> V_2 . V_32 = V_16 -> V_33 ;
V_39 = F_60 ( & V_211 , & V_116 , V_16 ,
V_168 -> V_222 ) ;
if ( V_39 ) {
F_10 ( V_49 , L_28 , V_39 ) ;
goto V_26;
}
if ( V_212 ) {
F_10 ( V_145 , L_25 ) ;
V_39 = - V_210 ;
goto V_26;
}
V_168 -> V_113 [ 1 ] . V_138 = V_211 ;
V_168 -> V_113 [ 1 ] . V_139 = V_116 ;
V_39 = F_45 ( V_168 ) ;
if ( V_39 )
goto V_26;
V_111 = (struct V_194 * ) V_168 -> V_113 [ 0 ] . V_138 ;
V_16 -> V_33 = V_111 -> V_2 . V_32 ;
V_16 -> V_205 = F_2 ( V_111 -> V_206 ) ;
if ( V_16 -> V_205 & V_207 )
F_10 ( V_145 , L_23 ) ;
V_39 = F_46 ( V_168 ) ;
V_26:
F_47 ( V_211 ) ;
F_44 ( V_168 ) ;
F_47 ( V_16 -> V_213 ) ;
V_16 -> V_213 = NULL ;
V_168 -> V_208 = V_39 ;
V_168 -> V_209 = NULL ;
}
static int
F_61 ( struct V_42 * V_16 , struct V_167 * V_168 )
{
if ( V_16 -> V_223 != V_224 && V_16 -> V_223 != V_225 )
V_16 -> V_223 = V_225 ;
switch ( V_16 -> V_223 ) {
case V_224 :
V_168 -> V_209 = F_48 ;
break;
case V_225 :
V_168 -> V_209 = F_55 ;
break;
default:
F_10 ( V_145 , L_29 , V_16 -> V_223 ) ;
return - V_210 ;
}
return 0 ;
}
int
F_62 ( const unsigned int V_109 , struct V_42 * V_16 ,
const struct V_40 * V_222 )
{
int V_39 = 0 ;
struct V_18 * V_17 = V_16 -> V_17 ;
struct V_167 * V_168 ;
F_10 ( V_49 , L_30 ) ;
if ( ! V_17 ) {
F_32 ( 1 , L_5 , V_120 ) ;
return - V_52 ;
}
V_168 = F_63 ( sizeof( struct V_167 ) , V_202 ) ;
if ( ! V_168 )
return - V_81 ;
V_39 = F_61 ( V_16 , V_168 ) ;
if ( V_39 )
goto V_26;
V_168 -> V_109 = V_109 ;
V_168 -> V_16 = V_16 ;
V_168 -> V_174 = V_176 ;
V_168 -> V_222 = (struct V_40 * ) V_222 ;
while ( V_168 -> V_209 )
V_168 -> V_209 ( V_168 ) ;
V_39 = V_168 -> V_208 ;
V_26:
F_47 ( V_168 ) ;
return V_39 ;
}
int
F_64 ( const unsigned int V_109 , struct V_42 * V_16 )
{
struct V_226 * V_105 ;
int V_39 = 0 ;
struct V_18 * V_17 ;
F_10 ( V_49 , L_31 , V_16 ) ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
if ( V_16 -> V_63 )
goto V_227;
V_39 = F_22 ( V_228 , NULL , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
V_105 -> V_2 . V_32 = V_16 -> V_33 ;
if ( V_17 -> V_34 )
V_105 -> V_2 . V_35 |= V_36 ;
V_39 = F_65 ( V_109 , V_16 , ( char * ) & V_105 -> V_2 , 0 ) ;
V_227:
return V_39 ;
}
static inline void F_66 ( struct V_4 * V_5 , T_3 V_229 )
{
F_25 ( & V_5 -> V_83 . V_84 . V_230 [ V_229 ] ) ;
}
static inline void F_67 ( struct V_4 * V_5 )
{
V_5 -> V_231 = 256 ;
V_5 -> V_232 = 1048576 ;
V_5 -> V_233 = 16777216 ;
}
int
F_18 ( const unsigned int V_109 , struct V_42 * V_16 , const char * V_234 ,
struct V_4 * V_5 , const struct V_40 * V_235 )
{
struct V_236 * V_105 ;
struct V_237 * V_111 = NULL ;
struct V_112 V_113 [ 2 ] ;
int V_39 = 0 ;
int V_114 ;
int V_238 ;
struct V_18 * V_17 ;
T_1 * V_239 = NULL ;
F_10 ( V_49 , L_32 ) ;
if ( ( V_16 -> V_17 ) && V_234 )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
if ( V_5 && V_5 -> V_240 )
return - V_241 ;
if ( ( V_5 && V_5 -> V_242 ) &&
( ( V_16 -> V_17 -> V_27 & V_243 ) == 0 ) ) {
F_10 ( V_145 , L_33 ) ;
return - V_210 ;
}
V_239 = F_56 ( V_244 * 2 , V_202 ) ;
if ( V_239 == NULL )
return - V_81 ;
V_238 = F_68 ( V_239 , V_234 , strlen ( V_234 ) , V_235 ) + 1 ;
V_238 *= 2 ;
if ( V_238 < 2 ) {
F_47 ( V_239 ) ;
return - V_245 ;
}
V_39 = F_22 ( V_43 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 ) {
F_47 ( V_239 ) ;
return V_39 ;
}
if ( V_5 == NULL ) {
V_105 -> V_2 . V_32 = V_16 -> V_33 ;
}
V_113 [ 0 ] . V_138 = ( char * ) V_105 ;
V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 - 1 ;
V_105 -> V_246 = F_4 ( sizeof( struct V_236 )
- 1 - 4 ) ;
V_105 -> V_247 = F_4 ( V_238 - 2 ) ;
V_113 [ 1 ] . V_138 = V_239 ;
V_113 [ 1 ] . V_139 = V_238 ;
F_30 ( V_105 , V_238 - 1 ) ;
V_39 = F_34 ( V_109 , V_16 , V_113 , 2 , & V_114 , 0 ) ;
V_111 = (struct V_237 * ) V_113 [ 0 ] . V_138 ;
if ( V_39 != 0 ) {
if ( V_5 ) {
F_66 ( V_5 , V_248 ) ;
V_5 -> V_63 = true ;
}
goto V_249;
}
if ( V_5 == NULL ) {
V_16 -> V_250 = V_111 -> V_2 . V_30 ;
goto V_251;
}
if ( V_111 -> V_252 & V_253 )
F_10 ( V_49 , L_34 ) ;
else if ( V_111 -> V_252 & V_254 ) {
V_5 -> V_255 = true ;
F_10 ( V_49 , L_35 ) ;
} else if ( V_111 -> V_252 & V_256 ) {
V_5 -> V_257 = true ;
F_10 ( V_49 , L_36 ) ;
} else {
F_10 ( V_145 , L_37 , V_111 -> V_252 ) ;
V_39 = - V_210 ;
goto V_249;
}
V_5 -> V_258 = F_36 ( V_111 -> V_259 ) ;
V_5 -> V_27 = V_111 -> V_131 ;
V_5 -> V_260 = F_36 ( V_111 -> V_261 ) ;
V_5 -> V_44 = V_189 ;
V_5 -> V_63 = false ;
V_5 -> V_31 = V_111 -> V_2 . V_30 ;
F_69 ( V_5 -> V_67 , V_234 , sizeof( V_5 -> V_67 ) ) ;
if ( ( V_111 -> V_131 & V_262 ) &&
( ( V_5 -> V_258 & V_263 ) == 0 ) )
F_10 ( V_145 , L_38 ) ;
F_67 ( V_5 ) ;
if ( V_5 -> V_258 & V_264 )
F_10 ( V_145 , L_39 ) ;
if ( V_5 -> V_16 -> V_17 -> V_181 -> V_265 )
V_39 = V_5 -> V_16 -> V_17 -> V_181 -> V_265 ( V_109 , V_5 ) ;
V_251:
F_40 ( V_114 , V_111 ) ;
F_47 ( V_239 ) ;
return V_39 ;
V_249:
if ( V_111 -> V_2 . V_218 == V_266 ) {
F_10 ( V_145 , L_40 , V_234 ) ;
if ( V_5 )
V_5 -> V_240 = true ;
}
goto V_251;
}
int
F_70 ( const unsigned int V_109 , struct V_4 * V_5 )
{
struct V_267 * V_105 ;
int V_39 = 0 ;
struct V_18 * V_17 ;
struct V_42 * V_16 = V_5 -> V_16 ;
F_10 ( V_49 , L_41 ) ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
if ( ( V_5 -> V_63 ) || ( V_5 -> V_16 -> V_63 ) )
return 0 ;
V_39 = F_22 ( V_48 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_65 ( V_109 , V_16 , ( char * ) & V_105 -> V_2 , 0 ) ;
if ( V_39 )
F_66 ( V_5 , V_268 ) ;
return V_39 ;
}
static struct V_269 *
F_71 ( void )
{
struct V_269 * V_270 ;
V_270 = F_63 ( sizeof( struct V_269 ) , V_202 ) ;
if ( ! V_270 )
return NULL ;
V_270 -> V_271 . V_272 = F_4 ( F_58
( struct V_269 , V_273 ) ) ;
V_270 -> V_271 . V_91 = F_8 ( 16 ) ;
V_270 -> V_271 . V_274 = F_4 ( F_58
( struct V_269 , V_275 ) ) ;
V_270 -> V_271 . V_276 = F_4 ( 4 ) ;
V_270 -> V_275 [ 0 ] = 'D' ;
V_270 -> V_275 [ 1 ] = 'H' ;
V_270 -> V_275 [ 2 ] = 'n' ;
V_270 -> V_275 [ 3 ] = 'Q' ;
return V_270 ;
}
static struct V_269 *
F_72 ( struct V_277 * V_278 )
{
struct V_269 * V_270 ;
V_270 = F_63 ( sizeof( struct V_269 ) , V_202 ) ;
if ( ! V_270 )
return NULL ;
V_270 -> V_271 . V_272 = F_4 ( F_58
( struct V_269 , V_273 ) ) ;
V_270 -> V_271 . V_91 = F_8 ( 16 ) ;
V_270 -> V_271 . V_274 = F_4 ( F_58
( struct V_269 , V_275 ) ) ;
V_270 -> V_271 . V_276 = F_4 ( 4 ) ;
V_270 -> V_273 . V_279 . V_280 = V_278 -> V_281 ;
V_270 -> V_273 . V_279 . V_282 = V_278 -> V_283 ;
V_270 -> V_275 [ 0 ] = 'D' ;
V_270 -> V_275 [ 1 ] = 'H' ;
V_270 -> V_275 [ 2 ] = 'n' ;
V_270 -> V_275 [ 3 ] = 'C' ;
return V_270 ;
}
static T_6
F_73 ( struct V_18 * V_17 , struct V_284 * V_111 ,
unsigned int * V_285 )
{
char * V_286 ;
struct V_287 * V_288 ;
unsigned int V_289 ;
unsigned int V_290 ;
char * V_291 ;
V_286 = ( char * ) V_111 + 4 + F_36 ( V_111 -> V_292 ) ;
V_290 = F_36 ( V_111 -> V_293 ) ;
V_288 = (struct V_287 * ) V_286 ;
while ( V_290 >= sizeof( struct V_287 ) ) {
V_291 = F_2 ( V_288 -> V_274 ) + ( char * ) V_288 ;
if ( F_2 ( V_288 -> V_276 ) == 4 &&
strncmp ( V_291 , L_42 , 4 ) == 0 )
return V_17 -> V_181 -> V_294 ( V_288 , V_285 ) ;
V_289 = F_36 ( V_288 -> V_295 ) ;
if ( ! V_289 )
break;
V_290 -= V_289 ;
V_288 = (struct V_287 * ) ( ( char * ) V_288 + V_289 ) ;
}
return 0 ;
}
static int
F_74 ( struct V_18 * V_17 , struct V_112 * V_113 ,
unsigned int * V_296 , T_6 * V_297 )
{
struct V_298 * V_105 = V_113 [ 0 ] . V_138 ;
unsigned int V_299 = * V_296 ;
V_113 [ V_299 ] . V_138 = V_17 -> V_181 -> V_300 ( V_297 + 1 , * V_297 ) ;
if ( V_113 [ V_299 ] . V_138 == NULL )
return - V_81 ;
V_113 [ V_299 ] . V_139 = V_17 -> V_123 -> V_301 ;
V_105 -> V_302 = V_303 ;
if ( ! V_105 -> V_292 )
V_105 -> V_292 = F_8 (
sizeof( struct V_298 ) - 4 +
V_113 [ V_299 - 1 ] . V_139 ) ;
F_75 ( & V_105 -> V_293 ,
V_17 -> V_123 -> V_301 ) ;
F_30 ( & V_105 -> V_2 , V_17 -> V_123 -> V_301 ) ;
* V_296 = V_299 + 1 ;
return 0 ;
}
static struct V_304 *
F_76 ( struct V_277 * V_305 )
{
struct V_304 * V_270 ;
V_270 = F_63 ( sizeof( struct V_304 ) , V_202 ) ;
if ( ! V_270 )
return NULL ;
V_270 -> V_271 . V_272 = F_4 ( F_58
( struct V_304 , V_306 ) ) ;
V_270 -> V_271 . V_91 = F_8 ( sizeof( struct V_307 ) ) ;
V_270 -> V_271 . V_274 = F_4 ( F_58
( struct V_304 , V_275 ) ) ;
V_270 -> V_271 . V_276 = F_4 ( 4 ) ;
V_270 -> V_306 . V_308 = 0 ;
V_270 -> V_306 . V_35 = F_8 ( V_309 ) ;
F_77 ( V_270 -> V_306 . V_310 ) ;
memcpy ( V_305 -> V_311 , V_270 -> V_306 . V_310 , 16 ) ;
V_270 -> V_275 [ 0 ] = 'D' ;
V_270 -> V_275 [ 1 ] = 'H' ;
V_270 -> V_275 [ 2 ] = '2' ;
V_270 -> V_275 [ 3 ] = 'Q' ;
return V_270 ;
}
static struct V_312 *
F_78 ( struct V_277 * V_278 )
{
struct V_312 * V_270 ;
V_270 = F_63 ( sizeof( struct V_312 ) ,
V_202 ) ;
if ( ! V_270 )
return NULL ;
V_270 -> V_271 . V_272 =
F_4 ( F_58 ( struct V_312 ,
V_306 ) ) ;
V_270 -> V_271 . V_91 =
F_8 ( sizeof( struct V_313 ) ) ;
V_270 -> V_271 . V_274 =
F_4 ( F_58 ( struct V_312 ,
V_275 ) ) ;
V_270 -> V_271 . V_276 = F_4 ( 4 ) ;
V_270 -> V_306 . V_279 . V_280 = V_278 -> V_281 ;
V_270 -> V_306 . V_279 . V_282 = V_278 -> V_283 ;
V_270 -> V_306 . V_35 = F_8 ( V_309 ) ;
memcpy ( V_270 -> V_306 . V_310 , V_278 -> V_311 , 16 ) ;
V_270 -> V_275 [ 0 ] = 'D' ;
V_270 -> V_275 [ 1 ] = 'H' ;
V_270 -> V_275 [ 2 ] = '2' ;
V_270 -> V_275 [ 3 ] = 'C' ;
return V_270 ;
}
static int
F_79 ( struct V_112 * V_113 , unsigned int * V_296 ,
struct V_314 * V_315 )
{
struct V_298 * V_105 = V_113 [ 0 ] . V_138 ;
unsigned int V_299 = * V_296 ;
V_113 [ V_299 ] . V_138 = F_76 ( V_315 -> V_278 ) ;
if ( V_113 [ V_299 ] . V_138 == NULL )
return - V_81 ;
V_113 [ V_299 ] . V_139 = sizeof( struct V_304 ) ;
if ( ! V_105 -> V_292 )
V_105 -> V_292 =
F_8 ( sizeof( struct V_298 ) - 4 +
V_113 [ 1 ] . V_139 ) ;
F_75 ( & V_105 -> V_293 , sizeof( struct V_304 ) ) ;
F_30 ( & V_105 -> V_2 , sizeof( struct V_304 ) ) ;
* V_296 = V_299 + 1 ;
return 0 ;
}
static int
F_80 ( struct V_112 * V_113 , unsigned int * V_296 ,
struct V_314 * V_315 )
{
struct V_298 * V_105 = V_113 [ 0 ] . V_138 ;
unsigned int V_299 = * V_296 ;
V_315 -> V_70 = false ;
V_113 [ V_299 ] . V_138 = F_78 ( V_315 -> V_278 ) ;
if ( V_113 [ V_299 ] . V_138 == NULL )
return - V_81 ;
V_113 [ V_299 ] . V_139 = sizeof( struct V_312 ) ;
if ( ! V_105 -> V_292 )
V_105 -> V_292 =
F_8 ( sizeof( struct V_298 ) - 4 +
V_113 [ 1 ] . V_139 ) ;
F_75 ( & V_105 -> V_293 ,
sizeof( struct V_312 ) ) ;
F_30 ( & V_105 -> V_2 ,
sizeof( struct V_312 ) ) ;
* V_296 = V_299 + 1 ;
return 0 ;
}
static int
F_81 ( struct V_112 * V_113 , unsigned int * V_296 ,
struct V_314 * V_315 , bool V_65 )
{
struct V_298 * V_105 = V_113 [ 0 ] . V_138 ;
unsigned int V_299 = * V_296 ;
if ( V_65 ) {
if ( V_315 -> V_70 )
return F_80 ( V_113 , V_296 ,
V_315 ) ;
else
return F_79 ( V_113 , V_296 , V_315 ) ;
}
if ( V_315 -> V_70 ) {
V_113 [ V_299 ] . V_138 = F_72 ( V_315 -> V_278 ) ;
V_315 -> V_70 = false ;
} else
V_113 [ V_299 ] . V_138 = F_71 () ;
if ( V_113 [ V_299 ] . V_138 == NULL )
return - V_81 ;
V_113 [ V_299 ] . V_139 = sizeof( struct V_269 ) ;
if ( ! V_105 -> V_292 )
V_105 -> V_292 =
F_8 ( sizeof( struct V_298 ) - 4 +
V_113 [ 1 ] . V_139 ) ;
F_75 ( & V_105 -> V_293 , sizeof( struct V_269 ) ) ;
F_30 ( & V_105 -> V_2 , sizeof( struct V_269 ) ) ;
* V_296 = V_299 + 1 ;
return 0 ;
}
int
F_82 ( const unsigned int V_109 , struct V_314 * V_315 , T_1 * V_316 ,
T_6 * V_297 , struct V_317 * V_270 ,
struct V_318 * * V_319 )
{
struct V_298 * V_105 ;
struct V_284 * V_111 ;
struct V_18 * V_17 ;
struct V_4 * V_5 = V_315 -> V_5 ;
struct V_42 * V_16 = V_5 -> V_16 ;
struct V_112 V_113 [ 4 ] ;
int V_114 ;
int V_320 ;
T_1 * V_321 = NULL ;
int V_322 ;
int V_39 = 0 ;
unsigned int V_323 = 2 ;
T_7 V_324 = 0 ;
char * V_325 = NULL , * V_326 = NULL ;
F_10 ( V_49 , L_43 ) ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
V_39 = F_22 ( V_47 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
if ( V_315 -> V_327 & V_328 )
V_324 |= V_329 ;
if ( V_315 -> V_327 & V_330 )
V_324 |= V_331 ;
V_105 -> V_332 = V_333 ;
V_105 -> V_334 = F_8 ( V_315 -> V_335 ) ;
V_105 -> V_336 = F_8 ( V_324 ) ;
V_105 -> V_337 = V_338 ;
V_105 -> V_339 = F_8 ( V_315 -> V_340 ) ;
V_105 -> V_341 = F_8 ( V_315 -> V_327 & V_342 ) ;
V_320 = ( 2 * F_83 ( ( V_343 * ) V_316 , V_344 ) ) + 2 ;
V_105 -> V_274 = F_4 ( sizeof( struct V_298 ) - 4 ) ;
V_113 [ 0 ] . V_138 = ( char * ) V_105 ;
V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 ;
V_105 -> V_276 = F_4 ( V_320 - 2 ) ;
V_113 [ 0 ] . V_139 -- ;
if ( V_320 % 8 != 0 ) {
V_322 = V_320 / 8 * 8 ;
if ( V_322 < V_320 )
V_322 += 8 ;
V_321 = F_63 ( V_322 , V_202 ) ;
if ( ! V_321 )
return - V_81 ;
memcpy ( ( char * ) V_321 , ( const char * ) V_316 ,
V_320 ) ;
V_320 = V_322 ;
V_316 = V_321 ;
}
V_113 [ 1 ] . V_139 = V_320 ;
V_113 [ 1 ] . V_138 = V_316 ;
F_30 ( V_105 , V_320 - 1 ) ;
if ( ! V_17 -> V_345 )
* V_297 = V_346 ;
if ( ! ( V_17 -> V_27 & V_347 ) ||
* V_297 == V_346 )
V_105 -> V_302 = * V_297 ;
else {
V_39 = F_74 ( V_17 , V_113 , & V_323 , V_297 ) ;
if ( V_39 ) {
F_84 ( V_105 ) ;
F_47 ( V_321 ) ;
return V_39 ;
}
V_326 = V_113 [ V_323 - 1 ] . V_138 ;
}
if ( * V_297 == V_348 ) {
if ( V_17 -> V_27 & V_347 ) {
struct V_287 * V_271 =
(struct V_287 * ) V_113 [ V_323 - 1 ] . V_138 ;
V_271 -> V_295 =
F_8 ( V_17 -> V_123 -> V_301 ) ;
}
V_39 = F_81 ( V_113 , & V_323 , V_315 ,
V_5 -> V_65 ) ;
if ( V_39 ) {
F_84 ( V_105 ) ;
F_47 ( V_321 ) ;
F_47 ( V_326 ) ;
return V_39 ;
}
V_325 = V_113 [ V_323 - 1 ] . V_138 ;
}
V_39 = F_34 ( V_109 , V_16 , V_113 , V_323 , & V_114 , 0 ) ;
V_111 = (struct V_284 * ) V_113 [ 0 ] . V_138 ;
if ( V_39 != 0 ) {
F_66 ( V_5 , V_349 ) ;
if ( V_319 )
* V_319 = F_52 ( V_111 , F_33 ( V_111 ) + 4 ,
V_202 ) ;
goto V_350;
}
V_315 -> V_278 -> V_281 = V_111 -> V_280 ;
V_315 -> V_278 -> V_283 = V_111 -> V_282 ;
if ( V_270 ) {
memcpy ( V_270 , & V_111 -> V_351 , 32 ) ;
V_270 -> V_352 = V_111 -> V_352 ;
V_270 -> V_353 = V_111 -> V_354 ;
V_270 -> V_355 = V_111 -> V_336 ;
V_270 -> V_356 = F_8 ( 1 ) ;
V_270 -> V_357 = 0 ;
}
if ( V_111 -> V_358 == V_303 )
* V_297 = F_73 ( V_17 , V_111 , & V_315 -> V_278 -> V_285 ) ;
else
* V_297 = V_111 -> V_358 ;
V_350:
F_47 ( V_321 ) ;
F_47 ( V_326 ) ;
F_47 ( V_325 ) ;
F_40 ( V_114 , V_111 ) ;
return V_39 ;
}
int
F_42 ( const unsigned int V_109 , struct V_4 * V_5 , T_8 V_281 ,
T_8 V_283 , T_4 V_359 , bool V_360 , char * V_361 ,
T_4 V_362 , char * * V_363 , T_4 * V_364 )
{
struct V_365 * V_105 ;
struct V_366 * V_111 ;
struct V_18 * V_17 ;
struct V_42 * V_16 ;
struct V_112 V_113 [ 2 ] ;
int V_114 ;
int V_323 ;
int V_39 = 0 ;
F_10 ( V_49 , L_44 ) ;
if ( V_363 != NULL )
* V_363 = NULL ;
if ( V_364 )
* V_364 = 0 ;
if ( V_5 )
V_16 = V_5 -> V_16 ;
else
return - V_52 ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
V_39 = F_22 ( V_75 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
V_105 -> V_367 = F_8 ( V_359 ) ;
V_105 -> V_280 = V_281 ;
V_105 -> V_282 = V_283 ;
if ( V_362 ) {
V_105 -> V_368 = F_8 ( V_362 ) ;
V_105 -> V_369 =
F_8 ( F_58 ( struct V_365 , V_220 ) - 4 ) ;
V_113 [ 1 ] . V_138 = V_361 ;
V_113 [ 1 ] . V_139 = V_362 ;
V_323 = 2 ;
} else
V_323 = 1 ;
V_105 -> V_370 = 0 ;
V_105 -> V_371 = 0 ;
V_105 -> V_372 = F_8 ( 0xFF00 ) ;
if ( V_360 )
V_105 -> V_35 = F_8 ( V_373 ) ;
else
V_105 -> V_35 = 0 ;
V_113 [ 0 ] . V_138 = ( char * ) V_105 ;
if ( V_362 ) {
V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 - 1 ;
F_30 ( V_105 , V_362 - 1 ) ;
} else
V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 ;
V_39 = F_34 ( V_109 , V_16 , V_113 , V_323 , & V_114 , 0 ) ;
V_111 = (struct V_366 * ) V_113 [ 0 ] . V_138 ;
if ( ( V_39 != 0 ) && ( V_39 != - V_245 ) ) {
F_66 ( V_5 , V_374 ) ;
goto V_375;
} else if ( V_39 == - V_245 ) {
if ( ( V_359 != V_376 ) &&
( V_359 != V_377 ) ) {
F_66 ( V_5 , V_374 ) ;
goto V_375;
}
}
if ( ( V_364 == NULL ) || ( V_363 == NULL ) )
goto V_375;
* V_364 = F_36 ( V_111 -> V_371 ) ;
if ( * V_364 == 0 )
goto V_375;
else if ( * V_364 > 0xFF00 ) {
F_10 ( V_145 , L_45 , * V_364 ) ;
* V_364 = 0 ;
V_39 = - V_52 ;
goto V_375;
}
if ( F_33 ( V_111 ) < F_36 ( V_111 -> V_370 ) + * V_364 ) {
F_10 ( V_145 , L_46 , * V_364 ,
F_36 ( V_111 -> V_370 ) ) ;
* V_364 = 0 ;
V_39 = - V_52 ;
goto V_375;
}
* V_363 = F_56 ( * V_364 , V_202 ) ;
if ( * V_363 == NULL ) {
V_39 = - V_81 ;
goto V_375;
}
memcpy ( * V_363 ,
( char * ) & V_111 -> V_2 . V_12 + F_36 ( V_111 -> V_370 ) ,
* V_364 ) ;
V_375:
F_40 ( V_114 , V_111 ) ;
return V_39 ;
}
int
F_85 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_8 V_281 , T_8 V_283 )
{
int V_39 ;
struct V_378 V_379 ;
char * V_380 = NULL ;
V_379 . V_381 =
F_4 ( V_382 ) ;
V_39 = F_42 ( V_109 , V_5 , V_281 , V_283 ,
V_383 , true ,
( char * ) & V_379 ,
2 , & V_380 , NULL ) ;
F_10 ( V_49 , L_47 , V_39 ) ;
return V_39 ;
}
int
F_86 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_8 V_281 , T_8 V_283 )
{
struct V_384 * V_105 ;
struct V_385 * V_111 ;
struct V_18 * V_17 ;
struct V_42 * V_16 = V_5 -> V_16 ;
struct V_112 V_113 [ 1 ] ;
int V_114 ;
int V_39 = 0 ;
F_10 ( V_49 , L_48 ) ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
V_39 = F_22 ( V_56 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
V_105 -> V_280 = V_281 ;
V_105 -> V_282 = V_283 ;
V_113 [ 0 ] . V_138 = ( char * ) V_105 ;
V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 ;
V_39 = F_34 ( V_109 , V_16 , V_113 , 1 , & V_114 , 0 ) ;
V_111 = (struct V_385 * ) V_113 [ 0 ] . V_138 ;
if ( V_39 != 0 ) {
F_66 ( V_5 , V_386 ) ;
goto V_387;
}
V_387:
F_40 ( V_114 , V_111 ) ;
return V_39 ;
}
static int
F_87 ( unsigned int V_388 , unsigned int V_389 ,
struct V_1 * V_2 , unsigned int V_390 )
{
unsigned int V_391 = F_88 ( V_2 -> V_11 ) ;
char * V_392 = V_391 + 4 + ( char * ) V_2 ;
char * V_393 = 4 + V_388 + ( char * ) V_2 ;
char * V_394 = V_393 + V_389 ;
if ( V_389 < V_390 ) {
F_10 ( V_145 , L_49 ,
V_389 , V_390 ) ;
return - V_245 ;
}
if ( ( V_391 > 0x7FFFFF ) || ( V_389 > 0x7FFFFF ) ) {
F_10 ( V_145 , L_50 ,
V_389 , V_391 ) ;
return - V_245 ;
}
if ( ( V_393 > V_392 ) || ( V_394 > V_392 ) ) {
F_10 ( V_145 , L_51 ) ;
return - V_245 ;
}
return 0 ;
}
static int
F_89 ( unsigned int V_388 , unsigned int V_389 ,
struct V_1 * V_2 , unsigned int V_395 ,
char * V_196 )
{
char * V_393 = 4 + V_388 + ( char * ) V_2 ;
int V_39 ;
if ( ! V_196 )
return - V_245 ;
V_39 = F_87 ( V_388 , V_389 , V_2 , V_395 ) ;
if ( V_39 )
return V_39 ;
memcpy ( V_196 , V_393 , V_389 ) ;
return 0 ;
}
static int
F_90 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_8 V_281 , T_8 V_283 , T_9 V_396 ,
T_10 V_397 , T_10 V_398 , void * V_196 )
{
struct V_399 * V_105 ;
struct V_400 * V_111 = NULL ;
struct V_112 V_113 [ 2 ] ;
int V_39 = 0 ;
int V_114 ;
struct V_18 * V_17 ;
struct V_42 * V_16 = V_5 -> V_16 ;
F_10 ( V_49 , L_52 ) ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
V_39 = F_22 ( V_78 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
V_105 -> V_401 = V_402 ;
V_105 -> V_403 = V_396 ;
V_105 -> V_280 = V_281 ;
V_105 -> V_282 = V_283 ;
V_105 -> V_404 =
F_4 ( sizeof( struct V_399 ) - 1 - 4 ) ;
V_105 -> V_405 = F_8 ( V_397 ) ;
V_113 [ 0 ] . V_138 = ( char * ) V_105 ;
V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 ;
V_39 = F_34 ( V_109 , V_16 , V_113 , 1 , & V_114 , 0 ) ;
V_111 = (struct V_400 * ) V_113 [ 0 ] . V_138 ;
if ( V_39 ) {
F_66 ( V_5 , V_406 ) ;
goto V_407;
}
V_39 = F_89 ( F_2 ( V_111 -> V_408 ) ,
F_36 ( V_111 -> V_405 ) ,
& V_111 -> V_2 , V_398 , V_196 ) ;
V_407:
F_40 ( V_114 , V_111 ) ;
return V_39 ;
}
int
F_91 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_8 V_281 , T_8 V_283 ,
struct V_317 * V_196 )
{
return F_90 ( V_109 , V_5 , V_281 , V_283 ,
V_409 ,
sizeof( struct V_317 ) + V_344 * 2 ,
sizeof( struct V_317 ) , V_196 ) ;
}
int
F_92 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_8 V_281 , T_8 V_283 , T_11 * V_410 )
{
return F_90 ( V_109 , V_5 , V_281 , V_283 ,
V_411 ,
sizeof( struct V_412 ) ,
sizeof( struct V_412 ) , V_410 ) ;
}
static void
F_93 ( struct V_413 * V_414 )
{
struct V_18 * V_17 = V_414 -> V_415 ;
struct V_416 * V_417 = (struct V_416 * ) V_414 -> V_418 ;
unsigned int V_419 = 1 ;
if ( V_414 -> V_420 == V_421 )
V_419 = F_2 ( V_417 -> V_2 . V_22 ) ;
F_13 ( & V_17 -> V_180 ) ;
F_94 ( V_414 ) ;
F_16 ( & V_17 -> V_180 ) ;
F_95 ( V_17 , V_419 , V_422 ) ;
}
void F_96 ( struct V_423 * V_424 )
{
struct V_18 * V_17 = F_97 ( V_424 ,
struct V_18 , V_70 . V_424 ) ;
struct V_42 * V_16 ;
struct V_4 * V_5 , * V_425 ;
struct V_426 V_427 ;
int V_428 = false ;
F_13 ( & V_17 -> V_429 ) ;
F_98 ( & V_427 ) ;
F_10 ( V_49 , L_53 ) ;
F_5 ( & V_430 ) ;
F_99 (ses, &server->smb_ses_list, smb_ses_list) {
F_99 (tcon, &ses->tcon_list, tcon_list) {
if ( V_5 -> V_63 || V_5 -> V_66 ) {
V_5 -> V_431 ++ ;
F_100 ( & V_5 -> V_432 , & V_427 ) ;
V_428 = true ;
}
}
}
if ( V_428 )
V_17 -> V_433 ++ ;
F_7 ( & V_430 ) ;
F_101 (tcon, tcon2, &tmp_list, rlist) {
if ( ! F_9 ( V_68 , V_5 ) )
F_102 ( V_5 ) ;
F_103 ( & V_5 -> V_432 ) ;
F_104 ( V_5 ) ;
}
F_10 ( V_49 , L_54 ) ;
F_16 ( & V_17 -> V_429 ) ;
if ( V_428 )
F_105 ( V_17 , 1 ) ;
}
int
F_106 ( struct V_18 * V_17 )
{
struct V_434 * V_105 ;
int V_39 = 0 ;
struct V_112 V_113 ;
struct V_435 V_436 = { . V_437 = & V_113 ,
. V_438 = 1 } ;
F_10 ( V_49 , L_55 ) ;
if ( V_17 -> V_53 == V_439 ) {
F_19 ( V_69 , & V_17 -> V_70 , 0 ) ;
return V_39 ;
}
V_39 = F_22 ( V_440 , NULL , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
V_105 -> V_2 . V_22 = F_4 ( 1 ) ;
V_113 . V_138 = ( char * ) V_105 ;
V_113 . V_139 = F_33 ( V_105 ) + 4 ;
V_39 = F_107 ( V_17 , & V_436 , NULL , F_93 , V_17 ,
V_422 ) ;
if ( V_39 )
F_10 ( V_49 , L_56 , V_39 ) ;
F_84 ( V_105 ) ;
return V_39 ;
}
int
F_108 ( const unsigned int V_109 , struct V_4 * V_5 , T_8 V_281 ,
T_8 V_283 )
{
struct V_441 * V_105 ;
struct V_18 * V_17 ;
struct V_42 * V_16 = V_5 -> V_16 ;
struct V_112 V_113 [ 1 ] ;
int V_114 ;
int V_39 = 0 ;
F_10 ( V_49 , L_57 ) ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
V_39 = F_22 ( V_72 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
V_105 -> V_280 = V_281 ;
V_105 -> V_282 = V_283 ;
V_113 [ 0 ] . V_138 = ( char * ) V_105 ;
V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 ;
V_39 = F_34 ( V_109 , V_16 , V_113 , 1 , & V_114 , 0 ) ;
if ( V_39 != 0 )
F_66 ( V_5 , V_442 ) ;
F_40 ( V_114 , V_113 [ 0 ] . V_138 ) ;
return V_39 ;
}
static int
F_109 ( struct V_112 * V_113 , struct V_443 * V_444 ,
unsigned int V_445 , int V_446 )
{
int V_39 = - V_447 ;
struct V_448 * V_105 = NULL ;
V_39 = F_22 ( V_73 , V_444 -> V_5 , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
if ( V_444 -> V_5 -> V_16 -> V_17 == NULL )
return - V_449 ;
V_105 -> V_2 . V_23 = F_8 ( V_444 -> V_450 ) ;
V_105 -> V_280 = V_444 -> V_281 ;
V_105 -> V_282 = V_444 -> V_283 ;
V_105 -> V_451 = 0 ;
V_105 -> V_452 = 0 ;
V_105 -> V_173 = 0 ;
V_105 -> V_453 = 0 ;
V_105 -> V_454 = F_8 ( V_444 -> V_455 ) ;
V_105 -> V_456 = F_110 ( V_444 -> V_388 ) ;
if ( V_446 & V_457 ) {
if ( ! ( V_446 & V_458 ) ) {
V_105 -> V_2 . V_459 =
F_8 ( F_33 ( V_105 ) + 4 ) ;
} else
V_105 -> V_2 . V_459 = 0 ;
if ( V_446 & V_460 ) {
V_105 -> V_2 . V_35 |= V_461 ;
V_105 -> V_2 . V_32 = 0xFFFFFFFF ;
V_105 -> V_2 . V_30 = 0xFFFFFFFF ;
V_105 -> V_280 = 0xFFFFFFFF ;
V_105 -> V_282 = 0xFFFFFFFF ;
}
}
if ( V_445 > V_444 -> V_455 )
V_105 -> V_462 = F_8 ( V_445 ) ;
else
V_105 -> V_462 = 0 ;
V_113 [ 0 ] . V_138 = ( char * ) V_105 ;
V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 ;
return V_39 ;
}
static void
F_111 ( struct V_413 * V_414 )
{
struct V_463 * V_464 = V_414 -> V_415 ;
struct V_4 * V_5 = F_112 ( V_464 -> V_465 -> V_466 ) ;
struct V_18 * V_17 = V_5 -> V_16 -> V_17 ;
struct V_1 * V_270 = (struct V_1 * ) V_464 -> V_113 . V_138 ;
unsigned int V_419 = 1 ;
struct V_435 V_436 = { . V_437 = & V_464 -> V_113 ,
. V_438 = 1 ,
. V_467 = V_464 -> V_468 ,
. V_469 = V_464 -> V_470 ,
. V_471 = V_464 -> V_472 ,
. V_473 = V_464 -> V_474 } ;
F_10 ( V_49 , L_58 ,
V_120 , V_414 -> V_414 , V_414 -> V_420 , V_464 -> V_208 ,
V_464 -> V_475 ) ;
switch ( V_414 -> V_420 ) {
case V_421 :
V_419 = F_2 ( V_270 -> V_22 ) ;
if ( V_17 -> V_34 ) {
int V_39 ;
V_39 = F_113 ( & V_436 , V_17 ) ;
if ( V_39 )
F_10 ( V_145 , L_59 ,
V_39 ) ;
}
F_114 ( V_464 -> V_476 ) ;
F_115 ( V_5 , V_464 -> V_476 ) ;
break;
case V_477 :
case V_478 :
V_464 -> V_208 = - V_58 ;
if ( V_17 -> V_34 && V_464 -> V_476 )
V_464 -> V_476 = 0 ;
F_114 ( V_464 -> V_476 ) ;
F_115 ( V_5 , V_464 -> V_476 ) ;
break;
default:
if ( V_464 -> V_208 != - V_479 )
V_464 -> V_208 = - V_52 ;
}
if ( V_464 -> V_208 )
F_66 ( V_5 , V_480 ) ;
F_116 ( V_69 , & V_464 -> V_424 ) ;
F_13 ( & V_17 -> V_180 ) ;
F_94 ( V_414 ) ;
F_16 ( & V_17 -> V_180 ) ;
F_95 ( V_17 , V_419 , 0 ) ;
}
int
F_117 ( struct V_463 * V_464 )
{
int V_39 , V_118 = 0 ;
struct V_1 * V_270 ;
struct V_443 V_444 ;
struct V_435 V_436 = { . V_437 = & V_464 -> V_113 ,
. V_438 = 1 } ;
struct V_18 * V_17 ;
F_10 ( V_49 , L_60 ,
V_120 , V_464 -> V_388 , V_464 -> V_475 ) ;
V_444 . V_5 = F_112 ( V_464 -> V_465 -> V_466 ) ;
V_444 . V_388 = V_464 -> V_388 ;
V_444 . V_455 = V_464 -> V_475 ;
V_444 . V_281 = V_464 -> V_465 -> V_278 . V_281 ;
V_444 . V_283 = V_464 -> V_465 -> V_278 . V_283 ;
V_444 . V_450 = V_464 -> V_450 ;
V_17 = V_444 . V_5 -> V_16 -> V_17 ;
V_39 = F_109 ( & V_464 -> V_113 , & V_444 , 0 , 0 ) ;
if ( V_39 ) {
if ( V_39 == - V_58 && V_464 -> V_20 ) {
V_464 -> V_20 = 0 ;
F_5 ( & V_17 -> V_19 ) ;
V_17 -> V_481 -- ;
F_7 ( & V_17 -> V_19 ) ;
}
return V_39 ;
}
V_270 = (struct V_1 * ) V_464 -> V_113 . V_138 ;
V_464 -> V_113 . V_139 = F_33 ( V_464 -> V_113 . V_138 ) + 4 ;
if ( V_464 -> V_20 ) {
V_270 -> V_29 = F_4 ( F_118 ( V_464 -> V_475 ,
V_482 ) ) ;
V_270 -> V_22 = V_270 -> V_29 ;
F_5 ( & V_17 -> V_19 ) ;
V_17 -> V_20 += V_464 -> V_20 -
F_2 ( V_270 -> V_29 ) ;
F_7 ( & V_17 -> V_19 ) ;
F_119 ( & V_17 -> V_483 ) ;
V_118 = V_484 ;
}
F_120 ( & V_464 -> V_485 ) ;
V_39 = F_107 ( V_444 . V_5 -> V_16 -> V_17 , & V_436 ,
V_486 , F_111 ,
V_464 , V_118 ) ;
if ( V_39 ) {
F_121 ( & V_464 -> V_485 , V_487 ) ;
F_66 ( V_444 . V_5 , V_480 ) ;
}
F_84 ( V_270 ) ;
return V_39 ;
}
int
F_122 ( const unsigned int V_109 , struct V_443 * V_444 ,
unsigned int * V_488 , char * * V_270 , int * V_489 )
{
int V_114 , V_39 = - V_447 ;
struct V_490 * V_111 = NULL ;
struct V_112 V_113 [ 1 ] ;
* V_488 = 0 ;
V_39 = F_109 ( V_113 , V_444 , 0 , 0 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_34 ( V_109 , V_444 -> V_5 -> V_16 , V_113 , 1 ,
& V_114 , V_179 ) ;
V_111 = (struct V_490 * ) V_113 [ 0 ] . V_138 ;
if ( V_111 -> V_2 . V_218 == V_491 ) {
F_40 ( V_114 , V_113 [ 0 ] . V_138 ) ;
return 0 ;
}
if ( V_39 ) {
F_66 ( V_444 -> V_5 , V_480 ) ;
F_10 ( V_145 , L_61 , V_39 ) ;
} else {
* V_488 = F_36 ( V_111 -> V_91 ) ;
if ( ( * V_488 > V_492 ) ||
( * V_488 > V_444 -> V_455 ) ) {
F_10 ( V_49 , L_62 ,
* V_488 , V_444 -> V_455 ) ;
V_39 = - V_52 ;
* V_488 = 0 ;
}
}
if ( * V_270 ) {
memcpy ( * V_270 , ( char * ) & V_111 -> V_2 . V_12 + V_111 -> V_272 ,
* V_488 ) ;
F_40 ( V_114 , V_113 [ 0 ] . V_138 ) ;
} else if ( V_114 != V_176 ) {
* V_270 = V_113 [ 0 ] . V_138 ;
if ( V_114 == V_175 )
* V_489 = V_175 ;
else if ( V_114 == V_493 )
* V_489 = V_493 ;
}
return V_39 ;
}
static void
F_123 ( struct V_413 * V_414 )
{
struct V_494 * V_495 = V_414 -> V_415 ;
struct V_4 * V_5 = F_112 ( V_495 -> V_465 -> V_466 ) ;
struct V_18 * V_17 = V_5 -> V_16 -> V_17 ;
unsigned int V_496 ;
struct V_497 * V_111 = (struct V_497 * ) V_414 -> V_418 ;
unsigned int V_419 = 1 ;
switch ( V_414 -> V_420 ) {
case V_421 :
V_419 = F_2 ( V_111 -> V_2 . V_22 ) ;
V_495 -> V_208 = F_124 ( V_414 , V_5 -> V_16 -> V_17 , 0 ) ;
if ( V_495 -> V_208 != 0 )
break;
V_496 = F_36 ( V_111 -> V_91 ) ;
if ( V_496 > V_495 -> V_475 )
V_496 &= 0xFFFF ;
if ( V_496 < V_495 -> V_475 )
V_495 -> V_208 = - V_498 ;
else
V_495 -> V_475 = V_496 ;
break;
case V_477 :
case V_478 :
V_495 -> V_208 = - V_58 ;
break;
default:
V_495 -> V_208 = - V_52 ;
break;
}
if ( V_495 -> V_208 )
F_66 ( V_5 , V_499 ) ;
F_116 ( V_69 , & V_495 -> V_424 ) ;
F_13 ( & V_17 -> V_180 ) ;
F_94 ( V_414 ) ;
F_16 ( & V_17 -> V_180 ) ;
F_95 ( V_5 -> V_16 -> V_17 , V_419 , 0 ) ;
}
int
F_125 ( struct V_494 * V_495 ,
void (* F_126)( struct V_500 * V_500 ) )
{
int V_39 = - V_447 , V_118 = 0 ;
struct V_501 * V_105 = NULL ;
struct V_4 * V_5 = F_112 ( V_495 -> V_465 -> V_466 ) ;
struct V_18 * V_17 = V_5 -> V_16 -> V_17 ;
struct V_112 V_113 ;
struct V_435 V_436 ;
V_39 = F_22 ( V_46 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 ) {
if ( V_39 == - V_58 && V_495 -> V_20 ) {
V_495 -> V_20 = 0 ;
F_5 ( & V_17 -> V_19 ) ;
V_17 -> V_481 -- ;
F_7 ( & V_17 -> V_19 ) ;
}
goto V_502;
}
V_105 -> V_2 . V_23 = F_8 ( V_495 -> V_465 -> V_450 ) ;
V_105 -> V_280 = V_495 -> V_465 -> V_278 . V_281 ;
V_105 -> V_282 = V_495 -> V_465 -> V_278 . V_283 ;
V_105 -> V_503 = 0 ;
V_105 -> V_504 = 0 ;
V_105 -> V_173 = 0 ;
V_105 -> V_456 = F_110 ( V_495 -> V_388 ) ;
V_105 -> V_272 = F_4 (
F_58 ( struct V_501 , V_220 ) - 4 ) ;
V_105 -> V_462 = 0 ;
V_113 . V_139 = F_33 ( V_105 ) + 4 - 1 ;
V_113 . V_138 = V_105 ;
V_436 . V_437 = & V_113 ;
V_436 . V_438 = 1 ;
V_436 . V_467 = V_495 -> V_468 ;
V_436 . V_469 = V_495 -> V_470 ;
V_436 . V_471 = V_495 -> V_472 ;
V_436 . V_473 = V_495 -> V_474 ;
F_10 ( V_49 , L_63 ,
V_495 -> V_388 , V_495 -> V_475 ) ;
V_105 -> V_454 = F_8 ( V_495 -> V_475 ) ;
F_30 ( & V_105 -> V_2 , V_495 -> V_475 - 1 ) ;
if ( V_495 -> V_20 ) {
V_105 -> V_2 . V_29 = F_4 ( F_118 ( V_495 -> V_475 ,
V_482 ) ) ;
V_105 -> V_2 . V_22 = V_105 -> V_2 . V_29 ;
F_5 ( & V_17 -> V_19 ) ;
V_17 -> V_20 += V_495 -> V_20 -
F_2 ( V_105 -> V_2 . V_29 ) ;
F_7 ( & V_17 -> V_19 ) ;
F_119 ( & V_17 -> V_483 ) ;
V_118 = V_484 ;
}
F_120 ( & V_495 -> V_485 ) ;
V_39 = F_107 ( V_17 , & V_436 , NULL , F_123 , V_495 ,
V_118 ) ;
if ( V_39 ) {
F_121 ( & V_495 -> V_485 , F_126 ) ;
F_66 ( V_5 , V_499 ) ;
}
V_502:
F_84 ( V_105 ) ;
return V_39 ;
}
int
F_127 ( const unsigned int V_109 , struct V_443 * V_444 ,
unsigned int * V_488 , struct V_112 * V_113 , int V_505 )
{
int V_39 = 0 ;
struct V_501 * V_105 = NULL ;
struct V_497 * V_111 = NULL ;
int V_114 ;
* V_488 = 0 ;
if ( V_505 < 1 )
return V_39 ;
V_39 = F_22 ( V_46 , V_444 -> V_5 , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
if ( V_444 -> V_5 -> V_16 -> V_17 == NULL )
return - V_449 ;
V_105 -> V_2 . V_23 = F_8 ( V_444 -> V_450 ) ;
V_105 -> V_280 = V_444 -> V_281 ;
V_105 -> V_282 = V_444 -> V_283 ;
V_105 -> V_503 = 0 ;
V_105 -> V_504 = 0 ;
V_105 -> V_173 = 0 ;
V_105 -> V_454 = F_8 ( V_444 -> V_455 ) ;
V_105 -> V_456 = F_110 ( V_444 -> V_388 ) ;
V_105 -> V_272 = F_4 (
F_58 ( struct V_501 , V_220 ) - 4 ) ;
V_105 -> V_462 = 0 ;
V_113 [ 0 ] . V_138 = ( char * ) V_105 ;
V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 - 1 ;
F_30 ( V_105 , V_444 -> V_455 - 1 ) ;
V_39 = F_34 ( V_109 , V_444 -> V_5 -> V_16 , V_113 , V_505 + 1 ,
& V_114 , 0 ) ;
V_111 = (struct V_497 * ) V_113 [ 0 ] . V_138 ;
if ( V_39 ) {
F_66 ( V_444 -> V_5 , V_499 ) ;
F_10 ( V_145 , L_64 , V_39 ) ;
} else
* V_488 = F_36 ( V_111 -> V_91 ) ;
F_40 ( V_114 , V_111 ) ;
return V_39 ;
}
static unsigned int
F_128 ( char * V_506 , char * V_394 , char * * V_507 , T_10 V_508 )
{
int V_203 ;
unsigned int V_509 = 0 ;
unsigned int V_510 = 0 ;
T_12 * V_511 ;
if ( V_506 == NULL )
return 0 ;
V_511 = ( T_12 * ) V_506 ;
while ( 1 ) {
V_511 = ( T_12 * )
( ( char * ) V_511 + V_510 ) ;
if ( ( char * ) V_511 + V_508 > V_394 ) {
F_10 ( V_145 , L_65 ) ;
break;
}
V_203 = F_36 ( V_511 -> V_512 ) ;
if ( ( char * ) V_511 + V_203 + V_508 > V_394 ) {
F_10 ( V_145 , L_66 ,
V_394 ) ;
break;
}
* V_507 = ( char * ) V_511 ;
V_509 ++ ;
V_510 = F_36 ( V_511 -> V_513 ) ;
if ( ! V_510 )
break;
}
return V_509 ;
}
int
F_129 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_8 V_281 , T_8 V_283 , int V_514 ,
struct V_515 * V_516 )
{
struct V_517 * V_105 ;
struct V_518 * V_111 = NULL ;
struct V_112 V_113 [ 2 ] ;
int V_39 = 0 ;
int V_203 ;
int V_114 = V_176 ;
unsigned char * V_519 ;
struct V_18 * V_17 ;
struct V_42 * V_16 = V_5 -> V_16 ;
T_1 V_520 = F_4 ( '*' ) ;
char * V_392 ;
unsigned int V_521 = V_522 ;
T_10 V_523 ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
V_39 = F_22 ( V_76 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
switch ( V_516 -> V_524 ) {
case V_525 :
V_105 -> V_526 = V_527 ;
V_523 = sizeof( T_12 ) - 1 ;
break;
case V_528 :
V_105 -> V_526 = V_529 ;
V_523 = sizeof( V_530 ) - 1 ;
break;
default:
F_10 ( V_145 , L_67 ,
V_516 -> V_524 ) ;
V_39 = - V_245 ;
goto V_531;
}
V_105 -> V_532 = F_8 ( V_514 ) ;
V_105 -> V_280 = V_281 ;
V_105 -> V_282 = V_283 ;
V_203 = 0x2 ;
V_519 = V_105 -> V_220 ;
memcpy ( V_519 , & V_520 , V_203 ) ;
V_105 -> V_533 =
F_4 ( sizeof( struct V_517 ) - 1 - 4 ) ;
V_105 -> V_512 = F_4 ( V_203 ) ;
V_521 = F_6 (unsigned int, output_size, server->maxBuf) ;
V_521 = F_6 (unsigned int, output_size, 2 << 15 ) ;
V_105 -> V_405 = F_8 ( V_521 ) ;
V_113 [ 0 ] . V_138 = ( char * ) V_105 ;
V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 - 1 ;
V_113 [ 1 ] . V_138 = ( char * ) ( V_105 -> V_220 ) ;
V_113 [ 1 ] . V_139 = V_203 ;
F_30 ( V_105 , V_203 - 1 ) ;
V_39 = F_34 ( V_109 , V_16 , V_113 , 2 , & V_114 , 0 ) ;
V_111 = (struct V_518 * ) V_113 [ 0 ] . V_138 ;
if ( V_39 ) {
if ( V_39 == - V_479 && V_111 -> V_2 . V_218 == V_534 ) {
V_516 -> V_535 = true ;
V_39 = 0 ;
}
F_66 ( V_5 , V_536 ) ;
goto V_531;
}
V_39 = F_87 ( F_2 ( V_111 -> V_408 ) ,
F_36 ( V_111 -> V_405 ) , & V_111 -> V_2 ,
V_523 ) ;
if ( V_39 )
goto V_531;
V_516 -> V_537 = true ;
if ( V_516 -> V_538 ) {
if ( V_516 -> V_539 )
F_84 ( V_516 -> V_538 ) ;
else
F_130 ( V_516 -> V_538 ) ;
}
V_516 -> V_538 = ( char * ) V_111 ;
V_516 -> V_540 = V_516 -> V_541 = 4 +
( char * ) & V_111 -> V_2 + F_2 ( V_111 -> V_408 ) ;
V_392 = F_33 ( V_111 ) + 4 + ( char * ) & V_111 -> V_2 ;
V_516 -> V_542 =
F_128 ( V_516 -> V_540 , V_392 ,
& V_516 -> V_541 , V_523 ) ;
V_516 -> V_543 += V_516 -> V_542 ;
F_10 ( V_49 , L_68 ,
V_516 -> V_542 , V_516 -> V_543 ,
V_516 -> V_540 , V_516 -> V_541 ) ;
if ( V_114 == V_493 )
V_516 -> V_539 = false ;
else if ( V_114 == V_175 )
V_516 -> V_539 = true ;
else
F_10 ( V_145 , L_69 ) ;
return V_39 ;
V_531:
F_40 ( V_114 , V_111 ) ;
return V_39 ;
}
static int
F_131 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_8 V_281 , T_8 V_283 , T_4 V_450 , int V_396 ,
unsigned int V_299 , void * * V_196 , unsigned int * V_508 )
{
struct V_544 * V_105 ;
struct V_545 * V_111 = NULL ;
struct V_112 * V_113 ;
int V_39 = 0 ;
int V_114 ;
unsigned int V_546 ;
struct V_18 * V_17 ;
struct V_42 * V_16 = V_5 -> V_16 ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
if ( ! V_299 )
return - V_245 ;
V_113 = F_56 ( sizeof( struct V_112 ) * V_299 , V_202 ) ;
if ( ! V_113 )
return - V_81 ;
V_39 = F_22 ( V_79 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 ) {
F_47 ( V_113 ) ;
return V_39 ;
}
V_105 -> V_2 . V_23 = F_8 ( V_450 ) ;
V_105 -> V_401 = V_402 ;
V_105 -> V_403 = V_396 ;
V_105 -> V_280 = V_281 ;
V_105 -> V_282 = V_283 ;
V_105 -> V_547 =
F_4 ( sizeof( struct V_544 ) - 1 - 4 ) ;
V_105 -> V_548 = F_8 ( * V_508 ) ;
F_30 ( V_105 , * V_508 - 1 ) ;
memcpy ( V_105 -> V_220 , * V_196 , * V_508 ) ;
V_113 [ 0 ] . V_138 = ( char * ) V_105 ;
V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 ;
for ( V_546 = 1 ; V_546 < V_299 ; V_546 ++ ) {
F_30 ( V_105 , V_508 [ V_546 ] ) ;
F_75 ( & V_105 -> V_548 , V_508 [ V_546 ] ) ;
V_113 [ V_546 ] . V_138 = ( char * ) V_196 [ V_546 ] ;
V_113 [ V_546 ] . V_139 = V_508 [ V_546 ] ;
}
V_39 = F_34 ( V_109 , V_16 , V_113 , V_299 , & V_114 , 0 ) ;
V_111 = (struct V_545 * ) V_113 [ 0 ] . V_138 ;
if ( V_39 != 0 )
F_66 ( V_5 , V_549 ) ;
F_40 ( V_114 , V_111 ) ;
F_47 ( V_113 ) ;
return V_39 ;
}
int
F_132 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_8 V_281 , T_8 V_283 , T_1 * V_550 )
{
struct V_551 V_552 ;
void * * V_196 ;
unsigned int V_508 [ 2 ] ;
int V_39 ;
int V_203 = ( 2 * F_83 ( ( V_343 * ) V_550 , V_344 ) ) ;
V_196 = F_56 ( sizeof( void * ) * 2 , V_202 ) ;
if ( ! V_196 )
return - V_81 ;
V_552 . V_553 = 1 ;
V_552 . V_554 = 0 ;
V_552 . V_512 = F_8 ( V_203 ) ;
V_196 [ 0 ] = & V_552 ;
V_508 [ 0 ] = sizeof( struct V_551 ) ;
V_196 [ 1 ] = V_550 ;
V_508 [ 1 ] = V_203 + 2 ;
V_39 = F_131 ( V_109 , V_5 , V_281 , V_283 ,
V_24 -> V_25 , V_555 , 2 , V_196 ,
V_508 ) ;
F_47 ( V_196 ) ;
return V_39 ;
}
int
F_133 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_8 V_281 , T_8 V_283 )
{
T_6 V_556 = 1 ;
void * V_196 ;
unsigned int V_508 ;
V_196 = & V_556 ;
V_508 = 1 ;
return F_131 ( V_109 , V_5 , V_281 , V_283 ,
V_24 -> V_25 , V_557 , 1 , & V_196 ,
& V_508 ) ;
}
int
F_134 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_8 V_281 , T_8 V_283 , T_1 * V_550 )
{
struct V_558 V_552 ;
void * * V_196 ;
unsigned int V_508 [ 2 ] ;
int V_39 ;
int V_203 = ( 2 * F_83 ( ( V_343 * ) V_550 , V_344 ) ) ;
V_196 = F_56 ( sizeof( void * ) * 2 , V_202 ) ;
if ( ! V_196 )
return - V_81 ;
V_552 . V_553 = 0 ;
V_552 . V_554 = 0 ;
V_552 . V_512 = F_8 ( V_203 ) ;
V_196 [ 0 ] = & V_552 ;
V_508 [ 0 ] = sizeof( struct V_558 ) ;
V_196 [ 1 ] = V_550 ;
V_508 [ 1 ] = V_203 + 2 ;
V_39 = F_131 ( V_109 , V_5 , V_281 , V_283 ,
V_24 -> V_25 , V_559 , 2 , V_196 , V_508 ) ;
F_47 ( V_196 ) ;
return V_39 ;
}
int
F_135 ( const unsigned int V_109 , struct V_4 * V_5 , T_8 V_281 ,
T_8 V_283 , T_4 V_450 , T_11 * V_560 , bool V_561 )
{
struct V_562 V_552 ;
void * V_196 ;
unsigned int V_508 ;
V_552 . V_353 = * V_560 ;
V_196 = & V_552 ;
V_508 = sizeof( struct V_562 ) ;
if ( V_561 )
return F_131 ( V_109 , V_5 , V_281 , V_283 ,
V_450 , V_563 , 1 , & V_196 , & V_508 ) ;
else
return F_131 ( V_109 , V_5 , V_281 , V_283 ,
V_450 , V_564 , 1 , & V_196 , & V_508 ) ;
}
int
F_136 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_8 V_281 , T_8 V_283 , T_13 * V_270 )
{
unsigned int V_508 ;
V_508 = sizeof( T_13 ) ;
return F_131 ( V_109 , V_5 , V_281 , V_283 ,
V_24 -> V_25 , V_565 , 1 ,
( void * * ) & V_270 , & V_508 ) ;
}
int
F_137 ( const unsigned int V_109 , struct V_4 * V_5 ,
const T_8 V_281 , const T_8 V_283 ,
T_6 V_566 )
{
int V_39 ;
struct V_567 * V_105 = NULL ;
F_10 ( V_49 , L_70 ) ;
V_39 = F_22 ( V_57 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
V_105 -> V_568 = V_283 ;
V_105 -> V_569 = V_281 ;
V_105 -> V_358 = V_566 ;
V_105 -> V_2 . V_22 = F_4 ( 1 ) ;
V_39 = F_65 ( V_109 , V_5 -> V_16 , ( char * ) V_105 , V_570 ) ;
if ( V_39 ) {
F_66 ( V_5 , V_571 ) ;
F_10 ( V_49 , L_71 , V_39 ) ;
}
return V_39 ;
}
static void
F_138 ( struct V_572 * V_573 ,
struct V_574 * V_575 )
{
V_575 -> V_576 = F_36 ( V_573 -> V_577 ) *
F_36 ( V_573 -> V_578 ) ;
V_575 -> V_579 = F_139 ( V_573 -> V_580 ) ;
V_575 -> V_581 = F_139 ( V_573 -> V_582 ) ;
V_575 -> V_583 = F_139 ( V_573 -> V_584 ) ;
return;
}
static int
F_140 ( struct V_112 * V_113 , struct V_4 * V_5 , int V_585 ,
int V_586 , T_8 V_281 , T_8 V_283 )
{
int V_39 ;
struct V_399 * V_105 ;
F_10 ( V_49 , L_72 , V_585 ) ;
if ( ( V_5 -> V_16 == NULL ) || ( V_5 -> V_16 -> V_17 == NULL ) )
return - V_52 ;
V_39 = F_22 ( V_78 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
V_105 -> V_401 = V_587 ;
V_105 -> V_403 = V_585 ;
V_105 -> V_280 = V_281 ;
V_105 -> V_282 = V_283 ;
V_105 -> V_404 =
F_4 ( sizeof( struct V_399 ) - 1 - 4 ) ;
V_105 -> V_405 = F_8 (
V_586 + sizeof( struct V_400 ) - 1 - 4 ) ;
V_113 -> V_138 = ( char * ) V_105 ;
V_113 -> V_139 = F_33 ( V_105 ) + 4 ;
return 0 ;
}
int
F_141 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_8 V_281 , T_8 V_283 , struct V_574 * V_588 )
{
struct V_400 * V_111 = NULL ;
struct V_112 V_113 ;
int V_39 = 0 ;
int V_114 ;
struct V_42 * V_16 = V_5 -> V_16 ;
struct V_572 * V_552 = NULL ;
V_39 = F_140 ( & V_113 , V_5 , V_589 ,
sizeof( struct V_572 ) ,
V_281 , V_283 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_34 ( V_109 , V_16 , & V_113 , 1 , & V_114 , 0 ) ;
if ( V_39 ) {
F_66 ( V_5 , V_406 ) ;
goto V_590;
}
V_111 = (struct V_400 * ) V_113 . V_138 ;
V_552 = (struct V_572 * ) ( 4 +
F_2 ( V_111 -> V_408 ) + ( char * ) & V_111 -> V_2 ) ;
V_39 = F_87 ( F_2 ( V_111 -> V_408 ) ,
F_36 ( V_111 -> V_405 ) , & V_111 -> V_2 ,
sizeof( struct V_572 ) ) ;
if ( ! V_39 )
F_138 ( V_552 , V_588 ) ;
V_590:
F_40 ( V_114 , V_113 . V_138 ) ;
return V_39 ;
}
int
F_142 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_8 V_281 , T_8 V_283 , int V_585 )
{
struct V_400 * V_111 = NULL ;
struct V_112 V_113 ;
int V_39 = 0 ;
int V_114 , V_591 , V_398 ;
struct V_42 * V_16 = V_5 -> V_16 ;
unsigned int V_592 , V_388 ;
if ( V_585 == V_593 ) {
V_591 = sizeof( V_594 ) ;
V_398 = sizeof( V_594 ) ;
} else if ( V_585 == V_595 ) {
V_591 = sizeof( V_596 ) ;
V_398 = V_597 ;
} else if ( V_585 == V_598 ) {
V_591 = sizeof( struct V_599 ) ;
V_398 = sizeof( struct V_599 ) ;
} else {
F_10 ( V_49 , L_73 , V_585 ) ;
return - V_245 ;
}
V_39 = F_140 ( & V_113 , V_5 , V_585 , V_591 ,
V_281 , V_283 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_34 ( V_109 , V_16 , & V_113 , 1 , & V_114 , 0 ) ;
if ( V_39 ) {
F_66 ( V_5 , V_406 ) ;
goto V_600;
}
V_111 = (struct V_400 * ) V_113 . V_138 ;
V_592 = F_36 ( V_111 -> V_405 ) ;
V_388 = F_2 ( V_111 -> V_408 ) ;
V_39 = F_87 ( V_388 , V_592 , & V_111 -> V_2 , V_398 ) ;
if ( V_39 )
goto V_600;
if ( V_585 == V_595 )
memcpy ( & V_5 -> V_601 , 4 + V_388
+ ( char * ) & V_111 -> V_2 , F_6 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_585 == V_593 )
memcpy ( & V_5 -> V_602 , 4 + V_388
+ ( char * ) & V_111 -> V_2 , sizeof( V_594 ) ) ;
else if ( V_585 == V_598 ) {
struct V_599 * V_603 = (struct V_599 * )
( 4 + V_388 + ( char * ) & V_111 -> V_2 ) ;
V_5 -> V_604 = F_36 ( V_603 -> V_35 ) ;
V_5 -> V_605 =
F_36 ( V_603 -> V_606 ) ;
}
V_600:
F_40 ( V_114 , V_113 . V_138 ) ;
return V_39 ;
}
int
F_143 ( const unsigned int V_109 , struct V_4 * V_5 ,
const T_14 V_607 , const T_14 V_283 , const T_7 V_450 ,
const T_7 V_608 , struct V_609 * V_270 )
{
int V_39 = 0 ;
struct V_610 * V_105 = NULL ;
struct V_112 V_113 [ 2 ] ;
int V_611 ;
unsigned int V_612 ;
F_10 ( V_49 , L_74 , V_608 ) ;
V_39 = F_22 ( V_74 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
V_105 -> V_2 . V_23 = F_8 ( V_450 ) ;
V_105 -> V_613 = F_4 ( V_608 ) ;
V_105 -> V_280 = V_607 ;
V_105 -> V_282 = V_283 ;
V_612 = V_608 * sizeof( struct V_609 ) ;
F_30 ( V_105 , V_612 - sizeof( struct V_609 ) ) ;
V_113 [ 0 ] . V_138 = ( char * ) V_105 ;
V_113 [ 0 ] . V_139 = F_33 ( V_105 ) + 4 - V_612 ;
V_113 [ 1 ] . V_138 = ( char * ) V_270 ;
V_113 [ 1 ] . V_139 = V_612 ;
F_25 ( & V_5 -> V_83 . V_614 . V_615 ) ;
V_39 = F_34 ( V_109 , V_5 -> V_16 , V_113 , 2 , & V_611 , V_616 ) ;
if ( V_39 ) {
F_10 ( V_49 , L_75 , V_39 ) ;
F_66 ( V_5 , V_617 ) ;
}
return V_39 ;
}
int
F_144 ( const unsigned int V_109 , struct V_4 * V_5 ,
const T_14 V_607 , const T_14 V_283 , const T_7 V_450 ,
const T_14 V_455 , const T_14 V_388 , const T_7 V_618 ,
const bool V_619 )
{
struct V_609 V_620 ;
V_620 . V_456 = F_110 ( V_388 ) ;
V_620 . V_454 = F_110 ( V_455 ) ;
V_620 . V_35 = F_8 ( V_618 ) ;
if ( ! V_619 && V_618 != V_621 )
V_620 . V_35 |= F_8 ( V_622 ) ;
return F_143 ( V_109 , V_5 , V_607 , V_283 , V_450 , 1 , & V_620 ) ;
}
int
F_145 ( const unsigned int V_109 , struct V_4 * V_5 ,
T_6 * V_623 , const T_15 V_624 )
{
int V_39 ;
struct V_625 * V_105 = NULL ;
F_10 ( V_49 , L_76 ) ;
V_39 = F_22 ( V_57 , V_5 , ( void * * ) & V_105 ) ;
if ( V_39 )
return V_39 ;
V_105 -> V_2 . V_22 = F_4 ( 1 ) ;
V_105 -> V_14 = F_4 ( 36 ) ;
F_30 ( V_105 , 12 ) ;
memcpy ( V_105 -> V_626 , V_623 , 16 ) ;
V_105 -> V_627 = V_624 ;
V_39 = F_65 ( V_109 , V_5 -> V_16 , ( char * ) V_105 , V_570 ) ;
if ( V_39 ) {
F_66 ( V_5 , V_571 ) ;
F_10 ( V_49 , L_77 , V_39 ) ;
}
return V_39 ;
}
