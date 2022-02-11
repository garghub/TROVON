int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 0 ;
int V_4 = 0 ;
int V_5 = 0 ;
int V_6 = 1 ;
int V_7 = 0 ;
int V_8 = 0 ;
int V_9 = 0 ;
int V_10 = 0 ;
long V_11 = 0 ;
long V_12 = 0 ;
long V_13 = - 1 ;
char * V_14 = NULL ;
char * V_15 = NULL ;
char * V_16 = NULL ;
char * V_17 = NULL ;
char * V_18 = NULL ;
char * V_19 = NULL ;
char * V_20 = NULL ;
char * V_21 = NULL ;
T_1 * V_22 = NULL ;
int V_23 = 0 ;
char * V_24 = NULL ;
char * V_25 = NULL ;
char * V_26 = NULL ;
char * V_27 = NULL ;
char * V_28 = NULL ;
T_2 * V_29 = NULL ;
char * V_30 = NULL ;
int V_31 = 0 ;
int V_32 = 0 ;
T_3 * V_33 = NULL ;
T_3 * V_34 = NULL ;
T_4 * V_35 = NULL , * V_36 = NULL , * V_37 = NULL , * V_38 = NULL ;
char * V_39 = NULL ;
T_5 * V_40 = NULL ;
T_6 * V_41 = NULL ;
T_7 * V_42 = NULL ;
T_8 * V_43 = NULL ;
char * * V_44 , * V_45 , * V_46 ;
int V_47 , V_48 ;
long V_49 ;
const T_9 * V_50 = NULL ;
T_10 * V_51 = NULL ;
T_10 * V_52 = NULL ;
T_4 * V_53 = NULL ;
#undef V_54
#define V_54 256
T_11 char V_55 [ 3 ] [ V_54 ] ;
#ifdef F_1
V_56 = 1 ;
V_57 = 1 ;
V_58 = 0 ;
#endif
F_2 () ;
F_3 () ;
V_59 = 0 ;
if ( V_60 == NULL )
if ( ( V_60 = F_4 ( F_5 () ) ) != NULL )
F_6 ( V_60 , V_61 , V_62 | V_63 ) ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
V_8 = 1 ;
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_14 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_65 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_30 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_31 = atoi ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_66 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_19 = * ( ++ V_2 ) ;
V_7 = 1 ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_24 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_25 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
V_32 = 1 ;
else if ( strcmp ( * V_2 , L_15 ) == 0 )
V_59 = 1 ;
else if ( strcmp ( * V_2 , L_16 ) == 0 )
V_9 = 1 ;
else if ( strcmp ( * V_2 , L_17 ) == 0 )
V_67 = 1 ;
else if ( strcmp ( * V_2 , L_18 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_11 = atol ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_19 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_12 = atol ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_20 ) == 0 )
{
V_1 -- ;
V_2 ++ ;
V_7 = 1 ;
break;
}
else if ( strcmp ( * V_2 , L_21 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_21 = * ( ++ V_2 ) ;
V_7 = 1 ;
}
else if ( strcmp ( * V_2 , L_22 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_20 = * ( ++ V_2 ) ;
V_7 = 1 ;
}
else if ( strcmp ( * V_2 , L_23 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_19 = * ( ++ V_2 ) ;
V_10 = 1 ;
}
else
{
V_64:
F_7 ( V_60 , L_24 , * V_2 ) ;
V_5 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_5 )
{
for ( V_44 = V_68 ; ( * V_44 != NULL ) ; V_44 ++ )
F_7 ( V_60 , * V_44 ) ;
goto V_69;
}
F_8 () ;
if ( V_14 == NULL ) V_14 = getenv ( L_25 ) ;
if ( V_14 == NULL ) V_14 = getenv ( L_26 ) ;
if ( V_14 == NULL )
{
#ifdef F_9
strncpy ( V_55 [ 0 ] , F_10 () ,
sizeof( V_55 [ 0 ] ) - 1 - sizeof( V_70 ) ) ;
#else
strncpy ( V_55 [ 0 ] , F_10 () ,
sizeof( V_55 [ 0 ] ) - 2 - sizeof( V_70 ) ) ;
strcat ( V_55 [ 0 ] , L_27 ) ;
#endif
strcat ( V_55 [ 0 ] , V_70 ) ;
V_14 = V_55 [ 0 ] ;
}
F_7 ( V_60 , L_28 , V_14 ) ;
if ( ( V_71 = F_11 ( NULL , V_14 , & V_13 ) ) == NULL )
{
if ( V_13 <= 0 )
F_7 ( V_60 , L_29 ,
V_14 ) ;
else
F_7 ( V_60 , L_30
, V_13 , V_14 ) ;
goto V_69;
}
if ( V_65 == NULL )
{
V_65 = F_12 ( V_71 , V_72 , V_73 ) ;
if ( V_65 == NULL )
{
F_13 ( V_72 , V_73 ) ;
goto V_69;
}
}
if ( V_71 != NULL )
{
V_45 = F_12 ( V_71 , NULL , L_31 ) ;
if ( V_45 != NULL )
{
T_4 * V_74 ;
V_74 = F_14 ( V_45 , L_32 ) ;
if ( V_74 == NULL )
{
F_15 () ;
}
else
{
F_16 ( V_74 ) ;
F_17 ( V_74 ) ;
}
}
}
if( ! F_18 ( V_71 ) ) {
F_19 ( V_60 ) ;
goto V_69;
}
V_35 = F_4 ( F_5 () ) ;
V_36 = F_4 ( F_5 () ) ;
V_37 = F_4 ( F_5 () ) ;
V_38 = F_4 ( F_5 () ) ;
if ( ( V_35 == NULL ) || ( V_36 == NULL ) || ( V_37 == NULL ) || ( V_38 == NULL ) )
{
F_19 ( V_60 ) ;
goto V_69;
}
if ( ( V_17 == NULL ) && ( ( V_17 = F_12 ( V_71 ,
V_65 , V_75 ) ) == NULL ) )
{
F_13 ( V_65 , V_75 ) ;
goto V_69;
}
if ( F_20 ( V_35 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
F_7 ( V_60 , L_33 ) ;
goto V_69;
}
if ( V_66 == NULL )
V_22 = F_21 ( V_35 , NULL , NULL ) ;
else
{
V_22 = F_21 ( V_35 , NULL , V_76 ) ;
memset ( V_66 , 0 , strlen ( V_66 ) ) ;
}
if ( V_22 == NULL )
{
F_7 ( V_60 , L_34 ) ;
goto V_69;
}
if ( ( V_18 == NULL ) && ( ( V_18 = F_12 ( V_71 ,
V_65 , V_77 ) ) == NULL ) )
{
F_13 ( V_65 , V_77 ) ;
goto V_69;
}
if ( F_20 ( V_35 , V_18 ) <= 0 )
{
perror ( V_18 ) ;
F_7 ( V_60 , L_35 ) ;
goto V_69;
}
V_33 = F_22 ( V_35 , NULL , NULL ) ;
if ( V_33 == NULL )
{
F_7 ( V_60 , L_36 ) ;
goto V_69;
}
if ( ! F_23 ( V_33 , V_22 ) )
{
F_7 ( V_60 , L_37 ) ;
goto V_69;
}
V_46 = F_12 ( V_71 , V_72 , V_78 ) ;
if ( ( V_46 != NULL ) && ( ( * V_46 == 'y' ) || ( * V_46 == 'Y' ) ) )
V_59 = 1 ;
V_46 = F_12 ( V_71 , V_72 , V_79 ) ;
if ( ( V_46 != NULL ) && ( ( * V_46 == 'y' ) || ( * V_46 == 'Y' ) ) )
V_67 = 1 ;
if ( ( V_25 == NULL ) && ( V_7 ) )
{
struct V_80 V_81 ;
if ( ( V_25 = F_12 ( V_71 , V_65 , V_82 ) )
== NULL )
{
F_7 ( V_60 , L_38 ) ;
goto V_69;
}
#ifdef F_9
if ( F_24 ( V_25 , V_83 | V_84 ) != 0 )
#else
if ( F_24 ( V_25 , V_83 | V_84 | V_85 ) != 0 )
#endif
{
F_7 ( V_60 , L_39 , V_25 ) ;
perror ( V_25 ) ;
goto V_69;
}
if ( V_80 ( V_25 , & V_81 ) != 0 )
{
F_7 ( V_60 , L_40 , V_25 ) ;
perror ( V_25 ) ;
goto V_69;
}
if ( ! ( V_81 . V_86 & V_87 ) )
{
F_7 ( V_60 , L_41 , V_25 ) ;
perror ( V_25 ) ;
goto V_69;
}
}
if ( ( V_39 = F_12 ( V_71 , V_65 , V_88 ) ) == NULL )
{
F_13 ( V_65 , V_88 ) ;
goto V_69;
}
if ( F_20 ( V_35 , V_39 ) <= 0 )
{
perror ( V_39 ) ;
F_7 ( V_60 , L_42 , V_39 ) ;
goto V_69;
}
V_40 = F_25 ( V_35 , V_89 ) ;
if ( V_40 == NULL ) goto V_69;
for ( V_47 = 0 ; V_47 < F_26 ( V_40 -> V_90 ) ; V_47 ++ )
{
V_44 = ( char * * ) F_27 ( V_40 -> V_90 , V_47 ) ;
if ( ( V_44 [ V_91 ] [ 0 ] != V_92 ) &&
( V_44 [ V_93 ] [ 0 ] != '\0' ) )
{
F_7 ( V_60 , L_43 , V_47 + 1 ) ;
goto V_69;
}
if ( ( V_44 [ V_91 ] [ 0 ] == V_92 ) &&
! F_28 ( V_44 [ V_93 ] ) )
{
F_7 ( V_60 , L_44 ,
V_47 + 1 ) ;
goto V_69;
}
if ( ! F_28 ( V_44 [ V_94 ] ) )
{
F_7 ( V_60 , L_45 , V_47 + 1 ) ;
goto V_69;
}
V_45 = V_44 [ V_95 ] ;
V_48 = strlen ( V_45 ) ;
if ( ( V_48 & 1 ) || ( V_48 < 2 ) )
{
F_7 ( V_60 , L_46 , V_47 + 1 , V_48 ) ;
goto V_69;
}
while ( * V_45 )
{
if ( ! ( ( ( * V_45 >= '0' ) && ( * V_45 <= '9' ) ) ||
( ( * V_45 >= 'A' ) && ( * V_45 <= 'F' ) ) ||
( ( * V_45 >= 'a' ) && ( * V_45 <= 'f' ) ) ) )
{
F_7 ( V_60 , L_47 , V_47 + 1 , ( long ) ( V_45 - V_44 [ V_95 ] ) , * V_45 ) ;
goto V_69;
}
V_45 ++ ;
}
}
if ( V_8 )
{
F_6 ( V_36 , stdout , V_62 | V_63 ) ;
F_29 ( V_36 , V_40 ) ;
F_7 ( V_60 , L_48 ,
V_40 -> V_90 -> V_96 ) ;
F_7 ( V_60 , L_49 ) ;
}
if ( ! F_30 ( V_40 , V_95 , NULL , V_97 ,
V_98 ) )
{
F_7 ( V_60 , L_50 , V_40 -> error , V_40 -> V_99 , V_40 -> V_100 ) ;
goto V_69;
}
if ( ! F_30 ( V_40 , V_101 , V_102 , V_103 ,
V_104 ) )
{
F_7 ( V_60 , L_51 ,
V_40 -> error , V_40 -> V_99 , V_40 -> V_100 ) ;
goto V_69;
}
if ( V_7 || V_9 )
{
if ( V_24 != NULL )
{
if ( F_31 ( V_37 , V_24 ) <= 0 )
{
perror ( V_24 ) ;
goto V_69;
}
}
else
F_6 ( V_37 , stdout , V_62 | V_63 ) ;
}
if ( V_7 )
{
if ( ( V_15 == NULL ) && ( ( V_15 = F_12 ( V_71 ,
V_65 , V_105 ) ) == NULL ) )
{
F_13 ( V_65 , V_105 ) ;
goto V_69;
}
if ( ( V_50 = F_32 ( V_15 ) ) == NULL )
{
F_7 ( V_60 , L_52 , V_15 ) ;
goto V_69;
}
if ( V_8 )
F_7 ( V_60 , L_53 ,
F_33 ( V_50 -> type ) ) ;
if ( ( V_16 == NULL ) && ( ( V_16 = F_12 ( V_71 ,
V_65 , V_106 ) ) == NULL ) )
{
F_13 ( V_65 , V_106 ) ;
goto V_69;
}
if ( V_8 )
F_7 ( V_60 , L_54 , V_16 ) ;
if ( ( V_26 = F_12 ( V_71 , V_65 , V_107 ) )
== NULL )
{
F_13 ( V_65 , V_107 ) ;
goto V_69;
}
V_27 = F_12 ( V_71 , V_65 , V_108 ) ;
if( V_27 ) {
T_12 V_109 ;
F_34 ( & V_109 ) ;
F_35 ( & V_109 , V_71 ) ;
if( ! F_36 ( V_71 , & V_109 , V_27 , NULL ) ) {
F_7 ( V_60 ,
L_55 ,
V_27 ) ;
V_6 = 1 ;
goto V_69;
}
}
if ( V_30 == NULL )
{
V_30 = ( char * ) F_12 ( V_71 , V_65 ,
V_110 ) ;
if ( V_30 == NULL )
V_30 = L_56 ;
else
{
if ( ! F_37 ( NULL , V_30 ) )
{
F_7 ( V_60 , L_57 ) ;
goto V_69;
}
}
}
if ( V_31 == 0 )
{
V_31 = ( int ) F_38 ( V_71 , V_65 ,
V_111 ) ;
}
if ( V_31 == 0 )
{
F_7 ( V_60 , L_58 ) ;
goto V_69;
}
if ( ( V_29 = F_39 ( V_26 ) ) == NULL )
{
F_7 ( V_60 , L_59 ) ;
goto V_69;
}
if ( V_8 )
{
if ( ( V_46 = F_40 ( V_29 ) ) == NULL ) goto V_69;
F_7 ( V_60 , L_60 , V_46 ) ;
Free ( V_46 ) ;
}
if ( ( V_51 = F_41 ( V_71 , V_16 ) ) == NULL )
{
F_7 ( V_60 , L_61 , V_16 ) ;
goto V_69;
}
if ( ( V_52 = F_42 () ) == NULL )
{
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
if ( V_20 != NULL )
{
V_3 ++ ;
V_48 = F_43 ( & V_34 , V_20 , V_22 , V_33 , V_50 , V_51 , V_40 ,
V_29 , V_30 , V_31 , V_27 , V_71 , V_8 ) ;
if ( V_48 < 0 ) goto V_69;
if ( V_48 > 0 )
{
V_4 ++ ;
F_7 ( V_60 , L_63 ) ;
if ( ! F_44 ( V_29 , 1 ) ) goto V_69;
if ( ! F_45 ( V_52 , ( char * ) V_34 ) )
{
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
if ( V_24 )
{
V_23 = 1 ;
V_32 = 1 ;
}
}
}
if ( V_21 != NULL )
{
V_3 ++ ;
V_48 = F_46 ( & V_34 , V_21 , V_22 , V_33 , V_50 , V_51 ,
V_40 , V_29 , V_30 , V_31 , V_32 ,
V_27 , V_71 , V_8 ) ;
if ( V_48 < 0 ) goto V_69;
if ( V_48 > 0 )
{
V_4 ++ ;
F_7 ( V_60 , L_63 ) ;
if ( ! F_44 ( V_29 , 1 ) ) goto V_69;
if ( ! F_45 ( V_52 , ( char * ) V_34 ) )
{
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
}
}
if ( V_19 != NULL )
{
V_3 ++ ;
V_48 = F_47 ( & V_34 , V_19 , V_22 , V_33 , V_50 , V_51 , V_40 ,
V_29 , V_30 , V_31 , V_32 ,
V_27 , V_71 , V_8 ) ;
if ( V_48 < 0 ) goto V_69;
if ( V_48 > 0 )
{
V_4 ++ ;
F_7 ( V_60 , L_63 ) ;
if ( ! F_44 ( V_29 , 1 ) ) goto V_69;
if ( ! F_45 ( V_52 , ( char * ) V_34 ) )
{
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
}
}
for ( V_47 = 0 ; V_47 < V_1 ; V_47 ++ )
{
V_3 ++ ;
V_48 = F_47 ( & V_34 , V_2 [ V_47 ] , V_22 , V_33 , V_50 , V_51 , V_40 ,
V_29 , V_30 , V_31 , V_32 ,
V_27 , V_71 , V_8 ) ;
if ( V_48 < 0 ) goto V_69;
if ( V_48 > 0 )
{
V_4 ++ ;
F_7 ( V_60 , L_63 ) ;
if ( ! F_44 ( V_29 , 1 ) ) goto V_69;
if ( ! F_45 ( V_52 , ( char * ) V_34 ) )
{
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
}
}
if ( F_26 ( V_52 ) > 0 )
{
if ( ! V_32 )
{
F_7 ( V_60 , L_64 , V_4 , V_3 ) ;
F_48 ( V_60 ) ;
V_55 [ 0 ] [ 0 ] = '\0' ;
fgets ( V_55 [ 0 ] , 10 , V_112 ) ;
if ( ( V_55 [ 0 ] [ 0 ] != 'y' ) && ( V_55 [ 0 ] [ 0 ] != 'Y' ) )
{
F_7 ( V_60 , L_65 ) ;
V_6 = 0 ;
goto V_69;
}
}
F_7 ( V_60 , L_66 , F_26 ( V_52 ) ) ;
strncpy ( V_55 [ 0 ] , V_26 , V_54 - 4 ) ;
#ifdef F_9
strcat ( V_55 [ 0 ] , L_67 ) ;
#else
strcat ( V_55 [ 0 ] , L_68 ) ;
#endif
if ( ! F_49 ( V_55 [ 0 ] , V_29 ) ) goto V_69;
strncpy ( V_55 [ 1 ] , V_39 , V_54 - 4 ) ;
#ifdef F_9
strcat ( V_55 [ 1 ] , L_67 ) ;
#else
strcat ( V_55 [ 1 ] , L_68 ) ;
#endif
if ( F_31 ( V_36 , V_55 [ 1 ] ) <= 0 )
{
perror ( V_39 ) ;
F_7 ( V_60 , L_42 , V_39 ) ;
goto V_69;
}
V_49 = F_29 ( V_36 , V_40 ) ;
if ( V_49 <= 0 ) goto V_69;
}
if ( V_8 )
F_7 ( V_60 , L_69 ) ;
for ( V_47 = 0 ; V_47 < F_26 ( V_52 ) ; V_47 ++ )
{
int V_113 ;
unsigned char * V_114 ;
V_34 = ( T_3 * ) F_27 ( V_52 , V_47 ) ;
V_48 = V_34 -> V_115 -> V_116 -> V_117 ;
V_45 = ( char * ) V_34 -> V_115 -> V_116 -> V_90 ;
strncpy ( V_55 [ 2 ] , V_25 , V_54 - ( V_48 * 2 ) - 6 ) ;
#ifndef F_9
strcat ( V_55 [ 2 ] , L_27 ) ;
#endif
V_114 = ( unsigned char * ) & ( V_55 [ 2 ] [ strlen ( V_55 [ 2 ] ) ] ) ;
if ( V_48 > 0 )
{
for ( V_113 = 0 ; V_113 < V_48 ; V_113 ++ )
{
sprintf ( ( char * ) V_114 , L_70 , ( unsigned char ) * ( V_45 ++ ) ) ;
V_114 += 2 ;
}
}
else
{
* ( V_114 ++ ) = '0' ;
* ( V_114 ++ ) = '0' ;
}
* ( V_114 ++ ) = '.' ; * ( V_114 ++ ) = 'p' ; * ( V_114 ++ ) = 'e' ; * ( V_114 ++ ) = 'm' ;
* V_114 = '\0' ;
if ( V_8 )
F_7 ( V_60 , L_71 , V_55 [ 2 ] ) ;
if ( F_31 ( V_38 , V_55 [ 2 ] ) <= 0 )
{
perror ( V_55 [ 2 ] ) ;
goto V_69;
}
F_50 ( V_38 , V_34 , 0 ) ;
F_50 ( V_37 , V_34 , V_23 ) ;
}
if ( F_26 ( V_52 ) )
{
strncpy ( V_55 [ 2 ] , V_26 , V_54 - 4 ) ;
#ifdef F_9
strcat ( V_55 [ 2 ] , L_72 ) ;
#else
strcat ( V_55 [ 2 ] , L_73 ) ;
#endif
F_17 ( V_35 ) ;
F_17 ( V_36 ) ;
V_35 = NULL ;
V_36 = NULL ;
if ( rename ( V_26 , V_55 [ 2 ] ) < 0 )
{
F_7 ( V_60 , L_74 ,
V_26 , V_55 [ 2 ] ) ;
perror ( L_75 ) ;
goto V_69;
}
if ( rename ( V_55 [ 0 ] , V_26 ) < 0 )
{
F_7 ( V_60 , L_74 ,
V_55 [ 0 ] , V_26 ) ;
perror ( L_75 ) ;
rename ( V_55 [ 2 ] , V_26 ) ;
goto V_69;
}
strncpy ( V_55 [ 2 ] , V_39 , V_54 - 4 ) ;
#ifdef F_9
strcat ( V_55 [ 2 ] , L_72 ) ;
#else
strcat ( V_55 [ 2 ] , L_73 ) ;
#endif
if ( rename ( V_39 , V_55 [ 2 ] ) < 0 )
{
F_7 ( V_60 , L_74 ,
V_39 , V_55 [ 2 ] ) ;
perror ( L_75 ) ;
goto V_69;
}
if ( rename ( V_55 [ 1 ] , V_39 ) < 0 )
{
F_7 ( V_60 , L_74 ,
V_55 [ 1 ] , V_39 ) ;
perror ( L_75 ) ;
rename ( V_55 [ 2 ] , V_39 ) ;
goto V_69;
}
F_7 ( V_60 , L_76 ) ;
}
}
if ( V_9 )
{
V_28 = F_12 ( V_71 , V_65 , V_118 ) ;
if( V_28 ) {
T_12 V_109 ;
F_34 ( & V_109 ) ;
F_35 ( & V_109 , V_71 ) ;
if( ! F_36 ( V_71 , & V_109 , V_28 , NULL ) ) {
F_7 ( V_60 ,
L_77 ,
V_28 ) ;
V_6 = 1 ;
goto V_69;
}
}
if ( ( V_53 = F_4 ( F_51 () ) ) == NULL ) goto V_69;
if ( ! V_11 && ! V_12 )
{
V_11 = F_38 ( V_71 , V_65 ,
V_119 ) ;
V_12 = F_38 ( V_71 , V_65 ,
V_120 ) ;
}
if ( ( V_11 == 0 ) && ( V_12 == 0 ) )
{
F_7 ( V_60 , L_78 ) ;
goto V_69;
}
if ( V_8 ) F_7 ( V_60 , L_79 ) ;
if ( ( V_41 = F_52 () ) == NULL ) goto V_69;
V_42 = V_41 -> V_41 ;
F_53 ( V_42 -> V_121 ) ;
V_42 -> V_121 = F_54 ( V_33 -> V_115 -> V_122 ) ;
if ( V_42 -> V_121 == NULL ) goto V_69;
F_55 ( V_42 -> V_123 , 0 ) ;
if ( V_42 -> V_124 == NULL )
V_42 -> V_124 = F_56 () ;
F_55 ( V_42 -> V_124 , ( V_11 * 24 + V_12 ) * 60 * 60 ) ;
for ( V_47 = 0 ; V_47 < F_26 ( V_40 -> V_90 ) ; V_47 ++ )
{
V_44 = ( char * * ) F_27 ( V_40 -> V_90 , V_47 ) ;
if ( V_44 [ V_91 ] [ 0 ] == V_92 )
{
if ( ( V_43 = F_57 () ) == NULL ) goto V_69;
F_58 ( ( V_125 * )
V_43 -> V_126 ,
( unsigned char * ) V_44 [ V_93 ] ,
strlen ( V_44 [ V_93 ] ) ) ;
F_59 ( V_53 ) ;
if ( ! F_60 ( V_53 , V_44 [ V_95 ] ) )
goto V_69;
if ( ! F_61 ( V_53 , V_43 -> V_116 ,
V_55 [ 0 ] , V_54 ) ) goto V_69;
F_45 ( V_42 -> V_127 , ( char * ) V_43 ) ;
}
}
F_62 ( V_42 -> V_127 , NULL ) ;
for ( V_47 = 0 ; V_47 < F_26 ( V_42 -> V_127 ) ; V_47 ++ )
{
V_43 = ( T_8 * ) F_27 ( V_42 -> V_127 , V_47 ) ;
V_43 -> V_128 = V_47 ;
}
if ( V_8 ) F_7 ( V_60 , L_80 ) ;
if ( V_15 != NULL )
{
if ( ( V_50 = F_32 ( V_15 ) ) == NULL )
{
F_7 ( V_60 , L_52 , V_15 ) ;
goto V_69;
}
}
else
{
#ifndef F_63
if ( V_22 -> type == V_129 )
V_50 = F_64 () ;
else
#endif
V_50 = F_65 () ;
}
if( V_28 ) {
T_12 V_130 ;
if ( V_42 -> V_131 == NULL )
if ( ( V_42 -> V_131 = F_66 () ) == NULL ) goto V_69;
F_67 ( V_42 -> V_131 , 1 ) ;
F_68 ( & V_130 , V_33 , NULL , NULL , V_41 , 0 ) ;
F_35 ( & V_130 , V_71 ) ;
if( ! F_69 ( V_71 , & V_130 ,
V_28 , V_41 ) ) goto V_69;
}
if ( ! F_70 ( V_41 , V_22 , V_50 ) ) goto V_69;
F_71 ( V_37 , V_41 ) ;
}
if ( V_10 )
{
V_35 = F_4 ( F_5 () ) ;
V_36 = F_4 ( F_5 () ) ;
if ( ( V_35 == NULL ) || ( V_36 == NULL ) )
{
F_19 ( V_60 ) ;
goto V_69;
}
if ( V_19 == NULL )
{
F_7 ( V_60 , L_81 ) ;
goto V_69;
}
else
{
if ( F_20 ( V_35 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
F_7 ( V_60 , L_82 , V_19 ) ;
goto V_69;
}
V_33 = F_22 ( V_35 , NULL , NULL ) ;
if ( V_33 == NULL )
{
F_7 ( V_60 , L_83 , V_19 ) ;
goto V_69;
}
V_48 = F_72 ( V_33 , V_40 ) ;
strncpy ( V_55 [ 0 ] , V_39 , V_54 - 4 ) ;
strcat ( V_55 [ 0 ] , L_68 ) ;
if ( F_31 ( V_36 , V_55 [ 0 ] ) <= 0 )
{
perror ( V_39 ) ;
F_7 ( V_60 , L_42 , V_39 ) ;
goto V_69;
}
V_48 = F_29 ( V_36 , V_40 ) ;
if ( V_48 <= 0 ) goto V_69;
F_17 ( V_35 ) ;
F_17 ( V_36 ) ;
V_35 = NULL ;
V_36 = NULL ;
strncpy ( V_55 [ 1 ] , V_39 , V_54 - 4 ) ;
strcat ( V_55 [ 1 ] , L_73 ) ;
if ( rename ( V_39 , V_55 [ 1 ] ) < 0 )
{
F_7 ( V_60 , L_84 , V_39 , V_55 [ 1 ] ) ;
perror ( L_75 ) ;
goto V_69;
}
if ( rename ( V_55 [ 0 ] , V_39 ) < 0 )
{
F_7 ( V_60 , L_84 , V_55 [ 0 ] , V_39 ) ;
perror ( L_75 ) ;
rename ( V_55 [ 1 ] , V_39 ) ;
goto V_69;
}
F_7 ( V_60 , L_76 ) ;
}
}
V_6 = 0 ;
V_69:
F_17 ( V_53 ) ;
F_17 ( V_38 ) ;
F_17 ( V_37 ) ;
F_17 ( V_36 ) ;
F_17 ( V_35 ) ;
F_73 ( V_52 , V_132 ) ;
if ( V_6 ) F_19 ( V_60 ) ;
F_74 ( V_29 ) ;
F_75 ( V_40 ) ;
F_76 ( V_22 ) ;
V_132 ( V_33 ) ;
F_77 ( V_41 ) ;
F_78 ( V_71 ) ;
F_79 () ;
F_80 () ;
EXIT ( V_6 ) ;
}
static void F_13 ( char * V_133 , char * V_134 )
{
F_7 ( V_60 , L_85 , V_133 , V_134 ) ;
}
static int T_13 V_76 ( char * V_55 , int V_135 , int V_136 )
{
int V_47 ;
if ( V_66 == NULL ) return ( 0 ) ;
V_47 = strlen ( V_66 ) ;
V_47 = ( V_47 > V_135 ) ? V_135 : V_47 ;
memcpy ( V_55 , V_66 , V_47 ) ;
return ( V_47 ) ;
}
static unsigned long V_97 ( char * * V_137 )
{
char * V_114 ;
V_114 = V_137 [ V_95 ] ;
while ( * V_114 == '0' ) V_114 ++ ;
return ( F_81 ( V_114 ) ) ;
}
static int V_98 ( char * * V_137 , char * * V_138 )
{
char * V_139 , * V_140 ;
for ( V_139 = V_137 [ V_95 ] ; * V_139 == '0' ; V_139 ++ ) ;
for ( V_140 = V_138 [ V_95 ] ; * V_140 == '0' ; V_140 ++ ) ;
return ( strcmp ( V_139 , V_140 ) ) ;
}
static unsigned long V_103 ( char * * V_137 )
{ return ( F_81 ( V_137 [ V_101 ] ) ) ; }
static int V_102 ( char * * V_137 )
{ return ( V_137 [ 0 ] [ 0 ] == 'V' ) ; }
static int V_104 ( char * * V_137 , char * * V_138 )
{ return ( strcmp ( V_137 [ V_101 ] ,
V_138 [ V_101 ] ) ) ; }
static T_2 * F_39 ( char * V_26 )
{
T_4 * V_35 = NULL ;
T_2 * V_6 = NULL ;
T_11 char V_55 [ 1024 ] ;
T_14 * V_141 = NULL ;
if ( ( V_35 = F_4 ( F_5 () ) ) == NULL )
{
F_19 ( V_60 ) ;
goto V_69;
}
if ( F_20 ( V_35 , V_26 ) <= 0 )
{
perror ( V_26 ) ;
goto V_69;
}
V_141 = F_66 () ;
if ( V_141 == NULL ) goto V_69;
if ( ! F_61 ( V_35 , V_141 , V_55 , 1024 ) )
{
F_7 ( V_60 , L_86 ,
V_26 ) ;
goto V_69;
}
V_6 = F_82 ( V_141 , NULL ) ;
if ( V_6 == NULL )
{
F_7 ( V_60 , L_87 ) ;
goto V_69;
}
V_69:
if ( V_35 != NULL ) F_17 ( V_35 ) ;
if ( V_141 != NULL ) F_83 ( V_141 ) ;
return ( V_6 ) ;
}
static int F_49 ( char * V_26 , T_2 * V_29 )
{
T_4 * V_36 ;
int V_6 = 0 ;
T_14 * V_141 = NULL ;
V_36 = F_4 ( F_5 () ) ;
if ( V_36 == NULL )
{
F_19 ( V_60 ) ;
goto V_69;
}
if ( F_31 ( V_36 , V_26 ) <= 0 )
{
perror ( V_26 ) ;
goto V_69;
}
if ( ( V_141 = F_84 ( V_29 , NULL ) ) == NULL )
{
F_7 ( V_60 , L_88 ) ;
goto V_69;
}
F_85 ( V_36 , V_141 ) ;
F_60 ( V_36 , L_63 ) ;
V_6 = 1 ;
V_69:
if ( V_36 != NULL ) F_17 ( V_36 ) ;
if ( V_141 != NULL ) F_83 ( V_141 ) ;
return ( V_6 ) ;
}
static int F_47 ( T_3 * * V_142 , char * V_19 , T_1 * V_22 , T_3 * V_33 ,
const T_9 * V_50 , T_10 * V_16 , T_5 * V_40 , T_2 * V_29 ,
char * V_30 , int V_31 , int V_32 , char * V_143 , T_15 * V_144 ,
int V_8 )
{
T_16 * V_7 = NULL ;
T_4 * V_35 = NULL ;
T_1 * V_145 = NULL ;
int V_146 = - 1 , V_47 ;
V_35 = F_4 ( F_5 () ) ;
if ( F_20 ( V_35 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
goto V_69;
}
if ( ( V_7 = F_86 ( V_35 , NULL , NULL ) ) == NULL )
{
F_7 ( V_60 , L_89 ,
V_19 ) ;
goto V_69;
}
if ( V_8 )
F_87 ( V_60 , V_7 ) ;
F_7 ( V_60 , L_90 ) ;
if ( ( V_145 = F_88 ( V_7 ) ) == NULL )
{
F_7 ( V_60 , L_91 ) ;
goto V_69;
}
V_47 = F_89 ( V_7 , V_145 ) ;
F_76 ( V_145 ) ;
if ( V_47 < 0 )
{
V_146 = 0 ;
F_7 ( V_60 , L_92 ) ;
goto V_69;
}
if ( V_47 == 0 )
{
V_146 = 0 ;
F_7 ( V_60 , L_93 ) ;
goto V_69;
}
else
F_7 ( V_60 , L_94 ) ;
V_146 = F_90 ( V_142 , V_22 , V_33 , V_50 , V_16 , V_40 , V_29 , V_30 ,
V_31 , V_32 , V_8 , V_7 , V_143 , V_144 ) ;
V_69:
if ( V_7 != NULL ) F_91 ( V_7 ) ;
if ( V_35 != NULL ) F_17 ( V_35 ) ;
return ( V_146 ) ;
}
static int F_46 ( T_3 * * V_142 , char * V_19 , T_1 * V_22 , T_3 * V_33 ,
const T_9 * V_50 , T_10 * V_16 , T_5 * V_40 , T_2 * V_29 ,
char * V_30 , int V_31 , int V_32 , char * V_143 , T_15 * V_144 ,
int V_8 )
{
T_3 * V_7 = NULL ;
T_16 * V_147 = NULL ;
T_4 * V_35 = NULL ;
T_1 * V_145 = NULL ;
int V_146 = - 1 , V_47 ;
V_35 = F_4 ( F_5 () ) ;
if ( F_20 ( V_35 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
goto V_69;
}
if ( ( V_7 = F_22 ( V_35 , NULL , NULL ) ) == NULL )
{
F_7 ( V_60 , L_95 , V_19 ) ;
goto V_69;
}
if ( V_8 )
F_92 ( V_60 , V_7 ) ;
F_7 ( V_60 , L_90 ) ;
if ( ( V_145 = F_93 ( V_7 ) ) == NULL )
{
F_7 ( V_60 , L_91 ) ;
goto V_69;
}
V_47 = F_94 ( V_7 , V_145 ) ;
F_76 ( V_145 ) ;
if ( V_47 < 0 )
{
V_146 = 0 ;
F_7 ( V_60 , L_92 ) ;
goto V_69;
}
if ( V_47 == 0 )
{
V_146 = 0 ;
F_7 ( V_60 , L_96 ) ;
goto V_69;
}
else
F_7 ( V_60 , L_94 ) ;
if ( ( V_147 = F_95 ( V_7 , NULL , F_65 () ) ) == NULL )
goto V_69;
V_146 = F_90 ( V_142 , V_22 , V_33 , V_50 , V_16 , V_40 , V_29 , V_30 , V_31 ,
V_32 , V_8 , V_147 , V_143 , V_144 ) ;
V_69:
if ( V_147 != NULL ) F_91 ( V_147 ) ;
if ( V_7 != NULL ) V_132 ( V_7 ) ;
if ( V_35 != NULL ) F_17 ( V_35 ) ;
return ( V_146 ) ;
}
static int F_90 ( T_3 * * V_142 , T_1 * V_22 , T_3 * V_33 , const T_9 * V_50 ,
T_10 * V_16 , T_5 * V_40 , T_2 * V_29 , char * V_30 , int V_31 ,
int V_32 , int V_8 , T_16 * V_7 , char * V_143 , T_15 * V_144 )
{
T_17 * V_133 = NULL , * V_148 = NULL , * V_122 = NULL ;
T_18 * V_149 , * V_150 ;
V_125 * V_151 , * V_152 ;
T_19 * V_153 ;
T_3 * V_6 = NULL ;
T_20 * V_42 ;
T_21 * V_154 ;
T_21 * V_155 , * V_156 ;
T_1 * V_145 ;
int V_146 = - 1 , V_47 , V_48 , V_157 , V_158 ;
char * V_45 ;
T_22 * V_159 ;
char * V_160 [ V_89 ] , * * V_161 , * * V_162 = NULL ;
char V_55 [ 25 ] , * V_163 ;
V_150 = F_56 () ;
if ( V_150 == NULL )
{
F_7 ( V_60 , L_97 ) ;
return ( 0 ) ;
}
for ( V_47 = 0 ; V_47 < V_89 ; V_47 ++ )
V_160 [ V_47 ] = NULL ;
F_7 ( V_60 , L_98 ) ;
V_133 = F_96 ( V_7 ) ;
for ( V_47 = 0 ; V_47 < F_97 ( V_133 ) ; V_47 ++ )
{
V_154 = ( T_21 * ) F_98 ( V_133 , V_47 ) ;
V_153 = F_99 ( V_154 ) ;
V_48 = F_100 ( V_60 , V_153 ) ;
V_151 = F_101 ( V_154 ) ;
V_163 = V_55 ;
for ( V_48 = 22 - V_48 ; V_48 > 0 ; V_48 -- )
* ( V_163 ++ ) = ' ' ;
* ( V_163 ++ ) = ':' ;
* ( V_163 ++ ) = '\0' ;
F_60 ( V_60 , V_55 ) ;
if ( V_67 )
{
V_158 = F_102 ( V_154 -> V_164 ) ;
if ( V_151 -> type == V_165 )
F_103 ( V_151 ) ;
if ( ( V_151 -> type == V_166 ) &&
( V_158 != V_167 ) )
V_151 -> type = V_168 ;
if ( ( V_158 == V_167 ) &&
( V_151 -> type == V_169 ) )
V_151 -> type = V_166 ;
}
if ( V_151 -> type == V_169 )
F_7 ( V_60 , L_99 ) ;
else if ( V_151 -> type == V_168 )
F_7 ( V_60 , L_100 ) ;
else if ( V_151 -> type == V_166 )
F_7 ( V_60 , L_101 ) ;
else if ( V_151 -> type == V_165 )
F_7 ( V_60 , L_102 ) ;
else
F_7 ( V_60 , L_103 , V_151 -> type ) ;
if ( ( F_102 ( V_153 ) == V_167 ) &&
( V_151 -> type != V_166 ) )
{
F_7 ( V_60 , L_104 ) ;
goto V_69;
}
V_48 = F_104 ( V_151 -> V_90 , V_151 -> V_117 ) ;
if ( ( ( V_48 == V_168 ) &&
( V_151 -> type != V_168 ) ) ||
( ( V_48 == V_166 ) &&
( V_151 -> type == V_169 ) ) )
{
F_7 ( V_60 , L_105 ) ;
goto V_69;
}
V_45 = ( char * ) V_151 -> V_90 ;
for ( V_48 = V_151 -> V_117 ; V_48 > 0 ; V_48 -- )
{
if ( ( * V_45 >= ' ' ) && ( * V_45 <= '~' ) )
F_7 ( V_60 , L_106 , * V_45 ) ;
else if ( * V_45 & 0x80 )
F_7 ( V_60 , L_107 , * V_45 ) ;
else if ( ( unsigned char ) * V_45 == 0xf7 )
F_7 ( V_60 , L_108 ) ;
else F_7 ( V_60 , L_109 , * V_45 + '@' ) ;
V_45 ++ ;
}
F_7 ( V_60 , L_110 ) ;
}
if ( ( V_122 = F_105 () ) == NULL )
{
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
V_148 = F_54 ( V_33 -> V_115 -> V_122 ) ;
if ( V_148 == NULL ) goto V_69;
V_151 = V_152 = NULL ;
for ( V_47 = 0 ; V_47 < F_26 ( V_16 ) ; V_47 ++ )
{
V_159 = ( T_22 * ) F_27 ( V_16 , V_47 ) ;
if ( ( V_48 = F_106 ( V_159 -> V_133 ) ) == V_170 )
{
F_7 ( V_60 , L_111 , V_159 -> V_133 ) ;
goto V_69;
}
V_153 = F_107 ( V_48 ) ;
V_157 = - 1 ;
for (; ; )
{
V_48 = F_108 ( V_133 , V_153 , V_157 ) ;
if ( V_48 < 0 )
{
if ( V_157 != - 1 ) break;
V_155 = NULL ;
}
else
{
V_155 = F_98 ( V_133 , V_48 ) ;
}
V_157 = V_48 ;
V_156 = NULL ;
if ( strcmp ( V_159 -> V_171 , L_112 ) == 0 )
{
if ( V_155 != NULL )
V_156 = V_155 ;
}
else if ( strcmp ( V_159 -> V_171 , L_113 ) == 0 )
{
if ( V_155 == NULL )
{
F_7 ( V_60 , L_114 , V_159 -> V_133 ) ;
goto V_69;
}
else
V_156 = V_155 ;
}
else if ( strcmp ( V_159 -> V_171 , L_115 ) == 0 )
{
int V_172 ;
if ( V_155 == NULL )
{
F_7 ( V_60 , L_116 , V_159 -> V_133 ) ;
goto V_69;
}
V_172 = - 1 ;
V_173:
V_48 = F_108 ( V_148 , V_153 , V_172 ) ;
if ( ( V_48 < 0 ) && ( V_172 == - 1 ) )
{
F_7 ( V_60 , L_117 , V_159 -> V_133 ) ;
goto V_69;
}
if ( V_48 >= 0 )
{
V_156 = F_98 ( V_148 , V_48 ) ;
V_151 = F_101 ( V_155 ) ;
V_152 = F_101 ( V_156 ) ;
V_172 = V_48 ;
if ( F_109 ( V_151 , V_152 ) != 0 )
goto V_173;
}
if ( V_48 < 0 )
{
F_7 ( V_60 , L_118 , V_159 -> V_133 , ( ( V_151 == NULL ) ? L_119 : ( char * ) V_151 -> V_90 ) , ( ( V_152 == NULL ) ? L_119 : ( char * ) V_152 -> V_90 ) ) ;
goto V_69;
}
}
else
{
F_7 ( V_60 , L_120 , V_159 -> V_171 ) ;
goto V_69;
}
if ( V_156 != NULL )
{
if ( ! F_110 ( V_122 , V_156 ,
F_97 ( V_122 ) , 0 ) )
{
if ( V_156 != NULL )
F_111 ( V_156 ) ;
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
}
if ( V_48 < 0 ) break;
}
}
if ( V_59 )
{
F_53 ( V_122 ) ;
V_122 = F_54 ( F_96 ( V_7 ) ) ;
if ( V_122 == NULL ) goto V_69;
}
if ( V_8 )
F_7 ( V_60 , L_121 ) ;
V_160 [ V_101 ] = F_112 ( V_122 , NULL , 0 ) ;
V_160 [ V_95 ] = F_40 ( V_29 ) ;
if ( ( V_160 [ V_101 ] == NULL ) || ( V_160 [ V_95 ] == NULL ) )
{
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
V_161 = F_113 ( V_40 , V_101 , V_160 ) ;
if ( V_161 != NULL )
{
F_7 ( V_60 , L_122 ,
V_160 [ V_101 ] ) ;
}
else
{
V_161 = F_113 ( V_40 , V_95 , V_160 ) ;
if ( V_161 != NULL )
{
F_7 ( V_60 , L_123 ,
V_160 [ V_95 ] ) ;
F_7 ( V_60 , L_124 ) ;
}
}
if ( V_161 != NULL )
{
F_7 ( V_60 ,
L_125 ) ;
if ( V_161 [ V_91 ] [ 0 ] == 'E' )
V_45 = L_126 ;
else if ( V_161 [ V_91 ] [ 0 ] == 'R' )
V_45 = L_127 ;
else if ( V_161 [ V_91 ] [ 0 ] == 'V' )
V_45 = L_128 ;
else
V_45 = L_129 ;
F_7 ( V_60 , L_130 , V_45 ) ; ;
if ( V_161 [ V_91 ] [ 0 ] == 'R' )
{
V_45 = V_161 [ V_94 ] ; if ( V_45 == NULL ) V_45 = L_131 ;
F_7 ( V_60 , L_132 , V_45 ) ;
}
V_45 = V_161 [ V_94 ] ; if ( V_45 == NULL ) V_45 = L_131 ;
F_7 ( V_60 , L_133 , V_45 ) ;
V_45 = V_161 [ V_95 ] ; if ( V_45 == NULL ) V_45 = L_131 ;
F_7 ( V_60 , L_134 , V_45 ) ;
V_45 = V_161 [ V_174 ] ; if ( V_45 == NULL ) V_45 = L_131 ;
F_7 ( V_60 , L_135 , V_45 ) ;
V_45 = V_161 [ V_101 ] ; if ( V_45 == NULL ) V_45 = L_131 ;
F_7 ( V_60 , L_136 , V_45 ) ;
V_146 = - 1 ;
goto V_69;
}
if ( V_8 )
F_7 ( V_60 , L_137 ) ;
if ( ( V_6 = F_114 () ) == NULL ) goto V_69;
V_42 = V_6 -> V_115 ;
#ifdef F_115
if ( ! F_116 ( V_33 , 2 ) ) goto V_69;
#endif
if ( F_84 ( V_29 , V_42 -> V_116 ) == NULL )
goto V_69;
if ( ! F_117 ( V_6 , F_118 ( V_33 ) ) )
goto V_69;
F_7 ( V_60 , L_138 ) ;
if ( strcmp ( V_30 , L_56 ) == 0 )
{
F_55 ( F_119 ( V_6 ) , 0 ) ;
F_55 ( F_120 ( V_6 ) , ( long ) 60 * 60 * 24 * V_31 ) ;
}
else
{
F_37 ( F_119 ( V_6 ) , V_30 ) ;
}
F_121 ( V_60 , F_120 ( V_6 ) ) ;
F_7 ( V_60 , L_139 , V_31 ) ;
if ( ! F_122 ( V_6 , V_122 ) ) goto V_69;
V_145 = F_88 ( V_7 ) ;
V_47 = F_123 ( V_6 , V_145 ) ;
F_76 ( V_145 ) ;
if ( ! V_47 ) goto V_69;
if ( V_143 )
{
T_12 V_109 ;
if ( V_42 -> V_131 == NULL )
if ( ( V_42 -> V_131 = F_66 () ) == NULL )
goto V_69;
F_67 ( V_42 -> V_131 , 2 ) ;
if ( V_42 -> V_27 != NULL )
F_124 ( V_42 -> V_27 ,
V_175 ) ;
V_42 -> V_27 = NULL ;
F_68 ( & V_109 , V_33 , V_6 , V_7 , NULL , 0 ) ;
F_35 ( & V_109 , V_144 ) ;
if( ! F_36 ( V_144 , & V_109 , V_143 , V_6 ) ) goto V_69;
}
if ( ! V_32 )
{
F_7 ( V_60 , L_140 ) ;
F_48 ( V_60 ) ;
V_55 [ 0 ] = '\0' ;
fgets ( V_55 , sizeof( V_55 ) - 1 , V_112 ) ;
if ( ! ( ( V_55 [ 0 ] == 'y' ) || ( V_55 [ 0 ] == 'Y' ) ) )
{
F_7 ( V_60 , L_141 ) ;
V_146 = 0 ;
goto V_69;
}
}
#ifndef F_63
if ( V_22 -> type == V_129 ) V_50 = F_64 () ;
V_145 = F_93 ( V_6 ) ;
if ( F_125 ( V_145 ) &&
! F_125 ( V_22 ) )
F_126 ( V_145 , V_22 ) ;
F_76 ( V_145 ) ;
#endif
if ( ! F_127 ( V_6 , V_22 , V_50 ) )
goto V_69;
V_160 [ V_91 ] = ( char * ) Malloc ( 2 ) ;
V_149 = F_120 ( V_6 ) ;
V_160 [ V_94 ] = ( char * ) Malloc ( V_149 -> V_117 + 1 ) ;
memcpy ( V_160 [ V_94 ] , V_149 -> V_90 , V_149 -> V_117 ) ;
V_160 [ V_94 ] [ V_149 -> V_117 ] = '\0' ;
V_160 [ V_93 ] = NULL ;
V_160 [ V_174 ] = ( char * ) Malloc ( 8 ) ;
if ( ( V_160 [ V_91 ] == NULL ) || ( V_160 [ V_94 ] == NULL ) ||
( V_160 [ V_174 ] == NULL ) )
{
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
strcpy ( V_160 [ V_174 ] , L_142 ) ;
V_160 [ V_91 ] [ 0 ] = 'V' ;
V_160 [ V_91 ] [ 1 ] = '\0' ;
if ( ( V_162 = ( char * * ) Malloc ( sizeof( char * ) * ( V_89 + 1 ) ) ) == NULL )
{
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
for ( V_47 = 0 ; V_47 < V_89 ; V_47 ++ )
{
V_162 [ V_47 ] = V_160 [ V_47 ] ;
V_160 [ V_47 ] = NULL ;
}
V_162 [ V_89 ] = NULL ;
if ( ! F_128 ( V_40 , V_162 ) )
{
F_7 ( V_60 , L_143 ) ;
F_7 ( V_60 , L_144 , V_40 -> error ) ;
goto V_69;
}
V_146 = 1 ;
V_69:
for ( V_47 = 0 ; V_47 < V_89 ; V_47 ++ )
if ( V_160 [ V_47 ] != NULL ) Free ( V_160 [ V_47 ] ) ;
if ( V_148 != NULL )
F_53 ( V_148 ) ;
if ( V_122 != NULL )
F_53 ( V_122 ) ;
if ( V_146 <= 0 )
{
if ( V_6 != NULL ) V_132 ( V_6 ) ;
V_6 = NULL ;
}
else
* V_142 = V_6 ;
return ( V_146 ) ;
}
static void F_50 ( T_4 * V_176 , T_3 * V_34 , int V_23 )
{
char * V_46 ;
char V_55 [ 256 ] ;
if ( V_23 )
{
( void ) F_129 ( V_176 , V_34 ) ;
return;
}
V_46 = F_112 ( F_130 ( V_34 ) , V_55 , 256 ) ;
F_7 ( V_176 , L_145 , V_46 ) ;
V_46 = F_112 ( F_118 ( V_34 ) , V_55 , 256 ) ;
F_7 ( V_176 , L_146 , V_46 ) ;
F_60 ( V_176 , L_147 ) ;
F_85 ( V_176 , V_34 -> V_115 -> V_116 ) ;
F_60 ( V_176 , L_148 ) ;
F_92 ( V_176 , V_34 ) ;
F_60 ( V_176 , L_63 ) ;
F_131 ( V_176 , V_34 ) ;
F_60 ( V_176 , L_63 ) ;
}
static int F_43 ( T_3 * * V_142 , char * V_19 , T_1 * V_22 , T_3 * V_33 ,
const T_9 * V_50 , T_10 * V_16 , T_5 * V_40 , T_2 * V_29 ,
char * V_30 , int V_31 , char * V_143 , T_15 * V_144 , int V_8 )
{
T_10 * V_177 = NULL ;
T_15 * V_178 = NULL ;
T_16 * V_7 = NULL ;
T_22 * V_159 = NULL ;
T_23 * V_179 = NULL ;
unsigned char * V_180 = NULL , * V_45 ;
T_24 * V_181 ;
char * type , * V_55 ;
T_1 * V_145 = NULL ;
T_17 * V_114 = NULL ;
T_21 * V_154 = NULL ;
int V_146 = - 1 , V_47 , V_48 ;
long V_182 ;
int V_158 ;
V_178 = F_11 ( NULL , V_19 , & V_182 ) ;
if ( V_178 == NULL )
{
F_7 ( V_60 , L_149 , V_182 , V_19 ) ;
F_19 ( V_60 ) ;
goto V_69;
}
V_177 = F_41 ( V_178 , L_150 ) ;
if ( F_26 ( V_177 ) == 0 )
{
F_7 ( V_60 , L_151 , V_19 ) ;
F_78 ( V_178 ) ;
goto V_69;
}
V_7 = F_132 () ;
if ( V_7 == NULL )
{
F_19 ( V_60 ) ;
goto V_69;
}
V_181 = V_7 -> V_183 ;
V_114 = V_181 -> V_122 ;
for ( V_47 = 0 ; ; V_47 ++ )
{
if ( ( int ) F_26 ( V_177 ) <= V_47 ) break;
V_159 = ( T_22 * ) F_27 ( V_177 , V_47 ) ;
type = V_159 -> V_133 ;
V_55 = V_159 -> V_171 ;
if ( ( V_158 = F_106 ( type ) ) == V_170 )
{
if ( strcmp ( type , L_152 ) == 0 )
{
V_180 = ( unsigned char * ) Malloc (
strlen ( V_159 -> V_171 ) + 1 ) ;
if ( V_180 == NULL )
{
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
V_48 = F_133 ( V_180 , ( unsigned char * ) V_159 -> V_171 ,
strlen ( V_159 -> V_171 ) ) ;
if ( V_48 <= 0 )
{
F_7 ( V_60 , L_153 ) ;
goto V_69;
}
V_45 = V_180 ;
V_179 = F_134 ( & V_179 , & V_45 , V_48 ) ;
Free ( V_180 ) ;
V_180 = NULL ;
if ( V_179 == NULL )
{
F_7 ( V_60 , L_154 ) ;
F_19 ( V_60 ) ;
goto V_69;
}
}
continue;
}
V_48 = F_104 ( ( unsigned char * ) V_55 , - 1 ) ;
if ( F_135 ( V_158 , & V_48 ) == 0 )
{
F_7 ( V_60 ,
L_155 , V_55 ) ;
goto V_69;
}
if ( ( V_154 = F_136 ( & V_154 , V_158 , V_48 ,
( unsigned char * ) V_55 ,
strlen ( V_55 ) ) ) == NULL )
goto V_69;
if ( ! F_110 ( V_114 , V_154 , F_97 ( V_114 ) , 0 ) )
goto V_69;
}
if ( V_179 == NULL )
{
F_7 ( V_60 , L_156 ,
V_19 ) ;
goto V_69;
}
F_7 ( V_60 , L_157 ) ;
if ( ( V_145 = F_137 ( V_179 -> V_184 -> V_185 ) ) == NULL )
{
F_7 ( V_60 , L_158 ) ;
goto V_69;
}
V_48 = F_138 ( V_179 , V_145 ) ;
if ( V_48 <= 0 )
{
F_7 ( V_60 , L_159 ) ;
goto V_69;
}
F_7 ( V_60 , L_94 ) ;
F_139 ( V_7 , V_145 ) ;
F_76 ( V_145 ) ;
V_146 = F_90 ( V_142 , V_22 , V_33 , V_50 , V_16 , V_40 , V_29 , V_30 ,
V_31 , 1 , V_8 , V_7 , V_143 , V_144 ) ;
V_69:
if ( V_7 != NULL ) F_91 ( V_7 ) ;
if ( V_178 != NULL ) F_78 ( V_178 ) ;
if ( V_180 != NULL ) Free ( V_180 ) ;
if ( V_179 != NULL ) F_140 ( V_179 ) ;
if ( V_154 != NULL ) F_111 ( V_154 ) ;
return ( V_146 ) ;
}
static int F_135 ( int V_158 , int * type )
{
if ( V_158 == V_167 )
* type = V_166 ;
if ( ( V_158 == V_186 ) && ( * type == V_166 ) )
* type = V_168 ;
if ( ( V_158 == V_187 ) && ( * type == V_166 ) )
* type = V_168 ;
if ( ( V_158 == V_188 ) && ( * type == V_168 ) )
return ( 0 ) ;
if ( V_158 == V_188 )
* type = V_166 ;
return ( 1 ) ;
}
static int F_28 ( char * V_151 )
{
T_18 V_149 ;
V_149 . V_90 = ( unsigned char * ) V_151 ;
V_149 . V_117 = strlen ( V_151 ) ;
V_149 . type = V_189 ;
return ( F_141 ( & V_149 ) ) ;
}
static int F_18 ( T_15 * V_190 )
{
char * V_45 ;
T_10 * V_191 ;
T_22 * V_192 ;
int V_47 ;
if( ! ( V_45 = F_12 ( V_190 , NULL , L_160 ) ) ) return 1 ;
if( ! ( V_191 = F_41 ( V_190 , V_45 ) ) ) {
F_7 ( V_60 , L_161 , V_45 ) ;
return 0 ;
}
for( V_47 = 0 ; V_47 < F_26 ( V_191 ) ; V_47 ++ ) {
V_192 = ( T_22 * ) F_27 ( V_191 , V_47 ) ;
if( F_142 ( V_192 -> V_171 , V_192 -> V_133 , V_192 -> V_133 ) == V_170 ) {
F_7 ( V_60 , L_162 ,
V_192 -> V_133 , V_192 -> V_171 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_72 ( T_3 * V_33 , T_5 * V_40 )
{
T_18 * V_149 = NULL ;
char * V_160 [ V_89 ] , * * V_161 , * * V_162 ;
int V_146 = - 1 , V_47 ;
for ( V_47 = 0 ; V_47 < V_89 ; V_47 ++ )
V_160 [ V_47 ] = NULL ;
V_160 [ V_101 ] = F_112 ( V_33 -> V_115 -> V_122 , NULL , 0 ) ;
V_160 [ V_95 ] = F_40 ( F_82 ( V_33 -> V_115 -> V_116 , NULL ) ) ;
if ( ( V_160 [ V_101 ] == NULL ) || ( V_160 [ V_95 ] == NULL ) )
{
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
V_161 = F_113 ( V_40 , V_101 , V_160 ) ;
if ( V_161 == NULL )
{
F_7 ( V_60 , L_163 , V_160 [ V_101 ] ) ;
V_160 [ V_91 ] = ( char * ) Malloc ( 2 ) ;
V_149 = F_120 ( V_33 ) ;
V_160 [ V_94 ] = ( char * ) Malloc ( V_149 -> V_117 + 1 ) ;
memcpy ( V_160 [ V_94 ] , V_149 -> V_90 , V_149 -> V_117 ) ;
V_160 [ V_94 ] [ V_149 -> V_117 ] = '\0' ;
V_160 [ V_93 ] = NULL ;
V_160 [ V_174 ] = ( char * ) Malloc ( 8 ) ;
if ( ( V_160 [ V_91 ] == NULL ) || ( V_160 [ V_94 ] == NULL ) ||
( V_160 [ V_174 ] == NULL ) )
{
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
strcpy ( V_160 [ V_174 ] , L_142 ) ;
V_160 [ V_91 ] [ 0 ] = 'V' ;
V_160 [ V_91 ] [ 1 ] = '\0' ;
if ( ( V_162 = ( char * * ) Malloc ( sizeof( char * ) * ( V_89 + 1 ) ) ) == NULL )
{
F_7 ( V_60 , L_62 ) ;
goto V_69;
}
for ( V_47 = 0 ; V_47 < V_89 ; V_47 ++ )
{
V_162 [ V_47 ] = V_160 [ V_47 ] ;
V_160 [ V_47 ] = NULL ;
}
V_162 [ V_89 ] = NULL ;
if ( ! F_128 ( V_40 , V_162 ) )
{
F_7 ( V_60 , L_143 ) ;
F_7 ( V_60 , L_144 , V_40 -> error ) ;
goto V_69;
}
F_72 ( V_33 , V_40 ) ;
V_146 = 1 ;
goto V_69;
}
else if ( V_98 ( V_160 , V_161 ) )
{
F_7 ( V_60 , L_164 ,
V_160 [ V_95 ] ) ;
goto V_69;
}
else if ( V_161 [ V_91 ] [ 0 ] == 'R' )
{
F_7 ( V_60 , L_165 ,
V_160 [ V_95 ] ) ;
goto V_69;
}
else
{
F_7 ( V_60 , L_166 , V_161 [ V_95 ] ) ;
V_149 = F_55 ( V_149 , 0 ) ;
V_161 [ V_91 ] [ 0 ] = 'R' ;
V_161 [ V_91 ] [ 1 ] = '\0' ;
V_161 [ V_93 ] = ( char * ) Malloc ( V_149 -> V_117 + 1 ) ;
memcpy ( V_161 [ V_93 ] , V_149 -> V_90 , V_149 -> V_117 ) ;
V_161 [ V_93 ] [ V_149 -> V_117 ] = '\0' ;
}
V_146 = 1 ;
V_69:
for ( V_47 = 0 ; V_47 < V_89 ; V_47 ++ )
{
if ( V_160 [ V_47 ] != NULL )
Free ( V_160 [ V_47 ] ) ;
}
F_143 ( V_149 ) ;
return ( V_146 ) ;
}
