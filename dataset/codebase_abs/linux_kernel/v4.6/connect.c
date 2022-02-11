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
return V_3 ;
}
static void
F_21 ( struct V_46 * V_47 )
{
int V_3 ;
struct V_1 * V_2 = F_22 ( V_47 ,
struct V_1 , V_48 . V_47 ) ;
unsigned long V_49 = V_2 -> V_49 ;
if ( ! V_2 -> V_50 -> V_51 || V_2 -> V_50 -> V_51 ( V_2 ) ||
( V_2 -> V_50 -> V_52 && ! V_2 -> V_50 -> V_52 ( V_2 ) ) ||
F_23 ( V_38 , V_2 -> V_37 + V_49 - V_53 ) )
goto V_54;
V_3 = V_2 -> V_50 -> V_48 ? V_2 -> V_50 -> V_48 ( V_2 ) : - V_55 ;
if ( V_3 )
F_5 ( V_20 , L_9 ,
V_2 -> V_56 ) ;
V_54:
F_24 ( V_57 , & V_2 -> V_48 , V_49 ) ;
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
F_30 ( V_38 , V_2 -> V_37 + 2 * V_2 -> V_49 ) ) {
F_5 ( V_59 , L_12 ,
V_2 -> V_56 , ( 2 * V_2 -> V_49 ) / V_53 ) ;
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
if ( V_2 -> V_50 -> V_104 &&
V_2 -> V_50 -> V_104 ( V_99 , V_2 , V_91 , V_100 ) )
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
F_12 ( & V_112 ) ;
F_2 ( & V_14 ) ;
F_13 (tmp, tmp2, &server->pending_mid_q) {
V_12 = F_7 ( V_5 , struct V_11 , V_39 ) ;
F_5 ( V_20 , L_19 , V_12 -> V_99 ) ;
V_12 -> V_40 = V_113 ;
F_14 ( & V_12 -> V_39 , & V_112 ) ;
}
F_3 ( & V_14 ) ;
F_13 (tmp, tmp2, &dispose_list) {
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
V_78 = V_2 -> V_50 -> V_120 ( V_91 , V_2 -> V_79 , V_2 ) ;
if ( V_78 != 0 )
F_54 ( L_23 , V_91 ,
F_55 (unsigned int, server->total_read, 48 ) ) ;
if ( V_2 -> V_50 -> V_121 &&
V_2 -> V_50 -> V_121 ( V_91 , V_2 , V_78 ) )
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
V_12 = V_2 -> V_50 -> V_127 ( V_2 , V_91 ) ;
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
} else if ( ! V_2 -> V_50 -> V_130 ||
! V_2 -> V_50 -> V_130 ( V_91 , V_2 ) ) {
F_5 ( V_59 , L_27 ,
F_60 ( & V_131 ) ) ;
F_54 ( L_28 , V_91 ,
F_27 ( V_2 ) ) ;
#ifdef F_61
if ( V_2 -> V_50 -> V_132 )
V_2 -> V_50 -> V_132 ( V_91 ) ;
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
V_148 -> V_50 = & V_179 ;
V_148 -> V_180 = & V_181 ;
break;
#ifdef F_4
case V_182 :
V_148 -> V_50 = & V_183 ;
V_148 -> V_180 = & V_184 ;
break;
case V_185 :
V_148 -> V_50 = & V_186 ;
V_148 -> V_180 = & V_187 ;
break;
case V_188 :
V_148 -> V_50 = & V_189 ;
V_148 -> V_180 = & V_190 ;
break;
case V_191 :
V_148 -> V_50 = & V_189 ;
V_148 -> V_180 = & V_192 ;
break;
#ifdef F_87
case V_193 :
V_148 -> V_50 = & V_194 ;
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
V_148 -> V_50 = & V_179 ;
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
if ( F_72 ( args , & V_142 ) ) {
F_5 ( V_59 , L_54 ,
V_21 ) ;
goto V_236;
}
V_148 -> V_49 = V_142 ;
break;
case V_348 :
V_148 -> V_170 = 1 ;
V_148 -> V_349 = NULL ;
break;
case V_350 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_351;
if ( F_94 ( string , V_352 ) >
V_352 ) {
F_98 ( L_55 ) ;
goto V_236;
}
F_11 ( V_148 -> V_349 ) ;
V_148 -> V_349 = F_91 ( string , V_141 ) ;
if ( ! V_148 -> V_349 )
goto V_236;
break;
case V_353 :
V_217 = strchr ( V_202 , '=' ) ;
V_217 ++ ;
if ( ! ( V_217 < V_203 && V_217 [ 1 ] == V_139 ) ) {
F_11 ( V_148 -> V_354 ) ;
V_148 -> V_354 = NULL ;
break;
}
case V_355 :
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
F_11 ( V_148 -> V_354 ) ;
V_206 = strlen ( V_144 ) ;
V_148 -> V_354 = F_100 ( V_206 + 1 , V_141 ) ;
if ( V_148 -> V_354 == NULL ) {
F_98 ( L_56 ) ;
goto V_236;
}
for ( V_207 = 0 , V_208 = 0 ; V_207 < V_206 ; V_207 ++ , V_208 ++ ) {
V_148 -> V_354 [ V_208 ] = V_144 [ V_207 ] ;
if ( ( V_144 [ V_207 ] == V_139 ) &&
V_144 [ V_207 + 1 ] == V_139 )
V_207 ++ ;
}
V_148 -> V_354 [ V_208 ] = '\0' ;
break;
case V_356 :
V_218 = false ;
break;
case V_357 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_351;
if ( ! F_101 ( V_97 , string ,
strlen ( string ) ) ) {
F_102 ( L_57 , string ) ;
goto V_236;
}
V_218 = true ;
break;
case V_358 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_351;
if ( F_94 ( string , V_359 )
== V_359 ) {
F_98 ( L_58 ) ;
goto V_236;
}
F_11 ( V_148 -> V_360 ) ;
V_148 -> V_360 = F_91 ( string , V_141 ) ;
if ( ! V_148 -> V_360 ) {
F_98 ( L_59 ) ;
goto V_236;
}
F_5 ( V_20 , L_60 ) ;
break;
case V_361 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_351;
if ( ! F_101 (
(struct V_96 * ) & V_148 -> V_362 ,
string , strlen ( string ) ) ) {
F_98 ( L_61 ,
string ) ;
goto V_236;
}
break;
case V_363 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_351;
if ( F_94 ( string , 1024 ) >= 65 ) {
F_98 ( L_62 ) ;
goto V_236;
}
if ( strncasecmp ( string , L_63 , 7 ) != 0 ) {
F_11 ( V_148 -> V_364 ) ;
V_148 -> V_364 = F_91 ( string ,
V_141 ) ;
if ( ! V_148 -> V_364 ) {
F_98 ( L_64 ) ;
goto V_236;
}
}
F_5 ( V_20 , L_65 , string ) ;
break;
case V_365 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_351;
memset ( V_148 -> V_220 , 0x20 ,
V_221 ) ;
for ( V_207 = 0 ; V_207 < V_221 ; V_207 ++ ) {
if ( string [ V_207 ] == 0 )
break;
V_148 -> V_220 [ V_207 ] = string [ V_207 ] ;
}
if ( V_207 == V_221 && string [ V_207 ] != 0 )
F_98 ( L_66 ) ;
break;
case V_366 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_351;
memset ( V_148 -> V_222 , 0x20 ,
V_367 ) ;
for ( V_207 = 0 ; V_207 < 15 ; V_207 ++ ) {
if ( string [ V_207 ] == 0 )
break;
V_148 -> V_222 [ V_207 ] = string [ V_207 ] ;
}
if ( V_207 == V_221 && string [ V_207 ] != 0 )
F_98 ( L_67 ) ;
break;
case V_368 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_351;
if ( strncasecmp ( string , L_68 , 1 ) == 0 ) {
break;
}
F_98 ( L_69 ) ;
goto V_236;
case V_369 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_351;
if ( F_86 ( string , V_148 ) != 0 )
goto V_236;
break;
case V_370 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_351;
if ( F_82 ( string , V_148 ) != 0 )
goto V_236;
break;
case V_371 :
string = F_73 ( args ) ;
if ( string == NULL )
goto V_351;
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
F_102 ( L_70 , V_215 ) ;
goto V_236;
}
#ifndef F_103
if ( V_148 -> V_319 ) {
F_5 ( V_59 , L_71 ) ;
goto V_236;
}
#endif
if ( ! V_148 -> V_199 ) {
F_5 ( V_59 , L_72 ) ;
goto V_236;
}
if ( ! strchr ( V_148 -> V_199 + 3 , '\\' ) ) {
F_5 ( V_59 , L_73 ) ;
goto V_236;
}
if ( ! V_218 ) {
if ( ! F_101 ( V_97 , & V_148 -> V_199 [ 2 ] ,
strlen ( & V_148 -> V_199 [ 2 ] ) ) ) {
F_102 ( L_74 ) ;
goto V_236;
}
}
F_41 ( V_97 , V_219 ) ;
if ( V_212 )
V_148 -> V_210 = V_210 ;
else if ( V_210 == 1 )
F_104 ( L_75 ) ;
if ( V_213 )
V_148 -> V_211 = V_211 ;
else if ( V_211 == 1 )
F_104 ( L_76 ) ;
F_11 ( V_204 ) ;
return 0 ;
V_351:
F_98 ( L_77 ) ;
V_236:
F_11 ( string ) ;
F_11 ( V_204 ) ;
return 1 ;
}
static bool
F_105 ( struct V_96 * V_362 , struct V_96 * V_372 )
{
switch ( V_362 -> V_373 ) {
case V_374 :
return ( V_372 -> V_373 == V_374 ) ;
case V_375 : {
struct V_376 * V_377 = (struct V_376 * ) V_362 ;
struct V_376 * V_378 = (struct V_376 * ) V_372 ;
return ( V_377 -> V_379 . V_380 == V_378 -> V_379 . V_380 ) ;
}
case V_381 : {
struct V_382 * V_383 = (struct V_382 * ) V_362 ;
struct V_382 * V_384 = (struct V_382 * ) V_372 ;
return F_106 ( & V_383 -> V_385 , & V_384 -> V_385 ) ;
}
default:
F_107 ( 1 ) ;
return false ;
}
}
static bool
F_108 ( struct V_1 * V_2 , struct V_96 * V_386 )
{
T_5 V_219 , * V_387 ;
switch ( V_386 -> V_373 ) {
case V_375 :
V_387 = & ( (struct V_376 * ) & V_2 -> V_97 ) -> V_388 ;
V_219 = ( (struct V_376 * ) V_386 ) -> V_388 ;
break;
case V_381 :
V_387 = & ( (struct V_382 * ) & V_2 -> V_97 ) -> V_389 ;
V_219 = ( (struct V_382 * ) V_386 ) -> V_389 ;
break;
default:
F_107 ( 1 ) ;
return false ;
}
if ( ! V_219 ) {
V_219 = F_109 ( V_98 ) ;
if ( V_219 == * V_387 )
return true ;
V_219 = F_109 ( V_390 ) ;
}
return V_219 == * V_387 ;
}
static bool
F_110 ( struct V_1 * V_2 , struct V_96 * V_386 ,
struct V_96 * V_362 )
{
switch ( V_386 -> V_373 ) {
case V_375 : {
struct V_376 * V_391 = (struct V_376 * ) V_386 ;
struct V_376 * V_392 =
(struct V_376 * ) & V_2 -> V_97 ;
if ( V_391 -> V_379 . V_380 != V_392 -> V_379 . V_380 )
return false ;
break;
}
case V_381 : {
struct V_382 * V_393 = (struct V_382 * ) V_386 ;
struct V_382 * V_394 =
(struct V_382 * ) & V_2 -> V_97 ;
if ( ! F_106 ( & V_393 -> V_385 ,
& V_394 -> V_385 ) )
return false ;
if ( V_393 -> V_395 != V_394 -> V_395 )
return false ;
break;
}
default:
F_107 ( 1 ) ;
return false ;
}
if ( ! F_105 ( V_362 , (struct V_96 * ) & V_2 -> V_362 ) )
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
struct V_96 * V_386 = (struct V_96 * ) & V_148 -> V_97 ;
if ( V_148 -> V_322 )
return 0 ;
if ( ( V_2 -> V_180 != V_148 -> V_180 ) || ( V_2 -> V_50 != V_148 -> V_50 ) )
return 0 ;
if ( ! F_114 ( F_115 ( V_2 ) , V_125 -> V_396 -> V_397 ) )
return 0 ;
if ( ! F_110 ( V_2 , V_386 ,
(struct V_96 * ) & V_148 -> V_362 ) )
return 0 ;
if ( ! F_108 ( V_2 , V_386 ) )
return 0 ;
if ( ! F_111 ( V_2 , V_148 ) )
return 0 ;
if ( V_2 -> V_49 != V_148 -> V_49 )
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
++ V_2 -> V_398 ;
F_3 ( & V_22 ) ;
F_5 ( V_20 , L_78 ) ;
return V_2 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_118 ( struct V_1 * V_2 )
{
struct V_123 * V_399 ;
F_2 ( & V_22 ) ;
if ( -- V_2 -> V_398 > 0 ) {
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
V_399 = F_65 ( & V_2 -> V_133 , NULL ) ;
if ( V_399 )
F_123 ( V_400 , V_399 ) ;
}
static struct V_1 *
F_124 ( struct V_147 * V_401 )
{
struct V_1 * V_402 = NULL ;
int V_3 ;
F_5 ( V_20 , L_79 , V_401 -> V_199 ) ;
V_402 = F_116 ( V_401 ) ;
if ( V_402 )
return V_402 ;
V_402 = F_100 ( sizeof( struct V_1 ) , V_141 ) ;
if ( ! V_402 ) {
V_3 = - V_83 ;
goto V_403;
}
V_402 -> V_50 = V_401 -> V_50 ;
V_402 -> V_180 = V_401 -> V_180 ;
F_125 ( V_402 , F_126 ( V_125 -> V_396 -> V_397 ) ) ;
V_402 -> V_56 = F_70 ( V_401 -> V_199 ) ;
if ( F_127 ( V_402 -> V_56 ) ) {
V_3 = F_128 ( V_402 -> V_56 ) ;
goto V_404;
}
V_402 -> V_251 = V_401 -> V_251 ;
V_402 -> V_253 = V_401 -> V_253 ;
V_402 -> V_405 = V_401 -> V_406 ;
V_402 -> V_407 = 0 ;
V_402 -> V_109 = 1 ;
F_129 ( & V_402 -> V_63 ) ;
F_129 ( & V_402 -> V_110 ) ;
F_12 ( & V_402 -> V_111 ) ;
F_130 ( & V_402 -> V_27 ) ;
memcpy ( V_402 -> V_408 ,
V_401 -> V_220 , V_367 ) ;
memcpy ( V_402 -> V_409 ,
V_401 -> V_222 , V_367 ) ;
V_402 -> V_33 = false ;
V_402 -> V_32 = 0 ;
V_402 -> V_37 = V_38 ;
F_131 ( & V_402 -> V_108 ) ;
F_12 ( & V_402 -> V_107 ) ;
F_12 ( & V_402 -> V_23 ) ;
F_132 ( & V_402 -> V_48 , F_21 ) ;
memcpy ( & V_402 -> V_362 , & V_401 -> V_362 ,
sizeof( V_402 -> V_362 ) ) ;
memcpy ( & V_402 -> V_97 , & V_401 -> V_97 ,
sizeof( V_402 -> V_97 ) ) ;
#ifdef F_4
F_133 ( V_402 -> V_410 , V_411 ) ;
#endif
V_402 -> V_15 = V_412 ;
++ V_402 -> V_398 ;
if ( V_401 -> V_49 >= V_413 &&
V_401 -> V_49 <= V_414 )
V_402 -> V_49 = V_401 -> V_49 * V_53 ;
else
V_402 -> V_49 = V_415 * V_53 ;
V_3 = F_134 ( V_402 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_80 ) ;
goto V_404;
}
F_135 ( V_416 ) ;
V_402 -> V_133 = F_136 ( F_56 ,
V_402 , L_81 ) ;
if ( F_127 ( V_402 -> V_133 ) ) {
V_3 = F_128 ( V_402 -> V_133 ) ;
F_5 ( V_59 , L_82 , V_3 ) ;
F_137 ( V_416 ) ;
goto V_404;
}
V_402 -> V_15 = V_45 ;
F_2 ( & V_22 ) ;
F_138 ( & V_402 -> V_107 , & V_417 ) ;
F_3 ( & V_22 ) ;
F_139 ( V_402 ) ;
F_24 ( V_57 , & V_402 -> V_48 , V_402 -> V_49 ) ;
return V_402 ;
V_404:
F_121 ( V_402 ) ;
F_119 ( F_115 ( V_402 ) ) ;
V_403:
if ( V_402 ) {
if ( ! F_127 ( V_402 -> V_56 ) )
F_11 ( V_402 -> V_56 ) ;
if ( V_402 -> V_28 )
F_10 ( V_402 -> V_28 ) ;
F_11 ( V_402 ) ;
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
if ( V_8 -> V_418 == NULL ) {
if ( ! V_148 -> V_170 )
return 0 ;
break;
}
if ( strncmp ( V_8 -> V_418 ,
V_148 -> V_349 ? V_148 -> V_349 : L_83 ,
V_352 ) )
return 0 ;
if ( ( V_148 -> V_349 && strlen ( V_148 -> V_349 ) != 0 ) &&
V_8 -> V_354 != NULL &&
strncmp ( V_8 -> V_354 ,
V_148 -> V_354 ? V_148 -> V_354 : L_83 ,
V_419 ) )
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
if ( V_8 -> V_420 == V_16 )
continue;
if ( ! F_140 ( V_8 , V_148 ) )
continue;
++ V_8 -> V_421 ;
F_3 ( & V_22 ) ;
return V_8 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_143 ( struct V_7 * V_8 )
{
unsigned int V_3 , V_422 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_20 , L_84 , V_21 , V_8 -> V_421 ) ;
F_2 ( & V_22 ) ;
if ( V_8 -> V_420 == V_16 ) {
F_3 ( & V_22 ) ;
return;
}
if ( -- V_8 -> V_421 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
if ( V_8 -> V_420 == V_62 )
V_8 -> V_420 = V_16 ;
F_3 ( & V_22 ) ;
if ( V_8 -> V_420 == V_16 && V_2 -> V_50 -> V_423 ) {
V_422 = F_144 () ;
V_3 = V_2 -> V_50 -> V_423 ( V_422 , V_8 ) ;
if ( V_3 )
F_5 ( V_59 , L_85 ,
V_21 , V_3 ) ;
F_145 ( V_422 ) ;
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
const char * V_139 , * V_424 ;
char * V_425 ;
T_6 V_36 ;
struct V_426 * V_426 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_376 * V_427 ;
struct V_382 * V_428 ;
const struct V_429 * V_430 ;
V_425 = F_35 ( V_431 , V_141 ) ;
if ( ! V_425 )
return - V_83 ;
switch ( V_2 -> V_97 . V_432 ) {
case V_375 :
V_427 = (struct V_376 * ) & V_2 -> V_97 ;
sprintf ( V_425 , L_86 , & V_427 -> V_379 . V_380 ) ;
break;
case V_381 :
V_428 = (struct V_382 * ) & V_2 -> V_97 ;
sprintf ( V_425 , L_87 , & V_428 -> V_385 . V_433 ) ;
break;
default:
F_5 ( V_20 , L_88 ,
V_2 -> V_97 . V_432 ) ;
V_3 = - V_140 ;
goto V_403;
}
F_5 ( V_20 , L_89 , V_21 , V_425 ) ;
V_426 = F_148 ( & V_434 , V_425 , L_83 ) ;
if ( F_127 ( V_426 ) ) {
if ( ! V_8 -> V_435 ) {
F_5 ( V_20 , L_90 ) ;
V_3 = F_128 ( V_426 ) ;
goto V_403;
}
sprintf ( V_425 , L_91 , V_8 -> V_435 ) ;
F_5 ( V_20 , L_89 , V_21 , V_425 ) ;
V_426 = F_148 ( & V_434 , V_425 , L_83 ) ;
if ( F_127 ( V_426 ) ) {
V_3 = F_128 ( V_426 ) ;
goto V_403;
}
}
F_149 ( & V_426 -> V_436 ) ;
V_430 = V_429 ( V_426 ) ;
if ( F_150 ( V_430 ) ) {
V_3 = V_430 ? F_128 ( V_430 ) : - V_140 ;
goto V_437;
}
V_424 = V_430 -> V_202 ;
V_139 = F_151 ( V_424 , V_430 -> V_438 , ':' ) ;
F_5 ( V_20 , L_92 , V_424 ) ;
if ( ! V_139 ) {
F_5 ( V_20 , L_93 ,
V_430 -> V_438 ) ;
V_3 = - V_140 ;
goto V_437;
}
V_36 = V_139 - V_424 ;
if ( V_36 > V_352 || V_36 <= 0 ) {
F_5 ( V_20 , L_94 ,
V_36 ) ;
V_3 = - V_140 ;
goto V_437;
}
V_148 -> V_349 = F_89 ( V_424 , V_36 , V_141 ) ;
if ( ! V_148 -> V_349 ) {
F_5 ( V_20 , L_95 ,
V_36 ) ;
V_3 = - V_83 ;
goto V_437;
}
F_5 ( V_20 , L_96 , V_21 , V_148 -> V_349 ) ;
V_36 = V_426 -> V_438 - ( V_36 + 1 ) ;
if ( V_36 > V_419 || V_36 <= 0 ) {
F_5 ( V_20 , L_97 , V_36 ) ;
V_3 = - V_140 ;
F_11 ( V_148 -> V_349 ) ;
V_148 -> V_349 = NULL ;
goto V_437;
}
++ V_139 ;
V_148 -> V_354 = F_89 ( V_139 , V_36 , V_141 ) ;
if ( ! V_148 -> V_354 ) {
F_5 ( V_20 , L_98 ,
V_36 ) ;
V_3 = - V_83 ;
F_11 ( V_148 -> V_349 ) ;
V_148 -> V_349 = NULL ;
goto V_437;
}
V_437:
F_152 ( & V_426 -> V_436 ) ;
F_153 ( V_426 ) ;
V_403:
F_11 ( V_425 ) ;
F_5 ( V_20 , L_99 , V_21 , V_3 ) ;
return V_3 ;
}
static struct V_7 *
F_154 ( struct V_1 * V_2 , struct V_147 * V_401 )
{
int V_3 = - V_83 ;
unsigned int V_422 ;
struct V_7 * V_8 ;
struct V_376 * V_386 = (struct V_376 * ) & V_2 -> V_97 ;
struct V_382 * V_393 = (struct V_382 * ) & V_2 -> V_97 ;
V_422 = F_144 () ;
V_8 = F_142 ( V_2 , V_401 ) ;
if ( V_8 ) {
F_5 ( V_20 , L_100 ,
V_8 -> V_420 ) ;
F_8 ( & V_8 -> V_439 ) ;
V_3 = F_155 ( V_422 , V_8 ) ;
if ( V_3 ) {
F_15 ( & V_8 -> V_439 ) ;
F_143 ( V_8 ) ;
F_156 ( V_422 ) ;
return F_71 ( V_3 ) ;
}
if ( V_8 -> V_24 ) {
F_5 ( V_20 , L_101 ) ;
V_3 = F_157 ( V_422 , V_8 ,
V_401 -> V_440 ) ;
if ( V_3 ) {
F_15 ( & V_8 -> V_439 ) ;
F_143 ( V_8 ) ;
F_156 ( V_422 ) ;
return F_71 ( V_3 ) ;
}
}
F_15 ( & V_8 -> V_439 ) ;
F_118 ( V_2 ) ;
F_156 ( V_422 ) ;
return V_8 ;
}
F_5 ( V_20 , L_102 ) ;
V_8 = F_158 () ;
if ( V_8 == NULL )
goto V_441;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_97 . V_432 == V_381 )
sprintf ( V_8 -> V_442 , L_103 , & V_393 -> V_385 ) ;
else
sprintf ( V_8 -> V_442 , L_104 , & V_386 -> V_379 ) ;
if ( V_401 -> V_349 ) {
V_8 -> V_418 = F_91 ( V_401 -> V_349 , V_141 ) ;
if ( ! V_8 -> V_418 )
goto V_441;
}
if ( V_401 -> V_354 ) {
V_8 -> V_354 = F_91 ( V_401 -> V_354 , V_141 ) ;
if ( ! V_8 -> V_354 )
goto V_441;
}
if ( V_401 -> V_360 ) {
V_8 -> V_435 = F_91 ( V_401 -> V_360 , V_141 ) ;
if ( ! V_8 -> V_435 )
goto V_441;
}
V_8 -> V_223 = V_401 -> V_223 ;
V_8 -> V_224 = V_401 -> V_224 ;
V_8 -> V_150 = V_401 -> V_150 ;
V_8 -> V_152 = V_401 -> V_152 ;
F_8 ( & V_8 -> V_439 ) ;
V_3 = F_155 ( V_422 , V_8 ) ;
if ( ! V_3 )
V_3 = F_157 ( V_422 , V_8 , V_401 -> V_440 ) ;
F_15 ( & V_8 -> V_439 ) ;
if ( V_3 )
goto V_441;
F_2 ( & V_22 ) ;
F_138 ( & V_8 -> V_23 , & V_2 -> V_23 ) ;
F_3 ( & V_22 ) ;
F_156 ( V_422 ) ;
return V_8 ;
V_441:
F_146 ( V_8 ) ;
F_156 ( V_422 ) ;
return F_71 ( V_3 ) ;
}
static int F_159 ( struct V_9 * V_10 , const char * V_136 )
{
if ( V_10 -> V_443 == V_16 )
return 0 ;
if ( strncmp ( V_10 -> V_444 , V_136 , V_445 ) )
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
++ V_10 -> V_446 ;
F_3 ( & V_22 ) ;
return V_10 ;
}
F_3 ( & V_22 ) ;
return NULL ;
}
static void
F_161 ( struct V_9 * V_10 )
{
unsigned int V_422 ;
struct V_7 * V_8 = V_10 -> V_8 ;
F_5 ( V_20 , L_105 , V_21 , V_10 -> V_446 ) ;
F_2 ( & V_22 ) ;
if ( -- V_10 -> V_446 > 0 ) {
F_3 ( & V_22 ) ;
return;
}
F_16 ( & V_10 -> V_26 ) ;
F_3 ( & V_22 ) ;
V_422 = F_144 () ;
if ( V_8 -> V_2 -> V_50 -> V_447 )
V_8 -> V_2 -> V_50 -> V_447 ( V_422 , V_10 ) ;
F_145 ( V_422 ) ;
F_162 ( V_10 ) ;
F_163 ( V_10 ) ;
F_143 ( V_8 ) ;
}
static struct V_9 *
F_164 ( struct V_7 * V_8 , struct V_147 * V_401 )
{
int V_3 , V_422 ;
struct V_9 * V_10 ;
V_10 = F_160 ( V_8 , V_401 -> V_199 ) ;
if ( V_10 ) {
F_5 ( V_20 , L_106 ) ;
F_143 ( V_8 ) ;
if ( V_10 -> V_312 != V_401 -> V_312 )
F_5 ( V_59 , L_107 ) ;
return V_10 ;
}
if ( ! V_8 -> V_2 -> V_50 -> V_448 ) {
V_3 = - V_55 ;
goto V_449;
}
V_10 = F_165 () ;
if ( V_10 == NULL ) {
V_3 = - V_83 ;
goto V_449;
}
V_10 -> V_8 = V_8 ;
if ( V_401 -> V_354 ) {
V_10 -> V_354 = F_91 ( V_401 -> V_354 , V_141 ) ;
if ( ! V_10 -> V_354 ) {
V_3 = - V_83 ;
goto V_449;
}
}
V_422 = F_144 () ;
V_3 = V_8 -> V_2 -> V_50 -> V_448 ( V_422 , V_8 , V_401 -> V_199 , V_10 ,
V_401 -> V_440 ) ;
F_156 ( V_422 ) ;
F_5 ( V_20 , L_108 , V_3 ) ;
if ( V_3 )
goto V_449;
if ( V_401 -> V_269 ) {
V_10 -> V_450 &= ~ V_451 ;
F_5 ( V_20 , L_109 , V_10 -> V_450 ) ;
}
V_10 -> V_312 = V_401 -> V_312 ;
V_10 -> V_452 = false ;
if ( V_401 -> V_325 ) {
if ( V_8 -> V_2 -> V_180 -> V_453 == 0 ) {
F_5 ( V_59 ,
L_110 ) ;
V_3 = - V_454 ;
goto V_449;
#ifdef F_4
} else if ( V_8 -> V_2 -> V_455 &
V_456 )
V_10 -> V_452 = true ;
else {
F_5 ( V_59 ,
L_111 ) ;
V_3 = - V_454 ;
goto V_449;
#endif
}
#ifdef F_4
} else if ( ( V_10 -> V_455 & V_457 )
&& ( V_8 -> V_2 -> V_455 & V_456 )
&& ( V_401 -> V_324 == false ) ) {
F_5 ( V_20 , L_112 ) ;
V_10 -> V_452 = true ;
#endif
} else if ( V_401 -> V_327 ) {
if ( V_8 -> V_2 -> V_180 -> V_453 == 0 ) {
F_5 ( V_59 ,
L_113 ) ;
V_3 = - V_454 ;
goto V_449;
}
V_10 -> V_458 = true ;
}
V_10 -> V_255 = V_401 -> V_255 ;
V_10 -> V_275 = V_401 -> V_275 ;
V_10 -> V_309 = V_401 -> V_309 ;
F_12 ( & V_10 -> V_459 ) ;
F_2 ( & V_22 ) ;
F_138 ( & V_10 -> V_26 , & V_8 -> V_26 ) ;
F_3 ( & V_22 ) ;
F_166 ( V_10 ) ;
return V_10 ;
V_449:
F_163 ( V_10 ) ;
return F_71 ( V_3 ) ;
}
void
F_167 ( struct V_460 * V_461 )
{
if ( ! V_461 || F_127 ( V_461 ) )
return;
if ( ! F_168 ( & V_461 -> V_462 ) ||
F_169 ( V_463 , & V_461 -> V_464 ) ) {
V_461 -> V_465 = V_38 ;
return;
}
if ( ! F_127 ( F_170 ( V_461 ) ) )
F_161 ( F_170 ( V_461 ) ) ;
F_11 ( V_461 ) ;
return;
}
static inline struct V_460 *
F_171 ( struct V_466 * V_467 )
{
return V_467 -> V_468 ;
}
static int
F_172 ( struct V_469 * V_470 , struct V_471 * V_472 )
{
struct V_466 * V_473 = F_173 ( V_470 ) ;
struct V_466 * V_65 = V_472 -> V_467 ;
if ( ( V_470 -> V_474 & V_475 ) != ( V_472 -> V_30 & V_475 ) )
return 0 ;
if ( ( V_473 -> V_476 & V_477 ) !=
( V_65 -> V_476 & V_477 ) )
return 0 ;
if ( V_65 -> V_344 && V_65 -> V_344 < V_473 -> V_344 )
return 0 ;
if ( V_65 -> V_342 && V_65 -> V_342 < V_473 -> V_342 )
return 0 ;
if ( ! F_141 ( V_473 -> V_478 , V_65 -> V_478 ) || ! F_174 ( V_473 -> V_479 , V_65 -> V_479 ) )
return 0 ;
if ( V_473 -> V_480 != V_65 -> V_480 ||
V_473 -> V_481 != V_65 -> V_481 )
return 0 ;
if ( strcmp ( V_473 -> V_440 -> V_482 , V_65 -> V_440 -> V_482 ) )
return 0 ;
if ( V_473 -> V_234 != V_65 -> V_234 )
return 0 ;
return 1 ;
}
int
F_175 ( struct V_469 * V_470 , void * V_202 )
{
struct V_471 * V_472 = (struct V_471 * ) V_202 ;
struct V_147 * V_401 ;
struct V_466 * V_467 ;
struct V_1 * V_483 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_460 * V_461 ;
int V_3 = 0 ;
F_2 ( & V_22 ) ;
V_467 = F_173 ( V_470 ) ;
V_461 = F_176 ( F_171 ( V_467 ) ) ;
if ( F_127 ( V_461 ) ) {
F_3 ( & V_22 ) ;
return V_3 ;
}
V_10 = F_170 ( V_461 ) ;
V_8 = V_10 -> V_8 ;
V_483 = V_8 -> V_2 ;
V_401 = V_472 -> V_148 ;
if ( ! F_113 ( V_483 , V_401 ) ||
! F_140 ( V_8 , V_401 ) ||
! F_159 ( V_10 , V_401 -> V_199 ) ) {
V_3 = 0 ;
goto V_484;
}
V_3 = F_172 ( V_470 , V_472 ) ;
V_484:
F_3 ( & V_22 ) ;
F_167 ( V_461 ) ;
return V_3 ;
}
int
F_177 ( const unsigned int V_422 , struct V_7 * V_8 , const char * V_485 ,
const struct V_486 * V_487 , unsigned int * V_488 ,
struct V_489 * * V_490 , int V_226 )
{
char * V_491 ;
int V_3 = 0 ;
if ( ! V_8 -> V_2 -> V_50 -> V_448 || ! V_8 -> V_2 -> V_50 -> V_492 )
return - V_55 ;
* V_488 = 0 ;
* V_490 = NULL ;
if ( V_8 -> V_25 == 0 ) {
V_491 = F_35 ( 2 +
F_94 ( V_8 -> V_442 , V_493 * 2 )
+ 1 + 4 + 2 , V_141 ) ;
if ( V_491 == NULL )
return - V_83 ;
V_491 [ 0 ] = '\\' ;
V_491 [ 1 ] = '\\' ;
strcpy ( V_491 + 2 , V_8 -> V_442 ) ;
strcpy ( V_491 + 2 + strlen ( V_8 -> V_442 ) , L_114 ) ;
V_3 = V_8 -> V_2 -> V_50 -> V_448 ( V_422 , V_8 , V_491 , NULL ,
V_487 ) ;
F_5 ( V_20 , L_115 , V_3 , V_8 -> V_25 ) ;
F_11 ( V_491 ) ;
}
if ( V_3 == 0 )
V_3 = V_8 -> V_2 -> V_50 -> V_492 ( V_422 , V_8 , V_485 ,
V_490 , V_488 ,
V_487 , V_226 ) ;
return V_3 ;
}
static inline void
F_178 ( struct V_494 * V_495 )
{
struct V_495 * V_496 = V_495 -> V_496 ;
F_179 ( F_180 ( V_496 ) ) ;
F_181 ( V_496 , L_116 ,
& V_497 [ 0 ] , L_117 , & V_498 [ 0 ] ) ;
}
static inline void
F_182 ( struct V_494 * V_495 )
{
struct V_495 * V_496 = V_495 -> V_496 ;
F_179 ( F_180 ( V_496 ) ) ;
F_181 ( V_496 , L_118 ,
& V_497 [ 1 ] , L_119 , & V_498 [ 1 ] ) ;
}
static inline void
F_178 ( struct V_494 * V_495 )
{
}
static inline void
F_182 ( struct V_494 * V_495 )
{
}
static void F_183 ( char * V_499 , char * V_500 , unsigned int V_78 )
{
unsigned int V_207 , V_208 ;
for ( V_207 = 0 , V_208 = 0 ; V_207 < ( V_78 ) ; V_207 ++ ) {
V_499 [ V_208 ] = 'A' + ( 0x0F & ( V_500 [ V_207 ] >> 4 ) ) ;
V_499 [ V_208 + 1 ] = 'A' + ( 0x0F & V_500 [ V_207 ] ) ;
V_208 += 2 ;
}
}
static int
F_184 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_362 . V_432 != V_374 ) {
struct V_494 * V_494 = V_2 -> V_28 ;
V_3 = V_494 -> V_50 -> V_501 ( V_494 ,
(struct V_96 * ) & V_2 -> V_362 ,
sizeof( V_2 -> V_362 ) ) ;
if ( V_3 < 0 ) {
struct V_376 * V_377 ;
struct V_382 * V_383 ;
V_377 = (struct V_376 * ) & V_2 -> V_362 ;
V_383 = (struct V_382 * ) & V_2 -> V_362 ;
if ( V_383 -> V_502 == V_381 )
F_5 ( V_59 , L_120 ,
& V_383 -> V_385 , V_3 ) ;
else
F_5 ( V_59 , L_121 ,
& V_377 -> V_379 . V_380 , V_3 ) ;
}
}
return V_3 ;
}
static int
F_185 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_503 * V_504 ;
struct V_505 * V_506 ;
V_504 = F_100 ( sizeof( struct V_503 ) ,
V_141 ) ;
if ( V_504 ) {
V_504 -> V_507 . V_508 . V_509 = 32 ;
if ( V_2 -> V_409 [ 0 ] != 0 )
F_183 ( V_504 -> V_507 .
V_508 . V_510 ,
V_2 -> V_409 ,
V_367 ) ;
else
F_183 ( V_504 -> V_507 .
V_508 . V_510 ,
V_511 ,
V_367 ) ;
V_504 -> V_507 . V_508 . V_512 = 32 ;
if ( V_2 -> V_408 [ 0 ] != 0 )
F_183 ( V_504 -> V_507 .
V_508 . V_513 ,
V_2 -> V_408 ,
V_367 ) ;
else
F_183 ( V_504 -> V_507 .
V_508 . V_513 ,
L_122 ,
V_367 ) ;
V_504 -> V_507 . V_508 . V_514 = 0 ;
V_504 -> V_507 . V_508 . V_515 = 0 ;
V_506 = (struct V_505 * ) V_504 ;
V_506 -> V_516 = F_186 ( 0x81000044 ) ;
V_3 = F_187 ( V_2 , V_506 , 0x44 ) ;
F_11 ( V_504 ) ;
F_38 ( 1000 , 2000 ) ;
}
return V_3 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_5 V_387 ;
int V_517 , V_518 ;
struct V_494 * V_494 = V_2 -> V_28 ;
struct V_96 * V_519 ;
V_519 = (struct V_96 * ) & V_2 -> V_97 ;
if ( V_2 -> V_97 . V_432 == V_381 ) {
V_387 = ( (struct V_382 * ) V_519 ) -> V_389 ;
V_517 = sizeof( struct V_382 ) ;
V_518 = V_381 ;
} else {
V_387 = ( (struct V_376 * ) V_519 ) -> V_388 ;
V_517 = sizeof( struct V_376 ) ;
V_518 = V_375 ;
}
if ( V_494 == NULL ) {
V_3 = F_188 ( F_115 ( V_2 ) , V_518 , V_520 ,
V_521 , & V_494 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_59 , L_123 , V_3 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
F_5 ( V_20 , L_124 ) ;
V_2 -> V_28 = V_494 ;
V_494 -> V_496 -> V_522 = V_75 ;
if ( V_518 == V_381 )
F_182 ( V_494 ) ;
else
F_178 ( V_494 ) ;
}
V_3 = F_184 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_494 -> V_496 -> V_523 = 7 * V_53 ;
V_494 -> V_496 -> V_524 = 5 * V_53 ;
if ( V_2 -> V_253 ) {
if ( V_494 -> V_496 -> V_525 < ( 200 * 1024 ) )
V_494 -> V_496 -> V_525 = 200 * 1024 ;
if ( V_494 -> V_496 -> V_526 < ( 140 * 1024 ) )
V_494 -> V_496 -> V_526 = 140 * 1024 ;
}
if ( V_2 -> V_405 ) {
int V_527 = 1 ;
V_3 = F_189 ( V_494 , V_528 , V_529 ,
( char * ) & V_527 , sizeof( V_527 ) ) ;
if ( V_3 )
F_5 ( V_20 , L_125 ,
V_3 ) ;
}
F_5 ( V_20 , L_126 ,
V_494 -> V_496 -> V_525 ,
V_494 -> V_496 -> V_526 , V_494 -> V_496 -> V_523 ) ;
V_3 = V_494 -> V_50 -> V_530 ( V_494 , V_519 , V_517 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_20 , L_127 , V_3 ) ;
F_10 ( V_494 ) ;
V_2 -> V_28 = NULL ;
return V_3 ;
}
if ( V_387 == F_109 ( V_390 ) )
V_3 = F_185 ( V_2 ) ;
return V_3 ;
}
static int
F_134 ( struct V_1 * V_2 )
{
T_5 * V_387 ;
struct V_382 * V_393 = (struct V_382 * ) & V_2 -> V_97 ;
struct V_376 * V_386 = (struct V_376 * ) & V_2 -> V_97 ;
if ( V_2 -> V_97 . V_432 == V_381 )
V_387 = & V_393 -> V_389 ;
else
V_387 = & V_386 -> V_388 ;
if ( * V_387 == 0 ) {
int V_3 ;
* V_387 = F_109 ( V_98 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
* V_387 = F_109 ( V_390 ) ;
}
return F_18 ( V_2 ) ;
}
void F_190 ( unsigned int V_422 , struct V_9 * V_10 ,
struct V_466 * V_467 , struct V_147 * V_531 )
{
T_7 V_532 = F_191 ( V_10 -> V_533 . V_534 ) ;
if ( V_531 && V_531 -> V_273 ) {
V_10 -> V_533 . V_534 = 0 ;
V_10 -> V_535 = 0 ;
F_5 ( V_20 , L_128 ) ;
return;
} else if ( V_531 )
V_10 -> V_535 = 1 ;
if ( V_10 -> V_535 == 0 ) {
F_5 ( V_20 , L_129 ) ;
return;
}
if ( ! F_192 ( V_422 , V_10 ) ) {
T_7 V_536 = F_191 ( V_10 -> V_533 . V_534 ) ;
F_5 ( V_20 , L_130 , V_536 ) ;
if ( V_531 == NULL ) {
if ( ( V_532 & V_537 ) == 0 )
V_536 &= ~ V_537 ;
if ( ( V_532 & V_538 ) == 0 ) {
if ( V_536 & V_538 )
F_5 ( V_59 , L_131 ) ;
V_536 &= ~ V_538 ;
} else if ( ( V_536 & V_538 ) == 0 ) {
F_5 ( V_59 , L_132 ) ;
F_5 ( V_59 , L_133 ) ;
}
}
if ( V_536 & V_539 )
F_5 ( V_59 , L_134 ) ;
V_536 &= V_540 ;
if ( V_531 && V_531 -> V_306 )
V_536 &= ~ V_537 ;
else if ( V_537 & V_536 ) {
F_5 ( V_20 , L_135 ) ;
if ( V_467 )
V_467 -> V_476 |=
V_541 ;
}
if ( V_531 && V_531 -> V_232 == 0 )
V_536 &= ~ V_538 ;
else if ( V_536 & V_538 ) {
F_5 ( V_20 , L_136 ) ;
if ( V_467 )
V_467 -> V_476 |=
V_542 ;
}
F_5 ( V_20 , L_137 , ( int ) V_536 ) ;
#ifdef F_61
if ( V_536 & V_543 )
F_5 ( V_20 , L_138 ) ;
if ( V_536 & V_544 )
F_5 ( V_20 , L_139 ) ;
if ( V_536 & V_538 )
F_5 ( V_20 , L_140 ) ;
if ( V_536 & V_545 )
F_5 ( V_20 , L_141 ) ;
if ( V_536 & V_537 )
F_5 ( V_20 , L_142 ) ;
if ( V_536 & V_546 )
F_5 ( V_20 , L_143 ) ;
if ( V_536 & V_547 )
F_5 ( V_20 , L_144 ) ;
if ( V_536 & V_548 )
F_5 ( V_20 , L_145 ) ;
if ( V_536 & V_539 )
F_5 ( V_20 , L_146 ) ;
#endif
if ( F_193 ( V_422 , V_10 , V_536 ) ) {
if ( V_531 == NULL ) {
F_5 ( V_20 , L_147 ) ;
} else
F_5 ( V_59 , L_148 ) ;
}
}
}
void F_194 ( struct V_147 * V_549 ,
struct V_466 * V_467 )
{
F_132 ( & V_467 -> V_550 , V_551 ) ;
F_131 ( & V_467 -> V_552 ) ;
V_467 -> V_553 = V_554 ;
V_467 -> V_342 = V_549 -> V_342 ;
V_467 -> V_344 = V_549 -> V_344 ;
V_467 -> V_478 = V_549 -> V_224 ;
V_467 -> V_479 = V_549 -> V_225 ;
V_467 -> V_480 = V_549 -> V_228 ;
V_467 -> V_481 = V_549 -> V_227 ;
F_5 ( V_20 , L_149 ,
V_467 -> V_480 , V_467 -> V_481 ) ;
V_467 -> V_234 = V_549 -> V_234 ;
V_467 -> V_440 = V_549 -> V_440 ;
if ( V_549 -> V_258 )
V_467 -> V_476 |= V_555 ;
if ( V_549 -> V_285 )
V_467 -> V_476 |= V_556 ;
if ( V_549 -> V_233 )
V_467 -> V_476 |= V_557 ;
if ( V_549 -> V_226 )
V_467 -> V_476 |= V_558 ;
if ( V_549 -> V_261 )
V_467 -> V_476 |= V_559 ;
if ( V_549 -> V_244 )
V_467 -> V_476 |= V_560 ;
if ( V_549 -> V_266 )
V_467 -> V_476 |= V_561 ;
if ( V_549 -> V_277 )
V_467 -> V_476 |= V_562 ;
if ( V_549 -> V_296 )
V_467 -> V_476 |= V_563 ;
if ( V_549 -> V_283 )
V_467 -> V_476 |= V_564 ;
if ( V_549 -> V_301 )
V_467 -> V_476 |= V_565 ;
if ( V_549 -> V_303 )
V_467 -> V_476 |= V_566 ;
if ( V_549 -> V_238 ) {
V_467 -> V_476 |= V_567 ;
V_467 -> V_568 = V_549 -> V_331 ;
}
if ( V_549 -> V_239 ) {
V_467 -> V_476 |= V_569 ;
V_467 -> V_570 = V_549 -> V_333 ;
}
if ( V_549 -> V_210 )
V_467 -> V_476 |= V_571 ;
if ( V_549 -> V_211 )
V_467 -> V_476 |= V_572 ;
if ( V_549 -> V_288 )
V_467 -> V_476 |= V_573 ;
if ( V_549 -> V_315 )
V_467 -> V_476 |= V_574 ;
if ( V_549 -> V_319 )
V_467 -> V_476 |= ( V_575 |
V_555 ) ;
if ( V_549 -> V_174 )
V_467 -> V_476 |= V_576 ;
if ( V_549 -> V_173 ) {
F_5 ( V_20 , L_150 ) ;
V_467 -> V_476 |= V_577 ;
}
if ( V_549 -> V_317 ) {
if ( V_549 -> V_266 ) {
F_5 ( V_59 , L_151 ) ;
}
V_467 -> V_476 |= V_578 ;
}
if ( ( V_549 -> V_303 ) && ( V_549 -> V_288 ) )
F_5 ( V_59 , L_152 ) ;
}
static void
F_195 ( struct V_147 * V_401 )
{
F_11 ( V_401 -> V_349 ) ;
F_196 ( V_401 -> V_354 ) ;
F_11 ( V_401 -> V_199 ) ;
F_11 ( V_401 -> V_360 ) ;
F_11 ( V_401 -> V_364 ) ;
F_11 ( V_401 -> V_200 ) ;
}
void
F_197 ( struct V_147 * V_401 )
{
if ( ! V_401 )
return;
F_195 ( V_401 ) ;
F_11 ( V_401 ) ;
}
static char *
F_198 ( const struct V_147 * V_148 ,
const struct V_466 * V_467 )
{
char * V_579 , * V_197 ;
unsigned int V_580 = V_148 -> V_200 ? strlen ( V_148 -> V_200 ) + 1 : 0 ;
unsigned int V_581 = F_94 ( V_148 -> V_199 , V_445 + 1 ) ;
V_579 = F_35 ( V_581 + V_580 + 1 , V_141 ) ;
if ( V_579 == NULL )
return F_71 ( - V_83 ) ;
strncpy ( V_579 , V_148 -> V_199 , V_581 ) ;
V_197 = V_579 + V_581 ;
if ( V_580 ) {
* V_197 = F_199 ( V_467 ) ;
strncpy ( V_197 + 1 , V_148 -> V_200 , V_580 ) ;
V_197 += V_580 ;
}
* V_197 = '\0' ;
F_90 ( V_579 , F_199 ( V_467 ) ) ;
F_5 ( V_20 , L_153 , V_21 , V_579 ) ;
return V_579 ;
}
static int
F_200 ( const unsigned int V_422 , struct V_7 * V_8 ,
struct V_147 * V_401 , struct V_466 * V_467 ,
int V_582 )
{
int V_3 ;
unsigned int V_488 = 0 ;
struct V_489 * V_490 = NULL ;
char * V_579 = NULL , * V_583 = NULL , * V_584 = NULL ;
V_579 = F_198 ( V_401 , V_467 ) ;
if ( F_127 ( V_579 ) )
return F_128 ( V_579 ) ;
V_583 = V_582 ? V_579 + 1 : V_401 -> V_199 + 1 ;
V_3 = F_177 ( V_422 , V_8 , V_583 , V_467 -> V_440 ,
& V_488 , & V_490 , F_201 ( V_467 ) ) ;
if ( ! V_3 && V_488 > 0 ) {
char * V_585 = NULL ;
V_584 = F_202 ( V_467 -> V_201 ,
V_579 + 1 , V_490 ,
& V_585 ) ;
F_203 ( V_490 , V_488 ) ;
if ( F_127 ( V_584 ) ) {
V_3 = F_128 ( V_584 ) ;
V_584 = NULL ;
} else {
F_195 ( V_401 ) ;
V_3 = F_204 ( V_401 , V_584 ,
V_585 ) ;
}
F_11 ( V_585 ) ;
F_11 ( V_467 -> V_201 ) ;
V_467 -> V_201 = V_584 ;
}
F_11 ( V_579 ) ;
return V_3 ;
}
static int
F_204 ( struct V_147 * V_401 , char * V_586 ,
const char * V_196 )
{
int V_3 = 0 ;
if ( F_92 ( V_586 , V_196 , V_401 ) )
return - V_140 ;
if ( V_401 -> V_170 ) {
F_5 ( V_20 , L_154 ) ;
F_11 ( V_401 -> V_349 ) ;
V_401 -> V_349 = NULL ;
} else if ( V_401 -> V_349 ) {
F_5 ( V_20 , L_155 , V_401 -> V_349 ) ;
} else {
F_5 ( V_59 , L_156 ) ;
return - V_140 ;
}
if ( V_401 -> V_364 == NULL ) {
V_401 -> V_440 = F_205 () ;
} else {
V_401 -> V_440 = F_206 ( V_401 -> V_364 ) ;
if ( V_401 -> V_440 == NULL ) {
F_5 ( V_59 , L_157 ,
V_401 -> V_364 ) ;
return - V_587 ;
}
}
return V_3 ;
}
struct V_147 *
F_207 ( char * V_586 , const char * V_196 )
{
int V_3 ;
struct V_147 * V_401 ;
V_401 = F_35 ( sizeof( struct V_147 ) , V_141 ) ;
if ( ! V_401 )
return F_71 ( - V_83 ) ;
V_3 = F_204 ( V_401 , V_586 , V_196 ) ;
if ( V_3 ) {
F_197 ( V_401 ) ;
V_401 = F_71 ( V_3 ) ;
}
return V_401 ;
}
int
F_208 ( struct V_466 * V_467 , struct V_147 * V_401 )
{
int V_3 ;
unsigned int V_422 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
char * V_579 ;
struct V_460 * V_461 ;
#ifdef F_209
int V_588 = 0 ;
#endif
V_3 = F_210 ( & V_467 -> V_589 , L_158 ) ;
if ( V_3 )
return V_3 ;
#ifdef F_209
V_590:
if ( V_588 ) {
if ( V_10 )
F_161 ( V_10 ) ;
else if ( V_8 )
F_143 ( V_8 ) ;
V_467 -> V_476 &= ~ V_542 ;
F_156 ( V_422 ) ;
}
#endif
V_3 = 0 ;
V_10 = NULL ;
V_8 = NULL ;
V_2 = NULL ;
V_579 = NULL ;
V_461 = NULL ;
V_422 = F_144 () ;
V_2 = F_124 ( V_401 ) ;
if ( F_127 ( V_2 ) ) {
V_3 = F_128 ( V_2 ) ;
F_211 ( & V_467 -> V_589 ) ;
goto V_484;
}
V_8 = F_154 ( V_2 , V_401 ) ;
if ( F_127 ( V_8 ) ) {
V_3 = F_128 ( V_8 ) ;
V_8 = NULL ;
goto V_591;
}
#ifdef F_4
if ( ( V_401 -> V_325 == true ) && ( ( V_8 -> V_2 -> V_455 &
V_456 ) == 0 ) ) {
F_5 ( V_59 , L_159 ) ;
V_3 = - V_454 ;
goto V_591;
}
#endif
V_10 = F_164 ( V_8 , V_401 ) ;
if ( F_127 ( V_10 ) ) {
V_3 = F_128 ( V_10 ) ;
V_10 = NULL ;
goto V_592;
}
if ( F_212 ( V_10 -> V_8 ) ) {
F_190 ( V_422 , V_10 , V_467 , V_401 ) ;
if ( ( V_10 -> V_8 -> V_2 -> V_15 == V_17 ) &&
( F_191 ( V_10 -> V_533 . V_534 ) &
V_539 ) ) {
V_3 = - V_593 ;
goto V_591;
}
} else
V_10 -> V_535 = 0 ;
if ( ! V_10 -> V_594 && V_2 -> V_50 -> V_595 )
V_2 -> V_50 -> V_595 ( V_422 , V_10 ) ;
V_467 -> V_344 = V_2 -> V_50 -> V_596 ( V_10 , V_401 ) ;
V_467 -> V_342 = V_2 -> V_50 -> V_597 ( V_10 , V_401 ) ;
V_467 -> V_589 . V_598 = V_467 -> V_342 / V_237 ;
V_592:
#ifdef F_209
if ( V_588 == 0 ) {
int V_599 = F_200 ( V_422 , V_8 , V_401 , V_467 ,
false ) ;
if ( ! V_599 ) {
V_588 ++ ;
goto V_590;
}
}
#endif
if ( ! V_3 && V_10 ) {
if ( ! V_2 -> V_50 -> V_600 ) {
V_3 = - V_55 ;
goto V_591;
}
V_579 = F_213 ( V_401 , V_467 , V_10 ) ;
if ( V_579 == NULL ) {
V_3 = - V_83 ;
goto V_591;
}
V_3 = V_2 -> V_50 -> V_600 ( V_422 , V_10 , V_467 ,
V_579 ) ;
if ( V_3 != 0 && V_3 != - V_601 ) {
F_11 ( V_579 ) ;
goto V_591;
}
F_11 ( V_579 ) ;
}
if ( V_3 == - V_601 ) {
#ifdef F_209
if ( V_588 > V_602 ) {
V_3 = - V_603 ;
goto V_591;
}
V_3 = F_200 ( V_422 , V_8 , V_401 , V_467 , true ) ;
if ( ! V_3 ) {
V_588 ++ ;
goto V_590;
}
goto V_591;
#else
V_3 = - V_454 ;
#endif
}
if ( V_3 )
goto V_591;
V_461 = F_100 ( sizeof *V_461 , V_141 ) ;
if ( V_461 == NULL ) {
V_3 = - V_83 ;
goto V_591;
}
V_461 -> V_604 = V_8 -> V_224 ;
V_461 -> V_605 = V_10 ;
V_461 -> V_465 = V_38 ;
F_214 ( V_606 , & V_461 -> V_464 ) ;
F_214 ( V_463 , & V_461 -> V_464 ) ;
V_467 -> V_468 = V_461 ;
F_2 ( & V_467 -> V_552 ) ;
F_215 ( & V_467 -> V_553 , V_461 ) ;
F_3 ( & V_467 -> V_552 ) ;
F_24 ( V_57 , & V_467 -> V_550 ,
V_607 ) ;
V_591:
if ( V_3 ) {
if ( V_10 )
F_161 ( V_10 ) ;
else if ( V_8 )
F_143 ( V_8 ) ;
else
F_118 ( V_2 ) ;
F_211 ( & V_467 -> V_589 ) ;
}
V_484:
F_156 ( V_422 ) ;
return V_3 ;
}
int
F_216 ( const unsigned int V_422 , struct V_7 * V_8 ,
const char * V_608 , struct V_9 * V_10 ,
const struct V_486 * V_487 )
{
struct V_505 * V_609 ;
struct V_505 * V_610 ;
T_8 * V_611 ;
T_9 * V_612 ;
unsigned char * V_613 ;
int V_3 = 0 ;
int V_78 ;
T_10 V_614 , V_615 ;
if ( V_8 == NULL )
return - V_616 ;
V_609 = F_26 () ;
if ( V_609 == NULL )
return - V_83 ;
V_610 = V_609 ;
F_217 ( V_609 , V_617 ,
NULL , 4 ) ;
V_609 -> V_618 = F_218 ( V_8 -> V_2 ) ;
V_609 -> V_619 = V_8 -> V_620 ;
V_611 = ( T_8 * ) V_609 ;
V_612 = ( T_9 * ) V_610 ;
V_611 -> V_621 = 0xFF ;
V_611 -> V_450 = F_219 ( V_622 ) ;
V_613 = & V_611 -> V_623 [ 0 ] ;
if ( ! V_10 || ( V_8 -> V_2 -> V_624 & V_625 ) ) {
V_611 -> V_626 = F_219 ( 1 ) ;
* V_613 = 0 ;
V_613 ++ ;
} else {
V_611 -> V_626 = F_219 ( V_627 ) ;
#ifdef F_84
if ( ( V_628 & V_629 ) &&
( V_8 -> V_150 == V_168 ) )
F_220 ( V_10 -> V_354 , V_8 -> V_2 -> V_630 ,
V_8 -> V_2 -> V_624 &
V_631 ? true : false ,
V_613 ) ;
else
#endif
V_3 = F_221 ( V_10 -> V_354 , V_8 -> V_2 -> V_630 ,
V_613 , V_487 ) ;
if ( V_3 ) {
F_5 ( V_20 , L_160 ,
V_21 , V_3 ) ;
F_63 ( V_609 ) ;
return V_3 ;
}
V_613 += V_627 ;
if ( V_8 -> V_455 & V_632 ) {
* V_613 = 0 ;
V_613 ++ ;
}
}
if ( V_8 -> V_2 -> V_152 )
V_609 -> V_633 |= V_634 ;
if ( V_8 -> V_455 & V_635 ) {
V_609 -> V_633 |= V_636 ;
}
if ( V_8 -> V_455 & V_637 ) {
V_609 -> V_633 |= V_638 ;
}
if ( V_8 -> V_455 & V_632 ) {
V_609 -> V_633 |= V_639 ;
V_78 =
F_222 ( ( V_640 * ) V_613 , V_608 ,
6 *
( + 256 ) , V_487 ) ;
V_613 += 2 * V_78 ;
V_613 += 2 ;
} else {
strcpy ( V_613 , V_608 ) ;
V_613 += strlen ( V_608 ) + 1 ;
}
strcpy ( V_613 , L_161 ) ;
V_613 += strlen ( L_161 ) ;
V_613 += 1 ;
V_615 = V_613 - & V_611 -> V_623 [ 0 ] ;
V_611 -> V_641 . V_516 = F_186 ( F_223 (
V_611 -> V_641 . V_516 ) + V_615 ) ;
V_611 -> V_642 = F_219 ( V_615 ) ;
V_3 = F_224 ( V_422 , V_8 , V_609 , V_610 , & V_78 ,
0 ) ;
if ( ( V_3 == 0 ) && ( V_10 != NULL ) ) {
bool V_643 ;
V_10 -> V_443 = V_62 ;
V_10 -> V_24 = false ;
V_10 -> V_644 = V_610 -> V_645 ;
V_613 = F_225 ( V_610 ) ;
V_614 = F_226 ( V_610 ) ;
V_78 = F_94 ( V_613 , V_614 - 2 ) ;
if ( V_609 -> V_633 & V_639 )
V_643 = true ;
else
V_643 = false ;
if ( V_78 == 3 ) {
if ( ( V_613 [ 0 ] == 'I' ) && ( V_613 [ 1 ] == 'P' ) &&
( V_613 [ 2 ] == 'C' ) ) {
F_5 ( V_20 , L_162 ) ;
V_10 -> V_594 = 1 ;
}
} else if ( V_78 == 2 ) {
if ( ( V_613 [ 0 ] == 'A' ) && ( V_613 [ 1 ] == ':' ) ) {
F_5 ( V_20 , L_163 ) ;
}
}
V_613 += V_78 + 1 ;
V_614 -= ( V_78 + 1 ) ;
F_227 ( V_10 -> V_444 , V_608 , sizeof( V_10 -> V_444 ) ) ;
F_11 ( V_10 -> V_646 ) ;
V_10 -> V_646 = F_228 ( V_613 ,
V_614 , V_643 ,
V_487 ) ;
F_5 ( V_20 , L_164 , V_10 -> V_646 ) ;
if ( ( V_610 -> V_647 == 3 ) ||
( V_610 -> V_647 == 7 ) )
V_10 -> V_450 = F_229 ( V_612 -> V_648 ) ;
else
V_10 -> V_450 = 0 ;
F_5 ( V_20 , L_165 , V_10 -> V_450 ) ;
} else if ( ( V_3 == 0 ) && V_10 == NULL ) {
V_8 -> V_25 = V_610 -> V_645 ;
}
F_63 ( V_609 ) ;
return V_3 ;
}
static void F_230 ( struct V_649 * V_122 )
{
struct V_466 * V_650 = F_22 ( V_122 , struct V_466 , V_651 ) ;
F_231 ( V_650 -> V_440 ) ;
F_11 ( V_650 ) ;
}
void
F_232 ( struct V_466 * V_467 )
{
struct V_652 * V_653 = & V_467 -> V_553 ;
struct V_654 * V_655 ;
struct V_460 * V_461 ;
F_120 ( & V_467 -> V_550 ) ;
F_2 ( & V_467 -> V_552 ) ;
while ( ( V_655 = F_233 ( V_653 ) ) ) {
V_461 = F_234 ( V_655 , struct V_460 , V_656 ) ;
F_176 ( V_461 ) ;
F_235 ( V_463 , & V_461 -> V_464 ) ;
F_236 ( V_655 , V_653 ) ;
F_3 ( & V_467 -> V_552 ) ;
F_167 ( V_461 ) ;
F_2 ( & V_467 -> V_552 ) ;
}
F_3 ( & V_467 -> V_552 ) ;
F_211 ( & V_467 -> V_589 ) ;
F_11 ( V_467 -> V_201 ) ;
F_237 ( & V_467 -> V_651 , F_230 ) ;
}
int
F_155 ( const unsigned int V_422 , struct V_7 * V_8 )
{
int V_3 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_50 -> V_51 || ! V_2 -> V_50 -> V_657 )
return - V_55 ;
if ( ! V_2 -> V_50 -> V_51 ( V_2 ) )
return 0 ;
F_238 ( V_2 , 1 ) ;
V_3 = V_2 -> V_50 -> V_657 ( V_422 , V_8 ) ;
if ( V_3 == 0 ) {
F_2 ( & V_14 ) ;
if ( V_2 -> V_15 == V_45 )
V_2 -> V_15 = V_62 ;
else
V_3 = - V_658 ;
F_3 ( & V_14 ) ;
}
return V_3 ;
}
int
F_157 ( const unsigned int V_422 , struct V_7 * V_8 ,
struct V_486 * V_659 )
{
int V_3 = - V_55 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_455 = V_2 -> V_455 ;
if ( V_660 == 0 )
V_8 -> V_455 &= ( ~ V_2 -> V_180 -> F_212 ) ;
F_5 ( V_20 , L_166 ,
V_2 -> V_624 , V_2 -> V_455 , V_2 -> V_661 ) ;
if ( V_2 -> V_50 -> V_662 )
V_3 = V_2 -> V_50 -> V_662 ( V_422 , V_8 , V_659 ) ;
if ( V_3 )
F_5 ( V_59 , L_167 , V_3 ) ;
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
F_240 ( struct V_466 * V_467 , T_3 V_663 )
{
int V_3 ;
struct V_9 * V_664 = F_241 ( V_467 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_147 * V_531 ;
V_531 = F_100 ( sizeof( * V_531 ) , V_141 ) ;
if ( V_531 == NULL )
return F_71 ( - V_83 ) ;
V_531 -> V_440 = V_467 -> V_440 ;
V_531 -> V_224 = V_663 ;
V_531 -> V_223 = V_663 ;
V_531 -> V_199 = V_664 -> V_444 ;
V_531 -> V_255 = V_664 -> V_255 ;
V_531 -> V_275 = V_664 -> V_275 ;
V_531 -> V_309 = V_664 -> V_309 ;
V_531 -> V_273 = ! V_664 -> V_535 ;
V_531 -> V_150 = V_664 -> V_8 -> V_150 ;
V_531 -> V_152 = V_664 -> V_8 -> V_152 ;
V_3 = F_239 ( V_531 , V_664 -> V_8 ) ;
if ( V_3 ) {
V_10 = F_71 ( V_3 ) ;
goto V_484;
}
F_2 ( & V_22 ) ;
++ V_664 -> V_8 -> V_2 -> V_398 ;
F_3 ( & V_22 ) ;
V_8 = F_154 ( V_664 -> V_8 -> V_2 , V_531 ) ;
if ( F_127 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 ;
F_118 ( V_664 -> V_8 -> V_2 ) ;
goto V_484;
}
V_10 = F_164 ( V_8 , V_531 ) ;
if ( F_127 ( V_10 ) ) {
F_143 ( V_8 ) ;
goto V_484;
}
if ( F_212 ( V_8 ) )
F_190 ( 0 , V_10 , NULL , V_531 ) ;
V_484:
F_11 ( V_531 -> V_349 ) ;
F_11 ( V_531 -> V_354 ) ;
F_11 ( V_531 ) ;
return V_10 ;
}
struct V_9 *
F_241 ( struct V_466 * V_467 )
{
return F_170 ( F_171 ( V_467 ) ) ;
}
static struct V_460 *
F_242 ( struct V_652 * V_653 , T_3 V_145 )
{
struct V_654 * V_655 = V_653 -> V_654 ;
struct V_460 * V_461 ;
while ( V_655 ) {
V_461 = F_234 ( V_655 , struct V_460 , V_656 ) ;
if ( F_243 ( V_461 -> V_604 , V_145 ) )
V_655 = V_655 -> V_665 ;
else if ( F_244 ( V_461 -> V_604 , V_145 ) )
V_655 = V_655 -> V_666 ;
else
return V_461 ;
}
return NULL ;
}
static void
F_215 ( struct V_652 * V_653 , struct V_460 * V_667 )
{
struct V_654 * * V_65 = & ( V_653 -> V_654 ) , * V_668 = NULL ;
struct V_460 * V_461 ;
while ( * V_65 ) {
V_461 = F_234 ( * V_65 , struct V_460 , V_656 ) ;
V_668 = * V_65 ;
if ( F_243 ( V_461 -> V_604 , V_667 -> V_604 ) )
V_65 = & ( ( * V_65 ) -> V_665 ) ;
else
V_65 = & ( ( * V_65 ) -> V_666 ) ;
}
F_245 ( & V_667 -> V_656 , V_668 , V_65 ) ;
F_246 ( & V_667 -> V_656 , V_653 ) ;
}
struct V_460 *
F_247 ( struct V_466 * V_467 )
{
int V_669 ;
T_3 V_663 = F_248 () ;
struct V_460 * V_461 , * V_670 ;
if ( ! ( V_467 -> V_476 & V_575 ) )
return F_176 ( F_171 ( V_467 ) ) ;
F_2 ( & V_467 -> V_552 ) ;
V_461 = F_242 ( & V_467 -> V_553 , V_663 ) ;
if ( V_461 )
F_176 ( V_461 ) ;
F_3 ( & V_467 -> V_552 ) ;
if ( V_461 == NULL ) {
V_670 = F_100 ( sizeof( * V_461 ) , V_141 ) ;
if ( V_670 == NULL )
return F_71 ( - V_83 ) ;
V_670 -> V_604 = V_663 ;
V_670 -> V_605 = F_71 ( - V_593 ) ;
F_214 ( V_671 , & V_670 -> V_464 ) ;
F_214 ( V_463 , & V_670 -> V_464 ) ;
F_176 ( V_670 ) ;
F_2 ( & V_467 -> V_552 ) ;
V_461 = F_242 ( & V_467 -> V_553 , V_663 ) ;
if ( V_461 ) {
F_176 ( V_461 ) ;
F_3 ( & V_467 -> V_552 ) ;
F_11 ( V_670 ) ;
goto V_672;
}
V_461 = V_670 ;
F_215 ( & V_467 -> V_553 , V_461 ) ;
F_3 ( & V_467 -> V_552 ) ;
} else {
V_672:
V_669 = F_249 ( & V_461 -> V_464 , V_671 ,
V_134 ) ;
if ( V_669 ) {
F_167 ( V_461 ) ;
return F_71 ( - V_88 ) ;
}
if ( ! F_127 ( V_461 -> V_605 ) )
return V_461 ;
if ( F_23 ( V_38 , V_461 -> V_465 + V_673 ) ) {
F_167 ( V_461 ) ;
return F_71 ( - V_593 ) ;
}
if ( F_250 ( V_671 , & V_461 -> V_464 ) )
goto V_672;
}
V_461 -> V_605 = F_240 ( V_467 , V_663 ) ;
F_235 ( V_671 , & V_461 -> V_464 ) ;
F_251 ( & V_461 -> V_464 , V_671 ) ;
if ( F_127 ( V_461 -> V_605 ) ) {
F_167 ( V_461 ) ;
return F_71 ( - V_593 ) ;
}
return V_461 ;
}
static void
V_551 ( struct V_46 * V_47 )
{
struct V_466 * V_467 = F_22 ( V_47 , struct V_466 ,
V_550 . V_47 ) ;
struct V_652 * V_653 = & V_467 -> V_553 ;
struct V_654 * V_655 = F_233 ( V_653 ) ;
struct V_654 * V_5 ;
struct V_460 * V_461 ;
F_2 ( & V_467 -> V_552 ) ;
V_655 = F_233 ( V_653 ) ;
while ( V_655 != NULL ) {
V_5 = V_655 ;
V_655 = F_252 ( V_5 ) ;
V_461 = F_234 ( V_5 , struct V_460 , V_656 ) ;
if ( F_169 ( V_606 , & V_461 -> V_464 ) ||
F_60 ( & V_461 -> V_462 ) != 0 ||
F_30 ( V_461 -> V_465 + V_607 , V_38 ) )
continue;
F_176 ( V_461 ) ;
F_235 ( V_463 , & V_461 -> V_464 ) ;
F_236 ( V_5 , V_653 ) ;
F_3 ( & V_467 -> V_552 ) ;
F_167 ( V_461 ) ;
F_2 ( & V_467 -> V_552 ) ;
}
F_3 ( & V_467 -> V_552 ) ;
F_24 ( V_57 , & V_467 -> V_550 ,
V_607 ) ;
}
