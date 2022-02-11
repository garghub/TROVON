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
F_5 ( V_6 , L_15 ) ;
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
F_5 ( V_6 , L_30 ) ;
F_5 ( V_6 , L_31 ) ;
}
int MAIN ( int V_9 , char * V_10 [] )
{
short V_11 = V_7 ;
char * V_12 = NULL , * V_13 = NULL ;
char * V_14 = NULL ;
int V_15 = 0 , V_16 = 0 ;
int V_17 = 1 ;
int V_18 = 0 ;
int V_19 = 0 , V_20 = 0 ;
int V_21 = 0 ;
T_2 * V_22 = NULL ;
#ifndef F_7
T_1 * V_1 = NULL ;
#endif
#if ! F_8 ( V_23 ) && ! F_8 ( V_24 )
V_22 = F_9 () ;
#elif ! F_8 ( V_24 )
V_22 = F_10 () ;
#elif ! F_8 ( V_23 )
V_22 = F_11 () ;
#endif
V_25 = V_9 ;
V_26 = V_10 ;
F_12 () ;
V_27 = 0 ;
V_28 = 0 ;
if ( V_6 == NULL )
V_6 = F_13 ( V_29 , V_30 ) ;
V_31 = 0 ;
#ifdef F_6
V_32 = 0 ;
#endif
V_33 = 0 ;
V_9 -- ;
V_10 ++ ;
while ( V_9 >= 1 )
{
if ( ( strcmp ( * V_10 , L_32 ) == 0 ) ||
( strcmp ( * V_10 , L_33 ) == 0 ) )
{
if ( -- V_9 < 1 ) goto V_34;
if ( ! F_14 ( * ( ++ V_10 ) , & V_11 ) )
goto V_34;
}
else if ( strcmp ( * V_10 , L_34 ) == 0 )
{
V_35 = V_36 | V_37 ;
if ( -- V_9 < 1 ) goto V_34;
V_31 = atoi ( * ( ++ V_10 ) ) ;
F_5 ( V_6 , L_35 , V_31 ) ;
}
else if ( strcmp ( * V_10 , L_36 ) == 0 )
{
V_35 = V_36 | V_38 |
V_37 ;
if ( -- V_9 < 1 ) goto V_34;
V_31 = atoi ( * ( ++ V_10 ) ) ;
F_5 ( V_6 , L_37 , V_31 ) ;
}
else if ( strcmp ( * V_10 , L_38 ) == 0 )
{
if ( -- V_9 < 1 ) goto V_34;
V_14 = * ( ++ V_10 ) ;
}
else if ( strcmp ( * V_10 , L_39 ) == 0 )
{
if ( -- V_9 < 1 ) goto V_34;
V_39 = * ( ++ V_10 ) ;
}
else if ( strcmp ( * V_10 , L_40 ) == 0 )
{
if ( -- V_9 < 1 ) goto V_34;
V_40 = * ( ++ V_10 ) ;
}
else if ( strcmp ( * V_10 , L_41 ) == 0 )
{
if ( -- V_9 < 1 ) goto V_34;
V_41 = * ( ++ V_10 ) ;
}
else if ( strcmp ( * V_10 , L_42 ) == 0 )
{
if ( -- V_9 < 1 ) goto V_34;
V_42 = * ( ++ V_10 ) ;
}
else if ( strcmp ( * V_10 , L_43 ) == 0 )
{
V_20 = 1 ;
}
else if ( strcmp ( * V_10 , L_44 ) == 0 )
{
if ( -- V_9 < 1 ) goto V_34;
V_12 = * ( ++ V_10 ) ;
}
else if ( strcmp ( * V_10 , L_45 ) == 0 )
{
if ( -- V_9 < 1 ) goto V_34;
V_43 = * ( ++ V_10 ) ;
}
else if ( strcmp ( * V_10 , L_46 ) == 0 )
{
if ( -- V_9 < 1 ) goto V_34;
V_13 = * ( ++ V_10 ) ;
}
#ifdef F_6
else if ( strcmp ( * V_10 , L_47 ) == 0 )
{ V_32 = 1 ; }
#endif
else if ( strcmp ( * V_10 , L_48 ) == 0 )
{
#ifdef F_6
V_32 = 1 ;
#endif
V_33 = 1 ;
}
else if ( strcmp ( * V_10 , L_49 ) == 0 )
{ V_28 = 1 ; }
else if ( strcmp ( * V_10 , L_50 ) == 0 )
{ V_44 = 1 ; }
else if ( strcmp ( * V_10 , L_51 ) == 0 )
{ V_21 = 1 ; }
else if ( strcmp ( * V_10 , L_52 ) == 0 )
{ V_27 = 1 ; }
else if ( strcmp ( * V_10 , L_53 ) == 0 )
{ V_16 = 1 ; }
else if ( strcmp ( * V_10 , L_54 ) == 0 )
{ V_19 = 1 ; }
else if ( strcmp ( * V_10 , L_55 ) == 0 )
{ V_45 = 1 ; }
else if ( strcmp ( * V_10 , L_56 ) == 0 )
{ V_45 = 2 ; }
else if ( strcmp ( * V_10 , L_57 ) == 0 )
{ V_18 |= V_46 ; }
else if ( strcmp ( * V_10 , L_58 ) == 0 )
{ V_18 |= V_47 ; }
else if ( strcmp ( * V_10 , L_59 ) == 0 )
{ V_18 |= V_48 ; }
#ifndef V_23
else if ( strcmp ( * V_10 , L_60 ) == 0 )
{ V_22 = F_11 () ; }
#endif
#ifndef V_24
else if ( strcmp ( * V_10 , L_61 ) == 0 )
{ V_22 = F_10 () ; }
#endif
#ifndef F_15
else if ( strcmp ( * V_10 , L_62 ) == 0 )
{ V_22 = F_16 () ; }
#endif
else
{
F_5 ( V_6 , L_63 , * V_10 ) ;
V_15 = 1 ;
break;
}
V_9 -- ;
V_10 ++ ;
}
if ( V_15 )
{
V_34:
F_4 () ;
goto V_49;
}
if ( V_50 == NULL )
{
if ( V_27 && ! V_28 )
{
V_50 = F_17 ( F_18 () ) ;
}
else
{
if ( V_50 == NULL )
V_50 = F_13 ( stdout , V_30 ) ;
}
}
#if ! F_8 ( V_51 ) || ! F_8 ( V_52 )
if ( V_20 )
#endif
{
V_39 = NULL ;
V_40 = NULL ;
V_41 = NULL ;
V_42 = NULL ;
}
F_19 () ;
F_20 () ;
V_53 = F_21 ( V_22 ) ;
if ( V_53 == NULL )
{
F_22 ( V_6 ) ;
goto V_49;
}
F_23 ( V_53 , 1 ) ;
if ( V_16 ) F_24 ( V_53 , V_54 ) ;
if ( V_44 ) F_24 ( V_53 , V_55 ) ;
F_24 ( V_53 , V_18 ) ;
if ( V_44 ) F_24 ( V_53 , V_56 ) ;
if ( V_21 ) F_25 ( V_53 , V_57 ) ;
F_26 ( V_53 , 128 ) ;
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
if ( ( ! F_27 ( V_53 , V_13 , V_12 ) ) ||
( ! F_28 ( V_53 ) ) )
{
F_22 ( V_6 ) ;
}
#ifndef F_7
V_1 = F_29 () ;
if ( V_1 != NULL )
{
F_5 ( V_50 , L_64 ) ;
}
else
{
F_5 ( V_50 , L_65 ) ;
V_1 = F_1 () ;
}
F_30 ( V_50 ) ;
F_31 ( V_53 , V_1 ) ;
F_32 ( V_1 ) ;
#endif
if ( ! F_33 ( V_53 , V_39 , V_40 ) )
goto V_49;
if ( V_41 != NULL )
{
if ( ! F_33 ( V_53 , V_41 , V_42 ) )
goto V_49;
}
#ifndef V_51
#if 1
F_34 ( V_53 , V_58 ) ;
#else
if ( ! V_19 && F_35 ( V_53 ) )
{
T_3 * V_59 ;
F_5 ( V_50 , L_66 ) ;
F_30 ( V_50 ) ;
V_59 = F_36 ( 512 , V_60 , NULL ) ;
if ( ! F_37 ( V_53 , V_59 ) )
{
F_22 ( V_6 ) ;
goto V_49;
}
F_38 ( V_59 ) ;
F_5 ( V_50 , L_2 ) ;
}
#endif
#endif
if ( V_43 != NULL )
F_39 ( V_53 , V_43 ) ;
F_40 ( V_53 , V_35 , V_61 ) ;
F_41 ( V_53 , ( void * ) & V_62 ,
sizeof V_62 ) ;
F_42 ( V_53 , F_43 ( V_13 ) ) ;
F_5 ( V_50 , L_67 ) ;
if ( V_45 )
F_44 ( V_11 , & V_63 , V_64 , V_14 ) ;
else
F_44 ( V_11 , & V_63 , V_65 , V_14 ) ;
F_45 ( V_50 , V_53 ) ;
V_17 = 0 ;
V_49:
if ( V_53 != NULL ) F_46 ( V_53 ) ;
if ( V_50 != NULL )
{
F_47 ( V_50 ) ;
V_50 = NULL ;
}
EXIT ( V_17 ) ;
}
static void F_45 ( T_4 * V_66 , T_5 * V_67 )
{
F_5 ( V_66 , L_68 ,
F_48 ( V_67 ) ) ;
F_5 ( V_66 , L_69 ,
F_49 ( V_67 ) ) ;
F_5 ( V_66 , L_70 ,
F_50 ( V_67 ) ) ;
F_5 ( V_66 , L_71 ,
F_51 ( V_67 ) ) ;
F_5 ( V_66 , L_72 ,
F_52 ( V_67 ) ) ;
F_5 ( V_66 , L_73 ,
F_53 ( V_67 ) ) ;
F_5 ( V_66 , L_74 ,
F_54 ( V_67 ) ) ;
F_5 ( V_66 , L_75 , F_55 ( V_67 ) ) ;
F_5 ( V_66 , L_76 , F_56 ( V_67 ) ) ;
F_5 ( V_66 , L_77 , F_57 ( V_67 ) ) ;
F_5 ( V_66 , L_78 , F_58 ( V_67 ) ) ;
F_5 ( V_66 , L_79 ,
F_59 ( V_67 ) ,
F_60 ( V_67 ) ) ;
}
static int V_65 ( char * V_68 , int V_69 , unsigned char * V_14 )
{
char * V_70 = NULL ;
T_6 V_71 ;
int V_17 = 1 , V_72 ;
int V_73 , V_74 ;
unsigned long V_75 ;
T_7 * V_76 = NULL ;
T_4 * V_77 ;
if ( ( V_70 = Malloc ( V_78 ) ) == NULL )
{
F_5 ( V_6 , L_80 ) ;
goto V_79;
}
#ifdef F_6
if ( V_32 )
{
unsigned long V_80 = 1 ;
if ( ! V_27 )
F_5 ( V_6 , L_81 ) ;
if ( F_61 ( V_69 , F_6 , & V_80 ) < 0 )
F_22 ( V_6 ) ;
}
#endif
if ( V_76 == NULL ) {
V_76 = ( T_7 * ) F_62 ( V_53 ) ;
if( V_14 )
F_63 ( V_76 , V_14 ,
strlen ( ( char * ) V_14 ) ) ;
}
F_64 ( V_76 ) ;
V_77 = F_65 ( V_69 , V_30 ) ;
if ( V_33 )
{
T_4 * V_81 ;
V_81 = F_17 ( F_66 () ) ;
V_77 = F_67 ( V_81 , V_77 ) ;
}
F_68 ( V_76 , V_77 , V_77 ) ;
F_69 ( V_76 ) ;
if ( V_28 )
{
V_76 -> V_82 = 1 ;
F_70 ( F_71 ( V_76 ) , V_83 ) ;
F_72 ( F_71 ( V_76 ) , V_50 ) ;
}
V_72 = V_69 + 1 ;
for (; ; )
{
F_73 ( & V_71 ) ;
#ifndef F_74
F_75 ( fileno ( V_84 ) , & V_71 ) ;
#endif
F_75 ( V_69 , & V_71 ) ;
V_74 = F_76 ( V_72 , ( void * ) & V_71 , NULL , NULL , NULL ) ;
if ( V_74 <= 0 ) continue;
if ( F_77 ( fileno ( V_84 ) , & V_71 ) )
{
V_74 = F_78 ( fileno ( V_84 ) , V_70 , V_78 ) ;
if ( ! V_27 )
{
if ( ( V_74 <= 0 ) || ( V_70 [ 0 ] == 'Q' ) )
{
F_5 ( V_50 , L_82 ) ;
F_79 ( V_69 ) ;
F_80 () ;
V_17 = - 11 ;
goto V_79;
}
if ( ( V_74 <= 0 ) || ( V_70 [ 0 ] == 'q' ) )
{
F_5 ( V_50 , L_82 ) ;
F_79 ( V_69 ) ;
goto V_79;
}
if ( ( V_70 [ 0 ] == 'r' ) &&
( ( V_70 [ 1 ] == '\n' ) || ( V_70 [ 1 ] == '\r' ) ) )
{
F_81 ( V_76 ) ;
V_74 = F_82 ( V_76 ) ;
printf ( L_83 , V_74 ) ;
V_74 = 0 ;
continue;
}
if ( ( V_70 [ 0 ] == 'R' ) &&
( ( V_70 [ 1 ] == '\n' ) || ( V_70 [ 1 ] == '\r' ) ) )
{
F_83 ( V_76 ,
V_36 | V_37 , NULL ) ;
F_81 ( V_76 ) ;
V_74 = F_82 ( V_76 ) ;
printf ( L_83 , V_74 ) ;
V_74 = 0 ;
continue;
}
if ( V_70 [ 0 ] == 'P' )
{
static char * V_85 = L_84 ;
F_84 ( F_85 ( V_76 ) , V_85 , strlen ( V_85 ) ) ;
}
if ( V_70 [ 0 ] == 'S' )
{
F_45 ( V_50 , F_86 ( V_76 ) ) ;
}
}
V_75 = V_73 = 0 ;
for (; ; )
{
#ifdef F_87
{ static V_86 = 0 ; if ( ++ V_86 == 100 ) { V_86 = 0 ; F_81 ( V_76 ) ; } }
#endif
V_73 = F_88 ( V_76 , & ( V_70 [ V_75 ] ) , ( unsigned int ) V_74 ) ;
switch ( F_89 ( V_76 , V_73 ) )
{
case V_87 :
break;
case V_88 :
case V_89 :
case V_90 :
F_5 ( V_50 , L_85 ) ;
break;
case V_91 :
case V_92 :
F_5 ( V_50 , L_86 ) ;
F_22 ( V_6 ) ;
V_17 = 1 ;
goto V_79;
case V_93 :
F_5 ( V_50 , L_82 ) ;
V_17 = 1 ;
goto V_79;
}
V_75 += V_73 ;
V_74 -= V_73 ;
if ( V_74 <= 0 ) break;
}
}
if ( F_77 ( V_69 , & V_71 ) )
{
if ( ! F_90 ( V_76 ) )
{
V_74 = F_91 ( V_76 ) ;
if ( V_74 < 0 )
{
V_17 = 0 ;
goto V_79;
}
else if ( V_74 == 0 )
{
V_17 = 1 ;
goto V_79;
}
}
else
{
V_94:
V_74 = F_92 ( V_76 , ( char * ) V_70 , V_78 ) ;
switch ( F_89 ( V_76 , V_74 ) )
{
case V_87 :
F_93 ( fileno ( stdout ) , V_70 ,
( unsigned int ) V_74 ) ;
if ( F_94 ( V_76 ) ) goto V_94;
break;
case V_88 :
case V_89 :
case V_90 :
F_5 ( V_50 , L_87 ) ;
break;
case V_91 :
case V_92 :
F_5 ( V_50 , L_86 ) ;
F_22 ( V_6 ) ;
V_17 = 1 ;
goto V_79;
case V_93 :
F_5 ( V_50 , L_82 ) ;
V_17 = 1 ;
goto V_79;
}
}
}
}
V_79:
F_5 ( V_50 , L_88 ) ;
#if 1
F_95 ( V_76 , V_95 | V_96 ) ;
#else
F_96 ( V_76 ) ;
#endif
if ( V_76 != NULL ) F_97 ( V_76 ) ;
F_5 ( V_50 , L_89 ) ;
if ( V_70 != NULL )
{
memset ( V_70 , 0 , V_78 ) ;
Free ( V_70 ) ;
}
if ( V_17 >= 0 )
F_5 ( V_50 , L_67 ) ;
return ( V_17 ) ;
}
static void F_80 ( void )
{
F_5 ( V_6 , L_90 ) ;
if ( V_63 >= 0 )
{
F_98 ( V_63 ) ;
}
}
static int F_91 ( T_7 * V_76 )
{
int V_74 ;
const char * V_85 ;
T_8 * V_97 ;
long V_98 ;
T_9 char V_70 [ V_99 ] ;
if ( ( V_74 = F_99 ( V_76 ) ) <= 0 )
{
if ( F_100 ( V_74 ) )
{
F_5 ( V_50 , L_91 ) ;
return ( 1 ) ;
}
F_5 ( V_6 , L_86 ) ;
V_98 = F_101 ( V_76 ) ;
if ( V_98 != V_100 )
{
F_5 ( V_6 , L_92 ,
F_102 ( V_98 ) ) ;
}
else
F_22 ( V_6 ) ;
return ( 0 ) ;
}
F_103 ( V_50 , F_104 ( V_76 ) ) ;
V_97 = F_105 ( V_76 ) ;
if ( V_97 != NULL )
{
F_5 ( V_50 , L_93 ) ;
F_106 ( V_50 , V_97 ) ;
F_107 ( F_108 ( V_97 ) , V_70 , V_99 ) ;
F_5 ( V_50 , L_94 , V_70 ) ;
F_107 ( F_109 ( V_97 ) , V_70 , V_99 ) ;
F_5 ( V_50 , L_95 , V_70 ) ;
F_110 ( V_97 ) ;
}
if ( F_111 ( V_76 , V_70 , V_99 ) != NULL )
F_5 ( V_50 , L_96 , V_70 ) ;
V_85 = F_112 ( F_113 ( V_76 ) ) ;
F_5 ( V_50 , L_97 , ( V_85 != NULL ) ? V_85 : L_98 ) ;
if ( V_76 -> V_101 ) F_5 ( V_50 , L_99 ) ;
if ( F_114 ( V_76 , V_102 , 0 , NULL ) &
V_103 )
F_5 ( V_50 , L_100 ) ;
return ( 1 ) ;
}
static T_1 * F_29 ( void )
{
T_1 * V_17 = NULL ;
T_4 * V_66 ;
if ( ( V_66 = F_115 ( V_104 , L_101 ) ) == NULL )
goto V_79;
V_17 = F_116 ( V_66 , NULL , NULL ) ;
V_79:
if ( V_66 != NULL ) F_47 ( V_66 ) ;
return ( V_17 ) ;
}
static int V_64 ( char * V_68 , int V_69 , unsigned char * V_14 )
{
char * V_70 = NULL ;
int V_17 = 1 ;
int V_74 , V_105 , V_73 , V_106 , V_107 ;
struct V_108 V_109 ;
T_7 * V_76 ;
T_10 * V_110 ;
T_4 * V_111 , * V_112 , * V_77 ;
long V_113 ;
V_70 = Malloc ( V_78 ) ;
if ( V_70 == NULL ) return ( 0 ) ;
V_111 = F_17 ( F_117 () ) ;
V_112 = F_17 ( F_118 () ) ;
if ( ( V_111 == NULL ) || ( V_112 == NULL ) ) goto V_79;
#ifdef F_6
if ( V_32 )
{
unsigned long V_80 = 1 ;
if ( ! V_27 )
F_5 ( V_6 , L_81 ) ;
if ( F_61 ( V_69 , F_6 , & V_80 ) < 0 )
F_22 ( V_6 ) ;
}
#endif
if ( ! F_119 ( V_111 , V_78 ) ) goto V_79;
if ( ( V_76 = ( T_7 * ) F_62 ( V_53 ) ) == NULL ) goto V_79;
if( V_14 ) F_63 ( V_76 , V_14 ,
strlen ( ( char * ) V_14 ) ) ;
V_77 = F_65 ( V_69 , V_30 ) ;
if ( V_33 )
{
T_4 * V_81 ;
V_81 = F_17 ( F_66 () ) ;
V_77 = F_67 ( V_81 , V_77 ) ;
}
F_68 ( V_76 , V_77 , V_77 ) ;
F_69 ( V_76 ) ;
F_120 ( V_112 , V_76 , V_114 ) ;
F_67 ( V_111 , V_112 ) ;
if ( V_28 )
{
V_76 -> V_82 = 1 ;
F_70 ( F_71 ( V_76 ) , V_83 ) ;
F_72 ( F_71 ( V_76 ) , V_50 ) ;
}
V_106 = 0 ;
for (; ; )
{
if ( V_44 )
{
V_74 = F_99 ( V_76 ) ;
switch ( F_89 ( V_76 , V_74 ) )
{
case V_87 :
break;
case V_88 :
case V_89 :
case V_90 :
continue;
case V_91 :
case V_92 :
case V_93 :
V_17 = 1 ;
goto V_79;
}
F_81 ( V_76 ) ;
F_88 ( V_76 , NULL , 0 ) ;
}
V_74 = F_121 ( V_111 , V_70 , V_78 - 1 ) ;
if ( V_74 < 0 )
{
if ( ! F_122 ( V_111 ) )
{
if ( ! V_27 )
F_22 ( V_6 ) ;
goto V_79;
}
else
{
F_5 ( V_50 , L_102 ) ;
#ifndef F_123
F_124 ( 1 ) ;
#endif
continue;
}
}
else if ( V_74 == 0 )
{
V_17 = 1 ;
goto V_49;
}
if ( ( ( V_45 == 1 ) && ( strncmp ( L_103 , V_70 , 4 ) == 0 ) ) ||
( ( V_45 == 2 ) && ( strncmp ( L_104 , V_70 , 10 ) == 0 ) ) )
{
char * V_2 ;
T_8 * V_97 ;
F_125 ( T_10 ) * V_115 ;
static char * V_116 = L_105 ;
F_126 ( V_111 , L_106 ) ;
F_126 ( V_111 , L_107 ) ;
F_126 ( V_111 , L_108 ) ;
F_126 ( V_111 , L_2 ) ;
for ( V_74 = 0 ; V_74 < V_25 ; V_74 ++ )
{
F_126 ( V_111 , V_26 [ V_74 ] ) ;
F_84 ( V_111 , L_109 , 1 ) ;
}
F_126 ( V_111 , L_2 ) ;
F_5 ( V_111 , L_110 ) ;
V_115 = F_127 ( V_76 ) ;
V_105 = F_128 ( V_115 ) ;
for ( V_74 = 0 ; V_74 < V_105 ; V_74 ++ )
{
V_110 = F_129 ( V_115 , V_74 ) ;
F_5 ( V_111 , L_111 ,
F_130 ( V_110 ) ,
F_112 ( V_110 ) ) ;
if ( ( ( ( V_74 + 1 ) % 2 ) == 0 ) && ( V_74 + 1 != V_105 ) )
F_126 ( V_111 , L_2 ) ;
}
F_126 ( V_111 , L_2 ) ;
V_2 = F_111 ( V_76 , V_70 , V_78 ) ;
if ( V_2 != NULL )
{
F_5 ( V_111 , L_112 ) ;
V_105 = V_74 = 0 ;
while ( * V_2 )
{
if ( * V_2 == ':' )
{
F_84 ( V_111 , V_116 , 26 - V_105 ) ;
V_74 ++ ;
V_105 = 0 ;
F_84 ( V_111 , ( ( V_74 % 3 ) ? L_109 : L_2 ) , 1 ) ;
}
else
{
F_84 ( V_111 , V_2 , 1 ) ;
V_105 ++ ;
}
V_2 ++ ;
}
F_126 ( V_111 , L_2 ) ;
}
F_5 ( V_111 , ( ( V_76 -> V_101 )
? L_113
: L_114 ) ) ;
V_110 = F_113 ( V_76 ) ;
F_5 ( V_111 , L_115 ,
F_130 ( V_110 ) ,
F_112 ( V_110 ) ) ;
F_131 ( V_111 , F_104 ( V_76 ) ) ;
F_5 ( V_111 , L_116 ) ;
F_45 ( V_111 , F_86 ( V_76 ) ) ;
F_5 ( V_111 , L_116 ) ;
V_97 = F_105 ( V_76 ) ;
if ( V_97 != NULL )
{
F_5 ( V_111 , L_93 ) ;
F_132 ( V_111 , V_97 ) ;
F_106 ( V_111 , V_97 ) ;
}
else
F_126 ( V_111 , L_117 ) ;
F_126 ( V_111 , L_118 ) ;
break;
}
else if ( ( V_45 == 2 ) && ( strncmp ( L_103 , V_70 , 4 ) == 0 ) )
{
T_4 * V_117 ;
char * V_2 , * V_118 ;
static char * V_119 = L_119 ;
V_2 = & ( V_70 [ 5 ] ) ;
V_107 = 0 ;
for ( V_118 = V_2 ; * V_118 != '\0' ; V_118 ++ )
{
if ( V_118 [ 0 ] == ' ' ) break;
if ( ( V_118 [ 0 ] == '.' ) &&
( strncmp ( & ( V_118 [ - 1 ] ) , L_120 , 4 ) == 0 ) )
V_107 = 1 ;
}
if ( * V_118 == '\0' )
{
F_126 ( V_111 , V_119 ) ;
F_5 ( V_111 , L_121 , V_2 ) ;
break;
}
* V_118 = '\0' ;
if ( V_107 )
{
F_126 ( V_111 , V_119 ) ;
F_5 ( V_111 , L_122 , V_2 ) ;
break;
}
if ( * V_2 == '/' )
{
F_126 ( V_111 , V_119 ) ;
F_5 ( V_111 , L_123 , V_2 ) ;
break;
}
if ( V_118 [ - 1 ] == '/' )
strcat ( V_2 , L_124 ) ;
if ( V_108 ( V_2 , & V_109 ) < 0 )
{
F_126 ( V_111 , V_119 ) ;
F_5 ( V_111 , L_125 , V_2 ) ;
F_22 ( V_111 ) ;
break;
}
if ( F_133 ( V_109 . V_120 ) )
{
strcat ( V_2 , L_126 ) ;
}
if ( ( V_117 = F_115 ( V_2 , L_101 ) ) == NULL )
{
F_126 ( V_111 , V_119 ) ;
F_5 ( V_111 , L_127 , V_2 ) ;
F_22 ( V_111 ) ;
break;
}
if ( ! V_27 )
F_5 ( V_6 , L_128 , V_2 ) ;
V_74 = strlen ( V_2 ) ;
if ( ( ( V_74 > 5 ) && ( strcmp ( & ( V_2 [ V_74 - 5 ] ) , L_129 ) == 0 ) ) ||
( ( V_74 > 4 ) && ( strcmp ( & ( V_2 [ V_74 - 4 ] ) , L_130 ) == 0 ) ) ||
( ( V_74 > 4 ) && ( strcmp ( & ( V_2 [ V_74 - 4 ] ) , L_131 ) == 0 ) ) )
F_126 ( V_111 , L_106 ) ;
else
F_126 ( V_111 , L_119 ) ;
V_113 = 0 ;
for (; ; )
{
V_74 = F_134 ( V_117 , V_70 , V_78 ) ;
if ( V_74 <= 0 ) break;
#ifdef F_87
V_113 += V_74 ;
fprintf ( V_29 , L_132 , V_74 ) ;
if ( V_113 > 3 * 1024 )
{
V_113 = 0 ;
fprintf ( V_29 , L_133 ) ;
F_81 ( V_76 ) ;
}
#endif
for ( V_105 = 0 ; V_105 < V_74 ; )
{
#ifdef F_87
{ static V_86 = 0 ; if ( ++ V_86 == 13 ) { F_81 ( V_76 ) ; } }
#endif
V_73 = F_84 ( V_111 , & ( V_70 [ V_105 ] ) , V_74 - V_105 ) ;
if ( V_73 <= 0 )
{
if ( ! F_122 ( V_111 ) )
goto V_121;
else
{
F_5 ( V_50 , L_134 ) ;
}
}
else
{
V_105 += V_73 ;
}
}
}
V_121:
F_47 ( V_117 ) ;
break;
}
}
for (; ; )
{
V_74 = ( int ) F_30 ( V_111 ) ;
if ( V_74 <= 0 )
{
if ( ! F_122 ( V_111 ) )
break;
}
else
break;
}
V_49:
#if 1
F_95 ( V_76 , V_95 | V_96 ) ;
#else
#endif
V_79:
if ( V_17 >= 0 )
F_5 ( V_50 , L_67 ) ;
if ( V_70 != NULL ) Free ( V_70 ) ;
if ( V_111 != NULL ) F_135 ( V_111 ) ;
return ( V_17 ) ;
}
static T_3 T_11 * V_58 ( T_7 * V_69 , int V_122 , int V_123 )
{
static T_3 * V_124 = NULL ;
if ( V_124 == NULL )
{
if ( ! V_27 )
{
F_5 ( V_6 , L_135 , V_123 ) ;
F_30 ( V_6 ) ;
}
V_124 = F_36 ( V_123 , V_60 , NULL , NULL ) ;
if ( ! V_27 )
{
F_5 ( V_6 , L_2 ) ;
F_30 ( V_6 ) ;
}
}
return ( V_124 ) ;
}
