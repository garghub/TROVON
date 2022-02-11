static void F_1 ( T_1 * V_1 )
{
V_1 -> V_2 = F_2 ( V_1 -> V_2 ) ;
V_1 -> V_3 = F_2 ( V_1 -> V_3 ) ;
V_1 -> V_4 = F_2 ( V_1 -> V_4 ) ;
V_1 -> V_5 = F_2 ( V_1 -> V_5 ) ;
V_1 -> V_6 . V_7 = F_2 ( V_1 -> V_6 . V_7 ) ;
V_1 -> V_6 . V_8 = F_3 ( V_1 -> V_6 . V_8 ) ;
V_1 -> V_9 = F_2 ( V_1 -> V_9 ) ;
}
static void F_4 ( T_1 * V_1 )
{
V_1 -> V_2 = F_5 ( V_1 -> V_2 ) ;
V_1 -> V_3 = F_5 ( V_1 -> V_3 ) ;
V_1 -> V_4 = F_5 ( V_1 -> V_4 ) ;
V_1 -> V_5 = F_5 ( V_1 -> V_5 ) ;
V_1 -> V_6 . V_7 = F_5 ( V_1 -> V_6 . V_7 ) ;
V_1 -> V_6 . V_8 = F_6 ( V_1 -> V_6 . V_8 ) ;
V_1 -> V_9 = F_5 ( V_1 -> V_9 ) ;
}
static int F_7 ( struct V_10 * V_11 , int V_12 , void * V_13 , int V_3 )
{
struct V_14 V_15 ;
T_2 V_16 ;
T_3 V_17 ;
int V_18 = - V_19 ;
if ( ! V_11 ) {
F_8 ( L_1 , V_20 ) ;
return V_18 ;
}
F_9 ( L_2 ,
V_20 , V_21 -> V_22 , V_12 , V_13 , V_3 ) ;
if ( V_23 == V_24 ) {
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_12 = V_12 ;
V_16 . V_25 = V_13 ;
V_16 . V_3 = V_3 ;
strcpy ( V_15 . V_26 , V_11 -> V_27 ) ;
V_15 . V_28 = ( V_29 ) & V_16 ;
V_18 = F_10 ( V_11 ) ;
if ( V_18 ) {
F_8 ( L_3 , V_20 , V_18 ) ;
return V_18 ;
}
V_17 = F_11 () ;
F_12 ( F_13 () ) ;
V_18 = V_11 -> V_30 -> V_31 ( V_11 , & V_15 , V_32 ) ;
F_12 ( V_17 ) ;
} else {
F_14 ( L_4 , V_20 ) ;
}
return V_18 ;
}
static int F_15 ( struct V_10 * V_11 , char * V_27 , int V_33 )
{
char V_25 [ V_34 ] ;
T_4 V_3 ;
V_33 = F_2 ( V_33 ) ;
V_3 = F_16 ( V_27 , ( char * ) ( & V_33 ) , sizeof( V_33 ) , V_25 , sizeof( V_25 ) ) ;
ASSERT ( V_3 ) ;
return F_7 ( V_11 , V_35 , V_25 , V_3 ) ;
}
static int
F_17 ( struct V_10 * V_11 ,
char * V_36 ,
void * V_37 , int V_38 , void * V_39 , int V_40 )
{
int V_41 ;
V_41 = F_16 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ;
ASSERT ( V_41 ) ;
if ( V_41 == 0 )
return 0 ;
return F_7 ( V_11 , V_35 , V_39 , V_41 ) ;
}
static int
F_18 ( struct V_10 * V_11 ,
char * V_36 ,
void * V_37 , int V_38 , void * V_39 , int V_40 )
{
int V_41 ;
V_41 = F_16 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ;
ASSERT ( V_41 ) ;
return F_7 ( V_11 , V_42 , V_39 , V_40 ) ;
}
static int
F_19 ( struct V_10 * V_11 , char * V_27 , char * V_25 , int V_3 )
{
static char V_43 [ V_44 ] ;
T_4 V_40 ;
V_40 = F_16 ( V_27 , V_25 , V_3 , V_43 , sizeof( V_43 ) ) ;
ASSERT ( V_40 ) ;
return F_7 ( V_11 , V_35 , V_43 , V_40 ) ;
}
static int
F_20 ( struct V_10 * V_11 , char * V_27 , char * V_25 , int V_40 )
{
static char V_43 [ V_44 ] ;
int error ;
T_4 V_3 ;
V_3 = F_16 ( V_27 , NULL , 0 , V_43 , sizeof( V_43 ) ) ;
ASSERT ( V_3 ) ;
error =
F_7 ( V_11 , V_42 , ( void * ) V_43 ,
V_44 ) ;
if ( ! error )
memcpy ( V_25 , V_43 , V_40 ) ;
return error ;
}
static int F_21 ( struct V_10 * V_11 , char * V_27 , int * V_45 )
{
union {
char V_25 [ V_34 ] ;
int V_33 ;
} V_46 ;
int error ;
T_4 V_3 ;
T_4 V_47 ;
V_3 =
F_16 ( V_27 , ( char * ) ( & V_47 ) , 0 , ( char * ) ( & V_46 ) ,
sizeof( V_46 . V_25 ) ) ;
ASSERT ( V_3 ) ;
error = F_7 ( V_11 , V_42 , ( void * ) & V_46 , V_3 ) ;
* V_45 = F_5 ( V_46 . V_33 ) ;
return error ;
}
static int
F_22 ( struct V_10 * V_11 ,
struct V_48 * V_49 , void * V_50 , char * V_51 )
{
T_5 V_52 ;
int error ;
struct V_53 V_54 ;
F_14 ( L_5 , V_11 -> V_27 ) ;
error = F_7 ( V_11 , V_55 , & V_52 , sizeof( V_52 ) ) ;
if ( error )
return error ;
V_52 . V_56 = F_5 ( V_52 . V_56 ) ;
if ( ! V_52 . V_56 )
return 0 ;
memset ( & V_54 , 0 , sizeof( struct V_53 ) ) ;
error = F_7 ( V_11 , V_57 , & V_54 , V_58 ) ;
if ( error ) {
F_8 ( L_6 ,
V_20 , V_52 . V_59 ) ;
return error ;
}
return 0 ;
}
static int
F_23 ( struct V_10 * V_11 ,
struct V_48 * V_49 , char * V_60 , char * V_51 )
{
F_14 ( L_7 , V_11 -> V_27 ) ;
strcpy ( V_60 , L_8 ) ;
return 0 ;
}
static int
F_24 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_61 * V_62 , char * V_51 )
{
int error , V_63 ;
T_4 V_64 = 0 ;
F_14 ( L_9 , V_20 , V_11 -> V_27 ) ;
if ( V_62 -> V_65 == 0 && V_62 -> V_66 < V_67 ) {
V_63 = V_62 -> V_66 ;
} else {
if ( V_62 -> V_65 >= 6 ) {
V_62 -> V_65 -= 6 ;
while ( V_62 -> V_65 -- )
V_62 -> V_66 *= 10 ;
} else if ( V_62 -> V_65 < 6 ) {
while ( V_62 -> V_65 ++ < 6 )
V_62 -> V_66 /= 10 ;
}
if ( V_62 -> V_66 > 4000 && V_62 -> V_66 < 5000 )
V_64 = V_68 ;
V_63 = F_25 ( V_62 -> V_66 , V_64 ) ;
}
V_63 = F_2 ( V_63 ) ;
error = F_7 ( V_11 , V_69 , & V_63 , sizeof( V_63 ) ) ;
if ( error )
return error ;
V_70 . V_71 = V_63 ;
return - V_72 ;
}
static int
F_26 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_61 * V_62 , char * V_51 )
{
T_6 V_73 ;
int error ;
F_14 ( L_10 , V_11 -> V_27 ) ;
error = F_7 ( V_11 , V_74 , & V_73 , sizeof( V_73 ) ) ;
if ( error )
return error ;
V_62 -> V_66 = F_5 ( V_73 . V_75 ) ;
V_62 -> V_65 = F_5 ( 0 ) ;
return 0 ;
}
static int
F_27 ( struct V_10 * V_11 ,
struct V_48 * V_49 , T_7 * V_76 , char * V_51 )
{
int V_77 = 0 , V_78 = 0 , error = 0 ;
F_14 ( L_11 , V_11 -> V_27 ) ;
switch ( * V_76 ) {
case V_79 :
V_77 = V_78 = 1 ;
break;
case V_80 :
case V_81 :
break;
case V_82 :
V_77 = 1 ;
break;
default:
return - V_19 ;
}
V_77 = F_2 ( V_77 ) ;
V_78 = F_2 ( V_78 ) ;
error = F_7 ( V_11 , V_83 , & V_77 , sizeof( V_77 ) ) ;
if ( error )
return error ;
error = F_7 ( V_11 , V_84 , & V_78 , sizeof( V_78 ) ) ;
if ( error )
return error ;
return - V_72 ;
}
static int
F_28 ( struct V_10 * V_11 ,
struct V_48 * V_49 , T_7 * V_76 , char * V_51 )
{
int error , V_77 = 0 , V_78 = 0 ;
F_14 ( L_12 , V_11 -> V_27 ) ;
error = F_7 ( V_11 , V_85 , & V_77 , sizeof( V_77 ) ) ;
if ( error )
return error ;
error = F_7 ( V_11 , V_86 , & V_78 , sizeof( V_78 ) ) ;
if ( error )
return error ;
V_77 = F_5 ( V_77 ) ;
V_78 = F_5 ( V_78 ) ;
* V_76 = V_77 ? V_78 ? V_79 : V_82 : V_80 ;
return 0 ;
}
static int
F_29 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_87 * V_88 , char * V_51 )
{
struct V_89 * V_90 = (struct V_89 * ) V_51 ;
T_8 * V_91 ;
T_9 V_92 ;
T_10 * V_93 ;
int error , V_94 , V_95 ;
T_4 V_96 ;
int V_97 ;
int V_98 = 0 , V_99 = 0 , V_100 = 0 ;
T_6 V_73 ;
T_11 V_101 = 0 ;
T_12 V_102 [ 4 ] [ 8 ] = { { 13 , 26 , 39 , 52 , 78 , 104 , 117 , 130 } ,
{ 14 , 29 , 43 , 58 , 87 , 116 , 130 , 144 } ,
{ 27 , 54 , 81 , 108 , 162 , 216 , 243 , 270 } ,
{ 30 , 60 , 90 , 120 , 180 , 240 , 270 , 300 }
} ;
F_14 ( L_13 , V_11 -> V_27 ) ;
if ( ! V_51 )
return - V_19 ;
V_93 = F_30 ( ( V_67 + 1 ) * 4 , V_103 ) ;
if ( ! V_93 ) {
F_8 ( L_14 ) ;
return - V_104 ;
}
V_91 = ( T_8 * ) V_93 ;
V_88 -> V_105 = sizeof( struct V_89 ) ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_91 -> V_106 = F_2 ( V_67 ) ;
error = F_7 ( V_11 , V_107 , V_93 ,
( V_67 + 1 ) * 4 ) ;
if ( error ) {
F_31 ( V_93 ) ;
return error ;
}
for ( V_94 = 0 ; V_94 < F_5 ( V_91 -> V_106 ) && V_94 < V_108 ;
V_94 ++ ) {
V_90 -> V_109 [ V_94 ] . V_94 = F_5 ( V_91 -> V_110 [ V_94 ] ) ;
V_96 = F_5 ( V_91 -> V_110 [ V_94 ] ) ;
if ( V_96 <= V_111 ) {
V_90 -> V_109 [ V_94 ] . V_66 = F_32 ( V_96 ) ;
} else {
V_90 -> V_109 [ V_94 ] . V_66 = F_33 (
V_112 / 2 , V_96 ) ;
}
V_90 -> V_109 [ V_94 ] . V_65 = 6 ;
}
V_90 -> V_113 = V_90 -> V_114 = V_94 ;
V_90 -> V_115 . V_116 = 5 ;
V_90 -> V_115 . V_117 = 0x100 - 200 ;
V_90 -> V_115 . V_118 = 0x100 - 200 ;
V_90 -> V_119 = 65535 ;
#if V_120 > 11
V_90 -> V_121 . V_116 = 3 ;
V_90 -> V_121 . V_117 = 0x100 + V_122 ;
V_90 -> V_121 . V_118 = 0x100 - 75 ;
#endif
error = F_7 ( V_11 , V_123 , & V_92 ,
sizeof( V_92 ) ) ;
if ( error ) {
F_31 ( V_93 ) ;
return error ;
}
V_92 . V_106 = F_5 ( V_92 . V_106 ) ;
V_90 -> V_124 = V_92 . V_106 ;
for ( V_94 = 0 ; V_94 < V_92 . V_106 && V_94 < V_125 ; V_94 ++ )
V_90 -> V_126 [ V_94 ] = ( V_92 . V_127 [ V_94 ] & 0x7f ) * 500000 ;
F_21 ( V_11 , L_15 , & V_100 ) ;
F_7 ( V_11 , V_128 , & V_97 , sizeof( V_97 ) ) ;
if ( V_100 == 1 && V_97 == V_129 ) {
F_21 ( V_11 , L_16 , & V_98 ) ;
F_21 ( V_11 , L_17 , & V_99 ) ;
F_7 ( V_11 , V_74 , & V_73 ,
sizeof( T_6 ) ) ;
V_73 . V_75 = F_5 ( V_73 . V_75 ) ;
if ( V_98 == 0 || ( V_98 == 2 && V_73 . V_75 <= 14 ) ) {
if ( V_99 == 0 )
V_101 = 0 ;
else
V_101 = 1 ;
}
if ( V_98 == 1 || ( V_98 == 2 && V_73 . V_75 >= 36 ) ) {
if ( V_99 == 0 )
V_101 = 2 ;
else
V_101 = 3 ;
}
V_90 -> V_124 += 8 ;
for ( V_95 = 0 ; V_94 < V_90 -> V_124 ; V_95 ++ , V_94 ++ ) {
V_90 -> V_126 [ V_94 ] =
( V_102 [ V_101 ] [ V_95 ] ) * 500000 ;
}
}
error = F_7 ( V_11 , V_128 , & V_94 , sizeof( V_94 ) ) ;
if ( error ) {
F_31 ( V_93 ) ;
return error ;
}
V_94 = F_5 ( V_94 ) ;
if ( V_94 == V_130 )
V_90 -> V_131 = 24000000 ;
else
V_90 -> V_131 = 1500000 ;
V_90 -> V_132 = 0 ;
V_90 -> V_133 = 2347 ;
V_90 -> V_134 = 256 ;
V_90 -> V_135 = 2346 ;
V_90 -> V_136 = V_137 ;
V_90 -> V_138 = 4 ;
V_90 -> V_139 [ 0 ] = V_140 ;
V_90 -> V_139 [ 1 ] = V_141 ;
#if V_120 > 17
V_90 -> V_139 [ 2 ] = V_142 ;
#else
V_90 -> V_139 [ 2 ] = 0 ;
#endif
V_90 -> V_139 [ 3 ] = V_143 ;
V_90 -> V_144 = 0 ;
V_90 -> V_145 = 0 ;
V_90 -> V_146 = 0 ;
V_90 -> V_147 = 0 ;
V_90 -> V_148 = 0 ;
V_90 -> V_149 = 0 ;
V_90 -> V_150 = 2 ;
V_90 -> V_151 [ 0 ] = 1 ;
V_90 -> V_151 [ 1 ] = 255 ;
V_90 -> V_152 = V_153 ;
#if V_120 > 10
V_90 -> V_154 = V_120 ;
V_90 -> V_155 = 19 ;
V_90 -> V_156 = V_157 ;
V_90 -> V_158 = V_157 ;
V_90 -> V_159 = 0 ;
V_90 -> V_160 = 1 ;
V_90 -> V_161 = 255 ;
V_90 -> V_162 = 0 ;
V_90 -> V_163 = 0 ;
#endif
#if V_120 > 17
V_90 -> V_164 = V_165 ;
V_90 -> V_164 |= V_166 ;
V_90 -> V_164 |= V_167 ;
V_90 -> V_164 |= V_168 ;
F_34 ( V_90 -> V_169 ) ;
F_35 ( V_90 -> V_169 , V_170 ) ;
F_35 ( V_90 -> V_169 , V_171 ) ;
F_35 ( V_90 -> V_169 , V_172 ) ;
F_35 ( V_90 -> V_169 , V_173 ) ;
F_35 ( V_90 -> V_169 , V_174 ) ;
#endif
F_31 ( V_93 ) ;
return 0 ;
}
static int F_36 ( int V_175 )
{
if ( V_175 <= V_176 )
return 0 ;
else if ( V_175 <= V_177 )
return 1 ;
else if ( V_175 <= V_178 )
return 2 ;
else if ( V_175 <= V_122 )
return 3 ;
else if ( V_175 <= V_179 )
return 4 ;
else
return 5 ;
}
static int
F_37 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_87 * V_88 , char * V_51 )
{
T_13 * V_180 = * ( T_13 * * ) F_38 ( V_11 ) ;
struct V_53 * V_181 = (struct V_53 * ) V_51 ;
int V_94 ;
F_14 ( L_18 , V_11 -> V_27 ) ;
if ( ! V_51 )
return - V_19 ;
V_180 -> V_182 = F_39 ( int , F_40 ( V_180 -> V_183 ) , V_88 -> V_105 ) ;
for ( V_94 = 0 ; V_94 < V_180 -> V_182 ; V_94 ++ )
memcpy ( V_180 -> V_183 [ V_94 ] , V_181 [ V_94 ] . V_184 , V_58 ) ;
memset ( V_180 -> V_185 , 0 , sizeof( V_180 -> V_185 ) ) ;
return 0 ;
}
static int
F_41 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_87 * V_88 , char * V_51 )
{
T_13 * V_180 = * ( T_13 * * ) F_38 ( V_11 ) ;
struct V_53 * V_181 = (struct V_53 * ) V_51 ;
struct V_186 * V_116 = (struct V_186 * ) & V_181 [ V_180 -> V_182 ] ;
int V_94 ;
F_14 ( L_19 , V_11 -> V_27 ) ;
if ( ! V_51 )
return - V_19 ;
V_88 -> V_105 = V_180 -> V_182 ;
for ( V_94 = 0 ; V_94 < V_180 -> V_182 ; V_94 ++ ) {
memcpy ( V_181 [ V_94 ] . V_184 , V_180 -> V_183 [ V_94 ] , V_58 ) ;
V_181 [ V_94 ] . V_187 = V_188 ;
memcpy ( & V_116 [ V_94 ] , & V_180 -> V_185 [ V_94 ] , sizeof( struct V_186 ) ) ;
V_180 -> V_185 [ V_94 ] . V_189 = 0 ;
}
return 0 ;
}
static int
F_42 ( int V_96 , T_14 * V_190 ,
int * V_191 )
{
T_15 V_192 = 0 ;
if ( V_96 != 0 ) {
V_190 -> V_193 . V_194 = 1 ;
V_190 -> V_193 . V_195 [ 0 ] = V_96 ;
if ( V_190 -> V_193 . V_195 [ 0 ] )
V_192 |= V_196 ;
else
V_192 |= V_197 ;
V_192 |= V_198 ;
V_192 |= V_199 ;
* V_191 += V_200 +
V_190 -> V_193 . V_194 * sizeof( T_15 ) ;
V_190 -> V_193 . V_195 [ 0 ] &= V_201 ;
V_190 -> V_193 . V_195 [ 0 ] |= V_192 ;
V_190 -> V_193 . V_195 [ 0 ] =
F_3 ( V_190 -> V_193 . V_195 [ 0 ] ) ;
V_190 -> V_193 . V_194 =
F_2 ( V_190 -> V_193 . V_194 ) ;
F_14 ( L_20 ,
V_20 , V_190 -> V_193 . V_195 [ 0 ] ) ;
}
return 1 ;
}
static int
F_43 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_53 * V_202 , char * V_51 )
{
int error = - V_19 ;
T_14 V_190 ;
int V_191 ;
F_14 ( L_21 , V_11 -> V_27 ) ;
if ( V_202 -> V_187 != V_203 ) {
F_8 ( L_22 ) ;
return - V_19 ;
}
if ( F_44 ( V_202 -> V_184 ) ||
F_45 ( V_202 -> V_184 ) ) {
T_16 V_204 ;
memset ( & V_204 , 0 , sizeof( T_16 ) ) ;
( void ) F_7 ( V_11 , V_205 , & V_204 ,
sizeof( T_16 ) ) ;
return 0 ;
}
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
V_191 = sizeof( V_190 . V_52 ) ;
memcpy ( V_190 . V_52 . V_59 , V_206 . V_59 , V_206 . V_56 ) ;
V_190 . V_52 . V_56 = F_2 ( V_206 . V_56 ) ;
memcpy ( & V_190 . V_193 . V_54 , V_202 -> V_184 , V_58 ) ;
F_14 ( L_23 ,
V_20 , V_70 . V_71 ) ;
F_42 ( V_70 . V_71 , & V_190 ,
& V_191 ) ;
error = F_7 ( V_11 , V_207 , & V_190 ,
V_191 ) ;
if ( error ) {
F_8 ( L_24 , V_20 , error ) ;
}
if ( V_206 . V_56 ) {
F_14 ( L_25 ,
V_20 , V_206 . V_59 , V_202 -> V_184 ,
V_70 . V_71 ) ;
}
memset ( & V_206 , 0 , sizeof( V_206 ) ) ;
return 0 ;
}
static int
F_46 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_53 * V_202 , char * V_51 )
{
F_14 ( L_26 , V_11 -> V_27 ) ;
V_202 -> V_187 = V_203 ;
memset ( V_202 -> V_184 , 0 , V_58 ) ;
( void ) F_7 ( V_11 , V_208 , V_202 -> V_184 , V_58 ) ;
return 0 ;
}
static int
F_47 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_53 * V_202 , char * V_51 )
{
struct V_209 * V_210 ;
T_16 V_204 ;
int error = - V_19 ;
F_14 ( L_27 , V_11 -> V_27 ) ;
V_210 = (struct V_209 * ) V_51 ;
if ( V_210 == NULL ) {
F_8 ( L_28 ) ;
return error ;
}
V_204 . V_33 = V_210 -> V_211 ;
memcpy ( & V_204 . V_212 , & V_210 -> V_181 . V_184 , V_58 ) ;
if ( V_210 -> V_12 == V_213 ) {
V_204 . V_33 = F_2 ( V_204 . V_33 ) ;
error =
F_7 ( V_11 , V_205 , & V_204 ,
sizeof( T_16 ) ) ;
} else if ( V_210 -> V_12 == V_214 ) {
V_204 . V_33 = F_2 ( V_204 . V_33 ) ;
error =
F_7 ( V_11 , V_215 ,
& V_204 , sizeof( T_16 ) ) ;
} else {
F_8 ( L_28 ) ;
return error ;
}
return error ;
}
static int
F_48 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_87 * V_88 , char * V_51 )
{
T_17 * V_91 ;
struct V_53 * V_181 = (struct V_53 * ) V_51 ;
struct V_186 V_116 [ V_216 ] ;
T_18 * V_217 = NULL ;
int error , V_94 ;
T_4 V_40 = V_88 -> V_105 ;
F_14 ( L_29 , V_11 -> V_27 ) ;
if ( ! V_51 )
return - V_19 ;
V_91 = F_49 ( V_40 , V_103 ) ;
if ( ! V_91 )
return - V_104 ;
V_91 -> V_40 = F_2 ( V_40 ) ;
error = F_7 ( V_11 , V_218 , V_91 , V_40 ) ;
if ( error ) {
F_8 ( L_30 , __LINE__ , error ) ;
F_31 ( V_91 ) ;
return error ;
}
V_91 -> V_40 = F_5 ( V_91 -> V_40 ) ;
V_91 -> V_219 = F_5 ( V_91 -> V_219 ) ;
V_91 -> V_106 = F_5 ( V_91 -> V_106 ) ;
if ( V_91 -> V_219 != V_220 ) {
F_8 ( L_31 ,
V_20 , V_91 -> V_219 ) ;
F_31 ( V_91 ) ;
return - V_19 ;
}
for ( V_94 = 0 , V_88 -> V_105 = 0 ;
V_94 < V_91 -> V_106 && V_88 -> V_105 < V_216 ; V_94 ++ ) {
V_217 = V_217 ? ( T_18 * ) ( ( unsigned long ) V_217 +
F_5 ( V_217 -> V_105 ) ) : V_91 ->
V_221 ;
ASSERT ( ( ( unsigned long ) V_217 + F_5 ( V_217 -> V_105 ) ) <=
( ( unsigned long ) V_91 + V_40 ) ) ;
if ( ! ( F_6 ( V_217 -> V_222 ) & V_223 ) )
continue;
memcpy ( V_181 [ V_88 -> V_105 ] . V_184 , & V_217 -> V_224 , V_58 ) ;
V_181 [ V_88 -> V_105 ] . V_187 = V_203 ;
V_116 [ V_88 -> V_105 ] . V_116 = F_36 ( F_6 ( V_217 -> V_225 ) ) ;
V_116 [ V_88 -> V_105 ] . V_117 = 0x100 + F_6 ( V_217 -> V_225 ) ;
V_116 [ V_88 -> V_105 ] . V_118 = 0x100 + V_217 -> V_226 ;
#if V_120 > 18
V_116 [ V_88 -> V_105 ] . V_189 = V_227 | V_228 ;
#else
V_116 [ V_88 -> V_105 ] . V_189 = 7 ;
#endif
V_88 -> V_105 ++ ;
}
F_31 ( V_91 ) ;
if ( V_88 -> V_105 ) {
memcpy ( & V_181 [ V_88 -> V_105 ] , V_116 ,
sizeof( struct V_186 ) * V_88 -> V_105 ) ;
V_88 -> V_5 = 1 ;
}
return 0 ;
}
static int
F_50 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_87 * V_88 , char * V_51 )
{
T_17 * V_91 ;
T_19 * V_25 ;
T_20 * V_229 = V_230 ;
struct V_53 * V_181 = (struct V_53 * ) V_51 ;
struct V_186 V_116 [ V_216 ] ;
T_18 * V_217 = NULL ;
int V_94 ;
F_14 ( L_29 , V_11 -> V_27 ) ;
if ( ! V_51 )
return - V_19 ;
if ( ( ! V_229 ) || ( ! V_229 -> V_231 ) ) {
F_8 ( L_32 , V_20 ) ;
return 0 ;
}
V_25 = V_229 -> V_232 ;
while ( V_25 ) {
V_91 = & ( ( V_233 * ) V_25 -> V_234 ) -> V_235 ;
if ( V_91 -> V_219 != V_220 ) {
F_8 ( L_31 ,
V_20 , V_91 -> V_219 ) ;
return - V_19 ;
}
V_217 = NULL ;
for ( V_94 = 0 , V_88 -> V_105 = 0 ;
V_94 < V_91 -> V_106 && V_88 -> V_105 < V_216 ; V_94 ++ ) {
V_217 = V_217 ? ( T_18 * ) ( ( unsigned long ) V_217 +
F_5 ( V_217 -> V_105 ) ) :
V_91 -> V_221 ;
ASSERT ( ( ( unsigned long ) V_217 + F_5 ( V_217 -> V_105 ) ) <=
( ( unsigned long ) V_91 + V_236 ) ) ;
if ( ! ( F_6 ( V_217 -> V_222 ) &
V_223 ) )
continue;
memcpy ( V_181 [ V_88 -> V_105 ] . V_184 , & V_217 -> V_224 ,
V_58 ) ;
V_181 [ V_88 -> V_105 ] . V_187 = V_203 ;
V_116 [ V_88 -> V_105 ] . V_116 =
F_36 ( F_6 ( V_217 -> V_225 ) ) ;
V_116 [ V_88 -> V_105 ] . V_117 = 0x100 +
F_6 ( V_217 -> V_225 ) ;
V_116 [ V_88 -> V_105 ] . V_118 = 0x100 + V_217 -> V_226 ;
#if V_120 > 18
V_116 [ V_88 -> V_105 ] . V_189 =
V_227 | V_228 ;
#else
V_116 [ V_88 -> V_105 ] . V_189 = 7 ;
#endif
V_88 -> V_105 ++ ;
}
V_25 = V_25 -> V_237 ;
}
if ( V_88 -> V_105 ) {
memcpy ( & V_181 [ V_88 -> V_105 ] , V_116 ,
sizeof( struct V_186 ) * V_88 -> V_105 ) ;
V_88 -> V_5 = 1 ;
}
return 0 ;
}
static int F_51 ( T_21 * V_193 , T_5 * V_52 )
{
int V_238 = 0 ;
memcpy ( V_193 -> V_54 , V_239 , V_58 ) ;
V_193 -> V_240 = V_241 ;
V_193 -> V_242 = 0 ;
V_193 -> V_243 = - 1 ;
V_193 -> V_244 = - 1 ;
V_193 -> V_245 = - 1 ;
V_193 -> V_246 = - 1 ;
V_193 -> V_247 = 0 ;
V_193 -> V_243 = F_2 ( V_193 -> V_243 ) ;
V_193 -> V_244 = F_2 ( V_193 -> V_244 ) ;
V_193 -> V_245 = F_2 ( V_193 -> V_245 ) ;
V_193 -> V_246 = F_2 ( V_193 -> V_246 ) ;
if ( V_52 && V_52 -> V_56 )
memcpy ( & V_193 -> V_52 , V_52 , sizeof( T_5 ) ) ;
return V_238 ;
}
static int F_52 ( T_20 * V_229 , T_5 * V_52 , T_12 V_248 )
{
int V_238 = 0 ;
V_229 -> V_249 -> V_219 = F_2 ( V_250 ) ;
V_229 -> V_249 -> V_248 = F_3 ( V_248 ) ;
V_229 -> V_249 -> V_251 = F_3 ( 0 ) ;
F_53 ( L_33 ,
V_20 , V_229 -> V_249 -> V_193 . V_243 ) ;
F_53 ( L_34 ,
V_229 -> V_249 -> V_193 . V_244 ) ;
F_53 ( L_35 ,
V_229 -> V_249 -> V_193 . V_245 ) ;
F_53 ( L_36 , V_229 -> V_249 -> V_193 . V_246 ) ;
F_53 ( L_37 , V_229 -> V_249 -> V_193 . V_242 ) ;
F_53 ( L_38 , V_229 -> V_249 -> V_193 . V_240 ) ;
( void ) F_17 ( V_229 -> V_11 , L_39 , V_229 -> V_249 ,
V_229 -> V_252 , V_229 -> V_43 ,
sizeof( V_229 -> V_43 ) ) ;
return V_238 ;
}
static void F_54 ( unsigned long V_253 )
{
T_20 * V_229 = ( T_20 * ) V_253 ;
if ( V_229 ) {
V_229 -> V_254 = 0 ;
if ( V_229 -> V_255 != V_256 ) {
F_14 ( L_40 ) ;
F_55 ( & V_229 -> V_257 ) ;
}
}
}
static void F_56 ( struct V_10 * V_11 )
{
char V_258 [ V_259 ] ;
char V_260 [ V_259 + 12 ] ;
F_18 ( V_11 , L_41 , L_42 , 0 , V_260 , sizeof( V_260 ) ) ;
memcpy ( V_258 , V_260 , V_259 ) ;
F_57 ( V_258 , V_261 ) ;
F_17 ( V_11 , L_41 , V_258 , V_259 ,
V_260 , sizeof( V_260 ) ) ;
}
static T_22 F_58 ( T_20 * V_229 )
{
T_19 * V_25 ;
T_19 * V_262 ;
V_233 * V_263 ;
V_233 V_91 ;
T_17 * V_235 ;
T_22 V_264 ;
int V_265 = 0 ;
F_59 () ;
if ( V_229 -> V_266 ) {
V_25 = V_229 -> V_266 ;
V_229 -> V_266 = V_25 -> V_237 ;
} else {
V_25 = F_30 ( sizeof( T_19 ) , V_103 ) ;
if ( ! V_25 ) {
F_8 ( L_43 ,
V_20 ) ;
F_60 () ;
return V_267 ;
}
V_25 -> V_237 = NULL ;
if ( ! V_229 -> V_232 )
V_229 -> V_232 = V_25 ;
else {
V_262 = V_229 -> V_232 ;
while ( V_262 -> V_237 ) {
V_262 = V_262 -> V_237 ;
}
V_262 -> V_237 = V_25 ;
}
}
memset ( V_25 -> V_234 , 0 , V_236 ) ;
V_263 = ( V_233 * ) V_25 -> V_234 ;
V_235 = & V_263 -> V_235 ;
V_235 -> V_40 = V_268 ;
V_235 -> V_219 = 0 ;
V_235 -> V_106 = 0 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_235 . V_40 = F_2 ( V_236 ) ;
V_265 = F_18 ( V_229 -> V_11 ,
L_44 ,
& V_91 ,
V_268 ,
V_25 -> V_234 , V_236 ) ;
if ( V_265 == 0 ) {
V_235 -> V_40 = F_5 ( V_235 -> V_40 ) ;
V_235 -> V_219 = F_5 ( V_235 -> V_219 ) ;
V_235 -> V_106 = F_5 ( V_235 -> V_106 ) ;
F_14 ( L_45 , V_235 -> V_106 ) ;
F_14 ( L_46 , V_235 -> V_40 ) ;
V_264 = F_5 ( V_263 -> V_264 ) ;
} else {
F_8 ( L_47 , V_20 , V_265 ) ;
V_264 = V_267 ;
}
F_60 () ;
return V_264 ;
}
static void F_61 ( T_20 * V_229 )
{
F_14 ( L_48 ,
V_20 , V_269 . V_59 ) ;
F_62 () ;
( void ) F_7 ( V_229 -> V_11 , V_270 , & V_269 ,
sizeof( V_269 ) ) ;
F_63 () ;
}
static void F_64 ( T_20 * V_229 )
{
#ifndef F_65
union V_271 V_272 ;
memset ( & V_272 , 0 , sizeof( V_272 ) ) ;
F_66 ( V_229 -> V_11 , V_171 , & V_272 , NULL ) ;
F_14 ( L_49 ) ;
#endif
}
static int F_67 ( void * V_253 )
{
T_22 V_264 ;
T_20 * V_229 = ( T_20 * ) V_253 ;
static bool V_273 = false ;
F_68 ( V_274 ) ;
V_264 = V_275 ;
while ( F_69 ( & V_229 -> V_257 ) == 0 ) {
if ( F_70 () )
break;
if ( V_229 -> V_254 ) {
F_71 ( & V_229 -> V_276 ) ;
V_229 -> V_254 = 0 ;
}
F_62 () ;
V_264 = F_58 ( V_229 ) ;
F_63 () ;
if ( V_277 && ( V_273 == true ) ) {
F_14 ( L_50 ,
V_20 , V_264 ) ;
F_64 ( V_229 ) ;
V_273 = false ;
V_264 = - 1 ;
}
switch ( V_264 ) {
case V_275 :
F_14 ( L_51 ) ;
F_62 () ;
F_52 ( V_229 , NULL , V_278 ) ;
F_63 () ;
F_72 ( & V_229 -> V_276 ,
V_279 + V_229 -> V_280 * V_281 / 1000 ) ;
V_229 -> V_254 = 1 ;
break;
case V_282 :
F_14 ( L_52 ) ;
V_229 -> V_255 = V_256 ;
F_64 ( V_229 ) ;
break;
case V_283 :
F_14 ( L_53 ) ;
F_72 ( & V_229 -> V_276 ,
V_279 + V_229 -> V_280 * V_281 / 1000 ) ;
V_229 -> V_254 = 1 ;
break;
case V_284 :
F_14 ( L_54 ) ;
V_229 -> V_255 = V_256 ;
if ( V_277 == 0 )
F_64 ( V_229 ) ;
else {
V_273 = true ;
F_61 ( V_229 ) ;
}
break;
case V_267 :
F_14 ( L_55 ) ;
V_229 -> V_255 = V_256 ;
break;
default:
F_14 ( L_56 ,
V_264 ) ;
break;
}
}
if ( V_229 -> V_254 ) {
F_71 ( & V_229 -> V_276 ) ;
V_229 -> V_254 = 0 ;
}
return 0 ;
}
static int
F_73 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
union V_271 * V_272 , char * V_51 )
{
int error ;
F_14 ( L_57 , V_20 , V_11 -> V_27 ) ;
V_285 = false ;
#if F_74 ( V_286 )
F_8 ( L_58 , V_20 ) ;
return - V_19 ;
#endif
if ( V_23 == V_287 )
return 0 ;
memset ( & V_269 , 0 , sizeof( V_269 ) ) ;
#ifndef F_75
V_277 = 0 ;
#endif
#if V_120 > 17
if ( V_272 -> V_253 . V_105 == sizeof( struct V_288 ) ) {
if ( V_272 -> V_253 . V_5 & V_289 ) {
struct V_288 * V_290 = (struct V_288 * ) V_51 ;
if ( V_277 ) {
F_14 ( L_59 ,
V_20 , V_290 -> V_291 ) ;
return - V_292 ;
} else {
V_269 . V_56 = F_39 ( V_293 ,
sizeof( V_269 . V_59 ) ,
V_290 -> V_294 ) ;
memcpy ( V_269 . V_59 , V_290 -> V_291 ,
V_269 . V_56 ) ;
V_269 . V_56 =
F_2 ( V_269 . V_56 ) ;
V_277 = 1 ;
F_14 ( L_60 ,
V_269 . V_59 ,
V_269 . V_56 ) ;
}
}
}
#endif
error = F_7 ( V_11 , V_270 , & V_269 ,
sizeof( V_269 ) ) ;
if ( error ) {
F_14 ( L_61 ,
V_269 . V_59 , error ) ;
V_277 = 0 ;
return - V_292 ;
}
return 0 ;
}
int F_76 ( struct V_10 * V_11 , T_4 V_295 )
{
T_5 V_52 ;
T_20 * V_229 = V_230 ;
if ( V_295 )
F_62 () ;
F_56 ( V_11 ) ;
F_14 ( L_62 ) ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_229 -> V_266 = V_229 -> V_232 ;
V_229 -> V_255 = V_296 ;
memset ( & V_229 -> V_249 -> V_193 , 0 ,
V_229 -> V_252 ) ;
F_51 ( & V_229 -> V_249 -> V_193 , & V_52 ) ;
F_52 ( V_229 , & V_52 , V_297 ) ;
if ( V_295 )
F_63 () ;
F_72 ( & V_229 -> V_276 , V_279 + V_229 -> V_280 * V_281 / 1000 ) ;
V_229 -> V_254 = 1 ;
return 0 ;
}
static int
F_77 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
union V_271 * V_272 , char * V_51 )
{
T_5 V_52 ;
T_20 * V_229 = V_230 ;
F_14 ( L_63 , V_11 -> V_27 ) ;
#if F_74 ( V_286 )
F_8 ( L_58 , V_20 ) ;
return - V_19 ;
#endif
if ( V_23 == V_287 ) {
F_14 ( L_64 , V_20 ) ;
return 0 ;
}
#ifdef F_78
if ( F_79 ( V_11 ) ) {
F_8 ( L_65 , V_20 ) ;
}
#endif
if ( ( ! V_229 ) || ( ! V_229 -> V_231 ) )
return F_73 ( V_11 , V_49 , V_272 , V_51 ) ;
if ( V_277 ) {
F_14 ( L_66 ,
V_20 ) ;
return - V_292 ;
}
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
#if V_120 > 17
if ( V_272 -> V_253 . V_105 == sizeof( struct V_288 ) ) {
if ( V_272 -> V_253 . V_5 & V_289 ) {
struct V_288 * V_290 = (struct V_288 * ) V_51 ;
V_52 . V_56 = F_39 ( V_293 , sizeof( V_52 . V_59 ) ,
V_290 -> V_294 ) ;
memcpy ( V_52 . V_59 , V_290 -> V_291 , V_52 . V_56 ) ;
V_52 . V_56 = F_2 ( V_52 . V_56 ) ;
} else {
V_277 = 0 ;
if ( V_229 -> V_255 == V_296 ) {
F_14 ( L_67 ,
V_20 ) ;
return 0 ;
}
}
}
#endif
F_76 ( V_11 , 0 ) ;
return 0 ;
}
static bool F_80 ( T_11 * * V_298 , T_11 * * V_299 , int * V_300 )
{
T_11 * V_301 = * V_298 ;
if ( ( V_301 [ 1 ] >= 6 ) &&
! memcmp ( ( const void * ) & V_301 [ 2 ] , ( const void * ) ( V_302 L_68 ) , 4 ) ) {
return true ;
}
V_301 += V_301 [ 1 ] + 2 ;
* V_300 -= ( int ) ( V_301 - * V_299 ) ;
* V_299 = V_301 ;
return false ;
}
static bool F_81 ( T_11 * * V_303 , T_11 * * V_299 , int * V_300 )
{
T_11 * V_301 = * V_303 ;
if ( ( V_301 [ 1 ] >= 4 ) &&
! memcmp ( ( const void * ) & V_301 [ 2 ] , ( const void * ) ( V_302 L_69 ) , 4 ) ) {
return true ;
}
V_301 += V_301 [ 1 ] + 2 ;
* V_300 -= ( int ) ( V_301 - * V_299 ) ;
* V_299 = V_301 ;
return false ;
}
static int
F_82 ( char * * V_304 , char * V_305 ,
struct V_48 * V_49 , T_18 * V_217 )
{
#if V_120 > 17
struct V_306 V_307 ;
char * V_308 ;
V_308 = * V_304 ;
if ( V_217 -> V_309 ) {
T_23 * V_301 ;
T_11 * V_262 = ( ( T_11 * ) V_217 ) + sizeof( T_18 ) ;
int V_310 = V_217 -> V_309 ;
V_301 = F_83 ( V_262 , V_310 , V_311 ) ;
if ( V_301 ) {
V_307 . V_12 = V_312 ;
V_307 . V_313 . V_253 . V_105 = V_301 -> V_3 + 2 ;
V_308 =
F_84 ( V_49 , V_308 , V_305 , & V_307 ,
( char * ) V_301 ) ;
}
V_262 = ( ( T_11 * ) V_217 ) + sizeof( T_18 ) ;
while ( ( V_301 = F_83 ( V_262 , V_310 , V_314 ) ) ) {
if ( F_81 ( ( ( T_11 * * ) & V_301 ) , & V_262 , & V_310 ) ) {
V_307 . V_12 = V_312 ;
V_307 . V_313 . V_253 . V_105 = V_301 -> V_3 + 2 ;
V_308 =
F_84 ( V_49 , V_308 , V_305 , & V_307 ,
( char * ) V_301 ) ;
break;
}
}
V_262 = ( ( T_11 * ) V_217 ) + sizeof( T_18 ) ;
V_310 = V_217 -> V_309 ;
while ( ( V_301 = F_83 ( V_262 , V_310 , V_314 ) ) ) {
if ( F_80 ( ( ( T_11 * * ) & V_301 ) , & V_262 , & V_310 ) ) {
V_307 . V_12 = V_312 ;
V_307 . V_313 . V_253 . V_105 = V_301 -> V_3 + 2 ;
V_308 =
F_84 ( V_49 , V_308 , V_305 , & V_307 ,
( char * ) V_301 ) ;
break;
}
}
* V_304 = V_308 ;
}
#endif
return 0 ;
}
static T_4
F_85 ( T_17 * V_91 ,
struct V_48 * V_49 , char * V_51 , short V_315 )
{
int V_94 , V_316 ;
struct V_306 V_307 ;
T_18 * V_217 = NULL ;
char * V_308 = V_51 , * V_305 = V_51 + V_315 - V_317 , * V_318 ;
int V_18 = 0 ;
ASSERT ( V_91 ) ;
for ( V_94 = 0 ; V_94 < V_91 -> V_106 && V_94 < V_216 ; V_94 ++ ) {
if ( V_91 -> V_219 != V_220 ) {
F_8 ( L_31 ,
V_20 , V_91 -> V_219 ) ;
return V_18 ;
}
V_217 = V_217 ? ( T_18 * ) ( ( unsigned long ) V_217 +
F_5 ( V_217 -> V_105 ) ) : V_91 ->
V_221 ;
F_14 ( L_70 , V_20 , V_217 -> V_59 ) ;
V_307 . V_12 = V_170 ;
V_307 . V_313 . V_319 . V_187 = V_203 ;
memcpy ( V_307 . V_313 . V_319 . V_184 , & V_217 -> V_224 , V_58 ) ;
V_308 =
F_86 ( V_49 , V_308 , V_305 , & V_307 ,
V_320 ) ;
V_307 . V_313 . V_253 . V_105 = F_5 ( V_217 -> V_56 ) ;
V_307 . V_12 = V_321 ;
V_307 . V_313 . V_253 . V_5 = 1 ;
V_308 = F_84 ( V_49 , V_308 , V_305 , & V_307 , V_217 -> V_59 ) ;
if ( F_6 ( V_217 -> V_222 ) & ( V_223 |
V_322 ) ) {
V_307 . V_12 = V_323 ;
if ( F_6 ( V_217 -> V_222 ) & V_223 )
V_307 . V_313 . V_324 = V_82 ;
else
V_307 . V_313 . V_324 = V_80 ;
V_308 =
F_86 ( V_49 , V_308 , V_305 , & V_307 ,
V_325 ) ;
}
V_307 . V_12 = V_326 ;
if ( F_87 ( V_217 -> V_192 ) <= V_111 )
V_307 . V_313 . V_109 . V_66 = F_32 (
F_87 ( V_217 -> V_192 ) ) ;
else
V_307 . V_313 . V_109 . V_66 = F_33 (
V_112 / 2 ,
F_87 ( V_217 -> V_192 ) ) ;
V_307 . V_313 . V_109 . V_65 = 6 ;
V_308 =
F_86 ( V_49 , V_308 , V_305 , & V_307 ,
V_327 ) ;
V_307 . V_12 = V_328 ;
V_307 . V_313 . V_116 . V_116 = F_36 ( F_6 ( V_217 -> V_225 ) ) ;
V_307 . V_313 . V_116 . V_117 = 0x100 + F_6 ( V_217 -> V_225 ) ;
V_307 . V_313 . V_116 . V_118 = 0x100 + V_217 -> V_226 ;
V_308 =
F_86 ( V_49 , V_308 , V_305 , & V_307 ,
V_329 ) ;
F_82 ( & V_308 , V_305 , V_49 , V_217 ) ;
V_307 . V_12 = V_330 ;
if ( F_6 ( V_217 -> V_222 ) & V_331 )
V_307 . V_313 . V_253 . V_5 = V_332 | V_333 ;
else
V_307 . V_313 . V_253 . V_5 = V_334 ;
V_307 . V_313 . V_253 . V_105 = 0 ;
V_308 =
F_84 ( V_49 , V_308 , V_305 , & V_307 , ( char * ) V_308 ) ;
if ( V_217 -> V_92 . V_106 ) {
if ( ( ( V_308 - V_51 ) +
V_335 ) <= ( unsigned long ) V_305 ) {
V_318 = V_308 + V_335 ;
V_307 . V_12 = V_336 ;
V_307 . V_313 . V_126 . V_337 = V_307 . V_313 . V_126 . V_338 =
0 ;
for ( V_316 = 0 ;
V_316 < V_217 -> V_92 . V_106
&& V_316 < V_125 ; V_316 ++ ) {
V_307 . V_313 . V_126 . V_318 =
( V_217 -> V_92 . V_127 [ V_316 ] & 0x7f ) *
500000 ;
V_318 =
F_88 ( V_49 , V_308 ,
V_318 , V_305 , & V_307 ,
V_339 ) ;
}
V_308 = V_318 ;
}
}
}
V_18 = V_308 - V_51 ;
if ( V_18 < 0 ) {
F_8 ( L_71 ) ;
V_18 = 0 ;
}
F_14 ( L_72 ,
V_20 , ( unsigned int ) ( V_308 - V_51 ) ) ;
return ( T_4 ) V_18 ;
}
static int
F_89 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_87 * V_88 , char * V_51 )
{
T_6 V_73 ;
T_17 * V_340 ;
T_17 * V_91 = ( T_17 * ) V_341 ;
int error ;
T_4 V_342 = V_88 -> V_105 ;
T_4 V_3 = V_343 ;
T_24 V_344 = 0 ;
#if F_74 ( F_75 )
T_20 * V_229 = V_230 ;
T_19 * V_345 ;
#endif
F_14 ( L_73 , V_11 -> V_27 , V_342 ) ;
if ( ! V_51 ) {
F_14 ( L_74 , V_11 -> V_27 ) ;
return - V_19 ;
}
error = F_7 ( V_11 , V_74 , & V_73 , sizeof( V_73 ) ) ;
if ( error )
return error ;
V_73 . V_346 = F_5 ( V_73 . V_346 ) ;
if ( V_73 . V_346 )
return - V_347 ;
if ( V_277 ) {
V_91 = F_30 ( V_3 , V_103 ) ;
if ( ! V_91 ) {
F_14 ( L_75 ,
V_11 -> V_27 ) ;
V_277 = 0 ;
return - V_104 ;
}
}
memset ( V_91 , 0 , V_3 ) ;
V_91 -> V_40 = F_2 ( V_3 ) ;
error = F_7 ( V_11 , V_218 , V_91 , V_3 ) ;
if ( error ) {
F_8 ( L_76 ,
V_11 -> V_27 , V_20 , error ) ;
V_88 -> V_105 = V_3 ;
if ( V_277 ) {
V_277 = 0 ;
F_31 ( V_91 ) ;
}
return 0 ;
}
V_91 -> V_40 = F_5 ( V_91 -> V_40 ) ;
V_91 -> V_219 = F_5 ( V_91 -> V_219 ) ;
V_91 -> V_106 = F_5 ( V_91 -> V_106 ) ;
if ( V_91 -> V_219 != V_220 ) {
F_8 ( L_31 ,
V_20 , V_91 -> V_219 ) ;
if ( V_277 ) {
V_277 = 0 ;
F_31 ( V_91 ) ;
}
return - V_19 ;
}
if ( V_277 ) {
F_14 ( L_77 ,
V_20 , V_91 -> V_106 ) ;
V_344 =
( T_24 ) F_85 ( V_91 , V_49 , V_51 ,
V_342 ) ;
F_31 ( V_91 ) ;
#if F_74 ( F_75 )
V_345 = V_229 -> V_232 ;
while ( V_345 != V_229 -> V_266 ) {
V_340 =
& ( ( V_233 * ) V_345 -> V_234 ) -> V_235 ;
F_14 ( L_78 ,
V_20 , V_340 -> V_106 ) ;
if ( V_340 -> V_106 > 0 )
V_344 +=
( T_24 ) F_85 ( V_340 ,
V_49 , V_51 + V_344 ,
V_342 - V_344 ) ;
V_345 = V_345 -> V_237 ;
}
#else
V_340 = ( T_17 * ) V_341 ;
F_14 ( L_78 ,
V_20 , V_340 -> V_106 ) ;
if ( V_340 -> V_106 > 0 )
V_344 +=
( T_24 ) F_85 ( V_340 , V_49 ,
V_51 + V_344 ,
V_342 -
V_344 ) ;
#endif
} else {
V_91 = ( T_17 * ) V_341 ;
V_344 =
( T_24 ) F_85 ( V_91 , V_49 , V_51 ,
V_342 ) ;
}
#if F_74 ( F_75 )
V_277 = 0 ;
#endif
if ( ( V_344 + V_317 ) < V_342 )
V_3 = V_344 ;
V_88 -> V_105 = V_3 ;
V_88 -> V_5 = 0 ;
F_14 ( L_79 ,
V_20 , V_88 -> V_105 , V_91 -> V_106 ) ;
return 0 ;
}
static int
F_90 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_87 * V_88 , char * V_51 )
{
T_17 * V_91 ;
struct V_306 V_307 ;
T_18 * V_217 = NULL ;
int V_348 , V_316 ;
int V_349 ;
char * V_308 = V_51 , * V_305 = V_51 + V_88 -> V_105 , * V_318 ;
T_20 * V_229 = V_230 ;
T_19 * V_345 ;
T_22 V_350 = 0 ;
T_11 V_351 ;
F_14 ( L_80 ,
V_11 -> V_27 , V_20 , V_88 -> V_105 ) ;
if ( ! V_51 ) {
F_14 ( L_81 ,
V_11 -> V_27 ) ;
return - V_19 ;
}
if ( ( ! V_229 ) || ( ! V_229 -> V_231 ) ) {
F_8 ( L_82 , V_20 ) ;
return F_89 ( V_11 , V_49 , V_88 , V_51 ) ;
}
if ( V_229 -> V_255 == V_296 ) {
F_14 ( L_83 , V_11 -> V_27 ) ;
return - V_347 ;
}
F_14 ( L_84 , V_11 -> V_27 ) ;
V_349 = 0 ;
V_345 = V_229 -> V_232 ;
while ( V_345 != V_229 -> V_266 ) {
V_91 = & ( ( V_233 * ) V_345 -> V_234 ) -> V_235 ;
V_350 += V_91 -> V_106 ;
if ( V_91 -> V_219 != V_220 ) {
F_8 ( L_31 ,
V_20 , V_91 -> V_219 ) ;
return - V_19 ;
}
V_217 = NULL ;
for ( V_348 = 0 ; V_348 < V_91 -> V_106 && V_349 < V_216 ;
V_349 ++ , V_348 ++ ) {
V_217 = V_217 ? ( T_18 * ) ( ( unsigned long ) V_217 +
F_5 ( V_217 -> V_105 ) ) :
V_91 -> V_221 ;
ASSERT ( ( ( unsigned long ) V_217 + F_5 ( V_217 -> V_105 ) ) <=
( ( unsigned long ) V_91 + V_236 ) ) ;
if ( V_308 + V_58 + V_217 -> V_56 +
V_325 + V_327 + V_329 >=
V_305 )
return - V_352 ;
V_307 . V_12 = V_170 ;
V_307 . V_313 . V_319 . V_187 = V_203 ;
memcpy ( V_307 . V_313 . V_319 . V_184 , & V_217 -> V_224 ,
V_58 ) ;
V_308 =
F_86 ( V_49 , V_308 , V_305 , & V_307 ,
V_320 ) ;
V_307 . V_313 . V_253 . V_105 = F_5 ( V_217 -> V_56 ) ;
V_307 . V_12 = V_321 ;
V_307 . V_313 . V_253 . V_5 = 1 ;
V_308 =
F_84 ( V_49 , V_308 , V_305 , & V_307 ,
V_217 -> V_59 ) ;
if ( F_6 ( V_217 -> V_222 ) &
( V_223 | V_322 ) ) {
V_307 . V_12 = V_323 ;
if ( F_6 ( V_217 -> V_222 ) &
V_223 )
V_307 . V_313 . V_324 = V_82 ;
else
V_307 . V_313 . V_324 = V_80 ;
V_308 =
F_86 ( V_49 , V_308 , V_305 , & V_307 ,
V_325 ) ;
}
V_307 . V_12 = V_326 ;
V_351 =
( V_217 -> V_353 ==
0 ) ? F_87 ( V_217 -> V_192 ) : V_217 -> V_353 ;
if ( V_351 <= V_111 )
V_307 . V_313 . V_109 . V_66 =
F_32 ( V_351 ) ;
else
V_307 . V_313 . V_109 . V_66 = F_33 (
V_112 / 2 ,
V_351 ) ;
V_307 . V_313 . V_109 . V_65 = 6 ;
V_308 =
F_86 ( V_49 , V_308 , V_305 , & V_307 ,
V_327 ) ;
V_307 . V_12 = V_328 ;
V_307 . V_313 . V_116 . V_116 = F_36 ( F_6 ( V_217 -> V_225 ) ) ;
V_307 . V_313 . V_116 . V_117 = 0x100 + F_6 ( V_217 -> V_225 ) ;
V_307 . V_313 . V_116 . V_118 = 0x100 + V_217 -> V_226 ;
V_308 =
F_86 ( V_49 , V_308 , V_305 , & V_307 ,
V_329 ) ;
F_82 ( & V_308 , V_305 , V_49 , V_217 ) ;
V_307 . V_12 = V_330 ;
if ( F_6 ( V_217 -> V_222 ) &
V_331 )
V_307 . V_313 . V_253 . V_5 =
V_332 | V_333 ;
else
V_307 . V_313 . V_253 . V_5 = V_334 ;
V_307 . V_313 . V_253 . V_105 = 0 ;
V_308 =
F_84 ( V_49 , V_308 , V_305 , & V_307 ,
( char * ) V_308 ) ;
if ( V_217 -> V_92 . V_106 ) {
if ( V_308 + V_125 * V_339 >=
V_305 )
return - V_352 ;
V_318 = V_308 + V_335 ;
V_307 . V_12 = V_336 ;
V_307 . V_313 . V_126 . V_337 = V_307 . V_313 . V_126 . V_338 =
0 ;
for ( V_316 = 0 ;
V_316 < V_217 -> V_92 . V_106
&& V_316 < V_125 ; V_316 ++ ) {
V_307 . V_313 . V_126 . V_318 =
( V_217 -> V_92 . V_127 [ V_316 ] & 0x7f ) *
500000 ;
V_318 =
F_88 ( V_49 , V_308 ,
V_318 , V_305 ,
& V_307 ,
V_339 ) ;
}
V_308 = V_318 ;
}
}
V_345 = V_345 -> V_237 ;
}
V_88 -> V_105 = V_308 - V_51 ;
V_88 -> V_5 = 0 ;
F_14 ( L_79 ,
V_20 , V_88 -> V_105 , V_350 ) ;
if ( ! V_88 -> V_105 )
return - V_347 ;
return 0 ;
}
static int
F_91 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_87 * V_88 , char * V_51 )
{
int error ;
T_14 V_190 ;
int V_191 ;
F_14 ( L_85 , V_11 -> V_27 ) ;
if ( V_285 )
return - V_347 ;
memset ( & V_206 , 0 , sizeof( V_206 ) ) ;
F_92 ( V_51 ) ;
if ( V_88 -> V_105 && V_51 ) {
#if V_120 > 20
V_206 . V_56 = F_39 ( V_293 , sizeof( V_206 . V_59 ) ,
V_88 -> V_105 ) ;
#else
V_206 . V_56 = F_39 ( V_293 , sizeof( V_206 . V_59 ) ,
V_88 -> V_105 - 1 ) ;
#endif
memcpy ( V_206 . V_59 , V_51 , V_206 . V_56 ) ;
} else {
V_206 . V_56 = 0 ;
}
V_206 . V_56 = F_2 ( V_206 . V_56 ) ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
V_191 = sizeof( V_190 . V_52 ) ;
memcpy ( & V_190 . V_52 . V_59 , V_206 . V_59 , V_206 . V_56 ) ;
V_190 . V_52 . V_56 = F_2 ( V_206 . V_56 ) ;
memcpy ( V_190 . V_193 . V_54 , V_239 , V_58 ) ;
F_42 ( V_70 . V_71 , & V_190 ,
& V_191 ) ;
error = F_7 ( V_11 , V_207 , & V_190 ,
V_191 ) ;
if ( error )
F_8 ( L_86 , error ) ;
if ( V_206 . V_56 ) {
F_14 ( L_87 ,
V_20 , V_206 . V_59 , V_70 . V_71 ) ;
}
return 0 ;
}
static int
F_93 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_87 * V_88 , char * V_51 )
{
T_5 V_52 ;
int error ;
F_14 ( L_88 , V_11 -> V_27 ) ;
if ( ! V_51 )
return - V_19 ;
error = F_7 ( V_11 , V_55 , & V_52 , sizeof( V_52 ) ) ;
if ( error ) {
F_8 ( L_89 ) ;
return error ;
}
V_52 . V_56 = F_5 ( V_52 . V_56 ) ;
memcpy ( V_51 , V_52 . V_59 , V_52 . V_56 ) ;
V_88 -> V_105 = V_52 . V_56 ;
V_88 -> V_5 = 1 ;
return 0 ;
}
static int
F_94 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_87 * V_88 , char * V_51 )
{
T_13 * V_180 = * ( T_13 * * ) F_38 ( V_11 ) ;
F_14 ( L_90 , V_11 -> V_27 ) ;
if ( ! V_51 )
return - V_19 ;
if ( V_88 -> V_105 > sizeof( V_180 -> V_354 ) )
return - V_352 ;
memcpy ( V_180 -> V_354 , V_51 , V_88 -> V_105 ) ;
V_180 -> V_354 [ V_88 -> V_105 - 1 ] = '\0' ;
return 0 ;
}
static int
F_95 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_87 * V_88 , char * V_51 )
{
T_13 * V_180 = * ( T_13 * * ) F_38 ( V_11 ) ;
F_14 ( L_91 , V_11 -> V_27 ) ;
if ( ! V_51 )
return - V_19 ;
strcpy ( V_51 , V_180 -> V_354 ) ;
V_88 -> V_105 = strlen ( V_51 ) + 1 ;
return 0 ;
}
static int
F_96 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_355 * V_356 , char * V_51 )
{
T_9 V_92 ;
int error , V_357 , V_94 , V_358 , V_359 ;
F_14 ( L_92 , V_11 -> V_27 ) ;
error = F_7 ( V_11 , V_123 , & V_92 ,
sizeof( V_92 ) ) ;
if ( error )
return error ;
V_92 . V_106 = F_5 ( V_92 . V_106 ) ;
if ( V_356 -> V_318 < 0 )
V_357 = V_92 . V_127 [ V_92 . V_106 - 1 ] & 0x7f ;
else if ( V_356 -> V_318 < V_92 . V_106 )
V_357 = V_92 . V_127 [ V_356 -> V_318 ] & 0x7f ;
else
V_357 = V_356 -> V_318 / 500000 ;
if ( V_356 -> V_337 ) {
V_358 = F_15 ( V_11 , L_93 , V_357 ) ;
V_359 = F_15 ( V_11 , L_94 , V_357 ) ;
if ( V_358 && V_359 )
return V_358 | V_359 ;
} else {
V_358 = F_15 ( V_11 , L_93 , 0 ) ;
V_359 = F_15 ( V_11 , L_94 , 0 ) ;
if ( V_358 && V_359 )
return V_358 | V_359 ;
for ( V_94 = 0 ; V_94 < V_92 . V_106 ; V_94 ++ )
if ( ( V_92 . V_127 [ V_94 ] & 0x7f ) > V_357 )
break;
V_92 . V_106 = F_2 ( V_94 ) ;
error = F_7 ( V_11 , V_360 , & V_92 ,
sizeof( V_92 ) ) ;
if ( error )
return error ;
}
return 0 ;
}
static int
F_97 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_355 * V_356 , char * V_51 )
{
int error , V_357 ;
F_14 ( L_95 , V_11 -> V_27 ) ;
error = F_7 ( V_11 , V_361 , & V_357 , sizeof( V_357 ) ) ;
if ( error )
return error ;
V_357 = F_5 ( V_357 ) ;
V_356 -> V_318 = V_357 * 500000 ;
return 0 ;
}
static int
F_98 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_355 * V_356 , char * V_51 )
{
int error , V_362 ;
F_14 ( L_96 , V_11 -> V_27 ) ;
if ( V_356 -> V_338 )
V_362 = V_363 ;
else if ( V_356 -> V_318 < 0 || V_356 -> V_318 > V_363 )
return - V_19 ;
else
V_362 = V_356 -> V_318 ;
error = F_15 ( V_11 , L_97 , V_362 ) ;
if ( error )
return error ;
return 0 ;
}
static int
F_99 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_355 * V_356 , char * V_51 )
{
int error , V_362 ;
F_14 ( L_98 , V_11 -> V_27 ) ;
error = F_21 ( V_11 , L_97 , & V_362 ) ;
if ( error )
return error ;
V_356 -> V_318 = V_362 ;
V_356 -> V_338 = ( V_362 >= V_363 ) ;
V_356 -> V_337 = 1 ;
return 0 ;
}
static int
F_100 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_355 * V_356 , char * V_51 )
{
int error , V_364 ;
F_14 ( L_99 , V_11 -> V_27 ) ;
if ( V_356 -> V_338 )
V_364 = V_365 ;
else if ( V_356 -> V_318 < 0 || V_356 -> V_318 > V_365 )
return - V_19 ;
else
V_364 = V_356 -> V_318 ;
error = F_15 ( V_11 , L_100 , V_364 ) ;
if ( error )
return error ;
return 0 ;
}
static int
F_101 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_355 * V_356 , char * V_51 )
{
int error , V_366 ;
F_14 ( L_101 , V_11 -> V_27 ) ;
error = F_21 ( V_11 , L_100 , & V_366 ) ;
if ( error )
return error ;
V_356 -> V_318 = V_366 ;
V_356 -> V_338 = ( V_366 >= V_365 ) ;
V_356 -> V_337 = 1 ;
return 0 ;
}
static int
F_102 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_355 * V_356 , char * V_51 )
{
int error , V_367 ;
T_12 V_368 ;
F_14 ( L_102 , V_11 -> V_27 ) ;
V_367 = V_356 -> V_338 ? V_369 : 0 ;
V_367 += V_369 << 16 ;
V_367 = F_2 ( V_367 ) ;
error = F_7 ( V_11 , V_370 , & V_367 , sizeof( V_367 ) ) ;
if ( error )
return error ;
if ( V_367 & V_369 )
return 0 ;
if ( ! ( V_356 -> V_5 & V_153 ) )
return - V_19 ;
if ( V_356 -> V_318 < 0 )
return 0 ;
if ( V_356 -> V_318 > 0xffff )
V_368 = 0xffff ;
else
V_368 = ( T_12 ) V_356 -> V_318 ;
error =
F_15 ( V_11 , L_103 , ( int ) ( F_103 ( V_368 ) ) ) ;
return error ;
}
static int
F_104 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_355 * V_356 , char * V_51 )
{
int error , V_367 , V_371 ;
T_11 V_372 ;
F_14 ( L_104 , V_11 -> V_27 ) ;
error = F_7 ( V_11 , V_373 , & V_367 , sizeof( V_367 ) ) ;
if ( error )
return error ;
error = F_21 ( V_11 , L_103 , & V_371 ) ;
if ( error )
return error ;
V_367 = F_5 ( V_367 ) ;
V_372 = ( T_11 ) ( V_371 & ~ V_374 ) ;
V_356 -> V_318 = ( V_375 ) F_105 ( V_372 ) ;
V_356 -> V_337 = 0 ;
V_356 -> V_338 =
( V_367 & ( V_369 | V_376 ) ) ? 1 : 0 ;
V_356 -> V_5 = V_153 ;
return 0 ;
}
static int
F_106 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_355 * V_356 , char * V_51 )
{
int error , V_377 , V_378 ;
F_14 ( L_105 , V_11 -> V_27 ) ;
V_356 -> V_338 = 0 ;
if ( ( V_356 -> V_5 & V_379 ) == V_380 )
return - V_19 ;
error = F_7 ( V_11 , V_381 , & V_377 , sizeof( V_377 ) ) ;
if ( error )
return error ;
error = F_7 ( V_11 , V_382 , & V_378 , sizeof( V_378 ) ) ;
if ( error )
return error ;
V_377 = F_5 ( V_377 ) ;
V_378 = F_5 ( V_378 ) ;
if ( V_356 -> V_5 & V_383 ) {
V_356 -> V_5 = V_157 | V_383 ;
V_356 -> V_318 = V_377 ;
} else {
V_356 -> V_5 = V_157 ;
V_356 -> V_318 = V_378 ;
if ( V_378 != V_377 )
V_356 -> V_5 |= V_384 ;
}
return 0 ;
}
static int
F_107 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_87 * V_88 , char * V_51 )
{
T_1 V_1 ;
int error , V_33 , V_385 ;
F_14 ( L_106 , V_11 -> V_27 ) ;
memset ( & V_1 , 0 , sizeof( V_1 ) ) ;
if ( ( V_88 -> V_5 & V_386 ) == 0 ) {
for ( V_1 . V_2 = 0 ; V_1 . V_2 < V_137 ;
V_1 . V_2 ++ ) {
V_33 = F_2 ( V_1 . V_2 ) ;
error = F_7 ( V_11 , V_387 , & V_33 ,
sizeof( V_33 ) ) ;
if ( error )
return error ;
V_33 = F_5 ( V_33 ) ;
if ( V_33 )
break;
}
if ( V_1 . V_2 == V_137 )
V_1 . V_2 = 0 ;
} else {
V_1 . V_2 = ( V_88 -> V_5 & V_386 ) - 1 ;
if ( V_1 . V_2 >= V_137 )
return - V_19 ;
}
if ( ! V_51 || ! V_88 -> V_105 || ( V_88 -> V_5 & V_333 ) ) {
V_33 = F_2 ( V_1 . V_2 ) ;
error = F_7 ( V_11 , V_388 , & V_33 ,
sizeof( V_33 ) ) ;
if ( error )
return error ;
} else {
V_1 . V_3 = V_88 -> V_105 ;
if ( V_88 -> V_105 > sizeof( V_1 . V_253 ) )
return - V_19 ;
memcpy ( V_1 . V_253 , V_51 , V_88 -> V_105 ) ;
V_1 . V_5 = V_389 ;
switch ( V_1 . V_3 ) {
case V_140 :
V_1 . V_4 = V_390 ;
break;
case V_141 :
V_1 . V_4 = V_391 ;
break;
case V_142 :
V_1 . V_4 = V_392 ;
break;
case V_143 :
V_1 . V_4 = V_393 ;
break;
default:
return - V_19 ;
}
F_1 ( & V_1 ) ;
error = F_7 ( V_11 , V_394 , & V_1 , sizeof( V_1 ) ) ;
if ( error )
return error ;
}
V_33 = ( V_88 -> V_5 & V_334 ) ? 0 : V_395 ;
error = F_21 ( V_11 , L_107 , & V_385 ) ;
if ( error )
return error ;
V_385 &= ~ ( V_395 ) ;
V_385 |= V_33 ;
error = F_15 ( V_11 , L_107 , V_385 ) ;
if ( error )
return error ;
V_33 = ( V_88 -> V_5 & V_396 ) ? 1 : 0 ;
V_33 = F_2 ( V_33 ) ;
error = F_7 ( V_11 , V_397 , & V_33 , sizeof( V_33 ) ) ;
if ( error )
return error ;
return 0 ;
}
static int
F_108 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_87 * V_88 , char * V_51 )
{
T_1 V_1 ;
int error , V_33 , V_385 , V_398 ;
F_14 ( L_108 , V_11 -> V_27 ) ;
memset ( & V_1 , 0 , sizeof( T_1 ) ) ;
if ( ( V_88 -> V_5 & V_386 ) == 0 ) {
for ( V_1 . V_2 = 0 ; V_1 . V_2 < V_137 ;
V_1 . V_2 ++ ) {
V_33 = V_1 . V_2 ;
error = F_7 ( V_11 , V_387 , & V_33 ,
sizeof( V_33 ) ) ;
if ( error )
return error ;
V_33 = F_5 ( V_33 ) ;
if ( V_33 )
break;
}
} else
V_1 . V_2 = ( V_88 -> V_5 & V_386 ) - 1 ;
if ( V_1 . V_2 >= V_137 )
V_1 . V_2 = 0 ;
error = F_7 ( V_11 , V_399 , & V_385 , sizeof( V_385 ) ) ;
if ( error )
return error ;
error = F_7 ( V_11 , V_400 , & V_398 , sizeof( V_398 ) ) ;
if ( error )
return error ;
F_4 ( & V_1 ) ;
V_385 = F_5 ( V_385 ) ;
V_398 = F_5 ( V_398 ) ;
V_88 -> V_105 = F_39 ( T_12 , V_401 , V_1 . V_3 ) ;
V_88 -> V_5 = V_1 . V_2 + 1 ;
if ( ! ( V_385 & ( V_395 | V_402 | V_403 ) ) )
V_88 -> V_5 |= V_334 ;
if ( V_398 )
V_88 -> V_5 |= V_396 ;
if ( V_88 -> V_105 && V_51 )
memcpy ( V_51 , V_1 . V_253 , V_88 -> V_105 ) ;
return 0 ;
}
static int
F_109 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_355 * V_356 , char * V_51 )
{
int error , V_404 ;
F_14 ( L_109 , V_11 -> V_27 ) ;
V_404 = V_356 -> V_338 ? V_405 : V_406 ;
V_404 = F_2 ( V_404 ) ;
error = F_7 ( V_11 , V_407 , & V_404 , sizeof( V_404 ) ) ;
if ( error )
return error ;
return 0 ;
}
static int
F_110 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_355 * V_356 , char * V_51 )
{
int error , V_404 ;
F_14 ( L_110 , V_11 -> V_27 ) ;
error = F_7 ( V_11 , V_408 , & V_404 , sizeof( V_404 ) ) ;
if ( error )
return error ;
V_404 = F_5 ( V_404 ) ;
V_356 -> V_338 = V_404 ? 0 : 1 ;
V_356 -> V_5 = V_409 ;
return 0 ;
}
static int
F_111 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_87 * V_410 , char * V_51 )
{
F_14 ( L_111 , V_11 -> V_27 ) ;
F_92 ( V_51 ) ;
F_19 ( V_11 , L_112 , V_51 , V_410 -> V_105 ) ;
return 0 ;
}
static int
F_112 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_87 * V_410 , char * V_51 )
{
F_14 ( L_113 , V_11 -> V_27 ) ;
V_410 -> V_105 = 64 ;
F_20 ( V_11 , L_112 , V_51 , V_410 -> V_105 ) ;
return 0 ;
}
static int
F_113 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_87 * V_88 , char * V_51 )
{
T_1 V_1 ;
int error ;
struct V_411 * V_307 ;
F_14 ( L_114 , V_11 -> V_27 ) ;
F_92 ( V_51 ) ;
memset ( & V_1 , 0 , sizeof( V_1 ) ) ;
V_307 = (struct V_411 * ) V_51 ;
if ( V_88 -> V_5 & V_334 ) {
}
V_1 . V_2 = 0 ;
if ( V_88 -> V_5 & V_386 )
V_1 . V_2 = ( V_88 -> V_5 & V_386 ) - 1 ;
V_1 . V_3 = V_307 -> V_412 ;
if ( ! F_114 ( V_307 -> V_181 . V_184 ) )
memcpy ( & V_1 . V_212 , & V_307 -> V_181 . V_184 , V_58 ) ;
if ( V_1 . V_3 == 0 ) {
if ( V_307 -> V_413 & V_414 ) {
F_115 ( L_115 ,
V_1 . V_2 ) ;
V_1 . V_2 = F_2 ( V_1 . V_2 ) ;
error = F_7 ( V_11 , V_388 ,
& V_1 . V_2 , sizeof( V_1 . V_2 ) ) ;
if ( error )
return error ;
} else {
F_1 ( & V_1 ) ;
F_7 ( V_11 , V_394 , & V_1 , sizeof( V_1 ) ) ;
}
} else {
if ( V_307 -> V_412 > sizeof( V_1 . V_253 ) )
return - V_19 ;
F_115 ( L_116 , V_1 . V_2 ) ;
if ( V_307 -> V_413 & V_414 ) {
F_115 ( L_117 ) ;
V_1 . V_5 = V_389 ;
}
memcpy ( V_1 . V_253 , V_307 -> V_1 , V_307 -> V_412 ) ;
if ( V_307 -> V_415 == V_416 ) {
T_11 V_417 [ 8 ] ;
memcpy ( V_417 , & V_1 . V_253 [ 24 ] , sizeof( V_417 ) ) ;
memcpy ( & V_1 . V_253 [ 24 ] , & V_1 . V_253 [ 16 ] , sizeof( V_417 ) ) ;
memcpy ( & V_1 . V_253 [ 16 ] , V_417 , sizeof( V_417 ) ) ;
}
if ( V_307 -> V_413 & V_418 ) {
unsigned char * V_419 ;
V_419 = ( unsigned char * ) V_307 -> V_420 ;
V_1 . V_6 . V_7 = ( V_419 [ 5 ] << 24 ) | ( V_419 [ 4 ] << 16 ) |
( V_419 [ 3 ] << 8 ) | V_419 [ 2 ] ;
V_1 . V_6 . V_8 = ( V_419 [ 1 ] << 8 ) | V_419 [ 0 ] ;
V_1 . V_9 = true ;
}
switch ( V_307 -> V_415 ) {
case V_421 :
V_1 . V_4 = V_422 ;
break;
case V_423 :
if ( V_307 -> V_412 == V_140 )
V_1 . V_4 = V_390 ;
else
V_1 . V_4 = V_391 ;
break;
case V_416 :
V_1 . V_4 = V_392 ;
break;
case V_424 :
V_1 . V_4 = V_393 ;
break;
default:
break;
}
F_1 ( & V_1 ) ;
F_116 ( V_11 ) ;
error = F_7 ( V_11 , V_394 , & V_1 , sizeof( V_1 ) ) ;
if ( error )
return error ;
}
return 0 ;
}
static int
F_117 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_355 * V_356 , char * V_51 )
{
struct V_425 * V_426 ;
T_4 V_94 ;
int V_18 = 0 ;
F_115 ( L_118 , V_11 -> V_27 ) ;
F_92 ( V_51 ) ;
V_426 = (struct V_425 * ) V_51 ;
if ( V_426 -> V_12 == V_427 ) {
F_115 ( L_119 ) ;
memset ( ( char * ) & V_428 , 0 , sizeof( V_428 ) ) ;
}
else if ( V_426 -> V_12 == V_429 ) {
{
T_25 V_430 , * V_431 ;
T_4 V_316 ;
V_431 = & V_430 ;
memcpy ( & V_431 -> V_430 [ 0 ] . V_224 ,
& V_426 -> V_54 . V_184 [ 0 ] ,
V_58 ) ;
memcpy ( & V_431 -> V_430 [ 0 ] . V_432 ,
& V_426 -> V_430 [ 0 ] ,
V_433 ) ;
F_115 ( L_120
L_121 , & V_431 -> V_430 [ 0 ] . V_224 ) ;
for ( V_316 = 0 ; V_316 < V_433 ; V_316 ++ )
F_115 ( L_122 , V_431 -> V_430 [ 0 ] . V_432 [ V_316 ] ) ;
F_115 ( L_123 ) ;
}
for ( V_94 = 0 ; V_94 < V_428 . V_434 . V_435 ; V_94 ++ )
if ( ! memcmp
( & V_426 -> V_54 . V_184 [ 0 ] ,
& V_428 . V_434 . V_430 [ V_94 ] . V_224 , V_58 ) )
break;
if ( ( V_428 . V_434 . V_435 > 0 )
&& ( V_94 < V_428 . V_434 . V_435 ) ) {
memset ( & V_428 . V_434 . V_430 [ V_94 ] , 0 , sizeof( V_436 ) ) ;
for (; V_94 < ( V_428 . V_434 . V_435 - 1 ) ; V_94 ++ ) {
memcpy ( & V_428 . V_434 . V_430 [ V_94 ] . V_224 ,
& V_428 . V_434 . V_430 [ V_94 + 1 ] . V_224 ,
V_58 ) ;
memcpy ( & V_428 . V_434 . V_430 [ V_94 ] . V_432 ,
& V_428 . V_434 . V_430 [ V_94 + 1 ] . V_432 ,
V_433 ) ;
}
V_428 . V_434 . V_435 -- ;
} else
V_18 = - V_19 ;
}
else if ( V_426 -> V_12 == V_437 ) {
for ( V_94 = 0 ; V_94 < V_428 . V_434 . V_435 ; V_94 ++ )
if ( ! memcmp
( & V_426 -> V_54 . V_184 [ 0 ] ,
& V_428 . V_434 . V_430 [ V_94 ] . V_224 , V_58 ) )
break;
if ( V_94 < V_438 ) {
memcpy ( & V_428 . V_434 . V_430 [ V_94 ] . V_224 ,
& V_426 -> V_54 . V_184 [ 0 ] ,
V_58 ) ;
memcpy ( & V_428 . V_434 . V_430 [ V_94 ] . V_432 ,
& V_426 -> V_430 [ 0 ] ,
V_433 ) ;
if ( V_94 == V_428 . V_434 . V_435 )
V_428 . V_434 . V_435 ++ ;
} else
V_18 = - V_19 ;
{
T_4 V_316 ;
T_4 V_95 ;
V_95 = V_428 . V_434 . V_435 ;
F_115 ( L_124 ,
& V_428 . V_434 . V_430 [ V_95 ] . V_224 ) ;
for ( V_316 = 0 ; V_316 < V_433 ; V_316 ++ )
F_115 ( L_122 ,
V_428 . V_434 . V_430 [ V_95 ] . V_432 [ V_316 ] ) ;
F_115 ( L_123 ) ;
}
}
F_115 ( L_125 ,
V_428 . V_434 . V_435 ) ;
for ( V_94 = 0 ; V_94 < V_428 . V_434 . V_435 ; V_94 ++ ) {
T_4 V_316 ;
F_115 ( L_126 ,
V_94 , & V_428 . V_434 . V_430 [ V_94 ] . V_224 ) ;
for ( V_316 = 0 ; V_316 < V_433 ; V_316 ++ )
F_115 ( L_122 , V_428 . V_434 . V_430 [ V_94 ] . V_432 [ V_316 ] ) ;
F_115 ( L_123 ) ;
}
F_115 ( L_123 ) ;
if ( ! V_18 )
V_18 = F_19 ( V_11 , L_127 , ( char * ) & V_428 ,
sizeof( V_428 ) ) ;
return V_18 ;
}
static int
F_118 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_355 * V_356 , char * V_51 )
{
F_14 ( L_128 , V_11 -> V_27 ) ;
return 0 ;
}
static int
F_119 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_355 * V_356 , char * V_51 )
{
int error = 0 ;
int V_439 ;
int V_440 ;
int V_33 = 0 ;
T_13 * V_180 = * ( T_13 * * ) F_38 ( V_11 ) ;
F_14 ( L_129 , V_11 -> V_27 ) ;
V_439 = V_356 -> V_5 & V_441 ;
V_440 = V_356 -> V_318 ;
F_14 ( L_130 ,
V_11 -> V_27 , V_439 , V_440 ) ;
switch ( V_439 ) {
case V_442 :
if ( V_440 & V_443 )
V_33 = V_444 ;
else if ( V_440 & ( V_445 ) )
V_33 = V_446 | V_447 ;
else if ( V_440 & V_448 )
V_33 = V_449 | V_450 ;
F_9 ( L_131 ,
V_20 , __LINE__ , V_33 ) ;
error = F_15 ( V_11 , L_132 , V_33 ) ;
if ( error )
return error ;
break;
case V_451 :
case V_452 :
if ( V_440 & ( V_453 | V_454 ) )
V_33 = V_395 ;
if ( V_440 & V_455 )
V_33 = V_402 ;
if ( V_440 & V_456 )
V_33 = V_403 ;
if ( V_439 == V_451 ) {
V_180 -> V_457 = V_33 ;
V_33 |= V_180 -> V_458 ;
} else {
V_180 -> V_458 = V_33 ;
V_33 |= V_180 -> V_457 ;
}
if ( V_180 -> V_459 && ! V_33 ) {
F_115 ( L_133 ,
V_11 -> V_27 , V_20 ) ;
error = F_15 ( V_11 , L_134 ,
true ) ;
if ( error ) {
F_115 ( L_135 ) ;
return error ;
}
} else if ( V_33 ) {
error = F_15 ( V_11 , L_134 ,
false ) ;
if ( error ) {
F_115 ( L_136 ) ;
return error ;
}
}
error = F_15 ( V_11 , L_107 , V_33 ) ;
if ( error )
return error ;
break;
case V_460 :
error = F_21 ( V_11 , L_132 , & V_33 ) ;
if ( error )
return error ;
if ( V_33 & ( V_446 | V_447 ) ) {
if ( V_440 & V_461 )
V_33 = V_446 ;
else
V_33 = V_447 ;
} else if ( V_33 & ( V_449 | V_450 ) ) {
if ( V_440 & V_461 )
V_33 = V_449 ;
else
V_33 = V_450 ;
}
F_9 ( L_137 ,
V_20 , __LINE__ , V_33 ) ;
error = F_15 ( V_11 , L_132 , V_33 ) ;
if ( error )
return error ;
break;
case V_462 :
F_19 ( V_11 , L_138 ,
( char * ) & V_440 , 1 ) ;
break;
case V_463 :
F_9 ( L_139 , V_440 ) ;
if ( V_440 == V_464 )
V_33 = 0 ;
else if ( V_440 == V_465 )
V_33 = 1 ;
else if ( V_440 ==
( V_464 | V_465 ) )
V_33 = 2 ;
else
error = 1 ;
if ( ! error ) {
error = F_15 ( V_11 , L_140 , V_33 ) ;
if ( error )
return error ;
}
break;
case V_466 :
if ( V_440 == 0 ) {
V_180 -> V_457 = 0 ;
V_180 -> V_458 = 0 ;
error = F_21 ( V_11 , L_107 , & V_33 ) ;
if ( error )
return error ;
if ( V_33 & ( V_402 | V_403 ) ) {
V_33 &= ~ ( V_402 | V_403 ) ;
F_15 ( V_11 , L_107 , V_33 ) ;
}
V_33 = 0 ;
F_9 ( L_137 ,
V_20 , __LINE__ , V_33 ) ;
F_15 ( V_11 , L_132 , 0 ) ;
return error ;
}
break;
case V_467 :
F_19 ( V_11 , L_141 , ( char * ) & V_440 , 1 ) ;
break;
case V_468 :
F_19 ( V_11 , L_142 ,
( char * ) & V_440 , 1 ) ;
break;
#if V_120 > 17
case V_469 :
F_9 ( L_143 , V_20 ) ;
break;
case V_470 :
{
int V_385 ;
if ( V_440 == 0 ) {
V_180 -> V_459 = false ;
error = F_15 ( V_11 ,
L_134 , false ) ;
if ( error ) {
F_115 ( L_144 ) ;
return error ;
}
} else {
V_180 -> V_459 = true ;
error = F_21 ( V_11 , L_107 , & V_385 ) ;
if ( error )
return error ;
if ( ! ( F_120 ( V_385 ) ) ) {
error = F_15 ( V_11 ,
L_134 ,
true ) ;
if ( error ) {
F_115 ( L_145 ) ;
return error ;
}
} else {
error = F_15 ( V_11 ,
L_134 ,
false ) ;
if ( error ) {
F_115 ( L_136 ) ;
return error ;
}
}
}
break;
}
#endif
default:
break;
}
return 0 ;
}
static int
F_121 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_355 * V_356 , char * V_51 )
{
int error ;
int V_439 ;
int V_440 = 0 ;
int V_33 ;
T_13 * V_180 = * ( T_13 * * ) F_38 ( V_11 ) ;
F_14 ( L_146 , V_11 -> V_27 ) ;
V_439 = V_356 -> V_5 & V_441 ;
switch ( V_439 ) {
case V_442 :
error = F_21 ( V_11 , L_132 , & V_33 ) ;
if ( error )
return error ;
if ( V_33 & ( V_471 | V_444 ) )
V_440 = V_443 ;
else if ( V_33 & ( V_446 | V_447 ) )
V_440 = V_445 ;
else if ( V_33 & ( V_449 | V_450 ) )
V_440 = V_448 ;
break;
case V_451 :
case V_452 :
if ( V_439 == V_451 )
V_33 = V_180 -> V_457 ;
else
V_33 = V_180 -> V_458 ;
V_440 = 0 ;
if ( V_33 ) {
if ( V_33 & V_395 )
V_440 |=
( V_453 |
V_454 ) ;
if ( V_33 & V_402 )
V_440 |= ( V_455 ) ;
if ( V_33 & V_403 )
V_440 |= ( V_456 ) ;
} else
V_440 = V_472 ;
break;
case V_460 :
error = F_21 ( V_11 , L_132 , & V_33 ) ;
if ( error )
return error ;
if ( F_122 ( V_33 ) )
V_440 = V_461 ;
else
V_440 = V_473 ;
break;
case V_462 :
F_20 ( V_11 , L_138 ,
( char * ) & V_440 , 1 ) ;
break;
case V_467 :
F_20 ( V_11 , L_141 , ( char * ) & V_440 , 1 ) ;
break;
case V_468 :
F_20 ( V_11 , L_142 ,
( char * ) & V_440 , 1 ) ;
break;
case V_463 :
error = F_21 ( V_11 , L_140 , & V_33 ) ;
if ( error )
return error ;
if ( ! V_33 )
V_440 = V_464 ;
else
V_440 = V_465 ;
break;
case V_466 :
error = F_21 ( V_11 , L_132 , & V_33 ) ;
if ( error )
return error ;
if ( V_33 )
V_440 = true ;
else
V_440 = false ;
break;
#if V_120 > 17
case V_469 :
F_8 ( L_143 , V_20 ) ;
break;
case V_470 :
V_440 = V_180 -> V_459 ;
break;
#endif
}
V_356 -> V_318 = V_440 ;
return 0 ;
}
int F_123 ( struct V_10 * V_11 , struct V_14 * V_474 , int V_12 )
{
struct V_475 * V_476 = (struct V_475 * ) V_474 ;
struct V_48 V_49 ;
T_26 V_477 ;
char * V_51 = NULL ;
int V_478 = 1 , V_479 = 0 , V_18 = 0 ;
F_14 ( L_147 ,
V_20 , V_12 ) ;
if ( V_12 < V_480 ||
F_124 ( V_12 ) >= F_40 ( V_481 ) ) {
F_8 ( L_148 ,
V_20 , V_12 ) ;
return - V_482 ;
}
V_477 = V_481 [ F_124 ( V_12 ) ] ;
if ( ! V_477 ) {
F_8 ( L_149 ,
V_20 , V_12 ) ;
return - V_482 ;
}
switch ( V_12 ) {
case V_483 :
case V_321 :
case V_484 :
case V_485 :
V_479 = V_486 + 1 ;
break;
case V_487 :
case V_330 :
#if V_120 > 17
case V_488 :
case V_489 :
#endif
V_479 = V_476 -> V_313 . V_253 . V_105 ;
break;
case V_490 :
V_479 = sizeof( struct V_89 ) + 500 ;
break;
case V_491 :
V_478 =
sizeof( struct V_53 ) + sizeof( struct V_186 ) ;
V_479 = V_216 ;
break;
#if V_120 > 13
case V_171 :
#if F_74 ( F_75 )
if ( V_230 )
V_479 = V_476 -> V_313 . V_253 . V_105 ;
else
#endif
V_479 = V_492 ;
break;
#endif
case V_493 :
V_478 = sizeof( struct V_53 ) ;
V_479 = V_494 ;
break;
case V_495 :
V_478 =
sizeof( struct V_53 ) + sizeof( struct V_186 ) ;
V_479 = V_494 ;
break;
#if V_120 > 17
case V_496 :
case V_497 :
#endif
case V_498 :
V_479 = V_476 -> V_313 . V_253 . V_105 ;
break;
}
if ( V_479 && V_476 -> V_313 . V_253 . V_499 ) {
if ( V_476 -> V_313 . V_253 . V_105 > V_479 ) {
F_8 ( L_150 ,
V_20 , V_12 , V_476 -> V_313 . V_253 . V_105 , V_479 ) ;
return - V_352 ;
}
V_51 = F_30 ( V_479 * V_478 , V_103 ) ;
if ( ! V_51 )
return - V_104 ;
if ( F_125
( V_51 , V_476 -> V_313 . V_253 . V_499 ,
V_476 -> V_313 . V_253 . V_105 * V_478 ) ) {
F_31 ( V_51 ) ;
return - V_500 ;
}
}
V_49 . V_12 = V_12 ;
V_49 . V_5 = 0 ;
V_18 = V_477 ( V_11 , & V_49 , & V_476 -> V_313 , V_51 ) ;
if ( V_51 ) {
if ( F_126
( V_476 -> V_313 . V_253 . V_499 , V_51 ,
V_476 -> V_313 . V_253 . V_105 * V_478 ) ) {
F_31 ( V_51 ) ;
return - V_500 ;
}
F_31 ( V_51 ) ;
}
return V_18 ;
}
bool
F_127 ( T_22 V_501 , T_22 V_264 , T_22 V_502 ,
char * V_503 , T_4 V_40 )
{
typedef struct V_504 {
T_22 V_505 ;
T_22 V_506 ;
T_22 V_507 ;
const char * V_508 ;
const char * V_509 ;
} V_504;
#define F_128 9999
const V_504 V_510 [] = {
{ V_511 , V_512 , F_128 ,
L_151 , L_152 } ,
{ V_511 , V_513 , F_128 ,
L_151 , L_153 } ,
{ V_511 , V_514 , F_128 ,
L_151 , L_154 } ,
{ V_515 , F_128 , V_516 ,
L_151 , L_155 } ,
{ V_515 , F_128 , V_517 ,
L_151 , L_156 } ,
{ V_518 , V_519 , F_128 ,
L_151 , L_157 } ,
{ V_518 , V_514 , F_128 ,
L_151 , L_158 } ,
{ V_518 , V_520 , F_128 ,
L_151 , L_159 } ,
{ V_521 , V_514 , F_128 ,
L_151 , L_160 } ,
{ V_521 , V_519 , F_128 ,
L_151 , L_161 } ,
{ V_521 , V_522 , F_128 ,
L_151 , L_162 } ,
{ V_523 , V_524 , F_128 ,
L_163 , L_164 } ,
{ V_523 , F_128 , F_128 ,
L_163 , L_165 } ,
{ V_525 , F_128 , F_128 ,
L_151 , L_166 } ,
{ V_526 , F_128 , F_128 ,
L_151 , L_167 } ,
{ V_527 , F_128 , F_128 ,
L_151 , L_168 }
} ;
const char * V_27 = L_42 ;
const char * V_528 = NULL ;
int V_94 ;
for ( V_94 = 0 ; V_94 < sizeof( V_510 ) / sizeof( V_510 [ 0 ] ) ; V_94 ++ ) {
const V_504 * V_529 = & V_510 [ V_94 ] ;
if ( V_529 -> V_505 == V_501 &&
( V_529 -> V_506 == V_264
|| V_529 -> V_506 == F_128 )
&& ( V_529 -> V_507 == V_502
|| V_529 -> V_507 == F_128 ) ) {
V_27 = V_529 -> V_508 ;
V_528 = V_529 -> V_509 ;
break;
}
}
if ( V_528 ) {
memset ( V_503 , 0 , V_40 ) ;
snprintf ( V_503 , V_40 , L_169 ,
V_27 , V_528 , V_264 , V_502 ) ;
F_9 ( L_170 , V_503 ) ;
return true ;
} else {
return false ;
}
}
static bool
F_129 ( T_27 * V_65 , char * V_503 , T_4 V_40 )
{
T_22 V_308 = F_130 ( V_65 -> V_501 ) ;
T_22 V_264 = F_130 ( V_65 -> V_264 ) ;
T_22 V_502 = F_130 ( V_65 -> V_502 ) ;
if ( F_127 ( V_308 , V_264 , V_502 , V_503 , V_40 ) ) {
return true ;
} else
return false ;
}
void F_131 ( struct V_10 * V_11 , T_27 * V_65 , void * V_253 )
{
#if V_120 > 13
union V_271 V_272 ;
char V_51 [ V_530 + 1 ] ;
int V_12 = 0 ;
T_22 V_501 = F_130 ( V_65 -> V_501 ) ;
T_12 V_5 = F_132 ( V_65 -> V_5 ) ;
T_22 V_531 = F_130 ( V_65 -> V_531 ) ;
T_22 V_264 = F_130 ( V_65 -> V_264 ) ;
T_13 * V_180 ;
T_22 V_532 ;
memset ( & V_272 , 0 , sizeof( V_272 ) ) ;
memset ( V_51 , 0 , sizeof( V_51 ) ) ;
V_180 = 0 ;
if ( ! V_11 ) {
F_8 ( L_1 , V_20 ) ;
return;
}
V_180 = * ( T_13 * * ) F_38 ( V_11 ) ;
F_14 ( L_171 , V_20 , V_11 -> V_27 , V_501 ) ;
switch ( V_501 ) {
case V_533 :
V_12 = V_172 ;
memcpy ( V_272 . V_181 . V_184 , & V_65 -> V_181 , V_58 ) ;
V_272 . V_181 . V_187 = V_203 ;
break;
#if V_120 > 14
case V_534 :
case V_535 :
case V_536 :
memcpy ( V_272 . V_181 . V_184 , & V_65 -> V_181 , V_58 ) ;
V_272 . V_181 . V_187 = V_203 ;
V_12 = V_537 ;
break;
case V_525 :
case V_526 :
V_12 = V_170 ;
memset ( V_272 . V_181 . V_184 , 0 , V_58 ) ;
V_272 . V_181 . V_187 = V_203 ;
memset ( & V_51 , 0 , V_58 ) ;
break;
case V_538 :
case V_539 :
V_12 = V_170 ;
if ( ! ( V_5 & V_540 ) ) {
memset ( V_272 . V_181 . V_184 , 0 , V_58 ) ;
memset ( & V_51 , 0 , V_58 ) ;
} else {
memcpy ( V_272 . V_181 . V_184 , & V_65 -> V_181 , V_58 ) ;
F_14 ( L_172 ) ;
}
V_272 . V_181 . V_187 = V_203 ;
break;
case V_541 :
V_12 = V_542 ;
if ( V_531 + 1 <= sizeof( V_51 ) ) {
V_272 . V_253 . V_105 = V_531 + 1 ;
V_51 [ 0 ] = V_541 ;
memcpy ( & V_51 [ 1 ] , V_253 , V_531 ) ;
F_14 ( L_173 ,
V_272 . V_253 . V_105 ) ;
}
break;
case V_543 :
V_12 = V_542 ;
memcpy ( & V_532 , V_253 , 4 ) ;
if ( sizeof( V_264 ) + 1 <= sizeof( V_51 ) ) {
V_272 . V_253 . V_105 = sizeof( V_264 ) + 1 ;
V_51 [ 0 ] = V_543 ;
memcpy ( & V_51 [ 1 ] , & V_264 , sizeof( V_264 ) ) ;
F_14 ( L_174 , V_264 ,
V_532 ) ;
F_14 ( L_175 ,
V_272 . V_253 . V_105 ) ;
}
break;
#endif
#if V_120 > 17
case V_544 :
{
struct V_545 * V_546 =
(struct V_545 * ) & V_51 ;
V_12 = V_173 ;
V_272 . V_253 . V_105 = sizeof( struct V_545 ) ;
if ( V_5 & V_547 )
V_546 -> V_5 |= V_548 ;
else
V_546 -> V_5 |= V_549 ;
memcpy ( V_546 -> V_550 . V_184 , & V_65 -> V_181 ,
V_58 ) ;
V_546 -> V_550 . V_187 = V_203 ;
break;
}
case V_551 :
{
if ( V_253 ) {
struct V_552 * V_553 =
(struct V_552 * ) & V_51 ;
T_28 * V_554 ;
T_29 * V_555 ;
int V_106 ;
V_12 = V_174 ;
V_554 = V_253 ;
V_106 = F_133 ( & V_554 ->
V_556 ) ;
ASSERT ( V_106 >= 0 ) ;
V_272 . V_253 . V_105 = sizeof( struct V_552 ) ;
V_555 = V_554 -> V_557 ;
while ( V_106 ) {
memset ( V_553 , 0 ,
sizeof( struct V_552 ) ) ;
if ( V_555 -> V_558 )
V_553 -> V_5 |=
V_559 ;
memcpy ( & V_553 -> V_54 . V_184 ,
& V_555 -> V_224 ,
V_58 ) ;
#ifndef F_65
F_66 ( V_11 , V_12 , & V_272 ,
V_51 ) ;
#endif
V_555 ++ ;
V_106 -- ;
}
}
return;
}
#endif
case V_261 :
#if F_74 ( F_75 )
if ( ( V_230 ) && ( V_230 -> V_231 ) &&
( V_230 -> V_255 != V_256 ) ) {
F_55 ( & V_230 -> V_257 ) ;
} else {
V_12 = V_171 ;
V_272 . V_253 . V_105 = strlen ( V_51 ) ;
F_14 ( L_176 ,
V_230 -> V_255 ) ;
}
#else
V_12 = V_171 ;
V_272 . V_253 . V_105 = strlen ( V_51 ) ;
F_14 ( L_177 ) ;
#endif
break;
case V_560 :
{
T_5 * V_52 ;
V_52 = ( T_5 * ) V_253 ;
F_8 ( L_178 ,
V_20 , V_561 ,
V_52 -> V_59 , V_52 -> V_56 ) ;
V_12 = V_542 ;
memset ( & V_272 , 0 , sizeof( V_272 ) ) ;
strcpy ( V_51 , V_561 ) ;
V_272 . V_253 . V_105 = strlen ( V_51 ) ;
}
break;
default:
F_14 ( L_179 , V_501 ) ;
break;
}
#ifndef F_65
if ( V_12 ) {
if ( V_12 == V_171 )
F_66 ( V_11 , V_12 , & V_272 , NULL ) ;
else
F_66 ( V_11 , V_12 , & V_272 , V_51 ) ;
}
#endif
#if V_120 > 14
memset ( V_51 , 0 , sizeof( V_51 ) ) ;
if ( F_129 ( V_65 , V_51 , sizeof( V_51 ) ) ) {
V_12 = V_542 ;
V_272 . V_253 . V_105 = strlen ( V_51 ) ;
#ifndef F_65
F_66 ( V_11 , V_12 , & V_272 , V_51 ) ;
#endif
}
#endif
#endif
}
int F_134 ( struct V_10 * V_11 , void * V_562 )
{
int V_563 ;
T_13 * V_180 ;
#if F_74 ( F_75 )
T_20 * V_229 = NULL ;
if ( ! V_11 )
return 0 ;
memset ( & V_70 , 0 , sizeof( V_564 ) ) ;
#ifdef V_286
V_563 =
( V_565 + F_135 ( V_566 , V_193 ) ) +
( V_567 * sizeof( T_12 ) ) +
V_568 * sizeof( T_5 ) ;
#else
V_563 =
( V_565 + F_135 ( V_566 , V_193 ) ) ;
#endif
V_229 = F_49 ( sizeof( T_20 ) , V_103 ) ;
if ( ! V_229 )
return - V_104 ;
V_229 -> V_249 = F_30 ( V_563 , V_103 ) ;
if ( ! V_229 -> V_249 ) {
F_31 ( V_229 ) ;
return - V_104 ;
}
V_229 -> V_252 = V_563 ;
V_229 -> V_231 = NULL ;
V_230 = V_229 ;
V_229 -> V_11 = V_11 ;
V_229 -> V_255 = V_256 ;
V_229 -> V_280 = 3000 ;
F_136 ( & V_229 -> V_276 ) ;
V_229 -> V_276 . V_253 = ( unsigned long ) V_229 ;
V_229 -> V_276 . V_569 = F_54 ;
F_137 ( & V_229 -> V_257 , 0 ) ;
V_229 -> V_231 = F_138 ( F_67 , V_229 ,
L_180 ) ;
if ( F_139 ( V_229 -> V_231 ) ) {
V_229 -> V_231 = NULL ;
return - V_104 ;
}
#endif
V_180 = * ( T_13 * * ) F_38 ( V_11 ) ;
V_180 -> V_570 = ( V_571 * ) V_562 ;
F_140 ( V_180 -> V_570 ) ;
F_141 () ;
#ifdef F_142
V_572 = V_11 ;
F_143 ( V_180 -> V_570 ) ;
#endif
V_341 = F_49 ( V_343 , V_103 ) ;
if ( ! V_341 )
return - V_104 ;
V_277 = 0 ;
return 0 ;
}
void F_144 ( void )
{
#if F_74 ( F_75 )
T_19 * V_25 ;
T_20 * V_229 = V_230 ;
if ( ! V_229 )
return;
if ( V_229 -> V_231 ) {
F_145 ( V_274 , V_229 -> V_231 , 1 ) ;
F_146 ( V_229 -> V_231 ) ;
V_229 -> V_231 = NULL ;
}
F_59 () ;
while ( V_229 -> V_232 ) {
V_25 = V_229 -> V_232 -> V_237 ;
F_31 ( V_229 -> V_232 ) ;
V_229 -> V_232 = V_25 ;
}
F_60 () ;
F_31 ( V_229 -> V_249 ) ;
F_31 ( V_229 ) ;
V_230 = NULL ;
#endif
F_31 ( V_341 ) ;
V_341 = NULL ;
}
void F_147 ( char * exp , char * V_573 , int line )
{
char V_574 [ 256 ] ;
char * V_575 ;
V_575 = strrchr ( V_573 , '/' ) ;
if ( V_575 )
V_575 ++ ;
if ( ! V_575 )
V_575 = V_573 ;
snprintf ( V_574 , 256 ,
L_181 , exp ,
V_575 , line ) ;
if ( ! F_148 () ) {
const int V_576 = 3 ;
F_149 ( V_577 L_182 , V_574 ) ;
F_149 ( V_577 L_183 , V_576 ) ;
F_150 ( V_578 ) ;
F_151 ( V_576 * V_281 ) ;
}
switch ( V_579 ) {
case 0 :
F_152 ( V_577 L_182 , V_574 ) ;
break;
case 1 :
F_149 ( V_577 L_182 , V_574 ) ;
F_153 () ;
break;
case 2 :
F_149 ( V_577 L_182 , V_574 ) ;
break;
default:
break;
}
}
