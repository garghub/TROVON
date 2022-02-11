int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
T_1 * V_4 = NULL ;
T_2 * V_5 = NULL , * V_6 = NULL ;
T_3 * V_7 = NULL , * V_8 = NULL ;
int V_9 , V_10 , V_11 = 0 ;
T_4 * V_12 = NULL ;
T_4 * STDout = NULL ;
int V_13 , V_14 , V_15 , V_16 , V_17 ;
char * V_18 = NULL , * V_19 = NULL , * V_20 = NULL , * V_21 = NULL ;
char * V_22 = NULL , * V_23 = NULL ;
int V_24 = 0 , V_25 = 0 , V_26 = 0 , V_27 = 0 , V_28 = 0 , V_29 = 0 , V_30 = 0 ;
int V_31 = 0 , V_32 = 0 , V_33 = 0 , V_34 = 0 ;
int V_35 = 0 ;
int V_36 = 0 , V_37 = V_38 , V_39 = 0 ;
char * * V_40 ;
T_5 * V_41 = NULL ;
T_1 * V_42 = NULL ;
int V_43 = 0 ;
char V_44 [ 256 ] ;
const T_6 * V_45 , * V_46 = F_1 () ;
T_7 * V_47 = NULL ;
char * V_48 = NULL , * V_49 = NULL ;
V_50 = 0 ;
F_2 () ;
if ( V_51 == NULL )
V_51 = F_3 ( V_52 , V_53 ) ;
STDout = F_3 ( stdout , V_53 ) ;
V_13 = V_54 ;
V_14 = V_54 ;
V_15 = V_54 ;
V_16 = V_54 ;
V_17 = V_54 ;
V_41 = F_4 () ;
if ( V_41 == NULL ) goto V_55;
F_5 ( V_41 , V_56 ) ;
V_1 -- ;
V_2 ++ ;
V_10 = 0 ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_57;
V_13 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_57;
V_14 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_57;
V_15 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
V_50 = 1 ;
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_57;
V_16 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_57;
V_16 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_57;
V_37 = atoi ( * ( ++ V_2 ) ) ;
if ( V_37 == 0 )
{
F_7 ( STDout , L_8 ) ;
goto V_57;
}
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_57;
V_49 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_57;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_57;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_57;
V_20 = * ( ++ V_2 ) ;
V_32 = ++ V_10 ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_57;
V_21 = * ( ++ V_2 ) ;
V_33 = ++ V_10 ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_57;
V_22 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_57;
V_23 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_16 ) == 0 )
V_35 = ++ V_10 ;
else if ( strcmp ( * V_2 , L_17 ) == 0 )
V_25 = ++ V_10 ;
else if ( strcmp ( * V_2 , L_18 ) == 0 )
V_39 = ++ V_10 ;
else if ( strcmp ( * V_2 , L_19 ) == 0 )
V_36 = ++ V_10 ;
else if ( strcmp ( * V_2 , L_20 ) == 0 )
V_24 = ++ V_10 ;
else if ( strcmp ( * V_2 , L_21 ) == 0 )
V_26 = ++ V_10 ;
else if ( strcmp ( * V_2 , L_22 ) == 0 )
V_27 = ++ V_10 ;
else if ( strcmp ( * V_2 , L_23 ) == 0 )
V_28 = ++ V_10 ;
else if ( strcmp ( * V_2 , L_24 ) == 0 )
V_43 = ++ V_10 ;
else if ( strcmp ( * V_2 , L_25 ) == 0 )
{
V_29 = ++ V_10 ;
V_30 = ++ V_10 ;
}
else if ( strcmp ( * V_2 , L_26 ) == 0 )
V_29 = ++ V_10 ;
else if ( strcmp ( * V_2 , L_27 ) == 0 )
V_30 = ++ V_10 ;
else if ( strcmp ( * V_2 , L_28 ) == 0 )
V_31 = ++ V_10 ;
else if ( strcmp ( * V_2 , L_29 ) == 0 )
V_34 = ++ V_10 ;
else if ( ( V_45 = F_8 ( & ( ( * V_2 ) [ 1 ] ) ) ) != NULL )
{
V_46 = V_45 ;
}
else
{
F_7 ( V_51 , L_30 , * V_2 ) ;
V_11 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_11 )
{
V_57:
for ( V_40 = V_58 ; ( * V_40 != NULL ) ; V_40 ++ )
F_7 ( V_51 , * V_40 ) ;
goto V_55;
}
F_9 () ;
F_10 () ;
if ( ! F_11 ( V_41 ) )
{
F_12 ( V_51 ) ;
goto V_55;
}
if ( ( V_22 == NULL ) && ( V_33 ) && ( V_16 == V_54 ) )
{ V_22 = V_21 ; }
else if ( ( V_33 ) && ( V_22 == NULL ) )
{
F_7 ( V_51 , L_31 ) ;
goto V_55;
}
if ( V_49 ) {
long V_59 ;
T_8 V_60 ;
if ( ! ( V_47 = F_13 ( NULL , V_49 , & V_59 ) ) ) {
if ( V_59 <= 0 )
F_7 ( V_51 ,
L_32 ,
V_49 ) ;
else
F_7 ( V_51 ,
L_33
, V_59 , V_49 ) ;
goto V_55;
}
if( ! ( V_48 = F_14 ( V_47 , L_34 ,
L_35 ) ) ) V_48 = L_34 ;
F_15 ( & V_60 ) ;
F_16 ( & V_60 , V_47 ) ;
if( ! F_17 ( V_47 , & V_60 , V_48 , NULL ) ) {
F_7 ( V_51 ,
L_36 ,
V_48 ) ;
F_12 ( V_51 ) ;
goto V_55;
}
}
if ( V_50 )
{
T_3 * V_61 ;
T_9 * V_62 ;
T_4 * V_63 ;
if ( ! V_32 && ! V_33 )
{
F_7 ( V_51 , L_37 ) ;
goto V_55;
}
V_63 = F_18 ( F_19 () ) ;
if ( V_63 == NULL )
{
F_12 ( V_51 ) ;
goto V_55;
}
if ( V_18 == NULL )
F_20 ( V_63 , V_64 , V_53 | V_65 ) ;
else
{
if ( F_21 ( V_63 , V_18 ) <= 0 )
{
perror ( V_18 ) ;
goto V_55;
}
}
V_4 = F_22 ( V_63 , NULL , NULL ) ;
F_23 ( V_63 ) ;
if ( V_4 == NULL ) { perror ( V_18 ) ; goto V_55; }
if ( ( V_4 -> V_66 == NULL ) ||
( V_4 -> V_66 -> V_67 == NULL ) ||
( V_4 -> V_66 -> V_67 -> V_68 == NULL ) ||
( V_4 -> V_66 -> V_67 -> V_68 -> V_69 == NULL ) )
{
F_7 ( V_51 , L_38 ) ;
F_7 ( V_51 , L_39 ) ;
goto V_55;
}
if ( ( V_61 = F_24 ( V_4 ) ) == NULL )
{
F_7 ( V_51 , L_40 ) ;
goto V_55;
}
V_9 = F_25 ( V_4 , V_61 ) ;
F_26 ( V_61 ) ;
if ( V_9 < 0 )
{
F_7 ( V_51 , L_41 ) ;
F_12 ( V_51 ) ;
goto V_55;
}
if ( V_9 == 0 )
{
F_7 ( V_51 , L_42 ) ;
goto V_55;
}
else
F_7 ( V_51 , L_43 ) ;
F_27 ( V_4 -> V_66 -> V_27 , V_44 , 256 ) ;
F_7 ( V_51 , L_44 , V_44 ) ;
if ( ( V_5 = F_28 () ) == NULL ) goto V_55;
V_62 = V_5 -> V_70 ;
if ( ! F_29 ( F_30 ( V_5 ) , 0 ) ) goto V_55;
if ( ! F_31 ( V_5 , V_4 -> V_66 -> V_27 ) ) goto V_55;
if ( ! F_32 ( V_5 , V_4 -> V_66 -> V_27 ) ) goto V_55;
F_33 ( F_34 ( V_5 ) , 0 ) ;
F_33 ( F_35 ( V_5 ) , ( long ) 60 * 60 * 24 * V_37 ) ;
#if 0
X509_PUBKEY_free(ci->key);
ci->key=req->req_info->pubkey;
req->req_info->pubkey=NULL;
#else
V_61 = F_24 ( V_4 ) ;
F_36 ( V_5 , V_61 ) ;
F_26 ( V_61 ) ;
#endif
}
else
V_5 = F_37 ( V_18 , V_13 ) ;
if ( V_5 == NULL ) goto V_55;
if ( V_33 )
{
V_6 = F_37 ( V_21 , V_16 ) ;
if ( V_6 == NULL ) goto V_55;
}
if ( ! V_31 || V_24 )
{
F_38 ( L_45 ,
L_46 , L_47 ) ;
V_12 = F_18 ( F_19 () ) ;
if ( V_12 == NULL )
{
F_12 ( V_51 ) ;
goto V_55;
}
if ( V_19 == NULL )
F_20 ( V_12 , stdout , V_53 ) ;
else
{
if ( F_39 ( V_12 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
goto V_55;
}
}
}
if ( V_10 )
{
for ( V_9 = 1 ; V_9 <= V_10 ; V_9 ++ )
{
if ( V_28 == V_9 )
{
F_27 ( F_40 ( V_5 ) ,
V_44 , 256 ) ;
F_7 ( STDout , L_48 , V_44 ) ;
}
else if ( V_27 == V_9 )
{
F_27 ( F_41 ( V_5 ) ,
V_44 , 256 ) ;
F_7 ( STDout , L_44 , V_44 ) ;
}
else if ( V_25 == V_9 )
{
F_7 ( STDout , L_49 ) ;
F_42 ( STDout , V_5 -> V_70 -> V_71 ) ;
F_7 ( STDout , L_50 ) ;
}
else if ( V_26 == V_9 )
{
F_7 ( STDout , L_51 , F_43 ( V_5 ) ) ;
}
else
if ( V_39 == V_9 )
{
T_3 * V_61 ;
V_61 = F_44 ( V_5 ) ;
if ( V_61 == NULL )
{
F_7 ( V_51 , L_52 ) ;
F_12 ( V_51 ) ;
goto V_55;
}
F_7 ( STDout , L_53 ) ;
#ifndef F_45
if ( V_61 -> type == V_72 )
F_46 ( STDout , V_61 -> V_61 . V_73 -> V_74 ) ;
else
#endif
#ifndef F_47
if ( V_61 -> type == V_75 )
F_46 ( STDout , V_61 -> V_61 . V_76 -> V_77 ) ;
else
#endif
F_7 ( STDout , L_54 ) ;
F_7 ( STDout , L_50 ) ;
F_26 ( V_61 ) ;
}
else
if ( V_35 == V_9 )
{
unsigned char * V_78 ;
char * V_79 ;
int V_80 , V_81 ;
F_27 ( F_41 ( V_5 ) ,
V_44 , 256 ) ;
F_7 ( STDout , L_55 , V_44 ) ;
V_79 = F_27 (
F_40 ( V_5 ) , V_44 , 256 ) ;
F_7 ( STDout , L_56 , V_44 ) ;
V_81 = F_48 ( V_5 , NULL ) ;
V_79 = Malloc ( V_81 ) ;
V_78 = ( unsigned char * ) V_79 ;
V_81 = F_49 ( F_41 ( V_5 ) , & V_78 ) ;
F_7 ( STDout , L_57 , V_81 ) ;
V_78 = ( unsigned char * ) V_79 ;
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ )
{
F_7 ( STDout , L_58 , V_78 [ V_80 ] ) ;
if ( ( V_80 & 0x0f ) == 0x0f ) F_7 ( STDout , L_50 ) ;
}
if ( V_80 % 16 != 0 ) F_7 ( STDout , L_50 ) ;
F_7 ( STDout , L_59 ) ;
V_81 = F_50 ( F_51 ( V_5 ) , & V_78 ) ;
F_7 ( STDout , L_60 , V_81 ) ;
V_78 = ( unsigned char * ) V_79 ;
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ )
{
F_7 ( STDout , L_58 , V_78 [ V_80 ] ) ;
if ( ( V_80 & 0x0f ) == 0x0f )
F_7 ( STDout , L_50 ) ;
}
if ( V_80 % 16 != 0 ) F_7 ( STDout , L_50 ) ;
F_7 ( STDout , L_59 ) ;
V_81 = F_48 ( V_5 , & V_78 ) ;
F_7 ( STDout , L_61 , V_81 ) ;
V_78 = ( unsigned char * ) V_79 ;
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ )
{
F_7 ( STDout , L_58 , V_78 [ V_80 ] ) ;
if ( ( V_80 & 0x0f ) == 0x0f )
F_7 ( STDout , L_50 ) ;
}
if ( V_80 % 16 != 0 ) F_7 ( STDout , L_50 ) ;
F_7 ( STDout , L_59 ) ;
Free ( V_79 ) ;
}
else if ( V_24 == V_9 )
{
F_52 ( V_12 , V_5 ) ;
}
else if ( V_29 == V_9 )
{
F_53 ( STDout , L_62 ) ;
F_54 ( STDout , F_34 ( V_5 ) ) ;
F_53 ( STDout , L_50 ) ;
}
else if ( V_30 == V_9 )
{
F_53 ( STDout , L_63 ) ;
F_54 ( STDout , F_35 ( V_5 ) ) ;
F_53 ( STDout , L_50 ) ;
}
else if ( V_43 == V_9 )
{
int V_82 ;
unsigned int V_74 ;
unsigned char V_83 [ V_84 ] ;
if ( ! F_55 ( V_5 , F_1 () , V_83 , & V_74 ) )
{
F_7 ( V_51 , L_64 ) ;
goto V_55;
}
F_7 ( STDout , L_65 ) ;
for ( V_82 = 0 ; V_82 < ( int ) V_74 ; V_82 ++ )
{
F_7 ( STDout , L_66 , V_83 [ V_82 ] ,
( V_82 + 1 == ( int ) V_74 )
? '\n' : ':' ) ;
}
}
else if ( ( V_32 == V_9 ) && ( V_36 == 0 ) )
{
F_7 ( V_51 , L_67 ) ;
if ( V_7 == NULL )
{
V_7 = F_56 ( V_20 , V_15 ) ;
if ( V_7 == NULL ) goto V_55;
}
#ifndef F_47
if ( V_7 -> type == V_75 )
V_46 = F_57 () ;
#endif
if ( ! F_58 ( V_5 , V_7 , V_37 , V_46 ,
V_47 , V_48 ) ) goto V_55;
}
else if ( V_33 == V_9 )
{
F_7 ( V_51 , L_68 ) ;
if ( V_22 != NULL )
{
V_8 = F_56 ( V_22 , V_17 ) ;
if ( V_8 == NULL ) goto V_55;
}
#ifndef F_47
if ( V_8 -> type == V_75 )
V_46 = F_57 () ;
#endif
if ( ! F_59 ( V_41 , V_21 , V_46 , V_5 , V_6 ,
V_8 , V_23 , V_34 , V_37 ,
V_47 , V_48 ) )
goto V_55;
}
else if ( V_36 == V_9 )
{
T_3 * V_85 ;
F_7 ( V_51 , L_69 ) ;
if ( V_20 == NULL )
{
F_7 ( V_51 , L_70 ) ;
goto V_55;
}
else
{
V_85 = F_56 ( V_20 , V_54 ) ;
if ( V_85 == NULL ) goto V_55;
}
F_7 ( V_51 , L_71 ) ;
V_42 = F_60 ( V_5 , V_85 , F_1 () ) ;
F_26 ( V_85 ) ;
if ( V_42 == NULL )
{
F_12 ( V_51 ) ;
goto V_55;
}
if ( ! V_31 )
{
F_61 ( V_12 , V_42 ) ;
F_62 ( V_12 , V_42 ) ;
}
V_31 = 1 ;
}
}
}
if ( V_31 )
{
V_3 = 0 ;
goto V_55;
}
if ( V_14 == V_86 )
V_9 = F_63 ( V_12 , V_5 ) ;
else if ( V_14 == V_54 )
V_9 = F_64 ( V_12 , V_5 ) ;
else if ( V_14 == V_87 )
{
T_10 V_88 ;
T_11 V_89 ;
V_89 . V_69 = ( unsigned char * ) V_90 ;
V_89 . V_91 = strlen ( V_90 ) ;
V_88 . V_92 = & V_89 ;
V_88 . V_69 = ( char * ) V_5 ;
V_88 . V_93 = F_65 () ;
V_9 = F_66 ( V_94 , V_12 , ( unsigned char * ) & V_88 ) ;
}
else {
F_7 ( V_51 , L_72 ) ;
goto V_55;
}
if ( ! V_9 ) {
F_7 ( V_51 , L_73 ) ;
F_12 ( V_51 ) ;
goto V_55;
}
V_3 = 0 ;
V_55:
F_67 () ;
F_68 ( V_47 ) ;
F_23 ( V_12 ) ;
F_23 ( STDout ) ;
F_69 ( V_41 ) ;
F_70 ( V_4 ) ;
F_71 ( V_5 ) ;
F_71 ( V_6 ) ;
F_26 ( V_7 ) ;
F_26 ( V_8 ) ;
F_70 ( V_42 ) ;
F_72 () ;
EXIT ( V_3 ) ;
}
static int F_59 ( T_5 * V_41 , char * V_21 , const T_6 * V_46 ,
T_2 * V_5 , T_2 * V_6 , T_3 * V_61 , char * V_95 , int V_96 ,
int V_37 , T_7 * V_97 , char * V_98 )
{
int V_3 = 0 ;
T_4 * V_99 = NULL ;
T_12 char V_100 [ 1024 ] ;
char * V_44 = NULL , * V_101 ;
T_13 * V_25 = NULL ;
T_14 * V_102 = NULL , V_103 ;
T_15 V_104 ;
T_3 * V_105 ;
V_105 = F_44 ( V_6 ) ;
F_73 ( V_105 , V_61 ) ;
F_26 ( V_105 ) ;
F_74 ( & V_104 , V_41 , V_5 , NULL ) ;
V_44 = ( char * ) Malloc ( F_75 ( V_61 ) * 2 +
( ( V_95 == NULL )
? ( strlen ( V_21 ) + strlen ( V_106 ) + 1 )
: ( strlen ( V_95 ) ) ) + 1 ) ;
if ( V_44 == NULL ) { F_7 ( V_51 , L_74 ) ; goto V_55; }
if ( V_95 == NULL )
{
strcpy ( V_44 , V_21 ) ;
for ( V_101 = V_44 ; * V_101 ; V_101 ++ )
if ( * V_101 == '.' )
{
* V_101 = '\0' ;
break;
}
strcat ( V_44 , V_106 ) ;
}
else
strcpy ( V_44 , V_95 ) ;
V_25 = F_76 () ;
V_102 = F_77 () ;
if ( ( V_25 == NULL ) || ( V_102 == NULL ) )
{
F_12 ( V_51 ) ;
goto V_55;
}
V_99 = F_18 ( F_19 () ) ;
if ( V_99 == NULL )
{
F_12 ( V_51 ) ;
goto V_55;
}
if ( F_21 ( V_99 , V_44 ) <= 0 )
{
if ( ! V_96 )
{
perror ( V_44 ) ;
goto V_55;
}
else
{
F_29 ( V_102 , 0 ) ;
F_78 ( V_25 ) ;
}
}
else
{
if ( ! F_79 ( V_99 , V_102 , V_100 , 1024 ) )
{
F_7 ( V_51 , L_75 , V_44 ) ;
F_12 ( V_51 ) ;
goto V_55;
}
else
{
V_25 = F_80 ( V_102 -> V_69 , V_102 -> V_91 , V_25 ) ;
if ( V_25 == NULL )
{
F_7 ( V_51 , L_76 ) ;
goto V_55;
}
}
}
if ( ! F_81 ( V_25 , 1 ) )
{ F_7 ( V_51 , L_77 ) ; goto V_55; }
V_103 . V_69 = ( unsigned char * ) V_100 ;
V_103 . V_91 = F_82 ( V_25 , V_103 . V_69 ) ;
if ( F_39 ( V_99 , V_44 ) <= 0 )
{
F_7 ( V_51 , L_78 ) ;
perror ( V_44 ) ;
goto V_55;
}
F_42 ( V_99 , & V_103 ) ;
F_53 ( V_99 , L_50 ) ;
F_23 ( V_99 ) ;
V_99 = NULL ;
if ( ! F_83 ( V_41 , V_5 ) ) goto V_55;
F_84 ( & V_104 , V_5 ) ;
if ( ! V_50 && ! F_85 ( & V_104 ) )
goto V_55;
if ( ! F_86 ( V_6 , V_61 ) )
{
F_7 ( V_51 , L_79 ) ;
goto V_55;
}
if ( ! F_31 ( V_5 , F_41 ( V_6 ) ) ) goto V_55;
if ( ! F_87 ( V_5 , V_102 ) ) goto V_55;
if ( F_33 ( F_34 ( V_5 ) , 0L ) == NULL )
goto V_55;
if ( F_33 ( F_35 ( V_5 ) , ( long ) 60 * 60 * 24 * V_37 ) == NULL )
goto V_55;
V_105 = F_44 ( V_5 ) ;
if ( ! F_88 ( V_61 ) &&
( F_89 ( V_61 , V_105 ) == 0 ) )
{
F_90 ( V_105 , 0 ) ;
F_36 ( V_5 , V_105 ) ;
}
F_26 ( V_105 ) ;
if( V_97 ) {
T_8 V_60 ;
F_91 ( V_5 , 2 ) ;
F_92 ( & V_60 , V_6 , V_5 , NULL , NULL , 0 ) ;
F_16 ( & V_60 , V_97 ) ;
if( ! F_17 ( V_97 , & V_60 , V_98 , V_5 ) ) goto V_55;
}
if ( ! F_93 ( V_5 , V_61 , V_46 ) ) goto V_55;
V_3 = 1 ;
V_55:
F_94 ( & V_104 ) ;
if ( ! V_3 )
F_12 ( V_51 ) ;
if ( V_44 != NULL ) Free ( V_44 ) ;
if ( V_102 != NULL ) F_95 ( V_102 ) ;
if ( V_99 != NULL ) F_23 ( V_99 ) ;
if ( V_25 != NULL ) F_96 ( V_25 ) ;
return ( V_3 ) ;
}
static int T_16 V_56 ( int V_107 , T_15 * V_41 )
{
char V_44 [ 256 ] ;
int V_108 ;
T_2 * V_109 ;
V_108 = F_97 ( V_41 ) ;
if ( V_108 == V_110 )
return ( 1 ) ;
if ( V_107 )
{
F_7 ( V_51 , L_80 ) ;
return ( 0 ) ;
}
else
{
V_109 = F_98 ( V_41 ) ;
F_27 ( F_41 ( V_109 ) , V_44 , 256 ) ;
F_7 ( V_51 , L_81 , V_44 ) ;
F_7 ( V_51 , L_82 ,
V_108 , F_99 ( V_41 ) ,
F_100 ( V_108 ) ) ;
return ( 1 ) ;
}
}
static T_3 * F_56 ( char * V_111 , int V_112 )
{
T_4 * V_113 = NULL ;
T_3 * V_61 = NULL ;
if ( V_111 == NULL )
{
F_7 ( V_51 , L_83 ) ;
goto V_55;
}
V_113 = F_18 ( F_19 () ) ;
if ( V_113 == NULL )
{
F_12 ( V_51 ) ;
goto V_55;
}
if ( F_21 ( V_113 , V_111 ) <= 0 )
{
perror ( V_111 ) ;
goto V_55;
}
#ifndef F_45
if ( V_112 == V_86 )
{
T_17 * V_73 ;
V_73 = F_101 ( V_113 , NULL ) ;
if ( V_73 != NULL )
{
if ( ( V_61 = F_102 () ) != NULL )
F_103 ( V_61 , V_73 ) ;
else
F_104 ( V_73 ) ;
}
}
else
#endif
if ( V_112 == V_54 )
{
V_61 = F_105 ( V_113 , NULL , NULL ) ;
}
else
{
F_7 ( V_51 , L_84 ) ;
goto V_55;
}
V_55:
if ( V_113 != NULL ) F_23 ( V_113 ) ;
if ( V_61 == NULL )
F_7 ( V_51 , L_85 ) ;
return ( V_61 ) ;
}
static T_2 * F_37 ( char * V_111 , int V_112 )
{
T_10 * V_88 = NULL ;
T_18 * V_44 = NULL ;
T_2 * V_5 = NULL ;
T_4 * V_114 ;
if ( ( V_114 = F_18 ( F_19 () ) ) == NULL )
{
F_12 ( V_51 ) ;
goto V_55;
}
if ( V_111 == NULL )
F_20 ( V_114 , V_64 , V_53 ) ;
else
{
if ( F_21 ( V_114 , V_111 ) <= 0 )
{
perror ( V_111 ) ;
goto V_55;
}
}
if ( V_112 == V_86 )
V_5 = F_106 ( V_114 , NULL ) ;
else if ( V_112 == V_87 )
{
unsigned char * V_101 , * V_115 ;
int V_116 = 0 , V_9 ;
V_44 = F_107 () ;
for (; ; )
{
if ( ( V_44 == NULL ) || ( ! F_108 ( V_44 , V_116 + 1024 * 10 ) ) )
goto V_55;
V_9 = F_109 ( V_114 , & ( V_44 -> V_69 [ V_116 ] ) , 1024 * 10 ) ;
V_116 += V_9 ;
if ( V_9 == 0 ) break;
if ( V_9 < 0 )
{
perror ( L_86 ) ;
goto V_55;
}
}
V_101 = ( unsigned char * ) V_44 -> V_69 ;
V_115 = V_101 ;
if ( ( V_88 = F_110 ( NULL , & V_101 , ( long ) V_116 ) ) == NULL )
goto V_55;
if ( ( V_88 -> V_92 == NULL ) || ( V_88 -> V_92 -> V_69 == NULL ) ||
( strncmp ( V_90 , ( char * ) V_88 -> V_92 -> V_69 ,
V_88 -> V_92 -> V_91 ) != 0 ) )
{
F_7 ( V_51 , L_87 ) ;
goto V_55;
}
V_101 = V_115 ;
V_88 -> V_93 = F_65 () ;
if ( ( V_88 = F_110 ( & V_88 , & V_101 , ( long ) V_116 ) ) == NULL )
goto V_55;
V_5 = ( T_2 * ) V_88 -> V_69 ;
V_88 -> V_69 = NULL ;
}
else if ( V_112 == V_54 )
V_5 = F_111 ( V_114 , NULL , NULL ) ;
else {
F_7 ( V_51 , L_88 ) ;
goto V_55;
}
V_55:
if ( V_5 == NULL )
{
F_7 ( V_51 , L_89 ) ;
F_12 ( V_51 ) ;
}
if ( V_88 != NULL ) F_112 ( V_88 ) ;
if ( V_114 != NULL ) F_23 ( V_114 ) ;
if ( V_44 != NULL ) F_113 ( V_44 ) ;
return ( V_5 ) ;
}
static int F_58 ( T_2 * V_5 , T_3 * V_61 , int V_37 , const T_6 * V_46 ,
T_7 * V_97 , char * V_98 )
{
T_3 * V_117 ;
V_117 = F_44 ( V_5 ) ;
F_73 ( V_117 , V_61 ) ;
F_90 ( V_117 , 1 ) ;
F_26 ( V_117 ) ;
if ( ! F_31 ( V_5 , F_41 ( V_5 ) ) ) goto V_108;
if ( F_33 ( F_34 ( V_5 ) , 0 ) == NULL ) goto V_108;
if ( F_33 ( F_35 ( V_5 ) , ( long ) 60 * 60 * 24 * V_37 ) == NULL )
goto V_108;
if ( ! F_36 ( V_5 , V_61 ) ) goto V_108;
if( V_97 ) {
T_8 V_41 ;
F_91 ( V_5 , 2 ) ;
F_92 ( & V_41 , V_5 , V_5 , NULL , NULL , 0 ) ;
F_16 ( & V_41 , V_97 ) ;
if( ! F_17 ( V_97 , & V_41 , V_98 , V_5 ) ) goto V_108;
}
if ( ! F_93 ( V_5 , V_61 , V_46 ) ) goto V_108;
return ( 1 ) ;
V_108:
F_12 ( V_51 ) ;
return ( 0 ) ;
}
