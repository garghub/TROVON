int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
T_1 * V_4 = NULL ;
T_2 * V_5 = NULL , * V_6 = NULL ;
T_3 * V_7 ;
T_4 * V_8 = NULL , * V_9 = NULL ;
int V_10 , V_11 , V_12 = 0 ;
T_5 * V_13 = NULL ;
T_5 * STDout = NULL ;
F_1 ( T_3 ) * V_14 = NULL , * V_15 = NULL ;
int V_16 , V_17 , V_18 , V_19 , V_20 ;
char * V_21 = NULL , * V_22 = NULL , * V_23 = NULL , * V_24 = NULL ;
char * V_25 = NULL , * V_26 = NULL ;
char * V_27 = NULL ;
int V_28 = 0 , V_29 = 0 , V_30 = 0 , V_31 = 0 , V_32 = 0 , V_33 = 0 , V_34 = 0 ;
int V_35 = 0 , V_36 = 0 , V_37 = 0 , V_38 = 0 ;
int V_39 = 0 , V_40 = 0 , V_41 = 0 , V_42 = 0 , V_43 = 0 ;
int V_44 = 0 ;
int V_45 = 0 , V_46 = V_47 , V_48 = 0 , V_49 = 0 ;
int V_50 = 0 ;
char * * V_51 ;
T_6 * V_52 = NULL ;
T_1 * V_53 = NULL ;
int V_54 = 0 ;
char V_55 [ 256 ] ;
const T_7 * V_56 , * V_57 = F_2 () ;
T_8 * V_58 = NULL ;
char * V_59 = NULL , * V_60 = NULL , * V_61 = NULL , * V_62 = NULL ;
int V_63 = 0 ;
V_64 = 0 ;
F_3 () ;
if ( V_65 == NULL )
V_65 = F_4 ( V_66 , V_67 ) ;
STDout = F_4 ( stdout , V_67 ) ;
V_16 = V_68 ;
V_17 = V_68 ;
V_18 = V_68 ;
V_19 = V_68 ;
V_20 = V_68 ;
V_52 = F_5 () ;
if ( V_52 == NULL ) goto V_69;
F_6 ( V_52 , V_70 ) ;
V_1 -- ;
V_2 ++ ;
V_11 = 0 ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_16 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_17 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_18 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
V_64 = 1 ;
V_63 = 1 ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_19 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_19 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_46 = atoi ( * ( ++ V_2 ) ) ;
if ( V_46 == 0 )
{
F_8 ( STDout , L_8 ) ;
goto V_71;
}
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_62 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_60 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_59 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_22 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_23 = * ( ++ V_2 ) ;
V_36 = ++ V_11 ;
V_63 = 1 ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_24 = * ( ++ V_2 ) ;
V_37 = ++ V_11 ;
V_63 = 1 ;
}
else if ( strcmp ( * V_2 , L_16 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_25 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_17 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_26 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_18 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
if( ! ( V_7 = F_9 ( * ( ++ V_2 ) , 0 ) ) ) {
F_8 ( V_65 ,
L_19 , * V_2 ) ;
goto V_71;
}
if( ! V_14 ) V_14 = F_10 () ;
F_11 ( V_14 , V_7 ) ;
V_39 = 1 ;
}
else if ( strcmp ( * V_2 , L_20 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
if( ! ( V_7 = F_9 ( * ( ++ V_2 ) , 0 ) ) ) {
F_8 ( V_65 ,
L_21 , * V_2 ) ;
goto V_71;
}
if( ! V_15 ) V_15 = F_10 () ;
F_11 ( V_15 , V_7 ) ;
V_39 = 1 ;
}
else if ( strcmp ( * V_2 , L_22 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_27 = * ( ++ V_2 ) ;
V_39 = 1 ;
}
else if ( strcmp ( * V_2 , L_22 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_71;
V_27 = * ( ++ V_2 ) ;
V_39 = 1 ;
}
else if ( strcmp ( * V_2 , L_23 ) == 0 )
V_44 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_24 ) == 0 )
V_29 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_25 ) == 0 )
V_48 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_26 ) == 0 )
V_49 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_27 ) == 0 )
V_45 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_28 ) == 0 )
V_28 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_29 ) == 0 )
V_30 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_30 ) == 0 )
V_31 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_31 ) == 0 )
V_32 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_32 ) == 0 )
V_54 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_33 ) == 0 )
{
V_33 = ++ V_11 ;
V_34 = ++ V_11 ;
}
else if ( strcmp ( * V_2 , L_34 ) == 0 )
V_50 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_35 ) == 0 )
V_33 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_36 ) == 0 )
V_34 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_37 ) == 0 )
V_35 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_38 ) == 0 )
V_39 = 1 ;
else if ( strcmp ( * V_2 , L_39 ) == 0 )
V_40 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_40 ) == 0 )
V_41 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_41 ) == 0 )
V_42 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_42 ) == 0 )
V_38 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_43 ) == 0 )
V_43 = 1 ;
else if ( ( V_56 = F_12 ( * V_2 + 1 ) ) )
{
V_57 = V_56 ;
}
else
{
F_8 ( V_65 , L_44 , * V_2 ) ;
V_12 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_12 )
{
V_71:
for ( V_51 = V_72 ; ( * V_51 != NULL ) ; V_51 ++ )
F_8 ( V_65 , * V_51 ) ;
goto V_69;
}
if ( V_63 )
F_13 ( NULL , V_65 , 0 ) ;
F_14 () ;
if( ! F_15 ( V_65 , V_62 , NULL , & V_61 , NULL ) ) {
F_8 ( V_65 , L_45 ) ;
goto V_69;
}
if ( ! F_16 ( V_52 ) )
{
F_17 ( V_65 ) ;
goto V_69;
}
if ( ( V_25 == NULL ) && ( V_37 ) && ( V_19 == V_68 ) )
{ V_25 = V_24 ; }
else if ( ( V_37 ) && ( V_25 == NULL ) )
{
F_8 ( V_65 , L_46 ) ;
goto V_69;
}
if ( V_60 ) {
long V_73 ;
T_9 V_74 ;
if ( ! ( V_58 = F_18 ( NULL , V_60 , & V_73 ) ) ) {
if ( V_73 <= 0 )
F_8 ( V_65 ,
L_47 ,
V_60 ) ;
else
F_8 ( V_65 ,
L_48
, V_73 , V_60 ) ;
goto V_69;
}
if( ! V_59 && ! ( V_59 = F_19 ( V_58 , L_49 ,
L_50 ) ) ) V_59 = L_49 ;
F_20 ( & V_74 ) ;
F_21 ( & V_74 , V_58 ) ;
if( ! F_22 ( V_58 , & V_74 , V_59 , NULL ) ) {
F_8 ( V_65 ,
L_51 ,
V_59 ) ;
F_17 ( V_65 ) ;
goto V_69;
}
}
if ( V_64 )
{
T_4 * V_75 ;
T_10 * V_76 ;
T_5 * V_77 ;
if ( ! V_36 && ! V_37 )
{
F_8 ( V_65 , L_52 ) ;
goto V_69;
}
V_77 = F_23 ( F_24 () ) ;
if ( V_77 == NULL )
{
F_17 ( V_65 ) ;
goto V_69;
}
if ( V_21 == NULL )
F_25 ( V_77 , V_78 , V_67 | V_79 ) ;
else
{
if ( F_26 ( V_77 , V_21 ) <= 0 )
{
perror ( V_21 ) ;
goto V_69;
}
}
V_4 = F_27 ( V_77 , NULL , NULL , NULL ) ;
F_28 ( V_77 ) ;
if ( V_4 == NULL ) { perror ( V_21 ) ; goto V_69; }
if ( ( V_4 -> V_80 == NULL ) ||
( V_4 -> V_80 -> V_49 == NULL ) ||
( V_4 -> V_80 -> V_49 -> V_81 == NULL ) ||
( V_4 -> V_80 -> V_49 -> V_81 -> V_82 == NULL ) )
{
F_8 ( V_65 , L_53 ) ;
F_8 ( V_65 , L_54 ) ;
goto V_69;
}
if ( ( V_75 = F_29 ( V_4 ) ) == NULL )
{
F_8 ( V_65 , L_55 ) ;
goto V_69;
}
V_10 = F_30 ( V_4 , V_75 ) ;
F_31 ( V_75 ) ;
if ( V_10 < 0 )
{
F_8 ( V_65 , L_56 ) ;
F_17 ( V_65 ) ;
goto V_69;
}
if ( V_10 == 0 )
{
F_8 ( V_65 , L_57 ) ;
goto V_69;
}
else
F_8 ( V_65 , L_58 ) ;
F_32 ( V_4 -> V_80 -> V_31 , V_55 , 256 ) ;
F_8 ( V_65 , L_59 , V_55 ) ;
if ( ( V_5 = F_33 () ) == NULL ) goto V_69;
V_76 = V_5 -> V_83 ;
if ( ! F_34 ( F_35 ( V_5 ) , 0 ) ) goto V_69;
if ( ! F_36 ( V_5 , V_4 -> V_80 -> V_31 ) ) goto V_69;
if ( ! F_37 ( V_5 , V_4 -> V_80 -> V_31 ) ) goto V_69;
F_38 ( F_39 ( V_5 ) , 0 ) ;
F_38 ( F_40 ( V_5 ) , ( long ) 60 * 60 * 24 * V_46 ) ;
V_75 = F_29 ( V_4 ) ;
F_41 ( V_5 , V_75 ) ;
F_31 ( V_75 ) ;
}
else
V_5 = F_42 ( V_21 , V_16 ) ;
if ( V_5 == NULL ) goto V_69;
if ( V_37 )
{
V_6 = F_42 ( V_24 , V_19 ) ;
if ( V_6 == NULL ) goto V_69;
}
if ( ! V_35 || V_28 )
{
F_43 ( L_60 ,
L_61 , L_62 ) ;
V_13 = F_23 ( F_24 () ) ;
if ( V_13 == NULL )
{
F_17 ( V_65 ) ;
goto V_69;
}
if ( V_22 == NULL )
F_25 ( V_13 , stdout , V_67 ) ;
else
{
if ( F_44 ( V_13 , V_22 ) <= 0 )
{
perror ( V_22 ) ;
goto V_69;
}
}
}
if( V_27 ) F_45 ( V_5 , ( unsigned char * ) V_27 , - 1 ) ;
if( V_40 ) F_46 ( V_5 ) ;
if( V_41 ) F_47 ( V_5 ) ;
if( V_14 ) {
for( V_10 = 0 ; V_10 < F_48 ( V_14 ) ; V_10 ++ ) {
V_7 = F_49 ( V_14 , V_10 ) ;
F_50 ( V_5 , V_7 ) ;
}
}
if( V_15 ) {
for( V_10 = 0 ; V_10 < F_48 ( V_15 ) ; V_10 ++ ) {
V_7 = F_49 ( V_15 , V_10 ) ;
F_51 ( V_5 , V_7 ) ;
}
}
if ( V_11 )
{
for ( V_10 = 1 ; V_10 <= V_11 ; V_10 ++ )
{
if ( V_32 == V_10 )
{
F_32 ( F_52 ( V_5 ) ,
V_55 , 256 ) ;
F_8 ( STDout , L_63 , V_55 ) ;
}
else if ( V_31 == V_10 )
{
F_32 ( F_53 ( V_5 ) ,
V_55 , 256 ) ;
F_8 ( STDout , L_59 , V_55 ) ;
}
else if ( V_29 == V_10 )
{
F_8 ( STDout , L_64 ) ;
F_54 ( STDout , V_5 -> V_83 -> V_84 ) ;
F_8 ( STDout , L_65 ) ;
}
else if ( V_42 == V_10 )
{
unsigned char * V_85 ;
V_85 = F_55 ( V_5 , NULL ) ;
if( V_85 ) F_8 ( STDout , L_66 , V_85 ) ;
else F_56 ( STDout , L_67 ) ;
}
else if ( V_30 == V_10 )
{
F_8 ( STDout , L_68 , F_57 ( V_5 ) ) ;
}
else if ( V_50 == V_10 )
{
T_11 * V_86 ;
int V_87 ;
F_8 ( STDout , L_69 ) ;
for( V_87 = 0 ; V_87 < F_58 () ; V_87 ++ )
{
V_86 = F_59 ( V_87 ) ;
F_60 ( STDout , V_5 , V_86 ) ;
}
}
else
if ( V_48 == V_10 )
{
T_4 * V_75 ;
V_75 = F_61 ( V_5 ) ;
if ( V_75 == NULL )
{
F_8 ( V_65 , L_70 ) ;
F_17 ( V_65 ) ;
goto V_69;
}
F_8 ( STDout , L_71 ) ;
#ifndef F_62
if ( V_75 -> type == V_88 )
F_63 ( STDout , V_75 -> V_75 . V_89 -> V_90 ) ;
else
#endif
#ifndef F_64
if ( V_75 -> type == V_91 )
F_63 ( STDout , V_75 -> V_75 . V_92 -> V_93 ) ;
else
#endif
F_8 ( STDout , L_72 ) ;
F_8 ( STDout , L_65 ) ;
F_31 ( V_75 ) ;
}
else
if ( V_49 == V_10 )
{
T_4 * V_75 ;
V_75 = F_61 ( V_5 ) ;
if ( V_75 == NULL )
{
F_8 ( V_65 , L_73 ) ;
F_17 ( V_65 ) ;
goto V_69;
}
F_65 ( STDout , V_75 ) ;
F_31 ( V_75 ) ;
}
else
if ( V_44 == V_10 )
{
unsigned char * V_94 ;
char * V_95 ;
int V_96 , V_97 ;
F_32 ( F_53 ( V_5 ) ,
V_55 , 256 ) ;
F_8 ( STDout , L_74 , V_55 ) ;
V_95 = F_32 (
F_52 ( V_5 ) , V_55 , 256 ) ;
F_8 ( STDout , L_75 , V_55 ) ;
V_97 = F_66 ( V_5 , NULL ) ;
V_95 = Malloc ( V_97 ) ;
V_94 = ( unsigned char * ) V_95 ;
V_97 = F_67 ( F_53 ( V_5 ) , & V_94 ) ;
F_8 ( STDout , L_76 , V_97 ) ;
V_94 = ( unsigned char * ) V_95 ;
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ )
{
F_8 ( STDout , L_77 , V_94 [ V_96 ] ) ;
if ( ( V_96 & 0x0f ) == 0x0f ) F_8 ( STDout , L_65 ) ;
}
if ( V_96 % 16 != 0 ) F_8 ( STDout , L_65 ) ;
F_8 ( STDout , L_78 ) ;
V_97 = F_68 ( F_69 ( V_5 ) , & V_94 ) ;
F_8 ( STDout , L_79 , V_97 ) ;
V_94 = ( unsigned char * ) V_95 ;
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ )
{
F_8 ( STDout , L_77 , V_94 [ V_96 ] ) ;
if ( ( V_96 & 0x0f ) == 0x0f )
F_8 ( STDout , L_65 ) ;
}
if ( V_96 % 16 != 0 ) F_8 ( STDout , L_65 ) ;
F_8 ( STDout , L_78 ) ;
V_97 = F_66 ( V_5 , & V_94 ) ;
F_8 ( STDout , L_80 , V_97 ) ;
V_94 = ( unsigned char * ) V_95 ;
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ )
{
F_8 ( STDout , L_77 , V_94 [ V_96 ] ) ;
if ( ( V_96 & 0x0f ) == 0x0f )
F_8 ( STDout , L_65 ) ;
}
if ( V_96 % 16 != 0 ) F_8 ( STDout , L_65 ) ;
F_8 ( STDout , L_78 ) ;
Free ( V_95 ) ;
}
else if ( V_28 == V_10 )
{
F_70 ( V_13 , V_5 ) ;
}
else if ( V_33 == V_10 )
{
F_56 ( STDout , L_81 ) ;
F_71 ( STDout , F_39 ( V_5 ) ) ;
F_56 ( STDout , L_65 ) ;
}
else if ( V_34 == V_10 )
{
F_56 ( STDout , L_82 ) ;
F_71 ( STDout , F_40 ( V_5 ) ) ;
F_56 ( STDout , L_65 ) ;
}
else if ( V_54 == V_10 )
{
int V_87 ;
unsigned int V_90 ;
unsigned char V_98 [ V_99 ] ;
if ( ! F_72 ( V_5 , V_57 , V_98 , & V_90 ) )
{
F_8 ( V_65 , L_83 ) ;
goto V_69;
}
F_8 ( STDout , L_84 ,
F_73 ( F_74 ( V_57 ) ) ) ;
for ( V_87 = 0 ; V_87 < ( int ) V_90 ; V_87 ++ )
{
F_8 ( STDout , L_85 , V_98 [ V_87 ] ,
( V_87 + 1 == ( int ) V_90 )
? '\n' : ':' ) ;
}
}
else if ( ( V_36 == V_10 ) && ( V_45 == 0 ) )
{
F_8 ( V_65 , L_86 ) ;
if ( V_8 == NULL )
{
V_8 = F_75 ( V_23 , V_18 , V_61 ) ;
if ( V_8 == NULL ) goto V_69;
}
#ifndef F_64
if ( V_8 -> type == V_91 )
V_57 = F_76 () ;
#endif
assert ( V_63 ) ;
if ( ! F_77 ( V_5 , V_8 , V_46 , V_43 , V_57 ,
V_58 , V_59 ) ) goto V_69;
}
else if ( V_37 == V_10 )
{
F_8 ( V_65 , L_87 ) ;
if ( V_25 != NULL )
{
V_9 = F_75 ( V_25 , V_20 , V_61 ) ;
if ( V_9 == NULL ) goto V_69;
}
#ifndef F_64
if ( V_9 -> type == V_91 )
V_57 = F_76 () ;
#endif
assert ( V_63 ) ;
if ( ! F_78 ( V_52 , V_24 , V_57 , V_5 , V_6 ,
V_9 , V_26 , V_38 , V_46 , V_43 ,
V_58 , V_59 ) )
goto V_69;
}
else if ( V_45 == V_10 )
{
T_4 * V_100 ;
F_8 ( V_65 , L_88 ) ;
if ( V_23 == NULL )
{
F_8 ( V_65 , L_89 ) ;
goto V_69;
}
else
{
V_100 = F_75 ( V_23 , V_68 , V_61 ) ;
if ( V_100 == NULL ) goto V_69;
}
F_8 ( V_65 , L_90 ) ;
if ( V_100 -> type == V_91 )
V_57 = F_76 () ;
V_53 = F_79 ( V_5 , V_100 , V_57 ) ;
F_31 ( V_100 ) ;
if ( V_53 == NULL )
{
F_17 ( V_65 ) ;
goto V_69;
}
if ( ! V_35 )
{
F_80 ( V_13 , V_53 ) ;
F_81 ( V_13 , V_53 ) ;
}
V_35 = 1 ;
}
}
}
if ( V_35 )
{
V_3 = 0 ;
goto V_69;
}
if ( V_17 == V_101 )
V_10 = F_82 ( V_13 , V_5 ) ;
else if ( V_17 == V_68 ) {
if( V_39 ) V_10 = F_83 ( V_13 , V_5 ) ;
else V_10 = F_84 ( V_13 , V_5 ) ;
} else if ( V_17 == V_102 )
{
T_12 V_103 ;
T_13 V_104 ;
V_104 . V_82 = ( unsigned char * ) V_105 ;
V_104 . V_106 = strlen ( V_105 ) ;
V_103 . V_107 = & V_104 ;
V_103 . V_82 = ( char * ) V_5 ;
V_103 . V_108 = F_85 () ;
V_10 = F_86 ( V_109 , V_13 , ( unsigned char * ) & V_103 ) ;
}
else {
F_8 ( V_65 , L_91 ) ;
goto V_69;
}
if ( ! V_10 ) {
F_8 ( V_65 , L_92 ) ;
F_17 ( V_65 ) ;
goto V_69;
}
V_3 = 0 ;
V_69:
if ( V_63 )
F_87 ( NULL , V_65 ) ;
F_88 () ;
F_89 ( V_58 ) ;
F_28 ( V_13 ) ;
F_28 ( STDout ) ;
F_90 ( V_52 ) ;
F_91 ( V_4 ) ;
F_92 ( V_5 ) ;
F_92 ( V_6 ) ;
F_31 ( V_8 ) ;
F_31 ( V_9 ) ;
F_91 ( V_53 ) ;
F_93 ( V_14 , V_110 ) ;
F_93 ( V_15 , V_110 ) ;
if( V_61 ) Free ( V_61 ) ;
EXIT ( V_3 ) ;
}
static int F_78 ( T_6 * V_52 , char * V_24 , const T_7 * V_57 ,
T_2 * V_5 , T_2 * V_6 , T_4 * V_75 , char * V_111 , int V_112 ,
int V_46 , int V_43 , T_8 * V_113 , char * V_114 )
{
int V_3 = 0 ;
T_5 * V_115 = NULL ;
T_14 char V_116 [ 1024 ] ;
char * V_55 = NULL , * V_117 ;
T_15 * V_29 = NULL ;
T_16 * V_118 = NULL , V_119 ;
T_17 V_120 ;
T_4 * V_121 ;
V_121 = F_61 ( V_6 ) ;
F_94 ( V_121 , V_75 ) ;
F_31 ( V_121 ) ;
F_95 ( & V_120 , V_52 , V_5 , NULL ) ;
V_55 = Malloc ( F_96 ( V_75 ) * 2 +
( ( V_111 == NULL )
? ( strlen ( V_24 ) + strlen ( V_122 ) + 1 )
: ( strlen ( V_111 ) ) ) + 1 ) ;
if ( V_55 == NULL ) { F_8 ( V_65 , L_93 ) ; goto V_69; }
if ( V_111 == NULL )
{
strcpy ( V_55 , V_24 ) ;
for ( V_117 = V_55 ; * V_117 ; V_117 ++ )
if ( * V_117 == '.' )
{
* V_117 = '\0' ;
break;
}
strcat ( V_55 , V_122 ) ;
}
else
strcpy ( V_55 , V_111 ) ;
V_29 = F_97 () ;
V_118 = F_98 () ;
if ( ( V_29 == NULL ) || ( V_118 == NULL ) )
{
F_17 ( V_65 ) ;
goto V_69;
}
V_115 = F_23 ( F_24 () ) ;
if ( V_115 == NULL )
{
F_17 ( V_65 ) ;
goto V_69;
}
if ( F_26 ( V_115 , V_55 ) <= 0 )
{
if ( ! V_112 )
{
perror ( V_55 ) ;
goto V_69;
}
else
{
F_34 ( V_118 , 1 ) ;
F_99 ( V_29 ) ;
}
}
else
{
if ( ! F_100 ( V_115 , V_118 , V_116 , 1024 ) )
{
F_8 ( V_65 , L_94 , V_55 ) ;
F_17 ( V_65 ) ;
goto V_69;
}
else
{
V_29 = F_101 ( V_118 -> V_82 , V_118 -> V_106 , V_29 ) ;
if ( V_29 == NULL )
{
F_8 ( V_65 , L_95 ) ;
goto V_69;
}
}
}
if ( ! F_102 ( V_29 , 1 ) )
{ F_8 ( V_65 , L_96 ) ; goto V_69; }
V_119 . V_82 = ( unsigned char * ) V_116 ;
V_119 . V_106 = F_103 ( V_29 , V_119 . V_82 ) ;
if ( F_44 ( V_115 , V_55 ) <= 0 )
{
F_8 ( V_65 , L_97 ) ;
perror ( V_55 ) ;
goto V_69;
}
F_54 ( V_115 , & V_119 ) ;
F_56 ( V_115 , L_65 ) ;
F_28 ( V_115 ) ;
V_115 = NULL ;
if ( ! F_104 ( V_52 , V_5 ) ) goto V_69;
F_105 ( & V_120 , V_5 ) ;
if ( ! V_64 && ! F_106 ( & V_120 ) )
goto V_69;
if ( ! F_107 ( V_6 , V_75 ) )
{
F_8 ( V_65 , L_98 ) ;
goto V_69;
}
if ( ! F_36 ( V_5 , F_53 ( V_6 ) ) ) goto V_69;
if ( ! F_108 ( V_5 , V_118 ) ) goto V_69;
if ( F_38 ( F_39 ( V_5 ) , 0L ) == NULL )
goto V_69;
if ( F_38 ( F_40 ( V_5 ) , ( long ) 60 * 60 * 24 * V_46 ) == NULL )
goto V_69;
if( V_43 ) {
while( F_109 ( V_5 ) > 0 ) F_110 ( V_5 , 0 ) ;
}
if( V_113 ) {
T_9 V_74 ;
F_111 ( V_5 , 2 ) ;
F_112 ( & V_74 , V_6 , V_5 , NULL , NULL , 0 ) ;
F_21 ( & V_74 , V_113 ) ;
if( ! F_22 ( V_113 , & V_74 , V_114 , V_5 ) ) goto V_69;
}
if ( ! F_113 ( V_5 , V_75 , V_57 ) ) goto V_69;
V_3 = 1 ;
V_69:
F_114 ( & V_120 ) ;
if ( ! V_3 )
F_17 ( V_65 ) ;
if ( V_55 != NULL ) Free ( V_55 ) ;
if ( V_118 != NULL ) F_115 ( V_118 ) ;
if ( V_115 != NULL ) F_28 ( V_115 ) ;
if ( V_29 != NULL ) F_116 ( V_29 ) ;
return ( V_3 ) ;
}
static int T_18 V_70 ( int V_123 , T_17 * V_52 )
{
char V_55 [ 256 ] ;
int V_124 ;
T_2 * V_125 ;
V_124 = F_117 ( V_52 ) ;
if ( V_124 == V_126 )
return ( 1 ) ;
if ( V_123 )
{
F_8 ( V_65 , L_99 ) ;
return ( 0 ) ;
}
else
{
V_125 = F_118 ( V_52 ) ;
F_32 ( F_53 ( V_125 ) , V_55 , 256 ) ;
F_8 ( V_65 , L_66 , V_55 ) ;
F_8 ( V_65 , L_100 ,
V_124 , F_119 ( V_52 ) ,
F_120 ( V_124 ) ) ;
return ( 1 ) ;
}
}
static T_4 * F_75 ( char * V_127 , int V_128 , char * V_61 )
{
T_5 * V_129 = NULL ;
T_4 * V_75 = NULL ;
if ( V_127 == NULL )
{
F_8 ( V_65 , L_101 ) ;
goto V_69;
}
V_129 = F_23 ( F_24 () ) ;
if ( V_129 == NULL )
{
F_17 ( V_65 ) ;
goto V_69;
}
if ( F_26 ( V_129 , V_127 ) <= 0 )
{
perror ( V_127 ) ;
goto V_69;
}
if ( V_128 == V_101 )
{
V_75 = F_121 ( V_129 , NULL ) ;
}
else if ( V_128 == V_68 )
{
V_75 = F_122 ( V_129 , NULL , NULL , V_61 ) ;
}
else
{
F_8 ( V_65 , L_102 ) ;
goto V_69;
}
V_69:
if ( V_129 != NULL ) F_28 ( V_129 ) ;
if ( V_75 == NULL )
F_8 ( V_65 , L_103 ) ;
return ( V_75 ) ;
}
static T_2 * F_42 ( char * V_127 , int V_128 )
{
T_12 * V_103 = NULL ;
T_19 * V_55 = NULL ;
T_2 * V_5 = NULL ;
T_5 * V_130 ;
if ( ( V_130 = F_23 ( F_24 () ) ) == NULL )
{
F_17 ( V_65 ) ;
goto V_69;
}
if ( V_127 == NULL )
F_25 ( V_130 , V_78 , V_67 ) ;
else
{
if ( F_26 ( V_130 , V_127 ) <= 0 )
{
perror ( V_127 ) ;
goto V_69;
}
}
if ( V_128 == V_101 )
V_5 = F_123 ( V_130 , NULL ) ;
else if ( V_128 == V_102 )
{
unsigned char * V_117 , * V_131 ;
int V_132 = 0 , V_10 ;
V_55 = F_124 () ;
for (; ; )
{
if ( ( V_55 == NULL ) || ( ! F_125 ( V_55 , V_132 + 1024 * 10 ) ) )
goto V_69;
V_10 = F_126 ( V_130 , & ( V_55 -> V_82 [ V_132 ] ) , 1024 * 10 ) ;
V_132 += V_10 ;
if ( V_10 == 0 ) break;
if ( V_10 < 0 )
{
perror ( L_104 ) ;
goto V_69;
}
}
V_117 = ( unsigned char * ) V_55 -> V_82 ;
V_131 = V_117 ;
if ( ( V_103 = F_127 ( NULL , & V_117 , ( long ) V_132 ) ) == NULL )
goto V_69;
if ( ( V_103 -> V_107 == NULL ) || ( V_103 -> V_107 -> V_82 == NULL ) ||
( strncmp ( V_105 , ( char * ) V_103 -> V_107 -> V_82 ,
V_103 -> V_107 -> V_106 ) != 0 ) )
{
F_8 ( V_65 , L_105 ) ;
goto V_69;
}
V_117 = V_131 ;
V_103 -> V_108 = F_85 () ;
if ( ( V_103 = F_127 ( & V_103 , & V_117 , ( long ) V_132 ) ) == NULL )
goto V_69;
V_5 = ( T_2 * ) V_103 -> V_82 ;
V_103 -> V_82 = NULL ;
}
else if ( V_128 == V_68 )
V_5 = F_128 ( V_130 , NULL , NULL , NULL ) ;
else {
F_8 ( V_65 , L_106 ) ;
goto V_69;
}
V_69:
if ( V_5 == NULL )
{
F_8 ( V_65 , L_107 ) ;
F_17 ( V_65 ) ;
}
if ( V_103 != NULL ) F_129 ( V_103 ) ;
if ( V_130 != NULL ) F_28 ( V_130 ) ;
if ( V_55 != NULL ) F_130 ( V_55 ) ;
return ( V_5 ) ;
}
static int F_77 ( T_2 * V_5 , T_4 * V_75 , int V_46 , int V_43 , const T_7 * V_57 ,
T_8 * V_113 , char * V_114 )
{
T_4 * V_133 ;
V_133 = F_61 ( V_5 ) ;
F_94 ( V_133 , V_75 ) ;
F_131 ( V_133 , 1 ) ;
F_31 ( V_133 ) ;
if ( ! F_36 ( V_5 , F_53 ( V_5 ) ) ) goto V_124;
if ( F_38 ( F_39 ( V_5 ) , 0 ) == NULL ) goto V_124;
if ( F_38 ( F_40 ( V_5 ) , ( long ) 60 * 60 * 24 * V_46 ) == NULL )
goto V_124;
if ( ! F_41 ( V_5 , V_75 ) ) goto V_124;
if( V_43 ) {
while( F_109 ( V_5 ) > 0 ) F_110 ( V_5 , 0 ) ;
}
if( V_113 ) {
T_9 V_52 ;
F_111 ( V_5 , 2 ) ;
F_112 ( & V_52 , V_5 , V_5 , NULL , NULL , 0 ) ;
F_21 ( & V_52 , V_113 ) ;
if( ! F_22 ( V_113 , & V_52 , V_114 , V_5 ) ) goto V_124;
}
if ( ! F_113 ( V_5 , V_75 , V_57 ) ) goto V_124;
return ( 1 ) ;
V_124:
F_17 ( V_65 ) ;
return ( 0 ) ;
}
static int F_60 ( T_5 * V_134 , T_2 * V_130 , T_11 * V_135 )
{
int V_136 , V_10 , V_137 ;
char * V_138 ;
V_136 = F_132 ( V_135 ) ;
V_138 = F_133 ( V_135 ) ;
for( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
V_137 = F_134 ( V_130 , V_136 , V_10 ) ;
F_8 ( V_134 , L_108 , V_138 , V_10 ? L_109 : L_110 ) ;
if( V_137 == 1 ) F_8 ( V_134 , L_111 ) ;
else if ( V_137 == 0 ) F_8 ( V_134 , L_112 ) ;
else F_8 ( V_134 , L_113 , V_137 ) ;
}
return 1 ;
}
