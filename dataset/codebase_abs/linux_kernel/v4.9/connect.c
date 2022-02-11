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
if ( F_77 ( args , & V_147 -> V_333 ) ) {
F_5 ( V_59 , L_41 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_238 = true ;
break;
case V_334 :
if ( F_81 ( args , & V_147 -> V_335 ) ) {
F_5 ( V_59 , L_42 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_239 = true ;
break;
case V_336 :
if ( F_77 ( args , & V_147 -> V_223 ) ) {
F_5 ( V_59 , L_43 ,
V_21 ) ;
goto V_236;
}
V_211 = true ;
break;
case V_337 :
if ( F_77 ( args , & V_147 -> V_222 ) ) {
F_5 ( V_59 , L_44 ,
V_21 ) ;
goto V_236;
}
break;
case V_338 :
if ( F_81 ( args , & V_147 -> V_224 ) ) {
F_5 ( V_59 , L_45 ,
V_21 ) ;
goto V_236;
}
V_212 = true ;
break;
case V_339 :
if ( F_74 ( args , & V_141 ) ) {
F_5 ( V_59 , L_46 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_227 = V_141 ;
break;
case V_340 :
if ( F_74 ( args , & V_141 ) ) {
F_5 ( V_59 , L_47 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_226 = V_141 ;
break;
case V_341 :
if ( F_74 ( args , & V_141 ) ||
V_141 > V_342 ) {
F_5 ( V_59 , L_48 ,
V_21 ) ;
goto V_236;
}
V_218 = ( unsigned short ) V_141 ;
break;
case V_343 :
if ( F_74 ( args , & V_141 ) ) {
F_5 ( V_59 , L_49 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_344 = V_141 ;
break;
case V_345 :
if ( F_74 ( args , & V_141 ) ) {
F_5 ( V_59 , L_50 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_346 = V_141 ;
break;
case V_347 :
if ( F_74 ( args , & V_141 ) ) {
F_5 ( V_59 , L_51 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_233 = V_54 * V_141 ;
if ( V_147 -> V_233 > V_348 ) {
F_5 ( V_59 , L_52 ) ;
goto V_236;
}
break;
case V_349 :
if ( F_74 ( args , & V_141 ) ) {
F_5 ( V_59 , L_53 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_50 = V_141 ;
break;
case V_350 :
if ( F_74 ( args , & V_141 ) || ( V_141 < 20 ) ||
( V_141 > 60000 ) ) {
F_5 ( V_59 , L_54 ,
V_21 ) ;
goto V_236;
}
V_147 -> V_351 = V_141 ;
break;
case V_352 :
V_147 -> V_169 = 1 ;
V_147 -> V_353 = NULL ;
break;
case V_354 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_355;
if ( F_96 ( string , V_356 ) >
V_356 ) {
F_100 ( L_55 ) ;
goto V_236;
}
F_11 ( V_147 -> V_353 ) ;
V_147 -> V_353 = F_93 ( string , V_139 ) ;
if ( ! V_147 -> V_353 )
goto V_236;
break;
case V_357 :
V_216 = strchr ( V_201 , '=' ) ;
V_216 ++ ;
if ( ! ( V_216 < V_202 && V_216 [ 1 ] == V_137 ) ) {
F_11 ( V_147 -> V_358 ) ;
V_147 -> V_358 = NULL ;
break;
}
case V_359 :
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
F_11 ( V_147 -> V_358 ) ;
V_205 = strlen ( V_143 ) ;
V_147 -> V_358 = F_102 ( V_205 + 1 , V_139 ) ;
if ( V_147 -> V_358 == NULL ) {
F_100 ( L_56 ) ;
goto V_236;
}
for ( V_206 = 0 , V_207 = 0 ; V_206 < V_205 ; V_206 ++ , V_207 ++ ) {
V_147 -> V_358 [ V_207 ] = V_143 [ V_206 ] ;
if ( ( V_143 [ V_206 ] == V_137 ) &&
V_143 [ V_206 + 1 ] == V_137 )
V_206 ++ ;
}
V_147 -> V_358 [ V_207 ] = '\0' ;
break;
case V_360 :
V_217 = false ;
break;
case V_361 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_355;
if ( ! F_103 ( V_95 , string ,
strlen ( string ) ) ) {
F_104 ( L_57 , string ) ;
goto V_236;
}
V_217 = true ;
break;
case V_362 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_355;
if ( F_96 ( string , V_363 )
== V_363 ) {
F_100 ( L_58 ) ;
goto V_236;
}
F_11 ( V_147 -> V_364 ) ;
V_147 -> V_364 = F_93 ( string , V_139 ) ;
if ( ! V_147 -> V_364 ) {
F_100 ( L_59 ) ;
goto V_236;
}
F_5 ( V_20 , L_60 ) ;
break;
case V_365 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_355;
if ( ! F_103 (
(struct V_94 * ) & V_147 -> V_366 ,
string , strlen ( string ) ) ) {
F_100 ( L_61 ,
string ) ;
goto V_236;
}
break;
case V_367 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_355;
if ( F_96 ( string , 1024 ) >= 65 ) {
F_100 ( L_62 ) ;
goto V_236;
}
if ( strncasecmp ( string , L_63 , 7 ) != 0 ) {
F_11 ( V_147 -> V_368 ) ;
V_147 -> V_368 = F_93 ( string ,
V_139 ) ;
if ( ! V_147 -> V_368 ) {
F_100 ( L_64 ) ;
goto V_236;
}
}
F_5 ( V_20 , L_65 , string ) ;
break;
case V_369 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_355;
memset ( V_147 -> V_219 , 0x20 ,
V_220 ) ;
for ( V_206 = 0 ; V_206 < V_220 ; V_206 ++ ) {
if ( string [ V_206 ] == 0 )
break;
V_147 -> V_219 [ V_206 ] = string [ V_206 ] ;
}
if ( V_206 == V_220 && string [ V_206 ] != 0 )
F_100 ( L_66 ) ;
break;
case V_370 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_355;
memset ( V_147 -> V_221 , 0x20 ,
V_371 ) ;
for ( V_206 = 0 ; V_206 < 15 ; V_206 ++ ) {
if ( string [ V_206 ] == 0 )
break;
V_147 -> V_221 [ V_206 ] = string [ V_206 ] ;
}
if ( V_206 == V_220 && string [ V_206 ] != 0 )
F_100 ( L_67 ) ;
break;
case V_372 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_355;
if ( strncasecmp ( string , L_68 , 1 ) == 0 ) {
break;
}
F_100 ( L_69 ) ;
goto V_236;
case V_373 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_355;
if ( F_88 ( string , V_147 ) != 0 )
goto V_236;
break;
case V_374 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_355;
if ( F_84 ( string , V_147 ) != 0 )
goto V_236;
break;
case V_375 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_355;
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
F_104 ( L_70 , V_214 ) ;
goto V_236;
}
#ifndef F_105
if ( V_147 -> V_321 ) {
F_5 ( V_59 , L_71 ) ;
goto V_236;
}
#endif
if ( ! V_147 -> V_198 ) {
F_5 ( V_59 , L_72 ) ;
goto V_236;
}
if ( ! strchr ( V_147 -> V_198 + 3 , '\\' ) ) {
F_5 ( V_59 , L_73 ) ;
goto V_236;
}
if ( ! V_217 ) {
if ( ! F_103 ( V_95 , & V_147 -> V_198 [ 2 ] ,
strlen ( & V_147 -> V_198 [ 2 ] ) ) ) {
F_104 ( L_74 ) ;
goto V_236;
}
}
F_42 ( V_95 , V_218 ) ;
if ( V_211 )
V_147 -> V_209 = V_209 ;
else if ( V_209 == 1 )
F_106 ( L_75 ) ;
if ( V_212 )
V_147 -> V_210 = V_210 ;
else if ( V_210 == 1 )
F_106 ( L_76 ) ;
F_11 ( V_203 ) ;
return 0 ;
V_355:
F_100 ( L_77 ) ;
V_236:
F_11 ( string ) ;
F_11 ( V_203 ) ;
return 1 ;
}
static bool
F_107 ( struct V_94 * V_366 , struct V_94 * V_376 )
{
switch ( V_366 -> V_377 ) {
case V_378 :
return ( V_376 -> V_377 == V_378 ) ;
case V_379 : {
struct V_380 * V_381 = (struct V_380 * ) V_366 ;
struct V_380 * V_382 = (struct V_380 * ) V_376 ;
return ( V_381 -> V_383 . V_384 == V_382 -> V_383 . V_384 ) ;
}
case V_385 : {
struct V_386 * V_387 = (struct V_386 * ) V_366 ;
struct V_386 * V_388 = (struct V_386 * ) V_376 ;
return F_108 ( & V_387 -> V_389 , & V_388 -> V_389 ) ;
}
default:
F_109 ( 1 ) ;
return false ;
}
}
static bool
F_110 ( struct V_1 * V_2 , struct V_94 * V_390 )
{
T_5 V_218 , * V_391 ;
switch ( V_390 -> V_377 ) {
case V_379 :
V_391 = & ( (struct V_380 * ) & V_2 -> V_95 ) -> V_392 ;
V_218 = ( (struct V_380 * ) V_390 ) -> V_392 ;
break;
case V_385 :
V_391 = & ( (struct V_386 * ) & V_2 -> V_95 ) -> V_393 ;
V_218 = ( (struct V_386 * ) V_390 ) -> V_393 ;
break;
default:
F_109 ( 1 ) ;
return false ;
}
if ( ! V_218 ) {
V_218 = F_111 ( V_96 ) ;
if ( V_218 == * V_391 )
return true ;
V_218 = F_111 ( V_394 ) ;
}
return V_218 == * V_391 ;
}
static bool
F_112 ( struct V_1 * V_2 , struct V_94 * V_390 ,
struct V_94 * V_366 )
{
switch ( V_390 -> V_377 ) {
case V_379 : {
struct V_380 * V_395 = (struct V_380 * ) V_390 ;
struct V_380 * V_396 =
(struct V_380 * ) & V_2 -> V_95 ;
if ( V_395 -> V_383 . V_384 != V_396 -> V_383 . V_384 )
return false ;
break;
}
case V_385 : {
struct V_386 * V_397 = (struct V_386 * ) V_390 ;
struct V_386 * V_398 =
(struct V_386 * ) & V_2 -> V_95 ;
if ( ! F_108 ( & V_397 -> V_389 ,
& V_398 -> V_389 ) )
return false ;
if ( V_397 -> V_399 != V_398 -> V_399 )
return false ;
break;
}
default:
F_109 ( 1 ) ;
return false ;
}
if ( ! F_107 ( V_366 , (struct V_94 * ) & V_2 -> V_366 ) )
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
struct V_94 * V_390 = (struct V_94 * ) & V_147 -> V_95 ;
if ( V_147 -> V_324 )
return 0 ;
if ( ( V_2 -> V_179 != V_147 -> V_179 ) || ( V_2 -> V_52 != V_147 -> V_52 ) )
return 0 ;
if ( ! F_116 ( F_117 ( V_2 ) , V_123 -> V_400 -> V_401 ) )
return 0 ;
if ( ! F_112 ( V_2 , V_390 ,
(struct V_94 * ) & V_147 -> V_366 ) )
return 0 ;
if ( ! F_110 ( V_2 , V_390 ) )
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
++ V_2 -> V_402 ;
F_3 ( & V_22 ) ;
F_5 ( V_20 , L_78 ) ;
return V_2 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_120 ( struct V_1 * V_2 )
{
struct V_121 * V_403 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_402 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_121 ( F_117 ( V_2 ) ) ;
F_16 ( & V_2 -> V_105 ) ;
F_3 ( & V_22 ) ;
F_122 ( & V_2 -> V_47 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
F_11 ( V_2 -> V_34 . V_35 ) ;
V_2 -> V_34 . V_35 = NULL ;
V_2 -> V_34 . V_36 = 0 ;
V_403 = F_66 ( & V_2 -> V_131 , NULL ) ;
if ( V_403 )
F_125 ( V_404 , V_403 ) ;
}
static struct V_1 *
F_126 ( struct V_146 * V_405 )
{
struct V_1 * V_406 = NULL ;
int V_3 ;
F_5 ( V_20 , L_79 , V_405 -> V_198 ) ;
V_406 = F_118 ( V_405 ) ;
if ( V_406 )
return V_406 ;
V_406 = F_102 ( sizeof( struct V_1 ) , V_139 ) ;
if ( ! V_406 ) {
V_3 = - V_140 ;
goto V_407;
}
V_406 -> V_52 = V_405 -> V_52 ;
V_406 -> V_179 = V_405 -> V_179 ;
F_127 ( V_406 , F_128 ( V_123 -> V_400 -> V_401 ) ) ;
V_406 -> V_57 = F_71 ( V_405 -> V_198 ) ;
if ( F_129 ( V_406 -> V_57 ) ) {
V_3 = F_130 ( V_406 -> V_57 ) ;
goto V_408;
}
V_406 -> V_251 = V_405 -> V_251 ;
V_406 -> V_253 = V_405 -> V_253 ;
V_406 -> V_409 = V_405 -> V_410 ;
V_406 -> V_411 = 0 ;
V_406 -> V_107 = 1 ;
F_131 ( & V_406 -> V_63 ) ;
F_131 ( & V_406 -> V_108 ) ;
F_12 ( & V_406 -> V_109 ) ;
F_132 ( & V_406 -> V_27 ) ;
memcpy ( V_406 -> V_412 ,
V_405 -> V_219 , V_371 ) ;
memcpy ( V_406 -> V_413 ,
V_405 -> V_221 , V_371 ) ;
V_406 -> V_33 = false ;
V_406 -> V_32 = 0 ;
V_406 -> V_37 = V_38 ;
F_133 ( & V_406 -> V_106 ) ;
F_12 ( & V_406 -> V_105 ) ;
F_12 ( & V_406 -> V_23 ) ;
F_134 ( & V_406 -> V_47 , F_22 ) ;
memcpy ( & V_406 -> V_366 , & V_405 -> V_366 ,
sizeof( V_406 -> V_366 ) ) ;
memcpy ( & V_406 -> V_95 , & V_405 -> V_95 ,
sizeof( V_406 -> V_95 ) ) ;
#ifdef F_4
F_135 ( V_406 -> V_414 ) ;
#endif
V_406 -> V_15 = V_51 ;
++ V_406 -> V_402 ;
if ( V_405 -> V_50 >= V_415 &&
V_405 -> V_50 <= V_416 )
V_406 -> V_50 = V_405 -> V_50 * V_54 ;
else
V_406 -> V_50 = V_235 * V_54 ;
V_3 = F_136 ( V_406 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_80 ) ;
goto V_408;
}
F_137 ( V_417 ) ;
V_406 -> V_131 = F_138 ( F_57 ,
V_406 , L_81 ) ;
if ( F_129 ( V_406 -> V_131 ) ) {
V_3 = F_130 ( V_406 -> V_131 ) ;
F_5 ( V_59 , L_82 , V_3 ) ;
F_139 ( V_417 ) ;
goto V_408;
}
V_406 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_140 ( & V_406 -> V_105 , & V_418 ) ;
F_3 ( & V_22 ) ;
F_141 ( V_406 ) ;
F_25 ( V_46 , & V_406 -> V_47 , V_406 -> V_50 ) ;
return V_406 ;
V_408:
F_123 ( V_406 ) ;
F_121 ( F_117 ( V_406 ) ) ;
V_407:
if ( V_406 ) {
if ( ! F_129 ( V_406 -> V_57 ) )
F_11 ( V_406 -> V_57 ) ;
if ( V_406 -> V_28 )
F_10 ( V_406 -> V_28 ) ;
F_11 ( V_406 ) ;
}
return F_72 ( V_3 ) ;
}
static int F_142 ( struct V_7 * V_8 , struct V_146 * V_147 )
{
if ( V_147 -> V_149 != V_150 &&
V_147 -> V_149 != V_8 -> V_149 )
return 0 ;
switch ( V_8 -> V_149 ) {
case V_156 :
if ( ! F_143 ( V_147 -> V_222 , V_8 -> V_222 ) )
return 0 ;
break;
default:
if ( V_8 -> V_419 == NULL ) {
if ( ! V_147 -> V_169 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_419 ,
V_147 -> V_353 ? V_147 -> V_353 : L_83 ,
V_356 ) )
return 0 ;
if ( ( V_147 -> V_353 && strlen ( V_147 -> V_353 ) != 0 ) &&
V_8 -> V_358 != NULL &&
strncmp ( V_8 -> V_358 ,
V_147 -> V_358 ? V_147 -> V_358 : L_83 ,
V_420 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_144 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_7 * V_8 ;
F_2 ( & V_22 ) ;
F_119 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_8 -> V_421 == V_16 )
continue;
if ( ! F_142 ( V_8 , V_147 ) )
continue;
++ V_8 -> V_422 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_145 ( struct V_7 * V_8 )
{
unsigned int V_3 , V_423 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_20 , L_84 , V_21 , V_8 -> V_422 ) ;
F_2 ( & V_22 ) ;
if ( V_8 -> V_421 == V_16 ) {
F_3 ( & V_22 ) ;
return;
}
if ( -- V_8 -> V_422 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
if ( V_8 -> V_421 == V_62 )
V_8 -> V_421 = V_16 ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_421 == V_16 && V_2 -> V_52 -> V_424 ) {
V_423 = F_146 () ;
V_3 = V_2 -> V_52 -> V_424 ( V_423 , V_8 ) ;
if ( V_3 )
F_5 ( V_59 , L_85 ,
V_21 , V_3 ) ;
F_147 ( V_423 ) ;
}
F_2 ( & V_22 ) ;
F_16 ( & V_8 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_148 ( V_8 ) ;
F_120 ( V_2 ) ;
}
static int
F_149 ( struct V_146 * V_147 , struct V_7 * V_8 )
{
int V_3 = 0 ;
const char * V_137 , * V_425 ;
char * V_426 ;
T_6 V_36 ;
struct V_427 * V_427 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_380 * V_428 ;
struct V_386 * V_429 ;
const struct V_430 * V_431 ;
V_426 = F_73 ( V_432 , V_139 ) ;
if ( ! V_426 )
return - V_140 ;
switch ( V_2 -> V_95 . V_433 ) {
case V_379 :
V_428 = (struct V_380 * ) & V_2 -> V_95 ;
sprintf ( V_426 , L_86 , & V_428 -> V_383 . V_384 ) ;
break;
case V_385 :
V_429 = (struct V_386 * ) & V_2 -> V_95 ;
sprintf ( V_426 , L_87 , & V_429 -> V_389 . V_434 ) ;
break;
default:
F_5 ( V_20 , L_88 ,
V_2 -> V_95 . V_433 ) ;
V_3 = - V_138 ;
goto V_407;
}
F_5 ( V_20 , L_89 , V_21 , V_426 ) ;
V_427 = F_150 ( & V_435 , V_426 , L_83 ) ;
if ( F_129 ( V_427 ) ) {
if ( ! V_8 -> V_436 ) {
F_5 ( V_20 , L_90 ) ;
V_3 = F_130 ( V_427 ) ;
goto V_407;
}
sprintf ( V_426 , L_91 , V_8 -> V_436 ) ;
F_5 ( V_20 , L_89 , V_21 , V_426 ) ;
V_427 = F_150 ( & V_435 , V_426 , L_83 ) ;
if ( F_129 ( V_427 ) ) {
V_3 = F_130 ( V_427 ) ;
goto V_407;
}
}
F_151 ( & V_427 -> V_437 ) ;
V_431 = V_430 ( V_427 ) ;
if ( F_152 ( V_431 ) ) {
V_3 = V_431 ? F_130 ( V_431 ) : - V_138 ;
goto V_438;
}
V_425 = V_431 -> V_201 ;
V_137 = F_153 ( V_425 , V_431 -> V_439 , ':' ) ;
F_5 ( V_20 , L_92 , V_425 ) ;
if ( ! V_137 ) {
F_5 ( V_20 , L_93 ,
V_431 -> V_439 ) ;
V_3 = - V_138 ;
goto V_438;
}
V_36 = V_137 - V_425 ;
if ( V_36 > V_356 || V_36 <= 0 ) {
F_5 ( V_20 , L_94 ,
V_36 ) ;
V_3 = - V_138 ;
goto V_438;
}
V_147 -> V_353 = F_91 ( V_425 , V_36 , V_139 ) ;
if ( ! V_147 -> V_353 ) {
F_5 ( V_20 , L_95 ,
V_36 ) ;
V_3 = - V_140 ;
goto V_438;
}
F_5 ( V_20 , L_96 , V_21 , V_147 -> V_353 ) ;
V_36 = V_427 -> V_439 - ( V_36 + 1 ) ;
if ( V_36 > V_420 || V_36 <= 0 ) {
F_5 ( V_20 , L_97 , V_36 ) ;
V_3 = - V_138 ;
F_11 ( V_147 -> V_353 ) ;
V_147 -> V_353 = NULL ;
goto V_438;
}
++ V_137 ;
V_147 -> V_358 = F_91 ( V_137 , V_36 , V_139 ) ;
if ( ! V_147 -> V_358 ) {
F_5 ( V_20 , L_98 ,
V_36 ) ;
V_3 = - V_140 ;
F_11 ( V_147 -> V_353 ) ;
V_147 -> V_353 = NULL ;
goto V_438;
}
V_438:
F_154 ( & V_427 -> V_437 ) ;
F_155 ( V_427 ) ;
V_407:
F_11 ( V_426 ) ;
F_5 ( V_20 , L_99 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_156 ( struct V_1 * V_2 , struct V_146 * V_405 )
{
int V_3 = - V_140 ;
unsigned int V_423 ;
struct V_7 * V_8 ;
struct V_380 * V_390 = (struct V_380 * ) & V_2 -> V_95 ;
struct V_386 * V_397 = (struct V_386 * ) & V_2 -> V_95 ;
V_423 = F_146 () ;
V_8 = F_144 ( V_2 , V_405 ) ;
if ( V_8 ) {
F_5 ( V_20 , L_100 ,
V_8 -> V_421 ) ;
F_8 ( & V_8 -> V_440 ) ;
V_3 = F_157 ( V_423 , V_8 ) ;
if ( V_3 ) {
F_15 ( & V_8 -> V_440 ) ;
F_145 ( V_8 ) ;
F_158 ( V_423 ) ;
return F_72 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_5 ( V_20 , L_101 ) ;
V_3 = F_159 ( V_423 , V_8 ,
V_405 -> V_441 ) ;
if ( V_3 ) {
F_15 ( & V_8 -> V_440 ) ;
F_145 ( V_8 ) ;
F_158 ( V_423 ) ;
return F_72 ( V_3 ) ;
}
}
F_15 ( & V_8 -> V_440 ) ;
F_120 ( V_2 ) ;
F_158 ( V_423 ) ;
return V_8 ;
}
F_5 ( V_20 , L_102 ) ;
V_8 = F_160 () ;
if ( V_8 == NULL )
goto V_442;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_95 . V_433 == V_385 )
sprintf ( V_8 -> V_443 , L_103 , & V_397 -> V_389 ) ;
else
sprintf ( V_8 -> V_443 , L_104 , & V_390 -> V_383 ) ;
if ( V_405 -> V_353 ) {
V_8 -> V_419 = F_93 ( V_405 -> V_353 , V_139 ) ;
if ( ! V_8 -> V_419 )
goto V_442;
}
if ( V_405 -> V_358 ) {
V_8 -> V_358 = F_93 ( V_405 -> V_358 , V_139 ) ;
if ( ! V_8 -> V_358 )
goto V_442;
}
if ( V_405 -> V_364 ) {
V_8 -> V_436 = F_93 ( V_405 -> V_364 , V_139 ) ;
if ( ! V_8 -> V_436 )
goto V_442;
}
V_8 -> V_222 = V_405 -> V_222 ;
V_8 -> V_223 = V_405 -> V_223 ;
V_8 -> V_149 = V_405 -> V_149 ;
V_8 -> V_151 = V_405 -> V_151 ;
F_8 ( & V_8 -> V_440 ) ;
V_3 = F_157 ( V_423 , V_8 ) ;
if ( ! V_3 )
V_3 = F_159 ( V_423 , V_8 , V_405 -> V_441 ) ;
F_15 ( & V_8 -> V_440 ) ;
if ( V_3 )
goto V_442;
F_2 ( & V_22 ) ;
F_140 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_158 ( V_423 ) ;
return V_8 ;
V_442:
F_148 ( V_8 ) ;
F_158 ( V_423 ) ;
return F_72 ( V_3 ) ;
}
static int F_161 ( struct V_9 * V_10 , const char * V_134 )
{
if ( V_10 -> V_444 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_445 , V_134 , V_446 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_162 ( struct V_7 * V_8 , const char * V_134 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_22 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_26 ) ;
if ( ! F_161 ( V_10 , V_134 ) )
continue;
++ V_10 -> V_447 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_163 ( struct V_9 * V_10 )
{
unsigned int V_423 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( V_20 , L_105 , V_21 , V_10 -> V_447 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_447 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_423 = F_146 () ;
if ( V_8 -> V_2 -> V_52 -> V_448 )
V_8 -> V_2 -> V_52 -> V_448 ( V_423 , V_10 ) ;
F_147 ( V_423 ) ;
F_164 ( V_10 ) ;
F_165 ( V_10 ) ;
F_145 ( V_8 ) ;
}
static struct V_9 *
F_166 ( struct V_7 * V_8 , struct V_146 * V_405 )
{
int V_3 , V_423 ;
struct V_9 * V_10 ;
V_10 = F_162 ( V_8 , V_405 -> V_198 ) ;
if ( V_10 ) {
F_5 ( V_20 , L_106 ) ;
F_145 ( V_8 ) ;
if ( V_10 -> V_314 != V_405 -> V_314 )
F_5 ( V_59 , L_107 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_52 -> V_449 ) {
V_3 = - V_56 ;
goto V_450;
}
V_10 = F_167 () ;
if ( V_10 == NULL ) {
V_3 = - V_140 ;
goto V_450;
}
V_10 -> V_8 = V_8 ;
if ( V_405 -> V_358 ) {
V_10 -> V_358 = F_93 ( V_405 -> V_358 , V_139 ) ;
if ( ! V_10 -> V_358 ) {
V_3 = - V_140 ;
goto V_450;
}
}
V_423 = F_146 () ;
V_3 = V_8 -> V_2 -> V_52 -> V_449 ( V_423 , V_8 , V_405 -> V_198 , V_10 ,
V_405 -> V_441 ) ;
F_158 ( V_423 ) ;
F_5 ( V_20 , L_108 , V_3 ) ;
if ( V_3 )
goto V_450;
if ( V_405 -> V_269 ) {
V_10 -> V_451 &= ~ V_452 ;
F_5 ( V_20 , L_109 , V_10 -> V_451 ) ;
}
V_10 -> V_314 = V_405 -> V_314 ;
V_10 -> V_453 = false ;
if ( V_405 -> V_327 ) {
if ( V_8 -> V_2 -> V_179 -> V_454 == 0 ) {
F_5 ( V_59 ,
L_110 ) ;
V_3 = - V_455 ;
goto V_450;
#ifdef F_4
} else if ( V_8 -> V_2 -> V_456 &
V_457 )
V_10 -> V_453 = true ;
else {
F_5 ( V_59 ,
L_111 ) ;
V_3 = - V_455 ;
goto V_450;
#endif
}
#ifdef F_4
} else if ( ( V_10 -> V_456 & V_458 )
&& ( V_8 -> V_2 -> V_456 & V_457 )
&& ( V_405 -> V_326 == false ) ) {
F_5 ( V_20 , L_112 ) ;
V_10 -> V_453 = true ;
#endif
} else if ( V_405 -> V_329 ) {
if ( V_8 -> V_2 -> V_179 -> V_454 == 0 ) {
F_5 ( V_59 ,
L_113 ) ;
V_3 = - V_455 ;
goto V_450;
}
V_10 -> V_459 = true ;
}
V_10 -> V_255 = V_405 -> V_255 ;
V_10 -> V_275 = V_405 -> V_275 ;
V_10 -> V_311 = V_405 -> V_311 ;
F_12 ( & V_10 -> V_460 ) ;
F_2 ( & V_22 ) ;
F_140 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_168 ( V_10 ) ;
return V_10 ;
V_450:
F_165 ( V_10 ) ;
return F_72 ( V_3 ) ;
}
void
F_169 ( struct V_461 * V_462 )
{
if ( ! V_462 || F_129 ( V_462 ) )
return;
if ( ! F_170 ( & V_462 -> V_463 ) ||
F_171 ( V_464 , & V_462 -> V_465 ) ) {
V_462 -> V_466 = V_38 ;
return;
}
if ( ! F_129 ( F_172 ( V_462 ) ) )
F_163 ( F_172 ( V_462 ) ) ;
F_11 ( V_462 ) ;
return;
}
static inline struct V_461 *
F_173 ( struct V_467 * V_468 )
{
return V_468 -> V_469 ;
}
static int
F_174 ( struct V_470 * V_471 , struct V_472 * V_473 )
{
struct V_467 * V_474 = F_175 ( V_471 ) ;
struct V_467 * V_475 = V_473 -> V_468 ;
if ( ( V_471 -> V_476 & V_477 ) != ( V_473 -> V_30 & V_477 ) )
return 0 ;
if ( ( V_474 -> V_478 & V_479 ) !=
( V_475 -> V_478 & V_479 ) )
return 0 ;
if ( V_475 -> V_346 && V_475 -> V_346 < V_474 -> V_346 )
return 0 ;
if ( V_475 -> V_344 && V_475 -> V_344 < V_474 -> V_344 )
return 0 ;
if ( ! F_143 ( V_474 -> V_480 , V_475 -> V_480 ) || ! F_176 ( V_474 -> V_481 , V_475 -> V_481 ) )
return 0 ;
if ( V_474 -> V_482 != V_475 -> V_482 ||
V_474 -> V_483 != V_475 -> V_483 )
return 0 ;
if ( strcmp ( V_474 -> V_441 -> V_484 , V_475 -> V_441 -> V_484 ) )
return 0 ;
if ( V_474 -> V_233 != V_475 -> V_233 )
return 0 ;
return 1 ;
}
static int
F_177 ( struct V_470 * V_471 , struct V_472 * V_473 )
{
struct V_467 * V_474 = F_175 ( V_471 ) ;
struct V_467 * V_475 = V_473 -> V_468 ;
if ( V_474 -> V_478 & V_485 ) {
if ( ! ( V_475 -> V_478 & V_485 ) )
return 0 ;
if ( strcmp ( V_475 -> V_199 , V_474 -> V_199 ) )
return 0 ;
return 1 ;
}
return 0 ;
}
int
F_178 ( struct V_470 * V_471 , void * V_201 )
{
struct V_472 * V_473 = (struct V_472 * ) V_201 ;
struct V_146 * V_405 ;
struct V_467 * V_468 ;
struct V_1 * V_486 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_461 * V_462 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_468 = F_175 ( V_471 ) ;
V_462 = F_179 ( F_173 ( V_468 ) ) ;
if ( F_129 ( V_462 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_172 ( V_462 ) ;
V_8 = V_10 -> V_8 ;
V_486 = V_8 -> V_2 ;
V_405 = V_473 -> V_147 ;
if ( ! F_115 ( V_486 , V_405 ) ||
! F_142 ( V_8 , V_405 ) ||
! F_161 ( V_10 , V_405 -> V_198 ) ||
! F_177 ( V_471 , V_473 ) ) {
V_3 = 0 ;
goto V_487;
}
V_3 = F_174 ( V_471 , V_473 ) ;
V_487:
F_3 ( & V_22 ) ;
F_169 ( V_462 ) ;
return V_3 ;
}
int
F_180 ( const unsigned int V_423 , struct V_7 * V_8 , const char * V_488 ,
const struct V_489 * V_490 , unsigned int * V_491 ,
struct V_492 * * V_493 , int V_225 )
{
char * V_494 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_52 -> V_449 || ! V_8 -> V_2 -> V_52 -> V_495 )
return - V_56 ;
* V_491 = 0 ;
* V_493 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_494 = F_73 ( 2 +
F_96 ( V_8 -> V_443 , V_496 * 2 )
+ 1 + 4 + 2 , V_139 ) ;
if ( V_494 == NULL )
return - V_140 ;
V_494 [ 0 ] = '\\' ;
V_494 [ 1 ] = '\\' ;
strcpy ( V_494 + 2 , V_8 -> V_443 ) ;
strcpy ( V_494 + 2 + strlen ( V_8 -> V_443 ) , L_114 ) ;
V_3 = V_8 -> V_2 -> V_52 -> V_449 ( V_423 , V_8 , V_494 , NULL ,
V_490 ) ;
F_5 ( V_20 , L_115 , V_3 , V_8 -> V_25 ) ;
F_11 ( V_494 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_52 -> V_495 ( V_423 , V_8 , V_488 ,
V_493 , V_491 ,
V_490 , V_225 ) ;
return V_3 ;
}
static inline void
F_181 ( struct V_497 * V_498 )
{
struct V_498 * V_499 = V_498 -> V_499 ;
F_182 ( ! F_183 ( V_499 ) ) ;
F_184 ( V_499 , L_116 ,
& V_500 [ 0 ] , L_117 , & V_501 [ 0 ] ) ;
}
static inline void
F_185 ( struct V_497 * V_498 )
{
struct V_498 * V_499 = V_498 -> V_499 ;
F_182 ( ! F_183 ( V_499 ) ) ;
F_184 ( V_499 , L_118 ,
& V_500 [ 1 ] , L_119 , & V_501 [ 1 ] ) ;
}
static inline void
F_181 ( struct V_497 * V_498 )
{
}
static inline void
F_185 ( struct V_497 * V_498 )
{
}
static void F_186 ( char * V_502 , char * V_503 , unsigned int V_66 )
{
unsigned int V_206 , V_207 ;
for ( V_206 = 0 , V_207 = 0 ; V_206 < ( V_66 ) ; V_206 ++ ) {
V_502 [ V_207 ] = 'A' + ( 0x0F & ( V_503 [ V_206 ] >> 4 ) ) ;
V_502 [ V_207 + 1 ] = 'A' + ( 0x0F & V_503 [ V_206 ] ) ;
V_207 += 2 ;
}
}
static int
F_187 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_366 . V_433 != V_378 ) {
struct V_497 * V_497 = V_2 -> V_28 ;
V_3 = V_497 -> V_52 -> V_504 ( V_497 ,
(struct V_94 * ) & V_2 -> V_366 ,
sizeof( V_2 -> V_366 ) ) ;
if ( V_3 < 0 ) {
struct V_380 * V_381 ;
struct V_386 * V_387 ;
V_381 = (struct V_380 * ) & V_2 -> V_366 ;
V_387 = (struct V_386 * ) & V_2 -> V_366 ;
if ( V_387 -> V_505 == V_385 )
F_5 ( V_59 , L_120 ,
& V_387 -> V_389 , V_3 ) ;
else
F_5 ( V_59 , L_121 ,
& V_381 -> V_383 . V_384 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_188 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_506 * V_507 ;
struct V_508 * V_509 ;
V_507 = F_102 ( sizeof( struct V_506 ) ,
V_139 ) ;
if ( V_507 ) {
V_507 -> V_510 . V_511 . V_512 = 32 ;
if ( V_2 -> V_413 [ 0 ] != 0 )
F_186 ( V_507 -> V_510 .
V_511 . V_513 ,
V_2 -> V_413 ,
V_371 ) ;
else
F_186 ( V_507 -> V_510 .
V_511 . V_513 ,
V_514 ,
V_371 ) ;
V_507 -> V_510 . V_511 . V_515 = 32 ;
if ( V_2 -> V_412 [ 0 ] != 0 )
F_186 ( V_507 -> V_510 .
V_511 . V_516 ,
V_2 -> V_412 ,
V_371 ) ;
else
F_186 ( V_507 -> V_510 .
V_511 . V_516 ,
L_122 ,
V_371 ) ;
V_507 -> V_510 . V_511 . V_517 = 0 ;
V_507 -> V_510 . V_511 . V_518 = 0 ;
V_509 = (struct V_508 * ) V_507 ;
V_509 -> V_519 = F_189 ( 0x81000044 ) ;
V_3 = F_190 ( V_2 , V_509 , 0x44 ) ;
F_11 ( V_507 ) ;
F_36 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_391 ;
int V_520 , V_521 ;
struct V_497 * V_497 = V_2 -> V_28 ;
struct V_94 * V_522 ;
V_522 = (struct V_94 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_433 == V_385 ) {
V_391 = ( (struct V_386 * ) V_522 ) -> V_393 ;
V_520 = sizeof( struct V_386 ) ;
V_521 = V_385 ;
} else {
V_391 = ( (struct V_380 * ) V_522 ) -> V_392 ;
V_520 = sizeof( struct V_380 ) ;
V_521 = V_379 ;
}
if ( V_497 == NULL ) {
V_3 = F_191 ( F_117 ( V_2 ) , V_521 , V_523 ,
V_524 , & V_497 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_123 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_5 ( V_20 , L_124 ) ;
V_2 -> V_28 = V_497 ;
V_497 -> V_499 -> V_525 = V_526 ;
if ( V_521 == V_385 )
F_185 ( V_497 ) ;
else
F_181 ( V_497 ) ;
}
V_3 = F_187 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_497 -> V_499 -> V_527 = 7 * V_54 ;
V_497 -> V_499 -> V_528 = 5 * V_54 ;
if ( V_2 -> V_253 ) {
if ( V_497 -> V_499 -> V_529 < ( 200 * 1024 ) )
V_497 -> V_499 -> V_529 = 200 * 1024 ;
if ( V_497 -> V_499 -> V_530 < ( 140 * 1024 ) )
V_497 -> V_499 -> V_530 = 140 * 1024 ;
}
if ( V_2 -> V_409 ) {
int V_531 = 1 ;
V_3 = F_192 ( V_497 , V_532 , V_533 ,
( char * ) & V_531 , sizeof( V_531 ) ) ;
if ( V_3 )
F_5 ( V_20 , L_125 ,
V_3 ) ;
}
F_5 ( V_20 , L_126 ,
V_497 -> V_499 -> V_529 ,
V_497 -> V_499 -> V_530 , V_497 -> V_499 -> V_527 ) ;
V_3 = V_497 -> V_52 -> V_534 ( V_497 , V_522 , V_520 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_20 , L_127 , V_3 ) ;
F_10 ( V_497 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_391 == F_111 ( V_394 ) )
V_3 = F_188 ( V_2 ) ;
return V_3 ;
}
static int
F_136 ( struct V_1 * V_2 )
{
T_5 * V_391 ;
struct V_386 * V_397 = (struct V_386 * ) & V_2 -> V_95 ;
struct V_380 * V_390 = (struct V_380 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_433 == V_385 )
V_391 = & V_397 -> V_393 ;
else
V_391 = & V_390 -> V_392 ;
if ( * V_391 == 0 ) {
int V_3 ;
* V_391 = F_111 ( V_96 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_391 = F_111 ( V_394 ) ;
}
return F_18 ( V_2 ) ;
}
void F_193 ( unsigned int V_423 , struct V_9 * V_10 ,
struct V_467 * V_468 , struct V_146 * V_535 )
{
T_7 V_536 = F_194 ( V_10 -> V_537 . V_538 ) ;
if ( V_535 && V_535 -> V_273 ) {
V_10 -> V_537 . V_538 = 0 ;
V_10 -> V_539 = 0 ;
F_5 ( V_20 , L_128 ) ;
return;
} else if ( V_535 )
V_10 -> V_539 = 1 ;
if ( V_10 -> V_539 == 0 ) {
F_5 ( V_20 , L_129 ) ;
return;
}
if ( ! F_195 ( V_423 , V_10 ) ) {
T_7 V_540 = F_194 ( V_10 -> V_537 . V_538 ) ;
F_5 ( V_20 , L_130 , V_540 ) ;
if ( V_535 == NULL ) {
if ( ( V_536 & V_541 ) == 0 )
V_540 &= ~ V_541 ;
if ( ( V_536 & V_542 ) == 0 ) {
if ( V_540 & V_542 )
F_5 ( V_59 , L_131 ) ;
V_540 &= ~ V_542 ;
} else if ( ( V_540 & V_542 ) == 0 ) {
F_5 ( V_59 , L_132 ) ;
F_5 ( V_59 , L_133 ) ;
}
}
if ( V_540 & V_543 )
F_5 ( V_59 , L_134 ) ;
V_540 &= V_544 ;
if ( V_535 && V_535 -> V_308 )
V_540 &= ~ V_541 ;
else if ( V_541 & V_540 ) {
F_5 ( V_20 , L_135 ) ;
if ( V_468 )
V_468 -> V_478 |=
V_545 ;
}
if ( V_535 && V_535 -> V_231 == 0 )
V_540 &= ~ V_542 ;
else if ( V_540 & V_542 ) {
F_5 ( V_20 , L_136 ) ;
if ( V_468 )
V_468 -> V_478 |=
V_546 ;
}
F_5 ( V_20 , L_137 , ( int ) V_540 ) ;
#ifdef F_62
if ( V_540 & V_547 )
F_5 ( V_20 , L_138 ) ;
if ( V_540 & V_548 )
F_5 ( V_20 , L_139 ) ;
if ( V_540 & V_542 )
F_5 ( V_20 , L_140 ) ;
if ( V_540 & V_549 )
F_5 ( V_20 , L_141 ) ;
if ( V_540 & V_541 )
F_5 ( V_20 , L_142 ) ;
if ( V_540 & V_550 )
F_5 ( V_20 , L_143 ) ;
if ( V_540 & V_551 )
F_5 ( V_20 , L_144 ) ;
if ( V_540 & V_552 )
F_5 ( V_20 , L_145 ) ;
if ( V_540 & V_543 )
F_5 ( V_20 , L_146 ) ;
#endif
if ( F_196 ( V_423 , V_10 , V_540 ) ) {
if ( V_535 == NULL ) {
F_5 ( V_20 , L_147 ) ;
} else
F_5 ( V_59 , L_148 ) ;
}
}
}
int F_197 ( struct V_146 * V_553 ,
struct V_467 * V_468 )
{
F_134 ( & V_468 -> V_554 , V_555 ) ;
F_133 ( & V_468 -> V_556 ) ;
V_468 -> V_557 = V_558 ;
V_468 -> V_344 = V_553 -> V_344 ;
V_468 -> V_346 = V_553 -> V_346 ;
V_468 -> V_480 = V_553 -> V_223 ;
V_468 -> V_481 = V_553 -> V_224 ;
V_468 -> V_482 = V_553 -> V_227 ;
V_468 -> V_483 = V_553 -> V_226 ;
F_5 ( V_20 , L_149 ,
V_468 -> V_482 , V_468 -> V_483 ) ;
V_468 -> V_233 = V_553 -> V_233 ;
V_468 -> V_441 = V_553 -> V_441 ;
if ( V_553 -> V_258 )
V_468 -> V_478 |= V_559 ;
if ( V_553 -> V_285 )
V_468 -> V_478 |= V_560 ;
if ( V_553 -> V_288 )
V_468 -> V_478 |= V_561 ;
if ( V_553 -> V_232 )
V_468 -> V_478 |= V_562 ;
if ( V_553 -> V_225 )
V_468 -> V_478 |= V_563 ;
if ( V_553 -> V_261 )
V_468 -> V_478 |= V_564 ;
if ( V_553 -> V_244 )
V_468 -> V_478 |= V_565 ;
if ( V_553 -> V_266 )
V_468 -> V_478 |= V_566 ;
if ( V_553 -> V_277 )
V_468 -> V_478 |= V_567 ;
if ( V_553 -> V_298 )
V_468 -> V_478 |= V_568 ;
if ( V_553 -> V_283 )
V_468 -> V_478 |= V_569 ;
if ( V_553 -> V_303 )
V_468 -> V_478 |= V_570 ;
if ( V_553 -> V_305 )
V_468 -> V_478 |= V_571 ;
if ( V_553 -> V_238 ) {
V_468 -> V_478 |= V_572 ;
V_468 -> V_573 = V_553 -> V_333 ;
}
if ( V_553 -> V_239 ) {
V_468 -> V_478 |= V_574 ;
V_468 -> V_575 = V_553 -> V_335 ;
}
if ( V_553 -> V_209 )
V_468 -> V_478 |= V_576 ;
if ( V_553 -> V_210 )
V_468 -> V_478 |= V_577 ;
if ( V_553 -> V_290 )
V_468 -> V_478 |= V_578 ;
if ( V_553 -> V_317 )
V_468 -> V_478 |= V_579 ;
if ( V_553 -> V_321 )
V_468 -> V_478 |= ( V_580 |
V_559 ) ;
if ( V_553 -> V_173 )
V_468 -> V_478 |= V_581 ;
if ( V_553 -> V_172 ) {
F_5 ( V_20 , L_150 ) ;
V_468 -> V_478 |= V_582 ;
}
if ( V_553 -> V_319 ) {
if ( V_553 -> V_266 ) {
F_5 ( V_59 , L_151 ) ;
}
V_468 -> V_478 |= V_583 ;
}
if ( ( V_553 -> V_305 ) && ( V_553 -> V_290 ) )
F_5 ( V_59 , L_152 ) ;
if ( V_553 -> V_199 ) {
V_468 -> V_199 = F_93 ( V_553 -> V_199 , V_139 ) ;
if ( V_468 -> V_199 == NULL )
return - V_140 ;
}
return 0 ;
}
static void
F_198 ( struct V_146 * V_405 )
{
F_11 ( V_405 -> V_353 ) ;
F_199 ( V_405 -> V_358 ) ;
F_11 ( V_405 -> V_198 ) ;
F_11 ( V_405 -> V_364 ) ;
F_11 ( V_405 -> V_368 ) ;
F_11 ( V_405 -> V_199 ) ;
}
void
F_200 ( struct V_146 * V_405 )
{
if ( ! V_405 )
return;
F_198 ( V_405 ) ;
F_11 ( V_405 ) ;
}
static char *
F_201 ( const struct V_146 * V_147 ,
const struct V_467 * V_468 )
{
char * V_584 , * V_196 ;
unsigned int V_585 = V_147 -> V_199 ? strlen ( V_147 -> V_199 ) + 1 : 0 ;
unsigned int V_586 = F_96 ( V_147 -> V_198 , V_446 + 1 ) ;
V_584 = F_73 ( V_586 + V_585 + 1 , V_139 ) ;
if ( V_584 == NULL )
return F_72 ( - V_140 ) ;
strncpy ( V_584 , V_147 -> V_198 , V_586 ) ;
V_196 = V_584 + V_586 ;
if ( V_585 ) {
* V_196 = F_202 ( V_468 ) ;
strncpy ( V_196 + 1 , V_147 -> V_199 , V_585 ) ;
V_196 += V_585 ;
}
* V_196 = '\0' ;
F_92 ( V_584 , F_202 ( V_468 ) ) ;
F_5 ( V_20 , L_153 , V_21 , V_584 ) ;
return V_584 ;
}
static int
F_203 ( const unsigned int V_423 , struct V_7 * V_8 ,
struct V_146 * V_405 , struct V_467 * V_468 ,
int V_587 )
{
int V_3 ;
unsigned int V_491 = 0 ;
struct V_492 * V_493 = NULL ;
char * V_584 = NULL , * V_588 = NULL , * V_589 = NULL ;
V_584 = F_201 ( V_405 , V_468 ) ;
if ( F_129 ( V_584 ) )
return F_130 ( V_584 ) ;
V_588 = V_587 ? V_584 + 1 : V_405 -> V_198 + 1 ;
V_3 = F_180 ( V_423 , V_8 , V_588 , V_468 -> V_441 ,
& V_491 , & V_493 , F_204 ( V_468 ) ) ;
if ( ! V_3 && V_491 > 0 ) {
char * V_590 = NULL ;
V_589 = F_205 ( V_468 -> V_200 ,
V_584 + 1 , V_493 ,
& V_590 ) ;
F_206 ( V_493 , V_491 ) ;
if ( F_129 ( V_589 ) ) {
V_3 = F_130 ( V_589 ) ;
V_589 = NULL ;
} else {
F_198 ( V_405 ) ;
V_3 = F_207 ( V_405 , V_589 ,
V_590 ) ;
}
F_11 ( V_590 ) ;
F_11 ( V_468 -> V_200 ) ;
V_468 -> V_200 = V_589 ;
}
F_11 ( V_584 ) ;
return V_3 ;
}
static int
F_207 ( struct V_146 * V_405 , char * V_591 ,
const char * V_195 )
{
int V_3 = 0 ;
if ( F_94 ( V_591 , V_195 , V_405 ) )
return - V_138 ;
if ( V_405 -> V_169 ) {
F_5 ( V_20 , L_154 ) ;
F_11 ( V_405 -> V_353 ) ;
V_405 -> V_353 = NULL ;
} else if ( V_405 -> V_353 ) {
F_5 ( V_20 , L_155 , V_405 -> V_353 ) ;
} else {
F_5 ( V_59 , L_156 ) ;
return - V_138 ;
}
if ( V_405 -> V_368 == NULL ) {
V_405 -> V_441 = F_208 () ;
} else {
V_405 -> V_441 = F_209 ( V_405 -> V_368 ) ;
if ( V_405 -> V_441 == NULL ) {
F_5 ( V_59 , L_157 ,
V_405 -> V_368 ) ;
return - V_592 ;
}
}
return V_3 ;
}
struct V_146 *
F_210 ( char * V_591 , const char * V_195 )
{
int V_3 ;
struct V_146 * V_405 ;
V_405 = F_73 ( sizeof( struct V_146 ) , V_139 ) ;
if ( ! V_405 )
return F_72 ( - V_140 ) ;
V_3 = F_207 ( V_405 , V_591 , V_195 ) ;
if ( V_3 ) {
F_200 ( V_405 ) ;
V_405 = F_72 ( V_3 ) ;
}
return V_405 ;
}
static int
F_211 ( struct V_1 * V_2 ,
unsigned int V_423 ,
struct V_9 * V_10 ,
struct V_467 * V_468 ,
char * V_584 )
{
int V_3 ;
char * V_593 ;
char V_594 , V_5 ;
V_594 = F_202 ( V_468 ) ;
V_593 = V_584 ;
V_3 = V_2 -> V_52 -> V_595 ( V_423 , V_10 , V_468 , L_83 ) ;
while ( V_3 == 0 ) {
while ( * V_593 == V_594 )
V_593 ++ ;
if ( ! * V_593 )
break;
while ( * V_593 && * V_593 != V_594 )
V_593 ++ ;
V_5 = * V_593 ;
* V_593 = 0 ;
V_3 = V_2 -> V_52 -> V_595 ( V_423 , V_10 , V_468 ,
V_584 ) ;
* V_593 = V_5 ;
}
return V_3 ;
}
int
F_212 ( struct V_467 * V_468 , struct V_146 * V_405 )
{
int V_3 ;
unsigned int V_423 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_584 ;
struct V_461 * V_462 ;
#ifdef F_213
int V_596 = 0 ;
#endif
V_3 = F_214 ( & V_468 -> V_597 , L_158 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_213
V_598:
if ( V_596 ) {
if ( V_10 )
F_163 ( V_10 ) ;
else if ( V_8 )
F_145 ( V_8 ) ;
V_468 -> V_478 &= ~ V_546 ;
F_158 ( V_423 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_584 = NULL ;
V_462 = NULL ;
V_423 = F_146 () ;
V_2 = F_126 ( V_405 ) ;
if ( F_129 ( V_2 ) ) {
V_3 = F_130 ( V_2 ) ;
F_215 ( & V_468 -> V_597 ) ;
goto V_487;
}
if ( ( V_405 -> V_351 < 20 ) ||
( V_405 -> V_351 > 60000 ) )
V_2 -> V_351 = V_599 ;
else
V_2 -> V_351 = V_405 -> V_351 ;
V_8 = F_156 ( V_2 , V_405 ) ;
if ( F_129 ( V_8 ) ) {
V_3 = F_130 ( V_8 ) ;
V_8 = NULL ;
goto V_600;
}
#ifdef F_4
if ( ( V_405 -> V_327 == true ) && ( ( V_8 -> V_2 -> V_456 &
V_457 ) == 0 ) ) {
F_5 ( V_59 , L_159 ) ;
V_3 = - V_455 ;
goto V_600;
}
#endif
V_10 = F_166 ( V_8 , V_405 ) ;
if ( F_129 ( V_10 ) ) {
V_3 = F_130 ( V_10 ) ;
V_10 = NULL ;
goto V_601;
}
if ( F_216 ( V_10 -> V_8 ) ) {
F_193 ( V_423 , V_10 , V_468 , V_405 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_194 ( V_10 -> V_537 . V_538 ) &
V_543 ) ) {
V_3 = - V_602 ;
goto V_600;
}
} else
V_10 -> V_539 = 0 ;
if ( ! V_10 -> V_603 && V_2 -> V_52 -> V_604 )
V_2 -> V_52 -> V_604 ( V_423 , V_10 ) ;
V_468 -> V_346 = V_2 -> V_52 -> V_605 ( V_10 , V_405 ) ;
V_468 -> V_344 = V_2 -> V_52 -> V_606 ( V_10 , V_405 ) ;
V_468 -> V_597 . V_607 = V_468 -> V_344 / V_237 ;
V_601:
#ifdef F_213
if ( V_596 == 0 ) {
int V_608 = F_203 ( V_423 , V_8 , V_405 , V_468 ,
false ) ;
if ( ! V_608 ) {
V_596 ++ ;
goto V_598;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_52 -> V_595 ) {
V_3 = - V_56 ;
goto V_600;
}
V_584 = F_217 ( V_405 , V_468 , V_10 ) ;
if ( V_584 == NULL ) {
V_3 = - V_140 ;
goto V_600;
}
V_3 = V_2 -> V_52 -> V_595 ( V_423 , V_10 , V_468 ,
V_584 ) ;
if ( V_3 != 0 && V_3 != - V_609 ) {
F_11 ( V_584 ) ;
goto V_600;
}
if ( V_3 != - V_609 ) {
V_3 = F_211 ( V_2 ,
V_423 , V_10 , V_468 ,
V_584 ) ;
if ( V_3 != 0 ) {
F_5 ( V_59 , L_160
L_161 ) ;
V_468 -> V_478 |= V_485 ;
V_3 = 0 ;
}
}
F_11 ( V_584 ) ;
}
if ( V_3 == - V_609 ) {
#ifdef F_213
if ( V_596 > V_610 ) {
V_3 = - V_611 ;
goto V_600;
}
V_3 = F_203 ( V_423 , V_8 , V_405 , V_468 , true ) ;
if ( ! V_3 ) {
V_596 ++ ;
goto V_598;
}
goto V_600;
#else
V_3 = - V_455 ;
#endif
}
if ( V_3 )
goto V_600;
V_462 = F_102 ( sizeof *V_462 , V_139 ) ;
if ( V_462 == NULL ) {
V_3 = - V_140 ;
goto V_600;
}
V_462 -> V_612 = V_8 -> V_223 ;
V_462 -> V_613 = V_10 ;
V_462 -> V_466 = V_38 ;
F_218 ( V_614 , & V_462 -> V_465 ) ;
F_218 ( V_464 , & V_462 -> V_465 ) ;
V_468 -> V_469 = V_462 ;
F_2 ( & V_468 -> V_556 ) ;
F_219 ( & V_468 -> V_557 , V_462 ) ;
F_3 ( & V_468 -> V_556 ) ;
F_25 ( V_46 , & V_468 -> V_554 ,
V_615 ) ;
V_600:
if ( V_3 ) {
if ( V_10 )
F_163 ( V_10 ) ;
else if ( V_8 )
F_145 ( V_8 ) ;
else
F_120 ( V_2 ) ;
F_215 ( & V_468 -> V_597 ) ;
}
V_487:
F_158 ( V_423 ) ;
return V_3 ;
}
int
F_220 ( const unsigned int V_423 , struct V_7 * V_8 ,
const char * V_616 , struct V_9 * V_10 ,
const struct V_489 * V_490 )
{
struct V_508 * V_617 ;
struct V_508 * V_618 ;
T_8 * V_619 ;
T_9 * V_620 ;
unsigned char * V_621 ;
int V_3 = 0 ;
int V_66 ;
T_10 V_622 , V_623 ;
if ( V_8 == NULL )
return - V_624 ;
V_617 = F_27 () ;
if ( V_617 == NULL )
return - V_140 ;
V_618 = V_617 ;
F_221 ( V_617 , V_625 ,
NULL , 4 ) ;
V_617 -> V_626 = F_222 ( V_8 -> V_2 ) ;
V_617 -> V_627 = V_8 -> V_628 ;
V_619 = ( T_8 * ) V_617 ;
V_620 = ( T_9 * ) V_618 ;
V_619 -> V_629 = 0xFF ;
V_619 -> V_451 = F_223 ( V_630 ) ;
V_621 = & V_619 -> V_631 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_632 & V_633 ) ) {
V_619 -> V_634 = F_223 ( 1 ) ;
* V_621 = 0 ;
V_621 ++ ;
} else {
V_619 -> V_634 = F_223 ( V_635 ) ;
#ifdef F_86
if ( ( V_636 & V_637 ) &&
( V_8 -> V_149 == V_167 ) )
F_224 ( V_10 -> V_358 , V_8 -> V_2 -> V_638 ,
V_8 -> V_2 -> V_632 &
V_639 ? true : false ,
V_621 ) ;
else
#endif
V_3 = F_225 ( V_10 -> V_358 , V_8 -> V_2 -> V_638 ,
V_621 , V_490 ) ;
if ( V_3 ) {
F_5 ( V_20 , L_162 ,
V_21 , V_3 ) ;
F_64 ( V_617 ) ;
return V_3 ;
}
V_621 += V_635 ;
if ( V_8 -> V_456 & V_640 ) {
* V_621 = 0 ;
V_621 ++ ;
}
}
if ( V_8 -> V_2 -> V_151 )
V_617 -> V_641 |= V_642 ;
if ( V_8 -> V_456 & V_643 ) {
V_617 -> V_641 |= V_644 ;
}
if ( V_8 -> V_456 & V_645 ) {
V_617 -> V_641 |= V_646 ;
}
if ( V_8 -> V_456 & V_640 ) {
V_617 -> V_641 |= V_647 ;
V_66 =
F_226 ( ( V_648 * ) V_621 , V_616 ,
6 *
( + 256 ) , V_490 ) ;
V_621 += 2 * V_66 ;
V_621 += 2 ;
} else {
strcpy ( V_621 , V_616 ) ;
V_621 += strlen ( V_616 ) + 1 ;
}
strcpy ( V_621 , L_163 ) ;
V_621 += strlen ( L_163 ) ;
V_621 += 1 ;
V_623 = V_621 - & V_619 -> V_631 [ 0 ] ;
V_619 -> V_649 . V_519 = F_189 ( F_227 (
V_619 -> V_649 . V_519 ) + V_623 ) ;
V_619 -> V_650 = F_223 ( V_623 ) ;
V_3 = F_228 ( V_423 , V_8 , V_617 , V_618 , & V_66 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_651 ;
V_10 -> V_444 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_652 = V_618 -> V_653 ;
V_621 = F_229 ( V_618 ) ;
V_622 = F_230 ( V_618 ) ;
V_66 = F_96 ( V_621 , V_622 - 2 ) ;
if ( V_617 -> V_641 & V_647 )
V_651 = true ;
else
V_651 = false ;
if ( V_66 == 3 ) {
if ( ( V_621 [ 0 ] == 'I' ) && ( V_621 [ 1 ] == 'P' ) &&
( V_621 [ 2 ] == 'C' ) ) {
F_5 ( V_20 , L_164 ) ;
V_10 -> V_603 = 1 ;
}
} else if ( V_66 == 2 ) {
if ( ( V_621 [ 0 ] == 'A' ) && ( V_621 [ 1 ] == ':' ) ) {
F_5 ( V_20 , L_165 ) ;
}
}
V_621 += V_66 + 1 ;
V_622 -= ( V_66 + 1 ) ;
F_231 ( V_10 -> V_445 , V_616 , sizeof( V_10 -> V_445 ) ) ;
F_11 ( V_10 -> V_654 ) ;
V_10 -> V_654 = F_232 ( V_621 ,
V_622 , V_651 ,
V_490 ) ;
F_5 ( V_20 , L_166 , V_10 -> V_654 ) ;
if ( ( V_618 -> V_655 == 3 ) ||
( V_618 -> V_655 == 7 ) )
V_10 -> V_451 = F_233 ( V_620 -> V_656 ) ;
else
V_10 -> V_451 = 0 ;
F_5 ( V_20 , L_167 , V_10 -> V_451 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_618 -> V_653 ;
}
F_64 ( V_617 ) ;
return V_3 ;
}
static void F_234 ( struct V_657 * V_120 )
{
struct V_467 * V_658 = F_23 ( V_120 , struct V_467 , V_659 ) ;
F_235 ( V_658 -> V_441 ) ;
F_11 ( V_658 ) ;
}
void
F_236 ( struct V_467 * V_468 )
{
struct V_660 * V_661 = & V_468 -> V_557 ;
struct V_662 * V_663 ;
struct V_461 * V_462 ;
F_122 ( & V_468 -> V_554 ) ;
F_2 ( & V_468 -> V_556 ) ;
while ( ( V_663 = F_237 ( V_661 ) ) ) {
V_462 = F_238 ( V_663 , struct V_461 , V_664 ) ;
F_179 ( V_462 ) ;
F_239 ( V_464 , & V_462 -> V_465 ) ;
F_240 ( V_663 , V_661 ) ;
F_3 ( & V_468 -> V_556 ) ;
F_169 ( V_462 ) ;
F_2 ( & V_468 -> V_556 ) ;
}
F_3 ( & V_468 -> V_556 ) ;
F_215 ( & V_468 -> V_597 ) ;
F_11 ( V_468 -> V_200 ) ;
F_11 ( V_468 -> V_199 ) ;
F_241 ( & V_468 -> V_659 , F_234 ) ;
}
int
F_157 ( const unsigned int V_423 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_52 -> V_665 || ! V_2 -> V_52 -> V_666 )
return - V_56 ;
if ( ! V_2 -> V_52 -> V_665 ( V_2 ) )
return 0 ;
F_242 ( V_2 , 1 ) ;
V_3 = V_2 -> V_52 -> V_666 ( V_423 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_667 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_159 ( const unsigned int V_423 , struct V_7 * V_8 ,
struct V_489 * V_668 )
{
int V_3 = - V_56 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_456 = V_2 -> V_456 ;
if ( V_669 == 0 )
V_8 -> V_456 &= ( ~ V_2 -> V_179 -> F_216 ) ;
F_5 ( V_20 , L_168 ,
V_2 -> V_632 , V_2 -> V_456 , V_2 -> V_670 ) ;
if ( V_2 -> V_52 -> V_671 )
V_3 = V_2 -> V_52 -> V_671 ( V_423 , V_8 , V_668 ) ;
if ( V_3 )
F_5 ( V_59 , L_169 , V_3 ) ;
return V_3 ;
}
static int
F_243 ( struct V_146 * V_147 , struct V_7 * V_8 )
{
V_147 -> V_149 = V_8 -> V_149 ;
if ( V_147 -> V_149 == V_156 )
return 0 ;
return F_149 ( V_147 , V_8 ) ;
}
static struct V_9 *
F_244 ( struct V_467 * V_468 , T_2 V_672 )
{
int V_3 ;
struct V_9 * V_673 = F_245 ( V_468 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_146 * V_535 ;
V_535 = F_102 ( sizeof( * V_535 ) , V_139 ) ;
if ( V_535 == NULL )
return F_72 ( - V_140 ) ;
V_535 -> V_441 = V_468 -> V_441 ;
V_535 -> V_223 = V_672 ;
V_535 -> V_222 = V_672 ;
V_535 -> V_198 = V_673 -> V_445 ;
V_535 -> V_255 = V_673 -> V_255 ;
V_535 -> V_275 = V_673 -> V_275 ;
V_535 -> V_311 = V_673 -> V_311 ;
V_535 -> V_273 = ! V_673 -> V_539 ;
V_535 -> V_149 = V_673 -> V_8 -> V_149 ;
V_535 -> V_151 = V_673 -> V_8 -> V_151 ;
V_3 = F_243 ( V_535 , V_673 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_72 ( V_3 ) ;
goto V_487;
}
F_2 ( & V_22 ) ;
++ V_673 -> V_8 -> V_2 -> V_402 ;
F_3 ( & V_22 ) ;
V_8 = F_156 ( V_673 -> V_8 -> V_2 , V_535 ) ;
if ( F_129 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_120 ( V_673 -> V_8 -> V_2 ) ;
goto V_487;
}
V_10 = F_166 ( V_8 , V_535 ) ;
if ( F_129 ( V_10 ) ) {
F_145 ( V_8 ) ;
goto V_487;
}
if ( F_216 ( V_8 ) )
F_193 ( 0 , V_10 , NULL , V_535 ) ;
V_487:
F_11 ( V_535 -> V_353 ) ;
F_11 ( V_535 -> V_358 ) ;
F_11 ( V_535 ) ;
return V_10 ;
}
struct V_9 *
F_245 ( struct V_467 * V_468 )
{
return F_172 ( F_173 ( V_468 ) ) ;
}
static struct V_461 *
F_246 ( struct V_660 * V_661 , T_2 V_144 )
{
struct V_662 * V_663 = V_661 -> V_662 ;
struct V_461 * V_462 ;
while ( V_663 ) {
V_462 = F_238 ( V_663 , struct V_461 , V_664 ) ;
if ( F_247 ( V_462 -> V_612 , V_144 ) )
V_663 = V_663 -> V_674 ;
else if ( F_248 ( V_462 -> V_612 , V_144 ) )
V_663 = V_663 -> V_675 ;
else
return V_462 ;
}
return NULL ;
}
static void
F_219 ( struct V_660 * V_661 , struct V_461 * V_676 )
{
struct V_662 * * V_475 = & ( V_661 -> V_662 ) , * V_677 = NULL ;
struct V_461 * V_462 ;
while ( * V_475 ) {
V_462 = F_238 ( * V_475 , struct V_461 , V_664 ) ;
V_677 = * V_475 ;
if ( F_247 ( V_462 -> V_612 , V_676 -> V_612 ) )
V_475 = & ( ( * V_475 ) -> V_674 ) ;
else
V_475 = & ( ( * V_475 ) -> V_675 ) ;
}
F_249 ( & V_676 -> V_664 , V_677 , V_475 ) ;
F_250 ( & V_676 -> V_664 , V_661 ) ;
}
struct V_461 *
F_251 ( struct V_467 * V_468 )
{
int V_678 ;
T_2 V_672 = F_252 () ;
struct V_461 * V_462 , * V_679 ;
if ( ! ( V_468 -> V_478 & V_580 ) )
return F_179 ( F_173 ( V_468 ) ) ;
F_2 ( & V_468 -> V_556 ) ;
V_462 = F_246 ( & V_468 -> V_557 , V_672 ) ;
if ( V_462 )
F_179 ( V_462 ) ;
F_3 ( & V_468 -> V_556 ) ;
if ( V_462 == NULL ) {
V_679 = F_102 ( sizeof( * V_462 ) , V_139 ) ;
if ( V_679 == NULL )
return F_72 ( - V_140 ) ;
V_679 -> V_612 = V_672 ;
V_679 -> V_613 = F_72 ( - V_602 ) ;
F_218 ( V_680 , & V_679 -> V_465 ) ;
F_218 ( V_464 , & V_679 -> V_465 ) ;
F_179 ( V_679 ) ;
F_2 ( & V_468 -> V_556 ) ;
V_462 = F_246 ( & V_468 -> V_557 , V_672 ) ;
if ( V_462 ) {
F_179 ( V_462 ) ;
F_3 ( & V_468 -> V_556 ) ;
F_11 ( V_679 ) ;
goto V_681;
}
V_462 = V_679 ;
F_219 ( & V_468 -> V_557 , V_462 ) ;
F_3 ( & V_468 -> V_556 ) ;
} else {
V_681:
V_678 = F_253 ( & V_462 -> V_465 , V_680 ,
V_132 ) ;
if ( V_678 ) {
F_169 ( V_462 ) ;
return F_72 ( - V_72 ) ;
}
if ( ! F_129 ( V_462 -> V_613 ) )
return V_462 ;
if ( F_24 ( V_38 , V_462 -> V_466 + V_682 ) ) {
F_169 ( V_462 ) ;
return F_72 ( - V_602 ) ;
}
if ( F_254 ( V_680 , & V_462 -> V_465 ) )
goto V_681;
}
V_462 -> V_613 = F_244 ( V_468 , V_672 ) ;
F_239 ( V_680 , & V_462 -> V_465 ) ;
F_255 ( & V_462 -> V_465 , V_680 ) ;
if ( F_129 ( V_462 -> V_613 ) ) {
F_169 ( V_462 ) ;
return F_72 ( - V_602 ) ;
}
return V_462 ;
}
static void
V_555 ( struct V_48 * V_49 )
{
struct V_467 * V_468 = F_23 ( V_49 , struct V_467 ,
V_554 . V_49 ) ;
struct V_660 * V_661 = & V_468 -> V_557 ;
struct V_662 * V_663 = F_237 ( V_661 ) ;
struct V_662 * V_5 ;
struct V_461 * V_462 ;
F_2 ( & V_468 -> V_556 ) ;
V_663 = F_237 ( V_661 ) ;
while ( V_663 != NULL ) {
V_5 = V_663 ;
V_663 = F_256 ( V_5 ) ;
V_462 = F_238 ( V_5 , struct V_461 , V_664 ) ;
if ( F_171 ( V_614 , & V_462 -> V_465 ) ||
F_61 ( & V_462 -> V_463 ) != 0 ||
F_31 ( V_462 -> V_466 + V_615 , V_38 ) )
continue;
F_179 ( V_462 ) ;
F_239 ( V_464 , & V_462 -> V_465 ) ;
F_240 ( V_5 , V_661 ) ;
F_3 ( & V_468 -> V_556 ) ;
F_169 ( V_462 ) ;
F_2 ( & V_468 -> V_556 ) ;
}
F_3 ( & V_468 -> V_556 ) ;
F_25 ( V_46 , & V_468 -> V_554 ,
V_615 ) ;
}
