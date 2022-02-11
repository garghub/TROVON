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
V_39 = F_18 ( 0 , V_5 -> V_16 , V_5 -> V_65 , V_5 , V_41 ) ;
F_16 ( & V_5 -> V_16 -> V_64 ) ;
if ( V_5 -> V_66 )
F_19 ( V_5 ) ;
F_10 ( V_49 , L_3 , V_39 ) ;
if ( V_39 )
goto V_26;
F_20 ( & V_67 ) ;
V_26:
switch ( V_38 ) {
case V_68 :
case V_69 :
case V_46 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
return - V_58 ;
}
F_21 ( V_41 ) ;
return V_39 ;
}
static int
F_22 ( T_1 V_38 , struct V_4 * V_5 ,
void * * V_76 )
{
int V_39 = 0 ;
V_39 = F_9 ( V_38 , V_5 ) ;
if ( V_39 )
return V_39 ;
* V_76 = F_23 () ;
if ( * V_76 == NULL ) {
return - V_77 ;
}
F_1 ( (struct V_1 * ) * V_76 , V_38 , V_5 ) ;
if ( V_5 != NULL ) {
#ifdef F_24
T_3 V_78 = F_2 ( V_38 ) ;
F_25 ( & V_5 -> V_79 . V_80 . V_81 [ V_78 ] ) ;
#endif
F_25 ( & V_5 -> V_82 ) ;
}
return V_39 ;
}
static void
F_26 ( struct V_83 * V_84 )
{
V_84 -> V_85 = V_86 ;
V_84 -> V_87 = F_4 ( 38 ) ;
V_84 -> V_88 = F_4 ( 1 ) ;
V_84 -> V_89 = F_4 ( V_90 ) ;
F_27 ( V_84 -> V_91 , V_90 ) ;
V_84 -> V_92 = V_93 ;
}
static void
F_28 ( struct V_94 * V_84 )
{
V_84 -> V_85 = V_95 ;
V_84 -> V_87 = F_4 ( 6 ) ;
V_84 -> V_96 = F_4 ( 2 ) ;
V_84 -> V_97 [ 0 ] = V_98 ;
V_84 -> V_97 [ 1 ] = V_99 ;
}
static void
F_29 ( struct V_100 * V_101 )
{
char * V_84 = ( char * ) V_101 + V_102 + 4 ;
F_26 ( (struct V_83 * ) V_84 ) ;
V_84 += 2 + sizeof( struct V_83 ) ;
F_28 ( (struct V_94 * ) V_84 ) ;
V_101 -> V_103 = F_8 ( V_102 ) ;
V_101 -> V_104 = F_4 ( 2 ) ;
F_30 ( V_101 , 4 + sizeof( struct V_83 ) + 2
+ sizeof( struct V_94 ) ) ;
}
static void F_29 ( struct V_100 * V_101 )
{
return;
}
int
F_31 ( const unsigned int V_105 , struct V_42 * V_16 )
{
struct V_100 * V_101 ;
struct V_106 * V_107 ;
struct V_108 V_109 [ 1 ] ;
int V_39 = 0 ;
int V_110 ;
struct V_18 * V_17 = V_16 -> V_17 ;
int V_111 , V_112 ;
char * V_113 ;
int V_114 = V_115 ;
F_10 ( V_49 , L_4 ) ;
if ( ! V_17 ) {
F_32 ( 1 , L_5 , V_116 ) ;
return - V_52 ;
}
V_39 = F_22 ( V_117 , NULL , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
V_101 -> V_2 . V_32 = 0 ;
V_101 -> V_118 [ 0 ] = F_4 ( V_16 -> V_17 -> V_119 -> V_120 ) ;
V_101 -> V_121 = F_4 ( 1 ) ;
F_30 ( V_101 , 2 ) ;
if ( V_16 -> V_34 )
V_101 -> V_122 = F_4 ( V_123 ) ;
else if ( V_124 & V_125 )
V_101 -> V_122 = F_4 ( V_126 ) ;
else
V_101 -> V_122 = 0 ;
V_101 -> V_127 = F_8 ( V_16 -> V_17 -> V_119 -> V_128 ) ;
if ( V_16 -> V_17 -> V_119 -> V_120 == V_129 )
memset ( V_101 -> V_130 , 0 , V_131 ) ;
else {
memcpy ( V_101 -> V_130 , V_17 -> V_132 ,
V_131 ) ;
if ( V_16 -> V_17 -> V_119 -> V_120 == V_133 )
F_29 ( V_101 ) ;
}
V_109 [ 0 ] . V_134 = ( char * ) V_101 ;
V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 ;
V_39 = F_34 ( V_105 , V_16 , V_109 , 1 , & V_110 , V_114 ) ;
V_107 = (struct V_106 * ) V_109 [ 0 ] . V_134 ;
if ( V_39 != 0 )
goto V_136;
F_10 ( V_49 , L_6 , V_107 -> V_122 ) ;
if ( V_107 -> V_137 == F_4 ( V_129 ) )
F_10 ( V_49 , L_7 ) ;
else if ( V_107 -> V_137 == F_4 ( V_138 ) )
F_10 ( V_49 , L_8 ) ;
else if ( V_107 -> V_137 == F_4 ( V_139 ) )
F_10 ( V_49 , L_9 ) ;
else if ( V_107 -> V_137 == F_4 ( V_140 ) )
F_10 ( V_49 , L_10 ) ;
#ifdef F_35
else if ( V_107 -> V_137 == F_4 ( V_133 ) )
F_10 ( V_49 , L_11 ) ;
#endif
else {
F_10 ( V_141 , L_12 ,
F_2 ( V_107 -> V_137 ) ) ;
V_39 = - V_52 ;
goto V_136;
}
V_17 -> V_142 = F_2 ( V_107 -> V_137 ) ;
V_17 -> V_143 = V_144 ;
V_17 -> V_145 = F_6 (unsigned int, le32_to_cpu(rsp->MaxTransactSize),
SMB2_MAX_BUFFER_SIZE) ;
V_17 -> V_146 = F_36 ( V_107 -> V_147 ) ;
V_17 -> V_148 = F_36 ( V_107 -> V_149 ) ;
V_17 -> V_150 = F_2 ( V_107 -> V_122 ) ;
V_17 -> V_27 = F_36 ( V_107 -> V_127 ) ;
V_17 -> V_27 |= V_151 | V_152 ;
V_113 = F_37 ( & V_111 , & V_112 ,
& V_107 -> V_2 ) ;
if ( V_112 == 0 )
F_10 ( V_49 , L_13 ) ;
V_39 = F_38 ( V_17 , V_16 -> V_34 ) ;
if ( V_39 )
goto V_136;
if ( V_112 ) {
V_39 = F_39 ( V_113 , V_112 , V_17 ) ;
if ( V_39 == 1 )
V_39 = 0 ;
else if ( V_39 == 0 )
V_39 = - V_52 ;
}
V_136:
F_40 ( V_110 , V_107 ) ;
return V_39 ;
}
int F_41 ( const unsigned int V_105 , struct V_4 * V_5 )
{
int V_39 = 0 ;
struct V_153 V_154 ;
struct V_155 * V_156 ;
T_4 V_157 ;
F_10 ( V_49 , L_14 ) ;
if ( V_5 -> V_16 -> V_17 -> V_34 == false )
return 0 ;
V_154 . V_127 =
F_8 ( V_5 -> V_16 -> V_17 -> V_119 -> V_128 ) ;
memcpy ( V_154 . V_158 , V_5 -> V_16 -> V_17 -> V_132 ,
V_131 ) ;
if ( V_5 -> V_16 -> V_34 )
V_154 . V_122 =
F_4 ( V_123 ) ;
else if ( V_124 & V_125 )
V_154 . V_122 =
F_4 ( V_126 ) ;
else
V_154 . V_122 = 0 ;
V_154 . V_121 = F_4 ( 1 ) ;
V_154 . V_118 [ 0 ] =
F_4 ( V_5 -> V_16 -> V_17 -> V_119 -> V_120 ) ;
V_39 = F_42 ( V_105 , V_5 , V_159 , V_159 ,
V_160 , true ,
( char * ) & V_154 , sizeof( struct V_153 ) ,
( char * * ) & V_156 , & V_157 ) ;
if ( V_39 != 0 ) {
F_10 ( V_141 , L_15 , V_39 ) ;
return - V_52 ;
}
if ( V_157 != sizeof( struct V_155 ) ) {
F_10 ( V_141 , L_16 ) ;
return - V_52 ;
}
if ( V_156 -> V_161 !=
F_4 ( V_5 -> V_16 -> V_17 -> V_119 -> V_120 ) )
goto V_162;
if ( V_156 -> V_122 != F_4 ( V_5 -> V_16 -> V_17 -> V_150 ) )
goto V_162;
if ( ( F_36 ( V_156 -> V_127 ) | V_151 |
V_152 ) != V_5 -> V_16 -> V_17 -> V_27 )
goto V_162;
F_10 ( V_49 , L_17 ) ;
return 0 ;
V_162:
F_10 ( V_141 , L_18 ) ;
return - V_52 ;
}
static int
F_43 ( struct V_163 * V_164 )
{
int V_39 ;
struct V_42 * V_16 = V_164 -> V_16 ;
struct V_165 * V_101 ;
struct V_18 * V_17 = V_16 -> V_17 ;
V_39 = F_22 ( V_166 , NULL , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
V_101 -> V_2 . V_32 = 0 ;
V_101 -> V_167 = V_164 -> V_168 ;
V_101 -> V_35 = 0 ;
V_101 -> V_2 . V_22 = F_4 ( 3 ) ;
if ( V_17 -> V_34 )
V_101 -> V_122 = V_123 ;
else if ( V_124 & V_125 )
V_101 -> V_122 = V_126 ;
else
V_101 -> V_122 = 0 ;
V_101 -> V_127 = 0 ;
V_101 -> V_169 = 0 ;
V_164 -> V_109 [ 0 ] . V_134 = ( char * ) V_101 ;
V_164 -> V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 - 1 ;
V_164 -> V_170 = V_171 ;
return 0 ;
}
static void
F_44 ( struct V_163 * V_164 )
{
F_40 ( V_164 -> V_170 , V_164 -> V_109 [ 0 ] . V_134 ) ;
V_164 -> V_170 = V_172 ;
}
static int
F_45 ( struct V_163 * V_164 )
{
int V_39 ;
struct V_165 * V_101 = V_164 -> V_109 [ 0 ] . V_134 ;
V_101 -> V_173 =
F_4 ( sizeof( struct V_165 ) -
1 - 4 ) ;
V_101 -> V_174 = F_4 ( V_164 -> V_109 [ 1 ] . V_135 ) ;
F_30 ( V_101 , V_164 -> V_109 [ 1 ] . V_135 - 1 ) ;
V_39 = F_34 ( V_164 -> V_105 , V_164 -> V_16 ,
V_164 -> V_109 , 2 ,
& V_164 -> V_170 ,
V_175 | V_115 ) ;
return V_39 ;
}
static int
F_46 ( struct V_163 * V_164 )
{
int V_39 = 0 ;
struct V_42 * V_16 = V_164 -> V_16 ;
F_13 ( & V_16 -> V_17 -> V_176 ) ;
if ( V_16 -> V_17 -> V_34 && V_16 -> V_17 -> V_177 -> V_178 ) {
V_39 = V_16 -> V_17 -> V_177 -> V_178 ( V_16 ) ;
F_47 ( V_16 -> V_179 . V_180 ) ;
V_16 -> V_179 . V_180 = NULL ;
if ( V_39 ) {
F_10 ( V_49 ,
L_19 ) ;
F_16 ( & V_16 -> V_17 -> V_176 ) ;
goto V_181;
}
}
if ( ! V_16 -> V_17 -> V_182 ) {
V_16 -> V_17 -> V_183 = 0x2 ;
V_16 -> V_17 -> V_182 = true ;
}
F_16 ( & V_16 -> V_17 -> V_176 ) ;
F_10 ( V_49 , L_20 ) ;
F_5 ( & V_184 ) ;
V_16 -> V_51 = V_185 ;
V_16 -> V_63 = false ;
F_7 ( & V_184 ) ;
V_181:
if ( ! V_16 -> V_17 -> V_34 ) {
F_47 ( V_16 -> V_179 . V_180 ) ;
V_16 -> V_179 . V_180 = NULL ;
}
return V_39 ;
}
static void
F_48 ( struct V_163 * V_164 )
{
int V_39 ;
struct V_42 * V_16 = V_164 -> V_16 ;
struct V_186 * V_187 ;
struct V_188 * V_189 = NULL ;
struct V_190 * V_107 = NULL ;
V_39 = F_43 ( V_164 ) ;
if ( V_39 )
goto V_26;
V_189 = F_49 ( V_16 ) ;
if ( F_50 ( V_189 ) ) {
V_39 = F_51 ( V_189 ) ;
V_189 = NULL ;
goto V_26;
}
V_187 = V_189 -> V_191 . V_192 [ 0 ] ;
if ( V_187 -> V_193 != V_194 ) {
F_10 ( V_141 ,
L_21 ,
V_194 , V_187 -> V_193 ) ;
V_39 = - V_195 ;
goto V_196;
}
V_16 -> V_179 . V_180 = F_52 ( V_187 -> V_192 , V_187 -> V_197 ,
V_198 ) ;
if ( ! V_16 -> V_179 . V_180 ) {
F_10 ( V_141 ,
L_22 ,
V_187 -> V_197 ) ;
V_39 = - V_77 ;
goto V_196;
}
V_16 -> V_179 . V_199 = V_187 -> V_197 ;
V_164 -> V_109 [ 1 ] . V_134 = V_187 -> V_192 + V_187 -> V_197 ;
V_164 -> V_109 [ 1 ] . V_135 = V_187 -> V_200 ;
V_39 = F_45 ( V_164 ) ;
if ( V_39 )
goto V_196;
V_107 = (struct V_190 * ) V_164 -> V_109 [ 0 ] . V_134 ;
V_16 -> V_33 = V_107 -> V_2 . V_32 ;
V_16 -> V_201 = F_2 ( V_107 -> V_202 ) ;
if ( V_16 -> V_201 & V_203 )
F_10 ( V_141 , L_23 ) ;
V_39 = F_46 ( V_164 ) ;
V_196:
F_53 ( V_189 ) ;
F_54 ( V_189 ) ;
V_26:
V_164 -> V_204 = V_39 ;
V_164 -> V_205 = NULL ;
F_44 ( V_164 ) ;
}
static void
F_48 ( struct V_163 * V_164 )
{
F_10 ( V_141 , L_24 ) ;
V_164 -> V_204 = - V_206 ;
V_164 -> V_205 = NULL ;
}
static void
F_55 ( struct V_163 * V_164 )
{
int V_39 ;
struct V_42 * V_16 = V_164 -> V_16 ;
struct V_190 * V_107 = NULL ;
char * V_207 = NULL ;
bool V_208 = false ;
T_5 V_112 = 0 ;
V_16 -> V_209 = F_56 ( sizeof( struct V_210 ) , V_198 ) ;
if ( ! V_16 -> V_209 ) {
V_39 = - V_77 ;
goto V_211;
}
V_16 -> V_209 -> V_212 = true ;
V_39 = F_43 ( V_164 ) ;
if ( V_39 )
goto V_211;
V_207 = F_56 ( sizeof( struct V_213 ) ,
V_198 ) ;
if ( V_207 == NULL ) {
V_39 = - V_77 ;
goto V_26;
}
F_57 ( V_207 , V_16 ) ;
if ( V_208 ) {
F_10 ( V_141 , L_25 ) ;
V_39 = - V_206 ;
goto V_26;
} else {
V_112 = sizeof( struct V_213 ) ;
}
V_164 -> V_109 [ 1 ] . V_134 = V_207 ;
V_164 -> V_109 [ 1 ] . V_135 = V_112 ;
V_39 = F_45 ( V_164 ) ;
V_107 = (struct V_190 * ) V_164 -> V_109 [ 0 ] . V_134 ;
if ( V_164 -> V_170 != V_172 &&
V_107 -> V_2 . V_214 == V_215 )
V_39 = 0 ;
if ( V_39 )
goto V_26;
if ( F_58 ( struct V_190 , V_216 ) - 4 !=
F_2 ( V_107 -> V_173 ) ) {
F_10 ( V_141 , L_26 ,
F_2 ( V_107 -> V_173 ) ) ;
V_39 = - V_52 ;
goto V_26;
}
V_39 = F_59 ( V_107 -> V_216 ,
F_2 ( V_107 -> V_174 ) , V_16 ) ;
if ( V_39 )
goto V_26;
F_10 ( V_49 , L_27 ) ;
V_16 -> V_33 = V_107 -> V_2 . V_32 ;
V_16 -> V_201 = F_2 ( V_107 -> V_202 ) ;
if ( V_16 -> V_201 & V_203 )
F_10 ( V_141 , L_23 ) ;
V_26:
F_47 ( V_207 ) ;
F_44 ( V_164 ) ;
if ( ! V_39 ) {
V_164 -> V_204 = 0 ;
V_164 -> V_205 = V_217 ;
return;
}
V_211:
F_47 ( V_16 -> V_209 ) ;
V_16 -> V_209 = NULL ;
V_164 -> V_204 = V_39 ;
V_164 -> V_205 = NULL ;
}
static void
V_217 ( struct V_163 * V_164 )
{
int V_39 ;
struct V_42 * V_16 = V_164 -> V_16 ;
struct V_165 * V_101 ;
struct V_190 * V_107 = NULL ;
unsigned char * V_207 = NULL ;
bool V_208 = false ;
T_5 V_112 = 0 ;
V_39 = F_43 ( V_164 ) ;
if ( V_39 )
goto V_26;
V_101 = (struct V_165 * ) V_164 -> V_109 [ 0 ] . V_134 ;
V_101 -> V_2 . V_32 = V_16 -> V_33 ;
V_39 = F_60 ( & V_207 , & V_112 , V_16 ,
V_164 -> V_218 ) ;
if ( V_39 ) {
F_10 ( V_49 , L_28 , V_39 ) ;
goto V_26;
}
if ( V_208 ) {
F_10 ( V_141 , L_25 ) ;
V_39 = - V_206 ;
goto V_26;
}
V_164 -> V_109 [ 1 ] . V_134 = V_207 ;
V_164 -> V_109 [ 1 ] . V_135 = V_112 ;
V_39 = F_45 ( V_164 ) ;
if ( V_39 )
goto V_26;
V_107 = (struct V_190 * ) V_164 -> V_109 [ 0 ] . V_134 ;
V_16 -> V_33 = V_107 -> V_2 . V_32 ;
V_16 -> V_201 = F_2 ( V_107 -> V_202 ) ;
if ( V_16 -> V_201 & V_203 )
F_10 ( V_141 , L_23 ) ;
V_39 = F_46 ( V_164 ) ;
V_26:
F_47 ( V_207 ) ;
F_44 ( V_164 ) ;
F_47 ( V_16 -> V_209 ) ;
V_16 -> V_209 = NULL ;
V_164 -> V_204 = V_39 ;
V_164 -> V_205 = NULL ;
}
static int
F_61 ( struct V_42 * V_16 , struct V_163 * V_164 )
{
if ( V_16 -> V_219 != V_220 && V_16 -> V_219 != V_221 )
V_16 -> V_219 = V_221 ;
switch ( V_16 -> V_219 ) {
case V_220 :
V_164 -> V_205 = F_48 ;
break;
case V_221 :
V_164 -> V_205 = F_55 ;
break;
default:
F_10 ( V_141 , L_29 , V_16 -> V_219 ) ;
return - V_206 ;
}
return 0 ;
}
int
F_62 ( const unsigned int V_105 , struct V_42 * V_16 ,
const struct V_40 * V_218 )
{
int V_39 = 0 ;
struct V_18 * V_17 = V_16 -> V_17 ;
struct V_163 * V_164 ;
F_10 ( V_49 , L_30 ) ;
if ( ! V_17 ) {
F_32 ( 1 , L_5 , V_116 ) ;
return - V_52 ;
}
V_164 = F_63 ( sizeof( struct V_163 ) , V_198 ) ;
if ( ! V_164 )
return - V_77 ;
V_39 = F_61 ( V_16 , V_164 ) ;
if ( V_39 )
goto V_26;
V_164 -> V_105 = V_105 ;
V_164 -> V_16 = V_16 ;
V_164 -> V_170 = V_172 ;
V_164 -> V_218 = (struct V_40 * ) V_218 ;
while ( V_164 -> V_205 )
V_164 -> V_205 ( V_164 ) ;
V_39 = V_164 -> V_204 ;
V_26:
F_47 ( V_164 ) ;
return V_39 ;
}
int
F_64 ( const unsigned int V_105 , struct V_42 * V_16 )
{
struct V_222 * V_101 ;
int V_39 = 0 ;
struct V_18 * V_17 ;
F_10 ( V_49 , L_31 , V_16 ) ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
if ( V_16 -> V_63 )
goto V_223;
V_39 = F_22 ( V_224 , NULL , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
V_101 -> V_2 . V_32 = V_16 -> V_33 ;
if ( V_17 -> V_34 )
V_101 -> V_2 . V_35 |= V_36 ;
V_39 = F_65 ( V_105 , V_16 , ( char * ) & V_101 -> V_2 , 0 ) ;
V_223:
return V_39 ;
}
static inline void F_66 ( struct V_4 * V_5 , T_3 V_225 )
{
F_25 ( & V_5 -> V_79 . V_80 . V_226 [ V_225 ] ) ;
}
static inline void F_67 ( struct V_4 * V_5 )
{
V_5 -> V_227 = 256 ;
V_5 -> V_228 = 1048576 ;
V_5 -> V_229 = 16777216 ;
}
int
F_18 ( const unsigned int V_105 , struct V_42 * V_16 , const char * V_230 ,
struct V_4 * V_5 , const struct V_40 * V_231 )
{
struct V_232 * V_101 ;
struct V_233 * V_107 = NULL ;
struct V_108 V_109 [ 2 ] ;
int V_39 = 0 ;
int V_110 ;
int V_234 ;
struct V_18 * V_17 ;
T_1 * V_235 = NULL ;
F_10 ( V_49 , L_32 ) ;
if ( ( V_16 -> V_17 ) && V_230 )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
if ( V_5 && V_5 -> V_236 )
return - V_237 ;
if ( ( V_5 && V_5 -> V_238 ) &&
( ( V_16 -> V_17 -> V_27 & V_239 ) == 0 ) ) {
F_10 ( V_141 , L_33 ) ;
return - V_206 ;
}
V_235 = F_56 ( V_240 * 2 , V_198 ) ;
if ( V_235 == NULL )
return - V_77 ;
V_234 = F_68 ( V_235 , V_230 , strlen ( V_230 ) , V_231 ) + 1 ;
V_234 *= 2 ;
if ( V_234 < 2 ) {
F_47 ( V_235 ) ;
return - V_241 ;
}
V_39 = F_22 ( V_43 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 ) {
F_47 ( V_235 ) ;
return V_39 ;
}
if ( V_5 == NULL ) {
V_101 -> V_2 . V_32 = V_16 -> V_33 ;
}
V_109 [ 0 ] . V_134 = ( char * ) V_101 ;
V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 - 1 ;
V_101 -> V_242 = F_4 ( sizeof( struct V_232 )
- 1 - 4 ) ;
V_101 -> V_243 = F_4 ( V_234 - 2 ) ;
V_109 [ 1 ] . V_134 = V_235 ;
V_109 [ 1 ] . V_135 = V_234 ;
F_30 ( V_101 , V_234 - 1 ) ;
V_39 = F_34 ( V_105 , V_16 , V_109 , 2 , & V_110 , 0 ) ;
V_107 = (struct V_233 * ) V_109 [ 0 ] . V_134 ;
if ( V_39 != 0 ) {
if ( V_5 ) {
F_66 ( V_5 , V_244 ) ;
V_5 -> V_63 = true ;
}
goto V_245;
}
if ( V_5 == NULL ) {
V_16 -> V_246 = V_107 -> V_2 . V_30 ;
goto V_247;
}
if ( V_107 -> V_248 & V_249 )
F_10 ( V_49 , L_34 ) ;
else if ( V_107 -> V_248 & V_250 ) {
V_5 -> V_251 = true ;
F_10 ( V_49 , L_35 ) ;
} else if ( V_107 -> V_248 & V_252 ) {
V_5 -> V_253 = true ;
F_10 ( V_49 , L_36 ) ;
} else {
F_10 ( V_141 , L_37 , V_107 -> V_248 ) ;
V_39 = - V_206 ;
goto V_245;
}
V_5 -> V_254 = F_36 ( V_107 -> V_255 ) ;
V_5 -> V_27 = V_107 -> V_127 ;
V_5 -> V_256 = F_36 ( V_107 -> V_257 ) ;
V_5 -> V_44 = V_185 ;
V_5 -> V_63 = false ;
V_5 -> V_31 = V_107 -> V_2 . V_30 ;
F_69 ( V_5 -> V_65 , V_230 , sizeof( V_5 -> V_65 ) ) ;
if ( ( V_107 -> V_127 & V_258 ) &&
( ( V_5 -> V_254 & V_259 ) == 0 ) )
F_10 ( V_141 , L_38 ) ;
F_67 ( V_5 ) ;
if ( V_5 -> V_254 & V_260 )
F_10 ( V_141 , L_39 ) ;
if ( V_5 -> V_16 -> V_17 -> V_177 -> V_261 )
V_39 = V_5 -> V_16 -> V_17 -> V_177 -> V_261 ( V_105 , V_5 ) ;
V_247:
F_40 ( V_110 , V_107 ) ;
F_47 ( V_235 ) ;
return V_39 ;
V_245:
if ( V_107 -> V_2 . V_214 == V_262 ) {
F_10 ( V_141 , L_40 , V_230 ) ;
if ( V_5 )
V_5 -> V_236 = true ;
}
goto V_247;
}
int
F_70 ( const unsigned int V_105 , struct V_4 * V_5 )
{
struct V_263 * V_101 ;
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
V_39 = F_22 ( V_48 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_65 ( V_105 , V_16 , ( char * ) & V_101 -> V_2 , 0 ) ;
if ( V_39 )
F_66 ( V_5 , V_264 ) ;
return V_39 ;
}
static struct V_265 *
F_71 ( void )
{
struct V_265 * V_266 ;
V_266 = F_63 ( sizeof( struct V_265 ) , V_198 ) ;
if ( ! V_266 )
return NULL ;
V_266 -> V_267 . V_268 = F_4 ( F_58
( struct V_265 , V_269 ) ) ;
V_266 -> V_267 . V_87 = F_8 ( 16 ) ;
V_266 -> V_267 . V_270 = F_4 ( F_58
( struct V_265 , V_271 ) ) ;
V_266 -> V_267 . V_272 = F_4 ( 4 ) ;
V_266 -> V_271 [ 0 ] = 'D' ;
V_266 -> V_271 [ 1 ] = 'H' ;
V_266 -> V_271 [ 2 ] = 'n' ;
V_266 -> V_271 [ 3 ] = 'Q' ;
return V_266 ;
}
static struct V_265 *
F_72 ( struct V_273 * V_274 )
{
struct V_265 * V_266 ;
V_266 = F_63 ( sizeof( struct V_265 ) , V_198 ) ;
if ( ! V_266 )
return NULL ;
V_266 -> V_267 . V_268 = F_4 ( F_58
( struct V_265 , V_269 ) ) ;
V_266 -> V_267 . V_87 = F_8 ( 16 ) ;
V_266 -> V_267 . V_270 = F_4 ( F_58
( struct V_265 , V_271 ) ) ;
V_266 -> V_267 . V_272 = F_4 ( 4 ) ;
V_266 -> V_269 . V_275 . V_276 = V_274 -> V_277 ;
V_266 -> V_269 . V_275 . V_278 = V_274 -> V_279 ;
V_266 -> V_271 [ 0 ] = 'D' ;
V_266 -> V_271 [ 1 ] = 'H' ;
V_266 -> V_271 [ 2 ] = 'n' ;
V_266 -> V_271 [ 3 ] = 'C' ;
return V_266 ;
}
static T_6
F_73 ( struct V_18 * V_17 , struct V_280 * V_107 ,
unsigned int * V_281 )
{
char * V_282 ;
struct V_283 * V_284 ;
unsigned int V_285 ;
unsigned int V_286 ;
char * V_287 ;
V_282 = ( char * ) V_107 + 4 + F_36 ( V_107 -> V_288 ) ;
V_286 = F_36 ( V_107 -> V_289 ) ;
V_284 = (struct V_283 * ) V_282 ;
while ( V_286 >= sizeof( struct V_283 ) ) {
V_287 = F_2 ( V_284 -> V_270 ) + ( char * ) V_284 ;
if ( F_2 ( V_284 -> V_272 ) == 4 &&
strncmp ( V_287 , L_42 , 4 ) == 0 )
return V_17 -> V_177 -> V_290 ( V_284 , V_281 ) ;
V_285 = F_36 ( V_284 -> V_291 ) ;
if ( ! V_285 )
break;
V_286 -= V_285 ;
V_284 = (struct V_283 * ) ( ( char * ) V_284 + V_285 ) ;
}
return 0 ;
}
static int
F_74 ( struct V_18 * V_17 , struct V_108 * V_109 ,
unsigned int * V_292 , T_6 * V_293 )
{
struct V_294 * V_101 = V_109 [ 0 ] . V_134 ;
unsigned int V_295 = * V_292 ;
V_109 [ V_295 ] . V_134 = V_17 -> V_177 -> V_296 ( V_293 + 1 , * V_293 ) ;
if ( V_109 [ V_295 ] . V_134 == NULL )
return - V_77 ;
V_109 [ V_295 ] . V_135 = V_17 -> V_119 -> V_297 ;
V_101 -> V_298 = V_299 ;
if ( ! V_101 -> V_288 )
V_101 -> V_288 = F_8 (
sizeof( struct V_294 ) - 4 +
V_109 [ V_295 - 1 ] . V_135 ) ;
F_75 ( & V_101 -> V_289 ,
V_17 -> V_119 -> V_297 ) ;
F_30 ( & V_101 -> V_2 , V_17 -> V_119 -> V_297 ) ;
* V_292 = V_295 + 1 ;
return 0 ;
}
static struct V_300 *
F_76 ( struct V_273 * V_301 )
{
struct V_300 * V_266 ;
V_266 = F_63 ( sizeof( struct V_300 ) , V_198 ) ;
if ( ! V_266 )
return NULL ;
V_266 -> V_267 . V_268 = F_4 ( F_58
( struct V_300 , V_302 ) ) ;
V_266 -> V_267 . V_87 = F_8 ( sizeof( struct V_303 ) ) ;
V_266 -> V_267 . V_270 = F_4 ( F_58
( struct V_300 , V_271 ) ) ;
V_266 -> V_267 . V_272 = F_4 ( 4 ) ;
V_266 -> V_302 . V_304 = 0 ;
V_266 -> V_302 . V_35 = F_8 ( V_305 ) ;
F_77 ( V_266 -> V_302 . V_306 ) ;
memcpy ( V_301 -> V_307 , V_266 -> V_302 . V_306 , 16 ) ;
V_266 -> V_271 [ 0 ] = 'D' ;
V_266 -> V_271 [ 1 ] = 'H' ;
V_266 -> V_271 [ 2 ] = '2' ;
V_266 -> V_271 [ 3 ] = 'Q' ;
return V_266 ;
}
static struct V_308 *
F_78 ( struct V_273 * V_274 )
{
struct V_308 * V_266 ;
V_266 = F_63 ( sizeof( struct V_308 ) ,
V_198 ) ;
if ( ! V_266 )
return NULL ;
V_266 -> V_267 . V_268 =
F_4 ( F_58 ( struct V_308 ,
V_302 ) ) ;
V_266 -> V_267 . V_87 =
F_8 ( sizeof( struct V_309 ) ) ;
V_266 -> V_267 . V_270 =
F_4 ( F_58 ( struct V_308 ,
V_271 ) ) ;
V_266 -> V_267 . V_272 = F_4 ( 4 ) ;
V_266 -> V_302 . V_275 . V_276 = V_274 -> V_277 ;
V_266 -> V_302 . V_275 . V_278 = V_274 -> V_279 ;
V_266 -> V_302 . V_35 = F_8 ( V_305 ) ;
memcpy ( V_266 -> V_302 . V_306 , V_274 -> V_307 , 16 ) ;
V_266 -> V_271 [ 0 ] = 'D' ;
V_266 -> V_271 [ 1 ] = 'H' ;
V_266 -> V_271 [ 2 ] = '2' ;
V_266 -> V_271 [ 3 ] = 'C' ;
return V_266 ;
}
static int
F_79 ( struct V_108 * V_109 , unsigned int * V_292 ,
struct V_310 * V_311 )
{
struct V_294 * V_101 = V_109 [ 0 ] . V_134 ;
unsigned int V_295 = * V_292 ;
V_109 [ V_295 ] . V_134 = F_76 ( V_311 -> V_274 ) ;
if ( V_109 [ V_295 ] . V_134 == NULL )
return - V_77 ;
V_109 [ V_295 ] . V_135 = sizeof( struct V_300 ) ;
if ( ! V_101 -> V_288 )
V_101 -> V_288 =
F_8 ( sizeof( struct V_294 ) - 4 +
V_109 [ 1 ] . V_135 ) ;
F_75 ( & V_101 -> V_289 , sizeof( struct V_300 ) ) ;
F_30 ( & V_101 -> V_2 , sizeof( struct V_300 ) ) ;
* V_292 = V_295 + 1 ;
return 0 ;
}
static int
F_80 ( struct V_108 * V_109 , unsigned int * V_292 ,
struct V_310 * V_311 )
{
struct V_294 * V_101 = V_109 [ 0 ] . V_134 ;
unsigned int V_295 = * V_292 ;
V_311 -> V_312 = false ;
V_109 [ V_295 ] . V_134 = F_78 ( V_311 -> V_274 ) ;
if ( V_109 [ V_295 ] . V_134 == NULL )
return - V_77 ;
V_109 [ V_295 ] . V_135 = sizeof( struct V_308 ) ;
if ( ! V_101 -> V_288 )
V_101 -> V_288 =
F_8 ( sizeof( struct V_294 ) - 4 +
V_109 [ 1 ] . V_135 ) ;
F_75 ( & V_101 -> V_289 ,
sizeof( struct V_308 ) ) ;
F_30 ( & V_101 -> V_2 ,
sizeof( struct V_308 ) ) ;
* V_292 = V_295 + 1 ;
return 0 ;
}
static int
F_81 ( struct V_108 * V_109 , unsigned int * V_292 ,
struct V_310 * V_311 , bool V_66 )
{
struct V_294 * V_101 = V_109 [ 0 ] . V_134 ;
unsigned int V_295 = * V_292 ;
if ( V_66 ) {
if ( V_311 -> V_312 )
return F_80 ( V_109 , V_292 ,
V_311 ) ;
else
return F_79 ( V_109 , V_292 , V_311 ) ;
}
if ( V_311 -> V_312 ) {
V_109 [ V_295 ] . V_134 = F_72 ( V_311 -> V_274 ) ;
V_311 -> V_312 = false ;
} else
V_109 [ V_295 ] . V_134 = F_71 () ;
if ( V_109 [ V_295 ] . V_134 == NULL )
return - V_77 ;
V_109 [ V_295 ] . V_135 = sizeof( struct V_265 ) ;
if ( ! V_101 -> V_288 )
V_101 -> V_288 =
F_8 ( sizeof( struct V_294 ) - 4 +
V_109 [ 1 ] . V_135 ) ;
F_75 ( & V_101 -> V_289 , sizeof( struct V_265 ) ) ;
F_30 ( & V_101 -> V_2 , sizeof( struct V_265 ) ) ;
* V_292 = V_295 + 1 ;
return 0 ;
}
int
F_82 ( const unsigned int V_105 , struct V_310 * V_311 , T_1 * V_313 ,
T_6 * V_293 , struct V_314 * V_266 ,
struct V_315 * * V_316 )
{
struct V_294 * V_101 ;
struct V_280 * V_107 ;
struct V_18 * V_17 ;
struct V_4 * V_5 = V_311 -> V_5 ;
struct V_42 * V_16 = V_5 -> V_16 ;
struct V_108 V_109 [ 4 ] ;
int V_110 ;
int V_317 ;
T_1 * V_318 = NULL ;
int V_319 ;
int V_39 = 0 ;
unsigned int V_320 = 2 ;
T_7 V_321 = 0 ;
char * V_322 = NULL , * V_323 = NULL ;
F_10 ( V_49 , L_43 ) ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
V_39 = F_22 ( V_47 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
if ( V_311 -> V_324 & V_325 )
V_321 |= V_326 ;
if ( V_311 -> V_324 & V_327 )
V_321 |= V_328 ;
V_101 -> V_329 = V_330 ;
V_101 -> V_331 = F_8 ( V_311 -> V_332 ) ;
V_101 -> V_333 = F_8 ( V_321 ) ;
V_101 -> V_334 = V_335 ;
V_101 -> V_336 = F_8 ( V_311 -> V_337 ) ;
V_101 -> V_338 = F_8 ( V_311 -> V_324 & V_339 ) ;
V_317 = ( 2 * F_83 ( ( V_340 * ) V_313 , V_341 ) ) + 2 ;
V_101 -> V_270 = F_4 ( sizeof( struct V_294 ) - 4 ) ;
V_109 [ 0 ] . V_134 = ( char * ) V_101 ;
V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 ;
V_101 -> V_272 = F_4 ( V_317 - 2 ) ;
V_109 [ 0 ] . V_135 -- ;
if ( V_317 % 8 != 0 ) {
V_319 = V_317 / 8 * 8 ;
if ( V_319 < V_317 )
V_319 += 8 ;
V_318 = F_63 ( V_319 , V_198 ) ;
if ( ! V_318 )
return - V_77 ;
memcpy ( ( char * ) V_318 , ( const char * ) V_313 ,
V_317 ) ;
V_317 = V_319 ;
V_313 = V_318 ;
}
V_109 [ 1 ] . V_135 = V_317 ;
V_109 [ 1 ] . V_134 = V_313 ;
F_30 ( V_101 , V_317 - 1 ) ;
if ( ! V_17 -> V_342 )
* V_293 = V_343 ;
if ( ! ( V_17 -> V_27 & V_344 ) ||
* V_293 == V_343 )
V_101 -> V_298 = * V_293 ;
else {
V_39 = F_74 ( V_17 , V_109 , & V_320 , V_293 ) ;
if ( V_39 ) {
F_84 ( V_101 ) ;
F_47 ( V_318 ) ;
return V_39 ;
}
V_323 = V_109 [ V_320 - 1 ] . V_134 ;
}
if ( * V_293 == V_345 ) {
if ( V_17 -> V_27 & V_344 ) {
struct V_283 * V_267 =
(struct V_283 * ) V_109 [ V_320 - 1 ] . V_134 ;
V_267 -> V_291 =
F_8 ( V_17 -> V_119 -> V_297 ) ;
}
V_39 = F_81 ( V_109 , & V_320 , V_311 ,
V_5 -> V_66 ) ;
if ( V_39 ) {
F_84 ( V_101 ) ;
F_47 ( V_318 ) ;
F_47 ( V_323 ) ;
return V_39 ;
}
V_322 = V_109 [ V_320 - 1 ] . V_134 ;
}
V_39 = F_34 ( V_105 , V_16 , V_109 , V_320 , & V_110 , 0 ) ;
V_107 = (struct V_280 * ) V_109 [ 0 ] . V_134 ;
if ( V_39 != 0 ) {
F_66 ( V_5 , V_346 ) ;
if ( V_316 )
* V_316 = F_52 ( V_107 , F_33 ( V_107 ) + 4 ,
V_198 ) ;
goto V_347;
}
V_311 -> V_274 -> V_277 = V_107 -> V_276 ;
V_311 -> V_274 -> V_279 = V_107 -> V_278 ;
if ( V_266 ) {
memcpy ( V_266 , & V_107 -> V_348 , 32 ) ;
V_266 -> V_349 = V_107 -> V_349 ;
V_266 -> V_350 = V_107 -> V_351 ;
V_266 -> V_352 = V_107 -> V_333 ;
V_266 -> V_353 = F_8 ( 1 ) ;
V_266 -> V_354 = 0 ;
}
if ( V_107 -> V_355 == V_299 )
* V_293 = F_73 ( V_17 , V_107 , & V_311 -> V_274 -> V_281 ) ;
else
* V_293 = V_107 -> V_355 ;
V_347:
F_47 ( V_318 ) ;
F_47 ( V_323 ) ;
F_47 ( V_322 ) ;
F_40 ( V_110 , V_107 ) ;
return V_39 ;
}
int
F_42 ( const unsigned int V_105 , struct V_4 * V_5 , T_8 V_277 ,
T_8 V_279 , T_4 V_356 , bool V_357 , char * V_358 ,
T_4 V_359 , char * * V_360 , T_4 * V_361 )
{
struct V_362 * V_101 ;
struct V_363 * V_107 ;
struct V_18 * V_17 ;
struct V_42 * V_16 ;
struct V_108 V_109 [ 2 ] ;
int V_110 ;
int V_320 ;
int V_39 = 0 ;
F_10 ( V_49 , L_44 ) ;
if ( V_360 != NULL )
* V_360 = NULL ;
if ( V_361 )
* V_361 = 0 ;
if ( V_5 )
V_16 = V_5 -> V_16 ;
else
return - V_52 ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
V_39 = F_22 ( V_71 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
V_101 -> V_364 = F_8 ( V_356 ) ;
V_101 -> V_276 = V_277 ;
V_101 -> V_278 = V_279 ;
if ( V_359 ) {
V_101 -> V_365 = F_8 ( V_359 ) ;
V_101 -> V_366 =
F_8 ( F_58 ( struct V_362 , V_216 ) - 4 ) ;
V_109 [ 1 ] . V_134 = V_358 ;
V_109 [ 1 ] . V_135 = V_359 ;
V_320 = 2 ;
} else
V_320 = 1 ;
V_101 -> V_367 = 0 ;
V_101 -> V_368 = 0 ;
V_101 -> V_369 = F_8 ( 0xFF00 ) ;
if ( V_357 )
V_101 -> V_35 = F_8 ( V_370 ) ;
else
V_101 -> V_35 = 0 ;
V_109 [ 0 ] . V_134 = ( char * ) V_101 ;
if ( V_359 ) {
V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 - 1 ;
F_30 ( V_101 , V_359 - 1 ) ;
} else
V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 ;
V_39 = F_34 ( V_105 , V_16 , V_109 , V_320 , & V_110 , 0 ) ;
V_107 = (struct V_363 * ) V_109 [ 0 ] . V_134 ;
if ( ( V_39 != 0 ) && ( V_39 != - V_241 ) ) {
F_66 ( V_5 , V_371 ) ;
goto V_372;
} else if ( V_39 == - V_241 ) {
if ( ( V_356 != V_373 ) &&
( V_356 != V_374 ) ) {
F_66 ( V_5 , V_371 ) ;
goto V_372;
}
}
if ( ( V_361 == NULL ) || ( V_360 == NULL ) )
goto V_372;
* V_361 = F_36 ( V_107 -> V_368 ) ;
if ( * V_361 == 0 )
goto V_372;
else if ( * V_361 > 0xFF00 ) {
F_10 ( V_141 , L_45 , * V_361 ) ;
* V_361 = 0 ;
V_39 = - V_52 ;
goto V_372;
}
if ( F_33 ( V_107 ) < F_36 ( V_107 -> V_367 ) + * V_361 ) {
F_10 ( V_141 , L_46 , * V_361 ,
F_36 ( V_107 -> V_367 ) ) ;
* V_361 = 0 ;
V_39 = - V_52 ;
goto V_372;
}
* V_360 = F_56 ( * V_361 , V_198 ) ;
if ( * V_360 == NULL ) {
V_39 = - V_77 ;
goto V_372;
}
memcpy ( * V_360 ,
( char * ) & V_107 -> V_2 . V_12 + F_36 ( V_107 -> V_367 ) ,
* V_361 ) ;
V_372:
F_40 ( V_110 , V_107 ) ;
return V_39 ;
}
int
F_85 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_8 V_277 , T_8 V_279 )
{
int V_39 ;
struct V_375 V_376 ;
char * V_377 = NULL ;
V_376 . V_378 =
F_4 ( V_379 ) ;
V_39 = F_42 ( V_105 , V_5 , V_277 , V_279 ,
V_380 , true ,
( char * ) & V_376 ,
2 , & V_377 , NULL ) ;
F_10 ( V_49 , L_47 , V_39 ) ;
return V_39 ;
}
int
F_86 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_8 V_277 , T_8 V_279 )
{
struct V_381 * V_101 ;
struct V_382 * V_107 ;
struct V_18 * V_17 ;
struct V_42 * V_16 = V_5 -> V_16 ;
struct V_108 V_109 [ 1 ] ;
int V_110 ;
int V_39 = 0 ;
F_10 ( V_49 , L_48 ) ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
V_39 = F_22 ( V_56 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
V_101 -> V_276 = V_277 ;
V_101 -> V_278 = V_279 ;
V_109 [ 0 ] . V_134 = ( char * ) V_101 ;
V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 ;
V_39 = F_34 ( V_105 , V_16 , V_109 , 1 , & V_110 , 0 ) ;
V_107 = (struct V_382 * ) V_109 [ 0 ] . V_134 ;
if ( V_39 != 0 ) {
F_66 ( V_5 , V_383 ) ;
goto V_384;
}
V_384:
F_40 ( V_110 , V_107 ) ;
return V_39 ;
}
static int
F_87 ( unsigned int V_385 , unsigned int V_386 ,
struct V_1 * V_2 , unsigned int V_387 )
{
unsigned int V_388 = F_88 ( V_2 -> V_11 ) ;
char * V_389 = V_388 + 4 + ( char * ) V_2 ;
char * V_390 = 4 + V_385 + ( char * ) V_2 ;
char * V_391 = V_390 + V_386 ;
if ( V_386 < V_387 ) {
F_10 ( V_141 , L_49 ,
V_386 , V_387 ) ;
return - V_241 ;
}
if ( ( V_388 > 0x7FFFFF ) || ( V_386 > 0x7FFFFF ) ) {
F_10 ( V_141 , L_50 ,
V_386 , V_388 ) ;
return - V_241 ;
}
if ( ( V_390 > V_389 ) || ( V_391 > V_389 ) ) {
F_10 ( V_141 , L_51 ) ;
return - V_241 ;
}
return 0 ;
}
static int
F_89 ( unsigned int V_385 , unsigned int V_386 ,
struct V_1 * V_2 , unsigned int V_392 ,
char * V_192 )
{
char * V_390 = 4 + V_385 + ( char * ) V_2 ;
int V_39 ;
if ( ! V_192 )
return - V_241 ;
V_39 = F_87 ( V_385 , V_386 , V_2 , V_392 ) ;
if ( V_39 )
return V_39 ;
memcpy ( V_192 , V_390 , V_386 ) ;
return 0 ;
}
static int
F_90 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_8 V_277 , T_8 V_279 , T_9 V_393 ,
T_10 V_394 , T_10 V_395 , void * V_192 )
{
struct V_396 * V_101 ;
struct V_397 * V_107 = NULL ;
struct V_108 V_109 [ 2 ] ;
int V_39 = 0 ;
int V_110 ;
struct V_18 * V_17 ;
struct V_42 * V_16 = V_5 -> V_16 ;
F_10 ( V_49 , L_52 ) ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
V_39 = F_22 ( V_74 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
V_101 -> V_398 = V_399 ;
V_101 -> V_400 = V_393 ;
V_101 -> V_276 = V_277 ;
V_101 -> V_278 = V_279 ;
V_101 -> V_401 =
F_4 ( sizeof( struct V_396 ) - 1 - 4 ) ;
V_101 -> V_402 = F_8 ( V_394 ) ;
V_109 [ 0 ] . V_134 = ( char * ) V_101 ;
V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 ;
V_39 = F_34 ( V_105 , V_16 , V_109 , 1 , & V_110 , 0 ) ;
V_107 = (struct V_397 * ) V_109 [ 0 ] . V_134 ;
if ( V_39 ) {
F_66 ( V_5 , V_403 ) ;
goto V_404;
}
V_39 = F_89 ( F_2 ( V_107 -> V_405 ) ,
F_36 ( V_107 -> V_402 ) ,
& V_107 -> V_2 , V_395 , V_192 ) ;
V_404:
F_40 ( V_110 , V_107 ) ;
return V_39 ;
}
int
F_91 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_8 V_277 , T_8 V_279 ,
struct V_314 * V_192 )
{
return F_90 ( V_105 , V_5 , V_277 , V_279 ,
V_406 ,
sizeof( struct V_314 ) + V_341 * 2 ,
sizeof( struct V_314 ) , V_192 ) ;
}
int
F_92 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_8 V_277 , T_8 V_279 , T_11 * V_407 )
{
return F_90 ( V_105 , V_5 , V_277 , V_279 ,
V_408 ,
sizeof( struct V_409 ) ,
sizeof( struct V_409 ) , V_407 ) ;
}
static void
F_93 ( struct V_410 * V_411 )
{
struct V_18 * V_17 = V_411 -> V_412 ;
struct V_413 * V_414 = (struct V_413 * ) V_411 -> V_415 ;
unsigned int V_416 = 1 ;
if ( V_411 -> V_417 == V_418 )
V_416 = F_2 ( V_414 -> V_2 . V_22 ) ;
F_13 ( & V_17 -> V_176 ) ;
F_94 ( V_411 ) ;
F_16 ( & V_17 -> V_176 ) ;
F_95 ( V_17 , V_416 , V_419 ) ;
}
int
F_96 ( struct V_18 * V_17 )
{
struct V_420 * V_101 ;
int V_39 = 0 ;
struct V_108 V_109 ;
struct V_421 V_422 = { . V_423 = & V_109 ,
. V_424 = 1 } ;
F_10 ( V_49 , L_53 ) ;
if ( V_17 -> V_53 == V_425 ) {
struct V_426 * V_427 , * V_428 ;
struct V_42 * V_16 ;
struct V_4 * V_5 ;
F_10 ( V_49 , L_54 ) ;
F_5 ( & V_429 ) ;
F_97 (tmp, &server->smb_ses_list) {
V_16 = F_98 ( V_427 , struct V_42 , V_430 ) ;
F_97 (tmp2, &ses->tcon_list) {
V_5 = F_98 ( V_428 , struct V_4 ,
V_431 ) ;
if ( V_5 && V_5 -> V_63 ) {
F_7 ( & V_429 ) ;
V_39 = F_9 ( V_432 , V_5 ) ;
F_5 ( & V_429 ) ;
}
}
}
F_7 ( & V_429 ) ;
}
if ( V_17 -> V_53 == V_425 )
return - V_52 ;
V_39 = F_22 ( V_432 , NULL , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
V_101 -> V_2 . V_22 = F_4 ( 1 ) ;
V_109 . V_134 = ( char * ) V_101 ;
V_109 . V_135 = F_33 ( V_101 ) + 4 ;
V_39 = F_99 ( V_17 , & V_422 , NULL , F_93 , V_17 ,
V_419 ) ;
if ( V_39 )
F_10 ( V_49 , L_55 , V_39 ) ;
F_84 ( V_101 ) ;
return V_39 ;
}
int
F_100 ( const unsigned int V_105 , struct V_4 * V_5 , T_8 V_277 ,
T_8 V_279 )
{
struct V_433 * V_101 ;
struct V_18 * V_17 ;
struct V_42 * V_16 = V_5 -> V_16 ;
struct V_108 V_109 [ 1 ] ;
int V_110 ;
int V_39 = 0 ;
F_10 ( V_49 , L_56 ) ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
V_39 = F_22 ( V_68 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
V_101 -> V_276 = V_277 ;
V_101 -> V_278 = V_279 ;
V_109 [ 0 ] . V_134 = ( char * ) V_101 ;
V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 ;
V_39 = F_34 ( V_105 , V_16 , V_109 , 1 , & V_110 , 0 ) ;
if ( V_39 != 0 )
F_66 ( V_5 , V_434 ) ;
F_40 ( V_110 , V_109 [ 0 ] . V_134 ) ;
return V_39 ;
}
static int
F_101 ( struct V_108 * V_109 , struct V_435 * V_436 ,
unsigned int V_437 , int V_438 )
{
int V_39 = - V_439 ;
struct V_440 * V_101 = NULL ;
V_39 = F_22 ( V_69 , V_436 -> V_5 , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
if ( V_436 -> V_5 -> V_16 -> V_17 == NULL )
return - V_441 ;
V_101 -> V_2 . V_23 = F_8 ( V_436 -> V_442 ) ;
V_101 -> V_276 = V_436 -> V_277 ;
V_101 -> V_278 = V_436 -> V_279 ;
V_101 -> V_443 = 0 ;
V_101 -> V_444 = 0 ;
V_101 -> V_169 = 0 ;
V_101 -> V_445 = 0 ;
V_101 -> V_446 = F_8 ( V_436 -> V_447 ) ;
V_101 -> V_448 = F_102 ( V_436 -> V_385 ) ;
if ( V_438 & V_449 ) {
if ( ! ( V_438 & V_450 ) ) {
V_101 -> V_2 . V_451 =
F_8 ( F_33 ( V_101 ) + 4 ) ;
} else
V_101 -> V_2 . V_451 = 0 ;
if ( V_438 & V_452 ) {
V_101 -> V_2 . V_35 |= V_453 ;
V_101 -> V_2 . V_32 = 0xFFFFFFFF ;
V_101 -> V_2 . V_30 = 0xFFFFFFFF ;
V_101 -> V_276 = 0xFFFFFFFF ;
V_101 -> V_278 = 0xFFFFFFFF ;
}
}
if ( V_437 > V_436 -> V_447 )
V_101 -> V_454 = F_8 ( V_437 ) ;
else
V_101 -> V_454 = 0 ;
V_109 [ 0 ] . V_134 = ( char * ) V_101 ;
V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 ;
return V_39 ;
}
static void
F_103 ( struct V_410 * V_411 )
{
struct V_455 * V_456 = V_411 -> V_412 ;
struct V_4 * V_5 = F_104 ( V_456 -> V_457 -> V_458 ) ;
struct V_18 * V_17 = V_5 -> V_16 -> V_17 ;
struct V_1 * V_266 = (struct V_1 * ) V_456 -> V_109 . V_134 ;
unsigned int V_416 = 1 ;
struct V_421 V_422 = { . V_423 = & V_456 -> V_109 ,
. V_424 = 1 ,
. V_459 = V_456 -> V_460 ,
. V_461 = V_456 -> V_462 ,
. V_463 = V_456 -> V_464 ,
. V_465 = V_456 -> V_466 } ;
F_10 ( V_49 , L_57 ,
V_116 , V_411 -> V_411 , V_411 -> V_417 , V_456 -> V_204 ,
V_456 -> V_467 ) ;
switch ( V_411 -> V_417 ) {
case V_418 :
V_416 = F_2 ( V_266 -> V_22 ) ;
if ( V_17 -> V_34 ) {
int V_39 ;
V_39 = F_105 ( & V_422 , V_17 ) ;
if ( V_39 )
F_10 ( V_141 , L_58 ,
V_39 ) ;
}
F_106 ( V_456 -> V_468 ) ;
F_107 ( V_5 , V_456 -> V_468 ) ;
break;
case V_469 :
case V_470 :
V_456 -> V_204 = - V_58 ;
if ( V_17 -> V_34 && V_456 -> V_468 )
V_456 -> V_468 = 0 ;
F_106 ( V_456 -> V_468 ) ;
F_107 ( V_5 , V_456 -> V_468 ) ;
break;
default:
if ( V_456 -> V_204 != - V_471 )
V_456 -> V_204 = - V_52 ;
}
if ( V_456 -> V_204 )
F_66 ( V_5 , V_472 ) ;
F_108 ( V_473 , & V_456 -> V_474 ) ;
F_13 ( & V_17 -> V_176 ) ;
F_94 ( V_411 ) ;
F_16 ( & V_17 -> V_176 ) ;
F_95 ( V_17 , V_416 , 0 ) ;
}
int
F_109 ( struct V_455 * V_456 )
{
int V_39 , V_114 = 0 ;
struct V_1 * V_266 ;
struct V_435 V_436 ;
struct V_421 V_422 = { . V_423 = & V_456 -> V_109 ,
. V_424 = 1 } ;
struct V_18 * V_17 ;
F_10 ( V_49 , L_59 ,
V_116 , V_456 -> V_385 , V_456 -> V_467 ) ;
V_436 . V_5 = F_104 ( V_456 -> V_457 -> V_458 ) ;
V_436 . V_385 = V_456 -> V_385 ;
V_436 . V_447 = V_456 -> V_467 ;
V_436 . V_277 = V_456 -> V_457 -> V_274 . V_277 ;
V_436 . V_279 = V_456 -> V_457 -> V_274 . V_279 ;
V_436 . V_442 = V_456 -> V_442 ;
V_17 = V_436 . V_5 -> V_16 -> V_17 ;
V_39 = F_101 ( & V_456 -> V_109 , & V_436 , 0 , 0 ) ;
if ( V_39 ) {
if ( V_39 == - V_58 && V_456 -> V_20 ) {
V_456 -> V_20 = 0 ;
F_5 ( & V_17 -> V_19 ) ;
V_17 -> V_475 -- ;
F_7 ( & V_17 -> V_19 ) ;
}
return V_39 ;
}
V_266 = (struct V_1 * ) V_456 -> V_109 . V_134 ;
V_456 -> V_109 . V_135 = F_33 ( V_456 -> V_109 . V_134 ) + 4 ;
if ( V_456 -> V_20 ) {
V_266 -> V_29 = F_4 ( F_110 ( V_456 -> V_467 ,
V_476 ) ) ;
V_266 -> V_22 = V_266 -> V_29 ;
F_5 ( & V_17 -> V_19 ) ;
V_17 -> V_20 += V_456 -> V_20 -
F_2 ( V_266 -> V_29 ) ;
F_7 ( & V_17 -> V_19 ) ;
F_111 ( & V_17 -> V_477 ) ;
V_114 = V_478 ;
}
F_112 ( & V_456 -> V_479 ) ;
V_39 = F_99 ( V_436 . V_5 -> V_16 -> V_17 , & V_422 ,
V_480 , F_103 ,
V_456 , V_114 ) ;
if ( V_39 ) {
F_113 ( & V_456 -> V_479 , V_481 ) ;
F_66 ( V_436 . V_5 , V_472 ) ;
}
F_84 ( V_266 ) ;
return V_39 ;
}
int
F_114 ( const unsigned int V_105 , struct V_435 * V_436 ,
unsigned int * V_482 , char * * V_266 , int * V_483 )
{
int V_110 , V_39 = - V_439 ;
struct V_484 * V_107 = NULL ;
struct V_108 V_109 [ 1 ] ;
* V_482 = 0 ;
V_39 = F_101 ( V_109 , V_436 , 0 , 0 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_34 ( V_105 , V_436 -> V_5 -> V_16 , V_109 , 1 ,
& V_110 , V_175 ) ;
V_107 = (struct V_484 * ) V_109 [ 0 ] . V_134 ;
if ( V_107 -> V_2 . V_214 == V_485 ) {
F_40 ( V_110 , V_109 [ 0 ] . V_134 ) ;
return 0 ;
}
if ( V_39 ) {
F_66 ( V_436 -> V_5 , V_472 ) ;
F_10 ( V_141 , L_60 , V_39 ) ;
} else {
* V_482 = F_36 ( V_107 -> V_87 ) ;
if ( ( * V_482 > V_486 ) ||
( * V_482 > V_436 -> V_447 ) ) {
F_10 ( V_49 , L_61 ,
* V_482 , V_436 -> V_447 ) ;
V_39 = - V_52 ;
* V_482 = 0 ;
}
}
if ( * V_266 ) {
memcpy ( * V_266 , ( char * ) & V_107 -> V_2 . V_12 + V_107 -> V_268 ,
* V_482 ) ;
F_40 ( V_110 , V_109 [ 0 ] . V_134 ) ;
} else if ( V_110 != V_172 ) {
* V_266 = V_109 [ 0 ] . V_134 ;
if ( V_110 == V_171 )
* V_483 = V_171 ;
else if ( V_110 == V_487 )
* V_483 = V_487 ;
}
return V_39 ;
}
static void
F_115 ( struct V_410 * V_411 )
{
struct V_488 * V_489 = V_411 -> V_412 ;
struct V_4 * V_5 = F_104 ( V_489 -> V_457 -> V_458 ) ;
struct V_18 * V_17 = V_5 -> V_16 -> V_17 ;
unsigned int V_490 ;
struct V_491 * V_107 = (struct V_491 * ) V_411 -> V_415 ;
unsigned int V_416 = 1 ;
switch ( V_411 -> V_417 ) {
case V_418 :
V_416 = F_2 ( V_107 -> V_2 . V_22 ) ;
V_489 -> V_204 = F_116 ( V_411 , V_5 -> V_16 -> V_17 , 0 ) ;
if ( V_489 -> V_204 != 0 )
break;
V_490 = F_36 ( V_107 -> V_87 ) ;
if ( V_490 > V_489 -> V_467 )
V_490 &= 0xFFFF ;
if ( V_490 < V_489 -> V_467 )
V_489 -> V_204 = - V_492 ;
else
V_489 -> V_467 = V_490 ;
break;
case V_469 :
case V_470 :
V_489 -> V_204 = - V_58 ;
break;
default:
V_489 -> V_204 = - V_52 ;
break;
}
if ( V_489 -> V_204 )
F_66 ( V_5 , V_493 ) ;
F_108 ( V_473 , & V_489 -> V_474 ) ;
F_13 ( & V_17 -> V_176 ) ;
F_94 ( V_411 ) ;
F_16 ( & V_17 -> V_176 ) ;
F_95 ( V_5 -> V_16 -> V_17 , V_416 , 0 ) ;
}
int
F_117 ( struct V_488 * V_489 ,
void (* F_118)( struct V_494 * V_494 ) )
{
int V_39 = - V_439 , V_114 = 0 ;
struct V_495 * V_101 = NULL ;
struct V_4 * V_5 = F_104 ( V_489 -> V_457 -> V_458 ) ;
struct V_18 * V_17 = V_5 -> V_16 -> V_17 ;
struct V_108 V_109 ;
struct V_421 V_422 ;
V_39 = F_22 ( V_46 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 ) {
if ( V_39 == - V_58 && V_489 -> V_20 ) {
V_489 -> V_20 = 0 ;
F_5 ( & V_17 -> V_19 ) ;
V_17 -> V_475 -- ;
F_7 ( & V_17 -> V_19 ) ;
}
goto V_496;
}
V_101 -> V_2 . V_23 = F_8 ( V_489 -> V_457 -> V_442 ) ;
V_101 -> V_276 = V_489 -> V_457 -> V_274 . V_277 ;
V_101 -> V_278 = V_489 -> V_457 -> V_274 . V_279 ;
V_101 -> V_497 = 0 ;
V_101 -> V_498 = 0 ;
V_101 -> V_169 = 0 ;
V_101 -> V_448 = F_102 ( V_489 -> V_385 ) ;
V_101 -> V_268 = F_4 (
F_58 ( struct V_495 , V_216 ) - 4 ) ;
V_101 -> V_454 = 0 ;
V_109 . V_135 = F_33 ( V_101 ) + 4 - 1 ;
V_109 . V_134 = V_101 ;
V_422 . V_423 = & V_109 ;
V_422 . V_424 = 1 ;
V_422 . V_459 = V_489 -> V_460 ;
V_422 . V_461 = V_489 -> V_462 ;
V_422 . V_463 = V_489 -> V_464 ;
V_422 . V_465 = V_489 -> V_466 ;
F_10 ( V_49 , L_62 ,
V_489 -> V_385 , V_489 -> V_467 ) ;
V_101 -> V_446 = F_8 ( V_489 -> V_467 ) ;
F_30 ( & V_101 -> V_2 , V_489 -> V_467 - 1 ) ;
if ( V_489 -> V_20 ) {
V_101 -> V_2 . V_29 = F_4 ( F_110 ( V_489 -> V_467 ,
V_476 ) ) ;
V_101 -> V_2 . V_22 = V_101 -> V_2 . V_29 ;
F_5 ( & V_17 -> V_19 ) ;
V_17 -> V_20 += V_489 -> V_20 -
F_2 ( V_101 -> V_2 . V_29 ) ;
F_7 ( & V_17 -> V_19 ) ;
F_111 ( & V_17 -> V_477 ) ;
V_114 = V_478 ;
}
F_112 ( & V_489 -> V_479 ) ;
V_39 = F_99 ( V_17 , & V_422 , NULL , F_115 , V_489 ,
V_114 ) ;
if ( V_39 ) {
F_113 ( & V_489 -> V_479 , F_118 ) ;
F_66 ( V_5 , V_493 ) ;
}
V_496:
F_84 ( V_101 ) ;
return V_39 ;
}
int
F_119 ( const unsigned int V_105 , struct V_435 * V_436 ,
unsigned int * V_482 , struct V_108 * V_109 , int V_499 )
{
int V_39 = 0 ;
struct V_495 * V_101 = NULL ;
struct V_491 * V_107 = NULL ;
int V_110 ;
* V_482 = 0 ;
if ( V_499 < 1 )
return V_39 ;
V_39 = F_22 ( V_46 , V_436 -> V_5 , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
if ( V_436 -> V_5 -> V_16 -> V_17 == NULL )
return - V_441 ;
V_101 -> V_2 . V_23 = F_8 ( V_436 -> V_442 ) ;
V_101 -> V_276 = V_436 -> V_277 ;
V_101 -> V_278 = V_436 -> V_279 ;
V_101 -> V_497 = 0 ;
V_101 -> V_498 = 0 ;
V_101 -> V_169 = 0 ;
V_101 -> V_446 = F_8 ( V_436 -> V_447 ) ;
V_101 -> V_448 = F_102 ( V_436 -> V_385 ) ;
V_101 -> V_268 = F_4 (
F_58 ( struct V_495 , V_216 ) - 4 ) ;
V_101 -> V_454 = 0 ;
V_109 [ 0 ] . V_134 = ( char * ) V_101 ;
V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 - 1 ;
F_30 ( V_101 , V_436 -> V_447 - 1 ) ;
V_39 = F_34 ( V_105 , V_436 -> V_5 -> V_16 , V_109 , V_499 + 1 ,
& V_110 , 0 ) ;
V_107 = (struct V_491 * ) V_109 [ 0 ] . V_134 ;
if ( V_39 ) {
F_66 ( V_436 -> V_5 , V_493 ) ;
F_10 ( V_141 , L_63 , V_39 ) ;
} else
* V_482 = F_36 ( V_107 -> V_87 ) ;
F_40 ( V_110 , V_107 ) ;
return V_39 ;
}
static unsigned int
F_120 ( char * V_500 , char * V_391 , char * * V_501 , T_10 V_502 )
{
int V_199 ;
unsigned int V_503 = 0 ;
unsigned int V_504 = 0 ;
T_12 * V_505 ;
if ( V_500 == NULL )
return 0 ;
V_505 = ( T_12 * ) V_500 ;
while ( 1 ) {
V_505 = ( T_12 * )
( ( char * ) V_505 + V_504 ) ;
if ( ( char * ) V_505 + V_502 > V_391 ) {
F_10 ( V_141 , L_64 ) ;
break;
}
V_199 = F_36 ( V_505 -> V_506 ) ;
if ( ( char * ) V_505 + V_199 + V_502 > V_391 ) {
F_10 ( V_141 , L_65 ,
V_391 ) ;
break;
}
* V_501 = ( char * ) V_505 ;
V_503 ++ ;
V_504 = F_36 ( V_505 -> V_507 ) ;
if ( ! V_504 )
break;
}
return V_503 ;
}
int
F_121 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_8 V_277 , T_8 V_279 , int V_508 ,
struct V_509 * V_510 )
{
struct V_511 * V_101 ;
struct V_512 * V_107 = NULL ;
struct V_108 V_109 [ 2 ] ;
int V_39 = 0 ;
int V_199 ;
int V_110 = V_172 ;
unsigned char * V_513 ;
struct V_18 * V_17 ;
struct V_42 * V_16 = V_5 -> V_16 ;
T_1 V_514 = F_4 ( '*' ) ;
char * V_389 ;
unsigned int V_515 = V_516 ;
T_10 V_517 ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
V_39 = F_22 ( V_72 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
switch ( V_510 -> V_518 ) {
case V_519 :
V_101 -> V_520 = V_521 ;
V_517 = sizeof( T_12 ) - 1 ;
break;
case V_522 :
V_101 -> V_520 = V_523 ;
V_517 = sizeof( V_524 ) - 1 ;
break;
default:
F_10 ( V_141 , L_66 ,
V_510 -> V_518 ) ;
V_39 = - V_241 ;
goto V_525;
}
V_101 -> V_526 = F_8 ( V_508 ) ;
V_101 -> V_276 = V_277 ;
V_101 -> V_278 = V_279 ;
V_199 = 0x2 ;
V_513 = V_101 -> V_216 ;
memcpy ( V_513 , & V_514 , V_199 ) ;
V_101 -> V_527 =
F_4 ( sizeof( struct V_511 ) - 1 - 4 ) ;
V_101 -> V_506 = F_4 ( V_199 ) ;
V_515 = F_6 (unsigned int, output_size, server->maxBuf) ;
V_515 = F_6 (unsigned int, output_size, 2 << 15 ) ;
V_101 -> V_402 = F_8 ( V_515 ) ;
V_109 [ 0 ] . V_134 = ( char * ) V_101 ;
V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 - 1 ;
V_109 [ 1 ] . V_134 = ( char * ) ( V_101 -> V_216 ) ;
V_109 [ 1 ] . V_135 = V_199 ;
F_30 ( V_101 , V_199 - 1 ) ;
V_39 = F_34 ( V_105 , V_16 , V_109 , 2 , & V_110 , 0 ) ;
V_107 = (struct V_512 * ) V_109 [ 0 ] . V_134 ;
if ( V_39 ) {
if ( V_39 == - V_471 && V_107 -> V_2 . V_214 == V_528 ) {
V_510 -> V_529 = true ;
V_39 = 0 ;
}
F_66 ( V_5 , V_530 ) ;
goto V_525;
}
V_39 = F_87 ( F_2 ( V_107 -> V_405 ) ,
F_36 ( V_107 -> V_402 ) , & V_107 -> V_2 ,
V_517 ) ;
if ( V_39 )
goto V_525;
V_510 -> V_531 = true ;
if ( V_510 -> V_532 ) {
if ( V_510 -> V_533 )
F_84 ( V_510 -> V_532 ) ;
else
F_122 ( V_510 -> V_532 ) ;
}
V_510 -> V_532 = ( char * ) V_107 ;
V_510 -> V_534 = V_510 -> V_535 = 4 +
( char * ) & V_107 -> V_2 + F_2 ( V_107 -> V_405 ) ;
V_389 = F_33 ( V_107 ) + 4 + ( char * ) & V_107 -> V_2 ;
V_510 -> V_536 =
F_120 ( V_510 -> V_534 , V_389 ,
& V_510 -> V_535 , V_517 ) ;
V_510 -> V_537 += V_510 -> V_536 ;
F_10 ( V_49 , L_67 ,
V_510 -> V_536 , V_510 -> V_537 ,
V_510 -> V_534 , V_510 -> V_535 ) ;
if ( V_110 == V_487 )
V_510 -> V_533 = false ;
else if ( V_110 == V_171 )
V_510 -> V_533 = true ;
else
F_10 ( V_141 , L_68 ) ;
return V_39 ;
V_525:
F_40 ( V_110 , V_107 ) ;
return V_39 ;
}
static int
F_123 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_8 V_277 , T_8 V_279 , T_4 V_442 , int V_393 ,
unsigned int V_295 , void * * V_192 , unsigned int * V_502 )
{
struct V_538 * V_101 ;
struct V_539 * V_107 = NULL ;
struct V_108 * V_109 ;
int V_39 = 0 ;
int V_110 ;
unsigned int V_540 ;
struct V_18 * V_17 ;
struct V_42 * V_16 = V_5 -> V_16 ;
if ( V_16 && ( V_16 -> V_17 ) )
V_17 = V_16 -> V_17 ;
else
return - V_52 ;
if ( ! V_295 )
return - V_241 ;
V_109 = F_56 ( sizeof( struct V_108 ) * V_295 , V_198 ) ;
if ( ! V_109 )
return - V_77 ;
V_39 = F_22 ( V_75 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 ) {
F_47 ( V_109 ) ;
return V_39 ;
}
V_101 -> V_2 . V_23 = F_8 ( V_442 ) ;
V_101 -> V_398 = V_399 ;
V_101 -> V_400 = V_393 ;
V_101 -> V_276 = V_277 ;
V_101 -> V_278 = V_279 ;
V_101 -> V_541 =
F_4 ( sizeof( struct V_538 ) - 1 - 4 ) ;
V_101 -> V_542 = F_8 ( * V_502 ) ;
F_30 ( V_101 , * V_502 - 1 ) ;
memcpy ( V_101 -> V_216 , * V_192 , * V_502 ) ;
V_109 [ 0 ] . V_134 = ( char * ) V_101 ;
V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 ;
for ( V_540 = 1 ; V_540 < V_295 ; V_540 ++ ) {
F_30 ( V_101 , V_502 [ V_540 ] ) ;
F_75 ( & V_101 -> V_542 , V_502 [ V_540 ] ) ;
V_109 [ V_540 ] . V_134 = ( char * ) V_192 [ V_540 ] ;
V_109 [ V_540 ] . V_135 = V_502 [ V_540 ] ;
}
V_39 = F_34 ( V_105 , V_16 , V_109 , V_295 , & V_110 , 0 ) ;
V_107 = (struct V_539 * ) V_109 [ 0 ] . V_134 ;
if ( V_39 != 0 )
F_66 ( V_5 , V_543 ) ;
F_40 ( V_110 , V_107 ) ;
F_47 ( V_109 ) ;
return V_39 ;
}
int
F_124 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_8 V_277 , T_8 V_279 , T_1 * V_544 )
{
struct V_545 V_546 ;
void * * V_192 ;
unsigned int V_502 [ 2 ] ;
int V_39 ;
int V_199 = ( 2 * F_83 ( ( V_340 * ) V_544 , V_341 ) ) ;
V_192 = F_56 ( sizeof( void * ) * 2 , V_198 ) ;
if ( ! V_192 )
return - V_77 ;
V_546 . V_547 = 1 ;
V_546 . V_548 = 0 ;
V_546 . V_506 = F_8 ( V_199 ) ;
V_192 [ 0 ] = & V_546 ;
V_502 [ 0 ] = sizeof( struct V_545 ) ;
V_192 [ 1 ] = V_544 ;
V_502 [ 1 ] = V_199 + 2 ;
V_39 = F_123 ( V_105 , V_5 , V_277 , V_279 ,
V_24 -> V_25 , V_549 , 2 , V_192 ,
V_502 ) ;
F_47 ( V_192 ) ;
return V_39 ;
}
int
F_125 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_8 V_277 , T_8 V_279 )
{
T_6 V_550 = 1 ;
void * V_192 ;
unsigned int V_502 ;
V_192 = & V_550 ;
V_502 = 1 ;
return F_123 ( V_105 , V_5 , V_277 , V_279 ,
V_24 -> V_25 , V_551 , 1 , & V_192 ,
& V_502 ) ;
}
int
F_126 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_8 V_277 , T_8 V_279 , T_1 * V_544 )
{
struct V_552 V_546 ;
void * * V_192 ;
unsigned int V_502 [ 2 ] ;
int V_39 ;
int V_199 = ( 2 * F_83 ( ( V_340 * ) V_544 , V_341 ) ) ;
V_192 = F_56 ( sizeof( void * ) * 2 , V_198 ) ;
if ( ! V_192 )
return - V_77 ;
V_546 . V_547 = 0 ;
V_546 . V_548 = 0 ;
V_546 . V_506 = F_8 ( V_199 ) ;
V_192 [ 0 ] = & V_546 ;
V_502 [ 0 ] = sizeof( struct V_552 ) ;
V_192 [ 1 ] = V_544 ;
V_502 [ 1 ] = V_199 + 2 ;
V_39 = F_123 ( V_105 , V_5 , V_277 , V_279 ,
V_24 -> V_25 , V_553 , 2 , V_192 , V_502 ) ;
F_47 ( V_192 ) ;
return V_39 ;
}
int
F_127 ( const unsigned int V_105 , struct V_4 * V_5 , T_8 V_277 ,
T_8 V_279 , T_4 V_442 , T_11 * V_554 , bool V_555 )
{
struct V_556 V_546 ;
void * V_192 ;
unsigned int V_502 ;
V_546 . V_350 = * V_554 ;
V_192 = & V_546 ;
V_502 = sizeof( struct V_556 ) ;
if ( V_555 )
return F_123 ( V_105 , V_5 , V_277 , V_279 ,
V_442 , V_557 , 1 , & V_192 , & V_502 ) ;
else
return F_123 ( V_105 , V_5 , V_277 , V_279 ,
V_442 , V_558 , 1 , & V_192 , & V_502 ) ;
}
int
F_128 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_8 V_277 , T_8 V_279 , T_13 * V_266 )
{
unsigned int V_502 ;
V_502 = sizeof( T_13 ) ;
return F_123 ( V_105 , V_5 , V_277 , V_279 ,
V_24 -> V_25 , V_559 , 1 ,
( void * * ) & V_266 , & V_502 ) ;
}
int
F_129 ( const unsigned int V_105 , struct V_4 * V_5 ,
const T_8 V_277 , const T_8 V_279 ,
T_6 V_560 )
{
int V_39 ;
struct V_561 * V_101 = NULL ;
F_10 ( V_49 , L_69 ) ;
V_39 = F_22 ( V_57 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
V_101 -> V_562 = V_279 ;
V_101 -> V_563 = V_277 ;
V_101 -> V_355 = V_560 ;
V_101 -> V_2 . V_22 = F_4 ( 1 ) ;
V_39 = F_65 ( V_105 , V_5 -> V_16 , ( char * ) V_101 , V_564 ) ;
if ( V_39 ) {
F_66 ( V_5 , V_565 ) ;
F_10 ( V_49 , L_70 , V_39 ) ;
}
return V_39 ;
}
static void
F_130 ( struct V_566 * V_567 ,
struct V_568 * V_569 )
{
V_569 -> V_570 = F_36 ( V_567 -> V_571 ) *
F_36 ( V_567 -> V_572 ) ;
V_569 -> V_573 = F_131 ( V_567 -> V_574 ) ;
V_569 -> V_575 = F_131 ( V_567 -> V_576 ) ;
V_569 -> V_577 = F_131 ( V_567 -> V_578 ) ;
return;
}
static int
F_132 ( struct V_108 * V_109 , struct V_4 * V_5 , int V_579 ,
int V_580 , T_8 V_277 , T_8 V_279 )
{
int V_39 ;
struct V_396 * V_101 ;
F_10 ( V_49 , L_71 , V_579 ) ;
if ( ( V_5 -> V_16 == NULL ) || ( V_5 -> V_16 -> V_17 == NULL ) )
return - V_52 ;
V_39 = F_22 ( V_74 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
V_101 -> V_398 = V_581 ;
V_101 -> V_400 = V_579 ;
V_101 -> V_276 = V_277 ;
V_101 -> V_278 = V_279 ;
V_101 -> V_401 =
F_4 ( sizeof( struct V_396 ) - 1 - 4 ) ;
V_101 -> V_402 = F_8 (
V_580 + sizeof( struct V_397 ) - 1 - 4 ) ;
V_109 -> V_134 = ( char * ) V_101 ;
V_109 -> V_135 = F_33 ( V_101 ) + 4 ;
return 0 ;
}
int
F_133 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_8 V_277 , T_8 V_279 , struct V_568 * V_582 )
{
struct V_397 * V_107 = NULL ;
struct V_108 V_109 ;
int V_39 = 0 ;
int V_110 ;
struct V_42 * V_16 = V_5 -> V_16 ;
struct V_566 * V_546 = NULL ;
V_39 = F_132 ( & V_109 , V_5 , V_583 ,
sizeof( struct V_566 ) ,
V_277 , V_279 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_34 ( V_105 , V_16 , & V_109 , 1 , & V_110 , 0 ) ;
if ( V_39 ) {
F_66 ( V_5 , V_403 ) ;
goto V_584;
}
V_107 = (struct V_397 * ) V_109 . V_134 ;
V_546 = (struct V_566 * ) ( 4 +
F_2 ( V_107 -> V_405 ) + ( char * ) & V_107 -> V_2 ) ;
V_39 = F_87 ( F_2 ( V_107 -> V_405 ) ,
F_36 ( V_107 -> V_402 ) , & V_107 -> V_2 ,
sizeof( struct V_566 ) ) ;
if ( ! V_39 )
F_130 ( V_546 , V_582 ) ;
V_584:
F_40 ( V_110 , V_109 . V_134 ) ;
return V_39 ;
}
int
F_134 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_8 V_277 , T_8 V_279 , int V_579 )
{
struct V_397 * V_107 = NULL ;
struct V_108 V_109 ;
int V_39 = 0 ;
int V_110 , V_585 , V_395 ;
struct V_42 * V_16 = V_5 -> V_16 ;
unsigned int V_586 , V_385 ;
if ( V_579 == V_587 ) {
V_585 = sizeof( V_588 ) ;
V_395 = sizeof( V_588 ) ;
} else if ( V_579 == V_589 ) {
V_585 = sizeof( V_590 ) ;
V_395 = V_591 ;
} else if ( V_579 == V_592 ) {
V_585 = sizeof( struct V_593 ) ;
V_395 = sizeof( struct V_593 ) ;
} else {
F_10 ( V_49 , L_72 , V_579 ) ;
return - V_241 ;
}
V_39 = F_132 ( & V_109 , V_5 , V_579 , V_585 ,
V_277 , V_279 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_34 ( V_105 , V_16 , & V_109 , 1 , & V_110 , 0 ) ;
if ( V_39 ) {
F_66 ( V_5 , V_403 ) ;
goto V_594;
}
V_107 = (struct V_397 * ) V_109 . V_134 ;
V_586 = F_36 ( V_107 -> V_402 ) ;
V_385 = F_2 ( V_107 -> V_405 ) ;
V_39 = F_87 ( V_385 , V_586 , & V_107 -> V_2 , V_395 ) ;
if ( V_39 )
goto V_594;
if ( V_579 == V_589 )
memcpy ( & V_5 -> V_595 , 4 + V_385
+ ( char * ) & V_107 -> V_2 , F_6 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_579 == V_587 )
memcpy ( & V_5 -> V_596 , 4 + V_385
+ ( char * ) & V_107 -> V_2 , sizeof( V_588 ) ) ;
else if ( V_579 == V_592 ) {
struct V_593 * V_597 = (struct V_593 * )
( 4 + V_385 + ( char * ) & V_107 -> V_2 ) ;
V_5 -> V_598 = F_36 ( V_597 -> V_35 ) ;
V_5 -> V_599 =
F_36 ( V_597 -> V_600 ) ;
}
V_594:
F_40 ( V_110 , V_109 . V_134 ) ;
return V_39 ;
}
int
F_135 ( const unsigned int V_105 , struct V_4 * V_5 ,
const T_14 V_601 , const T_14 V_279 , const T_7 V_442 ,
const T_7 V_602 , struct V_603 * V_266 )
{
int V_39 = 0 ;
struct V_604 * V_101 = NULL ;
struct V_108 V_109 [ 2 ] ;
int V_605 ;
unsigned int V_606 ;
F_10 ( V_49 , L_73 , V_602 ) ;
V_39 = F_22 ( V_70 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
V_101 -> V_2 . V_23 = F_8 ( V_442 ) ;
V_101 -> V_607 = F_4 ( V_602 ) ;
V_101 -> V_276 = V_601 ;
V_101 -> V_278 = V_279 ;
V_606 = V_602 * sizeof( struct V_603 ) ;
F_30 ( V_101 , V_606 - sizeof( struct V_603 ) ) ;
V_109 [ 0 ] . V_134 = ( char * ) V_101 ;
V_109 [ 0 ] . V_135 = F_33 ( V_101 ) + 4 - V_606 ;
V_109 [ 1 ] . V_134 = ( char * ) V_266 ;
V_109 [ 1 ] . V_135 = V_606 ;
F_25 ( & V_5 -> V_79 . V_608 . V_609 ) ;
V_39 = F_34 ( V_105 , V_5 -> V_16 , V_109 , 2 , & V_605 , V_610 ) ;
if ( V_39 ) {
F_10 ( V_49 , L_74 , V_39 ) ;
F_66 ( V_5 , V_611 ) ;
}
return V_39 ;
}
int
F_136 ( const unsigned int V_105 , struct V_4 * V_5 ,
const T_14 V_601 , const T_14 V_279 , const T_7 V_442 ,
const T_14 V_447 , const T_14 V_385 , const T_7 V_612 ,
const bool V_613 )
{
struct V_603 V_614 ;
V_614 . V_448 = F_102 ( V_385 ) ;
V_614 . V_446 = F_102 ( V_447 ) ;
V_614 . V_35 = F_8 ( V_612 ) ;
if ( ! V_613 && V_612 != V_615 )
V_614 . V_35 |= F_8 ( V_616 ) ;
return F_135 ( V_105 , V_5 , V_601 , V_279 , V_442 , 1 , & V_614 ) ;
}
int
F_137 ( const unsigned int V_105 , struct V_4 * V_5 ,
T_6 * V_617 , const T_15 V_618 )
{
int V_39 ;
struct V_619 * V_101 = NULL ;
F_10 ( V_49 , L_75 ) ;
V_39 = F_22 ( V_57 , V_5 , ( void * * ) & V_101 ) ;
if ( V_39 )
return V_39 ;
V_101 -> V_2 . V_22 = F_4 ( 1 ) ;
V_101 -> V_14 = F_4 ( 36 ) ;
F_30 ( V_101 , 12 ) ;
memcpy ( V_101 -> V_620 , V_617 , 16 ) ;
V_101 -> V_621 = V_618 ;
V_39 = F_65 ( V_105 , V_5 -> V_16 , ( char * ) V_101 , V_564 ) ;
if ( V_39 ) {
F_66 ( V_5 , V_565 ) ;
F_10 ( V_49 , L_76 , V_39 ) ;
}
return V_39 ;
}
