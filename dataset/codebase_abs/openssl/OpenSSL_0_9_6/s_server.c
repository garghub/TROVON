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
V_6 = - 1 ;
V_7 = NULL ;
V_8 = V_9 ;
V_10 = NULL ;
V_11 = NULL ;
V_12 = V_13 ;
V_14 = NULL ;
#ifdef F_5
V_15 = 0 ;
#endif
V_16 = 0 ;
V_17 = NULL ;
V_18 = 0 ;
V_19 = NULL ;
V_20 = 0 ;
V_21 = 0 ;
V_22 = 0 ;
}
static void F_6 ( void )
{
F_7 ( V_23 , L_1 ) ;
F_7 ( V_23 , L_2 ) ;
F_7 ( V_23 , L_3 , V_24 ) ;
F_7 ( V_23 , L_4 ) ;
F_7 ( V_23 , L_5 ) ;
F_7 ( V_23 , L_6 ) ;
F_7 ( V_23 , L_7 ) ;
F_7 ( V_23 , L_8 , V_13 ) ;
F_7 ( V_23 , L_9 ) ;
F_7 ( V_23 , L_10 , V_13 ) ;
F_7 ( V_23 , L_11 ) ;
F_7 ( V_23 , L_12 ) ;
F_7 ( V_23 , L_13 ) ;
F_7 ( V_23 , L_14 ) ;
#ifdef F_5
F_7 ( V_23 , L_15 ) ;
#endif
F_7 ( V_23 , L_16 ) ;
F_7 ( V_23 , L_17 ) ;
F_7 ( V_23 , L_18 ) ;
F_7 ( V_23 , L_19 ) ;
F_7 ( V_23 , L_20 ) ;
F_7 ( V_23 , L_21 ) ;
F_7 ( V_23 , L_22 ) ;
F_7 ( V_23 , L_23 ) ;
F_7 ( V_23 , L_24 ) ;
F_7 ( V_23 , L_25 ) ;
F_7 ( V_23 , L_26 ) ;
F_7 ( V_23 , L_27 ) ;
F_7 ( V_23 , L_28 ) ;
F_7 ( V_23 , L_29 ) ;
F_7 ( V_23 , L_30 ) ;
F_7 ( V_23 , L_31 ) ;
#ifndef F_8
F_7 ( V_23 , L_32 ) ;
#endif
F_7 ( V_23 , L_33 ) ;
F_7 ( V_23 , L_34 ) ;
F_7 ( V_23 , L_35 ) ;
}
T_2 * F_9 ()
{
return ( & V_25 ) ;
}
static int F_10 ( T_3 * V_26 )
{
T_4 * V_27 ;
V_27 = ( T_4 * ) F_11 ( sizeof( T_4 ) + 1024 ) ;
V_27 -> V_28 = 1024 ;
V_27 -> V_29 [ 0 ] = '\0' ;
V_26 -> V_30 = ( char * ) V_27 ;
V_26 -> V_31 = 1 ;
V_26 -> V_32 = 0 ;
return ( 1 ) ;
}
static int F_12 ( T_3 * V_33 )
{
if ( V_33 == NULL ) return ( 0 ) ;
if ( V_33 -> V_30 != NULL )
F_13 ( V_33 -> V_30 ) ;
V_33 -> V_30 = NULL ;
V_33 -> V_31 = 0 ;
V_33 -> V_32 = 0 ;
return ( 1 ) ;
}
static int F_14 ( T_3 * V_34 , char * V_35 , int V_36 )
{
int V_37 = 0 ;
if ( V_35 == NULL || V_36 == 0 ) return ( 0 ) ;
if ( V_34 -> V_38 == NULL ) return ( 0 ) ;
V_37 = F_15 ( V_34 -> V_38 , V_35 , V_36 ) ;
if ( V_37 > 0 )
F_16 ( V_35 , V_35 , V_37 ) ;
return ( V_37 ) ;
}
static int F_17 ( T_3 * V_34 , char * V_39 , int V_40 )
{
T_4 * V_27 ;
int V_37 = 0 ;
int V_41 ;
unsigned char V_42 ;
if ( ( V_39 == NULL ) || ( V_40 <= 0 ) ) return ( 0 ) ;
if ( V_34 -> V_38 == NULL ) return ( 0 ) ;
V_27 = ( T_4 * ) V_34 -> V_30 ;
if ( V_40 > ( V_41 = V_27 -> V_28 ) )
{
V_41 = V_41 + V_41 ;
if ( V_41 < V_40 )
V_41 = V_40 ;
F_13 ( V_27 ) ;
V_27 = ( T_4 * ) F_11 ( sizeof( T_4 ) + V_41 ) ;
V_27 -> V_28 = V_41 ;
V_27 -> V_29 [ 0 ] = '\0' ;
V_34 -> V_30 = ( char * ) V_27 ;
}
F_18 ( V_27 -> V_29 , V_39 , V_40 ) ;
V_37 = F_19 ( V_34 -> V_38 , V_27 -> V_29 , V_40 ) ;
return ( V_37 ) ;
}
static long F_20 ( T_3 * V_34 , int V_43 , long V_41 , char * V_30 )
{
long V_37 ;
if ( V_34 -> V_38 == NULL ) return ( 0 ) ;
switch ( V_43 )
{
case V_44 :
V_37 = 0L ;
break;
default:
V_37 = F_21 ( V_34 -> V_38 , V_43 , V_41 , V_30 ) ;
break;
}
return ( V_37 ) ;
}
static int F_22 ( T_3 * V_45 , char * V_46 , int V_47 )
{
int V_48 , V_37 ;
if ( V_45 -> V_38 == NULL ) return ( 0 ) ;
for ( V_48 = 0 ; V_48 < V_47 - 1 ; ++ V_48 )
{
V_37 = F_14 ( V_45 , & V_46 [ V_48 ] , 1 ) ;
if ( V_37 <= 0 )
break;
else if ( V_46 [ V_48 ] == '\n' )
{
++ V_48 ;
break;
}
}
if ( V_48 < V_47 )
V_46 [ V_48 ] = '\0' ;
return ( V_37 < 0 && V_48 == 0 ) ? V_37 : V_48 ;
}
static int F_23 ( T_3 * V_45 , char * V_49 )
{
if ( V_45 -> V_38 == NULL ) return ( 0 ) ;
return F_17 ( V_45 , V_49 , strlen ( V_49 ) ) ;
}
int MAIN ( int V_50 , char * V_51 [] )
{
short V_52 = V_24 ;
char * V_53 = NULL , * V_54 = NULL ;
char * V_55 = NULL ;
char * V_56 = NULL ;
int V_57 = 0 , V_58 = 0 ;
int V_37 = 1 ;
int V_59 = 0 ;
int V_60 = 0 , V_61 = 0 , V_62 = 0 ;
int V_63 = 0 ;
T_5 * V_64 = NULL ;
#ifndef F_8
T_1 * V_1 = NULL ;
#endif
#if ! F_24 ( V_65 ) && ! F_24 ( V_66 )
V_64 = F_25 () ;
#elif ! F_24 ( V_66 )
V_64 = F_26 () ;
#elif ! F_24 ( V_65 )
V_64 = F_27 () ;
#endif
V_67 = V_50 ;
V_68 = V_51 ;
F_28 () ;
#ifdef F_29
F_4 () ;
#endif
if ( V_23 == NULL )
V_23 = F_30 ( V_69 , V_70 ) ;
V_71 = 0 ;
#ifdef F_5
V_15 = 0 ;
#endif
V_16 = 0 ;
V_50 -- ;
V_51 ++ ;
while ( V_50 >= 1 )
{
if ( ( strcmp ( * V_51 , L_36 ) == 0 ) ||
( strcmp ( * V_51 , L_37 ) == 0 ) )
{
if ( -- V_50 < 1 ) goto V_72;
if ( ! F_31 ( * ( ++ V_51 ) , & V_52 ) )
goto V_72;
}
else if ( strcmp ( * V_51 , L_38 ) == 0 )
{
V_8 = V_73 | V_74 ;
if ( -- V_50 < 1 ) goto V_72;
V_71 = atoi ( * ( ++ V_51 ) ) ;
F_7 ( V_23 , L_39 , V_71 ) ;
}
else if ( strcmp ( * V_51 , L_40 ) == 0 )
{
V_8 = V_73 | V_75 |
V_74 ;
if ( -- V_50 < 1 ) goto V_72;
V_71 = atoi ( * ( ++ V_51 ) ) ;
F_7 ( V_23 , L_41 , V_71 ) ;
}
else if ( strcmp ( * V_51 , L_42 ) == 0 )
{
if ( -- V_50 < 1 ) goto V_72;
V_55 = * ( ++ V_51 ) ;
}
else if ( strcmp ( * V_51 , L_43 ) == 0 )
{
if ( -- V_50 < 1 ) goto V_72;
V_12 = * ( ++ V_51 ) ;
}
else if ( strcmp ( * V_51 , L_44 ) == 0 )
{
if ( -- V_50 < 1 ) goto V_72;
V_14 = * ( ++ V_51 ) ;
}
else if ( strcmp ( * V_51 , L_45 ) == 0 )
{
if ( -- V_50 < 1 ) goto V_72;
V_56 = * ( ++ V_51 ) ;
}
else if ( strcmp ( * V_51 , L_46 ) == 0 )
{
if ( -- V_50 < 1 ) goto V_72;
V_10 = * ( ++ V_51 ) ;
}
else if ( strcmp ( * V_51 , L_47 ) == 0 )
{
if ( -- V_50 < 1 ) goto V_72;
V_11 = * ( ++ V_51 ) ;
}
else if ( strcmp ( * V_51 , L_48 ) == 0 )
{
V_62 = 1 ;
}
else if ( strcmp ( * V_51 , L_49 ) == 0 )
{
if ( -- V_50 < 1 ) goto V_72;
V_53 = * ( ++ V_51 ) ;
}
else if ( strcmp ( * V_51 , L_50 ) == 0 )
{
if ( -- V_50 < 1 ) goto V_72;
V_7 = * ( ++ V_51 ) ;
}
else if ( strcmp ( * V_51 , L_51 ) == 0 )
{
if ( -- V_50 < 1 ) goto V_72;
V_54 = * ( ++ V_51 ) ;
}
#ifdef F_5
else if ( strcmp ( * V_51 , L_52 ) == 0 )
{ V_15 = 1 ; }
#endif
else if ( strcmp ( * V_51 , L_53 ) == 0 )
{
#ifdef F_5
V_15 = 1 ;
#endif
V_16 = 1 ;
}
else if ( strcmp ( * V_51 , L_54 ) == 0 )
{ V_20 = 1 ; }
else if ( strcmp ( * V_51 , L_55 ) == 0 )
{ V_22 = 1 ; }
else if ( strcmp ( * V_51 , L_56 ) == 0 )
{ V_63 = 1 ; }
else if ( strcmp ( * V_51 , L_57 ) == 0 )
{ V_76 = 1 ; }
else if ( strcmp ( * V_51 , L_58 ) == 0 )
{ V_21 = 1 ; }
else if ( strcmp ( * V_51 , L_59 ) == 0 )
{ V_58 = 1 ; }
else if ( strcmp ( * V_51 , L_60 ) == 0 )
{ V_60 = 1 ; }
else if ( strcmp ( * V_51 , L_61 ) == 0 )
{ V_61 = 1 ; }
else if ( strcmp ( * V_51 , L_62 ) == 0 )
{ V_18 = 1 ; }
else if ( strcmp ( * V_51 , L_63 ) == 0 )
{ V_18 = 2 ; }
else if ( strcmp ( * V_51 , L_64 ) == 0 )
{ V_59 |= V_77 ; }
else if ( strcmp ( * V_51 , L_65 ) == 0 )
{ V_59 |= V_78 ; }
else if ( strcmp ( * V_51 , L_66 ) == 0 )
{ V_59 |= V_79 ; }
#ifndef V_65
else if ( strcmp ( * V_51 , L_67 ) == 0 )
{ V_64 = F_27 () ; }
#endif
#ifndef V_66
else if ( strcmp ( * V_51 , L_68 ) == 0 )
{ V_64 = F_26 () ; }
#endif
#ifndef F_32
else if ( strcmp ( * V_51 , L_69 ) == 0 )
{ V_64 = F_33 () ; }
#endif
else
{
F_7 ( V_23 , L_70 , * V_51 ) ;
V_57 = 1 ;
break;
}
V_50 -- ;
V_51 ++ ;
}
if ( V_57 )
{
V_72:
F_6 () ;
goto V_80;
}
F_34 ( NULL , V_23 , 0 ) ;
if ( V_19 == NULL )
{
if ( V_21 && ! V_20 )
{
V_19 = F_35 ( F_36 () ) ;
}
else
{
if ( V_19 == NULL )
V_19 = F_30 ( stdout , V_70 ) ;
}
}
#if ! F_24 ( V_81 ) || ! F_24 ( V_82 )
if ( V_62 )
#endif
{
V_12 = NULL ;
V_14 = NULL ;
V_10 = NULL ;
V_11 = NULL ;
}
F_37 () ;
F_38 () ;
V_17 = F_39 ( V_64 ) ;
if ( V_17 == NULL )
{
F_40 ( V_23 ) ;
goto V_80;
}
F_41 ( V_17 , 1 ) ;
if ( V_58 ) F_42 ( V_17 , V_83 ) ;
if ( V_22 ) F_42 ( V_17 , V_84 ) ;
F_42 ( V_17 , V_59 ) ;
if ( V_22 ) F_42 ( V_17 , V_85 ) ;
if ( V_63 ) F_43 ( V_17 , V_86 ) ;
F_44 ( V_17 , 128 ) ;
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
if ( ( ! F_45 ( V_17 , V_54 , V_53 ) ) ||
( ! F_46 ( V_17 ) ) )
{
F_40 ( V_23 ) ;
}
#ifndef F_8
if ( ! V_61 )
{
V_1 = F_47 ( V_56 ? V_56 : V_12 ) ;
if ( V_1 != NULL )
{
F_7 ( V_19 , L_71 ) ;
}
else
{
F_7 ( V_19 , L_72 ) ;
V_1 = F_1 () ;
}
( void ) F_48 ( V_19 ) ;
F_49 ( V_17 , V_1 ) ;
F_50 ( V_1 ) ;
}
#endif
if ( ! F_51 ( V_17 , V_12 , V_14 ) )
goto V_80;
if ( V_10 != NULL )
{
if ( ! F_51 ( V_17 , V_10 , V_11 ) )
goto V_80;
}
#ifndef V_81
#if 1
F_52 ( V_17 , V_87 ) ;
#else
if ( ! V_60 && F_53 ( V_17 ) )
{
T_6 * V_88 ;
F_7 ( V_19 , L_73 ) ;
F_48 ( V_19 ) ;
V_88 = F_54 ( 512 , V_89 , NULL ) ;
if ( ! F_55 ( V_17 , V_88 ) )
{
F_40 ( V_23 ) ;
goto V_80;
}
F_56 ( V_88 ) ;
F_7 ( V_19 , L_2 ) ;
}
#endif
#endif
if ( V_7 != NULL )
if( ! F_57 ( V_17 , V_7 ) ) {
F_7 ( V_23 , L_74 ) ;
F_40 ( V_23 ) ;
goto V_80;
}
F_58 ( V_17 , V_8 , V_90 ) ;
F_59 ( V_17 , ( void * ) & V_91 ,
sizeof V_91 ) ;
if ( V_54 != NULL )
F_60 ( V_17 , F_61 ( V_54 ) ) ;
F_7 ( V_19 , L_75 ) ;
if ( V_18 )
F_62 ( V_52 , & V_6 , V_92 , V_55 ) ;
else
F_62 ( V_52 , & V_6 , V_93 , V_55 ) ;
F_63 ( V_19 , V_17 ) ;
V_37 = 0 ;
V_80:
if ( V_17 != NULL ) F_64 ( V_17 ) ;
if ( V_19 != NULL )
{
F_65 ( V_19 ) ;
V_19 = NULL ;
}
EXIT ( V_37 ) ;
}
static void F_63 ( T_3 * V_94 , T_7 * V_95 )
{
F_7 ( V_94 , L_76 ,
F_66 ( V_95 ) ) ;
F_7 ( V_94 , L_77 ,
F_67 ( V_95 ) ) ;
F_7 ( V_94 , L_78 ,
F_68 ( V_95 ) ) ;
F_7 ( V_94 , L_79 ,
F_69 ( V_95 ) ) ;
F_7 ( V_94 , L_80 ,
F_70 ( V_95 ) ) ;
F_7 ( V_94 , L_81 ,
F_71 ( V_95 ) ) ;
F_7 ( V_94 , L_82 ,
F_72 ( V_95 ) ) ;
F_7 ( V_94 , L_83 , F_73 ( V_95 ) ) ;
F_7 ( V_94 , L_84 , F_74 ( V_95 ) ) ;
F_7 ( V_94 , L_85 , F_75 ( V_95 ) ) ;
F_7 ( V_94 , L_86 , F_76 ( V_95 ) ) ;
F_7 ( V_94 , L_87 ,
F_77 ( V_95 ) ,
F_78 ( V_95 ) ) ;
}
static int V_93 ( char * V_96 , int V_97 , unsigned char * V_55 )
{
char * V_46 = NULL ;
T_8 V_98 ;
int V_37 = 1 , V_99 ;
int V_100 , V_48 ;
unsigned long V_101 ;
T_9 * V_102 = NULL ;
T_3 * V_103 ;
#ifdef F_79
struct V_104 V_105 ;
#endif
if ( ( V_46 = F_11 ( V_106 ) ) == NULL )
{
F_7 ( V_23 , L_88 ) ;
goto V_107;
}
#ifdef F_5
if ( V_15 )
{
unsigned long V_108 = 1 ;
if ( ! V_21 )
F_7 ( V_23 , L_89 ) ;
if ( F_80 ( V_97 , F_5 , & V_108 ) < 0 )
F_40 ( V_23 ) ;
}
#endif
if ( V_102 == NULL ) {
V_102 = F_81 ( V_17 ) ;
if( V_55 )
F_82 ( V_102 , V_55 ,
strlen ( ( char * ) V_55 ) ) ;
}
F_83 ( V_102 ) ;
V_103 = F_84 ( V_97 , V_70 ) ;
if ( V_16 )
{
T_3 * V_109 ;
V_109 = F_35 ( F_85 () ) ;
V_103 = F_86 ( V_109 , V_103 ) ;
}
F_87 ( V_102 , V_103 , V_103 ) ;
F_88 ( V_102 ) ;
if ( V_20 )
{
V_102 -> V_110 = 1 ;
F_89 ( F_90 ( V_102 ) , V_111 ) ;
F_91 ( F_90 ( V_102 ) , V_19 ) ;
}
V_99 = V_97 + 1 ;
for (; ; )
{
int V_112 ;
int V_113 ;
V_112 = 0 ;
V_113 = F_92 ( V_102 ) ;
if ( ! V_113 )
{
F_93 ( & V_98 ) ;
#ifndef F_79
F_94 ( fileno ( V_114 ) , & V_98 ) ;
#endif
F_94 ( V_97 , & V_98 ) ;
#ifdef F_79
V_105 . V_115 = 1 ;
V_105 . V_116 = 0 ;
V_48 = F_95 ( V_99 , ( void * ) & V_98 , NULL , NULL , & V_105 ) ;
if( ( V_48 < 0 ) || ( ! V_48 && ! F_96 () ) ) continue;
if( F_96 () )
V_112 = 1 ;
#else
V_48 = F_95 ( V_99 , ( void * ) & V_98 , NULL , NULL , NULL ) ;
if ( V_48 <= 0 ) continue;
if ( F_97 ( fileno ( V_114 ) , & V_98 ) )
V_112 = 1 ;
#endif
if ( F_97 ( V_97 , & V_98 ) )
V_113 = 1 ;
}
if ( V_112 )
{
if ( V_76 )
{
int V_117 , V_118 ;
V_48 = F_98 ( fileno ( V_114 ) , V_46 , V_106 / 2 ) ;
V_118 = 0 ;
for ( V_117 = 0 ; V_117 < V_48 ; V_117 ++ )
if ( V_46 [ V_117 ] == '\n' )
V_118 ++ ;
for ( V_117 = V_48 - 1 ; V_117 >= 0 ; V_117 -- )
{
V_46 [ V_117 + V_118 ] = V_46 [ V_117 ] ;
if ( V_46 [ V_117 ] == '\n' )
{
V_118 -- ;
V_48 ++ ;
V_46 [ V_117 + V_118 ] = '\r' ;
}
}
assert ( V_118 == 0 ) ;
}
else
V_48 = F_98 ( fileno ( V_114 ) , V_46 , V_106 ) ;
if ( ! V_21 )
{
if ( ( V_48 <= 0 ) || ( V_46 [ 0 ] == 'Q' ) )
{
F_7 ( V_19 , L_90 ) ;
F_99 ( V_97 ) ;
F_100 () ;
V_37 = - 11 ;
goto V_107;
}
if ( ( V_48 <= 0 ) || ( V_46 [ 0 ] == 'q' ) )
{
F_7 ( V_19 , L_90 ) ;
F_99 ( V_97 ) ;
goto V_107;
}
if ( ( V_46 [ 0 ] == 'r' ) &&
( ( V_46 [ 1 ] == '\n' ) || ( V_46 [ 1 ] == '\r' ) ) )
{
F_101 ( V_102 ) ;
V_48 = F_102 ( V_102 ) ;
printf ( L_91 , V_48 ) ;
V_48 = 0 ;
continue;
}
if ( ( V_46 [ 0 ] == 'R' ) &&
( ( V_46 [ 1 ] == '\n' ) || ( V_46 [ 1 ] == '\r' ) ) )
{
F_103 ( V_102 ,
V_73 | V_74 , NULL ) ;
F_101 ( V_102 ) ;
V_48 = F_102 ( V_102 ) ;
printf ( L_91 , V_48 ) ;
V_48 = 0 ;
continue;
}
if ( V_46 [ 0 ] == 'P' )
{
static char * V_49 = L_92 ;
F_19 ( F_104 ( V_102 ) , V_49 , strlen ( V_49 ) ) ;
}
if ( V_46 [ 0 ] == 'S' )
{
F_63 ( V_19 , F_105 ( V_102 ) ) ;
}
}
#ifdef F_106
F_18 ( V_46 , V_46 , V_48 ) ;
#endif
V_101 = V_100 = 0 ;
for (; ; )
{
#ifdef F_107
{ static V_119 = 0 ; if ( ++ V_119 == 100 ) { V_119 = 0 ; F_101 ( V_102 ) ; } }
#endif
V_100 = F_108 ( V_102 , & ( V_46 [ V_101 ] ) , ( unsigned int ) V_48 ) ;
switch ( F_109 ( V_102 , V_100 ) )
{
case V_120 :
break;
case V_121 :
case V_122 :
case V_123 :
F_7 ( V_19 , L_93 ) ;
break;
case V_124 :
case V_125 :
F_7 ( V_19 , L_94 ) ;
F_40 ( V_23 ) ;
V_37 = 1 ;
goto V_107;
case V_126 :
F_7 ( V_19 , L_90 ) ;
V_37 = 1 ;
goto V_107;
}
V_101 += V_100 ;
V_48 -= V_100 ;
if ( V_48 <= 0 ) break;
}
}
if ( V_113 )
{
if ( ! F_110 ( V_102 ) )
{
V_48 = F_111 ( V_102 ) ;
if ( V_48 < 0 )
{
V_37 = 0 ;
goto V_107;
}
else if ( V_48 == 0 )
{
V_37 = 1 ;
goto V_107;
}
}
else
{
V_127:
V_48 = F_112 ( V_102 , ( char * ) V_46 , V_106 ) ;
switch ( F_109 ( V_102 , V_48 ) )
{
case V_120 :
#ifdef F_106
F_16 ( V_46 , V_46 , V_48 ) ;
#endif
F_113 ( fileno ( stdout ) , V_46 ,
( unsigned int ) V_48 ) ;
if ( F_92 ( V_102 ) ) goto V_127;
break;
case V_121 :
case V_122 :
case V_123 :
F_7 ( V_19 , L_95 ) ;
break;
case V_124 :
case V_125 :
F_7 ( V_19 , L_94 ) ;
F_40 ( V_23 ) ;
V_37 = 1 ;
goto V_107;
case V_126 :
F_7 ( V_19 , L_90 ) ;
V_37 = 1 ;
goto V_107;
}
}
}
}
V_107:
F_7 ( V_19 , L_96 ) ;
#if 1
F_114 ( V_102 , V_128 | V_129 ) ;
#else
F_115 ( V_102 ) ;
#endif
if ( V_102 != NULL ) F_116 ( V_102 ) ;
F_7 ( V_19 , L_97 ) ;
if ( V_46 != NULL )
{
memset ( V_46 , 0 , V_106 ) ;
F_13 ( V_46 ) ;
}
if ( V_37 >= 0 )
F_7 ( V_19 , L_75 ) ;
return ( V_37 ) ;
}
static void F_100 ( void )
{
F_7 ( V_23 , L_98 ) ;
if ( V_6 >= 0 )
{
F_117 ( V_6 ) ;
}
}
static int F_111 ( T_9 * V_102 )
{
int V_48 ;
const char * V_49 ;
T_10 * V_130 ;
long V_131 ;
T_11 char V_46 [ V_132 ] ;
if ( ( V_48 = F_118 ( V_102 ) ) <= 0 )
{
if ( F_119 ( V_48 ) )
{
F_7 ( V_19 , L_99 ) ;
return ( 1 ) ;
}
F_7 ( V_23 , L_94 ) ;
V_131 = F_120 ( V_102 ) ;
if ( V_131 != V_133 )
{
F_7 ( V_23 , L_100 ,
F_121 ( V_131 ) ) ;
}
else
F_40 ( V_23 ) ;
return ( 0 ) ;
}
F_122 ( V_19 , F_123 ( V_102 ) ) ;
V_130 = F_124 ( V_102 ) ;
if ( V_130 != NULL )
{
F_7 ( V_19 , L_101 ) ;
F_125 ( V_19 , V_130 ) ;
F_126 ( F_127 ( V_130 ) , V_46 , V_132 ) ;
F_7 ( V_19 , L_102 , V_46 ) ;
F_126 ( F_128 ( V_130 ) , V_46 , V_132 ) ;
F_7 ( V_19 , L_103 , V_46 ) ;
F_129 ( V_130 ) ;
}
if ( F_130 ( V_102 , V_46 , V_132 ) != NULL )
F_7 ( V_19 , L_104 , V_46 ) ;
V_49 = F_131 ( F_132 ( V_102 ) ) ;
F_7 ( V_19 , L_105 , ( V_49 != NULL ) ? V_49 : L_106 ) ;
if ( V_102 -> V_134 ) F_7 ( V_19 , L_107 ) ;
if ( F_133 ( V_102 , V_135 , 0 , NULL ) &
V_136 )
F_7 ( V_19 , L_108 ) ;
return ( 1 ) ;
}
static T_1 * F_47 ( char * V_56 )
{
T_1 * V_37 = NULL ;
T_3 * V_94 ;
if ( ( V_94 = F_134 ( V_56 , L_109 ) ) == NULL )
goto V_107;
V_37 = F_135 ( V_94 , NULL , NULL , NULL ) ;
V_107:
if ( V_94 != NULL ) F_65 ( V_94 ) ;
return ( V_37 ) ;
}
static int V_92 ( char * V_96 , int V_97 , unsigned char * V_55 )
{
char * V_46 = NULL ;
int V_37 = 1 ;
int V_48 , V_117 , V_100 , V_137 , V_138 ;
struct V_139 V_140 ;
T_9 * V_102 ;
T_12 * V_141 ;
T_3 * V_142 , * V_143 , * V_103 ;
long V_144 ;
V_46 = F_11 ( V_106 ) ;
if ( V_46 == NULL ) return ( 0 ) ;
V_142 = F_35 ( F_136 () ) ;
V_143 = F_35 ( F_137 () ) ;
if ( ( V_142 == NULL ) || ( V_143 == NULL ) ) goto V_107;
#ifdef F_5
if ( V_15 )
{
unsigned long V_108 = 1 ;
if ( ! V_21 )
F_7 ( V_23 , L_89 ) ;
if ( F_80 ( V_97 , F_5 , & V_108 ) < 0 )
F_40 ( V_23 ) ;
}
#endif
if ( ! F_138 ( V_142 , V_106 ) ) goto V_107;
if ( ( V_102 = F_81 ( V_17 ) ) == NULL ) goto V_107;
if( V_55 ) F_82 ( V_102 , V_55 ,
strlen ( ( char * ) V_55 ) ) ;
V_103 = F_84 ( V_97 , V_70 ) ;
if ( V_16 )
{
T_3 * V_109 ;
V_109 = F_35 ( F_85 () ) ;
V_103 = F_86 ( V_109 , V_103 ) ;
}
F_87 ( V_102 , V_103 , V_103 ) ;
F_88 ( V_102 ) ;
F_139 ( V_143 , V_102 , V_145 ) ;
F_86 ( V_142 , V_143 ) ;
#ifdef F_106
V_142 = F_86 ( F_35 ( F_9 () ) , V_142 ) ;
#endif
if ( V_20 )
{
V_102 -> V_110 = 1 ;
F_89 ( F_90 ( V_102 ) , V_111 ) ;
F_91 ( F_90 ( V_102 ) , V_19 ) ;
}
V_137 = 0 ;
for (; ; )
{
if ( V_22 )
{
V_48 = F_118 ( V_102 ) ;
switch ( F_109 ( V_102 , V_48 ) )
{
case V_120 :
break;
case V_121 :
case V_122 :
case V_123 :
continue;
case V_124 :
case V_125 :
case V_126 :
V_37 = 1 ;
goto V_107;
}
F_101 ( V_102 ) ;
F_108 ( V_102 , NULL , 0 ) ;
}
V_48 = F_140 ( V_142 , V_46 , V_106 - 1 ) ;
if ( V_48 < 0 )
{
if ( ! F_141 ( V_142 ) )
{
if ( ! V_21 )
F_40 ( V_23 ) ;
goto V_107;
}
else
{
F_7 ( V_19 , L_110 ) ;
#ifndef F_142
F_143 ( 1 ) ;
#endif
continue;
}
}
else if ( V_48 == 0 )
{
V_37 = 1 ;
goto V_80;
}
if ( ( ( V_18 == 1 ) && ( strncmp ( L_111 , V_46 , 4 ) == 0 ) ) ||
( ( V_18 == 2 ) && ( strncmp ( L_112 , V_46 , 10 ) == 0 ) ) )
{
char * V_2 ;
T_10 * V_130 ;
F_144 ( T_12 ) * V_146 ;
static char * V_147 = L_113 ;
F_145 ( V_142 , L_114 ) ;
F_145 ( V_142 , L_115 ) ;
F_145 ( V_142 , L_116 ) ;
F_145 ( V_142 , L_2 ) ;
for ( V_48 = 0 ; V_48 < V_67 ; V_48 ++ )
{
F_145 ( V_142 , V_68 [ V_48 ] ) ;
F_19 ( V_142 , L_117 , 1 ) ;
}
F_145 ( V_142 , L_2 ) ;
F_7 ( V_142 , L_118 ) ;
V_146 = F_146 ( V_102 ) ;
V_117 = F_147 ( V_146 ) ;
for ( V_48 = 0 ; V_48 < V_117 ; V_48 ++ )
{
V_141 = F_148 ( V_146 , V_48 ) ;
F_7 ( V_142 , L_119 ,
F_149 ( V_141 ) ,
F_131 ( V_141 ) ) ;
if ( ( ( ( V_48 + 1 ) % 2 ) == 0 ) && ( V_48 + 1 != V_117 ) )
F_145 ( V_142 , L_2 ) ;
}
F_145 ( V_142 , L_2 ) ;
V_2 = F_130 ( V_102 , V_46 , V_106 ) ;
if ( V_2 != NULL )
{
F_7 ( V_142 , L_120 ) ;
V_117 = V_48 = 0 ;
while ( * V_2 )
{
if ( * V_2 == ':' )
{
F_19 ( V_142 , V_147 , 26 - V_117 ) ;
V_48 ++ ;
V_117 = 0 ;
F_19 ( V_142 , ( ( V_48 % 3 ) ? L_117 : L_2 ) , 1 ) ;
}
else
{
F_19 ( V_142 , V_2 , 1 ) ;
V_117 ++ ;
}
V_2 ++ ;
}
F_145 ( V_142 , L_2 ) ;
}
F_7 ( V_142 , ( ( V_102 -> V_134 )
? L_121
: L_122 ) ) ;
V_141 = F_132 ( V_102 ) ;
F_7 ( V_142 , L_123 ,
F_149 ( V_141 ) ,
F_131 ( V_141 ) ) ;
F_150 ( V_142 , F_123 ( V_102 ) ) ;
F_7 ( V_142 , L_124 ) ;
F_63 ( V_142 , F_105 ( V_102 ) ) ;
F_7 ( V_142 , L_124 ) ;
V_130 = F_124 ( V_102 ) ;
if ( V_130 != NULL )
{
F_7 ( V_142 , L_101 ) ;
F_151 ( V_142 , V_130 ) ;
F_125 ( V_142 , V_130 ) ;
}
else
F_145 ( V_142 , L_125 ) ;
F_145 ( V_142 , L_126 ) ;
break;
}
else if ( ( V_18 == 2 ) && ( strncmp ( L_127 , V_46 , 5 ) == 0 ) )
{
T_3 * V_148 ;
char * V_2 , * V_149 ;
static char * V_150 = L_128 ;
V_2 = & ( V_46 [ 5 ] ) ;
V_138 = 0 ;
for ( V_149 = V_2 ; * V_149 != '\0' ; V_149 ++ )
{
if ( V_149 [ 0 ] == ' ' ) break;
if ( ( V_149 [ 0 ] == '.' ) &&
( strncmp ( & ( V_149 [ - 1 ] ) , L_129 , 4 ) == 0 ) )
V_138 = 1 ;
}
if ( * V_149 == '\0' )
{
F_145 ( V_142 , V_150 ) ;
F_7 ( V_142 , L_130 , V_2 ) ;
break;
}
* V_149 = '\0' ;
if ( V_138 )
{
F_145 ( V_142 , V_150 ) ;
F_7 ( V_142 , L_131 , V_2 ) ;
break;
}
if ( * V_2 == '/' )
{
F_145 ( V_142 , V_150 ) ;
F_7 ( V_142 , L_132 , V_2 ) ;
break;
}
if ( V_149 [ - 1 ] == '/' )
strcat ( V_2 , L_133 ) ;
if ( V_139 ( V_2 , & V_140 ) < 0 )
{
F_145 ( V_142 , V_150 ) ;
F_7 ( V_142 , L_134 , V_2 ) ;
F_40 ( V_142 ) ;
break;
}
if ( F_152 ( V_140 . V_151 ) )
{
strcat ( V_2 , L_135 ) ;
}
if ( ( V_148 = F_134 ( V_2 , L_109 ) ) == NULL )
{
F_145 ( V_142 , V_150 ) ;
F_7 ( V_142 , L_136 , V_2 ) ;
F_40 ( V_142 ) ;
break;
}
if ( ! V_21 )
F_7 ( V_23 , L_137 , V_2 ) ;
V_48 = strlen ( V_2 ) ;
if ( ( ( V_48 > 5 ) && ( strcmp ( & ( V_2 [ V_48 - 5 ] ) , L_138 ) == 0 ) ) ||
( ( V_48 > 4 ) && ( strcmp ( & ( V_2 [ V_48 - 4 ] ) , L_139 ) == 0 ) ) ||
( ( V_48 > 4 ) && ( strcmp ( & ( V_2 [ V_48 - 4 ] ) , L_140 ) == 0 ) ) )
F_145 ( V_142 , L_114 ) ;
else
F_145 ( V_142 , L_128 ) ;
V_144 = 0 ;
for (; ; )
{
V_48 = F_15 ( V_148 , V_46 , V_106 ) ;
if ( V_48 <= 0 ) break;
#ifdef F_107
V_144 += V_48 ;
fprintf ( V_69 , L_141 , V_48 ) ;
if ( V_144 > 3 * 1024 )
{
V_144 = 0 ;
fprintf ( V_69 , L_142 ) ;
F_101 ( V_102 ) ;
}
#endif
for ( V_117 = 0 ; V_117 < V_48 ; )
{
#ifdef F_107
{ static V_119 = 0 ; if ( ++ V_119 == 13 ) { F_101 ( V_102 ) ; } }
#endif
V_100 = F_19 ( V_142 , & ( V_46 [ V_117 ] ) , V_48 - V_117 ) ;
if ( V_100 <= 0 )
{
if ( ! F_141 ( V_142 ) )
goto V_152;
else
{
F_7 ( V_19 , L_143 ) ;
}
}
else
{
V_117 += V_100 ;
}
}
}
V_152:
F_65 ( V_148 ) ;
break;
}
}
for (; ; )
{
V_48 = ( int ) F_48 ( V_142 ) ;
if ( V_48 <= 0 )
{
if ( ! F_141 ( V_142 ) )
break;
}
else
break;
}
V_80:
#if 1
F_114 ( V_102 , V_128 | V_129 ) ;
#else
#endif
V_107:
if ( V_37 >= 0 )
F_7 ( V_19 , L_75 ) ;
if ( V_46 != NULL ) F_13 ( V_46 ) ;
if ( V_142 != NULL ) F_153 ( V_142 ) ;
return ( V_37 ) ;
}
static T_6 T_13 * V_87 ( T_9 * V_97 , int V_153 , int V_154 )
{
static T_6 * V_155 = NULL ;
if ( V_155 == NULL )
{
if ( ! V_21 )
{
F_7 ( V_23 , L_144 , V_154 ) ;
( void ) F_48 ( V_23 ) ;
}
V_155 = F_54 ( V_154 , V_89 , NULL , NULL ) ;
if ( ! V_21 )
{
F_7 ( V_23 , L_2 ) ;
( void ) F_48 ( V_23 ) ;
}
}
return ( V_155 ) ;
}
