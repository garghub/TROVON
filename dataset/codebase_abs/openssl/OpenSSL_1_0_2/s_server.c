static T_1 * F_1 ( void )
{
T_1 * V_1 = NULL ;
if ( ( V_1 = F_2 () ) == NULL )
return ( NULL ) ;
V_1 -> V_2 = F_3 ( V_3 , sizeof( V_3 ) , NULL ) ;
V_1 -> V_4 = F_3 ( V_5 , sizeof( V_5 ) , NULL ) ;
if ( ( V_1 -> V_2 == NULL ) || ( V_1 -> V_4 == NULL ) )
return ( NULL ) ;
return ( V_1 ) ;
}
static unsigned int F_4 ( T_2 * V_6 , const char * V_7 ,
unsigned char * V_8 ,
unsigned int V_9 )
{
unsigned int V_10 = 0 ;
int V_11 ;
T_3 * V_12 = NULL ;
if ( V_13 )
F_5 ( V_14 , L_1 ) ;
if ( ! V_7 ) {
F_5 ( V_15 , L_2 ) ;
goto V_16;
}
if ( V_13 )
F_5 ( V_14 , L_3 ,
V_7 ? ( int ) strlen ( V_7 ) : 0 , V_7 ) ;
if ( strcmp ( V_7 , V_17 ) != 0 ) {
F_5 ( V_14 , L_4
L_5 , V_7 , V_17 ) ;
goto V_16;
}
if ( V_13 )
F_5 ( V_14 , L_6 ) ;
V_11 = F_6 ( & V_12 , V_18 ) ;
if ( ! V_11 ) {
F_5 ( V_15 , L_7 ,
V_18 ) ;
if ( V_12 )
F_7 ( V_12 ) ;
return 0 ;
}
if ( F_8 ( V_12 ) > ( int ) V_9 ) {
F_5 ( V_15 ,
L_8 ,
V_9 , F_8 ( V_12 ) ) ;
F_7 ( V_12 ) ;
return 0 ;
}
V_11 = F_9 ( V_12 , V_8 ) ;
F_7 ( V_12 ) ;
if ( V_11 < 0 )
goto V_16;
V_10 = ( unsigned int ) V_11 ;
if ( V_13 )
F_5 ( V_14 , L_9 , V_10 ) ;
return V_10 ;
V_16:
if ( V_13 )
F_5 ( V_15 , L_10 ) ;
return 0 ;
}
static int T_4 F_10 ( T_2 * V_19 , int * V_20 , void * V_21 )
{
T_5 * V_2 = ( T_5 * ) V_21 ;
if ( V_2 -> V_22 == NULL && V_2 -> V_23 == NULL ) {
V_2 -> V_22 = F_11 ( V_19 ) ;
F_5 ( V_15 , L_11 , V_2 -> V_22 ) ;
return ( - 1 ) ;
}
if ( V_2 -> V_23 == NULL ) {
F_5 ( V_15 , L_12 , V_2 -> V_22 ) ;
return V_24 ;
}
if ( F_12
( V_19 , V_2 -> V_23 -> V_25 , V_2 -> V_23 -> V_4 , V_2 -> V_23 -> V_19 , V_2 -> V_23 -> V_26 ,
V_2 -> V_23 -> V_27 ) < 0 ) {
* V_20 = V_28 ;
return V_24 ;
}
F_5 ( V_15 ,
L_13 ,
V_2 -> V_22 , V_2 -> V_23 -> V_27 ) ;
V_2 -> V_23 = NULL ;
V_2 -> V_22 = NULL ;
return V_29 ;
}
static void F_13 ( void )
{
V_30 = - 1 ;
V_31 = V_32 ;
V_33 = NULL ;
V_34 = NULL ;
V_35 = NULL ;
V_36 = V_37 ;
V_38 = NULL ;
V_39 = NULL ;
# ifndef F_14
V_40 = V_41 ;
V_42 = NULL ;
V_43 = NULL ;
# endif
# ifdef F_15
V_44 = 0 ;
# endif
V_45 = 0 ;
V_46 = NULL ;
V_47 = 0 ;
V_14 = NULL ;
V_13 = 0 ;
V_48 = 0 ;
V_49 = 0 ;
V_50 = 0 ;
V_51 = 0 ;
# ifndef F_16
V_52 = NULL ;
# endif
}
static void F_17 ( void )
{
F_5 ( V_15 , L_14 ) ;
F_5 ( V_15 , L_15 ) ;
F_5 ( V_15 ,
L_16 , V_53 ) ;
F_5 ( V_15 ,
L_17 ) ;
F_5 ( V_15 ,
L_18 ) ;
F_5 ( V_15 ,
L_19 ) ;
F_5 ( V_15 , L_20 ) ;
F_5 ( V_15 ,
L_21 ) ;
F_5 ( V_15 ,
L_22 ) ;
F_5 ( V_15 ,
L_23 ) ;
F_5 ( V_15 , L_24 ) ;
F_5 ( V_15 , L_25 , V_37 ) ;
#ifndef F_14
F_5 ( V_15 ,
L_26 ) ;
F_5 ( V_15 ,
L_27 ) ;
F_5 ( V_15 ,
L_28 ) ;
#endif
F_5 ( V_15 ,
L_29 ) ;
F_5 ( V_15 ,
L_30
L_31 ) ;
F_5 ( V_15 ,
L_32
L_33
L_34 ) ;
F_5 ( V_15 ,
L_35 ) ;
F_5 ( V_15 ,
L_36 ) ;
F_5 ( V_15 , L_37 ,
V_37 ) ;
F_5 ( V_15 ,
L_38 ) ;
F_5 ( V_15 ,
L_39 ) ;
F_5 ( V_15 ,
L_40 ) ;
F_5 ( V_15 ,
L_41 ) ;
F_5 ( V_15 ,
L_42 ) ;
F_5 ( V_15 ,
L_43 ) ;
F_5 ( V_15 ,
L_44 ) ;
F_5 ( V_15 ,
L_45 ) ;
F_5 ( V_15 ,
L_46 ) ;
#ifndef F_18
F_5 ( V_15 ,
L_47
L_48
L_49 ) ;
#endif
#ifdef F_15
F_5 ( V_15 , L_50 ) ;
#endif
F_5 ( V_15 ,
L_51 ) ;
F_5 ( V_15 ,
L_52 ) ;
F_5 ( V_15 , L_53 ) ;
F_5 ( V_15 , L_54 ) ;
F_5 ( V_15 , L_55 ) ;
F_5 ( V_15 , L_56 ) ;
F_5 ( V_15 , L_57 ) ;
F_5 ( V_15 ,
L_58 ) ;
F_5 ( V_15 ,
L_59 ) ;
F_5 ( V_15 , L_60 ) ;
F_5 ( V_15 , L_61 ) ;
F_5 ( V_15 , L_62 ) ;
#ifndef F_19
F_5 ( V_15 , L_63 ) ;
F_5 ( V_15 , L_64 ) ;
# ifndef F_20
F_5 ( V_15 , L_65 ) ;
# endif
#endif
#ifndef F_21
F_5 ( V_15 , L_66 ) ;
F_5 ( V_15 ,
L_67 ) ;
#endif
F_5 ( V_15 , L_68 ) ;
#ifndef F_22
F_5 ( V_15 , L_69 ) ;
#endif
F_5 ( V_15 , L_70 ) ;
F_5 ( V_15 , L_71 ) ;
F_5 ( V_15 , L_72 ) ;
F_5 ( V_15 , L_73 ) ;
F_5 ( V_15 , L_74 ) ;
F_5 ( V_15 , L_75 ) ;
F_5 ( V_15 , L_76 ) ;
F_5 ( V_15 , L_77 ) ;
F_5 ( V_15 , L_78 ) ;
F_5 ( V_15 , L_79 ) ;
F_5 ( V_15 , L_80 ) ;
F_5 ( V_15 , L_81 ) ;
F_5 ( V_15 , L_82 ) ;
#ifndef F_23
F_5 ( V_15 , L_83 ) ;
#endif
#ifndef F_18
F_5 ( V_15 , L_84 ) ;
#endif
F_5 ( V_15 , L_85 ) ;
F_5 ( V_15 ,
L_86 ) ;
F_5 ( V_15 ,
L_87 ) ;
F_5 ( V_15 ,
L_88 ) ;
F_5 ( V_15 ,
L_89 ) ;
F_5 ( V_15 ,
L_90 ) ;
#ifndef F_16
F_5 ( V_15 ,
L_91 ) ;
#endif
F_5 ( V_15 ,
L_92 ) ;
F_5 ( V_15 , L_93 , V_54 ,
V_54 ) ;
#ifndef F_14
F_5 ( V_15 ,
L_94 ) ;
F_5 ( V_15 ,
L_95 ) ;
F_5 ( V_15 ,
L_96 ) ;
F_5 ( V_15 , L_25 , V_41 ) ;
F_5 ( V_15 ,
L_97 ) ;
F_5 ( V_15 , L_37 ,
V_41 ) ;
F_5 ( V_15 ,
L_98 ) ;
F_5 ( V_15 ,
L_99 ) ;
F_5 ( V_15 ,
L_100 ) ;
# ifndef F_24
F_5 ( V_15 ,
L_101 ) ;
# endif
# ifndef F_25
F_5 ( V_15 ,
L_102 ) ;
# endif
F_5 ( V_15 ,
L_103 ) ;
#endif
F_5 ( V_15 ,
L_104 ) ;
F_5 ( V_15 ,
L_105 ) ;
F_5 ( V_15 ,
L_106 ) ;
F_5 ( V_15 ,
L_107 ) ;
F_5 ( V_15 ,
L_108 ) ;
F_5 ( V_15 , L_109 ) ;
}
T_6 * F_26 ()
{
return ( & V_55 ) ;
}
static int F_27 ( T_7 * V_56 )
{
T_8 * V_57 ;
V_57 = ( T_8 * ) F_28 ( sizeof( T_8 ) + 1024 ) ;
V_57 -> V_58 = 1024 ;
V_57 -> V_59 [ 0 ] = '\0' ;
V_56 -> V_60 = ( char * ) V_57 ;
V_56 -> V_61 = 1 ;
V_56 -> V_62 = 0 ;
return ( 1 ) ;
}
static int F_29 ( T_7 * V_63 )
{
if ( V_63 == NULL )
return ( 0 ) ;
if ( V_63 -> V_60 != NULL )
F_30 ( V_63 -> V_60 ) ;
V_63 -> V_60 = NULL ;
V_63 -> V_61 = 0 ;
V_63 -> V_62 = 0 ;
return ( 1 ) ;
}
static int F_31 ( T_7 * V_64 , char * V_65 , int V_66 )
{
int V_11 = 0 ;
if ( V_65 == NULL || V_66 == 0 )
return ( 0 ) ;
if ( V_64 -> V_67 == NULL )
return ( 0 ) ;
V_11 = F_32 ( V_64 -> V_67 , V_65 , V_66 ) ;
if ( V_11 > 0 )
F_33 ( V_65 , V_65 , V_11 ) ;
return ( V_11 ) ;
}
static int F_34 ( T_7 * V_64 , const char * V_68 , int V_69 )
{
T_8 * V_57 ;
int V_11 = 0 ;
int V_70 ;
unsigned char V_71 ;
if ( ( V_68 == NULL ) || ( V_69 <= 0 ) )
return ( 0 ) ;
if ( V_64 -> V_67 == NULL )
return ( 0 ) ;
V_57 = ( T_8 * ) V_64 -> V_60 ;
if ( V_69 > ( V_70 = V_57 -> V_58 ) ) {
V_70 = V_70 + V_70 ;
if ( V_70 < V_69 )
V_70 = V_69 ;
F_30 ( V_57 ) ;
V_57 =
( T_8 * ) F_28 ( sizeof( T_8 ) + V_70 ) ;
V_57 -> V_58 = V_70 ;
V_57 -> V_59 [ 0 ] = '\0' ;
V_64 -> V_60 = ( char * ) V_57 ;
}
F_35 ( V_57 -> V_59 , V_68 , V_69 ) ;
V_11 = F_36 ( V_64 -> V_67 , V_57 -> V_59 , V_69 ) ;
return ( V_11 ) ;
}
static long F_37 ( T_7 * V_64 , int V_72 , long V_70 , void * V_60 )
{
long V_11 ;
if ( V_64 -> V_67 == NULL )
return ( 0 ) ;
switch ( V_72 ) {
case V_73 :
V_11 = 0L ;
break;
default:
V_11 = F_38 ( V_64 -> V_67 , V_72 , V_70 , V_60 ) ;
break;
}
return ( V_11 ) ;
}
static int F_39 ( T_7 * V_74 , char * V_75 , int V_76 )
{
int V_77 , V_11 = 0 ;
if ( V_74 -> V_67 == NULL )
return ( 0 ) ;
for ( V_77 = 0 ; V_77 < V_76 - 1 ; ++ V_77 ) {
V_11 = F_31 ( V_74 , & V_75 [ V_77 ] , 1 ) ;
if ( V_11 <= 0 )
break;
else if ( V_75 [ V_77 ] == '\n' ) {
++ V_77 ;
break;
}
}
if ( V_77 < V_76 )
V_75 [ V_77 ] = '\0' ;
return ( V_11 < 0 && V_77 == 0 ) ? V_11 : V_77 ;
}
static int F_40 ( T_7 * V_74 , const char * V_78 )
{
if ( V_74 -> V_67 == NULL )
return ( 0 ) ;
return F_34 ( V_74 , V_78 , strlen ( V_78 ) ) ;
}
static int T_4 F_41 ( T_2 * V_19 , int * V_20 , void * V_21 )
{
T_9 * V_2 = ( T_9 * ) V_21 ;
const char * V_79 = F_42 ( V_19 , V_80 ) ;
if ( V_79 && V_2 -> V_81 )
F_5 ( V_2 -> V_81 , L_110 ,
V_79 ) ;
if ( ! V_2 -> V_79 )
return V_82 ;
if ( V_79 ) {
if ( strcasecmp ( V_79 , V_2 -> V_79 ) )
return V_2 -> V_83 ;
if ( V_43 ) {
F_5 ( V_2 -> V_81 , L_111 ) ;
F_43 ( V_19 , V_43 ) ;
}
}
return V_84 ;
}
static int F_44 ( T_2 * V_19 , void * V_21 )
{
T_10 * V_85 = V_21 ;
T_7 * V_86 = V_85 -> V_86 ;
char * V_87 , * V_88 , * V_89 ;
int V_90 ;
unsigned char * V_91 = NULL ;
int V_92 ;
F_45 ( V_93 ) * V_94 = NULL ;
T_11 * V_95 = NULL ;
T_12 V_96 ;
T_13 V_97 ;
T_14 * V_98 = NULL ;
T_15 * V_99 = NULL ;
T_16 * V_100 = NULL ;
F_45 ( V_101 ) * V_102 ;
int V_11 = V_82 ;
int V_77 ;
# if 0
STACK_OF(OCSP_RESPID) *ids;
SSL_get_tlsext_status_ids(s, &ids);
BIO_printf(err, "cert_status: received %d ids\n",
sk_OCSP_RESPID_num(ids));
# endif
if ( V_85 -> V_103 )
F_46 ( V_86 , L_112 ) ;
V_95 = F_47 ( V_19 ) ;
V_94 = F_48 ( V_95 ) ;
if ( V_94 ) {
if ( ! F_49 ( F_50 ( V_94 , 0 ) ,
& V_87 , & V_88 , & V_89 , & V_90 ) ) {
F_46 ( V_86 , L_113 ) ;
goto V_86;
}
if ( V_85 -> V_103 )
F_5 ( V_86 , L_114 ,
F_50 ( V_94 , 0 ) ) ;
} else {
if ( ! V_85 -> V_87 ) {
F_46 ( V_85 -> V_86 ,
L_115 ) ;
goto V_104;
}
V_87 = V_85 -> V_87 ;
V_89 = V_85 -> V_89 ;
V_88 = V_85 -> V_88 ;
V_90 = V_85 -> V_90 ;
}
if ( ! F_51 ( & V_96 ,
F_52 ( F_53 ( V_19 ) ) ,
NULL , NULL ) )
goto V_86;
if ( F_54 ( & V_96 , V_105 ,
F_55 ( V_95 ) , & V_97 ) <= 0 ) {
F_46 ( V_86 , L_116 ) ;
F_56 ( & V_96 ) ;
goto V_104;
}
V_98 = F_57 () ;
if ( ! V_98 )
goto V_86;
V_100 = F_58 ( NULL , V_95 , V_97 . V_106 . V_107 ) ;
F_59 ( V_97 . V_106 . V_107 ) ;
F_56 ( & V_96 ) ;
if ( ! V_100 )
goto V_86;
if ( ! F_60 ( V_98 , V_100 ) )
goto V_86;
V_100 = NULL ;
F_61 ( V_19 , & V_102 ) ;
for ( V_77 = 0 ; V_77 < F_62 ( V_102 ) ; V_77 ++ ) {
V_101 * V_108 = F_63 ( V_102 , V_77 ) ;
if ( ! F_64 ( V_98 , V_108 , - 1 ) )
goto V_86;
}
V_99 = F_65 ( V_86 , V_98 , V_87 , V_89 , V_88 , V_90 , NULL ,
V_85 -> V_109 ) ;
if ( ! V_99 ) {
F_46 ( V_86 , L_117 ) ;
goto V_104;
}
V_92 = F_66 ( V_99 , & V_91 ) ;
if ( V_92 <= 0 )
goto V_86;
F_67 ( V_19 , V_91 , V_92 ) ;
if ( V_85 -> V_103 ) {
F_46 ( V_86 , L_118 ) ;
F_68 ( V_86 , V_99 , 2 ) ;
}
V_11 = V_84 ;
V_104:
if ( V_11 != V_84 )
F_69 ( V_86 ) ;
if ( V_94 ) {
F_30 ( V_87 ) ;
F_30 ( V_89 ) ;
F_30 ( V_88 ) ;
F_70 ( V_94 ) ;
}
if ( V_100 )
F_71 ( V_100 ) ;
if ( V_98 )
F_72 ( V_98 ) ;
if ( V_99 )
F_73 ( V_99 ) ;
return V_11 ;
V_86:
V_11 = V_110 ;
goto V_104;
}
static int F_74 ( T_2 * V_19 , const unsigned char * * V_106 ,
unsigned int * V_111 , void * V_21 )
{
T_17 * V_112 = V_21 ;
* V_106 = V_112 -> V_106 ;
* V_111 = V_112 -> V_111 ;
return V_84 ;
}
static int F_75 ( T_2 * V_19 , const unsigned char * * V_65 , unsigned char * V_113 ,
const unsigned char * V_68 , unsigned int V_114 , void * V_21 )
{
T_18 * V_115 = V_21 ;
if ( ! V_49 ) {
unsigned V_77 ;
F_5 ( V_14 , L_119 ) ;
for ( V_77 = 0 ; V_77 < V_114 ; ) {
if ( V_77 )
F_36 ( V_14 , L_120 , 2 ) ;
F_36 ( V_14 , & V_68 [ V_77 + 1 ] , V_68 [ V_77 ] ) ;
V_77 += V_68 [ V_77 ] + 1 ;
}
F_36 ( V_14 , L_15 , 1 ) ;
}
if ( F_76
( ( unsigned char * * ) V_65 , V_113 , V_115 -> V_106 , V_115 -> V_111 , V_68 ,
V_114 ) != V_116 ) {
return V_82 ;
}
if ( ! V_49 ) {
F_5 ( V_14 , L_121 ) ;
F_36 ( V_14 , * V_65 , * V_113 ) ;
F_36 ( V_14 , L_15 , 1 ) ;
}
return V_84 ;
}
int MAIN ( int V_117 , char * V_118 [] )
{
T_19 * V_119 = NULL ;
int V_120 = 0 ;
short V_88 = V_53 ;
char * V_121 = NULL , * V_122 = NULL ;
char * V_123 = NULL , * V_124 = NULL ;
char * V_125 = NULL , * V_126 = NULL ;
unsigned char * V_127 = NULL ;
char * V_128 = NULL ;
int V_129 = 0 ;
int V_11 = 1 ;
int V_130 = 0 ;
int V_131 = 0 , V_132 = 0 , V_133 = 0 , V_134 = 0 ;
int V_135 = 0 ;
const T_20 * V_136 = NULL ;
int V_137 = V_138 ;
T_21 * V_139 = NULL ;
char * V_140 = NULL ;
int V_141 = V_142 , V_143 = V_142 ;
char * V_144 = NULL , * V_145 = NULL ;
char * V_146 = NULL , * V_147 = NULL ;
int V_148 = V_142 , V_149 = V_142 ;
T_11 * V_150 = NULL , * V_151 = NULL ;
F_45 ( T_11 ) * V_152 = NULL , * V_153 = NULL ;
T_22 * V_154 = NULL , * V_155 = NULL ;
int V_156 = 0 , V_157 = 0 ;
int V_158 = 0 , V_159 = - 1 ;
#ifndef F_14
T_22 * V_160 = NULL ;
T_11 * V_161 = NULL ;
T_9 V_162 = { NULL , NULL , V_163 } ;
# ifndef F_24
const char * V_164 = NULL ;
T_17 V_112 = { NULL , 0 } ;
# endif
const char * V_165 = NULL ;
T_18 V_115 = { NULL , 0 } ;
#endif
#ifndef F_19
static char * V_166 = NULL ;
#endif
#ifndef F_21
char * V_167 = NULL ;
char * V_168 = NULL ;
#endif
T_23 * V_169 = NULL ;
T_24 * V_170 = NULL ;
F_45 ( V_93 ) * V_171 = NULL ;
char * V_172 = NULL ;
int V_173 = V_142 ;
int V_174 = 0 ;
F_45 ( V_175 ) * V_176 = NULL ;
V_136 = F_77 () ;
V_177 = V_117 ;
V_178 = V_118 ;
F_78 () ;
#ifdef F_79
F_13 () ;
#endif
if ( V_15 == NULL )
V_15 = F_80 ( V_179 , V_180 ) ;
if ( ! F_81 ( V_15 , NULL ) )
goto V_181;
V_170 = F_82 () ;
if ( ! V_170 )
goto V_181;
F_83 ( V_170 , V_182 ) ;
F_83 ( V_170 , V_183 ) ;
V_184 = 0 ;
#ifdef F_15
V_44 = 0 ;
#endif
V_45 = 0 ;
V_117 -- ;
V_118 ++ ;
while ( V_117 >= 1 ) {
if ( ( strcmp ( * V_118 , L_122 ) == 0 ) || ( strcmp ( * V_118 , L_123 ) == 0 ) ) {
if ( -- V_117 < 1 )
goto V_185;
if ( ! F_84 ( * ( ++ V_118 ) , & V_88 ) )
goto V_185;
} else if ( strcmp ( * V_118 , L_124 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_159 = atol ( * ( ++ V_118 ) ) ;
if ( V_159 <= 0 ) {
F_5 ( V_15 , L_125 , * V_118 ) ;
goto V_185;
}
} else if ( strcmp ( * V_118 , L_126 ) == 0 ) {
V_31 = V_186 | V_187 ;
if ( -- V_117 < 1 )
goto V_185;
V_184 = atoi ( * ( ++ V_118 ) ) ;
if ( ! V_49 )
F_5 ( V_15 , L_127 , V_184 ) ;
} else if ( strcmp ( * V_118 , L_128 ) == 0 ) {
V_31 =
V_186 | V_188 |
V_187 ;
if ( -- V_117 < 1 )
goto V_185;
V_184 = atoi ( * ( ++ V_118 ) ) ;
if ( ! V_49 )
F_5 ( V_15 ,
L_129 ,
V_184 ) ;
} else if ( strcmp ( * V_118 , L_130 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_127 = ( unsigned char * ) * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_131 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_36 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_132 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_172 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_133 ) == 0 )
V_174 = 1 ;
#ifndef F_14
else if ( strcmp ( * V_118 , L_134 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_189 = * ( ++ V_118 ) ;
}
#endif
else if ( strcmp ( * V_118 , L_135 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_141 = F_85 ( * ( ++ V_118 ) ) ;
} else if ( strcmp ( * V_118 , L_136 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_38 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_137 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_143 = F_85 ( * ( ++ V_118 ) ) ;
} else if ( strcmp ( * V_118 , L_138 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_144 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_139 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_39 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_140 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_128 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_141 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_148 = F_85 ( * ( ++ V_118 ) ) ;
} else if ( strcmp ( * V_118 , L_142 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_33 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_143 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_149 = F_85 ( * ( ++ V_118 ) ) ;
} else if ( strcmp ( * V_118 , L_144 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_146 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_145 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_34 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_146 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_35 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_147 ) == 0 ) {
V_134 = 1 ;
} else if ( strcmp ( * V_118 , L_148 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_121 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_149 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_123 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_150 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_125 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_151 ) == 0 )
V_156 = 1 ;
else if ( strcmp ( * V_118 , L_152 ) == 0 )
V_157 = 1 ;
else if ( strcmp ( * V_118 , L_153 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_173 = F_85 ( * ( ++ V_118 ) ) ;
} else if ( F_86 ( & V_118 , & V_117 , & V_120 , V_15 , & V_119 ) ) {
if ( V_120 )
goto V_185;
continue;
} else if ( F_87 ( & V_118 , & V_117 , & V_120 , V_15 , & V_169 ) ) {
if ( V_120 )
goto V_185;
continue;
} else if ( F_88 ( & V_118 , & V_117 , V_170 , & V_120 , V_15 , & V_171 ) ) {
if ( V_120 )
goto V_185;
continue;
} else if ( strcmp ( * V_118 , L_154 ) == 0 )
V_190 = 1 ;
else if ( strcmp ( * V_118 , L_155 ) == 0 )
V_191 = 1 ;
else if ( strcmp ( * V_118 , L_156 ) == 0 )
V_130 = 1 ;
else if ( strcmp ( * V_118 , L_157 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_122 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_158 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_124 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_159 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_126 = * ( ++ V_118 ) ;
}
#ifdef F_15
else if ( strcmp ( * V_118 , L_160 ) == 0 ) {
V_44 = 1 ;
}
#endif
else if ( strcmp ( * V_118 , L_161 ) == 0 ) {
#ifdef F_15
V_44 = 1 ;
#endif
V_45 = 1 ;
} else if ( strcmp ( * V_118 , L_162 ) == 0 )
V_192 = 1 ;
else if ( strcmp ( * V_118 , L_163 ) == 0 )
V_192 = 0 ;
else if ( strcmp ( * V_118 , L_164 ) == 0 ) {
V_13 = 1 ;
}
#ifndef F_14
else if ( strcmp ( * V_118 , L_165 ) == 0 )
V_193 = 1 ;
else if ( strcmp ( * V_118 , L_166 ) == 0 )
V_194 = 1 ;
else if ( strcmp ( * V_118 , L_167 ) == 0 ) {
V_194 = 1 ;
V_195 . V_103 = 1 ;
} else if ( ! strcmp ( * V_118 , L_168 ) ) {
V_194 = 1 ;
if ( -- V_117 < 1 )
goto V_185;
V_195 . V_109 = atoi ( * ( ++ V_118 ) ) ;
} else if ( ! strcmp ( * V_118 , L_169 ) ) {
V_194 = 1 ;
if ( -- V_117 < 1 )
goto V_185;
if ( ! F_49 ( * ( ++ V_118 ) ,
& V_195 . V_87 ,
& V_195 . V_88 ,
& V_195 . V_89 , & V_195 . V_90 ) ) {
F_5 ( V_15 , L_170 ) ;
goto V_185;
}
}
#endif
else if ( strcmp ( * V_118 , L_171 ) == 0 ) {
V_48 = 1 ;
} else if ( strcmp ( * V_118 , L_172 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_196 = F_89 ( * ( ++ V_118 ) , L_173 ) ;
}
#ifndef F_90
else if ( strcmp ( * V_118 , L_174 ) == 0 ) {
V_48 = 2 ;
}
#endif
else if ( strcmp ( * V_118 , L_175 ) == 0 ) {
V_51 = 1 ;
} else if ( strcmp ( * V_118 , L_176 ) == 0 ) {
V_135 = 1 ;
} else if ( strcmp ( * V_118 , L_177 ) == 0 ) {
V_197 = 1 ;
} else if ( strcmp ( * V_118 , L_178 ) == 0 ) {
V_49 = 1 ;
} else if ( strcmp ( * V_118 , L_179 ) == 0 ) {
V_49 = 1 ;
V_50 = 1 ;
V_191 = 1 ;
} else if ( strcmp ( * V_118 , L_180 ) == 0 ) {
V_131 = 1 ;
} else if ( strcmp ( * V_118 , L_181 ) == 0 ) {
V_132 = 1 ;
} else if ( strcmp ( * V_118 , L_182 ) == 0 ) {
V_133 = 1 ;
} else if ( strcmp ( * V_118 , L_183 ) == 0 ) {
V_198 = 1 ;
}
#ifndef F_19
else if ( strcmp ( * V_118 , L_184 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_166 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_185 ) == 0 ) {
T_25 V_77 ;
if ( -- V_117 < 1 )
goto V_185;
V_18 = * ( ++ V_118 ) ;
for ( V_77 = 0 ; V_77 < strlen ( V_18 ) ; V_77 ++ ) {
if ( isxdigit ( ( unsigned char ) V_18 [ V_77 ] ) )
continue;
F_5 ( V_15 , L_186 , * V_118 ) ;
goto V_185;
}
}
#endif
#ifndef F_21
else if ( strcmp ( * V_118 , L_187 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_168 = * ( ++ V_118 ) ;
V_136 = F_91 () ;
} else if ( strcmp ( * V_118 , L_188 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_167 = * ( ++ V_118 ) ;
V_136 = F_91 () ;
}
#endif
else if ( strcmp ( * V_118 , L_189 ) == 0 ) {
V_158 = 1 ;
} else if ( strcmp ( * V_118 , L_190 ) == 0 ) {
V_47 = 1 ;
} else if ( strcmp ( * V_118 , L_191 ) == 0 ) {
V_47 = 2 ;
} else if ( strcmp ( * V_118 , L_192 ) == 0 ) {
V_47 = 3 ;
}
#ifndef F_92
else if ( strcmp ( * V_118 , L_193 ) == 0 ) {
V_133 = 1 ;
V_136 = F_93 () ;
}
#endif
#ifndef F_22
else if ( strcmp ( * V_118 , L_194 ) == 0 ) {
V_136 = F_94 () ;
}
#endif
#ifndef F_95
else if ( strcmp ( * V_118 , L_195 ) == 0 ) {
V_136 = F_91 () ;
} else if ( strcmp ( * V_118 , L_196 ) == 0 ) {
V_136 = F_96 () ;
} else if ( strcmp ( * V_118 , L_197 ) == 0 ) {
V_136 = F_97 () ;
}
#endif
#ifndef F_98
else if ( strcmp ( * V_118 , L_198 ) == 0 ) {
V_136 = F_99 () ;
V_137 = V_199 ;
} else if ( strcmp ( * V_118 , L_199 ) == 0 ) {
V_136 = F_100 () ;
V_137 = V_199 ;
} else if ( strcmp ( * V_118 , L_200 ) == 0 ) {
V_136 = F_101 () ;
V_137 = V_199 ;
} else if ( strcmp ( * V_118 , L_201 ) == 0 )
V_200 = 1 ;
else if ( strcmp ( * V_118 , L_202 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_201 = atol ( * ( ++ V_118 ) ) ;
} else if ( strcmp ( * V_118 , L_203 ) == 0 )
V_202 = 1 ;
#endif
else if ( strcmp ( * V_118 , L_204 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_203 = * ( ++ V_118 ) ;
}
#ifndef F_16
else if ( strcmp ( * V_118 , L_205 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_52 = * ( ++ V_118 ) ;
}
#endif
else if ( strcmp ( * V_118 , L_206 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_140 = * ( ++ V_118 ) ;
}
#ifndef F_14
else if ( strcmp ( * V_118 , L_207 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_162 . V_79 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_208 ) == 0 ) {
V_162 . V_83 = V_110 ;
} else if ( strcmp ( * V_118 , L_209 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_40 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_210 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_42 = * ( ++ V_118 ) ;
}
# ifndef F_24
else if ( strcmp ( * V_118 , L_211 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_164 = * ( ++ V_118 ) ;
}
# endif
else if ( strcmp ( * V_118 , L_212 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_165 = * ( ++ V_118 ) ;
}
#endif
#if ! F_102 ( F_20 ) && ! F_102 ( F_19 )
else if ( strcmp ( * V_118 , L_213 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_204 = * ( ++ V_118 ) ;
}
#endif
#ifndef F_25
else if ( strcmp ( * V_118 , L_214 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_205 = * ( ++ V_118 ) ;
}
#endif
else if ( strcmp ( * V_118 , L_215 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_206 = * ( ++ V_118 ) ;
} else if ( strcmp ( * V_118 , L_216 ) == 0 ) {
if ( -- V_117 < 1 )
goto V_185;
V_207 = atoi ( * ( ++ V_118 ) ) ;
if ( V_207 == 0 )
goto V_185;
} else {
F_5 ( V_15 , L_217 , * V_118 ) ;
V_129 = 1 ;
break;
}
V_117 -- ;
V_118 ++ ;
}
if ( V_129 ) {
V_185:
F_17 () ;
goto V_181;
}
#ifndef F_98
if ( V_47 && V_137 == V_199 ) {
F_5 ( V_15 , L_218 ) ;
goto V_181;
}
#endif
#if ! F_102 ( F_20 ) && ! F_102 ( F_19 )
if ( V_204 ) {
if ( V_18 ) {
F_5 ( V_15 , L_219 ) ;
goto V_181;
}
V_17 = L_220 ;
}
#endif
F_103 () ;
F_104 () ;
#ifndef F_16
V_139 = F_105 ( V_15 , V_52 , 1 ) ;
#endif
if ( ! F_106 ( V_15 , V_144 , V_146 , & V_145 , & V_147 ) ) {
F_5 ( V_15 , L_221 ) ;
goto V_181;
}
if ( V_38 == NULL )
V_38 = V_36 ;
#ifndef F_14
if ( V_42 == NULL )
V_42 = V_40 ;
#endif
if ( ! F_107 ( & V_169 , V_15 ) )
goto V_181;
if ( V_134 == 0 ) {
V_154 = F_108 ( V_15 , V_38 , V_143 , 0 , V_145 , V_139 ,
L_222 ) ;
if ( ! V_154 ) {
F_69 ( V_15 ) ;
goto V_181;
}
V_150 = F_109 ( V_15 , V_36 , V_141 ,
NULL , V_139 , L_223 ) ;
if ( ! V_150 ) {
F_69 ( V_15 ) ;
goto V_181;
}
if ( V_39 ) {
V_152 = F_110 ( V_15 , V_39 , V_142 ,
NULL , V_139 , L_224 ) ;
if ( ! V_152 )
goto V_181;
}
#ifndef F_14
if ( V_162 . V_79 ) {
V_160 = F_108 ( V_15 , V_42 , V_143 , 0 , V_145 , V_139 ,
L_225 ) ;
if ( ! V_160 ) {
F_69 ( V_15 ) ;
goto V_181;
}
V_161 = F_109 ( V_15 , V_40 , V_141 ,
NULL , V_139 , L_226 ) ;
if ( ! V_161 ) {
F_69 ( V_15 ) ;
goto V_181;
}
}
#endif
}
#if ! F_102 ( F_14 )
# if ! F_102 ( F_24 )
if ( V_164 ) {
unsigned short V_111 ;
V_112 . V_106 = F_111 ( & V_111 , V_164 ) ;
if ( V_112 . V_106 == NULL )
goto V_181;
V_112 . V_111 = V_111 ;
} else {
V_112 . V_106 = NULL ;
}
# endif
V_115 . V_106 = NULL ;
if ( V_165 ) {
unsigned short V_111 ;
V_115 . V_106 = F_111 ( & V_111 , V_165 ) ;
if ( V_115 . V_106 == NULL )
goto V_181;
V_115 . V_111 = V_111 ;
}
#endif
if ( V_172 ) {
V_175 * V_208 ;
V_208 = F_112 ( V_172 , V_173 ) ;
if ( ! V_208 ) {
F_46 ( V_15 , L_227 ) ;
F_69 ( V_15 ) ;
goto V_181;
}
V_176 = F_113 () ;
if ( ! V_176 || ! F_114 ( V_176 , V_208 ) ) {
F_46 ( V_15 , L_228 ) ;
F_69 ( V_15 ) ;
F_115 ( V_208 ) ;
goto V_181;
}
}
if ( V_33 ) {
if ( V_34 == NULL )
V_34 = V_33 ;
V_155 = F_108 ( V_15 , V_34 , V_149 ,
0 , V_147 , V_139 , L_229 ) ;
if ( ! V_155 ) {
F_69 ( V_15 ) ;
goto V_181;
}
V_151 = F_109 ( V_15 , V_33 , V_148 ,
NULL , V_139 , L_226 ) ;
if ( ! V_151 ) {
F_69 ( V_15 ) ;
goto V_181;
}
if ( V_35 ) {
V_153 = F_110 ( V_15 , V_35 , V_142 ,
NULL , V_139 , L_230 ) ;
if ( ! V_153 )
goto V_181;
}
}
if ( ! F_116 ( NULL , V_15 , 1 ) && V_140 == NULL
&& ! F_117 () ) {
F_5 ( V_15 ,
L_231 ) ;
}
if ( V_140 != NULL )
F_5 ( V_15 , L_232 ,
F_118 ( V_140 ) ) ;
if ( V_14 == NULL ) {
if ( V_49 && ! V_13 ) {
V_14 = F_119 ( F_120 () ) ;
if ( V_48 && ! V_196 )
V_196 = F_80 ( stdout , V_180 ) ;
} else {
if ( V_14 == NULL )
V_14 = F_80 ( stdout , V_180 ) ;
}
}
#if ! F_102 ( V_209 ) || ! F_102 ( V_210 ) || ! F_102 ( V_211 )
if ( V_134 )
#endif
{
V_36 = NULL ;
V_38 = NULL ;
V_33 = NULL ;
V_34 = NULL ;
#ifndef F_14
V_40 = NULL ;
V_42 = NULL ;
#endif
}
V_46 = F_121 ( V_136 ) ;
if ( V_46 == NULL ) {
F_69 ( V_15 ) ;
goto V_181;
}
if ( V_203 ) {
if ( strlen ( V_203 ) >= 32 )
F_5 ( V_15 ,
L_233 ) ;
else if ( strlen ( V_203 ) >= 16 )
F_5 ( V_15 ,
L_234 ) ;
if ( ! F_122 ( V_46 , V_212 ) ) {
F_5 ( V_15 , L_235 ) ;
F_69 ( V_15 ) ;
goto V_181;
}
F_5 ( V_15 , L_236 , V_203 ) ;
}
F_123 ( V_46 , 1 ) ;
if ( V_51 )
F_124 ( V_46 , V_213 ) ;
if ( V_169 )
F_125 ( V_46 , V_169 ) ;
if ( V_137 == V_199 )
F_126 ( V_46 , 1 ) ;
if ( V_135 )
F_127 ( V_46 , V_214 ) ;
if ( V_156 )
F_128 ( V_46 , V_215 ) ;
else if ( V_157 )
F_129 ( V_46 ) ;
else
F_130 ( V_46 , 128 ) ;
#ifndef F_25
if ( V_205 != NULL )
F_131 ( V_46 , V_205 ) ;
#endif
#if 0
if (cipher == NULL)
cipher = getenv("SSL_CIPHER");
#endif
#if 0
if (s_cert_file == NULL) {
BIO_printf(bio_err,
"You must specify a certificate file for the server to use\n");
goto end;
}
#endif
if ( ( ! F_132 ( V_46 , V_122 , V_121 ) ) ||
( ! F_133 ( V_46 ) ) ) {
F_69 ( V_15 ) ;
}
if ( V_119 )
F_134 ( V_46 , V_119 ) ;
F_135 ( V_46 , V_176 , 0 ) ;
if ( ! F_136 ( V_46 , V_15 , V_170 , V_171 , V_133 , V_216 ) )
goto V_181;
if ( ! F_137 ( V_46 , V_125 , V_126 , V_123 , V_124 ,
V_176 , V_174 ) ) {
F_5 ( V_15 , L_237 ) ;
F_69 ( V_15 ) ;
goto V_181;
}
#ifndef F_14
if ( V_161 ) {
V_43 = F_121 ( V_136 ) ;
if ( V_43 == NULL ) {
F_69 ( V_15 ) ;
goto V_181;
}
}
if ( V_43 ) {
F_5 ( V_14 , L_238 ) ;
if ( V_203 ) {
if ( strlen ( V_203 ) >= 32 )
F_5 ( V_15 ,
L_233 ) ;
else if ( strlen ( V_203 ) >= 16 )
F_5 ( V_15 ,
L_234 ) ;
if ( ! F_122 ( V_43 , V_212 ) ) {
F_5 ( V_15 , L_235 ) ;
F_69 ( V_15 ) ;
goto V_181;
}
F_5 ( V_15 , L_236 , V_203 ) ;
}
F_123 ( V_43 , 1 ) ;
if ( V_51 )
F_124 ( V_43 , V_213 ) ;
if ( V_169 )
F_125 ( V_43 , V_169 ) ;
if ( V_137 == V_199 )
F_126 ( V_43 , 1 ) ;
if ( V_135 )
F_127 ( V_43 , V_214 ) ;
if ( V_156 )
F_128 ( V_43 , V_215 ) ;
else if ( V_157 )
F_129 ( V_43 ) ;
else
F_130 ( V_43 , 128 ) ;
if ( ( ! F_132 ( V_43 , V_122 , V_121 ) ) ||
( ! F_133 ( V_43 ) ) ) {
F_69 ( V_15 ) ;
}
if ( V_119 )
F_134 ( V_43 , V_119 ) ;
F_135 ( V_43 , V_176 , 0 ) ;
if ( ! F_136 ( V_43 , V_15 , V_170 , V_171 , V_133 , V_216 ) )
goto V_181;
}
# ifndef F_24
if ( V_112 . V_106 )
F_138 ( V_46 , F_74 ,
& V_112 ) ;
# endif
if ( V_115 . V_106 )
F_139 ( V_46 , F_75 , & V_115 ) ;
#endif
#ifndef F_23
if ( ! V_132 ) {
T_1 * V_1 = NULL ;
if ( V_128 )
V_1 = F_140 ( V_128 ) ;
else if ( V_36 )
V_1 = F_140 ( V_36 ) ;
if ( V_1 != NULL ) {
F_5 ( V_14 , L_239 ) ;
} else {
F_5 ( V_14 , L_240 ) ;
V_1 = F_1 () ;
}
( void ) F_141 ( V_14 ) ;
F_142 ( V_46 , V_1 ) ;
# ifndef F_14
if ( V_43 ) {
if ( ! V_128 ) {
T_1 * V_217 = F_140 ( V_40 ) ;
if ( V_217 != NULL ) {
F_5 ( V_14 , L_239 ) ;
( void ) F_141 ( V_14 ) ;
F_143 ( V_1 ) ;
V_1 = V_217 ;
}
}
F_142 ( V_43 , V_1 ) ;
}
# endif
F_143 ( V_1 ) ;
}
#endif
if ( ! F_144 ( V_46 , V_150 , V_154 , V_152 , V_130 ) )
goto V_181;
#ifndef F_14
if ( V_189 != NULL
&& ! F_145 ( V_46 , V_189 ) ) {
F_69 ( V_15 ) ;
goto V_181;
}
#endif
#ifndef F_14
if ( V_43 && ! F_144 ( V_43 , V_161 , V_160 , NULL , V_130 ) )
goto V_181;
#endif
if ( V_151 != NULL ) {
if ( ! F_144 ( V_46 , V_151 , V_155 , V_153 , V_130 ) )
goto V_181;
}
#ifndef V_209
# if 1
if ( ! V_131 ) {
F_146 ( V_46 , V_218 ) ;
# ifndef F_14
if ( V_43 )
F_146 ( V_43 , V_218 ) ;
# endif
}
# else
if ( ! V_131 && F_147 ( V_46 ) ) {
T_26 * V_219 ;
F_5 ( V_14 , L_241 ) ;
F_141 ( V_14 ) ;
V_219 = F_148 ( 512 , V_220 , NULL ) ;
if ( ! F_149 ( V_46 , V_219 ) ) {
F_69 ( V_15 ) ;
goto V_181;
}
# ifndef F_14
if ( V_43 ) {
if ( ! F_149 ( V_43 , V_219 ) ) {
F_69 ( V_15 ) ;
goto V_181;
}
}
# endif
F_150 ( V_219 ) ;
F_5 ( V_14 , L_15 ) ;
}
# endif
#endif
#ifndef F_19
# ifdef F_20
if ( V_18 != NULL )
# else
if ( V_18 != NULL || V_204 )
# endif
{
if ( V_13 )
F_5 ( V_14 ,
L_242 ) ;
F_151 ( V_46 , F_4 ) ;
}
if ( ! F_152 ( V_46 , V_166 ) ) {
F_5 ( V_15 , L_243 ) ;
F_69 ( V_15 ) ;
goto V_181;
}
#endif
F_153 ( V_46 , V_31 , V_221 ) ;
F_154 ( V_46 , ( void * ) & V_222 ,
sizeof V_222 ) ;
F_155 ( V_46 , V_223 ) ;
F_156 ( V_46 , V_224 ) ;
#ifndef F_14
if ( V_43 ) {
F_153 ( V_43 , V_31 , V_221 ) ;
F_154 ( V_43 ,
( void * ) & V_222 ,
sizeof V_222 ) ;
V_162 . V_81 = V_14 ;
F_157 ( V_43 , F_41 ) ;
F_158 ( V_43 , & V_162 ) ;
F_157 ( V_46 , F_41 ) ;
F_158 ( V_46 , & V_162 ) ;
}
#endif
#ifndef F_21
if ( V_168 != NULL ) {
V_225 . V_226 = F_159 ( V_167 ) ;
V_225 . V_23 = NULL ;
V_225 . V_22 = NULL ;
if ( ( V_11 =
F_160 ( V_225 . V_226 ,
V_168 ) ) != V_227 ) {
F_5 ( V_15 ,
L_244 ,
V_168 , V_11 ) ;
goto V_181;
}
F_153 ( V_46 , V_32 , V_221 ) ;
F_161 ( V_46 , & V_225 ) ;
F_162 ( V_46 , F_10 ) ;
} else
#endif
if ( V_122 != NULL ) {
F_163 ( V_46 , F_164 ( V_122 ) ) ;
#ifndef F_14
if ( V_43 )
F_163 ( V_43 , F_164 ( V_122 ) ) ;
#endif
}
F_5 ( V_14 , L_245 ) ;
( void ) F_141 ( V_14 ) ;
if ( V_158 )
F_165 ( V_88 , V_137 , & V_30 , V_228 , V_127 ,
V_159 ) ;
else if ( V_47 )
F_165 ( V_88 , V_137 , & V_30 , V_229 , V_127 ,
V_159 ) ;
else
F_165 ( V_88 , V_137 , & V_30 , V_230 , V_127 ,
V_159 ) ;
F_166 ( V_14 , V_46 ) ;
V_11 = 0 ;
V_181:
if ( V_46 != NULL )
F_167 ( V_46 ) ;
if ( V_150 )
F_59 ( V_150 ) ;
if ( V_176 )
F_168 ( V_176 , F_115 ) ;
if ( V_151 )
F_59 ( V_151 ) ;
if ( V_154 )
F_169 ( V_154 ) ;
if ( V_155 )
F_169 ( V_155 ) ;
if ( V_152 )
F_170 ( V_152 , F_59 ) ;
if ( V_153 )
F_170 ( V_153 , F_59 ) ;
if ( V_145 )
F_30 ( V_145 ) ;
if ( V_147 )
F_30 ( V_147 ) ;
if ( V_119 )
F_171 ( V_119 ) ;
F_172 () ;
#ifndef F_14
if ( V_195 . V_87 )
F_30 ( V_195 . V_87 ) ;
if ( V_195 . V_88 )
F_30 ( V_195 . V_88 ) ;
if ( V_195 . V_89 )
F_30 ( V_195 . V_89 ) ;
if ( V_43 != NULL )
F_167 ( V_43 ) ;
if ( V_161 )
F_59 ( V_161 ) ;
if ( V_160 )
F_169 ( V_160 ) ;
if ( V_231 != NULL )
F_173 ( V_231 ) ;
# ifndef F_24
if ( V_112 . V_106 )
F_30 ( V_112 . V_106 ) ;
# endif
if ( V_115 . V_106 )
F_30 ( V_115 . V_106 ) ;
#endif
F_174 ( V_169 ) ;
if ( V_171 )
F_175 ( V_171 ) ;
if ( V_170 )
F_176 ( V_170 ) ;
#ifndef F_20
if ( V_204 && V_18 )
F_30 ( V_18 ) ;
#endif
if ( V_14 != NULL ) {
F_173 ( V_14 ) ;
V_14 = NULL ;
}
if ( V_196 != NULL ) {
F_173 ( V_196 ) ;
V_196 = NULL ;
}
F_177 () ;
F_178 ( V_11 ) ;
}
static void F_166 ( T_7 * V_232 , T_27 * V_233 )
{
F_5 ( V_232 , L_246 ,
F_179 ( V_233 ) ) ;
F_5 ( V_232 , L_247 ,
F_180 ( V_233 ) ) ;
F_5 ( V_232 , L_248 ,
F_181 ( V_233 ) ) ;
F_5 ( V_232 , L_249 ,
F_182 ( V_233 ) ) ;
F_5 ( V_232 , L_250 ,
F_183 ( V_233 ) ) ;
F_5 ( V_232 , L_251 ,
F_184 ( V_233 ) ) ;
F_5 ( V_232 , L_252 ,
F_185 ( V_233 ) ) ;
F_5 ( V_232 , L_253 , F_186 ( V_233 ) ) ;
F_5 ( V_232 , L_254 ,
F_187 ( V_233 ) ) ;
F_5 ( V_232 , L_255 ,
F_188 ( V_233 ) ) ;
F_5 ( V_232 , L_256 ,
F_189 ( V_233 ) ) ;
F_5 ( V_232 , L_257 ,
F_190 ( V_233 ) ,
F_191 ( V_233 ) ) ;
}
static int V_230 ( char * V_234 , int V_19 , int V_235 , unsigned char * V_127 )
{
char * V_75 = NULL ;
T_28 V_236 ;
int V_11 = 1 , V_237 ;
int V_238 , V_77 ;
unsigned long V_239 ;
T_2 * V_240 = NULL ;
T_7 * V_241 ;
#ifndef F_192
T_29 * V_242 ;
#endif
struct V_243 V_109 ;
#if F_102 ( V_244 ) || F_102 ( V_245 ) || F_102 ( V_246 ) || F_102 ( V_247 )
struct V_243 V_248 ;
#else
struct V_243 * V_249 ;
#endif
if ( ( V_75 = F_28 ( V_250 ) ) == NULL ) {
F_5 ( V_15 , L_258 ) ;
goto V_86;
}
#ifdef F_15
if ( V_44 ) {
unsigned long V_251 = 1 ;
if ( ! V_49 )
F_5 ( V_15 , L_259 ) ;
if ( F_193 ( V_19 , F_15 , & V_251 ) < 0 )
F_69 ( V_15 ) ;
}
#endif
if ( V_240 == NULL ) {
V_240 = F_194 ( V_46 ) ;
#ifndef F_14
if ( V_193 ) {
F_195 ( V_240 , V_252 ) ;
F_196 ( V_240 , V_14 ) ;
}
if ( V_194 ) {
F_197 ( V_46 , F_44 ) ;
V_195 . V_86 = V_15 ;
F_198 ( V_46 , & V_195 ) ;
}
#endif
#ifndef F_192
if ( ( V_242 = F_199 () ) != NULL ) {
F_200 ( V_240 , V_242 ) ;
F_201 ( V_242 , V_253 , V_254 ) ;
F_201 ( V_242 , V_255 , V_256 ) ;
}
#endif
if ( V_127 )
F_202 ( V_240 , V_127 , strlen ( ( char * ) V_127 ) ) ;
}
F_203 ( V_240 ) ;
#if 0
# ifdef F_204
SSL_set_tlsext_opaque_prf_input(con, "Test server", 11);
# endif
#endif
if ( V_235 == V_199 ) {
V_241 = F_205 ( V_19 , V_180 ) ;
if ( V_200 ) {
V_109 . V_257 = 0 ;
V_109 . V_258 = V_259 ;
F_38 ( V_241 , V_260 , 0 , & V_109 ) ;
V_109 . V_257 = 0 ;
V_109 . V_258 = V_261 ;
F_38 ( V_241 , V_262 , 0 , & V_109 ) ;
}
if ( V_201 ) {
if ( V_201 < F_206 ( V_240 ) ) {
F_5 ( V_15 , L_260 ,
F_206 ( V_240 ) ) ;
V_11 = - 1 ;
F_173 ( V_241 ) ;
goto V_86;
}
F_207 ( V_240 , V_263 ) ;
if ( ! F_208 ( V_240 , V_201 ) ) {
F_5 ( V_15 , L_261 ) ;
V_11 = - 1 ;
F_173 ( V_241 ) ;
goto V_86;
}
} else
F_38 ( V_241 , V_264 , 0 , NULL ) ;
F_207 ( V_240 , V_265 ) ;
} else
V_241 = F_209 ( V_19 , V_180 ) ;
if ( V_45 ) {
T_7 * V_266 ;
V_266 = F_119 ( F_210 () ) ;
V_241 = F_211 ( V_266 , V_241 ) ;
}
#ifndef F_20
if ( V_204 )
F_212 ( V_14 , V_241 , V_204 ) ;
#endif
F_213 ( V_240 , V_241 , V_241 ) ;
F_214 ( V_240 ) ;
if ( V_13 ) {
F_215 ( V_240 , 1 ) ;
F_216 ( F_217 ( V_240 ) , V_267 ) ;
F_218 ( F_217 ( V_240 ) , ( char * ) V_14 ) ;
}
if ( V_48 ) {
#ifndef F_90
if ( V_48 == 2 )
F_219 ( V_240 , V_268 ) ;
else
#endif
F_219 ( V_240 , V_269 ) ;
F_220 ( V_240 , V_196 ? V_196 : V_14 ) ;
}
#ifndef F_14
if ( V_193 ) {
F_195 ( V_240 , V_252 ) ;
F_196 ( V_240 , V_14 ) ;
}
#endif
V_237 = V_19 + 1 ;
for (; ; ) {
int V_270 ;
int V_271 ;
V_270 = 0 ;
V_271 = F_221 ( V_240 ) ;
if ( ! V_271 ) {
F_222 ( & V_236 ) ;
#if ! F_102 ( V_244 ) && ! F_102 ( V_245 ) && ! F_102 ( V_246 ) && ! F_102 ( V_247 )
F_223 ( fileno ( V_272 ) , & V_236 ) ;
#endif
F_223 ( V_19 , & V_236 ) ;
#if F_102 ( V_244 ) || F_102 ( V_245 ) || F_102 ( V_246 )
V_248 . V_257 = 1 ;
V_248 . V_258 = 0 ;
V_77 = F_224 ( V_237 , ( void * ) & V_236 , NULL , NULL , & V_248 ) ;
if ( ( V_77 < 0 ) || ( ! V_77 && ! F_225 () ) )
continue;
if ( F_225 () )
V_270 = 1 ;
#elif F_102 ( V_247 )
V_248 . V_257 = 1 ;
V_248 . V_258 = 0 ;
( void ) F_226 ( fileno ( V_272 ) , V_273 , V_274 ) ;
V_77 = F_224 ( V_237 , ( void * ) & V_236 , NULL , NULL , & V_248 ) ;
if ( ( V_77 < 0 ) || ( ! V_77 && F_227 ( fileno ( V_272 ) , V_75 , 0 ) < 0 ) )
continue;
if ( F_227 ( fileno ( V_272 ) , V_75 , 0 ) >= 0 )
V_270 = 1 ;
( void ) F_226 ( fileno ( V_272 ) , V_273 , 0 ) ;
#else
if ( ( F_228 ( V_240 ) == V_275 ) &&
F_229 ( V_240 , & V_109 ) )
V_249 = & V_109 ;
else
V_249 = NULL ;
V_77 = F_224 ( V_237 , ( void * ) & V_236 , NULL , NULL , V_249 ) ;
if ( ( F_228 ( V_240 ) == V_275 )
&& F_230 ( V_240 ) > 0 ) {
F_5 ( V_15 , L_262 ) ;
}
if ( V_77 <= 0 )
continue;
if ( F_231 ( fileno ( V_272 ) , & V_236 ) )
V_270 = 1 ;
#endif
if ( F_231 ( V_19 , & V_236 ) )
V_271 = 1 ;
}
if ( V_270 ) {
if ( V_197 ) {
int V_276 , V_277 ;
V_77 = F_232 ( V_75 , V_250 / 2 ) ;
V_277 = 0 ;
for ( V_276 = 0 ; V_276 < V_77 ; V_276 ++ )
if ( V_75 [ V_276 ] == '\n' )
V_277 ++ ;
for ( V_276 = V_77 - 1 ; V_276 >= 0 ; V_276 -- ) {
V_75 [ V_276 + V_277 ] = V_75 [ V_276 ] ;
if ( V_75 [ V_276 ] == '\n' ) {
V_277 -- ;
V_77 ++ ;
V_75 [ V_276 + V_277 ] = '\r' ;
}
}
assert ( V_277 == 0 ) ;
} else
V_77 = F_232 ( V_75 , V_250 ) ;
if ( ! V_49 && ! V_50 ) {
if ( ( V_77 <= 0 ) || ( V_75 [ 0 ] == 'Q' ) ) {
F_5 ( V_14 , L_263 ) ;
F_233 ( V_19 ) ;
F_234 () ;
V_11 = - 11 ;
goto V_86;
}
if ( ( V_77 <= 0 ) || ( V_75 [ 0 ] == 'q' ) ) {
F_5 ( V_14 , L_263 ) ;
if ( F_228 ( V_240 ) != V_275 )
F_233 ( V_19 ) ;
goto V_86;
}
#ifndef F_235
if ( ( V_75 [ 0 ] == 'B' ) && ( ( V_75 [ 1 ] == '\n' ) || ( V_75 [ 1 ] == '\r' ) ) ) {
F_5 ( V_15 , L_264 ) ;
F_236 ( V_240 ) ;
V_77 = 0 ;
continue;
}
#endif
if ( ( V_75 [ 0 ] == 'r' ) && ( ( V_75 [ 1 ] == '\n' ) || ( V_75 [ 1 ] == '\r' ) ) ) {
F_237 ( V_240 ) ;
V_77 = F_238 ( V_240 ) ;
printf ( L_265 , V_77 ) ;
V_77 = 0 ;
continue;
}
if ( ( V_75 [ 0 ] == 'R' ) && ( ( V_75 [ 1 ] == '\n' ) || ( V_75 [ 1 ] == '\r' ) ) ) {
F_239 ( V_240 ,
V_186 | V_187 ,
NULL ) ;
F_237 ( V_240 ) ;
V_77 = F_238 ( V_240 ) ;
printf ( L_265 , V_77 ) ;
V_77 = 0 ;
continue;
}
if ( V_75 [ 0 ] == 'P' ) {
static const char * V_78 = L_266 ;
F_36 ( F_240 ( V_240 ) , V_78 , strlen ( V_78 ) ) ;
}
if ( V_75 [ 0 ] == 'S' ) {
F_166 ( V_14 , F_53 ( V_240 ) ) ;
}
}
#ifdef F_241
F_35 ( V_75 , V_75 , V_77 ) ;
#endif
V_239 = V_238 = 0 ;
for (; ; ) {
#ifdef F_242
{
static V_278 = 0 ;
if ( ++ V_278 == 100 ) {
V_278 = 0 ;
F_237 ( V_240 ) ;
}
}
#endif
V_238 = F_243 ( V_240 , & ( V_75 [ V_239 ] ) , ( unsigned int ) V_77 ) ;
#ifndef F_21
while ( F_244 ( V_240 , V_238 ) == V_279 ) {
F_5 ( V_14 , L_267 ) ;
V_225 . V_23 =
F_245 ( V_225 . V_226 ,
V_225 . V_22 ) ;
if ( V_225 . V_23 )
F_5 ( V_14 , L_268 ,
V_225 . V_23 -> V_27 ) ;
else
F_5 ( V_14 , L_269 ) ;
V_238 = F_243 ( V_240 , & ( V_75 [ V_239 ] ) , ( unsigned int ) V_77 ) ;
}
#endif
switch ( F_244 ( V_240 , V_238 ) ) {
case V_29 :
break;
case V_280 :
case V_281 :
case V_279 :
F_5 ( V_14 , L_270 ) ;
break;
case V_282 :
case V_283 :
F_5 ( V_14 , L_271 ) ;
F_69 ( V_15 ) ;
V_11 = 1 ;
goto V_86;
case V_284 :
F_5 ( V_14 , L_263 ) ;
V_11 = 1 ;
goto V_86;
}
V_239 += V_238 ;
V_77 -= V_238 ;
if ( V_77 <= 0 )
break;
}
}
if ( V_271 ) {
if ( ! F_246 ( V_240 ) ) {
V_77 = F_247 ( V_240 ) ;
if ( V_77 < 0 ) {
V_11 = 0 ;
goto V_86;
} else if ( V_77 == 0 ) {
V_11 = 1 ;
goto V_86;
}
} else {
V_285:
V_77 = F_248 ( V_240 , ( char * ) V_75 , V_250 ) ;
#ifndef F_21
while ( F_244 ( V_240 , V_77 ) == V_279 ) {
F_5 ( V_14 , L_272 ) ;
V_225 . V_23 =
F_245 ( V_225 . V_226 ,
V_225 . V_22 ) ;
if ( V_225 . V_23 )
F_5 ( V_14 , L_268 ,
V_225 . V_23 -> V_27 ) ;
else
F_5 ( V_14 , L_269 ) ;
V_77 = F_248 ( V_240 , ( char * ) V_75 , V_250 ) ;
}
#endif
switch ( F_244 ( V_240 , V_77 ) ) {
case V_29 :
#ifdef F_241
F_33 ( V_75 , V_75 , V_77 ) ;
#endif
F_249 ( V_75 , ( unsigned int ) V_77 ) ;
if ( F_221 ( V_240 ) )
goto V_285;
break;
case V_280 :
case V_281 :
F_5 ( V_14 , L_273 ) ;
break;
case V_282 :
case V_283 :
F_5 ( V_14 , L_271 ) ;
F_69 ( V_15 ) ;
V_11 = 1 ;
goto V_86;
case V_284 :
F_5 ( V_14 , L_263 ) ;
V_11 = 1 ;
goto V_86;
}
}
}
}
V_86:
if ( V_240 != NULL ) {
F_5 ( V_14 , L_274 ) ;
#if 1
F_250 ( V_240 , V_286 | V_287 ) ;
#else
F_251 ( V_240 ) ;
#endif
F_252 ( V_240 ) ;
}
F_5 ( V_14 , L_275 ) ;
if ( V_75 != NULL ) {
F_253 ( V_75 , V_250 ) ;
F_30 ( V_75 ) ;
}
if ( V_11 >= 0 )
F_5 ( V_14 , L_245 ) ;
return ( V_11 ) ;
}
static void F_234 ( void )
{
F_5 ( V_15 , L_276 ) ;
if ( V_30 >= 0 ) {
F_254 ( V_30 ) ;
}
}
static int F_247 ( T_2 * V_240 )
{
int V_77 ;
const char * V_78 ;
T_11 * V_288 ;
long V_289 ;
T_30 char V_75 [ V_290 ] ;
#ifndef F_192
char * V_291 ;
#endif
#if ! F_102 ( F_14 ) && ! F_102 ( F_24 )
const unsigned char * V_292 ;
unsigned V_293 ;
#endif
unsigned char * V_294 ;
V_77 = F_255 ( V_240 ) ;
#ifdef F_256
{
while ( V_77 <= 0 && F_244 ( V_240 , V_77 ) == V_279
&& F_257 ( V_240 ) == V_295 ) {
fprintf ( V_179 ,
L_277 ) ;
V_77 = F_255 ( V_240 ) ;
}
}
#endif
#ifndef F_21
while ( V_77 <= 0 && F_244 ( V_240 , V_77 ) == V_279 ) {
F_5 ( V_14 , L_278 ,
V_225 . V_22 ) ;
V_225 . V_23 =
F_245 ( V_225 . V_226 ,
V_225 . V_22 ) ;
if ( V_225 . V_23 )
F_5 ( V_14 , L_268 ,
V_225 . V_23 -> V_27 ) ;
else
F_5 ( V_14 , L_269 ) ;
V_77 = F_255 ( V_240 ) ;
}
#endif
if ( V_77 <= 0 ) {
if ( F_258 ( V_77 ) ) {
F_5 ( V_14 , L_279 ) ;
return ( 1 ) ;
}
F_5 ( V_15 , L_271 ) ;
V_289 = F_259 ( V_240 ) ;
if ( V_289 != V_296 ) {
F_5 ( V_15 , L_280 ,
F_260 ( V_289 ) ) ;
}
F_69 ( V_15 ) ;
return ( 0 ) ;
}
if ( V_50 )
F_261 ( V_15 , V_240 ) ;
F_262 ( V_14 , F_263 ( V_240 ) ) ;
V_288 = F_264 ( V_240 ) ;
if ( V_288 != NULL ) {
F_5 ( V_14 , L_281 ) ;
F_265 ( V_14 , V_288 ) ;
F_266 ( F_267 ( V_288 ) , V_75 , sizeof V_75 ) ;
F_5 ( V_14 , L_282 , V_75 ) ;
F_266 ( F_55 ( V_288 ) , V_75 , sizeof V_75 ) ;
F_5 ( V_14 , L_283 , V_75 ) ;
F_59 ( V_288 ) ;
}
if ( F_268 ( V_240 , V_75 , sizeof V_75 ) != NULL )
F_5 ( V_14 , L_284 , V_75 ) ;
V_78 = F_269 ( F_270 ( V_240 ) ) ;
F_271 ( V_14 , V_240 ) ;
#ifndef F_272
F_273 ( V_14 , V_240 ) ;
F_274 ( V_14 , V_240 , 0 ) ;
#endif
F_5 ( V_14 , L_285 , ( V_78 != NULL ) ? V_78 : L_286 ) ;
#if ! F_102 ( F_14 ) && ! F_102 ( F_24 )
F_275 ( V_240 , & V_292 , & V_293 ) ;
if ( V_292 ) {
F_5 ( V_14 , L_287 ) ;
F_36 ( V_14 , V_292 , V_293 ) ;
F_5 ( V_14 , L_15 ) ;
}
#endif
#ifndef F_25
{
T_31 * V_297
= F_276 ( V_240 ) ;
if ( V_297 )
F_5 ( V_14 , L_288 ,
V_297 -> V_298 ) ;
}
#endif
if ( F_277 ( V_240 ) )
F_5 ( V_14 , L_289 ) ;
if ( F_278 ( V_240 , V_299 , 0 , NULL ) &
V_300 )
F_5 ( V_14 , L_290 ) ;
#ifndef F_192
V_291 = F_279 ( F_280 ( V_240 ) ) ;
if ( V_291 != NULL ) {
F_5 ( V_14 , L_291 ,
V_291 ) ;
}
#endif
F_5 ( V_14 , L_292 ,
F_281 ( V_240 ) ? L_293 : L_294 ) ;
if ( V_206 != NULL ) {
F_5 ( V_14 , L_295 ) ;
F_5 ( V_14 , L_296 , V_206 ) ;
F_5 ( V_14 , L_297 , V_207 ) ;
V_294 = F_28 ( V_207 ) ;
if ( V_294 != NULL ) {
if ( ! F_282 ( V_240 , V_294 ,
V_207 ,
V_206 ,
strlen ( V_206 ) ,
NULL , 0 , 0 ) ) {
F_5 ( V_14 , L_298 ) ;
} else {
F_5 ( V_14 , L_299 ) ;
for ( V_77 = 0 ; V_77 < V_207 ; V_77 ++ )
F_5 ( V_14 , L_300 , V_294 [ V_77 ] ) ;
F_5 ( V_14 , L_15 ) ;
}
F_30 ( V_294 ) ;
}
}
return ( 1 ) ;
}
static T_1 * F_140 ( const char * V_128 )
{
T_1 * V_11 = NULL ;
T_7 * V_232 ;
if ( ( V_232 = F_89 ( V_128 , L_301 ) ) == NULL )
goto V_86;
V_11 = F_283 ( V_232 , NULL , NULL , NULL ) ;
V_86:
if ( V_232 != NULL )
F_173 ( V_232 ) ;
return ( V_11 ) ;
}
static int V_229 ( char * V_234 , int V_19 , int V_235 , unsigned char * V_127 )
{
char * V_75 = NULL ;
int V_11 = 1 ;
int V_77 , V_276 , V_238 , V_301 ;
T_2 * V_240 ;
const T_32 * V_302 ;
T_7 * V_303 , * V_304 , * V_241 ;
#ifndef F_192
T_29 * V_242 ;
#endif
V_75 = F_28 ( V_250 ) ;
if ( V_75 == NULL )
return ( 0 ) ;
V_303 = F_119 ( F_284 () ) ;
V_304 = F_119 ( F_285 () ) ;
if ( ( V_303 == NULL ) || ( V_304 == NULL ) )
goto V_86;
#ifdef F_15
if ( V_44 ) {
unsigned long V_251 = 1 ;
if ( ! V_49 )
F_5 ( V_15 , L_259 ) ;
if ( F_193 ( V_19 , F_15 , & V_251 ) < 0 )
F_69 ( V_15 ) ;
}
#endif
if ( ! F_286 ( V_303 , V_250 ) )
goto V_86;
if ( ( V_240 = F_194 ( V_46 ) ) == NULL )
goto V_86;
#ifndef F_14
if ( V_193 ) {
F_195 ( V_240 , V_252 ) ;
F_196 ( V_240 , V_14 ) ;
}
#endif
#ifndef F_192
if ( ( V_242 = F_199 () ) != NULL ) {
F_201 ( V_242 , V_253 , V_254 ) ;
F_201 ( V_242 , V_255 , V_256 ) ;
}
#endif
if ( V_127 )
F_202 ( V_240 , V_127 , strlen ( ( char * ) V_127 ) ) ;
V_241 = F_209 ( V_19 , V_180 ) ;
if ( V_45 ) {
T_7 * V_266 ;
V_266 = F_119 ( F_210 () ) ;
V_241 = F_211 ( V_266 , V_241 ) ;
}
F_213 ( V_240 , V_241 , V_241 ) ;
F_214 ( V_240 ) ;
F_287 ( V_304 , V_240 , V_305 ) ;
F_211 ( V_303 , V_304 ) ;
#ifdef F_241
V_303 = F_211 ( F_119 ( F_26 () ) , V_303 ) ;
#endif
if ( V_13 ) {
F_215 ( V_240 , 1 ) ;
F_216 ( F_217 ( V_240 ) , V_267 ) ;
F_218 ( F_217 ( V_240 ) , ( char * ) V_14 ) ;
}
if ( V_48 ) {
#ifndef F_90
if ( V_48 == 2 )
F_219 ( V_240 , V_268 ) ;
else
#endif
F_219 ( V_240 , V_269 ) ;
F_220 ( V_240 , V_196 ? V_196 : V_14 ) ;
}
for (; ; ) {
if ( V_51 ) {
V_77 = F_255 ( V_240 ) ;
#ifndef F_21
while ( V_77 <= 0
&& F_244 ( V_240 , V_77 ) == V_279 ) {
F_5 ( V_14 , L_278 ,
V_225 . V_22 ) ;
V_225 . V_23 =
F_245 ( V_225 . V_226 ,
V_225 . V_22 ) ;
if ( V_225 . V_23 )
F_5 ( V_14 , L_268 ,
V_225 . V_23 -> V_27 ) ;
else
F_5 ( V_14 , L_269 ) ;
V_77 = F_255 ( V_240 ) ;
}
#endif
switch ( F_244 ( V_240 , V_77 ) ) {
case V_29 :
break;
case V_280 :
case V_281 :
case V_279 :
continue;
case V_282 :
case V_283 :
case V_284 :
V_11 = 1 ;
goto V_86;
}
F_237 ( V_240 ) ;
F_243 ( V_240 , NULL , 0 ) ;
}
V_77 = F_288 ( V_303 , V_75 , V_250 - 1 ) ;
if ( V_77 < 0 ) {
if ( ! F_289 ( V_303 ) ) {
if ( ! V_49 )
F_69 ( V_15 ) ;
goto V_86;
} else {
F_5 ( V_14 , L_302 ) ;
#if F_102 ( V_246 )
F_290 ( 1000 ) ;
#elif ! F_102 ( V_245 ) && ! F_102 ( V_306 )
F_291 ( 1 ) ;
#endif
continue;
}
} else if ( V_77 == 0 ) {
V_11 = 1 ;
goto V_181;
}
if ( ( ( V_47 == 1 ) && ( strncmp ( L_303 , V_75 , 4 ) == 0 ) ) ||
( ( V_47 == 2 ) && ( strncmp ( L_304 , V_75 , 10 ) == 0 ) ) ) {
char * V_2 ;
T_11 * V_288 ;
F_45 ( T_32 ) * V_307 ;
static const char * V_308 = L_305 ;
F_46 ( V_303 ,
L_306 ) ;
F_46 ( V_303 , L_307 ) ;
F_46 ( V_303 , L_308 ) ;
F_46 ( V_303 , L_15 ) ;
for ( V_77 = 0 ; V_77 < V_177 ; V_77 ++ ) {
F_46 ( V_303 , V_178 [ V_77 ] ) ;
F_36 ( V_303 , L_309 , 1 ) ;
}
F_46 ( V_303 , L_15 ) ;
F_5 ( V_303 ,
L_292 ,
F_281 ( V_240 ) ?
L_293 : L_294 ) ;
F_5 ( V_303 , L_310 ) ;
V_307 = F_292 ( V_240 ) ;
V_276 = F_293 ( V_307 ) ;
for ( V_77 = 0 ; V_77 < V_276 ; V_77 ++ ) {
V_302 = F_294 ( V_307 , V_77 ) ;
F_5 ( V_303 , L_311 ,
F_295 ( V_302 ) , F_269 ( V_302 ) ) ;
if ( ( ( ( V_77 + 1 ) % 2 ) == 0 ) && ( V_77 + 1 != V_276 ) )
F_46 ( V_303 , L_15 ) ;
}
F_46 ( V_303 , L_15 ) ;
V_2 = F_268 ( V_240 , V_75 , V_250 ) ;
if ( V_2 != NULL ) {
F_5 ( V_303 ,
L_312 ) ;
V_276 = V_77 = 0 ;
while ( * V_2 ) {
if ( * V_2 == ':' ) {
F_36 ( V_303 , V_308 , 26 - V_276 ) ;
V_77 ++ ;
V_276 = 0 ;
F_36 ( V_303 , ( ( V_77 % 3 ) ? L_309 : L_15 ) , 1 ) ;
} else {
F_36 ( V_303 , V_2 , 1 ) ;
V_276 ++ ;
}
V_2 ++ ;
}
F_46 ( V_303 , L_15 ) ;
}
F_271 ( V_303 , V_240 ) ;
#ifndef F_272
F_274 ( V_303 , V_240 , 0 ) ;
#endif
F_5 ( V_303 , ( F_277 ( V_240 )
? L_313 : L_314 ) ) ;
V_302 = F_270 ( V_240 ) ;
F_5 ( V_303 , L_315 ,
F_295 ( V_302 ) , F_269 ( V_302 ) ) ;
F_296 ( V_303 , F_263 ( V_240 ) ) ;
F_5 ( V_303 , L_316 ) ;
F_166 ( V_303 , F_53 ( V_240 ) ) ;
F_5 ( V_303 , L_316 ) ;
V_288 = F_264 ( V_240 ) ;
if ( V_288 != NULL ) {
F_5 ( V_303 , L_281 ) ;
F_297 ( V_303 , V_288 ) ;
F_265 ( V_303 , V_288 ) ;
} else
F_46 ( V_303 , L_317 ) ;
F_46 ( V_303 , L_318 ) ;
break;
} else if ( ( V_47 == 2 || V_47 == 3 )
&& ( strncmp ( L_319 , V_75 , 5 ) == 0 ) ) {
T_7 * V_309 ;
char * V_2 , * V_139 ;
static const char * V_310 =
L_320 ;
V_2 = & ( V_75 [ 5 ] ) ;
V_301 = 1 ;
for ( V_139 = V_2 ; * V_139 != '\0' ; V_139 ++ ) {
if ( V_139 [ 0 ] == ' ' )
break;
switch ( V_301 ) {
case 1 :
V_301 = ( V_139 [ 0 ] == '.' ) ? 2 : 0 ;
break;
case 2 :
V_301 = ( V_139 [ 0 ] == '.' ) ? 3 : 0 ;
break;
case 3 :
V_301 = ( V_139 [ 0 ] == '/' ) ? - 1 : 0 ;
break;
}
if ( V_301 == 0 )
V_301 = ( V_139 [ 0 ] == '/' ) ? 1 : 0 ;
}
V_301 = ( V_301 == 3 ) || ( V_301 == - 1 ) ;
if ( * V_139 == '\0' ) {
F_46 ( V_303 , V_310 ) ;
F_5 ( V_303 , L_321 , V_2 ) ;
break;
}
* V_139 = '\0' ;
if ( V_301 ) {
F_46 ( V_303 , V_310 ) ;
F_5 ( V_303 , L_322 , V_2 ) ;
break;
}
if ( * V_2 == '/' ) {
F_46 ( V_303 , V_310 ) ;
F_5 ( V_303 , L_323 , V_2 ) ;
break;
}
#if 0
if (e[-1] == '/')
strcat(p, "index.html");
#endif
if ( F_298 ( V_2 ) > 0 ) {
#if 0
strcat(p, "/index.html");
#else
F_46 ( V_303 , V_310 ) ;
F_5 ( V_303 , L_324 , V_2 ) ;
break;
#endif
}
if ( ( V_309 = F_89 ( V_2 , L_301 ) ) == NULL ) {
F_46 ( V_303 , V_310 ) ;
F_5 ( V_303 , L_325 , V_2 ) ;
F_69 ( V_303 ) ;
break;
}
if ( ! V_49 )
F_5 ( V_15 , L_326 , V_2 ) ;
if ( V_47 == 2 ) {
V_77 = strlen ( V_2 ) ;
if ( ( ( V_77 > 5 ) && ( strcmp ( & ( V_2 [ V_77 - 5 ] ) , L_327 ) == 0 ) ) ||
( ( V_77 > 4 ) && ( strcmp ( & ( V_2 [ V_77 - 4 ] ) , L_328 ) == 0 ) ) ||
( ( V_77 > 4 ) && ( strcmp ( & ( V_2 [ V_77 - 4 ] ) , L_329 ) == 0 ) ) )
F_46 ( V_303 ,
L_306 ) ;
else
F_46 ( V_303 ,
L_320 ) ;
}
for (; ; ) {
V_77 = F_32 ( V_309 , V_75 , V_250 ) ;
if ( V_77 <= 0 )
break;
#ifdef F_242
V_311 += V_77 ;
fprintf ( V_179 , L_330 , V_77 ) ;
if ( V_311 > 3 * 1024 ) {
V_311 = 0 ;
fprintf ( V_179 , L_331 ) ;
F_237 ( V_240 ) ;
}
#endif
for ( V_276 = 0 ; V_276 < V_77 ; ) {
#ifdef F_242
{
static V_278 = 0 ;
if ( ++ V_278 == 13 ) {
F_237 ( V_240 ) ;
}
}
#endif
V_238 = F_36 ( V_303 , & ( V_75 [ V_276 ] ) , V_77 - V_276 ) ;
if ( V_238 <= 0 ) {
if ( ! F_289 ( V_303 ) )
goto V_312;
else {
F_5 ( V_14 , L_332 ) ;
}
} else {
V_276 += V_238 ;
}
}
}
V_312:
F_173 ( V_309 ) ;
break;
}
}
for (; ; ) {
V_77 = ( int ) F_141 ( V_303 ) ;
if ( V_77 <= 0 ) {
if ( ! F_289 ( V_303 ) )
break;
} else
break;
}
V_181:
#if 1
F_250 ( V_240 , V_286 | V_287 ) ;
#else
#endif
V_86:
if ( V_11 >= 0 )
F_5 ( V_14 , L_245 ) ;
if ( V_75 != NULL )
F_30 ( V_75 ) ;
if ( V_303 != NULL )
F_299 ( V_303 ) ;
return ( V_11 ) ;
}
static int V_228 ( char * V_234 , int V_19 , int V_235 , unsigned char * V_127 )
{
char * V_75 = NULL ;
int V_77 ;
int V_11 = 1 ;
T_2 * V_240 ;
T_7 * V_303 , * V_304 , * V_241 ;
#ifndef F_192
T_29 * V_242 ;
#endif
V_75 = F_28 ( V_250 ) ;
if ( V_75 == NULL )
return ( 0 ) ;
V_303 = F_119 ( F_284 () ) ;
V_304 = F_119 ( F_285 () ) ;
if ( ( V_303 == NULL ) || ( V_304 == NULL ) )
goto V_86;
if ( ! F_286 ( V_303 , V_250 ) )
goto V_86;
if ( ( V_240 = F_194 ( V_46 ) ) == NULL )
goto V_86;
#ifndef F_14
if ( V_193 ) {
F_195 ( V_240 , V_252 ) ;
F_196 ( V_240 , V_14 ) ;
}
#endif
#ifndef F_192
if ( ( V_242 = F_199 () ) != NULL ) {
F_201 ( V_242 , V_253 , V_254 ) ;
F_201 ( V_242 , V_255 , V_256 ) ;
}
#endif
if ( V_127 )
F_202 ( V_240 , V_127 , strlen ( ( char * ) V_127 ) ) ;
V_241 = F_209 ( V_19 , V_180 ) ;
F_213 ( V_240 , V_241 , V_241 ) ;
F_214 ( V_240 ) ;
F_287 ( V_304 , V_240 , V_305 ) ;
F_211 ( V_303 , V_304 ) ;
#ifdef F_241
V_303 = F_211 ( F_119 ( F_26 () ) , V_303 ) ;
#endif
if ( V_13 ) {
F_215 ( V_240 , 1 ) ;
F_216 ( F_217 ( V_240 ) , V_267 ) ;
F_218 ( F_217 ( V_240 ) , ( char * ) V_14 ) ;
}
if ( V_48 ) {
#ifndef F_90
if ( V_48 == 2 )
F_219 ( V_240 , V_268 ) ;
else
#endif
F_219 ( V_240 , V_269 ) ;
F_220 ( V_240 , V_196 ? V_196 : V_14 ) ;
}
for (; ; ) {
V_77 = F_300 ( V_303 ) ;
if ( V_77 > 0 )
break;
if ( ! F_289 ( V_303 ) ) {
F_46 ( V_15 , L_333 ) ;
F_69 ( V_15 ) ;
goto V_181;
}
}
F_5 ( V_15 , L_334 ) ;
F_261 ( V_15 , V_240 ) ;
for (; ; ) {
V_77 = F_288 ( V_303 , V_75 , V_250 - 1 ) ;
if ( V_77 < 0 ) {
if ( ! F_289 ( V_303 ) ) {
if ( ! V_49 )
F_69 ( V_15 ) ;
goto V_86;
} else {
F_5 ( V_14 , L_302 ) ;
#if F_102 ( V_246 )
F_290 ( 1000 ) ;
#elif ! F_102 ( V_245 ) && ! F_102 ( V_306 )
F_291 ( 1 ) ;
#endif
continue;
}
} else if ( V_77 == 0 ) {
V_11 = 1 ;
F_5 ( V_15 , L_275 ) ;
goto V_181;
} else {
char * V_2 = V_75 + V_77 - 1 ;
while ( V_77 && ( * V_2 == '\n' || * V_2 == '\r' ) ) {
V_2 -- ;
V_77 -- ;
}
if ( ! V_192 && V_77 == 5 && ! strncmp ( V_75 , L_335 , 5 ) ) {
V_11 = 1 ;
F_5 ( V_15 , L_275 ) ;
goto V_181;
}
F_301 ( ( unsigned char * ) V_75 , NULL , V_77 ) ;
V_75 [ V_77 ] = '\n' ;
F_36 ( V_303 , V_75 , V_77 + 1 ) ;
for (; ; ) {
V_77 = F_141 ( V_303 ) ;
if ( V_77 > 0 )
break;
if ( ! F_289 ( V_303 ) )
goto V_181;
}
}
}
V_181:
F_250 ( V_240 , V_286 | V_287 ) ;
V_86:
if ( V_75 != NULL )
F_30 ( V_75 ) ;
if ( V_303 != NULL )
F_299 ( V_303 ) ;
return ( V_11 ) ;
}
static T_26 T_4 * V_218 ( T_2 * V_19 , int V_313 , int V_314 )
{
T_3 * V_12 = NULL ;
static T_26 * V_315 = NULL ;
if ( ! V_315 && ( ( V_12 = F_302 () ) == NULL ) )
F_5 ( V_15 , L_336 ) ;
if ( ! V_315 && V_12 ) {
if ( ! V_49 ) {
F_5 ( V_15 , L_337 ,
V_314 ) ;
( void ) F_141 ( V_15 ) ;
}
if ( ! F_303 ( V_12 , V_220 ) || ( ( V_315 = F_304 () ) == NULL ) ||
! F_305 ( V_315 , V_314 , V_12 , NULL ) ) {
if ( V_315 )
F_150 ( V_315 ) ;
V_315 = NULL ;
}
if ( ! V_49 ) {
F_5 ( V_15 , L_15 ) ;
( void ) F_141 ( V_15 ) ;
}
F_7 ( V_12 ) ;
}
return ( V_315 ) ;
}
static int V_212 ( const T_2 * V_6 , unsigned char * V_100 ,
unsigned int * V_316 )
{
unsigned int V_278 = 0 ;
do {
F_306 ( V_100 , * V_316 ) ;
memcpy ( V_100 , V_203 ,
( strlen ( V_203 ) < * V_316 ) ?
strlen ( V_203 ) : * V_316 ) ;
}
while ( F_307 ( V_6 , V_100 , * V_316 ) &&
( ++ V_278 < V_317 ) );
if ( V_278 >= V_317 )
return 0 ;
return 1 ;
}
static int F_308 ( T_2 * V_6 , T_33 * V_318 )
{
T_34 * V_319 ;
unsigned char * V_2 ;
V_319 = F_28 ( sizeof( T_34 ) ) ;
F_309 ( V_318 , & V_319 -> V_320 ) ;
V_319 -> V_321 = F_310 ( V_318 , NULL ) ;
V_319 -> V_100 = F_311 ( F_309 ( V_318 , NULL ) , V_319 -> V_320 ) ;
V_319 -> V_322 = F_28 ( V_319 -> V_321 ) ;
V_2 = V_319 -> V_322 ;
F_310 ( V_318 , & V_2 ) ;
V_319 -> V_323 = V_324 ;
V_324 = V_319 ;
F_5 ( V_15 , L_338 ) ;
return 0 ;
}
static T_33 * F_312 ( T_2 * V_6 , unsigned char * V_100 , int V_320 ,
int * V_325 )
{
T_34 * V_319 ;
* V_325 = 0 ;
for ( V_319 = V_324 ; V_319 ; V_319 = V_319 -> V_323 ) {
if ( V_320 == ( int ) V_319 -> V_320 && ! memcmp ( V_319 -> V_100 , V_100 , V_320 ) ) {
const unsigned char * V_2 = V_319 -> V_322 ;
F_5 ( V_15 , L_339 ) ;
return F_313 ( NULL , & V_2 , V_319 -> V_321 ) ;
}
}
F_5 ( V_15 , L_340 ) ;
return NULL ;
}
static void F_314 ( T_27 * V_326 , T_33 * V_318 )
{
T_34 * V_319 , * V_327 = NULL ;
const unsigned char * V_100 ;
unsigned int V_320 ;
V_100 = F_309 ( V_318 , & V_320 ) ;
for ( V_319 = V_324 ; V_319 ; V_319 = V_319 -> V_323 ) {
if ( V_320 == V_319 -> V_320 && ! memcmp ( V_319 -> V_100 , V_100 , V_320 ) ) {
if ( V_327 )
V_327 -> V_323 = V_319 -> V_323 ;
else
V_324 = V_319 -> V_323 ;
F_30 ( V_319 -> V_100 ) ;
F_30 ( V_319 -> V_322 ) ;
F_30 ( V_319 ) ;
return;
}
V_327 = V_319 ;
}
}
static void F_129 ( T_27 * V_326 )
{
F_128 ( V_326 ,
V_328 |
V_329 ) ;
F_315 ( V_326 , F_308 ) ;
F_316 ( V_326 , F_312 ) ;
F_317 ( V_326 , F_314 ) ;
}
static void F_172 ( void )
{
T_34 * V_319 , * V_330 ;
for ( V_319 = V_324 ; V_319 ; ) {
F_30 ( V_319 -> V_100 ) ;
F_30 ( V_319 -> V_322 ) ;
V_330 = V_319 ;
V_319 = V_319 -> V_323 ;
F_30 ( V_330 ) ;
}
V_324 = NULL ;
}
