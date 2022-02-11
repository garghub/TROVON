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
case V_180 :
V_142 -> V_48 = & V_181 ;
V_142 -> V_173 = & V_182 ;
break;
#endif
default:
F_27 ( 1 , L_34 , V_140 ) ;
return 1 ;
}
return 0 ;
}
static int
F_81 ( const char * V_183 , struct V_141 * V_142 )
{
char * V_184 ;
const char * V_185 = L_35 ;
T_1 V_35 ;
V_35 = strspn ( V_183 , V_185 ) ;
if ( V_35 != 2 )
return - V_138 ;
V_184 = strpbrk ( V_183 + 2 , V_185 ) ;
if ( ! V_184 )
return - V_138 ;
++ V_184 ;
V_35 = strcspn ( V_184 , V_185 ) ;
V_184 += V_35 ;
V_142 -> V_186 = F_82 ( V_183 , V_184 - V_183 , V_114 ) ;
if ( ! V_142 -> V_186 )
return - V_81 ;
F_83 ( V_142 -> V_186 , '\\' ) ;
if ( ! * V_184 ++ || ! * V_184 )
return 0 ;
V_142 -> V_187 = F_84 ( V_184 , V_114 ) ;
if ( ! V_142 -> V_187 )
return - V_81 ;
return 0 ;
}
static int
F_85 ( const char * V_188 , const char * V_183 ,
struct V_141 * V_142 )
{
char * V_189 , * V_190 ;
char * V_191 = NULL , * V_192 ;
unsigned int V_193 , V_194 , V_195 ;
char V_196 [ 2 ] ;
short int V_197 = - 1 ;
short int V_198 = - 1 ;
bool V_199 = false ;
bool V_200 = false ;
bool V_201 = false ;
char * V_202 = NULL ;
char * V_203 = F_86 () -> V_203 ;
char * string = NULL ;
char * V_204 , * V_140 ;
char V_137 ;
bool V_205 = false ;
unsigned short V_206 = 0 ;
struct V_93 * V_94 = (struct V_93 * ) & V_142 -> V_94 ;
V_196 [ 0 ] = ',' ;
V_196 [ 1 ] = 0 ;
V_137 = V_196 [ 0 ] ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
memset ( V_142 -> V_207 , 0x20 , V_208 ) ;
for ( V_194 = 0 ; V_194 < F_87 ( V_203 , V_208 ) ; V_194 ++ )
V_142 -> V_207 [ V_194 ] = toupper ( V_203 [ V_194 ] ) ;
V_142 -> V_207 [ V_208 ] = 0 ;
V_142 -> V_209 [ 0 ] = 0 ;
V_142 -> V_210 = F_88 () ;
V_142 -> V_211 = F_88 () ;
V_142 -> V_212 = F_89 () ;
V_142 -> V_213 = V_142 -> V_214 = V_215 | V_216 | V_217 ;
V_142 -> V_218 = 1 ;
V_142 -> V_219 = 1 ;
V_142 -> V_167 = true ;
V_142 -> V_220 = V_221 ;
V_142 -> V_48 = & V_172 ;
V_142 -> V_173 = & V_174 ;
if ( ! V_188 )
goto V_222;
V_191 = F_82 ( V_188 , V_223 , V_114 ) ;
if ( ! V_191 )
goto V_222;
V_192 = V_191 ;
V_190 = V_192 + strlen ( V_192 ) ;
if ( strncmp ( V_192 , L_36 , 4 ) == 0 ) {
if ( V_192 [ 4 ] != 0 ) {
V_196 [ 0 ] = V_192 [ 4 ] ;
V_192 += 5 ;
} else {
F_5 ( 1 , L_37 ) ;
}
}
V_142 -> V_224 = false ;
V_142 -> V_225 = false ;
if ( F_81 ( V_183 , V_142 ) == - V_81 ) {
F_90 ( V_226 L_38
L_39 ) ;
goto V_227;
}
while ( ( V_189 = F_91 ( & V_192 , V_196 ) ) != NULL ) {
T_2 args [ V_143 ] ;
unsigned long V_139 ;
int V_228 ;
if ( ! * V_189 )
continue;
V_228 = F_77 ( V_189 , V_229 , args ) ;
switch ( V_228 ) {
case V_230 :
break;
case V_231 :
V_142 -> V_232 = 0 ;
break;
case V_233 :
V_142 -> V_232 = 1 ;
break;
case V_234 :
V_197 = 1 ;
break;
case V_235 :
V_197 = 0 ;
break;
case V_236 :
V_198 = 1 ;
break;
case V_237 :
V_198 = 0 ;
break;
case V_238 :
V_142 -> V_239 = 1 ;
break;
case V_240 :
V_142 -> V_241 = 1 ;
break;
case V_242 :
V_142 -> V_243 = 1 ;
break;
case V_244 :
V_142 -> V_243 = 0 ;
break;
case V_245 :
V_142 -> V_246 = 0 ;
break;
case V_247 :
V_142 -> V_246 = 1 ;
break;
case V_248 :
V_142 -> V_249 = 1 ;
break;
case V_250 :
V_142 -> V_249 = 0 ;
break;
case V_251 :
V_142 -> V_252 = 1 ;
break;
case V_253 :
V_142 -> V_252 = 0 ;
break;
case V_254 :
V_142 -> V_255 = 1 ;
break;
case V_256 :
V_142 -> V_218 = 1 ;
break;
case V_257 :
V_142 -> V_218 = 0 ;
break;
case V_258 :
V_142 -> V_259 = 1 ;
break;
case V_260 :
V_142 -> V_261 = 1 ;
break;
case V_262 :
V_142 -> V_263 = 0 ;
break;
case V_264 :
V_142 -> V_263 = 1 ;
if ( V_142 -> V_214 ==
( V_265 & ~ ( V_266 | V_267 ) ) )
V_142 -> V_214 = V_265 ;
break;
case V_268 :
V_142 -> V_269 = 1 ;
break;
case V_270 :
V_142 -> V_271 = 1 ;
break;
case V_272 :
V_142 -> V_271 = 0 ;
break;
case V_273 :
V_142 -> V_274 = true ;
break;
case V_275 :
V_142 -> V_274 = false ;
break;
case V_276 :
V_142 -> V_243 = 0 ;
break;
case V_277 :
V_142 -> V_243 = 1 ;
break;
case V_278 :
V_142 -> V_279 = 0 ;
break;
case V_280 :
V_142 -> V_279 = 1 ;
break;
case V_281 :
V_142 -> V_282 = 1 ;
break;
case V_283 :
V_142 -> V_282 = 0 ;
break;
case V_284 :
V_142 -> V_219 = 1 ;
break;
case V_285 :
V_142 -> V_219 = 0 ;
break;
case V_286 :
V_142 -> V_287 = 1 ;
break;
case V_288 :
V_142 -> V_289 = 1 ;
break;
case V_290 :
V_142 -> V_289 = 0 ;
break;
case V_291 :
V_142 -> V_292 = 0 ;
break;
case V_293 :
V_142 -> V_292 = 1 ;
break;
case V_294 :
V_142 -> V_295 = 1 ;
break;
case V_296 :
V_142 -> V_146 |= V_149 ;
break;
case V_297 :
V_142 -> V_298 = 1 ;
break;
case V_299 :
F_90 ( V_300 L_40
L_41
L_42 ) ;
break;
case V_301 :
#ifndef F_92
F_27 ( 1 , L_43
L_44 ) ;
goto V_222;
#endif
V_142 -> V_302 = true ;
break;
case V_303 :
V_142 -> V_304 = true ;
break;
case V_305 :
V_142 -> V_306 = true ;
break;
case V_307 :
V_201 = true ;
break;
case V_308 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_45 ,
V_20 ) ;
goto V_222;
}
V_142 -> V_309 = V_139 ;
V_142 -> V_224 = true ;
break;
case V_310 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_46 ,
V_20 ) ;
goto V_222;
}
V_142 -> V_311 = V_139 ;
V_142 -> V_225 = true ;
break;
case V_312 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_47 ,
V_20 ) ;
goto V_222;
}
V_142 -> V_211 = V_139 ;
V_199 = true ;
break;
case V_313 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_48 ,
V_20 ) ;
goto V_222;
}
V_142 -> V_210 = V_139 ;
break;
case V_314 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_49 ,
V_20 ) ;
goto V_222;
}
V_142 -> V_212 = V_139 ;
V_200 = true ;
break;
case V_315 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_50 ,
V_20 ) ;
goto V_222;
}
V_142 -> V_214 = V_139 ;
break;
case V_316 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_51 ,
V_20 ) ;
goto V_222;
}
V_142 -> V_213 = V_139 ;
break;
case V_317 :
if ( F_73 ( args , & V_139 ) ||
V_139 > V_318 ) {
F_27 ( 1 , L_52 , V_20 ) ;
goto V_222;
}
V_206 = ( unsigned short ) V_139 ;
break;
case V_319 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_53 ,
V_20 ) ;
goto V_222;
}
V_142 -> V_320 = V_139 ;
break;
case V_321 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_54 ,
V_20 ) ;
goto V_222;
}
V_142 -> V_322 = V_139 ;
break;
case V_323 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_55 ,
V_20 ) ;
goto V_222;
}
V_142 -> V_220 = V_52 * V_139 ;
if ( V_142 -> V_220 > V_324 ) {
F_27 ( 1 , L_56
L_57 ) ;
goto V_222;
}
break;
case V_325 :
V_142 -> V_163 = 1 ;
V_142 -> V_326 = NULL ;
break;
case V_327 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_227;
if ( F_87 ( string , V_328 ) >
V_328 ) {
F_90 ( V_300 L_58 ) ;
goto V_222;
}
V_142 -> V_326 = F_84 ( string , V_114 ) ;
if ( ! V_142 -> V_326 ) {
F_90 ( V_300 L_59
L_60 ) ;
goto V_222;
}
break;
case V_329 :
V_142 -> V_330 = NULL ;
break;
case V_331 :
V_140 = strchr ( V_189 , '=' ) ;
V_140 ++ ;
V_204 = ( char * ) V_140 + strlen ( V_140 ) ;
if ( V_204 < V_190 && V_204 [ 1 ] == V_137 ) {
V_204 [ 0 ] = V_137 ;
while ( ( V_204 = strchr ( V_204 , V_137 ) )
!= NULL && ( V_204 [ 1 ] == V_137 ) ) {
V_204 = ( char * ) & V_204 [ 2 ] ;
}
if ( V_204 ) {
V_204 [ 0 ] = '\0' ;
V_192 = ( char * ) & V_204 [ 1 ] ;
} else
V_192 = V_190 ;
}
V_193 = strlen ( V_140 ) ;
V_142 -> V_330 = F_93 ( V_193 + 1 , V_114 ) ;
if ( V_142 -> V_330 == NULL ) {
F_90 ( V_300 L_59
L_61 ) ;
goto V_222;
}
for ( V_194 = 0 , V_195 = 0 ; V_194 < V_193 ; V_194 ++ , V_195 ++ ) {
V_142 -> V_330 [ V_195 ] = V_140 [ V_194 ] ;
if ( ( V_140 [ V_194 ] == V_137 ) &&
V_140 [ V_194 + 1 ] == V_137 )
V_194 ++ ;
}
V_142 -> V_330 [ V_195 ] = '\0' ;
break;
case V_332 :
V_205 = false ;
break;
case V_333 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_227;
if ( ! F_94 ( V_94 , string ,
strlen ( string ) ) ) {
F_90 ( V_226 L_62 ,
string ) ;
goto V_222;
}
V_205 = true ;
break;
case V_334 :
string = V_142 -> V_186 ;
V_142 -> V_186 = F_74 ( args ) ;
if ( V_142 -> V_186 == NULL )
goto V_227;
F_83 ( V_142 -> V_186 , '\\' ) ;
if ( V_142 -> V_186 [ 0 ] != '\\' || V_142 -> V_186 [ 1 ] != '\\' ) {
F_90 ( V_226 L_63
L_64 ) ;
goto V_222;
}
if ( ! string || strcmp ( string , V_142 -> V_186 ) )
F_90 ( V_300 L_65
L_66
L_67
L_68
L_69
L_70
L_71 , string ,
V_142 -> V_186 ) ;
break;
case V_335 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_227;
if ( F_87 ( string , 256 ) == 256 ) {
F_90 ( V_300 L_72
L_73 ) ;
goto V_222;
}
V_142 -> V_336 = F_84 ( string , V_114 ) ;
if ( ! V_142 -> V_336 ) {
F_90 ( V_300 L_59
L_74 ) ;
goto V_222;
}
F_5 ( 1 , L_75 ) ;
break;
case V_337 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_227;
if ( ! F_94 (
(struct V_93 * ) & V_142 -> V_338 ,
string , strlen ( string ) ) ) {
F_90 ( V_300 L_76
L_77 , string ) ;
goto V_222;
}
break;
case V_339 :
if ( * args [ 0 ] . V_340 == '/' || * args [ 0 ] . V_340 == '\\' )
args [ 0 ] . V_340 ++ ;
string = V_142 -> V_187 ;
V_142 -> V_187 = F_74 ( args ) ;
if ( V_142 -> V_187 == NULL )
goto V_227;
if ( ! string || strcmp ( string , V_142 -> V_187 ) )
F_90 ( V_300 L_65
L_78
L_79
L_80
L_81
L_82
L_83 , string ,
V_142 -> V_187 ) ;
break;
case V_341 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_227;
if ( F_87 ( string , 1024 ) >= 65 ) {
F_90 ( V_300 L_84
L_85 ) ;
goto V_222;
}
if ( F_95 ( string , L_86 , 7 ) != 0 ) {
V_142 -> V_342 = F_84 ( string ,
V_114 ) ;
if ( ! V_142 -> V_342 ) {
F_90 ( V_300 L_87
L_88 ) ;
goto V_222;
}
}
F_5 ( 1 , L_89 , string ) ;
break;
case V_343 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_227;
if ( F_95 ( string , L_90 , 11 ) == 0 ) {
F_90 ( V_300 L_91
L_92
L_93
L_94 ) ;
V_142 -> V_344 = 1 ;
}
break;
case V_345 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_227;
memset ( V_142 -> V_207 , 0x20 ,
V_208 ) ;
for ( V_194 = 0 ; V_194 < V_208 ; V_194 ++ ) {
if ( string [ V_194 ] == 0 )
break;
V_142 -> V_207 [ V_194 ] = string [ V_194 ] ;
}
if ( V_194 == V_208 && string [ V_194 ] != 0 )
F_90 ( V_300 L_95
L_96 ) ;
break;
case V_346 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_227;
memset ( V_142 -> V_209 , 0x20 ,
V_347 ) ;
for ( V_194 = 0 ; V_194 < 15 ; V_194 ++ ) {
if ( string [ V_194 ] == 0 )
break;
V_142 -> V_209 [ V_194 ] = string [ V_194 ] ;
}
if ( V_194 == V_208 && string [ V_194 ] != 0 )
F_90 ( V_300 L_97
L_98 ) ;
break;
case V_348 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_227;
if ( F_95 ( string , L_99 , 1 ) == 0 ) {
break;
}
F_90 ( V_300 L_100
L_101 ) ;
goto V_222;
case V_349 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_227;
if ( F_80 ( string , V_142 ) != 0 )
goto V_222;
break;
case V_350 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_227;
if ( F_76 ( string , V_142 ) != 0 )
goto V_222;
break;
case V_351 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_227;
if ( F_79 ( string , V_142 ) != 0 )
goto V_222;
break;
default:
if ( ! V_202 )
V_202 = V_189 ;
break;
}
F_11 ( string ) ;
string = NULL ;
}
if ( ! V_201 && V_202 ) {
F_90 ( V_226 L_102 , V_202 ) ;
goto V_222;
}
#ifndef F_96
if ( V_142 -> V_306 ) {
F_27 ( 1 , L_103
L_104 ) ;
goto V_222;
}
#endif
if ( ! V_142 -> V_186 ) {
F_27 ( 1 , L_105
L_106 ) ;
goto V_222;
}
if ( ! strchr ( V_142 -> V_186 + 3 , '\\' ) ) {
F_27 ( 1 , L_107 ) ;
goto V_222;
}
if ( ! V_205 ) {
if ( ! F_94 ( V_94 , & V_142 -> V_186 [ 2 ] ,
strlen ( & V_142 -> V_186 [ 2 ] ) ) ) {
F_90 ( V_226 L_108
L_109 ) ;
goto V_222;
}
}
F_42 ( V_94 , V_206 ) ;
if ( V_199 )
V_142 -> V_197 = V_197 ;
else if ( V_197 == 1 )
F_90 ( V_352 L_110
L_111 ) ;
if ( V_200 )
V_142 -> V_198 = V_198 ;
else if ( V_198 == 1 )
F_90 ( V_352 L_112
L_113 ) ;
F_11 ( V_191 ) ;
return 0 ;
V_227:
F_90 ( V_300 L_114 ) ;
V_222:
F_11 ( string ) ;
F_11 ( V_191 ) ;
return 1 ;
}
static bool
F_97 ( struct V_93 * V_338 , struct V_93 * V_353 )
{
switch ( V_338 -> V_354 ) {
case V_355 :
return ( V_353 -> V_354 == V_355 ) ;
case V_356 : {
struct V_357 * V_358 = (struct V_357 * ) V_338 ;
struct V_357 * V_359 = (struct V_357 * ) V_353 ;
return ( V_358 -> V_360 . V_361 == V_359 -> V_360 . V_361 ) ;
}
case V_362 : {
struct V_363 * V_364 = (struct V_363 * ) V_338 ;
struct V_363 * V_365 = (struct V_363 * ) V_353 ;
return F_98 ( & V_364 -> V_366 , & V_365 -> V_366 ) ;
}
default:
F_99 ( 1 ) ;
return false ;
}
}
static bool
F_100 ( struct V_1 * V_2 , struct V_93 * V_367 )
{
T_3 V_206 , * V_368 ;
switch ( V_367 -> V_354 ) {
case V_356 :
V_368 = & ( (struct V_357 * ) & V_2 -> V_94 ) -> V_369 ;
V_206 = ( (struct V_357 * ) V_367 ) -> V_369 ;
break;
case V_362 :
V_368 = & ( (struct V_363 * ) & V_2 -> V_94 ) -> V_370 ;
V_206 = ( (struct V_363 * ) V_367 ) -> V_370 ;
break;
default:
F_99 ( 1 ) ;
return false ;
}
if ( ! V_206 ) {
V_206 = F_101 ( V_95 ) ;
if ( V_206 == * V_368 )
return true ;
V_206 = F_101 ( V_371 ) ;
}
return V_206 == * V_368 ;
}
static bool
F_102 ( struct V_1 * V_2 , struct V_93 * V_367 ,
struct V_93 * V_338 )
{
switch ( V_367 -> V_354 ) {
case V_356 : {
struct V_357 * V_372 = (struct V_357 * ) V_367 ;
struct V_357 * V_373 =
(struct V_357 * ) & V_2 -> V_94 ;
if ( V_372 -> V_360 . V_361 != V_373 -> V_360 . V_361 )
return false ;
break;
}
case V_362 : {
struct V_363 * V_374 = (struct V_363 * ) V_367 ;
struct V_363 * V_375 =
(struct V_363 * ) & V_2 -> V_94 ;
if ( ! F_98 ( & V_374 -> V_366 ,
& V_375 -> V_366 ) )
return false ;
if ( V_374 -> V_376 != V_375 -> V_376 )
return false ;
break;
}
default:
F_99 ( 1 ) ;
return false ;
}
if ( ! F_97 ( V_338 , (struct V_93 * ) & V_2 -> V_338 ) )
return false ;
return true ;
}
static bool
F_103 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
unsigned int V_377 ;
if ( V_142 -> V_146 & ( ~ ( V_149 | V_378 ) ) )
V_377 = V_142 -> V_146 ;
else
V_377 = V_379 | V_142 -> V_146 ;
switch ( V_2 -> V_380 ) {
case V_381 :
if ( ! ( V_377 & ( V_161 | V_382 ) ) )
return false ;
break;
case V_383 :
if ( ! ( V_377 & V_158 ) )
return false ;
break;
case V_384 :
if ( ! ( V_377 & V_155 ) )
return false ;
break;
case V_385 :
if ( ! ( V_377 & V_147 ) )
return false ;
break;
case V_386 :
if ( ! ( V_377 & V_152 ) )
return false ;
break;
default:
return false ;
}
if ( ( V_377 & V_387 ) == 0 &&
( V_2 -> V_388 & V_389 ) )
return false ;
else if ( ( ( V_377 & V_149 ) == V_149 ) &&
( V_2 -> V_388 &
( V_390 | V_389 ) ) == 0 )
return false ;
return true ;
}
static int F_104 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
struct V_93 * V_367 = (struct V_93 * ) & V_142 -> V_94 ;
if ( ( V_2 -> V_173 != V_142 -> V_173 ) || ( V_2 -> V_48 != V_142 -> V_48 ) )
return 0 ;
if ( ! F_105 ( F_106 ( V_2 ) , V_123 -> V_391 -> V_392 ) )
return 0 ;
if ( ! F_102 ( V_2 , V_367 ,
(struct V_93 * ) & V_142 -> V_338 ) )
return 0 ;
if ( ! F_100 ( V_2 , V_367 ) )
return 0 ;
if ( ! F_103 ( V_2 , V_142 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_107 ( struct V_141 * V_142 )
{
struct V_1 * V_2 ;
F_2 ( & V_21 ) ;
F_108 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_104 ( V_2 , V_142 ) )
continue;
++ V_2 -> V_393 ;
F_3 ( & V_21 ) ;
F_5 ( 1 , L_115 ) ;
return V_2 ;
}
F_3 ( & V_21 ) ;
return NULL ;
}
static void
F_109 ( struct V_1 * V_2 )
{
struct V_121 * V_394 ;
F_2 ( & V_21 ) ;
if ( -- V_2 -> V_393 > 0 ) {
F_3 ( & V_21 ) ;
return;
}
F_110 ( F_106 ( V_2 ) ) ;
F_16 ( & V_2 -> V_104 ) ;
F_3 ( & V_21 ) ;
F_111 ( & V_2 -> V_47 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_112 ( V_2 ) ;
F_113 ( V_2 ) ;
F_11 ( V_2 -> V_33 . V_34 ) ;
V_2 -> V_33 . V_34 = NULL ;
V_2 -> V_33 . V_35 = 0 ;
V_394 = F_66 ( & V_2 -> V_131 , NULL ) ;
if ( V_394 )
F_114 ( V_395 , V_394 ) ;
}
static struct V_1 *
F_115 ( struct V_141 * V_396 )
{
struct V_1 * V_397 = NULL ;
int V_3 ;
F_5 ( 1 , L_116 , V_396 -> V_186 ) ;
V_397 = F_107 ( V_396 ) ;
if ( V_397 )
return V_397 ;
V_397 = F_93 ( sizeof( struct V_1 ) , V_114 ) ;
if ( ! V_397 ) {
V_3 = - V_81 ;
goto V_398;
}
V_3 = F_116 ( V_397 ) ;
if ( V_3 ) {
F_27 ( 1 , L_117 , V_3 ) ;
goto V_398;
}
V_397 -> V_48 = V_396 -> V_48 ;
V_397 -> V_173 = V_396 -> V_173 ;
F_117 ( V_397 , F_118 ( V_123 -> V_391 -> V_392 ) ) ;
V_397 -> V_55 = F_71 ( V_396 -> V_186 ) ;
if ( F_119 ( V_397 -> V_55 ) ) {
V_3 = F_120 ( V_397 -> V_55 ) ;
goto V_399;
}
V_397 -> V_239 = V_396 -> V_239 ;
V_397 -> V_241 = V_396 -> V_241 ;
V_397 -> V_400 = V_396 -> V_344 ;
V_397 -> V_401 = 0 ;
V_397 -> V_106 = 1 ;
F_121 ( & V_397 -> V_61 ) ;
F_121 ( & V_397 -> V_107 ) ;
F_13 ( & V_397 -> V_108 ) ;
F_122 ( & V_397 -> V_26 ) ;
memcpy ( V_397 -> V_402 ,
V_396 -> V_207 , V_347 ) ;
memcpy ( V_397 -> V_403 ,
V_396 -> V_209 , V_347 ) ;
V_397 -> V_32 = false ;
V_397 -> V_31 = 0 ;
V_397 -> V_36 = V_37 ;
F_123 ( & V_397 -> V_105 ) ;
F_13 ( & V_397 -> V_104 ) ;
F_13 ( & V_397 -> V_22 ) ;
F_124 ( & V_397 -> V_47 , F_21 ) ;
memcpy ( & V_397 -> V_338 , & V_396 -> V_338 ,
sizeof( V_397 -> V_338 ) ) ;
memcpy ( & V_397 -> V_94 , & V_396 -> V_94 ,
sizeof( V_397 -> V_94 ) ) ;
V_397 -> V_15 = V_404 ;
++ V_397 -> V_393 ;
V_3 = F_125 ( V_397 ) ;
if ( V_3 < 0 ) {
F_27 ( 1 , L_118 ) ;
goto V_399;
}
F_126 ( V_405 ) ;
V_397 -> V_131 = F_127 ( F_57 ,
V_397 , L_119 ) ;
if ( F_119 ( V_397 -> V_131 ) ) {
V_3 = F_120 ( V_397 -> V_131 ) ;
F_27 ( 1 , L_120 , V_3 ) ;
F_128 ( V_405 ) ;
goto V_399;
}
V_397 -> V_15 = V_44 ;
F_2 ( & V_21 ) ;
F_129 ( & V_397 -> V_104 , & V_406 ) ;
F_3 ( & V_21 ) ;
F_130 ( V_397 ) ;
F_24 ( V_56 , & V_397 -> V_47 , V_51 ) ;
return V_397 ;
V_399:
F_112 ( V_397 ) ;
F_110 ( F_106 ( V_397 ) ) ;
V_398:
if ( V_397 ) {
if ( ! F_119 ( V_397 -> V_55 ) )
F_11 ( V_397 -> V_55 ) ;
if ( V_397 -> V_27 )
F_10 ( V_397 -> V_27 ) ;
F_11 ( V_397 ) ;
}
return F_72 ( V_3 ) ;
}
static int F_131 ( struct V_7 * V_8 , struct V_141 * V_142 )
{
switch ( V_8 -> V_2 -> V_380 ) {
case V_385 :
if ( V_142 -> V_210 != V_8 -> V_210 )
return 0 ;
break;
default:
if ( V_8 -> V_407 == NULL ) {
if ( ! V_142 -> V_163 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_407 ,
V_142 -> V_326 ? V_142 -> V_326 : L_121 ,
V_328 ) )
return 0 ;
if ( strlen ( V_142 -> V_326 ) != 0 &&
V_8 -> V_330 != NULL &&
strncmp ( V_8 -> V_330 ,
V_142 -> V_330 ? V_142 -> V_330 : L_121 ,
V_408 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_132 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
struct V_7 * V_8 ;
F_2 ( & V_21 ) ;
F_108 (ses, &server->smb_ses_list, smb_ses_list) {
if ( ! F_131 ( V_8 , V_142 ) )
continue;
++ V_8 -> V_409 ;
F_3 ( & V_21 ) ;
return V_8 ;
}
F_3 ( & V_21 ) ;
return NULL ;
}
static void
F_133 ( struct V_7 * V_8 )
{
unsigned int V_410 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( 1 , L_122 , V_20 , V_8 -> V_409 ) ;
F_2 ( & V_21 ) ;
if ( -- V_8 -> V_409 > 0 ) {
F_3 ( & V_21 ) ;
return;
}
F_16 ( & V_8 -> V_22 ) ;
F_3 ( & V_21 ) ;
if ( V_8 -> V_411 == V_60 && V_2 -> V_48 -> V_412 ) {
V_410 = F_134 () ;
V_2 -> V_48 -> V_412 ( V_410 , V_8 ) ;
F_135 ( V_410 ) ;
}
F_136 ( V_8 ) ;
F_109 ( V_2 ) ;
}
static int
F_137 ( struct V_141 * V_142 , struct V_7 * V_8 )
{
int V_3 = 0 ;
char * V_413 , * V_137 , * V_414 ;
T_4 V_35 ;
struct V_415 * V_415 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_357 * V_416 ;
struct V_363 * V_417 ;
struct V_418 * V_419 ;
V_413 = F_36 ( V_420 , V_114 ) ;
if ( ! V_413 )
return - V_81 ;
switch ( V_2 -> V_94 . V_421 ) {
case V_356 :
V_416 = (struct V_357 * ) & V_2 -> V_94 ;
sprintf ( V_413 , L_123 , & V_416 -> V_360 . V_361 ) ;
break;
case V_362 :
V_417 = (struct V_363 * ) & V_2 -> V_94 ;
sprintf ( V_413 , L_124 , & V_417 -> V_366 . V_422 ) ;
break;
default:
F_5 ( 1 , L_125 , V_2 -> V_94 . V_421 ) ;
V_3 = - V_138 ;
goto V_398;
}
F_5 ( 1 , L_126 , V_20 , V_413 ) ;
V_415 = F_138 ( & V_423 , V_413 , L_121 ) ;
if ( F_119 ( V_415 ) ) {
if ( ! V_8 -> V_424 ) {
F_5 ( 1 , L_127 ) ;
V_3 = F_120 ( V_415 ) ;
goto V_398;
}
sprintf ( V_413 , L_128 , V_8 -> V_424 ) ;
F_5 ( 1 , L_126 , V_20 , V_413 ) ;
V_415 = F_138 ( & V_423 , V_413 , L_121 ) ;
if ( F_119 ( V_415 ) ) {
V_3 = F_120 ( V_415 ) ;
goto V_398;
}
}
F_139 ( & V_415 -> V_425 ) ;
V_419 = V_415 -> V_414 . V_189 ;
if ( F_140 ( V_419 ) ) {
V_3 = V_419 ? F_120 ( V_419 ) : - V_138 ;
goto V_426;
}
V_414 = ( char * ) V_419 -> V_189 ;
V_137 = F_141 ( V_414 , V_419 -> V_427 , ':' ) ;
F_5 ( 1 , L_129 , V_414 ) ;
if ( ! V_137 ) {
F_5 ( 1 , L_130 ,
V_419 -> V_427 ) ;
V_3 = - V_138 ;
goto V_426;
}
V_35 = V_137 - V_414 ;
if ( V_35 > V_328 || V_35 <= 0 ) {
F_5 ( 1 , L_131 , V_35 ) ;
V_3 = - V_138 ;
goto V_426;
}
V_142 -> V_326 = F_82 ( V_414 , V_35 , V_114 ) ;
if ( ! V_142 -> V_326 ) {
F_5 ( 1 , L_132 , V_35 ) ;
V_3 = - V_81 ;
goto V_426;
}
F_5 ( 1 , L_133 , V_20 , V_142 -> V_326 ) ;
V_35 = V_415 -> V_427 - ( V_35 + 1 ) ;
if ( V_35 > V_408 || V_35 <= 0 ) {
F_5 ( 1 , L_134 , V_35 ) ;
V_3 = - V_138 ;
F_11 ( V_142 -> V_326 ) ;
V_142 -> V_326 = NULL ;
goto V_426;
}
++ V_137 ;
V_142 -> V_330 = F_82 ( V_137 , V_35 , V_114 ) ;
if ( ! V_142 -> V_330 ) {
F_5 ( 1 , L_135 , V_35 ) ;
V_3 = - V_81 ;
F_11 ( V_142 -> V_326 ) ;
V_142 -> V_326 = NULL ;
goto V_426;
}
V_426:
F_142 ( & V_415 -> V_425 ) ;
F_143 ( V_415 ) ;
V_398:
F_11 ( V_413 ) ;
F_5 ( 1 , L_136 , V_20 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_144 ( struct V_1 * V_2 , struct V_141 * V_396 )
{
int V_3 = - V_81 ;
unsigned int V_410 ;
struct V_7 * V_8 ;
struct V_357 * V_367 = (struct V_357 * ) & V_2 -> V_94 ;
struct V_363 * V_374 = (struct V_363 * ) & V_2 -> V_94 ;
V_410 = F_134 () ;
V_8 = F_132 ( V_2 , V_396 ) ;
if ( V_8 ) {
F_5 ( 1 , L_137 , V_8 -> V_411 ) ;
F_8 ( & V_8 -> V_428 ) ;
V_3 = F_145 ( V_410 , V_8 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_428 ) ;
F_133 ( V_8 ) ;
F_146 ( V_410 ) ;
return F_72 ( V_3 ) ;
}
if ( V_8 -> V_23 ) {
F_5 ( 1 , L_138 ) ;
V_3 = F_147 ( V_410 , V_8 ,
V_396 -> V_429 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_428 ) ;
F_133 ( V_8 ) ;
F_146 ( V_410 ) ;
return F_72 ( V_3 ) ;
}
}
F_12 ( & V_8 -> V_428 ) ;
F_109 ( V_2 ) ;
F_146 ( V_410 ) ;
return V_8 ;
}
F_5 ( 1 , L_139 ) ;
V_8 = F_148 () ;
if ( V_8 == NULL )
goto V_430;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_94 . V_421 == V_362 )
sprintf ( V_8 -> V_431 , L_140 , & V_374 -> V_366 ) ;
else
sprintf ( V_8 -> V_431 , L_141 , & V_367 -> V_360 ) ;
if ( V_396 -> V_326 ) {
V_8 -> V_407 = F_84 ( V_396 -> V_326 , V_114 ) ;
if ( ! V_8 -> V_407 )
goto V_430;
}
if ( V_396 -> V_330 ) {
V_8 -> V_330 = F_84 ( V_396 -> V_330 , V_114 ) ;
if ( ! V_8 -> V_330 )
goto V_430;
}
if ( V_396 -> V_336 ) {
V_8 -> V_424 = F_84 ( V_396 -> V_336 , V_114 ) ;
if ( ! V_8 -> V_424 )
goto V_430;
}
V_8 -> V_210 = V_396 -> V_210 ;
V_8 -> V_211 = V_396 -> V_211 ;
V_8 -> V_432 = V_396 -> V_146 ;
F_8 ( & V_8 -> V_428 ) ;
V_3 = F_145 ( V_410 , V_8 ) ;
if ( ! V_3 )
V_3 = F_147 ( V_410 , V_8 , V_396 -> V_429 ) ;
F_12 ( & V_8 -> V_428 ) ;
if ( V_3 )
goto V_430;
F_2 ( & V_21 ) ;
F_129 ( & V_8 -> V_22 , & V_2 -> V_22 ) ;
F_3 ( & V_21 ) ;
F_146 ( V_410 ) ;
return V_8 ;
V_430:
F_136 ( V_8 ) ;
F_146 ( V_410 ) ;
return F_72 ( V_3 ) ;
}
static int F_149 ( struct V_9 * V_10 , const char * V_134 )
{
if ( V_10 -> V_433 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_434 , V_134 , V_435 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_150 ( struct V_7 * V_8 , const char * V_134 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_21 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_25 ) ;
if ( ! F_149 ( V_10 , V_134 ) )
continue;
++ V_10 -> V_436 ;
F_3 ( & V_21 ) ;
return V_10 ;
}
F_3 ( & V_21 ) ;
return NULL ;
}
static void
F_151 ( struct V_9 * V_10 )
{
unsigned int V_410 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( 1 , L_142 , V_20 , V_10 -> V_436 ) ;
F_2 ( & V_21 ) ;
if ( -- V_10 -> V_436 > 0 ) {
F_3 ( & V_21 ) ;
return;
}
F_16 ( & V_10 -> V_25 ) ;
F_3 ( & V_21 ) ;
V_410 = F_134 () ;
if ( V_8 -> V_2 -> V_48 -> V_437 )
V_8 -> V_2 -> V_48 -> V_437 ( V_410 , V_10 ) ;
F_135 ( V_410 ) ;
F_152 ( V_10 ) ;
F_153 ( V_10 ) ;
F_133 ( V_8 ) ;
}
static struct V_9 *
F_154 ( struct V_7 * V_8 , struct V_141 * V_396 )
{
int V_3 , V_410 ;
struct V_9 * V_10 ;
V_10 = F_150 ( V_8 , V_396 -> V_186 ) ;
if ( V_10 ) {
F_5 ( 1 , L_143 ) ;
F_133 ( V_8 ) ;
if ( V_10 -> V_298 != V_396 -> V_298 )
F_27 ( 1 , L_144
L_145 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_48 -> V_438 ) {
V_3 = - V_54 ;
goto V_439;
}
V_10 = F_155 () ;
if ( V_10 == NULL ) {
V_3 = - V_81 ;
goto V_439;
}
V_10 -> V_8 = V_8 ;
if ( V_396 -> V_330 ) {
V_10 -> V_330 = F_84 ( V_396 -> V_330 , V_114 ) ;
if ( ! V_10 -> V_330 ) {
V_3 = - V_81 ;
goto V_439;
}
}
V_410 = F_134 () ;
V_3 = V_8 -> V_2 -> V_48 -> V_438 ( V_410 , V_8 , V_396 -> V_186 , V_10 ,
V_396 -> V_429 ) ;
F_146 ( V_410 ) ;
F_5 ( 1 , L_146 , V_3 ) ;
if ( V_3 )
goto V_439;
if ( V_396 -> V_255 ) {
V_10 -> V_440 &= ~ V_441 ;
F_5 ( 1 , L_147 , V_10 -> V_440 ) ;
}
V_10 -> V_298 = V_396 -> V_298 ;
V_10 -> V_243 = V_396 -> V_243 ;
V_10 -> V_261 = V_396 -> V_261 ;
V_10 -> V_295 = V_396 -> V_295 ;
F_13 ( & V_10 -> V_442 ) ;
F_2 ( & V_21 ) ;
F_129 ( & V_10 -> V_25 , & V_8 -> V_25 ) ;
F_3 ( & V_21 ) ;
F_156 ( V_10 ) ;
return V_10 ;
V_439:
F_153 ( V_10 ) ;
return F_72 ( V_3 ) ;
}
void
F_157 ( struct V_443 * V_444 )
{
if ( ! V_444 || F_119 ( V_444 ) )
return;
if ( ! F_158 ( & V_444 -> V_445 ) ||
F_159 ( V_446 , & V_444 -> V_447 ) ) {
V_444 -> V_448 = V_37 ;
return;
}
if ( ! F_119 ( F_160 ( V_444 ) ) )
F_151 ( F_160 ( V_444 ) ) ;
F_11 ( V_444 ) ;
return;
}
static inline struct V_443 *
F_161 ( struct V_449 * V_450 )
{
return V_450 -> V_451 ;
}
static int
F_162 ( struct V_452 * V_453 , struct V_454 * V_455 )
{
struct V_449 * V_456 = F_163 ( V_453 ) ;
struct V_449 * V_63 = V_455 -> V_450 ;
if ( ( V_453 -> V_457 & V_458 ) != ( V_455 -> V_29 & V_458 ) )
return 0 ;
if ( ( V_456 -> V_459 & V_460 ) !=
( V_63 -> V_459 & V_460 ) )
return 0 ;
if ( V_63 -> V_322 && V_63 -> V_322 < V_456 -> V_322 )
return 0 ;
if ( V_63 -> V_320 && V_63 -> V_320 < V_456 -> V_320 )
return 0 ;
if ( V_456 -> V_461 != V_63 -> V_461 || V_456 -> V_462 != V_63 -> V_462 )
return 0 ;
if ( V_456 -> V_463 != V_63 -> V_463 ||
V_456 -> V_464 != V_63 -> V_464 )
return 0 ;
if ( strcmp ( V_456 -> V_429 -> V_465 , V_63 -> V_429 -> V_465 ) )
return 0 ;
if ( V_456 -> V_220 != V_63 -> V_220 )
return 0 ;
return 1 ;
}
int
F_164 ( struct V_452 * V_453 , void * V_189 )
{
struct V_454 * V_455 = (struct V_454 * ) V_189 ;
struct V_141 * V_396 ;
struct V_449 * V_450 ;
struct V_1 * V_466 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_443 * V_444 ;
int V_3 = 0 ;
F_2 ( & V_21 ) ;
V_450 = F_163 ( V_453 ) ;
V_444 = F_165 ( F_161 ( V_450 ) ) ;
if ( F_119 ( V_444 ) ) {
F_3 ( & V_21 ) ;
return V_3 ;
}
V_10 = F_160 ( V_444 ) ;
V_8 = V_10 -> V_8 ;
V_466 = V_8 -> V_2 ;
V_396 = V_455 -> V_142 ;
if ( ! F_104 ( V_466 , V_396 ) ||
! F_131 ( V_8 , V_396 ) ||
! F_149 ( V_10 , V_396 -> V_186 ) ) {
V_3 = 0 ;
goto V_467;
}
V_3 = F_162 ( V_453 , V_455 ) ;
V_467:
F_3 ( & V_21 ) ;
F_157 ( V_444 ) ;
return V_3 ;
}
int
F_166 ( const unsigned int V_410 , struct V_7 * V_8 , const char * V_468 ,
const struct V_469 * V_470 , unsigned int * V_471 ,
struct V_472 * * V_473 , int V_249 )
{
char * V_474 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_48 -> V_438 || ! V_8 -> V_2 -> V_48 -> V_475 )
return - V_54 ;
* V_471 = 0 ;
* V_473 = NULL ;
if ( V_8 -> V_24 == 0 ) {
V_474 = F_36 ( 2 +
F_87 ( V_8 -> V_431 , V_476 * 2 )
+ 1 + 4 + 2 , V_114 ) ;
if ( V_474 == NULL )
return - V_81 ;
V_474 [ 0 ] = '\\' ;
V_474 [ 1 ] = '\\' ;
strcpy ( V_474 + 2 , V_8 -> V_431 ) ;
strcpy ( V_474 + 2 + strlen ( V_8 -> V_431 ) , L_148 ) ;
V_3 = V_8 -> V_2 -> V_48 -> V_438 ( V_410 , V_8 , V_474 , NULL ,
V_470 ) ;
F_5 ( 1 , L_149 , V_3 , V_8 -> V_24 ) ;
F_11 ( V_474 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_48 -> V_475 ( V_410 , V_8 , V_468 ,
V_473 , V_471 ,
V_470 , V_249 ) ;
return V_3 ;
}
static inline void
F_167 ( struct V_477 * V_478 )
{
struct V_478 * V_479 = V_478 -> V_479 ;
F_168 ( F_169 ( V_479 ) ) ;
F_170 ( V_479 , L_150 ,
& V_480 [ 0 ] , L_151 , & V_481 [ 0 ] ) ;
}
static inline void
F_171 ( struct V_477 * V_478 )
{
struct V_478 * V_479 = V_478 -> V_479 ;
F_168 ( F_169 ( V_479 ) ) ;
F_170 ( V_479 , L_152 ,
& V_480 [ 1 ] , L_153 , & V_481 [ 1 ] ) ;
}
static inline void
F_167 ( struct V_477 * V_478 )
{
}
static inline void
F_171 ( struct V_477 * V_478 )
{
}
static void F_172 ( char * V_482 , char * V_483 , unsigned int V_76 )
{
unsigned int V_194 , V_195 ;
for ( V_194 = 0 , V_195 = 0 ; V_194 < ( V_76 ) ; V_194 ++ ) {
V_482 [ V_195 ] = 'A' + ( 0x0F & ( V_483 [ V_194 ] >> 4 ) ) ;
V_482 [ V_195 + 1 ] = 'A' + ( 0x0F & V_483 [ V_194 ] ) ;
V_195 += 2 ;
}
}
static int
F_173 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_338 . V_421 != V_355 ) {
struct V_477 * V_477 = V_2 -> V_27 ;
V_3 = V_477 -> V_48 -> V_484 ( V_477 ,
(struct V_93 * ) & V_2 -> V_338 ,
sizeof( V_2 -> V_338 ) ) ;
if ( V_3 < 0 ) {
struct V_357 * V_358 ;
struct V_363 * V_364 ;
V_358 = (struct V_357 * ) & V_2 -> V_338 ;
V_364 = (struct V_363 * ) & V_2 -> V_338 ;
if ( V_364 -> V_485 == V_362 )
F_27 ( 1 , L_154
L_155 ,
& V_364 -> V_366 , V_3 ) ;
else
F_27 ( 1 , L_154
L_156 ,
& V_358 -> V_360 . V_361 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_174 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_486 * V_487 ;
struct V_488 * V_489 ;
V_487 = F_93 ( sizeof( struct V_486 ) ,
V_114 ) ;
if ( V_487 ) {
V_487 -> V_490 . V_491 . V_492 = 32 ;
if ( V_2 -> V_403 &&
V_2 -> V_403 [ 0 ] != 0 )
F_172 ( V_487 -> V_490 .
V_491 . V_493 ,
V_2 -> V_403 ,
V_347 ) ;
else
F_172 ( V_487 -> V_490 .
V_491 . V_493 ,
V_494 ,
V_347 ) ;
V_487 -> V_490 . V_491 . V_495 = 32 ;
if ( V_2 -> V_402 &&
V_2 -> V_402 [ 0 ] != 0 )
F_172 ( V_487 -> V_490 .
V_491 . V_496 ,
V_2 -> V_402 ,
V_347 ) ;
else
F_172 ( V_487 -> V_490 .
V_491 . V_496 ,
L_157 ,
V_347 ) ;
V_487 -> V_490 . V_491 . V_497 = 0 ;
V_487 -> V_490 . V_491 . V_498 = 0 ;
V_489 = (struct V_488 * ) V_487 ;
V_489 -> V_499 = F_175 ( 0x81000044 ) ;
V_3 = F_176 ( V_2 , V_489 , 0x44 ) ;
F_11 ( V_487 ) ;
F_39 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_3 V_368 ;
int V_500 , V_501 ;
struct V_477 * V_477 = V_2 -> V_27 ;
struct V_93 * V_502 ;
V_502 = (struct V_93 * ) & V_2 -> V_94 ;
if ( V_2 -> V_94 . V_421 == V_362 ) {
V_368 = ( (struct V_363 * ) V_502 ) -> V_370 ;
V_500 = sizeof( struct V_363 ) ;
V_501 = V_362 ;
} else {
V_368 = ( (struct V_357 * ) V_502 ) -> V_369 ;
V_500 = sizeof( struct V_357 ) ;
V_501 = V_356 ;
}
if ( V_477 == NULL ) {
V_3 = F_177 ( F_106 ( V_2 ) , V_501 , V_503 ,
V_504 , & V_477 , 1 ) ;
if ( V_3 < 0 ) {
F_27 ( 1 , L_158 , V_3 ) ;
V_2 -> V_27 = NULL ;
return V_3 ;
}
F_5 ( 1 , L_159 ) ;
V_2 -> V_27 = V_477 ;
V_477 -> V_479 -> V_505 = V_73 ;
if ( V_501 == V_362 )
F_171 ( V_477 ) ;
else
F_167 ( V_477 ) ;
}
V_3 = F_173 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_477 -> V_479 -> V_506 = 7 * V_52 ;
V_477 -> V_479 -> V_507 = 5 * V_52 ;
if ( V_2 -> V_241 ) {
if ( V_477 -> V_479 -> V_508 < ( 200 * 1024 ) )
V_477 -> V_479 -> V_508 = 200 * 1024 ;
if ( V_477 -> V_479 -> V_509 < ( 140 * 1024 ) )
V_477 -> V_479 -> V_509 = 140 * 1024 ;
}
if ( V_2 -> V_400 ) {
int V_510 = 1 ;
V_3 = F_178 ( V_477 , V_511 , V_512 ,
( char * ) & V_510 , sizeof( V_510 ) ) ;
if ( V_3 )
F_5 ( 1 , L_160 , V_3 ) ;
}
F_5 ( 1 , L_161 ,
V_477 -> V_479 -> V_508 ,
V_477 -> V_479 -> V_509 , V_477 -> V_479 -> V_506 ) ;
V_3 = V_477 -> V_48 -> V_513 ( V_477 , V_502 , V_500 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( 1 , L_162 , V_3 ) ;
F_10 ( V_477 ) ;
V_2 -> V_27 = NULL ;
return V_3 ;
}
if ( V_368 == F_101 ( V_371 ) )
V_3 = F_174 ( V_2 ) ;
return V_3 ;
}
static int
F_125 ( struct V_1 * V_2 )
{
T_3 * V_368 ;
struct V_363 * V_374 = (struct V_363 * ) & V_2 -> V_94 ;
struct V_357 * V_367 = (struct V_357 * ) & V_2 -> V_94 ;
if ( V_2 -> V_94 . V_421 == V_362 )
V_368 = & V_374 -> V_370 ;
else
V_368 = & V_367 -> V_369 ;
if ( * V_368 == 0 ) {
int V_3 ;
* V_368 = F_101 ( V_95 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_368 = F_101 ( V_371 ) ;
}
return F_18 ( V_2 ) ;
}
void F_179 ( unsigned int V_410 , struct V_9 * V_10 ,
struct V_449 * V_450 , struct V_141 * V_514 )
{
T_5 V_515 = F_180 ( V_10 -> V_516 . V_517 ) ;
if ( V_514 && V_514 -> V_259 ) {
V_10 -> V_516 . V_517 = 0 ;
V_10 -> V_518 = 0 ;
F_5 ( 1 , L_163 ) ;
return;
} else if ( V_514 )
V_10 -> V_518 = 1 ;
if ( V_10 -> V_518 == 0 ) {
F_5 ( 1 , L_164 ) ;
return;
}
if ( ! F_181 ( V_410 , V_10 ) ) {
T_5 V_519 = F_180 ( V_10 -> V_516 . V_517 ) ;
F_5 ( 1 , L_165 , V_519 ) ;
if ( V_514 == NULL ) {
if ( ( V_515 & V_520 ) == 0 )
V_519 &= ~ V_520 ;
if ( ( V_515 & V_521 ) == 0 ) {
if ( V_519 & V_521 )
F_27 ( 1 , L_166 ) ;
V_519 &= ~ V_521 ;
} else if ( ( V_519 & V_521 ) == 0 ) {
F_27 ( 1 , L_167 ) ;
F_27 ( 1 , L_168 ) ;
}
}
if ( V_519 & V_522 )
F_27 ( 1 , L_169 ) ;
V_519 &= V_523 ;
if ( V_514 && V_514 -> V_292 )
V_519 &= ~ V_520 ;
else if ( V_520 & V_519 ) {
F_5 ( 1 , L_170 ) ;
if ( V_450 )
V_450 -> V_459 |=
V_524 ;
}
if ( V_514 && V_514 -> V_218 == 0 )
V_519 &= ~ V_521 ;
else if ( V_519 & V_521 ) {
F_5 ( 1 , L_171 ) ;
if ( V_450 )
V_450 -> V_459 |=
V_525 ;
}
F_5 ( 1 , L_172 , ( int ) V_519 ) ;
#ifdef F_62
if ( V_519 & V_526 )
F_5 ( 1 , L_173 ) ;
if ( V_519 & V_527 )
F_5 ( 1 , L_174 ) ;
if ( V_519 & V_521 )
F_5 ( 1 , L_175 ) ;
if ( V_519 & V_528 )
F_5 ( 1 , L_176 ) ;
if ( V_519 & V_520 )
F_5 ( 1 , L_177 ) ;
if ( V_519 & V_529 )
F_5 ( 1 , L_178 ) ;
if ( V_519 & V_530 )
F_5 ( 1 , L_179 ) ;
if ( V_519 & V_531 )
F_5 ( 1 , L_180 ) ;
if ( V_519 & V_522 )
F_5 ( 1 , L_181 ) ;
#endif
if ( F_182 ( V_410 , V_10 , V_519 ) ) {
if ( V_514 == NULL ) {
F_5 ( 1 , L_182 ) ;
} else
F_27 ( 1 , L_183
L_184
L_185
L_186
L_187
L_188 ) ;
}
}
}
void F_183 ( struct V_141 * V_532 ,
struct V_449 * V_450 )
{
F_124 ( & V_450 -> V_533 , V_534 ) ;
F_123 ( & V_450 -> V_535 ) ;
V_450 -> V_536 = V_537 ;
V_450 -> V_320 = V_532 -> V_320 ;
V_450 -> V_322 = V_532 -> V_322 ;
V_450 -> V_461 = V_532 -> V_211 ;
V_450 -> V_462 = V_532 -> V_212 ;
V_450 -> V_463 = V_532 -> V_214 ;
V_450 -> V_464 = V_532 -> V_213 ;
F_5 ( 1 , L_189 ,
V_450 -> V_463 , V_450 -> V_464 ) ;
V_450 -> V_220 = V_532 -> V_220 ;
V_450 -> V_429 = V_532 -> V_429 ;
if ( V_532 -> V_246 )
V_450 -> V_459 |= V_538 ;
if ( V_532 -> V_271 )
V_450 -> V_459 |= V_539 ;
if ( V_532 -> V_219 )
V_450 -> V_459 |= V_540 ;
if ( V_532 -> V_249 )
V_450 -> V_459 |= V_541 ;
if ( V_532 -> V_232 )
V_450 -> V_459 |= V_542 ;
if ( V_532 -> V_252 )
V_450 -> V_459 |= V_543 ;
if ( V_532 -> V_263 )
V_450 -> V_459 |= V_544 ;
if ( V_532 -> V_282 )
V_450 -> V_459 |= V_545 ;
if ( V_532 -> V_269 )
V_450 -> V_459 |= V_546 ;
if ( V_532 -> V_287 )
V_450 -> V_459 |= V_547 ;
if ( V_532 -> V_289 )
V_450 -> V_459 |= V_548 ;
if ( V_532 -> V_224 ) {
V_450 -> V_459 |= V_549 ;
V_450 -> V_550 = V_532 -> V_309 ;
}
if ( V_532 -> V_225 ) {
V_450 -> V_459 |= V_551 ;
V_450 -> V_552 = V_532 -> V_311 ;
}
if ( V_532 -> V_197 )
V_450 -> V_459 |= V_553 ;
if ( V_532 -> V_198 )
V_450 -> V_459 |= V_554 ;
if ( V_532 -> V_274 )
V_450 -> V_459 |= V_555 ;
if ( V_532 -> V_302 )
V_450 -> V_459 |= V_556 ;
if ( V_532 -> V_306 )
V_450 -> V_459 |= ( V_557 |
V_538 ) ;
if ( V_532 -> V_167 )
V_450 -> V_459 |= V_558 ;
if ( V_532 -> V_166 ) {
F_5 ( 1 , L_190 ) ;
V_450 -> V_459 |= V_559 ;
}
if ( V_532 -> V_304 ) {
if ( V_532 -> V_252 ) {
F_27 ( 1 , L_191
L_192 ) ;
} else {
V_450 -> V_459 |= V_560 ;
}
}
if ( ( V_532 -> V_289 ) && ( V_532 -> V_274 ) )
F_27 ( 1 , L_193
L_194 ) ;
}
static void
F_184 ( struct V_141 * V_396 )
{
F_11 ( V_396 -> V_326 ) ;
F_185 ( V_396 -> V_330 ) ;
F_11 ( V_396 -> V_186 ) ;
F_11 ( V_396 -> V_336 ) ;
F_11 ( V_396 -> V_342 ) ;
F_11 ( V_396 -> V_187 ) ;
}
void
F_186 ( struct V_141 * V_396 )
{
if ( ! V_396 )
return;
F_184 ( V_396 ) ;
F_11 ( V_396 ) ;
}
static char *
F_187 ( const struct V_141 * V_142 ,
const struct V_449 * V_450 )
{
char * V_561 , * V_184 ;
unsigned int V_562 = V_142 -> V_187 ? strlen ( V_142 -> V_187 ) + 1 : 0 ;
unsigned int V_563 = F_87 ( V_142 -> V_186 , V_435 + 1 ) ;
V_561 = F_36 ( V_563 + V_562 + 1 , V_114 ) ;
if ( V_561 == NULL )
return F_72 ( - V_81 ) ;
strncpy ( V_561 , V_142 -> V_186 , V_563 ) ;
V_184 = V_561 + V_563 ;
if ( V_562 ) {
* V_184 ++ = F_188 ( V_450 ) ;
strncpy ( V_184 , V_142 -> V_187 , V_562 ) ;
V_184 += V_562 ;
}
* V_184 = '\0' ;
F_83 ( V_561 , F_188 ( V_450 ) ) ;
F_5 ( 1 , L_195 , V_20 , V_561 ) ;
return V_561 ;
}
static int
F_189 ( const unsigned int V_410 , struct V_7 * V_8 ,
struct V_141 * V_396 , struct V_449 * V_450 ,
int V_564 )
{
int V_3 ;
unsigned int V_471 = 0 ;
struct V_472 * V_473 = NULL ;
char * V_561 = NULL , * V_565 = NULL , * V_566 = NULL ;
V_561 = F_187 ( V_396 , V_450 ) ;
if ( F_119 ( V_561 ) )
return F_120 ( V_561 ) ;
V_565 = V_564 ? V_561 + 1 : V_396 -> V_186 + 1 ;
V_3 = F_166 ( V_410 , V_8 , V_565 , V_450 -> V_429 ,
& V_471 , & V_473 ,
V_450 -> V_459 & V_541 ) ;
if ( ! V_3 && V_471 > 0 ) {
char * V_567 = NULL ;
V_566 = F_190 ( V_450 -> V_188 ,
V_561 + 1 , V_473 ,
& V_567 ) ;
F_191 ( V_473 , V_471 ) ;
if ( F_119 ( V_566 ) ) {
V_3 = F_120 ( V_566 ) ;
V_566 = NULL ;
} else {
F_184 ( V_396 ) ;
V_3 = F_192 ( V_396 , V_566 ,
V_567 ) ;
}
F_11 ( V_567 ) ;
F_11 ( V_450 -> V_188 ) ;
V_450 -> V_188 = V_566 ;
}
F_11 ( V_561 ) ;
return V_3 ;
}
static int
F_192 ( struct V_141 * V_396 , char * V_568 ,
const char * V_183 )
{
int V_3 = 0 ;
if ( F_85 ( V_568 , V_183 , V_396 ) )
return - V_138 ;
if ( V_396 -> V_163 ) {
F_5 ( 1 , L_196 ) ;
F_11 ( V_396 -> V_326 ) ;
V_396 -> V_326 = NULL ;
} else if ( V_396 -> V_326 ) {
F_5 ( 1 , L_197 , V_396 -> V_326 ) ;
} else {
F_193 ( L_198 ) ;
return - V_138 ;
}
if ( V_396 -> V_342 == NULL ) {
V_396 -> V_429 = F_194 () ;
} else {
V_396 -> V_429 = F_195 ( V_396 -> V_342 ) ;
if ( V_396 -> V_429 == NULL ) {
F_27 ( 1 , L_199 ,
V_396 -> V_342 ) ;
return - V_569 ;
}
}
return V_3 ;
}
struct V_141 *
F_196 ( char * V_568 , const char * V_183 )
{
int V_3 ;
struct V_141 * V_396 ;
V_396 = F_36 ( sizeof( struct V_141 ) , V_114 ) ;
if ( ! V_396 )
return F_72 ( - V_81 ) ;
V_3 = F_192 ( V_396 , V_568 , V_183 ) ;
if ( V_3 ) {
F_186 ( V_396 ) ;
V_396 = F_72 ( V_3 ) ;
}
return V_396 ;
}
int
F_197 ( struct V_449 * V_450 , struct V_141 * V_396 )
{
int V_3 ;
unsigned int V_410 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_561 ;
struct V_443 * V_444 ;
#ifdef F_198
int V_570 = 0 ;
#endif
V_3 = F_199 ( & V_450 -> V_571 , L_200 , V_572 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_198
V_573:
if ( V_570 ) {
if ( V_10 )
F_151 ( V_10 ) ;
else if ( V_8 )
F_133 ( V_8 ) ;
F_146 ( V_410 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_561 = NULL ;
V_444 = NULL ;
V_410 = F_134 () ;
V_2 = F_115 ( V_396 ) ;
if ( F_119 ( V_2 ) ) {
V_3 = F_120 ( V_2 ) ;
F_200 ( & V_450 -> V_571 ) ;
goto V_467;
}
V_8 = F_144 ( V_2 , V_396 ) ;
if ( F_119 ( V_8 ) ) {
V_3 = F_120 ( V_8 ) ;
V_8 = NULL ;
goto V_574;
}
V_10 = F_154 ( V_8 , V_396 ) ;
if ( F_119 ( V_10 ) ) {
V_3 = F_120 ( V_10 ) ;
V_10 = NULL ;
goto V_575;
}
if ( F_201 ( V_10 -> V_8 ) ) {
F_179 ( V_410 , V_10 , V_450 , V_396 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_180 ( V_10 -> V_516 . V_517 ) &
V_522 ) ) {
V_3 = - V_576 ;
goto V_574;
}
} else
V_10 -> V_518 = 0 ;
if ( ! V_10 -> V_577 && V_2 -> V_48 -> V_578 )
V_2 -> V_48 -> V_578 ( V_410 , V_10 ) ;
V_450 -> V_322 = V_2 -> V_48 -> V_579 ( V_10 , V_396 ) ;
V_450 -> V_320 = V_2 -> V_48 -> V_580 ( V_10 , V_396 ) ;
V_450 -> V_571 . V_581 = V_450 -> V_320 / V_582 ;
V_575:
#ifdef F_198
if ( V_570 == 0 ) {
int V_583 = F_189 ( V_410 , V_8 , V_396 , V_450 ,
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
V_561 = F_202 ( V_396 , V_450 , V_10 ) ;
if ( V_561 == NULL ) {
V_3 = - V_81 ;
goto V_574;
}
V_3 = V_2 -> V_48 -> V_584 ( V_410 , V_10 , V_450 ,
V_561 ) ;
if ( V_3 != 0 && V_3 != - V_585 ) {
F_11 ( V_561 ) ;
goto V_574;
}
F_11 ( V_561 ) ;
}
if ( V_3 == - V_585 ) {
#ifdef F_198
if ( V_570 > V_586 ) {
V_3 = - V_587 ;
goto V_574;
}
V_3 = F_189 ( V_410 , V_8 , V_396 , V_450 , true ) ;
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
V_444 = F_93 ( sizeof *V_444 , V_114 ) ;
if ( V_444 == NULL ) {
V_3 = - V_81 ;
goto V_574;
}
V_444 -> V_589 = V_8 -> V_211 ;
V_444 -> V_590 = V_10 ;
V_444 -> V_448 = V_37 ;
F_203 ( V_591 , & V_444 -> V_447 ) ;
F_203 ( V_446 , & V_444 -> V_447 ) ;
V_450 -> V_451 = V_444 ;
F_2 ( & V_450 -> V_535 ) ;
F_204 ( & V_450 -> V_536 , V_444 ) ;
F_3 ( & V_450 -> V_535 ) ;
F_24 ( V_56 , & V_450 -> V_533 ,
V_592 ) ;
V_574:
if ( V_3 ) {
if ( V_10 )
F_151 ( V_10 ) ;
else if ( V_8 )
F_133 ( V_8 ) ;
else
F_109 ( V_2 ) ;
F_200 ( & V_450 -> V_571 ) ;
}
V_467:
F_146 ( V_410 ) ;
return V_3 ;
}
int
F_205 ( const unsigned int V_410 , struct V_7 * V_8 ,
const char * V_593 , struct V_9 * V_10 ,
const struct V_469 * V_470 )
{
struct V_488 * V_594 ;
struct V_488 * V_595 ;
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
V_596 -> V_440 = F_208 ( V_607 ) ;
V_598 = & V_596 -> V_608 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_388 & V_609 ) ) {
V_596 -> V_610 = F_208 ( 1 ) ;
* V_598 = 0 ;
V_598 ++ ;
} else {
V_596 -> V_610 = F_208 ( V_611 ) ;
#ifdef F_78
if ( ( V_379 & V_161 ) &&
( V_8 -> V_2 -> V_380 == V_381 ) )
F_209 ( V_10 -> V_330 , V_8 -> V_2 -> V_612 ,
V_8 -> V_2 -> V_388 &
V_613 ? true : false ,
V_598 ) ;
else
#endif
V_3 = F_210 ( V_10 -> V_330 , V_8 -> V_2 -> V_612 ,
V_598 , V_470 ) ;
V_598 += V_611 ;
if ( V_8 -> V_614 & V_615 ) {
* V_598 = 0 ;
V_598 ++ ;
}
}
if ( V_8 -> V_2 -> V_388 &
( V_389 | V_390 ) )
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
( + 256 ) , V_470 ) ;
V_598 += 2 * V_76 ;
V_598 += 2 ;
} else {
strcpy ( V_598 , V_593 ) ;
V_598 += strlen ( V_593 ) + 1 ;
}
strcpy ( V_598 , L_201 ) ;
V_598 += strlen ( L_201 ) ;
V_598 += 1 ;
V_600 = V_598 - & V_596 -> V_608 [ 0 ] ;
V_596 -> V_624 . V_499 = F_175 ( F_212 (
V_596 -> V_624 . V_499 ) + V_600 ) ;
V_596 -> V_625 = F_208 ( V_600 ) ;
V_3 = F_213 ( V_410 , V_8 , V_594 , V_595 , & V_76 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_626 ;
V_10 -> V_433 = V_60 ;
V_10 -> V_23 = false ;
V_10 -> V_627 = V_595 -> V_628 ;
V_598 = F_214 ( V_595 ) ;
V_599 = F_215 ( V_595 ) ;
V_76 = F_87 ( V_598 , V_599 - 2 ) ;
if ( V_594 -> V_616 & V_622 )
V_626 = true ;
else
V_626 = false ;
if ( V_76 == 3 ) {
if ( ( V_598 [ 0 ] == 'I' ) && ( V_598 [ 1 ] == 'P' ) &&
( V_598 [ 2 ] == 'C' ) ) {
F_5 ( 1 , L_202 ) ;
V_10 -> V_577 = 1 ;
}
} else if ( V_76 == 2 ) {
if ( ( V_598 [ 0 ] == 'A' ) && ( V_598 [ 1 ] == ':' ) ) {
F_5 ( 1 , L_203 ) ;
}
}
V_598 += V_76 + 1 ;
V_599 -= ( V_76 + 1 ) ;
strncpy ( V_10 -> V_434 , V_593 , V_435 ) ;
F_11 ( V_10 -> V_629 ) ;
V_10 -> V_629 = F_216 ( V_598 ,
V_599 , V_626 ,
V_470 ) ;
F_5 ( 1 , L_204 , V_10 -> V_629 ) ;
if ( ( V_595 -> V_630 == 3 ) ||
( V_595 -> V_630 == 7 ) )
V_10 -> V_440 = F_217 ( V_597 -> V_631 ) ;
else
V_10 -> V_440 = 0 ;
F_5 ( 1 , L_205 , V_10 -> V_440 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_24 = V_595 -> V_628 ;
}
F_64 ( V_594 ) ;
return V_3 ;
}
void
F_218 ( struct V_449 * V_450 )
{
struct V_632 * V_633 = & V_450 -> V_536 ;
struct V_634 * V_635 ;
struct V_443 * V_444 ;
F_111 ( & V_450 -> V_533 ) ;
F_2 ( & V_450 -> V_535 ) ;
while ( ( V_635 = F_219 ( V_633 ) ) ) {
V_444 = F_220 ( V_635 , struct V_443 , V_636 ) ;
F_165 ( V_444 ) ;
F_221 ( V_446 , & V_444 -> V_447 ) ;
F_222 ( V_635 , V_633 ) ;
F_3 ( & V_450 -> V_535 ) ;
F_157 ( V_444 ) ;
F_2 ( & V_450 -> V_535 ) ;
}
F_3 ( & V_450 -> V_535 ) ;
F_200 ( & V_450 -> V_571 ) ;
F_11 ( V_450 -> V_188 ) ;
F_223 ( V_450 -> V_429 ) ;
F_11 ( V_450 ) ;
}
int
F_145 ( const unsigned int V_410 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_48 -> V_49 || ! V_2 -> V_48 -> V_637 )
return - V_54 ;
if ( ! V_2 -> V_48 -> V_49 ( V_2 ) )
return 0 ;
F_224 ( V_2 , 1 ) ;
V_3 = V_2 -> V_48 -> V_637 ( V_410 , V_8 ) ;
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
F_147 ( const unsigned int V_410 , struct V_7 * V_8 ,
struct V_469 * V_639 )
{
int V_3 = - V_54 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_29 = 0 ;
V_8 -> V_614 = V_2 -> V_614 ;
if ( V_640 == 0 )
V_8 -> V_614 &= ( ~ V_2 -> V_173 -> F_201 ) ;
F_5 ( 1 , L_206 ,
V_2 -> V_388 , V_2 -> V_614 , V_2 -> V_641 ) ;
if ( V_2 -> V_48 -> V_642 )
V_3 = V_2 -> V_48 -> V_642 ( V_410 , V_8 , V_639 ) ;
if ( V_3 ) {
F_27 ( 1 , L_207 , V_3 ) ;
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
F_5 ( 1 , L_208 ) ;
F_2 ( & V_14 ) ;
V_8 -> V_411 = V_60 ;
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
switch ( V_8 -> V_2 -> V_380 ) {
case V_385 :
V_142 -> V_146 = V_645 ;
return 0 ;
case V_383 :
V_142 -> V_146 = V_646 ;
break;
case V_384 :
V_142 -> V_146 = V_647 ;
break;
case V_386 :
V_142 -> V_146 = V_648 ;
break;
case V_381 :
V_142 -> V_146 = V_649 ;
break;
}
return F_137 ( V_142 , V_8 ) ;
}
static struct V_9 *
F_226 ( struct V_449 * V_450 , T_9 V_650 )
{
int V_3 ;
struct V_9 * V_651 = F_227 ( V_450 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_141 * V_514 ;
V_514 = F_93 ( sizeof( * V_514 ) , V_114 ) ;
if ( V_514 == NULL )
return F_72 ( - V_81 ) ;
V_514 -> V_429 = V_450 -> V_429 ;
V_514 -> V_211 = V_650 ;
V_514 -> V_210 = V_650 ;
V_514 -> V_186 = V_651 -> V_434 ;
V_514 -> V_243 = V_651 -> V_243 ;
V_514 -> V_261 = V_651 -> V_261 ;
V_514 -> V_295 = V_651 -> V_295 ;
V_514 -> V_259 = ! V_651 -> V_518 ;
V_3 = F_225 ( V_514 , V_651 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_72 ( V_3 ) ;
goto V_467;
}
F_2 ( & V_21 ) ;
++ V_651 -> V_8 -> V_2 -> V_393 ;
F_3 ( & V_21 ) ;
V_8 = F_144 ( V_651 -> V_8 -> V_2 , V_514 ) ;
if ( F_119 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_109 ( V_651 -> V_8 -> V_2 ) ;
goto V_467;
}
V_10 = F_154 ( V_8 , V_514 ) ;
if ( F_119 ( V_10 ) ) {
F_133 ( V_8 ) ;
goto V_467;
}
if ( F_201 ( V_8 ) )
F_179 ( 0 , V_10 , NULL , V_514 ) ;
V_467:
F_11 ( V_514 -> V_326 ) ;
F_11 ( V_514 -> V_330 ) ;
F_11 ( V_514 ) ;
return V_10 ;
}
struct V_9 *
F_227 ( struct V_449 * V_450 )
{
return F_160 ( F_161 ( V_450 ) ) ;
}
static int
F_228 ( void * V_652 )
{
F_69 () ;
return F_68 ( V_123 ) ? - V_86 : 0 ;
}
static struct V_443 *
F_229 ( struct V_632 * V_633 , T_9 V_653 )
{
struct V_634 * V_635 = V_633 -> V_634 ;
struct V_443 * V_444 ;
while ( V_635 ) {
V_444 = F_220 ( V_635 , struct V_443 , V_636 ) ;
if ( V_444 -> V_589 > V_653 )
V_635 = V_635 -> V_654 ;
else if ( V_444 -> V_589 < V_653 )
V_635 = V_635 -> V_655 ;
else
return V_444 ;
}
return NULL ;
}
static void
F_204 ( struct V_632 * V_633 , struct V_443 * V_656 )
{
struct V_634 * * V_63 = & ( V_633 -> V_634 ) , * V_657 = NULL ;
struct V_443 * V_444 ;
while ( * V_63 ) {
V_444 = F_220 ( * V_63 , struct V_443 , V_636 ) ;
V_657 = * V_63 ;
if ( V_444 -> V_589 > V_656 -> V_589 )
V_63 = & ( ( * V_63 ) -> V_654 ) ;
else
V_63 = & ( ( * V_63 ) -> V_655 ) ;
}
F_230 ( & V_656 -> V_636 , V_657 , V_63 ) ;
F_231 ( & V_656 -> V_636 , V_633 ) ;
}
struct V_443 *
F_232 ( struct V_449 * V_450 )
{
int V_658 ;
T_9 V_650 = F_233 () ;
struct V_443 * V_444 , * V_659 ;
if ( ! ( V_450 -> V_459 & V_557 ) )
return F_165 ( F_161 ( V_450 ) ) ;
F_2 ( & V_450 -> V_535 ) ;
V_444 = F_229 ( & V_450 -> V_536 , V_650 ) ;
if ( V_444 )
F_165 ( V_444 ) ;
F_3 ( & V_450 -> V_535 ) ;
if ( V_444 == NULL ) {
V_659 = F_93 ( sizeof( * V_444 ) , V_114 ) ;
if ( V_659 == NULL )
return F_72 ( - V_81 ) ;
V_659 -> V_589 = V_650 ;
V_659 -> V_590 = F_72 ( - V_576 ) ;
F_203 ( V_660 , & V_659 -> V_447 ) ;
F_203 ( V_446 , & V_659 -> V_447 ) ;
F_165 ( V_659 ) ;
F_2 ( & V_450 -> V_535 ) ;
V_444 = F_229 ( & V_450 -> V_536 , V_650 ) ;
if ( V_444 ) {
F_165 ( V_444 ) ;
F_3 ( & V_450 -> V_535 ) ;
F_11 ( V_659 ) ;
goto V_661;
}
V_444 = V_659 ;
F_204 ( & V_450 -> V_536 , V_444 ) ;
F_3 ( & V_450 -> V_535 ) ;
} else {
V_661:
V_658 = F_234 ( & V_444 -> V_447 , V_660 ,
F_228 ,
V_132 ) ;
if ( V_658 ) {
F_157 ( V_444 ) ;
return F_72 ( V_658 ) ;
}
if ( ! F_119 ( V_444 -> V_590 ) )
return V_444 ;
if ( F_23 ( V_37 , V_444 -> V_448 + V_662 ) ) {
F_157 ( V_444 ) ;
return F_72 ( - V_576 ) ;
}
if ( F_235 ( V_660 , & V_444 -> V_447 ) )
goto V_661;
}
V_444 -> V_590 = F_226 ( V_450 , V_650 ) ;
F_221 ( V_660 , & V_444 -> V_447 ) ;
F_236 ( & V_444 -> V_447 , V_660 ) ;
if ( F_119 ( V_444 -> V_590 ) ) {
F_157 ( V_444 ) ;
return F_72 ( - V_576 ) ;
}
return V_444 ;
}
static void
V_534 ( struct V_45 * V_46 )
{
struct V_449 * V_450 = F_22 ( V_46 , struct V_449 ,
V_533 . V_46 ) ;
struct V_632 * V_633 = & V_450 -> V_536 ;
struct V_634 * V_635 = F_219 ( V_633 ) ;
struct V_634 * V_5 ;
struct V_443 * V_444 ;
F_2 ( & V_450 -> V_535 ) ;
V_635 = F_219 ( V_633 ) ;
while ( V_635 != NULL ) {
V_5 = V_635 ;
V_635 = F_237 ( V_5 ) ;
V_444 = F_220 ( V_5 , struct V_443 , V_636 ) ;
if ( F_159 ( V_591 , & V_444 -> V_447 ) ||
F_61 ( & V_444 -> V_445 ) != 0 ||
F_31 ( V_444 -> V_448 + V_592 , V_37 ) )
continue;
F_165 ( V_444 ) ;
F_221 ( V_446 , & V_444 -> V_447 ) ;
F_222 ( V_5 , V_633 ) ;
F_3 ( & V_450 -> V_535 ) ;
F_157 ( V_444 ) ;
F_2 ( & V_450 -> V_535 ) ;
}
F_3 ( & V_450 -> V_535 ) ;
F_24 ( V_56 , & V_450 -> V_533 ,
V_592 ) ;
}
