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
switch ( F_83 ( V_143 , V_149 , args ) ) {
case V_150 :
V_147 -> V_151 |= V_152 | V_153 ;
break;
case V_154 :
V_147 -> V_151 |= V_152 | V_155 ;
break;
case V_156 :
F_5 ( V_59 , L_29 ) ;
break;
case V_157 :
V_147 -> V_151 |= V_158 ;
break;
case V_159 :
V_147 -> V_151 |= V_158 | V_155 ;
break;
case V_160 :
V_147 -> V_151 |= V_161 ;
break;
case V_162 :
V_147 -> V_151 |= V_161 | V_155 ;
break;
case V_163 :
V_147 -> V_151 |= V_164 ;
break;
case V_165 :
V_147 -> V_151 |= V_164 | V_155 ;
break;
#ifdef F_84
case V_166 :
V_147 -> V_151 |= V_167 ;
break;
#endif
case V_168 :
V_147 -> V_169 = 1 ;
V_147 -> V_151 |= V_161 ;
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
#endif
default:
F_5 ( V_59 , L_32 , V_143 ) ;
return 1 ;
}
return 0 ;
}
static int
F_87 ( const char * V_189 , struct V_146 * V_147 )
{
char * V_190 ;
const char * V_191 = L_33 ;
T_1 V_36 ;
V_36 = strspn ( V_189 , V_191 ) ;
if ( V_36 != 2 )
return - V_140 ;
V_190 = strpbrk ( V_189 + 2 , V_191 ) ;
if ( ! V_190 )
return - V_140 ;
++ V_190 ;
V_36 = strcspn ( V_190 , V_191 ) ;
V_190 += V_36 ;
V_147 -> V_192 = F_88 ( V_189 , V_190 - V_189 , V_116 ) ;
if ( ! V_147 -> V_192 )
return - V_83 ;
F_89 ( V_147 -> V_192 , '\\' ) ;
if ( ! * V_190 ++ || ! * V_190 )
return 0 ;
V_147 -> V_193 = F_90 ( V_190 , V_116 ) ;
if ( ! V_147 -> V_193 )
return - V_83 ;
return 0 ;
}
static int
F_91 ( const char * V_194 , const char * V_189 ,
struct V_146 * V_147 )
{
char * V_195 , * V_196 ;
char * V_197 = NULL , * V_198 ;
unsigned int V_199 , V_200 , V_201 ;
char V_202 [ 2 ] ;
short int V_203 = - 1 ;
short int V_204 = - 1 ;
bool V_205 = false ;
bool V_206 = false ;
bool V_207 = false ;
char * V_208 = NULL ;
char * V_209 = F_92 () -> V_209 ;
char * string = NULL ;
char * V_210 , * V_143 ;
char V_139 ;
bool V_211 = false ;
unsigned short V_212 = 0 ;
struct V_95 * V_96 = (struct V_95 * ) & V_147 -> V_96 ;
V_202 [ 0 ] = ',' ;
V_202 [ 1 ] = 0 ;
V_139 = V_202 [ 0 ] ;
memset ( V_147 , 0 , sizeof( * V_147 ) ) ;
memset ( V_147 -> V_213 , 0x20 , V_214 ) ;
for ( V_200 = 0 ; V_200 < F_93 ( V_209 , V_214 ) ; V_200 ++ )
V_147 -> V_213 [ V_200 ] = toupper ( V_209 [ V_200 ] ) ;
V_147 -> V_213 [ V_214 ] = 0 ;
V_147 -> V_215 [ 0 ] = 0 ;
V_147 -> V_216 = F_94 () ;
V_147 -> V_217 = F_94 () ;
V_147 -> V_218 = F_95 () ;
V_147 -> V_219 = V_147 -> V_220 = V_221 | V_222 | V_223 ;
V_147 -> V_224 = 1 ;
V_147 -> V_225 = 1 ;
V_147 -> V_173 = true ;
V_147 -> V_226 = V_227 ;
V_147 -> V_49 = & V_178 ;
V_147 -> V_179 = & V_180 ;
if ( ! V_194 )
goto V_228;
V_197 = F_88 ( V_194 , V_229 , V_116 ) ;
if ( ! V_197 )
goto V_228;
V_198 = V_197 ;
V_196 = V_198 + strlen ( V_198 ) ;
if ( strncmp ( V_198 , L_34 , 4 ) == 0 ) {
if ( V_198 [ 4 ] != 0 ) {
V_202 [ 0 ] = V_198 [ 4 ] ;
V_198 += 5 ;
} else {
F_5 ( V_20 , L_35 ) ;
}
}
V_147 -> V_230 = false ;
V_147 -> V_231 = false ;
switch ( F_87 ( V_189 , V_147 ) ) {
case 0 :
break;
case - V_83 :
F_5 ( V_59 , L_36 ) ;
goto V_228;
case - V_140 :
F_5 ( V_59 , L_37 ) ;
goto V_228;
default:
F_5 ( V_59 , L_38 ) ;
goto V_228;
}
while ( ( V_195 = F_96 ( & V_198 , V_202 ) ) != NULL ) {
T_2 args [ V_148 ] ;
unsigned long V_141 ;
int V_232 ;
if ( ! * V_195 )
continue;
V_232 = F_83 ( V_195 , V_233 , args ) ;
switch ( V_232 ) {
case V_234 :
break;
case V_235 :
V_147 -> V_236 = 0 ;
break;
case V_237 :
V_147 -> V_236 = 1 ;
break;
case V_238 :
V_203 = 1 ;
break;
case V_239 :
V_203 = 0 ;
break;
case V_240 :
V_204 = 1 ;
break;
case V_241 :
V_204 = 0 ;
break;
case V_242 :
V_147 -> V_243 = 1 ;
break;
case V_244 :
V_147 -> V_245 = 1 ;
break;
case V_246 :
V_147 -> V_247 = 1 ;
break;
case V_248 :
V_147 -> V_247 = 0 ;
break;
case V_249 :
V_147 -> V_250 = 0 ;
break;
case V_251 :
V_147 -> V_250 = 1 ;
break;
case V_252 :
V_147 -> V_253 = 1 ;
break;
case V_254 :
V_147 -> V_253 = 0 ;
break;
case V_255 :
V_147 -> V_256 = 1 ;
break;
case V_257 :
V_147 -> V_256 = 0 ;
break;
case V_258 :
V_147 -> V_259 = 1 ;
break;
case V_260 :
V_147 -> V_224 = 1 ;
break;
case V_261 :
V_147 -> V_224 = 0 ;
break;
case V_262 :
V_147 -> V_263 = 1 ;
break;
case V_264 :
V_147 -> V_265 = 1 ;
break;
case V_266 :
V_147 -> V_267 = 0 ;
break;
case V_268 :
V_147 -> V_267 = 1 ;
if ( V_147 -> V_220 ==
( V_269 & ~ ( V_270 | V_271 ) ) )
V_147 -> V_220 = V_269 ;
break;
case V_272 :
V_147 -> V_273 = 1 ;
break;
case V_274 :
V_147 -> V_275 = 1 ;
break;
case V_276 :
V_147 -> V_275 = 0 ;
break;
case V_277 :
V_147 -> V_278 = true ;
break;
case V_279 :
V_147 -> V_278 = false ;
break;
case V_280 :
V_147 -> V_247 = 0 ;
break;
case V_281 :
V_147 -> V_247 = 1 ;
break;
case V_282 :
V_147 -> V_283 = 0 ;
break;
case V_284 :
V_147 -> V_283 = 1 ;
break;
case V_285 :
V_147 -> V_286 = 1 ;
break;
case V_287 :
V_147 -> V_286 = 0 ;
break;
case V_288 :
V_147 -> V_225 = 1 ;
break;
case V_289 :
V_147 -> V_225 = 0 ;
break;
case V_290 :
V_147 -> V_291 = 1 ;
break;
case V_292 :
V_147 -> V_293 = 1 ;
break;
case V_294 :
V_147 -> V_293 = 0 ;
break;
case V_295 :
V_147 -> V_296 = 0 ;
break;
case V_297 :
V_147 -> V_296 = 1 ;
break;
case V_298 :
V_147 -> V_299 = 1 ;
break;
case V_300 :
V_147 -> V_151 |= V_155 ;
break;
case V_301 :
V_147 -> V_302 = 1 ;
break;
case V_303 :
F_97 ( V_304 L_39
L_40
L_41 ) ;
break;
case V_305 :
#ifndef F_98
F_5 ( V_59 , L_42 ) ;
goto V_228;
#endif
V_147 -> V_306 = true ;
break;
case V_307 :
V_147 -> V_308 = true ;
break;
case V_309 :
V_147 -> V_310 = true ;
break;
case V_311 :
V_207 = true ;
break;
case V_312 :
if ( F_75 ( args , & V_147 -> V_313 ) ) {
F_5 ( V_59 , L_43 ,
V_21 ) ;
goto V_228;
}
V_147 -> V_230 = true ;
break;
case V_314 :
if ( F_79 ( args , & V_147 -> V_315 ) ) {
F_5 ( V_59 , L_44 ,
V_21 ) ;
goto V_228;
}
V_147 -> V_231 = true ;
break;
case V_316 :
if ( F_75 ( args , & V_147 -> V_217 ) ) {
F_5 ( V_59 , L_45 ,
V_21 ) ;
goto V_228;
}
V_205 = true ;
break;
case V_317 :
if ( F_75 ( args , & V_147 -> V_216 ) ) {
F_5 ( V_59 , L_46 ,
V_21 ) ;
goto V_228;
}
break;
case V_318 :
if ( F_79 ( args , & V_147 -> V_218 ) ) {
F_5 ( V_59 , L_47 ,
V_21 ) ;
goto V_228;
}
V_206 = true ;
break;
case V_319 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_48 ,
V_21 ) ;
goto V_228;
}
V_147 -> V_220 = V_141 ;
break;
case V_320 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_49 ,
V_21 ) ;
goto V_228;
}
V_147 -> V_219 = V_141 ;
break;
case V_321 :
if ( F_72 ( args , & V_141 ) ||
V_141 > V_322 ) {
F_5 ( V_59 , L_50 ,
V_21 ) ;
goto V_228;
}
V_212 = ( unsigned short ) V_141 ;
break;
case V_323 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_51 ,
V_21 ) ;
goto V_228;
}
V_147 -> V_324 = V_141 ;
break;
case V_325 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_52 ,
V_21 ) ;
goto V_228;
}
V_147 -> V_326 = V_141 ;
break;
case V_327 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_53 ,
V_21 ) ;
goto V_228;
}
V_147 -> V_226 = V_53 * V_141 ;
if ( V_147 -> V_226 > V_328 ) {
F_5 ( V_59 , L_54 ) ;
goto V_228;
}
break;
case V_329 :
V_147 -> V_169 = 1 ;
V_147 -> V_330 = NULL ;
break;
case V_331 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_332;
if ( F_93 ( string , V_333 ) >
V_333 ) {
F_97 ( V_304 L_55 ) ;
goto V_228;
}
V_147 -> V_330 = F_90 ( string , V_116 ) ;
if ( ! V_147 -> V_330 )
goto V_228;
break;
case V_334 :
V_210 = strchr ( V_195 , '=' ) ;
V_210 ++ ;
if ( ! ( V_210 < V_196 && V_210 [ 1 ] == V_139 ) ) {
V_147 -> V_335 = NULL ;
break;
}
case V_336 :
V_143 = strchr ( V_195 , '=' ) ;
V_143 ++ ;
V_210 = ( char * ) V_143 + strlen ( V_143 ) ;
if ( V_210 < V_196 && V_210 [ 1 ] == V_139 ) {
V_210 [ 0 ] = V_139 ;
while ( ( V_210 = strchr ( V_210 , V_139 ) )
!= NULL && ( V_210 [ 1 ] == V_139 ) ) {
V_210 = ( char * ) & V_210 [ 2 ] ;
}
if ( V_210 ) {
V_210 [ 0 ] = '\0' ;
V_198 = ( char * ) & V_210 [ 1 ] ;
} else
V_198 = V_196 ;
}
V_199 = strlen ( V_143 ) ;
V_147 -> V_335 = F_99 ( V_199 + 1 , V_116 ) ;
if ( V_147 -> V_335 == NULL ) {
F_97 ( V_304 L_56
L_57 ) ;
goto V_228;
}
for ( V_200 = 0 , V_201 = 0 ; V_200 < V_199 ; V_200 ++ , V_201 ++ ) {
V_147 -> V_335 [ V_201 ] = V_143 [ V_200 ] ;
if ( ( V_143 [ V_200 ] == V_139 ) &&
V_143 [ V_200 + 1 ] == V_139 )
V_200 ++ ;
}
V_147 -> V_335 [ V_201 ] = '\0' ;
break;
case V_337 :
V_211 = false ;
break;
case V_338 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_332;
if ( ! F_100 ( V_96 , string ,
strlen ( string ) ) ) {
F_97 ( V_339 L_58 ,
string ) ;
goto V_228;
}
V_211 = true ;
break;
case V_340 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_332;
if ( F_93 ( string , 256 ) == 256 ) {
F_97 ( V_304 L_59
L_60 ) ;
goto V_228;
}
V_147 -> V_341 = F_90 ( string , V_116 ) ;
if ( ! V_147 -> V_341 ) {
F_97 ( V_304 L_56
L_61 ) ;
goto V_228;
}
F_5 ( V_20 , L_62 ) ;
break;
case V_342 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_332;
if ( ! F_100 (
(struct V_95 * ) & V_147 -> V_343 ,
string , strlen ( string ) ) ) {
F_97 ( V_304 L_63
L_64 , string ) ;
goto V_228;
}
break;
case V_344 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_332;
if ( F_93 ( string , 1024 ) >= 65 ) {
F_97 ( V_304 L_65
L_66 ) ;
goto V_228;
}
if ( F_101 ( string , L_67 , 7 ) != 0 ) {
V_147 -> V_345 = F_90 ( string ,
V_116 ) ;
if ( ! V_147 -> V_345 ) {
F_97 ( V_304 L_68
L_69 ) ;
goto V_228;
}
}
F_5 ( V_20 , L_70 , string ) ;
break;
case V_346 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_332;
memset ( V_147 -> V_213 , 0x20 ,
V_214 ) ;
for ( V_200 = 0 ; V_200 < V_214 ; V_200 ++ ) {
if ( string [ V_200 ] == 0 )
break;
V_147 -> V_213 [ V_200 ] = string [ V_200 ] ;
}
if ( V_200 == V_214 && string [ V_200 ] != 0 )
F_97 ( V_304 L_71
L_72 ) ;
break;
case V_347 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_332;
memset ( V_147 -> V_215 , 0x20 ,
V_348 ) ;
for ( V_200 = 0 ; V_200 < 15 ; V_200 ++ ) {
if ( string [ V_200 ] == 0 )
break;
V_147 -> V_215 [ V_200 ] = string [ V_200 ] ;
}
if ( V_200 == V_214 && string [ V_200 ] != 0 )
F_97 ( V_304 L_73
L_74 ) ;
break;
case V_349 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_332;
if ( F_101 ( string , L_75 , 1 ) == 0 ) {
break;
}
F_97 ( V_304 L_76
L_77 ) ;
goto V_228;
case V_350 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_332;
if ( F_86 ( string , V_147 ) != 0 )
goto V_228;
break;
case V_351 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_332;
if ( F_82 ( string , V_147 ) != 0 )
goto V_228;
break;
case V_352 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_332;
if ( F_85 ( string , V_147 ) != 0 )
goto V_228;
break;
default:
if ( ! V_208 )
V_208 = V_195 ;
break;
}
F_11 ( string ) ;
string = NULL ;
}
if ( ! V_207 && V_208 ) {
F_97 ( V_339 L_78 , V_208 ) ;
goto V_228;
}
#ifndef F_102
if ( V_147 -> V_310 ) {
F_5 ( V_59 , L_79 ) ;
goto V_228;
}
#endif
if ( ! V_147 -> V_192 ) {
F_5 ( V_59 , L_80 ) ;
goto V_228;
}
if ( ! strchr ( V_147 -> V_192 + 3 , '\\' ) ) {
F_5 ( V_59 , L_81 ) ;
goto V_228;
}
if ( ! V_211 ) {
if ( ! F_100 ( V_96 , & V_147 -> V_192 [ 2 ] ,
strlen ( & V_147 -> V_192 [ 2 ] ) ) ) {
F_97 ( V_339 L_82
L_83 ) ;
goto V_228;
}
}
F_41 ( V_96 , V_212 ) ;
if ( V_205 )
V_147 -> V_203 = V_203 ;
else if ( V_203 == 1 )
F_97 ( V_353 L_84
L_85 ) ;
if ( V_206 )
V_147 -> V_204 = V_204 ;
else if ( V_204 == 1 )
F_97 ( V_353 L_86
L_87 ) ;
F_11 ( V_197 ) ;
return 0 ;
V_332:
F_97 ( V_304 L_88 ) ;
V_228:
F_11 ( string ) ;
F_11 ( V_197 ) ;
return 1 ;
}
static bool
F_103 ( struct V_95 * V_343 , struct V_95 * V_354 )
{
switch ( V_343 -> V_355 ) {
case V_356 :
return ( V_354 -> V_355 == V_356 ) ;
case V_357 : {
struct V_358 * V_359 = (struct V_358 * ) V_343 ;
struct V_358 * V_360 = (struct V_358 * ) V_354 ;
return ( V_359 -> V_361 . V_362 == V_360 -> V_361 . V_362 ) ;
}
case V_363 : {
struct V_364 * V_365 = (struct V_364 * ) V_343 ;
struct V_364 * V_366 = (struct V_364 * ) V_354 ;
return F_104 ( & V_365 -> V_367 , & V_366 -> V_367 ) ;
}
default:
F_105 ( 1 ) ;
return false ;
}
}
static bool
F_106 ( struct V_1 * V_2 , struct V_95 * V_368 )
{
T_5 V_212 , * V_369 ;
switch ( V_368 -> V_355 ) {
case V_357 :
V_369 = & ( (struct V_358 * ) & V_2 -> V_96 ) -> V_370 ;
V_212 = ( (struct V_358 * ) V_368 ) -> V_370 ;
break;
case V_363 :
V_369 = & ( (struct V_364 * ) & V_2 -> V_96 ) -> V_371 ;
V_212 = ( (struct V_364 * ) V_368 ) -> V_371 ;
break;
default:
F_105 ( 1 ) ;
return false ;
}
if ( ! V_212 ) {
V_212 = F_107 ( V_97 ) ;
if ( V_212 == * V_369 )
return true ;
V_212 = F_107 ( V_372 ) ;
}
return V_212 == * V_369 ;
}
static bool
F_108 ( struct V_1 * V_2 , struct V_95 * V_368 ,
struct V_95 * V_343 )
{
switch ( V_368 -> V_355 ) {
case V_357 : {
struct V_358 * V_373 = (struct V_358 * ) V_368 ;
struct V_358 * V_374 =
(struct V_358 * ) & V_2 -> V_96 ;
if ( V_373 -> V_361 . V_362 != V_374 -> V_361 . V_362 )
return false ;
break;
}
case V_363 : {
struct V_364 * V_375 = (struct V_364 * ) V_368 ;
struct V_364 * V_376 =
(struct V_364 * ) & V_2 -> V_96 ;
if ( ! F_104 ( & V_375 -> V_367 ,
& V_376 -> V_367 ) )
return false ;
if ( V_375 -> V_377 != V_376 -> V_377 )
return false ;
break;
}
default:
F_105 ( 1 ) ;
return false ;
}
if ( ! F_103 ( V_343 , (struct V_95 * ) & V_2 -> V_343 ) )
return false ;
return true ;
}
static bool
F_109 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
unsigned int V_378 ;
if ( V_147 -> V_151 & ( ~ ( V_155 | V_379 ) ) )
V_378 = V_147 -> V_151 ;
else
V_378 = V_380 | V_147 -> V_151 ;
switch ( V_2 -> V_381 ) {
case V_382 :
if ( ! ( V_378 & ( V_167 | V_383 ) ) )
return false ;
break;
case V_384 :
if ( ! ( V_378 & V_164 ) )
return false ;
break;
case V_385 :
if ( ! ( V_378 & V_161 ) )
return false ;
break;
case V_386 :
if ( ! ( V_378 & V_152 ) )
return false ;
break;
case V_387 :
if ( ! ( V_378 & V_158 ) )
return false ;
break;
default:
return false ;
}
if ( ( V_378 & V_153 ) == 0 &&
( V_2 -> V_388 & V_389 ) )
return false ;
else if ( ( ( V_378 & V_155 ) == V_155 ) &&
( V_2 -> V_388 &
( V_390 | V_389 ) ) == 0 )
return false ;
return true ;
}
static int F_110 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_95 * V_368 = (struct V_95 * ) & V_147 -> V_96 ;
if ( ( V_2 -> V_179 != V_147 -> V_179 ) || ( V_2 -> V_49 != V_147 -> V_49 ) )
return 0 ;
if ( ! F_111 ( F_112 ( V_2 ) , V_125 -> V_391 -> V_392 ) )
return 0 ;
if ( ! F_108 ( V_2 , V_368 ,
(struct V_95 * ) & V_147 -> V_343 ) )
return 0 ;
if ( ! F_106 ( V_2 , V_368 ) )
return 0 ;
if ( ! F_109 ( V_2 , V_147 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_113 ( struct V_146 * V_147 )
{
struct V_1 * V_2 ;
F_2 ( & V_22 ) ;
F_114 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_110 ( V_2 , V_147 ) )
continue;
++ V_2 -> V_393 ;
F_3 ( & V_22 ) ;
F_5 ( V_20 , L_89 ) ;
return V_2 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_115 ( struct V_1 * V_2 )
{
struct V_123 * V_394 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_393 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_116 ( F_112 ( V_2 ) ) ;
F_16 ( & V_2 -> V_106 ) ;
F_3 ( & V_22 ) ;
F_117 ( & V_2 -> V_48 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
F_11 ( V_2 -> V_34 . V_35 ) ;
V_2 -> V_34 . V_35 = NULL ;
V_2 -> V_34 . V_36 = 0 ;
V_394 = F_65 ( & V_2 -> V_133 , NULL ) ;
if ( V_394 )
F_120 ( V_395 , V_394 ) ;
}
static struct V_1 *
F_121 ( struct V_146 * V_396 )
{
struct V_1 * V_397 = NULL ;
int V_3 ;
F_5 ( V_20 , L_90 , V_396 -> V_192 ) ;
V_397 = F_113 ( V_396 ) ;
if ( V_397 )
return V_397 ;
V_397 = F_99 ( sizeof( struct V_1 ) , V_116 ) ;
if ( ! V_397 ) {
V_3 = - V_83 ;
goto V_398;
}
V_3 = F_122 ( V_397 ) ;
if ( V_3 ) {
F_5 ( V_59 , L_91 , V_3 ) ;
goto V_398;
}
V_397 -> V_49 = V_396 -> V_49 ;
V_397 -> V_179 = V_396 -> V_179 ;
F_123 ( V_397 , F_124 ( V_125 -> V_391 -> V_392 ) ) ;
V_397 -> V_56 = F_70 ( V_396 -> V_192 ) ;
if ( F_125 ( V_397 -> V_56 ) ) {
V_3 = F_126 ( V_397 -> V_56 ) ;
goto V_399;
}
V_397 -> V_243 = V_396 -> V_243 ;
V_397 -> V_245 = V_396 -> V_245 ;
V_397 -> V_400 = V_396 -> V_401 ;
V_397 -> V_402 = 0 ;
V_397 -> V_108 = 1 ;
F_127 ( & V_397 -> V_63 ) ;
F_127 ( & V_397 -> V_109 ) ;
F_13 ( & V_397 -> V_110 ) ;
F_128 ( & V_397 -> V_27 ) ;
memcpy ( V_397 -> V_403 ,
V_396 -> V_213 , V_348 ) ;
memcpy ( V_397 -> V_404 ,
V_396 -> V_215 , V_348 ) ;
V_397 -> V_33 = false ;
V_397 -> V_32 = 0 ;
V_397 -> V_37 = V_38 ;
F_129 ( & V_397 -> V_107 ) ;
F_13 ( & V_397 -> V_106 ) ;
F_13 ( & V_397 -> V_23 ) ;
F_130 ( & V_397 -> V_48 , F_21 ) ;
memcpy ( & V_397 -> V_343 , & V_396 -> V_343 ,
sizeof( V_397 -> V_343 ) ) ;
memcpy ( & V_397 -> V_96 , & V_396 -> V_96 ,
sizeof( V_397 -> V_96 ) ) ;
V_397 -> V_15 = V_405 ;
++ V_397 -> V_393 ;
V_3 = F_131 ( V_397 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_92 ) ;
goto V_399;
}
F_132 ( V_406 ) ;
V_397 -> V_133 = F_133 ( F_56 ,
V_397 , L_93 ) ;
if ( F_125 ( V_397 -> V_133 ) ) {
V_3 = F_126 ( V_397 -> V_133 ) ;
F_5 ( V_59 , L_94 , V_3 ) ;
F_134 ( V_406 ) ;
goto V_399;
}
V_397 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_135 ( & V_397 -> V_106 , & V_407 ) ;
F_3 ( & V_22 ) ;
F_136 ( V_397 ) ;
F_24 ( V_57 , & V_397 -> V_48 , V_52 ) ;
return V_397 ;
V_399:
F_118 ( V_397 ) ;
F_116 ( F_112 ( V_397 ) ) ;
V_398:
if ( V_397 ) {
if ( ! F_125 ( V_397 -> V_56 ) )
F_11 ( V_397 -> V_56 ) ;
if ( V_397 -> V_28 )
F_10 ( V_397 -> V_28 ) ;
F_11 ( V_397 ) ;
}
return F_71 ( V_3 ) ;
}
static int F_137 ( struct V_7 * V_8 , struct V_146 * V_147 )
{
switch ( V_8 -> V_2 -> V_381 ) {
case V_386 :
if ( ! F_138 ( V_147 -> V_216 , V_8 -> V_216 ) )
return 0 ;
break;
default:
if ( V_8 -> V_408 == NULL ) {
if ( ! V_147 -> V_169 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_408 ,
V_147 -> V_330 ? V_147 -> V_330 : L_95 ,
V_333 ) )
return 0 ;
if ( strlen ( V_147 -> V_330 ) != 0 &&
V_8 -> V_335 != NULL &&
strncmp ( V_8 -> V_335 ,
V_147 -> V_335 ? V_147 -> V_335 : L_95 ,
V_409 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_139 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_7 * V_8 ;
F_2 ( & V_22 ) ;
F_114 (ses, &server->smb_ses_list, smb_ses_list) {
if ( ! F_137 ( V_8 , V_147 ) )
continue;
++ V_8 -> V_410 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_140 ( struct V_7 * V_8 )
{
unsigned int V_411 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_20 , L_96 , V_21 , V_8 -> V_410 ) ;
F_2 ( & V_22 ) ;
if ( -- V_8 -> V_410 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_8 -> V_23 ) ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_412 == V_62 && V_2 -> V_49 -> V_413 ) {
V_411 = F_141 () ;
V_2 -> V_49 -> V_413 ( V_411 , V_8 ) ;
F_142 ( V_411 ) ;
}
F_143 ( V_8 ) ;
F_115 ( V_2 ) ;
}
static int
F_144 ( struct V_146 * V_147 , struct V_7 * V_8 )
{
int V_3 = 0 ;
char * V_414 , * V_139 , * V_415 ;
T_6 V_36 ;
struct V_416 * V_416 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_358 * V_417 ;
struct V_364 * V_418 ;
struct V_419 * V_420 ;
V_414 = F_35 ( V_421 , V_116 ) ;
if ( ! V_414 )
return - V_83 ;
switch ( V_2 -> V_96 . V_422 ) {
case V_357 :
V_417 = (struct V_358 * ) & V_2 -> V_96 ;
sprintf ( V_414 , L_97 , & V_417 -> V_361 . V_362 ) ;
break;
case V_363 :
V_418 = (struct V_364 * ) & V_2 -> V_96 ;
sprintf ( V_414 , L_98 , & V_418 -> V_367 . V_423 ) ;
break;
default:
F_5 ( V_20 , L_99 ,
V_2 -> V_96 . V_422 ) ;
V_3 = - V_140 ;
goto V_398;
}
F_5 ( V_20 , L_100 , V_21 , V_414 ) ;
V_416 = F_145 ( & V_424 , V_414 , L_95 ) ;
if ( F_125 ( V_416 ) ) {
if ( ! V_8 -> V_425 ) {
F_5 ( V_20 , L_101 ) ;
V_3 = F_126 ( V_416 ) ;
goto V_398;
}
sprintf ( V_414 , L_102 , V_8 -> V_425 ) ;
F_5 ( V_20 , L_100 , V_21 , V_414 ) ;
V_416 = F_145 ( & V_424 , V_414 , L_95 ) ;
if ( F_125 ( V_416 ) ) {
V_3 = F_126 ( V_416 ) ;
goto V_398;
}
}
F_146 ( & V_416 -> V_426 ) ;
V_420 = V_416 -> V_415 . V_195 ;
if ( F_147 ( V_420 ) ) {
V_3 = V_420 ? F_126 ( V_420 ) : - V_140 ;
goto V_427;
}
V_415 = ( char * ) V_420 -> V_195 ;
V_139 = F_148 ( V_415 , V_420 -> V_428 , ':' ) ;
F_5 ( V_20 , L_103 , V_415 ) ;
if ( ! V_139 ) {
F_5 ( V_20 , L_104 ,
V_420 -> V_428 ) ;
V_3 = - V_140 ;
goto V_427;
}
V_36 = V_139 - V_415 ;
if ( V_36 > V_333 || V_36 <= 0 ) {
F_5 ( V_20 , L_105 ,
V_36 ) ;
V_3 = - V_140 ;
goto V_427;
}
V_147 -> V_330 = F_88 ( V_415 , V_36 , V_116 ) ;
if ( ! V_147 -> V_330 ) {
F_5 ( V_20 , L_106 ,
V_36 ) ;
V_3 = - V_83 ;
goto V_427;
}
F_5 ( V_20 , L_107 , V_21 , V_147 -> V_330 ) ;
V_36 = V_416 -> V_428 - ( V_36 + 1 ) ;
if ( V_36 > V_409 || V_36 <= 0 ) {
F_5 ( V_20 , L_108 , V_36 ) ;
V_3 = - V_140 ;
F_11 ( V_147 -> V_330 ) ;
V_147 -> V_330 = NULL ;
goto V_427;
}
++ V_139 ;
V_147 -> V_335 = F_88 ( V_139 , V_36 , V_116 ) ;
if ( ! V_147 -> V_335 ) {
F_5 ( V_20 , L_109 ,
V_36 ) ;
V_3 = - V_83 ;
F_11 ( V_147 -> V_330 ) ;
V_147 -> V_330 = NULL ;
goto V_427;
}
V_427:
F_149 ( & V_416 -> V_426 ) ;
F_150 ( V_416 ) ;
V_398:
F_11 ( V_414 ) ;
F_5 ( V_20 , L_110 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_151 ( struct V_1 * V_2 , struct V_146 * V_396 )
{
int V_3 = - V_83 ;
unsigned int V_411 ;
struct V_7 * V_8 ;
struct V_358 * V_368 = (struct V_358 * ) & V_2 -> V_96 ;
struct V_364 * V_375 = (struct V_364 * ) & V_2 -> V_96 ;
V_411 = F_141 () ;
V_8 = F_139 ( V_2 , V_396 ) ;
if ( V_8 ) {
F_5 ( V_20 , L_111 ,
V_8 -> V_412 ) ;
F_8 ( & V_8 -> V_429 ) ;
V_3 = F_152 ( V_411 , V_8 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_429 ) ;
F_140 ( V_8 ) ;
F_153 ( V_411 ) ;
return F_71 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_5 ( V_20 , L_112 ) ;
V_3 = F_154 ( V_411 , V_8 ,
V_396 -> V_430 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_429 ) ;
F_140 ( V_8 ) ;
F_153 ( V_411 ) ;
return F_71 ( V_3 ) ;
}
}
F_12 ( & V_8 -> V_429 ) ;
F_115 ( V_2 ) ;
F_153 ( V_411 ) ;
return V_8 ;
}
F_5 ( V_20 , L_113 ) ;
V_8 = F_155 () ;
if ( V_8 == NULL )
goto V_431;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_96 . V_422 == V_363 )
sprintf ( V_8 -> V_432 , L_114 , & V_375 -> V_367 ) ;
else
sprintf ( V_8 -> V_432 , L_115 , & V_368 -> V_361 ) ;
if ( V_396 -> V_330 ) {
V_8 -> V_408 = F_90 ( V_396 -> V_330 , V_116 ) ;
if ( ! V_8 -> V_408 )
goto V_431;
}
if ( V_396 -> V_335 ) {
V_8 -> V_335 = F_90 ( V_396 -> V_335 , V_116 ) ;
if ( ! V_8 -> V_335 )
goto V_431;
}
if ( V_396 -> V_341 ) {
V_8 -> V_425 = F_90 ( V_396 -> V_341 , V_116 ) ;
if ( ! V_8 -> V_425 )
goto V_431;
}
V_8 -> V_216 = V_396 -> V_216 ;
V_8 -> V_217 = V_396 -> V_217 ;
V_8 -> V_433 = V_396 -> V_151 ;
F_8 ( & V_8 -> V_429 ) ;
V_3 = F_152 ( V_411 , V_8 ) ;
if ( ! V_3 )
V_3 = F_154 ( V_411 , V_8 , V_396 -> V_430 ) ;
F_12 ( & V_8 -> V_429 ) ;
if ( V_3 )
goto V_431;
F_2 ( & V_22 ) ;
F_135 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_153 ( V_411 ) ;
return V_8 ;
V_431:
F_143 ( V_8 ) ;
F_153 ( V_411 ) ;
return F_71 ( V_3 ) ;
}
static int F_156 ( struct V_9 * V_10 , const char * V_136 )
{
if ( V_10 -> V_434 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_435 , V_136 , V_436 ) )
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
++ V_10 -> V_437 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_158 ( struct V_9 * V_10 )
{
unsigned int V_411 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( V_20 , L_116 , V_21 , V_10 -> V_437 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_437 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_411 = F_141 () ;
if ( V_8 -> V_2 -> V_49 -> V_438 )
V_8 -> V_2 -> V_49 -> V_438 ( V_411 , V_10 ) ;
F_142 ( V_411 ) ;
F_159 ( V_10 ) ;
F_160 ( V_10 ) ;
F_140 ( V_8 ) ;
}
static struct V_9 *
F_161 ( struct V_7 * V_8 , struct V_146 * V_396 )
{
int V_3 , V_411 ;
struct V_9 * V_10 ;
V_10 = F_157 ( V_8 , V_396 -> V_192 ) ;
if ( V_10 ) {
F_5 ( V_20 , L_117 ) ;
F_140 ( V_8 ) ;
if ( V_10 -> V_302 != V_396 -> V_302 )
F_5 ( V_59 , L_118 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_49 -> V_439 ) {
V_3 = - V_55 ;
goto V_440;
}
V_10 = F_162 () ;
if ( V_10 == NULL ) {
V_3 = - V_83 ;
goto V_440;
}
V_10 -> V_8 = V_8 ;
if ( V_396 -> V_335 ) {
V_10 -> V_335 = F_90 ( V_396 -> V_335 , V_116 ) ;
if ( ! V_10 -> V_335 ) {
V_3 = - V_83 ;
goto V_440;
}
}
V_411 = F_141 () ;
V_3 = V_8 -> V_2 -> V_49 -> V_439 ( V_411 , V_8 , V_396 -> V_192 , V_10 ,
V_396 -> V_430 ) ;
F_153 ( V_411 ) ;
F_5 ( V_20 , L_119 , V_3 ) ;
if ( V_3 )
goto V_440;
if ( V_396 -> V_259 ) {
V_10 -> V_441 &= ~ V_442 ;
F_5 ( V_20 , L_120 , V_10 -> V_441 ) ;
}
V_10 -> V_302 = V_396 -> V_302 ;
V_10 -> V_247 = V_396 -> V_247 ;
V_10 -> V_265 = V_396 -> V_265 ;
V_10 -> V_299 = V_396 -> V_299 ;
F_13 ( & V_10 -> V_443 ) ;
F_2 ( & V_22 ) ;
F_135 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_163 ( V_10 ) ;
return V_10 ;
V_440:
F_160 ( V_10 ) ;
return F_71 ( V_3 ) ;
}
void
F_164 ( struct V_444 * V_445 )
{
if ( ! V_445 || F_125 ( V_445 ) )
return;
if ( ! F_165 ( & V_445 -> V_446 ) ||
F_166 ( V_447 , & V_445 -> V_448 ) ) {
V_445 -> V_449 = V_38 ;
return;
}
if ( ! F_125 ( F_167 ( V_445 ) ) )
F_158 ( F_167 ( V_445 ) ) ;
F_11 ( V_445 ) ;
return;
}
static inline struct V_444 *
F_168 ( struct V_450 * V_451 )
{
return V_451 -> V_452 ;
}
static int
F_169 ( struct V_453 * V_454 , struct V_455 * V_456 )
{
struct V_450 * V_457 = F_170 ( V_454 ) ;
struct V_450 * V_65 = V_456 -> V_451 ;
if ( ( V_454 -> V_458 & V_459 ) != ( V_456 -> V_30 & V_459 ) )
return 0 ;
if ( ( V_457 -> V_460 & V_461 ) !=
( V_65 -> V_460 & V_461 ) )
return 0 ;
if ( V_65 -> V_326 && V_65 -> V_326 < V_457 -> V_326 )
return 0 ;
if ( V_65 -> V_324 && V_65 -> V_324 < V_457 -> V_324 )
return 0 ;
if ( ! F_138 ( V_457 -> V_462 , V_65 -> V_462 ) || ! F_171 ( V_457 -> V_463 , V_65 -> V_463 ) )
return 0 ;
if ( V_457 -> V_464 != V_65 -> V_464 ||
V_457 -> V_465 != V_65 -> V_465 )
return 0 ;
if ( strcmp ( V_457 -> V_430 -> V_466 , V_65 -> V_430 -> V_466 ) )
return 0 ;
if ( V_457 -> V_226 != V_65 -> V_226 )
return 0 ;
return 1 ;
}
int
F_172 ( struct V_453 * V_454 , void * V_195 )
{
struct V_455 * V_456 = (struct V_455 * ) V_195 ;
struct V_146 * V_396 ;
struct V_450 * V_451 ;
struct V_1 * V_467 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_444 * V_445 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_451 = F_170 ( V_454 ) ;
V_445 = F_173 ( F_168 ( V_451 ) ) ;
if ( F_125 ( V_445 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_167 ( V_445 ) ;
V_8 = V_10 -> V_8 ;
V_467 = V_8 -> V_2 ;
V_396 = V_456 -> V_147 ;
if ( ! F_110 ( V_467 , V_396 ) ||
! F_137 ( V_8 , V_396 ) ||
! F_156 ( V_10 , V_396 -> V_192 ) ) {
V_3 = 0 ;
goto V_468;
}
V_3 = F_169 ( V_454 , V_456 ) ;
V_468:
F_3 ( & V_22 ) ;
F_164 ( V_445 ) ;
return V_3 ;
}
int
F_174 ( const unsigned int V_411 , struct V_7 * V_8 , const char * V_469 ,
const struct V_470 * V_471 , unsigned int * V_472 ,
struct V_473 * * V_474 , int V_253 )
{
char * V_475 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_49 -> V_439 || ! V_8 -> V_2 -> V_49 -> V_476 )
return - V_55 ;
* V_472 = 0 ;
* V_474 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_475 = F_35 ( 2 +
F_93 ( V_8 -> V_432 , V_477 * 2 )
+ 1 + 4 + 2 , V_116 ) ;
if ( V_475 == NULL )
return - V_83 ;
V_475 [ 0 ] = '\\' ;
V_475 [ 1 ] = '\\' ;
strcpy ( V_475 + 2 , V_8 -> V_432 ) ;
strcpy ( V_475 + 2 + strlen ( V_8 -> V_432 ) , L_121 ) ;
V_3 = V_8 -> V_2 -> V_49 -> V_439 ( V_411 , V_8 , V_475 , NULL ,
V_471 ) ;
F_5 ( V_20 , L_122 , V_3 , V_8 -> V_25 ) ;
F_11 ( V_475 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_49 -> V_476 ( V_411 , V_8 , V_469 ,
V_474 , V_472 ,
V_471 , V_253 ) ;
return V_3 ;
}
static inline void
F_175 ( struct V_478 * V_479 )
{
struct V_479 * V_480 = V_479 -> V_480 ;
F_176 ( F_177 ( V_480 ) ) ;
F_178 ( V_480 , L_123 ,
& V_481 [ 0 ] , L_124 , & V_482 [ 0 ] ) ;
}
static inline void
F_179 ( struct V_478 * V_479 )
{
struct V_479 * V_480 = V_479 -> V_480 ;
F_176 ( F_177 ( V_480 ) ) ;
F_178 ( V_480 , L_125 ,
& V_481 [ 1 ] , L_126 , & V_482 [ 1 ] ) ;
}
static inline void
F_175 ( struct V_478 * V_479 )
{
}
static inline void
F_179 ( struct V_478 * V_479 )
{
}
static void F_180 ( char * V_483 , char * V_484 , unsigned int V_78 )
{
unsigned int V_200 , V_201 ;
for ( V_200 = 0 , V_201 = 0 ; V_200 < ( V_78 ) ; V_200 ++ ) {
V_483 [ V_201 ] = 'A' + ( 0x0F & ( V_484 [ V_200 ] >> 4 ) ) ;
V_483 [ V_201 + 1 ] = 'A' + ( 0x0F & V_484 [ V_200 ] ) ;
V_201 += 2 ;
}
}
static int
F_181 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_343 . V_422 != V_356 ) {
struct V_478 * V_478 = V_2 -> V_28 ;
V_3 = V_478 -> V_49 -> V_485 ( V_478 ,
(struct V_95 * ) & V_2 -> V_343 ,
sizeof( V_2 -> V_343 ) ) ;
if ( V_3 < 0 ) {
struct V_358 * V_359 ;
struct V_364 * V_365 ;
V_359 = (struct V_358 * ) & V_2 -> V_343 ;
V_365 = (struct V_364 * ) & V_2 -> V_343 ;
if ( V_365 -> V_486 == V_363 )
F_5 ( V_59 , L_127 ,
& V_365 -> V_367 , V_3 ) ;
else
F_5 ( V_59 , L_128 ,
& V_359 -> V_361 . V_362 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_182 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_487 * V_488 ;
struct V_489 * V_490 ;
V_488 = F_99 ( sizeof( struct V_487 ) ,
V_116 ) ;
if ( V_488 ) {
V_488 -> V_491 . V_492 . V_493 = 32 ;
if ( V_2 -> V_404 &&
V_2 -> V_404 [ 0 ] != 0 )
F_180 ( V_488 -> V_491 .
V_492 . V_494 ,
V_2 -> V_404 ,
V_348 ) ;
else
F_180 ( V_488 -> V_491 .
V_492 . V_494 ,
V_495 ,
V_348 ) ;
V_488 -> V_491 . V_492 . V_496 = 32 ;
if ( V_2 -> V_403 &&
V_2 -> V_403 [ 0 ] != 0 )
F_180 ( V_488 -> V_491 .
V_492 . V_497 ,
V_2 -> V_403 ,
V_348 ) ;
else
F_180 ( V_488 -> V_491 .
V_492 . V_497 ,
L_129 ,
V_348 ) ;
V_488 -> V_491 . V_492 . V_498 = 0 ;
V_488 -> V_491 . V_492 . V_499 = 0 ;
V_490 = (struct V_489 * ) V_488 ;
V_490 -> V_500 = F_183 ( 0x81000044 ) ;
V_3 = F_184 ( V_2 , V_490 , 0x44 ) ;
F_11 ( V_488 ) ;
F_38 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_369 ;
int V_501 , V_502 ;
struct V_478 * V_478 = V_2 -> V_28 ;
struct V_95 * V_503 ;
V_503 = (struct V_95 * ) & V_2 -> V_96 ;
if ( V_2 -> V_96 . V_422 == V_363 ) {
V_369 = ( (struct V_364 * ) V_503 ) -> V_371 ;
V_501 = sizeof( struct V_364 ) ;
V_502 = V_363 ;
} else {
V_369 = ( (struct V_358 * ) V_503 ) -> V_370 ;
V_501 = sizeof( struct V_358 ) ;
V_502 = V_357 ;
}
if ( V_478 == NULL ) {
V_3 = F_185 ( F_112 ( V_2 ) , V_502 , V_504 ,
V_505 , & V_478 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_130 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_5 ( V_20 , L_131 ) ;
V_2 -> V_28 = V_478 ;
V_478 -> V_480 -> V_506 = V_75 ;
if ( V_502 == V_363 )
F_179 ( V_478 ) ;
else
F_175 ( V_478 ) ;
}
V_3 = F_181 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_478 -> V_480 -> V_507 = 7 * V_53 ;
V_478 -> V_480 -> V_508 = 5 * V_53 ;
if ( V_2 -> V_245 ) {
if ( V_478 -> V_480 -> V_509 < ( 200 * 1024 ) )
V_478 -> V_480 -> V_509 = 200 * 1024 ;
if ( V_478 -> V_480 -> V_510 < ( 140 * 1024 ) )
V_478 -> V_480 -> V_510 = 140 * 1024 ;
}
if ( V_2 -> V_400 ) {
int V_511 = 1 ;
V_3 = F_186 ( V_478 , V_512 , V_513 ,
( char * ) & V_511 , sizeof( V_511 ) ) ;
if ( V_3 )
F_5 ( V_20 , L_132 ,
V_3 ) ;
}
F_5 ( V_20 , L_133 ,
V_478 -> V_480 -> V_509 ,
V_478 -> V_480 -> V_510 , V_478 -> V_480 -> V_507 ) ;
V_3 = V_478 -> V_49 -> V_514 ( V_478 , V_503 , V_501 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_20 , L_134 , V_3 ) ;
F_10 ( V_478 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_369 == F_107 ( V_372 ) )
V_3 = F_182 ( V_2 ) ;
return V_3 ;
}
static int
F_131 ( struct V_1 * V_2 )
{
T_5 * V_369 ;
struct V_364 * V_375 = (struct V_364 * ) & V_2 -> V_96 ;
struct V_358 * V_368 = (struct V_358 * ) & V_2 -> V_96 ;
if ( V_2 -> V_96 . V_422 == V_363 )
V_369 = & V_375 -> V_371 ;
else
V_369 = & V_368 -> V_370 ;
if ( * V_369 == 0 ) {
int V_3 ;
* V_369 = F_107 ( V_97 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_369 = F_107 ( V_372 ) ;
}
return F_18 ( V_2 ) ;
}
void F_187 ( unsigned int V_411 , struct V_9 * V_10 ,
struct V_450 * V_451 , struct V_146 * V_515 )
{
T_7 V_516 = F_188 ( V_10 -> V_517 . V_518 ) ;
if ( V_515 && V_515 -> V_263 ) {
V_10 -> V_517 . V_518 = 0 ;
V_10 -> V_519 = 0 ;
F_5 ( V_20 , L_135 ) ;
return;
} else if ( V_515 )
V_10 -> V_519 = 1 ;
if ( V_10 -> V_519 == 0 ) {
F_5 ( V_20 , L_136 ) ;
return;
}
if ( ! F_189 ( V_411 , V_10 ) ) {
T_7 V_520 = F_188 ( V_10 -> V_517 . V_518 ) ;
F_5 ( V_20 , L_137 , V_520 ) ;
if ( V_515 == NULL ) {
if ( ( V_516 & V_521 ) == 0 )
V_520 &= ~ V_521 ;
if ( ( V_516 & V_522 ) == 0 ) {
if ( V_520 & V_522 )
F_5 ( V_59 , L_138 ) ;
V_520 &= ~ V_522 ;
} else if ( ( V_520 & V_522 ) == 0 ) {
F_5 ( V_59 , L_139 ) ;
F_5 ( V_59 , L_140 ) ;
}
}
if ( V_520 & V_523 )
F_5 ( V_59 , L_141 ) ;
V_520 &= V_524 ;
if ( V_515 && V_515 -> V_296 )
V_520 &= ~ V_521 ;
else if ( V_521 & V_520 ) {
F_5 ( V_20 , L_142 ) ;
if ( V_451 )
V_451 -> V_460 |=
V_525 ;
}
if ( V_515 && V_515 -> V_224 == 0 )
V_520 &= ~ V_522 ;
else if ( V_520 & V_522 ) {
F_5 ( V_20 , L_143 ) ;
if ( V_451 )
V_451 -> V_460 |=
V_526 ;
}
F_5 ( V_20 , L_144 , ( int ) V_520 ) ;
#ifdef F_61
if ( V_520 & V_527 )
F_5 ( V_20 , L_145 ) ;
if ( V_520 & V_528 )
F_5 ( V_20 , L_146 ) ;
if ( V_520 & V_522 )
F_5 ( V_20 , L_147 ) ;
if ( V_520 & V_529 )
F_5 ( V_20 , L_148 ) ;
if ( V_520 & V_521 )
F_5 ( V_20 , L_149 ) ;
if ( V_520 & V_530 )
F_5 ( V_20 , L_150 ) ;
if ( V_520 & V_531 )
F_5 ( V_20 , L_151 ) ;
if ( V_520 & V_532 )
F_5 ( V_20 , L_152 ) ;
if ( V_520 & V_523 )
F_5 ( V_20 , L_153 ) ;
#endif
if ( F_190 ( V_411 , V_10 , V_520 ) ) {
if ( V_515 == NULL ) {
F_5 ( V_20 , L_154 ) ;
} else
F_5 ( V_59 , L_155 ) ;
}
}
}
void F_191 ( struct V_146 * V_533 ,
struct V_450 * V_451 )
{
F_130 ( & V_451 -> V_534 , V_535 ) ;
F_129 ( & V_451 -> V_536 ) ;
V_451 -> V_537 = V_538 ;
V_451 -> V_324 = V_533 -> V_324 ;
V_451 -> V_326 = V_533 -> V_326 ;
V_451 -> V_462 = V_533 -> V_217 ;
V_451 -> V_463 = V_533 -> V_218 ;
V_451 -> V_464 = V_533 -> V_220 ;
V_451 -> V_465 = V_533 -> V_219 ;
F_5 ( V_20 , L_156 ,
V_451 -> V_464 , V_451 -> V_465 ) ;
V_451 -> V_226 = V_533 -> V_226 ;
V_451 -> V_430 = V_533 -> V_430 ;
if ( V_533 -> V_250 )
V_451 -> V_460 |= V_539 ;
if ( V_533 -> V_275 )
V_451 -> V_460 |= V_540 ;
if ( V_533 -> V_225 )
V_451 -> V_460 |= V_541 ;
if ( V_533 -> V_253 )
V_451 -> V_460 |= V_542 ;
if ( V_533 -> V_236 )
V_451 -> V_460 |= V_543 ;
if ( V_533 -> V_256 )
V_451 -> V_460 |= V_544 ;
if ( V_533 -> V_267 )
V_451 -> V_460 |= V_545 ;
if ( V_533 -> V_286 )
V_451 -> V_460 |= V_546 ;
if ( V_533 -> V_273 )
V_451 -> V_460 |= V_547 ;
if ( V_533 -> V_291 )
V_451 -> V_460 |= V_548 ;
if ( V_533 -> V_293 )
V_451 -> V_460 |= V_549 ;
if ( V_533 -> V_230 ) {
V_451 -> V_460 |= V_550 ;
V_451 -> V_551 = V_533 -> V_313 ;
}
if ( V_533 -> V_231 ) {
V_451 -> V_460 |= V_552 ;
V_451 -> V_553 = V_533 -> V_315 ;
}
if ( V_533 -> V_203 )
V_451 -> V_460 |= V_554 ;
if ( V_533 -> V_204 )
V_451 -> V_460 |= V_555 ;
if ( V_533 -> V_278 )
V_451 -> V_460 |= V_556 ;
if ( V_533 -> V_306 )
V_451 -> V_460 |= V_557 ;
if ( V_533 -> V_310 )
V_451 -> V_460 |= ( V_558 |
V_539 ) ;
if ( V_533 -> V_173 )
V_451 -> V_460 |= V_559 ;
if ( V_533 -> V_172 ) {
F_5 ( V_20 , L_157 ) ;
V_451 -> V_460 |= V_560 ;
}
if ( V_533 -> V_308 ) {
if ( V_533 -> V_256 ) {
F_5 ( V_59 , L_158 ) ;
} else {
V_451 -> V_460 |= V_561 ;
}
}
if ( ( V_533 -> V_293 ) && ( V_533 -> V_278 ) )
F_5 ( V_59 , L_159 ) ;
}
static void
F_192 ( struct V_146 * V_396 )
{
F_11 ( V_396 -> V_330 ) ;
F_193 ( V_396 -> V_335 ) ;
F_11 ( V_396 -> V_192 ) ;
F_11 ( V_396 -> V_341 ) ;
F_11 ( V_396 -> V_345 ) ;
F_11 ( V_396 -> V_193 ) ;
}
void
F_194 ( struct V_146 * V_396 )
{
if ( ! V_396 )
return;
F_192 ( V_396 ) ;
F_11 ( V_396 ) ;
}
static char *
F_195 ( const struct V_146 * V_147 ,
const struct V_450 * V_451 )
{
char * V_562 , * V_190 ;
unsigned int V_563 = V_147 -> V_193 ? strlen ( V_147 -> V_193 ) + 1 : 0 ;
unsigned int V_564 = F_93 ( V_147 -> V_192 , V_436 + 1 ) ;
V_562 = F_35 ( V_564 + V_563 + 1 , V_116 ) ;
if ( V_562 == NULL )
return F_71 ( - V_83 ) ;
strncpy ( V_562 , V_147 -> V_192 , V_564 ) ;
V_190 = V_562 + V_564 ;
if ( V_563 ) {
* V_190 = F_196 ( V_451 ) ;
strncpy ( V_190 + 1 , V_147 -> V_193 , V_563 ) ;
V_190 += V_563 ;
}
* V_190 = '\0' ;
F_89 ( V_562 , F_196 ( V_451 ) ) ;
F_5 ( V_20 , L_160 , V_21 , V_562 ) ;
return V_562 ;
}
static int
F_197 ( const unsigned int V_411 , struct V_7 * V_8 ,
struct V_146 * V_396 , struct V_450 * V_451 ,
int V_565 )
{
int V_3 ;
unsigned int V_472 = 0 ;
struct V_473 * V_474 = NULL ;
char * V_562 = NULL , * V_566 = NULL , * V_567 = NULL ;
V_562 = F_195 ( V_396 , V_451 ) ;
if ( F_125 ( V_562 ) )
return F_126 ( V_562 ) ;
V_566 = V_565 ? V_562 + 1 : V_396 -> V_192 + 1 ;
V_3 = F_174 ( V_411 , V_8 , V_566 , V_451 -> V_430 ,
& V_472 , & V_474 ,
V_451 -> V_460 & V_542 ) ;
if ( ! V_3 && V_472 > 0 ) {
char * V_568 = NULL ;
V_567 = F_198 ( V_451 -> V_194 ,
V_562 + 1 , V_474 ,
& V_568 ) ;
F_199 ( V_474 , V_472 ) ;
if ( F_125 ( V_567 ) ) {
V_3 = F_126 ( V_567 ) ;
V_567 = NULL ;
} else {
F_192 ( V_396 ) ;
V_3 = F_200 ( V_396 , V_567 ,
V_568 ) ;
}
F_11 ( V_568 ) ;
F_11 ( V_451 -> V_194 ) ;
V_451 -> V_194 = V_567 ;
}
F_11 ( V_562 ) ;
return V_3 ;
}
static int
F_200 ( struct V_146 * V_396 , char * V_569 ,
const char * V_189 )
{
int V_3 = 0 ;
if ( F_91 ( V_569 , V_189 , V_396 ) )
return - V_140 ;
if ( V_396 -> V_169 ) {
F_5 ( V_20 , L_161 ) ;
F_11 ( V_396 -> V_330 ) ;
V_396 -> V_330 = NULL ;
} else if ( V_396 -> V_330 ) {
F_5 ( V_20 , L_162 , V_396 -> V_330 ) ;
} else {
F_5 ( V_59 , L_163 ) ;
return - V_140 ;
}
if ( V_396 -> V_345 == NULL ) {
V_396 -> V_430 = F_201 () ;
} else {
V_396 -> V_430 = F_202 ( V_396 -> V_345 ) ;
if ( V_396 -> V_430 == NULL ) {
F_5 ( V_59 , L_164 ,
V_396 -> V_345 ) ;
return - V_570 ;
}
}
return V_3 ;
}
struct V_146 *
F_203 ( char * V_569 , const char * V_189 )
{
int V_3 ;
struct V_146 * V_396 ;
V_396 = F_35 ( sizeof( struct V_146 ) , V_116 ) ;
if ( ! V_396 )
return F_71 ( - V_83 ) ;
V_3 = F_200 ( V_396 , V_569 , V_189 ) ;
if ( V_3 ) {
F_194 ( V_396 ) ;
V_396 = F_71 ( V_3 ) ;
}
return V_396 ;
}
int
F_204 ( struct V_450 * V_451 , struct V_146 * V_396 )
{
int V_3 ;
unsigned int V_411 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_562 ;
struct V_444 * V_445 ;
#ifdef F_205
int V_571 = 0 ;
#endif
V_3 = F_206 ( & V_451 -> V_572 , L_165 , V_573 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_205
V_574:
if ( V_571 ) {
if ( V_10 )
F_158 ( V_10 ) ;
else if ( V_8 )
F_140 ( V_8 ) ;
F_153 ( V_411 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_562 = NULL ;
V_445 = NULL ;
V_411 = F_141 () ;
V_2 = F_121 ( V_396 ) ;
if ( F_125 ( V_2 ) ) {
V_3 = F_126 ( V_2 ) ;
F_207 ( & V_451 -> V_572 ) ;
goto V_468;
}
V_8 = F_151 ( V_2 , V_396 ) ;
if ( F_125 ( V_8 ) ) {
V_3 = F_126 ( V_8 ) ;
V_8 = NULL ;
goto V_575;
}
V_10 = F_161 ( V_8 , V_396 ) ;
if ( F_125 ( V_10 ) ) {
V_3 = F_126 ( V_10 ) ;
V_10 = NULL ;
goto V_576;
}
if ( F_208 ( V_10 -> V_8 ) ) {
F_187 ( V_411 , V_10 , V_451 , V_396 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_188 ( V_10 -> V_517 . V_518 ) &
V_523 ) ) {
V_3 = - V_577 ;
goto V_575;
}
} else
V_10 -> V_519 = 0 ;
if ( ! V_10 -> V_578 && V_2 -> V_49 -> V_579 )
V_2 -> V_49 -> V_579 ( V_411 , V_10 ) ;
V_451 -> V_326 = V_2 -> V_49 -> V_580 ( V_10 , V_396 ) ;
V_451 -> V_324 = V_2 -> V_49 -> V_581 ( V_10 , V_396 ) ;
V_451 -> V_572 . V_582 = V_451 -> V_324 / V_583 ;
V_576:
#ifdef F_205
if ( V_571 == 0 ) {
int V_584 = F_197 ( V_411 , V_8 , V_396 , V_451 ,
false ) ;
if ( ! V_584 ) {
V_571 ++ ;
goto V_574;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_49 -> V_585 ) {
V_3 = - V_55 ;
goto V_575;
}
V_562 = F_209 ( V_396 , V_451 , V_10 ) ;
if ( V_562 == NULL ) {
V_3 = - V_83 ;
goto V_575;
}
V_3 = V_2 -> V_49 -> V_585 ( V_411 , V_10 , V_451 ,
V_562 ) ;
if ( V_3 != 0 && V_3 != - V_586 ) {
F_11 ( V_562 ) ;
goto V_575;
}
F_11 ( V_562 ) ;
}
if ( V_3 == - V_586 ) {
#ifdef F_205
if ( V_571 > V_587 ) {
V_3 = - V_588 ;
goto V_575;
}
V_3 = F_197 ( V_411 , V_8 , V_396 , V_451 , true ) ;
if ( ! V_3 ) {
V_571 ++ ;
goto V_574;
}
goto V_575;
#else
V_3 = - V_589 ;
#endif
}
if ( V_3 )
goto V_575;
V_445 = F_99 ( sizeof *V_445 , V_116 ) ;
if ( V_445 == NULL ) {
V_3 = - V_83 ;
goto V_575;
}
V_445 -> V_590 = V_8 -> V_217 ;
V_445 -> V_591 = V_10 ;
V_445 -> V_449 = V_38 ;
F_210 ( V_592 , & V_445 -> V_448 ) ;
F_210 ( V_447 , & V_445 -> V_448 ) ;
V_451 -> V_452 = V_445 ;
F_2 ( & V_451 -> V_536 ) ;
F_211 ( & V_451 -> V_537 , V_445 ) ;
F_3 ( & V_451 -> V_536 ) ;
F_24 ( V_57 , & V_451 -> V_534 ,
V_593 ) ;
V_575:
if ( V_3 ) {
if ( V_10 )
F_158 ( V_10 ) ;
else if ( V_8 )
F_140 ( V_8 ) ;
else
F_115 ( V_2 ) ;
F_207 ( & V_451 -> V_572 ) ;
}
V_468:
F_153 ( V_411 ) ;
return V_3 ;
}
int
F_212 ( const unsigned int V_411 , struct V_7 * V_8 ,
const char * V_594 , struct V_9 * V_10 ,
const struct V_470 * V_471 )
{
struct V_489 * V_595 ;
struct V_489 * V_596 ;
T_8 * V_597 ;
T_9 * V_598 ;
unsigned char * V_599 ;
int V_3 = 0 ;
int V_78 ;
T_10 V_600 , V_601 ;
if ( V_8 == NULL )
return - V_602 ;
V_595 = F_26 () ;
if ( V_595 == NULL )
return - V_83 ;
V_596 = V_595 ;
F_213 ( V_595 , V_603 ,
NULL , 4 ) ;
V_595 -> V_604 = F_214 ( V_8 -> V_2 ) ;
V_595 -> V_605 = V_8 -> V_606 ;
V_597 = ( T_8 * ) V_595 ;
V_598 = ( T_9 * ) V_596 ;
V_597 -> V_607 = 0xFF ;
V_597 -> V_441 = F_215 ( V_608 ) ;
V_599 = & V_597 -> V_609 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_388 & V_610 ) ) {
V_597 -> V_611 = F_215 ( 1 ) ;
* V_599 = 0 ;
V_599 ++ ;
} else {
V_597 -> V_611 = F_215 ( V_612 ) ;
#ifdef F_84
if ( ( V_380 & V_167 ) &&
( V_8 -> V_2 -> V_381 == V_382 ) )
F_216 ( V_10 -> V_335 , V_8 -> V_2 -> V_613 ,
V_8 -> V_2 -> V_388 &
V_614 ? true : false ,
V_599 ) ;
else
#endif
V_3 = F_217 ( V_10 -> V_335 , V_8 -> V_2 -> V_613 ,
V_599 , V_471 ) ;
V_599 += V_612 ;
if ( V_8 -> V_615 & V_616 ) {
* V_599 = 0 ;
V_599 ++ ;
}
}
if ( V_8 -> V_2 -> V_388 &
( V_389 | V_390 ) )
V_595 -> V_617 |= V_618 ;
if ( V_8 -> V_615 & V_619 ) {
V_595 -> V_617 |= V_620 ;
}
if ( V_8 -> V_615 & V_621 ) {
V_595 -> V_617 |= V_622 ;
}
if ( V_8 -> V_615 & V_616 ) {
V_595 -> V_617 |= V_623 ;
V_78 =
F_218 ( ( V_624 * ) V_599 , V_594 ,
6 *
( + 256 ) , V_471 ) ;
V_599 += 2 * V_78 ;
V_599 += 2 ;
} else {
strcpy ( V_599 , V_594 ) ;
V_599 += strlen ( V_594 ) + 1 ;
}
strcpy ( V_599 , L_166 ) ;
V_599 += strlen ( L_166 ) ;
V_599 += 1 ;
V_601 = V_599 - & V_597 -> V_609 [ 0 ] ;
V_597 -> V_625 . V_500 = F_183 ( F_219 (
V_597 -> V_625 . V_500 ) + V_601 ) ;
V_597 -> V_626 = F_215 ( V_601 ) ;
V_3 = F_220 ( V_411 , V_8 , V_595 , V_596 , & V_78 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_627 ;
V_10 -> V_434 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_628 = V_596 -> V_629 ;
V_599 = F_221 ( V_596 ) ;
V_600 = F_222 ( V_596 ) ;
V_78 = F_93 ( V_599 , V_600 - 2 ) ;
if ( V_595 -> V_617 & V_623 )
V_627 = true ;
else
V_627 = false ;
if ( V_78 == 3 ) {
if ( ( V_599 [ 0 ] == 'I' ) && ( V_599 [ 1 ] == 'P' ) &&
( V_599 [ 2 ] == 'C' ) ) {
F_5 ( V_20 , L_167 ) ;
V_10 -> V_578 = 1 ;
}
} else if ( V_78 == 2 ) {
if ( ( V_599 [ 0 ] == 'A' ) && ( V_599 [ 1 ] == ':' ) ) {
F_5 ( V_20 , L_168 ) ;
}
}
V_599 += V_78 + 1 ;
V_600 -= ( V_78 + 1 ) ;
strncpy ( V_10 -> V_435 , V_594 , V_436 ) ;
F_11 ( V_10 -> V_630 ) ;
V_10 -> V_630 = F_223 ( V_599 ,
V_600 , V_627 ,
V_471 ) ;
F_5 ( V_20 , L_169 , V_10 -> V_630 ) ;
if ( ( V_596 -> V_631 == 3 ) ||
( V_596 -> V_631 == 7 ) )
V_10 -> V_441 = F_224 ( V_598 -> V_632 ) ;
else
V_10 -> V_441 = 0 ;
F_5 ( V_20 , L_170 , V_10 -> V_441 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_596 -> V_629 ;
}
F_63 ( V_595 ) ;
return V_3 ;
}
void
F_225 ( struct V_450 * V_451 )
{
struct V_633 * V_634 = & V_451 -> V_537 ;
struct V_635 * V_636 ;
struct V_444 * V_445 ;
F_117 ( & V_451 -> V_534 ) ;
F_2 ( & V_451 -> V_536 ) ;
while ( ( V_636 = F_226 ( V_634 ) ) ) {
V_445 = F_227 ( V_636 , struct V_444 , V_637 ) ;
F_173 ( V_445 ) ;
F_228 ( V_447 , & V_445 -> V_448 ) ;
F_229 ( V_636 , V_634 ) ;
F_3 ( & V_451 -> V_536 ) ;
F_164 ( V_445 ) ;
F_2 ( & V_451 -> V_536 ) ;
}
F_3 ( & V_451 -> V_536 ) ;
F_207 ( & V_451 -> V_572 ) ;
F_11 ( V_451 -> V_194 ) ;
F_230 ( V_451 -> V_430 ) ;
F_11 ( V_451 ) ;
}
int
F_152 ( const unsigned int V_411 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_49 -> V_50 || ! V_2 -> V_49 -> V_638 )
return - V_55 ;
if ( ! V_2 -> V_49 -> V_50 ( V_2 ) )
return 0 ;
F_231 ( V_2 , 1 ) ;
V_3 = V_2 -> V_49 -> V_638 ( V_411 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_639 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_154 ( const unsigned int V_411 , struct V_7 * V_8 ,
struct V_470 * V_640 )
{
int V_3 = - V_55 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_30 = 0 ;
V_8 -> V_615 = V_2 -> V_615 ;
if ( V_641 == 0 )
V_8 -> V_615 &= ( ~ V_2 -> V_179 -> F_208 ) ;
F_5 ( V_20 , L_171 ,
V_2 -> V_388 , V_2 -> V_615 , V_2 -> V_642 ) ;
if ( V_2 -> V_49 -> V_643 )
V_3 = V_2 -> V_49 -> V_643 ( V_411 , V_8 , V_640 ) ;
if ( V_3 ) {
F_5 ( V_59 , L_172 , V_3 ) ;
} else {
F_8 ( & V_2 -> V_27 ) ;
if ( ! V_2 -> V_33 ) {
V_2 -> V_34 . V_35 = V_8 -> V_644 . V_35 ;
V_2 -> V_34 . V_36 = V_8 -> V_644 . V_36 ;
V_2 -> V_32 = 0x2 ;
V_2 -> V_33 = true ;
V_8 -> V_644 . V_35 = NULL ;
}
F_12 ( & V_2 -> V_27 ) ;
F_5 ( V_20 , L_173 ) ;
F_2 ( & V_14 ) ;
V_8 -> V_412 = V_62 ;
V_8 -> V_24 = false ;
F_3 ( & V_14 ) ;
}
F_11 ( V_8 -> V_644 . V_35 ) ;
V_8 -> V_644 . V_35 = NULL ;
V_8 -> V_644 . V_36 = 0 ;
F_11 ( V_8 -> V_645 ) ;
V_8 -> V_645 = NULL ;
return V_3 ;
}
static int
F_232 ( struct V_146 * V_147 , struct V_7 * V_8 )
{
switch ( V_8 -> V_2 -> V_381 ) {
case V_386 :
V_147 -> V_151 = V_646 ;
return 0 ;
case V_384 :
V_147 -> V_151 = V_647 ;
break;
case V_385 :
V_147 -> V_151 = V_648 ;
break;
case V_387 :
V_147 -> V_151 = V_649 ;
break;
case V_382 :
V_147 -> V_151 = V_650 ;
break;
}
return F_144 ( V_147 , V_8 ) ;
}
static struct V_9 *
F_233 ( struct V_450 * V_451 , T_3 V_651 )
{
int V_3 ;
struct V_9 * V_652 = F_234 ( V_451 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_146 * V_515 ;
V_515 = F_99 ( sizeof( * V_515 ) , V_116 ) ;
if ( V_515 == NULL )
return F_71 ( - V_83 ) ;
V_515 -> V_430 = V_451 -> V_430 ;
V_515 -> V_217 = V_651 ;
V_515 -> V_216 = V_651 ;
V_515 -> V_192 = V_652 -> V_435 ;
V_515 -> V_247 = V_652 -> V_247 ;
V_515 -> V_265 = V_652 -> V_265 ;
V_515 -> V_299 = V_652 -> V_299 ;
V_515 -> V_263 = ! V_652 -> V_519 ;
V_3 = F_232 ( V_515 , V_652 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_71 ( V_3 ) ;
goto V_468;
}
F_2 ( & V_22 ) ;
++ V_652 -> V_8 -> V_2 -> V_393 ;
F_3 ( & V_22 ) ;
V_8 = F_151 ( V_652 -> V_8 -> V_2 , V_515 ) ;
if ( F_125 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_115 ( V_652 -> V_8 -> V_2 ) ;
goto V_468;
}
V_10 = F_161 ( V_8 , V_515 ) ;
if ( F_125 ( V_10 ) ) {
F_140 ( V_8 ) ;
goto V_468;
}
if ( F_208 ( V_8 ) )
F_187 ( 0 , V_10 , NULL , V_515 ) ;
V_468:
F_11 ( V_515 -> V_330 ) ;
F_11 ( V_515 -> V_335 ) ;
F_11 ( V_515 ) ;
return V_10 ;
}
struct V_9 *
F_234 ( struct V_450 * V_451 )
{
return F_167 ( F_168 ( V_451 ) ) ;
}
static int
F_235 ( void * V_653 )
{
F_68 () ;
return F_67 ( V_125 ) ? - V_88 : 0 ;
}
static struct V_444 *
F_236 ( struct V_633 * V_634 , T_3 V_144 )
{
struct V_635 * V_636 = V_634 -> V_635 ;
struct V_444 * V_445 ;
while ( V_636 ) {
V_445 = F_227 ( V_636 , struct V_444 , V_637 ) ;
if ( F_237 ( V_445 -> V_590 , V_144 ) )
V_636 = V_636 -> V_654 ;
else if ( F_238 ( V_445 -> V_590 , V_144 ) )
V_636 = V_636 -> V_655 ;
else
return V_445 ;
}
return NULL ;
}
static void
F_211 ( struct V_633 * V_634 , struct V_444 * V_656 )
{
struct V_635 * * V_65 = & ( V_634 -> V_635 ) , * V_657 = NULL ;
struct V_444 * V_445 ;
while ( * V_65 ) {
V_445 = F_227 ( * V_65 , struct V_444 , V_637 ) ;
V_657 = * V_65 ;
if ( F_237 ( V_445 -> V_590 , V_656 -> V_590 ) )
V_65 = & ( ( * V_65 ) -> V_654 ) ;
else
V_65 = & ( ( * V_65 ) -> V_655 ) ;
}
F_239 ( & V_656 -> V_637 , V_657 , V_65 ) ;
F_240 ( & V_656 -> V_637 , V_634 ) ;
}
struct V_444 *
F_241 ( struct V_450 * V_451 )
{
int V_658 ;
T_3 V_651 = F_242 () ;
struct V_444 * V_445 , * V_659 ;
if ( ! ( V_451 -> V_460 & V_558 ) )
return F_173 ( F_168 ( V_451 ) ) ;
F_2 ( & V_451 -> V_536 ) ;
V_445 = F_236 ( & V_451 -> V_537 , V_651 ) ;
if ( V_445 )
F_173 ( V_445 ) ;
F_3 ( & V_451 -> V_536 ) ;
if ( V_445 == NULL ) {
V_659 = F_99 ( sizeof( * V_445 ) , V_116 ) ;
if ( V_659 == NULL )
return F_71 ( - V_83 ) ;
V_659 -> V_590 = V_651 ;
V_659 -> V_591 = F_71 ( - V_577 ) ;
F_210 ( V_660 , & V_659 -> V_448 ) ;
F_210 ( V_447 , & V_659 -> V_448 ) ;
F_173 ( V_659 ) ;
F_2 ( & V_451 -> V_536 ) ;
V_445 = F_236 ( & V_451 -> V_537 , V_651 ) ;
if ( V_445 ) {
F_173 ( V_445 ) ;
F_3 ( & V_451 -> V_536 ) ;
F_11 ( V_659 ) ;
goto V_661;
}
V_445 = V_659 ;
F_211 ( & V_451 -> V_537 , V_445 ) ;
F_3 ( & V_451 -> V_536 ) ;
} else {
V_661:
V_658 = F_243 ( & V_445 -> V_448 , V_660 ,
F_235 ,
V_134 ) ;
if ( V_658 ) {
F_164 ( V_445 ) ;
return F_71 ( V_658 ) ;
}
if ( ! F_125 ( V_445 -> V_591 ) )
return V_445 ;
if ( F_23 ( V_38 , V_445 -> V_449 + V_662 ) ) {
F_164 ( V_445 ) ;
return F_71 ( - V_577 ) ;
}
if ( F_244 ( V_660 , & V_445 -> V_448 ) )
goto V_661;
}
V_445 -> V_591 = F_233 ( V_451 , V_651 ) ;
F_228 ( V_660 , & V_445 -> V_448 ) ;
F_245 ( & V_445 -> V_448 , V_660 ) ;
if ( F_125 ( V_445 -> V_591 ) ) {
F_164 ( V_445 ) ;
return F_71 ( - V_577 ) ;
}
return V_445 ;
}
static void
V_535 ( struct V_46 * V_47 )
{
struct V_450 * V_451 = F_22 ( V_47 , struct V_450 ,
V_534 . V_47 ) ;
struct V_633 * V_634 = & V_451 -> V_537 ;
struct V_635 * V_636 = F_226 ( V_634 ) ;
struct V_635 * V_5 ;
struct V_444 * V_445 ;
F_2 ( & V_451 -> V_536 ) ;
V_636 = F_226 ( V_634 ) ;
while ( V_636 != NULL ) {
V_5 = V_636 ;
V_636 = F_246 ( V_5 ) ;
V_445 = F_227 ( V_5 , struct V_444 , V_637 ) ;
if ( F_166 ( V_592 , & V_445 -> V_448 ) ||
F_60 ( & V_445 -> V_446 ) != 0 ||
F_30 ( V_445 -> V_449 + V_593 , V_38 ) )
continue;
F_173 ( V_445 ) ;
F_228 ( V_447 , & V_445 -> V_448 ) ;
F_229 ( V_5 , V_634 ) ;
F_3 ( & V_451 -> V_536 ) ;
F_164 ( V_445 ) ;
F_2 ( & V_451 -> V_536 ) ;
}
F_3 ( & V_451 -> V_536 ) ;
F_24 ( V_57 , & V_451 -> V_534 ,
V_593 ) ;
}
