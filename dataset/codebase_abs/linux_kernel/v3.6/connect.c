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
F_5 ( 1 , L_1 ) ;
F_5 ( 1 , L_2 , V_20 ) ;
F_2 ( & V_21 ) ;
F_6 (tmp, &server->smb_ses_list) {
V_8 = F_7 ( V_5 , struct V_7 , V_22 ) ;
V_8 -> V_23 = true ;
V_8 -> V_24 = 0 ;
F_6 (tmp2, &ses->tcon_list) {
V_10 = F_7 ( V_6 , struct V_9 , V_25 ) ;
V_10 -> V_23 = true ;
}
}
F_3 ( & V_21 ) ;
F_5 ( 1 , L_3 , V_20 ) ;
F_8 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_27 ) {
F_5 ( 1 , L_4 , V_2 -> V_27 -> V_28 ,
V_2 -> V_27 -> V_29 ) ;
F_9 ( V_2 -> V_27 , V_30 ) ;
F_5 ( 1 , L_5 ,
V_2 -> V_27 -> V_28 ,
V_2 -> V_27 -> V_29 ) ;
F_10 ( V_2 -> V_27 ) ;
V_2 -> V_27 = NULL ;
}
V_2 -> V_31 = 0 ;
V_2 -> V_32 = false ;
F_11 ( V_2 -> V_33 . V_34 ) ;
V_2 -> V_33 . V_34 = NULL ;
V_2 -> V_33 . V_35 = 0 ;
V_2 -> V_36 = V_37 ;
F_12 ( & V_2 -> V_26 ) ;
F_13 ( & V_13 ) ;
F_5 ( 1 , L_6 , V_20 ) ;
F_2 ( & V_14 ) ;
F_14 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_7 ( V_5 , struct V_11 , V_38 ) ;
if ( V_12 -> V_39 == V_40 )
V_12 -> V_39 = V_41 ;
F_15 ( & V_12 -> V_38 , & V_13 ) ;
}
F_3 ( & V_14 ) ;
F_5 ( 1 , L_7 , V_20 ) ;
F_14 (tmp, tmp2, &retry_list) {
V_12 = F_7 ( V_5 , struct V_11 , V_38 ) ;
F_16 ( & V_12 -> V_38 ) ;
V_12 -> V_42 ( V_12 ) ;
}
do {
F_17 () ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 ) {
F_5 ( 1 , L_8 , V_3 ) ;
F_19 ( 3000 ) ;
} else {
F_20 ( & V_43 ) ;
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 != V_16 )
V_2 -> V_15 = V_44 ;
F_3 ( & V_14 ) ;
}
} while ( V_2 -> V_15 == V_17 );
return V_3 ;
}
static void
F_21 ( struct V_45 * V_46 )
{
int V_3 ;
struct V_1 * V_2 = F_22 ( V_46 ,
struct V_1 , V_47 . V_46 ) ;
if ( ! V_2 -> V_48 -> V_49 || V_2 -> V_48 -> V_49 ( V_2 ) ||
( V_2 -> V_48 -> V_50 && ! V_2 -> V_48 -> V_50 ( V_2 ) ) ||
F_23 ( V_37 , V_2 -> V_36 + V_51 - V_52 ) )
goto V_53;
V_3 = V_2 -> V_48 -> V_47 ? V_2 -> V_48 -> V_47 ( V_2 ) : - V_54 ;
if ( V_3 )
F_5 ( 1 , L_9 ,
V_2 -> V_55 ) ;
V_53:
F_24 ( V_56 , & V_2 -> V_47 , V_51 ) ;
}
static bool
F_25 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_57 ) {
V_2 -> V_57 = ( char * ) F_26 () ;
if ( ! V_2 -> V_57 ) {
F_27 ( 1 , L_10 ) ;
F_19 ( 3000 ) ;
return false ;
}
} else if ( V_2 -> V_58 ) {
memset ( V_2 -> V_57 , 0 , F_28 ( V_2 ) ) ;
}
if ( ! V_2 -> V_59 ) {
V_2 -> V_59 = ( char * ) F_29 () ;
if ( ! V_2 -> V_59 ) {
F_27 ( 1 , L_11 ) ;
F_19 ( 1000 ) ;
return false ;
}
} else {
memset ( V_2 -> V_59 , 0 , F_28 ( V_2 ) ) ;
}
return true ;
}
static bool
F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 == V_60 &&
F_31 ( V_37 , V_2 -> V_36 + 2 * V_51 ) ) {
F_27 ( 1 , L_12
L_13 , V_2 -> V_55 ,
( 2 * V_51 ) / V_52 ) ;
F_1 ( V_2 ) ;
F_32 ( & V_2 -> V_61 ) ;
return true ;
}
return false ;
}
static unsigned int
F_33 ( struct V_62 * V_63 , struct V_62 * V_64 , unsigned int V_65 ,
T_1 V_66 )
{
T_1 V_67 = 0 ;
while ( V_66 || ! V_64 -> V_68 ) {
int V_69 = F_34 ( V_66 , V_64 -> V_68 ) ;
V_66 -= V_69 ;
V_67 += V_69 ;
if ( V_64 -> V_68 == V_67 ) {
V_64 ++ ;
V_65 -- ;
V_67 = 0 ;
}
}
memcpy ( V_63 , V_64 , sizeof( * V_64 ) * V_65 ) ;
V_63 -> V_70 += V_67 ;
V_63 -> V_68 -= V_67 ;
return V_65 ;
}
static struct V_62 *
F_35 ( struct V_1 * V_2 , unsigned int V_65 )
{
struct V_62 * V_71 ;
if ( V_2 -> V_64 && V_65 <= V_2 -> V_72 )
return V_2 -> V_64 ;
V_71 = F_36 ( sizeof( * V_71 ) * V_65 , V_73 ) ;
if ( V_71 ) {
F_11 ( V_2 -> V_64 ) ;
V_2 -> V_64 = V_71 ;
V_2 -> V_72 = V_65 ;
}
return V_71 ;
}
int
F_37 ( struct V_1 * V_2 , struct V_62 * V_74 ,
unsigned int V_65 , unsigned int V_75 )
{
int V_76 = 0 ;
int V_77 ;
unsigned int V_78 ;
struct V_79 V_80 ;
struct V_62 * V_64 ;
V_64 = F_35 ( V_2 , V_65 ) ;
if ( ! V_64 )
return - V_81 ;
V_80 . V_82 = NULL ;
V_80 . V_83 = 0 ;
for ( V_77 = 0 ; V_75 ; V_77 += V_76 , V_75 -= V_76 ) {
F_17 () ;
if ( F_30 ( V_2 ) ) {
V_77 = - V_84 ;
break;
}
V_78 = F_33 ( V_64 , V_74 , V_65 , V_77 ) ;
V_76 = F_38 ( V_2 -> V_27 , & V_80 ,
V_64 , V_78 , V_75 , 0 ) ;
if ( V_2 -> V_15 == V_16 ) {
V_77 = - V_85 ;
break;
} else if ( V_2 -> V_15 == V_17 ) {
F_1 ( V_2 ) ;
V_77 = - V_84 ;
break;
} else if ( V_76 == - V_86 ||
V_76 == - V_84 ||
V_76 == - V_87 ) {
F_39 ( 1000 , 2000 ) ;
V_76 = 0 ;
continue;
} else if ( V_76 <= 0 ) {
F_5 ( 1 , L_14
L_15 , V_75 , V_76 ) ;
F_1 ( V_2 ) ;
V_77 = - V_84 ;
break;
}
}
return V_77 ;
}
int
F_40 ( struct V_1 * V_2 , char * V_88 ,
unsigned int V_75 )
{
struct V_62 V_64 ;
V_64 . V_70 = V_88 ;
V_64 . V_68 = V_75 ;
return F_37 ( V_2 , & V_64 , 1 , V_75 ) ;
}
static bool
F_41 ( struct V_1 * V_2 , unsigned char type )
{
switch ( type ) {
case V_89 :
return true ;
case V_90 :
F_5 ( 1 , L_16 ) ;
break;
case V_91 :
F_5 ( 1 , L_17 ) ;
break;
case V_92 :
F_5 ( 1 , L_18 ) ;
F_19 ( 1000 ) ;
F_42 ( (struct V_93 * ) & V_2 -> V_94 , V_95 ) ;
F_1 ( V_2 ) ;
F_32 ( & V_2 -> V_61 ) ;
break;
default:
F_27 ( 1 , L_19 , type ) ;
F_1 ( V_2 ) ;
}
return false ;
}
void
F_43 ( struct V_11 * V_96 , bool V_97 )
{
#ifdef F_44
V_96 -> V_98 = V_37 ;
#endif
F_2 ( & V_14 ) ;
if ( ! V_97 )
V_96 -> V_39 = V_99 ;
else
V_96 -> V_39 = V_100 ;
F_16 ( & V_96 -> V_38 ) ;
F_3 ( & V_14 ) ;
}
static void
F_45 ( struct V_11 * V_96 , struct V_1 * V_2 ,
char * V_88 , int V_97 )
{
if ( V_2 -> V_48 -> V_101 &&
V_2 -> V_48 -> V_101 ( V_96 , V_2 , V_88 , V_97 ) )
return;
V_96 -> V_102 = V_88 ;
V_96 -> V_58 = V_2 -> V_58 ;
if ( ! V_96 -> V_103 ) {
if ( V_2 -> V_58 )
V_2 -> V_57 = NULL ;
else
V_2 -> V_59 = NULL ;
}
F_43 ( V_96 , V_97 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_76 ;
F_2 ( & V_21 ) ;
F_16 ( & V_2 -> V_104 ) ;
F_3 ( & V_21 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_47 ( & V_2 -> V_61 ) ;
F_2 ( & V_2 -> V_105 ) ;
if ( V_2 -> V_106 <= 0 )
V_2 -> V_106 = 1 ;
F_3 ( & V_2 -> V_105 ) ;
F_47 ( & V_2 -> V_107 ) ;
F_19 ( 125 ) ;
if ( V_2 -> V_27 ) {
F_10 ( V_2 -> V_27 ) ;
V_2 -> V_27 = NULL ;
}
if ( ! F_48 ( & V_2 -> V_108 ) ) {
struct V_4 V_109 ;
struct V_11 * V_12 ;
struct V_4 * V_5 , * V_6 ;
F_13 ( & V_109 ) ;
F_2 ( & V_14 ) ;
F_14 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_7 ( V_5 , struct V_11 , V_38 ) ;
F_5 ( 1 , L_20 , V_12 -> V_96 ) ;
V_12 -> V_39 = V_110 ;
F_15 ( & V_12 -> V_38 , & V_109 ) ;
}
F_3 ( & V_14 ) ;
F_14 (tmp, tmp2, &dispose_list) {
V_12 = F_7 ( V_5 , struct V_11 , V_38 ) ;
F_5 ( 1 , L_21 , V_12 -> V_96 ) ;
F_16 ( & V_12 -> V_38 ) ;
V_12 -> V_42 ( V_12 ) ;
}
F_19 ( 125 ) ;
}
if ( ! F_48 ( & V_2 -> V_108 ) ) {
F_5 ( 1 , L_22 ) ;
F_19 ( 46000 ) ;
}
F_11 ( V_2 -> V_55 ) ;
F_11 ( V_2 -> V_64 ) ;
F_11 ( V_2 ) ;
V_76 = F_49 ( & V_111 ) ;
if ( V_76 > 0 )
F_50 ( V_112 , V_76 + V_113 ,
V_114 ) ;
}
static int
F_51 ( struct V_1 * V_2 , struct V_11 * V_96 )
{
int V_76 ;
char * V_88 = V_2 -> V_59 ;
unsigned int V_115 = F_52 ( V_88 ) ;
if ( V_115 > V_116 + F_53 ( V_2 ) - 4 ) {
F_27 ( 1 , L_23 ,
V_115 ) ;
F_1 ( V_2 ) ;
F_32 ( & V_2 -> V_61 ) ;
return - V_84 ;
}
if ( V_115 > V_117 - 4 ) {
V_2 -> V_58 = true ;
memcpy ( V_2 -> V_57 , V_88 , V_2 -> V_77 ) ;
V_88 = V_2 -> V_57 ;
}
V_76 = F_40 ( V_2 , V_88 + F_28 ( V_2 ) - 1 ,
V_115 - F_28 ( V_2 ) + 1 + 4 ) ;
if ( V_76 < 0 )
return V_76 ;
V_2 -> V_77 += V_76 ;
F_54 ( V_88 , V_2 -> V_77 ) ;
V_76 = V_2 -> V_48 -> V_118 ( V_88 , V_2 -> V_77 ) ;
if ( V_76 != 0 )
F_55 ( L_24 , V_88 ,
F_56 (unsigned int, server->total_read, 48 ) ) ;
if ( ! V_96 )
return V_76 ;
F_45 ( V_96 , V_2 , V_88 , V_76 ) ;
return 0 ;
}
static int
F_57 ( void * V_119 )
{
int V_76 ;
struct V_1 * V_2 = V_119 ;
unsigned int V_115 ;
char * V_88 = NULL ;
struct V_120 * V_121 = NULL ;
struct V_11 * V_12 ;
V_122 -> V_29 |= V_123 ;
F_5 ( 1 , L_25 , F_58 ( V_122 ) ) ;
V_76 = F_59 ( & V_111 ) ;
if ( V_76 > 1 )
F_50 ( V_112 , V_76 + V_113 ,
V_114 ) ;
F_60 () ;
while ( V_2 -> V_15 != V_16 ) {
if ( F_17 () )
continue;
if ( ! F_25 ( V_2 ) )
continue;
V_2 -> V_58 = false ;
V_88 = V_2 -> V_59 ;
V_115 = 4 ;
V_76 = F_40 ( V_2 , V_88 , V_115 ) ;
if ( V_76 < 0 )
continue;
V_2 -> V_77 = V_76 ;
V_115 = F_52 ( V_88 ) ;
F_5 ( 1 , L_26 , V_115 ) ;
if ( ! F_41 ( V_2 , V_88 [ 0 ] ) )
continue;
if ( V_115 < F_28 ( V_2 ) - 1 - 4 ) {
F_27 ( 1 , L_27 ,
V_115 ) ;
F_1 ( V_2 ) ;
F_32 ( & V_2 -> V_61 ) ;
continue;
}
V_76 = F_40 ( V_2 , V_88 + 4 ,
F_28 ( V_2 ) - 1 - 4 ) ;
if ( V_76 < 0 )
continue;
V_2 -> V_77 += V_76 ;
V_12 = V_2 -> V_48 -> V_124 ( V_2 , V_88 ) ;
if ( ! V_12 || ! V_12 -> V_125 )
V_76 = F_51 ( V_2 , V_12 ) ;
else
V_76 = V_12 -> V_125 ( V_2 , V_12 ) ;
if ( V_76 < 0 )
continue;
if ( V_2 -> V_58 )
V_88 = V_2 -> V_57 ;
V_2 -> V_36 = V_37 ;
if ( V_12 != NULL ) {
if ( ! V_12 -> V_103 || V_12 -> V_126 )
V_12 -> V_42 ( V_12 ) ;
} else if ( ! V_2 -> V_48 -> V_127 ||
! V_2 -> V_48 -> V_127 ( V_88 , V_2 ) ) {
F_27 ( 1 , L_28
L_29 , F_61 ( & V_128 ) ) ;
F_55 ( L_30 , V_88 ,
F_28 ( V_2 ) ) ;
#ifdef F_62
if ( V_2 -> V_48 -> V_129 )
V_2 -> V_48 -> V_129 ( V_88 ) ;
F_63 ( V_2 ) ;
#endif
}
}
F_64 ( V_2 -> V_57 ) ;
if ( V_2 -> V_59 )
F_65 ( V_2 -> V_59 ) ;
V_121 = F_66 ( & V_2 -> V_130 , NULL ) ;
F_46 ( V_2 ) ;
if ( ! V_121 ) {
F_67 ( V_131 ) ;
while ( ! F_68 ( V_122 ) ) {
F_69 () ;
F_67 ( V_131 ) ;
}
F_67 ( V_132 ) ;
}
F_70 ( 0 ) ;
}
static char *
F_71 ( const char * V_133 )
{
const char * V_134 ;
char * V_135 , * V_136 ;
unsigned int V_35 ;
V_134 = V_133 + 2 ;
V_136 = strchr ( V_134 , '\\' ) ;
if ( ! V_136 )
return F_72 ( - V_137 ) ;
V_35 = V_136 - V_134 ;
V_135 = F_36 ( ( V_35 + 1 ) , V_114 ) ;
if ( V_135 == NULL )
return F_72 ( - V_81 ) ;
memcpy ( V_135 , V_134 , V_35 ) ;
V_135 [ V_35 ] = '\0' ;
return V_135 ;
}
static int F_73 ( T_2 args [] , unsigned long * V_138 )
{
int V_3 ;
char * string ;
string = F_74 ( args ) ;
if ( string == NULL )
return - V_81 ;
V_3 = F_75 ( string , 0 , V_138 ) ;
F_11 ( string ) ;
return V_3 ;
}
static int F_76 ( char * V_139 ,
struct V_140 * V_141 )
{
T_2 args [ V_142 ] ;
switch ( F_77 ( V_139 , V_143 , args ) ) {
case V_144 :
V_141 -> V_145 |= V_146 ;
break;
case V_147 :
V_141 -> V_145 |= V_146 | V_148 ;
break;
case V_149 :
F_27 ( 1 , L_31 ) ;
break;
case V_150 :
V_141 -> V_145 |= V_151 ;
break;
case V_152 :
V_141 -> V_145 |= V_151 | V_148 ;
break;
case V_153 :
V_141 -> V_145 |= V_154 ;
break;
case V_155 :
V_141 -> V_145 |= V_154 | V_148 ;
break;
case V_156 :
V_141 -> V_145 |= V_157 ;
break;
case V_158 :
V_141 -> V_145 |= V_157 | V_148 ;
break;
#ifdef F_78
case V_159 :
V_141 -> V_145 |= V_160 ;
break;
#endif
case V_161 :
V_141 -> V_162 = 1 ;
break;
default:
F_27 ( 1 , L_32 , V_139 ) ;
return 1 ;
}
return 0 ;
}
static int
F_79 ( char * V_139 , struct V_140 * V_141 )
{
T_2 args [ V_142 ] ;
switch ( F_77 ( V_139 , V_163 , args ) ) {
case V_164 :
V_141 -> V_165 = false ;
V_141 -> V_166 = false ;
break;
case V_167 :
V_141 -> V_165 = false ;
V_141 -> V_166 = true ;
break;
case V_168 :
V_141 -> V_165 = true ;
V_141 -> V_166 = false ;
break;
default:
F_27 ( 1 , L_33 , V_139 ) ;
return 1 ;
}
return 0 ;
}
static int
F_80 ( char * V_139 , struct V_140 * V_141 )
{
T_2 args [ V_142 ] ;
switch ( F_77 ( V_139 , V_169 , args ) ) {
case V_170 :
V_141 -> V_48 = & V_171 ;
V_141 -> V_172 = & V_173 ;
break;
#ifdef F_4
case V_174 :
V_141 -> V_48 = & V_175 ;
V_141 -> V_172 = & V_176 ;
break;
#endif
default:
F_27 ( 1 , L_34 , V_139 ) ;
return 1 ;
}
return 0 ;
}
static int
F_81 ( const char * V_177 , const char * V_178 ,
struct V_140 * V_141 )
{
char * V_179 , * V_180 ;
char * V_181 = NULL , * V_182 ;
unsigned int V_183 , V_184 , V_185 ;
char V_186 [ 2 ] ;
short int V_187 = - 1 ;
short int V_188 = - 1 ;
bool V_189 = false ;
bool V_190 = false ;
bool V_191 = false ;
char * V_192 = NULL ;
char * V_193 = F_82 () -> V_193 ;
char * string = NULL ;
char * V_194 , * V_139 ;
char V_136 ;
bool V_195 = false ;
static bool V_196 = false ;
V_186 [ 0 ] = ',' ;
V_186 [ 1 ] = 0 ;
V_136 = V_186 [ 0 ] ;
memset ( V_141 -> V_197 , 0x20 , V_198 ) ;
for ( V_184 = 0 ; V_184 < F_83 ( V_193 , V_198 ) ; V_184 ++ )
V_141 -> V_197 [ V_184 ] = toupper ( V_193 [ V_184 ] ) ;
V_141 -> V_197 [ V_198 ] = 0 ;
V_141 -> V_199 [ 0 ] = 0 ;
V_141 -> V_200 = F_84 () ;
V_141 -> V_201 = F_84 () ;
V_141 -> V_202 = F_85 () ;
V_141 -> V_203 = V_141 -> V_204 = V_205 | V_206 | V_207 ;
V_141 -> V_208 = 1 ;
V_141 -> V_209 = 1 ;
V_141 -> V_210 = V_211 ;
V_141 -> V_48 = & V_171 ;
V_141 -> V_172 = & V_173 ;
if ( ! V_177 )
goto V_212;
V_181 = F_86 ( V_177 , V_213 , V_114 ) ;
if ( ! V_181 )
goto V_212;
V_182 = V_181 ;
V_180 = V_182 + strlen ( V_182 ) ;
if ( strncmp ( V_182 , L_35 , 4 ) == 0 ) {
if ( V_182 [ 4 ] != 0 ) {
V_186 [ 0 ] = V_182 [ 4 ] ;
V_182 += 5 ;
} else {
F_5 ( 1 , L_36 ) ;
}
}
V_141 -> V_214 = false ;
V_141 -> V_215 = false ;
while ( ( V_179 = F_87 ( & V_182 , V_186 ) ) != NULL ) {
T_2 args [ V_142 ] ;
unsigned long V_138 ;
int V_216 ;
if ( ! * V_179 )
continue;
V_216 = F_77 ( V_179 , V_217 , args ) ;
switch ( V_216 ) {
case V_218 :
break;
case V_219 :
V_141 -> V_220 = 0 ;
break;
case V_221 :
V_141 -> V_220 = 1 ;
break;
case V_222 :
V_187 = 1 ;
break;
case V_223 :
V_187 = 0 ;
break;
case V_224 :
V_141 -> V_225 = 1 ;
break;
case V_226 :
V_141 -> V_227 = 1 ;
break;
case V_228 :
V_141 -> V_229 = 1 ;
break;
case V_230 :
V_141 -> V_229 = 0 ;
break;
case V_231 :
V_141 -> V_232 = 0 ;
break;
case V_233 :
V_141 -> V_232 = 1 ;
break;
case V_234 :
V_141 -> V_235 = 1 ;
break;
case V_236 :
V_141 -> V_235 = 0 ;
break;
case V_237 :
V_141 -> V_238 = 1 ;
break;
case V_239 :
V_141 -> V_238 = 0 ;
break;
case V_240 :
V_141 -> V_241 = 1 ;
break;
case V_242 :
V_141 -> V_208 = 1 ;
break;
case V_243 :
V_141 -> V_208 = 0 ;
break;
case V_244 :
V_141 -> V_245 = 1 ;
break;
case V_246 :
V_141 -> V_247 = 1 ;
break;
case V_248 :
V_141 -> V_249 = 0 ;
break;
case V_250 :
V_141 -> V_249 = 1 ;
if ( V_141 -> V_204 ==
( V_251 & ~ ( V_252 | V_253 ) ) )
V_141 -> V_204 = V_251 ;
break;
case V_254 :
V_141 -> V_255 = 1 ;
break;
case V_256 :
V_141 -> V_257 = 1 ;
break;
case V_258 :
V_141 -> V_257 = 0 ;
break;
case V_259 :
V_141 -> V_260 = true ;
break;
case V_261 :
V_141 -> V_260 = false ;
break;
case V_262 :
V_141 -> V_229 = 0 ;
break;
case V_263 :
V_141 -> V_229 = 1 ;
break;
case V_264 :
V_141 -> V_265 = 0 ;
break;
case V_266 :
V_141 -> V_265 = 1 ;
break;
case V_267 :
V_141 -> V_268 = 1 ;
break;
case V_269 :
V_141 -> V_268 = 0 ;
break;
case V_270 :
V_141 -> V_209 = 1 ;
break;
case V_271 :
V_141 -> V_209 = 0 ;
break;
case V_272 :
V_141 -> V_273 = 1 ;
break;
case V_274 :
V_141 -> V_275 = 1 ;
break;
case V_276 :
V_141 -> V_275 = 0 ;
break;
case V_277 :
V_141 -> V_278 = 0 ;
break;
case V_279 :
V_141 -> V_278 = 1 ;
break;
case V_280 :
V_141 -> V_281 = 1 ;
break;
case V_282 :
V_141 -> V_145 |= V_148 ;
break;
case V_283 :
V_141 -> V_284 = 1 ;
break;
case V_285 :
V_195 = true ;
V_141 -> V_165 = true ;
V_141 -> V_166 = false ;
F_27 ( 1 , L_37
L_38
L_39 ) ;
break;
case V_286 :
V_195 = true ;
V_141 -> V_165 = false ;
V_141 -> V_166 = true ;
F_27 ( 1 , L_40
L_41
L_39 ) ;
break;
case V_287 :
F_88 ( V_288 L_42
L_43
L_44 ) ;
break;
case V_289 :
#ifndef F_89
F_27 ( 1 , L_45
L_46 ) ;
goto V_212;
#endif
V_141 -> V_290 = true ;
break;
case V_291 :
V_141 -> V_292 = true ;
break;
case V_293 :
V_141 -> V_294 = true ;
break;
case V_295 :
V_191 = true ;
break;
case V_296 :
if ( F_73 ( args , & V_138 ) ) {
F_27 ( 1 , L_47 ,
V_20 ) ;
goto V_212;
}
V_141 -> V_297 = V_138 ;
V_141 -> V_214 = true ;
break;
case V_298 :
if ( F_73 ( args , & V_138 ) ) {
F_27 ( 1 , L_48 ,
V_20 ) ;
goto V_212;
}
V_141 -> V_299 = V_138 ;
V_141 -> V_215 = true ;
break;
case V_300 :
if ( F_73 ( args , & V_138 ) ) {
F_27 ( 1 , L_49 ,
V_20 ) ;
goto V_212;
}
V_141 -> V_201 = V_138 ;
V_189 = true ;
break;
case V_301 :
if ( F_73 ( args , & V_138 ) ) {
F_27 ( 1 , L_50 ,
V_20 ) ;
goto V_212;
}
V_141 -> V_200 = V_138 ;
break;
case V_302 :
if ( F_73 ( args , & V_138 ) ) {
F_27 ( 1 , L_51 ,
V_20 ) ;
goto V_212;
}
V_141 -> V_202 = V_138 ;
V_190 = true ;
break;
case V_303 :
if ( F_73 ( args , & V_138 ) ) {
F_27 ( 1 , L_52 ,
V_20 ) ;
goto V_212;
}
V_141 -> V_204 = V_138 ;
break;
case V_304 :
if ( F_73 ( args , & V_138 ) ) {
F_27 ( 1 , L_53 ,
V_20 ) ;
goto V_212;
}
V_141 -> V_203 = V_138 ;
break;
case V_305 :
if ( F_73 ( args , & V_138 ) ) {
F_27 ( 1 , L_54 ,
V_20 ) ;
goto V_212;
}
V_141 -> V_306 = V_138 ;
break;
case V_307 :
if ( F_73 ( args , & V_138 ) ) {
F_27 ( 1 , L_55 ,
V_20 ) ;
goto V_212;
}
V_141 -> V_308 = V_138 ;
break;
case V_309 :
if ( F_73 ( args , & V_138 ) ) {
F_27 ( 1 , L_56 ,
V_20 ) ;
goto V_212;
}
V_141 -> V_310 = V_138 ;
break;
case V_311 :
if ( F_73 ( args , & V_138 ) ) {
F_27 ( 1 , L_57 ,
V_20 ) ;
goto V_212;
}
V_141 -> V_210 = V_52 * V_138 ;
if ( V_141 -> V_210 > V_312 ) {
F_27 ( 1 , L_58
L_59 ) ;
goto V_212;
}
break;
case V_313 :
V_141 -> V_162 = 1 ;
V_141 -> V_314 = NULL ;
break;
case V_315 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
if ( F_83 ( string , V_317 ) >
V_317 ) {
F_88 ( V_288 L_60 ) ;
goto V_212;
}
V_141 -> V_314 = F_90 ( string , V_114 ) ;
if ( ! V_141 -> V_314 ) {
F_88 ( V_288 L_61
L_62 ) ;
goto V_212;
}
break;
case V_318 :
V_141 -> V_319 = NULL ;
break;
case V_320 :
V_139 = strchr ( V_179 , '=' ) ;
V_139 ++ ;
V_194 = ( char * ) V_139 + strlen ( V_139 ) ;
if ( V_194 < V_180 && V_194 [ 1 ] == V_136 ) {
V_194 [ 0 ] = V_136 ;
while ( ( V_194 = strchr ( V_194 , V_136 ) )
!= NULL && ( V_194 [ 1 ] == V_136 ) ) {
V_194 = ( char * ) & V_194 [ 2 ] ;
}
if ( V_194 ) {
V_194 [ 0 ] = '\0' ;
V_182 = ( char * ) & V_194 [ 1 ] ;
} else
V_182 = V_180 ;
}
V_183 = strlen ( V_139 ) ;
V_141 -> V_319 = F_91 ( V_183 + 1 , V_114 ) ;
if ( V_141 -> V_319 == NULL ) {
F_88 ( V_288 L_61
L_63 ) ;
goto V_212;
}
for ( V_184 = 0 , V_185 = 0 ; V_184 < V_183 ; V_184 ++ , V_185 ++ ) {
V_141 -> V_319 [ V_185 ] = V_139 [ V_184 ] ;
if ( ( V_139 [ V_184 ] == V_136 ) &&
V_139 [ V_184 + 1 ] == V_136 )
V_184 ++ ;
}
V_141 -> V_319 [ V_185 ] = '\0' ;
break;
case V_321 :
V_141 -> V_322 = NULL ;
break;
case V_323 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
if ( F_83 ( string , V_324 ) >
V_324 ) {
F_88 ( V_288 L_64
L_65 ) ;
goto V_212;
}
V_141 -> V_322 = F_90 ( string , V_114 ) ;
if ( ! V_141 -> V_322 ) {
F_88 ( V_288 L_61
L_66 ) ;
goto V_212;
}
break;
case V_325 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
V_183 = F_83 ( string , 300 ) ;
if ( V_183 == 300 ) {
F_88 ( V_288 L_67 ) ;
goto V_212;
}
V_141 -> V_326 = F_36 ( V_183 + 1 , V_114 ) ;
if ( V_141 -> V_326 == NULL ) {
F_88 ( V_288 L_68 ) ;
goto V_212;
}
strcpy ( V_141 -> V_326 , string ) ;
if ( strncmp ( string , L_69 , 2 ) == 0 ) {
V_141 -> V_326 [ 0 ] = '\\' ;
V_141 -> V_326 [ 1 ] = '\\' ;
} else if ( strncmp ( string , L_70 , 2 ) != 0 ) {
F_88 ( V_288 L_71
L_72 ) ;
goto V_212;
}
break;
case V_327 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
if ( F_83 ( string , 256 ) == 256 ) {
F_88 ( V_288 L_73
L_74 ) ;
goto V_212;
}
V_141 -> V_328 = F_90 ( string , V_114 ) ;
if ( ! V_141 -> V_328 ) {
F_88 ( V_288 L_61
L_75 ) ;
goto V_212;
}
F_5 ( 1 , L_76 ) ;
break;
case V_329 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
if ( ! F_92 (
(struct V_93 * ) & V_141 -> V_330 ,
string , strlen ( string ) ) ) {
F_88 ( V_288 L_77
L_78 , string ) ;
goto V_212;
}
break;
case V_331 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
V_183 = F_83 ( string , 1024 ) ;
if ( string [ 0 ] != '/' )
V_183 ++ ;
if ( V_183 > 1024 ) {
F_88 ( V_288 L_79 ) ;
goto V_212;
}
V_141 -> V_332 = F_36 ( V_183 + 1 , V_114 ) ;
if ( V_141 -> V_332 == NULL ) {
F_88 ( V_288 L_61
L_80 ) ;
goto V_212;
}
if ( string [ 0 ] != '/' ) {
V_141 -> V_332 [ 0 ] = '/' ;
strcpy ( V_141 -> V_332 + 1 , string ) ;
} else
strcpy ( V_141 -> V_332 , string ) ;
break;
case V_333 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
if ( F_83 ( string , 1024 ) >= 65 ) {
F_88 ( V_288 L_81
L_82 ) ;
goto V_212;
}
if ( F_93 ( string , L_83 , 7 ) != 0 ) {
V_141 -> V_334 = F_90 ( string ,
V_114 ) ;
if ( ! V_141 -> V_334 ) {
F_88 ( V_288 L_84
L_85 ) ;
goto V_212;
}
}
F_5 ( 1 , L_86 , string ) ;
break;
case V_335 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
if ( F_93 ( string , L_87 , 11 ) == 0 )
V_141 -> V_336 = 1 ;
break;
case V_337 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
memset ( V_141 -> V_197 , 0x20 ,
V_198 ) ;
for ( V_184 = 0 ; V_184 < V_198 ; V_184 ++ ) {
if ( string [ V_184 ] == 0 )
break;
V_141 -> V_197 [ V_184 ] = string [ V_184 ] ;
}
if ( V_184 == V_198 && string [ V_184 ] != 0 )
F_88 ( V_288 L_88
L_89 ) ;
break;
case V_338 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
memset ( V_141 -> V_199 , 0x20 ,
V_339 ) ;
for ( V_184 = 0 ; V_184 < 15 ; V_184 ++ ) {
if ( string [ V_184 ] == 0 )
break;
V_141 -> V_199 [ V_184 ] = string [ V_184 ] ;
}
if ( V_184 == V_198 && string [ V_184 ] != 0 )
F_88 ( V_288 L_90
L_91 ) ;
break;
case V_340 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
if ( F_93 ( string , L_92 , 1 ) == 0 ) {
break;
}
F_88 ( V_288 L_93
L_94 ) ;
goto V_212;
case V_341 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
if ( F_80 ( string , V_141 ) != 0 )
goto V_212;
break;
case V_342 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
if ( F_76 ( string , V_141 ) != 0 )
goto V_212;
break;
case V_343 :
V_195 = true ;
string = F_74 ( args ) ;
if ( string == NULL )
goto V_316;
if ( F_79 ( string , V_141 ) != 0 )
goto V_212;
break;
default:
if ( ! V_192 )
V_192 = V_179 ;
break;
}
F_11 ( string ) ;
string = NULL ;
}
if ( ! V_191 && V_192 ) {
F_88 ( V_344 L_95 , V_192 ) ;
goto V_212;
}
#ifndef F_94
if ( V_141 -> V_294 ) {
F_27 ( 1 , L_96
L_97 ) ;
goto V_212;
}
#endif
if ( V_141 -> V_322 == NULL )
V_141 -> V_322 = & V_141 -> V_326 [ 2 ] ;
if ( V_189 )
V_141 -> V_187 = V_187 ;
else if ( V_187 == 1 )
F_88 ( V_345 L_98
L_99 ) ;
if ( V_190 )
V_141 -> V_188 = V_188 ;
else if ( V_188 == 1 )
F_88 ( V_345 L_100
L_101 ) ;
if ( ! V_195 && ! V_196 ) {
V_196 = true ;
F_88 ( V_345 L_102
L_103
L_104 ) ;
}
F_11 ( V_181 ) ;
return 0 ;
V_316:
F_88 ( V_288 L_105 ) ;
V_212:
F_11 ( string ) ;
F_11 ( V_181 ) ;
return 1 ;
}
static bool
F_95 ( struct V_93 * V_330 , struct V_93 * V_346 )
{
switch ( V_330 -> V_347 ) {
case V_348 :
return ( V_346 -> V_347 == V_348 ) ;
case V_349 : {
struct V_350 * V_351 = (struct V_350 * ) V_330 ;
struct V_350 * V_352 = (struct V_350 * ) V_346 ;
return ( V_351 -> V_353 . V_354 == V_352 -> V_353 . V_354 ) ;
}
case V_355 : {
struct V_356 * V_357 = (struct V_356 * ) V_330 ;
struct V_356 * V_358 = (struct V_356 * ) & V_346 ;
return F_96 ( & V_357 -> V_359 , & V_358 -> V_359 ) ;
}
default:
F_97 ( 1 ) ;
return false ;
}
}
static bool
F_98 ( struct V_1 * V_2 , struct V_93 * V_360 )
{
T_3 V_306 , * V_361 ;
switch ( V_360 -> V_347 ) {
case V_349 :
V_361 = & ( (struct V_350 * ) & V_2 -> V_94 ) -> V_362 ;
V_306 = ( (struct V_350 * ) V_360 ) -> V_362 ;
break;
case V_355 :
V_361 = & ( (struct V_356 * ) & V_2 -> V_94 ) -> V_363 ;
V_306 = ( (struct V_356 * ) V_360 ) -> V_363 ;
break;
default:
F_97 ( 1 ) ;
return false ;
}
if ( ! V_306 ) {
V_306 = F_99 ( V_95 ) ;
if ( V_306 == * V_361 )
return true ;
V_306 = F_99 ( V_364 ) ;
}
return V_306 == * V_361 ;
}
static bool
F_100 ( struct V_1 * V_2 , struct V_93 * V_360 ,
struct V_93 * V_330 )
{
switch ( V_360 -> V_347 ) {
case V_349 : {
struct V_350 * V_365 = (struct V_350 * ) V_360 ;
struct V_350 * V_366 =
(struct V_350 * ) & V_2 -> V_94 ;
if ( V_365 -> V_353 . V_354 != V_366 -> V_353 . V_354 )
return false ;
break;
}
case V_355 : {
struct V_356 * V_367 = (struct V_356 * ) V_360 ;
struct V_356 * V_368 =
(struct V_356 * ) & V_2 -> V_94 ;
if ( ! F_96 ( & V_367 -> V_359 ,
& V_368 -> V_359 ) )
return false ;
if ( V_367 -> V_369 != V_368 -> V_369 )
return false ;
break;
}
default:
F_97 ( 1 ) ;
return false ;
}
if ( ! F_95 ( V_330 , (struct V_93 * ) & V_2 -> V_330 ) )
return false ;
return true ;
}
static bool
F_101 ( struct V_1 * V_2 , struct V_140 * V_141 )
{
unsigned int V_370 ;
if ( V_141 -> V_145 & ( ~ ( V_148 | V_371 ) ) )
V_370 = V_141 -> V_145 ;
else
V_370 = V_372 | V_141 -> V_145 ;
switch ( V_2 -> V_373 ) {
case V_374 :
if ( ! ( V_370 & ( V_160 | V_375 ) ) )
return false ;
break;
case V_376 :
if ( ! ( V_370 & V_157 ) )
return false ;
break;
case V_377 :
if ( ! ( V_370 & V_154 ) )
return false ;
break;
case V_378 :
if ( ! ( V_370 & V_146 ) )
return false ;
break;
case V_379 :
if ( ! ( V_370 & V_151 ) )
return false ;
break;
default:
return false ;
}
if ( ( V_370 & V_380 ) == 0 &&
( V_2 -> V_381 & V_382 ) )
return false ;
else if ( ( ( V_370 & V_148 ) == V_148 ) &&
( V_2 -> V_381 &
( V_383 | V_382 ) ) == 0 )
return false ;
return true ;
}
static int F_102 ( struct V_1 * V_2 , struct V_93 * V_360 ,
struct V_140 * V_141 )
{
if ( ( V_2 -> V_172 != V_141 -> V_172 ) || ( V_2 -> V_48 != V_141 -> V_48 ) )
return 0 ;
if ( ! F_103 ( F_104 ( V_2 ) , V_122 -> V_384 -> V_385 ) )
return 0 ;
if ( ! F_100 ( V_2 , V_360 ,
(struct V_93 * ) & V_141 -> V_330 ) )
return 0 ;
if ( ! F_98 ( V_2 , V_360 ) )
return 0 ;
if ( ! F_101 ( V_2 , V_141 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_105 ( struct V_93 * V_360 , struct V_140 * V_141 )
{
struct V_1 * V_2 ;
F_2 ( & V_21 ) ;
F_106 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_102 ( V_2 , V_360 , V_141 ) )
continue;
++ V_2 -> V_386 ;
F_3 ( & V_21 ) ;
F_5 ( 1 , L_106 ) ;
return V_2 ;
}
F_3 ( & V_21 ) ;
return NULL ;
}
static void
F_107 ( struct V_1 * V_2 )
{
struct V_120 * V_387 ;
F_2 ( & V_21 ) ;
if ( -- V_2 -> V_386 > 0 ) {
F_3 ( & V_21 ) ;
return;
}
F_108 ( F_104 ( V_2 ) ) ;
F_16 ( & V_2 -> V_104 ) ;
F_3 ( & V_21 ) ;
F_109 ( & V_2 -> V_47 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
F_11 ( V_2 -> V_33 . V_34 ) ;
V_2 -> V_33 . V_34 = NULL ;
V_2 -> V_33 . V_35 = 0 ;
V_387 = F_66 ( & V_2 -> V_130 , NULL ) ;
if ( V_387 )
F_112 ( V_388 , V_387 ) ;
}
static struct V_1 *
F_113 ( struct V_140 * V_389 )
{
struct V_1 * V_390 = NULL ;
struct V_391 V_360 ;
struct V_350 * V_392 = (struct V_350 * ) & V_360 ;
struct V_356 * V_393 = (struct V_356 * ) & V_360 ;
int V_3 ;
memset ( & V_360 , 0 , sizeof( struct V_391 ) ) ;
F_5 ( 1 , L_107 , V_389 -> V_326 , V_389 -> V_322 ) ;
if ( V_389 -> V_322 && V_389 -> V_326 ) {
V_3 = F_114 ( (struct V_93 * ) & V_360 ,
V_389 -> V_322 ,
strlen ( V_389 -> V_322 ) ,
V_389 -> V_306 ) ;
if ( ! V_3 ) {
V_3 = - V_137 ;
goto V_394;
}
} else if ( V_389 -> V_322 ) {
F_27 ( 1 , L_108 ) ;
V_3 = - V_137 ;
goto V_394;
} else {
F_27 ( 1 , L_109
L_110 ) ;
V_3 = - V_137 ;
goto V_394;
}
V_390 = F_105 ( (struct V_93 * ) & V_360 , V_389 ) ;
if ( V_390 )
return V_390 ;
V_390 = F_91 ( sizeof( struct V_1 ) , V_114 ) ;
if ( ! V_390 ) {
V_3 = - V_81 ;
goto V_394;
}
V_3 = F_115 ( V_390 ) ;
if ( V_3 ) {
F_27 ( 1 , L_111 , V_3 ) ;
goto V_394;
}
V_390 -> V_48 = V_389 -> V_48 ;
V_390 -> V_172 = V_389 -> V_172 ;
F_116 ( V_390 , F_117 ( V_122 -> V_384 -> V_385 ) ) ;
V_390 -> V_55 = F_71 ( V_389 -> V_326 ) ;
if ( F_118 ( V_390 -> V_55 ) ) {
V_3 = F_119 ( V_390 -> V_55 ) ;
goto V_395;
}
V_390 -> V_225 = V_389 -> V_225 ;
V_390 -> V_227 = V_389 -> V_227 ;
V_390 -> V_396 = V_389 -> V_336 ;
V_390 -> V_397 = 0 ;
V_390 -> V_106 = 1 ;
F_120 ( & V_390 -> V_61 ) ;
F_120 ( & V_390 -> V_107 ) ;
F_13 ( & V_390 -> V_108 ) ;
F_121 ( & V_390 -> V_26 ) ;
memcpy ( V_390 -> V_398 ,
V_389 -> V_197 , V_339 ) ;
memcpy ( V_390 -> V_399 ,
V_389 -> V_199 , V_339 ) ;
V_390 -> V_32 = false ;
V_390 -> V_31 = 0 ;
V_390 -> V_36 = V_37 ;
F_122 ( & V_390 -> V_105 ) ;
F_13 ( & V_390 -> V_104 ) ;
F_13 ( & V_390 -> V_22 ) ;
F_123 ( & V_390 -> V_47 , F_21 ) ;
V_390 -> V_15 = V_400 ;
memcpy ( & V_390 -> V_330 , & V_389 -> V_330 ,
sizeof( V_390 -> V_330 ) ) ;
++ V_390 -> V_386 ;
if ( V_360 . V_401 == V_355 ) {
F_5 ( 1 , L_112 ) ;
memcpy ( & V_390 -> V_94 , V_393 ,
sizeof( struct V_356 ) ) ;
} else
memcpy ( & V_390 -> V_94 , V_392 ,
sizeof( struct V_350 ) ) ;
V_3 = F_124 ( V_390 ) ;
if ( V_3 < 0 ) {
F_27 ( 1 , L_113 ) ;
goto V_395;
}
F_125 ( V_402 ) ;
V_390 -> V_130 = F_126 ( F_57 ,
V_390 , L_114 ) ;
if ( F_118 ( V_390 -> V_130 ) ) {
V_3 = F_119 ( V_390 -> V_130 ) ;
F_27 ( 1 , L_115 , V_3 ) ;
F_127 ( V_402 ) ;
goto V_395;
}
V_390 -> V_15 = V_44 ;
F_2 ( & V_21 ) ;
F_128 ( & V_390 -> V_104 , & V_403 ) ;
F_3 ( & V_21 ) ;
F_129 ( V_390 ) ;
F_24 ( V_56 , & V_390 -> V_47 , V_51 ) ;
return V_390 ;
V_395:
F_110 ( V_390 ) ;
F_108 ( F_104 ( V_390 ) ) ;
V_394:
if ( V_390 ) {
if ( ! F_118 ( V_390 -> V_55 ) )
F_11 ( V_390 -> V_55 ) ;
if ( V_390 -> V_27 )
F_10 ( V_390 -> V_27 ) ;
F_11 ( V_390 ) ;
}
return F_72 ( V_3 ) ;
}
static int F_130 ( struct V_7 * V_8 , struct V_140 * V_141 )
{
switch ( V_8 -> V_2 -> V_373 ) {
case V_378 :
if ( V_141 -> V_200 != V_8 -> V_200 )
return 0 ;
break;
default:
if ( V_8 -> V_404 == NULL ) {
if ( ! V_141 -> V_162 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_404 ,
V_141 -> V_314 ? V_141 -> V_314 : L_116 ,
V_317 ) )
return 0 ;
if ( strlen ( V_141 -> V_314 ) != 0 &&
V_8 -> V_319 != NULL &&
strncmp ( V_8 -> V_319 ,
V_141 -> V_319 ? V_141 -> V_319 : L_116 ,
V_405 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_131 ( struct V_1 * V_2 , struct V_140 * V_141 )
{
struct V_7 * V_8 ;
F_2 ( & V_21 ) ;
F_106 (ses, &server->smb_ses_list, smb_ses_list) {
if ( ! F_130 ( V_8 , V_141 ) )
continue;
++ V_8 -> V_406 ;
F_3 ( & V_21 ) ;
return V_8 ;
}
F_3 ( & V_21 ) ;
return NULL ;
}
static void
F_132 ( struct V_7 * V_8 )
{
unsigned int V_407 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( 1 , L_117 , V_20 , V_8 -> V_406 ) ;
F_2 ( & V_21 ) ;
if ( -- V_8 -> V_406 > 0 ) {
F_3 ( & V_21 ) ;
return;
}
F_16 ( & V_8 -> V_22 ) ;
F_3 ( & V_21 ) ;
if ( V_8 -> V_408 == V_60 && V_2 -> V_48 -> V_409 ) {
V_407 = F_133 () ;
V_2 -> V_48 -> V_409 ( V_407 , V_8 ) ;
F_134 ( V_407 ) ;
}
F_135 ( V_8 ) ;
F_107 ( V_2 ) ;
}
static int
F_136 ( struct V_140 * V_141 , struct V_7 * V_8 )
{
int V_3 = 0 ;
char * V_410 , * V_136 , * V_411 ;
T_4 V_35 ;
struct V_412 * V_412 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_350 * V_413 ;
struct V_356 * V_414 ;
struct V_415 * V_416 ;
V_410 = F_36 ( V_417 , V_114 ) ;
if ( ! V_410 )
return - V_81 ;
switch ( V_2 -> V_94 . V_401 ) {
case V_349 :
V_413 = (struct V_350 * ) & V_2 -> V_94 ;
sprintf ( V_410 , L_118 , & V_413 -> V_353 . V_354 ) ;
break;
case V_355 :
V_414 = (struct V_356 * ) & V_2 -> V_94 ;
sprintf ( V_410 , L_119 , & V_414 -> V_359 . V_418 ) ;
break;
default:
F_5 ( 1 , L_120 , V_2 -> V_94 . V_401 ) ;
V_3 = - V_137 ;
goto V_394;
}
F_5 ( 1 , L_121 , V_20 , V_410 ) ;
V_412 = F_137 ( & V_419 , V_410 , L_116 ) ;
if ( F_118 ( V_412 ) ) {
if ( ! V_8 -> V_420 ) {
F_5 ( 1 , L_122 ) ;
V_3 = F_119 ( V_412 ) ;
goto V_394;
}
sprintf ( V_410 , L_123 , V_8 -> V_420 ) ;
F_5 ( 1 , L_121 , V_20 , V_410 ) ;
V_412 = F_137 ( & V_419 , V_410 , L_116 ) ;
if ( F_118 ( V_412 ) ) {
V_3 = F_119 ( V_412 ) ;
goto V_394;
}
}
F_138 ( & V_412 -> V_421 ) ;
V_416 = V_412 -> V_411 . V_179 ;
if ( F_139 ( V_416 ) ) {
V_3 = V_416 ? F_119 ( V_416 ) : - V_137 ;
goto V_422;
}
V_411 = ( char * ) V_416 -> V_179 ;
V_136 = F_140 ( V_411 , V_416 -> V_423 , ':' ) ;
F_5 ( 1 , L_124 , V_411 ) ;
if ( ! V_136 ) {
F_5 ( 1 , L_125 ,
V_416 -> V_423 ) ;
V_3 = - V_137 ;
goto V_422;
}
V_35 = V_136 - V_411 ;
if ( V_35 > V_317 || V_35 <= 0 ) {
F_5 ( 1 , L_126 , V_35 ) ;
V_3 = - V_137 ;
goto V_422;
}
V_141 -> V_314 = F_86 ( V_411 , V_35 , V_114 ) ;
if ( ! V_141 -> V_314 ) {
F_5 ( 1 , L_127 , V_35 ) ;
V_3 = - V_81 ;
goto V_422;
}
F_5 ( 1 , L_128 , V_20 , V_141 -> V_314 ) ;
V_35 = V_412 -> V_423 - ( V_35 + 1 ) ;
if ( V_35 > V_405 || V_35 <= 0 ) {
F_5 ( 1 , L_129 , V_35 ) ;
V_3 = - V_137 ;
F_11 ( V_141 -> V_314 ) ;
V_141 -> V_314 = NULL ;
goto V_422;
}
++ V_136 ;
V_141 -> V_319 = F_86 ( V_136 , V_35 , V_114 ) ;
if ( ! V_141 -> V_319 ) {
F_5 ( 1 , L_130 , V_35 ) ;
V_3 = - V_81 ;
F_11 ( V_141 -> V_314 ) ;
V_141 -> V_314 = NULL ;
goto V_422;
}
V_422:
F_141 ( & V_412 -> V_421 ) ;
F_142 ( V_412 ) ;
V_394:
F_11 ( V_410 ) ;
F_5 ( 1 , L_131 , V_20 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_143 ( struct V_1 * V_2 , struct V_140 * V_389 )
{
int V_3 = - V_81 ;
unsigned int V_407 ;
struct V_7 * V_8 ;
struct V_350 * V_360 = (struct V_350 * ) & V_2 -> V_94 ;
struct V_356 * V_367 = (struct V_356 * ) & V_2 -> V_94 ;
V_407 = F_133 () ;
V_8 = F_131 ( V_2 , V_389 ) ;
if ( V_8 ) {
F_5 ( 1 , L_132 , V_8 -> V_408 ) ;
F_8 ( & V_8 -> V_424 ) ;
V_3 = F_144 ( V_407 , V_8 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_424 ) ;
F_132 ( V_8 ) ;
F_145 ( V_407 ) ;
return F_72 ( V_3 ) ;
}
if ( V_8 -> V_23 ) {
F_5 ( 1 , L_133 ) ;
V_3 = F_146 ( V_407 , V_8 ,
V_389 -> V_425 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_424 ) ;
F_132 ( V_8 ) ;
F_145 ( V_407 ) ;
return F_72 ( V_3 ) ;
}
}
F_12 ( & V_8 -> V_424 ) ;
F_107 ( V_2 ) ;
F_145 ( V_407 ) ;
return V_8 ;
}
F_5 ( 1 , L_134 ) ;
V_8 = F_147 () ;
if ( V_8 == NULL )
goto V_426;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_94 . V_401 == V_355 )
sprintf ( V_8 -> V_427 , L_135 , & V_367 -> V_359 ) ;
else
sprintf ( V_8 -> V_427 , L_136 , & V_360 -> V_353 ) ;
if ( V_389 -> V_314 ) {
V_8 -> V_404 = F_90 ( V_389 -> V_314 , V_114 ) ;
if ( ! V_8 -> V_404 )
goto V_426;
}
if ( V_389 -> V_319 ) {
V_8 -> V_319 = F_90 ( V_389 -> V_319 , V_114 ) ;
if ( ! V_8 -> V_319 )
goto V_426;
}
if ( V_389 -> V_328 ) {
V_8 -> V_420 = F_90 ( V_389 -> V_328 , V_114 ) ;
if ( ! V_8 -> V_420 )
goto V_426;
}
V_8 -> V_200 = V_389 -> V_200 ;
V_8 -> V_201 = V_389 -> V_201 ;
if ( ( V_389 -> V_145 == 0 ) && V_428 == false ) {
V_428 = true ;
F_27 ( 1 , L_137
L_138
L_139 ) ;
}
V_8 -> V_429 = V_389 -> V_145 ;
F_8 ( & V_8 -> V_424 ) ;
V_3 = F_144 ( V_407 , V_8 ) ;
if ( ! V_3 )
V_3 = F_146 ( V_407 , V_8 , V_389 -> V_425 ) ;
F_12 ( & V_8 -> V_424 ) ;
if ( V_3 )
goto V_426;
F_2 ( & V_21 ) ;
F_128 ( & V_8 -> V_22 , & V_2 -> V_22 ) ;
F_3 ( & V_21 ) ;
F_145 ( V_407 ) ;
return V_8 ;
V_426:
F_135 ( V_8 ) ;
F_145 ( V_407 ) ;
return F_72 ( V_3 ) ;
}
static int F_148 ( struct V_9 * V_10 , const char * V_133 )
{
if ( V_10 -> V_430 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_431 , V_133 , V_432 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_149 ( struct V_7 * V_8 , const char * V_133 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_21 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_25 ) ;
if ( ! F_148 ( V_10 , V_133 ) )
continue;
++ V_10 -> V_433 ;
F_3 ( & V_21 ) ;
return V_10 ;
}
F_3 ( & V_21 ) ;
return NULL ;
}
static void
F_150 ( struct V_9 * V_10 )
{
unsigned int V_407 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( 1 , L_140 , V_20 , V_10 -> V_433 ) ;
F_2 ( & V_21 ) ;
if ( -- V_10 -> V_433 > 0 ) {
F_3 ( & V_21 ) ;
return;
}
F_16 ( & V_10 -> V_25 ) ;
F_3 ( & V_21 ) ;
V_407 = F_133 () ;
if ( V_8 -> V_2 -> V_48 -> V_434 )
V_8 -> V_2 -> V_48 -> V_434 ( V_407 , V_10 ) ;
F_134 ( V_407 ) ;
F_151 ( V_10 ) ;
F_152 ( V_10 ) ;
F_132 ( V_8 ) ;
}
static struct V_9 *
F_153 ( struct V_7 * V_8 , struct V_140 * V_389 )
{
int V_3 , V_407 ;
struct V_9 * V_10 ;
V_10 = F_149 ( V_8 , V_389 -> V_326 ) ;
if ( V_10 ) {
F_5 ( 1 , L_141 ) ;
F_132 ( V_8 ) ;
if ( V_10 -> V_284 != V_389 -> V_284 )
F_27 ( 1 , L_142
L_143 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_48 -> V_435 ) {
V_3 = - V_54 ;
goto V_436;
}
V_10 = F_154 () ;
if ( V_10 == NULL ) {
V_3 = - V_81 ;
goto V_436;
}
V_10 -> V_8 = V_8 ;
if ( V_389 -> V_319 ) {
V_10 -> V_319 = F_90 ( V_389 -> V_319 , V_114 ) ;
if ( ! V_10 -> V_319 ) {
V_3 = - V_81 ;
goto V_436;
}
}
if ( strchr ( V_389 -> V_326 + 3 , '\\' ) == NULL
&& strchr ( V_389 -> V_326 + 3 , '/' ) == NULL ) {
F_27 ( 1 , L_144 ) ;
V_3 = - V_437 ;
goto V_436;
}
V_407 = F_133 () ;
V_3 = V_8 -> V_2 -> V_48 -> V_435 ( V_407 , V_8 , V_389 -> V_326 , V_10 ,
V_389 -> V_425 ) ;
F_145 ( V_407 ) ;
F_5 ( 1 , L_145 , V_3 ) ;
if ( V_3 )
goto V_436;
if ( V_389 -> V_241 ) {
V_10 -> V_438 &= ~ V_439 ;
F_5 ( 1 , L_146 , V_10 -> V_438 ) ;
}
V_10 -> V_284 = V_389 -> V_284 ;
V_10 -> V_229 = V_389 -> V_229 ;
V_10 -> V_247 = V_389 -> V_247 ;
V_10 -> V_281 = V_389 -> V_281 ;
F_2 ( & V_21 ) ;
F_128 ( & V_10 -> V_25 , & V_8 -> V_25 ) ;
F_3 ( & V_21 ) ;
F_155 ( V_10 ) ;
return V_10 ;
V_436:
F_152 ( V_10 ) ;
return F_72 ( V_3 ) ;
}
void
F_156 ( struct V_440 * V_441 )
{
if ( ! V_441 || F_118 ( V_441 ) )
return;
if ( ! F_157 ( & V_441 -> V_442 ) ||
F_158 ( V_443 , & V_441 -> V_444 ) ) {
V_441 -> V_445 = V_37 ;
return;
}
if ( ! F_118 ( F_159 ( V_441 ) ) )
F_150 ( F_159 ( V_441 ) ) ;
F_11 ( V_441 ) ;
return;
}
static inline struct V_440 *
F_160 ( struct V_446 * V_447 )
{
return V_447 -> V_448 ;
}
static int
F_161 ( struct V_449 * V_450 , struct V_451 * V_452 )
{
struct V_446 * V_453 = F_162 ( V_450 ) ;
struct V_446 * V_63 = V_452 -> V_447 ;
if ( ( V_450 -> V_454 & V_455 ) != ( V_452 -> V_29 & V_455 ) )
return 0 ;
if ( ( V_453 -> V_456 & V_457 ) !=
( V_63 -> V_456 & V_457 ) )
return 0 ;
if ( V_63 -> V_310 && V_63 -> V_310 < V_453 -> V_310 )
return 0 ;
if ( V_63 -> V_308 && V_63 -> V_308 < V_453 -> V_308 )
return 0 ;
if ( V_453 -> V_458 != V_63 -> V_458 || V_453 -> V_459 != V_63 -> V_459 )
return 0 ;
if ( V_453 -> V_460 != V_63 -> V_460 ||
V_453 -> V_461 != V_63 -> V_461 )
return 0 ;
if ( strcmp ( V_453 -> V_425 -> V_462 , V_63 -> V_425 -> V_462 ) )
return 0 ;
if ( V_453 -> V_210 != V_63 -> V_210 )
return 0 ;
return 1 ;
}
int
F_163 ( struct V_449 * V_450 , void * V_179 )
{
struct V_451 * V_452 = (struct V_451 * ) V_179 ;
struct V_140 * V_389 ;
struct V_446 * V_447 ;
struct V_1 * V_463 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_440 * V_441 ;
struct V_391 V_360 ;
int V_3 = 0 ;
memset ( & V_360 , 0 , sizeof( struct V_391 ) ) ;
F_2 ( & V_21 ) ;
V_447 = F_162 ( V_450 ) ;
V_441 = F_164 ( F_160 ( V_447 ) ) ;
if ( F_118 ( V_441 ) ) {
F_3 ( & V_21 ) ;
return V_3 ;
}
V_10 = F_159 ( V_441 ) ;
V_8 = V_10 -> V_8 ;
V_463 = V_8 -> V_2 ;
V_389 = V_452 -> V_141 ;
if ( ! V_389 -> V_322 || ! V_389 -> V_326 )
goto V_464;
V_3 = F_114 ( (struct V_93 * ) & V_360 ,
V_389 -> V_322 ,
strlen ( V_389 -> V_322 ) ,
V_389 -> V_306 ) ;
if ( ! V_3 )
goto V_464;
if ( ! F_102 ( V_463 , (struct V_93 * ) & V_360 , V_389 ) ||
! F_130 ( V_8 , V_389 ) ||
! F_148 ( V_10 , V_389 -> V_326 ) ) {
V_3 = 0 ;
goto V_464;
}
V_3 = F_161 ( V_450 , V_452 ) ;
V_464:
F_3 ( & V_21 ) ;
F_156 ( V_441 ) ;
return V_3 ;
}
int
F_165 ( const unsigned int V_407 , struct V_7 * V_8 , const char * V_465 ,
const struct V_466 * V_467 , unsigned int * V_468 ,
struct V_469 * * V_470 , int V_235 )
{
char * V_471 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_48 -> V_435 || ! V_8 -> V_2 -> V_48 -> V_472 )
return - V_54 ;
* V_468 = 0 ;
* V_470 = NULL ;
if ( V_8 -> V_24 == 0 ) {
V_471 = F_36 ( 2 +
F_83 ( V_8 -> V_427 , V_473 * 2 )
+ 1 + 4 + 2 , V_114 ) ;
if ( V_471 == NULL )
return - V_81 ;
V_471 [ 0 ] = '\\' ;
V_471 [ 1 ] = '\\' ;
strcpy ( V_471 + 2 , V_8 -> V_427 ) ;
strcpy ( V_471 + 2 + strlen ( V_8 -> V_427 ) , L_147 ) ;
V_3 = V_8 -> V_2 -> V_48 -> V_435 ( V_407 , V_8 , V_471 , NULL ,
V_467 ) ;
F_5 ( 1 , L_148 , V_3 , V_8 -> V_24 ) ;
F_11 ( V_471 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_48 -> V_472 ( V_407 , V_8 , V_465 ,
V_470 , V_468 ,
V_467 , V_235 ) ;
return V_3 ;
}
static inline void
F_166 ( struct V_474 * V_475 )
{
struct V_475 * V_476 = V_475 -> V_476 ;
F_167 ( F_168 ( V_476 ) ) ;
F_169 ( V_476 , L_149 ,
& V_477 [ 0 ] , L_150 , & V_478 [ 0 ] ) ;
}
static inline void
F_170 ( struct V_474 * V_475 )
{
struct V_475 * V_476 = V_475 -> V_476 ;
F_167 ( F_168 ( V_476 ) ) ;
F_169 ( V_476 , L_151 ,
& V_477 [ 1 ] , L_152 , & V_478 [ 1 ] ) ;
}
static inline void
F_166 ( struct V_474 * V_475 )
{
}
static inline void
F_170 ( struct V_474 * V_475 )
{
}
static void F_171 ( char * V_479 , char * V_480 , unsigned int V_76 )
{
unsigned int V_184 , V_185 ;
for ( V_184 = 0 , V_185 = 0 ; V_184 < ( V_76 ) ; V_184 ++ ) {
V_479 [ V_185 ] = 'A' + ( 0x0F & ( V_480 [ V_184 ] >> 4 ) ) ;
V_479 [ V_185 + 1 ] = 'A' + ( 0x0F & V_480 [ V_184 ] ) ;
V_185 += 2 ;
}
}
static int
F_172 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_330 . V_401 != V_348 ) {
struct V_474 * V_474 = V_2 -> V_27 ;
V_3 = V_474 -> V_48 -> V_481 ( V_474 ,
(struct V_93 * ) & V_2 -> V_330 ,
sizeof( V_2 -> V_330 ) ) ;
if ( V_3 < 0 ) {
struct V_350 * V_351 ;
struct V_356 * V_357 ;
V_351 = (struct V_350 * ) & V_2 -> V_330 ;
V_357 = (struct V_356 * ) & V_2 -> V_330 ;
if ( V_357 -> V_482 == V_355 )
F_27 ( 1 , L_153
L_154 ,
& V_357 -> V_359 , V_3 ) ;
else
F_27 ( 1 , L_153
L_155 ,
& V_351 -> V_353 . V_354 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_173 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_483 * V_484 ;
struct V_485 * V_486 ;
V_484 = F_91 ( sizeof( struct V_483 ) ,
V_114 ) ;
if ( V_484 ) {
V_484 -> V_487 . V_488 . V_489 = 32 ;
if ( V_2 -> V_399 &&
V_2 -> V_399 [ 0 ] != 0 )
F_171 ( V_484 -> V_487 .
V_488 . V_490 ,
V_2 -> V_399 ,
V_339 ) ;
else
F_171 ( V_484 -> V_487 .
V_488 . V_490 ,
V_491 ,
V_339 ) ;
V_484 -> V_487 . V_488 . V_492 = 32 ;
if ( V_2 -> V_398 &&
V_2 -> V_398 [ 0 ] != 0 )
F_171 ( V_484 -> V_487 .
V_488 . V_493 ,
V_2 -> V_398 ,
V_339 ) ;
else
F_171 ( V_484 -> V_487 .
V_488 . V_493 ,
L_156 ,
V_339 ) ;
V_484 -> V_487 . V_488 . V_494 = 0 ;
V_484 -> V_487 . V_488 . V_495 = 0 ;
V_486 = (struct V_485 * ) V_484 ;
V_486 -> V_496 = F_174 ( 0x81000044 ) ;
V_3 = F_175 ( V_2 , V_486 , 0x44 ) ;
F_11 ( V_484 ) ;
F_39 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_3 V_361 ;
int V_497 , V_498 ;
struct V_474 * V_474 = V_2 -> V_27 ;
struct V_93 * V_499 ;
V_499 = (struct V_93 * ) & V_2 -> V_94 ;
if ( V_2 -> V_94 . V_401 == V_355 ) {
V_361 = ( (struct V_356 * ) V_499 ) -> V_363 ;
V_497 = sizeof( struct V_356 ) ;
V_498 = V_355 ;
} else {
V_361 = ( (struct V_350 * ) V_499 ) -> V_362 ;
V_497 = sizeof( struct V_350 ) ;
V_498 = V_349 ;
}
if ( V_474 == NULL ) {
V_3 = F_176 ( F_104 ( V_2 ) , V_498 , V_500 ,
V_501 , & V_474 , 1 ) ;
if ( V_3 < 0 ) {
F_27 ( 1 , L_157 , V_3 ) ;
V_2 -> V_27 = NULL ;
return V_3 ;
}
F_5 ( 1 , L_158 ) ;
V_2 -> V_27 = V_474 ;
V_474 -> V_476 -> V_502 = V_73 ;
if ( V_498 == V_355 )
F_170 ( V_474 ) ;
else
F_166 ( V_474 ) ;
}
V_3 = F_172 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_474 -> V_476 -> V_503 = 7 * V_52 ;
V_474 -> V_476 -> V_504 = 5 * V_52 ;
if ( V_2 -> V_227 ) {
if ( V_474 -> V_476 -> V_505 < ( 200 * 1024 ) )
V_474 -> V_476 -> V_505 = 200 * 1024 ;
if ( V_474 -> V_476 -> V_506 < ( 140 * 1024 ) )
V_474 -> V_476 -> V_506 = 140 * 1024 ;
}
if ( V_2 -> V_396 ) {
int V_507 = 1 ;
V_3 = F_177 ( V_474 , V_508 , V_509 ,
( char * ) & V_507 , sizeof( V_507 ) ) ;
if ( V_3 )
F_5 ( 1 , L_159 , V_3 ) ;
}
F_5 ( 1 , L_160 ,
V_474 -> V_476 -> V_505 ,
V_474 -> V_476 -> V_506 , V_474 -> V_476 -> V_503 ) ;
V_3 = V_474 -> V_48 -> V_510 ( V_474 , V_499 , V_497 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( 1 , L_161 , V_3 ) ;
F_10 ( V_474 ) ;
V_2 -> V_27 = NULL ;
return V_3 ;
}
if ( V_361 == F_99 ( V_364 ) )
V_3 = F_173 ( V_2 ) ;
return V_3 ;
}
static int
F_124 ( struct V_1 * V_2 )
{
T_3 * V_361 ;
struct V_356 * V_367 = (struct V_356 * ) & V_2 -> V_94 ;
struct V_350 * V_360 = (struct V_350 * ) & V_2 -> V_94 ;
if ( V_2 -> V_94 . V_401 == V_355 )
V_361 = & V_367 -> V_363 ;
else
V_361 = & V_360 -> V_362 ;
if ( * V_361 == 0 ) {
int V_3 ;
* V_361 = F_99 ( V_95 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_361 = F_99 ( V_364 ) ;
}
return F_18 ( V_2 ) ;
}
void F_178 ( unsigned int V_407 , struct V_9 * V_10 ,
struct V_446 * V_447 , struct V_140 * V_511 )
{
T_5 V_512 = F_179 ( V_10 -> V_513 . V_514 ) ;
if ( V_511 && V_511 -> V_245 ) {
V_10 -> V_513 . V_514 = 0 ;
V_10 -> V_515 = 0 ;
F_5 ( 1 , L_162 ) ;
return;
} else if ( V_511 )
V_10 -> V_515 = 1 ;
if ( V_10 -> V_515 == 0 ) {
F_5 ( 1 , L_163 ) ;
return;
}
if ( ! F_180 ( V_407 , V_10 ) ) {
T_5 V_516 = F_179 ( V_10 -> V_513 . V_514 ) ;
F_5 ( 1 , L_164 , V_516 ) ;
if ( V_511 == NULL ) {
if ( ( V_512 & V_517 ) == 0 )
V_516 &= ~ V_517 ;
if ( ( V_512 & V_518 ) == 0 ) {
if ( V_516 & V_518 )
F_27 ( 1 , L_165 ) ;
V_516 &= ~ V_518 ;
} else if ( ( V_516 & V_518 ) == 0 ) {
F_27 ( 1 , L_166 ) ;
F_27 ( 1 , L_167 ) ;
}
}
if ( V_516 & V_519 )
F_27 ( 1 , L_168 ) ;
V_516 &= V_520 ;
if ( V_511 && V_511 -> V_278 )
V_516 &= ~ V_517 ;
else if ( V_517 & V_516 ) {
F_5 ( 1 , L_169 ) ;
if ( V_447 )
V_447 -> V_456 |=
V_521 ;
}
if ( V_511 && V_511 -> V_208 == 0 )
V_516 &= ~ V_518 ;
else if ( V_516 & V_518 ) {
F_5 ( 1 , L_170 ) ;
if ( V_447 )
V_447 -> V_456 |=
V_522 ;
}
F_5 ( 1 , L_171 , ( int ) V_516 ) ;
#ifdef F_62
if ( V_516 & V_523 )
F_5 ( 1 , L_172 ) ;
if ( V_516 & V_524 )
F_5 ( 1 , L_173 ) ;
if ( V_516 & V_518 )
F_5 ( 1 , L_174 ) ;
if ( V_516 & V_525 )
F_5 ( 1 , L_175 ) ;
if ( V_516 & V_517 )
F_5 ( 1 , L_176 ) ;
if ( V_516 & V_526 )
F_5 ( 1 , L_177 ) ;
if ( V_516 & V_527 )
F_5 ( 1 , L_178 ) ;
if ( V_516 & V_528 )
F_5 ( 1 , L_179 ) ;
if ( V_516 & V_519 )
F_5 ( 1 , L_180 ) ;
#endif
if ( F_181 ( V_407 , V_10 , V_516 ) ) {
if ( V_511 == NULL ) {
F_5 ( 1 , L_181 ) ;
} else
F_27 ( 1 , L_182
L_183
L_184
L_185
L_186
L_39 ) ;
}
}
}
void F_182 ( struct V_140 * V_529 ,
struct V_446 * V_447 )
{
F_123 ( & V_447 -> V_530 , V_531 ) ;
F_122 ( & V_447 -> V_532 ) ;
V_447 -> V_533 = V_534 ;
V_447 -> V_308 = V_529 -> V_308 ;
V_447 -> V_310 = V_529 -> V_310 ;
V_447 -> V_458 = V_529 -> V_201 ;
V_447 -> V_459 = V_529 -> V_202 ;
V_447 -> V_460 = V_529 -> V_204 ;
V_447 -> V_461 = V_529 -> V_203 ;
F_5 ( 1 , L_187 ,
V_447 -> V_460 , V_447 -> V_461 ) ;
V_447 -> V_210 = V_529 -> V_210 ;
V_447 -> V_425 = V_529 -> V_425 ;
if ( V_529 -> V_232 )
V_447 -> V_456 |= V_535 ;
if ( V_529 -> V_257 )
V_447 -> V_456 |= V_536 ;
if ( V_529 -> V_209 )
V_447 -> V_456 |= V_537 ;
if ( V_529 -> V_235 )
V_447 -> V_456 |= V_538 ;
if ( V_529 -> V_220 )
V_447 -> V_456 |= V_539 ;
if ( V_529 -> V_238 )
V_447 -> V_456 |= V_540 ;
if ( V_529 -> V_249 )
V_447 -> V_456 |= V_541 ;
if ( V_529 -> V_268 )
V_447 -> V_456 |= V_542 ;
if ( V_529 -> V_255 )
V_447 -> V_456 |= V_543 ;
if ( V_529 -> V_273 )
V_447 -> V_456 |= V_544 ;
if ( V_529 -> V_275 )
V_447 -> V_456 |= V_545 ;
if ( V_529 -> V_214 ) {
V_447 -> V_456 |= V_546 ;
V_447 -> V_547 = V_529 -> V_297 ;
}
if ( V_529 -> V_215 ) {
V_447 -> V_456 |= V_548 ;
V_447 -> V_549 = V_529 -> V_299 ;
}
if ( V_529 -> V_187 )
V_447 -> V_456 |= V_550 ;
if ( V_529 -> V_188 )
V_447 -> V_456 |= V_551 ;
if ( V_529 -> V_260 )
V_447 -> V_456 |= V_552 ;
if ( V_529 -> V_290 )
V_447 -> V_456 |= V_553 ;
if ( V_529 -> V_294 )
V_447 -> V_456 |= ( V_554 |
V_535 ) ;
if ( V_529 -> V_166 )
V_447 -> V_456 |= V_555 ;
if ( V_529 -> V_165 ) {
F_5 ( 1 , L_188 ) ;
V_447 -> V_456 |= V_556 ;
}
if ( V_529 -> V_292 ) {
if ( V_529 -> V_238 ) {
F_27 ( 1 , L_189
L_190 ) ;
} else {
V_447 -> V_456 |= V_557 ;
}
}
if ( ( V_529 -> V_275 ) && ( V_529 -> V_260 ) )
F_27 ( 1 , L_191
L_192 ) ;
}
static unsigned int
F_183 ( struct V_9 * V_10 , struct V_140 * V_529 )
{
T_5 V_558 = F_179 ( V_10 -> V_513 . V_514 ) ;
struct V_1 * V_2 = V_10 -> V_8 -> V_2 ;
unsigned int V_310 ;
if ( V_529 -> V_310 )
V_310 = V_529 -> V_310 ;
else if ( V_10 -> V_515 && ( V_558 & V_527 ) )
V_310 = V_559 ;
else
V_310 = V_560 ;
if ( ! V_10 -> V_515 || ! ( V_558 & V_527 ) )
V_310 = F_56 (unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE) ;
if ( ! ( V_2 -> V_561 & V_562 ) ||
( ! ( V_2 -> V_561 & V_563 ) &&
( V_2 -> V_381 & ( V_383 | V_382 ) ) ) )
V_310 = F_56 (unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4 ) ;
V_310 = F_56 (unsigned int, wsize, CIFS_KMAP_SIZE_LIMIT) ;
V_310 = F_56 (unsigned int, wsize, CIFS_MAX_WSIZE) ;
return V_310 ;
}
static unsigned int
F_184 ( struct V_9 * V_10 , struct V_140 * V_529 )
{
T_5 V_558 = F_179 ( V_10 -> V_513 . V_514 ) ;
struct V_1 * V_2 = V_10 -> V_8 -> V_2 ;
unsigned int V_308 , V_564 ;
if ( V_10 -> V_515 && ( V_558 & V_526 ) )
V_564 = V_559 ;
else if ( V_2 -> V_561 & V_565 )
V_564 = V_566 ;
else
V_564 = V_2 -> V_18 - sizeof( V_567 ) ;
V_308 = V_529 -> V_308 ? V_529 -> V_308 : V_564 ;
if ( ! ( V_2 -> V_561 & V_565 ) )
V_308 = F_56 (unsigned int, CIFSMaxBufSize, rsize) ;
V_308 = F_56 (unsigned int, rsize, CIFS_KMAP_SIZE_LIMIT) ;
V_308 = F_56 (unsigned int, rsize, CIFS_MAX_RSIZE) ;
return V_308 ;
}
static void
F_185 ( struct V_140 * V_389 )
{
F_11 ( V_389 -> V_314 ) ;
F_186 ( V_389 -> V_319 ) ;
if ( V_389 -> V_322 != V_389 -> V_326 + 2 )
F_11 ( V_389 -> V_322 ) ;
F_11 ( V_389 -> V_326 ) ;
F_11 ( V_389 -> V_328 ) ;
F_11 ( V_389 -> V_334 ) ;
F_11 ( V_389 -> V_332 ) ;
}
void
F_187 ( struct V_140 * V_389 )
{
if ( ! V_389 )
return;
F_185 ( V_389 ) ;
F_11 ( V_389 ) ;
}
static char *
F_188 ( const struct V_140 * V_141 ,
const struct V_446 * V_447 )
{
char * V_568 , * V_569 ;
unsigned int V_570 = V_141 -> V_332 ? strlen ( V_141 -> V_332 ) : 0 ;
unsigned int V_571 = F_83 ( V_141 -> V_326 , V_432 + 1 ) ;
V_568 = F_36 ( V_571 + V_570 + 1 , V_114 ) ;
if ( V_568 == NULL )
return F_72 ( - V_81 ) ;
strncpy ( V_568 , V_141 -> V_326 , V_571 ) ;
V_569 = V_568 + V_571 ;
if ( V_570 ) {
strncpy ( V_569 , V_141 -> V_332 , V_570 ) ;
V_569 += V_570 ;
}
* V_569 = '\0' ;
F_189 ( V_568 , F_190 ( V_447 ) ) ;
F_5 ( 1 , L_193 , V_20 , V_568 ) ;
return V_568 ;
}
static int
F_191 ( const unsigned int V_407 , struct V_7 * V_8 ,
struct V_140 * V_389 , struct V_446 * V_447 ,
int V_572 )
{
int V_3 ;
unsigned int V_468 = 0 ;
struct V_469 * V_470 = NULL ;
char * V_568 = NULL , * V_573 = NULL , * V_574 = NULL ;
V_568 = F_188 ( V_389 , V_447 ) ;
if ( F_118 ( V_568 ) )
return F_119 ( V_568 ) ;
V_573 = V_572 ? V_568 + 1 : V_389 -> V_326 + 1 ;
V_3 = F_165 ( V_407 , V_8 , V_573 , V_447 -> V_425 ,
& V_468 , & V_470 ,
V_447 -> V_456 & V_538 ) ;
if ( ! V_3 && V_468 > 0 ) {
char * V_575 = NULL ;
V_574 = F_192 ( V_447 -> V_177 ,
V_568 + 1 , V_470 ,
& V_575 ) ;
F_193 ( V_470 , V_468 ) ;
if ( F_118 ( V_574 ) ) {
V_3 = F_119 ( V_574 ) ;
V_574 = NULL ;
} else {
F_185 ( V_389 ) ;
memset ( V_389 , '\0' , sizeof( * V_389 ) ) ;
V_3 = F_194 ( V_389 , V_574 ,
V_575 ) ;
}
F_11 ( V_575 ) ;
F_11 ( V_447 -> V_177 ) ;
V_447 -> V_177 = V_574 ;
}
F_11 ( V_568 ) ;
return V_3 ;
}
static int
F_194 ( struct V_140 * V_389 , char * V_576 ,
const char * V_178 )
{
int V_3 = 0 ;
if ( F_81 ( V_576 , V_178 , V_389 ) )
return - V_137 ;
if ( V_389 -> V_162 ) {
F_5 ( 1 , L_194 ) ;
F_11 ( V_389 -> V_314 ) ;
V_389 -> V_314 = NULL ;
} else if ( V_389 -> V_314 ) {
F_5 ( 1 , L_195 , V_389 -> V_314 ) ;
} else {
F_195 ( L_196 ) ;
return - V_137 ;
}
if ( V_389 -> V_334 == NULL ) {
V_389 -> V_425 = F_196 () ;
} else {
V_389 -> V_425 = F_197 ( V_389 -> V_334 ) ;
if ( V_389 -> V_425 == NULL ) {
F_27 ( 1 , L_197 ,
V_389 -> V_334 ) ;
return - V_577 ;
}
}
return V_3 ;
}
struct V_140 *
F_198 ( char * V_576 , const char * V_178 )
{
int V_3 ;
struct V_140 * V_389 ;
V_389 = F_91 ( sizeof( struct V_140 ) , V_114 ) ;
if ( ! V_389 )
return F_72 ( - V_81 ) ;
V_3 = F_194 ( V_389 , V_576 , V_178 ) ;
if ( V_3 ) {
F_187 ( V_389 ) ;
V_389 = F_72 ( V_3 ) ;
}
return V_389 ;
}
int
F_199 ( struct V_446 * V_447 , struct V_140 * V_389 )
{
int V_3 ;
unsigned int V_407 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_568 ;
struct V_440 * V_441 ;
#ifdef F_200
int V_578 = 0 ;
#endif
V_3 = F_201 ( & V_447 -> V_579 , L_198 , V_580 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_200
V_581:
if ( V_578 ) {
if ( V_10 )
F_150 ( V_10 ) ;
else if ( V_8 )
F_132 ( V_8 ) ;
F_145 ( V_407 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_568 = NULL ;
V_441 = NULL ;
V_407 = F_133 () ;
V_2 = F_113 ( V_389 ) ;
if ( F_118 ( V_2 ) ) {
V_3 = F_119 ( V_2 ) ;
F_202 ( & V_447 -> V_579 ) ;
goto V_464;
}
V_8 = F_143 ( V_2 , V_389 ) ;
if ( F_118 ( V_8 ) ) {
V_3 = F_119 ( V_8 ) ;
V_8 = NULL ;
goto V_582;
}
V_10 = F_153 ( V_8 , V_389 ) ;
if ( F_118 ( V_10 ) ) {
V_3 = F_119 ( V_10 ) ;
V_10 = NULL ;
goto V_583;
}
if ( F_203 ( V_10 -> V_8 ) ) {
F_178 ( V_407 , V_10 , V_447 , V_389 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_179 ( V_10 -> V_513 . V_514 ) &
V_519 ) ) {
V_3 = - V_584 ;
goto V_582;
}
} else
V_10 -> V_515 = 0 ;
if ( ! V_10 -> V_585 && V_2 -> V_48 -> V_586 )
V_2 -> V_48 -> V_586 ( V_407 , V_10 ) ;
V_447 -> V_310 = F_183 ( V_10 , V_389 ) ;
V_447 -> V_308 = F_184 ( V_10 , V_389 ) ;
V_447 -> V_579 . V_587 = V_447 -> V_308 / V_588 ;
V_583:
#ifdef F_200
if ( V_578 == 0 ) {
int V_589 = F_191 ( V_407 , V_8 , V_389 , V_447 ,
false ) ;
if ( ! V_589 ) {
V_578 ++ ;
goto V_581;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_48 -> V_590 ) {
V_3 = - V_54 ;
goto V_582;
}
V_568 = F_204 ( V_389 , V_447 , V_10 ) ;
if ( V_568 == NULL ) {
V_3 = - V_81 ;
goto V_582;
}
V_3 = V_2 -> V_48 -> V_590 ( V_407 , V_10 , V_447 ,
V_568 ) ;
if ( V_3 != 0 && V_3 != - V_591 ) {
F_11 ( V_568 ) ;
goto V_582;
}
F_11 ( V_568 ) ;
}
if ( V_3 == - V_591 ) {
#ifdef F_200
if ( V_578 > V_592 ) {
V_3 = - V_593 ;
goto V_582;
}
V_3 = F_191 ( V_407 , V_8 , V_389 , V_447 , true ) ;
if ( ! V_3 ) {
V_578 ++ ;
goto V_581;
}
goto V_582;
#else
V_3 = - V_594 ;
#endif
}
if ( V_3 )
goto V_582;
V_441 = F_91 ( sizeof *V_441 , V_114 ) ;
if ( V_441 == NULL ) {
V_3 = - V_81 ;
goto V_582;
}
V_441 -> V_595 = V_8 -> V_201 ;
V_441 -> V_596 = V_10 ;
V_441 -> V_445 = V_37 ;
F_205 ( V_597 , & V_441 -> V_444 ) ;
F_205 ( V_443 , & V_441 -> V_444 ) ;
V_447 -> V_448 = V_441 ;
F_2 ( & V_447 -> V_532 ) ;
F_206 ( & V_447 -> V_533 , V_441 ) ;
F_3 ( & V_447 -> V_532 ) ;
F_24 ( V_56 , & V_447 -> V_530 ,
V_598 ) ;
V_582:
if ( V_3 ) {
if ( V_10 )
F_150 ( V_10 ) ;
else if ( V_8 )
F_132 ( V_8 ) ;
else
F_107 ( V_2 ) ;
F_202 ( & V_447 -> V_579 ) ;
}
V_464:
F_145 ( V_407 ) ;
return V_3 ;
}
int
F_207 ( const unsigned int V_407 , struct V_7 * V_8 ,
const char * V_599 , struct V_9 * V_10 ,
const struct V_466 * V_467 )
{
struct V_485 * V_600 ;
struct V_485 * V_601 ;
T_6 * V_602 ;
T_7 * V_603 ;
unsigned char * V_604 ;
int V_3 = 0 ;
int V_76 ;
T_8 V_605 , V_606 ;
if ( V_8 == NULL )
return - V_607 ;
V_600 = F_26 () ;
if ( V_600 == NULL )
return - V_81 ;
V_601 = V_600 ;
F_208 ( V_600 , V_608 ,
NULL , 4 ) ;
V_600 -> V_609 = F_209 ( V_8 -> V_2 ) ;
V_600 -> V_610 = V_8 -> V_611 ;
V_602 = ( T_6 * ) V_600 ;
V_603 = ( T_7 * ) V_601 ;
V_602 -> V_612 = 0xFF ;
V_602 -> V_438 = F_210 ( V_613 ) ;
V_604 = & V_602 -> V_614 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_381 & V_615 ) ) {
V_602 -> V_616 = F_210 ( 1 ) ;
* V_604 = 0 ;
V_604 ++ ;
} else {
V_602 -> V_616 = F_210 ( V_617 ) ;
#ifdef F_78
if ( ( V_372 & V_160 ) &&
( V_8 -> V_2 -> V_373 == V_374 ) )
F_211 ( V_10 -> V_319 , V_8 -> V_2 -> V_618 ,
V_8 -> V_2 -> V_381 &
V_619 ? true : false ,
V_604 ) ;
else
#endif
V_3 = F_212 ( V_10 -> V_319 , V_8 -> V_2 -> V_618 ,
V_604 , V_467 ) ;
V_604 += V_617 ;
if ( V_8 -> V_561 & V_620 ) {
* V_604 = 0 ;
V_604 ++ ;
}
}
if ( V_8 -> V_2 -> V_381 &
( V_382 | V_383 ) )
V_600 -> V_621 |= V_622 ;
if ( V_8 -> V_561 & V_623 ) {
V_600 -> V_621 |= V_624 ;
}
if ( V_8 -> V_561 & V_625 ) {
V_600 -> V_621 |= V_626 ;
}
if ( V_8 -> V_561 & V_620 ) {
V_600 -> V_621 |= V_627 ;
V_76 =
F_213 ( ( V_628 * ) V_604 , V_599 ,
6 *
( + 256 ) , V_467 ) ;
V_604 += 2 * V_76 ;
V_604 += 2 ;
} else {
strcpy ( V_604 , V_599 ) ;
V_604 += strlen ( V_599 ) + 1 ;
}
strcpy ( V_604 , L_199 ) ;
V_604 += strlen ( L_199 ) ;
V_604 += 1 ;
V_606 = V_604 - & V_602 -> V_614 [ 0 ] ;
V_602 -> V_629 . V_496 = F_174 ( F_214 (
V_602 -> V_629 . V_496 ) + V_606 ) ;
V_602 -> V_630 = F_210 ( V_606 ) ;
V_3 = F_215 ( V_407 , V_8 , V_600 , V_601 , & V_76 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_631 ;
V_10 -> V_430 = V_60 ;
V_10 -> V_23 = false ;
V_10 -> V_632 = V_601 -> V_633 ;
V_604 = F_216 ( V_601 ) ;
V_605 = F_217 ( V_601 ) ;
V_76 = F_83 ( V_604 , V_605 - 2 ) ;
if ( V_600 -> V_621 & V_627 )
V_631 = true ;
else
V_631 = false ;
if ( V_76 == 3 ) {
if ( ( V_604 [ 0 ] == 'I' ) && ( V_604 [ 1 ] == 'P' ) &&
( V_604 [ 2 ] == 'C' ) ) {
F_5 ( 1 , L_200 ) ;
V_10 -> V_585 = 1 ;
}
} else if ( V_76 == 2 ) {
if ( ( V_604 [ 0 ] == 'A' ) && ( V_604 [ 1 ] == ':' ) ) {
F_5 ( 1 , L_201 ) ;
}
}
V_604 += V_76 + 1 ;
V_605 -= ( V_76 + 1 ) ;
strncpy ( V_10 -> V_431 , V_599 , V_432 ) ;
F_11 ( V_10 -> V_634 ) ;
V_10 -> V_634 = F_218 ( V_604 ,
V_605 , V_631 ,
V_467 ) ;
F_5 ( 1 , L_202 , V_10 -> V_634 ) ;
if ( ( V_601 -> V_635 == 3 ) ||
( V_601 -> V_635 == 7 ) )
V_10 -> V_438 = F_219 ( V_603 -> V_636 ) ;
else
V_10 -> V_438 = 0 ;
F_5 ( 1 , L_203 , V_10 -> V_438 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_24 = V_601 -> V_633 ;
}
F_64 ( V_600 ) ;
return V_3 ;
}
void
F_220 ( struct V_446 * V_447 )
{
struct V_637 * V_638 = & V_447 -> V_533 ;
struct V_639 * V_640 ;
struct V_440 * V_441 ;
F_109 ( & V_447 -> V_530 ) ;
F_2 ( & V_447 -> V_532 ) ;
while ( ( V_640 = F_221 ( V_638 ) ) ) {
V_441 = F_222 ( V_640 , struct V_440 , V_641 ) ;
F_164 ( V_441 ) ;
F_223 ( V_443 , & V_441 -> V_444 ) ;
F_224 ( V_640 , V_638 ) ;
F_3 ( & V_447 -> V_532 ) ;
F_156 ( V_441 ) ;
F_2 ( & V_447 -> V_532 ) ;
}
F_3 ( & V_447 -> V_532 ) ;
F_202 ( & V_447 -> V_579 ) ;
F_11 ( V_447 -> V_177 ) ;
F_225 ( V_447 -> V_425 ) ;
F_11 ( V_447 ) ;
}
int
F_144 ( const unsigned int V_407 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_48 -> V_49 || ! V_2 -> V_48 -> V_642 )
return - V_54 ;
if ( ! V_2 -> V_48 -> V_49 ( V_2 ) )
return 0 ;
F_226 ( V_2 , 1 ) ;
V_3 = V_2 -> V_48 -> V_642 ( V_407 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_44 )
V_2 -> V_15 = V_60 ;
else
V_3 = - V_643 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_146 ( const unsigned int V_407 , struct V_7 * V_8 ,
struct V_466 * V_644 )
{
int V_3 = - V_54 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_29 = 0 ;
V_8 -> V_561 = V_2 -> V_561 ;
if ( V_645 == 0 )
V_8 -> V_561 &= ( ~ V_2 -> V_172 -> F_203 ) ;
F_5 ( 1 , L_204 ,
V_2 -> V_381 , V_2 -> V_561 , V_2 -> V_646 ) ;
if ( V_2 -> V_48 -> V_647 )
V_3 = V_2 -> V_48 -> V_647 ( V_407 , V_8 , V_644 ) ;
if ( V_3 ) {
F_27 ( 1 , L_205 , V_3 ) ;
} else {
F_8 ( & V_8 -> V_2 -> V_26 ) ;
if ( ! V_2 -> V_32 ) {
V_2 -> V_33 . V_34 = V_8 -> V_648 . V_34 ;
V_2 -> V_33 . V_35 = V_8 -> V_648 . V_35 ;
V_2 -> V_31 = 0x2 ;
V_2 -> V_32 = true ;
V_8 -> V_648 . V_34 = NULL ;
}
F_12 ( & V_2 -> V_26 ) ;
F_5 ( 1 , L_206 ) ;
F_2 ( & V_14 ) ;
V_8 -> V_408 = V_60 ;
V_8 -> V_23 = false ;
F_3 ( & V_14 ) ;
}
F_11 ( V_8 -> V_648 . V_34 ) ;
V_8 -> V_648 . V_34 = NULL ;
V_8 -> V_648 . V_35 = 0 ;
F_11 ( V_8 -> V_649 ) ;
V_8 -> V_649 = NULL ;
return V_3 ;
}
static int
F_227 ( struct V_140 * V_141 , struct V_7 * V_8 )
{
switch ( V_8 -> V_2 -> V_373 ) {
case V_378 :
V_141 -> V_145 = V_650 ;
return 0 ;
case V_376 :
V_141 -> V_145 = V_651 ;
break;
case V_377 :
V_141 -> V_145 = V_652 ;
break;
case V_379 :
V_141 -> V_145 = V_653 ;
break;
case V_374 :
V_141 -> V_145 = V_654 ;
break;
}
return F_136 ( V_141 , V_8 ) ;
}
static struct V_9 *
F_228 ( struct V_446 * V_447 , T_9 V_655 )
{
int V_3 ;
struct V_9 * V_656 = F_229 ( V_447 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_140 * V_511 ;
V_511 = F_91 ( sizeof( * V_511 ) , V_114 ) ;
if ( V_511 == NULL )
return F_72 ( - V_81 ) ;
V_511 -> V_425 = V_447 -> V_425 ;
V_511 -> V_201 = V_655 ;
V_511 -> V_200 = V_655 ;
V_511 -> V_326 = V_656 -> V_431 ;
V_511 -> V_229 = V_656 -> V_229 ;
V_511 -> V_247 = V_656 -> V_247 ;
V_511 -> V_281 = V_656 -> V_281 ;
V_511 -> V_245 = ! V_656 -> V_515 ;
V_3 = F_227 ( V_511 , V_656 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_72 ( V_3 ) ;
goto V_464;
}
F_2 ( & V_21 ) ;
++ V_656 -> V_8 -> V_2 -> V_386 ;
F_3 ( & V_21 ) ;
V_8 = F_143 ( V_656 -> V_8 -> V_2 , V_511 ) ;
if ( F_118 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_107 ( V_656 -> V_8 -> V_2 ) ;
goto V_464;
}
V_10 = F_153 ( V_8 , V_511 ) ;
if ( F_118 ( V_10 ) ) {
F_132 ( V_8 ) ;
goto V_464;
}
if ( F_203 ( V_8 ) )
F_178 ( 0 , V_10 , NULL , V_511 ) ;
V_464:
F_11 ( V_511 -> V_314 ) ;
F_11 ( V_511 -> V_319 ) ;
F_11 ( V_511 ) ;
return V_10 ;
}
struct V_9 *
F_229 ( struct V_446 * V_447 )
{
return F_159 ( F_160 ( V_447 ) ) ;
}
static int
F_230 ( void * V_657 )
{
F_69 () ;
return F_68 ( V_122 ) ? - V_86 : 0 ;
}
static struct V_440 *
F_231 ( struct V_637 * V_638 , T_9 V_658 )
{
struct V_639 * V_640 = V_638 -> V_639 ;
struct V_440 * V_441 ;
while ( V_640 ) {
V_441 = F_222 ( V_640 , struct V_440 , V_641 ) ;
if ( V_441 -> V_595 > V_658 )
V_640 = V_640 -> V_659 ;
else if ( V_441 -> V_595 < V_658 )
V_640 = V_640 -> V_660 ;
else
return V_441 ;
}
return NULL ;
}
static void
F_206 ( struct V_637 * V_638 , struct V_440 * V_661 )
{
struct V_639 * * V_63 = & ( V_638 -> V_639 ) , * V_662 = NULL ;
struct V_440 * V_441 ;
while ( * V_63 ) {
V_441 = F_222 ( * V_63 , struct V_440 , V_641 ) ;
V_662 = * V_63 ;
if ( V_441 -> V_595 > V_661 -> V_595 )
V_63 = & ( ( * V_63 ) -> V_659 ) ;
else
V_63 = & ( ( * V_63 ) -> V_660 ) ;
}
F_232 ( & V_661 -> V_641 , V_662 , V_63 ) ;
F_233 ( & V_661 -> V_641 , V_638 ) ;
}
struct V_440 *
F_234 ( struct V_446 * V_447 )
{
int V_663 ;
T_9 V_655 = F_235 () ;
struct V_440 * V_441 , * V_664 ;
if ( ! ( V_447 -> V_456 & V_554 ) )
return F_164 ( F_160 ( V_447 ) ) ;
F_2 ( & V_447 -> V_532 ) ;
V_441 = F_231 ( & V_447 -> V_533 , V_655 ) ;
if ( V_441 )
F_164 ( V_441 ) ;
F_3 ( & V_447 -> V_532 ) ;
if ( V_441 == NULL ) {
V_664 = F_91 ( sizeof( * V_441 ) , V_114 ) ;
if ( V_664 == NULL )
return F_72 ( - V_81 ) ;
V_664 -> V_595 = V_655 ;
V_664 -> V_596 = F_72 ( - V_584 ) ;
F_205 ( V_665 , & V_664 -> V_444 ) ;
F_205 ( V_443 , & V_664 -> V_444 ) ;
F_164 ( V_664 ) ;
F_2 ( & V_447 -> V_532 ) ;
V_441 = F_231 ( & V_447 -> V_533 , V_655 ) ;
if ( V_441 ) {
F_164 ( V_441 ) ;
F_3 ( & V_447 -> V_532 ) ;
F_11 ( V_664 ) ;
goto V_666;
}
V_441 = V_664 ;
F_206 ( & V_447 -> V_533 , V_441 ) ;
F_3 ( & V_447 -> V_532 ) ;
} else {
V_666:
V_663 = F_236 ( & V_441 -> V_444 , V_665 ,
F_230 ,
V_131 ) ;
if ( V_663 ) {
F_156 ( V_441 ) ;
return F_72 ( V_663 ) ;
}
if ( ! F_118 ( V_441 -> V_596 ) )
return V_441 ;
if ( F_23 ( V_37 , V_441 -> V_445 + V_667 ) ) {
F_156 ( V_441 ) ;
return F_72 ( - V_584 ) ;
}
if ( F_237 ( V_665 , & V_441 -> V_444 ) )
goto V_666;
}
V_441 -> V_596 = F_228 ( V_447 , V_655 ) ;
F_223 ( V_665 , & V_441 -> V_444 ) ;
F_238 ( & V_441 -> V_444 , V_665 ) ;
if ( F_118 ( V_441 -> V_596 ) ) {
F_156 ( V_441 ) ;
return F_72 ( - V_584 ) ;
}
return V_441 ;
}
static void
V_531 ( struct V_45 * V_46 )
{
struct V_446 * V_447 = F_22 ( V_46 , struct V_446 ,
V_530 . V_46 ) ;
struct V_637 * V_638 = & V_447 -> V_533 ;
struct V_639 * V_640 = F_221 ( V_638 ) ;
struct V_639 * V_5 ;
struct V_440 * V_441 ;
F_2 ( & V_447 -> V_532 ) ;
V_640 = F_221 ( V_638 ) ;
while ( V_640 != NULL ) {
V_5 = V_640 ;
V_640 = F_239 ( V_5 ) ;
V_441 = F_222 ( V_5 , struct V_440 , V_641 ) ;
if ( F_158 ( V_597 , & V_441 -> V_444 ) ||
F_61 ( & V_441 -> V_442 ) != 0 ||
F_31 ( V_441 -> V_445 + V_598 , V_37 ) )
continue;
F_164 ( V_441 ) ;
F_223 ( V_443 , & V_441 -> V_444 ) ;
F_224 ( V_5 , V_638 ) ;
F_3 ( & V_447 -> V_532 ) ;
F_156 ( V_441 ) ;
F_2 ( & V_447 -> V_532 ) ;
}
F_3 ( & V_447 -> V_532 ) ;
F_24 ( V_56 , & V_447 -> V_530 ,
V_598 ) ;
}
