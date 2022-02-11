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
V_148 -> V_223 = true ;
V_148 -> V_224 = V_148 -> V_225 = V_226 | V_227 | V_228 ;
V_148 -> V_229 = 1 ;
V_148 -> V_230 = 1 ;
V_148 -> V_174 = true ;
V_148 -> V_231 = V_232 ;
V_148 -> V_49 = & V_179 ;
V_148 -> V_180 = & V_181 ;
if ( ! V_198 )
goto V_233;
V_201 = F_88 ( V_198 , V_234 , V_117 ) ;
if ( ! V_201 )
goto V_233;
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
V_148 -> V_235 = false ;
V_148 -> V_236 = false ;
switch ( F_87 ( V_193 , V_148 ) ) {
case 0 :
break;
case - V_83 :
F_5 ( V_59 , L_36 ) ;
goto V_233;
case - V_141 :
F_5 ( V_59 , L_37 ) ;
goto V_233;
default:
F_5 ( V_59 , L_38 ) ;
goto V_233;
}
while ( ( V_199 = F_96 ( & V_202 , V_206 ) ) != NULL ) {
T_2 args [ V_149 ] ;
unsigned long V_142 ;
int V_237 ;
if ( ! * V_199 )
continue;
V_237 = F_83 ( V_199 , V_238 , args ) ;
switch ( V_237 ) {
case V_239 :
break;
case V_240 :
V_148 -> V_241 = 0 ;
break;
case V_242 :
V_148 -> V_241 = 1 ;
break;
case V_243 :
V_207 = 1 ;
break;
case V_244 :
V_207 = 0 ;
break;
case V_245 :
V_208 = 1 ;
break;
case V_246 :
V_208 = 0 ;
break;
case V_247 :
V_148 -> V_248 = 1 ;
break;
case V_249 :
V_148 -> V_250 = 1 ;
break;
case V_251 :
V_148 -> V_252 = 1 ;
break;
case V_253 :
V_148 -> V_252 = 0 ;
break;
case V_254 :
V_148 -> V_255 = 0 ;
break;
case V_256 :
V_148 -> V_255 = 1 ;
break;
case V_257 :
V_148 -> V_258 = true ;
V_148 -> V_223 = false ;
break;
case V_259 :
V_148 -> V_258 = false ;
break;
case V_260 :
V_148 -> V_223 = true ;
V_148 -> V_258 = false ;
break;
case V_261 :
V_148 -> V_223 = false ;
break;
case V_262 :
V_148 -> V_263 = 1 ;
break;
case V_264 :
V_148 -> V_263 = 0 ;
break;
case V_265 :
V_148 -> V_266 = 1 ;
break;
case V_267 :
V_148 -> V_229 = 1 ;
break;
case V_268 :
V_148 -> V_229 = 0 ;
break;
case V_269 :
V_148 -> V_270 = 1 ;
break;
case V_271 :
V_148 -> V_272 = 1 ;
break;
case V_273 :
V_148 -> V_274 = 0 ;
break;
case V_275 :
V_148 -> V_274 = 1 ;
if ( V_148 -> V_225 ==
( V_276 & ~ ( V_277 | V_278 ) ) )
V_148 -> V_225 = V_276 ;
break;
case V_279 :
V_148 -> V_280 = 1 ;
break;
case V_281 :
V_148 -> V_282 = 1 ;
break;
case V_283 :
V_148 -> V_282 = 0 ;
break;
case V_284 :
V_148 -> V_285 = true ;
break;
case V_286 :
V_148 -> V_285 = false ;
break;
case V_287 :
V_148 -> V_252 = 0 ;
break;
case V_288 :
V_148 -> V_252 = 1 ;
break;
case V_289 :
V_148 -> V_290 = 0 ;
break;
case V_291 :
V_148 -> V_290 = 1 ;
break;
case V_292 :
V_148 -> V_293 = 1 ;
break;
case V_294 :
V_148 -> V_293 = 0 ;
break;
case V_295 :
V_148 -> V_230 = 1 ;
break;
case V_296 :
V_148 -> V_230 = 0 ;
break;
case V_297 :
V_148 -> V_298 = 1 ;
break;
case V_299 :
V_148 -> V_300 = 1 ;
break;
case V_301 :
V_148 -> V_300 = 0 ;
break;
case V_302 :
V_148 -> V_303 = 0 ;
break;
case V_304 :
V_148 -> V_303 = 1 ;
break;
case V_305 :
V_148 -> V_306 = 1 ;
break;
case V_307 :
V_148 -> V_152 = true ;
break;
case V_308 :
V_148 -> V_309 = 1 ;
break;
case V_310 :
F_97 ( V_311 L_39
L_40
L_41 ) ;
break;
case V_312 :
#ifndef F_98
F_5 ( V_59 , L_42 ) ;
goto V_233;
#endif
V_148 -> V_313 = true ;
break;
case V_314 :
V_148 -> V_315 = true ;
break;
case V_316 :
V_148 -> V_317 = true ;
break;
case V_318 :
V_211 = true ;
break;
case V_319 :
V_148 -> V_320 = true ;
break;
case V_321 :
if ( F_75 ( args , & V_148 -> V_322 ) ) {
F_5 ( V_59 , L_43 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_235 = true ;
break;
case V_323 :
if ( F_79 ( args , & V_148 -> V_324 ) ) {
F_5 ( V_59 , L_44 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_236 = true ;
break;
case V_325 :
if ( F_75 ( args , & V_148 -> V_221 ) ) {
F_5 ( V_59 , L_45 ,
V_21 ) ;
goto V_233;
}
V_209 = true ;
break;
case V_326 :
if ( F_75 ( args , & V_148 -> V_220 ) ) {
F_5 ( V_59 , L_46 ,
V_21 ) ;
goto V_233;
}
break;
case V_327 :
if ( F_79 ( args , & V_148 -> V_222 ) ) {
F_5 ( V_59 , L_47 ,
V_21 ) ;
goto V_233;
}
V_210 = true ;
break;
case V_328 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_48 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_225 = V_142 ;
break;
case V_329 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_49 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_224 = V_142 ;
break;
case V_330 :
if ( F_72 ( args , & V_142 ) ||
V_142 > V_331 ) {
F_5 ( V_59 , L_50 ,
V_21 ) ;
goto V_233;
}
V_216 = ( unsigned short ) V_142 ;
break;
case V_332 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_51 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_333 = V_142 ;
break;
case V_334 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_52 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_335 = V_142 ;
break;
case V_336 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_53 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_231 = V_53 * V_142 ;
if ( V_148 -> V_231 > V_337 ) {
F_5 ( V_59 , L_54 ) ;
goto V_233;
}
break;
case V_338 :
V_148 -> V_170 = 1 ;
V_148 -> V_339 = NULL ;
break;
case V_340 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_341;
if ( F_93 ( string , V_342 ) >
V_342 ) {
F_97 ( V_311 L_55 ) ;
goto V_233;
}
V_148 -> V_339 = F_90 ( string , V_117 ) ;
if ( ! V_148 -> V_339 )
goto V_233;
break;
case V_343 :
V_214 = strchr ( V_199 , '=' ) ;
V_214 ++ ;
if ( ! ( V_214 < V_200 && V_214 [ 1 ] == V_140 ) ) {
F_11 ( V_148 -> V_344 ) ;
V_148 -> V_344 = NULL ;
break;
}
case V_345 :
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
F_11 ( V_148 -> V_344 ) ;
V_203 = strlen ( V_144 ) ;
V_148 -> V_344 = F_99 ( V_203 + 1 , V_117 ) ;
if ( V_148 -> V_344 == NULL ) {
F_97 ( V_311 L_56
L_57 ) ;
goto V_233;
}
for ( V_204 = 0 , V_205 = 0 ; V_204 < V_203 ; V_204 ++ , V_205 ++ ) {
V_148 -> V_344 [ V_205 ] = V_144 [ V_204 ] ;
if ( ( V_144 [ V_204 ] == V_140 ) &&
V_144 [ V_204 + 1 ] == V_140 )
V_204 ++ ;
}
V_148 -> V_344 [ V_205 ] = '\0' ;
break;
case V_346 :
V_215 = false ;
break;
case V_347 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_341;
if ( ! F_100 ( V_97 , string ,
strlen ( string ) ) ) {
F_97 ( V_348 L_58 ,
string ) ;
goto V_233;
}
V_215 = true ;
break;
case V_349 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_341;
if ( F_93 ( string , V_350 )
== V_350 ) {
F_97 ( V_311 L_59
L_60 ) ;
goto V_233;
}
V_148 -> V_351 = F_90 ( string , V_117 ) ;
if ( ! V_148 -> V_351 ) {
F_97 ( V_311 L_56
L_61 ) ;
goto V_233;
}
F_5 ( V_20 , L_62 ) ;
break;
case V_352 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_341;
if ( ! F_100 (
(struct V_96 * ) & V_148 -> V_353 ,
string , strlen ( string ) ) ) {
F_97 ( V_311 L_63
L_64 , string ) ;
goto V_233;
}
break;
case V_354 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_341;
if ( F_93 ( string , 1024 ) >= 65 ) {
F_97 ( V_311 L_65
L_66 ) ;
goto V_233;
}
if ( strncasecmp ( string , L_67 , 7 ) != 0 ) {
V_148 -> V_355 = F_90 ( string ,
V_117 ) ;
if ( ! V_148 -> V_355 ) {
F_97 ( V_311 L_68
L_69 ) ;
goto V_233;
}
}
F_5 ( V_20 , L_70 , string ) ;
break;
case V_356 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_341;
memset ( V_148 -> V_217 , 0x20 ,
V_218 ) ;
for ( V_204 = 0 ; V_204 < V_218 ; V_204 ++ ) {
if ( string [ V_204 ] == 0 )
break;
V_148 -> V_217 [ V_204 ] = string [ V_204 ] ;
}
if ( V_204 == V_218 && string [ V_204 ] != 0 )
F_97 ( V_311 L_71
L_72 ) ;
break;
case V_357 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_341;
memset ( V_148 -> V_219 , 0x20 ,
V_358 ) ;
for ( V_204 = 0 ; V_204 < 15 ; V_204 ++ ) {
if ( string [ V_204 ] == 0 )
break;
V_148 -> V_219 [ V_204 ] = string [ V_204 ] ;
}
if ( V_204 == V_218 && string [ V_204 ] != 0 )
F_97 ( V_311 L_73
L_74 ) ;
break;
case V_359 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_341;
if ( strncasecmp ( string , L_75 , 1 ) == 0 ) {
break;
}
F_97 ( V_311 L_76
L_77 ) ;
goto V_233;
case V_360 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_341;
if ( F_86 ( string , V_148 ) != 0 )
goto V_233;
break;
case V_361 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_341;
if ( F_82 ( string , V_148 ) != 0 )
goto V_233;
break;
case V_362 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_341;
if ( F_85 ( string , V_148 ) != 0 )
goto V_233;
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
F_97 ( V_348 L_78 , V_212 ) ;
goto V_233;
}
#ifndef F_101
if ( V_148 -> V_317 ) {
F_5 ( V_59 , L_79 ) ;
goto V_233;
}
#endif
if ( ! V_148 -> V_196 ) {
F_5 ( V_59 , L_80 ) ;
goto V_233;
}
if ( ! strchr ( V_148 -> V_196 + 3 , '\\' ) ) {
F_5 ( V_59 , L_81 ) ;
goto V_233;
}
if ( ! V_215 ) {
if ( ! F_100 ( V_97 , & V_148 -> V_196 [ 2 ] ,
strlen ( & V_148 -> V_196 [ 2 ] ) ) ) {
F_97 ( V_348 L_82
L_83 ) ;
goto V_233;
}
}
F_41 ( V_97 , V_216 ) ;
if ( V_209 )
V_148 -> V_207 = V_207 ;
else if ( V_207 == 1 )
F_97 ( V_363 L_84
L_85 ) ;
if ( V_210 )
V_148 -> V_208 = V_208 ;
else if ( V_208 == 1 )
F_97 ( V_363 L_86
L_87 ) ;
F_11 ( V_201 ) ;
return 0 ;
V_341:
F_97 ( V_311 L_88 ) ;
V_233:
F_11 ( string ) ;
F_11 ( V_201 ) ;
return 1 ;
}
static bool
F_102 ( struct V_96 * V_353 , struct V_96 * V_364 )
{
switch ( V_353 -> V_365 ) {
case V_366 :
return ( V_364 -> V_365 == V_366 ) ;
case V_367 : {
struct V_368 * V_369 = (struct V_368 * ) V_353 ;
struct V_368 * V_370 = (struct V_368 * ) V_364 ;
return ( V_369 -> V_371 . V_372 == V_370 -> V_371 . V_372 ) ;
}
case V_373 : {
struct V_374 * V_375 = (struct V_374 * ) V_353 ;
struct V_374 * V_376 = (struct V_374 * ) V_364 ;
return F_103 ( & V_375 -> V_377 , & V_376 -> V_377 ) ;
}
default:
F_104 ( 1 ) ;
return false ;
}
}
static bool
F_105 ( struct V_1 * V_2 , struct V_96 * V_378 )
{
T_5 V_216 , * V_379 ;
switch ( V_378 -> V_365 ) {
case V_367 :
V_379 = & ( (struct V_368 * ) & V_2 -> V_97 ) -> V_380 ;
V_216 = ( (struct V_368 * ) V_378 ) -> V_380 ;
break;
case V_373 :
V_379 = & ( (struct V_374 * ) & V_2 -> V_97 ) -> V_381 ;
V_216 = ( (struct V_374 * ) V_378 ) -> V_381 ;
break;
default:
F_104 ( 1 ) ;
return false ;
}
if ( ! V_216 ) {
V_216 = F_106 ( V_98 ) ;
if ( V_216 == * V_379 )
return true ;
V_216 = F_106 ( V_382 ) ;
}
return V_216 == * V_379 ;
}
static bool
F_107 ( struct V_1 * V_2 , struct V_96 * V_378 ,
struct V_96 * V_353 )
{
switch ( V_378 -> V_365 ) {
case V_367 : {
struct V_368 * V_383 = (struct V_368 * ) V_378 ;
struct V_368 * V_384 =
(struct V_368 * ) & V_2 -> V_97 ;
if ( V_383 -> V_371 . V_372 != V_384 -> V_371 . V_372 )
return false ;
break;
}
case V_373 : {
struct V_374 * V_385 = (struct V_374 * ) V_378 ;
struct V_374 * V_386 =
(struct V_374 * ) & V_2 -> V_97 ;
if ( ! F_103 ( & V_385 -> V_377 ,
& V_386 -> V_377 ) )
return false ;
if ( V_385 -> V_387 != V_386 -> V_387 )
return false ;
break;
}
default:
F_104 ( 1 ) ;
return false ;
}
if ( ! F_102 ( V_353 , (struct V_96 * ) & V_2 -> V_353 ) )
return false ;
return true ;
}
static bool
F_108 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
if ( F_109 ( V_2 , V_148 -> V_150 ) == V_151 )
return false ;
if ( V_148 -> V_152 && ! V_2 -> V_152 )
return false ;
return true ;
}
static int F_110 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
struct V_96 * V_378 = (struct V_96 * ) & V_148 -> V_97 ;
if ( V_148 -> V_320 )
return 0 ;
if ( ( V_2 -> V_180 != V_148 -> V_180 ) || ( V_2 -> V_49 != V_148 -> V_49 ) )
return 0 ;
if ( ! F_111 ( F_112 ( V_2 ) , V_126 -> V_388 -> V_389 ) )
return 0 ;
if ( ! F_107 ( V_2 , V_378 ,
(struct V_96 * ) & V_148 -> V_353 ) )
return 0 ;
if ( ! F_105 ( V_2 , V_378 ) )
return 0 ;
if ( ! F_108 ( V_2 , V_148 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_113 ( struct V_147 * V_148 )
{
struct V_1 * V_2 ;
F_2 ( & V_22 ) ;
F_114 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_110 ( V_2 , V_148 ) )
continue;
++ V_2 -> V_390 ;
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
struct V_124 * V_391 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_390 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_116 ( F_112 ( V_2 ) ) ;
F_16 ( & V_2 -> V_107 ) ;
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
V_391 = F_65 ( & V_2 -> V_134 , NULL ) ;
if ( V_391 )
F_120 ( V_392 , V_391 ) ;
}
static struct V_1 *
F_121 ( struct V_147 * V_393 )
{
struct V_1 * V_394 = NULL ;
int V_3 ;
F_5 ( V_20 , L_90 , V_393 -> V_196 ) ;
V_394 = F_113 ( V_393 ) ;
if ( V_394 )
return V_394 ;
V_394 = F_99 ( sizeof( struct V_1 ) , V_117 ) ;
if ( ! V_394 ) {
V_3 = - V_83 ;
goto V_395;
}
V_394 -> V_49 = V_393 -> V_49 ;
V_394 -> V_180 = V_393 -> V_180 ;
F_122 ( V_394 , F_123 ( V_126 -> V_388 -> V_389 ) ) ;
V_394 -> V_56 = F_70 ( V_393 -> V_196 ) ;
if ( F_124 ( V_394 -> V_56 ) ) {
V_3 = F_125 ( V_394 -> V_56 ) ;
goto V_396;
}
V_394 -> V_248 = V_393 -> V_248 ;
V_394 -> V_250 = V_393 -> V_250 ;
V_394 -> V_397 = V_393 -> V_398 ;
V_394 -> V_399 = 0 ;
V_394 -> V_109 = 1 ;
F_126 ( & V_394 -> V_63 ) ;
F_126 ( & V_394 -> V_110 ) ;
F_13 ( & V_394 -> V_111 ) ;
F_127 ( & V_394 -> V_27 ) ;
memcpy ( V_394 -> V_400 ,
V_393 -> V_217 , V_358 ) ;
memcpy ( V_394 -> V_401 ,
V_393 -> V_219 , V_358 ) ;
V_394 -> V_33 = false ;
V_394 -> V_32 = 0 ;
V_394 -> V_37 = V_38 ;
F_128 ( & V_394 -> V_108 ) ;
F_13 ( & V_394 -> V_107 ) ;
F_13 ( & V_394 -> V_23 ) ;
F_129 ( & V_394 -> V_48 , F_21 ) ;
memcpy ( & V_394 -> V_353 , & V_393 -> V_353 ,
sizeof( V_394 -> V_353 ) ) ;
memcpy ( & V_394 -> V_97 , & V_393 -> V_97 ,
sizeof( V_394 -> V_97 ) ) ;
#ifdef F_4
F_130 ( V_394 -> V_402 , V_403 ) ;
#endif
V_394 -> V_15 = V_404 ;
++ V_394 -> V_390 ;
V_3 = F_131 ( V_394 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_91 ) ;
goto V_396;
}
F_132 ( V_405 ) ;
V_394 -> V_134 = F_133 ( F_56 ,
V_394 , L_92 ) ;
if ( F_124 ( V_394 -> V_134 ) ) {
V_3 = F_125 ( V_394 -> V_134 ) ;
F_5 ( V_59 , L_93 , V_3 ) ;
F_134 ( V_405 ) ;
goto V_396;
}
V_394 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_135 ( & V_394 -> V_107 , & V_406 ) ;
F_3 ( & V_22 ) ;
F_136 ( V_394 ) ;
F_24 ( V_57 , & V_394 -> V_48 , V_52 ) ;
return V_394 ;
V_396:
F_118 ( V_394 ) ;
F_116 ( F_112 ( V_394 ) ) ;
V_395:
if ( V_394 ) {
if ( ! F_124 ( V_394 -> V_56 ) )
F_11 ( V_394 -> V_56 ) ;
if ( V_394 -> V_28 )
F_10 ( V_394 -> V_28 ) ;
F_11 ( V_394 ) ;
}
return F_71 ( V_3 ) ;
}
static int F_137 ( struct V_7 * V_8 , struct V_147 * V_148 )
{
if ( V_148 -> V_150 != V_151 &&
V_148 -> V_150 != V_8 -> V_150 )
return 0 ;
switch ( V_8 -> V_150 ) {
case V_157 :
if ( ! F_138 ( V_148 -> V_220 , V_8 -> V_220 ) )
return 0 ;
break;
default:
if ( V_8 -> V_407 == NULL ) {
if ( ! V_148 -> V_170 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_407 ,
V_148 -> V_339 ? V_148 -> V_339 : L_94 ,
V_342 ) )
return 0 ;
if ( ( V_148 -> V_339 && strlen ( V_148 -> V_339 ) != 0 ) &&
V_8 -> V_344 != NULL &&
strncmp ( V_8 -> V_344 ,
V_148 -> V_344 ? V_148 -> V_344 : L_94 ,
V_408 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_139 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
struct V_7 * V_8 ;
F_2 ( & V_22 ) ;
F_114 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_8 -> V_409 == V_16 )
continue;
if ( ! F_137 ( V_8 , V_148 ) )
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
unsigned int V_3 , V_411 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_20 , L_95 , V_21 , V_8 -> V_410 ) ;
F_2 ( & V_22 ) ;
if ( V_8 -> V_409 == V_16 ) {
F_3 ( & V_22 ) ;
return;
}
if ( -- V_8 -> V_410 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
if ( V_8 -> V_409 == V_62 )
V_8 -> V_409 = V_16 ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_409 == V_16 && V_2 -> V_49 -> V_412 ) {
V_411 = F_141 () ;
V_3 = V_2 -> V_49 -> V_412 ( V_411 , V_8 ) ;
if ( V_3 )
F_5 ( V_59 , L_96 ,
V_21 , V_3 ) ;
F_142 ( V_411 ) ;
}
F_2 ( & V_22 ) ;
F_16 ( & V_8 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_143 ( V_8 ) ;
F_115 ( V_2 ) ;
}
static int
F_144 ( struct V_147 * V_148 , struct V_7 * V_8 )
{
int V_3 = 0 ;
char * V_413 , * V_140 , * V_414 ;
T_6 V_36 ;
struct V_415 * V_415 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_368 * V_416 ;
struct V_374 * V_417 ;
struct V_418 * V_419 ;
V_413 = F_35 ( V_420 , V_117 ) ;
if ( ! V_413 )
return - V_83 ;
switch ( V_2 -> V_97 . V_421 ) {
case V_367 :
V_416 = (struct V_368 * ) & V_2 -> V_97 ;
sprintf ( V_413 , L_97 , & V_416 -> V_371 . V_372 ) ;
break;
case V_373 :
V_417 = (struct V_374 * ) & V_2 -> V_97 ;
sprintf ( V_413 , L_98 , & V_417 -> V_377 . V_422 ) ;
break;
default:
F_5 ( V_20 , L_99 ,
V_2 -> V_97 . V_421 ) ;
V_3 = - V_141 ;
goto V_395;
}
F_5 ( V_20 , L_100 , V_21 , V_413 ) ;
V_415 = F_145 ( & V_423 , V_413 , L_94 ) ;
if ( F_124 ( V_415 ) ) {
if ( ! V_8 -> V_424 ) {
F_5 ( V_20 , L_101 ) ;
V_3 = F_125 ( V_415 ) ;
goto V_395;
}
sprintf ( V_413 , L_102 , V_8 -> V_424 ) ;
F_5 ( V_20 , L_100 , V_21 , V_413 ) ;
V_415 = F_145 ( & V_423 , V_413 , L_94 ) ;
if ( F_124 ( V_415 ) ) {
V_3 = F_125 ( V_415 ) ;
goto V_395;
}
}
F_146 ( & V_415 -> V_425 ) ;
V_419 = V_415 -> V_414 . V_199 ;
if ( F_147 ( V_419 ) ) {
V_3 = V_419 ? F_125 ( V_419 ) : - V_141 ;
goto V_426;
}
V_414 = ( char * ) V_419 -> V_199 ;
V_140 = F_148 ( V_414 , V_419 -> V_427 , ':' ) ;
F_5 ( V_20 , L_103 , V_414 ) ;
if ( ! V_140 ) {
F_5 ( V_20 , L_104 ,
V_419 -> V_427 ) ;
V_3 = - V_141 ;
goto V_426;
}
V_36 = V_140 - V_414 ;
if ( V_36 > V_342 || V_36 <= 0 ) {
F_5 ( V_20 , L_105 ,
V_36 ) ;
V_3 = - V_141 ;
goto V_426;
}
V_148 -> V_339 = F_88 ( V_414 , V_36 , V_117 ) ;
if ( ! V_148 -> V_339 ) {
F_5 ( V_20 , L_106 ,
V_36 ) ;
V_3 = - V_83 ;
goto V_426;
}
F_5 ( V_20 , L_107 , V_21 , V_148 -> V_339 ) ;
V_36 = V_415 -> V_427 - ( V_36 + 1 ) ;
if ( V_36 > V_408 || V_36 <= 0 ) {
F_5 ( V_20 , L_108 , V_36 ) ;
V_3 = - V_141 ;
F_11 ( V_148 -> V_339 ) ;
V_148 -> V_339 = NULL ;
goto V_426;
}
++ V_140 ;
V_148 -> V_344 = F_88 ( V_140 , V_36 , V_117 ) ;
if ( ! V_148 -> V_344 ) {
F_5 ( V_20 , L_109 ,
V_36 ) ;
V_3 = - V_83 ;
F_11 ( V_148 -> V_339 ) ;
V_148 -> V_339 = NULL ;
goto V_426;
}
V_426:
F_149 ( & V_415 -> V_425 ) ;
F_150 ( V_415 ) ;
V_395:
F_11 ( V_413 ) ;
F_5 ( V_20 , L_110 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_151 ( struct V_1 * V_2 , struct V_147 * V_393 )
{
int V_3 = - V_83 ;
unsigned int V_411 ;
struct V_7 * V_8 ;
struct V_368 * V_378 = (struct V_368 * ) & V_2 -> V_97 ;
struct V_374 * V_385 = (struct V_374 * ) & V_2 -> V_97 ;
V_411 = F_141 () ;
V_8 = F_139 ( V_2 , V_393 ) ;
if ( V_8 ) {
F_5 ( V_20 , L_111 ,
V_8 -> V_409 ) ;
F_8 ( & V_8 -> V_428 ) ;
V_3 = F_152 ( V_411 , V_8 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_428 ) ;
F_140 ( V_8 ) ;
F_153 ( V_411 ) ;
return F_71 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_5 ( V_20 , L_112 ) ;
V_3 = F_154 ( V_411 , V_8 ,
V_393 -> V_429 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_428 ) ;
F_140 ( V_8 ) ;
F_153 ( V_411 ) ;
return F_71 ( V_3 ) ;
}
}
F_12 ( & V_8 -> V_428 ) ;
F_115 ( V_2 ) ;
F_153 ( V_411 ) ;
return V_8 ;
}
F_5 ( V_20 , L_113 ) ;
V_8 = F_155 () ;
if ( V_8 == NULL )
goto V_430;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_97 . V_421 == V_373 )
sprintf ( V_8 -> V_431 , L_114 , & V_385 -> V_377 ) ;
else
sprintf ( V_8 -> V_431 , L_115 , & V_378 -> V_371 ) ;
if ( V_393 -> V_339 ) {
V_8 -> V_407 = F_90 ( V_393 -> V_339 , V_117 ) ;
if ( ! V_8 -> V_407 )
goto V_430;
}
if ( V_393 -> V_344 ) {
V_8 -> V_344 = F_90 ( V_393 -> V_344 , V_117 ) ;
if ( ! V_8 -> V_344 )
goto V_430;
}
if ( V_393 -> V_351 ) {
V_8 -> V_424 = F_90 ( V_393 -> V_351 , V_117 ) ;
if ( ! V_8 -> V_424 )
goto V_430;
}
V_8 -> V_220 = V_393 -> V_220 ;
V_8 -> V_221 = V_393 -> V_221 ;
V_8 -> V_150 = V_393 -> V_150 ;
V_8 -> V_152 = V_393 -> V_152 ;
F_8 ( & V_8 -> V_428 ) ;
V_3 = F_152 ( V_411 , V_8 ) ;
if ( ! V_3 )
V_3 = F_154 ( V_411 , V_8 , V_393 -> V_429 ) ;
F_12 ( & V_8 -> V_428 ) ;
if ( V_3 )
goto V_430;
F_2 ( & V_22 ) ;
F_135 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_153 ( V_411 ) ;
return V_8 ;
V_430:
F_143 ( V_8 ) ;
F_153 ( V_411 ) ;
return F_71 ( V_3 ) ;
}
static int F_156 ( struct V_9 * V_10 , const char * V_137 )
{
if ( V_10 -> V_432 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_433 , V_137 , V_434 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_157 ( struct V_7 * V_8 , const char * V_137 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_22 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_26 ) ;
if ( ! F_156 ( V_10 , V_137 ) )
continue;
++ V_10 -> V_435 ;
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
F_5 ( V_20 , L_116 , V_21 , V_10 -> V_435 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_435 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_411 = F_141 () ;
if ( V_8 -> V_2 -> V_49 -> V_436 )
V_8 -> V_2 -> V_49 -> V_436 ( V_411 , V_10 ) ;
F_142 ( V_411 ) ;
F_159 ( V_10 ) ;
F_160 ( V_10 ) ;
F_140 ( V_8 ) ;
}
static struct V_9 *
F_161 ( struct V_7 * V_8 , struct V_147 * V_393 )
{
int V_3 , V_411 ;
struct V_9 * V_10 ;
V_10 = F_157 ( V_8 , V_393 -> V_196 ) ;
if ( V_10 ) {
F_5 ( V_20 , L_117 ) ;
F_140 ( V_8 ) ;
if ( V_10 -> V_309 != V_393 -> V_309 )
F_5 ( V_59 , L_118 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_49 -> V_437 ) {
V_3 = - V_55 ;
goto V_438;
}
V_10 = F_162 () ;
if ( V_10 == NULL ) {
V_3 = - V_83 ;
goto V_438;
}
V_10 -> V_8 = V_8 ;
if ( V_393 -> V_344 ) {
V_10 -> V_344 = F_90 ( V_393 -> V_344 , V_117 ) ;
if ( ! V_10 -> V_344 ) {
V_3 = - V_83 ;
goto V_438;
}
}
V_411 = F_141 () ;
V_3 = V_8 -> V_2 -> V_49 -> V_437 ( V_411 , V_8 , V_393 -> V_196 , V_10 ,
V_393 -> V_429 ) ;
F_153 ( V_411 ) ;
F_5 ( V_20 , L_119 , V_3 ) ;
if ( V_3 )
goto V_438;
if ( V_393 -> V_266 ) {
V_10 -> V_439 &= ~ V_440 ;
F_5 ( V_20 , L_120 , V_10 -> V_439 ) ;
}
V_10 -> V_309 = V_393 -> V_309 ;
V_10 -> V_252 = V_393 -> V_252 ;
V_10 -> V_272 = V_393 -> V_272 ;
V_10 -> V_306 = V_393 -> V_306 ;
F_13 ( & V_10 -> V_441 ) ;
F_2 ( & V_22 ) ;
F_135 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_163 ( V_10 ) ;
return V_10 ;
V_438:
F_160 ( V_10 ) ;
return F_71 ( V_3 ) ;
}
void
F_164 ( struct V_442 * V_443 )
{
if ( ! V_443 || F_124 ( V_443 ) )
return;
if ( ! F_165 ( & V_443 -> V_444 ) ||
F_166 ( V_445 , & V_443 -> V_446 ) ) {
V_443 -> V_447 = V_38 ;
return;
}
if ( ! F_124 ( F_167 ( V_443 ) ) )
F_158 ( F_167 ( V_443 ) ) ;
F_11 ( V_443 ) ;
return;
}
static inline struct V_442 *
F_168 ( struct V_448 * V_449 )
{
return V_449 -> V_450 ;
}
static int
F_169 ( struct V_451 * V_452 , struct V_453 * V_454 )
{
struct V_448 * V_455 = F_170 ( V_452 ) ;
struct V_448 * V_65 = V_454 -> V_449 ;
if ( ( V_452 -> V_456 & V_457 ) != ( V_454 -> V_30 & V_457 ) )
return 0 ;
if ( ( V_455 -> V_458 & V_459 ) !=
( V_65 -> V_458 & V_459 ) )
return 0 ;
if ( V_65 -> V_335 && V_65 -> V_335 < V_455 -> V_335 )
return 0 ;
if ( V_65 -> V_333 && V_65 -> V_333 < V_455 -> V_333 )
return 0 ;
if ( ! F_138 ( V_455 -> V_460 , V_65 -> V_460 ) || ! F_171 ( V_455 -> V_461 , V_65 -> V_461 ) )
return 0 ;
if ( V_455 -> V_462 != V_65 -> V_462 ||
V_455 -> V_463 != V_65 -> V_463 )
return 0 ;
if ( strcmp ( V_455 -> V_429 -> V_464 , V_65 -> V_429 -> V_464 ) )
return 0 ;
if ( V_455 -> V_231 != V_65 -> V_231 )
return 0 ;
return 1 ;
}
int
F_172 ( struct V_451 * V_452 , void * V_199 )
{
struct V_453 * V_454 = (struct V_453 * ) V_199 ;
struct V_147 * V_393 ;
struct V_448 * V_449 ;
struct V_1 * V_465 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_442 * V_443 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_449 = F_170 ( V_452 ) ;
V_443 = F_173 ( F_168 ( V_449 ) ) ;
if ( F_124 ( V_443 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_167 ( V_443 ) ;
V_8 = V_10 -> V_8 ;
V_465 = V_8 -> V_2 ;
V_393 = V_454 -> V_148 ;
if ( ! F_110 ( V_465 , V_393 ) ||
! F_137 ( V_8 , V_393 ) ||
! F_156 ( V_10 , V_393 -> V_196 ) ) {
V_3 = 0 ;
goto V_466;
}
V_3 = F_169 ( V_452 , V_454 ) ;
V_466:
F_3 ( & V_22 ) ;
F_164 ( V_443 ) ;
return V_3 ;
}
int
F_174 ( const unsigned int V_411 , struct V_7 * V_8 , const char * V_467 ,
const struct V_468 * V_469 , unsigned int * V_470 ,
struct V_471 * * V_472 , int V_223 )
{
char * V_473 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_49 -> V_437 || ! V_8 -> V_2 -> V_49 -> V_474 )
return - V_55 ;
* V_470 = 0 ;
* V_472 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_473 = F_35 ( 2 +
F_93 ( V_8 -> V_431 , V_475 * 2 )
+ 1 + 4 + 2 , V_117 ) ;
if ( V_473 == NULL )
return - V_83 ;
V_473 [ 0 ] = '\\' ;
V_473 [ 1 ] = '\\' ;
strcpy ( V_473 + 2 , V_8 -> V_431 ) ;
strcpy ( V_473 + 2 + strlen ( V_8 -> V_431 ) , L_121 ) ;
V_3 = V_8 -> V_2 -> V_49 -> V_437 ( V_411 , V_8 , V_473 , NULL ,
V_469 ) ;
F_5 ( V_20 , L_122 , V_3 , V_8 -> V_25 ) ;
F_11 ( V_473 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_49 -> V_474 ( V_411 , V_8 , V_467 ,
V_472 , V_470 ,
V_469 , V_223 ) ;
return V_3 ;
}
static inline void
F_175 ( struct V_476 * V_477 )
{
struct V_477 * V_478 = V_477 -> V_478 ;
F_176 ( F_177 ( V_478 ) ) ;
F_178 ( V_478 , L_123 ,
& V_479 [ 0 ] , L_124 , & V_480 [ 0 ] ) ;
}
static inline void
F_179 ( struct V_476 * V_477 )
{
struct V_477 * V_478 = V_477 -> V_478 ;
F_176 ( F_177 ( V_478 ) ) ;
F_178 ( V_478 , L_125 ,
& V_479 [ 1 ] , L_126 , & V_480 [ 1 ] ) ;
}
static inline void
F_175 ( struct V_476 * V_477 )
{
}
static inline void
F_179 ( struct V_476 * V_477 )
{
}
static void F_180 ( char * V_481 , char * V_482 , unsigned int V_78 )
{
unsigned int V_204 , V_205 ;
for ( V_204 = 0 , V_205 = 0 ; V_204 < ( V_78 ) ; V_204 ++ ) {
V_481 [ V_205 ] = 'A' + ( 0x0F & ( V_482 [ V_204 ] >> 4 ) ) ;
V_481 [ V_205 + 1 ] = 'A' + ( 0x0F & V_482 [ V_204 ] ) ;
V_205 += 2 ;
}
}
static int
F_181 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_353 . V_421 != V_366 ) {
struct V_476 * V_476 = V_2 -> V_28 ;
V_3 = V_476 -> V_49 -> V_483 ( V_476 ,
(struct V_96 * ) & V_2 -> V_353 ,
sizeof( V_2 -> V_353 ) ) ;
if ( V_3 < 0 ) {
struct V_368 * V_369 ;
struct V_374 * V_375 ;
V_369 = (struct V_368 * ) & V_2 -> V_353 ;
V_375 = (struct V_374 * ) & V_2 -> V_353 ;
if ( V_375 -> V_484 == V_373 )
F_5 ( V_59 , L_127 ,
& V_375 -> V_377 , V_3 ) ;
else
F_5 ( V_59 , L_128 ,
& V_369 -> V_371 . V_372 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_182 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_485 * V_486 ;
struct V_487 * V_488 ;
V_486 = F_99 ( sizeof( struct V_485 ) ,
V_117 ) ;
if ( V_486 ) {
V_486 -> V_489 . V_490 . V_491 = 32 ;
if ( V_2 -> V_401 &&
V_2 -> V_401 [ 0 ] != 0 )
F_180 ( V_486 -> V_489 .
V_490 . V_492 ,
V_2 -> V_401 ,
V_358 ) ;
else
F_180 ( V_486 -> V_489 .
V_490 . V_492 ,
V_493 ,
V_358 ) ;
V_486 -> V_489 . V_490 . V_494 = 32 ;
if ( V_2 -> V_400 &&
V_2 -> V_400 [ 0 ] != 0 )
F_180 ( V_486 -> V_489 .
V_490 . V_495 ,
V_2 -> V_400 ,
V_358 ) ;
else
F_180 ( V_486 -> V_489 .
V_490 . V_495 ,
L_129 ,
V_358 ) ;
V_486 -> V_489 . V_490 . V_496 = 0 ;
V_486 -> V_489 . V_490 . V_497 = 0 ;
V_488 = (struct V_487 * ) V_486 ;
V_488 -> V_498 = F_183 ( 0x81000044 ) ;
V_3 = F_184 ( V_2 , V_488 , 0x44 ) ;
F_11 ( V_486 ) ;
F_38 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_379 ;
int V_499 , V_500 ;
struct V_476 * V_476 = V_2 -> V_28 ;
struct V_96 * V_501 ;
V_501 = (struct V_96 * ) & V_2 -> V_97 ;
if ( V_2 -> V_97 . V_421 == V_373 ) {
V_379 = ( (struct V_374 * ) V_501 ) -> V_381 ;
V_499 = sizeof( struct V_374 ) ;
V_500 = V_373 ;
} else {
V_379 = ( (struct V_368 * ) V_501 ) -> V_380 ;
V_499 = sizeof( struct V_368 ) ;
V_500 = V_367 ;
}
if ( V_476 == NULL ) {
V_3 = F_185 ( F_112 ( V_2 ) , V_500 , V_502 ,
V_503 , & V_476 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_130 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_5 ( V_20 , L_131 ) ;
V_2 -> V_28 = V_476 ;
V_476 -> V_478 -> V_504 = V_75 ;
if ( V_500 == V_373 )
F_179 ( V_476 ) ;
else
F_175 ( V_476 ) ;
}
V_3 = F_181 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_476 -> V_478 -> V_505 = 7 * V_53 ;
V_476 -> V_478 -> V_506 = 5 * V_53 ;
if ( V_2 -> V_250 ) {
if ( V_476 -> V_478 -> V_507 < ( 200 * 1024 ) )
V_476 -> V_478 -> V_507 = 200 * 1024 ;
if ( V_476 -> V_478 -> V_508 < ( 140 * 1024 ) )
V_476 -> V_478 -> V_508 = 140 * 1024 ;
}
if ( V_2 -> V_397 ) {
int V_509 = 1 ;
V_3 = F_186 ( V_476 , V_510 , V_511 ,
( char * ) & V_509 , sizeof( V_509 ) ) ;
if ( V_3 )
F_5 ( V_20 , L_132 ,
V_3 ) ;
}
F_5 ( V_20 , L_133 ,
V_476 -> V_478 -> V_507 ,
V_476 -> V_478 -> V_508 , V_476 -> V_478 -> V_505 ) ;
V_3 = V_476 -> V_49 -> V_512 ( V_476 , V_501 , V_499 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_20 , L_134 , V_3 ) ;
F_10 ( V_476 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_379 == F_106 ( V_382 ) )
V_3 = F_182 ( V_2 ) ;
return V_3 ;
}
static int
F_131 ( struct V_1 * V_2 )
{
T_5 * V_379 ;
struct V_374 * V_385 = (struct V_374 * ) & V_2 -> V_97 ;
struct V_368 * V_378 = (struct V_368 * ) & V_2 -> V_97 ;
if ( V_2 -> V_97 . V_421 == V_373 )
V_379 = & V_385 -> V_381 ;
else
V_379 = & V_378 -> V_380 ;
if ( * V_379 == 0 ) {
int V_3 ;
* V_379 = F_106 ( V_98 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_379 = F_106 ( V_382 ) ;
}
return F_18 ( V_2 ) ;
}
void F_187 ( unsigned int V_411 , struct V_9 * V_10 ,
struct V_448 * V_449 , struct V_147 * V_513 )
{
T_7 V_514 = F_188 ( V_10 -> V_515 . V_516 ) ;
if ( V_513 && V_513 -> V_270 ) {
V_10 -> V_515 . V_516 = 0 ;
V_10 -> V_517 = 0 ;
F_5 ( V_20 , L_135 ) ;
return;
} else if ( V_513 )
V_10 -> V_517 = 1 ;
if ( V_10 -> V_517 == 0 ) {
F_5 ( V_20 , L_136 ) ;
return;
}
if ( ! F_189 ( V_411 , V_10 ) ) {
T_7 V_518 = F_188 ( V_10 -> V_515 . V_516 ) ;
F_5 ( V_20 , L_137 , V_518 ) ;
if ( V_513 == NULL ) {
if ( ( V_514 & V_519 ) == 0 )
V_518 &= ~ V_519 ;
if ( ( V_514 & V_520 ) == 0 ) {
if ( V_518 & V_520 )
F_5 ( V_59 , L_138 ) ;
V_518 &= ~ V_520 ;
} else if ( ( V_518 & V_520 ) == 0 ) {
F_5 ( V_59 , L_139 ) ;
F_5 ( V_59 , L_140 ) ;
}
}
if ( V_518 & V_521 )
F_5 ( V_59 , L_141 ) ;
V_518 &= V_522 ;
if ( V_513 && V_513 -> V_303 )
V_518 &= ~ V_519 ;
else if ( V_519 & V_518 ) {
F_5 ( V_20 , L_142 ) ;
if ( V_449 )
V_449 -> V_458 |=
V_523 ;
}
if ( V_513 && V_513 -> V_229 == 0 )
V_518 &= ~ V_520 ;
else if ( V_518 & V_520 ) {
F_5 ( V_20 , L_143 ) ;
if ( V_449 )
V_449 -> V_458 |=
V_524 ;
}
F_5 ( V_20 , L_144 , ( int ) V_518 ) ;
#ifdef F_61
if ( V_518 & V_525 )
F_5 ( V_20 , L_145 ) ;
if ( V_518 & V_526 )
F_5 ( V_20 , L_146 ) ;
if ( V_518 & V_520 )
F_5 ( V_20 , L_147 ) ;
if ( V_518 & V_527 )
F_5 ( V_20 , L_148 ) ;
if ( V_518 & V_519 )
F_5 ( V_20 , L_149 ) ;
if ( V_518 & V_528 )
F_5 ( V_20 , L_150 ) ;
if ( V_518 & V_529 )
F_5 ( V_20 , L_151 ) ;
if ( V_518 & V_530 )
F_5 ( V_20 , L_152 ) ;
if ( V_518 & V_521 )
F_5 ( V_20 , L_153 ) ;
#endif
if ( F_190 ( V_411 , V_10 , V_518 ) ) {
if ( V_513 == NULL ) {
F_5 ( V_20 , L_154 ) ;
} else
F_5 ( V_59 , L_155 ) ;
}
}
}
void F_191 ( struct V_147 * V_531 ,
struct V_448 * V_449 )
{
F_129 ( & V_449 -> V_532 , V_533 ) ;
F_128 ( & V_449 -> V_534 ) ;
V_449 -> V_535 = V_536 ;
V_449 -> V_333 = V_531 -> V_333 ;
V_449 -> V_335 = V_531 -> V_335 ;
V_449 -> V_460 = V_531 -> V_221 ;
V_449 -> V_461 = V_531 -> V_222 ;
V_449 -> V_462 = V_531 -> V_225 ;
V_449 -> V_463 = V_531 -> V_224 ;
F_5 ( V_20 , L_156 ,
V_449 -> V_462 , V_449 -> V_463 ) ;
V_449 -> V_231 = V_531 -> V_231 ;
V_449 -> V_429 = V_531 -> V_429 ;
if ( V_531 -> V_255 )
V_449 -> V_458 |= V_537 ;
if ( V_531 -> V_282 )
V_449 -> V_458 |= V_538 ;
if ( V_531 -> V_230 )
V_449 -> V_458 |= V_539 ;
if ( V_531 -> V_223 )
V_449 -> V_458 |= V_540 ;
if ( V_531 -> V_258 )
V_449 -> V_458 |= V_541 ;
if ( V_531 -> V_241 )
V_449 -> V_458 |= V_542 ;
if ( V_531 -> V_263 )
V_449 -> V_458 |= V_543 ;
if ( V_531 -> V_274 )
V_449 -> V_458 |= V_544 ;
if ( V_531 -> V_293 )
V_449 -> V_458 |= V_545 ;
if ( V_531 -> V_280 )
V_449 -> V_458 |= V_546 ;
if ( V_531 -> V_298 )
V_449 -> V_458 |= V_547 ;
if ( V_531 -> V_300 )
V_449 -> V_458 |= V_548 ;
if ( V_531 -> V_235 ) {
V_449 -> V_458 |= V_549 ;
V_449 -> V_550 = V_531 -> V_322 ;
}
if ( V_531 -> V_236 ) {
V_449 -> V_458 |= V_551 ;
V_449 -> V_552 = V_531 -> V_324 ;
}
if ( V_531 -> V_207 )
V_449 -> V_458 |= V_553 ;
if ( V_531 -> V_208 )
V_449 -> V_458 |= V_554 ;
if ( V_531 -> V_285 )
V_449 -> V_458 |= V_555 ;
if ( V_531 -> V_313 )
V_449 -> V_458 |= V_556 ;
if ( V_531 -> V_317 )
V_449 -> V_458 |= ( V_557 |
V_537 ) ;
if ( V_531 -> V_174 )
V_449 -> V_458 |= V_558 ;
if ( V_531 -> V_173 ) {
F_5 ( V_20 , L_157 ) ;
V_449 -> V_458 |= V_559 ;
}
if ( V_531 -> V_315 ) {
if ( V_531 -> V_263 ) {
F_5 ( V_59 , L_158 ) ;
}
V_449 -> V_458 |= V_560 ;
}
if ( ( V_531 -> V_300 ) && ( V_531 -> V_285 ) )
F_5 ( V_59 , L_159 ) ;
}
static void
F_192 ( struct V_147 * V_393 )
{
F_11 ( V_393 -> V_339 ) ;
F_193 ( V_393 -> V_344 ) ;
F_11 ( V_393 -> V_196 ) ;
F_11 ( V_393 -> V_351 ) ;
F_11 ( V_393 -> V_355 ) ;
F_11 ( V_393 -> V_197 ) ;
}
void
F_194 ( struct V_147 * V_393 )
{
if ( ! V_393 )
return;
F_192 ( V_393 ) ;
F_11 ( V_393 ) ;
}
static char *
F_195 ( const struct V_147 * V_148 ,
const struct V_448 * V_449 )
{
char * V_561 , * V_194 ;
unsigned int V_562 = V_148 -> V_197 ? strlen ( V_148 -> V_197 ) + 1 : 0 ;
unsigned int V_563 = F_93 ( V_148 -> V_196 , V_434 + 1 ) ;
V_561 = F_35 ( V_563 + V_562 + 1 , V_117 ) ;
if ( V_561 == NULL )
return F_71 ( - V_83 ) ;
strncpy ( V_561 , V_148 -> V_196 , V_563 ) ;
V_194 = V_561 + V_563 ;
if ( V_562 ) {
* V_194 = F_196 ( V_449 ) ;
strncpy ( V_194 + 1 , V_148 -> V_197 , V_562 ) ;
V_194 += V_562 ;
}
* V_194 = '\0' ;
F_89 ( V_561 , F_196 ( V_449 ) ) ;
F_5 ( V_20 , L_160 , V_21 , V_561 ) ;
return V_561 ;
}
static int
F_197 ( const unsigned int V_411 , struct V_7 * V_8 ,
struct V_147 * V_393 , struct V_448 * V_449 ,
int V_564 )
{
int V_3 ;
unsigned int V_470 = 0 ;
struct V_471 * V_472 = NULL ;
char * V_561 = NULL , * V_565 = NULL , * V_566 = NULL ;
V_561 = F_195 ( V_393 , V_449 ) ;
if ( F_124 ( V_561 ) )
return F_125 ( V_561 ) ;
V_565 = V_564 ? V_561 + 1 : V_393 -> V_196 + 1 ;
V_3 = F_174 ( V_411 , V_8 , V_565 , V_449 -> V_429 ,
& V_470 , & V_472 , F_198 ( V_449 ) ) ;
if ( ! V_3 && V_470 > 0 ) {
char * V_567 = NULL ;
V_566 = F_199 ( V_449 -> V_198 ,
V_561 + 1 , V_472 ,
& V_567 ) ;
F_200 ( V_472 , V_470 ) ;
if ( F_124 ( V_566 ) ) {
V_3 = F_125 ( V_566 ) ;
V_566 = NULL ;
} else {
F_192 ( V_393 ) ;
V_3 = F_201 ( V_393 , V_566 ,
V_567 ) ;
}
F_11 ( V_567 ) ;
F_11 ( V_449 -> V_198 ) ;
V_449 -> V_198 = V_566 ;
}
F_11 ( V_561 ) ;
return V_3 ;
}
static int
F_201 ( struct V_147 * V_393 , char * V_568 ,
const char * V_193 )
{
int V_3 = 0 ;
if ( F_91 ( V_568 , V_193 , V_393 ) )
return - V_141 ;
if ( V_393 -> V_170 ) {
F_5 ( V_20 , L_161 ) ;
F_11 ( V_393 -> V_339 ) ;
V_393 -> V_339 = NULL ;
} else if ( V_393 -> V_339 ) {
F_5 ( V_20 , L_162 , V_393 -> V_339 ) ;
} else {
F_5 ( V_59 , L_163 ) ;
return - V_141 ;
}
if ( V_393 -> V_355 == NULL ) {
V_393 -> V_429 = F_202 () ;
} else {
V_393 -> V_429 = F_203 ( V_393 -> V_355 ) ;
if ( V_393 -> V_429 == NULL ) {
F_5 ( V_59 , L_164 ,
V_393 -> V_355 ) ;
return - V_569 ;
}
}
return V_3 ;
}
struct V_147 *
F_204 ( char * V_568 , const char * V_193 )
{
int V_3 ;
struct V_147 * V_393 ;
V_393 = F_35 ( sizeof( struct V_147 ) , V_117 ) ;
if ( ! V_393 )
return F_71 ( - V_83 ) ;
V_3 = F_201 ( V_393 , V_568 , V_193 ) ;
if ( V_3 ) {
F_194 ( V_393 ) ;
V_393 = F_71 ( V_3 ) ;
}
return V_393 ;
}
int
F_205 ( struct V_448 * V_449 , struct V_147 * V_393 )
{
int V_3 ;
unsigned int V_411 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_561 ;
struct V_442 * V_443 ;
#ifdef F_206
int V_570 = 0 ;
#endif
V_3 = F_207 ( & V_449 -> V_571 , L_165 , V_572 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_206
V_573:
if ( V_570 ) {
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
V_561 = NULL ;
V_443 = NULL ;
V_411 = F_141 () ;
V_2 = F_121 ( V_393 ) ;
if ( F_124 ( V_2 ) ) {
V_3 = F_125 ( V_2 ) ;
F_208 ( & V_449 -> V_571 ) ;
goto V_466;
}
V_8 = F_151 ( V_2 , V_393 ) ;
if ( F_124 ( V_8 ) ) {
V_3 = F_125 ( V_8 ) ;
V_8 = NULL ;
goto V_574;
}
V_10 = F_161 ( V_8 , V_393 ) ;
if ( F_124 ( V_10 ) ) {
V_3 = F_125 ( V_10 ) ;
V_10 = NULL ;
goto V_575;
}
if ( F_209 ( V_10 -> V_8 ) ) {
F_187 ( V_411 , V_10 , V_449 , V_393 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_188 ( V_10 -> V_515 . V_516 ) &
V_521 ) ) {
V_3 = - V_576 ;
goto V_574;
}
} else
V_10 -> V_517 = 0 ;
if ( ! V_10 -> V_577 && V_2 -> V_49 -> V_578 )
V_2 -> V_49 -> V_578 ( V_411 , V_10 ) ;
V_449 -> V_335 = V_2 -> V_49 -> V_579 ( V_10 , V_393 ) ;
V_449 -> V_333 = V_2 -> V_49 -> V_580 ( V_10 , V_393 ) ;
V_449 -> V_571 . V_581 = V_449 -> V_333 / V_582 ;
V_575:
#ifdef F_206
if ( V_570 == 0 ) {
int V_583 = F_197 ( V_411 , V_8 , V_393 , V_449 ,
false ) ;
if ( ! V_583 ) {
V_570 ++ ;
goto V_573;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_49 -> V_584 ) {
V_3 = - V_55 ;
goto V_574;
}
V_561 = F_210 ( V_393 , V_449 , V_10 ) ;
if ( V_561 == NULL ) {
V_3 = - V_83 ;
goto V_574;
}
V_3 = V_2 -> V_49 -> V_584 ( V_411 , V_10 , V_449 ,
V_561 ) ;
if ( V_3 != 0 && V_3 != - V_585 ) {
F_11 ( V_561 ) ;
goto V_574;
}
F_11 ( V_561 ) ;
}
if ( V_3 == - V_585 ) {
#ifdef F_206
if ( V_570 > V_586 ) {
V_3 = - V_587 ;
goto V_574;
}
V_3 = F_197 ( V_411 , V_8 , V_393 , V_449 , true ) ;
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
V_443 = F_99 ( sizeof *V_443 , V_117 ) ;
if ( V_443 == NULL ) {
V_3 = - V_83 ;
goto V_574;
}
V_443 -> V_589 = V_8 -> V_221 ;
V_443 -> V_590 = V_10 ;
V_443 -> V_447 = V_38 ;
F_211 ( V_591 , & V_443 -> V_446 ) ;
F_211 ( V_445 , & V_443 -> V_446 ) ;
V_449 -> V_450 = V_443 ;
F_2 ( & V_449 -> V_534 ) ;
F_212 ( & V_449 -> V_535 , V_443 ) ;
F_3 ( & V_449 -> V_534 ) ;
F_24 ( V_57 , & V_449 -> V_532 ,
V_592 ) ;
V_574:
if ( V_3 ) {
if ( V_10 )
F_158 ( V_10 ) ;
else if ( V_8 )
F_140 ( V_8 ) ;
else
F_115 ( V_2 ) ;
F_208 ( & V_449 -> V_571 ) ;
}
V_466:
F_153 ( V_411 ) ;
return V_3 ;
}
int
F_213 ( const unsigned int V_411 , struct V_7 * V_8 ,
const char * V_593 , struct V_9 * V_10 ,
const struct V_468 * V_469 )
{
struct V_487 * V_594 ;
struct V_487 * V_595 ;
T_8 * V_596 ;
T_9 * V_597 ;
unsigned char * V_598 ;
int V_3 = 0 ;
int V_78 ;
T_10 V_599 , V_600 ;
if ( V_8 == NULL )
return - V_601 ;
V_594 = F_26 () ;
if ( V_594 == NULL )
return - V_83 ;
V_595 = V_594 ;
F_214 ( V_594 , V_602 ,
NULL , 4 ) ;
V_594 -> V_603 = F_215 ( V_8 -> V_2 ) ;
V_594 -> V_604 = V_8 -> V_605 ;
V_596 = ( T_8 * ) V_594 ;
V_597 = ( T_9 * ) V_595 ;
V_596 -> V_606 = 0xFF ;
V_596 -> V_439 = F_216 ( V_607 ) ;
V_598 = & V_596 -> V_608 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_609 & V_610 ) ) {
V_596 -> V_611 = F_216 ( 1 ) ;
* V_598 = 0 ;
V_598 ++ ;
} else {
V_596 -> V_611 = F_216 ( V_612 ) ;
#ifdef F_84
if ( ( V_613 & V_614 ) &&
( V_8 -> V_150 == V_168 ) )
F_217 ( V_10 -> V_344 , V_8 -> V_2 -> V_615 ,
V_8 -> V_2 -> V_609 &
V_616 ? true : false ,
V_598 ) ;
else
#endif
V_3 = F_218 ( V_10 -> V_344 , V_8 -> V_2 -> V_615 ,
V_598 , V_469 ) ;
V_598 += V_612 ;
if ( V_8 -> V_617 & V_618 ) {
* V_598 = 0 ;
V_598 ++ ;
}
}
if ( V_8 -> V_2 -> V_152 )
V_594 -> V_619 |= V_620 ;
if ( V_8 -> V_617 & V_621 ) {
V_594 -> V_619 |= V_622 ;
}
if ( V_8 -> V_617 & V_623 ) {
V_594 -> V_619 |= V_624 ;
}
if ( V_8 -> V_617 & V_618 ) {
V_594 -> V_619 |= V_625 ;
V_78 =
F_219 ( ( V_626 * ) V_598 , V_593 ,
6 *
( + 256 ) , V_469 ) ;
V_598 += 2 * V_78 ;
V_598 += 2 ;
} else {
strcpy ( V_598 , V_593 ) ;
V_598 += strlen ( V_593 ) + 1 ;
}
strcpy ( V_598 , L_166 ) ;
V_598 += strlen ( L_166 ) ;
V_598 += 1 ;
V_600 = V_598 - & V_596 -> V_608 [ 0 ] ;
V_596 -> V_627 . V_498 = F_183 ( F_220 (
V_596 -> V_627 . V_498 ) + V_600 ) ;
V_596 -> V_628 = F_216 ( V_600 ) ;
V_3 = F_221 ( V_411 , V_8 , V_594 , V_595 , & V_78 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_629 ;
V_10 -> V_432 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_630 = V_595 -> V_631 ;
V_598 = F_222 ( V_595 ) ;
V_599 = F_223 ( V_595 ) ;
V_78 = F_93 ( V_598 , V_599 - 2 ) ;
if ( V_594 -> V_619 & V_625 )
V_629 = true ;
else
V_629 = false ;
if ( V_78 == 3 ) {
if ( ( V_598 [ 0 ] == 'I' ) && ( V_598 [ 1 ] == 'P' ) &&
( V_598 [ 2 ] == 'C' ) ) {
F_5 ( V_20 , L_167 ) ;
V_10 -> V_577 = 1 ;
}
} else if ( V_78 == 2 ) {
if ( ( V_598 [ 0 ] == 'A' ) && ( V_598 [ 1 ] == ':' ) ) {
F_5 ( V_20 , L_168 ) ;
}
}
V_598 += V_78 + 1 ;
V_599 -= ( V_78 + 1 ) ;
F_224 ( V_10 -> V_433 , V_593 , sizeof( V_10 -> V_433 ) ) ;
F_11 ( V_10 -> V_632 ) ;
V_10 -> V_632 = F_225 ( V_598 ,
V_599 , V_629 ,
V_469 ) ;
F_5 ( V_20 , L_169 , V_10 -> V_632 ) ;
if ( ( V_595 -> V_633 == 3 ) ||
( V_595 -> V_633 == 7 ) )
V_10 -> V_439 = F_226 ( V_597 -> V_634 ) ;
else
V_10 -> V_439 = 0 ;
F_5 ( V_20 , L_170 , V_10 -> V_439 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_595 -> V_631 ;
}
F_63 ( V_594 ) ;
return V_3 ;
}
static void F_227 ( struct V_635 * V_123 )
{
struct V_448 * V_636 = F_22 ( V_123 , struct V_448 , V_637 ) ;
F_228 ( V_636 -> V_429 ) ;
F_11 ( V_636 ) ;
}
void
F_229 ( struct V_448 * V_449 )
{
struct V_638 * V_639 = & V_449 -> V_535 ;
struct V_640 * V_641 ;
struct V_442 * V_443 ;
F_117 ( & V_449 -> V_532 ) ;
F_2 ( & V_449 -> V_534 ) ;
while ( ( V_641 = F_230 ( V_639 ) ) ) {
V_443 = F_231 ( V_641 , struct V_442 , V_642 ) ;
F_173 ( V_443 ) ;
F_232 ( V_445 , & V_443 -> V_446 ) ;
F_233 ( V_641 , V_639 ) ;
F_3 ( & V_449 -> V_534 ) ;
F_164 ( V_443 ) ;
F_2 ( & V_449 -> V_534 ) ;
}
F_3 ( & V_449 -> V_534 ) ;
F_208 ( & V_449 -> V_571 ) ;
F_11 ( V_449 -> V_198 ) ;
F_234 ( & V_449 -> V_637 , F_227 ) ;
}
int
F_152 ( const unsigned int V_411 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_49 -> V_50 || ! V_2 -> V_49 -> V_643 )
return - V_55 ;
if ( ! V_2 -> V_49 -> V_50 ( V_2 ) )
return 0 ;
F_235 ( V_2 , 1 ) ;
V_3 = V_2 -> V_49 -> V_643 ( V_411 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_644 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_154 ( const unsigned int V_411 , struct V_7 * V_8 ,
struct V_468 * V_645 )
{
int V_3 = - V_55 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_617 = V_2 -> V_617 ;
if ( V_646 == 0 )
V_8 -> V_617 &= ( ~ V_2 -> V_180 -> F_209 ) ;
F_5 ( V_20 , L_171 ,
V_2 -> V_609 , V_2 -> V_617 , V_2 -> V_647 ) ;
if ( V_2 -> V_49 -> V_648 )
V_3 = V_2 -> V_49 -> V_648 ( V_411 , V_8 , V_645 ) ;
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
return F_144 ( V_148 , V_8 ) ;
}
static struct V_9 *
F_237 ( struct V_448 * V_449 , T_3 V_649 )
{
int V_3 ;
struct V_9 * V_650 = F_238 ( V_449 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_147 * V_513 ;
V_513 = F_99 ( sizeof( * V_513 ) , V_117 ) ;
if ( V_513 == NULL )
return F_71 ( - V_83 ) ;
V_513 -> V_429 = V_449 -> V_429 ;
V_513 -> V_221 = V_649 ;
V_513 -> V_220 = V_649 ;
V_513 -> V_196 = V_650 -> V_433 ;
V_513 -> V_252 = V_650 -> V_252 ;
V_513 -> V_272 = V_650 -> V_272 ;
V_513 -> V_306 = V_650 -> V_306 ;
V_513 -> V_270 = ! V_650 -> V_517 ;
V_513 -> V_150 = V_650 -> V_8 -> V_150 ;
V_513 -> V_152 = V_650 -> V_8 -> V_152 ;
V_3 = F_236 ( V_513 , V_650 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_71 ( V_3 ) ;
goto V_466;
}
F_2 ( & V_22 ) ;
++ V_650 -> V_8 -> V_2 -> V_390 ;
F_3 ( & V_22 ) ;
V_8 = F_151 ( V_650 -> V_8 -> V_2 , V_513 ) ;
if ( F_124 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_115 ( V_650 -> V_8 -> V_2 ) ;
goto V_466;
}
V_10 = F_161 ( V_8 , V_513 ) ;
if ( F_124 ( V_10 ) ) {
F_140 ( V_8 ) ;
goto V_466;
}
if ( F_209 ( V_8 ) )
F_187 ( 0 , V_10 , NULL , V_513 ) ;
V_466:
F_11 ( V_513 -> V_339 ) ;
F_11 ( V_513 -> V_344 ) ;
F_11 ( V_513 ) ;
return V_10 ;
}
struct V_9 *
F_238 ( struct V_448 * V_449 )
{
return F_167 ( F_168 ( V_449 ) ) ;
}
static struct V_442 *
F_239 ( struct V_638 * V_639 , T_3 V_145 )
{
struct V_640 * V_641 = V_639 -> V_640 ;
struct V_442 * V_443 ;
while ( V_641 ) {
V_443 = F_231 ( V_641 , struct V_442 , V_642 ) ;
if ( F_240 ( V_443 -> V_589 , V_145 ) )
V_641 = V_641 -> V_651 ;
else if ( F_241 ( V_443 -> V_589 , V_145 ) )
V_641 = V_641 -> V_652 ;
else
return V_443 ;
}
return NULL ;
}
static void
F_212 ( struct V_638 * V_639 , struct V_442 * V_653 )
{
struct V_640 * * V_65 = & ( V_639 -> V_640 ) , * V_654 = NULL ;
struct V_442 * V_443 ;
while ( * V_65 ) {
V_443 = F_231 ( * V_65 , struct V_442 , V_642 ) ;
V_654 = * V_65 ;
if ( F_240 ( V_443 -> V_589 , V_653 -> V_589 ) )
V_65 = & ( ( * V_65 ) -> V_651 ) ;
else
V_65 = & ( ( * V_65 ) -> V_652 ) ;
}
F_242 ( & V_653 -> V_642 , V_654 , V_65 ) ;
F_243 ( & V_653 -> V_642 , V_639 ) ;
}
struct V_442 *
F_244 ( struct V_448 * V_449 )
{
int V_655 ;
T_3 V_649 = F_245 () ;
struct V_442 * V_443 , * V_656 ;
if ( ! ( V_449 -> V_458 & V_557 ) )
return F_173 ( F_168 ( V_449 ) ) ;
F_2 ( & V_449 -> V_534 ) ;
V_443 = F_239 ( & V_449 -> V_535 , V_649 ) ;
if ( V_443 )
F_173 ( V_443 ) ;
F_3 ( & V_449 -> V_534 ) ;
if ( V_443 == NULL ) {
V_656 = F_99 ( sizeof( * V_443 ) , V_117 ) ;
if ( V_656 == NULL )
return F_71 ( - V_83 ) ;
V_656 -> V_589 = V_649 ;
V_656 -> V_590 = F_71 ( - V_576 ) ;
F_211 ( V_657 , & V_656 -> V_446 ) ;
F_211 ( V_445 , & V_656 -> V_446 ) ;
F_173 ( V_656 ) ;
F_2 ( & V_449 -> V_534 ) ;
V_443 = F_239 ( & V_449 -> V_535 , V_649 ) ;
if ( V_443 ) {
F_173 ( V_443 ) ;
F_3 ( & V_449 -> V_534 ) ;
F_11 ( V_656 ) ;
goto V_658;
}
V_443 = V_656 ;
F_212 ( & V_449 -> V_535 , V_443 ) ;
F_3 ( & V_449 -> V_534 ) ;
} else {
V_658:
V_655 = F_246 ( & V_443 -> V_446 , V_657 ,
V_135 ) ;
if ( V_655 ) {
F_164 ( V_443 ) ;
return F_71 ( - V_88 ) ;
}
if ( ! F_124 ( V_443 -> V_590 ) )
return V_443 ;
if ( F_23 ( V_38 , V_443 -> V_447 + V_659 ) ) {
F_164 ( V_443 ) ;
return F_71 ( - V_576 ) ;
}
if ( F_247 ( V_657 , & V_443 -> V_446 ) )
goto V_658;
}
V_443 -> V_590 = F_237 ( V_449 , V_649 ) ;
F_232 ( V_657 , & V_443 -> V_446 ) ;
F_248 ( & V_443 -> V_446 , V_657 ) ;
if ( F_124 ( V_443 -> V_590 ) ) {
F_164 ( V_443 ) ;
return F_71 ( - V_576 ) ;
}
return V_443 ;
}
static void
V_533 ( struct V_46 * V_47 )
{
struct V_448 * V_449 = F_22 ( V_47 , struct V_448 ,
V_532 . V_47 ) ;
struct V_638 * V_639 = & V_449 -> V_535 ;
struct V_640 * V_641 = F_230 ( V_639 ) ;
struct V_640 * V_5 ;
struct V_442 * V_443 ;
F_2 ( & V_449 -> V_534 ) ;
V_641 = F_230 ( V_639 ) ;
while ( V_641 != NULL ) {
V_5 = V_641 ;
V_641 = F_249 ( V_5 ) ;
V_443 = F_231 ( V_5 , struct V_442 , V_642 ) ;
if ( F_166 ( V_591 , & V_443 -> V_446 ) ||
F_60 ( & V_443 -> V_444 ) != 0 ||
F_30 ( V_443 -> V_447 + V_592 , V_38 ) )
continue;
F_173 ( V_443 ) ;
F_232 ( V_445 , & V_443 -> V_446 ) ;
F_233 ( V_5 , V_639 ) ;
F_3 ( & V_449 -> V_534 ) ;
F_164 ( V_443 ) ;
F_2 ( & V_449 -> V_534 ) ;
}
F_3 ( & V_449 -> V_534 ) ;
F_24 ( V_57 , & V_449 -> V_532 ,
V_592 ) ;
}
