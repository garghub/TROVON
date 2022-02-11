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
F_8 ( & V_2 -> V_27 ) ;
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
F_12 ( & V_2 -> V_27 ) ;
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
V_78 == - V_89 ||
V_78 == - V_90 ) {
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
F_39 ( struct V_1 * V_2 , char * V_91 ,
unsigned int V_77 )
{
struct V_64 V_66 ;
V_66 . V_72 = V_91 ;
V_66 . V_70 = V_77 ;
return F_36 ( V_2 , & V_66 , 1 , V_77 ) ;
}
static bool
F_40 ( struct V_1 * V_2 , unsigned char type )
{
switch ( type ) {
case V_92 :
return true ;
case V_93 :
F_5 ( V_20 , L_15 ) ;
break;
case V_94 :
F_5 ( V_20 , L_16 ) ;
break;
case V_95 :
F_5 ( V_20 , L_17 ) ;
F_19 ( 1000 ) ;
F_41 ( (struct V_96 * ) & V_2 -> V_97 , V_98 ) ;
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
F_42 ( struct V_11 * V_99 , bool V_100 )
{
#ifdef F_43
V_99 -> V_101 = V_38 ;
#endif
F_2 ( & V_14 ) ;
if ( ! V_100 )
V_99 -> V_40 = V_102 ;
else
V_99 -> V_40 = V_103 ;
F_16 ( & V_99 -> V_39 ) ;
F_3 ( & V_14 ) ;
}
static void
F_44 ( struct V_11 * V_99 , struct V_1 * V_2 ,
char * V_91 , int V_100 )
{
if ( V_2 -> V_49 -> V_104 &&
V_2 -> V_49 -> V_104 ( V_99 , V_2 , V_91 , V_100 ) )
return;
V_99 -> V_105 = V_91 ;
V_99 -> V_60 = V_2 -> V_60 ;
if ( ! V_99 -> V_106 ) {
if ( V_2 -> V_60 )
V_2 -> V_58 = NULL ;
else
V_2 -> V_61 = NULL ;
}
F_42 ( V_99 , V_100 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_78 ;
F_2 ( & V_22 ) ;
F_16 ( & V_2 -> V_107 ) ;
F_3 ( & V_22 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_46 ( & V_2 -> V_63 ) ;
F_2 ( & V_2 -> V_108 ) ;
if ( V_2 -> V_109 <= 0 )
V_2 -> V_109 = 1 ;
F_3 ( & V_2 -> V_108 ) ;
F_46 ( & V_2 -> V_110 ) ;
F_19 ( 125 ) ;
if ( V_2 -> V_28 ) {
F_10 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
}
if ( ! F_47 ( & V_2 -> V_111 ) ) {
struct V_4 V_112 ;
struct V_11 * V_12 ;
struct V_4 * V_5 , * V_6 ;
F_13 ( & V_112 ) ;
F_2 ( & V_14 ) ;
F_14 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_7 ( V_5 , struct V_11 , V_39 ) ;
F_5 ( V_20 , L_19 , V_12 -> V_99 ) ;
V_12 -> V_40 = V_113 ;
F_15 ( & V_12 -> V_39 , & V_112 ) ;
}
F_3 ( & V_14 ) ;
F_14 (tmp, tmp2, &dispose_list) {
V_12 = F_7 ( V_5 , struct V_11 , V_39 ) ;
F_5 ( V_20 , L_20 , V_12 -> V_99 ) ;
F_16 ( & V_12 -> V_39 ) ;
V_12 -> V_43 ( V_12 ) ;
}
F_19 ( 125 ) ;
}
if ( ! F_47 ( & V_2 -> V_111 ) ) {
F_5 ( V_20 , L_21 ) ;
F_19 ( 46000 ) ;
}
F_11 ( V_2 -> V_56 ) ;
F_11 ( V_2 -> V_66 ) ;
F_11 ( V_2 ) ;
V_78 = F_48 ( & V_114 ) ;
if ( V_78 > 0 )
F_49 ( V_115 , V_78 + V_116 ,
V_117 ) ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_11 * V_99 )
{
int V_78 ;
char * V_91 = V_2 -> V_61 ;
unsigned int V_118 = F_51 ( V_91 ) ;
if ( V_118 > V_119 + F_52 ( V_2 ) - 4 ) {
F_5 ( V_59 , L_22 , V_118 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
return - V_86 ;
}
if ( V_118 > V_120 - 4 ) {
V_2 -> V_60 = true ;
memcpy ( V_2 -> V_58 , V_91 , V_2 -> V_79 ) ;
V_91 = V_2 -> V_58 ;
}
V_78 = F_39 ( V_2 , V_91 + F_27 ( V_2 ) - 1 ,
V_118 - F_27 ( V_2 ) + 1 + 4 ) ;
if ( V_78 < 0 )
return V_78 ;
V_2 -> V_79 += V_78 ;
F_53 ( V_91 , V_2 -> V_79 ) ;
V_78 = V_2 -> V_49 -> V_121 ( V_91 , V_2 -> V_79 ) ;
if ( V_78 != 0 )
F_54 ( L_23 , V_91 ,
F_55 (unsigned int, server->total_read, 48 ) ) ;
if ( V_2 -> V_49 -> V_122 &&
V_2 -> V_49 -> V_122 ( V_91 , V_2 , V_78 ) )
return - 1 ;
if ( ! V_99 )
return V_78 ;
F_44 ( V_99 , V_2 , V_91 , V_78 ) ;
return 0 ;
}
static int
F_56 ( void * V_123 )
{
int V_78 ;
struct V_1 * V_2 = V_123 ;
unsigned int V_118 ;
char * V_91 = NULL ;
struct V_124 * V_125 = NULL ;
struct V_11 * V_12 ;
V_126 -> V_30 |= V_127 ;
F_5 ( V_20 , L_24 , F_57 ( V_126 ) ) ;
V_78 = F_58 ( & V_114 ) ;
if ( V_78 > 1 )
F_49 ( V_115 , V_78 + V_116 ,
V_117 ) ;
F_59 () ;
while ( V_2 -> V_15 != V_16 ) {
if ( F_17 () )
continue;
if ( ! F_25 ( V_2 ) )
continue;
V_2 -> V_60 = false ;
V_91 = V_2 -> V_61 ;
V_118 = 4 ;
V_78 = F_39 ( V_2 , V_91 , V_118 ) ;
if ( V_78 < 0 )
continue;
V_2 -> V_79 = V_78 ;
V_118 = F_51 ( V_91 ) ;
F_5 ( V_20 , L_25 , V_118 ) ;
if ( ! F_40 ( V_2 , V_91 [ 0 ] ) )
continue;
if ( V_118 < F_27 ( V_2 ) - 1 - 4 ) {
F_5 ( V_59 , L_26 ,
V_118 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
continue;
}
V_78 = F_39 ( V_2 , V_91 + 4 ,
F_27 ( V_2 ) - 1 - 4 ) ;
if ( V_78 < 0 )
continue;
V_2 -> V_79 += V_78 ;
V_12 = V_2 -> V_49 -> V_128 ( V_2 , V_91 ) ;
if ( ! V_12 || ! V_12 -> V_129 )
V_78 = F_50 ( V_2 , V_12 ) ;
else
V_78 = V_12 -> V_129 ( V_2 , V_12 ) ;
if ( V_78 < 0 )
continue;
if ( V_2 -> V_60 )
V_91 = V_2 -> V_58 ;
V_2 -> V_37 = V_38 ;
if ( V_12 != NULL ) {
if ( ! V_12 -> V_106 || V_12 -> V_130 )
V_12 -> V_43 ( V_12 ) ;
} else if ( ! V_2 -> V_49 -> V_131 ||
! V_2 -> V_49 -> V_131 ( V_91 , V_2 ) ) {
F_5 ( V_59 , L_27 ,
F_60 ( & V_132 ) ) ;
F_54 ( L_28 , V_91 ,
F_27 ( V_2 ) ) ;
#ifdef F_61
if ( V_2 -> V_49 -> V_133 )
V_2 -> V_49 -> V_133 ( V_91 ) ;
F_62 ( V_2 ) ;
#endif
}
}
F_63 ( V_2 -> V_58 ) ;
if ( V_2 -> V_61 )
F_64 ( V_2 -> V_61 ) ;
V_125 = F_65 ( & V_2 -> V_134 , NULL ) ;
F_45 ( V_2 ) ;
if ( ! V_125 ) {
F_66 ( V_135 ) ;
while ( ! F_67 ( V_126 ) ) {
F_68 () ;
F_66 ( V_135 ) ;
}
F_66 ( V_136 ) ;
}
F_69 ( 0 ) ;
}
static char *
F_70 ( const char * V_137 )
{
const char * V_138 ;
char * V_139 , * V_140 ;
unsigned int V_36 ;
V_138 = V_137 + 2 ;
V_140 = strchr ( V_138 , '\\' ) ;
if ( ! V_140 )
return F_71 ( - V_141 ) ;
V_36 = V_140 - V_138 ;
V_139 = F_35 ( ( V_36 + 1 ) , V_117 ) ;
if ( V_139 == NULL )
return F_71 ( - V_83 ) ;
memcpy ( V_139 , V_138 , V_36 ) ;
V_139 [ V_36 ] = '\0' ;
return V_139 ;
}
static int F_72 ( T_2 args [] , unsigned long * V_142 )
{
int V_3 ;
char * string ;
string = F_73 ( args ) ;
if ( string == NULL )
return - V_83 ;
V_3 = F_74 ( string , 0 , V_142 ) ;
F_11 ( string ) ;
return V_3 ;
}
static int F_75 ( T_2 args [] , T_3 * V_143 )
{
unsigned long V_144 ;
T_3 V_145 ;
int V_3 ;
V_3 = F_72 ( args , & V_144 ) ;
if ( V_3 )
return V_3 ;
V_145 = F_76 ( F_77 () , V_144 ) ;
if ( ! F_78 ( V_145 ) )
return - V_141 ;
* V_143 = V_145 ;
return 0 ;
}
static int F_79 ( T_2 args [] , T_4 * V_143 )
{
unsigned long V_144 ;
T_4 V_146 ;
int V_3 ;
V_3 = F_72 ( args , & V_144 ) ;
if ( V_3 )
return V_3 ;
V_146 = F_80 ( F_77 () , V_144 ) ;
if ( ! F_81 ( V_146 ) )
return - V_141 ;
* V_143 = V_146 ;
return 0 ;
}
static int F_82 ( char * V_144 ,
struct V_147 * V_148 )
{
T_2 args [ V_149 ] ;
V_148 -> V_150 = V_151 ;
V_148 -> V_152 = false ;
switch ( F_83 ( V_144 , V_153 , args ) ) {
case V_154 :
F_5 ( V_59 , L_29 ) ;
return 1 ;
case V_155 :
V_148 -> V_152 = true ;
case V_156 :
V_148 -> V_150 = V_157 ;
break;
case V_158 :
V_148 -> V_152 = true ;
case V_159 :
V_148 -> V_150 = V_160 ;
break;
case V_161 :
V_148 -> V_152 = true ;
case V_162 :
V_148 -> V_150 = V_163 ;
break;
case V_164 :
V_148 -> V_152 = true ;
case V_165 :
V_148 -> V_150 = V_166 ;
break;
#ifdef F_84
case V_167 :
V_148 -> V_150 = V_168 ;
break;
#endif
case V_169 :
V_148 -> V_170 = 1 ;
break;
default:
F_5 ( V_59 , L_30 , V_144 ) ;
return 1 ;
}
return 0 ;
}
static int
F_85 ( char * V_144 , struct V_147 * V_148 )
{
T_2 args [ V_149 ] ;
switch ( F_83 ( V_144 , V_171 , args ) ) {
case V_172 :
V_148 -> V_173 = false ;
V_148 -> V_174 = false ;
break;
case V_175 :
V_148 -> V_173 = false ;
V_148 -> V_174 = true ;
break;
case V_176 :
V_148 -> V_173 = true ;
V_148 -> V_174 = false ;
break;
default:
F_5 ( V_59 , L_31 , V_144 ) ;
return 1 ;
}
return 0 ;
}
static int
F_86 ( char * V_144 , struct V_147 * V_148 )
{
T_2 args [ V_149 ] ;
switch ( F_83 ( V_144 , V_177 , args ) ) {
case V_178 :
V_148 -> V_49 = & V_179 ;
V_148 -> V_180 = & V_181 ;
break;
#ifdef F_4
case V_182 :
V_148 -> V_49 = & V_183 ;
V_148 -> V_180 = & V_184 ;
break;
case V_185 :
V_148 -> V_49 = & V_186 ;
V_148 -> V_180 = & V_187 ;
break;
case V_188 :
V_148 -> V_49 = & V_189 ;
V_148 -> V_180 = & V_190 ;
break;
case V_191 :
V_148 -> V_49 = & V_189 ;
V_148 -> V_180 = & V_192 ;
break;
#endif
default:
F_5 ( V_59 , L_32 , V_144 ) ;
return 1 ;
}
return 0 ;
}
static int
F_87 ( const char * V_193 , struct V_147 * V_148 )
{
char * V_194 ;
const char * V_195 = L_33 ;
T_1 V_36 ;
V_36 = strspn ( V_193 , V_195 ) ;
if ( V_36 != 2 )
return - V_141 ;
V_194 = strpbrk ( V_193 + 2 , V_195 ) ;
if ( ! V_194 )
return - V_141 ;
++ V_194 ;
V_36 = strcspn ( V_194 , V_195 ) ;
V_194 += V_36 ;
V_148 -> V_196 = F_88 ( V_193 , V_194 - V_193 , V_117 ) ;
if ( ! V_148 -> V_196 )
return - V_83 ;
F_89 ( V_148 -> V_196 , '\\' ) ;
if ( ! * V_194 ++ || ! * V_194 )
return 0 ;
V_148 -> V_197 = F_90 ( V_194 , V_117 ) ;
if ( ! V_148 -> V_197 )
return - V_83 ;
return 0 ;
}
static int
F_91 ( const char * V_198 , const char * V_193 ,
struct V_147 * V_148 )
{
char * V_199 , * V_200 ;
char * V_201 = NULL , * V_202 ;
unsigned int V_203 , V_204 , V_205 ;
char V_206 [ 2 ] ;
short int V_207 = - 1 ;
short int V_208 = - 1 ;
bool V_209 = false ;
bool V_210 = false ;
bool V_211 = false ;
char * V_212 = NULL ;
char * V_213 = F_92 () -> V_213 ;
char * string = NULL ;
char * V_214 , * V_144 ;
char V_140 ;
bool V_215 = false ;
unsigned short V_216 = 0 ;
struct V_96 * V_97 = (struct V_96 * ) & V_148 -> V_97 ;
V_206 [ 0 ] = ',' ;
V_206 [ 1 ] = 0 ;
V_140 = V_206 [ 0 ] ;
memset ( V_148 , 0 , sizeof( * V_148 ) ) ;
memset ( V_148 -> V_217 , 0x20 , V_218 ) ;
for ( V_204 = 0 ; V_204 < F_93 ( V_213 , V_218 ) ; V_204 ++ )
V_148 -> V_217 [ V_204 ] = toupper ( V_213 [ V_204 ] ) ;
V_148 -> V_217 [ V_218 ] = 0 ;
V_148 -> V_219 [ 0 ] = 0 ;
V_148 -> V_220 = F_94 () ;
V_148 -> V_221 = F_94 () ;
V_148 -> V_222 = F_95 () ;
V_148 -> V_223 = V_148 -> V_224 = V_225 | V_226 | V_227 ;
V_148 -> V_228 = 1 ;
V_148 -> V_229 = 1 ;
V_148 -> V_174 = true ;
V_148 -> V_230 = V_231 ;
V_148 -> V_49 = & V_179 ;
V_148 -> V_180 = & V_181 ;
if ( ! V_198 )
goto V_232;
V_201 = F_88 ( V_198 , V_233 , V_117 ) ;
if ( ! V_201 )
goto V_232;
V_202 = V_201 ;
V_200 = V_202 + strlen ( V_202 ) ;
if ( strncmp ( V_202 , L_34 , 4 ) == 0 ) {
if ( V_202 [ 4 ] != 0 ) {
V_206 [ 0 ] = V_202 [ 4 ] ;
V_202 += 5 ;
} else {
F_5 ( V_20 , L_35 ) ;
}
}
V_148 -> V_234 = false ;
V_148 -> V_235 = false ;
switch ( F_87 ( V_193 , V_148 ) ) {
case 0 :
break;
case - V_83 :
F_5 ( V_59 , L_36 ) ;
goto V_232;
case - V_141 :
F_5 ( V_59 , L_37 ) ;
goto V_232;
default:
F_5 ( V_59 , L_38 ) ;
goto V_232;
}
while ( ( V_199 = F_96 ( & V_202 , V_206 ) ) != NULL ) {
T_2 args [ V_149 ] ;
unsigned long V_142 ;
int V_236 ;
if ( ! * V_199 )
continue;
V_236 = F_83 ( V_199 , V_237 , args ) ;
switch ( V_236 ) {
case V_238 :
break;
case V_239 :
V_148 -> V_240 = 0 ;
break;
case V_241 :
V_148 -> V_240 = 1 ;
break;
case V_242 :
V_207 = 1 ;
break;
case V_243 :
V_207 = 0 ;
break;
case V_244 :
V_208 = 1 ;
break;
case V_245 :
V_208 = 0 ;
break;
case V_246 :
V_148 -> V_247 = 1 ;
break;
case V_248 :
V_148 -> V_249 = 1 ;
break;
case V_250 :
V_148 -> V_251 = 1 ;
break;
case V_252 :
V_148 -> V_251 = 0 ;
break;
case V_253 :
V_148 -> V_254 = 0 ;
break;
case V_255 :
V_148 -> V_254 = 1 ;
break;
case V_256 :
V_148 -> V_257 = 1 ;
break;
case V_258 :
V_148 -> V_257 = 0 ;
break;
case V_259 :
V_148 -> V_260 = 1 ;
break;
case V_261 :
V_148 -> V_260 = 0 ;
break;
case V_262 :
V_148 -> V_263 = 1 ;
break;
case V_264 :
V_148 -> V_228 = 1 ;
break;
case V_265 :
V_148 -> V_228 = 0 ;
break;
case V_266 :
V_148 -> V_267 = 1 ;
break;
case V_268 :
V_148 -> V_269 = 1 ;
break;
case V_270 :
V_148 -> V_271 = 0 ;
break;
case V_272 :
V_148 -> V_271 = 1 ;
if ( V_148 -> V_224 ==
( V_273 & ~ ( V_274 | V_275 ) ) )
V_148 -> V_224 = V_273 ;
break;
case V_276 :
V_148 -> V_277 = 1 ;
break;
case V_278 :
V_148 -> V_279 = 1 ;
break;
case V_280 :
V_148 -> V_279 = 0 ;
break;
case V_281 :
V_148 -> V_282 = true ;
break;
case V_283 :
V_148 -> V_282 = false ;
break;
case V_284 :
V_148 -> V_251 = 0 ;
break;
case V_285 :
V_148 -> V_251 = 1 ;
break;
case V_286 :
V_148 -> V_287 = 0 ;
break;
case V_288 :
V_148 -> V_287 = 1 ;
break;
case V_289 :
V_148 -> V_290 = 1 ;
break;
case V_291 :
V_148 -> V_290 = 0 ;
break;
case V_292 :
V_148 -> V_229 = 1 ;
break;
case V_293 :
V_148 -> V_229 = 0 ;
break;
case V_294 :
V_148 -> V_295 = 1 ;
break;
case V_296 :
V_148 -> V_297 = 1 ;
break;
case V_298 :
V_148 -> V_297 = 0 ;
break;
case V_299 :
V_148 -> V_300 = 0 ;
break;
case V_301 :
V_148 -> V_300 = 1 ;
break;
case V_302 :
V_148 -> V_303 = 1 ;
break;
case V_304 :
V_148 -> V_152 = true ;
break;
case V_305 :
V_148 -> V_306 = 1 ;
break;
case V_307 :
F_97 ( V_308 L_39
L_40
L_41 ) ;
break;
case V_309 :
#ifndef F_98
F_5 ( V_59 , L_42 ) ;
goto V_232;
#endif
V_148 -> V_310 = true ;
break;
case V_311 :
V_148 -> V_312 = true ;
break;
case V_313 :
V_148 -> V_314 = true ;
break;
case V_315 :
V_211 = true ;
break;
case V_316 :
V_148 -> V_317 = true ;
break;
case V_318 :
if ( F_75 ( args , & V_148 -> V_319 ) ) {
F_5 ( V_59 , L_43 ,
V_21 ) ;
goto V_232;
}
V_148 -> V_234 = true ;
break;
case V_320 :
if ( F_79 ( args , & V_148 -> V_321 ) ) {
F_5 ( V_59 , L_44 ,
V_21 ) ;
goto V_232;
}
V_148 -> V_235 = true ;
break;
case V_322 :
if ( F_75 ( args , & V_148 -> V_221 ) ) {
F_5 ( V_59 , L_45 ,
V_21 ) ;
goto V_232;
}
V_209 = true ;
break;
case V_323 :
if ( F_75 ( args , & V_148 -> V_220 ) ) {
F_5 ( V_59 , L_46 ,
V_21 ) ;
goto V_232;
}
break;
case V_324 :
if ( F_79 ( args , & V_148 -> V_222 ) ) {
F_5 ( V_59 , L_47 ,
V_21 ) ;
goto V_232;
}
V_210 = true ;
break;
case V_325 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_48 ,
V_21 ) ;
goto V_232;
}
V_148 -> V_224 = V_142 ;
break;
case V_326 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_49 ,
V_21 ) ;
goto V_232;
}
V_148 -> V_223 = V_142 ;
break;
case V_327 :
if ( F_72 ( args , & V_142 ) ||
V_142 > V_328 ) {
F_5 ( V_59 , L_50 ,
V_21 ) ;
goto V_232;
}
V_216 = ( unsigned short ) V_142 ;
break;
case V_329 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_51 ,
V_21 ) ;
goto V_232;
}
V_148 -> V_330 = V_142 ;
break;
case V_331 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_52 ,
V_21 ) ;
goto V_232;
}
V_148 -> V_332 = V_142 ;
break;
case V_333 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_53 ,
V_21 ) ;
goto V_232;
}
V_148 -> V_230 = V_53 * V_142 ;
if ( V_148 -> V_230 > V_334 ) {
F_5 ( V_59 , L_54 ) ;
goto V_232;
}
break;
case V_335 :
V_148 -> V_170 = 1 ;
V_148 -> V_336 = NULL ;
break;
case V_337 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_338;
if ( F_93 ( string , V_339 ) >
V_339 ) {
F_97 ( V_308 L_55 ) ;
goto V_232;
}
V_148 -> V_336 = F_90 ( string , V_117 ) ;
if ( ! V_148 -> V_336 )
goto V_232;
break;
case V_340 :
V_214 = strchr ( V_199 , '=' ) ;
V_214 ++ ;
if ( ! ( V_214 < V_200 && V_214 [ 1 ] == V_140 ) ) {
F_11 ( V_148 -> V_341 ) ;
V_148 -> V_341 = NULL ;
break;
}
case V_342 :
V_144 = strchr ( V_199 , '=' ) ;
V_144 ++ ;
V_214 = ( char * ) V_144 + strlen ( V_144 ) ;
if ( V_214 < V_200 && V_214 [ 1 ] == V_140 ) {
V_214 [ 0 ] = V_140 ;
while ( ( V_214 = strchr ( V_214 , V_140 ) )
!= NULL && ( V_214 [ 1 ] == V_140 ) ) {
V_214 = ( char * ) & V_214 [ 2 ] ;
}
if ( V_214 ) {
V_214 [ 0 ] = '\0' ;
V_202 = ( char * ) & V_214 [ 1 ] ;
} else
V_202 = V_200 ;
}
F_11 ( V_148 -> V_341 ) ;
V_203 = strlen ( V_144 ) ;
V_148 -> V_341 = F_99 ( V_203 + 1 , V_117 ) ;
if ( V_148 -> V_341 == NULL ) {
F_97 ( V_308 L_56
L_57 ) ;
goto V_232;
}
for ( V_204 = 0 , V_205 = 0 ; V_204 < V_203 ; V_204 ++ , V_205 ++ ) {
V_148 -> V_341 [ V_205 ] = V_144 [ V_204 ] ;
if ( ( V_144 [ V_204 ] == V_140 ) &&
V_144 [ V_204 + 1 ] == V_140 )
V_204 ++ ;
}
V_148 -> V_341 [ V_205 ] = '\0' ;
break;
case V_343 :
V_215 = false ;
break;
case V_344 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_338;
if ( ! F_100 ( V_97 , string ,
strlen ( string ) ) ) {
F_97 ( V_345 L_58 ,
string ) ;
goto V_232;
}
V_215 = true ;
break;
case V_346 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_338;
if ( F_93 ( string , V_347 )
== V_347 ) {
F_97 ( V_308 L_59
L_60 ) ;
goto V_232;
}
V_148 -> V_348 = F_90 ( string , V_117 ) ;
if ( ! V_148 -> V_348 ) {
F_97 ( V_308 L_56
L_61 ) ;
goto V_232;
}
F_5 ( V_20 , L_62 ) ;
break;
case V_349 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_338;
if ( ! F_100 (
(struct V_96 * ) & V_148 -> V_350 ,
string , strlen ( string ) ) ) {
F_97 ( V_308 L_63
L_64 , string ) ;
goto V_232;
}
break;
case V_351 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_338;
if ( F_93 ( string , 1024 ) >= 65 ) {
F_97 ( V_308 L_65
L_66 ) ;
goto V_232;
}
if ( F_101 ( string , L_67 , 7 ) != 0 ) {
V_148 -> V_352 = F_90 ( string ,
V_117 ) ;
if ( ! V_148 -> V_352 ) {
F_97 ( V_308 L_68
L_69 ) ;
goto V_232;
}
}
F_5 ( V_20 , L_70 , string ) ;
break;
case V_353 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_338;
memset ( V_148 -> V_217 , 0x20 ,
V_218 ) ;
for ( V_204 = 0 ; V_204 < V_218 ; V_204 ++ ) {
if ( string [ V_204 ] == 0 )
break;
V_148 -> V_217 [ V_204 ] = string [ V_204 ] ;
}
if ( V_204 == V_218 && string [ V_204 ] != 0 )
F_97 ( V_308 L_71
L_72 ) ;
break;
case V_354 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_338;
memset ( V_148 -> V_219 , 0x20 ,
V_355 ) ;
for ( V_204 = 0 ; V_204 < 15 ; V_204 ++ ) {
if ( string [ V_204 ] == 0 )
break;
V_148 -> V_219 [ V_204 ] = string [ V_204 ] ;
}
if ( V_204 == V_218 && string [ V_204 ] != 0 )
F_97 ( V_308 L_73
L_74 ) ;
break;
case V_356 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_338;
if ( F_101 ( string , L_75 , 1 ) == 0 ) {
break;
}
F_97 ( V_308 L_76
L_77 ) ;
goto V_232;
case V_357 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_338;
if ( F_86 ( string , V_148 ) != 0 )
goto V_232;
break;
case V_358 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_338;
if ( F_82 ( string , V_148 ) != 0 )
goto V_232;
break;
case V_359 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_338;
if ( F_85 ( string , V_148 ) != 0 )
goto V_232;
break;
default:
if ( ! V_212 )
V_212 = V_199 ;
break;
}
F_11 ( string ) ;
string = NULL ;
}
if ( ! V_211 && V_212 ) {
F_97 ( V_345 L_78 , V_212 ) ;
goto V_232;
}
#ifndef F_102
if ( V_148 -> V_314 ) {
F_5 ( V_59 , L_79 ) ;
goto V_232;
}
#endif
if ( ! V_148 -> V_196 ) {
F_5 ( V_59 , L_80 ) ;
goto V_232;
}
if ( ! strchr ( V_148 -> V_196 + 3 , '\\' ) ) {
F_5 ( V_59 , L_81 ) ;
goto V_232;
}
if ( ! V_215 ) {
if ( ! F_100 ( V_97 , & V_148 -> V_196 [ 2 ] ,
strlen ( & V_148 -> V_196 [ 2 ] ) ) ) {
F_97 ( V_345 L_82
L_83 ) ;
goto V_232;
}
}
F_41 ( V_97 , V_216 ) ;
if ( V_209 )
V_148 -> V_207 = V_207 ;
else if ( V_207 == 1 )
F_97 ( V_360 L_84
L_85 ) ;
if ( V_210 )
V_148 -> V_208 = V_208 ;
else if ( V_208 == 1 )
F_97 ( V_360 L_86
L_87 ) ;
F_11 ( V_201 ) ;
return 0 ;
V_338:
F_97 ( V_308 L_88 ) ;
V_232:
F_11 ( string ) ;
F_11 ( V_201 ) ;
return 1 ;
}
static bool
F_103 ( struct V_96 * V_350 , struct V_96 * V_361 )
{
switch ( V_350 -> V_362 ) {
case V_363 :
return ( V_361 -> V_362 == V_363 ) ;
case V_364 : {
struct V_365 * V_366 = (struct V_365 * ) V_350 ;
struct V_365 * V_367 = (struct V_365 * ) V_361 ;
return ( V_366 -> V_368 . V_369 == V_367 -> V_368 . V_369 ) ;
}
case V_370 : {
struct V_371 * V_372 = (struct V_371 * ) V_350 ;
struct V_371 * V_373 = (struct V_371 * ) V_361 ;
return F_104 ( & V_372 -> V_374 , & V_373 -> V_374 ) ;
}
default:
F_105 ( 1 ) ;
return false ;
}
}
static bool
F_106 ( struct V_1 * V_2 , struct V_96 * V_375 )
{
T_5 V_216 , * V_376 ;
switch ( V_375 -> V_362 ) {
case V_364 :
V_376 = & ( (struct V_365 * ) & V_2 -> V_97 ) -> V_377 ;
V_216 = ( (struct V_365 * ) V_375 ) -> V_377 ;
break;
case V_370 :
V_376 = & ( (struct V_371 * ) & V_2 -> V_97 ) -> V_378 ;
V_216 = ( (struct V_371 * ) V_375 ) -> V_378 ;
break;
default:
F_105 ( 1 ) ;
return false ;
}
if ( ! V_216 ) {
V_216 = F_107 ( V_98 ) ;
if ( V_216 == * V_376 )
return true ;
V_216 = F_107 ( V_379 ) ;
}
return V_216 == * V_376 ;
}
static bool
F_108 ( struct V_1 * V_2 , struct V_96 * V_375 ,
struct V_96 * V_350 )
{
switch ( V_375 -> V_362 ) {
case V_364 : {
struct V_365 * V_380 = (struct V_365 * ) V_375 ;
struct V_365 * V_381 =
(struct V_365 * ) & V_2 -> V_97 ;
if ( V_380 -> V_368 . V_369 != V_381 -> V_368 . V_369 )
return false ;
break;
}
case V_370 : {
struct V_371 * V_382 = (struct V_371 * ) V_375 ;
struct V_371 * V_383 =
(struct V_371 * ) & V_2 -> V_97 ;
if ( ! F_104 ( & V_382 -> V_374 ,
& V_383 -> V_374 ) )
return false ;
if ( V_382 -> V_384 != V_383 -> V_384 )
return false ;
break;
}
default:
F_105 ( 1 ) ;
return false ;
}
if ( ! F_103 ( V_350 , (struct V_96 * ) & V_2 -> V_350 ) )
return false ;
return true ;
}
static bool
F_109 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
if ( F_110 ( V_2 , V_148 -> V_150 ) == V_151 )
return false ;
if ( V_148 -> V_152 && ! V_2 -> V_152 )
return false ;
return true ;
}
static int F_111 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
struct V_96 * V_375 = (struct V_96 * ) & V_148 -> V_97 ;
if ( V_148 -> V_317 )
return 0 ;
if ( ( V_2 -> V_180 != V_148 -> V_180 ) || ( V_2 -> V_49 != V_148 -> V_49 ) )
return 0 ;
if ( ! F_112 ( F_113 ( V_2 ) , V_126 -> V_385 -> V_386 ) )
return 0 ;
if ( ! F_108 ( V_2 , V_375 ,
(struct V_96 * ) & V_148 -> V_350 ) )
return 0 ;
if ( ! F_106 ( V_2 , V_375 ) )
return 0 ;
if ( ! F_109 ( V_2 , V_148 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_114 ( struct V_147 * V_148 )
{
struct V_1 * V_2 ;
F_2 ( & V_22 ) ;
F_115 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_111 ( V_2 , V_148 ) )
continue;
++ V_2 -> V_387 ;
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
struct V_124 * V_388 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_387 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_117 ( F_113 ( V_2 ) ) ;
F_16 ( & V_2 -> V_107 ) ;
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
V_388 = F_65 ( & V_2 -> V_134 , NULL ) ;
if ( V_388 )
F_121 ( V_389 , V_388 ) ;
}
static struct V_1 *
F_122 ( struct V_147 * V_390 )
{
struct V_1 * V_391 = NULL ;
int V_3 ;
F_5 ( V_20 , L_90 , V_390 -> V_196 ) ;
V_391 = F_114 ( V_390 ) ;
if ( V_391 )
return V_391 ;
V_391 = F_99 ( sizeof( struct V_1 ) , V_117 ) ;
if ( ! V_391 ) {
V_3 = - V_83 ;
goto V_392;
}
V_391 -> V_49 = V_390 -> V_49 ;
V_391 -> V_180 = V_390 -> V_180 ;
F_123 ( V_391 , F_124 ( V_126 -> V_385 -> V_386 ) ) ;
V_391 -> V_56 = F_70 ( V_390 -> V_196 ) ;
if ( F_125 ( V_391 -> V_56 ) ) {
V_3 = F_126 ( V_391 -> V_56 ) ;
goto V_393;
}
V_391 -> V_247 = V_390 -> V_247 ;
V_391 -> V_249 = V_390 -> V_249 ;
V_391 -> V_394 = V_390 -> V_395 ;
V_391 -> V_396 = 0 ;
V_391 -> V_109 = 1 ;
F_127 ( & V_391 -> V_63 ) ;
F_127 ( & V_391 -> V_110 ) ;
F_13 ( & V_391 -> V_111 ) ;
F_128 ( & V_391 -> V_27 ) ;
memcpy ( V_391 -> V_397 ,
V_390 -> V_217 , V_355 ) ;
memcpy ( V_391 -> V_398 ,
V_390 -> V_219 , V_355 ) ;
V_391 -> V_33 = false ;
V_391 -> V_32 = 0 ;
V_391 -> V_37 = V_38 ;
F_129 ( & V_391 -> V_108 ) ;
F_13 ( & V_391 -> V_107 ) ;
F_13 ( & V_391 -> V_23 ) ;
F_130 ( & V_391 -> V_48 , F_21 ) ;
memcpy ( & V_391 -> V_350 , & V_390 -> V_350 ,
sizeof( V_391 -> V_350 ) ) ;
memcpy ( & V_391 -> V_97 , & V_390 -> V_97 ,
sizeof( V_391 -> V_97 ) ) ;
#ifdef F_4
F_131 ( V_391 -> V_399 , V_400 ) ;
#endif
V_391 -> V_15 = V_401 ;
++ V_391 -> V_387 ;
V_3 = F_132 ( V_391 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_91 ) ;
goto V_393;
}
F_133 ( V_402 ) ;
V_391 -> V_134 = F_134 ( F_56 ,
V_391 , L_92 ) ;
if ( F_125 ( V_391 -> V_134 ) ) {
V_3 = F_126 ( V_391 -> V_134 ) ;
F_5 ( V_59 , L_93 , V_3 ) ;
F_135 ( V_402 ) ;
goto V_393;
}
V_391 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_136 ( & V_391 -> V_107 , & V_403 ) ;
F_3 ( & V_22 ) ;
F_137 ( V_391 ) ;
F_24 ( V_57 , & V_391 -> V_48 , V_52 ) ;
return V_391 ;
V_393:
F_119 ( V_391 ) ;
F_117 ( F_113 ( V_391 ) ) ;
V_392:
if ( V_391 ) {
if ( ! F_125 ( V_391 -> V_56 ) )
F_11 ( V_391 -> V_56 ) ;
if ( V_391 -> V_28 )
F_10 ( V_391 -> V_28 ) ;
F_11 ( V_391 ) ;
}
return F_71 ( V_3 ) ;
}
static int F_138 ( struct V_7 * V_8 , struct V_147 * V_148 )
{
if ( V_148 -> V_150 != V_151 &&
V_148 -> V_150 != V_8 -> V_150 )
return 0 ;
switch ( V_8 -> V_150 ) {
case V_157 :
if ( ! F_139 ( V_148 -> V_220 , V_8 -> V_220 ) )
return 0 ;
break;
default:
if ( V_8 -> V_404 == NULL ) {
if ( ! V_148 -> V_170 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_404 ,
V_148 -> V_336 ? V_148 -> V_336 : L_94 ,
V_339 ) )
return 0 ;
if ( ( V_148 -> V_336 && strlen ( V_148 -> V_336 ) != 0 ) &&
V_8 -> V_341 != NULL &&
strncmp ( V_8 -> V_341 ,
V_148 -> V_341 ? V_148 -> V_341 : L_94 ,
V_405 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_140 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
struct V_7 * V_8 ;
F_2 ( & V_22 ) ;
F_115 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_8 -> V_406 == V_16 )
continue;
if ( ! F_138 ( V_8 , V_148 ) )
continue;
++ V_8 -> V_407 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_141 ( struct V_7 * V_8 )
{
unsigned int V_3 , V_408 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_20 , L_95 , V_21 , V_8 -> V_407 ) ;
F_2 ( & V_22 ) ;
if ( V_8 -> V_406 == V_16 ) {
F_3 ( & V_22 ) ;
return;
}
if ( -- V_8 -> V_407 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
if ( V_8 -> V_406 == V_62 )
V_8 -> V_406 = V_16 ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_406 == V_16 && V_2 -> V_49 -> V_409 ) {
V_408 = F_142 () ;
V_3 = V_2 -> V_49 -> V_409 ( V_408 , V_8 ) ;
if ( V_3 )
F_5 ( V_59 , L_96 ,
V_21 , V_3 ) ;
F_143 ( V_408 ) ;
}
F_2 ( & V_22 ) ;
F_16 ( & V_8 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_144 ( V_8 ) ;
F_116 ( V_2 ) ;
}
static int
F_145 ( struct V_147 * V_148 , struct V_7 * V_8 )
{
int V_3 = 0 ;
char * V_410 , * V_140 , * V_411 ;
T_6 V_36 ;
struct V_412 * V_412 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_365 * V_413 ;
struct V_371 * V_414 ;
struct V_415 * V_416 ;
V_410 = F_35 ( V_417 , V_117 ) ;
if ( ! V_410 )
return - V_83 ;
switch ( V_2 -> V_97 . V_418 ) {
case V_364 :
V_413 = (struct V_365 * ) & V_2 -> V_97 ;
sprintf ( V_410 , L_97 , & V_413 -> V_368 . V_369 ) ;
break;
case V_370 :
V_414 = (struct V_371 * ) & V_2 -> V_97 ;
sprintf ( V_410 , L_98 , & V_414 -> V_374 . V_419 ) ;
break;
default:
F_5 ( V_20 , L_99 ,
V_2 -> V_97 . V_418 ) ;
V_3 = - V_141 ;
goto V_392;
}
F_5 ( V_20 , L_100 , V_21 , V_410 ) ;
V_412 = F_146 ( & V_420 , V_410 , L_94 ) ;
if ( F_125 ( V_412 ) ) {
if ( ! V_8 -> V_421 ) {
F_5 ( V_20 , L_101 ) ;
V_3 = F_126 ( V_412 ) ;
goto V_392;
}
sprintf ( V_410 , L_102 , V_8 -> V_421 ) ;
F_5 ( V_20 , L_100 , V_21 , V_410 ) ;
V_412 = F_146 ( & V_420 , V_410 , L_94 ) ;
if ( F_125 ( V_412 ) ) {
V_3 = F_126 ( V_412 ) ;
goto V_392;
}
}
F_147 ( & V_412 -> V_422 ) ;
V_416 = V_412 -> V_411 . V_199 ;
if ( F_148 ( V_416 ) ) {
V_3 = V_416 ? F_126 ( V_416 ) : - V_141 ;
goto V_423;
}
V_411 = ( char * ) V_416 -> V_199 ;
V_140 = F_149 ( V_411 , V_416 -> V_424 , ':' ) ;
F_5 ( V_20 , L_103 , V_411 ) ;
if ( ! V_140 ) {
F_5 ( V_20 , L_104 ,
V_416 -> V_424 ) ;
V_3 = - V_141 ;
goto V_423;
}
V_36 = V_140 - V_411 ;
if ( V_36 > V_339 || V_36 <= 0 ) {
F_5 ( V_20 , L_105 ,
V_36 ) ;
V_3 = - V_141 ;
goto V_423;
}
V_148 -> V_336 = F_88 ( V_411 , V_36 , V_117 ) ;
if ( ! V_148 -> V_336 ) {
F_5 ( V_20 , L_106 ,
V_36 ) ;
V_3 = - V_83 ;
goto V_423;
}
F_5 ( V_20 , L_107 , V_21 , V_148 -> V_336 ) ;
V_36 = V_412 -> V_424 - ( V_36 + 1 ) ;
if ( V_36 > V_405 || V_36 <= 0 ) {
F_5 ( V_20 , L_108 , V_36 ) ;
V_3 = - V_141 ;
F_11 ( V_148 -> V_336 ) ;
V_148 -> V_336 = NULL ;
goto V_423;
}
++ V_140 ;
V_148 -> V_341 = F_88 ( V_140 , V_36 , V_117 ) ;
if ( ! V_148 -> V_341 ) {
F_5 ( V_20 , L_109 ,
V_36 ) ;
V_3 = - V_83 ;
F_11 ( V_148 -> V_336 ) ;
V_148 -> V_336 = NULL ;
goto V_423;
}
V_423:
F_150 ( & V_412 -> V_422 ) ;
F_151 ( V_412 ) ;
V_392:
F_11 ( V_410 ) ;
F_5 ( V_20 , L_110 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_152 ( struct V_1 * V_2 , struct V_147 * V_390 )
{
int V_3 = - V_83 ;
unsigned int V_408 ;
struct V_7 * V_8 ;
struct V_365 * V_375 = (struct V_365 * ) & V_2 -> V_97 ;
struct V_371 * V_382 = (struct V_371 * ) & V_2 -> V_97 ;
V_408 = F_142 () ;
V_8 = F_140 ( V_2 , V_390 ) ;
if ( V_8 ) {
F_5 ( V_20 , L_111 ,
V_8 -> V_406 ) ;
F_8 ( & V_8 -> V_425 ) ;
V_3 = F_153 ( V_408 , V_8 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_425 ) ;
F_141 ( V_8 ) ;
F_154 ( V_408 ) ;
return F_71 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_5 ( V_20 , L_112 ) ;
V_3 = F_155 ( V_408 , V_8 ,
V_390 -> V_426 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_425 ) ;
F_141 ( V_8 ) ;
F_154 ( V_408 ) ;
return F_71 ( V_3 ) ;
}
}
F_12 ( & V_8 -> V_425 ) ;
F_116 ( V_2 ) ;
F_154 ( V_408 ) ;
return V_8 ;
}
F_5 ( V_20 , L_113 ) ;
V_8 = F_156 () ;
if ( V_8 == NULL )
goto V_427;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_97 . V_418 == V_370 )
sprintf ( V_8 -> V_428 , L_114 , & V_382 -> V_374 ) ;
else
sprintf ( V_8 -> V_428 , L_115 , & V_375 -> V_368 ) ;
if ( V_390 -> V_336 ) {
V_8 -> V_404 = F_90 ( V_390 -> V_336 , V_117 ) ;
if ( ! V_8 -> V_404 )
goto V_427;
}
if ( V_390 -> V_341 ) {
V_8 -> V_341 = F_90 ( V_390 -> V_341 , V_117 ) ;
if ( ! V_8 -> V_341 )
goto V_427;
}
if ( V_390 -> V_348 ) {
V_8 -> V_421 = F_90 ( V_390 -> V_348 , V_117 ) ;
if ( ! V_8 -> V_421 )
goto V_427;
}
V_8 -> V_220 = V_390 -> V_220 ;
V_8 -> V_221 = V_390 -> V_221 ;
V_8 -> V_150 = V_390 -> V_150 ;
V_8 -> V_152 = V_390 -> V_152 ;
F_8 ( & V_8 -> V_425 ) ;
V_3 = F_153 ( V_408 , V_8 ) ;
if ( ! V_3 )
V_3 = F_155 ( V_408 , V_8 , V_390 -> V_426 ) ;
F_12 ( & V_8 -> V_425 ) ;
if ( V_3 )
goto V_427;
F_2 ( & V_22 ) ;
F_136 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_154 ( V_408 ) ;
return V_8 ;
V_427:
F_144 ( V_8 ) ;
F_154 ( V_408 ) ;
return F_71 ( V_3 ) ;
}
static int F_157 ( struct V_9 * V_10 , const char * V_137 )
{
if ( V_10 -> V_429 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_430 , V_137 , V_431 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_158 ( struct V_7 * V_8 , const char * V_137 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_22 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_26 ) ;
if ( ! F_157 ( V_10 , V_137 ) )
continue;
++ V_10 -> V_432 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_159 ( struct V_9 * V_10 )
{
unsigned int V_408 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( V_20 , L_116 , V_21 , V_10 -> V_432 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_432 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_408 = F_142 () ;
if ( V_8 -> V_2 -> V_49 -> V_433 )
V_8 -> V_2 -> V_49 -> V_433 ( V_408 , V_10 ) ;
F_143 ( V_408 ) ;
F_160 ( V_10 ) ;
F_161 ( V_10 ) ;
F_141 ( V_8 ) ;
}
static struct V_9 *
F_162 ( struct V_7 * V_8 , struct V_147 * V_390 )
{
int V_3 , V_408 ;
struct V_9 * V_10 ;
V_10 = F_158 ( V_8 , V_390 -> V_196 ) ;
if ( V_10 ) {
F_5 ( V_20 , L_117 ) ;
F_141 ( V_8 ) ;
if ( V_10 -> V_306 != V_390 -> V_306 )
F_5 ( V_59 , L_118 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_49 -> V_434 ) {
V_3 = - V_55 ;
goto V_435;
}
V_10 = F_163 () ;
if ( V_10 == NULL ) {
V_3 = - V_83 ;
goto V_435;
}
V_10 -> V_8 = V_8 ;
if ( V_390 -> V_341 ) {
V_10 -> V_341 = F_90 ( V_390 -> V_341 , V_117 ) ;
if ( ! V_10 -> V_341 ) {
V_3 = - V_83 ;
goto V_435;
}
}
V_408 = F_142 () ;
V_3 = V_8 -> V_2 -> V_49 -> V_434 ( V_408 , V_8 , V_390 -> V_196 , V_10 ,
V_390 -> V_426 ) ;
F_154 ( V_408 ) ;
F_5 ( V_20 , L_119 , V_3 ) ;
if ( V_3 )
goto V_435;
if ( V_390 -> V_263 ) {
V_10 -> V_436 &= ~ V_437 ;
F_5 ( V_20 , L_120 , V_10 -> V_436 ) ;
}
V_10 -> V_306 = V_390 -> V_306 ;
V_10 -> V_251 = V_390 -> V_251 ;
V_10 -> V_269 = V_390 -> V_269 ;
V_10 -> V_303 = V_390 -> V_303 ;
F_13 ( & V_10 -> V_438 ) ;
F_2 ( & V_22 ) ;
F_136 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_164 ( V_10 ) ;
return V_10 ;
V_435:
F_161 ( V_10 ) ;
return F_71 ( V_3 ) ;
}
void
F_165 ( struct V_439 * V_440 )
{
if ( ! V_440 || F_125 ( V_440 ) )
return;
if ( ! F_166 ( & V_440 -> V_441 ) ||
F_167 ( V_442 , & V_440 -> V_443 ) ) {
V_440 -> V_444 = V_38 ;
return;
}
if ( ! F_125 ( F_168 ( V_440 ) ) )
F_159 ( F_168 ( V_440 ) ) ;
F_11 ( V_440 ) ;
return;
}
static inline struct V_439 *
F_169 ( struct V_445 * V_446 )
{
return V_446 -> V_447 ;
}
static int
F_170 ( struct V_448 * V_449 , struct V_450 * V_451 )
{
struct V_445 * V_452 = F_171 ( V_449 ) ;
struct V_445 * V_65 = V_451 -> V_446 ;
if ( ( V_449 -> V_453 & V_454 ) != ( V_451 -> V_30 & V_454 ) )
return 0 ;
if ( ( V_452 -> V_455 & V_456 ) !=
( V_65 -> V_455 & V_456 ) )
return 0 ;
if ( V_65 -> V_332 && V_65 -> V_332 < V_452 -> V_332 )
return 0 ;
if ( V_65 -> V_330 && V_65 -> V_330 < V_452 -> V_330 )
return 0 ;
if ( ! F_139 ( V_452 -> V_457 , V_65 -> V_457 ) || ! F_172 ( V_452 -> V_458 , V_65 -> V_458 ) )
return 0 ;
if ( V_452 -> V_459 != V_65 -> V_459 ||
V_452 -> V_460 != V_65 -> V_460 )
return 0 ;
if ( strcmp ( V_452 -> V_426 -> V_461 , V_65 -> V_426 -> V_461 ) )
return 0 ;
if ( V_452 -> V_230 != V_65 -> V_230 )
return 0 ;
return 1 ;
}
int
F_173 ( struct V_448 * V_449 , void * V_199 )
{
struct V_450 * V_451 = (struct V_450 * ) V_199 ;
struct V_147 * V_390 ;
struct V_445 * V_446 ;
struct V_1 * V_462 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_439 * V_440 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_446 = F_171 ( V_449 ) ;
V_440 = F_174 ( F_169 ( V_446 ) ) ;
if ( F_125 ( V_440 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_168 ( V_440 ) ;
V_8 = V_10 -> V_8 ;
V_462 = V_8 -> V_2 ;
V_390 = V_451 -> V_148 ;
if ( ! F_111 ( V_462 , V_390 ) ||
! F_138 ( V_8 , V_390 ) ||
! F_157 ( V_10 , V_390 -> V_196 ) ) {
V_3 = 0 ;
goto V_463;
}
V_3 = F_170 ( V_449 , V_451 ) ;
V_463:
F_3 ( & V_22 ) ;
F_165 ( V_440 ) ;
return V_3 ;
}
int
F_175 ( const unsigned int V_408 , struct V_7 * V_8 , const char * V_464 ,
const struct V_465 * V_466 , unsigned int * V_467 ,
struct V_468 * * V_469 , int V_257 )
{
char * V_470 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_49 -> V_434 || ! V_8 -> V_2 -> V_49 -> V_471 )
return - V_55 ;
* V_467 = 0 ;
* V_469 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_470 = F_35 ( 2 +
F_93 ( V_8 -> V_428 , V_472 * 2 )
+ 1 + 4 + 2 , V_117 ) ;
if ( V_470 == NULL )
return - V_83 ;
V_470 [ 0 ] = '\\' ;
V_470 [ 1 ] = '\\' ;
strcpy ( V_470 + 2 , V_8 -> V_428 ) ;
strcpy ( V_470 + 2 + strlen ( V_8 -> V_428 ) , L_121 ) ;
V_3 = V_8 -> V_2 -> V_49 -> V_434 ( V_408 , V_8 , V_470 , NULL ,
V_466 ) ;
F_5 ( V_20 , L_122 , V_3 , V_8 -> V_25 ) ;
F_11 ( V_470 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_49 -> V_471 ( V_408 , V_8 , V_464 ,
V_469 , V_467 ,
V_466 , V_257 ) ;
return V_3 ;
}
static inline void
F_176 ( struct V_473 * V_474 )
{
struct V_474 * V_475 = V_474 -> V_475 ;
F_177 ( F_178 ( V_475 ) ) ;
F_179 ( V_475 , L_123 ,
& V_476 [ 0 ] , L_124 , & V_477 [ 0 ] ) ;
}
static inline void
F_180 ( struct V_473 * V_474 )
{
struct V_474 * V_475 = V_474 -> V_475 ;
F_177 ( F_178 ( V_475 ) ) ;
F_179 ( V_475 , L_125 ,
& V_476 [ 1 ] , L_126 , & V_477 [ 1 ] ) ;
}
static inline void
F_176 ( struct V_473 * V_474 )
{
}
static inline void
F_180 ( struct V_473 * V_474 )
{
}
static void F_181 ( char * V_478 , char * V_479 , unsigned int V_78 )
{
unsigned int V_204 , V_205 ;
for ( V_204 = 0 , V_205 = 0 ; V_204 < ( V_78 ) ; V_204 ++ ) {
V_478 [ V_205 ] = 'A' + ( 0x0F & ( V_479 [ V_204 ] >> 4 ) ) ;
V_478 [ V_205 + 1 ] = 'A' + ( 0x0F & V_479 [ V_204 ] ) ;
V_205 += 2 ;
}
}
static int
F_182 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_350 . V_418 != V_363 ) {
struct V_473 * V_473 = V_2 -> V_28 ;
V_3 = V_473 -> V_49 -> V_480 ( V_473 ,
(struct V_96 * ) & V_2 -> V_350 ,
sizeof( V_2 -> V_350 ) ) ;
if ( V_3 < 0 ) {
struct V_365 * V_366 ;
struct V_371 * V_372 ;
V_366 = (struct V_365 * ) & V_2 -> V_350 ;
V_372 = (struct V_371 * ) & V_2 -> V_350 ;
if ( V_372 -> V_481 == V_370 )
F_5 ( V_59 , L_127 ,
& V_372 -> V_374 , V_3 ) ;
else
F_5 ( V_59 , L_128 ,
& V_366 -> V_368 . V_369 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_183 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_482 * V_483 ;
struct V_484 * V_485 ;
V_483 = F_99 ( sizeof( struct V_482 ) ,
V_117 ) ;
if ( V_483 ) {
V_483 -> V_486 . V_487 . V_488 = 32 ;
if ( V_2 -> V_398 &&
V_2 -> V_398 [ 0 ] != 0 )
F_181 ( V_483 -> V_486 .
V_487 . V_489 ,
V_2 -> V_398 ,
V_355 ) ;
else
F_181 ( V_483 -> V_486 .
V_487 . V_489 ,
V_490 ,
V_355 ) ;
V_483 -> V_486 . V_487 . V_491 = 32 ;
if ( V_2 -> V_397 &&
V_2 -> V_397 [ 0 ] != 0 )
F_181 ( V_483 -> V_486 .
V_487 . V_492 ,
V_2 -> V_397 ,
V_355 ) ;
else
F_181 ( V_483 -> V_486 .
V_487 . V_492 ,
L_129 ,
V_355 ) ;
V_483 -> V_486 . V_487 . V_493 = 0 ;
V_483 -> V_486 . V_487 . V_494 = 0 ;
V_485 = (struct V_484 * ) V_483 ;
V_485 -> V_495 = F_184 ( 0x81000044 ) ;
V_3 = F_185 ( V_2 , V_485 , 0x44 ) ;
F_11 ( V_483 ) ;
F_38 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_376 ;
int V_496 , V_497 ;
struct V_473 * V_473 = V_2 -> V_28 ;
struct V_96 * V_498 ;
V_498 = (struct V_96 * ) & V_2 -> V_97 ;
if ( V_2 -> V_97 . V_418 == V_370 ) {
V_376 = ( (struct V_371 * ) V_498 ) -> V_378 ;
V_496 = sizeof( struct V_371 ) ;
V_497 = V_370 ;
} else {
V_376 = ( (struct V_365 * ) V_498 ) -> V_377 ;
V_496 = sizeof( struct V_365 ) ;
V_497 = V_364 ;
}
if ( V_473 == NULL ) {
V_3 = F_186 ( F_113 ( V_2 ) , V_497 , V_499 ,
V_500 , & V_473 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_130 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_5 ( V_20 , L_131 ) ;
V_2 -> V_28 = V_473 ;
V_473 -> V_475 -> V_501 = V_75 ;
if ( V_497 == V_370 )
F_180 ( V_473 ) ;
else
F_176 ( V_473 ) ;
}
V_3 = F_182 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_473 -> V_475 -> V_502 = 7 * V_53 ;
V_473 -> V_475 -> V_503 = 5 * V_53 ;
if ( V_2 -> V_249 ) {
if ( V_473 -> V_475 -> V_504 < ( 200 * 1024 ) )
V_473 -> V_475 -> V_504 = 200 * 1024 ;
if ( V_473 -> V_475 -> V_505 < ( 140 * 1024 ) )
V_473 -> V_475 -> V_505 = 140 * 1024 ;
}
if ( V_2 -> V_394 ) {
int V_506 = 1 ;
V_3 = F_187 ( V_473 , V_507 , V_508 ,
( char * ) & V_506 , sizeof( V_506 ) ) ;
if ( V_3 )
F_5 ( V_20 , L_132 ,
V_3 ) ;
}
F_5 ( V_20 , L_133 ,
V_473 -> V_475 -> V_504 ,
V_473 -> V_475 -> V_505 , V_473 -> V_475 -> V_502 ) ;
V_3 = V_473 -> V_49 -> V_509 ( V_473 , V_498 , V_496 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_20 , L_134 , V_3 ) ;
F_10 ( V_473 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_376 == F_107 ( V_379 ) )
V_3 = F_183 ( V_2 ) ;
return V_3 ;
}
static int
F_132 ( struct V_1 * V_2 )
{
T_5 * V_376 ;
struct V_371 * V_382 = (struct V_371 * ) & V_2 -> V_97 ;
struct V_365 * V_375 = (struct V_365 * ) & V_2 -> V_97 ;
if ( V_2 -> V_97 . V_418 == V_370 )
V_376 = & V_382 -> V_378 ;
else
V_376 = & V_375 -> V_377 ;
if ( * V_376 == 0 ) {
int V_3 ;
* V_376 = F_107 ( V_98 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_376 = F_107 ( V_379 ) ;
}
return F_18 ( V_2 ) ;
}
void F_188 ( unsigned int V_408 , struct V_9 * V_10 ,
struct V_445 * V_446 , struct V_147 * V_510 )
{
T_7 V_511 = F_189 ( V_10 -> V_512 . V_513 ) ;
if ( V_510 && V_510 -> V_267 ) {
V_10 -> V_512 . V_513 = 0 ;
V_10 -> V_514 = 0 ;
F_5 ( V_20 , L_135 ) ;
return;
} else if ( V_510 )
V_10 -> V_514 = 1 ;
if ( V_10 -> V_514 == 0 ) {
F_5 ( V_20 , L_136 ) ;
return;
}
if ( ! F_190 ( V_408 , V_10 ) ) {
T_7 V_515 = F_189 ( V_10 -> V_512 . V_513 ) ;
F_5 ( V_20 , L_137 , V_515 ) ;
if ( V_510 == NULL ) {
if ( ( V_511 & V_516 ) == 0 )
V_515 &= ~ V_516 ;
if ( ( V_511 & V_517 ) == 0 ) {
if ( V_515 & V_517 )
F_5 ( V_59 , L_138 ) ;
V_515 &= ~ V_517 ;
} else if ( ( V_515 & V_517 ) == 0 ) {
F_5 ( V_59 , L_139 ) ;
F_5 ( V_59 , L_140 ) ;
}
}
if ( V_515 & V_518 )
F_5 ( V_59 , L_141 ) ;
V_515 &= V_519 ;
if ( V_510 && V_510 -> V_300 )
V_515 &= ~ V_516 ;
else if ( V_516 & V_515 ) {
F_5 ( V_20 , L_142 ) ;
if ( V_446 )
V_446 -> V_455 |=
V_520 ;
}
if ( V_510 && V_510 -> V_228 == 0 )
V_515 &= ~ V_517 ;
else if ( V_515 & V_517 ) {
F_5 ( V_20 , L_143 ) ;
if ( V_446 )
V_446 -> V_455 |=
V_521 ;
}
F_5 ( V_20 , L_144 , ( int ) V_515 ) ;
#ifdef F_61
if ( V_515 & V_522 )
F_5 ( V_20 , L_145 ) ;
if ( V_515 & V_523 )
F_5 ( V_20 , L_146 ) ;
if ( V_515 & V_517 )
F_5 ( V_20 , L_147 ) ;
if ( V_515 & V_524 )
F_5 ( V_20 , L_148 ) ;
if ( V_515 & V_516 )
F_5 ( V_20 , L_149 ) ;
if ( V_515 & V_525 )
F_5 ( V_20 , L_150 ) ;
if ( V_515 & V_526 )
F_5 ( V_20 , L_151 ) ;
if ( V_515 & V_527 )
F_5 ( V_20 , L_152 ) ;
if ( V_515 & V_518 )
F_5 ( V_20 , L_153 ) ;
#endif
if ( F_191 ( V_408 , V_10 , V_515 ) ) {
if ( V_510 == NULL ) {
F_5 ( V_20 , L_154 ) ;
} else
F_5 ( V_59 , L_155 ) ;
}
}
}
void F_192 ( struct V_147 * V_528 ,
struct V_445 * V_446 )
{
F_130 ( & V_446 -> V_529 , V_530 ) ;
F_129 ( & V_446 -> V_531 ) ;
V_446 -> V_532 = V_533 ;
V_446 -> V_330 = V_528 -> V_330 ;
V_446 -> V_332 = V_528 -> V_332 ;
V_446 -> V_457 = V_528 -> V_221 ;
V_446 -> V_458 = V_528 -> V_222 ;
V_446 -> V_459 = V_528 -> V_224 ;
V_446 -> V_460 = V_528 -> V_223 ;
F_5 ( V_20 , L_156 ,
V_446 -> V_459 , V_446 -> V_460 ) ;
V_446 -> V_230 = V_528 -> V_230 ;
V_446 -> V_426 = V_528 -> V_426 ;
if ( V_528 -> V_254 )
V_446 -> V_455 |= V_534 ;
if ( V_528 -> V_279 )
V_446 -> V_455 |= V_535 ;
if ( V_528 -> V_229 )
V_446 -> V_455 |= V_536 ;
if ( V_528 -> V_257 )
V_446 -> V_455 |= V_537 ;
if ( V_528 -> V_240 )
V_446 -> V_455 |= V_538 ;
if ( V_528 -> V_260 )
V_446 -> V_455 |= V_539 ;
if ( V_528 -> V_271 )
V_446 -> V_455 |= V_540 ;
if ( V_528 -> V_290 )
V_446 -> V_455 |= V_541 ;
if ( V_528 -> V_277 )
V_446 -> V_455 |= V_542 ;
if ( V_528 -> V_295 )
V_446 -> V_455 |= V_543 ;
if ( V_528 -> V_297 )
V_446 -> V_455 |= V_544 ;
if ( V_528 -> V_234 ) {
V_446 -> V_455 |= V_545 ;
V_446 -> V_546 = V_528 -> V_319 ;
}
if ( V_528 -> V_235 ) {
V_446 -> V_455 |= V_547 ;
V_446 -> V_548 = V_528 -> V_321 ;
}
if ( V_528 -> V_207 )
V_446 -> V_455 |= V_549 ;
if ( V_528 -> V_208 )
V_446 -> V_455 |= V_550 ;
if ( V_528 -> V_282 )
V_446 -> V_455 |= V_551 ;
if ( V_528 -> V_310 )
V_446 -> V_455 |= V_552 ;
if ( V_528 -> V_314 )
V_446 -> V_455 |= ( V_553 |
V_534 ) ;
if ( V_528 -> V_174 )
V_446 -> V_455 |= V_554 ;
if ( V_528 -> V_173 ) {
F_5 ( V_20 , L_157 ) ;
V_446 -> V_455 |= V_555 ;
}
if ( V_528 -> V_312 ) {
if ( V_528 -> V_260 ) {
F_5 ( V_59 , L_158 ) ;
} else {
V_446 -> V_455 |= V_556 ;
}
}
if ( ( V_528 -> V_297 ) && ( V_528 -> V_282 ) )
F_5 ( V_59 , L_159 ) ;
}
static void
F_193 ( struct V_147 * V_390 )
{
F_11 ( V_390 -> V_336 ) ;
F_194 ( V_390 -> V_341 ) ;
F_11 ( V_390 -> V_196 ) ;
F_11 ( V_390 -> V_348 ) ;
F_11 ( V_390 -> V_352 ) ;
F_11 ( V_390 -> V_197 ) ;
}
void
F_195 ( struct V_147 * V_390 )
{
if ( ! V_390 )
return;
F_193 ( V_390 ) ;
F_11 ( V_390 ) ;
}
static char *
F_196 ( const struct V_147 * V_148 ,
const struct V_445 * V_446 )
{
char * V_557 , * V_194 ;
unsigned int V_558 = V_148 -> V_197 ? strlen ( V_148 -> V_197 ) + 1 : 0 ;
unsigned int V_559 = F_93 ( V_148 -> V_196 , V_431 + 1 ) ;
V_557 = F_35 ( V_559 + V_558 + 1 , V_117 ) ;
if ( V_557 == NULL )
return F_71 ( - V_83 ) ;
strncpy ( V_557 , V_148 -> V_196 , V_559 ) ;
V_194 = V_557 + V_559 ;
if ( V_558 ) {
* V_194 = F_197 ( V_446 ) ;
strncpy ( V_194 + 1 , V_148 -> V_197 , V_558 ) ;
V_194 += V_558 ;
}
* V_194 = '\0' ;
F_89 ( V_557 , F_197 ( V_446 ) ) ;
F_5 ( V_20 , L_160 , V_21 , V_557 ) ;
return V_557 ;
}
static int
F_198 ( const unsigned int V_408 , struct V_7 * V_8 ,
struct V_147 * V_390 , struct V_445 * V_446 ,
int V_560 )
{
int V_3 ;
unsigned int V_467 = 0 ;
struct V_468 * V_469 = NULL ;
char * V_557 = NULL , * V_561 = NULL , * V_562 = NULL ;
V_557 = F_196 ( V_390 , V_446 ) ;
if ( F_125 ( V_557 ) )
return F_126 ( V_557 ) ;
V_561 = V_560 ? V_557 + 1 : V_390 -> V_196 + 1 ;
V_3 = F_175 ( V_408 , V_8 , V_561 , V_446 -> V_426 ,
& V_467 , & V_469 ,
V_446 -> V_455 & V_537 ) ;
if ( ! V_3 && V_467 > 0 ) {
char * V_563 = NULL ;
V_562 = F_199 ( V_446 -> V_198 ,
V_557 + 1 , V_469 ,
& V_563 ) ;
F_200 ( V_469 , V_467 ) ;
if ( F_125 ( V_562 ) ) {
V_3 = F_126 ( V_562 ) ;
V_562 = NULL ;
} else {
F_193 ( V_390 ) ;
V_3 = F_201 ( V_390 , V_562 ,
V_563 ) ;
}
F_11 ( V_563 ) ;
F_11 ( V_446 -> V_198 ) ;
V_446 -> V_198 = V_562 ;
}
F_11 ( V_557 ) ;
return V_3 ;
}
static int
F_201 ( struct V_147 * V_390 , char * V_564 ,
const char * V_193 )
{
int V_3 = 0 ;
if ( F_91 ( V_564 , V_193 , V_390 ) )
return - V_141 ;
if ( V_390 -> V_170 ) {
F_5 ( V_20 , L_161 ) ;
F_11 ( V_390 -> V_336 ) ;
V_390 -> V_336 = NULL ;
} else if ( V_390 -> V_336 ) {
F_5 ( V_20 , L_162 , V_390 -> V_336 ) ;
} else {
F_5 ( V_59 , L_163 ) ;
return - V_141 ;
}
if ( V_390 -> V_352 == NULL ) {
V_390 -> V_426 = F_202 () ;
} else {
V_390 -> V_426 = F_203 ( V_390 -> V_352 ) ;
if ( V_390 -> V_426 == NULL ) {
F_5 ( V_59 , L_164 ,
V_390 -> V_352 ) ;
return - V_565 ;
}
}
return V_3 ;
}
struct V_147 *
F_204 ( char * V_564 , const char * V_193 )
{
int V_3 ;
struct V_147 * V_390 ;
V_390 = F_35 ( sizeof( struct V_147 ) , V_117 ) ;
if ( ! V_390 )
return F_71 ( - V_83 ) ;
V_3 = F_201 ( V_390 , V_564 , V_193 ) ;
if ( V_3 ) {
F_195 ( V_390 ) ;
V_390 = F_71 ( V_3 ) ;
}
return V_390 ;
}
int
F_205 ( struct V_445 * V_446 , struct V_147 * V_390 )
{
int V_3 ;
unsigned int V_408 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_557 ;
struct V_439 * V_440 ;
#ifdef F_206
int V_566 = 0 ;
#endif
V_3 = F_207 ( & V_446 -> V_567 , L_165 , V_568 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_206
V_569:
if ( V_566 ) {
if ( V_10 )
F_159 ( V_10 ) ;
else if ( V_8 )
F_141 ( V_8 ) ;
F_154 ( V_408 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_557 = NULL ;
V_440 = NULL ;
V_408 = F_142 () ;
V_2 = F_122 ( V_390 ) ;
if ( F_125 ( V_2 ) ) {
V_3 = F_126 ( V_2 ) ;
F_208 ( & V_446 -> V_567 ) ;
goto V_463;
}
V_8 = F_152 ( V_2 , V_390 ) ;
if ( F_125 ( V_8 ) ) {
V_3 = F_126 ( V_8 ) ;
V_8 = NULL ;
goto V_570;
}
V_10 = F_162 ( V_8 , V_390 ) ;
if ( F_125 ( V_10 ) ) {
V_3 = F_126 ( V_10 ) ;
V_10 = NULL ;
goto V_571;
}
if ( F_209 ( V_10 -> V_8 ) ) {
F_188 ( V_408 , V_10 , V_446 , V_390 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_189 ( V_10 -> V_512 . V_513 ) &
V_518 ) ) {
V_3 = - V_572 ;
goto V_570;
}
} else
V_10 -> V_514 = 0 ;
if ( ! V_10 -> V_573 && V_2 -> V_49 -> V_574 )
V_2 -> V_49 -> V_574 ( V_408 , V_10 ) ;
V_446 -> V_332 = V_2 -> V_49 -> V_575 ( V_10 , V_390 ) ;
V_446 -> V_330 = V_2 -> V_49 -> V_576 ( V_10 , V_390 ) ;
V_446 -> V_567 . V_577 = V_446 -> V_330 / V_578 ;
V_571:
#ifdef F_206
if ( V_566 == 0 ) {
int V_579 = F_198 ( V_408 , V_8 , V_390 , V_446 ,
false ) ;
if ( ! V_579 ) {
V_566 ++ ;
goto V_569;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_49 -> V_580 ) {
V_3 = - V_55 ;
goto V_570;
}
V_557 = F_210 ( V_390 , V_446 , V_10 ) ;
if ( V_557 == NULL ) {
V_3 = - V_83 ;
goto V_570;
}
V_3 = V_2 -> V_49 -> V_580 ( V_408 , V_10 , V_446 ,
V_557 ) ;
if ( V_3 != 0 && V_3 != - V_581 ) {
F_11 ( V_557 ) ;
goto V_570;
}
F_11 ( V_557 ) ;
}
if ( V_3 == - V_581 ) {
#ifdef F_206
if ( V_566 > V_582 ) {
V_3 = - V_583 ;
goto V_570;
}
V_3 = F_198 ( V_408 , V_8 , V_390 , V_446 , true ) ;
if ( ! V_3 ) {
V_566 ++ ;
goto V_569;
}
goto V_570;
#else
V_3 = - V_584 ;
#endif
}
if ( V_3 )
goto V_570;
V_440 = F_99 ( sizeof *V_440 , V_117 ) ;
if ( V_440 == NULL ) {
V_3 = - V_83 ;
goto V_570;
}
V_440 -> V_585 = V_8 -> V_221 ;
V_440 -> V_586 = V_10 ;
V_440 -> V_444 = V_38 ;
F_211 ( V_587 , & V_440 -> V_443 ) ;
F_211 ( V_442 , & V_440 -> V_443 ) ;
V_446 -> V_447 = V_440 ;
F_2 ( & V_446 -> V_531 ) ;
F_212 ( & V_446 -> V_532 , V_440 ) ;
F_3 ( & V_446 -> V_531 ) ;
F_24 ( V_57 , & V_446 -> V_529 ,
V_588 ) ;
V_570:
if ( V_3 ) {
if ( V_10 )
F_159 ( V_10 ) ;
else if ( V_8 )
F_141 ( V_8 ) ;
else
F_116 ( V_2 ) ;
F_208 ( & V_446 -> V_567 ) ;
}
V_463:
F_154 ( V_408 ) ;
return V_3 ;
}
int
F_213 ( const unsigned int V_408 , struct V_7 * V_8 ,
const char * V_589 , struct V_9 * V_10 ,
const struct V_465 * V_466 )
{
struct V_484 * V_590 ;
struct V_484 * V_591 ;
T_8 * V_592 ;
T_9 * V_593 ;
unsigned char * V_594 ;
int V_3 = 0 ;
int V_78 ;
T_10 V_595 , V_596 ;
if ( V_8 == NULL )
return - V_597 ;
V_590 = F_26 () ;
if ( V_590 == NULL )
return - V_83 ;
V_591 = V_590 ;
F_214 ( V_590 , V_598 ,
NULL , 4 ) ;
V_590 -> V_599 = F_215 ( V_8 -> V_2 ) ;
V_590 -> V_600 = V_8 -> V_601 ;
V_592 = ( T_8 * ) V_590 ;
V_593 = ( T_9 * ) V_591 ;
V_592 -> V_602 = 0xFF ;
V_592 -> V_436 = F_216 ( V_603 ) ;
V_594 = & V_592 -> V_604 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_605 & V_606 ) ) {
V_592 -> V_607 = F_216 ( 1 ) ;
* V_594 = 0 ;
V_594 ++ ;
} else {
V_592 -> V_607 = F_216 ( V_608 ) ;
#ifdef F_84
if ( ( V_609 & V_610 ) &&
( V_8 -> V_150 == V_168 ) )
F_217 ( V_10 -> V_341 , V_8 -> V_2 -> V_611 ,
V_8 -> V_2 -> V_605 &
V_612 ? true : false ,
V_594 ) ;
else
#endif
V_3 = F_218 ( V_10 -> V_341 , V_8 -> V_2 -> V_611 ,
V_594 , V_466 ) ;
V_594 += V_608 ;
if ( V_8 -> V_613 & V_614 ) {
* V_594 = 0 ;
V_594 ++ ;
}
}
if ( V_8 -> V_2 -> V_152 )
V_590 -> V_615 |= V_616 ;
if ( V_8 -> V_613 & V_617 ) {
V_590 -> V_615 |= V_618 ;
}
if ( V_8 -> V_613 & V_619 ) {
V_590 -> V_615 |= V_620 ;
}
if ( V_8 -> V_613 & V_614 ) {
V_590 -> V_615 |= V_621 ;
V_78 =
F_219 ( ( V_622 * ) V_594 , V_589 ,
6 *
( + 256 ) , V_466 ) ;
V_594 += 2 * V_78 ;
V_594 += 2 ;
} else {
strcpy ( V_594 , V_589 ) ;
V_594 += strlen ( V_589 ) + 1 ;
}
strcpy ( V_594 , L_166 ) ;
V_594 += strlen ( L_166 ) ;
V_594 += 1 ;
V_596 = V_594 - & V_592 -> V_604 [ 0 ] ;
V_592 -> V_623 . V_495 = F_184 ( F_220 (
V_592 -> V_623 . V_495 ) + V_596 ) ;
V_592 -> V_624 = F_216 ( V_596 ) ;
V_3 = F_221 ( V_408 , V_8 , V_590 , V_591 , & V_78 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_625 ;
V_10 -> V_429 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_626 = V_591 -> V_627 ;
V_594 = F_222 ( V_591 ) ;
V_595 = F_223 ( V_591 ) ;
V_78 = F_93 ( V_594 , V_595 - 2 ) ;
if ( V_590 -> V_615 & V_621 )
V_625 = true ;
else
V_625 = false ;
if ( V_78 == 3 ) {
if ( ( V_594 [ 0 ] == 'I' ) && ( V_594 [ 1 ] == 'P' ) &&
( V_594 [ 2 ] == 'C' ) ) {
F_5 ( V_20 , L_167 ) ;
V_10 -> V_573 = 1 ;
}
} else if ( V_78 == 2 ) {
if ( ( V_594 [ 0 ] == 'A' ) && ( V_594 [ 1 ] == ':' ) ) {
F_5 ( V_20 , L_168 ) ;
}
}
V_594 += V_78 + 1 ;
V_595 -= ( V_78 + 1 ) ;
F_224 ( V_10 -> V_430 , V_589 , sizeof( V_10 -> V_430 ) ) ;
F_11 ( V_10 -> V_628 ) ;
V_10 -> V_628 = F_225 ( V_594 ,
V_595 , V_625 ,
V_466 ) ;
F_5 ( V_20 , L_169 , V_10 -> V_628 ) ;
if ( ( V_591 -> V_629 == 3 ) ||
( V_591 -> V_629 == 7 ) )
V_10 -> V_436 = F_226 ( V_593 -> V_630 ) ;
else
V_10 -> V_436 = 0 ;
F_5 ( V_20 , L_170 , V_10 -> V_436 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_591 -> V_627 ;
}
F_63 ( V_590 ) ;
return V_3 ;
}
static void F_227 ( struct V_631 * V_123 )
{
struct V_445 * V_632 = F_22 ( V_123 , struct V_445 , V_633 ) ;
F_228 ( V_632 -> V_426 ) ;
F_11 ( V_632 ) ;
}
void
F_229 ( struct V_445 * V_446 )
{
struct V_634 * V_635 = & V_446 -> V_532 ;
struct V_636 * V_637 ;
struct V_439 * V_440 ;
F_118 ( & V_446 -> V_529 ) ;
F_2 ( & V_446 -> V_531 ) ;
while ( ( V_637 = F_230 ( V_635 ) ) ) {
V_440 = F_231 ( V_637 , struct V_439 , V_638 ) ;
F_174 ( V_440 ) ;
F_232 ( V_442 , & V_440 -> V_443 ) ;
F_233 ( V_637 , V_635 ) ;
F_3 ( & V_446 -> V_531 ) ;
F_165 ( V_440 ) ;
F_2 ( & V_446 -> V_531 ) ;
}
F_3 ( & V_446 -> V_531 ) ;
F_208 ( & V_446 -> V_567 ) ;
F_11 ( V_446 -> V_198 ) ;
F_234 ( & V_446 -> V_633 , F_227 ) ;
}
int
F_153 ( const unsigned int V_408 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_49 -> V_50 || ! V_2 -> V_49 -> V_639 )
return - V_55 ;
if ( ! V_2 -> V_49 -> V_50 ( V_2 ) )
return 0 ;
F_235 ( V_2 , 1 ) ;
V_3 = V_2 -> V_49 -> V_639 ( V_408 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_640 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_155 ( const unsigned int V_408 , struct V_7 * V_8 ,
struct V_465 * V_641 )
{
int V_3 = - V_55 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_613 = V_2 -> V_613 ;
if ( V_642 == 0 )
V_8 -> V_613 &= ( ~ V_2 -> V_180 -> F_209 ) ;
F_5 ( V_20 , L_171 ,
V_2 -> V_605 , V_2 -> V_613 , V_2 -> V_643 ) ;
if ( V_2 -> V_49 -> V_644 )
V_3 = V_2 -> V_49 -> V_644 ( V_408 , V_8 , V_641 ) ;
if ( V_3 )
F_5 ( V_59 , L_172 , V_3 ) ;
return V_3 ;
}
static int
F_236 ( struct V_147 * V_148 , struct V_7 * V_8 )
{
V_148 -> V_150 = V_8 -> V_150 ;
if ( V_148 -> V_150 == V_157 )
return 0 ;
return F_145 ( V_148 , V_8 ) ;
}
static struct V_9 *
F_237 ( struct V_445 * V_446 , T_3 V_645 )
{
int V_3 ;
struct V_9 * V_646 = F_238 ( V_446 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_147 * V_510 ;
V_510 = F_99 ( sizeof( * V_510 ) , V_117 ) ;
if ( V_510 == NULL )
return F_71 ( - V_83 ) ;
V_510 -> V_426 = V_446 -> V_426 ;
V_510 -> V_221 = V_645 ;
V_510 -> V_220 = V_645 ;
V_510 -> V_196 = V_646 -> V_430 ;
V_510 -> V_251 = V_646 -> V_251 ;
V_510 -> V_269 = V_646 -> V_269 ;
V_510 -> V_303 = V_646 -> V_303 ;
V_510 -> V_267 = ! V_646 -> V_514 ;
V_510 -> V_150 = V_646 -> V_8 -> V_150 ;
V_510 -> V_152 = V_646 -> V_8 -> V_152 ;
V_3 = F_236 ( V_510 , V_646 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_71 ( V_3 ) ;
goto V_463;
}
F_2 ( & V_22 ) ;
++ V_646 -> V_8 -> V_2 -> V_387 ;
F_3 ( & V_22 ) ;
V_8 = F_152 ( V_646 -> V_8 -> V_2 , V_510 ) ;
if ( F_125 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_116 ( V_646 -> V_8 -> V_2 ) ;
goto V_463;
}
V_10 = F_162 ( V_8 , V_510 ) ;
if ( F_125 ( V_10 ) ) {
F_141 ( V_8 ) ;
goto V_463;
}
if ( F_209 ( V_8 ) )
F_188 ( 0 , V_10 , NULL , V_510 ) ;
V_463:
F_11 ( V_510 -> V_336 ) ;
F_11 ( V_510 -> V_341 ) ;
F_11 ( V_510 ) ;
return V_10 ;
}
struct V_9 *
F_238 ( struct V_445 * V_446 )
{
return F_168 ( F_169 ( V_446 ) ) ;
}
static struct V_439 *
F_239 ( struct V_634 * V_635 , T_3 V_145 )
{
struct V_636 * V_637 = V_635 -> V_636 ;
struct V_439 * V_440 ;
while ( V_637 ) {
V_440 = F_231 ( V_637 , struct V_439 , V_638 ) ;
if ( F_240 ( V_440 -> V_585 , V_145 ) )
V_637 = V_637 -> V_647 ;
else if ( F_241 ( V_440 -> V_585 , V_145 ) )
V_637 = V_637 -> V_648 ;
else
return V_440 ;
}
return NULL ;
}
static void
F_212 ( struct V_634 * V_635 , struct V_439 * V_649 )
{
struct V_636 * * V_65 = & ( V_635 -> V_636 ) , * V_650 = NULL ;
struct V_439 * V_440 ;
while ( * V_65 ) {
V_440 = F_231 ( * V_65 , struct V_439 , V_638 ) ;
V_650 = * V_65 ;
if ( F_240 ( V_440 -> V_585 , V_649 -> V_585 ) )
V_65 = & ( ( * V_65 ) -> V_647 ) ;
else
V_65 = & ( ( * V_65 ) -> V_648 ) ;
}
F_242 ( & V_649 -> V_638 , V_650 , V_65 ) ;
F_243 ( & V_649 -> V_638 , V_635 ) ;
}
struct V_439 *
F_244 ( struct V_445 * V_446 )
{
int V_651 ;
T_3 V_645 = F_245 () ;
struct V_439 * V_440 , * V_652 ;
if ( ! ( V_446 -> V_455 & V_553 ) )
return F_174 ( F_169 ( V_446 ) ) ;
F_2 ( & V_446 -> V_531 ) ;
V_440 = F_239 ( & V_446 -> V_532 , V_645 ) ;
if ( V_440 )
F_174 ( V_440 ) ;
F_3 ( & V_446 -> V_531 ) ;
if ( V_440 == NULL ) {
V_652 = F_99 ( sizeof( * V_440 ) , V_117 ) ;
if ( V_652 == NULL )
return F_71 ( - V_83 ) ;
V_652 -> V_585 = V_645 ;
V_652 -> V_586 = F_71 ( - V_572 ) ;
F_211 ( V_653 , & V_652 -> V_443 ) ;
F_211 ( V_442 , & V_652 -> V_443 ) ;
F_174 ( V_652 ) ;
F_2 ( & V_446 -> V_531 ) ;
V_440 = F_239 ( & V_446 -> V_532 , V_645 ) ;
if ( V_440 ) {
F_174 ( V_440 ) ;
F_3 ( & V_446 -> V_531 ) ;
F_11 ( V_652 ) ;
goto V_654;
}
V_440 = V_652 ;
F_212 ( & V_446 -> V_532 , V_440 ) ;
F_3 ( & V_446 -> V_531 ) ;
} else {
V_654:
V_651 = F_246 ( & V_440 -> V_443 , V_653 ,
V_135 ) ;
if ( V_651 ) {
F_165 ( V_440 ) ;
return F_71 ( - V_88 ) ;
}
if ( ! F_125 ( V_440 -> V_586 ) )
return V_440 ;
if ( F_23 ( V_38 , V_440 -> V_444 + V_655 ) ) {
F_165 ( V_440 ) ;
return F_71 ( - V_572 ) ;
}
if ( F_247 ( V_653 , & V_440 -> V_443 ) )
goto V_654;
}
V_440 -> V_586 = F_237 ( V_446 , V_645 ) ;
F_232 ( V_653 , & V_440 -> V_443 ) ;
F_248 ( & V_440 -> V_443 , V_653 ) ;
if ( F_125 ( V_440 -> V_586 ) ) {
F_165 ( V_440 ) ;
return F_71 ( - V_572 ) ;
}
return V_440 ;
}
static void
V_530 ( struct V_46 * V_47 )
{
struct V_445 * V_446 = F_22 ( V_47 , struct V_445 ,
V_529 . V_47 ) ;
struct V_634 * V_635 = & V_446 -> V_532 ;
struct V_636 * V_637 = F_230 ( V_635 ) ;
struct V_636 * V_5 ;
struct V_439 * V_440 ;
F_2 ( & V_446 -> V_531 ) ;
V_637 = F_230 ( V_635 ) ;
while ( V_637 != NULL ) {
V_5 = V_637 ;
V_637 = F_249 ( V_5 ) ;
V_440 = F_231 ( V_5 , struct V_439 , V_638 ) ;
if ( F_167 ( V_587 , & V_440 -> V_443 ) ||
F_60 ( & V_440 -> V_441 ) != 0 ||
F_30 ( V_440 -> V_444 + V_588 , V_38 ) )
continue;
F_174 ( V_440 ) ;
F_232 ( V_442 , & V_440 -> V_443 ) ;
F_233 ( V_5 , V_635 ) ;
F_3 ( & V_446 -> V_531 ) ;
F_165 ( V_440 ) ;
F_2 ( & V_446 -> V_531 ) ;
}
F_3 ( & V_446 -> V_531 ) ;
F_24 ( V_57 , & V_446 -> V_529 ,
V_588 ) ;
}
