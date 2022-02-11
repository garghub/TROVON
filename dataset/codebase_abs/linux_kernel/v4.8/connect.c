int
F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 , * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_4 V_13 ;
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_16 ) {
F_3 ( & V_14 ) ;
return V_3 ;
} else
V_2 -> V_15 = V_17 ;
F_3 ( & V_14 ) ;
V_2 -> V_18 = 0 ;
#ifdef F_4
V_2 -> V_19 = 0 ;
#endif
F_5 ( V_20 , L_1 ) ;
F_5 ( V_20 , L_2 ,
V_21 ) ;
F_2 ( & V_22 ) ;
F_6 (tmp, &server->smb_ses_list) {
V_8 = F_7 ( V_5 , struct V_7 , V_23 ) ;
V_8 -> V_24 = true ;
V_8 -> V_25 = 0 ;
F_6 (tmp2, &ses->tcon_list) {
V_10 = F_7 ( V_6 , struct V_9 , V_26 ) ;
V_10 -> V_24 = true ;
}
}
F_3 ( & V_22 ) ;
F_5 ( V_20 , L_3 , V_21 ) ;
F_8 ( & V_2 -> V_27 ) ;
if ( V_2 -> V_28 ) {
F_5 ( V_20 , L_4 ,
V_2 -> V_28 -> V_29 , V_2 -> V_28 -> V_30 ) ;
F_9 ( V_2 -> V_28 , V_31 ) ;
F_5 ( V_20 , L_5 ,
V_2 -> V_28 -> V_29 , V_2 -> V_28 -> V_30 ) ;
F_10 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
}
V_2 -> V_32 = 0 ;
V_2 -> V_33 = false ;
F_11 ( V_2 -> V_34 . V_35 ) ;
V_2 -> V_34 . V_35 = NULL ;
V_2 -> V_34 . V_36 = 0 ;
V_2 -> V_37 = V_38 ;
F_12 ( & V_13 ) ;
F_5 ( V_20 , L_6 , V_21 ) ;
F_2 ( & V_14 ) ;
F_13 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_7 ( V_5 , struct V_11 , V_39 ) ;
if ( V_12 -> V_40 == V_41 )
V_12 -> V_40 = V_42 ;
F_14 ( & V_12 -> V_39 , & V_13 ) ;
}
F_3 ( & V_14 ) ;
F_15 ( & V_2 -> V_27 ) ;
F_5 ( V_20 , L_7 , V_21 ) ;
F_13 (tmp, tmp2, &retry_list) {
V_12 = F_7 ( V_5 , struct V_11 , V_39 ) ;
F_16 ( & V_12 -> V_39 ) ;
V_12 -> V_43 ( V_12 ) ;
}
do {
F_17 () ;
F_8 ( & V_2 -> V_27 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 ) {
F_5 ( V_20 , L_8 , V_3 ) ;
F_15 ( & V_2 -> V_27 ) ;
F_19 ( 3000 ) ;
} else {
F_20 ( & V_44 ) ;
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 != V_16 )
V_2 -> V_15 = V_45 ;
F_3 ( & V_14 ) ;
F_15 ( & V_2 -> V_27 ) ;
}
} while ( V_2 -> V_15 == V_17 );
return V_3 ;
}
static void
F_21 ( struct V_46 * V_47 )
{
int V_3 ;
struct V_1 * V_2 = F_22 ( V_47 ,
struct V_1 , V_48 . V_47 ) ;
unsigned long V_49 = V_2 -> V_49 ;
if ( V_2 -> V_15 == V_17 ||
V_2 -> V_15 == V_16 || V_2 -> V_15 == V_50 ||
( V_2 -> V_51 -> V_52 && ! V_2 -> V_51 -> V_52 ( V_2 ) ) ||
F_23 ( V_38 , V_2 -> V_37 + V_49 - V_53 ) )
goto V_54;
V_3 = V_2 -> V_51 -> V_48 ? V_2 -> V_51 -> V_48 ( V_2 ) : - V_55 ;
if ( V_3 )
F_5 ( V_20 , L_9 ,
V_2 -> V_56 ) ;
V_54:
F_24 ( V_57 , & V_2 -> V_48 , V_49 ) ;
}
static bool
F_25 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_58 ) {
V_2 -> V_58 = ( char * ) F_26 () ;
if ( ! V_2 -> V_58 ) {
F_5 ( V_59 , L_10 ) ;
F_19 ( 3000 ) ;
return false ;
}
} else if ( V_2 -> V_60 ) {
memset ( V_2 -> V_58 , 0 , F_27 ( V_2 ) ) ;
}
if ( ! V_2 -> V_61 ) {
V_2 -> V_61 = ( char * ) F_28 () ;
if ( ! V_2 -> V_61 ) {
F_5 ( V_59 , L_11 ) ;
F_19 ( 1000 ) ;
return false ;
}
} else {
memset ( V_2 -> V_61 , 0 , F_27 ( V_2 ) ) ;
}
return true ;
}
static bool
F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 == V_62 &&
F_30 ( V_38 , V_2 -> V_37 + 2 * V_2 -> V_49 ) ) {
F_5 ( V_59 , L_12 ,
V_2 -> V_56 , ( 2 * V_2 -> V_49 ) / V_53 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
return true ;
}
return false ;
}
static int
F_32 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
int V_66 = 0 ;
int V_67 ;
V_65 -> V_68 = NULL ;
V_65 -> V_69 = 0 ;
for ( V_67 = 0 ; F_33 ( V_65 ) ; V_67 += V_66 ) {
F_17 () ;
if ( F_29 ( V_2 ) )
return - V_70 ;
V_66 = F_34 ( V_2 -> V_28 , V_65 , 0 ) ;
if ( V_2 -> V_15 == V_16 )
return - V_71 ;
if ( V_2 -> V_15 == V_17 ) {
F_1 ( V_2 ) ;
return - V_70 ;
}
if ( V_66 == - V_72 ||
V_66 == - V_73 ||
V_66 == - V_74 ) {
F_35 ( 1000 , 2000 ) ;
V_66 = 0 ;
continue;
}
if ( V_66 <= 0 ) {
F_5 ( V_20 , L_13 , V_66 ) ;
F_1 ( V_2 ) ;
return - V_70 ;
}
}
return V_67 ;
}
int
F_36 ( struct V_1 * V_2 , char * V_75 ,
unsigned int V_76 )
{
struct V_64 V_65 ;
struct V_77 V_78 = { . V_79 = V_75 , . V_80 = V_76 } ;
F_37 ( & V_65 . V_81 , V_82 | V_83 , & V_78 , 1 , V_76 ) ;
return F_32 ( V_2 , & V_65 ) ;
}
int
F_38 ( struct V_1 * V_2 , struct V_84 * V_84 ,
unsigned int V_76 )
{
struct V_64 V_65 ;
struct V_85 V_86 = { . V_87 = V_84 , . V_88 = V_76 } ;
F_39 ( & V_65 . V_81 , V_82 | V_89 , & V_86 , 1 , V_76 ) ;
return F_32 ( V_2 , & V_65 ) ;
}
static bool
F_40 ( struct V_1 * V_2 , unsigned char type )
{
switch ( type ) {
case V_90 :
return true ;
case V_91 :
F_5 ( V_20 , L_14 ) ;
break;
case V_92 :
F_5 ( V_20 , L_15 ) ;
break;
case V_93 :
F_5 ( V_20 , L_16 ) ;
F_19 ( 1000 ) ;
F_41 ( (struct V_94 * ) & V_2 -> V_95 , V_96 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
break;
default:
F_5 ( V_59 , L_17 , type ) ;
F_1 ( V_2 ) ;
}
return false ;
}
void
F_42 ( struct V_11 * V_97 , bool V_98 )
{
#ifdef F_43
V_97 -> V_99 = V_38 ;
#endif
F_2 ( & V_14 ) ;
if ( ! V_98 )
V_97 -> V_40 = V_100 ;
else
V_97 -> V_40 = V_101 ;
F_16 ( & V_97 -> V_39 ) ;
F_3 ( & V_14 ) ;
}
static void
F_44 ( struct V_11 * V_97 , struct V_1 * V_2 ,
char * V_75 , int V_98 )
{
if ( V_2 -> V_51 -> V_102 &&
V_2 -> V_51 -> V_102 ( V_97 , V_2 , V_75 , V_98 ) )
return;
V_97 -> V_103 = V_75 ;
V_97 -> V_60 = V_2 -> V_60 ;
if ( ! V_97 -> V_104 ) {
if ( V_2 -> V_60 )
V_2 -> V_58 = NULL ;
else
V_2 -> V_61 = NULL ;
}
F_42 ( V_97 , V_98 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_66 ;
F_2 ( & V_22 ) ;
F_16 ( & V_2 -> V_105 ) ;
F_3 ( & V_22 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_46 ( & V_2 -> V_63 ) ;
F_2 ( & V_2 -> V_106 ) ;
if ( V_2 -> V_107 <= 0 )
V_2 -> V_107 = 1 ;
F_3 ( & V_2 -> V_106 ) ;
F_46 ( & V_2 -> V_108 ) ;
F_19 ( 125 ) ;
if ( V_2 -> V_28 ) {
F_10 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
}
if ( ! F_47 ( & V_2 -> V_109 ) ) {
struct V_4 V_110 ;
struct V_11 * V_12 ;
struct V_4 * V_5 , * V_6 ;
F_12 ( & V_110 ) ;
F_2 ( & V_14 ) ;
F_13 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_7 ( V_5 , struct V_11 , V_39 ) ;
F_5 ( V_20 , L_18 , V_12 -> V_97 ) ;
V_12 -> V_40 = V_111 ;
F_14 ( & V_12 -> V_39 , & V_110 ) ;
}
F_3 ( & V_14 ) ;
F_13 (tmp, tmp2, &dispose_list) {
V_12 = F_7 ( V_5 , struct V_11 , V_39 ) ;
F_5 ( V_20 , L_19 , V_12 -> V_97 ) ;
F_16 ( & V_12 -> V_39 ) ;
V_12 -> V_43 ( V_12 ) ;
}
F_19 ( 125 ) ;
}
if ( ! F_47 ( & V_2 -> V_109 ) ) {
F_5 ( V_20 , L_20 ) ;
F_19 ( 46000 ) ;
}
F_11 ( V_2 -> V_56 ) ;
F_11 ( V_2 ) ;
V_66 = F_48 ( & V_112 ) ;
if ( V_66 > 0 )
F_49 ( V_113 , V_66 + V_114 ) ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_11 * V_97 )
{
int V_66 ;
char * V_75 = V_2 -> V_61 ;
unsigned int V_115 = F_51 ( V_75 ) ;
if ( V_115 > V_116 + F_52 ( V_2 ) - 4 ) {
F_5 ( V_59 , L_21 , V_115 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
return - V_70 ;
}
if ( V_115 > V_117 - 4 ) {
V_2 -> V_60 = true ;
memcpy ( V_2 -> V_58 , V_75 , V_2 -> V_67 ) ;
V_75 = V_2 -> V_58 ;
}
V_66 = F_36 ( V_2 , V_75 + F_27 ( V_2 ) - 1 ,
V_115 - F_27 ( V_2 ) + 1 + 4 ) ;
if ( V_66 < 0 )
return V_66 ;
V_2 -> V_67 += V_66 ;
F_53 ( V_75 , V_2 -> V_67 ) ;
V_66 = V_2 -> V_51 -> V_118 ( V_75 , V_2 -> V_67 , V_2 ) ;
if ( V_66 != 0 )
F_54 ( L_22 , V_75 ,
F_55 (unsigned int, server->total_read, 48 ) ) ;
if ( V_2 -> V_51 -> V_119 &&
V_2 -> V_51 -> V_119 ( V_75 , V_2 , V_66 ) )
return - 1 ;
if ( ! V_97 )
return V_66 ;
F_44 ( V_97 , V_2 , V_75 , V_66 ) ;
return 0 ;
}
static int
F_56 ( void * V_120 )
{
int V_66 ;
struct V_1 * V_2 = V_120 ;
unsigned int V_115 ;
char * V_75 = NULL ;
struct V_121 * V_122 = NULL ;
struct V_11 * V_12 ;
V_123 -> V_30 |= V_124 ;
F_5 ( V_20 , L_23 , F_57 ( V_123 ) ) ;
V_66 = F_58 ( & V_112 ) ;
if ( V_66 > 1 )
F_49 ( V_113 , V_66 + V_114 ) ;
F_59 () ;
while ( V_2 -> V_15 != V_16 ) {
if ( F_17 () )
continue;
if ( ! F_25 ( V_2 ) )
continue;
V_2 -> V_60 = false ;
V_75 = V_2 -> V_61 ;
V_115 = 4 ;
V_66 = F_36 ( V_2 , V_75 , V_115 ) ;
if ( V_66 < 0 )
continue;
V_2 -> V_67 = V_66 ;
V_115 = F_51 ( V_75 ) ;
F_5 ( V_20 , L_24 , V_115 ) ;
if ( ! F_40 ( V_2 , V_75 [ 0 ] ) )
continue;
if ( V_115 < F_27 ( V_2 ) - 1 - 4 ) {
F_5 ( V_59 , L_25 ,
V_115 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
continue;
}
V_66 = F_36 ( V_2 , V_75 + 4 ,
F_27 ( V_2 ) - 1 - 4 ) ;
if ( V_66 < 0 )
continue;
V_2 -> V_67 += V_66 ;
V_12 = V_2 -> V_51 -> V_125 ( V_2 , V_75 ) ;
if ( ! V_12 || ! V_12 -> V_126 )
V_66 = F_50 ( V_2 , V_12 ) ;
else
V_66 = V_12 -> V_126 ( V_2 , V_12 ) ;
if ( V_66 < 0 )
continue;
if ( V_2 -> V_60 )
V_75 = V_2 -> V_58 ;
V_2 -> V_37 = V_38 ;
if ( V_12 != NULL ) {
if ( ! V_12 -> V_104 || V_12 -> V_127 )
V_12 -> V_43 ( V_12 ) ;
} else if ( ! V_2 -> V_51 -> V_128 ||
! V_2 -> V_51 -> V_128 ( V_75 , V_2 ) ) {
F_5 ( V_59 , L_26 ,
F_60 ( & V_129 ) ) ;
F_54 ( L_27 , V_75 ,
F_27 ( V_2 ) ) ;
#ifdef F_61
if ( V_2 -> V_51 -> V_130 )
V_2 -> V_51 -> V_130 ( V_75 ) ;
F_62 ( V_2 ) ;
#endif
}
}
F_63 ( V_2 -> V_58 ) ;
if ( V_2 -> V_61 )
F_64 ( V_2 -> V_61 ) ;
V_122 = F_65 ( & V_2 -> V_131 , NULL ) ;
F_45 ( V_2 ) ;
if ( ! V_122 ) {
F_66 ( V_132 ) ;
while ( ! F_67 ( V_123 ) ) {
F_68 () ;
F_66 ( V_132 ) ;
}
F_66 ( V_133 ) ;
}
F_69 ( 0 ) ;
}
static char *
F_70 ( const char * V_134 )
{
const char * V_135 ;
char * V_136 , * V_137 ;
unsigned int V_36 ;
V_135 = V_134 + 2 ;
V_137 = strchr ( V_135 , '\\' ) ;
if ( ! V_137 )
return F_71 ( - V_138 ) ;
V_36 = V_137 - V_135 ;
V_136 = F_72 ( ( V_36 + 1 ) , V_139 ) ;
if ( V_136 == NULL )
return F_71 ( - V_140 ) ;
memcpy ( V_136 , V_135 , V_36 ) ;
V_136 [ V_36 ] = '\0' ;
return V_136 ;
}
static int F_73 ( T_1 args [] , unsigned long * V_141 )
{
int V_3 ;
char * string ;
string = F_74 ( args ) ;
if ( string == NULL )
return - V_140 ;
V_3 = F_75 ( string , 0 , V_141 ) ;
F_11 ( string ) ;
return V_3 ;
}
static int F_76 ( T_1 args [] , T_2 * V_142 )
{
unsigned long V_143 ;
T_2 V_144 ;
int V_3 ;
V_3 = F_73 ( args , & V_143 ) ;
if ( V_3 )
return V_3 ;
V_144 = F_77 ( F_78 () , V_143 ) ;
if ( ! F_79 ( V_144 ) )
return - V_138 ;
* V_142 = V_144 ;
return 0 ;
}
static int F_80 ( T_1 args [] , T_3 * V_142 )
{
unsigned long V_143 ;
T_3 V_145 ;
int V_3 ;
V_3 = F_73 ( args , & V_143 ) ;
if ( V_3 )
return V_3 ;
V_145 = F_81 ( F_78 () , V_143 ) ;
if ( ! F_82 ( V_145 ) )
return - V_138 ;
* V_142 = V_145 ;
return 0 ;
}
static int F_83 ( char * V_143 ,
struct V_146 * V_147 )
{
T_1 args [ V_148 ] ;
V_147 -> V_149 = V_150 ;
V_147 -> V_151 = false ;
switch ( F_84 ( V_143 , V_152 , args ) ) {
case V_153 :
F_5 ( V_59 , L_28 ) ;
return 1 ;
case V_154 :
V_147 -> V_151 = true ;
case V_155 :
V_147 -> V_149 = V_156 ;
break;
case V_157 :
V_147 -> V_151 = true ;
case V_158 :
V_147 -> V_149 = V_159 ;
break;
case V_160 :
V_147 -> V_151 = true ;
case V_161 :
V_147 -> V_149 = V_162 ;
break;
case V_163 :
V_147 -> V_151 = true ;
case V_164 :
V_147 -> V_149 = V_165 ;
break;
#ifdef F_85
case V_166 :
V_147 -> V_149 = V_167 ;
break;
#endif
case V_168 :
V_147 -> V_169 = 1 ;
break;
default:
F_5 ( V_59 , L_29 , V_143 ) ;
return 1 ;
}
return 0 ;
}
static int
F_86 ( char * V_143 , struct V_146 * V_147 )
{
T_1 args [ V_148 ] ;
switch ( F_84 ( V_143 , V_170 , args ) ) {
case V_171 :
V_147 -> V_172 = false ;
V_147 -> V_173 = false ;
break;
case V_174 :
V_147 -> V_172 = false ;
V_147 -> V_173 = true ;
break;
case V_175 :
V_147 -> V_172 = true ;
V_147 -> V_173 = false ;
break;
default:
F_5 ( V_59 , L_30 , V_143 ) ;
return 1 ;
}
return 0 ;
}
static int
F_87 ( char * V_143 , struct V_146 * V_147 )
{
T_1 args [ V_148 ] ;
switch ( F_84 ( V_143 , V_176 , args ) ) {
case V_177 :
V_147 -> V_51 = & V_178 ;
V_147 -> V_179 = & V_180 ;
break;
#ifdef F_4
case V_181 :
V_147 -> V_51 = & V_182 ;
V_147 -> V_179 = & V_183 ;
break;
case V_184 :
V_147 -> V_51 = & V_185 ;
V_147 -> V_179 = & V_186 ;
break;
case V_187 :
V_147 -> V_51 = & V_188 ;
V_147 -> V_179 = & V_189 ;
break;
case V_190 :
V_147 -> V_51 = & V_188 ;
V_147 -> V_179 = & V_191 ;
break;
#ifdef F_88
case V_192 :
V_147 -> V_51 = & V_193 ;
V_147 -> V_179 = & V_194 ;
break;
#endif
#endif
default:
F_5 ( V_59 , L_31 , V_143 ) ;
return 1 ;
}
return 0 ;
}
static int
F_89 ( const char * V_195 , struct V_146 * V_147 )
{
char * V_196 ;
const char * V_197 = L_32 ;
T_4 V_36 ;
V_36 = strspn ( V_195 , V_197 ) ;
if ( V_36 != 2 )
return - V_138 ;
V_196 = strpbrk ( V_195 + 2 , V_197 ) ;
if ( ! V_196 )
return - V_138 ;
++ V_196 ;
V_36 = strcspn ( V_196 , V_197 ) ;
V_196 += V_36 ;
V_147 -> V_198 = F_90 ( V_195 , V_196 - V_195 , V_139 ) ;
if ( ! V_147 -> V_198 )
return - V_140 ;
F_91 ( V_147 -> V_198 , '\\' ) ;
if ( * V_196 == '/' || * V_196 == '\\' )
V_196 ++ ;
if ( ! * V_196 )
return 0 ;
V_147 -> V_199 = F_92 ( V_196 , V_139 ) ;
if ( ! V_147 -> V_199 )
return - V_140 ;
return 0 ;
}
static int
F_93 ( const char * V_200 , const char * V_195 ,
struct V_146 * V_147 )
{
char * V_201 , * V_202 ;
char * V_203 = NULL , * V_204 ;
unsigned int V_205 , V_206 , V_207 ;
char V_208 [ 2 ] ;
short int V_209 = - 1 ;
short int V_210 = - 1 ;
bool V_211 = false ;
bool V_212 = false ;
bool V_213 = false ;
char * V_214 = NULL ;
char * V_215 = F_94 () -> V_215 ;
char * string = NULL ;
char * V_216 , * V_143 ;
char V_137 ;
bool V_217 = false ;
unsigned short V_218 = 0 ;
struct V_94 * V_95 = (struct V_94 * ) & V_147 -> V_95 ;
V_208 [ 0 ] = ',' ;
V_208 [ 1 ] = 0 ;
V_137 = V_208 [ 0 ] ;
memset ( V_147 , 0 , sizeof( * V_147 ) ) ;
memset ( V_147 -> V_219 , 0x20 , V_220 ) ;
for ( V_206 = 0 ; V_206 < F_95 ( V_215 , V_220 ) ; V_206 ++ )
V_147 -> V_219 [ V_206 ] = toupper ( V_215 [ V_206 ] ) ;
V_147 -> V_219 [ V_220 ] = 0 ;
V_147 -> V_221 [ 0 ] = 0 ;
V_147 -> V_222 = F_96 () ;
V_147 -> V_223 = F_96 () ;
V_147 -> V_224 = F_97 () ;
V_147 -> V_225 = true ;
V_147 -> V_226 = V_147 -> V_227 = V_228 | V_229 | V_230 ;
V_147 -> V_231 = 1 ;
V_147 -> V_232 = 1 ;
V_147 -> V_173 = true ;
V_147 -> V_233 = V_234 ;
V_147 -> V_51 = & V_178 ;
V_147 -> V_179 = & V_180 ;
V_147 -> V_49 = V_235 ;
if ( ! V_200 )
goto V_236;
V_203 = F_90 ( V_200 , V_237 , V_139 ) ;
if ( ! V_203 )
goto V_236;
V_204 = V_203 ;
V_202 = V_204 + strlen ( V_204 ) ;
if ( strncmp ( V_204 , L_33 , 4 ) == 0 ) {
if ( V_204 [ 4 ] != 0 ) {
V_208 [ 0 ] = V_204 [ 4 ] ;
V_204 += 5 ;
} else {
F_5 ( V_20 , L_34 ) ;
}
}
V_147 -> V_238 = false ;
V_147 -> V_239 = false ;
switch ( F_89 ( V_195 , V_147 ) ) {
case 0 :
break;
case - V_140 :
F_5 ( V_59 , L_35 ) ;
goto V_236;
case - V_138 :
F_5 ( V_59 , L_36 ) ;
goto V_236;
default:
F_5 ( V_59 , L_37 ) ;
goto V_236;
}
while ( ( V_201 = F_98 ( & V_204 , V_208 ) ) != NULL ) {
T_1 args [ V_148 ] ;
unsigned long V_141 ;
int V_240 ;
if ( ! * V_201 )
continue;
V_240 = F_84 ( V_201 , V_241 , args ) ;
switch ( V_240 ) {
case V_242 :
break;
case V_243 :
V_147 -> V_244 = 0 ;
break;
case V_245 :
V_147 -> V_244 = 1 ;
break;
case V_246 :
V_209 = 1 ;
break;
case V_247 :
V_209 = 0 ;
break;
case V_248 :
V_210 = 1 ;
break;
case V_249 :
V_210 = 0 ;
break;
case V_250 :
V_147 -> V_251 = 1 ;
break;
case V_252 :
V_147 -> V_253 = 1 ;
break;
case V_254 :
V_147 -> V_255 = 1 ;
break;
case V_256 :
V_147 -> V_255 = 0 ;
break;
case V_257 :
V_147 -> V_258 = 0 ;
break;
case V_259 :
V_147 -> V_258 = 1 ;
break;
case V_260 :
V_147 -> V_261 = true ;
V_147 -> V_225 = false ;
break;
case V_262 :
V_147 -> V_261 = false ;
break;
case V_263 :
V_147 -> V_225 = true ;
V_147 -> V_261 = false ;
break;
case V_264 :
V_147 -> V_225 = false ;
break;
case V_265 :
V_147 -> V_266 = 1 ;
break;
case V_267 :
V_147 -> V_266 = 0 ;
break;
case V_268 :
V_147 -> V_269 = 1 ;
break;
case V_270 :
V_147 -> V_231 = 1 ;
break;
case V_271 :
V_147 -> V_231 = 0 ;
break;
case V_272 :
V_147 -> V_273 = 1 ;
break;
case V_274 :
V_147 -> V_275 = 1 ;
break;
case V_276 :
V_147 -> V_277 = 0 ;
break;
case V_278 :
V_147 -> V_277 = 1 ;
if ( V_147 -> V_227 ==
( V_279 & ~ ( V_280 | V_281 ) ) )
V_147 -> V_227 = V_279 ;
break;
case V_282 :
V_147 -> V_283 = 1 ;
break;
case V_284 :
V_147 -> V_285 = 1 ;
break;
case V_286 :
V_147 -> V_285 = 0 ;
break;
case V_287 :
V_147 -> V_288 = true ;
break;
case V_289 :
V_147 -> V_288 = false ;
break;
case V_290 :
V_147 -> V_255 = 0 ;
break;
case V_291 :
V_147 -> V_255 = 1 ;
break;
case V_292 :
V_147 -> V_293 = 0 ;
break;
case V_294 :
V_147 -> V_293 = 1 ;
break;
case V_295 :
V_147 -> V_296 = 1 ;
break;
case V_297 :
V_147 -> V_296 = 0 ;
break;
case V_298 :
V_147 -> V_232 = 1 ;
break;
case V_299 :
V_147 -> V_232 = 0 ;
break;
case V_300 :
V_147 -> V_301 = 1 ;
break;
case V_302 :
V_147 -> V_303 = 1 ;
break;
case V_304 :
V_147 -> V_303 = 0 ;
break;
case V_305 :
V_147 -> V_306 = 0 ;
break;
case V_307 :
V_147 -> V_306 = 1 ;
break;
case V_308 :
V_147 -> V_309 = 1 ;
break;
case V_310 :
V_147 -> V_151 = true ;
break;
case V_311 :
V_147 -> V_312 = 1 ;
break;
case V_313 :
F_99 ( L_38 ) ;
break;
case V_314 :
#ifndef F_100
F_5 ( V_59 , L_39 ) ;
goto V_236;
#endif
V_147 -> V_315 = true ;
break;
case V_316 :
V_147 -> V_317 = true ;
break;
case V_318 :
V_147 -> V_319 = true ;
break;
case V_320 :
V_213 = true ;
break;
case V_321 :
V_147 -> V_322 = true ;
break;
case V_323 :
V_147 -> V_324 = true ;
if ( V_147 -> V_325 ) {
F_5 ( V_59 ,
L_40 ) ;
goto V_236;
}
break;
case V_326 :
V_147 -> V_325 = true ;
if ( ( V_147 -> V_324 ) || ( V_147 -> V_327 ) ) {
F_5 ( V_59 ,
L_40 ) ;
goto V_236;
}
break;
case V_328 :
V_147 -> V_327 = true ;
if ( V_147 -> V_325 ) {
F_5 ( V_59 ,
L_40 ) ;
goto V_236;
}
break;
case V_329 :
V_147 -> V_327 = false ;
break;
case V_330 :
if ( F_76 ( args , & V_147 -> V_331 ) ) {
F_5 ( V_59 , L_41 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_238 = true ;
break;
case V_332 :
if ( F_80 ( args , & V_147 -> V_333 ) ) {
F_5 ( V_59 , L_42 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_239 = true ;
break;
case V_334 :
if ( F_76 ( args , & V_147 -> V_223 ) ) {
F_5 ( V_59 , L_43 ,
V_21 ) ;
goto V_236;
}
V_211 = true ;
break;
case V_335 :
if ( F_76 ( args , & V_147 -> V_222 ) ) {
F_5 ( V_59 , L_44 ,
V_21 ) ;
goto V_236;
}
break;
case V_336 :
if ( F_80 ( args , & V_147 -> V_224 ) ) {
F_5 ( V_59 , L_45 ,
V_21 ) ;
goto V_236;
}
V_212 = true ;
break;
case V_337 :
if ( F_73 ( args , & V_141 ) ) {
F_5 ( V_59 , L_46 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_227 = V_141 ;
break;
case V_338 :
if ( F_73 ( args , & V_141 ) ) {
F_5 ( V_59 , L_47 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_226 = V_141 ;
break;
case V_339 :
if ( F_73 ( args , & V_141 ) ||
V_141 > V_340 ) {
F_5 ( V_59 , L_48 ,
V_21 ) ;
goto V_236;
}
V_218 = ( unsigned short ) V_141 ;
break;
case V_341 :
if ( F_73 ( args , & V_141 ) ) {
F_5 ( V_59 , L_49 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_342 = V_141 ;
break;
case V_343 :
if ( F_73 ( args , & V_141 ) ) {
F_5 ( V_59 , L_50 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_344 = V_141 ;
break;
case V_345 :
if ( F_73 ( args , & V_141 ) ) {
F_5 ( V_59 , L_51 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_233 = V_53 * V_141 ;
if ( V_147 -> V_233 > V_346 ) {
F_5 ( V_59 , L_52 ) ;
goto V_236;
}
break;
case V_347 :
if ( F_73 ( args , & V_141 ) ) {
F_5 ( V_59 , L_53 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_49 = V_141 ;
break;
case V_348 :
V_147 -> V_169 = 1 ;
V_147 -> V_349 = NULL ;
break;
case V_350 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_351;
if ( F_95 ( string , V_352 ) >
V_352 ) {
F_99 ( L_54 ) ;
goto V_236;
}
F_11 ( V_147 -> V_349 ) ;
V_147 -> V_349 = F_92 ( string , V_139 ) ;
if ( ! V_147 -> V_349 )
goto V_236;
break;
case V_353 :
V_216 = strchr ( V_201 , '=' ) ;
V_216 ++ ;
if ( ! ( V_216 < V_202 && V_216 [ 1 ] == V_137 ) ) {
F_11 ( V_147 -> V_354 ) ;
V_147 -> V_354 = NULL ;
break;
}
case V_355 :
V_143 = strchr ( V_201 , '=' ) ;
V_143 ++ ;
V_216 = ( char * ) V_143 + strlen ( V_143 ) ;
if ( V_216 < V_202 && V_216 [ 1 ] == V_137 ) {
V_216 [ 0 ] = V_137 ;
while ( ( V_216 = strchr ( V_216 , V_137 ) )
!= NULL && ( V_216 [ 1 ] == V_137 ) ) {
V_216 = ( char * ) & V_216 [ 2 ] ;
}
if ( V_216 ) {
V_216 [ 0 ] = '\0' ;
V_204 = ( char * ) & V_216 [ 1 ] ;
} else
V_204 = V_202 ;
}
F_11 ( V_147 -> V_354 ) ;
V_205 = strlen ( V_143 ) ;
V_147 -> V_354 = F_101 ( V_205 + 1 , V_139 ) ;
if ( V_147 -> V_354 == NULL ) {
F_99 ( L_55 ) ;
goto V_236;
}
for ( V_206 = 0 , V_207 = 0 ; V_206 < V_205 ; V_206 ++ , V_207 ++ ) {
V_147 -> V_354 [ V_207 ] = V_143 [ V_206 ] ;
if ( ( V_143 [ V_206 ] == V_137 ) &&
V_143 [ V_206 + 1 ] == V_137 )
V_206 ++ ;
}
V_147 -> V_354 [ V_207 ] = '\0' ;
break;
case V_356 :
V_217 = false ;
break;
case V_357 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_351;
if ( ! F_102 ( V_95 , string ,
strlen ( string ) ) ) {
F_103 ( L_56 , string ) ;
goto V_236;
}
V_217 = true ;
break;
case V_358 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_351;
if ( F_95 ( string , V_359 )
== V_359 ) {
F_99 ( L_57 ) ;
goto V_236;
}
F_11 ( V_147 -> V_360 ) ;
V_147 -> V_360 = F_92 ( string , V_139 ) ;
if ( ! V_147 -> V_360 ) {
F_99 ( L_58 ) ;
goto V_236;
}
F_5 ( V_20 , L_59 ) ;
break;
case V_361 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_351;
if ( ! F_102 (
(struct V_94 * ) & V_147 -> V_362 ,
string , strlen ( string ) ) ) {
F_99 ( L_60 ,
string ) ;
goto V_236;
}
break;
case V_363 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_351;
if ( F_95 ( string , 1024 ) >= 65 ) {
F_99 ( L_61 ) ;
goto V_236;
}
if ( strncasecmp ( string , L_62 , 7 ) != 0 ) {
F_11 ( V_147 -> V_364 ) ;
V_147 -> V_364 = F_92 ( string ,
V_139 ) ;
if ( ! V_147 -> V_364 ) {
F_99 ( L_63 ) ;
goto V_236;
}
}
F_5 ( V_20 , L_64 , string ) ;
break;
case V_365 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_351;
memset ( V_147 -> V_219 , 0x20 ,
V_220 ) ;
for ( V_206 = 0 ; V_206 < V_220 ; V_206 ++ ) {
if ( string [ V_206 ] == 0 )
break;
V_147 -> V_219 [ V_206 ] = string [ V_206 ] ;
}
if ( V_206 == V_220 && string [ V_206 ] != 0 )
F_99 ( L_65 ) ;
break;
case V_366 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_351;
memset ( V_147 -> V_221 , 0x20 ,
V_367 ) ;
for ( V_206 = 0 ; V_206 < 15 ; V_206 ++ ) {
if ( string [ V_206 ] == 0 )
break;
V_147 -> V_221 [ V_206 ] = string [ V_206 ] ;
}
if ( V_206 == V_220 && string [ V_206 ] != 0 )
F_99 ( L_66 ) ;
break;
case V_368 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_351;
if ( strncasecmp ( string , L_67 , 1 ) == 0 ) {
break;
}
F_99 ( L_68 ) ;
goto V_236;
case V_369 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_351;
if ( F_87 ( string , V_147 ) != 0 )
goto V_236;
break;
case V_370 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_351;
if ( F_83 ( string , V_147 ) != 0 )
goto V_236;
break;
case V_371 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_351;
if ( F_86 ( string , V_147 ) != 0 )
goto V_236;
break;
default:
if ( ! V_214 )
V_214 = V_201 ;
break;
}
F_11 ( string ) ;
string = NULL ;
}
if ( ! V_213 && V_214 ) {
F_103 ( L_69 , V_214 ) ;
goto V_236;
}
#ifndef F_104
if ( V_147 -> V_319 ) {
F_5 ( V_59 , L_70 ) ;
goto V_236;
}
#endif
if ( ! V_147 -> V_198 ) {
F_5 ( V_59 , L_71 ) ;
goto V_236;
}
if ( ! strchr ( V_147 -> V_198 + 3 , '\\' ) ) {
F_5 ( V_59 , L_72 ) ;
goto V_236;
}
if ( ! V_217 ) {
if ( ! F_102 ( V_95 , & V_147 -> V_198 [ 2 ] ,
strlen ( & V_147 -> V_198 [ 2 ] ) ) ) {
F_103 ( L_73 ) ;
goto V_236;
}
}
F_41 ( V_95 , V_218 ) ;
if ( V_211 )
V_147 -> V_209 = V_209 ;
else if ( V_209 == 1 )
F_105 ( L_74 ) ;
if ( V_212 )
V_147 -> V_210 = V_210 ;
else if ( V_210 == 1 )
F_105 ( L_75 ) ;
F_11 ( V_203 ) ;
return 0 ;
V_351:
F_99 ( L_76 ) ;
V_236:
F_11 ( string ) ;
F_11 ( V_203 ) ;
return 1 ;
}
static bool
F_106 ( struct V_94 * V_362 , struct V_94 * V_372 )
{
switch ( V_362 -> V_373 ) {
case V_374 :
return ( V_372 -> V_373 == V_374 ) ;
case V_375 : {
struct V_376 * V_377 = (struct V_376 * ) V_362 ;
struct V_376 * V_378 = (struct V_376 * ) V_372 ;
return ( V_377 -> V_379 . V_380 == V_378 -> V_379 . V_380 ) ;
}
case V_381 : {
struct V_382 * V_383 = (struct V_382 * ) V_362 ;
struct V_382 * V_384 = (struct V_382 * ) V_372 ;
return F_107 ( & V_383 -> V_385 , & V_384 -> V_385 ) ;
}
default:
F_108 ( 1 ) ;
return false ;
}
}
static bool
F_109 ( struct V_1 * V_2 , struct V_94 * V_386 )
{
T_5 V_218 , * V_387 ;
switch ( V_386 -> V_373 ) {
case V_375 :
V_387 = & ( (struct V_376 * ) & V_2 -> V_95 ) -> V_388 ;
V_218 = ( (struct V_376 * ) V_386 ) -> V_388 ;
break;
case V_381 :
V_387 = & ( (struct V_382 * ) & V_2 -> V_95 ) -> V_389 ;
V_218 = ( (struct V_382 * ) V_386 ) -> V_389 ;
break;
default:
F_108 ( 1 ) ;
return false ;
}
if ( ! V_218 ) {
V_218 = F_110 ( V_96 ) ;
if ( V_218 == * V_387 )
return true ;
V_218 = F_110 ( V_390 ) ;
}
return V_218 == * V_387 ;
}
static bool
F_111 ( struct V_1 * V_2 , struct V_94 * V_386 ,
struct V_94 * V_362 )
{
switch ( V_386 -> V_373 ) {
case V_375 : {
struct V_376 * V_391 = (struct V_376 * ) V_386 ;
struct V_376 * V_392 =
(struct V_376 * ) & V_2 -> V_95 ;
if ( V_391 -> V_379 . V_380 != V_392 -> V_379 . V_380 )
return false ;
break;
}
case V_381 : {
struct V_382 * V_393 = (struct V_382 * ) V_386 ;
struct V_382 * V_394 =
(struct V_382 * ) & V_2 -> V_95 ;
if ( ! F_107 ( & V_393 -> V_385 ,
& V_394 -> V_385 ) )
return false ;
if ( V_393 -> V_395 != V_394 -> V_395 )
return false ;
break;
}
default:
F_108 ( 1 ) ;
return false ;
}
if ( ! F_106 ( V_362 , (struct V_94 * ) & V_2 -> V_362 ) )
return false ;
return true ;
}
static bool
F_112 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
if ( F_113 ( V_2 , V_147 -> V_149 ) == V_150 )
return false ;
if ( V_147 -> V_151 && ! V_2 -> V_151 )
return false ;
return true ;
}
static int F_114 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_94 * V_386 = (struct V_94 * ) & V_147 -> V_95 ;
if ( V_147 -> V_322 )
return 0 ;
if ( ( V_2 -> V_179 != V_147 -> V_179 ) || ( V_2 -> V_51 != V_147 -> V_51 ) )
return 0 ;
if ( ! F_115 ( F_116 ( V_2 ) , V_123 -> V_396 -> V_397 ) )
return 0 ;
if ( ! F_111 ( V_2 , V_386 ,
(struct V_94 * ) & V_147 -> V_362 ) )
return 0 ;
if ( ! F_109 ( V_2 , V_386 ) )
return 0 ;
if ( ! F_112 ( V_2 , V_147 ) )
return 0 ;
if ( V_2 -> V_49 != V_147 -> V_49 * V_53 )
return 0 ;
return 1 ;
}
static struct V_1 *
F_117 ( struct V_146 * V_147 )
{
struct V_1 * V_2 ;
F_2 ( & V_22 ) ;
F_118 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_114 ( V_2 , V_147 ) )
continue;
++ V_2 -> V_398 ;
F_3 ( & V_22 ) ;
F_5 ( V_20 , L_77 ) ;
return V_2 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_119 ( struct V_1 * V_2 )
{
struct V_121 * V_399 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_398 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_120 ( F_116 ( V_2 ) ) ;
F_16 ( & V_2 -> V_105 ) ;
F_3 ( & V_22 ) ;
F_121 ( & V_2 -> V_48 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_11 ( V_2 -> V_34 . V_35 ) ;
V_2 -> V_34 . V_35 = NULL ;
V_2 -> V_34 . V_36 = 0 ;
V_399 = F_65 ( & V_2 -> V_131 , NULL ) ;
if ( V_399 )
F_124 ( V_400 , V_399 ) ;
}
static struct V_1 *
F_125 ( struct V_146 * V_401 )
{
struct V_1 * V_402 = NULL ;
int V_3 ;
F_5 ( V_20 , L_78 , V_401 -> V_198 ) ;
V_402 = F_117 ( V_401 ) ;
if ( V_402 )
return V_402 ;
V_402 = F_101 ( sizeof( struct V_1 ) , V_139 ) ;
if ( ! V_402 ) {
V_3 = - V_140 ;
goto V_403;
}
V_402 -> V_51 = V_401 -> V_51 ;
V_402 -> V_179 = V_401 -> V_179 ;
F_126 ( V_402 , F_127 ( V_123 -> V_396 -> V_397 ) ) ;
V_402 -> V_56 = F_70 ( V_401 -> V_198 ) ;
if ( F_128 ( V_402 -> V_56 ) ) {
V_3 = F_129 ( V_402 -> V_56 ) ;
goto V_404;
}
V_402 -> V_251 = V_401 -> V_251 ;
V_402 -> V_253 = V_401 -> V_253 ;
V_402 -> V_405 = V_401 -> V_406 ;
V_402 -> V_407 = 0 ;
V_402 -> V_107 = 1 ;
F_130 ( & V_402 -> V_63 ) ;
F_130 ( & V_402 -> V_108 ) ;
F_12 ( & V_402 -> V_109 ) ;
F_131 ( & V_402 -> V_27 ) ;
memcpy ( V_402 -> V_408 ,
V_401 -> V_219 , V_367 ) ;
memcpy ( V_402 -> V_409 ,
V_401 -> V_221 , V_367 ) ;
V_402 -> V_33 = false ;
V_402 -> V_32 = 0 ;
V_402 -> V_37 = V_38 ;
F_132 ( & V_402 -> V_106 ) ;
F_12 ( & V_402 -> V_105 ) ;
F_12 ( & V_402 -> V_23 ) ;
F_133 ( & V_402 -> V_48 , F_21 ) ;
memcpy ( & V_402 -> V_362 , & V_401 -> V_362 ,
sizeof( V_402 -> V_362 ) ) ;
memcpy ( & V_402 -> V_95 , & V_401 -> V_95 ,
sizeof( V_402 -> V_95 ) ) ;
#ifdef F_4
F_134 ( V_402 -> V_410 , V_411 ) ;
#endif
V_402 -> V_15 = V_50 ;
++ V_402 -> V_398 ;
if ( V_401 -> V_49 >= V_412 &&
V_401 -> V_49 <= V_413 )
V_402 -> V_49 = V_401 -> V_49 * V_53 ;
else
V_402 -> V_49 = V_235 * V_53 ;
V_3 = F_135 ( V_402 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_79 ) ;
goto V_404;
}
F_136 ( V_414 ) ;
V_402 -> V_131 = F_137 ( F_56 ,
V_402 , L_80 ) ;
if ( F_128 ( V_402 -> V_131 ) ) {
V_3 = F_129 ( V_402 -> V_131 ) ;
F_5 ( V_59 , L_81 , V_3 ) ;
F_138 ( V_414 ) ;
goto V_404;
}
V_402 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_139 ( & V_402 -> V_105 , & V_415 ) ;
F_3 ( & V_22 ) ;
F_140 ( V_402 ) ;
F_24 ( V_57 , & V_402 -> V_48 , V_402 -> V_49 ) ;
return V_402 ;
V_404:
F_122 ( V_402 ) ;
F_120 ( F_116 ( V_402 ) ) ;
V_403:
if ( V_402 ) {
if ( ! F_128 ( V_402 -> V_56 ) )
F_11 ( V_402 -> V_56 ) ;
if ( V_402 -> V_28 )
F_10 ( V_402 -> V_28 ) ;
F_11 ( V_402 ) ;
}
return F_71 ( V_3 ) ;
}
static int F_141 ( struct V_7 * V_8 , struct V_146 * V_147 )
{
if ( V_147 -> V_149 != V_150 &&
V_147 -> V_149 != V_8 -> V_149 )
return 0 ;
switch ( V_8 -> V_149 ) {
case V_156 :
if ( ! F_142 ( V_147 -> V_222 , V_8 -> V_222 ) )
return 0 ;
break;
default:
if ( V_8 -> V_416 == NULL ) {
if ( ! V_147 -> V_169 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_416 ,
V_147 -> V_349 ? V_147 -> V_349 : L_82 ,
V_352 ) )
return 0 ;
if ( ( V_147 -> V_349 && strlen ( V_147 -> V_349 ) != 0 ) &&
V_8 -> V_354 != NULL &&
strncmp ( V_8 -> V_354 ,
V_147 -> V_354 ? V_147 -> V_354 : L_82 ,
V_417 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_143 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_7 * V_8 ;
F_2 ( & V_22 ) ;
F_118 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_8 -> V_418 == V_16 )
continue;
if ( ! F_141 ( V_8 , V_147 ) )
continue;
++ V_8 -> V_419 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_144 ( struct V_7 * V_8 )
{
unsigned int V_3 , V_420 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_20 , L_83 , V_21 , V_8 -> V_419 ) ;
F_2 ( & V_22 ) ;
if ( V_8 -> V_418 == V_16 ) {
F_3 ( & V_22 ) ;
return;
}
if ( -- V_8 -> V_419 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
if ( V_8 -> V_418 == V_62 )
V_8 -> V_418 = V_16 ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_418 == V_16 && V_2 -> V_51 -> V_421 ) {
V_420 = F_145 () ;
V_3 = V_2 -> V_51 -> V_421 ( V_420 , V_8 ) ;
if ( V_3 )
F_5 ( V_59 , L_84 ,
V_21 , V_3 ) ;
F_146 ( V_420 ) ;
}
F_2 ( & V_22 ) ;
F_16 ( & V_8 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_147 ( V_8 ) ;
F_119 ( V_2 ) ;
}
static int
F_148 ( struct V_146 * V_147 , struct V_7 * V_8 )
{
int V_3 = 0 ;
const char * V_137 , * V_422 ;
char * V_423 ;
T_6 V_36 ;
struct V_424 * V_424 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_376 * V_425 ;
struct V_382 * V_426 ;
const struct V_427 * V_428 ;
V_423 = F_72 ( V_429 , V_139 ) ;
if ( ! V_423 )
return - V_140 ;
switch ( V_2 -> V_95 . V_430 ) {
case V_375 :
V_425 = (struct V_376 * ) & V_2 -> V_95 ;
sprintf ( V_423 , L_85 , & V_425 -> V_379 . V_380 ) ;
break;
case V_381 :
V_426 = (struct V_382 * ) & V_2 -> V_95 ;
sprintf ( V_423 , L_86 , & V_426 -> V_385 . V_431 ) ;
break;
default:
F_5 ( V_20 , L_87 ,
V_2 -> V_95 . V_430 ) ;
V_3 = - V_138 ;
goto V_403;
}
F_5 ( V_20 , L_88 , V_21 , V_423 ) ;
V_424 = F_149 ( & V_432 , V_423 , L_82 ) ;
if ( F_128 ( V_424 ) ) {
if ( ! V_8 -> V_433 ) {
F_5 ( V_20 , L_89 ) ;
V_3 = F_129 ( V_424 ) ;
goto V_403;
}
sprintf ( V_423 , L_90 , V_8 -> V_433 ) ;
F_5 ( V_20 , L_88 , V_21 , V_423 ) ;
V_424 = F_149 ( & V_432 , V_423 , L_82 ) ;
if ( F_128 ( V_424 ) ) {
V_3 = F_129 ( V_424 ) ;
goto V_403;
}
}
F_150 ( & V_424 -> V_434 ) ;
V_428 = V_427 ( V_424 ) ;
if ( F_151 ( V_428 ) ) {
V_3 = V_428 ? F_129 ( V_428 ) : - V_138 ;
goto V_435;
}
V_422 = V_428 -> V_201 ;
V_137 = F_152 ( V_422 , V_428 -> V_436 , ':' ) ;
F_5 ( V_20 , L_91 , V_422 ) ;
if ( ! V_137 ) {
F_5 ( V_20 , L_92 ,
V_428 -> V_436 ) ;
V_3 = - V_138 ;
goto V_435;
}
V_36 = V_137 - V_422 ;
if ( V_36 > V_352 || V_36 <= 0 ) {
F_5 ( V_20 , L_93 ,
V_36 ) ;
V_3 = - V_138 ;
goto V_435;
}
V_147 -> V_349 = F_90 ( V_422 , V_36 , V_139 ) ;
if ( ! V_147 -> V_349 ) {
F_5 ( V_20 , L_94 ,
V_36 ) ;
V_3 = - V_140 ;
goto V_435;
}
F_5 ( V_20 , L_95 , V_21 , V_147 -> V_349 ) ;
V_36 = V_424 -> V_436 - ( V_36 + 1 ) ;
if ( V_36 > V_417 || V_36 <= 0 ) {
F_5 ( V_20 , L_96 , V_36 ) ;
V_3 = - V_138 ;
F_11 ( V_147 -> V_349 ) ;
V_147 -> V_349 = NULL ;
goto V_435;
}
++ V_137 ;
V_147 -> V_354 = F_90 ( V_137 , V_36 , V_139 ) ;
if ( ! V_147 -> V_354 ) {
F_5 ( V_20 , L_97 ,
V_36 ) ;
V_3 = - V_140 ;
F_11 ( V_147 -> V_349 ) ;
V_147 -> V_349 = NULL ;
goto V_435;
}
V_435:
F_153 ( & V_424 -> V_434 ) ;
F_154 ( V_424 ) ;
V_403:
F_11 ( V_423 ) ;
F_5 ( V_20 , L_98 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_155 ( struct V_1 * V_2 , struct V_146 * V_401 )
{
int V_3 = - V_140 ;
unsigned int V_420 ;
struct V_7 * V_8 ;
struct V_376 * V_386 = (struct V_376 * ) & V_2 -> V_95 ;
struct V_382 * V_393 = (struct V_382 * ) & V_2 -> V_95 ;
V_420 = F_145 () ;
V_8 = F_143 ( V_2 , V_401 ) ;
if ( V_8 ) {
F_5 ( V_20 , L_99 ,
V_8 -> V_418 ) ;
F_8 ( & V_8 -> V_437 ) ;
V_3 = F_156 ( V_420 , V_8 ) ;
if ( V_3 ) {
F_15 ( & V_8 -> V_437 ) ;
F_144 ( V_8 ) ;
F_157 ( V_420 ) ;
return F_71 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_5 ( V_20 , L_100 ) ;
V_3 = F_158 ( V_420 , V_8 ,
V_401 -> V_438 ) ;
if ( V_3 ) {
F_15 ( & V_8 -> V_437 ) ;
F_144 ( V_8 ) ;
F_157 ( V_420 ) ;
return F_71 ( V_3 ) ;
}
}
F_15 ( & V_8 -> V_437 ) ;
F_119 ( V_2 ) ;
F_157 ( V_420 ) ;
return V_8 ;
}
F_5 ( V_20 , L_101 ) ;
V_8 = F_159 () ;
if ( V_8 == NULL )
goto V_439;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_95 . V_430 == V_381 )
sprintf ( V_8 -> V_440 , L_102 , & V_393 -> V_385 ) ;
else
sprintf ( V_8 -> V_440 , L_103 , & V_386 -> V_379 ) ;
if ( V_401 -> V_349 ) {
V_8 -> V_416 = F_92 ( V_401 -> V_349 , V_139 ) ;
if ( ! V_8 -> V_416 )
goto V_439;
}
if ( V_401 -> V_354 ) {
V_8 -> V_354 = F_92 ( V_401 -> V_354 , V_139 ) ;
if ( ! V_8 -> V_354 )
goto V_439;
}
if ( V_401 -> V_360 ) {
V_8 -> V_433 = F_92 ( V_401 -> V_360 , V_139 ) ;
if ( ! V_8 -> V_433 )
goto V_439;
}
V_8 -> V_222 = V_401 -> V_222 ;
V_8 -> V_223 = V_401 -> V_223 ;
V_8 -> V_149 = V_401 -> V_149 ;
V_8 -> V_151 = V_401 -> V_151 ;
F_8 ( & V_8 -> V_437 ) ;
V_3 = F_156 ( V_420 , V_8 ) ;
if ( ! V_3 )
V_3 = F_158 ( V_420 , V_8 , V_401 -> V_438 ) ;
F_15 ( & V_8 -> V_437 ) ;
if ( V_3 )
goto V_439;
F_2 ( & V_22 ) ;
F_139 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_157 ( V_420 ) ;
return V_8 ;
V_439:
F_147 ( V_8 ) ;
F_157 ( V_420 ) ;
return F_71 ( V_3 ) ;
}
static int F_160 ( struct V_9 * V_10 , const char * V_134 )
{
if ( V_10 -> V_441 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_442 , V_134 , V_443 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_161 ( struct V_7 * V_8 , const char * V_134 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_22 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_26 ) ;
if ( ! F_160 ( V_10 , V_134 ) )
continue;
++ V_10 -> V_444 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_162 ( struct V_9 * V_10 )
{
unsigned int V_420 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( V_20 , L_104 , V_21 , V_10 -> V_444 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_444 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_420 = F_145 () ;
if ( V_8 -> V_2 -> V_51 -> V_445 )
V_8 -> V_2 -> V_51 -> V_445 ( V_420 , V_10 ) ;
F_146 ( V_420 ) ;
F_163 ( V_10 ) ;
F_164 ( V_10 ) ;
F_144 ( V_8 ) ;
}
static struct V_9 *
F_165 ( struct V_7 * V_8 , struct V_146 * V_401 )
{
int V_3 , V_420 ;
struct V_9 * V_10 ;
V_10 = F_161 ( V_8 , V_401 -> V_198 ) ;
if ( V_10 ) {
F_5 ( V_20 , L_105 ) ;
F_144 ( V_8 ) ;
if ( V_10 -> V_312 != V_401 -> V_312 )
F_5 ( V_59 , L_106 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_51 -> V_446 ) {
V_3 = - V_55 ;
goto V_447;
}
V_10 = F_166 () ;
if ( V_10 == NULL ) {
V_3 = - V_140 ;
goto V_447;
}
V_10 -> V_8 = V_8 ;
if ( V_401 -> V_354 ) {
V_10 -> V_354 = F_92 ( V_401 -> V_354 , V_139 ) ;
if ( ! V_10 -> V_354 ) {
V_3 = - V_140 ;
goto V_447;
}
}
V_420 = F_145 () ;
V_3 = V_8 -> V_2 -> V_51 -> V_446 ( V_420 , V_8 , V_401 -> V_198 , V_10 ,
V_401 -> V_438 ) ;
F_157 ( V_420 ) ;
F_5 ( V_20 , L_107 , V_3 ) ;
if ( V_3 )
goto V_447;
if ( V_401 -> V_269 ) {
V_10 -> V_448 &= ~ V_449 ;
F_5 ( V_20 , L_108 , V_10 -> V_448 ) ;
}
V_10 -> V_312 = V_401 -> V_312 ;
V_10 -> V_450 = false ;
if ( V_401 -> V_325 ) {
if ( V_8 -> V_2 -> V_179 -> V_451 == 0 ) {
F_5 ( V_59 ,
L_109 ) ;
V_3 = - V_452 ;
goto V_447;
#ifdef F_4
} else if ( V_8 -> V_2 -> V_453 &
V_454 )
V_10 -> V_450 = true ;
else {
F_5 ( V_59 ,
L_110 ) ;
V_3 = - V_452 ;
goto V_447;
#endif
}
#ifdef F_4
} else if ( ( V_10 -> V_453 & V_455 )
&& ( V_8 -> V_2 -> V_453 & V_454 )
&& ( V_401 -> V_324 == false ) ) {
F_5 ( V_20 , L_111 ) ;
V_10 -> V_450 = true ;
#endif
} else if ( V_401 -> V_327 ) {
if ( V_8 -> V_2 -> V_179 -> V_451 == 0 ) {
F_5 ( V_59 ,
L_112 ) ;
V_3 = - V_452 ;
goto V_447;
}
V_10 -> V_456 = true ;
}
V_10 -> V_255 = V_401 -> V_255 ;
V_10 -> V_275 = V_401 -> V_275 ;
V_10 -> V_309 = V_401 -> V_309 ;
F_12 ( & V_10 -> V_457 ) ;
F_2 ( & V_22 ) ;
F_139 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_167 ( V_10 ) ;
return V_10 ;
V_447:
F_164 ( V_10 ) ;
return F_71 ( V_3 ) ;
}
void
F_168 ( struct V_458 * V_459 )
{
if ( ! V_459 || F_128 ( V_459 ) )
return;
if ( ! F_169 ( & V_459 -> V_460 ) ||
F_170 ( V_461 , & V_459 -> V_462 ) ) {
V_459 -> V_463 = V_38 ;
return;
}
if ( ! F_128 ( F_171 ( V_459 ) ) )
F_162 ( F_171 ( V_459 ) ) ;
F_11 ( V_459 ) ;
return;
}
static inline struct V_458 *
F_172 ( struct V_464 * V_465 )
{
return V_465 -> V_466 ;
}
static int
F_173 ( struct V_467 * V_468 , struct V_469 * V_470 )
{
struct V_464 * V_471 = F_174 ( V_468 ) ;
struct V_464 * V_472 = V_470 -> V_465 ;
if ( ( V_468 -> V_473 & V_474 ) != ( V_470 -> V_30 & V_474 ) )
return 0 ;
if ( ( V_471 -> V_475 & V_476 ) !=
( V_472 -> V_475 & V_476 ) )
return 0 ;
if ( V_472 -> V_344 && V_472 -> V_344 < V_471 -> V_344 )
return 0 ;
if ( V_472 -> V_342 && V_472 -> V_342 < V_471 -> V_342 )
return 0 ;
if ( ! F_142 ( V_471 -> V_477 , V_472 -> V_477 ) || ! F_175 ( V_471 -> V_478 , V_472 -> V_478 ) )
return 0 ;
if ( V_471 -> V_479 != V_472 -> V_479 ||
V_471 -> V_480 != V_472 -> V_480 )
return 0 ;
if ( strcmp ( V_471 -> V_438 -> V_481 , V_472 -> V_438 -> V_481 ) )
return 0 ;
if ( V_471 -> V_233 != V_472 -> V_233 )
return 0 ;
return 1 ;
}
static int
F_176 ( struct V_467 * V_468 , struct V_469 * V_470 )
{
struct V_464 * V_471 = F_174 ( V_468 ) ;
struct V_464 * V_472 = V_470 -> V_465 ;
if ( V_471 -> V_475 & V_482 ) {
if ( ! ( V_472 -> V_475 & V_482 ) )
return 0 ;
if ( strcmp ( V_472 -> V_199 , V_471 -> V_199 ) )
return 0 ;
return 1 ;
}
return 0 ;
}
int
F_177 ( struct V_467 * V_468 , void * V_201 )
{
struct V_469 * V_470 = (struct V_469 * ) V_201 ;
struct V_146 * V_401 ;
struct V_464 * V_465 ;
struct V_1 * V_483 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_458 * V_459 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_465 = F_174 ( V_468 ) ;
V_459 = F_178 ( F_172 ( V_465 ) ) ;
if ( F_128 ( V_459 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_171 ( V_459 ) ;
V_8 = V_10 -> V_8 ;
V_483 = V_8 -> V_2 ;
V_401 = V_470 -> V_147 ;
if ( ! F_114 ( V_483 , V_401 ) ||
! F_141 ( V_8 , V_401 ) ||
! F_160 ( V_10 , V_401 -> V_198 ) ||
! F_176 ( V_468 , V_470 ) ) {
V_3 = 0 ;
goto V_484;
}
V_3 = F_173 ( V_468 , V_470 ) ;
V_484:
F_3 ( & V_22 ) ;
F_168 ( V_459 ) ;
return V_3 ;
}
int
F_179 ( const unsigned int V_420 , struct V_7 * V_8 , const char * V_485 ,
const struct V_486 * V_487 , unsigned int * V_488 ,
struct V_489 * * V_490 , int V_225 )
{
char * V_491 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_51 -> V_446 || ! V_8 -> V_2 -> V_51 -> V_492 )
return - V_55 ;
* V_488 = 0 ;
* V_490 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_491 = F_72 ( 2 +
F_95 ( V_8 -> V_440 , V_493 * 2 )
+ 1 + 4 + 2 , V_139 ) ;
if ( V_491 == NULL )
return - V_140 ;
V_491 [ 0 ] = '\\' ;
V_491 [ 1 ] = '\\' ;
strcpy ( V_491 + 2 , V_8 -> V_440 ) ;
strcpy ( V_491 + 2 + strlen ( V_8 -> V_440 ) , L_113 ) ;
V_3 = V_8 -> V_2 -> V_51 -> V_446 ( V_420 , V_8 , V_491 , NULL ,
V_487 ) ;
F_5 ( V_20 , L_114 , V_3 , V_8 -> V_25 ) ;
F_11 ( V_491 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_51 -> V_492 ( V_420 , V_8 , V_485 ,
V_490 , V_488 ,
V_487 , V_225 ) ;
return V_3 ;
}
static inline void
F_180 ( struct V_494 * V_495 )
{
struct V_495 * V_496 = V_495 -> V_496 ;
F_181 ( ! F_182 ( V_496 ) ) ;
F_183 ( V_496 , L_115 ,
& V_497 [ 0 ] , L_116 , & V_498 [ 0 ] ) ;
}
static inline void
F_184 ( struct V_494 * V_495 )
{
struct V_495 * V_496 = V_495 -> V_496 ;
F_181 ( ! F_182 ( V_496 ) ) ;
F_183 ( V_496 , L_117 ,
& V_497 [ 1 ] , L_118 , & V_498 [ 1 ] ) ;
}
static inline void
F_180 ( struct V_494 * V_495 )
{
}
static inline void
F_184 ( struct V_494 * V_495 )
{
}
static void F_185 ( char * V_499 , char * V_500 , unsigned int V_66 )
{
unsigned int V_206 , V_207 ;
for ( V_206 = 0 , V_207 = 0 ; V_206 < ( V_66 ) ; V_206 ++ ) {
V_499 [ V_207 ] = 'A' + ( 0x0F & ( V_500 [ V_206 ] >> 4 ) ) ;
V_499 [ V_207 + 1 ] = 'A' + ( 0x0F & V_500 [ V_206 ] ) ;
V_207 += 2 ;
}
}
static int
F_186 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_362 . V_430 != V_374 ) {
struct V_494 * V_494 = V_2 -> V_28 ;
V_3 = V_494 -> V_51 -> V_501 ( V_494 ,
(struct V_94 * ) & V_2 -> V_362 ,
sizeof( V_2 -> V_362 ) ) ;
if ( V_3 < 0 ) {
struct V_376 * V_377 ;
struct V_382 * V_383 ;
V_377 = (struct V_376 * ) & V_2 -> V_362 ;
V_383 = (struct V_382 * ) & V_2 -> V_362 ;
if ( V_383 -> V_502 == V_381 )
F_5 ( V_59 , L_119 ,
& V_383 -> V_385 , V_3 ) ;
else
F_5 ( V_59 , L_120 ,
& V_377 -> V_379 . V_380 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_187 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_503 * V_504 ;
struct V_505 * V_506 ;
V_504 = F_101 ( sizeof( struct V_503 ) ,
V_139 ) ;
if ( V_504 ) {
V_504 -> V_507 . V_508 . V_509 = 32 ;
if ( V_2 -> V_409 [ 0 ] != 0 )
F_185 ( V_504 -> V_507 .
V_508 . V_510 ,
V_2 -> V_409 ,
V_367 ) ;
else
F_185 ( V_504 -> V_507 .
V_508 . V_510 ,
V_511 ,
V_367 ) ;
V_504 -> V_507 . V_508 . V_512 = 32 ;
if ( V_2 -> V_408 [ 0 ] != 0 )
F_185 ( V_504 -> V_507 .
V_508 . V_513 ,
V_2 -> V_408 ,
V_367 ) ;
else
F_185 ( V_504 -> V_507 .
V_508 . V_513 ,
L_121 ,
V_367 ) ;
V_504 -> V_507 . V_508 . V_514 = 0 ;
V_504 -> V_507 . V_508 . V_515 = 0 ;
V_506 = (struct V_505 * ) V_504 ;
V_506 -> V_516 = F_188 ( 0x81000044 ) ;
V_3 = F_189 ( V_2 , V_506 , 0x44 ) ;
F_11 ( V_504 ) ;
F_35 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_387 ;
int V_517 , V_518 ;
struct V_494 * V_494 = V_2 -> V_28 ;
struct V_94 * V_519 ;
V_519 = (struct V_94 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_430 == V_381 ) {
V_387 = ( (struct V_382 * ) V_519 ) -> V_389 ;
V_517 = sizeof( struct V_382 ) ;
V_518 = V_381 ;
} else {
V_387 = ( (struct V_376 * ) V_519 ) -> V_388 ;
V_517 = sizeof( struct V_376 ) ;
V_518 = V_375 ;
}
if ( V_494 == NULL ) {
V_3 = F_190 ( F_116 ( V_2 ) , V_518 , V_520 ,
V_521 , & V_494 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_122 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_5 ( V_20 , L_123 ) ;
V_2 -> V_28 = V_494 ;
V_494 -> V_496 -> V_522 = V_523 ;
if ( V_518 == V_381 )
F_184 ( V_494 ) ;
else
F_180 ( V_494 ) ;
}
V_3 = F_186 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_494 -> V_496 -> V_524 = 7 * V_53 ;
V_494 -> V_496 -> V_525 = 5 * V_53 ;
if ( V_2 -> V_253 ) {
if ( V_494 -> V_496 -> V_526 < ( 200 * 1024 ) )
V_494 -> V_496 -> V_526 = 200 * 1024 ;
if ( V_494 -> V_496 -> V_527 < ( 140 * 1024 ) )
V_494 -> V_496 -> V_527 = 140 * 1024 ;
}
if ( V_2 -> V_405 ) {
int V_528 = 1 ;
V_3 = F_191 ( V_494 , V_529 , V_530 ,
( char * ) & V_528 , sizeof( V_528 ) ) ;
if ( V_3 )
F_5 ( V_20 , L_124 ,
V_3 ) ;
}
F_5 ( V_20 , L_125 ,
V_494 -> V_496 -> V_526 ,
V_494 -> V_496 -> V_527 , V_494 -> V_496 -> V_524 ) ;
V_3 = V_494 -> V_51 -> V_531 ( V_494 , V_519 , V_517 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_20 , L_126 , V_3 ) ;
F_10 ( V_494 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_387 == F_110 ( V_390 ) )
V_3 = F_187 ( V_2 ) ;
return V_3 ;
}
static int
F_135 ( struct V_1 * V_2 )
{
T_5 * V_387 ;
struct V_382 * V_393 = (struct V_382 * ) & V_2 -> V_95 ;
struct V_376 * V_386 = (struct V_376 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_430 == V_381 )
V_387 = & V_393 -> V_389 ;
else
V_387 = & V_386 -> V_388 ;
if ( * V_387 == 0 ) {
int V_3 ;
* V_387 = F_110 ( V_96 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_387 = F_110 ( V_390 ) ;
}
return F_18 ( V_2 ) ;
}
void F_192 ( unsigned int V_420 , struct V_9 * V_10 ,
struct V_464 * V_465 , struct V_146 * V_532 )
{
T_7 V_533 = F_193 ( V_10 -> V_534 . V_535 ) ;
if ( V_532 && V_532 -> V_273 ) {
V_10 -> V_534 . V_535 = 0 ;
V_10 -> V_536 = 0 ;
F_5 ( V_20 , L_127 ) ;
return;
} else if ( V_532 )
V_10 -> V_536 = 1 ;
if ( V_10 -> V_536 == 0 ) {
F_5 ( V_20 , L_128 ) ;
return;
}
if ( ! F_194 ( V_420 , V_10 ) ) {
T_7 V_537 = F_193 ( V_10 -> V_534 . V_535 ) ;
F_5 ( V_20 , L_129 , V_537 ) ;
if ( V_532 == NULL ) {
if ( ( V_533 & V_538 ) == 0 )
V_537 &= ~ V_538 ;
if ( ( V_533 & V_539 ) == 0 ) {
if ( V_537 & V_539 )
F_5 ( V_59 , L_130 ) ;
V_537 &= ~ V_539 ;
} else if ( ( V_537 & V_539 ) == 0 ) {
F_5 ( V_59 , L_131 ) ;
F_5 ( V_59 , L_132 ) ;
}
}
if ( V_537 & V_540 )
F_5 ( V_59 , L_133 ) ;
V_537 &= V_541 ;
if ( V_532 && V_532 -> V_306 )
V_537 &= ~ V_538 ;
else if ( V_538 & V_537 ) {
F_5 ( V_20 , L_134 ) ;
if ( V_465 )
V_465 -> V_475 |=
V_542 ;
}
if ( V_532 && V_532 -> V_231 == 0 )
V_537 &= ~ V_539 ;
else if ( V_537 & V_539 ) {
F_5 ( V_20 , L_135 ) ;
if ( V_465 )
V_465 -> V_475 |=
V_543 ;
}
F_5 ( V_20 , L_136 , ( int ) V_537 ) ;
#ifdef F_61
if ( V_537 & V_544 )
F_5 ( V_20 , L_137 ) ;
if ( V_537 & V_545 )
F_5 ( V_20 , L_138 ) ;
if ( V_537 & V_539 )
F_5 ( V_20 , L_139 ) ;
if ( V_537 & V_546 )
F_5 ( V_20 , L_140 ) ;
if ( V_537 & V_538 )
F_5 ( V_20 , L_141 ) ;
if ( V_537 & V_547 )
F_5 ( V_20 , L_142 ) ;
if ( V_537 & V_548 )
F_5 ( V_20 , L_143 ) ;
if ( V_537 & V_549 )
F_5 ( V_20 , L_144 ) ;
if ( V_537 & V_540 )
F_5 ( V_20 , L_145 ) ;
#endif
if ( F_195 ( V_420 , V_10 , V_537 ) ) {
if ( V_532 == NULL ) {
F_5 ( V_20 , L_146 ) ;
} else
F_5 ( V_59 , L_147 ) ;
}
}
}
int F_196 ( struct V_146 * V_550 ,
struct V_464 * V_465 )
{
F_133 ( & V_465 -> V_551 , V_552 ) ;
F_132 ( & V_465 -> V_553 ) ;
V_465 -> V_554 = V_555 ;
V_465 -> V_342 = V_550 -> V_342 ;
V_465 -> V_344 = V_550 -> V_344 ;
V_465 -> V_477 = V_550 -> V_223 ;
V_465 -> V_478 = V_550 -> V_224 ;
V_465 -> V_479 = V_550 -> V_227 ;
V_465 -> V_480 = V_550 -> V_226 ;
F_5 ( V_20 , L_148 ,
V_465 -> V_479 , V_465 -> V_480 ) ;
V_465 -> V_233 = V_550 -> V_233 ;
V_465 -> V_438 = V_550 -> V_438 ;
if ( V_550 -> V_258 )
V_465 -> V_475 |= V_556 ;
if ( V_550 -> V_285 )
V_465 -> V_475 |= V_557 ;
if ( V_550 -> V_232 )
V_465 -> V_475 |= V_558 ;
if ( V_550 -> V_225 )
V_465 -> V_475 |= V_559 ;
if ( V_550 -> V_261 )
V_465 -> V_475 |= V_560 ;
if ( V_550 -> V_244 )
V_465 -> V_475 |= V_561 ;
if ( V_550 -> V_266 )
V_465 -> V_475 |= V_562 ;
if ( V_550 -> V_277 )
V_465 -> V_475 |= V_563 ;
if ( V_550 -> V_296 )
V_465 -> V_475 |= V_564 ;
if ( V_550 -> V_283 )
V_465 -> V_475 |= V_565 ;
if ( V_550 -> V_301 )
V_465 -> V_475 |= V_566 ;
if ( V_550 -> V_303 )
V_465 -> V_475 |= V_567 ;
if ( V_550 -> V_238 ) {
V_465 -> V_475 |= V_568 ;
V_465 -> V_569 = V_550 -> V_331 ;
}
if ( V_550 -> V_239 ) {
V_465 -> V_475 |= V_570 ;
V_465 -> V_571 = V_550 -> V_333 ;
}
if ( V_550 -> V_209 )
V_465 -> V_475 |= V_572 ;
if ( V_550 -> V_210 )
V_465 -> V_475 |= V_573 ;
if ( V_550 -> V_288 )
V_465 -> V_475 |= V_574 ;
if ( V_550 -> V_315 )
V_465 -> V_475 |= V_575 ;
if ( V_550 -> V_319 )
V_465 -> V_475 |= ( V_576 |
V_556 ) ;
if ( V_550 -> V_173 )
V_465 -> V_475 |= V_577 ;
if ( V_550 -> V_172 ) {
F_5 ( V_20 , L_149 ) ;
V_465 -> V_475 |= V_578 ;
}
if ( V_550 -> V_317 ) {
if ( V_550 -> V_266 ) {
F_5 ( V_59 , L_150 ) ;
}
V_465 -> V_475 |= V_579 ;
}
if ( ( V_550 -> V_303 ) && ( V_550 -> V_288 ) )
F_5 ( V_59 , L_151 ) ;
if ( V_550 -> V_199 ) {
V_465 -> V_199 = F_92 ( V_550 -> V_199 , V_139 ) ;
if ( V_465 -> V_199 == NULL )
return - V_140 ;
}
return 0 ;
}
static void
F_197 ( struct V_146 * V_401 )
{
F_11 ( V_401 -> V_349 ) ;
F_198 ( V_401 -> V_354 ) ;
F_11 ( V_401 -> V_198 ) ;
F_11 ( V_401 -> V_360 ) ;
F_11 ( V_401 -> V_364 ) ;
F_11 ( V_401 -> V_199 ) ;
}
void
F_199 ( struct V_146 * V_401 )
{
if ( ! V_401 )
return;
F_197 ( V_401 ) ;
F_11 ( V_401 ) ;
}
static char *
F_200 ( const struct V_146 * V_147 ,
const struct V_464 * V_465 )
{
char * V_580 , * V_196 ;
unsigned int V_581 = V_147 -> V_199 ? strlen ( V_147 -> V_199 ) + 1 : 0 ;
unsigned int V_582 = F_95 ( V_147 -> V_198 , V_443 + 1 ) ;
V_580 = F_72 ( V_582 + V_581 + 1 , V_139 ) ;
if ( V_580 == NULL )
return F_71 ( - V_140 ) ;
strncpy ( V_580 , V_147 -> V_198 , V_582 ) ;
V_196 = V_580 + V_582 ;
if ( V_581 ) {
* V_196 = F_201 ( V_465 ) ;
strncpy ( V_196 + 1 , V_147 -> V_199 , V_581 ) ;
V_196 += V_581 ;
}
* V_196 = '\0' ;
F_91 ( V_580 , F_201 ( V_465 ) ) ;
F_5 ( V_20 , L_152 , V_21 , V_580 ) ;
return V_580 ;
}
static int
F_202 ( const unsigned int V_420 , struct V_7 * V_8 ,
struct V_146 * V_401 , struct V_464 * V_465 ,
int V_583 )
{
int V_3 ;
unsigned int V_488 = 0 ;
struct V_489 * V_490 = NULL ;
char * V_580 = NULL , * V_584 = NULL , * V_585 = NULL ;
V_580 = F_200 ( V_401 , V_465 ) ;
if ( F_128 ( V_580 ) )
return F_129 ( V_580 ) ;
V_584 = V_583 ? V_580 + 1 : V_401 -> V_198 + 1 ;
V_3 = F_179 ( V_420 , V_8 , V_584 , V_465 -> V_438 ,
& V_488 , & V_490 , F_203 ( V_465 ) ) ;
if ( ! V_3 && V_488 > 0 ) {
char * V_586 = NULL ;
V_585 = F_204 ( V_465 -> V_200 ,
V_580 + 1 , V_490 ,
& V_586 ) ;
F_205 ( V_490 , V_488 ) ;
if ( F_128 ( V_585 ) ) {
V_3 = F_129 ( V_585 ) ;
V_585 = NULL ;
} else {
F_197 ( V_401 ) ;
V_3 = F_206 ( V_401 , V_585 ,
V_586 ) ;
}
F_11 ( V_586 ) ;
F_11 ( V_465 -> V_200 ) ;
V_465 -> V_200 = V_585 ;
}
F_11 ( V_580 ) ;
return V_3 ;
}
static int
F_206 ( struct V_146 * V_401 , char * V_587 ,
const char * V_195 )
{
int V_3 = 0 ;
if ( F_93 ( V_587 , V_195 , V_401 ) )
return - V_138 ;
if ( V_401 -> V_169 ) {
F_5 ( V_20 , L_153 ) ;
F_11 ( V_401 -> V_349 ) ;
V_401 -> V_349 = NULL ;
} else if ( V_401 -> V_349 ) {
F_5 ( V_20 , L_154 , V_401 -> V_349 ) ;
} else {
F_5 ( V_59 , L_155 ) ;
return - V_138 ;
}
if ( V_401 -> V_364 == NULL ) {
V_401 -> V_438 = F_207 () ;
} else {
V_401 -> V_438 = F_208 ( V_401 -> V_364 ) ;
if ( V_401 -> V_438 == NULL ) {
F_5 ( V_59 , L_156 ,
V_401 -> V_364 ) ;
return - V_588 ;
}
}
return V_3 ;
}
struct V_146 *
F_209 ( char * V_587 , const char * V_195 )
{
int V_3 ;
struct V_146 * V_401 ;
V_401 = F_72 ( sizeof( struct V_146 ) , V_139 ) ;
if ( ! V_401 )
return F_71 ( - V_140 ) ;
V_3 = F_206 ( V_401 , V_587 , V_195 ) ;
if ( V_3 ) {
F_199 ( V_401 ) ;
V_401 = F_71 ( V_3 ) ;
}
return V_401 ;
}
static int
F_210 ( struct V_1 * V_2 ,
unsigned int V_420 ,
struct V_9 * V_10 ,
struct V_464 * V_465 ,
char * V_580 )
{
int V_3 ;
char * V_589 ;
char V_590 , V_5 ;
V_590 = F_201 ( V_465 ) ;
V_589 = V_580 ;
V_3 = V_2 -> V_51 -> V_591 ( V_420 , V_10 , V_465 , L_82 ) ;
while ( V_3 == 0 ) {
while ( * V_589 == V_590 )
V_589 ++ ;
if ( ! * V_589 )
break;
while ( * V_589 && * V_589 != V_590 )
V_589 ++ ;
V_5 = * V_589 ;
* V_589 = 0 ;
V_3 = V_2 -> V_51 -> V_591 ( V_420 , V_10 , V_465 ,
V_580 ) ;
* V_589 = V_5 ;
}
return V_3 ;
}
int
F_211 ( struct V_464 * V_465 , struct V_146 * V_401 )
{
int V_3 ;
unsigned int V_420 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_580 ;
struct V_458 * V_459 ;
#ifdef F_212
int V_592 = 0 ;
#endif
V_3 = F_213 ( & V_465 -> V_593 , L_157 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_212
V_594:
if ( V_592 ) {
if ( V_10 )
F_162 ( V_10 ) ;
else if ( V_8 )
F_144 ( V_8 ) ;
V_465 -> V_475 &= ~ V_543 ;
F_157 ( V_420 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_580 = NULL ;
V_459 = NULL ;
V_420 = F_145 () ;
V_2 = F_125 ( V_401 ) ;
if ( F_128 ( V_2 ) ) {
V_3 = F_129 ( V_2 ) ;
F_214 ( & V_465 -> V_593 ) ;
goto V_484;
}
V_8 = F_155 ( V_2 , V_401 ) ;
if ( F_128 ( V_8 ) ) {
V_3 = F_129 ( V_8 ) ;
V_8 = NULL ;
goto V_595;
}
#ifdef F_4
if ( ( V_401 -> V_325 == true ) && ( ( V_8 -> V_2 -> V_453 &
V_454 ) == 0 ) ) {
F_5 ( V_59 , L_158 ) ;
V_3 = - V_452 ;
goto V_595;
}
#endif
V_10 = F_165 ( V_8 , V_401 ) ;
if ( F_128 ( V_10 ) ) {
V_3 = F_129 ( V_10 ) ;
V_10 = NULL ;
goto V_596;
}
if ( F_215 ( V_10 -> V_8 ) ) {
F_192 ( V_420 , V_10 , V_465 , V_401 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_193 ( V_10 -> V_534 . V_535 ) &
V_540 ) ) {
V_3 = - V_597 ;
goto V_595;
}
} else
V_10 -> V_536 = 0 ;
if ( ! V_10 -> V_598 && V_2 -> V_51 -> V_599 )
V_2 -> V_51 -> V_599 ( V_420 , V_10 ) ;
V_465 -> V_344 = V_2 -> V_51 -> V_600 ( V_10 , V_401 ) ;
V_465 -> V_342 = V_2 -> V_51 -> V_601 ( V_10 , V_401 ) ;
V_465 -> V_593 . V_602 = V_465 -> V_342 / V_237 ;
V_596:
#ifdef F_212
if ( V_592 == 0 ) {
int V_603 = F_202 ( V_420 , V_8 , V_401 , V_465 ,
false ) ;
if ( ! V_603 ) {
V_592 ++ ;
goto V_594;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_51 -> V_591 ) {
V_3 = - V_55 ;
goto V_595;
}
V_580 = F_216 ( V_401 , V_465 , V_10 ) ;
if ( V_580 == NULL ) {
V_3 = - V_140 ;
goto V_595;
}
V_3 = V_2 -> V_51 -> V_591 ( V_420 , V_10 , V_465 ,
V_580 ) ;
if ( V_3 != 0 && V_3 != - V_604 ) {
F_11 ( V_580 ) ;
goto V_595;
}
V_3 = F_210 ( V_2 ,
V_420 , V_10 , V_465 ,
V_580 ) ;
if ( V_3 != 0 ) {
F_5 ( V_59 , L_159
L_160 ) ;
V_465 -> V_475 |= V_482 ;
V_3 = 0 ;
}
F_11 ( V_580 ) ;
}
if ( V_3 == - V_604 ) {
#ifdef F_212
if ( V_592 > V_605 ) {
V_3 = - V_606 ;
goto V_595;
}
V_3 = F_202 ( V_420 , V_8 , V_401 , V_465 , true ) ;
if ( ! V_3 ) {
V_592 ++ ;
goto V_594;
}
goto V_595;
#else
V_3 = - V_452 ;
#endif
}
if ( V_3 )
goto V_595;
V_459 = F_101 ( sizeof *V_459 , V_139 ) ;
if ( V_459 == NULL ) {
V_3 = - V_140 ;
goto V_595;
}
V_459 -> V_607 = V_8 -> V_223 ;
V_459 -> V_608 = V_10 ;
V_459 -> V_463 = V_38 ;
F_217 ( V_609 , & V_459 -> V_462 ) ;
F_217 ( V_461 , & V_459 -> V_462 ) ;
V_465 -> V_466 = V_459 ;
F_2 ( & V_465 -> V_553 ) ;
F_218 ( & V_465 -> V_554 , V_459 ) ;
F_3 ( & V_465 -> V_553 ) ;
F_24 ( V_57 , & V_465 -> V_551 ,
V_610 ) ;
V_595:
if ( V_3 ) {
if ( V_10 )
F_162 ( V_10 ) ;
else if ( V_8 )
F_144 ( V_8 ) ;
else
F_119 ( V_2 ) ;
F_214 ( & V_465 -> V_593 ) ;
}
V_484:
F_157 ( V_420 ) ;
return V_3 ;
}
int
F_219 ( const unsigned int V_420 , struct V_7 * V_8 ,
const char * V_611 , struct V_9 * V_10 ,
const struct V_486 * V_487 )
{
struct V_505 * V_612 ;
struct V_505 * V_613 ;
T_8 * V_614 ;
T_9 * V_615 ;
unsigned char * V_616 ;
int V_3 = 0 ;
int V_66 ;
T_10 V_617 , V_618 ;
if ( V_8 == NULL )
return - V_619 ;
V_612 = F_26 () ;
if ( V_612 == NULL )
return - V_140 ;
V_613 = V_612 ;
F_220 ( V_612 , V_620 ,
NULL , 4 ) ;
V_612 -> V_621 = F_221 ( V_8 -> V_2 ) ;
V_612 -> V_622 = V_8 -> V_623 ;
V_614 = ( T_8 * ) V_612 ;
V_615 = ( T_9 * ) V_613 ;
V_614 -> V_624 = 0xFF ;
V_614 -> V_448 = F_222 ( V_625 ) ;
V_616 = & V_614 -> V_626 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_627 & V_628 ) ) {
V_614 -> V_629 = F_222 ( 1 ) ;
* V_616 = 0 ;
V_616 ++ ;
} else {
V_614 -> V_629 = F_222 ( V_630 ) ;
#ifdef F_85
if ( ( V_631 & V_632 ) &&
( V_8 -> V_149 == V_167 ) )
F_223 ( V_10 -> V_354 , V_8 -> V_2 -> V_633 ,
V_8 -> V_2 -> V_627 &
V_634 ? true : false ,
V_616 ) ;
else
#endif
V_3 = F_224 ( V_10 -> V_354 , V_8 -> V_2 -> V_633 ,
V_616 , V_487 ) ;
if ( V_3 ) {
F_5 ( V_20 , L_161 ,
V_21 , V_3 ) ;
F_63 ( V_612 ) ;
return V_3 ;
}
V_616 += V_630 ;
if ( V_8 -> V_453 & V_635 ) {
* V_616 = 0 ;
V_616 ++ ;
}
}
if ( V_8 -> V_2 -> V_151 )
V_612 -> V_636 |= V_637 ;
if ( V_8 -> V_453 & V_638 ) {
V_612 -> V_636 |= V_639 ;
}
if ( V_8 -> V_453 & V_640 ) {
V_612 -> V_636 |= V_641 ;
}
if ( V_8 -> V_453 & V_635 ) {
V_612 -> V_636 |= V_642 ;
V_66 =
F_225 ( ( V_643 * ) V_616 , V_611 ,
6 *
( + 256 ) , V_487 ) ;
V_616 += 2 * V_66 ;
V_616 += 2 ;
} else {
strcpy ( V_616 , V_611 ) ;
V_616 += strlen ( V_611 ) + 1 ;
}
strcpy ( V_616 , L_162 ) ;
V_616 += strlen ( L_162 ) ;
V_616 += 1 ;
V_618 = V_616 - & V_614 -> V_626 [ 0 ] ;
V_614 -> V_644 . V_516 = F_188 ( F_226 (
V_614 -> V_644 . V_516 ) + V_618 ) ;
V_614 -> V_645 = F_222 ( V_618 ) ;
V_3 = F_227 ( V_420 , V_8 , V_612 , V_613 , & V_66 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_646 ;
V_10 -> V_441 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_647 = V_613 -> V_648 ;
V_616 = F_228 ( V_613 ) ;
V_617 = F_229 ( V_613 ) ;
V_66 = F_95 ( V_616 , V_617 - 2 ) ;
if ( V_612 -> V_636 & V_642 )
V_646 = true ;
else
V_646 = false ;
if ( V_66 == 3 ) {
if ( ( V_616 [ 0 ] == 'I' ) && ( V_616 [ 1 ] == 'P' ) &&
( V_616 [ 2 ] == 'C' ) ) {
F_5 ( V_20 , L_163 ) ;
V_10 -> V_598 = 1 ;
}
} else if ( V_66 == 2 ) {
if ( ( V_616 [ 0 ] == 'A' ) && ( V_616 [ 1 ] == ':' ) ) {
F_5 ( V_20 , L_164 ) ;
}
}
V_616 += V_66 + 1 ;
V_617 -= ( V_66 + 1 ) ;
F_230 ( V_10 -> V_442 , V_611 , sizeof( V_10 -> V_442 ) ) ;
F_11 ( V_10 -> V_649 ) ;
V_10 -> V_649 = F_231 ( V_616 ,
V_617 , V_646 ,
V_487 ) ;
F_5 ( V_20 , L_165 , V_10 -> V_649 ) ;
if ( ( V_613 -> V_650 == 3 ) ||
( V_613 -> V_650 == 7 ) )
V_10 -> V_448 = F_232 ( V_615 -> V_651 ) ;
else
V_10 -> V_448 = 0 ;
F_5 ( V_20 , L_166 , V_10 -> V_448 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_613 -> V_648 ;
}
F_63 ( V_612 ) ;
return V_3 ;
}
static void F_233 ( struct V_652 * V_120 )
{
struct V_464 * V_653 = F_22 ( V_120 , struct V_464 , V_654 ) ;
F_234 ( V_653 -> V_438 ) ;
F_11 ( V_653 ) ;
}
void
F_235 ( struct V_464 * V_465 )
{
struct V_655 * V_656 = & V_465 -> V_554 ;
struct V_657 * V_658 ;
struct V_458 * V_459 ;
F_121 ( & V_465 -> V_551 ) ;
F_2 ( & V_465 -> V_553 ) ;
while ( ( V_658 = F_236 ( V_656 ) ) ) {
V_459 = F_237 ( V_658 , struct V_458 , V_659 ) ;
F_178 ( V_459 ) ;
F_238 ( V_461 , & V_459 -> V_462 ) ;
F_239 ( V_658 , V_656 ) ;
F_3 ( & V_465 -> V_553 ) ;
F_168 ( V_459 ) ;
F_2 ( & V_465 -> V_553 ) ;
}
F_3 ( & V_465 -> V_553 ) ;
F_214 ( & V_465 -> V_593 ) ;
F_11 ( V_465 -> V_200 ) ;
F_11 ( V_465 -> V_199 ) ;
F_240 ( & V_465 -> V_654 , F_233 ) ;
}
int
F_156 ( const unsigned int V_420 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_51 -> V_660 || ! V_2 -> V_51 -> V_661 )
return - V_55 ;
if ( ! V_2 -> V_51 -> V_660 ( V_2 ) )
return 0 ;
F_241 ( V_2 , 1 ) ;
V_3 = V_2 -> V_51 -> V_661 ( V_420 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_662 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_158 ( const unsigned int V_420 , struct V_7 * V_8 ,
struct V_486 * V_663 )
{
int V_3 = - V_55 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_453 = V_2 -> V_453 ;
if ( V_664 == 0 )
V_8 -> V_453 &= ( ~ V_2 -> V_179 -> F_215 ) ;
F_5 ( V_20 , L_167 ,
V_2 -> V_627 , V_2 -> V_453 , V_2 -> V_665 ) ;
if ( V_2 -> V_51 -> V_666 )
V_3 = V_2 -> V_51 -> V_666 ( V_420 , V_8 , V_663 ) ;
if ( V_3 )
F_5 ( V_59 , L_168 , V_3 ) ;
return V_3 ;
}
static int
F_242 ( struct V_146 * V_147 , struct V_7 * V_8 )
{
V_147 -> V_149 = V_8 -> V_149 ;
if ( V_147 -> V_149 == V_156 )
return 0 ;
return F_148 ( V_147 , V_8 ) ;
}
static struct V_9 *
F_243 ( struct V_464 * V_465 , T_2 V_667 )
{
int V_3 ;
struct V_9 * V_668 = F_244 ( V_465 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_146 * V_532 ;
V_532 = F_101 ( sizeof( * V_532 ) , V_139 ) ;
if ( V_532 == NULL )
return F_71 ( - V_140 ) ;
V_532 -> V_438 = V_465 -> V_438 ;
V_532 -> V_223 = V_667 ;
V_532 -> V_222 = V_667 ;
V_532 -> V_198 = V_668 -> V_442 ;
V_532 -> V_255 = V_668 -> V_255 ;
V_532 -> V_275 = V_668 -> V_275 ;
V_532 -> V_309 = V_668 -> V_309 ;
V_532 -> V_273 = ! V_668 -> V_536 ;
V_532 -> V_149 = V_668 -> V_8 -> V_149 ;
V_532 -> V_151 = V_668 -> V_8 -> V_151 ;
V_3 = F_242 ( V_532 , V_668 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_71 ( V_3 ) ;
goto V_484;
}
F_2 ( & V_22 ) ;
++ V_668 -> V_8 -> V_2 -> V_398 ;
F_3 ( & V_22 ) ;
V_8 = F_155 ( V_668 -> V_8 -> V_2 , V_532 ) ;
if ( F_128 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_119 ( V_668 -> V_8 -> V_2 ) ;
goto V_484;
}
V_10 = F_165 ( V_8 , V_532 ) ;
if ( F_128 ( V_10 ) ) {
F_144 ( V_8 ) ;
goto V_484;
}
if ( F_215 ( V_8 ) )
F_192 ( 0 , V_10 , NULL , V_532 ) ;
V_484:
F_11 ( V_532 -> V_349 ) ;
F_11 ( V_532 -> V_354 ) ;
F_11 ( V_532 ) ;
return V_10 ;
}
struct V_9 *
F_244 ( struct V_464 * V_465 )
{
return F_171 ( F_172 ( V_465 ) ) ;
}
static struct V_458 *
F_245 ( struct V_655 * V_656 , T_2 V_144 )
{
struct V_657 * V_658 = V_656 -> V_657 ;
struct V_458 * V_459 ;
while ( V_658 ) {
V_459 = F_237 ( V_658 , struct V_458 , V_659 ) ;
if ( F_246 ( V_459 -> V_607 , V_144 ) )
V_658 = V_658 -> V_669 ;
else if ( F_247 ( V_459 -> V_607 , V_144 ) )
V_658 = V_658 -> V_670 ;
else
return V_459 ;
}
return NULL ;
}
static void
F_218 ( struct V_655 * V_656 , struct V_458 * V_671 )
{
struct V_657 * * V_472 = & ( V_656 -> V_657 ) , * V_672 = NULL ;
struct V_458 * V_459 ;
while ( * V_472 ) {
V_459 = F_237 ( * V_472 , struct V_458 , V_659 ) ;
V_672 = * V_472 ;
if ( F_246 ( V_459 -> V_607 , V_671 -> V_607 ) )
V_472 = & ( ( * V_472 ) -> V_669 ) ;
else
V_472 = & ( ( * V_472 ) -> V_670 ) ;
}
F_248 ( & V_671 -> V_659 , V_672 , V_472 ) ;
F_249 ( & V_671 -> V_659 , V_656 ) ;
}
struct V_458 *
F_250 ( struct V_464 * V_465 )
{
int V_673 ;
T_2 V_667 = F_251 () ;
struct V_458 * V_459 , * V_674 ;
if ( ! ( V_465 -> V_475 & V_576 ) )
return F_178 ( F_172 ( V_465 ) ) ;
F_2 ( & V_465 -> V_553 ) ;
V_459 = F_245 ( & V_465 -> V_554 , V_667 ) ;
if ( V_459 )
F_178 ( V_459 ) ;
F_3 ( & V_465 -> V_553 ) ;
if ( V_459 == NULL ) {
V_674 = F_101 ( sizeof( * V_459 ) , V_139 ) ;
if ( V_674 == NULL )
return F_71 ( - V_140 ) ;
V_674 -> V_607 = V_667 ;
V_674 -> V_608 = F_71 ( - V_597 ) ;
F_217 ( V_675 , & V_674 -> V_462 ) ;
F_217 ( V_461 , & V_674 -> V_462 ) ;
F_178 ( V_674 ) ;
F_2 ( & V_465 -> V_553 ) ;
V_459 = F_245 ( & V_465 -> V_554 , V_667 ) ;
if ( V_459 ) {
F_178 ( V_459 ) ;
F_3 ( & V_465 -> V_553 ) ;
F_11 ( V_674 ) ;
goto V_676;
}
V_459 = V_674 ;
F_218 ( & V_465 -> V_554 , V_459 ) ;
F_3 ( & V_465 -> V_553 ) ;
} else {
V_676:
V_673 = F_252 ( & V_459 -> V_462 , V_675 ,
V_132 ) ;
if ( V_673 ) {
F_168 ( V_459 ) ;
return F_71 ( - V_72 ) ;
}
if ( ! F_128 ( V_459 -> V_608 ) )
return V_459 ;
if ( F_23 ( V_38 , V_459 -> V_463 + V_677 ) ) {
F_168 ( V_459 ) ;
return F_71 ( - V_597 ) ;
}
if ( F_253 ( V_675 , & V_459 -> V_462 ) )
goto V_676;
}
V_459 -> V_608 = F_243 ( V_465 , V_667 ) ;
F_238 ( V_675 , & V_459 -> V_462 ) ;
F_254 ( & V_459 -> V_462 , V_675 ) ;
if ( F_128 ( V_459 -> V_608 ) ) {
F_168 ( V_459 ) ;
return F_71 ( - V_597 ) ;
}
return V_459 ;
}
static void
V_552 ( struct V_46 * V_47 )
{
struct V_464 * V_465 = F_22 ( V_47 , struct V_464 ,
V_551 . V_47 ) ;
struct V_655 * V_656 = & V_465 -> V_554 ;
struct V_657 * V_658 = F_236 ( V_656 ) ;
struct V_657 * V_5 ;
struct V_458 * V_459 ;
F_2 ( & V_465 -> V_553 ) ;
V_658 = F_236 ( V_656 ) ;
while ( V_658 != NULL ) {
V_5 = V_658 ;
V_658 = F_255 ( V_5 ) ;
V_459 = F_237 ( V_5 , struct V_458 , V_659 ) ;
if ( F_170 ( V_609 , & V_459 -> V_462 ) ||
F_60 ( & V_459 -> V_460 ) != 0 ||
F_30 ( V_459 -> V_463 + V_610 , V_38 ) )
continue;
F_178 ( V_459 ) ;
F_238 ( V_461 , & V_459 -> V_462 ) ;
F_239 ( V_5 , V_656 ) ;
F_3 ( & V_465 -> V_553 ) ;
F_168 ( V_459 ) ;
F_2 ( & V_465 -> V_553 ) ;
}
F_3 ( & V_465 -> V_553 ) ;
F_24 ( V_57 , & V_465 -> V_551 ,
V_610 ) ;
}
