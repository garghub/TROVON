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
if ( V_1 == NULL )
V_1 = F_10 ( V_58 , V_59 ) ;
if ( ( ( V_13 = Malloc ( V_60 ) ) == NULL ) ||
( ( V_14 = Malloc ( V_60 ) ) == NULL ) )
{
F_2 ( V_1 , L_28 ) ;
goto V_61;
}
V_62 = 0 ;
V_63 = V_64 ;
#ifdef F_3
V_65 = 0 ;
#endif
V_4 -- ;
V_5 ++ ;
while ( V_4 >= 1 )
{
if ( strcmp ( * V_5 , L_29 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_66;
V_24 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_30 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_66;
V_21 = atoi ( * ( ++ V_5 ) ) ;
if ( V_21 == 0 ) goto V_66;
}
else if ( strcmp ( * V_5 , L_31 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_66;
if ( ! F_11 ( * ( ++ V_5 ) , & V_24 , NULL , & V_21 ) )
goto V_66;
}
else if ( strcmp ( * V_5 , L_32 ) == 0 )
{
V_32 = V_67 ;
if ( -- V_4 < 1 ) goto V_66;
V_62 = atoi ( * ( ++ V_5 ) ) ;
F_2 ( V_1 , L_33 , V_62 ) ;
}
else if ( strcmp ( * V_5 , L_34 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_66;
V_25 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_35 ) == 0 )
V_47 = 1 ;
else if ( strcmp ( * V_5 , L_36 ) == 0 )
V_35 = 1 ;
else if ( strcmp ( * V_5 , L_37 ) == 0 )
V_55 = 1 ;
else if ( strcmp ( * V_5 , L_38 ) == 0 )
V_54 = 1 ;
else if ( strcmp ( * V_5 , L_39 ) == 0 )
V_56 = 1 ;
else if ( strcmp ( * V_5 , L_40 ) == 0 )
V_57 = 1 ;
else if ( strcmp ( * V_5 , L_41 ) == 0 )
V_46 = 1 ;
else if ( strcmp ( * V_5 , L_42 ) == 0 )
V_12 = 1 ;
#ifndef V_52
else if ( strcmp ( * V_5 , L_43 ) == 0 )
V_48 = F_8 () ;
#endif
#ifndef V_53
else if ( strcmp ( * V_5 , L_44 ) == 0 )
V_48 = F_7 () ;
#endif
#ifndef F_12
else if ( strcmp ( * V_5 , L_45 ) == 0 )
V_48 = F_13 () ;
#endif
else if ( strcmp ( * V_5 , L_46 ) == 0 )
V_34 = 1 ;
else if ( strcmp ( * V_5 , L_47 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_66;
V_26 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_48 ) == 0 )
{
V_30 = 5 ;
}
else if ( strcmp ( * V_5 , L_49 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_66;
V_27 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_50 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_66;
V_28 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_51 ) == 0 )
V_6 |= V_68 ;
else if ( strcmp ( * V_5 , L_52 ) == 0 )
V_6 |= V_69 ;
else if ( strcmp ( * V_5 , L_53 ) == 0 )
V_6 |= V_70 ;
else if ( strcmp ( * V_5 , L_54 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_66;
V_29 = * ( ++ V_5 ) ;
}
#ifdef F_3
else if ( strcmp ( * V_5 , L_55 ) == 0 )
{ V_65 = 1 ; }
#endif
else
{
F_2 ( V_1 , L_56 , * V_5 ) ;
V_31 = 1 ;
break;
}
V_4 -- ;
V_5 ++ ;
}
if ( V_31 )
{
V_66:
F_1 () ;
goto V_61;
}
F_14 ( NULL , V_1 , 0 ) ;
if ( V_71 == NULL )
{
if ( V_55 )
{
V_71 = F_15 ( F_16 () ) ;
}
else
{
if ( V_71 == NULL )
V_71 = F_10 ( stdout , V_59 ) ;
}
}
F_17 () ;
F_18 () ;
V_42 = F_19 ( V_48 ) ;
if ( V_42 == NULL )
{
F_20 ( V_1 ) ;
goto V_61;
}
if ( V_34 )
F_21 ( V_42 , V_72 | V_6 ) ;
else
F_21 ( V_42 , V_6 ) ;
if ( V_12 ) F_22 ( V_42 , V_73 ) ;
if ( V_29 != NULL )
if( ! F_23 ( V_42 , V_29 ) ) {
F_2 ( V_1 , L_57 ) ;
F_20 ( V_1 ) ;
goto V_61;
}
#if 0
else
SSL_CTX_set_cipher_list(ctx,getenv("SSL_CIPHER"));
#endif
F_24 ( V_42 , V_32 , V_74 ) ;
if ( ! F_25 ( V_42 , V_25 , V_26 ) )
goto V_61;
if ( ( ! F_26 ( V_42 , V_28 , V_27 ) ) ||
( ! F_27 ( V_42 ) ) )
{
F_20 ( V_1 ) ;
}
V_7 = F_28 ( V_42 ) ;
V_75:
if ( F_29 ( & V_9 , V_24 , V_21 ) == 0 )
{
F_2 ( V_1 , L_58 , F_30 () ) ;
F_31 ( V_9 ) ;
goto V_61;
}
F_2 ( V_71 , L_59 , V_9 ) ;
#ifdef F_3
if ( V_65 )
{
unsigned long V_76 = 1 ;
F_2 ( V_71 , L_60 ) ;
if ( F_32 ( V_9 , F_3 , & V_76 ) < 0 )
{
F_20 ( V_1 ) ;
goto V_61;
}
}
#endif
if ( V_54 & 0x01 ) V_7 -> V_77 = 1 ;
V_49 = F_33 ( V_9 , V_59 ) ;
if ( V_46 )
{
T_5 * V_78 ;
V_78 = F_15 ( F_34 () ) ;
V_49 = F_35 ( V_78 , V_49 ) ;
}
if ( V_56 )
{
V_7 -> V_77 = 1 ;
F_36 ( V_49 , V_79 ) ;
F_37 ( V_49 , V_71 ) ;
}
F_38 ( V_7 , V_49 , V_49 ) ;
F_39 ( V_7 ) ;
V_11 = F_40 ( V_7 ) + 1 ;
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
F_41 ( & V_19 ) ;
F_41 ( & V_20 ) ;
if ( F_42 ( V_7 ) && ! F_43 ( V_7 ) )
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
F_44 ( V_71 , V_7 , V_23 ) ;
if ( V_23 > 0 ) V_23 -- ;
if ( V_30 )
{
V_30 -- ;
F_2 ( V_71 , L_61 ) ;
F_45 ( V_7 ) ;
F_39 ( V_7 ) ;
F_31 ( F_40 ( V_7 ) ) ;
goto V_75;
}
}
}
V_41 = V_39 && F_46 ( V_7 ) ;
if ( ! V_41 )
{
#ifndef F_4
if ( V_40 )
{
if ( V_37 ) F_47 ( fileno ( V_80 ) , & V_19 ) ;
if ( V_36 ) F_47 ( fileno ( stdout ) , & V_20 ) ;
}
if ( V_39 )
F_47 ( F_40 ( V_7 ) , & V_19 ) ;
if ( V_38 )
F_47 ( F_40 ( V_7 ) , & V_20 ) ;
#else
if( ! V_40 || ! V_36 ) {
if ( V_39 )
F_47 ( F_40 ( V_7 ) , & V_19 ) ;
if ( V_38 )
F_47 ( F_40 ( V_7 ) , & V_20 ) ;
}
#endif
#ifdef F_4
V_45 = 0 ;
if( ! V_36 ) {
if( V_37 ) {
V_51 . V_81 = 1 ;
V_51 . V_82 = 0 ;
V_45 = F_48 ( V_11 , ( void * ) & V_19 , ( void * ) & V_20 ,
NULL , & V_51 ) ;
if( ! V_45 && ( ! F_49 () || ! V_37 ) ) continue;
} else V_45 = F_48 ( V_11 , ( void * ) & V_19 , ( void * ) & V_20 ,
NULL , NULL ) ;
}
#else
V_45 = F_48 ( V_11 , ( void * ) & V_19 , ( void * ) & V_20 ,
NULL , NULL ) ;
#endif
if ( V_45 < 0 )
{
F_2 ( V_1 , L_62 ,
F_30 () ) ;
goto V_83;
}
}
if ( ! V_41 && F_50 ( F_40 ( V_7 ) , & V_20 ) )
{
V_10 = F_51 ( V_7 , & ( V_13 [ V_16 ] ) ,
( unsigned int ) V_15 ) ;
switch ( F_52 ( V_7 , V_10 ) )
{
case V_84 :
V_16 += V_10 ;
V_15 -= V_10 ;
if ( V_10 <= 0 ) goto V_61;
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
case V_85 :
F_2 ( V_71 , L_63 ) ;
V_38 = 1 ;
V_37 = 0 ;
break;
case V_86 :
F_2 ( V_71 , L_64 ) ;
V_36 = 0 ;
V_39 = 1 ;
V_38 = 0 ;
break;
case V_87 :
F_2 ( V_71 , L_65 ) ;
break;
case V_88 :
if ( V_15 != 0 )
{
F_2 ( V_71 , L_66 ) ;
goto V_83;
}
else
{
V_37 = 1 ;
V_38 = 0 ;
break;
}
case V_89 :
if ( ( V_10 != 0 ) || ( V_15 != 0 ) )
{
F_2 ( V_1 , L_67 ,
F_30 () ) ;
goto V_83;
}
else
{
V_37 = 1 ;
V_38 = 0 ;
}
break;
case V_90 :
F_20 ( V_1 ) ;
goto V_83;
}
}
#ifdef F_4
else if ( ! V_41 && V_36 )
#else
else if ( ! V_41 && F_50 ( fileno ( stdout ) , & V_20 ) )
#endif
{
#ifdef F_53
F_54 ( & ( V_14 [ V_18 ] ) , & ( V_14 [ V_18 ] ) , V_17 ) ;
#endif
V_45 = F_55 ( fileno ( stdout ) , & ( V_14 [ V_18 ] ) , V_17 ) ;
if ( V_45 <= 0 )
{
F_2 ( V_71 , L_68 ) ;
goto V_83;
}
V_17 -= V_45 ; ;
V_18 += V_45 ;
if ( V_17 <= 0 )
{
V_39 = 1 ;
V_36 = 0 ;
}
}
else if ( V_41 || F_50 ( F_40 ( V_7 ) , & V_19 ) )
{
#ifdef F_56
{ static int V_91 ; if ( ++ V_91 == 52 ) { F_57 ( V_7 ) ; V_91 = 0 ; } }
#endif
#if 1
V_10 = F_58 ( V_7 , V_14 , 1024 ) ;
#else
V_10 = F_58 ( V_7 , V_14 , 16 ) ;
{ char V_92 [ 10240 ] ;
printf ( L_69 , V_10 , F_46 ( V_7 ) , F_59 ( V_7 , V_92 , 10240 ) ) ;
}
#endif
switch ( F_52 ( V_7 , V_10 ) )
{
case V_84 :
if ( V_10 <= 0 )
goto V_61;
V_18 = 0 ;
V_17 = V_10 ;
V_39 = 0 ;
V_36 = 1 ;
break;
case V_85 :
F_2 ( V_71 , L_70 ) ;
V_38 = 1 ;
V_37 = 0 ;
break;
case V_86 :
F_2 ( V_71 , L_71 ) ;
V_36 = 0 ;
V_39 = 1 ;
if ( ( V_37 == 0 ) && ( V_38 == 0 ) )
V_38 = 1 ;
break;
case V_87 :
F_2 ( V_71 , L_72 ) ;
break;
case V_89 :
F_2 ( V_1 , L_73 , F_30 () ) ;
goto V_83;
case V_88 :
F_2 ( V_71 , L_74 ) ;
goto V_83;
case V_90 :
F_20 ( V_1 ) ;
goto V_83;
}
}
#ifdef F_4
else if ( F_49 () )
#else
else if ( F_50 ( fileno ( V_80 ) , & V_19 ) )
#endif
{
if ( V_35 )
{
int V_93 , V_94 ;
V_45 = F_60 ( fileno ( V_80 ) , V_13 , V_60 / 2 ) ;
V_94 = 0 ;
for ( V_93 = 0 ; V_93 < V_45 ; V_93 ++ )
if ( V_13 [ V_93 ] == '\n' )
V_94 ++ ;
for ( V_93 = V_45 - 1 ; V_93 >= 0 ; V_93 -- )
{
V_13 [ V_93 + V_94 ] = V_13 [ V_93 ] ;
if ( V_13 [ V_93 ] == '\n' )
{
V_94 -- ;
V_45 ++ ;
V_13 [ V_93 + V_94 ] = '\r' ;
}
}
assert ( V_94 == 0 ) ;
}
else
V_45 = F_60 ( fileno ( V_80 ) , V_13 , V_60 ) ;
if ( ( ! V_55 ) && ( ( V_45 <= 0 ) || ( V_13 [ 0 ] == 'Q' ) ) )
{
F_2 ( V_1 , L_68 ) ;
goto V_83;
}
if ( ( ! V_55 ) && ( V_13 [ 0 ] == 'R' ) )
{
F_2 ( V_1 , L_75 ) ;
F_57 ( V_7 ) ;
V_15 = 0 ;
}
else
{
V_15 = V_45 ;
V_16 = 0 ;
#ifdef F_53
F_61 ( V_13 , V_13 , V_45 ) ;
#endif
}
V_38 = 1 ;
V_37 = 0 ;
}
}
V_83:
F_45 ( V_7 ) ;
F_31 ( F_40 ( V_7 ) ) ;
V_43 = 0 ;
V_61:
if( V_47 ) F_44 ( V_71 , V_7 , 1 ) ;
if ( V_7 != NULL ) F_62 ( V_7 ) ;
if ( V_8 != NULL ) F_62 ( V_8 ) ;
if ( V_42 != NULL ) F_63 ( V_42 ) ;
if ( V_13 != NULL ) { memset ( V_13 , 0 , V_60 ) ; Free ( V_13 ) ; }
if ( V_14 != NULL ) { memset ( V_14 , 0 , V_60 ) ; Free ( V_14 ) ; }
if ( V_71 != NULL )
{
F_64 ( V_71 ) ;
V_71 = NULL ;
}
EXIT ( V_43 ) ;
}
static void F_44 ( T_5 * V_95 , T_1 * V_9 , int V_96 )
{
T_6 * V_97 = NULL ;
char * V_98 ;
static char * V_99 = L_76 ;
char V_100 [ V_101 ] ;
F_65 ( T_6 ) * V_102 ;
F_65 ( V_103 ) * V_104 ;
T_7 * V_105 ;
V_103 * V_106 ;
int V_93 , V_45 ;
if ( V_96 )
{
int V_107 = 0 ;
V_102 = F_66 ( V_9 ) ;
if ( V_102 != NULL )
{
V_107 = 1 ;
F_2 ( V_95 , L_77 ) ;
for ( V_45 = 0 ; V_45 < F_67 ( V_102 ) ; V_45 ++ )
{
F_68 ( F_69 (
F_70 ( V_102 , V_45 ) ) , V_100 , V_101 ) ;
F_2 ( V_95 , L_78 , V_45 , V_100 ) ;
F_68 ( F_71 (
F_70 ( V_102 , V_45 ) ) , V_100 , V_101 ) ;
F_2 ( V_95 , L_79 , V_100 ) ;
if ( V_57 )
F_72 ( V_95 , F_70 ( V_102 , V_45 ) ) ;
}
}
F_2 ( V_95 , L_80 ) ;
V_97 = F_73 ( V_9 ) ;
if ( V_97 != NULL )
{
F_2 ( V_95 , L_81 ) ;
if ( ! ( V_57 && V_107 ) )
F_72 ( V_95 , V_97 ) ;
F_68 ( F_69 ( V_97 ) ,
V_100 , V_101 ) ;
F_2 ( V_95 , L_82 , V_100 ) ;
F_68 ( F_71 ( V_97 ) ,
V_100 , V_101 ) ;
F_2 ( V_95 , L_83 , V_100 ) ;
}
else
F_2 ( V_95 , L_84 ) ;
V_104 = F_74 ( V_9 ) ;
if ( ( V_104 != NULL ) && ( F_75 ( V_104 ) > 0 ) )
{
F_2 ( V_95 , L_85 ) ;
for ( V_45 = 0 ; V_45 < F_75 ( V_104 ) ; V_45 ++ )
{
V_106 = F_76 ( V_104 , V_45 ) ;
F_68 ( V_106 , V_100 , sizeof( V_100 ) ) ;
F_77 ( V_95 , V_100 , strlen ( V_100 ) ) ;
F_77 ( V_95 , L_2 , 1 ) ;
}
}
else
{
F_2 ( V_95 , L_86 ) ;
}
V_98 = F_78 ( V_9 , V_100 , V_101 ) ;
if ( V_98 != NULL )
{
F_2 ( V_95 , L_87 ) ;
V_93 = V_45 = 0 ;
while ( * V_98 )
{
if ( * V_98 == ':' )
{
F_77 ( V_95 , V_99 , 15 - V_93 % 25 ) ;
V_45 ++ ;
V_93 = 0 ;
F_77 ( V_95 , ( ( V_45 % 3 ) ? L_88 : L_2 ) , 1 ) ;
}
else
{
F_77 ( V_95 , V_98 , 1 ) ;
V_93 ++ ;
}
V_98 ++ ;
}
F_77 ( V_95 , L_2 , 1 ) ;
}
F_2 ( V_95 , L_89 ,
F_79 ( F_80 ( V_9 ) ) ,
F_81 ( F_82 ( V_9 ) ) ) ;
}
F_2 ( V_95 , ( ( V_9 -> V_108 ) ? L_90 : L_91 ) ) ;
V_105 = F_83 ( V_9 ) ;
F_2 ( V_95 , L_92 ,
F_84 ( V_105 ) ,
F_85 ( V_105 ) ) ;
if ( V_97 != NULL ) {
T_8 * V_109 ;
V_109 = F_86 ( V_97 ) ;
F_2 ( V_95 , L_93 ,
F_87 ( V_109 ) ) ;
F_88 ( V_109 ) ;
}
F_89 ( V_95 , F_90 ( V_9 ) ) ;
F_2 ( V_95 , L_80 ) ;
if ( V_97 != NULL )
F_91 ( V_97 ) ;
}
