int MAIN ( int V_1 , char * * V_2 )
{
char * V_3 = NULL , * V_4 = NULL ;
int V_5 = 0 ;
int V_6 = 0 ;
int V_7 = 0 ;
int V_8 = 1 ;
int V_9 = 0 ;
int V_10 = 0 ;
int V_11 = 0 ;
int V_12 = 0 ;
long V_13 = 0 ;
long V_14 = 0 ;
long V_15 = - 1 ;
char * V_16 = NULL ;
char * V_17 = NULL ;
char * V_18 = NULL ;
char * V_19 = NULL ;
char * V_20 = NULL ;
char * V_21 = NULL ;
char * V_22 = NULL ;
char * V_23 = NULL ;
T_1 * V_24 = NULL ;
int V_25 = 0 ;
char * V_26 = NULL ;
char * V_27 = NULL ;
char * V_28 = NULL ;
char * V_29 = NULL ;
char * V_30 = NULL ;
T_2 * V_31 = NULL ;
char * V_32 = NULL ;
char * V_33 = NULL ;
int V_34 = 0 ;
int V_35 = 0 ;
int V_36 = 0 ;
T_3 * V_37 = NULL ;
T_3 * V_38 = NULL ;
T_4 * V_39 = NULL , * V_40 = NULL , * V_41 = NULL , * V_42 = NULL ;
char * V_43 = NULL ;
T_5 * V_44 = NULL ;
T_6 * V_45 = NULL ;
T_7 * V_46 = NULL ;
T_8 * V_47 = NULL ;
char * * V_48 , * V_49 , * V_50 ;
int V_51 , V_52 ;
long V_53 ;
const T_9 * V_54 = NULL ;
F_1 ( V_55 ) * V_56 = NULL ;
F_1 ( T_3 ) * V_57 = NULL ;
T_4 * V_58 = NULL ;
#undef V_59
#define V_59 256
T_10 char V_60 [ 3 ] [ V_59 ] ;
char * V_61 = NULL ;
#ifdef F_2
V_62 = 1 ;
V_63 = 1 ;
V_64 = 0 ;
#endif
F_3 () ;
V_65 = NULL ;
V_3 = NULL ;
V_66 = NULL ;
V_67 = 0 ;
V_68 = 0 ;
if ( V_69 == NULL )
if ( ( V_69 = F_4 ( F_5 () ) ) != NULL )
F_6 ( V_69 , V_70 , V_71 | V_72 ) ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
V_10 = 1 ;
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_66 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_32 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_33 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_34 = atoi ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_4 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_3 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_20 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_21 = * ( ++ V_2 ) ;
V_9 = 1 ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_26 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_27 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_16 ) == 0 )
V_36 = 1 ;
else if ( strcmp ( * V_2 , L_17 ) == 0 )
V_35 = 1 ;
else if ( strcmp ( * V_2 , L_18 ) == 0 )
V_67 = 1 ;
else if ( strcmp ( * V_2 , L_19 ) == 0 )
V_11 = 1 ;
else if ( strcmp ( * V_2 , L_20 ) == 0 )
V_68 = 1 ;
else if ( strcmp ( * V_2 , L_21 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_13 = atol ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_22 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_14 = atol ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_23 ) == 0 )
{
V_1 -- ;
V_2 ++ ;
V_9 = 1 ;
break;
}
else if ( strcmp ( * V_2 , L_24 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_23 = * ( ++ V_2 ) ;
V_9 = 1 ;
}
else if ( strcmp ( * V_2 , L_25 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_22 = * ( ++ V_2 ) ;
V_9 = 1 ;
}
else if ( strcmp ( * V_2 , L_26 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_21 = * ( ++ V_2 ) ;
V_12 = 1 ;
}
else if ( strcmp ( * V_2 , L_27 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_29 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_28 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_73;
V_30 = * ( ++ V_2 ) ;
}
else
{
V_73:
F_7 ( V_69 , L_29 , * V_2 ) ;
V_7 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_7 )
{
for ( V_48 = V_74 ; ( * V_48 != NULL ) ; V_48 ++ )
F_7 ( V_69 , * V_48 ) ;
goto V_75;
}
F_8 () ;
if ( V_16 == NULL ) V_16 = getenv ( L_30 ) ;
if ( V_16 == NULL ) V_16 = getenv ( L_31 ) ;
if ( V_16 == NULL )
{
#ifdef F_9
strncpy ( V_60 [ 0 ] , F_10 () ,
sizeof( V_60 [ 0 ] ) - 1 - sizeof( V_76 ) ) ;
#else
strncpy ( V_60 [ 0 ] , F_10 () ,
sizeof( V_60 [ 0 ] ) - 2 - sizeof( V_76 ) ) ;
strcat ( V_60 [ 0 ] , L_32 ) ;
#endif
strcat ( V_60 [ 0 ] , V_76 ) ;
V_16 = V_60 [ 0 ] ;
}
F_7 ( V_69 , L_33 , V_16 ) ;
if ( ( V_65 = F_11 ( NULL , V_16 , & V_15 ) ) == NULL )
{
if ( V_15 <= 0 )
F_7 ( V_69 , L_34 ,
V_16 ) ;
else
F_7 ( V_69 , L_35
, V_15 , V_16 ) ;
goto V_75;
}
if ( V_66 == NULL )
{
V_66 = F_12 ( V_65 , V_77 , V_78 ) ;
if ( V_66 == NULL )
{
F_13 ( V_77 , V_78 ) ;
goto V_75;
}
}
if ( V_65 != NULL )
{
V_49 = F_12 ( V_65 , NULL , L_36 ) ;
if ( V_49 != NULL )
{
T_4 * V_79 ;
V_79 = F_14 ( V_49 , L_37 ) ;
if ( V_79 == NULL )
{
F_15 () ;
}
else
{
F_16 ( V_79 ) ;
F_17 ( V_79 ) ;
}
}
if( ! F_18 ( V_69 , V_65 ) )
{
F_19 ( V_69 ) ;
goto V_75;
}
}
V_61 = F_12 ( V_65 , V_77 , L_38 ) ;
F_20 ( V_61 , V_69 , 0 ) ;
V_39 = F_4 ( F_5 () ) ;
V_40 = F_4 ( F_5 () ) ;
V_41 = F_4 ( F_5 () ) ;
V_42 = F_4 ( F_5 () ) ;
if ( ( V_39 == NULL ) || ( V_40 == NULL ) || ( V_41 == NULL ) || ( V_42 == NULL ) )
{
F_19 ( V_69 ) ;
goto V_75;
}
if ( ( V_19 == NULL ) && ( ( V_19 = F_12 ( V_65 ,
V_66 , V_80 ) ) == NULL ) )
{
F_13 ( V_66 , V_80 ) ;
goto V_75;
}
if( ! V_3 && ! F_21 ( V_69 , V_4 , NULL , & V_3 , NULL ) )
{
F_7 ( V_69 , L_39 ) ;
goto V_75;
}
if ( F_22 ( V_39 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
F_7 ( V_69 , L_40 ) ;
goto V_75;
}
V_24 = F_23 ( V_39 , NULL , NULL , V_3 ) ;
if( V_3 ) memset ( V_3 , 0 , strlen ( V_3 ) ) ;
if ( V_24 == NULL )
{
F_7 ( V_69 , L_41 ) ;
goto V_75;
}
if ( ( V_20 == NULL ) && ( ( V_20 = F_12 ( V_65 ,
V_66 , V_81 ) ) == NULL ) )
{
F_13 ( V_66 , V_81 ) ;
goto V_75;
}
if ( F_22 ( V_39 , V_20 ) <= 0 )
{
perror ( V_20 ) ;
F_7 ( V_69 , L_42 ) ;
goto V_75;
}
V_37 = F_24 ( V_39 , NULL , NULL , NULL ) ;
if ( V_37 == NULL )
{
F_7 ( V_69 , L_43 ) ;
goto V_75;
}
if ( ! F_25 ( V_37 , V_24 ) )
{
F_7 ( V_69 , L_44 ) ;
goto V_75;
}
V_50 = F_12 ( V_65 , V_77 , V_82 ) ;
if ( ( V_50 != NULL ) && ( ( * V_50 == 'y' ) || ( * V_50 == 'Y' ) ) )
V_67 = 1 ;
V_50 = F_12 ( V_65 , V_77 , V_83 ) ;
if ( ( V_50 != NULL ) && ( ( * V_50 == 'y' ) || ( * V_50 == 'Y' ) ) )
V_68 = 1 ;
if ( ( V_27 == NULL ) && ( V_9 ) )
{
struct V_84 V_85 ;
if ( ( V_27 = F_12 ( V_65 , V_66 , V_86 ) )
== NULL )
{
F_7 ( V_69 , L_45 ) ;
goto V_75;
}
#ifndef F_9
if ( F_26 ( V_27 , V_87 | V_88 | V_89 ) != 0 )
{
F_7 ( V_69 , L_46 , V_27 ) ;
perror ( V_27 ) ;
goto V_75;
}
if ( V_84 ( V_27 , & V_85 ) != 0 )
{
F_7 ( V_69 , L_47 , V_27 ) ;
perror ( V_27 ) ;
goto V_75;
}
#ifdef F_27
if ( ! ( V_85 . V_90 & F_27 ) )
{
F_7 ( V_69 , L_48 , V_27 ) ;
perror ( V_27 ) ;
goto V_75;
}
#endif
#endif
}
if ( ( V_43 = F_12 ( V_65 , V_66 , V_91 ) ) == NULL )
{
F_13 ( V_66 , V_91 ) ;
goto V_75;
}
if ( F_22 ( V_39 , V_43 ) <= 0 )
{
perror ( V_43 ) ;
F_7 ( V_69 , L_49 , V_43 ) ;
goto V_75;
}
V_44 = F_28 ( V_39 , V_92 ) ;
if ( V_44 == NULL ) goto V_75;
for ( V_51 = 0 ; V_51 < F_29 ( V_44 -> V_93 ) ; V_51 ++ )
{
V_48 = ( char * * ) F_30 ( V_44 -> V_93 , V_51 ) ;
if ( ( V_48 [ V_94 ] [ 0 ] != V_95 ) &&
( V_48 [ V_96 ] [ 0 ] != '\0' ) )
{
F_7 ( V_69 , L_50 , V_51 + 1 ) ;
goto V_75;
}
if ( ( V_48 [ V_94 ] [ 0 ] == V_95 ) &&
! F_31 ( V_48 [ V_96 ] ) )
{
F_7 ( V_69 , L_51 ,
V_51 + 1 ) ;
goto V_75;
}
if ( ! F_31 ( V_48 [ V_97 ] ) )
{
F_7 ( V_69 , L_52 , V_51 + 1 ) ;
goto V_75;
}
V_49 = V_48 [ V_98 ] ;
V_52 = strlen ( V_49 ) ;
if ( ( V_52 & 1 ) || ( V_52 < 2 ) )
{
F_7 ( V_69 , L_53 , V_51 + 1 , V_52 ) ;
goto V_75;
}
while ( * V_49 )
{
if ( ! ( ( ( * V_49 >= '0' ) && ( * V_49 <= '9' ) ) ||
( ( * V_49 >= 'A' ) && ( * V_49 <= 'F' ) ) ||
( ( * V_49 >= 'a' ) && ( * V_49 <= 'f' ) ) ) )
{
F_7 ( V_69 , L_54 , V_51 + 1 , ( long ) ( V_49 - V_48 [ V_98 ] ) , * V_49 ) ;
goto V_75;
}
V_49 ++ ;
}
}
if ( V_10 )
{
F_6 ( V_40 , stdout , V_71 | V_72 ) ;
#ifdef F_9
{
T_4 * V_99 = F_4 ( F_32 () ) ;
V_40 = F_33 ( V_99 , V_40 ) ;
}
#endif
F_34 ( V_40 , V_44 ) ;
F_7 ( V_69 , L_55 ,
V_44 -> V_93 -> V_100 ) ;
F_7 ( V_69 , L_56 ) ;
}
if ( ! F_35 ( V_44 , V_98 , NULL , V_101 ,
V_102 ) )
{
F_7 ( V_69 , L_57 , V_44 -> error , V_44 -> V_103 , V_44 -> V_104 ) ;
goto V_75;
}
if ( ! F_35 ( V_44 , V_105 , V_106 , V_107 ,
V_108 ) )
{
F_7 ( V_69 , L_58 ,
V_44 -> error , V_44 -> V_103 , V_44 -> V_104 ) ;
goto V_75;
}
if ( V_9 || V_11 )
{
if ( V_26 != NULL )
{
if ( F_36 ( V_41 , V_26 ) <= 0 )
{
perror ( V_26 ) ;
goto V_75;
}
}
else
{
F_6 ( V_41 , stdout , V_71 | V_72 ) ;
#ifdef F_9
{
T_4 * V_99 = F_4 ( F_32 () ) ;
V_41 = F_33 ( V_99 , V_41 ) ;
}
#endif
}
}
if ( V_9 )
{
if ( ( V_17 == NULL ) && ( ( V_17 = F_12 ( V_65 ,
V_66 , V_109 ) ) == NULL ) )
{
F_13 ( V_66 , V_109 ) ;
goto V_75;
}
if ( ( V_54 = F_37 ( V_17 ) ) == NULL )
{
F_7 ( V_69 , L_59 , V_17 ) ;
goto V_75;
}
if ( V_10 )
F_7 ( V_69 , L_60 ,
F_38 ( V_54 -> type ) ) ;
if ( ( V_18 == NULL ) && ( ( V_18 = F_12 ( V_65 ,
V_66 , V_110 ) ) == NULL ) )
{
F_13 ( V_66 , V_110 ) ;
goto V_75;
}
if ( V_10 )
F_7 ( V_69 , L_61 , V_18 ) ;
if ( ( V_28 = F_12 ( V_65 , V_66 , V_111 ) )
== NULL )
{
F_13 ( V_66 , V_111 ) ;
goto V_75;
}
if( ! V_29 )
V_29 = F_12 ( V_65 , V_66 , V_112 ) ;
if( V_29 ) {
T_11 V_113 ;
F_39 ( & V_113 ) ;
F_40 ( & V_113 , V_65 ) ;
if( ! F_41 ( V_65 , & V_113 , V_29 , NULL ) ) {
F_7 ( V_69 ,
L_62 ,
V_29 ) ;
V_8 = 1 ;
goto V_75;
}
}
if ( V_32 == NULL )
{
V_32 = F_12 ( V_65 , V_66 ,
V_114 ) ;
}
if ( V_32 && ! F_42 ( NULL , V_32 ) )
{
F_7 ( V_69 , L_63 ) ;
goto V_75;
}
if ( V_32 == NULL ) V_32 = L_64 ;
if ( V_33 == NULL )
{
V_33 = F_12 ( V_65 , V_66 ,
V_115 ) ;
}
if ( V_33 && ! F_42 ( NULL , V_33 ) )
{
F_7 ( V_69 , L_65 ) ;
goto V_75;
}
if ( V_34 == 0 )
{
V_34 = ( int ) F_43 ( V_65 , V_66 ,
V_116 ) ;
}
if ( ! V_33 && ( V_34 == 0 ) )
{
F_7 ( V_69 , L_66 ) ;
goto V_75;
}
if ( ( V_31 = F_44 ( V_28 ) ) == NULL )
{
F_7 ( V_69 , L_67 ) ;
goto V_75;
}
if ( V_10 )
{
if ( ( V_50 = F_45 ( V_31 ) ) == NULL ) goto V_75;
F_7 ( V_69 , L_68 , V_50 ) ;
F_46 ( V_50 ) ;
}
if ( ( V_56 = F_47 ( V_65 , V_18 ) ) == NULL )
{
F_7 ( V_69 , L_69 , V_18 ) ;
goto V_75;
}
if ( ( V_57 = F_48 () ) == NULL )
{
F_7 ( V_69 , L_70 ) ;
goto V_75;
}
if ( V_22 != NULL )
{
V_5 ++ ;
V_52 = F_49 ( & V_38 , V_22 , V_24 , V_37 , V_54 , V_56 , V_44 ,
V_31 , V_32 , V_33 , V_34 , V_29 , V_65 ,
V_10 ) ;
if ( V_52 < 0 ) goto V_75;
if ( V_52 > 0 )
{
V_6 ++ ;
F_7 ( V_69 , L_71 ) ;
if ( ! F_50 ( V_31 , 1 ) ) goto V_75;
if ( ! F_51 ( V_57 , V_38 ) )
{
F_7 ( V_69 , L_70 ) ;
goto V_75;
}
if ( V_26 )
{
V_25 = 1 ;
V_35 = 1 ;
}
}
}
if ( V_23 != NULL )
{
V_5 ++ ;
V_52 = F_52 ( & V_38 , V_23 , V_24 , V_37 , V_54 , V_56 ,
V_44 , V_31 , V_32 , V_33 , V_34 , V_35 ,
V_29 , V_65 , V_10 ) ;
if ( V_52 < 0 ) goto V_75;
if ( V_52 > 0 )
{
V_6 ++ ;
F_7 ( V_69 , L_71 ) ;
if ( ! F_50 ( V_31 , 1 ) ) goto V_75;
if ( ! F_51 ( V_57 , V_38 ) )
{
F_7 ( V_69 , L_70 ) ;
goto V_75;
}
}
}
if ( V_21 != NULL )
{
V_5 ++ ;
V_52 = F_53 ( & V_38 , V_21 , V_24 , V_37 , V_54 , V_56 , V_44 ,
V_31 , V_32 , V_33 , V_34 , V_35 ,
V_29 , V_65 , V_10 ) ;
if ( V_52 < 0 ) goto V_75;
if ( V_52 > 0 )
{
V_6 ++ ;
F_7 ( V_69 , L_71 ) ;
if ( ! F_50 ( V_31 , 1 ) ) goto V_75;
if ( ! F_51 ( V_57 , V_38 ) )
{
F_7 ( V_69 , L_70 ) ;
goto V_75;
}
}
}
for ( V_51 = 0 ; V_51 < V_1 ; V_51 ++ )
{
V_5 ++ ;
V_52 = F_53 ( & V_38 , V_2 [ V_51 ] , V_24 , V_37 , V_54 , V_56 , V_44 ,
V_31 , V_32 , V_33 , V_34 , V_35 ,
V_29 , V_65 , V_10 ) ;
if ( V_52 < 0 ) goto V_75;
if ( V_52 > 0 )
{
V_6 ++ ;
F_7 ( V_69 , L_71 ) ;
if ( ! F_50 ( V_31 , 1 ) ) goto V_75;
if ( ! F_51 ( V_57 , V_38 ) )
{
F_7 ( V_69 , L_70 ) ;
goto V_75;
}
}
}
if ( F_54 ( V_57 ) > 0 )
{
if ( ! V_35 )
{
F_7 ( V_69 , L_72 , V_6 , V_5 ) ;
( void ) F_55 ( V_69 ) ;
V_60 [ 0 ] [ 0 ] = '\0' ;
fgets ( V_60 [ 0 ] , 10 , V_117 ) ;
if ( ( V_60 [ 0 ] [ 0 ] != 'y' ) && ( V_60 [ 0 ] [ 0 ] != 'Y' ) )
{
F_7 ( V_69 , L_73 ) ;
V_8 = 0 ;
goto V_75;
}
}
F_7 ( V_69 , L_74 , F_54 ( V_57 ) ) ;
strncpy ( V_60 [ 0 ] , V_28 , V_59 - 4 ) ;
#ifdef F_9
strcat ( V_60 [ 0 ] , L_75 ) ;
#else
strcat ( V_60 [ 0 ] , L_76 ) ;
#endif
if ( ! F_56 ( V_60 [ 0 ] , V_31 ) ) goto V_75;
strncpy ( V_60 [ 1 ] , V_43 , V_59 - 4 ) ;
#ifdef F_9
strcat ( V_60 [ 1 ] , L_75 ) ;
#else
strcat ( V_60 [ 1 ] , L_76 ) ;
#endif
if ( F_36 ( V_40 , V_60 [ 1 ] ) <= 0 )
{
perror ( V_43 ) ;
F_7 ( V_69 , L_49 , V_43 ) ;
goto V_75;
}
V_53 = F_34 ( V_40 , V_44 ) ;
if ( V_53 <= 0 ) goto V_75;
}
if ( V_10 )
F_7 ( V_69 , L_77 ) ;
for ( V_51 = 0 ; V_51 < F_54 ( V_57 ) ; V_51 ++ )
{
int V_118 ;
unsigned char * V_119 ;
V_38 = F_57 ( V_57 , V_51 ) ;
V_52 = V_38 -> V_120 -> V_121 -> V_122 ;
V_49 = ( char * ) V_38 -> V_120 -> V_121 -> V_93 ;
strncpy ( V_60 [ 2 ] , V_27 , V_59 - ( V_52 * 2 ) - 6 ) ;
#ifndef F_9
strcat ( V_60 [ 2 ] , L_32 ) ;
#endif
V_119 = ( unsigned char * ) & ( V_60 [ 2 ] [ strlen ( V_60 [ 2 ] ) ] ) ;
if ( V_52 > 0 )
{
for ( V_118 = 0 ; V_118 < V_52 ; V_118 ++ )
{
sprintf ( ( char * ) V_119 , L_78 , ( unsigned char ) * ( V_49 ++ ) ) ;
V_119 += 2 ;
}
}
else
{
* ( V_119 ++ ) = '0' ;
* ( V_119 ++ ) = '0' ;
}
* ( V_119 ++ ) = '.' ; * ( V_119 ++ ) = 'p' ; * ( V_119 ++ ) = 'e' ; * ( V_119 ++ ) = 'm' ;
* V_119 = '\0' ;
if ( V_10 )
F_7 ( V_69 , L_79 , V_60 [ 2 ] ) ;
if ( F_36 ( V_42 , V_60 [ 2 ] ) <= 0 )
{
perror ( V_60 [ 2 ] ) ;
goto V_75;
}
F_58 ( V_42 , V_38 , 0 , V_36 ) ;
F_58 ( V_41 , V_38 , V_25 , V_36 ) ;
}
if ( F_54 ( V_57 ) )
{
strncpy ( V_60 [ 2 ] , V_28 , V_59 - 4 ) ;
#ifdef F_9
strcat ( V_60 [ 2 ] , L_80 ) ;
#else
strcat ( V_60 [ 2 ] , L_81 ) ;
#endif
F_17 ( V_39 ) ;
F_59 ( V_40 ) ;
V_39 = NULL ;
V_40 = NULL ;
if ( rename ( V_28 , V_60 [ 2 ] ) < 0 )
{
F_7 ( V_69 , L_82 ,
V_28 , V_60 [ 2 ] ) ;
perror ( L_83 ) ;
goto V_75;
}
if ( rename ( V_60 [ 0 ] , V_28 ) < 0 )
{
F_7 ( V_69 , L_82 ,
V_60 [ 0 ] , V_28 ) ;
perror ( L_83 ) ;
rename ( V_60 [ 2 ] , V_28 ) ;
goto V_75;
}
strncpy ( V_60 [ 2 ] , V_43 , V_59 - 4 ) ;
#ifdef F_9
strcat ( V_60 [ 2 ] , L_80 ) ;
#else
strcat ( V_60 [ 2 ] , L_81 ) ;
#endif
if ( rename ( V_43 , V_60 [ 2 ] ) < 0 )
{
F_7 ( V_69 , L_82 ,
V_43 , V_60 [ 2 ] ) ;
perror ( L_83 ) ;
goto V_75;
}
if ( rename ( V_60 [ 1 ] , V_43 ) < 0 )
{
F_7 ( V_69 , L_82 ,
V_60 [ 1 ] , V_43 ) ;
perror ( L_83 ) ;
rename ( V_60 [ 2 ] , V_43 ) ;
goto V_75;
}
F_7 ( V_69 , L_84 ) ;
}
}
if ( V_11 )
{
if( ! V_30 ) V_30 = F_12 ( V_65 , V_66 , V_123 ) ;
if( V_30 ) {
T_11 V_113 ;
F_39 ( & V_113 ) ;
F_40 ( & V_113 , V_65 ) ;
if( ! F_41 ( V_65 , & V_113 , V_30 , NULL ) ) {
F_7 ( V_69 ,
L_85 ,
V_30 ) ;
V_8 = 1 ;
goto V_75;
}
}
if ( ( V_58 = F_4 ( F_60 () ) ) == NULL ) goto V_75;
if ( ! V_13 && ! V_14 )
{
V_13 = F_43 ( V_65 , V_66 ,
V_124 ) ;
V_14 = F_43 ( V_65 , V_66 ,
V_125 ) ;
}
if ( ( V_13 == 0 ) && ( V_14 == 0 ) )
{
F_7 ( V_69 , L_86 ) ;
goto V_75;
}
if ( V_10 ) F_7 ( V_69 , L_87 ) ;
if ( ( V_45 = F_61 () ) == NULL ) goto V_75;
V_46 = V_45 -> V_45 ;
F_62 ( V_46 -> V_126 ) ;
V_46 -> V_126 = F_63 ( V_37 -> V_120 -> V_127 ) ;
if ( V_46 -> V_126 == NULL ) goto V_75;
F_64 ( V_46 -> V_128 , 0 ) ;
if ( V_46 -> V_129 == NULL )
V_46 -> V_129 = F_65 () ;
F_64 ( V_46 -> V_129 , ( V_13 * 24 + V_14 ) * 60 * 60 ) ;
for ( V_51 = 0 ; V_51 < F_29 ( V_44 -> V_93 ) ; V_51 ++ )
{
V_48 = ( char * * ) F_30 ( V_44 -> V_93 , V_51 ) ;
if ( V_48 [ V_94 ] [ 0 ] == V_95 )
{
if ( ( V_47 = F_66 () ) == NULL ) goto V_75;
F_67 ( ( V_130 * )
V_47 -> V_131 ,
( unsigned char * ) V_48 [ V_96 ] ,
strlen ( V_48 [ V_96 ] ) ) ;
( void ) F_68 ( V_58 ) ;
if ( ! F_69 ( V_58 , V_48 [ V_98 ] ) )
goto V_75;
if ( ! F_70 ( V_58 , V_47 -> V_121 ,
V_60 [ 0 ] , V_59 ) ) goto V_75;
F_71 ( V_46 -> V_132 , V_47 ) ;
}
}
F_72 ( V_46 -> V_132 ) ;
for ( V_51 = 0 ; V_51 < F_73 ( V_46 -> V_132 ) ; V_51 ++ )
{
V_47 = F_74 ( V_46 -> V_132 , V_51 ) ;
V_47 -> V_133 = V_51 ;
}
if ( V_10 ) F_7 ( V_69 , L_88 ) ;
if ( V_17 != NULL )
{
if ( ( V_54 = F_37 ( V_17 ) ) == NULL )
{
F_7 ( V_69 , L_59 , V_17 ) ;
goto V_75;
}
}
else
{
#ifndef F_75
if ( V_24 -> type == V_134 )
V_54 = F_76 () ;
else
#endif
V_54 = F_77 () ;
}
if( V_30 ) {
T_11 V_135 ;
if ( V_46 -> V_136 == NULL )
if ( ( V_46 -> V_136 = F_78 () ) == NULL ) goto V_75;
F_79 ( V_46 -> V_136 , 1 ) ;
F_80 ( & V_135 , V_37 , NULL , NULL , V_45 , 0 ) ;
F_40 ( & V_135 , V_65 ) ;
if( ! F_81 ( V_65 , & V_135 ,
V_30 , V_45 ) ) goto V_75;
}
if ( ! F_82 ( V_45 , V_24 , V_54 ) ) goto V_75;
F_83 ( V_41 , V_45 ) ;
}
if ( V_12 )
{
if ( V_21 == NULL )
{
F_7 ( V_69 , L_89 ) ;
goto V_75;
}
else
{
T_3 * V_137 ;
if ( F_22 ( V_39 , V_21 ) <= 0 )
{
perror ( V_21 ) ;
F_7 ( V_69 , L_90 , V_21 ) ;
goto V_75;
}
V_137 = F_24 ( V_39 , NULL , NULL , NULL ) ;
if ( V_137 == NULL )
{
F_7 ( V_69 , L_91 , V_21 ) ;
goto V_75;
}
V_52 = F_84 ( V_137 , V_44 ) ;
if ( V_52 <= 0 ) goto V_75;
F_85 ( V_137 ) ;
strncpy ( V_60 [ 0 ] , V_43 , V_59 - 4 ) ;
strcat ( V_60 [ 0 ] , L_76 ) ;
if ( F_36 ( V_40 , V_60 [ 0 ] ) <= 0 )
{
perror ( V_43 ) ;
F_7 ( V_69 , L_49 , V_43 ) ;
goto V_75;
}
V_52 = F_34 ( V_40 , V_44 ) ;
if ( V_52 <= 0 ) goto V_75;
strncpy ( V_60 [ 1 ] , V_43 , V_59 - 4 ) ;
strcat ( V_60 [ 1 ] , L_81 ) ;
if ( rename ( V_43 , V_60 [ 1 ] ) < 0 )
{
F_7 ( V_69 , L_82 , V_43 , V_60 [ 1 ] ) ;
perror ( L_83 ) ;
goto V_75;
}
if ( rename ( V_60 [ 0 ] , V_43 ) < 0 )
{
F_7 ( V_69 , L_82 , V_60 [ 0 ] , V_43 ) ;
perror ( L_83 ) ;
rename ( V_60 [ 1 ] , V_43 ) ;
goto V_75;
}
F_7 ( V_69 , L_84 ) ;
}
}
V_8 = 0 ;
V_75:
F_17 ( V_58 ) ;
F_59 ( V_42 ) ;
F_59 ( V_41 ) ;
F_59 ( V_40 ) ;
F_17 ( V_39 ) ;
F_86 ( V_57 , F_85 ) ;
if ( V_8 ) F_19 ( V_69 ) ;
F_87 ( V_61 , V_69 ) ;
F_88 ( V_31 ) ;
F_89 ( V_44 ) ;
F_90 ( V_24 ) ;
F_85 ( V_37 ) ;
F_91 ( V_45 ) ;
F_92 ( V_65 ) ;
F_93 () ;
EXIT ( V_8 ) ;
}
static void F_13 ( char * V_138 , char * V_139 )
{
F_7 ( V_69 , L_92 , V_138 , V_139 ) ;
}
static unsigned long V_101 ( char * * V_140 )
{
char * V_119 ;
V_119 = V_140 [ V_98 ] ;
while ( * V_119 == '0' ) V_119 ++ ;
return ( F_94 ( V_119 ) ) ;
}
static int V_102 ( char * * V_140 , char * * V_141 )
{
char * V_142 , * V_143 ;
for ( V_142 = V_140 [ V_98 ] ; * V_142 == '0' ; V_142 ++ ) ;
for ( V_143 = V_141 [ V_98 ] ; * V_143 == '0' ; V_143 ++ ) ;
return ( strcmp ( V_142 , V_143 ) ) ;
}
static unsigned long V_107 ( char * * V_140 )
{ return ( F_94 ( V_140 [ V_105 ] ) ) ; }
static int V_106 ( char * * V_140 )
{ return ( V_140 [ 0 ] [ 0 ] == 'V' ) ; }
static int V_108 ( char * * V_140 , char * * V_141 )
{ return ( strcmp ( V_140 [ V_105 ] ,
V_141 [ V_105 ] ) ) ; }
static T_2 * F_44 ( char * V_28 )
{
T_4 * V_39 = NULL ;
T_2 * V_8 = NULL ;
T_10 char V_60 [ 1024 ] ;
T_12 * V_144 = NULL ;
if ( ( V_39 = F_4 ( F_5 () ) ) == NULL )
{
F_19 ( V_69 ) ;
goto V_75;
}
if ( F_22 ( V_39 , V_28 ) <= 0 )
{
perror ( V_28 ) ;
goto V_75;
}
V_144 = F_78 () ;
if ( V_144 == NULL ) goto V_75;
if ( ! F_70 ( V_39 , V_144 , V_60 , 1024 ) )
{
F_7 ( V_69 , L_93 ,
V_28 ) ;
goto V_75;
}
V_8 = F_95 ( V_144 , NULL ) ;
if ( V_8 == NULL )
{
F_7 ( V_69 , L_94 ) ;
goto V_75;
}
V_75:
if ( V_39 != NULL ) F_17 ( V_39 ) ;
if ( V_144 != NULL ) F_96 ( V_144 ) ;
return ( V_8 ) ;
}
static int F_56 ( char * V_28 , T_2 * V_31 )
{
T_4 * V_40 ;
int V_8 = 0 ;
T_12 * V_144 = NULL ;
V_40 = F_4 ( F_5 () ) ;
if ( V_40 == NULL )
{
F_19 ( V_69 ) ;
goto V_75;
}
if ( F_36 ( V_40 , V_28 ) <= 0 )
{
perror ( V_28 ) ;
goto V_75;
}
if ( ( V_144 = F_97 ( V_31 , NULL ) ) == NULL )
{
F_7 ( V_69 , L_95 ) ;
goto V_75;
}
F_98 ( V_40 , V_144 ) ;
F_69 ( V_40 , L_71 ) ;
V_8 = 1 ;
V_75:
if ( V_40 != NULL ) F_59 ( V_40 ) ;
if ( V_144 != NULL ) F_96 ( V_144 ) ;
return ( V_8 ) ;
}
static void F_58 ( T_4 * V_145 , T_3 * V_38 , int V_25 , int V_36 )
{
if ( V_25 )
{
( void ) F_99 ( V_145 , V_38 ) ;
return;
}
#if 0
f=X509_NAME_oneline(X509_get_issuer_name(x),buf,256);
BIO_printf(bp,"issuer :%s\n",f);
f=X509_NAME_oneline(X509_get_subject_name(x),buf,256);
BIO_printf(bp,"subject:%s\n",f);
BIO_puts(bp,"serial :");
i2a_ASN1_INTEGER(bp,x->cert_info->serialNumber);
BIO_puts(bp,"\n\n");
#endif
if( ! V_36 ) F_100 ( V_145 , V_38 ) ;
F_101 ( V_145 , V_38 ) ;
}
static int F_102 ( int V_146 , int * type )
{
if ( V_146 == V_147 )
* type = V_148 ;
if ( ( V_146 == V_149 ) && ( * type == V_148 ) )
* type = V_150 ;
if ( ( V_146 == V_151 ) && ( * type == V_148 ) )
* type = V_150 ;
if ( ( V_146 == V_152 ) && ( * type == V_150 ) )
return ( 0 ) ;
if ( V_146 == V_152 )
* type = V_148 ;
return ( 1 ) ;
}
static int F_31 ( char * V_153 )
{
T_13 V_154 ;
V_154 . V_93 = ( unsigned char * ) V_153 ;
V_154 . V_122 = strlen ( V_153 ) ;
V_154 . type = V_155 ;
return ( F_103 ( & V_154 ) ) ;
}
static int F_84 ( T_3 * V_37 , T_5 * V_44 )
{
T_13 * V_154 = NULL , * V_156 = NULL ;
char * V_157 [ V_92 ] , * * V_158 , * * V_159 ;
T_2 * V_160 = NULL ;
int V_161 = - 1 , V_51 ;
for ( V_51 = 0 ; V_51 < V_92 ; V_51 ++ )
V_157 [ V_51 ] = NULL ;
V_157 [ V_105 ] = F_104 ( F_105 ( V_37 ) , NULL , 0 ) ;
V_160 = F_95 ( F_106 ( V_37 ) , NULL ) ;
V_157 [ V_98 ] = F_45 ( V_160 ) ;
F_88 ( V_160 ) ;
if ( ( V_157 [ V_105 ] == NULL ) || ( V_157 [ V_98 ] == NULL ) )
{
F_7 ( V_69 , L_70 ) ;
goto V_75;
}
V_158 = F_107 ( V_44 , V_98 , V_157 ) ;
if ( V_158 == NULL )
{
F_7 ( V_69 , L_96 , V_157 [ V_105 ] ) ;
V_157 [ V_94 ] = ( char * ) F_108 ( 2 ) ;
V_154 = F_109 ( V_37 ) ;
V_157 [ V_97 ] = ( char * ) F_108 ( V_154 -> V_122 + 1 ) ;
memcpy ( V_157 [ V_97 ] , V_154 -> V_93 , V_154 -> V_122 ) ;
V_157 [ V_97 ] [ V_154 -> V_122 ] = '\0' ;
V_157 [ V_96 ] = NULL ;
V_157 [ V_162 ] = ( char * ) F_108 ( 8 ) ;
if ( ( V_157 [ V_94 ] == NULL ) || ( V_157 [ V_97 ] == NULL ) ||
( V_157 [ V_162 ] == NULL ) )
{
F_7 ( V_69 , L_70 ) ;
goto V_75;
}
strcpy ( V_157 [ V_162 ] , L_97 ) ;
V_157 [ V_94 ] [ 0 ] = 'V' ;
V_157 [ V_94 ] [ 1 ] = '\0' ;
if ( ( V_159 = ( char * * ) F_108 ( sizeof( char * ) * ( V_92 + 1 ) ) ) == NULL )
{
F_7 ( V_69 , L_70 ) ;
goto V_75;
}
for ( V_51 = 0 ; V_51 < V_92 ; V_51 ++ )
{
V_159 [ V_51 ] = V_157 [ V_51 ] ;
V_157 [ V_51 ] = NULL ;
}
V_159 [ V_92 ] = NULL ;
if ( ! F_110 ( V_44 , V_159 ) )
{
F_7 ( V_69 , L_98 ) ;
F_7 ( V_69 , L_99 , V_44 -> error ) ;
goto V_75;
}
V_161 = F_84 ( V_37 , V_44 ) ;
goto V_75;
}
else if ( V_108 ( V_157 , V_158 ) )
{
F_7 ( V_69 , L_100 ,
V_157 [ V_105 ] ) ;
goto V_75;
}
else if ( V_158 [ V_94 ] [ 0 ] == 'R' )
{
F_7 ( V_69 , L_101 ,
V_157 [ V_98 ] ) ;
goto V_75;
}
else
{
F_7 ( V_69 , L_102 , V_158 [ V_98 ] ) ;
V_156 = F_65 () ;
V_156 = F_64 ( V_156 , 0 ) ;
V_158 [ V_94 ] [ 0 ] = 'R' ;
V_158 [ V_94 ] [ 1 ] = '\0' ;
V_158 [ V_96 ] = ( char * ) F_108 ( V_156 -> V_122 + 1 ) ;
memcpy ( V_158 [ V_96 ] , V_156 -> V_93 , V_156 -> V_122 ) ;
V_158 [ V_96 ] [ V_156 -> V_122 ] = '\0' ;
F_111 ( V_156 ) ;
}
V_161 = 1 ;
V_75:
for ( V_51 = 0 ; V_51 < V_92 ; V_51 ++ )
{
if ( V_157 [ V_51 ] != NULL )
F_46 ( V_157 [ V_51 ] ) ;
}
return ( V_161 ) ;
}
