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
int V_35 = 0 , V_36 = 0 , V_37 = 0 , V_38 = 0 , V_39 = 0 ;
int V_40 = 0 , V_41 = 0 , V_42 = 0 , V_43 = 0 , V_44 = 0 ;
int V_45 = 0 ;
int V_46 = 0 , V_47 = V_48 , V_49 = 0 , V_50 = 0 ;
int V_51 = 0 ;
char * * V_52 ;
T_6 * V_53 = NULL ;
T_1 * V_54 = NULL ;
int V_55 = 0 ;
char V_56 [ 256 ] ;
const T_7 * V_57 , * V_58 = F_2 () ;
T_8 * V_59 = NULL ;
char * V_60 = NULL , * V_61 = NULL , * V_62 = NULL , * V_63 = NULL ;
int V_64 = 0 ;
int V_65 = 0 , V_66 = 0 ;
unsigned long V_67 = 0 ;
V_68 = 0 ;
F_3 () ;
if ( V_69 == NULL )
V_69 = F_4 ( V_70 , V_71 ) ;
STDout = F_4 ( stdout , V_71 ) ;
#ifdef F_5
{
T_5 * V_72 = F_6 ( F_7 () ) ;
STDout = F_8 ( V_72 , STDout ) ;
}
#endif
V_16 = V_73 ;
V_17 = V_73 ;
V_18 = V_73 ;
V_19 = V_73 ;
V_20 = V_73 ;
V_53 = F_9 () ;
if ( V_53 == NULL ) goto V_74;
F_10 ( V_53 , V_75 ) ;
V_1 -- ;
V_2 ++ ;
V_11 = 0 ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_16 = F_11 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_17 = F_11 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_18 = F_11 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
V_68 = 1 ;
V_64 = 1 ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_19 = F_11 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_19 = F_11 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_47 = atoi ( * ( ++ V_2 ) ) ;
if ( V_47 == 0 )
{
F_12 ( STDout , L_8 ) ;
goto V_76;
}
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_63 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_61 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_60 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_22 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_23 = * ( ++ V_2 ) ;
V_36 = ++ V_11 ;
V_64 = 1 ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_24 = * ( ++ V_2 ) ;
V_37 = ++ V_11 ;
V_64 = 1 ;
}
else if ( strcmp ( * V_2 , L_16 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_25 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_17 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_26 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_18 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
if ( ! ( V_7 = F_13 ( * ( ++ V_2 ) , 0 ) ) )
{
F_12 ( V_69 ,
L_19 , * V_2 ) ;
goto V_76;
}
if ( ! V_14 ) V_14 = F_14 () ;
F_15 ( V_14 , V_7 ) ;
V_40 = 1 ;
}
else if ( strcmp ( * V_2 , L_20 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
if ( ! ( V_7 = F_13 ( * ( ++ V_2 ) , 0 ) ) )
{
F_12 ( V_69 ,
L_21 , * V_2 ) ;
goto V_76;
}
if ( ! V_15 ) V_15 = F_14 () ;
F_15 ( V_15 , V_7 ) ;
V_40 = 1 ;
}
else if ( strcmp ( * V_2 , L_22 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_27 = * ( ++ V_2 ) ;
V_40 = 1 ;
}
else if ( strcmp ( * V_2 , L_23 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
if ( ! F_16 ( & V_67 , * ( ++ V_2 ) ) ) goto V_76;
}
else if ( strcmp ( * V_2 , L_22 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_27 = * ( ++ V_2 ) ;
V_40 = 1 ;
}
else if ( strcmp ( * V_2 , L_24 ) == 0 )
V_45 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_25 ) == 0 )
V_39 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_26 ) == 0 )
V_29 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_27 ) == 0 )
V_49 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_28 ) == 0 )
V_50 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_29 ) == 0 )
V_46 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_30 ) == 0 )
V_28 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_31 ) == 0 )
V_30 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_32 ) == 0 )
V_31 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_33 ) == 0 )
V_32 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_34 ) == 0 )
V_55 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_35 ) == 0 )
{
V_33 = ++ V_11 ;
V_34 = ++ V_11 ;
}
else if ( strcmp ( * V_2 , L_36 ) == 0 )
V_51 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_37 ) == 0 )
V_33 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_38 ) == 0 )
V_34 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_39 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_76;
V_66 = atoi ( * ( ++ V_2 ) ) ;
V_65 = 1 ;
}
else if ( strcmp ( * V_2 , L_40 ) == 0 )
V_35 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_41 ) == 0 )
V_40 = 1 ;
else if ( strcmp ( * V_2 , L_42 ) == 0 )
V_41 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_43 ) == 0 )
V_42 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_44 ) == 0 )
V_43 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_45 ) == 0 )
V_38 = ++ V_11 ;
else if ( strcmp ( * V_2 , L_46 ) == 0 )
V_44 = 1 ;
#if 1
else if ( strcmp ( * V_2 , L_47 ) == 0 )
{
F_12 ( V_69 , L_48 ) ;
V_44 = 1 ;
}
#endif
else if ( ( V_57 = F_17 ( * V_2 + 1 ) ) )
{
V_58 = V_57 ;
}
else
{
F_12 ( V_69 , L_49 , * V_2 ) ;
V_12 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_12 )
{
V_76:
for ( V_52 = V_77 ; ( * V_52 != NULL ) ; V_52 ++ )
F_12 ( V_69 , * V_52 ) ;
goto V_74;
}
if ( V_64 )
F_18 ( NULL , V_69 , 0 ) ;
F_19 () ;
if ( ! F_20 ( V_69 , V_63 , NULL , & V_62 , NULL ) )
{
F_12 ( V_69 , L_50 ) ;
goto V_74;
}
if ( ! F_21 ( V_53 ) )
{
F_22 ( V_69 ) ;
goto V_74;
}
if ( ( V_25 == NULL ) && ( V_37 ) && ( V_19 == V_73 ) )
{ V_25 = V_24 ; }
else if ( ( V_37 ) && ( V_25 == NULL ) )
{
F_12 ( V_69 , L_51 ) ;
goto V_74;
}
if ( V_61 )
{
long V_78 ;
T_9 V_79 ;
if ( ! ( V_59 = F_23 ( NULL , V_61 , & V_78 ) ) )
{
if ( V_78 <= 0 )
F_12 ( V_69 ,
L_52 ,
V_61 ) ;
else
F_12 ( V_69 ,
L_53
, V_78 , V_61 ) ;
goto V_74;
}
if ( ! V_60 && ! ( V_60 = F_24 ( V_59 , L_54 ,
L_55 ) ) ) V_60 = L_54 ;
F_25 ( & V_79 ) ;
F_26 ( & V_79 , V_59 ) ;
if ( ! F_27 ( V_59 , & V_79 , V_60 , NULL ) )
{
F_12 ( V_69 ,
L_56 ,
V_60 ) ;
F_22 ( V_69 ) ;
goto V_74;
}
}
if ( V_68 )
{
T_4 * V_80 ;
T_10 * V_81 ;
T_5 * V_82 ;
if ( ! V_36 && ! V_37 )
{
F_12 ( V_69 , L_57 ) ;
goto V_74;
}
V_82 = F_6 ( F_28 () ) ;
if ( V_82 == NULL )
{
F_22 ( V_69 ) ;
goto V_74;
}
if ( V_21 == NULL )
F_29 ( V_82 , V_83 , V_71 | V_84 ) ;
else
{
if ( F_30 ( V_82 , V_21 ) <= 0 )
{
perror ( V_21 ) ;
F_31 ( V_82 ) ;
goto V_74;
}
}
V_4 = F_32 ( V_82 , NULL , NULL , NULL ) ;
F_31 ( V_82 ) ;
if ( V_4 == NULL )
{
F_22 ( V_69 ) ;
goto V_74;
}
if ( ( V_4 -> V_85 == NULL ) ||
( V_4 -> V_85 -> V_50 == NULL ) ||
( V_4 -> V_85 -> V_50 -> V_86 == NULL ) ||
( V_4 -> V_85 -> V_50 -> V_86 -> V_87 == NULL ) )
{
F_12 ( V_69 , L_58 ) ;
F_12 ( V_69 , L_59 ) ;
goto V_74;
}
if ( ( V_80 = F_33 ( V_4 ) ) == NULL )
{
F_12 ( V_69 , L_60 ) ;
goto V_74;
}
V_10 = F_34 ( V_4 , V_80 ) ;
F_35 ( V_80 ) ;
if ( V_10 < 0 )
{
F_12 ( V_69 , L_61 ) ;
F_22 ( V_69 ) ;
goto V_74;
}
if ( V_10 == 0 )
{
F_12 ( V_69 , L_62 ) ;
goto V_74;
}
else
F_12 ( V_69 , L_63 ) ;
F_36 ( V_69 , L_64 , F_37 ( V_4 ) , V_67 ) ;
if ( ( V_5 = F_38 () ) == NULL ) goto V_74;
V_81 = V_5 -> V_88 ;
if ( ! F_39 ( F_40 ( V_5 ) , 0 ) ) goto V_74;
if ( ! F_41 ( V_5 , V_4 -> V_85 -> V_31 ) ) goto V_74;
if ( ! F_42 ( V_5 , V_4 -> V_85 -> V_31 ) ) goto V_74;
F_43 ( F_44 ( V_5 ) , 0 ) ;
F_43 ( F_45 ( V_5 ) , ( long ) 60 * 60 * 24 * V_47 ) ;
V_80 = F_33 ( V_4 ) ;
F_46 ( V_5 , V_80 ) ;
F_35 ( V_80 ) ;
}
else
V_5 = F_47 ( V_69 , V_21 , V_16 ) ;
if ( V_5 == NULL ) goto V_74;
if ( V_37 )
{
V_6 = F_47 ( V_69 , V_24 , V_19 ) ;
if ( V_6 == NULL ) goto V_74;
}
if ( ! V_35 || V_28 )
{
F_48 ( L_65 ,
L_66 , L_67 ) ;
V_13 = F_6 ( F_28 () ) ;
if ( V_13 == NULL )
{
F_22 ( V_69 ) ;
goto V_74;
}
if ( V_22 == NULL )
{
F_29 ( V_13 , stdout , V_71 ) ;
#ifdef F_5
{
T_5 * V_72 = F_6 ( F_7 () ) ;
V_13 = F_8 ( V_72 , V_13 ) ;
}
#endif
}
else
{
if ( F_49 ( V_13 , V_22 ) <= 0 )
{
perror ( V_22 ) ;
goto V_74;
}
}
}
if ( V_27 ) F_50 ( V_5 , ( unsigned char * ) V_27 , - 1 ) ;
if ( V_41 ) F_51 ( V_5 ) ;
if ( V_42 ) F_52 ( V_5 ) ;
if ( V_14 )
{
for ( V_10 = 0 ; V_10 < F_53 ( V_14 ) ; V_10 ++ )
{
V_7 = F_54 ( V_14 , V_10 ) ;
F_55 ( V_5 , V_7 ) ;
}
}
if ( V_15 )
{
for ( V_10 = 0 ; V_10 < F_53 ( V_15 ) ; V_10 ++ )
{
V_7 = F_54 ( V_15 , V_10 ) ;
F_56 ( V_5 , V_7 ) ;
}
}
if ( V_11 )
{
for ( V_10 = 1 ; V_10 <= V_11 ; V_10 ++ )
{
if ( V_32 == V_10 )
{
F_36 ( STDout , L_68 ,
F_57 ( V_5 ) , V_67 ) ;
}
else if ( V_31 == V_10 )
{
F_36 ( STDout , L_69 ,
F_58 ( V_5 ) , V_67 ) ;
}
else if ( V_29 == V_10 )
{
F_12 ( STDout , L_70 ) ;
F_59 ( STDout , V_5 -> V_88 -> V_89 ) ;
F_12 ( STDout , L_71 ) ;
}
else if ( V_39 == V_10 )
{
int V_90 ;
T_11 * V_91 ;
V_91 = F_60 ( V_5 ) ;
for ( V_90 = 0 ; V_90 < F_61 ( V_91 ) ; V_90 ++ )
F_12 ( STDout , L_72 , F_62 ( V_91 , V_90 ) ) ;
F_63 ( V_91 ) ;
}
else if ( V_43 == V_10 )
{
unsigned char * V_92 ;
V_92 = F_64 ( V_5 , NULL ) ;
if ( V_92 ) F_12 ( STDout , L_72 , V_92 ) ;
else F_65 ( STDout , L_73 ) ;
}
else if ( V_30 == V_10 )
{
F_12 ( STDout , L_74 , F_66 ( V_5 ) ) ;
}
else if ( V_51 == V_10 )
{
T_12 * V_93 ;
int V_90 ;
F_12 ( STDout , L_75 ) ;
for ( V_90 = 0 ; V_90 < F_67 () ; V_90 ++ )
{
V_93 = F_68 ( V_90 ) ;
F_69 ( STDout , V_5 , V_93 ) ;
}
}
else
if ( V_49 == V_10 )
{
T_4 * V_80 ;
V_80 = F_70 ( V_5 ) ;
if ( V_80 == NULL )
{
F_12 ( V_69 , L_76 ) ;
F_22 ( V_69 ) ;
goto V_74;
}
F_12 ( STDout , L_77 ) ;
#ifndef F_71
if ( V_80 -> type == V_94 )
F_72 ( STDout , V_80 -> V_80 . V_95 -> V_96 ) ;
else
#endif
#ifndef F_73
if ( V_80 -> type == V_97 )
F_72 ( STDout , V_80 -> V_80 . V_98 -> V_99 ) ;
else
#endif
F_12 ( STDout , L_78 ) ;
F_12 ( STDout , L_71 ) ;
F_35 ( V_80 ) ;
}
else
if ( V_50 == V_10 )
{
T_4 * V_80 ;
V_80 = F_70 ( V_5 ) ;
if ( V_80 == NULL )
{
F_12 ( V_69 , L_79 ) ;
F_22 ( V_69 ) ;
goto V_74;
}
F_74 ( STDout , V_80 ) ;
F_35 ( V_80 ) ;
}
else
if ( V_45 == V_10 )
{
unsigned char * V_100 ;
char * V_101 ;
int V_102 , V_103 ;
F_75 ( F_58 ( V_5 ) ,
V_56 , 256 ) ;
F_12 ( STDout , L_80 , V_56 ) ;
V_101 = F_75 (
F_57 ( V_5 ) , V_56 , 256 ) ;
F_12 ( STDout , L_81 , V_56 ) ;
V_103 = F_76 ( V_5 , NULL ) ;
V_101 = F_77 ( V_103 ) ;
V_100 = ( unsigned char * ) V_101 ;
V_103 = F_78 ( F_58 ( V_5 ) , & V_100 ) ;
F_12 ( STDout , L_82 , V_103 ) ;
V_100 = ( unsigned char * ) V_101 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ )
{
F_12 ( STDout , L_83 , V_100 [ V_102 ] ) ;
if ( ( V_102 & 0x0f ) == 0x0f ) F_12 ( STDout , L_71 ) ;
}
if ( V_102 % 16 != 0 ) F_12 ( STDout , L_71 ) ;
F_12 ( STDout , L_84 ) ;
V_103 = F_79 ( F_80 ( V_5 ) , & V_100 ) ;
F_12 ( STDout , L_85 , V_103 ) ;
V_100 = ( unsigned char * ) V_101 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ )
{
F_12 ( STDout , L_83 , V_100 [ V_102 ] ) ;
if ( ( V_102 & 0x0f ) == 0x0f )
F_12 ( STDout , L_71 ) ;
}
if ( V_102 % 16 != 0 ) F_12 ( STDout , L_71 ) ;
F_12 ( STDout , L_84 ) ;
V_103 = F_76 ( V_5 , & V_100 ) ;
F_12 ( STDout , L_86 , V_103 ) ;
V_100 = ( unsigned char * ) V_101 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ )
{
F_12 ( STDout , L_83 , V_100 [ V_102 ] ) ;
if ( ( V_102 & 0x0f ) == 0x0f )
F_12 ( STDout , L_71 ) ;
}
if ( V_102 % 16 != 0 ) F_12 ( STDout , L_71 ) ;
F_12 ( STDout , L_84 ) ;
F_81 ( V_101 ) ;
}
else if ( V_28 == V_10 )
{
F_82 ( V_13 , V_5 ) ;
}
else if ( V_33 == V_10 )
{
F_65 ( STDout , L_87 ) ;
F_83 ( STDout , F_44 ( V_5 ) ) ;
F_65 ( STDout , L_71 ) ;
}
else if ( V_34 == V_10 )
{
F_65 ( STDout , L_88 ) ;
F_83 ( STDout , F_45 ( V_5 ) ) ;
F_65 ( STDout , L_71 ) ;
}
else if ( V_55 == V_10 )
{
int V_90 ;
unsigned int V_96 ;
unsigned char V_104 [ V_105 ] ;
if ( ! F_84 ( V_5 , V_58 , V_104 , & V_96 ) )
{
F_12 ( V_69 , L_89 ) ;
goto V_74;
}
F_12 ( STDout , L_90 ,
F_85 ( F_86 ( V_58 ) ) ) ;
for ( V_90 = 0 ; V_90 < ( int ) V_96 ; V_90 ++ )
{
F_12 ( STDout , L_91 , V_104 [ V_90 ] ,
( V_90 + 1 == ( int ) V_96 )
? '\n' : ':' ) ;
}
}
else if ( ( V_36 == V_10 ) && ( V_46 == 0 ) )
{
F_12 ( V_69 , L_92 ) ;
if ( V_8 == NULL )
{
V_8 = F_87 ( V_69 ,
V_23 , V_18 , V_62 ) ;
if ( V_8 == NULL ) goto V_74;
}
#ifndef F_73
if ( V_8 -> type == V_97 )
V_58 = F_88 () ;
#endif
assert ( V_64 ) ;
if ( ! F_89 ( V_5 , V_8 , V_47 , V_44 , V_58 ,
V_59 , V_60 ) ) goto V_74;
}
else if ( V_37 == V_10 )
{
F_12 ( V_69 , L_93 ) ;
if ( V_25 != NULL )
{
V_9 = F_87 ( V_69 ,
V_25 , V_20 , V_62 ) ;
if ( V_9 == NULL ) goto V_74;
}
#ifndef F_73
if ( V_9 -> type == V_97 )
V_58 = F_88 () ;
#endif
assert ( V_64 ) ;
if ( ! F_90 ( V_53 , V_24 , V_58 , V_5 , V_6 ,
V_9 , V_26 , V_38 , V_47 , V_44 ,
V_59 , V_60 ) )
goto V_74;
}
else if ( V_46 == V_10 )
{
T_4 * V_106 ;
F_12 ( V_69 , L_94 ) ;
if ( V_23 == NULL )
{
F_12 ( V_69 , L_95 ) ;
goto V_74;
}
else
{
V_106 = F_87 ( V_69 ,
V_23 , V_73 , V_62 ) ;
if ( V_106 == NULL ) goto V_74;
}
F_12 ( V_69 , L_96 ) ;
if ( V_106 -> type == V_97 )
V_58 = F_88 () ;
V_54 = F_91 ( V_5 , V_106 , V_58 ) ;
F_35 ( V_106 ) ;
if ( V_54 == NULL )
{
F_22 ( V_69 ) ;
goto V_74;
}
if ( ! V_35 )
{
F_92 ( V_13 , V_54 ) ;
F_93 ( V_13 , V_54 ) ;
}
V_35 = 1 ;
}
}
}
if ( V_65 )
{
T_13 V_107 = time ( NULL ) ;
if ( F_94 ( F_45 ( V_5 ) , V_107 + V_66 ) == - 1 )
{
F_12 ( V_13 , L_97 ) ;
V_3 = 1 ;
}
else
{
F_12 ( V_13 , L_98 ) ;
V_3 = 0 ;
}
goto V_74;
}
if ( V_35 )
{
V_3 = 0 ;
goto V_74;
}
if ( V_17 == V_108 )
V_10 = F_95 ( V_13 , V_5 ) ;
else if ( V_17 == V_73 )
{
if ( V_40 ) V_10 = F_96 ( V_13 , V_5 ) ;
else V_10 = F_97 ( V_13 , V_5 ) ;
}
else if ( V_17 == V_109 )
{
T_14 V_110 ;
T_15 V_111 ;
V_111 . V_87 = ( unsigned char * ) V_112 ;
V_111 . V_113 = strlen ( V_112 ) ;
V_110 . V_114 = & V_111 ;
V_110 . V_87 = ( char * ) V_5 ;
V_110 . V_115 = F_98 () ;
V_10 = F_99 ( V_116 , V_13 , ( unsigned char * ) & V_110 ) ;
}
else {
F_12 ( V_69 , L_99 ) ;
goto V_74;
}
if ( ! V_10 )
{
F_12 ( V_69 , L_100 ) ;
F_22 ( V_69 ) ;
goto V_74;
}
V_3 = 0 ;
V_74:
if ( V_64 )
F_100 ( NULL , V_69 ) ;
F_101 () ;
F_102 ( V_59 ) ;
F_103 ( V_13 ) ;
F_103 ( STDout ) ;
F_104 ( V_53 ) ;
F_105 ( V_4 ) ;
F_106 ( V_5 ) ;
F_106 ( V_6 ) ;
F_35 ( V_8 ) ;
F_35 ( V_9 ) ;
F_105 ( V_54 ) ;
F_107 ( V_14 , V_117 ) ;
F_107 ( V_15 , V_117 ) ;
if ( V_62 ) F_81 ( V_62 ) ;
EXIT ( V_3 ) ;
}
static int F_90 ( T_6 * V_53 , char * V_24 , const T_7 * V_58 ,
T_2 * V_5 , T_2 * V_6 , T_4 * V_80 , char * V_118 , int V_119 ,
int V_47 , int V_44 , T_8 * V_120 , char * V_121 )
{
int V_3 = 0 ;
T_5 * V_122 = NULL ;
T_16 char V_123 [ 1024 ] ;
char * V_56 = NULL , * V_124 ;
T_17 * V_29 = NULL ;
T_18 * V_125 = NULL , V_126 ;
T_19 V_127 ;
T_4 * V_128 ;
V_128 = F_70 ( V_6 ) ;
F_108 ( V_128 , V_80 ) ;
F_35 ( V_128 ) ;
F_109 ( & V_127 , V_53 , V_5 , NULL ) ;
V_56 = F_77 ( F_110 ( V_80 ) * 2 +
( ( V_118 == NULL )
? ( strlen ( V_24 ) + strlen ( V_129 ) + 1 )
: ( strlen ( V_118 ) ) ) + 1 ) ;
if ( V_56 == NULL ) { F_12 ( V_69 , L_101 ) ; goto V_74; }
if ( V_118 == NULL )
{
strcpy ( V_56 , V_24 ) ;
for ( V_124 = V_56 ; * V_124 ; V_124 ++ )
if ( * V_124 == '.' )
{
* V_124 = '\0' ;
break;
}
strcat ( V_56 , V_129 ) ;
}
else
strcpy ( V_56 , V_118 ) ;
V_29 = F_111 () ;
V_125 = F_112 () ;
if ( ( V_29 == NULL ) || ( V_125 == NULL ) )
{
F_22 ( V_69 ) ;
goto V_74;
}
V_122 = F_6 ( F_28 () ) ;
if ( V_122 == NULL )
{
F_22 ( V_69 ) ;
goto V_74;
}
if ( F_30 ( V_122 , V_56 ) <= 0 )
{
if ( ! V_119 )
{
perror ( V_56 ) ;
goto V_74;
}
else
{
F_39 ( V_125 , 1 ) ;
F_113 ( V_29 ) ;
}
}
else
{
if ( ! F_114 ( V_122 , V_125 , V_123 , 1024 ) )
{
F_12 ( V_69 , L_102 , V_56 ) ;
F_22 ( V_69 ) ;
goto V_74;
}
else
{
V_29 = F_115 ( V_125 -> V_87 , V_125 -> V_113 , V_29 ) ;
if ( V_29 == NULL )
{
F_12 ( V_69 , L_103 ) ;
goto V_74;
}
}
}
if ( ! F_116 ( V_29 , 1 ) )
{ F_12 ( V_69 , L_104 ) ; goto V_74; }
V_126 . V_87 = ( unsigned char * ) V_123 ;
V_126 . V_113 = F_117 ( V_29 , V_126 . V_87 ) ;
if ( F_49 ( V_122 , V_56 ) <= 0 )
{
F_12 ( V_69 , L_105 ) ;
perror ( V_56 ) ;
goto V_74;
}
F_59 ( V_122 , & V_126 ) ;
F_65 ( V_122 , L_71 ) ;
F_31 ( V_122 ) ;
V_122 = NULL ;
if ( ! F_118 ( V_53 , V_5 ) ) goto V_74;
F_119 ( & V_127 , V_5 ) ;
if ( ! V_68 && ! F_120 ( & V_127 ) )
goto V_74;
if ( ! F_121 ( V_6 , V_80 ) )
{
F_12 ( V_69 , L_106 ) ;
goto V_74;
}
if ( ! F_41 ( V_5 , F_58 ( V_6 ) ) ) goto V_74;
if ( ! F_122 ( V_5 , V_125 ) ) goto V_74;
if ( F_43 ( F_44 ( V_5 ) , 0L ) == NULL )
goto V_74;
if ( F_43 ( F_45 ( V_5 ) , ( long ) 60 * 60 * 24 * V_47 ) == NULL )
goto V_74;
if ( V_44 )
{
while ( F_123 ( V_5 ) > 0 ) F_124 ( V_5 , 0 ) ;
}
if ( V_120 )
{
T_9 V_79 ;
F_125 ( V_5 , 2 ) ;
F_126 ( & V_79 , V_6 , V_5 , NULL , NULL , 0 ) ;
F_26 ( & V_79 , V_120 ) ;
if ( ! F_27 ( V_120 , & V_79 , V_121 , V_5 ) ) goto V_74;
}
if ( ! F_127 ( V_5 , V_80 , V_58 ) ) goto V_74;
V_3 = 1 ;
V_74:
F_128 ( & V_127 ) ;
if ( ! V_3 )
F_22 ( V_69 ) ;
if ( V_56 != NULL ) F_81 ( V_56 ) ;
if ( V_125 != NULL ) F_129 ( V_125 ) ;
if ( V_122 != NULL ) F_31 ( V_122 ) ;
if ( V_29 != NULL ) F_130 ( V_29 ) ;
return V_3 ;
}
static int T_20 V_75 ( int V_130 , T_19 * V_53 )
{
int V_131 ;
T_2 * V_132 ;
V_131 = F_131 ( V_53 ) ;
if ( V_131 == V_133 )
return 1 ;
if ( V_130 )
{
F_12 ( V_69 , L_107 ) ;
return 0 ;
}
else
{
V_132 = F_132 ( V_53 ) ;
F_36 ( V_69 , NULL , F_58 ( V_132 ) , 0 ) ;
F_12 ( V_69 , L_108 ,
V_131 , F_133 ( V_53 ) ,
F_134 ( V_131 ) ) ;
return 1 ;
}
}
static int F_89 ( T_2 * V_5 , T_4 * V_80 , int V_47 , int V_44 , const T_7 * V_58 ,
T_8 * V_120 , char * V_121 )
{
T_4 * V_134 ;
V_134 = F_70 ( V_5 ) ;
F_108 ( V_134 , V_80 ) ;
F_135 ( V_134 , 1 ) ;
F_35 ( V_134 ) ;
if ( ! F_41 ( V_5 , F_58 ( V_5 ) ) ) goto V_131;
if ( F_43 ( F_44 ( V_5 ) , 0 ) == NULL ) goto V_131;
if ( F_43 ( F_45 ( V_5 ) , ( long ) 60 * 60 * 24 * V_47 ) == NULL )
goto V_131;
if ( ! F_46 ( V_5 , V_80 ) ) goto V_131;
if ( V_44 )
{
while ( F_123 ( V_5 ) > 0 ) F_124 ( V_5 , 0 ) ;
}
if ( V_120 )
{
T_9 V_53 ;
F_125 ( V_5 , 2 ) ;
F_126 ( & V_53 , V_5 , V_5 , NULL , NULL , 0 ) ;
F_26 ( & V_53 , V_120 ) ;
if ( ! F_27 ( V_120 , & V_53 , V_121 , V_5 ) ) goto V_131;
}
if ( ! F_127 ( V_5 , V_80 , V_58 ) ) goto V_131;
return 1 ;
V_131:
F_22 ( V_69 ) ;
return 0 ;
}
static int F_69 ( T_5 * V_135 , T_2 * V_136 , T_12 * V_137 )
{
int V_138 , V_10 , V_139 ;
char * V_140 ;
V_138 = F_136 ( V_137 ) ;
V_140 = F_137 ( V_137 ) ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ )
{
V_139 = F_138 ( V_136 , V_138 , V_10 ) ;
F_12 ( V_135 , L_109 , V_140 , V_10 ? L_110 : L_111 ) ;
if ( V_139 == 1 ) F_12 ( V_135 , L_112 ) ;
else if ( V_139 == 0 ) F_12 ( V_135 , L_113 ) ;
else F_12 ( V_135 , L_114 , V_139 ) ;
}
return 1 ;
}
