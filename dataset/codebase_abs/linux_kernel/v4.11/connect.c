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
return F_55 ( V_2 , V_97 ) ;
}
int
F_55 ( struct V_1 * V_2 , struct V_11 * V_97 )
{
char * V_75 = V_2 -> V_60 ? V_2 -> V_58 : V_2 -> V_61 ;
int V_66 ;
V_66 = V_2 -> V_52 -> V_118 ( V_75 , V_2 -> V_67 , V_2 ) ;
if ( V_66 != 0 )
F_56 ( L_22 , V_75 ,
F_57 (unsigned int, server->total_read, 48 ) ) ;
if ( V_2 -> V_52 -> V_119 &&
V_2 -> V_52 -> V_119 ( V_75 , V_2 , V_66 ) )
return - 1 ;
if ( ! V_97 )
return V_66 ;
F_45 ( V_97 , V_2 , V_75 , V_66 ) ;
return 0 ;
}
static int
F_58 ( void * V_120 )
{
int V_66 ;
struct V_1 * V_2 = V_120 ;
unsigned int V_115 ;
char * V_75 = NULL ;
struct V_121 * V_122 = NULL ;
struct V_11 * V_12 ;
V_123 -> V_30 |= V_124 ;
F_5 ( V_20 , L_23 , F_59 ( V_123 ) ) ;
V_66 = F_60 ( & V_112 ) ;
if ( V_66 > 1 )
F_50 ( V_113 , V_66 + V_114 ) ;
F_61 () ;
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
if ( V_2 -> V_52 -> V_125 &&
V_2 -> V_52 -> V_126 &&
V_2 -> V_52 -> V_125 ( V_75 ) ) {
V_66 = V_2 -> V_52 -> V_126 ( V_2 ,
& V_12 ) ;
} else {
V_12 = V_2 -> V_52 -> V_127 ( V_2 , V_75 ) ;
if ( ! V_12 || ! V_12 -> V_128 )
V_66 = F_51 ( V_2 , V_12 ) ;
else
V_66 = V_12 -> V_128 ( V_2 , V_12 ) ;
}
if ( V_66 < 0 )
continue;
if ( V_2 -> V_60 )
V_75 = V_2 -> V_58 ;
V_2 -> V_37 = V_38 ;
if ( V_12 != NULL ) {
if ( ( V_12 -> V_129 & V_130 ) &&
V_12 -> V_40 == V_100 &&
V_2 -> V_52 -> V_131 )
V_2 -> V_52 -> V_131 (
V_12 -> V_103 ,
V_2 ) ;
if ( ! V_12 -> V_104 || V_12 -> V_132 )
V_12 -> V_43 ( V_12 ) ;
} else if ( V_2 -> V_52 -> V_133 &&
V_2 -> V_52 -> V_133 ( V_75 , V_2 ) ) {
F_5 ( V_20 , L_26 ) ;
} else {
F_5 ( V_59 , L_27 ,
F_62 ( & V_134 ) ) ;
F_56 ( L_28 , V_75 ,
F_28 ( V_2 ) ) ;
#ifdef F_63
if ( V_2 -> V_52 -> V_135 )
V_2 -> V_52 -> V_135 ( V_75 ) ;
F_64 ( V_2 ) ;
#endif
}
}
F_65 ( V_2 -> V_58 ) ;
if ( V_2 -> V_61 )
F_66 ( V_2 -> V_61 ) ;
V_122 = F_67 ( & V_2 -> V_136 , NULL ) ;
F_46 ( V_2 ) ;
if ( ! V_122 ) {
F_68 ( V_137 ) ;
while ( ! F_69 ( V_123 ) ) {
F_70 () ;
F_68 ( V_137 ) ;
}
F_68 ( V_138 ) ;
}
F_71 ( 0 ) ;
}
static char *
F_72 ( const char * V_139 )
{
const char * V_140 ;
char * V_141 , * V_142 ;
unsigned int V_36 ;
V_140 = V_139 + 2 ;
V_142 = strchr ( V_140 , '\\' ) ;
if ( ! V_142 )
return F_73 ( - V_143 ) ;
V_36 = V_142 - V_140 ;
V_141 = F_74 ( ( V_36 + 1 ) , V_144 ) ;
if ( V_141 == NULL )
return F_73 ( - V_145 ) ;
memcpy ( V_141 , V_140 , V_36 ) ;
V_141 [ V_36 ] = '\0' ;
return V_141 ;
}
static int F_75 ( T_1 args [] , unsigned long * V_146 )
{
int V_3 ;
char * string ;
string = F_76 ( args ) ;
if ( string == NULL )
return - V_145 ;
V_3 = F_77 ( string , 0 , V_146 ) ;
F_11 ( string ) ;
return V_3 ;
}
static int F_78 ( T_1 args [] , T_2 * V_147 )
{
unsigned long V_148 ;
T_2 V_149 ;
int V_3 ;
V_3 = F_75 ( args , & V_148 ) ;
if ( V_3 )
return V_3 ;
V_149 = F_79 ( F_80 () , V_148 ) ;
if ( ! F_81 ( V_149 ) )
return - V_143 ;
* V_147 = V_149 ;
return 0 ;
}
static int F_82 ( T_1 args [] , T_3 * V_147 )
{
unsigned long V_148 ;
T_3 V_150 ;
int V_3 ;
V_3 = F_75 ( args , & V_148 ) ;
if ( V_3 )
return V_3 ;
V_150 = F_83 ( F_80 () , V_148 ) ;
if ( ! F_84 ( V_150 ) )
return - V_143 ;
* V_147 = V_150 ;
return 0 ;
}
static int F_85 ( char * V_148 ,
struct V_151 * V_152 )
{
T_1 args [ V_153 ] ;
V_152 -> V_154 = V_155 ;
V_152 -> V_156 = false ;
switch ( F_86 ( V_148 , V_157 , args ) ) {
case V_158 :
F_5 ( V_59 , L_29 ) ;
return 1 ;
case V_159 :
V_152 -> V_156 = true ;
case V_160 :
V_152 -> V_154 = V_161 ;
break;
case V_162 :
V_152 -> V_156 = true ;
case V_163 :
V_152 -> V_154 = V_164 ;
break;
case V_165 :
V_152 -> V_156 = true ;
case V_166 :
V_152 -> V_154 = V_167 ;
break;
case V_168 :
V_152 -> V_156 = true ;
case V_169 :
V_152 -> V_154 = V_170 ;
break;
#ifdef F_87
case V_171 :
V_152 -> V_154 = V_172 ;
break;
#endif
case V_173 :
V_152 -> V_174 = 1 ;
break;
default:
F_5 ( V_59 , L_30 , V_148 ) ;
return 1 ;
}
return 0 ;
}
static int
F_88 ( char * V_148 , struct V_151 * V_152 )
{
T_1 args [ V_153 ] ;
switch ( F_86 ( V_148 , V_175 , args ) ) {
case V_176 :
V_152 -> V_177 = false ;
V_152 -> V_178 = false ;
break;
case V_179 :
V_152 -> V_177 = false ;
V_152 -> V_178 = true ;
break;
case V_180 :
V_152 -> V_177 = true ;
V_152 -> V_178 = false ;
break;
default:
F_5 ( V_59 , L_31 , V_148 ) ;
return 1 ;
}
return 0 ;
}
static int
F_89 ( char * V_148 , struct V_151 * V_152 )
{
T_1 args [ V_153 ] ;
switch ( F_86 ( V_148 , V_181 , args ) ) {
case V_182 :
V_152 -> V_52 = & V_183 ;
V_152 -> V_184 = & V_185 ;
break;
#ifdef F_4
case V_186 :
V_152 -> V_52 = & V_187 ;
V_152 -> V_184 = & V_188 ;
break;
case V_189 :
V_152 -> V_52 = & V_190 ;
V_152 -> V_184 = & V_191 ;
break;
case V_192 :
V_152 -> V_52 = & V_193 ;
V_152 -> V_184 = & V_194 ;
break;
case V_195 :
V_152 -> V_52 = & V_193 ;
V_152 -> V_184 = & V_196 ;
break;
#ifdef F_90
case V_197 :
V_152 -> V_52 = & V_198 ;
V_152 -> V_184 = & V_199 ;
break;
#endif
#endif
default:
F_5 ( V_59 , L_32 , V_148 ) ;
return 1 ;
}
return 0 ;
}
static int
F_91 ( const char * V_200 , struct V_151 * V_152 )
{
char * V_201 ;
const char * V_202 = L_33 ;
T_4 V_36 ;
V_36 = strspn ( V_200 , V_202 ) ;
if ( V_36 != 2 )
return - V_143 ;
V_201 = strpbrk ( V_200 + 2 , V_202 ) ;
if ( ! V_201 )
return - V_143 ;
++ V_201 ;
V_36 = strcspn ( V_201 , V_202 ) ;
V_201 += V_36 ;
V_152 -> V_203 = F_92 ( V_200 , V_201 - V_200 , V_144 ) ;
if ( ! V_152 -> V_203 )
return - V_145 ;
F_93 ( V_152 -> V_203 , '\\' ) ;
if ( * V_201 == '/' || * V_201 == '\\' )
V_201 ++ ;
if ( ! * V_201 )
return 0 ;
V_152 -> V_204 = F_94 ( V_201 , V_144 ) ;
if ( ! V_152 -> V_204 )
return - V_145 ;
return 0 ;
}
static int
F_95 ( const char * V_205 , const char * V_200 ,
struct V_151 * V_152 )
{
char * V_206 , * V_207 ;
char * V_208 = NULL , * V_209 ;
unsigned int V_210 , V_211 , V_212 ;
char V_213 [ 2 ] ;
short int V_214 = - 1 ;
short int V_215 = - 1 ;
bool V_216 = false ;
bool V_217 = false ;
bool V_218 = false ;
char * V_219 = NULL ;
char * V_220 = F_96 () -> V_220 ;
char * string = NULL ;
char * V_221 , * V_148 ;
char V_142 ;
bool V_222 = false ;
unsigned short V_223 = 0 ;
struct V_94 * V_95 = (struct V_94 * ) & V_152 -> V_95 ;
V_213 [ 0 ] = ',' ;
V_213 [ 1 ] = 0 ;
V_142 = V_213 [ 0 ] ;
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
memset ( V_152 -> V_224 , 0x20 , V_225 ) ;
for ( V_211 = 0 ; V_211 < F_97 ( V_220 , V_225 ) ; V_211 ++ )
V_152 -> V_224 [ V_211 ] = toupper ( V_220 [ V_211 ] ) ;
V_152 -> V_224 [ V_225 ] = 0 ;
V_152 -> V_226 [ 0 ] = 0 ;
V_152 -> V_227 = F_98 () ;
V_152 -> V_228 = F_98 () ;
V_152 -> V_229 = F_99 () ;
V_152 -> V_230 = true ;
V_152 -> V_231 = V_152 -> V_232 = V_233 | V_234 | V_235 ;
V_152 -> V_236 = 1 ;
V_152 -> V_237 = 1 ;
V_152 -> V_178 = true ;
V_152 -> V_238 = V_239 ;
V_152 -> V_52 = & V_183 ;
V_152 -> V_184 = & V_185 ;
V_152 -> V_50 = V_240 ;
if ( ! V_205 )
goto V_241;
V_208 = F_92 ( V_205 , V_242 , V_144 ) ;
if ( ! V_208 )
goto V_241;
V_209 = V_208 ;
V_207 = V_209 + strlen ( V_209 ) ;
if ( strncmp ( V_209 , L_34 , 4 ) == 0 ) {
if ( V_209 [ 4 ] != 0 ) {
V_213 [ 0 ] = V_209 [ 4 ] ;
V_209 += 5 ;
} else {
F_5 ( V_20 , L_35 ) ;
}
}
V_152 -> V_243 = false ;
V_152 -> V_244 = false ;
switch ( F_91 ( V_200 , V_152 ) ) {
case 0 :
break;
case - V_145 :
F_5 ( V_59 , L_36 ) ;
goto V_241;
case - V_143 :
F_5 ( V_59 , L_37 ) ;
goto V_241;
default:
F_5 ( V_59 , L_38 ) ;
goto V_241;
}
while ( ( V_206 = F_100 ( & V_209 , V_213 ) ) != NULL ) {
T_1 args [ V_153 ] ;
unsigned long V_146 ;
int V_245 ;
if ( ! * V_206 )
continue;
V_245 = F_86 ( V_206 , V_246 , args ) ;
switch ( V_245 ) {
case V_247 :
break;
case V_248 :
V_152 -> V_249 = 0 ;
break;
case V_250 :
V_152 -> V_249 = 1 ;
break;
case V_251 :
V_214 = 1 ;
break;
case V_252 :
V_214 = 0 ;
break;
case V_253 :
V_215 = 1 ;
break;
case V_254 :
V_215 = 0 ;
break;
case V_255 :
V_152 -> V_256 = 1 ;
break;
case V_257 :
V_152 -> V_258 = 1 ;
break;
case V_259 :
V_152 -> V_260 = 1 ;
break;
case V_261 :
V_152 -> V_260 = 0 ;
break;
case V_262 :
V_152 -> V_263 = 0 ;
break;
case V_264 :
V_152 -> V_263 = 1 ;
break;
case V_265 :
V_152 -> V_266 = true ;
V_152 -> V_230 = false ;
break;
case V_267 :
V_152 -> V_266 = false ;
break;
case V_268 :
V_152 -> V_230 = true ;
V_152 -> V_266 = false ;
break;
case V_269 :
V_152 -> V_230 = false ;
break;
case V_270 :
V_152 -> V_271 = 1 ;
break;
case V_272 :
V_152 -> V_271 = 0 ;
break;
case V_273 :
V_152 -> V_274 = 1 ;
break;
case V_275 :
V_152 -> V_236 = 1 ;
break;
case V_276 :
V_152 -> V_236 = 0 ;
break;
case V_277 :
V_152 -> V_278 = 1 ;
break;
case V_279 :
V_152 -> V_280 = 1 ;
break;
case V_281 :
V_152 -> V_282 = 0 ;
break;
case V_283 :
V_152 -> V_282 = 1 ;
if ( V_152 -> V_232 ==
( V_284 & ~ ( V_285 | V_286 ) ) )
V_152 -> V_232 = V_284 ;
break;
case V_287 :
V_152 -> V_288 = 1 ;
break;
case V_289 :
V_152 -> V_290 = 1 ;
break;
case V_291 :
V_152 -> V_290 = 0 ;
break;
case V_292 :
V_152 -> V_293 = 1 ;
break;
case V_294 :
V_152 -> V_295 = true ;
break;
case V_296 :
V_152 -> V_295 = false ;
break;
case V_297 :
V_152 -> V_260 = 0 ;
break;
case V_298 :
V_152 -> V_260 = 1 ;
break;
case V_299 :
V_152 -> V_300 = 0 ;
break;
case V_301 :
V_152 -> V_300 = 1 ;
break;
case V_302 :
V_152 -> V_303 = 1 ;
break;
case V_304 :
V_152 -> V_303 = 0 ;
break;
case V_305 :
V_152 -> V_237 = 1 ;
break;
case V_306 :
V_152 -> V_237 = 0 ;
break;
case V_307 :
V_152 -> V_308 = 1 ;
break;
case V_309 :
V_152 -> V_310 = 1 ;
break;
case V_311 :
V_152 -> V_310 = 0 ;
break;
case V_312 :
V_152 -> V_313 = 0 ;
break;
case V_314 :
V_152 -> V_313 = 1 ;
break;
case V_315 :
V_152 -> V_316 = 1 ;
break;
case V_317 :
V_152 -> V_156 = true ;
break;
case V_318 :
V_152 -> V_319 = 1 ;
break;
case V_320 :
F_101 ( L_39 ) ;
break;
case V_321 :
#ifndef F_102
F_5 ( V_59 , L_40 ) ;
goto V_241;
#endif
V_152 -> V_322 = true ;
break;
case V_323 :
V_152 -> V_324 = true ;
break;
case V_325 :
V_152 -> V_326 = true ;
break;
case V_327 :
V_218 = true ;
break;
case V_328 :
V_152 -> V_329 = true ;
break;
case V_330 :
V_152 -> V_331 = true ;
if ( V_152 -> V_332 ) {
F_5 ( V_59 ,
L_41 ) ;
goto V_241;
}
break;
case V_333 :
V_152 -> V_332 = true ;
if ( ( V_152 -> V_331 ) || ( V_152 -> V_334 ) ) {
F_5 ( V_59 ,
L_41 ) ;
goto V_241;
}
break;
case V_335 :
V_152 -> V_334 = true ;
if ( V_152 -> V_332 ) {
F_5 ( V_59 ,
L_41 ) ;
goto V_241;
}
break;
case V_336 :
V_152 -> V_334 = false ;
break;
case V_337 :
V_152 -> V_338 = true ;
break;
case V_339 :
if ( F_78 ( args , & V_152 -> V_340 ) ) {
F_5 ( V_59 , L_42 ,
V_21 ) ;
goto V_241;
}
V_152 -> V_243 = true ;
break;
case V_341 :
if ( F_82 ( args , & V_152 -> V_342 ) ) {
F_5 ( V_59 , L_43 ,
V_21 ) ;
goto V_241;
}
V_152 -> V_244 = true ;
break;
case V_343 :
if ( F_78 ( args , & V_152 -> V_228 ) ) {
F_5 ( V_59 , L_44 ,
V_21 ) ;
goto V_241;
}
V_216 = true ;
break;
case V_344 :
if ( F_78 ( args , & V_152 -> V_227 ) ) {
F_5 ( V_59 , L_45 ,
V_21 ) ;
goto V_241;
}
break;
case V_345 :
if ( F_82 ( args , & V_152 -> V_229 ) ) {
F_5 ( V_59 , L_46 ,
V_21 ) ;
goto V_241;
}
V_217 = true ;
break;
case V_346 :
if ( F_75 ( args , & V_146 ) ) {
F_5 ( V_59 , L_47 ,
V_21 ) ;
goto V_241;
}
V_152 -> V_232 = V_146 ;
break;
case V_347 :
if ( F_75 ( args , & V_146 ) ) {
F_5 ( V_59 , L_48 ,
V_21 ) ;
goto V_241;
}
V_152 -> V_231 = V_146 ;
break;
case V_348 :
if ( F_75 ( args , & V_146 ) ||
V_146 > V_349 ) {
F_5 ( V_59 , L_49 ,
V_21 ) ;
goto V_241;
}
V_223 = ( unsigned short ) V_146 ;
break;
case V_350 :
if ( F_75 ( args , & V_146 ) ) {
F_5 ( V_59 , L_50 ,
V_21 ) ;
goto V_241;
}
V_152 -> V_351 = V_146 ;
break;
case V_352 :
if ( F_75 ( args , & V_146 ) ) {
F_5 ( V_59 , L_51 ,
V_21 ) ;
goto V_241;
}
V_152 -> V_353 = V_146 ;
break;
case V_354 :
if ( F_75 ( args , & V_146 ) ) {
F_5 ( V_59 , L_52 ,
V_21 ) ;
goto V_241;
}
V_152 -> V_238 = V_54 * V_146 ;
if ( V_152 -> V_238 > V_355 ) {
F_5 ( V_59 , L_53 ) ;
goto V_241;
}
break;
case V_356 :
if ( F_75 ( args , & V_146 ) ) {
F_5 ( V_59 , L_54 ,
V_21 ) ;
goto V_241;
}
V_152 -> V_50 = V_146 ;
break;
case V_357 :
if ( F_75 ( args , & V_146 ) ) {
F_5 ( V_59 , L_55 ,
V_21 ) ;
goto V_241;
}
V_152 -> V_358 = V_146 ;
break;
case V_359 :
if ( F_75 ( args , & V_146 ) || ( V_146 < 20 ) ||
( V_146 > 60000 ) ) {
F_5 ( V_59 , L_56 ,
V_21 ) ;
goto V_241;
}
V_152 -> V_360 = V_146 ;
break;
case V_361 :
V_152 -> V_174 = 1 ;
V_152 -> V_362 = NULL ;
break;
case V_363 :
string = F_76 ( args ) ;
if ( string == NULL )
goto V_364;
if ( F_97 ( string , V_365 ) >
V_365 ) {
F_101 ( L_57 ) ;
goto V_241;
}
F_11 ( V_152 -> V_362 ) ;
V_152 -> V_362 = F_94 ( string , V_144 ) ;
if ( ! V_152 -> V_362 )
goto V_241;
break;
case V_366 :
V_221 = strchr ( V_206 , '=' ) ;
V_221 ++ ;
if ( ! ( V_221 < V_207 && V_221 [ 1 ] == V_142 ) ) {
F_11 ( V_152 -> V_367 ) ;
V_152 -> V_367 = NULL ;
break;
}
case V_368 :
V_148 = strchr ( V_206 , '=' ) ;
V_148 ++ ;
V_221 = ( char * ) V_148 + strlen ( V_148 ) ;
if ( V_221 < V_207 && V_221 [ 1 ] == V_142 ) {
V_221 [ 0 ] = V_142 ;
while ( ( V_221 = strchr ( V_221 , V_142 ) )
!= NULL && ( V_221 [ 1 ] == V_142 ) ) {
V_221 = ( char * ) & V_221 [ 2 ] ;
}
if ( V_221 ) {
V_221 [ 0 ] = '\0' ;
V_209 = ( char * ) & V_221 [ 1 ] ;
} else
V_209 = V_207 ;
}
F_11 ( V_152 -> V_367 ) ;
V_210 = strlen ( V_148 ) ;
V_152 -> V_367 = F_103 ( V_210 + 1 , V_144 ) ;
if ( V_152 -> V_367 == NULL ) {
F_101 ( L_58 ) ;
goto V_241;
}
for ( V_211 = 0 , V_212 = 0 ; V_211 < V_210 ; V_211 ++ , V_212 ++ ) {
V_152 -> V_367 [ V_212 ] = V_148 [ V_211 ] ;
if ( ( V_148 [ V_211 ] == V_142 ) &&
V_148 [ V_211 + 1 ] == V_142 )
V_211 ++ ;
}
V_152 -> V_367 [ V_212 ] = '\0' ;
break;
case V_369 :
V_222 = false ;
break;
case V_370 :
string = F_76 ( args ) ;
if ( string == NULL )
goto V_364;
if ( ! F_104 ( V_95 , string ,
strlen ( string ) ) ) {
F_105 ( L_59 , string ) ;
goto V_241;
}
V_222 = true ;
break;
case V_371 :
string = F_76 ( args ) ;
if ( string == NULL )
goto V_364;
if ( F_97 ( string , V_372 )
== V_372 ) {
F_101 ( L_60 ) ;
goto V_241;
}
F_11 ( V_152 -> V_373 ) ;
V_152 -> V_373 = F_94 ( string , V_144 ) ;
if ( ! V_152 -> V_373 ) {
F_101 ( L_61 ) ;
goto V_241;
}
F_5 ( V_20 , L_62 ) ;
break;
case V_374 :
string = F_76 ( args ) ;
if ( string == NULL )
goto V_364;
if ( ! F_104 (
(struct V_94 * ) & V_152 -> V_375 ,
string , strlen ( string ) ) ) {
F_101 ( L_63 ,
string ) ;
goto V_241;
}
break;
case V_376 :
string = F_76 ( args ) ;
if ( string == NULL )
goto V_364;
if ( F_97 ( string , 1024 ) >= 65 ) {
F_101 ( L_64 ) ;
goto V_241;
}
if ( strncasecmp ( string , L_65 , 7 ) != 0 ) {
F_11 ( V_152 -> V_377 ) ;
V_152 -> V_377 = F_94 ( string ,
V_144 ) ;
if ( ! V_152 -> V_377 ) {
F_101 ( L_66 ) ;
goto V_241;
}
}
F_5 ( V_20 , L_67 , string ) ;
break;
case V_378 :
string = F_76 ( args ) ;
if ( string == NULL )
goto V_364;
memset ( V_152 -> V_224 , 0x20 ,
V_225 ) ;
for ( V_211 = 0 ; V_211 < V_225 ; V_211 ++ ) {
if ( string [ V_211 ] == 0 )
break;
V_152 -> V_224 [ V_211 ] = string [ V_211 ] ;
}
if ( V_211 == V_225 && string [ V_211 ] != 0 )
F_101 ( L_68 ) ;
break;
case V_379 :
string = F_76 ( args ) ;
if ( string == NULL )
goto V_364;
memset ( V_152 -> V_226 , 0x20 ,
V_380 ) ;
for ( V_211 = 0 ; V_211 < 15 ; V_211 ++ ) {
if ( string [ V_211 ] == 0 )
break;
V_152 -> V_226 [ V_211 ] = string [ V_211 ] ;
}
if ( V_211 == V_225 && string [ V_211 ] != 0 )
F_101 ( L_69 ) ;
break;
case V_381 :
string = F_76 ( args ) ;
if ( string == NULL )
goto V_364;
if ( strncasecmp ( string , L_70 , 1 ) == 0 ) {
break;
}
F_101 ( L_71 ) ;
goto V_241;
case V_382 :
string = F_76 ( args ) ;
if ( string == NULL )
goto V_364;
if ( F_89 ( string , V_152 ) != 0 )
goto V_241;
break;
case V_383 :
string = F_76 ( args ) ;
if ( string == NULL )
goto V_364;
if ( F_85 ( string , V_152 ) != 0 )
goto V_241;
break;
case V_384 :
string = F_76 ( args ) ;
if ( string == NULL )
goto V_364;
if ( F_88 ( string , V_152 ) != 0 )
goto V_241;
break;
default:
if ( ! V_219 )
V_219 = V_206 ;
break;
}
F_11 ( string ) ;
string = NULL ;
}
if ( ! V_218 && V_219 ) {
F_105 ( L_72 , V_219 ) ;
goto V_241;
}
#ifndef F_106
if ( V_152 -> V_326 ) {
F_5 ( V_59 , L_73 ) ;
goto V_241;
}
#endif
if ( ! V_152 -> V_203 ) {
F_5 ( V_59 , L_74 ) ;
goto V_241;
}
if ( ! strchr ( V_152 -> V_203 + 3 , '\\' ) ) {
F_5 ( V_59 , L_75 ) ;
goto V_241;
}
if ( ! V_222 ) {
if ( ! F_104 ( V_95 , & V_152 -> V_203 [ 2 ] ,
strlen ( & V_152 -> V_203 [ 2 ] ) ) ) {
F_105 ( L_76 ) ;
goto V_241;
}
}
F_42 ( V_95 , V_223 ) ;
if ( V_216 )
V_152 -> V_214 = V_214 ;
else if ( V_214 == 1 )
F_107 ( L_77 ) ;
if ( V_217 )
V_152 -> V_215 = V_215 ;
else if ( V_215 == 1 )
F_107 ( L_78 ) ;
F_11 ( V_208 ) ;
return 0 ;
V_364:
F_101 ( L_79 ) ;
V_241:
F_11 ( string ) ;
F_11 ( V_208 ) ;
return 1 ;
}
static bool
F_108 ( struct V_94 * V_375 , struct V_94 * V_385 )
{
switch ( V_375 -> V_386 ) {
case V_387 :
return ( V_385 -> V_386 == V_387 ) ;
case V_388 : {
struct V_389 * V_390 = (struct V_389 * ) V_375 ;
struct V_389 * V_391 = (struct V_389 * ) V_385 ;
return ( V_390 -> V_392 . V_393 == V_391 -> V_392 . V_393 ) ;
}
case V_394 : {
struct V_395 * V_396 = (struct V_395 * ) V_375 ;
struct V_395 * V_397 = (struct V_395 * ) V_385 ;
return F_109 ( & V_396 -> V_398 , & V_397 -> V_398 ) ;
}
default:
F_110 ( 1 ) ;
return false ;
}
}
static bool
F_111 ( struct V_1 * V_2 , struct V_94 * V_399 )
{
T_5 V_223 , * V_400 ;
switch ( V_399 -> V_386 ) {
case V_388 :
V_400 = & ( (struct V_389 * ) & V_2 -> V_95 ) -> V_401 ;
V_223 = ( (struct V_389 * ) V_399 ) -> V_401 ;
break;
case V_394 :
V_400 = & ( (struct V_395 * ) & V_2 -> V_95 ) -> V_402 ;
V_223 = ( (struct V_395 * ) V_399 ) -> V_402 ;
break;
default:
F_110 ( 1 ) ;
return false ;
}
if ( ! V_223 ) {
V_223 = F_112 ( V_96 ) ;
if ( V_223 == * V_400 )
return true ;
V_223 = F_112 ( V_403 ) ;
}
return V_223 == * V_400 ;
}
static bool
F_113 ( struct V_1 * V_2 , struct V_94 * V_399 ,
struct V_94 * V_375 )
{
switch ( V_399 -> V_386 ) {
case V_388 : {
struct V_389 * V_404 = (struct V_389 * ) V_399 ;
struct V_389 * V_405 =
(struct V_389 * ) & V_2 -> V_95 ;
if ( V_404 -> V_392 . V_393 != V_405 -> V_392 . V_393 )
return false ;
break;
}
case V_394 : {
struct V_395 * V_406 = (struct V_395 * ) V_399 ;
struct V_395 * V_407 =
(struct V_395 * ) & V_2 -> V_95 ;
if ( ! F_109 ( & V_406 -> V_398 ,
& V_407 -> V_398 ) )
return false ;
if ( V_406 -> V_408 != V_407 -> V_408 )
return false ;
break;
}
default:
F_110 ( 1 ) ;
return false ;
}
if ( ! F_108 ( V_375 , (struct V_94 * ) & V_2 -> V_375 ) )
return false ;
return true ;
}
static bool
F_114 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
if ( V_2 -> V_52 -> V_409 ( V_2 , V_152 -> V_154 )
== V_155 )
return false ;
if ( V_152 -> V_156 && ! V_2 -> V_156 )
return false ;
return true ;
}
static int F_115 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
struct V_94 * V_399 = (struct V_94 * ) & V_152 -> V_95 ;
if ( V_152 -> V_329 )
return 0 ;
if ( ( V_2 -> V_184 != V_152 -> V_184 ) || ( V_2 -> V_52 != V_152 -> V_52 ) )
return 0 ;
if ( ! F_116 ( F_117 ( V_2 ) , V_123 -> V_410 -> V_411 ) )
return 0 ;
if ( ! F_113 ( V_2 , V_399 ,
(struct V_94 * ) & V_152 -> V_375 ) )
return 0 ;
if ( ! F_111 ( V_2 , V_399 ) )
return 0 ;
if ( ! F_114 ( V_2 , V_152 ) )
return 0 ;
if ( V_2 -> V_50 != V_152 -> V_50 * V_54 )
return 0 ;
return 1 ;
}
static struct V_1 *
F_118 ( struct V_151 * V_152 )
{
struct V_1 * V_2 ;
F_2 ( & V_22 ) ;
F_119 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_115 ( V_2 , V_152 ) )
continue;
++ V_2 -> V_412 ;
F_3 ( & V_22 ) ;
F_5 ( V_20 , L_80 ) ;
return V_2 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
void
F_120 ( struct V_1 * V_2 , int V_413 )
{
struct V_121 * V_414 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_412 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_121 ( F_117 ( V_2 ) ) ;
F_16 ( & V_2 -> V_105 ) ;
F_3 ( & V_22 ) ;
F_122 ( & V_2 -> V_47 ) ;
#ifdef F_4
if ( V_413 )
F_123 ( & V_2 -> V_415 ) ;
else
F_122 ( & V_2 -> V_415 ) ;
#endif
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
F_11 ( V_2 -> V_34 . V_35 ) ;
V_2 -> V_34 . V_35 = NULL ;
V_2 -> V_34 . V_36 = 0 ;
V_414 = F_67 ( & V_2 -> V_136 , NULL ) ;
if ( V_414 )
F_126 ( V_416 , V_414 ) ;
}
static struct V_1 *
F_127 ( struct V_151 * V_417 )
{
struct V_1 * V_418 = NULL ;
int V_3 ;
F_5 ( V_20 , L_81 , V_417 -> V_203 ) ;
V_418 = F_118 ( V_417 ) ;
if ( V_418 )
return V_418 ;
V_418 = F_103 ( sizeof( struct V_1 ) , V_144 ) ;
if ( ! V_418 ) {
V_3 = - V_145 ;
goto V_419;
}
V_418 -> V_52 = V_417 -> V_52 ;
V_418 -> V_184 = V_417 -> V_184 ;
F_128 ( V_418 , F_129 ( V_123 -> V_410 -> V_411 ) ) ;
V_418 -> V_57 = F_72 ( V_417 -> V_203 ) ;
if ( F_130 ( V_418 -> V_57 ) ) {
V_3 = F_131 ( V_418 -> V_57 ) ;
goto V_420;
}
V_418 -> V_256 = V_417 -> V_256 ;
V_418 -> V_258 = V_417 -> V_258 ;
V_418 -> V_421 = V_417 -> V_422 ;
V_418 -> V_423 = 0 ;
V_418 -> V_107 = 1 ;
F_132 ( & V_418 -> V_63 ) ;
F_132 ( & V_418 -> V_108 ) ;
F_12 ( & V_418 -> V_109 ) ;
F_133 ( & V_418 -> V_27 ) ;
memcpy ( V_418 -> V_424 ,
V_417 -> V_224 , V_380 ) ;
memcpy ( V_418 -> V_425 ,
V_417 -> V_226 , V_380 ) ;
V_418 -> V_33 = false ;
V_418 -> V_32 = 0 ;
V_418 -> V_37 = V_38 ;
F_134 ( & V_418 -> V_106 ) ;
F_12 ( & V_418 -> V_105 ) ;
F_12 ( & V_418 -> V_23 ) ;
F_135 ( & V_418 -> V_47 , F_22 ) ;
#ifdef F_4
F_135 ( & V_418 -> V_415 , V_426 ) ;
F_133 ( & V_418 -> V_427 ) ;
#endif
memcpy ( & V_418 -> V_375 , & V_417 -> V_375 ,
sizeof( V_418 -> V_375 ) ) ;
memcpy ( & V_418 -> V_95 , & V_417 -> V_95 ,
sizeof( V_418 -> V_95 ) ) ;
#ifdef F_4
F_136 ( V_418 -> V_428 ) ;
#endif
V_418 -> V_15 = V_51 ;
++ V_418 -> V_412 ;
if ( V_417 -> V_50 >= V_429 &&
V_417 -> V_50 <= V_430 )
V_418 -> V_50 = V_417 -> V_50 * V_54 ;
else
V_418 -> V_50 = V_240 * V_54 ;
V_3 = F_137 ( V_418 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_82 ) ;
goto V_420;
}
F_138 ( V_431 ) ;
V_418 -> V_136 = F_139 ( F_58 ,
V_418 , L_83 ) ;
if ( F_130 ( V_418 -> V_136 ) ) {
V_3 = F_131 ( V_418 -> V_136 ) ;
F_5 ( V_59 , L_84 , V_3 ) ;
F_140 ( V_431 ) ;
goto V_420;
}
V_418 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_141 ( & V_418 -> V_105 , & V_432 ) ;
F_3 ( & V_22 ) ;
F_142 ( V_418 ) ;
F_25 ( V_46 , & V_418 -> V_47 , V_418 -> V_50 ) ;
return V_418 ;
V_420:
F_124 ( V_418 ) ;
F_121 ( F_117 ( V_418 ) ) ;
V_419:
if ( V_418 ) {
if ( ! F_130 ( V_418 -> V_57 ) )
F_11 ( V_418 -> V_57 ) ;
if ( V_418 -> V_28 )
F_10 ( V_418 -> V_28 ) ;
F_11 ( V_418 ) ;
}
return F_73 ( V_3 ) ;
}
static int F_143 ( struct V_7 * V_8 , struct V_151 * V_152 )
{
if ( V_152 -> V_154 != V_155 &&
V_152 -> V_154 != V_8 -> V_154 )
return 0 ;
switch ( V_8 -> V_154 ) {
case V_161 :
if ( ! F_144 ( V_152 -> V_227 , V_8 -> V_227 ) )
return 0 ;
break;
default:
if ( V_8 -> V_433 == NULL ) {
if ( ! V_152 -> V_174 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_433 ,
V_152 -> V_362 ? V_152 -> V_362 : L_85 ,
V_365 ) )
return 0 ;
if ( ( V_152 -> V_362 && strlen ( V_152 -> V_362 ) != 0 ) &&
V_8 -> V_367 != NULL &&
strncmp ( V_8 -> V_367 ,
V_152 -> V_367 ? V_152 -> V_367 : L_85 ,
V_434 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_145 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
struct V_7 * V_8 ;
F_2 ( & V_22 ) ;
F_119 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_8 -> V_435 == V_16 )
continue;
if ( ! F_143 ( V_8 , V_152 ) )
continue;
++ V_8 -> V_436 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_146 ( struct V_7 * V_8 )
{
unsigned int V_3 , V_437 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_20 , L_86 , V_21 , V_8 -> V_436 ) ;
F_2 ( & V_22 ) ;
if ( V_8 -> V_435 == V_16 ) {
F_3 ( & V_22 ) ;
return;
}
if ( -- V_8 -> V_436 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
if ( V_8 -> V_435 == V_62 )
V_8 -> V_435 = V_16 ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_435 == V_16 && V_2 -> V_52 -> V_438 ) {
V_437 = F_147 () ;
V_3 = V_2 -> V_52 -> V_438 ( V_437 , V_8 ) ;
if ( V_3 )
F_5 ( V_59 , L_87 ,
V_21 , V_3 ) ;
F_148 ( V_437 ) ;
}
F_2 ( & V_22 ) ;
F_16 ( & V_8 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_149 ( V_8 ) ;
F_120 ( V_2 , 0 ) ;
}
static int
F_150 ( struct V_151 * V_152 , struct V_7 * V_8 )
{
int V_3 = 0 ;
const char * V_142 , * V_439 ;
char * V_440 ;
T_6 V_36 ;
struct V_441 * V_441 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_389 * V_442 ;
struct V_395 * V_443 ;
const struct V_444 * V_445 ;
V_440 = F_74 ( V_446 , V_144 ) ;
if ( ! V_440 )
return - V_145 ;
switch ( V_2 -> V_95 . V_447 ) {
case V_388 :
V_442 = (struct V_389 * ) & V_2 -> V_95 ;
sprintf ( V_440 , L_88 , & V_442 -> V_392 . V_393 ) ;
break;
case V_394 :
V_443 = (struct V_395 * ) & V_2 -> V_95 ;
sprintf ( V_440 , L_89 , & V_443 -> V_398 . V_448 ) ;
break;
default:
F_5 ( V_20 , L_90 ,
V_2 -> V_95 . V_447 ) ;
V_3 = - V_143 ;
goto V_419;
}
F_5 ( V_20 , L_91 , V_21 , V_440 ) ;
V_441 = F_151 ( & V_449 , V_440 , L_85 ) ;
if ( F_130 ( V_441 ) ) {
if ( ! V_8 -> V_450 ) {
F_5 ( V_20 , L_92 ) ;
V_3 = F_131 ( V_441 ) ;
goto V_419;
}
sprintf ( V_440 , L_93 , V_8 -> V_450 ) ;
F_5 ( V_20 , L_91 , V_21 , V_440 ) ;
V_441 = F_151 ( & V_449 , V_440 , L_85 ) ;
if ( F_130 ( V_441 ) ) {
V_3 = F_131 ( V_441 ) ;
goto V_419;
}
}
F_152 ( & V_441 -> V_451 ) ;
V_445 = F_153 ( V_441 ) ;
if ( F_154 ( V_445 ) ) {
V_3 = V_445 ? F_131 ( V_445 ) : - V_143 ;
goto V_452;
}
V_439 = V_445 -> V_206 ;
V_142 = F_155 ( V_439 , V_445 -> V_453 , ':' ) ;
F_5 ( V_20 , L_94 , V_439 ) ;
if ( ! V_142 ) {
F_5 ( V_20 , L_95 ,
V_445 -> V_453 ) ;
V_3 = - V_143 ;
goto V_452;
}
V_36 = V_142 - V_439 ;
if ( V_36 > V_365 || V_36 <= 0 ) {
F_5 ( V_20 , L_96 ,
V_36 ) ;
V_3 = - V_143 ;
goto V_452;
}
V_152 -> V_362 = F_92 ( V_439 , V_36 , V_144 ) ;
if ( ! V_152 -> V_362 ) {
F_5 ( V_20 , L_97 ,
V_36 ) ;
V_3 = - V_145 ;
goto V_452;
}
F_5 ( V_20 , L_98 , V_21 , V_152 -> V_362 ) ;
V_36 = V_441 -> V_453 - ( V_36 + 1 ) ;
if ( V_36 > V_434 || V_36 <= 0 ) {
F_5 ( V_20 , L_99 , V_36 ) ;
V_3 = - V_143 ;
F_11 ( V_152 -> V_362 ) ;
V_152 -> V_362 = NULL ;
goto V_452;
}
++ V_142 ;
V_152 -> V_367 = F_92 ( V_142 , V_36 , V_144 ) ;
if ( ! V_152 -> V_367 ) {
F_5 ( V_20 , L_100 ,
V_36 ) ;
V_3 = - V_145 ;
F_11 ( V_152 -> V_362 ) ;
V_152 -> V_362 = NULL ;
goto V_452;
}
V_452:
F_156 ( & V_441 -> V_451 ) ;
F_157 ( V_441 ) ;
V_419:
F_11 ( V_440 ) ;
F_5 ( V_20 , L_101 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_158 ( struct V_1 * V_2 , struct V_151 * V_417 )
{
int V_3 = - V_145 ;
unsigned int V_437 ;
struct V_7 * V_8 ;
struct V_389 * V_399 = (struct V_389 * ) & V_2 -> V_95 ;
struct V_395 * V_406 = (struct V_395 * ) & V_2 -> V_95 ;
V_437 = F_147 () ;
V_8 = F_145 ( V_2 , V_417 ) ;
if ( V_8 ) {
F_5 ( V_20 , L_102 ,
V_8 -> V_435 ) ;
F_8 ( & V_8 -> V_454 ) ;
V_3 = F_159 ( V_437 , V_8 ) ;
if ( V_3 ) {
F_15 ( & V_8 -> V_454 ) ;
F_146 ( V_8 ) ;
F_160 ( V_437 ) ;
return F_73 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_5 ( V_20 , L_103 ) ;
V_3 = F_161 ( V_437 , V_8 ,
V_417 -> V_455 ) ;
if ( V_3 ) {
F_15 ( & V_8 -> V_454 ) ;
F_146 ( V_8 ) ;
F_160 ( V_437 ) ;
return F_73 ( V_3 ) ;
}
}
F_15 ( & V_8 -> V_454 ) ;
F_120 ( V_2 , 0 ) ;
F_160 ( V_437 ) ;
return V_8 ;
}
F_5 ( V_20 , L_104 ) ;
V_8 = F_162 () ;
if ( V_8 == NULL )
goto V_456;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_95 . V_447 == V_394 )
sprintf ( V_8 -> V_457 , L_105 , & V_406 -> V_398 ) ;
else
sprintf ( V_8 -> V_457 , L_106 , & V_399 -> V_392 ) ;
if ( V_417 -> V_362 ) {
V_8 -> V_433 = F_94 ( V_417 -> V_362 , V_144 ) ;
if ( ! V_8 -> V_433 )
goto V_456;
}
if ( V_417 -> V_367 ) {
V_8 -> V_367 = F_94 ( V_417 -> V_367 , V_144 ) ;
if ( ! V_8 -> V_367 )
goto V_456;
}
if ( V_417 -> V_373 ) {
V_8 -> V_450 = F_94 ( V_417 -> V_373 , V_144 ) ;
if ( ! V_8 -> V_450 )
goto V_456;
}
if ( V_417 -> V_338 )
V_8 -> V_458 = V_417 -> V_338 ;
V_8 -> V_227 = V_417 -> V_227 ;
V_8 -> V_228 = V_417 -> V_228 ;
V_8 -> V_154 = V_417 -> V_154 ;
V_8 -> V_156 = V_417 -> V_156 ;
F_8 ( & V_8 -> V_454 ) ;
V_3 = F_159 ( V_437 , V_8 ) ;
if ( ! V_3 )
V_3 = F_161 ( V_437 , V_8 , V_417 -> V_455 ) ;
F_15 ( & V_8 -> V_454 ) ;
if ( V_3 )
goto V_456;
F_2 ( & V_22 ) ;
F_141 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_160 ( V_437 ) ;
return V_8 ;
V_456:
F_149 ( V_8 ) ;
F_160 ( V_437 ) ;
return F_73 ( V_3 ) ;
}
static int F_163 ( struct V_9 * V_10 , struct V_151 * V_417 )
{
if ( V_10 -> V_459 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_460 , V_417 -> V_203 , V_461 ) )
return 0 ;
if ( V_10 -> V_319 != V_417 -> V_319 )
return 0 ;
#ifdef F_4
if ( V_10 -> V_358 != V_417 -> V_358 )
return 0 ;
#endif
return 1 ;
}
static struct V_9 *
F_164 ( struct V_7 * V_8 , struct V_151 * V_417 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_22 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_26 ) ;
if ( ! F_163 ( V_10 , V_417 ) )
continue;
++ V_10 -> V_462 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
void
F_165 ( struct V_9 * V_10 )
{
unsigned int V_437 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( V_20 , L_107 , V_21 , V_10 -> V_462 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_462 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_437 = F_147 () ;
if ( V_8 -> V_2 -> V_52 -> V_463 )
V_8 -> V_2 -> V_52 -> V_463 ( V_437 , V_10 ) ;
F_148 ( V_437 ) ;
F_166 ( V_10 ) ;
F_167 ( V_10 ) ;
F_146 ( V_8 ) ;
}
static struct V_9 *
F_168 ( struct V_7 * V_8 , struct V_151 * V_417 )
{
int V_3 , V_437 ;
struct V_9 * V_10 ;
V_10 = F_164 ( V_8 , V_417 ) ;
if ( V_10 ) {
F_5 ( V_20 , L_108 ) ;
F_146 ( V_8 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_52 -> V_464 ) {
V_3 = - V_56 ;
goto V_465;
}
V_10 = F_169 () ;
if ( V_10 == NULL ) {
V_3 = - V_145 ;
goto V_465;
}
if ( V_417 -> V_358 ) {
#ifdef F_4
if ( V_8 -> V_2 -> V_184 -> V_466 == 0 ) {
F_5 ( V_59 ,
L_109 ) ;
V_3 = - V_467 ;
goto V_465;
} else
V_10 -> V_358 = V_417 -> V_358 ;
#else
F_5 ( V_59 , L_110 ) ;
V_3 = - V_467 ;
goto V_465;
#endif
}
V_10 -> V_8 = V_8 ;
if ( V_417 -> V_367 ) {
V_10 -> V_367 = F_94 ( V_417 -> V_367 , V_144 ) ;
if ( ! V_10 -> V_367 ) {
V_3 = - V_145 ;
goto V_465;
}
}
V_437 = F_147 () ;
V_3 = V_8 -> V_2 -> V_52 -> V_464 ( V_437 , V_8 , V_417 -> V_203 , V_10 ,
V_417 -> V_455 ) ;
F_160 ( V_437 ) ;
F_5 ( V_20 , L_111 , V_3 ) ;
if ( V_3 )
goto V_465;
if ( V_417 -> V_274 ) {
V_10 -> V_468 &= ~ V_469 ;
F_5 ( V_20 , L_112 , V_10 -> V_468 ) ;
}
V_10 -> V_470 = false ;
if ( V_417 -> V_332 ) {
if ( V_8 -> V_2 -> V_184 -> V_466 == 0 ) {
F_5 ( V_59 ,
L_113 ) ;
V_3 = - V_467 ;
goto V_465;
#ifdef F_4
} else if ( V_8 -> V_2 -> V_471 &
V_472 )
V_10 -> V_470 = true ;
else {
F_5 ( V_59 ,
L_114 ) ;
V_3 = - V_467 ;
goto V_465;
#endif
}
#ifdef F_4
} else if ( ( V_10 -> V_471 & V_473 )
&& ( V_8 -> V_2 -> V_471 & V_472 )
&& ( V_417 -> V_331 == false ) ) {
F_5 ( V_20 , L_115 ) ;
V_10 -> V_470 = true ;
#endif
} else if ( V_417 -> V_334 ) {
if ( V_8 -> V_2 -> V_184 -> V_466 == 0 ) {
F_5 ( V_59 ,
L_116 ) ;
V_3 = - V_467 ;
goto V_465;
}
V_10 -> V_474 = true ;
}
if ( V_417 -> V_319 ) {
if ( V_8 -> V_2 -> V_184 -> V_466 == 0 ) {
F_5 ( V_59 ,
L_117 ) ;
V_3 = - V_467 ;
goto V_465;
#ifdef F_4
} else if ( V_10 -> V_8 -> V_2 -> V_471 &
V_475 )
V_10 -> V_319 = true ;
else {
F_5 ( V_59 , L_118 ) ;
V_3 = - V_467 ;
goto V_465;
#endif
}
}
V_10 -> V_260 = V_417 -> V_260 ;
V_10 -> V_280 = V_417 -> V_280 ;
V_10 -> V_316 = V_417 -> V_316 ;
F_12 ( & V_10 -> V_476 ) ;
F_2 ( & V_22 ) ;
F_141 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_170 ( V_10 ) ;
return V_10 ;
V_465:
F_167 ( V_10 ) ;
return F_73 ( V_3 ) ;
}
void
F_171 ( struct V_477 * V_478 )
{
if ( ! V_478 || F_130 ( V_478 ) )
return;
if ( ! F_172 ( & V_478 -> V_479 ) ||
F_173 ( V_480 , & V_478 -> V_481 ) ) {
V_478 -> V_482 = V_38 ;
return;
}
if ( ! F_130 ( F_174 ( V_478 ) ) )
F_165 ( F_174 ( V_478 ) ) ;
F_11 ( V_478 ) ;
return;
}
static inline struct V_477 *
F_175 ( struct V_483 * V_484 )
{
return V_484 -> V_485 ;
}
static int
F_176 ( struct V_486 * V_487 , struct V_488 * V_489 )
{
struct V_483 * V_490 = F_177 ( V_487 ) ;
struct V_483 * V_491 = V_489 -> V_484 ;
if ( ( V_487 -> V_492 & V_493 ) != ( V_489 -> V_30 & V_493 ) )
return 0 ;
if ( ( V_490 -> V_494 & V_495 ) !=
( V_491 -> V_494 & V_495 ) )
return 0 ;
if ( V_491 -> V_353 && V_491 -> V_353 < V_490 -> V_353 )
return 0 ;
if ( V_491 -> V_351 && V_491 -> V_351 < V_490 -> V_351 )
return 0 ;
if ( ! F_144 ( V_490 -> V_496 , V_491 -> V_496 ) || ! F_178 ( V_490 -> V_497 , V_491 -> V_497 ) )
return 0 ;
if ( V_490 -> V_498 != V_491 -> V_498 ||
V_490 -> V_499 != V_491 -> V_499 )
return 0 ;
if ( strcmp ( V_490 -> V_455 -> V_500 , V_491 -> V_455 -> V_500 ) )
return 0 ;
if ( V_490 -> V_238 != V_491 -> V_238 )
return 0 ;
return 1 ;
}
static int
F_179 ( struct V_486 * V_487 , struct V_488 * V_489 )
{
struct V_483 * V_490 = F_177 ( V_487 ) ;
struct V_483 * V_491 = V_489 -> V_484 ;
if ( V_490 -> V_494 & V_501 ) {
if ( ! ( V_491 -> V_494 & V_501 ) )
return 0 ;
if ( strcmp ( V_491 -> V_204 , V_490 -> V_204 ) )
return 0 ;
return 1 ;
}
return 0 ;
}
int
F_180 ( struct V_486 * V_487 , void * V_206 )
{
struct V_488 * V_489 = (struct V_488 * ) V_206 ;
struct V_151 * V_417 ;
struct V_483 * V_484 ;
struct V_1 * V_502 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_477 * V_478 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_484 = F_177 ( V_487 ) ;
V_478 = F_181 ( F_175 ( V_484 ) ) ;
if ( F_130 ( V_478 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_174 ( V_478 ) ;
V_8 = V_10 -> V_8 ;
V_502 = V_8 -> V_2 ;
V_417 = V_489 -> V_152 ;
if ( ! F_115 ( V_502 , V_417 ) ||
! F_143 ( V_8 , V_417 ) ||
! F_163 ( V_10 , V_417 ) ||
! F_179 ( V_487 , V_489 ) ) {
V_3 = 0 ;
goto V_503;
}
V_3 = F_176 ( V_487 , V_489 ) ;
V_503:
F_3 ( & V_22 ) ;
F_171 ( V_478 ) ;
return V_3 ;
}
int
F_182 ( const unsigned int V_437 , struct V_7 * V_8 , const char * V_504 ,
const struct V_505 * V_506 , unsigned int * V_507 ,
struct V_508 * * V_509 , int V_230 )
{
char * V_510 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_52 -> V_464 || ! V_8 -> V_2 -> V_52 -> V_511 )
return - V_56 ;
* V_507 = 0 ;
* V_509 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_510 = F_74 ( 2 +
F_97 ( V_8 -> V_457 , V_512 * 2 )
+ 1 + 4 + 2 , V_144 ) ;
if ( V_510 == NULL )
return - V_145 ;
V_510 [ 0 ] = '\\' ;
V_510 [ 1 ] = '\\' ;
strcpy ( V_510 + 2 , V_8 -> V_457 ) ;
strcpy ( V_510 + 2 + strlen ( V_8 -> V_457 ) , L_119 ) ;
V_3 = V_8 -> V_2 -> V_52 -> V_464 ( V_437 , V_8 , V_510 , NULL ,
V_506 ) ;
F_5 ( V_20 , L_120 , V_3 , V_8 -> V_25 ) ;
F_11 ( V_510 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_52 -> V_511 ( V_437 , V_8 , V_504 ,
V_509 , V_507 ,
V_506 , V_230 ) ;
return V_3 ;
}
static inline void
F_183 ( struct V_513 * V_514 )
{
struct V_514 * V_515 = V_514 -> V_515 ;
F_184 ( ! F_185 ( V_515 ) ) ;
F_186 ( V_515 , L_121 ,
& V_516 [ 0 ] , L_122 , & V_517 [ 0 ] ) ;
}
static inline void
F_187 ( struct V_513 * V_514 )
{
struct V_514 * V_515 = V_514 -> V_515 ;
F_184 ( ! F_185 ( V_515 ) ) ;
F_186 ( V_515 , L_123 ,
& V_516 [ 1 ] , L_124 , & V_517 [ 1 ] ) ;
}
static inline void
F_183 ( struct V_513 * V_514 )
{
}
static inline void
F_187 ( struct V_513 * V_514 )
{
}
static void F_188 ( char * V_518 , char * V_519 , unsigned int V_66 )
{
unsigned int V_211 , V_212 ;
for ( V_211 = 0 , V_212 = 0 ; V_211 < ( V_66 ) ; V_211 ++ ) {
V_518 [ V_212 ] = 'A' + ( 0x0F & ( V_519 [ V_211 ] >> 4 ) ) ;
V_518 [ V_212 + 1 ] = 'A' + ( 0x0F & V_519 [ V_211 ] ) ;
V_212 += 2 ;
}
}
static int
F_189 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_375 . V_447 != V_387 ) {
struct V_513 * V_513 = V_2 -> V_28 ;
V_3 = V_513 -> V_52 -> V_520 ( V_513 ,
(struct V_94 * ) & V_2 -> V_375 ,
sizeof( V_2 -> V_375 ) ) ;
if ( V_3 < 0 ) {
struct V_389 * V_390 ;
struct V_395 * V_396 ;
V_390 = (struct V_389 * ) & V_2 -> V_375 ;
V_396 = (struct V_395 * ) & V_2 -> V_375 ;
if ( V_396 -> V_521 == V_394 )
F_5 ( V_59 , L_125 ,
& V_396 -> V_398 , V_3 ) ;
else
F_5 ( V_59 , L_126 ,
& V_390 -> V_392 . V_393 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_190 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_522 * V_523 ;
struct V_524 * V_525 ;
V_523 = F_103 ( sizeof( struct V_522 ) ,
V_144 ) ;
if ( V_523 ) {
V_523 -> V_526 . V_527 . V_528 = 32 ;
if ( V_2 -> V_425 [ 0 ] != 0 )
F_188 ( V_523 -> V_526 .
V_527 . V_529 ,
V_2 -> V_425 ,
V_380 ) ;
else
F_188 ( V_523 -> V_526 .
V_527 . V_529 ,
V_530 ,
V_380 ) ;
V_523 -> V_526 . V_527 . V_531 = 32 ;
if ( V_2 -> V_424 [ 0 ] != 0 )
F_188 ( V_523 -> V_526 .
V_527 . V_532 ,
V_2 -> V_424 ,
V_380 ) ;
else
F_188 ( V_523 -> V_526 .
V_527 . V_532 ,
L_127 ,
V_380 ) ;
V_523 -> V_526 . V_527 . V_533 = 0 ;
V_523 -> V_526 . V_527 . V_534 = 0 ;
V_525 = (struct V_524 * ) V_523 ;
V_525 -> V_535 = F_191 ( 0x81000044 ) ;
V_3 = F_192 ( V_2 , V_525 , 0x44 ) ;
F_11 ( V_523 ) ;
F_36 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_400 ;
int V_536 , V_537 ;
struct V_513 * V_513 = V_2 -> V_28 ;
struct V_94 * V_538 ;
V_538 = (struct V_94 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_447 == V_394 ) {
V_400 = ( (struct V_395 * ) V_538 ) -> V_402 ;
V_536 = sizeof( struct V_395 ) ;
V_537 = V_394 ;
} else {
V_400 = ( (struct V_389 * ) V_538 ) -> V_401 ;
V_536 = sizeof( struct V_389 ) ;
V_537 = V_388 ;
}
if ( V_513 == NULL ) {
V_3 = F_193 ( F_117 ( V_2 ) , V_537 , V_539 ,
V_540 , & V_513 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_128 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_5 ( V_20 , L_129 ) ;
V_2 -> V_28 = V_513 ;
V_513 -> V_515 -> V_541 = V_542 ;
if ( V_537 == V_394 )
F_187 ( V_513 ) ;
else
F_183 ( V_513 ) ;
}
V_3 = F_189 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_513 -> V_515 -> V_543 = 7 * V_54 ;
V_513 -> V_515 -> V_544 = 5 * V_54 ;
if ( V_2 -> V_258 ) {
if ( V_513 -> V_515 -> V_545 < ( 200 * 1024 ) )
V_513 -> V_515 -> V_545 = 200 * 1024 ;
if ( V_513 -> V_515 -> V_546 < ( 140 * 1024 ) )
V_513 -> V_515 -> V_546 = 140 * 1024 ;
}
if ( V_2 -> V_421 ) {
int V_547 = 1 ;
V_3 = F_194 ( V_513 , V_548 , V_549 ,
( char * ) & V_547 , sizeof( V_547 ) ) ;
if ( V_3 )
F_5 ( V_20 , L_130 ,
V_3 ) ;
}
F_5 ( V_20 , L_131 ,
V_513 -> V_515 -> V_545 ,
V_513 -> V_515 -> V_546 , V_513 -> V_515 -> V_543 ) ;
V_3 = V_513 -> V_52 -> V_550 ( V_513 , V_538 , V_536 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_20 , L_132 , V_3 ) ;
F_10 ( V_513 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_400 == F_112 ( V_403 ) )
V_3 = F_190 ( V_2 ) ;
return V_3 ;
}
static int
F_137 ( struct V_1 * V_2 )
{
T_5 * V_400 ;
struct V_395 * V_406 = (struct V_395 * ) & V_2 -> V_95 ;
struct V_389 * V_399 = (struct V_389 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_447 == V_394 )
V_400 = & V_406 -> V_402 ;
else
V_400 = & V_399 -> V_401 ;
if ( * V_400 == 0 ) {
int V_3 ;
* V_400 = F_112 ( V_96 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_400 = F_112 ( V_403 ) ;
}
return F_18 ( V_2 ) ;
}
void F_195 ( unsigned int V_437 , struct V_9 * V_10 ,
struct V_483 * V_484 , struct V_151 * V_551 )
{
T_7 V_552 = F_196 ( V_10 -> V_553 . V_554 ) ;
if ( V_551 && V_551 -> V_278 ) {
V_10 -> V_553 . V_554 = 0 ;
V_10 -> V_555 = 0 ;
F_5 ( V_20 , L_133 ) ;
return;
} else if ( V_551 )
V_10 -> V_555 = 1 ;
if ( V_10 -> V_555 == 0 ) {
F_5 ( V_20 , L_134 ) ;
return;
}
if ( ! F_197 ( V_437 , V_10 ) ) {
T_7 V_556 = F_196 ( V_10 -> V_553 . V_554 ) ;
F_5 ( V_20 , L_135 , V_556 ) ;
if ( V_551 == NULL ) {
if ( ( V_552 & V_557 ) == 0 )
V_556 &= ~ V_557 ;
if ( ( V_552 & V_558 ) == 0 ) {
if ( V_556 & V_558 )
F_5 ( V_59 , L_136 ) ;
V_556 &= ~ V_558 ;
} else if ( ( V_556 & V_558 ) == 0 ) {
F_5 ( V_59 , L_137 ) ;
F_5 ( V_59 , L_138 ) ;
}
}
if ( V_556 & V_559 )
F_5 ( V_59 , L_139 ) ;
V_556 &= V_560 ;
if ( V_551 && V_551 -> V_313 )
V_556 &= ~ V_557 ;
else if ( V_557 & V_556 ) {
F_5 ( V_20 , L_140 ) ;
if ( V_484 )
V_484 -> V_494 |=
V_561 ;
}
if ( V_551 && V_551 -> V_236 == 0 )
V_556 &= ~ V_558 ;
else if ( V_556 & V_558 ) {
F_5 ( V_20 , L_141 ) ;
if ( V_484 )
V_484 -> V_494 |=
V_562 ;
}
F_5 ( V_20 , L_142 , ( int ) V_556 ) ;
#ifdef F_63
if ( V_556 & V_563 )
F_5 ( V_20 , L_143 ) ;
if ( V_556 & V_564 )
F_5 ( V_20 , L_144 ) ;
if ( V_556 & V_558 )
F_5 ( V_20 , L_145 ) ;
if ( V_556 & V_565 )
F_5 ( V_20 , L_146 ) ;
if ( V_556 & V_557 )
F_5 ( V_20 , L_147 ) ;
if ( V_556 & V_566 )
F_5 ( V_20 , L_148 ) ;
if ( V_556 & V_567 )
F_5 ( V_20 , L_149 ) ;
if ( V_556 & V_568 )
F_5 ( V_20 , L_150 ) ;
if ( V_556 & V_559 )
F_5 ( V_20 , L_151 ) ;
#endif
if ( F_198 ( V_437 , V_10 , V_556 ) ) {
if ( V_551 == NULL ) {
F_5 ( V_20 , L_152 ) ;
} else
F_5 ( V_59 , L_153 ) ;
}
}
}
int F_199 ( struct V_151 * V_569 ,
struct V_483 * V_484 )
{
F_135 ( & V_484 -> V_570 , V_571 ) ;
F_134 ( & V_484 -> V_572 ) ;
V_484 -> V_573 = V_574 ;
V_484 -> V_351 = V_569 -> V_351 ;
V_484 -> V_353 = V_569 -> V_353 ;
V_484 -> V_496 = V_569 -> V_228 ;
V_484 -> V_497 = V_569 -> V_229 ;
V_484 -> V_498 = V_569 -> V_232 ;
V_484 -> V_499 = V_569 -> V_231 ;
F_5 ( V_20 , L_154 ,
V_484 -> V_498 , V_484 -> V_499 ) ;
V_484 -> V_238 = V_569 -> V_238 ;
V_484 -> V_455 = V_569 -> V_455 ;
if ( V_569 -> V_263 )
V_484 -> V_494 |= V_575 ;
if ( V_569 -> V_290 )
V_484 -> V_494 |= V_576 ;
if ( V_569 -> V_293 )
V_484 -> V_494 |= V_577 ;
if ( V_569 -> V_237 )
V_484 -> V_494 |= V_578 ;
if ( V_569 -> V_230 )
V_484 -> V_494 |= V_579 ;
if ( V_569 -> V_266 )
V_484 -> V_494 |= V_580 ;
if ( V_569 -> V_249 )
V_484 -> V_494 |= V_581 ;
if ( V_569 -> V_271 )
V_484 -> V_494 |= V_582 ;
if ( V_569 -> V_282 )
V_484 -> V_494 |= V_583 ;
if ( V_569 -> V_303 )
V_484 -> V_494 |= V_584 ;
if ( V_569 -> V_288 )
V_484 -> V_494 |= V_585 ;
if ( V_569 -> V_308 )
V_484 -> V_494 |= V_586 ;
if ( V_569 -> V_310 )
V_484 -> V_494 |= V_587 ;
if ( V_569 -> V_243 ) {
V_484 -> V_494 |= V_588 ;
V_484 -> V_589 = V_569 -> V_340 ;
}
if ( V_569 -> V_244 ) {
V_484 -> V_494 |= V_590 ;
V_484 -> V_591 = V_569 -> V_342 ;
}
if ( V_569 -> V_214 )
V_484 -> V_494 |= V_592 ;
if ( V_569 -> V_215 )
V_484 -> V_494 |= V_593 ;
if ( V_569 -> V_295 )
V_484 -> V_494 |= V_594 ;
if ( V_569 -> V_322 )
V_484 -> V_494 |= V_595 ;
if ( V_569 -> V_326 )
V_484 -> V_494 |= ( V_596 |
V_575 ) ;
if ( V_569 -> V_178 )
V_484 -> V_494 |= V_597 ;
if ( V_569 -> V_177 ) {
F_5 ( V_20 , L_155 ) ;
V_484 -> V_494 |= V_598 ;
}
if ( V_569 -> V_324 ) {
if ( V_569 -> V_271 ) {
F_5 ( V_59 , L_156 ) ;
}
V_484 -> V_494 |= V_599 ;
}
if ( ( V_569 -> V_310 ) && ( V_569 -> V_295 ) )
F_5 ( V_59 , L_157 ) ;
if ( V_569 -> V_204 ) {
V_484 -> V_204 = F_94 ( V_569 -> V_204 , V_144 ) ;
if ( V_484 -> V_204 == NULL )
return - V_145 ;
}
return 0 ;
}
static void
F_200 ( struct V_151 * V_417 )
{
F_11 ( V_417 -> V_362 ) ;
F_201 ( V_417 -> V_367 ) ;
F_11 ( V_417 -> V_203 ) ;
F_11 ( V_417 -> V_373 ) ;
F_11 ( V_417 -> V_377 ) ;
F_11 ( V_417 -> V_204 ) ;
}
void
F_202 ( struct V_151 * V_417 )
{
if ( ! V_417 )
return;
F_200 ( V_417 ) ;
F_11 ( V_417 ) ;
}
static char *
F_203 ( const struct V_151 * V_152 ,
const struct V_483 * V_484 )
{
char * V_600 , * V_201 ;
unsigned int V_601 = V_152 -> V_204 ? strlen ( V_152 -> V_204 ) + 1 : 0 ;
unsigned int V_602 = F_97 ( V_152 -> V_203 , V_461 + 1 ) ;
V_600 = F_74 ( V_602 + V_601 + 1 , V_144 ) ;
if ( V_600 == NULL )
return F_73 ( - V_145 ) ;
strncpy ( V_600 , V_152 -> V_203 , V_602 ) ;
V_201 = V_600 + V_602 ;
if ( V_601 ) {
* V_201 = F_204 ( V_484 ) ;
strncpy ( V_201 + 1 , V_152 -> V_204 , V_601 ) ;
V_201 += V_601 ;
}
* V_201 = '\0' ;
F_93 ( V_600 , F_204 ( V_484 ) ) ;
F_5 ( V_20 , L_158 , V_21 , V_600 ) ;
return V_600 ;
}
static int
F_205 ( const unsigned int V_437 , struct V_7 * V_8 ,
struct V_151 * V_417 , struct V_483 * V_484 ,
int V_603 )
{
int V_3 ;
unsigned int V_507 = 0 ;
struct V_508 * V_509 = NULL ;
char * V_600 = NULL , * V_604 = NULL , * V_605 = NULL ;
V_600 = F_203 ( V_417 , V_484 ) ;
if ( F_130 ( V_600 ) )
return F_131 ( V_600 ) ;
V_604 = V_603 ? V_600 + 1 : V_417 -> V_203 + 1 ;
V_3 = F_182 ( V_437 , V_8 , V_604 , V_484 -> V_455 ,
& V_507 , & V_509 , F_206 ( V_484 ) ) ;
if ( ! V_3 && V_507 > 0 ) {
char * V_606 = NULL ;
V_605 = F_207 ( V_484 -> V_205 ,
V_600 + 1 , V_509 ,
& V_606 ) ;
F_208 ( V_509 , V_507 ) ;
if ( F_130 ( V_605 ) ) {
V_3 = F_131 ( V_605 ) ;
V_605 = NULL ;
} else {
F_200 ( V_417 ) ;
V_3 = F_209 ( V_417 , V_605 ,
V_606 ) ;
}
F_11 ( V_606 ) ;
F_11 ( V_484 -> V_205 ) ;
V_484 -> V_205 = V_605 ;
}
F_11 ( V_600 ) ;
return V_3 ;
}
static int
F_209 ( struct V_151 * V_417 , char * V_607 ,
const char * V_200 )
{
int V_3 = 0 ;
if ( F_95 ( V_607 , V_200 , V_417 ) )
return - V_143 ;
if ( V_417 -> V_174 ) {
F_5 ( V_20 , L_159 ) ;
F_11 ( V_417 -> V_362 ) ;
V_417 -> V_362 = NULL ;
} else if ( V_417 -> V_362 ) {
F_5 ( V_20 , L_160 , V_417 -> V_362 ) ;
} else {
F_5 ( V_59 , L_161 ) ;
return - V_143 ;
}
if ( V_417 -> V_377 == NULL ) {
V_417 -> V_455 = F_210 () ;
} else {
V_417 -> V_455 = F_211 ( V_417 -> V_377 ) ;
if ( V_417 -> V_455 == NULL ) {
F_5 ( V_59 , L_162 ,
V_417 -> V_377 ) ;
return - V_608 ;
}
}
return V_3 ;
}
struct V_151 *
F_212 ( char * V_607 , const char * V_200 )
{
int V_3 ;
struct V_151 * V_417 ;
V_417 = F_74 ( sizeof( struct V_151 ) , V_144 ) ;
if ( ! V_417 )
return F_73 ( - V_145 ) ;
V_3 = F_209 ( V_417 , V_607 , V_200 ) ;
if ( V_3 ) {
F_202 ( V_417 ) ;
V_417 = F_73 ( V_3 ) ;
}
return V_417 ;
}
static int
F_213 ( struct V_1 * V_2 ,
unsigned int V_437 ,
struct V_9 * V_10 ,
struct V_483 * V_484 ,
char * V_600 )
{
int V_3 ;
char * V_609 ;
char V_610 , V_5 ;
V_610 = F_204 ( V_484 ) ;
V_609 = V_600 ;
V_3 = V_2 -> V_52 -> V_611 ( V_437 , V_10 , V_484 , L_85 ) ;
while ( V_3 == 0 ) {
while ( * V_609 == V_610 )
V_609 ++ ;
if ( ! * V_609 )
break;
while ( * V_609 && * V_609 != V_610 )
V_609 ++ ;
V_5 = * V_609 ;
* V_609 = 0 ;
V_3 = V_2 -> V_52 -> V_611 ( V_437 , V_10 , V_484 ,
V_600 ) ;
* V_609 = V_5 ;
}
return V_3 ;
}
int
F_214 ( struct V_483 * V_484 , struct V_151 * V_417 )
{
int V_3 ;
unsigned int V_437 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_600 ;
struct V_477 * V_478 ;
#ifdef F_215
int V_612 = 0 ;
#endif
V_3 = F_216 ( & V_484 -> V_613 , L_163 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_215
V_614:
if ( V_612 ) {
if ( V_10 )
F_165 ( V_10 ) ;
else if ( V_8 )
F_146 ( V_8 ) ;
V_484 -> V_494 &= ~ V_562 ;
F_160 ( V_437 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_600 = NULL ;
V_478 = NULL ;
V_437 = F_147 () ;
V_2 = F_127 ( V_417 ) ;
if ( F_130 ( V_2 ) ) {
V_3 = F_131 ( V_2 ) ;
F_217 ( & V_484 -> V_613 ) ;
goto V_503;
}
if ( ( V_417 -> V_360 < 20 ) ||
( V_417 -> V_360 > 60000 ) )
V_2 -> V_360 = V_615 ;
else
V_2 -> V_360 = V_417 -> V_360 ;
V_8 = F_158 ( V_2 , V_417 ) ;
if ( F_130 ( V_8 ) ) {
V_3 = F_131 ( V_8 ) ;
V_8 = NULL ;
goto V_616;
}
#ifdef F_4
if ( ( V_417 -> V_332 == true ) && ( ( V_8 -> V_2 -> V_471 &
V_472 ) == 0 ) ) {
F_5 ( V_59 , L_164 ) ;
V_3 = - V_467 ;
goto V_616;
}
#endif
V_10 = F_168 ( V_8 , V_417 ) ;
if ( F_130 ( V_10 ) ) {
V_3 = F_131 ( V_10 ) ;
V_10 = NULL ;
if ( V_3 == - V_617 )
goto V_616;
goto V_618;
}
if ( F_218 ( V_10 -> V_8 ) ) {
F_195 ( V_437 , V_10 , V_484 , V_417 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_196 ( V_10 -> V_553 . V_554 ) &
V_559 ) ) {
V_3 = - V_617 ;
goto V_616;
}
} else
V_10 -> V_555 = 0 ;
if ( ! V_10 -> V_619 && V_2 -> V_52 -> V_620 )
V_2 -> V_52 -> V_620 ( V_437 , V_10 ) ;
V_484 -> V_353 = V_2 -> V_52 -> V_621 ( V_10 , V_417 ) ;
V_484 -> V_351 = V_2 -> V_52 -> V_622 ( V_10 , V_417 ) ;
V_484 -> V_613 . V_623 = V_484 -> V_351 / V_242 ;
V_618:
#ifdef F_215
if ( V_612 == 0 ) {
int V_624 = F_205 ( V_437 , V_8 , V_417 , V_484 ,
false ) ;
if ( ! V_624 ) {
V_612 ++ ;
goto V_614;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_52 -> V_611 ) {
V_3 = - V_56 ;
goto V_616;
}
V_600 = F_219 ( V_417 , V_484 , V_10 ,
V_10 -> V_468 & V_469 ) ;
if ( V_600 == NULL ) {
V_3 = - V_145 ;
goto V_616;
}
V_3 = V_2 -> V_52 -> V_611 ( V_437 , V_10 , V_484 ,
V_600 ) ;
if ( V_3 != 0 && V_3 != - V_625 ) {
F_11 ( V_600 ) ;
goto V_616;
}
if ( V_3 != - V_625 ) {
V_3 = F_213 ( V_2 ,
V_437 , V_10 , V_484 ,
V_600 ) ;
if ( V_3 != 0 ) {
F_5 ( V_59 , L_165
L_166 ) ;
V_484 -> V_494 |= V_501 ;
V_3 = 0 ;
}
}
F_11 ( V_600 ) ;
}
if ( V_3 == - V_625 ) {
#ifdef F_215
if ( V_612 > V_626 ) {
V_3 = - V_627 ;
goto V_616;
}
V_3 = F_205 ( V_437 , V_8 , V_417 , V_484 , true ) ;
if ( ! V_3 ) {
V_612 ++ ;
goto V_614;
}
goto V_616;
#else
V_3 = - V_467 ;
#endif
}
if ( V_3 )
goto V_616;
V_478 = F_103 ( sizeof *V_478 , V_144 ) ;
if ( V_478 == NULL ) {
V_3 = - V_145 ;
goto V_616;
}
V_478 -> V_628 = V_8 -> V_228 ;
V_478 -> V_629 = V_10 ;
V_478 -> V_482 = V_38 ;
F_220 ( V_630 , & V_478 -> V_481 ) ;
F_220 ( V_480 , & V_478 -> V_481 ) ;
V_484 -> V_485 = V_478 ;
F_2 ( & V_484 -> V_572 ) ;
F_221 ( & V_484 -> V_573 , V_478 ) ;
F_3 ( & V_484 -> V_572 ) ;
F_25 ( V_46 , & V_484 -> V_570 ,
V_631 ) ;
V_616:
if ( V_3 ) {
if ( V_10 )
F_165 ( V_10 ) ;
else if ( V_8 )
F_146 ( V_8 ) ;
else
F_120 ( V_2 , 0 ) ;
F_217 ( & V_484 -> V_613 ) ;
}
V_503:
F_160 ( V_437 ) ;
return V_3 ;
}
int
F_222 ( const unsigned int V_437 , struct V_7 * V_8 ,
const char * V_632 , struct V_9 * V_10 ,
const struct V_505 * V_506 )
{
struct V_524 * V_633 ;
struct V_524 * V_634 ;
T_8 * V_635 ;
T_9 * V_636 ;
unsigned char * V_637 ;
int V_3 = 0 ;
int V_66 ;
T_10 V_638 , V_639 ;
if ( V_8 == NULL )
return - V_640 ;
V_633 = F_27 () ;
if ( V_633 == NULL )
return - V_145 ;
V_634 = V_633 ;
F_223 ( V_633 , V_641 ,
NULL , 4 ) ;
V_633 -> V_642 = F_224 ( V_8 -> V_2 ) ;
V_633 -> V_643 = V_8 -> V_644 ;
V_635 = ( T_8 * ) V_633 ;
V_636 = ( T_9 * ) V_634 ;
V_635 -> V_645 = 0xFF ;
V_635 -> V_468 = F_225 ( V_646 ) ;
V_637 = & V_635 -> V_647 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_648 & V_649 ) ) {
V_635 -> V_650 = F_225 ( 1 ) ;
* V_637 = 0 ;
V_637 ++ ;
} else {
V_635 -> V_650 = F_225 ( V_651 ) ;
#ifdef F_87
if ( ( V_652 & V_653 ) &&
( V_8 -> V_154 == V_172 ) )
F_226 ( V_10 -> V_367 , V_8 -> V_2 -> V_654 ,
V_8 -> V_2 -> V_648 &
V_655 ? true : false ,
V_637 ) ;
else
#endif
V_3 = F_227 ( V_10 -> V_367 , V_8 -> V_2 -> V_654 ,
V_637 , V_506 ) ;
if ( V_3 ) {
F_5 ( V_20 , L_167 ,
V_21 , V_3 ) ;
F_65 ( V_633 ) ;
return V_3 ;
}
V_637 += V_651 ;
if ( V_8 -> V_471 & V_656 ) {
* V_637 = 0 ;
V_637 ++ ;
}
}
if ( V_8 -> V_2 -> V_156 )
V_633 -> V_657 |= V_658 ;
if ( V_8 -> V_471 & V_659 ) {
V_633 -> V_657 |= V_660 ;
}
if ( V_8 -> V_471 & V_661 ) {
V_633 -> V_657 |= V_662 ;
}
if ( V_8 -> V_471 & V_656 ) {
V_633 -> V_657 |= V_663 ;
V_66 =
F_228 ( ( V_664 * ) V_637 , V_632 ,
6 *
( + 256 ) , V_506 ) ;
V_637 += 2 * V_66 ;
V_637 += 2 ;
} else {
strcpy ( V_637 , V_632 ) ;
V_637 += strlen ( V_632 ) + 1 ;
}
strcpy ( V_637 , L_168 ) ;
V_637 += strlen ( L_168 ) ;
V_637 += 1 ;
V_639 = V_637 - & V_635 -> V_647 [ 0 ] ;
V_635 -> V_665 . V_535 = F_191 ( F_229 (
V_635 -> V_665 . V_535 ) + V_639 ) ;
V_635 -> V_666 = F_225 ( V_639 ) ;
V_3 = F_230 ( V_437 , V_8 , V_633 , V_634 , & V_66 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_667 ;
V_10 -> V_459 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_668 = V_634 -> V_669 ;
V_637 = F_231 ( V_634 ) ;
V_638 = F_232 ( V_634 ) ;
V_66 = F_97 ( V_637 , V_638 - 2 ) ;
if ( V_633 -> V_657 & V_663 )
V_667 = true ;
else
V_667 = false ;
if ( V_66 == 3 ) {
if ( ( V_637 [ 0 ] == 'I' ) && ( V_637 [ 1 ] == 'P' ) &&
( V_637 [ 2 ] == 'C' ) ) {
F_5 ( V_20 , L_169 ) ;
V_10 -> V_619 = 1 ;
}
} else if ( V_66 == 2 ) {
if ( ( V_637 [ 0 ] == 'A' ) && ( V_637 [ 1 ] == ':' ) ) {
F_5 ( V_20 , L_170 ) ;
}
}
V_637 += V_66 + 1 ;
V_638 -= ( V_66 + 1 ) ;
F_233 ( V_10 -> V_460 , V_632 , sizeof( V_10 -> V_460 ) ) ;
F_11 ( V_10 -> V_670 ) ;
V_10 -> V_670 = F_234 ( V_637 ,
V_638 , V_667 ,
V_506 ) ;
F_5 ( V_20 , L_171 , V_10 -> V_670 ) ;
if ( ( V_634 -> V_671 == 3 ) ||
( V_634 -> V_671 == 7 ) )
V_10 -> V_468 = F_235 ( V_636 -> V_672 ) ;
else
V_10 -> V_468 = 0 ;
F_5 ( V_20 , L_172 , V_10 -> V_468 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_634 -> V_669 ;
}
F_65 ( V_633 ) ;
return V_3 ;
}
static void F_236 ( struct V_673 * V_120 )
{
struct V_483 * V_674 = F_23 ( V_120 , struct V_483 , V_675 ) ;
F_237 ( V_674 -> V_455 ) ;
F_11 ( V_674 ) ;
}
void
F_238 ( struct V_483 * V_484 )
{
struct V_676 * V_677 = & V_484 -> V_573 ;
struct V_678 * V_679 ;
struct V_477 * V_478 ;
F_122 ( & V_484 -> V_570 ) ;
F_2 ( & V_484 -> V_572 ) ;
while ( ( V_679 = F_239 ( V_677 ) ) ) {
V_478 = F_240 ( V_679 , struct V_477 , V_680 ) ;
F_181 ( V_478 ) ;
F_241 ( V_480 , & V_478 -> V_481 ) ;
F_242 ( V_679 , V_677 ) ;
F_3 ( & V_484 -> V_572 ) ;
F_171 ( V_478 ) ;
F_2 ( & V_484 -> V_572 ) ;
}
F_3 ( & V_484 -> V_572 ) ;
F_217 ( & V_484 -> V_613 ) ;
F_11 ( V_484 -> V_205 ) ;
F_11 ( V_484 -> V_204 ) ;
F_243 ( & V_484 -> V_675 , F_236 ) ;
}
int
F_159 ( const unsigned int V_437 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_52 -> V_681 || ! V_2 -> V_52 -> V_682 )
return - V_56 ;
if ( ! V_2 -> V_52 -> V_681 ( V_2 ) )
return 0 ;
F_244 ( V_2 , 1 ) ;
V_3 = V_2 -> V_52 -> V_682 ( V_437 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_683 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_161 ( const unsigned int V_437 , struct V_7 * V_8 ,
struct V_505 * V_684 )
{
int V_3 = - V_56 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_471 = V_2 -> V_471 ;
if ( V_685 == 0 )
V_8 -> V_471 &= ( ~ V_2 -> V_184 -> F_218 ) ;
F_5 ( V_20 , L_173 ,
V_2 -> V_648 , V_2 -> V_471 , V_2 -> V_686 ) ;
if ( V_2 -> V_52 -> V_687 )
V_3 = V_2 -> V_52 -> V_687 ( V_437 , V_8 , V_684 ) ;
if ( V_3 )
F_5 ( V_59 , L_174 , V_3 ) ;
return V_3 ;
}
static int
F_245 ( struct V_151 * V_152 , struct V_7 * V_8 )
{
V_152 -> V_154 = V_8 -> V_154 ;
if ( V_152 -> V_154 == V_161 )
return 0 ;
return F_150 ( V_152 , V_8 ) ;
}
static struct V_9 *
F_246 ( struct V_483 * V_484 , T_2 V_688 )
{
int V_3 ;
struct V_9 * V_689 = F_247 ( V_484 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_151 * V_551 ;
V_551 = F_103 ( sizeof( * V_551 ) , V_144 ) ;
if ( V_551 == NULL )
return F_73 ( - V_145 ) ;
V_551 -> V_455 = V_484 -> V_455 ;
V_551 -> V_228 = V_688 ;
V_551 -> V_227 = V_688 ;
V_551 -> V_203 = V_689 -> V_460 ;
V_551 -> V_260 = V_689 -> V_260 ;
V_551 -> V_280 = V_689 -> V_280 ;
V_551 -> V_316 = V_689 -> V_316 ;
V_551 -> V_278 = ! V_689 -> V_555 ;
V_551 -> V_154 = V_689 -> V_8 -> V_154 ;
V_551 -> V_156 = V_689 -> V_8 -> V_156 ;
V_3 = F_245 ( V_551 , V_689 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_73 ( V_3 ) ;
goto V_503;
}
F_2 ( & V_22 ) ;
++ V_689 -> V_8 -> V_2 -> V_412 ;
F_3 ( & V_22 ) ;
V_8 = F_158 ( V_689 -> V_8 -> V_2 , V_551 ) ;
if ( F_130 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_120 ( V_689 -> V_8 -> V_2 , 0 ) ;
goto V_503;
}
V_10 = F_168 ( V_8 , V_551 ) ;
if ( F_130 ( V_10 ) ) {
F_146 ( V_8 ) ;
goto V_503;
}
if ( F_218 ( V_8 ) )
F_195 ( 0 , V_10 , NULL , V_551 ) ;
V_503:
F_11 ( V_551 -> V_362 ) ;
F_11 ( V_551 -> V_367 ) ;
F_11 ( V_551 ) ;
return V_10 ;
}
struct V_9 *
F_247 ( struct V_483 * V_484 )
{
return F_174 ( F_175 ( V_484 ) ) ;
}
static struct V_477 *
F_248 ( struct V_676 * V_677 , T_2 V_149 )
{
struct V_678 * V_679 = V_677 -> V_678 ;
struct V_477 * V_478 ;
while ( V_679 ) {
V_478 = F_240 ( V_679 , struct V_477 , V_680 ) ;
if ( F_249 ( V_478 -> V_628 , V_149 ) )
V_679 = V_679 -> V_690 ;
else if ( F_250 ( V_478 -> V_628 , V_149 ) )
V_679 = V_679 -> V_691 ;
else
return V_478 ;
}
return NULL ;
}
static void
F_221 ( struct V_676 * V_677 , struct V_477 * V_692 )
{
struct V_678 * * V_491 = & ( V_677 -> V_678 ) , * V_693 = NULL ;
struct V_477 * V_478 ;
while ( * V_491 ) {
V_478 = F_240 ( * V_491 , struct V_477 , V_680 ) ;
V_693 = * V_491 ;
if ( F_249 ( V_478 -> V_628 , V_692 -> V_628 ) )
V_491 = & ( ( * V_491 ) -> V_690 ) ;
else
V_491 = & ( ( * V_491 ) -> V_691 ) ;
}
F_251 ( & V_692 -> V_680 , V_693 , V_491 ) ;
F_252 ( & V_692 -> V_680 , V_677 ) ;
}
struct V_477 *
F_253 ( struct V_483 * V_484 )
{
int V_694 ;
T_2 V_688 = F_254 () ;
struct V_477 * V_478 , * V_695 ;
if ( ! ( V_484 -> V_494 & V_596 ) )
return F_181 ( F_175 ( V_484 ) ) ;
F_2 ( & V_484 -> V_572 ) ;
V_478 = F_248 ( & V_484 -> V_573 , V_688 ) ;
if ( V_478 )
F_181 ( V_478 ) ;
F_3 ( & V_484 -> V_572 ) ;
if ( V_478 == NULL ) {
V_695 = F_103 ( sizeof( * V_478 ) , V_144 ) ;
if ( V_695 == NULL )
return F_73 ( - V_145 ) ;
V_695 -> V_628 = V_688 ;
V_695 -> V_629 = F_73 ( - V_617 ) ;
F_220 ( V_696 , & V_695 -> V_481 ) ;
F_220 ( V_480 , & V_695 -> V_481 ) ;
F_181 ( V_695 ) ;
F_2 ( & V_484 -> V_572 ) ;
V_478 = F_248 ( & V_484 -> V_573 , V_688 ) ;
if ( V_478 ) {
F_181 ( V_478 ) ;
F_3 ( & V_484 -> V_572 ) ;
F_11 ( V_695 ) ;
goto V_697;
}
V_478 = V_695 ;
F_221 ( & V_484 -> V_573 , V_478 ) ;
F_3 ( & V_484 -> V_572 ) ;
} else {
V_697:
V_694 = F_255 ( & V_478 -> V_481 , V_696 ,
V_137 ) ;
if ( V_694 ) {
F_171 ( V_478 ) ;
return F_73 ( - V_72 ) ;
}
if ( ! F_130 ( V_478 -> V_629 ) )
return V_478 ;
if ( F_24 ( V_38 , V_478 -> V_482 + V_698 ) ) {
F_171 ( V_478 ) ;
return F_73 ( - V_617 ) ;
}
if ( F_256 ( V_696 , & V_478 -> V_481 ) )
goto V_697;
}
V_478 -> V_629 = F_246 ( V_484 , V_688 ) ;
F_241 ( V_696 , & V_478 -> V_481 ) ;
F_257 ( & V_478 -> V_481 , V_696 ) ;
if ( F_130 ( V_478 -> V_629 ) ) {
F_171 ( V_478 ) ;
return F_73 ( - V_617 ) ;
}
return V_478 ;
}
static void
V_571 ( struct V_48 * V_49 )
{
struct V_483 * V_484 = F_23 ( V_49 , struct V_483 ,
V_570 . V_49 ) ;
struct V_676 * V_677 = & V_484 -> V_573 ;
struct V_678 * V_679 = F_239 ( V_677 ) ;
struct V_678 * V_5 ;
struct V_477 * V_478 ;
F_2 ( & V_484 -> V_572 ) ;
V_679 = F_239 ( V_677 ) ;
while ( V_679 != NULL ) {
V_5 = V_679 ;
V_679 = F_258 ( V_5 ) ;
V_478 = F_240 ( V_5 , struct V_477 , V_680 ) ;
if ( F_173 ( V_630 , & V_478 -> V_481 ) ||
F_62 ( & V_478 -> V_479 ) != 0 ||
F_31 ( V_478 -> V_482 + V_631 , V_38 ) )
continue;
F_181 ( V_478 ) ;
F_241 ( V_480 , & V_478 -> V_481 ) ;
F_242 ( V_5 , V_677 ) ;
F_3 ( & V_484 -> V_572 ) ;
F_171 ( V_478 ) ;
F_2 ( & V_484 -> V_572 ) ;
}
F_3 ( & V_484 -> V_572 ) ;
F_25 ( V_46 , & V_484 -> V_570 ,
V_631 ) ;
}
