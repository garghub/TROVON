int MAIN ( int V_1 , char * * V_2 )
{
char * V_3 = NULL ;
int V_4 = 0 ;
int V_5 = 0 ;
int V_6 = 0 ;
int V_7 = 1 ;
int V_8 = 0 ;
int V_9 = 0 ;
int V_10 = 0 ;
int V_11 = 0 ;
long V_12 = 0 ;
long V_13 = 0 ;
long V_14 = - 1 ;
char * V_15 = NULL ;
char * V_16 = NULL ;
char * V_17 = NULL ;
char * V_18 = NULL ;
char * V_19 = NULL ;
char * V_20 = NULL ;
char * V_21 = NULL ;
char * V_22 = NULL ;
T_1 * V_23 = NULL ;
int V_24 = 0 ;
char * V_25 = NULL ;
char * V_26 = NULL ;
char * V_27 = NULL ;
char * V_28 = NULL ;
char * V_29 = NULL ;
T_2 * V_30 = NULL ;
char * V_31 = NULL ;
char * V_32 = NULL ;
int V_33 = 0 ;
int V_34 = 0 ;
int V_35 = 0 ;
T_3 * V_36 = NULL ;
T_3 * V_37 = NULL ;
T_4 * V_38 = NULL , * V_39 = NULL , * V_40 = NULL , * V_41 = NULL ;
char * V_42 = NULL ;
T_5 * V_43 = NULL ;
T_6 * V_44 = NULL ;
T_7 * V_45 = NULL ;
T_8 * V_46 = NULL ;
char * * V_47 , * V_48 , * V_49 ;
int V_50 , V_51 ;
long V_52 ;
const T_9 * V_53 = NULL ;
F_1 ( V_54 ) * V_55 = NULL ;
T_10 * V_56 = NULL ;
T_4 * V_57 = NULL ;
#undef V_58
#define V_58 256
T_11 char V_59 [ 3 ] [ V_58 ] ;
char * V_60 = NULL ;
#ifdef F_2
V_61 = 1 ;
V_62 = 1 ;
V_63 = 0 ;
#endif
F_3 () ;
V_64 = NULL ;
V_3 = NULL ;
V_65 = NULL ;
V_66 = 0 ;
V_67 = 0 ;
if ( V_68 == NULL )
if ( ( V_68 = F_4 ( F_5 () ) ) != NULL )
F_6 ( V_68 , V_69 , V_70 | V_71 ) ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
V_9 = 1 ;
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_65 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_31 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_32 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_33 = atoi ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_3 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_20 = * ( ++ V_2 ) ;
V_8 = 1 ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_25 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_26 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
V_35 = 1 ;
else if ( strcmp ( * V_2 , L_16 ) == 0 )
V_34 = 1 ;
else if ( strcmp ( * V_2 , L_17 ) == 0 )
V_66 = 1 ;
else if ( strcmp ( * V_2 , L_18 ) == 0 )
V_10 = 1 ;
else if ( strcmp ( * V_2 , L_19 ) == 0 )
V_67 = 1 ;
else if ( strcmp ( * V_2 , L_20 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_12 = atol ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_21 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_13 = atol ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_22 ) == 0 )
{
V_1 -- ;
V_2 ++ ;
V_8 = 1 ;
break;
}
else if ( strcmp ( * V_2 , L_23 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_22 = * ( ++ V_2 ) ;
V_8 = 1 ;
}
else if ( strcmp ( * V_2 , L_24 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_21 = * ( ++ V_2 ) ;
V_8 = 1 ;
}
else if ( strcmp ( * V_2 , L_25 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_20 = * ( ++ V_2 ) ;
V_11 = 1 ;
}
else if ( strcmp ( * V_2 , L_26 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_28 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_27 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_72;
V_29 = * ( ++ V_2 ) ;
}
else
{
V_72:
F_7 ( V_68 , L_28 , * V_2 ) ;
V_6 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_6 )
{
for ( V_47 = V_73 ; ( * V_47 != NULL ) ; V_47 ++ )
F_7 ( V_68 , * V_47 ) ;
goto V_74;
}
F_8 () ;
if ( V_15 == NULL ) V_15 = getenv ( L_29 ) ;
if ( V_15 == NULL ) V_15 = getenv ( L_30 ) ;
if ( V_15 == NULL )
{
#ifdef F_9
strncpy ( V_59 [ 0 ] , F_10 () ,
sizeof( V_59 [ 0 ] ) - 1 - sizeof( V_75 ) ) ;
#else
strncpy ( V_59 [ 0 ] , F_10 () ,
sizeof( V_59 [ 0 ] ) - 2 - sizeof( V_75 ) ) ;
strcat ( V_59 [ 0 ] , L_31 ) ;
#endif
strcat ( V_59 [ 0 ] , V_75 ) ;
V_15 = V_59 [ 0 ] ;
}
F_7 ( V_68 , L_32 , V_15 ) ;
if ( ( V_64 = F_11 ( NULL , V_15 , & V_14 ) ) == NULL )
{
if ( V_14 <= 0 )
F_7 ( V_68 , L_33 ,
V_15 ) ;
else
F_7 ( V_68 , L_34
, V_14 , V_15 ) ;
goto V_74;
}
if ( V_65 == NULL )
{
V_65 = F_12 ( V_64 , V_76 , V_77 ) ;
if ( V_65 == NULL )
{
F_13 ( V_76 , V_77 ) ;
goto V_74;
}
}
if ( V_64 != NULL )
{
V_48 = F_12 ( V_64 , NULL , L_35 ) ;
if ( V_48 != NULL )
{
T_4 * V_78 ;
V_78 = F_14 ( V_48 , L_36 ) ;
if ( V_78 == NULL )
{
F_15 () ;
}
else
{
F_16 ( V_78 ) ;
F_17 ( V_78 ) ;
}
}
if( ! F_18 ( V_64 ) )
{
F_19 ( V_68 ) ;
goto V_74;
}
}
V_60 = F_12 ( V_64 , V_76 , L_37 ) ;
F_20 ( V_60 , V_68 , 0 ) ;
V_38 = F_4 ( F_5 () ) ;
V_39 = F_4 ( F_5 () ) ;
V_40 = F_4 ( F_5 () ) ;
V_41 = F_4 ( F_5 () ) ;
if ( ( V_38 == NULL ) || ( V_39 == NULL ) || ( V_40 == NULL ) || ( V_41 == NULL ) )
{
F_19 ( V_68 ) ;
goto V_74;
}
if ( ( V_18 == NULL ) && ( ( V_18 = F_12 ( V_64 ,
V_65 , V_79 ) ) == NULL ) )
{
F_13 ( V_65 , V_79 ) ;
goto V_74;
}
if ( F_21 ( V_38 , V_18 ) <= 0 )
{
perror ( V_18 ) ;
F_7 ( V_68 , L_38 ) ;
goto V_74;
}
V_23 = F_22 ( V_38 , NULL , NULL , V_3 ) ;
if( V_3 ) memset ( V_3 , 0 , strlen ( V_3 ) ) ;
if ( V_23 == NULL )
{
F_7 ( V_68 , L_39 ) ;
goto V_74;
}
if ( ( V_19 == NULL ) && ( ( V_19 = F_12 ( V_64 ,
V_65 , V_80 ) ) == NULL ) )
{
F_13 ( V_65 , V_80 ) ;
goto V_74;
}
if ( F_21 ( V_38 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
F_7 ( V_68 , L_40 ) ;
goto V_74;
}
V_36 = F_23 ( V_38 , NULL , NULL , NULL ) ;
if ( V_36 == NULL )
{
F_7 ( V_68 , L_41 ) ;
goto V_74;
}
if ( ! F_24 ( V_36 , V_23 ) )
{
F_7 ( V_68 , L_42 ) ;
goto V_74;
}
V_49 = F_12 ( V_64 , V_76 , V_81 ) ;
if ( ( V_49 != NULL ) && ( ( * V_49 == 'y' ) || ( * V_49 == 'Y' ) ) )
V_66 = 1 ;
V_49 = F_12 ( V_64 , V_76 , V_82 ) ;
if ( ( V_49 != NULL ) && ( ( * V_49 == 'y' ) || ( * V_49 == 'Y' ) ) )
V_67 = 1 ;
if ( ( V_26 == NULL ) && ( V_8 ) )
{
struct V_83 V_84 ;
if ( ( V_26 = F_12 ( V_64 , V_65 , V_85 ) )
== NULL )
{
F_7 ( V_68 , L_43 ) ;
goto V_74;
}
#ifndef F_9
if ( F_25 ( V_26 , V_86 | V_87 | V_88 ) != 0 )
{
F_7 ( V_68 , L_44 , V_26 ) ;
perror ( V_26 ) ;
goto V_74;
}
if ( V_83 ( V_26 , & V_84 ) != 0 )
{
F_7 ( V_68 , L_45 , V_26 ) ;
perror ( V_26 ) ;
goto V_74;
}
#ifdef F_26
if ( ! ( V_84 . V_89 & F_26 ) )
{
F_7 ( V_68 , L_46 , V_26 ) ;
perror ( V_26 ) ;
goto V_74;
}
#endif
#endif
}
if ( ( V_42 = F_12 ( V_64 , V_65 , V_90 ) ) == NULL )
{
F_13 ( V_65 , V_90 ) ;
goto V_74;
}
if ( F_21 ( V_38 , V_42 ) <= 0 )
{
perror ( V_42 ) ;
F_7 ( V_68 , L_47 , V_42 ) ;
goto V_74;
}
V_43 = F_27 ( V_38 , V_91 ) ;
if ( V_43 == NULL ) goto V_74;
for ( V_50 = 0 ; V_50 < F_28 ( V_43 -> V_92 ) ; V_50 ++ )
{
V_47 = ( char * * ) F_29 ( V_43 -> V_92 , V_50 ) ;
if ( ( V_47 [ V_93 ] [ 0 ] != V_94 ) &&
( V_47 [ V_95 ] [ 0 ] != '\0' ) )
{
F_7 ( V_68 , L_48 , V_50 + 1 ) ;
goto V_74;
}
if ( ( V_47 [ V_93 ] [ 0 ] == V_94 ) &&
! F_30 ( V_47 [ V_95 ] ) )
{
F_7 ( V_68 , L_49 ,
V_50 + 1 ) ;
goto V_74;
}
if ( ! F_30 ( V_47 [ V_96 ] ) )
{
F_7 ( V_68 , L_50 , V_50 + 1 ) ;
goto V_74;
}
V_48 = V_47 [ V_97 ] ;
V_51 = strlen ( V_48 ) ;
if ( ( V_51 & 1 ) || ( V_51 < 2 ) )
{
F_7 ( V_68 , L_51 , V_50 + 1 , V_51 ) ;
goto V_74;
}
while ( * V_48 )
{
if ( ! ( ( ( * V_48 >= '0' ) && ( * V_48 <= '9' ) ) ||
( ( * V_48 >= 'A' ) && ( * V_48 <= 'F' ) ) ||
( ( * V_48 >= 'a' ) && ( * V_48 <= 'f' ) ) ) )
{
F_7 ( V_68 , L_52 , V_50 + 1 , ( long ) ( V_48 - V_47 [ V_97 ] ) , * V_48 ) ;
goto V_74;
}
V_48 ++ ;
}
}
if ( V_9 )
{
F_6 ( V_39 , stdout , V_70 | V_71 ) ;
F_31 ( V_39 , V_43 ) ;
F_7 ( V_68 , L_53 ,
V_43 -> V_92 -> V_98 ) ;
F_7 ( V_68 , L_54 ) ;
}
if ( ! F_32 ( V_43 , V_97 , NULL , V_99 ,
V_100 ) )
{
F_7 ( V_68 , L_55 , V_43 -> error , V_43 -> V_101 , V_43 -> V_102 ) ;
goto V_74;
}
if ( ! F_32 ( V_43 , V_103 , V_104 , V_105 ,
V_106 ) )
{
F_7 ( V_68 , L_56 ,
V_43 -> error , V_43 -> V_101 , V_43 -> V_102 ) ;
goto V_74;
}
if ( V_8 || V_10 )
{
if ( V_25 != NULL )
{
if ( F_33 ( V_40 , V_25 ) <= 0 )
{
perror ( V_25 ) ;
goto V_74;
}
}
else
F_6 ( V_40 , stdout , V_70 | V_71 ) ;
}
if ( V_8 )
{
if ( ( V_16 == NULL ) && ( ( V_16 = F_12 ( V_64 ,
V_65 , V_107 ) ) == NULL ) )
{
F_13 ( V_65 , V_107 ) ;
goto V_74;
}
if ( ( V_53 = F_34 ( V_16 ) ) == NULL )
{
F_7 ( V_68 , L_57 , V_16 ) ;
goto V_74;
}
if ( V_9 )
F_7 ( V_68 , L_58 ,
F_35 ( V_53 -> type ) ) ;
if ( ( V_17 == NULL ) && ( ( V_17 = F_12 ( V_64 ,
V_65 , V_108 ) ) == NULL ) )
{
F_13 ( V_65 , V_108 ) ;
goto V_74;
}
if ( V_9 )
F_7 ( V_68 , L_59 , V_17 ) ;
if ( ( V_27 = F_12 ( V_64 , V_65 , V_109 ) )
== NULL )
{
F_13 ( V_65 , V_109 ) ;
goto V_74;
}
if( ! V_28 )
V_28 = F_12 ( V_64 , V_65 , V_110 ) ;
if( V_28 ) {
T_12 V_111 ;
F_36 ( & V_111 ) ;
F_37 ( & V_111 , V_64 ) ;
if( ! F_38 ( V_64 , & V_111 , V_28 , NULL ) ) {
F_7 ( V_68 ,
L_60 ,
V_28 ) ;
V_7 = 1 ;
goto V_74;
}
}
if ( V_31 == NULL )
{
V_31 = F_12 ( V_64 , V_65 ,
V_112 ) ;
}
if ( V_31 && ! F_39 ( NULL , V_31 ) )
{
F_7 ( V_68 , L_61 ) ;
goto V_74;
}
if ( V_31 == NULL ) V_31 = L_62 ;
if ( V_32 == NULL )
{
V_32 = F_12 ( V_64 , V_65 ,
V_113 ) ;
}
if ( V_32 && ! F_39 ( NULL , V_32 ) )
{
F_7 ( V_68 , L_63 ) ;
goto V_74;
}
if ( V_33 == 0 )
{
V_33 = ( int ) F_40 ( V_64 , V_65 ,
V_114 ) ;
}
if ( ! V_32 && ( V_33 == 0 ) )
{
F_7 ( V_68 , L_64 ) ;
goto V_74;
}
if ( ( V_30 = F_41 ( V_27 ) ) == NULL )
{
F_7 ( V_68 , L_65 ) ;
goto V_74;
}
if ( V_9 )
{
if ( ( V_49 = F_42 ( V_30 ) ) == NULL ) goto V_74;
F_7 ( V_68 , L_66 , V_49 ) ;
Free ( V_49 ) ;
}
if ( ( V_55 = F_43 ( V_64 , V_17 ) ) == NULL )
{
F_7 ( V_68 , L_67 , V_17 ) ;
goto V_74;
}
if ( ( V_56 = F_44 () ) == NULL )
{
F_7 ( V_68 , L_68 ) ;
goto V_74;
}
if ( V_21 != NULL )
{
V_4 ++ ;
V_51 = F_45 ( & V_37 , V_21 , V_23 , V_36 , V_53 , V_55 , V_43 ,
V_30 , V_31 , V_32 , V_33 , V_28 , V_64 ,
V_9 ) ;
if ( V_51 < 0 ) goto V_74;
if ( V_51 > 0 )
{
V_5 ++ ;
F_7 ( V_68 , L_69 ) ;
if ( ! F_46 ( V_30 , 1 ) ) goto V_74;
if ( ! F_47 ( V_56 , ( char * ) V_37 ) )
{
F_7 ( V_68 , L_68 ) ;
goto V_74;
}
if ( V_25 )
{
V_24 = 1 ;
V_34 = 1 ;
}
}
}
if ( V_22 != NULL )
{
V_4 ++ ;
V_51 = F_48 ( & V_37 , V_22 , V_23 , V_36 , V_53 , V_55 ,
V_43 , V_30 , V_31 , V_32 , V_33 , V_34 ,
V_28 , V_64 , V_9 ) ;
if ( V_51 < 0 ) goto V_74;
if ( V_51 > 0 )
{
V_5 ++ ;
F_7 ( V_68 , L_69 ) ;
if ( ! F_46 ( V_30 , 1 ) ) goto V_74;
if ( ! F_47 ( V_56 , ( char * ) V_37 ) )
{
F_7 ( V_68 , L_68 ) ;
goto V_74;
}
}
}
if ( V_20 != NULL )
{
V_4 ++ ;
V_51 = F_49 ( & V_37 , V_20 , V_23 , V_36 , V_53 , V_55 , V_43 ,
V_30 , V_31 , V_32 , V_33 , V_34 ,
V_28 , V_64 , V_9 ) ;
if ( V_51 < 0 ) goto V_74;
if ( V_51 > 0 )
{
V_5 ++ ;
F_7 ( V_68 , L_69 ) ;
if ( ! F_46 ( V_30 , 1 ) ) goto V_74;
if ( ! F_47 ( V_56 , ( char * ) V_37 ) )
{
F_7 ( V_68 , L_68 ) ;
goto V_74;
}
}
}
for ( V_50 = 0 ; V_50 < V_1 ; V_50 ++ )
{
V_4 ++ ;
V_51 = F_49 ( & V_37 , V_2 [ V_50 ] , V_23 , V_36 , V_53 , V_55 , V_43 ,
V_30 , V_31 , V_32 , V_33 , V_34 ,
V_28 , V_64 , V_9 ) ;
if ( V_51 < 0 ) goto V_74;
if ( V_51 > 0 )
{
V_5 ++ ;
F_7 ( V_68 , L_69 ) ;
if ( ! F_46 ( V_30 , 1 ) ) goto V_74;
if ( ! F_47 ( V_56 , ( char * ) V_37 ) )
{
F_7 ( V_68 , L_68 ) ;
goto V_74;
}
}
}
if ( F_28 ( V_56 ) > 0 )
{
if ( ! V_34 )
{
F_7 ( V_68 , L_70 , V_5 , V_4 ) ;
( void ) F_50 ( V_68 ) ;
V_59 [ 0 ] [ 0 ] = '\0' ;
fgets ( V_59 [ 0 ] , 10 , V_115 ) ;
if ( ( V_59 [ 0 ] [ 0 ] != 'y' ) && ( V_59 [ 0 ] [ 0 ] != 'Y' ) )
{
F_7 ( V_68 , L_71 ) ;
V_7 = 0 ;
goto V_74;
}
}
F_7 ( V_68 , L_72 , F_28 ( V_56 ) ) ;
strncpy ( V_59 [ 0 ] , V_27 , V_58 - 4 ) ;
#ifdef F_9
strcat ( V_59 [ 0 ] , L_73 ) ;
#else
strcat ( V_59 [ 0 ] , L_74 ) ;
#endif
if ( ! F_51 ( V_59 [ 0 ] , V_30 ) ) goto V_74;
strncpy ( V_59 [ 1 ] , V_42 , V_58 - 4 ) ;
#ifdef F_9
strcat ( V_59 [ 1 ] , L_73 ) ;
#else
strcat ( V_59 [ 1 ] , L_74 ) ;
#endif
if ( F_33 ( V_39 , V_59 [ 1 ] ) <= 0 )
{
perror ( V_42 ) ;
F_7 ( V_68 , L_47 , V_42 ) ;
goto V_74;
}
V_52 = F_31 ( V_39 , V_43 ) ;
if ( V_52 <= 0 ) goto V_74;
}
if ( V_9 )
F_7 ( V_68 , L_75 ) ;
for ( V_50 = 0 ; V_50 < F_28 ( V_56 ) ; V_50 ++ )
{
int V_116 ;
unsigned char * V_117 ;
V_37 = ( T_3 * ) F_29 ( V_56 , V_50 ) ;
V_51 = V_37 -> V_118 -> V_119 -> V_120 ;
V_48 = ( char * ) V_37 -> V_118 -> V_119 -> V_92 ;
strncpy ( V_59 [ 2 ] , V_26 , V_58 - ( V_51 * 2 ) - 6 ) ;
#ifndef F_9
strcat ( V_59 [ 2 ] , L_31 ) ;
#endif
V_117 = ( unsigned char * ) & ( V_59 [ 2 ] [ strlen ( V_59 [ 2 ] ) ] ) ;
if ( V_51 > 0 )
{
for ( V_116 = 0 ; V_116 < V_51 ; V_116 ++ )
{
sprintf ( ( char * ) V_117 , L_76 , ( unsigned char ) * ( V_48 ++ ) ) ;
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
if ( V_9 )
F_7 ( V_68 , L_77 , V_59 [ 2 ] ) ;
if ( F_33 ( V_41 , V_59 [ 2 ] ) <= 0 )
{
perror ( V_59 [ 2 ] ) ;
goto V_74;
}
F_52 ( V_41 , V_37 , 0 , V_35 ) ;
F_52 ( V_40 , V_37 , V_24 , V_35 ) ;
}
if ( F_28 ( V_56 ) )
{
strncpy ( V_59 [ 2 ] , V_27 , V_58 - 4 ) ;
#ifdef F_9
strcat ( V_59 [ 2 ] , L_78 ) ;
#else
strcat ( V_59 [ 2 ] , L_79 ) ;
#endif
F_17 ( V_38 ) ;
F_17 ( V_39 ) ;
V_38 = NULL ;
V_39 = NULL ;
if ( rename ( V_27 , V_59 [ 2 ] ) < 0 )
{
F_7 ( V_68 , L_80 ,
V_27 , V_59 [ 2 ] ) ;
perror ( L_81 ) ;
goto V_74;
}
if ( rename ( V_59 [ 0 ] , V_27 ) < 0 )
{
F_7 ( V_68 , L_80 ,
V_59 [ 0 ] , V_27 ) ;
perror ( L_81 ) ;
rename ( V_59 [ 2 ] , V_27 ) ;
goto V_74;
}
strncpy ( V_59 [ 2 ] , V_42 , V_58 - 4 ) ;
#ifdef F_9
strcat ( V_59 [ 2 ] , L_78 ) ;
#else
strcat ( V_59 [ 2 ] , L_79 ) ;
#endif
if ( rename ( V_42 , V_59 [ 2 ] ) < 0 )
{
F_7 ( V_68 , L_80 ,
V_42 , V_59 [ 2 ] ) ;
perror ( L_81 ) ;
goto V_74;
}
if ( rename ( V_59 [ 1 ] , V_42 ) < 0 )
{
F_7 ( V_68 , L_80 ,
V_59 [ 1 ] , V_42 ) ;
perror ( L_81 ) ;
rename ( V_59 [ 2 ] , V_42 ) ;
goto V_74;
}
F_7 ( V_68 , L_82 ) ;
}
}
if ( V_10 )
{
if( ! V_29 ) V_29 = F_12 ( V_64 , V_65 , V_121 ) ;
if( V_29 ) {
T_12 V_111 ;
F_36 ( & V_111 ) ;
F_37 ( & V_111 , V_64 ) ;
if( ! F_38 ( V_64 , & V_111 , V_29 , NULL ) ) {
F_7 ( V_68 ,
L_83 ,
V_29 ) ;
V_7 = 1 ;
goto V_74;
}
}
if ( ( V_57 = F_4 ( F_53 () ) ) == NULL ) goto V_74;
if ( ! V_12 && ! V_13 )
{
V_12 = F_40 ( V_64 , V_65 ,
V_122 ) ;
V_13 = F_40 ( V_64 , V_65 ,
V_123 ) ;
}
if ( ( V_12 == 0 ) && ( V_13 == 0 ) )
{
F_7 ( V_68 , L_84 ) ;
goto V_74;
}
if ( V_9 ) F_7 ( V_68 , L_85 ) ;
if ( ( V_44 = F_54 () ) == NULL ) goto V_74;
V_45 = V_44 -> V_44 ;
F_55 ( V_45 -> V_124 ) ;
V_45 -> V_124 = F_56 ( V_36 -> V_118 -> V_125 ) ;
if ( V_45 -> V_124 == NULL ) goto V_74;
F_57 ( V_45 -> V_126 , 0 ) ;
if ( V_45 -> V_127 == NULL )
V_45 -> V_127 = F_58 () ;
F_57 ( V_45 -> V_127 , ( V_12 * 24 + V_13 ) * 60 * 60 ) ;
for ( V_50 = 0 ; V_50 < F_28 ( V_43 -> V_92 ) ; V_50 ++ )
{
V_47 = ( char * * ) F_29 ( V_43 -> V_92 , V_50 ) ;
if ( V_47 [ V_93 ] [ 0 ] == V_94 )
{
if ( ( V_46 = F_59 () ) == NULL ) goto V_74;
F_60 ( ( V_128 * )
V_46 -> V_129 ,
( unsigned char * ) V_47 [ V_95 ] ,
strlen ( V_47 [ V_95 ] ) ) ;
( void ) F_61 ( V_57 ) ;
if ( ! F_62 ( V_57 , V_47 [ V_97 ] ) )
goto V_74;
if ( ! F_63 ( V_57 , V_46 -> V_119 ,
V_59 [ 0 ] , V_58 ) ) goto V_74;
F_64 ( V_45 -> V_130 , V_46 ) ;
}
}
F_65 ( V_45 -> V_130 ) ;
for ( V_50 = 0 ; V_50 < F_66 ( V_45 -> V_130 ) ; V_50 ++ )
{
V_46 = F_67 ( V_45 -> V_130 , V_50 ) ;
V_46 -> V_131 = V_50 ;
}
if ( V_9 ) F_7 ( V_68 , L_86 ) ;
if ( V_16 != NULL )
{
if ( ( V_53 = F_34 ( V_16 ) ) == NULL )
{
F_7 ( V_68 , L_57 , V_16 ) ;
goto V_74;
}
}
else
{
#ifndef F_68
if ( V_23 -> type == V_132 )
V_53 = F_69 () ;
else
#endif
V_53 = F_70 () ;
}
if( V_29 ) {
T_12 V_133 ;
if ( V_45 -> V_134 == NULL )
if ( ( V_45 -> V_134 = F_71 () ) == NULL ) goto V_74;
F_72 ( V_45 -> V_134 , 1 ) ;
F_73 ( & V_133 , V_36 , NULL , NULL , V_44 , 0 ) ;
F_37 ( & V_133 , V_64 ) ;
if( ! F_74 ( V_64 , & V_133 ,
V_29 , V_44 ) ) goto V_74;
}
if ( ! F_75 ( V_44 , V_23 , V_53 ) ) goto V_74;
F_76 ( V_40 , V_44 ) ;
}
if ( V_11 )
{
if ( V_20 == NULL )
{
F_7 ( V_68 , L_87 ) ;
goto V_74;
}
else
{
T_3 * V_135 ;
if ( F_21 ( V_38 , V_20 ) <= 0 )
{
perror ( V_20 ) ;
F_7 ( V_68 , L_88 , V_20 ) ;
goto V_74;
}
V_135 = F_23 ( V_38 , NULL , NULL , NULL ) ;
if ( V_135 == NULL )
{
F_7 ( V_68 , L_89 , V_20 ) ;
goto V_74;
}
V_51 = F_77 ( V_135 , V_43 ) ;
if ( V_51 <= 0 ) goto V_74;
F_78 ( V_135 ) ;
strncpy ( V_59 [ 0 ] , V_42 , V_58 - 4 ) ;
strcat ( V_59 [ 0 ] , L_74 ) ;
if ( F_33 ( V_39 , V_59 [ 0 ] ) <= 0 )
{
perror ( V_42 ) ;
F_7 ( V_68 , L_47 , V_42 ) ;
goto V_74;
}
V_51 = F_31 ( V_39 , V_43 ) ;
if ( V_51 <= 0 ) goto V_74;
strncpy ( V_59 [ 1 ] , V_42 , V_58 - 4 ) ;
strcat ( V_59 [ 1 ] , L_79 ) ;
if ( rename ( V_42 , V_59 [ 1 ] ) < 0 )
{
F_7 ( V_68 , L_80 , V_42 , V_59 [ 1 ] ) ;
perror ( L_81 ) ;
goto V_74;
}
if ( rename ( V_59 [ 0 ] , V_42 ) < 0 )
{
F_7 ( V_68 , L_80 , V_59 [ 0 ] , V_42 ) ;
perror ( L_81 ) ;
rename ( V_59 [ 1 ] , V_42 ) ;
goto V_74;
}
F_7 ( V_68 , L_82 ) ;
}
}
V_7 = 0 ;
V_74:
F_17 ( V_57 ) ;
F_17 ( V_41 ) ;
F_17 ( V_40 ) ;
F_17 ( V_39 ) ;
F_17 ( V_38 ) ;
F_79 ( V_56 , F_78 ) ;
if ( V_7 ) F_19 ( V_68 ) ;
F_80 ( V_60 , V_68 ) ;
F_81 ( V_30 ) ;
F_82 ( V_43 ) ;
F_83 ( V_23 ) ;
F_78 ( V_36 ) ;
F_84 ( V_44 ) ;
F_85 ( V_64 ) ;
F_86 () ;
EXIT ( V_7 ) ;
}
static void F_13 ( char * V_136 , char * V_137 )
{
F_7 ( V_68 , L_90 , V_136 , V_137 ) ;
}
static unsigned long V_99 ( char * * V_138 )
{
char * V_117 ;
V_117 = V_138 [ V_97 ] ;
while ( * V_117 == '0' ) V_117 ++ ;
return ( F_87 ( V_117 ) ) ;
}
static int V_100 ( char * * V_138 , char * * V_139 )
{
char * V_140 , * V_141 ;
for ( V_140 = V_138 [ V_97 ] ; * V_140 == '0' ; V_140 ++ ) ;
for ( V_141 = V_139 [ V_97 ] ; * V_141 == '0' ; V_141 ++ ) ;
return ( strcmp ( V_140 , V_141 ) ) ;
}
static unsigned long V_105 ( char * * V_138 )
{ return ( F_87 ( V_138 [ V_103 ] ) ) ; }
static int V_104 ( char * * V_138 )
{ return ( V_138 [ 0 ] [ 0 ] == 'V' ) ; }
static int V_106 ( char * * V_138 , char * * V_139 )
{ return ( strcmp ( V_138 [ V_103 ] ,
V_139 [ V_103 ] ) ) ; }
static T_2 * F_41 ( char * V_27 )
{
T_4 * V_38 = NULL ;
T_2 * V_7 = NULL ;
T_11 char V_59 [ 1024 ] ;
T_13 * V_142 = NULL ;
if ( ( V_38 = F_4 ( F_5 () ) ) == NULL )
{
F_19 ( V_68 ) ;
goto V_74;
}
if ( F_21 ( V_38 , V_27 ) <= 0 )
{
perror ( V_27 ) ;
goto V_74;
}
V_142 = F_71 () ;
if ( V_142 == NULL ) goto V_74;
if ( ! F_63 ( V_38 , V_142 , V_59 , 1024 ) )
{
F_7 ( V_68 , L_91 ,
V_27 ) ;
goto V_74;
}
V_7 = F_88 ( V_142 , NULL ) ;
if ( V_7 == NULL )
{
F_7 ( V_68 , L_92 ) ;
goto V_74;
}
V_74:
if ( V_38 != NULL ) F_17 ( V_38 ) ;
if ( V_142 != NULL ) F_89 ( V_142 ) ;
return ( V_7 ) ;
}
static int F_51 ( char * V_27 , T_2 * V_30 )
{
T_4 * V_39 ;
int V_7 = 0 ;
T_13 * V_142 = NULL ;
V_39 = F_4 ( F_5 () ) ;
if ( V_39 == NULL )
{
F_19 ( V_68 ) ;
goto V_74;
}
if ( F_33 ( V_39 , V_27 ) <= 0 )
{
perror ( V_27 ) ;
goto V_74;
}
if ( ( V_142 = F_90 ( V_30 , NULL ) ) == NULL )
{
F_7 ( V_68 , L_93 ) ;
goto V_74;
}
F_91 ( V_39 , V_142 ) ;
F_62 ( V_39 , L_69 ) ;
V_7 = 1 ;
V_74:
if ( V_39 != NULL ) F_17 ( V_39 ) ;
if ( V_142 != NULL ) F_89 ( V_142 ) ;
return ( V_7 ) ;
}
static void F_52 ( T_4 * V_143 , T_3 * V_37 , int V_24 , int V_35 )
{
if ( V_24 )
{
( void ) F_92 ( V_143 , V_37 ) ;
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
if( ! V_35 ) F_93 ( V_143 , V_37 ) ;
F_94 ( V_143 , V_37 ) ;
}
static int F_95 ( int V_144 , int * type )
{
if ( V_144 == V_145 )
* type = V_146 ;
if ( ( V_144 == V_147 ) && ( * type == V_146 ) )
* type = V_148 ;
if ( ( V_144 == V_149 ) && ( * type == V_146 ) )
* type = V_148 ;
if ( ( V_144 == V_150 ) && ( * type == V_148 ) )
return ( 0 ) ;
if ( V_144 == V_150 )
* type = V_146 ;
return ( 1 ) ;
}
static int F_30 ( char * V_151 )
{
T_14 V_152 ;
V_152 . V_92 = ( unsigned char * ) V_151 ;
V_152 . V_120 = strlen ( V_151 ) ;
V_152 . type = V_153 ;
return ( F_96 ( & V_152 ) ) ;
}
static int F_18 ( T_15 * V_154 )
{
char * V_48 ;
F_1 ( V_54 ) * V_155 ;
V_54 * V_156 ;
int V_50 ;
if( ! ( V_48 = F_12 ( V_154 , NULL , L_94 ) ) ) return 1 ;
if( ! ( V_155 = F_43 ( V_154 , V_48 ) ) ) {
F_7 ( V_68 , L_95 , V_48 ) ;
return 0 ;
}
for( V_50 = 0 ; V_50 < F_97 ( V_155 ) ; V_50 ++ ) {
V_156 = F_98 ( V_155 , V_50 ) ;
if( F_99 ( V_156 -> V_157 , V_156 -> V_136 , V_156 -> V_136 ) == V_158 ) {
F_7 ( V_68 , L_96 ,
V_156 -> V_136 , V_156 -> V_157 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_77 ( T_3 * V_36 , T_5 * V_43 )
{
T_14 * V_152 = NULL , * V_159 = NULL ;
char * V_160 [ V_91 ] , * * V_161 , * * V_162 ;
T_2 * V_163 = NULL ;
int V_164 = - 1 , V_50 ;
for ( V_50 = 0 ; V_50 < V_91 ; V_50 ++ )
V_160 [ V_50 ] = NULL ;
V_160 [ V_103 ] = F_100 ( F_101 ( V_36 ) , NULL , 0 ) ;
V_163 = F_88 ( F_102 ( V_36 ) , NULL ) ;
V_160 [ V_97 ] = F_42 ( V_163 ) ;
F_81 ( V_163 ) ;
if ( ( V_160 [ V_103 ] == NULL ) || ( V_160 [ V_97 ] == NULL ) )
{
F_7 ( V_68 , L_68 ) ;
goto V_74;
}
V_161 = F_103 ( V_43 , V_97 , V_160 ) ;
if ( V_161 == NULL )
{
F_7 ( V_68 , L_97 , V_160 [ V_103 ] ) ;
V_160 [ V_93 ] = ( char * ) Malloc ( 2 ) ;
V_152 = F_104 ( V_36 ) ;
V_160 [ V_96 ] = ( char * ) Malloc ( V_152 -> V_120 + 1 ) ;
memcpy ( V_160 [ V_96 ] , V_152 -> V_92 , V_152 -> V_120 ) ;
V_160 [ V_96 ] [ V_152 -> V_120 ] = '\0' ;
V_160 [ V_95 ] = NULL ;
V_160 [ V_165 ] = ( char * ) Malloc ( 8 ) ;
if ( ( V_160 [ V_93 ] == NULL ) || ( V_160 [ V_96 ] == NULL ) ||
( V_160 [ V_165 ] == NULL ) )
{
F_7 ( V_68 , L_68 ) ;
goto V_74;
}
strcpy ( V_160 [ V_165 ] , L_98 ) ;
V_160 [ V_93 ] [ 0 ] = 'V' ;
V_160 [ V_93 ] [ 1 ] = '\0' ;
if ( ( V_162 = ( char * * ) Malloc ( sizeof( char * ) * ( V_91 + 1 ) ) ) == NULL )
{
F_7 ( V_68 , L_68 ) ;
goto V_74;
}
for ( V_50 = 0 ; V_50 < V_91 ; V_50 ++ )
{
V_162 [ V_50 ] = V_160 [ V_50 ] ;
V_160 [ V_50 ] = NULL ;
}
V_162 [ V_91 ] = NULL ;
if ( ! F_105 ( V_43 , V_162 ) )
{
F_7 ( V_68 , L_99 ) ;
F_7 ( V_68 , L_100 , V_43 -> error ) ;
goto V_74;
}
V_164 = F_77 ( V_36 , V_43 ) ;
goto V_74;
}
else if ( V_106 ( V_160 , V_161 ) )
{
F_7 ( V_68 , L_101 ,
V_160 [ V_103 ] ) ;
goto V_74;
}
else if ( V_161 [ V_93 ] [ 0 ] == 'R' )
{
F_7 ( V_68 , L_102 ,
V_160 [ V_97 ] ) ;
goto V_74;
}
else
{
F_7 ( V_68 , L_103 , V_161 [ V_97 ] ) ;
V_159 = F_58 () ;
V_159 = F_57 ( V_159 , 0 ) ;
V_161 [ V_93 ] [ 0 ] = 'R' ;
V_161 [ V_93 ] [ 1 ] = '\0' ;
V_161 [ V_95 ] = ( char * ) Malloc ( V_159 -> V_120 + 1 ) ;
memcpy ( V_161 [ V_95 ] , V_159 -> V_92 , V_159 -> V_120 ) ;
V_161 [ V_95 ] [ V_159 -> V_120 ] = '\0' ;
F_106 ( V_159 ) ;
}
V_164 = 1 ;
V_74:
for ( V_50 = 0 ; V_50 < V_91 ; V_50 ++ )
{
if ( V_160 [ V_50 ] != NULL )
Free ( V_160 [ V_50 ] ) ;
}
return ( V_164 ) ;
}
