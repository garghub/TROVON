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
if ( ( V_2 -> V_15 == V_62 ||
V_2 -> V_15 == V_45 ) &&
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
case V_201 :
V_153 -> V_52 = & V_194 ;
V_153 -> V_185 = & V_202 ;
break;
case V_203 :
V_153 -> V_52 = & V_194 ;
V_153 -> V_185 = & V_204 ;
break;
default:
F_4 ( V_59 , L_32 , V_149 ) ;
return 1 ;
}
return 0 ;
}
static int
F_90 ( const char * V_205 , struct V_152 * V_153 )
{
char * V_206 ;
const char * V_207 = L_33 ;
T_4 V_36 ;
V_36 = strspn ( V_205 , V_207 ) ;
if ( V_36 != 2 )
return - V_144 ;
V_206 = strpbrk ( V_205 + 2 , V_207 ) ;
if ( ! V_206 )
return - V_144 ;
++ V_206 ;
V_36 = strcspn ( V_206 , V_207 ) ;
V_206 += V_36 ;
V_153 -> V_208 = F_91 ( V_205 , V_206 - V_205 , V_145 ) ;
if ( ! V_153 -> V_208 )
return - V_146 ;
F_92 ( V_153 -> V_208 , '\\' ) ;
if ( * V_206 == '/' || * V_206 == '\\' )
V_206 ++ ;
if ( ! * V_206 )
return 0 ;
V_153 -> V_209 = F_93 ( V_206 , V_145 ) ;
if ( ! V_153 -> V_209 )
return - V_146 ;
return 0 ;
}
static int
F_94 ( const char * V_210 , const char * V_205 ,
struct V_152 * V_153 )
{
char * V_211 , * V_212 ;
char * V_213 = NULL , * V_214 ;
unsigned int V_215 , V_216 , V_217 ;
char V_218 [ 2 ] ;
short int V_219 = - 1 ;
short int V_220 = - 1 ;
bool V_221 = false ;
bool V_222 = false ;
bool V_223 = false ;
char * V_224 = NULL ;
char * V_225 = F_95 () -> V_225 ;
char * string = NULL ;
char * V_226 , * V_149 ;
char V_143 ;
bool V_227 = false ;
bool V_228 = false ;
unsigned short V_229 = 0 ;
struct V_94 * V_95 = (struct V_94 * ) & V_153 -> V_95 ;
V_218 [ 0 ] = ',' ;
V_218 [ 1 ] = 0 ;
V_143 = V_218 [ 0 ] ;
memset ( V_153 , 0 , sizeof( * V_153 ) ) ;
memset ( V_153 -> V_230 , 0x20 , V_231 ) ;
for ( V_216 = 0 ; V_216 < F_96 ( V_225 , V_231 ) ; V_216 ++ )
V_153 -> V_230 [ V_216 ] = toupper ( V_225 [ V_216 ] ) ;
V_153 -> V_230 [ V_231 ] = 0 ;
V_153 -> V_232 [ 0 ] = 0 ;
V_153 -> V_233 = F_97 () ;
V_153 -> V_234 = F_97 () ;
V_153 -> V_235 = F_98 () ;
V_153 -> V_236 = true ;
V_153 -> V_237 = V_153 -> V_238 = V_239 | V_240 | V_241 ;
V_153 -> V_242 = 1 ;
V_153 -> V_243 = 1 ;
V_153 -> V_179 = true ;
V_153 -> V_244 = V_245 ;
V_153 -> V_52 = & V_194 ;
V_153 -> V_185 = & V_204 ;
V_153 -> V_50 = V_246 ;
if ( ! V_210 )
goto V_247;
V_213 = F_91 ( V_210 , V_248 , V_145 ) ;
if ( ! V_213 )
goto V_247;
V_214 = V_213 ;
V_212 = V_214 + strlen ( V_214 ) ;
if ( strncmp ( V_214 , L_34 , 4 ) == 0 ) {
if ( V_214 [ 4 ] != 0 ) {
V_218 [ 0 ] = V_214 [ 4 ] ;
V_214 += 5 ;
} else {
F_4 ( V_20 , L_35 ) ;
}
}
V_153 -> V_249 = false ;
V_153 -> V_250 = false ;
switch ( F_90 ( V_205 , V_153 ) ) {
case 0 :
break;
case - V_146 :
F_4 ( V_59 , L_36 ) ;
goto V_247;
case - V_144 :
F_4 ( V_59 , L_37 ) ;
goto V_247;
default:
F_4 ( V_59 , L_38 ) ;
goto V_247;
}
while ( ( V_211 = F_99 ( & V_214 , V_218 ) ) != NULL ) {
T_1 args [ V_154 ] ;
unsigned long V_147 ;
int V_251 ;
if ( ! * V_211 )
continue;
V_251 = F_85 ( V_211 , V_252 , args ) ;
switch ( V_251 ) {
case V_253 :
break;
case V_254 :
V_153 -> V_255 = 0 ;
break;
case V_256 :
V_153 -> V_255 = 1 ;
break;
case V_257 :
V_219 = 1 ;
break;
case V_258 :
V_219 = 0 ;
break;
case V_259 :
V_220 = 1 ;
break;
case V_260 :
V_220 = 0 ;
break;
case V_261 :
V_153 -> V_262 = 1 ;
break;
case V_263 :
V_153 -> V_264 = 1 ;
break;
case V_265 :
V_153 -> V_266 = 1 ;
break;
case V_267 :
V_153 -> V_266 = 0 ;
break;
case V_268 :
V_153 -> V_269 = 0 ;
break;
case V_270 :
V_153 -> V_269 = 1 ;
break;
case V_271 :
V_153 -> V_272 = true ;
V_153 -> V_236 = false ;
break;
case V_273 :
V_153 -> V_272 = false ;
break;
case V_274 :
V_153 -> V_236 = true ;
V_153 -> V_272 = false ;
break;
case V_275 :
V_153 -> V_236 = false ;
break;
case V_276 :
V_153 -> V_277 = 1 ;
break;
case V_278 :
V_153 -> V_277 = 0 ;
break;
case V_279 :
V_153 -> V_280 = 1 ;
break;
case V_281 :
V_153 -> V_242 = 1 ;
break;
case V_282 :
V_153 -> V_242 = 0 ;
break;
case V_283 :
V_153 -> V_284 = 1 ;
break;
case V_285 :
V_153 -> V_286 = 1 ;
break;
case V_287 :
V_153 -> V_288 = 0 ;
break;
case V_289 :
V_153 -> V_288 = 1 ;
if ( V_153 -> V_238 ==
( V_290 & ~ ( V_291 | V_292 ) ) )
V_153 -> V_238 = V_290 ;
break;
case V_293 :
V_153 -> V_294 = 1 ;
break;
case V_295 :
V_153 -> V_296 = 1 ;
break;
case V_297 :
V_153 -> V_296 = 0 ;
break;
case V_298 :
V_153 -> V_299 = 1 ;
break;
case V_300 :
V_153 -> V_301 = true ;
break;
case V_302 :
V_153 -> V_301 = false ;
break;
case V_303 :
V_153 -> V_266 = 0 ;
break;
case V_304 :
V_153 -> V_266 = 1 ;
break;
case V_305 :
V_153 -> V_306 = 0 ;
break;
case V_307 :
V_153 -> V_306 = 1 ;
break;
case V_308 :
V_153 -> V_309 = 1 ;
break;
case V_310 :
V_153 -> V_309 = 0 ;
break;
case V_311 :
V_153 -> V_243 = 1 ;
break;
case V_312 :
V_153 -> V_243 = 0 ;
break;
case V_313 :
V_153 -> V_314 = 1 ;
break;
case V_315 :
V_153 -> V_316 = 1 ;
break;
case V_317 :
V_153 -> V_316 = 0 ;
break;
case V_318 :
V_153 -> V_319 = 0 ;
break;
case V_320 :
V_153 -> V_319 = 1 ;
break;
case V_321 :
V_153 -> V_322 = 1 ;
break;
case V_323 :
V_153 -> V_157 = true ;
break;
case V_324 :
V_153 -> V_325 = 1 ;
break;
case V_326 :
F_100 ( L_39 ) ;
break;
case V_327 :
#ifndef F_101
F_4 ( V_59 , L_40 ) ;
goto V_247;
#endif
V_153 -> V_328 = true ;
break;
case V_329 :
V_153 -> V_330 = true ;
break;
case V_331 :
V_153 -> V_332 = true ;
break;
case V_333 :
V_223 = true ;
break;
case V_334 :
V_153 -> V_335 = true ;
break;
case V_336 :
V_153 -> V_337 = true ;
if ( V_153 -> V_338 ) {
F_4 ( V_59 ,
L_41 ) ;
goto V_247;
}
break;
case V_339 :
V_153 -> V_338 = true ;
if ( ( V_153 -> V_337 ) || ( V_153 -> V_340 ) ) {
F_4 ( V_59 ,
L_41 ) ;
goto V_247;
}
break;
case V_341 :
V_153 -> V_340 = true ;
if ( V_153 -> V_338 ) {
F_4 ( V_59 ,
L_41 ) ;
goto V_247;
}
break;
case V_342 :
V_153 -> V_340 = false ;
break;
case V_343 :
V_153 -> V_344 = true ;
break;
case V_345 :
if ( F_77 ( args , & V_153 -> V_346 ) ) {
F_4 ( V_59 , L_42 ,
V_21 ) ;
goto V_247;
}
V_153 -> V_249 = true ;
break;
case V_347 :
if ( F_81 ( args , & V_153 -> V_348 ) ) {
F_4 ( V_59 , L_43 ,
V_21 ) ;
goto V_247;
}
V_153 -> V_250 = true ;
break;
case V_349 :
if ( F_77 ( args , & V_153 -> V_234 ) ) {
F_4 ( V_59 , L_44 ,
V_21 ) ;
goto V_247;
}
V_221 = true ;
break;
case V_350 :
if ( F_77 ( args , & V_153 -> V_233 ) ) {
F_4 ( V_59 , L_45 ,
V_21 ) ;
goto V_247;
}
break;
case V_351 :
if ( F_81 ( args , & V_153 -> V_235 ) ) {
F_4 ( V_59 , L_46 ,
V_21 ) ;
goto V_247;
}
V_222 = true ;
break;
case V_352 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_47 ,
V_21 ) ;
goto V_247;
}
V_153 -> V_238 = V_147 ;
break;
case V_353 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_48 ,
V_21 ) ;
goto V_247;
}
V_153 -> V_237 = V_147 ;
break;
case V_354 :
if ( F_74 ( args , & V_147 ) ||
V_147 > V_355 ) {
F_4 ( V_59 , L_49 ,
V_21 ) ;
goto V_247;
}
V_229 = ( unsigned short ) V_147 ;
break;
case V_356 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_50 ,
V_21 ) ;
goto V_247;
}
V_153 -> V_357 = V_147 ;
break;
case V_358 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_51 ,
V_21 ) ;
goto V_247;
}
V_153 -> V_359 = V_147 ;
break;
case V_360 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_52 ,
V_21 ) ;
goto V_247;
}
V_153 -> V_244 = V_54 * V_147 ;
if ( V_153 -> V_244 > V_361 ) {
F_4 ( V_59 , L_53 ) ;
goto V_247;
}
break;
case V_362 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_54 ,
V_21 ) ;
goto V_247;
}
V_153 -> V_50 = V_147 ;
break;
case V_363 :
if ( F_74 ( args , & V_147 ) ) {
F_4 ( V_59 , L_55 ,
V_21 ) ;
goto V_247;
}
V_153 -> V_364 = V_147 ;
break;
case V_365 :
if ( F_74 ( args , & V_147 ) || ( V_147 < 20 ) ||
( V_147 > 60000 ) ) {
F_4 ( V_59 , L_56 ,
V_21 ) ;
goto V_247;
}
V_153 -> V_366 = V_147 ;
break;
case V_367 :
V_153 -> V_175 = 1 ;
V_153 -> V_368 = NULL ;
break;
case V_369 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_370;
if ( F_96 ( string , V_371 ) >
V_371 ) {
F_100 ( L_57 ) ;
goto V_247;
}
F_10 ( V_153 -> V_368 ) ;
V_153 -> V_368 = F_93 ( string , V_145 ) ;
if ( ! V_153 -> V_368 )
goto V_247;
break;
case V_372 :
V_226 = strchr ( V_211 , '=' ) ;
V_226 ++ ;
if ( ! ( V_226 < V_212 && V_226 [ 1 ] == V_143 ) ) {
F_10 ( V_153 -> V_373 ) ;
V_153 -> V_373 = NULL ;
break;
}
case V_374 :
V_149 = strchr ( V_211 , '=' ) ;
V_149 ++ ;
V_226 = ( char * ) V_149 + strlen ( V_149 ) ;
if ( V_226 < V_212 && V_226 [ 1 ] == V_143 ) {
V_226 [ 0 ] = V_143 ;
while ( ( V_226 = strchr ( V_226 , V_143 ) )
!= NULL && ( V_226 [ 1 ] == V_143 ) ) {
V_226 = ( char * ) & V_226 [ 2 ] ;
}
if ( V_226 ) {
V_226 [ 0 ] = '\0' ;
V_214 = ( char * ) & V_226 [ 1 ] ;
} else
V_214 = V_212 ;
}
F_10 ( V_153 -> V_373 ) ;
V_215 = strlen ( V_149 ) ;
V_153 -> V_373 = F_102 ( V_215 + 1 , V_145 ) ;
if ( V_153 -> V_373 == NULL ) {
F_100 ( L_58 ) ;
goto V_247;
}
for ( V_216 = 0 , V_217 = 0 ; V_216 < V_215 ; V_216 ++ , V_217 ++ ) {
V_153 -> V_373 [ V_217 ] = V_149 [ V_216 ] ;
if ( ( V_149 [ V_216 ] == V_143 ) &&
V_149 [ V_216 + 1 ] == V_143 )
V_216 ++ ;
}
V_153 -> V_373 [ V_217 ] = '\0' ;
break;
case V_375 :
V_227 = false ;
break;
case V_376 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_370;
if ( ! F_103 ( V_95 , string ,
strlen ( string ) ) ) {
F_104 ( L_59 , string ) ;
goto V_247;
}
V_227 = true ;
break;
case V_377 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_370;
if ( F_96 ( string , V_378 )
== V_378 ) {
F_100 ( L_60 ) ;
goto V_247;
}
F_10 ( V_153 -> V_379 ) ;
V_153 -> V_379 = F_93 ( string , V_145 ) ;
if ( ! V_153 -> V_379 ) {
F_100 ( L_61 ) ;
goto V_247;
}
F_4 ( V_20 , L_62 ) ;
break;
case V_380 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_370;
if ( ! F_103 (
(struct V_94 * ) & V_153 -> V_381 ,
string , strlen ( string ) ) ) {
F_100 ( L_63 ,
string ) ;
goto V_247;
}
break;
case V_382 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_370;
if ( F_96 ( string , 1024 ) >= 65 ) {
F_100 ( L_64 ) ;
goto V_247;
}
if ( strncasecmp ( string , L_65 , 7 ) != 0 ) {
F_10 ( V_153 -> V_383 ) ;
V_153 -> V_383 = F_93 ( string ,
V_145 ) ;
if ( ! V_153 -> V_383 ) {
F_100 ( L_66 ) ;
goto V_247;
}
}
F_4 ( V_20 , L_67 , string ) ;
break;
case V_384 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_370;
memset ( V_153 -> V_230 , 0x20 ,
V_231 ) ;
for ( V_216 = 0 ; V_216 < V_231 ; V_216 ++ ) {
if ( string [ V_216 ] == 0 )
break;
V_153 -> V_230 [ V_216 ] = string [ V_216 ] ;
}
if ( V_216 == V_231 && string [ V_216 ] != 0 )
F_100 ( L_68 ) ;
break;
case V_385 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_370;
memset ( V_153 -> V_232 , 0x20 ,
V_386 ) ;
for ( V_216 = 0 ; V_216 < 15 ; V_216 ++ ) {
if ( string [ V_216 ] == 0 )
break;
V_153 -> V_232 [ V_216 ] = string [ V_216 ] ;
}
if ( V_216 == V_231 && string [ V_216 ] != 0 )
F_100 ( L_69 ) ;
break;
case V_387 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_370;
if ( strncasecmp ( string , L_70 , 1 ) == 0 ) {
if ( strlen ( string ) > 1 ) {
F_100 ( L_71
L_72
L_73
L_74 , string ) ;
goto V_247;
}
break;
}
F_100 ( L_75 ) ;
goto V_247;
case V_388 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_370;
if ( F_88 ( string , V_153 ) != 0 )
goto V_247;
V_228 = true ;
break;
case V_389 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_370;
if ( F_84 ( string , V_153 ) != 0 )
goto V_247;
break;
case V_390 :
string = F_75 ( args ) ;
if ( string == NULL )
goto V_370;
if ( F_87 ( string , V_153 ) != 0 )
goto V_247;
break;
default:
if ( ! V_224 )
V_224 = V_211 ;
break;
}
F_10 ( string ) ;
string = NULL ;
}
if ( ! V_223 && V_224 ) {
F_104 ( L_76 , V_224 ) ;
goto V_247;
}
#ifndef F_105
if ( V_153 -> V_332 ) {
F_4 ( V_59 , L_77 ) ;
goto V_247;
}
#endif
if ( ! V_153 -> V_208 ) {
F_4 ( V_59 , L_78 ) ;
goto V_247;
}
if ( ! strchr ( V_153 -> V_208 + 3 , '\\' ) ) {
F_4 ( V_59 , L_79 ) ;
goto V_247;
}
if ( ! V_227 ) {
int V_36 ;
const char * V_391 ;
V_391 = strchr ( & V_153 -> V_208 [ 2 ] , '\\' ) ;
V_36 = V_391 - & V_153 -> V_208 [ 2 ] ;
if ( ! F_103 ( V_95 , & V_153 -> V_208 [ 2 ] , V_36 ) ) {
F_104 ( L_80 ) ;
goto V_247;
}
}
F_41 ( V_95 , V_229 ) ;
if ( V_221 )
V_153 -> V_219 = V_219 ;
else if ( V_219 == 1 )
F_106 ( L_81 ) ;
if ( V_222 )
V_153 -> V_220 = V_220 ;
else if ( V_220 == 1 )
F_106 ( L_82 ) ;
if ( V_228 == false )
F_100 ( L_83
L_84
L_85
L_86
L_87 ) ;
F_10 ( V_213 ) ;
return 0 ;
V_370:
F_100 ( L_88 ) ;
V_247:
F_10 ( string ) ;
F_10 ( V_213 ) ;
return 1 ;
}
static bool
F_107 ( struct V_94 * V_381 , struct V_94 * V_392 )
{
switch ( V_381 -> V_393 ) {
case V_394 :
return ( V_392 -> V_393 == V_394 ) ;
case V_395 : {
struct V_396 * V_397 = (struct V_396 * ) V_381 ;
struct V_396 * V_398 = (struct V_396 * ) V_392 ;
return ( V_397 -> V_399 . V_400 == V_398 -> V_399 . V_400 ) ;
}
case V_401 : {
struct V_402 * V_403 = (struct V_402 * ) V_381 ;
struct V_402 * V_404 = (struct V_402 * ) V_392 ;
return F_108 ( & V_403 -> V_405 , & V_404 -> V_405 ) ;
}
default:
F_109 ( 1 ) ;
return false ;
}
}
static bool
F_110 ( struct V_1 * V_2 , struct V_94 * V_406 )
{
T_5 V_229 , * V_407 ;
switch ( V_406 -> V_393 ) {
case V_395 :
V_407 = & ( (struct V_396 * ) & V_2 -> V_95 ) -> V_408 ;
V_229 = ( (struct V_396 * ) V_406 ) -> V_408 ;
break;
case V_401 :
V_407 = & ( (struct V_402 * ) & V_2 -> V_95 ) -> V_409 ;
V_229 = ( (struct V_402 * ) V_406 ) -> V_409 ;
break;
default:
F_109 ( 1 ) ;
return false ;
}
if ( ! V_229 ) {
V_229 = F_111 ( V_96 ) ;
if ( V_229 == * V_407 )
return true ;
V_229 = F_111 ( V_410 ) ;
}
return V_229 == * V_407 ;
}
static bool
F_112 ( struct V_1 * V_2 , struct V_94 * V_406 ,
struct V_94 * V_381 )
{
switch ( V_406 -> V_393 ) {
case V_395 : {
struct V_396 * V_411 = (struct V_396 * ) V_406 ;
struct V_396 * V_412 =
(struct V_396 * ) & V_2 -> V_95 ;
if ( V_411 -> V_399 . V_400 != V_412 -> V_399 . V_400 )
return false ;
break;
}
case V_401 : {
struct V_402 * V_413 = (struct V_402 * ) V_406 ;
struct V_402 * V_414 =
(struct V_402 * ) & V_2 -> V_95 ;
if ( ! F_108 ( & V_413 -> V_405 ,
& V_414 -> V_405 ) )
return false ;
if ( V_413 -> V_415 != V_414 -> V_415 )
return false ;
break;
}
default:
F_109 ( 1 ) ;
return false ;
}
if ( ! F_107 ( V_381 , (struct V_94 * ) & V_2 -> V_381 ) )
return false ;
return true ;
}
static bool
F_113 ( struct V_1 * V_2 , struct V_152 * V_153 )
{
if ( V_2 -> V_52 -> V_416 ( V_2 , V_153 -> V_155 )
== V_156 )
return false ;
if ( V_153 -> V_157 && ! V_2 -> V_157 )
return false ;
return true ;
}
static int F_114 ( struct V_1 * V_2 , struct V_152 * V_153 )
{
struct V_94 * V_406 = (struct V_94 * ) & V_153 -> V_95 ;
if ( V_153 -> V_335 )
return 0 ;
if ( ( V_2 -> V_185 != V_153 -> V_185 ) || ( V_2 -> V_52 != V_153 -> V_52 ) )
return 0 ;
if ( ! F_115 ( F_116 ( V_2 ) , V_124 -> V_417 -> V_418 ) )
return 0 ;
if ( ! F_112 ( V_2 , V_406 ,
(struct V_94 * ) & V_153 -> V_381 ) )
return 0 ;
if ( ! F_110 ( V_2 , V_406 ) )
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
++ V_2 -> V_419 ;
F_3 ( & V_22 ) ;
F_4 ( V_20 , L_89 ) ;
return V_2 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
void
F_119 ( struct V_1 * V_2 , int V_420 )
{
struct V_122 * V_421 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_419 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_120 ( F_116 ( V_2 ) ) ;
F_15 ( & V_2 -> V_105 ) ;
F_3 ( & V_22 ) ;
F_121 ( & V_2 -> V_47 ) ;
if ( V_420 )
F_122 ( & V_2 -> V_422 ) ;
else
F_121 ( & V_2 -> V_422 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
F_10 ( V_2 -> V_34 . V_35 ) ;
V_2 -> V_34 . V_35 = NULL ;
V_2 -> V_34 . V_36 = 0 ;
V_421 = F_66 ( & V_2 -> V_137 , NULL ) ;
if ( V_421 )
F_125 ( V_423 , V_421 ) ;
}
static struct V_1 *
F_126 ( struct V_152 * V_424 )
{
struct V_1 * V_425 = NULL ;
int V_3 ;
F_4 ( V_20 , L_90 , V_424 -> V_208 ) ;
V_425 = F_117 ( V_424 ) ;
if ( V_425 )
return V_425 ;
V_425 = F_102 ( sizeof( struct V_1 ) , V_145 ) ;
if ( ! V_425 ) {
V_3 = - V_146 ;
goto V_426;
}
V_425 -> V_52 = V_424 -> V_52 ;
V_425 -> V_185 = V_424 -> V_185 ;
F_127 ( V_425 , F_128 ( V_124 -> V_417 -> V_418 ) ) ;
V_425 -> V_57 = F_71 ( V_424 -> V_208 ) ;
if ( F_129 ( V_425 -> V_57 ) ) {
V_3 = F_130 ( V_425 -> V_57 ) ;
goto V_427;
}
V_425 -> V_262 = V_424 -> V_262 ;
V_425 -> V_264 = V_424 -> V_264 ;
V_425 -> V_428 = V_424 -> V_429 ;
V_425 -> V_430 = 0 ;
V_425 -> V_107 = 1 ;
F_131 ( & V_425 -> V_63 ) ;
F_131 ( & V_425 -> V_108 ) ;
F_11 ( & V_425 -> V_109 ) ;
F_132 ( & V_425 -> V_27 ) ;
memcpy ( V_425 -> V_431 ,
V_424 -> V_230 , V_386 ) ;
memcpy ( V_425 -> V_432 ,
V_424 -> V_232 , V_386 ) ;
V_425 -> V_33 = false ;
V_425 -> V_32 = 0 ;
V_425 -> V_37 = V_38 ;
F_133 ( & V_425 -> V_106 ) ;
F_11 ( & V_425 -> V_105 ) ;
F_11 ( & V_425 -> V_23 ) ;
F_134 ( & V_425 -> V_47 , F_21 ) ;
F_134 ( & V_425 -> V_422 , V_433 ) ;
F_132 ( & V_425 -> V_434 ) ;
memcpy ( & V_425 -> V_381 , & V_424 -> V_381 ,
sizeof( V_425 -> V_381 ) ) ;
memcpy ( & V_425 -> V_95 , & V_424 -> V_95 ,
sizeof( V_425 -> V_95 ) ) ;
F_135 ( V_425 -> V_435 ) ;
V_425 -> V_15 = V_51 ;
++ V_425 -> V_419 ;
if ( V_424 -> V_50 >= V_436 &&
V_424 -> V_50 <= V_437 )
V_425 -> V_50 = V_424 -> V_50 * V_54 ;
else
V_425 -> V_50 = V_246 * V_54 ;
V_3 = F_136 ( V_425 ) ;
if ( V_3 < 0 ) {
F_4 ( V_59 , L_91 ) ;
goto V_427;
}
F_137 ( V_438 ) ;
V_425 -> V_137 = F_138 ( F_57 ,
V_425 , L_92 ) ;
if ( F_129 ( V_425 -> V_137 ) ) {
V_3 = F_130 ( V_425 -> V_137 ) ;
F_4 ( V_59 , L_93 , V_3 ) ;
F_139 ( V_438 ) ;
goto V_427;
}
V_425 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_140 ( & V_425 -> V_105 , & V_439 ) ;
F_3 ( & V_22 ) ;
F_141 ( V_425 ) ;
F_24 ( V_46 , & V_425 -> V_47 , V_425 -> V_50 ) ;
return V_425 ;
V_427:
F_123 ( V_425 ) ;
F_120 ( F_116 ( V_425 ) ) ;
V_426:
if ( V_425 ) {
if ( ! F_129 ( V_425 -> V_57 ) )
F_10 ( V_425 -> V_57 ) ;
if ( V_425 -> V_28 )
F_9 ( V_425 -> V_28 ) ;
F_10 ( V_425 ) ;
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
if ( ! F_143 ( V_153 -> V_233 , V_8 -> V_233 ) )
return 0 ;
break;
default:
if ( V_8 -> V_440 == NULL ) {
if ( ! V_153 -> V_175 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_440 ,
V_153 -> V_368 ? V_153 -> V_368 : L_94 ,
V_371 ) )
return 0 ;
if ( ( V_153 -> V_368 && strlen ( V_153 -> V_368 ) != 0 ) &&
V_8 -> V_373 != NULL &&
strncmp ( V_8 -> V_373 ,
V_153 -> V_373 ? V_153 -> V_373 : L_94 ,
V_441 ) )
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
if ( V_8 -> V_442 == V_16 )
continue;
if ( ! F_142 ( V_8 , V_153 ) )
continue;
++ V_8 -> V_443 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_145 ( struct V_7 * V_8 )
{
unsigned int V_3 , V_444 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_4 ( V_20 , L_95 , V_21 , V_8 -> V_443 ) ;
F_2 ( & V_22 ) ;
if ( V_8 -> V_442 == V_16 ) {
F_3 ( & V_22 ) ;
return;
}
if ( -- V_8 -> V_443 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
if ( V_8 -> V_442 == V_62 )
V_8 -> V_442 = V_16 ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_442 == V_16 && V_2 -> V_52 -> V_445 ) {
V_444 = F_146 () ;
V_3 = V_2 -> V_52 -> V_445 ( V_444 , V_8 ) ;
if ( V_3 )
F_4 ( V_59 , L_96 ,
V_21 , V_3 ) ;
F_147 ( V_444 ) ;
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
const char * V_143 , * V_446 ;
char * V_447 ;
T_6 V_36 ;
struct V_448 * V_448 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_396 * V_449 ;
struct V_402 * V_450 ;
const struct V_451 * V_452 ;
V_447 = F_73 ( V_453 , V_145 ) ;
if ( ! V_447 )
return - V_146 ;
switch ( V_2 -> V_95 . V_454 ) {
case V_395 :
V_449 = (struct V_396 * ) & V_2 -> V_95 ;
sprintf ( V_447 , L_97 , & V_449 -> V_399 . V_400 ) ;
break;
case V_401 :
V_450 = (struct V_402 * ) & V_2 -> V_95 ;
sprintf ( V_447 , L_98 , & V_450 -> V_405 . V_455 ) ;
break;
default:
F_4 ( V_20 , L_99 ,
V_2 -> V_95 . V_454 ) ;
V_3 = - V_144 ;
goto V_426;
}
F_4 ( V_20 , L_100 , V_21 , V_447 ) ;
V_448 = F_150 ( & V_456 , V_447 , L_94 ) ;
if ( F_129 ( V_448 ) ) {
if ( ! V_8 -> V_457 ) {
F_4 ( V_20 , L_101 ) ;
V_3 = F_130 ( V_448 ) ;
goto V_426;
}
sprintf ( V_447 , L_102 , V_8 -> V_457 ) ;
F_4 ( V_20 , L_100 , V_21 , V_447 ) ;
V_448 = F_150 ( & V_456 , V_447 , L_94 ) ;
if ( F_129 ( V_448 ) ) {
V_3 = F_130 ( V_448 ) ;
goto V_426;
}
}
F_151 ( & V_448 -> V_458 ) ;
V_452 = F_152 ( V_448 ) ;
if ( F_153 ( V_452 ) ) {
V_3 = V_452 ? F_130 ( V_452 ) : - V_144 ;
goto V_459;
}
V_446 = V_452 -> V_211 ;
V_143 = F_154 ( V_446 , V_452 -> V_460 , ':' ) ;
F_4 ( V_20 , L_103 , V_446 ) ;
if ( ! V_143 ) {
F_4 ( V_20 , L_104 ,
V_452 -> V_460 ) ;
V_3 = - V_144 ;
goto V_459;
}
V_36 = V_143 - V_446 ;
if ( V_36 > V_371 || V_36 <= 0 ) {
F_4 ( V_20 , L_105 ,
V_36 ) ;
V_3 = - V_144 ;
goto V_459;
}
V_153 -> V_368 = F_91 ( V_446 , V_36 , V_145 ) ;
if ( ! V_153 -> V_368 ) {
F_4 ( V_20 , L_106 ,
V_36 ) ;
V_3 = - V_146 ;
goto V_459;
}
F_4 ( V_20 , L_107 , V_21 , V_153 -> V_368 ) ;
V_36 = V_448 -> V_460 - ( V_36 + 1 ) ;
if ( V_36 > V_441 || V_36 <= 0 ) {
F_4 ( V_20 , L_108 , V_36 ) ;
V_3 = - V_144 ;
F_10 ( V_153 -> V_368 ) ;
V_153 -> V_368 = NULL ;
goto V_459;
}
++ V_143 ;
V_153 -> V_373 = F_91 ( V_143 , V_36 , V_145 ) ;
if ( ! V_153 -> V_373 ) {
F_4 ( V_20 , L_109 ,
V_36 ) ;
V_3 = - V_146 ;
F_10 ( V_153 -> V_368 ) ;
V_153 -> V_368 = NULL ;
goto V_459;
}
V_459:
F_155 ( & V_448 -> V_458 ) ;
F_156 ( V_448 ) ;
V_426:
F_10 ( V_447 ) ;
F_4 ( V_20 , L_110 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_157 ( struct V_1 * V_2 , struct V_152 * V_424 )
{
int V_3 = - V_146 ;
unsigned int V_444 ;
struct V_7 * V_8 ;
struct V_396 * V_406 = (struct V_396 * ) & V_2 -> V_95 ;
struct V_402 * V_413 = (struct V_402 * ) & V_2 -> V_95 ;
V_444 = F_146 () ;
V_8 = F_144 ( V_2 , V_424 ) ;
if ( V_8 ) {
F_4 ( V_20 , L_111 ,
V_8 -> V_442 ) ;
F_7 ( & V_8 -> V_461 ) ;
V_3 = F_158 ( V_444 , V_8 ) ;
if ( V_3 ) {
F_14 ( & V_8 -> V_461 ) ;
F_145 ( V_8 ) ;
F_159 ( V_444 ) ;
return F_72 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_4 ( V_20 , L_112 ) ;
V_3 = F_160 ( V_444 , V_8 ,
V_424 -> V_462 ) ;
if ( V_3 ) {
F_14 ( & V_8 -> V_461 ) ;
F_145 ( V_8 ) ;
F_159 ( V_444 ) ;
return F_72 ( V_3 ) ;
}
}
F_14 ( & V_8 -> V_461 ) ;
F_119 ( V_2 , 0 ) ;
F_159 ( V_444 ) ;
return V_8 ;
}
F_4 ( V_20 , L_113 ) ;
V_8 = F_161 () ;
if ( V_8 == NULL )
goto V_463;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_95 . V_454 == V_401 )
sprintf ( V_8 -> V_464 , L_114 , & V_413 -> V_405 ) ;
else
sprintf ( V_8 -> V_464 , L_115 , & V_406 -> V_399 ) ;
if ( V_424 -> V_368 ) {
V_8 -> V_440 = F_93 ( V_424 -> V_368 , V_145 ) ;
if ( ! V_8 -> V_440 )
goto V_463;
}
if ( V_424 -> V_373 ) {
V_8 -> V_373 = F_93 ( V_424 -> V_373 , V_145 ) ;
if ( ! V_8 -> V_373 )
goto V_463;
}
if ( V_424 -> V_379 ) {
V_8 -> V_457 = F_93 ( V_424 -> V_379 , V_145 ) ;
if ( ! V_8 -> V_457 )
goto V_463;
}
if ( V_424 -> V_344 )
V_8 -> V_465 = V_424 -> V_344 ;
V_8 -> V_233 = V_424 -> V_233 ;
V_8 -> V_234 = V_424 -> V_234 ;
V_8 -> V_155 = V_424 -> V_155 ;
V_8 -> V_157 = V_424 -> V_157 ;
F_7 ( & V_8 -> V_461 ) ;
V_3 = F_158 ( V_444 , V_8 ) ;
if ( ! V_3 )
V_3 = F_160 ( V_444 , V_8 , V_424 -> V_462 ) ;
F_14 ( & V_8 -> V_461 ) ;
if ( V_3 )
goto V_463;
F_2 ( & V_22 ) ;
F_140 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_159 ( V_444 ) ;
return V_8 ;
V_463:
F_148 ( V_8 ) ;
F_159 ( V_444 ) ;
return F_72 ( V_3 ) ;
}
static int F_162 ( struct V_9 * V_10 , struct V_152 * V_424 )
{
if ( V_10 -> V_466 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_467 , V_424 -> V_208 , V_468 ) )
return 0 ;
if ( V_10 -> V_325 != V_424 -> V_325 )
return 0 ;
if ( V_10 -> V_364 != V_424 -> V_364 )
return 0 ;
return 1 ;
}
static struct V_9 *
F_163 ( struct V_7 * V_8 , struct V_152 * V_424 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_22 ) ;
F_5 (tmp, &ses->tcon_list) {
V_10 = F_6 ( V_5 , struct V_9 , V_26 ) ;
if ( ! F_162 ( V_10 , V_424 ) )
continue;
++ V_10 -> V_469 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
void
F_164 ( struct V_9 * V_10 )
{
unsigned int V_444 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_4 ( V_20 , L_116 , V_21 , V_10 -> V_469 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_469 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_15 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_444 = F_146 () ;
if ( V_8 -> V_2 -> V_52 -> V_470 )
V_8 -> V_2 -> V_52 -> V_470 ( V_444 , V_10 ) ;
F_147 ( V_444 ) ;
F_165 ( V_10 ) ;
F_166 ( V_10 ) ;
F_145 ( V_8 ) ;
}
static struct V_9 *
F_167 ( struct V_7 * V_8 , struct V_152 * V_424 )
{
int V_3 , V_444 ;
struct V_9 * V_10 ;
V_10 = F_163 ( V_8 , V_424 ) ;
if ( V_10 ) {
F_4 ( V_20 , L_117 ) ;
F_145 ( V_8 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_52 -> V_471 ) {
V_3 = - V_56 ;
goto V_472;
}
V_10 = F_168 () ;
if ( V_10 == NULL ) {
V_3 = - V_146 ;
goto V_472;
}
if ( V_424 -> V_364 ) {
if ( V_8 -> V_2 -> V_185 -> V_473 == 0 ) {
F_4 ( V_59 ,
L_118 ) ;
V_3 = - V_474 ;
goto V_472;
} else
V_10 -> V_364 = V_424 -> V_364 ;
}
V_10 -> V_8 = V_8 ;
if ( V_424 -> V_373 ) {
V_10 -> V_373 = F_93 ( V_424 -> V_373 , V_145 ) ;
if ( ! V_10 -> V_373 ) {
V_3 = - V_146 ;
goto V_472;
}
}
V_444 = F_146 () ;
V_3 = V_8 -> V_2 -> V_52 -> V_471 ( V_444 , V_8 , V_424 -> V_208 , V_10 ,
V_424 -> V_462 ) ;
F_159 ( V_444 ) ;
F_4 ( V_20 , L_119 , V_3 ) ;
if ( V_3 )
goto V_472;
if ( V_424 -> V_280 ) {
V_10 -> V_475 &= ~ V_476 ;
F_4 ( V_20 , L_120 , V_10 -> V_475 ) ;
}
V_10 -> V_477 = false ;
if ( V_424 -> V_338 ) {
if ( V_8 -> V_2 -> V_185 -> V_473 == 0 ) {
F_4 ( V_59 ,
L_121 ) ;
V_3 = - V_474 ;
goto V_472;
} else if ( V_8 -> V_2 -> V_478 &
V_479 )
V_10 -> V_477 = true ;
else {
F_4 ( V_59 ,
L_122 ) ;
V_3 = - V_474 ;
goto V_472;
}
} else if ( ( V_10 -> V_478 & V_480 )
&& ( V_8 -> V_2 -> V_478 & V_479 )
&& ( V_424 -> V_337 == false ) ) {
F_4 ( V_20 , L_123 ) ;
V_10 -> V_477 = true ;
} else if ( V_424 -> V_340 ) {
if ( V_8 -> V_2 -> V_185 -> V_473 == 0 ) {
F_4 ( V_59 ,
L_124 ) ;
V_3 = - V_474 ;
goto V_472;
}
V_10 -> V_481 = true ;
}
if ( V_424 -> V_325 ) {
if ( V_8 -> V_2 -> V_185 -> V_473 == 0 ) {
F_4 ( V_59 ,
L_125 ) ;
V_3 = - V_474 ;
goto V_472;
} else if ( V_10 -> V_8 -> V_2 -> V_478 &
V_482 )
V_10 -> V_325 = true ;
else {
F_4 ( V_59 , L_126 ) ;
V_3 = - V_474 ;
goto V_472;
}
}
V_10 -> V_266 = V_424 -> V_266 ;
V_10 -> V_286 = V_424 -> V_286 ;
V_10 -> V_322 = V_424 -> V_322 ;
F_11 ( & V_10 -> V_483 ) ;
F_2 ( & V_22 ) ;
F_140 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_169 ( V_10 ) ;
return V_10 ;
V_472:
F_166 ( V_10 ) ;
return F_72 ( V_3 ) ;
}
void
F_170 ( struct V_484 * V_485 )
{
if ( ! V_485 || F_129 ( V_485 ) )
return;
if ( ! F_171 ( & V_485 -> V_486 ) ||
F_172 ( V_487 , & V_485 -> V_488 ) ) {
V_485 -> V_489 = V_38 ;
return;
}
if ( ! F_129 ( F_173 ( V_485 ) ) )
F_164 ( F_173 ( V_485 ) ) ;
F_10 ( V_485 ) ;
return;
}
static inline struct V_484 *
F_174 ( struct V_490 * V_491 )
{
return V_491 -> V_492 ;
}
static int
F_175 ( struct V_493 * V_494 , struct V_495 * V_496 )
{
struct V_490 * V_497 = F_176 ( V_494 ) ;
struct V_490 * V_498 = V_496 -> V_491 ;
if ( ( V_494 -> V_499 & V_500 ) != ( V_496 -> V_30 & V_500 ) )
return 0 ;
if ( ( V_497 -> V_501 & V_502 ) !=
( V_498 -> V_501 & V_502 ) )
return 0 ;
if ( V_498 -> V_359 && V_498 -> V_359 < V_497 -> V_359 )
return 0 ;
if ( V_498 -> V_357 && V_498 -> V_357 < V_497 -> V_357 )
return 0 ;
if ( ! F_143 ( V_497 -> V_503 , V_498 -> V_503 ) || ! F_177 ( V_497 -> V_504 , V_498 -> V_504 ) )
return 0 ;
if ( V_497 -> V_505 != V_498 -> V_505 ||
V_497 -> V_506 != V_498 -> V_506 )
return 0 ;
if ( strcmp ( V_497 -> V_462 -> V_507 , V_498 -> V_462 -> V_507 ) )
return 0 ;
if ( V_497 -> V_244 != V_498 -> V_244 )
return 0 ;
return 1 ;
}
static int
F_178 ( struct V_493 * V_494 , struct V_495 * V_496 )
{
struct V_490 * V_497 = F_176 ( V_494 ) ;
struct V_490 * V_498 = V_496 -> V_491 ;
bool V_508 = V_497 -> V_501 & V_509 ;
bool V_510 = V_498 -> V_501 & V_509 ;
if ( V_508 && V_510 && ! strcmp ( V_498 -> V_209 , V_497 -> V_209 ) )
return 1 ;
else if ( ! V_508 && ! V_510 )
return 1 ;
return 0 ;
}
int
F_179 ( struct V_493 * V_494 , void * V_211 )
{
struct V_495 * V_496 = (struct V_495 * ) V_211 ;
struct V_152 * V_424 ;
struct V_490 * V_491 ;
struct V_1 * V_511 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_484 * V_485 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_491 = F_176 ( V_494 ) ;
V_485 = F_180 ( F_174 ( V_491 ) ) ;
if ( F_129 ( V_485 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_173 ( V_485 ) ;
V_8 = V_10 -> V_8 ;
V_511 = V_8 -> V_2 ;
V_424 = V_496 -> V_153 ;
if ( ! F_114 ( V_511 , V_424 ) ||
! F_142 ( V_8 , V_424 ) ||
! F_162 ( V_10 , V_424 ) ||
! F_178 ( V_494 , V_496 ) ) {
V_3 = 0 ;
goto V_512;
}
V_3 = F_175 ( V_494 , V_496 ) ;
V_512:
F_3 ( & V_22 ) ;
F_170 ( V_485 ) ;
return V_3 ;
}
int
F_181 ( const unsigned int V_444 , struct V_7 * V_8 , const char * V_513 ,
const struct V_514 * V_515 , unsigned int * V_516 ,
struct V_517 * * V_518 , int V_236 )
{
char * V_519 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_52 -> V_471 || ! V_8 -> V_2 -> V_52 -> V_520 )
return - V_56 ;
* V_516 = 0 ;
* V_518 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_519 = F_73 ( 2 +
F_96 ( V_8 -> V_464 , V_521 * 2 )
+ 1 + 4 + 2 , V_145 ) ;
if ( V_519 == NULL )
return - V_146 ;
V_519 [ 0 ] = '\\' ;
V_519 [ 1 ] = '\\' ;
strcpy ( V_519 + 2 , V_8 -> V_464 ) ;
strcpy ( V_519 + 2 + strlen ( V_8 -> V_464 ) , L_127 ) ;
V_3 = V_8 -> V_2 -> V_52 -> V_471 ( V_444 , V_8 , V_519 , NULL ,
V_515 ) ;
F_4 ( V_20 , L_128 , V_3 , V_8 -> V_25 ) ;
F_10 ( V_519 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_52 -> V_520 ( V_444 , V_8 , V_513 ,
V_518 , V_516 ,
V_515 , V_236 ) ;
return V_3 ;
}
static inline void
F_182 ( struct V_522 * V_523 )
{
struct V_523 * V_524 = V_523 -> V_524 ;
F_183 ( ! F_184 ( V_524 ) ) ;
F_185 ( V_524 , L_129 ,
& V_525 [ 0 ] , L_130 , & V_526 [ 0 ] ) ;
}
static inline void
F_186 ( struct V_522 * V_523 )
{
struct V_523 * V_524 = V_523 -> V_524 ;
F_183 ( ! F_184 ( V_524 ) ) ;
F_185 ( V_524 , L_131 ,
& V_525 [ 1 ] , L_132 , & V_526 [ 1 ] ) ;
}
static inline void
F_182 ( struct V_522 * V_523 )
{
}
static inline void
F_186 ( struct V_522 * V_523 )
{
}
static void F_187 ( char * V_527 , char * V_528 , unsigned int V_66 )
{
unsigned int V_216 , V_217 ;
for ( V_216 = 0 , V_217 = 0 ; V_216 < ( V_66 ) ; V_216 ++ ) {
V_527 [ V_217 ] = 'A' + ( 0x0F & ( V_528 [ V_216 ] >> 4 ) ) ;
V_527 [ V_217 + 1 ] = 'A' + ( 0x0F & V_528 [ V_216 ] ) ;
V_217 += 2 ;
}
}
static int
F_188 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_381 . V_454 != V_394 ) {
struct V_522 * V_522 = V_2 -> V_28 ;
V_3 = V_522 -> V_52 -> V_529 ( V_522 ,
(struct V_94 * ) & V_2 -> V_381 ,
sizeof( V_2 -> V_381 ) ) ;
if ( V_3 < 0 ) {
struct V_396 * V_397 ;
struct V_402 * V_403 ;
V_397 = (struct V_396 * ) & V_2 -> V_381 ;
V_403 = (struct V_402 * ) & V_2 -> V_381 ;
if ( V_403 -> V_530 == V_401 )
F_4 ( V_59 , L_133 ,
& V_403 -> V_405 , V_3 ) ;
else
F_4 ( V_59 , L_134 ,
& V_397 -> V_399 . V_400 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_189 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_531 * V_532 ;
struct V_533 * V_534 ;
V_532 = F_102 ( sizeof( struct V_531 ) ,
V_145 ) ;
if ( V_532 ) {
V_532 -> V_535 . V_536 . V_537 = 32 ;
if ( V_2 -> V_432 [ 0 ] != 0 )
F_187 ( V_532 -> V_535 .
V_536 . V_538 ,
V_2 -> V_432 ,
V_386 ) ;
else
F_187 ( V_532 -> V_535 .
V_536 . V_538 ,
V_539 ,
V_386 ) ;
V_532 -> V_535 . V_536 . V_540 = 32 ;
if ( V_2 -> V_431 [ 0 ] != 0 )
F_187 ( V_532 -> V_535 .
V_536 . V_541 ,
V_2 -> V_431 ,
V_386 ) ;
else
F_187 ( V_532 -> V_535 .
V_536 . V_541 ,
L_135 ,
V_386 ) ;
V_532 -> V_535 . V_536 . V_542 = 0 ;
V_532 -> V_535 . V_536 . V_543 = 0 ;
V_534 = (struct V_533 * ) V_532 ;
V_534 -> V_544 = F_190 ( 0x81000044 ) ;
V_3 = F_191 ( V_2 , V_534 , 0x44 ) ;
F_10 ( V_532 ) ;
F_35 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_407 ;
int V_545 , V_546 ;
struct V_522 * V_522 = V_2 -> V_28 ;
struct V_94 * V_547 ;
V_547 = (struct V_94 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_454 == V_401 ) {
V_407 = ( (struct V_402 * ) V_547 ) -> V_409 ;
V_545 = sizeof( struct V_402 ) ;
V_546 = V_401 ;
} else {
V_407 = ( (struct V_396 * ) V_547 ) -> V_408 ;
V_545 = sizeof( struct V_396 ) ;
V_546 = V_395 ;
}
if ( V_522 == NULL ) {
V_3 = F_192 ( F_116 ( V_2 ) , V_546 , V_548 ,
V_549 , & V_522 , 1 ) ;
if ( V_3 < 0 ) {
F_4 ( V_59 , L_136 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_4 ( V_20 , L_137 ) ;
V_2 -> V_28 = V_522 ;
V_522 -> V_524 -> V_550 = V_551 ;
if ( V_546 == V_401 )
F_186 ( V_522 ) ;
else
F_182 ( V_522 ) ;
}
V_3 = F_188 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_522 -> V_524 -> V_552 = 7 * V_54 ;
V_522 -> V_524 -> V_553 = 5 * V_54 ;
if ( V_2 -> V_264 ) {
if ( V_522 -> V_524 -> V_554 < ( 200 * 1024 ) )
V_522 -> V_524 -> V_554 = 200 * 1024 ;
if ( V_522 -> V_524 -> V_555 < ( 140 * 1024 ) )
V_522 -> V_524 -> V_555 = 140 * 1024 ;
}
if ( V_2 -> V_428 ) {
int V_556 = 1 ;
V_3 = F_193 ( V_522 , V_557 , V_558 ,
( char * ) & V_556 , sizeof( V_556 ) ) ;
if ( V_3 )
F_4 ( V_20 , L_138 ,
V_3 ) ;
}
F_4 ( V_20 , L_139 ,
V_522 -> V_524 -> V_554 ,
V_522 -> V_524 -> V_555 , V_522 -> V_524 -> V_552 ) ;
V_3 = V_522 -> V_52 -> V_559 ( V_522 , V_547 , V_545 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( V_20 , L_140 , V_3 ) ;
F_9 ( V_522 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_407 == F_111 ( V_410 ) )
V_3 = F_189 ( V_2 ) ;
return V_3 ;
}
static int
F_136 ( struct V_1 * V_2 )
{
T_5 * V_407 ;
struct V_402 * V_413 = (struct V_402 * ) & V_2 -> V_95 ;
struct V_396 * V_406 = (struct V_396 * ) & V_2 -> V_95 ;
if ( V_2 -> V_95 . V_454 == V_401 )
V_407 = & V_413 -> V_409 ;
else
V_407 = & V_406 -> V_408 ;
if ( * V_407 == 0 ) {
int V_3 ;
* V_407 = F_111 ( V_96 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_407 = F_111 ( V_410 ) ;
}
return F_17 ( V_2 ) ;
}
void F_194 ( unsigned int V_444 , struct V_9 * V_10 ,
struct V_490 * V_491 , struct V_152 * V_560 )
{
T_7 V_561 = F_195 ( V_10 -> V_562 . V_563 ) ;
if ( V_560 && V_560 -> V_284 ) {
V_10 -> V_562 . V_563 = 0 ;
V_10 -> V_564 = 0 ;
F_4 ( V_20 , L_141 ) ;
return;
} else if ( V_560 )
V_10 -> V_564 = 1 ;
if ( V_10 -> V_564 == 0 ) {
F_4 ( V_20 , L_142 ) ;
return;
}
if ( ! F_196 ( V_444 , V_10 ) ) {
T_7 V_565 = F_195 ( V_10 -> V_562 . V_563 ) ;
F_4 ( V_20 , L_143 , V_565 ) ;
if ( V_560 == NULL ) {
if ( ( V_561 & V_566 ) == 0 )
V_565 &= ~ V_566 ;
if ( ( V_561 & V_567 ) == 0 ) {
if ( V_565 & V_567 )
F_4 ( V_59 , L_144 ) ;
V_565 &= ~ V_567 ;
} else if ( ( V_565 & V_567 ) == 0 ) {
F_4 ( V_59 , L_145 ) ;
F_4 ( V_59 , L_146 ) ;
}
}
if ( V_565 & V_568 )
F_4 ( V_59 , L_147 ) ;
V_565 &= V_569 ;
if ( V_560 && V_560 -> V_319 )
V_565 &= ~ V_566 ;
else if ( V_566 & V_565 ) {
F_4 ( V_20 , L_148 ) ;
if ( V_491 )
V_491 -> V_501 |=
V_570 ;
}
if ( V_560 && V_560 -> V_242 == 0 )
V_565 &= ~ V_567 ;
else if ( V_565 & V_567 ) {
F_4 ( V_20 , L_149 ) ;
if ( V_491 )
V_491 -> V_501 |=
V_571 ;
}
F_4 ( V_20 , L_150 , ( int ) V_565 ) ;
#ifdef F_62
if ( V_565 & V_572 )
F_4 ( V_20 , L_151 ) ;
if ( V_565 & V_573 )
F_4 ( V_20 , L_152 ) ;
if ( V_565 & V_567 )
F_4 ( V_20 , L_153 ) ;
if ( V_565 & V_574 )
F_4 ( V_20 , L_154 ) ;
if ( V_565 & V_566 )
F_4 ( V_20 , L_155 ) ;
if ( V_565 & V_575 )
F_4 ( V_20 , L_156 ) ;
if ( V_565 & V_576 )
F_4 ( V_20 , L_157 ) ;
if ( V_565 & V_577 )
F_4 ( V_20 , L_158 ) ;
if ( V_565 & V_568 )
F_4 ( V_20 , L_159 ) ;
#endif
if ( F_197 ( V_444 , V_10 , V_565 ) ) {
if ( V_560 == NULL ) {
F_4 ( V_20 , L_160 ) ;
} else
F_4 ( V_59 , L_161 ) ;
}
}
}
int F_198 ( struct V_152 * V_578 ,
struct V_490 * V_491 )
{
F_134 ( & V_491 -> V_579 , V_580 ) ;
F_133 ( & V_491 -> V_581 ) ;
V_491 -> V_582 = V_583 ;
V_491 -> V_357 = V_578 -> V_357 ;
V_491 -> V_359 = V_578 -> V_359 ;
V_491 -> V_503 = V_578 -> V_234 ;
V_491 -> V_504 = V_578 -> V_235 ;
V_491 -> V_505 = V_578 -> V_238 ;
V_491 -> V_506 = V_578 -> V_237 ;
F_4 ( V_20 , L_162 ,
V_491 -> V_505 , V_491 -> V_506 ) ;
V_491 -> V_244 = V_578 -> V_244 ;
V_491 -> V_462 = V_578 -> V_462 ;
if ( V_578 -> V_269 )
V_491 -> V_501 |= V_584 ;
if ( V_578 -> V_296 )
V_491 -> V_501 |= V_585 ;
if ( V_578 -> V_299 )
V_491 -> V_501 |= V_586 ;
if ( V_578 -> V_243 )
V_491 -> V_501 |= V_587 ;
if ( V_578 -> V_236 )
V_491 -> V_501 |= V_588 ;
if ( V_578 -> V_272 )
V_491 -> V_501 |= V_589 ;
if ( V_578 -> V_255 )
V_491 -> V_501 |= V_590 ;
if ( V_578 -> V_277 )
V_491 -> V_501 |= V_591 ;
if ( V_578 -> V_288 )
V_491 -> V_501 |= V_592 ;
if ( V_578 -> V_309 )
V_491 -> V_501 |= V_593 ;
if ( V_578 -> V_294 )
V_491 -> V_501 |= V_594 ;
if ( V_578 -> V_314 )
V_491 -> V_501 |= V_595 ;
if ( V_578 -> V_316 )
V_491 -> V_501 |= V_596 ;
if ( V_578 -> V_249 ) {
V_491 -> V_501 |= V_597 ;
V_491 -> V_598 = V_578 -> V_346 ;
}
if ( V_578 -> V_250 ) {
V_491 -> V_501 |= V_599 ;
V_491 -> V_600 = V_578 -> V_348 ;
}
if ( V_578 -> V_219 )
V_491 -> V_501 |= V_601 ;
if ( V_578 -> V_220 )
V_491 -> V_501 |= V_602 ;
if ( V_578 -> V_301 )
V_491 -> V_501 |= V_603 ;
if ( V_578 -> V_328 )
V_491 -> V_501 |= V_604 ;
if ( V_578 -> V_332 )
V_491 -> V_501 |= ( V_605 |
V_584 ) ;
if ( V_578 -> V_179 )
V_491 -> V_501 |= V_606 ;
if ( V_578 -> V_178 ) {
F_4 ( V_20 , L_163 ) ;
V_491 -> V_501 |= V_607 ;
}
if ( V_578 -> V_330 ) {
if ( V_578 -> V_277 ) {
F_4 ( V_59 , L_164 ) ;
}
V_491 -> V_501 |= V_608 ;
}
if ( ( V_578 -> V_316 ) && ( V_578 -> V_301 ) )
F_4 ( V_59 , L_165 ) ;
if ( V_578 -> V_209 ) {
V_491 -> V_209 = F_93 ( V_578 -> V_209 , V_145 ) ;
if ( V_491 -> V_209 == NULL )
return - V_146 ;
}
return 0 ;
}
static void
F_199 ( struct V_152 * V_424 )
{
F_10 ( V_424 -> V_368 ) ;
F_200 ( V_424 -> V_373 ) ;
F_10 ( V_424 -> V_208 ) ;
F_10 ( V_424 -> V_379 ) ;
F_10 ( V_424 -> V_383 ) ;
F_10 ( V_424 -> V_209 ) ;
}
void
F_201 ( struct V_152 * V_424 )
{
if ( ! V_424 )
return;
F_199 ( V_424 ) ;
F_10 ( V_424 ) ;
}
static char *
F_202 ( const struct V_152 * V_153 ,
const struct V_490 * V_491 )
{
char * V_609 , * V_206 ;
unsigned int V_610 = V_153 -> V_209 ? strlen ( V_153 -> V_209 ) + 1 : 0 ;
unsigned int V_611 = F_96 ( V_153 -> V_208 , V_468 + 1 ) ;
V_609 = F_73 ( V_611 + V_610 + 1 , V_145 ) ;
if ( V_609 == NULL )
return F_72 ( - V_146 ) ;
strncpy ( V_609 , V_153 -> V_208 , V_611 ) ;
V_206 = V_609 + V_611 ;
if ( V_610 ) {
* V_206 = F_203 ( V_491 ) ;
strncpy ( V_206 + 1 , V_153 -> V_209 , V_610 ) ;
V_206 += V_610 ;
}
* V_206 = '\0' ;
F_92 ( V_609 , F_203 ( V_491 ) ) ;
F_4 ( V_20 , L_166 , V_21 , V_609 ) ;
return V_609 ;
}
static int
F_204 ( const unsigned int V_444 , struct V_7 * V_8 ,
struct V_152 * V_424 , struct V_490 * V_491 ,
int V_612 )
{
int V_3 ;
unsigned int V_516 = 0 ;
struct V_517 * V_518 = NULL ;
char * V_609 = NULL , * V_613 = NULL , * V_614 = NULL ;
V_609 = F_202 ( V_424 , V_491 ) ;
if ( F_129 ( V_609 ) )
return F_130 ( V_609 ) ;
V_613 = V_612 ? V_609 + 1 : V_424 -> V_208 + 1 ;
V_3 = F_181 ( V_444 , V_8 , V_613 , V_491 -> V_462 ,
& V_516 , & V_518 , F_205 ( V_491 ) ) ;
if ( ! V_3 && V_516 > 0 ) {
char * V_615 = NULL ;
V_614 = F_206 ( V_491 -> V_210 ,
V_609 + 1 , V_518 ,
& V_615 ) ;
F_207 ( V_518 , V_516 ) ;
if ( F_129 ( V_614 ) ) {
V_3 = F_130 ( V_614 ) ;
V_614 = NULL ;
} else {
F_199 ( V_424 ) ;
V_3 = F_208 ( V_424 , V_614 ,
V_615 ) ;
}
F_10 ( V_615 ) ;
F_10 ( V_491 -> V_210 ) ;
V_491 -> V_210 = V_614 ;
}
F_10 ( V_609 ) ;
return V_3 ;
}
static int
F_208 ( struct V_152 * V_424 , char * V_616 ,
const char * V_205 )
{
int V_3 = 0 ;
if ( F_94 ( V_616 , V_205 , V_424 ) )
return - V_144 ;
if ( V_424 -> V_175 ) {
F_4 ( V_20 , L_167 ) ;
F_10 ( V_424 -> V_368 ) ;
V_424 -> V_368 = NULL ;
} else if ( V_424 -> V_368 ) {
F_4 ( V_20 , L_168 , V_424 -> V_368 ) ;
} else {
F_4 ( V_59 , L_169 ) ;
return - V_144 ;
}
if ( V_424 -> V_383 == NULL ) {
V_424 -> V_462 = F_209 () ;
} else {
V_424 -> V_462 = F_210 ( V_424 -> V_383 ) ;
if ( V_424 -> V_462 == NULL ) {
F_4 ( V_59 , L_170 ,
V_424 -> V_383 ) ;
return - V_617 ;
}
}
return V_3 ;
}
struct V_152 *
F_211 ( char * V_616 , const char * V_205 )
{
int V_3 ;
struct V_152 * V_424 ;
V_424 = F_73 ( sizeof( struct V_152 ) , V_145 ) ;
if ( ! V_424 )
return F_72 ( - V_146 ) ;
V_3 = F_208 ( V_424 , V_616 , V_205 ) ;
if ( V_3 ) {
F_201 ( V_424 ) ;
V_424 = F_72 ( V_3 ) ;
}
return V_424 ;
}
static int
F_212 ( struct V_1 * V_2 ,
unsigned int V_444 ,
struct V_9 * V_10 ,
struct V_490 * V_491 ,
char * V_609 )
{
int V_3 ;
char * V_618 ;
char V_619 , V_5 ;
V_619 = F_203 ( V_491 ) ;
V_618 = V_609 ;
V_3 = V_2 -> V_52 -> V_620 ( V_444 , V_10 , V_491 , L_94 ) ;
while ( V_3 == 0 ) {
while ( * V_618 == V_619 )
V_618 ++ ;
if ( ! * V_618 )
break;
while ( * V_618 && * V_618 != V_619 )
V_618 ++ ;
V_5 = * V_618 ;
* V_618 = 0 ;
V_3 = V_2 -> V_52 -> V_620 ( V_444 , V_10 , V_491 ,
V_609 ) ;
* V_618 = V_5 ;
}
return V_3 ;
}
int
F_213 ( struct V_490 * V_491 , struct V_152 * V_424 )
{
int V_3 ;
unsigned int V_444 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_609 ;
struct V_484 * V_485 ;
#ifdef F_214
int V_621 = 0 ;
#endif
#ifdef F_214
V_622:
if ( V_621 ) {
if ( V_10 )
F_164 ( V_10 ) ;
else if ( V_8 )
F_145 ( V_8 ) ;
V_491 -> V_501 &= ~ V_571 ;
F_159 ( V_444 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_609 = NULL ;
V_485 = NULL ;
V_444 = F_146 () ;
V_2 = F_126 ( V_424 ) ;
if ( F_129 ( V_2 ) ) {
V_3 = F_130 ( V_2 ) ;
goto V_512;
}
if ( ( V_424 -> V_366 < 20 ) ||
( V_424 -> V_366 > 60000 ) )
V_2 -> V_366 = V_623 ;
else
V_2 -> V_366 = V_424 -> V_366 ;
V_8 = F_157 ( V_2 , V_424 ) ;
if ( F_129 ( V_8 ) ) {
V_3 = F_130 ( V_8 ) ;
V_8 = NULL ;
goto V_624;
}
if ( ( V_424 -> V_338 == true ) && ( ( V_8 -> V_2 -> V_478 &
V_479 ) == 0 ) ) {
F_4 ( V_59 , L_171 ) ;
V_3 = - V_474 ;
goto V_624;
}
V_10 = F_167 ( V_8 , V_424 ) ;
if ( F_129 ( V_10 ) ) {
V_3 = F_130 ( V_10 ) ;
V_10 = NULL ;
if ( V_3 == - V_625 )
goto V_624;
goto V_626;
}
if ( F_215 ( V_10 -> V_8 ) ) {
F_194 ( V_444 , V_10 , V_491 , V_424 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_195 ( V_10 -> V_562 . V_563 ) &
V_568 ) ) {
V_3 = - V_625 ;
goto V_624;
}
} else
V_10 -> V_564 = 0 ;
if ( ! V_10 -> V_627 && V_2 -> V_52 -> V_628 )
V_2 -> V_52 -> V_628 ( V_444 , V_10 ) ;
V_491 -> V_359 = V_2 -> V_52 -> V_629 ( V_10 , V_424 ) ;
V_491 -> V_357 = V_2 -> V_52 -> V_630 ( V_10 , V_424 ) ;
V_626:
#ifdef F_214
if ( V_621 == 0 ) {
int V_631 = F_204 ( V_444 , V_8 , V_424 , V_491 ,
false ) ;
if ( ! V_631 ) {
V_621 ++ ;
goto V_622;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_52 -> V_620 ) {
V_3 = - V_56 ;
goto V_624;
}
V_609 = F_216 ( V_424 , V_491 , V_10 ,
V_10 -> V_475 & V_476 ) ;
if ( V_609 == NULL ) {
V_3 = - V_146 ;
goto V_624;
}
V_3 = V_2 -> V_52 -> V_620 ( V_444 , V_10 , V_491 ,
V_609 ) ;
if ( V_3 != 0 && V_3 != - V_632 ) {
F_10 ( V_609 ) ;
goto V_624;
}
if ( V_3 != - V_632 ) {
V_3 = F_212 ( V_2 ,
V_444 , V_10 , V_491 ,
V_609 ) ;
if ( V_3 != 0 ) {
F_4 ( V_59 , L_172
L_173 ) ;
V_491 -> V_501 |= V_509 ;
V_3 = 0 ;
}
}
F_10 ( V_609 ) ;
}
if ( V_3 == - V_632 ) {
#ifdef F_214
if ( V_621 > V_633 ) {
V_3 = - V_634 ;
goto V_624;
}
V_3 = F_204 ( V_444 , V_8 , V_424 , V_491 , true ) ;
if ( ! V_3 ) {
V_621 ++ ;
goto V_622;
}
goto V_624;
#else
V_3 = - V_474 ;
#endif
}
if ( V_3 )
goto V_624;
V_485 = F_102 ( sizeof *V_485 , V_145 ) ;
if ( V_485 == NULL ) {
V_3 = - V_146 ;
goto V_624;
}
V_485 -> V_635 = V_8 -> V_234 ;
V_485 -> V_636 = V_10 ;
V_485 -> V_489 = V_38 ;
F_217 ( V_637 , & V_485 -> V_488 ) ;
F_217 ( V_487 , & V_485 -> V_488 ) ;
V_491 -> V_492 = V_485 ;
F_2 ( & V_491 -> V_581 ) ;
F_218 ( & V_491 -> V_582 , V_485 ) ;
F_3 ( & V_491 -> V_581 ) ;
F_24 ( V_46 , & V_491 -> V_579 ,
V_638 ) ;
V_624:
if ( V_3 ) {
if ( V_10 )
F_164 ( V_10 ) ;
else if ( V_8 )
F_145 ( V_8 ) ;
else
F_119 ( V_2 , 0 ) ;
}
V_512:
F_159 ( V_444 ) ;
return V_3 ;
}
int
F_219 ( const unsigned int V_444 , struct V_7 * V_8 ,
const char * V_639 , struct V_9 * V_10 ,
const struct V_514 * V_515 )
{
struct V_533 * V_640 ;
struct V_533 * V_641 ;
T_8 * V_642 ;
T_9 * V_643 ;
unsigned char * V_644 ;
int V_3 = 0 ;
int V_66 ;
T_10 V_645 , V_646 ;
if ( V_8 == NULL )
return - V_647 ;
V_640 = F_26 () ;
if ( V_640 == NULL )
return - V_146 ;
V_641 = V_640 ;
F_220 ( V_640 , V_648 ,
NULL , 4 ) ;
V_640 -> V_649 = F_221 ( V_8 -> V_2 ) ;
V_640 -> V_650 = V_8 -> V_651 ;
V_642 = ( T_8 * ) V_640 ;
V_643 = ( T_9 * ) V_641 ;
V_642 -> V_652 = 0xFF ;
V_642 -> V_475 = F_222 ( V_653 ) ;
V_644 = & V_642 -> V_654 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_655 & V_656 ) ) {
V_642 -> V_657 = F_222 ( 1 ) ;
* V_644 = 0 ;
V_644 ++ ;
} else {
V_642 -> V_657 = F_222 ( V_658 ) ;
#ifdef F_86
if ( ( V_659 & V_660 ) &&
( V_8 -> V_155 == V_173 ) )
F_223 ( V_10 -> V_373 , V_8 -> V_2 -> V_661 ,
V_8 -> V_2 -> V_655 &
V_662 ? true : false ,
V_644 ) ;
else
#endif
V_3 = F_224 ( V_10 -> V_373 , V_8 -> V_2 -> V_661 ,
V_644 , V_515 ) ;
if ( V_3 ) {
F_4 ( V_20 , L_174 ,
V_21 , V_3 ) ;
F_64 ( V_640 ) ;
return V_3 ;
}
V_644 += V_658 ;
if ( V_8 -> V_478 & V_663 ) {
* V_644 = 0 ;
V_644 ++ ;
}
}
if ( V_8 -> V_2 -> V_157 )
V_640 -> V_664 |= V_665 ;
if ( V_8 -> V_478 & V_666 ) {
V_640 -> V_664 |= V_667 ;
}
if ( V_8 -> V_478 & V_668 ) {
V_640 -> V_664 |= V_669 ;
}
if ( V_8 -> V_478 & V_663 ) {
V_640 -> V_664 |= V_670 ;
V_66 =
F_225 ( ( V_671 * ) V_644 , V_639 ,
6 *
( + 256 ) , V_515 ) ;
V_644 += 2 * V_66 ;
V_644 += 2 ;
} else {
strcpy ( V_644 , V_639 ) ;
V_644 += strlen ( V_639 ) + 1 ;
}
strcpy ( V_644 , L_175 ) ;
V_644 += strlen ( L_175 ) ;
V_644 += 1 ;
V_646 = V_644 - & V_642 -> V_654 [ 0 ] ;
V_642 -> V_672 . V_544 = F_190 ( F_226 (
V_642 -> V_672 . V_544 ) + V_646 ) ;
V_642 -> V_673 = F_222 ( V_646 ) ;
V_3 = F_227 ( V_444 , V_8 , V_640 , V_641 , & V_66 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_674 ;
V_10 -> V_466 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_675 = V_641 -> V_676 ;
V_644 = F_228 ( V_641 ) ;
V_645 = F_229 ( V_641 ) ;
V_66 = F_96 ( V_644 , V_645 - 2 ) ;
if ( V_640 -> V_664 & V_670 )
V_674 = true ;
else
V_674 = false ;
if ( V_66 == 3 ) {
if ( ( V_644 [ 0 ] == 'I' ) && ( V_644 [ 1 ] == 'P' ) &&
( V_644 [ 2 ] == 'C' ) ) {
F_4 ( V_20 , L_176 ) ;
V_10 -> V_627 = 1 ;
}
} else if ( V_66 == 2 ) {
if ( ( V_644 [ 0 ] == 'A' ) && ( V_644 [ 1 ] == ':' ) ) {
F_4 ( V_20 , L_177 ) ;
}
}
V_644 += V_66 + 1 ;
V_645 -= ( V_66 + 1 ) ;
F_230 ( V_10 -> V_467 , V_639 , sizeof( V_10 -> V_467 ) ) ;
F_10 ( V_10 -> V_677 ) ;
V_10 -> V_677 = F_231 ( V_644 ,
V_645 , V_674 ,
V_515 ) ;
F_4 ( V_20 , L_178 , V_10 -> V_677 ) ;
if ( ( V_641 -> V_678 == 3 ) ||
( V_641 -> V_678 == 7 ) )
V_10 -> V_475 = F_232 ( V_643 -> V_679 ) ;
else
V_10 -> V_475 = 0 ;
F_4 ( V_20 , L_179 , V_10 -> V_475 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_641 -> V_676 ;
}
F_64 ( V_640 ) ;
return V_3 ;
}
static void F_233 ( struct V_680 * V_121 )
{
struct V_490 * V_681 = F_22 ( V_121 , struct V_490 , V_682 ) ;
F_234 ( V_681 -> V_462 ) ;
F_10 ( V_681 ) ;
}
void
F_235 ( struct V_490 * V_491 )
{
struct V_683 * V_684 = & V_491 -> V_582 ;
struct V_685 * V_686 ;
struct V_484 * V_485 ;
F_121 ( & V_491 -> V_579 ) ;
F_2 ( & V_491 -> V_581 ) ;
while ( ( V_686 = F_236 ( V_684 ) ) ) {
V_485 = F_237 ( V_686 , struct V_484 , V_687 ) ;
F_180 ( V_485 ) ;
F_238 ( V_487 , & V_485 -> V_488 ) ;
F_239 ( V_686 , V_684 ) ;
F_3 ( & V_491 -> V_581 ) ;
F_170 ( V_485 ) ;
F_2 ( & V_491 -> V_581 ) ;
}
F_3 ( & V_491 -> V_581 ) ;
F_10 ( V_491 -> V_210 ) ;
F_10 ( V_491 -> V_209 ) ;
F_240 ( & V_491 -> V_682 , F_233 ) ;
}
int
F_158 ( const unsigned int V_444 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_52 -> V_688 || ! V_2 -> V_52 -> V_689 )
return - V_56 ;
if ( ! V_2 -> V_52 -> V_688 ( V_2 ) )
return 0 ;
F_241 ( V_2 , 1 ) ;
V_3 = V_2 -> V_52 -> V_689 ( V_444 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_690 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_160 ( const unsigned int V_444 , struct V_7 * V_8 ,
struct V_514 * V_691 )
{
int V_3 = - V_56 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_478 = V_2 -> V_478 ;
if ( V_692 == 0 )
V_8 -> V_478 &= ( ~ V_2 -> V_185 -> F_215 ) ;
F_4 ( V_20 , L_180 ,
V_2 -> V_655 , V_2 -> V_478 , V_2 -> V_693 ) ;
if ( V_8 -> V_694 . V_35 ) {
F_4 ( V_59 , L_181 ,
V_8 -> V_694 . V_35 ) ;
F_10 ( V_8 -> V_694 . V_35 ) ;
V_8 -> V_694 . V_35 = NULL ;
V_8 -> V_694 . V_36 = 0 ;
}
if ( V_2 -> V_52 -> V_695 )
V_3 = V_2 -> V_52 -> V_695 ( V_444 , V_8 , V_691 ) ;
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
F_243 ( struct V_490 * V_491 , T_2 V_696 )
{
int V_3 ;
struct V_9 * V_697 = F_244 ( V_491 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_152 * V_560 ;
V_560 = F_102 ( sizeof( * V_560 ) , V_145 ) ;
if ( V_560 == NULL )
return F_72 ( - V_146 ) ;
V_560 -> V_462 = V_491 -> V_462 ;
V_560 -> V_234 = V_696 ;
V_560 -> V_233 = V_696 ;
V_560 -> V_208 = V_697 -> V_467 ;
V_560 -> V_266 = V_697 -> V_266 ;
V_560 -> V_286 = V_697 -> V_286 ;
V_560 -> V_322 = V_697 -> V_322 ;
V_560 -> V_284 = ! V_697 -> V_564 ;
V_560 -> V_155 = V_697 -> V_8 -> V_155 ;
V_560 -> V_157 = V_697 -> V_8 -> V_157 ;
V_3 = F_242 ( V_560 , V_697 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_72 ( V_3 ) ;
goto V_512;
}
F_2 ( & V_22 ) ;
++ V_697 -> V_8 -> V_2 -> V_419 ;
F_3 ( & V_22 ) ;
V_8 = F_157 ( V_697 -> V_8 -> V_2 , V_560 ) ;
if ( F_129 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_119 ( V_697 -> V_8 -> V_2 , 0 ) ;
goto V_512;
}
V_10 = F_167 ( V_8 , V_560 ) ;
if ( F_129 ( V_10 ) ) {
F_145 ( V_8 ) ;
goto V_512;
}
if ( F_215 ( V_8 ) )
F_194 ( 0 , V_10 , NULL , V_560 ) ;
V_512:
F_10 ( V_560 -> V_368 ) ;
F_10 ( V_560 -> V_373 ) ;
F_10 ( V_560 ) ;
return V_10 ;
}
struct V_9 *
F_244 ( struct V_490 * V_491 )
{
return F_173 ( F_174 ( V_491 ) ) ;
}
static struct V_484 *
F_245 ( struct V_683 * V_684 , T_2 V_150 )
{
struct V_685 * V_686 = V_684 -> V_685 ;
struct V_484 * V_485 ;
while ( V_686 ) {
V_485 = F_237 ( V_686 , struct V_484 , V_687 ) ;
if ( F_246 ( V_485 -> V_635 , V_150 ) )
V_686 = V_686 -> V_698 ;
else if ( F_247 ( V_485 -> V_635 , V_150 ) )
V_686 = V_686 -> V_699 ;
else
return V_485 ;
}
return NULL ;
}
static void
F_218 ( struct V_683 * V_684 , struct V_484 * V_700 )
{
struct V_685 * * V_498 = & ( V_684 -> V_685 ) , * V_701 = NULL ;
struct V_484 * V_485 ;
while ( * V_498 ) {
V_485 = F_237 ( * V_498 , struct V_484 , V_687 ) ;
V_701 = * V_498 ;
if ( F_246 ( V_485 -> V_635 , V_700 -> V_635 ) )
V_498 = & ( ( * V_498 ) -> V_698 ) ;
else
V_498 = & ( ( * V_498 ) -> V_699 ) ;
}
F_248 ( & V_700 -> V_687 , V_701 , V_498 ) ;
F_249 ( & V_700 -> V_687 , V_684 ) ;
}
struct V_484 *
F_250 ( struct V_490 * V_491 )
{
int V_702 ;
T_2 V_696 = F_251 () ;
struct V_484 * V_485 , * V_703 ;
if ( ! ( V_491 -> V_501 & V_605 ) )
return F_180 ( F_174 ( V_491 ) ) ;
F_2 ( & V_491 -> V_581 ) ;
V_485 = F_245 ( & V_491 -> V_582 , V_696 ) ;
if ( V_485 )
F_180 ( V_485 ) ;
F_3 ( & V_491 -> V_581 ) ;
if ( V_485 == NULL ) {
V_703 = F_102 ( sizeof( * V_485 ) , V_145 ) ;
if ( V_703 == NULL )
return F_72 ( - V_146 ) ;
V_703 -> V_635 = V_696 ;
V_703 -> V_636 = F_72 ( - V_625 ) ;
F_217 ( V_704 , & V_703 -> V_488 ) ;
F_217 ( V_487 , & V_703 -> V_488 ) ;
F_180 ( V_703 ) ;
F_2 ( & V_491 -> V_581 ) ;
V_485 = F_245 ( & V_491 -> V_582 , V_696 ) ;
if ( V_485 ) {
F_180 ( V_485 ) ;
F_3 ( & V_491 -> V_581 ) ;
F_10 ( V_703 ) ;
goto V_705;
}
V_485 = V_703 ;
F_218 ( & V_491 -> V_582 , V_485 ) ;
F_3 ( & V_491 -> V_581 ) ;
} else {
V_705:
V_702 = F_252 ( & V_485 -> V_488 , V_704 ,
V_138 ) ;
if ( V_702 ) {
F_170 ( V_485 ) ;
return F_72 ( - V_72 ) ;
}
if ( ! F_129 ( V_485 -> V_636 ) )
return V_485 ;
if ( F_23 ( V_38 , V_485 -> V_489 + V_706 ) ) {
F_170 ( V_485 ) ;
return F_72 ( - V_625 ) ;
}
if ( F_253 ( V_704 , & V_485 -> V_488 ) )
goto V_705;
}
V_485 -> V_636 = F_243 ( V_491 , V_696 ) ;
F_238 ( V_704 , & V_485 -> V_488 ) ;
F_254 ( & V_485 -> V_488 , V_704 ) ;
if ( F_129 ( V_485 -> V_636 ) ) {
F_170 ( V_485 ) ;
return F_72 ( - V_625 ) ;
}
return V_485 ;
}
static void
V_580 ( struct V_48 * V_49 )
{
struct V_490 * V_491 = F_22 ( V_49 , struct V_490 ,
V_579 . V_49 ) ;
struct V_683 * V_684 = & V_491 -> V_582 ;
struct V_685 * V_686 = F_236 ( V_684 ) ;
struct V_685 * V_5 ;
struct V_484 * V_485 ;
F_2 ( & V_491 -> V_581 ) ;
V_686 = F_236 ( V_684 ) ;
while ( V_686 != NULL ) {
V_5 = V_686 ;
V_686 = F_255 ( V_5 ) ;
V_485 = F_237 ( V_5 , struct V_484 , V_687 ) ;
if ( F_172 ( V_637 , & V_485 -> V_488 ) ||
F_61 ( & V_485 -> V_486 ) != 0 ||
F_30 ( V_485 -> V_489 + V_638 , V_38 ) )
continue;
F_180 ( V_485 ) ;
F_238 ( V_487 , & V_485 -> V_488 ) ;
F_239 ( V_5 , V_684 ) ;
F_3 ( & V_491 -> V_581 ) ;
F_170 ( V_485 ) ;
F_2 ( & V_491 -> V_581 ) ;
}
F_3 ( & V_491 -> V_581 ) ;
F_24 ( V_46 , & V_491 -> V_579 ,
V_638 ) ;
}
