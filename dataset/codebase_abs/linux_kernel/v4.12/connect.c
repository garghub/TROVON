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
int V_36 ;
const char * V_385 ;
V_385 = strchr ( & V_152 -> V_203 [ 2 ] , '\\' ) ;
V_36 = V_385 - & V_152 -> V_203 [ 2 ] ;
if ( ! F_104 ( V_95 , & V_152 -> V_203 [ 2 ] , V_36 ) ) {
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
F_108 ( struct V_94 * V_375 , struct V_94 * V_386 )
{
switch ( V_375 -> V_387 ) {
case V_388 :
return ( V_386 -> V_387 == V_388 ) ;
case V_389 : {
struct V_390 * V_391 = (struct V_390 * ) V_375 ;
struct V_390 * V_392 = (struct V_390 * ) V_386 ;
return ( V_391 -> V_393 . V_394 == V_392 -> V_393 . V_394 ) ;
}
case V_395 : {
struct V_396 * V_397 = (struct V_396 * ) V_375 ;
struct V_396 * V_398 = (struct V_396 * ) V_386 ;
return F_109 ( & V_397 -> V_399 , & V_398 -> V_399 ) ;
}
default:
F_110 ( 1 ) ;
return false ;
}
}
static bool
F_111 ( struct V_1 * V_2 , struct V_94 * V_400 )
{
T_5 V_223 , * V_401 ;
switch ( V_400 -> V_387 ) {
case V_389 :
V_401 = & ( (struct V_390 * ) & V_2 -> V_95 ) -> V_402 ;
V_223 = ( (struct V_390 * ) V_400 ) -> V_402 ;
break;
case V_395 :
V_401 = & ( (struct V_396 * ) & V_2 -> V_95 ) -> V_403 ;
V_223 = ( (struct V_396 * ) V_400 ) -> V_403 ;
break;
default:
F_110 ( 1 ) ;
return false ;
}
if ( ! V_223 ) {
V_223 = F_112 ( V_96 ) ;
if ( V_223 == * V_401 )
return true ;
V_223 = F_112 ( V_404 ) ;
}
return V_223 == * V_401 ;
}
static bool
F_113 ( struct V_1 * V_2 , struct V_94 * V_400 ,
struct V_94 * V_375 )
{
switch ( V_400 -> V_387 ) {
case V_389 : {
struct V_390 * V_405 = (struct V_390 * ) V_400 ;
struct V_390 * V_406 =
(struct V_390 * ) & V_2 -> V_95 ;
if ( V_405 -> V_393 . V_394 != V_406 -> V_393 . V_394 )
return false ;
break;
}
case V_395 : {
struct V_396 * V_407 = (struct V_396 * ) V_400 ;
struct V_396 * V_408 =
(struct V_396 * ) & V_2 -> V_95 ;
if ( ! F_109 ( & V_407 -> V_399 ,
& V_408 -> V_399 ) )
return false ;
if ( V_407 -> V_409 != V_408 -> V_409 )
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
if ( V_2 -> V_52 -> V_410 ( V_2 , V_152 -> V_154 )
== V_155 )
return false ;
if ( V_152 -> V_156 && ! V_2 -> V_156 )
return false ;
return true ;
}
static int F_115 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
struct V_94 * V_400 = (struct V_94 * ) & V_152 -> V_95 ;
if ( V_152 -> V_329 )
return 0 ;
if ( ( V_2 -> V_184 != V_152 -> V_184 ) || ( V_2 -> V_52 != V_152 -> V_52 ) )
return 0 ;
if ( ! F_116 ( F_117 ( V_2 ) , V_123 -> V_411 -> V_412 ) )
return 0 ;
if ( ! F_113 ( V_2 , V_400 ,
(struct V_94 * ) & V_152 -> V_375 ) )
return 0 ;
if ( ! F_111 ( V_2 , V_400 ) )
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
++ V_2 -> V_413 ;
F_3 ( & V_22 ) ;
F_5 ( V_20 , L_80 ) ;
return V_2 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
void
F_120 ( struct V_1 * V_2 , int V_414 )
{
struct V_121 * V_415 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_413 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_121 ( F_117 ( V_2 ) ) ;
F_16 ( & V_2 -> V_105 ) ;
F_3 ( & V_22 ) ;
F_122 ( & V_2 -> V_47 ) ;
#ifdef F_4
if ( V_414 )
F_123 ( & V_2 -> V_416 ) ;
else
F_122 ( & V_2 -> V_416 ) ;
#endif
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
F_11 ( V_2 -> V_34 . V_35 ) ;
V_2 -> V_34 . V_35 = NULL ;
V_2 -> V_34 . V_36 = 0 ;
V_415 = F_67 ( & V_2 -> V_136 , NULL ) ;
if ( V_415 )
F_126 ( V_417 , V_415 ) ;
}
static struct V_1 *
F_127 ( struct V_151 * V_418 )
{
struct V_1 * V_419 = NULL ;
int V_3 ;
F_5 ( V_20 , L_81 , V_418 -> V_203 ) ;
V_419 = F_118 ( V_418 ) ;
if ( V_419 )
return V_419 ;
V_419 = F_103 ( sizeof( struct V_1 ) , V_144 ) ;
if ( ! V_419 ) {
V_3 = - V_145 ;
goto V_420;
}
V_419 -> V_52 = V_418 -> V_52 ;
V_419 -> V_184 = V_418 -> V_184 ;
F_128 ( V_419 , F_129 ( V_123 -> V_411 -> V_412 ) ) ;
V_419 -> V_57 = F_72 ( V_418 -> V_203 ) ;
if ( F_130 ( V_419 -> V_57 ) ) {
V_3 = F_131 ( V_419 -> V_57 ) ;
goto V_421;
}
V_419 -> V_256 = V_418 -> V_256 ;
V_419 -> V_258 = V_418 -> V_258 ;
V_419 -> V_422 = V_418 -> V_423 ;
V_419 -> V_424 = 0 ;
V_419 -> V_107 = 1 ;
F_132 ( & V_419 -> V_63 ) ;
F_132 ( & V_419 -> V_108 ) ;
F_12 ( & V_419 -> V_109 ) ;
F_133 ( & V_419 -> V_27 ) ;
memcpy ( V_419 -> V_425 ,
V_418 -> V_224 , V_380 ) ;
memcpy ( V_419 -> V_426 ,
V_418 -> V_226 , V_380 ) ;
V_419 -> V_33 = false ;
V_419 -> V_32 = 0 ;
V_419 -> V_37 = V_38 ;
F_134 ( & V_419 -> V_106 ) ;
F_12 ( & V_419 -> V_105 ) ;
F_12 ( & V_419 -> V_23 ) ;
F_135 ( & V_419 -> V_47 , F_22 ) ;
#ifdef F_4
F_135 ( & V_419 -> V_416 , V_427 ) ;
F_133 ( & V_419 -> V_428 ) ;
#endif
memcpy ( & V_419 -> V_375 , & V_418 -> V_375 ,
sizeof( V_419 -> V_375 ) ) ;
memcpy ( & V_419 -> V_95 , & V_418 -> V_95 ,
sizeof( V_419 -> V_95 ) ) ;
#ifdef F_4
F_136 ( V_419 -> V_429 ) ;
#endif
V_419 -> V_15 = V_51 ;
++ V_419 -> V_413 ;
if ( V_418 -> V_50 >= V_430 &&
V_418 -> V_50 <= V_431 )
V_419 -> V_50 = V_418 -> V_50 * V_54 ;
else
V_419 -> V_50 = V_240 * V_54 ;
V_3 = F_137 ( V_419 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_82 ) ;
goto V_421;
}
F_138 ( V_432 ) ;
V_419 -> V_136 = F_139 ( F_58 ,
V_419 , L_83 ) ;
if ( F_130 ( V_419 -> V_136 ) ) {
V_3 = F_131 ( V_419 -> V_136 ) ;
F_5 ( V_59 , L_84 , V_3 ) ;
F_140 ( V_432 ) ;
goto V_421;
}
V_419 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_141 ( & V_419 -> V_105 , & V_433 ) ;
F_3 ( & V_22 ) ;
F_142 ( V_419 ) ;
F_25 ( V_46 , & V_419 -> V_47 , V_419 -> V_50 ) ;
return V_419 ;
V_421:
F_124 ( V_419 ) ;
F_121 ( F_117 ( V_419 ) ) ;
V_420:
if ( V_419 ) {
if ( ! F_130 ( V_419 -> V_57 ) )
F_11 ( V_419 -> V_57 ) ;
if ( V_419 -> V_28 )
F_10 ( V_419 -> V_28 ) ;
F_11 ( V_419 ) ;
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
if ( V_8 -> V_434 == NULL ) {
if ( ! V_152 -> V_174 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_434 ,
V_152 -> V_362 ? V_152 -> V_362 : L_85 ,
V_365 ) )
return 0 ;
if ( ( V_152 -> V_362 && strlen ( V_152 -> V_362 ) != 0 ) &&
V_8 -> V_367 != NULL &&
strncmp ( V_8 -> V_367 ,
V_152 -> V_367 ? V_152 -> V_367 : L_85 ,
V_435 ) )
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
if ( V_8 -> V_436 == V_16 )
continue;
if ( ! F_143 ( V_8 , V_152 ) )
continue;
++ V_8 -> V_437 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_146 ( struct V_7 * V_8 )
{
unsigned int V_3 , V_438 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_20 , L_86 , V_21 , V_8 -> V_437 ) ;
F_2 ( & V_22 ) ;
if ( V_8 -> V_436 == V_16 ) {
F_3 ( & V_22 ) ;
return;
}
if ( -- V_8 -> V_437 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
if ( V_8 -> V_436 == V_62 )
V_8 -> V_436 = V_16 ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_436 == V_16 && V_2 -> V_52 -> V_439 ) {
V_438 = F_147 () ;
V_3 = V_2 -> V_52 -> V_439 ( V_438 , V_8 ) ;
if ( V_3 )
F_5 ( V_59 , L_87 ,
V_21 , V_3 ) ;
F_148 ( V_438 ) ;
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
const char * V_142 , * V_440 ;
char * V_441 ;
T_6 V_36 ;
struct V_442 * V_442 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_390 * V_443 ;
struct V_396 * V_444 ;
const struct V_445 * V_446 ;
V_441 = F_74 ( V_447 , V_144 ) ;
if ( ! V_441 )
return - V_145 ;
switch ( V_2 -> V_95 . V_448 ) {
case V_389 :
V_443 = (struct V_390 * ) & V_2 -> V_95 ;
sprintf ( V_441 , L_88 , & V_443 -> V_393 . V_394 ) ;
break;
case V_395 :
V_444 = (struct V_396 * ) & V_2 -> V_95 ;
sprintf ( V_441 , L_89 , & V_444 -> V_399 . V_449 ) ;
break;
default:
F_5 ( V_20 , L_90 ,
V_2 -> V_95 . V_448 ) ;
V_3 = - V_143 ;
goto V_420;
}
F_5 ( V_20 , L_91 , V_21 , V_441 ) ;
V_442 = F_151 ( & V_450 , V_441 , L_85 ) ;
if ( F_130 ( V_442 ) ) {
if ( ! V_8 -> V_451 ) {
F_5 ( V_20 , L_92 ) ;
V_3 = F_131 ( V_442 ) ;
goto V_420;
}
sprintf ( V_441 , L_93 , V_8 -> V_451 ) ;
F_5 ( V_20 , L_91 , V_21 , V_441 ) ;
V_442 = F_151 ( & V_450 , V_441 , L_85 ) ;
if ( F_130 ( V_442 ) ) {
V_3 = F_131 ( V_442 ) ;
goto V_420;
}
}
F_152 ( & V_442 -> V_452 ) ;
V_446 = F_153 ( V_442 ) ;
if ( F_154 ( V_446 ) ) {
V_3 = V_446 ? F_131 ( V_446 ) : - V_143 ;
goto V_453;
}
V_440 = V_446 -> V_206 ;
V_142 = F_155 ( V_440 , V_446 -> V_454 , ':' ) ;
F_5 ( V_20 , L_94 , V_440 ) ;
if ( ! V_142 ) {
F_5 ( V_20 , L_95 ,
V_446 -> V_454 ) ;
V_3 = - V_143 ;
goto V_453;
}
V_36 = V_142 - V_440 ;
if ( V_36 > V_365 || V_36 <= 0 ) {
F_5 ( V_20 , L_96 ,
V_36 ) ;
V_3 = - V_143 ;
goto V_453;
}
V_152 -> V_362 = F_92 ( V_440 , V_36 , V_144 ) ;
if ( ! V_152 -> V_362 ) {
F_5 ( V_20 , L_97 ,
V_36 ) ;
V_3 = - V_145 ;
goto V_453;
}
F_5 ( V_20 , L_98 , V_21 , V_152 -> V_362 ) ;
V_36 = V_442 -> V_454 - ( V_36 + 1 ) ;
if ( V_36 > V_435 || V_36 <= 0 ) {
F_5 ( V_20 , L_99 , V_36 ) ;
V_3 = - V_143 ;
F_11 ( V_152 -> V_362 ) ;
V_152 -> V_362 = NULL ;
goto V_453;
}
++ V_142 ;
V_152 -> V_367 = F_92 ( V_142 , V_36 , V_144 ) ;
if ( ! V_152 -> V_367 ) {
F_5 ( V_20 , L_100 ,
V_36 ) ;
V_3 = - V_145 ;
F_11 ( V_152 -> V_362 ) ;
V_152 -> V_362 = NULL ;
goto V_453;
}
V_453:
F_156 ( & V_442 -> V_452 ) ;
F_157 ( V_442 ) ;
V_420:
F_11 ( V_441 ) ;
F_5 ( V_20 , L_101 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_158 ( struct V_1 * V_2 , struct V_151 * V_418 )
{
int V_3 = - V_145 ;
unsigned int V_438 ;
struct V_7 * V_8 ;
struct V_390 * V_400 = (struct V_390 * ) & V_2 -> V_95 ;
struct V_396 * V_407 = (struct V_396 * ) & V_2 -> V_95 ;
V_438 = F_147 () ;
V_8 = F_145 ( V_2 , V_418 ) ;
if ( V_8 ) {
F_5 ( V_20 , L_102 ,
V_8 -> V_436 ) ;
F_8 ( & V_8 -> V_455 ) ;
V_3 = F_159 ( V_438 , V_8 ) ;
if ( V_3 ) {
F_15 ( & V_8 -> V_455 ) ;
F_146 ( V_8 ) ;
F_160 ( V_438 ) ;
return F_73 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_5 ( V_20 , L_103 ) ;
V_3 = F_161 ( V_438 , V_8 ,
V_418 -> V_456 ) ;
if ( V_3 ) {
F_15 ( & V_8 -> V_455 ) ;
F_146 ( V_8 ) ;
F_160 ( V_438 ) ;
return F_73 ( V_3 ) ;
}
}
F_15 ( & V_8 -> V_455 ) ;
F_120 ( V_2 , 0 ) ;
F_160 ( V_438 ) ;
return V_8 ;
}
F_5 ( V_20 , L_104 ) ;
V_8 = F_162 () ;
if ( V_8 == NULL )
goto V_457;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_95 . V_448 == V_395 )
sprintf ( V_8 -> V_458 , L_105 , & V_407 -> V_399 ) ;
else
sprintf ( V_8 -> V_458 , L_106 , & V_400 -> V_393 ) ;
if ( V_418 -> V_362 ) {
V_8 -> V_434 = F_94 ( V_418 -> V_362 , V_144 ) ;
if ( ! V_8 -> V_434 )
goto V_457;
}
if ( V_418 -> V_367 ) {
V_8 -> V_367 = F_94 ( V_418 -> V_367 , V_144 ) ;
if ( ! V_8 -> V_367 )
goto V_457;
}
if ( V_418 -> V_373 ) {
V_8 -> V_451 = F_94 ( V_418 -> V_373 , V_144 ) ;
if ( ! V_8 -> V_451 )
goto V_457;
}
if ( V_418 -> V_338 )
V_8 -> V_459 = V_418 -> V_338 ;
V_8 -> V_227 = V_418 -> V_227 ;
V_8 -> V_228 = V_418 -> V_228 ;
V_8 -> V_154 = V_418 -> V_154 ;
V_8 -> V_156 = V_418 -> V_156 ;
F_8 ( & V_8 -> V_455 ) ;
V_3 = F_159 ( V_438 , V_8 ) ;
if ( ! V_3 )
V_3 = F_161 ( V_438 , V_8 , V_418 -> V_456 ) ;
F_15 ( & V_8 -> V_455 ) ;
if ( V_3 )
goto V_457;
F_2 ( & V_22 ) ;
F_141 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_160 ( V_438 ) ;
return V_8 ;
V_457:
F_149 ( V_8 ) ;
F_160 ( V_438 ) ;
return F_73 ( V_3 ) ;
}
static int F_163 ( struct V_9 * V_10 , struct V_151 * V_418 )
{
if ( V_10 -> V_460 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_461 , V_418 -> V_203 , V_462 ) )
return 0 ;
if ( V_10 -> V_319 != V_418 -> V_319 )
return 0 ;
#ifdef F_4
if ( V_10 -> V_358 != V_418 -> V_358 )
return 0 ;
#endif
return 1 ;
}
static struct V_9 *
F_164 ( struct V_7 * V_8 , struct V_151 * V_418 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_22 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_26 ) ;
if ( ! F_163 ( V_10 , V_418 ) )
continue;
++ V_10 -> V_463 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
void
F_165 ( struct V_9 * V_10 )
{
unsigned int V_438 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( V_20 , L_107 , V_21 , V_10 -> V_463 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_463 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_438 = F_147 () ;
if ( V_8 -> V_2 -> V_52 -> V_464 )
V_8 -> V_2 -> V_52 -> V_464 ( V_438 , V_10 ) ;
F_148 ( V_438 ) ;
F_166 ( V_10 ) ;
F_167 ( V_10 ) ;
F_146 ( V_8 ) ;
}
static struct V_9 *
F_168 ( struct V_7 * V_8 , struct V_151 * V_418 )
{
int V_3 , V_438 ;
struct V_9 * V_10 ;
V_10 = F_164 ( V_8 , V_418 ) ;
if ( V_10 ) {
F_5 ( V_20 , L_108 ) ;
F_146 ( V_8 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_52 -> V_465 ) {
V_3 = - V_56 ;
goto V_466;
}
V_10 = F_169 () ;
if ( V_10 == NULL ) {
V_3 = - V_145 ;
goto V_466;
}
if ( V_418 -> V_358 ) {
#ifdef F_4
if ( V_8 -> V_2 -> V_184 -> V_467 == 0 ) {
F_5 ( V_59 ,
L_109 ) ;
V_3 = - V_468 ;
goto V_466;
} else
V_10 -> V_358 = V_418 -> V_358 ;
#else
F_5 ( V_59 , L_110 ) ;
V_3 = - V_468 ;
goto V_466;
#endif
}
V_10 -> V_8 = V_8 ;
if ( V_418 -> V_367 ) {
V_10 -> V_367 = F_94 ( V_418 -> V_367 , V_144 ) ;
if ( ! V_10 -> V_367 ) {
V_3 = - V_145 ;
goto V_466;
}
}
V_438 = F_147 () ;
V_3 = V_8 -> V_2 -> V_52 -> V_465 ( V_438 , V_8 , V_418 -> V_203 , V_10 ,
V_418 -> V_456 ) ;
F_160 ( V_438 ) ;
F_5 ( V_20 , L_111 , V_3 ) ;
if ( V_3 )
goto V_466;
if ( V_418 -> V_274 ) {
V_10 -> V_469 &= ~ V_470 ;
F_5 ( V_20 , L_112 , V_10 -> V_469 ) ;
}
V_10 -> V_471 = false ;
if ( V_418 -> V_332 ) {
if ( V_8 -> V_2 -> V_184 -> V_467 == 0 ) {
F_5 ( V_59 ,
L_113 ) ;
V_3 = - V_468 ;
goto V_466;
#ifdef F_4
} else if ( V_8 -> V_2 -> V_472 &
V_473 )
V_10 -> V_471 = true ;
else {
F_5 ( V_59 ,
L_114 ) ;
V_3 = - V_468 ;
goto V_466;
#endif
}
#ifdef F_4
} else if ( ( V_10 -> V_472 & V_474 )
&& ( V_8 -> V_2 -> V_472 & V_473 )
&& ( V_418 -> V_331 == false ) ) {
F_5 ( V_20 , L_115 ) ;
V_10 -> V_471 = true ;
#endif
} else if ( V_418 -> V_334 ) {
if ( V_8 -> V_2 -> V_184 -> V_467 == 0 ) {
F_5 ( V_59 ,
L_116 ) ;
V_3 = - V_468 ;
goto V_466;
}
V_10 -> V_475 = true ;
}
if ( V_418 -> V_319 ) {
if ( V_8 -> V_2 -> V_184 -> V_467 == 0 ) {
F_5 ( V_59 ,
L_117 ) ;
V_3 = - V_468 ;
goto V_466;
#ifdef F_4
} else if ( V_10 -> V_8 -> V_2 -> V_472 &
V_476 )
V_10 -> V_319 = true ;
else {
F_5 ( V_59 , L_118 ) ;
V_3 = - V_468 ;
goto V_466;
#endif
}
}
V_10 -> V_260 = V_418 -> V_260 ;
V_10 -> V_280 = V_418 -> V_280 ;
V_10 -> V_316 = V_418 -> V_316 ;
F_12 ( & V_10 -> V_477 ) ;
F_2 ( & V_22 ) ;
F_141 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_170 ( V_10 ) ;
return V_10 ;
V_466:
F_167 ( V_10 ) ;
return F_73 ( V_3 ) ;
}
void
F_171 ( struct V_478 * V_479 )
{
if ( ! V_479 || F_130 ( V_479 ) )
return;
if ( ! F_172 ( & V_479 -> V_480 ) ||
F_173 ( V_481 , & V_479 -> V_482 ) ) {
V_479 -> V_483 = V_38 ;
return;
}
if ( ! F_130 ( F_174 ( V_479 ) ) )
F_165 ( F_174 ( V_479 ) ) ;
F_11 ( V_479 ) ;
return;
}
static inline struct V_478 *
F_175 ( struct V_484 * V_485 )
{
return V_485 -> V_486 ;
}
static int
F_176 ( struct V_487 * V_488 , struct V_489 * V_490 )
{
struct V_484 * V_491 = F_177 ( V_488 ) ;
struct V_484 * V_492 = V_490 -> V_485 ;
if ( ( V_488 -> V_493 & V_494 ) != ( V_490 -> V_30 & V_494 ) )
return 0 ;
if ( ( V_491 -> V_495 & V_496 ) !=
( V_492 -> V_495 & V_496 ) )
return 0 ;
if ( V_492 -> V_353 && V_492 -> V_353 < V_491 -> V_353 )
return 0 ;
if ( V_492 -> V_351 && V_492 -> V_351 < V_491 -> V_351 )
return 0 ;
if ( ! F_144 ( V_491 -> V_497 , V_492 -> V_497 ) || ! F_178 ( V_491 -> V_498 , V_492 -> V_498 ) )
return 0 ;
if ( V_491 -> V_499 != V_492 -> V_499 ||
V_491 -> V_500 != V_492 -> V_500 )
return 0 ;
if ( strcmp ( V_491 -> V_456 -> V_501 , V_492 -> V_456 -> V_501 ) )
return 0 ;
if ( V_491 -> V_238 != V_492 -> V_238 )
return 0 ;
return 1 ;
}
static int
F_179 ( struct V_487 * V_488 , struct V_489 * V_490 )
{
struct V_484 * V_491 = F_177 ( V_488 ) ;
struct V_484 * V_492 = V_490 -> V_485 ;
bool V_502 = V_491 -> V_495 & V_503 ;
bool V_504 = V_492 -> V_495 & V_503 ;
if ( V_502 && V_504 && ! strcmp ( V_492 -> V_204 , V_491 -> V_204 ) )
return 1 ;
else if ( ! V_502 && ! V_504 )
return 1 ;
return 0 ;
}
int
F_180 ( struct V_487 * V_488 , void * V_206 )
{
struct V_489 * V_490 = (struct V_489 * ) V_206 ;
struct V_151 * V_418 ;
struct V_484 * V_485 ;
struct V_1 * V_505 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_478 * V_479 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_485 = F_177 ( V_488 ) ;
V_479 = F_181 ( F_175 ( V_485 ) ) ;
if ( F_130 ( V_479 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_174 ( V_479 ) ;
V_8 = V_10 -> V_8 ;
V_505 = V_8 -> V_2 ;
V_418 = V_490 -> V_152 ;
if ( ! F_115 ( V_505 , V_418 ) ||
! F_143 ( V_8 , V_418 ) ||
! F_163 ( V_10 , V_418 ) ||
! F_179 ( V_488 , V_490 ) ) {
V_3 = 0 ;
goto V_506;
}
V_3 = F_176 ( V_488 , V_490 ) ;
V_506:
F_3 ( & V_22 ) ;
F_171 ( V_479 ) ;
return V_3 ;
}
int
F_182 ( const unsigned int V_438 , struct V_7 * V_8 , const char * V_507 ,
const struct V_508 * V_509 , unsigned int * V_510 ,
struct V_511 * * V_512 , int V_230 )
{
char * V_513 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_52 -> V_465 || ! V_8 -> V_2 -> V_52 -> V_514 )
return - V_56 ;
* V_510 = 0 ;
* V_512 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_513 = F_74 ( 2 +
F_97 ( V_8 -> V_458 , V_515 * 2 )
+ 1 + 4 + 2 , V_144 ) ;
if ( V_513 == NULL )
return - V_145 ;
V_513 [ 0 ] = '\\' ;
V_513 [ 1 ] = '\\' ;
strcpy ( V_513 + 2 , V_8 -> V_458 ) ;
strcpy ( V_513 + 2 + strlen ( V_8 -> V_458 ) , L_119 ) ;
V_3 = V_8 -> V_2 -> V_52 -> V_465 ( V_438 , V_8 , V_513 , NULL ,
V_509 ) ;
F_5 ( V_20 , L_120 , V_3 , V_8 -> V_25 ) ;
F_11 ( V_513 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_52 -> V_514 ( V_438 , V_8 , V_507 ,
V_512 , V_510 ,
V_509 , V_230 ) ;
return V_3 ;
}
static inline void
F_183 ( struct V_516 * V_517 )
{
struct V_517 * V_518 = V_517 -> V_518 ;
F_184 ( ! F_185 ( V_518 ) ) ;
F_186 ( V_518 , L_121 ,
& V_519 [ 0 ] , L_122 , & V_520 [ 0 ] ) ;
}
static inline void
F_187 ( struct V_516 * V_517 )
{
struct V_517 * V_518 = V_517 -> V_518 ;
F_184 ( ! F_185 ( V_518 ) ) ;
F_186 ( V_518 , L_123 ,
& V_519 [ 1 ] , L_124 , & V_520 [ 1 ] ) ;
}
static inline void
F_183 ( struct V_516 * V_517 )
{
}
static inline void
F_187 ( struct V_516 * V_517 )
{
}
static void F_188 ( char * V_521 , char * V_522 , unsigned int V_66 )
{
unsigned int V_211 , V_212 ;
for ( V_211 = 0 , V_212 = 0 ; V_211 < ( V_66 ) ; V_211 ++ ) {
V_521 [ V_212 ] = 'A' + ( 0x0F & ( V_522 [ V_211 ] >> 4 ) ) ;
V_521 [ V_212 + 1 ] = 'A' + ( 0x0F & V_522 [ V_211 ] ) ;
V_212 += 2 ;
}
}
static int
F_189 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_375 . V_448 != V_388 ) {
struct V_516 * V_516 = V_2 -> V_28 ;
V_3 = V_516 -> V_52 -> V_523 ( V_516 ,
(struct V_94 * ) & V_2 -> V_375 ,
sizeof( V_2 -> V_375 ) ) ;
if ( V_3 < 0 ) {
struct V_390 * V_391 ;
struct V_396 * V_397 ;
V_391 = (struct V_390 * ) & V_2 -> V_375 ;
V_397 = (struct V_396 * ) & V_2 -> V_375 ;
if ( V_397 -> V_524 == V_395 )
F_5 ( V_59 , L_125 ,
& V_397 -> V_399 , V_3 ) ;
else
F_5 ( V_59 , L_126 ,
& V_391 -> V_393 . V_394 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_190 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_525 * V_526 ;
struct V_527 * V_528 ;
V_526 = F_103 ( sizeof( struct V_525 ) ,
V_144 ) ;
if ( V_526 ) {
V_526 -> V_529 . V_530 . V_531 = 32 ;
if ( V_2 -> V_426 [ 0 ] != 0 )
F_188 ( V_526 -> V_529 .
V_530 . V_532 ,
V_2 -> V_426 ,
V_380 ) ;
else
F_188 ( V_526 -> V_529 .
V_530 . V_532 ,
V_533 ,
V_380 ) ;
V_526 -> V_529 . V_530 . V_534 = 32 ;
if ( V_2 -> V_425 [ 0 ] != 0 )
F_188 ( V_526 -> V_529 .
V_530 . V_535 ,
V_2 -> V_425 ,
V_380 ) ;
else
F_188 ( V_526 -> V_529 .
V_530 . V_535 ,
L_127 ,
V_380 ) ;
V_526 -> V_529 . V_530 . V_536 = 0 ;
V_526 -> V_529 . V_530 . V_537 = 0 ;
V_528 = (struct V_527 * ) V_526 ;
V_528 -> V_538 = F_191 ( 0x81000044 ) ;
V_3 = F_192 ( V_2 , V_528 , 0x44 ) ;
F_11 ( V_526 ) ;
F_36 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_401 ;
int V_539 , V_540 ;
struct V_516 * V_516 = V_2 -> V_28 ;
struct V_94 * V_541 ;
V_541 = (struct V_94 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_448 == V_395 ) {
V_401 = ( (struct V_396 * ) V_541 ) -> V_403 ;
V_539 = sizeof( struct V_396 ) ;
V_540 = V_395 ;
} else {
V_401 = ( (struct V_390 * ) V_541 ) -> V_402 ;
V_539 = sizeof( struct V_390 ) ;
V_540 = V_389 ;
}
if ( V_516 == NULL ) {
V_3 = F_193 ( F_117 ( V_2 ) , V_540 , V_542 ,
V_543 , & V_516 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_128 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_5 ( V_20 , L_129 ) ;
V_2 -> V_28 = V_516 ;
V_516 -> V_518 -> V_544 = V_545 ;
if ( V_540 == V_395 )
F_187 ( V_516 ) ;
else
F_183 ( V_516 ) ;
}
V_3 = F_189 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_516 -> V_518 -> V_546 = 7 * V_54 ;
V_516 -> V_518 -> V_547 = 5 * V_54 ;
if ( V_2 -> V_258 ) {
if ( V_516 -> V_518 -> V_548 < ( 200 * 1024 ) )
V_516 -> V_518 -> V_548 = 200 * 1024 ;
if ( V_516 -> V_518 -> V_549 < ( 140 * 1024 ) )
V_516 -> V_518 -> V_549 = 140 * 1024 ;
}
if ( V_2 -> V_422 ) {
int V_550 = 1 ;
V_3 = F_194 ( V_516 , V_551 , V_552 ,
( char * ) & V_550 , sizeof( V_550 ) ) ;
if ( V_3 )
F_5 ( V_20 , L_130 ,
V_3 ) ;
}
F_5 ( V_20 , L_131 ,
V_516 -> V_518 -> V_548 ,
V_516 -> V_518 -> V_549 , V_516 -> V_518 -> V_546 ) ;
V_3 = V_516 -> V_52 -> V_553 ( V_516 , V_541 , V_539 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_20 , L_132 , V_3 ) ;
F_10 ( V_516 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_401 == F_112 ( V_404 ) )
V_3 = F_190 ( V_2 ) ;
return V_3 ;
}
static int
F_137 ( struct V_1 * V_2 )
{
T_5 * V_401 ;
struct V_396 * V_407 = (struct V_396 * ) & V_2 -> V_95 ;
struct V_390 * V_400 = (struct V_390 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_448 == V_395 )
V_401 = & V_407 -> V_403 ;
else
V_401 = & V_400 -> V_402 ;
if ( * V_401 == 0 ) {
int V_3 ;
* V_401 = F_112 ( V_96 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_401 = F_112 ( V_404 ) ;
}
return F_18 ( V_2 ) ;
}
void F_195 ( unsigned int V_438 , struct V_9 * V_10 ,
struct V_484 * V_485 , struct V_151 * V_554 )
{
T_7 V_555 = F_196 ( V_10 -> V_556 . V_557 ) ;
if ( V_554 && V_554 -> V_278 ) {
V_10 -> V_556 . V_557 = 0 ;
V_10 -> V_558 = 0 ;
F_5 ( V_20 , L_133 ) ;
return;
} else if ( V_554 )
V_10 -> V_558 = 1 ;
if ( V_10 -> V_558 == 0 ) {
F_5 ( V_20 , L_134 ) ;
return;
}
if ( ! F_197 ( V_438 , V_10 ) ) {
T_7 V_559 = F_196 ( V_10 -> V_556 . V_557 ) ;
F_5 ( V_20 , L_135 , V_559 ) ;
if ( V_554 == NULL ) {
if ( ( V_555 & V_560 ) == 0 )
V_559 &= ~ V_560 ;
if ( ( V_555 & V_561 ) == 0 ) {
if ( V_559 & V_561 )
F_5 ( V_59 , L_136 ) ;
V_559 &= ~ V_561 ;
} else if ( ( V_559 & V_561 ) == 0 ) {
F_5 ( V_59 , L_137 ) ;
F_5 ( V_59 , L_138 ) ;
}
}
if ( V_559 & V_562 )
F_5 ( V_59 , L_139 ) ;
V_559 &= V_563 ;
if ( V_554 && V_554 -> V_313 )
V_559 &= ~ V_560 ;
else if ( V_560 & V_559 ) {
F_5 ( V_20 , L_140 ) ;
if ( V_485 )
V_485 -> V_495 |=
V_564 ;
}
if ( V_554 && V_554 -> V_236 == 0 )
V_559 &= ~ V_561 ;
else if ( V_559 & V_561 ) {
F_5 ( V_20 , L_141 ) ;
if ( V_485 )
V_485 -> V_495 |=
V_565 ;
}
F_5 ( V_20 , L_142 , ( int ) V_559 ) ;
#ifdef F_63
if ( V_559 & V_566 )
F_5 ( V_20 , L_143 ) ;
if ( V_559 & V_567 )
F_5 ( V_20 , L_144 ) ;
if ( V_559 & V_561 )
F_5 ( V_20 , L_145 ) ;
if ( V_559 & V_568 )
F_5 ( V_20 , L_146 ) ;
if ( V_559 & V_560 )
F_5 ( V_20 , L_147 ) ;
if ( V_559 & V_569 )
F_5 ( V_20 , L_148 ) ;
if ( V_559 & V_570 )
F_5 ( V_20 , L_149 ) ;
if ( V_559 & V_571 )
F_5 ( V_20 , L_150 ) ;
if ( V_559 & V_562 )
F_5 ( V_20 , L_151 ) ;
#endif
if ( F_198 ( V_438 , V_10 , V_559 ) ) {
if ( V_554 == NULL ) {
F_5 ( V_20 , L_152 ) ;
} else
F_5 ( V_59 , L_153 ) ;
}
}
}
int F_199 ( struct V_151 * V_572 ,
struct V_484 * V_485 )
{
F_135 ( & V_485 -> V_573 , V_574 ) ;
F_134 ( & V_485 -> V_575 ) ;
V_485 -> V_576 = V_577 ;
V_485 -> V_351 = V_572 -> V_351 ;
V_485 -> V_353 = V_572 -> V_353 ;
V_485 -> V_497 = V_572 -> V_228 ;
V_485 -> V_498 = V_572 -> V_229 ;
V_485 -> V_499 = V_572 -> V_232 ;
V_485 -> V_500 = V_572 -> V_231 ;
F_5 ( V_20 , L_154 ,
V_485 -> V_499 , V_485 -> V_500 ) ;
V_485 -> V_238 = V_572 -> V_238 ;
V_485 -> V_456 = V_572 -> V_456 ;
if ( V_572 -> V_263 )
V_485 -> V_495 |= V_578 ;
if ( V_572 -> V_290 )
V_485 -> V_495 |= V_579 ;
if ( V_572 -> V_293 )
V_485 -> V_495 |= V_580 ;
if ( V_572 -> V_237 )
V_485 -> V_495 |= V_581 ;
if ( V_572 -> V_230 )
V_485 -> V_495 |= V_582 ;
if ( V_572 -> V_266 )
V_485 -> V_495 |= V_583 ;
if ( V_572 -> V_249 )
V_485 -> V_495 |= V_584 ;
if ( V_572 -> V_271 )
V_485 -> V_495 |= V_585 ;
if ( V_572 -> V_282 )
V_485 -> V_495 |= V_586 ;
if ( V_572 -> V_303 )
V_485 -> V_495 |= V_587 ;
if ( V_572 -> V_288 )
V_485 -> V_495 |= V_588 ;
if ( V_572 -> V_308 )
V_485 -> V_495 |= V_589 ;
if ( V_572 -> V_310 )
V_485 -> V_495 |= V_590 ;
if ( V_572 -> V_243 ) {
V_485 -> V_495 |= V_591 ;
V_485 -> V_592 = V_572 -> V_340 ;
}
if ( V_572 -> V_244 ) {
V_485 -> V_495 |= V_593 ;
V_485 -> V_594 = V_572 -> V_342 ;
}
if ( V_572 -> V_214 )
V_485 -> V_495 |= V_595 ;
if ( V_572 -> V_215 )
V_485 -> V_495 |= V_596 ;
if ( V_572 -> V_295 )
V_485 -> V_495 |= V_597 ;
if ( V_572 -> V_322 )
V_485 -> V_495 |= V_598 ;
if ( V_572 -> V_326 )
V_485 -> V_495 |= ( V_599 |
V_578 ) ;
if ( V_572 -> V_178 )
V_485 -> V_495 |= V_600 ;
if ( V_572 -> V_177 ) {
F_5 ( V_20 , L_155 ) ;
V_485 -> V_495 |= V_601 ;
}
if ( V_572 -> V_324 ) {
if ( V_572 -> V_271 ) {
F_5 ( V_59 , L_156 ) ;
}
V_485 -> V_495 |= V_602 ;
}
if ( ( V_572 -> V_310 ) && ( V_572 -> V_295 ) )
F_5 ( V_59 , L_157 ) ;
if ( V_572 -> V_204 ) {
V_485 -> V_204 = F_94 ( V_572 -> V_204 , V_144 ) ;
if ( V_485 -> V_204 == NULL )
return - V_145 ;
}
return 0 ;
}
static void
F_200 ( struct V_151 * V_418 )
{
F_11 ( V_418 -> V_362 ) ;
F_201 ( V_418 -> V_367 ) ;
F_11 ( V_418 -> V_203 ) ;
F_11 ( V_418 -> V_373 ) ;
F_11 ( V_418 -> V_377 ) ;
F_11 ( V_418 -> V_204 ) ;
}
void
F_202 ( struct V_151 * V_418 )
{
if ( ! V_418 )
return;
F_200 ( V_418 ) ;
F_11 ( V_418 ) ;
}
static char *
F_203 ( const struct V_151 * V_152 ,
const struct V_484 * V_485 )
{
char * V_603 , * V_201 ;
unsigned int V_604 = V_152 -> V_204 ? strlen ( V_152 -> V_204 ) + 1 : 0 ;
unsigned int V_605 = F_97 ( V_152 -> V_203 , V_462 + 1 ) ;
V_603 = F_74 ( V_605 + V_604 + 1 , V_144 ) ;
if ( V_603 == NULL )
return F_73 ( - V_145 ) ;
strncpy ( V_603 , V_152 -> V_203 , V_605 ) ;
V_201 = V_603 + V_605 ;
if ( V_604 ) {
* V_201 = F_204 ( V_485 ) ;
strncpy ( V_201 + 1 , V_152 -> V_204 , V_604 ) ;
V_201 += V_604 ;
}
* V_201 = '\0' ;
F_93 ( V_603 , F_204 ( V_485 ) ) ;
F_5 ( V_20 , L_158 , V_21 , V_603 ) ;
return V_603 ;
}
static int
F_205 ( const unsigned int V_438 , struct V_7 * V_8 ,
struct V_151 * V_418 , struct V_484 * V_485 ,
int V_606 )
{
int V_3 ;
unsigned int V_510 = 0 ;
struct V_511 * V_512 = NULL ;
char * V_603 = NULL , * V_607 = NULL , * V_608 = NULL ;
V_603 = F_203 ( V_418 , V_485 ) ;
if ( F_130 ( V_603 ) )
return F_131 ( V_603 ) ;
V_607 = V_606 ? V_603 + 1 : V_418 -> V_203 + 1 ;
V_3 = F_182 ( V_438 , V_8 , V_607 , V_485 -> V_456 ,
& V_510 , & V_512 , F_206 ( V_485 ) ) ;
if ( ! V_3 && V_510 > 0 ) {
char * V_609 = NULL ;
V_608 = F_207 ( V_485 -> V_205 ,
V_603 + 1 , V_512 ,
& V_609 ) ;
F_208 ( V_512 , V_510 ) ;
if ( F_130 ( V_608 ) ) {
V_3 = F_131 ( V_608 ) ;
V_608 = NULL ;
} else {
F_200 ( V_418 ) ;
V_3 = F_209 ( V_418 , V_608 ,
V_609 ) ;
}
F_11 ( V_609 ) ;
F_11 ( V_485 -> V_205 ) ;
V_485 -> V_205 = V_608 ;
}
F_11 ( V_603 ) ;
return V_3 ;
}
static int
F_209 ( struct V_151 * V_418 , char * V_610 ,
const char * V_200 )
{
int V_3 = 0 ;
if ( F_95 ( V_610 , V_200 , V_418 ) )
return - V_143 ;
if ( V_418 -> V_174 ) {
F_5 ( V_20 , L_159 ) ;
F_11 ( V_418 -> V_362 ) ;
V_418 -> V_362 = NULL ;
} else if ( V_418 -> V_362 ) {
F_5 ( V_20 , L_160 , V_418 -> V_362 ) ;
} else {
F_5 ( V_59 , L_161 ) ;
return - V_143 ;
}
if ( V_418 -> V_377 == NULL ) {
V_418 -> V_456 = F_210 () ;
} else {
V_418 -> V_456 = F_211 ( V_418 -> V_377 ) ;
if ( V_418 -> V_456 == NULL ) {
F_5 ( V_59 , L_162 ,
V_418 -> V_377 ) ;
return - V_611 ;
}
}
return V_3 ;
}
struct V_151 *
F_212 ( char * V_610 , const char * V_200 )
{
int V_3 ;
struct V_151 * V_418 ;
V_418 = F_74 ( sizeof( struct V_151 ) , V_144 ) ;
if ( ! V_418 )
return F_73 ( - V_145 ) ;
V_3 = F_209 ( V_418 , V_610 , V_200 ) ;
if ( V_3 ) {
F_202 ( V_418 ) ;
V_418 = F_73 ( V_3 ) ;
}
return V_418 ;
}
static int
F_213 ( struct V_1 * V_2 ,
unsigned int V_438 ,
struct V_9 * V_10 ,
struct V_484 * V_485 ,
char * V_603 )
{
int V_3 ;
char * V_612 ;
char V_613 , V_5 ;
V_613 = F_204 ( V_485 ) ;
V_612 = V_603 ;
V_3 = V_2 -> V_52 -> V_614 ( V_438 , V_10 , V_485 , L_85 ) ;
while ( V_3 == 0 ) {
while ( * V_612 == V_613 )
V_612 ++ ;
if ( ! * V_612 )
break;
while ( * V_612 && * V_612 != V_613 )
V_612 ++ ;
V_5 = * V_612 ;
* V_612 = 0 ;
V_3 = V_2 -> V_52 -> V_614 ( V_438 , V_10 , V_485 ,
V_603 ) ;
* V_612 = V_5 ;
}
return V_3 ;
}
int
F_214 ( struct V_484 * V_485 , struct V_151 * V_418 )
{
int V_3 ;
unsigned int V_438 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_603 ;
struct V_478 * V_479 ;
#ifdef F_215
int V_615 = 0 ;
#endif
#ifdef F_215
V_616:
if ( V_615 ) {
if ( V_10 )
F_165 ( V_10 ) ;
else if ( V_8 )
F_146 ( V_8 ) ;
V_485 -> V_495 &= ~ V_565 ;
F_160 ( V_438 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_603 = NULL ;
V_479 = NULL ;
V_438 = F_147 () ;
V_2 = F_127 ( V_418 ) ;
if ( F_130 ( V_2 ) ) {
V_3 = F_131 ( V_2 ) ;
goto V_506;
}
if ( ( V_418 -> V_360 < 20 ) ||
( V_418 -> V_360 > 60000 ) )
V_2 -> V_360 = V_617 ;
else
V_2 -> V_360 = V_418 -> V_360 ;
V_8 = F_158 ( V_2 , V_418 ) ;
if ( F_130 ( V_8 ) ) {
V_3 = F_131 ( V_8 ) ;
V_8 = NULL ;
goto V_618;
}
#ifdef F_4
if ( ( V_418 -> V_332 == true ) && ( ( V_8 -> V_2 -> V_472 &
V_473 ) == 0 ) ) {
F_5 ( V_59 , L_163 ) ;
V_3 = - V_468 ;
goto V_618;
}
#endif
V_10 = F_168 ( V_8 , V_418 ) ;
if ( F_130 ( V_10 ) ) {
V_3 = F_131 ( V_10 ) ;
V_10 = NULL ;
if ( V_3 == - V_619 )
goto V_618;
goto V_620;
}
if ( F_216 ( V_10 -> V_8 ) ) {
F_195 ( V_438 , V_10 , V_485 , V_418 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_196 ( V_10 -> V_556 . V_557 ) &
V_562 ) ) {
V_3 = - V_619 ;
goto V_618;
}
} else
V_10 -> V_558 = 0 ;
if ( ! V_10 -> V_621 && V_2 -> V_52 -> V_622 )
V_2 -> V_52 -> V_622 ( V_438 , V_10 ) ;
V_485 -> V_353 = V_2 -> V_52 -> V_623 ( V_10 , V_418 ) ;
V_485 -> V_351 = V_2 -> V_52 -> V_624 ( V_10 , V_418 ) ;
V_620:
#ifdef F_215
if ( V_615 == 0 ) {
int V_625 = F_205 ( V_438 , V_8 , V_418 , V_485 ,
false ) ;
if ( ! V_625 ) {
V_615 ++ ;
goto V_616;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_52 -> V_614 ) {
V_3 = - V_56 ;
goto V_618;
}
V_603 = F_217 ( V_418 , V_485 , V_10 ,
V_10 -> V_469 & V_470 ) ;
if ( V_603 == NULL ) {
V_3 = - V_145 ;
goto V_618;
}
V_3 = V_2 -> V_52 -> V_614 ( V_438 , V_10 , V_485 ,
V_603 ) ;
if ( V_3 != 0 && V_3 != - V_626 ) {
F_11 ( V_603 ) ;
goto V_618;
}
if ( V_3 != - V_626 ) {
V_3 = F_213 ( V_2 ,
V_438 , V_10 , V_485 ,
V_603 ) ;
if ( V_3 != 0 ) {
F_5 ( V_59 , L_164
L_165 ) ;
V_485 -> V_495 |= V_503 ;
V_3 = 0 ;
}
}
F_11 ( V_603 ) ;
}
if ( V_3 == - V_626 ) {
#ifdef F_215
if ( V_615 > V_627 ) {
V_3 = - V_628 ;
goto V_618;
}
V_3 = F_205 ( V_438 , V_8 , V_418 , V_485 , true ) ;
if ( ! V_3 ) {
V_615 ++ ;
goto V_616;
}
goto V_618;
#else
V_3 = - V_468 ;
#endif
}
if ( V_3 )
goto V_618;
V_479 = F_103 ( sizeof *V_479 , V_144 ) ;
if ( V_479 == NULL ) {
V_3 = - V_145 ;
goto V_618;
}
V_479 -> V_629 = V_8 -> V_228 ;
V_479 -> V_630 = V_10 ;
V_479 -> V_483 = V_38 ;
F_218 ( V_631 , & V_479 -> V_482 ) ;
F_218 ( V_481 , & V_479 -> V_482 ) ;
V_485 -> V_486 = V_479 ;
F_2 ( & V_485 -> V_575 ) ;
F_219 ( & V_485 -> V_576 , V_479 ) ;
F_3 ( & V_485 -> V_575 ) ;
F_25 ( V_46 , & V_485 -> V_573 ,
V_632 ) ;
V_618:
if ( V_3 ) {
if ( V_10 )
F_165 ( V_10 ) ;
else if ( V_8 )
F_146 ( V_8 ) ;
else
F_120 ( V_2 , 0 ) ;
}
V_506:
F_160 ( V_438 ) ;
return V_3 ;
}
int
F_220 ( const unsigned int V_438 , struct V_7 * V_8 ,
const char * V_633 , struct V_9 * V_10 ,
const struct V_508 * V_509 )
{
struct V_527 * V_634 ;
struct V_527 * V_635 ;
T_8 * V_636 ;
T_9 * V_637 ;
unsigned char * V_638 ;
int V_3 = 0 ;
int V_66 ;
T_10 V_639 , V_640 ;
if ( V_8 == NULL )
return - V_641 ;
V_634 = F_27 () ;
if ( V_634 == NULL )
return - V_145 ;
V_635 = V_634 ;
F_221 ( V_634 , V_642 ,
NULL , 4 ) ;
V_634 -> V_643 = F_222 ( V_8 -> V_2 ) ;
V_634 -> V_644 = V_8 -> V_645 ;
V_636 = ( T_8 * ) V_634 ;
V_637 = ( T_9 * ) V_635 ;
V_636 -> V_646 = 0xFF ;
V_636 -> V_469 = F_223 ( V_647 ) ;
V_638 = & V_636 -> V_648 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_649 & V_650 ) ) {
V_636 -> V_651 = F_223 ( 1 ) ;
* V_638 = 0 ;
V_638 ++ ;
} else {
V_636 -> V_651 = F_223 ( V_652 ) ;
#ifdef F_87
if ( ( V_653 & V_654 ) &&
( V_8 -> V_154 == V_172 ) )
F_224 ( V_10 -> V_367 , V_8 -> V_2 -> V_655 ,
V_8 -> V_2 -> V_649 &
V_656 ? true : false ,
V_638 ) ;
else
#endif
V_3 = F_225 ( V_10 -> V_367 , V_8 -> V_2 -> V_655 ,
V_638 , V_509 ) ;
if ( V_3 ) {
F_5 ( V_20 , L_166 ,
V_21 , V_3 ) ;
F_65 ( V_634 ) ;
return V_3 ;
}
V_638 += V_652 ;
if ( V_8 -> V_472 & V_657 ) {
* V_638 = 0 ;
V_638 ++ ;
}
}
if ( V_8 -> V_2 -> V_156 )
V_634 -> V_658 |= V_659 ;
if ( V_8 -> V_472 & V_660 ) {
V_634 -> V_658 |= V_661 ;
}
if ( V_8 -> V_472 & V_662 ) {
V_634 -> V_658 |= V_663 ;
}
if ( V_8 -> V_472 & V_657 ) {
V_634 -> V_658 |= V_664 ;
V_66 =
F_226 ( ( V_665 * ) V_638 , V_633 ,
6 *
( + 256 ) , V_509 ) ;
V_638 += 2 * V_66 ;
V_638 += 2 ;
} else {
strcpy ( V_638 , V_633 ) ;
V_638 += strlen ( V_633 ) + 1 ;
}
strcpy ( V_638 , L_167 ) ;
V_638 += strlen ( L_167 ) ;
V_638 += 1 ;
V_640 = V_638 - & V_636 -> V_648 [ 0 ] ;
V_636 -> V_666 . V_538 = F_191 ( F_227 (
V_636 -> V_666 . V_538 ) + V_640 ) ;
V_636 -> V_667 = F_223 ( V_640 ) ;
V_3 = F_228 ( V_438 , V_8 , V_634 , V_635 , & V_66 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_668 ;
V_10 -> V_460 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_669 = V_635 -> V_670 ;
V_638 = F_229 ( V_635 ) ;
V_639 = F_230 ( V_635 ) ;
V_66 = F_97 ( V_638 , V_639 - 2 ) ;
if ( V_634 -> V_658 & V_664 )
V_668 = true ;
else
V_668 = false ;
if ( V_66 == 3 ) {
if ( ( V_638 [ 0 ] == 'I' ) && ( V_638 [ 1 ] == 'P' ) &&
( V_638 [ 2 ] == 'C' ) ) {
F_5 ( V_20 , L_168 ) ;
V_10 -> V_621 = 1 ;
}
} else if ( V_66 == 2 ) {
if ( ( V_638 [ 0 ] == 'A' ) && ( V_638 [ 1 ] == ':' ) ) {
F_5 ( V_20 , L_169 ) ;
}
}
V_638 += V_66 + 1 ;
V_639 -= ( V_66 + 1 ) ;
F_231 ( V_10 -> V_461 , V_633 , sizeof( V_10 -> V_461 ) ) ;
F_11 ( V_10 -> V_671 ) ;
V_10 -> V_671 = F_232 ( V_638 ,
V_639 , V_668 ,
V_509 ) ;
F_5 ( V_20 , L_170 , V_10 -> V_671 ) ;
if ( ( V_635 -> V_672 == 3 ) ||
( V_635 -> V_672 == 7 ) )
V_10 -> V_469 = F_233 ( V_637 -> V_673 ) ;
else
V_10 -> V_469 = 0 ;
F_5 ( V_20 , L_171 , V_10 -> V_469 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_635 -> V_670 ;
}
F_65 ( V_634 ) ;
return V_3 ;
}
static void F_234 ( struct V_674 * V_120 )
{
struct V_484 * V_675 = F_23 ( V_120 , struct V_484 , V_676 ) ;
F_235 ( V_675 -> V_456 ) ;
F_11 ( V_675 ) ;
}
void
F_236 ( struct V_484 * V_485 )
{
struct V_677 * V_678 = & V_485 -> V_576 ;
struct V_679 * V_680 ;
struct V_478 * V_479 ;
F_122 ( & V_485 -> V_573 ) ;
F_2 ( & V_485 -> V_575 ) ;
while ( ( V_680 = F_237 ( V_678 ) ) ) {
V_479 = F_238 ( V_680 , struct V_478 , V_681 ) ;
F_181 ( V_479 ) ;
F_239 ( V_481 , & V_479 -> V_482 ) ;
F_240 ( V_680 , V_678 ) ;
F_3 ( & V_485 -> V_575 ) ;
F_171 ( V_479 ) ;
F_2 ( & V_485 -> V_575 ) ;
}
F_3 ( & V_485 -> V_575 ) ;
F_11 ( V_485 -> V_205 ) ;
F_11 ( V_485 -> V_204 ) ;
F_241 ( & V_485 -> V_676 , F_234 ) ;
}
int
F_159 ( const unsigned int V_438 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_52 -> V_682 || ! V_2 -> V_52 -> V_683 )
return - V_56 ;
if ( ! V_2 -> V_52 -> V_682 ( V_2 ) )
return 0 ;
F_242 ( V_2 , 1 ) ;
V_3 = V_2 -> V_52 -> V_683 ( V_438 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_684 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_161 ( const unsigned int V_438 , struct V_7 * V_8 ,
struct V_508 * V_685 )
{
int V_3 = - V_56 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_472 = V_2 -> V_472 ;
if ( V_686 == 0 )
V_8 -> V_472 &= ( ~ V_2 -> V_184 -> F_216 ) ;
F_5 ( V_20 , L_172 ,
V_2 -> V_649 , V_2 -> V_472 , V_2 -> V_687 ) ;
if ( V_2 -> V_52 -> V_688 )
V_3 = V_2 -> V_52 -> V_688 ( V_438 , V_8 , V_685 ) ;
if ( V_3 )
F_5 ( V_59 , L_173 , V_3 ) ;
return V_3 ;
}
static int
F_243 ( struct V_151 * V_152 , struct V_7 * V_8 )
{
V_152 -> V_154 = V_8 -> V_154 ;
if ( V_152 -> V_154 == V_161 )
return 0 ;
return F_150 ( V_152 , V_8 ) ;
}
static struct V_9 *
F_244 ( struct V_484 * V_485 , T_2 V_689 )
{
int V_3 ;
struct V_9 * V_690 = F_245 ( V_485 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_151 * V_554 ;
V_554 = F_103 ( sizeof( * V_554 ) , V_144 ) ;
if ( V_554 == NULL )
return F_73 ( - V_145 ) ;
V_554 -> V_456 = V_485 -> V_456 ;
V_554 -> V_228 = V_689 ;
V_554 -> V_227 = V_689 ;
V_554 -> V_203 = V_690 -> V_461 ;
V_554 -> V_260 = V_690 -> V_260 ;
V_554 -> V_280 = V_690 -> V_280 ;
V_554 -> V_316 = V_690 -> V_316 ;
V_554 -> V_278 = ! V_690 -> V_558 ;
V_554 -> V_154 = V_690 -> V_8 -> V_154 ;
V_554 -> V_156 = V_690 -> V_8 -> V_156 ;
V_3 = F_243 ( V_554 , V_690 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_73 ( V_3 ) ;
goto V_506;
}
F_2 ( & V_22 ) ;
++ V_690 -> V_8 -> V_2 -> V_413 ;
F_3 ( & V_22 ) ;
V_8 = F_158 ( V_690 -> V_8 -> V_2 , V_554 ) ;
if ( F_130 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_120 ( V_690 -> V_8 -> V_2 , 0 ) ;
goto V_506;
}
V_10 = F_168 ( V_8 , V_554 ) ;
if ( F_130 ( V_10 ) ) {
F_146 ( V_8 ) ;
goto V_506;
}
if ( F_216 ( V_8 ) )
F_195 ( 0 , V_10 , NULL , V_554 ) ;
V_506:
F_11 ( V_554 -> V_362 ) ;
F_11 ( V_554 -> V_367 ) ;
F_11 ( V_554 ) ;
return V_10 ;
}
struct V_9 *
F_245 ( struct V_484 * V_485 )
{
return F_174 ( F_175 ( V_485 ) ) ;
}
static struct V_478 *
F_246 ( struct V_677 * V_678 , T_2 V_149 )
{
struct V_679 * V_680 = V_678 -> V_679 ;
struct V_478 * V_479 ;
while ( V_680 ) {
V_479 = F_238 ( V_680 , struct V_478 , V_681 ) ;
if ( F_247 ( V_479 -> V_629 , V_149 ) )
V_680 = V_680 -> V_691 ;
else if ( F_248 ( V_479 -> V_629 , V_149 ) )
V_680 = V_680 -> V_692 ;
else
return V_479 ;
}
return NULL ;
}
static void
F_219 ( struct V_677 * V_678 , struct V_478 * V_693 )
{
struct V_679 * * V_492 = & ( V_678 -> V_679 ) , * V_694 = NULL ;
struct V_478 * V_479 ;
while ( * V_492 ) {
V_479 = F_238 ( * V_492 , struct V_478 , V_681 ) ;
V_694 = * V_492 ;
if ( F_247 ( V_479 -> V_629 , V_693 -> V_629 ) )
V_492 = & ( ( * V_492 ) -> V_691 ) ;
else
V_492 = & ( ( * V_492 ) -> V_692 ) ;
}
F_249 ( & V_693 -> V_681 , V_694 , V_492 ) ;
F_250 ( & V_693 -> V_681 , V_678 ) ;
}
struct V_478 *
F_251 ( struct V_484 * V_485 )
{
int V_695 ;
T_2 V_689 = F_252 () ;
struct V_478 * V_479 , * V_696 ;
if ( ! ( V_485 -> V_495 & V_599 ) )
return F_181 ( F_175 ( V_485 ) ) ;
F_2 ( & V_485 -> V_575 ) ;
V_479 = F_246 ( & V_485 -> V_576 , V_689 ) ;
if ( V_479 )
F_181 ( V_479 ) ;
F_3 ( & V_485 -> V_575 ) ;
if ( V_479 == NULL ) {
V_696 = F_103 ( sizeof( * V_479 ) , V_144 ) ;
if ( V_696 == NULL )
return F_73 ( - V_145 ) ;
V_696 -> V_629 = V_689 ;
V_696 -> V_630 = F_73 ( - V_619 ) ;
F_218 ( V_697 , & V_696 -> V_482 ) ;
F_218 ( V_481 , & V_696 -> V_482 ) ;
F_181 ( V_696 ) ;
F_2 ( & V_485 -> V_575 ) ;
V_479 = F_246 ( & V_485 -> V_576 , V_689 ) ;
if ( V_479 ) {
F_181 ( V_479 ) ;
F_3 ( & V_485 -> V_575 ) ;
F_11 ( V_696 ) ;
goto V_698;
}
V_479 = V_696 ;
F_219 ( & V_485 -> V_576 , V_479 ) ;
F_3 ( & V_485 -> V_575 ) ;
} else {
V_698:
V_695 = F_253 ( & V_479 -> V_482 , V_697 ,
V_137 ) ;
if ( V_695 ) {
F_171 ( V_479 ) ;
return F_73 ( - V_72 ) ;
}
if ( ! F_130 ( V_479 -> V_630 ) )
return V_479 ;
if ( F_24 ( V_38 , V_479 -> V_483 + V_699 ) ) {
F_171 ( V_479 ) ;
return F_73 ( - V_619 ) ;
}
if ( F_254 ( V_697 , & V_479 -> V_482 ) )
goto V_698;
}
V_479 -> V_630 = F_244 ( V_485 , V_689 ) ;
F_239 ( V_697 , & V_479 -> V_482 ) ;
F_255 ( & V_479 -> V_482 , V_697 ) ;
if ( F_130 ( V_479 -> V_630 ) ) {
F_171 ( V_479 ) ;
return F_73 ( - V_619 ) ;
}
return V_479 ;
}
static void
V_574 ( struct V_48 * V_49 )
{
struct V_484 * V_485 = F_23 ( V_49 , struct V_484 ,
V_573 . V_49 ) ;
struct V_677 * V_678 = & V_485 -> V_576 ;
struct V_679 * V_680 = F_237 ( V_678 ) ;
struct V_679 * V_5 ;
struct V_478 * V_479 ;
F_2 ( & V_485 -> V_575 ) ;
V_680 = F_237 ( V_678 ) ;
while ( V_680 != NULL ) {
V_5 = V_680 ;
V_680 = F_256 ( V_5 ) ;
V_479 = F_238 ( V_5 , struct V_478 , V_681 ) ;
if ( F_173 ( V_631 , & V_479 -> V_482 ) ||
F_62 ( & V_479 -> V_480 ) != 0 ||
F_31 ( V_479 -> V_483 + V_632 , V_38 ) )
continue;
F_181 ( V_479 ) ;
F_239 ( V_481 , & V_479 -> V_482 ) ;
F_240 ( V_5 , V_678 ) ;
F_3 ( & V_485 -> V_575 ) ;
F_171 ( V_479 ) ;
F_2 ( & V_485 -> V_575 ) ;
}
F_3 ( & V_485 -> V_575 ) ;
F_25 ( V_46 , & V_485 -> V_573 ,
V_632 ) ;
}
