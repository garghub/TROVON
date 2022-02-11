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
if ( V_2 -> V_15 == V_45 )
F_21 ( V_46 , & V_2 -> V_47 , 0 ) ;
return V_3 ;
}
static void
F_22 ( struct V_48 * V_49 )
{
int V_3 ;
struct V_1 * V_2 = F_23 ( V_49 ,
struct V_1 , V_47 . V_49 ) ;
unsigned long V_50 ;
if ( V_2 -> V_15 == V_45 )
V_50 = 0 ;
else
V_50 = V_2 -> V_50 ;
if ( V_2 -> V_15 == V_17 ||
V_2 -> V_15 == V_16 ||
V_2 -> V_15 == V_51 ||
( V_2 -> V_52 -> V_53 && ! V_2 -> V_52 -> V_53 ( V_2 ) ) ||
F_24 ( V_38 , V_2 -> V_37 + V_50 - V_54 ) )
goto V_55;
V_3 = V_2 -> V_52 -> V_47 ? V_2 -> V_52 -> V_47 ( V_2 ) : - V_56 ;
if ( V_3 )
F_5 ( V_20 , L_9 ,
V_2 -> V_57 ) ;
V_55:
F_25 ( V_46 , & V_2 -> V_47 , V_2 -> V_50 ) ;
}
static bool
F_26 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_58 ) {
V_2 -> V_58 = ( char * ) F_27 () ;
if ( ! V_2 -> V_58 ) {
F_5 ( V_59 , L_10 ) ;
F_19 ( 3000 ) ;
return false ;
}
} else if ( V_2 -> V_60 ) {
memset ( V_2 -> V_58 , 0 , F_28 ( V_2 ) ) ;
}
if ( ! V_2 -> V_61 ) {
V_2 -> V_61 = ( char * ) F_29 () ;
if ( ! V_2 -> V_61 ) {
F_5 ( V_59 , L_11 ) ;
F_19 ( 1000 ) ;
return false ;
}
} else {
memset ( V_2 -> V_61 , 0 , F_28 ( V_2 ) ) ;
}
return true ;
}
static bool
F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 == V_62 &&
F_31 ( V_38 , V_2 -> V_37 + 2 * V_2 -> V_50 ) ) {
F_5 ( V_59 , L_12 ,
V_2 -> V_57 , ( 2 * V_2 -> V_50 ) / V_54 ) ;
F_1 ( V_2 ) ;
F_32 ( & V_2 -> V_63 ) ;
return true ;
}
return false ;
}
static int
F_33 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
int V_66 = 0 ;
int V_67 ;
V_65 -> V_68 = NULL ;
V_65 -> V_69 = 0 ;
for ( V_67 = 0 ; F_34 ( V_65 ) ; V_67 += V_66 ) {
F_17 () ;
if ( F_30 ( V_2 ) )
return - V_70 ;
V_66 = F_35 ( V_2 -> V_28 , V_65 , 0 ) ;
if ( V_2 -> V_15 == V_16 )
return - V_71 ;
if ( V_2 -> V_15 == V_17 ) {
F_1 ( V_2 ) ;
return - V_70 ;
}
if ( V_66 == - V_72 ||
V_66 == - V_73 ||
V_66 == - V_74 ) {
F_36 ( 1000 , 2000 ) ;
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
F_37 ( struct V_1 * V_2 , char * V_75 ,
unsigned int V_76 )
{
struct V_64 V_65 ;
struct V_77 V_78 = { . V_79 = V_75 , . V_80 = V_76 } ;
F_38 ( & V_65 . V_81 , V_82 | V_83 , & V_78 , 1 , V_76 ) ;
return F_33 ( V_2 , & V_65 ) ;
}
int
F_39 ( struct V_1 * V_2 , struct V_84 * V_84 ,
unsigned int V_76 )
{
struct V_64 V_65 ;
struct V_85 V_86 = { . V_87 = V_84 , . V_88 = V_76 } ;
F_40 ( & V_65 . V_81 , V_82 | V_89 , & V_86 , 1 , V_76 ) ;
return F_33 ( V_2 , & V_65 ) ;
}
static bool
F_41 ( struct V_1 * V_2 , unsigned char type )
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
F_42 ( (struct V_94 * ) & V_2 -> V_95 , V_96 ) ;
F_1 ( V_2 ) ;
F_32 ( & V_2 -> V_63 ) ;
break;
default:
F_5 ( V_59 , L_17 , type ) ;
F_1 ( V_2 ) ;
}
return false ;
}
void
F_43 ( struct V_11 * V_97 , bool V_98 )
{
#ifdef F_44
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
F_45 ( struct V_11 * V_97 , struct V_1 * V_2 ,
char * V_75 , int V_98 )
{
if ( V_2 -> V_52 -> V_102 &&
V_2 -> V_52 -> V_102 ( V_97 , V_2 , V_75 , V_98 ) )
return;
V_97 -> V_103 = V_75 ;
V_97 -> V_60 = V_2 -> V_60 ;
if ( ! V_97 -> V_104 ) {
if ( V_2 -> V_60 )
V_2 -> V_58 = NULL ;
else
V_2 -> V_61 = NULL ;
}
F_43 ( V_97 , V_98 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_66 ;
F_2 ( & V_22 ) ;
F_16 ( & V_2 -> V_105 ) ;
F_3 ( & V_22 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_47 ( & V_2 -> V_63 ) ;
F_2 ( & V_2 -> V_106 ) ;
if ( V_2 -> V_107 <= 0 )
V_2 -> V_107 = 1 ;
F_3 ( & V_2 -> V_106 ) ;
F_47 ( & V_2 -> V_108 ) ;
F_19 ( 125 ) ;
if ( V_2 -> V_28 ) {
F_10 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
}
if ( ! F_48 ( & V_2 -> V_109 ) ) {
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
if ( ! F_48 ( & V_2 -> V_109 ) ) {
F_5 ( V_20 , L_20 ) ;
F_19 ( 46000 ) ;
}
F_11 ( V_2 -> V_57 ) ;
F_11 ( V_2 ) ;
V_66 = F_49 ( & V_112 ) ;
if ( V_66 > 0 )
F_50 ( V_113 , V_66 + V_114 ) ;
}
static int
F_51 ( struct V_1 * V_2 , struct V_11 * V_97 )
{
int V_66 ;
char * V_75 = V_2 -> V_61 ;
unsigned int V_115 = F_52 ( V_75 ) ;
if ( V_115 > V_116 + F_53 ( V_2 ) - 4 ) {
F_5 ( V_59 , L_21 , V_115 ) ;
F_1 ( V_2 ) ;
F_32 ( & V_2 -> V_63 ) ;
return - V_70 ;
}
if ( V_115 > V_117 - 4 ) {
V_2 -> V_60 = true ;
memcpy ( V_2 -> V_58 , V_75 , V_2 -> V_67 ) ;
V_75 = V_2 -> V_58 ;
}
V_66 = F_37 ( V_2 , V_75 + F_28 ( V_2 ) - 1 ,
V_115 - F_28 ( V_2 ) + 1 + 4 ) ;
if ( V_66 < 0 )
return V_66 ;
V_2 -> V_67 += V_66 ;
F_54 ( V_75 , V_2 -> V_67 ) ;
V_66 = V_2 -> V_52 -> V_118 ( V_75 , V_2 -> V_67 , V_2 ) ;
if ( V_66 != 0 )
F_55 ( L_22 , V_75 ,
F_56 (unsigned int, server->total_read, 48 ) ) ;
if ( V_2 -> V_52 -> V_119 &&
V_2 -> V_52 -> V_119 ( V_75 , V_2 , V_66 ) )
return - 1 ;
if ( ! V_97 )
return V_66 ;
F_45 ( V_97 , V_2 , V_75 , V_66 ) ;
return 0 ;
}
static int
F_57 ( void * V_120 )
{
int V_66 ;
struct V_1 * V_2 = V_120 ;
unsigned int V_115 ;
char * V_75 = NULL ;
struct V_121 * V_122 = NULL ;
struct V_11 * V_12 ;
V_123 -> V_30 |= V_124 ;
F_5 ( V_20 , L_23 , F_58 ( V_123 ) ) ;
V_66 = F_59 ( & V_112 ) ;
if ( V_66 > 1 )
F_50 ( V_113 , V_66 + V_114 ) ;
F_60 () ;
while ( V_2 -> V_15 != V_16 ) {
if ( F_17 () )
continue;
if ( ! F_26 ( V_2 ) )
continue;
V_2 -> V_60 = false ;
V_75 = V_2 -> V_61 ;
V_115 = 4 ;
V_66 = F_37 ( V_2 , V_75 , V_115 ) ;
if ( V_66 < 0 )
continue;
V_2 -> V_67 = V_66 ;
V_115 = F_52 ( V_75 ) ;
F_5 ( V_20 , L_24 , V_115 ) ;
if ( ! F_41 ( V_2 , V_75 [ 0 ] ) )
continue;
if ( V_115 < F_28 ( V_2 ) - 1 - 4 ) {
F_5 ( V_59 , L_25 ,
V_115 ) ;
F_1 ( V_2 ) ;
F_32 ( & V_2 -> V_63 ) ;
continue;
}
V_66 = F_37 ( V_2 , V_75 + 4 ,
F_28 ( V_2 ) - 1 - 4 ) ;
if ( V_66 < 0 )
continue;
V_2 -> V_67 += V_66 ;
V_12 = V_2 -> V_52 -> V_125 ( V_2 , V_75 ) ;
if ( ! V_12 || ! V_12 -> V_126 )
V_66 = F_51 ( V_2 , V_12 ) ;
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
} else if ( ! V_2 -> V_52 -> V_128 ||
! V_2 -> V_52 -> V_128 ( V_75 , V_2 ) ) {
F_5 ( V_59 , L_26 ,
F_61 ( & V_129 ) ) ;
F_55 ( L_27 , V_75 ,
F_28 ( V_2 ) ) ;
#ifdef F_62
if ( V_2 -> V_52 -> V_130 )
V_2 -> V_52 -> V_130 ( V_75 ) ;
F_63 ( V_2 ) ;
#endif
}
}
F_64 ( V_2 -> V_58 ) ;
if ( V_2 -> V_61 )
F_65 ( V_2 -> V_61 ) ;
V_122 = F_66 ( & V_2 -> V_131 , NULL ) ;
F_46 ( V_2 ) ;
if ( ! V_122 ) {
F_67 ( V_132 ) ;
while ( ! F_68 ( V_123 ) ) {
F_69 () ;
F_67 ( V_132 ) ;
}
F_67 ( V_133 ) ;
}
F_70 ( 0 ) ;
}
static char *
F_71 ( const char * V_134 )
{
const char * V_135 ;
char * V_136 , * V_137 ;
unsigned int V_36 ;
V_135 = V_134 + 2 ;
V_137 = strchr ( V_135 , '\\' ) ;
if ( ! V_137 )
return F_72 ( - V_138 ) ;
V_36 = V_137 - V_135 ;
V_136 = F_73 ( ( V_36 + 1 ) , V_139 ) ;
if ( V_136 == NULL )
return F_72 ( - V_140 ) ;
memcpy ( V_136 , V_135 , V_36 ) ;
V_136 [ V_36 ] = '\0' ;
return V_136 ;
}
static int F_74 ( T_1 args [] , unsigned long * V_141 )
{
int V_3 ;
char * string ;
string = F_75 ( args ) ;
if ( string == NULL )
return - V_140 ;
V_3 = F_76 ( string , 0 , V_141 ) ;
F_11 ( string ) ;
return V_3 ;
}
static int F_77 ( T_1 args [] , T_2 * V_142 )
{
unsigned long V_143 ;
T_2 V_144 ;
int V_3 ;
V_3 = F_74 ( args , & V_143 ) ;
if ( V_3 )
return V_3 ;
V_144 = F_78 ( F_79 () , V_143 ) ;
if ( ! F_80 ( V_144 ) )
return - V_138 ;
* V_142 = V_144 ;
return 0 ;
}
static int F_81 ( T_1 args [] , T_3 * V_142 )
{
unsigned long V_143 ;
T_3 V_145 ;
int V_3 ;
V_3 = F_74 ( args , & V_143 ) ;
if ( V_3 )
return V_3 ;
V_145 = F_82 ( F_79 () , V_143 ) ;
if ( ! F_83 ( V_145 ) )
return - V_138 ;
* V_142 = V_145 ;
return 0 ;
}
static int F_84 ( char * V_143 ,
struct V_146 * V_147 )
{
T_1 args [ V_148 ] ;
V_147 -> V_149 = V_150 ;
V_147 -> V_151 = false ;
switch ( F_85 ( V_143 , V_152 , args ) ) {
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
#ifdef F_86
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
F_87 ( char * V_143 , struct V_146 * V_147 )
{
T_1 args [ V_148 ] ;
switch ( F_85 ( V_143 , V_170 , args ) ) {
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
F_88 ( char * V_143 , struct V_146 * V_147 )
{
T_1 args [ V_148 ] ;
switch ( F_85 ( V_143 , V_176 , args ) ) {
case V_177 :
V_147 -> V_52 = & V_178 ;
V_147 -> V_179 = & V_180 ;
break;
#ifdef F_4
case V_181 :
V_147 -> V_52 = & V_182 ;
V_147 -> V_179 = & V_183 ;
break;
case V_184 :
V_147 -> V_52 = & V_185 ;
V_147 -> V_179 = & V_186 ;
break;
case V_187 :
V_147 -> V_52 = & V_188 ;
V_147 -> V_179 = & V_189 ;
break;
case V_190 :
V_147 -> V_52 = & V_188 ;
V_147 -> V_179 = & V_191 ;
break;
#ifdef F_89
case V_192 :
V_147 -> V_52 = & V_193 ;
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
F_90 ( const char * V_195 , struct V_146 * V_147 )
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
V_147 -> V_198 = F_91 ( V_195 , V_196 - V_195 , V_139 ) ;
if ( ! V_147 -> V_198 )
return - V_140 ;
F_92 ( V_147 -> V_198 , '\\' ) ;
if ( * V_196 == '/' || * V_196 == '\\' )
V_196 ++ ;
if ( ! * V_196 )
return 0 ;
V_147 -> V_199 = F_93 ( V_196 , V_139 ) ;
if ( ! V_147 -> V_199 )
return - V_140 ;
return 0 ;
}
static int
F_94 ( const char * V_200 , const char * V_195 ,
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
char * V_215 = F_95 () -> V_215 ;
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
for ( V_206 = 0 ; V_206 < F_96 ( V_215 , V_220 ) ; V_206 ++ )
V_147 -> V_219 [ V_206 ] = toupper ( V_215 [ V_206 ] ) ;
V_147 -> V_219 [ V_220 ] = 0 ;
V_147 -> V_221 [ 0 ] = 0 ;
V_147 -> V_222 = F_97 () ;
V_147 -> V_223 = F_97 () ;
V_147 -> V_224 = F_98 () ;
V_147 -> V_225 = true ;
V_147 -> V_226 = V_147 -> V_227 = V_228 | V_229 | V_230 ;
V_147 -> V_231 = 1 ;
V_147 -> V_232 = 1 ;
V_147 -> V_173 = true ;
V_147 -> V_233 = V_234 ;
V_147 -> V_52 = & V_178 ;
V_147 -> V_179 = & V_180 ;
V_147 -> V_50 = V_235 ;
if ( ! V_200 )
goto V_236;
V_203 = F_91 ( V_200 , V_237 , V_139 ) ;
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
switch ( F_90 ( V_195 , V_147 ) ) {
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
while ( ( V_201 = F_99 ( & V_204 , V_208 ) ) != NULL ) {
T_1 args [ V_148 ] ;
unsigned long V_141 ;
int V_240 ;
if ( ! * V_201 )
continue;
V_240 = F_85 ( V_201 , V_241 , args ) ;
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
V_147 -> V_288 = 1 ;
break;
case V_289 :
V_147 -> V_290 = true ;
break;
case V_291 :
V_147 -> V_290 = false ;
break;
case V_292 :
V_147 -> V_255 = 0 ;
break;
case V_293 :
V_147 -> V_255 = 1 ;
break;
case V_294 :
V_147 -> V_295 = 0 ;
break;
case V_296 :
V_147 -> V_295 = 1 ;
break;
case V_297 :
V_147 -> V_298 = 1 ;
break;
case V_299 :
V_147 -> V_298 = 0 ;
break;
case V_300 :
V_147 -> V_232 = 1 ;
break;
case V_301 :
V_147 -> V_232 = 0 ;
break;
case V_302 :
V_147 -> V_303 = 1 ;
break;
case V_304 :
V_147 -> V_305 = 1 ;
break;
case V_306 :
V_147 -> V_305 = 0 ;
break;
case V_307 :
V_147 -> V_308 = 0 ;
break;
case V_309 :
V_147 -> V_308 = 1 ;
break;
case V_310 :
V_147 -> V_311 = 1 ;
break;
case V_312 :
V_147 -> V_151 = true ;
break;
case V_313 :
V_147 -> V_314 = 1 ;
break;
case V_315 :
F_100 ( L_38 ) ;
break;
case V_316 :
#ifndef F_101
F_5 ( V_59 , L_39 ) ;
goto V_236;
#endif
V_147 -> V_317 = true ;
break;
case V_318 :
V_147 -> V_319 = true ;
break;
case V_320 :
V_147 -> V_321 = true ;
break;
case V_322 :
V_213 = true ;
break;
case V_323 :
V_147 -> V_324 = true ;
break;
case V_325 :
V_147 -> V_326 = true ;
if ( V_147 -> V_327 ) {
F_5 ( V_59 ,
L_40 ) ;
goto V_236;
}
break;
case V_328 :
V_147 -> V_327 = true ;
if ( ( V_147 -> V_326 ) || ( V_147 -> V_329 ) ) {
F_5 ( V_59 ,
L_40 ) ;
goto V_236;
}
break;
case V_330 :
V_147 -> V_329 = true ;
if ( V_147 -> V_327 ) {
F_5 ( V_59 ,
L_40 ) ;
goto V_236;
}
break;
case V_331 :
V_147 -> V_329 = false ;
break;
case V_332 :
V_147 -> V_333 = true ;
break;
case V_334 :
if ( F_77 ( args , & V_147 -> V_335 ) ) {
F_5 ( V_59 , L_41 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_238 = true ;
break;
case V_336 :
if ( F_81 ( args , & V_147 -> V_337 ) ) {
F_5 ( V_59 , L_42 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_239 = true ;
break;
case V_338 :
if ( F_77 ( args , & V_147 -> V_223 ) ) {
F_5 ( V_59 , L_43 ,
V_21 ) ;
goto V_236;
}
V_211 = true ;
break;
case V_339 :
if ( F_77 ( args , & V_147 -> V_222 ) ) {
F_5 ( V_59 , L_44 ,
V_21 ) ;
goto V_236;
}
break;
case V_340 :
if ( F_81 ( args , & V_147 -> V_224 ) ) {
F_5 ( V_59 , L_45 ,
V_21 ) ;
goto V_236;
}
V_212 = true ;
break;
case V_341 :
if ( F_74 ( args , & V_141 ) ) {
F_5 ( V_59 , L_46 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_227 = V_141 ;
break;
case V_342 :
if ( F_74 ( args , & V_141 ) ) {
F_5 ( V_59 , L_47 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_226 = V_141 ;
break;
case V_343 :
if ( F_74 ( args , & V_141 ) ||
V_141 > V_344 ) {
F_5 ( V_59 , L_48 ,
V_21 ) ;
goto V_236;
}
V_218 = ( unsigned short ) V_141 ;
break;
case V_345 :
if ( F_74 ( args , & V_141 ) ) {
F_5 ( V_59 , L_49 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_346 = V_141 ;
break;
case V_347 :
if ( F_74 ( args , & V_141 ) ) {
F_5 ( V_59 , L_50 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_348 = V_141 ;
break;
case V_349 :
if ( F_74 ( args , & V_141 ) ) {
F_5 ( V_59 , L_51 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_233 = V_54 * V_141 ;
if ( V_147 -> V_233 > V_350 ) {
F_5 ( V_59 , L_52 ) ;
goto V_236;
}
break;
case V_351 :
if ( F_74 ( args , & V_141 ) ) {
F_5 ( V_59 , L_53 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_50 = V_141 ;
break;
case V_352 :
if ( F_74 ( args , & V_141 ) ) {
F_5 ( V_59 , L_54 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_353 = V_141 ;
break;
case V_354 :
if ( F_74 ( args , & V_141 ) || ( V_141 < 20 ) ||
( V_141 > 60000 ) ) {
F_5 ( V_59 , L_55 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_355 = V_141 ;
break;
case V_356 :
V_147 -> V_169 = 1 ;
V_147 -> V_357 = NULL ;
break;
case V_358 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_359;
if ( F_96 ( string , V_360 ) >
V_360 ) {
F_100 ( L_56 ) ;
goto V_236;
}
F_11 ( V_147 -> V_357 ) ;
V_147 -> V_357 = F_93 ( string , V_139 ) ;
if ( ! V_147 -> V_357 )
goto V_236;
break;
case V_361 :
V_216 = strchr ( V_201 , '=' ) ;
V_216 ++ ;
if ( ! ( V_216 < V_202 && V_216 [ 1 ] == V_137 ) ) {
F_11 ( V_147 -> V_362 ) ;
V_147 -> V_362 = NULL ;
break;
}
case V_363 :
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
F_11 ( V_147 -> V_362 ) ;
V_205 = strlen ( V_143 ) ;
V_147 -> V_362 = F_102 ( V_205 + 1 , V_139 ) ;
if ( V_147 -> V_362 == NULL ) {
F_100 ( L_57 ) ;
goto V_236;
}
for ( V_206 = 0 , V_207 = 0 ; V_206 < V_205 ; V_206 ++ , V_207 ++ ) {
V_147 -> V_362 [ V_207 ] = V_143 [ V_206 ] ;
if ( ( V_143 [ V_206 ] == V_137 ) &&
V_143 [ V_206 + 1 ] == V_137 )
V_206 ++ ;
}
V_147 -> V_362 [ V_207 ] = '\0' ;
break;
case V_364 :
V_217 = false ;
break;
case V_365 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_359;
if ( ! F_103 ( V_95 , string ,
strlen ( string ) ) ) {
F_104 ( L_58 , string ) ;
goto V_236;
}
V_217 = true ;
break;
case V_366 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_359;
if ( F_96 ( string , V_367 )
== V_367 ) {
F_100 ( L_59 ) ;
goto V_236;
}
F_11 ( V_147 -> V_368 ) ;
V_147 -> V_368 = F_93 ( string , V_139 ) ;
if ( ! V_147 -> V_368 ) {
F_100 ( L_60 ) ;
goto V_236;
}
F_5 ( V_20 , L_61 ) ;
break;
case V_369 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_359;
if ( ! F_103 (
(struct V_94 * ) & V_147 -> V_370 ,
string , strlen ( string ) ) ) {
F_100 ( L_62 ,
string ) ;
goto V_236;
}
break;
case V_371 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_359;
if ( F_96 ( string , 1024 ) >= 65 ) {
F_100 ( L_63 ) ;
goto V_236;
}
if ( strncasecmp ( string , L_64 , 7 ) != 0 ) {
F_11 ( V_147 -> V_372 ) ;
V_147 -> V_372 = F_93 ( string ,
V_139 ) ;
if ( ! V_147 -> V_372 ) {
F_100 ( L_65 ) ;
goto V_236;
}
}
F_5 ( V_20 , L_66 , string ) ;
break;
case V_373 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_359;
memset ( V_147 -> V_219 , 0x20 ,
V_220 ) ;
for ( V_206 = 0 ; V_206 < V_220 ; V_206 ++ ) {
if ( string [ V_206 ] == 0 )
break;
V_147 -> V_219 [ V_206 ] = string [ V_206 ] ;
}
if ( V_206 == V_220 && string [ V_206 ] != 0 )
F_100 ( L_67 ) ;
break;
case V_374 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_359;
memset ( V_147 -> V_221 , 0x20 ,
V_375 ) ;
for ( V_206 = 0 ; V_206 < 15 ; V_206 ++ ) {
if ( string [ V_206 ] == 0 )
break;
V_147 -> V_221 [ V_206 ] = string [ V_206 ] ;
}
if ( V_206 == V_220 && string [ V_206 ] != 0 )
F_100 ( L_68 ) ;
break;
case V_376 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_359;
if ( strncasecmp ( string , L_69 , 1 ) == 0 ) {
break;
}
F_100 ( L_70 ) ;
goto V_236;
case V_377 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_359;
if ( F_88 ( string , V_147 ) != 0 )
goto V_236;
break;
case V_378 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_359;
if ( F_84 ( string , V_147 ) != 0 )
goto V_236;
break;
case V_379 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_359;
if ( F_87 ( string , V_147 ) != 0 )
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
F_104 ( L_71 , V_214 ) ;
goto V_236;
}
#ifndef F_105
if ( V_147 -> V_321 ) {
F_5 ( V_59 , L_72 ) ;
goto V_236;
}
#endif
if ( ! V_147 -> V_198 ) {
F_5 ( V_59 , L_73 ) ;
goto V_236;
}
if ( ! strchr ( V_147 -> V_198 + 3 , '\\' ) ) {
F_5 ( V_59 , L_74 ) ;
goto V_236;
}
if ( ! V_217 ) {
if ( ! F_103 ( V_95 , & V_147 -> V_198 [ 2 ] ,
strlen ( & V_147 -> V_198 [ 2 ] ) ) ) {
F_104 ( L_75 ) ;
goto V_236;
}
}
F_42 ( V_95 , V_218 ) ;
if ( V_211 )
V_147 -> V_209 = V_209 ;
else if ( V_209 == 1 )
F_106 ( L_76 ) ;
if ( V_212 )
V_147 -> V_210 = V_210 ;
else if ( V_210 == 1 )
F_106 ( L_77 ) ;
F_11 ( V_203 ) ;
return 0 ;
V_359:
F_100 ( L_78 ) ;
V_236:
F_11 ( string ) ;
F_11 ( V_203 ) ;
return 1 ;
}
static bool
F_107 ( struct V_94 * V_370 , struct V_94 * V_380 )
{
switch ( V_370 -> V_381 ) {
case V_382 :
return ( V_380 -> V_381 == V_382 ) ;
case V_383 : {
struct V_384 * V_385 = (struct V_384 * ) V_370 ;
struct V_384 * V_386 = (struct V_384 * ) V_380 ;
return ( V_385 -> V_387 . V_388 == V_386 -> V_387 . V_388 ) ;
}
case V_389 : {
struct V_390 * V_391 = (struct V_390 * ) V_370 ;
struct V_390 * V_392 = (struct V_390 * ) V_380 ;
return F_108 ( & V_391 -> V_393 , & V_392 -> V_393 ) ;
}
default:
F_109 ( 1 ) ;
return false ;
}
}
static bool
F_110 ( struct V_1 * V_2 , struct V_94 * V_394 )
{
T_5 V_218 , * V_395 ;
switch ( V_394 -> V_381 ) {
case V_383 :
V_395 = & ( (struct V_384 * ) & V_2 -> V_95 ) -> V_396 ;
V_218 = ( (struct V_384 * ) V_394 ) -> V_396 ;
break;
case V_389 :
V_395 = & ( (struct V_390 * ) & V_2 -> V_95 ) -> V_397 ;
V_218 = ( (struct V_390 * ) V_394 ) -> V_397 ;
break;
default:
F_109 ( 1 ) ;
return false ;
}
if ( ! V_218 ) {
V_218 = F_111 ( V_96 ) ;
if ( V_218 == * V_395 )
return true ;
V_218 = F_111 ( V_398 ) ;
}
return V_218 == * V_395 ;
}
static bool
F_112 ( struct V_1 * V_2 , struct V_94 * V_394 ,
struct V_94 * V_370 )
{
switch ( V_394 -> V_381 ) {
case V_383 : {
struct V_384 * V_399 = (struct V_384 * ) V_394 ;
struct V_384 * V_400 =
(struct V_384 * ) & V_2 -> V_95 ;
if ( V_399 -> V_387 . V_388 != V_400 -> V_387 . V_388 )
return false ;
break;
}
case V_389 : {
struct V_390 * V_401 = (struct V_390 * ) V_394 ;
struct V_390 * V_402 =
(struct V_390 * ) & V_2 -> V_95 ;
if ( ! F_108 ( & V_401 -> V_393 ,
& V_402 -> V_393 ) )
return false ;
if ( V_401 -> V_403 != V_402 -> V_403 )
return false ;
break;
}
default:
F_109 ( 1 ) ;
return false ;
}
if ( ! F_107 ( V_370 , (struct V_94 * ) & V_2 -> V_370 ) )
return false ;
return true ;
}
static bool
F_113 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
if ( F_114 ( V_2 , V_147 -> V_149 ) == V_150 )
return false ;
if ( V_147 -> V_151 && ! V_2 -> V_151 )
return false ;
return true ;
}
static int F_115 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_94 * V_394 = (struct V_94 * ) & V_147 -> V_95 ;
if ( V_147 -> V_324 )
return 0 ;
if ( ( V_2 -> V_179 != V_147 -> V_179 ) || ( V_2 -> V_52 != V_147 -> V_52 ) )
return 0 ;
if ( ! F_116 ( F_117 ( V_2 ) , V_123 -> V_404 -> V_405 ) )
return 0 ;
if ( ! F_112 ( V_2 , V_394 ,
(struct V_94 * ) & V_147 -> V_370 ) )
return 0 ;
if ( ! F_110 ( V_2 , V_394 ) )
return 0 ;
if ( ! F_113 ( V_2 , V_147 ) )
return 0 ;
if ( V_2 -> V_50 != V_147 -> V_50 * V_54 )
return 0 ;
return 1 ;
}
static struct V_1 *
F_118 ( struct V_146 * V_147 )
{
struct V_1 * V_2 ;
F_2 ( & V_22 ) ;
F_119 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_115 ( V_2 , V_147 ) )
continue;
++ V_2 -> V_406 ;
F_3 ( & V_22 ) ;
F_5 ( V_20 , L_79 ) ;
return V_2 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
void
F_120 ( struct V_1 * V_2 , int V_407 )
{
struct V_121 * V_408 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_406 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_121 ( F_117 ( V_2 ) ) ;
F_16 ( & V_2 -> V_105 ) ;
F_3 ( & V_22 ) ;
F_122 ( & V_2 -> V_47 ) ;
#ifdef F_4
if ( V_407 )
F_123 ( & V_2 -> V_409 ) ;
else
F_122 ( & V_2 -> V_409 ) ;
#endif
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
F_11 ( V_2 -> V_34 . V_35 ) ;
V_2 -> V_34 . V_35 = NULL ;
V_2 -> V_34 . V_36 = 0 ;
V_408 = F_66 ( & V_2 -> V_131 , NULL ) ;
if ( V_408 )
F_126 ( V_410 , V_408 ) ;
}
static struct V_1 *
F_127 ( struct V_146 * V_411 )
{
struct V_1 * V_412 = NULL ;
int V_3 ;
F_5 ( V_20 , L_80 , V_411 -> V_198 ) ;
V_412 = F_118 ( V_411 ) ;
if ( V_412 )
return V_412 ;
V_412 = F_102 ( sizeof( struct V_1 ) , V_139 ) ;
if ( ! V_412 ) {
V_3 = - V_140 ;
goto V_413;
}
V_412 -> V_52 = V_411 -> V_52 ;
V_412 -> V_179 = V_411 -> V_179 ;
F_128 ( V_412 , F_129 ( V_123 -> V_404 -> V_405 ) ) ;
V_412 -> V_57 = F_71 ( V_411 -> V_198 ) ;
if ( F_130 ( V_412 -> V_57 ) ) {
V_3 = F_131 ( V_412 -> V_57 ) ;
goto V_414;
}
V_412 -> V_251 = V_411 -> V_251 ;
V_412 -> V_253 = V_411 -> V_253 ;
V_412 -> V_415 = V_411 -> V_416 ;
V_412 -> V_417 = 0 ;
V_412 -> V_107 = 1 ;
F_132 ( & V_412 -> V_63 ) ;
F_132 ( & V_412 -> V_108 ) ;
F_12 ( & V_412 -> V_109 ) ;
F_133 ( & V_412 -> V_27 ) ;
memcpy ( V_412 -> V_418 ,
V_411 -> V_219 , V_375 ) ;
memcpy ( V_412 -> V_419 ,
V_411 -> V_221 , V_375 ) ;
V_412 -> V_33 = false ;
V_412 -> V_32 = 0 ;
V_412 -> V_37 = V_38 ;
F_134 ( & V_412 -> V_106 ) ;
F_12 ( & V_412 -> V_105 ) ;
F_12 ( & V_412 -> V_23 ) ;
F_135 ( & V_412 -> V_47 , F_22 ) ;
#ifdef F_4
F_135 ( & V_412 -> V_409 , V_420 ) ;
F_133 ( & V_412 -> V_421 ) ;
#endif
memcpy ( & V_412 -> V_370 , & V_411 -> V_370 ,
sizeof( V_412 -> V_370 ) ) ;
memcpy ( & V_412 -> V_95 , & V_411 -> V_95 ,
sizeof( V_412 -> V_95 ) ) ;
#ifdef F_4
F_136 ( V_412 -> V_422 ) ;
#endif
V_412 -> V_15 = V_51 ;
++ V_412 -> V_406 ;
if ( V_411 -> V_50 >= V_423 &&
V_411 -> V_50 <= V_424 )
V_412 -> V_50 = V_411 -> V_50 * V_54 ;
else
V_412 -> V_50 = V_235 * V_54 ;
V_3 = F_137 ( V_412 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_81 ) ;
goto V_414;
}
F_138 ( V_425 ) ;
V_412 -> V_131 = F_139 ( F_57 ,
V_412 , L_82 ) ;
if ( F_130 ( V_412 -> V_131 ) ) {
V_3 = F_131 ( V_412 -> V_131 ) ;
F_5 ( V_59 , L_83 , V_3 ) ;
F_140 ( V_425 ) ;
goto V_414;
}
V_412 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_141 ( & V_412 -> V_105 , & V_426 ) ;
F_3 ( & V_22 ) ;
F_142 ( V_412 ) ;
F_25 ( V_46 , & V_412 -> V_47 , V_412 -> V_50 ) ;
return V_412 ;
V_414:
F_124 ( V_412 ) ;
F_121 ( F_117 ( V_412 ) ) ;
V_413:
if ( V_412 ) {
if ( ! F_130 ( V_412 -> V_57 ) )
F_11 ( V_412 -> V_57 ) ;
if ( V_412 -> V_28 )
F_10 ( V_412 -> V_28 ) ;
F_11 ( V_412 ) ;
}
return F_72 ( V_3 ) ;
}
static int F_143 ( struct V_7 * V_8 , struct V_146 * V_147 )
{
if ( V_147 -> V_149 != V_150 &&
V_147 -> V_149 != V_8 -> V_149 )
return 0 ;
switch ( V_8 -> V_149 ) {
case V_156 :
if ( ! F_144 ( V_147 -> V_222 , V_8 -> V_222 ) )
return 0 ;
break;
default:
if ( V_8 -> V_427 == NULL ) {
if ( ! V_147 -> V_169 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_427 ,
V_147 -> V_357 ? V_147 -> V_357 : L_84 ,
V_360 ) )
return 0 ;
if ( ( V_147 -> V_357 && strlen ( V_147 -> V_357 ) != 0 ) &&
V_8 -> V_362 != NULL &&
strncmp ( V_8 -> V_362 ,
V_147 -> V_362 ? V_147 -> V_362 : L_84 ,
V_428 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_145 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_7 * V_8 ;
F_2 ( & V_22 ) ;
F_119 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_8 -> V_429 == V_16 )
continue;
if ( ! F_143 ( V_8 , V_147 ) )
continue;
++ V_8 -> V_430 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_146 ( struct V_7 * V_8 )
{
unsigned int V_3 , V_431 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_20 , L_85 , V_21 , V_8 -> V_430 ) ;
F_2 ( & V_22 ) ;
if ( V_8 -> V_429 == V_16 ) {
F_3 ( & V_22 ) ;
return;
}
if ( -- V_8 -> V_430 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
if ( V_8 -> V_429 == V_62 )
V_8 -> V_429 = V_16 ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_429 == V_16 && V_2 -> V_52 -> V_432 ) {
V_431 = F_147 () ;
V_3 = V_2 -> V_52 -> V_432 ( V_431 , V_8 ) ;
if ( V_3 )
F_5 ( V_59 , L_86 ,
V_21 , V_3 ) ;
F_148 ( V_431 ) ;
}
F_2 ( & V_22 ) ;
F_16 ( & V_8 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_149 ( V_8 ) ;
F_120 ( V_2 , 0 ) ;
}
static int
F_150 ( struct V_146 * V_147 , struct V_7 * V_8 )
{
int V_3 = 0 ;
const char * V_137 , * V_433 ;
char * V_434 ;
T_6 V_36 ;
struct V_435 * V_435 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_384 * V_436 ;
struct V_390 * V_437 ;
const struct V_438 * V_439 ;
V_434 = F_73 ( V_440 , V_139 ) ;
if ( ! V_434 )
return - V_140 ;
switch ( V_2 -> V_95 . V_441 ) {
case V_383 :
V_436 = (struct V_384 * ) & V_2 -> V_95 ;
sprintf ( V_434 , L_87 , & V_436 -> V_387 . V_388 ) ;
break;
case V_389 :
V_437 = (struct V_390 * ) & V_2 -> V_95 ;
sprintf ( V_434 , L_88 , & V_437 -> V_393 . V_442 ) ;
break;
default:
F_5 ( V_20 , L_89 ,
V_2 -> V_95 . V_441 ) ;
V_3 = - V_138 ;
goto V_413;
}
F_5 ( V_20 , L_90 , V_21 , V_434 ) ;
V_435 = F_151 ( & V_443 , V_434 , L_84 ) ;
if ( F_130 ( V_435 ) ) {
if ( ! V_8 -> V_444 ) {
F_5 ( V_20 , L_91 ) ;
V_3 = F_131 ( V_435 ) ;
goto V_413;
}
sprintf ( V_434 , L_92 , V_8 -> V_444 ) ;
F_5 ( V_20 , L_90 , V_21 , V_434 ) ;
V_435 = F_151 ( & V_443 , V_434 , L_84 ) ;
if ( F_130 ( V_435 ) ) {
V_3 = F_131 ( V_435 ) ;
goto V_413;
}
}
F_152 ( & V_435 -> V_445 ) ;
V_439 = V_438 ( V_435 ) ;
if ( F_153 ( V_439 ) ) {
V_3 = V_439 ? F_131 ( V_439 ) : - V_138 ;
goto V_446;
}
V_433 = V_439 -> V_201 ;
V_137 = F_154 ( V_433 , V_439 -> V_447 , ':' ) ;
F_5 ( V_20 , L_93 , V_433 ) ;
if ( ! V_137 ) {
F_5 ( V_20 , L_94 ,
V_439 -> V_447 ) ;
V_3 = - V_138 ;
goto V_446;
}
V_36 = V_137 - V_433 ;
if ( V_36 > V_360 || V_36 <= 0 ) {
F_5 ( V_20 , L_95 ,
V_36 ) ;
V_3 = - V_138 ;
goto V_446;
}
V_147 -> V_357 = F_91 ( V_433 , V_36 , V_139 ) ;
if ( ! V_147 -> V_357 ) {
F_5 ( V_20 , L_96 ,
V_36 ) ;
V_3 = - V_140 ;
goto V_446;
}
F_5 ( V_20 , L_97 , V_21 , V_147 -> V_357 ) ;
V_36 = V_435 -> V_447 - ( V_36 + 1 ) ;
if ( V_36 > V_428 || V_36 <= 0 ) {
F_5 ( V_20 , L_98 , V_36 ) ;
V_3 = - V_138 ;
F_11 ( V_147 -> V_357 ) ;
V_147 -> V_357 = NULL ;
goto V_446;
}
++ V_137 ;
V_147 -> V_362 = F_91 ( V_137 , V_36 , V_139 ) ;
if ( ! V_147 -> V_362 ) {
F_5 ( V_20 , L_99 ,
V_36 ) ;
V_3 = - V_140 ;
F_11 ( V_147 -> V_357 ) ;
V_147 -> V_357 = NULL ;
goto V_446;
}
V_446:
F_155 ( & V_435 -> V_445 ) ;
F_156 ( V_435 ) ;
V_413:
F_11 ( V_434 ) ;
F_5 ( V_20 , L_100 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_157 ( struct V_1 * V_2 , struct V_146 * V_411 )
{
int V_3 = - V_140 ;
unsigned int V_431 ;
struct V_7 * V_8 ;
struct V_384 * V_394 = (struct V_384 * ) & V_2 -> V_95 ;
struct V_390 * V_401 = (struct V_390 * ) & V_2 -> V_95 ;
V_431 = F_147 () ;
V_8 = F_145 ( V_2 , V_411 ) ;
if ( V_8 ) {
F_5 ( V_20 , L_101 ,
V_8 -> V_429 ) ;
F_8 ( & V_8 -> V_448 ) ;
V_3 = F_158 ( V_431 , V_8 ) ;
if ( V_3 ) {
F_15 ( & V_8 -> V_448 ) ;
F_146 ( V_8 ) ;
F_159 ( V_431 ) ;
return F_72 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_5 ( V_20 , L_102 ) ;
V_3 = F_160 ( V_431 , V_8 ,
V_411 -> V_449 ) ;
if ( V_3 ) {
F_15 ( & V_8 -> V_448 ) ;
F_146 ( V_8 ) ;
F_159 ( V_431 ) ;
return F_72 ( V_3 ) ;
}
}
F_15 ( & V_8 -> V_448 ) ;
F_120 ( V_2 , 0 ) ;
F_159 ( V_431 ) ;
return V_8 ;
}
F_5 ( V_20 , L_103 ) ;
V_8 = F_161 () ;
if ( V_8 == NULL )
goto V_450;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_95 . V_441 == V_389 )
sprintf ( V_8 -> V_451 , L_104 , & V_401 -> V_393 ) ;
else
sprintf ( V_8 -> V_451 , L_105 , & V_394 -> V_387 ) ;
if ( V_411 -> V_357 ) {
V_8 -> V_427 = F_93 ( V_411 -> V_357 , V_139 ) ;
if ( ! V_8 -> V_427 )
goto V_450;
}
if ( V_411 -> V_362 ) {
V_8 -> V_362 = F_93 ( V_411 -> V_362 , V_139 ) ;
if ( ! V_8 -> V_362 )
goto V_450;
}
if ( V_411 -> V_368 ) {
V_8 -> V_444 = F_93 ( V_411 -> V_368 , V_139 ) ;
if ( ! V_8 -> V_444 )
goto V_450;
}
if ( V_411 -> V_333 )
V_8 -> V_452 = V_411 -> V_333 ;
V_8 -> V_222 = V_411 -> V_222 ;
V_8 -> V_223 = V_411 -> V_223 ;
V_8 -> V_149 = V_411 -> V_149 ;
V_8 -> V_151 = V_411 -> V_151 ;
F_8 ( & V_8 -> V_448 ) ;
V_3 = F_158 ( V_431 , V_8 ) ;
if ( ! V_3 )
V_3 = F_160 ( V_431 , V_8 , V_411 -> V_449 ) ;
F_15 ( & V_8 -> V_448 ) ;
if ( V_3 )
goto V_450;
F_2 ( & V_22 ) ;
F_141 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_159 ( V_431 ) ;
return V_8 ;
V_450:
F_149 ( V_8 ) ;
F_159 ( V_431 ) ;
return F_72 ( V_3 ) ;
}
static int F_162 ( struct V_9 * V_10 , const char * V_134 )
{
if ( V_10 -> V_453 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_454 , V_134 , V_455 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_163 ( struct V_7 * V_8 , struct V_146 * V_411 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_22 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_26 ) ;
if ( ! F_162 ( V_10 , V_411 -> V_198 ) )
continue;
#ifdef F_4
if ( V_10 -> V_353 != V_411 -> V_353 )
continue;
#endif
++ V_10 -> V_456 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
void
F_164 ( struct V_9 * V_10 )
{
unsigned int V_431 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( V_20 , L_106 , V_21 , V_10 -> V_456 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_456 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_431 = F_147 () ;
if ( V_8 -> V_2 -> V_52 -> V_457 )
V_8 -> V_2 -> V_52 -> V_457 ( V_431 , V_10 ) ;
F_148 ( V_431 ) ;
F_165 ( V_10 ) ;
F_166 ( V_10 ) ;
F_146 ( V_8 ) ;
}
static struct V_9 *
F_167 ( struct V_7 * V_8 , struct V_146 * V_411 )
{
int V_3 , V_431 ;
struct V_9 * V_10 ;
V_10 = F_163 ( V_8 , V_411 ) ;
if ( V_10 ) {
F_5 ( V_20 , L_107 ) ;
F_146 ( V_8 ) ;
if ( V_10 -> V_314 != V_411 -> V_314 )
F_5 ( V_59 , L_108 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_52 -> V_458 ) {
V_3 = - V_56 ;
goto V_459;
}
V_10 = F_168 () ;
if ( V_10 == NULL ) {
V_3 = - V_140 ;
goto V_459;
}
if ( V_411 -> V_353 ) {
#ifdef F_4
if ( V_8 -> V_2 -> V_179 -> V_460 == 0 ) {
F_5 ( V_59 ,
L_109 ) ;
V_3 = - V_461 ;
goto V_459;
} else
V_10 -> V_353 = V_411 -> V_353 ;
#else
F_5 ( V_59 , L_110 ) ;
V_3 = - V_461 ;
goto V_459;
#endif
}
V_10 -> V_8 = V_8 ;
if ( V_411 -> V_362 ) {
V_10 -> V_362 = F_93 ( V_411 -> V_362 , V_139 ) ;
if ( ! V_10 -> V_362 ) {
V_3 = - V_140 ;
goto V_459;
}
}
V_431 = F_147 () ;
V_3 = V_8 -> V_2 -> V_52 -> V_458 ( V_431 , V_8 , V_411 -> V_198 , V_10 ,
V_411 -> V_449 ) ;
F_159 ( V_431 ) ;
F_5 ( V_20 , L_111 , V_3 ) ;
if ( V_3 )
goto V_459;
if ( V_411 -> V_269 ) {
V_10 -> V_462 &= ~ V_463 ;
F_5 ( V_20 , L_112 , V_10 -> V_462 ) ;
}
V_10 -> V_314 = V_411 -> V_314 ;
V_10 -> V_464 = false ;
if ( V_411 -> V_327 ) {
if ( V_8 -> V_2 -> V_179 -> V_460 == 0 ) {
F_5 ( V_59 ,
L_113 ) ;
V_3 = - V_461 ;
goto V_459;
#ifdef F_4
} else if ( V_8 -> V_2 -> V_465 &
V_466 )
V_10 -> V_464 = true ;
else {
F_5 ( V_59 ,
L_114 ) ;
V_3 = - V_461 ;
goto V_459;
#endif
}
#ifdef F_4
} else if ( ( V_10 -> V_465 & V_467 )
&& ( V_8 -> V_2 -> V_465 & V_466 )
&& ( V_411 -> V_326 == false ) ) {
F_5 ( V_20 , L_115 ) ;
V_10 -> V_464 = true ;
#endif
} else if ( V_411 -> V_329 ) {
if ( V_8 -> V_2 -> V_179 -> V_460 == 0 ) {
F_5 ( V_59 ,
L_116 ) ;
V_3 = - V_461 ;
goto V_459;
}
V_10 -> V_468 = true ;
}
V_10 -> V_255 = V_411 -> V_255 ;
V_10 -> V_275 = V_411 -> V_275 ;
V_10 -> V_311 = V_411 -> V_311 ;
F_12 ( & V_10 -> V_469 ) ;
F_2 ( & V_22 ) ;
F_141 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_169 ( V_10 ) ;
return V_10 ;
V_459:
F_166 ( V_10 ) ;
return F_72 ( V_3 ) ;
}
void
F_170 ( struct V_470 * V_471 )
{
if ( ! V_471 || F_130 ( V_471 ) )
return;
if ( ! F_171 ( & V_471 -> V_472 ) ||
F_172 ( V_473 , & V_471 -> V_474 ) ) {
V_471 -> V_475 = V_38 ;
return;
}
if ( ! F_130 ( F_173 ( V_471 ) ) )
F_164 ( F_173 ( V_471 ) ) ;
F_11 ( V_471 ) ;
return;
}
static inline struct V_470 *
F_174 ( struct V_476 * V_477 )
{
return V_477 -> V_478 ;
}
static int
F_175 ( struct V_479 * V_480 , struct V_481 * V_482 )
{
struct V_476 * V_483 = F_176 ( V_480 ) ;
struct V_476 * V_484 = V_482 -> V_477 ;
if ( ( V_480 -> V_485 & V_486 ) != ( V_482 -> V_30 & V_486 ) )
return 0 ;
if ( ( V_483 -> V_487 & V_488 ) !=
( V_484 -> V_487 & V_488 ) )
return 0 ;
if ( V_484 -> V_348 && V_484 -> V_348 < V_483 -> V_348 )
return 0 ;
if ( V_484 -> V_346 && V_484 -> V_346 < V_483 -> V_346 )
return 0 ;
if ( ! F_144 ( V_483 -> V_489 , V_484 -> V_489 ) || ! F_177 ( V_483 -> V_490 , V_484 -> V_490 ) )
return 0 ;
if ( V_483 -> V_491 != V_484 -> V_491 ||
V_483 -> V_492 != V_484 -> V_492 )
return 0 ;
if ( strcmp ( V_483 -> V_449 -> V_493 , V_484 -> V_449 -> V_493 ) )
return 0 ;
if ( V_483 -> V_233 != V_484 -> V_233 )
return 0 ;
return 1 ;
}
static int
F_178 ( struct V_479 * V_480 , struct V_481 * V_482 )
{
struct V_476 * V_483 = F_176 ( V_480 ) ;
struct V_476 * V_484 = V_482 -> V_477 ;
if ( V_483 -> V_487 & V_494 ) {
if ( ! ( V_484 -> V_487 & V_494 ) )
return 0 ;
if ( strcmp ( V_484 -> V_199 , V_483 -> V_199 ) )
return 0 ;
return 1 ;
}
return 0 ;
}
int
F_179 ( struct V_479 * V_480 , void * V_201 )
{
struct V_481 * V_482 = (struct V_481 * ) V_201 ;
struct V_146 * V_411 ;
struct V_476 * V_477 ;
struct V_1 * V_495 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_470 * V_471 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_477 = F_176 ( V_480 ) ;
V_471 = F_180 ( F_174 ( V_477 ) ) ;
if ( F_130 ( V_471 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_173 ( V_471 ) ;
V_8 = V_10 -> V_8 ;
V_495 = V_8 -> V_2 ;
V_411 = V_482 -> V_147 ;
if ( ! F_115 ( V_495 , V_411 ) ||
! F_143 ( V_8 , V_411 ) ||
! F_162 ( V_10 , V_411 -> V_198 ) ||
! F_178 ( V_480 , V_482 ) ) {
V_3 = 0 ;
goto V_496;
}
V_3 = F_175 ( V_480 , V_482 ) ;
V_496:
F_3 ( & V_22 ) ;
F_170 ( V_471 ) ;
return V_3 ;
}
int
F_181 ( const unsigned int V_431 , struct V_7 * V_8 , const char * V_497 ,
const struct V_498 * V_499 , unsigned int * V_500 ,
struct V_501 * * V_502 , int V_225 )
{
char * V_503 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_52 -> V_458 || ! V_8 -> V_2 -> V_52 -> V_504 )
return - V_56 ;
* V_500 = 0 ;
* V_502 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_503 = F_73 ( 2 +
F_96 ( V_8 -> V_451 , V_505 * 2 )
+ 1 + 4 + 2 , V_139 ) ;
if ( V_503 == NULL )
return - V_140 ;
V_503 [ 0 ] = '\\' ;
V_503 [ 1 ] = '\\' ;
strcpy ( V_503 + 2 , V_8 -> V_451 ) ;
strcpy ( V_503 + 2 + strlen ( V_8 -> V_451 ) , L_117 ) ;
V_3 = V_8 -> V_2 -> V_52 -> V_458 ( V_431 , V_8 , V_503 , NULL ,
V_499 ) ;
F_5 ( V_20 , L_118 , V_3 , V_8 -> V_25 ) ;
F_11 ( V_503 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_52 -> V_504 ( V_431 , V_8 , V_497 ,
V_502 , V_500 ,
V_499 , V_225 ) ;
return V_3 ;
}
static inline void
F_182 ( struct V_506 * V_507 )
{
struct V_507 * V_508 = V_507 -> V_508 ;
F_183 ( ! F_184 ( V_508 ) ) ;
F_185 ( V_508 , L_119 ,
& V_509 [ 0 ] , L_120 , & V_510 [ 0 ] ) ;
}
static inline void
F_186 ( struct V_506 * V_507 )
{
struct V_507 * V_508 = V_507 -> V_508 ;
F_183 ( ! F_184 ( V_508 ) ) ;
F_185 ( V_508 , L_121 ,
& V_509 [ 1 ] , L_122 , & V_510 [ 1 ] ) ;
}
static inline void
F_182 ( struct V_506 * V_507 )
{
}
static inline void
F_186 ( struct V_506 * V_507 )
{
}
static void F_187 ( char * V_511 , char * V_512 , unsigned int V_66 )
{
unsigned int V_206 , V_207 ;
for ( V_206 = 0 , V_207 = 0 ; V_206 < ( V_66 ) ; V_206 ++ ) {
V_511 [ V_207 ] = 'A' + ( 0x0F & ( V_512 [ V_206 ] >> 4 ) ) ;
V_511 [ V_207 + 1 ] = 'A' + ( 0x0F & V_512 [ V_206 ] ) ;
V_207 += 2 ;
}
}
static int
F_188 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_370 . V_441 != V_382 ) {
struct V_506 * V_506 = V_2 -> V_28 ;
V_3 = V_506 -> V_52 -> V_513 ( V_506 ,
(struct V_94 * ) & V_2 -> V_370 ,
sizeof( V_2 -> V_370 ) ) ;
if ( V_3 < 0 ) {
struct V_384 * V_385 ;
struct V_390 * V_391 ;
V_385 = (struct V_384 * ) & V_2 -> V_370 ;
V_391 = (struct V_390 * ) & V_2 -> V_370 ;
if ( V_391 -> V_514 == V_389 )
F_5 ( V_59 , L_123 ,
& V_391 -> V_393 , V_3 ) ;
else
F_5 ( V_59 , L_124 ,
& V_385 -> V_387 . V_388 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_189 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_515 * V_516 ;
struct V_517 * V_518 ;
V_516 = F_102 ( sizeof( struct V_515 ) ,
V_139 ) ;
if ( V_516 ) {
V_516 -> V_519 . V_520 . V_521 = 32 ;
if ( V_2 -> V_419 [ 0 ] != 0 )
F_187 ( V_516 -> V_519 .
V_520 . V_522 ,
V_2 -> V_419 ,
V_375 ) ;
else
F_187 ( V_516 -> V_519 .
V_520 . V_522 ,
V_523 ,
V_375 ) ;
V_516 -> V_519 . V_520 . V_524 = 32 ;
if ( V_2 -> V_418 [ 0 ] != 0 )
F_187 ( V_516 -> V_519 .
V_520 . V_525 ,
V_2 -> V_418 ,
V_375 ) ;
else
F_187 ( V_516 -> V_519 .
V_520 . V_525 ,
L_125 ,
V_375 ) ;
V_516 -> V_519 . V_520 . V_526 = 0 ;
V_516 -> V_519 . V_520 . V_527 = 0 ;
V_518 = (struct V_517 * ) V_516 ;
V_518 -> V_528 = F_190 ( 0x81000044 ) ;
V_3 = F_191 ( V_2 , V_518 , 0x44 ) ;
F_11 ( V_516 ) ;
F_36 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_395 ;
int V_529 , V_530 ;
struct V_506 * V_506 = V_2 -> V_28 ;
struct V_94 * V_531 ;
V_531 = (struct V_94 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_441 == V_389 ) {
V_395 = ( (struct V_390 * ) V_531 ) -> V_397 ;
V_529 = sizeof( struct V_390 ) ;
V_530 = V_389 ;
} else {
V_395 = ( (struct V_384 * ) V_531 ) -> V_396 ;
V_529 = sizeof( struct V_384 ) ;
V_530 = V_383 ;
}
if ( V_506 == NULL ) {
V_3 = F_192 ( F_117 ( V_2 ) , V_530 , V_532 ,
V_533 , & V_506 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_126 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_5 ( V_20 , L_127 ) ;
V_2 -> V_28 = V_506 ;
V_506 -> V_508 -> V_534 = V_535 ;
if ( V_530 == V_389 )
F_186 ( V_506 ) ;
else
F_182 ( V_506 ) ;
}
V_3 = F_188 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_506 -> V_508 -> V_536 = 7 * V_54 ;
V_506 -> V_508 -> V_537 = 5 * V_54 ;
if ( V_2 -> V_253 ) {
if ( V_506 -> V_508 -> V_538 < ( 200 * 1024 ) )
V_506 -> V_508 -> V_538 = 200 * 1024 ;
if ( V_506 -> V_508 -> V_539 < ( 140 * 1024 ) )
V_506 -> V_508 -> V_539 = 140 * 1024 ;
}
if ( V_2 -> V_415 ) {
int V_540 = 1 ;
V_3 = F_193 ( V_506 , V_541 , V_542 ,
( char * ) & V_540 , sizeof( V_540 ) ) ;
if ( V_3 )
F_5 ( V_20 , L_128 ,
V_3 ) ;
}
F_5 ( V_20 , L_129 ,
V_506 -> V_508 -> V_538 ,
V_506 -> V_508 -> V_539 , V_506 -> V_508 -> V_536 ) ;
V_3 = V_506 -> V_52 -> V_543 ( V_506 , V_531 , V_529 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_20 , L_130 , V_3 ) ;
F_10 ( V_506 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_395 == F_111 ( V_398 ) )
V_3 = F_189 ( V_2 ) ;
return V_3 ;
}
static int
F_137 ( struct V_1 * V_2 )
{
T_5 * V_395 ;
struct V_390 * V_401 = (struct V_390 * ) & V_2 -> V_95 ;
struct V_384 * V_394 = (struct V_384 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_441 == V_389 )
V_395 = & V_401 -> V_397 ;
else
V_395 = & V_394 -> V_396 ;
if ( * V_395 == 0 ) {
int V_3 ;
* V_395 = F_111 ( V_96 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_395 = F_111 ( V_398 ) ;
}
return F_18 ( V_2 ) ;
}
void F_194 ( unsigned int V_431 , struct V_9 * V_10 ,
struct V_476 * V_477 , struct V_146 * V_544 )
{
T_7 V_545 = F_195 ( V_10 -> V_546 . V_547 ) ;
if ( V_544 && V_544 -> V_273 ) {
V_10 -> V_546 . V_547 = 0 ;
V_10 -> V_548 = 0 ;
F_5 ( V_20 , L_131 ) ;
return;
} else if ( V_544 )
V_10 -> V_548 = 1 ;
if ( V_10 -> V_548 == 0 ) {
F_5 ( V_20 , L_132 ) ;
return;
}
if ( ! F_196 ( V_431 , V_10 ) ) {
T_7 V_549 = F_195 ( V_10 -> V_546 . V_547 ) ;
F_5 ( V_20 , L_133 , V_549 ) ;
if ( V_544 == NULL ) {
if ( ( V_545 & V_550 ) == 0 )
V_549 &= ~ V_550 ;
if ( ( V_545 & V_551 ) == 0 ) {
if ( V_549 & V_551 )
F_5 ( V_59 , L_134 ) ;
V_549 &= ~ V_551 ;
} else if ( ( V_549 & V_551 ) == 0 ) {
F_5 ( V_59 , L_135 ) ;
F_5 ( V_59 , L_136 ) ;
}
}
if ( V_549 & V_552 )
F_5 ( V_59 , L_137 ) ;
V_549 &= V_553 ;
if ( V_544 && V_544 -> V_308 )
V_549 &= ~ V_550 ;
else if ( V_550 & V_549 ) {
F_5 ( V_20 , L_138 ) ;
if ( V_477 )
V_477 -> V_487 |=
V_554 ;
}
if ( V_544 && V_544 -> V_231 == 0 )
V_549 &= ~ V_551 ;
else if ( V_549 & V_551 ) {
F_5 ( V_20 , L_139 ) ;
if ( V_477 )
V_477 -> V_487 |=
V_555 ;
}
F_5 ( V_20 , L_140 , ( int ) V_549 ) ;
#ifdef F_62
if ( V_549 & V_556 )
F_5 ( V_20 , L_141 ) ;
if ( V_549 & V_557 )
F_5 ( V_20 , L_142 ) ;
if ( V_549 & V_551 )
F_5 ( V_20 , L_143 ) ;
if ( V_549 & V_558 )
F_5 ( V_20 , L_144 ) ;
if ( V_549 & V_550 )
F_5 ( V_20 , L_145 ) ;
if ( V_549 & V_559 )
F_5 ( V_20 , L_146 ) ;
if ( V_549 & V_560 )
F_5 ( V_20 , L_147 ) ;
if ( V_549 & V_561 )
F_5 ( V_20 , L_148 ) ;
if ( V_549 & V_552 )
F_5 ( V_20 , L_149 ) ;
#endif
if ( F_197 ( V_431 , V_10 , V_549 ) ) {
if ( V_544 == NULL ) {
F_5 ( V_20 , L_150 ) ;
} else
F_5 ( V_59 , L_151 ) ;
}
}
}
int F_198 ( struct V_146 * V_562 ,
struct V_476 * V_477 )
{
F_135 ( & V_477 -> V_563 , V_564 ) ;
F_134 ( & V_477 -> V_565 ) ;
V_477 -> V_566 = V_567 ;
V_477 -> V_346 = V_562 -> V_346 ;
V_477 -> V_348 = V_562 -> V_348 ;
V_477 -> V_489 = V_562 -> V_223 ;
V_477 -> V_490 = V_562 -> V_224 ;
V_477 -> V_491 = V_562 -> V_227 ;
V_477 -> V_492 = V_562 -> V_226 ;
F_5 ( V_20 , L_152 ,
V_477 -> V_491 , V_477 -> V_492 ) ;
V_477 -> V_233 = V_562 -> V_233 ;
V_477 -> V_449 = V_562 -> V_449 ;
if ( V_562 -> V_258 )
V_477 -> V_487 |= V_568 ;
if ( V_562 -> V_285 )
V_477 -> V_487 |= V_569 ;
if ( V_562 -> V_288 )
V_477 -> V_487 |= V_570 ;
if ( V_562 -> V_232 )
V_477 -> V_487 |= V_571 ;
if ( V_562 -> V_225 )
V_477 -> V_487 |= V_572 ;
if ( V_562 -> V_261 )
V_477 -> V_487 |= V_573 ;
if ( V_562 -> V_244 )
V_477 -> V_487 |= V_574 ;
if ( V_562 -> V_266 )
V_477 -> V_487 |= V_575 ;
if ( V_562 -> V_277 )
V_477 -> V_487 |= V_576 ;
if ( V_562 -> V_298 )
V_477 -> V_487 |= V_577 ;
if ( V_562 -> V_283 )
V_477 -> V_487 |= V_578 ;
if ( V_562 -> V_303 )
V_477 -> V_487 |= V_579 ;
if ( V_562 -> V_305 )
V_477 -> V_487 |= V_580 ;
if ( V_562 -> V_238 ) {
V_477 -> V_487 |= V_581 ;
V_477 -> V_582 = V_562 -> V_335 ;
}
if ( V_562 -> V_239 ) {
V_477 -> V_487 |= V_583 ;
V_477 -> V_584 = V_562 -> V_337 ;
}
if ( V_562 -> V_209 )
V_477 -> V_487 |= V_585 ;
if ( V_562 -> V_210 )
V_477 -> V_487 |= V_586 ;
if ( V_562 -> V_290 )
V_477 -> V_487 |= V_587 ;
if ( V_562 -> V_317 )
V_477 -> V_487 |= V_588 ;
if ( V_562 -> V_321 )
V_477 -> V_487 |= ( V_589 |
V_568 ) ;
if ( V_562 -> V_173 )
V_477 -> V_487 |= V_590 ;
if ( V_562 -> V_172 ) {
F_5 ( V_20 , L_153 ) ;
V_477 -> V_487 |= V_591 ;
}
if ( V_562 -> V_319 ) {
if ( V_562 -> V_266 ) {
F_5 ( V_59 , L_154 ) ;
}
V_477 -> V_487 |= V_592 ;
}
if ( ( V_562 -> V_305 ) && ( V_562 -> V_290 ) )
F_5 ( V_59 , L_155 ) ;
if ( V_562 -> V_199 ) {
V_477 -> V_199 = F_93 ( V_562 -> V_199 , V_139 ) ;
if ( V_477 -> V_199 == NULL )
return - V_140 ;
}
return 0 ;
}
static void
F_199 ( struct V_146 * V_411 )
{
F_11 ( V_411 -> V_357 ) ;
F_200 ( V_411 -> V_362 ) ;
F_11 ( V_411 -> V_198 ) ;
F_11 ( V_411 -> V_368 ) ;
F_11 ( V_411 -> V_372 ) ;
F_11 ( V_411 -> V_199 ) ;
}
void
F_201 ( struct V_146 * V_411 )
{
if ( ! V_411 )
return;
F_199 ( V_411 ) ;
F_11 ( V_411 ) ;
}
static char *
F_202 ( const struct V_146 * V_147 ,
const struct V_476 * V_477 )
{
char * V_593 , * V_196 ;
unsigned int V_594 = V_147 -> V_199 ? strlen ( V_147 -> V_199 ) + 1 : 0 ;
unsigned int V_595 = F_96 ( V_147 -> V_198 , V_455 + 1 ) ;
V_593 = F_73 ( V_595 + V_594 + 1 , V_139 ) ;
if ( V_593 == NULL )
return F_72 ( - V_140 ) ;
strncpy ( V_593 , V_147 -> V_198 , V_595 ) ;
V_196 = V_593 + V_595 ;
if ( V_594 ) {
* V_196 = F_203 ( V_477 ) ;
strncpy ( V_196 + 1 , V_147 -> V_199 , V_594 ) ;
V_196 += V_594 ;
}
* V_196 = '\0' ;
F_92 ( V_593 , F_203 ( V_477 ) ) ;
F_5 ( V_20 , L_156 , V_21 , V_593 ) ;
return V_593 ;
}
static int
F_204 ( const unsigned int V_431 , struct V_7 * V_8 ,
struct V_146 * V_411 , struct V_476 * V_477 ,
int V_596 )
{
int V_3 ;
unsigned int V_500 = 0 ;
struct V_501 * V_502 = NULL ;
char * V_593 = NULL , * V_597 = NULL , * V_598 = NULL ;
V_593 = F_202 ( V_411 , V_477 ) ;
if ( F_130 ( V_593 ) )
return F_131 ( V_593 ) ;
V_597 = V_596 ? V_593 + 1 : V_411 -> V_198 + 1 ;
V_3 = F_181 ( V_431 , V_8 , V_597 , V_477 -> V_449 ,
& V_500 , & V_502 , F_205 ( V_477 ) ) ;
if ( ! V_3 && V_500 > 0 ) {
char * V_599 = NULL ;
V_598 = F_206 ( V_477 -> V_200 ,
V_593 + 1 , V_502 ,
& V_599 ) ;
F_207 ( V_502 , V_500 ) ;
if ( F_130 ( V_598 ) ) {
V_3 = F_131 ( V_598 ) ;
V_598 = NULL ;
} else {
F_199 ( V_411 ) ;
V_3 = F_208 ( V_411 , V_598 ,
V_599 ) ;
}
F_11 ( V_599 ) ;
F_11 ( V_477 -> V_200 ) ;
V_477 -> V_200 = V_598 ;
}
F_11 ( V_593 ) ;
return V_3 ;
}
static int
F_208 ( struct V_146 * V_411 , char * V_600 ,
const char * V_195 )
{
int V_3 = 0 ;
if ( F_94 ( V_600 , V_195 , V_411 ) )
return - V_138 ;
if ( V_411 -> V_169 ) {
F_5 ( V_20 , L_157 ) ;
F_11 ( V_411 -> V_357 ) ;
V_411 -> V_357 = NULL ;
} else if ( V_411 -> V_357 ) {
F_5 ( V_20 , L_158 , V_411 -> V_357 ) ;
} else {
F_5 ( V_59 , L_159 ) ;
return - V_138 ;
}
if ( V_411 -> V_372 == NULL ) {
V_411 -> V_449 = F_209 () ;
} else {
V_411 -> V_449 = F_210 ( V_411 -> V_372 ) ;
if ( V_411 -> V_449 == NULL ) {
F_5 ( V_59 , L_160 ,
V_411 -> V_372 ) ;
return - V_601 ;
}
}
return V_3 ;
}
struct V_146 *
F_211 ( char * V_600 , const char * V_195 )
{
int V_3 ;
struct V_146 * V_411 ;
V_411 = F_73 ( sizeof( struct V_146 ) , V_139 ) ;
if ( ! V_411 )
return F_72 ( - V_140 ) ;
V_3 = F_208 ( V_411 , V_600 , V_195 ) ;
if ( V_3 ) {
F_201 ( V_411 ) ;
V_411 = F_72 ( V_3 ) ;
}
return V_411 ;
}
static int
F_212 ( struct V_1 * V_2 ,
unsigned int V_431 ,
struct V_9 * V_10 ,
struct V_476 * V_477 ,
char * V_593 )
{
int V_3 ;
char * V_602 ;
char V_603 , V_5 ;
V_603 = F_203 ( V_477 ) ;
V_602 = V_593 ;
V_3 = V_2 -> V_52 -> V_604 ( V_431 , V_10 , V_477 , L_84 ) ;
while ( V_3 == 0 ) {
while ( * V_602 == V_603 )
V_602 ++ ;
if ( ! * V_602 )
break;
while ( * V_602 && * V_602 != V_603 )
V_602 ++ ;
V_5 = * V_602 ;
* V_602 = 0 ;
V_3 = V_2 -> V_52 -> V_604 ( V_431 , V_10 , V_477 ,
V_593 ) ;
* V_602 = V_5 ;
}
return V_3 ;
}
int
F_213 ( struct V_476 * V_477 , struct V_146 * V_411 )
{
int V_3 ;
unsigned int V_431 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_593 ;
struct V_470 * V_471 ;
#ifdef F_214
int V_605 = 0 ;
#endif
V_3 = F_215 ( & V_477 -> V_606 , L_161 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_214
V_607:
if ( V_605 ) {
if ( V_10 )
F_164 ( V_10 ) ;
else if ( V_8 )
F_146 ( V_8 ) ;
V_477 -> V_487 &= ~ V_555 ;
F_159 ( V_431 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_593 = NULL ;
V_471 = NULL ;
V_431 = F_147 () ;
V_2 = F_127 ( V_411 ) ;
if ( F_130 ( V_2 ) ) {
V_3 = F_131 ( V_2 ) ;
F_216 ( & V_477 -> V_606 ) ;
goto V_496;
}
if ( ( V_411 -> V_355 < 20 ) ||
( V_411 -> V_355 > 60000 ) )
V_2 -> V_355 = V_608 ;
else
V_2 -> V_355 = V_411 -> V_355 ;
V_8 = F_157 ( V_2 , V_411 ) ;
if ( F_130 ( V_8 ) ) {
V_3 = F_131 ( V_8 ) ;
V_8 = NULL ;
goto V_609;
}
#ifdef F_4
if ( ( V_411 -> V_327 == true ) && ( ( V_8 -> V_2 -> V_465 &
V_466 ) == 0 ) ) {
F_5 ( V_59 , L_162 ) ;
V_3 = - V_461 ;
goto V_609;
}
#endif
V_10 = F_167 ( V_8 , V_411 ) ;
if ( F_130 ( V_10 ) ) {
V_3 = F_131 ( V_10 ) ;
V_10 = NULL ;
goto V_610;
}
if ( F_217 ( V_10 -> V_8 ) ) {
F_194 ( V_431 , V_10 , V_477 , V_411 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_195 ( V_10 -> V_546 . V_547 ) &
V_552 ) ) {
V_3 = - V_611 ;
goto V_609;
}
} else
V_10 -> V_548 = 0 ;
if ( ! V_10 -> V_612 && V_2 -> V_52 -> V_613 )
V_2 -> V_52 -> V_613 ( V_431 , V_10 ) ;
V_477 -> V_348 = V_2 -> V_52 -> V_614 ( V_10 , V_411 ) ;
V_477 -> V_346 = V_2 -> V_52 -> V_615 ( V_10 , V_411 ) ;
V_477 -> V_606 . V_616 = V_477 -> V_346 / V_237 ;
V_610:
#ifdef F_214
if ( V_605 == 0 ) {
int V_617 = F_204 ( V_431 , V_8 , V_411 , V_477 ,
false ) ;
if ( ! V_617 ) {
V_605 ++ ;
goto V_607;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_52 -> V_604 ) {
V_3 = - V_56 ;
goto V_609;
}
V_593 = F_218 ( V_411 , V_477 , V_10 ,
V_10 -> V_462 & V_463 ) ;
if ( V_593 == NULL ) {
V_3 = - V_140 ;
goto V_609;
}
V_3 = V_2 -> V_52 -> V_604 ( V_431 , V_10 , V_477 ,
V_593 ) ;
if ( V_3 != 0 && V_3 != - V_618 ) {
F_11 ( V_593 ) ;
goto V_609;
}
if ( V_3 != - V_618 ) {
V_3 = F_212 ( V_2 ,
V_431 , V_10 , V_477 ,
V_593 ) ;
if ( V_3 != 0 ) {
F_5 ( V_59 , L_163
L_164 ) ;
V_477 -> V_487 |= V_494 ;
V_3 = 0 ;
}
}
F_11 ( V_593 ) ;
}
if ( V_3 == - V_618 ) {
#ifdef F_214
if ( V_605 > V_619 ) {
V_3 = - V_620 ;
goto V_609;
}
V_3 = F_204 ( V_431 , V_8 , V_411 , V_477 , true ) ;
if ( ! V_3 ) {
V_605 ++ ;
goto V_607;
}
goto V_609;
#else
V_3 = - V_461 ;
#endif
}
if ( V_3 )
goto V_609;
V_471 = F_102 ( sizeof *V_471 , V_139 ) ;
if ( V_471 == NULL ) {
V_3 = - V_140 ;
goto V_609;
}
V_471 -> V_621 = V_8 -> V_223 ;
V_471 -> V_622 = V_10 ;
V_471 -> V_475 = V_38 ;
F_219 ( V_623 , & V_471 -> V_474 ) ;
F_219 ( V_473 , & V_471 -> V_474 ) ;
V_477 -> V_478 = V_471 ;
F_2 ( & V_477 -> V_565 ) ;
F_220 ( & V_477 -> V_566 , V_471 ) ;
F_3 ( & V_477 -> V_565 ) ;
F_25 ( V_46 , & V_477 -> V_563 ,
V_624 ) ;
V_609:
if ( V_3 ) {
if ( V_10 )
F_164 ( V_10 ) ;
else if ( V_8 )
F_146 ( V_8 ) ;
else
F_120 ( V_2 , 0 ) ;
F_216 ( & V_477 -> V_606 ) ;
}
V_496:
F_159 ( V_431 ) ;
return V_3 ;
}
int
F_221 ( const unsigned int V_431 , struct V_7 * V_8 ,
const char * V_625 , struct V_9 * V_10 ,
const struct V_498 * V_499 )
{
struct V_517 * V_626 ;
struct V_517 * V_627 ;
T_8 * V_628 ;
T_9 * V_629 ;
unsigned char * V_630 ;
int V_3 = 0 ;
int V_66 ;
T_10 V_631 , V_632 ;
if ( V_8 == NULL )
return - V_633 ;
V_626 = F_27 () ;
if ( V_626 == NULL )
return - V_140 ;
V_627 = V_626 ;
F_222 ( V_626 , V_634 ,
NULL , 4 ) ;
V_626 -> V_635 = F_223 ( V_8 -> V_2 ) ;
V_626 -> V_636 = V_8 -> V_637 ;
V_628 = ( T_8 * ) V_626 ;
V_629 = ( T_9 * ) V_627 ;
V_628 -> V_638 = 0xFF ;
V_628 -> V_462 = F_224 ( V_639 ) ;
V_630 = & V_628 -> V_640 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_641 & V_642 ) ) {
V_628 -> V_643 = F_224 ( 1 ) ;
* V_630 = 0 ;
V_630 ++ ;
} else {
V_628 -> V_643 = F_224 ( V_644 ) ;
#ifdef F_86
if ( ( V_645 & V_646 ) &&
( V_8 -> V_149 == V_167 ) )
F_225 ( V_10 -> V_362 , V_8 -> V_2 -> V_647 ,
V_8 -> V_2 -> V_641 &
V_648 ? true : false ,
V_630 ) ;
else
#endif
V_3 = F_226 ( V_10 -> V_362 , V_8 -> V_2 -> V_647 ,
V_630 , V_499 ) ;
if ( V_3 ) {
F_5 ( V_20 , L_165 ,
V_21 , V_3 ) ;
F_64 ( V_626 ) ;
return V_3 ;
}
V_630 += V_644 ;
if ( V_8 -> V_465 & V_649 ) {
* V_630 = 0 ;
V_630 ++ ;
}
}
if ( V_8 -> V_2 -> V_151 )
V_626 -> V_650 |= V_651 ;
if ( V_8 -> V_465 & V_652 ) {
V_626 -> V_650 |= V_653 ;
}
if ( V_8 -> V_465 & V_654 ) {
V_626 -> V_650 |= V_655 ;
}
if ( V_8 -> V_465 & V_649 ) {
V_626 -> V_650 |= V_656 ;
V_66 =
F_227 ( ( V_657 * ) V_630 , V_625 ,
6 *
( + 256 ) , V_499 ) ;
V_630 += 2 * V_66 ;
V_630 += 2 ;
} else {
strcpy ( V_630 , V_625 ) ;
V_630 += strlen ( V_625 ) + 1 ;
}
strcpy ( V_630 , L_166 ) ;
V_630 += strlen ( L_166 ) ;
V_630 += 1 ;
V_632 = V_630 - & V_628 -> V_640 [ 0 ] ;
V_628 -> V_658 . V_528 = F_190 ( F_228 (
V_628 -> V_658 . V_528 ) + V_632 ) ;
V_628 -> V_659 = F_224 ( V_632 ) ;
V_3 = F_229 ( V_431 , V_8 , V_626 , V_627 , & V_66 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_660 ;
V_10 -> V_453 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_661 = V_627 -> V_662 ;
V_630 = F_230 ( V_627 ) ;
V_631 = F_231 ( V_627 ) ;
V_66 = F_96 ( V_630 , V_631 - 2 ) ;
if ( V_626 -> V_650 & V_656 )
V_660 = true ;
else
V_660 = false ;
if ( V_66 == 3 ) {
if ( ( V_630 [ 0 ] == 'I' ) && ( V_630 [ 1 ] == 'P' ) &&
( V_630 [ 2 ] == 'C' ) ) {
F_5 ( V_20 , L_167 ) ;
V_10 -> V_612 = 1 ;
}
} else if ( V_66 == 2 ) {
if ( ( V_630 [ 0 ] == 'A' ) && ( V_630 [ 1 ] == ':' ) ) {
F_5 ( V_20 , L_168 ) ;
}
}
V_630 += V_66 + 1 ;
V_631 -= ( V_66 + 1 ) ;
F_232 ( V_10 -> V_454 , V_625 , sizeof( V_10 -> V_454 ) ) ;
F_11 ( V_10 -> V_663 ) ;
V_10 -> V_663 = F_233 ( V_630 ,
V_631 , V_660 ,
V_499 ) ;
F_5 ( V_20 , L_169 , V_10 -> V_663 ) ;
if ( ( V_627 -> V_664 == 3 ) ||
( V_627 -> V_664 == 7 ) )
V_10 -> V_462 = F_234 ( V_629 -> V_665 ) ;
else
V_10 -> V_462 = 0 ;
F_5 ( V_20 , L_170 , V_10 -> V_462 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_627 -> V_662 ;
}
F_64 ( V_626 ) ;
return V_3 ;
}
static void F_235 ( struct V_666 * V_120 )
{
struct V_476 * V_667 = F_23 ( V_120 , struct V_476 , V_668 ) ;
F_236 ( V_667 -> V_449 ) ;
F_11 ( V_667 ) ;
}
void
F_237 ( struct V_476 * V_477 )
{
struct V_669 * V_670 = & V_477 -> V_566 ;
struct V_671 * V_672 ;
struct V_470 * V_471 ;
F_122 ( & V_477 -> V_563 ) ;
F_2 ( & V_477 -> V_565 ) ;
while ( ( V_672 = F_238 ( V_670 ) ) ) {
V_471 = F_239 ( V_672 , struct V_470 , V_673 ) ;
F_180 ( V_471 ) ;
F_240 ( V_473 , & V_471 -> V_474 ) ;
F_241 ( V_672 , V_670 ) ;
F_3 ( & V_477 -> V_565 ) ;
F_170 ( V_471 ) ;
F_2 ( & V_477 -> V_565 ) ;
}
F_3 ( & V_477 -> V_565 ) ;
F_216 ( & V_477 -> V_606 ) ;
F_11 ( V_477 -> V_200 ) ;
F_11 ( V_477 -> V_199 ) ;
F_242 ( & V_477 -> V_668 , F_235 ) ;
}
int
F_158 ( const unsigned int V_431 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_52 -> V_674 || ! V_2 -> V_52 -> V_675 )
return - V_56 ;
if ( ! V_2 -> V_52 -> V_674 ( V_2 ) )
return 0 ;
F_243 ( V_2 , 1 ) ;
V_3 = V_2 -> V_52 -> V_675 ( V_431 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_676 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_160 ( const unsigned int V_431 , struct V_7 * V_8 ,
struct V_498 * V_677 )
{
int V_3 = - V_56 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_465 = V_2 -> V_465 ;
if ( V_678 == 0 )
V_8 -> V_465 &= ( ~ V_2 -> V_179 -> F_217 ) ;
F_5 ( V_20 , L_171 ,
V_2 -> V_641 , V_2 -> V_465 , V_2 -> V_679 ) ;
if ( V_2 -> V_52 -> V_680 )
V_3 = V_2 -> V_52 -> V_680 ( V_431 , V_8 , V_677 ) ;
if ( V_3 )
F_5 ( V_59 , L_172 , V_3 ) ;
return V_3 ;
}
static int
F_244 ( struct V_146 * V_147 , struct V_7 * V_8 )
{
V_147 -> V_149 = V_8 -> V_149 ;
if ( V_147 -> V_149 == V_156 )
return 0 ;
return F_150 ( V_147 , V_8 ) ;
}
static struct V_9 *
F_245 ( struct V_476 * V_477 , T_2 V_681 )
{
int V_3 ;
struct V_9 * V_682 = F_246 ( V_477 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_146 * V_544 ;
V_544 = F_102 ( sizeof( * V_544 ) , V_139 ) ;
if ( V_544 == NULL )
return F_72 ( - V_140 ) ;
V_544 -> V_449 = V_477 -> V_449 ;
V_544 -> V_223 = V_681 ;
V_544 -> V_222 = V_681 ;
V_544 -> V_198 = V_682 -> V_454 ;
V_544 -> V_255 = V_682 -> V_255 ;
V_544 -> V_275 = V_682 -> V_275 ;
V_544 -> V_311 = V_682 -> V_311 ;
V_544 -> V_273 = ! V_682 -> V_548 ;
V_544 -> V_149 = V_682 -> V_8 -> V_149 ;
V_544 -> V_151 = V_682 -> V_8 -> V_151 ;
V_3 = F_244 ( V_544 , V_682 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_72 ( V_3 ) ;
goto V_496;
}
F_2 ( & V_22 ) ;
++ V_682 -> V_8 -> V_2 -> V_406 ;
F_3 ( & V_22 ) ;
V_8 = F_157 ( V_682 -> V_8 -> V_2 , V_544 ) ;
if ( F_130 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_120 ( V_682 -> V_8 -> V_2 , 0 ) ;
goto V_496;
}
V_10 = F_167 ( V_8 , V_544 ) ;
if ( F_130 ( V_10 ) ) {
F_146 ( V_8 ) ;
goto V_496;
}
if ( F_217 ( V_8 ) )
F_194 ( 0 , V_10 , NULL , V_544 ) ;
V_496:
F_11 ( V_544 -> V_357 ) ;
F_11 ( V_544 -> V_362 ) ;
F_11 ( V_544 ) ;
return V_10 ;
}
struct V_9 *
F_246 ( struct V_476 * V_477 )
{
return F_173 ( F_174 ( V_477 ) ) ;
}
static struct V_470 *
F_247 ( struct V_669 * V_670 , T_2 V_144 )
{
struct V_671 * V_672 = V_670 -> V_671 ;
struct V_470 * V_471 ;
while ( V_672 ) {
V_471 = F_239 ( V_672 , struct V_470 , V_673 ) ;
if ( F_248 ( V_471 -> V_621 , V_144 ) )
V_672 = V_672 -> V_683 ;
else if ( F_249 ( V_471 -> V_621 , V_144 ) )
V_672 = V_672 -> V_684 ;
else
return V_471 ;
}
return NULL ;
}
static void
F_220 ( struct V_669 * V_670 , struct V_470 * V_685 )
{
struct V_671 * * V_484 = & ( V_670 -> V_671 ) , * V_686 = NULL ;
struct V_470 * V_471 ;
while ( * V_484 ) {
V_471 = F_239 ( * V_484 , struct V_470 , V_673 ) ;
V_686 = * V_484 ;
if ( F_248 ( V_471 -> V_621 , V_685 -> V_621 ) )
V_484 = & ( ( * V_484 ) -> V_683 ) ;
else
V_484 = & ( ( * V_484 ) -> V_684 ) ;
}
F_250 ( & V_685 -> V_673 , V_686 , V_484 ) ;
F_251 ( & V_685 -> V_673 , V_670 ) ;
}
struct V_470 *
F_252 ( struct V_476 * V_477 )
{
int V_687 ;
T_2 V_681 = F_253 () ;
struct V_470 * V_471 , * V_688 ;
if ( ! ( V_477 -> V_487 & V_589 ) )
return F_180 ( F_174 ( V_477 ) ) ;
F_2 ( & V_477 -> V_565 ) ;
V_471 = F_247 ( & V_477 -> V_566 , V_681 ) ;
if ( V_471 )
F_180 ( V_471 ) ;
F_3 ( & V_477 -> V_565 ) ;
if ( V_471 == NULL ) {
V_688 = F_102 ( sizeof( * V_471 ) , V_139 ) ;
if ( V_688 == NULL )
return F_72 ( - V_140 ) ;
V_688 -> V_621 = V_681 ;
V_688 -> V_622 = F_72 ( - V_611 ) ;
F_219 ( V_689 , & V_688 -> V_474 ) ;
F_219 ( V_473 , & V_688 -> V_474 ) ;
F_180 ( V_688 ) ;
F_2 ( & V_477 -> V_565 ) ;
V_471 = F_247 ( & V_477 -> V_566 , V_681 ) ;
if ( V_471 ) {
F_180 ( V_471 ) ;
F_3 ( & V_477 -> V_565 ) ;
F_11 ( V_688 ) ;
goto V_690;
}
V_471 = V_688 ;
F_220 ( & V_477 -> V_566 , V_471 ) ;
F_3 ( & V_477 -> V_565 ) ;
} else {
V_690:
V_687 = F_254 ( & V_471 -> V_474 , V_689 ,
V_132 ) ;
if ( V_687 ) {
F_170 ( V_471 ) ;
return F_72 ( - V_72 ) ;
}
if ( ! F_130 ( V_471 -> V_622 ) )
return V_471 ;
if ( F_24 ( V_38 , V_471 -> V_475 + V_691 ) ) {
F_170 ( V_471 ) ;
return F_72 ( - V_611 ) ;
}
if ( F_255 ( V_689 , & V_471 -> V_474 ) )
goto V_690;
}
V_471 -> V_622 = F_245 ( V_477 , V_681 ) ;
F_240 ( V_689 , & V_471 -> V_474 ) ;
F_256 ( & V_471 -> V_474 , V_689 ) ;
if ( F_130 ( V_471 -> V_622 ) ) {
F_170 ( V_471 ) ;
return F_72 ( - V_611 ) ;
}
return V_471 ;
}
static void
V_564 ( struct V_48 * V_49 )
{
struct V_476 * V_477 = F_23 ( V_49 , struct V_476 ,
V_563 . V_49 ) ;
struct V_669 * V_670 = & V_477 -> V_566 ;
struct V_671 * V_672 = F_238 ( V_670 ) ;
struct V_671 * V_5 ;
struct V_470 * V_471 ;
F_2 ( & V_477 -> V_565 ) ;
V_672 = F_238 ( V_670 ) ;
while ( V_672 != NULL ) {
V_5 = V_672 ;
V_672 = F_257 ( V_5 ) ;
V_471 = F_239 ( V_5 , struct V_470 , V_673 ) ;
if ( F_172 ( V_623 , & V_471 -> V_474 ) ||
F_61 ( & V_471 -> V_472 ) != 0 ||
F_31 ( V_471 -> V_475 + V_624 , V_38 ) )
continue;
F_180 ( V_471 ) ;
F_240 ( V_473 , & V_471 -> V_474 ) ;
F_241 ( V_5 , V_670 ) ;
F_3 ( & V_477 -> V_565 ) ;
F_170 ( V_471 ) ;
F_2 ( & V_477 -> V_565 ) ;
}
F_3 ( & V_477 -> V_565 ) ;
F_25 ( V_46 , & V_477 -> V_563 ,
V_624 ) ;
}
