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
#ifndef F_6
V_24 = NULL ;
#endif
}
static void F_7 ( void )
{
F_8 ( V_25 , L_1 ) ;
F_8 ( V_25 , L_2 ) ;
F_8 ( V_25 , L_3 , V_26 ) ;
F_8 ( V_25 , L_4 ) ;
F_8 ( V_25 , L_5 ) ;
F_8 ( V_25 , L_6 ) ;
F_8 ( V_25 , L_7 ) ;
F_8 ( V_25 , L_8 , V_13 ) ;
F_8 ( V_25 , L_9 ) ;
F_8 ( V_25 , L_10 ) ;
F_8 ( V_25 , L_11 , V_13 ) ;
F_8 ( V_25 , L_12 ) ;
F_8 ( V_25 , L_13 ) ;
F_8 ( V_25 , L_14 ) ;
F_8 ( V_25 , L_15 ) ;
F_8 ( V_25 , L_16 ) ;
F_8 ( V_25 , L_17 ) ;
F_8 ( V_25 , L_18 ) ;
F_8 ( V_25 , L_19 ) ;
F_8 ( V_25 , L_20 ) ;
#ifndef F_9
F_8 ( V_25 , L_21 \
L_22 \
L_23 ) ;
#endif
#ifdef F_5
F_8 ( V_25 , L_24 ) ;
#endif
F_8 ( V_25 , L_25 ) ;
F_8 ( V_25 , L_26 ) ;
F_8 ( V_25 , L_27 ) ;
F_8 ( V_25 , L_28 ) ;
F_8 ( V_25 , L_29 ) ;
F_8 ( V_25 , L_30 ) ;
F_8 ( V_25 , L_31 ) ;
F_8 ( V_25 , L_32 ) ;
F_8 ( V_25 , L_33 ) ;
F_8 ( V_25 , L_34 ) ;
F_8 ( V_25 , L_35 ) ;
F_8 ( V_25 , L_36 ) ;
F_8 ( V_25 , L_37 ) ;
F_8 ( V_25 , L_38 ) ;
F_8 ( V_25 , L_39 ) ;
F_8 ( V_25 , L_40 ) ;
F_8 ( V_25 , L_41 ) ;
F_8 ( V_25 , L_42 ) ;
F_8 ( V_25 , L_43 ) ;
F_8 ( V_25 , L_44 ) ;
F_8 ( V_25 , L_45 ) ;
F_8 ( V_25 , L_46 ) ;
#ifndef F_10
F_8 ( V_25 , L_47 ) ;
#endif
#ifndef F_9
F_8 ( V_25 , L_48 ) ;
#endif
F_8 ( V_25 , L_49 ) ;
F_8 ( V_25 , L_50 ) ;
F_8 ( V_25 , L_51 ) ;
F_8 ( V_25 , L_52 ) ;
F_8 ( V_25 , L_53 ) ;
#ifndef F_6
F_8 ( V_25 , L_54 ) ;
#endif
F_8 ( V_25 , L_55 ) ;
F_8 ( V_25 , L_56 , V_27 , V_27 ) ;
}
T_2 * F_11 ()
{
return ( & V_28 ) ;
}
static int F_12 ( T_3 * V_29 )
{
T_4 * V_30 ;
V_30 = ( T_4 * ) F_13 ( sizeof( T_4 ) + 1024 ) ;
V_30 -> V_31 = 1024 ;
V_30 -> V_32 [ 0 ] = '\0' ;
V_29 -> V_33 = ( char * ) V_30 ;
V_29 -> V_34 = 1 ;
V_29 -> V_35 = 0 ;
return ( 1 ) ;
}
static int F_14 ( T_3 * V_36 )
{
if ( V_36 == NULL ) return ( 0 ) ;
if ( V_36 -> V_33 != NULL )
F_15 ( V_36 -> V_33 ) ;
V_36 -> V_33 = NULL ;
V_36 -> V_34 = 0 ;
V_36 -> V_35 = 0 ;
return ( 1 ) ;
}
static int F_16 ( T_3 * V_37 , char * V_38 , int V_39 )
{
int V_40 = 0 ;
if ( V_38 == NULL || V_39 == 0 ) return ( 0 ) ;
if ( V_37 -> V_41 == NULL ) return ( 0 ) ;
V_40 = F_17 ( V_37 -> V_41 , V_38 , V_39 ) ;
if ( V_40 > 0 )
F_18 ( V_38 , V_38 , V_40 ) ;
return ( V_40 ) ;
}
static int F_19 ( T_3 * V_37 , const char * V_42 , int V_43 )
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
F_15 ( V_30 ) ;
V_30 = ( T_4 * ) F_13 ( sizeof( T_4 ) + V_44 ) ;
V_30 -> V_31 = V_44 ;
V_30 -> V_32 [ 0 ] = '\0' ;
V_37 -> V_33 = ( char * ) V_30 ;
}
F_20 ( V_30 -> V_32 , V_42 , V_43 ) ;
V_40 = F_21 ( V_37 -> V_41 , V_30 -> V_32 , V_43 ) ;
return ( V_40 ) ;
}
static long F_22 ( T_3 * V_37 , int V_46 , long V_44 , void * V_33 )
{
long V_40 ;
if ( V_37 -> V_41 == NULL ) return ( 0 ) ;
switch ( V_46 )
{
case V_47 :
V_40 = 0L ;
break;
default:
V_40 = F_23 ( V_37 -> V_41 , V_46 , V_44 , V_33 ) ;
break;
}
return ( V_40 ) ;
}
static int F_24 ( T_3 * V_48 , char * V_49 , int V_50 )
{
int V_51 , V_40 = 0 ;
if ( V_48 -> V_41 == NULL ) return ( 0 ) ;
for ( V_51 = 0 ; V_51 < V_50 - 1 ; ++ V_51 )
{
V_40 = F_16 ( V_48 , & V_49 [ V_51 ] , 1 ) ;
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
static int F_25 ( T_3 * V_48 , const char * V_52 )
{
if ( V_48 -> V_41 == NULL ) return ( 0 ) ;
return F_19 ( V_48 , V_52 , strlen ( V_52 ) ) ;
}
int MAIN ( int V_53 , char * V_54 [] )
{
T_5 * V_55 = NULL ;
int V_56 = 0 ;
short V_57 = V_26 ;
char * V_58 = NULL , * V_59 = NULL ;
unsigned char * V_60 = NULL ;
char * V_61 = NULL ;
char * V_62 = NULL ;
int V_63 = 0 , V_64 = 0 ;
int V_40 = 1 ;
int V_65 = 0 ;
int V_66 = 0 , V_67 = 0 , V_68 = 0 , V_69 = 0 ;
int V_70 = 0 ;
T_6 * V_71 = NULL ;
#ifdef F_26
#undef F_26
#endif
int F_26 = V_72 ;
#ifndef F_6
T_7 * V_73 = NULL ;
#endif
char * V_74 = NULL ;
int V_75 = V_76 , V_77 = V_76 ;
char * V_78 = NULL , * V_79 = NULL ;
char * V_80 = NULL , * V_81 = NULL ;
int V_82 = V_76 , V_83 = V_76 ;
T_8 * V_84 = NULL , * V_85 = NULL ;
T_9 * V_86 = NULL , * V_87 = NULL ;
#if ! F_27 ( V_88 ) && ! F_27 ( V_89 )
V_71 = F_28 () ;
#elif ! F_27 ( V_89 )
V_71 = F_29 () ;
#elif ! F_27 ( V_88 )
V_71 = F_30 () ;
#endif
V_90 = V_53 ;
V_91 = V_54 ;
F_31 () ;
#ifdef F_32
F_4 () ;
#endif
if ( V_25 == NULL )
V_25 = F_33 ( V_92 , V_93 ) ;
if ( ! F_34 ( V_25 , NULL ) )
goto V_94;
V_95 = 0 ;
#ifdef F_5
V_15 = 0 ;
#endif
V_16 = 0 ;
V_53 -- ;
V_54 ++ ;
while ( V_53 >= 1 )
{
if ( ( strcmp ( * V_54 , L_57 ) == 0 ) ||
( strcmp ( * V_54 , L_58 ) == 0 ) )
{
if ( -- V_53 < 1 ) goto V_96;
if ( ! F_35 ( * ( ++ V_54 ) , & V_57 ) )
goto V_96;
}
else if ( strcmp ( * V_54 , L_59 ) == 0 )
{
V_8 = V_97 | V_98 ;
if ( -- V_53 < 1 ) goto V_96;
V_95 = atoi ( * ( ++ V_54 ) ) ;
F_8 ( V_25 , L_60 , V_95 ) ;
}
else if ( strcmp ( * V_54 , L_61 ) == 0 )
{
V_8 = V_97 | V_99 |
V_98 ;
if ( -- V_53 < 1 ) goto V_96;
V_95 = atoi ( * ( ++ V_54 ) ) ;
F_8 ( V_25 , L_62 , V_95 ) ;
}
else if ( strcmp ( * V_54 , L_63 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_60 = ( unsigned char * ) * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_64 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_12 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_65 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_75 = F_36 ( * ( ++ V_54 ) ) ;
}
else if ( strcmp ( * V_54 , L_66 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_14 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_67 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_77 = F_36 ( * ( ++ V_54 ) ) ;
}
else if ( strcmp ( * V_54 , L_68 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_78 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_69 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_61 = * ( ++ V_54 ) ;
}
#ifndef F_9
else if ( strcmp ( * V_54 , L_70 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_62 = * ( ++ V_54 ) ;
}
#endif
else if ( strcmp ( * V_54 , L_71 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_82 = F_36 ( * ( ++ V_54 ) ) ;
}
else if ( strcmp ( * V_54 , L_72 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_10 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_73 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_83 = F_36 ( * ( ++ V_54 ) ) ;
}
else if ( strcmp ( * V_54 , L_74 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_80 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_75 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_11 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_76 ) == 0 )
{
V_69 = 1 ;
}
else if ( strcmp ( * V_54 , L_77 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_58 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_78 ) == 0 )
{
V_56 |= V_100 ;
}
else if ( strcmp ( * V_54 , L_78 ) == 0 )
{
V_56 |= V_100 | V_101 ;
}
else if ( strcmp ( * V_54 , L_79 ) == 0 )
{ V_65 |= V_102 ; }
else if ( strcmp ( * V_54 , L_80 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_7 = * ( ++ V_54 ) ;
}
else if ( strcmp ( * V_54 , L_81 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_59 = * ( ++ V_54 ) ;
}
#ifdef F_5
else if ( strcmp ( * V_54 , L_82 ) == 0 )
{ V_15 = 1 ; }
#endif
else if ( strcmp ( * V_54 , L_83 ) == 0 )
{
#ifdef F_5
V_15 = 1 ;
#endif
V_16 = 1 ;
}
else if ( strcmp ( * V_54 , L_84 ) == 0 )
{ V_20 = 1 ; }
else if ( strcmp ( * V_54 , L_85 ) == 0 )
{ V_21 = 1 ; }
else if ( strcmp ( * V_54 , L_86 ) == 0 )
{ V_23 = 1 ; }
else if ( strcmp ( * V_54 , L_87 ) == 0 )
{ V_70 = 1 ; }
else if ( strcmp ( * V_54 , L_88 ) == 0 )
{ V_103 = 1 ; }
else if ( strcmp ( * V_54 , L_89 ) == 0 )
{ V_22 = 1 ; }
else if ( strcmp ( * V_54 , L_90 ) == 0 )
{ V_64 = 1 ; }
else if ( strcmp ( * V_54 , L_91 ) == 0 )
{ V_66 = 1 ; }
else if ( strcmp ( * V_54 , L_92 ) == 0 )
{ V_67 = 1 ; }
else if ( strcmp ( * V_54 , L_93 ) == 0 )
{ V_68 = 1 ; }
else if ( strcmp ( * V_54 , L_94 ) == 0 )
{ V_18 = 1 ; }
else if ( strcmp ( * V_54 , L_95 ) == 0 )
{ V_18 = 2 ; }
else if ( strcmp ( * V_54 , L_96 ) == 0 )
{ V_18 = 3 ; }
else if ( strcmp ( * V_54 , L_97 ) == 0 )
{ V_65 |= V_104 ; }
else if ( strcmp ( * V_54 , L_98 ) == 0 )
{ V_65 |= V_105 ; }
else if ( strcmp ( * V_54 , L_99 ) == 0 )
{ V_65 |= V_106 ; }
#ifndef V_88
else if ( strcmp ( * V_54 , L_100 ) == 0 )
{ V_71 = F_30 () ; }
#endif
#ifndef V_89
else if ( strcmp ( * V_54 , L_101 ) == 0 )
{ V_71 = F_29 () ; }
#endif
#ifndef F_37
else if ( strcmp ( * V_54 , L_102 ) == 0 )
{ V_71 = F_38 () ; }
#endif
#ifndef F_39
else if ( strcmp ( * V_54 , L_103 ) == 0 )
{
V_71 = F_40 () ;
F_26 = V_107 ;
}
else if ( strcmp ( * V_54 , L_104 ) == 0 )
V_108 = 1 ;
else if ( strcmp ( * V_54 , L_105 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_109 = atol ( * ( ++ V_54 ) ) ;
}
else if ( strcmp ( * V_54 , L_106 ) == 0 )
V_110 = 1 ;
#endif
else if ( strcmp ( * V_54 , L_107 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_111 = * ( ++ V_54 ) ;
}
#ifndef F_6
else if ( strcmp ( * V_54 , L_108 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_24 = * ( ++ V_54 ) ;
}
#endif
else if ( strcmp ( * V_54 , L_109 ) == 0 )
{
if ( -- V_53 < 1 ) goto V_96;
V_74 = * ( ++ V_54 ) ;
}
else
{
F_8 ( V_25 , L_110 , * V_54 ) ;
V_63 = 1 ;
break;
}
V_53 -- ;
V_54 ++ ;
}
if ( V_63 )
{
V_96:
F_7 () ;
goto V_94;
}
F_41 () ;
F_42 () ;
#ifndef F_6
V_73 = F_43 ( V_25 , V_24 , 1 ) ;
#endif
if ( ! F_44 ( V_25 , V_78 , V_80 , & V_79 , & V_81 ) )
{
F_8 ( V_25 , L_111 ) ;
goto V_94;
}
if ( V_14 == NULL )
V_14 = V_12 ;
V_86 = F_45 ( V_25 , V_14 , V_77 , 0 , V_79 , V_73 ,
L_112 ) ;
if ( ! V_86 )
{
F_46 ( V_25 ) ;
goto V_94;
}
V_84 = F_47 ( V_25 , V_12 , V_75 ,
NULL , V_73 , L_113 ) ;
if ( ! V_84 )
{
F_46 ( V_25 ) ;
goto V_94;
}
if ( V_10 )
{
if ( V_11 == NULL )
V_11 = V_10 ;
V_87 = F_45 ( V_25 , V_11 , V_83 ,
0 , V_81 , V_73 ,
L_114 ) ;
if ( ! V_87 )
{
F_46 ( V_25 ) ;
goto V_94;
}
V_85 = F_47 ( V_25 , V_10 , V_82 ,
NULL , V_73 , L_115 ) ;
if ( ! V_85 )
{
F_46 ( V_25 ) ;
goto V_94;
}
}
if ( ! F_48 ( NULL , V_25 , 1 ) && V_74 == NULL
&& ! F_49 () )
{
F_8 ( V_25 , L_116 ) ;
}
if ( V_74 != NULL )
F_8 ( V_25 , L_117 ,
F_50 ( V_74 ) ) ;
if ( V_19 == NULL )
{
if ( V_22 && ! V_20 && ! V_21 )
{
V_19 = F_51 ( F_52 () ) ;
}
else
{
if ( V_19 == NULL )
V_19 = F_33 ( stdout , V_93 ) ;
}
}
#if ! F_27 ( V_112 ) || ! F_27 ( V_113 ) || ! F_27 ( V_114 )
if ( V_69 )
#endif
{
V_12 = NULL ;
V_14 = NULL ;
V_10 = NULL ;
V_11 = NULL ;
}
V_17 = F_53 ( V_71 ) ;
if ( V_17 == NULL )
{
F_46 ( V_25 ) ;
goto V_94;
}
if ( V_111 )
{
if( strlen ( V_111 ) >= 32 )
F_8 ( V_25 ,
L_118 ) ;
else if( strlen ( V_111 ) >= 16 )
F_8 ( V_25 ,
L_119 ) ;
if( ! F_54 ( V_17 , V_115 ) )
{
F_8 ( V_25 , L_120 ) ;
F_46 ( V_25 ) ;
goto V_94;
}
F_8 ( V_25 , L_121 , V_111 ) ;
}
F_55 ( V_17 , 1 ) ;
if ( V_64 ) F_56 ( V_17 , V_116 ) ;
if ( V_23 ) F_56 ( V_17 , V_117 ) ;
F_56 ( V_17 , V_65 ) ;
if ( F_26 == V_107 ) F_57 ( V_17 , 1 ) ;
if ( V_70 ) F_58 ( V_17 , V_118 ) ;
F_59 ( V_17 , 128 ) ;
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
if ( ( ! F_60 ( V_17 , V_59 , V_58 ) ) ||
( ! F_61 ( V_17 ) ) )
{
F_46 ( V_25 ) ;
}
V_55 = F_62 ( V_17 ) ;
F_63 ( V_55 , V_56 ) ;
#ifndef F_10
if ( ! V_67 )
{
T_1 * V_1 = NULL ;
if ( V_61 )
V_1 = F_64 ( V_61 ) ;
else if ( V_12 )
V_1 = F_64 ( V_12 ) ;
if ( V_1 != NULL )
{
F_8 ( V_19 , L_122 ) ;
}
else
{
F_8 ( V_19 , L_123 ) ;
V_1 = F_1 () ;
}
( void ) F_65 ( V_19 ) ;
F_66 ( V_17 , V_1 ) ;
F_67 ( V_1 ) ;
}
#endif
#ifndef F_9
if ( ! V_68 )
{
T_10 * V_119 = NULL ;
if ( V_62 )
{
int V_120 = F_68 ( V_62 ) ;
if ( V_120 == 0 )
{
F_8 ( V_25 , L_124 ,
V_62 ) ;
goto V_94;
}
V_119 = F_69 ( V_120 ) ;
if ( V_119 == NULL )
{
F_8 ( V_25 , L_125 ,
V_62 ) ;
goto V_94;
}
}
if ( V_119 != NULL )
{
F_8 ( V_19 , L_126 ) ;
}
else
{
F_8 ( V_19 , L_127 ) ;
V_119 = F_69 ( V_121 ) ;
if ( V_119 == NULL )
{
F_8 ( V_25 , L_128 ) ;
goto V_94;
}
}
( void ) F_65 ( V_19 ) ;
F_70 ( V_17 , V_119 ) ;
F_71 ( V_119 ) ;
}
#endif
if ( ! F_72 ( V_17 , V_84 , V_86 ) )
goto V_94;
if ( V_85 != NULL )
{
if ( ! F_72 ( V_17 , V_85 , V_87 ) )
goto V_94;
}
#ifndef V_112
#if 1
if ( ! V_66 )
F_73 ( V_17 , V_122 ) ;
#else
if ( ! V_66 && F_74 ( V_17 ) )
{
T_11 * V_123 ;
F_8 ( V_19 , L_129 ) ;
F_65 ( V_19 ) ;
V_123 = F_75 ( 512 , V_124 , NULL ) ;
if ( ! F_76 ( V_17 , V_123 ) )
{
F_46 ( V_25 ) ;
goto V_94;
}
F_77 ( V_123 ) ;
F_8 ( V_19 , L_2 ) ;
}
#endif
#endif
if ( V_7 != NULL )
if( ! F_78 ( V_17 , V_7 ) ) {
F_8 ( V_25 , L_130 ) ;
F_46 ( V_25 ) ;
goto V_94;
}
F_79 ( V_17 , V_8 , V_125 ) ;
F_80 ( V_17 , ( void * ) & V_126 ,
sizeof V_126 ) ;
if ( V_59 != NULL )
F_81 ( V_17 , F_82 ( V_59 ) ) ;
F_8 ( V_19 , L_131 ) ;
if ( V_18 )
F_83 ( V_57 , F_26 , & V_6 , V_127 , V_60 ) ;
else
F_83 ( V_57 , F_26 , & V_6 , V_128 , V_60 ) ;
F_84 ( V_19 , V_17 ) ;
V_40 = 0 ;
V_94:
if ( V_17 != NULL ) F_85 ( V_17 ) ;
if ( V_84 )
F_86 ( V_84 ) ;
if ( V_85 )
F_86 ( V_85 ) ;
if ( V_86 )
F_87 ( V_86 ) ;
if ( V_87 )
F_87 ( V_87 ) ;
if ( V_79 )
F_15 ( V_79 ) ;
if ( V_81 )
F_15 ( V_81 ) ;
if ( V_19 != NULL )
{
F_88 ( V_19 ) ;
V_19 = NULL ;
}
F_89 () ;
F_90 ( V_40 ) ;
}
static void F_84 ( T_3 * V_129 , T_12 * V_130 )
{
F_8 ( V_129 , L_132 ,
F_91 ( V_130 ) ) ;
F_8 ( V_129 , L_133 ,
F_92 ( V_130 ) ) ;
F_8 ( V_129 , L_134 ,
F_93 ( V_130 ) ) ;
F_8 ( V_129 , L_135 ,
F_94 ( V_130 ) ) ;
F_8 ( V_129 , L_136 ,
F_95 ( V_130 ) ) ;
F_8 ( V_129 , L_137 ,
F_96 ( V_130 ) ) ;
F_8 ( V_129 , L_138 ,
F_97 ( V_130 ) ) ;
F_8 ( V_129 , L_139 , F_98 ( V_130 ) ) ;
F_8 ( V_129 , L_140 , F_99 ( V_130 ) ) ;
F_8 ( V_129 , L_141 , F_100 ( V_130 ) ) ;
F_8 ( V_129 , L_142 , F_101 ( V_130 ) ) ;
F_8 ( V_129 , L_143 ,
F_102 ( V_130 ) ,
F_103 ( V_130 ) ) ;
}
static int V_128 ( char * V_131 , int V_132 , unsigned char * V_60 )
{
char * V_49 = NULL ;
T_13 V_133 ;
int V_40 = 1 , V_134 ;
int V_135 , V_51 ;
unsigned long V_136 ;
T_14 * V_137 = NULL ;
T_3 * V_138 ;
#if F_27 ( V_139 ) || F_27 ( V_140 ) || F_27 ( V_141 )
struct V_142 V_143 ;
#endif
if ( ( V_49 = F_13 ( V_144 ) ) == NULL )
{
F_8 ( V_25 , L_144 ) ;
goto V_145;
}
#ifdef F_5
if ( V_15 )
{
unsigned long V_146 = 1 ;
if ( ! V_22 )
F_8 ( V_25 , L_145 ) ;
if ( F_104 ( V_132 , F_5 , & V_146 ) < 0 )
F_46 ( V_25 ) ;
}
#endif
if ( V_137 == NULL ) {
V_137 = F_105 ( V_17 ) ;
#ifndef F_106
if ( ( V_137 -> V_147 = F_107 () ) != NULL )
{
F_108 ( V_137 -> V_147 , V_148 ,
V_149 ) ;
F_108 ( V_137 -> V_147 , V_150 ,
V_151 ) ;
}
#endif
if( V_60 )
F_109 ( V_137 , V_60 ,
strlen ( ( char * ) V_60 ) ) ;
}
F_110 ( V_137 ) ;
if ( F_111 ( V_137 ) == V_152 )
{
struct V_142 V_153 ;
V_138 = F_112 ( V_132 , V_93 ) ;
if ( V_108 )
{
V_153 . V_154 = 0 ;
V_153 . V_155 = V_156 ;
F_23 ( V_138 , V_157 , 0 , & V_153 ) ;
V_153 . V_154 = 0 ;
V_153 . V_155 = V_158 ;
F_23 ( V_138 , V_159 , 0 , & V_153 ) ;
}
if ( V_109 > 0 )
{
F_113 ( V_137 , V_160 ) ;
F_114 ( V_137 , V_109 ) ;
}
else
F_23 ( V_138 , V_161 , 0 , NULL ) ;
F_113 ( V_137 , V_162 ) ;
}
else
V_138 = F_115 ( V_132 , V_93 ) ;
if ( V_16 )
{
T_3 * V_163 ;
V_163 = F_51 ( F_116 () ) ;
V_138 = F_117 ( V_163 , V_138 ) ;
}
F_118 ( V_137 , V_138 , V_138 ) ;
F_119 ( V_137 ) ;
if ( V_20 )
{
V_137 -> V_164 = 1 ;
F_120 ( F_121 ( V_137 ) , V_165 ) ;
F_122 ( F_121 ( V_137 ) , V_19 ) ;
}
if ( V_21 )
{
F_123 ( V_137 , V_166 ) ;
F_124 ( V_137 , V_19 ) ;
}
V_134 = V_132 + 1 ;
for (; ; )
{
int V_167 ;
int V_168 ;
V_167 = 0 ;
V_168 = F_125 ( V_137 ) ;
if ( ! V_168 )
{
F_126 ( & V_133 ) ;
#if ! F_27 ( V_139 ) && ! F_27 ( V_140 ) && ! F_27 ( V_141 )
F_127 ( fileno ( V_169 ) , & V_133 ) ;
#endif
F_127 ( V_132 , & V_133 ) ;
#if F_27 ( V_139 ) || F_27 ( V_140 ) || F_27 ( V_141 )
V_143 . V_154 = 1 ;
V_143 . V_155 = 0 ;
V_51 = F_128 ( V_134 , ( void * ) & V_133 , NULL , NULL , & V_143 ) ;
if( ( V_51 < 0 ) || ( ! V_51 && ! F_129 () ) ) continue;
if( F_129 () )
V_167 = 1 ;
#else
V_51 = F_128 ( V_134 , ( void * ) & V_133 , NULL , NULL , NULL ) ;
if ( V_51 <= 0 ) continue;
if ( F_130 ( fileno ( V_169 ) , & V_133 ) )
V_167 = 1 ;
#endif
if ( F_130 ( V_132 , & V_133 ) )
V_168 = 1 ;
}
if ( V_167 )
{
if ( V_103 )
{
int V_170 , V_171 ;
V_51 = F_131 ( fileno ( V_169 ) , V_49 , V_144 / 2 ) ;
V_171 = 0 ;
for ( V_170 = 0 ; V_170 < V_51 ; V_170 ++ )
if ( V_49 [ V_170 ] == '\n' )
V_171 ++ ;
for ( V_170 = V_51 - 1 ; V_170 >= 0 ; V_170 -- )
{
V_49 [ V_170 + V_171 ] = V_49 [ V_170 ] ;
if ( V_49 [ V_170 ] == '\n' )
{
V_171 -- ;
V_51 ++ ;
V_49 [ V_170 + V_171 ] = '\r' ;
}
}
assert ( V_171 == 0 ) ;
}
else
V_51 = F_131 ( fileno ( V_169 ) , V_49 , V_144 ) ;
if ( ! V_22 )
{
if ( ( V_51 <= 0 ) || ( V_49 [ 0 ] == 'Q' ) )
{
F_8 ( V_19 , L_146 ) ;
F_132 ( V_132 ) ;
F_133 () ;
V_40 = - 11 ;
goto V_145;
}
if ( ( V_51 <= 0 ) || ( V_49 [ 0 ] == 'q' ) )
{
F_8 ( V_19 , L_146 ) ;
if ( F_111 ( V_137 ) != V_152 )
F_132 ( V_132 ) ;
goto V_145;
}
if ( ( V_49 [ 0 ] == 'r' ) &&
( ( V_49 [ 1 ] == '\n' ) || ( V_49 [ 1 ] == '\r' ) ) )
{
F_134 ( V_137 ) ;
V_51 = F_135 ( V_137 ) ;
printf ( L_147 , V_51 ) ;
V_51 = 0 ;
continue;
}
if ( ( V_49 [ 0 ] == 'R' ) &&
( ( V_49 [ 1 ] == '\n' ) || ( V_49 [ 1 ] == '\r' ) ) )
{
F_136 ( V_137 ,
V_97 | V_98 , NULL ) ;
F_134 ( V_137 ) ;
V_51 = F_135 ( V_137 ) ;
printf ( L_147 , V_51 ) ;
V_51 = 0 ;
continue;
}
if ( V_49 [ 0 ] == 'P' )
{
static const char * V_52 = L_148 ;
F_21 ( F_137 ( V_137 ) , V_52 , strlen ( V_52 ) ) ;
}
if ( V_49 [ 0 ] == 'S' )
{
F_84 ( V_19 , F_138 ( V_137 ) ) ;
}
}
#ifdef F_139
F_20 ( V_49 , V_49 , V_51 ) ;
#endif
V_136 = V_135 = 0 ;
for (; ; )
{
#ifdef F_140
{ static V_172 = 0 ; if ( ++ V_172 == 100 ) { V_172 = 0 ; F_134 ( V_137 ) ; } }
#endif
V_135 = F_141 ( V_137 , & ( V_49 [ V_136 ] ) , ( unsigned int ) V_51 ) ;
switch ( F_142 ( V_137 , V_135 ) )
{
case V_173 :
break;
case V_174 :
case V_175 :
case V_176 :
F_8 ( V_19 , L_149 ) ;
break;
case V_177 :
case V_178 :
F_8 ( V_19 , L_150 ) ;
F_46 ( V_25 ) ;
V_40 = 1 ;
goto V_145;
case V_179 :
F_8 ( V_19 , L_146 ) ;
V_40 = 1 ;
goto V_145;
}
V_136 += V_135 ;
V_51 -= V_135 ;
if ( V_51 <= 0 ) break;
}
}
if ( V_168 )
{
if ( ! F_143 ( V_137 ) )
{
V_51 = F_144 ( V_137 ) ;
if ( V_51 < 0 )
{
V_40 = 0 ;
goto V_145;
}
else if ( V_51 == 0 )
{
V_40 = 1 ;
goto V_145;
}
}
else
{
V_180:
V_51 = F_145 ( V_137 , ( char * ) V_49 , V_144 ) ;
switch ( F_142 ( V_137 , V_51 ) )
{
case V_173 :
#ifdef F_139
F_18 ( V_49 , V_49 , V_51 ) ;
#endif
F_146 ( fileno ( stdout ) , V_49 ,
( unsigned int ) V_51 ) ;
if ( F_125 ( V_137 ) ) goto V_180;
break;
case V_174 :
case V_175 :
case V_176 :
F_8 ( V_19 , L_151 ) ;
break;
case V_177 :
case V_178 :
F_8 ( V_19 , L_150 ) ;
F_46 ( V_25 ) ;
V_40 = 1 ;
goto V_145;
case V_179 :
F_8 ( V_19 , L_146 ) ;
V_40 = 1 ;
goto V_145;
}
}
}
}
V_145:
F_8 ( V_19 , L_152 ) ;
#if 1
F_147 ( V_137 , V_181 | V_182 ) ;
#else
F_148 ( V_137 ) ;
#endif
if ( V_137 != NULL ) F_149 ( V_137 ) ;
F_8 ( V_19 , L_153 ) ;
if ( V_49 != NULL )
{
F_150 ( V_49 , V_144 ) ;
F_15 ( V_49 ) ;
}
if ( V_40 >= 0 )
F_8 ( V_19 , L_131 ) ;
return ( V_40 ) ;
}
static void F_133 ( void )
{
F_8 ( V_25 , L_154 ) ;
if ( V_6 >= 0 )
{
F_151 ( V_6 ) ;
}
}
static int F_144 ( T_14 * V_137 )
{
int V_51 ;
const char * V_52 ;
T_8 * V_183 ;
long V_184 ;
T_15 char V_49 [ V_185 ] ;
if ( ( V_51 = F_152 ( V_137 ) ) <= 0 )
{
if ( F_153 ( V_51 ) )
{
F_8 ( V_19 , L_155 ) ;
return ( 1 ) ;
}
F_8 ( V_25 , L_150 ) ;
V_184 = F_154 ( V_137 ) ;
if ( V_184 != V_186 )
{
F_8 ( V_25 , L_156 ,
F_155 ( V_184 ) ) ;
}
else
F_46 ( V_25 ) ;
return ( 0 ) ;
}
F_156 ( V_19 , F_157 ( V_137 ) ) ;
V_183 = F_158 ( V_137 ) ;
if ( V_183 != NULL )
{
F_8 ( V_19 , L_157 ) ;
F_159 ( V_19 , V_183 ) ;
F_160 ( F_161 ( V_183 ) , V_49 , sizeof V_49 ) ;
F_8 ( V_19 , L_158 , V_49 ) ;
F_160 ( F_162 ( V_183 ) , V_49 , sizeof V_49 ) ;
F_8 ( V_19 , L_159 , V_49 ) ;
F_86 ( V_183 ) ;
}
if ( F_163 ( V_137 , V_49 , sizeof V_49 ) != NULL )
F_8 ( V_19 , L_160 , V_49 ) ;
V_52 = F_164 ( F_165 ( V_137 ) ) ;
F_8 ( V_19 , L_161 , ( V_52 != NULL ) ? V_52 : L_162 ) ;
if ( V_137 -> V_187 ) F_8 ( V_19 , L_163 ) ;
if ( F_166 ( V_137 , V_188 , 0 , NULL ) &
V_189 )
F_8 ( V_19 , L_164 ) ;
#ifndef F_106
if ( V_137 -> V_147 -> V_190 != NULL )
{
F_8 ( V_19 , L_165 ,
V_137 -> V_147 -> V_190 ) ;
}
#endif
return ( 1 ) ;
}
static T_1 * F_64 ( const char * V_61 )
{
T_1 * V_40 = NULL ;
T_3 * V_129 ;
if ( ( V_129 = F_167 ( V_61 , L_166 ) ) == NULL )
goto V_145;
V_40 = F_168 ( V_129 , NULL , NULL , NULL ) ;
V_145:
if ( V_129 != NULL ) F_88 ( V_129 ) ;
return ( V_40 ) ;
}
static int V_127 ( char * V_131 , int V_132 , unsigned char * V_60 )
{
char * V_49 = NULL ;
int V_40 = 1 ;
int V_51 , V_170 , V_135 , V_191 , V_192 ;
struct V_193 V_194 ;
T_14 * V_137 ;
T_16 * V_195 ;
T_3 * V_196 , * V_197 , * V_138 ;
long V_198 ;
V_49 = F_13 ( V_144 ) ;
if ( V_49 == NULL ) return ( 0 ) ;
V_196 = F_51 ( F_169 () ) ;
V_197 = F_51 ( F_170 () ) ;
if ( ( V_196 == NULL ) || ( V_197 == NULL ) ) goto V_145;
#ifdef F_5
if ( V_15 )
{
unsigned long V_146 = 1 ;
if ( ! V_22 )
F_8 ( V_25 , L_145 ) ;
if ( F_104 ( V_132 , F_5 , & V_146 ) < 0 )
F_46 ( V_25 ) ;
}
#endif
if ( ! F_171 ( V_196 , V_144 ) ) goto V_145;
if ( ( V_137 = F_105 ( V_17 ) ) == NULL ) goto V_145;
#ifndef F_106
if ( ( V_137 -> V_147 = F_107 () ) != NULL )
{
F_108 ( V_137 -> V_147 , V_148 , V_149 ) ;
F_108 ( V_137 -> V_147 , V_150 , V_151 ) ;
}
#endif
if( V_60 ) F_109 ( V_137 , V_60 ,
strlen ( ( char * ) V_60 ) ) ;
V_138 = F_115 ( V_132 , V_93 ) ;
if ( V_16 )
{
T_3 * V_163 ;
V_163 = F_51 ( F_116 () ) ;
V_138 = F_117 ( V_163 , V_138 ) ;
}
F_118 ( V_137 , V_138 , V_138 ) ;
F_119 ( V_137 ) ;
F_172 ( V_197 , V_137 , V_199 ) ;
F_117 ( V_196 , V_197 ) ;
#ifdef F_139
V_196 = F_117 ( F_51 ( F_11 () ) , V_196 ) ;
#endif
if ( V_20 )
{
V_137 -> V_164 = 1 ;
F_120 ( F_121 ( V_137 ) , V_165 ) ;
F_122 ( F_121 ( V_137 ) , V_19 ) ;
}
if ( V_21 )
{
F_123 ( V_137 , V_166 ) ;
F_124 ( V_137 , V_19 ) ;
}
V_191 = 0 ;
for (; ; )
{
if ( V_23 )
{
V_51 = F_152 ( V_137 ) ;
switch ( F_142 ( V_137 , V_51 ) )
{
case V_173 :
break;
case V_174 :
case V_175 :
case V_176 :
continue;
case V_177 :
case V_178 :
case V_179 :
V_40 = 1 ;
goto V_145;
}
F_134 ( V_137 ) ;
F_141 ( V_137 , NULL , 0 ) ;
}
V_51 = F_173 ( V_196 , V_49 , V_144 - 1 ) ;
if ( V_51 < 0 )
{
if ( ! F_174 ( V_196 ) )
{
if ( ! V_22 )
F_46 ( V_25 ) ;
goto V_145;
}
else
{
F_8 ( V_19 , L_167 ) ;
#if F_27 ( V_141 )
F_175 ( 1000 ) ;
#elif ! F_27 ( V_140 ) && ! F_27 ( V_200 )
F_176 ( 1 ) ;
#endif
continue;
}
}
else if ( V_51 == 0 )
{
V_40 = 1 ;
goto V_94;
}
if ( ( ( V_18 == 1 ) && ( strncmp ( L_168 , V_49 , 4 ) == 0 ) ) ||
( ( V_18 == 2 ) && ( strncmp ( L_169 , V_49 , 10 ) == 0 ) ) )
{
char * V_2 ;
T_8 * V_183 ;
F_177 ( T_16 ) * V_201 ;
static const char * V_202 = L_170 ;
F_178 ( V_196 , L_171 ) ;
F_178 ( V_196 , L_172 ) ;
F_178 ( V_196 , L_173 ) ;
F_178 ( V_196 , L_2 ) ;
for ( V_51 = 0 ; V_51 < V_90 ; V_51 ++ )
{
F_178 ( V_196 , V_91 [ V_51 ] ) ;
F_21 ( V_196 , L_174 , 1 ) ;
}
F_178 ( V_196 , L_2 ) ;
F_8 ( V_196 , L_175 ) ;
V_201 = F_179 ( V_137 ) ;
V_170 = F_180 ( V_201 ) ;
for ( V_51 = 0 ; V_51 < V_170 ; V_51 ++ )
{
V_195 = F_181 ( V_201 , V_51 ) ;
F_8 ( V_196 , L_176 ,
F_182 ( V_195 ) ,
F_164 ( V_195 ) ) ;
if ( ( ( ( V_51 + 1 ) % 2 ) == 0 ) && ( V_51 + 1 != V_170 ) )
F_178 ( V_196 , L_2 ) ;
}
F_178 ( V_196 , L_2 ) ;
V_2 = F_163 ( V_137 , V_49 , V_144 ) ;
if ( V_2 != NULL )
{
F_8 ( V_196 , L_177 ) ;
V_170 = V_51 = 0 ;
while ( * V_2 )
{
if ( * V_2 == ':' )
{
F_21 ( V_196 , V_202 , 26 - V_170 ) ;
V_51 ++ ;
V_170 = 0 ;
F_21 ( V_196 , ( ( V_51 % 3 ) ? L_174 : L_2 ) , 1 ) ;
}
else
{
F_21 ( V_196 , V_2 , 1 ) ;
V_170 ++ ;
}
V_2 ++ ;
}
F_178 ( V_196 , L_2 ) ;
}
F_8 ( V_196 , ( ( V_137 -> V_187 )
? L_178
: L_179 ) ) ;
V_195 = F_165 ( V_137 ) ;
F_8 ( V_196 , L_180 ,
F_182 ( V_195 ) ,
F_164 ( V_195 ) ) ;
F_183 ( V_196 , F_157 ( V_137 ) ) ;
F_8 ( V_196 , L_181 ) ;
F_84 ( V_196 , F_138 ( V_137 ) ) ;
F_8 ( V_196 , L_181 ) ;
V_183 = F_158 ( V_137 ) ;
if ( V_183 != NULL )
{
F_8 ( V_196 , L_157 ) ;
F_184 ( V_196 , V_183 ) ;
F_159 ( V_196 , V_183 ) ;
}
else
F_178 ( V_196 , L_182 ) ;
F_178 ( V_196 , L_183 ) ;
break;
}
else if ( ( V_18 == 2 || V_18 == 3 )
&& ( strncmp ( L_184 , V_49 , 5 ) == 0 ) )
{
T_3 * V_203 ;
char * V_2 , * V_73 ;
static const char * V_204 = L_185 ;
V_2 = & ( V_49 [ 5 ] ) ;
V_192 = 1 ;
for ( V_73 = V_2 ; * V_73 != '\0' ; V_73 ++ )
{
if ( V_73 [ 0 ] == ' ' )
break;
switch ( V_192 )
{
case 1 :
V_192 = ( V_73 [ 0 ] == '.' ) ? 2 : 0 ;
break;
case 2 :
V_192 = ( V_73 [ 0 ] == '.' ) ? 3 : 0 ;
break;
case 3 :
V_192 = ( V_73 [ 0 ] == '/' ) ? - 1 : 0 ;
break;
}
if ( V_192 == 0 )
V_192 = ( V_73 [ 0 ] == '/' ) ? 1 : 0 ;
}
V_192 = ( V_192 == 3 ) || ( V_192 == - 1 ) ;
if ( * V_73 == '\0' )
{
F_178 ( V_196 , V_204 ) ;
F_8 ( V_196 , L_186 , V_2 ) ;
break;
}
* V_73 = '\0' ;
if ( V_192 )
{
F_178 ( V_196 , V_204 ) ;
F_8 ( V_196 , L_187 , V_2 ) ;
break;
}
if ( * V_2 == '/' )
{
F_178 ( V_196 , V_204 ) ;
F_8 ( V_196 , L_188 , V_2 ) ;
break;
}
#if 0
if (e[-1] == '/')
strcat(p,"index.html");
#endif
if ( V_193 ( V_2 , & V_194 ) < 0 )
{
F_178 ( V_196 , V_204 ) ;
F_8 ( V_196 , L_189 , V_2 ) ;
F_46 ( V_196 ) ;
break;
}
if ( F_185 ( V_194 . V_205 ) )
{
#if 0
strcat(p,"/index.html");
#else
F_178 ( V_196 , V_204 ) ;
F_8 ( V_196 , L_190 , V_2 ) ;
break;
#endif
}
if ( ( V_203 = F_167 ( V_2 , L_166 ) ) == NULL )
{
F_178 ( V_196 , V_204 ) ;
F_8 ( V_196 , L_191 , V_2 ) ;
F_46 ( V_196 ) ;
break;
}
if ( ! V_22 )
F_8 ( V_25 , L_192 , V_2 ) ;
if ( V_18 == 2 )
{
V_51 = strlen ( V_2 ) ;
if ( ( ( V_51 > 5 ) && ( strcmp ( & ( V_2 [ V_51 - 5 ] ) , L_193 ) == 0 ) ) ||
( ( V_51 > 4 ) && ( strcmp ( & ( V_2 [ V_51 - 4 ] ) , L_194 ) == 0 ) ) ||
( ( V_51 > 4 ) && ( strcmp ( & ( V_2 [ V_51 - 4 ] ) , L_195 ) == 0 ) ) )
F_178 ( V_196 , L_171 ) ;
else
F_178 ( V_196 , L_185 ) ;
}
V_198 = 0 ;
for (; ; )
{
V_51 = F_17 ( V_203 , V_49 , V_144 ) ;
if ( V_51 <= 0 ) break;
#ifdef F_140
V_198 += V_51 ;
fprintf ( V_92 , L_196 , V_51 ) ;
if ( V_198 > 3 * 1024 )
{
V_198 = 0 ;
fprintf ( V_92 , L_197 ) ;
F_134 ( V_137 ) ;
}
#endif
for ( V_170 = 0 ; V_170 < V_51 ; )
{
#ifdef F_140
{ static V_172 = 0 ; if ( ++ V_172 == 13 ) { F_134 ( V_137 ) ; } }
#endif
V_135 = F_21 ( V_196 , & ( V_49 [ V_170 ] ) , V_51 - V_170 ) ;
if ( V_135 <= 0 )
{
if ( ! F_174 ( V_196 ) )
goto V_206;
else
{
F_8 ( V_19 , L_198 ) ;
}
}
else
{
V_170 += V_135 ;
}
}
}
V_206:
F_88 ( V_203 ) ;
break;
}
}
for (; ; )
{
V_51 = ( int ) F_65 ( V_196 ) ;
if ( V_51 <= 0 )
{
if ( ! F_174 ( V_196 ) )
break;
}
else
break;
}
V_94:
#if 1
F_147 ( V_137 , V_181 | V_182 ) ;
#else
#endif
V_145:
if ( V_40 >= 0 )
F_8 ( V_19 , L_131 ) ;
if ( V_49 != NULL ) F_15 ( V_49 ) ;
if ( V_196 != NULL ) F_186 ( V_196 ) ;
return ( V_40 ) ;
}
static T_11 T_17 * V_122 ( T_14 * V_132 , int V_207 , int V_208 )
{
T_18 * V_209 = NULL ;
static T_11 * V_210 = NULL ;
if ( ! V_210 && ( ( V_209 = F_187 () ) == NULL ) )
F_8 ( V_25 , L_199 ) ;
if ( ! V_210 && V_209 )
{
if ( ! V_22 )
{
F_8 ( V_25 , L_200 , V_208 ) ;
( void ) F_65 ( V_25 ) ;
}
if( ! F_188 ( V_209 , V_124 ) || ( ( V_210 = F_189 () ) == NULL ) ||
! F_190 ( V_210 , V_208 , V_209 , NULL ) )
{
if( V_210 ) F_77 ( V_210 ) ;
V_210 = NULL ;
}
if ( ! V_22 )
{
F_8 ( V_25 , L_2 ) ;
( void ) F_65 ( V_25 ) ;
}
F_191 ( V_209 ) ;
}
return ( V_210 ) ;
}
static int V_115 ( const T_14 * V_211 , unsigned char * V_212 ,
unsigned int * V_213 )
{
unsigned int V_172 = 0 ;
do {
F_192 ( V_212 , * V_213 ) ;
memcpy ( V_212 , V_111 ,
( strlen ( V_111 ) < * V_213 ) ?
strlen ( V_111 ) : * V_213 ) ;
}
while( F_193 ( V_211 , V_212 , * V_213 ) &&
( ++ V_172 < V_214 ) );
if( V_172 >= V_214 )
return 0 ;
return 1 ;
}
