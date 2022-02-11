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
char * V_31 = NULL ;
int V_32 = 0 ;
int V_33 = 0 ;
T_3 * V_34 = NULL ;
T_3 * V_35 = NULL ;
T_4 * V_36 = NULL , * V_37 = NULL , * V_38 = NULL , * V_39 = NULL ;
char * V_40 = NULL ;
T_5 * V_41 = NULL ;
T_6 * V_42 = NULL ;
T_7 * V_43 = NULL ;
T_8 * V_44 = NULL ;
char * * V_45 , * V_46 , * V_47 ;
int V_48 , V_49 ;
long V_50 ;
const T_9 * V_51 = NULL ;
F_1 ( V_52 ) * V_53 = NULL ;
T_10 * V_54 = NULL ;
T_4 * V_55 = NULL ;
#undef V_56
#define V_56 256
T_11 char V_57 [ 3 ] [ V_56 ] ;
#ifdef F_2
V_58 = 1 ;
V_59 = 1 ;
V_60 = 0 ;
#endif
F_3 () ;
F_4 () ;
V_61 = 0 ;
if ( V_62 == NULL )
if ( ( V_62 = F_5 ( F_6 () ) ) != NULL )
F_7 ( V_62 , V_63 , V_64 | V_65 ) ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
V_8 = 1 ;
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_14 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_67 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_30 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_31 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_32 = atoi ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_68 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_19 = * ( ++ V_2 ) ;
V_7 = 1 ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_24 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_25 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
V_33 = 1 ;
else if ( strcmp ( * V_2 , L_16 ) == 0 )
V_61 = 1 ;
else if ( strcmp ( * V_2 , L_17 ) == 0 )
V_9 = 1 ;
else if ( strcmp ( * V_2 , L_18 ) == 0 )
V_69 = 1 ;
else if ( strcmp ( * V_2 , L_19 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_11 = atol ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_20 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_12 = atol ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_21 ) == 0 )
{
V_1 -- ;
V_2 ++ ;
V_7 = 1 ;
break;
}
else if ( strcmp ( * V_2 , L_22 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_21 = * ( ++ V_2 ) ;
V_7 = 1 ;
}
else if ( strcmp ( * V_2 , L_23 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_20 = * ( ++ V_2 ) ;
V_7 = 1 ;
}
else if ( strcmp ( * V_2 , L_24 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_19 = * ( ++ V_2 ) ;
V_10 = 1 ;
}
else
{
V_66:
F_8 ( V_62 , L_25 , * V_2 ) ;
V_5 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_5 )
{
for ( V_45 = V_70 ; ( * V_45 != NULL ) ; V_45 ++ )
F_8 ( V_62 , * V_45 ) ;
goto V_71;
}
F_9 () ;
if ( V_14 == NULL ) V_14 = getenv ( L_26 ) ;
if ( V_14 == NULL ) V_14 = getenv ( L_27 ) ;
if ( V_14 == NULL )
{
#ifdef F_10
strncpy ( V_57 [ 0 ] , F_11 () ,
sizeof( V_57 [ 0 ] ) - 1 - sizeof( V_72 ) ) ;
#else
strncpy ( V_57 [ 0 ] , F_11 () ,
sizeof( V_57 [ 0 ] ) - 2 - sizeof( V_72 ) ) ;
strcat ( V_57 [ 0 ] , L_28 ) ;
#endif
strcat ( V_57 [ 0 ] , V_72 ) ;
V_14 = V_57 [ 0 ] ;
}
F_8 ( V_62 , L_29 , V_14 ) ;
if ( ( V_73 = F_12 ( NULL , V_14 , & V_13 ) ) == NULL )
{
if ( V_13 <= 0 )
F_8 ( V_62 , L_30 ,
V_14 ) ;
else
F_8 ( V_62 , L_31
, V_13 , V_14 ) ;
goto V_71;
}
if ( V_67 == NULL )
{
V_67 = F_13 ( V_73 , V_74 , V_75 ) ;
if ( V_67 == NULL )
{
F_14 ( V_74 , V_75 ) ;
goto V_71;
}
}
if ( V_73 != NULL )
{
V_46 = F_13 ( V_73 , NULL , L_32 ) ;
if ( V_46 != NULL )
{
T_4 * V_76 ;
V_76 = F_15 ( V_46 , L_33 ) ;
if ( V_76 == NULL )
{
F_16 () ;
}
else
{
F_17 ( V_76 ) ;
F_18 ( V_76 ) ;
}
}
}
if( ! F_19 ( V_73 ) ) {
F_20 ( V_62 ) ;
goto V_71;
}
V_36 = F_5 ( F_6 () ) ;
V_37 = F_5 ( F_6 () ) ;
V_38 = F_5 ( F_6 () ) ;
V_39 = F_5 ( F_6 () ) ;
if ( ( V_36 == NULL ) || ( V_37 == NULL ) || ( V_38 == NULL ) || ( V_39 == NULL ) )
{
F_20 ( V_62 ) ;
goto V_71;
}
if ( ( V_17 == NULL ) && ( ( V_17 = F_13 ( V_73 ,
V_67 , V_77 ) ) == NULL ) )
{
F_14 ( V_67 , V_77 ) ;
goto V_71;
}
if ( F_21 ( V_36 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
F_8 ( V_62 , L_34 ) ;
goto V_71;
}
if ( V_68 == NULL )
V_22 = F_22 ( V_36 , NULL , NULL , NULL ) ;
else
{
V_22 = F_22 ( V_36 , NULL , V_78 , NULL ) ;
memset ( V_68 , 0 , strlen ( V_68 ) ) ;
}
if ( V_22 == NULL )
{
F_8 ( V_62 , L_35 ) ;
goto V_71;
}
if ( ( V_18 == NULL ) && ( ( V_18 = F_13 ( V_73 ,
V_67 , V_79 ) ) == NULL ) )
{
F_14 ( V_67 , V_79 ) ;
goto V_71;
}
if ( F_21 ( V_36 , V_18 ) <= 0 )
{
perror ( V_18 ) ;
F_8 ( V_62 , L_36 ) ;
goto V_71;
}
V_34 = F_23 ( V_36 , NULL , NULL , NULL ) ;
if ( V_34 == NULL )
{
F_8 ( V_62 , L_37 ) ;
goto V_71;
}
if ( ! F_24 ( V_34 , V_22 ) )
{
F_8 ( V_62 , L_38 ) ;
goto V_71;
}
V_47 = F_13 ( V_73 , V_74 , V_80 ) ;
if ( ( V_47 != NULL ) && ( ( * V_47 == 'y' ) || ( * V_47 == 'Y' ) ) )
V_61 = 1 ;
V_47 = F_13 ( V_73 , V_74 , V_81 ) ;
if ( ( V_47 != NULL ) && ( ( * V_47 == 'y' ) || ( * V_47 == 'Y' ) ) )
V_69 = 1 ;
if ( ( V_25 == NULL ) && ( V_7 ) )
{
struct V_82 V_83 ;
if ( ( V_25 = F_13 ( V_73 , V_67 , V_84 ) )
== NULL )
{
F_8 ( V_62 , L_39 ) ;
goto V_71;
}
#ifdef F_10
if ( F_25 ( V_25 , V_85 | V_86 ) != 0 )
#else
if ( F_25 ( V_25 , V_85 | V_86 | V_87 ) != 0 )
#endif
{
F_8 ( V_62 , L_40 , V_25 ) ;
perror ( V_25 ) ;
goto V_71;
}
if ( V_82 ( V_25 , & V_83 ) != 0 )
{
F_8 ( V_62 , L_41 , V_25 ) ;
perror ( V_25 ) ;
goto V_71;
}
if ( ! ( V_83 . V_88 & V_89 ) )
{
F_8 ( V_62 , L_42 , V_25 ) ;
perror ( V_25 ) ;
goto V_71;
}
}
if ( ( V_40 = F_13 ( V_73 , V_67 , V_90 ) ) == NULL )
{
F_14 ( V_67 , V_90 ) ;
goto V_71;
}
if ( F_21 ( V_36 , V_40 ) <= 0 )
{
perror ( V_40 ) ;
F_8 ( V_62 , L_43 , V_40 ) ;
goto V_71;
}
V_41 = F_26 ( V_36 , V_91 ) ;
if ( V_41 == NULL ) goto V_71;
for ( V_48 = 0 ; V_48 < F_27 ( V_41 -> V_92 ) ; V_48 ++ )
{
V_45 = ( char * * ) F_28 ( V_41 -> V_92 , V_48 ) ;
if ( ( V_45 [ V_93 ] [ 0 ] != V_94 ) &&
( V_45 [ V_95 ] [ 0 ] != '\0' ) )
{
F_8 ( V_62 , L_44 , V_48 + 1 ) ;
goto V_71;
}
if ( ( V_45 [ V_93 ] [ 0 ] == V_94 ) &&
! F_29 ( V_45 [ V_95 ] ) )
{
F_8 ( V_62 , L_45 ,
V_48 + 1 ) ;
goto V_71;
}
if ( ! F_29 ( V_45 [ V_96 ] ) )
{
F_8 ( V_62 , L_46 , V_48 + 1 ) ;
goto V_71;
}
V_46 = V_45 [ V_97 ] ;
V_49 = strlen ( V_46 ) ;
if ( ( V_49 & 1 ) || ( V_49 < 2 ) )
{
F_8 ( V_62 , L_47 , V_48 + 1 , V_49 ) ;
goto V_71;
}
while ( * V_46 )
{
if ( ! ( ( ( * V_46 >= '0' ) && ( * V_46 <= '9' ) ) ||
( ( * V_46 >= 'A' ) && ( * V_46 <= 'F' ) ) ||
( ( * V_46 >= 'a' ) && ( * V_46 <= 'f' ) ) ) )
{
F_8 ( V_62 , L_48 , V_48 + 1 , ( long ) ( V_46 - V_45 [ V_97 ] ) , * V_46 ) ;
goto V_71;
}
V_46 ++ ;
}
}
if ( V_8 )
{
F_7 ( V_37 , stdout , V_64 | V_65 ) ;
F_30 ( V_37 , V_41 ) ;
F_8 ( V_62 , L_49 ,
V_41 -> V_92 -> V_98 ) ;
F_8 ( V_62 , L_50 ) ;
}
if ( ! F_31 ( V_41 , V_97 , NULL , V_99 ,
V_100 ) )
{
F_8 ( V_62 , L_51 , V_41 -> error , V_41 -> V_101 , V_41 -> V_102 ) ;
goto V_71;
}
if ( ! F_31 ( V_41 , V_103 , V_104 , V_105 ,
V_106 ) )
{
F_8 ( V_62 , L_52 ,
V_41 -> error , V_41 -> V_101 , V_41 -> V_102 ) ;
goto V_71;
}
if ( V_7 || V_9 )
{
if ( V_24 != NULL )
{
if ( F_32 ( V_38 , V_24 ) <= 0 )
{
perror ( V_24 ) ;
goto V_71;
}
}
else
F_7 ( V_38 , stdout , V_64 | V_65 ) ;
}
if ( V_7 )
{
if ( ( V_15 == NULL ) && ( ( V_15 = F_13 ( V_73 ,
V_67 , V_107 ) ) == NULL ) )
{
F_14 ( V_67 , V_107 ) ;
goto V_71;
}
if ( ( V_51 = F_33 ( V_15 ) ) == NULL )
{
F_8 ( V_62 , L_53 , V_15 ) ;
goto V_71;
}
if ( V_8 )
F_8 ( V_62 , L_54 ,
F_34 ( V_51 -> type ) ) ;
if ( ( V_16 == NULL ) && ( ( V_16 = F_13 ( V_73 ,
V_67 , V_108 ) ) == NULL ) )
{
F_14 ( V_67 , V_108 ) ;
goto V_71;
}
if ( V_8 )
F_8 ( V_62 , L_55 , V_16 ) ;
if ( ( V_26 = F_13 ( V_73 , V_67 , V_109 ) )
== NULL )
{
F_14 ( V_67 , V_109 ) ;
goto V_71;
}
V_27 = F_13 ( V_73 , V_67 , V_110 ) ;
if( V_27 ) {
T_12 V_111 ;
F_35 ( & V_111 ) ;
F_36 ( & V_111 , V_73 ) ;
if( ! F_37 ( V_73 , & V_111 , V_27 , NULL ) ) {
F_8 ( V_62 ,
L_56 ,
V_27 ) ;
V_6 = 1 ;
goto V_71;
}
}
if ( V_30 == NULL )
{
V_30 = F_13 ( V_73 , V_67 ,
V_112 ) ;
}
if ( V_30 && ! F_38 ( NULL , V_30 ) )
{
F_8 ( V_62 , L_57 ) ;
goto V_71;
}
if ( V_30 == NULL ) V_30 = L_58 ;
if ( V_31 == NULL )
{
V_31 = F_13 ( V_73 , V_67 ,
V_113 ) ;
}
if ( V_31 && ! F_38 ( NULL , V_31 ) )
{
F_8 ( V_62 , L_59 ) ;
goto V_71;
}
if ( V_32 == 0 )
{
V_32 = ( int ) F_39 ( V_73 , V_67 ,
V_114 ) ;
}
if ( ! V_31 && ( V_32 == 0 ) )
{
F_8 ( V_62 , L_60 ) ;
goto V_71;
}
if ( ( V_29 = F_40 ( V_26 ) ) == NULL )
{
F_8 ( V_62 , L_61 ) ;
goto V_71;
}
if ( V_8 )
{
if ( ( V_47 = F_41 ( V_29 ) ) == NULL ) goto V_71;
F_8 ( V_62 , L_62 , V_47 ) ;
Free ( V_47 ) ;
}
if ( ( V_53 = F_42 ( V_73 , V_16 ) ) == NULL )
{
F_8 ( V_62 , L_63 , V_16 ) ;
goto V_71;
}
if ( ( V_54 = F_43 () ) == NULL )
{
F_8 ( V_62 , L_64 ) ;
goto V_71;
}
if ( V_20 != NULL )
{
V_3 ++ ;
V_49 = F_44 ( & V_35 , V_20 , V_22 , V_34 , V_51 , V_53 , V_41 ,
V_29 , V_30 , V_31 , V_32 , V_27 , V_73 ,
V_8 ) ;
if ( V_49 < 0 ) goto V_71;
if ( V_49 > 0 )
{
V_4 ++ ;
F_8 ( V_62 , L_65 ) ;
if ( ! F_45 ( V_29 , 1 ) ) goto V_71;
if ( ! F_46 ( V_54 , ( char * ) V_35 ) )
{
F_8 ( V_62 , L_64 ) ;
goto V_71;
}
if ( V_24 )
{
V_23 = 1 ;
V_33 = 1 ;
}
}
}
if ( V_21 != NULL )
{
V_3 ++ ;
V_49 = F_47 ( & V_35 , V_21 , V_22 , V_34 , V_51 , V_53 ,
V_41 , V_29 , V_30 , V_31 , V_32 , V_33 ,
V_27 , V_73 , V_8 ) ;
if ( V_49 < 0 ) goto V_71;
if ( V_49 > 0 )
{
V_4 ++ ;
F_8 ( V_62 , L_65 ) ;
if ( ! F_45 ( V_29 , 1 ) ) goto V_71;
if ( ! F_46 ( V_54 , ( char * ) V_35 ) )
{
F_8 ( V_62 , L_64 ) ;
goto V_71;
}
}
}
if ( V_19 != NULL )
{
V_3 ++ ;
V_49 = F_48 ( & V_35 , V_19 , V_22 , V_34 , V_51 , V_53 , V_41 ,
V_29 , V_30 , V_31 , V_32 , V_33 ,
V_27 , V_73 , V_8 ) ;
if ( V_49 < 0 ) goto V_71;
if ( V_49 > 0 )
{
V_4 ++ ;
F_8 ( V_62 , L_65 ) ;
if ( ! F_45 ( V_29 , 1 ) ) goto V_71;
if ( ! F_46 ( V_54 , ( char * ) V_35 ) )
{
F_8 ( V_62 , L_64 ) ;
goto V_71;
}
}
}
for ( V_48 = 0 ; V_48 < V_1 ; V_48 ++ )
{
V_3 ++ ;
V_49 = F_48 ( & V_35 , V_2 [ V_48 ] , V_22 , V_34 , V_51 , V_53 , V_41 ,
V_29 , V_30 , V_31 , V_32 , V_33 ,
V_27 , V_73 , V_8 ) ;
if ( V_49 < 0 ) goto V_71;
if ( V_49 > 0 )
{
V_4 ++ ;
F_8 ( V_62 , L_65 ) ;
if ( ! F_45 ( V_29 , 1 ) ) goto V_71;
if ( ! F_46 ( V_54 , ( char * ) V_35 ) )
{
F_8 ( V_62 , L_64 ) ;
goto V_71;
}
}
}
if ( F_27 ( V_54 ) > 0 )
{
if ( ! V_33 )
{
F_8 ( V_62 , L_66 , V_4 , V_3 ) ;
( void ) F_49 ( V_62 ) ;
V_57 [ 0 ] [ 0 ] = '\0' ;
fgets ( V_57 [ 0 ] , 10 , V_115 ) ;
if ( ( V_57 [ 0 ] [ 0 ] != 'y' ) && ( V_57 [ 0 ] [ 0 ] != 'Y' ) )
{
F_8 ( V_62 , L_67 ) ;
V_6 = 0 ;
goto V_71;
}
}
F_8 ( V_62 , L_68 , F_27 ( V_54 ) ) ;
strncpy ( V_57 [ 0 ] , V_26 , V_56 - 4 ) ;
#ifdef F_10
strcat ( V_57 [ 0 ] , L_69 ) ;
#else
strcat ( V_57 [ 0 ] , L_70 ) ;
#endif
if ( ! F_50 ( V_57 [ 0 ] , V_29 ) ) goto V_71;
strncpy ( V_57 [ 1 ] , V_40 , V_56 - 4 ) ;
#ifdef F_10
strcat ( V_57 [ 1 ] , L_69 ) ;
#else
strcat ( V_57 [ 1 ] , L_70 ) ;
#endif
if ( F_32 ( V_37 , V_57 [ 1 ] ) <= 0 )
{
perror ( V_40 ) ;
F_8 ( V_62 , L_43 , V_40 ) ;
goto V_71;
}
V_50 = F_30 ( V_37 , V_41 ) ;
if ( V_50 <= 0 ) goto V_71;
}
if ( V_8 )
F_8 ( V_62 , L_71 ) ;
for ( V_48 = 0 ; V_48 < F_27 ( V_54 ) ; V_48 ++ )
{
int V_116 ;
unsigned char * V_117 ;
V_35 = ( T_3 * ) F_28 ( V_54 , V_48 ) ;
V_49 = V_35 -> V_118 -> V_119 -> V_120 ;
V_46 = ( char * ) V_35 -> V_118 -> V_119 -> V_92 ;
strncpy ( V_57 [ 2 ] , V_25 , V_56 - ( V_49 * 2 ) - 6 ) ;
#ifndef F_10
strcat ( V_57 [ 2 ] , L_28 ) ;
#endif
V_117 = ( unsigned char * ) & ( V_57 [ 2 ] [ strlen ( V_57 [ 2 ] ) ] ) ;
if ( V_49 > 0 )
{
for ( V_116 = 0 ; V_116 < V_49 ; V_116 ++ )
{
sprintf ( ( char * ) V_117 , L_72 , ( unsigned char ) * ( V_46 ++ ) ) ;
V_117 += 2 ;
}
}
else
{
* ( V_117 ++ ) = '0' ;
* ( V_117 ++ ) = '0' ;
}
* ( V_117 ++ ) = '.' ; * ( V_117 ++ ) = 'p' ; * ( V_117 ++ ) = 'e' ; * ( V_117 ++ ) = 'm' ;
* V_117 = '\0' ;
if ( V_8 )
F_8 ( V_62 , L_73 , V_57 [ 2 ] ) ;
if ( F_32 ( V_39 , V_57 [ 2 ] ) <= 0 )
{
perror ( V_57 [ 2 ] ) ;
goto V_71;
}
F_51 ( V_39 , V_35 , 0 ) ;
F_51 ( V_38 , V_35 , V_23 ) ;
}
if ( F_27 ( V_54 ) )
{
strncpy ( V_57 [ 2 ] , V_26 , V_56 - 4 ) ;
#ifdef F_10
strcat ( V_57 [ 2 ] , L_74 ) ;
#else
strcat ( V_57 [ 2 ] , L_75 ) ;
#endif
F_18 ( V_36 ) ;
F_18 ( V_37 ) ;
V_36 = NULL ;
V_37 = NULL ;
if ( rename ( V_26 , V_57 [ 2 ] ) < 0 )
{
F_8 ( V_62 , L_76 ,
V_26 , V_57 [ 2 ] ) ;
perror ( L_77 ) ;
goto V_71;
}
if ( rename ( V_57 [ 0 ] , V_26 ) < 0 )
{
F_8 ( V_62 , L_76 ,
V_57 [ 0 ] , V_26 ) ;
perror ( L_77 ) ;
rename ( V_57 [ 2 ] , V_26 ) ;
goto V_71;
}
strncpy ( V_57 [ 2 ] , V_40 , V_56 - 4 ) ;
#ifdef F_10
strcat ( V_57 [ 2 ] , L_74 ) ;
#else
strcat ( V_57 [ 2 ] , L_75 ) ;
#endif
if ( rename ( V_40 , V_57 [ 2 ] ) < 0 )
{
F_8 ( V_62 , L_76 ,
V_40 , V_57 [ 2 ] ) ;
perror ( L_77 ) ;
goto V_71;
}
if ( rename ( V_57 [ 1 ] , V_40 ) < 0 )
{
F_8 ( V_62 , L_76 ,
V_57 [ 1 ] , V_40 ) ;
perror ( L_77 ) ;
rename ( V_57 [ 2 ] , V_40 ) ;
goto V_71;
}
F_8 ( V_62 , L_78 ) ;
}
}
if ( V_9 )
{
V_28 = F_13 ( V_73 , V_67 , V_121 ) ;
if( V_28 ) {
T_12 V_111 ;
F_35 ( & V_111 ) ;
F_36 ( & V_111 , V_73 ) ;
if( ! F_37 ( V_73 , & V_111 , V_28 , NULL ) ) {
F_8 ( V_62 ,
L_79 ,
V_28 ) ;
V_6 = 1 ;
goto V_71;
}
}
if ( ( V_55 = F_5 ( F_52 () ) ) == NULL ) goto V_71;
if ( ! V_11 && ! V_12 )
{
V_11 = F_39 ( V_73 , V_67 ,
V_122 ) ;
V_12 = F_39 ( V_73 , V_67 ,
V_123 ) ;
}
if ( ( V_11 == 0 ) && ( V_12 == 0 ) )
{
F_8 ( V_62 , L_80 ) ;
goto V_71;
}
if ( V_8 ) F_8 ( V_62 , L_81 ) ;
if ( ( V_42 = F_53 () ) == NULL ) goto V_71;
V_43 = V_42 -> V_42 ;
F_54 ( V_43 -> V_124 ) ;
V_43 -> V_124 = F_55 ( V_34 -> V_118 -> V_125 ) ;
if ( V_43 -> V_124 == NULL ) goto V_71;
F_56 ( V_43 -> V_126 , 0 ) ;
if ( V_43 -> V_127 == NULL )
V_43 -> V_127 = F_57 () ;
F_56 ( V_43 -> V_127 , ( V_11 * 24 + V_12 ) * 60 * 60 ) ;
for ( V_48 = 0 ; V_48 < F_27 ( V_41 -> V_92 ) ; V_48 ++ )
{
V_45 = ( char * * ) F_28 ( V_41 -> V_92 , V_48 ) ;
if ( V_45 [ V_93 ] [ 0 ] == V_94 )
{
if ( ( V_44 = F_58 () ) == NULL ) goto V_71;
F_59 ( ( V_128 * )
V_44 -> V_129 ,
( unsigned char * ) V_45 [ V_95 ] ,
strlen ( V_45 [ V_95 ] ) ) ;
( void ) F_60 ( V_55 ) ;
if ( ! F_61 ( V_55 , V_45 [ V_97 ] ) )
goto V_71;
if ( ! F_62 ( V_55 , V_44 -> V_119 ,
V_57 [ 0 ] , V_56 ) ) goto V_71;
F_63 ( V_43 -> V_130 , V_44 ) ;
}
}
F_64 ( V_43 -> V_130 ) ;
for ( V_48 = 0 ; V_48 < F_65 ( V_43 -> V_130 ) ; V_48 ++ )
{
V_44 = F_66 ( V_43 -> V_130 , V_48 ) ;
V_44 -> V_131 = V_48 ;
}
if ( V_8 ) F_8 ( V_62 , L_82 ) ;
if ( V_15 != NULL )
{
if ( ( V_51 = F_33 ( V_15 ) ) == NULL )
{
F_8 ( V_62 , L_53 , V_15 ) ;
goto V_71;
}
}
else
{
#ifndef F_67
if ( V_22 -> type == V_132 )
V_51 = F_68 () ;
else
#endif
V_51 = F_69 () ;
}
if( V_28 ) {
T_12 V_133 ;
if ( V_43 -> V_134 == NULL )
if ( ( V_43 -> V_134 = F_70 () ) == NULL ) goto V_71;
F_71 ( V_43 -> V_134 , 1 ) ;
F_72 ( & V_133 , V_34 , NULL , NULL , V_42 , 0 ) ;
F_36 ( & V_133 , V_73 ) ;
if( ! F_73 ( V_73 , & V_133 ,
V_28 , V_42 ) ) goto V_71;
}
if ( ! F_74 ( V_42 , V_22 , V_51 ) ) goto V_71;
F_75 ( V_38 , V_42 ) ;
}
if ( V_10 )
{
V_36 = F_5 ( F_6 () ) ;
V_37 = F_5 ( F_6 () ) ;
if ( ( V_36 == NULL ) || ( V_37 == NULL ) )
{
F_20 ( V_62 ) ;
goto V_71;
}
if ( V_19 == NULL )
{
F_8 ( V_62 , L_83 ) ;
goto V_71;
}
else
{
if ( F_21 ( V_36 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
F_8 ( V_62 , L_84 , V_19 ) ;
goto V_71;
}
V_34 = F_23 ( V_36 , NULL , NULL , NULL ) ;
if ( V_34 == NULL )
{
F_8 ( V_62 , L_85 , V_19 ) ;
goto V_71;
}
V_49 = F_76 ( V_34 , V_41 ) ;
strncpy ( V_57 [ 0 ] , V_40 , V_56 - 4 ) ;
strcat ( V_57 [ 0 ] , L_70 ) ;
if ( F_32 ( V_37 , V_57 [ 0 ] ) <= 0 )
{
perror ( V_40 ) ;
F_8 ( V_62 , L_43 , V_40 ) ;
goto V_71;
}
V_49 = F_30 ( V_37 , V_41 ) ;
if ( V_49 <= 0 ) goto V_71;
F_18 ( V_36 ) ;
F_18 ( V_37 ) ;
V_36 = NULL ;
V_37 = NULL ;
strncpy ( V_57 [ 1 ] , V_40 , V_56 - 4 ) ;
strcat ( V_57 [ 1 ] , L_75 ) ;
if ( rename ( V_40 , V_57 [ 1 ] ) < 0 )
{
F_8 ( V_62 , L_86 , V_40 , V_57 [ 1 ] ) ;
perror ( L_77 ) ;
goto V_71;
}
if ( rename ( V_57 [ 0 ] , V_40 ) < 0 )
{
F_8 ( V_62 , L_86 , V_57 [ 0 ] , V_40 ) ;
perror ( L_77 ) ;
rename ( V_57 [ 1 ] , V_40 ) ;
goto V_71;
}
F_8 ( V_62 , L_78 ) ;
}
}
V_6 = 0 ;
V_71:
F_18 ( V_55 ) ;
F_18 ( V_39 ) ;
F_18 ( V_38 ) ;
F_18 ( V_37 ) ;
F_18 ( V_36 ) ;
F_77 ( V_54 , V_135 ) ;
if ( V_6 ) F_20 ( V_62 ) ;
F_78 ( V_29 ) ;
F_79 ( V_41 ) ;
F_80 ( V_22 ) ;
V_135 ( V_34 ) ;
F_81 ( V_42 ) ;
F_82 ( V_73 ) ;
F_83 () ;
F_84 () ;
EXIT ( V_6 ) ;
}
static void F_14 ( char * V_136 , char * V_137 )
{
F_8 ( V_62 , L_87 , V_136 , V_137 ) ;
}
static int T_13 V_78 ( char * V_57 , int V_138 , int V_139 , void * V_140 )
{
int V_48 ;
if ( V_68 == NULL ) return ( 0 ) ;
V_48 = strlen ( V_68 ) ;
V_48 = ( V_48 > V_138 ) ? V_138 : V_48 ;
memcpy ( V_57 , V_68 , V_48 ) ;
return ( V_48 ) ;
}
static unsigned long V_99 ( char * * V_141 )
{
char * V_117 ;
V_117 = V_141 [ V_97 ] ;
while ( * V_117 == '0' ) V_117 ++ ;
return ( F_85 ( V_117 ) ) ;
}
static int V_100 ( char * * V_141 , char * * V_142 )
{
char * V_143 , * V_144 ;
for ( V_143 = V_141 [ V_97 ] ; * V_143 == '0' ; V_143 ++ ) ;
for ( V_144 = V_142 [ V_97 ] ; * V_144 == '0' ; V_144 ++ ) ;
return ( strcmp ( V_143 , V_144 ) ) ;
}
static unsigned long V_105 ( char * * V_141 )
{ return ( F_85 ( V_141 [ V_103 ] ) ) ; }
static int V_104 ( char * * V_141 )
{ return ( V_141 [ 0 ] [ 0 ] == 'V' ) ; }
static int V_106 ( char * * V_141 , char * * V_142 )
{ return ( strcmp ( V_141 [ V_103 ] ,
V_142 [ V_103 ] ) ) ; }
static T_2 * F_40 ( char * V_26 )
{
T_4 * V_36 = NULL ;
T_2 * V_6 = NULL ;
T_11 char V_57 [ 1024 ] ;
T_14 * V_145 = NULL ;
if ( ( V_36 = F_5 ( F_6 () ) ) == NULL )
{
F_20 ( V_62 ) ;
goto V_71;
}
if ( F_21 ( V_36 , V_26 ) <= 0 )
{
perror ( V_26 ) ;
goto V_71;
}
V_145 = F_70 () ;
if ( V_145 == NULL ) goto V_71;
if ( ! F_62 ( V_36 , V_145 , V_57 , 1024 ) )
{
F_8 ( V_62 , L_88 ,
V_26 ) ;
goto V_71;
}
V_6 = F_86 ( V_145 , NULL ) ;
if ( V_6 == NULL )
{
F_8 ( V_62 , L_89 ) ;
goto V_71;
}
V_71:
if ( V_36 != NULL ) F_18 ( V_36 ) ;
if ( V_145 != NULL ) F_87 ( V_145 ) ;
return ( V_6 ) ;
}
static int F_50 ( char * V_26 , T_2 * V_29 )
{
T_4 * V_37 ;
int V_6 = 0 ;
T_14 * V_145 = NULL ;
V_37 = F_5 ( F_6 () ) ;
if ( V_37 == NULL )
{
F_20 ( V_62 ) ;
goto V_71;
}
if ( F_32 ( V_37 , V_26 ) <= 0 )
{
perror ( V_26 ) ;
goto V_71;
}
if ( ( V_145 = F_88 ( V_29 , NULL ) ) == NULL )
{
F_8 ( V_62 , L_90 ) ;
goto V_71;
}
F_89 ( V_37 , V_145 ) ;
F_61 ( V_37 , L_65 ) ;
V_6 = 1 ;
V_71:
if ( V_37 != NULL ) F_18 ( V_37 ) ;
if ( V_145 != NULL ) F_87 ( V_145 ) ;
return ( V_6 ) ;
}
static void F_51 ( T_4 * V_146 , T_3 * V_35 , int V_23 )
{
char * V_47 ;
char V_57 [ 256 ] ;
if ( V_23 )
{
( void ) F_90 ( V_146 , V_35 ) ;
return;
}
V_47 = F_91 ( F_92 ( V_35 ) , V_57 , 256 ) ;
F_8 ( V_146 , L_91 , V_47 ) ;
V_47 = F_91 ( F_93 ( V_35 ) , V_57 , 256 ) ;
F_8 ( V_146 , L_92 , V_47 ) ;
F_61 ( V_146 , L_93 ) ;
F_89 ( V_146 , V_35 -> V_118 -> V_119 ) ;
F_61 ( V_146 , L_94 ) ;
F_94 ( V_146 , V_35 ) ;
F_61 ( V_146 , L_65 ) ;
F_95 ( V_146 , V_35 ) ;
F_61 ( V_146 , L_65 ) ;
}
static int F_96 ( int V_147 , int * type )
{
if ( V_147 == V_148 )
* type = V_149 ;
if ( ( V_147 == V_150 ) && ( * type == V_149 ) )
* type = V_151 ;
if ( ( V_147 == V_152 ) && ( * type == V_149 ) )
* type = V_151 ;
if ( ( V_147 == V_153 ) && ( * type == V_151 ) )
return ( 0 ) ;
if ( V_147 == V_153 )
* type = V_149 ;
return ( 1 ) ;
}
static int F_29 ( char * V_154 )
{
T_15 V_155 ;
V_155 . V_92 = ( unsigned char * ) V_154 ;
V_155 . V_120 = strlen ( V_154 ) ;
V_155 . type = V_156 ;
return ( F_97 ( & V_155 ) ) ;
}
static int F_19 ( T_16 * V_157 )
{
char * V_46 ;
F_1 ( V_52 ) * V_158 ;
V_52 * V_159 ;
int V_48 ;
if( ! ( V_46 = F_13 ( V_157 , NULL , L_95 ) ) ) return 1 ;
if( ! ( V_158 = F_42 ( V_157 , V_46 ) ) ) {
F_8 ( V_62 , L_96 , V_46 ) ;
return 0 ;
}
for( V_48 = 0 ; V_48 < F_98 ( V_158 ) ; V_48 ++ ) {
V_159 = F_99 ( V_158 , V_48 ) ;
if( F_100 ( V_159 -> V_160 , V_159 -> V_136 , V_159 -> V_136 ) == V_161 ) {
F_8 ( V_62 , L_97 ,
V_159 -> V_136 , V_159 -> V_160 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_76 ( T_3 * V_34 , T_5 * V_41 )
{
T_15 * V_155 = NULL ;
char * V_162 [ V_91 ] , * * V_163 , * * V_164 ;
int V_165 = - 1 , V_48 ;
for ( V_48 = 0 ; V_48 < V_91 ; V_48 ++ )
V_162 [ V_48 ] = NULL ;
V_162 [ V_103 ] = F_91 ( V_34 -> V_118 -> V_125 , NULL , 0 ) ;
V_162 [ V_97 ] = F_41 ( F_86 ( V_34 -> V_118 -> V_119 , NULL ) ) ;
if ( ( V_162 [ V_103 ] == NULL ) || ( V_162 [ V_97 ] == NULL ) )
{
F_8 ( V_62 , L_64 ) ;
goto V_71;
}
V_163 = F_101 ( V_41 , V_103 , V_162 ) ;
if ( V_163 == NULL )
{
F_8 ( V_62 , L_98 , V_162 [ V_103 ] ) ;
V_162 [ V_93 ] = ( char * ) Malloc ( 2 ) ;
V_155 = F_102 ( V_34 ) ;
V_162 [ V_96 ] = ( char * ) Malloc ( V_155 -> V_120 + 1 ) ;
memcpy ( V_162 [ V_96 ] , V_155 -> V_92 , V_155 -> V_120 ) ;
V_162 [ V_96 ] [ V_155 -> V_120 ] = '\0' ;
V_162 [ V_95 ] = NULL ;
V_162 [ V_166 ] = ( char * ) Malloc ( 8 ) ;
if ( ( V_162 [ V_93 ] == NULL ) || ( V_162 [ V_96 ] == NULL ) ||
( V_162 [ V_166 ] == NULL ) )
{
F_8 ( V_62 , L_64 ) ;
goto V_71;
}
strcpy ( V_162 [ V_166 ] , L_99 ) ;
V_162 [ V_93 ] [ 0 ] = 'V' ;
V_162 [ V_93 ] [ 1 ] = '\0' ;
if ( ( V_164 = ( char * * ) Malloc ( sizeof( char * ) * ( V_91 + 1 ) ) ) == NULL )
{
F_8 ( V_62 , L_64 ) ;
goto V_71;
}
for ( V_48 = 0 ; V_48 < V_91 ; V_48 ++ )
{
V_164 [ V_48 ] = V_162 [ V_48 ] ;
V_162 [ V_48 ] = NULL ;
}
V_164 [ V_91 ] = NULL ;
if ( ! F_103 ( V_41 , V_164 ) )
{
F_8 ( V_62 , L_100 ) ;
F_8 ( V_62 , L_101 , V_41 -> error ) ;
goto V_71;
}
F_76 ( V_34 , V_41 ) ;
V_165 = 1 ;
goto V_71;
}
else if ( V_100 ( V_162 , V_163 ) )
{
F_8 ( V_62 , L_102 ,
V_162 [ V_97 ] ) ;
goto V_71;
}
else if ( V_163 [ V_93 ] [ 0 ] == 'R' )
{
F_8 ( V_62 , L_103 ,
V_162 [ V_97 ] ) ;
goto V_71;
}
else
{
F_8 ( V_62 , L_104 , V_163 [ V_97 ] ) ;
V_155 = F_56 ( V_155 , 0 ) ;
V_163 [ V_93 ] [ 0 ] = 'R' ;
V_163 [ V_93 ] [ 1 ] = '\0' ;
V_163 [ V_95 ] = ( char * ) Malloc ( V_155 -> V_120 + 1 ) ;
memcpy ( V_163 [ V_95 ] , V_155 -> V_92 , V_155 -> V_120 ) ;
V_163 [ V_95 ] [ V_155 -> V_120 ] = '\0' ;
}
V_165 = 1 ;
V_71:
for ( V_48 = 0 ; V_48 < V_91 ; V_48 ++ )
{
if ( V_162 [ V_48 ] != NULL )
Free ( V_162 [ V_48 ] ) ;
}
F_104 ( V_155 ) ;
return ( V_165 ) ;
}
