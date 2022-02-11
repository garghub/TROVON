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
if ( V_2 -> V_48 -> V_119 &&
V_2 -> V_48 -> V_119 ( V_88 , V_2 , V_76 ) )
return - 1 ;
if ( ! V_96 )
return V_76 ;
F_45 ( V_96 , V_2 , V_88 , V_76 ) ;
return 0 ;
}
static int
F_57 ( void * V_120 )
{
int V_76 ;
struct V_1 * V_2 = V_120 ;
unsigned int V_115 ;
char * V_88 = NULL ;
struct V_121 * V_122 = NULL ;
struct V_11 * V_12 ;
V_123 -> V_29 |= V_124 ;
F_5 ( 1 , L_25 , F_58 ( V_123 ) ) ;
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
V_12 = V_2 -> V_48 -> V_125 ( V_2 , V_88 ) ;
if ( ! V_12 || ! V_12 -> V_126 )
V_76 = F_51 ( V_2 , V_12 ) ;
else
V_76 = V_12 -> V_126 ( V_2 , V_12 ) ;
if ( V_76 < 0 )
continue;
if ( V_2 -> V_58 )
V_88 = V_2 -> V_57 ;
V_2 -> V_36 = V_37 ;
if ( V_12 != NULL ) {
if ( ! V_12 -> V_103 || V_12 -> V_127 )
V_12 -> V_42 ( V_12 ) ;
} else if ( ! V_2 -> V_48 -> V_128 ||
! V_2 -> V_48 -> V_128 ( V_88 , V_2 ) ) {
F_27 ( 1 , L_28
L_29 , F_61 ( & V_129 ) ) ;
F_55 ( L_30 , V_88 ,
F_28 ( V_2 ) ) ;
#ifdef F_62
if ( V_2 -> V_48 -> V_130 )
V_2 -> V_48 -> V_130 ( V_88 ) ;
F_63 ( V_2 ) ;
#endif
}
}
F_64 ( V_2 -> V_57 ) ;
if ( V_2 -> V_59 )
F_65 ( V_2 -> V_59 ) ;
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
unsigned int V_35 ;
V_135 = V_134 + 2 ;
V_137 = strchr ( V_135 , '\\' ) ;
if ( ! V_137 )
return F_72 ( - V_138 ) ;
V_35 = V_137 - V_135 ;
V_136 = F_36 ( ( V_35 + 1 ) , V_114 ) ;
if ( V_136 == NULL )
return F_72 ( - V_81 ) ;
memcpy ( V_136 , V_135 , V_35 ) ;
V_136 [ V_35 ] = '\0' ;
return V_136 ;
}
static int F_73 ( T_2 args [] , unsigned long * V_139 )
{
int V_3 ;
char * string ;
string = F_74 ( args ) ;
if ( string == NULL )
return - V_81 ;
V_3 = F_75 ( string , 0 , V_139 ) ;
F_11 ( string ) ;
return V_3 ;
}
static int F_76 ( char * V_140 ,
struct V_141 * V_142 )
{
T_2 args [ V_143 ] ;
switch ( F_77 ( V_140 , V_144 , args ) ) {
case V_145 :
V_142 -> V_146 |= V_147 ;
break;
case V_148 :
V_142 -> V_146 |= V_147 | V_149 ;
break;
case V_150 :
F_27 ( 1 , L_31 ) ;
break;
case V_151 :
V_142 -> V_146 |= V_152 ;
break;
case V_153 :
V_142 -> V_146 |= V_152 | V_149 ;
break;
case V_154 :
V_142 -> V_146 |= V_155 ;
break;
case V_156 :
V_142 -> V_146 |= V_155 | V_149 ;
break;
case V_157 :
V_142 -> V_146 |= V_158 ;
break;
case V_159 :
V_142 -> V_146 |= V_158 | V_149 ;
break;
#ifdef F_78
case V_160 :
V_142 -> V_146 |= V_161 ;
break;
#endif
case V_162 :
V_142 -> V_163 = 1 ;
break;
default:
F_27 ( 1 , L_32 , V_140 ) ;
return 1 ;
}
return 0 ;
}
static int
F_79 ( char * V_140 , struct V_141 * V_142 )
{
T_2 args [ V_143 ] ;
switch ( F_77 ( V_140 , V_164 , args ) ) {
case V_165 :
V_142 -> V_166 = false ;
V_142 -> V_167 = false ;
break;
case V_168 :
V_142 -> V_166 = false ;
V_142 -> V_167 = true ;
break;
case V_169 :
V_142 -> V_166 = true ;
V_142 -> V_167 = false ;
break;
default:
F_27 ( 1 , L_33 , V_140 ) ;
return 1 ;
}
return 0 ;
}
static int
F_80 ( char * V_140 , struct V_141 * V_142 )
{
T_2 args [ V_143 ] ;
switch ( F_77 ( V_140 , V_170 , args ) ) {
case V_171 :
V_142 -> V_48 = & V_172 ;
V_142 -> V_173 = & V_174 ;
break;
#ifdef F_4
case V_175 :
V_142 -> V_48 = & V_176 ;
V_142 -> V_173 = & V_177 ;
break;
case V_178 :
V_142 -> V_48 = & V_176 ;
V_142 -> V_173 = & V_179 ;
break;
#endif
default:
F_27 ( 1 , L_34 , V_140 ) ;
return 1 ;
}
return 0 ;
}
static int
F_81 ( const char * V_180 , const char * V_181 ,
struct V_141 * V_142 )
{
char * V_182 , * V_183 ;
char * V_184 = NULL , * V_185 ;
unsigned int V_186 , V_187 , V_188 ;
char V_189 [ 2 ] ;
short int V_190 = - 1 ;
short int V_191 = - 1 ;
bool V_192 = false ;
bool V_193 = false ;
bool V_194 = false ;
char * V_195 = NULL ;
char * V_196 = F_82 () -> V_196 ;
char * string = NULL ;
char * V_197 , * V_140 ;
char V_137 ;
V_189 [ 0 ] = ',' ;
V_189 [ 1 ] = 0 ;
V_137 = V_189 [ 0 ] ;
memset ( V_142 -> V_198 , 0x20 , V_199 ) ;
for ( V_187 = 0 ; V_187 < F_83 ( V_196 , V_199 ) ; V_187 ++ )
V_142 -> V_198 [ V_187 ] = toupper ( V_196 [ V_187 ] ) ;
V_142 -> V_198 [ V_199 ] = 0 ;
V_142 -> V_200 [ 0 ] = 0 ;
V_142 -> V_201 = F_84 () ;
V_142 -> V_202 = F_84 () ;
V_142 -> V_203 = F_85 () ;
V_142 -> V_204 = V_142 -> V_205 = V_206 | V_207 | V_208 ;
V_142 -> V_209 = 1 ;
V_142 -> V_210 = 1 ;
V_142 -> V_167 = true ;
V_142 -> V_211 = V_212 ;
V_142 -> V_48 = & V_172 ;
V_142 -> V_173 = & V_174 ;
if ( ! V_180 )
goto V_213;
V_184 = F_86 ( V_180 , V_214 , V_114 ) ;
if ( ! V_184 )
goto V_213;
V_185 = V_184 ;
V_183 = V_185 + strlen ( V_185 ) ;
if ( strncmp ( V_185 , L_35 , 4 ) == 0 ) {
if ( V_185 [ 4 ] != 0 ) {
V_189 [ 0 ] = V_185 [ 4 ] ;
V_185 += 5 ;
} else {
F_5 ( 1 , L_36 ) ;
}
}
V_142 -> V_215 = false ;
V_142 -> V_216 = false ;
while ( ( V_182 = F_87 ( & V_185 , V_189 ) ) != NULL ) {
T_2 args [ V_143 ] ;
unsigned long V_139 ;
int V_217 ;
if ( ! * V_182 )
continue;
V_217 = F_77 ( V_182 , V_218 , args ) ;
switch ( V_217 ) {
case V_219 :
break;
case V_220 :
V_142 -> V_221 = 0 ;
break;
case V_222 :
V_142 -> V_221 = 1 ;
break;
case V_223 :
V_190 = 1 ;
break;
case V_224 :
V_190 = 0 ;
break;
case V_225 :
V_191 = 1 ;
break;
case V_226 :
V_191 = 0 ;
break;
case V_227 :
V_142 -> V_228 = 1 ;
break;
case V_229 :
V_142 -> V_230 = 1 ;
break;
case V_231 :
V_142 -> V_232 = 1 ;
break;
case V_233 :
V_142 -> V_232 = 0 ;
break;
case V_234 :
V_142 -> V_235 = 0 ;
break;
case V_236 :
V_142 -> V_235 = 1 ;
break;
case V_237 :
V_142 -> V_238 = 1 ;
break;
case V_239 :
V_142 -> V_238 = 0 ;
break;
case V_240 :
V_142 -> V_241 = 1 ;
break;
case V_242 :
V_142 -> V_241 = 0 ;
break;
case V_243 :
V_142 -> V_244 = 1 ;
break;
case V_245 :
V_142 -> V_209 = 1 ;
break;
case V_246 :
V_142 -> V_209 = 0 ;
break;
case V_247 :
V_142 -> V_248 = 1 ;
break;
case V_249 :
V_142 -> V_250 = 1 ;
break;
case V_251 :
V_142 -> V_252 = 0 ;
break;
case V_253 :
V_142 -> V_252 = 1 ;
if ( V_142 -> V_205 ==
( V_254 & ~ ( V_255 | V_256 ) ) )
V_142 -> V_205 = V_254 ;
break;
case V_257 :
V_142 -> V_258 = 1 ;
break;
case V_259 :
V_142 -> V_260 = 1 ;
break;
case V_261 :
V_142 -> V_260 = 0 ;
break;
case V_262 :
V_142 -> V_263 = true ;
break;
case V_264 :
V_142 -> V_263 = false ;
break;
case V_265 :
V_142 -> V_232 = 0 ;
break;
case V_266 :
V_142 -> V_232 = 1 ;
break;
case V_267 :
V_142 -> V_268 = 0 ;
break;
case V_269 :
V_142 -> V_268 = 1 ;
break;
case V_270 :
V_142 -> V_271 = 1 ;
break;
case V_272 :
V_142 -> V_271 = 0 ;
break;
case V_273 :
V_142 -> V_210 = 1 ;
break;
case V_274 :
V_142 -> V_210 = 0 ;
break;
case V_275 :
V_142 -> V_276 = 1 ;
break;
case V_277 :
V_142 -> V_278 = 1 ;
break;
case V_279 :
V_142 -> V_278 = 0 ;
break;
case V_280 :
V_142 -> V_281 = 0 ;
break;
case V_282 :
V_142 -> V_281 = 1 ;
break;
case V_283 :
V_142 -> V_284 = 1 ;
break;
case V_285 :
V_142 -> V_146 |= V_149 ;
break;
case V_286 :
V_142 -> V_287 = 1 ;
break;
case V_288 :
F_88 ( V_289 L_37
L_38
L_39 ) ;
break;
case V_290 :
#ifndef F_89
F_27 ( 1 , L_40
L_41 ) ;
goto V_213;
#endif
V_142 -> V_291 = true ;
break;
case V_292 :
V_142 -> V_293 = true ;
break;
case V_294 :
V_142 -> V_295 = true ;
break;
case V_296 :
V_194 = true ;
break;
case V_297 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_42 ,
V_20 ) ;
goto V_213;
}
V_142 -> V_298 = V_139 ;
V_142 -> V_215 = true ;
break;
case V_299 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_43 ,
V_20 ) ;
goto V_213;
}
V_142 -> V_300 = V_139 ;
V_142 -> V_216 = true ;
break;
case V_301 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_44 ,
V_20 ) ;
goto V_213;
}
V_142 -> V_202 = V_139 ;
V_192 = true ;
break;
case V_302 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_45 ,
V_20 ) ;
goto V_213;
}
V_142 -> V_201 = V_139 ;
break;
case V_303 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_46 ,
V_20 ) ;
goto V_213;
}
V_142 -> V_203 = V_139 ;
V_193 = true ;
break;
case V_304 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_47 ,
V_20 ) ;
goto V_213;
}
V_142 -> V_205 = V_139 ;
break;
case V_305 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_48 ,
V_20 ) ;
goto V_213;
}
V_142 -> V_204 = V_139 ;
break;
case V_306 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_49 ,
V_20 ) ;
goto V_213;
}
V_142 -> V_307 = V_139 ;
break;
case V_308 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_50 ,
V_20 ) ;
goto V_213;
}
V_142 -> V_309 = V_139 ;
break;
case V_310 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_51 ,
V_20 ) ;
goto V_213;
}
V_142 -> V_311 = V_139 ;
break;
case V_312 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_52 ,
V_20 ) ;
goto V_213;
}
V_142 -> V_211 = V_52 * V_139 ;
if ( V_142 -> V_211 > V_313 ) {
F_27 ( 1 , L_53
L_54 ) ;
goto V_213;
}
break;
case V_314 :
V_142 -> V_163 = 1 ;
V_142 -> V_315 = NULL ;
break;
case V_316 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
if ( F_83 ( string , V_318 ) >
V_318 ) {
F_88 ( V_289 L_55 ) ;
goto V_213;
}
V_142 -> V_315 = F_90 ( string , V_114 ) ;
if ( ! V_142 -> V_315 ) {
F_88 ( V_289 L_56
L_57 ) ;
goto V_213;
}
break;
case V_319 :
V_142 -> V_320 = NULL ;
break;
case V_321 :
V_140 = strchr ( V_182 , '=' ) ;
V_140 ++ ;
V_197 = ( char * ) V_140 + strlen ( V_140 ) ;
if ( V_197 < V_183 && V_197 [ 1 ] == V_137 ) {
V_197 [ 0 ] = V_137 ;
while ( ( V_197 = strchr ( V_197 , V_137 ) )
!= NULL && ( V_197 [ 1 ] == V_137 ) ) {
V_197 = ( char * ) & V_197 [ 2 ] ;
}
if ( V_197 ) {
V_197 [ 0 ] = '\0' ;
V_185 = ( char * ) & V_197 [ 1 ] ;
} else
V_185 = V_183 ;
}
V_186 = strlen ( V_140 ) ;
V_142 -> V_320 = F_91 ( V_186 + 1 , V_114 ) ;
if ( V_142 -> V_320 == NULL ) {
F_88 ( V_289 L_56
L_58 ) ;
goto V_213;
}
for ( V_187 = 0 , V_188 = 0 ; V_187 < V_186 ; V_187 ++ , V_188 ++ ) {
V_142 -> V_320 [ V_188 ] = V_140 [ V_187 ] ;
if ( ( V_140 [ V_187 ] == V_137 ) &&
V_140 [ V_187 + 1 ] == V_137 )
V_187 ++ ;
}
V_142 -> V_320 [ V_188 ] = '\0' ;
break;
case V_322 :
V_142 -> V_323 = NULL ;
break;
case V_324 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
if ( F_83 ( string , V_325 ) >
V_325 ) {
F_88 ( V_289 L_59
L_60 ) ;
goto V_213;
}
V_142 -> V_323 = F_90 ( string , V_114 ) ;
if ( ! V_142 -> V_323 ) {
F_88 ( V_289 L_56
L_61 ) ;
goto V_213;
}
break;
case V_326 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
V_186 = F_83 ( string , 300 ) ;
if ( V_186 == 300 ) {
F_88 ( V_289 L_62 ) ;
goto V_213;
}
V_142 -> V_327 = F_36 ( V_186 + 1 , V_114 ) ;
if ( V_142 -> V_327 == NULL ) {
F_88 ( V_289 L_63 ) ;
goto V_213;
}
strcpy ( V_142 -> V_327 , string ) ;
if ( strncmp ( string , L_64 , 2 ) == 0 ) {
V_142 -> V_327 [ 0 ] = '\\' ;
V_142 -> V_327 [ 1 ] = '\\' ;
} else if ( strncmp ( string , L_65 , 2 ) != 0 ) {
F_88 ( V_289 L_66
L_67 ) ;
goto V_213;
}
break;
case V_328 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
if ( F_83 ( string , 256 ) == 256 ) {
F_88 ( V_289 L_68
L_69 ) ;
goto V_213;
}
V_142 -> V_329 = F_90 ( string , V_114 ) ;
if ( ! V_142 -> V_329 ) {
F_88 ( V_289 L_56
L_70 ) ;
goto V_213;
}
F_5 ( 1 , L_71 ) ;
break;
case V_330 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
if ( ! F_92 (
(struct V_93 * ) & V_142 -> V_331 ,
string , strlen ( string ) ) ) {
F_88 ( V_289 L_72
L_73 , string ) ;
goto V_213;
}
break;
case V_332 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
V_186 = F_83 ( string , 1024 ) ;
if ( string [ 0 ] != '/' )
V_186 ++ ;
if ( V_186 > 1024 ) {
F_88 ( V_289 L_74 ) ;
goto V_213;
}
V_142 -> V_333 = F_36 ( V_186 + 1 , V_114 ) ;
if ( V_142 -> V_333 == NULL ) {
F_88 ( V_289 L_56
L_75 ) ;
goto V_213;
}
if ( string [ 0 ] != '/' ) {
V_142 -> V_333 [ 0 ] = '/' ;
strcpy ( V_142 -> V_333 + 1 , string ) ;
} else
strcpy ( V_142 -> V_333 , string ) ;
break;
case V_334 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
if ( F_83 ( string , 1024 ) >= 65 ) {
F_88 ( V_289 L_76
L_77 ) ;
goto V_213;
}
if ( F_93 ( string , L_78 , 7 ) != 0 ) {
V_142 -> V_335 = F_90 ( string ,
V_114 ) ;
if ( ! V_142 -> V_335 ) {
F_88 ( V_289 L_79
L_80 ) ;
goto V_213;
}
}
F_5 ( 1 , L_81 , string ) ;
break;
case V_336 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
if ( F_93 ( string , L_82 , 11 ) == 0 ) {
F_88 ( V_289 L_83
L_84
L_85
L_86 ) ;
V_142 -> V_337 = 1 ;
}
break;
case V_338 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
memset ( V_142 -> V_198 , 0x20 ,
V_199 ) ;
for ( V_187 = 0 ; V_187 < V_199 ; V_187 ++ ) {
if ( string [ V_187 ] == 0 )
break;
V_142 -> V_198 [ V_187 ] = string [ V_187 ] ;
}
if ( V_187 == V_199 && string [ V_187 ] != 0 )
F_88 ( V_289 L_87
L_88 ) ;
break;
case V_339 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
memset ( V_142 -> V_200 , 0x20 ,
V_340 ) ;
for ( V_187 = 0 ; V_187 < 15 ; V_187 ++ ) {
if ( string [ V_187 ] == 0 )
break;
V_142 -> V_200 [ V_187 ] = string [ V_187 ] ;
}
if ( V_187 == V_199 && string [ V_187 ] != 0 )
F_88 ( V_289 L_89
L_90 ) ;
break;
case V_341 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
if ( F_93 ( string , L_91 , 1 ) == 0 ) {
break;
}
F_88 ( V_289 L_92
L_93 ) ;
goto V_213;
case V_342 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
if ( F_80 ( string , V_142 ) != 0 )
goto V_213;
break;
case V_343 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
if ( F_76 ( string , V_142 ) != 0 )
goto V_213;
break;
case V_344 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_317;
if ( F_79 ( string , V_142 ) != 0 )
goto V_213;
break;
default:
if ( ! V_195 )
V_195 = V_182 ;
break;
}
F_11 ( string ) ;
string = NULL ;
}
if ( ! V_194 && V_195 ) {
F_88 ( V_345 L_94 , V_195 ) ;
goto V_213;
}
#ifndef F_94
if ( V_142 -> V_295 ) {
F_27 ( 1 , L_95
L_96 ) ;
goto V_213;
}
#endif
if ( V_142 -> V_323 == NULL )
V_142 -> V_323 = & V_142 -> V_327 [ 2 ] ;
if ( V_192 )
V_142 -> V_190 = V_190 ;
else if ( V_190 == 1 )
F_88 ( V_346 L_97
L_98 ) ;
if ( V_193 )
V_142 -> V_191 = V_191 ;
else if ( V_191 == 1 )
F_88 ( V_346 L_99
L_100 ) ;
F_11 ( V_184 ) ;
return 0 ;
V_317:
F_88 ( V_289 L_101 ) ;
V_213:
F_11 ( string ) ;
F_11 ( V_184 ) ;
return 1 ;
}
static bool
F_95 ( struct V_93 * V_331 , struct V_93 * V_347 )
{
switch ( V_331 -> V_348 ) {
case V_349 :
return ( V_347 -> V_348 == V_349 ) ;
case V_350 : {
struct V_351 * V_352 = (struct V_351 * ) V_331 ;
struct V_351 * V_353 = (struct V_351 * ) V_347 ;
return ( V_352 -> V_354 . V_355 == V_353 -> V_354 . V_355 ) ;
}
case V_356 : {
struct V_357 * V_358 = (struct V_357 * ) V_331 ;
struct V_357 * V_359 = (struct V_357 * ) & V_347 ;
return F_96 ( & V_358 -> V_360 , & V_359 -> V_360 ) ;
}
default:
F_97 ( 1 ) ;
return false ;
}
}
static bool
F_98 ( struct V_1 * V_2 , struct V_93 * V_361 )
{
T_3 V_307 , * V_362 ;
switch ( V_361 -> V_348 ) {
case V_350 :
V_362 = & ( (struct V_351 * ) & V_2 -> V_94 ) -> V_363 ;
V_307 = ( (struct V_351 * ) V_361 ) -> V_363 ;
break;
case V_356 :
V_362 = & ( (struct V_357 * ) & V_2 -> V_94 ) -> V_364 ;
V_307 = ( (struct V_357 * ) V_361 ) -> V_364 ;
break;
default:
F_97 ( 1 ) ;
return false ;
}
if ( ! V_307 ) {
V_307 = F_99 ( V_95 ) ;
if ( V_307 == * V_362 )
return true ;
V_307 = F_99 ( V_365 ) ;
}
return V_307 == * V_362 ;
}
static bool
F_100 ( struct V_1 * V_2 , struct V_93 * V_361 ,
struct V_93 * V_331 )
{
switch ( V_361 -> V_348 ) {
case V_350 : {
struct V_351 * V_366 = (struct V_351 * ) V_361 ;
struct V_351 * V_367 =
(struct V_351 * ) & V_2 -> V_94 ;
if ( V_366 -> V_354 . V_355 != V_367 -> V_354 . V_355 )
return false ;
break;
}
case V_356 : {
struct V_357 * V_368 = (struct V_357 * ) V_361 ;
struct V_357 * V_369 =
(struct V_357 * ) & V_2 -> V_94 ;
if ( ! F_96 ( & V_368 -> V_360 ,
& V_369 -> V_360 ) )
return false ;
if ( V_368 -> V_370 != V_369 -> V_370 )
return false ;
break;
}
default:
F_97 ( 1 ) ;
return false ;
}
if ( ! F_95 ( V_331 , (struct V_93 * ) & V_2 -> V_331 ) )
return false ;
return true ;
}
static bool
F_101 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
unsigned int V_371 ;
if ( V_142 -> V_146 & ( ~ ( V_149 | V_372 ) ) )
V_371 = V_142 -> V_146 ;
else
V_371 = V_373 | V_142 -> V_146 ;
switch ( V_2 -> V_374 ) {
case V_375 :
if ( ! ( V_371 & ( V_161 | V_376 ) ) )
return false ;
break;
case V_377 :
if ( ! ( V_371 & V_158 ) )
return false ;
break;
case V_378 :
if ( ! ( V_371 & V_155 ) )
return false ;
break;
case V_379 :
if ( ! ( V_371 & V_147 ) )
return false ;
break;
case V_380 :
if ( ! ( V_371 & V_152 ) )
return false ;
break;
default:
return false ;
}
if ( ( V_371 & V_381 ) == 0 &&
( V_2 -> V_382 & V_383 ) )
return false ;
else if ( ( ( V_371 & V_149 ) == V_149 ) &&
( V_2 -> V_382 &
( V_384 | V_383 ) ) == 0 )
return false ;
return true ;
}
static int F_102 ( struct V_1 * V_2 , struct V_93 * V_361 ,
struct V_141 * V_142 )
{
if ( ( V_2 -> V_173 != V_142 -> V_173 ) || ( V_2 -> V_48 != V_142 -> V_48 ) )
return 0 ;
if ( ! F_103 ( F_104 ( V_2 ) , V_123 -> V_385 -> V_386 ) )
return 0 ;
if ( ! F_100 ( V_2 , V_361 ,
(struct V_93 * ) & V_142 -> V_331 ) )
return 0 ;
if ( ! F_98 ( V_2 , V_361 ) )
return 0 ;
if ( ! F_101 ( V_2 , V_142 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_105 ( struct V_93 * V_361 , struct V_141 * V_142 )
{
struct V_1 * V_2 ;
F_2 ( & V_21 ) ;
F_106 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_102 ( V_2 , V_361 , V_142 ) )
continue;
++ V_2 -> V_387 ;
F_3 ( & V_21 ) ;
F_5 ( 1 , L_102 ) ;
return V_2 ;
}
F_3 ( & V_21 ) ;
return NULL ;
}
static void
F_107 ( struct V_1 * V_2 )
{
struct V_121 * V_388 ;
F_2 ( & V_21 ) ;
if ( -- V_2 -> V_387 > 0 ) {
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
V_388 = F_66 ( & V_2 -> V_131 , NULL ) ;
if ( V_388 )
F_112 ( V_389 , V_388 ) ;
}
static struct V_1 *
F_113 ( struct V_141 * V_390 )
{
struct V_1 * V_391 = NULL ;
struct V_392 V_361 ;
struct V_351 * V_393 = (struct V_351 * ) & V_361 ;
struct V_357 * V_394 = (struct V_357 * ) & V_361 ;
int V_3 ;
memset ( & V_361 , 0 , sizeof( struct V_392 ) ) ;
F_5 ( 1 , L_103 , V_390 -> V_327 , V_390 -> V_323 ) ;
if ( V_390 -> V_323 && V_390 -> V_327 ) {
V_3 = F_114 ( (struct V_93 * ) & V_361 ,
V_390 -> V_323 ,
strlen ( V_390 -> V_323 ) ,
V_390 -> V_307 ) ;
if ( ! V_3 ) {
V_3 = - V_138 ;
goto V_395;
}
} else if ( V_390 -> V_323 ) {
F_27 ( 1 , L_104 ) ;
V_3 = - V_138 ;
goto V_395;
} else {
F_27 ( 1 , L_105
L_106 ) ;
V_3 = - V_138 ;
goto V_395;
}
V_391 = F_105 ( (struct V_93 * ) & V_361 , V_390 ) ;
if ( V_391 )
return V_391 ;
V_391 = F_91 ( sizeof( struct V_1 ) , V_114 ) ;
if ( ! V_391 ) {
V_3 = - V_81 ;
goto V_395;
}
V_3 = F_115 ( V_391 ) ;
if ( V_3 ) {
F_27 ( 1 , L_107 , V_3 ) ;
goto V_395;
}
V_391 -> V_48 = V_390 -> V_48 ;
V_391 -> V_173 = V_390 -> V_173 ;
F_116 ( V_391 , F_117 ( V_123 -> V_385 -> V_386 ) ) ;
V_391 -> V_55 = F_71 ( V_390 -> V_327 ) ;
if ( F_118 ( V_391 -> V_55 ) ) {
V_3 = F_119 ( V_391 -> V_55 ) ;
goto V_396;
}
V_391 -> V_228 = V_390 -> V_228 ;
V_391 -> V_230 = V_390 -> V_230 ;
V_391 -> V_397 = V_390 -> V_337 ;
V_391 -> V_398 = 0 ;
V_391 -> V_106 = 1 ;
F_120 ( & V_391 -> V_61 ) ;
F_120 ( & V_391 -> V_107 ) ;
F_13 ( & V_391 -> V_108 ) ;
F_121 ( & V_391 -> V_26 ) ;
memcpy ( V_391 -> V_399 ,
V_390 -> V_198 , V_340 ) ;
memcpy ( V_391 -> V_400 ,
V_390 -> V_200 , V_340 ) ;
V_391 -> V_32 = false ;
V_391 -> V_31 = 0 ;
V_391 -> V_36 = V_37 ;
F_122 ( & V_391 -> V_105 ) ;
F_13 ( & V_391 -> V_104 ) ;
F_13 ( & V_391 -> V_22 ) ;
F_123 ( & V_391 -> V_47 , F_21 ) ;
V_391 -> V_15 = V_401 ;
memcpy ( & V_391 -> V_331 , & V_390 -> V_331 ,
sizeof( V_391 -> V_331 ) ) ;
++ V_391 -> V_387 ;
if ( V_361 . V_402 == V_356 ) {
F_5 ( 1 , L_108 ) ;
memcpy ( & V_391 -> V_94 , V_394 ,
sizeof( struct V_357 ) ) ;
} else
memcpy ( & V_391 -> V_94 , V_393 ,
sizeof( struct V_351 ) ) ;
V_3 = F_124 ( V_391 ) ;
if ( V_3 < 0 ) {
F_27 ( 1 , L_109 ) ;
goto V_396;
}
F_125 ( V_403 ) ;
V_391 -> V_131 = F_126 ( F_57 ,
V_391 , L_110 ) ;
if ( F_118 ( V_391 -> V_131 ) ) {
V_3 = F_119 ( V_391 -> V_131 ) ;
F_27 ( 1 , L_111 , V_3 ) ;
F_127 ( V_403 ) ;
goto V_396;
}
V_391 -> V_15 = V_44 ;
F_2 ( & V_21 ) ;
F_128 ( & V_391 -> V_104 , & V_404 ) ;
F_3 ( & V_21 ) ;
F_129 ( V_391 ) ;
F_24 ( V_56 , & V_391 -> V_47 , V_51 ) ;
return V_391 ;
V_396:
F_110 ( V_391 ) ;
F_108 ( F_104 ( V_391 ) ) ;
V_395:
if ( V_391 ) {
if ( ! F_118 ( V_391 -> V_55 ) )
F_11 ( V_391 -> V_55 ) ;
if ( V_391 -> V_27 )
F_10 ( V_391 -> V_27 ) ;
F_11 ( V_391 ) ;
}
return F_72 ( V_3 ) ;
}
static int F_130 ( struct V_7 * V_8 , struct V_141 * V_142 )
{
switch ( V_8 -> V_2 -> V_374 ) {
case V_379 :
if ( V_142 -> V_201 != V_8 -> V_201 )
return 0 ;
break;
default:
if ( V_8 -> V_405 == NULL ) {
if ( ! V_142 -> V_163 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_405 ,
V_142 -> V_315 ? V_142 -> V_315 : L_112 ,
V_318 ) )
return 0 ;
if ( strlen ( V_142 -> V_315 ) != 0 &&
V_8 -> V_320 != NULL &&
strncmp ( V_8 -> V_320 ,
V_142 -> V_320 ? V_142 -> V_320 : L_112 ,
V_406 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_131 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
struct V_7 * V_8 ;
F_2 ( & V_21 ) ;
F_106 (ses, &server->smb_ses_list, smb_ses_list) {
if ( ! F_130 ( V_8 , V_142 ) )
continue;
++ V_8 -> V_407 ;
F_3 ( & V_21 ) ;
return V_8 ;
}
F_3 ( & V_21 ) ;
return NULL ;
}
static void
F_132 ( struct V_7 * V_8 )
{
unsigned int V_408 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( 1 , L_113 , V_20 , V_8 -> V_407 ) ;
F_2 ( & V_21 ) ;
if ( -- V_8 -> V_407 > 0 ) {
F_3 ( & V_21 ) ;
return;
}
F_16 ( & V_8 -> V_22 ) ;
F_3 ( & V_21 ) ;
if ( V_8 -> V_409 == V_60 && V_2 -> V_48 -> V_410 ) {
V_408 = F_133 () ;
V_2 -> V_48 -> V_410 ( V_408 , V_8 ) ;
F_134 ( V_408 ) ;
}
F_135 ( V_8 ) ;
F_107 ( V_2 ) ;
}
static int
F_136 ( struct V_141 * V_142 , struct V_7 * V_8 )
{
int V_3 = 0 ;
char * V_411 , * V_137 , * V_412 ;
T_4 V_35 ;
struct V_413 * V_413 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_351 * V_414 ;
struct V_357 * V_415 ;
struct V_416 * V_417 ;
V_411 = F_36 ( V_418 , V_114 ) ;
if ( ! V_411 )
return - V_81 ;
switch ( V_2 -> V_94 . V_402 ) {
case V_350 :
V_414 = (struct V_351 * ) & V_2 -> V_94 ;
sprintf ( V_411 , L_114 , & V_414 -> V_354 . V_355 ) ;
break;
case V_356 :
V_415 = (struct V_357 * ) & V_2 -> V_94 ;
sprintf ( V_411 , L_115 , & V_415 -> V_360 . V_419 ) ;
break;
default:
F_5 ( 1 , L_116 , V_2 -> V_94 . V_402 ) ;
V_3 = - V_138 ;
goto V_395;
}
F_5 ( 1 , L_117 , V_20 , V_411 ) ;
V_413 = F_137 ( & V_420 , V_411 , L_112 ) ;
if ( F_118 ( V_413 ) ) {
if ( ! V_8 -> V_421 ) {
F_5 ( 1 , L_118 ) ;
V_3 = F_119 ( V_413 ) ;
goto V_395;
}
sprintf ( V_411 , L_119 , V_8 -> V_421 ) ;
F_5 ( 1 , L_117 , V_20 , V_411 ) ;
V_413 = F_137 ( & V_420 , V_411 , L_112 ) ;
if ( F_118 ( V_413 ) ) {
V_3 = F_119 ( V_413 ) ;
goto V_395;
}
}
F_138 ( & V_413 -> V_422 ) ;
V_417 = V_413 -> V_412 . V_182 ;
if ( F_139 ( V_417 ) ) {
V_3 = V_417 ? F_119 ( V_417 ) : - V_138 ;
goto V_423;
}
V_412 = ( char * ) V_417 -> V_182 ;
V_137 = F_140 ( V_412 , V_417 -> V_424 , ':' ) ;
F_5 ( 1 , L_120 , V_412 ) ;
if ( ! V_137 ) {
F_5 ( 1 , L_121 ,
V_417 -> V_424 ) ;
V_3 = - V_138 ;
goto V_423;
}
V_35 = V_137 - V_412 ;
if ( V_35 > V_318 || V_35 <= 0 ) {
F_5 ( 1 , L_122 , V_35 ) ;
V_3 = - V_138 ;
goto V_423;
}
V_142 -> V_315 = F_86 ( V_412 , V_35 , V_114 ) ;
if ( ! V_142 -> V_315 ) {
F_5 ( 1 , L_123 , V_35 ) ;
V_3 = - V_81 ;
goto V_423;
}
F_5 ( 1 , L_124 , V_20 , V_142 -> V_315 ) ;
V_35 = V_413 -> V_424 - ( V_35 + 1 ) ;
if ( V_35 > V_406 || V_35 <= 0 ) {
F_5 ( 1 , L_125 , V_35 ) ;
V_3 = - V_138 ;
F_11 ( V_142 -> V_315 ) ;
V_142 -> V_315 = NULL ;
goto V_423;
}
++ V_137 ;
V_142 -> V_320 = F_86 ( V_137 , V_35 , V_114 ) ;
if ( ! V_142 -> V_320 ) {
F_5 ( 1 , L_126 , V_35 ) ;
V_3 = - V_81 ;
F_11 ( V_142 -> V_315 ) ;
V_142 -> V_315 = NULL ;
goto V_423;
}
V_423:
F_141 ( & V_413 -> V_422 ) ;
F_142 ( V_413 ) ;
V_395:
F_11 ( V_411 ) ;
F_5 ( 1 , L_127 , V_20 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_143 ( struct V_1 * V_2 , struct V_141 * V_390 )
{
int V_3 = - V_81 ;
unsigned int V_408 ;
struct V_7 * V_8 ;
struct V_351 * V_361 = (struct V_351 * ) & V_2 -> V_94 ;
struct V_357 * V_368 = (struct V_357 * ) & V_2 -> V_94 ;
V_408 = F_133 () ;
V_8 = F_131 ( V_2 , V_390 ) ;
if ( V_8 ) {
F_5 ( 1 , L_128 , V_8 -> V_409 ) ;
F_8 ( & V_8 -> V_425 ) ;
V_3 = F_144 ( V_408 , V_8 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_425 ) ;
F_132 ( V_8 ) ;
F_145 ( V_408 ) ;
return F_72 ( V_3 ) ;
}
if ( V_8 -> V_23 ) {
F_5 ( 1 , L_129 ) ;
V_3 = F_146 ( V_408 , V_8 ,
V_390 -> V_426 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_425 ) ;
F_132 ( V_8 ) ;
F_145 ( V_408 ) ;
return F_72 ( V_3 ) ;
}
}
F_12 ( & V_8 -> V_425 ) ;
F_107 ( V_2 ) ;
F_145 ( V_408 ) ;
return V_8 ;
}
F_5 ( 1 , L_130 ) ;
V_8 = F_147 () ;
if ( V_8 == NULL )
goto V_427;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_94 . V_402 == V_356 )
sprintf ( V_8 -> V_428 , L_131 , & V_368 -> V_360 ) ;
else
sprintf ( V_8 -> V_428 , L_132 , & V_361 -> V_354 ) ;
if ( V_390 -> V_315 ) {
V_8 -> V_405 = F_90 ( V_390 -> V_315 , V_114 ) ;
if ( ! V_8 -> V_405 )
goto V_427;
}
if ( V_390 -> V_320 ) {
V_8 -> V_320 = F_90 ( V_390 -> V_320 , V_114 ) ;
if ( ! V_8 -> V_320 )
goto V_427;
}
if ( V_390 -> V_329 ) {
V_8 -> V_421 = F_90 ( V_390 -> V_329 , V_114 ) ;
if ( ! V_8 -> V_421 )
goto V_427;
}
V_8 -> V_201 = V_390 -> V_201 ;
V_8 -> V_202 = V_390 -> V_202 ;
if ( ( V_390 -> V_146 == 0 ) && V_429 == false ) {
V_429 = true ;
F_27 ( 1 , L_133
L_134
L_135 ) ;
}
V_8 -> V_430 = V_390 -> V_146 ;
F_8 ( & V_8 -> V_425 ) ;
V_3 = F_144 ( V_408 , V_8 ) ;
if ( ! V_3 )
V_3 = F_146 ( V_408 , V_8 , V_390 -> V_426 ) ;
F_12 ( & V_8 -> V_425 ) ;
if ( V_3 )
goto V_427;
F_2 ( & V_21 ) ;
F_128 ( & V_8 -> V_22 , & V_2 -> V_22 ) ;
F_3 ( & V_21 ) ;
F_145 ( V_408 ) ;
return V_8 ;
V_427:
F_135 ( V_8 ) ;
F_145 ( V_408 ) ;
return F_72 ( V_3 ) ;
}
static int F_148 ( struct V_9 * V_10 , const char * V_134 )
{
if ( V_10 -> V_431 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_432 , V_134 , V_433 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_149 ( struct V_7 * V_8 , const char * V_134 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_21 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_25 ) ;
if ( ! F_148 ( V_10 , V_134 ) )
continue;
++ V_10 -> V_434 ;
F_3 ( & V_21 ) ;
return V_10 ;
}
F_3 ( & V_21 ) ;
return NULL ;
}
static void
F_150 ( struct V_9 * V_10 )
{
unsigned int V_408 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( 1 , L_136 , V_20 , V_10 -> V_434 ) ;
F_2 ( & V_21 ) ;
if ( -- V_10 -> V_434 > 0 ) {
F_3 ( & V_21 ) ;
return;
}
F_16 ( & V_10 -> V_25 ) ;
F_3 ( & V_21 ) ;
V_408 = F_133 () ;
if ( V_8 -> V_2 -> V_48 -> V_435 )
V_8 -> V_2 -> V_48 -> V_435 ( V_408 , V_10 ) ;
F_134 ( V_408 ) ;
F_151 ( V_10 ) ;
F_152 ( V_10 ) ;
F_132 ( V_8 ) ;
}
static struct V_9 *
F_153 ( struct V_7 * V_8 , struct V_141 * V_390 )
{
int V_3 , V_408 ;
struct V_9 * V_10 ;
V_10 = F_149 ( V_8 , V_390 -> V_327 ) ;
if ( V_10 ) {
F_5 ( 1 , L_137 ) ;
F_132 ( V_8 ) ;
if ( V_10 -> V_287 != V_390 -> V_287 )
F_27 ( 1 , L_138
L_139 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_48 -> V_436 ) {
V_3 = - V_54 ;
goto V_437;
}
V_10 = F_154 () ;
if ( V_10 == NULL ) {
V_3 = - V_81 ;
goto V_437;
}
V_10 -> V_8 = V_8 ;
if ( V_390 -> V_320 ) {
V_10 -> V_320 = F_90 ( V_390 -> V_320 , V_114 ) ;
if ( ! V_10 -> V_320 ) {
V_3 = - V_81 ;
goto V_437;
}
}
if ( strchr ( V_390 -> V_327 + 3 , '\\' ) == NULL
&& strchr ( V_390 -> V_327 + 3 , '/' ) == NULL ) {
F_27 ( 1 , L_140 ) ;
V_3 = - V_438 ;
goto V_437;
}
V_408 = F_133 () ;
V_3 = V_8 -> V_2 -> V_48 -> V_436 ( V_408 , V_8 , V_390 -> V_327 , V_10 ,
V_390 -> V_426 ) ;
F_145 ( V_408 ) ;
F_5 ( 1 , L_141 , V_3 ) ;
if ( V_3 )
goto V_437;
if ( V_390 -> V_244 ) {
V_10 -> V_439 &= ~ V_440 ;
F_5 ( 1 , L_142 , V_10 -> V_439 ) ;
}
V_10 -> V_287 = V_390 -> V_287 ;
V_10 -> V_232 = V_390 -> V_232 ;
V_10 -> V_250 = V_390 -> V_250 ;
V_10 -> V_284 = V_390 -> V_284 ;
F_13 ( & V_10 -> V_441 ) ;
F_2 ( & V_21 ) ;
F_128 ( & V_10 -> V_25 , & V_8 -> V_25 ) ;
F_3 ( & V_21 ) ;
F_155 ( V_10 ) ;
return V_10 ;
V_437:
F_152 ( V_10 ) ;
return F_72 ( V_3 ) ;
}
void
F_156 ( struct V_442 * V_443 )
{
if ( ! V_443 || F_118 ( V_443 ) )
return;
if ( ! F_157 ( & V_443 -> V_444 ) ||
F_158 ( V_445 , & V_443 -> V_446 ) ) {
V_443 -> V_447 = V_37 ;
return;
}
if ( ! F_118 ( F_159 ( V_443 ) ) )
F_150 ( F_159 ( V_443 ) ) ;
F_11 ( V_443 ) ;
return;
}
static inline struct V_442 *
F_160 ( struct V_448 * V_449 )
{
return V_449 -> V_450 ;
}
static int
F_161 ( struct V_451 * V_452 , struct V_453 * V_454 )
{
struct V_448 * V_455 = F_162 ( V_452 ) ;
struct V_448 * V_63 = V_454 -> V_449 ;
if ( ( V_452 -> V_456 & V_457 ) != ( V_454 -> V_29 & V_457 ) )
return 0 ;
if ( ( V_455 -> V_458 & V_459 ) !=
( V_63 -> V_458 & V_459 ) )
return 0 ;
if ( V_63 -> V_311 && V_63 -> V_311 < V_455 -> V_311 )
return 0 ;
if ( V_63 -> V_309 && V_63 -> V_309 < V_455 -> V_309 )
return 0 ;
if ( V_455 -> V_460 != V_63 -> V_460 || V_455 -> V_461 != V_63 -> V_461 )
return 0 ;
if ( V_455 -> V_462 != V_63 -> V_462 ||
V_455 -> V_463 != V_63 -> V_463 )
return 0 ;
if ( strcmp ( V_455 -> V_426 -> V_464 , V_63 -> V_426 -> V_464 ) )
return 0 ;
if ( V_455 -> V_211 != V_63 -> V_211 )
return 0 ;
return 1 ;
}
int
F_163 ( struct V_451 * V_452 , void * V_182 )
{
struct V_453 * V_454 = (struct V_453 * ) V_182 ;
struct V_141 * V_390 ;
struct V_448 * V_449 ;
struct V_1 * V_465 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_442 * V_443 ;
struct V_392 V_361 ;
int V_3 = 0 ;
memset ( & V_361 , 0 , sizeof( struct V_392 ) ) ;
F_2 ( & V_21 ) ;
V_449 = F_162 ( V_452 ) ;
V_443 = F_164 ( F_160 ( V_449 ) ) ;
if ( F_118 ( V_443 ) ) {
F_3 ( & V_21 ) ;
return V_3 ;
}
V_10 = F_159 ( V_443 ) ;
V_8 = V_10 -> V_8 ;
V_465 = V_8 -> V_2 ;
V_390 = V_454 -> V_142 ;
if ( ! V_390 -> V_323 || ! V_390 -> V_327 )
goto V_466;
V_3 = F_114 ( (struct V_93 * ) & V_361 ,
V_390 -> V_323 ,
strlen ( V_390 -> V_323 ) ,
V_390 -> V_307 ) ;
if ( ! V_3 )
goto V_466;
if ( ! F_102 ( V_465 , (struct V_93 * ) & V_361 , V_390 ) ||
! F_130 ( V_8 , V_390 ) ||
! F_148 ( V_10 , V_390 -> V_327 ) ) {
V_3 = 0 ;
goto V_466;
}
V_3 = F_161 ( V_452 , V_454 ) ;
V_466:
F_3 ( & V_21 ) ;
F_156 ( V_443 ) ;
return V_3 ;
}
int
F_165 ( const unsigned int V_408 , struct V_7 * V_8 , const char * V_467 ,
const struct V_468 * V_469 , unsigned int * V_470 ,
struct V_471 * * V_472 , int V_238 )
{
char * V_473 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_48 -> V_436 || ! V_8 -> V_2 -> V_48 -> V_474 )
return - V_54 ;
* V_470 = 0 ;
* V_472 = NULL ;
if ( V_8 -> V_24 == 0 ) {
V_473 = F_36 ( 2 +
F_83 ( V_8 -> V_428 , V_475 * 2 )
+ 1 + 4 + 2 , V_114 ) ;
if ( V_473 == NULL )
return - V_81 ;
V_473 [ 0 ] = '\\' ;
V_473 [ 1 ] = '\\' ;
strcpy ( V_473 + 2 , V_8 -> V_428 ) ;
strcpy ( V_473 + 2 + strlen ( V_8 -> V_428 ) , L_143 ) ;
V_3 = V_8 -> V_2 -> V_48 -> V_436 ( V_408 , V_8 , V_473 , NULL ,
V_469 ) ;
F_5 ( 1 , L_144 , V_3 , V_8 -> V_24 ) ;
F_11 ( V_473 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_48 -> V_474 ( V_408 , V_8 , V_467 ,
V_472 , V_470 ,
V_469 , V_238 ) ;
return V_3 ;
}
static inline void
F_166 ( struct V_476 * V_477 )
{
struct V_477 * V_478 = V_477 -> V_478 ;
F_167 ( F_168 ( V_478 ) ) ;
F_169 ( V_478 , L_145 ,
& V_479 [ 0 ] , L_146 , & V_480 [ 0 ] ) ;
}
static inline void
F_170 ( struct V_476 * V_477 )
{
struct V_477 * V_478 = V_477 -> V_478 ;
F_167 ( F_168 ( V_478 ) ) ;
F_169 ( V_478 , L_147 ,
& V_479 [ 1 ] , L_148 , & V_480 [ 1 ] ) ;
}
static inline void
F_166 ( struct V_476 * V_477 )
{
}
static inline void
F_170 ( struct V_476 * V_477 )
{
}
static void F_171 ( char * V_481 , char * V_482 , unsigned int V_76 )
{
unsigned int V_187 , V_188 ;
for ( V_187 = 0 , V_188 = 0 ; V_187 < ( V_76 ) ; V_187 ++ ) {
V_481 [ V_188 ] = 'A' + ( 0x0F & ( V_482 [ V_187 ] >> 4 ) ) ;
V_481 [ V_188 + 1 ] = 'A' + ( 0x0F & V_482 [ V_187 ] ) ;
V_188 += 2 ;
}
}
static int
F_172 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_331 . V_402 != V_349 ) {
struct V_476 * V_476 = V_2 -> V_27 ;
V_3 = V_476 -> V_48 -> V_483 ( V_476 ,
(struct V_93 * ) & V_2 -> V_331 ,
sizeof( V_2 -> V_331 ) ) ;
if ( V_3 < 0 ) {
struct V_351 * V_352 ;
struct V_357 * V_358 ;
V_352 = (struct V_351 * ) & V_2 -> V_331 ;
V_358 = (struct V_357 * ) & V_2 -> V_331 ;
if ( V_358 -> V_484 == V_356 )
F_27 ( 1 , L_149
L_150 ,
& V_358 -> V_360 , V_3 ) ;
else
F_27 ( 1 , L_149
L_151 ,
& V_352 -> V_354 . V_355 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_173 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_485 * V_486 ;
struct V_487 * V_488 ;
V_486 = F_91 ( sizeof( struct V_485 ) ,
V_114 ) ;
if ( V_486 ) {
V_486 -> V_489 . V_490 . V_491 = 32 ;
if ( V_2 -> V_400 &&
V_2 -> V_400 [ 0 ] != 0 )
F_171 ( V_486 -> V_489 .
V_490 . V_492 ,
V_2 -> V_400 ,
V_340 ) ;
else
F_171 ( V_486 -> V_489 .
V_490 . V_492 ,
V_493 ,
V_340 ) ;
V_486 -> V_489 . V_490 . V_494 = 32 ;
if ( V_2 -> V_399 &&
V_2 -> V_399 [ 0 ] != 0 )
F_171 ( V_486 -> V_489 .
V_490 . V_495 ,
V_2 -> V_399 ,
V_340 ) ;
else
F_171 ( V_486 -> V_489 .
V_490 . V_495 ,
L_152 ,
V_340 ) ;
V_486 -> V_489 . V_490 . V_496 = 0 ;
V_486 -> V_489 . V_490 . V_497 = 0 ;
V_488 = (struct V_487 * ) V_486 ;
V_488 -> V_498 = F_174 ( 0x81000044 ) ;
V_3 = F_175 ( V_2 , V_488 , 0x44 ) ;
F_11 ( V_486 ) ;
F_39 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_3 V_362 ;
int V_499 , V_500 ;
struct V_476 * V_476 = V_2 -> V_27 ;
struct V_93 * V_501 ;
V_501 = (struct V_93 * ) & V_2 -> V_94 ;
if ( V_2 -> V_94 . V_402 == V_356 ) {
V_362 = ( (struct V_357 * ) V_501 ) -> V_364 ;
V_499 = sizeof( struct V_357 ) ;
V_500 = V_356 ;
} else {
V_362 = ( (struct V_351 * ) V_501 ) -> V_363 ;
V_499 = sizeof( struct V_351 ) ;
V_500 = V_350 ;
}
if ( V_476 == NULL ) {
V_3 = F_176 ( F_104 ( V_2 ) , V_500 , V_502 ,
V_503 , & V_476 , 1 ) ;
if ( V_3 < 0 ) {
F_27 ( 1 , L_153 , V_3 ) ;
V_2 -> V_27 = NULL ;
return V_3 ;
}
F_5 ( 1 , L_154 ) ;
V_2 -> V_27 = V_476 ;
V_476 -> V_478 -> V_504 = V_73 ;
if ( V_500 == V_356 )
F_170 ( V_476 ) ;
else
F_166 ( V_476 ) ;
}
V_3 = F_172 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_476 -> V_478 -> V_505 = 7 * V_52 ;
V_476 -> V_478 -> V_506 = 5 * V_52 ;
if ( V_2 -> V_230 ) {
if ( V_476 -> V_478 -> V_507 < ( 200 * 1024 ) )
V_476 -> V_478 -> V_507 = 200 * 1024 ;
if ( V_476 -> V_478 -> V_508 < ( 140 * 1024 ) )
V_476 -> V_478 -> V_508 = 140 * 1024 ;
}
if ( V_2 -> V_397 ) {
int V_509 = 1 ;
V_3 = F_177 ( V_476 , V_510 , V_511 ,
( char * ) & V_509 , sizeof( V_509 ) ) ;
if ( V_3 )
F_5 ( 1 , L_155 , V_3 ) ;
}
F_5 ( 1 , L_156 ,
V_476 -> V_478 -> V_507 ,
V_476 -> V_478 -> V_508 , V_476 -> V_478 -> V_505 ) ;
V_3 = V_476 -> V_48 -> V_512 ( V_476 , V_501 , V_499 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( 1 , L_157 , V_3 ) ;
F_10 ( V_476 ) ;
V_2 -> V_27 = NULL ;
return V_3 ;
}
if ( V_362 == F_99 ( V_365 ) )
V_3 = F_173 ( V_2 ) ;
return V_3 ;
}
static int
F_124 ( struct V_1 * V_2 )
{
T_3 * V_362 ;
struct V_357 * V_368 = (struct V_357 * ) & V_2 -> V_94 ;
struct V_351 * V_361 = (struct V_351 * ) & V_2 -> V_94 ;
if ( V_2 -> V_94 . V_402 == V_356 )
V_362 = & V_368 -> V_364 ;
else
V_362 = & V_361 -> V_363 ;
if ( * V_362 == 0 ) {
int V_3 ;
* V_362 = F_99 ( V_95 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_362 = F_99 ( V_365 ) ;
}
return F_18 ( V_2 ) ;
}
void F_178 ( unsigned int V_408 , struct V_9 * V_10 ,
struct V_448 * V_449 , struct V_141 * V_513 )
{
T_5 V_514 = F_179 ( V_10 -> V_515 . V_516 ) ;
if ( V_513 && V_513 -> V_248 ) {
V_10 -> V_515 . V_516 = 0 ;
V_10 -> V_517 = 0 ;
F_5 ( 1 , L_158 ) ;
return;
} else if ( V_513 )
V_10 -> V_517 = 1 ;
if ( V_10 -> V_517 == 0 ) {
F_5 ( 1 , L_159 ) ;
return;
}
if ( ! F_180 ( V_408 , V_10 ) ) {
T_5 V_518 = F_179 ( V_10 -> V_515 . V_516 ) ;
F_5 ( 1 , L_160 , V_518 ) ;
if ( V_513 == NULL ) {
if ( ( V_514 & V_519 ) == 0 )
V_518 &= ~ V_519 ;
if ( ( V_514 & V_520 ) == 0 ) {
if ( V_518 & V_520 )
F_27 ( 1 , L_161 ) ;
V_518 &= ~ V_520 ;
} else if ( ( V_518 & V_520 ) == 0 ) {
F_27 ( 1 , L_162 ) ;
F_27 ( 1 , L_163 ) ;
}
}
if ( V_518 & V_521 )
F_27 ( 1 , L_164 ) ;
V_518 &= V_522 ;
if ( V_513 && V_513 -> V_281 )
V_518 &= ~ V_519 ;
else if ( V_519 & V_518 ) {
F_5 ( 1 , L_165 ) ;
if ( V_449 )
V_449 -> V_458 |=
V_523 ;
}
if ( V_513 && V_513 -> V_209 == 0 )
V_518 &= ~ V_520 ;
else if ( V_518 & V_520 ) {
F_5 ( 1 , L_166 ) ;
if ( V_449 )
V_449 -> V_458 |=
V_524 ;
}
F_5 ( 1 , L_167 , ( int ) V_518 ) ;
#ifdef F_62
if ( V_518 & V_525 )
F_5 ( 1 , L_168 ) ;
if ( V_518 & V_526 )
F_5 ( 1 , L_169 ) ;
if ( V_518 & V_520 )
F_5 ( 1 , L_170 ) ;
if ( V_518 & V_527 )
F_5 ( 1 , L_171 ) ;
if ( V_518 & V_519 )
F_5 ( 1 , L_172 ) ;
if ( V_518 & V_528 )
F_5 ( 1 , L_173 ) ;
if ( V_518 & V_529 )
F_5 ( 1 , L_174 ) ;
if ( V_518 & V_530 )
F_5 ( 1 , L_175 ) ;
if ( V_518 & V_521 )
F_5 ( 1 , L_176 ) ;
#endif
if ( F_181 ( V_408 , V_10 , V_518 ) ) {
if ( V_513 == NULL ) {
F_5 ( 1 , L_177 ) ;
} else
F_27 ( 1 , L_178
L_179
L_180
L_181
L_182
L_183 ) ;
}
}
}
void F_182 ( struct V_141 * V_531 ,
struct V_448 * V_449 )
{
F_123 ( & V_449 -> V_532 , V_533 ) ;
F_122 ( & V_449 -> V_534 ) ;
V_449 -> V_535 = V_536 ;
V_449 -> V_309 = V_531 -> V_309 ;
V_449 -> V_311 = V_531 -> V_311 ;
V_449 -> V_460 = V_531 -> V_202 ;
V_449 -> V_461 = V_531 -> V_203 ;
V_449 -> V_462 = V_531 -> V_205 ;
V_449 -> V_463 = V_531 -> V_204 ;
F_5 ( 1 , L_184 ,
V_449 -> V_462 , V_449 -> V_463 ) ;
V_449 -> V_211 = V_531 -> V_211 ;
V_449 -> V_426 = V_531 -> V_426 ;
if ( V_531 -> V_235 )
V_449 -> V_458 |= V_537 ;
if ( V_531 -> V_260 )
V_449 -> V_458 |= V_538 ;
if ( V_531 -> V_210 )
V_449 -> V_458 |= V_539 ;
if ( V_531 -> V_238 )
V_449 -> V_458 |= V_540 ;
if ( V_531 -> V_221 )
V_449 -> V_458 |= V_541 ;
if ( V_531 -> V_241 )
V_449 -> V_458 |= V_542 ;
if ( V_531 -> V_252 )
V_449 -> V_458 |= V_543 ;
if ( V_531 -> V_271 )
V_449 -> V_458 |= V_544 ;
if ( V_531 -> V_258 )
V_449 -> V_458 |= V_545 ;
if ( V_531 -> V_276 )
V_449 -> V_458 |= V_546 ;
if ( V_531 -> V_278 )
V_449 -> V_458 |= V_547 ;
if ( V_531 -> V_215 ) {
V_449 -> V_458 |= V_548 ;
V_449 -> V_549 = V_531 -> V_298 ;
}
if ( V_531 -> V_216 ) {
V_449 -> V_458 |= V_550 ;
V_449 -> V_551 = V_531 -> V_300 ;
}
if ( V_531 -> V_190 )
V_449 -> V_458 |= V_552 ;
if ( V_531 -> V_191 )
V_449 -> V_458 |= V_553 ;
if ( V_531 -> V_263 )
V_449 -> V_458 |= V_554 ;
if ( V_531 -> V_291 )
V_449 -> V_458 |= V_555 ;
if ( V_531 -> V_295 )
V_449 -> V_458 |= ( V_556 |
V_537 ) ;
if ( V_531 -> V_167 )
V_449 -> V_458 |= V_557 ;
if ( V_531 -> V_166 ) {
F_5 ( 1 , L_185 ) ;
V_449 -> V_458 |= V_558 ;
}
if ( V_531 -> V_293 ) {
if ( V_531 -> V_241 ) {
F_27 ( 1 , L_186
L_187 ) ;
} else {
V_449 -> V_458 |= V_559 ;
}
}
if ( ( V_531 -> V_278 ) && ( V_531 -> V_263 ) )
F_27 ( 1 , L_188
L_189 ) ;
}
static void
F_183 ( struct V_141 * V_390 )
{
F_11 ( V_390 -> V_315 ) ;
F_184 ( V_390 -> V_320 ) ;
if ( V_390 -> V_323 != V_390 -> V_327 + 2 )
F_11 ( V_390 -> V_323 ) ;
F_11 ( V_390 -> V_327 ) ;
F_11 ( V_390 -> V_329 ) ;
F_11 ( V_390 -> V_335 ) ;
F_11 ( V_390 -> V_333 ) ;
}
void
F_185 ( struct V_141 * V_390 )
{
if ( ! V_390 )
return;
F_183 ( V_390 ) ;
F_11 ( V_390 ) ;
}
static char *
F_186 ( const struct V_141 * V_142 ,
const struct V_448 * V_449 )
{
char * V_560 , * V_561 ;
unsigned int V_562 = V_142 -> V_333 ? strlen ( V_142 -> V_333 ) : 0 ;
unsigned int V_563 = F_83 ( V_142 -> V_327 , V_433 + 1 ) ;
V_560 = F_36 ( V_563 + V_562 + 1 , V_114 ) ;
if ( V_560 == NULL )
return F_72 ( - V_81 ) ;
strncpy ( V_560 , V_142 -> V_327 , V_563 ) ;
V_561 = V_560 + V_563 ;
if ( V_562 ) {
strncpy ( V_561 , V_142 -> V_333 , V_562 ) ;
V_561 += V_562 ;
}
* V_561 = '\0' ;
F_187 ( V_560 , F_188 ( V_449 ) ) ;
F_5 ( 1 , L_190 , V_20 , V_560 ) ;
return V_560 ;
}
static int
F_189 ( const unsigned int V_408 , struct V_7 * V_8 ,
struct V_141 * V_390 , struct V_448 * V_449 ,
int V_564 )
{
int V_3 ;
unsigned int V_470 = 0 ;
struct V_471 * V_472 = NULL ;
char * V_560 = NULL , * V_565 = NULL , * V_566 = NULL ;
V_560 = F_186 ( V_390 , V_449 ) ;
if ( F_118 ( V_560 ) )
return F_119 ( V_560 ) ;
V_565 = V_564 ? V_560 + 1 : V_390 -> V_327 + 1 ;
V_3 = F_165 ( V_408 , V_8 , V_565 , V_449 -> V_426 ,
& V_470 , & V_472 ,
V_449 -> V_458 & V_540 ) ;
if ( ! V_3 && V_470 > 0 ) {
char * V_567 = NULL ;
V_566 = F_190 ( V_449 -> V_180 ,
V_560 + 1 , V_472 ,
& V_567 ) ;
F_191 ( V_472 , V_470 ) ;
if ( F_118 ( V_566 ) ) {
V_3 = F_119 ( V_566 ) ;
V_566 = NULL ;
} else {
F_183 ( V_390 ) ;
memset ( V_390 , '\0' , sizeof( * V_390 ) ) ;
V_3 = F_192 ( V_390 , V_566 ,
V_567 ) ;
}
F_11 ( V_567 ) ;
F_11 ( V_449 -> V_180 ) ;
V_449 -> V_180 = V_566 ;
}
F_11 ( V_560 ) ;
return V_3 ;
}
static int
F_192 ( struct V_141 * V_390 , char * V_568 ,
const char * V_181 )
{
int V_3 = 0 ;
if ( F_81 ( V_568 , V_181 , V_390 ) )
return - V_138 ;
if ( V_390 -> V_163 ) {
F_5 ( 1 , L_191 ) ;
F_11 ( V_390 -> V_315 ) ;
V_390 -> V_315 = NULL ;
} else if ( V_390 -> V_315 ) {
F_5 ( 1 , L_192 , V_390 -> V_315 ) ;
} else {
F_193 ( L_193 ) ;
return - V_138 ;
}
if ( V_390 -> V_335 == NULL ) {
V_390 -> V_426 = F_194 () ;
} else {
V_390 -> V_426 = F_195 ( V_390 -> V_335 ) ;
if ( V_390 -> V_426 == NULL ) {
F_27 ( 1 , L_194 ,
V_390 -> V_335 ) ;
return - V_569 ;
}
}
return V_3 ;
}
struct V_141 *
F_196 ( char * V_568 , const char * V_181 )
{
int V_3 ;
struct V_141 * V_390 ;
V_390 = F_91 ( sizeof( struct V_141 ) , V_114 ) ;
if ( ! V_390 )
return F_72 ( - V_81 ) ;
V_3 = F_192 ( V_390 , V_568 , V_181 ) ;
if ( V_3 ) {
F_185 ( V_390 ) ;
V_390 = F_72 ( V_3 ) ;
}
return V_390 ;
}
int
F_197 ( struct V_448 * V_449 , struct V_141 * V_390 )
{
int V_3 ;
unsigned int V_408 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_560 ;
struct V_442 * V_443 ;
#ifdef F_198
int V_570 = 0 ;
#endif
V_3 = F_199 ( & V_449 -> V_571 , L_195 , V_572 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_198
V_573:
if ( V_570 ) {
if ( V_10 )
F_150 ( V_10 ) ;
else if ( V_8 )
F_132 ( V_8 ) ;
F_145 ( V_408 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_560 = NULL ;
V_443 = NULL ;
V_408 = F_133 () ;
V_2 = F_113 ( V_390 ) ;
if ( F_118 ( V_2 ) ) {
V_3 = F_119 ( V_2 ) ;
F_200 ( & V_449 -> V_571 ) ;
goto V_466;
}
V_8 = F_143 ( V_2 , V_390 ) ;
if ( F_118 ( V_8 ) ) {
V_3 = F_119 ( V_8 ) ;
V_8 = NULL ;
goto V_574;
}
V_10 = F_153 ( V_8 , V_390 ) ;
if ( F_118 ( V_10 ) ) {
V_3 = F_119 ( V_10 ) ;
V_10 = NULL ;
goto V_575;
}
if ( F_201 ( V_10 -> V_8 ) ) {
F_178 ( V_408 , V_10 , V_449 , V_390 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_179 ( V_10 -> V_515 . V_516 ) &
V_521 ) ) {
V_3 = - V_576 ;
goto V_574;
}
} else
V_10 -> V_517 = 0 ;
if ( ! V_10 -> V_577 && V_2 -> V_48 -> V_578 )
V_2 -> V_48 -> V_578 ( V_408 , V_10 ) ;
V_449 -> V_311 = V_2 -> V_48 -> V_579 ( V_10 , V_390 ) ;
V_449 -> V_309 = V_2 -> V_48 -> V_580 ( V_10 , V_390 ) ;
V_449 -> V_571 . V_581 = V_449 -> V_309 / V_582 ;
V_575:
#ifdef F_198
if ( V_570 == 0 ) {
int V_583 = F_189 ( V_408 , V_8 , V_390 , V_449 ,
false ) ;
if ( ! V_583 ) {
V_570 ++ ;
goto V_573;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_48 -> V_584 ) {
V_3 = - V_54 ;
goto V_574;
}
V_560 = F_202 ( V_390 , V_449 , V_10 ) ;
if ( V_560 == NULL ) {
V_3 = - V_81 ;
goto V_574;
}
V_3 = V_2 -> V_48 -> V_584 ( V_408 , V_10 , V_449 ,
V_560 ) ;
if ( V_3 != 0 && V_3 != - V_585 ) {
F_11 ( V_560 ) ;
goto V_574;
}
F_11 ( V_560 ) ;
}
if ( V_3 == - V_585 ) {
#ifdef F_198
if ( V_570 > V_586 ) {
V_3 = - V_587 ;
goto V_574;
}
V_3 = F_189 ( V_408 , V_8 , V_390 , V_449 , true ) ;
if ( ! V_3 ) {
V_570 ++ ;
goto V_573;
}
goto V_574;
#else
V_3 = - V_588 ;
#endif
}
if ( V_3 )
goto V_574;
V_443 = F_91 ( sizeof *V_443 , V_114 ) ;
if ( V_443 == NULL ) {
V_3 = - V_81 ;
goto V_574;
}
V_443 -> V_589 = V_8 -> V_202 ;
V_443 -> V_590 = V_10 ;
V_443 -> V_447 = V_37 ;
F_203 ( V_591 , & V_443 -> V_446 ) ;
F_203 ( V_445 , & V_443 -> V_446 ) ;
V_449 -> V_450 = V_443 ;
F_2 ( & V_449 -> V_534 ) ;
F_204 ( & V_449 -> V_535 , V_443 ) ;
F_3 ( & V_449 -> V_534 ) ;
F_24 ( V_56 , & V_449 -> V_532 ,
V_592 ) ;
V_574:
if ( V_3 ) {
if ( V_10 )
F_150 ( V_10 ) ;
else if ( V_8 )
F_132 ( V_8 ) ;
else
F_107 ( V_2 ) ;
F_200 ( & V_449 -> V_571 ) ;
}
V_466:
F_145 ( V_408 ) ;
return V_3 ;
}
int
F_205 ( const unsigned int V_408 , struct V_7 * V_8 ,
const char * V_593 , struct V_9 * V_10 ,
const struct V_468 * V_469 )
{
struct V_487 * V_594 ;
struct V_487 * V_595 ;
T_6 * V_596 ;
T_7 * V_597 ;
unsigned char * V_598 ;
int V_3 = 0 ;
int V_76 ;
T_8 V_599 , V_600 ;
if ( V_8 == NULL )
return - V_601 ;
V_594 = F_26 () ;
if ( V_594 == NULL )
return - V_81 ;
V_595 = V_594 ;
F_206 ( V_594 , V_602 ,
NULL , 4 ) ;
V_594 -> V_603 = F_207 ( V_8 -> V_2 ) ;
V_594 -> V_604 = V_8 -> V_605 ;
V_596 = ( T_6 * ) V_594 ;
V_597 = ( T_7 * ) V_595 ;
V_596 -> V_606 = 0xFF ;
V_596 -> V_439 = F_208 ( V_607 ) ;
V_598 = & V_596 -> V_608 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_382 & V_609 ) ) {
V_596 -> V_610 = F_208 ( 1 ) ;
* V_598 = 0 ;
V_598 ++ ;
} else {
V_596 -> V_610 = F_208 ( V_611 ) ;
#ifdef F_78
if ( ( V_373 & V_161 ) &&
( V_8 -> V_2 -> V_374 == V_375 ) )
F_209 ( V_10 -> V_320 , V_8 -> V_2 -> V_612 ,
V_8 -> V_2 -> V_382 &
V_613 ? true : false ,
V_598 ) ;
else
#endif
V_3 = F_210 ( V_10 -> V_320 , V_8 -> V_2 -> V_612 ,
V_598 , V_469 ) ;
V_598 += V_611 ;
if ( V_8 -> V_614 & V_615 ) {
* V_598 = 0 ;
V_598 ++ ;
}
}
if ( V_8 -> V_2 -> V_382 &
( V_383 | V_384 ) )
V_594 -> V_616 |= V_617 ;
if ( V_8 -> V_614 & V_618 ) {
V_594 -> V_616 |= V_619 ;
}
if ( V_8 -> V_614 & V_620 ) {
V_594 -> V_616 |= V_621 ;
}
if ( V_8 -> V_614 & V_615 ) {
V_594 -> V_616 |= V_622 ;
V_76 =
F_211 ( ( V_623 * ) V_598 , V_593 ,
6 *
( + 256 ) , V_469 ) ;
V_598 += 2 * V_76 ;
V_598 += 2 ;
} else {
strcpy ( V_598 , V_593 ) ;
V_598 += strlen ( V_593 ) + 1 ;
}
strcpy ( V_598 , L_196 ) ;
V_598 += strlen ( L_196 ) ;
V_598 += 1 ;
V_600 = V_598 - & V_596 -> V_608 [ 0 ] ;
V_596 -> V_624 . V_498 = F_174 ( F_212 (
V_596 -> V_624 . V_498 ) + V_600 ) ;
V_596 -> V_625 = F_208 ( V_600 ) ;
V_3 = F_213 ( V_408 , V_8 , V_594 , V_595 , & V_76 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_626 ;
V_10 -> V_431 = V_60 ;
V_10 -> V_23 = false ;
V_10 -> V_627 = V_595 -> V_628 ;
V_598 = F_214 ( V_595 ) ;
V_599 = F_215 ( V_595 ) ;
V_76 = F_83 ( V_598 , V_599 - 2 ) ;
if ( V_594 -> V_616 & V_622 )
V_626 = true ;
else
V_626 = false ;
if ( V_76 == 3 ) {
if ( ( V_598 [ 0 ] == 'I' ) && ( V_598 [ 1 ] == 'P' ) &&
( V_598 [ 2 ] == 'C' ) ) {
F_5 ( 1 , L_197 ) ;
V_10 -> V_577 = 1 ;
}
} else if ( V_76 == 2 ) {
if ( ( V_598 [ 0 ] == 'A' ) && ( V_598 [ 1 ] == ':' ) ) {
F_5 ( 1 , L_198 ) ;
}
}
V_598 += V_76 + 1 ;
V_599 -= ( V_76 + 1 ) ;
strncpy ( V_10 -> V_432 , V_593 , V_433 ) ;
F_11 ( V_10 -> V_629 ) ;
V_10 -> V_629 = F_216 ( V_598 ,
V_599 , V_626 ,
V_469 ) ;
F_5 ( 1 , L_199 , V_10 -> V_629 ) ;
if ( ( V_595 -> V_630 == 3 ) ||
( V_595 -> V_630 == 7 ) )
V_10 -> V_439 = F_217 ( V_597 -> V_631 ) ;
else
V_10 -> V_439 = 0 ;
F_5 ( 1 , L_200 , V_10 -> V_439 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_24 = V_595 -> V_628 ;
}
F_64 ( V_594 ) ;
return V_3 ;
}
void
F_218 ( struct V_448 * V_449 )
{
struct V_632 * V_633 = & V_449 -> V_535 ;
struct V_634 * V_635 ;
struct V_442 * V_443 ;
F_109 ( & V_449 -> V_532 ) ;
F_2 ( & V_449 -> V_534 ) ;
while ( ( V_635 = F_219 ( V_633 ) ) ) {
V_443 = F_220 ( V_635 , struct V_442 , V_636 ) ;
F_164 ( V_443 ) ;
F_221 ( V_445 , & V_443 -> V_446 ) ;
F_222 ( V_635 , V_633 ) ;
F_3 ( & V_449 -> V_534 ) ;
F_156 ( V_443 ) ;
F_2 ( & V_449 -> V_534 ) ;
}
F_3 ( & V_449 -> V_534 ) ;
F_200 ( & V_449 -> V_571 ) ;
F_11 ( V_449 -> V_180 ) ;
F_223 ( V_449 -> V_426 ) ;
F_11 ( V_449 ) ;
}
int
F_144 ( const unsigned int V_408 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_48 -> V_49 || ! V_2 -> V_48 -> V_637 )
return - V_54 ;
if ( ! V_2 -> V_48 -> V_49 ( V_2 ) )
return 0 ;
F_224 ( V_2 , 1 ) ;
V_3 = V_2 -> V_48 -> V_637 ( V_408 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_44 )
V_2 -> V_15 = V_60 ;
else
V_3 = - V_638 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_146 ( const unsigned int V_408 , struct V_7 * V_8 ,
struct V_468 * V_639 )
{
int V_3 = - V_54 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_29 = 0 ;
V_8 -> V_614 = V_2 -> V_614 ;
if ( V_640 == 0 )
V_8 -> V_614 &= ( ~ V_2 -> V_173 -> F_201 ) ;
F_5 ( 1 , L_201 ,
V_2 -> V_382 , V_2 -> V_614 , V_2 -> V_641 ) ;
if ( V_2 -> V_48 -> V_642 )
V_3 = V_2 -> V_48 -> V_642 ( V_408 , V_8 , V_639 ) ;
if ( V_3 ) {
F_27 ( 1 , L_202 , V_3 ) ;
} else {
F_8 ( & V_8 -> V_2 -> V_26 ) ;
if ( ! V_2 -> V_32 ) {
V_2 -> V_33 . V_34 = V_8 -> V_643 . V_34 ;
V_2 -> V_33 . V_35 = V_8 -> V_643 . V_35 ;
V_2 -> V_31 = 0x2 ;
V_2 -> V_32 = true ;
V_8 -> V_643 . V_34 = NULL ;
}
F_12 ( & V_2 -> V_26 ) ;
F_5 ( 1 , L_203 ) ;
F_2 ( & V_14 ) ;
V_8 -> V_409 = V_60 ;
V_8 -> V_23 = false ;
F_3 ( & V_14 ) ;
}
F_11 ( V_8 -> V_643 . V_34 ) ;
V_8 -> V_643 . V_34 = NULL ;
V_8 -> V_643 . V_35 = 0 ;
F_11 ( V_8 -> V_644 ) ;
V_8 -> V_644 = NULL ;
return V_3 ;
}
static int
F_225 ( struct V_141 * V_142 , struct V_7 * V_8 )
{
switch ( V_8 -> V_2 -> V_374 ) {
case V_379 :
V_142 -> V_146 = V_645 ;
return 0 ;
case V_377 :
V_142 -> V_146 = V_646 ;
break;
case V_378 :
V_142 -> V_146 = V_647 ;
break;
case V_380 :
V_142 -> V_146 = V_648 ;
break;
case V_375 :
V_142 -> V_146 = V_649 ;
break;
}
return F_136 ( V_142 , V_8 ) ;
}
static struct V_9 *
F_226 ( struct V_448 * V_449 , T_9 V_650 )
{
int V_3 ;
struct V_9 * V_651 = F_227 ( V_449 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_141 * V_513 ;
V_513 = F_91 ( sizeof( * V_513 ) , V_114 ) ;
if ( V_513 == NULL )
return F_72 ( - V_81 ) ;
V_513 -> V_426 = V_449 -> V_426 ;
V_513 -> V_202 = V_650 ;
V_513 -> V_201 = V_650 ;
V_513 -> V_327 = V_651 -> V_432 ;
V_513 -> V_232 = V_651 -> V_232 ;
V_513 -> V_250 = V_651 -> V_250 ;
V_513 -> V_284 = V_651 -> V_284 ;
V_513 -> V_248 = ! V_651 -> V_517 ;
V_3 = F_225 ( V_513 , V_651 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_72 ( V_3 ) ;
goto V_466;
}
F_2 ( & V_21 ) ;
++ V_651 -> V_8 -> V_2 -> V_387 ;
F_3 ( & V_21 ) ;
V_8 = F_143 ( V_651 -> V_8 -> V_2 , V_513 ) ;
if ( F_118 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_107 ( V_651 -> V_8 -> V_2 ) ;
goto V_466;
}
V_10 = F_153 ( V_8 , V_513 ) ;
if ( F_118 ( V_10 ) ) {
F_132 ( V_8 ) ;
goto V_466;
}
if ( F_201 ( V_8 ) )
F_178 ( 0 , V_10 , NULL , V_513 ) ;
V_466:
F_11 ( V_513 -> V_315 ) ;
F_11 ( V_513 -> V_320 ) ;
F_11 ( V_513 ) ;
return V_10 ;
}
struct V_9 *
F_227 ( struct V_448 * V_449 )
{
return F_159 ( F_160 ( V_449 ) ) ;
}
static int
F_228 ( void * V_652 )
{
F_69 () ;
return F_68 ( V_123 ) ? - V_86 : 0 ;
}
static struct V_442 *
F_229 ( struct V_632 * V_633 , T_9 V_653 )
{
struct V_634 * V_635 = V_633 -> V_634 ;
struct V_442 * V_443 ;
while ( V_635 ) {
V_443 = F_220 ( V_635 , struct V_442 , V_636 ) ;
if ( V_443 -> V_589 > V_653 )
V_635 = V_635 -> V_654 ;
else if ( V_443 -> V_589 < V_653 )
V_635 = V_635 -> V_655 ;
else
return V_443 ;
}
return NULL ;
}
static void
F_204 ( struct V_632 * V_633 , struct V_442 * V_656 )
{
struct V_634 * * V_63 = & ( V_633 -> V_634 ) , * V_657 = NULL ;
struct V_442 * V_443 ;
while ( * V_63 ) {
V_443 = F_220 ( * V_63 , struct V_442 , V_636 ) ;
V_657 = * V_63 ;
if ( V_443 -> V_589 > V_656 -> V_589 )
V_63 = & ( ( * V_63 ) -> V_654 ) ;
else
V_63 = & ( ( * V_63 ) -> V_655 ) ;
}
F_230 ( & V_656 -> V_636 , V_657 , V_63 ) ;
F_231 ( & V_656 -> V_636 , V_633 ) ;
}
struct V_442 *
F_232 ( struct V_448 * V_449 )
{
int V_658 ;
T_9 V_650 = F_233 () ;
struct V_442 * V_443 , * V_659 ;
if ( ! ( V_449 -> V_458 & V_556 ) )
return F_164 ( F_160 ( V_449 ) ) ;
F_2 ( & V_449 -> V_534 ) ;
V_443 = F_229 ( & V_449 -> V_535 , V_650 ) ;
if ( V_443 )
F_164 ( V_443 ) ;
F_3 ( & V_449 -> V_534 ) ;
if ( V_443 == NULL ) {
V_659 = F_91 ( sizeof( * V_443 ) , V_114 ) ;
if ( V_659 == NULL )
return F_72 ( - V_81 ) ;
V_659 -> V_589 = V_650 ;
V_659 -> V_590 = F_72 ( - V_576 ) ;
F_203 ( V_660 , & V_659 -> V_446 ) ;
F_203 ( V_445 , & V_659 -> V_446 ) ;
F_164 ( V_659 ) ;
F_2 ( & V_449 -> V_534 ) ;
V_443 = F_229 ( & V_449 -> V_535 , V_650 ) ;
if ( V_443 ) {
F_164 ( V_443 ) ;
F_3 ( & V_449 -> V_534 ) ;
F_11 ( V_659 ) ;
goto V_661;
}
V_443 = V_659 ;
F_204 ( & V_449 -> V_535 , V_443 ) ;
F_3 ( & V_449 -> V_534 ) ;
} else {
V_661:
V_658 = F_234 ( & V_443 -> V_446 , V_660 ,
F_228 ,
V_132 ) ;
if ( V_658 ) {
F_156 ( V_443 ) ;
return F_72 ( V_658 ) ;
}
if ( ! F_118 ( V_443 -> V_590 ) )
return V_443 ;
if ( F_23 ( V_37 , V_443 -> V_447 + V_662 ) ) {
F_156 ( V_443 ) ;
return F_72 ( - V_576 ) ;
}
if ( F_235 ( V_660 , & V_443 -> V_446 ) )
goto V_661;
}
V_443 -> V_590 = F_226 ( V_449 , V_650 ) ;
F_221 ( V_660 , & V_443 -> V_446 ) ;
F_236 ( & V_443 -> V_446 , V_660 ) ;
if ( F_118 ( V_443 -> V_590 ) ) {
F_156 ( V_443 ) ;
return F_72 ( - V_576 ) ;
}
return V_443 ;
}
static void
V_533 ( struct V_45 * V_46 )
{
struct V_448 * V_449 = F_22 ( V_46 , struct V_448 ,
V_532 . V_46 ) ;
struct V_632 * V_633 = & V_449 -> V_535 ;
struct V_634 * V_635 = F_219 ( V_633 ) ;
struct V_634 * V_5 ;
struct V_442 * V_443 ;
F_2 ( & V_449 -> V_534 ) ;
V_635 = F_219 ( V_633 ) ;
while ( V_635 != NULL ) {
V_5 = V_635 ;
V_635 = F_237 ( V_5 ) ;
V_443 = F_220 ( V_5 , struct V_442 , V_636 ) ;
if ( F_158 ( V_591 , & V_443 -> V_446 ) ||
F_61 ( & V_443 -> V_444 ) != 0 ||
F_31 ( V_443 -> V_447 + V_592 , V_37 ) )
continue;
F_164 ( V_443 ) ;
F_221 ( V_445 , & V_443 -> V_446 ) ;
F_222 ( V_5 , V_633 ) ;
F_3 ( & V_449 -> V_534 ) ;
F_156 ( V_443 ) ;
F_2 ( & V_449 -> V_534 ) ;
}
F_3 ( & V_449 -> V_534 ) ;
F_24 ( V_56 , & V_449 -> V_532 ,
V_592 ) ;
}
