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
V_147 -> V_49 = & V_185 ;
V_147 -> V_179 = & V_186 ;
break;
case V_187 :
V_147 -> V_49 = & V_188 ;
V_147 -> V_179 = & V_189 ;
break;
case V_190 :
V_147 -> V_49 = & V_188 ;
V_147 -> V_179 = & V_191 ;
break;
#endif
default:
F_5 ( V_59 , L_32 , V_143 ) ;
return 1 ;
}
return 0 ;
}
static int
F_87 ( const char * V_192 , struct V_146 * V_147 )
{
char * V_193 ;
const char * V_194 = L_33 ;
T_1 V_36 ;
V_36 = strspn ( V_192 , V_194 ) ;
if ( V_36 != 2 )
return - V_140 ;
V_193 = strpbrk ( V_192 + 2 , V_194 ) ;
if ( ! V_193 )
return - V_140 ;
++ V_193 ;
V_36 = strcspn ( V_193 , V_194 ) ;
V_193 += V_36 ;
V_147 -> V_195 = F_88 ( V_192 , V_193 - V_192 , V_116 ) ;
if ( ! V_147 -> V_195 )
return - V_83 ;
F_89 ( V_147 -> V_195 , '\\' ) ;
if ( ! * V_193 ++ || ! * V_193 )
return 0 ;
V_147 -> V_196 = F_90 ( V_193 , V_116 ) ;
if ( ! V_147 -> V_196 )
return - V_83 ;
return 0 ;
}
static int
F_91 ( const char * V_197 , const char * V_192 ,
struct V_146 * V_147 )
{
char * V_198 , * V_199 ;
char * V_200 = NULL , * V_201 ;
unsigned int V_202 , V_203 , V_204 ;
char V_205 [ 2 ] ;
short int V_206 = - 1 ;
short int V_207 = - 1 ;
bool V_208 = false ;
bool V_209 = false ;
bool V_210 = false ;
char * V_211 = NULL ;
char * V_212 = F_92 () -> V_212 ;
char * string = NULL ;
char * V_213 , * V_143 ;
char V_139 ;
bool V_214 = false ;
unsigned short V_215 = 0 ;
struct V_95 * V_96 = (struct V_95 * ) & V_147 -> V_96 ;
V_205 [ 0 ] = ',' ;
V_205 [ 1 ] = 0 ;
V_139 = V_205 [ 0 ] ;
memset ( V_147 , 0 , sizeof( * V_147 ) ) ;
memset ( V_147 -> V_216 , 0x20 , V_217 ) ;
for ( V_203 = 0 ; V_203 < F_93 ( V_212 , V_217 ) ; V_203 ++ )
V_147 -> V_216 [ V_203 ] = toupper ( V_212 [ V_203 ] ) ;
V_147 -> V_216 [ V_217 ] = 0 ;
V_147 -> V_218 [ 0 ] = 0 ;
V_147 -> V_219 = F_94 () ;
V_147 -> V_220 = F_94 () ;
V_147 -> V_221 = F_95 () ;
V_147 -> V_222 = V_147 -> V_223 = V_224 | V_225 | V_226 ;
V_147 -> V_227 = 1 ;
V_147 -> V_228 = 1 ;
V_147 -> V_173 = true ;
V_147 -> V_229 = V_230 ;
V_147 -> V_49 = & V_178 ;
V_147 -> V_179 = & V_180 ;
if ( ! V_197 )
goto V_231;
V_200 = F_88 ( V_197 , V_232 , V_116 ) ;
if ( ! V_200 )
goto V_231;
V_201 = V_200 ;
V_199 = V_201 + strlen ( V_201 ) ;
if ( strncmp ( V_201 , L_34 , 4 ) == 0 ) {
if ( V_201 [ 4 ] != 0 ) {
V_205 [ 0 ] = V_201 [ 4 ] ;
V_201 += 5 ;
} else {
F_5 ( V_20 , L_35 ) ;
}
}
V_147 -> V_233 = false ;
V_147 -> V_234 = false ;
switch ( F_87 ( V_192 , V_147 ) ) {
case 0 :
break;
case - V_83 :
F_5 ( V_59 , L_36 ) ;
goto V_231;
case - V_140 :
F_5 ( V_59 , L_37 ) ;
goto V_231;
default:
F_5 ( V_59 , L_38 ) ;
goto V_231;
}
while ( ( V_198 = F_96 ( & V_201 , V_205 ) ) != NULL ) {
T_2 args [ V_148 ] ;
unsigned long V_141 ;
int V_235 ;
if ( ! * V_198 )
continue;
V_235 = F_83 ( V_198 , V_236 , args ) ;
switch ( V_235 ) {
case V_237 :
break;
case V_238 :
V_147 -> V_239 = 0 ;
break;
case V_240 :
V_147 -> V_239 = 1 ;
break;
case V_241 :
V_206 = 1 ;
break;
case V_242 :
V_206 = 0 ;
break;
case V_243 :
V_207 = 1 ;
break;
case V_244 :
V_207 = 0 ;
break;
case V_245 :
V_147 -> V_246 = 1 ;
break;
case V_247 :
V_147 -> V_248 = 1 ;
break;
case V_249 :
V_147 -> V_250 = 1 ;
break;
case V_251 :
V_147 -> V_250 = 0 ;
break;
case V_252 :
V_147 -> V_253 = 0 ;
break;
case V_254 :
V_147 -> V_253 = 1 ;
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
V_147 -> V_259 = 0 ;
break;
case V_261 :
V_147 -> V_262 = 1 ;
break;
case V_263 :
V_147 -> V_227 = 1 ;
break;
case V_264 :
V_147 -> V_227 = 0 ;
break;
case V_265 :
V_147 -> V_266 = 1 ;
break;
case V_267 :
V_147 -> V_268 = 1 ;
break;
case V_269 :
V_147 -> V_270 = 0 ;
break;
case V_271 :
V_147 -> V_270 = 1 ;
if ( V_147 -> V_223 ==
( V_272 & ~ ( V_273 | V_274 ) ) )
V_147 -> V_223 = V_272 ;
break;
case V_275 :
V_147 -> V_276 = 1 ;
break;
case V_277 :
V_147 -> V_278 = 1 ;
break;
case V_279 :
V_147 -> V_278 = 0 ;
break;
case V_280 :
V_147 -> V_281 = true ;
break;
case V_282 :
V_147 -> V_281 = false ;
break;
case V_283 :
V_147 -> V_250 = 0 ;
break;
case V_284 :
V_147 -> V_250 = 1 ;
break;
case V_285 :
V_147 -> V_286 = 0 ;
break;
case V_287 :
V_147 -> V_286 = 1 ;
break;
case V_288 :
V_147 -> V_289 = 1 ;
break;
case V_290 :
V_147 -> V_289 = 0 ;
break;
case V_291 :
V_147 -> V_228 = 1 ;
break;
case V_292 :
V_147 -> V_228 = 0 ;
break;
case V_293 :
V_147 -> V_294 = 1 ;
break;
case V_295 :
V_147 -> V_296 = 1 ;
break;
case V_297 :
V_147 -> V_296 = 0 ;
break;
case V_298 :
V_147 -> V_299 = 0 ;
break;
case V_300 :
V_147 -> V_299 = 1 ;
break;
case V_301 :
V_147 -> V_302 = 1 ;
break;
case V_303 :
V_147 -> V_151 = true ;
break;
case V_304 :
V_147 -> V_305 = 1 ;
break;
case V_306 :
F_97 ( V_307 L_39
L_40
L_41 ) ;
break;
case V_308 :
#ifndef F_98
F_5 ( V_59 , L_42 ) ;
goto V_231;
#endif
V_147 -> V_309 = true ;
break;
case V_310 :
V_147 -> V_311 = true ;
break;
case V_312 :
V_147 -> V_313 = true ;
break;
case V_314 :
V_210 = true ;
break;
case V_315 :
V_147 -> V_316 = true ;
break;
case V_317 :
if ( F_75 ( args , & V_147 -> V_318 ) ) {
F_5 ( V_59 , L_43 ,
V_21 ) ;
goto V_231;
}
V_147 -> V_233 = true ;
break;
case V_319 :
if ( F_79 ( args , & V_147 -> V_320 ) ) {
F_5 ( V_59 , L_44 ,
V_21 ) ;
goto V_231;
}
V_147 -> V_234 = true ;
break;
case V_321 :
if ( F_75 ( args , & V_147 -> V_220 ) ) {
F_5 ( V_59 , L_45 ,
V_21 ) ;
goto V_231;
}
V_208 = true ;
break;
case V_322 :
if ( F_75 ( args , & V_147 -> V_219 ) ) {
F_5 ( V_59 , L_46 ,
V_21 ) ;
goto V_231;
}
break;
case V_323 :
if ( F_79 ( args , & V_147 -> V_221 ) ) {
F_5 ( V_59 , L_47 ,
V_21 ) ;
goto V_231;
}
V_209 = true ;
break;
case V_324 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_48 ,
V_21 ) ;
goto V_231;
}
V_147 -> V_223 = V_141 ;
break;
case V_325 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_49 ,
V_21 ) ;
goto V_231;
}
V_147 -> V_222 = V_141 ;
break;
case V_326 :
if ( F_72 ( args , & V_141 ) ||
V_141 > V_327 ) {
F_5 ( V_59 , L_50 ,
V_21 ) ;
goto V_231;
}
V_215 = ( unsigned short ) V_141 ;
break;
case V_328 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_51 ,
V_21 ) ;
goto V_231;
}
V_147 -> V_329 = V_141 ;
break;
case V_330 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_52 ,
V_21 ) ;
goto V_231;
}
V_147 -> V_331 = V_141 ;
break;
case V_332 :
if ( F_72 ( args , & V_141 ) ) {
F_5 ( V_59 , L_53 ,
V_21 ) ;
goto V_231;
}
V_147 -> V_229 = V_53 * V_141 ;
if ( V_147 -> V_229 > V_333 ) {
F_5 ( V_59 , L_54 ) ;
goto V_231;
}
break;
case V_334 :
V_147 -> V_169 = 1 ;
V_147 -> V_335 = NULL ;
break;
case V_336 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_337;
if ( F_93 ( string , V_338 ) >
V_338 ) {
F_97 ( V_307 L_55 ) ;
goto V_231;
}
V_147 -> V_335 = F_90 ( string , V_116 ) ;
if ( ! V_147 -> V_335 )
goto V_231;
break;
case V_339 :
V_213 = strchr ( V_198 , '=' ) ;
V_213 ++ ;
if ( ! ( V_213 < V_199 && V_213 [ 1 ] == V_139 ) ) {
V_147 -> V_340 = NULL ;
break;
}
case V_341 :
V_143 = strchr ( V_198 , '=' ) ;
V_143 ++ ;
V_213 = ( char * ) V_143 + strlen ( V_143 ) ;
if ( V_213 < V_199 && V_213 [ 1 ] == V_139 ) {
V_213 [ 0 ] = V_139 ;
while ( ( V_213 = strchr ( V_213 , V_139 ) )
!= NULL && ( V_213 [ 1 ] == V_139 ) ) {
V_213 = ( char * ) & V_213 [ 2 ] ;
}
if ( V_213 ) {
V_213 [ 0 ] = '\0' ;
V_201 = ( char * ) & V_213 [ 1 ] ;
} else
V_201 = V_199 ;
}
V_202 = strlen ( V_143 ) ;
V_147 -> V_340 = F_99 ( V_202 + 1 , V_116 ) ;
if ( V_147 -> V_340 == NULL ) {
F_97 ( V_307 L_56
L_57 ) ;
goto V_231;
}
for ( V_203 = 0 , V_204 = 0 ; V_203 < V_202 ; V_203 ++ , V_204 ++ ) {
V_147 -> V_340 [ V_204 ] = V_143 [ V_203 ] ;
if ( ( V_143 [ V_203 ] == V_139 ) &&
V_143 [ V_203 + 1 ] == V_139 )
V_203 ++ ;
}
V_147 -> V_340 [ V_204 ] = '\0' ;
break;
case V_342 :
V_214 = false ;
break;
case V_343 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_337;
if ( ! F_100 ( V_96 , string ,
strlen ( string ) ) ) {
F_97 ( V_344 L_58 ,
string ) ;
goto V_231;
}
V_214 = true ;
break;
case V_345 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_337;
if ( F_93 ( string , V_346 )
== V_346 ) {
F_97 ( V_307 L_59
L_60 ) ;
goto V_231;
}
V_147 -> V_347 = F_90 ( string , V_116 ) ;
if ( ! V_147 -> V_347 ) {
F_97 ( V_307 L_56
L_61 ) ;
goto V_231;
}
F_5 ( V_20 , L_62 ) ;
break;
case V_348 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_337;
if ( ! F_100 (
(struct V_95 * ) & V_147 -> V_349 ,
string , strlen ( string ) ) ) {
F_97 ( V_307 L_63
L_64 , string ) ;
goto V_231;
}
break;
case V_350 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_337;
if ( F_93 ( string , 1024 ) >= 65 ) {
F_97 ( V_307 L_65
L_66 ) ;
goto V_231;
}
if ( F_101 ( string , L_67 , 7 ) != 0 ) {
V_147 -> V_351 = F_90 ( string ,
V_116 ) ;
if ( ! V_147 -> V_351 ) {
F_97 ( V_307 L_68
L_69 ) ;
goto V_231;
}
}
F_5 ( V_20 , L_70 , string ) ;
break;
case V_352 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_337;
memset ( V_147 -> V_216 , 0x20 ,
V_217 ) ;
for ( V_203 = 0 ; V_203 < V_217 ; V_203 ++ ) {
if ( string [ V_203 ] == 0 )
break;
V_147 -> V_216 [ V_203 ] = string [ V_203 ] ;
}
if ( V_203 == V_217 && string [ V_203 ] != 0 )
F_97 ( V_307 L_71
L_72 ) ;
break;
case V_353 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_337;
memset ( V_147 -> V_218 , 0x20 ,
V_354 ) ;
for ( V_203 = 0 ; V_203 < 15 ; V_203 ++ ) {
if ( string [ V_203 ] == 0 )
break;
V_147 -> V_218 [ V_203 ] = string [ V_203 ] ;
}
if ( V_203 == V_217 && string [ V_203 ] != 0 )
F_97 ( V_307 L_73
L_74 ) ;
break;
case V_355 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_337;
if ( F_101 ( string , L_75 , 1 ) == 0 ) {
break;
}
F_97 ( V_307 L_76
L_77 ) ;
goto V_231;
case V_356 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_337;
if ( F_86 ( string , V_147 ) != 0 )
goto V_231;
break;
case V_357 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_337;
if ( F_82 ( string , V_147 ) != 0 )
goto V_231;
break;
case V_358 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_337;
if ( F_85 ( string , V_147 ) != 0 )
goto V_231;
break;
default:
if ( ! V_211 )
V_211 = V_198 ;
break;
}
F_11 ( string ) ;
string = NULL ;
}
if ( ! V_210 && V_211 ) {
F_97 ( V_344 L_78 , V_211 ) ;
goto V_231;
}
#ifndef F_102
if ( V_147 -> V_313 ) {
F_5 ( V_59 , L_79 ) ;
goto V_231;
}
#endif
if ( ! V_147 -> V_195 ) {
F_5 ( V_59 , L_80 ) ;
goto V_231;
}
if ( ! strchr ( V_147 -> V_195 + 3 , '\\' ) ) {
F_5 ( V_59 , L_81 ) ;
goto V_231;
}
if ( ! V_214 ) {
if ( ! F_100 ( V_96 , & V_147 -> V_195 [ 2 ] ,
strlen ( & V_147 -> V_195 [ 2 ] ) ) ) {
F_97 ( V_344 L_82
L_83 ) ;
goto V_231;
}
}
F_41 ( V_96 , V_215 ) ;
if ( V_208 )
V_147 -> V_206 = V_206 ;
else if ( V_206 == 1 )
F_97 ( V_359 L_84
L_85 ) ;
if ( V_209 )
V_147 -> V_207 = V_207 ;
else if ( V_207 == 1 )
F_97 ( V_359 L_86
L_87 ) ;
F_11 ( V_200 ) ;
return 0 ;
V_337:
F_97 ( V_307 L_88 ) ;
V_231:
F_11 ( string ) ;
F_11 ( V_200 ) ;
return 1 ;
}
static bool
F_103 ( struct V_95 * V_349 , struct V_95 * V_360 )
{
switch ( V_349 -> V_361 ) {
case V_362 :
return ( V_360 -> V_361 == V_362 ) ;
case V_363 : {
struct V_364 * V_365 = (struct V_364 * ) V_349 ;
struct V_364 * V_366 = (struct V_364 * ) V_360 ;
return ( V_365 -> V_367 . V_368 == V_366 -> V_367 . V_368 ) ;
}
case V_369 : {
struct V_370 * V_371 = (struct V_370 * ) V_349 ;
struct V_370 * V_372 = (struct V_370 * ) V_360 ;
return F_104 ( & V_371 -> V_373 , & V_372 -> V_373 ) ;
}
default:
F_105 ( 1 ) ;
return false ;
}
}
static bool
F_106 ( struct V_1 * V_2 , struct V_95 * V_374 )
{
T_5 V_215 , * V_375 ;
switch ( V_374 -> V_361 ) {
case V_363 :
V_375 = & ( (struct V_364 * ) & V_2 -> V_96 ) -> V_376 ;
V_215 = ( (struct V_364 * ) V_374 ) -> V_376 ;
break;
case V_369 :
V_375 = & ( (struct V_370 * ) & V_2 -> V_96 ) -> V_377 ;
V_215 = ( (struct V_370 * ) V_374 ) -> V_377 ;
break;
default:
F_105 ( 1 ) ;
return false ;
}
if ( ! V_215 ) {
V_215 = F_107 ( V_97 ) ;
if ( V_215 == * V_375 )
return true ;
V_215 = F_107 ( V_378 ) ;
}
return V_215 == * V_375 ;
}
static bool
F_108 ( struct V_1 * V_2 , struct V_95 * V_374 ,
struct V_95 * V_349 )
{
switch ( V_374 -> V_361 ) {
case V_363 : {
struct V_364 * V_379 = (struct V_364 * ) V_374 ;
struct V_364 * V_380 =
(struct V_364 * ) & V_2 -> V_96 ;
if ( V_379 -> V_367 . V_368 != V_380 -> V_367 . V_368 )
return false ;
break;
}
case V_369 : {
struct V_370 * V_381 = (struct V_370 * ) V_374 ;
struct V_370 * V_382 =
(struct V_370 * ) & V_2 -> V_96 ;
if ( ! F_104 ( & V_381 -> V_373 ,
& V_382 -> V_373 ) )
return false ;
if ( V_381 -> V_383 != V_382 -> V_383 )
return false ;
break;
}
default:
F_105 ( 1 ) ;
return false ;
}
if ( ! F_103 ( V_349 , (struct V_95 * ) & V_2 -> V_349 ) )
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
struct V_95 * V_374 = (struct V_95 * ) & V_147 -> V_96 ;
if ( V_147 -> V_316 )
return 0 ;
if ( ( V_2 -> V_179 != V_147 -> V_179 ) || ( V_2 -> V_49 != V_147 -> V_49 ) )
return 0 ;
if ( ! F_112 ( F_113 ( V_2 ) , V_125 -> V_384 -> V_385 ) )
return 0 ;
if ( ! F_108 ( V_2 , V_374 ,
(struct V_95 * ) & V_147 -> V_349 ) )
return 0 ;
if ( ! F_106 ( V_2 , V_374 ) )
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
++ V_2 -> V_386 ;
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
struct V_123 * V_387 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_386 > 0 ) {
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
V_387 = F_65 ( & V_2 -> V_133 , NULL ) ;
if ( V_387 )
F_121 ( V_388 , V_387 ) ;
}
static struct V_1 *
F_122 ( struct V_146 * V_389 )
{
struct V_1 * V_390 = NULL ;
int V_3 ;
F_5 ( V_20 , L_90 , V_389 -> V_195 ) ;
V_390 = F_114 ( V_389 ) ;
if ( V_390 )
return V_390 ;
V_390 = F_99 ( sizeof( struct V_1 ) , V_116 ) ;
if ( ! V_390 ) {
V_3 = - V_83 ;
goto V_391;
}
V_390 -> V_49 = V_389 -> V_49 ;
V_390 -> V_179 = V_389 -> V_179 ;
F_123 ( V_390 , F_124 ( V_125 -> V_384 -> V_385 ) ) ;
V_390 -> V_56 = F_70 ( V_389 -> V_195 ) ;
if ( F_125 ( V_390 -> V_56 ) ) {
V_3 = F_126 ( V_390 -> V_56 ) ;
goto V_392;
}
V_390 -> V_246 = V_389 -> V_246 ;
V_390 -> V_248 = V_389 -> V_248 ;
V_390 -> V_393 = V_389 -> V_394 ;
V_390 -> V_395 = 0 ;
V_390 -> V_108 = 1 ;
F_127 ( & V_390 -> V_63 ) ;
F_127 ( & V_390 -> V_109 ) ;
F_13 ( & V_390 -> V_110 ) ;
F_128 ( & V_390 -> V_27 ) ;
memcpy ( V_390 -> V_396 ,
V_389 -> V_216 , V_354 ) ;
memcpy ( V_390 -> V_397 ,
V_389 -> V_218 , V_354 ) ;
V_390 -> V_33 = false ;
V_390 -> V_32 = 0 ;
V_390 -> V_37 = V_38 ;
F_129 ( & V_390 -> V_107 ) ;
F_13 ( & V_390 -> V_106 ) ;
F_13 ( & V_390 -> V_23 ) ;
F_130 ( & V_390 -> V_48 , F_21 ) ;
memcpy ( & V_390 -> V_349 , & V_389 -> V_349 ,
sizeof( V_390 -> V_349 ) ) ;
memcpy ( & V_390 -> V_96 , & V_389 -> V_96 ,
sizeof( V_390 -> V_96 ) ) ;
#ifdef F_4
F_131 ( V_390 -> V_398 , V_399 ) ;
#endif
V_390 -> V_15 = V_400 ;
++ V_390 -> V_386 ;
V_3 = F_132 ( V_390 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_91 ) ;
goto V_392;
}
F_133 ( V_401 ) ;
V_390 -> V_133 = F_134 ( F_56 ,
V_390 , L_92 ) ;
if ( F_125 ( V_390 -> V_133 ) ) {
V_3 = F_126 ( V_390 -> V_133 ) ;
F_5 ( V_59 , L_93 , V_3 ) ;
F_135 ( V_401 ) ;
goto V_392;
}
V_390 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_136 ( & V_390 -> V_106 , & V_402 ) ;
F_3 ( & V_22 ) ;
F_137 ( V_390 ) ;
F_24 ( V_57 , & V_390 -> V_48 , V_52 ) ;
return V_390 ;
V_392:
F_119 ( V_390 ) ;
F_117 ( F_113 ( V_390 ) ) ;
V_391:
if ( V_390 ) {
if ( ! F_125 ( V_390 -> V_56 ) )
F_11 ( V_390 -> V_56 ) ;
if ( V_390 -> V_28 )
F_10 ( V_390 -> V_28 ) ;
F_11 ( V_390 ) ;
}
return F_71 ( V_3 ) ;
}
static int F_138 ( struct V_7 * V_8 , struct V_146 * V_147 )
{
if ( V_147 -> V_149 != V_150 &&
V_147 -> V_149 != V_8 -> V_149 )
return 0 ;
switch ( V_8 -> V_149 ) {
case V_156 :
if ( ! F_139 ( V_147 -> V_219 , V_8 -> V_219 ) )
return 0 ;
break;
default:
if ( V_8 -> V_403 == NULL ) {
if ( ! V_147 -> V_169 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_403 ,
V_147 -> V_335 ? V_147 -> V_335 : L_94 ,
V_338 ) )
return 0 ;
if ( ( V_147 -> V_335 && strlen ( V_147 -> V_335 ) != 0 ) &&
V_8 -> V_340 != NULL &&
strncmp ( V_8 -> V_340 ,
V_147 -> V_340 ? V_147 -> V_340 : L_94 ,
V_404 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_140 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_7 * V_8 ;
F_2 ( & V_22 ) ;
F_115 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_8 -> V_405 == V_16 )
continue;
if ( ! F_138 ( V_8 , V_147 ) )
continue;
++ V_8 -> V_406 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_141 ( struct V_7 * V_8 )
{
unsigned int V_3 , V_407 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_20 , L_95 , V_21 , V_8 -> V_406 ) ;
F_2 ( & V_22 ) ;
if ( V_8 -> V_405 == V_16 ) {
F_3 ( & V_22 ) ;
return;
}
if ( -- V_8 -> V_406 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
if ( V_8 -> V_405 == V_62 )
V_8 -> V_405 = V_16 ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_405 == V_16 && V_2 -> V_49 -> V_408 ) {
V_407 = F_142 () ;
V_3 = V_2 -> V_49 -> V_408 ( V_407 , V_8 ) ;
if ( V_3 )
F_5 ( V_59 , L_96 ,
V_21 , V_3 ) ;
F_143 ( V_407 ) ;
}
F_2 ( & V_22 ) ;
F_16 ( & V_8 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_144 ( V_8 ) ;
F_116 ( V_2 ) ;
}
static int
F_145 ( struct V_146 * V_147 , struct V_7 * V_8 )
{
int V_3 = 0 ;
char * V_409 , * V_139 , * V_410 ;
T_6 V_36 ;
struct V_411 * V_411 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_364 * V_412 ;
struct V_370 * V_413 ;
struct V_414 * V_415 ;
V_409 = F_35 ( V_416 , V_116 ) ;
if ( ! V_409 )
return - V_83 ;
switch ( V_2 -> V_96 . V_417 ) {
case V_363 :
V_412 = (struct V_364 * ) & V_2 -> V_96 ;
sprintf ( V_409 , L_97 , & V_412 -> V_367 . V_368 ) ;
break;
case V_369 :
V_413 = (struct V_370 * ) & V_2 -> V_96 ;
sprintf ( V_409 , L_98 , & V_413 -> V_373 . V_418 ) ;
break;
default:
F_5 ( V_20 , L_99 ,
V_2 -> V_96 . V_417 ) ;
V_3 = - V_140 ;
goto V_391;
}
F_5 ( V_20 , L_100 , V_21 , V_409 ) ;
V_411 = F_146 ( & V_419 , V_409 , L_94 ) ;
if ( F_125 ( V_411 ) ) {
if ( ! V_8 -> V_420 ) {
F_5 ( V_20 , L_101 ) ;
V_3 = F_126 ( V_411 ) ;
goto V_391;
}
sprintf ( V_409 , L_102 , V_8 -> V_420 ) ;
F_5 ( V_20 , L_100 , V_21 , V_409 ) ;
V_411 = F_146 ( & V_419 , V_409 , L_94 ) ;
if ( F_125 ( V_411 ) ) {
V_3 = F_126 ( V_411 ) ;
goto V_391;
}
}
F_147 ( & V_411 -> V_421 ) ;
V_415 = V_411 -> V_410 . V_198 ;
if ( F_148 ( V_415 ) ) {
V_3 = V_415 ? F_126 ( V_415 ) : - V_140 ;
goto V_422;
}
V_410 = ( char * ) V_415 -> V_198 ;
V_139 = F_149 ( V_410 , V_415 -> V_423 , ':' ) ;
F_5 ( V_20 , L_103 , V_410 ) ;
if ( ! V_139 ) {
F_5 ( V_20 , L_104 ,
V_415 -> V_423 ) ;
V_3 = - V_140 ;
goto V_422;
}
V_36 = V_139 - V_410 ;
if ( V_36 > V_338 || V_36 <= 0 ) {
F_5 ( V_20 , L_105 ,
V_36 ) ;
V_3 = - V_140 ;
goto V_422;
}
V_147 -> V_335 = F_88 ( V_410 , V_36 , V_116 ) ;
if ( ! V_147 -> V_335 ) {
F_5 ( V_20 , L_106 ,
V_36 ) ;
V_3 = - V_83 ;
goto V_422;
}
F_5 ( V_20 , L_107 , V_21 , V_147 -> V_335 ) ;
V_36 = V_411 -> V_423 - ( V_36 + 1 ) ;
if ( V_36 > V_404 || V_36 <= 0 ) {
F_5 ( V_20 , L_108 , V_36 ) ;
V_3 = - V_140 ;
F_11 ( V_147 -> V_335 ) ;
V_147 -> V_335 = NULL ;
goto V_422;
}
++ V_139 ;
V_147 -> V_340 = F_88 ( V_139 , V_36 , V_116 ) ;
if ( ! V_147 -> V_340 ) {
F_5 ( V_20 , L_109 ,
V_36 ) ;
V_3 = - V_83 ;
F_11 ( V_147 -> V_335 ) ;
V_147 -> V_335 = NULL ;
goto V_422;
}
V_422:
F_150 ( & V_411 -> V_421 ) ;
F_151 ( V_411 ) ;
V_391:
F_11 ( V_409 ) ;
F_5 ( V_20 , L_110 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_152 ( struct V_1 * V_2 , struct V_146 * V_389 )
{
int V_3 = - V_83 ;
unsigned int V_407 ;
struct V_7 * V_8 ;
struct V_364 * V_374 = (struct V_364 * ) & V_2 -> V_96 ;
struct V_370 * V_381 = (struct V_370 * ) & V_2 -> V_96 ;
V_407 = F_142 () ;
V_8 = F_140 ( V_2 , V_389 ) ;
if ( V_8 ) {
F_5 ( V_20 , L_111 ,
V_8 -> V_405 ) ;
F_8 ( & V_8 -> V_424 ) ;
V_3 = F_153 ( V_407 , V_8 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_424 ) ;
F_141 ( V_8 ) ;
F_154 ( V_407 ) ;
return F_71 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_5 ( V_20 , L_112 ) ;
V_3 = F_155 ( V_407 , V_8 ,
V_389 -> V_425 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_424 ) ;
F_141 ( V_8 ) ;
F_154 ( V_407 ) ;
return F_71 ( V_3 ) ;
}
}
F_12 ( & V_8 -> V_424 ) ;
F_116 ( V_2 ) ;
F_154 ( V_407 ) ;
return V_8 ;
}
F_5 ( V_20 , L_113 ) ;
V_8 = F_156 () ;
if ( V_8 == NULL )
goto V_426;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_96 . V_417 == V_369 )
sprintf ( V_8 -> V_427 , L_114 , & V_381 -> V_373 ) ;
else
sprintf ( V_8 -> V_427 , L_115 , & V_374 -> V_367 ) ;
if ( V_389 -> V_335 ) {
V_8 -> V_403 = F_90 ( V_389 -> V_335 , V_116 ) ;
if ( ! V_8 -> V_403 )
goto V_426;
}
if ( V_389 -> V_340 ) {
V_8 -> V_340 = F_90 ( V_389 -> V_340 , V_116 ) ;
if ( ! V_8 -> V_340 )
goto V_426;
}
if ( V_389 -> V_347 ) {
V_8 -> V_420 = F_90 ( V_389 -> V_347 , V_116 ) ;
if ( ! V_8 -> V_420 )
goto V_426;
}
V_8 -> V_219 = V_389 -> V_219 ;
V_8 -> V_220 = V_389 -> V_220 ;
V_8 -> V_149 = V_389 -> V_149 ;
V_8 -> V_151 = V_389 -> V_151 ;
F_8 ( & V_8 -> V_424 ) ;
V_3 = F_153 ( V_407 , V_8 ) ;
if ( ! V_3 )
V_3 = F_155 ( V_407 , V_8 , V_389 -> V_425 ) ;
F_12 ( & V_8 -> V_424 ) ;
if ( V_3 )
goto V_426;
F_2 ( & V_22 ) ;
F_136 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_154 ( V_407 ) ;
return V_8 ;
V_426:
F_144 ( V_8 ) ;
F_154 ( V_407 ) ;
return F_71 ( V_3 ) ;
}
static int F_157 ( struct V_9 * V_10 , const char * V_136 )
{
if ( V_10 -> V_428 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_429 , V_136 , V_430 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_158 ( struct V_7 * V_8 , const char * V_136 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_22 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_26 ) ;
if ( ! F_157 ( V_10 , V_136 ) )
continue;
++ V_10 -> V_431 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_159 ( struct V_9 * V_10 )
{
unsigned int V_407 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( V_20 , L_116 , V_21 , V_10 -> V_431 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_431 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_407 = F_142 () ;
if ( V_8 -> V_2 -> V_49 -> V_432 )
V_8 -> V_2 -> V_49 -> V_432 ( V_407 , V_10 ) ;
F_143 ( V_407 ) ;
F_160 ( V_10 ) ;
F_161 ( V_10 ) ;
F_141 ( V_8 ) ;
}
static struct V_9 *
F_162 ( struct V_7 * V_8 , struct V_146 * V_389 )
{
int V_3 , V_407 ;
struct V_9 * V_10 ;
V_10 = F_158 ( V_8 , V_389 -> V_195 ) ;
if ( V_10 ) {
F_5 ( V_20 , L_117 ) ;
F_141 ( V_8 ) ;
if ( V_10 -> V_305 != V_389 -> V_305 )
F_5 ( V_59 , L_118 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_49 -> V_433 ) {
V_3 = - V_55 ;
goto V_434;
}
V_10 = F_163 () ;
if ( V_10 == NULL ) {
V_3 = - V_83 ;
goto V_434;
}
V_10 -> V_8 = V_8 ;
if ( V_389 -> V_340 ) {
V_10 -> V_340 = F_90 ( V_389 -> V_340 , V_116 ) ;
if ( ! V_10 -> V_340 ) {
V_3 = - V_83 ;
goto V_434;
}
}
V_407 = F_142 () ;
V_3 = V_8 -> V_2 -> V_49 -> V_433 ( V_407 , V_8 , V_389 -> V_195 , V_10 ,
V_389 -> V_425 ) ;
F_154 ( V_407 ) ;
F_5 ( V_20 , L_119 , V_3 ) ;
if ( V_3 )
goto V_434;
if ( V_389 -> V_262 ) {
V_10 -> V_435 &= ~ V_436 ;
F_5 ( V_20 , L_120 , V_10 -> V_435 ) ;
}
V_10 -> V_305 = V_389 -> V_305 ;
V_10 -> V_250 = V_389 -> V_250 ;
V_10 -> V_268 = V_389 -> V_268 ;
V_10 -> V_302 = V_389 -> V_302 ;
F_13 ( & V_10 -> V_437 ) ;
F_2 ( & V_22 ) ;
F_136 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_164 ( V_10 ) ;
return V_10 ;
V_434:
F_161 ( V_10 ) ;
return F_71 ( V_3 ) ;
}
void
F_165 ( struct V_438 * V_439 )
{
if ( ! V_439 || F_125 ( V_439 ) )
return;
if ( ! F_166 ( & V_439 -> V_440 ) ||
F_167 ( V_441 , & V_439 -> V_442 ) ) {
V_439 -> V_443 = V_38 ;
return;
}
if ( ! F_125 ( F_168 ( V_439 ) ) )
F_159 ( F_168 ( V_439 ) ) ;
F_11 ( V_439 ) ;
return;
}
static inline struct V_438 *
F_169 ( struct V_444 * V_445 )
{
return V_445 -> V_446 ;
}
static int
F_170 ( struct V_447 * V_448 , struct V_449 * V_450 )
{
struct V_444 * V_451 = F_171 ( V_448 ) ;
struct V_444 * V_65 = V_450 -> V_445 ;
if ( ( V_448 -> V_452 & V_453 ) != ( V_450 -> V_30 & V_453 ) )
return 0 ;
if ( ( V_451 -> V_454 & V_455 ) !=
( V_65 -> V_454 & V_455 ) )
return 0 ;
if ( V_65 -> V_331 && V_65 -> V_331 < V_451 -> V_331 )
return 0 ;
if ( V_65 -> V_329 && V_65 -> V_329 < V_451 -> V_329 )
return 0 ;
if ( ! F_139 ( V_451 -> V_456 , V_65 -> V_456 ) || ! F_172 ( V_451 -> V_457 , V_65 -> V_457 ) )
return 0 ;
if ( V_451 -> V_458 != V_65 -> V_458 ||
V_451 -> V_459 != V_65 -> V_459 )
return 0 ;
if ( strcmp ( V_451 -> V_425 -> V_460 , V_65 -> V_425 -> V_460 ) )
return 0 ;
if ( V_451 -> V_229 != V_65 -> V_229 )
return 0 ;
return 1 ;
}
int
F_173 ( struct V_447 * V_448 , void * V_198 )
{
struct V_449 * V_450 = (struct V_449 * ) V_198 ;
struct V_146 * V_389 ;
struct V_444 * V_445 ;
struct V_1 * V_461 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_438 * V_439 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_445 = F_171 ( V_448 ) ;
V_439 = F_174 ( F_169 ( V_445 ) ) ;
if ( F_125 ( V_439 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_168 ( V_439 ) ;
V_8 = V_10 -> V_8 ;
V_461 = V_8 -> V_2 ;
V_389 = V_450 -> V_147 ;
if ( ! F_111 ( V_461 , V_389 ) ||
! F_138 ( V_8 , V_389 ) ||
! F_157 ( V_10 , V_389 -> V_195 ) ) {
V_3 = 0 ;
goto V_462;
}
V_3 = F_170 ( V_448 , V_450 ) ;
V_462:
F_3 ( & V_22 ) ;
F_165 ( V_439 ) ;
return V_3 ;
}
int
F_175 ( const unsigned int V_407 , struct V_7 * V_8 , const char * V_463 ,
const struct V_464 * V_465 , unsigned int * V_466 ,
struct V_467 * * V_468 , int V_256 )
{
char * V_469 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_49 -> V_433 || ! V_8 -> V_2 -> V_49 -> V_470 )
return - V_55 ;
* V_466 = 0 ;
* V_468 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_469 = F_35 ( 2 +
F_93 ( V_8 -> V_427 , V_471 * 2 )
+ 1 + 4 + 2 , V_116 ) ;
if ( V_469 == NULL )
return - V_83 ;
V_469 [ 0 ] = '\\' ;
V_469 [ 1 ] = '\\' ;
strcpy ( V_469 + 2 , V_8 -> V_427 ) ;
strcpy ( V_469 + 2 + strlen ( V_8 -> V_427 ) , L_121 ) ;
V_3 = V_8 -> V_2 -> V_49 -> V_433 ( V_407 , V_8 , V_469 , NULL ,
V_465 ) ;
F_5 ( V_20 , L_122 , V_3 , V_8 -> V_25 ) ;
F_11 ( V_469 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_49 -> V_470 ( V_407 , V_8 , V_463 ,
V_468 , V_466 ,
V_465 , V_256 ) ;
return V_3 ;
}
static inline void
F_176 ( struct V_472 * V_473 )
{
struct V_473 * V_474 = V_473 -> V_474 ;
F_177 ( F_178 ( V_474 ) ) ;
F_179 ( V_474 , L_123 ,
& V_475 [ 0 ] , L_124 , & V_476 [ 0 ] ) ;
}
static inline void
F_180 ( struct V_472 * V_473 )
{
struct V_473 * V_474 = V_473 -> V_474 ;
F_177 ( F_178 ( V_474 ) ) ;
F_179 ( V_474 , L_125 ,
& V_475 [ 1 ] , L_126 , & V_476 [ 1 ] ) ;
}
static inline void
F_176 ( struct V_472 * V_473 )
{
}
static inline void
F_180 ( struct V_472 * V_473 )
{
}
static void F_181 ( char * V_477 , char * V_478 , unsigned int V_78 )
{
unsigned int V_203 , V_204 ;
for ( V_203 = 0 , V_204 = 0 ; V_203 < ( V_78 ) ; V_203 ++ ) {
V_477 [ V_204 ] = 'A' + ( 0x0F & ( V_478 [ V_203 ] >> 4 ) ) ;
V_477 [ V_204 + 1 ] = 'A' + ( 0x0F & V_478 [ V_203 ] ) ;
V_204 += 2 ;
}
}
static int
F_182 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_349 . V_417 != V_362 ) {
struct V_472 * V_472 = V_2 -> V_28 ;
V_3 = V_472 -> V_49 -> V_479 ( V_472 ,
(struct V_95 * ) & V_2 -> V_349 ,
sizeof( V_2 -> V_349 ) ) ;
if ( V_3 < 0 ) {
struct V_364 * V_365 ;
struct V_370 * V_371 ;
V_365 = (struct V_364 * ) & V_2 -> V_349 ;
V_371 = (struct V_370 * ) & V_2 -> V_349 ;
if ( V_371 -> V_480 == V_369 )
F_5 ( V_59 , L_127 ,
& V_371 -> V_373 , V_3 ) ;
else
F_5 ( V_59 , L_128 ,
& V_365 -> V_367 . V_368 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_183 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_481 * V_482 ;
struct V_483 * V_484 ;
V_482 = F_99 ( sizeof( struct V_481 ) ,
V_116 ) ;
if ( V_482 ) {
V_482 -> V_485 . V_486 . V_487 = 32 ;
if ( V_2 -> V_397 &&
V_2 -> V_397 [ 0 ] != 0 )
F_181 ( V_482 -> V_485 .
V_486 . V_488 ,
V_2 -> V_397 ,
V_354 ) ;
else
F_181 ( V_482 -> V_485 .
V_486 . V_488 ,
V_489 ,
V_354 ) ;
V_482 -> V_485 . V_486 . V_490 = 32 ;
if ( V_2 -> V_396 &&
V_2 -> V_396 [ 0 ] != 0 )
F_181 ( V_482 -> V_485 .
V_486 . V_491 ,
V_2 -> V_396 ,
V_354 ) ;
else
F_181 ( V_482 -> V_485 .
V_486 . V_491 ,
L_129 ,
V_354 ) ;
V_482 -> V_485 . V_486 . V_492 = 0 ;
V_482 -> V_485 . V_486 . V_493 = 0 ;
V_484 = (struct V_483 * ) V_482 ;
V_484 -> V_494 = F_184 ( 0x81000044 ) ;
V_3 = F_185 ( V_2 , V_484 , 0x44 ) ;
F_11 ( V_482 ) ;
F_38 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_375 ;
int V_495 , V_496 ;
struct V_472 * V_472 = V_2 -> V_28 ;
struct V_95 * V_497 ;
V_497 = (struct V_95 * ) & V_2 -> V_96 ;
if ( V_2 -> V_96 . V_417 == V_369 ) {
V_375 = ( (struct V_370 * ) V_497 ) -> V_377 ;
V_495 = sizeof( struct V_370 ) ;
V_496 = V_369 ;
} else {
V_375 = ( (struct V_364 * ) V_497 ) -> V_376 ;
V_495 = sizeof( struct V_364 ) ;
V_496 = V_363 ;
}
if ( V_472 == NULL ) {
V_3 = F_186 ( F_113 ( V_2 ) , V_496 , V_498 ,
V_499 , & V_472 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_130 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_5 ( V_20 , L_131 ) ;
V_2 -> V_28 = V_472 ;
V_472 -> V_474 -> V_500 = V_75 ;
if ( V_496 == V_369 )
F_180 ( V_472 ) ;
else
F_176 ( V_472 ) ;
}
V_3 = F_182 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_472 -> V_474 -> V_501 = 7 * V_53 ;
V_472 -> V_474 -> V_502 = 5 * V_53 ;
if ( V_2 -> V_248 ) {
if ( V_472 -> V_474 -> V_503 < ( 200 * 1024 ) )
V_472 -> V_474 -> V_503 = 200 * 1024 ;
if ( V_472 -> V_474 -> V_504 < ( 140 * 1024 ) )
V_472 -> V_474 -> V_504 = 140 * 1024 ;
}
if ( V_2 -> V_393 ) {
int V_505 = 1 ;
V_3 = F_187 ( V_472 , V_506 , V_507 ,
( char * ) & V_505 , sizeof( V_505 ) ) ;
if ( V_3 )
F_5 ( V_20 , L_132 ,
V_3 ) ;
}
F_5 ( V_20 , L_133 ,
V_472 -> V_474 -> V_503 ,
V_472 -> V_474 -> V_504 , V_472 -> V_474 -> V_501 ) ;
V_3 = V_472 -> V_49 -> V_508 ( V_472 , V_497 , V_495 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_20 , L_134 , V_3 ) ;
F_10 ( V_472 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_375 == F_107 ( V_378 ) )
V_3 = F_183 ( V_2 ) ;
return V_3 ;
}
static int
F_132 ( struct V_1 * V_2 )
{
T_5 * V_375 ;
struct V_370 * V_381 = (struct V_370 * ) & V_2 -> V_96 ;
struct V_364 * V_374 = (struct V_364 * ) & V_2 -> V_96 ;
if ( V_2 -> V_96 . V_417 == V_369 )
V_375 = & V_381 -> V_377 ;
else
V_375 = & V_374 -> V_376 ;
if ( * V_375 == 0 ) {
int V_3 ;
* V_375 = F_107 ( V_97 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_375 = F_107 ( V_378 ) ;
}
return F_18 ( V_2 ) ;
}
void F_188 ( unsigned int V_407 , struct V_9 * V_10 ,
struct V_444 * V_445 , struct V_146 * V_509 )
{
T_7 V_510 = F_189 ( V_10 -> V_511 . V_512 ) ;
if ( V_509 && V_509 -> V_266 ) {
V_10 -> V_511 . V_512 = 0 ;
V_10 -> V_513 = 0 ;
F_5 ( V_20 , L_135 ) ;
return;
} else if ( V_509 )
V_10 -> V_513 = 1 ;
if ( V_10 -> V_513 == 0 ) {
F_5 ( V_20 , L_136 ) ;
return;
}
if ( ! F_190 ( V_407 , V_10 ) ) {
T_7 V_514 = F_189 ( V_10 -> V_511 . V_512 ) ;
F_5 ( V_20 , L_137 , V_514 ) ;
if ( V_509 == NULL ) {
if ( ( V_510 & V_515 ) == 0 )
V_514 &= ~ V_515 ;
if ( ( V_510 & V_516 ) == 0 ) {
if ( V_514 & V_516 )
F_5 ( V_59 , L_138 ) ;
V_514 &= ~ V_516 ;
} else if ( ( V_514 & V_516 ) == 0 ) {
F_5 ( V_59 , L_139 ) ;
F_5 ( V_59 , L_140 ) ;
}
}
if ( V_514 & V_517 )
F_5 ( V_59 , L_141 ) ;
V_514 &= V_518 ;
if ( V_509 && V_509 -> V_299 )
V_514 &= ~ V_515 ;
else if ( V_515 & V_514 ) {
F_5 ( V_20 , L_142 ) ;
if ( V_445 )
V_445 -> V_454 |=
V_519 ;
}
if ( V_509 && V_509 -> V_227 == 0 )
V_514 &= ~ V_516 ;
else if ( V_514 & V_516 ) {
F_5 ( V_20 , L_143 ) ;
if ( V_445 )
V_445 -> V_454 |=
V_520 ;
}
F_5 ( V_20 , L_144 , ( int ) V_514 ) ;
#ifdef F_61
if ( V_514 & V_521 )
F_5 ( V_20 , L_145 ) ;
if ( V_514 & V_522 )
F_5 ( V_20 , L_146 ) ;
if ( V_514 & V_516 )
F_5 ( V_20 , L_147 ) ;
if ( V_514 & V_523 )
F_5 ( V_20 , L_148 ) ;
if ( V_514 & V_515 )
F_5 ( V_20 , L_149 ) ;
if ( V_514 & V_524 )
F_5 ( V_20 , L_150 ) ;
if ( V_514 & V_525 )
F_5 ( V_20 , L_151 ) ;
if ( V_514 & V_526 )
F_5 ( V_20 , L_152 ) ;
if ( V_514 & V_517 )
F_5 ( V_20 , L_153 ) ;
#endif
if ( F_191 ( V_407 , V_10 , V_514 ) ) {
if ( V_509 == NULL ) {
F_5 ( V_20 , L_154 ) ;
} else
F_5 ( V_59 , L_155 ) ;
}
}
}
void F_192 ( struct V_146 * V_527 ,
struct V_444 * V_445 )
{
F_130 ( & V_445 -> V_528 , V_529 ) ;
F_129 ( & V_445 -> V_530 ) ;
V_445 -> V_531 = V_532 ;
V_445 -> V_329 = V_527 -> V_329 ;
V_445 -> V_331 = V_527 -> V_331 ;
V_445 -> V_456 = V_527 -> V_220 ;
V_445 -> V_457 = V_527 -> V_221 ;
V_445 -> V_458 = V_527 -> V_223 ;
V_445 -> V_459 = V_527 -> V_222 ;
F_5 ( V_20 , L_156 ,
V_445 -> V_458 , V_445 -> V_459 ) ;
V_445 -> V_229 = V_527 -> V_229 ;
V_445 -> V_425 = V_527 -> V_425 ;
if ( V_527 -> V_253 )
V_445 -> V_454 |= V_533 ;
if ( V_527 -> V_278 )
V_445 -> V_454 |= V_534 ;
if ( V_527 -> V_228 )
V_445 -> V_454 |= V_535 ;
if ( V_527 -> V_256 )
V_445 -> V_454 |= V_536 ;
if ( V_527 -> V_239 )
V_445 -> V_454 |= V_537 ;
if ( V_527 -> V_259 )
V_445 -> V_454 |= V_538 ;
if ( V_527 -> V_270 )
V_445 -> V_454 |= V_539 ;
if ( V_527 -> V_289 )
V_445 -> V_454 |= V_540 ;
if ( V_527 -> V_276 )
V_445 -> V_454 |= V_541 ;
if ( V_527 -> V_294 )
V_445 -> V_454 |= V_542 ;
if ( V_527 -> V_296 )
V_445 -> V_454 |= V_543 ;
if ( V_527 -> V_233 ) {
V_445 -> V_454 |= V_544 ;
V_445 -> V_545 = V_527 -> V_318 ;
}
if ( V_527 -> V_234 ) {
V_445 -> V_454 |= V_546 ;
V_445 -> V_547 = V_527 -> V_320 ;
}
if ( V_527 -> V_206 )
V_445 -> V_454 |= V_548 ;
if ( V_527 -> V_207 )
V_445 -> V_454 |= V_549 ;
if ( V_527 -> V_281 )
V_445 -> V_454 |= V_550 ;
if ( V_527 -> V_309 )
V_445 -> V_454 |= V_551 ;
if ( V_527 -> V_313 )
V_445 -> V_454 |= ( V_552 |
V_533 ) ;
if ( V_527 -> V_173 )
V_445 -> V_454 |= V_553 ;
if ( V_527 -> V_172 ) {
F_5 ( V_20 , L_157 ) ;
V_445 -> V_454 |= V_554 ;
}
if ( V_527 -> V_311 ) {
if ( V_527 -> V_259 ) {
F_5 ( V_59 , L_158 ) ;
} else {
V_445 -> V_454 |= V_555 ;
}
}
if ( ( V_527 -> V_296 ) && ( V_527 -> V_281 ) )
F_5 ( V_59 , L_159 ) ;
}
static void
F_193 ( struct V_146 * V_389 )
{
F_11 ( V_389 -> V_335 ) ;
F_194 ( V_389 -> V_340 ) ;
F_11 ( V_389 -> V_195 ) ;
F_11 ( V_389 -> V_347 ) ;
F_11 ( V_389 -> V_351 ) ;
F_11 ( V_389 -> V_196 ) ;
}
void
F_195 ( struct V_146 * V_389 )
{
if ( ! V_389 )
return;
F_193 ( V_389 ) ;
F_11 ( V_389 ) ;
}
static char *
F_196 ( const struct V_146 * V_147 ,
const struct V_444 * V_445 )
{
char * V_556 , * V_193 ;
unsigned int V_557 = V_147 -> V_196 ? strlen ( V_147 -> V_196 ) + 1 : 0 ;
unsigned int V_558 = F_93 ( V_147 -> V_195 , V_430 + 1 ) ;
V_556 = F_35 ( V_558 + V_557 + 1 , V_116 ) ;
if ( V_556 == NULL )
return F_71 ( - V_83 ) ;
strncpy ( V_556 , V_147 -> V_195 , V_558 ) ;
V_193 = V_556 + V_558 ;
if ( V_557 ) {
* V_193 = F_197 ( V_445 ) ;
strncpy ( V_193 + 1 , V_147 -> V_196 , V_557 ) ;
V_193 += V_557 ;
}
* V_193 = '\0' ;
F_89 ( V_556 , F_197 ( V_445 ) ) ;
F_5 ( V_20 , L_160 , V_21 , V_556 ) ;
return V_556 ;
}
static int
F_198 ( const unsigned int V_407 , struct V_7 * V_8 ,
struct V_146 * V_389 , struct V_444 * V_445 ,
int V_559 )
{
int V_3 ;
unsigned int V_466 = 0 ;
struct V_467 * V_468 = NULL ;
char * V_556 = NULL , * V_560 = NULL , * V_561 = NULL ;
V_556 = F_196 ( V_389 , V_445 ) ;
if ( F_125 ( V_556 ) )
return F_126 ( V_556 ) ;
V_560 = V_559 ? V_556 + 1 : V_389 -> V_195 + 1 ;
V_3 = F_175 ( V_407 , V_8 , V_560 , V_445 -> V_425 ,
& V_466 , & V_468 ,
V_445 -> V_454 & V_536 ) ;
if ( ! V_3 && V_466 > 0 ) {
char * V_562 = NULL ;
V_561 = F_199 ( V_445 -> V_197 ,
V_556 + 1 , V_468 ,
& V_562 ) ;
F_200 ( V_468 , V_466 ) ;
if ( F_125 ( V_561 ) ) {
V_3 = F_126 ( V_561 ) ;
V_561 = NULL ;
} else {
F_193 ( V_389 ) ;
V_3 = F_201 ( V_389 , V_561 ,
V_562 ) ;
}
F_11 ( V_562 ) ;
F_11 ( V_445 -> V_197 ) ;
V_445 -> V_197 = V_561 ;
}
F_11 ( V_556 ) ;
return V_3 ;
}
static int
F_201 ( struct V_146 * V_389 , char * V_563 ,
const char * V_192 )
{
int V_3 = 0 ;
if ( F_91 ( V_563 , V_192 , V_389 ) )
return - V_140 ;
if ( V_389 -> V_169 ) {
F_5 ( V_20 , L_161 ) ;
F_11 ( V_389 -> V_335 ) ;
V_389 -> V_335 = NULL ;
} else if ( V_389 -> V_335 ) {
F_5 ( V_20 , L_162 , V_389 -> V_335 ) ;
} else {
F_5 ( V_59 , L_163 ) ;
return - V_140 ;
}
if ( V_389 -> V_351 == NULL ) {
V_389 -> V_425 = F_202 () ;
} else {
V_389 -> V_425 = F_203 ( V_389 -> V_351 ) ;
if ( V_389 -> V_425 == NULL ) {
F_5 ( V_59 , L_164 ,
V_389 -> V_351 ) ;
return - V_564 ;
}
}
return V_3 ;
}
struct V_146 *
F_204 ( char * V_563 , const char * V_192 )
{
int V_3 ;
struct V_146 * V_389 ;
V_389 = F_35 ( sizeof( struct V_146 ) , V_116 ) ;
if ( ! V_389 )
return F_71 ( - V_83 ) ;
V_3 = F_201 ( V_389 , V_563 , V_192 ) ;
if ( V_3 ) {
F_195 ( V_389 ) ;
V_389 = F_71 ( V_3 ) ;
}
return V_389 ;
}
int
F_205 ( struct V_444 * V_445 , struct V_146 * V_389 )
{
int V_3 ;
unsigned int V_407 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_556 ;
struct V_438 * V_439 ;
#ifdef F_206
int V_565 = 0 ;
#endif
V_3 = F_207 ( & V_445 -> V_566 , L_165 , V_567 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_206
V_568:
if ( V_565 ) {
if ( V_10 )
F_159 ( V_10 ) ;
else if ( V_8 )
F_141 ( V_8 ) ;
F_154 ( V_407 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_556 = NULL ;
V_439 = NULL ;
V_407 = F_142 () ;
V_2 = F_122 ( V_389 ) ;
if ( F_125 ( V_2 ) ) {
V_3 = F_126 ( V_2 ) ;
F_208 ( & V_445 -> V_566 ) ;
goto V_462;
}
V_8 = F_152 ( V_2 , V_389 ) ;
if ( F_125 ( V_8 ) ) {
V_3 = F_126 ( V_8 ) ;
V_8 = NULL ;
goto V_569;
}
V_10 = F_162 ( V_8 , V_389 ) ;
if ( F_125 ( V_10 ) ) {
V_3 = F_126 ( V_10 ) ;
V_10 = NULL ;
goto V_570;
}
if ( F_209 ( V_10 -> V_8 ) ) {
F_188 ( V_407 , V_10 , V_445 , V_389 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_189 ( V_10 -> V_511 . V_512 ) &
V_517 ) ) {
V_3 = - V_571 ;
goto V_569;
}
} else
V_10 -> V_513 = 0 ;
if ( ! V_10 -> V_572 && V_2 -> V_49 -> V_573 )
V_2 -> V_49 -> V_573 ( V_407 , V_10 ) ;
V_445 -> V_331 = V_2 -> V_49 -> V_574 ( V_10 , V_389 ) ;
V_445 -> V_329 = V_2 -> V_49 -> V_575 ( V_10 , V_389 ) ;
V_445 -> V_566 . V_576 = V_445 -> V_329 / V_577 ;
V_570:
#ifdef F_206
if ( V_565 == 0 ) {
int V_578 = F_198 ( V_407 , V_8 , V_389 , V_445 ,
false ) ;
if ( ! V_578 ) {
V_565 ++ ;
goto V_568;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_49 -> V_579 ) {
V_3 = - V_55 ;
goto V_569;
}
V_556 = F_210 ( V_389 , V_445 , V_10 ) ;
if ( V_556 == NULL ) {
V_3 = - V_83 ;
goto V_569;
}
V_3 = V_2 -> V_49 -> V_579 ( V_407 , V_10 , V_445 ,
V_556 ) ;
if ( V_3 != 0 && V_3 != - V_580 ) {
F_11 ( V_556 ) ;
goto V_569;
}
F_11 ( V_556 ) ;
}
if ( V_3 == - V_580 ) {
#ifdef F_206
if ( V_565 > V_581 ) {
V_3 = - V_582 ;
goto V_569;
}
V_3 = F_198 ( V_407 , V_8 , V_389 , V_445 , true ) ;
if ( ! V_3 ) {
V_565 ++ ;
goto V_568;
}
goto V_569;
#else
V_3 = - V_583 ;
#endif
}
if ( V_3 )
goto V_569;
V_439 = F_99 ( sizeof *V_439 , V_116 ) ;
if ( V_439 == NULL ) {
V_3 = - V_83 ;
goto V_569;
}
V_439 -> V_584 = V_8 -> V_220 ;
V_439 -> V_585 = V_10 ;
V_439 -> V_443 = V_38 ;
F_211 ( V_586 , & V_439 -> V_442 ) ;
F_211 ( V_441 , & V_439 -> V_442 ) ;
V_445 -> V_446 = V_439 ;
F_2 ( & V_445 -> V_530 ) ;
F_212 ( & V_445 -> V_531 , V_439 ) ;
F_3 ( & V_445 -> V_530 ) ;
F_24 ( V_57 , & V_445 -> V_528 ,
V_587 ) ;
V_569:
if ( V_3 ) {
if ( V_10 )
F_159 ( V_10 ) ;
else if ( V_8 )
F_141 ( V_8 ) ;
else
F_116 ( V_2 ) ;
F_208 ( & V_445 -> V_566 ) ;
}
V_462:
F_154 ( V_407 ) ;
return V_3 ;
}
int
F_213 ( const unsigned int V_407 , struct V_7 * V_8 ,
const char * V_588 , struct V_9 * V_10 ,
const struct V_464 * V_465 )
{
struct V_483 * V_589 ;
struct V_483 * V_590 ;
T_8 * V_591 ;
T_9 * V_592 ;
unsigned char * V_593 ;
int V_3 = 0 ;
int V_78 ;
T_10 V_594 , V_595 ;
if ( V_8 == NULL )
return - V_596 ;
V_589 = F_26 () ;
if ( V_589 == NULL )
return - V_83 ;
V_590 = V_589 ;
F_214 ( V_589 , V_597 ,
NULL , 4 ) ;
V_589 -> V_598 = F_215 ( V_8 -> V_2 ) ;
V_589 -> V_599 = V_8 -> V_600 ;
V_591 = ( T_8 * ) V_589 ;
V_592 = ( T_9 * ) V_590 ;
V_591 -> V_601 = 0xFF ;
V_591 -> V_435 = F_216 ( V_602 ) ;
V_593 = & V_591 -> V_603 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_604 & V_605 ) ) {
V_591 -> V_606 = F_216 ( 1 ) ;
* V_593 = 0 ;
V_593 ++ ;
} else {
V_591 -> V_606 = F_216 ( V_607 ) ;
#ifdef F_84
if ( ( V_608 & V_609 ) &&
( V_8 -> V_149 == V_167 ) )
F_217 ( V_10 -> V_340 , V_8 -> V_2 -> V_610 ,
V_8 -> V_2 -> V_604 &
V_611 ? true : false ,
V_593 ) ;
else
#endif
V_3 = F_218 ( V_10 -> V_340 , V_8 -> V_2 -> V_610 ,
V_593 , V_465 ) ;
V_593 += V_607 ;
if ( V_8 -> V_612 & V_613 ) {
* V_593 = 0 ;
V_593 ++ ;
}
}
if ( V_8 -> V_2 -> V_151 )
V_589 -> V_614 |= V_615 ;
if ( V_8 -> V_612 & V_616 ) {
V_589 -> V_614 |= V_617 ;
}
if ( V_8 -> V_612 & V_618 ) {
V_589 -> V_614 |= V_619 ;
}
if ( V_8 -> V_612 & V_613 ) {
V_589 -> V_614 |= V_620 ;
V_78 =
F_219 ( ( V_621 * ) V_593 , V_588 ,
6 *
( + 256 ) , V_465 ) ;
V_593 += 2 * V_78 ;
V_593 += 2 ;
} else {
strcpy ( V_593 , V_588 ) ;
V_593 += strlen ( V_588 ) + 1 ;
}
strcpy ( V_593 , L_166 ) ;
V_593 += strlen ( L_166 ) ;
V_593 += 1 ;
V_595 = V_593 - & V_591 -> V_603 [ 0 ] ;
V_591 -> V_622 . V_494 = F_184 ( F_220 (
V_591 -> V_622 . V_494 ) + V_595 ) ;
V_591 -> V_623 = F_216 ( V_595 ) ;
V_3 = F_221 ( V_407 , V_8 , V_589 , V_590 , & V_78 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_624 ;
V_10 -> V_428 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_625 = V_590 -> V_626 ;
V_593 = F_222 ( V_590 ) ;
V_594 = F_223 ( V_590 ) ;
V_78 = F_93 ( V_593 , V_594 - 2 ) ;
if ( V_589 -> V_614 & V_620 )
V_624 = true ;
else
V_624 = false ;
if ( V_78 == 3 ) {
if ( ( V_593 [ 0 ] == 'I' ) && ( V_593 [ 1 ] == 'P' ) &&
( V_593 [ 2 ] == 'C' ) ) {
F_5 ( V_20 , L_167 ) ;
V_10 -> V_572 = 1 ;
}
} else if ( V_78 == 2 ) {
if ( ( V_593 [ 0 ] == 'A' ) && ( V_593 [ 1 ] == ':' ) ) {
F_5 ( V_20 , L_168 ) ;
}
}
V_593 += V_78 + 1 ;
V_594 -= ( V_78 + 1 ) ;
F_224 ( V_10 -> V_429 , V_588 , sizeof( V_10 -> V_429 ) ) ;
F_11 ( V_10 -> V_627 ) ;
V_10 -> V_627 = F_225 ( V_593 ,
V_594 , V_624 ,
V_465 ) ;
F_5 ( V_20 , L_169 , V_10 -> V_627 ) ;
if ( ( V_590 -> V_628 == 3 ) ||
( V_590 -> V_628 == 7 ) )
V_10 -> V_435 = F_226 ( V_592 -> V_629 ) ;
else
V_10 -> V_435 = 0 ;
F_5 ( V_20 , L_170 , V_10 -> V_435 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_590 -> V_626 ;
}
F_63 ( V_589 ) ;
return V_3 ;
}
static void F_227 ( struct V_630 * V_122 )
{
struct V_444 * V_631 = F_22 ( V_122 , struct V_444 , V_632 ) ;
F_228 ( V_631 -> V_425 ) ;
F_11 ( V_631 ) ;
}
void
F_229 ( struct V_444 * V_445 )
{
struct V_633 * V_634 = & V_445 -> V_531 ;
struct V_635 * V_636 ;
struct V_438 * V_439 ;
F_118 ( & V_445 -> V_528 ) ;
F_2 ( & V_445 -> V_530 ) ;
while ( ( V_636 = F_230 ( V_634 ) ) ) {
V_439 = F_231 ( V_636 , struct V_438 , V_637 ) ;
F_174 ( V_439 ) ;
F_232 ( V_441 , & V_439 -> V_442 ) ;
F_233 ( V_636 , V_634 ) ;
F_3 ( & V_445 -> V_530 ) ;
F_165 ( V_439 ) ;
F_2 ( & V_445 -> V_530 ) ;
}
F_3 ( & V_445 -> V_530 ) ;
F_208 ( & V_445 -> V_566 ) ;
F_11 ( V_445 -> V_197 ) ;
F_234 ( & V_445 -> V_632 , F_227 ) ;
}
int
F_153 ( const unsigned int V_407 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_49 -> V_50 || ! V_2 -> V_49 -> V_638 )
return - V_55 ;
if ( ! V_2 -> V_49 -> V_50 ( V_2 ) )
return 0 ;
F_235 ( V_2 , 1 ) ;
V_3 = V_2 -> V_49 -> V_638 ( V_407 , V_8 ) ;
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
F_155 ( const unsigned int V_407 , struct V_7 * V_8 ,
struct V_464 * V_640 )
{
int V_3 = - V_55 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_612 = V_2 -> V_612 ;
if ( V_641 == 0 )
V_8 -> V_612 &= ( ~ V_2 -> V_179 -> F_209 ) ;
F_5 ( V_20 , L_171 ,
V_2 -> V_604 , V_2 -> V_612 , V_2 -> V_642 ) ;
if ( V_2 -> V_49 -> V_643 )
V_3 = V_2 -> V_49 -> V_643 ( V_407 , V_8 , V_640 ) ;
if ( V_3 )
F_5 ( V_59 , L_172 , V_3 ) ;
return V_3 ;
}
static int
F_236 ( struct V_146 * V_147 , struct V_7 * V_8 )
{
V_147 -> V_149 = V_8 -> V_149 ;
if ( V_147 -> V_149 == V_156 )
return 0 ;
return F_145 ( V_147 , V_8 ) ;
}
static struct V_9 *
F_237 ( struct V_444 * V_445 , T_3 V_644 )
{
int V_3 ;
struct V_9 * V_645 = F_238 ( V_445 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_146 * V_509 ;
V_509 = F_99 ( sizeof( * V_509 ) , V_116 ) ;
if ( V_509 == NULL )
return F_71 ( - V_83 ) ;
V_509 -> V_425 = V_445 -> V_425 ;
V_509 -> V_220 = V_644 ;
V_509 -> V_219 = V_644 ;
V_509 -> V_195 = V_645 -> V_429 ;
V_509 -> V_250 = V_645 -> V_250 ;
V_509 -> V_268 = V_645 -> V_268 ;
V_509 -> V_302 = V_645 -> V_302 ;
V_509 -> V_266 = ! V_645 -> V_513 ;
V_509 -> V_149 = V_645 -> V_8 -> V_149 ;
V_509 -> V_151 = V_645 -> V_8 -> V_151 ;
V_3 = F_236 ( V_509 , V_645 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_71 ( V_3 ) ;
goto V_462;
}
F_2 ( & V_22 ) ;
++ V_645 -> V_8 -> V_2 -> V_386 ;
F_3 ( & V_22 ) ;
V_8 = F_152 ( V_645 -> V_8 -> V_2 , V_509 ) ;
if ( F_125 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_116 ( V_645 -> V_8 -> V_2 ) ;
goto V_462;
}
V_10 = F_162 ( V_8 , V_509 ) ;
if ( F_125 ( V_10 ) ) {
F_141 ( V_8 ) ;
goto V_462;
}
if ( F_209 ( V_8 ) )
F_188 ( 0 , V_10 , NULL , V_509 ) ;
V_462:
F_11 ( V_509 -> V_335 ) ;
F_11 ( V_509 -> V_340 ) ;
F_11 ( V_509 ) ;
return V_10 ;
}
struct V_9 *
F_238 ( struct V_444 * V_445 )
{
return F_168 ( F_169 ( V_445 ) ) ;
}
static int
F_239 ( void * V_646 )
{
F_68 () ;
return F_67 ( V_125 ) ? - V_88 : 0 ;
}
static struct V_438 *
F_240 ( struct V_633 * V_634 , T_3 V_144 )
{
struct V_635 * V_636 = V_634 -> V_635 ;
struct V_438 * V_439 ;
while ( V_636 ) {
V_439 = F_231 ( V_636 , struct V_438 , V_637 ) ;
if ( F_241 ( V_439 -> V_584 , V_144 ) )
V_636 = V_636 -> V_647 ;
else if ( F_242 ( V_439 -> V_584 , V_144 ) )
V_636 = V_636 -> V_648 ;
else
return V_439 ;
}
return NULL ;
}
static void
F_212 ( struct V_633 * V_634 , struct V_438 * V_649 )
{
struct V_635 * * V_65 = & ( V_634 -> V_635 ) , * V_650 = NULL ;
struct V_438 * V_439 ;
while ( * V_65 ) {
V_439 = F_231 ( * V_65 , struct V_438 , V_637 ) ;
V_650 = * V_65 ;
if ( F_241 ( V_439 -> V_584 , V_649 -> V_584 ) )
V_65 = & ( ( * V_65 ) -> V_647 ) ;
else
V_65 = & ( ( * V_65 ) -> V_648 ) ;
}
F_243 ( & V_649 -> V_637 , V_650 , V_65 ) ;
F_244 ( & V_649 -> V_637 , V_634 ) ;
}
struct V_438 *
F_245 ( struct V_444 * V_445 )
{
int V_651 ;
T_3 V_644 = F_246 () ;
struct V_438 * V_439 , * V_652 ;
if ( ! ( V_445 -> V_454 & V_552 ) )
return F_174 ( F_169 ( V_445 ) ) ;
F_2 ( & V_445 -> V_530 ) ;
V_439 = F_240 ( & V_445 -> V_531 , V_644 ) ;
if ( V_439 )
F_174 ( V_439 ) ;
F_3 ( & V_445 -> V_530 ) ;
if ( V_439 == NULL ) {
V_652 = F_99 ( sizeof( * V_439 ) , V_116 ) ;
if ( V_652 == NULL )
return F_71 ( - V_83 ) ;
V_652 -> V_584 = V_644 ;
V_652 -> V_585 = F_71 ( - V_571 ) ;
F_211 ( V_653 , & V_652 -> V_442 ) ;
F_211 ( V_441 , & V_652 -> V_442 ) ;
F_174 ( V_652 ) ;
F_2 ( & V_445 -> V_530 ) ;
V_439 = F_240 ( & V_445 -> V_531 , V_644 ) ;
if ( V_439 ) {
F_174 ( V_439 ) ;
F_3 ( & V_445 -> V_530 ) ;
F_11 ( V_652 ) ;
goto V_654;
}
V_439 = V_652 ;
F_212 ( & V_445 -> V_531 , V_439 ) ;
F_3 ( & V_445 -> V_530 ) ;
} else {
V_654:
V_651 = F_247 ( & V_439 -> V_442 , V_653 ,
F_239 ,
V_134 ) ;
if ( V_651 ) {
F_165 ( V_439 ) ;
return F_71 ( V_651 ) ;
}
if ( ! F_125 ( V_439 -> V_585 ) )
return V_439 ;
if ( F_23 ( V_38 , V_439 -> V_443 + V_655 ) ) {
F_165 ( V_439 ) ;
return F_71 ( - V_571 ) ;
}
if ( F_248 ( V_653 , & V_439 -> V_442 ) )
goto V_654;
}
V_439 -> V_585 = F_237 ( V_445 , V_644 ) ;
F_232 ( V_653 , & V_439 -> V_442 ) ;
F_249 ( & V_439 -> V_442 , V_653 ) ;
if ( F_125 ( V_439 -> V_585 ) ) {
F_165 ( V_439 ) ;
return F_71 ( - V_571 ) ;
}
return V_439 ;
}
static void
V_529 ( struct V_46 * V_47 )
{
struct V_444 * V_445 = F_22 ( V_47 , struct V_444 ,
V_528 . V_47 ) ;
struct V_633 * V_634 = & V_445 -> V_531 ;
struct V_635 * V_636 = F_230 ( V_634 ) ;
struct V_635 * V_5 ;
struct V_438 * V_439 ;
F_2 ( & V_445 -> V_530 ) ;
V_636 = F_230 ( V_634 ) ;
while ( V_636 != NULL ) {
V_5 = V_636 ;
V_636 = F_250 ( V_5 ) ;
V_439 = F_231 ( V_5 , struct V_438 , V_637 ) ;
if ( F_167 ( V_586 , & V_439 -> V_442 ) ||
F_60 ( & V_439 -> V_440 ) != 0 ||
F_30 ( V_439 -> V_443 + V_587 , V_38 ) )
continue;
F_174 ( V_439 ) ;
F_232 ( V_441 , & V_439 -> V_442 ) ;
F_233 ( V_5 , V_634 ) ;
F_3 ( & V_445 -> V_530 ) ;
F_165 ( V_439 ) ;
F_2 ( & V_445 -> V_530 ) ;
}
F_3 ( & V_445 -> V_530 ) ;
F_24 ( V_57 , & V_445 -> V_528 ,
V_587 ) ;
}
