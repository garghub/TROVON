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
V_23 = 0 ;
V_24 = NULL ;
}
static void F_6 ( void )
{
F_7 ( V_25 , L_1 ) ;
F_7 ( V_25 , L_2 ) ;
F_7 ( V_25 , L_3 , V_26 ) ;
F_7 ( V_25 , L_4 ) ;
F_7 ( V_25 , L_5 ) ;
F_7 ( V_25 , L_6 ) ;
F_7 ( V_25 , L_7 ) ;
F_7 ( V_25 , L_8 , V_13 ) ;
F_7 ( V_25 , L_9 ) ;
F_7 ( V_25 , L_10 , V_13 ) ;
F_7 ( V_25 , L_11 ) ;
F_7 ( V_25 , L_12 ) ;
F_7 ( V_25 , L_13 ) ;
F_7 ( V_25 , L_14 ) ;
#ifdef F_5
F_7 ( V_25 , L_15 ) ;
#endif
F_7 ( V_25 , L_16 ) ;
F_7 ( V_25 , L_17 ) ;
F_7 ( V_25 , L_18 ) ;
F_7 ( V_25 , L_19 ) ;
F_7 ( V_25 , L_20 ) ;
F_7 ( V_25 , L_21 ) ;
F_7 ( V_25 , L_22 ) ;
F_7 ( V_25 , L_23 ) ;
F_7 ( V_25 , L_24 ) ;
F_7 ( V_25 , L_25 ) ;
F_7 ( V_25 , L_26 ) ;
F_7 ( V_25 , L_27 ) ;
F_7 ( V_25 , L_28 ) ;
F_7 ( V_25 , L_29 ) ;
F_7 ( V_25 , L_30 ) ;
F_7 ( V_25 , L_31 ) ;
F_7 ( V_25 , L_32 ) ;
F_7 ( V_25 , L_33 ) ;
#ifndef F_8
F_7 ( V_25 , L_34 ) ;
#endif
F_7 ( V_25 , L_35 ) ;
F_7 ( V_25 , L_36 ) ;
F_7 ( V_25 , L_37 ) ;
F_7 ( V_25 , L_38 ) ;
F_7 ( V_25 , L_39 ) ;
F_7 ( V_25 , L_40 ) ;
F_7 ( V_25 , L_41 ) ;
F_7 ( V_25 , L_42 , V_27 , V_27 ) ;
}
T_2 * F_9 ()
{
return ( & V_28 ) ;
}
static int F_10 ( T_3 * V_29 )
{
T_4 * V_30 ;
V_30 = ( T_4 * ) F_11 ( sizeof( T_4 ) + 1024 ) ;
V_30 -> V_31 = 1024 ;
V_30 -> V_32 [ 0 ] = '\0' ;
V_29 -> V_33 = ( char * ) V_30 ;
V_29 -> V_34 = 1 ;
V_29 -> V_35 = 0 ;
return ( 1 ) ;
}
static int F_12 ( T_3 * V_36 )
{
if ( V_36 == NULL ) return ( 0 ) ;
if ( V_36 -> V_33 != NULL )
F_13 ( V_36 -> V_33 ) ;
V_36 -> V_33 = NULL ;
V_36 -> V_34 = 0 ;
V_36 -> V_35 = 0 ;
return ( 1 ) ;
}
static int F_14 ( T_3 * V_37 , char * V_38 , int V_39 )
{
int V_40 = 0 ;
if ( V_38 == NULL || V_39 == 0 ) return ( 0 ) ;
if ( V_37 -> V_41 == NULL ) return ( 0 ) ;
V_40 = F_15 ( V_37 -> V_41 , V_38 , V_39 ) ;
if ( V_40 > 0 )
F_16 ( V_38 , V_38 , V_40 ) ;
return ( V_40 ) ;
}
static int F_17 ( T_3 * V_37 , const char * V_42 , int V_43 )
{
T_4 * V_30 ;
int V_40 = 0 ;
int V_44 ;
unsigned char V_45 ;
if ( ( V_42 == NULL ) || ( V_43 <= 0 ) ) return ( 0 ) ;
if ( V_37 -> V_41 == NULL ) return ( 0 ) ;
V_30 = ( T_4 * ) V_37 -> V_33 ;
if ( V_43 > ( V_44 = V_30 -> V_31 ) )
{
V_44 = V_44 + V_44 ;
if ( V_44 < V_43 )
V_44 = V_43 ;
F_13 ( V_30 ) ;
V_30 = ( T_4 * ) F_11 ( sizeof( T_4 ) + V_44 ) ;
V_30 -> V_31 = V_44 ;
V_30 -> V_32 [ 0 ] = '\0' ;
V_37 -> V_33 = ( char * ) V_30 ;
}
F_18 ( V_30 -> V_32 , V_42 , V_43 ) ;
V_40 = F_19 ( V_37 -> V_41 , V_30 -> V_32 , V_43 ) ;
return ( V_40 ) ;
}
static long F_20 ( T_3 * V_37 , int V_46 , long V_44 , void * V_33 )
{
long V_40 ;
if ( V_37 -> V_41 == NULL ) return ( 0 ) ;
switch ( V_46 )
{
case V_47 :
V_40 = 0L ;
break;
default:
V_40 = F_21 ( V_37 -> V_41 , V_46 , V_44 , V_33 ) ;
break;
}
return ( V_40 ) ;
}
static int F_22 ( T_3 * V_48 , char * V_49 , int V_50 )
{
int V_51 , V_40 = 0 ;
if ( V_48 -> V_41 == NULL ) return ( 0 ) ;
for ( V_51 = 0 ; V_51 < V_50 - 1 ; ++ V_51 )
{
V_40 = F_14 ( V_48 , & V_49 [ V_51 ] , 1 ) ;
if ( V_40 <= 0 )
break;
else if ( V_49 [ V_51 ] == '\n' )
{
++ V_51 ;
break;
}
}
if ( V_51 < V_50 )
V_49 [ V_51 ] = '\0' ;
return ( V_40 < 0 && V_51 == 0 ) ? V_40 : V_51 ;
}
static int F_23 ( T_3 * V_48 , const char * V_52 )
{
if ( V_48 -> V_41 == NULL ) return ( 0 ) ;
return F_17 ( V_48 , V_52 , strlen ( V_52 ) ) ;
}
int MAIN ( int V_53 , char * V_54 [] )
{
T_5 * V_55 = NULL ;
int V_56 = 0 ;
short V_57 = V_26 ;
char * V_58 = NULL , * V_59 = NULL ;
char * V_60 = NULL ;
char * V_61 = NULL ;
int V_62 = 0 , V_63 = 0 ;
int V_40 = 1 ;
int V_64 = 0 ;
int V_65 = 0 , V_66 = 0 , V_67 = 0 ;
int V_68 = 0 ;
T_6 * V_69 = NULL ;
T_7 * V_70 = NULL ;
char * V_71 = NULL ;
#if ! F_24 ( V_72 ) && ! F_24 ( V_73 )
V_69 = F_25 () ;
#elif ! F_24 ( V_73 )
V_69 = F_26 () ;
#elif ! F_24 ( V_72 )
V_69 = F_27 () ;
#endif
V_74 = V_53 ;
V_75 = V_54 ;
F_28 () ;
#ifdef F_29
F_4 () ;
#endif
if ( V_25 == NULL )
V_25 = F_30 ( V_76 , V_77 ) ;
if ( ! F_31 ( V_25 , NULL ) )
goto V_78;
V_79 = 0 ;
#ifdef F_5
V_15 = 0 ;
#endif
V_16 = 0 ;
V_53 -- ;
V_54 ++ ;
while ( V_53 >= 1 )
{
if ( ( strcmp ( * V_54 , L_43 ) == 0 ) ||
( strcmp ( * V_54 , L_44 ) == 0 ) )
{
if ( -- V_53 < 1 ) goto V_80;
if ( ! F_32 ( * ( ++ V_54 ) , & V_57 ) )
goto V_80;
}
else if ( strcmp ( * V_54 , L_45 ) == 0 )
{
V_8 = V_81 | V_82 ;
if ( -- V_53 < 1 ) goto V_80;
V_79 = atoi ( * ( ++ V_54 ) ) ;
F_7 ( V_25 , L_46 , V_79 ) ;
}
else if ( strcmp ( * V_54 , L_47 ) == 0 )
{
V_8 = V_81 | V_83 |
V_82 ;
if ( -- V_53 < 1 ) goto V_80;
V_79 = atoi ( * ( ++ V_54 ) ) ;
F_7 ( V_25 , L_48 , V_79 ) ;
}
else if ( strcmp ( * V_54 , L_49 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_80;
V_60 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_50 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_80;
V_12 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_51 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_80;
V_14 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_52 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_80;
V_61 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_53 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_80;
V_10 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_54 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_80;
V_11 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_55 ) == 0 )
{
V_67 = 1 ;
}
else if ( strcmp ( * V_54 , L_56 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_80;
V_58 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_57 ) == 0 )
{
V_56 |= V_84 ;
}
else if ( strcmp ( * V_54 , L_57 ) == 0 )
{
V_56 |= V_84 | V_85 ;
}
else if ( strcmp ( * V_54 , L_58 ) == 0 )
{ V_64 |= V_86 ; }
else if ( strcmp ( * V_54 , L_59 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_80;
V_7 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_60 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_80;
V_59 = * ( ++ V_54 ) ;
}
#ifdef F_5
else if ( strcmp ( * V_54 , L_61 ) == 0 )
{ V_15 = 1 ; }
#endif
else if ( strcmp ( * V_54 , L_62 ) == 0 )
{
#ifdef F_5
V_15 = 1 ;
#endif
V_16 = 1 ;
}
else if ( strcmp ( * V_54 , L_63 ) == 0 )
{ V_20 = 1 ; }
else if ( strcmp ( * V_54 , L_64 ) == 0 )
{ V_21 = 1 ; }
else if ( strcmp ( * V_54 , L_65 ) == 0 )
{ V_23 = 1 ; }
else if ( strcmp ( * V_54 , L_66 ) == 0 )
{ V_68 = 1 ; }
else if ( strcmp ( * V_54 , L_67 ) == 0 )
{ V_87 = 1 ; }
else if ( strcmp ( * V_54 , L_68 ) == 0 )
{ V_22 = 1 ; }
else if ( strcmp ( * V_54 , L_69 ) == 0 )
{ V_63 = 1 ; }
else if ( strcmp ( * V_54 , L_70 ) == 0 )
{ V_65 = 1 ; }
else if ( strcmp ( * V_54 , L_71 ) == 0 )
{ V_66 = 1 ; }
else if ( strcmp ( * V_54 , L_72 ) == 0 )
{ V_18 = 1 ; }
else if ( strcmp ( * V_54 , L_73 ) == 0 )
{ V_18 = 2 ; }
else if ( strcmp ( * V_54 , L_74 ) == 0 )
{ V_18 = 3 ; }
else if ( strcmp ( * V_54 , L_75 ) == 0 )
{ V_64 |= V_88 ; }
else if ( strcmp ( * V_54 , L_76 ) == 0 )
{ V_64 |= V_89 ; }
else if ( strcmp ( * V_54 , L_77 ) == 0 )
{ V_64 |= V_90 ; }
#ifndef V_72
else if ( strcmp ( * V_54 , L_78 ) == 0 )
{ V_69 = F_27 () ; }
#endif
#ifndef V_73
else if ( strcmp ( * V_54 , L_79 ) == 0 )
{ V_69 = F_26 () ; }
#endif
#ifndef F_33
else if ( strcmp ( * V_54 , L_80 ) == 0 )
{ V_69 = F_34 () ; }
#endif
else if ( strcmp ( * V_54 , L_81 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_80;
V_91 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_82 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_80;
V_24 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_83 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_80;
V_71 = * ( ++ V_54 ) ;
}
else
{
F_7 ( V_25 , L_84 , * V_54 ) ;
V_62 = 1 ;
break;
}
V_53 -- ;
V_54 ++ ;
}
if ( V_62 )
{
V_80:
F_6 () ;
goto V_78;
}
F_35 () ;
F_36 () ;
V_70 = F_37 ( V_25 , V_24 , 1 ) ;
if ( ! F_38 ( NULL , V_25 , 1 ) && V_71 == NULL
&& ! F_39 () )
{
F_7 ( V_25 , L_85 ) ;
}
if ( V_71 != NULL )
F_7 ( V_25 , L_86 ,
F_40 ( V_71 ) ) ;
if ( V_19 == NULL )
{
if ( V_22 && ! V_20 && ! V_21 )
{
V_19 = F_41 ( F_42 () ) ;
}
else
{
if ( V_19 == NULL )
V_19 = F_30 ( stdout , V_77 ) ;
}
}
#if ! F_24 ( V_92 ) || ! F_24 ( V_93 )
if ( V_67 )
#endif
{
V_12 = NULL ;
V_14 = NULL ;
V_10 = NULL ;
V_11 = NULL ;
}
V_17 = F_43 ( V_69 ) ;
if ( V_17 == NULL )
{
F_44 ( V_25 ) ;
goto V_78;
}
if ( V_91 )
{
if( strlen ( V_91 ) >= 32 )
F_7 ( V_25 ,
L_87 ) ;
else if( strlen ( V_91 ) >= 16 )
F_7 ( V_25 ,
L_88 ) ;
if( ! F_45 ( V_17 , V_94 ) )
{
F_7 ( V_25 , L_89 ) ;
F_44 ( V_25 ) ;
goto V_78;
}
F_7 ( V_25 , L_90 , V_91 ) ;
}
F_46 ( V_17 , 1 ) ;
if ( V_63 ) F_47 ( V_17 , V_95 ) ;
if ( V_23 ) F_47 ( V_17 , V_96 ) ;
F_47 ( V_17 , V_64 ) ;
if ( V_68 ) F_48 ( V_17 , V_97 ) ;
F_49 ( V_17 , 128 ) ;
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
if ( ( ! F_50 ( V_17 , V_59 , V_58 ) ) ||
( ! F_51 ( V_17 ) ) )
{
F_44 ( V_25 ) ;
}
V_55 = F_52 ( V_17 ) ;
F_53 ( V_55 , V_56 ) ;
#ifndef F_8
if ( ! V_66 )
{
T_1 * V_1 = NULL ;
if ( V_61 )
V_1 = F_54 ( V_61 ) ;
else if ( V_12 )
V_1 = F_54 ( V_12 ) ;
if ( V_1 != NULL )
{
F_7 ( V_19 , L_91 ) ;
}
else
{
F_7 ( V_19 , L_92 ) ;
V_1 = F_1 () ;
}
( void ) F_55 ( V_19 ) ;
F_56 ( V_17 , V_1 ) ;
F_57 ( V_1 ) ;
}
#endif
if ( ! F_58 ( V_17 , V_12 , V_14 ) )
goto V_78;
if ( V_10 != NULL )
{
if ( ! F_58 ( V_17 , V_10 , V_11 ) )
goto V_78;
}
#ifndef V_92
#if 1
if ( ! V_65 )
F_59 ( V_17 , V_98 ) ;
#else
if ( ! V_65 && F_60 ( V_17 ) )
{
T_8 * V_99 ;
F_7 ( V_19 , L_93 ) ;
F_55 ( V_19 ) ;
V_99 = F_61 ( 512 , V_100 , NULL ) ;
if ( ! F_62 ( V_17 , V_99 ) )
{
F_44 ( V_25 ) ;
goto V_78;
}
F_63 ( V_99 ) ;
F_7 ( V_19 , L_2 ) ;
}
#endif
#endif
if ( V_7 != NULL )
if( ! F_64 ( V_17 , V_7 ) ) {
F_7 ( V_25 , L_94 ) ;
F_44 ( V_25 ) ;
goto V_78;
}
F_65 ( V_17 , V_8 , V_101 ) ;
F_66 ( V_17 , ( void * ) & V_102 ,
sizeof V_102 ) ;
if ( V_59 != NULL )
F_67 ( V_17 , F_68 ( V_59 ) ) ;
F_7 ( V_19 , L_95 ) ;
if ( V_18 )
F_69 ( V_57 , & V_6 , V_103 , V_60 ) ;
else
F_69 ( V_57 , & V_6 , V_104 , V_60 ) ;
F_70 ( V_19 , V_17 ) ;
V_40 = 0 ;
V_78:
if ( V_17 != NULL ) F_71 ( V_17 ) ;
if ( V_19 != NULL )
{
F_72 ( V_19 ) ;
V_19 = NULL ;
}
F_73 () ;
F_74 ( V_40 ) ;
}
static void F_70 ( T_3 * V_105 , T_9 * V_106 )
{
F_7 ( V_105 , L_96 ,
F_75 ( V_106 ) ) ;
F_7 ( V_105 , L_97 ,
F_76 ( V_106 ) ) ;
F_7 ( V_105 , L_98 ,
F_77 ( V_106 ) ) ;
F_7 ( V_105 , L_99 ,
F_78 ( V_106 ) ) ;
F_7 ( V_105 , L_100 ,
F_79 ( V_106 ) ) ;
F_7 ( V_105 , L_101 ,
F_80 ( V_106 ) ) ;
F_7 ( V_105 , L_102 ,
F_81 ( V_106 ) ) ;
F_7 ( V_105 , L_103 , F_82 ( V_106 ) ) ;
F_7 ( V_105 , L_104 , F_83 ( V_106 ) ) ;
F_7 ( V_105 , L_105 , F_84 ( V_106 ) ) ;
F_7 ( V_105 , L_106 , F_85 ( V_106 ) ) ;
F_7 ( V_105 , L_107 ,
F_86 ( V_106 ) ,
F_87 ( V_106 ) ) ;
}
static int V_104 ( char * V_107 , int V_108 , unsigned char * V_60 )
{
char * V_49 = NULL ;
T_10 V_109 ;
int V_40 = 1 , V_110 ;
int V_111 , V_51 ;
unsigned long V_112 ;
T_11 * V_113 = NULL ;
T_3 * V_114 ;
#ifdef F_88
struct V_115 V_116 ;
#endif
if ( ( V_49 = F_11 ( V_117 ) ) == NULL )
{
F_7 ( V_25 , L_108 ) ;
goto V_118;
}
#ifdef F_5
if ( V_15 )
{
unsigned long V_119 = 1 ;
if ( ! V_22 )
F_7 ( V_25 , L_109 ) ;
if ( F_89 ( V_108 , F_5 , & V_119 ) < 0 )
F_44 ( V_25 ) ;
}
#endif
if ( V_113 == NULL ) {
V_113 = F_90 ( V_17 ) ;
#ifndef F_91
if ( ( V_113 -> V_120 = F_92 () ) != NULL )
{
F_93 ( V_113 -> V_120 , V_121 ,
V_122 ) ;
F_93 ( V_113 -> V_120 , V_123 ,
V_124 ) ;
}
#endif
if( V_60 )
F_94 ( V_113 , V_60 ,
strlen ( ( char * ) V_60 ) ) ;
}
F_95 ( V_113 ) ;
V_114 = F_96 ( V_108 , V_77 ) ;
if ( V_16 )
{
T_3 * V_125 ;
V_125 = F_41 ( F_97 () ) ;
V_114 = F_98 ( V_125 , V_114 ) ;
}
F_99 ( V_113 , V_114 , V_114 ) ;
F_100 ( V_113 ) ;
if ( V_20 )
{
V_113 -> V_126 = 1 ;
F_101 ( F_102 ( V_113 ) , V_127 ) ;
F_103 ( F_102 ( V_113 ) , V_19 ) ;
}
if ( V_21 )
{
F_104 ( V_113 , V_128 ) ;
F_105 ( V_113 , V_19 ) ;
}
V_110 = V_108 + 1 ;
for (; ; )
{
int V_129 ;
int V_130 ;
V_129 = 0 ;
V_130 = F_106 ( V_113 ) ;
if ( ! V_130 )
{
F_107 ( & V_109 ) ;
#ifndef F_88
F_108 ( fileno ( V_131 ) , & V_109 ) ;
#endif
F_108 ( V_108 , & V_109 ) ;
#ifdef F_88
V_116 . V_132 = 1 ;
V_116 . V_133 = 0 ;
V_51 = F_109 ( V_110 , ( void * ) & V_109 , NULL , NULL , & V_116 ) ;
if( ( V_51 < 0 ) || ( ! V_51 && ! F_110 () ) ) continue;
if( F_110 () )
V_129 = 1 ;
#else
V_51 = F_109 ( V_110 , ( void * ) & V_109 , NULL , NULL , NULL ) ;
if ( V_51 <= 0 ) continue;
if ( F_111 ( fileno ( V_131 ) , & V_109 ) )
V_129 = 1 ;
#endif
if ( F_111 ( V_108 , & V_109 ) )
V_130 = 1 ;
}
if ( V_129 )
{
if ( V_87 )
{
int V_134 , V_135 ;
V_51 = F_112 ( fileno ( V_131 ) , V_49 , V_117 / 2 ) ;
V_135 = 0 ;
for ( V_134 = 0 ; V_134 < V_51 ; V_134 ++ )
if ( V_49 [ V_134 ] == '\n' )
V_135 ++ ;
for ( V_134 = V_51 - 1 ; V_134 >= 0 ; V_134 -- )
{
V_49 [ V_134 + V_135 ] = V_49 [ V_134 ] ;
if ( V_49 [ V_134 ] == '\n' )
{
V_135 -- ;
V_51 ++ ;
V_49 [ V_134 + V_135 ] = '\r' ;
}
}
assert ( V_135 == 0 ) ;
}
else
V_51 = F_112 ( fileno ( V_131 ) , V_49 , V_117 ) ;
if ( ! V_22 )
{
if ( ( V_51 <= 0 ) || ( V_49 [ 0 ] == 'Q' ) )
{
F_7 ( V_19 , L_110 ) ;
F_113 ( V_108 ) ;
F_114 () ;
V_40 = - 11 ;
goto V_118;
}
if ( ( V_51 <= 0 ) || ( V_49 [ 0 ] == 'q' ) )
{
F_7 ( V_19 , L_110 ) ;
F_113 ( V_108 ) ;
goto V_118;
}
if ( ( V_49 [ 0 ] == 'r' ) &&
( ( V_49 [ 1 ] == '\n' ) || ( V_49 [ 1 ] == '\r' ) ) )
{
F_115 ( V_113 ) ;
V_51 = F_116 ( V_113 ) ;
printf ( L_111 , V_51 ) ;
V_51 = 0 ;
continue;
}
if ( ( V_49 [ 0 ] == 'R' ) &&
( ( V_49 [ 1 ] == '\n' ) || ( V_49 [ 1 ] == '\r' ) ) )
{
F_117 ( V_113 ,
V_81 | V_82 , NULL ) ;
F_115 ( V_113 ) ;
V_51 = F_116 ( V_113 ) ;
printf ( L_111 , V_51 ) ;
V_51 = 0 ;
continue;
}
if ( V_49 [ 0 ] == 'P' )
{
static char * V_52 = L_112 ;
F_19 ( F_118 ( V_113 ) , V_52 , strlen ( V_52 ) ) ;
}
if ( V_49 [ 0 ] == 'S' )
{
F_70 ( V_19 , F_119 ( V_113 ) ) ;
}
}
#ifdef F_120
F_18 ( V_49 , V_49 , V_51 ) ;
#endif
V_112 = V_111 = 0 ;
for (; ; )
{
#ifdef F_121
{ static V_136 = 0 ; if ( ++ V_136 == 100 ) { V_136 = 0 ; F_115 ( V_113 ) ; } }
#endif
V_111 = F_122 ( V_113 , & ( V_49 [ V_112 ] ) , ( unsigned int ) V_51 ) ;
switch ( F_123 ( V_113 , V_111 ) )
{
case V_137 :
break;
case V_138 :
case V_139 :
case V_140 :
F_7 ( V_19 , L_113 ) ;
break;
case V_141 :
case V_142 :
F_7 ( V_19 , L_114 ) ;
F_44 ( V_25 ) ;
V_40 = 1 ;
goto V_118;
case V_143 :
F_7 ( V_19 , L_110 ) ;
V_40 = 1 ;
goto V_118;
}
V_112 += V_111 ;
V_51 -= V_111 ;
if ( V_51 <= 0 ) break;
}
}
if ( V_130 )
{
if ( ! F_124 ( V_113 ) )
{
V_51 = F_125 ( V_113 ) ;
if ( V_51 < 0 )
{
V_40 = 0 ;
goto V_118;
}
else if ( V_51 == 0 )
{
V_40 = 1 ;
goto V_118;
}
}
else
{
V_144:
V_51 = F_126 ( V_113 , ( char * ) V_49 , V_117 ) ;
switch ( F_123 ( V_113 , V_51 ) )
{
case V_137 :
#ifdef F_120
F_16 ( V_49 , V_49 , V_51 ) ;
#endif
F_127 ( fileno ( stdout ) , V_49 ,
( unsigned int ) V_51 ) ;
if ( F_106 ( V_113 ) ) goto V_144;
break;
case V_138 :
case V_139 :
case V_140 :
F_7 ( V_19 , L_115 ) ;
break;
case V_141 :
case V_142 :
F_7 ( V_19 , L_114 ) ;
F_44 ( V_25 ) ;
V_40 = 1 ;
goto V_118;
case V_143 :
F_7 ( V_19 , L_110 ) ;
V_40 = 1 ;
goto V_118;
}
}
}
}
V_118:
F_7 ( V_19 , L_116 ) ;
#if 1
F_128 ( V_113 , V_145 | V_146 ) ;
#else
F_129 ( V_113 ) ;
#endif
if ( V_113 != NULL ) F_130 ( V_113 ) ;
F_7 ( V_19 , L_117 ) ;
if ( V_49 != NULL )
{
F_131 ( V_49 , V_117 ) ;
F_13 ( V_49 ) ;
}
if ( V_40 >= 0 )
F_7 ( V_19 , L_95 ) ;
return ( V_40 ) ;
}
static void F_114 ( void )
{
F_7 ( V_25 , L_118 ) ;
if ( V_6 >= 0 )
{
F_132 ( V_6 ) ;
}
}
static int F_125 ( T_11 * V_113 )
{
int V_51 ;
const char * V_52 ;
T_12 * V_147 ;
long V_148 ;
T_13 char V_49 [ V_149 ] ;
if ( ( V_51 = F_133 ( V_113 ) ) <= 0 )
{
if ( F_134 ( V_51 ) )
{
F_7 ( V_19 , L_119 ) ;
return ( 1 ) ;
}
F_7 ( V_25 , L_114 ) ;
V_148 = F_135 ( V_113 ) ;
if ( V_148 != V_150 )
{
F_7 ( V_25 , L_120 ,
F_136 ( V_148 ) ) ;
}
else
F_44 ( V_25 ) ;
return ( 0 ) ;
}
F_137 ( V_19 , F_138 ( V_113 ) ) ;
V_147 = F_139 ( V_113 ) ;
if ( V_147 != NULL )
{
F_7 ( V_19 , L_121 ) ;
F_140 ( V_19 , V_147 ) ;
F_141 ( F_142 ( V_147 ) , V_49 , sizeof V_49 ) ;
F_7 ( V_19 , L_122 , V_49 ) ;
F_141 ( F_143 ( V_147 ) , V_49 , sizeof V_49 ) ;
F_7 ( V_19 , L_123 , V_49 ) ;
F_144 ( V_147 ) ;
}
if ( F_145 ( V_113 , V_49 , sizeof V_49 ) != NULL )
F_7 ( V_19 , L_124 , V_49 ) ;
V_52 = F_146 ( F_147 ( V_113 ) ) ;
F_7 ( V_19 , L_125 , ( V_52 != NULL ) ? V_52 : L_126 ) ;
if ( V_113 -> V_151 ) F_7 ( V_19 , L_127 ) ;
if ( F_148 ( V_113 , V_152 , 0 , NULL ) &
V_153 )
F_7 ( V_19 , L_128 ) ;
return ( 1 ) ;
}
static T_1 * F_54 ( char * V_61 )
{
T_1 * V_40 = NULL ;
T_3 * V_105 ;
if ( ( V_105 = F_149 ( V_61 , L_129 ) ) == NULL )
goto V_118;
V_40 = F_150 ( V_105 , NULL , NULL , NULL ) ;
V_118:
if ( V_105 != NULL ) F_72 ( V_105 ) ;
return ( V_40 ) ;
}
static int V_103 ( char * V_107 , int V_108 , unsigned char * V_60 )
{
char * V_49 = NULL ;
int V_40 = 1 ;
int V_51 , V_134 , V_111 , V_154 , V_155 ;
struct V_156 V_157 ;
T_11 * V_113 ;
T_14 * V_158 ;
T_3 * V_159 , * V_160 , * V_114 ;
long V_161 ;
V_49 = F_11 ( V_117 ) ;
if ( V_49 == NULL ) return ( 0 ) ;
V_159 = F_41 ( F_151 () ) ;
V_160 = F_41 ( F_152 () ) ;
if ( ( V_159 == NULL ) || ( V_160 == NULL ) ) goto V_118;
#ifdef F_5
if ( V_15 )
{
unsigned long V_119 = 1 ;
if ( ! V_22 )
F_7 ( V_25 , L_109 ) ;
if ( F_89 ( V_108 , F_5 , & V_119 ) < 0 )
F_44 ( V_25 ) ;
}
#endif
if ( ! F_153 ( V_159 , V_117 ) ) goto V_118;
if ( ( V_113 = F_90 ( V_17 ) ) == NULL ) goto V_118;
#ifndef F_91
if ( ( V_113 -> V_120 = F_92 () ) != NULL )
{
F_93 ( V_113 -> V_120 , V_121 , V_122 ) ;
F_93 ( V_113 -> V_120 , V_123 , V_124 ) ;
}
#endif
if( V_60 ) F_94 ( V_113 , V_60 ,
strlen ( ( char * ) V_60 ) ) ;
V_114 = F_96 ( V_108 , V_77 ) ;
if ( V_16 )
{
T_3 * V_125 ;
V_125 = F_41 ( F_97 () ) ;
V_114 = F_98 ( V_125 , V_114 ) ;
}
F_99 ( V_113 , V_114 , V_114 ) ;
F_100 ( V_113 ) ;
F_154 ( V_160 , V_113 , V_162 ) ;
F_98 ( V_159 , V_160 ) ;
#ifdef F_120
V_159 = F_98 ( F_41 ( F_9 () ) , V_159 ) ;
#endif
if ( V_20 )
{
V_113 -> V_126 = 1 ;
F_101 ( F_102 ( V_113 ) , V_127 ) ;
F_103 ( F_102 ( V_113 ) , V_19 ) ;
}
if ( V_21 )
{
F_104 ( V_113 , V_128 ) ;
F_105 ( V_113 , V_19 ) ;
}
V_154 = 0 ;
for (; ; )
{
if ( V_23 )
{
V_51 = F_133 ( V_113 ) ;
switch ( F_123 ( V_113 , V_51 ) )
{
case V_137 :
break;
case V_138 :
case V_139 :
case V_140 :
continue;
case V_141 :
case V_142 :
case V_143 :
V_40 = 1 ;
goto V_118;
}
F_115 ( V_113 ) ;
F_122 ( V_113 , NULL , 0 ) ;
}
V_51 = F_155 ( V_159 , V_49 , V_117 - 1 ) ;
if ( V_51 < 0 )
{
if ( ! F_156 ( V_159 ) )
{
if ( ! V_22 )
F_44 ( V_25 ) ;
goto V_118;
}
else
{
F_7 ( V_19 , L_130 ) ;
#if ! F_24 ( V_163 ) && ! F_24 ( V_164 )
F_157 ( 1 ) ;
#endif
continue;
}
}
else if ( V_51 == 0 )
{
V_40 = 1 ;
goto V_78;
}
if ( ( ( V_18 == 1 ) && ( strncmp ( L_131 , V_49 , 4 ) == 0 ) ) ||
( ( V_18 == 2 ) && ( strncmp ( L_132 , V_49 , 10 ) == 0 ) ) )
{
char * V_2 ;
T_12 * V_147 ;
F_158 ( T_14 ) * V_165 ;
static char * V_166 = L_133 ;
F_159 ( V_159 , L_134 ) ;
F_159 ( V_159 , L_135 ) ;
F_159 ( V_159 , L_136 ) ;
F_159 ( V_159 , L_2 ) ;
for ( V_51 = 0 ; V_51 < V_74 ; V_51 ++ )
{
F_159 ( V_159 , V_75 [ V_51 ] ) ;
F_19 ( V_159 , L_137 , 1 ) ;
}
F_159 ( V_159 , L_2 ) ;
F_7 ( V_159 , L_138 ) ;
V_165 = F_160 ( V_113 ) ;
V_134 = F_161 ( V_165 ) ;
for ( V_51 = 0 ; V_51 < V_134 ; V_51 ++ )
{
V_158 = F_162 ( V_165 , V_51 ) ;
F_7 ( V_159 , L_139 ,
F_163 ( V_158 ) ,
F_146 ( V_158 ) ) ;
if ( ( ( ( V_51 + 1 ) % 2 ) == 0 ) && ( V_51 + 1 != V_134 ) )
F_159 ( V_159 , L_2 ) ;
}
F_159 ( V_159 , L_2 ) ;
V_2 = F_145 ( V_113 , V_49 , V_117 ) ;
if ( V_2 != NULL )
{
F_7 ( V_159 , L_140 ) ;
V_134 = V_51 = 0 ;
while ( * V_2 )
{
if ( * V_2 == ':' )
{
F_19 ( V_159 , V_166 , 26 - V_134 ) ;
V_51 ++ ;
V_134 = 0 ;
F_19 ( V_159 , ( ( V_51 % 3 ) ? L_137 : L_2 ) , 1 ) ;
}
else
{
F_19 ( V_159 , V_2 , 1 ) ;
V_134 ++ ;
}
V_2 ++ ;
}
F_159 ( V_159 , L_2 ) ;
}
F_7 ( V_159 , ( ( V_113 -> V_151 )
? L_141
: L_142 ) ) ;
V_158 = F_147 ( V_113 ) ;
F_7 ( V_159 , L_143 ,
F_163 ( V_158 ) ,
F_146 ( V_158 ) ) ;
F_164 ( V_159 , F_138 ( V_113 ) ) ;
F_7 ( V_159 , L_144 ) ;
F_70 ( V_159 , F_119 ( V_113 ) ) ;
F_7 ( V_159 , L_144 ) ;
V_147 = F_139 ( V_113 ) ;
if ( V_147 != NULL )
{
F_7 ( V_159 , L_121 ) ;
F_165 ( V_159 , V_147 ) ;
F_140 ( V_159 , V_147 ) ;
}
else
F_159 ( V_159 , L_145 ) ;
F_159 ( V_159 , L_146 ) ;
break;
}
else if ( ( V_18 == 2 || V_18 == 3 )
&& ( strncmp ( L_147 , V_49 , 5 ) == 0 ) )
{
T_3 * V_167 ;
char * V_2 , * V_70 ;
static char * V_168 = L_148 ;
V_2 = & ( V_49 [ 5 ] ) ;
V_155 = 1 ;
for ( V_70 = V_2 ; * V_70 != '\0' ; V_70 ++ )
{
if ( V_70 [ 0 ] == ' ' )
break;
switch ( V_155 )
{
case 1 :
V_155 = ( V_70 [ 0 ] == '.' ) ? 2 : 0 ;
break;
case 2 :
V_155 = ( V_70 [ 0 ] == '.' ) ? 3 : 0 ;
break;
case 3 :
V_155 = ( V_70 [ 0 ] == '/' ) ? - 1 : 0 ;
break;
}
if ( V_155 == 0 )
V_155 = ( V_70 [ 0 ] == '/' ) ? 1 : 0 ;
}
V_155 = ( V_155 == 3 ) || ( V_155 == - 1 ) ;
if ( * V_70 == '\0' )
{
F_159 ( V_159 , V_168 ) ;
F_7 ( V_159 , L_149 , V_2 ) ;
break;
}
* V_70 = '\0' ;
if ( V_155 )
{
F_159 ( V_159 , V_168 ) ;
F_7 ( V_159 , L_150 , V_2 ) ;
break;
}
if ( * V_2 == '/' )
{
F_159 ( V_159 , V_168 ) ;
F_7 ( V_159 , L_151 , V_2 ) ;
break;
}
#if 0
if (e[-1] == '/')
strcat(p,"index.html");
#endif
if ( V_156 ( V_2 , & V_157 ) < 0 )
{
F_159 ( V_159 , V_168 ) ;
F_7 ( V_159 , L_152 , V_2 ) ;
F_44 ( V_159 ) ;
break;
}
if ( F_166 ( V_157 . V_169 ) )
{
#if 0
strcat(p,"/index.html");
#else
F_159 ( V_159 , V_168 ) ;
F_7 ( V_159 , L_153 , V_2 ) ;
break;
#endif
}
if ( ( V_167 = F_149 ( V_2 , L_129 ) ) == NULL )
{
F_159 ( V_159 , V_168 ) ;
F_7 ( V_159 , L_154 , V_2 ) ;
F_44 ( V_159 ) ;
break;
}
if ( ! V_22 )
F_7 ( V_25 , L_155 , V_2 ) ;
if ( V_18 == 2 )
{
V_51 = strlen ( V_2 ) ;
if ( ( ( V_51 > 5 ) && ( strcmp ( & ( V_2 [ V_51 - 5 ] ) , L_156 ) == 0 ) ) ||
( ( V_51 > 4 ) && ( strcmp ( & ( V_2 [ V_51 - 4 ] ) , L_157 ) == 0 ) ) ||
( ( V_51 > 4 ) && ( strcmp ( & ( V_2 [ V_51 - 4 ] ) , L_158 ) == 0 ) ) )
F_159 ( V_159 , L_134 ) ;
else
F_159 ( V_159 , L_148 ) ;
}
V_161 = 0 ;
for (; ; )
{
V_51 = F_15 ( V_167 , V_49 , V_117 ) ;
if ( V_51 <= 0 ) break;
#ifdef F_121
V_161 += V_51 ;
fprintf ( V_76 , L_159 , V_51 ) ;
if ( V_161 > 3 * 1024 )
{
V_161 = 0 ;
fprintf ( V_76 , L_160 ) ;
F_115 ( V_113 ) ;
}
#endif
for ( V_134 = 0 ; V_134 < V_51 ; )
{
#ifdef F_121
{ static V_136 = 0 ; if ( ++ V_136 == 13 ) { F_115 ( V_113 ) ; } }
#endif
V_111 = F_19 ( V_159 , & ( V_49 [ V_134 ] ) , V_51 - V_134 ) ;
if ( V_111 <= 0 )
{
if ( ! F_156 ( V_159 ) )
goto V_170;
else
{
F_7 ( V_19 , L_161 ) ;
}
}
else
{
V_134 += V_111 ;
}
}
}
V_170:
F_72 ( V_167 ) ;
break;
}
}
for (; ; )
{
V_51 = ( int ) F_55 ( V_159 ) ;
if ( V_51 <= 0 )
{
if ( ! F_156 ( V_159 ) )
break;
}
else
break;
}
V_78:
#if 1
F_128 ( V_113 , V_145 | V_146 ) ;
#else
#endif
V_118:
if ( V_40 >= 0 )
F_7 ( V_19 , L_95 ) ;
if ( V_49 != NULL ) F_13 ( V_49 ) ;
if ( V_159 != NULL ) F_167 ( V_159 ) ;
return ( V_40 ) ;
}
static T_8 T_15 * V_98 ( T_11 * V_108 , int V_171 , int V_172 )
{
static T_8 * V_173 = NULL ;
if ( V_173 == NULL )
{
if ( ! V_22 )
{
F_7 ( V_25 , L_162 , V_172 ) ;
( void ) F_55 ( V_25 ) ;
}
V_173 = F_61 ( V_172 , V_100 , NULL , NULL ) ;
if ( ! V_22 )
{
F_7 ( V_25 , L_2 ) ;
( void ) F_55 ( V_25 ) ;
}
}
return ( V_173 ) ;
}
static int V_94 ( const T_11 * V_174 , unsigned char * V_175 ,
unsigned int * V_176 )
{
unsigned int V_136 = 0 ;
do {
F_168 ( V_175 , * V_176 ) ;
memcpy ( V_175 , V_91 ,
( strlen ( V_91 ) < * V_176 ) ?
strlen ( V_91 ) : * V_176 ) ;
}
while( F_169 ( V_174 , V_175 , * V_176 ) &&
( ++ V_136 < V_177 ) );
if( V_136 >= V_177 )
return 0 ;
return 1 ;
}
