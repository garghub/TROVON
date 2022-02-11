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
static int F_76 ( T_2 args [] , T_3 * V_140 )
{
unsigned long V_141 ;
T_3 V_142 ;
int V_3 ;
V_3 = F_73 ( args , & V_141 ) ;
if ( V_3 )
return V_3 ;
V_142 = F_77 ( F_78 () , V_141 ) ;
if ( ! F_79 ( V_142 ) )
return - V_138 ;
* V_140 = V_142 ;
return 0 ;
}
static int F_80 ( T_2 args [] , T_4 * V_140 )
{
unsigned long V_141 ;
T_4 V_143 ;
int V_3 ;
V_3 = F_73 ( args , & V_141 ) ;
if ( V_3 )
return V_3 ;
V_143 = F_81 ( F_78 () , V_141 ) ;
if ( ! F_82 ( V_143 ) )
return - V_138 ;
* V_140 = V_143 ;
return 0 ;
}
static int F_83 ( char * V_141 ,
struct V_144 * V_145 )
{
T_2 args [ V_146 ] ;
switch ( F_84 ( V_141 , V_147 , args ) ) {
case V_148 :
V_145 -> V_149 |= V_150 | V_151 ;
break;
case V_152 :
V_145 -> V_149 |= V_150 | V_153 ;
break;
case V_154 :
F_27 ( 1 , L_31 ) ;
break;
case V_155 :
V_145 -> V_149 |= V_156 ;
break;
case V_157 :
V_145 -> V_149 |= V_156 | V_153 ;
break;
case V_158 :
V_145 -> V_149 |= V_159 ;
break;
case V_160 :
V_145 -> V_149 |= V_159 | V_153 ;
break;
case V_161 :
V_145 -> V_149 |= V_162 ;
break;
case V_163 :
V_145 -> V_149 |= V_162 | V_153 ;
break;
#ifdef F_85
case V_164 :
V_145 -> V_149 |= V_165 ;
break;
#endif
case V_166 :
V_145 -> V_167 = 1 ;
break;
default:
F_27 ( 1 , L_32 , V_141 ) ;
return 1 ;
}
return 0 ;
}
static int
F_86 ( char * V_141 , struct V_144 * V_145 )
{
T_2 args [ V_146 ] ;
switch ( F_84 ( V_141 , V_168 , args ) ) {
case V_169 :
V_145 -> V_170 = false ;
V_145 -> V_171 = false ;
break;
case V_172 :
V_145 -> V_170 = false ;
V_145 -> V_171 = true ;
break;
case V_173 :
V_145 -> V_170 = true ;
V_145 -> V_171 = false ;
break;
default:
F_27 ( 1 , L_33 , V_141 ) ;
return 1 ;
}
return 0 ;
}
static int
F_87 ( char * V_141 , struct V_144 * V_145 )
{
T_2 args [ V_146 ] ;
switch ( F_84 ( V_141 , V_174 , args ) ) {
case V_175 :
V_145 -> V_48 = & V_176 ;
V_145 -> V_177 = & V_178 ;
break;
#ifdef F_4
case V_179 :
V_145 -> V_48 = & V_180 ;
V_145 -> V_177 = & V_181 ;
break;
case V_182 :
V_145 -> V_48 = & V_180 ;
V_145 -> V_177 = & V_183 ;
break;
case V_184 :
V_145 -> V_48 = & V_185 ;
V_145 -> V_177 = & V_186 ;
break;
#endif
default:
F_27 ( 1 , L_34 , V_141 ) ;
return 1 ;
}
return 0 ;
}
static int
F_88 ( const char * V_187 , struct V_144 * V_145 )
{
char * V_188 ;
const char * V_189 = L_35 ;
T_1 V_35 ;
V_35 = strspn ( V_187 , V_189 ) ;
if ( V_35 != 2 )
return - V_138 ;
V_188 = strpbrk ( V_187 + 2 , V_189 ) ;
if ( ! V_188 )
return - V_138 ;
++ V_188 ;
V_35 = strcspn ( V_188 , V_189 ) ;
V_188 += V_35 ;
V_145 -> V_190 = F_89 ( V_187 , V_188 - V_187 , V_114 ) ;
if ( ! V_145 -> V_190 )
return - V_81 ;
F_90 ( V_145 -> V_190 , '\\' ) ;
if ( ! * V_188 ++ || ! * V_188 )
return 0 ;
V_145 -> V_191 = F_91 ( V_188 , V_114 ) ;
if ( ! V_145 -> V_191 )
return - V_81 ;
return 0 ;
}
static int
F_92 ( const char * V_192 , const char * V_187 ,
struct V_144 * V_145 )
{
char * V_193 , * V_194 ;
char * V_195 = NULL , * V_196 ;
unsigned int V_197 , V_198 , V_199 ;
char V_200 [ 2 ] ;
short int V_201 = - 1 ;
short int V_202 = - 1 ;
bool V_203 = false ;
bool V_204 = false ;
bool V_205 = false ;
char * V_206 = NULL ;
char * V_207 = F_93 () -> V_207 ;
char * string = NULL ;
char * V_208 , * V_141 ;
char V_137 ;
bool V_209 = false ;
unsigned short V_210 = 0 ;
struct V_93 * V_94 = (struct V_93 * ) & V_145 -> V_94 ;
V_200 [ 0 ] = ',' ;
V_200 [ 1 ] = 0 ;
V_137 = V_200 [ 0 ] ;
memset ( V_145 , 0 , sizeof( * V_145 ) ) ;
memset ( V_145 -> V_211 , 0x20 , V_212 ) ;
for ( V_198 = 0 ; V_198 < F_94 ( V_207 , V_212 ) ; V_198 ++ )
V_145 -> V_211 [ V_198 ] = toupper ( V_207 [ V_198 ] ) ;
V_145 -> V_211 [ V_212 ] = 0 ;
V_145 -> V_213 [ 0 ] = 0 ;
V_145 -> V_214 = F_95 () ;
V_145 -> V_215 = F_95 () ;
V_145 -> V_216 = F_96 () ;
V_145 -> V_217 = V_145 -> V_218 = V_219 | V_220 | V_221 ;
V_145 -> V_222 = 1 ;
V_145 -> V_223 = 1 ;
V_145 -> V_171 = true ;
V_145 -> V_224 = V_225 ;
V_145 -> V_48 = & V_176 ;
V_145 -> V_177 = & V_178 ;
if ( ! V_192 )
goto V_226;
V_195 = F_89 ( V_192 , V_227 , V_114 ) ;
if ( ! V_195 )
goto V_226;
V_196 = V_195 ;
V_194 = V_196 + strlen ( V_196 ) ;
if ( strncmp ( V_196 , L_36 , 4 ) == 0 ) {
if ( V_196 [ 4 ] != 0 ) {
V_200 [ 0 ] = V_196 [ 4 ] ;
V_196 += 5 ;
} else {
F_5 ( 1 , L_37 ) ;
}
}
V_145 -> V_228 = false ;
V_145 -> V_229 = false ;
if ( F_88 ( V_187 , V_145 ) == - V_81 ) {
F_97 ( V_230 L_38
L_39 ) ;
goto V_231;
}
while ( ( V_193 = F_98 ( & V_196 , V_200 ) ) != NULL ) {
T_2 args [ V_146 ] ;
unsigned long V_139 ;
int V_232 ;
if ( ! * V_193 )
continue;
V_232 = F_84 ( V_193 , V_233 , args ) ;
switch ( V_232 ) {
case V_234 :
break;
case V_235 :
V_145 -> V_236 = 0 ;
break;
case V_237 :
V_145 -> V_236 = 1 ;
break;
case V_238 :
V_201 = 1 ;
break;
case V_239 :
V_201 = 0 ;
break;
case V_240 :
V_202 = 1 ;
break;
case V_241 :
V_202 = 0 ;
break;
case V_242 :
V_145 -> V_243 = 1 ;
break;
case V_244 :
V_145 -> V_245 = 1 ;
break;
case V_246 :
V_145 -> V_247 = 1 ;
break;
case V_248 :
V_145 -> V_247 = 0 ;
break;
case V_249 :
V_145 -> V_250 = 0 ;
break;
case V_251 :
V_145 -> V_250 = 1 ;
break;
case V_252 :
V_145 -> V_253 = 1 ;
break;
case V_254 :
V_145 -> V_253 = 0 ;
break;
case V_255 :
V_145 -> V_256 = 1 ;
break;
case V_257 :
V_145 -> V_256 = 0 ;
break;
case V_258 :
V_145 -> V_259 = 1 ;
break;
case V_260 :
V_145 -> V_222 = 1 ;
break;
case V_261 :
V_145 -> V_222 = 0 ;
break;
case V_262 :
V_145 -> V_263 = 1 ;
break;
case V_264 :
V_145 -> V_265 = 1 ;
break;
case V_266 :
V_145 -> V_267 = 0 ;
break;
case V_268 :
V_145 -> V_267 = 1 ;
if ( V_145 -> V_218 ==
( V_269 & ~ ( V_270 | V_271 ) ) )
V_145 -> V_218 = V_269 ;
break;
case V_272 :
V_145 -> V_273 = 1 ;
break;
case V_274 :
V_145 -> V_275 = 1 ;
break;
case V_276 :
V_145 -> V_275 = 0 ;
break;
case V_277 :
V_145 -> V_278 = true ;
break;
case V_279 :
V_145 -> V_278 = false ;
break;
case V_280 :
V_145 -> V_247 = 0 ;
break;
case V_281 :
V_145 -> V_247 = 1 ;
break;
case V_282 :
V_145 -> V_283 = 0 ;
break;
case V_284 :
V_145 -> V_283 = 1 ;
break;
case V_285 :
V_145 -> V_286 = 1 ;
break;
case V_287 :
V_145 -> V_286 = 0 ;
break;
case V_288 :
V_145 -> V_223 = 1 ;
break;
case V_289 :
V_145 -> V_223 = 0 ;
break;
case V_290 :
V_145 -> V_291 = 1 ;
break;
case V_292 :
V_145 -> V_293 = 1 ;
break;
case V_294 :
V_145 -> V_293 = 0 ;
break;
case V_295 :
V_145 -> V_296 = 0 ;
break;
case V_297 :
V_145 -> V_296 = 1 ;
break;
case V_298 :
V_145 -> V_299 = 1 ;
break;
case V_300 :
V_145 -> V_149 |= V_153 ;
break;
case V_301 :
V_145 -> V_302 = 1 ;
break;
case V_303 :
F_97 ( V_304 L_40
L_41
L_42 ) ;
break;
case V_305 :
#ifndef F_99
F_27 ( 1 , L_43
L_44 ) ;
goto V_226;
#endif
V_145 -> V_306 = true ;
break;
case V_307 :
V_145 -> V_308 = true ;
break;
case V_309 :
V_145 -> V_310 = true ;
break;
case V_311 :
V_205 = true ;
break;
case V_312 :
if ( F_76 ( args , & V_145 -> V_313 ) ) {
F_27 ( 1 , L_45 ,
V_20 ) ;
goto V_226;
}
V_145 -> V_228 = true ;
break;
case V_314 :
if ( F_80 ( args , & V_145 -> V_315 ) ) {
F_27 ( 1 , L_46 ,
V_20 ) ;
goto V_226;
}
V_145 -> V_229 = true ;
break;
case V_316 :
if ( F_76 ( args , & V_145 -> V_215 ) ) {
F_27 ( 1 , L_47 ,
V_20 ) ;
goto V_226;
}
V_203 = true ;
break;
case V_317 :
if ( F_76 ( args , & V_145 -> V_214 ) ) {
F_27 ( 1 , L_48 ,
V_20 ) ;
goto V_226;
}
break;
case V_318 :
if ( F_80 ( args , & V_145 -> V_216 ) ) {
F_27 ( 1 , L_49 ,
V_20 ) ;
goto V_226;
}
V_204 = true ;
break;
case V_319 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_50 ,
V_20 ) ;
goto V_226;
}
V_145 -> V_218 = V_139 ;
break;
case V_320 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_51 ,
V_20 ) ;
goto V_226;
}
V_145 -> V_217 = V_139 ;
break;
case V_321 :
if ( F_73 ( args , & V_139 ) ||
V_139 > V_322 ) {
F_27 ( 1 , L_52 , V_20 ) ;
goto V_226;
}
V_210 = ( unsigned short ) V_139 ;
break;
case V_323 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_53 ,
V_20 ) ;
goto V_226;
}
V_145 -> V_324 = V_139 ;
break;
case V_325 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_54 ,
V_20 ) ;
goto V_226;
}
V_145 -> V_326 = V_139 ;
break;
case V_327 :
if ( F_73 ( args , & V_139 ) ) {
F_27 ( 1 , L_55 ,
V_20 ) ;
goto V_226;
}
V_145 -> V_224 = V_52 * V_139 ;
if ( V_145 -> V_224 > V_328 ) {
F_27 ( 1 , L_56
L_57 ) ;
goto V_226;
}
break;
case V_329 :
V_145 -> V_167 = 1 ;
V_145 -> V_330 = NULL ;
break;
case V_331 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_231;
if ( F_94 ( string , V_332 ) >
V_332 ) {
F_97 ( V_304 L_58 ) ;
goto V_226;
}
V_145 -> V_330 = F_91 ( string , V_114 ) ;
if ( ! V_145 -> V_330 ) {
F_97 ( V_304 L_59
L_60 ) ;
goto V_226;
}
break;
case V_333 :
V_208 = strchr ( V_193 , '=' ) ;
V_208 ++ ;
if ( ! ( V_208 < V_194 && V_208 [ 1 ] == V_137 ) ) {
V_145 -> V_334 = NULL ;
break;
}
case V_335 :
V_141 = strchr ( V_193 , '=' ) ;
V_141 ++ ;
V_208 = ( char * ) V_141 + strlen ( V_141 ) ;
if ( V_208 < V_194 && V_208 [ 1 ] == V_137 ) {
V_208 [ 0 ] = V_137 ;
while ( ( V_208 = strchr ( V_208 , V_137 ) )
!= NULL && ( V_208 [ 1 ] == V_137 ) ) {
V_208 = ( char * ) & V_208 [ 2 ] ;
}
if ( V_208 ) {
V_208 [ 0 ] = '\0' ;
V_196 = ( char * ) & V_208 [ 1 ] ;
} else
V_196 = V_194 ;
}
V_197 = strlen ( V_141 ) ;
V_145 -> V_334 = F_100 ( V_197 + 1 , V_114 ) ;
if ( V_145 -> V_334 == NULL ) {
F_97 ( V_304 L_59
L_61 ) ;
goto V_226;
}
for ( V_198 = 0 , V_199 = 0 ; V_198 < V_197 ; V_198 ++ , V_199 ++ ) {
V_145 -> V_334 [ V_199 ] = V_141 [ V_198 ] ;
if ( ( V_141 [ V_198 ] == V_137 ) &&
V_141 [ V_198 + 1 ] == V_137 )
V_198 ++ ;
}
V_145 -> V_334 [ V_199 ] = '\0' ;
break;
case V_336 :
V_209 = false ;
break;
case V_337 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_231;
if ( ! F_101 ( V_94 , string ,
strlen ( string ) ) ) {
F_97 ( V_230 L_62 ,
string ) ;
goto V_226;
}
V_209 = true ;
break;
case V_338 :
string = V_145 -> V_190 ;
V_145 -> V_190 = F_74 ( args ) ;
if ( V_145 -> V_190 == NULL )
goto V_231;
F_90 ( V_145 -> V_190 , '\\' ) ;
if ( V_145 -> V_190 [ 0 ] != '\\' || V_145 -> V_190 [ 1 ] != '\\' ) {
F_97 ( V_230 L_63
L_64 ) ;
goto V_226;
}
if ( ! string || strcmp ( string , V_145 -> V_190 ) )
F_97 ( V_304 L_65
L_66
L_67
L_68
L_69
L_70
L_71 , string ,
V_145 -> V_190 ) ;
break;
case V_339 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_231;
if ( F_94 ( string , 256 ) == 256 ) {
F_97 ( V_304 L_72
L_73 ) ;
goto V_226;
}
V_145 -> V_340 = F_91 ( string , V_114 ) ;
if ( ! V_145 -> V_340 ) {
F_97 ( V_304 L_59
L_74 ) ;
goto V_226;
}
F_5 ( 1 , L_75 ) ;
break;
case V_341 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_231;
if ( ! F_101 (
(struct V_93 * ) & V_145 -> V_342 ,
string , strlen ( string ) ) ) {
F_97 ( V_304 L_76
L_77 , string ) ;
goto V_226;
}
break;
case V_343 :
if ( * args [ 0 ] . V_344 == '/' || * args [ 0 ] . V_344 == '\\' )
args [ 0 ] . V_344 ++ ;
string = V_145 -> V_191 ;
V_145 -> V_191 = F_74 ( args ) ;
if ( V_145 -> V_191 == NULL )
goto V_231;
if ( ! string || strcmp ( string , V_145 -> V_191 ) )
F_97 ( V_304 L_65
L_78
L_79
L_80
L_81
L_82
L_83 , string ,
V_145 -> V_191 ) ;
break;
case V_345 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_231;
if ( F_94 ( string , 1024 ) >= 65 ) {
F_97 ( V_304 L_84
L_85 ) ;
goto V_226;
}
if ( F_102 ( string , L_86 , 7 ) != 0 ) {
V_145 -> V_346 = F_91 ( string ,
V_114 ) ;
if ( ! V_145 -> V_346 ) {
F_97 ( V_304 L_87
L_88 ) ;
goto V_226;
}
}
F_5 ( 1 , L_89 , string ) ;
break;
case V_347 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_231;
memset ( V_145 -> V_211 , 0x20 ,
V_212 ) ;
for ( V_198 = 0 ; V_198 < V_212 ; V_198 ++ ) {
if ( string [ V_198 ] == 0 )
break;
V_145 -> V_211 [ V_198 ] = string [ V_198 ] ;
}
if ( V_198 == V_212 && string [ V_198 ] != 0 )
F_97 ( V_304 L_90
L_91 ) ;
break;
case V_348 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_231;
memset ( V_145 -> V_213 , 0x20 ,
V_349 ) ;
for ( V_198 = 0 ; V_198 < 15 ; V_198 ++ ) {
if ( string [ V_198 ] == 0 )
break;
V_145 -> V_213 [ V_198 ] = string [ V_198 ] ;
}
if ( V_198 == V_212 && string [ V_198 ] != 0 )
F_97 ( V_304 L_92
L_93 ) ;
break;
case V_350 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_231;
if ( F_102 ( string , L_94 , 1 ) == 0 ) {
break;
}
F_97 ( V_304 L_95
L_96 ) ;
goto V_226;
case V_351 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_231;
if ( F_87 ( string , V_145 ) != 0 )
goto V_226;
break;
case V_352 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_231;
if ( F_83 ( string , V_145 ) != 0 )
goto V_226;
break;
case V_353 :
string = F_74 ( args ) ;
if ( string == NULL )
goto V_231;
if ( F_86 ( string , V_145 ) != 0 )
goto V_226;
break;
default:
if ( ! V_206 )
V_206 = V_193 ;
break;
}
F_11 ( string ) ;
string = NULL ;
}
if ( ! V_205 && V_206 ) {
F_97 ( V_230 L_97 , V_206 ) ;
goto V_226;
}
#ifndef F_103
if ( V_145 -> V_310 ) {
F_27 ( 1 , L_98
L_99 ) ;
goto V_226;
}
#endif
if ( ! V_145 -> V_190 ) {
F_27 ( 1 , L_100
L_101 ) ;
goto V_226;
}
if ( ! strchr ( V_145 -> V_190 + 3 , '\\' ) ) {
F_27 ( 1 , L_102 ) ;
goto V_226;
}
if ( ! V_209 ) {
if ( ! F_101 ( V_94 , & V_145 -> V_190 [ 2 ] ,
strlen ( & V_145 -> V_190 [ 2 ] ) ) ) {
F_97 ( V_230 L_103
L_104 ) ;
goto V_226;
}
}
F_42 ( V_94 , V_210 ) ;
if ( V_203 )
V_145 -> V_201 = V_201 ;
else if ( V_201 == 1 )
F_97 ( V_354 L_105
L_106 ) ;
if ( V_204 )
V_145 -> V_202 = V_202 ;
else if ( V_202 == 1 )
F_97 ( V_354 L_107
L_108 ) ;
F_11 ( V_195 ) ;
return 0 ;
V_231:
F_97 ( V_304 L_109 ) ;
V_226:
F_11 ( string ) ;
F_11 ( V_195 ) ;
return 1 ;
}
static bool
F_104 ( struct V_93 * V_342 , struct V_93 * V_355 )
{
switch ( V_342 -> V_356 ) {
case V_357 :
return ( V_355 -> V_356 == V_357 ) ;
case V_358 : {
struct V_359 * V_360 = (struct V_359 * ) V_342 ;
struct V_359 * V_361 = (struct V_359 * ) V_355 ;
return ( V_360 -> V_362 . V_363 == V_361 -> V_362 . V_363 ) ;
}
case V_364 : {
struct V_365 * V_366 = (struct V_365 * ) V_342 ;
struct V_365 * V_367 = (struct V_365 * ) V_355 ;
return F_105 ( & V_366 -> V_368 , & V_367 -> V_368 ) ;
}
default:
F_106 ( 1 ) ;
return false ;
}
}
static bool
F_107 ( struct V_1 * V_2 , struct V_93 * V_369 )
{
T_5 V_210 , * V_370 ;
switch ( V_369 -> V_356 ) {
case V_358 :
V_370 = & ( (struct V_359 * ) & V_2 -> V_94 ) -> V_371 ;
V_210 = ( (struct V_359 * ) V_369 ) -> V_371 ;
break;
case V_364 :
V_370 = & ( (struct V_365 * ) & V_2 -> V_94 ) -> V_372 ;
V_210 = ( (struct V_365 * ) V_369 ) -> V_372 ;
break;
default:
F_106 ( 1 ) ;
return false ;
}
if ( ! V_210 ) {
V_210 = F_108 ( V_95 ) ;
if ( V_210 == * V_370 )
return true ;
V_210 = F_108 ( V_373 ) ;
}
return V_210 == * V_370 ;
}
static bool
F_109 ( struct V_1 * V_2 , struct V_93 * V_369 ,
struct V_93 * V_342 )
{
switch ( V_369 -> V_356 ) {
case V_358 : {
struct V_359 * V_374 = (struct V_359 * ) V_369 ;
struct V_359 * V_375 =
(struct V_359 * ) & V_2 -> V_94 ;
if ( V_374 -> V_362 . V_363 != V_375 -> V_362 . V_363 )
return false ;
break;
}
case V_364 : {
struct V_365 * V_376 = (struct V_365 * ) V_369 ;
struct V_365 * V_377 =
(struct V_365 * ) & V_2 -> V_94 ;
if ( ! F_105 ( & V_376 -> V_368 ,
& V_377 -> V_368 ) )
return false ;
if ( V_376 -> V_378 != V_377 -> V_378 )
return false ;
break;
}
default:
F_106 ( 1 ) ;
return false ;
}
if ( ! F_104 ( V_342 , (struct V_93 * ) & V_2 -> V_342 ) )
return false ;
return true ;
}
static bool
F_110 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
unsigned int V_379 ;
if ( V_145 -> V_149 & ( ~ ( V_153 | V_380 ) ) )
V_379 = V_145 -> V_149 ;
else
V_379 = V_381 | V_145 -> V_149 ;
switch ( V_2 -> V_382 ) {
case V_383 :
if ( ! ( V_379 & ( V_165 | V_384 ) ) )
return false ;
break;
case V_385 :
if ( ! ( V_379 & V_162 ) )
return false ;
break;
case V_386 :
if ( ! ( V_379 & V_159 ) )
return false ;
break;
case V_387 :
if ( ! ( V_379 & V_150 ) )
return false ;
break;
case V_388 :
if ( ! ( V_379 & V_156 ) )
return false ;
break;
default:
return false ;
}
if ( ( V_379 & V_151 ) == 0 &&
( V_2 -> V_389 & V_390 ) )
return false ;
else if ( ( ( V_379 & V_153 ) == V_153 ) &&
( V_2 -> V_389 &
( V_391 | V_390 ) ) == 0 )
return false ;
return true ;
}
static int F_111 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_93 * V_369 = (struct V_93 * ) & V_145 -> V_94 ;
if ( ( V_2 -> V_177 != V_145 -> V_177 ) || ( V_2 -> V_48 != V_145 -> V_48 ) )
return 0 ;
if ( ! F_112 ( F_113 ( V_2 ) , V_123 -> V_392 -> V_393 ) )
return 0 ;
if ( ! F_109 ( V_2 , V_369 ,
(struct V_93 * ) & V_145 -> V_342 ) )
return 0 ;
if ( ! F_107 ( V_2 , V_369 ) )
return 0 ;
if ( ! F_110 ( V_2 , V_145 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_114 ( struct V_144 * V_145 )
{
struct V_1 * V_2 ;
F_2 ( & V_21 ) ;
F_115 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_111 ( V_2 , V_145 ) )
continue;
++ V_2 -> V_394 ;
F_3 ( & V_21 ) ;
F_5 ( 1 , L_110 ) ;
return V_2 ;
}
F_3 ( & V_21 ) ;
return NULL ;
}
static void
F_116 ( struct V_1 * V_2 )
{
struct V_121 * V_395 ;
F_2 ( & V_21 ) ;
if ( -- V_2 -> V_394 > 0 ) {
F_3 ( & V_21 ) ;
return;
}
F_117 ( F_113 ( V_2 ) ) ;
F_16 ( & V_2 -> V_104 ) ;
F_3 ( & V_21 ) ;
F_118 ( & V_2 -> V_47 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_11 ( V_2 -> V_33 . V_34 ) ;
V_2 -> V_33 . V_34 = NULL ;
V_2 -> V_33 . V_35 = 0 ;
V_395 = F_66 ( & V_2 -> V_131 , NULL ) ;
if ( V_395 )
F_121 ( V_396 , V_395 ) ;
}
static struct V_1 *
F_122 ( struct V_144 * V_397 )
{
struct V_1 * V_398 = NULL ;
int V_3 ;
F_5 ( 1 , L_111 , V_397 -> V_190 ) ;
V_398 = F_114 ( V_397 ) ;
if ( V_398 )
return V_398 ;
V_398 = F_100 ( sizeof( struct V_1 ) , V_114 ) ;
if ( ! V_398 ) {
V_3 = - V_81 ;
goto V_399;
}
V_3 = F_123 ( V_398 ) ;
if ( V_3 ) {
F_27 ( 1 , L_112 , V_3 ) ;
goto V_399;
}
V_398 -> V_48 = V_397 -> V_48 ;
V_398 -> V_177 = V_397 -> V_177 ;
F_124 ( V_398 , F_125 ( V_123 -> V_392 -> V_393 ) ) ;
V_398 -> V_55 = F_71 ( V_397 -> V_190 ) ;
if ( F_126 ( V_398 -> V_55 ) ) {
V_3 = F_127 ( V_398 -> V_55 ) ;
goto V_400;
}
V_398 -> V_243 = V_397 -> V_243 ;
V_398 -> V_245 = V_397 -> V_245 ;
V_398 -> V_401 = V_397 -> V_402 ;
V_398 -> V_403 = 0 ;
V_398 -> V_106 = 1 ;
F_128 ( & V_398 -> V_61 ) ;
F_128 ( & V_398 -> V_107 ) ;
F_13 ( & V_398 -> V_108 ) ;
F_129 ( & V_398 -> V_26 ) ;
memcpy ( V_398 -> V_404 ,
V_397 -> V_211 , V_349 ) ;
memcpy ( V_398 -> V_405 ,
V_397 -> V_213 , V_349 ) ;
V_398 -> V_32 = false ;
V_398 -> V_31 = 0 ;
V_398 -> V_36 = V_37 ;
F_130 ( & V_398 -> V_105 ) ;
F_13 ( & V_398 -> V_104 ) ;
F_13 ( & V_398 -> V_22 ) ;
F_131 ( & V_398 -> V_47 , F_21 ) ;
memcpy ( & V_398 -> V_342 , & V_397 -> V_342 ,
sizeof( V_398 -> V_342 ) ) ;
memcpy ( & V_398 -> V_94 , & V_397 -> V_94 ,
sizeof( V_398 -> V_94 ) ) ;
V_398 -> V_15 = V_406 ;
++ V_398 -> V_394 ;
V_3 = F_132 ( V_398 ) ;
if ( V_3 < 0 ) {
F_27 ( 1 , L_113 ) ;
goto V_400;
}
F_133 ( V_407 ) ;
V_398 -> V_131 = F_134 ( F_57 ,
V_398 , L_114 ) ;
if ( F_126 ( V_398 -> V_131 ) ) {
V_3 = F_127 ( V_398 -> V_131 ) ;
F_27 ( 1 , L_115 , V_3 ) ;
F_135 ( V_407 ) ;
goto V_400;
}
V_398 -> V_15 = V_44 ;
F_2 ( & V_21 ) ;
F_136 ( & V_398 -> V_104 , & V_408 ) ;
F_3 ( & V_21 ) ;
F_137 ( V_398 ) ;
F_24 ( V_56 , & V_398 -> V_47 , V_51 ) ;
return V_398 ;
V_400:
F_119 ( V_398 ) ;
F_117 ( F_113 ( V_398 ) ) ;
V_399:
if ( V_398 ) {
if ( ! F_126 ( V_398 -> V_55 ) )
F_11 ( V_398 -> V_55 ) ;
if ( V_398 -> V_27 )
F_10 ( V_398 -> V_27 ) ;
F_11 ( V_398 ) ;
}
return F_72 ( V_3 ) ;
}
static int F_138 ( struct V_7 * V_8 , struct V_144 * V_145 )
{
switch ( V_8 -> V_2 -> V_382 ) {
case V_387 :
if ( ! F_139 ( V_145 -> V_214 , V_8 -> V_214 ) )
return 0 ;
break;
default:
if ( V_8 -> V_409 == NULL ) {
if ( ! V_145 -> V_167 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_409 ,
V_145 -> V_330 ? V_145 -> V_330 : L_116 ,
V_332 ) )
return 0 ;
if ( strlen ( V_145 -> V_330 ) != 0 &&
V_8 -> V_334 != NULL &&
strncmp ( V_8 -> V_334 ,
V_145 -> V_334 ? V_145 -> V_334 : L_116 ,
V_410 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_140 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_7 * V_8 ;
F_2 ( & V_21 ) ;
F_115 (ses, &server->smb_ses_list, smb_ses_list) {
if ( ! F_138 ( V_8 , V_145 ) )
continue;
++ V_8 -> V_411 ;
F_3 ( & V_21 ) ;
return V_8 ;
}
F_3 ( & V_21 ) ;
return NULL ;
}
static void
F_141 ( struct V_7 * V_8 )
{
unsigned int V_412 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( 1 , L_117 , V_20 , V_8 -> V_411 ) ;
F_2 ( & V_21 ) ;
if ( -- V_8 -> V_411 > 0 ) {
F_3 ( & V_21 ) ;
return;
}
F_16 ( & V_8 -> V_22 ) ;
F_3 ( & V_21 ) ;
if ( V_8 -> V_413 == V_60 && V_2 -> V_48 -> V_414 ) {
V_412 = F_142 () ;
V_2 -> V_48 -> V_414 ( V_412 , V_8 ) ;
F_143 ( V_412 ) ;
}
F_144 ( V_8 ) ;
F_116 ( V_2 ) ;
}
static int
F_145 ( struct V_144 * V_145 , struct V_7 * V_8 )
{
int V_3 = 0 ;
char * V_415 , * V_137 , * V_416 ;
T_6 V_35 ;
struct V_417 * V_417 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_359 * V_418 ;
struct V_365 * V_419 ;
struct V_420 * V_421 ;
V_415 = F_36 ( V_422 , V_114 ) ;
if ( ! V_415 )
return - V_81 ;
switch ( V_2 -> V_94 . V_423 ) {
case V_358 :
V_418 = (struct V_359 * ) & V_2 -> V_94 ;
sprintf ( V_415 , L_118 , & V_418 -> V_362 . V_363 ) ;
break;
case V_364 :
V_419 = (struct V_365 * ) & V_2 -> V_94 ;
sprintf ( V_415 , L_119 , & V_419 -> V_368 . V_424 ) ;
break;
default:
F_5 ( 1 , L_120 , V_2 -> V_94 . V_423 ) ;
V_3 = - V_138 ;
goto V_399;
}
F_5 ( 1 , L_121 , V_20 , V_415 ) ;
V_417 = F_146 ( & V_425 , V_415 , L_116 ) ;
if ( F_126 ( V_417 ) ) {
if ( ! V_8 -> V_426 ) {
F_5 ( 1 , L_122 ) ;
V_3 = F_127 ( V_417 ) ;
goto V_399;
}
sprintf ( V_415 , L_123 , V_8 -> V_426 ) ;
F_5 ( 1 , L_121 , V_20 , V_415 ) ;
V_417 = F_146 ( & V_425 , V_415 , L_116 ) ;
if ( F_126 ( V_417 ) ) {
V_3 = F_127 ( V_417 ) ;
goto V_399;
}
}
F_147 ( & V_417 -> V_427 ) ;
V_421 = V_417 -> V_416 . V_193 ;
if ( F_148 ( V_421 ) ) {
V_3 = V_421 ? F_127 ( V_421 ) : - V_138 ;
goto V_428;
}
V_416 = ( char * ) V_421 -> V_193 ;
V_137 = F_149 ( V_416 , V_421 -> V_429 , ':' ) ;
F_5 ( 1 , L_124 , V_416 ) ;
if ( ! V_137 ) {
F_5 ( 1 , L_125 ,
V_421 -> V_429 ) ;
V_3 = - V_138 ;
goto V_428;
}
V_35 = V_137 - V_416 ;
if ( V_35 > V_332 || V_35 <= 0 ) {
F_5 ( 1 , L_126 , V_35 ) ;
V_3 = - V_138 ;
goto V_428;
}
V_145 -> V_330 = F_89 ( V_416 , V_35 , V_114 ) ;
if ( ! V_145 -> V_330 ) {
F_5 ( 1 , L_127 , V_35 ) ;
V_3 = - V_81 ;
goto V_428;
}
F_5 ( 1 , L_128 , V_20 , V_145 -> V_330 ) ;
V_35 = V_417 -> V_429 - ( V_35 + 1 ) ;
if ( V_35 > V_410 || V_35 <= 0 ) {
F_5 ( 1 , L_129 , V_35 ) ;
V_3 = - V_138 ;
F_11 ( V_145 -> V_330 ) ;
V_145 -> V_330 = NULL ;
goto V_428;
}
++ V_137 ;
V_145 -> V_334 = F_89 ( V_137 , V_35 , V_114 ) ;
if ( ! V_145 -> V_334 ) {
F_5 ( 1 , L_130 , V_35 ) ;
V_3 = - V_81 ;
F_11 ( V_145 -> V_330 ) ;
V_145 -> V_330 = NULL ;
goto V_428;
}
V_428:
F_150 ( & V_417 -> V_427 ) ;
F_151 ( V_417 ) ;
V_399:
F_11 ( V_415 ) ;
F_5 ( 1 , L_131 , V_20 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_152 ( struct V_1 * V_2 , struct V_144 * V_397 )
{
int V_3 = - V_81 ;
unsigned int V_412 ;
struct V_7 * V_8 ;
struct V_359 * V_369 = (struct V_359 * ) & V_2 -> V_94 ;
struct V_365 * V_376 = (struct V_365 * ) & V_2 -> V_94 ;
V_412 = F_142 () ;
V_8 = F_140 ( V_2 , V_397 ) ;
if ( V_8 ) {
F_5 ( 1 , L_132 , V_8 -> V_413 ) ;
F_8 ( & V_8 -> V_430 ) ;
V_3 = F_153 ( V_412 , V_8 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_430 ) ;
F_141 ( V_8 ) ;
F_154 ( V_412 ) ;
return F_72 ( V_3 ) ;
}
if ( V_8 -> V_23 ) {
F_5 ( 1 , L_133 ) ;
V_3 = F_155 ( V_412 , V_8 ,
V_397 -> V_431 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_430 ) ;
F_141 ( V_8 ) ;
F_154 ( V_412 ) ;
return F_72 ( V_3 ) ;
}
}
F_12 ( & V_8 -> V_430 ) ;
F_116 ( V_2 ) ;
F_154 ( V_412 ) ;
return V_8 ;
}
F_5 ( 1 , L_134 ) ;
V_8 = F_156 () ;
if ( V_8 == NULL )
goto V_432;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_94 . V_423 == V_364 )
sprintf ( V_8 -> V_433 , L_135 , & V_376 -> V_368 ) ;
else
sprintf ( V_8 -> V_433 , L_136 , & V_369 -> V_362 ) ;
if ( V_397 -> V_330 ) {
V_8 -> V_409 = F_91 ( V_397 -> V_330 , V_114 ) ;
if ( ! V_8 -> V_409 )
goto V_432;
}
if ( V_397 -> V_334 ) {
V_8 -> V_334 = F_91 ( V_397 -> V_334 , V_114 ) ;
if ( ! V_8 -> V_334 )
goto V_432;
}
if ( V_397 -> V_340 ) {
V_8 -> V_426 = F_91 ( V_397 -> V_340 , V_114 ) ;
if ( ! V_8 -> V_426 )
goto V_432;
}
V_8 -> V_214 = V_397 -> V_214 ;
V_8 -> V_215 = V_397 -> V_215 ;
V_8 -> V_434 = V_397 -> V_149 ;
F_8 ( & V_8 -> V_430 ) ;
V_3 = F_153 ( V_412 , V_8 ) ;
if ( ! V_3 )
V_3 = F_155 ( V_412 , V_8 , V_397 -> V_431 ) ;
F_12 ( & V_8 -> V_430 ) ;
if ( V_3 )
goto V_432;
F_2 ( & V_21 ) ;
F_136 ( & V_8 -> V_22 , & V_2 -> V_22 ) ;
F_3 ( & V_21 ) ;
F_154 ( V_412 ) ;
return V_8 ;
V_432:
F_144 ( V_8 ) ;
F_154 ( V_412 ) ;
return F_72 ( V_3 ) ;
}
static int F_157 ( struct V_9 * V_10 , const char * V_134 )
{
if ( V_10 -> V_435 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_436 , V_134 , V_437 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_158 ( struct V_7 * V_8 , const char * V_134 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_21 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_25 ) ;
if ( ! F_157 ( V_10 , V_134 ) )
continue;
++ V_10 -> V_438 ;
F_3 ( & V_21 ) ;
return V_10 ;
}
F_3 ( & V_21 ) ;
return NULL ;
}
static void
F_159 ( struct V_9 * V_10 )
{
unsigned int V_412 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( 1 , L_137 , V_20 , V_10 -> V_438 ) ;
F_2 ( & V_21 ) ;
if ( -- V_10 -> V_438 > 0 ) {
F_3 ( & V_21 ) ;
return;
}
F_16 ( & V_10 -> V_25 ) ;
F_3 ( & V_21 ) ;
V_412 = F_142 () ;
if ( V_8 -> V_2 -> V_48 -> V_439 )
V_8 -> V_2 -> V_48 -> V_439 ( V_412 , V_10 ) ;
F_143 ( V_412 ) ;
F_160 ( V_10 ) ;
F_161 ( V_10 ) ;
F_141 ( V_8 ) ;
}
static struct V_9 *
F_162 ( struct V_7 * V_8 , struct V_144 * V_397 )
{
int V_3 , V_412 ;
struct V_9 * V_10 ;
V_10 = F_158 ( V_8 , V_397 -> V_190 ) ;
if ( V_10 ) {
F_5 ( 1 , L_138 ) ;
F_141 ( V_8 ) ;
if ( V_10 -> V_302 != V_397 -> V_302 )
F_27 ( 1 , L_139
L_140 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_48 -> V_440 ) {
V_3 = - V_54 ;
goto V_441;
}
V_10 = F_163 () ;
if ( V_10 == NULL ) {
V_3 = - V_81 ;
goto V_441;
}
V_10 -> V_8 = V_8 ;
if ( V_397 -> V_334 ) {
V_10 -> V_334 = F_91 ( V_397 -> V_334 , V_114 ) ;
if ( ! V_10 -> V_334 ) {
V_3 = - V_81 ;
goto V_441;
}
}
V_412 = F_142 () ;
V_3 = V_8 -> V_2 -> V_48 -> V_440 ( V_412 , V_8 , V_397 -> V_190 , V_10 ,
V_397 -> V_431 ) ;
F_154 ( V_412 ) ;
F_5 ( 1 , L_141 , V_3 ) ;
if ( V_3 )
goto V_441;
if ( V_397 -> V_259 ) {
V_10 -> V_442 &= ~ V_443 ;
F_5 ( 1 , L_142 , V_10 -> V_442 ) ;
}
V_10 -> V_302 = V_397 -> V_302 ;
V_10 -> V_247 = V_397 -> V_247 ;
V_10 -> V_265 = V_397 -> V_265 ;
V_10 -> V_299 = V_397 -> V_299 ;
F_13 ( & V_10 -> V_444 ) ;
F_2 ( & V_21 ) ;
F_136 ( & V_10 -> V_25 , & V_8 -> V_25 ) ;
F_3 ( & V_21 ) ;
F_164 ( V_10 ) ;
return V_10 ;
V_441:
F_161 ( V_10 ) ;
return F_72 ( V_3 ) ;
}
void
F_165 ( struct V_445 * V_446 )
{
if ( ! V_446 || F_126 ( V_446 ) )
return;
if ( ! F_166 ( & V_446 -> V_447 ) ||
F_167 ( V_448 , & V_446 -> V_449 ) ) {
V_446 -> V_450 = V_37 ;
return;
}
if ( ! F_126 ( F_168 ( V_446 ) ) )
F_159 ( F_168 ( V_446 ) ) ;
F_11 ( V_446 ) ;
return;
}
static inline struct V_445 *
F_169 ( struct V_451 * V_452 )
{
return V_452 -> V_453 ;
}
static int
F_170 ( struct V_454 * V_455 , struct V_456 * V_457 )
{
struct V_451 * V_458 = F_171 ( V_455 ) ;
struct V_451 * V_63 = V_457 -> V_452 ;
if ( ( V_455 -> V_459 & V_460 ) != ( V_457 -> V_29 & V_460 ) )
return 0 ;
if ( ( V_458 -> V_461 & V_462 ) !=
( V_63 -> V_461 & V_462 ) )
return 0 ;
if ( V_63 -> V_326 && V_63 -> V_326 < V_458 -> V_326 )
return 0 ;
if ( V_63 -> V_324 && V_63 -> V_324 < V_458 -> V_324 )
return 0 ;
if ( ! F_139 ( V_458 -> V_463 , V_63 -> V_463 ) || ! F_172 ( V_458 -> V_464 , V_63 -> V_464 ) )
return 0 ;
if ( V_458 -> V_465 != V_63 -> V_465 ||
V_458 -> V_466 != V_63 -> V_466 )
return 0 ;
if ( strcmp ( V_458 -> V_431 -> V_467 , V_63 -> V_431 -> V_467 ) )
return 0 ;
if ( V_458 -> V_224 != V_63 -> V_224 )
return 0 ;
return 1 ;
}
int
F_173 ( struct V_454 * V_455 , void * V_193 )
{
struct V_456 * V_457 = (struct V_456 * ) V_193 ;
struct V_144 * V_397 ;
struct V_451 * V_452 ;
struct V_1 * V_468 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_445 * V_446 ;
int V_3 = 0 ;
F_2 ( & V_21 ) ;
V_452 = F_171 ( V_455 ) ;
V_446 = F_174 ( F_169 ( V_452 ) ) ;
if ( F_126 ( V_446 ) ) {
F_3 ( & V_21 ) ;
return V_3 ;
}
V_10 = F_168 ( V_446 ) ;
V_8 = V_10 -> V_8 ;
V_468 = V_8 -> V_2 ;
V_397 = V_457 -> V_145 ;
if ( ! F_111 ( V_468 , V_397 ) ||
! F_138 ( V_8 , V_397 ) ||
! F_157 ( V_10 , V_397 -> V_190 ) ) {
V_3 = 0 ;
goto V_469;
}
V_3 = F_170 ( V_455 , V_457 ) ;
V_469:
F_3 ( & V_21 ) ;
F_165 ( V_446 ) ;
return V_3 ;
}
int
F_175 ( const unsigned int V_412 , struct V_7 * V_8 , const char * V_470 ,
const struct V_471 * V_472 , unsigned int * V_473 ,
struct V_474 * * V_475 , int V_253 )
{
char * V_476 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_48 -> V_440 || ! V_8 -> V_2 -> V_48 -> V_477 )
return - V_54 ;
* V_473 = 0 ;
* V_475 = NULL ;
if ( V_8 -> V_24 == 0 ) {
V_476 = F_36 ( 2 +
F_94 ( V_8 -> V_433 , V_478 * 2 )
+ 1 + 4 + 2 , V_114 ) ;
if ( V_476 == NULL )
return - V_81 ;
V_476 [ 0 ] = '\\' ;
V_476 [ 1 ] = '\\' ;
strcpy ( V_476 + 2 , V_8 -> V_433 ) ;
strcpy ( V_476 + 2 + strlen ( V_8 -> V_433 ) , L_143 ) ;
V_3 = V_8 -> V_2 -> V_48 -> V_440 ( V_412 , V_8 , V_476 , NULL ,
V_472 ) ;
F_5 ( 1 , L_144 , V_3 , V_8 -> V_24 ) ;
F_11 ( V_476 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_48 -> V_477 ( V_412 , V_8 , V_470 ,
V_475 , V_473 ,
V_472 , V_253 ) ;
return V_3 ;
}
static inline void
F_176 ( struct V_479 * V_480 )
{
struct V_480 * V_481 = V_480 -> V_481 ;
F_177 ( F_178 ( V_481 ) ) ;
F_179 ( V_481 , L_145 ,
& V_482 [ 0 ] , L_146 , & V_483 [ 0 ] ) ;
}
static inline void
F_180 ( struct V_479 * V_480 )
{
struct V_480 * V_481 = V_480 -> V_481 ;
F_177 ( F_178 ( V_481 ) ) ;
F_179 ( V_481 , L_147 ,
& V_482 [ 1 ] , L_148 , & V_483 [ 1 ] ) ;
}
static inline void
F_176 ( struct V_479 * V_480 )
{
}
static inline void
F_180 ( struct V_479 * V_480 )
{
}
static void F_181 ( char * V_484 , char * V_485 , unsigned int V_76 )
{
unsigned int V_198 , V_199 ;
for ( V_198 = 0 , V_199 = 0 ; V_198 < ( V_76 ) ; V_198 ++ ) {
V_484 [ V_199 ] = 'A' + ( 0x0F & ( V_485 [ V_198 ] >> 4 ) ) ;
V_484 [ V_199 + 1 ] = 'A' + ( 0x0F & V_485 [ V_198 ] ) ;
V_199 += 2 ;
}
}
static int
F_182 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_342 . V_423 != V_357 ) {
struct V_479 * V_479 = V_2 -> V_27 ;
V_3 = V_479 -> V_48 -> V_486 ( V_479 ,
(struct V_93 * ) & V_2 -> V_342 ,
sizeof( V_2 -> V_342 ) ) ;
if ( V_3 < 0 ) {
struct V_359 * V_360 ;
struct V_365 * V_366 ;
V_360 = (struct V_359 * ) & V_2 -> V_342 ;
V_366 = (struct V_365 * ) & V_2 -> V_342 ;
if ( V_366 -> V_487 == V_364 )
F_27 ( 1 , L_149
L_150 ,
& V_366 -> V_368 , V_3 ) ;
else
F_27 ( 1 , L_149
L_151 ,
& V_360 -> V_362 . V_363 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_183 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_488 * V_489 ;
struct V_490 * V_491 ;
V_489 = F_100 ( sizeof( struct V_488 ) ,
V_114 ) ;
if ( V_489 ) {
V_489 -> V_492 . V_493 . V_494 = 32 ;
if ( V_2 -> V_405 &&
V_2 -> V_405 [ 0 ] != 0 )
F_181 ( V_489 -> V_492 .
V_493 . V_495 ,
V_2 -> V_405 ,
V_349 ) ;
else
F_181 ( V_489 -> V_492 .
V_493 . V_495 ,
V_496 ,
V_349 ) ;
V_489 -> V_492 . V_493 . V_497 = 32 ;
if ( V_2 -> V_404 &&
V_2 -> V_404 [ 0 ] != 0 )
F_181 ( V_489 -> V_492 .
V_493 . V_498 ,
V_2 -> V_404 ,
V_349 ) ;
else
F_181 ( V_489 -> V_492 .
V_493 . V_498 ,
L_152 ,
V_349 ) ;
V_489 -> V_492 . V_493 . V_499 = 0 ;
V_489 -> V_492 . V_493 . V_500 = 0 ;
V_491 = (struct V_490 * ) V_489 ;
V_491 -> V_501 = F_184 ( 0x81000044 ) ;
V_3 = F_185 ( V_2 , V_491 , 0x44 ) ;
F_11 ( V_489 ) ;
F_39 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_370 ;
int V_502 , V_503 ;
struct V_479 * V_479 = V_2 -> V_27 ;
struct V_93 * V_504 ;
V_504 = (struct V_93 * ) & V_2 -> V_94 ;
if ( V_2 -> V_94 . V_423 == V_364 ) {
V_370 = ( (struct V_365 * ) V_504 ) -> V_372 ;
V_502 = sizeof( struct V_365 ) ;
V_503 = V_364 ;
} else {
V_370 = ( (struct V_359 * ) V_504 ) -> V_371 ;
V_502 = sizeof( struct V_359 ) ;
V_503 = V_358 ;
}
if ( V_479 == NULL ) {
V_3 = F_186 ( F_113 ( V_2 ) , V_503 , V_505 ,
V_506 , & V_479 , 1 ) ;
if ( V_3 < 0 ) {
F_27 ( 1 , L_153 , V_3 ) ;
V_2 -> V_27 = NULL ;
return V_3 ;
}
F_5 ( 1 , L_154 ) ;
V_2 -> V_27 = V_479 ;
V_479 -> V_481 -> V_507 = V_73 ;
if ( V_503 == V_364 )
F_180 ( V_479 ) ;
else
F_176 ( V_479 ) ;
}
V_3 = F_182 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_479 -> V_481 -> V_508 = 7 * V_52 ;
V_479 -> V_481 -> V_509 = 5 * V_52 ;
if ( V_2 -> V_245 ) {
if ( V_479 -> V_481 -> V_510 < ( 200 * 1024 ) )
V_479 -> V_481 -> V_510 = 200 * 1024 ;
if ( V_479 -> V_481 -> V_511 < ( 140 * 1024 ) )
V_479 -> V_481 -> V_511 = 140 * 1024 ;
}
if ( V_2 -> V_401 ) {
int V_512 = 1 ;
V_3 = F_187 ( V_479 , V_513 , V_514 ,
( char * ) & V_512 , sizeof( V_512 ) ) ;
if ( V_3 )
F_5 ( 1 , L_155 , V_3 ) ;
}
F_5 ( 1 , L_156 ,
V_479 -> V_481 -> V_510 ,
V_479 -> V_481 -> V_511 , V_479 -> V_481 -> V_508 ) ;
V_3 = V_479 -> V_48 -> V_515 ( V_479 , V_504 , V_502 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( 1 , L_157 , V_3 ) ;
F_10 ( V_479 ) ;
V_2 -> V_27 = NULL ;
return V_3 ;
}
if ( V_370 == F_108 ( V_373 ) )
V_3 = F_183 ( V_2 ) ;
return V_3 ;
}
static int
F_132 ( struct V_1 * V_2 )
{
T_5 * V_370 ;
struct V_365 * V_376 = (struct V_365 * ) & V_2 -> V_94 ;
struct V_359 * V_369 = (struct V_359 * ) & V_2 -> V_94 ;
if ( V_2 -> V_94 . V_423 == V_364 )
V_370 = & V_376 -> V_372 ;
else
V_370 = & V_369 -> V_371 ;
if ( * V_370 == 0 ) {
int V_3 ;
* V_370 = F_108 ( V_95 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_370 = F_108 ( V_373 ) ;
}
return F_18 ( V_2 ) ;
}
void F_188 ( unsigned int V_412 , struct V_9 * V_10 ,
struct V_451 * V_452 , struct V_144 * V_516 )
{
T_7 V_517 = F_189 ( V_10 -> V_518 . V_519 ) ;
if ( V_516 && V_516 -> V_263 ) {
V_10 -> V_518 . V_519 = 0 ;
V_10 -> V_520 = 0 ;
F_5 ( 1 , L_158 ) ;
return;
} else if ( V_516 )
V_10 -> V_520 = 1 ;
if ( V_10 -> V_520 == 0 ) {
F_5 ( 1 , L_159 ) ;
return;
}
if ( ! F_190 ( V_412 , V_10 ) ) {
T_7 V_521 = F_189 ( V_10 -> V_518 . V_519 ) ;
F_5 ( 1 , L_160 , V_521 ) ;
if ( V_516 == NULL ) {
if ( ( V_517 & V_522 ) == 0 )
V_521 &= ~ V_522 ;
if ( ( V_517 & V_523 ) == 0 ) {
if ( V_521 & V_523 )
F_27 ( 1 , L_161 ) ;
V_521 &= ~ V_523 ;
} else if ( ( V_521 & V_523 ) == 0 ) {
F_27 ( 1 , L_162 ) ;
F_27 ( 1 , L_163 ) ;
}
}
if ( V_521 & V_524 )
F_27 ( 1 , L_164 ) ;
V_521 &= V_525 ;
if ( V_516 && V_516 -> V_296 )
V_521 &= ~ V_522 ;
else if ( V_522 & V_521 ) {
F_5 ( 1 , L_165 ) ;
if ( V_452 )
V_452 -> V_461 |=
V_526 ;
}
if ( V_516 && V_516 -> V_222 == 0 )
V_521 &= ~ V_523 ;
else if ( V_521 & V_523 ) {
F_5 ( 1 , L_166 ) ;
if ( V_452 )
V_452 -> V_461 |=
V_527 ;
}
F_5 ( 1 , L_167 , ( int ) V_521 ) ;
#ifdef F_62
if ( V_521 & V_528 )
F_5 ( 1 , L_168 ) ;
if ( V_521 & V_529 )
F_5 ( 1 , L_169 ) ;
if ( V_521 & V_523 )
F_5 ( 1 , L_170 ) ;
if ( V_521 & V_530 )
F_5 ( 1 , L_171 ) ;
if ( V_521 & V_522 )
F_5 ( 1 , L_172 ) ;
if ( V_521 & V_531 )
F_5 ( 1 , L_173 ) ;
if ( V_521 & V_532 )
F_5 ( 1 , L_174 ) ;
if ( V_521 & V_533 )
F_5 ( 1 , L_175 ) ;
if ( V_521 & V_524 )
F_5 ( 1 , L_176 ) ;
#endif
if ( F_191 ( V_412 , V_10 , V_521 ) ) {
if ( V_516 == NULL ) {
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
void F_192 ( struct V_144 * V_534 ,
struct V_451 * V_452 )
{
F_131 ( & V_452 -> V_535 , V_536 ) ;
F_130 ( & V_452 -> V_537 ) ;
V_452 -> V_538 = V_539 ;
V_452 -> V_324 = V_534 -> V_324 ;
V_452 -> V_326 = V_534 -> V_326 ;
V_452 -> V_463 = V_534 -> V_215 ;
V_452 -> V_464 = V_534 -> V_216 ;
V_452 -> V_465 = V_534 -> V_218 ;
V_452 -> V_466 = V_534 -> V_217 ;
F_5 ( 1 , L_184 ,
V_452 -> V_465 , V_452 -> V_466 ) ;
V_452 -> V_224 = V_534 -> V_224 ;
V_452 -> V_431 = V_534 -> V_431 ;
if ( V_534 -> V_250 )
V_452 -> V_461 |= V_540 ;
if ( V_534 -> V_275 )
V_452 -> V_461 |= V_541 ;
if ( V_534 -> V_223 )
V_452 -> V_461 |= V_542 ;
if ( V_534 -> V_253 )
V_452 -> V_461 |= V_543 ;
if ( V_534 -> V_236 )
V_452 -> V_461 |= V_544 ;
if ( V_534 -> V_256 )
V_452 -> V_461 |= V_545 ;
if ( V_534 -> V_267 )
V_452 -> V_461 |= V_546 ;
if ( V_534 -> V_286 )
V_452 -> V_461 |= V_547 ;
if ( V_534 -> V_273 )
V_452 -> V_461 |= V_548 ;
if ( V_534 -> V_291 )
V_452 -> V_461 |= V_549 ;
if ( V_534 -> V_293 )
V_452 -> V_461 |= V_550 ;
if ( V_534 -> V_228 ) {
V_452 -> V_461 |= V_551 ;
V_452 -> V_552 = V_534 -> V_313 ;
}
if ( V_534 -> V_229 ) {
V_452 -> V_461 |= V_553 ;
V_452 -> V_554 = V_534 -> V_315 ;
}
if ( V_534 -> V_201 )
V_452 -> V_461 |= V_555 ;
if ( V_534 -> V_202 )
V_452 -> V_461 |= V_556 ;
if ( V_534 -> V_278 )
V_452 -> V_461 |= V_557 ;
if ( V_534 -> V_306 )
V_452 -> V_461 |= V_558 ;
if ( V_534 -> V_310 )
V_452 -> V_461 |= ( V_559 |
V_540 ) ;
if ( V_534 -> V_171 )
V_452 -> V_461 |= V_560 ;
if ( V_534 -> V_170 ) {
F_5 ( 1 , L_185 ) ;
V_452 -> V_461 |= V_561 ;
}
if ( V_534 -> V_308 ) {
if ( V_534 -> V_256 ) {
F_27 ( 1 , L_186
L_187 ) ;
} else {
V_452 -> V_461 |= V_562 ;
}
}
if ( ( V_534 -> V_293 ) && ( V_534 -> V_278 ) )
F_27 ( 1 , L_188
L_189 ) ;
}
static void
F_193 ( struct V_144 * V_397 )
{
F_11 ( V_397 -> V_330 ) ;
F_194 ( V_397 -> V_334 ) ;
F_11 ( V_397 -> V_190 ) ;
F_11 ( V_397 -> V_340 ) ;
F_11 ( V_397 -> V_346 ) ;
F_11 ( V_397 -> V_191 ) ;
}
void
F_195 ( struct V_144 * V_397 )
{
if ( ! V_397 )
return;
F_193 ( V_397 ) ;
F_11 ( V_397 ) ;
}
static char *
F_196 ( const struct V_144 * V_145 ,
const struct V_451 * V_452 )
{
char * V_563 , * V_188 ;
unsigned int V_564 = V_145 -> V_191 ? strlen ( V_145 -> V_191 ) + 1 : 0 ;
unsigned int V_565 = F_94 ( V_145 -> V_190 , V_437 + 1 ) ;
V_563 = F_36 ( V_565 + V_564 + 1 , V_114 ) ;
if ( V_563 == NULL )
return F_72 ( - V_81 ) ;
strncpy ( V_563 , V_145 -> V_190 , V_565 ) ;
V_188 = V_563 + V_565 ;
if ( V_564 ) {
* V_188 ++ = F_197 ( V_452 ) ;
strncpy ( V_188 , V_145 -> V_191 , V_564 ) ;
V_188 += V_564 ;
}
* V_188 = '\0' ;
F_90 ( V_563 , F_197 ( V_452 ) ) ;
F_5 ( 1 , L_190 , V_20 , V_563 ) ;
return V_563 ;
}
static int
F_198 ( const unsigned int V_412 , struct V_7 * V_8 ,
struct V_144 * V_397 , struct V_451 * V_452 ,
int V_566 )
{
int V_3 ;
unsigned int V_473 = 0 ;
struct V_474 * V_475 = NULL ;
char * V_563 = NULL , * V_567 = NULL , * V_568 = NULL ;
V_563 = F_196 ( V_397 , V_452 ) ;
if ( F_126 ( V_563 ) )
return F_127 ( V_563 ) ;
V_567 = V_566 ? V_563 + 1 : V_397 -> V_190 + 1 ;
V_3 = F_175 ( V_412 , V_8 , V_567 , V_452 -> V_431 ,
& V_473 , & V_475 ,
V_452 -> V_461 & V_543 ) ;
if ( ! V_3 && V_473 > 0 ) {
char * V_569 = NULL ;
V_568 = F_199 ( V_452 -> V_192 ,
V_563 + 1 , V_475 ,
& V_569 ) ;
F_200 ( V_475 , V_473 ) ;
if ( F_126 ( V_568 ) ) {
V_3 = F_127 ( V_568 ) ;
V_568 = NULL ;
} else {
F_193 ( V_397 ) ;
V_3 = F_201 ( V_397 , V_568 ,
V_569 ) ;
}
F_11 ( V_569 ) ;
F_11 ( V_452 -> V_192 ) ;
V_452 -> V_192 = V_568 ;
}
F_11 ( V_563 ) ;
return V_3 ;
}
static int
F_201 ( struct V_144 * V_397 , char * V_570 ,
const char * V_187 )
{
int V_3 = 0 ;
if ( F_92 ( V_570 , V_187 , V_397 ) )
return - V_138 ;
if ( V_397 -> V_167 ) {
F_5 ( 1 , L_191 ) ;
F_11 ( V_397 -> V_330 ) ;
V_397 -> V_330 = NULL ;
} else if ( V_397 -> V_330 ) {
F_5 ( 1 , L_192 , V_397 -> V_330 ) ;
} else {
F_202 ( L_193 ) ;
return - V_138 ;
}
if ( V_397 -> V_346 == NULL ) {
V_397 -> V_431 = F_203 () ;
} else {
V_397 -> V_431 = F_204 ( V_397 -> V_346 ) ;
if ( V_397 -> V_431 == NULL ) {
F_27 ( 1 , L_194 ,
V_397 -> V_346 ) ;
return - V_571 ;
}
}
return V_3 ;
}
struct V_144 *
F_205 ( char * V_570 , const char * V_187 )
{
int V_3 ;
struct V_144 * V_397 ;
V_397 = F_36 ( sizeof( struct V_144 ) , V_114 ) ;
if ( ! V_397 )
return F_72 ( - V_81 ) ;
V_3 = F_201 ( V_397 , V_570 , V_187 ) ;
if ( V_3 ) {
F_195 ( V_397 ) ;
V_397 = F_72 ( V_3 ) ;
}
return V_397 ;
}
int
F_206 ( struct V_451 * V_452 , struct V_144 * V_397 )
{
int V_3 ;
unsigned int V_412 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_563 ;
struct V_445 * V_446 ;
#ifdef F_207
int V_572 = 0 ;
#endif
V_3 = F_208 ( & V_452 -> V_573 , L_195 , V_574 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_207
V_575:
if ( V_572 ) {
if ( V_10 )
F_159 ( V_10 ) ;
else if ( V_8 )
F_141 ( V_8 ) ;
F_154 ( V_412 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_563 = NULL ;
V_446 = NULL ;
V_412 = F_142 () ;
V_2 = F_122 ( V_397 ) ;
if ( F_126 ( V_2 ) ) {
V_3 = F_127 ( V_2 ) ;
F_209 ( & V_452 -> V_573 ) ;
goto V_469;
}
V_8 = F_152 ( V_2 , V_397 ) ;
if ( F_126 ( V_8 ) ) {
V_3 = F_127 ( V_8 ) ;
V_8 = NULL ;
goto V_576;
}
V_10 = F_162 ( V_8 , V_397 ) ;
if ( F_126 ( V_10 ) ) {
V_3 = F_127 ( V_10 ) ;
V_10 = NULL ;
goto V_577;
}
if ( F_210 ( V_10 -> V_8 ) ) {
F_188 ( V_412 , V_10 , V_452 , V_397 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_189 ( V_10 -> V_518 . V_519 ) &
V_524 ) ) {
V_3 = - V_578 ;
goto V_576;
}
} else
V_10 -> V_520 = 0 ;
if ( ! V_10 -> V_579 && V_2 -> V_48 -> V_580 )
V_2 -> V_48 -> V_580 ( V_412 , V_10 ) ;
V_452 -> V_326 = V_2 -> V_48 -> V_581 ( V_10 , V_397 ) ;
V_452 -> V_324 = V_2 -> V_48 -> V_582 ( V_10 , V_397 ) ;
V_452 -> V_573 . V_583 = V_452 -> V_324 / V_584 ;
V_577:
#ifdef F_207
if ( V_572 == 0 ) {
int V_585 = F_198 ( V_412 , V_8 , V_397 , V_452 ,
false ) ;
if ( ! V_585 ) {
V_572 ++ ;
goto V_575;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_48 -> V_586 ) {
V_3 = - V_54 ;
goto V_576;
}
V_563 = F_211 ( V_397 , V_452 , V_10 ) ;
if ( V_563 == NULL ) {
V_3 = - V_81 ;
goto V_576;
}
V_3 = V_2 -> V_48 -> V_586 ( V_412 , V_10 , V_452 ,
V_563 ) ;
if ( V_3 != 0 && V_3 != - V_587 ) {
F_11 ( V_563 ) ;
goto V_576;
}
F_11 ( V_563 ) ;
}
if ( V_3 == - V_587 ) {
#ifdef F_207
if ( V_572 > V_588 ) {
V_3 = - V_589 ;
goto V_576;
}
V_3 = F_198 ( V_412 , V_8 , V_397 , V_452 , true ) ;
if ( ! V_3 ) {
V_572 ++ ;
goto V_575;
}
goto V_576;
#else
V_3 = - V_590 ;
#endif
}
if ( V_3 )
goto V_576;
V_446 = F_100 ( sizeof *V_446 , V_114 ) ;
if ( V_446 == NULL ) {
V_3 = - V_81 ;
goto V_576;
}
V_446 -> V_591 = V_8 -> V_215 ;
V_446 -> V_592 = V_10 ;
V_446 -> V_450 = V_37 ;
F_212 ( V_593 , & V_446 -> V_449 ) ;
F_212 ( V_448 , & V_446 -> V_449 ) ;
V_452 -> V_453 = V_446 ;
F_2 ( & V_452 -> V_537 ) ;
F_213 ( & V_452 -> V_538 , V_446 ) ;
F_3 ( & V_452 -> V_537 ) ;
F_24 ( V_56 , & V_452 -> V_535 ,
V_594 ) ;
V_576:
if ( V_3 ) {
if ( V_10 )
F_159 ( V_10 ) ;
else if ( V_8 )
F_141 ( V_8 ) ;
else
F_116 ( V_2 ) ;
F_209 ( & V_452 -> V_573 ) ;
}
V_469:
F_154 ( V_412 ) ;
return V_3 ;
}
int
F_214 ( const unsigned int V_412 , struct V_7 * V_8 ,
const char * V_595 , struct V_9 * V_10 ,
const struct V_471 * V_472 )
{
struct V_490 * V_596 ;
struct V_490 * V_597 ;
T_8 * V_598 ;
T_9 * V_599 ;
unsigned char * V_600 ;
int V_3 = 0 ;
int V_76 ;
T_10 V_601 , V_602 ;
if ( V_8 == NULL )
return - V_603 ;
V_596 = F_26 () ;
if ( V_596 == NULL )
return - V_81 ;
V_597 = V_596 ;
F_215 ( V_596 , V_604 ,
NULL , 4 ) ;
V_596 -> V_605 = F_216 ( V_8 -> V_2 ) ;
V_596 -> V_606 = V_8 -> V_607 ;
V_598 = ( T_8 * ) V_596 ;
V_599 = ( T_9 * ) V_597 ;
V_598 -> V_608 = 0xFF ;
V_598 -> V_442 = F_217 ( V_609 ) ;
V_600 = & V_598 -> V_610 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_389 & V_611 ) ) {
V_598 -> V_612 = F_217 ( 1 ) ;
* V_600 = 0 ;
V_600 ++ ;
} else {
V_598 -> V_612 = F_217 ( V_613 ) ;
#ifdef F_85
if ( ( V_381 & V_165 ) &&
( V_8 -> V_2 -> V_382 == V_383 ) )
F_218 ( V_10 -> V_334 , V_8 -> V_2 -> V_614 ,
V_8 -> V_2 -> V_389 &
V_615 ? true : false ,
V_600 ) ;
else
#endif
V_3 = F_219 ( V_10 -> V_334 , V_8 -> V_2 -> V_614 ,
V_600 , V_472 ) ;
V_600 += V_613 ;
if ( V_8 -> V_616 & V_617 ) {
* V_600 = 0 ;
V_600 ++ ;
}
}
if ( V_8 -> V_2 -> V_389 &
( V_390 | V_391 ) )
V_596 -> V_618 |= V_619 ;
if ( V_8 -> V_616 & V_620 ) {
V_596 -> V_618 |= V_621 ;
}
if ( V_8 -> V_616 & V_622 ) {
V_596 -> V_618 |= V_623 ;
}
if ( V_8 -> V_616 & V_617 ) {
V_596 -> V_618 |= V_624 ;
V_76 =
F_220 ( ( V_625 * ) V_600 , V_595 ,
6 *
( + 256 ) , V_472 ) ;
V_600 += 2 * V_76 ;
V_600 += 2 ;
} else {
strcpy ( V_600 , V_595 ) ;
V_600 += strlen ( V_595 ) + 1 ;
}
strcpy ( V_600 , L_196 ) ;
V_600 += strlen ( L_196 ) ;
V_600 += 1 ;
V_602 = V_600 - & V_598 -> V_610 [ 0 ] ;
V_598 -> V_626 . V_501 = F_184 ( F_221 (
V_598 -> V_626 . V_501 ) + V_602 ) ;
V_598 -> V_627 = F_217 ( V_602 ) ;
V_3 = F_222 ( V_412 , V_8 , V_596 , V_597 , & V_76 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_628 ;
V_10 -> V_435 = V_60 ;
V_10 -> V_23 = false ;
V_10 -> V_629 = V_597 -> V_630 ;
V_600 = F_223 ( V_597 ) ;
V_601 = F_224 ( V_597 ) ;
V_76 = F_94 ( V_600 , V_601 - 2 ) ;
if ( V_596 -> V_618 & V_624 )
V_628 = true ;
else
V_628 = false ;
if ( V_76 == 3 ) {
if ( ( V_600 [ 0 ] == 'I' ) && ( V_600 [ 1 ] == 'P' ) &&
( V_600 [ 2 ] == 'C' ) ) {
F_5 ( 1 , L_197 ) ;
V_10 -> V_579 = 1 ;
}
} else if ( V_76 == 2 ) {
if ( ( V_600 [ 0 ] == 'A' ) && ( V_600 [ 1 ] == ':' ) ) {
F_5 ( 1 , L_198 ) ;
}
}
V_600 += V_76 + 1 ;
V_601 -= ( V_76 + 1 ) ;
strncpy ( V_10 -> V_436 , V_595 , V_437 ) ;
F_11 ( V_10 -> V_631 ) ;
V_10 -> V_631 = F_225 ( V_600 ,
V_601 , V_628 ,
V_472 ) ;
F_5 ( 1 , L_199 , V_10 -> V_631 ) ;
if ( ( V_597 -> V_632 == 3 ) ||
( V_597 -> V_632 == 7 ) )
V_10 -> V_442 = F_226 ( V_599 -> V_633 ) ;
else
V_10 -> V_442 = 0 ;
F_5 ( 1 , L_200 , V_10 -> V_442 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_24 = V_597 -> V_630 ;
}
F_64 ( V_596 ) ;
return V_3 ;
}
void
F_227 ( struct V_451 * V_452 )
{
struct V_634 * V_635 = & V_452 -> V_538 ;
struct V_636 * V_637 ;
struct V_445 * V_446 ;
F_118 ( & V_452 -> V_535 ) ;
F_2 ( & V_452 -> V_537 ) ;
while ( ( V_637 = F_228 ( V_635 ) ) ) {
V_446 = F_229 ( V_637 , struct V_445 , V_638 ) ;
F_174 ( V_446 ) ;
F_230 ( V_448 , & V_446 -> V_449 ) ;
F_231 ( V_637 , V_635 ) ;
F_3 ( & V_452 -> V_537 ) ;
F_165 ( V_446 ) ;
F_2 ( & V_452 -> V_537 ) ;
}
F_3 ( & V_452 -> V_537 ) ;
F_209 ( & V_452 -> V_573 ) ;
F_11 ( V_452 -> V_192 ) ;
F_232 ( V_452 -> V_431 ) ;
F_11 ( V_452 ) ;
}
int
F_153 ( const unsigned int V_412 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_48 -> V_49 || ! V_2 -> V_48 -> V_639 )
return - V_54 ;
if ( ! V_2 -> V_48 -> V_49 ( V_2 ) )
return 0 ;
F_233 ( V_2 , 1 ) ;
V_3 = V_2 -> V_48 -> V_639 ( V_412 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_44 )
V_2 -> V_15 = V_60 ;
else
V_3 = - V_640 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_155 ( const unsigned int V_412 , struct V_7 * V_8 ,
struct V_471 * V_641 )
{
int V_3 = - V_54 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_29 = 0 ;
V_8 -> V_616 = V_2 -> V_616 ;
if ( V_642 == 0 )
V_8 -> V_616 &= ( ~ V_2 -> V_177 -> F_210 ) ;
F_5 ( 1 , L_201 ,
V_2 -> V_389 , V_2 -> V_616 , V_2 -> V_643 ) ;
if ( V_2 -> V_48 -> V_644 )
V_3 = V_2 -> V_48 -> V_644 ( V_412 , V_8 , V_641 ) ;
if ( V_3 ) {
F_27 ( 1 , L_202 , V_3 ) ;
} else {
F_8 ( & V_8 -> V_2 -> V_26 ) ;
if ( ! V_2 -> V_32 ) {
V_2 -> V_33 . V_34 = V_8 -> V_645 . V_34 ;
V_2 -> V_33 . V_35 = V_8 -> V_645 . V_35 ;
V_2 -> V_31 = 0x2 ;
V_2 -> V_32 = true ;
V_8 -> V_645 . V_34 = NULL ;
}
F_12 ( & V_2 -> V_26 ) ;
F_5 ( 1 , L_203 ) ;
F_2 ( & V_14 ) ;
V_8 -> V_413 = V_60 ;
V_8 -> V_23 = false ;
F_3 ( & V_14 ) ;
}
F_11 ( V_8 -> V_645 . V_34 ) ;
V_8 -> V_645 . V_34 = NULL ;
V_8 -> V_645 . V_35 = 0 ;
F_11 ( V_8 -> V_646 ) ;
V_8 -> V_646 = NULL ;
return V_3 ;
}
static int
F_234 ( struct V_144 * V_145 , struct V_7 * V_8 )
{
switch ( V_8 -> V_2 -> V_382 ) {
case V_387 :
V_145 -> V_149 = V_647 ;
return 0 ;
case V_385 :
V_145 -> V_149 = V_648 ;
break;
case V_386 :
V_145 -> V_149 = V_649 ;
break;
case V_388 :
V_145 -> V_149 = V_650 ;
break;
case V_383 :
V_145 -> V_149 = V_651 ;
break;
}
return F_145 ( V_145 , V_8 ) ;
}
static struct V_9 *
F_235 ( struct V_451 * V_452 , T_3 V_652 )
{
int V_3 ;
struct V_9 * V_653 = F_236 ( V_452 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_144 * V_516 ;
V_516 = F_100 ( sizeof( * V_516 ) , V_114 ) ;
if ( V_516 == NULL )
return F_72 ( - V_81 ) ;
V_516 -> V_431 = V_452 -> V_431 ;
V_516 -> V_215 = V_652 ;
V_516 -> V_214 = V_652 ;
V_516 -> V_190 = V_653 -> V_436 ;
V_516 -> V_247 = V_653 -> V_247 ;
V_516 -> V_265 = V_653 -> V_265 ;
V_516 -> V_299 = V_653 -> V_299 ;
V_516 -> V_263 = ! V_653 -> V_520 ;
V_3 = F_234 ( V_516 , V_653 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_72 ( V_3 ) ;
goto V_469;
}
F_2 ( & V_21 ) ;
++ V_653 -> V_8 -> V_2 -> V_394 ;
F_3 ( & V_21 ) ;
V_8 = F_152 ( V_653 -> V_8 -> V_2 , V_516 ) ;
if ( F_126 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_116 ( V_653 -> V_8 -> V_2 ) ;
goto V_469;
}
V_10 = F_162 ( V_8 , V_516 ) ;
if ( F_126 ( V_10 ) ) {
F_141 ( V_8 ) ;
goto V_469;
}
if ( F_210 ( V_8 ) )
F_188 ( 0 , V_10 , NULL , V_516 ) ;
V_469:
F_11 ( V_516 -> V_330 ) ;
F_11 ( V_516 -> V_334 ) ;
F_11 ( V_516 ) ;
return V_10 ;
}
struct V_9 *
F_236 ( struct V_451 * V_452 )
{
return F_168 ( F_169 ( V_452 ) ) ;
}
static int
F_237 ( void * V_654 )
{
F_69 () ;
return F_68 ( V_123 ) ? - V_86 : 0 ;
}
static struct V_445 *
F_238 ( struct V_634 * V_635 , T_3 V_142 )
{
struct V_636 * V_637 = V_635 -> V_636 ;
struct V_445 * V_446 ;
while ( V_637 ) {
V_446 = F_229 ( V_637 , struct V_445 , V_638 ) ;
if ( F_239 ( V_446 -> V_591 , V_142 ) )
V_637 = V_637 -> V_655 ;
else if ( F_240 ( V_446 -> V_591 , V_142 ) )
V_637 = V_637 -> V_656 ;
else
return V_446 ;
}
return NULL ;
}
static void
F_213 ( struct V_634 * V_635 , struct V_445 * V_657 )
{
struct V_636 * * V_63 = & ( V_635 -> V_636 ) , * V_658 = NULL ;
struct V_445 * V_446 ;
while ( * V_63 ) {
V_446 = F_229 ( * V_63 , struct V_445 , V_638 ) ;
V_658 = * V_63 ;
if ( F_239 ( V_446 -> V_591 , V_657 -> V_591 ) )
V_63 = & ( ( * V_63 ) -> V_655 ) ;
else
V_63 = & ( ( * V_63 ) -> V_656 ) ;
}
F_241 ( & V_657 -> V_638 , V_658 , V_63 ) ;
F_242 ( & V_657 -> V_638 , V_635 ) ;
}
struct V_445 *
F_243 ( struct V_451 * V_452 )
{
int V_659 ;
T_3 V_652 = F_244 () ;
struct V_445 * V_446 , * V_660 ;
if ( ! ( V_452 -> V_461 & V_559 ) )
return F_174 ( F_169 ( V_452 ) ) ;
F_2 ( & V_452 -> V_537 ) ;
V_446 = F_238 ( & V_452 -> V_538 , V_652 ) ;
if ( V_446 )
F_174 ( V_446 ) ;
F_3 ( & V_452 -> V_537 ) ;
if ( V_446 == NULL ) {
V_660 = F_100 ( sizeof( * V_446 ) , V_114 ) ;
if ( V_660 == NULL )
return F_72 ( - V_81 ) ;
V_660 -> V_591 = V_652 ;
V_660 -> V_592 = F_72 ( - V_578 ) ;
F_212 ( V_661 , & V_660 -> V_449 ) ;
F_212 ( V_448 , & V_660 -> V_449 ) ;
F_174 ( V_660 ) ;
F_2 ( & V_452 -> V_537 ) ;
V_446 = F_238 ( & V_452 -> V_538 , V_652 ) ;
if ( V_446 ) {
F_174 ( V_446 ) ;
F_3 ( & V_452 -> V_537 ) ;
F_11 ( V_660 ) ;
goto V_662;
}
V_446 = V_660 ;
F_213 ( & V_452 -> V_538 , V_446 ) ;
F_3 ( & V_452 -> V_537 ) ;
} else {
V_662:
V_659 = F_245 ( & V_446 -> V_449 , V_661 ,
F_237 ,
V_132 ) ;
if ( V_659 ) {
F_165 ( V_446 ) ;
return F_72 ( V_659 ) ;
}
if ( ! F_126 ( V_446 -> V_592 ) )
return V_446 ;
if ( F_23 ( V_37 , V_446 -> V_450 + V_663 ) ) {
F_165 ( V_446 ) ;
return F_72 ( - V_578 ) ;
}
if ( F_246 ( V_661 , & V_446 -> V_449 ) )
goto V_662;
}
V_446 -> V_592 = F_235 ( V_452 , V_652 ) ;
F_230 ( V_661 , & V_446 -> V_449 ) ;
F_247 ( & V_446 -> V_449 , V_661 ) ;
if ( F_126 ( V_446 -> V_592 ) ) {
F_165 ( V_446 ) ;
return F_72 ( - V_578 ) ;
}
return V_446 ;
}
static void
V_536 ( struct V_45 * V_46 )
{
struct V_451 * V_452 = F_22 ( V_46 , struct V_451 ,
V_535 . V_46 ) ;
struct V_634 * V_635 = & V_452 -> V_538 ;
struct V_636 * V_637 = F_228 ( V_635 ) ;
struct V_636 * V_5 ;
struct V_445 * V_446 ;
F_2 ( & V_452 -> V_537 ) ;
V_637 = F_228 ( V_635 ) ;
while ( V_637 != NULL ) {
V_5 = V_637 ;
V_637 = F_248 ( V_5 ) ;
V_446 = F_229 ( V_5 , struct V_445 , V_638 ) ;
if ( F_167 ( V_593 , & V_446 -> V_449 ) ||
F_61 ( & V_446 -> V_447 ) != 0 ||
F_31 ( V_446 -> V_450 + V_594 , V_37 ) )
continue;
F_174 ( V_446 ) ;
F_230 ( V_448 , & V_446 -> V_449 ) ;
F_231 ( V_5 , V_635 ) ;
F_3 ( & V_452 -> V_537 ) ;
F_165 ( V_446 ) ;
F_2 ( & V_452 -> V_537 ) ;
}
F_3 ( & V_452 -> V_537 ) ;
F_24 ( V_56 , & V_452 -> V_535 ,
V_594 ) ;
}
