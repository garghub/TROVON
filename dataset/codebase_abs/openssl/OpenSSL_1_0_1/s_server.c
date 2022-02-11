static T_1 * F_1 ( void )
{
T_1 * V_1 = NULL ;
if ( ( V_1 = F_2 () ) == NULL ) return ( NULL ) ;
V_1 -> V_2 = F_3 ( V_3 , sizeof( V_3 ) , NULL ) ;
V_1 -> V_4 = F_3 ( V_5 , sizeof( V_5 ) , NULL ) ;
if ( ( V_1 -> V_2 == NULL ) || ( V_1 -> V_4 == NULL ) )
return ( NULL ) ;
return ( V_1 ) ;
}
static unsigned int F_4 ( T_2 * V_6 , const char * V_7 ,
unsigned char * V_8 , unsigned int V_9 )
{
unsigned int V_10 = 0 ;
int V_11 ;
T_3 * V_12 = NULL ;
if ( V_13 )
F_5 ( V_14 , L_1 ) ;
if ( ! V_7 )
{
F_5 ( V_15 , L_2 ) ;
goto V_16;
}
if ( V_13 )
F_5 ( V_14 , L_3 ,
V_7 ? ( int ) strlen ( V_7 ) : 0 , V_7 ) ;
if ( strcmp ( V_7 , V_17 ) != 0 )
{
F_5 ( V_14 , L_4
L_5 , V_7 ,
V_17 ) ;
goto V_16;
}
if ( V_13 )
F_5 ( V_14 , L_6 ) ;
V_11 = F_6 ( & V_12 , V_18 ) ;
if ( ! V_11 )
{
F_5 ( V_15 , L_7 , V_18 ) ;
if ( V_12 )
F_7 ( V_12 ) ;
return 0 ;
}
if ( F_8 ( V_12 ) > ( int ) V_9 )
{
F_5 ( V_15 , L_8 ,
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
if ( V_2 -> V_22 == NULL && V_2 -> V_23 == NULL )
{
V_2 -> V_22 = F_11 ( V_19 ) ;
F_5 ( V_15 , L_11 , V_2 -> V_22 ) ;
return ( - 1 ) ;
}
if ( V_2 -> V_23 == NULL )
{
F_5 ( V_15 , L_12 , V_2 -> V_22 ) ;
return V_24 ;
}
if ( F_12 ( V_19 , V_2 -> V_23 -> V_25 , V_2 -> V_23 -> V_4 , V_2 -> V_23 -> V_19 , V_2 -> V_23 -> V_26 ,
V_2 -> V_23 -> V_27 ) < 0 )
{
* V_20 = V_28 ;
return V_24 ;
}
F_5 ( V_15 , L_13 , V_2 -> V_22 , V_2 -> V_23 -> V_27 ) ;
V_2 -> V_23 = NULL ;
V_2 -> V_22 = NULL ;
return V_29 ;
}
static void F_13 ( void )
{
V_30 = - 1 ;
V_31 = NULL ;
V_32 = V_33 ;
V_34 = NULL ;
V_35 = NULL ;
V_36 = V_37 ;
V_38 = NULL ;
#ifndef F_14
V_39 = V_40 ;
V_41 = NULL ;
V_42 = NULL ;
#endif
#ifdef F_15
V_43 = 0 ;
#endif
V_44 = 0 ;
V_45 = NULL ;
V_46 = 0 ;
V_14 = NULL ;
V_13 = 0 ;
V_47 = 0 ;
V_48 = 0 ;
V_49 = 0 ;
#ifndef F_16
V_50 = NULL ;
#endif
}
static void F_17 ( void )
{
F_5 ( V_15 , L_14 ) ;
F_5 ( V_15 , L_15 ) ;
F_5 ( V_15 , L_16 , V_51 ) ;
F_5 ( V_15 , L_17 ) ;
F_5 ( V_15 , L_18 ) ;
F_5 ( V_15 , L_19 ) ;
F_5 ( V_15 , L_20 ) ;
F_5 ( V_15 , L_21 , V_37 ) ;
F_5 ( V_15 , L_22 \
L_23 ) ;
F_5 ( V_15 , L_24 \
L_25 \
L_26 ) ;
F_5 ( V_15 , L_27 ) ;
F_5 ( V_15 , L_28 ) ;
F_5 ( V_15 , L_29 , V_37 ) ;
F_5 ( V_15 , L_30 ) ;
F_5 ( V_15 , L_31 ) ;
F_5 ( V_15 , L_32 ) ;
F_5 ( V_15 , L_33 ) ;
F_5 ( V_15 , L_34 ) ;
F_5 ( V_15 , L_35 ) ;
F_5 ( V_15 , L_36 ) ;
F_5 ( V_15 , L_37 ) ;
F_5 ( V_15 , L_38 ) ;
#ifndef F_18
F_5 ( V_15 , L_39 \
L_40 \
L_41 ) ;
#endif
#ifdef F_15
F_5 ( V_15 , L_42 ) ;
#endif
F_5 ( V_15 , L_43 ) ;
F_5 ( V_15 , L_44 ) ;
F_5 ( V_15 , L_45 ) ;
F_5 ( V_15 , L_46 ) ;
F_5 ( V_15 , L_47 ) ;
F_5 ( V_15 , L_48 ) ;
F_5 ( V_15 , L_49 ) ;
F_5 ( V_15 , L_50 ) ;
F_5 ( V_15 , L_51 ) ;
F_5 ( V_15 , L_52 ) ;
F_5 ( V_15 , L_53 ) ;
F_5 ( V_15 , L_54 ) ;
#ifndef F_19
F_5 ( V_15 , L_55 ) ;
F_5 ( V_15 , L_56 ) ;
# ifndef F_20
F_5 ( V_15 , L_57 ) ;
# endif
#endif
#ifndef F_21
F_5 ( V_15 , L_58 ) ;
F_5 ( V_15 , L_59 ) ;
#endif
F_5 ( V_15 , L_60 ) ;
F_5 ( V_15 , L_61 ) ;
F_5 ( V_15 , L_62 ) ;
F_5 ( V_15 , L_63 ) ;
F_5 ( V_15 , L_64 ) ;
F_5 ( V_15 , L_65 ) ;
F_5 ( V_15 , L_66 ) ;
F_5 ( V_15 , L_67 ) ;
F_5 ( V_15 , L_68 ) ;
F_5 ( V_15 , L_69 ) ;
F_5 ( V_15 , L_70 ) ;
F_5 ( V_15 , L_71 ) ;
F_5 ( V_15 , L_72 ) ;
F_5 ( V_15 , L_73 ) ;
#ifndef F_22
F_5 ( V_15 , L_74 ) ;
#endif
#ifndef F_18
F_5 ( V_15 , L_75 ) ;
#endif
F_5 ( V_15 , L_76 ) ;
F_5 ( V_15 , L_77 ) ;
F_5 ( V_15 , L_78 ) ;
F_5 ( V_15 , L_79 ) ;
F_5 ( V_15 , L_80 ) ;
#ifndef F_16
F_5 ( V_15 , L_81 ) ;
#endif
F_5 ( V_15 , L_82 ) ;
F_5 ( V_15 , L_83 , V_52 , V_52 ) ;
#ifndef F_14
F_5 ( V_15 , L_84 ) ;
F_5 ( V_15 , L_85 ) ;
F_5 ( V_15 , L_86 ) ;
F_5 ( V_15 , L_21 , V_40 ) ;
F_5 ( V_15 , L_87 ) ;
F_5 ( V_15 , L_29 , V_40 ) ;
F_5 ( V_15 , L_88 ) ;
F_5 ( V_15 , L_89 ) ;
F_5 ( V_15 , L_90 ) ;
# ifndef F_23
F_5 ( V_15 , L_91 ) ;
# endif
F_5 ( V_15 , L_92 ) ;
#endif
F_5 ( V_15 , L_93 ) ;
F_5 ( V_15 , L_94 ) ;
}
T_6 * F_24 ()
{
return ( & V_53 ) ;
}
static int F_25 ( T_7 * V_54 )
{
T_8 * V_55 ;
V_55 = ( T_8 * ) F_26 ( sizeof( T_8 ) + 1024 ) ;
V_55 -> V_56 = 1024 ;
V_55 -> V_57 [ 0 ] = '\0' ;
V_54 -> V_58 = ( char * ) V_55 ;
V_54 -> V_59 = 1 ;
V_54 -> V_60 = 0 ;
return ( 1 ) ;
}
static int F_27 ( T_7 * V_61 )
{
if ( V_61 == NULL ) return ( 0 ) ;
if ( V_61 -> V_58 != NULL )
F_28 ( V_61 -> V_58 ) ;
V_61 -> V_58 = NULL ;
V_61 -> V_59 = 0 ;
V_61 -> V_60 = 0 ;
return ( 1 ) ;
}
static int F_29 ( T_7 * V_62 , char * V_63 , int V_64 )
{
int V_11 = 0 ;
if ( V_63 == NULL || V_64 == 0 ) return ( 0 ) ;
if ( V_62 -> V_65 == NULL ) return ( 0 ) ;
V_11 = F_30 ( V_62 -> V_65 , V_63 , V_64 ) ;
if ( V_11 > 0 )
F_31 ( V_63 , V_63 , V_11 ) ;
return ( V_11 ) ;
}
static int F_32 ( T_7 * V_62 , const char * V_66 , int V_67 )
{
T_8 * V_55 ;
int V_11 = 0 ;
int V_68 ;
unsigned char V_69 ;
if ( ( V_66 == NULL ) || ( V_67 <= 0 ) ) return ( 0 ) ;
if ( V_62 -> V_65 == NULL ) return ( 0 ) ;
V_55 = ( T_8 * ) V_62 -> V_58 ;
if ( V_67 > ( V_68 = V_55 -> V_56 ) )
{
V_68 = V_68 + V_68 ;
if ( V_68 < V_67 )
V_68 = V_67 ;
F_28 ( V_55 ) ;
V_55 = ( T_8 * ) F_26 ( sizeof( T_8 ) + V_68 ) ;
V_55 -> V_56 = V_68 ;
V_55 -> V_57 [ 0 ] = '\0' ;
V_62 -> V_58 = ( char * ) V_55 ;
}
F_33 ( V_55 -> V_57 , V_66 , V_67 ) ;
V_11 = F_34 ( V_62 -> V_65 , V_55 -> V_57 , V_67 ) ;
return ( V_11 ) ;
}
static long F_35 ( T_7 * V_62 , int V_70 , long V_68 , void * V_58 )
{
long V_11 ;
if ( V_62 -> V_65 == NULL ) return ( 0 ) ;
switch ( V_70 )
{
case V_71 :
V_11 = 0L ;
break;
default:
V_11 = F_36 ( V_62 -> V_65 , V_70 , V_68 , V_58 ) ;
break;
}
return ( V_11 ) ;
}
static int F_37 ( T_7 * V_72 , char * V_73 , int V_74 )
{
int V_75 , V_11 = 0 ;
if ( V_72 -> V_65 == NULL ) return ( 0 ) ;
for ( V_75 = 0 ; V_75 < V_74 - 1 ; ++ V_75 )
{
V_11 = F_29 ( V_72 , & V_73 [ V_75 ] , 1 ) ;
if ( V_11 <= 0 )
break;
else if ( V_73 [ V_75 ] == '\n' )
{
++ V_75 ;
break;
}
}
if ( V_75 < V_74 )
V_73 [ V_75 ] = '\0' ;
return ( V_11 < 0 && V_75 == 0 ) ? V_11 : V_75 ;
}
static int F_38 ( T_7 * V_72 , const char * V_76 )
{
if ( V_72 -> V_65 == NULL ) return ( 0 ) ;
return F_32 ( V_72 , V_76 , strlen ( V_76 ) ) ;
}
static int T_4 F_39 ( T_2 * V_19 , int * V_20 , void * V_21 )
{
T_9 * V_2 = ( T_9 * ) V_21 ;
const char * V_77 = F_40 ( V_19 , V_78 ) ;
if ( V_77 && V_2 -> V_79 )
F_5 ( V_2 -> V_79 , L_95 , V_77 ) ;
if ( ! V_2 -> V_77 )
return V_80 ;
if ( V_77 )
{
if ( strcmp ( V_77 , V_2 -> V_77 ) )
return V_2 -> V_81 ;
if ( V_42 )
{
F_5 ( V_2 -> V_79 , L_96 ) ;
F_41 ( V_19 , V_42 ) ;
}
}
return V_82 ;
}
static int F_42 ( T_2 * V_19 , void * V_21 )
{
T_10 * V_83 = V_21 ;
T_7 * V_84 = V_83 -> V_84 ;
char * V_85 , * V_86 , * V_87 ;
int V_88 ;
unsigned char * V_89 = NULL ;
int V_90 ;
F_43 ( V_91 ) * V_92 = NULL ;
T_11 * V_93 = NULL ;
T_12 V_94 ;
T_13 V_95 ;
T_14 * V_96 = NULL ;
T_15 * V_97 = NULL ;
T_16 * V_98 = NULL ;
F_43 ( V_99 ) * V_100 ;
int V_11 = V_80 ;
int V_75 ;
#if 0
STACK_OF(OCSP_RESPID) *ids;
SSL_get_tlsext_status_ids(s, &ids);
BIO_printf(err, "cert_status: received %d ids\n", sk_OCSP_RESPID_num(ids));
#endif
if ( V_83 -> V_101 )
F_44 ( V_84 , L_97 ) ;
V_93 = F_45 ( V_19 ) ;
V_92 = F_46 ( V_93 ) ;
if ( V_92 )
{
if ( ! F_47 ( F_48 ( V_92 , 0 ) ,
& V_85 , & V_86 , & V_87 , & V_88 ) )
{
F_44 ( V_84 , L_98 ) ;
goto V_84;
}
if ( V_83 -> V_101 )
F_5 ( V_84 , L_99 ,
F_48 ( V_92 , 0 ) ) ;
}
else
{
if ( ! V_83 -> V_85 )
{
F_44 ( V_83 -> V_84 , L_100 ) ;
goto V_102;
}
V_85 = V_83 -> V_85 ;
V_87 = V_83 -> V_87 ;
V_86 = V_83 -> V_86 ;
V_88 = V_83 -> V_88 ;
}
if ( ! F_49 ( & V_94 ,
F_50 ( F_51 ( V_19 ) ) ,
NULL , NULL ) )
goto V_84;
if ( F_52 ( & V_94 , V_103 ,
F_53 ( V_93 ) , & V_95 ) <= 0 )
{
F_44 ( V_84 , L_101 ) ;
F_54 ( & V_94 ) ;
goto V_102;
}
V_96 = F_55 () ;
if ( ! V_96 )
goto V_84;
V_98 = F_56 ( NULL , V_93 , V_95 . V_104 . V_105 ) ;
F_57 ( V_95 . V_104 . V_105 ) ;
F_54 ( & V_94 ) ;
if ( ! V_98 )
goto V_84;
if ( ! F_58 ( V_96 , V_98 ) )
goto V_84;
V_98 = NULL ;
F_59 ( V_19 , & V_100 ) ;
for ( V_75 = 0 ; V_75 < F_60 ( V_100 ) ; V_75 ++ )
{
V_99 * V_106 = F_61 ( V_100 , V_75 ) ;
if ( ! F_62 ( V_96 , V_106 , - 1 ) )
goto V_84;
}
V_97 = F_63 ( V_84 , V_96 , V_85 , V_87 , V_86 , V_88 , NULL ,
V_83 -> V_107 ) ;
if ( ! V_97 )
{
F_44 ( V_84 , L_102 ) ;
goto V_102;
}
V_90 = F_64 ( V_97 , & V_89 ) ;
if ( V_90 <= 0 )
goto V_84;
F_65 ( V_19 , V_89 , V_90 ) ;
if ( V_83 -> V_101 )
{
F_44 ( V_84 , L_103 ) ;
F_66 ( V_84 , V_97 , 2 ) ;
}
V_11 = V_82 ;
V_102:
if ( V_11 != V_82 )
F_67 ( V_84 ) ;
if ( V_92 )
{
F_28 ( V_85 ) ;
F_28 ( V_87 ) ;
F_28 ( V_86 ) ;
F_68 ( V_92 ) ;
}
if ( V_98 )
F_69 ( V_98 ) ;
if ( V_96 )
F_70 ( V_96 ) ;
if ( V_97 )
F_71 ( V_97 ) ;
return V_11 ;
V_84:
V_11 = V_108 ;
goto V_102;
}
static int F_72 ( T_2 * V_19 , const unsigned char * * V_104 , unsigned int * V_109 , void * V_21 )
{
T_17 * V_110 = V_21 ;
* V_104 = V_110 -> V_104 ;
* V_109 = V_110 -> V_109 ;
return V_82 ;
}
int MAIN ( int V_111 , char * V_112 [] )
{
T_18 * V_113 = NULL ;
int V_114 = 0 ;
short V_86 = V_51 ;
char * V_115 = NULL , * V_116 = NULL ;
unsigned char * V_117 = NULL ;
char * V_118 = NULL ;
#ifndef F_18
char * V_119 = NULL ;
#endif
int V_120 = 0 , V_121 = 0 ;
int V_11 = 1 ;
int V_122 = 0 ;
int V_123 = 0 , V_124 = 0 , V_125 = 0 , V_126 = 0 ;
int V_127 = 0 ;
const T_19 * V_128 = NULL ;
int V_129 = V_130 ;
T_20 * V_131 = NULL ;
char * V_132 = NULL ;
int V_133 = V_134 , V_135 = V_134 ;
char * V_136 = NULL , * V_137 = NULL ;
char * V_138 = NULL , * V_139 = NULL ;
int V_140 = V_134 , V_141 = V_134 ;
T_11 * V_142 = NULL , * V_143 = NULL ;
T_21 * V_144 = NULL , * V_145 = NULL ;
int V_146 = 0 ;
#ifndef F_14
T_21 * V_147 = NULL ;
T_11 * V_148 = NULL ;
T_9 V_149 = { NULL , NULL , V_150 } ;
# ifndef F_23
const char * V_151 = NULL ;
T_17 V_110 ;
# endif
#endif
#ifndef F_19
static char * V_152 = NULL ;
#endif
#ifndef F_21
char * V_153 = NULL ;
char * V_154 = NULL ;
#endif
#if ! F_73 ( V_155 ) && ! F_73 ( V_156 )
V_128 = F_74 () ;
#elif ! F_73 ( V_156 )
V_128 = F_75 () ;
#elif ! F_73 ( V_155 )
V_128 = F_76 () ;
#elif ! F_73 ( V_157 )
V_128 = F_77 () ;
#else
#endif
V_158 = V_111 ;
V_159 = V_112 ;
F_78 () ;
#ifdef F_79
F_13 () ;
#endif
if ( V_15 == NULL )
V_15 = F_80 ( V_160 , V_161 ) ;
if ( ! F_81 ( V_15 , NULL ) )
goto V_162;
V_163 = 0 ;
#ifdef F_15
V_43 = 0 ;
#endif
V_44 = 0 ;
V_111 -- ;
V_112 ++ ;
while ( V_111 >= 1 )
{
if ( ( strcmp ( * V_112 , L_104 ) == 0 ) ||
( strcmp ( * V_112 , L_105 ) == 0 ) )
{
if ( -- V_111 < 1 ) goto V_164;
if ( ! F_82 ( * ( ++ V_112 ) , & V_86 ) )
goto V_164;
}
else if ( strcmp ( * V_112 , L_106 ) == 0 )
{
V_32 = V_165 | V_166 ;
if ( -- V_111 < 1 ) goto V_164;
V_163 = atoi ( * ( ++ V_112 ) ) ;
F_5 ( V_15 , L_107 , V_163 ) ;
}
else if ( strcmp ( * V_112 , L_108 ) == 0 )
{
V_32 = V_165 | V_167 |
V_166 ;
if ( -- V_111 < 1 ) goto V_164;
V_163 = atoi ( * ( ++ V_112 ) ) ;
F_5 ( V_15 , L_109 , V_163 ) ;
}
else if ( strcmp ( * V_112 , L_110 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_117 = ( unsigned char * ) * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_111 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_36 = * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_112 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_133 = F_83 ( * ( ++ V_112 ) ) ;
}
else if ( strcmp ( * V_112 , L_113 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_38 = * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_114 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_135 = F_83 ( * ( ++ V_112 ) ) ;
}
else if ( strcmp ( * V_112 , L_115 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_136 = * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_116 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_118 = * ( ++ V_112 ) ;
}
#ifndef F_18
else if ( strcmp ( * V_112 , L_117 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_119 = * ( ++ V_112 ) ;
}
#endif
else if ( strcmp ( * V_112 , L_118 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_140 = F_83 ( * ( ++ V_112 ) ) ;
}
else if ( strcmp ( * V_112 , L_119 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_34 = * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_120 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_141 = F_83 ( * ( ++ V_112 ) ) ;
}
else if ( strcmp ( * V_112 , L_121 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_138 = * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_122 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_35 = * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_123 ) == 0 )
{
V_126 = 1 ;
}
else if ( strcmp ( * V_112 , L_124 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_115 = * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_125 ) == 0 )
V_146 = 1 ;
else if ( F_84 ( & V_112 , & V_111 , & V_114 , V_15 , & V_113 ) )
{
if ( V_114 )
goto V_164;
continue;
}
else if ( strcmp ( * V_112 , L_126 ) == 0 )
V_168 = 1 ;
else if ( strcmp ( * V_112 , L_127 ) == 0 )
{ V_122 |= V_169 ; }
else if ( strcmp ( * V_112 , L_128 ) == 0 )
V_122 |= V_170 ;
else if ( strcmp ( * V_112 , L_129 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_31 = * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_130 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_116 = * ( ++ V_112 ) ;
}
#ifdef F_15
else if ( strcmp ( * V_112 , L_131 ) == 0 )
{ V_43 = 1 ; }
#endif
else if ( strcmp ( * V_112 , L_132 ) == 0 )
{
#ifdef F_15
V_43 = 1 ;
#endif
V_44 = 1 ;
}
else if ( strcmp ( * V_112 , L_133 ) == 0 )
{ V_13 = 1 ; }
#ifndef F_14
else if ( strcmp ( * V_112 , L_134 ) == 0 )
V_171 = 1 ;
else if ( strcmp ( * V_112 , L_135 ) == 0 )
V_172 = 1 ;
else if ( strcmp ( * V_112 , L_136 ) == 0 )
{
V_172 = 1 ;
V_173 . V_101 = 1 ;
}
else if ( ! strcmp ( * V_112 , L_137 ) )
{
V_172 = 1 ;
if ( -- V_111 < 1 ) goto V_164;
V_173 . V_107 = atoi ( * ( ++ V_112 ) ) ;
}
else if ( ! strcmp ( * V_112 , L_138 ) )
{
V_172 = 1 ;
if ( -- V_111 < 1 ) goto V_164;
if ( ! F_47 ( * ( ++ V_112 ) ,
& V_173 . V_85 ,
& V_173 . V_86 ,
& V_173 . V_87 ,
& V_173 . V_88 ) )
{
F_5 ( V_15 , L_139 ) ;
goto V_164;
}
}
#endif
else if ( strcmp ( * V_112 , L_140 ) == 0 )
{ V_47 = 1 ; }
else if ( strcmp ( * V_112 , L_141 ) == 0 )
{ V_49 = 1 ; }
else if ( strcmp ( * V_112 , L_142 ) == 0 )
{ V_127 = 1 ; }
else if ( strcmp ( * V_112 , L_143 ) == 0 )
{ V_174 = 1 ; }
else if ( strcmp ( * V_112 , L_144 ) == 0 )
{ V_48 = 1 ; }
else if ( strcmp ( * V_112 , L_145 ) == 0 )
{ V_121 = 1 ; }
else if ( strcmp ( * V_112 , L_146 ) == 0 )
{ V_123 = 1 ; }
else if ( strcmp ( * V_112 , L_147 ) == 0 )
{ V_124 = 1 ; }
else if ( strcmp ( * V_112 , L_148 ) == 0 )
{ V_125 = 1 ; }
#ifndef F_19
else if ( strcmp ( * V_112 , L_149 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_152 = * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_150 ) == 0 )
{
T_22 V_75 ;
if ( -- V_111 < 1 ) goto V_164;
V_18 = * ( ++ V_112 ) ;
for ( V_75 = 0 ; V_75 < strlen ( V_18 ) ; V_75 ++ )
{
if ( isxdigit ( ( unsigned char ) V_18 [ V_75 ] ) )
continue;
F_5 ( V_15 , L_151 , * V_112 ) ;
goto V_164;
}
}
#endif
#ifndef F_21
else if ( strcmp ( * V_112 , L_152 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_154 = * ( ++ V_112 ) ;
V_128 = F_77 () ;
}
else if ( strcmp ( * V_112 , L_153 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_153 = * ( ++ V_112 ) ;
V_128 = F_77 () ;
}
#endif
else if ( strcmp ( * V_112 , L_154 ) == 0 )
{ V_46 = 1 ; }
else if ( strcmp ( * V_112 , L_155 ) == 0 )
{ V_46 = 2 ; }
else if ( strcmp ( * V_112 , L_156 ) == 0 )
{ V_46 = 3 ; }
else if ( strcmp ( * V_112 , L_157 ) == 0 )
{ V_122 |= V_175 ; }
else if ( strcmp ( * V_112 , L_158 ) == 0 )
{ V_122 |= V_176 ; }
else if ( strcmp ( * V_112 , L_159 ) == 0 )
{ V_122 |= V_177 ; }
else if ( strcmp ( * V_112 , L_160 ) == 0 )
{ V_122 |= V_178 ; }
else if ( strcmp ( * V_112 , L_161 ) == 0 )
{ V_122 |= V_179 ; }
else if ( strcmp ( * V_112 , L_162 ) == 0 )
{ V_122 |= V_180 ; }
#ifndef F_14
else if ( strcmp ( * V_112 , L_163 ) == 0 )
{ V_122 |= V_181 ; }
#endif
#ifndef V_155
else if ( strcmp ( * V_112 , L_164 ) == 0 )
{ V_128 = F_76 () ; }
#endif
#ifndef V_156
else if ( strcmp ( * V_112 , L_165 ) == 0 )
{ V_128 = F_75 () ; }
#endif
#ifndef V_157
else if ( strcmp ( * V_112 , L_166 ) == 0 )
{ V_128 = F_77 () ; }
else if ( strcmp ( * V_112 , L_167 ) == 0 )
{ V_128 = F_85 () ; }
else if ( strcmp ( * V_112 , L_168 ) == 0 )
{ V_128 = F_86 () ; }
#endif
#ifndef F_87
else if ( strcmp ( * V_112 , L_169 ) == 0 )
{
V_128 = F_88 () ;
V_129 = V_182 ;
}
else if ( strcmp ( * V_112 , L_170 ) == 0 )
V_183 = 1 ;
else if ( strcmp ( * V_112 , L_171 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_184 = atol ( * ( ++ V_112 ) ) ;
}
else if ( strcmp ( * V_112 , L_172 ) == 0 )
V_185 = 1 ;
#endif
else if ( strcmp ( * V_112 , L_173 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_186 = * ( ++ V_112 ) ;
}
#ifndef F_16
else if ( strcmp ( * V_112 , L_174 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_50 = * ( ++ V_112 ) ;
}
#endif
else if ( strcmp ( * V_112 , L_175 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_132 = * ( ++ V_112 ) ;
}
#ifndef F_14
else if ( strcmp ( * V_112 , L_176 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_149 . V_77 = * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_177 ) == 0 )
{ V_149 . V_81 = V_108 ; }
else if ( strcmp ( * V_112 , L_178 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_39 = * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_179 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_41 = * ( ++ V_112 ) ;
}
# ifndef F_23
else if ( strcmp ( * V_112 , L_180 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_151 = * ( ++ V_112 ) ;
}
# endif
#endif
#if ! F_73 ( F_20 ) && ! F_73 ( F_19 )
else if ( strcmp ( * V_112 , L_181 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_187 = * ( ++ V_112 ) ;
}
#endif
else if ( strcmp ( * V_112 , L_182 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_188 = * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_183 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_189 = * ( ++ V_112 ) ;
}
else if ( strcmp ( * V_112 , L_184 ) == 0 )
{
if ( -- V_111 < 1 ) goto V_164;
V_190 = atoi ( * ( ++ V_112 ) ) ;
if ( V_190 == 0 ) goto V_164;
}
else
{
F_5 ( V_15 , L_185 , * V_112 ) ;
V_120 = 1 ;
break;
}
V_111 -- ;
V_112 ++ ;
}
if ( V_120 )
{
V_164:
F_17 () ;
goto V_162;
}
#if ! F_73 ( F_20 ) && ! F_73 ( F_19 )
if ( V_187 )
{
if ( V_18 )
{
F_5 ( V_15 ,
L_186 ) ;
goto V_162;
}
V_17 = L_187 ;
if ( V_31 )
{
F_5 ( V_15 , L_188 ) ;
goto V_162;
}
V_31 = L_189 ;
}
#endif
F_89 () ;
F_90 () ;
#ifndef F_16
V_131 = F_91 ( V_15 , V_50 , 1 ) ;
#endif
if ( ! F_92 ( V_15 , V_136 , V_138 , & V_137 , & V_139 ) )
{
F_5 ( V_15 , L_190 ) ;
goto V_162;
}
if ( V_38 == NULL )
V_38 = V_36 ;
#ifndef F_14
if ( V_41 == NULL )
V_41 = V_39 ;
#endif
if ( V_126 == 0 )
{
V_144 = F_93 ( V_15 , V_38 , V_135 , 0 , V_137 , V_131 ,
L_191 ) ;
if ( ! V_144 )
{
F_67 ( V_15 ) ;
goto V_162;
}
V_142 = F_94 ( V_15 , V_36 , V_133 ,
NULL , V_131 , L_192 ) ;
if ( ! V_142 )
{
F_67 ( V_15 ) ;
goto V_162;
}
#ifndef F_14
if ( V_149 . V_77 )
{
V_147 = F_93 ( V_15 , V_41 , V_135 , 0 , V_137 , V_131 ,
L_193 ) ;
if ( ! V_147 )
{
F_67 ( V_15 ) ;
goto V_162;
}
V_148 = F_94 ( V_15 , V_39 , V_133 ,
NULL , V_131 , L_194 ) ;
if ( ! V_148 )
{
F_67 ( V_15 ) ;
goto V_162;
}
}
# ifndef F_23
if ( V_151 )
{
unsigned short V_109 ;
V_110 . V_104 = F_95 ( & V_109 ,
V_151 ) ;
if ( V_110 . V_104 == NULL )
goto V_162;
V_110 . V_109 = V_109 ;
}
else
{
V_110 . V_104 = NULL ;
}
# endif
#endif
}
if ( V_34 )
{
if ( V_35 == NULL )
V_35 = V_34 ;
V_145 = F_93 ( V_15 , V_35 , V_141 ,
0 , V_139 , V_131 ,
L_195 ) ;
if ( ! V_145 )
{
F_67 ( V_15 ) ;
goto V_162;
}
V_143 = F_94 ( V_15 , V_34 , V_140 ,
NULL , V_131 , L_194 ) ;
if ( ! V_143 )
{
F_67 ( V_15 ) ;
goto V_162;
}
}
if ( ! F_96 ( NULL , V_15 , 1 ) && V_132 == NULL
&& ! F_97 () )
{
F_5 ( V_15 , L_196 ) ;
}
if ( V_132 != NULL )
F_5 ( V_15 , L_197 ,
F_98 ( V_132 ) ) ;
if ( V_14 == NULL )
{
if ( V_48 && ! V_13 && ! V_47 )
{
V_14 = F_99 ( F_100 () ) ;
}
else
{
if ( V_14 == NULL )
V_14 = F_80 ( stdout , V_161 ) ;
}
}
#if ! F_73 ( V_191 ) || ! F_73 ( V_192 ) || ! F_73 ( V_193 )
if ( V_126 )
#endif
{
V_36 = NULL ;
V_38 = NULL ;
V_34 = NULL ;
V_35 = NULL ;
#ifndef F_14
V_39 = NULL ;
V_41 = NULL ;
#endif
}
V_45 = F_101 ( V_128 ) ;
if ( V_45 == NULL )
{
F_67 ( V_15 ) ;
goto V_162;
}
if ( V_186 )
{
if( strlen ( V_186 ) >= 32 )
F_5 ( V_15 ,
L_198 ) ;
else if( strlen ( V_186 ) >= 16 )
F_5 ( V_15 ,
L_199 ) ;
if( ! F_102 ( V_45 , V_194 ) )
{
F_5 ( V_15 , L_200 ) ;
F_67 ( V_15 ) ;
goto V_162;
}
F_5 ( V_15 , L_201 , V_186 ) ;
}
F_103 ( V_45 , 1 ) ;
if ( V_121 ) F_104 ( V_45 , V_195 ) ;
if ( V_49 ) F_104 ( V_45 , V_196 ) ;
F_104 ( V_45 , V_122 ) ;
if ( V_129 == V_182 ) F_105 ( V_45 , 1 ) ;
if ( V_127 ) F_106 ( V_45 , V_197 ) ;
if ( V_146 )
F_107 ( V_45 , V_198 ) ;
else
F_108 ( V_45 , 128 ) ;
if ( V_188 != NULL )
F_109 ( V_45 , V_188 ) ;
#if 0
if (cipher == NULL) cipher=getenv("SSL_CIPHER");
#endif
#if 0
if (s_cert_file == NULL)
{
BIO_printf(bio_err,"You must specify a certificate file for the server to use\n");
goto end;
}
#endif
if ( ( ! F_110 ( V_45 , V_116 , V_115 ) ) ||
( ! F_111 ( V_45 ) ) )
{
F_67 ( V_15 ) ;
}
if ( V_113 )
F_112 ( V_45 , V_113 ) ;
#ifndef F_14
if ( V_148 )
{
V_42 = F_101 ( V_128 ) ;
if ( V_42 == NULL )
{
F_67 ( V_15 ) ;
goto V_162;
}
}
if ( V_42 )
{
F_5 ( V_14 , L_202 ) ;
if ( V_186 )
{
if( strlen ( V_186 ) >= 32 )
F_5 ( V_15 ,
L_198 ) ;
else if( strlen ( V_186 ) >= 16 )
F_5 ( V_15 ,
L_199 ) ;
if( ! F_102 ( V_42 , V_194 ) )
{
F_5 ( V_15 , L_200 ) ;
F_67 ( V_15 ) ;
goto V_162;
}
F_5 ( V_15 , L_201 , V_186 ) ;
}
F_103 ( V_42 , 1 ) ;
if ( V_121 ) F_104 ( V_42 , V_195 ) ;
if ( V_49 ) F_104 ( V_42 , V_196 ) ;
F_104 ( V_42 , V_122 ) ;
if ( V_129 == V_182 ) F_105 ( V_42 , 1 ) ;
if ( V_127 ) F_106 ( V_42 , V_197 ) ;
if ( V_146 )
F_107 ( V_42 , V_198 ) ;
else
F_108 ( V_42 , 128 ) ;
if ( ( ! F_110 ( V_42 , V_116 , V_115 ) ) ||
( ! F_111 ( V_42 ) ) )
{
F_67 ( V_15 ) ;
}
if ( V_113 )
F_112 ( V_42 , V_113 ) ;
}
# ifndef F_23
if ( V_110 . V_104 )
F_113 ( V_45 , F_72 , & V_110 ) ;
# endif
#endif
#ifndef F_22
if ( ! V_124 )
{
T_1 * V_1 = NULL ;
if ( V_118 )
V_1 = F_114 ( V_118 ) ;
else if ( V_36 )
V_1 = F_114 ( V_36 ) ;
if ( V_1 != NULL )
{
F_5 ( V_14 , L_203 ) ;
}
else
{
F_5 ( V_14 , L_204 ) ;
V_1 = F_1 () ;
}
( void ) F_115 ( V_14 ) ;
F_116 ( V_45 , V_1 ) ;
#ifndef F_14
if ( V_42 )
{
if ( ! V_118 )
{
T_1 * V_199 = F_114 ( V_39 ) ;
if ( V_199 != NULL )
{
F_5 ( V_14 , L_203 ) ;
( void ) F_115 ( V_14 ) ;
F_117 ( V_1 ) ;
V_1 = V_199 ;
}
}
F_116 ( V_42 , V_1 ) ;
}
#endif
F_117 ( V_1 ) ;
}
#endif
#ifndef F_18
if ( ! V_125 )
{
T_23 * V_200 = NULL ;
if ( V_119 )
{
int V_201 = F_118 ( V_119 ) ;
if ( V_201 == 0 )
{
F_5 ( V_15 , L_205 ,
V_119 ) ;
goto V_162;
}
V_200 = F_119 ( V_201 ) ;
if ( V_200 == NULL )
{
F_5 ( V_15 , L_206 ,
V_119 ) ;
goto V_162;
}
}
if ( V_200 != NULL )
{
F_5 ( V_14 , L_207 ) ;
}
else
{
F_5 ( V_14 , L_208 ) ;
V_200 = F_119 ( V_202 ) ;
if ( V_200 == NULL )
{
F_5 ( V_15 , L_209 ) ;
goto V_162;
}
}
( void ) F_115 ( V_14 ) ;
F_120 ( V_45 , V_200 ) ;
#ifndef F_14
if ( V_42 )
F_120 ( V_42 , V_200 ) ;
#endif
F_121 ( V_200 ) ;
}
#endif
if ( ! F_122 ( V_45 , V_142 , V_144 ) )
goto V_162;
#ifndef F_14
if ( V_42 && ! F_122 ( V_42 , V_148 , V_147 ) )
goto V_162;
#endif
if ( V_143 != NULL )
{
if ( ! F_122 ( V_45 , V_143 , V_145 ) )
goto V_162;
}
#ifndef V_191
#if 1
if ( ! V_123 )
{
F_123 ( V_45 , V_203 ) ;
#ifndef F_14
if ( V_42 )
F_123 ( V_42 , V_203 ) ;
#endif
}
#else
if ( ! V_123 && F_124 ( V_45 ) )
{
T_24 * V_204 ;
F_5 ( V_14 , L_210 ) ;
F_115 ( V_14 ) ;
V_204 = F_125 ( 512 , V_205 , NULL ) ;
if ( ! F_126 ( V_45 , V_204 ) )
{
F_67 ( V_15 ) ;
goto V_162;
}
#ifndef F_14
if ( V_42 )
{
if ( ! F_126 ( V_42 , V_204 ) )
{
F_67 ( V_15 ) ;
goto V_162;
}
}
#endif
F_127 ( V_204 ) ;
F_5 ( V_14 , L_15 ) ;
}
#endif
#endif
#ifndef F_19
#ifdef F_20
if ( V_18 != NULL )
#else
if ( V_18 != NULL || V_187 )
#endif
{
if ( V_13 )
F_5 ( V_14 , L_211 ) ;
F_128 ( V_45 , F_4 ) ;
}
if ( ! F_129 ( V_45 , V_152 ) )
{
F_5 ( V_15 , L_212 ) ;
F_67 ( V_15 ) ;
goto V_162;
}
#endif
if ( V_31 != NULL )
{
if( ! F_130 ( V_45 , V_31 ) )
{
F_5 ( V_15 , L_213 ) ;
F_67 ( V_15 ) ;
goto V_162;
}
#ifndef F_14
if ( V_42 && ! F_130 ( V_42 , V_31 ) )
{
F_5 ( V_15 , L_213 ) ;
F_67 ( V_15 ) ;
goto V_162;
}
#endif
}
F_131 ( V_45 , V_32 , V_206 ) ;
F_132 ( V_45 , ( void * ) & V_207 ,
sizeof V_207 ) ;
F_133 ( V_45 , V_208 ) ;
F_134 ( V_45 , V_209 ) ;
#ifndef F_14
if ( V_42 )
{
F_131 ( V_42 , V_32 , V_206 ) ;
F_132 ( V_42 , ( void * ) & V_207 ,
sizeof V_207 ) ;
V_149 . V_79 = V_14 ;
F_135 ( V_42 , F_39 ) ;
F_136 ( V_42 , & V_149 ) ;
F_135 ( V_45 , F_39 ) ;
F_136 ( V_45 , & V_149 ) ;
}
#endif
#ifndef F_21
if ( V_154 != NULL )
{
V_210 . V_211 = F_137 ( V_153 ) ;
V_210 . V_23 = NULL ;
V_210 . V_22 = NULL ;
if ( ( V_11 = F_138 ( V_210 . V_211 , V_154 ) ) != V_212 )
{
F_5 ( V_15 ,
L_214 ,
V_154 , V_11 ) ;
goto V_162;
}
F_131 ( V_45 , V_33 , V_206 ) ;
F_139 ( V_45 , & V_210 ) ;
F_140 ( V_45 , F_10 ) ;
}
else
#endif
if ( V_116 != NULL )
{
F_141 ( V_45 , F_142 ( V_116 ) ) ;
#ifndef F_14
if ( V_42 )
F_141 ( V_42 , F_142 ( V_116 ) ) ;
#endif
}
F_5 ( V_14 , L_215 ) ;
( void ) F_115 ( V_14 ) ;
if ( V_46 )
F_143 ( V_86 , V_129 , & V_30 , V_213 , V_117 ) ;
else
F_143 ( V_86 , V_129 , & V_30 , V_214 , V_117 ) ;
F_144 ( V_14 , V_45 ) ;
V_11 = 0 ;
V_162:
if ( V_45 != NULL ) F_145 ( V_45 ) ;
if ( V_142 )
F_57 ( V_142 ) ;
if ( V_143 )
F_57 ( V_143 ) ;
if ( V_144 )
F_146 ( V_144 ) ;
if ( V_145 )
F_146 ( V_145 ) ;
if ( V_137 )
F_28 ( V_137 ) ;
if ( V_139 )
F_28 ( V_139 ) ;
#ifndef F_14
if ( V_42 != NULL ) F_145 ( V_42 ) ;
if ( V_148 )
F_57 ( V_148 ) ;
if ( V_147 )
F_146 ( V_147 ) ;
#endif
if ( V_14 != NULL )
{
F_147 ( V_14 ) ;
V_14 = NULL ;
}
F_148 () ;
F_149 ( V_11 ) ;
}
static void F_144 ( T_7 * V_215 , T_25 * V_216 )
{
F_5 ( V_215 , L_216 ,
F_150 ( V_216 ) ) ;
F_5 ( V_215 , L_217 ,
F_151 ( V_216 ) ) ;
F_5 ( V_215 , L_218 ,
F_152 ( V_216 ) ) ;
F_5 ( V_215 , L_219 ,
F_153 ( V_216 ) ) ;
F_5 ( V_215 , L_220 ,
F_154 ( V_216 ) ) ;
F_5 ( V_215 , L_221 ,
F_155 ( V_216 ) ) ;
F_5 ( V_215 , L_222 ,
F_156 ( V_216 ) ) ;
F_5 ( V_215 , L_223 , F_157 ( V_216 ) ) ;
F_5 ( V_215 , L_224 , F_158 ( V_216 ) ) ;
F_5 ( V_215 , L_225 , F_159 ( V_216 ) ) ;
F_5 ( V_215 , L_226 , F_160 ( V_216 ) ) ;
F_5 ( V_215 , L_227 ,
F_161 ( V_216 ) ,
F_162 ( V_216 ) ) ;
}
static int V_214 ( char * V_217 , int V_19 , unsigned char * V_117 )
{
char * V_73 = NULL ;
T_26 V_218 ;
int V_11 = 1 , V_219 ;
int V_220 , V_75 ;
unsigned long V_221 ;
T_2 * V_222 = NULL ;
T_7 * V_223 ;
#ifndef F_163
T_27 * V_224 ;
#endif
struct V_225 V_107 ;
#if F_73 ( V_226 ) || F_73 ( V_227 ) || F_73 ( V_228 ) || F_73 ( V_229 )
struct V_225 V_230 ;
#else
struct V_225 * V_231 ;
#endif
if ( ( V_73 = F_26 ( V_232 ) ) == NULL )
{
F_5 ( V_15 , L_228 ) ;
goto V_84;
}
#ifdef F_15
if ( V_43 )
{
unsigned long V_233 = 1 ;
if ( ! V_48 )
F_5 ( V_15 , L_229 ) ;
if ( F_164 ( V_19 , F_15 , & V_233 ) < 0 )
F_67 ( V_15 ) ;
}
#endif
if ( V_222 == NULL ) {
V_222 = F_165 ( V_45 ) ;
#ifndef F_14
if ( V_171 )
{
F_166 ( V_222 , V_234 ) ;
F_167 ( V_222 , V_14 ) ;
}
if ( V_172 )
{
F_168 ( V_45 , F_42 ) ;
V_173 . V_84 = V_15 ;
F_169 ( V_45 , & V_173 ) ;
}
#endif
#ifndef F_163
if ( ( V_224 = F_170 () ) != NULL )
{
F_171 ( V_222 , V_224 ) ;
F_172 ( V_224 , V_235 , V_236 ) ;
F_172 ( V_224 , V_237 , V_238 ) ;
}
#endif
if( V_117 )
F_173 ( V_222 , V_117 ,
strlen ( ( char * ) V_117 ) ) ;
}
F_174 ( V_222 ) ;
#if 0
#ifdef F_175
SSL_set_tlsext_opaque_prf_input(con, "Test server", 11);
#endif
#endif
if ( F_176 ( V_222 ) == V_239 )
{
V_223 = F_177 ( V_19 , V_161 ) ;
if ( V_183 )
{
V_107 . V_240 = 0 ;
V_107 . V_241 = V_242 ;
F_36 ( V_223 , V_243 , 0 , & V_107 ) ;
V_107 . V_240 = 0 ;
V_107 . V_241 = V_244 ;
F_36 ( V_223 , V_245 , 0 , & V_107 ) ;
}
if ( V_184 > 28 )
{
F_178 ( V_222 , V_246 ) ;
F_179 ( V_222 , V_184 - 28 ) ;
}
else
F_36 ( V_223 , V_247 , 0 , NULL ) ;
F_178 ( V_222 , V_248 ) ;
}
else
V_223 = F_180 ( V_19 , V_161 ) ;
if ( V_44 )
{
T_7 * V_249 ;
V_249 = F_99 ( F_181 () ) ;
V_223 = F_182 ( V_249 , V_223 ) ;
}
#ifndef F_20
if( V_187 )
F_183 ( V_14 , V_223 , V_187 ) ;
#endif
F_184 ( V_222 , V_223 , V_223 ) ;
F_185 ( V_222 ) ;
if ( V_13 )
{
F_186 ( V_222 , 1 ) ;
F_187 ( F_188 ( V_222 ) , V_250 ) ;
F_189 ( F_188 ( V_222 ) , ( char * ) V_14 ) ;
}
if ( V_47 )
{
F_190 ( V_222 , V_251 ) ;
F_191 ( V_222 , V_14 ) ;
}
#ifndef F_14
if ( V_171 )
{
F_166 ( V_222 , V_234 ) ;
F_167 ( V_222 , V_14 ) ;
}
#endif
V_219 = V_19 + 1 ;
for (; ; )
{
int V_252 ;
int V_253 ;
V_252 = 0 ;
V_253 = F_192 ( V_222 ) ;
if ( ! V_253 )
{
F_193 ( & V_218 ) ;
#if ! F_73 ( V_226 ) && ! F_73 ( V_227 ) && ! F_73 ( V_228 ) && ! F_73 ( V_229 )
F_194 ( fileno ( V_254 ) , & V_218 ) ;
#endif
F_194 ( V_19 , & V_218 ) ;
#if F_73 ( V_226 ) || F_73 ( V_227 ) || F_73 ( V_228 )
V_230 . V_240 = 1 ;
V_230 . V_241 = 0 ;
V_75 = F_195 ( V_219 , ( void * ) & V_218 , NULL , NULL , & V_230 ) ;
if( ( V_75 < 0 ) || ( ! V_75 && ! F_196 () ) ) continue;
if( F_196 () )
V_252 = 1 ;
#elif F_73 ( V_229 )
V_230 . V_240 = 1 ;
V_230 . V_241 = 0 ;
( void ) F_197 ( fileno ( V_254 ) , V_255 , V_256 ) ;
V_75 = F_195 ( V_219 , ( void * ) & V_218 , NULL , NULL , & V_230 ) ;
if ( ( V_75 < 0 ) || ( ! V_75 && F_198 ( fileno ( V_254 ) , V_73 , 0 ) < 0 ) )
continue;
if ( F_198 ( fileno ( V_254 ) , V_73 , 0 ) >= 0 )
V_252 = 1 ;
( void ) F_197 ( fileno ( V_254 ) , V_255 , 0 ) ;
#else
if ( ( F_176 ( V_222 ) == V_239 ) &&
F_199 ( V_222 , & V_107 ) )
V_231 = & V_107 ;
else
V_231 = NULL ;
V_75 = F_195 ( V_219 , ( void * ) & V_218 , NULL , NULL , V_231 ) ;
if ( ( F_176 ( V_222 ) == V_239 ) && F_200 ( V_222 ) > 0 )
{
F_5 ( V_15 , L_230 ) ;
}
if ( V_75 <= 0 ) continue;
if ( F_201 ( fileno ( V_254 ) , & V_218 ) )
V_252 = 1 ;
#endif
if ( F_201 ( V_19 , & V_218 ) )
V_253 = 1 ;
}
if ( V_252 )
{
if ( V_174 )
{
int V_257 , V_258 ;
V_75 = F_202 ( V_73 , V_232 / 2 ) ;
V_258 = 0 ;
for ( V_257 = 0 ; V_257 < V_75 ; V_257 ++ )
if ( V_73 [ V_257 ] == '\n' )
V_258 ++ ;
for ( V_257 = V_75 - 1 ; V_257 >= 0 ; V_257 -- )
{
V_73 [ V_257 + V_258 ] = V_73 [ V_257 ] ;
if ( V_73 [ V_257 ] == '\n' )
{
V_258 -- ;
V_75 ++ ;
V_73 [ V_257 + V_258 ] = '\r' ;
}
}
assert ( V_258 == 0 ) ;
}
else
V_75 = F_202 ( V_73 , V_232 ) ;
if ( ! V_48 )
{
if ( ( V_75 <= 0 ) || ( V_73 [ 0 ] == 'Q' ) )
{
F_5 ( V_14 , L_231 ) ;
F_203 ( V_19 ) ;
F_204 () ;
V_11 = - 11 ;
goto V_84;
}
if ( ( V_75 <= 0 ) || ( V_73 [ 0 ] == 'q' ) )
{
F_5 ( V_14 , L_231 ) ;
if ( F_176 ( V_222 ) != V_239 )
F_203 ( V_19 ) ;
goto V_84;
}
#ifndef F_205
if ( ( V_73 [ 0 ] == 'B' ) &&
( ( V_73 [ 1 ] == '\n' ) || ( V_73 [ 1 ] == '\r' ) ) )
{
F_5 ( V_15 , L_232 ) ;
F_206 ( V_222 ) ;
V_75 = 0 ;
continue;
}
#endif
if ( ( V_73 [ 0 ] == 'r' ) &&
( ( V_73 [ 1 ] == '\n' ) || ( V_73 [ 1 ] == '\r' ) ) )
{
F_207 ( V_222 ) ;
V_75 = F_208 ( V_222 ) ;
printf ( L_233 , V_75 ) ;
V_75 = 0 ;
continue;
}
if ( ( V_73 [ 0 ] == 'R' ) &&
( ( V_73 [ 1 ] == '\n' ) || ( V_73 [ 1 ] == '\r' ) ) )
{
F_209 ( V_222 ,
V_165 | V_166 , NULL ) ;
F_207 ( V_222 ) ;
V_75 = F_208 ( V_222 ) ;
printf ( L_233 , V_75 ) ;
V_75 = 0 ;
continue;
}
if ( V_73 [ 0 ] == 'P' )
{
static const char * V_76 = L_234 ;
F_34 ( F_210 ( V_222 ) , V_76 , strlen ( V_76 ) ) ;
}
if ( V_73 [ 0 ] == 'S' )
{
F_144 ( V_14 , F_51 ( V_222 ) ) ;
}
}
#ifdef F_211
F_33 ( V_73 , V_73 , V_75 ) ;
#endif
V_221 = V_220 = 0 ;
for (; ; )
{
#ifdef F_212
{ static V_259 = 0 ; if ( ++ V_259 == 100 ) { V_259 = 0 ; F_207 ( V_222 ) ; } }
#endif
V_220 = F_213 ( V_222 , & ( V_73 [ V_221 ] ) , ( unsigned int ) V_75 ) ;
#ifndef F_21
while ( F_214 ( V_222 , V_220 ) == V_260 )
{
F_5 ( V_14 , L_235 ) ;
V_210 . V_23 = F_215 ( V_210 . V_211 , V_210 . V_22 ) ;
if ( V_210 . V_23 )
F_5 ( V_14 , L_236 , V_210 . V_23 -> V_27 ) ;
else
F_5 ( V_14 , L_237 ) ;
V_220 = F_213 ( V_222 , & ( V_73 [ V_221 ] ) , ( unsigned int ) V_75 ) ;
}
#endif
switch ( F_214 ( V_222 , V_220 ) )
{
case V_29 :
break;
case V_261 :
case V_262 :
case V_260 :
F_5 ( V_14 , L_238 ) ;
break;
case V_263 :
case V_264 :
F_5 ( V_14 , L_239 ) ;
F_67 ( V_15 ) ;
V_11 = 1 ;
goto V_84;
case V_265 :
F_5 ( V_14 , L_231 ) ;
V_11 = 1 ;
goto V_84;
}
V_221 += V_220 ;
V_75 -= V_220 ;
if ( V_75 <= 0 ) break;
}
}
if ( V_253 )
{
if ( ! F_216 ( V_222 ) )
{
V_75 = F_217 ( V_222 ) ;
if ( V_75 < 0 )
{
V_11 = 0 ;
goto V_84;
}
else if ( V_75 == 0 )
{
V_11 = 1 ;
goto V_84;
}
}
else
{
V_266:
V_75 = F_218 ( V_222 , ( char * ) V_73 , V_232 ) ;
#ifndef F_21
while ( F_214 ( V_222 , V_75 ) == V_260 )
{
F_5 ( V_14 , L_240 ) ;
V_210 . V_23 = F_215 ( V_210 . V_211 , V_210 . V_22 ) ;
if ( V_210 . V_23 )
F_5 ( V_14 , L_236 , V_210 . V_23 -> V_27 ) ;
else
F_5 ( V_14 , L_237 ) ;
V_75 = F_218 ( V_222 , ( char * ) V_73 , V_232 ) ;
}
#endif
switch ( F_214 ( V_222 , V_75 ) )
{
case V_29 :
#ifdef F_211
F_31 ( V_73 , V_73 , V_75 ) ;
#endif
F_219 ( V_73 ,
( unsigned int ) V_75 ) ;
if ( F_192 ( V_222 ) ) goto V_266;
break;
case V_261 :
case V_262 :
F_5 ( V_14 , L_241 ) ;
break;
case V_263 :
case V_264 :
F_5 ( V_14 , L_239 ) ;
F_67 ( V_15 ) ;
V_11 = 1 ;
goto V_84;
case V_265 :
F_5 ( V_14 , L_231 ) ;
V_11 = 1 ;
goto V_84;
}
}
}
}
V_84:
if ( V_222 != NULL )
{
F_5 ( V_14 , L_242 ) ;
#if 1
F_220 ( V_222 , V_267 | V_268 ) ;
#else
F_221 ( V_222 ) ;
#endif
F_222 ( V_222 ) ;
}
F_5 ( V_14 , L_243 ) ;
if ( V_73 != NULL )
{
F_223 ( V_73 , V_232 ) ;
F_28 ( V_73 ) ;
}
if ( V_11 >= 0 )
F_5 ( V_14 , L_215 ) ;
return ( V_11 ) ;
}
static void F_204 ( void )
{
F_5 ( V_15 , L_244 ) ;
if ( V_30 >= 0 )
{
F_224 ( V_30 ) ;
}
}
static int F_217 ( T_2 * V_222 )
{
int V_75 ;
const char * V_76 ;
T_11 * V_269 ;
long V_270 ;
T_28 char V_73 [ V_271 ] ;
#ifndef F_163
char * V_272 ;
#endif
#if ! F_73 ( F_14 ) && ! F_73 ( F_23 )
const unsigned char * V_273 ;
unsigned V_274 ;
#endif
unsigned char * V_275 ;
V_75 = F_225 ( V_222 ) ;
#ifndef F_21
while ( V_75 <= 0 && F_214 ( V_222 , V_75 ) == V_260 )
{
F_5 ( V_14 , L_245 , V_210 . V_22 ) ;
V_210 . V_23 = F_215 ( V_210 . V_211 , V_210 . V_22 ) ;
if ( V_210 . V_23 )
F_5 ( V_14 , L_236 , V_210 . V_23 -> V_27 ) ;
else
F_5 ( V_14 , L_237 ) ;
V_75 = F_225 ( V_222 ) ;
}
#endif
if ( V_75 <= 0 )
{
if ( F_226 ( V_75 ) )
{
F_5 ( V_14 , L_246 ) ;
return ( 1 ) ;
}
F_5 ( V_15 , L_239 ) ;
V_270 = F_227 ( V_222 ) ;
if ( V_270 != V_276 )
{
F_5 ( V_15 , L_247 ,
F_228 ( V_270 ) ) ;
}
else
F_67 ( V_15 ) ;
return ( 0 ) ;
}
F_229 ( V_14 , F_230 ( V_222 ) ) ;
V_269 = F_231 ( V_222 ) ;
if ( V_269 != NULL )
{
F_5 ( V_14 , L_248 ) ;
F_232 ( V_14 , V_269 ) ;
F_233 ( F_234 ( V_269 ) , V_73 , sizeof V_73 ) ;
F_5 ( V_14 , L_249 , V_73 ) ;
F_233 ( F_53 ( V_269 ) , V_73 , sizeof V_73 ) ;
F_5 ( V_14 , L_250 , V_73 ) ;
F_57 ( V_269 ) ;
}
if ( F_235 ( V_222 , V_73 , sizeof V_73 ) != NULL )
F_5 ( V_14 , L_251 , V_73 ) ;
V_76 = F_236 ( F_237 ( V_222 ) ) ;
F_5 ( V_14 , L_252 , ( V_76 != NULL ) ? V_76 : L_253 ) ;
#if ! F_73 ( F_14 ) && ! F_73 ( F_23 )
F_238 ( V_222 , & V_273 , & V_274 ) ;
if ( V_273 )
{
F_5 ( V_14 , L_254 ) ;
F_34 ( V_14 , V_273 , V_274 ) ;
F_5 ( V_14 , L_15 ) ;
}
#endif
{
T_29 * V_277
= F_239 ( V_222 ) ;
if( V_277 )
F_5 ( V_14 , L_255 ,
V_277 -> V_278 ) ;
}
if ( F_240 ( V_222 ) ) F_5 ( V_14 , L_256 ) ;
if ( F_241 ( V_222 , V_279 , 0 , NULL ) &
V_280 )
F_5 ( V_14 ,
L_257 ) ;
#ifndef F_163
V_272 = F_242 ( F_243 ( V_222 ) ) ;
if ( V_272 != NULL )
{
F_5 ( V_14 , L_258 ,
V_272 ) ;
}
#endif
F_5 ( V_14 , L_259 ,
F_244 ( V_222 ) ? L_260 : L_261 ) ;
if ( V_189 != NULL )
{
F_5 ( V_14 , L_262 ) ;
F_5 ( V_14 , L_263 , V_189 ) ;
F_5 ( V_14 , L_264 ,
V_190 ) ;
V_275 = F_26 ( V_190 ) ;
if ( V_275 != NULL )
{
if ( ! F_245 ( V_222 , V_275 ,
V_190 ,
V_189 ,
strlen ( V_189 ) ,
NULL , 0 , 0 ) )
{
F_5 ( V_14 , L_265 ) ;
}
else
{
F_5 ( V_14 , L_266 ) ;
for ( V_75 = 0 ; V_75 < V_190 ; V_75 ++ )
F_5 ( V_14 , L_267 ,
V_275 [ V_75 ] ) ;
F_5 ( V_14 , L_15 ) ;
}
F_28 ( V_275 ) ;
}
}
return ( 1 ) ;
}
static T_1 * F_114 ( const char * V_118 )
{
T_1 * V_11 = NULL ;
T_7 * V_215 ;
if ( ( V_215 = F_246 ( V_118 , L_268 ) ) == NULL )
goto V_84;
V_11 = F_247 ( V_215 , NULL , NULL , NULL ) ;
V_84:
if ( V_215 != NULL ) F_147 ( V_215 ) ;
return ( V_11 ) ;
}
static int V_213 ( char * V_217 , int V_19 , unsigned char * V_117 )
{
char * V_73 = NULL ;
int V_11 = 1 ;
int V_75 , V_257 , V_220 , V_281 ;
T_2 * V_222 ;
const T_30 * V_282 ;
T_7 * V_283 , * V_284 , * V_223 ;
#ifndef F_163
T_27 * V_224 ;
#endif
V_73 = F_26 ( V_232 ) ;
if ( V_73 == NULL ) return ( 0 ) ;
V_283 = F_99 ( F_248 () ) ;
V_284 = F_99 ( F_249 () ) ;
if ( ( V_283 == NULL ) || ( V_284 == NULL ) ) goto V_84;
#ifdef F_15
if ( V_43 )
{
unsigned long V_233 = 1 ;
if ( ! V_48 )
F_5 ( V_15 , L_229 ) ;
if ( F_164 ( V_19 , F_15 , & V_233 ) < 0 )
F_67 ( V_15 ) ;
}
#endif
if ( ! F_250 ( V_283 , V_232 ) ) goto V_84;
if ( ( V_222 = F_165 ( V_45 ) ) == NULL ) goto V_84;
#ifndef F_14
if ( V_171 )
{
F_166 ( V_222 , V_234 ) ;
F_167 ( V_222 , V_14 ) ;
}
#endif
#ifndef F_163
if ( ( V_224 = F_170 () ) != NULL )
{
F_172 ( V_224 , V_235 , V_236 ) ;
F_172 ( V_224 , V_237 , V_238 ) ;
}
#endif
if( V_117 ) F_173 ( V_222 , V_117 ,
strlen ( ( char * ) V_117 ) ) ;
V_223 = F_180 ( V_19 , V_161 ) ;
if ( V_44 )
{
T_7 * V_249 ;
V_249 = F_99 ( F_181 () ) ;
V_223 = F_182 ( V_249 , V_223 ) ;
}
F_184 ( V_222 , V_223 , V_223 ) ;
F_185 ( V_222 ) ;
F_251 ( V_284 , V_222 , V_285 ) ;
F_182 ( V_283 , V_284 ) ;
#ifdef F_211
V_283 = F_182 ( F_99 ( F_24 () ) , V_283 ) ;
#endif
if ( V_13 )
{
F_186 ( V_222 , 1 ) ;
F_187 ( F_188 ( V_222 ) , V_250 ) ;
F_189 ( F_188 ( V_222 ) , ( char * ) V_14 ) ;
}
if ( V_47 )
{
F_190 ( V_222 , V_251 ) ;
F_191 ( V_222 , V_14 ) ;
}
for (; ; )
{
if ( V_49 )
{
V_75 = F_225 ( V_222 ) ;
#ifndef F_21
while ( V_75 <= 0 && F_214 ( V_222 , V_75 ) == V_260 )
{
F_5 ( V_14 , L_245 , V_210 . V_22 ) ;
V_210 . V_23 = F_215 ( V_210 . V_211 , V_210 . V_22 ) ;
if ( V_210 . V_23 )
F_5 ( V_14 , L_236 , V_210 . V_23 -> V_27 ) ;
else
F_5 ( V_14 , L_237 ) ;
V_75 = F_225 ( V_222 ) ;
}
#endif
switch ( F_214 ( V_222 , V_75 ) )
{
case V_29 :
break;
case V_261 :
case V_262 :
case V_260 :
continue;
case V_263 :
case V_264 :
case V_265 :
V_11 = 1 ;
goto V_84;
}
F_207 ( V_222 ) ;
F_213 ( V_222 , NULL , 0 ) ;
}
V_75 = F_252 ( V_283 , V_73 , V_232 - 1 ) ;
if ( V_75 < 0 )
{
if ( ! F_253 ( V_283 ) )
{
if ( ! V_48 )
F_67 ( V_15 ) ;
goto V_84;
}
else
{
F_5 ( V_14 , L_269 ) ;
#if F_73 ( V_228 )
F_254 ( 1000 ) ;
#elif ! F_73 ( V_227 ) && ! F_73 ( V_286 )
F_255 ( 1 ) ;
#endif
continue;
}
}
else if ( V_75 == 0 )
{
V_11 = 1 ;
goto V_162;
}
if ( ( ( V_46 == 1 ) && ( strncmp ( L_270 , V_73 , 4 ) == 0 ) ) ||
( ( V_46 == 2 ) && ( strncmp ( L_271 , V_73 , 10 ) == 0 ) ) )
{
char * V_2 ;
T_11 * V_269 ;
F_43 ( T_30 ) * V_287 ;
static const char * V_288 = L_272 ;
F_44 ( V_283 , L_273 ) ;
F_44 ( V_283 , L_274 ) ;
F_44 ( V_283 , L_275 ) ;
F_44 ( V_283 , L_15 ) ;
for ( V_75 = 0 ; V_75 < V_158 ; V_75 ++ )
{
F_44 ( V_283 , V_159 [ V_75 ] ) ;
F_34 ( V_283 , L_276 , 1 ) ;
}
F_44 ( V_283 , L_15 ) ;
F_5 ( V_283 , L_277 ) ;
V_287 = F_256 ( V_222 ) ;
V_257 = F_257 ( V_287 ) ;
for ( V_75 = 0 ; V_75 < V_257 ; V_75 ++ )
{
V_282 = F_258 ( V_287 , V_75 ) ;
F_5 ( V_283 , L_278 ,
F_259 ( V_282 ) ,
F_236 ( V_282 ) ) ;
if ( ( ( ( V_75 + 1 ) % 2 ) == 0 ) && ( V_75 + 1 != V_257 ) )
F_44 ( V_283 , L_15 ) ;
}
F_44 ( V_283 , L_15 ) ;
V_2 = F_235 ( V_222 , V_73 , V_232 ) ;
if ( V_2 != NULL )
{
F_5 ( V_283 , L_279 ) ;
V_257 = V_75 = 0 ;
while ( * V_2 )
{
if ( * V_2 == ':' )
{
F_34 ( V_283 , V_288 , 26 - V_257 ) ;
V_75 ++ ;
V_257 = 0 ;
F_34 ( V_283 , ( ( V_75 % 3 ) ? L_276 : L_15 ) , 1 ) ;
}
else
{
F_34 ( V_283 , V_2 , 1 ) ;
V_257 ++ ;
}
V_2 ++ ;
}
F_44 ( V_283 , L_15 ) ;
}
F_5 ( V_283 , ( F_240 ( V_222 )
? L_280
: L_281 ) ) ;
V_282 = F_237 ( V_222 ) ;
F_5 ( V_283 , L_282 ,
F_259 ( V_282 ) ,
F_236 ( V_282 ) ) ;
F_260 ( V_283 , F_230 ( V_222 ) ) ;
F_5 ( V_283 , L_283 ) ;
F_144 ( V_283 , F_51 ( V_222 ) ) ;
F_5 ( V_283 , L_283 ) ;
V_269 = F_231 ( V_222 ) ;
if ( V_269 != NULL )
{
F_5 ( V_283 , L_248 ) ;
F_261 ( V_283 , V_269 ) ;
F_232 ( V_283 , V_269 ) ;
}
else
F_44 ( V_283 , L_284 ) ;
F_44 ( V_283 , L_285 ) ;
break;
}
else if ( ( V_46 == 2 || V_46 == 3 )
&& ( strncmp ( L_286 , V_73 , 5 ) == 0 ) )
{
T_7 * V_289 ;
char * V_2 , * V_131 ;
static const char * V_290 = L_287 ;
V_2 = & ( V_73 [ 5 ] ) ;
V_281 = 1 ;
for ( V_131 = V_2 ; * V_131 != '\0' ; V_131 ++ )
{
if ( V_131 [ 0 ] == ' ' )
break;
switch ( V_281 )
{
case 1 :
V_281 = ( V_131 [ 0 ] == '.' ) ? 2 : 0 ;
break;
case 2 :
V_281 = ( V_131 [ 0 ] == '.' ) ? 3 : 0 ;
break;
case 3 :
V_281 = ( V_131 [ 0 ] == '/' ) ? - 1 : 0 ;
break;
}
if ( V_281 == 0 )
V_281 = ( V_131 [ 0 ] == '/' ) ? 1 : 0 ;
}
V_281 = ( V_281 == 3 ) || ( V_281 == - 1 ) ;
if ( * V_131 == '\0' )
{
F_44 ( V_283 , V_290 ) ;
F_5 ( V_283 , L_288 , V_2 ) ;
break;
}
* V_131 = '\0' ;
if ( V_281 )
{
F_44 ( V_283 , V_290 ) ;
F_5 ( V_283 , L_289 , V_2 ) ;
break;
}
if ( * V_2 == '/' )
{
F_44 ( V_283 , V_290 ) ;
F_5 ( V_283 , L_290 , V_2 ) ;
break;
}
#if 0
if (e[-1] == '/')
strcat(p,"index.html");
#endif
if ( F_262 ( V_2 ) > 0 )
{
#if 0
strcat(p,"/index.html");
#else
F_44 ( V_283 , V_290 ) ;
F_5 ( V_283 , L_291 , V_2 ) ;
break;
#endif
}
if ( ( V_289 = F_246 ( V_2 , L_268 ) ) == NULL )
{
F_44 ( V_283 , V_290 ) ;
F_5 ( V_283 , L_292 , V_2 ) ;
F_67 ( V_283 ) ;
break;
}
if ( ! V_48 )
F_5 ( V_15 , L_293 , V_2 ) ;
if ( V_46 == 2 )
{
V_75 = strlen ( V_2 ) ;
if ( ( ( V_75 > 5 ) && ( strcmp ( & ( V_2 [ V_75 - 5 ] ) , L_294 ) == 0 ) ) ||
( ( V_75 > 4 ) && ( strcmp ( & ( V_2 [ V_75 - 4 ] ) , L_295 ) == 0 ) ) ||
( ( V_75 > 4 ) && ( strcmp ( & ( V_2 [ V_75 - 4 ] ) , L_296 ) == 0 ) ) )
F_44 ( V_283 , L_273 ) ;
else
F_44 ( V_283 , L_287 ) ;
}
for (; ; )
{
V_75 = F_30 ( V_289 , V_73 , V_232 ) ;
if ( V_75 <= 0 ) break;
#ifdef F_212
V_291 += V_75 ;
fprintf ( V_160 , L_297 , V_75 ) ;
if ( V_291 > 3 * 1024 )
{
V_291 = 0 ;
fprintf ( V_160 , L_298 ) ;
F_207 ( V_222 ) ;
}
#endif
for ( V_257 = 0 ; V_257 < V_75 ; )
{
#ifdef F_212
{ static V_259 = 0 ; if ( ++ V_259 == 13 ) { F_207 ( V_222 ) ; } }
#endif
V_220 = F_34 ( V_283 , & ( V_73 [ V_257 ] ) , V_75 - V_257 ) ;
if ( V_220 <= 0 )
{
if ( ! F_253 ( V_283 ) )
goto V_292;
else
{
F_5 ( V_14 , L_299 ) ;
}
}
else
{
V_257 += V_220 ;
}
}
}
V_292:
F_147 ( V_289 ) ;
break;
}
}
for (; ; )
{
V_75 = ( int ) F_115 ( V_283 ) ;
if ( V_75 <= 0 )
{
if ( ! F_253 ( V_283 ) )
break;
}
else
break;
}
V_162:
#if 1
F_220 ( V_222 , V_267 | V_268 ) ;
#else
#endif
V_84:
if ( V_11 >= 0 )
F_5 ( V_14 , L_215 ) ;
if ( V_73 != NULL ) F_28 ( V_73 ) ;
if ( V_283 != NULL ) F_263 ( V_283 ) ;
return ( V_11 ) ;
}
static T_24 T_4 * V_203 ( T_2 * V_19 , int V_293 , int V_294 )
{
T_3 * V_12 = NULL ;
static T_24 * V_295 = NULL ;
if ( ! V_295 && ( ( V_12 = F_264 () ) == NULL ) )
F_5 ( V_15 , L_300 ) ;
if ( ! V_295 && V_12 )
{
if ( ! V_48 )
{
F_5 ( V_15 , L_301 , V_294 ) ;
( void ) F_115 ( V_15 ) ;
}
if( ! F_265 ( V_12 , V_205 ) || ( ( V_295 = F_266 () ) == NULL ) ||
! F_267 ( V_295 , V_294 , V_12 , NULL ) )
{
if( V_295 ) F_127 ( V_295 ) ;
V_295 = NULL ;
}
if ( ! V_48 )
{
F_5 ( V_15 , L_15 ) ;
( void ) F_115 ( V_15 ) ;
}
F_7 ( V_12 ) ;
}
return ( V_295 ) ;
}
static int V_194 ( const T_2 * V_6 , unsigned char * V_98 ,
unsigned int * V_296 )
{
unsigned int V_259 = 0 ;
do {
F_268 ( V_98 , * V_296 ) ;
memcpy ( V_98 , V_186 ,
( strlen ( V_186 ) < * V_296 ) ?
strlen ( V_186 ) : * V_296 ) ;
}
while( F_269 ( V_6 , V_98 , * V_296 ) &&
( ++ V_259 < V_297 ) );
if( V_259 >= V_297 )
return 0 ;
return 1 ;
}
