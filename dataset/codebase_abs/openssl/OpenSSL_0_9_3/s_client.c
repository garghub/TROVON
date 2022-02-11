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
int V_35 , V_36 , V_37 , V_38 , V_39 , V_40 ;
T_3 * V_41 = NULL ;
int V_42 = 1 , V_43 = 1 , V_44 , V_45 = 0 ;
T_4 * V_46 = NULL ;
T_5 * V_47 ;
#if ! F_4 ( V_48 ) && ! F_4 ( V_49 )
V_46 = F_5 () ;
#elif ! F_4 ( V_49 )
V_46 = F_6 () ;
#elif ! F_4 ( V_48 )
V_46 = F_7 () ;
#endif
F_8 () ;
V_50 = 0 ;
V_51 = 0 ;
V_52 = 0 ;
V_53 = 0 ;
if ( V_1 == NULL )
V_1 = F_9 ( V_54 , V_55 ) ;
if ( ( ( V_13 = Malloc ( V_56 ) ) == NULL ) ||
( ( V_14 = Malloc ( V_56 ) ) == NULL ) )
{
F_2 ( V_1 , L_27 ) ;
goto V_57;
}
V_58 = 0 ;
V_59 = V_60 ;
#ifdef F_3
V_61 = 0 ;
#endif
V_4 -- ;
V_5 ++ ;
while ( V_4 >= 1 )
{
if ( strcmp ( * V_5 , L_28 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_62;
V_24 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_29 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_62;
V_21 = atoi ( * ( ++ V_5 ) ) ;
if ( V_21 == 0 ) goto V_62;
}
else if ( strcmp ( * V_5 , L_30 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_62;
if ( ! F_10 ( * ( ++ V_5 ) , & V_24 , NULL , & V_21 ) )
goto V_62;
}
else if ( strcmp ( * V_5 , L_31 ) == 0 )
{
V_32 = V_63 ;
if ( -- V_4 < 1 ) goto V_62;
V_58 = atoi ( * ( ++ V_5 ) ) ;
F_2 ( V_1 , L_32 , V_58 ) ;
}
else if ( strcmp ( * V_5 , L_33 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_62;
V_25 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_34 ) == 0 )
V_51 = 1 ;
else if ( strcmp ( * V_5 , L_35 ) == 0 )
V_50 = 1 ;
else if ( strcmp ( * V_5 , L_36 ) == 0 )
V_52 = 1 ;
else if ( strcmp ( * V_5 , L_37 ) == 0 )
V_53 = 1 ;
else if ( strcmp ( * V_5 , L_38 ) == 0 )
V_45 = 1 ;
else if ( strcmp ( * V_5 , L_39 ) == 0 )
V_12 = 1 ;
#ifndef V_48
else if ( strcmp ( * V_5 , L_40 ) == 0 )
V_46 = F_7 () ;
#endif
#ifndef V_49
else if ( strcmp ( * V_5 , L_41 ) == 0 )
V_46 = F_6 () ;
#endif
#ifndef F_11
else if ( strcmp ( * V_5 , L_42 ) == 0 )
V_46 = F_12 () ;
#endif
else if ( strcmp ( * V_5 , L_43 ) == 0 )
V_34 = 1 ;
else if ( strcmp ( * V_5 , L_44 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_62;
V_26 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_45 ) == 0 )
{
V_30 = 5 ;
}
else if ( strcmp ( * V_5 , L_46 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_62;
V_27 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_47 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_62;
V_28 = * ( ++ V_5 ) ;
}
else if ( strcmp ( * V_5 , L_48 ) == 0 )
V_6 |= V_64 ;
else if ( strcmp ( * V_5 , L_49 ) == 0 )
V_6 |= V_65 ;
else if ( strcmp ( * V_5 , L_50 ) == 0 )
V_6 |= V_66 ;
else if ( strcmp ( * V_5 , L_51 ) == 0 )
{
if ( -- V_4 < 1 ) goto V_62;
V_29 = * ( ++ V_5 ) ;
}
#ifdef F_3
else if ( strcmp ( * V_5 , L_52 ) == 0 )
{ V_61 = 1 ; }
#endif
else
{
F_2 ( V_1 , L_53 , * V_5 ) ;
V_31 = 1 ;
break;
}
V_4 -- ;
V_5 ++ ;
}
if ( V_31 )
{
V_62:
F_1 () ;
goto V_57;
}
if ( V_67 == NULL )
{
if ( V_51 )
{
V_67 = F_13 ( F_14 () ) ;
}
else
{
if ( V_67 == NULL )
V_67 = F_9 ( stdout , V_55 ) ;
}
}
F_15 () ;
V_41 = F_16 ( V_46 ) ;
if ( V_41 == NULL )
{
F_17 ( V_1 ) ;
goto V_57;
}
if ( V_34 )
F_18 ( V_41 , V_68 | V_6 ) ;
else
F_18 ( V_41 , V_6 ) ;
if ( V_12 ) F_19 ( V_41 , V_69 ) ;
if ( V_29 != NULL )
F_20 ( V_41 , V_29 ) ;
#if 0
else
SSL_CTX_set_cipher_list(ctx,getenv("SSL_CIPHER"));
#endif
F_21 ( V_41 , V_32 , V_70 ) ;
if ( ! F_22 ( V_41 , V_25 , V_26 ) )
goto V_57;
if ( ( ! F_23 ( V_41 , V_28 , V_27 ) ) ||
( ! F_24 ( V_41 ) ) )
{
F_17 ( V_1 ) ;
}
F_25 () ;
V_7 = ( T_1 * ) F_26 ( V_41 ) ;
V_71:
if ( F_27 ( & V_9 , V_24 , V_21 ) == 0 )
{
F_2 ( V_1 , L_54 , F_28 () ) ;
F_29 ( V_9 ) ;
goto V_57;
}
F_2 ( V_67 , L_55 , V_9 ) ;
#ifdef F_3
if ( V_61 )
{
unsigned long V_72 = 1 ;
F_2 ( V_67 , L_56 ) ;
if ( F_30 ( V_9 , F_3 , & V_72 ) < 0 )
{
F_17 ( V_1 ) ;
goto V_57;
}
}
#endif
if ( V_50 & 0x01 ) V_7 -> V_73 = 1 ;
V_47 = F_31 ( V_9 , V_55 ) ;
if ( V_45 )
{
T_5 * V_74 ;
V_74 = F_13 ( F_32 () ) ;
V_47 = F_33 ( V_74 , V_47 ) ;
}
if ( V_52 )
{
V_7 -> V_73 = 1 ;
F_34 ( V_47 , V_75 ) ;
F_35 ( V_47 , V_67 ) ;
}
F_36 ( V_7 , V_47 , V_47 ) ;
F_37 ( V_7 ) ;
V_11 = F_38 ( V_7 ) + 1 ;
V_36 = 1 ;
V_35 = 0 ;
V_39 = 0 ;
V_38 = 1 ;
V_37 = 1 ;
V_15 = 0 ;
V_16 = 0 ;
V_17 = 0 ;
V_18 = 0 ;
for (; ; )
{
F_39 ( & V_19 ) ;
F_39 ( & V_20 ) ;
if ( F_40 ( V_7 ) && ! F_41 ( V_7 ) )
{
V_43 = 1 ;
V_39 = 0 ;
}
else
{
V_39 = 1 ;
if ( V_43 )
{
V_43 = 0 ;
F_42 ( V_67 , V_7 , V_23 ) ;
if ( V_23 > 0 ) V_23 -- ;
if ( V_30 )
{
V_30 -- ;
F_2 ( V_67 , L_57 ) ;
F_43 ( V_7 ) ;
F_37 ( V_7 ) ;
F_29 ( F_38 ( V_7 ) ) ;
goto V_71;
}
}
}
V_40 = V_38 && F_44 ( V_7 ) ;
if ( ! V_40 )
{
#ifndef F_45
if ( V_39 )
{
if ( V_36 ) F_46 ( fileno ( V_76 ) , & V_19 ) ;
if ( V_35 ) F_46 ( fileno ( stdout ) , & V_20 ) ;
}
#endif
if ( V_38 )
F_46 ( F_38 ( V_7 ) , & V_19 ) ;
if ( V_37 )
F_46 ( F_38 ( V_7 ) , & V_20 ) ;
V_44 = F_47 ( V_11 , ( void * ) & V_19 , ( void * ) & V_20 ,
NULL , NULL ) ;
if ( V_44 < 0 )
{
F_2 ( V_1 , L_58 ,
F_28 () ) ;
goto V_77;
}
}
if ( ! V_40 && F_48 ( F_38 ( V_7 ) , & V_20 ) )
{
V_10 = F_49 ( V_7 , & ( V_13 [ V_16 ] ) ,
( unsigned int ) V_15 ) ;
switch ( F_50 ( V_7 , V_10 ) )
{
case V_78 :
V_16 += V_10 ;
V_15 -= V_10 ;
if ( V_10 <= 0 ) goto V_57;
if ( V_15 <= 0 )
{
V_36 = 1 ;
V_37 = 0 ;
}
else
{
V_36 = 0 ;
V_37 = 1 ;
}
break;
case V_79 :
F_2 ( V_67 , L_59 ) ;
V_37 = 1 ;
V_36 = 0 ;
break;
case V_80 :
F_2 ( V_67 , L_60 ) ;
V_35 = 0 ;
V_38 = 1 ;
V_37 = 0 ;
break;
case V_81 :
F_2 ( V_67 , L_61 ) ;
break;
case V_82 :
if ( V_15 != 0 )
{
F_2 ( V_67 , L_62 ) ;
goto V_77;
}
else
{
V_36 = 1 ;
V_37 = 0 ;
break;
}
case V_83 :
if ( ( V_10 != 0 ) || ( V_15 != 0 ) )
{
F_2 ( V_1 , L_63 ,
F_28 () ) ;
goto V_77;
}
else
{
V_36 = 1 ;
V_37 = 0 ;
}
break;
case V_84 :
F_17 ( V_1 ) ;
goto V_77;
}
}
#ifndef F_45
else if ( ! V_40 && F_48 ( fileno ( stdout ) , & V_20 ) )
{
V_44 = F_51 ( fileno ( stdout ) , & ( V_14 [ V_18 ] ) , V_17 ) ;
if ( V_44 <= 0 )
{
F_2 ( V_67 , L_64 ) ;
goto V_77;
}
V_17 -= V_44 ; ;
V_18 += V_44 ;
if ( V_17 <= 0 )
{
V_38 = 1 ;
V_35 = 0 ;
}
}
#endif
else if ( V_40 || F_48 ( F_38 ( V_7 ) , & V_19 ) )
{
#ifdef F_52
{ static int V_85 ; if ( ++ V_85 == 52 ) { F_53 ( V_7 ) ; V_85 = 0 ; } }
#endif
#if 1
V_10 = F_54 ( V_7 , V_14 , 1024 ) ;
#else
V_10 = F_54 ( V_7 , V_14 , 16 ) ;
{ char V_86 [ 10240 ] ;
printf ( L_65 , V_10 , F_44 ( V_7 ) , F_55 ( V_7 , V_86 , 10240 ) ) ;
}
#endif
switch ( F_50 ( V_7 , V_10 ) )
{
case V_78 :
if ( V_10 <= 0 )
goto V_57;
V_18 = 0 ;
V_17 = V_10 ;
V_38 = 0 ;
V_35 = 1 ;
break;
case V_79 :
F_2 ( V_67 , L_66 ) ;
V_37 = 1 ;
V_36 = 0 ;
break;
case V_80 :
F_2 ( V_67 , L_67 ) ;
V_35 = 0 ;
V_38 = 1 ;
if ( ( V_36 == 0 ) && ( V_37 == 0 ) )
V_37 = 1 ;
break;
case V_81 :
F_2 ( V_67 , L_68 ) ;
break;
case V_83 :
F_2 ( V_1 , L_69 , F_28 () ) ;
goto V_77;
case V_82 :
F_2 ( V_67 , L_70 ) ;
goto V_77;
case V_84 :
F_17 ( V_1 ) ;
goto V_77;
}
}
#ifndef F_45
else if ( F_48 ( fileno ( V_76 ) , & V_19 ) )
{
V_44 = F_56 ( fileno ( V_76 ) , V_13 , V_56 ) ;
if ( ( ! V_51 ) && ( ( V_44 <= 0 ) || ( V_13 [ 0 ] == 'Q' ) ) )
{
F_2 ( V_1 , L_64 ) ;
goto V_77;
}
if ( ( ! V_51 ) && ( V_13 [ 0 ] == 'R' ) )
{
F_2 ( V_1 , L_71 ) ;
F_53 ( V_7 ) ;
V_15 = 0 ;
}
else
{
V_15 = V_44 ;
V_16 = 0 ;
}
V_37 = 1 ;
V_36 = 0 ;
}
#endif
}
V_77:
F_43 ( V_7 ) ;
F_29 ( F_38 ( V_7 ) ) ;
V_42 = 0 ;
V_57:
if ( V_7 != NULL ) F_57 ( V_7 ) ;
if ( V_8 != NULL ) F_57 ( V_8 ) ;
if ( V_41 != NULL ) F_58 ( V_41 ) ;
if ( V_13 != NULL ) { memset ( V_13 , 0 , V_56 ) ; Free ( V_13 ) ; }
if ( V_14 != NULL ) { memset ( V_14 , 0 , V_56 ) ; Free ( V_14 ) ; }
if ( V_67 != NULL )
{
F_59 ( V_67 ) ;
V_67 = NULL ;
}
EXIT ( V_42 ) ;
}
static void F_42 ( T_5 * V_87 , T_1 * V_9 , int V_88 )
{
T_6 * V_89 = NULL ;
char * V_90 ;
static char * V_91 = L_72 ;
char V_92 [ V_93 ] ;
F_60 ( T_6 ) * V_94 ;
F_60 ( V_95 ) * V_96 ;
T_7 * V_97 ;
V_95 * V_98 ;
int V_99 , V_44 ;
if ( V_88 )
{
int V_100 = 0 ;
V_94 = F_61 ( V_9 ) ;
if ( V_94 != NULL )
{
V_100 = 1 ;
F_2 ( V_87 , L_73 ) ;
for ( V_44 = 0 ; V_44 < F_62 ( V_94 ) ; V_44 ++ )
{
F_63 ( F_64 (
F_65 ( V_94 , V_44 ) ) , V_92 , V_93 ) ;
F_2 ( V_87 , L_74 , V_44 , V_92 ) ;
F_63 ( F_66 (
F_65 ( V_94 , V_44 ) ) , V_92 , V_93 ) ;
F_2 ( V_87 , L_75 , V_92 ) ;
if ( V_53 )
F_67 ( V_87 , F_65 ( V_94 , V_44 ) ) ;
}
}
F_2 ( V_87 , L_76 ) ;
V_89 = F_68 ( V_9 ) ;
if ( V_89 != NULL )
{
F_2 ( V_87 , L_77 ) ;
if ( ! ( V_53 && V_100 ) )
F_67 ( V_87 , V_89 ) ;
F_63 ( F_64 ( V_89 ) ,
V_92 , V_93 ) ;
F_2 ( V_87 , L_78 , V_92 ) ;
F_63 ( F_66 ( V_89 ) ,
V_92 , V_93 ) ;
F_2 ( V_87 , L_79 , V_92 ) ;
}
else
F_2 ( V_87 , L_80 ) ;
V_96 = F_69 ( V_9 ) ;
if ( ( V_96 != NULL ) && ( F_70 ( V_96 ) > 0 ) )
{
F_2 ( V_87 , L_81 ) ;
for ( V_44 = 0 ; V_44 < F_70 ( V_96 ) ; V_44 ++ )
{
V_98 = F_71 ( V_96 , V_44 ) ;
F_63 ( V_98 , V_92 , sizeof( V_92 ) ) ;
F_72 ( V_87 , V_92 , strlen ( V_92 ) ) ;
F_72 ( V_87 , L_2 , 1 ) ;
}
}
else
{
F_2 ( V_87 , L_82 ) ;
}
V_90 = F_73 ( V_9 , V_92 , V_93 ) ;
if ( V_90 != NULL )
{
F_2 ( V_87 , L_83 ) ;
V_99 = V_44 = 0 ;
while ( * V_90 )
{
if ( * V_90 == ':' )
{
F_72 ( V_87 , V_91 , 15 - V_99 % 25 ) ;
V_44 ++ ;
V_99 = 0 ;
F_72 ( V_87 , ( ( V_44 % 3 ) ? L_84 : L_2 ) , 1 ) ;
}
else
{
F_72 ( V_87 , V_90 , 1 ) ;
V_99 ++ ;
}
V_90 ++ ;
}
F_72 ( V_87 , L_2 , 1 ) ;
}
F_2 ( V_87 , L_85 ,
F_74 ( F_75 ( V_9 ) ) ,
F_76 ( F_77 ( V_9 ) ) ) ;
}
F_2 ( V_87 , ( ( V_9 -> V_101 ) ? L_86 : L_87 ) ) ;
V_97 = F_78 ( V_9 ) ;
F_2 ( V_87 , L_88 ,
F_79 ( V_97 ) ,
F_80 ( V_97 ) ) ;
if ( V_89 != NULL ) {
T_8 * V_102 ;
V_102 = F_81 ( V_89 ) ;
F_2 ( V_87 , L_89 ,
F_82 ( V_102 ) ) ;
F_83 ( V_102 ) ;
}
F_84 ( V_87 , F_85 ( V_9 ) ) ;
F_2 ( V_87 , L_76 ) ;
if ( V_89 != NULL )
F_86 ( V_89 ) ;
}
