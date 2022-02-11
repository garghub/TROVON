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
V_2 -> V_19 = 0 ;
F_4 ( V_20 , L_1 ) ;
F_4 ( V_20 , L_2 ,
V_21 ) ;
F_2 ( & V_22 ) ;
F_5 (tmp, &server->smb_ses_list) {
V_8 = F_6 ( V_5 , struct V_7 , V_23 ) ;
V_8 -> V_24 = true ;
V_8 -> V_25 = 0 ;
F_5 (tmp2, &ses->tcon_list) {
V_10 = F_6 ( V_6 , struct V_9 , V_26 ) ;
V_10 -> V_24 = true ;
}
}
F_3 ( & V_22 ) ;
F_4 ( V_20 , L_3 , V_21 ) ;
F_7 ( & V_2 -> V_27 ) ;
if ( V_2 -> V_28 ) {
F_4 ( V_20 , L_4 ,
V_2 -> V_28 -> V_29 , V_2 -> V_28 -> V_30 ) ;
F_8 ( V_2 -> V_28 , V_31 ) ;
F_4 ( V_20 , L_5 ,
V_2 -> V_28 -> V_29 , V_2 -> V_28 -> V_30 ) ;
F_9 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
}
V_2 -> V_32 = 0 ;
V_2 -> V_33 = false ;
F_10 ( V_2 -> V_34 . V_35 ) ;
V_2 -> V_34 . V_35 = NULL ;
V_2 -> V_34 . V_36 = 0 ;
V_2 -> V_37 = V_38 ;
F_11 ( & V_13 ) ;
F_4 ( V_20 , L_6 , V_21 ) ;
F_2 ( & V_14 ) ;
F_12 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_6 ( V_5 , struct V_11 , V_39 ) ;
if ( V_12 -> V_40 == V_41 )
V_12 -> V_40 = V_42 ;
F_13 ( & V_12 -> V_39 , & V_13 ) ;
}
F_3 ( & V_14 ) ;
F_14 ( & V_2 -> V_27 ) ;
F_4 ( V_20 , L_7 , V_21 ) ;
F_12 (tmp, tmp2, &retry_list) {
V_12 = F_6 ( V_5 , struct V_11 , V_39 ) ;
F_15 ( & V_12 -> V_39 ) ;
V_12 -> V_43 ( V_12 ) ;
}
do {
F_16 () ;
F_7 ( & V_2 -> V_27 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 ) {
F_4 ( V_20 , L_8 , V_3 ) ;
F_14 ( & V_2 -> V_27 ) ;
F_18 ( 3000 ) ;
} else {
F_19 ( & V_44 ) ;
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 != V_16 )
V_2 -> V_15 = V_45 ;
F_3 ( & V_14 ) ;
F_14 ( & V_2 -> V_27 ) ;
}
} while ( V_2 -> V_15 == V_17 );
if ( V_2 -> V_15 == V_45 )
F_20 ( V_46 , & V_2 -> V_47 , 0 ) ;
return V_3 ;
}
static void
F_21 ( struct V_48 * V_49 )
{
int V_3 ;
struct V_1 * V_2 = F_22 ( V_49 ,
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
F_23 ( V_38 , V_2 -> V_37 + V_50 - V_54 ) )
goto V_55;
V_3 = V_2 -> V_52 -> V_47 ? V_2 -> V_52 -> V_47 ( V_2 ) : - V_56 ;
if ( V_3 )
F_4 ( V_20 , L_9 ,
V_2 -> V_57 ) ;
V_55:
F_24 ( V_46 , & V_2 -> V_47 , V_2 -> V_50 ) ;
}
static bool
F_25 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_58 ) {
V_2 -> V_58 = ( char * ) F_26 () ;
if ( ! V_2 -> V_58 ) {
F_4 ( V_59 , L_10 ) ;
F_18 ( 3000 ) ;
return false ;
}
} else if ( V_2 -> V_60 ) {
memset ( V_2 -> V_58 , 0 , F_27 ( V_2 ) ) ;
}
if ( ! V_2 -> V_61 ) {
V_2 -> V_61 = ( char * ) F_28 () ;
if ( ! V_2 -> V_61 ) {
F_4 ( V_59 , L_11 ) ;
F_18 ( 1000 ) ;
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
F_30 ( V_38 , V_2 -> V_37 + 2 * V_2 -> V_50 ) ) {
F_4 ( V_59 , L_12 ,
V_2 -> V_57 , ( 2 * V_2 -> V_50 ) / V_54 ) ;
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
F_16 () ;
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
F_4 ( V_20 , L_13 , V_66 ) ;
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
F_4 ( V_20 , L_14 ) ;
break;
case V_92 :
F_4 ( V_20 , L_15 ) ;
break;
case V_93 :
F_4 ( V_20 , L_16 ) ;
F_18 ( 1000 ) ;
F_41 ( (struct V_94 * ) & V_2 -> V_95 , V_96 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
break;
default:
F_4 ( V_59 , L_17 , type ) ;
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
F_15 ( & V_97 -> V_39 ) ;
F_3 ( & V_14 ) ;
}
static void
F_44 ( struct V_11 * V_97 , struct V_1 * V_2 ,
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
F_42 ( V_97 , V_98 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_66 ;
F_2 ( & V_22 ) ;
F_15 ( & V_2 -> V_105 ) ;
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
F_18 ( 125 ) ;
if ( V_2 -> V_28 ) {
F_9 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
}
if ( ! F_47 ( & V_2 -> V_109 ) ) {
struct V_4 V_110 ;
struct V_11 * V_12 ;
struct V_4 * V_5 , * V_6 ;
F_11 ( & V_110 ) ;
F_2 ( & V_14 ) ;
F_12 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_6 ( V_5 , struct V_11 , V_39 ) ;
F_4 ( V_20 , L_18 , V_12 -> V_97 ) ;
V_12 -> V_40 = V_111 ;
F_13 ( & V_12 -> V_39 , & V_110 ) ;
}
F_3 ( & V_14 ) ;
F_12 (tmp, tmp2, &dispose_list) {
V_12 = F_6 ( V_5 , struct V_11 , V_39 ) ;
F_4 ( V_20 , L_19 , V_12 -> V_97 ) ;
F_15 ( & V_12 -> V_39 ) ;
V_12 -> V_43 ( V_12 ) ;
}
F_18 ( 125 ) ;
}
if ( ! F_47 ( & V_2 -> V_109 ) ) {
F_4 ( V_20 , L_20 ) ;
F_18 ( 46000 ) ;
}
F_10 ( V_2 -> V_57 ) ;
F_10 ( V_2 ) ;
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
F_4 ( V_59 , L_21 , V_115 ) ;
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
return F_54 ( V_2 , V_97 ) ;
}
int
F_54 ( struct V_1 * V_2 , struct V_11 * V_97 )
{
char * V_75 = V_2 -> V_60 ? V_2 -> V_58 : V_2 -> V_61 ;
int V_66 ;
V_66 = V_2 -> V_52 -> V_118 ( V_75 , V_2 -> V_67 , V_2 ) ;
if ( V_66 != 0 )
F_55 ( L_22 , V_75 ,
F_56 (unsigned int, server->total_read, 48 ) ) ;
if ( V_2 -> V_52 -> V_119 &&
V_2 -> V_52 -> V_119 ( V_75 ) ) {
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
return - 1 ;
}
if ( V_2 -> V_52 -> V_120 &&
V_2 -> V_52 -> V_120 ( V_75 , V_2 , V_66 ) )
return - 1 ;
if ( ! V_97 )
return V_66 ;
F_44 ( V_97 , V_2 , V_75 , V_66 ) ;
return 0 ;
}
static int
F_57 ( void * V_121 )
{
int V_66 ;
struct V_1 * V_2 = V_121 ;
unsigned int V_115 ;
char * V_75 = NULL ;
struct V_122 * V_123 = NULL ;
struct V_11 * V_12 ;
V_124 -> V_30 |= V_125 ;
F_4 ( V_20 , L_23 , F_58 ( V_124 ) ) ;
V_66 = F_59 ( & V_112 ) ;
if ( V_66 > 1 )
F_49 ( V_113 , V_66 + V_114 ) ;
F_60 () ;
while ( V_2 -> V_15 != V_16 ) {
if ( F_16 () )
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
F_4 ( V_20 , L_24 , V_115 ) ;
if ( ! F_40 ( V_2 , V_75 [ 0 ] ) )
continue;
if ( V_115 < F_27 ( V_2 ) - 1 - 4 ) {
F_4 ( V_59 , L_25 ,
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
if ( V_2 -> V_52 -> V_126 &&
V_2 -> V_52 -> V_127 &&
V_2 -> V_52 -> V_126 ( V_75 ) ) {
V_66 = V_2 -> V_52 -> V_127 ( V_2 ,
& V_12 ) ;
} else {
V_12 = V_2 -> V_52 -> V_128 ( V_2 , V_75 ) ;
if ( ! V_12 || ! V_12 -> V_129 )
V_66 = F_50 ( V_2 , V_12 ) ;
else
V_66 = V_12 -> V_129 ( V_2 , V_12 ) ;
}
if ( V_66 < 0 )
continue;
if ( V_2 -> V_60 )
V_75 = V_2 -> V_58 ;
V_2 -> V_37 = V_38 ;
if ( V_12 != NULL ) {
if ( ( V_12 -> V_130 & V_131 ) &&
V_12 -> V_40 == V_100 &&
V_2 -> V_52 -> V_132 )
V_2 -> V_52 -> V_132 (
V_12 -> V_103 ,
V_2 ) ;
if ( ! V_12 -> V_104 || V_12 -> V_133 )
V_12 -> V_43 ( V_12 ) ;
} else if ( V_2 -> V_52 -> V_134 &&
V_2 -> V_52 -> V_134 ( V_75 , V_2 ) ) {
F_4 ( V_20 , L_26 ) ;
} else {
F_4 ( V_59 , L_27 ,
F_61 ( & V_135 ) ) ;
F_55 ( L_28 , V_75 ,
F_27 ( V_2 ) ) ;
#ifdef F_62
if ( V_2 -> V_52 -> V_136 )
V_2 -> V_52 -> V_136 ( V_75 ) ;
F_63 ( V_2 ) ;
#endif
}
}
F_64 ( V_2 -> V_58 ) ;
if ( V_2 -> V_61 )
F_65 ( V_2 -> V_61 ) ;
V_123 = F_66 ( & V_2 -> V_137 , NULL ) ;
F_45 ( V_2 ) ;
if ( ! V_123 ) {
F_67 ( V_138 ) ;
while ( ! F_68 ( V_124 ) ) {
F_69 () ;
F_67 ( V_138 ) ;
}
F_67 ( V_139 ) ;
}
F_70 ( 0 ) ;
}
static char *
F_71 ( const char * V_140 )
{
const char * V_141 ;
char * V_142 , * V_143 ;
unsigned int V_36 ;
V_141 = V_140 + 2 ;
V_143 = strchr ( V_141 , '\\' ) ;
if ( ! V_143 )
return F_72 ( - V_144 ) ;
V_36 = V_143 - V_141 ;
V_142 = F_73 ( ( V_36 + 1 ) , V_145 ) ;
if ( V_142 == NULL )
return F_72 ( - V_146 ) ;
memcpy ( V_142 , V_141 , V_36 ) ;
V_142 [ V_36 ] = '\0' ;
return V_142 ;
}
static int F_74 ( T_1 args [] , unsigned long * V_147 )
{
int V_3 ;
char * string ;
string = F_75 ( args ) ;
if ( string == NULL )
return - V_146 ;
V_3 = F_76 ( string , 0 , V_147 ) ;
F_10 ( string ) ;
return V_3 ;
}
static int F_77 ( T_1 args [] , T_2 * V_148 )
{
unsigned long V_149 ;
T_2 V_150 ;
int V_3 ;
V_3 = F_74 ( args , & V_149 ) ;
if ( V_3 )
return V_3 ;
V_150 = F_78 ( F_79 () , V_149 ) ;
if ( ! F_80 ( V_150 ) )
return - V_144 ;
* V_148 = V_150 ;
return 0 ;
}
static int F_81 ( T_1 args [] , T_3 * V_148 )
{
unsigned long V_149 ;
T_3 V_151 ;
int V_3 ;
V_3 = F_74 ( args , & V_149 ) ;
if ( V_3 )
return V_3 ;
V_151 = F_82 ( F_79 () , V_149 ) ;
if ( ! F_83 ( V_151 ) )
return - V_144 ;
* V_148 = V_151 ;
return 0 ;
}
static int F_84 ( char * V_149 ,
struct V_152 * V_153 )
{
T_1 args [ V_154 ] ;
V_153 -> V_155 = V_156 ;
V_153 -> V_157 = false ;
switch ( F_85 ( V_149 , V_158 , args ) ) {
case V_159 :
F_4 ( V_59 , L_29 ) ;
return 1 ;
case V_160 :
V_153 -> V_157 = true ;
case V_161 :
V_153 -> V_155 = V_162 ;
break;
case V_163 :
V_153 -> V_157 = true ;
case V_164 :
V_153 -> V_155 = V_165 ;
break;
case V_166 :
V_153 -> V_157 = true ;
case V_167 :
V_153 -> V_155 = V_168 ;
break;
case V_169 :
V_153 -> V_157 = true ;
case V_170 :
V_153 -> V_155 = V_171 ;
break;
#ifdef F_86
case V_172 :
V_153 -> V_155 = V_173 ;
break;
#endif
case V_174 :
V_153 -> V_175 = 1 ;
break;
default:
F_4 ( V_59 , L_30 , V_149 ) ;
return 1 ;
}
return 0 ;
}
static int
F_87 ( char * V_149 , struct V_152 * V_153 )
{
T_1 args [ V_154 ] ;
switch ( F_85 ( V_149 , V_176 , args ) ) {
case V_177 :
V_153 -> V_178 = false ;
V_153 -> V_179 = false ;
break;
case V_180 :
V_153 -> V_178 = false ;
V_153 -> V_179 = true ;
break;
case V_181 :
V_153 -> V_178 = true ;
V_153 -> V_179 = false ;
break;
default:
F_4 ( V_59 , L_31 , V_149 ) ;
return 1 ;
}
return 0 ;
}
static int
F_88 ( char * V_149 , struct V_152 * V_153 )
{
T_1 args [ V_154 ] ;
switch ( F_85 ( V_149 , V_182 , args ) ) {
case V_183 :
V_153 -> V_52 = & V_184 ;
V_153 -> V_185 = & V_186 ;
break;
case V_187 :
V_153 -> V_52 = & V_188 ;
V_153 -> V_185 = & V_189 ;
break;
case V_190 :
V_153 -> V_52 = & V_191 ;
V_153 -> V_185 = & V_192 ;
break;
case V_193 :
V_153 -> V_52 = & V_194 ;
V_153 -> V_185 = & V_195 ;
break;
case V_196 :
V_153 -> V_52 = & V_194 ;
V_153 -> V_185 = & V_197 ;
break;
#ifdef F_89
case V_198 :
V_153 -> V_52 = & V_199 ;
V_153 -> V_185 = & V_200 ;
break;
#endif
default:
F_4 ( V_59 , L_32 , V_149 ) ;
return 1 ;
}
return 0 ;
}
static int
F_90 ( const char * V_201 , struct V_152 * V_153 )
{
char * V_202 ;
const char * V_203 = L_33 ;
T_4 V_36 ;
V_36 = strspn ( V_201 , V_203 ) ;
if ( V_36 != 2 )
return - V_144 ;
V_202 = strpbrk ( V_201 + 2 , V_203 ) ;
if ( ! V_202 )
return - V_144 ;
++ V_202 ;
V_36 = strcspn ( V_202 , V_203 ) ;
V_202 += V_36 ;
V_153 -> V_204 = F_91 ( V_201 , V_202 - V_201 , V_145 ) ;
if ( ! V_153 -> V_204 )
return - V_146 ;
F_92 ( V_153 -> V_204 , '\\' ) ;
if ( * V_202 == '/' || * V_202 == '\\' )
V_202 ++ ;
if ( ! * V_202 )
return 0 ;
V_153 -> V_205 = F_93 ( V_202 , V_145 ) ;
if ( ! V_153 -> V_205 )
return - V_146 ;
return 0 ;
}
static int
F_94 ( const char * V_206 , const char * V_201 ,
struct V_152 * V_153 )
{
char * V_207 , * V_208 ;
char * V_209 = NULL , * V_210 ;
unsigned int V_211 , V_212 , V_213 ;
char V_214 [ 2 ] ;
short int V_215 = - 1 ;
short int V_216 = - 1 ;
bool V_217 = false ;
bool V_218 = false ;
bool V_219 = false ;
char * V_220 = NULL ;
char * V_221 = F_95 () -> V_221 ;
char * string = NULL ;
char * V_222 , * V_149 ;
char V_143 ;
bool V_223 = false ;
bool V_224 = false ;
unsigned short V_225 = 0 ;
struct V_94 * V_95 = (struct V_94 * ) & V_153 -> V_95 ;
V_214 [ 0 ] = ',' ;
V_214 [ 1 ] = 0 ;
V_143 = V_214 [ 0 ] ;
memset ( V_153 , 0 , sizeof( * V_153 ) ) ;
memset ( V_153 -> V_226 , 0x20 , V_227 ) ;
for ( V_212 = 0 ; V_212 < F_96 ( V_221 , V_227 ) ; V_212 ++ )
V_153 -> V_226 [ V_212 ] = toupper ( V_221 [ V_212 ] ) ;
V_153 -> V_226 [ V_227 ] = 0 ;
V_153 -> V_228 [ 0 ] = 0 ;
V_153 -> V_229 = F_97 () ;
V_153 -> V_230 = F_97 () ;
V_153 -> V_231 = F_98 () ;
V_153 -> V_232 = true ;
V_153 -> V_233 = V_153 -> V_234 = V_235 | V_236 | V_237 ;
V_153 -> V_238 = 1 ;
V_153 -> V_239 = 1 ;
V_153 -> V_179 = true ;
V_153 -> V_240 = V_241 ;
V_153 -> V_52 = & V_194 ;
V_153 -> V_185 = & V_195 ;
V_153 -> V_50 = V_242 ;
if ( ! V_206 )
goto V_243;
V_209 = F_91 ( V_206 , V_244 , V_145 ) ;
if ( ! V_209 )
goto V_243;
V_210 = V_209 ;
V_208 = V_210 + strlen ( V_210 ) ;
if ( strncmp ( V_210 , L_34 , 4 ) == 0 ) {
if ( V_210 [ 4 ] != 0 ) {
V_214 [ 0 ] = V_210 [ 4 ] ;
V_210 += 5 ;
} else {
F_4 ( V_20 , L_35 ) ;
}
}
V_153 -> V_245 = false ;
V_153 -> V_246 = false ;
switch ( F_90 ( V_201 , V_153 ) ) {
case 0 :
break;
case - V_146 :
F_4 ( V_59 , L_36 ) ;
goto V_243;
case - V_144 :
F_4 ( V_59 , L_37 ) ;
goto V_243;
default:
F_4 ( V_59 , L_38 ) ;
goto V_243;
}
while ( ( V_207 = F_99 ( & V_210 , V_214 ) ) != NULL ) {
T_1 args [ V_154 ] ;
unsigned long V_147 ;
int V_247 ;
if ( ! * V_207 )
continue;
V_247 = F_85 ( V_207 , V_248 , args ) ;
switch ( V_247 ) {
case V_249 :
break;
case V_250 :
V_153 -> V_251 = 0 ;
break;
case V_252 :
V_153 -> V_251 = 1 ;
break;
case V_253 :
V_215 = 1 ;
break;
case V_254 :
V_215 = 0 ;
break;
case V_255 :
V_216 = 1 ;
break;
case V_256 :
V_216 = 0 ;
break;
case V_257 :
V_153 -> V_258 = 1 ;
break;
case V_259 :
V_153 -> V_260 = 1 ;
break;
case V_261 :
V_153 -> V_262 = 1 ;
break;
case V_263 :
V_153 -> V_262 = 0 ;
break;
case V_264 :
V_153 -> V_265 = 0 ;
break;
case V_266 :
V_153 -> V_265 = 1 ;
break;
case V_267 :
V_153 -> V_268 = true ;
V_153 -> V_232 = false ;
break;
case V_269 :
V_153 -> V_268 = false ;
break;
case V_270 :
V_153 -> V_232 = true ;
V_153 -> V_268 = false ;
break;
case V_271 :
V_153 -> V_232 = false ;
break;
case V_272 :
V_153 -> V_273 = 1 ;
break;
case V_274 :
V_153 -> V_273 = 0 ;
break;
case V_275 :
V_153 -> V_276 = 1 ;
break;
case V_277 :
V_153 -> V_238 = 1 ;
break;
case V_278 :
V_153 -> V_238 = 0 ;
break;
case V_279 :
V_153 -> V_280 = 1 ;
break;
case V_281 :
V_153 -> V_282 = 1 ;
break;
case V_283 :
V_153 -> V_284 = 0 ;
break;
case V_285 :
V_153 -> V_284 = 1 ;
if ( V_153 -> V_234 ==
( V_286 & ~ ( V_287 | V_288 ) ) )
V_153 -> V_234 = V_286 ;
break;
case V_289 :
V_153 -> V_290 = 1 ;
break;
case V_291 :
V_153 -> V_292 = 1 ;
break;
case V_293 :
V_153 -> V_292 = 0 ;
break;
case V_294 :
V_153 -> V_295 = 1 ;
break;
case V_296 :
V_153 -> V_297 = true ;
break;
case V_298 :
V_153 -> V_297 = false ;
break;
case V_299 :
V_153 -> V_262 = 0 ;
break;
case V_300 :
V_153 -> V_262 = 1 ;
break;
case V_301 :
V_153 -> V_302 = 0 ;
break;
case V_303 :
V_153 -> V_302 = 1 ;
break;
case V_304 :
V_153 -> V_305 = 1 ;
break;
case V_306 :
V_153 -> V_305 = 0 ;
break;
case V_307 :
V_153 -> V_239 = 1 ;
break;
case V_308 :
V_153 -> V_239 = 0 ;
break;
case V_309 :
V_153 -> V_310 = 1 ;
break;
case V_311 :
V_153 -> V_312 = 1 ;
break;
case V_313 :
V_153 -> V_312 = 0 ;
break;
case V_314 :
V_153 -> V_315 = 0 ;
break;
case V_316 :
V_153 -> V_315 = 1 ;
break;
case V_317 :
V_153 -> V_318 = 1 ;
break;
case V_319 :
V_153 -> V_157 = true ;
break;
case V_320 :
V_153 -> V_321 = 1 ;
break;
case V_322 :
F_100 ( L_39 ) ;
break;
case V_323 :
#ifndef F_101
F_4 ( V_59 , L_40 ) ;
goto V_243;
#endif
V_153 -> V_324 = true ;
break;
case V_325 :
V_153 -> V_326 = true ;
break;
case V_327 :
V_153 -> V_328 = true ;
break;
case V_329 :
V_219 = true ;
break;
case V_330 :
V_153 -> V_331 = true ;
break;
case V_332 :
V_153 -> V_333 = true ;
if ( V_153 -> V_334 ) {
F_4 ( V_59 ,
L_41 ) ;
goto V_243;
}
break;
case V_335 :
V_153 -> V_334 = true ;
if ( ( V_153 -> V_333 ) || ( V_153 -> V_336 ) ) {
F_4 ( V_59 ,
L_41 ) ;
goto V_243;
}
break;
case V_337 :
V_153 -> V_336 = true ;
if ( V_153 -> V_334 ) {
F_4 ( V_59 ,
L_41 ) ;
goto V_243;
}
break;
case V_338 :
V_153 -> V_336 = false ;
break;
case V_339 :
V_153 -> V_340 = true ;
break;
case V_341 :
if ( F_77 ( args , & V_153 -> V_342 ) ) {
F_4 ( V_59 , L_42 ,
V_21 ) ;
goto V_243;
}
V_153 -> V_245 = true ;
break;
case V_343 :
if ( F_81 ( args , & V_153 -> V_344 ) ) {
F_4 ( V_59 , L_43 ,
V_21 ) ;
goto V_243;
}
V_153 -> V_246 = true ;
break;
case V_345 :
if ( F_77 ( args , & V_153 -> V_230 ) ) {
F_4 ( V_59 , L_44 ,
V_21 ) ;
goto V_243;
}
V_217 = true ;
break;
case V_346 :
if ( F_77 ( args , & V_153 -> V_229 ) ) {
F_4 ( V_59 , L_45 ,
V_21 ) ;
goto V_243;
}
break;
case V_347 :
if ( F_81 ( args , & V_153 -> V_231 ) ) {
F_4 ( V_59 , L_46 ,
V_21 ) ;
goto V_243;
}
V_218 = true ;
break;
case V_348 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_47 ,
V_21 ) ;
goto V_243;
}
V_153 -> V_234 = V_147 ;
break;
case V_349 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_48 ,
V_21 ) ;
goto V_243;
}
V_153 -> V_233 = V_147 ;
break;
case V_350 :
if ( F_74 ( args , & V_147 ) ||
V_147 > V_351 ) {
F_4 ( V_59 , L_49 ,
V_21 ) ;
goto V_243;
}
V_225 = ( unsigned short ) V_147 ;
break;
case V_352 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_50 ,
V_21 ) ;
goto V_243;
}
V_153 -> V_353 = V_147 ;
break;
case V_354 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_51 ,
V_21 ) ;
goto V_243;
}
V_153 -> V_355 = V_147 ;
break;
case V_356 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_52 ,
V_21 ) ;
goto V_243;
}
V_153 -> V_240 = V_54 * V_147 ;
if ( V_153 -> V_240 > V_357 ) {
F_4 ( V_59 , L_53 ) ;
goto V_243;
}
break;
case V_358 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_54 ,
V_21 ) ;
goto V_243;
}
V_153 -> V_50 = V_147 ;
break;
case V_359 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_55 ,
V_21 ) ;
goto V_243;
}
V_153 -> V_360 = V_147 ;
break;
case V_361 :
if ( F_74 ( args , & V_147 ) || ( V_147 < 20 ) ||
( V_147 > 60000 ) ) {
F_4 ( V_59 , L_56 ,
V_21 ) ;
goto V_243;
}
V_153 -> V_362 = V_147 ;
break;
case V_363 :
V_153 -> V_175 = 1 ;
V_153 -> V_364 = NULL ;
break;
case V_365 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_366;
if ( F_96 ( string , V_367 ) >
V_367 ) {
F_100 ( L_57 ) ;
goto V_243;
}
F_10 ( V_153 -> V_364 ) ;
V_153 -> V_364 = F_93 ( string , V_145 ) ;
if ( ! V_153 -> V_364 )
goto V_243;
break;
case V_368 :
V_222 = strchr ( V_207 , '=' ) ;
V_222 ++ ;
if ( ! ( V_222 < V_208 && V_222 [ 1 ] == V_143 ) ) {
F_10 ( V_153 -> V_369 ) ;
V_153 -> V_369 = NULL ;
break;
}
case V_370 :
V_149 = strchr ( V_207 , '=' ) ;
V_149 ++ ;
V_222 = ( char * ) V_149 + strlen ( V_149 ) ;
if ( V_222 < V_208 && V_222 [ 1 ] == V_143 ) {
V_222 [ 0 ] = V_143 ;
while ( ( V_222 = strchr ( V_222 , V_143 ) )
!= NULL && ( V_222 [ 1 ] == V_143 ) ) {
V_222 = ( char * ) & V_222 [ 2 ] ;
}
if ( V_222 ) {
V_222 [ 0 ] = '\0' ;
V_210 = ( char * ) & V_222 [ 1 ] ;
} else
V_210 = V_208 ;
}
F_10 ( V_153 -> V_369 ) ;
V_211 = strlen ( V_149 ) ;
V_153 -> V_369 = F_102 ( V_211 + 1 , V_145 ) ;
if ( V_153 -> V_369 == NULL ) {
F_100 ( L_58 ) ;
goto V_243;
}
for ( V_212 = 0 , V_213 = 0 ; V_212 < V_211 ; V_212 ++ , V_213 ++ ) {
V_153 -> V_369 [ V_213 ] = V_149 [ V_212 ] ;
if ( ( V_149 [ V_212 ] == V_143 ) &&
V_149 [ V_212 + 1 ] == V_143 )
V_212 ++ ;
}
V_153 -> V_369 [ V_213 ] = '\0' ;
break;
case V_371 :
V_223 = false ;
break;
case V_372 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_366;
if ( ! F_103 ( V_95 , string ,
strlen ( string ) ) ) {
F_104 ( L_59 , string ) ;
goto V_243;
}
V_223 = true ;
break;
case V_373 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_366;
if ( F_96 ( string , V_374 )
== V_374 ) {
F_100 ( L_60 ) ;
goto V_243;
}
F_10 ( V_153 -> V_375 ) ;
V_153 -> V_375 = F_93 ( string , V_145 ) ;
if ( ! V_153 -> V_375 ) {
F_100 ( L_61 ) ;
goto V_243;
}
F_4 ( V_20 , L_62 ) ;
break;
case V_376 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_366;
if ( ! F_103 (
(struct V_94 * ) & V_153 -> V_377 ,
string , strlen ( string ) ) ) {
F_100 ( L_63 ,
string ) ;
goto V_243;
}
break;
case V_378 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_366;
if ( F_96 ( string , 1024 ) >= 65 ) {
F_100 ( L_64 ) ;
goto V_243;
}
if ( strncasecmp ( string , L_65 , 7 ) != 0 ) {
F_10 ( V_153 -> V_379 ) ;
V_153 -> V_379 = F_93 ( string ,
V_145 ) ;
if ( ! V_153 -> V_379 ) {
F_100 ( L_66 ) ;
goto V_243;
}
}
F_4 ( V_20 , L_67 , string ) ;
break;
case V_380 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_366;
memset ( V_153 -> V_226 , 0x20 ,
V_227 ) ;
for ( V_212 = 0 ; V_212 < V_227 ; V_212 ++ ) {
if ( string [ V_212 ] == 0 )
break;
V_153 -> V_226 [ V_212 ] = string [ V_212 ] ;
}
if ( V_212 == V_227 && string [ V_212 ] != 0 )
F_100 ( L_68 ) ;
break;
case V_381 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_366;
memset ( V_153 -> V_228 , 0x20 ,
V_382 ) ;
for ( V_212 = 0 ; V_212 < 15 ; V_212 ++ ) {
if ( string [ V_212 ] == 0 )
break;
V_153 -> V_228 [ V_212 ] = string [ V_212 ] ;
}
if ( V_212 == V_227 && string [ V_212 ] != 0 )
F_100 ( L_69 ) ;
break;
case V_383 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_366;
if ( strncasecmp ( string , L_70 , 1 ) == 0 ) {
if ( strlen ( string ) > 1 ) {
F_100 ( L_71
L_72
L_73
L_74 , string ) ;
goto V_243;
}
break;
}
F_100 ( L_75 ) ;
goto V_243;
case V_384 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_366;
if ( F_88 ( string , V_153 ) != 0 )
goto V_243;
V_224 = true ;
break;
case V_385 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_366;
if ( F_84 ( string , V_153 ) != 0 )
goto V_243;
break;
case V_386 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_366;
if ( F_87 ( string , V_153 ) != 0 )
goto V_243;
break;
default:
if ( ! V_220 )
V_220 = V_207 ;
break;
}
F_10 ( string ) ;
string = NULL ;
}
if ( ! V_219 && V_220 ) {
F_104 ( L_76 , V_220 ) ;
goto V_243;
}
#ifndef F_105
if ( V_153 -> V_328 ) {
F_4 ( V_59 , L_77 ) ;
goto V_243;
}
#endif
if ( ! V_153 -> V_204 ) {
F_4 ( V_59 , L_78 ) ;
goto V_243;
}
if ( ! strchr ( V_153 -> V_204 + 3 , '\\' ) ) {
F_4 ( V_59 , L_79 ) ;
goto V_243;
}
if ( ! V_223 ) {
int V_36 ;
const char * V_387 ;
V_387 = strchr ( & V_153 -> V_204 [ 2 ] , '\\' ) ;
V_36 = V_387 - & V_153 -> V_204 [ 2 ] ;
if ( ! F_103 ( V_95 , & V_153 -> V_204 [ 2 ] , V_36 ) ) {
F_104 ( L_80 ) ;
goto V_243;
}
}
F_41 ( V_95 , V_225 ) ;
if ( V_217 )
V_153 -> V_215 = V_215 ;
else if ( V_215 == 1 )
F_106 ( L_81 ) ;
if ( V_218 )
V_153 -> V_216 = V_216 ;
else if ( V_216 == 1 )
F_106 ( L_82 ) ;
if ( V_224 == false )
F_100 ( L_83
L_84
L_85
L_86
L_87
L_88 ) ;
F_10 ( V_209 ) ;
return 0 ;
V_366:
F_100 ( L_89 ) ;
V_243:
F_10 ( string ) ;
F_10 ( V_209 ) ;
return 1 ;
}
static bool
F_107 ( struct V_94 * V_377 , struct V_94 * V_388 )
{
switch ( V_377 -> V_389 ) {
case V_390 :
return ( V_388 -> V_389 == V_390 ) ;
case V_391 : {
struct V_392 * V_393 = (struct V_392 * ) V_377 ;
struct V_392 * V_394 = (struct V_392 * ) V_388 ;
return ( V_393 -> V_395 . V_396 == V_394 -> V_395 . V_396 ) ;
}
case V_397 : {
struct V_398 * V_399 = (struct V_398 * ) V_377 ;
struct V_398 * V_400 = (struct V_398 * ) V_388 ;
return F_108 ( & V_399 -> V_401 , & V_400 -> V_401 ) ;
}
default:
F_109 ( 1 ) ;
return false ;
}
}
static bool
F_110 ( struct V_1 * V_2 , struct V_94 * V_402 )
{
T_5 V_225 , * V_403 ;
switch ( V_402 -> V_389 ) {
case V_391 :
V_403 = & ( (struct V_392 * ) & V_2 -> V_95 ) -> V_404 ;
V_225 = ( (struct V_392 * ) V_402 ) -> V_404 ;
break;
case V_397 :
V_403 = & ( (struct V_398 * ) & V_2 -> V_95 ) -> V_405 ;
V_225 = ( (struct V_398 * ) V_402 ) -> V_405 ;
break;
default:
F_109 ( 1 ) ;
return false ;
}
if ( ! V_225 ) {
V_225 = F_111 ( V_96 ) ;
if ( V_225 == * V_403 )
return true ;
V_225 = F_111 ( V_406 ) ;
}
return V_225 == * V_403 ;
}
static bool
F_112 ( struct V_1 * V_2 , struct V_94 * V_402 ,
struct V_94 * V_377 )
{
switch ( V_402 -> V_389 ) {
case V_391 : {
struct V_392 * V_407 = (struct V_392 * ) V_402 ;
struct V_392 * V_408 =
(struct V_392 * ) & V_2 -> V_95 ;
if ( V_407 -> V_395 . V_396 != V_408 -> V_395 . V_396 )
return false ;
break;
}
case V_397 : {
struct V_398 * V_409 = (struct V_398 * ) V_402 ;
struct V_398 * V_410 =
(struct V_398 * ) & V_2 -> V_95 ;
if ( ! F_108 ( & V_409 -> V_401 ,
& V_410 -> V_401 ) )
return false ;
if ( V_409 -> V_411 != V_410 -> V_411 )
return false ;
break;
}
default:
F_109 ( 1 ) ;
return false ;
}
if ( ! F_107 ( V_377 , (struct V_94 * ) & V_2 -> V_377 ) )
return false ;
return true ;
}
static bool
F_113 ( struct V_1 * V_2 , struct V_152 * V_153 )
{
if ( V_2 -> V_52 -> V_412 ( V_2 , V_153 -> V_155 )
== V_156 )
return false ;
if ( V_153 -> V_157 && ! V_2 -> V_157 )
return false ;
return true ;
}
static int F_114 ( struct V_1 * V_2 , struct V_152 * V_153 )
{
struct V_94 * V_402 = (struct V_94 * ) & V_153 -> V_95 ;
if ( V_153 -> V_331 )
return 0 ;
if ( ( V_2 -> V_185 != V_153 -> V_185 ) || ( V_2 -> V_52 != V_153 -> V_52 ) )
return 0 ;
if ( ! F_115 ( F_116 ( V_2 ) , V_124 -> V_413 -> V_414 ) )
return 0 ;
if ( ! F_112 ( V_2 , V_402 ,
(struct V_94 * ) & V_153 -> V_377 ) )
return 0 ;
if ( ! F_110 ( V_2 , V_402 ) )
return 0 ;
if ( ! F_113 ( V_2 , V_153 ) )
return 0 ;
if ( V_2 -> V_50 != V_153 -> V_50 * V_54 )
return 0 ;
return 1 ;
}
static struct V_1 *
F_117 ( struct V_152 * V_153 )
{
struct V_1 * V_2 ;
F_2 ( & V_22 ) ;
F_118 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_114 ( V_2 , V_153 ) )
continue;
++ V_2 -> V_415 ;
F_3 ( & V_22 ) ;
F_4 ( V_20 , L_90 ) ;
return V_2 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
void
F_119 ( struct V_1 * V_2 , int V_416 )
{
struct V_122 * V_417 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_415 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_120 ( F_116 ( V_2 ) ) ;
F_15 ( & V_2 -> V_105 ) ;
F_3 ( & V_22 ) ;
F_121 ( & V_2 -> V_47 ) ;
if ( V_416 )
F_122 ( & V_2 -> V_418 ) ;
else
F_121 ( & V_2 -> V_418 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
F_10 ( V_2 -> V_34 . V_35 ) ;
V_2 -> V_34 . V_35 = NULL ;
V_2 -> V_34 . V_36 = 0 ;
V_417 = F_66 ( & V_2 -> V_137 , NULL ) ;
if ( V_417 )
F_125 ( V_419 , V_417 ) ;
}
static struct V_1 *
F_126 ( struct V_152 * V_420 )
{
struct V_1 * V_421 = NULL ;
int V_3 ;
F_4 ( V_20 , L_91 , V_420 -> V_204 ) ;
V_421 = F_117 ( V_420 ) ;
if ( V_421 )
return V_421 ;
V_421 = F_102 ( sizeof( struct V_1 ) , V_145 ) ;
if ( ! V_421 ) {
V_3 = - V_146 ;
goto V_422;
}
V_421 -> V_52 = V_420 -> V_52 ;
V_421 -> V_185 = V_420 -> V_185 ;
F_127 ( V_421 , F_128 ( V_124 -> V_413 -> V_414 ) ) ;
V_421 -> V_57 = F_71 ( V_420 -> V_204 ) ;
if ( F_129 ( V_421 -> V_57 ) ) {
V_3 = F_130 ( V_421 -> V_57 ) ;
goto V_423;
}
V_421 -> V_258 = V_420 -> V_258 ;
V_421 -> V_260 = V_420 -> V_260 ;
V_421 -> V_424 = V_420 -> V_425 ;
V_421 -> V_426 = 0 ;
V_421 -> V_107 = 1 ;
F_131 ( & V_421 -> V_63 ) ;
F_131 ( & V_421 -> V_108 ) ;
F_11 ( & V_421 -> V_109 ) ;
F_132 ( & V_421 -> V_27 ) ;
memcpy ( V_421 -> V_427 ,
V_420 -> V_226 , V_382 ) ;
memcpy ( V_421 -> V_428 ,
V_420 -> V_228 , V_382 ) ;
V_421 -> V_33 = false ;
V_421 -> V_32 = 0 ;
V_421 -> V_37 = V_38 ;
F_133 ( & V_421 -> V_106 ) ;
F_11 ( & V_421 -> V_105 ) ;
F_11 ( & V_421 -> V_23 ) ;
F_134 ( & V_421 -> V_47 , F_21 ) ;
F_134 ( & V_421 -> V_418 , V_429 ) ;
F_132 ( & V_421 -> V_430 ) ;
memcpy ( & V_421 -> V_377 , & V_420 -> V_377 ,
sizeof( V_421 -> V_377 ) ) ;
memcpy ( & V_421 -> V_95 , & V_420 -> V_95 ,
sizeof( V_421 -> V_95 ) ) ;
F_135 ( V_421 -> V_431 ) ;
V_421 -> V_15 = V_51 ;
++ V_421 -> V_415 ;
if ( V_420 -> V_50 >= V_432 &&
V_420 -> V_50 <= V_433 )
V_421 -> V_50 = V_420 -> V_50 * V_54 ;
else
V_421 -> V_50 = V_242 * V_54 ;
V_3 = F_136 ( V_421 ) ;
if ( V_3 < 0 ) {
F_4 ( V_59 , L_92 ) ;
goto V_423;
}
F_137 ( V_434 ) ;
V_421 -> V_137 = F_138 ( F_57 ,
V_421 , L_93 ) ;
if ( F_129 ( V_421 -> V_137 ) ) {
V_3 = F_130 ( V_421 -> V_137 ) ;
F_4 ( V_59 , L_94 , V_3 ) ;
F_139 ( V_434 ) ;
goto V_423;
}
V_421 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_140 ( & V_421 -> V_105 , & V_435 ) ;
F_3 ( & V_22 ) ;
F_141 ( V_421 ) ;
F_24 ( V_46 , & V_421 -> V_47 , V_421 -> V_50 ) ;
return V_421 ;
V_423:
F_123 ( V_421 ) ;
F_120 ( F_116 ( V_421 ) ) ;
V_422:
if ( V_421 ) {
if ( ! F_129 ( V_421 -> V_57 ) )
F_10 ( V_421 -> V_57 ) ;
if ( V_421 -> V_28 )
F_9 ( V_421 -> V_28 ) ;
F_10 ( V_421 ) ;
}
return F_72 ( V_3 ) ;
}
static int F_142 ( struct V_7 * V_8 , struct V_152 * V_153 )
{
if ( V_153 -> V_155 != V_156 &&
V_153 -> V_155 != V_8 -> V_155 )
return 0 ;
switch ( V_8 -> V_155 ) {
case V_162 :
if ( ! F_143 ( V_153 -> V_229 , V_8 -> V_229 ) )
return 0 ;
break;
default:
if ( V_8 -> V_436 == NULL ) {
if ( ! V_153 -> V_175 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_436 ,
V_153 -> V_364 ? V_153 -> V_364 : L_95 ,
V_367 ) )
return 0 ;
if ( ( V_153 -> V_364 && strlen ( V_153 -> V_364 ) != 0 ) &&
V_8 -> V_369 != NULL &&
strncmp ( V_8 -> V_369 ,
V_153 -> V_369 ? V_153 -> V_369 : L_95 ,
V_437 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_144 ( struct V_1 * V_2 , struct V_152 * V_153 )
{
struct V_7 * V_8 ;
F_2 ( & V_22 ) ;
F_118 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_8 -> V_438 == V_16 )
continue;
if ( ! F_142 ( V_8 , V_153 ) )
continue;
++ V_8 -> V_439 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_145 ( struct V_7 * V_8 )
{
unsigned int V_3 , V_440 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( V_20 , L_96 , V_21 , V_8 -> V_439 ) ;
F_2 ( & V_22 ) ;
if ( V_8 -> V_438 == V_16 ) {
F_3 ( & V_22 ) ;
return;
}
if ( -- V_8 -> V_439 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
if ( V_8 -> V_438 == V_62 )
V_8 -> V_438 = V_16 ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_438 == V_16 && V_2 -> V_52 -> V_441 ) {
V_440 = F_146 () ;
V_3 = V_2 -> V_52 -> V_441 ( V_440 , V_8 ) ;
if ( V_3 )
F_4 ( V_59 , L_97 ,
V_21 , V_3 ) ;
F_147 ( V_440 ) ;
}
F_2 ( & V_22 ) ;
F_15 ( & V_8 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_148 ( V_8 ) ;
F_119 ( V_2 , 0 ) ;
}
static int
F_149 ( struct V_152 * V_153 , struct V_7 * V_8 )
{
int V_3 = 0 ;
const char * V_143 , * V_442 ;
char * V_443 ;
T_6 V_36 ;
struct V_444 * V_444 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_392 * V_445 ;
struct V_398 * V_446 ;
const struct V_447 * V_448 ;
V_443 = F_73 ( V_449 , V_145 ) ;
if ( ! V_443 )
return - V_146 ;
switch ( V_2 -> V_95 . V_450 ) {
case V_391 :
V_445 = (struct V_392 * ) & V_2 -> V_95 ;
sprintf ( V_443 , L_98 , & V_445 -> V_395 . V_396 ) ;
break;
case V_397 :
V_446 = (struct V_398 * ) & V_2 -> V_95 ;
sprintf ( V_443 , L_99 , & V_446 -> V_401 . V_451 ) ;
break;
default:
F_4 ( V_20 , L_100 ,
V_2 -> V_95 . V_450 ) ;
V_3 = - V_144 ;
goto V_422;
}
F_4 ( V_20 , L_101 , V_21 , V_443 ) ;
V_444 = F_150 ( & V_452 , V_443 , L_95 ) ;
if ( F_129 ( V_444 ) ) {
if ( ! V_8 -> V_453 ) {
F_4 ( V_20 , L_102 ) ;
V_3 = F_130 ( V_444 ) ;
goto V_422;
}
sprintf ( V_443 , L_103 , V_8 -> V_453 ) ;
F_4 ( V_20 , L_101 , V_21 , V_443 ) ;
V_444 = F_150 ( & V_452 , V_443 , L_95 ) ;
if ( F_129 ( V_444 ) ) {
V_3 = F_130 ( V_444 ) ;
goto V_422;
}
}
F_151 ( & V_444 -> V_454 ) ;
V_448 = F_152 ( V_444 ) ;
if ( F_153 ( V_448 ) ) {
V_3 = V_448 ? F_130 ( V_448 ) : - V_144 ;
goto V_455;
}
V_442 = V_448 -> V_207 ;
V_143 = F_154 ( V_442 , V_448 -> V_456 , ':' ) ;
F_4 ( V_20 , L_104 , V_442 ) ;
if ( ! V_143 ) {
F_4 ( V_20 , L_105 ,
V_448 -> V_456 ) ;
V_3 = - V_144 ;
goto V_455;
}
V_36 = V_143 - V_442 ;
if ( V_36 > V_367 || V_36 <= 0 ) {
F_4 ( V_20 , L_106 ,
V_36 ) ;
V_3 = - V_144 ;
goto V_455;
}
V_153 -> V_364 = F_91 ( V_442 , V_36 , V_145 ) ;
if ( ! V_153 -> V_364 ) {
F_4 ( V_20 , L_107 ,
V_36 ) ;
V_3 = - V_146 ;
goto V_455;
}
F_4 ( V_20 , L_108 , V_21 , V_153 -> V_364 ) ;
V_36 = V_444 -> V_456 - ( V_36 + 1 ) ;
if ( V_36 > V_437 || V_36 <= 0 ) {
F_4 ( V_20 , L_109 , V_36 ) ;
V_3 = - V_144 ;
F_10 ( V_153 -> V_364 ) ;
V_153 -> V_364 = NULL ;
goto V_455;
}
++ V_143 ;
V_153 -> V_369 = F_91 ( V_143 , V_36 , V_145 ) ;
if ( ! V_153 -> V_369 ) {
F_4 ( V_20 , L_110 ,
V_36 ) ;
V_3 = - V_146 ;
F_10 ( V_153 -> V_364 ) ;
V_153 -> V_364 = NULL ;
goto V_455;
}
V_455:
F_155 ( & V_444 -> V_454 ) ;
F_156 ( V_444 ) ;
V_422:
F_10 ( V_443 ) ;
F_4 ( V_20 , L_111 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_157 ( struct V_1 * V_2 , struct V_152 * V_420 )
{
int V_3 = - V_146 ;
unsigned int V_440 ;
struct V_7 * V_8 ;
struct V_392 * V_402 = (struct V_392 * ) & V_2 -> V_95 ;
struct V_398 * V_409 = (struct V_398 * ) & V_2 -> V_95 ;
V_440 = F_146 () ;
V_8 = F_144 ( V_2 , V_420 ) ;
if ( V_8 ) {
F_4 ( V_20 , L_112 ,
V_8 -> V_438 ) ;
F_7 ( & V_8 -> V_457 ) ;
V_3 = F_158 ( V_440 , V_8 ) ;
if ( V_3 ) {
F_14 ( & V_8 -> V_457 ) ;
F_145 ( V_8 ) ;
F_159 ( V_440 ) ;
return F_72 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_4 ( V_20 , L_113 ) ;
V_3 = F_160 ( V_440 , V_8 ,
V_420 -> V_458 ) ;
if ( V_3 ) {
F_14 ( & V_8 -> V_457 ) ;
F_145 ( V_8 ) ;
F_159 ( V_440 ) ;
return F_72 ( V_3 ) ;
}
}
F_14 ( & V_8 -> V_457 ) ;
F_119 ( V_2 , 0 ) ;
F_159 ( V_440 ) ;
return V_8 ;
}
F_4 ( V_20 , L_114 ) ;
V_8 = F_161 () ;
if ( V_8 == NULL )
goto V_459;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_95 . V_450 == V_397 )
sprintf ( V_8 -> V_460 , L_115 , & V_409 -> V_401 ) ;
else
sprintf ( V_8 -> V_460 , L_116 , & V_402 -> V_395 ) ;
if ( V_420 -> V_364 ) {
V_8 -> V_436 = F_93 ( V_420 -> V_364 , V_145 ) ;
if ( ! V_8 -> V_436 )
goto V_459;
}
if ( V_420 -> V_369 ) {
V_8 -> V_369 = F_93 ( V_420 -> V_369 , V_145 ) ;
if ( ! V_8 -> V_369 )
goto V_459;
}
if ( V_420 -> V_375 ) {
V_8 -> V_453 = F_93 ( V_420 -> V_375 , V_145 ) ;
if ( ! V_8 -> V_453 )
goto V_459;
}
if ( V_420 -> V_340 )
V_8 -> V_461 = V_420 -> V_340 ;
V_8 -> V_229 = V_420 -> V_229 ;
V_8 -> V_230 = V_420 -> V_230 ;
V_8 -> V_155 = V_420 -> V_155 ;
V_8 -> V_157 = V_420 -> V_157 ;
F_7 ( & V_8 -> V_457 ) ;
V_3 = F_158 ( V_440 , V_8 ) ;
if ( ! V_3 )
V_3 = F_160 ( V_440 , V_8 , V_420 -> V_458 ) ;
F_14 ( & V_8 -> V_457 ) ;
if ( V_3 )
goto V_459;
F_2 ( & V_22 ) ;
F_140 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_159 ( V_440 ) ;
return V_8 ;
V_459:
F_148 ( V_8 ) ;
F_159 ( V_440 ) ;
return F_72 ( V_3 ) ;
}
static int F_162 ( struct V_9 * V_10 , struct V_152 * V_420 )
{
if ( V_10 -> V_462 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_463 , V_420 -> V_204 , V_464 ) )
return 0 ;
if ( V_10 -> V_321 != V_420 -> V_321 )
return 0 ;
if ( V_10 -> V_360 != V_420 -> V_360 )
return 0 ;
return 1 ;
}
static struct V_9 *
F_163 ( struct V_7 * V_8 , struct V_152 * V_420 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_22 ) ;
F_5 (tmp, &ses->tcon_list) {
V_10 = F_6 ( V_5 , struct V_9 , V_26 ) ;
if ( ! F_162 ( V_10 , V_420 ) )
continue;
++ V_10 -> V_465 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
void
F_164 ( struct V_9 * V_10 )
{
unsigned int V_440 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_4 ( V_20 , L_117 , V_21 , V_10 -> V_465 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_465 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_15 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_440 = F_146 () ;
if ( V_8 -> V_2 -> V_52 -> V_466 )
V_8 -> V_2 -> V_52 -> V_466 ( V_440 , V_10 ) ;
F_147 ( V_440 ) ;
F_165 ( V_10 ) ;
F_166 ( V_10 ) ;
F_145 ( V_8 ) ;
}
static struct V_9 *
F_167 ( struct V_7 * V_8 , struct V_152 * V_420 )
{
int V_3 , V_440 ;
struct V_9 * V_10 ;
V_10 = F_163 ( V_8 , V_420 ) ;
if ( V_10 ) {
F_4 ( V_20 , L_118 ) ;
F_145 ( V_8 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_52 -> V_467 ) {
V_3 = - V_56 ;
goto V_468;
}
V_10 = F_168 () ;
if ( V_10 == NULL ) {
V_3 = - V_146 ;
goto V_468;
}
if ( V_420 -> V_360 ) {
if ( V_8 -> V_2 -> V_185 -> V_469 == 0 ) {
F_4 ( V_59 ,
L_119 ) ;
V_3 = - V_470 ;
goto V_468;
} else
V_10 -> V_360 = V_420 -> V_360 ;
}
V_10 -> V_8 = V_8 ;
if ( V_420 -> V_369 ) {
V_10 -> V_369 = F_93 ( V_420 -> V_369 , V_145 ) ;
if ( ! V_10 -> V_369 ) {
V_3 = - V_146 ;
goto V_468;
}
}
V_440 = F_146 () ;
V_3 = V_8 -> V_2 -> V_52 -> V_467 ( V_440 , V_8 , V_420 -> V_204 , V_10 ,
V_420 -> V_458 ) ;
F_159 ( V_440 ) ;
F_4 ( V_20 , L_120 , V_3 ) ;
if ( V_3 )
goto V_468;
if ( V_420 -> V_276 ) {
V_10 -> V_471 &= ~ V_472 ;
F_4 ( V_20 , L_121 , V_10 -> V_471 ) ;
}
V_10 -> V_473 = false ;
if ( V_420 -> V_334 ) {
if ( V_8 -> V_2 -> V_185 -> V_469 == 0 ) {
F_4 ( V_59 ,
L_122 ) ;
V_3 = - V_470 ;
goto V_468;
} else if ( V_8 -> V_2 -> V_474 &
V_475 )
V_10 -> V_473 = true ;
else {
F_4 ( V_59 ,
L_123 ) ;
V_3 = - V_470 ;
goto V_468;
}
} else if ( ( V_10 -> V_474 & V_476 )
&& ( V_8 -> V_2 -> V_474 & V_475 )
&& ( V_420 -> V_333 == false ) ) {
F_4 ( V_20 , L_124 ) ;
V_10 -> V_473 = true ;
} else if ( V_420 -> V_336 ) {
if ( V_8 -> V_2 -> V_185 -> V_469 == 0 ) {
F_4 ( V_59 ,
L_125 ) ;
V_3 = - V_470 ;
goto V_468;
}
V_10 -> V_477 = true ;
}
if ( V_420 -> V_321 ) {
if ( V_8 -> V_2 -> V_185 -> V_469 == 0 ) {
F_4 ( V_59 ,
L_126 ) ;
V_3 = - V_470 ;
goto V_468;
} else if ( V_10 -> V_8 -> V_2 -> V_474 &
V_478 )
V_10 -> V_321 = true ;
else {
F_4 ( V_59 , L_127 ) ;
V_3 = - V_470 ;
goto V_468;
}
}
V_10 -> V_262 = V_420 -> V_262 ;
V_10 -> V_282 = V_420 -> V_282 ;
V_10 -> V_318 = V_420 -> V_318 ;
F_11 ( & V_10 -> V_479 ) ;
F_2 ( & V_22 ) ;
F_140 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_169 ( V_10 ) ;
return V_10 ;
V_468:
F_166 ( V_10 ) ;
return F_72 ( V_3 ) ;
}
void
F_170 ( struct V_480 * V_481 )
{
if ( ! V_481 || F_129 ( V_481 ) )
return;
if ( ! F_171 ( & V_481 -> V_482 ) ||
F_172 ( V_483 , & V_481 -> V_484 ) ) {
V_481 -> V_485 = V_38 ;
return;
}
if ( ! F_129 ( F_173 ( V_481 ) ) )
F_164 ( F_173 ( V_481 ) ) ;
F_10 ( V_481 ) ;
return;
}
static inline struct V_480 *
F_174 ( struct V_486 * V_487 )
{
return V_487 -> V_488 ;
}
static int
F_175 ( struct V_489 * V_490 , struct V_491 * V_492 )
{
struct V_486 * V_493 = F_176 ( V_490 ) ;
struct V_486 * V_494 = V_492 -> V_487 ;
if ( ( V_490 -> V_495 & V_496 ) != ( V_492 -> V_30 & V_496 ) )
return 0 ;
if ( ( V_493 -> V_497 & V_498 ) !=
( V_494 -> V_497 & V_498 ) )
return 0 ;
if ( V_494 -> V_355 && V_494 -> V_355 < V_493 -> V_355 )
return 0 ;
if ( V_494 -> V_353 && V_494 -> V_353 < V_493 -> V_353 )
return 0 ;
if ( ! F_143 ( V_493 -> V_499 , V_494 -> V_499 ) || ! F_177 ( V_493 -> V_500 , V_494 -> V_500 ) )
return 0 ;
if ( V_493 -> V_501 != V_494 -> V_501 ||
V_493 -> V_502 != V_494 -> V_502 )
return 0 ;
if ( strcmp ( V_493 -> V_458 -> V_503 , V_494 -> V_458 -> V_503 ) )
return 0 ;
if ( V_493 -> V_240 != V_494 -> V_240 )
return 0 ;
return 1 ;
}
static int
F_178 ( struct V_489 * V_490 , struct V_491 * V_492 )
{
struct V_486 * V_493 = F_176 ( V_490 ) ;
struct V_486 * V_494 = V_492 -> V_487 ;
bool V_504 = V_493 -> V_497 & V_505 ;
bool V_506 = V_494 -> V_497 & V_505 ;
if ( V_504 && V_506 && ! strcmp ( V_494 -> V_205 , V_493 -> V_205 ) )
return 1 ;
else if ( ! V_504 && ! V_506 )
return 1 ;
return 0 ;
}
int
F_179 ( struct V_489 * V_490 , void * V_207 )
{
struct V_491 * V_492 = (struct V_491 * ) V_207 ;
struct V_152 * V_420 ;
struct V_486 * V_487 ;
struct V_1 * V_507 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_480 * V_481 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_487 = F_176 ( V_490 ) ;
V_481 = F_180 ( F_174 ( V_487 ) ) ;
if ( F_129 ( V_481 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_173 ( V_481 ) ;
V_8 = V_10 -> V_8 ;
V_507 = V_8 -> V_2 ;
V_420 = V_492 -> V_153 ;
if ( ! F_114 ( V_507 , V_420 ) ||
! F_142 ( V_8 , V_420 ) ||
! F_162 ( V_10 , V_420 ) ||
! F_178 ( V_490 , V_492 ) ) {
V_3 = 0 ;
goto V_508;
}
V_3 = F_175 ( V_490 , V_492 ) ;
V_508:
F_3 ( & V_22 ) ;
F_170 ( V_481 ) ;
return V_3 ;
}
int
F_181 ( const unsigned int V_440 , struct V_7 * V_8 , const char * V_509 ,
const struct V_510 * V_511 , unsigned int * V_512 ,
struct V_513 * * V_514 , int V_232 )
{
char * V_515 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_52 -> V_467 || ! V_8 -> V_2 -> V_52 -> V_516 )
return - V_56 ;
* V_512 = 0 ;
* V_514 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_515 = F_73 ( 2 +
F_96 ( V_8 -> V_460 , V_517 * 2 )
+ 1 + 4 + 2 , V_145 ) ;
if ( V_515 == NULL )
return - V_146 ;
V_515 [ 0 ] = '\\' ;
V_515 [ 1 ] = '\\' ;
strcpy ( V_515 + 2 , V_8 -> V_460 ) ;
strcpy ( V_515 + 2 + strlen ( V_8 -> V_460 ) , L_128 ) ;
V_3 = V_8 -> V_2 -> V_52 -> V_467 ( V_440 , V_8 , V_515 , NULL ,
V_511 ) ;
F_4 ( V_20 , L_129 , V_3 , V_8 -> V_25 ) ;
F_10 ( V_515 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_52 -> V_516 ( V_440 , V_8 , V_509 ,
V_514 , V_512 ,
V_511 , V_232 ) ;
return V_3 ;
}
static inline void
F_182 ( struct V_518 * V_519 )
{
struct V_519 * V_520 = V_519 -> V_520 ;
F_183 ( ! F_184 ( V_520 ) ) ;
F_185 ( V_520 , L_130 ,
& V_521 [ 0 ] , L_131 , & V_522 [ 0 ] ) ;
}
static inline void
F_186 ( struct V_518 * V_519 )
{
struct V_519 * V_520 = V_519 -> V_520 ;
F_183 ( ! F_184 ( V_520 ) ) ;
F_185 ( V_520 , L_132 ,
& V_521 [ 1 ] , L_133 , & V_522 [ 1 ] ) ;
}
static inline void
F_182 ( struct V_518 * V_519 )
{
}
static inline void
F_186 ( struct V_518 * V_519 )
{
}
static void F_187 ( char * V_523 , char * V_524 , unsigned int V_66 )
{
unsigned int V_212 , V_213 ;
for ( V_212 = 0 , V_213 = 0 ; V_212 < ( V_66 ) ; V_212 ++ ) {
V_523 [ V_213 ] = 'A' + ( 0x0F & ( V_524 [ V_212 ] >> 4 ) ) ;
V_523 [ V_213 + 1 ] = 'A' + ( 0x0F & V_524 [ V_212 ] ) ;
V_213 += 2 ;
}
}
static int
F_188 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_377 . V_450 != V_390 ) {
struct V_518 * V_518 = V_2 -> V_28 ;
V_3 = V_518 -> V_52 -> V_525 ( V_518 ,
(struct V_94 * ) & V_2 -> V_377 ,
sizeof( V_2 -> V_377 ) ) ;
if ( V_3 < 0 ) {
struct V_392 * V_393 ;
struct V_398 * V_399 ;
V_393 = (struct V_392 * ) & V_2 -> V_377 ;
V_399 = (struct V_398 * ) & V_2 -> V_377 ;
if ( V_399 -> V_526 == V_397 )
F_4 ( V_59 , L_134 ,
& V_399 -> V_401 , V_3 ) ;
else
F_4 ( V_59 , L_135 ,
& V_393 -> V_395 . V_396 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_189 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_527 * V_528 ;
struct V_529 * V_530 ;
V_528 = F_102 ( sizeof( struct V_527 ) ,
V_145 ) ;
if ( V_528 ) {
V_528 -> V_531 . V_532 . V_533 = 32 ;
if ( V_2 -> V_428 [ 0 ] != 0 )
F_187 ( V_528 -> V_531 .
V_532 . V_534 ,
V_2 -> V_428 ,
V_382 ) ;
else
F_187 ( V_528 -> V_531 .
V_532 . V_534 ,
V_535 ,
V_382 ) ;
V_528 -> V_531 . V_532 . V_536 = 32 ;
if ( V_2 -> V_427 [ 0 ] != 0 )
F_187 ( V_528 -> V_531 .
V_532 . V_537 ,
V_2 -> V_427 ,
V_382 ) ;
else
F_187 ( V_528 -> V_531 .
V_532 . V_537 ,
L_136 ,
V_382 ) ;
V_528 -> V_531 . V_532 . V_538 = 0 ;
V_528 -> V_531 . V_532 . V_539 = 0 ;
V_530 = (struct V_529 * ) V_528 ;
V_530 -> V_540 = F_190 ( 0x81000044 ) ;
V_3 = F_191 ( V_2 , V_530 , 0x44 ) ;
F_10 ( V_528 ) ;
F_35 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_403 ;
int V_541 , V_542 ;
struct V_518 * V_518 = V_2 -> V_28 ;
struct V_94 * V_543 ;
V_543 = (struct V_94 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_450 == V_397 ) {
V_403 = ( (struct V_398 * ) V_543 ) -> V_405 ;
V_541 = sizeof( struct V_398 ) ;
V_542 = V_397 ;
} else {
V_403 = ( (struct V_392 * ) V_543 ) -> V_404 ;
V_541 = sizeof( struct V_392 ) ;
V_542 = V_391 ;
}
if ( V_518 == NULL ) {
V_3 = F_192 ( F_116 ( V_2 ) , V_542 , V_544 ,
V_545 , & V_518 , 1 ) ;
if ( V_3 < 0 ) {
F_4 ( V_59 , L_137 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_4 ( V_20 , L_138 ) ;
V_2 -> V_28 = V_518 ;
V_518 -> V_520 -> V_546 = V_547 ;
if ( V_542 == V_397 )
F_186 ( V_518 ) ;
else
F_182 ( V_518 ) ;
}
V_3 = F_188 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_518 -> V_520 -> V_548 = 7 * V_54 ;
V_518 -> V_520 -> V_549 = 5 * V_54 ;
if ( V_2 -> V_260 ) {
if ( V_518 -> V_520 -> V_550 < ( 200 * 1024 ) )
V_518 -> V_520 -> V_550 = 200 * 1024 ;
if ( V_518 -> V_520 -> V_551 < ( 140 * 1024 ) )
V_518 -> V_520 -> V_551 = 140 * 1024 ;
}
if ( V_2 -> V_424 ) {
int V_552 = 1 ;
V_3 = F_193 ( V_518 , V_553 , V_554 ,
( char * ) & V_552 , sizeof( V_552 ) ) ;
if ( V_3 )
F_4 ( V_20 , L_139 ,
V_3 ) ;
}
F_4 ( V_20 , L_140 ,
V_518 -> V_520 -> V_550 ,
V_518 -> V_520 -> V_551 , V_518 -> V_520 -> V_548 ) ;
V_3 = V_518 -> V_52 -> V_555 ( V_518 , V_543 , V_541 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( V_20 , L_141 , V_3 ) ;
F_9 ( V_518 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_403 == F_111 ( V_406 ) )
V_3 = F_189 ( V_2 ) ;
return V_3 ;
}
static int
F_136 ( struct V_1 * V_2 )
{
T_5 * V_403 ;
struct V_398 * V_409 = (struct V_398 * ) & V_2 -> V_95 ;
struct V_392 * V_402 = (struct V_392 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_450 == V_397 )
V_403 = & V_409 -> V_405 ;
else
V_403 = & V_402 -> V_404 ;
if ( * V_403 == 0 ) {
int V_3 ;
* V_403 = F_111 ( V_96 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_403 = F_111 ( V_406 ) ;
}
return F_17 ( V_2 ) ;
}
void F_194 ( unsigned int V_440 , struct V_9 * V_10 ,
struct V_486 * V_487 , struct V_152 * V_556 )
{
T_7 V_557 = F_195 ( V_10 -> V_558 . V_559 ) ;
if ( V_556 && V_556 -> V_280 ) {
V_10 -> V_558 . V_559 = 0 ;
V_10 -> V_560 = 0 ;
F_4 ( V_20 , L_142 ) ;
return;
} else if ( V_556 )
V_10 -> V_560 = 1 ;
if ( V_10 -> V_560 == 0 ) {
F_4 ( V_20 , L_143 ) ;
return;
}
if ( ! F_196 ( V_440 , V_10 ) ) {
T_7 V_561 = F_195 ( V_10 -> V_558 . V_559 ) ;
F_4 ( V_20 , L_144 , V_561 ) ;
if ( V_556 == NULL ) {
if ( ( V_557 & V_562 ) == 0 )
V_561 &= ~ V_562 ;
if ( ( V_557 & V_563 ) == 0 ) {
if ( V_561 & V_563 )
F_4 ( V_59 , L_145 ) ;
V_561 &= ~ V_563 ;
} else if ( ( V_561 & V_563 ) == 0 ) {
F_4 ( V_59 , L_146 ) ;
F_4 ( V_59 , L_147 ) ;
}
}
if ( V_561 & V_564 )
F_4 ( V_59 , L_148 ) ;
V_561 &= V_565 ;
if ( V_556 && V_556 -> V_315 )
V_561 &= ~ V_562 ;
else if ( V_562 & V_561 ) {
F_4 ( V_20 , L_149 ) ;
if ( V_487 )
V_487 -> V_497 |=
V_566 ;
}
if ( V_556 && V_556 -> V_238 == 0 )
V_561 &= ~ V_563 ;
else if ( V_561 & V_563 ) {
F_4 ( V_20 , L_150 ) ;
if ( V_487 )
V_487 -> V_497 |=
V_567 ;
}
F_4 ( V_20 , L_151 , ( int ) V_561 ) ;
#ifdef F_62
if ( V_561 & V_568 )
F_4 ( V_20 , L_152 ) ;
if ( V_561 & V_569 )
F_4 ( V_20 , L_153 ) ;
if ( V_561 & V_563 )
F_4 ( V_20 , L_154 ) ;
if ( V_561 & V_570 )
F_4 ( V_20 , L_155 ) ;
if ( V_561 & V_562 )
F_4 ( V_20 , L_156 ) ;
if ( V_561 & V_571 )
F_4 ( V_20 , L_157 ) ;
if ( V_561 & V_572 )
F_4 ( V_20 , L_158 ) ;
if ( V_561 & V_573 )
F_4 ( V_20 , L_159 ) ;
if ( V_561 & V_564 )
F_4 ( V_20 , L_160 ) ;
#endif
if ( F_197 ( V_440 , V_10 , V_561 ) ) {
if ( V_556 == NULL ) {
F_4 ( V_20 , L_161 ) ;
} else
F_4 ( V_59 , L_162 ) ;
}
}
}
int F_198 ( struct V_152 * V_574 ,
struct V_486 * V_487 )
{
F_134 ( & V_487 -> V_575 , V_576 ) ;
F_133 ( & V_487 -> V_577 ) ;
V_487 -> V_578 = V_579 ;
V_487 -> V_353 = V_574 -> V_353 ;
V_487 -> V_355 = V_574 -> V_355 ;
V_487 -> V_499 = V_574 -> V_230 ;
V_487 -> V_500 = V_574 -> V_231 ;
V_487 -> V_501 = V_574 -> V_234 ;
V_487 -> V_502 = V_574 -> V_233 ;
F_4 ( V_20 , L_163 ,
V_487 -> V_501 , V_487 -> V_502 ) ;
V_487 -> V_240 = V_574 -> V_240 ;
V_487 -> V_458 = V_574 -> V_458 ;
if ( V_574 -> V_265 )
V_487 -> V_497 |= V_580 ;
if ( V_574 -> V_292 )
V_487 -> V_497 |= V_581 ;
if ( V_574 -> V_295 )
V_487 -> V_497 |= V_582 ;
if ( V_574 -> V_239 )
V_487 -> V_497 |= V_583 ;
if ( V_574 -> V_232 )
V_487 -> V_497 |= V_584 ;
if ( V_574 -> V_268 )
V_487 -> V_497 |= V_585 ;
if ( V_574 -> V_251 )
V_487 -> V_497 |= V_586 ;
if ( V_574 -> V_273 )
V_487 -> V_497 |= V_587 ;
if ( V_574 -> V_284 )
V_487 -> V_497 |= V_588 ;
if ( V_574 -> V_305 )
V_487 -> V_497 |= V_589 ;
if ( V_574 -> V_290 )
V_487 -> V_497 |= V_590 ;
if ( V_574 -> V_310 )
V_487 -> V_497 |= V_591 ;
if ( V_574 -> V_312 )
V_487 -> V_497 |= V_592 ;
if ( V_574 -> V_245 ) {
V_487 -> V_497 |= V_593 ;
V_487 -> V_594 = V_574 -> V_342 ;
}
if ( V_574 -> V_246 ) {
V_487 -> V_497 |= V_595 ;
V_487 -> V_596 = V_574 -> V_344 ;
}
if ( V_574 -> V_215 )
V_487 -> V_497 |= V_597 ;
if ( V_574 -> V_216 )
V_487 -> V_497 |= V_598 ;
if ( V_574 -> V_297 )
V_487 -> V_497 |= V_599 ;
if ( V_574 -> V_324 )
V_487 -> V_497 |= V_600 ;
if ( V_574 -> V_328 )
V_487 -> V_497 |= ( V_601 |
V_580 ) ;
if ( V_574 -> V_179 )
V_487 -> V_497 |= V_602 ;
if ( V_574 -> V_178 ) {
F_4 ( V_20 , L_164 ) ;
V_487 -> V_497 |= V_603 ;
}
if ( V_574 -> V_326 ) {
if ( V_574 -> V_273 ) {
F_4 ( V_59 , L_165 ) ;
}
V_487 -> V_497 |= V_604 ;
}
if ( ( V_574 -> V_312 ) && ( V_574 -> V_297 ) )
F_4 ( V_59 , L_166 ) ;
if ( V_574 -> V_205 ) {
V_487 -> V_205 = F_93 ( V_574 -> V_205 , V_145 ) ;
if ( V_487 -> V_205 == NULL )
return - V_146 ;
}
return 0 ;
}
static void
F_199 ( struct V_152 * V_420 )
{
F_10 ( V_420 -> V_364 ) ;
F_200 ( V_420 -> V_369 ) ;
F_10 ( V_420 -> V_204 ) ;
F_10 ( V_420 -> V_375 ) ;
F_10 ( V_420 -> V_379 ) ;
F_10 ( V_420 -> V_205 ) ;
}
void
F_201 ( struct V_152 * V_420 )
{
if ( ! V_420 )
return;
F_199 ( V_420 ) ;
F_10 ( V_420 ) ;
}
static char *
F_202 ( const struct V_152 * V_153 ,
const struct V_486 * V_487 )
{
char * V_605 , * V_202 ;
unsigned int V_606 = V_153 -> V_205 ? strlen ( V_153 -> V_205 ) + 1 : 0 ;
unsigned int V_607 = F_96 ( V_153 -> V_204 , V_464 + 1 ) ;
V_605 = F_73 ( V_607 + V_606 + 1 , V_145 ) ;
if ( V_605 == NULL )
return F_72 ( - V_146 ) ;
strncpy ( V_605 , V_153 -> V_204 , V_607 ) ;
V_202 = V_605 + V_607 ;
if ( V_606 ) {
* V_202 = F_203 ( V_487 ) ;
strncpy ( V_202 + 1 , V_153 -> V_205 , V_606 ) ;
V_202 += V_606 ;
}
* V_202 = '\0' ;
F_92 ( V_605 , F_203 ( V_487 ) ) ;
F_4 ( V_20 , L_167 , V_21 , V_605 ) ;
return V_605 ;
}
static int
F_204 ( const unsigned int V_440 , struct V_7 * V_8 ,
struct V_152 * V_420 , struct V_486 * V_487 ,
int V_608 )
{
int V_3 ;
unsigned int V_512 = 0 ;
struct V_513 * V_514 = NULL ;
char * V_605 = NULL , * V_609 = NULL , * V_610 = NULL ;
V_605 = F_202 ( V_420 , V_487 ) ;
if ( F_129 ( V_605 ) )
return F_130 ( V_605 ) ;
V_609 = V_608 ? V_605 + 1 : V_420 -> V_204 + 1 ;
V_3 = F_181 ( V_440 , V_8 , V_609 , V_487 -> V_458 ,
& V_512 , & V_514 , F_205 ( V_487 ) ) ;
if ( ! V_3 && V_512 > 0 ) {
char * V_611 = NULL ;
V_610 = F_206 ( V_487 -> V_206 ,
V_605 + 1 , V_514 ,
& V_611 ) ;
F_207 ( V_514 , V_512 ) ;
if ( F_129 ( V_610 ) ) {
V_3 = F_130 ( V_610 ) ;
V_610 = NULL ;
} else {
F_199 ( V_420 ) ;
V_3 = F_208 ( V_420 , V_610 ,
V_611 ) ;
}
F_10 ( V_611 ) ;
F_10 ( V_487 -> V_206 ) ;
V_487 -> V_206 = V_610 ;
}
F_10 ( V_605 ) ;
return V_3 ;
}
static int
F_208 ( struct V_152 * V_420 , char * V_612 ,
const char * V_201 )
{
int V_3 = 0 ;
if ( F_94 ( V_612 , V_201 , V_420 ) )
return - V_144 ;
if ( V_420 -> V_175 ) {
F_4 ( V_20 , L_168 ) ;
F_10 ( V_420 -> V_364 ) ;
V_420 -> V_364 = NULL ;
} else if ( V_420 -> V_364 ) {
F_4 ( V_20 , L_169 , V_420 -> V_364 ) ;
} else {
F_4 ( V_59 , L_170 ) ;
return - V_144 ;
}
if ( V_420 -> V_379 == NULL ) {
V_420 -> V_458 = F_209 () ;
} else {
V_420 -> V_458 = F_210 ( V_420 -> V_379 ) ;
if ( V_420 -> V_458 == NULL ) {
F_4 ( V_59 , L_171 ,
V_420 -> V_379 ) ;
return - V_613 ;
}
}
return V_3 ;
}
struct V_152 *
F_211 ( char * V_612 , const char * V_201 )
{
int V_3 ;
struct V_152 * V_420 ;
V_420 = F_73 ( sizeof( struct V_152 ) , V_145 ) ;
if ( ! V_420 )
return F_72 ( - V_146 ) ;
V_3 = F_208 ( V_420 , V_612 , V_201 ) ;
if ( V_3 ) {
F_201 ( V_420 ) ;
V_420 = F_72 ( V_3 ) ;
}
return V_420 ;
}
static int
F_212 ( struct V_1 * V_2 ,
unsigned int V_440 ,
struct V_9 * V_10 ,
struct V_486 * V_487 ,
char * V_605 )
{
int V_3 ;
char * V_614 ;
char V_615 , V_5 ;
V_615 = F_203 ( V_487 ) ;
V_614 = V_605 ;
V_3 = V_2 -> V_52 -> V_616 ( V_440 , V_10 , V_487 , L_95 ) ;
while ( V_3 == 0 ) {
while ( * V_614 == V_615 )
V_614 ++ ;
if ( ! * V_614 )
break;
while ( * V_614 && * V_614 != V_615 )
V_614 ++ ;
V_5 = * V_614 ;
* V_614 = 0 ;
V_3 = V_2 -> V_52 -> V_616 ( V_440 , V_10 , V_487 ,
V_605 ) ;
* V_614 = V_5 ;
}
return V_3 ;
}
int
F_213 ( struct V_486 * V_487 , struct V_152 * V_420 )
{
int V_3 ;
unsigned int V_440 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_605 ;
struct V_480 * V_481 ;
#ifdef F_214
int V_617 = 0 ;
#endif
#ifdef F_214
V_618:
if ( V_617 ) {
if ( V_10 )
F_164 ( V_10 ) ;
else if ( V_8 )
F_145 ( V_8 ) ;
V_487 -> V_497 &= ~ V_567 ;
F_159 ( V_440 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_605 = NULL ;
V_481 = NULL ;
V_440 = F_146 () ;
V_2 = F_126 ( V_420 ) ;
if ( F_129 ( V_2 ) ) {
V_3 = F_130 ( V_2 ) ;
goto V_508;
}
if ( ( V_420 -> V_362 < 20 ) ||
( V_420 -> V_362 > 60000 ) )
V_2 -> V_362 = V_619 ;
else
V_2 -> V_362 = V_420 -> V_362 ;
V_8 = F_157 ( V_2 , V_420 ) ;
if ( F_129 ( V_8 ) ) {
V_3 = F_130 ( V_8 ) ;
V_8 = NULL ;
goto V_620;
}
if ( ( V_420 -> V_334 == true ) && ( ( V_8 -> V_2 -> V_474 &
V_475 ) == 0 ) ) {
F_4 ( V_59 , L_172 ) ;
V_3 = - V_470 ;
goto V_620;
}
V_10 = F_167 ( V_8 , V_420 ) ;
if ( F_129 ( V_10 ) ) {
V_3 = F_130 ( V_10 ) ;
V_10 = NULL ;
if ( V_3 == - V_621 )
goto V_620;
goto V_622;
}
if ( F_215 ( V_10 -> V_8 ) ) {
F_194 ( V_440 , V_10 , V_487 , V_420 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_195 ( V_10 -> V_558 . V_559 ) &
V_564 ) ) {
V_3 = - V_621 ;
goto V_620;
}
} else
V_10 -> V_560 = 0 ;
if ( ! V_10 -> V_623 && V_2 -> V_52 -> V_624 )
V_2 -> V_52 -> V_624 ( V_440 , V_10 ) ;
V_487 -> V_355 = V_2 -> V_52 -> V_625 ( V_10 , V_420 ) ;
V_487 -> V_353 = V_2 -> V_52 -> V_626 ( V_10 , V_420 ) ;
V_622:
#ifdef F_214
if ( V_617 == 0 ) {
int V_627 = F_204 ( V_440 , V_8 , V_420 , V_487 ,
false ) ;
if ( ! V_627 ) {
V_617 ++ ;
goto V_618;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_52 -> V_616 ) {
V_3 = - V_56 ;
goto V_620;
}
V_605 = F_216 ( V_420 , V_487 , V_10 ,
V_10 -> V_471 & V_472 ) ;
if ( V_605 == NULL ) {
V_3 = - V_146 ;
goto V_620;
}
V_3 = V_2 -> V_52 -> V_616 ( V_440 , V_10 , V_487 ,
V_605 ) ;
if ( V_3 != 0 && V_3 != - V_628 ) {
F_10 ( V_605 ) ;
goto V_620;
}
if ( V_3 != - V_628 ) {
V_3 = F_212 ( V_2 ,
V_440 , V_10 , V_487 ,
V_605 ) ;
if ( V_3 != 0 ) {
F_4 ( V_59 , L_173
L_174 ) ;
V_487 -> V_497 |= V_505 ;
V_3 = 0 ;
}
}
F_10 ( V_605 ) ;
}
if ( V_3 == - V_628 ) {
#ifdef F_214
if ( V_617 > V_629 ) {
V_3 = - V_630 ;
goto V_620;
}
V_3 = F_204 ( V_440 , V_8 , V_420 , V_487 , true ) ;
if ( ! V_3 ) {
V_617 ++ ;
goto V_618;
}
goto V_620;
#else
V_3 = - V_470 ;
#endif
}
if ( V_3 )
goto V_620;
V_481 = F_102 ( sizeof *V_481 , V_145 ) ;
if ( V_481 == NULL ) {
V_3 = - V_146 ;
goto V_620;
}
V_481 -> V_631 = V_8 -> V_230 ;
V_481 -> V_632 = V_10 ;
V_481 -> V_485 = V_38 ;
F_217 ( V_633 , & V_481 -> V_484 ) ;
F_217 ( V_483 , & V_481 -> V_484 ) ;
V_487 -> V_488 = V_481 ;
F_2 ( & V_487 -> V_577 ) ;
F_218 ( & V_487 -> V_578 , V_481 ) ;
F_3 ( & V_487 -> V_577 ) ;
F_24 ( V_46 , & V_487 -> V_575 ,
V_634 ) ;
V_620:
if ( V_3 ) {
if ( V_10 )
F_164 ( V_10 ) ;
else if ( V_8 )
F_145 ( V_8 ) ;
else
F_119 ( V_2 , 0 ) ;
}
V_508:
F_159 ( V_440 ) ;
return V_3 ;
}
int
F_219 ( const unsigned int V_440 , struct V_7 * V_8 ,
const char * V_635 , struct V_9 * V_10 ,
const struct V_510 * V_511 )
{
struct V_529 * V_636 ;
struct V_529 * V_637 ;
T_8 * V_638 ;
T_9 * V_639 ;
unsigned char * V_640 ;
int V_3 = 0 ;
int V_66 ;
T_10 V_641 , V_642 ;
if ( V_8 == NULL )
return - V_643 ;
V_636 = F_26 () ;
if ( V_636 == NULL )
return - V_146 ;
V_637 = V_636 ;
F_220 ( V_636 , V_644 ,
NULL , 4 ) ;
V_636 -> V_645 = F_221 ( V_8 -> V_2 ) ;
V_636 -> V_646 = V_8 -> V_647 ;
V_638 = ( T_8 * ) V_636 ;
V_639 = ( T_9 * ) V_637 ;
V_638 -> V_648 = 0xFF ;
V_638 -> V_471 = F_222 ( V_649 ) ;
V_640 = & V_638 -> V_650 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_651 & V_652 ) ) {
V_638 -> V_653 = F_222 ( 1 ) ;
* V_640 = 0 ;
V_640 ++ ;
} else {
V_638 -> V_653 = F_222 ( V_654 ) ;
#ifdef F_86
if ( ( V_655 & V_656 ) &&
( V_8 -> V_155 == V_173 ) )
F_223 ( V_10 -> V_369 , V_8 -> V_2 -> V_657 ,
V_8 -> V_2 -> V_651 &
V_658 ? true : false ,
V_640 ) ;
else
#endif
V_3 = F_224 ( V_10 -> V_369 , V_8 -> V_2 -> V_657 ,
V_640 , V_511 ) ;
if ( V_3 ) {
F_4 ( V_20 , L_175 ,
V_21 , V_3 ) ;
F_64 ( V_636 ) ;
return V_3 ;
}
V_640 += V_654 ;
if ( V_8 -> V_474 & V_659 ) {
* V_640 = 0 ;
V_640 ++ ;
}
}
if ( V_8 -> V_2 -> V_157 )
V_636 -> V_660 |= V_661 ;
if ( V_8 -> V_474 & V_662 ) {
V_636 -> V_660 |= V_663 ;
}
if ( V_8 -> V_474 & V_664 ) {
V_636 -> V_660 |= V_665 ;
}
if ( V_8 -> V_474 & V_659 ) {
V_636 -> V_660 |= V_666 ;
V_66 =
F_225 ( ( V_667 * ) V_640 , V_635 ,
6 *
( + 256 ) , V_511 ) ;
V_640 += 2 * V_66 ;
V_640 += 2 ;
} else {
strcpy ( V_640 , V_635 ) ;
V_640 += strlen ( V_635 ) + 1 ;
}
strcpy ( V_640 , L_176 ) ;
V_640 += strlen ( L_176 ) ;
V_640 += 1 ;
V_642 = V_640 - & V_638 -> V_650 [ 0 ] ;
V_638 -> V_668 . V_540 = F_190 ( F_226 (
V_638 -> V_668 . V_540 ) + V_642 ) ;
V_638 -> V_669 = F_222 ( V_642 ) ;
V_3 = F_227 ( V_440 , V_8 , V_636 , V_637 , & V_66 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_670 ;
V_10 -> V_462 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_671 = V_637 -> V_672 ;
V_640 = F_228 ( V_637 ) ;
V_641 = F_229 ( V_637 ) ;
V_66 = F_96 ( V_640 , V_641 - 2 ) ;
if ( V_636 -> V_660 & V_666 )
V_670 = true ;
else
V_670 = false ;
if ( V_66 == 3 ) {
if ( ( V_640 [ 0 ] == 'I' ) && ( V_640 [ 1 ] == 'P' ) &&
( V_640 [ 2 ] == 'C' ) ) {
F_4 ( V_20 , L_177 ) ;
V_10 -> V_623 = 1 ;
}
} else if ( V_66 == 2 ) {
if ( ( V_640 [ 0 ] == 'A' ) && ( V_640 [ 1 ] == ':' ) ) {
F_4 ( V_20 , L_178 ) ;
}
}
V_640 += V_66 + 1 ;
V_641 -= ( V_66 + 1 ) ;
F_230 ( V_10 -> V_463 , V_635 , sizeof( V_10 -> V_463 ) ) ;
F_10 ( V_10 -> V_673 ) ;
V_10 -> V_673 = F_231 ( V_640 ,
V_641 , V_670 ,
V_511 ) ;
F_4 ( V_20 , L_179 , V_10 -> V_673 ) ;
if ( ( V_637 -> V_674 == 3 ) ||
( V_637 -> V_674 == 7 ) )
V_10 -> V_471 = F_232 ( V_639 -> V_675 ) ;
else
V_10 -> V_471 = 0 ;
F_4 ( V_20 , L_180 , V_10 -> V_471 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_637 -> V_672 ;
}
F_64 ( V_636 ) ;
return V_3 ;
}
static void F_233 ( struct V_676 * V_121 )
{
struct V_486 * V_677 = F_22 ( V_121 , struct V_486 , V_678 ) ;
F_234 ( V_677 -> V_458 ) ;
F_10 ( V_677 ) ;
}
void
F_235 ( struct V_486 * V_487 )
{
struct V_679 * V_680 = & V_487 -> V_578 ;
struct V_681 * V_682 ;
struct V_480 * V_481 ;
F_121 ( & V_487 -> V_575 ) ;
F_2 ( & V_487 -> V_577 ) ;
while ( ( V_682 = F_236 ( V_680 ) ) ) {
V_481 = F_237 ( V_682 , struct V_480 , V_683 ) ;
F_180 ( V_481 ) ;
F_238 ( V_483 , & V_481 -> V_484 ) ;
F_239 ( V_682 , V_680 ) ;
F_3 ( & V_487 -> V_577 ) ;
F_170 ( V_481 ) ;
F_2 ( & V_487 -> V_577 ) ;
}
F_3 ( & V_487 -> V_577 ) ;
F_10 ( V_487 -> V_206 ) ;
F_10 ( V_487 -> V_205 ) ;
F_240 ( & V_487 -> V_678 , F_233 ) ;
}
int
F_158 ( const unsigned int V_440 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_52 -> V_684 || ! V_2 -> V_52 -> V_685 )
return - V_56 ;
if ( ! V_2 -> V_52 -> V_684 ( V_2 ) )
return 0 ;
F_241 ( V_2 , 1 ) ;
V_3 = V_2 -> V_52 -> V_685 ( V_440 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_686 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_160 ( const unsigned int V_440 , struct V_7 * V_8 ,
struct V_510 * V_687 )
{
int V_3 = - V_56 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_474 = V_2 -> V_474 ;
if ( V_688 == 0 )
V_8 -> V_474 &= ( ~ V_2 -> V_185 -> F_215 ) ;
F_4 ( V_20 , L_181 ,
V_2 -> V_651 , V_2 -> V_474 , V_2 -> V_689 ) ;
if ( V_2 -> V_52 -> V_690 )
V_3 = V_2 -> V_52 -> V_690 ( V_440 , V_8 , V_687 ) ;
if ( V_3 )
F_4 ( V_59 , L_182 , V_3 ) ;
return V_3 ;
}
static int
F_242 ( struct V_152 * V_153 , struct V_7 * V_8 )
{
V_153 -> V_155 = V_8 -> V_155 ;
if ( V_153 -> V_155 == V_162 )
return 0 ;
return F_149 ( V_153 , V_8 ) ;
}
static struct V_9 *
F_243 ( struct V_486 * V_487 , T_2 V_691 )
{
int V_3 ;
struct V_9 * V_692 = F_244 ( V_487 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_152 * V_556 ;
V_556 = F_102 ( sizeof( * V_556 ) , V_145 ) ;
if ( V_556 == NULL )
return F_72 ( - V_146 ) ;
V_556 -> V_458 = V_487 -> V_458 ;
V_556 -> V_230 = V_691 ;
V_556 -> V_229 = V_691 ;
V_556 -> V_204 = V_692 -> V_463 ;
V_556 -> V_262 = V_692 -> V_262 ;
V_556 -> V_282 = V_692 -> V_282 ;
V_556 -> V_318 = V_692 -> V_318 ;
V_556 -> V_280 = ! V_692 -> V_560 ;
V_556 -> V_155 = V_692 -> V_8 -> V_155 ;
V_556 -> V_157 = V_692 -> V_8 -> V_157 ;
V_3 = F_242 ( V_556 , V_692 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_72 ( V_3 ) ;
goto V_508;
}
F_2 ( & V_22 ) ;
++ V_692 -> V_8 -> V_2 -> V_415 ;
F_3 ( & V_22 ) ;
V_8 = F_157 ( V_692 -> V_8 -> V_2 , V_556 ) ;
if ( F_129 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_119 ( V_692 -> V_8 -> V_2 , 0 ) ;
goto V_508;
}
V_10 = F_167 ( V_8 , V_556 ) ;
if ( F_129 ( V_10 ) ) {
F_145 ( V_8 ) ;
goto V_508;
}
if ( F_215 ( V_8 ) )
F_194 ( 0 , V_10 , NULL , V_556 ) ;
V_508:
F_10 ( V_556 -> V_364 ) ;
F_10 ( V_556 -> V_369 ) ;
F_10 ( V_556 ) ;
return V_10 ;
}
struct V_9 *
F_244 ( struct V_486 * V_487 )
{
return F_173 ( F_174 ( V_487 ) ) ;
}
static struct V_480 *
F_245 ( struct V_679 * V_680 , T_2 V_150 )
{
struct V_681 * V_682 = V_680 -> V_681 ;
struct V_480 * V_481 ;
while ( V_682 ) {
V_481 = F_237 ( V_682 , struct V_480 , V_683 ) ;
if ( F_246 ( V_481 -> V_631 , V_150 ) )
V_682 = V_682 -> V_693 ;
else if ( F_247 ( V_481 -> V_631 , V_150 ) )
V_682 = V_682 -> V_694 ;
else
return V_481 ;
}
return NULL ;
}
static void
F_218 ( struct V_679 * V_680 , struct V_480 * V_695 )
{
struct V_681 * * V_494 = & ( V_680 -> V_681 ) , * V_696 = NULL ;
struct V_480 * V_481 ;
while ( * V_494 ) {
V_481 = F_237 ( * V_494 , struct V_480 , V_683 ) ;
V_696 = * V_494 ;
if ( F_246 ( V_481 -> V_631 , V_695 -> V_631 ) )
V_494 = & ( ( * V_494 ) -> V_693 ) ;
else
V_494 = & ( ( * V_494 ) -> V_694 ) ;
}
F_248 ( & V_695 -> V_683 , V_696 , V_494 ) ;
F_249 ( & V_695 -> V_683 , V_680 ) ;
}
struct V_480 *
F_250 ( struct V_486 * V_487 )
{
int V_697 ;
T_2 V_691 = F_251 () ;
struct V_480 * V_481 , * V_698 ;
if ( ! ( V_487 -> V_497 & V_601 ) )
return F_180 ( F_174 ( V_487 ) ) ;
F_2 ( & V_487 -> V_577 ) ;
V_481 = F_245 ( & V_487 -> V_578 , V_691 ) ;
if ( V_481 )
F_180 ( V_481 ) ;
F_3 ( & V_487 -> V_577 ) ;
if ( V_481 == NULL ) {
V_698 = F_102 ( sizeof( * V_481 ) , V_145 ) ;
if ( V_698 == NULL )
return F_72 ( - V_146 ) ;
V_698 -> V_631 = V_691 ;
V_698 -> V_632 = F_72 ( - V_621 ) ;
F_217 ( V_699 , & V_698 -> V_484 ) ;
F_217 ( V_483 , & V_698 -> V_484 ) ;
F_180 ( V_698 ) ;
F_2 ( & V_487 -> V_577 ) ;
V_481 = F_245 ( & V_487 -> V_578 , V_691 ) ;
if ( V_481 ) {
F_180 ( V_481 ) ;
F_3 ( & V_487 -> V_577 ) ;
F_10 ( V_698 ) ;
goto V_700;
}
V_481 = V_698 ;
F_218 ( & V_487 -> V_578 , V_481 ) ;
F_3 ( & V_487 -> V_577 ) ;
} else {
V_700:
V_697 = F_252 ( & V_481 -> V_484 , V_699 ,
V_138 ) ;
if ( V_697 ) {
F_170 ( V_481 ) ;
return F_72 ( - V_72 ) ;
}
if ( ! F_129 ( V_481 -> V_632 ) )
return V_481 ;
if ( F_23 ( V_38 , V_481 -> V_485 + V_701 ) ) {
F_170 ( V_481 ) ;
return F_72 ( - V_621 ) ;
}
if ( F_253 ( V_699 , & V_481 -> V_484 ) )
goto V_700;
}
V_481 -> V_632 = F_243 ( V_487 , V_691 ) ;
F_238 ( V_699 , & V_481 -> V_484 ) ;
F_254 ( & V_481 -> V_484 , V_699 ) ;
if ( F_129 ( V_481 -> V_632 ) ) {
F_170 ( V_481 ) ;
return F_72 ( - V_621 ) ;
}
return V_481 ;
}
static void
V_576 ( struct V_48 * V_49 )
{
struct V_486 * V_487 = F_22 ( V_49 , struct V_486 ,
V_575 . V_49 ) ;
struct V_679 * V_680 = & V_487 -> V_578 ;
struct V_681 * V_682 = F_236 ( V_680 ) ;
struct V_681 * V_5 ;
struct V_480 * V_481 ;
F_2 ( & V_487 -> V_577 ) ;
V_682 = F_236 ( V_680 ) ;
while ( V_682 != NULL ) {
V_5 = V_682 ;
V_682 = F_255 ( V_5 ) ;
V_481 = F_237 ( V_5 , struct V_480 , V_683 ) ;
if ( F_172 ( V_633 , & V_481 -> V_484 ) ||
F_61 ( & V_481 -> V_482 ) != 0 ||
F_30 ( V_481 -> V_485 + V_634 , V_38 ) )
continue;
F_180 ( V_481 ) ;
F_238 ( V_483 , & V_481 -> V_484 ) ;
F_239 ( V_5 , V_680 ) ;
F_3 ( & V_487 -> V_577 ) ;
F_170 ( V_481 ) ;
F_2 ( & V_487 -> V_577 ) ;
}
F_3 ( & V_487 -> V_577 ) ;
F_24 ( V_46 , & V_487 -> V_575 ,
V_634 ) ;
}
