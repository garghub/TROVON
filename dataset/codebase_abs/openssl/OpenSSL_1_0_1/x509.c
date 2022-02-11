int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 1 ;
T_2 * V_5 = NULL ;
T_3 * V_6 = NULL , * V_7 = NULL ;
T_4 * V_8 ;
F_1 ( V_9 ) * V_10 = NULL ;
T_5 * V_11 = NULL , * V_12 = NULL ;
T_6 * V_13 = NULL ;
int V_14 , V_15 , V_16 = 0 ;
T_7 * V_17 = NULL ;
T_7 * STDout = NULL ;
F_1 ( T_4 ) * V_18 = NULL , * V_19 = NULL ;
int V_20 , V_21 , V_22 , V_23 , V_24 ;
char * V_25 = NULL , * V_26 = NULL , * V_27 = NULL , * V_28 = NULL ;
char * V_29 = NULL , * V_30 = NULL ;
char * V_31 = NULL ;
int V_32 = 0 , V_33 = 0 , V_34 = 0 , V_35 = 0 , V_36 = 0 , V_37 = 0 ;
int V_38 = 0 ;
int V_39 = 0 , V_40 = 0 , V_41 = 0 ;
#ifndef F_2
int V_42 = 0 , V_43 = 0 ;
#endif
int V_44 = 0 , V_45 = 0 , V_46 = 0 , V_47 = 0 , V_48 = 0 ;
int V_49 = 0 ;
int V_50 = 0 , V_51 = 0 , V_52 = 0 , V_53 = 0 , V_54 = 0 ;
int V_55 = 0 ;
int V_56 = 0 , V_57 = V_58 , V_59 = 0 , V_60 = 0 ;
int V_61 = 0 ;
const char * * V_62 ;
T_8 * V_63 = NULL ;
T_2 * V_64 = NULL ;
int V_65 = 0 ;
char V_66 [ 256 ] ;
const T_9 * V_67 , * V_68 = NULL ;
T_10 * V_69 = NULL ;
char * V_70 = NULL , * V_71 = NULL , * V_72 = NULL , * V_73 = NULL ;
int V_74 = 0 ;
int V_75 = 0 , V_76 = 0 ;
unsigned long V_77 = 0 , V_78 = 0 ;
#ifndef F_3
char * V_79 = NULL ;
#endif
V_80 = 0 ;
F_4 () ;
if ( V_81 == NULL )
V_81 = F_5 ( V_82 , V_83 ) ;
if ( ! F_6 ( V_81 , NULL ) )
goto V_84;
STDout = F_5 ( stdout , V_83 ) ;
#ifdef F_7
{
T_7 * V_85 = F_8 ( F_9 () ) ;
STDout = F_10 ( V_85 , STDout ) ;
}
#endif
V_20 = V_86 ;
V_21 = V_86 ;
V_22 = V_86 ;
V_23 = V_86 ;
V_24 = V_86 ;
V_63 = F_11 () ;
if ( V_63 == NULL ) goto V_84;
F_12 ( V_63 , V_87 ) ;
V_1 -- ;
V_2 ++ ;
V_15 = 0 ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_20 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_21 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_22 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
V_80 = 1 ;
V_74 = 1 ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_23 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_24 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 )
goto V_88;
if ( ! V_10 )
V_10 = F_14 () ;
if ( ! V_10 || ! F_15 ( V_10 , * ( ++ V_2 ) ) )
goto V_88;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_57 = atoi ( * ( ++ V_2 ) ) ;
if ( V_57 == 0 )
{
F_16 ( STDout , L_9 ) ;
goto V_88;
}
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_73 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_71 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_70 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_25 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_26 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_27 = * ( ++ V_2 ) ;
V_45 = ++ V_15 ;
V_74 = 1 ;
}
else if ( strcmp ( * V_2 , L_16 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_28 = * ( ++ V_2 ) ;
V_46 = ++ V_15 ;
V_74 = 1 ;
}
else if ( strcmp ( * V_2 , L_17 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_29 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_18 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_30 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_19 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
if ( ! ( V_13 = F_17 ( NULL , * ( ++ V_2 ) ) ) )
goto V_88;
}
else if ( strcmp ( * V_2 , L_20 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
if ( ! ( V_8 = F_18 ( * ( ++ V_2 ) , 0 ) ) )
{
F_16 ( V_81 ,
L_21 , * V_2 ) ;
goto V_88;
}
if ( ! V_18 ) V_18 = F_19 () ;
F_20 ( V_18 , V_8 ) ;
V_50 = 1 ;
}
else if ( strcmp ( * V_2 , L_22 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
if ( ! ( V_8 = F_18 ( * ( ++ V_2 ) , 0 ) ) )
{
F_16 ( V_81 ,
L_23 , * V_2 ) ;
goto V_88;
}
if ( ! V_19 ) V_19 = F_19 () ;
F_20 ( V_19 , V_8 ) ;
V_50 = 1 ;
}
else if ( strcmp ( * V_2 , L_24 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_31 = * ( ++ V_2 ) ;
V_50 = 1 ;
}
else if ( strcmp ( * V_2 , L_25 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
if ( ! F_21 ( & V_78 , * ( ++ V_2 ) ) ) goto V_88;
}
else if ( strcmp ( * V_2 , L_26 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
if ( ! F_22 ( & V_77 , * ( ++ V_2 ) ) ) goto V_88;
}
#ifndef F_3
else if ( strcmp ( * V_2 , L_27 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_79 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_28 ) == 0 )
V_55 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_29 ) == 0 )
V_48 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_30 ) == 0 )
V_49 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_31 ) == 0 )
V_33 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_32 ) == 0 )
V_38 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_33 ) == 0 )
V_59 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_34 ) == 0 )
V_60 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_35 ) == 0 )
V_56 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_36 ) == 0 )
V_32 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_37 ) == 0
|| strcmp ( * V_2 , L_38 ) == 0 )
V_39 = ++ V_15 ;
#ifndef F_2
else if ( strcmp ( * V_2 , L_39 ) == 0 )
V_42 = ++ V_15 ;
#endif
else if ( strcmp ( * V_2 , L_40 ) == 0 )
V_40 = ++ V_15 ;
#ifndef F_2
else if ( strcmp ( * V_2 , L_41 ) == 0 )
V_43 = ++ V_15 ;
#endif
else if ( strcmp ( * V_2 , L_42 ) == 0 )
V_34 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_43 ) == 0 )
V_35 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_44 ) == 0 )
V_65 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_45 ) == 0 )
{
V_36 = ++ V_15 ;
V_37 = ++ V_15 ;
}
else if ( strcmp ( * V_2 , L_46 ) == 0 )
V_61 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_47 ) == 0 )
V_36 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_48 ) == 0 )
V_37 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_49 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_88;
V_76 = atoi ( * ( ++ V_2 ) ) ;
V_75 = 1 ;
}
else if ( strcmp ( * V_2 , L_50 ) == 0 )
V_44 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_51 ) == 0 )
V_50 = 1 ;
else if ( strcmp ( * V_2 , L_52 ) == 0 )
V_51 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_53 ) == 0 )
V_52 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_54 ) == 0 )
V_53 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_55 ) == 0 )
V_47 = ++ V_15 ;
else if ( strcmp ( * V_2 , L_56 ) == 0 )
V_54 = 1 ;
#if 1
else if ( strcmp ( * V_2 , L_57 ) == 0 )
{
F_16 ( V_81 , L_58 ) ;
V_54 = 1 ;
}
#endif
else if ( strcmp ( * V_2 , L_59 ) == 0 )
V_41 = ++ V_15 ;
else if ( ( V_67 = F_23 ( * V_2 + 1 ) ) )
{
V_68 = V_67 ;
}
else
{
F_16 ( V_81 , L_60 , * V_2 ) ;
V_16 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_16 )
{
V_88:
for ( V_62 = V_89 ; ( * V_62 != NULL ) ; V_62 ++ )
F_16 ( V_81 , L_61 , * V_62 ) ;
goto V_84;
}
#ifndef F_3
V_3 = F_24 ( V_81 , V_79 , 0 ) ;
#endif
if ( V_74 )
F_25 ( NULL , V_81 , 0 ) ;
F_26 () ;
if ( ! F_27 ( V_81 , V_73 , NULL , & V_72 , NULL ) )
{
F_16 ( V_81 , L_62 ) ;
goto V_84;
}
if ( ! F_28 ( V_63 ) )
{
F_29 ( V_81 ) ;
goto V_84;
}
if ( ( V_29 == NULL ) && ( V_46 ) && ( V_23 == V_86 ) )
{ V_29 = V_28 ; }
else if ( ( V_46 ) && ( V_29 == NULL ) )
{
F_16 ( V_81 , L_63 ) ;
goto V_84;
}
if ( V_71 )
{
long V_90 = - 1 ;
T_11 V_91 ;
V_69 = F_30 ( NULL ) ;
if ( ! F_31 ( V_69 , V_71 , & V_90 ) )
{
if ( V_90 <= 0 )
F_16 ( V_81 ,
L_64 ,
V_71 ) ;
else
F_16 ( V_81 ,
L_65
, V_90 , V_71 ) ;
goto V_84;
}
if ( ! V_70 )
{
V_70 = F_32 ( V_69 , L_66 , L_67 ) ;
if ( ! V_70 )
{
F_33 () ;
V_70 = L_66 ;
}
}
F_34 ( & V_91 ) ;
F_35 ( & V_91 , V_69 ) ;
if ( ! F_36 ( V_69 , & V_91 , V_70 , NULL ) )
{
F_16 ( V_81 ,
L_68 ,
V_70 ) ;
F_29 ( V_81 ) ;
goto V_84;
}
}
if ( V_80 )
{
T_5 * V_92 ;
T_7 * V_93 ;
if ( ! V_45 && ! V_46 )
{
F_16 ( V_81 , L_69 ) ;
goto V_84;
}
V_93 = F_8 ( F_37 () ) ;
if ( V_93 == NULL )
{
F_29 ( V_81 ) ;
goto V_84;
}
if ( V_25 == NULL )
F_38 ( V_93 , V_94 , V_83 | V_95 ) ;
else
{
if ( F_39 ( V_93 , V_25 ) <= 0 )
{
perror ( V_25 ) ;
F_40 ( V_93 ) ;
goto V_84;
}
}
V_5 = F_41 ( V_93 , NULL , NULL , NULL ) ;
F_40 ( V_93 ) ;
if ( V_5 == NULL )
{
F_29 ( V_81 ) ;
goto V_84;
}
if ( ( V_5 -> V_96 == NULL ) ||
( V_5 -> V_96 -> V_60 == NULL ) ||
( V_5 -> V_96 -> V_60 -> V_97 == NULL ) ||
( V_5 -> V_96 -> V_60 -> V_97 -> V_98 == NULL ) )
{
F_16 ( V_81 , L_70 ) ;
F_16 ( V_81 , L_71 ) ;
goto V_84;
}
if ( ( V_92 = F_42 ( V_5 ) ) == NULL )
{
F_16 ( V_81 , L_72 ) ;
goto V_84;
}
V_14 = F_43 ( V_5 , V_92 ) ;
F_44 ( V_92 ) ;
if ( V_14 < 0 )
{
F_16 ( V_81 , L_73 ) ;
F_29 ( V_81 ) ;
goto V_84;
}
if ( V_14 == 0 )
{
F_16 ( V_81 , L_74 ) ;
goto V_84;
}
else
F_16 ( V_81 , L_75 ) ;
F_45 ( V_81 , L_76 , F_46 ( V_5 ) , V_77 ) ;
if ( ( V_6 = F_47 () ) == NULL ) goto V_84;
if ( V_13 == NULL )
{
V_13 = F_48 () ;
if ( ! V_13 || ! F_49 ( NULL , V_13 ) )
goto V_84;
if ( ! F_50 ( V_6 , V_13 ) )
goto V_84;
F_51 ( V_13 ) ;
V_13 = NULL ;
}
else if ( ! F_50 ( V_6 , V_13 ) )
goto V_84;
if ( ! F_52 ( V_6 , V_5 -> V_96 -> V_34 ) ) goto V_84;
if ( ! F_53 ( V_6 , V_5 -> V_96 -> V_34 ) ) goto V_84;
F_54 ( F_55 ( V_6 ) , 0 ) ;
F_56 ( F_57 ( V_6 ) , V_57 , 0 , NULL ) ;
V_92 = F_42 ( V_5 ) ;
F_58 ( V_6 , V_92 ) ;
F_44 ( V_92 ) ;
}
else
V_6 = F_59 ( V_81 , V_25 , V_20 , NULL , V_3 , L_77 ) ;
if ( V_6 == NULL ) goto V_84;
if ( V_46 )
{
V_7 = F_59 ( V_81 , V_28 , V_23 , NULL , V_3 , L_78 ) ;
if ( V_7 == NULL ) goto V_84;
}
if ( ! V_44 || V_32 || V_38 )
{
F_60 ( L_79 ,
L_80 , L_81 ) ;
V_17 = F_8 ( F_37 () ) ;
if ( V_17 == NULL )
{
F_29 ( V_81 ) ;
goto V_84;
}
if ( V_26 == NULL )
{
F_38 ( V_17 , stdout , V_83 ) ;
#ifdef F_7
{
T_7 * V_85 = F_8 ( F_9 () ) ;
V_17 = F_10 ( V_85 , V_17 ) ;
}
#endif
}
else
{
if ( F_61 ( V_17 , V_26 ) <= 0 )
{
perror ( V_26 ) ;
goto V_84;
}
}
}
if ( V_31 ) F_62 ( V_6 , ( unsigned char * ) V_31 , - 1 ) ;
if ( V_51 ) F_63 ( V_6 ) ;
if ( V_52 ) F_64 ( V_6 ) ;
if ( V_18 )
{
for ( V_14 = 0 ; V_14 < F_65 ( V_18 ) ; V_14 ++ )
{
V_8 = F_66 ( V_18 , V_14 ) ;
F_67 ( V_6 , V_8 ) ;
}
}
if ( V_19 )
{
for ( V_14 = 0 ; V_14 < F_65 ( V_19 ) ; V_14 ++ )
{
V_8 = F_66 ( V_19 , V_14 ) ;
F_68 ( V_6 , V_8 ) ;
}
}
if ( V_15 )
{
for ( V_14 = 1 ; V_14 <= V_15 ; V_14 ++ )
{
if ( V_35 == V_14 )
{
F_45 ( STDout , L_82 ,
F_69 ( V_6 ) , V_77 ) ;
}
else if ( V_34 == V_14 )
{
F_45 ( STDout , L_83 ,
F_70 ( V_6 ) , V_77 ) ;
}
else if ( V_33 == V_14 )
{
F_16 ( STDout , L_84 ) ;
F_71 ( STDout ,
F_72 ( V_6 ) ) ;
F_16 ( STDout , L_85 ) ;
}
else if ( V_38 == V_14 )
{
T_12 * V_99 ;
T_6 * V_100 ;
V_100 = F_72 ( V_6 ) ;
V_99 = F_73 ( V_100 , NULL ) ;
if ( ! V_99 )
goto V_84;
if ( ! F_74 ( V_99 , 1 ) )
goto V_84;
V_100 = F_75 ( V_99 , NULL ) ;
if ( ! V_100 )
goto V_84;
F_76 ( V_99 ) ;
F_71 ( V_17 , V_100 ) ;
F_51 ( V_100 ) ;
F_77 ( V_17 , L_85 ) ;
}
else if ( ( V_48 == V_14 ) || ( V_49 == V_14 ) )
{
int V_101 ;
F_1 ( V_9 ) * V_102 ;
if ( V_48 == V_14 )
V_102 = F_78 ( V_6 ) ;
else
V_102 = F_79 ( V_6 ) ;
for ( V_101 = 0 ; V_101 < F_80 ( V_102 ) ; V_101 ++ )
F_16 ( STDout , L_86 ,
F_81 ( V_102 , V_101 ) ) ;
F_82 ( V_102 ) ;
}
else if ( V_53 == V_14 )
{
unsigned char * V_103 ;
V_103 = F_83 ( V_6 , NULL ) ;
if ( V_103 ) F_16 ( STDout , L_86 , V_103 ) ;
else F_77 ( STDout , L_87 ) ;
}
else if ( V_39 == V_14 )
{
F_16 ( STDout , L_88 , F_84 ( V_6 ) ) ;
}
#ifndef F_2
else if ( V_42 == V_14 )
{
F_16 ( STDout , L_88 , F_85 ( V_6 ) ) ;
}
#endif
else if ( V_40 == V_14 )
{
F_16 ( STDout , L_88 , F_86 ( V_6 ) ) ;
}
#ifndef F_2
else if ( V_43 == V_14 )
{
F_16 ( STDout , L_88 , F_87 ( V_6 ) ) ;
}
#endif
else if ( V_61 == V_14 )
{
T_13 * V_104 ;
int V_101 ;
F_16 ( STDout , L_89 ) ;
for ( V_101 = 0 ; V_101 < F_88 () ; V_101 ++ )
{
V_104 = F_89 ( V_101 ) ;
F_90 ( STDout , V_6 , V_104 ) ;
}
}
else
if ( V_59 == V_14 )
{
T_5 * V_92 ;
V_92 = F_91 ( V_6 ) ;
if ( V_92 == NULL )
{
F_16 ( V_81 , L_90 ) ;
F_29 ( V_81 ) ;
goto V_84;
}
F_16 ( STDout , L_91 ) ;
#ifndef F_92
if ( V_92 -> type == V_105 )
F_93 ( STDout , V_92 -> V_92 . V_106 -> V_107 ) ;
else
#endif
#ifndef F_94
if ( V_92 -> type == V_108 )
F_93 ( STDout , V_92 -> V_92 . V_109 -> V_110 ) ;
else
#endif
F_16 ( STDout , L_92 ) ;
F_16 ( STDout , L_85 ) ;
F_44 ( V_92 ) ;
}
else
if ( V_60 == V_14 )
{
T_5 * V_92 ;
V_92 = F_91 ( V_6 ) ;
if ( V_92 == NULL )
{
F_16 ( V_81 , L_93 ) ;
F_29 ( V_81 ) ;
goto V_84;
}
F_95 ( STDout , V_92 ) ;
F_44 ( V_92 ) ;
}
else
if ( V_55 == V_14 )
{
unsigned char * V_111 ;
char * V_112 ;
int V_113 , V_114 ;
F_96 ( F_70 ( V_6 ) ,
V_66 , sizeof V_66 ) ;
F_16 ( STDout , L_94 , V_66 ) ;
V_112 = F_96 (
F_69 ( V_6 ) , V_66 ,
sizeof V_66 ) ;
F_16 ( STDout , L_95 , V_66 ) ;
V_114 = F_97 ( V_6 , NULL ) ;
V_112 = F_98 ( V_114 ) ;
V_111 = ( unsigned char * ) V_112 ;
V_114 = F_99 ( F_70 ( V_6 ) , & V_111 ) ;
F_16 ( STDout , L_96 , V_114 ) ;
V_111 = ( unsigned char * ) V_112 ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ )
{
F_16 ( STDout , L_97 , V_111 [ V_113 ] ) ;
if ( ( V_113 & 0x0f ) == 0x0f ) F_16 ( STDout , L_85 ) ;
}
if ( V_113 % 16 != 0 ) F_16 ( STDout , L_85 ) ;
F_16 ( STDout , L_98 ) ;
V_114 = F_100 ( F_101 ( V_6 ) , & V_111 ) ;
F_16 ( STDout , L_99 , V_114 ) ;
V_111 = ( unsigned char * ) V_112 ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ )
{
F_16 ( STDout , L_97 , V_111 [ V_113 ] ) ;
if ( ( V_113 & 0x0f ) == 0x0f )
F_16 ( STDout , L_85 ) ;
}
if ( V_113 % 16 != 0 ) F_16 ( STDout , L_85 ) ;
F_16 ( STDout , L_98 ) ;
V_114 = F_97 ( V_6 , & V_111 ) ;
F_16 ( STDout , L_100 , V_114 ) ;
V_111 = ( unsigned char * ) V_112 ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ )
{
F_16 ( STDout , L_97 , V_111 [ V_113 ] ) ;
if ( ( V_113 & 0x0f ) == 0x0f )
F_16 ( STDout , L_85 ) ;
}
if ( V_113 % 16 != 0 ) F_16 ( STDout , L_85 ) ;
F_16 ( STDout , L_98 ) ;
F_102 ( V_112 ) ;
}
else if ( V_32 == V_14 )
{
F_103 ( V_17 , V_6 , V_77 , V_78 ) ;
}
else if ( V_36 == V_14 )
{
F_77 ( STDout , L_101 ) ;
F_104 ( STDout , F_55 ( V_6 ) ) ;
F_77 ( STDout , L_85 ) ;
}
else if ( V_37 == V_14 )
{
F_77 ( STDout , L_102 ) ;
F_104 ( STDout , F_57 ( V_6 ) ) ;
F_77 ( STDout , L_85 ) ;
}
else if ( V_65 == V_14 )
{
int V_101 ;
unsigned int V_107 ;
unsigned char V_115 [ V_116 ] ;
const T_9 * V_117 = V_68 ;
if ( ! V_117 )
V_117 = F_105 () ;
if ( ! F_106 ( V_6 , V_117 , V_115 , & V_107 ) )
{
F_16 ( V_81 , L_103 ) ;
goto V_84;
}
F_16 ( STDout , L_104 ,
F_107 ( F_108 ( V_117 ) ) ) ;
for ( V_101 = 0 ; V_101 < ( int ) V_107 ; V_101 ++ )
{
F_16 ( STDout , L_105 , V_115 [ V_101 ] ,
( V_101 + 1 == ( int ) V_107 )
? '\n' : ':' ) ;
}
}
else if ( ( V_45 == V_14 ) && ( V_56 == 0 ) )
{
F_16 ( V_81 , L_106 ) ;
if ( V_11 == NULL )
{
V_11 = F_109 ( V_81 ,
V_27 , V_22 , 0 ,
V_72 , V_3 , L_107 ) ;
if ( V_11 == NULL ) goto V_84;
}
assert ( V_74 ) ;
if ( ! F_110 ( V_6 , V_11 , V_57 , V_54 , V_68 ,
V_69 , V_70 ) ) goto V_84;
}
else if ( V_46 == V_14 )
{
F_16 ( V_81 , L_108 ) ;
if ( V_29 != NULL )
{
V_12 = F_109 ( V_81 ,
V_29 , V_24 ,
0 , V_72 , V_3 ,
L_109 ) ;
if ( V_12 == NULL ) goto V_84;
}
assert ( V_74 ) ;
if ( ! F_111 ( V_63 , V_28 , V_68 , V_6 , V_7 ,
V_12 , V_10 ,
V_30 , V_47 , V_57 , V_54 ,
V_69 , V_70 , V_13 ) )
goto V_84;
}
else if ( V_56 == V_14 )
{
T_5 * V_118 ;
F_16 ( V_81 , L_110 ) ;
if ( V_27 == NULL )
{
F_16 ( V_81 , L_111 ) ;
goto V_84;
}
else
{
V_118 = F_109 ( V_81 ,
V_27 , V_22 , 0 ,
V_72 , V_3 , L_112 ) ;
if ( V_118 == NULL ) goto V_84;
}
F_16 ( V_81 , L_113 ) ;
V_64 = F_112 ( V_6 , V_118 , V_68 ) ;
F_44 ( V_118 ) ;
if ( V_64 == NULL )
{
F_29 ( V_81 ) ;
goto V_84;
}
if ( ! V_44 )
{
F_113 ( V_17 , V_64 ) ;
F_114 ( V_17 , V_64 ) ;
}
V_44 = 1 ;
}
else if ( V_41 == V_14 )
{
F_115 ( V_17 , V_6 ) ;
}
}
}
if ( V_75 )
{
T_14 V_119 = time ( NULL ) + V_76 ;
if ( F_116 ( F_57 ( V_6 ) , & V_119 ) < 0 )
{
F_16 ( V_17 , L_114 ) ;
V_4 = 1 ;
}
else
{
F_16 ( V_17 , L_115 ) ;
V_4 = 0 ;
}
goto V_84;
}
if ( V_44 )
{
V_4 = 0 ;
goto V_84;
}
if ( V_21 == V_120 )
V_14 = F_117 ( V_17 , V_6 ) ;
else if ( V_21 == V_86 )
{
if ( V_50 ) V_14 = F_118 ( V_17 , V_6 ) ;
else V_14 = F_119 ( V_17 , V_6 ) ;
}
else if ( V_21 == V_121 )
{
T_15 V_122 ;
T_16 V_123 ;
V_123 . V_98 = ( unsigned char * ) V_124 ;
V_123 . V_125 = strlen ( V_124 ) ;
V_122 . V_126 = & V_123 ;
V_122 . V_127 = V_6 ;
V_14 = F_120 ( F_121 ( T_15 ) , V_17 , & V_122 ) ;
}
else {
F_16 ( V_81 , L_116 ) ;
goto V_84;
}
if ( ! V_14 )
{
F_16 ( V_81 , L_117 ) ;
F_29 ( V_81 ) ;
goto V_84;
}
V_4 = 0 ;
V_84:
if ( V_74 )
F_122 ( NULL , V_81 ) ;
F_123 () ;
F_124 ( V_69 ) ;
F_125 ( V_17 ) ;
F_125 ( STDout ) ;
F_126 ( V_63 ) ;
F_127 ( V_5 ) ;
F_128 ( V_6 ) ;
F_128 ( V_7 ) ;
F_44 ( V_11 ) ;
F_44 ( V_12 ) ;
if ( V_10 )
F_129 ( V_10 ) ;
F_127 ( V_64 ) ;
F_51 ( V_13 ) ;
F_130 ( V_18 , V_128 ) ;
F_130 ( V_19 , V_128 ) ;
if ( V_72 ) F_102 ( V_72 ) ;
F_131 () ;
F_132 ( V_4 ) ;
}
static T_6 * F_133 ( char * V_28 , char * V_129 , int V_130 )
{
char * V_66 = NULL , * V_131 ;
T_6 * V_132 = NULL ;
T_12 * V_33 = NULL ;
T_17 V_133 ;
V_133 = ( ( V_129 == NULL )
? ( strlen ( V_28 ) + strlen ( V_134 ) + 1 )
: ( strlen ( V_129 ) ) ) + 1 ;
V_66 = F_98 ( V_133 ) ;
if ( V_66 == NULL ) { F_16 ( V_81 , L_118 ) ; goto V_84; }
if ( V_129 == NULL )
{
F_134 ( V_66 , V_28 , V_133 ) ;
for ( V_131 = V_66 ; * V_131 ; V_131 ++ )
if ( * V_131 == '.' )
{
* V_131 = '\0' ;
break;
}
F_135 ( V_66 , V_134 , V_133 ) ;
}
else
F_134 ( V_66 , V_129 , V_133 ) ;
V_33 = F_136 ( V_66 , V_130 , NULL ) ;
if ( V_33 == NULL ) goto V_84;
if ( ! F_74 ( V_33 , 1 ) )
{ F_16 ( V_81 , L_119 ) ; goto V_84; }
if ( ! F_137 ( V_66 , NULL , V_33 , & V_132 ) ) goto V_84;
V_84:
if ( V_66 ) F_102 ( V_66 ) ;
F_76 ( V_33 ) ;
return V_132 ;
}
static int T_18 V_87 ( int V_135 , T_19 * V_63 )
{
int V_136 ;
T_3 * V_137 ;
V_136 = F_138 ( V_63 ) ;
if ( V_136 == V_138 )
return 1 ;
if ( V_135 )
{
F_16 ( V_81 , L_120 ) ;
return 0 ;
}
else
{
V_137 = F_139 ( V_63 ) ;
F_45 ( V_81 , NULL , F_70 ( V_137 ) , 0 ) ;
F_16 ( V_81 , L_121 ,
V_136 , F_140 ( V_63 ) ,
F_141 ( V_136 ) ) ;
return 1 ;
}
}
static int F_110 ( T_3 * V_6 , T_5 * V_92 , int V_57 , int V_54 , const T_9 * V_68 ,
T_10 * V_139 , char * V_140 )
{
T_5 * V_141 ;
V_141 = F_91 ( V_6 ) ;
F_142 ( V_141 , V_92 ) ;
F_143 ( V_141 , 1 ) ;
F_44 ( V_141 ) ;
if ( ! F_52 ( V_6 , F_70 ( V_6 ) ) ) goto V_136;
if ( F_54 ( F_55 ( V_6 ) , 0 ) == NULL ) goto V_136;
if ( F_54 ( F_57 ( V_6 ) , ( long ) 60 * 60 * 24 * V_57 ) == NULL )
goto V_136;
if ( ! F_58 ( V_6 , V_92 ) ) goto V_136;
if ( V_54 )
{
while ( F_144 ( V_6 ) > 0 ) F_145 ( V_6 , 0 ) ;
}
if ( V_139 )
{
T_11 V_63 ;
F_146 ( V_6 , 2 ) ;
F_147 ( & V_63 , V_6 , V_6 , NULL , NULL , 0 ) ;
F_35 ( & V_63 , V_139 ) ;
if ( ! F_36 ( V_139 , & V_63 , V_140 , V_6 ) ) goto V_136;
}
if ( ! F_148 ( V_6 , V_92 , V_68 ) ) goto V_136;
return 1 ;
V_136:
F_29 ( V_81 ) ;
return 0 ;
}
static int F_90 ( T_7 * V_142 , T_3 * V_127 , T_13 * V_143 )
{
int V_144 , V_14 , V_145 ;
char * V_146 ;
V_144 = F_149 ( V_143 ) ;
V_146 = F_150 ( V_143 ) ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ )
{
V_145 = F_151 ( V_127 , V_144 , V_14 ) ;
F_16 ( V_142 , L_122 , V_146 , V_14 ? L_123 : L_124 ) ;
if ( V_145 == 1 ) F_16 ( V_142 , L_125 ) ;
else if ( V_145 == 0 ) F_16 ( V_142 , L_126 ) ;
else F_16 ( V_142 , L_127 , V_145 ) ;
}
return 1 ;
}
