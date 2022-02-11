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
#ifdef F_4
F_2 ( V_1 , L_19 ) ;
#endif
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
#ifdef F_4
int V_35 = 0 ;
#endif
int V_36 , V_37 , V_38 , V_39 , V_40 , V_41 ;
T_3 * V_42 = NULL ;
int V_43 = 1 , V_44 = 1 , V_45 , V_46 = 0 ;
T_4 * V_47 = NULL ;
T_5 * V_48 ;
#if ! F_5 ( V_49 ) && ! F_5 ( V_50 )
V_47 = F_6 () ;
#elif ! F_5 ( V_50 )
V_47 = F_7 () ;
#elif ! F_5 ( V_49 )
V_47 = F_8 () ;
#endif
F_9 () ;
V_51 = 0 ;
V_52 = 0 ;
V_53 = 0 ;
V_54 = 0 ;
if ( V_1 == NULL )
V_1 = F_10 ( V_55 , V_56 ) ;
if ( ( ( V_13 = Malloc ( V_57 ) ) == NULL ) ||
( ( V_14 = Malloc ( V_57 ) ) == NULL ) )
{
F_2 ( V_1 , L_28 ) ;
goto V_58;
}
V_59 = 0 ;
V_60 = V_61 ;
#ifdef F_3
V_62 = 0 ;
#endif
V_4 -- ;
V_5 ++ ;
while ( V_4 >= 1 )
{
if ( strcmp ( * V_5 , L_29 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_63;
V_24 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_30 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_63;
V_21 = atoi ( * ( ++ V_5 ) ) ;
if ( V_21 == 0 ) goto V_63;
}
else if ( strcmp ( * V_5 , L_31 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_63;
if ( ! F_11 ( * ( ++ V_5 ) , & V_24 , NULL , & V_21 ) )
goto V_63;
}
else if ( strcmp ( * V_5 , L_32 ) == 0 )
{
V_32 = V_64 ;
if ( -- V_4 < 1 ) goto V_63;
V_59 = atoi ( * ( ++ V_5 ) ) ;
F_2 ( V_1 , L_33 , V_59 ) ;
}
else if ( strcmp ( * V_5 , L_34 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_63;
V_25 = * ( ++ V_5 ) ;
}
#ifdef F_4
else if ( strcmp ( * V_5 , L_35 ) == 0 )
V_35 = 1 ;
#endif
else if ( strcmp ( * V_5 , L_36 ) == 0 )
V_52 = 1 ;
else if ( strcmp ( * V_5 , L_37 ) == 0 )
V_51 = 1 ;
else if ( strcmp ( * V_5 , L_38 ) == 0 )
V_53 = 1 ;
else if ( strcmp ( * V_5 , L_39 ) == 0 )
V_54 = 1 ;
else if ( strcmp ( * V_5 , L_40 ) == 0 )
V_46 = 1 ;
else if ( strcmp ( * V_5 , L_41 ) == 0 )
V_12 = 1 ;
#ifndef V_49
else if ( strcmp ( * V_5 , L_42 ) == 0 )
V_47 = F_8 () ;
#endif
#ifndef V_50
else if ( strcmp ( * V_5 , L_43 ) == 0 )
V_47 = F_7 () ;
#endif
#ifndef F_12
else if ( strcmp ( * V_5 , L_44 ) == 0 )
V_47 = F_13 () ;
#endif
else if ( strcmp ( * V_5 , L_45 ) == 0 )
V_34 = 1 ;
else if ( strcmp ( * V_5 , L_46 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_63;
V_26 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_47 ) == 0 )
{
V_30 = 5 ;
}
else if ( strcmp ( * V_5 , L_48 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_63;
V_27 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_49 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_63;
V_28 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_50 ) == 0 )
V_6 |= V_65 ;
else if ( strcmp ( * V_5 , L_51 ) == 0 )
V_6 |= V_66 ;
else if ( strcmp ( * V_5 , L_52 ) == 0 )
V_6 |= V_67 ;
else if ( strcmp ( * V_5 , L_53 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_63;
V_29 = * ( ++ V_5 ) ;
}
#ifdef F_3
else if ( strcmp ( * V_5 , L_54 ) == 0 )
{ V_62 = 1 ; }
#endif
else
{
F_2 ( V_1 , L_55 , * V_5 ) ;
V_31 = 1 ;
break;
}
V_4 -- ;
V_5 ++ ;
}
if ( V_31 )
{
V_63:
F_1 () ;
goto V_58;
}
if ( V_68 == NULL )
{
if ( V_52 )
{
V_68 = F_14 ( F_15 () ) ;
}
else
{
if ( V_68 == NULL )
V_68 = F_10 ( stdout , V_56 ) ;
}
}
F_16 () ;
V_42 = F_17 ( V_47 ) ;
if ( V_42 == NULL )
{
F_18 ( V_1 ) ;
goto V_58;
}
if ( V_34 )
F_19 ( V_42 , V_69 | V_6 ) ;
else
F_19 ( V_42 , V_6 ) ;
if ( V_12 ) F_20 ( V_42 , V_70 ) ;
if ( V_29 != NULL )
F_21 ( V_42 , V_29 ) ;
#if 0
else
SSL_CTX_set_cipher_list(ctx,getenv("SSL_CIPHER"));
#endif
F_22 ( V_42 , V_32 , V_71 ) ;
if ( ! F_23 ( V_42 , V_25 , V_26 ) )
goto V_58;
if ( ( ! F_24 ( V_42 , V_28 , V_27 ) ) ||
( ! F_25 ( V_42 ) ) )
{
F_18 ( V_1 ) ;
}
F_26 () ;
V_7 = ( T_1 * ) F_27 ( V_42 ) ;
V_72:
if ( F_28 ( & V_9 , V_24 , V_21 ) == 0 )
{
F_2 ( V_1 , L_56 , F_29 () ) ;
F_30 ( V_9 ) ;
goto V_58;
}
F_2 ( V_68 , L_57 , V_9 ) ;
#ifdef F_3
if ( V_62 )
{
unsigned long V_73 = 1 ;
F_2 ( V_68 , L_58 ) ;
if ( F_31 ( V_9 , F_3 , & V_73 ) < 0 )
{
F_18 ( V_1 ) ;
goto V_58;
}
}
#endif
if ( V_51 & 0x01 ) V_7 -> V_74 = 1 ;
V_48 = F_32 ( V_9 , V_56 ) ;
if ( V_46 )
{
T_5 * V_75 ;
V_75 = F_14 ( F_33 () ) ;
V_48 = F_34 ( V_75 , V_48 ) ;
}
if ( V_53 )
{
V_7 -> V_74 = 1 ;
F_35 ( V_48 , V_76 ) ;
F_36 ( V_48 , V_68 ) ;
}
F_37 ( V_7 , V_48 , V_48 ) ;
F_38 ( V_7 ) ;
V_11 = F_39 ( V_7 ) + 1 ;
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
F_40 ( & V_19 ) ;
F_40 ( & V_20 ) ;
if ( F_41 ( V_7 ) && ! F_42 ( V_7 ) )
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
F_43 ( V_68 , V_7 , V_23 ) ;
if ( V_23 > 0 ) V_23 -- ;
if ( V_30 )
{
V_30 -- ;
F_2 ( V_68 , L_59 ) ;
F_44 ( V_7 ) ;
F_38 ( V_7 ) ;
F_30 ( F_39 ( V_7 ) ) ;
goto V_72;
}
}
}
V_41 = V_39 && F_45 ( V_7 ) ;
if ( ! V_41 )
{
#ifndef F_46
if ( V_40 )
{
if ( V_37 ) F_47 ( fileno ( V_77 ) , & V_19 ) ;
if ( V_36 ) F_47 ( fileno ( stdout ) , & V_20 ) ;
}
#endif
if ( V_39 )
F_47 ( F_39 ( V_7 ) , & V_19 ) ;
if ( V_38 )
F_47 ( F_39 ( V_7 ) , & V_20 ) ;
V_45 = F_48 ( V_11 , ( void * ) & V_19 , ( void * ) & V_20 ,
NULL , NULL ) ;
if ( V_45 < 0 )
{
F_2 ( V_1 , L_60 ,
F_29 () ) ;
goto V_78;
}
}
if ( ! V_41 && F_49 ( F_39 ( V_7 ) , & V_20 ) )
{
V_10 = F_50 ( V_7 , & ( V_13 [ V_16 ] ) ,
( unsigned int ) V_15 ) ;
switch ( F_51 ( V_7 , V_10 ) )
{
case V_79 :
V_16 += V_10 ;
V_15 -= V_10 ;
if ( V_10 <= 0 ) goto V_58;
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
case V_80 :
F_2 ( V_68 , L_61 ) ;
V_38 = 1 ;
V_37 = 0 ;
break;
case V_81 :
F_2 ( V_68 , L_62 ) ;
V_36 = 0 ;
V_39 = 1 ;
V_38 = 0 ;
break;
case V_82 :
F_2 ( V_68 , L_63 ) ;
break;
case V_83 :
if ( V_15 != 0 )
{
F_2 ( V_68 , L_64 ) ;
goto V_78;
}
else
{
V_37 = 1 ;
V_38 = 0 ;
break;
}
case V_84 :
if ( ( V_10 != 0 ) || ( V_15 != 0 ) )
{
F_2 ( V_1 , L_65 ,
F_29 () ) ;
goto V_78;
}
else
{
V_37 = 1 ;
V_38 = 0 ;
}
break;
case V_85 :
F_18 ( V_1 ) ;
goto V_78;
}
}
#ifndef F_46
else if ( ! V_41 && F_49 ( fileno ( stdout ) , & V_20 ) )
{
#ifdef F_52
F_53 ( & ( V_14 [ V_18 ] ) , & ( V_14 [ V_18 ] ) , V_17 ) ;
#endif
V_45 = F_54 ( fileno ( stdout ) , & ( V_14 [ V_18 ] ) , V_17 ) ;
if ( V_45 <= 0 )
{
F_2 ( V_68 , L_66 ) ;
goto V_78;
}
V_17 -= V_45 ; ;
V_18 += V_45 ;
if ( V_17 <= 0 )
{
V_39 = 1 ;
V_36 = 0 ;
}
}
#endif
else if ( V_41 || F_49 ( F_39 ( V_7 ) , & V_19 ) )
{
#ifdef F_55
{ static int V_86 ; if ( ++ V_86 == 52 ) { F_56 ( V_7 ) ; V_86 = 0 ; } }
#endif
#if 1
V_10 = F_57 ( V_7 , V_14 , 1024 ) ;
#else
V_10 = F_57 ( V_7 , V_14 , 16 ) ;
{ char V_87 [ 10240 ] ;
printf ( L_67 , V_10 , F_45 ( V_7 ) , F_58 ( V_7 , V_87 , 10240 ) ) ;
}
#endif
switch ( F_51 ( V_7 , V_10 ) )
{
case V_79 :
if ( V_10 <= 0 )
goto V_58;
V_18 = 0 ;
V_17 = V_10 ;
V_39 = 0 ;
V_36 = 1 ;
break;
case V_80 :
F_2 ( V_68 , L_68 ) ;
V_38 = 1 ;
V_37 = 0 ;
break;
case V_81 :
F_2 ( V_68 , L_69 ) ;
V_36 = 0 ;
V_39 = 1 ;
if ( ( V_37 == 0 ) && ( V_38 == 0 ) )
V_38 = 1 ;
break;
case V_82 :
F_2 ( V_68 , L_70 ) ;
break;
case V_84 :
F_2 ( V_1 , L_71 , F_29 () ) ;
goto V_78;
case V_83 :
F_2 ( V_68 , L_72 ) ;
goto V_78;
case V_85 :
F_18 ( V_1 ) ;
goto V_78;
}
}
#ifndef F_46
else if ( F_49 ( fileno ( V_77 ) , & V_19 ) )
{
#ifdef F_4
if ( V_35 )
{
int V_88 , V_89 ;
V_45 = F_59 ( fileno ( V_77 ) , V_13 , V_57 / 2 ) ;
V_89 = 0 ;
for ( V_88 = 0 ; V_88 < V_45 ; V_88 ++ )
if ( V_13 [ V_88 ] == '\n' )
V_89 ++ ;
for ( V_88 = V_45 - 1 ; V_88 >= 0 ; V_88 -- )
{
V_13 [ V_88 + V_89 ] = V_13 [ V_88 ] ;
if ( V_13 [ V_88 ] == '\n' )
{
V_89 -- ;
V_45 ++ ;
V_13 [ V_88 + V_89 ] = '\r' ;
}
}
assert ( V_89 == 0 ) ;
}
else
#endif
V_45 = F_59 ( fileno ( V_77 ) , V_13 , V_57 ) ;
if ( ( ! V_52 ) && ( ( V_45 <= 0 ) || ( V_13 [ 0 ] == 'Q' ) ) )
{
F_2 ( V_1 , L_66 ) ;
goto V_78;
}
if ( ( ! V_52 ) && ( V_13 [ 0 ] == 'R' ) )
{
F_2 ( V_1 , L_73 ) ;
F_56 ( V_7 ) ;
V_15 = 0 ;
}
else
{
V_15 = V_45 ;
V_16 = 0 ;
#ifdef F_52
F_60 ( V_13 , V_13 , V_45 ) ;
#endif
}
V_38 = 1 ;
V_37 = 0 ;
}
#endif
}
V_78:
F_44 ( V_7 ) ;
F_30 ( F_39 ( V_7 ) ) ;
V_43 = 0 ;
V_58:
if ( V_7 != NULL ) F_61 ( V_7 ) ;
if ( V_8 != NULL ) F_61 ( V_8 ) ;
if ( V_42 != NULL ) F_62 ( V_42 ) ;
if ( V_13 != NULL ) { memset ( V_13 , 0 , V_57 ) ; Free ( V_13 ) ; }
if ( V_14 != NULL ) { memset ( V_14 , 0 , V_57 ) ; Free ( V_14 ) ; }
if ( V_68 != NULL )
{
F_63 ( V_68 ) ;
V_68 = NULL ;
}
EXIT ( V_43 ) ;
}
static void F_43 ( T_5 * V_90 , T_1 * V_9 , int V_91 )
{
T_6 * V_92 = NULL ;
char * V_93 ;
static char * V_94 = L_74 ;
char V_95 [ V_96 ] ;
F_64 ( T_6 ) * V_97 ;
F_64 ( V_98 ) * V_99 ;
T_7 * V_100 ;
V_98 * V_101 ;
int V_88 , V_45 ;
if ( V_91 )
{
int V_102 = 0 ;
V_97 = F_65 ( V_9 ) ;
if ( V_97 != NULL )
{
V_102 = 1 ;
F_2 ( V_90 , L_75 ) ;
for ( V_45 = 0 ; V_45 < F_66 ( V_97 ) ; V_45 ++ )
{
F_67 ( F_68 (
F_69 ( V_97 , V_45 ) ) , V_95 , V_96 ) ;
F_2 ( V_90 , L_76 , V_45 , V_95 ) ;
F_67 ( F_70 (
F_69 ( V_97 , V_45 ) ) , V_95 , V_96 ) ;
F_2 ( V_90 , L_77 , V_95 ) ;
if ( V_54 )
F_71 ( V_90 , F_69 ( V_97 , V_45 ) ) ;
}
}
F_2 ( V_90 , L_78 ) ;
V_92 = F_72 ( V_9 ) ;
if ( V_92 != NULL )
{
F_2 ( V_90 , L_79 ) ;
if ( ! ( V_54 && V_102 ) )
F_71 ( V_90 , V_92 ) ;
F_67 ( F_68 ( V_92 ) ,
V_95 , V_96 ) ;
F_2 ( V_90 , L_80 , V_95 ) ;
F_67 ( F_70 ( V_92 ) ,
V_95 , V_96 ) ;
F_2 ( V_90 , L_81 , V_95 ) ;
}
else
F_2 ( V_90 , L_82 ) ;
V_99 = F_73 ( V_9 ) ;
if ( ( V_99 != NULL ) && ( F_74 ( V_99 ) > 0 ) )
{
F_2 ( V_90 , L_83 ) ;
for ( V_45 = 0 ; V_45 < F_74 ( V_99 ) ; V_45 ++ )
{
V_101 = F_75 ( V_99 , V_45 ) ;
F_67 ( V_101 , V_95 , sizeof( V_95 ) ) ;
F_76 ( V_90 , V_95 , strlen ( V_95 ) ) ;
F_76 ( V_90 , L_2 , 1 ) ;
}
}
else
{
F_2 ( V_90 , L_84 ) ;
}
V_93 = F_77 ( V_9 , V_95 , V_96 ) ;
if ( V_93 != NULL )
{
F_2 ( V_90 , L_85 ) ;
V_88 = V_45 = 0 ;
while ( * V_93 )
{
if ( * V_93 == ':' )
{
F_76 ( V_90 , V_94 , 15 - V_88 % 25 ) ;
V_45 ++ ;
V_88 = 0 ;
F_76 ( V_90 , ( ( V_45 % 3 ) ? L_86 : L_2 ) , 1 ) ;
}
else
{
F_76 ( V_90 , V_93 , 1 ) ;
V_88 ++ ;
}
V_93 ++ ;
}
F_76 ( V_90 , L_2 , 1 ) ;
}
F_2 ( V_90 , L_87 ,
F_78 ( F_79 ( V_9 ) ) ,
F_80 ( F_81 ( V_9 ) ) ) ;
}
F_2 ( V_90 , ( ( V_9 -> V_103 ) ? L_88 : L_89 ) ) ;
V_100 = F_82 ( V_9 ) ;
F_2 ( V_90 , L_90 ,
F_83 ( V_100 ) ,
F_84 ( V_100 ) ) ;
if ( V_92 != NULL ) {
T_8 * V_104 ;
V_104 = F_85 ( V_92 ) ;
F_2 ( V_90 , L_91 ,
F_86 ( V_104 ) ) ;
F_87 ( V_104 ) ;
}
F_88 ( V_90 , F_89 ( V_9 ) ) ;
F_2 ( V_90 , L_78 ) ;
if ( V_92 != NULL )
F_90 ( V_92 ) ;
}
