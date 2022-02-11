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
int V_47 , V_140 , V_178 ;
struct V_179 V_180 [ V_181 ] ;
for ( V_47 = 0 ; V_47 < V_181 ; V_47 ++ )
V_180 [ V_47 ] . V_182 = V_47 ;
V_178 = F_52 ( V_10 , V_180 , 1 , V_181 ) ;
if ( V_178 < 0 )
goto V_183;
V_6 -> V_184 = V_178 ;
for ( V_47 = 0 ; V_47 < V_178 ; V_47 ++ ) {
if ( F_53 ( V_180 [ V_47 ] . V_185 ,
F_17 , 0 , L_9 , V_6 ) ) {
F_54 ( L_10 ,
V_6 -> V_19 -> V_20 , V_180 [ V_47 ] . V_185 ) ;
for ( V_140 = 0 ; V_140 < V_47 ; V_140 ++ )
F_55 ( V_180 [ V_140 ] . V_185 , V_6 ) ;
F_56 ( V_10 ) ;
goto V_183;
}
V_6 -> V_180 [ V_47 ] = V_180 [ V_47 ] ;
}
V_6 -> V_186 |= V_187 ;
F_57 ( L_11 , V_6 -> V_19 -> V_20 ) ;
return V_188 ;
V_183:
if ( F_58 ( V_10 , 1 ) < 0 )
goto V_189;
if ( F_53 ( V_10 -> V_32 , F_17 ,
V_190 , L_9 , V_6 ) ) {
F_54 ( L_10 ,
V_6 -> V_19 -> V_20 , V_10 -> V_32 ) ;
F_59 ( V_10 ) ;
goto V_189;
}
V_6 -> V_186 |= V_191 ;
F_57 ( L_12 , V_6 -> V_19 -> V_20 ) ;
return V_188 ;
V_189:
if ( F_53 ( V_10 -> V_32 , F_17 ,
V_190 , L_9 , V_6 ) ) {
F_54 ( L_13 ,
V_6 -> V_19 -> V_20 , V_10 -> V_32 ) ;
return V_192 ;
}
return V_188 ;
}
static int F_60 ( struct V_15 * V_10 , const struct V_193 * V_194 )
{
struct V_195 * V_19 ;
struct V_5 * V_6 ;
T_4 V_196 , V_197 ;
int error ;
error = F_61 ( V_10 ) ;
if( error ) {
return - V_198 ;
}
V_19 = F_62 ( & V_199 , sizeof( struct V_5 ) ) ;
if( ! V_19 ) {
goto V_200;
}
error = F_63 ( V_10 , F_64 ( 64 ) ) ;
if( error ) {
error = F_63 ( V_10 , F_64 ( 32 ) ) ;
if( error ) {
F_9 ( V_201
L_14 ,
V_19 -> V_20 ) ;
goto V_202;
}
}
F_65 ( & V_203 ) ;
V_196 = V_10 -> V_196 -> V_204 ;
V_197 = V_10 -> V_205 ;
V_6 = (struct V_5 * ) V_19 -> V_206 ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 -> V_10 = V_10 ;
V_6 -> V_19 = V_19 ;
V_19 -> V_207 = V_146 ;
V_19 -> V_208 = V_145 ;
V_19 -> V_209 = 16 ;
V_19 -> V_210 = V_211 ;
V_19 -> V_212 = V_4 ;
V_19 -> V_213 = V_214 ;
V_19 -> V_215 = ( V_196 << 8 ) | V_197 ;
F_66 ( V_10 , V_19 ) ;
F_67 ( V_10 ) ;
error = F_68 ( V_10 , L_9 ) ;
if( error ) {
goto V_202;
}
F_69 ( & V_6 -> V_216 ) ;
F_69 ( & V_6 -> V_217 ) ;
F_69 ( & V_6 -> V_218 ) ;
F_69 ( & V_6 -> V_219 ) ;
F_69 ( & V_6 -> V_220 ) ;
F_69 ( & V_6 -> V_221 ) ;
V_6 -> V_186 |= ( V_222 |
V_223 |
V_224 ) ;
V_6 -> V_186 &= ~ V_225 ;
F_41 ( & V_6 -> V_163 ) ;
V_6 -> V_7 = V_194 -> V_226 ;
error = F_5 ( V_6 ) ;
if( ! error ) {
goto V_227;
}
error = F_33 ( V_6 ) ;
if ( ! error )
goto V_228;
error = F_70 ( V_6 ) ;
if( ! error ) {
goto V_229;
}
error = F_38 ( V_6 ) ;
if( error ) {
goto V_229;
}
error = F_71 ( V_19 , & V_10 -> V_11 ) ;
if( error ) {
goto V_230;
}
if ( F_51 ( V_10 , V_6 ) == V_192 )
goto V_231;
F_72 ( V_6 ) ;
F_73 ( & V_6 -> V_166 , F_43 ) ;
F_74 ( & V_6 -> V_176 , 16 ) ;
F_74 ( & V_6 -> V_232 , 16 ) ;
V_6 -> V_233 = V_234 ;
F_75 ( & V_6 -> V_235 ) ;
V_6 -> V_235 . V_236 = V_237 + F_76 ( 6 * V_238 ) ;
V_6 -> V_235 . V_239 = ( unsigned long ) V_6 ;
V_6 -> V_235 . V_240 = & V_241 ;
F_77 ( & V_6 -> V_235 ) ;
if( F_78 ( V_6 ) )
goto V_242;
F_79 ( V_19 ) ;
return 0 ;
V_242:
F_80 ( & V_6 -> V_235 ) ;
F_81 ( & V_6 -> V_166 ) ;
F_82 ( V_6 ) ;
F_32 ( V_6 ) ;
F_83 ( V_10 , V_6 ) ;
V_231:
F_84 ( V_19 ) ;
V_230:
F_85 ( V_6 ) ;
V_229:
F_3 ( V_6 ) ;
V_228:
F_16 ( V_6 ) ;
V_227:
F_86 ( V_10 ) ;
V_202:
F_87 ( V_19 ) ;
V_200:
F_88 ( V_10 ) ;
return - V_198 ;
}
static void F_83 ( struct V_15 * V_10 ,
struct V_5 * V_6 )
{
int V_47 ;
if ( V_6 -> V_186 & V_191 ) {
F_55 ( V_10 -> V_32 , V_6 ) ;
F_59 ( V_10 ) ;
} else if ( V_6 -> V_186 & V_187 ) {
for ( V_47 = 0 ; V_47 < V_6 -> V_184 ; V_47 ++ )
F_55 ( V_6 -> V_180 [ V_47 ] . V_185 , V_6 ) ;
F_56 ( V_10 ) ;
} else
F_55 ( V_10 -> V_32 , V_6 ) ;
}
static int F_89 ( struct V_15 * V_10 , T_7 V_243 )
{
T_6 V_244 ;
struct V_195 * V_19 = F_90 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_206 ;
V_244 = F_91 ( V_6 ) ;
F_83 ( V_10 , V_6 ) ;
F_80 ( & V_6 -> V_235 ) ;
F_81 ( & V_6 -> V_166 ) ;
F_82 ( V_6 ) ;
F_32 ( V_6 ) ;
F_66 ( V_10 , V_19 ) ;
F_92 ( V_10 ) ;
F_88 ( V_10 ) ;
F_93 ( V_10 , F_94 ( V_10 , V_243 ) ) ;
return 0 ;
}
static int F_95 ( struct V_15 * V_10 )
{
int error ;
struct V_195 * V_19 = F_90 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_206 ;
F_93 ( V_10 , V_245 ) ;
F_96 ( V_10 , V_245 , 0 ) ;
F_97 ( V_10 ) ;
if ( F_61 ( V_10 ) ) {
F_54 ( L_15 , V_246 ) ;
return - V_198 ;
}
error = F_63 ( V_10 , F_64 ( 64 ) ) ;
if ( error ) {
error = F_63 ( V_10 , F_64 ( 32 ) ) ;
if ( error ) {
F_54 ( L_14 ,
V_19 -> V_20 ) ;
goto V_247;
}
}
F_67 ( V_10 ) ;
if ( F_51 ( V_10 , V_6 ) == V_192 )
goto V_248;
F_72 ( V_6 ) ;
F_73 ( & V_6 -> V_166 , F_43 ) ;
F_74 ( & V_6 -> V_176 , 16 ) ;
F_74 ( & V_6 -> V_232 , 16 ) ;
V_6 -> V_233 = V_234 ;
F_75 ( & V_6 -> V_235 ) ;
V_6 -> V_235 . V_236 = V_237 + F_76 ( 6 * V_238 ) ;
V_6 -> V_235 . V_239 = ( unsigned long ) V_6 ;
V_6 -> V_235 . V_240 = & V_241 ;
F_77 ( & V_6 -> V_235 ) ;
return 0 ;
V_248:
F_82 ( V_6 ) ;
F_32 ( V_6 ) ;
V_247:
F_84 ( V_19 ) ;
F_85 ( V_6 ) ;
F_16 ( V_6 ) ;
F_86 ( V_10 ) ;
F_87 ( V_19 ) ;
F_88 ( V_10 ) ;
return - V_198 ;
}
static T_4 F_98 ( struct V_5 * V_6 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_249 , & V_46 -> V_65 ) ;
if ( ! F_23 ( V_6 ) ) {
F_9 ( V_18
L_16
, V_6 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_99 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_250 , V_46 -> V_56 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_18
L_16
, V_6 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_100 ( struct V_5 * V_57 )
{
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
F_13 ( V_249 , & V_46 -> V_65 ) ;
F_13 ( V_67 , & V_46 -> V_68 ) ;
if ( ! F_26 ( V_57 ) ) {
F_9 ( V_18
L_16
, V_57 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_101 ( struct V_5 * V_57 )
{
struct V_60 * V_46 = V_57 -> V_61 ;
F_13 ( V_249 , V_46 -> V_65 ) ;
if ( ! F_27 ( V_57 ) ) {
F_15 ( L_17
L_18 , V_57 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_102 ( struct V_5 * V_6 )
{
T_4 V_251 = 0 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
V_251 = F_98 ( V_6 ) ;
}
break;
case V_8 : {
V_251 = F_99 ( V_6 ) ;
}
break;
case V_23 : {
V_251 = F_100 ( V_6 ) ;
}
break;
case V_9 :
V_251 = F_101 ( V_6 ) ;
break;
}
return V_251 ;
}
static void F_103 ( struct V_138 * V_252 )
{
struct V_253 * V_254 = V_252 -> V_254 ;
F_104 ( V_254 ) ;
}
static void F_105 ( struct V_138 * V_252 )
{
struct V_5 * V_6 = V_252 -> V_6 ;
struct V_253 * V_254 = V_252 -> V_254 ;
unsigned long V_31 ;
F_106 ( & V_6 -> V_255 ) ;
F_103 ( V_252 ) ;
V_252 -> V_256 = V_257 ;
F_107 ( & V_6 -> V_217 , V_31 ) ;
F_42 ( & V_252 -> V_162 , & V_6 -> V_163 ) ;
F_108 ( & V_6 -> V_217 , V_31 ) ;
V_254 -> V_258 ( V_254 ) ;
}
static void F_109 ( struct V_138 * V_252 )
{
struct V_253 * V_254 = V_252 -> V_254 ;
struct V_259 * V_260 = (struct V_259 * ) V_254 -> V_261 ;
V_254 -> V_262 = V_263 << 16 ;
if ( V_260 ) {
int V_264 =
sizeof( struct V_259 ) < V_265
? sizeof( struct V_259 ) : V_265 ;
memset ( V_260 , 0 , V_265 ) ;
memcpy ( V_260 , V_252 -> V_160 . V_266 , V_264 ) ;
V_260 -> V_267 = V_268 ;
V_260 -> V_269 = 1 ;
}
}
static T_8 F_91 ( struct V_5 * V_6 )
{
T_8 V_270 = 0 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_270 = F_12 ( & V_46 -> V_271 ) ;
F_13 ( V_270 | V_272 , \
& V_46 -> V_271 ) ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_270 = F_12 ( V_46 -> V_79 ) ;
F_13 ( 0 , V_46 -> V_79 ) ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
V_270 = F_12 ( & V_46 -> V_273 ) ;
F_13 ( V_270 | V_274 , & V_46 -> V_273 ) ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
F_13 ( V_275 , V_46 -> V_103 ) ;
}
break;
}
return V_270 ;
}
static void F_110 ( struct V_5 * V_6 ,
struct V_138 * V_252 , bool error )
{
T_4 V_194 , V_172 ;
V_194 = V_252 -> V_254 -> V_73 -> V_194 ;
V_172 = V_252 -> V_254 -> V_73 -> V_172 ;
if ( ! error ) {
if ( V_6 -> V_147 [ V_194 ] [ V_172 ] == V_148 )
V_6 -> V_147 [ V_194 ] [ V_172 ] = V_276 ;
V_252 -> V_254 -> V_262 = V_263 << 16 ;
F_105 ( V_252 ) ;
} else{
switch ( V_252 -> V_160 . V_277 ) {
case V_278 : {
V_6 -> V_147 [ V_194 ] [ V_172 ] = V_148 ;
V_252 -> V_254 -> V_262 = V_279 << 16 ;
F_105 ( V_252 ) ;
}
break;
case V_280 :
case V_281 : {
V_6 -> V_147 [ V_194 ] [ V_172 ] = V_148 ;
V_252 -> V_254 -> V_262 = V_282 << 16 ;
F_105 ( V_252 ) ;
}
break;
case V_283 : {
V_6 -> V_147 [ V_194 ] [ V_172 ] = V_276 ;
F_109 ( V_252 ) ;
F_105 ( V_252 ) ;
}
break;
default:
F_9 ( V_18
L_19
, V_6 -> V_19 -> V_20
, V_194
, V_172
, V_252 -> V_160 . V_277 ) ;
V_6 -> V_147 [ V_194 ] [ V_172 ] = V_148 ;
V_252 -> V_254 -> V_262 = V_279 << 16 ;
F_105 ( V_252 ) ;
break;
}
}
}
static void F_111 ( struct V_5 * V_6 , struct V_138 * V_284 , bool error )
{
int V_194 , V_172 ;
if ( ( V_284 -> V_6 != V_6 ) || ( V_284 -> V_256 != V_285 ) ) {
if ( V_284 -> V_256 == V_286 ) {
struct V_253 * V_287 = V_284 -> V_254 ;
if ( V_287 ) {
V_194 = V_287 -> V_73 -> V_194 ;
V_172 = V_287 -> V_73 -> V_172 ;
V_287 -> V_262 |= V_288 << 16 ;
F_105 ( V_284 ) ;
F_9 ( V_18 L_20 ,
V_6 -> V_19 -> V_20 , V_284 ) ;
}
return;
}
F_9 ( V_18 L_21
L_22
L_23
, V_6 -> V_19 -> V_20
, V_6
, V_284
, V_284 -> V_6
, V_284 -> V_256
, F_112 ( & V_6 -> V_255 ) ) ;
return;
}
F_110 ( V_6 , V_284 , error ) ;
}
static void F_113 ( struct V_5 * V_6 )
{
int V_47 = 0 ;
T_6 V_289 , V_290 ;
struct V_291 * V_292 ;
bool error ;
struct V_138 * V_284 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
T_6 V_48 ;
V_48 = F_12 ( & V_46 -> V_48 ) &
V_6 -> V_293 ;
F_13 ( V_48 , & V_46 -> V_48 ) ;
while( ( ( V_289 = F_12 ( & V_46 -> V_294 ) ) != 0xFFFFFFFF )
&& ( V_47 ++ < V_211 ) ) {
V_292 = (struct V_291 * ) ( V_6 -> V_159 + ( V_289 << 5 ) ) ;
V_284 = F_44 ( V_292 , struct V_138 , V_160 ) ;
error = ( V_289 & V_295 ) ? true : false ;
F_111 ( V_6 , V_284 , error ) ;
}
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_296 , V_46 -> V_52 ) ;
for ( V_47 = 0 ; V_47 < V_297 ; V_47 ++ ) {
V_289 = V_46 -> V_298 [ V_47 ] ;
if ( V_289 != 0 ) {
V_46 -> V_298 [ V_47 ] = 0 ;
V_292 = (struct V_291 * ) ( V_6 -> V_159 + ( V_289 << 5 ) ) ;
V_284 = F_44 ( V_292 , struct V_138 , V_160 ) ;
error = ( V_289 & V_295 ) ? true : false ;
F_111 ( V_6 , V_284 , error ) ;
}
V_46 -> V_299 [ V_47 ] = 0 ;
}
V_46 -> V_300 = 0 ;
V_46 -> V_301 = 0 ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
while ( ( F_12 ( & V_46 -> V_101 ) & V_302 ) && ( V_47 ++ < V_211 ) ) {
V_289 = F_12 ( & V_46 -> V_303 ) ;
V_290 = ( V_289 & 0xFFFFFFF0 ) ;
V_292 = (struct V_291 * ) ( V_6 -> V_159 + V_290 ) ;
V_284 = F_44 ( V_292 , struct V_138 , V_160 ) ;
error = ( V_289 & V_304 ) ? true : false ;
F_111 ( V_6 , V_284 , error ) ;
}
}
break;
case V_9 : {
struct V_60 * V_305 = V_6 -> V_61 ;
T_6 V_306 ;
T_6 V_300 , V_307 , V_308 , V_309 , V_310 ;
unsigned long V_31 ;
V_309 = F_112 ( & V_6 -> V_255 ) ;
for ( V_47 = 0 ; V_47 < V_309 ; V_47 ++ ) {
F_107 ( & V_6 -> V_219 , V_31 ) ;
V_306 =
V_305 -> V_298 [ 0 ] . V_308 + 1 ;
V_300 = V_305 -> V_300 ;
if ( ( V_300 & 0xFFF ) !=
( V_306 & 0xFFF ) ) {
V_310 = V_300 & 0x4000 ;
V_307 = ( V_300 & 0xFFF ) + 1 ;
V_307 %= V_311 ;
V_305 -> V_300 = V_307 ? ( V_307 | V_310 ) :
( ( V_310 ^ 0x4000 ) + 1 ) ;
V_300 = V_305 -> V_300 ;
F_108 ( & V_6 -> V_219 , V_31 ) ;
V_308 = V_305 -> V_298 [ V_300 &
0xFFF ] . V_308 ;
V_290 = ( V_308 & 0xFFFFFFF0 ) ;
V_292 = (struct V_291 * )
( V_6 -> V_159 + V_290 ) ;
V_284 = F_44 ( V_292 ,
struct V_138 , V_160 ) ;
error = ( V_308 &
V_304 ) ?
true : false ;
F_111 ( V_6 , V_284 , error ) ;
F_13 ( V_300 ,
V_305 -> V_128 ) ;
} else {
F_108 ( & V_6 -> V_219 , V_31 ) ;
F_114 ( 10 ) ;
}
}
V_305 -> V_301 = 0 ;
V_305 -> V_300 = 0x40FF ;
}
break;
}
}
static void F_115 ( struct V_15 * V_10 )
{
struct V_195 * V_19 = F_90 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_206 ;
int V_312 = 0 ;
F_116 ( V_6 ) ;
F_84 ( V_19 ) ;
F_81 ( & V_6 -> V_166 ) ;
F_80 ( & V_6 -> V_235 ) ;
F_91 ( V_6 ) ;
F_82 ( V_6 ) ;
F_32 ( V_6 ) ;
V_6 -> V_186 |= V_225 ;
V_6 -> V_186 &= ~ V_313 ;
for ( V_312 = 0 ; V_312 < V_211 ; V_312 ++ ) {
if ( ! F_112 ( & V_6 -> V_255 ) )
break;
F_18 ( V_6 ) ;
F_24 ( 25 ) ;
}
if ( F_112 ( & V_6 -> V_255 ) ) {
int V_47 ;
F_102 ( V_6 ) ;
F_113 ( V_6 ) ;
for ( V_47 = 0 ; V_47 < V_157 ; V_47 ++ ) {
struct V_138 * V_252 = V_6 -> V_161 [ V_47 ] ;
if ( V_252 -> V_256 == V_285 ) {
V_252 -> V_256 = V_286 ;
V_252 -> V_254 -> V_262 = V_288 << 16 ;
F_105 ( V_252 ) ;
}
}
}
F_83 ( V_10 , V_6 ) ;
F_85 ( V_6 ) ;
F_3 ( V_6 ) ;
F_16 ( V_6 ) ;
F_86 ( V_10 ) ;
F_87 ( V_19 ) ;
F_88 ( V_10 ) ;
}
static void F_117 ( struct V_15 * V_10 )
{
struct V_195 * V_19 = F_90 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_206 ;
F_80 ( & V_6 -> V_235 ) ;
F_91 ( V_6 ) ;
F_83 ( V_10 , V_6 ) ;
F_81 ( & V_6 -> V_166 ) ;
F_82 ( V_6 ) ;
F_32 ( V_6 ) ;
}
static int F_118 ( void )
{
int error = 0 ;
error = F_119 ( & V_314 ) ;
return error ;
}
static void F_120 ( void )
{
F_121 ( & V_314 ) ;
}
static void F_122 ( struct V_5 * V_6 ,
T_8 V_244 )
{
T_8 V_315 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_315 = V_244 & ~ ( V_316 |
V_317 |
V_318 ) ;
F_13 ( V_315 , & V_46 -> V_271 ) ;
V_6 -> V_293 = ~ ( V_244 & V_315 ) & 0x000000ff ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_315 = V_244 | ( V_319 |
V_320 |
V_321 |
V_53 ) ;
F_13 ( V_315 , V_46 -> V_79 ) ;
V_6 -> V_293 = ( V_244 | V_315 ) & 0x0000000f ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
V_315 = ~ ( V_322 | V_323 | V_324 ) ;
F_13 ( V_244 & V_315 , & V_46 -> V_273 ) ;
V_6 -> V_293 = ~ ( V_244 & V_315 ) & 0x0000000f ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
V_315 = V_325 ;
F_13 ( V_244 | V_315 , V_46 -> V_103 ) ;
break;
}
}
}
static int F_123 ( struct V_5 * V_6 ,
struct V_138 * V_252 , struct V_253 * V_254 )
{
struct V_291 * V_160 = (struct V_291 * ) & V_252 -> V_160 ;
T_9 * V_326 = ( T_9 * ) & V_160 -> V_327 ;
T_10 V_328 , V_329 ;
int V_330 = 0x30 ;
T_10 V_331 = 0 ;
int V_47 ;
struct V_332 * V_333 ;
int V_334 ;
V_252 -> V_254 = V_254 ;
memset ( V_160 , 0 , sizeof( struct V_291 ) ) ;
V_160 -> V_335 = V_254 -> V_73 -> V_194 ;
V_160 -> V_336 = V_254 -> V_73 -> V_172 ;
V_160 -> V_337 = 1 ;
V_160 -> V_338 = 0 ;
memcpy ( V_160 -> V_339 , V_254 -> V_340 , V_254 -> V_341 ) ;
V_334 = F_124 ( V_254 ) ;
if ( F_125 ( V_334 > V_6 -> V_19 -> V_154 || V_334 < 0 ) )
return V_192 ;
F_126 (pcmd, sg, nseg, i) {
V_331 = F_127 ( F_128 ( V_333 ) ) ;
V_328 = F_127 ( F_129 ( F_130 ( V_333 ) ) ) ;
V_329 = F_127 ( F_131 ( F_130 ( V_333 ) ) ) ;
if ( V_329 == 0 ) {
struct V_342 * V_343 = (struct V_342 * ) V_326 ;
V_343 -> V_344 = V_328 ;
V_343 -> V_331 = V_331 ;
V_326 += sizeof ( struct V_342 ) ;
V_330 += sizeof ( struct V_342 ) ;
} else {
struct V_155 * V_343 = (struct V_155 * ) V_326 ;
V_343 -> V_345 = V_329 ;
V_343 -> V_344 = V_328 ;
V_343 -> V_331 = V_331 | F_127 ( V_346 ) ;
V_326 += sizeof ( struct V_155 ) ;
V_330 += sizeof ( struct V_155 ) ;
}
}
V_160 -> V_347 = ( T_4 ) V_334 ;
V_160 -> V_348 = F_132 ( V_254 ) ;
V_160 -> V_349 = V_330 / 0x100 + ( V_330 % 0x100 ? 1 : 0 ) ;
if ( V_330 > 256 )
V_160 -> V_350 |= V_351 ;
if ( V_254 -> V_352 == V_353 )
V_160 -> V_350 |= V_354 ;
V_252 -> V_355 = V_330 ;
return V_188 ;
}
static void F_133 ( struct V_5 * V_6 , struct V_138 * V_252 )
{
T_6 V_141 = V_252 -> V_141 ;
struct V_291 * V_160 = (struct V_291 * ) & V_252 -> V_160 ;
F_45 ( & V_6 -> V_255 ) ;
V_252 -> V_256 = V_285 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
if ( V_160 -> V_350 & V_351 )
F_13 ( V_141 | V_356 ,
& V_46 -> V_357 ) ;
else
F_13 ( V_141 , & V_46 -> V_357 ) ;
break;
}
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
T_6 V_358 , V_359 = V_46 -> V_301 ;
V_358 = ( ( V_359 + 1 ) % V_297 ) ;
V_46 -> V_299 [ V_358 ] = 0 ;
if ( V_160 -> V_350 & V_351 ) {
V_46 -> V_299 [ V_359 ] =
V_141 | V_356 ;
} else {
V_46 -> V_299 [ V_359 ] = V_141 ;
}
V_359 ++ ;
V_359 %= V_297 ;
V_46 -> V_301 = V_359 ;
F_13 ( V_360 , V_46 -> V_56 ) ;
}
break;
case V_23 : {
struct V_58 T_1 * V_59 = V_6 -> V_24 ;
T_6 V_361 , V_355 ;
V_355 = ( V_252 -> V_355 > 0x300 ) ? 0x300 : V_252 -> V_355 ;
V_361 = ( V_141 | ( ( V_355 - 1 ) >> 6 ) | 1 ) ;
if ( V_6 -> V_362 ) {
F_13 ( V_6 -> V_362 , & V_59 -> V_363 ) ;
F_13 ( V_361 , & V_59 -> V_364 ) ;
} else {
F_13 ( V_361 , & V_59 -> V_364 ) ;
}
}
break;
case V_9 : {
struct V_60 * V_305 = V_6 -> V_61 ;
T_11 V_307 ;
T_11 V_301 , V_310 ;
unsigned long V_31 ;
struct V_365 * V_366 ;
F_107 ( & V_6 -> V_218 , V_31 ) ;
V_301 = V_305 -> V_301 ;
V_366 = (struct V_365 * ) & ( V_305 -> V_299 [ V_301 & 0xFF ] ) ;
V_366 -> V_367 = F_131 ( V_141 ) ;
V_366 -> V_308 = F_129 ( V_141 ) ;
V_366 -> V_331 = V_252 -> V_355 >> 2 ;
V_160 -> V_338 = F_129 ( V_141 ) ;
V_310 = V_301 & 0x4000 ;
V_307 = V_301 + 1 ;
V_307 &= ( V_368 - 1 ) ;
V_305 -> V_301 = V_307 ? ( V_307 | V_310 ) :
( V_310 ^ 0x4000 ) ;
F_13 ( V_301 , V_305 -> V_120 ) ;
F_108 ( & V_6 -> V_218 , V_31 ) ;
break;
}
}
}
static void F_134 ( struct V_5 * V_6 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_6 -> V_186 &= ~ V_369 ;
F_13 ( V_370 , & V_46 -> V_65 ) ;
if ( ! F_23 ( V_6 ) ) {
F_9 ( V_18
L_24
, V_6 -> V_19 -> V_20 ) ;
}
}
static void F_135 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
V_6 -> V_186 &= ~ V_369 ;
F_13 ( V_371 , V_46 -> V_56 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_18
L_24
, V_6 -> V_19 -> V_20 ) ;
}
}
static void F_136 ( struct V_5 * V_57 )
{
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
V_57 -> V_186 &= ~ V_369 ;
F_13 ( V_370 , & V_46 -> V_65 ) ;
F_13 ( V_67 , & V_46 -> V_68 ) ;
if ( ! F_26 ( V_57 ) ) {
F_9 ( V_18
L_24
, V_57 -> V_19 -> V_20 ) ;
}
return;
}
static void F_137 ( struct V_5 * V_57 )
{
struct V_60 * V_46 = V_57 -> V_61 ;
V_57 -> V_186 &= ~ V_369 ;
F_13 ( V_370 , V_46 -> V_65 ) ;
if ( ! F_27 ( V_57 ) )
F_15 ( L_25
L_26 , V_57 -> V_19 -> V_20 ) ;
}
static void F_82 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
F_134 ( V_6 ) ;
}
break;
case V_8 : {
F_135 ( V_6 ) ;
}
break;
case V_23 : {
F_136 ( V_6 ) ;
}
break;
case V_9 :
F_137 ( V_6 ) ;
break;
}
}
static void F_85 ( struct V_5 * V_6 )
{
F_4 ( & V_6 -> V_10 -> V_11 , V_6 -> V_156 , V_6 -> V_70 , V_6 -> V_71 ) ;
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
static void F_139 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_376 , & V_46 -> V_68 ) ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_377 , V_46 -> V_56 ) ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
F_13 ( V_378 , & V_46 -> V_68 ) ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
F_13 ( V_379 ,
V_46 -> V_68 ) ;
}
break;
}
}
struct V_380 T_1 * F_140 ( struct V_5 * V_6 )
{
struct V_380 T_1 * V_381 = NULL ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_381 = (struct V_380 T_1 * ) & V_46 -> V_87 ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_381 = (struct V_380 T_1 * ) V_46 -> V_87 ;
}
break;
case V_23 : {
struct V_58 T_1 * V_59 = V_6 -> V_24 ;
V_381 = (struct V_380 T_1 * ) & V_59 -> V_87 ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
V_381 = (struct V_380 T_1 * ) V_46 -> V_87 ;
}
break;
}
return V_381 ;
}
static struct V_380 T_1 * F_141 ( struct V_5 * V_6 )
{
struct V_380 T_1 * V_382 = NULL ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_382 = (struct V_380 T_1 * ) & V_46 -> V_85 ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_382 = (struct V_380 T_1 * ) V_46 -> V_85 ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
V_382 = (struct V_380 T_1 * ) & V_46 -> V_85 ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
V_382 = (struct V_380 T_1 * ) V_46 -> V_85 ;
}
break;
}
return V_382 ;
}
static T_6
F_142 ( struct V_5 * V_6 ,
struct V_380 T_1 * V_383 )
{
T_4 * V_384 ;
T_4 * V_385 = NULL ;
T_6 T_1 * V_386 ;
T_6 V_387 , V_388 , * V_389 = NULL ;
V_386 = ( T_6 T_1 * ) V_383 -> V_239 ;
V_387 = F_12 ( & V_383 -> V_388 ) ;
if ( V_387 > 0 ) {
V_385 = F_143 ( 128 , V_390 ) ;
V_389 = ( T_6 * ) V_385 ;
if ( V_385 == NULL )
return 0 ;
V_388 = V_387 ;
while ( V_388 >= 4 ) {
* V_389 ++ = F_12 ( V_386 ) ;
V_386 ++ ;
V_388 -= 4 ;
}
if ( V_388 )
* V_389 = F_12 ( V_386 ) ;
V_389 = ( T_6 * ) V_385 ;
}
while ( V_387 > 0 ) {
V_384 = & V_6 -> V_391 [ V_6 -> V_392 ] ;
* V_384 = * V_385 ;
V_6 -> V_392 ++ ;
V_6 -> V_392 %= V_393 ;
V_385 ++ ;
V_387 -- ;
}
F_22 ( V_389 ) ;
F_138 ( V_6 ) ;
return 1 ;
}
T_6
F_144 ( struct V_5 * V_6 ,
struct V_380 T_1 * V_383 ) {
T_4 * V_384 ;
T_4 T_1 * V_386 ;
T_6 V_387 ;
if ( V_6 -> V_7 & ( V_23 | V_9 ) )
return F_142 ( V_6 , V_383 ) ;
V_386 = ( T_4 T_1 * ) V_383 -> V_239 ;
V_387 = F_12 ( & V_383 -> V_388 ) ;
while ( V_387 > 0 ) {
V_384 = & V_6 -> V_391 [ V_6 -> V_392 ] ;
* V_384 = F_46 ( V_386 ) ;
V_6 -> V_392 ++ ;
V_6 -> V_392 %= V_393 ;
V_386 ++ ;
V_387 -- ;
}
F_138 ( V_6 ) ;
return 1 ;
}
static void F_145 ( struct V_5 * V_6 )
{
unsigned long V_31 ;
struct V_380 T_1 * V_383 ;
T_12 V_394 ;
F_107 ( & V_6 -> V_220 , V_31 ) ;
V_383 = F_140 ( V_6 ) ;
V_394 = ( V_6 -> V_392 - V_6 -> V_395 - 1 ) &
( V_393 - 1 ) ;
if ( V_394 >= F_12 ( & V_383 -> V_388 ) ) {
if ( F_144 ( V_6 , V_383 ) == 0 )
V_6 -> V_186 |= V_396 ;
} else
V_6 -> V_186 |= V_396 ;
F_108 ( & V_6 -> V_220 , V_31 ) ;
}
static void F_146 ( struct V_5 * V_6 )
{
T_4 * V_384 ;
struct V_380 T_1 * V_397 ;
T_4 * V_385 = NULL ;
T_6 T_1 * V_386 ;
T_6 V_398 = 0 , V_388 , * V_389 = NULL , V_239 ;
if ( V_6 -> V_186 & V_224 ) {
V_385 = F_143 ( 128 , V_390 ) ;
V_389 = ( T_6 * ) V_385 ;
if ( V_385 == NULL )
return;
V_6 -> V_186 &= ( ~ V_224 ) ;
V_397 = F_141 ( V_6 ) ;
V_386 = ( T_6 T_1 * ) V_397 -> V_239 ;
while ( ( V_6 -> V_399 != V_6 -> V_400 )
&& ( V_398 < 124 ) ) {
V_384 = & V_6 -> V_401 [ V_6 -> V_399 ] ;
* V_385 = * V_384 ;
V_6 -> V_399 ++ ;
V_6 -> V_399 %= V_393 ;
V_385 ++ ;
V_398 ++ ;
}
V_388 = V_398 ;
V_385 = ( T_4 * ) V_389 ;
while ( V_388 >= 4 ) {
V_239 = * V_389 ++ ;
F_13 ( V_239 , V_386 ) ;
V_386 ++ ;
V_388 -= 4 ;
}
if ( V_388 ) {
V_239 = * V_389 ;
F_13 ( V_239 , V_386 ) ;
}
F_13 ( V_398 , & V_397 -> V_388 ) ;
F_22 ( V_385 ) ;
F_139 ( V_6 ) ;
}
}
void
F_147 ( struct V_5 * V_6 )
{
T_4 * V_384 ;
struct V_380 T_1 * V_397 ;
T_4 T_1 * V_386 ;
T_12 V_398 = 0 ;
if ( V_6 -> V_7 & ( V_23 | V_9 ) ) {
F_146 ( V_6 ) ;
return;
}
if ( V_6 -> V_186 & V_224 ) {
V_6 -> V_186 &= ( ~ V_224 ) ;
V_397 = F_141 ( V_6 ) ;
V_386 = ( T_4 T_1 * ) V_397 -> V_239 ;
while ( ( V_6 -> V_399 != V_6 -> V_400 )
&& ( V_398 < 124 ) ) {
V_384 = & V_6 -> V_401 [ V_6 -> V_399 ] ;
F_148 ( * V_384 , V_386 ) ;
V_6 -> V_399 ++ ;
V_6 -> V_399 %= V_393 ;
V_386 ++ ;
V_398 ++ ;
}
F_13 ( V_398 , & V_397 -> V_388 ) ;
F_139 ( V_6 ) ;
}
}
static void F_149 ( struct V_5 * V_6 )
{
unsigned long V_31 ;
F_107 ( & V_6 -> V_221 , V_31 ) ;
V_6 -> V_186 |= V_224 ;
if ( V_6 -> V_399 != V_6 -> V_400 )
F_147 ( V_6 ) ;
if ( V_6 -> V_399 == V_6 -> V_400 )
V_6 -> V_186 |= V_222 ;
F_108 ( & V_6 -> V_221 , V_31 ) ;
}
static void F_150 ( struct V_5 * V_6 )
{
T_6 V_25 ;
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_25 = F_12 ( & V_46 -> V_25 ) ;
do {
F_13 ( V_25 , & V_46 -> V_25 ) ;
if ( V_25 & V_402 )
F_145 ( V_6 ) ;
if ( V_25 & V_403 )
F_149 ( V_6 ) ;
V_25 = F_12 ( & V_46 -> V_25 ) ;
} while ( V_25 & ( V_402
| V_403 ) );
}
static void F_151 ( struct V_5 * V_57 )
{
T_6 V_25 ;
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
V_25 = F_12 ( & V_46 -> V_25 ) ;
do {
F_13 ( V_25 , & V_46 -> V_28 ) ;
F_12 ( & V_46 -> V_28 ) ;
if ( V_25 & V_404 )
F_145 ( V_57 ) ;
if ( V_25 & V_405 )
F_149 ( V_57 ) ;
if ( V_25 & V_26 )
F_152 ( V_57 ) ;
V_25 = F_12 ( & V_46 -> V_25 ) ;
} while ( V_25 & ( V_404
| V_405
| V_26 ) );
}
static void F_153 ( struct V_5 * V_57 )
{
T_6 V_25 ;
struct V_60 * V_305 = V_57 -> V_61 ;
V_25 = F_12 ( V_305 -> V_25 ) ;
do {
F_13 ( V_25 , V_305 -> V_25 ) ;
if ( V_25 & V_62 )
F_154 ( V_57 ) ;
if ( V_25 & V_406 )
F_145 ( V_57 ) ;
if ( V_25 & V_407 )
F_149 ( V_57 ) ;
V_25 = F_12 ( V_305 -> V_25 ) ;
} while ( V_25 & ( V_406
| V_407
| V_62 ) );
}
static void F_155 ( struct V_5 * V_6 )
{
T_6 V_289 ;
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
struct V_291 * V_292 ;
struct V_138 * V_284 ;
bool error ;
while ( ( V_289 = F_12 ( & V_46 -> V_294 ) ) != 0xFFFFFFFF ) {
V_292 = (struct V_291 * ) ( V_6 -> V_159 + ( V_289 << 5 ) ) ;
V_284 = F_44 ( V_292 , struct V_138 , V_160 ) ;
error = ( V_289 & V_295 ) ? true : false ;
F_111 ( V_6 , V_284 , error ) ;
}
}
static void F_156 ( struct V_5 * V_6 )
{
T_6 V_359 ;
T_6 V_289 ;
struct V_50 * V_46 = V_6 -> V_51 ;
struct V_291 * V_292 ;
struct V_138 * V_284 ;
bool error ;
V_359 = V_46 -> V_300 ;
while ( ( V_289 = V_46 -> V_298 [ V_359 ] ) != 0 ) {
V_46 -> V_298 [ V_359 ] = 0 ;
V_292 = (struct V_291 * ) ( V_6 -> V_159 + ( V_289 << 5 ) ) ;
V_284 = F_44 ( V_292 , struct V_138 , V_160 ) ;
error = ( V_289 & V_295 ) ? true : false ;
F_111 ( V_6 , V_284 , error ) ;
V_359 ++ ;
V_359 %= V_297 ;
V_46 -> V_300 = V_359 ;
}
}
static void F_157 ( struct V_5 * V_6 )
{
struct V_58 T_1 * V_59 ;
struct V_291 * V_160 ;
struct V_138 * V_252 ;
T_6 V_289 , V_290 , V_408 = 0 ;
int error ;
V_59 = V_6 -> V_24 ;
while ( ( V_289 = F_12 ( & V_59 -> V_303 ) ) !=
0xFFFFFFFF ) {
V_290 = ( V_289 & 0xFFFFFFF0 ) ;
V_160 = (struct V_291 * ) ( V_6 -> V_159
+ V_290 ) ;
V_252 = F_44 ( V_160 , struct V_138 ,
V_160 ) ;
error = ( V_289 & V_304 )
? true : false ;
F_111 ( V_6 , V_252 , error ) ;
V_408 ++ ;
if ( V_408 == V_409 ) {
F_13 ( V_410 ,
& V_59 -> V_68 ) ;
V_408 = 0 ;
}
}
}
static void F_158 ( struct V_5 * V_6 )
{
T_8 V_306 , V_300 , V_307 , V_310 ;
T_6 V_308 , V_290 ;
int error ;
struct V_60 * V_305 ;
struct V_291 * V_160 ;
struct V_138 * V_252 ;
unsigned long V_31 ;
F_107 ( & V_6 -> V_219 , V_31 ) ;
V_305 = V_6 -> V_61 ;
V_306 = V_305 -> V_298 [ 0 ] . V_308 + 1 ;
V_300 = V_305 -> V_300 ;
if ( ( V_300 & 0xFFF ) != ( V_306 & 0xFFF ) ) {
do {
V_310 = V_300 & 0x4000 ;
V_307 = ( V_300 & 0xFFF ) + 1 ;
V_307 %= V_311 ;
V_305 -> V_300 = V_307 ? ( V_307 | V_310 ) :
( ( V_310 ^ 0x4000 ) + 1 ) ;
V_300 = V_305 -> V_300 ;
V_308 = V_305 -> V_298 [ V_300 &
0xFFF ] . V_308 ;
V_290 = ( V_308 & 0xFFFFFFF0 ) ;
V_160 = (struct V_291 * ) ( V_6 -> V_159
+ V_290 ) ;
V_252 = F_44 ( V_160 ,
struct V_138 , V_160 ) ;
error = ( V_308 & V_304 )
? true : false ;
F_111 ( V_6 , V_252 , error ) ;
F_13 ( V_300 , V_305 -> V_128 ) ;
} while ( ( V_300 & 0xFFF ) !=
( V_306 & 0xFFF ) );
}
F_13 ( V_411 ,
V_305 -> V_130 ) ;
F_12 ( V_305 -> V_130 ) ;
F_108 ( & V_6 -> V_219 , V_31 ) ;
}
static void F_159 ( struct V_5 * V_6 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_49 , & V_46 -> V_48 ) ;
F_160 ( & V_6 -> V_166 ) ;
}
static void F_161 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_54 , V_46 -> V_52 ) ;
F_160 ( & V_6 -> V_166 ) ;
}
static void F_152 ( struct V_5 * V_6 )
{
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
F_13 ( V_27 , & V_46 -> V_28 ) ;
F_160 ( & V_6 -> V_166 ) ;
}
static void F_154 ( struct V_5 * V_6 )
{
struct V_60 * V_46 = V_6 -> V_61 ;
F_13 ( V_62 , V_46 -> V_25 ) ;
F_12 ( V_46 -> V_25 ) ;
F_160 ( & V_6 -> V_166 ) ;
}
static int F_162 ( struct V_5 * V_6 )
{
T_6 V_48 ;
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_48 = F_12 ( & V_46 -> V_48 ) &
V_6 -> V_293 ;
if ( ! ( V_48 & V_412 ) )
return V_413 ;
do {
F_13 ( V_48 , & V_46 -> V_48 ) ;
if ( V_48 & V_414 )
F_150 ( V_6 ) ;
if ( V_48 & V_415 )
F_155 ( V_6 ) ;
if ( V_48 & V_49 )
F_159 ( V_6 ) ;
V_48 = F_12 ( & V_46 -> V_48 ) &
V_6 -> V_293 ;
} while ( V_48 & ( V_414
| V_415
| V_49 ) );
return V_416 ;
}
static int F_163 ( struct V_5 * V_6 )
{
T_6 V_25 ;
struct V_50 * V_46 = V_6 -> V_51 ;
V_25 = F_12 ( V_46 -> V_52 ) &
V_6 -> V_293 ;
if ( ! V_25 )
return V_413 ;
do {
F_13 ( ~ V_25 , V_46 -> V_52 ) ;
F_13 ( V_55 , V_46 -> V_56 ) ;
if ( V_25 & V_319 )
F_145 ( V_6 ) ;
if ( V_25 & V_320 )
F_149 ( V_6 ) ;
if ( V_25 & V_321 )
F_156 ( V_6 ) ;
if ( V_25 & V_53 )
F_161 ( V_6 ) ;
V_25 = F_12 ( V_46 -> V_52 ) &
V_6 -> V_293 ;
} while ( V_25 & ( V_319
| V_320
| V_321
| V_53 ) );
return V_416 ;
}
static int F_164 ( struct V_5 * V_57 )
{
T_6 V_417 ;
struct V_58 T_1 * V_59 = V_57 -> V_24 ;
V_417 = F_12 ( & V_59 -> V_101 ) &
( V_302 |
V_418 ) ;
if ( ! V_417 )
return V_413 ;
do {
if ( V_417 & V_418 )
F_151 ( V_57 ) ;
if ( V_417 & V_302 )
F_157 ( V_57 ) ;
V_417 = F_12 ( & V_59 -> V_101 ) ;
} while ( V_417 & ( V_302 |
V_418 ) );
return V_416 ;
}
static T_2 F_165 ( struct V_5 * V_57 )
{
T_8 V_417 ;
struct V_60 * V_305 = V_57 -> V_61 ;
V_417 = F_12 ( V_305 -> V_101 ) &
( V_419 |
V_420 ) ;
if ( ! V_417 )
return V_413 ;
do {
if ( V_417 &
V_419 )
F_158 ( V_57 ) ;
if ( V_417 &
V_420 )
F_153 ( V_57 ) ;
V_417 = F_12 ( V_305 -> V_101 ) ;
} while ( V_417 &
( V_419 |
V_420 ) );
return V_416 ;
}
static T_2 F_18 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 :
return F_162 ( V_6 ) ;
break;
case V_8 :
return F_163 ( V_6 ) ;
break;
case V_23 :
return F_164 ( V_6 ) ;
case V_9 :
return F_165 ( V_6 ) ;
default:
return V_413 ;
}
}
static void F_166 ( struct V_5 * V_6 )
{
if ( V_6 ) {
if ( V_6 -> V_186 & V_369 ) {
T_6 V_244 ;
V_6 -> V_186 &= ~ V_369 ;
V_244 = F_91 ( V_6 ) ;
F_82 ( V_6 ) ;
F_32 ( V_6 ) ;
F_122 ( V_6 , V_244 ) ;
}
}
}
void F_167 ( struct V_5 * V_6 )
{
T_6 V_47 ;
if ( V_6 -> V_186 & V_396 ) {
for ( V_47 = 0 ; V_47 < 15 ; V_47 ++ ) {
if ( V_6 -> V_186 & V_396 ) {
V_6 -> V_186 &= ~ V_396 ;
V_6 -> V_395 = 0 ;
V_6 -> V_392 = 0 ;
F_138 ( V_6 ) ;
F_114 ( 30 ) ;
} else if ( V_6 -> V_395 !=
V_6 -> V_392 ) {
V_6 -> V_395 = 0 ;
V_6 -> V_392 = 0 ;
F_114 ( 30 ) ;
} else
break;
}
}
}
static int F_168 ( struct V_5 * V_6 ,
struct V_253 * V_421 )
{
char * V_44 ;
unsigned short V_422 ;
int V_423 = 0 , V_424 = 0 ;
unsigned long V_31 ;
struct V_425 * V_426 ;
T_6 V_427 = ( T_6 ) V_421 -> V_340 [ 5 ] << 24 |
( T_6 ) V_421 -> V_340 [ 6 ] << 16 |
( T_6 ) V_421 -> V_340 [ 7 ] << 8 |
( T_6 ) V_421 -> V_340 [ 8 ] ;
struct V_332 * V_333 ;
V_422 = F_169 ( V_421 ) ;
V_333 = F_170 ( V_421 ) ;
V_44 = F_171 ( F_172 ( V_333 ) ) + V_333 -> V_428 ;
if ( V_422 > 1 ) {
V_423 = V_429 ;
goto V_430;
}
V_424 += V_333 -> V_331 ;
if ( V_424 > sizeof( struct V_425 ) ) {
V_423 = V_429 ;
F_57 ( L_27 , V_246 ) ;
goto V_430;
}
V_426 = (struct V_425 * ) V_44 ;
switch ( V_427 ) {
case V_431 : {
unsigned char * V_432 ;
T_4 * V_433 ;
T_6 V_398 = 0 ;
V_432 = F_143 ( V_434 , V_390 ) ;
if ( ! V_432 ) {
V_423 = V_429 ;
F_57 ( L_28 , V_246 ) ;
goto V_430;
}
V_433 = V_432 ;
F_107 ( & V_6 -> V_220 , V_31 ) ;
if ( V_6 -> V_395 != V_6 -> V_392 ) {
unsigned int V_435 = V_6 -> V_395 ;
unsigned int V_436 = V_6 -> V_392 ;
unsigned int V_437 = F_173 ( V_436 , V_435 , V_393 ) ;
V_398 = F_174 ( V_436 , V_435 , V_393 ) ;
if ( V_398 > V_434 )
V_398 = V_434 ;
if ( V_398 <= V_437 )
memcpy ( V_433 , V_6 -> V_391 + V_435 , V_398 ) ;
else {
memcpy ( V_433 , V_6 -> V_391 + V_435 , V_437 ) ;
memcpy ( V_433 + V_437 , V_6 -> V_391 , V_398 - V_437 ) ;
}
V_6 -> V_395 = ( V_6 -> V_395 + V_398 ) % V_393 ;
}
memcpy ( V_426 -> V_438 , V_432 ,
V_398 ) ;
if ( V_6 -> V_186 & V_396 ) {
struct V_380 T_1 * V_383 ;
V_6 -> V_186 &= ~ V_396 ;
V_383 = F_140 ( V_6 ) ;
if ( F_144 ( V_6 , V_383 ) == 0 )
V_6 -> V_186 |= V_396 ;
}
F_108 ( & V_6 -> V_220 , V_31 ) ;
F_22 ( V_432 ) ;
V_426 -> V_439 . V_440 = V_398 ;
if ( V_6 -> V_233 == V_441 )
V_426 -> V_439 . V_442 =
V_443 ;
else
V_426 -> V_439 . V_442 =
V_444 ;
break;
}
case V_445 : {
unsigned char * V_432 ;
T_6 V_446 ;
T_12 V_447 ;
T_4 * V_384 , * V_448 ;
V_446 = V_426 -> V_439 . V_440 ;
if ( V_446 > V_434 ) {
V_423 = V_429 ;
goto V_430;
}
V_432 = F_143 ( V_434 , V_390 ) ;
if ( ! V_432 ) {
V_423 = V_429 ;
goto V_430;
}
V_448 = V_432 ;
memcpy ( V_448 ,
V_426 -> V_438 , V_446 ) ;
F_107 ( & V_6 -> V_221 , V_31 ) ;
if ( V_6 -> V_400 != V_6 -> V_399 ) {
struct V_259 * V_260 =
(struct V_259 * ) V_421 -> V_261 ;
F_147 ( V_6 ) ;
V_260 -> V_267 = V_268 ;
V_260 -> V_449 = V_450 ;
V_260 -> V_451 = 0x0A ;
V_260 -> V_452 = 0x20 ;
V_260 -> V_269 = 1 ;
V_423 = V_429 ;
} else {
V_384 = & V_6 -> V_401 [ V_6 -> V_400 ] ;
V_447 = V_393 - V_6 -> V_400 ;
if ( V_446 > V_447 ) {
memcpy ( V_384 , V_448 , V_447 ) ;
V_448 += V_447 ;
V_446 -= V_447 ;
V_6 -> V_400 = 0 ;
V_384 = V_6 -> V_401 ;
}
memcpy ( V_384 , V_448 , V_446 ) ;
V_6 -> V_400 += V_446 ;
V_6 -> V_400 %= V_393 ;
if ( V_6 -> V_186 & V_222 ) {
V_6 -> V_186 &=
~ V_222 ;
F_147 ( V_6 ) ;
}
}
F_108 ( & V_6 -> V_221 , V_31 ) ;
F_22 ( V_432 ) ;
if ( V_6 -> V_233 == V_441 )
V_426 -> V_439 . V_442 =
V_443 ;
else
V_426 -> V_439 . V_442 =
V_444 ;
break;
}
case V_453 : {
T_4 * V_384 = V_6 -> V_391 ;
F_167 ( V_6 ) ;
F_107 ( & V_6 -> V_220 , V_31 ) ;
V_6 -> V_186 |= V_223 ;
V_6 -> V_395 = 0 ;
V_6 -> V_392 = 0 ;
memset ( V_384 , 0 , V_393 ) ;
F_108 ( & V_6 -> V_220 , V_31 ) ;
if ( V_6 -> V_233 == V_441 )
V_426 -> V_439 . V_442 =
V_443 ;
else
V_426 -> V_439 . V_442 =
V_444 ;
break;
}
case V_454 : {
T_4 * V_384 = V_6 -> V_401 ;
F_107 ( & V_6 -> V_221 , V_31 ) ;
V_6 -> V_186 |= ( V_222 |
V_224 ) ;
V_6 -> V_399 = 0 ;
V_6 -> V_400 = 0 ;
memset ( V_384 , 0 , V_393 ) ;
F_108 ( & V_6 -> V_221 , V_31 ) ;
if ( V_6 -> V_233 == V_441 )
V_426 -> V_439 . V_442 =
V_443 ;
else
V_426 -> V_439 . V_442 =
V_444 ;
break;
}
case V_455 : {
T_4 * V_384 ;
F_167 ( V_6 ) ;
F_107 ( & V_6 -> V_220 , V_31 ) ;
V_6 -> V_186 |= V_223 ;
V_6 -> V_395 = 0 ;
V_6 -> V_392 = 0 ;
V_384 = V_6 -> V_391 ;
memset ( V_384 , 0 , sizeof( struct V_380 ) ) ;
F_108 ( & V_6 -> V_220 , V_31 ) ;
F_107 ( & V_6 -> V_221 , V_31 ) ;
V_6 -> V_186 |= ( V_222 |
V_224 ) ;
V_6 -> V_399 = 0 ;
V_6 -> V_400 = 0 ;
V_384 = V_6 -> V_401 ;
memset ( V_384 , 0 , sizeof( struct V_380 ) ) ;
F_108 ( & V_6 -> V_221 , V_31 ) ;
if ( V_6 -> V_233 == V_441 )
V_426 -> V_439 . V_442 =
V_443 ;
else
V_426 -> V_439 . V_442 =
V_444 ;
break;
}
case V_456 : {
if ( V_6 -> V_233 == V_441 )
V_426 -> V_439 . V_442 =
V_443 ;
else
V_426 -> V_439 . V_442 =
V_457 ;
break;
}
case V_458 : {
T_9 * V_459 = L_29 ;
if ( V_6 -> V_233 == V_441 )
V_426 -> V_439 . V_442 =
V_443 ;
else
V_426 -> V_439 . V_442 =
V_444 ;
memcpy ( V_426 -> V_438 ,
V_459 , ( V_460 ) strlen ( V_459 ) ) ;
break;
}
case V_461 : {
if ( V_6 -> V_233 == V_441 )
V_426 -> V_439 . V_442 =
V_443 ;
else
V_426 -> V_439 . V_442 =
V_444 ;
F_166 ( V_6 ) ;
break;
}
case V_462 : {
if ( V_6 -> V_233 == V_441 )
V_426 -> V_439 . V_442 =
V_443 ;
else
V_426 -> V_439 . V_442 =
V_444 ;
F_32 ( V_6 ) ;
break;
}
default:
V_423 = V_429 ;
F_57 ( L_30 , V_246 ) ;
}
V_430:
if ( V_422 ) {
struct V_332 * V_333 = F_170 ( V_421 ) ;
F_175 ( V_44 - V_333 -> V_428 ) ;
}
return V_423 ;
}
static struct V_138 * F_176 ( struct V_5 * V_6 )
{
struct V_463 * V_436 = & V_6 -> V_163 ;
struct V_138 * V_252 = NULL ;
unsigned long V_31 ;
F_107 ( & V_6 -> V_217 , V_31 ) ;
if ( ! F_177 ( V_436 ) ) {
V_252 = F_178 ( V_436 -> V_464 , struct V_138 , V_162 ) ;
F_179 ( & V_252 -> V_162 ) ;
} else{
F_108 ( & V_6 -> V_217 , V_31 ) ;
return NULL ;
}
F_108 ( & V_6 -> V_217 , V_31 ) ;
return V_252 ;
}
static void F_180 ( struct V_5 * V_6 ,
struct V_253 * V_421 )
{
switch ( V_421 -> V_340 [ 0 ] ) {
case V_465 : {
unsigned char V_466 [ 36 ] ;
char * V_44 ;
struct V_332 * V_333 ;
if ( V_421 -> V_73 -> V_172 ) {
V_421 -> V_262 = ( V_467 << 16 ) ;
V_421 -> V_258 ( V_421 ) ;
return;
}
V_466 [ 0 ] = V_468 ;
V_466 [ 1 ] = 0 ;
V_466 [ 2 ] = 0 ;
V_466 [ 4 ] = 31 ;
strncpy ( & V_466 [ 8 ] , L_31 , 8 ) ;
strncpy ( & V_466 [ 16 ] , L_32 , 16 ) ;
strncpy ( & V_466 [ 32 ] , L_33 , 4 ) ;
V_333 = F_170 ( V_421 ) ;
V_44 = F_171 ( F_172 ( V_333 ) ) + V_333 -> V_428 ;
memcpy ( V_44 , V_466 , sizeof( V_466 ) ) ;
V_333 = F_170 ( V_421 ) ;
F_175 ( V_44 - V_333 -> V_428 ) ;
V_421 -> V_258 ( V_421 ) ;
}
break;
case V_469 :
case V_470 : {
if ( F_168 ( V_6 , V_421 ) )
V_421 -> V_262 = ( V_471 << 16 ) ;
V_421 -> V_258 ( V_421 ) ;
}
break;
default:
V_421 -> V_258 ( V_421 ) ;
}
}
static int F_181 ( struct V_253 * V_421 ,
void (* F_182)( struct V_253 * ) )
{
struct V_195 * V_19 = V_421 -> V_73 -> V_19 ;
struct V_5 * V_6 = (struct V_5 * ) V_19 -> V_206 ;
struct V_138 * V_252 ;
int V_171 = V_421 -> V_73 -> V_194 ;
V_421 -> V_258 = F_182 ;
V_421 -> V_472 = NULL ;
V_421 -> V_262 = 0 ;
if ( V_171 == 16 ) {
F_180 ( V_6 , V_421 ) ;
return 0 ;
}
V_252 = F_176 ( V_6 ) ;
if ( ! V_252 )
return V_473 ;
if ( F_123 ( V_6 , V_252 , V_421 ) == V_192 ) {
V_421 -> V_262 = ( V_471 << 16 ) | ( V_474 << 1 ) ;
V_421 -> V_258 ( V_421 ) ;
return 0 ;
}
F_133 ( V_6 , V_252 ) ;
return 0 ;
}
bool F_183 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
char * V_475 = V_6 -> V_476 ;
char * V_477 = V_6 -> V_478 ;
char * V_479 = V_6 -> V_168 ;
char T_1 * V_480 ;
char T_1 * V_481 ;
char T_1 * V_482 ;
int V_483 ;
V_480 = ( char T_1 * ) ( & V_46 -> V_89 [ 15 ] ) ;
V_481 = ( char T_1 * ) ( & V_46 -> V_89 [ 17 ] ) ;
V_482 = ( char T_1 * ) ( & V_46 -> V_89 [ 21 ] ) ;
F_184 ( V_6 ) ;
F_13 ( V_484 , V_46 -> V_56 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_485 L_34 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
F_13 ( V_486 , V_46 -> V_56 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_18 L_35 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_483 = 8 ;
while ( V_483 ) {
* V_475 = F_46 ( V_480 ) ;
V_475 ++ ;
V_480 ++ ;
V_483 -- ;
}
V_483 = 16 ;
while ( V_483 ) {
* V_477 = F_46 ( V_481 ) ;
V_477 ++ ;
V_481 ++ ;
V_483 -- ;
}
V_483 = 16 ;
while( V_483 ) {
* V_479 = F_46 ( V_482 ) ;
V_479 ++ ;
V_482 ++ ;
V_483 -- ;
}
F_15 ( L_36 ,
V_6 -> V_19 -> V_20 ,
V_6 -> V_476 ,
V_6 -> V_478 ) ;
V_6 -> V_169 = F_12 ( & V_46 -> V_89 [ 0 ] ) ;
V_6 -> V_487 = F_12 ( & V_46 -> V_89 [ 1 ] ) ;
V_6 -> V_488 = F_12 ( & V_46 -> V_89 [ 2 ] ) ;
V_6 -> V_489 = F_12 ( & V_46 -> V_89 [ 3 ] ) ;
V_6 -> V_490 = F_12 ( & V_46 -> V_89 [ 4 ] ) ;
V_6 -> V_151 = F_12 ( & V_46 -> V_89 [ 25 ] ) ;
return true ;
}
static bool F_185 ( struct V_5 * V_57 )
{
T_6 V_244 , V_491 , V_492 = 0 ;
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
char * V_475 = V_57 -> V_476 ;
char * V_477 = V_57 -> V_478 ;
char T_1 * V_480 = ( char T_1 * ) ( & V_46 -> V_136 [ 15 ] ) ;
char T_1 * V_481 = ( char T_1 * ) ( & V_46 -> V_136 [ 17 ] ) ;
int V_483 ;
V_244 = F_12 ( & V_46 -> V_273 ) ;
F_13 ( V_244 | V_274 , & V_46 -> V_273 ) ;
do {
V_492 = F_12 ( & V_46 -> V_110 ) ;
} while ( ( V_492 & V_493 ) == 0 );
F_13 ( V_494 , & V_46 -> V_65 ) ;
F_13 ( V_67 , & V_46 -> V_68 ) ;
for ( V_491 = 0 ; V_491 < 2000 ; V_491 ++ ) {
if ( F_12 ( & V_46 -> V_25 ) & V_26 ) {
F_13 ( V_27 , & V_46 -> V_28 ) ;
break;
}
F_186 ( 10 ) ;
}
if ( V_491 >= 2000 ) {
F_9 ( V_18 L_35 , V_57 -> V_19 -> V_20 ) ;
return false ;
}
V_483 = 8 ;
while ( V_483 ) {
* V_475 = F_46 ( V_480 ) ;
V_475 ++ ;
V_480 ++ ;
V_483 -- ;
}
V_483 = 16 ;
while ( V_483 ) {
* V_477 = F_46 ( V_481 ) ;
V_477 ++ ;
V_481 ++ ;
V_483 -- ;
}
F_15 ( L_36 ,
V_57 -> V_19 -> V_20 ,
V_57 -> V_476 ,
V_57 -> V_478 ) ;
V_57 -> V_487 = F_12 ( & V_46 -> V_136 [ 1 ] ) ;
V_57 -> V_488 = F_12 ( & V_46 -> V_136 [ 2 ] ) ;
V_57 -> V_489 = F_12 ( & V_46 -> V_136 [ 3 ] ) ;
V_57 -> V_490 = F_12 ( & V_46 -> V_136 [ 4 ] ) ;
V_57 -> V_151 = F_12 ( & V_46 -> V_136 [ 25 ] ) ;
return true ;
}
static bool F_187 ( struct V_5 * V_6 )
{
char * V_475 = V_6 -> V_476 ;
char * V_477 = V_6 -> V_478 ;
char * V_479 = V_6 -> V_168 ;
char T_1 * V_480 ;
char T_1 * V_481 ;
char T_1 * V_482 ;
T_8 V_483 ;
struct V_60 * V_46 = V_6 -> V_61 ;
V_480 = ( char T_1 * ) ( & V_46 -> V_136 [ 15 ] ) ;
V_481 = ( char T_1 * ) ( & V_46 -> V_136 [ 17 ] ) ;
V_482 = ( char T_1 * ) ( & V_46 -> V_136 [ 21 ] ) ;
if ( F_12 ( V_6 -> V_61 -> V_25 ) &
V_62 ) {
F_13 ( V_62 ,
V_6 -> V_61 -> V_25 ) ;
}
F_13 ( V_494 , V_46 -> V_65 ) ;
if ( ! F_27 ( V_6 ) ) {
F_15 ( L_37
L_38 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_483 = 8 ;
while ( V_483 ) {
* V_475 = F_46 ( V_480 ) ;
V_475 ++ ;
V_480 ++ ;
V_483 -- ;
}
V_483 = 16 ;
while ( V_483 ) {
* V_477 = F_46 ( V_481 ) ;
V_477 ++ ;
V_481 ++ ;
V_483 -- ;
}
V_483 = 16 ;
while ( V_483 ) {
* V_479 = F_46 ( V_482 ) ;
V_479 ++ ;
V_482 ++ ;
V_483 -- ;
}
V_6 -> V_169 = F_12 ( & V_46 -> V_136 [ 0 ] ) ;
V_6 -> V_487 = F_12 ( & V_46 -> V_136 [ 1 ] ) ;
V_6 -> V_488 = F_12 ( & V_46 -> V_136 [ 2 ] ) ;
V_6 -> V_489 = F_12 ( & V_46 -> V_136 [ 3 ] ) ;
V_6 -> V_490 = F_12 ( & V_46 -> V_136 [ 4 ] ) ;
V_6 -> V_151 = F_12 ( & V_46 -> V_136 [ 25 ] ) ;
F_15 ( L_36 ,
V_6 -> V_19 -> V_20 ,
V_6 -> V_476 ,
V_6 -> V_478 ) ;
return true ;
}
static bool F_70 ( struct V_5 * V_6 )
{
bool V_69 = false ;
switch ( V_6 -> V_7 ) {
case V_16 :
V_69 = F_188 ( V_6 ) ;
break;
case V_8 :
V_69 = F_183 ( V_6 ) ;
break;
case V_23 :
V_69 = F_185 ( V_6 ) ;
break;
case V_9 :
V_69 = F_187 ( V_6 ) ;
break;
default:
break;
}
if ( V_6 -> V_488 > V_211 )
V_6 -> V_495 = V_211 ;
else
V_6 -> V_495 = V_6 -> V_488 - 1 ;
V_6 -> V_19 -> V_210 = V_6 -> V_495 ;
return V_69 ;
}
static int F_189 ( struct V_5 * V_6 ,
struct V_138 * V_496 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
struct V_138 * V_252 ;
struct V_291 * V_160 ;
T_6 V_289 , V_48 , V_497 = 0 , V_312 = 0 ;
int V_69 ;
bool error ;
V_498:
V_312 ++ ;
V_48 = F_12 ( & V_46 -> V_48 ) & V_6 -> V_293 ;
F_13 ( V_48 , & V_46 -> V_48 ) ;
while ( 1 ) {
if ( ( V_289 = F_12 ( & V_46 -> V_294 ) ) == 0xFFFFFFFF ) {
if ( V_497 ) {
V_69 = V_188 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_312 > 100 ) {
V_69 = V_192 ;
break;
}
goto V_498;
}
}
V_160 = (struct V_291 * ) ( V_6 -> V_159 + ( V_289 << 5 ) ) ;
V_252 = F_44 ( V_160 , struct V_138 , V_160 ) ;
V_497 |= ( V_252 == V_496 ) ? 1 : 0 ;
if ( ( V_252 -> V_6 != V_6 ) || ( V_252 -> V_256 != V_285 ) ) {
if ( ( V_252 -> V_256 == V_286 ) || ( V_252 == V_496 ) ) {
F_9 ( V_18 L_39
L_40
, V_6 -> V_19 -> V_20
, V_252 -> V_254 -> V_73 -> V_194
, ( T_8 ) V_252 -> V_254 -> V_73 -> V_172
, V_252 ) ;
V_252 -> V_254 -> V_262 = V_288 << 16 ;
F_105 ( V_252 ) ;
continue;
}
F_9 ( V_18 L_41
L_42
L_43
, V_6 -> V_19 -> V_20
, V_252
, F_112 ( & V_6 -> V_255 ) ) ;
continue;
}
error = ( V_289 & V_295 ) ? true : false ;
F_110 ( V_6 , V_252 , error ) ;
}
return V_69 ;
}
static int F_190 ( struct V_5 * V_6 ,
struct V_138 * V_496 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
struct V_291 * V_160 ;
struct V_138 * V_252 ;
T_6 V_289 , V_497 = 0 , V_312 = 0 ;
int V_359 , V_69 ;
bool error ;
V_499:
V_312 ++ ;
F_13 ( V_296 , V_46 -> V_52 ) ;
while( 1 ) {
V_359 = V_46 -> V_300 ;
V_289 = V_46 -> V_298 [ V_359 ] ;
if ( V_289 == 0 ) {
if ( V_497 ) {
V_69 = V_188 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_312 > 100 ) {
V_69 = V_192 ;
break;
}
goto V_499;
}
}
V_46 -> V_298 [ V_359 ] = 0 ;
V_359 ++ ;
V_359 %= V_297 ;
V_46 -> V_300 = V_359 ;
V_160 = (struct V_291 * ) ( V_6 -> V_159 + ( V_289 << 5 ) ) ;
V_252 = F_44 ( V_160 , struct V_138 , V_160 ) ;
V_497 |= ( V_252 == V_496 ) ? 1 : 0 ;
if ( ( V_252 -> V_6 != V_6 ) || ( V_252 -> V_256 != V_285 ) ) {
if ( ( V_252 -> V_256 == V_286 ) || ( V_252 == V_496 ) ) {
F_9 ( V_18 L_39
L_40
, V_6 -> V_19 -> V_20
, V_252 -> V_254 -> V_73 -> V_194
, ( T_8 ) V_252 -> V_254 -> V_73 -> V_172
, V_252 ) ;
V_252 -> V_254 -> V_262 = V_288 << 16 ;
F_105 ( V_252 ) ;
continue;
}
F_9 ( V_18 L_41
L_42
L_43
, V_6 -> V_19 -> V_20
, V_252
, F_112 ( & V_6 -> V_255 ) ) ;
continue;
}
error = ( V_289 & V_295 ) ? true : false ;
F_110 ( V_6 , V_252 , error ) ;
}
return V_69 ;
}
static int F_191 ( struct V_5 * V_6 ,
struct V_138 * V_496 )
{
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
T_6 V_289 , V_290 ;
struct V_291 * V_160 ;
bool error ;
struct V_138 * V_284 ;
T_6 V_497 = 0 , V_312 = 0 ;
int V_69 ;
V_500:
V_312 ++ ;
while ( 1 ) {
if ( ( F_12 ( & V_46 -> V_101 ) & V_302 ) == 0 ) {
if ( V_497 ) {
V_69 = V_188 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_312 > 100 ) {
V_69 = V_192 ;
break;
}
goto V_500;
}
}
V_289 = F_12 ( & V_46 -> V_303 ) ;
V_290 = ( V_289 & 0xFFFFFFF0 ) ;
V_160 = (struct V_291 * ) ( V_6 -> V_159 + V_290 ) ;
V_284 = F_44 ( V_160 , struct V_138 , V_160 ) ;
V_497 |= ( V_284 == V_496 ) ? 1 : 0 ;
if ( ( V_284 -> V_6 != V_6 ) || ( V_284 -> V_256 != V_285 ) ) {
if ( V_284 -> V_256 == V_286 ) {
F_9 ( V_18 L_39
L_40
, V_6 -> V_19 -> V_20
, V_284 -> V_254 -> V_73 -> V_194
, ( T_8 ) V_284 -> V_254 -> V_73 -> V_172
, V_284 ) ;
V_284 -> V_254 -> V_262 = V_288 << 16 ;
F_105 ( V_284 ) ;
continue;
}
F_9 ( V_18 L_41
L_42
L_43
, V_6 -> V_19 -> V_20
, V_284
, F_112 ( & V_6 -> V_255 ) ) ;
continue;
}
error = ( V_289 & V_304 ) ? true : false ;
F_110 ( V_6 , V_284 , error ) ;
}
return V_69 ;
}
static int F_192 ( struct V_5 * V_6 ,
struct V_138 * V_496 )
{
bool error ;
T_6 V_497 = 0 , V_312 = 0 , V_289 , V_290 ;
int V_69 , V_300 , V_307 , V_306 , V_310 ;
unsigned long V_31 ;
struct V_291 * V_160 ;
struct V_138 * V_284 ;
struct V_60 * V_305 = V_6 -> V_61 ;
V_501:
V_312 ++ ;
while ( 1 ) {
F_107 ( & V_6 -> V_219 , V_31 ) ;
V_306 = V_305 -> V_298 [ 0 ] . V_308 + 1 ;
V_300 = V_305 -> V_300 ;
if ( ( V_306 & 0xFFF ) == ( V_300 & 0xFFF ) ) {
F_108 ( & V_6 -> V_219 , V_31 ) ;
if ( V_497 ) {
V_69 = V_188 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_312 > 40 ) {
V_69 = V_192 ;
break;
}
goto V_501;
}
}
V_310 = V_300 & 0x4000 ;
V_307 = ( V_300 & 0xFFF ) + 1 ;
V_307 %= V_311 ;
V_305 -> V_300 = V_307 ? ( V_307 | V_310 ) :
( ( V_310 ^ 0x4000 ) + 1 ) ;
V_300 = V_305 -> V_300 ;
F_108 ( & V_6 -> V_219 , V_31 ) ;
V_289 = V_305 -> V_298 [ V_300 & 0xFFF ] . V_308 ;
V_290 = ( V_289 & 0xFFFFFFF0 ) ;
V_160 = (struct V_291 * ) ( V_6 -> V_159 +
V_290 ) ;
V_284 = F_44 ( V_160 , struct V_138 ,
V_160 ) ;
V_497 |= ( V_284 == V_496 ) ? 1 : 0 ;
if ( ( V_284 -> V_6 != V_6 ) ||
( V_284 -> V_256 != V_285 ) ) {
if ( V_284 -> V_256 == V_286 ) {
F_15 ( L_44
L_45
L_46
, V_6 -> V_19 -> V_20
, V_284 -> V_254 -> V_73 -> V_194
, ( T_8 ) V_284 -> V_254 -> V_73 -> V_172
, V_284 ) ;
V_284 -> V_254 -> V_262 = V_288 << 16 ;
F_105 ( V_284 ) ;
continue;
}
F_15 ( L_47
L_48
L_49
, V_6 -> V_19 -> V_20
, V_284
, F_112 ( & V_6 -> V_255 ) ) ;
continue;
}
error = ( V_289 & V_304 )
? true : false ;
F_110 ( V_6 , V_284 , error ) ;
}
return V_69 ;
}
static int F_193 ( struct V_5 * V_6 ,
struct V_138 * V_496 )
{
int V_69 = 0 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
V_69 = F_189 ( V_6 , V_496 ) ;
}
break;
case V_8 : {
V_69 = F_190 ( V_6 , V_496 ) ;
}
break;
case V_23 : {
V_69 = F_191 ( V_6 , V_496 ) ;
}
break;
case V_9 :
V_69 = F_192 ( V_6 , V_496 ) ;
break;
}
return V_69 ;
}
static int F_194 ( struct V_5 * V_6 )
{
T_6 V_141 , V_362 ;
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
V_141 = F_195 ( V_71 ) ;
V_362 = F_196 ( V_71 ) ;
V_6 -> V_362 = V_362 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
if ( V_362 != 0 ) {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_502 , \
& V_46 -> V_89 [ 0 ] ) ;
F_13 ( V_362 , & V_46 -> V_89 [ 1 ] ) ;
F_13 ( V_503 , \
& V_46 -> V_65 ) ;
if ( ! F_23 ( V_6 ) ) {
F_9 (KERN_NOTICE L_50set ccb high \
part physical address timeout\nL_51arcmsr%d: cannot set driver mode\nL_52set configL_53arcmsr%d: 'set command Q window' \
timeout \nL_54arcmsr%d: can't set driver mode.\n",
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
pr_notice("arcmsr%d: wait 'start adapter L_55background rebulid'
