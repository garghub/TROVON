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
F_12 ( & V_2 -> V_27 ) ;
F_19 ( 3000 ) ;
} else {
F_20 ( & V_44 ) ;
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 != V_16 )
V_2 -> V_15 = V_45 ;
F_3 ( & V_14 ) ;
F_12 ( & V_2 -> V_27 ) ;
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
F_49 ( V_115 , V_78 + V_116 ) ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_11 * V_99 )
{
int V_78 ;
char * V_91 = V_2 -> V_61 ;
unsigned int V_117 = F_51 ( V_91 ) ;
if ( V_117 > V_118 + F_52 ( V_2 ) - 4 ) {
F_5 ( V_59 , L_22 , V_117 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
return - V_86 ;
}
if ( V_117 > V_119 - 4 ) {
V_2 -> V_60 = true ;
memcpy ( V_2 -> V_58 , V_91 , V_2 -> V_79 ) ;
V_91 = V_2 -> V_58 ;
}
V_78 = F_39 ( V_2 , V_91 + F_27 ( V_2 ) - 1 ,
V_117 - F_27 ( V_2 ) + 1 + 4 ) ;
if ( V_78 < 0 )
return V_78 ;
V_2 -> V_79 += V_78 ;
F_53 ( V_91 , V_2 -> V_79 ) ;
V_78 = V_2 -> V_49 -> V_120 ( V_91 , V_2 -> V_79 ) ;
if ( V_78 != 0 )
F_54 ( L_23 , V_91 ,
F_55 (unsigned int, server->total_read, 48 ) ) ;
if ( V_2 -> V_49 -> V_121 &&
V_2 -> V_49 -> V_121 ( V_91 , V_2 , V_78 ) )
return - 1 ;
if ( ! V_99 )
return V_78 ;
F_44 ( V_99 , V_2 , V_91 , V_78 ) ;
return 0 ;
}
static int
F_56 ( void * V_122 )
{
int V_78 ;
struct V_1 * V_2 = V_122 ;
unsigned int V_117 ;
char * V_91 = NULL ;
struct V_123 * V_124 = NULL ;
struct V_11 * V_12 ;
V_125 -> V_30 |= V_126 ;
F_5 ( V_20 , L_24 , F_57 ( V_125 ) ) ;
V_78 = F_58 ( & V_114 ) ;
if ( V_78 > 1 )
F_49 ( V_115 , V_78 + V_116 ) ;
F_59 () ;
while ( V_2 -> V_15 != V_16 ) {
if ( F_17 () )
continue;
if ( ! F_25 ( V_2 ) )
continue;
V_2 -> V_60 = false ;
V_91 = V_2 -> V_61 ;
V_117 = 4 ;
V_78 = F_39 ( V_2 , V_91 , V_117 ) ;
if ( V_78 < 0 )
continue;
V_2 -> V_79 = V_78 ;
V_117 = F_51 ( V_91 ) ;
F_5 ( V_20 , L_25 , V_117 ) ;
if ( ! F_40 ( V_2 , V_91 [ 0 ] ) )
continue;
if ( V_117 < F_27 ( V_2 ) - 1 - 4 ) {
F_5 ( V_59 , L_26 ,
V_117 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_63 ) ;
continue;
}
V_78 = F_39 ( V_2 , V_91 + 4 ,
F_27 ( V_2 ) - 1 - 4 ) ;
if ( V_78 < 0 )
continue;
V_2 -> V_79 += V_78 ;
V_12 = V_2 -> V_49 -> V_127 ( V_2 , V_91 ) ;
if ( ! V_12 || ! V_12 -> V_128 )
V_78 = F_50 ( V_2 , V_12 ) ;
else
V_78 = V_12 -> V_128 ( V_2 , V_12 ) ;
if ( V_78 < 0 )
continue;
if ( V_2 -> V_60 )
V_91 = V_2 -> V_58 ;
V_2 -> V_37 = V_38 ;
if ( V_12 != NULL ) {
if ( ! V_12 -> V_106 || V_12 -> V_129 )
V_12 -> V_43 ( V_12 ) ;
} else if ( ! V_2 -> V_49 -> V_130 ||
! V_2 -> V_49 -> V_130 ( V_91 , V_2 ) ) {
F_5 ( V_59 , L_27 ,
F_60 ( & V_131 ) ) ;
F_54 ( L_28 , V_91 ,
F_27 ( V_2 ) ) ;
#ifdef F_61
if ( V_2 -> V_49 -> V_132 )
V_2 -> V_49 -> V_132 ( V_91 ) ;
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
V_138 = F_35 ( ( V_36 + 1 ) , V_141 ) ;
if ( V_138 == NULL )
return F_71 ( - V_83 ) ;
memcpy ( V_138 , V_137 , V_36 ) ;
V_138 [ V_36 ] = '\0' ;
return V_138 ;
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
return - V_140 ;
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
return - V_140 ;
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
#ifdef F_87
case V_193 :
V_148 -> V_49 = & V_194 ;
V_148 -> V_180 = & V_195 ;
break;
#endif
#endif
default:
F_5 ( V_59 , L_32 , V_144 ) ;
return 1 ;
}
return 0 ;
}
static int
F_88 ( const char * V_196 , struct V_147 * V_148 )
{
char * V_197 ;
const char * V_198 = L_33 ;
T_1 V_36 ;
V_36 = strspn ( V_196 , V_198 ) ;
if ( V_36 != 2 )
return - V_140 ;
V_197 = strpbrk ( V_196 + 2 , V_198 ) ;
if ( ! V_197 )
return - V_140 ;
++ V_197 ;
V_36 = strcspn ( V_197 , V_198 ) ;
V_197 += V_36 ;
V_148 -> V_199 = F_89 ( V_196 , V_197 - V_196 , V_141 ) ;
if ( ! V_148 -> V_199 )
return - V_83 ;
F_90 ( V_148 -> V_199 , '\\' ) ;
if ( ! * V_197 ++ || ! * V_197 )
return 0 ;
V_148 -> V_200 = F_91 ( V_197 , V_141 ) ;
if ( ! V_148 -> V_200 )
return - V_83 ;
return 0 ;
}
static int
F_92 ( const char * V_201 , const char * V_196 ,
struct V_147 * V_148 )
{
char * V_202 , * V_203 ;
char * V_204 = NULL , * V_205 ;
unsigned int V_206 , V_207 , V_208 ;
char V_209 [ 2 ] ;
short int V_210 = - 1 ;
short int V_211 = - 1 ;
bool V_212 = false ;
bool V_213 = false ;
bool V_214 = false ;
char * V_215 = NULL ;
char * V_216 = F_93 () -> V_216 ;
char * string = NULL ;
char * V_217 , * V_144 ;
char V_139 ;
bool V_218 = false ;
unsigned short V_219 = 0 ;
struct V_96 * V_97 = (struct V_96 * ) & V_148 -> V_97 ;
V_209 [ 0 ] = ',' ;
V_209 [ 1 ] = 0 ;
V_139 = V_209 [ 0 ] ;
memset ( V_148 , 0 , sizeof( * V_148 ) ) ;
memset ( V_148 -> V_220 , 0x20 , V_221 ) ;
for ( V_207 = 0 ; V_207 < F_94 ( V_216 , V_221 ) ; V_207 ++ )
V_148 -> V_220 [ V_207 ] = toupper ( V_216 [ V_207 ] ) ;
V_148 -> V_220 [ V_221 ] = 0 ;
V_148 -> V_222 [ 0 ] = 0 ;
V_148 -> V_223 = F_95 () ;
V_148 -> V_224 = F_95 () ;
V_148 -> V_225 = F_96 () ;
V_148 -> V_226 = true ;
V_148 -> V_227 = V_148 -> V_228 = V_229 | V_230 | V_231 ;
V_148 -> V_232 = 1 ;
V_148 -> V_233 = 1 ;
V_148 -> V_174 = true ;
V_148 -> V_234 = V_235 ;
V_148 -> V_49 = & V_179 ;
V_148 -> V_180 = & V_181 ;
if ( ! V_201 )
goto V_236;
V_204 = F_89 ( V_201 , V_237 , V_141 ) ;
if ( ! V_204 )
goto V_236;
V_205 = V_204 ;
V_203 = V_205 + strlen ( V_205 ) ;
if ( strncmp ( V_205 , L_34 , 4 ) == 0 ) {
if ( V_205 [ 4 ] != 0 ) {
V_209 [ 0 ] = V_205 [ 4 ] ;
V_205 += 5 ;
} else {
F_5 ( V_20 , L_35 ) ;
}
}
V_148 -> V_238 = false ;
V_148 -> V_239 = false ;
switch ( F_88 ( V_196 , V_148 ) ) {
case 0 :
break;
case - V_83 :
F_5 ( V_59 , L_36 ) ;
goto V_236;
case - V_140 :
F_5 ( V_59 , L_37 ) ;
goto V_236;
default:
F_5 ( V_59 , L_38 ) ;
goto V_236;
}
while ( ( V_202 = F_97 ( & V_205 , V_209 ) ) != NULL ) {
T_2 args [ V_149 ] ;
unsigned long V_142 ;
int V_240 ;
if ( ! * V_202 )
continue;
V_240 = F_83 ( V_202 , V_241 , args ) ;
switch ( V_240 ) {
case V_242 :
break;
case V_243 :
V_148 -> V_244 = 0 ;
break;
case V_245 :
V_148 -> V_244 = 1 ;
break;
case V_246 :
V_210 = 1 ;
break;
case V_247 :
V_210 = 0 ;
break;
case V_248 :
V_211 = 1 ;
break;
case V_249 :
V_211 = 0 ;
break;
case V_250 :
V_148 -> V_251 = 1 ;
break;
case V_252 :
V_148 -> V_253 = 1 ;
break;
case V_254 :
V_148 -> V_255 = 1 ;
break;
case V_256 :
V_148 -> V_255 = 0 ;
break;
case V_257 :
V_148 -> V_258 = 0 ;
break;
case V_259 :
V_148 -> V_258 = 1 ;
break;
case V_260 :
V_148 -> V_261 = true ;
V_148 -> V_226 = false ;
break;
case V_262 :
V_148 -> V_261 = false ;
break;
case V_263 :
V_148 -> V_226 = true ;
V_148 -> V_261 = false ;
break;
case V_264 :
V_148 -> V_226 = false ;
break;
case V_265 :
V_148 -> V_266 = 1 ;
break;
case V_267 :
V_148 -> V_266 = 0 ;
break;
case V_268 :
V_148 -> V_269 = 1 ;
break;
case V_270 :
V_148 -> V_232 = 1 ;
break;
case V_271 :
V_148 -> V_232 = 0 ;
break;
case V_272 :
V_148 -> V_273 = 1 ;
break;
case V_274 :
V_148 -> V_275 = 1 ;
break;
case V_276 :
V_148 -> V_277 = 0 ;
break;
case V_278 :
V_148 -> V_277 = 1 ;
if ( V_148 -> V_228 ==
( V_279 & ~ ( V_280 | V_281 ) ) )
V_148 -> V_228 = V_279 ;
break;
case V_282 :
V_148 -> V_283 = 1 ;
break;
case V_284 :
V_148 -> V_285 = 1 ;
break;
case V_286 :
V_148 -> V_285 = 0 ;
break;
case V_287 :
V_148 -> V_288 = true ;
break;
case V_289 :
V_148 -> V_288 = false ;
break;
case V_290 :
V_148 -> V_255 = 0 ;
break;
case V_291 :
V_148 -> V_255 = 1 ;
break;
case V_292 :
V_148 -> V_293 = 0 ;
break;
case V_294 :
V_148 -> V_293 = 1 ;
break;
case V_295 :
V_148 -> V_296 = 1 ;
break;
case V_297 :
V_148 -> V_296 = 0 ;
break;
case V_298 :
V_148 -> V_233 = 1 ;
break;
case V_299 :
V_148 -> V_233 = 0 ;
break;
case V_300 :
V_148 -> V_301 = 1 ;
break;
case V_302 :
V_148 -> V_303 = 1 ;
break;
case V_304 :
V_148 -> V_303 = 0 ;
break;
case V_305 :
V_148 -> V_306 = 0 ;
break;
case V_307 :
V_148 -> V_306 = 1 ;
break;
case V_308 :
V_148 -> V_309 = 1 ;
break;
case V_310 :
V_148 -> V_152 = true ;
break;
case V_311 :
V_148 -> V_312 = 1 ;
break;
case V_313 :
F_98 ( L_39 ) ;
break;
case V_314 :
#ifndef F_99
F_5 ( V_59 , L_40 ) ;
goto V_236;
#endif
V_148 -> V_315 = true ;
break;
case V_316 :
V_148 -> V_317 = true ;
break;
case V_318 :
V_148 -> V_319 = true ;
break;
case V_320 :
V_214 = true ;
break;
case V_321 :
V_148 -> V_322 = true ;
break;
case V_323 :
V_148 -> V_324 = true ;
if ( V_148 -> V_325 ) {
F_5 ( V_59 ,
L_41 ) ;
goto V_236;
}
break;
case V_326 :
V_148 -> V_325 = true ;
if ( ( V_148 -> V_324 ) || ( V_148 -> V_327 ) ) {
F_5 ( V_59 ,
L_41 ) ;
goto V_236;
}
break;
case V_328 :
V_148 -> V_327 = true ;
if ( V_148 -> V_325 ) {
F_5 ( V_59 ,
L_41 ) ;
goto V_236;
}
break;
case V_329 :
V_148 -> V_327 = false ;
break;
case V_330 :
if ( F_75 ( args , & V_148 -> V_331 ) ) {
F_5 ( V_59 , L_42 ,
V_21 ) ;
goto V_236;
}
V_148 -> V_238 = true ;
break;
case V_332 :
if ( F_79 ( args , & V_148 -> V_333 ) ) {
F_5 ( V_59 , L_43 ,
V_21 ) ;
goto V_236;
}
V_148 -> V_239 = true ;
break;
case V_334 :
if ( F_75 ( args , & V_148 -> V_224 ) ) {
F_5 ( V_59 , L_44 ,
V_21 ) ;
goto V_236;
}
V_212 = true ;
break;
case V_335 :
if ( F_75 ( args , & V_148 -> V_223 ) ) {
F_5 ( V_59 , L_45 ,
V_21 ) ;
goto V_236;
}
break;
case V_336 :
if ( F_79 ( args , & V_148 -> V_225 ) ) {
F_5 ( V_59 , L_46 ,
V_21 ) ;
goto V_236;
}
V_213 = true ;
break;
case V_337 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_47 ,
V_21 ) ;
goto V_236;
}
V_148 -> V_228 = V_142 ;
break;
case V_338 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_48 ,
V_21 ) ;
goto V_236;
}
V_148 -> V_227 = V_142 ;
break;
case V_339 :
if ( F_72 ( args , & V_142 ) ||
V_142 > V_340 ) {
F_5 ( V_59 , L_49 ,
V_21 ) ;
goto V_236;
}
V_219 = ( unsigned short ) V_142 ;
break;
case V_341 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_50 ,
V_21 ) ;
goto V_236;
}
V_148 -> V_342 = V_142 ;
break;
case V_343 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_51 ,
V_21 ) ;
goto V_236;
}
V_148 -> V_344 = V_142 ;
break;
case V_345 :
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_52 ,
V_21 ) ;
goto V_236;
}
V_148 -> V_234 = V_53 * V_142 ;
if ( V_148 -> V_234 > V_346 ) {
F_5 ( V_59 , L_53 ) ;
goto V_236;
}
break;
case V_347 :
V_148 -> V_170 = 1 ;
V_148 -> V_348 = NULL ;
break;
case V_349 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_350;
if ( F_94 ( string , V_351 ) >
V_351 ) {
F_98 ( L_54 ) ;
goto V_236;
}
F_11 ( V_148 -> V_348 ) ;
V_148 -> V_348 = F_91 ( string , V_141 ) ;
if ( ! V_148 -> V_348 )
goto V_236;
break;
case V_352 :
V_217 = strchr ( V_202 , '=' ) ;
V_217 ++ ;
if ( ! ( V_217 < V_203 && V_217 [ 1 ] == V_139 ) ) {
F_11 ( V_148 -> V_353 ) ;
V_148 -> V_353 = NULL ;
break;
}
case V_354 :
V_144 = strchr ( V_202 , '=' ) ;
V_144 ++ ;
V_217 = ( char * ) V_144 + strlen ( V_144 ) ;
if ( V_217 < V_203 && V_217 [ 1 ] == V_139 ) {
V_217 [ 0 ] = V_139 ;
while ( ( V_217 = strchr ( V_217 , V_139 ) )
!= NULL && ( V_217 [ 1 ] == V_139 ) ) {
V_217 = ( char * ) & V_217 [ 2 ] ;
}
if ( V_217 ) {
V_217 [ 0 ] = '\0' ;
V_205 = ( char * ) & V_217 [ 1 ] ;
} else
V_205 = V_203 ;
}
F_11 ( V_148 -> V_353 ) ;
V_206 = strlen ( V_144 ) ;
V_148 -> V_353 = F_100 ( V_206 + 1 , V_141 ) ;
if ( V_148 -> V_353 == NULL ) {
F_98 ( L_55 ) ;
goto V_236;
}
for ( V_207 = 0 , V_208 = 0 ; V_207 < V_206 ; V_207 ++ , V_208 ++ ) {
V_148 -> V_353 [ V_208 ] = V_144 [ V_207 ] ;
if ( ( V_144 [ V_207 ] == V_139 ) &&
V_144 [ V_207 + 1 ] == V_139 )
V_207 ++ ;
}
V_148 -> V_353 [ V_208 ] = '\0' ;
break;
case V_355 :
V_218 = false ;
break;
case V_356 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_350;
if ( ! F_101 ( V_97 , string ,
strlen ( string ) ) ) {
F_102 ( L_56 , string ) ;
goto V_236;
}
V_218 = true ;
break;
case V_357 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_350;
if ( F_94 ( string , V_358 )
== V_358 ) {
F_98 ( L_57 ) ;
goto V_236;
}
F_11 ( V_148 -> V_359 ) ;
V_148 -> V_359 = F_91 ( string , V_141 ) ;
if ( ! V_148 -> V_359 ) {
F_98 ( L_58 ) ;
goto V_236;
}
F_5 ( V_20 , L_59 ) ;
break;
case V_360 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_350;
if ( ! F_101 (
(struct V_96 * ) & V_148 -> V_361 ,
string , strlen ( string ) ) ) {
F_98 ( L_60 ,
string ) ;
goto V_236;
}
break;
case V_362 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_350;
if ( F_94 ( string , 1024 ) >= 65 ) {
F_98 ( L_61 ) ;
goto V_236;
}
if ( strncasecmp ( string , L_62 , 7 ) != 0 ) {
F_11 ( V_148 -> V_363 ) ;
V_148 -> V_363 = F_91 ( string ,
V_141 ) ;
if ( ! V_148 -> V_363 ) {
F_98 ( L_63 ) ;
goto V_236;
}
}
F_5 ( V_20 , L_64 , string ) ;
break;
case V_364 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_350;
memset ( V_148 -> V_220 , 0x20 ,
V_221 ) ;
for ( V_207 = 0 ; V_207 < V_221 ; V_207 ++ ) {
if ( string [ V_207 ] == 0 )
break;
V_148 -> V_220 [ V_207 ] = string [ V_207 ] ;
}
if ( V_207 == V_221 && string [ V_207 ] != 0 )
F_98 ( L_65 ) ;
break;
case V_365 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_350;
memset ( V_148 -> V_222 , 0x20 ,
V_366 ) ;
for ( V_207 = 0 ; V_207 < 15 ; V_207 ++ ) {
if ( string [ V_207 ] == 0 )
break;
V_148 -> V_222 [ V_207 ] = string [ V_207 ] ;
}
if ( V_207 == V_221 && string [ V_207 ] != 0 )
F_98 ( L_66 ) ;
break;
case V_367 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_350;
if ( strncasecmp ( string , L_67 , 1 ) == 0 ) {
break;
}
F_98 ( L_68 ) ;
goto V_236;
case V_368 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_350;
if ( F_86 ( string , V_148 ) != 0 )
goto V_236;
break;
case V_369 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_350;
if ( F_82 ( string , V_148 ) != 0 )
goto V_236;
break;
case V_370 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_350;
if ( F_85 ( string , V_148 ) != 0 )
goto V_236;
break;
default:
if ( ! V_215 )
V_215 = V_202 ;
break;
}
F_11 ( string ) ;
string = NULL ;
}
if ( ! V_214 && V_215 ) {
F_102 ( L_69 , V_215 ) ;
goto V_236;
}
#ifndef F_103
if ( V_148 -> V_319 ) {
F_5 ( V_59 , L_70 ) ;
goto V_236;
}
#endif
if ( ! V_148 -> V_199 ) {
F_5 ( V_59 , L_71 ) ;
goto V_236;
}
if ( ! strchr ( V_148 -> V_199 + 3 , '\\' ) ) {
F_5 ( V_59 , L_72 ) ;
goto V_236;
}
if ( ! V_218 ) {
if ( ! F_101 ( V_97 , & V_148 -> V_199 [ 2 ] ,
strlen ( & V_148 -> V_199 [ 2 ] ) ) ) {
F_102 ( L_73 ) ;
goto V_236;
}
}
F_41 ( V_97 , V_219 ) ;
if ( V_212 )
V_148 -> V_210 = V_210 ;
else if ( V_210 == 1 )
F_104 ( L_74 ) ;
if ( V_213 )
V_148 -> V_211 = V_211 ;
else if ( V_211 == 1 )
F_104 ( L_75 ) ;
F_11 ( V_204 ) ;
return 0 ;
V_350:
F_98 ( L_76 ) ;
V_236:
F_11 ( string ) ;
F_11 ( V_204 ) ;
return 1 ;
}
static bool
F_105 ( struct V_96 * V_361 , struct V_96 * V_371 )
{
switch ( V_361 -> V_372 ) {
case V_373 :
return ( V_371 -> V_372 == V_373 ) ;
case V_374 : {
struct V_375 * V_376 = (struct V_375 * ) V_361 ;
struct V_375 * V_377 = (struct V_375 * ) V_371 ;
return ( V_376 -> V_378 . V_379 == V_377 -> V_378 . V_379 ) ;
}
case V_380 : {
struct V_381 * V_382 = (struct V_381 * ) V_361 ;
struct V_381 * V_383 = (struct V_381 * ) V_371 ;
return F_106 ( & V_382 -> V_384 , & V_383 -> V_384 ) ;
}
default:
F_107 ( 1 ) ;
return false ;
}
}
static bool
F_108 ( struct V_1 * V_2 , struct V_96 * V_385 )
{
T_5 V_219 , * V_386 ;
switch ( V_385 -> V_372 ) {
case V_374 :
V_386 = & ( (struct V_375 * ) & V_2 -> V_97 ) -> V_387 ;
V_219 = ( (struct V_375 * ) V_385 ) -> V_387 ;
break;
case V_380 :
V_386 = & ( (struct V_381 * ) & V_2 -> V_97 ) -> V_388 ;
V_219 = ( (struct V_381 * ) V_385 ) -> V_388 ;
break;
default:
F_107 ( 1 ) ;
return false ;
}
if ( ! V_219 ) {
V_219 = F_109 ( V_98 ) ;
if ( V_219 == * V_386 )
return true ;
V_219 = F_109 ( V_389 ) ;
}
return V_219 == * V_386 ;
}
static bool
F_110 ( struct V_1 * V_2 , struct V_96 * V_385 ,
struct V_96 * V_361 )
{
switch ( V_385 -> V_372 ) {
case V_374 : {
struct V_375 * V_390 = (struct V_375 * ) V_385 ;
struct V_375 * V_391 =
(struct V_375 * ) & V_2 -> V_97 ;
if ( V_390 -> V_378 . V_379 != V_391 -> V_378 . V_379 )
return false ;
break;
}
case V_380 : {
struct V_381 * V_392 = (struct V_381 * ) V_385 ;
struct V_381 * V_393 =
(struct V_381 * ) & V_2 -> V_97 ;
if ( ! F_106 ( & V_392 -> V_384 ,
& V_393 -> V_384 ) )
return false ;
if ( V_392 -> V_394 != V_393 -> V_394 )
return false ;
break;
}
default:
F_107 ( 1 ) ;
return false ;
}
if ( ! F_105 ( V_361 , (struct V_96 * ) & V_2 -> V_361 ) )
return false ;
return true ;
}
static bool
F_111 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
if ( F_112 ( V_2 , V_148 -> V_150 ) == V_151 )
return false ;
if ( V_148 -> V_152 && ! V_2 -> V_152 )
return false ;
return true ;
}
static int F_113 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
struct V_96 * V_385 = (struct V_96 * ) & V_148 -> V_97 ;
if ( V_148 -> V_322 )
return 0 ;
if ( ( V_2 -> V_180 != V_148 -> V_180 ) || ( V_2 -> V_49 != V_148 -> V_49 ) )
return 0 ;
if ( ! F_114 ( F_115 ( V_2 ) , V_125 -> V_395 -> V_396 ) )
return 0 ;
if ( ! F_110 ( V_2 , V_385 ,
(struct V_96 * ) & V_148 -> V_361 ) )
return 0 ;
if ( ! F_108 ( V_2 , V_385 ) )
return 0 ;
if ( ! F_111 ( V_2 , V_148 ) )
return 0 ;
return 1 ;
}
static struct V_1 *
F_116 ( struct V_147 * V_148 )
{
struct V_1 * V_2 ;
F_2 ( & V_22 ) ;
F_117 (server, &cifs_tcp_ses_list, tcp_ses_list) {
if ( ! F_113 ( V_2 , V_148 ) )
continue;
++ V_2 -> V_397 ;
F_3 ( & V_22 ) ;
F_5 ( V_20 , L_77 ) ;
return V_2 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_118 ( struct V_1 * V_2 )
{
struct V_123 * V_398 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_397 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_119 ( F_115 ( V_2 ) ) ;
F_16 ( & V_2 -> V_107 ) ;
F_3 ( & V_22 ) ;
F_120 ( & V_2 -> V_48 ) ;
F_2 ( & V_14 ) ;
V_2 -> V_15 = V_16 ;
F_3 ( & V_14 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_11 ( V_2 -> V_34 . V_35 ) ;
V_2 -> V_34 . V_35 = NULL ;
V_2 -> V_34 . V_36 = 0 ;
V_398 = F_65 ( & V_2 -> V_133 , NULL ) ;
if ( V_398 )
F_123 ( V_399 , V_398 ) ;
}
static struct V_1 *
F_124 ( struct V_147 * V_400 )
{
struct V_1 * V_401 = NULL ;
int V_3 ;
F_5 ( V_20 , L_78 , V_400 -> V_199 ) ;
V_401 = F_116 ( V_400 ) ;
if ( V_401 )
return V_401 ;
V_401 = F_100 ( sizeof( struct V_1 ) , V_141 ) ;
if ( ! V_401 ) {
V_3 = - V_83 ;
goto V_402;
}
V_401 -> V_49 = V_400 -> V_49 ;
V_401 -> V_180 = V_400 -> V_180 ;
F_125 ( V_401 , F_126 ( V_125 -> V_395 -> V_396 ) ) ;
V_401 -> V_56 = F_70 ( V_400 -> V_199 ) ;
if ( F_127 ( V_401 -> V_56 ) ) {
V_3 = F_128 ( V_401 -> V_56 ) ;
goto V_403;
}
V_401 -> V_251 = V_400 -> V_251 ;
V_401 -> V_253 = V_400 -> V_253 ;
V_401 -> V_404 = V_400 -> V_405 ;
V_401 -> V_406 = 0 ;
V_401 -> V_109 = 1 ;
F_129 ( & V_401 -> V_63 ) ;
F_129 ( & V_401 -> V_110 ) ;
F_13 ( & V_401 -> V_111 ) ;
F_130 ( & V_401 -> V_27 ) ;
memcpy ( V_401 -> V_407 ,
V_400 -> V_220 , V_366 ) ;
memcpy ( V_401 -> V_408 ,
V_400 -> V_222 , V_366 ) ;
V_401 -> V_33 = false ;
V_401 -> V_32 = 0 ;
V_401 -> V_37 = V_38 ;
F_131 ( & V_401 -> V_108 ) ;
F_13 ( & V_401 -> V_107 ) ;
F_13 ( & V_401 -> V_23 ) ;
F_132 ( & V_401 -> V_48 , F_21 ) ;
memcpy ( & V_401 -> V_361 , & V_400 -> V_361 ,
sizeof( V_401 -> V_361 ) ) ;
memcpy ( & V_401 -> V_97 , & V_400 -> V_97 ,
sizeof( V_401 -> V_97 ) ) ;
#ifdef F_4
F_133 ( V_401 -> V_409 , V_410 ) ;
#endif
V_401 -> V_15 = V_411 ;
++ V_401 -> V_397 ;
V_3 = F_134 ( V_401 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_79 ) ;
goto V_403;
}
F_135 ( V_412 ) ;
V_401 -> V_133 = F_136 ( F_56 ,
V_401 , L_80 ) ;
if ( F_127 ( V_401 -> V_133 ) ) {
V_3 = F_128 ( V_401 -> V_133 ) ;
F_5 ( V_59 , L_81 , V_3 ) ;
F_137 ( V_412 ) ;
goto V_403;
}
V_401 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_138 ( & V_401 -> V_107 , & V_413 ) ;
F_3 ( & V_22 ) ;
F_139 ( V_401 ) ;
F_24 ( V_57 , & V_401 -> V_48 , V_52 ) ;
return V_401 ;
V_403:
F_121 ( V_401 ) ;
F_119 ( F_115 ( V_401 ) ) ;
V_402:
if ( V_401 ) {
if ( ! F_127 ( V_401 -> V_56 ) )
F_11 ( V_401 -> V_56 ) ;
if ( V_401 -> V_28 )
F_10 ( V_401 -> V_28 ) ;
F_11 ( V_401 ) ;
}
return F_71 ( V_3 ) ;
}
static int F_140 ( struct V_7 * V_8 , struct V_147 * V_148 )
{
if ( V_148 -> V_150 != V_151 &&
V_148 -> V_150 != V_8 -> V_150 )
return 0 ;
switch ( V_8 -> V_150 ) {
case V_157 :
if ( ! F_141 ( V_148 -> V_223 , V_8 -> V_223 ) )
return 0 ;
break;
default:
if ( V_8 -> V_414 == NULL ) {
if ( ! V_148 -> V_170 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_414 ,
V_148 -> V_348 ? V_148 -> V_348 : L_82 ,
V_351 ) )
return 0 ;
if ( ( V_148 -> V_348 && strlen ( V_148 -> V_348 ) != 0 ) &&
V_8 -> V_353 != NULL &&
strncmp ( V_8 -> V_353 ,
V_148 -> V_353 ? V_148 -> V_353 : L_82 ,
V_415 ) )
return 0 ;
}
return 1 ;
}
static struct V_7 *
F_142 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
struct V_7 * V_8 ;
F_2 ( & V_22 ) ;
F_117 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_8 -> V_416 == V_16 )
continue;
if ( ! F_140 ( V_8 , V_148 ) )
continue;
++ V_8 -> V_417 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_143 ( struct V_7 * V_8 )
{
unsigned int V_3 , V_418 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_20 , L_83 , V_21 , V_8 -> V_417 ) ;
F_2 ( & V_22 ) ;
if ( V_8 -> V_416 == V_16 ) {
F_3 ( & V_22 ) ;
return;
}
if ( -- V_8 -> V_417 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
if ( V_8 -> V_416 == V_62 )
V_8 -> V_416 = V_16 ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_416 == V_16 && V_2 -> V_49 -> V_419 ) {
V_418 = F_144 () ;
V_3 = V_2 -> V_49 -> V_419 ( V_418 , V_8 ) ;
if ( V_3 )
F_5 ( V_59 , L_84 ,
V_21 , V_3 ) ;
F_145 ( V_418 ) ;
}
F_2 ( & V_22 ) ;
F_16 ( & V_8 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_146 ( V_8 ) ;
F_118 ( V_2 ) ;
}
static int
F_147 ( struct V_147 * V_148 , struct V_7 * V_8 )
{
int V_3 = 0 ;
const char * V_139 , * V_420 ;
char * V_421 ;
T_6 V_36 ;
struct V_422 * V_422 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_375 * V_423 ;
struct V_381 * V_424 ;
const struct V_425 * V_426 ;
V_421 = F_35 ( V_427 , V_141 ) ;
if ( ! V_421 )
return - V_83 ;
switch ( V_2 -> V_97 . V_428 ) {
case V_374 :
V_423 = (struct V_375 * ) & V_2 -> V_97 ;
sprintf ( V_421 , L_85 , & V_423 -> V_378 . V_379 ) ;
break;
case V_380 :
V_424 = (struct V_381 * ) & V_2 -> V_97 ;
sprintf ( V_421 , L_86 , & V_424 -> V_384 . V_429 ) ;
break;
default:
F_5 ( V_20 , L_87 ,
V_2 -> V_97 . V_428 ) ;
V_3 = - V_140 ;
goto V_402;
}
F_5 ( V_20 , L_88 , V_21 , V_421 ) ;
V_422 = F_148 ( & V_430 , V_421 , L_82 ) ;
if ( F_127 ( V_422 ) ) {
if ( ! V_8 -> V_431 ) {
F_5 ( V_20 , L_89 ) ;
V_3 = F_128 ( V_422 ) ;
goto V_402;
}
sprintf ( V_421 , L_90 , V_8 -> V_431 ) ;
F_5 ( V_20 , L_88 , V_21 , V_421 ) ;
V_422 = F_148 ( & V_430 , V_421 , L_82 ) ;
if ( F_127 ( V_422 ) ) {
V_3 = F_128 ( V_422 ) ;
goto V_402;
}
}
F_149 ( & V_422 -> V_432 ) ;
V_426 = V_425 ( V_422 ) ;
if ( F_150 ( V_426 ) ) {
V_3 = V_426 ? F_128 ( V_426 ) : - V_140 ;
goto V_433;
}
V_420 = V_426 -> V_202 ;
V_139 = F_151 ( V_420 , V_426 -> V_434 , ':' ) ;
F_5 ( V_20 , L_91 , V_420 ) ;
if ( ! V_139 ) {
F_5 ( V_20 , L_92 ,
V_426 -> V_434 ) ;
V_3 = - V_140 ;
goto V_433;
}
V_36 = V_139 - V_420 ;
if ( V_36 > V_351 || V_36 <= 0 ) {
F_5 ( V_20 , L_93 ,
V_36 ) ;
V_3 = - V_140 ;
goto V_433;
}
V_148 -> V_348 = F_89 ( V_420 , V_36 , V_141 ) ;
if ( ! V_148 -> V_348 ) {
F_5 ( V_20 , L_94 ,
V_36 ) ;
V_3 = - V_83 ;
goto V_433;
}
F_5 ( V_20 , L_95 , V_21 , V_148 -> V_348 ) ;
V_36 = V_422 -> V_434 - ( V_36 + 1 ) ;
if ( V_36 > V_415 || V_36 <= 0 ) {
F_5 ( V_20 , L_96 , V_36 ) ;
V_3 = - V_140 ;
F_11 ( V_148 -> V_348 ) ;
V_148 -> V_348 = NULL ;
goto V_433;
}
++ V_139 ;
V_148 -> V_353 = F_89 ( V_139 , V_36 , V_141 ) ;
if ( ! V_148 -> V_353 ) {
F_5 ( V_20 , L_97 ,
V_36 ) ;
V_3 = - V_83 ;
F_11 ( V_148 -> V_348 ) ;
V_148 -> V_348 = NULL ;
goto V_433;
}
V_433:
F_152 ( & V_422 -> V_432 ) ;
F_153 ( V_422 ) ;
V_402:
F_11 ( V_421 ) ;
F_5 ( V_20 , L_98 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_154 ( struct V_1 * V_2 , struct V_147 * V_400 )
{
int V_3 = - V_83 ;
unsigned int V_418 ;
struct V_7 * V_8 ;
struct V_375 * V_385 = (struct V_375 * ) & V_2 -> V_97 ;
struct V_381 * V_392 = (struct V_381 * ) & V_2 -> V_97 ;
V_418 = F_144 () ;
V_8 = F_142 ( V_2 , V_400 ) ;
if ( V_8 ) {
F_5 ( V_20 , L_99 ,
V_8 -> V_416 ) ;
F_8 ( & V_8 -> V_435 ) ;
V_3 = F_155 ( V_418 , V_8 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_435 ) ;
F_143 ( V_8 ) ;
F_156 ( V_418 ) ;
return F_71 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_5 ( V_20 , L_100 ) ;
V_3 = F_157 ( V_418 , V_8 ,
V_400 -> V_436 ) ;
if ( V_3 ) {
F_12 ( & V_8 -> V_435 ) ;
F_143 ( V_8 ) ;
F_156 ( V_418 ) ;
return F_71 ( V_3 ) ;
}
}
F_12 ( & V_8 -> V_435 ) ;
F_118 ( V_2 ) ;
F_156 ( V_418 ) ;
return V_8 ;
}
F_5 ( V_20 , L_101 ) ;
V_8 = F_158 () ;
if ( V_8 == NULL )
goto V_437;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_97 . V_428 == V_380 )
sprintf ( V_8 -> V_438 , L_102 , & V_392 -> V_384 ) ;
else
sprintf ( V_8 -> V_438 , L_103 , & V_385 -> V_378 ) ;
if ( V_400 -> V_348 ) {
V_8 -> V_414 = F_91 ( V_400 -> V_348 , V_141 ) ;
if ( ! V_8 -> V_414 )
goto V_437;
}
if ( V_400 -> V_353 ) {
V_8 -> V_353 = F_91 ( V_400 -> V_353 , V_141 ) ;
if ( ! V_8 -> V_353 )
goto V_437;
}
if ( V_400 -> V_359 ) {
V_8 -> V_431 = F_91 ( V_400 -> V_359 , V_141 ) ;
if ( ! V_8 -> V_431 )
goto V_437;
}
V_8 -> V_223 = V_400 -> V_223 ;
V_8 -> V_224 = V_400 -> V_224 ;
V_8 -> V_150 = V_400 -> V_150 ;
V_8 -> V_152 = V_400 -> V_152 ;
F_8 ( & V_8 -> V_435 ) ;
V_3 = F_155 ( V_418 , V_8 ) ;
if ( ! V_3 )
V_3 = F_157 ( V_418 , V_8 , V_400 -> V_436 ) ;
F_12 ( & V_8 -> V_435 ) ;
if ( V_3 )
goto V_437;
F_2 ( & V_22 ) ;
F_138 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_156 ( V_418 ) ;
return V_8 ;
V_437:
F_146 ( V_8 ) ;
F_156 ( V_418 ) ;
return F_71 ( V_3 ) ;
}
static int F_159 ( struct V_9 * V_10 , const char * V_136 )
{
if ( V_10 -> V_439 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_440 , V_136 , V_441 ) )
return 0 ;
return 1 ;
}
static struct V_9 *
F_160 ( struct V_7 * V_8 , const char * V_136 )
{
struct V_4 * V_5 ;
struct V_9 * V_10 ;
F_2 ( & V_22 ) ;
F_6 (tmp, &ses->tcon_list) {
V_10 = F_7 ( V_5 , struct V_9 , V_26 ) ;
if ( ! F_159 ( V_10 , V_136 ) )
continue;
++ V_10 -> V_442 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_161 ( struct V_9 * V_10 )
{
unsigned int V_418 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( V_20 , L_104 , V_21 , V_10 -> V_442 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_442 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_418 = F_144 () ;
if ( V_8 -> V_2 -> V_49 -> V_443 )
V_8 -> V_2 -> V_49 -> V_443 ( V_418 , V_10 ) ;
F_145 ( V_418 ) ;
F_162 ( V_10 ) ;
F_163 ( V_10 ) ;
F_143 ( V_8 ) ;
}
static struct V_9 *
F_164 ( struct V_7 * V_8 , struct V_147 * V_400 )
{
int V_3 , V_418 ;
struct V_9 * V_10 ;
V_10 = F_160 ( V_8 , V_400 -> V_199 ) ;
if ( V_10 ) {
F_5 ( V_20 , L_105 ) ;
F_143 ( V_8 ) ;
if ( V_10 -> V_312 != V_400 -> V_312 )
F_5 ( V_59 , L_106 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_49 -> V_444 ) {
V_3 = - V_55 ;
goto V_445;
}
V_10 = F_165 () ;
if ( V_10 == NULL ) {
V_3 = - V_83 ;
goto V_445;
}
V_10 -> V_8 = V_8 ;
if ( V_400 -> V_353 ) {
V_10 -> V_353 = F_91 ( V_400 -> V_353 , V_141 ) ;
if ( ! V_10 -> V_353 ) {
V_3 = - V_83 ;
goto V_445;
}
}
V_418 = F_144 () ;
V_3 = V_8 -> V_2 -> V_49 -> V_444 ( V_418 , V_8 , V_400 -> V_199 , V_10 ,
V_400 -> V_436 ) ;
F_156 ( V_418 ) ;
F_5 ( V_20 , L_107 , V_3 ) ;
if ( V_3 )
goto V_445;
if ( V_400 -> V_269 ) {
V_10 -> V_446 &= ~ V_447 ;
F_5 ( V_20 , L_108 , V_10 -> V_446 ) ;
}
V_10 -> V_312 = V_400 -> V_312 ;
V_10 -> V_448 = false ;
if ( V_400 -> V_325 ) {
if ( V_8 -> V_2 -> V_180 -> V_449 == 0 ) {
F_5 ( V_59 ,
L_109 ) ;
V_3 = - V_450 ;
goto V_445;
#ifdef F_4
} else if ( V_8 -> V_2 -> V_451 &
V_452 )
V_10 -> V_448 = true ;
else {
F_5 ( V_59 ,
L_110 ) ;
V_3 = - V_450 ;
goto V_445;
#endif
}
#ifdef F_4
} else if ( ( V_10 -> V_451 & V_453 )
&& ( V_8 -> V_2 -> V_451 & V_452 )
&& ( V_400 -> V_324 == false ) ) {
F_5 ( V_20 , L_111 ) ;
V_10 -> V_448 = true ;
#endif
} else if ( V_400 -> V_327 ) {
if ( V_8 -> V_2 -> V_180 -> V_449 == 0 ) {
F_5 ( V_59 ,
L_112 ) ;
V_3 = - V_450 ;
goto V_445;
}
V_10 -> V_454 = true ;
}
V_10 -> V_255 = V_400 -> V_255 ;
V_10 -> V_275 = V_400 -> V_275 ;
V_10 -> V_309 = V_400 -> V_309 ;
F_13 ( & V_10 -> V_455 ) ;
F_2 ( & V_22 ) ;
F_138 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_166 ( V_10 ) ;
return V_10 ;
V_445:
F_163 ( V_10 ) ;
return F_71 ( V_3 ) ;
}
void
F_167 ( struct V_456 * V_457 )
{
if ( ! V_457 || F_127 ( V_457 ) )
return;
if ( ! F_168 ( & V_457 -> V_458 ) ||
F_169 ( V_459 , & V_457 -> V_460 ) ) {
V_457 -> V_461 = V_38 ;
return;
}
if ( ! F_127 ( F_170 ( V_457 ) ) )
F_161 ( F_170 ( V_457 ) ) ;
F_11 ( V_457 ) ;
return;
}
static inline struct V_456 *
F_171 ( struct V_462 * V_463 )
{
return V_463 -> V_464 ;
}
static int
F_172 ( struct V_465 * V_466 , struct V_467 * V_468 )
{
struct V_462 * V_469 = F_173 ( V_466 ) ;
struct V_462 * V_65 = V_468 -> V_463 ;
if ( ( V_466 -> V_470 & V_471 ) != ( V_468 -> V_30 & V_471 ) )
return 0 ;
if ( ( V_469 -> V_472 & V_473 ) !=
( V_65 -> V_472 & V_473 ) )
return 0 ;
if ( V_65 -> V_344 && V_65 -> V_344 < V_469 -> V_344 )
return 0 ;
if ( V_65 -> V_342 && V_65 -> V_342 < V_469 -> V_342 )
return 0 ;
if ( ! F_141 ( V_469 -> V_474 , V_65 -> V_474 ) || ! F_174 ( V_469 -> V_475 , V_65 -> V_475 ) )
return 0 ;
if ( V_469 -> V_476 != V_65 -> V_476 ||
V_469 -> V_477 != V_65 -> V_477 )
return 0 ;
if ( strcmp ( V_469 -> V_436 -> V_478 , V_65 -> V_436 -> V_478 ) )
return 0 ;
if ( V_469 -> V_234 != V_65 -> V_234 )
return 0 ;
return 1 ;
}
int
F_175 ( struct V_465 * V_466 , void * V_202 )
{
struct V_467 * V_468 = (struct V_467 * ) V_202 ;
struct V_147 * V_400 ;
struct V_462 * V_463 ;
struct V_1 * V_479 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_456 * V_457 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_463 = F_173 ( V_466 ) ;
V_457 = F_176 ( F_171 ( V_463 ) ) ;
if ( F_127 ( V_457 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_170 ( V_457 ) ;
V_8 = V_10 -> V_8 ;
V_479 = V_8 -> V_2 ;
V_400 = V_468 -> V_148 ;
if ( ! F_113 ( V_479 , V_400 ) ||
! F_140 ( V_8 , V_400 ) ||
! F_159 ( V_10 , V_400 -> V_199 ) ) {
V_3 = 0 ;
goto V_480;
}
V_3 = F_172 ( V_466 , V_468 ) ;
V_480:
F_3 ( & V_22 ) ;
F_167 ( V_457 ) ;
return V_3 ;
}
int
F_177 ( const unsigned int V_418 , struct V_7 * V_8 , const char * V_481 ,
const struct V_482 * V_483 , unsigned int * V_484 ,
struct V_485 * * V_486 , int V_226 )
{
char * V_487 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_49 -> V_444 || ! V_8 -> V_2 -> V_49 -> V_488 )
return - V_55 ;
* V_484 = 0 ;
* V_486 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_487 = F_35 ( 2 +
F_94 ( V_8 -> V_438 , V_489 * 2 )
+ 1 + 4 + 2 , V_141 ) ;
if ( V_487 == NULL )
return - V_83 ;
V_487 [ 0 ] = '\\' ;
V_487 [ 1 ] = '\\' ;
strcpy ( V_487 + 2 , V_8 -> V_438 ) ;
strcpy ( V_487 + 2 + strlen ( V_8 -> V_438 ) , L_113 ) ;
V_3 = V_8 -> V_2 -> V_49 -> V_444 ( V_418 , V_8 , V_487 , NULL ,
V_483 ) ;
F_5 ( V_20 , L_114 , V_3 , V_8 -> V_25 ) ;
F_11 ( V_487 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_49 -> V_488 ( V_418 , V_8 , V_481 ,
V_486 , V_484 ,
V_483 , V_226 ) ;
return V_3 ;
}
static inline void
F_178 ( struct V_490 * V_491 )
{
struct V_491 * V_492 = V_491 -> V_492 ;
F_179 ( F_180 ( V_492 ) ) ;
F_181 ( V_492 , L_115 ,
& V_493 [ 0 ] , L_116 , & V_494 [ 0 ] ) ;
}
static inline void
F_182 ( struct V_490 * V_491 )
{
struct V_491 * V_492 = V_491 -> V_492 ;
F_179 ( F_180 ( V_492 ) ) ;
F_181 ( V_492 , L_117 ,
& V_493 [ 1 ] , L_118 , & V_494 [ 1 ] ) ;
}
static inline void
F_178 ( struct V_490 * V_491 )
{
}
static inline void
F_182 ( struct V_490 * V_491 )
{
}
static void F_183 ( char * V_495 , char * V_496 , unsigned int V_78 )
{
unsigned int V_207 , V_208 ;
for ( V_207 = 0 , V_208 = 0 ; V_207 < ( V_78 ) ; V_207 ++ ) {
V_495 [ V_208 ] = 'A' + ( 0x0F & ( V_496 [ V_207 ] >> 4 ) ) ;
V_495 [ V_208 + 1 ] = 'A' + ( 0x0F & V_496 [ V_207 ] ) ;
V_208 += 2 ;
}
}
static int
F_184 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_361 . V_428 != V_373 ) {
struct V_490 * V_490 = V_2 -> V_28 ;
V_3 = V_490 -> V_49 -> V_497 ( V_490 ,
(struct V_96 * ) & V_2 -> V_361 ,
sizeof( V_2 -> V_361 ) ) ;
if ( V_3 < 0 ) {
struct V_375 * V_376 ;
struct V_381 * V_382 ;
V_376 = (struct V_375 * ) & V_2 -> V_361 ;
V_382 = (struct V_381 * ) & V_2 -> V_361 ;
if ( V_382 -> V_498 == V_380 )
F_5 ( V_59 , L_119 ,
& V_382 -> V_384 , V_3 ) ;
else
F_5 ( V_59 , L_120 ,
& V_376 -> V_378 . V_379 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_185 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_499 * V_500 ;
struct V_501 * V_502 ;
V_500 = F_100 ( sizeof( struct V_499 ) ,
V_141 ) ;
if ( V_500 ) {
V_500 -> V_503 . V_504 . V_505 = 32 ;
if ( V_2 -> V_408 &&
V_2 -> V_408 [ 0 ] != 0 )
F_183 ( V_500 -> V_503 .
V_504 . V_506 ,
V_2 -> V_408 ,
V_366 ) ;
else
F_183 ( V_500 -> V_503 .
V_504 . V_506 ,
V_507 ,
V_366 ) ;
V_500 -> V_503 . V_504 . V_508 = 32 ;
if ( V_2 -> V_407 [ 0 ] != 0 )
F_183 ( V_500 -> V_503 .
V_504 . V_509 ,
V_2 -> V_407 ,
V_366 ) ;
else
F_183 ( V_500 -> V_503 .
V_504 . V_509 ,
L_121 ,
V_366 ) ;
V_500 -> V_503 . V_504 . V_510 = 0 ;
V_500 -> V_503 . V_504 . V_511 = 0 ;
V_502 = (struct V_501 * ) V_500 ;
V_502 -> V_512 = F_186 ( 0x81000044 ) ;
V_3 = F_187 ( V_2 , V_502 , 0x44 ) ;
F_11 ( V_500 ) ;
F_38 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_386 ;
int V_513 , V_514 ;
struct V_490 * V_490 = V_2 -> V_28 ;
struct V_96 * V_515 ;
V_515 = (struct V_96 * ) & V_2 -> V_97 ;
if ( V_2 -> V_97 . V_428 == V_380 ) {
V_386 = ( (struct V_381 * ) V_515 ) -> V_388 ;
V_513 = sizeof( struct V_381 ) ;
V_514 = V_380 ;
} else {
V_386 = ( (struct V_375 * ) V_515 ) -> V_387 ;
V_513 = sizeof( struct V_375 ) ;
V_514 = V_374 ;
}
if ( V_490 == NULL ) {
V_3 = F_188 ( F_115 ( V_2 ) , V_514 , V_516 ,
V_517 , & V_490 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_122 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_5 ( V_20 , L_123 ) ;
V_2 -> V_28 = V_490 ;
V_490 -> V_492 -> V_518 = V_75 ;
if ( V_514 == V_380 )
F_182 ( V_490 ) ;
else
F_178 ( V_490 ) ;
}
V_3 = F_184 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_490 -> V_492 -> V_519 = 7 * V_53 ;
V_490 -> V_492 -> V_520 = 5 * V_53 ;
if ( V_2 -> V_253 ) {
if ( V_490 -> V_492 -> V_521 < ( 200 * 1024 ) )
V_490 -> V_492 -> V_521 = 200 * 1024 ;
if ( V_490 -> V_492 -> V_522 < ( 140 * 1024 ) )
V_490 -> V_492 -> V_522 = 140 * 1024 ;
}
if ( V_2 -> V_404 ) {
int V_523 = 1 ;
V_3 = F_189 ( V_490 , V_524 , V_525 ,
( char * ) & V_523 , sizeof( V_523 ) ) ;
if ( V_3 )
F_5 ( V_20 , L_124 ,
V_3 ) ;
}
F_5 ( V_20 , L_125 ,
V_490 -> V_492 -> V_521 ,
V_490 -> V_492 -> V_522 , V_490 -> V_492 -> V_519 ) ;
V_3 = V_490 -> V_49 -> V_526 ( V_490 , V_515 , V_513 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_20 , L_126 , V_3 ) ;
F_10 ( V_490 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_386 == F_109 ( V_389 ) )
V_3 = F_185 ( V_2 ) ;
return V_3 ;
}
static int
F_134 ( struct V_1 * V_2 )
{
T_5 * V_386 ;
struct V_381 * V_392 = (struct V_381 * ) & V_2 -> V_97 ;
struct V_375 * V_385 = (struct V_375 * ) & V_2 -> V_97 ;
if ( V_2 -> V_97 . V_428 == V_380 )
V_386 = & V_392 -> V_388 ;
else
V_386 = & V_385 -> V_387 ;
if ( * V_386 == 0 ) {
int V_3 ;
* V_386 = F_109 ( V_98 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_386 = F_109 ( V_389 ) ;
}
return F_18 ( V_2 ) ;
}
void F_190 ( unsigned int V_418 , struct V_9 * V_10 ,
struct V_462 * V_463 , struct V_147 * V_527 )
{
T_7 V_528 = F_191 ( V_10 -> V_529 . V_530 ) ;
if ( V_527 && V_527 -> V_273 ) {
V_10 -> V_529 . V_530 = 0 ;
V_10 -> V_531 = 0 ;
F_5 ( V_20 , L_127 ) ;
return;
} else if ( V_527 )
V_10 -> V_531 = 1 ;
if ( V_10 -> V_531 == 0 ) {
F_5 ( V_20 , L_128 ) ;
return;
}
if ( ! F_192 ( V_418 , V_10 ) ) {
T_7 V_532 = F_191 ( V_10 -> V_529 . V_530 ) ;
F_5 ( V_20 , L_129 , V_532 ) ;
if ( V_527 == NULL ) {
if ( ( V_528 & V_533 ) == 0 )
V_532 &= ~ V_533 ;
if ( ( V_528 & V_534 ) == 0 ) {
if ( V_532 & V_534 )
F_5 ( V_59 , L_130 ) ;
V_532 &= ~ V_534 ;
} else if ( ( V_532 & V_534 ) == 0 ) {
F_5 ( V_59 , L_131 ) ;
F_5 ( V_59 , L_132 ) ;
}
}
if ( V_532 & V_535 )
F_5 ( V_59 , L_133 ) ;
V_532 &= V_536 ;
if ( V_527 && V_527 -> V_306 )
V_532 &= ~ V_533 ;
else if ( V_533 & V_532 ) {
F_5 ( V_20 , L_134 ) ;
if ( V_463 )
V_463 -> V_472 |=
V_537 ;
}
if ( V_527 && V_527 -> V_232 == 0 )
V_532 &= ~ V_534 ;
else if ( V_532 & V_534 ) {
F_5 ( V_20 , L_135 ) ;
if ( V_463 )
V_463 -> V_472 |=
V_538 ;
}
F_5 ( V_20 , L_136 , ( int ) V_532 ) ;
#ifdef F_61
if ( V_532 & V_539 )
F_5 ( V_20 , L_137 ) ;
if ( V_532 & V_540 )
F_5 ( V_20 , L_138 ) ;
if ( V_532 & V_534 )
F_5 ( V_20 , L_139 ) ;
if ( V_532 & V_541 )
F_5 ( V_20 , L_140 ) ;
if ( V_532 & V_533 )
F_5 ( V_20 , L_141 ) ;
if ( V_532 & V_542 )
F_5 ( V_20 , L_142 ) ;
if ( V_532 & V_543 )
F_5 ( V_20 , L_143 ) ;
if ( V_532 & V_544 )
F_5 ( V_20 , L_144 ) ;
if ( V_532 & V_535 )
F_5 ( V_20 , L_145 ) ;
#endif
if ( F_193 ( V_418 , V_10 , V_532 ) ) {
if ( V_527 == NULL ) {
F_5 ( V_20 , L_146 ) ;
} else
F_5 ( V_59 , L_147 ) ;
}
}
}
void F_194 ( struct V_147 * V_545 ,
struct V_462 * V_463 )
{
F_132 ( & V_463 -> V_546 , V_547 ) ;
F_131 ( & V_463 -> V_548 ) ;
V_463 -> V_549 = V_550 ;
V_463 -> V_342 = V_545 -> V_342 ;
V_463 -> V_344 = V_545 -> V_344 ;
V_463 -> V_474 = V_545 -> V_224 ;
V_463 -> V_475 = V_545 -> V_225 ;
V_463 -> V_476 = V_545 -> V_228 ;
V_463 -> V_477 = V_545 -> V_227 ;
F_5 ( V_20 , L_148 ,
V_463 -> V_476 , V_463 -> V_477 ) ;
V_463 -> V_234 = V_545 -> V_234 ;
V_463 -> V_436 = V_545 -> V_436 ;
if ( V_545 -> V_258 )
V_463 -> V_472 |= V_551 ;
if ( V_545 -> V_285 )
V_463 -> V_472 |= V_552 ;
if ( V_545 -> V_233 )
V_463 -> V_472 |= V_553 ;
if ( V_545 -> V_226 )
V_463 -> V_472 |= V_554 ;
if ( V_545 -> V_261 )
V_463 -> V_472 |= V_555 ;
if ( V_545 -> V_244 )
V_463 -> V_472 |= V_556 ;
if ( V_545 -> V_266 )
V_463 -> V_472 |= V_557 ;
if ( V_545 -> V_277 )
V_463 -> V_472 |= V_558 ;
if ( V_545 -> V_296 )
V_463 -> V_472 |= V_559 ;
if ( V_545 -> V_283 )
V_463 -> V_472 |= V_560 ;
if ( V_545 -> V_301 )
V_463 -> V_472 |= V_561 ;
if ( V_545 -> V_303 )
V_463 -> V_472 |= V_562 ;
if ( V_545 -> V_238 ) {
V_463 -> V_472 |= V_563 ;
V_463 -> V_564 = V_545 -> V_331 ;
}
if ( V_545 -> V_239 ) {
V_463 -> V_472 |= V_565 ;
V_463 -> V_566 = V_545 -> V_333 ;
}
if ( V_545 -> V_210 )
V_463 -> V_472 |= V_567 ;
if ( V_545 -> V_211 )
V_463 -> V_472 |= V_568 ;
if ( V_545 -> V_288 )
V_463 -> V_472 |= V_569 ;
if ( V_545 -> V_315 )
V_463 -> V_472 |= V_570 ;
if ( V_545 -> V_319 )
V_463 -> V_472 |= ( V_571 |
V_551 ) ;
if ( V_545 -> V_174 )
V_463 -> V_472 |= V_572 ;
if ( V_545 -> V_173 ) {
F_5 ( V_20 , L_149 ) ;
V_463 -> V_472 |= V_573 ;
}
if ( V_545 -> V_317 ) {
if ( V_545 -> V_266 ) {
F_5 ( V_59 , L_150 ) ;
}
V_463 -> V_472 |= V_574 ;
}
if ( ( V_545 -> V_303 ) && ( V_545 -> V_288 ) )
F_5 ( V_59 , L_151 ) ;
}
static void
F_195 ( struct V_147 * V_400 )
{
F_11 ( V_400 -> V_348 ) ;
F_196 ( V_400 -> V_353 ) ;
F_11 ( V_400 -> V_199 ) ;
F_11 ( V_400 -> V_359 ) ;
F_11 ( V_400 -> V_363 ) ;
F_11 ( V_400 -> V_200 ) ;
}
void
F_197 ( struct V_147 * V_400 )
{
if ( ! V_400 )
return;
F_195 ( V_400 ) ;
F_11 ( V_400 ) ;
}
static char *
F_198 ( const struct V_147 * V_148 ,
const struct V_462 * V_463 )
{
char * V_575 , * V_197 ;
unsigned int V_576 = V_148 -> V_200 ? strlen ( V_148 -> V_200 ) + 1 : 0 ;
unsigned int V_577 = F_94 ( V_148 -> V_199 , V_441 + 1 ) ;
V_575 = F_35 ( V_577 + V_576 + 1 , V_141 ) ;
if ( V_575 == NULL )
return F_71 ( - V_83 ) ;
strncpy ( V_575 , V_148 -> V_199 , V_577 ) ;
V_197 = V_575 + V_577 ;
if ( V_576 ) {
* V_197 = F_199 ( V_463 ) ;
strncpy ( V_197 + 1 , V_148 -> V_200 , V_576 ) ;
V_197 += V_576 ;
}
* V_197 = '\0' ;
F_90 ( V_575 , F_199 ( V_463 ) ) ;
F_5 ( V_20 , L_152 , V_21 , V_575 ) ;
return V_575 ;
}
static int
F_200 ( const unsigned int V_418 , struct V_7 * V_8 ,
struct V_147 * V_400 , struct V_462 * V_463 ,
int V_578 )
{
int V_3 ;
unsigned int V_484 = 0 ;
struct V_485 * V_486 = NULL ;
char * V_575 = NULL , * V_579 = NULL , * V_580 = NULL ;
V_575 = F_198 ( V_400 , V_463 ) ;
if ( F_127 ( V_575 ) )
return F_128 ( V_575 ) ;
V_579 = V_578 ? V_575 + 1 : V_400 -> V_199 + 1 ;
V_3 = F_177 ( V_418 , V_8 , V_579 , V_463 -> V_436 ,
& V_484 , & V_486 , F_201 ( V_463 ) ) ;
if ( ! V_3 && V_484 > 0 ) {
char * V_581 = NULL ;
V_580 = F_202 ( V_463 -> V_201 ,
V_575 + 1 , V_486 ,
& V_581 ) ;
F_203 ( V_486 , V_484 ) ;
if ( F_127 ( V_580 ) ) {
V_3 = F_128 ( V_580 ) ;
V_580 = NULL ;
} else {
F_195 ( V_400 ) ;
V_3 = F_204 ( V_400 , V_580 ,
V_581 ) ;
}
F_11 ( V_581 ) ;
F_11 ( V_463 -> V_201 ) ;
V_463 -> V_201 = V_580 ;
}
F_11 ( V_575 ) ;
return V_3 ;
}
static int
F_204 ( struct V_147 * V_400 , char * V_582 ,
const char * V_196 )
{
int V_3 = 0 ;
if ( F_92 ( V_582 , V_196 , V_400 ) )
return - V_140 ;
if ( V_400 -> V_170 ) {
F_5 ( V_20 , L_153 ) ;
F_11 ( V_400 -> V_348 ) ;
V_400 -> V_348 = NULL ;
} else if ( V_400 -> V_348 ) {
F_5 ( V_20 , L_154 , V_400 -> V_348 ) ;
} else {
F_5 ( V_59 , L_155 ) ;
return - V_140 ;
}
if ( V_400 -> V_363 == NULL ) {
V_400 -> V_436 = F_205 () ;
} else {
V_400 -> V_436 = F_206 ( V_400 -> V_363 ) ;
if ( V_400 -> V_436 == NULL ) {
F_5 ( V_59 , L_156 ,
V_400 -> V_363 ) ;
return - V_583 ;
}
}
return V_3 ;
}
struct V_147 *
F_207 ( char * V_582 , const char * V_196 )
{
int V_3 ;
struct V_147 * V_400 ;
V_400 = F_35 ( sizeof( struct V_147 ) , V_141 ) ;
if ( ! V_400 )
return F_71 ( - V_83 ) ;
V_3 = F_204 ( V_400 , V_582 , V_196 ) ;
if ( V_3 ) {
F_197 ( V_400 ) ;
V_400 = F_71 ( V_3 ) ;
}
return V_400 ;
}
int
F_208 ( struct V_462 * V_463 , struct V_147 * V_400 )
{
int V_3 ;
unsigned int V_418 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_575 ;
struct V_456 * V_457 ;
#ifdef F_209
int V_584 = 0 ;
#endif
V_3 = F_210 ( & V_463 -> V_585 , L_157 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_209
V_586:
if ( V_584 ) {
if ( V_10 )
F_161 ( V_10 ) ;
else if ( V_8 )
F_143 ( V_8 ) ;
V_463 -> V_472 &= ~ V_538 ;
F_156 ( V_418 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_575 = NULL ;
V_457 = NULL ;
V_418 = F_144 () ;
V_2 = F_124 ( V_400 ) ;
if ( F_127 ( V_2 ) ) {
V_3 = F_128 ( V_2 ) ;
F_211 ( & V_463 -> V_585 ) ;
goto V_480;
}
V_8 = F_154 ( V_2 , V_400 ) ;
if ( F_127 ( V_8 ) ) {
V_3 = F_128 ( V_8 ) ;
V_8 = NULL ;
goto V_587;
}
#ifdef F_4
if ( ( V_400 -> V_325 == true ) && ( ( V_8 -> V_2 -> V_451 &
V_452 ) == 0 ) ) {
F_5 ( V_59 , L_158 ) ;
V_3 = - V_450 ;
goto V_587;
}
#endif
V_10 = F_164 ( V_8 , V_400 ) ;
if ( F_127 ( V_10 ) ) {
V_3 = F_128 ( V_10 ) ;
V_10 = NULL ;
goto V_588;
}
if ( F_212 ( V_10 -> V_8 ) ) {
F_190 ( V_418 , V_10 , V_463 , V_400 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_191 ( V_10 -> V_529 . V_530 ) &
V_535 ) ) {
V_3 = - V_589 ;
goto V_587;
}
} else
V_10 -> V_531 = 0 ;
if ( ! V_10 -> V_590 && V_2 -> V_49 -> V_591 )
V_2 -> V_49 -> V_591 ( V_418 , V_10 ) ;
V_463 -> V_344 = V_2 -> V_49 -> V_592 ( V_10 , V_400 ) ;
V_463 -> V_342 = V_2 -> V_49 -> V_593 ( V_10 , V_400 ) ;
V_463 -> V_585 . V_594 = V_463 -> V_342 / V_595 ;
V_588:
#ifdef F_209
if ( V_584 == 0 ) {
int V_596 = F_200 ( V_418 , V_8 , V_400 , V_463 ,
false ) ;
if ( ! V_596 ) {
V_584 ++ ;
goto V_586;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_49 -> V_597 ) {
V_3 = - V_55 ;
goto V_587;
}
V_575 = F_213 ( V_400 , V_463 , V_10 ) ;
if ( V_575 == NULL ) {
V_3 = - V_83 ;
goto V_587;
}
V_3 = V_2 -> V_49 -> V_597 ( V_418 , V_10 , V_463 ,
V_575 ) ;
if ( V_3 != 0 && V_3 != - V_598 ) {
F_11 ( V_575 ) ;
goto V_587;
}
F_11 ( V_575 ) ;
}
if ( V_3 == - V_598 ) {
#ifdef F_209
if ( V_584 > V_599 ) {
V_3 = - V_600 ;
goto V_587;
}
V_3 = F_200 ( V_418 , V_8 , V_400 , V_463 , true ) ;
if ( ! V_3 ) {
V_584 ++ ;
goto V_586;
}
goto V_587;
#else
V_3 = - V_450 ;
#endif
}
if ( V_3 )
goto V_587;
V_457 = F_100 ( sizeof *V_457 , V_141 ) ;
if ( V_457 == NULL ) {
V_3 = - V_83 ;
goto V_587;
}
V_457 -> V_601 = V_8 -> V_224 ;
V_457 -> V_602 = V_10 ;
V_457 -> V_461 = V_38 ;
F_214 ( V_603 , & V_457 -> V_460 ) ;
F_214 ( V_459 , & V_457 -> V_460 ) ;
V_463 -> V_464 = V_457 ;
F_2 ( & V_463 -> V_548 ) ;
F_215 ( & V_463 -> V_549 , V_457 ) ;
F_3 ( & V_463 -> V_548 ) ;
F_24 ( V_57 , & V_463 -> V_546 ,
V_604 ) ;
V_587:
if ( V_3 ) {
if ( V_10 )
F_161 ( V_10 ) ;
else if ( V_8 )
F_143 ( V_8 ) ;
else
F_118 ( V_2 ) ;
F_211 ( & V_463 -> V_585 ) ;
}
V_480:
F_156 ( V_418 ) ;
return V_3 ;
}
int
F_216 ( const unsigned int V_418 , struct V_7 * V_8 ,
const char * V_605 , struct V_9 * V_10 ,
const struct V_482 * V_483 )
{
struct V_501 * V_606 ;
struct V_501 * V_607 ;
T_8 * V_608 ;
T_9 * V_609 ;
unsigned char * V_610 ;
int V_3 = 0 ;
int V_78 ;
T_10 V_611 , V_612 ;
if ( V_8 == NULL )
return - V_613 ;
V_606 = F_26 () ;
if ( V_606 == NULL )
return - V_83 ;
V_607 = V_606 ;
F_217 ( V_606 , V_614 ,
NULL , 4 ) ;
V_606 -> V_615 = F_218 ( V_8 -> V_2 ) ;
V_606 -> V_616 = V_8 -> V_617 ;
V_608 = ( T_8 * ) V_606 ;
V_609 = ( T_9 * ) V_607 ;
V_608 -> V_618 = 0xFF ;
V_608 -> V_446 = F_219 ( V_619 ) ;
V_610 = & V_608 -> V_620 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_621 & V_622 ) ) {
V_608 -> V_623 = F_219 ( 1 ) ;
* V_610 = 0 ;
V_610 ++ ;
} else {
V_608 -> V_623 = F_219 ( V_624 ) ;
#ifdef F_84
if ( ( V_625 & V_626 ) &&
( V_8 -> V_150 == V_168 ) )
F_220 ( V_10 -> V_353 , V_8 -> V_2 -> V_627 ,
V_8 -> V_2 -> V_621 &
V_628 ? true : false ,
V_610 ) ;
else
#endif
V_3 = F_221 ( V_10 -> V_353 , V_8 -> V_2 -> V_627 ,
V_610 , V_483 ) ;
if ( V_3 ) {
F_5 ( V_20 , L_159 ,
V_21 , V_3 ) ;
F_63 ( V_606 ) ;
return V_3 ;
}
V_610 += V_624 ;
if ( V_8 -> V_451 & V_629 ) {
* V_610 = 0 ;
V_610 ++ ;
}
}
if ( V_8 -> V_2 -> V_152 )
V_606 -> V_630 |= V_631 ;
if ( V_8 -> V_451 & V_632 ) {
V_606 -> V_630 |= V_633 ;
}
if ( V_8 -> V_451 & V_634 ) {
V_606 -> V_630 |= V_635 ;
}
if ( V_8 -> V_451 & V_629 ) {
V_606 -> V_630 |= V_636 ;
V_78 =
F_222 ( ( V_637 * ) V_610 , V_605 ,
6 *
( + 256 ) , V_483 ) ;
V_610 += 2 * V_78 ;
V_610 += 2 ;
} else {
strcpy ( V_610 , V_605 ) ;
V_610 += strlen ( V_605 ) + 1 ;
}
strcpy ( V_610 , L_160 ) ;
V_610 += strlen ( L_160 ) ;
V_610 += 1 ;
V_612 = V_610 - & V_608 -> V_620 [ 0 ] ;
V_608 -> V_638 . V_512 = F_186 ( F_223 (
V_608 -> V_638 . V_512 ) + V_612 ) ;
V_608 -> V_639 = F_219 ( V_612 ) ;
V_3 = F_224 ( V_418 , V_8 , V_606 , V_607 , & V_78 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_640 ;
V_10 -> V_439 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_641 = V_607 -> V_642 ;
V_610 = F_225 ( V_607 ) ;
V_611 = F_226 ( V_607 ) ;
V_78 = F_94 ( V_610 , V_611 - 2 ) ;
if ( V_606 -> V_630 & V_636 )
V_640 = true ;
else
V_640 = false ;
if ( V_78 == 3 ) {
if ( ( V_610 [ 0 ] == 'I' ) && ( V_610 [ 1 ] == 'P' ) &&
( V_610 [ 2 ] == 'C' ) ) {
F_5 ( V_20 , L_161 ) ;
V_10 -> V_590 = 1 ;
}
} else if ( V_78 == 2 ) {
if ( ( V_610 [ 0 ] == 'A' ) && ( V_610 [ 1 ] == ':' ) ) {
F_5 ( V_20 , L_162 ) ;
}
}
V_610 += V_78 + 1 ;
V_611 -= ( V_78 + 1 ) ;
F_227 ( V_10 -> V_440 , V_605 , sizeof( V_10 -> V_440 ) ) ;
F_11 ( V_10 -> V_643 ) ;
V_10 -> V_643 = F_228 ( V_610 ,
V_611 , V_640 ,
V_483 ) ;
F_5 ( V_20 , L_163 , V_10 -> V_643 ) ;
if ( ( V_607 -> V_644 == 3 ) ||
( V_607 -> V_644 == 7 ) )
V_10 -> V_446 = F_229 ( V_609 -> V_645 ) ;
else
V_10 -> V_446 = 0 ;
F_5 ( V_20 , L_164 , V_10 -> V_446 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_607 -> V_642 ;
}
F_63 ( V_606 ) ;
return V_3 ;
}
static void F_230 ( struct V_646 * V_122 )
{
struct V_462 * V_647 = F_22 ( V_122 , struct V_462 , V_648 ) ;
F_231 ( V_647 -> V_436 ) ;
F_11 ( V_647 ) ;
}
void
F_232 ( struct V_462 * V_463 )
{
struct V_649 * V_650 = & V_463 -> V_549 ;
struct V_651 * V_652 ;
struct V_456 * V_457 ;
F_120 ( & V_463 -> V_546 ) ;
F_2 ( & V_463 -> V_548 ) ;
while ( ( V_652 = F_233 ( V_650 ) ) ) {
V_457 = F_234 ( V_652 , struct V_456 , V_653 ) ;
F_176 ( V_457 ) ;
F_235 ( V_459 , & V_457 -> V_460 ) ;
F_236 ( V_652 , V_650 ) ;
F_3 ( & V_463 -> V_548 ) ;
F_167 ( V_457 ) ;
F_2 ( & V_463 -> V_548 ) ;
}
F_3 ( & V_463 -> V_548 ) ;
F_211 ( & V_463 -> V_585 ) ;
F_11 ( V_463 -> V_201 ) ;
F_237 ( & V_463 -> V_648 , F_230 ) ;
}
int
F_155 ( const unsigned int V_418 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_49 -> V_50 || ! V_2 -> V_49 -> V_654 )
return - V_55 ;
if ( ! V_2 -> V_49 -> V_50 ( V_2 ) )
return 0 ;
F_238 ( V_2 , 1 ) ;
V_3 = V_2 -> V_49 -> V_654 ( V_418 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_655 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_157 ( const unsigned int V_418 , struct V_7 * V_8 ,
struct V_482 * V_656 )
{
int V_3 = - V_55 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_451 = V_2 -> V_451 ;
if ( V_657 == 0 )
V_8 -> V_451 &= ( ~ V_2 -> V_180 -> F_212 ) ;
F_5 ( V_20 , L_165 ,
V_2 -> V_621 , V_2 -> V_451 , V_2 -> V_658 ) ;
if ( V_2 -> V_49 -> V_659 )
V_3 = V_2 -> V_49 -> V_659 ( V_418 , V_8 , V_656 ) ;
if ( V_3 )
F_5 ( V_59 , L_166 , V_3 ) ;
return V_3 ;
}
static int
F_239 ( struct V_147 * V_148 , struct V_7 * V_8 )
{
V_148 -> V_150 = V_8 -> V_150 ;
if ( V_148 -> V_150 == V_157 )
return 0 ;
return F_147 ( V_148 , V_8 ) ;
}
static struct V_9 *
F_240 ( struct V_462 * V_463 , T_3 V_660 )
{
int V_3 ;
struct V_9 * V_661 = F_241 ( V_463 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_147 * V_527 ;
V_527 = F_100 ( sizeof( * V_527 ) , V_141 ) ;
if ( V_527 == NULL )
return F_71 ( - V_83 ) ;
V_527 -> V_436 = V_463 -> V_436 ;
V_527 -> V_224 = V_660 ;
V_527 -> V_223 = V_660 ;
V_527 -> V_199 = V_661 -> V_440 ;
V_527 -> V_255 = V_661 -> V_255 ;
V_527 -> V_275 = V_661 -> V_275 ;
V_527 -> V_309 = V_661 -> V_309 ;
V_527 -> V_273 = ! V_661 -> V_531 ;
V_527 -> V_150 = V_661 -> V_8 -> V_150 ;
V_527 -> V_152 = V_661 -> V_8 -> V_152 ;
V_3 = F_239 ( V_527 , V_661 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_71 ( V_3 ) ;
goto V_480;
}
F_2 ( & V_22 ) ;
++ V_661 -> V_8 -> V_2 -> V_397 ;
F_3 ( & V_22 ) ;
V_8 = F_154 ( V_661 -> V_8 -> V_2 , V_527 ) ;
if ( F_127 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_118 ( V_661 -> V_8 -> V_2 ) ;
goto V_480;
}
V_10 = F_164 ( V_8 , V_527 ) ;
if ( F_127 ( V_10 ) ) {
F_143 ( V_8 ) ;
goto V_480;
}
if ( F_212 ( V_8 ) )
F_190 ( 0 , V_10 , NULL , V_527 ) ;
V_480:
F_11 ( V_527 -> V_348 ) ;
F_11 ( V_527 -> V_353 ) ;
F_11 ( V_527 ) ;
return V_10 ;
}
struct V_9 *
F_241 ( struct V_462 * V_463 )
{
return F_170 ( F_171 ( V_463 ) ) ;
}
static struct V_456 *
F_242 ( struct V_649 * V_650 , T_3 V_145 )
{
struct V_651 * V_652 = V_650 -> V_651 ;
struct V_456 * V_457 ;
while ( V_652 ) {
V_457 = F_234 ( V_652 , struct V_456 , V_653 ) ;
if ( F_243 ( V_457 -> V_601 , V_145 ) )
V_652 = V_652 -> V_662 ;
else if ( F_244 ( V_457 -> V_601 , V_145 ) )
V_652 = V_652 -> V_663 ;
else
return V_457 ;
}
return NULL ;
}
static void
F_215 ( struct V_649 * V_650 , struct V_456 * V_664 )
{
struct V_651 * * V_65 = & ( V_650 -> V_651 ) , * V_665 = NULL ;
struct V_456 * V_457 ;
while ( * V_65 ) {
V_457 = F_234 ( * V_65 , struct V_456 , V_653 ) ;
V_665 = * V_65 ;
if ( F_243 ( V_457 -> V_601 , V_664 -> V_601 ) )
V_65 = & ( ( * V_65 ) -> V_662 ) ;
else
V_65 = & ( ( * V_65 ) -> V_663 ) ;
}
F_245 ( & V_664 -> V_653 , V_665 , V_65 ) ;
F_246 ( & V_664 -> V_653 , V_650 ) ;
}
struct V_456 *
F_247 ( struct V_462 * V_463 )
{
int V_666 ;
T_3 V_660 = F_248 () ;
struct V_456 * V_457 , * V_667 ;
if ( ! ( V_463 -> V_472 & V_571 ) )
return F_176 ( F_171 ( V_463 ) ) ;
F_2 ( & V_463 -> V_548 ) ;
V_457 = F_242 ( & V_463 -> V_549 , V_660 ) ;
if ( V_457 )
F_176 ( V_457 ) ;
F_3 ( & V_463 -> V_548 ) ;
if ( V_457 == NULL ) {
V_667 = F_100 ( sizeof( * V_457 ) , V_141 ) ;
if ( V_667 == NULL )
return F_71 ( - V_83 ) ;
V_667 -> V_601 = V_660 ;
V_667 -> V_602 = F_71 ( - V_589 ) ;
F_214 ( V_668 , & V_667 -> V_460 ) ;
F_214 ( V_459 , & V_667 -> V_460 ) ;
F_176 ( V_667 ) ;
F_2 ( & V_463 -> V_548 ) ;
V_457 = F_242 ( & V_463 -> V_549 , V_660 ) ;
if ( V_457 ) {
F_176 ( V_457 ) ;
F_3 ( & V_463 -> V_548 ) ;
F_11 ( V_667 ) ;
goto V_669;
}
V_457 = V_667 ;
F_215 ( & V_463 -> V_549 , V_457 ) ;
F_3 ( & V_463 -> V_548 ) ;
} else {
V_669:
V_666 = F_249 ( & V_457 -> V_460 , V_668 ,
V_134 ) ;
if ( V_666 ) {
F_167 ( V_457 ) ;
return F_71 ( - V_88 ) ;
}
if ( ! F_127 ( V_457 -> V_602 ) )
return V_457 ;
if ( F_23 ( V_38 , V_457 -> V_461 + V_670 ) ) {
F_167 ( V_457 ) ;
return F_71 ( - V_589 ) ;
}
if ( F_250 ( V_668 , & V_457 -> V_460 ) )
goto V_669;
}
V_457 -> V_602 = F_240 ( V_463 , V_660 ) ;
F_235 ( V_668 , & V_457 -> V_460 ) ;
F_251 ( & V_457 -> V_460 , V_668 ) ;
if ( F_127 ( V_457 -> V_602 ) ) {
F_167 ( V_457 ) ;
return F_71 ( - V_589 ) ;
}
return V_457 ;
}
static void
V_547 ( struct V_46 * V_47 )
{
struct V_462 * V_463 = F_22 ( V_47 , struct V_462 ,
V_546 . V_47 ) ;
struct V_649 * V_650 = & V_463 -> V_549 ;
struct V_651 * V_652 = F_233 ( V_650 ) ;
struct V_651 * V_5 ;
struct V_456 * V_457 ;
F_2 ( & V_463 -> V_548 ) ;
V_652 = F_233 ( V_650 ) ;
while ( V_652 != NULL ) {
V_5 = V_652 ;
V_652 = F_252 ( V_5 ) ;
V_457 = F_234 ( V_5 , struct V_456 , V_653 ) ;
if ( F_169 ( V_603 , & V_457 -> V_460 ) ||
F_60 ( & V_457 -> V_458 ) != 0 ||
F_30 ( V_457 -> V_461 + V_604 , V_38 ) )
continue;
F_176 ( V_457 ) ;
F_235 ( V_459 , & V_457 -> V_460 ) ;
F_236 ( V_5 , V_650 ) ;
F_3 ( & V_463 -> V_548 ) ;
F_167 ( V_457 ) ;
F_2 ( & V_463 -> V_548 ) ;
}
F_3 ( & V_463 -> V_548 ) ;
F_24 ( V_57 , & V_463 -> V_546 ,
V_604 ) ;
}
