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
static void F_10 ( void )
{
V_19 = - 1 ;
V_20 = NULL ;
V_21 = V_22 ;
V_23 = NULL ;
V_24 = NULL ;
V_25 = V_26 ;
V_27 = NULL ;
#ifndef F_11
V_28 = V_29 ;
V_30 = NULL ;
V_31 = NULL ;
#endif
#ifdef F_12
V_32 = 0 ;
#endif
V_33 = 0 ;
V_34 = NULL ;
V_35 = 0 ;
V_14 = NULL ;
V_13 = 0 ;
V_36 = 0 ;
V_37 = 0 ;
V_38 = 0 ;
#ifndef F_13
V_39 = NULL ;
#endif
}
static void F_14 ( void )
{
F_5 ( V_15 , L_11 ) ;
F_5 ( V_15 , L_12 ) ;
F_5 ( V_15 , L_13 , V_40 ) ;
F_5 ( V_15 , L_14 ) ;
F_5 ( V_15 , L_15 ) ;
F_5 ( V_15 , L_16 ) ;
F_5 ( V_15 , L_17 ) ;
F_5 ( V_15 , L_18 , V_26 ) ;
F_5 ( V_15 , L_19 \
L_20 ) ;
F_5 ( V_15 , L_21 \
L_22 \
L_23 ) ;
F_5 ( V_15 , L_24 ) ;
F_5 ( V_15 , L_25 ) ;
F_5 ( V_15 , L_26 , V_26 ) ;
F_5 ( V_15 , L_27 ) ;
F_5 ( V_15 , L_28 ) ;
F_5 ( V_15 , L_29 ) ;
F_5 ( V_15 , L_30 ) ;
F_5 ( V_15 , L_31 ) ;
F_5 ( V_15 , L_32 ) ;
F_5 ( V_15 , L_33 ) ;
F_5 ( V_15 , L_34 ) ;
F_5 ( V_15 , L_35 ) ;
#ifndef F_15
F_5 ( V_15 , L_36 \
L_37 \
L_38 ) ;
#endif
#ifdef F_12
F_5 ( V_15 , L_39 ) ;
#endif
F_5 ( V_15 , L_40 ) ;
F_5 ( V_15 , L_41 ) ;
F_5 ( V_15 , L_42 ) ;
F_5 ( V_15 , L_43 ) ;
F_5 ( V_15 , L_44 ) ;
F_5 ( V_15 , L_45 ) ;
F_5 ( V_15 , L_46 ) ;
F_5 ( V_15 , L_47 ) ;
F_5 ( V_15 , L_48 ) ;
F_5 ( V_15 , L_49 ) ;
F_5 ( V_15 , L_50 ) ;
F_5 ( V_15 , L_51 ) ;
#ifndef F_16
F_5 ( V_15 , L_52 ) ;
F_5 ( V_15 , L_53 ) ;
# ifndef F_17
F_5 ( V_15 , L_54 ) ;
# endif
#endif
F_5 ( V_15 , L_55 ) ;
F_5 ( V_15 , L_56 ) ;
F_5 ( V_15 , L_57 ) ;
F_5 ( V_15 , L_58 ) ;
F_5 ( V_15 , L_59 ) ;
F_5 ( V_15 , L_60 ) ;
F_5 ( V_15 , L_61 ) ;
F_5 ( V_15 , L_62 ) ;
F_5 ( V_15 , L_63 ) ;
F_5 ( V_15 , L_64 ) ;
#ifndef F_18
F_5 ( V_15 , L_65 ) ;
#endif
#ifndef F_15
F_5 ( V_15 , L_66 ) ;
#endif
F_5 ( V_15 , L_67 ) ;
F_5 ( V_15 , L_68 ) ;
F_5 ( V_15 , L_69 ) ;
F_5 ( V_15 , L_70 ) ;
F_5 ( V_15 , L_71 ) ;
#ifndef F_13
F_5 ( V_15 , L_72 ) ;
#endif
F_5 ( V_15 , L_73 ) ;
F_5 ( V_15 , L_74 , V_41 , V_41 ) ;
#ifndef F_11
F_5 ( V_15 , L_75 ) ;
F_5 ( V_15 , L_76 ) ;
F_5 ( V_15 , L_77 ) ;
F_5 ( V_15 , L_18 , V_29 ) ;
F_5 ( V_15 , L_78 ) ;
F_5 ( V_15 , L_26 , V_29 ) ;
F_5 ( V_15 , L_79 ) ;
F_5 ( V_15 , L_80 ) ;
F_5 ( V_15 , L_81 ) ;
#endif
}
T_4 * F_19 ()
{
return ( & V_42 ) ;
}
static int F_20 ( T_5 * V_43 )
{
T_6 * V_44 ;
V_44 = ( T_6 * ) F_21 ( sizeof( T_6 ) + 1024 ) ;
V_44 -> V_45 = 1024 ;
V_44 -> V_46 [ 0 ] = '\0' ;
V_43 -> V_47 = ( char * ) V_44 ;
V_43 -> V_48 = 1 ;
V_43 -> V_49 = 0 ;
return ( 1 ) ;
}
static int F_22 ( T_5 * V_50 )
{
if ( V_50 == NULL ) return ( 0 ) ;
if ( V_50 -> V_47 != NULL )
F_23 ( V_50 -> V_47 ) ;
V_50 -> V_47 = NULL ;
V_50 -> V_48 = 0 ;
V_50 -> V_49 = 0 ;
return ( 1 ) ;
}
static int F_24 ( T_5 * V_51 , char * V_52 , int V_53 )
{
int V_11 = 0 ;
if ( V_52 == NULL || V_53 == 0 ) return ( 0 ) ;
if ( V_51 -> V_54 == NULL ) return ( 0 ) ;
V_11 = F_25 ( V_51 -> V_54 , V_52 , V_53 ) ;
if ( V_11 > 0 )
F_26 ( V_52 , V_52 , V_11 ) ;
return ( V_11 ) ;
}
static int F_27 ( T_5 * V_51 , const char * V_55 , int V_56 )
{
T_6 * V_44 ;
int V_11 = 0 ;
int V_57 ;
unsigned char V_58 ;
if ( ( V_55 == NULL ) || ( V_56 <= 0 ) ) return ( 0 ) ;
if ( V_51 -> V_54 == NULL ) return ( 0 ) ;
V_44 = ( T_6 * ) V_51 -> V_47 ;
if ( V_56 > ( V_57 = V_44 -> V_45 ) )
{
V_57 = V_57 + V_57 ;
if ( V_57 < V_56 )
V_57 = V_56 ;
F_23 ( V_44 ) ;
V_44 = ( T_6 * ) F_21 ( sizeof( T_6 ) + V_57 ) ;
V_44 -> V_45 = V_57 ;
V_44 -> V_46 [ 0 ] = '\0' ;
V_51 -> V_47 = ( char * ) V_44 ;
}
F_28 ( V_44 -> V_46 , V_55 , V_56 ) ;
V_11 = F_29 ( V_51 -> V_54 , V_44 -> V_46 , V_56 ) ;
return ( V_11 ) ;
}
static long F_30 ( T_5 * V_51 , int V_59 , long V_57 , void * V_47 )
{
long V_11 ;
if ( V_51 -> V_54 == NULL ) return ( 0 ) ;
switch ( V_59 )
{
case V_60 :
V_11 = 0L ;
break;
default:
V_11 = F_31 ( V_51 -> V_54 , V_59 , V_57 , V_47 ) ;
break;
}
return ( V_11 ) ;
}
static int F_32 ( T_5 * V_61 , char * V_62 , int V_63 )
{
int V_64 , V_11 = 0 ;
if ( V_61 -> V_54 == NULL ) return ( 0 ) ;
for ( V_64 = 0 ; V_64 < V_63 - 1 ; ++ V_64 )
{
V_11 = F_24 ( V_61 , & V_62 [ V_64 ] , 1 ) ;
if ( V_11 <= 0 )
break;
else if ( V_62 [ V_64 ] == '\n' )
{
++ V_64 ;
break;
}
}
if ( V_64 < V_63 )
V_62 [ V_64 ] = '\0' ;
return ( V_11 < 0 && V_64 == 0 ) ? V_11 : V_64 ;
}
static int F_33 ( T_5 * V_61 , const char * V_65 )
{
if ( V_61 -> V_54 == NULL ) return ( 0 ) ;
return F_27 ( V_61 , V_65 , strlen ( V_65 ) ) ;
}
static int T_7 F_34 ( T_2 * V_66 , int * V_67 , void * V_68 )
{
T_8 * V_2 = ( T_8 * ) V_68 ;
const char * V_69 = F_35 ( V_66 , V_70 ) ;
if ( V_69 && V_2 -> V_71 )
F_5 ( V_2 -> V_71 , L_82 , V_69 ) ;
if ( ! V_2 -> V_69 )
return V_72 ;
if ( V_69 )
{
if ( strcmp ( V_69 , V_2 -> V_69 ) )
return V_2 -> V_73 ;
if ( V_31 )
{
F_5 ( V_2 -> V_71 , L_83 ) ;
F_36 ( V_66 , V_31 ) ;
}
}
return V_74 ;
}
static int F_37 ( T_2 * V_66 , void * V_68 )
{
T_9 * V_75 = V_68 ;
T_5 * V_76 = V_75 -> V_76 ;
char * V_77 , * V_78 , * V_79 ;
int V_80 ;
unsigned char * V_81 = NULL ;
int V_82 ;
F_38 ( V_83 ) * V_84 = NULL ;
T_10 * V_85 = NULL ;
T_11 V_86 ;
T_12 V_87 ;
T_13 * V_88 = NULL ;
T_14 * V_89 = NULL ;
T_15 * V_90 = NULL ;
F_38 ( V_91 ) * V_92 ;
int V_11 = V_72 ;
int V_64 ;
#if 0
STACK_OF(OCSP_RESPID) *ids;
SSL_get_tlsext_status_ids(s, &ids);
BIO_printf(err, "cert_status: received %d ids\n", sk_OCSP_RESPID_num(ids));
#endif
if ( V_75 -> V_93 )
F_39 ( V_76 , L_84 ) ;
V_85 = F_40 ( V_66 ) ;
V_84 = F_41 ( V_85 ) ;
if ( V_84 )
{
if ( ! F_42 ( F_43 ( V_84 , 0 ) ,
& V_77 , & V_78 , & V_79 , & V_80 ) )
{
F_39 ( V_76 , L_85 ) ;
goto V_76;
}
if ( V_75 -> V_93 )
F_5 ( V_76 , L_86 ,
F_43 ( V_84 , 0 ) ) ;
}
else
{
if ( ! V_75 -> V_77 )
{
F_39 ( V_75 -> V_76 , L_87 ) ;
goto V_94;
}
V_77 = V_75 -> V_77 ;
V_79 = V_75 -> V_79 ;
V_78 = V_75 -> V_78 ;
V_80 = V_75 -> V_80 ;
}
if ( ! F_44 ( & V_86 ,
F_45 ( F_46 ( V_66 ) ) ,
NULL , NULL ) )
goto V_76;
if ( F_47 ( & V_86 , V_95 ,
F_48 ( V_85 ) , & V_87 ) <= 0 )
{
F_39 ( V_76 , L_88 ) ;
F_49 ( & V_86 ) ;
goto V_94;
}
V_88 = F_50 () ;
if ( ! V_88 )
goto V_76;
V_90 = F_51 ( NULL , V_85 , V_87 . V_96 . V_97 ) ;
F_52 ( V_87 . V_96 . V_97 ) ;
F_49 ( & V_86 ) ;
if ( ! V_90 )
goto V_76;
if ( ! F_53 ( V_88 , V_90 ) )
goto V_76;
V_90 = NULL ;
F_54 ( V_66 , & V_92 ) ;
for ( V_64 = 0 ; V_64 < F_55 ( V_92 ) ; V_64 ++ )
{
V_91 * V_98 = F_56 ( V_92 , V_64 ) ;
if ( ! F_57 ( V_88 , V_98 , - 1 ) )
goto V_76;
}
V_89 = F_58 ( V_76 , V_88 , V_77 , V_79 , V_78 , V_80 , NULL ,
V_75 -> V_99 ) ;
if ( ! V_89 )
{
F_39 ( V_76 , L_89 ) ;
goto V_94;
}
V_82 = F_59 ( V_89 , & V_81 ) ;
if ( V_82 <= 0 )
goto V_76;
F_60 ( V_66 , V_81 , V_82 ) ;
if ( V_75 -> V_93 )
{
F_39 ( V_76 , L_90 ) ;
F_61 ( V_76 , V_89 , 2 ) ;
}
V_11 = V_74 ;
V_94:
if ( V_11 != V_74 )
F_62 ( V_76 ) ;
if ( V_84 )
{
F_23 ( V_77 ) ;
F_23 ( V_79 ) ;
F_23 ( V_78 ) ;
F_63 ( V_84 ) ;
}
if ( V_90 )
F_64 ( V_90 ) ;
if ( V_88 )
F_65 ( V_88 ) ;
if ( V_89 )
F_66 ( V_89 ) ;
return V_11 ;
V_76:
V_11 = V_100 ;
goto V_94;
}
int MAIN ( int V_101 , char * V_102 [] )
{
T_16 * V_103 = NULL ;
int V_104 = 0 ;
short V_78 = V_40 ;
char * V_105 = NULL , * V_106 = NULL ;
unsigned char * V_107 = NULL ;
char * V_108 = NULL ;
#ifndef F_15
char * V_109 = NULL ;
#endif
int V_110 = 0 , V_111 = 0 ;
int V_11 = 1 ;
int V_112 = 0 ;
int V_113 = 0 , V_114 = 0 , V_115 = 0 , V_116 = 0 ;
int V_117 = 0 ;
const T_17 * V_118 = NULL ;
int V_119 = V_120 ;
T_18 * V_121 = NULL ;
char * V_122 = NULL ;
int V_123 = V_124 , V_125 = V_124 ;
char * V_126 = NULL , * V_127 = NULL ;
char * V_128 = NULL , * V_129 = NULL ;
int V_130 = V_124 , V_131 = V_124 ;
T_10 * V_132 = NULL , * V_133 = NULL ;
T_19 * V_134 = NULL , * V_135 = NULL ;
int V_136 = 0 ;
#ifndef F_11
T_19 * V_137 = NULL ;
T_10 * V_138 = NULL ;
#endif
#ifndef F_11
T_8 V_139 = { NULL , NULL , V_140 } ;
#endif
#ifndef F_16
static char * V_141 = NULL ;
#endif
#if ! F_67 ( V_142 ) && ! F_67 ( V_143 )
V_118 = F_68 () ;
#elif ! F_67 ( V_143 )
V_118 = F_69 () ;
#elif ! F_67 ( V_142 )
V_118 = F_70 () ;
#endif
V_144 = V_101 ;
V_145 = V_102 ;
F_71 () ;
#ifdef F_72
F_10 () ;
#endif
if ( V_15 == NULL )
V_15 = F_73 ( V_146 , V_147 ) ;
if ( ! F_74 ( V_15 , NULL ) )
goto V_148;
V_149 = 0 ;
#ifdef F_12
V_32 = 0 ;
#endif
V_33 = 0 ;
V_101 -- ;
V_102 ++ ;
while ( V_101 >= 1 )
{
if ( ( strcmp ( * V_102 , L_91 ) == 0 ) ||
( strcmp ( * V_102 , L_92 ) == 0 ) )
{
if ( -- V_101 < 1 ) goto V_150;
if ( ! F_75 ( * ( ++ V_102 ) , & V_78 ) )
goto V_150;
}
else if ( strcmp ( * V_102 , L_93 ) == 0 )
{
V_21 = V_151 | V_152 ;
if ( -- V_101 < 1 ) goto V_150;
V_149 = atoi ( * ( ++ V_102 ) ) ;
F_5 ( V_15 , L_94 , V_149 ) ;
}
else if ( strcmp ( * V_102 , L_95 ) == 0 )
{
V_21 = V_151 | V_153 |
V_152 ;
if ( -- V_101 < 1 ) goto V_150;
V_149 = atoi ( * ( ++ V_102 ) ) ;
F_5 ( V_15 , L_96 , V_149 ) ;
}
else if ( strcmp ( * V_102 , L_97 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_107 = ( unsigned char * ) * ( ++ V_102 ) ;
}
else if ( strcmp ( * V_102 , L_98 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_25 = * ( ++ V_102 ) ;
}
else if ( strcmp ( * V_102 , L_99 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_123 = F_76 ( * ( ++ V_102 ) ) ;
}
else if ( strcmp ( * V_102 , L_100 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_27 = * ( ++ V_102 ) ;
}
else if ( strcmp ( * V_102 , L_101 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_125 = F_76 ( * ( ++ V_102 ) ) ;
}
else if ( strcmp ( * V_102 , L_102 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_126 = * ( ++ V_102 ) ;
}
else if ( strcmp ( * V_102 , L_103 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_108 = * ( ++ V_102 ) ;
}
#ifndef F_15
else if ( strcmp ( * V_102 , L_104 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_109 = * ( ++ V_102 ) ;
}
#endif
else if ( strcmp ( * V_102 , L_105 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_130 = F_76 ( * ( ++ V_102 ) ) ;
}
else if ( strcmp ( * V_102 , L_106 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_23 = * ( ++ V_102 ) ;
}
else if ( strcmp ( * V_102 , L_107 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_131 = F_76 ( * ( ++ V_102 ) ) ;
}
else if ( strcmp ( * V_102 , L_108 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_128 = * ( ++ V_102 ) ;
}
else if ( strcmp ( * V_102 , L_109 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_24 = * ( ++ V_102 ) ;
}
else if ( strcmp ( * V_102 , L_110 ) == 0 )
{
V_116 = 1 ;
}
else if ( strcmp ( * V_102 , L_111 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_105 = * ( ++ V_102 ) ;
}
else if ( strcmp ( * V_102 , L_112 ) == 0 )
V_136 = 1 ;
else if ( F_77 ( & V_102 , & V_101 , & V_104 , V_15 , & V_103 ) )
{
if ( V_104 )
goto V_150;
continue;
}
else if ( strcmp ( * V_102 , L_113 ) == 0 )
V_154 = 1 ;
else if ( strcmp ( * V_102 , L_114 ) == 0 )
{ V_112 |= V_155 ; }
else if ( strcmp ( * V_102 , L_115 ) == 0 )
V_112 |= V_156 ;
else if ( strcmp ( * V_102 , L_116 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_20 = * ( ++ V_102 ) ;
}
else if ( strcmp ( * V_102 , L_117 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_106 = * ( ++ V_102 ) ;
}
#ifdef F_12
else if ( strcmp ( * V_102 , L_118 ) == 0 )
{ V_32 = 1 ; }
#endif
else if ( strcmp ( * V_102 , L_119 ) == 0 )
{
#ifdef F_12
V_32 = 1 ;
#endif
V_33 = 1 ;
}
else if ( strcmp ( * V_102 , L_120 ) == 0 )
{ V_13 = 1 ; }
#ifndef F_11
else if ( strcmp ( * V_102 , L_121 ) == 0 )
V_157 = 1 ;
else if ( strcmp ( * V_102 , L_122 ) == 0 )
V_158 = 1 ;
else if ( strcmp ( * V_102 , L_123 ) == 0 )
{
V_158 = 1 ;
V_159 . V_93 = 1 ;
}
else if ( ! strcmp ( * V_102 , L_124 ) )
{
V_158 = 1 ;
if ( -- V_101 < 1 ) goto V_150;
V_159 . V_99 = atoi ( * ( ++ V_102 ) ) ;
}
else if ( ! strcmp ( * V_102 , L_125 ) )
{
V_158 = 1 ;
if ( -- V_101 < 1 ) goto V_150;
if ( ! F_42 ( * ( ++ V_102 ) ,
& V_159 . V_77 ,
& V_159 . V_78 ,
& V_159 . V_79 ,
& V_159 . V_80 ) )
{
F_5 ( V_15 , L_126 ) ;
goto V_150;
}
}
#endif
else if ( strcmp ( * V_102 , L_127 ) == 0 )
{ V_36 = 1 ; }
else if ( strcmp ( * V_102 , L_128 ) == 0 )
{ V_38 = 1 ; }
else if ( strcmp ( * V_102 , L_129 ) == 0 )
{ V_117 = 1 ; }
else if ( strcmp ( * V_102 , L_130 ) == 0 )
{ V_160 = 1 ; }
else if ( strcmp ( * V_102 , L_131 ) == 0 )
{ V_37 = 1 ; }
else if ( strcmp ( * V_102 , L_132 ) == 0 )
{ V_111 = 1 ; }
else if ( strcmp ( * V_102 , L_133 ) == 0 )
{ V_113 = 1 ; }
else if ( strcmp ( * V_102 , L_134 ) == 0 )
{ V_114 = 1 ; }
else if ( strcmp ( * V_102 , L_135 ) == 0 )
{ V_115 = 1 ; }
#ifndef F_16
else if ( strcmp ( * V_102 , L_136 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_141 = * ( ++ V_102 ) ;
}
else if ( strcmp ( * V_102 , L_137 ) == 0 )
{
T_20 V_64 ;
if ( -- V_101 < 1 ) goto V_150;
V_18 = * ( ++ V_102 ) ;
for ( V_64 = 0 ; V_64 < strlen ( V_18 ) ; V_64 ++ )
{
if ( isxdigit ( ( int ) V_18 [ V_64 ] ) )
continue;
F_5 ( V_15 , L_138 , * V_102 ) ;
goto V_150;
}
}
#endif
else if ( strcmp ( * V_102 , L_139 ) == 0 )
{ V_35 = 1 ; }
else if ( strcmp ( * V_102 , L_140 ) == 0 )
{ V_35 = 2 ; }
else if ( strcmp ( * V_102 , L_141 ) == 0 )
{ V_35 = 3 ; }
else if ( strcmp ( * V_102 , L_142 ) == 0 )
{ V_112 |= V_161 ; }
else if ( strcmp ( * V_102 , L_143 ) == 0 )
{ V_112 |= V_162 ; }
else if ( strcmp ( * V_102 , L_144 ) == 0 )
{ V_112 |= V_163 ; }
else if ( strcmp ( * V_102 , L_145 ) == 0 )
{ V_112 |= V_164 ; }
#ifndef F_11
else if ( strcmp ( * V_102 , L_146 ) == 0 )
{ V_112 |= V_165 ; }
#endif
#ifndef V_142
else if ( strcmp ( * V_102 , L_147 ) == 0 )
{ V_118 = F_70 () ; }
#endif
#ifndef V_143
else if ( strcmp ( * V_102 , L_148 ) == 0 )
{ V_118 = F_69 () ; }
#endif
#ifndef F_78
else if ( strcmp ( * V_102 , L_149 ) == 0 )
{ V_118 = F_79 () ; }
#endif
#ifndef F_80
else if ( strcmp ( * V_102 , L_150 ) == 0 )
{
V_118 = F_81 () ;
V_119 = V_166 ;
}
else if ( strcmp ( * V_102 , L_151 ) == 0 )
V_167 = 1 ;
else if ( strcmp ( * V_102 , L_152 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_168 = atol ( * ( ++ V_102 ) ) ;
}
else if ( strcmp ( * V_102 , L_153 ) == 0 )
V_169 = 1 ;
#endif
else if ( strcmp ( * V_102 , L_154 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_170 = * ( ++ V_102 ) ;
}
#ifndef F_13
else if ( strcmp ( * V_102 , L_155 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_39 = * ( ++ V_102 ) ;
}
#endif
else if ( strcmp ( * V_102 , L_156 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_122 = * ( ++ V_102 ) ;
}
#ifndef F_11
else if ( strcmp ( * V_102 , L_157 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_139 . V_69 = * ( ++ V_102 ) ;
}
else if ( strcmp ( * V_102 , L_158 ) == 0 )
{ V_139 . V_73 = V_100 ; }
else if ( strcmp ( * V_102 , L_159 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_28 = * ( ++ V_102 ) ;
}
else if ( strcmp ( * V_102 , L_160 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_30 = * ( ++ V_102 ) ;
}
#endif
#if ! F_67 ( F_17 ) && ! F_67 ( F_16 )
else if ( strcmp ( * V_102 , L_161 ) == 0 )
{
if ( -- V_101 < 1 ) goto V_150;
V_171 = * ( ++ V_102 ) ;
}
#endif
else
{
F_5 ( V_15 , L_162 , * V_102 ) ;
V_110 = 1 ;
break;
}
V_101 -- ;
V_102 ++ ;
}
if ( V_110 )
{
V_150:
F_14 () ;
goto V_148;
}
#if ! F_67 ( F_17 ) && ! F_67 ( F_16 )
if ( V_171 )
{
if ( V_18 )
{
F_5 ( V_15 ,
L_163 ) ;
goto V_148;
}
V_17 = L_164 ;
if ( V_20 )
{
F_5 ( V_15 , L_165 ) ;
goto V_148;
}
V_20 = L_166 ;
}
#endif
F_82 () ;
F_83 () ;
#ifndef F_13
V_121 = F_84 ( V_15 , V_39 , 1 ) ;
#endif
if ( ! F_85 ( V_15 , V_126 , V_128 , & V_127 , & V_129 ) )
{
F_5 ( V_15 , L_167 ) ;
goto V_148;
}
if ( V_27 == NULL )
V_27 = V_25 ;
#ifndef F_11
if ( V_30 == NULL )
V_30 = V_28 ;
#endif
if ( V_116 == 0 )
{
V_134 = F_86 ( V_15 , V_27 , V_125 , 0 , V_127 , V_121 ,
L_168 ) ;
if ( ! V_134 )
{
F_62 ( V_15 ) ;
goto V_148;
}
V_132 = F_87 ( V_15 , V_25 , V_123 ,
NULL , V_121 , L_169 ) ;
if ( ! V_132 )
{
F_62 ( V_15 ) ;
goto V_148;
}
#ifndef F_11
if ( V_139 . V_69 )
{
V_137 = F_86 ( V_15 , V_30 , V_125 , 0 , V_127 , V_121 ,
L_170 ) ;
if ( ! V_137 )
{
F_62 ( V_15 ) ;
goto V_148;
}
V_138 = F_87 ( V_15 , V_28 , V_123 ,
NULL , V_121 , L_171 ) ;
if ( ! V_138 )
{
F_62 ( V_15 ) ;
goto V_148;
}
}
#endif
}
if ( V_23 )
{
if ( V_24 == NULL )
V_24 = V_23 ;
V_135 = F_86 ( V_15 , V_24 , V_131 ,
0 , V_129 , V_121 ,
L_172 ) ;
if ( ! V_135 )
{
F_62 ( V_15 ) ;
goto V_148;
}
V_133 = F_87 ( V_15 , V_23 , V_130 ,
NULL , V_121 , L_171 ) ;
if ( ! V_133 )
{
F_62 ( V_15 ) ;
goto V_148;
}
}
if ( ! F_88 ( NULL , V_15 , 1 ) && V_122 == NULL
&& ! F_89 () )
{
F_5 ( V_15 , L_173 ) ;
}
if ( V_122 != NULL )
F_5 ( V_15 , L_174 ,
F_90 ( V_122 ) ) ;
if ( V_14 == NULL )
{
if ( V_37 && ! V_13 && ! V_36 )
{
V_14 = F_91 ( F_92 () ) ;
}
else
{
if ( V_14 == NULL )
V_14 = F_73 ( stdout , V_147 ) ;
}
}
#if ! F_67 ( V_172 ) || ! F_67 ( V_173 ) || ! F_67 ( V_174 )
if ( V_116 )
#endif
{
V_25 = NULL ;
V_27 = NULL ;
V_23 = NULL ;
V_24 = NULL ;
#ifndef F_11
V_28 = NULL ;
V_30 = NULL ;
#endif
}
V_34 = F_93 ( V_118 ) ;
if ( V_34 == NULL )
{
F_62 ( V_15 ) ;
goto V_148;
}
if ( V_170 )
{
if( strlen ( V_170 ) >= 32 )
F_5 ( V_15 ,
L_175 ) ;
else if( strlen ( V_170 ) >= 16 )
F_5 ( V_15 ,
L_176 ) ;
if( ! F_94 ( V_34 , V_175 ) )
{
F_5 ( V_15 , L_177 ) ;
F_62 ( V_15 ) ;
goto V_148;
}
F_5 ( V_15 , L_178 , V_170 ) ;
}
F_95 ( V_34 , 1 ) ;
if ( V_111 ) F_96 ( V_34 , V_176 ) ;
if ( V_38 ) F_96 ( V_34 , V_177 ) ;
F_96 ( V_34 , V_112 ) ;
if ( V_119 == V_166 ) F_97 ( V_34 , 1 ) ;
if ( V_117 ) F_98 ( V_34 , V_178 ) ;
if ( V_136 )
F_99 ( V_34 , V_179 ) ;
else
F_100 ( V_34 , 128 ) ;
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
if ( ( ! F_101 ( V_34 , V_106 , V_105 ) ) ||
( ! F_102 ( V_34 ) ) )
{
F_62 ( V_15 ) ;
}
if ( V_103 )
F_103 ( V_34 , V_103 ) ;
#ifndef F_11
if ( V_138 )
{
V_31 = F_93 ( V_118 ) ;
if ( V_31 == NULL )
{
F_62 ( V_15 ) ;
goto V_148;
}
}
if ( V_31 )
{
F_5 ( V_14 , L_179 ) ;
if ( V_170 )
{
if( strlen ( V_170 ) >= 32 )
F_5 ( V_15 ,
L_175 ) ;
else if( strlen ( V_170 ) >= 16 )
F_5 ( V_15 ,
L_176 ) ;
if( ! F_94 ( V_31 , V_175 ) )
{
F_5 ( V_15 , L_177 ) ;
F_62 ( V_15 ) ;
goto V_148;
}
F_5 ( V_15 , L_178 , V_170 ) ;
}
F_95 ( V_31 , 1 ) ;
if ( V_111 ) F_96 ( V_31 , V_176 ) ;
if ( V_38 ) F_96 ( V_31 , V_177 ) ;
F_96 ( V_31 , V_112 ) ;
if ( V_119 == V_166 ) F_97 ( V_31 , 1 ) ;
if ( V_117 ) F_98 ( V_31 , V_178 ) ;
if ( V_136 )
F_99 ( V_31 , V_179 ) ;
else
F_100 ( V_31 , 128 ) ;
if ( ( ! F_101 ( V_31 , V_106 , V_105 ) ) ||
( ! F_102 ( V_31 ) ) )
{
F_62 ( V_15 ) ;
}
if ( V_103 )
F_103 ( V_31 , V_103 ) ;
}
#endif
#ifndef F_18
if ( ! V_114 )
{
T_1 * V_1 = NULL ;
if ( V_108 )
V_1 = F_104 ( V_108 ) ;
else if ( V_25 )
V_1 = F_104 ( V_25 ) ;
if ( V_1 != NULL )
{
F_5 ( V_14 , L_180 ) ;
}
else
{
F_5 ( V_14 , L_181 ) ;
V_1 = F_1 () ;
}
( void ) F_105 ( V_14 ) ;
F_106 ( V_34 , V_1 ) ;
#ifndef F_11
if ( V_31 )
{
if ( ! V_108 )
{
T_1 * V_180 = F_104 ( V_28 ) ;
if ( V_180 != NULL )
{
F_5 ( V_14 , L_180 ) ;
( void ) F_105 ( V_14 ) ;
F_107 ( V_1 ) ;
V_1 = V_180 ;
}
}
F_106 ( V_31 , V_1 ) ;
}
#endif
F_107 ( V_1 ) ;
}
#endif
#ifndef F_15
if ( ! V_115 )
{
T_21 * V_181 = NULL ;
if ( V_109 )
{
int V_182 = F_108 ( V_109 ) ;
if ( V_182 == 0 )
{
F_5 ( V_15 , L_182 ,
V_109 ) ;
goto V_148;
}
V_181 = F_109 ( V_182 ) ;
if ( V_181 == NULL )
{
F_5 ( V_15 , L_183 ,
V_109 ) ;
goto V_148;
}
}
if ( V_181 != NULL )
{
F_5 ( V_14 , L_184 ) ;
}
else
{
F_5 ( V_14 , L_185 ) ;
V_181 = F_109 ( V_183 ) ;
if ( V_181 == NULL )
{
F_5 ( V_15 , L_186 ) ;
goto V_148;
}
}
( void ) F_105 ( V_14 ) ;
F_110 ( V_34 , V_181 ) ;
#ifndef F_11
if ( V_31 )
F_110 ( V_31 , V_181 ) ;
#endif
F_111 ( V_181 ) ;
}
#endif
if ( ! F_112 ( V_34 , V_132 , V_134 ) )
goto V_148;
#ifndef F_11
if ( V_31 && ! F_112 ( V_31 , V_138 , V_137 ) )
goto V_148;
#endif
if ( V_133 != NULL )
{
if ( ! F_112 ( V_34 , V_133 , V_135 ) )
goto V_148;
}
#ifndef V_172
#if 1
if ( ! V_113 )
{
F_113 ( V_34 , V_184 ) ;
#ifndef F_11
if ( V_31 )
F_113 ( V_31 , V_184 ) ;
#endif
}
#else
if ( ! V_113 && F_114 ( V_34 ) )
{
T_22 * V_185 ;
F_5 ( V_14 , L_187 ) ;
F_105 ( V_14 ) ;
V_185 = F_115 ( 512 , V_186 , NULL ) ;
if ( ! F_116 ( V_34 , V_185 ) )
{
F_62 ( V_15 ) ;
goto V_148;
}
#ifndef F_11
if ( V_31 )
{
if ( ! F_116 ( V_31 , V_185 ) )
{
F_62 ( V_15 ) ;
goto V_148;
}
}
#endif
F_117 ( V_185 ) ;
F_5 ( V_14 , L_12 ) ;
}
#endif
#endif
#ifndef F_16
#ifdef F_17
if ( V_18 != NULL )
#else
if ( V_18 != NULL || V_171 )
#endif
{
if ( V_13 )
F_5 ( V_14 , L_188 ) ;
F_118 ( V_34 , F_4 ) ;
}
if ( ! F_119 ( V_34 , V_141 ) )
{
F_5 ( V_15 , L_189 ) ;
F_62 ( V_15 ) ;
goto V_148;
}
#endif
if ( V_20 != NULL )
{
if( ! F_120 ( V_34 , V_20 ) )
{
F_5 ( V_15 , L_190 ) ;
F_62 ( V_15 ) ;
goto V_148;
}
#ifndef F_11
if ( V_31 && ! F_120 ( V_31 , V_20 ) )
{
F_5 ( V_15 , L_190 ) ;
F_62 ( V_15 ) ;
goto V_148;
}
#endif
}
F_121 ( V_34 , V_21 , V_187 ) ;
F_122 ( V_34 , ( void * ) & V_188 ,
sizeof V_188 ) ;
F_123 ( V_34 , V_189 ) ;
F_124 ( V_34 , V_190 ) ;
#ifndef F_11
if ( V_31 )
{
F_121 ( V_31 , V_21 , V_187 ) ;
F_122 ( V_31 , ( void * ) & V_188 ,
sizeof V_188 ) ;
V_139 . V_71 = V_14 ;
F_125 ( V_31 , F_34 ) ;
F_126 ( V_31 , & V_139 ) ;
F_125 ( V_34 , F_34 ) ;
F_126 ( V_34 , & V_139 ) ;
}
#endif
if ( V_106 != NULL )
{
F_127 ( V_34 , F_128 ( V_106 ) ) ;
#ifndef F_11
if ( V_31 )
F_127 ( V_31 , F_128 ( V_106 ) ) ;
#endif
}
F_5 ( V_14 , L_191 ) ;
( void ) F_105 ( V_14 ) ;
if ( V_35 )
F_129 ( V_78 , V_119 , & V_19 , V_191 , V_107 ) ;
else
F_129 ( V_78 , V_119 , & V_19 , V_192 , V_107 ) ;
F_130 ( V_14 , V_34 ) ;
V_11 = 0 ;
V_148:
if ( V_34 != NULL ) F_131 ( V_34 ) ;
if ( V_132 )
F_52 ( V_132 ) ;
if ( V_133 )
F_52 ( V_133 ) ;
if ( V_134 )
F_132 ( V_134 ) ;
if ( V_135 )
F_132 ( V_135 ) ;
if ( V_127 )
F_23 ( V_127 ) ;
if ( V_129 )
F_23 ( V_129 ) ;
#ifndef F_11
if ( V_31 != NULL ) F_131 ( V_31 ) ;
if ( V_138 )
F_52 ( V_138 ) ;
if ( V_137 )
F_132 ( V_137 ) ;
#endif
if ( V_14 != NULL )
{
F_133 ( V_14 ) ;
V_14 = NULL ;
}
F_134 () ;
F_135 ( V_11 ) ;
}
static void F_130 ( T_5 * V_193 , T_23 * V_194 )
{
F_5 ( V_193 , L_192 ,
F_136 ( V_194 ) ) ;
F_5 ( V_193 , L_193 ,
F_137 ( V_194 ) ) ;
F_5 ( V_193 , L_194 ,
F_138 ( V_194 ) ) ;
F_5 ( V_193 , L_195 ,
F_139 ( V_194 ) ) ;
F_5 ( V_193 , L_196 ,
F_140 ( V_194 ) ) ;
F_5 ( V_193 , L_197 ,
F_141 ( V_194 ) ) ;
F_5 ( V_193 , L_198 ,
F_142 ( V_194 ) ) ;
F_5 ( V_193 , L_199 , F_143 ( V_194 ) ) ;
F_5 ( V_193 , L_200 , F_144 ( V_194 ) ) ;
F_5 ( V_193 , L_201 , F_145 ( V_194 ) ) ;
F_5 ( V_193 , L_202 , F_146 ( V_194 ) ) ;
F_5 ( V_193 , L_203 ,
F_147 ( V_194 ) ,
F_148 ( V_194 ) ) ;
}
static int V_192 ( char * V_195 , int V_66 , unsigned char * V_107 )
{
char * V_62 = NULL ;
T_24 V_196 ;
int V_11 = 1 , V_197 ;
int V_198 , V_64 ;
unsigned long V_199 ;
T_2 * V_200 = NULL ;
T_5 * V_201 ;
struct V_202 V_99 ;
#if F_67 ( V_203 ) || F_67 ( V_204 ) || F_67 ( V_205 ) || F_67 ( V_206 )
struct V_202 V_207 ;
#else
struct V_202 * V_208 ;
#endif
if ( ( V_62 = F_21 ( V_209 ) ) == NULL )
{
F_5 ( V_15 , L_204 ) ;
goto V_76;
}
#ifdef F_12
if ( V_32 )
{
unsigned long V_210 = 1 ;
if ( ! V_37 )
F_5 ( V_15 , L_205 ) ;
if ( F_149 ( V_66 , F_12 , & V_210 ) < 0 )
F_62 ( V_15 ) ;
}
#endif
if ( V_200 == NULL ) {
V_200 = F_150 ( V_34 ) ;
#ifndef F_11
if ( V_157 )
{
F_151 ( V_200 , V_211 ) ;
F_152 ( V_200 , V_14 ) ;
}
if ( V_158 )
{
F_153 ( V_34 , F_37 ) ;
V_159 . V_76 = V_15 ;
F_154 ( V_34 , & V_159 ) ;
}
#endif
#ifndef F_155
if ( ( V_200 -> V_212 = F_156 () ) != NULL )
{
F_157 ( V_200 -> V_212 , V_213 ,
V_214 ) ;
F_157 ( V_200 -> V_212 , V_215 ,
V_216 ) ;
}
#endif
if( V_107 )
F_158 ( V_200 , V_107 ,
strlen ( ( char * ) V_107 ) ) ;
}
F_159 ( V_200 ) ;
#if 0
#ifdef F_160
SSL_set_tlsext_opaque_prf_input(con, "Test server", 11);
#endif
#endif
if ( F_161 ( V_200 ) == V_217 )
{
V_201 = F_162 ( V_66 , V_147 ) ;
if ( V_167 )
{
V_99 . V_218 = 0 ;
V_99 . V_219 = V_220 ;
F_31 ( V_201 , V_221 , 0 , & V_99 ) ;
V_99 . V_218 = 0 ;
V_99 . V_219 = V_222 ;
F_31 ( V_201 , V_223 , 0 , & V_99 ) ;
}
if ( V_168 > 28 )
{
F_163 ( V_200 , V_224 ) ;
F_164 ( V_200 , V_168 - 28 ) ;
}
else
F_31 ( V_201 , V_225 , 0 , NULL ) ;
F_163 ( V_200 , V_226 ) ;
}
else
V_201 = F_165 ( V_66 , V_147 ) ;
if ( V_33 )
{
T_5 * V_227 ;
V_227 = F_91 ( F_166 () ) ;
V_201 = F_167 ( V_227 , V_201 ) ;
}
#ifndef F_17
if( V_171 )
F_168 ( V_14 , V_201 , V_171 ) ;
#endif
F_169 ( V_200 , V_201 , V_201 ) ;
F_170 ( V_200 ) ;
if ( V_13 )
{
V_200 -> V_228 = 1 ;
F_171 ( F_172 ( V_200 ) , V_229 ) ;
F_173 ( F_172 ( V_200 ) , ( char * ) V_14 ) ;
}
if ( V_36 )
{
F_174 ( V_200 , V_230 ) ;
F_175 ( V_200 , V_14 ) ;
}
#ifndef F_11
if ( V_157 )
{
F_151 ( V_200 , V_211 ) ;
F_152 ( V_200 , V_14 ) ;
}
#endif
V_197 = V_66 + 1 ;
for (; ; )
{
int V_231 ;
int V_232 ;
V_231 = 0 ;
V_232 = F_176 ( V_200 ) ;
if ( ! V_232 )
{
F_177 ( & V_196 ) ;
#if ! F_67 ( V_203 ) && ! F_67 ( V_204 ) && ! F_67 ( V_205 ) && ! F_67 ( V_206 )
F_178 ( fileno ( V_233 ) , & V_196 ) ;
#endif
F_178 ( V_66 , & V_196 ) ;
#if F_67 ( V_203 ) || F_67 ( V_204 ) || F_67 ( V_205 )
V_207 . V_218 = 1 ;
V_207 . V_219 = 0 ;
V_64 = F_179 ( V_197 , ( void * ) & V_196 , NULL , NULL , & V_207 ) ;
if( ( V_64 < 0 ) || ( ! V_64 && ! F_180 () ) ) continue;
if( F_180 () )
V_231 = 1 ;
#elif F_67 ( V_206 )
V_207 . V_218 = 1 ;
V_207 . V_219 = 0 ;
( void ) F_181 ( fileno ( V_233 ) , V_234 , V_235 ) ;
V_64 = F_179 ( V_197 , ( void * ) & V_196 , NULL , NULL , & V_207 ) ;
if ( ( V_64 < 0 ) || ( ! V_64 && F_182 ( fileno ( V_233 ) , V_62 , 0 ) < 0 ) )
continue;
if ( F_182 ( fileno ( V_233 ) , V_62 , 0 ) >= 0 )
V_231 = 1 ;
( void ) F_181 ( fileno ( V_233 ) , V_234 , 0 ) ;
#else
if ( ( F_161 ( V_200 ) == V_217 ) &&
F_183 ( V_200 , & V_99 ) )
V_208 = & V_99 ;
else
V_208 = NULL ;
V_64 = F_179 ( V_197 , ( void * ) & V_196 , NULL , NULL , V_208 ) ;
if ( ( F_161 ( V_200 ) == V_217 ) && F_184 ( V_200 ) > 0 )
{
F_5 ( V_15 , L_206 ) ;
}
if ( V_64 <= 0 ) continue;
if ( F_185 ( fileno ( V_233 ) , & V_196 ) )
V_231 = 1 ;
#endif
if ( F_185 ( V_66 , & V_196 ) )
V_232 = 1 ;
}
if ( V_231 )
{
if ( V_160 )
{
int V_236 , V_237 ;
V_64 = F_186 ( V_62 , V_209 / 2 ) ;
V_237 = 0 ;
for ( V_236 = 0 ; V_236 < V_64 ; V_236 ++ )
if ( V_62 [ V_236 ] == '\n' )
V_237 ++ ;
for ( V_236 = V_64 - 1 ; V_236 >= 0 ; V_236 -- )
{
V_62 [ V_236 + V_237 ] = V_62 [ V_236 ] ;
if ( V_62 [ V_236 ] == '\n' )
{
V_237 -- ;
V_64 ++ ;
V_62 [ V_236 + V_237 ] = '\r' ;
}
}
assert ( V_237 == 0 ) ;
}
else
V_64 = F_186 ( V_62 , V_209 ) ;
if ( ! V_37 )
{
if ( ( V_64 <= 0 ) || ( V_62 [ 0 ] == 'Q' ) )
{
F_5 ( V_14 , L_207 ) ;
F_187 ( V_66 ) ;
F_188 () ;
V_11 = - 11 ;
goto V_76;
}
if ( ( V_64 <= 0 ) || ( V_62 [ 0 ] == 'q' ) )
{
F_5 ( V_14 , L_207 ) ;
if ( F_161 ( V_200 ) != V_217 )
F_187 ( V_66 ) ;
goto V_76;
}
if ( ( V_62 [ 0 ] == 'r' ) &&
( ( V_62 [ 1 ] == '\n' ) || ( V_62 [ 1 ] == '\r' ) ) )
{
F_189 ( V_200 ) ;
V_64 = F_190 ( V_200 ) ;
printf ( L_208 , V_64 ) ;
V_64 = 0 ;
continue;
}
if ( ( V_62 [ 0 ] == 'R' ) &&
( ( V_62 [ 1 ] == '\n' ) || ( V_62 [ 1 ] == '\r' ) ) )
{
F_191 ( V_200 ,
V_151 | V_152 , NULL ) ;
F_189 ( V_200 ) ;
V_64 = F_190 ( V_200 ) ;
printf ( L_208 , V_64 ) ;
V_64 = 0 ;
continue;
}
if ( V_62 [ 0 ] == 'P' )
{
static const char * V_65 = L_209 ;
F_29 ( F_192 ( V_200 ) , V_65 , strlen ( V_65 ) ) ;
}
if ( V_62 [ 0 ] == 'S' )
{
F_130 ( V_14 , F_46 ( V_200 ) ) ;
}
}
#ifdef F_193
F_28 ( V_62 , V_62 , V_64 ) ;
#endif
V_199 = V_198 = 0 ;
for (; ; )
{
#ifdef F_194
{ static V_238 = 0 ; if ( ++ V_238 == 100 ) { V_238 = 0 ; F_189 ( V_200 ) ; } }
#endif
V_198 = F_195 ( V_200 , & ( V_62 [ V_199 ] ) , ( unsigned int ) V_64 ) ;
switch ( F_196 ( V_200 , V_198 ) )
{
case V_239 :
break;
case V_240 :
case V_241 :
case V_242 :
F_5 ( V_14 , L_210 ) ;
break;
case V_243 :
case V_244 :
F_5 ( V_14 , L_211 ) ;
F_62 ( V_15 ) ;
V_11 = 1 ;
goto V_76;
case V_245 :
F_5 ( V_14 , L_207 ) ;
V_11 = 1 ;
goto V_76;
}
V_199 += V_198 ;
V_64 -= V_198 ;
if ( V_64 <= 0 ) break;
}
}
if ( V_232 )
{
if ( ! F_197 ( V_200 ) )
{
V_64 = F_198 ( V_200 ) ;
if ( V_64 < 0 )
{
V_11 = 0 ;
goto V_76;
}
else if ( V_64 == 0 )
{
V_11 = 1 ;
goto V_76;
}
}
else
{
V_246:
V_64 = F_199 ( V_200 , ( char * ) V_62 , V_209 ) ;
switch ( F_196 ( V_200 , V_64 ) )
{
case V_239 :
#ifdef F_193
F_26 ( V_62 , V_62 , V_64 ) ;
#endif
F_200 ( V_62 ,
( unsigned int ) V_64 ) ;
if ( F_176 ( V_200 ) ) goto V_246;
break;
case V_240 :
case V_241 :
case V_242 :
F_5 ( V_14 , L_212 ) ;
break;
case V_243 :
case V_244 :
F_5 ( V_14 , L_211 ) ;
F_62 ( V_15 ) ;
V_11 = 1 ;
goto V_76;
case V_245 :
F_5 ( V_14 , L_207 ) ;
V_11 = 1 ;
goto V_76;
}
}
}
}
V_76:
if ( V_200 != NULL )
{
F_5 ( V_14 , L_213 ) ;
#if 1
F_201 ( V_200 , V_247 | V_248 ) ;
#else
F_202 ( V_200 ) ;
#endif
F_203 ( V_200 ) ;
}
F_5 ( V_14 , L_214 ) ;
if ( V_62 != NULL )
{
F_204 ( V_62 , V_209 ) ;
F_23 ( V_62 ) ;
}
if ( V_11 >= 0 )
F_5 ( V_14 , L_191 ) ;
return ( V_11 ) ;
}
static void F_188 ( void )
{
F_5 ( V_15 , L_215 ) ;
if ( V_19 >= 0 )
{
F_205 ( V_19 ) ;
}
}
static int F_198 ( T_2 * V_200 )
{
int V_64 ;
const char * V_65 ;
T_10 * V_249 ;
long V_250 ;
T_25 char V_62 [ V_251 ] ;
if ( ( V_64 = F_206 ( V_200 ) ) <= 0 )
{
if ( F_207 ( V_64 ) )
{
F_5 ( V_14 , L_216 ) ;
return ( 1 ) ;
}
F_5 ( V_15 , L_211 ) ;
V_250 = F_208 ( V_200 ) ;
if ( V_250 != V_252 )
{
F_5 ( V_15 , L_217 ,
F_209 ( V_250 ) ) ;
}
else
F_62 ( V_15 ) ;
return ( 0 ) ;
}
F_210 ( V_14 , F_211 ( V_200 ) ) ;
V_249 = F_212 ( V_200 ) ;
if ( V_249 != NULL )
{
F_5 ( V_14 , L_218 ) ;
F_213 ( V_14 , V_249 ) ;
F_214 ( F_215 ( V_249 ) , V_62 , sizeof V_62 ) ;
F_5 ( V_14 , L_219 , V_62 ) ;
F_214 ( F_48 ( V_249 ) , V_62 , sizeof V_62 ) ;
F_5 ( V_14 , L_220 , V_62 ) ;
F_52 ( V_249 ) ;
}
if ( F_216 ( V_200 , V_62 , sizeof V_62 ) != NULL )
F_5 ( V_14 , L_221 , V_62 ) ;
V_65 = F_217 ( F_218 ( V_200 ) ) ;
F_5 ( V_14 , L_222 , ( V_65 != NULL ) ? V_65 : L_223 ) ;
if ( V_200 -> V_253 ) F_5 ( V_14 , L_224 ) ;
if ( F_219 ( V_200 , V_254 , 0 , NULL ) &
V_255 )
F_5 ( V_14 , L_225 ) ;
#ifndef F_155
if ( V_200 -> V_212 -> V_256 != NULL )
{
F_5 ( V_14 , L_226 ,
V_200 -> V_212 -> V_256 ) ;
}
#endif
F_5 ( V_14 , L_227 ,
F_220 ( V_200 ) ? L_228 : L_229 ) ;
return ( 1 ) ;
}
static T_1 * F_104 ( const char * V_108 )
{
T_1 * V_11 = NULL ;
T_5 * V_193 ;
if ( ( V_193 = F_221 ( V_108 , L_230 ) ) == NULL )
goto V_76;
V_11 = F_222 ( V_193 , NULL , NULL , NULL ) ;
V_76:
if ( V_193 != NULL ) F_133 ( V_193 ) ;
return ( V_11 ) ;
}
static int V_191 ( char * V_195 , int V_66 , unsigned char * V_107 )
{
char * V_62 = NULL ;
int V_11 = 1 ;
int V_64 , V_236 , V_198 , V_257 , V_258 ;
T_2 * V_200 ;
const T_26 * V_259 ;
T_5 * V_260 , * V_261 , * V_201 ;
long V_262 ;
V_62 = F_21 ( V_209 ) ;
if ( V_62 == NULL ) return ( 0 ) ;
V_260 = F_91 ( F_223 () ) ;
V_261 = F_91 ( F_224 () ) ;
if ( ( V_260 == NULL ) || ( V_261 == NULL ) ) goto V_76;
#ifdef F_12
if ( V_32 )
{
unsigned long V_210 = 1 ;
if ( ! V_37 )
F_5 ( V_15 , L_205 ) ;
if ( F_149 ( V_66 , F_12 , & V_210 ) < 0 )
F_62 ( V_15 ) ;
}
#endif
if ( ! F_225 ( V_260 , V_209 ) ) goto V_76;
if ( ( V_200 = F_150 ( V_34 ) ) == NULL ) goto V_76;
#ifndef F_11
if ( V_157 )
{
F_151 ( V_200 , V_211 ) ;
F_152 ( V_200 , V_14 ) ;
}
#endif
#ifndef F_155
if ( ( V_200 -> V_212 = F_156 () ) != NULL )
{
F_157 ( V_200 -> V_212 , V_213 , V_214 ) ;
F_157 ( V_200 -> V_212 , V_215 , V_216 ) ;
}
#endif
if( V_107 ) F_158 ( V_200 , V_107 ,
strlen ( ( char * ) V_107 ) ) ;
V_201 = F_165 ( V_66 , V_147 ) ;
if ( V_33 )
{
T_5 * V_227 ;
V_227 = F_91 ( F_166 () ) ;
V_201 = F_167 ( V_227 , V_201 ) ;
}
F_169 ( V_200 , V_201 , V_201 ) ;
F_170 ( V_200 ) ;
F_226 ( V_261 , V_200 , V_263 ) ;
F_167 ( V_260 , V_261 ) ;
#ifdef F_193
V_260 = F_167 ( F_91 ( F_19 () ) , V_260 ) ;
#endif
if ( V_13 )
{
V_200 -> V_228 = 1 ;
F_171 ( F_172 ( V_200 ) , V_229 ) ;
F_173 ( F_172 ( V_200 ) , ( char * ) V_14 ) ;
}
if ( V_36 )
{
F_174 ( V_200 , V_230 ) ;
F_175 ( V_200 , V_14 ) ;
}
V_257 = 0 ;
for (; ; )
{
if ( V_38 )
{
V_64 = F_206 ( V_200 ) ;
switch ( F_196 ( V_200 , V_64 ) )
{
case V_239 :
break;
case V_240 :
case V_241 :
case V_242 :
continue;
case V_243 :
case V_244 :
case V_245 :
V_11 = 1 ;
goto V_76;
}
F_189 ( V_200 ) ;
F_195 ( V_200 , NULL , 0 ) ;
}
V_64 = F_227 ( V_260 , V_62 , V_209 - 1 ) ;
if ( V_64 < 0 )
{
if ( ! F_228 ( V_260 ) )
{
if ( ! V_37 )
F_62 ( V_15 ) ;
goto V_76;
}
else
{
F_5 ( V_14 , L_231 ) ;
#if F_67 ( V_205 )
F_229 ( 1000 ) ;
#elif ! F_67 ( V_204 ) && ! F_67 ( V_264 )
F_230 ( 1 ) ;
#endif
continue;
}
}
else if ( V_64 == 0 )
{
V_11 = 1 ;
goto V_148;
}
if ( ( ( V_35 == 1 ) && ( strncmp ( L_232 , V_62 , 4 ) == 0 ) ) ||
( ( V_35 == 2 ) && ( strncmp ( L_233 , V_62 , 10 ) == 0 ) ) )
{
char * V_2 ;
T_10 * V_249 ;
F_38 ( T_26 ) * V_265 ;
static const char * V_266 = L_234 ;
F_39 ( V_260 , L_235 ) ;
F_39 ( V_260 , L_236 ) ;
F_39 ( V_260 , L_237 ) ;
F_39 ( V_260 , L_12 ) ;
for ( V_64 = 0 ; V_64 < V_144 ; V_64 ++ )
{
F_39 ( V_260 , V_145 [ V_64 ] ) ;
F_29 ( V_260 , L_238 , 1 ) ;
}
F_39 ( V_260 , L_12 ) ;
F_5 ( V_260 , L_239 ) ;
V_265 = F_231 ( V_200 ) ;
V_236 = F_232 ( V_265 ) ;
for ( V_64 = 0 ; V_64 < V_236 ; V_64 ++ )
{
V_259 = F_233 ( V_265 , V_64 ) ;
F_5 ( V_260 , L_240 ,
F_234 ( V_259 ) ,
F_217 ( V_259 ) ) ;
if ( ( ( ( V_64 + 1 ) % 2 ) == 0 ) && ( V_64 + 1 != V_236 ) )
F_39 ( V_260 , L_12 ) ;
}
F_39 ( V_260 , L_12 ) ;
V_2 = F_216 ( V_200 , V_62 , V_209 ) ;
if ( V_2 != NULL )
{
F_5 ( V_260 , L_241 ) ;
V_236 = V_64 = 0 ;
while ( * V_2 )
{
if ( * V_2 == ':' )
{
F_29 ( V_260 , V_266 , 26 - V_236 ) ;
V_64 ++ ;
V_236 = 0 ;
F_29 ( V_260 , ( ( V_64 % 3 ) ? L_238 : L_12 ) , 1 ) ;
}
else
{
F_29 ( V_260 , V_2 , 1 ) ;
V_236 ++ ;
}
V_2 ++ ;
}
F_39 ( V_260 , L_12 ) ;
}
F_5 ( V_260 , ( ( V_200 -> V_253 )
? L_242
: L_243 ) ) ;
V_259 = F_218 ( V_200 ) ;
F_5 ( V_260 , L_244 ,
F_234 ( V_259 ) ,
F_217 ( V_259 ) ) ;
F_235 ( V_260 , F_211 ( V_200 ) ) ;
F_5 ( V_260 , L_245 ) ;
F_130 ( V_260 , F_46 ( V_200 ) ) ;
F_5 ( V_260 , L_245 ) ;
V_249 = F_212 ( V_200 ) ;
if ( V_249 != NULL )
{
F_5 ( V_260 , L_218 ) ;
F_236 ( V_260 , V_249 ) ;
F_213 ( V_260 , V_249 ) ;
}
else
F_39 ( V_260 , L_246 ) ;
F_39 ( V_260 , L_247 ) ;
break;
}
else if ( ( V_35 == 2 || V_35 == 3 )
&& ( strncmp ( L_248 , V_62 , 5 ) == 0 ) )
{
T_5 * V_267 ;
char * V_2 , * V_121 ;
static const char * V_268 = L_249 ;
V_2 = & ( V_62 [ 5 ] ) ;
V_258 = 1 ;
for ( V_121 = V_2 ; * V_121 != '\0' ; V_121 ++ )
{
if ( V_121 [ 0 ] == ' ' )
break;
switch ( V_258 )
{
case 1 :
V_258 = ( V_121 [ 0 ] == '.' ) ? 2 : 0 ;
break;
case 2 :
V_258 = ( V_121 [ 0 ] == '.' ) ? 3 : 0 ;
break;
case 3 :
V_258 = ( V_121 [ 0 ] == '/' ) ? - 1 : 0 ;
break;
}
if ( V_258 == 0 )
V_258 = ( V_121 [ 0 ] == '/' ) ? 1 : 0 ;
}
V_258 = ( V_258 == 3 ) || ( V_258 == - 1 ) ;
if ( * V_121 == '\0' )
{
F_39 ( V_260 , V_268 ) ;
F_5 ( V_260 , L_250 , V_2 ) ;
break;
}
* V_121 = '\0' ;
if ( V_258 )
{
F_39 ( V_260 , V_268 ) ;
F_5 ( V_260 , L_251 , V_2 ) ;
break;
}
if ( * V_2 == '/' )
{
F_39 ( V_260 , V_268 ) ;
F_5 ( V_260 , L_252 , V_2 ) ;
break;
}
#if 0
if (e[-1] == '/')
strcat(p,"index.html");
#endif
if ( F_237 ( V_2 ) > 0 )
{
#if 0
strcat(p,"/index.html");
#else
F_39 ( V_260 , V_268 ) ;
F_5 ( V_260 , L_253 , V_2 ) ;
break;
#endif
}
if ( ( V_267 = F_221 ( V_2 , L_230 ) ) == NULL )
{
F_39 ( V_260 , V_268 ) ;
F_5 ( V_260 , L_254 , V_2 ) ;
F_62 ( V_260 ) ;
break;
}
if ( ! V_37 )
F_5 ( V_15 , L_255 , V_2 ) ;
if ( V_35 == 2 )
{
V_64 = strlen ( V_2 ) ;
if ( ( ( V_64 > 5 ) && ( strcmp ( & ( V_2 [ V_64 - 5 ] ) , L_256 ) == 0 ) ) ||
( ( V_64 > 4 ) && ( strcmp ( & ( V_2 [ V_64 - 4 ] ) , L_257 ) == 0 ) ) ||
( ( V_64 > 4 ) && ( strcmp ( & ( V_2 [ V_64 - 4 ] ) , L_258 ) == 0 ) ) )
F_39 ( V_260 , L_235 ) ;
else
F_39 ( V_260 , L_249 ) ;
}
V_262 = 0 ;
for (; ; )
{
V_64 = F_25 ( V_267 , V_62 , V_209 ) ;
if ( V_64 <= 0 ) break;
#ifdef F_194
V_262 += V_64 ;
fprintf ( V_146 , L_259 , V_64 ) ;
if ( V_262 > 3 * 1024 )
{
V_262 = 0 ;
fprintf ( V_146 , L_260 ) ;
F_189 ( V_200 ) ;
}
#endif
for ( V_236 = 0 ; V_236 < V_64 ; )
{
#ifdef F_194
{ static V_238 = 0 ; if ( ++ V_238 == 13 ) { F_189 ( V_200 ) ; } }
#endif
V_198 = F_29 ( V_260 , & ( V_62 [ V_236 ] ) , V_64 - V_236 ) ;
if ( V_198 <= 0 )
{
if ( ! F_228 ( V_260 ) )
goto V_269;
else
{
F_5 ( V_14 , L_261 ) ;
}
}
else
{
V_236 += V_198 ;
}
}
}
V_269:
F_133 ( V_267 ) ;
break;
}
}
for (; ; )
{
V_64 = ( int ) F_105 ( V_260 ) ;
if ( V_64 <= 0 )
{
if ( ! F_228 ( V_260 ) )
break;
}
else
break;
}
V_148:
#if 1
F_201 ( V_200 , V_247 | V_248 ) ;
#else
#endif
V_76:
if ( V_11 >= 0 )
F_5 ( V_14 , L_191 ) ;
if ( V_62 != NULL ) F_23 ( V_62 ) ;
if ( V_260 != NULL ) F_238 ( V_260 ) ;
return ( V_11 ) ;
}
static T_22 T_7 * V_184 ( T_2 * V_66 , int V_270 , int V_271 )
{
T_3 * V_12 = NULL ;
static T_22 * V_272 = NULL ;
if ( ! V_272 && ( ( V_12 = F_239 () ) == NULL ) )
F_5 ( V_15 , L_262 ) ;
if ( ! V_272 && V_12 )
{
if ( ! V_37 )
{
F_5 ( V_15 , L_263 , V_271 ) ;
( void ) F_105 ( V_15 ) ;
}
if( ! F_240 ( V_12 , V_186 ) || ( ( V_272 = F_241 () ) == NULL ) ||
! F_242 ( V_272 , V_271 , V_12 , NULL ) )
{
if( V_272 ) F_117 ( V_272 ) ;
V_272 = NULL ;
}
if ( ! V_37 )
{
F_5 ( V_15 , L_12 ) ;
( void ) F_105 ( V_15 ) ;
}
F_7 ( V_12 ) ;
}
return ( V_272 ) ;
}
static int V_175 ( const T_2 * V_6 , unsigned char * V_90 ,
unsigned int * V_273 )
{
unsigned int V_238 = 0 ;
do {
F_243 ( V_90 , * V_273 ) ;
memcpy ( V_90 , V_170 ,
( strlen ( V_170 ) < * V_273 ) ?
strlen ( V_170 ) : * V_273 ) ;
}
while( F_244 ( V_6 , V_90 , * V_273 ) &&
( ++ V_238 < V_274 ) );
if( V_238 >= V_274 )
return 0 ;
return 1 ;
}
