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
F_97 ( L_39 ) ;
break;
case V_311 :
#ifndef F_98
F_5 ( V_59 , L_40 ) ;
goto V_233;
#endif
V_148 -> V_312 = true ;
break;
case V_313 :
V_148 -> V_314 = true ;
break;
case V_315 :
V_148 -> V_316 = true ;
break;
case V_317 :
V_211 = true ;
break;
case V_318 :
V_148 -> V_319 = true ;
break;
case V_320 :
if ( F_75 ( args , & V_148 -> V_321 ) ) {
F_5 ( V_59 , L_41 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_235 = true ;
break;
case V_322 :
if ( F_79 ( args , & V_148 -> V_323 ) ) {
F_5 ( V_59 , L_42 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_236 = true ;
break;
case V_324 :
if ( F_75 ( args , & V_148 -> V_221 ) ) {
F_5 ( V_59 , L_43 ,
V_21 ) ;
goto V_233;
}
V_209 = true ;
break;
case V_325 :
if ( F_75 ( args , & V_148 -> V_220 ) ) {
F_5 ( V_59 , L_44 ,
V_21 ) ;
goto V_233;
}
break;
case V_326 :
if ( F_79 ( args , & V_148 -> V_222 ) ) {
F_5 ( V_59 , L_45 ,
V_21 ) ;
goto V_233;
}
V_210 = true ;
break;
case V_327 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_46 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_225 = V_142 ;
break;
case V_328 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_47 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_224 = V_142 ;
break;
case V_329 :
if ( F_72 ( args , & V_142 ) ||
V_142 > V_330 ) {
F_5 ( V_59 , L_48 ,
V_21 ) ;
goto V_233;
}
V_216 = ( unsigned short ) V_142 ;
break;
case V_331 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_49 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_332 = V_142 ;
break;
case V_333 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_50 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_334 = V_142 ;
break;
case V_335 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_51 ,
V_21 ) ;
goto V_233;
}
V_148 -> V_231 = V_53 * V_142 ;
if ( V_148 -> V_231 > V_336 ) {
F_5 ( V_59 , L_52 ) ;
goto V_233;
}
break;
case V_337 :
V_148 -> V_170 = 1 ;
V_148 -> V_338 = NULL ;
break;
case V_339 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_340;
if ( F_93 ( string , V_341 ) >
V_341 ) {
F_97 ( L_53 ) ;
goto V_233;
}
V_148 -> V_338 = F_90 ( string , V_117 ) ;
if ( ! V_148 -> V_338 )
goto V_233;
break;
case V_342 :
V_214 = strchr ( V_199 , '=' ) ;
V_214 ++ ;
if ( ! ( V_214 < V_200 && V_214 [ 1 ] == V_140 ) ) {
F_11 ( V_148 -> V_343 ) ;
V_148 -> V_343 = NULL ;
break;
}
case V_344 :
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
F_11 ( V_148 -> V_343 ) ;
V_203 = strlen ( V_144 ) ;
V_148 -> V_343 = F_99 ( V_203 + 1 , V_117 ) ;
if ( V_148 -> V_343 == NULL ) {
F_97 ( L_54 ) ;
goto V_233;
}
for ( V_204 = 0 , V_205 = 0 ; V_204 < V_203 ; V_204 ++ , V_205 ++ ) {
V_148 -> V_343 [ V_205 ] = V_144 [ V_204 ] ;
if ( ( V_144 [ V_204 ] == V_140 ) &&
V_144 [ V_204 + 1 ] == V_140 )
V_204 ++ ;
}
V_148 -> V_343 [ V_205 ] = '\0' ;
break;
case V_345 :
V_215 = false ;
break;
case V_346 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_340;
if ( ! F_100 ( V_97 , string ,
strlen ( string ) ) ) {
F_101 ( L_55 , string ) ;
goto V_233;
}
V_215 = true ;
break;
case V_347 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_340;
if ( F_93 ( string , V_348 )
== V_348 ) {
F_97 ( L_56 ) ;
goto V_233;
}
V_148 -> V_349 = F_90 ( string , V_117 ) ;
if ( ! V_148 -> V_349 ) {
F_97 ( L_57 ) ;
goto V_233;
}
F_5 ( V_20 , L_58 ) ;
break;
case V_350 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_340;
if ( ! F_100 (
(struct V_96 * ) & V_148 -> V_351 ,
string , strlen ( string ) ) ) {
F_97 ( L_59 ,
string ) ;
goto V_233;
}
break;
case V_352 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_340;
if ( F_93 ( string , 1024 ) >= 65 ) {
F_97 ( L_60 ) ;
goto V_233;
}
if ( strncasecmp ( string , L_61 , 7 ) != 0 ) {
V_148 -> V_353 = F_90 ( string ,
V_117 ) ;
if ( ! V_148 -> V_353 ) {
F_97 ( L_62 ) ;
goto V_233;
}
}
F_5 ( V_20 , L_63 , string ) ;
break;
case V_354 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_340;
memset ( V_148 -> V_217 , 0x20 ,
V_218 ) ;
for ( V_204 = 0 ; V_204 < V_218 ; V_204 ++ ) {
if ( string [ V_204 ] == 0 )
break;
V_148 -> V_217 [ V_204 ] = string [ V_204 ] ;
}
if ( V_204 == V_218 && string [ V_204 ] != 0 )
F_97 ( L_64 ) ;
break;
case V_355 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_340;
memset ( V_148 -> V_219 , 0x20 ,
V_356 ) ;
for ( V_204 = 0 ; V_204 < 15 ; V_204 ++ ) {
if ( string [ V_204 ] == 0 )
break;
V_148 -> V_219 [ V_204 ] = string [ V_204 ] ;
}
if ( V_204 == V_218 && string [ V_204 ] != 0 )
F_97 ( L_65 ) ;
break;
case V_357 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_340;
if ( strncasecmp ( string , L_66 , 1 ) == 0 ) {
break;
}
F_97 ( L_67 ) ;
goto V_233;
case V_358 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_340;
if ( F_86 ( string , V_148 ) != 0 )
goto V_233;
break;
case V_359 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_340;
if ( F_82 ( string , V_148 ) != 0 )
goto V_233;
break;
case V_360 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_340;
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
F_101 ( L_68 , V_212 ) ;
goto V_233;
}
#ifndef F_102
if ( V_148 -> V_316 ) {
F_5 ( V_59 , L_69 ) ;
goto V_233;
}
#endif
if ( ! V_148 -> V_196 ) {
F_5 ( V_59 , L_70 ) ;
goto V_233;
}
if ( ! strchr ( V_148 -> V_196 + 3 , '\\' ) ) {
F_5 ( V_59 , L_71 ) ;
goto V_233;
}
if ( ! V_215 ) {
if ( ! F_100 ( V_97 , & V_148 -> V_196 [ 2 ] ,
strlen ( & V_148 -> V_196 [ 2 ] ) ) ) {
F_101 ( L_72 ) ;
goto V_233;
}
}
F_41 ( V_97 , V_216 ) ;
if ( V_209 )
V_148 -> V_207 = V_207 ;
else if ( V_207 == 1 )
F_103 ( L_73 ) ;
if ( V_210 )
V_148 -> V_208 = V_208 ;
else if ( V_208 == 1 )
F_103 ( L_74 ) ;
F_11 ( V_201 ) ;
return 0 ;
V_340:
F_97 ( L_75 ) ;
V_233:
F_11 ( string ) ;
F_11 ( V_201 ) ;
return 1 ;
}
static bool
F_104 ( struct V_96 * V_351 , struct V_96 * V_361 )
{
switch ( V_351 -> V_362 ) {
case V_363 :
return ( V_361 -> V_362 == V_363 ) ;
case V_364 : {
struct V_365 * V_366 = (struct V_365 * ) V_351 ;
struct V_365 * V_367 = (struct V_365 * ) V_361 ;
return ( V_366 -> V_368 . V_369 == V_367 -> V_368 . V_369 ) ;
}
case V_370 : {
struct V_371 * V_372 = (struct V_371 * ) V_351 ;
struct V_371 * V_373 = (struct V_371 * ) V_361 ;
return F_105 ( & V_372 -> V_374 , & V_373 -> V_374 ) ;
}
default:
F_106 ( 1 ) ;
return false ;
}
}
static bool
F_107 ( struct V_1 * V_2 , struct V_96 * V_375 )
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
F_106 ( 1 ) ;
return false ;
}
if ( ! V_216 ) {
V_216 = F_108 ( V_98 ) ;
if ( V_216 == * V_376 )
return true ;
V_216 = F_108 ( V_379 ) ;
}
return V_216 == * V_376 ;
}
static bool
F_109 ( struct V_1 * V_2 , struct V_96 * V_375 ,
struct V_96 * V_351 )
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
if ( ! F_105 ( & V_382 -> V_374 ,
& V_383 -> V_374 ) )
return false ;
if ( V_382 -> V_384 != V_383 -> V_384 )
return false ;
break;
}
default:
F_106 ( 1 ) ;
return false ;
}
if ( ! F_104 ( V_351 , (struct V_96 * ) & V_2 -> V_351 ) )
return false ;
return true ;
}
static bool
F_110 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
if ( F_111 ( V_2 , V_148 -> V_150 ) == V_151 )
return false ;
if ( V_148 -> V_152 && ! V_2 -> V_152 )
return false ;
return true ;
}
static int F_112 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
struct V_96 * V_375 = (struct V_96 * ) & V_148 -> V_97 ;
if ( V_148 -> V_319 )
return 0 ;
if ( ( V_2 -> V_180 != V_148 -> V_180 ) || ( V_2 -> V_49 != V_148 -> V_49 ) )
return 0 ;
if ( ! F_113 ( F_114 ( V_2 ) , V_126 -> V_385 -> V_386 ) )
return 0 ;
if ( ! F_109 ( V_2 , V_375 ,
(struct V_96 * ) & V_148 -> V_351 ) )
return 0 ;
if ( ! F_107 ( V_2 , V_375 ) )
return 0 ;
if ( ! F_110 ( V_2 , V_148 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_115 ( struct V_147 * V_148 )
{
struct V_1 * V_2 ;
F_2 ( & V_22 ) ;
F_116 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_112 ( V_2 , V_148 ) )
continue;
++ V_2 -> V_387 ;
F_3 ( & V_22 ) ;
F_5 ( V_20 , L_76 ) ;
return V_2 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_117 ( struct V_1 * V_2 )
{
struct V_124 * V_388 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_387 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_118 ( F_114 ( V_2 ) ) ;
F_16 ( & V_2 -> V_107 ) ;
F_3 ( & V_22 ) ;
F_119 ( & V_2 -> V_48 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
F_11 ( V_2 -> V_34 . V_35 ) ;
V_2 -> V_34 . V_35 = NULL ;
V_2 -> V_34 . V_36 = 0 ;
V_388 = F_65 ( & V_2 -> V_134 , NULL ) ;
if ( V_388 )
F_122 ( V_389 , V_388 ) ;
}
static struct V_1 *
F_123 ( struct V_147 * V_390 )
{
struct V_1 * V_391 = NULL ;
int V_3 ;
F_5 ( V_20 , L_77 , V_390 -> V_196 ) ;
V_391 = F_115 ( V_390 ) ;
if ( V_391 )
return V_391 ;
V_391 = F_99 ( sizeof( struct V_1 ) , V_117 ) ;
if ( ! V_391 ) {
V_3 = - V_83 ;
goto V_392;
}
V_391 -> V_49 = V_390 -> V_49 ;
V_391 -> V_180 = V_390 -> V_180 ;
F_124 ( V_391 , F_125 ( V_126 -> V_385 -> V_386 ) ) ;
V_391 -> V_56 = F_70 ( V_390 -> V_196 ) ;
if ( F_126 ( V_391 -> V_56 ) ) {
V_3 = F_127 ( V_391 -> V_56 ) ;
goto V_393;
}
V_391 -> V_248 = V_390 -> V_248 ;
V_391 -> V_250 = V_390 -> V_250 ;
V_391 -> V_394 = V_390 -> V_395 ;
V_391 -> V_396 = 0 ;
V_391 -> V_109 = 1 ;
F_128 ( & V_391 -> V_63 ) ;
F_128 ( & V_391 -> V_110 ) ;
F_13 ( & V_391 -> V_111 ) ;
F_129 ( & V_391 -> V_27 ) ;
memcpy ( V_391 -> V_397 ,
V_390 -> V_217 , V_356 ) ;
memcpy ( V_391 -> V_398 ,
V_390 -> V_219 , V_356 ) ;
V_391 -> V_33 = false ;
V_391 -> V_32 = 0 ;
V_391 -> V_37 = V_38 ;
F_130 ( & V_391 -> V_108 ) ;
F_13 ( & V_391 -> V_107 ) ;
F_13 ( & V_391 -> V_23 ) ;
F_131 ( & V_391 -> V_48 , F_21 ) ;
memcpy ( & V_391 -> V_351 , & V_390 -> V_351 ,
sizeof( V_391 -> V_351 ) ) ;
memcpy ( & V_391 -> V_97 , & V_390 -> V_97 ,
sizeof( V_391 -> V_97 ) ) ;
#ifdef F_4
F_132 ( V_391 -> V_399 , V_400 ) ;
#endif
V_391 -> V_15 = V_401 ;
++ V_391 -> V_387 ;
V_3 = F_133 ( V_391 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_78 ) ;
goto V_393;
}
F_134 ( V_402 ) ;
V_391 -> V_134 = F_135 ( F_56 ,
V_391 , L_79 ) ;
if ( F_126 ( V_391 -> V_134 ) ) {
V_3 = F_127 ( V_391 -> V_134 ) ;
F_5 ( V_59 , L_80 , V_3 ) ;
F_136 ( V_402 ) ;
goto V_393;
}
V_391 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_137 ( & V_391 -> V_107 , & V_403 ) ;
F_3 ( & V_22 ) ;
F_138 ( V_391 ) ;
F_24 ( V_57 , & V_391 -> V_48 , V_52 ) ;
return V_391 ;
V_393:
F_120 ( V_391 ) ;
F_118 ( F_114 ( V_391 ) ) ;
V_392:
if ( V_391 ) {
if ( ! F_126 ( V_391 -> V_56 ) )
F_11 ( V_391 -> V_56 ) ;
if ( V_391 -> V_28 )
F_10 ( V_391 -> V_28 ) ;
F_11 ( V_391 ) ;
}
return F_71 ( V_3 ) ;
}
static int F_139 ( struct V_7 * V_8 , struct V_147 * V_148 )
{
if ( V_148 -> V_150 != V_151 &&
V_148 -> V_150 != V_8 -> V_150 )
return 0 ;
switch ( V_8 -> V_150 ) {
case V_157 :
if ( ! F_140 ( V_148 -> V_220 , V_8 -> V_220 ) )
return 0 ;
break;
default:
if ( V_8 -> V_404 == NULL ) {
if ( ! V_148 -> V_170 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_404 ,
V_148 -> V_338 ? V_148 -> V_338 : L_81 ,
V_341 ) )
return 0 ;
if ( ( V_148 -> V_338 && strlen ( V_148 -> V_338 ) != 0 ) &&
V_8 -> V_343 != NULL &&
strncmp ( V_8 -> V_343 ,
V_148 -> V_343 ? V_148 -> V_343 : L_81 ,
V_405 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_141 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
struct V_7 * V_8 ;
F_2 ( & V_22 ) ;
F_116 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_8 -> V_406 == V_16 )
continue;
if ( ! F_139 ( V_8 , V_148 ) )
continue;
++ V_8 -> V_407 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_142 ( struct V_7 * V_8 )
{
unsigned int V_3 , V_408 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_20 , L_82 , V_21 , V_8 -> V_407 ) ;
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
V_408 = F_143 () ;
V_3 = V_2 -> V_49 -> V_409 ( V_408 , V_8 ) ;
if ( V_3 )
F_5 ( V_59 , L_83 ,
V_21 , V_3 ) ;
F_144 ( V_408 ) ;
}
F_2 ( & V_22 ) ;
F_16 ( & V_8 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_145 ( V_8 ) ;
F_117 ( V_2 ) ;
}
static int
F_146 ( struct V_147 * V_148 , struct V_7 * V_8 )
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
sprintf ( V_410 , L_84 , & V_413 -> V_368 . V_369 ) ;
break;
case V_370 :
V_414 = (struct V_371 * ) & V_2 -> V_97 ;
sprintf ( V_410 , L_85 , & V_414 -> V_374 . V_419 ) ;
break;
default:
F_5 ( V_20 , L_86 ,
V_2 -> V_97 . V_418 ) ;
V_3 = - V_141 ;
goto V_392;
}
F_5 ( V_20 , L_87 , V_21 , V_410 ) ;
V_412 = F_147 ( & V_420 , V_410 , L_81 ) ;
if ( F_126 ( V_412 ) ) {
if ( ! V_8 -> V_421 ) {
F_5 ( V_20 , L_88 ) ;
V_3 = F_127 ( V_412 ) ;
goto V_392;
}
sprintf ( V_410 , L_89 , V_8 -> V_421 ) ;
F_5 ( V_20 , L_87 , V_21 , V_410 ) ;
V_412 = F_147 ( & V_420 , V_410 , L_81 ) ;
if ( F_126 ( V_412 ) ) {
V_3 = F_127 ( V_412 ) ;
goto V_392;
}
}
F_148 ( & V_412 -> V_422 ) ;
V_416 = V_412 -> V_411 . V_199 ;
if ( F_149 ( V_416 ) ) {
V_3 = V_416 ? F_127 ( V_416 ) : - V_141 ;
goto V_423;
}
V_411 = ( char * ) V_416 -> V_199 ;
V_140 = F_150 ( V_411 , V_416 -> V_424 , ':' ) ;
F_5 ( V_20 , L_90 , V_411 ) ;
if ( ! V_140 ) {
F_5 ( V_20 , L_91 ,
V_416 -> V_424 ) ;
V_3 = - V_141 ;
goto V_423;
}
V_36 = V_140 - V_411 ;
if ( V_36 > V_341 || V_36 <= 0 ) {
F_5 ( V_20 , L_92 ,
V_36 ) ;
V_3 = - V_141 ;
goto V_423;
}
V_148 -> V_338 = F_88 ( V_411 , V_36 , V_117 ) ;
if ( ! V_148 -> V_338 ) {
F_5 ( V_20 , L_93 ,
V_36 ) ;
V_3 = - V_83 ;
goto V_423;
}
F_5 ( V_20 , L_94 , V_21 , V_148 -> V_338 ) ;
V_36 = V_412 -> V_424 - ( V_36 + 1 ) ;
if ( V_36 > V_405 || V_36 <= 0 ) {
F_5 ( V_20 , L_95 , V_36 ) ;
V_3 = - V_141 ;
F_11 ( V_148 -> V_338 ) ;
V_148 -> V_338 = NULL ;
goto V_423;
}
++ V_140 ;
V_148 -> V_343 = F_88 ( V_140 , V_36 , V_117 ) ;
if ( ! V_148 -> V_343 ) {
F_5 ( V_20 , L_96 ,
V_36 ) ;
V_3 = - V_83 ;
F_11 ( V_148 -> V_338 ) ;
V_148 -> V_338 = NULL ;
goto V_423;
}
V_423:
F_151 ( & V_412 -> V_422 ) ;
F_152 ( V_412 ) ;
V_392:
F_11 ( V_410 ) ;
F_5 ( V_20 , L_97 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_153 ( struct V_1 * V_2 , struct V_147 * V_390 )
{
int V_3 = - V_83 ;
unsigned int V_408 ;
struct V_7 * V_8 ;
struct V_365 * V_375 = (struct V_365 * ) & V_2 -> V_97 ;
struct V_371 * V_382 = (struct V_371 * ) & V_2 -> V_97 ;
V_408 = F_143 () ;
V_8 = F_141 ( V_2 , V_390 ) ;
if ( V_8 ) {
F_5 ( V_20 , L_98 ,
V_8 -> V_406 ) ;
F_8 ( & V_8 -> V_425 ) ;
V_3 = F_154 ( V_408 , V_8 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_425 ) ;
F_142 ( V_8 ) ;
F_155 ( V_408 ) ;
return F_71 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_5 ( V_20 , L_99 ) ;
V_3 = F_156 ( V_408 , V_8 ,
V_390 -> V_426 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_425 ) ;
F_142 ( V_8 ) ;
F_155 ( V_408 ) ;
return F_71 ( V_3 ) ;
}
}
F_12 ( & V_8 -> V_425 ) ;
F_117 ( V_2 ) ;
F_155 ( V_408 ) ;
return V_8 ;
}
F_5 ( V_20 , L_100 ) ;
V_8 = F_157 () ;
if ( V_8 == NULL )
goto V_427;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_97 . V_418 == V_370 )
sprintf ( V_8 -> V_428 , L_101 , & V_382 -> V_374 ) ;
else
sprintf ( V_8 -> V_428 , L_102 , & V_375 -> V_368 ) ;
if ( V_390 -> V_338 ) {
V_8 -> V_404 = F_90 ( V_390 -> V_338 , V_117 ) ;
if ( ! V_8 -> V_404 )
goto V_427;
}
if ( V_390 -> V_343 ) {
V_8 -> V_343 = F_90 ( V_390 -> V_343 , V_117 ) ;
if ( ! V_8 -> V_343 )
goto V_427;
}
if ( V_390 -> V_349 ) {
V_8 -> V_421 = F_90 ( V_390 -> V_349 , V_117 ) ;
if ( ! V_8 -> V_421 )
goto V_427;
}
V_8 -> V_220 = V_390 -> V_220 ;
V_8 -> V_221 = V_390 -> V_221 ;
V_8 -> V_150 = V_390 -> V_150 ;
V_8 -> V_152 = V_390 -> V_152 ;
F_8 ( & V_8 -> V_425 ) ;
V_3 = F_154 ( V_408 , V_8 ) ;
if ( ! V_3 )
V_3 = F_156 ( V_408 , V_8 , V_390 -> V_426 ) ;
F_12 ( & V_8 -> V_425 ) ;
if ( V_3 )
goto V_427;
F_2 ( & V_22 ) ;
F_137 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_155 ( V_408 ) ;
return V_8 ;
V_427:
F_145 ( V_8 ) ;
F_155 ( V_408 ) ;
return F_71 ( V_3 ) ;
}
static int F_158 ( struct V_9 * V_10 , const char * V_137 )
{
if ( V_10 -> V_429 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_430 , V_137 , V_431 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_159 ( struct V_7 * V_8 , const char * V_137 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_22 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_26 ) ;
if ( ! F_158 ( V_10 , V_137 ) )
continue;
++ V_10 -> V_432 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_160 ( struct V_9 * V_10 )
{
unsigned int V_408 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( V_20 , L_103 , V_21 , V_10 -> V_432 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_432 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_408 = F_143 () ;
if ( V_8 -> V_2 -> V_49 -> V_433 )
V_8 -> V_2 -> V_49 -> V_433 ( V_408 , V_10 ) ;
F_144 ( V_408 ) ;
F_161 ( V_10 ) ;
F_162 ( V_10 ) ;
F_142 ( V_8 ) ;
}
static struct V_9 *
F_163 ( struct V_7 * V_8 , struct V_147 * V_390 )
{
int V_3 , V_408 ;
struct V_9 * V_10 ;
V_10 = F_159 ( V_8 , V_390 -> V_196 ) ;
if ( V_10 ) {
F_5 ( V_20 , L_104 ) ;
F_142 ( V_8 ) ;
if ( V_10 -> V_309 != V_390 -> V_309 )
F_5 ( V_59 , L_105 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_49 -> V_434 ) {
V_3 = - V_55 ;
goto V_435;
}
V_10 = F_164 () ;
if ( V_10 == NULL ) {
V_3 = - V_83 ;
goto V_435;
}
V_10 -> V_8 = V_8 ;
if ( V_390 -> V_343 ) {
V_10 -> V_343 = F_90 ( V_390 -> V_343 , V_117 ) ;
if ( ! V_10 -> V_343 ) {
V_3 = - V_83 ;
goto V_435;
}
}
V_408 = F_143 () ;
V_3 = V_8 -> V_2 -> V_49 -> V_434 ( V_408 , V_8 , V_390 -> V_196 , V_10 ,
V_390 -> V_426 ) ;
F_155 ( V_408 ) ;
F_5 ( V_20 , L_106 , V_3 ) ;
if ( V_3 )
goto V_435;
if ( V_390 -> V_266 ) {
V_10 -> V_436 &= ~ V_437 ;
F_5 ( V_20 , L_107 , V_10 -> V_436 ) ;
}
V_10 -> V_309 = V_390 -> V_309 ;
V_10 -> V_252 = V_390 -> V_252 ;
V_10 -> V_272 = V_390 -> V_272 ;
V_10 -> V_306 = V_390 -> V_306 ;
F_13 ( & V_10 -> V_438 ) ;
F_2 ( & V_22 ) ;
F_137 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_165 ( V_10 ) ;
return V_10 ;
V_435:
F_162 ( V_10 ) ;
return F_71 ( V_3 ) ;
}
void
F_166 ( struct V_439 * V_440 )
{
if ( ! V_440 || F_126 ( V_440 ) )
return;
if ( ! F_167 ( & V_440 -> V_441 ) ||
F_168 ( V_442 , & V_440 -> V_443 ) ) {
V_440 -> V_444 = V_38 ;
return;
}
if ( ! F_126 ( F_169 ( V_440 ) ) )
F_160 ( F_169 ( V_440 ) ) ;
F_11 ( V_440 ) ;
return;
}
static inline struct V_439 *
F_170 ( struct V_445 * V_446 )
{
return V_446 -> V_447 ;
}
static int
F_171 ( struct V_448 * V_449 , struct V_450 * V_451 )
{
struct V_445 * V_452 = F_172 ( V_449 ) ;
struct V_445 * V_65 = V_451 -> V_446 ;
if ( ( V_449 -> V_453 & V_454 ) != ( V_451 -> V_30 & V_454 ) )
return 0 ;
if ( ( V_452 -> V_455 & V_456 ) !=
( V_65 -> V_455 & V_456 ) )
return 0 ;
if ( V_65 -> V_334 && V_65 -> V_334 < V_452 -> V_334 )
return 0 ;
if ( V_65 -> V_332 && V_65 -> V_332 < V_452 -> V_332 )
return 0 ;
if ( ! F_140 ( V_452 -> V_457 , V_65 -> V_457 ) || ! F_173 ( V_452 -> V_458 , V_65 -> V_458 ) )
return 0 ;
if ( V_452 -> V_459 != V_65 -> V_459 ||
V_452 -> V_460 != V_65 -> V_460 )
return 0 ;
if ( strcmp ( V_452 -> V_426 -> V_461 , V_65 -> V_426 -> V_461 ) )
return 0 ;
if ( V_452 -> V_231 != V_65 -> V_231 )
return 0 ;
return 1 ;
}
int
F_174 ( struct V_448 * V_449 , void * V_199 )
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
V_446 = F_172 ( V_449 ) ;
V_440 = F_175 ( F_170 ( V_446 ) ) ;
if ( F_126 ( V_440 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_169 ( V_440 ) ;
V_8 = V_10 -> V_8 ;
V_462 = V_8 -> V_2 ;
V_390 = V_451 -> V_148 ;
if ( ! F_112 ( V_462 , V_390 ) ||
! F_139 ( V_8 , V_390 ) ||
! F_158 ( V_10 , V_390 -> V_196 ) ) {
V_3 = 0 ;
goto V_463;
}
V_3 = F_171 ( V_449 , V_451 ) ;
V_463:
F_3 ( & V_22 ) ;
F_166 ( V_440 ) ;
return V_3 ;
}
int
F_176 ( const unsigned int V_408 , struct V_7 * V_8 , const char * V_464 ,
const struct V_465 * V_466 , unsigned int * V_467 ,
struct V_468 * * V_469 , int V_223 )
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
strcpy ( V_470 + 2 + strlen ( V_8 -> V_428 ) , L_108 ) ;
V_3 = V_8 -> V_2 -> V_49 -> V_434 ( V_408 , V_8 , V_470 , NULL ,
V_466 ) ;
F_5 ( V_20 , L_109 , V_3 , V_8 -> V_25 ) ;
F_11 ( V_470 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_49 -> V_471 ( V_408 , V_8 , V_464 ,
V_469 , V_467 ,
V_466 , V_223 ) ;
return V_3 ;
}
static inline void
F_177 ( struct V_473 * V_474 )
{
struct V_474 * V_475 = V_474 -> V_475 ;
F_178 ( F_179 ( V_475 ) ) ;
F_180 ( V_475 , L_110 ,
& V_476 [ 0 ] , L_111 , & V_477 [ 0 ] ) ;
}
static inline void
F_181 ( struct V_473 * V_474 )
{
struct V_474 * V_475 = V_474 -> V_475 ;
F_178 ( F_179 ( V_475 ) ) ;
F_180 ( V_475 , L_112 ,
& V_476 [ 1 ] , L_113 , & V_477 [ 1 ] ) ;
}
static inline void
F_177 ( struct V_473 * V_474 )
{
}
static inline void
F_181 ( struct V_473 * V_474 )
{
}
static void F_182 ( char * V_478 , char * V_479 , unsigned int V_78 )
{
unsigned int V_204 , V_205 ;
for ( V_204 = 0 , V_205 = 0 ; V_204 < ( V_78 ) ; V_204 ++ ) {
V_478 [ V_205 ] = 'A' + ( 0x0F & ( V_479 [ V_204 ] >> 4 ) ) ;
V_478 [ V_205 + 1 ] = 'A' + ( 0x0F & V_479 [ V_204 ] ) ;
V_205 += 2 ;
}
}
static int
F_183 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_351 . V_418 != V_363 ) {
struct V_473 * V_473 = V_2 -> V_28 ;
V_3 = V_473 -> V_49 -> V_480 ( V_473 ,
(struct V_96 * ) & V_2 -> V_351 ,
sizeof( V_2 -> V_351 ) ) ;
if ( V_3 < 0 ) {
struct V_365 * V_366 ;
struct V_371 * V_372 ;
V_366 = (struct V_365 * ) & V_2 -> V_351 ;
V_372 = (struct V_371 * ) & V_2 -> V_351 ;
if ( V_372 -> V_481 == V_370 )
F_5 ( V_59 , L_114 ,
& V_372 -> V_374 , V_3 ) ;
else
F_5 ( V_59 , L_115 ,
& V_366 -> V_368 . V_369 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_184 ( struct V_1 * V_2 )
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
F_182 ( V_483 -> V_486 .
V_487 . V_489 ,
V_2 -> V_398 ,
V_356 ) ;
else
F_182 ( V_483 -> V_486 .
V_487 . V_489 ,
V_490 ,
V_356 ) ;
V_483 -> V_486 . V_487 . V_491 = 32 ;
if ( V_2 -> V_397 &&
V_2 -> V_397 [ 0 ] != 0 )
F_182 ( V_483 -> V_486 .
V_487 . V_492 ,
V_2 -> V_397 ,
V_356 ) ;
else
F_182 ( V_483 -> V_486 .
V_487 . V_492 ,
L_116 ,
V_356 ) ;
V_483 -> V_486 . V_487 . V_493 = 0 ;
V_483 -> V_486 . V_487 . V_494 = 0 ;
V_485 = (struct V_484 * ) V_483 ;
V_485 -> V_495 = F_185 ( 0x81000044 ) ;
V_3 = F_186 ( V_2 , V_485 , 0x44 ) ;
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
V_3 = F_187 ( F_114 ( V_2 ) , V_497 , V_499 ,
V_500 , & V_473 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_117 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_5 ( V_20 , L_118 ) ;
V_2 -> V_28 = V_473 ;
V_473 -> V_475 -> V_501 = V_75 ;
if ( V_497 == V_370 )
F_181 ( V_473 ) ;
else
F_177 ( V_473 ) ;
}
V_3 = F_183 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_473 -> V_475 -> V_502 = 7 * V_53 ;
V_473 -> V_475 -> V_503 = 5 * V_53 ;
if ( V_2 -> V_250 ) {
if ( V_473 -> V_475 -> V_504 < ( 200 * 1024 ) )
V_473 -> V_475 -> V_504 = 200 * 1024 ;
if ( V_473 -> V_475 -> V_505 < ( 140 * 1024 ) )
V_473 -> V_475 -> V_505 = 140 * 1024 ;
}
if ( V_2 -> V_394 ) {
int V_506 = 1 ;
V_3 = F_188 ( V_473 , V_507 , V_508 ,
( char * ) & V_506 , sizeof( V_506 ) ) ;
if ( V_3 )
F_5 ( V_20 , L_119 ,
V_3 ) ;
}
F_5 ( V_20 , L_120 ,
V_473 -> V_475 -> V_504 ,
V_473 -> V_475 -> V_505 , V_473 -> V_475 -> V_502 ) ;
V_3 = V_473 -> V_49 -> V_509 ( V_473 , V_498 , V_496 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_20 , L_121 , V_3 ) ;
F_10 ( V_473 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_376 == F_108 ( V_379 ) )
V_3 = F_184 ( V_2 ) ;
return V_3 ;
}
static int
F_133 ( struct V_1 * V_2 )
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
* V_376 = F_108 ( V_98 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_376 = F_108 ( V_379 ) ;
}
return F_18 ( V_2 ) ;
}
void F_189 ( unsigned int V_408 , struct V_9 * V_10 ,
struct V_445 * V_446 , struct V_147 * V_510 )
{
T_7 V_511 = F_190 ( V_10 -> V_512 . V_513 ) ;
if ( V_510 && V_510 -> V_270 ) {
V_10 -> V_512 . V_513 = 0 ;
V_10 -> V_514 = 0 ;
F_5 ( V_20 , L_122 ) ;
return;
} else if ( V_510 )
V_10 -> V_514 = 1 ;
if ( V_10 -> V_514 == 0 ) {
F_5 ( V_20 , L_123 ) ;
return;
}
if ( ! F_191 ( V_408 , V_10 ) ) {
T_7 V_515 = F_190 ( V_10 -> V_512 . V_513 ) ;
F_5 ( V_20 , L_124 , V_515 ) ;
if ( V_510 == NULL ) {
if ( ( V_511 & V_516 ) == 0 )
V_515 &= ~ V_516 ;
if ( ( V_511 & V_517 ) == 0 ) {
if ( V_515 & V_517 )
F_5 ( V_59 , L_125 ) ;
V_515 &= ~ V_517 ;
} else if ( ( V_515 & V_517 ) == 0 ) {
F_5 ( V_59 , L_126 ) ;
F_5 ( V_59 , L_127 ) ;
}
}
if ( V_515 & V_518 )
F_5 ( V_59 , L_128 ) ;
V_515 &= V_519 ;
if ( V_510 && V_510 -> V_303 )
V_515 &= ~ V_516 ;
else if ( V_516 & V_515 ) {
F_5 ( V_20 , L_129 ) ;
if ( V_446 )
V_446 -> V_455 |=
V_520 ;
}
if ( V_510 && V_510 -> V_229 == 0 )
V_515 &= ~ V_517 ;
else if ( V_515 & V_517 ) {
F_5 ( V_20 , L_130 ) ;
if ( V_446 )
V_446 -> V_455 |=
V_521 ;
}
F_5 ( V_20 , L_131 , ( int ) V_515 ) ;
#ifdef F_61
if ( V_515 & V_522 )
F_5 ( V_20 , L_132 ) ;
if ( V_515 & V_523 )
F_5 ( V_20 , L_133 ) ;
if ( V_515 & V_517 )
F_5 ( V_20 , L_134 ) ;
if ( V_515 & V_524 )
F_5 ( V_20 , L_135 ) ;
if ( V_515 & V_516 )
F_5 ( V_20 , L_136 ) ;
if ( V_515 & V_525 )
F_5 ( V_20 , L_137 ) ;
if ( V_515 & V_526 )
F_5 ( V_20 , L_138 ) ;
if ( V_515 & V_527 )
F_5 ( V_20 , L_139 ) ;
if ( V_515 & V_518 )
F_5 ( V_20 , L_140 ) ;
#endif
if ( F_192 ( V_408 , V_10 , V_515 ) ) {
if ( V_510 == NULL ) {
F_5 ( V_20 , L_141 ) ;
} else
F_5 ( V_59 , L_142 ) ;
}
}
}
void F_193 ( struct V_147 * V_528 ,
struct V_445 * V_446 )
{
F_131 ( & V_446 -> V_529 , V_530 ) ;
F_130 ( & V_446 -> V_531 ) ;
V_446 -> V_532 = V_533 ;
V_446 -> V_332 = V_528 -> V_332 ;
V_446 -> V_334 = V_528 -> V_334 ;
V_446 -> V_457 = V_528 -> V_221 ;
V_446 -> V_458 = V_528 -> V_222 ;
V_446 -> V_459 = V_528 -> V_225 ;
V_446 -> V_460 = V_528 -> V_224 ;
F_5 ( V_20 , L_143 ,
V_446 -> V_459 , V_446 -> V_460 ) ;
V_446 -> V_231 = V_528 -> V_231 ;
V_446 -> V_426 = V_528 -> V_426 ;
if ( V_528 -> V_255 )
V_446 -> V_455 |= V_534 ;
if ( V_528 -> V_282 )
V_446 -> V_455 |= V_535 ;
if ( V_528 -> V_230 )
V_446 -> V_455 |= V_536 ;
if ( V_528 -> V_223 )
V_446 -> V_455 |= V_537 ;
if ( V_528 -> V_258 )
V_446 -> V_455 |= V_538 ;
if ( V_528 -> V_241 )
V_446 -> V_455 |= V_539 ;
if ( V_528 -> V_263 )
V_446 -> V_455 |= V_540 ;
if ( V_528 -> V_274 )
V_446 -> V_455 |= V_541 ;
if ( V_528 -> V_293 )
V_446 -> V_455 |= V_542 ;
if ( V_528 -> V_280 )
V_446 -> V_455 |= V_543 ;
if ( V_528 -> V_298 )
V_446 -> V_455 |= V_544 ;
if ( V_528 -> V_300 )
V_446 -> V_455 |= V_545 ;
if ( V_528 -> V_235 ) {
V_446 -> V_455 |= V_546 ;
V_446 -> V_547 = V_528 -> V_321 ;
}
if ( V_528 -> V_236 ) {
V_446 -> V_455 |= V_548 ;
V_446 -> V_549 = V_528 -> V_323 ;
}
if ( V_528 -> V_207 )
V_446 -> V_455 |= V_550 ;
if ( V_528 -> V_208 )
V_446 -> V_455 |= V_551 ;
if ( V_528 -> V_285 )
V_446 -> V_455 |= V_552 ;
if ( V_528 -> V_312 )
V_446 -> V_455 |= V_553 ;
if ( V_528 -> V_316 )
V_446 -> V_455 |= ( V_554 |
V_534 ) ;
if ( V_528 -> V_174 )
V_446 -> V_455 |= V_555 ;
if ( V_528 -> V_173 ) {
F_5 ( V_20 , L_144 ) ;
V_446 -> V_455 |= V_556 ;
}
if ( V_528 -> V_314 ) {
if ( V_528 -> V_263 ) {
F_5 ( V_59 , L_145 ) ;
}
V_446 -> V_455 |= V_557 ;
}
if ( ( V_528 -> V_300 ) && ( V_528 -> V_285 ) )
F_5 ( V_59 , L_146 ) ;
}
static void
F_194 ( struct V_147 * V_390 )
{
F_11 ( V_390 -> V_338 ) ;
F_195 ( V_390 -> V_343 ) ;
F_11 ( V_390 -> V_196 ) ;
F_11 ( V_390 -> V_349 ) ;
F_11 ( V_390 -> V_353 ) ;
F_11 ( V_390 -> V_197 ) ;
}
void
F_196 ( struct V_147 * V_390 )
{
if ( ! V_390 )
return;
F_194 ( V_390 ) ;
F_11 ( V_390 ) ;
}
static char *
F_197 ( const struct V_147 * V_148 ,
const struct V_445 * V_446 )
{
char * V_558 , * V_194 ;
unsigned int V_559 = V_148 -> V_197 ? strlen ( V_148 -> V_197 ) + 1 : 0 ;
unsigned int V_560 = F_93 ( V_148 -> V_196 , V_431 + 1 ) ;
V_558 = F_35 ( V_560 + V_559 + 1 , V_117 ) ;
if ( V_558 == NULL )
return F_71 ( - V_83 ) ;
strncpy ( V_558 , V_148 -> V_196 , V_560 ) ;
V_194 = V_558 + V_560 ;
if ( V_559 ) {
* V_194 = F_198 ( V_446 ) ;
strncpy ( V_194 + 1 , V_148 -> V_197 , V_559 ) ;
V_194 += V_559 ;
}
* V_194 = '\0' ;
F_89 ( V_558 , F_198 ( V_446 ) ) ;
F_5 ( V_20 , L_147 , V_21 , V_558 ) ;
return V_558 ;
}
static int
F_199 ( const unsigned int V_408 , struct V_7 * V_8 ,
struct V_147 * V_390 , struct V_445 * V_446 ,
int V_561 )
{
int V_3 ;
unsigned int V_467 = 0 ;
struct V_468 * V_469 = NULL ;
char * V_558 = NULL , * V_562 = NULL , * V_563 = NULL ;
V_558 = F_197 ( V_390 , V_446 ) ;
if ( F_126 ( V_558 ) )
return F_127 ( V_558 ) ;
V_562 = V_561 ? V_558 + 1 : V_390 -> V_196 + 1 ;
V_3 = F_176 ( V_408 , V_8 , V_562 , V_446 -> V_426 ,
& V_467 , & V_469 , F_200 ( V_446 ) ) ;
if ( ! V_3 && V_467 > 0 ) {
char * V_564 = NULL ;
V_563 = F_201 ( V_446 -> V_198 ,
V_558 + 1 , V_469 ,
& V_564 ) ;
F_202 ( V_469 , V_467 ) ;
if ( F_126 ( V_563 ) ) {
V_3 = F_127 ( V_563 ) ;
V_563 = NULL ;
} else {
F_194 ( V_390 ) ;
V_3 = F_203 ( V_390 , V_563 ,
V_564 ) ;
}
F_11 ( V_564 ) ;
F_11 ( V_446 -> V_198 ) ;
V_446 -> V_198 = V_563 ;
}
F_11 ( V_558 ) ;
return V_3 ;
}
static int
F_203 ( struct V_147 * V_390 , char * V_565 ,
const char * V_193 )
{
int V_3 = 0 ;
if ( F_91 ( V_565 , V_193 , V_390 ) )
return - V_141 ;
if ( V_390 -> V_170 ) {
F_5 ( V_20 , L_148 ) ;
F_11 ( V_390 -> V_338 ) ;
V_390 -> V_338 = NULL ;
} else if ( V_390 -> V_338 ) {
F_5 ( V_20 , L_149 , V_390 -> V_338 ) ;
} else {
F_5 ( V_59 , L_150 ) ;
return - V_141 ;
}
if ( V_390 -> V_353 == NULL ) {
V_390 -> V_426 = F_204 () ;
} else {
V_390 -> V_426 = F_205 ( V_390 -> V_353 ) ;
if ( V_390 -> V_426 == NULL ) {
F_5 ( V_59 , L_151 ,
V_390 -> V_353 ) ;
return - V_566 ;
}
}
return V_3 ;
}
struct V_147 *
F_206 ( char * V_565 , const char * V_193 )
{
int V_3 ;
struct V_147 * V_390 ;
V_390 = F_35 ( sizeof( struct V_147 ) , V_117 ) ;
if ( ! V_390 )
return F_71 ( - V_83 ) ;
V_3 = F_203 ( V_390 , V_565 , V_193 ) ;
if ( V_3 ) {
F_196 ( V_390 ) ;
V_390 = F_71 ( V_3 ) ;
}
return V_390 ;
}
int
F_207 ( struct V_445 * V_446 , struct V_147 * V_390 )
{
int V_3 ;
unsigned int V_408 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_558 ;
struct V_439 * V_440 ;
#ifdef F_208
int V_567 = 0 ;
#endif
V_3 = F_209 ( & V_446 -> V_568 , L_152 , V_569 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_208
V_570:
if ( V_567 ) {
if ( V_10 )
F_160 ( V_10 ) ;
else if ( V_8 )
F_142 ( V_8 ) ;
F_155 ( V_408 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_558 = NULL ;
V_440 = NULL ;
V_408 = F_143 () ;
V_2 = F_123 ( V_390 ) ;
if ( F_126 ( V_2 ) ) {
V_3 = F_127 ( V_2 ) ;
F_210 ( & V_446 -> V_568 ) ;
goto V_463;
}
V_8 = F_153 ( V_2 , V_390 ) ;
if ( F_126 ( V_8 ) ) {
V_3 = F_127 ( V_8 ) ;
V_8 = NULL ;
goto V_571;
}
V_10 = F_163 ( V_8 , V_390 ) ;
if ( F_126 ( V_10 ) ) {
V_3 = F_127 ( V_10 ) ;
V_10 = NULL ;
goto V_572;
}
if ( F_211 ( V_10 -> V_8 ) ) {
F_189 ( V_408 , V_10 , V_446 , V_390 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_190 ( V_10 -> V_512 . V_513 ) &
V_518 ) ) {
V_3 = - V_573 ;
goto V_571;
}
} else
V_10 -> V_514 = 0 ;
if ( ! V_10 -> V_574 && V_2 -> V_49 -> V_575 )
V_2 -> V_49 -> V_575 ( V_408 , V_10 ) ;
V_446 -> V_334 = V_2 -> V_49 -> V_576 ( V_10 , V_390 ) ;
V_446 -> V_332 = V_2 -> V_49 -> V_577 ( V_10 , V_390 ) ;
V_446 -> V_568 . V_578 = V_446 -> V_332 / V_579 ;
V_572:
#ifdef F_208
if ( V_567 == 0 ) {
int V_580 = F_199 ( V_408 , V_8 , V_390 , V_446 ,
false ) ;
if ( ! V_580 ) {
V_567 ++ ;
goto V_570;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_49 -> V_581 ) {
V_3 = - V_55 ;
goto V_571;
}
V_558 = F_212 ( V_390 , V_446 , V_10 ) ;
if ( V_558 == NULL ) {
V_3 = - V_83 ;
goto V_571;
}
V_3 = V_2 -> V_49 -> V_581 ( V_408 , V_10 , V_446 ,
V_558 ) ;
if ( V_3 != 0 && V_3 != - V_582 ) {
F_11 ( V_558 ) ;
goto V_571;
}
F_11 ( V_558 ) ;
}
if ( V_3 == - V_582 ) {
#ifdef F_208
if ( V_567 > V_583 ) {
V_3 = - V_584 ;
goto V_571;
}
V_3 = F_199 ( V_408 , V_8 , V_390 , V_446 , true ) ;
if ( ! V_3 ) {
V_567 ++ ;
goto V_570;
}
goto V_571;
#else
V_3 = - V_585 ;
#endif
}
if ( V_3 )
goto V_571;
V_440 = F_99 ( sizeof *V_440 , V_117 ) ;
if ( V_440 == NULL ) {
V_3 = - V_83 ;
goto V_571;
}
V_440 -> V_586 = V_8 -> V_221 ;
V_440 -> V_587 = V_10 ;
V_440 -> V_444 = V_38 ;
F_213 ( V_588 , & V_440 -> V_443 ) ;
F_213 ( V_442 , & V_440 -> V_443 ) ;
V_446 -> V_447 = V_440 ;
F_2 ( & V_446 -> V_531 ) ;
F_214 ( & V_446 -> V_532 , V_440 ) ;
F_3 ( & V_446 -> V_531 ) ;
F_24 ( V_57 , & V_446 -> V_529 ,
V_589 ) ;
V_571:
if ( V_3 ) {
if ( V_10 )
F_160 ( V_10 ) ;
else if ( V_8 )
F_142 ( V_8 ) ;
else
F_117 ( V_2 ) ;
F_210 ( & V_446 -> V_568 ) ;
}
V_463:
F_155 ( V_408 ) ;
return V_3 ;
}
int
F_215 ( const unsigned int V_408 , struct V_7 * V_8 ,
const char * V_590 , struct V_9 * V_10 ,
const struct V_465 * V_466 )
{
struct V_484 * V_591 ;
struct V_484 * V_592 ;
T_8 * V_593 ;
T_9 * V_594 ;
unsigned char * V_595 ;
int V_3 = 0 ;
int V_78 ;
T_10 V_596 , V_597 ;
if ( V_8 == NULL )
return - V_598 ;
V_591 = F_26 () ;
if ( V_591 == NULL )
return - V_83 ;
V_592 = V_591 ;
F_216 ( V_591 , V_599 ,
NULL , 4 ) ;
V_591 -> V_600 = F_217 ( V_8 -> V_2 ) ;
V_591 -> V_601 = V_8 -> V_602 ;
V_593 = ( T_8 * ) V_591 ;
V_594 = ( T_9 * ) V_592 ;
V_593 -> V_603 = 0xFF ;
V_593 -> V_436 = F_218 ( V_604 ) ;
V_595 = & V_593 -> V_605 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_606 & V_607 ) ) {
V_593 -> V_608 = F_218 ( 1 ) ;
* V_595 = 0 ;
V_595 ++ ;
} else {
V_593 -> V_608 = F_218 ( V_609 ) ;
#ifdef F_84
if ( ( V_610 & V_611 ) &&
( V_8 -> V_150 == V_168 ) )
F_219 ( V_10 -> V_343 , V_8 -> V_2 -> V_612 ,
V_8 -> V_2 -> V_606 &
V_613 ? true : false ,
V_595 ) ;
else
#endif
V_3 = F_220 ( V_10 -> V_343 , V_8 -> V_2 -> V_612 ,
V_595 , V_466 ) ;
V_595 += V_609 ;
if ( V_8 -> V_614 & V_615 ) {
* V_595 = 0 ;
V_595 ++ ;
}
}
if ( V_8 -> V_2 -> V_152 )
V_591 -> V_616 |= V_617 ;
if ( V_8 -> V_614 & V_618 ) {
V_591 -> V_616 |= V_619 ;
}
if ( V_8 -> V_614 & V_620 ) {
V_591 -> V_616 |= V_621 ;
}
if ( V_8 -> V_614 & V_615 ) {
V_591 -> V_616 |= V_622 ;
V_78 =
F_221 ( ( V_623 * ) V_595 , V_590 ,
6 *
( + 256 ) , V_466 ) ;
V_595 += 2 * V_78 ;
V_595 += 2 ;
} else {
strcpy ( V_595 , V_590 ) ;
V_595 += strlen ( V_590 ) + 1 ;
}
strcpy ( V_595 , L_153 ) ;
V_595 += strlen ( L_153 ) ;
V_595 += 1 ;
V_597 = V_595 - & V_593 -> V_605 [ 0 ] ;
V_593 -> V_624 . V_495 = F_185 ( F_222 (
V_593 -> V_624 . V_495 ) + V_597 ) ;
V_593 -> V_625 = F_218 ( V_597 ) ;
V_3 = F_223 ( V_408 , V_8 , V_591 , V_592 , & V_78 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_626 ;
V_10 -> V_429 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_627 = V_592 -> V_628 ;
V_595 = F_224 ( V_592 ) ;
V_596 = F_225 ( V_592 ) ;
V_78 = F_93 ( V_595 , V_596 - 2 ) ;
if ( V_591 -> V_616 & V_622 )
V_626 = true ;
else
V_626 = false ;
if ( V_78 == 3 ) {
if ( ( V_595 [ 0 ] == 'I' ) && ( V_595 [ 1 ] == 'P' ) &&
( V_595 [ 2 ] == 'C' ) ) {
F_5 ( V_20 , L_154 ) ;
V_10 -> V_574 = 1 ;
}
} else if ( V_78 == 2 ) {
if ( ( V_595 [ 0 ] == 'A' ) && ( V_595 [ 1 ] == ':' ) ) {
F_5 ( V_20 , L_155 ) ;
}
}
V_595 += V_78 + 1 ;
V_596 -= ( V_78 + 1 ) ;
F_226 ( V_10 -> V_430 , V_590 , sizeof( V_10 -> V_430 ) ) ;
F_11 ( V_10 -> V_629 ) ;
V_10 -> V_629 = F_227 ( V_595 ,
V_596 , V_626 ,
V_466 ) ;
F_5 ( V_20 , L_156 , V_10 -> V_629 ) ;
if ( ( V_592 -> V_630 == 3 ) ||
( V_592 -> V_630 == 7 ) )
V_10 -> V_436 = F_228 ( V_594 -> V_631 ) ;
else
V_10 -> V_436 = 0 ;
F_5 ( V_20 , L_157 , V_10 -> V_436 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_592 -> V_628 ;
}
F_63 ( V_591 ) ;
return V_3 ;
}
static void F_229 ( struct V_632 * V_123 )
{
struct V_445 * V_633 = F_22 ( V_123 , struct V_445 , V_634 ) ;
F_230 ( V_633 -> V_426 ) ;
F_11 ( V_633 ) ;
}
void
F_231 ( struct V_445 * V_446 )
{
struct V_635 * V_636 = & V_446 -> V_532 ;
struct V_637 * V_638 ;
struct V_439 * V_440 ;
F_119 ( & V_446 -> V_529 ) ;
F_2 ( & V_446 -> V_531 ) ;
while ( ( V_638 = F_232 ( V_636 ) ) ) {
V_440 = F_233 ( V_638 , struct V_439 , V_639 ) ;
F_175 ( V_440 ) ;
F_234 ( V_442 , & V_440 -> V_443 ) ;
F_235 ( V_638 , V_636 ) ;
F_3 ( & V_446 -> V_531 ) ;
F_166 ( V_440 ) ;
F_2 ( & V_446 -> V_531 ) ;
}
F_3 ( & V_446 -> V_531 ) ;
F_210 ( & V_446 -> V_568 ) ;
F_11 ( V_446 -> V_198 ) ;
F_236 ( & V_446 -> V_634 , F_229 ) ;
}
int
F_154 ( const unsigned int V_408 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_49 -> V_50 || ! V_2 -> V_49 -> V_640 )
return - V_55 ;
if ( ! V_2 -> V_49 -> V_50 ( V_2 ) )
return 0 ;
F_237 ( V_2 , 1 ) ;
V_3 = V_2 -> V_49 -> V_640 ( V_408 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_641 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_156 ( const unsigned int V_408 , struct V_7 * V_8 ,
struct V_465 * V_642 )
{
int V_3 = - V_55 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_614 = V_2 -> V_614 ;
if ( V_643 == 0 )
V_8 -> V_614 &= ( ~ V_2 -> V_180 -> F_211 ) ;
F_5 ( V_20 , L_158 ,
V_2 -> V_606 , V_2 -> V_614 , V_2 -> V_644 ) ;
if ( V_2 -> V_49 -> V_645 )
V_3 = V_2 -> V_49 -> V_645 ( V_408 , V_8 , V_642 ) ;
if ( V_3 )
F_5 ( V_59 , L_159 , V_3 ) ;
return V_3 ;
}
static int
F_238 ( struct V_147 * V_148 , struct V_7 * V_8 )
{
V_148 -> V_150 = V_8 -> V_150 ;
if ( V_148 -> V_150 == V_157 )
return 0 ;
return F_146 ( V_148 , V_8 ) ;
}
static struct V_9 *
F_239 ( struct V_445 * V_446 , T_3 V_646 )
{
int V_3 ;
struct V_9 * V_647 = F_240 ( V_446 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_147 * V_510 ;
V_510 = F_99 ( sizeof( * V_510 ) , V_117 ) ;
if ( V_510 == NULL )
return F_71 ( - V_83 ) ;
V_510 -> V_426 = V_446 -> V_426 ;
V_510 -> V_221 = V_646 ;
V_510 -> V_220 = V_646 ;
V_510 -> V_196 = V_647 -> V_430 ;
V_510 -> V_252 = V_647 -> V_252 ;
V_510 -> V_272 = V_647 -> V_272 ;
V_510 -> V_306 = V_647 -> V_306 ;
V_510 -> V_270 = ! V_647 -> V_514 ;
V_510 -> V_150 = V_647 -> V_8 -> V_150 ;
V_510 -> V_152 = V_647 -> V_8 -> V_152 ;
V_3 = F_238 ( V_510 , V_647 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_71 ( V_3 ) ;
goto V_463;
}
F_2 ( & V_22 ) ;
++ V_647 -> V_8 -> V_2 -> V_387 ;
F_3 ( & V_22 ) ;
V_8 = F_153 ( V_647 -> V_8 -> V_2 , V_510 ) ;
if ( F_126 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_117 ( V_647 -> V_8 -> V_2 ) ;
goto V_463;
}
V_10 = F_163 ( V_8 , V_510 ) ;
if ( F_126 ( V_10 ) ) {
F_142 ( V_8 ) ;
goto V_463;
}
if ( F_211 ( V_8 ) )
F_189 ( 0 , V_10 , NULL , V_510 ) ;
V_463:
F_11 ( V_510 -> V_338 ) ;
F_11 ( V_510 -> V_343 ) ;
F_11 ( V_510 ) ;
return V_10 ;
}
struct V_9 *
F_240 ( struct V_445 * V_446 )
{
return F_169 ( F_170 ( V_446 ) ) ;
}
static struct V_439 *
F_241 ( struct V_635 * V_636 , T_3 V_145 )
{
struct V_637 * V_638 = V_636 -> V_637 ;
struct V_439 * V_440 ;
while ( V_638 ) {
V_440 = F_233 ( V_638 , struct V_439 , V_639 ) ;
if ( F_242 ( V_440 -> V_586 , V_145 ) )
V_638 = V_638 -> V_648 ;
else if ( F_243 ( V_440 -> V_586 , V_145 ) )
V_638 = V_638 -> V_649 ;
else
return V_440 ;
}
return NULL ;
}
static void
F_214 ( struct V_635 * V_636 , struct V_439 * V_650 )
{
struct V_637 * * V_65 = & ( V_636 -> V_637 ) , * V_651 = NULL ;
struct V_439 * V_440 ;
while ( * V_65 ) {
V_440 = F_233 ( * V_65 , struct V_439 , V_639 ) ;
V_651 = * V_65 ;
if ( F_242 ( V_440 -> V_586 , V_650 -> V_586 ) )
V_65 = & ( ( * V_65 ) -> V_648 ) ;
else
V_65 = & ( ( * V_65 ) -> V_649 ) ;
}
F_244 ( & V_650 -> V_639 , V_651 , V_65 ) ;
F_245 ( & V_650 -> V_639 , V_636 ) ;
}
struct V_439 *
F_246 ( struct V_445 * V_446 )
{
int V_652 ;
T_3 V_646 = F_247 () ;
struct V_439 * V_440 , * V_653 ;
if ( ! ( V_446 -> V_455 & V_554 ) )
return F_175 ( F_170 ( V_446 ) ) ;
F_2 ( & V_446 -> V_531 ) ;
V_440 = F_241 ( & V_446 -> V_532 , V_646 ) ;
if ( V_440 )
F_175 ( V_440 ) ;
F_3 ( & V_446 -> V_531 ) ;
if ( V_440 == NULL ) {
V_653 = F_99 ( sizeof( * V_440 ) , V_117 ) ;
if ( V_653 == NULL )
return F_71 ( - V_83 ) ;
V_653 -> V_586 = V_646 ;
V_653 -> V_587 = F_71 ( - V_573 ) ;
F_213 ( V_654 , & V_653 -> V_443 ) ;
F_213 ( V_442 , & V_653 -> V_443 ) ;
F_175 ( V_653 ) ;
F_2 ( & V_446 -> V_531 ) ;
V_440 = F_241 ( & V_446 -> V_532 , V_646 ) ;
if ( V_440 ) {
F_175 ( V_440 ) ;
F_3 ( & V_446 -> V_531 ) ;
F_11 ( V_653 ) ;
goto V_655;
}
V_440 = V_653 ;
F_214 ( & V_446 -> V_532 , V_440 ) ;
F_3 ( & V_446 -> V_531 ) ;
} else {
V_655:
V_652 = F_248 ( & V_440 -> V_443 , V_654 ,
V_135 ) ;
if ( V_652 ) {
F_166 ( V_440 ) ;
return F_71 ( - V_88 ) ;
}
if ( ! F_126 ( V_440 -> V_587 ) )
return V_440 ;
if ( F_23 ( V_38 , V_440 -> V_444 + V_656 ) ) {
F_166 ( V_440 ) ;
return F_71 ( - V_573 ) ;
}
if ( F_249 ( V_654 , & V_440 -> V_443 ) )
goto V_655;
}
V_440 -> V_587 = F_239 ( V_446 , V_646 ) ;
F_234 ( V_654 , & V_440 -> V_443 ) ;
F_250 ( & V_440 -> V_443 , V_654 ) ;
if ( F_126 ( V_440 -> V_587 ) ) {
F_166 ( V_440 ) ;
return F_71 ( - V_573 ) ;
}
return V_440 ;
}
static void
V_530 ( struct V_46 * V_47 )
{
struct V_445 * V_446 = F_22 ( V_47 , struct V_445 ,
V_529 . V_47 ) ;
struct V_635 * V_636 = & V_446 -> V_532 ;
struct V_637 * V_638 = F_232 ( V_636 ) ;
struct V_637 * V_5 ;
struct V_439 * V_440 ;
F_2 ( & V_446 -> V_531 ) ;
V_638 = F_232 ( V_636 ) ;
while ( V_638 != NULL ) {
V_5 = V_638 ;
V_638 = F_251 ( V_5 ) ;
V_440 = F_233 ( V_5 , struct V_439 , V_639 ) ;
if ( F_168 ( V_588 , & V_440 -> V_443 ) ||
F_60 ( & V_440 -> V_441 ) != 0 ||
F_30 ( V_440 -> V_444 + V_589 , V_38 ) )
continue;
F_175 ( V_440 ) ;
F_234 ( V_442 , & V_440 -> V_443 ) ;
F_235 ( V_5 , V_636 ) ;
F_3 ( & V_446 -> V_531 ) ;
F_166 ( V_440 ) ;
F_2 ( & V_446 -> V_531 ) ;
}
F_3 ( & V_446 -> V_531 ) ;
F_24 ( V_57 , & V_446 -> V_529 ,
V_589 ) ;
}
