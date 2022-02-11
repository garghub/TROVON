int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 1 ;
T_2 * V_5 = NULL ;
T_3 * V_6 = NULL , * V_7 = NULL ;
T_4 * V_8 ;
T_5 * V_9 = NULL , * V_10 = NULL ;
T_6 * V_11 = NULL ;
int V_12 , V_13 , V_14 = 0 ;
T_7 * V_15 = NULL ;
T_7 * STDout = NULL ;
F_1 ( T_4 ) * V_16 = NULL , * V_17 = NULL ;
int V_18 , V_19 , V_20 , V_21 , V_22 ;
char * V_23 = NULL , * V_24 = NULL , * V_25 = NULL , * V_26 = NULL ;
char * V_27 = NULL , * V_28 = NULL ;
char * V_29 = NULL ;
int V_30 = 0 , V_31 = 0 , V_32 = 0 , V_33 = 0 , V_34 = 0 , V_35 = 0 ;
int V_36 = 0 ;
int V_37 = 0 , V_38 = 0 , V_39 = 0 ;
int V_40 = 0 , V_41 = 0 , V_42 = 0 , V_43 = 0 , V_44 = 0 ;
int V_45 = 0 , V_46 = 0 , V_47 = 0 , V_48 = 0 , V_49 = 0 ;
int V_50 = 0 ;
int V_51 = 0 , V_52 = V_53 , V_54 = 0 , V_55 = 0 ;
int V_56 = 0 ;
const char * * V_57 ;
T_8 * V_58 = NULL ;
T_2 * V_59 = NULL ;
int V_60 = 0 ;
char V_61 [ 256 ] ;
const T_9 * V_62 , * V_63 = F_2 () ;
T_10 * V_64 = NULL ;
char * V_65 = NULL , * V_66 = NULL , * V_67 = NULL , * V_68 = NULL ;
int V_69 = 0 ;
int V_70 = 0 , V_71 = 0 ;
unsigned long V_72 = 0 , V_73 = 0 ;
#ifndef F_3
char * V_74 = NULL ;
#endif
V_75 = 0 ;
F_4 () ;
if ( V_76 == NULL )
V_76 = F_5 ( V_77 , V_78 ) ;
if ( ! F_6 ( V_76 , NULL ) )
goto V_79;
STDout = F_5 ( stdout , V_78 ) ;
#ifdef F_7
{
T_7 * V_80 = F_8 ( F_9 () ) ;
STDout = F_10 ( V_80 , STDout ) ;
}
#endif
V_18 = V_81 ;
V_19 = V_81 ;
V_20 = V_81 ;
V_21 = V_81 ;
V_22 = V_81 ;
V_58 = F_11 () ;
if ( V_58 == NULL ) goto V_79;
F_12 ( V_58 , V_82 ) ;
V_1 -- ;
V_2 ++ ;
V_13 = 0 ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_18 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_19 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_20 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
V_75 = 1 ;
V_69 = 1 ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_21 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_22 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_52 = atoi ( * ( ++ V_2 ) ) ;
if ( V_52 == 0 )
{
F_14 ( STDout , L_8 ) ;
goto V_83;
}
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_68 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_66 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_65 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_23 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_24 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_25 = * ( ++ V_2 ) ;
V_41 = ++ V_13 ;
V_69 = 1 ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_26 = * ( ++ V_2 ) ;
V_42 = ++ V_13 ;
V_69 = 1 ;
}
else if ( strcmp ( * V_2 , L_16 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_27 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_17 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_28 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_18 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
if ( ! ( V_11 = F_15 ( NULL , * ( ++ V_2 ) ) ) )
goto V_83;
}
else if ( strcmp ( * V_2 , L_19 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
if ( ! ( V_8 = F_16 ( * ( ++ V_2 ) , 0 ) ) )
{
F_14 ( V_76 ,
L_20 , * V_2 ) ;
goto V_83;
}
if ( ! V_16 ) V_16 = F_17 () ;
F_18 ( V_16 , V_8 ) ;
V_45 = 1 ;
}
else if ( strcmp ( * V_2 , L_21 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
if ( ! ( V_8 = F_16 ( * ( ++ V_2 ) , 0 ) ) )
{
F_14 ( V_76 ,
L_22 , * V_2 ) ;
goto V_83;
}
if ( ! V_17 ) V_17 = F_17 () ;
F_18 ( V_17 , V_8 ) ;
V_45 = 1 ;
}
else if ( strcmp ( * V_2 , L_23 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_29 = * ( ++ V_2 ) ;
V_45 = 1 ;
}
else if ( strcmp ( * V_2 , L_24 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
if ( ! F_19 ( & V_73 , * ( ++ V_2 ) ) ) goto V_83;
}
else if ( strcmp ( * V_2 , L_25 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
if ( ! F_20 ( & V_72 , * ( ++ V_2 ) ) ) goto V_83;
}
#ifndef F_3
else if ( strcmp ( * V_2 , L_26 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_74 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_27 ) == 0 )
V_50 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_28 ) == 0 )
V_44 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_29 ) == 0 )
V_31 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_30 ) == 0 )
V_36 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_31 ) == 0 )
V_54 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_32 ) == 0 )
V_55 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_33 ) == 0 )
V_51 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_34 ) == 0 )
V_30 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_35 ) == 0
|| strcmp ( * V_2 , L_36 ) == 0 )
V_37 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_37 ) == 0 )
V_38 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_38 ) == 0 )
V_32 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_39 ) == 0 )
V_33 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_40 ) == 0 )
V_60 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_41 ) == 0 )
{
V_34 = ++ V_13 ;
V_35 = ++ V_13 ;
}
else if ( strcmp ( * V_2 , L_42 ) == 0 )
V_56 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_43 ) == 0 )
V_34 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_44 ) == 0 )
V_35 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_45 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_83;
V_71 = atoi ( * ( ++ V_2 ) ) ;
V_70 = 1 ;
}
else if ( strcmp ( * V_2 , L_46 ) == 0 )
V_40 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_47 ) == 0 )
V_45 = 1 ;
else if ( strcmp ( * V_2 , L_48 ) == 0 )
V_46 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_49 ) == 0 )
V_47 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_50 ) == 0 )
V_48 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_51 ) == 0 )
V_43 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_52 ) == 0 )
V_49 = 1 ;
#if 1
else if ( strcmp ( * V_2 , L_53 ) == 0 )
{
F_14 ( V_76 , L_54 ) ;
V_49 = 1 ;
}
#endif
else if ( strcmp ( * V_2 , L_55 ) == 0 )
V_39 = ++ V_13 ;
else if ( ( V_62 = F_21 ( * V_2 + 1 ) ) )
{
V_63 = V_62 ;
}
else
{
F_14 ( V_76 , L_56 , * V_2 ) ;
V_14 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_14 )
{
V_83:
for ( V_57 = V_84 ; ( * V_57 != NULL ) ; V_57 ++ )
F_14 ( V_76 , L_57 , * V_57 ) ;
goto V_79;
}
#ifndef F_3
V_3 = F_22 ( V_76 , V_74 , 0 ) ;
#endif
if ( V_69 )
F_23 ( NULL , V_76 , 0 ) ;
F_24 () ;
if ( ! F_25 ( V_76 , V_68 , NULL , & V_67 , NULL ) )
{
F_14 ( V_76 , L_58 ) ;
goto V_79;
}
if ( ! F_26 ( V_58 ) )
{
F_27 ( V_76 ) ;
goto V_79;
}
if ( ( V_27 == NULL ) && ( V_42 ) && ( V_21 == V_81 ) )
{ V_27 = V_26 ; }
else if ( ( V_42 ) && ( V_27 == NULL ) )
{
F_14 ( V_76 , L_59 ) ;
goto V_79;
}
if ( V_66 )
{
long V_85 = - 1 ;
T_11 V_86 ;
V_64 = F_28 ( NULL ) ;
if ( ! F_29 ( V_64 , V_66 , & V_85 ) )
{
if ( V_85 <= 0 )
F_14 ( V_76 ,
L_60 ,
V_66 ) ;
else
F_14 ( V_76 ,
L_61
, V_85 , V_66 ) ;
goto V_79;
}
if ( ! V_65 )
{
V_65 = F_30 ( V_64 , L_62 , L_63 ) ;
if ( ! V_65 )
{
F_31 () ;
V_65 = L_62 ;
}
}
F_32 ( & V_86 ) ;
F_33 ( & V_86 , V_64 ) ;
if ( ! F_34 ( V_64 , & V_86 , V_65 , NULL ) )
{
F_14 ( V_76 ,
L_64 ,
V_65 ) ;
F_27 ( V_76 ) ;
goto V_79;
}
}
if ( V_75 )
{
T_5 * V_87 ;
T_12 * V_88 ;
T_7 * V_89 ;
if ( ! V_41 && ! V_42 )
{
F_14 ( V_76 , L_65 ) ;
goto V_79;
}
V_89 = F_8 ( F_35 () ) ;
if ( V_89 == NULL )
{
F_27 ( V_76 ) ;
goto V_79;
}
if ( V_23 == NULL )
F_36 ( V_89 , V_90 , V_78 | V_91 ) ;
else
{
if ( F_37 ( V_89 , V_23 ) <= 0 )
{
perror ( V_23 ) ;
F_38 ( V_89 ) ;
goto V_79;
}
}
V_5 = F_39 ( V_89 , NULL , NULL , NULL ) ;
F_38 ( V_89 ) ;
if ( V_5 == NULL )
{
F_27 ( V_76 ) ;
goto V_79;
}
if ( ( V_5 -> V_92 == NULL ) ||
( V_5 -> V_92 -> V_55 == NULL ) ||
( V_5 -> V_92 -> V_55 -> V_93 == NULL ) ||
( V_5 -> V_92 -> V_55 -> V_93 -> V_94 == NULL ) )
{
F_14 ( V_76 , L_66 ) ;
F_14 ( V_76 , L_67 ) ;
goto V_79;
}
if ( ( V_87 = F_40 ( V_5 ) ) == NULL )
{
F_14 ( V_76 , L_68 ) ;
goto V_79;
}
V_12 = F_41 ( V_5 , V_87 ) ;
F_42 ( V_87 ) ;
if ( V_12 < 0 )
{
F_14 ( V_76 , L_69 ) ;
F_27 ( V_76 ) ;
goto V_79;
}
if ( V_12 == 0 )
{
F_14 ( V_76 , L_70 ) ;
goto V_79;
}
else
F_14 ( V_76 , L_71 ) ;
F_43 ( V_76 , L_72 , F_44 ( V_5 ) , V_72 ) ;
if ( ( V_6 = F_45 () ) == NULL ) goto V_79;
V_88 = V_6 -> V_95 ;
if ( V_11 == NULL )
{
V_11 = F_46 () ;
if ( ! V_11 || ! F_47 ( NULL , V_11 ) )
goto V_79;
if ( ! F_48 ( V_6 , V_11 ) )
goto V_79;
F_49 ( V_11 ) ;
V_11 = NULL ;
}
else if ( ! F_48 ( V_6 , V_11 ) )
goto V_79;
if ( ! F_50 ( V_6 , V_5 -> V_92 -> V_32 ) ) goto V_79;
if ( ! F_51 ( V_6 , V_5 -> V_92 -> V_32 ) ) goto V_79;
F_52 ( F_53 ( V_6 ) , 0 ) ;
F_52 ( F_54 ( V_6 ) , ( long ) 60 * 60 * 24 * V_52 ) ;
V_87 = F_40 ( V_5 ) ;
F_55 ( V_6 , V_87 ) ;
F_42 ( V_87 ) ;
}
else
V_6 = F_56 ( V_76 , V_23 , V_18 , NULL , V_3 , L_73 ) ;
if ( V_6 == NULL ) goto V_79;
if ( V_42 )
{
V_7 = F_56 ( V_76 , V_26 , V_21 , NULL , V_3 , L_74 ) ;
if ( V_7 == NULL ) goto V_79;
}
if ( ! V_40 || V_30 || V_36 )
{
F_57 ( L_75 ,
L_76 , L_77 ) ;
V_15 = F_8 ( F_35 () ) ;
if ( V_15 == NULL )
{
F_27 ( V_76 ) ;
goto V_79;
}
if ( V_24 == NULL )
{
F_36 ( V_15 , stdout , V_78 ) ;
#ifdef F_7
{
T_7 * V_80 = F_8 ( F_9 () ) ;
V_15 = F_10 ( V_80 , V_15 ) ;
}
#endif
}
else
{
if ( F_58 ( V_15 , V_24 ) <= 0 )
{
perror ( V_24 ) ;
goto V_79;
}
}
}
if ( V_29 ) F_59 ( V_6 , ( unsigned char * ) V_29 , - 1 ) ;
if ( V_46 ) F_60 ( V_6 ) ;
if ( V_47 ) F_61 ( V_6 ) ;
if ( V_16 )
{
for ( V_12 = 0 ; V_12 < F_62 ( V_16 ) ; V_12 ++ )
{
V_8 = F_63 ( V_16 , V_12 ) ;
F_64 ( V_6 , V_8 ) ;
}
}
if ( V_17 )
{
for ( V_12 = 0 ; V_12 < F_62 ( V_17 ) ; V_12 ++ )
{
V_8 = F_63 ( V_17 , V_12 ) ;
F_65 ( V_6 , V_8 ) ;
}
}
if ( V_13 )
{
for ( V_12 = 1 ; V_12 <= V_13 ; V_12 ++ )
{
if ( V_33 == V_12 )
{
F_43 ( STDout , L_78 ,
F_66 ( V_6 ) , V_72 ) ;
}
else if ( V_32 == V_12 )
{
F_43 ( STDout , L_79 ,
F_67 ( V_6 ) , V_72 ) ;
}
else if ( V_31 == V_12 )
{
F_14 ( STDout , L_80 ) ;
F_68 ( STDout ,
F_69 ( V_6 ) ) ;
F_14 ( STDout , L_81 ) ;
}
else if ( V_36 == V_12 )
{
T_13 * V_96 ;
T_6 * V_97 ;
V_97 = F_69 ( V_6 ) ;
V_96 = F_70 ( V_97 , NULL ) ;
if ( ! V_96 )
goto V_79;
if ( ! F_71 ( V_96 , 1 ) )
goto V_79;
V_97 = F_72 ( V_96 , NULL ) ;
if ( ! V_97 )
goto V_79;
F_73 ( V_96 ) ;
F_68 ( V_15 , V_97 ) ;
F_49 ( V_97 ) ;
F_74 ( V_15 , L_81 ) ;
}
else if ( V_44 == V_12 )
{
int V_98 ;
T_14 * V_99 ;
V_99 = F_75 ( V_6 ) ;
for ( V_98 = 0 ; V_98 < F_76 ( V_99 ) ; V_98 ++ )
F_14 ( STDout , L_82 , F_77 ( V_99 , V_98 ) ) ;
F_78 ( V_99 ) ;
}
else if ( V_48 == V_12 )
{
unsigned char * V_100 ;
V_100 = F_79 ( V_6 , NULL ) ;
if ( V_100 ) F_14 ( STDout , L_82 , V_100 ) ;
else F_74 ( STDout , L_83 ) ;
}
else if ( V_37 == V_12 )
{
F_14 ( STDout , L_84 , F_80 ( V_6 ) ) ;
}
else if ( V_38 == V_12 )
{
F_14 ( STDout , L_84 , F_81 ( V_6 ) ) ;
}
else if ( V_56 == V_12 )
{
T_15 * V_101 ;
int V_98 ;
F_14 ( STDout , L_85 ) ;
for ( V_98 = 0 ; V_98 < F_82 () ; V_98 ++ )
{
V_101 = F_83 ( V_98 ) ;
F_84 ( STDout , V_6 , V_101 ) ;
}
}
else
if ( V_54 == V_12 )
{
T_5 * V_87 ;
V_87 = F_85 ( V_6 ) ;
if ( V_87 == NULL )
{
F_14 ( V_76 , L_86 ) ;
F_27 ( V_76 ) ;
goto V_79;
}
F_14 ( STDout , L_87 ) ;
#ifndef F_86
if ( V_87 -> type == V_102 )
F_87 ( STDout , V_87 -> V_87 . V_103 -> V_104 ) ;
else
#endif
#ifndef F_88
if ( V_87 -> type == V_105 )
F_87 ( STDout , V_87 -> V_87 . V_106 -> V_107 ) ;
else
#endif
F_14 ( STDout , L_88 ) ;
F_14 ( STDout , L_81 ) ;
F_42 ( V_87 ) ;
}
else
if ( V_55 == V_12 )
{
T_5 * V_87 ;
V_87 = F_85 ( V_6 ) ;
if ( V_87 == NULL )
{
F_14 ( V_76 , L_89 ) ;
F_27 ( V_76 ) ;
goto V_79;
}
F_89 ( STDout , V_87 ) ;
F_42 ( V_87 ) ;
}
else
if ( V_50 == V_12 )
{
unsigned char * V_108 ;
char * V_109 ;
int V_110 , V_111 ;
F_90 ( F_67 ( V_6 ) ,
V_61 , sizeof V_61 ) ;
F_14 ( STDout , L_90 , V_61 ) ;
V_109 = F_90 (
F_66 ( V_6 ) , V_61 ,
sizeof V_61 ) ;
F_14 ( STDout , L_91 , V_61 ) ;
V_111 = F_91 ( V_6 , NULL ) ;
V_109 = F_92 ( V_111 ) ;
V_108 = ( unsigned char * ) V_109 ;
V_111 = F_93 ( F_67 ( V_6 ) , & V_108 ) ;
F_14 ( STDout , L_92 , V_111 ) ;
V_108 = ( unsigned char * ) V_109 ;
for ( V_110 = 0 ; V_110 < V_111 ; V_110 ++ )
{
F_14 ( STDout , L_93 , V_108 [ V_110 ] ) ;
if ( ( V_110 & 0x0f ) == 0x0f ) F_14 ( STDout , L_81 ) ;
}
if ( V_110 % 16 != 0 ) F_14 ( STDout , L_81 ) ;
F_14 ( STDout , L_94 ) ;
V_111 = F_94 ( F_95 ( V_6 ) , & V_108 ) ;
F_14 ( STDout , L_95 , V_111 ) ;
V_108 = ( unsigned char * ) V_109 ;
for ( V_110 = 0 ; V_110 < V_111 ; V_110 ++ )
{
F_14 ( STDout , L_93 , V_108 [ V_110 ] ) ;
if ( ( V_110 & 0x0f ) == 0x0f )
F_14 ( STDout , L_81 ) ;
}
if ( V_110 % 16 != 0 ) F_14 ( STDout , L_81 ) ;
F_14 ( STDout , L_94 ) ;
V_111 = F_91 ( V_6 , & V_108 ) ;
F_14 ( STDout , L_96 , V_111 ) ;
V_108 = ( unsigned char * ) V_109 ;
for ( V_110 = 0 ; V_110 < V_111 ; V_110 ++ )
{
F_14 ( STDout , L_93 , V_108 [ V_110 ] ) ;
if ( ( V_110 & 0x0f ) == 0x0f )
F_14 ( STDout , L_81 ) ;
}
if ( V_110 % 16 != 0 ) F_14 ( STDout , L_81 ) ;
F_14 ( STDout , L_94 ) ;
F_96 ( V_109 ) ;
}
else if ( V_30 == V_12 )
{
F_97 ( V_15 , V_6 , V_72 , V_73 ) ;
}
else if ( V_34 == V_12 )
{
F_74 ( STDout , L_97 ) ;
F_98 ( STDout , F_53 ( V_6 ) ) ;
F_74 ( STDout , L_81 ) ;
}
else if ( V_35 == V_12 )
{
F_74 ( STDout , L_98 ) ;
F_98 ( STDout , F_54 ( V_6 ) ) ;
F_74 ( STDout , L_81 ) ;
}
else if ( V_60 == V_12 )
{
int V_98 ;
unsigned int V_104 ;
unsigned char V_112 [ V_113 ] ;
if ( ! F_99 ( V_6 , V_63 , V_112 , & V_104 ) )
{
F_14 ( V_76 , L_99 ) ;
goto V_79;
}
F_14 ( STDout , L_100 ,
F_100 ( F_101 ( V_63 ) ) ) ;
for ( V_98 = 0 ; V_98 < ( int ) V_104 ; V_98 ++ )
{
F_14 ( STDout , L_101 , V_112 [ V_98 ] ,
( V_98 + 1 == ( int ) V_104 )
? '\n' : ':' ) ;
}
}
else if ( ( V_41 == V_12 ) && ( V_51 == 0 ) )
{
F_14 ( V_76 , L_102 ) ;
if ( V_9 == NULL )
{
V_9 = F_102 ( V_76 ,
V_25 , V_20 , 0 ,
V_67 , V_3 , L_103 ) ;
if ( V_9 == NULL ) goto V_79;
}
#ifndef F_88
if ( V_9 -> type == V_105 )
V_63 = F_103 () ;
#endif
#ifndef F_104
if ( V_9 -> type == V_114 )
V_63 = F_105 () ;
#endif
assert ( V_69 ) ;
if ( ! F_106 ( V_6 , V_9 , V_52 , V_49 , V_63 ,
V_64 , V_65 ) ) goto V_79;
}
else if ( V_42 == V_12 )
{
F_14 ( V_76 , L_104 ) ;
if ( V_27 != NULL )
{
V_10 = F_102 ( V_76 ,
V_27 , V_22 ,
0 , V_67 , V_3 ,
L_105 ) ;
if ( V_10 == NULL ) goto V_79;
}
#ifndef F_88
if ( V_10 -> type == V_105 )
V_63 = F_103 () ;
#endif
#ifndef F_104
if ( V_10 -> type == V_114 )
V_63 = F_105 () ;
#endif
assert ( V_69 ) ;
if ( ! F_107 ( V_58 , V_26 , V_63 , V_6 , V_7 ,
V_10 , V_28 , V_43 , V_52 , V_49 ,
V_64 , V_65 , V_11 ) )
goto V_79;
}
else if ( V_51 == V_12 )
{
T_5 * V_115 ;
F_14 ( V_76 , L_106 ) ;
if ( V_25 == NULL )
{
F_14 ( V_76 , L_107 ) ;
goto V_79;
}
else
{
V_115 = F_102 ( V_76 ,
V_25 , V_81 , 0 ,
V_67 , V_3 , L_108 ) ;
if ( V_115 == NULL ) goto V_79;
}
F_14 ( V_76 , L_109 ) ;
#ifndef F_88
if ( V_115 -> type == V_105 )
V_63 = F_103 () ;
#endif
#ifndef F_104
if ( V_115 -> type == V_114 )
V_63 = F_105 () ;
#endif
V_59 = F_108 ( V_6 , V_115 , V_63 ) ;
F_42 ( V_115 ) ;
if ( V_59 == NULL )
{
F_27 ( V_76 ) ;
goto V_79;
}
if ( ! V_40 )
{
F_109 ( V_15 , V_59 ) ;
F_110 ( V_15 , V_59 ) ;
}
V_40 = 1 ;
}
else if ( V_39 == V_12 )
{
F_111 ( V_15 , V_6 ) ;
}
}
}
if ( V_70 )
{
T_16 V_116 = time ( NULL ) + V_71 ;
if ( F_112 ( F_54 ( V_6 ) , & V_116 ) < 0 )
{
F_14 ( V_15 , L_110 ) ;
V_4 = 1 ;
}
else
{
F_14 ( V_15 , L_111 ) ;
V_4 = 0 ;
}
goto V_79;
}
if ( V_40 )
{
V_4 = 0 ;
goto V_79;
}
if ( V_19 == V_117 )
V_12 = F_113 ( V_15 , V_6 ) ;
else if ( V_19 == V_81 )
{
if ( V_45 ) V_12 = F_114 ( V_15 , V_6 ) ;
else V_12 = F_115 ( V_15 , V_6 ) ;
}
else if ( V_19 == V_118 )
{
T_17 V_119 ;
T_18 V_120 ;
V_120 . V_94 = ( unsigned char * ) V_121 ;
V_120 . V_122 = strlen ( V_121 ) ;
V_119 . V_123 = & V_120 ;
V_119 . V_94 = ( char * ) V_6 ;
V_119 . V_124 = F_116 () ;
V_12 = F_117 ( T_17 , V_125 , V_15 , & V_119 ) ;
}
else {
F_14 ( V_76 , L_112 ) ;
goto V_79;
}
if ( ! V_12 )
{
F_14 ( V_76 , L_113 ) ;
F_27 ( V_76 ) ;
goto V_79;
}
V_4 = 0 ;
V_79:
if ( V_69 )
F_118 ( NULL , V_76 ) ;
F_119 () ;
F_120 ( V_64 ) ;
F_121 ( V_15 ) ;
F_121 ( STDout ) ;
F_122 ( V_58 ) ;
F_123 ( V_5 ) ;
F_124 ( V_6 ) ;
F_124 ( V_7 ) ;
F_42 ( V_9 ) ;
F_42 ( V_10 ) ;
F_123 ( V_59 ) ;
F_49 ( V_11 ) ;
F_125 ( V_16 , V_126 ) ;
F_125 ( V_17 , V_126 ) ;
if ( V_67 ) F_96 ( V_67 ) ;
F_126 () ;
F_127 ( V_4 ) ;
}
static T_6 * F_128 ( char * V_26 , char * V_127 , int V_128 )
{
char * V_61 = NULL , * V_129 ;
T_6 * V_130 = NULL ;
T_13 * V_31 = NULL ;
T_19 V_131 ;
V_131 = ( ( V_127 == NULL )
? ( strlen ( V_26 ) + strlen ( V_132 ) + 1 )
: ( strlen ( V_127 ) ) ) + 1 ;
V_61 = F_92 ( V_131 ) ;
if ( V_61 == NULL ) { F_14 ( V_76 , L_114 ) ; goto V_79; }
if ( V_127 == NULL )
{
F_129 ( V_61 , V_26 , V_131 ) ;
for ( V_129 = V_61 ; * V_129 ; V_129 ++ )
if ( * V_129 == '.' )
{
* V_129 = '\0' ;
break;
}
F_130 ( V_61 , V_132 , V_131 ) ;
}
else
F_129 ( V_61 , V_127 , V_131 ) ;
V_31 = F_131 ( V_61 , V_128 , NULL ) ;
if ( V_31 == NULL ) goto V_79;
if ( ! F_71 ( V_31 , 1 ) )
{ F_14 ( V_76 , L_115 ) ; goto V_79; }
if ( ! F_132 ( V_61 , NULL , V_31 , & V_130 ) ) goto V_79;
V_79:
if ( V_61 ) F_96 ( V_61 ) ;
F_73 ( V_31 ) ;
return V_130 ;
}
static int F_107 ( T_8 * V_58 , char * V_26 , const T_9 * V_63 ,
T_3 * V_6 , T_3 * V_7 , T_5 * V_87 , char * V_127 , int V_128 ,
int V_52 , int V_49 , T_10 * V_133 , char * V_134 , T_6 * V_11 )
{
int V_4 = 0 ;
T_6 * V_130 = NULL ;
T_20 V_135 ;
T_5 * V_136 ;
V_136 = F_85 ( V_7 ) ;
F_133 ( V_136 , V_87 ) ;
F_42 ( V_136 ) ;
if( ! F_134 ( & V_135 , V_58 , V_6 , NULL ) )
{
F_14 ( V_76 , L_116 ) ;
goto V_79;
}
if ( V_11 ) V_130 = V_11 ;
else if ( ! ( V_130 = F_128 ( V_26 , V_127 , V_128 ) ) )
goto V_79;
F_135 ( & V_135 , V_6 ) ;
if ( ! V_75 && ! F_136 ( & V_135 ) )
goto V_79;
if ( ! F_137 ( V_7 , V_87 ) )
{
F_14 ( V_76 , L_117 ) ;
goto V_79;
}
if ( ! F_50 ( V_6 , F_67 ( V_7 ) ) ) goto V_79;
if ( ! F_48 ( V_6 , V_130 ) ) goto V_79;
if ( F_52 ( F_53 ( V_6 ) , 0L ) == NULL )
goto V_79;
if ( F_52 ( F_54 ( V_6 ) , ( long ) 60 * 60 * 24 * V_52 ) == NULL )
goto V_79;
if ( V_49 )
{
while ( F_138 ( V_6 ) > 0 ) F_139 ( V_6 , 0 ) ;
}
if ( V_133 )
{
T_11 V_86 ;
F_140 ( V_6 , 2 ) ;
F_141 ( & V_86 , V_7 , V_6 , NULL , NULL , 0 ) ;
F_33 ( & V_86 , V_133 ) ;
if ( ! F_34 ( V_133 , & V_86 , V_134 , V_6 ) ) goto V_79;
}
if ( ! F_142 ( V_6 , V_87 , V_63 ) ) goto V_79;
V_4 = 1 ;
V_79:
F_143 ( & V_135 ) ;
if ( ! V_4 )
F_27 ( V_76 ) ;
if ( ! V_11 ) F_49 ( V_130 ) ;
return V_4 ;
}
static int T_21 V_82 ( int V_137 , T_20 * V_58 )
{
int V_138 ;
T_3 * V_139 ;
V_138 = F_144 ( V_58 ) ;
if ( V_138 == V_140 )
return 1 ;
if ( V_137 )
{
F_14 ( V_76 , L_118 ) ;
return 0 ;
}
else
{
V_139 = F_145 ( V_58 ) ;
F_43 ( V_76 , NULL , F_67 ( V_139 ) , 0 ) ;
F_14 ( V_76 , L_119 ,
V_138 , F_146 ( V_58 ) ,
F_147 ( V_138 ) ) ;
return 1 ;
}
}
static int F_106 ( T_3 * V_6 , T_5 * V_87 , int V_52 , int V_49 , const T_9 * V_63 ,
T_10 * V_133 , char * V_134 )
{
T_5 * V_141 ;
V_141 = F_85 ( V_6 ) ;
F_133 ( V_141 , V_87 ) ;
F_148 ( V_141 , 1 ) ;
F_42 ( V_141 ) ;
if ( ! F_50 ( V_6 , F_67 ( V_6 ) ) ) goto V_138;
if ( F_52 ( F_53 ( V_6 ) , 0 ) == NULL ) goto V_138;
if ( F_52 ( F_54 ( V_6 ) , ( long ) 60 * 60 * 24 * V_52 ) == NULL )
goto V_138;
if ( ! F_55 ( V_6 , V_87 ) ) goto V_138;
if ( V_49 )
{
while ( F_138 ( V_6 ) > 0 ) F_139 ( V_6 , 0 ) ;
}
if ( V_133 )
{
T_11 V_58 ;
F_140 ( V_6 , 2 ) ;
F_141 ( & V_58 , V_6 , V_6 , NULL , NULL , 0 ) ;
F_33 ( & V_58 , V_133 ) ;
if ( ! F_34 ( V_133 , & V_58 , V_134 , V_6 ) ) goto V_138;
}
if ( ! F_142 ( V_6 , V_87 , V_63 ) ) goto V_138;
return 1 ;
V_138:
F_27 ( V_76 ) ;
return 0 ;
}
static int F_84 ( T_7 * V_142 , T_3 * V_143 , T_15 * V_144 )
{
int V_145 , V_12 , V_146 ;
char * V_147 ;
V_145 = F_149 ( V_144 ) ;
V_147 = F_150 ( V_144 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
{
V_146 = F_151 ( V_143 , V_145 , V_12 ) ;
F_14 ( V_142 , L_120 , V_147 , V_12 ? L_121 : L_122 ) ;
if ( V_146 == 1 ) F_14 ( V_142 , L_123 ) ;
else if ( V_146 == 0 ) F_14 ( V_142 , L_124 ) ;
else F_14 ( V_142 , L_125 , V_146 ) ;
}
return 1 ;
}
