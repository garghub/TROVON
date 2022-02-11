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
static void F_4 ( void )
{
F_5 ( V_6 , L_1 ) ;
F_5 ( V_6 , L_2 ) ;
F_5 ( V_6 , L_3 , V_7 ) ;
F_5 ( V_6 , L_4 ) ;
F_5 ( V_6 , L_5 ) ;
F_5 ( V_6 , L_6 ) ;
F_5 ( V_6 , L_7 ) ;
F_5 ( V_6 , L_8 , V_8 ) ;
F_5 ( V_6 , L_9 ) ;
F_5 ( V_6 , L_10 , V_8 ) ;
F_5 ( V_6 , L_11 ) ;
F_5 ( V_6 , L_12 ) ;
#ifdef F_6
F_5 ( V_6 , L_13 ) ;
#endif
F_5 ( V_6 , L_14 ) ;
#ifdef F_7
F_5 ( V_6 , L_15 ) ;
#endif
F_5 ( V_6 , L_16 ) ;
F_5 ( V_6 , L_17 ) ;
F_5 ( V_6 , L_18 ) ;
F_5 ( V_6 , L_19 ) ;
F_5 ( V_6 , L_20 ) ;
F_5 ( V_6 , L_21 ) ;
F_5 ( V_6 , L_22 ) ;
F_5 ( V_6 , L_23 ) ;
F_5 ( V_6 , L_24 ) ;
F_5 ( V_6 , L_25 ) ;
F_5 ( V_6 , L_26 ) ;
F_5 ( V_6 , L_27 ) ;
F_5 ( V_6 , L_28 ) ;
F_5 ( V_6 , L_29 ) ;
#ifndef F_8
F_5 ( V_6 , L_30 ) ;
#endif
F_5 ( V_6 , L_31 ) ;
F_5 ( V_6 , L_32 ) ;
F_5 ( V_6 , L_33 ) ;
}
T_2 * F_9 ()
{
return ( & V_9 ) ;
}
static int F_10 ( T_3 * V_10 )
{
T_4 * V_11 ;
V_11 = ( T_4 * ) Malloc ( sizeof( T_4 ) + 1024 ) ;
V_11 -> V_12 = 1024 ;
V_11 -> V_13 [ 0 ] = '\0' ;
V_10 -> V_14 = ( char * ) V_11 ;
V_10 -> V_15 = 1 ;
V_10 -> V_16 = 0 ;
return ( 1 ) ;
}
static int F_11 ( T_3 * V_17 )
{
if ( V_17 == NULL ) return ( 0 ) ;
if ( V_17 -> V_14 != NULL )
Free ( V_17 -> V_14 ) ;
V_17 -> V_14 = NULL ;
V_17 -> V_15 = 0 ;
V_17 -> V_16 = 0 ;
return ( 1 ) ;
}
static int F_12 ( T_3 * V_18 , char * V_19 , int V_20 )
{
int V_21 = 0 ;
if ( V_19 == NULL || V_20 == 0 ) return ( 0 ) ;
if ( V_18 -> V_22 == NULL ) return ( 0 ) ;
V_21 = F_13 ( V_18 -> V_22 , V_19 , V_20 ) ;
if ( V_21 > 0 )
F_14 ( V_19 , V_19 , V_21 ) ;
return ( V_21 ) ;
}
static int F_15 ( T_3 * V_18 , char * V_23 , int V_24 )
{
T_4 * V_11 ;
int V_21 = 0 ;
int V_25 ;
unsigned char V_26 ;
if ( ( V_23 == NULL ) || ( V_24 <= 0 ) ) return ( 0 ) ;
if ( V_18 -> V_22 == NULL ) return ( 0 ) ;
V_11 = ( T_4 * ) V_18 -> V_14 ;
if ( V_24 > ( V_25 = V_11 -> V_12 ) )
{
V_25 = V_25 + V_25 ;
if ( V_25 < V_24 )
V_25 = V_24 ;
Free ( ( char * ) V_11 ) ;
V_11 = ( T_4 * ) Malloc ( sizeof( T_4 ) + V_25 ) ;
V_11 -> V_12 = V_25 ;
V_11 -> V_13 [ 0 ] = '\0' ;
V_18 -> V_14 = ( char * ) V_11 ;
}
F_16 ( V_11 -> V_13 , V_23 , V_24 ) ;
V_21 = F_17 ( V_18 -> V_22 , V_11 -> V_13 , V_24 ) ;
return ( V_21 ) ;
}
static long F_18 ( T_3 * V_18 , int V_27 , long V_25 , char * V_14 )
{
long V_21 ;
if ( V_18 -> V_22 == NULL ) return ( 0 ) ;
switch ( V_27 )
{
case V_28 :
V_21 = 0L ;
break;
default:
V_21 = F_19 ( V_18 -> V_22 , V_27 , V_25 , V_14 ) ;
break;
}
return ( V_21 ) ;
}
static int F_20 ( T_3 * V_29 , char * V_30 , int V_31 )
{
int V_32 , V_21 ;
if ( V_29 -> V_22 == NULL ) return ( 0 ) ;
for ( V_32 = 0 ; V_32 < V_31 - 1 ; ++ V_32 )
{
V_21 = F_12 ( V_29 , & V_30 [ V_32 ] , 1 ) ;
if ( V_21 <= 0 )
break;
else if ( V_30 [ V_32 ] == '\n' )
{
++ V_32 ;
break;
}
}
if ( V_32 < V_31 )
V_30 [ V_32 ] = '\0' ;
return ( V_21 < 0 && V_32 == 0 ) ? V_21 : V_32 ;
}
static int F_21 ( T_3 * V_29 , char * V_33 )
{
if ( V_29 -> V_22 == NULL ) return ( 0 ) ;
return F_15 ( V_29 , V_33 , strlen ( V_33 ) ) ;
}
int MAIN ( int V_34 , char * V_35 [] )
{
short V_36 = V_7 ;
char * V_37 = NULL , * V_38 = NULL ;
char * V_39 = NULL ;
int V_40 = 0 , V_41 = 0 ;
int V_21 = 1 ;
int V_42 = 0 ;
int V_43 = 0 , V_44 = 0 , V_45 = 0 ;
int V_46 = 0 ;
T_5 * V_47 = NULL ;
#ifndef F_8
T_1 * V_1 = NULL ;
#endif
#if ! F_22 ( V_48 ) && ! F_22 ( V_49 )
V_47 = F_23 () ;
#elif ! F_22 ( V_49 )
V_47 = F_24 () ;
#elif ! F_22 ( V_48 )
V_47 = F_25 () ;
#endif
V_50 = V_34 ;
V_51 = V_35 ;
F_26 () ;
V_52 = 0 ;
V_53 = 0 ;
if ( V_6 == NULL )
V_6 = F_27 ( V_54 , V_55 ) ;
V_56 = 0 ;
#ifdef F_6
V_57 = 0 ;
#endif
V_58 = 0 ;
V_34 -- ;
V_35 ++ ;
while ( V_34 >= 1 )
{
if ( ( strcmp ( * V_35 , L_34 ) == 0 ) ||
( strcmp ( * V_35 , L_35 ) == 0 ) )
{
if ( -- V_34 < 1 ) goto V_59;
if ( ! F_28 ( * ( ++ V_35 ) , & V_36 ) )
goto V_59;
}
else if ( strcmp ( * V_35 , L_36 ) == 0 )
{
V_60 = V_61 | V_62 ;
if ( -- V_34 < 1 ) goto V_59;
V_56 = atoi ( * ( ++ V_35 ) ) ;
F_5 ( V_6 , L_37 , V_56 ) ;
}
else if ( strcmp ( * V_35 , L_38 ) == 0 )
{
V_60 = V_61 | V_63 |
V_62 ;
if ( -- V_34 < 1 ) goto V_59;
V_56 = atoi ( * ( ++ V_35 ) ) ;
F_5 ( V_6 , L_39 , V_56 ) ;
}
else if ( strcmp ( * V_35 , L_40 ) == 0 )
{
if ( -- V_34 < 1 ) goto V_59;
V_39 = * ( ++ V_35 ) ;
}
else if ( strcmp ( * V_35 , L_41 ) == 0 )
{
if ( -- V_34 < 1 ) goto V_59;
V_64 = * ( ++ V_35 ) ;
}
else if ( strcmp ( * V_35 , L_42 ) == 0 )
{
if ( -- V_34 < 1 ) goto V_59;
V_65 = * ( ++ V_35 ) ;
}
else if ( strcmp ( * V_35 , L_43 ) == 0 )
{
if ( -- V_34 < 1 ) goto V_59;
V_66 = * ( ++ V_35 ) ;
}
else if ( strcmp ( * V_35 , L_44 ) == 0 )
{
if ( -- V_34 < 1 ) goto V_59;
V_67 = * ( ++ V_35 ) ;
}
else if ( strcmp ( * V_35 , L_45 ) == 0 )
{
V_45 = 1 ;
}
else if ( strcmp ( * V_35 , L_46 ) == 0 )
{
if ( -- V_34 < 1 ) goto V_59;
V_37 = * ( ++ V_35 ) ;
}
else if ( strcmp ( * V_35 , L_47 ) == 0 )
{
if ( -- V_34 < 1 ) goto V_59;
V_68 = * ( ++ V_35 ) ;
}
else if ( strcmp ( * V_35 , L_48 ) == 0 )
{
if ( -- V_34 < 1 ) goto V_59;
V_38 = * ( ++ V_35 ) ;
}
#ifdef F_6
else if ( strcmp ( * V_35 , L_49 ) == 0 )
{ V_57 = 1 ; }
#endif
else if ( strcmp ( * V_35 , L_50 ) == 0 )
{
#ifdef F_6
V_57 = 1 ;
#endif
V_58 = 1 ;
}
else if ( strcmp ( * V_35 , L_51 ) == 0 )
{ V_53 = 1 ; }
else if ( strcmp ( * V_35 , L_52 ) == 0 )
{ V_69 = 1 ; }
else if ( strcmp ( * V_35 , L_53 ) == 0 )
{ V_46 = 1 ; }
#ifdef F_7
else if ( strcmp ( * V_35 , L_54 ) == 0 )
{ V_70 = 1 ; }
#endif
else if ( strcmp ( * V_35 , L_55 ) == 0 )
{ V_52 = 1 ; }
else if ( strcmp ( * V_35 , L_56 ) == 0 )
{ V_41 = 1 ; }
else if ( strcmp ( * V_35 , L_57 ) == 0 )
{ V_43 = 1 ; }
else if ( strcmp ( * V_35 , L_58 ) == 0 )
{ V_44 = 1 ; }
else if ( strcmp ( * V_35 , L_59 ) == 0 )
{ V_71 = 1 ; }
else if ( strcmp ( * V_35 , L_60 ) == 0 )
{ V_71 = 2 ; }
else if ( strcmp ( * V_35 , L_61 ) == 0 )
{ V_42 |= V_72 ; }
else if ( strcmp ( * V_35 , L_62 ) == 0 )
{ V_42 |= V_73 ; }
else if ( strcmp ( * V_35 , L_63 ) == 0 )
{ V_42 |= V_74 ; }
#ifndef V_48
else if ( strcmp ( * V_35 , L_64 ) == 0 )
{ V_47 = F_25 () ; }
#endif
#ifndef V_49
else if ( strcmp ( * V_35 , L_65 ) == 0 )
{ V_47 = F_24 () ; }
#endif
#ifndef F_29
else if ( strcmp ( * V_35 , L_66 ) == 0 )
{ V_47 = F_30 () ; }
#endif
else
{
F_5 ( V_6 , L_67 , * V_35 ) ;
V_40 = 1 ;
break;
}
V_34 -- ;
V_35 ++ ;
}
if ( V_40 )
{
V_59:
F_4 () ;
goto V_75;
}
if ( V_76 == NULL )
{
if ( V_52 && ! V_53 )
{
V_76 = F_31 ( F_32 () ) ;
}
else
{
if ( V_76 == NULL )
V_76 = F_27 ( stdout , V_55 ) ;
}
}
#if ! F_22 ( V_77 ) || ! F_22 ( V_78 )
if ( V_45 )
#endif
{
V_64 = NULL ;
V_65 = NULL ;
V_66 = NULL ;
V_67 = NULL ;
}
F_33 () ;
F_34 () ;
V_79 = F_35 ( V_47 ) ;
if ( V_79 == NULL )
{
F_36 ( V_6 ) ;
goto V_75;
}
F_37 ( V_79 , 1 ) ;
if ( V_41 ) F_38 ( V_79 , V_80 ) ;
if ( V_69 ) F_38 ( V_79 , V_81 ) ;
F_38 ( V_79 , V_42 ) ;
if ( V_69 ) F_38 ( V_79 , V_82 ) ;
if ( V_46 ) F_39 ( V_79 , V_83 ) ;
F_40 ( V_79 , 128 ) ;
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
if ( ( ! F_41 ( V_79 , V_38 , V_37 ) ) ||
( ! F_42 ( V_79 ) ) )
{
F_36 ( V_6 ) ;
}
#ifndef F_8
if ( ! V_44 )
{
V_1 = F_43 () ;
if ( V_1 != NULL )
{
F_5 ( V_76 , L_68 ) ;
}
else
{
F_5 ( V_76 , L_69 ) ;
V_1 = F_1 () ;
}
( void ) F_44 ( V_76 ) ;
F_45 ( V_79 , V_1 ) ;
F_46 ( V_1 ) ;
}
#endif
if ( ! F_47 ( V_79 , V_64 , V_65 ) )
goto V_75;
if ( V_66 != NULL )
{
if ( ! F_47 ( V_79 , V_66 , V_67 ) )
goto V_75;
}
#ifndef V_77
#if 1
F_48 ( V_79 , V_84 ) ;
#else
if ( ! V_43 && F_49 ( V_79 ) )
{
T_6 * V_85 ;
F_5 ( V_76 , L_70 ) ;
F_44 ( V_76 ) ;
V_85 = F_50 ( 512 , V_86 , NULL ) ;
if ( ! F_51 ( V_79 , V_85 ) )
{
F_36 ( V_6 ) ;
goto V_75;
}
F_52 ( V_85 ) ;
F_5 ( V_76 , L_2 ) ;
}
#endif
#endif
if ( V_68 != NULL )
F_53 ( V_79 , V_68 ) ;
F_54 ( V_79 , V_60 , V_87 ) ;
F_55 ( V_79 , ( void * ) & V_88 ,
sizeof V_88 ) ;
F_56 ( V_79 , F_57 ( V_38 ) ) ;
F_5 ( V_76 , L_71 ) ;
if ( V_71 )
F_58 ( V_36 , & V_89 , V_90 , V_39 ) ;
else
F_58 ( V_36 , & V_89 , V_91 , V_39 ) ;
F_59 ( V_76 , V_79 ) ;
V_21 = 0 ;
V_75:
if ( V_79 != NULL ) F_60 ( V_79 ) ;
if ( V_76 != NULL )
{
F_61 ( V_76 ) ;
V_76 = NULL ;
}
EXIT ( V_21 ) ;
}
static void F_59 ( T_3 * V_92 , T_7 * V_93 )
{
F_5 ( V_92 , L_72 ,
F_62 ( V_93 ) ) ;
F_5 ( V_92 , L_73 ,
F_63 ( V_93 ) ) ;
F_5 ( V_92 , L_74 ,
F_64 ( V_93 ) ) ;
F_5 ( V_92 , L_75 ,
F_65 ( V_93 ) ) ;
F_5 ( V_92 , L_76 ,
F_66 ( V_93 ) ) ;
F_5 ( V_92 , L_77 ,
F_67 ( V_93 ) ) ;
F_5 ( V_92 , L_78 ,
F_68 ( V_93 ) ) ;
F_5 ( V_92 , L_79 , F_69 ( V_93 ) ) ;
F_5 ( V_92 , L_80 , F_70 ( V_93 ) ) ;
F_5 ( V_92 , L_81 , F_71 ( V_93 ) ) ;
F_5 ( V_92 , L_82 , F_72 ( V_93 ) ) ;
F_5 ( V_92 , L_83 ,
F_73 ( V_93 ) ,
F_74 ( V_93 ) ) ;
}
static int V_91 ( char * V_94 , int V_95 , unsigned char * V_39 )
{
char * V_30 = NULL ;
T_8 V_96 ;
int V_21 = 1 , V_97 ;
int V_98 , V_32 ;
unsigned long V_99 ;
T_9 * V_100 = NULL ;
T_3 * V_101 ;
if ( ( V_30 = Malloc ( V_102 ) ) == NULL )
{
F_5 ( V_6 , L_84 ) ;
goto V_103;
}
#ifdef F_6
if ( V_57 )
{
unsigned long V_104 = 1 ;
if ( ! V_52 )
F_5 ( V_6 , L_85 ) ;
if ( F_75 ( V_95 , F_6 , & V_104 ) < 0 )
F_36 ( V_6 ) ;
}
#endif
if ( V_100 == NULL ) {
V_100 = ( T_9 * ) F_76 ( V_79 ) ;
if( V_39 )
F_77 ( V_100 , V_39 ,
strlen ( ( char * ) V_39 ) ) ;
}
F_78 ( V_100 ) ;
V_101 = F_79 ( V_95 , V_55 ) ;
if ( V_58 )
{
T_3 * V_105 ;
V_105 = F_31 ( F_80 () ) ;
V_101 = F_81 ( V_105 , V_101 ) ;
}
F_82 ( V_100 , V_101 , V_101 ) ;
F_83 ( V_100 ) ;
if ( V_53 )
{
V_100 -> V_106 = 1 ;
F_84 ( F_85 ( V_100 ) , V_107 ) ;
F_86 ( F_85 ( V_100 ) , V_76 ) ;
}
V_97 = V_95 + 1 ;
for (; ; )
{
F_87 ( & V_96 ) ;
#ifndef F_88
F_89 ( fileno ( V_108 ) , & V_96 ) ;
#endif
F_89 ( V_95 , & V_96 ) ;
V_32 = F_90 ( V_97 , ( void * ) & V_96 , NULL , NULL , NULL ) ;
if ( V_32 <= 0 ) continue;
if ( F_91 ( fileno ( V_108 ) , & V_96 ) )
{
#ifdef F_7
if ( V_70 )
{
int V_109 , V_110 ;
V_32 = F_92 ( fileno ( V_108 ) , V_30 , V_102 / 2 ) ;
V_110 = 0 ;
for ( V_109 = 0 ; V_109 < V_32 ; V_109 ++ )
if ( V_30 [ V_109 ] == '\n' )
V_110 ++ ;
for ( V_109 = V_32 - 1 ; V_109 >= 0 ; V_109 -- )
{
V_30 [ V_109 + V_110 ] = V_30 [ V_109 ] ;
if ( V_30 [ V_109 ] == '\n' )
{
V_110 -- ;
V_32 ++ ;
V_30 [ V_109 + V_110 ] = '\r' ;
}
}
assert ( V_110 == 0 ) ;
}
else
#endif
V_32 = F_92 ( fileno ( V_108 ) , V_30 , V_102 ) ;
if ( ! V_52 )
{
if ( ( V_32 <= 0 ) || ( V_30 [ 0 ] == 'Q' ) )
{
F_5 ( V_76 , L_86 ) ;
F_93 ( V_95 ) ;
F_94 () ;
V_21 = - 11 ;
goto V_103;
}
if ( ( V_32 <= 0 ) || ( V_30 [ 0 ] == 'q' ) )
{
F_5 ( V_76 , L_86 ) ;
F_93 ( V_95 ) ;
goto V_103;
}
if ( ( V_30 [ 0 ] == 'r' ) &&
( ( V_30 [ 1 ] == '\n' ) || ( V_30 [ 1 ] == '\r' ) ) )
{
F_95 ( V_100 ) ;
V_32 = F_96 ( V_100 ) ;
printf ( L_87 , V_32 ) ;
V_32 = 0 ;
continue;
}
if ( ( V_30 [ 0 ] == 'R' ) &&
( ( V_30 [ 1 ] == '\n' ) || ( V_30 [ 1 ] == '\r' ) ) )
{
F_97 ( V_100 ,
V_61 | V_62 , NULL ) ;
F_95 ( V_100 ) ;
V_32 = F_96 ( V_100 ) ;
printf ( L_87 , V_32 ) ;
V_32 = 0 ;
continue;
}
if ( V_30 [ 0 ] == 'P' )
{
static char * V_33 = L_88 ;
F_17 ( F_98 ( V_100 ) , V_33 , strlen ( V_33 ) ) ;
}
if ( V_30 [ 0 ] == 'S' )
{
F_59 ( V_76 , F_99 ( V_100 ) ) ;
}
}
#ifdef F_100
F_16 ( V_30 , V_30 , V_32 ) ;
#endif
V_99 = V_98 = 0 ;
for (; ; )
{
#ifdef F_101
{ static V_111 = 0 ; if ( ++ V_111 == 100 ) { V_111 = 0 ; F_95 ( V_100 ) ; } }
#endif
V_98 = F_102 ( V_100 , & ( V_30 [ V_99 ] ) , ( unsigned int ) V_32 ) ;
switch ( F_103 ( V_100 , V_98 ) )
{
case V_112 :
break;
case V_113 :
case V_114 :
case V_115 :
F_5 ( V_76 , L_89 ) ;
break;
case V_116 :
case V_117 :
F_5 ( V_76 , L_90 ) ;
F_36 ( V_6 ) ;
V_21 = 1 ;
goto V_103;
case V_118 :
F_5 ( V_76 , L_86 ) ;
V_21 = 1 ;
goto V_103;
}
V_99 += V_98 ;
V_32 -= V_98 ;
if ( V_32 <= 0 ) break;
}
}
if ( F_91 ( V_95 , & V_96 ) )
{
if ( ! F_104 ( V_100 ) )
{
V_32 = F_105 ( V_100 ) ;
if ( V_32 < 0 )
{
V_21 = 0 ;
goto V_103;
}
else if ( V_32 == 0 )
{
V_21 = 1 ;
goto V_103;
}
}
else
{
V_119:
V_32 = F_106 ( V_100 , ( char * ) V_30 , V_102 ) ;
switch ( F_103 ( V_100 , V_32 ) )
{
case V_112 :
#ifdef F_100
F_14 ( V_30 , V_30 , V_32 ) ;
#endif
F_107 ( fileno ( stdout ) , V_30 ,
( unsigned int ) V_32 ) ;
if ( F_108 ( V_100 ) ) goto V_119;
break;
case V_113 :
case V_114 :
case V_115 :
F_5 ( V_76 , L_91 ) ;
break;
case V_116 :
case V_117 :
F_5 ( V_76 , L_90 ) ;
F_36 ( V_6 ) ;
V_21 = 1 ;
goto V_103;
case V_118 :
F_5 ( V_76 , L_86 ) ;
V_21 = 1 ;
goto V_103;
}
}
}
}
V_103:
F_5 ( V_76 , L_92 ) ;
#if 1
F_109 ( V_100 , V_120 | V_121 ) ;
#else
F_110 ( V_100 ) ;
#endif
if ( V_100 != NULL ) F_111 ( V_100 ) ;
F_5 ( V_76 , L_93 ) ;
if ( V_30 != NULL )
{
memset ( V_30 , 0 , V_102 ) ;
Free ( V_30 ) ;
}
if ( V_21 >= 0 )
F_5 ( V_76 , L_71 ) ;
return ( V_21 ) ;
}
static void F_94 ( void )
{
F_5 ( V_6 , L_94 ) ;
if ( V_89 >= 0 )
{
F_112 ( V_89 ) ;
}
}
static int F_105 ( T_9 * V_100 )
{
int V_32 ;
const char * V_33 ;
T_10 * V_122 ;
long V_123 ;
T_11 char V_30 [ V_124 ] ;
if ( ( V_32 = F_113 ( V_100 ) ) <= 0 )
{
if ( F_114 ( V_32 ) )
{
F_5 ( V_76 , L_95 ) ;
return ( 1 ) ;
}
F_5 ( V_6 , L_90 ) ;
V_123 = F_115 ( V_100 ) ;
if ( V_123 != V_125 )
{
F_5 ( V_6 , L_96 ,
F_116 ( V_123 ) ) ;
}
else
F_36 ( V_6 ) ;
return ( 0 ) ;
}
F_117 ( V_76 , F_118 ( V_100 ) ) ;
V_122 = F_119 ( V_100 ) ;
if ( V_122 != NULL )
{
F_5 ( V_76 , L_97 ) ;
F_120 ( V_76 , V_122 ) ;
F_121 ( F_122 ( V_122 ) , V_30 , V_124 ) ;
F_5 ( V_76 , L_98 , V_30 ) ;
F_121 ( F_123 ( V_122 ) , V_30 , V_124 ) ;
F_5 ( V_76 , L_99 , V_30 ) ;
F_124 ( V_122 ) ;
}
if ( F_125 ( V_100 , V_30 , V_124 ) != NULL )
F_5 ( V_76 , L_100 , V_30 ) ;
V_33 = F_126 ( F_127 ( V_100 ) ) ;
F_5 ( V_76 , L_101 , ( V_33 != NULL ) ? V_33 : L_102 ) ;
if ( V_100 -> V_126 ) F_5 ( V_76 , L_103 ) ;
if ( F_128 ( V_100 , V_127 , 0 , NULL ) &
V_128 )
F_5 ( V_76 , L_104 ) ;
return ( 1 ) ;
}
static T_1 * F_43 ( void )
{
T_1 * V_21 = NULL ;
T_3 * V_92 ;
if ( ( V_92 = F_129 ( V_129 , L_105 ) ) == NULL )
goto V_103;
V_21 = F_130 ( V_92 , NULL , NULL , NULL ) ;
V_103:
if ( V_92 != NULL ) F_61 ( V_92 ) ;
return ( V_21 ) ;
}
static int V_90 ( char * V_94 , int V_95 , unsigned char * V_39 )
{
char * V_30 = NULL ;
int V_21 = 1 ;
int V_32 , V_109 , V_98 , V_130 , V_131 ;
struct V_132 V_133 ;
T_9 * V_100 ;
T_12 * V_134 ;
T_3 * V_135 , * V_136 , * V_101 ;
long V_137 ;
V_30 = Malloc ( V_102 ) ;
if ( V_30 == NULL ) return ( 0 ) ;
V_135 = F_31 ( F_131 () ) ;
V_136 = F_31 ( F_132 () ) ;
if ( ( V_135 == NULL ) || ( V_136 == NULL ) ) goto V_103;
#ifdef F_6
if ( V_57 )
{
unsigned long V_104 = 1 ;
if ( ! V_52 )
F_5 ( V_6 , L_85 ) ;
if ( F_75 ( V_95 , F_6 , & V_104 ) < 0 )
F_36 ( V_6 ) ;
}
#endif
if ( ! F_133 ( V_135 , V_102 ) ) goto V_103;
if ( ( V_100 = ( T_9 * ) F_76 ( V_79 ) ) == NULL ) goto V_103;
if( V_39 ) F_77 ( V_100 , V_39 ,
strlen ( ( char * ) V_39 ) ) ;
V_101 = F_79 ( V_95 , V_55 ) ;
if ( V_58 )
{
T_3 * V_105 ;
V_105 = F_31 ( F_80 () ) ;
V_101 = F_81 ( V_105 , V_101 ) ;
}
F_82 ( V_100 , V_101 , V_101 ) ;
F_83 ( V_100 ) ;
F_134 ( V_136 , V_100 , V_138 ) ;
F_81 ( V_135 , V_136 ) ;
#ifdef F_100
V_135 = F_81 ( F_31 ( F_9 () ) , V_135 ) ;
#endif
if ( V_53 )
{
V_100 -> V_106 = 1 ;
F_84 ( F_85 ( V_100 ) , V_107 ) ;
F_86 ( F_85 ( V_100 ) , V_76 ) ;
}
V_130 = 0 ;
for (; ; )
{
if ( V_69 )
{
V_32 = F_113 ( V_100 ) ;
switch ( F_103 ( V_100 , V_32 ) )
{
case V_112 :
break;
case V_113 :
case V_114 :
case V_115 :
continue;
case V_116 :
case V_117 :
case V_118 :
V_21 = 1 ;
goto V_103;
}
F_95 ( V_100 ) ;
F_102 ( V_100 , NULL , 0 ) ;
}
V_32 = F_135 ( V_135 , V_30 , V_102 - 1 ) ;
if ( V_32 < 0 )
{
if ( ! F_136 ( V_135 ) )
{
if ( ! V_52 )
F_36 ( V_6 ) ;
goto V_103;
}
else
{
F_5 ( V_76 , L_106 ) ;
#ifndef F_137
F_138 ( 1 ) ;
#endif
continue;
}
}
else if ( V_32 == 0 )
{
V_21 = 1 ;
goto V_75;
}
if ( ( ( V_71 == 1 ) && ( strncmp ( L_107 , V_30 , 4 ) == 0 ) ) ||
( ( V_71 == 2 ) && ( strncmp ( L_108 , V_30 , 10 ) == 0 ) ) )
{
char * V_2 ;
T_10 * V_122 ;
F_139 ( T_12 ) * V_139 ;
static char * V_140 = L_109 ;
F_140 ( V_135 , L_110 ) ;
F_140 ( V_135 , L_111 ) ;
F_140 ( V_135 , L_112 ) ;
F_140 ( V_135 , L_2 ) ;
for ( V_32 = 0 ; V_32 < V_50 ; V_32 ++ )
{
F_140 ( V_135 , V_51 [ V_32 ] ) ;
F_17 ( V_135 , L_113 , 1 ) ;
}
F_140 ( V_135 , L_2 ) ;
F_5 ( V_135 , L_114 ) ;
V_139 = F_141 ( V_100 ) ;
V_109 = F_142 ( V_139 ) ;
for ( V_32 = 0 ; V_32 < V_109 ; V_32 ++ )
{
V_134 = F_143 ( V_139 , V_32 ) ;
F_5 ( V_135 , L_115 ,
F_144 ( V_134 ) ,
F_126 ( V_134 ) ) ;
if ( ( ( ( V_32 + 1 ) % 2 ) == 0 ) && ( V_32 + 1 != V_109 ) )
F_140 ( V_135 , L_2 ) ;
}
F_140 ( V_135 , L_2 ) ;
V_2 = F_125 ( V_100 , V_30 , V_102 ) ;
if ( V_2 != NULL )
{
F_5 ( V_135 , L_116 ) ;
V_109 = V_32 = 0 ;
while ( * V_2 )
{
if ( * V_2 == ':' )
{
F_17 ( V_135 , V_140 , 26 - V_109 ) ;
V_32 ++ ;
V_109 = 0 ;
F_17 ( V_135 , ( ( V_32 % 3 ) ? L_113 : L_2 ) , 1 ) ;
}
else
{
F_17 ( V_135 , V_2 , 1 ) ;
V_109 ++ ;
}
V_2 ++ ;
}
F_140 ( V_135 , L_2 ) ;
}
F_5 ( V_135 , ( ( V_100 -> V_126 )
? L_117
: L_118 ) ) ;
V_134 = F_127 ( V_100 ) ;
F_5 ( V_135 , L_119 ,
F_144 ( V_134 ) ,
F_126 ( V_134 ) ) ;
F_145 ( V_135 , F_118 ( V_100 ) ) ;
F_5 ( V_135 , L_120 ) ;
F_59 ( V_135 , F_99 ( V_100 ) ) ;
F_5 ( V_135 , L_120 ) ;
V_122 = F_119 ( V_100 ) ;
if ( V_122 != NULL )
{
F_5 ( V_135 , L_97 ) ;
F_146 ( V_135 , V_122 ) ;
F_120 ( V_135 , V_122 ) ;
}
else
F_140 ( V_135 , L_121 ) ;
F_140 ( V_135 , L_122 ) ;
break;
}
else if ( ( V_71 == 2 ) && ( strncmp ( L_123 , V_30 , 5 ) == 0 ) )
{
T_3 * V_141 ;
char * V_2 , * V_142 ;
static char * V_143 = L_124 ;
V_2 = & ( V_30 [ 5 ] ) ;
V_131 = 0 ;
for ( V_142 = V_2 ; * V_142 != '\0' ; V_142 ++ )
{
if ( V_142 [ 0 ] == ' ' ) break;
if ( ( V_142 [ 0 ] == '.' ) &&
( strncmp ( & ( V_142 [ - 1 ] ) , L_125 , 4 ) == 0 ) )
V_131 = 1 ;
}
if ( * V_142 == '\0' )
{
F_140 ( V_135 , V_143 ) ;
F_5 ( V_135 , L_126 , V_2 ) ;
break;
}
* V_142 = '\0' ;
if ( V_131 )
{
F_140 ( V_135 , V_143 ) ;
F_5 ( V_135 , L_127 , V_2 ) ;
break;
}
if ( * V_2 == '/' )
{
F_140 ( V_135 , V_143 ) ;
F_5 ( V_135 , L_128 , V_2 ) ;
break;
}
if ( V_142 [ - 1 ] == '/' )
strcat ( V_2 , L_129 ) ;
if ( V_132 ( V_2 , & V_133 ) < 0 )
{
F_140 ( V_135 , V_143 ) ;
F_5 ( V_135 , L_130 , V_2 ) ;
F_36 ( V_135 ) ;
break;
}
if ( F_147 ( V_133 . V_144 ) )
{
strcat ( V_2 , L_131 ) ;
}
if ( ( V_141 = F_129 ( V_2 , L_105 ) ) == NULL )
{
F_140 ( V_135 , V_143 ) ;
F_5 ( V_135 , L_132 , V_2 ) ;
F_36 ( V_135 ) ;
break;
}
if ( ! V_52 )
F_5 ( V_6 , L_133 , V_2 ) ;
V_32 = strlen ( V_2 ) ;
if ( ( ( V_32 > 5 ) && ( strcmp ( & ( V_2 [ V_32 - 5 ] ) , L_134 ) == 0 ) ) ||
( ( V_32 > 4 ) && ( strcmp ( & ( V_2 [ V_32 - 4 ] ) , L_135 ) == 0 ) ) ||
( ( V_32 > 4 ) && ( strcmp ( & ( V_2 [ V_32 - 4 ] ) , L_136 ) == 0 ) ) )
F_140 ( V_135 , L_110 ) ;
else
F_140 ( V_135 , L_124 ) ;
V_137 = 0 ;
for (; ; )
{
V_32 = F_13 ( V_141 , V_30 , V_102 ) ;
if ( V_32 <= 0 ) break;
#ifdef F_101
V_137 += V_32 ;
fprintf ( V_54 , L_137 , V_32 ) ;
if ( V_137 > 3 * 1024 )
{
V_137 = 0 ;
fprintf ( V_54 , L_138 ) ;
F_95 ( V_100 ) ;
}
#endif
for ( V_109 = 0 ; V_109 < V_32 ; )
{
#ifdef F_101
{ static V_111 = 0 ; if ( ++ V_111 == 13 ) { F_95 ( V_100 ) ; } }
#endif
V_98 = F_17 ( V_135 , & ( V_30 [ V_109 ] ) , V_32 - V_109 ) ;
if ( V_98 <= 0 )
{
if ( ! F_136 ( V_135 ) )
goto V_145;
else
{
F_5 ( V_76 , L_139 ) ;
}
}
else
{
V_109 += V_98 ;
}
}
}
V_145:
F_61 ( V_141 ) ;
break;
}
}
for (; ; )
{
V_32 = ( int ) F_44 ( V_135 ) ;
if ( V_32 <= 0 )
{
if ( ! F_136 ( V_135 ) )
break;
}
else
break;
}
V_75:
#if 1
F_109 ( V_100 , V_120 | V_121 ) ;
#else
#endif
V_103:
if ( V_21 >= 0 )
F_5 ( V_76 , L_71 ) ;
if ( V_30 != NULL ) Free ( V_30 ) ;
if ( V_135 != NULL ) F_148 ( V_135 ) ;
return ( V_21 ) ;
}
static T_6 T_13 * V_84 ( T_9 * V_95 , int V_146 , int V_147 )
{
static T_6 * V_148 = NULL ;
if ( V_148 == NULL )
{
if ( ! V_52 )
{
F_5 ( V_6 , L_140 , V_147 ) ;
( void ) F_44 ( V_6 ) ;
}
V_148 = F_50 ( V_147 , V_86 , NULL , NULL ) ;
if ( ! V_52 )
{
F_5 ( V_6 , L_2 ) ;
( void ) F_44 ( V_6 ) ;
}
}
return ( V_148 ) ;
}
