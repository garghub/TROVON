static void F_1 ( void )
{
F_2 ( V_1 , L_1 ) ;
F_2 ( V_1 , L_2 ) ;
F_2 ( V_1 , L_3 ) ;
F_2 ( V_1 , L_4 ) ;
F_2 ( V_1 , L_5 , V_2 , V_3 ) ;
F_2 ( V_1 , L_6 ) ;
F_2 ( V_1 , L_7 ) ;
F_2 ( V_1 , L_8 ) ;
F_2 ( V_1 , L_9 ) ;
F_2 ( V_1 , L_10 ) ;
F_2 ( V_1 , L_11 ) ;
F_2 ( V_1 , L_12 ) ;
F_2 ( V_1 , L_13 ) ;
F_2 ( V_1 , L_14 ) ;
F_2 ( V_1 , L_15 ) ;
F_2 ( V_1 , L_16 ) ;
F_2 ( V_1 , L_17 ) ;
#ifdef F_3
F_2 ( V_1 , L_18 ) ;
#endif
F_2 ( V_1 , L_19 ) ;
F_2 ( V_1 , L_20 ) ;
F_2 ( V_1 , L_21 ) ;
F_2 ( V_1 , L_22 ) ;
F_2 ( V_1 , L_23 ) ;
F_2 ( V_1 , L_24 ) ;
F_2 ( V_1 , L_25 ) ;
F_2 ( V_1 , L_26 ) ;
F_2 ( V_1 , L_27 ) ;
F_2 ( V_1 , L_28 ) ;
}
int MAIN ( int V_4 , char * * V_5 )
{
int V_6 = 0 ;
T_1 * V_7 = NULL , * V_8 = NULL ;
int V_9 , V_10 , V_11 , V_12 = 0 ;
char * V_13 = NULL , * V_14 = NULL ;
int V_15 , V_16 ;
int V_17 , V_18 ;
T_2 V_19 , V_20 ;
short V_21 = V_22 ;
int V_23 = 1 ;
char * V_24 = V_2 ;
char * V_25 = NULL , * V_26 = NULL ;
char * V_27 = NULL , * V_28 = NULL , * V_29 = NULL ;
int V_30 = 0 , V_31 = 0 , V_32 = V_33 , V_34 = 0 ;
int V_35 = 0 ;
int V_36 , V_37 , V_38 , V_39 , V_40 , V_41 ;
T_3 * V_42 = NULL ;
int V_43 = 1 , V_44 = 1 , V_45 , V_46 = 0 ;
int V_47 = 0 ;
T_4 * V_48 = NULL ;
T_5 * V_49 ;
#ifdef F_4
struct V_50 V_51 ;
#endif
#if ! F_5 ( V_52 ) && ! F_5 ( V_53 )
V_48 = F_6 () ;
#elif ! F_5 ( V_53 )
V_48 = F_7 () ;
#elif ! F_5 ( V_52 )
V_48 = F_8 () ;
#endif
F_9 () ;
V_54 = 0 ;
V_55 = 0 ;
V_56 = 0 ;
V_57 = 0 ;
V_58 = 0 ;
if ( V_1 == NULL )
V_1 = F_10 ( V_59 , V_60 ) ;
if ( ( ( V_13 = F_11 ( V_61 ) ) == NULL ) ||
( ( V_14 = F_11 ( V_61 ) ) == NULL ) )
{
F_2 ( V_1 , L_29 ) ;
goto V_62;
}
V_63 = 0 ;
V_64 = V_65 ;
#ifdef F_3
V_66 = 0 ;
#endif
V_4 -- ;
V_5 ++ ;
while ( V_4 >= 1 )
{
if ( strcmp ( * V_5 , L_30 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_67;
V_24 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_31 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_67;
V_21 = atoi ( * ( ++ V_5 ) ) ;
if ( V_21 == 0 ) goto V_67;
}
else if ( strcmp ( * V_5 , L_32 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_67;
if ( ! F_12 ( * ( ++ V_5 ) , & V_24 , NULL , & V_21 ) )
goto V_67;
}
else if ( strcmp ( * V_5 , L_33 ) == 0 )
{
V_32 = V_68 ;
if ( -- V_4 < 1 ) goto V_67;
V_63 = atoi ( * ( ++ V_5 ) ) ;
F_2 ( V_1 , L_34 , V_63 ) ;
}
else if ( strcmp ( * V_5 , L_35 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_67;
V_25 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_36 ) == 0 )
V_47 = 1 ;
else if ( strcmp ( * V_5 , L_37 ) == 0 )
V_35 = 1 ;
else if ( strcmp ( * V_5 , L_38 ) == 0 )
{
V_55 = 1 ;
V_56 = 1 ;
}
else if ( strcmp ( * V_5 , L_39 ) == 0 )
V_56 = 1 ;
else if ( strcmp ( * V_5 , L_40 ) == 0 )
V_54 = 1 ;
else if ( strcmp ( * V_5 , L_41 ) == 0 )
V_57 = 1 ;
else if ( strcmp ( * V_5 , L_42 ) == 0 )
V_58 = 1 ;
else if ( strcmp ( * V_5 , L_43 ) == 0 )
V_46 = 1 ;
else if ( strcmp ( * V_5 , L_44 ) == 0 )
V_12 = 1 ;
#ifndef V_52
else if ( strcmp ( * V_5 , L_45 ) == 0 )
V_48 = F_8 () ;
#endif
#ifndef V_53
else if ( strcmp ( * V_5 , L_46 ) == 0 )
V_48 = F_7 () ;
#endif
#ifndef F_13
else if ( strcmp ( * V_5 , L_47 ) == 0 )
V_48 = F_14 () ;
#endif
else if ( strcmp ( * V_5 , L_48 ) == 0 )
V_34 = 1 ;
else if ( strcmp ( * V_5 , L_49 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_67;
V_26 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_50 ) == 0 )
{
V_30 = 5 ;
}
else if ( strcmp ( * V_5 , L_51 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_67;
V_27 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_52 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_67;
V_28 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_53 ) == 0 )
V_6 |= V_69 ;
else if ( strcmp ( * V_5 , L_54 ) == 0 )
V_6 |= V_70 ;
else if ( strcmp ( * V_5 , L_55 ) == 0 )
V_6 |= V_71 ;
else if ( strcmp ( * V_5 , L_56 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_67;
V_29 = * ( ++ V_5 ) ;
}
#ifdef F_3
else if ( strcmp ( * V_5 , L_57 ) == 0 )
{ V_66 = 1 ; }
#endif
else
{
F_2 ( V_1 , L_58 , * V_5 ) ;
V_31 = 1 ;
break;
}
V_4 -- ;
V_5 ++ ;
}
if ( V_31 )
{
V_67:
F_1 () ;
goto V_62;
}
F_15 ( NULL , V_1 , 0 ) ;
if ( V_72 == NULL )
{
if ( V_55 )
{
V_72 = F_16 ( F_17 () ) ;
}
else
{
if ( V_72 == NULL )
V_72 = F_10 ( stdout , V_60 ) ;
}
}
F_18 () ;
F_19 () ;
V_42 = F_20 ( V_48 ) ;
if ( V_42 == NULL )
{
F_21 ( V_1 ) ;
goto V_62;
}
if ( V_34 )
F_22 ( V_42 , V_73 | V_6 ) ;
else
F_22 ( V_42 , V_6 ) ;
if ( V_12 ) F_23 ( V_42 , V_74 ) ;
if ( V_29 != NULL )
if( ! F_24 ( V_42 , V_29 ) ) {
F_2 ( V_1 , L_59 ) ;
F_21 ( V_1 ) ;
goto V_62;
}
#if 0
else
SSL_CTX_set_cipher_list(ctx,getenv("SSL_CIPHER"));
#endif
F_25 ( V_42 , V_32 , V_75 ) ;
if ( ! F_26 ( V_42 , V_25 , V_26 ) )
goto V_62;
if ( ( ! F_27 ( V_42 , V_28 , V_27 ) ) ||
( ! F_28 ( V_42 ) ) )
{
F_21 ( V_1 ) ;
}
V_7 = F_29 ( V_42 ) ;
V_76:
if ( F_30 ( & V_9 , V_24 , V_21 ) == 0 )
{
F_2 ( V_1 , L_60 , F_31 () ) ;
F_32 ( V_9 ) ;
goto V_62;
}
F_2 ( V_72 , L_61 , V_9 ) ;
#ifdef F_3
if ( V_66 )
{
unsigned long V_77 = 1 ;
F_2 ( V_72 , L_62 ) ;
if ( F_33 ( V_9 , F_3 , & V_77 ) < 0 )
{
F_21 ( V_1 ) ;
goto V_62;
}
}
#endif
if ( V_54 & 0x01 ) V_7 -> V_78 = 1 ;
V_49 = F_34 ( V_9 , V_60 ) ;
if ( V_46 )
{
T_5 * V_79 ;
V_79 = F_16 ( F_35 () ) ;
V_49 = F_36 ( V_79 , V_49 ) ;
}
if ( V_57 )
{
V_7 -> V_78 = 1 ;
F_37 ( V_49 , V_80 ) ;
F_38 ( V_49 , V_72 ) ;
}
F_39 ( V_7 , V_49 , V_49 ) ;
F_40 ( V_7 ) ;
V_11 = F_41 ( V_7 ) + 1 ;
V_37 = 1 ;
V_36 = 0 ;
V_40 = 0 ;
V_39 = 1 ;
V_38 = 1 ;
V_15 = 0 ;
V_16 = 0 ;
V_17 = 0 ;
V_18 = 0 ;
for (; ; )
{
F_42 ( & V_19 ) ;
F_42 ( & V_20 ) ;
if ( F_43 ( V_7 ) && ! F_44 ( V_7 ) )
{
V_44 = 1 ;
V_40 = 0 ;
}
else
{
V_40 = 1 ;
if ( V_44 )
{
V_44 = 0 ;
F_45 ( V_72 , V_7 , V_23 ) ;
if ( V_23 > 0 ) V_23 -- ;
if ( V_30 )
{
V_30 -- ;
F_2 ( V_72 , L_63 ) ;
F_46 ( V_7 ) ;
F_40 ( V_7 ) ;
F_32 ( F_41 ( V_7 ) ) ;
goto V_76;
}
}
}
V_41 = V_39 && F_47 ( V_7 ) ;
if ( ! V_41 )
{
#ifndef F_4
if ( V_40 )
{
if ( V_37 ) F_48 ( fileno ( V_81 ) , & V_19 ) ;
if ( V_36 ) F_48 ( fileno ( stdout ) , & V_20 ) ;
}
if ( V_39 )
F_48 ( F_41 ( V_7 ) , & V_19 ) ;
if ( V_38 )
F_48 ( F_41 ( V_7 ) , & V_20 ) ;
#else
if( ! V_40 || ! V_36 ) {
if ( V_39 )
F_48 ( F_41 ( V_7 ) , & V_19 ) ;
if ( V_38 )
F_48 ( F_41 ( V_7 ) , & V_20 ) ;
}
#endif
#ifdef F_4
V_45 = 0 ;
if( ! V_36 ) {
if( V_37 ) {
V_51 . V_82 = 1 ;
V_51 . V_83 = 0 ;
V_45 = F_49 ( V_11 , ( void * ) & V_19 , ( void * ) & V_20 ,
NULL , & V_51 ) ;
if( ! V_45 && ( ! ( ( F_50 () ) || ( V_84 == F_51 ( F_52 ( V_85 ) , 0 ) ) ) || ! V_37 ) ) continue;
} else V_45 = F_49 ( V_11 , ( void * ) & V_19 , ( void * ) & V_20 ,
NULL , NULL ) ;
}
#else
V_45 = F_49 ( V_11 , ( void * ) & V_19 , ( void * ) & V_20 ,
NULL , NULL ) ;
#endif
if ( V_45 < 0 )
{
F_2 ( V_1 , L_64 ,
F_31 () ) ;
goto V_86;
}
}
if ( ! V_41 && F_53 ( F_41 ( V_7 ) , & V_20 ) )
{
V_10 = F_54 ( V_7 , & ( V_13 [ V_16 ] ) ,
( unsigned int ) V_15 ) ;
switch ( F_55 ( V_7 , V_10 ) )
{
case V_87 :
V_16 += V_10 ;
V_15 -= V_10 ;
if ( V_10 <= 0 ) goto V_62;
if ( V_15 <= 0 )
{
V_37 = 1 ;
V_38 = 0 ;
}
else
{
V_37 = 0 ;
V_38 = 1 ;
}
break;
case V_88 :
F_2 ( V_72 , L_65 ) ;
V_38 = 1 ;
V_37 = 0 ;
break;
case V_89 :
F_2 ( V_72 , L_66 ) ;
V_36 = 0 ;
V_39 = 1 ;
V_38 = 0 ;
break;
case V_90 :
F_2 ( V_72 , L_67 ) ;
break;
case V_91 :
if ( V_15 != 0 )
{
F_2 ( V_72 , L_68 ) ;
goto V_86;
}
else
{
V_37 = 1 ;
V_38 = 0 ;
break;
}
case V_92 :
if ( ( V_10 != 0 ) || ( V_15 != 0 ) )
{
F_2 ( V_1 , L_69 ,
F_31 () ) ;
goto V_86;
}
else
{
V_37 = 1 ;
V_38 = 0 ;
}
break;
case V_93 :
F_21 ( V_1 ) ;
goto V_86;
}
}
#ifdef F_4
else if ( ! V_41 && V_36 )
#else
else if ( ! V_41 && F_53 ( fileno ( stdout ) , & V_20 ) )
#endif
{
#ifdef F_56
F_57 ( & ( V_14 [ V_18 ] ) , & ( V_14 [ V_18 ] ) , V_17 ) ;
#endif
V_45 = F_58 ( fileno ( stdout ) , & ( V_14 [ V_18 ] ) , V_17 ) ;
if ( V_45 <= 0 )
{
F_2 ( V_72 , L_70 ) ;
goto V_86;
}
V_17 -= V_45 ; ;
V_18 += V_45 ;
if ( V_17 <= 0 )
{
V_39 = 1 ;
V_36 = 0 ;
}
}
else if ( V_41 || F_53 ( F_41 ( V_7 ) , & V_19 ) )
{
#ifdef F_59
{ static int V_94 ; if ( ++ V_94 == 52 ) { F_60 ( V_7 ) ; V_94 = 0 ; } }
#endif
#if 1
V_10 = F_61 ( V_7 , V_14 , 1024 ) ;
#else
V_10 = F_61 ( V_7 , V_14 , 16 ) ;
{ char V_95 [ 10240 ] ;
printf ( L_71 , V_10 , F_47 ( V_7 ) , F_62 ( V_7 , V_95 , 10240 ) ) ;
}
#endif
switch ( F_55 ( V_7 , V_10 ) )
{
case V_87 :
if ( V_10 <= 0 )
goto V_62;
V_18 = 0 ;
V_17 = V_10 ;
V_39 = 0 ;
V_36 = 1 ;
break;
case V_88 :
F_2 ( V_72 , L_72 ) ;
V_38 = 1 ;
V_37 = 0 ;
break;
case V_89 :
F_2 ( V_72 , L_73 ) ;
V_36 = 0 ;
V_39 = 1 ;
if ( ( V_37 == 0 ) && ( V_38 == 0 ) )
V_38 = 1 ;
break;
case V_90 :
F_2 ( V_72 , L_74 ) ;
break;
case V_92 :
F_2 ( V_1 , L_75 , F_31 () ) ;
goto V_86;
case V_91 :
F_2 ( V_72 , L_76 ) ;
goto V_86;
case V_93 :
F_21 ( V_1 ) ;
goto V_86;
}
}
#ifdef F_4
else if ( ( F_50 () ) || ( V_84 == F_51 ( F_52 ( V_85 ) , 0 ) ) )
#else
else if ( F_53 ( fileno ( V_81 ) , & V_19 ) )
#endif
{
if ( V_35 )
{
int V_96 , V_97 ;
V_45 = F_63 ( fileno ( V_81 ) , V_13 , V_61 / 2 ) ;
V_97 = 0 ;
for ( V_96 = 0 ; V_96 < V_45 ; V_96 ++ )
if ( V_13 [ V_96 ] == '\n' )
V_97 ++ ;
for ( V_96 = V_45 - 1 ; V_96 >= 0 ; V_96 -- )
{
V_13 [ V_96 + V_97 ] = V_13 [ V_96 ] ;
if ( V_13 [ V_96 ] == '\n' )
{
V_97 -- ;
V_45 ++ ;
V_13 [ V_96 + V_97 ] = '\r' ;
}
}
assert ( V_97 == 0 ) ;
}
else
V_45 = F_63 ( fileno ( V_81 ) , V_13 , V_61 ) ;
if ( ( ! V_56 ) && ( ( V_45 <= 0 ) || ( V_13 [ 0 ] == 'Q' ) ) )
{
F_2 ( V_1 , L_70 ) ;
goto V_86;
}
if ( ( ! V_56 ) && ( V_13 [ 0 ] == 'R' ) )
{
F_2 ( V_1 , L_77 ) ;
F_60 ( V_7 ) ;
V_15 = 0 ;
}
else
{
V_15 = V_45 ;
V_16 = 0 ;
#ifdef F_56
F_64 ( V_13 , V_13 , V_45 ) ;
#endif
}
V_38 = 1 ;
V_37 = 0 ;
}
}
V_86:
F_46 ( V_7 ) ;
F_32 ( F_41 ( V_7 ) ) ;
V_43 = 0 ;
V_62:
if( V_47 ) F_45 ( V_72 , V_7 , 1 ) ;
if ( V_7 != NULL ) F_65 ( V_7 ) ;
if ( V_8 != NULL ) F_65 ( V_8 ) ;
if ( V_42 != NULL ) F_66 ( V_42 ) ;
if ( V_13 != NULL ) { memset ( V_13 , 0 , V_61 ) ; F_67 ( V_13 ) ; }
if ( V_14 != NULL ) { memset ( V_14 , 0 , V_61 ) ; F_67 ( V_14 ) ; }
if ( V_72 != NULL )
{
F_68 ( V_72 ) ;
V_72 = NULL ;
}
EXIT ( V_43 ) ;
}
static void F_45 ( T_5 * V_98 , T_1 * V_9 , int V_99 )
{
T_6 * V_100 = NULL ;
char * V_101 ;
static char * V_102 = L_78 ;
char V_103 [ V_104 ] ;
F_69 ( T_6 ) * V_105 ;
F_69 ( V_106 ) * V_107 ;
T_7 * V_108 ;
V_106 * V_109 ;
int V_96 , V_45 ;
if ( V_99 )
{
int V_110 = 0 ;
V_105 = F_70 ( V_9 ) ;
if ( V_105 != NULL )
{
V_110 = 1 ;
F_2 ( V_98 , L_79 ) ;
for ( V_45 = 0 ; V_45 < F_71 ( V_105 ) ; V_45 ++ )
{
F_72 ( F_73 (
F_74 ( V_105 , V_45 ) ) , V_103 , V_104 ) ;
F_2 ( V_98 , L_80 , V_45 , V_103 ) ;
F_72 ( F_75 (
F_74 ( V_105 , V_45 ) ) , V_103 , V_104 ) ;
F_2 ( V_98 , L_81 , V_103 ) ;
if ( V_58 )
F_76 ( V_98 , F_74 ( V_105 , V_45 ) ) ;
}
}
F_2 ( V_98 , L_82 ) ;
V_100 = F_77 ( V_9 ) ;
if ( V_100 != NULL )
{
F_2 ( V_98 , L_83 ) ;
if ( ! ( V_58 && V_110 ) )
F_76 ( V_98 , V_100 ) ;
F_72 ( F_73 ( V_100 ) ,
V_103 , V_104 ) ;
F_2 ( V_98 , L_84 , V_103 ) ;
F_72 ( F_75 ( V_100 ) ,
V_103 , V_104 ) ;
F_2 ( V_98 , L_85 , V_103 ) ;
}
else
F_2 ( V_98 , L_86 ) ;
V_107 = F_78 ( V_9 ) ;
if ( ( V_107 != NULL ) && ( F_79 ( V_107 ) > 0 ) )
{
F_2 ( V_98 , L_87 ) ;
for ( V_45 = 0 ; V_45 < F_79 ( V_107 ) ; V_45 ++ )
{
V_109 = F_80 ( V_107 , V_45 ) ;
F_72 ( V_109 , V_103 , sizeof( V_103 ) ) ;
F_81 ( V_98 , V_103 , strlen ( V_103 ) ) ;
F_81 ( V_98 , L_2 , 1 ) ;
}
}
else
{
F_2 ( V_98 , L_88 ) ;
}
V_101 = F_82 ( V_9 , V_103 , V_104 ) ;
if ( V_101 != NULL )
{
F_2 ( V_98 , L_89 ) ;
V_96 = V_45 = 0 ;
while ( * V_101 )
{
if ( * V_101 == ':' )
{
F_81 ( V_98 , V_102 , 15 - V_96 % 25 ) ;
V_45 ++ ;
V_96 = 0 ;
F_81 ( V_98 , ( ( V_45 % 3 ) ? L_90 : L_2 ) , 1 ) ;
}
else
{
F_81 ( V_98 , V_101 , 1 ) ;
V_96 ++ ;
}
V_101 ++ ;
}
F_81 ( V_98 , L_2 , 1 ) ;
}
F_2 ( V_98 , L_91 ,
F_83 ( F_84 ( V_9 ) ) ,
F_85 ( F_86 ( V_9 ) ) ) ;
}
F_2 ( V_98 , ( ( V_9 -> V_111 ) ? L_92 : L_93 ) ) ;
V_108 = F_87 ( V_9 ) ;
F_2 ( V_98 , L_94 ,
F_88 ( V_108 ) ,
F_89 ( V_108 ) ) ;
if ( V_100 != NULL ) {
T_8 * V_112 ;
V_112 = F_90 ( V_100 ) ;
F_2 ( V_98 , L_95 ,
F_91 ( V_112 ) ) ;
F_92 ( V_112 ) ;
}
F_93 ( V_98 , F_94 ( V_9 ) ) ;
F_2 ( V_98 , L_82 ) ;
if ( V_100 != NULL )
F_95 ( V_100 ) ;
}
