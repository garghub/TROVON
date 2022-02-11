static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 > V_4 )
V_3 = V_4 ;
return F_2 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_8 :
case V_9 : {
F_4 ( & V_6 -> V_10 -> V_11 , V_6 -> V_12 ,
V_6 -> V_13 , V_6 -> V_14 ) ;
break;
}
}
}
static bool F_5 ( struct V_5 * V_6 )
{
struct V_15 * V_10 = V_6 -> V_10 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
V_6 -> V_17 = F_6 ( F_7 ( V_10 , 0 ) , F_8 ( V_10 , 0 ) ) ;
if ( ! V_6 -> V_17 ) {
F_9 ( V_18 L_1 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
break;
}
case V_8 : {
void T_1 * V_21 , * V_22 ;
V_21 = F_6 ( F_7 ( V_10 , 0 ) , F_8 ( V_10 , 0 ) ) ;
if ( ! V_21 ) {
F_9 ( V_18 L_1 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_22 = F_6 ( F_7 ( V_10 , 2 ) , F_8 ( V_10 , 2 ) ) ;
if ( ! V_22 ) {
F_10 ( V_21 ) ;
F_9 ( V_18 L_1 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_6 -> V_21 = V_21 ;
V_6 -> V_22 = V_22 ;
break;
}
case V_23 : {
V_6 -> V_24 = F_11 ( F_7 ( V_10 , 1 ) , F_8 ( V_10 , 1 ) ) ;
if ( ! V_6 -> V_24 ) {
F_9 ( V_18 L_1 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
if ( F_12 ( & V_6 -> V_24 -> V_25 ) & V_26 ) {
F_13 ( V_27 , & V_6 -> V_24 -> V_28 ) ;
return true ;
}
break;
}
case V_9 : {
void T_1 * V_21 ;
unsigned long V_29 , V_30 , V_31 ;
V_29 = ( unsigned long ) F_7 ( V_10 , 0 ) ;
V_30 = F_8 ( V_10 , 0 ) ;
V_31 = F_14 ( V_10 , 0 ) ;
V_21 = F_6 ( V_29 , V_30 ) ;
if ( ! V_21 ) {
F_15 ( L_2 ,
V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_6 -> V_21 = V_21 ;
break;
}
}
return true ;
}
static void F_16 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
F_10 ( V_6 -> V_17 ) ;
}
break;
case V_8 : {
F_10 ( V_6 -> V_21 ) ;
F_10 ( V_6 -> V_22 ) ;
}
break;
case V_23 : {
F_10 ( V_6 -> V_24 ) ;
}
break;
case V_9 :
F_10 ( V_6 -> V_21 ) ;
break;
}
}
static T_2 F_17 ( int V_32 , void * V_33 )
{
T_2 V_34 ;
struct V_5 * V_6 = V_33 ;
V_34 = F_18 ( V_6 ) ;
return V_34 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_35 * V_36 , T_3 V_37 , int * V_38 )
{
int V_39 , V_40 , V_41 , V_42 , V_43 ;
unsigned char * V_44 ;
V_44 = F_20 ( V_36 ) ;
if ( V_44 ) {
V_39 = F_21 ( V_44 , V_37 , & V_38 [ 2 ] , & V_38 [ 0 ] , & V_38 [ 1 ] ) ;
F_22 ( V_44 ) ;
if ( V_39 != - 1 )
return V_39 ;
}
V_43 = V_37 ;
V_40 = 64 ;
V_41 = 32 ;
V_42 = V_43 / ( V_40 * V_41 ) ;
if ( V_42 > 1024 ) {
V_40 = 255 ;
V_41 = 63 ;
V_42 = V_43 / ( V_40 * V_41 ) ;
}
V_38 [ 0 ] = V_40 ;
V_38 [ 1 ] = V_41 ;
V_38 [ 2 ] = V_42 ;
return 0 ;
}
static T_4 F_23 ( struct V_5 * V_6 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < 2000 ; V_47 ++ ) {
if ( F_12 ( & V_46 -> V_48 ) &
V_49 ) {
F_13 ( V_49 ,
& V_46 -> V_48 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static T_4 F_25 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < 2000 ; V_47 ++ ) {
if ( F_12 ( V_46 -> V_52 )
& V_53 ) {
F_13 ( V_54 ,
V_46 -> V_52 ) ;
F_13 ( V_55 ,
V_46 -> V_56 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static T_4 F_26 ( struct V_5 * V_57 )
{
struct V_58 T_1 * V_59 = V_57 -> V_24 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < 2000 ; V_47 ++ ) {
if ( F_12 ( & V_59 -> V_25 )
& V_26 ) {
F_13 ( V_27 ,
& V_59 -> V_28 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static bool F_27 ( struct V_5 * V_57 )
{
struct V_60 * V_46 = V_57 -> V_61 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < 2000 ; V_47 ++ ) {
if ( F_12 ( V_46 -> V_25 )
& V_62 ) {
F_13 ( V_62 ,
V_46 -> V_25 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static void F_28 ( struct V_5 * V_6 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
int V_63 = 30 ;
F_13 ( V_64 , & V_46 -> V_65 ) ;
do {
if ( F_23 ( V_6 ) )
break;
else {
V_63 -- ;
F_9 ( V_18 L_3 , V_6 -> V_19 -> V_20 , V_63 ) ;
}
} while ( V_63 != 0 );
}
static void F_29 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
int V_63 = 30 ;
F_13 ( V_66 , V_46 -> V_56 ) ;
do {
if ( F_25 ( V_6 ) )
break;
else {
V_63 -- ;
F_9 ( V_18 L_4 , V_6 -> V_19 -> V_20 , V_63 ) ;
}
} while ( V_63 != 0 );
}
static void F_30 ( struct V_5 * V_57 )
{
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
int V_63 = 30 ;
F_13 ( V_64 , & V_46 -> V_65 ) ;
F_13 ( V_67 , & V_46 -> V_68 ) ;
do {
if ( F_26 ( V_57 ) ) {
break;
} else {
V_63 -- ;
F_9 ( V_18 L_4 , V_57 -> V_19 -> V_20 , V_63 ) ;
}
} while ( V_63 != 0 );
return;
}
static void F_31 ( struct V_5 * V_57 )
{
int V_63 = 15 ;
struct V_60 * V_46 = V_57 -> V_61 ;
F_13 ( V_64 , V_46 -> V_65 ) ;
do {
if ( F_27 ( V_57 ) )
break;
V_63 -- ;
F_15 ( L_5
L_6 ,
V_57 -> V_19 -> V_20 , V_63 ) ;
} while ( V_63 != 0 );
}
static void F_32 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
F_28 ( V_6 ) ;
}
break;
case V_8 : {
F_29 ( V_6 ) ;
}
break;
case V_23 : {
F_30 ( V_6 ) ;
}
break;
case V_9 :
F_31 ( V_6 ) ;
break;
}
}
static bool F_33 ( struct V_5 * V_6 )
{
bool V_69 = true ;
void * V_70 ;
T_5 V_71 ;
struct V_15 * V_10 = V_6 -> V_10 ;
switch ( V_6 -> V_7 ) {
case V_8 : {
struct V_50 * V_46 ;
V_6 -> V_12 = F_34 ( sizeof( struct V_50 ) , 32 ) ;
V_70 = F_35 ( & V_10 -> V_11 , V_6 -> V_12 ,
& V_71 , V_72 ) ;
if ( ! V_70 ) {
F_15 ( L_7 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_6 -> V_14 = V_71 ;
V_6 -> V_13 = V_70 ;
V_46 = (struct V_50 * ) V_70 ;
V_6 -> V_51 = V_46 ;
if ( V_6 -> V_10 -> V_73 == V_74 ) {
V_46 -> V_56 = F_36 ( V_75 ) ;
V_46 -> V_76 = F_36 ( V_77 ) ;
V_46 -> V_52 = F_36 ( V_78 ) ;
V_46 -> V_79 = F_36 ( V_80 ) ;
} else {
V_46 -> V_56 = F_36 ( V_81 ) ;
V_46 -> V_76 = F_36 ( V_82 ) ;
V_46 -> V_52 = F_36 ( V_83 ) ;
V_46 -> V_79 = F_36 ( V_84 ) ;
}
V_46 -> V_85 = F_37 ( V_86 ) ;
V_46 -> V_87 = F_37 ( V_88 ) ;
V_46 -> V_89 = F_37 ( V_90 ) ;
}
break;
case V_9 : {
struct V_60 * V_46 ;
V_6 -> V_12 = F_34 ( sizeof( struct V_60 ) , 32 ) ;
V_70 = F_35 ( & V_10 -> V_11 , V_6 -> V_12 ,
& V_71 , V_72 ) ;
if ( ! V_70 ) {
F_15 ( L_7 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_6 -> V_14 = V_71 ;
V_6 -> V_13 = V_70 ;
V_46 = (struct V_60 * ) V_70 ;
V_6 -> V_61 = V_46 ;
V_46 -> V_91 = F_36 ( V_92 ) ;
V_46 -> V_93 = F_36 ( V_94 ) ;
V_46 -> V_95 = F_36 ( V_96 ) ;
V_46 -> V_97 = F_36 ( V_98 ) ;
V_46 -> V_99 = F_36 ( V_100 ) ;
V_46 -> V_101 = F_36 ( V_102 ) ;
V_46 -> V_103 = F_36 ( V_104 ) ;
V_46 -> V_65 = F_36 ( V_105 ) ;
V_46 -> V_106 = F_36 ( V_107 ) ;
V_46 -> V_108 = F_36 ( V_109 ) ;
V_46 -> V_110 = F_36 ( V_111 ) ;
V_46 -> V_68 = F_36 ( V_112 ) ;
V_46 -> V_25 = F_36 ( V_113 ) ;
V_46 -> V_114 = F_36 ( V_115 ) ;
V_46 -> V_116 = F_36 ( V_117 ) ;
V_46 -> V_118 = F_36 ( V_119 ) ;
V_46 -> V_120 = F_36 ( V_121 ) ;
V_46 -> V_122 = F_36 ( V_123 ) ;
V_46 -> V_124 = F_36 ( V_125 ) ;
V_46 -> V_126 = F_36 ( V_127 ) ;
V_46 -> V_128 = F_36 ( V_129 ) ;
V_46 -> V_130 = F_36 ( V_131 ) ;
V_46 -> V_132 = F_36 ( V_133 ) ;
V_46 -> V_85 = F_36 ( V_134 ) ;
V_46 -> V_87 = F_36 ( V_135 ) ;
V_46 -> V_136 = F_36 ( V_137 ) ;
}
break;
default:
break;
}
return V_69 ;
}
static int F_38 ( struct V_5 * V_6 )
{
struct V_15 * V_10 = V_6 -> V_10 ;
void * V_70 ;
T_5 V_71 ;
struct V_138 * V_139 ;
int V_47 = 0 , V_140 = 0 ;
T_5 V_141 ;
unsigned long V_12 ;
unsigned long V_142 ;
unsigned long V_143 ;
T_6 V_144 ;
for ( V_47 = 0 ; V_47 < V_145 ; V_47 ++ )
for ( V_140 = 0 ; V_140 < V_146 ; V_140 ++ )
V_6 -> V_147 [ V_47 ] [ V_140 ] = V_148 ;
V_142 = V_149 ;
V_143 = V_150 ;
V_144 = V_6 -> V_151 ;
if( ( V_144 & 0xFF ) >= 3 ) {
V_142 = ( V_152 << ( ( V_144 >> 8 ) & 0xFF ) ) * 1024 ;
V_143 = ( V_142 / 4096 ) ;
}
V_6 -> V_19 -> V_153 = V_142 / 512 ;
V_6 -> V_19 -> V_154 = V_143 ;
V_12 = F_34 ( sizeof( struct V_138 ) + ( V_143 - 1 ) * sizeof( struct V_155 ) , 32 ) ;
V_6 -> V_156 = V_12 * V_157 ;
V_70 = F_39 ( & V_10 -> V_11 , V_6 -> V_156 , & V_71 , V_72 ) ;
if( ! V_70 ) {
F_9 ( V_18 L_8 , V_6 -> V_19 -> V_20 ) ;
return - V_158 ;
}
V_6 -> V_70 = V_70 ;
V_6 -> V_71 = V_71 ;
memset ( V_70 , 0 , V_6 -> V_156 ) ;
V_139 = V_70 ;
V_6 -> V_159 = ( unsigned long ) V_70 - ( unsigned long ) V_71 ;
for( V_47 = 0 ; V_47 < V_157 ; V_47 ++ ) {
V_141 = V_71 + F_40 ( struct V_138 , V_160 ) ;
switch ( V_6 -> V_7 ) {
case V_16 :
case V_8 :
V_139 -> V_141 = V_141 >> 5 ;
break;
case V_23 :
case V_9 :
V_139 -> V_141 = V_141 ;
break;
}
V_6 -> V_161 [ V_47 ] = V_139 ;
V_139 -> V_6 = V_6 ;
F_41 ( & V_139 -> V_162 ) ;
F_42 ( & V_139 -> V_162 , & V_6 -> V_163 ) ;
V_139 = (struct V_138 * ) ( ( unsigned long ) V_139 + V_12 ) ;
V_71 = V_71 + V_12 ;
}
return 0 ;
}
static void F_43 ( struct V_164 * V_165 )
{
struct V_5 * V_6 = F_44 ( V_165 ,
struct V_5 , V_166 ) ;
char * V_167 = ( char * ) V_6 -> V_168 ;
T_6 T_1 * V_169 = NULL ;
char T_1 * V_170 = NULL ;
int V_171 , V_172 ;
struct V_1 * V_173 ;
char V_174 , V_175 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_169 = ( T_6 T_1 * ) ( & V_46 -> V_89 [ 0 ] ) ;
V_170 = ( char T_1 * ) ( & V_46 -> V_89 [ 21 ] ) ;
break;
}
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_169 = ( T_6 T_1 * ) ( & V_46 -> V_89 [ 0 ] ) ;
V_170 = ( char T_1 * ) ( & V_46 -> V_89 [ 21 ] ) ;
break;
}
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
V_169 = ( T_6 T_1 * ) ( & V_46 -> V_136 [ 0 ] ) ;
V_170 = ( char T_1 * ) ( & V_46 -> V_136 [ 21 ] ) ;
break;
}
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
V_169 = ( T_6 T_1 * ) ( & V_46 -> V_136 [ 0 ] ) ;
V_170 = ( char T_1 * ) ( & V_46 -> V_136 [ 21 ] ) ;
break;
}
}
F_45 ( & V_6 -> V_176 ) ;
if ( F_12 ( V_169 ) != V_177 )
return;
for ( V_171 = 0 ; V_171 < V_145 - 1 ;
V_171 ++ ) {
V_175 = F_46 ( V_170 ) ;
V_174 = ( * V_167 ) ^ V_175 ;
if ( V_174 != 0 ) {
* V_167 = V_175 ;
for ( V_172 = 0 ; V_172 < V_146 ;
V_172 ++ ) {
if ( ( V_174 & 0x01 ) == 1 &&
( V_175 & 0x01 ) == 1 ) {
F_47 ( V_6 -> V_19 ,
0 , V_171 , V_172 ) ;
} else if ( ( V_174 & 0x01 ) == 1
&& ( V_175 & 0x01 ) == 0 ) {
V_173 = F_48 ( V_6 -> V_19 ,
0 , V_171 , V_172 ) ;
if ( V_173 != NULL ) {
F_49 ( V_173 ) ;
F_50 ( V_173 ) ;
}
}
V_175 >>= 1 ;
V_174 >>= 1 ;
}
}
V_170 ++ ;
V_167 ++ ;
}
}
static int
F_51 ( struct V_15 * V_10 , struct V_5 * V_6 )
{
unsigned long V_31 ;
int V_178 , V_47 ;
V_178 = F_52 ( V_10 , 1 , V_179 ,
V_180 ) ;
if ( V_178 > 0 ) {
F_53 ( L_9 , V_6 -> V_19 -> V_20 ) ;
V_31 = 0 ;
} else {
V_178 = F_52 ( V_10 , 1 , 1 ,
V_181 | V_182 ) ;
if ( V_178 < 1 )
return V_183 ;
V_31 = V_184 ;
}
V_6 -> V_185 = V_178 ;
for ( V_47 = 0 ; V_47 < V_178 ; V_47 ++ ) {
if ( F_54 ( F_55 ( V_10 , V_47 ) , F_17 ,
V_31 , L_10 , V_6 ) ) {
F_56 ( L_11 ,
V_6 -> V_19 -> V_20 , F_55 ( V_10 , V_47 ) ) ;
goto V_186;
}
}
return V_187 ;
V_186:
while ( -- V_47 >= 0 )
F_57 ( F_55 ( V_10 , V_47 ) , V_6 ) ;
F_58 ( V_10 ) ;
return V_183 ;
}
static int F_59 ( struct V_15 * V_10 , const struct V_188 * V_189 )
{
struct V_190 * V_19 ;
struct V_5 * V_6 ;
T_4 V_191 , V_192 ;
int error ;
error = F_60 ( V_10 ) ;
if( error ) {
return - V_193 ;
}
V_19 = F_61 ( & V_194 , sizeof( struct V_5 ) ) ;
if( ! V_19 ) {
goto V_195;
}
error = F_62 ( V_10 , F_63 ( 64 ) ) ;
if( error ) {
error = F_62 ( V_10 , F_63 ( 32 ) ) ;
if( error ) {
F_9 ( V_196
L_12 ,
V_19 -> V_20 ) ;
goto V_197;
}
}
F_64 ( & V_198 ) ;
V_191 = V_10 -> V_191 -> V_199 ;
V_192 = V_10 -> V_200 ;
V_6 = (struct V_5 * ) V_19 -> V_201 ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 -> V_10 = V_10 ;
V_6 -> V_19 = V_19 ;
V_19 -> V_202 = V_146 ;
V_19 -> V_203 = V_145 ;
V_19 -> V_204 = 16 ;
V_19 -> V_205 = V_206 ;
V_19 -> V_207 = V_4 ;
V_19 -> V_208 = V_209 ;
V_19 -> V_210 = ( V_191 << 8 ) | V_192 ;
F_65 ( V_10 , V_19 ) ;
F_66 ( V_10 ) ;
error = F_67 ( V_10 , L_10 ) ;
if( error ) {
goto V_197;
}
F_68 ( & V_6 -> V_211 ) ;
F_68 ( & V_6 -> V_212 ) ;
F_68 ( & V_6 -> V_213 ) ;
F_68 ( & V_6 -> V_214 ) ;
F_68 ( & V_6 -> V_215 ) ;
F_68 ( & V_6 -> V_216 ) ;
V_6 -> V_217 |= ( V_218 |
V_219 |
V_220 ) ;
V_6 -> V_217 &= ~ V_221 ;
F_41 ( & V_6 -> V_163 ) ;
V_6 -> V_7 = V_189 -> V_222 ;
error = F_5 ( V_6 ) ;
if( ! error ) {
goto V_223;
}
error = F_33 ( V_6 ) ;
if ( ! error )
goto V_224;
error = F_69 ( V_6 ) ;
if( ! error ) {
goto V_225;
}
error = F_38 ( V_6 ) ;
if( error ) {
goto V_225;
}
error = F_70 ( V_19 , & V_10 -> V_11 ) ;
if( error ) {
goto V_226;
}
if ( F_51 ( V_10 , V_6 ) == V_183 )
goto V_227;
F_71 ( V_6 ) ;
F_72 ( & V_6 -> V_166 , F_43 ) ;
F_73 ( & V_6 -> V_176 , 16 ) ;
F_73 ( & V_6 -> V_228 , 16 ) ;
V_6 -> V_229 = V_230 ;
F_74 ( & V_6 -> V_231 ) ;
V_6 -> V_231 . V_232 = V_233 + F_75 ( 6 * V_234 ) ;
V_6 -> V_231 . V_235 = ( unsigned long ) V_6 ;
V_6 -> V_231 . V_236 = & V_237 ;
F_76 ( & V_6 -> V_231 ) ;
if( F_77 ( V_6 ) )
goto V_238;
F_78 ( V_19 ) ;
return 0 ;
V_238:
F_79 ( & V_6 -> V_231 ) ;
F_80 ( & V_6 -> V_166 ) ;
F_81 ( V_6 ) ;
F_32 ( V_6 ) ;
F_82 ( V_10 , V_6 ) ;
V_227:
F_83 ( V_19 ) ;
V_226:
F_84 ( V_6 ) ;
V_225:
F_3 ( V_6 ) ;
V_224:
F_16 ( V_6 ) ;
V_223:
F_85 ( V_10 ) ;
V_197:
F_86 ( V_19 ) ;
V_195:
F_87 ( V_10 ) ;
return - V_193 ;
}
static void F_82 ( struct V_15 * V_10 ,
struct V_5 * V_6 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_6 -> V_185 ; V_47 ++ )
F_57 ( F_55 ( V_10 , V_47 ) , V_6 ) ;
F_58 ( V_10 ) ;
}
static int F_88 ( struct V_15 * V_10 , T_7 V_239 )
{
T_6 V_240 ;
struct V_190 * V_19 = F_89 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_201 ;
V_240 = F_90 ( V_6 ) ;
F_82 ( V_10 , V_6 ) ;
F_79 ( & V_6 -> V_231 ) ;
F_80 ( & V_6 -> V_166 ) ;
F_81 ( V_6 ) ;
F_32 ( V_6 ) ;
F_65 ( V_10 , V_19 ) ;
F_91 ( V_10 ) ;
F_87 ( V_10 ) ;
F_92 ( V_10 , F_93 ( V_10 , V_239 ) ) ;
return 0 ;
}
static int F_94 ( struct V_15 * V_10 )
{
int error ;
struct V_190 * V_19 = F_89 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_201 ;
F_92 ( V_10 , V_241 ) ;
F_95 ( V_10 , V_241 , 0 ) ;
F_96 ( V_10 ) ;
if ( F_60 ( V_10 ) ) {
F_56 ( L_13 , V_242 ) ;
return - V_193 ;
}
error = F_62 ( V_10 , F_63 ( 64 ) ) ;
if ( error ) {
error = F_62 ( V_10 , F_63 ( 32 ) ) ;
if ( error ) {
F_56 ( L_12 ,
V_19 -> V_20 ) ;
goto V_243;
}
}
F_66 ( V_10 ) ;
if ( F_51 ( V_10 , V_6 ) == V_183 )
goto V_244;
F_71 ( V_6 ) ;
F_72 ( & V_6 -> V_166 , F_43 ) ;
F_73 ( & V_6 -> V_176 , 16 ) ;
F_73 ( & V_6 -> V_228 , 16 ) ;
V_6 -> V_229 = V_230 ;
F_74 ( & V_6 -> V_231 ) ;
V_6 -> V_231 . V_232 = V_233 + F_75 ( 6 * V_234 ) ;
V_6 -> V_231 . V_235 = ( unsigned long ) V_6 ;
V_6 -> V_231 . V_236 = & V_237 ;
F_76 ( & V_6 -> V_231 ) ;
return 0 ;
V_244:
F_81 ( V_6 ) ;
F_32 ( V_6 ) ;
V_243:
F_83 ( V_19 ) ;
F_84 ( V_6 ) ;
F_16 ( V_6 ) ;
F_85 ( V_10 ) ;
F_86 ( V_19 ) ;
F_87 ( V_10 ) ;
return - V_193 ;
}
static T_4 F_97 ( struct V_5 * V_6 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_245 , & V_46 -> V_65 ) ;
if ( ! F_23 ( V_6 ) ) {
F_9 ( V_18
L_14
, V_6 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_98 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_246 , V_46 -> V_56 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_18
L_14
, V_6 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_99 ( struct V_5 * V_57 )
{
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
F_13 ( V_245 , & V_46 -> V_65 ) ;
F_13 ( V_67 , & V_46 -> V_68 ) ;
if ( ! F_26 ( V_57 ) ) {
F_9 ( V_18
L_14
, V_57 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_100 ( struct V_5 * V_57 )
{
struct V_60 * V_46 = V_57 -> V_61 ;
F_13 ( V_245 , V_46 -> V_65 ) ;
if ( ! F_27 ( V_57 ) ) {
F_15 ( L_15
L_16 , V_57 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_101 ( struct V_5 * V_6 )
{
T_4 V_247 = 0 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
V_247 = F_97 ( V_6 ) ;
}
break;
case V_8 : {
V_247 = F_98 ( V_6 ) ;
}
break;
case V_23 : {
V_247 = F_99 ( V_6 ) ;
}
break;
case V_9 :
V_247 = F_100 ( V_6 ) ;
break;
}
return V_247 ;
}
static void F_102 ( struct V_138 * V_248 )
{
struct V_249 * V_250 = V_248 -> V_250 ;
F_103 ( V_250 ) ;
}
static void F_104 ( struct V_138 * V_248 )
{
struct V_5 * V_6 = V_248 -> V_6 ;
struct V_249 * V_250 = V_248 -> V_250 ;
unsigned long V_31 ;
F_105 ( & V_6 -> V_251 ) ;
F_102 ( V_248 ) ;
V_248 -> V_252 = V_253 ;
F_106 ( & V_6 -> V_212 , V_31 ) ;
F_42 ( & V_248 -> V_162 , & V_6 -> V_163 ) ;
F_107 ( & V_6 -> V_212 , V_31 ) ;
V_250 -> V_254 ( V_250 ) ;
}
static void F_108 ( struct V_138 * V_248 )
{
struct V_249 * V_250 = V_248 -> V_250 ;
struct V_255 * V_256 = (struct V_255 * ) V_250 -> V_257 ;
V_250 -> V_258 = V_259 << 16 ;
if ( V_256 ) {
int V_260 =
sizeof( struct V_255 ) < V_261
? sizeof( struct V_255 ) : V_261 ;
memset ( V_256 , 0 , V_261 ) ;
memcpy ( V_256 , V_248 -> V_160 . V_262 , V_260 ) ;
V_256 -> V_263 = V_264 ;
V_256 -> V_265 = 1 ;
}
}
static T_8 F_90 ( struct V_5 * V_6 )
{
T_8 V_266 = 0 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_266 = F_12 ( & V_46 -> V_267 ) ;
F_13 ( V_266 | V_268 , \
& V_46 -> V_267 ) ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_266 = F_12 ( V_46 -> V_79 ) ;
F_13 ( 0 , V_46 -> V_79 ) ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
V_266 = F_12 ( & V_46 -> V_269 ) ;
F_13 ( V_266 | V_270 , & V_46 -> V_269 ) ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
F_13 ( V_271 , V_46 -> V_103 ) ;
}
break;
}
return V_266 ;
}
static void F_109 ( struct V_5 * V_6 ,
struct V_138 * V_248 , bool error )
{
T_4 V_189 , V_172 ;
V_189 = V_248 -> V_250 -> V_73 -> V_189 ;
V_172 = V_248 -> V_250 -> V_73 -> V_172 ;
if ( ! error ) {
if ( V_6 -> V_147 [ V_189 ] [ V_172 ] == V_148 )
V_6 -> V_147 [ V_189 ] [ V_172 ] = V_272 ;
V_248 -> V_250 -> V_258 = V_259 << 16 ;
F_104 ( V_248 ) ;
} else{
switch ( V_248 -> V_160 . V_273 ) {
case V_274 : {
V_6 -> V_147 [ V_189 ] [ V_172 ] = V_148 ;
V_248 -> V_250 -> V_258 = V_275 << 16 ;
F_104 ( V_248 ) ;
}
break;
case V_276 :
case V_277 : {
V_6 -> V_147 [ V_189 ] [ V_172 ] = V_148 ;
V_248 -> V_250 -> V_258 = V_278 << 16 ;
F_104 ( V_248 ) ;
}
break;
case V_279 : {
V_6 -> V_147 [ V_189 ] [ V_172 ] = V_272 ;
F_108 ( V_248 ) ;
F_104 ( V_248 ) ;
}
break;
default:
F_9 ( V_18
L_17
, V_6 -> V_19 -> V_20
, V_189
, V_172
, V_248 -> V_160 . V_273 ) ;
V_6 -> V_147 [ V_189 ] [ V_172 ] = V_148 ;
V_248 -> V_250 -> V_258 = V_275 << 16 ;
F_104 ( V_248 ) ;
break;
}
}
}
static void F_110 ( struct V_5 * V_6 , struct V_138 * V_280 , bool error )
{
int V_189 , V_172 ;
if ( ( V_280 -> V_6 != V_6 ) || ( V_280 -> V_252 != V_281 ) ) {
if ( V_280 -> V_252 == V_282 ) {
struct V_249 * V_283 = V_280 -> V_250 ;
if ( V_283 ) {
V_189 = V_283 -> V_73 -> V_189 ;
V_172 = V_283 -> V_73 -> V_172 ;
V_283 -> V_258 |= V_284 << 16 ;
F_104 ( V_280 ) ;
F_9 ( V_18 L_18 ,
V_6 -> V_19 -> V_20 , V_280 ) ;
}
return;
}
F_9 ( V_18 L_19
L_20
L_21
, V_6 -> V_19 -> V_20
, V_6
, V_280
, V_280 -> V_6
, V_280 -> V_252
, F_111 ( & V_6 -> V_251 ) ) ;
return;
}
F_109 ( V_6 , V_280 , error ) ;
}
static void F_112 ( struct V_5 * V_6 )
{
int V_47 = 0 ;
T_6 V_285 , V_286 ;
struct V_287 * V_288 ;
bool error ;
struct V_138 * V_280 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
T_6 V_48 ;
V_48 = F_12 ( & V_46 -> V_48 ) &
V_6 -> V_289 ;
F_13 ( V_48 , & V_46 -> V_48 ) ;
while( ( ( V_285 = F_12 ( & V_46 -> V_290 ) ) != 0xFFFFFFFF )
&& ( V_47 ++ < V_206 ) ) {
V_288 = (struct V_287 * ) ( V_6 -> V_159 + ( V_285 << 5 ) ) ;
V_280 = F_44 ( V_288 , struct V_138 , V_160 ) ;
error = ( V_285 & V_291 ) ? true : false ;
F_110 ( V_6 , V_280 , error ) ;
}
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_292 , V_46 -> V_52 ) ;
for ( V_47 = 0 ; V_47 < V_293 ; V_47 ++ ) {
V_285 = V_46 -> V_294 [ V_47 ] ;
if ( V_285 != 0 ) {
V_46 -> V_294 [ V_47 ] = 0 ;
V_288 = (struct V_287 * ) ( V_6 -> V_159 + ( V_285 << 5 ) ) ;
V_280 = F_44 ( V_288 , struct V_138 , V_160 ) ;
error = ( V_285 & V_291 ) ? true : false ;
F_110 ( V_6 , V_280 , error ) ;
}
V_46 -> V_295 [ V_47 ] = 0 ;
}
V_46 -> V_296 = 0 ;
V_46 -> V_297 = 0 ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
while ( ( F_12 ( & V_46 -> V_101 ) & V_298 ) && ( V_47 ++ < V_206 ) ) {
V_285 = F_12 ( & V_46 -> V_299 ) ;
V_286 = ( V_285 & 0xFFFFFFF0 ) ;
V_288 = (struct V_287 * ) ( V_6 -> V_159 + V_286 ) ;
V_280 = F_44 ( V_288 , struct V_138 , V_160 ) ;
error = ( V_285 & V_300 ) ? true : false ;
F_110 ( V_6 , V_280 , error ) ;
}
}
break;
case V_9 : {
struct V_60 * V_301 = V_6 -> V_61 ;
T_6 V_302 ;
T_6 V_296 , V_303 , V_304 , V_305 , V_306 ;
unsigned long V_31 ;
V_305 = F_111 ( & V_6 -> V_251 ) ;
for ( V_47 = 0 ; V_47 < V_305 ; V_47 ++ ) {
F_106 ( & V_6 -> V_214 , V_31 ) ;
V_302 =
V_301 -> V_294 [ 0 ] . V_304 + 1 ;
V_296 = V_301 -> V_296 ;
if ( ( V_296 & 0xFFF ) !=
( V_302 & 0xFFF ) ) {
V_306 = V_296 & 0x4000 ;
V_303 = ( V_296 & 0xFFF ) + 1 ;
V_303 %= V_307 ;
V_301 -> V_296 = V_303 ? ( V_303 | V_306 ) :
( ( V_306 ^ 0x4000 ) + 1 ) ;
V_296 = V_301 -> V_296 ;
F_107 ( & V_6 -> V_214 , V_31 ) ;
V_304 = V_301 -> V_294 [ V_296 &
0xFFF ] . V_304 ;
V_286 = ( V_304 & 0xFFFFFFF0 ) ;
V_288 = (struct V_287 * )
( V_6 -> V_159 + V_286 ) ;
V_280 = F_44 ( V_288 ,
struct V_138 , V_160 ) ;
error = ( V_304 &
V_300 ) ?
true : false ;
F_110 ( V_6 , V_280 , error ) ;
F_13 ( V_296 ,
V_301 -> V_128 ) ;
} else {
F_107 ( & V_6 -> V_214 , V_31 ) ;
F_113 ( 10 ) ;
}
}
V_301 -> V_297 = 0 ;
V_301 -> V_296 = 0x40FF ;
}
break;
}
}
static void F_114 ( struct V_15 * V_10 )
{
struct V_190 * V_19 = F_89 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_201 ;
int V_308 = 0 ;
F_115 ( V_6 ) ;
F_83 ( V_19 ) ;
F_80 ( & V_6 -> V_166 ) ;
F_79 ( & V_6 -> V_231 ) ;
F_90 ( V_6 ) ;
F_81 ( V_6 ) ;
F_32 ( V_6 ) ;
V_6 -> V_217 |= V_221 ;
V_6 -> V_217 &= ~ V_309 ;
for ( V_308 = 0 ; V_308 < V_206 ; V_308 ++ ) {
if ( ! F_111 ( & V_6 -> V_251 ) )
break;
F_18 ( V_6 ) ;
F_24 ( 25 ) ;
}
if ( F_111 ( & V_6 -> V_251 ) ) {
int V_47 ;
F_101 ( V_6 ) ;
F_112 ( V_6 ) ;
for ( V_47 = 0 ; V_47 < V_157 ; V_47 ++ ) {
struct V_138 * V_248 = V_6 -> V_161 [ V_47 ] ;
if ( V_248 -> V_252 == V_281 ) {
V_248 -> V_252 = V_282 ;
V_248 -> V_250 -> V_258 = V_284 << 16 ;
F_104 ( V_248 ) ;
}
}
}
F_82 ( V_10 , V_6 ) ;
F_84 ( V_6 ) ;
F_3 ( V_6 ) ;
F_16 ( V_6 ) ;
F_85 ( V_10 ) ;
F_86 ( V_19 ) ;
F_87 ( V_10 ) ;
}
static void F_116 ( struct V_15 * V_10 )
{
struct V_190 * V_19 = F_89 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_201 ;
F_79 ( & V_6 -> V_231 ) ;
F_90 ( V_6 ) ;
F_82 ( V_10 , V_6 ) ;
F_80 ( & V_6 -> V_166 ) ;
F_81 ( V_6 ) ;
F_32 ( V_6 ) ;
}
static int F_117 ( void )
{
int error = 0 ;
error = F_118 ( & V_310 ) ;
return error ;
}
static void F_119 ( void )
{
F_120 ( & V_310 ) ;
}
static void F_121 ( struct V_5 * V_6 ,
T_8 V_240 )
{
T_8 V_311 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_311 = V_240 & ~ ( V_312 |
V_313 |
V_314 ) ;
F_13 ( V_311 , & V_46 -> V_267 ) ;
V_6 -> V_289 = ~ ( V_240 & V_311 ) & 0x000000ff ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_311 = V_240 | ( V_315 |
V_316 |
V_317 |
V_53 ) ;
F_13 ( V_311 , V_46 -> V_79 ) ;
V_6 -> V_289 = ( V_240 | V_311 ) & 0x0000000f ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
V_311 = ~ ( V_318 | V_319 | V_320 ) ;
F_13 ( V_240 & V_311 , & V_46 -> V_269 ) ;
V_6 -> V_289 = ~ ( V_240 & V_311 ) & 0x0000000f ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
V_311 = V_321 ;
F_13 ( V_240 | V_311 , V_46 -> V_103 ) ;
break;
}
}
}
static int F_122 ( struct V_5 * V_6 ,
struct V_138 * V_248 , struct V_249 * V_250 )
{
struct V_287 * V_160 = (struct V_287 * ) & V_248 -> V_160 ;
T_9 * V_322 = ( T_9 * ) & V_160 -> V_323 ;
T_10 V_324 , V_325 ;
int V_326 = 0x30 ;
T_10 V_327 = 0 ;
int V_47 ;
struct V_328 * V_329 ;
int V_330 ;
V_248 -> V_250 = V_250 ;
memset ( V_160 , 0 , sizeof( struct V_287 ) ) ;
V_160 -> V_331 = V_250 -> V_73 -> V_189 ;
V_160 -> V_332 = V_250 -> V_73 -> V_172 ;
V_160 -> V_333 = 1 ;
V_160 -> V_334 = 0 ;
memcpy ( V_160 -> V_335 , V_250 -> V_336 , V_250 -> V_337 ) ;
V_330 = F_123 ( V_250 ) ;
if ( F_124 ( V_330 > V_6 -> V_19 -> V_154 || V_330 < 0 ) )
return V_183 ;
F_125 (pcmd, sg, nseg, i) {
V_327 = F_126 ( F_127 ( V_329 ) ) ;
V_324 = F_126 ( F_128 ( F_129 ( V_329 ) ) ) ;
V_325 = F_126 ( F_130 ( F_129 ( V_329 ) ) ) ;
if ( V_325 == 0 ) {
struct V_338 * V_339 = (struct V_338 * ) V_322 ;
V_339 -> V_340 = V_324 ;
V_339 -> V_327 = V_327 ;
V_322 += sizeof ( struct V_338 ) ;
V_326 += sizeof ( struct V_338 ) ;
} else {
struct V_155 * V_339 = (struct V_155 * ) V_322 ;
V_339 -> V_341 = V_325 ;
V_339 -> V_340 = V_324 ;
V_339 -> V_327 = V_327 | F_126 ( V_342 ) ;
V_322 += sizeof ( struct V_155 ) ;
V_326 += sizeof ( struct V_155 ) ;
}
}
V_160 -> V_343 = ( T_4 ) V_330 ;
V_160 -> V_344 = F_131 ( V_250 ) ;
V_160 -> V_345 = V_326 / 0x100 + ( V_326 % 0x100 ? 1 : 0 ) ;
if ( V_326 > 256 )
V_160 -> V_346 |= V_347 ;
if ( V_250 -> V_348 == V_349 )
V_160 -> V_346 |= V_350 ;
V_248 -> V_351 = V_326 ;
return V_187 ;
}
static void F_132 ( struct V_5 * V_6 , struct V_138 * V_248 )
{
T_6 V_141 = V_248 -> V_141 ;
struct V_287 * V_160 = (struct V_287 * ) & V_248 -> V_160 ;
F_45 ( & V_6 -> V_251 ) ;
V_248 -> V_252 = V_281 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
if ( V_160 -> V_346 & V_347 )
F_13 ( V_141 | V_352 ,
& V_46 -> V_353 ) ;
else
F_13 ( V_141 , & V_46 -> V_353 ) ;
break;
}
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
T_6 V_354 , V_355 = V_46 -> V_297 ;
V_354 = ( ( V_355 + 1 ) % V_293 ) ;
V_46 -> V_295 [ V_354 ] = 0 ;
if ( V_160 -> V_346 & V_347 ) {
V_46 -> V_295 [ V_355 ] =
V_141 | V_352 ;
} else {
V_46 -> V_295 [ V_355 ] = V_141 ;
}
V_355 ++ ;
V_355 %= V_293 ;
V_46 -> V_297 = V_355 ;
F_13 ( V_356 , V_46 -> V_56 ) ;
}
break;
case V_23 : {
struct V_58 T_1 * V_59 = V_6 -> V_24 ;
T_6 V_357 , V_351 ;
V_351 = ( V_248 -> V_351 > 0x300 ) ? 0x300 : V_248 -> V_351 ;
V_357 = ( V_141 | ( ( V_351 - 1 ) >> 6 ) | 1 ) ;
if ( V_6 -> V_358 ) {
F_13 ( V_6 -> V_358 , & V_59 -> V_359 ) ;
F_13 ( V_357 , & V_59 -> V_360 ) ;
} else {
F_13 ( V_357 , & V_59 -> V_360 ) ;
}
}
break;
case V_9 : {
struct V_60 * V_301 = V_6 -> V_61 ;
T_11 V_303 ;
T_11 V_297 , V_306 ;
unsigned long V_31 ;
struct V_361 * V_362 ;
F_106 ( & V_6 -> V_213 , V_31 ) ;
V_297 = V_301 -> V_297 ;
V_362 = (struct V_361 * ) & ( V_301 -> V_295 [ V_297 & 0xFF ] ) ;
V_362 -> V_363 = F_130 ( V_141 ) ;
V_362 -> V_304 = F_128 ( V_141 ) ;
V_362 -> V_327 = V_248 -> V_351 >> 2 ;
V_160 -> V_334 = F_128 ( V_141 ) ;
V_306 = V_297 & 0x4000 ;
V_303 = V_297 + 1 ;
V_303 &= ( V_364 - 1 ) ;
V_301 -> V_297 = V_303 ? ( V_303 | V_306 ) :
( V_306 ^ 0x4000 ) ;
F_13 ( V_297 , V_301 -> V_120 ) ;
F_107 ( & V_6 -> V_213 , V_31 ) ;
break;
}
}
}
static void F_133 ( struct V_5 * V_6 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_6 -> V_217 &= ~ V_365 ;
F_13 ( V_366 , & V_46 -> V_65 ) ;
if ( ! F_23 ( V_6 ) ) {
F_9 ( V_18
L_22
, V_6 -> V_19 -> V_20 ) ;
}
}
static void F_134 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
V_6 -> V_217 &= ~ V_365 ;
F_13 ( V_367 , V_46 -> V_56 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_18
L_22
, V_6 -> V_19 -> V_20 ) ;
}
}
static void F_135 ( struct V_5 * V_57 )
{
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
V_57 -> V_217 &= ~ V_365 ;
F_13 ( V_366 , & V_46 -> V_65 ) ;
F_13 ( V_67 , & V_46 -> V_68 ) ;
if ( ! F_26 ( V_57 ) ) {
F_9 ( V_18
L_22
, V_57 -> V_19 -> V_20 ) ;
}
return;
}
static void F_136 ( struct V_5 * V_57 )
{
struct V_60 * V_46 = V_57 -> V_61 ;
V_57 -> V_217 &= ~ V_365 ;
F_13 ( V_366 , V_46 -> V_65 ) ;
if ( ! F_27 ( V_57 ) )
F_15 ( L_23
L_24 , V_57 -> V_19 -> V_20 ) ;
}
static void F_81 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
F_133 ( V_6 ) ;
}
break;
case V_8 : {
F_134 ( V_6 ) ;
}
break;
case V_23 : {
F_135 ( V_6 ) ;
}
break;
case V_9 :
F_136 ( V_6 ) ;
break;
}
}
static void F_84 ( struct V_5 * V_6 )
{
F_4 ( & V_6 -> V_10 -> V_11 , V_6 -> V_156 , V_6 -> V_70 , V_6 -> V_71 ) ;
}
static void F_137 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_368 , & V_46 -> V_68 ) ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_369 , V_46 -> V_56 ) ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
F_13 ( V_370 , & V_46 -> V_68 ) ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
F_13 ( V_371 ,
V_46 -> V_68 ) ;
}
break;
}
}
static void F_138 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_372 , & V_46 -> V_68 ) ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_373 , V_46 -> V_56 ) ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
F_13 ( V_374 , & V_46 -> V_68 ) ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
F_13 ( V_375 ,
V_46 -> V_68 ) ;
}
break;
}
}
struct V_376 T_1 * F_139 ( struct V_5 * V_6 )
{
struct V_376 T_1 * V_377 = NULL ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_377 = (struct V_376 T_1 * ) & V_46 -> V_87 ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_377 = (struct V_376 T_1 * ) V_46 -> V_87 ;
}
break;
case V_23 : {
struct V_58 T_1 * V_59 = V_6 -> V_24 ;
V_377 = (struct V_376 T_1 * ) & V_59 -> V_87 ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
V_377 = (struct V_376 T_1 * ) V_46 -> V_87 ;
}
break;
}
return V_377 ;
}
static struct V_376 T_1 * F_140 ( struct V_5 * V_6 )
{
struct V_376 T_1 * V_378 = NULL ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_378 = (struct V_376 T_1 * ) & V_46 -> V_85 ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_378 = (struct V_376 T_1 * ) V_46 -> V_85 ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
V_378 = (struct V_376 T_1 * ) & V_46 -> V_85 ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
V_378 = (struct V_376 T_1 * ) V_46 -> V_85 ;
}
break;
}
return V_378 ;
}
static T_6
F_141 ( struct V_5 * V_6 ,
struct V_376 T_1 * V_379 )
{
T_4 * V_380 ;
T_4 * V_381 = NULL ;
T_6 T_1 * V_382 ;
T_6 V_383 , V_384 , * V_385 = NULL ;
V_382 = ( T_6 T_1 * ) V_379 -> V_235 ;
V_383 = F_12 ( & V_379 -> V_384 ) ;
if ( V_383 > 0 ) {
V_381 = F_142 ( 128 , V_386 ) ;
V_385 = ( T_6 * ) V_381 ;
if ( V_381 == NULL )
return 0 ;
V_384 = V_383 ;
while ( V_384 >= 4 ) {
* V_385 ++ = F_12 ( V_382 ) ;
V_382 ++ ;
V_384 -= 4 ;
}
if ( V_384 )
* V_385 = F_12 ( V_382 ) ;
V_385 = ( T_6 * ) V_381 ;
}
while ( V_383 > 0 ) {
V_380 = & V_6 -> V_387 [ V_6 -> V_388 ] ;
* V_380 = * V_381 ;
V_6 -> V_388 ++ ;
V_6 -> V_388 %= V_389 ;
V_381 ++ ;
V_383 -- ;
}
F_22 ( V_385 ) ;
F_137 ( V_6 ) ;
return 1 ;
}
T_6
F_143 ( struct V_5 * V_6 ,
struct V_376 T_1 * V_379 ) {
T_4 * V_380 ;
T_4 T_1 * V_382 ;
T_6 V_383 ;
if ( V_6 -> V_7 & ( V_23 | V_9 ) )
return F_141 ( V_6 , V_379 ) ;
V_382 = ( T_4 T_1 * ) V_379 -> V_235 ;
V_383 = F_12 ( & V_379 -> V_384 ) ;
while ( V_383 > 0 ) {
V_380 = & V_6 -> V_387 [ V_6 -> V_388 ] ;
* V_380 = F_46 ( V_382 ) ;
V_6 -> V_388 ++ ;
V_6 -> V_388 %= V_389 ;
V_382 ++ ;
V_383 -- ;
}
F_137 ( V_6 ) ;
return 1 ;
}
static void F_144 ( struct V_5 * V_6 )
{
unsigned long V_31 ;
struct V_376 T_1 * V_379 ;
T_12 V_390 ;
F_106 ( & V_6 -> V_215 , V_31 ) ;
V_379 = F_139 ( V_6 ) ;
V_390 = ( V_6 -> V_388 - V_6 -> V_391 - 1 ) &
( V_389 - 1 ) ;
if ( V_390 >= F_12 ( & V_379 -> V_384 ) ) {
if ( F_143 ( V_6 , V_379 ) == 0 )
V_6 -> V_217 |= V_392 ;
} else
V_6 -> V_217 |= V_392 ;
F_107 ( & V_6 -> V_215 , V_31 ) ;
}
static void F_145 ( struct V_5 * V_6 )
{
T_4 * V_380 ;
struct V_376 T_1 * V_393 ;
T_4 * V_381 = NULL ;
T_6 T_1 * V_382 ;
T_6 V_394 = 0 , V_384 , * V_385 = NULL , V_235 ;
if ( V_6 -> V_217 & V_220 ) {
V_381 = F_142 ( 128 , V_386 ) ;
V_385 = ( T_6 * ) V_381 ;
if ( V_381 == NULL )
return;
V_6 -> V_217 &= ( ~ V_220 ) ;
V_393 = F_140 ( V_6 ) ;
V_382 = ( T_6 T_1 * ) V_393 -> V_235 ;
while ( ( V_6 -> V_395 != V_6 -> V_396 )
&& ( V_394 < 124 ) ) {
V_380 = & V_6 -> V_397 [ V_6 -> V_395 ] ;
* V_381 = * V_380 ;
V_6 -> V_395 ++ ;
V_6 -> V_395 %= V_389 ;
V_381 ++ ;
V_394 ++ ;
}
V_384 = V_394 ;
V_381 = ( T_4 * ) V_385 ;
while ( V_384 >= 4 ) {
V_235 = * V_385 ++ ;
F_13 ( V_235 , V_382 ) ;
V_382 ++ ;
V_384 -= 4 ;
}
if ( V_384 ) {
V_235 = * V_385 ;
F_13 ( V_235 , V_382 ) ;
}
F_13 ( V_394 , & V_393 -> V_384 ) ;
F_22 ( V_381 ) ;
F_138 ( V_6 ) ;
}
}
void
F_146 ( struct V_5 * V_6 )
{
T_4 * V_380 ;
struct V_376 T_1 * V_393 ;
T_4 T_1 * V_382 ;
T_12 V_394 = 0 ;
if ( V_6 -> V_7 & ( V_23 | V_9 ) ) {
F_145 ( V_6 ) ;
return;
}
if ( V_6 -> V_217 & V_220 ) {
V_6 -> V_217 &= ( ~ V_220 ) ;
V_393 = F_140 ( V_6 ) ;
V_382 = ( T_4 T_1 * ) V_393 -> V_235 ;
while ( ( V_6 -> V_395 != V_6 -> V_396 )
&& ( V_394 < 124 ) ) {
V_380 = & V_6 -> V_397 [ V_6 -> V_395 ] ;
F_147 ( * V_380 , V_382 ) ;
V_6 -> V_395 ++ ;
V_6 -> V_395 %= V_389 ;
V_382 ++ ;
V_394 ++ ;
}
F_13 ( V_394 , & V_393 -> V_384 ) ;
F_138 ( V_6 ) ;
}
}
static void F_148 ( struct V_5 * V_6 )
{
unsigned long V_31 ;
F_106 ( & V_6 -> V_216 , V_31 ) ;
V_6 -> V_217 |= V_220 ;
if ( V_6 -> V_395 != V_6 -> V_396 )
F_146 ( V_6 ) ;
if ( V_6 -> V_395 == V_6 -> V_396 )
V_6 -> V_217 |= V_218 ;
F_107 ( & V_6 -> V_216 , V_31 ) ;
}
static void F_149 ( struct V_5 * V_6 )
{
T_6 V_25 ;
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_25 = F_12 ( & V_46 -> V_25 ) ;
do {
F_13 ( V_25 , & V_46 -> V_25 ) ;
if ( V_25 & V_398 )
F_144 ( V_6 ) ;
if ( V_25 & V_399 )
F_148 ( V_6 ) ;
V_25 = F_12 ( & V_46 -> V_25 ) ;
} while ( V_25 & ( V_398
| V_399 ) );
}
static void F_150 ( struct V_5 * V_57 )
{
T_6 V_25 ;
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
V_25 = F_12 ( & V_46 -> V_25 ) ;
do {
F_13 ( V_25 , & V_46 -> V_28 ) ;
F_12 ( & V_46 -> V_28 ) ;
if ( V_25 & V_400 )
F_144 ( V_57 ) ;
if ( V_25 & V_401 )
F_148 ( V_57 ) ;
if ( V_25 & V_26 )
F_151 ( V_57 ) ;
V_25 = F_12 ( & V_46 -> V_25 ) ;
} while ( V_25 & ( V_400
| V_401
| V_26 ) );
}
static void F_152 ( struct V_5 * V_57 )
{
T_6 V_25 ;
struct V_60 * V_301 = V_57 -> V_61 ;
V_25 = F_12 ( V_301 -> V_25 ) ;
do {
F_13 ( V_25 , V_301 -> V_25 ) ;
if ( V_25 & V_62 )
F_153 ( V_57 ) ;
if ( V_25 & V_402 )
F_144 ( V_57 ) ;
if ( V_25 & V_403 )
F_148 ( V_57 ) ;
V_25 = F_12 ( V_301 -> V_25 ) ;
} while ( V_25 & ( V_402
| V_403
| V_62 ) );
}
static void F_154 ( struct V_5 * V_6 )
{
T_6 V_285 ;
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
struct V_287 * V_288 ;
struct V_138 * V_280 ;
bool error ;
while ( ( V_285 = F_12 ( & V_46 -> V_290 ) ) != 0xFFFFFFFF ) {
V_288 = (struct V_287 * ) ( V_6 -> V_159 + ( V_285 << 5 ) ) ;
V_280 = F_44 ( V_288 , struct V_138 , V_160 ) ;
error = ( V_285 & V_291 ) ? true : false ;
F_110 ( V_6 , V_280 , error ) ;
}
}
static void F_155 ( struct V_5 * V_6 )
{
T_6 V_355 ;
T_6 V_285 ;
struct V_50 * V_46 = V_6 -> V_51 ;
struct V_287 * V_288 ;
struct V_138 * V_280 ;
bool error ;
V_355 = V_46 -> V_296 ;
while ( ( V_285 = V_46 -> V_294 [ V_355 ] ) != 0 ) {
V_46 -> V_294 [ V_355 ] = 0 ;
V_288 = (struct V_287 * ) ( V_6 -> V_159 + ( V_285 << 5 ) ) ;
V_280 = F_44 ( V_288 , struct V_138 , V_160 ) ;
error = ( V_285 & V_291 ) ? true : false ;
F_110 ( V_6 , V_280 , error ) ;
V_355 ++ ;
V_355 %= V_293 ;
V_46 -> V_296 = V_355 ;
}
}
static void F_156 ( struct V_5 * V_6 )
{
struct V_58 T_1 * V_59 ;
struct V_287 * V_160 ;
struct V_138 * V_248 ;
T_6 V_285 , V_286 , V_404 = 0 ;
int error ;
V_59 = V_6 -> V_24 ;
while ( ( V_285 = F_12 ( & V_59 -> V_299 ) ) !=
0xFFFFFFFF ) {
V_286 = ( V_285 & 0xFFFFFFF0 ) ;
V_160 = (struct V_287 * ) ( V_6 -> V_159
+ V_286 ) ;
V_248 = F_44 ( V_160 , struct V_138 ,
V_160 ) ;
error = ( V_285 & V_300 )
? true : false ;
F_110 ( V_6 , V_248 , error ) ;
V_404 ++ ;
if ( V_404 == V_405 ) {
F_13 ( V_406 ,
& V_59 -> V_68 ) ;
V_404 = 0 ;
}
}
}
static void F_157 ( struct V_5 * V_6 )
{
T_8 V_302 , V_296 , V_303 , V_306 ;
T_6 V_304 , V_286 ;
int error ;
struct V_60 * V_301 ;
struct V_287 * V_160 ;
struct V_138 * V_248 ;
unsigned long V_31 ;
F_106 ( & V_6 -> V_214 , V_31 ) ;
V_301 = V_6 -> V_61 ;
V_302 = V_301 -> V_294 [ 0 ] . V_304 + 1 ;
V_296 = V_301 -> V_296 ;
if ( ( V_296 & 0xFFF ) != ( V_302 & 0xFFF ) ) {
do {
V_306 = V_296 & 0x4000 ;
V_303 = ( V_296 & 0xFFF ) + 1 ;
V_303 %= V_307 ;
V_301 -> V_296 = V_303 ? ( V_303 | V_306 ) :
( ( V_306 ^ 0x4000 ) + 1 ) ;
V_296 = V_301 -> V_296 ;
V_304 = V_301 -> V_294 [ V_296 &
0xFFF ] . V_304 ;
V_286 = ( V_304 & 0xFFFFFFF0 ) ;
V_160 = (struct V_287 * ) ( V_6 -> V_159
+ V_286 ) ;
V_248 = F_44 ( V_160 ,
struct V_138 , V_160 ) ;
error = ( V_304 & V_300 )
? true : false ;
F_110 ( V_6 , V_248 , error ) ;
F_13 ( V_296 , V_301 -> V_128 ) ;
} while ( ( V_296 & 0xFFF ) !=
( V_302 & 0xFFF ) );
}
F_13 ( V_407 ,
V_301 -> V_130 ) ;
F_12 ( V_301 -> V_130 ) ;
F_107 ( & V_6 -> V_214 , V_31 ) ;
}
static void F_158 ( struct V_5 * V_6 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_49 , & V_46 -> V_48 ) ;
F_159 ( & V_6 -> V_166 ) ;
}
static void F_160 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_54 , V_46 -> V_52 ) ;
F_159 ( & V_6 -> V_166 ) ;
}
static void F_151 ( struct V_5 * V_6 )
{
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
F_13 ( V_27 , & V_46 -> V_28 ) ;
F_159 ( & V_6 -> V_166 ) ;
}
static void F_153 ( struct V_5 * V_6 )
{
struct V_60 * V_46 = V_6 -> V_61 ;
F_13 ( V_62 , V_46 -> V_25 ) ;
F_12 ( V_46 -> V_25 ) ;
F_159 ( & V_6 -> V_166 ) ;
}
static int F_161 ( struct V_5 * V_6 )
{
T_6 V_48 ;
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_48 = F_12 ( & V_46 -> V_48 ) &
V_6 -> V_289 ;
if ( ! ( V_48 & V_408 ) )
return V_409 ;
do {
F_13 ( V_48 , & V_46 -> V_48 ) ;
if ( V_48 & V_410 )
F_149 ( V_6 ) ;
if ( V_48 & V_411 )
F_154 ( V_6 ) ;
if ( V_48 & V_49 )
F_158 ( V_6 ) ;
V_48 = F_12 ( & V_46 -> V_48 ) &
V_6 -> V_289 ;
} while ( V_48 & ( V_410
| V_411
| V_49 ) );
return V_412 ;
}
static int F_162 ( struct V_5 * V_6 )
{
T_6 V_25 ;
struct V_50 * V_46 = V_6 -> V_51 ;
V_25 = F_12 ( V_46 -> V_52 ) &
V_6 -> V_289 ;
if ( ! V_25 )
return V_409 ;
do {
F_13 ( ~ V_25 , V_46 -> V_52 ) ;
F_13 ( V_55 , V_46 -> V_56 ) ;
if ( V_25 & V_315 )
F_144 ( V_6 ) ;
if ( V_25 & V_316 )
F_148 ( V_6 ) ;
if ( V_25 & V_317 )
F_155 ( V_6 ) ;
if ( V_25 & V_53 )
F_160 ( V_6 ) ;
V_25 = F_12 ( V_46 -> V_52 ) &
V_6 -> V_289 ;
} while ( V_25 & ( V_315
| V_316
| V_317
| V_53 ) );
return V_412 ;
}
static int F_163 ( struct V_5 * V_57 )
{
T_6 V_413 ;
struct V_58 T_1 * V_59 = V_57 -> V_24 ;
V_413 = F_12 ( & V_59 -> V_101 ) &
( V_298 |
V_414 ) ;
if ( ! V_413 )
return V_409 ;
do {
if ( V_413 & V_414 )
F_150 ( V_57 ) ;
if ( V_413 & V_298 )
F_156 ( V_57 ) ;
V_413 = F_12 ( & V_59 -> V_101 ) ;
} while ( V_413 & ( V_298 |
V_414 ) );
return V_412 ;
}
static T_2 F_164 ( struct V_5 * V_57 )
{
T_8 V_413 ;
struct V_60 * V_301 = V_57 -> V_61 ;
V_413 = F_12 ( V_301 -> V_101 ) &
( V_415 |
V_416 ) ;
if ( ! V_413 )
return V_409 ;
do {
if ( V_413 &
V_415 )
F_157 ( V_57 ) ;
if ( V_413 &
V_416 )
F_152 ( V_57 ) ;
V_413 = F_12 ( V_301 -> V_101 ) ;
} while ( V_413 &
( V_415 |
V_416 ) );
return V_412 ;
}
static T_2 F_18 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 :
return F_161 ( V_6 ) ;
break;
case V_8 :
return F_162 ( V_6 ) ;
break;
case V_23 :
return F_163 ( V_6 ) ;
case V_9 :
return F_164 ( V_6 ) ;
default:
return V_409 ;
}
}
static void F_165 ( struct V_5 * V_6 )
{
if ( V_6 ) {
if ( V_6 -> V_217 & V_365 ) {
T_6 V_240 ;
V_6 -> V_217 &= ~ V_365 ;
V_240 = F_90 ( V_6 ) ;
F_81 ( V_6 ) ;
F_32 ( V_6 ) ;
F_121 ( V_6 , V_240 ) ;
}
}
}
void F_166 ( struct V_5 * V_6 )
{
T_6 V_47 ;
if ( V_6 -> V_217 & V_392 ) {
for ( V_47 = 0 ; V_47 < 15 ; V_47 ++ ) {
if ( V_6 -> V_217 & V_392 ) {
V_6 -> V_217 &= ~ V_392 ;
V_6 -> V_391 = 0 ;
V_6 -> V_388 = 0 ;
F_137 ( V_6 ) ;
F_113 ( 30 ) ;
} else if ( V_6 -> V_391 !=
V_6 -> V_388 ) {
V_6 -> V_391 = 0 ;
V_6 -> V_388 = 0 ;
F_113 ( 30 ) ;
} else
break;
}
}
}
static int F_167 ( struct V_5 * V_6 ,
struct V_249 * V_417 )
{
char * V_44 ;
unsigned short V_418 ;
int V_419 = 0 , V_420 = 0 ;
unsigned long V_31 ;
struct V_421 * V_422 ;
T_6 V_423 = ( T_6 ) V_417 -> V_336 [ 5 ] << 24 |
( T_6 ) V_417 -> V_336 [ 6 ] << 16 |
( T_6 ) V_417 -> V_336 [ 7 ] << 8 |
( T_6 ) V_417 -> V_336 [ 8 ] ;
struct V_328 * V_329 ;
V_418 = F_168 ( V_417 ) ;
V_329 = F_169 ( V_417 ) ;
V_44 = F_170 ( F_171 ( V_329 ) ) + V_329 -> V_424 ;
if ( V_418 > 1 ) {
V_419 = V_425 ;
goto V_426;
}
V_420 += V_329 -> V_327 ;
if ( V_420 > sizeof( struct V_421 ) ) {
V_419 = V_425 ;
F_53 ( L_25 , V_242 ) ;
goto V_426;
}
V_422 = (struct V_421 * ) V_44 ;
switch ( V_423 ) {
case V_427 : {
unsigned char * V_428 ;
T_4 * V_429 ;
T_6 V_394 = 0 ;
V_428 = F_142 ( V_430 , V_386 ) ;
if ( ! V_428 ) {
V_419 = V_425 ;
F_53 ( L_26 , V_242 ) ;
goto V_426;
}
V_429 = V_428 ;
F_106 ( & V_6 -> V_215 , V_31 ) ;
if ( V_6 -> V_391 != V_6 -> V_388 ) {
unsigned int V_431 = V_6 -> V_391 ;
unsigned int V_432 = V_6 -> V_388 ;
unsigned int V_433 = F_172 ( V_432 , V_431 , V_389 ) ;
V_394 = F_173 ( V_432 , V_431 , V_389 ) ;
if ( V_394 > V_430 )
V_394 = V_430 ;
if ( V_394 <= V_433 )
memcpy ( V_429 , V_6 -> V_387 + V_431 , V_394 ) ;
else {
memcpy ( V_429 , V_6 -> V_387 + V_431 , V_433 ) ;
memcpy ( V_429 + V_433 , V_6 -> V_387 , V_394 - V_433 ) ;
}
V_6 -> V_391 = ( V_6 -> V_391 + V_394 ) % V_389 ;
}
memcpy ( V_422 -> V_434 , V_428 ,
V_394 ) ;
if ( V_6 -> V_217 & V_392 ) {
struct V_376 T_1 * V_379 ;
V_6 -> V_217 &= ~ V_392 ;
V_379 = F_139 ( V_6 ) ;
if ( F_143 ( V_6 , V_379 ) == 0 )
V_6 -> V_217 |= V_392 ;
}
F_107 ( & V_6 -> V_215 , V_31 ) ;
F_22 ( V_428 ) ;
V_422 -> V_435 . V_436 = V_394 ;
if ( V_6 -> V_229 == V_437 )
V_422 -> V_435 . V_438 =
V_439 ;
else
V_422 -> V_435 . V_438 =
V_440 ;
break;
}
case V_441 : {
unsigned char * V_428 ;
T_6 V_442 ;
T_12 V_443 ;
T_4 * V_380 , * V_444 ;
V_442 = V_422 -> V_435 . V_436 ;
if ( V_442 > V_430 ) {
V_419 = V_425 ;
goto V_426;
}
V_428 = F_142 ( V_430 , V_386 ) ;
if ( ! V_428 ) {
V_419 = V_425 ;
goto V_426;
}
V_444 = V_428 ;
memcpy ( V_444 ,
V_422 -> V_434 , V_442 ) ;
F_106 ( & V_6 -> V_216 , V_31 ) ;
if ( V_6 -> V_396 != V_6 -> V_395 ) {
struct V_255 * V_256 =
(struct V_255 * ) V_417 -> V_257 ;
F_146 ( V_6 ) ;
V_256 -> V_263 = V_264 ;
V_256 -> V_445 = V_446 ;
V_256 -> V_447 = 0x0A ;
V_256 -> V_448 = 0x20 ;
V_256 -> V_265 = 1 ;
V_419 = V_425 ;
} else {
V_380 = & V_6 -> V_397 [ V_6 -> V_396 ] ;
V_443 = V_389 - V_6 -> V_396 ;
if ( V_442 > V_443 ) {
memcpy ( V_380 , V_444 , V_443 ) ;
V_444 += V_443 ;
V_442 -= V_443 ;
V_6 -> V_396 = 0 ;
V_380 = V_6 -> V_397 ;
}
memcpy ( V_380 , V_444 , V_442 ) ;
V_6 -> V_396 += V_442 ;
V_6 -> V_396 %= V_389 ;
if ( V_6 -> V_217 & V_218 ) {
V_6 -> V_217 &=
~ V_218 ;
F_146 ( V_6 ) ;
}
}
F_107 ( & V_6 -> V_216 , V_31 ) ;
F_22 ( V_428 ) ;
if ( V_6 -> V_229 == V_437 )
V_422 -> V_435 . V_438 =
V_439 ;
else
V_422 -> V_435 . V_438 =
V_440 ;
break;
}
case V_449 : {
T_4 * V_380 = V_6 -> V_387 ;
F_166 ( V_6 ) ;
F_106 ( & V_6 -> V_215 , V_31 ) ;
V_6 -> V_217 |= V_219 ;
V_6 -> V_391 = 0 ;
V_6 -> V_388 = 0 ;
memset ( V_380 , 0 , V_389 ) ;
F_107 ( & V_6 -> V_215 , V_31 ) ;
if ( V_6 -> V_229 == V_437 )
V_422 -> V_435 . V_438 =
V_439 ;
else
V_422 -> V_435 . V_438 =
V_440 ;
break;
}
case V_450 : {
T_4 * V_380 = V_6 -> V_397 ;
F_106 ( & V_6 -> V_216 , V_31 ) ;
V_6 -> V_217 |= ( V_218 |
V_220 ) ;
V_6 -> V_395 = 0 ;
V_6 -> V_396 = 0 ;
memset ( V_380 , 0 , V_389 ) ;
F_107 ( & V_6 -> V_216 , V_31 ) ;
if ( V_6 -> V_229 == V_437 )
V_422 -> V_435 . V_438 =
V_439 ;
else
V_422 -> V_435 . V_438 =
V_440 ;
break;
}
case V_451 : {
T_4 * V_380 ;
F_166 ( V_6 ) ;
F_106 ( & V_6 -> V_215 , V_31 ) ;
V_6 -> V_217 |= V_219 ;
V_6 -> V_391 = 0 ;
V_6 -> V_388 = 0 ;
V_380 = V_6 -> V_387 ;
memset ( V_380 , 0 , sizeof( struct V_376 ) ) ;
F_107 ( & V_6 -> V_215 , V_31 ) ;
F_106 ( & V_6 -> V_216 , V_31 ) ;
V_6 -> V_217 |= ( V_218 |
V_220 ) ;
V_6 -> V_395 = 0 ;
V_6 -> V_396 = 0 ;
V_380 = V_6 -> V_397 ;
memset ( V_380 , 0 , sizeof( struct V_376 ) ) ;
F_107 ( & V_6 -> V_216 , V_31 ) ;
if ( V_6 -> V_229 == V_437 )
V_422 -> V_435 . V_438 =
V_439 ;
else
V_422 -> V_435 . V_438 =
V_440 ;
break;
}
case V_452 : {
if ( V_6 -> V_229 == V_437 )
V_422 -> V_435 . V_438 =
V_439 ;
else
V_422 -> V_435 . V_438 =
V_453 ;
break;
}
case V_454 : {
T_9 * V_455 = L_27 ;
if ( V_6 -> V_229 == V_437 )
V_422 -> V_435 . V_438 =
V_439 ;
else
V_422 -> V_435 . V_438 =
V_440 ;
memcpy ( V_422 -> V_434 ,
V_455 , ( V_456 ) strlen ( V_455 ) ) ;
break;
}
case V_457 : {
if ( V_6 -> V_229 == V_437 )
V_422 -> V_435 . V_438 =
V_439 ;
else
V_422 -> V_435 . V_438 =
V_440 ;
F_165 ( V_6 ) ;
break;
}
case V_458 : {
if ( V_6 -> V_229 == V_437 )
V_422 -> V_435 . V_438 =
V_439 ;
else
V_422 -> V_435 . V_438 =
V_440 ;
F_32 ( V_6 ) ;
break;
}
default:
V_419 = V_425 ;
F_53 ( L_28 , V_242 ) ;
}
V_426:
if ( V_418 ) {
struct V_328 * V_329 = F_169 ( V_417 ) ;
F_174 ( V_44 - V_329 -> V_424 ) ;
}
return V_419 ;
}
static struct V_138 * F_175 ( struct V_5 * V_6 )
{
struct V_459 * V_432 = & V_6 -> V_163 ;
struct V_138 * V_248 = NULL ;
unsigned long V_31 ;
F_106 ( & V_6 -> V_212 , V_31 ) ;
if ( ! F_176 ( V_432 ) ) {
V_248 = F_177 ( V_432 -> V_460 , struct V_138 , V_162 ) ;
F_178 ( & V_248 -> V_162 ) ;
} else{
F_107 ( & V_6 -> V_212 , V_31 ) ;
return NULL ;
}
F_107 ( & V_6 -> V_212 , V_31 ) ;
return V_248 ;
}
static void F_179 ( struct V_5 * V_6 ,
struct V_249 * V_417 )
{
switch ( V_417 -> V_336 [ 0 ] ) {
case V_461 : {
unsigned char V_462 [ 36 ] ;
char * V_44 ;
struct V_328 * V_329 ;
if ( V_417 -> V_73 -> V_172 ) {
V_417 -> V_258 = ( V_463 << 16 ) ;
V_417 -> V_254 ( V_417 ) ;
return;
}
V_462 [ 0 ] = V_464 ;
V_462 [ 1 ] = 0 ;
V_462 [ 2 ] = 0 ;
V_462 [ 4 ] = 31 ;
strncpy ( & V_462 [ 8 ] , L_29 , 8 ) ;
strncpy ( & V_462 [ 16 ] , L_30 , 16 ) ;
strncpy ( & V_462 [ 32 ] , L_31 , 4 ) ;
V_329 = F_169 ( V_417 ) ;
V_44 = F_170 ( F_171 ( V_329 ) ) + V_329 -> V_424 ;
memcpy ( V_44 , V_462 , sizeof( V_462 ) ) ;
V_329 = F_169 ( V_417 ) ;
F_174 ( V_44 - V_329 -> V_424 ) ;
V_417 -> V_254 ( V_417 ) ;
}
break;
case V_465 :
case V_466 : {
if ( F_167 ( V_6 , V_417 ) )
V_417 -> V_258 = ( V_467 << 16 ) ;
V_417 -> V_254 ( V_417 ) ;
}
break;
default:
V_417 -> V_254 ( V_417 ) ;
}
}
static int F_180 ( struct V_249 * V_417 ,
void (* F_181)( struct V_249 * ) )
{
struct V_190 * V_19 = V_417 -> V_73 -> V_19 ;
struct V_5 * V_6 = (struct V_5 * ) V_19 -> V_201 ;
struct V_138 * V_248 ;
int V_171 = V_417 -> V_73 -> V_189 ;
V_417 -> V_254 = F_181 ;
V_417 -> V_468 = NULL ;
V_417 -> V_258 = 0 ;
if ( V_171 == 16 ) {
F_179 ( V_6 , V_417 ) ;
return 0 ;
}
V_248 = F_175 ( V_6 ) ;
if ( ! V_248 )
return V_469 ;
if ( F_122 ( V_6 , V_248 , V_417 ) == V_183 ) {
V_417 -> V_258 = ( V_467 << 16 ) | ( V_470 << 1 ) ;
V_417 -> V_254 ( V_417 ) ;
return 0 ;
}
F_132 ( V_6 , V_248 ) ;
return 0 ;
}
bool F_182 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
char * V_471 = V_6 -> V_472 ;
char * V_473 = V_6 -> V_474 ;
char * V_475 = V_6 -> V_168 ;
char T_1 * V_476 ;
char T_1 * V_477 ;
char T_1 * V_478 ;
int V_479 ;
V_476 = ( char T_1 * ) ( & V_46 -> V_89 [ 15 ] ) ;
V_477 = ( char T_1 * ) ( & V_46 -> V_89 [ 17 ] ) ;
V_478 = ( char T_1 * ) ( & V_46 -> V_89 [ 21 ] ) ;
F_183 ( V_6 ) ;
F_13 ( V_480 , V_46 -> V_56 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_481 L_32 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
F_13 ( V_482 , V_46 -> V_56 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_18 L_33 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_479 = 8 ;
while ( V_479 ) {
* V_471 = F_46 ( V_476 ) ;
V_471 ++ ;
V_476 ++ ;
V_479 -- ;
}
V_479 = 16 ;
while ( V_479 ) {
* V_473 = F_46 ( V_477 ) ;
V_473 ++ ;
V_477 ++ ;
V_479 -- ;
}
V_479 = 16 ;
while( V_479 ) {
* V_475 = F_46 ( V_478 ) ;
V_475 ++ ;
V_478 ++ ;
V_479 -- ;
}
F_15 ( L_34 ,
V_6 -> V_19 -> V_20 ,
V_6 -> V_472 ,
V_6 -> V_474 ) ;
V_6 -> V_169 = F_12 ( & V_46 -> V_89 [ 0 ] ) ;
V_6 -> V_483 = F_12 ( & V_46 -> V_89 [ 1 ] ) ;
V_6 -> V_484 = F_12 ( & V_46 -> V_89 [ 2 ] ) ;
V_6 -> V_485 = F_12 ( & V_46 -> V_89 [ 3 ] ) ;
V_6 -> V_486 = F_12 ( & V_46 -> V_89 [ 4 ] ) ;
V_6 -> V_151 = F_12 ( & V_46 -> V_89 [ 25 ] ) ;
return true ;
}
static bool F_184 ( struct V_5 * V_57 )
{
T_6 V_240 , V_487 , V_488 = 0 ;
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
char * V_471 = V_57 -> V_472 ;
char * V_473 = V_57 -> V_474 ;
char T_1 * V_476 = ( char T_1 * ) ( & V_46 -> V_136 [ 15 ] ) ;
char T_1 * V_477 = ( char T_1 * ) ( & V_46 -> V_136 [ 17 ] ) ;
int V_479 ;
V_240 = F_12 ( & V_46 -> V_269 ) ;
F_13 ( V_240 | V_270 , & V_46 -> V_269 ) ;
do {
V_488 = F_12 ( & V_46 -> V_110 ) ;
} while ( ( V_488 & V_489 ) == 0 );
F_13 ( V_490 , & V_46 -> V_65 ) ;
F_13 ( V_67 , & V_46 -> V_68 ) ;
for ( V_487 = 0 ; V_487 < 2000 ; V_487 ++ ) {
if ( F_12 ( & V_46 -> V_25 ) & V_26 ) {
F_13 ( V_27 , & V_46 -> V_28 ) ;
break;
}
F_185 ( 10 ) ;
}
if ( V_487 >= 2000 ) {
F_9 ( V_18 L_33 , V_57 -> V_19 -> V_20 ) ;
return false ;
}
V_479 = 8 ;
while ( V_479 ) {
* V_471 = F_46 ( V_476 ) ;
V_471 ++ ;
V_476 ++ ;
V_479 -- ;
}
V_479 = 16 ;
while ( V_479 ) {
* V_473 = F_46 ( V_477 ) ;
V_473 ++ ;
V_477 ++ ;
V_479 -- ;
}
F_15 ( L_34 ,
V_57 -> V_19 -> V_20 ,
V_57 -> V_472 ,
V_57 -> V_474 ) ;
V_57 -> V_483 = F_12 ( & V_46 -> V_136 [ 1 ] ) ;
V_57 -> V_484 = F_12 ( & V_46 -> V_136 [ 2 ] ) ;
V_57 -> V_485 = F_12 ( & V_46 -> V_136 [ 3 ] ) ;
V_57 -> V_486 = F_12 ( & V_46 -> V_136 [ 4 ] ) ;
V_57 -> V_151 = F_12 ( & V_46 -> V_136 [ 25 ] ) ;
return true ;
}
static bool F_186 ( struct V_5 * V_6 )
{
char * V_471 = V_6 -> V_472 ;
char * V_473 = V_6 -> V_474 ;
char * V_475 = V_6 -> V_168 ;
char T_1 * V_476 ;
char T_1 * V_477 ;
char T_1 * V_478 ;
T_8 V_479 ;
struct V_60 * V_46 = V_6 -> V_61 ;
V_476 = ( char T_1 * ) ( & V_46 -> V_136 [ 15 ] ) ;
V_477 = ( char T_1 * ) ( & V_46 -> V_136 [ 17 ] ) ;
V_478 = ( char T_1 * ) ( & V_46 -> V_136 [ 21 ] ) ;
if ( F_12 ( V_6 -> V_61 -> V_25 ) &
V_62 ) {
F_13 ( V_62 ,
V_6 -> V_61 -> V_25 ) ;
}
F_13 ( V_490 , V_46 -> V_65 ) ;
if ( ! F_27 ( V_6 ) ) {
F_15 ( L_35
L_36 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_479 = 8 ;
while ( V_479 ) {
* V_471 = F_46 ( V_476 ) ;
V_471 ++ ;
V_476 ++ ;
V_479 -- ;
}
V_479 = 16 ;
while ( V_479 ) {
* V_473 = F_46 ( V_477 ) ;
V_473 ++ ;
V_477 ++ ;
V_479 -- ;
}
V_479 = 16 ;
while ( V_479 ) {
* V_475 = F_46 ( V_478 ) ;
V_475 ++ ;
V_478 ++ ;
V_479 -- ;
}
V_6 -> V_169 = F_12 ( & V_46 -> V_136 [ 0 ] ) ;
V_6 -> V_483 = F_12 ( & V_46 -> V_136 [ 1 ] ) ;
V_6 -> V_484 = F_12 ( & V_46 -> V_136 [ 2 ] ) ;
V_6 -> V_485 = F_12 ( & V_46 -> V_136 [ 3 ] ) ;
V_6 -> V_486 = F_12 ( & V_46 -> V_136 [ 4 ] ) ;
V_6 -> V_151 = F_12 ( & V_46 -> V_136 [ 25 ] ) ;
F_15 ( L_34 ,
V_6 -> V_19 -> V_20 ,
V_6 -> V_472 ,
V_6 -> V_474 ) ;
return true ;
}
static bool F_69 ( struct V_5 * V_6 )
{
bool V_69 = false ;
switch ( V_6 -> V_7 ) {
case V_16 :
V_69 = F_187 ( V_6 ) ;
break;
case V_8 :
V_69 = F_182 ( V_6 ) ;
break;
case V_23 :
V_69 = F_184 ( V_6 ) ;
break;
case V_9 :
V_69 = F_186 ( V_6 ) ;
break;
default:
break;
}
if ( V_6 -> V_484 > V_206 )
V_6 -> V_491 = V_206 ;
else
V_6 -> V_491 = V_6 -> V_484 - 1 ;
V_6 -> V_19 -> V_205 = V_6 -> V_491 ;
return V_69 ;
}
static int F_188 ( struct V_5 * V_6 ,
struct V_138 * V_492 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
struct V_138 * V_248 ;
struct V_287 * V_160 ;
T_6 V_285 , V_48 , V_493 = 0 , V_308 = 0 ;
int V_69 ;
bool error ;
V_494:
V_308 ++ ;
V_48 = F_12 ( & V_46 -> V_48 ) & V_6 -> V_289 ;
F_13 ( V_48 , & V_46 -> V_48 ) ;
while ( 1 ) {
if ( ( V_285 = F_12 ( & V_46 -> V_290 ) ) == 0xFFFFFFFF ) {
if ( V_493 ) {
V_69 = V_187 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_308 > 100 ) {
V_69 = V_183 ;
break;
}
goto V_494;
}
}
V_160 = (struct V_287 * ) ( V_6 -> V_159 + ( V_285 << 5 ) ) ;
V_248 = F_44 ( V_160 , struct V_138 , V_160 ) ;
V_493 |= ( V_248 == V_492 ) ? 1 : 0 ;
if ( ( V_248 -> V_6 != V_6 ) || ( V_248 -> V_252 != V_281 ) ) {
if ( ( V_248 -> V_252 == V_282 ) || ( V_248 == V_492 ) ) {
F_9 ( V_18 L_37
L_38
, V_6 -> V_19 -> V_20
, V_248 -> V_250 -> V_73 -> V_189
, ( T_8 ) V_248 -> V_250 -> V_73 -> V_172
, V_248 ) ;
V_248 -> V_250 -> V_258 = V_284 << 16 ;
F_104 ( V_248 ) ;
continue;
}
F_9 ( V_18 L_39
L_40
L_41
, V_6 -> V_19 -> V_20
, V_248
, F_111 ( & V_6 -> V_251 ) ) ;
continue;
}
error = ( V_285 & V_291 ) ? true : false ;
F_109 ( V_6 , V_248 , error ) ;
}
return V_69 ;
}
static int F_189 ( struct V_5 * V_6 ,
struct V_138 * V_492 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
struct V_287 * V_160 ;
struct V_138 * V_248 ;
T_6 V_285 , V_493 = 0 , V_308 = 0 ;
int V_355 , V_69 ;
bool error ;
V_495:
V_308 ++ ;
F_13 ( V_292 , V_46 -> V_52 ) ;
while( 1 ) {
V_355 = V_46 -> V_296 ;
V_285 = V_46 -> V_294 [ V_355 ] ;
if ( V_285 == 0 ) {
if ( V_493 ) {
V_69 = V_187 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_308 > 100 ) {
V_69 = V_183 ;
break;
}
goto V_495;
}
}
V_46 -> V_294 [ V_355 ] = 0 ;
V_355 ++ ;
V_355 %= V_293 ;
V_46 -> V_296 = V_355 ;
V_160 = (struct V_287 * ) ( V_6 -> V_159 + ( V_285 << 5 ) ) ;
V_248 = F_44 ( V_160 , struct V_138 , V_160 ) ;
V_493 |= ( V_248 == V_492 ) ? 1 : 0 ;
if ( ( V_248 -> V_6 != V_6 ) || ( V_248 -> V_252 != V_281 ) ) {
if ( ( V_248 -> V_252 == V_282 ) || ( V_248 == V_492 ) ) {
F_9 ( V_18 L_37
L_38
, V_6 -> V_19 -> V_20
, V_248 -> V_250 -> V_73 -> V_189
, ( T_8 ) V_248 -> V_250 -> V_73 -> V_172
, V_248 ) ;
V_248 -> V_250 -> V_258 = V_284 << 16 ;
F_104 ( V_248 ) ;
continue;
}
F_9 ( V_18 L_39
L_40
L_41
, V_6 -> V_19 -> V_20
, V_248
, F_111 ( & V_6 -> V_251 ) ) ;
continue;
}
error = ( V_285 & V_291 ) ? true : false ;
F_109 ( V_6 , V_248 , error ) ;
}
return V_69 ;
}
static int F_190 ( struct V_5 * V_6 ,
struct V_138 * V_492 )
{
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
T_6 V_285 , V_286 ;
struct V_287 * V_160 ;
bool error ;
struct V_138 * V_280 ;
T_6 V_493 = 0 , V_308 = 0 ;
int V_69 ;
V_496:
V_308 ++ ;
while ( 1 ) {
if ( ( F_12 ( & V_46 -> V_101 ) & V_298 ) == 0 ) {
if ( V_493 ) {
V_69 = V_187 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_308 > 100 ) {
V_69 = V_183 ;
break;
}
goto V_496;
}
}
V_285 = F_12 ( & V_46 -> V_299 ) ;
V_286 = ( V_285 & 0xFFFFFFF0 ) ;
V_160 = (struct V_287 * ) ( V_6 -> V_159 + V_286 ) ;
V_280 = F_44 ( V_160 , struct V_138 , V_160 ) ;
V_493 |= ( V_280 == V_492 ) ? 1 : 0 ;
if ( ( V_280 -> V_6 != V_6 ) || ( V_280 -> V_252 != V_281 ) ) {
if ( V_280 -> V_252 == V_282 ) {
F_9 ( V_18 L_37
L_38
, V_6 -> V_19 -> V_20
, V_280 -> V_250 -> V_73 -> V_189
, ( T_8 ) V_280 -> V_250 -> V_73 -> V_172
, V_280 ) ;
V_280 -> V_250 -> V_258 = V_284 << 16 ;
F_104 ( V_280 ) ;
continue;
}
F_9 ( V_18 L_39
L_40
L_41
, V_6 -> V_19 -> V_20
, V_280
, F_111 ( & V_6 -> V_251 ) ) ;
continue;
}
error = ( V_285 & V_300 ) ? true : false ;
F_109 ( V_6 , V_280 , error ) ;
}
return V_69 ;
}
static int F_191 ( struct V_5 * V_6 ,
struct V_138 * V_492 )
{
bool error ;
T_6 V_493 = 0 , V_308 = 0 , V_285 , V_286 ;
int V_69 , V_296 , V_303 , V_302 , V_306 ;
unsigned long V_31 ;
struct V_287 * V_160 ;
struct V_138 * V_280 ;
struct V_60 * V_301 = V_6 -> V_61 ;
V_497:
V_308 ++ ;
while ( 1 ) {
F_106 ( & V_6 -> V_214 , V_31 ) ;
V_302 = V_301 -> V_294 [ 0 ] . V_304 + 1 ;
V_296 = V_301 -> V_296 ;
if ( ( V_302 & 0xFFF ) == ( V_296 & 0xFFF ) ) {
F_107 ( & V_6 -> V_214 , V_31 ) ;
if ( V_493 ) {
V_69 = V_187 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_308 > 40 ) {
V_69 = V_183 ;
break;
}
goto V_497;
}
}
V_306 = V_296 & 0x4000 ;
V_303 = ( V_296 & 0xFFF ) + 1 ;
V_303 %= V_307 ;
V_301 -> V_296 = V_303 ? ( V_303 | V_306 ) :
( ( V_306 ^ 0x4000 ) + 1 ) ;
V_296 = V_301 -> V_296 ;
F_107 ( & V_6 -> V_214 , V_31 ) ;
V_285 = V_301 -> V_294 [ V_296 & 0xFFF ] . V_304 ;
V_286 = ( V_285 & 0xFFFFFFF0 ) ;
V_160 = (struct V_287 * ) ( V_6 -> V_159 +
V_286 ) ;
V_280 = F_44 ( V_160 , struct V_138 ,
V_160 ) ;
V_493 |= ( V_280 == V_492 ) ? 1 : 0 ;
if ( ( V_280 -> V_6 != V_6 ) ||
( V_280 -> V_252 != V_281 ) ) {
if ( V_280 -> V_252 == V_282 ) {
F_15 ( L_42
L_43
L_44
, V_6 -> V_19 -> V_20
, V_280 -> V_250 -> V_73 -> V_189
, ( T_8 ) V_280 -> V_250 -> V_73 -> V_172
, V_280 ) ;
V_280 -> V_250 -> V_258 = V_284 << 16 ;
F_104 ( V_280 ) ;
continue;
}
F_15 ( L_45
L_46
L_47
, V_6 -> V_19 -> V_20
, V_280
, F_111 ( & V_6 -> V_251 ) ) ;
continue;
}
error = ( V_285 & V_300 )
? true : false ;
F_109 ( V_6 , V_280 , error ) ;
}
return V_69 ;
}
static int F_192 ( struct V_5 * V_6 ,
struct V_138 * V_492 )
{
int V_69 = 0 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
V_69 = F_188 ( V_6 , V_492 ) ;
}
break;
case V_8 : {
V_69 = F_189 ( V_6 , V_492 ) ;
}
break;
case V_23 : {
V_69 = F_190 ( V_6 , V_492 ) ;
}
break;
case V_9 :
V_69 = F_191 ( V_6 , V_492 ) ;
break;
}
return V_69 ;
}
static int F_193 ( struct V_5 * V_6 )
{
T_6 V_141 , V_358 ;
T_5 V_71 ;
switch ( V_6 -> V_7 ) {
case V_8 :
case V_9 :
V_71 = V_6 -> V_14 ;
break;
default:
V_71 = V_6 -> V_71 ;
break;
}
V_141 = F_194 ( V_71 ) ;
V_358 = F_195 ( V_71 ) ;
V_6 -> V_358 = V_358 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
if ( V_358 != 0 ) {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_498 , \
& V_46 -> V_89 [ 0 ] ) ;
F_13 ( V_358 , & V_46 -> V_89 [ 1 ] ) ;
F_13 ( V_499 , \
& V_46 -> V_65 ) ;
if ( ! F_23 ( V_6 ) ) {
F_9 (KERN_NOTICE L_48set ccb high \
part physical address timeout\nL_49arcmsr%d: cannot set driver mode\nL_50set configL_51arcmsr%d: 'set command Q window' \
timeout \nL_52arcmsr%d: can't set driver mode.\n",
acb->host->host_no);
return 1;
}
}
break;
case ACB_ADAPTER_TYPE_C: {
if (cdb_phyaddr_hi32 != 0) {
struct MessageUnit_C __iomem *reg = acb->pmuC;
printk(KERN_NOTICE "arcmsr%d: cdb_phyaddr_hi32=0x%x\n",
acb->adapter_index, cdb_phyaddr_hi32);
writel(ARCMSR_SIGNATURE_SET_CONFIG, &reg->msgcode_rwbuffer[0]);
writel(cdb_phyaddr_hi32, &reg->msgcode_rwbuffer[1]);
writel(ARCMSR_INBOUND_MESG0_SET_CONFIG, &reg->inbound_msgaddr0);
writel(ARCMSR_HBCMU_DRV2IOP_MESSAGE_CMD_DONE, &reg->inbound_doorbell);
if (!arcmsr_hbaC_wait_msgint_ready(acb)) {
printk(KERN_NOTICE "arcmsr%d: 'set command Q window' \
timeout \n", acb->host->host_no);
return 1;
}
}
}
break;
case ACB_ADAPTER_TYPE_D: {
uint32_t __iomem *rwbuffer;
struct MessageUnit_D *reg = acb->pmuD;
reg->postq_index = 0;
reg->doneq_index = 0;
rwbuffer = reg->msgcode_rwbuffer;
writel(ARCMSR_SIGNATURE_SET_CONFIG, rwbuffer++);
writel(cdb_phyaddr_hi32, rwbuffer++);
writel(cdb_phyaddr, rwbuffer++);
writel(cdb_phyaddr + (ARCMSR_MAX_ARC1214_POSTQUEUE *
sizeof(struct InBound_SRB)), rwbuffer++);
writel(0x100, rwbuffer);
writel(ARCMSR_INBOUND_MESG0_SET_CONFIG, reg->inbound_msgaddr0);
if (!arcmsr_hbaD_wait_msgint_ready(acb)) {
pr_notice("arcmsr%d: 'set command Q window' timeout\n",
acb->host->host_no);
return 1;
}
}
break;
}
return 0;
}
static void arcmsr_wait_firmware_ready(struct AdapterControlBlock *acb)
{
uint32_t firmware_state = 0;
switch (acb->adapter_type) {
case ACB_ADAPTER_TYPE_A: {
struct MessageUnit_A __iomem *reg = acb->pmuA;
do {
firmware_state = readl(&reg->outbound_msgaddr1);
} while ((firmware_state & ARCMSR_OUTBOUND_MESG1_FIRMWARE_OK) == 0);
}
break;
case ACB_ADAPTER_TYPE_B: {
struct MessageUnit_B *reg = acb->pmuB;
do {
firmware_state = readl(reg->iop2drv_doorbell);
} while ((firmware_state & ARCMSR_MESSAGE_FIRMWARE_OK) == 0);
writel(ARCMSR_DRV2IOP_END_OF_INTERRUPT, reg->drv2iop_doorbell);
}
break;
case ACB_ADAPTER_TYPE_C: {
struct MessageUnit_C __iomem *reg = acb->pmuC;
do {
firmware_state = readl(&reg->outbound_msgaddr1);
} while ((firmware_state & ARCMSR_HBCMU_MESSAGE_FIRMWARE_OK) == 0);
}
break;
case ACB_ADAPTER_TYPE_D: {
struct MessageUnit_D *reg = acb->pmuD;
do {
firmware_state = readl(reg->outbound_msgaddr1);
} while ((firmware_state &
ARCMSR_ARC1214_MESSAGE_FIRMWARE_OK) == 0);
}
break;
}
}
static void arcmsr_hbaA_request_device_map(struct AdapterControlBlock *acb)
{
struct MessageUnit_A __iomem *reg = acb->pmuA;
if (unlikely(atomic_read(&acb->rq_map_token) == 0) || ((acb->acb_flags & ACB_F_BUS_RESET) != 0 ) || ((acb->acb_flags & ACB_F_ABORT) != 0 )){
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
return;
} else {
acb->fw_flag = FW_NORMAL;
if (atomic_read(&acb->ante_token_value) == atomic_read(&acb->rq_map_token)){
atomic_set(&acb->rq_map_token, 16);
}
atomic_set(&acb->ante_token_value, atomic_read(&acb->rq_map_token));
if (atomic_dec_and_test(&acb->rq_map_token)) {
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
return;
}
writel(ARCMSR_INBOUND_MESG0_GET_CONFIG, &reg->inbound_msgaddr0);
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
}
return;
}
static void arcmsr_hbaB_request_device_map(struct AdapterControlBlock *acb)
{
struct MessageUnit_B *reg = acb->pmuB;
if (unlikely(atomic_read(&acb->rq_map_token) == 0) || ((acb->acb_flags & ACB_F_BUS_RESET) != 0 ) || ((acb->acb_flags & ACB_F_ABORT) != 0 )){
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
return;
} else {
acb->fw_flag = FW_NORMAL;
if (atomic_read(&acb->ante_token_value) == atomic_read(&acb->rq_map_token)) {
atomic_set(&acb->rq_map_token, 16);
}
atomic_set(&acb->ante_token_value, atomic_read(&acb->rq_map_token));
if (atomic_dec_and_test(&acb->rq_map_token)) {
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
return;
}
writel(ARCMSR_MESSAGE_GET_CONFIG, reg->drv2iop_doorbell);
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
}
return;
}
static void arcmsr_hbaC_request_device_map(struct AdapterControlBlock *acb)
{
struct MessageUnit_C __iomem *reg = acb->pmuC;
if (unlikely(atomic_read(&acb->rq_map_token) == 0) || ((acb->acb_flags & ACB_F_BUS_RESET) != 0) || ((acb->acb_flags & ACB_F_ABORT) != 0)) {
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
return;
} else {
acb->fw_flag = FW_NORMAL;
if (atomic_read(&acb->ante_token_value) == atomic_read(&acb->rq_map_token)) {
atomic_set(&acb->rq_map_token, 16);
}
atomic_set(&acb->ante_token_value, atomic_read(&acb->rq_map_token));
if (atomic_dec_and_test(&acb->rq_map_token)) {
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
return;
}
writel(ARCMSR_INBOUND_MESG0_GET_CONFIG, &reg->inbound_msgaddr0);
writel(ARCMSR_HBCMU_DRV2IOP_MESSAGE_CMD_DONE, &reg->inbound_doorbell);
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
}
return;
}
static void arcmsr_hbaD_request_device_map(struct AdapterControlBlock *acb)
{
struct MessageUnit_D *reg = acb->pmuD;
if (unlikely(atomic_read(&acb->rq_map_token) == 0) ||
((acb->acb_flags & ACB_F_BUS_RESET) != 0) ||
((acb->acb_flags & ACB_F_ABORT) != 0)) {
mod_timer(&acb->eternal_timer,
jiffies + msecs_to_jiffies(6 * HZ));
} else {
acb->fw_flag = FW_NORMAL;
if (atomic_read(&acb->ante_token_value) ==
atomic_read(&acb->rq_map_token)) {
atomic_set(&acb->rq_map_token, 16);
}
atomic_set(&acb->ante_token_value,
atomic_read(&acb->rq_map_token));
if (atomic_dec_and_test(&acb->rq_map_token)) {
mod_timer(&acb->eternal_timer, jiffies +
msecs_to_jiffies(6 * HZ));
return;
}
writel(ARCMSR_INBOUND_MESG0_GET_CONFIG,
reg->inbound_msgaddr0);
mod_timer(&acb->eternal_timer, jiffies +
msecs_to_jiffies(6 * HZ));
}
}
static void arcmsr_request_device_map(unsigned long pacb)
{
struct AdapterControlBlock *acb = (struct AdapterControlBlock *)pacb;
switch (acb->adapter_type) {
case ACB_ADAPTER_TYPE_A: {
arcmsr_hbaA_request_device_map(acb);
}
break;
case ACB_ADAPTER_TYPE_B: {
arcmsr_hbaB_request_device_map(acb);
}
break;
case ACB_ADAPTER_TYPE_C: {
arcmsr_hbaC_request_device_map(acb);
}
break;
case ACB_ADAPTER_TYPE_D:
arcmsr_hbaD_request_device_map(acb);
break;
}
}
static void arcmsr_hbaA_start_bgrb(struct AdapterControlBlock *acb)
{
struct MessageUnit_A __iomem *reg = acb->pmuA;
acb->acb_flags |= ACB_F_MSG_START_BGRB;
writel(ARCMSR_INBOUND_MESG0_START_BGRB, &reg->inbound_msgaddr0);
if (!arcmsr_hbaA_wait_msgint_ready(acb)) {
printk(KERN_NOTICE "arcmsr%d: wait 'start adapter background \
rebulid' timeout \n", acb->host->host_no);
}
}
static void arcmsr_hbaB_start_bgrb(struct AdapterControlBlock *acb)
{
struct MessageUnit_B *reg = acb->pmuB;
acb->acb_flags |= ACB_F_MSG_START_BGRB;
writel(ARCMSR_MESSAGE_START_BGRB, reg->drv2iop_doorbell);
if (!arcmsr_hbaB_wait_msgint_ready(acb)) {
printk(KERN_NOTICE "arcmsr%d: wait 'start adapter background \
rebulid' timeout \n",acb->host->host_no);
}
}
static void arcmsr_hbaC_start_bgrb(struct AdapterControlBlock *pACB)
{
struct MessageUnit_C __iomem *phbcmu = pACB->pmuC;
pACB->acb_flags |= ACB_F_MSG_START_BGRB;
writel(ARCMSR_INBOUND_MESG0_START_BGRB, &phbcmu->inbound_msgaddr0);
writel(ARCMSR_HBCMU_DRV2IOP_MESSAGE_CMD_DONE, &phbcmu->inbound_doorbell);
if (!arcmsr_hbaC_wait_msgint_ready(pACB)) {
printk(KERN_NOTICE "arcmsr%d: wait 'start adapter background \
rebulid' timeout \n", pACB->host->host_no);
}
return;
}
static void arcmsr_hbaD_start_bgrb(struct AdapterControlBlock *pACB)
{
struct MessageUnit_D *pmu = pACB->pmuD;
pACB->acb_flags |= ACB_F_MSG_START_BGRB;
writel(ARCMSR_INBOUND_MESG0_START_BGRB, pmu->inbound_msgaddr0);
if (!arcmsr_hbaD_wait_msgint_ready(pACB)) {
pr_notice("arcmsr%d: wait 'start adapter L_53background rebulid'
