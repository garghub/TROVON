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
F_12 ( & V_2 -> V_27 ) ;
F_13 ( & V_13 ) ;
F_5 ( V_20 , L_6 , V_21 ) ;
F_2 ( & V_14 ) ;
F_14 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_7 ( V_5 , struct V_11 , V_39 ) ;
if ( V_12 -> V_40 == V_41 )
V_12 -> V_40 = V_42 ;
F_15 ( & V_12 -> V_39 , & V_13 ) ;
}
F_3 ( & V_14 ) ;
F_5 ( V_20 , L_7 , V_21 ) ;
F_14 (tmp, tmp2, &retry_list) {
V_12 = F_7 ( V_5 , struct V_11 , V_39 ) ;
F_16 ( & V_12 -> V_39 ) ;
V_12 -> V_43 ( V_12 ) ;
}
do {
F_17 () ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 ) {
F_5 ( V_20 , L_8 , V_3 ) ;
F_19 ( 3000 ) ;
} else {
F_20 ( & V_44 ) ;
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 != V_16 )
V_2 -> V_15 = V_45 ;
F_3 ( & V_14 ) ;
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
if ( ! V_2 -> V_49 -> V_50 || V_2 -> V_49 -> V_50 ( V_2 ) ||
( V_2 -> V_49 -> V_51 && ! V_2 -> V_49 -> V_51 ( V_2 ) ) ||
F_23 ( V_38 , V_2 -> V_37 + V_52 - V_53 ) )
goto V_54;
V_3 = V_2 -> V_49 -> V_48 ? V_2 -> V_49 -> V_48 ( V_2 ) : - V_55 ;
if ( V_3 )
F_5 ( V_20 , L_9 ,
V_2 -> V_56 ) ;
V_54:
F_24 ( V_57 , & V_2 -> V_48 , V_52 ) ;
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
F_30 ( V_38 , V_2 -> V_37 + 2 * V_52 ) ) {
F_5 ( V_59 , L_12 ,
V_2 -> V_56 , ( 2 * V_52 ) / V_53 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
return true ;
}
return false ;
}
static unsigned int
F_32 ( struct V_64 * V_65 , struct V_64 * V_66 , unsigned int V_67 ,
T_1 V_68 )
{
T_1 V_69 = 0 ;
while ( V_68 || ! V_66 -> V_70 ) {
int V_71 = F_33 ( V_68 , V_66 -> V_70 ) ;
V_68 -= V_71 ;
V_69 += V_71 ;
if ( V_66 -> V_70 == V_69 ) {
V_66 ++ ;
V_67 -- ;
V_69 = 0 ;
}
}
memcpy ( V_65 , V_66 , sizeof( * V_66 ) * V_67 ) ;
V_65 -> V_72 += V_69 ;
V_65 -> V_70 -= V_69 ;
return V_67 ;
}
static struct V_64 *
F_34 ( struct V_1 * V_2 , unsigned int V_67 )
{
struct V_64 * V_73 ;
if ( V_2 -> V_66 && V_67 <= V_2 -> V_74 )
return V_2 -> V_66 ;
V_73 = F_35 ( sizeof( * V_73 ) * V_67 , V_75 ) ;
if ( V_73 ) {
F_11 ( V_2 -> V_66 ) ;
V_2 -> V_66 = V_73 ;
V_2 -> V_74 = V_67 ;
}
return V_73 ;
}
int
F_36 ( struct V_1 * V_2 , struct V_64 * V_76 ,
unsigned int V_67 , unsigned int V_77 )
{
int V_78 = 0 ;
int V_79 ;
unsigned int V_80 ;
struct V_81 V_82 ;
struct V_64 * V_66 ;
V_66 = F_34 ( V_2 , V_67 ) ;
if ( ! V_66 )
return - V_83 ;
V_82 . V_84 = NULL ;
V_82 . V_85 = 0 ;
for ( V_79 = 0 ; V_77 ; V_79 += V_78 , V_77 -= V_78 ) {
F_17 () ;
if ( F_29 ( V_2 ) ) {
V_79 = - V_86 ;
break;
}
V_80 = F_32 ( V_66 , V_76 , V_67 , V_79 ) ;
V_78 = F_37 ( V_2 -> V_28 , & V_82 ,
V_66 , V_80 , V_77 , 0 ) ;
if ( V_2 -> V_15 == V_16 ) {
V_79 = - V_87 ;
break;
} else if ( V_2 -> V_15 == V_17 ) {
F_1 ( V_2 ) ;
V_79 = - V_86 ;
break;
} else if ( V_78 == - V_88 ||
V_78 == - V_86 ||
V_78 == - V_89 ) {
F_38 ( 1000 , 2000 ) ;
V_78 = 0 ;
continue;
} else if ( V_78 <= 0 ) {
F_5 ( V_20 , L_13
L_14 , V_77 , V_78 ) ;
F_1 ( V_2 ) ;
V_79 = - V_86 ;
break;
}
}
return V_79 ;
}
int
F_39 ( struct V_1 * V_2 , char * V_90 ,
unsigned int V_77 )
{
struct V_64 V_66 ;
V_66 . V_72 = V_90 ;
V_66 . V_70 = V_77 ;
return F_36 ( V_2 , & V_66 , 1 , V_77 ) ;
}
static bool
F_40 ( struct V_1 * V_2 , unsigned char type )
{
switch ( type ) {
case V_91 :
return true ;
case V_92 :
F_5 ( V_20 , L_15 ) ;
break;
case V_93 :
F_5 ( V_20 , L_16 ) ;
break;
case V_94 :
F_5 ( V_20 , L_17 ) ;
F_19 ( 1000 ) ;
F_41 ( (struct V_95 * ) & V_2 -> V_96 , V_97 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
break;
default:
F_5 ( V_59 , L_18 , type ) ;
F_1 ( V_2 ) ;
}
return false ;
}
void
F_42 ( struct V_11 * V_98 , bool V_99 )
{
#ifdef F_43
V_98 -> V_100 = V_38 ;
#endif
F_2 ( & V_14 ) ;
if ( ! V_99 )
V_98 -> V_40 = V_101 ;
else
V_98 -> V_40 = V_102 ;
F_16 ( & V_98 -> V_39 ) ;
F_3 ( & V_14 ) ;
}
static void
F_44 ( struct V_11 * V_98 , struct V_1 * V_2 ,
char * V_90 , int V_99 )
{
if ( V_2 -> V_49 -> V_103 &&
V_2 -> V_49 -> V_103 ( V_98 , V_2 , V_90 , V_99 ) )
return;
V_98 -> V_104 = V_90 ;
V_98 -> V_60 = V_2 -> V_60 ;
if ( ! V_98 -> V_105 ) {
if ( V_2 -> V_60 )
V_2 -> V_58 = NULL ;
else
V_2 -> V_61 = NULL ;
}
F_42 ( V_98 , V_99 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_78 ;
F_2 ( & V_22 ) ;
F_16 ( & V_2 -> V_106 ) ;
F_3 ( & V_22 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_46 ( & V_2 -> V_63 ) ;
F_2 ( & V_2 -> V_107 ) ;
if ( V_2 -> V_108 <= 0 )
V_2 -> V_108 = 1 ;
F_3 ( & V_2 -> V_107 ) ;
F_46 ( & V_2 -> V_109 ) ;
F_19 ( 125 ) ;
if ( V_2 -> V_28 ) {
F_10 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
}
if ( ! F_47 ( & V_2 -> V_110 ) ) {
struct V_4 V_111 ;
struct V_11 * V_12 ;
struct V_4 * V_5 , * V_6 ;
F_13 ( & V_111 ) ;
F_2 ( & V_14 ) ;
F_14 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_7 ( V_5 , struct V_11 , V_39 ) ;
F_5 ( V_20 , L_19 , V_12 -> V_98 ) ;
V_12 -> V_40 = V_112 ;
F_15 ( & V_12 -> V_39 , & V_111 ) ;
}
F_3 ( & V_14 ) ;
F_14 (tmp, tmp2, &dispose_list) {
V_12 = F_7 ( V_5 , struct V_11 , V_39 ) ;
F_5 ( V_20 , L_20 , V_12 -> V_98 ) ;
F_16 ( & V_12 -> V_39 ) ;
V_12 -> V_43 ( V_12 ) ;
}
F_19 ( 125 ) ;
}
if ( ! F_47 ( & V_2 -> V_110 ) ) {
F_5 ( V_20 , L_21 ) ;
F_19 ( 46000 ) ;
}
F_11 ( V_2 -> V_56 ) ;
F_11 ( V_2 -> V_66 ) ;
F_11 ( V_2 ) ;
V_78 = F_48 ( & V_113 ) ;
if ( V_78 > 0 )
F_49 ( V_114 , V_78 + V_115 ,
V_116 ) ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_11 * V_98 )
{
int V_78 ;
char * V_90 = V_2 -> V_61 ;
unsigned int V_117 = F_51 ( V_90 ) ;
if ( V_117 > V_118 + F_52 ( V_2 ) - 4 ) {
F_5 ( V_59 , L_22 , V_117 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
return - V_86 ;
}
if ( V_117 > V_119 - 4 ) {
V_2 -> V_60 = true ;
memcpy ( V_2 -> V_58 , V_90 , V_2 -> V_79 ) ;
V_90 = V_2 -> V_58 ;
}
V_78 = F_39 ( V_2 , V_90 + F_27 ( V_2 ) - 1 ,
V_117 - F_27 ( V_2 ) + 1 + 4 ) ;
if ( V_78 < 0 )
return V_78 ;
V_2 -> V_79 += V_78 ;
F_53 ( V_90 , V_2 -> V_79 ) ;
V_78 = V_2 -> V_49 -> V_120 ( V_90 , V_2 -> V_79 ) ;
if ( V_78 != 0 )
F_54 ( L_23 , V_90 ,
F_55 (unsigned int, server->total_read, 48 ) ) ;
if ( V_2 -> V_49 -> V_121 &&
V_2 -> V_49 -> V_121 ( V_90 , V_2 , V_78 ) )
return - 1 ;
if ( ! V_98 )
return V_78 ;
F_44 ( V_98 , V_2 , V_90 , V_78 ) ;
return 0 ;
}
static int
F_56 ( void * V_122 )
{
int V_78 ;
struct V_1 * V_2 = V_122 ;
unsigned int V_117 ;
char * V_90 = NULL ;
struct V_123 * V_124 = NULL ;
struct V_11 * V_12 ;
V_125 -> V_30 |= V_126 ;
F_5 ( V_20 , L_24 , F_57 ( V_125 ) ) ;
V_78 = F_58 ( & V_113 ) ;
if ( V_78 > 1 )
F_49 ( V_114 , V_78 + V_115 ,
V_116 ) ;
F_59 () ;
while ( V_2 -> V_15 != V_16 ) {
if ( F_17 () )
continue;
if ( ! F_25 ( V_2 ) )
continue;
V_2 -> V_60 = false ;
V_90 = V_2 -> V_61 ;
V_117 = 4 ;
V_78 = F_39 ( V_2 , V_90 , V_117 ) ;
if ( V_78 < 0 )
continue;
V_2 -> V_79 = V_78 ;
V_117 = F_51 ( V_90 ) ;
F_5 ( V_20 , L_25 , V_117 ) ;
if ( ! F_40 ( V_2 , V_90 [ 0 ] ) )
continue;
if ( V_117 < F_27 ( V_2 ) - 1 - 4 ) {
F_5 ( V_59 , L_26 ,
V_117 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
continue;
}
V_78 = F_39 ( V_2 , V_90 + 4 ,
F_27 ( V_2 ) - 1 - 4 ) ;
if ( V_78 < 0 )
continue;
V_2 -> V_79 += V_78 ;
V_12 = V_2 -> V_49 -> V_127 ( V_2 , V_90 ) ;
if ( ! V_12 || ! V_12 -> V_128 )
V_78 = F_50 ( V_2 , V_12 ) ;
else
V_78 = V_12 -> V_128 ( V_2 , V_12 ) ;
if ( V_78 < 0 )
continue;
if ( V_2 -> V_60 )
V_90 = V_2 -> V_58 ;
V_2 -> V_37 = V_38 ;
if ( V_12 != NULL ) {
if ( ! V_12 -> V_105 || V_12 -> V_129 )
V_12 -> V_43 ( V_12 ) ;
} else if ( ! V_2 -> V_49 -> V_130 ||
! V_2 -> V_49 -> V_130 ( V_90 , V_2 ) ) {
F_5 ( V_59 , L_27 ,
F_60 ( & V_131 ) ) ;
F_54 ( L_28 , V_90 ,
F_27 ( V_2 ) ) ;
#ifdef F_61
if ( V_2 -> V_49 -> V_132 )
V_2 -> V_49 -> V_132 ( V_90 ) ;
F_62 ( V_2 ) ;
#endif
}
}
F_63 ( V_2 -> V_58 ) ;
if ( V_2 -> V_61 )
F_64 ( V_2 -> V_61 ) ;
V_124 = F_65 ( & V_2 -> V_133 , NULL ) ;
F_45 ( V_2 ) ;
if ( ! V_124 ) {
F_66 ( V_134 ) ;
while ( ! F_67 ( V_125 ) ) {
F_68 () ;
F_66 ( V_134 ) ;
}
F_66 ( V_135 ) ;
}
F_69 ( 0 ) ;
}
static char *
F_70 ( const char * V_136 )
{
const char * V_137 ;
char * V_138 , * V_139 ;
unsigned int V_36 ;
V_137 = V_136 + 2 ;
V_139 = strchr ( V_137 , '\\' ) ;
if ( ! V_139 )
return F_71 ( - V_140 ) ;
V_36 = V_139 - V_137 ;
V_138 = F_35 ( ( V_36 + 1 ) , V_116 ) ;
if ( V_138 == NULL )
return F_71 ( - V_83 ) ;
memcpy ( V_138 , V_137 , V_36 ) ;
V_138 [ V_36 ] = '\0' ;
return V_138 ;
}
static int F_72 ( T_2 args [] , unsigned long * V_141 )
{
int V_3 ;
char * string ;
string = F_73 ( args ) ;
if ( string == NULL )
return - V_83 ;
V_3 = F_74 ( string , 0 , V_141 ) ;
F_11 ( string ) ;
return V_3 ;
}
static int F_75 ( T_2 args [] , T_3 * V_142 )
{
unsigned long V_143 ;
T_3 V_144 ;
int V_3 ;
V_3 = F_72 ( args , & V_143 ) ;
if ( V_3 )
return V_3 ;
V_144 = F_76 ( F_77 () , V_143 ) ;
if ( ! F_78 ( V_144 ) )
return - V_140 ;
* V_142 = V_144 ;
return 0 ;
}
static int F_79 ( T_2 args [] , T_4 * V_142 )
{
unsigned long V_143 ;
T_4 V_145 ;
int V_3 ;
V_3 = F_72 ( args , & V_143 ) ;
if ( V_3 )
return V_3 ;
V_145 = F_80 ( F_77 () , V_143 ) ;
if ( ! F_81 ( V_145 ) )
return - V_140 ;
* V_142 = V_145 ;
return 0 ;
}
static int F_82 ( char * V_143 ,
struct V_146 * V_147 )
{
T_2 args [ V_148 ] ;
V_147 -> V_149 = V_150 ;
V_147 -> V_151 = false ;
switch ( F_83 ( V_143 , V_152 , args ) ) {
case V_153 :
F_5 ( V_59 , L_29 ) ;
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
#ifdef F_84
case V_166 :
V_147 -> V_149 = V_167 ;
break;
#endif
case V_168 :
V_147 -> V_169 = 1 ;
break;
default:
F_5 ( V_59 , L_30 , V_143 ) ;
return 1 ;
}
return 0 ;
}
static int
F_85 ( char * V_143 , struct V_146 * V_147 )
{
T_2 args [ V_148 ] ;
switch ( F_83 ( V_143 , V_170 , args ) ) {
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
F_5 ( V_59 , L_31 , V_143 ) ;
return 1 ;
}
return 0 ;
}
static int
F_86 ( char * V_143 , struct V_146 * V_147 )
{
T_2 args [ V_148 ] ;
switch ( F_83 ( V_143 , V_176 , args ) ) {
case V_177 :
V_147 -> V_49 = & V_178 ;
V_147 -> V_179 = & V_180 ;
break;
#ifdef F_4
case V_181 :
V_147 -> V_49 = & V_182 ;
V_147 -> V_179 = & V_183 ;
break;
case V_184 :
V_147 -> V_49 = & V_182 ;
V_147 -> V_179 = & V_185 ;
break;
case V_186 :
V_147 -> V_49 = & V_187 ;
V_147 -> V_179 = & V_188 ;
break;
case V_189 :
V_147 -> V_49 = & V_187 ;
V_147 -> V_179 = & V_190 ;
break;
#endif
default:
F_5 ( V_59 , L_32 , V_143 ) ;
return 1 ;
}
return 0 ;
}
static int
F_87 ( const char * V_191 , struct V_146 * V_147 )
{
char * V_192 ;
const char * V_193 = L_33 ;
T_1 V_36 ;
V_36 = strspn ( V_191 , V_193 ) ;
if ( V_36 != 2 )
return - V_140 ;
V_192 = strpbrk ( V_191 + 2 , V_193 ) ;
if ( ! V_192 )
return - V_140 ;
++ V_192 ;
V_36 = strcspn ( V_192 , V_193 ) ;
V_192 += V_36 ;
V_147 -> V_194 = F_88 ( V_191 , V_192 - V_191 , V_116 ) ;
if ( ! V_147 -> V_194 )
return - V_83 ;
F_89 ( V_147 -> V_194 , '\\' ) ;
if ( ! * V_192 ++ || ! * V_192 )
return 0 ;
V_147 -> V_195 = F_90 ( V_192 , V_116 ) ;
if ( ! V_147 -> V_195 )
return - V_83 ;
return 0 ;
}
static int
F_91 ( const char * V_196 , const char * V_191 ,
struct V_146 * V_147 )
{
char * V_197 , * V_198 ;
char * V_199 = NULL , * V_200 ;
unsigned int V_201 , V_202 , V_203 ;
char V_204 [ 2 ] ;
short int V_205 = - 1 ;
short int V_206 = - 1 ;
bool V_207 = false ;
bool V_208 = false ;
bool V_209 = false ;
char * V_210 = NULL ;
char * V_211 = F_92 () -> V_211 ;
char * string = NULL ;
char * V_212 , * V_143 ;
char V_139 ;
bool V_213 = false ;
unsigned short V_214 = 0 ;
struct V_95 * V_96 = (struct V_95 * ) & V_147 -> V_96 ;
V_204 [ 0 ] = ',' ;
V_204 [ 1 ] = 0 ;
V_139 = V_204 [ 0 ] ;
memset ( V_147 , 0 , sizeof( * V_147 ) ) ;
memset ( V_147 -> V_215 , 0x20 , V_216 ) ;
for ( V_202 = 0 ; V_202 < F_93 ( V_211 , V_216 ) ; V_202 ++ )
V_147 -> V_215 [ V_202 ] = toupper ( V_211 [ V_202 ] ) ;
V_147 -> V_215 [ V_216 ] = 0 ;
V_147 -> V_217 [ 0 ] = 0 ;
V_147 -> V_218 = F_94 () ;
V_147 -> V_219 = F_94 () ;
V_147 -> V_220 = F_95 () ;
V_147 -> V_221 = V_147 -> V_222 = V_223 | V_224 | V_225 ;
V_147 -> V_226 = 1 ;
V_147 -> V_227 = 1 ;
V_147 -> V_173 = true ;
V_147 -> V_228 = V_229 ;
V_147 -> V_49 = & V_178 ;
V_147 -> V_179 = & V_180 ;
if ( ! V_196 )
goto V_230;
V_199 = F_88 ( V_196 , V_231 , V_116 ) ;
if ( ! V_199 )
goto V_230;
V_200 = V_199 ;
V_198 = V_200 + strlen ( V_200 ) ;
if ( strncmp ( V_200 , L_34 , 4 ) == 0 ) {
if ( V_200 [ 4 ] != 0 ) {
V_204 [ 0 ] = V_200 [ 4 ] ;
V_200 += 5 ;
} else {
F_5 ( V_20 , L_35 ) ;
}
}
V_147 -> V_232 = false ;
V_147 -> V_233 = false ;
switch ( F_87 ( V_191 , V_147 ) ) {
case 0 :
break;
case - V_83 :
F_5 ( V_59 , L_36 ) ;
goto V_230;
case - V_140 :
F_5 ( V_59 , L_37 ) ;
goto V_230;
default:
F_5 ( V_59 , L_38 ) ;
goto V_230;
}
while ( ( V_197 = F_96 ( & V_200 , V_204 ) ) != NULL ) {
T_2 args [ V_148 ] ;
unsigned long V_141 ;
int V_234 ;
if ( ! * V_197 )
continue;
V_234 = F_83 ( V_197 , V_235 , args ) ;
switch ( V_234 ) {
case V_236 :
break;
case V_237 :
V_147 -> V_238 = 0 ;
break;
case V_239 :
V_147 -> V_238 = 1 ;
break;
case V_240 :
V_205 = 1 ;
break;
case V_241 :
V_205 = 0 ;
break;
case V_242 :
V_206 = 1 ;
break;
case V_243 :
V_206 = 0 ;
break;
case V_244 :
V_147 -> V_245 = 1 ;
break;
case V_246 :
V_147 -> V_247 = 1 ;
break;
case V_248 :
V_147 -> V_249 = 1 ;
break;
case V_250 :
V_147 -> V_249 = 0 ;
break;
case V_251 :
V_147 -> V_252 = 0 ;
break;
case V_253 :
V_147 -> V_252 = 1 ;
break;
case V_254 :
V_147 -> V_255 = 1 ;
break;
case V_256 :
V_147 -> V_255 = 0 ;
break;
case V_257 :
V_147 -> V_258 = 1 ;
break;
case V_259 :
V_147 -> V_258 = 0 ;
break;
case V_260 :
V_147 -> V_261 = 1 ;
break;
case V_262 :
V_147 -> V_226 = 1 ;
break;
case V_263 :
V_147 -> V_226 = 0 ;
break;
case V_264 :
V_147 -> V_265 = 1 ;
break;
case V_266 :
V_147 -> V_267 = 1 ;
break;
case V_268 :
V_147 -> V_269 = 0 ;
break;
case V_270 :
V_147 -> V_269 = 1 ;
if ( V_147 -> V_222 ==
( V_271 & ~ ( V_272 | V_273 ) ) )
V_147 -> V_222 = V_271 ;
break;
case V_274 :
V_147 -> V_275 = 1 ;
break;
case V_276 :
V_147 -> V_277 = 1 ;
break;
case V_278 :
V_147 -> V_277 = 0 ;
break;
case V_279 :
V_147 -> V_280 = true ;
break;
case V_281 :
V_147 -> V_280 = false ;
break;
case V_282 :
V_147 -> V_249 = 0 ;
break;
case V_283 :
V_147 -> V_249 = 1 ;
break;
case V_284 :
V_147 -> V_285 = 0 ;
break;
case V_286 :
V_147 -> V_285 = 1 ;
break;
case V_287 :
V_147 -> V_288 = 1 ;
break;
case V_289 :
V_147 -> V_288 = 0 ;
break;
case V_290 :
V_147 -> V_227 = 1 ;
break;
case V_291 :
V_147 -> V_227 = 0 ;
break;
case V_292 :
V_147 -> V_293 = 1 ;
break;
case V_294 :
V_147 -> V_295 = 1 ;
break;
case V_296 :
V_147 -> V_295 = 0 ;
break;
case V_297 :
V_147 -> V_298 = 0 ;
break;
case V_299 :
V_147 -> V_298 = 1 ;
break;
case V_300 :
V_147 -> V_301 = 1 ;
break;
case V_302 :
V_147 -> V_151 = true ;
break;
case V_303 :
V_147 -> V_304 = 1 ;
break;
case V_305 :
F_97 ( V_306 L_39
L_40
L_41 ) ;
break;
case V_307 :
#ifndef F_98
F_5 ( V_59 , L_42 ) ;
goto V_230;
#endif
V_147 -> V_308 = true ;
break;
case V_309 :
V_147 -> V_310 = true ;
break;
case V_311 :
V_147 -> V_312 = true ;
break;
case V_313 :
V_209 = true ;
break;
case V_314 :
V_147 -> V_315 = true ;
break;
case V_316 :
if ( F_75 ( args , & V_147 -> V_317 ) ) {
F_5 ( V_59 , L_43 ,
V_21 ) ;
goto V_230;
}
V_147 -> V_232 = true ;
break;
case V_318 :
if ( F_79 ( args , & V_147 -> V_319 ) ) {
F_5 ( V_59 , L_44 ,
V_21 ) ;
goto V_230;
}
V_147 -> V_233 = true ;
break;
case V_320 :
if ( F_75 ( args , & V_147 -> V_219 ) ) {
F_5 ( V_59 , L_45 ,
V_21 ) ;
goto V_230;
}
V_207 = true ;
break;
case V_321 :
if ( F_75 ( args , & V_147 -> V_218 ) ) {
F_5 ( V_59 , L_46 ,
V_21 ) ;
goto V_230;
}
break;
case V_322 :
if ( F_79 ( args , & V_147 -> V_220 ) ) {
F_5 ( V_59 , L_47 ,
V_21 ) ;
goto V_230;
}
V_208 = true ;
break;
case V_323 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_48 ,
V_21 ) ;
goto V_230;
}
V_147 -> V_222 = V_141 ;
break;
case V_324 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_49 ,
V_21 ) ;
goto V_230;
}
V_147 -> V_221 = V_141 ;
break;
case V_325 :
if ( F_72 ( args , & V_141 ) ||
V_141 > V_326 ) {
F_5 ( V_59 , L_50 ,
V_21 ) ;
goto V_230;
}
V_214 = ( unsigned short ) V_141 ;
break;
case V_327 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_51 ,
V_21 ) ;
goto V_230;
}
V_147 -> V_328 = V_141 ;
break;
case V_329 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_52 ,
V_21 ) ;
goto V_230;
}
V_147 -> V_330 = V_141 ;
break;
case V_331 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_53 ,
V_21 ) ;
goto V_230;
}
V_147 -> V_228 = V_53 * V_141 ;
if ( V_147 -> V_228 > V_332 ) {
F_5 ( V_59 , L_54 ) ;
goto V_230;
}
break;
case V_333 :
V_147 -> V_169 = 1 ;
V_147 -> V_334 = NULL ;
break;
case V_335 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_336;
if ( F_93 ( string , V_337 ) >
V_337 ) {
F_97 ( V_306 L_55 ) ;
goto V_230;
}
V_147 -> V_334 = F_90 ( string , V_116 ) ;
if ( ! V_147 -> V_334 )
goto V_230;
break;
case V_338 :
V_212 = strchr ( V_197 , '=' ) ;
V_212 ++ ;
if ( ! ( V_212 < V_198 && V_212 [ 1 ] == V_139 ) ) {
V_147 -> V_339 = NULL ;
break;
}
case V_340 :
V_143 = strchr ( V_197 , '=' ) ;
V_143 ++ ;
V_212 = ( char * ) V_143 + strlen ( V_143 ) ;
if ( V_212 < V_198 && V_212 [ 1 ] == V_139 ) {
V_212 [ 0 ] = V_139 ;
while ( ( V_212 = strchr ( V_212 , V_139 ) )
!= NULL && ( V_212 [ 1 ] == V_139 ) ) {
V_212 = ( char * ) & V_212 [ 2 ] ;
}
if ( V_212 ) {
V_212 [ 0 ] = '\0' ;
V_200 = ( char * ) & V_212 [ 1 ] ;
} else
V_200 = V_198 ;
}
V_201 = strlen ( V_143 ) ;
V_147 -> V_339 = F_99 ( V_201 + 1 , V_116 ) ;
if ( V_147 -> V_339 == NULL ) {
F_97 ( V_306 L_56
L_57 ) ;
goto V_230;
}
for ( V_202 = 0 , V_203 = 0 ; V_202 < V_201 ; V_202 ++ , V_203 ++ ) {
V_147 -> V_339 [ V_203 ] = V_143 [ V_202 ] ;
if ( ( V_143 [ V_202 ] == V_139 ) &&
V_143 [ V_202 + 1 ] == V_139 )
V_202 ++ ;
}
V_147 -> V_339 [ V_203 ] = '\0' ;
break;
case V_341 :
V_213 = false ;
break;
case V_342 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_336;
if ( ! F_100 ( V_96 , string ,
strlen ( string ) ) ) {
F_97 ( V_343 L_58 ,
string ) ;
goto V_230;
}
V_213 = true ;
break;
case V_344 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_336;
if ( F_93 ( string , V_345 )
== V_345 ) {
F_97 ( V_306 L_59
L_60 ) ;
goto V_230;
}
V_147 -> V_346 = F_90 ( string , V_116 ) ;
if ( ! V_147 -> V_346 ) {
F_97 ( V_306 L_56
L_61 ) ;
goto V_230;
}
F_5 ( V_20 , L_62 ) ;
break;
case V_347 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_336;
if ( ! F_100 (
(struct V_95 * ) & V_147 -> V_348 ,
string , strlen ( string ) ) ) {
F_97 ( V_306 L_63
L_64 , string ) ;
goto V_230;
}
break;
case V_349 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_336;
if ( F_93 ( string , 1024 ) >= 65 ) {
F_97 ( V_306 L_65
L_66 ) ;
goto V_230;
}
if ( F_101 ( string , L_67 , 7 ) != 0 ) {
V_147 -> V_350 = F_90 ( string ,
V_116 ) ;
if ( ! V_147 -> V_350 ) {
F_97 ( V_306 L_68
L_69 ) ;
goto V_230;
}
}
F_5 ( V_20 , L_70 , string ) ;
break;
case V_351 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_336;
memset ( V_147 -> V_215 , 0x20 ,
V_216 ) ;
for ( V_202 = 0 ; V_202 < V_216 ; V_202 ++ ) {
if ( string [ V_202 ] == 0 )
break;
V_147 -> V_215 [ V_202 ] = string [ V_202 ] ;
}
if ( V_202 == V_216 && string [ V_202 ] != 0 )
F_97 ( V_306 L_71
L_72 ) ;
break;
case V_352 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_336;
memset ( V_147 -> V_217 , 0x20 ,
V_353 ) ;
for ( V_202 = 0 ; V_202 < 15 ; V_202 ++ ) {
if ( string [ V_202 ] == 0 )
break;
V_147 -> V_217 [ V_202 ] = string [ V_202 ] ;
}
if ( V_202 == V_216 && string [ V_202 ] != 0 )
F_97 ( V_306 L_73
L_74 ) ;
break;
case V_354 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_336;
if ( F_101 ( string , L_75 , 1 ) == 0 ) {
break;
}
F_97 ( V_306 L_76
L_77 ) ;
goto V_230;
case V_355 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_336;
if ( F_86 ( string , V_147 ) != 0 )
goto V_230;
break;
case V_356 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_336;
if ( F_82 ( string , V_147 ) != 0 )
goto V_230;
break;
case V_357 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_336;
if ( F_85 ( string , V_147 ) != 0 )
goto V_230;
break;
default:
if ( ! V_210 )
V_210 = V_197 ;
break;
}
F_11 ( string ) ;
string = NULL ;
}
if ( ! V_209 && V_210 ) {
F_97 ( V_343 L_78 , V_210 ) ;
goto V_230;
}
#ifndef F_102
if ( V_147 -> V_312 ) {
F_5 ( V_59 , L_79 ) ;
goto V_230;
}
#endif
if ( ! V_147 -> V_194 ) {
F_5 ( V_59 , L_80 ) ;
goto V_230;
}
if ( ! strchr ( V_147 -> V_194 + 3 , '\\' ) ) {
F_5 ( V_59 , L_81 ) ;
goto V_230;
}
if ( ! V_213 ) {
if ( ! F_100 ( V_96 , & V_147 -> V_194 [ 2 ] ,
strlen ( & V_147 -> V_194 [ 2 ] ) ) ) {
F_97 ( V_343 L_82
L_83 ) ;
goto V_230;
}
}
F_41 ( V_96 , V_214 ) ;
if ( V_207 )
V_147 -> V_205 = V_205 ;
else if ( V_205 == 1 )
F_97 ( V_358 L_84
L_85 ) ;
if ( V_208 )
V_147 -> V_206 = V_206 ;
else if ( V_206 == 1 )
F_97 ( V_358 L_86
L_87 ) ;
F_11 ( V_199 ) ;
return 0 ;
V_336:
F_97 ( V_306 L_88 ) ;
V_230:
F_11 ( string ) ;
F_11 ( V_199 ) ;
return 1 ;
}
static bool
F_103 ( struct V_95 * V_348 , struct V_95 * V_359 )
{
switch ( V_348 -> V_360 ) {
case V_361 :
return ( V_359 -> V_360 == V_361 ) ;
case V_362 : {
struct V_363 * V_364 = (struct V_363 * ) V_348 ;
struct V_363 * V_365 = (struct V_363 * ) V_359 ;
return ( V_364 -> V_366 . V_367 == V_365 -> V_366 . V_367 ) ;
}
case V_368 : {
struct V_369 * V_370 = (struct V_369 * ) V_348 ;
struct V_369 * V_371 = (struct V_369 * ) V_359 ;
return F_104 ( & V_370 -> V_372 , & V_371 -> V_372 ) ;
}
default:
F_105 ( 1 ) ;
return false ;
}
}
static bool
F_106 ( struct V_1 * V_2 , struct V_95 * V_373 )
{
T_5 V_214 , * V_374 ;
switch ( V_373 -> V_360 ) {
case V_362 :
V_374 = & ( (struct V_363 * ) & V_2 -> V_96 ) -> V_375 ;
V_214 = ( (struct V_363 * ) V_373 ) -> V_375 ;
break;
case V_368 :
V_374 = & ( (struct V_369 * ) & V_2 -> V_96 ) -> V_376 ;
V_214 = ( (struct V_369 * ) V_373 ) -> V_376 ;
break;
default:
F_105 ( 1 ) ;
return false ;
}
if ( ! V_214 ) {
V_214 = F_107 ( V_97 ) ;
if ( V_214 == * V_374 )
return true ;
V_214 = F_107 ( V_377 ) ;
}
return V_214 == * V_374 ;
}
static bool
F_108 ( struct V_1 * V_2 , struct V_95 * V_373 ,
struct V_95 * V_348 )
{
switch ( V_373 -> V_360 ) {
case V_362 : {
struct V_363 * V_378 = (struct V_363 * ) V_373 ;
struct V_363 * V_379 =
(struct V_363 * ) & V_2 -> V_96 ;
if ( V_378 -> V_366 . V_367 != V_379 -> V_366 . V_367 )
return false ;
break;
}
case V_368 : {
struct V_369 * V_380 = (struct V_369 * ) V_373 ;
struct V_369 * V_381 =
(struct V_369 * ) & V_2 -> V_96 ;
if ( ! F_104 ( & V_380 -> V_372 ,
& V_381 -> V_372 ) )
return false ;
if ( V_380 -> V_382 != V_381 -> V_382 )
return false ;
break;
}
default:
F_105 ( 1 ) ;
return false ;
}
if ( ! F_103 ( V_348 , (struct V_95 * ) & V_2 -> V_348 ) )
return false ;
return true ;
}
static bool
F_109 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
if ( F_110 ( V_2 , V_147 -> V_149 ) == V_150 )
return false ;
if ( V_147 -> V_151 && ! V_2 -> V_151 )
return false ;
return true ;
}
static int F_111 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_95 * V_373 = (struct V_95 * ) & V_147 -> V_96 ;
if ( V_147 -> V_315 )
return 0 ;
if ( ( V_2 -> V_179 != V_147 -> V_179 ) || ( V_2 -> V_49 != V_147 -> V_49 ) )
return 0 ;
if ( ! F_112 ( F_113 ( V_2 ) , V_125 -> V_383 -> V_384 ) )
return 0 ;
if ( ! F_108 ( V_2 , V_373 ,
(struct V_95 * ) & V_147 -> V_348 ) )
return 0 ;
if ( ! F_106 ( V_2 , V_373 ) )
return 0 ;
if ( ! F_109 ( V_2 , V_147 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_114 ( struct V_146 * V_147 )
{
struct V_1 * V_2 ;
F_2 ( & V_22 ) ;
F_115 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_111 ( V_2 , V_147 ) )
continue;
++ V_2 -> V_385 ;
F_3 ( & V_22 ) ;
F_5 ( V_20 , L_89 ) ;
return V_2 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_116 ( struct V_1 * V_2 )
{
struct V_123 * V_386 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_385 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_117 ( F_113 ( V_2 ) ) ;
F_16 ( & V_2 -> V_106 ) ;
F_3 ( & V_22 ) ;
F_118 ( & V_2 -> V_48 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_11 ( V_2 -> V_34 . V_35 ) ;
V_2 -> V_34 . V_35 = NULL ;
V_2 -> V_34 . V_36 = 0 ;
V_386 = F_65 ( & V_2 -> V_133 , NULL ) ;
if ( V_386 )
F_121 ( V_387 , V_386 ) ;
}
static struct V_1 *
F_122 ( struct V_146 * V_388 )
{
struct V_1 * V_389 = NULL ;
int V_3 ;
F_5 ( V_20 , L_90 , V_388 -> V_194 ) ;
V_389 = F_114 ( V_388 ) ;
if ( V_389 )
return V_389 ;
V_389 = F_99 ( sizeof( struct V_1 ) , V_116 ) ;
if ( ! V_389 ) {
V_3 = - V_83 ;
goto V_390;
}
V_389 -> V_49 = V_388 -> V_49 ;
V_389 -> V_179 = V_388 -> V_179 ;
F_123 ( V_389 , F_124 ( V_125 -> V_383 -> V_384 ) ) ;
V_389 -> V_56 = F_70 ( V_388 -> V_194 ) ;
if ( F_125 ( V_389 -> V_56 ) ) {
V_3 = F_126 ( V_389 -> V_56 ) ;
goto V_391;
}
V_389 -> V_245 = V_388 -> V_245 ;
V_389 -> V_247 = V_388 -> V_247 ;
V_389 -> V_392 = V_388 -> V_393 ;
V_389 -> V_394 = 0 ;
V_389 -> V_108 = 1 ;
F_127 ( & V_389 -> V_63 ) ;
F_127 ( & V_389 -> V_109 ) ;
F_13 ( & V_389 -> V_110 ) ;
F_128 ( & V_389 -> V_27 ) ;
memcpy ( V_389 -> V_395 ,
V_388 -> V_215 , V_353 ) ;
memcpy ( V_389 -> V_396 ,
V_388 -> V_217 , V_353 ) ;
V_389 -> V_33 = false ;
V_389 -> V_32 = 0 ;
V_389 -> V_37 = V_38 ;
F_129 ( & V_389 -> V_107 ) ;
F_13 ( & V_389 -> V_106 ) ;
F_13 ( & V_389 -> V_23 ) ;
F_130 ( & V_389 -> V_48 , F_21 ) ;
memcpy ( & V_389 -> V_348 , & V_388 -> V_348 ,
sizeof( V_389 -> V_348 ) ) ;
memcpy ( & V_389 -> V_96 , & V_388 -> V_96 ,
sizeof( V_389 -> V_96 ) ) ;
V_389 -> V_15 = V_397 ;
++ V_389 -> V_385 ;
V_3 = F_131 ( V_389 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_91 ) ;
goto V_391;
}
F_132 ( V_398 ) ;
V_389 -> V_133 = F_133 ( F_56 ,
V_389 , L_92 ) ;
if ( F_125 ( V_389 -> V_133 ) ) {
V_3 = F_126 ( V_389 -> V_133 ) ;
F_5 ( V_59 , L_93 , V_3 ) ;
F_134 ( V_398 ) ;
goto V_391;
}
V_389 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_135 ( & V_389 -> V_106 , & V_399 ) ;
F_3 ( & V_22 ) ;
F_136 ( V_389 ) ;
F_24 ( V_57 , & V_389 -> V_48 , V_52 ) ;
return V_389 ;
V_391:
F_119 ( V_389 ) ;
F_117 ( F_113 ( V_389 ) ) ;
V_390:
if ( V_389 ) {
if ( ! F_125 ( V_389 -> V_56 ) )
F_11 ( V_389 -> V_56 ) ;
if ( V_389 -> V_28 )
F_10 ( V_389 -> V_28 ) ;
F_11 ( V_389 ) ;
}
return F_71 ( V_3 ) ;
}
static int F_137 ( struct V_7 * V_8 , struct V_146 * V_147 )
{
if ( V_147 -> V_149 != V_150 &&
V_147 -> V_149 != V_8 -> V_149 )
return 0 ;
switch ( V_8 -> V_149 ) {
case V_156 :
if ( ! F_138 ( V_147 -> V_218 , V_8 -> V_218 ) )
return 0 ;
break;
default:
if ( V_8 -> V_400 == NULL ) {
if ( ! V_147 -> V_169 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_400 ,
V_147 -> V_334 ? V_147 -> V_334 : L_94 ,
V_337 ) )
return 0 ;
if ( strlen ( V_147 -> V_334 ) != 0 &&
V_8 -> V_339 != NULL &&
strncmp ( V_8 -> V_339 ,
V_147 -> V_339 ? V_147 -> V_339 : L_94 ,
V_401 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_139 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_7 * V_8 ;
F_2 ( & V_22 ) ;
F_115 (ses, &server->smb_ses_list, smb_ses_list) {
if ( ! F_137 ( V_8 , V_147 ) )
continue;
++ V_8 -> V_402 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_140 ( struct V_7 * V_8 )
{
unsigned int V_403 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_20 , L_95 , V_21 , V_8 -> V_402 ) ;
F_2 ( & V_22 ) ;
if ( -- V_8 -> V_402 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_8 -> V_23 ) ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_404 == V_62 && V_2 -> V_49 -> V_405 ) {
V_403 = F_141 () ;
V_2 -> V_49 -> V_405 ( V_403 , V_8 ) ;
F_142 ( V_403 ) ;
}
F_143 ( V_8 ) ;
F_116 ( V_2 ) ;
}
static int
F_144 ( struct V_146 * V_147 , struct V_7 * V_8 )
{
int V_3 = 0 ;
char * V_406 , * V_139 , * V_407 ;
T_6 V_36 ;
struct V_408 * V_408 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_363 * V_409 ;
struct V_369 * V_410 ;
struct V_411 * V_412 ;
V_406 = F_35 ( V_413 , V_116 ) ;
if ( ! V_406 )
return - V_83 ;
switch ( V_2 -> V_96 . V_414 ) {
case V_362 :
V_409 = (struct V_363 * ) & V_2 -> V_96 ;
sprintf ( V_406 , L_96 , & V_409 -> V_366 . V_367 ) ;
break;
case V_368 :
V_410 = (struct V_369 * ) & V_2 -> V_96 ;
sprintf ( V_406 , L_97 , & V_410 -> V_372 . V_415 ) ;
break;
default:
F_5 ( V_20 , L_98 ,
V_2 -> V_96 . V_414 ) ;
V_3 = - V_140 ;
goto V_390;
}
F_5 ( V_20 , L_99 , V_21 , V_406 ) ;
V_408 = F_145 ( & V_416 , V_406 , L_94 ) ;
if ( F_125 ( V_408 ) ) {
if ( ! V_8 -> V_417 ) {
F_5 ( V_20 , L_100 ) ;
V_3 = F_126 ( V_408 ) ;
goto V_390;
}
sprintf ( V_406 , L_101 , V_8 -> V_417 ) ;
F_5 ( V_20 , L_99 , V_21 , V_406 ) ;
V_408 = F_145 ( & V_416 , V_406 , L_94 ) ;
if ( F_125 ( V_408 ) ) {
V_3 = F_126 ( V_408 ) ;
goto V_390;
}
}
F_146 ( & V_408 -> V_418 ) ;
V_412 = V_408 -> V_407 . V_197 ;
if ( F_147 ( V_412 ) ) {
V_3 = V_412 ? F_126 ( V_412 ) : - V_140 ;
goto V_419;
}
V_407 = ( char * ) V_412 -> V_197 ;
V_139 = F_148 ( V_407 , V_412 -> V_420 , ':' ) ;
F_5 ( V_20 , L_102 , V_407 ) ;
if ( ! V_139 ) {
F_5 ( V_20 , L_103 ,
V_412 -> V_420 ) ;
V_3 = - V_140 ;
goto V_419;
}
V_36 = V_139 - V_407 ;
if ( V_36 > V_337 || V_36 <= 0 ) {
F_5 ( V_20 , L_104 ,
V_36 ) ;
V_3 = - V_140 ;
goto V_419;
}
V_147 -> V_334 = F_88 ( V_407 , V_36 , V_116 ) ;
if ( ! V_147 -> V_334 ) {
F_5 ( V_20 , L_105 ,
V_36 ) ;
V_3 = - V_83 ;
goto V_419;
}
F_5 ( V_20 , L_106 , V_21 , V_147 -> V_334 ) ;
V_36 = V_408 -> V_420 - ( V_36 + 1 ) ;
if ( V_36 > V_401 || V_36 <= 0 ) {
F_5 ( V_20 , L_107 , V_36 ) ;
V_3 = - V_140 ;
F_11 ( V_147 -> V_334 ) ;
V_147 -> V_334 = NULL ;
goto V_419;
}
++ V_139 ;
V_147 -> V_339 = F_88 ( V_139 , V_36 , V_116 ) ;
if ( ! V_147 -> V_339 ) {
F_5 ( V_20 , L_108 ,
V_36 ) ;
V_3 = - V_83 ;
F_11 ( V_147 -> V_334 ) ;
V_147 -> V_334 = NULL ;
goto V_419;
}
V_419:
F_149 ( & V_408 -> V_418 ) ;
F_150 ( V_408 ) ;
V_390:
F_11 ( V_406 ) ;
F_5 ( V_20 , L_109 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_151 ( struct V_1 * V_2 , struct V_146 * V_388 )
{
int V_3 = - V_83 ;
unsigned int V_403 ;
struct V_7 * V_8 ;
struct V_363 * V_373 = (struct V_363 * ) & V_2 -> V_96 ;
struct V_369 * V_380 = (struct V_369 * ) & V_2 -> V_96 ;
V_403 = F_141 () ;
V_8 = F_139 ( V_2 , V_388 ) ;
if ( V_8 ) {
F_5 ( V_20 , L_110 ,
V_8 -> V_404 ) ;
F_8 ( & V_8 -> V_421 ) ;
V_3 = F_152 ( V_403 , V_8 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_421 ) ;
F_140 ( V_8 ) ;
F_153 ( V_403 ) ;
return F_71 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_5 ( V_20 , L_111 ) ;
V_3 = F_154 ( V_403 , V_8 ,
V_388 -> V_422 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_421 ) ;
F_140 ( V_8 ) ;
F_153 ( V_403 ) ;
return F_71 ( V_3 ) ;
}
}
F_12 ( & V_8 -> V_421 ) ;
F_116 ( V_2 ) ;
F_153 ( V_403 ) ;
return V_8 ;
}
F_5 ( V_20 , L_112 ) ;
V_8 = F_155 () ;
if ( V_8 == NULL )
goto V_423;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_96 . V_414 == V_368 )
sprintf ( V_8 -> V_424 , L_113 , & V_380 -> V_372 ) ;
else
sprintf ( V_8 -> V_424 , L_114 , & V_373 -> V_366 ) ;
if ( V_388 -> V_334 ) {
V_8 -> V_400 = F_90 ( V_388 -> V_334 , V_116 ) ;
if ( ! V_8 -> V_400 )
goto V_423;
}
if ( V_388 -> V_339 ) {
V_8 -> V_339 = F_90 ( V_388 -> V_339 , V_116 ) ;
if ( ! V_8 -> V_339 )
goto V_423;
}
if ( V_388 -> V_346 ) {
V_8 -> V_417 = F_90 ( V_388 -> V_346 , V_116 ) ;
if ( ! V_8 -> V_417 )
goto V_423;
}
V_8 -> V_218 = V_388 -> V_218 ;
V_8 -> V_219 = V_388 -> V_219 ;
V_8 -> V_149 = V_388 -> V_149 ;
V_8 -> V_151 = V_388 -> V_151 ;
F_8 ( & V_8 -> V_421 ) ;
V_3 = F_152 ( V_403 , V_8 ) ;
if ( ! V_3 )
V_3 = F_154 ( V_403 , V_8 , V_388 -> V_422 ) ;
F_12 ( & V_8 -> V_421 ) ;
if ( V_3 )
goto V_423;
F_2 ( & V_22 ) ;
F_135 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_153 ( V_403 ) ;
return V_8 ;
V_423:
F_143 ( V_8 ) ;
F_153 ( V_403 ) ;
return F_71 ( V_3 ) ;
}
static int F_156 ( struct V_9 * V_10 , const char * V_136 )
{
if ( V_10 -> V_425 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_426 , V_136 , V_427 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_157 ( struct V_7 * V_8 , const char * V_136 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_22 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_26 ) ;
if ( ! F_156 ( V_10 , V_136 ) )
continue;
++ V_10 -> V_428 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_158 ( struct V_9 * V_10 )
{
unsigned int V_403 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( V_20 , L_115 , V_21 , V_10 -> V_428 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_428 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_403 = F_141 () ;
if ( V_8 -> V_2 -> V_49 -> V_429 )
V_8 -> V_2 -> V_49 -> V_429 ( V_403 , V_10 ) ;
F_142 ( V_403 ) ;
F_159 ( V_10 ) ;
F_160 ( V_10 ) ;
F_140 ( V_8 ) ;
}
static struct V_9 *
F_161 ( struct V_7 * V_8 , struct V_146 * V_388 )
{
int V_3 , V_403 ;
struct V_9 * V_10 ;
V_10 = F_157 ( V_8 , V_388 -> V_194 ) ;
if ( V_10 ) {
F_5 ( V_20 , L_116 ) ;
F_140 ( V_8 ) ;
if ( V_10 -> V_304 != V_388 -> V_304 )
F_5 ( V_59 , L_117 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_49 -> V_430 ) {
V_3 = - V_55 ;
goto V_431;
}
V_10 = F_162 () ;
if ( V_10 == NULL ) {
V_3 = - V_83 ;
goto V_431;
}
V_10 -> V_8 = V_8 ;
if ( V_388 -> V_339 ) {
V_10 -> V_339 = F_90 ( V_388 -> V_339 , V_116 ) ;
if ( ! V_10 -> V_339 ) {
V_3 = - V_83 ;
goto V_431;
}
}
V_403 = F_141 () ;
V_3 = V_8 -> V_2 -> V_49 -> V_430 ( V_403 , V_8 , V_388 -> V_194 , V_10 ,
V_388 -> V_422 ) ;
F_153 ( V_403 ) ;
F_5 ( V_20 , L_118 , V_3 ) ;
if ( V_3 )
goto V_431;
if ( V_388 -> V_261 ) {
V_10 -> V_432 &= ~ V_433 ;
F_5 ( V_20 , L_119 , V_10 -> V_432 ) ;
}
V_10 -> V_304 = V_388 -> V_304 ;
V_10 -> V_249 = V_388 -> V_249 ;
V_10 -> V_267 = V_388 -> V_267 ;
V_10 -> V_301 = V_388 -> V_301 ;
F_13 ( & V_10 -> V_434 ) ;
F_2 ( & V_22 ) ;
F_135 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_163 ( V_10 ) ;
return V_10 ;
V_431:
F_160 ( V_10 ) ;
return F_71 ( V_3 ) ;
}
void
F_164 ( struct V_435 * V_436 )
{
if ( ! V_436 || F_125 ( V_436 ) )
return;
if ( ! F_165 ( & V_436 -> V_437 ) ||
F_166 ( V_438 , & V_436 -> V_439 ) ) {
V_436 -> V_440 = V_38 ;
return;
}
if ( ! F_125 ( F_167 ( V_436 ) ) )
F_158 ( F_167 ( V_436 ) ) ;
F_11 ( V_436 ) ;
return;
}
static inline struct V_435 *
F_168 ( struct V_441 * V_442 )
{
return V_442 -> V_443 ;
}
static int
F_169 ( struct V_444 * V_445 , struct V_446 * V_447 )
{
struct V_441 * V_448 = F_170 ( V_445 ) ;
struct V_441 * V_65 = V_447 -> V_442 ;
if ( ( V_445 -> V_449 & V_450 ) != ( V_447 -> V_30 & V_450 ) )
return 0 ;
if ( ( V_448 -> V_451 & V_452 ) !=
( V_65 -> V_451 & V_452 ) )
return 0 ;
if ( V_65 -> V_330 && V_65 -> V_330 < V_448 -> V_330 )
return 0 ;
if ( V_65 -> V_328 && V_65 -> V_328 < V_448 -> V_328 )
return 0 ;
if ( ! F_138 ( V_448 -> V_453 , V_65 -> V_453 ) || ! F_171 ( V_448 -> V_454 , V_65 -> V_454 ) )
return 0 ;
if ( V_448 -> V_455 != V_65 -> V_455 ||
V_448 -> V_456 != V_65 -> V_456 )
return 0 ;
if ( strcmp ( V_448 -> V_422 -> V_457 , V_65 -> V_422 -> V_457 ) )
return 0 ;
if ( V_448 -> V_228 != V_65 -> V_228 )
return 0 ;
return 1 ;
}
int
F_172 ( struct V_444 * V_445 , void * V_197 )
{
struct V_446 * V_447 = (struct V_446 * ) V_197 ;
struct V_146 * V_388 ;
struct V_441 * V_442 ;
struct V_1 * V_458 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_435 * V_436 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_442 = F_170 ( V_445 ) ;
V_436 = F_173 ( F_168 ( V_442 ) ) ;
if ( F_125 ( V_436 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_167 ( V_436 ) ;
V_8 = V_10 -> V_8 ;
V_458 = V_8 -> V_2 ;
V_388 = V_447 -> V_147 ;
if ( ! F_111 ( V_458 , V_388 ) ||
! F_137 ( V_8 , V_388 ) ||
! F_156 ( V_10 , V_388 -> V_194 ) ) {
V_3 = 0 ;
goto V_459;
}
V_3 = F_169 ( V_445 , V_447 ) ;
V_459:
F_3 ( & V_22 ) ;
F_164 ( V_436 ) ;
return V_3 ;
}
int
F_174 ( const unsigned int V_403 , struct V_7 * V_8 , const char * V_460 ,
const struct V_461 * V_462 , unsigned int * V_463 ,
struct V_464 * * V_465 , int V_255 )
{
char * V_466 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_49 -> V_430 || ! V_8 -> V_2 -> V_49 -> V_467 )
return - V_55 ;
* V_463 = 0 ;
* V_465 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_466 = F_35 ( 2 +
F_93 ( V_8 -> V_424 , V_468 * 2 )
+ 1 + 4 + 2 , V_116 ) ;
if ( V_466 == NULL )
return - V_83 ;
V_466 [ 0 ] = '\\' ;
V_466 [ 1 ] = '\\' ;
strcpy ( V_466 + 2 , V_8 -> V_424 ) ;
strcpy ( V_466 + 2 + strlen ( V_8 -> V_424 ) , L_120 ) ;
V_3 = V_8 -> V_2 -> V_49 -> V_430 ( V_403 , V_8 , V_466 , NULL ,
V_462 ) ;
F_5 ( V_20 , L_121 , V_3 , V_8 -> V_25 ) ;
F_11 ( V_466 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_49 -> V_467 ( V_403 , V_8 , V_460 ,
V_465 , V_463 ,
V_462 , V_255 ) ;
return V_3 ;
}
static inline void
F_175 ( struct V_469 * V_470 )
{
struct V_470 * V_471 = V_470 -> V_471 ;
F_176 ( F_177 ( V_471 ) ) ;
F_178 ( V_471 , L_122 ,
& V_472 [ 0 ] , L_123 , & V_473 [ 0 ] ) ;
}
static inline void
F_179 ( struct V_469 * V_470 )
{
struct V_470 * V_471 = V_470 -> V_471 ;
F_176 ( F_177 ( V_471 ) ) ;
F_178 ( V_471 , L_124 ,
& V_472 [ 1 ] , L_125 , & V_473 [ 1 ] ) ;
}
static inline void
F_175 ( struct V_469 * V_470 )
{
}
static inline void
F_179 ( struct V_469 * V_470 )
{
}
static void F_180 ( char * V_474 , char * V_475 , unsigned int V_78 )
{
unsigned int V_202 , V_203 ;
for ( V_202 = 0 , V_203 = 0 ; V_202 < ( V_78 ) ; V_202 ++ ) {
V_474 [ V_203 ] = 'A' + ( 0x0F & ( V_475 [ V_202 ] >> 4 ) ) ;
V_474 [ V_203 + 1 ] = 'A' + ( 0x0F & V_475 [ V_202 ] ) ;
V_203 += 2 ;
}
}
static int
F_181 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_348 . V_414 != V_361 ) {
struct V_469 * V_469 = V_2 -> V_28 ;
V_3 = V_469 -> V_49 -> V_476 ( V_469 ,
(struct V_95 * ) & V_2 -> V_348 ,
sizeof( V_2 -> V_348 ) ) ;
if ( V_3 < 0 ) {
struct V_363 * V_364 ;
struct V_369 * V_370 ;
V_364 = (struct V_363 * ) & V_2 -> V_348 ;
V_370 = (struct V_369 * ) & V_2 -> V_348 ;
if ( V_370 -> V_477 == V_368 )
F_5 ( V_59 , L_126 ,
& V_370 -> V_372 , V_3 ) ;
else
F_5 ( V_59 , L_127 ,
& V_364 -> V_366 . V_367 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_182 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_478 * V_479 ;
struct V_480 * V_481 ;
V_479 = F_99 ( sizeof( struct V_478 ) ,
V_116 ) ;
if ( V_479 ) {
V_479 -> V_482 . V_483 . V_484 = 32 ;
if ( V_2 -> V_396 &&
V_2 -> V_396 [ 0 ] != 0 )
F_180 ( V_479 -> V_482 .
V_483 . V_485 ,
V_2 -> V_396 ,
V_353 ) ;
else
F_180 ( V_479 -> V_482 .
V_483 . V_485 ,
V_486 ,
V_353 ) ;
V_479 -> V_482 . V_483 . V_487 = 32 ;
if ( V_2 -> V_395 &&
V_2 -> V_395 [ 0 ] != 0 )
F_180 ( V_479 -> V_482 .
V_483 . V_488 ,
V_2 -> V_395 ,
V_353 ) ;
else
F_180 ( V_479 -> V_482 .
V_483 . V_488 ,
L_128 ,
V_353 ) ;
V_479 -> V_482 . V_483 . V_489 = 0 ;
V_479 -> V_482 . V_483 . V_490 = 0 ;
V_481 = (struct V_480 * ) V_479 ;
V_481 -> V_491 = F_183 ( 0x81000044 ) ;
V_3 = F_184 ( V_2 , V_481 , 0x44 ) ;
F_11 ( V_479 ) ;
F_38 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_374 ;
int V_492 , V_493 ;
struct V_469 * V_469 = V_2 -> V_28 ;
struct V_95 * V_494 ;
V_494 = (struct V_95 * ) & V_2 -> V_96 ;
if ( V_2 -> V_96 . V_414 == V_368 ) {
V_374 = ( (struct V_369 * ) V_494 ) -> V_376 ;
V_492 = sizeof( struct V_369 ) ;
V_493 = V_368 ;
} else {
V_374 = ( (struct V_363 * ) V_494 ) -> V_375 ;
V_492 = sizeof( struct V_363 ) ;
V_493 = V_362 ;
}
if ( V_469 == NULL ) {
V_3 = F_185 ( F_113 ( V_2 ) , V_493 , V_495 ,
V_496 , & V_469 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_129 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_5 ( V_20 , L_130 ) ;
V_2 -> V_28 = V_469 ;
V_469 -> V_471 -> V_497 = V_75 ;
if ( V_493 == V_368 )
F_179 ( V_469 ) ;
else
F_175 ( V_469 ) ;
}
V_3 = F_181 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_469 -> V_471 -> V_498 = 7 * V_53 ;
V_469 -> V_471 -> V_499 = 5 * V_53 ;
if ( V_2 -> V_247 ) {
if ( V_469 -> V_471 -> V_500 < ( 200 * 1024 ) )
V_469 -> V_471 -> V_500 = 200 * 1024 ;
if ( V_469 -> V_471 -> V_501 < ( 140 * 1024 ) )
V_469 -> V_471 -> V_501 = 140 * 1024 ;
}
if ( V_2 -> V_392 ) {
int V_502 = 1 ;
V_3 = F_186 ( V_469 , V_503 , V_504 ,
( char * ) & V_502 , sizeof( V_502 ) ) ;
if ( V_3 )
F_5 ( V_20 , L_131 ,
V_3 ) ;
}
F_5 ( V_20 , L_132 ,
V_469 -> V_471 -> V_500 ,
V_469 -> V_471 -> V_501 , V_469 -> V_471 -> V_498 ) ;
V_3 = V_469 -> V_49 -> V_505 ( V_469 , V_494 , V_492 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_20 , L_133 , V_3 ) ;
F_10 ( V_469 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_374 == F_107 ( V_377 ) )
V_3 = F_182 ( V_2 ) ;
return V_3 ;
}
static int
F_131 ( struct V_1 * V_2 )
{
T_5 * V_374 ;
struct V_369 * V_380 = (struct V_369 * ) & V_2 -> V_96 ;
struct V_363 * V_373 = (struct V_363 * ) & V_2 -> V_96 ;
if ( V_2 -> V_96 . V_414 == V_368 )
V_374 = & V_380 -> V_376 ;
else
V_374 = & V_373 -> V_375 ;
if ( * V_374 == 0 ) {
int V_3 ;
* V_374 = F_107 ( V_97 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_374 = F_107 ( V_377 ) ;
}
return F_18 ( V_2 ) ;
}
void F_187 ( unsigned int V_403 , struct V_9 * V_10 ,
struct V_441 * V_442 , struct V_146 * V_506 )
{
T_7 V_507 = F_188 ( V_10 -> V_508 . V_509 ) ;
if ( V_506 && V_506 -> V_265 ) {
V_10 -> V_508 . V_509 = 0 ;
V_10 -> V_510 = 0 ;
F_5 ( V_20 , L_134 ) ;
return;
} else if ( V_506 )
V_10 -> V_510 = 1 ;
if ( V_10 -> V_510 == 0 ) {
F_5 ( V_20 , L_135 ) ;
return;
}
if ( ! F_189 ( V_403 , V_10 ) ) {
T_7 V_511 = F_188 ( V_10 -> V_508 . V_509 ) ;
F_5 ( V_20 , L_136 , V_511 ) ;
if ( V_506 == NULL ) {
if ( ( V_507 & V_512 ) == 0 )
V_511 &= ~ V_512 ;
if ( ( V_507 & V_513 ) == 0 ) {
if ( V_511 & V_513 )
F_5 ( V_59 , L_137 ) ;
V_511 &= ~ V_513 ;
} else if ( ( V_511 & V_513 ) == 0 ) {
F_5 ( V_59 , L_138 ) ;
F_5 ( V_59 , L_139 ) ;
}
}
if ( V_511 & V_514 )
F_5 ( V_59 , L_140 ) ;
V_511 &= V_515 ;
if ( V_506 && V_506 -> V_298 )
V_511 &= ~ V_512 ;
else if ( V_512 & V_511 ) {
F_5 ( V_20 , L_141 ) ;
if ( V_442 )
V_442 -> V_451 |=
V_516 ;
}
if ( V_506 && V_506 -> V_226 == 0 )
V_511 &= ~ V_513 ;
else if ( V_511 & V_513 ) {
F_5 ( V_20 , L_142 ) ;
if ( V_442 )
V_442 -> V_451 |=
V_517 ;
}
F_5 ( V_20 , L_143 , ( int ) V_511 ) ;
#ifdef F_61
if ( V_511 & V_518 )
F_5 ( V_20 , L_144 ) ;
if ( V_511 & V_519 )
F_5 ( V_20 , L_145 ) ;
if ( V_511 & V_513 )
F_5 ( V_20 , L_146 ) ;
if ( V_511 & V_520 )
F_5 ( V_20 , L_147 ) ;
if ( V_511 & V_512 )
F_5 ( V_20 , L_148 ) ;
if ( V_511 & V_521 )
F_5 ( V_20 , L_149 ) ;
if ( V_511 & V_522 )
F_5 ( V_20 , L_150 ) ;
if ( V_511 & V_523 )
F_5 ( V_20 , L_151 ) ;
if ( V_511 & V_514 )
F_5 ( V_20 , L_152 ) ;
#endif
if ( F_190 ( V_403 , V_10 , V_511 ) ) {
if ( V_506 == NULL ) {
F_5 ( V_20 , L_153 ) ;
} else
F_5 ( V_59 , L_154 ) ;
}
}
}
void F_191 ( struct V_146 * V_524 ,
struct V_441 * V_442 )
{
F_130 ( & V_442 -> V_525 , V_526 ) ;
F_129 ( & V_442 -> V_527 ) ;
V_442 -> V_528 = V_529 ;
V_442 -> V_328 = V_524 -> V_328 ;
V_442 -> V_330 = V_524 -> V_330 ;
V_442 -> V_453 = V_524 -> V_219 ;
V_442 -> V_454 = V_524 -> V_220 ;
V_442 -> V_455 = V_524 -> V_222 ;
V_442 -> V_456 = V_524 -> V_221 ;
F_5 ( V_20 , L_155 ,
V_442 -> V_455 , V_442 -> V_456 ) ;
V_442 -> V_228 = V_524 -> V_228 ;
V_442 -> V_422 = V_524 -> V_422 ;
if ( V_524 -> V_252 )
V_442 -> V_451 |= V_530 ;
if ( V_524 -> V_277 )
V_442 -> V_451 |= V_531 ;
if ( V_524 -> V_227 )
V_442 -> V_451 |= V_532 ;
if ( V_524 -> V_255 )
V_442 -> V_451 |= V_533 ;
if ( V_524 -> V_238 )
V_442 -> V_451 |= V_534 ;
if ( V_524 -> V_258 )
V_442 -> V_451 |= V_535 ;
if ( V_524 -> V_269 )
V_442 -> V_451 |= V_536 ;
if ( V_524 -> V_288 )
V_442 -> V_451 |= V_537 ;
if ( V_524 -> V_275 )
V_442 -> V_451 |= V_538 ;
if ( V_524 -> V_293 )
V_442 -> V_451 |= V_539 ;
if ( V_524 -> V_295 )
V_442 -> V_451 |= V_540 ;
if ( V_524 -> V_232 ) {
V_442 -> V_451 |= V_541 ;
V_442 -> V_542 = V_524 -> V_317 ;
}
if ( V_524 -> V_233 ) {
V_442 -> V_451 |= V_543 ;
V_442 -> V_544 = V_524 -> V_319 ;
}
if ( V_524 -> V_205 )
V_442 -> V_451 |= V_545 ;
if ( V_524 -> V_206 )
V_442 -> V_451 |= V_546 ;
if ( V_524 -> V_280 )
V_442 -> V_451 |= V_547 ;
if ( V_524 -> V_308 )
V_442 -> V_451 |= V_548 ;
if ( V_524 -> V_312 )
V_442 -> V_451 |= ( V_549 |
V_530 ) ;
if ( V_524 -> V_173 )
V_442 -> V_451 |= V_550 ;
if ( V_524 -> V_172 ) {
F_5 ( V_20 , L_156 ) ;
V_442 -> V_451 |= V_551 ;
}
if ( V_524 -> V_310 ) {
if ( V_524 -> V_258 ) {
F_5 ( V_59 , L_157 ) ;
} else {
V_442 -> V_451 |= V_552 ;
}
}
if ( ( V_524 -> V_295 ) && ( V_524 -> V_280 ) )
F_5 ( V_59 , L_158 ) ;
}
static void
F_192 ( struct V_146 * V_388 )
{
F_11 ( V_388 -> V_334 ) ;
F_193 ( V_388 -> V_339 ) ;
F_11 ( V_388 -> V_194 ) ;
F_11 ( V_388 -> V_346 ) ;
F_11 ( V_388 -> V_350 ) ;
F_11 ( V_388 -> V_195 ) ;
}
void
F_194 ( struct V_146 * V_388 )
{
if ( ! V_388 )
return;
F_192 ( V_388 ) ;
F_11 ( V_388 ) ;
}
static char *
F_195 ( const struct V_146 * V_147 ,
const struct V_441 * V_442 )
{
char * V_553 , * V_192 ;
unsigned int V_554 = V_147 -> V_195 ? strlen ( V_147 -> V_195 ) + 1 : 0 ;
unsigned int V_555 = F_93 ( V_147 -> V_194 , V_427 + 1 ) ;
V_553 = F_35 ( V_555 + V_554 + 1 , V_116 ) ;
if ( V_553 == NULL )
return F_71 ( - V_83 ) ;
strncpy ( V_553 , V_147 -> V_194 , V_555 ) ;
V_192 = V_553 + V_555 ;
if ( V_554 ) {
* V_192 = F_196 ( V_442 ) ;
strncpy ( V_192 + 1 , V_147 -> V_195 , V_554 ) ;
V_192 += V_554 ;
}
* V_192 = '\0' ;
F_89 ( V_553 , F_196 ( V_442 ) ) ;
F_5 ( V_20 , L_159 , V_21 , V_553 ) ;
return V_553 ;
}
static int
F_197 ( const unsigned int V_403 , struct V_7 * V_8 ,
struct V_146 * V_388 , struct V_441 * V_442 ,
int V_556 )
{
int V_3 ;
unsigned int V_463 = 0 ;
struct V_464 * V_465 = NULL ;
char * V_553 = NULL , * V_557 = NULL , * V_558 = NULL ;
V_553 = F_195 ( V_388 , V_442 ) ;
if ( F_125 ( V_553 ) )
return F_126 ( V_553 ) ;
V_557 = V_556 ? V_553 + 1 : V_388 -> V_194 + 1 ;
V_3 = F_174 ( V_403 , V_8 , V_557 , V_442 -> V_422 ,
& V_463 , & V_465 ,
V_442 -> V_451 & V_533 ) ;
if ( ! V_3 && V_463 > 0 ) {
char * V_559 = NULL ;
V_558 = F_198 ( V_442 -> V_196 ,
V_553 + 1 , V_465 ,
& V_559 ) ;
F_199 ( V_465 , V_463 ) ;
if ( F_125 ( V_558 ) ) {
V_3 = F_126 ( V_558 ) ;
V_558 = NULL ;
} else {
F_192 ( V_388 ) ;
V_3 = F_200 ( V_388 , V_558 ,
V_559 ) ;
}
F_11 ( V_559 ) ;
F_11 ( V_442 -> V_196 ) ;
V_442 -> V_196 = V_558 ;
}
F_11 ( V_553 ) ;
return V_3 ;
}
static int
F_200 ( struct V_146 * V_388 , char * V_560 ,
const char * V_191 )
{
int V_3 = 0 ;
if ( F_91 ( V_560 , V_191 , V_388 ) )
return - V_140 ;
if ( V_388 -> V_169 ) {
F_5 ( V_20 , L_160 ) ;
F_11 ( V_388 -> V_334 ) ;
V_388 -> V_334 = NULL ;
} else if ( V_388 -> V_334 ) {
F_5 ( V_20 , L_161 , V_388 -> V_334 ) ;
} else {
F_5 ( V_59 , L_162 ) ;
return - V_140 ;
}
if ( V_388 -> V_350 == NULL ) {
V_388 -> V_422 = F_201 () ;
} else {
V_388 -> V_422 = F_202 ( V_388 -> V_350 ) ;
if ( V_388 -> V_422 == NULL ) {
F_5 ( V_59 , L_163 ,
V_388 -> V_350 ) ;
return - V_561 ;
}
}
return V_3 ;
}
struct V_146 *
F_203 ( char * V_560 , const char * V_191 )
{
int V_3 ;
struct V_146 * V_388 ;
V_388 = F_35 ( sizeof( struct V_146 ) , V_116 ) ;
if ( ! V_388 )
return F_71 ( - V_83 ) ;
V_3 = F_200 ( V_388 , V_560 , V_191 ) ;
if ( V_3 ) {
F_194 ( V_388 ) ;
V_388 = F_71 ( V_3 ) ;
}
return V_388 ;
}
int
F_204 ( struct V_441 * V_442 , struct V_146 * V_388 )
{
int V_3 ;
unsigned int V_403 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_553 ;
struct V_435 * V_436 ;
#ifdef F_205
int V_562 = 0 ;
#endif
V_3 = F_206 ( & V_442 -> V_563 , L_164 , V_564 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_205
V_565:
if ( V_562 ) {
if ( V_10 )
F_158 ( V_10 ) ;
else if ( V_8 )
F_140 ( V_8 ) ;
F_153 ( V_403 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_553 = NULL ;
V_436 = NULL ;
V_403 = F_141 () ;
V_2 = F_122 ( V_388 ) ;
if ( F_125 ( V_2 ) ) {
V_3 = F_126 ( V_2 ) ;
F_207 ( & V_442 -> V_563 ) ;
goto V_459;
}
V_8 = F_151 ( V_2 , V_388 ) ;
if ( F_125 ( V_8 ) ) {
V_3 = F_126 ( V_8 ) ;
V_8 = NULL ;
goto V_566;
}
V_10 = F_161 ( V_8 , V_388 ) ;
if ( F_125 ( V_10 ) ) {
V_3 = F_126 ( V_10 ) ;
V_10 = NULL ;
goto V_567;
}
if ( F_208 ( V_10 -> V_8 ) ) {
F_187 ( V_403 , V_10 , V_442 , V_388 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_188 ( V_10 -> V_508 . V_509 ) &
V_514 ) ) {
V_3 = - V_568 ;
goto V_566;
}
} else
V_10 -> V_510 = 0 ;
if ( ! V_10 -> V_569 && V_2 -> V_49 -> V_570 )
V_2 -> V_49 -> V_570 ( V_403 , V_10 ) ;
V_442 -> V_330 = V_2 -> V_49 -> V_571 ( V_10 , V_388 ) ;
V_442 -> V_328 = V_2 -> V_49 -> V_572 ( V_10 , V_388 ) ;
V_442 -> V_563 . V_573 = V_442 -> V_328 / V_574 ;
V_567:
#ifdef F_205
if ( V_562 == 0 ) {
int V_575 = F_197 ( V_403 , V_8 , V_388 , V_442 ,
false ) ;
if ( ! V_575 ) {
V_562 ++ ;
goto V_565;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_49 -> V_576 ) {
V_3 = - V_55 ;
goto V_566;
}
V_553 = F_209 ( V_388 , V_442 , V_10 ) ;
if ( V_553 == NULL ) {
V_3 = - V_83 ;
goto V_566;
}
V_3 = V_2 -> V_49 -> V_576 ( V_403 , V_10 , V_442 ,
V_553 ) ;
if ( V_3 != 0 && V_3 != - V_577 ) {
F_11 ( V_553 ) ;
goto V_566;
}
F_11 ( V_553 ) ;
}
if ( V_3 == - V_577 ) {
#ifdef F_205
if ( V_562 > V_578 ) {
V_3 = - V_579 ;
goto V_566;
}
V_3 = F_197 ( V_403 , V_8 , V_388 , V_442 , true ) ;
if ( ! V_3 ) {
V_562 ++ ;
goto V_565;
}
goto V_566;
#else
V_3 = - V_580 ;
#endif
}
if ( V_3 )
goto V_566;
V_436 = F_99 ( sizeof *V_436 , V_116 ) ;
if ( V_436 == NULL ) {
V_3 = - V_83 ;
goto V_566;
}
V_436 -> V_581 = V_8 -> V_219 ;
V_436 -> V_582 = V_10 ;
V_436 -> V_440 = V_38 ;
F_210 ( V_583 , & V_436 -> V_439 ) ;
F_210 ( V_438 , & V_436 -> V_439 ) ;
V_442 -> V_443 = V_436 ;
F_2 ( & V_442 -> V_527 ) ;
F_211 ( & V_442 -> V_528 , V_436 ) ;
F_3 ( & V_442 -> V_527 ) ;
F_24 ( V_57 , & V_442 -> V_525 ,
V_584 ) ;
V_566:
if ( V_3 ) {
if ( V_10 )
F_158 ( V_10 ) ;
else if ( V_8 )
F_140 ( V_8 ) ;
else
F_116 ( V_2 ) ;
F_207 ( & V_442 -> V_563 ) ;
}
V_459:
F_153 ( V_403 ) ;
return V_3 ;
}
int
F_212 ( const unsigned int V_403 , struct V_7 * V_8 ,
const char * V_585 , struct V_9 * V_10 ,
const struct V_461 * V_462 )
{
struct V_480 * V_586 ;
struct V_480 * V_587 ;
T_8 * V_588 ;
T_9 * V_589 ;
unsigned char * V_590 ;
int V_3 = 0 ;
int V_78 ;
T_10 V_591 , V_592 ;
if ( V_8 == NULL )
return - V_593 ;
V_586 = F_26 () ;
if ( V_586 == NULL )
return - V_83 ;
V_587 = V_586 ;
F_213 ( V_586 , V_594 ,
NULL , 4 ) ;
V_586 -> V_595 = F_214 ( V_8 -> V_2 ) ;
V_586 -> V_596 = V_8 -> V_597 ;
V_588 = ( T_8 * ) V_586 ;
V_589 = ( T_9 * ) V_587 ;
V_588 -> V_598 = 0xFF ;
V_588 -> V_432 = F_215 ( V_599 ) ;
V_590 = & V_588 -> V_600 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_601 & V_602 ) ) {
V_588 -> V_603 = F_215 ( 1 ) ;
* V_590 = 0 ;
V_590 ++ ;
} else {
V_588 -> V_603 = F_215 ( V_604 ) ;
#ifdef F_84
if ( ( V_605 & V_606 ) &&
( V_8 -> V_149 == V_167 ) )
F_216 ( V_10 -> V_339 , V_8 -> V_2 -> V_607 ,
V_8 -> V_2 -> V_601 &
V_608 ? true : false ,
V_590 ) ;
else
#endif
V_3 = F_217 ( V_10 -> V_339 , V_8 -> V_2 -> V_607 ,
V_590 , V_462 ) ;
V_590 += V_604 ;
if ( V_8 -> V_609 & V_610 ) {
* V_590 = 0 ;
V_590 ++ ;
}
}
if ( V_8 -> V_2 -> V_151 )
V_586 -> V_611 |= V_612 ;
if ( V_8 -> V_609 & V_613 ) {
V_586 -> V_611 |= V_614 ;
}
if ( V_8 -> V_609 & V_615 ) {
V_586 -> V_611 |= V_616 ;
}
if ( V_8 -> V_609 & V_610 ) {
V_586 -> V_611 |= V_617 ;
V_78 =
F_218 ( ( V_618 * ) V_590 , V_585 ,
6 *
( + 256 ) , V_462 ) ;
V_590 += 2 * V_78 ;
V_590 += 2 ;
} else {
strcpy ( V_590 , V_585 ) ;
V_590 += strlen ( V_585 ) + 1 ;
}
strcpy ( V_590 , L_165 ) ;
V_590 += strlen ( L_165 ) ;
V_590 += 1 ;
V_592 = V_590 - & V_588 -> V_600 [ 0 ] ;
V_588 -> V_619 . V_491 = F_183 ( F_219 (
V_588 -> V_619 . V_491 ) + V_592 ) ;
V_588 -> V_620 = F_215 ( V_592 ) ;
V_3 = F_220 ( V_403 , V_8 , V_586 , V_587 , & V_78 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_621 ;
V_10 -> V_425 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_622 = V_587 -> V_623 ;
V_590 = F_221 ( V_587 ) ;
V_591 = F_222 ( V_587 ) ;
V_78 = F_93 ( V_590 , V_591 - 2 ) ;
if ( V_586 -> V_611 & V_617 )
V_621 = true ;
else
V_621 = false ;
if ( V_78 == 3 ) {
if ( ( V_590 [ 0 ] == 'I' ) && ( V_590 [ 1 ] == 'P' ) &&
( V_590 [ 2 ] == 'C' ) ) {
F_5 ( V_20 , L_166 ) ;
V_10 -> V_569 = 1 ;
}
} else if ( V_78 == 2 ) {
if ( ( V_590 [ 0 ] == 'A' ) && ( V_590 [ 1 ] == ':' ) ) {
F_5 ( V_20 , L_167 ) ;
}
}
V_590 += V_78 + 1 ;
V_591 -= ( V_78 + 1 ) ;
F_223 ( V_10 -> V_426 , V_585 , sizeof( V_10 -> V_426 ) ) ;
F_11 ( V_10 -> V_624 ) ;
V_10 -> V_624 = F_224 ( V_590 ,
V_591 , V_621 ,
V_462 ) ;
F_5 ( V_20 , L_168 , V_10 -> V_624 ) ;
if ( ( V_587 -> V_625 == 3 ) ||
( V_587 -> V_625 == 7 ) )
V_10 -> V_432 = F_225 ( V_589 -> V_626 ) ;
else
V_10 -> V_432 = 0 ;
F_5 ( V_20 , L_169 , V_10 -> V_432 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_587 -> V_623 ;
}
F_63 ( V_586 ) ;
return V_3 ;
}
void
F_226 ( struct V_441 * V_442 )
{
struct V_627 * V_628 = & V_442 -> V_528 ;
struct V_629 * V_630 ;
struct V_435 * V_436 ;
F_118 ( & V_442 -> V_525 ) ;
F_2 ( & V_442 -> V_527 ) ;
while ( ( V_630 = F_227 ( V_628 ) ) ) {
V_436 = F_228 ( V_630 , struct V_435 , V_631 ) ;
F_173 ( V_436 ) ;
F_229 ( V_438 , & V_436 -> V_439 ) ;
F_230 ( V_630 , V_628 ) ;
F_3 ( & V_442 -> V_527 ) ;
F_164 ( V_436 ) ;
F_2 ( & V_442 -> V_527 ) ;
}
F_3 ( & V_442 -> V_527 ) ;
F_207 ( & V_442 -> V_563 ) ;
F_11 ( V_442 -> V_196 ) ;
F_231 ( V_442 -> V_422 ) ;
F_11 ( V_442 ) ;
}
int
F_152 ( const unsigned int V_403 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_49 -> V_50 || ! V_2 -> V_49 -> V_632 )
return - V_55 ;
if ( ! V_2 -> V_49 -> V_50 ( V_2 ) )
return 0 ;
F_232 ( V_2 , 1 ) ;
V_3 = V_2 -> V_49 -> V_632 ( V_403 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_633 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_154 ( const unsigned int V_403 , struct V_7 * V_8 ,
struct V_461 * V_634 )
{
int V_3 = - V_55 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_609 = V_2 -> V_609 ;
if ( V_635 == 0 )
V_8 -> V_609 &= ( ~ V_2 -> V_179 -> F_208 ) ;
F_5 ( V_20 , L_170 ,
V_2 -> V_601 , V_2 -> V_609 , V_2 -> V_636 ) ;
if ( V_2 -> V_49 -> V_637 )
V_3 = V_2 -> V_49 -> V_637 ( V_403 , V_8 , V_634 ) ;
if ( V_3 ) {
F_5 ( V_59 , L_171 , V_3 ) ;
} else {
F_8 ( & V_2 -> V_27 ) ;
if ( ! V_2 -> V_33 ) {
V_2 -> V_34 . V_35 = V_8 -> V_638 . V_35 ;
V_2 -> V_34 . V_36 = V_8 -> V_638 . V_36 ;
V_2 -> V_32 = 0x2 ;
V_2 -> V_33 = true ;
V_8 -> V_638 . V_35 = NULL ;
if ( V_2 -> V_49 -> V_639 )
V_2 -> V_49 -> V_639 ( V_2 ) ;
}
F_12 ( & V_2 -> V_27 ) ;
F_5 ( V_20 , L_172 ) ;
F_2 ( & V_14 ) ;
V_8 -> V_404 = V_62 ;
V_8 -> V_24 = false ;
F_3 ( & V_14 ) ;
}
F_11 ( V_8 -> V_638 . V_35 ) ;
V_8 -> V_638 . V_35 = NULL ;
V_8 -> V_638 . V_36 = 0 ;
F_11 ( V_8 -> V_640 ) ;
V_8 -> V_640 = NULL ;
return V_3 ;
}
static int
F_233 ( struct V_146 * V_147 , struct V_7 * V_8 )
{
V_147 -> V_149 = V_8 -> V_149 ;
if ( V_147 -> V_149 == V_156 )
return 0 ;
return F_144 ( V_147 , V_8 ) ;
}
static struct V_9 *
F_234 ( struct V_441 * V_442 , T_3 V_641 )
{
int V_3 ;
struct V_9 * V_642 = F_235 ( V_442 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_146 * V_506 ;
V_506 = F_99 ( sizeof( * V_506 ) , V_116 ) ;
if ( V_506 == NULL )
return F_71 ( - V_83 ) ;
V_506 -> V_422 = V_442 -> V_422 ;
V_506 -> V_219 = V_641 ;
V_506 -> V_218 = V_641 ;
V_506 -> V_194 = V_642 -> V_426 ;
V_506 -> V_249 = V_642 -> V_249 ;
V_506 -> V_267 = V_642 -> V_267 ;
V_506 -> V_301 = V_642 -> V_301 ;
V_506 -> V_265 = ! V_642 -> V_510 ;
V_506 -> V_149 = V_642 -> V_8 -> V_149 ;
V_506 -> V_151 = V_642 -> V_8 -> V_151 ;
V_3 = F_233 ( V_506 , V_642 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_71 ( V_3 ) ;
goto V_459;
}
F_2 ( & V_22 ) ;
++ V_642 -> V_8 -> V_2 -> V_385 ;
F_3 ( & V_22 ) ;
V_8 = F_151 ( V_642 -> V_8 -> V_2 , V_506 ) ;
if ( F_125 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_116 ( V_642 -> V_8 -> V_2 ) ;
goto V_459;
}
V_10 = F_161 ( V_8 , V_506 ) ;
if ( F_125 ( V_10 ) ) {
F_140 ( V_8 ) ;
goto V_459;
}
if ( F_208 ( V_8 ) )
F_187 ( 0 , V_10 , NULL , V_506 ) ;
V_459:
F_11 ( V_506 -> V_334 ) ;
F_11 ( V_506 -> V_339 ) ;
F_11 ( V_506 ) ;
return V_10 ;
}
struct V_9 *
F_235 ( struct V_441 * V_442 )
{
return F_167 ( F_168 ( V_442 ) ) ;
}
static int
F_236 ( void * V_643 )
{
F_68 () ;
return F_67 ( V_125 ) ? - V_88 : 0 ;
}
static struct V_435 *
F_237 ( struct V_627 * V_628 , T_3 V_144 )
{
struct V_629 * V_630 = V_628 -> V_629 ;
struct V_435 * V_436 ;
while ( V_630 ) {
V_436 = F_228 ( V_630 , struct V_435 , V_631 ) ;
if ( F_238 ( V_436 -> V_581 , V_144 ) )
V_630 = V_630 -> V_644 ;
else if ( F_239 ( V_436 -> V_581 , V_144 ) )
V_630 = V_630 -> V_645 ;
else
return V_436 ;
}
return NULL ;
}
static void
F_211 ( struct V_627 * V_628 , struct V_435 * V_646 )
{
struct V_629 * * V_65 = & ( V_628 -> V_629 ) , * V_647 = NULL ;
struct V_435 * V_436 ;
while ( * V_65 ) {
V_436 = F_228 ( * V_65 , struct V_435 , V_631 ) ;
V_647 = * V_65 ;
if ( F_238 ( V_436 -> V_581 , V_646 -> V_581 ) )
V_65 = & ( ( * V_65 ) -> V_644 ) ;
else
V_65 = & ( ( * V_65 ) -> V_645 ) ;
}
F_240 ( & V_646 -> V_631 , V_647 , V_65 ) ;
F_241 ( & V_646 -> V_631 , V_628 ) ;
}
struct V_435 *
F_242 ( struct V_441 * V_442 )
{
int V_648 ;
T_3 V_641 = F_243 () ;
struct V_435 * V_436 , * V_649 ;
if ( ! ( V_442 -> V_451 & V_549 ) )
return F_173 ( F_168 ( V_442 ) ) ;
F_2 ( & V_442 -> V_527 ) ;
V_436 = F_237 ( & V_442 -> V_528 , V_641 ) ;
if ( V_436 )
F_173 ( V_436 ) ;
F_3 ( & V_442 -> V_527 ) ;
if ( V_436 == NULL ) {
V_649 = F_99 ( sizeof( * V_436 ) , V_116 ) ;
if ( V_649 == NULL )
return F_71 ( - V_83 ) ;
V_649 -> V_581 = V_641 ;
V_649 -> V_582 = F_71 ( - V_568 ) ;
F_210 ( V_650 , & V_649 -> V_439 ) ;
F_210 ( V_438 , & V_649 -> V_439 ) ;
F_173 ( V_649 ) ;
F_2 ( & V_442 -> V_527 ) ;
V_436 = F_237 ( & V_442 -> V_528 , V_641 ) ;
if ( V_436 ) {
F_173 ( V_436 ) ;
F_3 ( & V_442 -> V_527 ) ;
F_11 ( V_649 ) ;
goto V_651;
}
V_436 = V_649 ;
F_211 ( & V_442 -> V_528 , V_436 ) ;
F_3 ( & V_442 -> V_527 ) ;
} else {
V_651:
V_648 = F_244 ( & V_436 -> V_439 , V_650 ,
F_236 ,
V_134 ) ;
if ( V_648 ) {
F_164 ( V_436 ) ;
return F_71 ( V_648 ) ;
}
if ( ! F_125 ( V_436 -> V_582 ) )
return V_436 ;
if ( F_23 ( V_38 , V_436 -> V_440 + V_652 ) ) {
F_164 ( V_436 ) ;
return F_71 ( - V_568 ) ;
}
if ( F_245 ( V_650 , & V_436 -> V_439 ) )
goto V_651;
}
V_436 -> V_582 = F_234 ( V_442 , V_641 ) ;
F_229 ( V_650 , & V_436 -> V_439 ) ;
F_246 ( & V_436 -> V_439 , V_650 ) ;
if ( F_125 ( V_436 -> V_582 ) ) {
F_164 ( V_436 ) ;
return F_71 ( - V_568 ) ;
}
return V_436 ;
}
static void
V_526 ( struct V_46 * V_47 )
{
struct V_441 * V_442 = F_22 ( V_47 , struct V_441 ,
V_525 . V_47 ) ;
struct V_627 * V_628 = & V_442 -> V_528 ;
struct V_629 * V_630 = F_227 ( V_628 ) ;
struct V_629 * V_5 ;
struct V_435 * V_436 ;
F_2 ( & V_442 -> V_527 ) ;
V_630 = F_227 ( V_628 ) ;
while ( V_630 != NULL ) {
V_5 = V_630 ;
V_630 = F_247 ( V_5 ) ;
V_436 = F_228 ( V_5 , struct V_435 , V_631 ) ;
if ( F_166 ( V_583 , & V_436 -> V_439 ) ||
F_60 ( & V_436 -> V_437 ) != 0 ||
F_30 ( V_436 -> V_440 + V_584 , V_38 ) )
continue;
F_173 ( V_436 ) ;
F_229 ( V_438 , & V_436 -> V_439 ) ;
F_230 ( V_5 , V_628 ) ;
F_3 ( & V_442 -> V_527 ) ;
F_164 ( V_436 ) ;
F_2 ( & V_442 -> V_527 ) ;
}
F_3 ( & V_442 -> V_527 ) ;
F_24 ( V_57 , & V_442 -> V_525 ,
V_584 ) ;
}
