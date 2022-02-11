int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 1 ;
T_2 * V_5 = NULL ;
T_3 * V_6 = NULL , * V_7 = NULL ;
T_4 * V_8 ;
F_1 ( V_9 ) * V_10 = NULL ;
T_5 * V_11 = NULL , * V_12 = NULL , * V_13 = NULL ;
T_6 * V_14 = NULL ;
int V_15 , V_16 , V_17 = 0 , V_18 = 0 ;
T_7 * V_19 = NULL ;
T_7 * STDout = NULL ;
F_1 ( T_4 ) * V_20 = NULL , * V_21 = NULL ;
int V_22 , V_23 , V_24 , V_25 , V_26 ;
char * V_27 = NULL , * V_28 = NULL , * V_29 = NULL , * V_30 = NULL ;
char * V_31 = NULL , * V_32 = NULL ;
char * V_33 = NULL ;
char * V_34 = NULL ;
int V_35 = 0 , V_36 = 0 , V_37 = 0 , V_38 = 0 , V_39 =
0 , V_40 = 0 ;
int V_41 = 0 ;
int V_42 = 0 , V_43 = 0 , V_44 = 0 ;
#ifndef F_2
int V_45 = 0 , V_46 = 0 ;
#endif
int V_47 = 0 , V_48 = 0 , V_49 = 0 , V_50 = 0 , V_51 = 0 ;
int V_52 = 0 ;
int V_53 = 0 , V_54 = 0 , V_55 = 0 , V_56 = 0 , V_57 = 0 ;
int V_58 = 0 ;
int V_59 = 0 , V_60 = V_61 , V_62 = 0 , V_63 = 0 ;
int V_64 = 0 ;
const char * * V_65 ;
T_8 * V_66 = NULL ;
T_2 * V_67 = NULL ;
int V_68 = 0 ;
char V_69 [ 256 ] ;
const T_9 * V_70 , * V_71 = NULL ;
T_10 * V_72 = NULL ;
char * V_73 = NULL , * V_74 = NULL , * V_75 = NULL , * V_76 = NULL ;
int V_77 = 0 ;
int V_78 = 0 , V_79 = 0 ;
unsigned long V_80 = 0 , V_81 = 0 ;
char * V_82 = NULL ;
char * V_83 = NULL ;
char * V_84 = NULL ;
#ifndef F_3
char * V_85 = NULL ;
#endif
V_86 = 0 ;
F_4 () ;
if ( V_87 == NULL )
V_87 = F_5 ( V_88 , V_89 ) ;
if ( ! F_6 ( V_87 , NULL ) )
goto V_90;
STDout = F_5 ( stdout , V_89 ) ;
#ifdef F_7
{
T_7 * V_91 = F_8 ( F_9 () ) ;
STDout = F_10 ( V_91 , STDout ) ;
}
#endif
V_22 = V_92 ;
V_23 = V_92 ;
V_24 = V_92 ;
V_25 = V_92 ;
V_26 = V_92 ;
V_66 = F_11 () ;
if ( V_66 == NULL )
goto V_90;
F_12 ( V_66 , V_93 ) ;
V_1 -- ;
V_2 ++ ;
V_16 = 0 ;
while ( V_1 >= 1 ) {
if ( strcmp ( * V_2 , L_1 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_22 = F_13 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_2 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_23 = F_13 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_3 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_24 = F_13 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_4 ) == 0 ) {
V_86 = 1 ;
V_77 = 1 ;
} else if ( strcmp ( * V_2 , L_5 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_25 = F_13 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_6 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_26 = F_13 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_7 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
if ( ! V_10 )
V_10 = F_14 () ;
if ( ! V_10 || ! F_15 ( V_10 , * ( ++ V_2 ) ) )
goto V_94;
}
#ifdef F_16
else if ( strcmp ( * V_2 , L_8 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_95 = atoi ( * ( ++ V_2 ) ) - 1 ;
}
#endif
else if ( strcmp ( * V_2 , L_9 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_60 = atoi ( * ( ++ V_2 ) ) ;
if ( V_60 == 0 ) {
F_17 ( V_87 , L_10 ) ;
goto V_94;
}
} else if ( strcmp ( * V_2 , L_11 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_76 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_12 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_74 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_13 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_73 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_14 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_27 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_15 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_28 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_16 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_29 = * ( ++ V_2 ) ;
V_48 = ++ V_16 ;
V_77 = 1 ;
} else if ( strcmp ( * V_2 , L_17 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_30 = * ( ++ V_2 ) ;
V_49 = ++ V_16 ;
V_77 = 1 ;
} else if ( strcmp ( * V_2 , L_18 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_31 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_19 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_32 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_20 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
if ( ! ( V_14 = F_18 ( NULL , * ( ++ V_2 ) ) ) )
goto V_94;
} else if ( strcmp ( * V_2 , L_21 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_33 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_22 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
if ( ! ( V_8 = F_19 ( * ( ++ V_2 ) , 0 ) ) ) {
F_17 ( V_87 , L_23 , * V_2 ) ;
goto V_94;
}
if ( ! V_20 )
V_20 = F_20 () ;
F_21 ( V_20 , V_8 ) ;
V_53 = 1 ;
} else if ( strcmp ( * V_2 , L_24 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
if ( ! ( V_8 = F_19 ( * ( ++ V_2 ) , 0 ) ) ) {
F_17 ( V_87 ,
L_25 , * V_2 ) ;
goto V_94;
}
if ( ! V_21 )
V_21 = F_20 () ;
F_21 ( V_21 , V_8 ) ;
V_53 = 1 ;
} else if ( strcmp ( * V_2 , L_26 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_34 = * ( ++ V_2 ) ;
V_53 = 1 ;
} else if ( strcmp ( * V_2 , L_27 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
if ( ! F_22 ( & V_81 , * ( ++ V_2 ) ) )
goto V_94;
} else if ( strcmp ( * V_2 , L_28 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
if ( ! F_23 ( & V_80 , * ( ++ V_2 ) ) )
goto V_94;
}
#ifndef F_3
else if ( strcmp ( * V_2 , L_29 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_85 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_30 ) == 0 )
V_58 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_31 ) == 0 )
V_51 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_32 ) == 0 )
V_52 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_33 ) == 0 )
V_36 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_34 ) == 0 )
V_41 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_35 ) == 0 )
V_62 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_36 ) == 0 )
V_63 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_37 ) == 0 )
V_59 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_38 ) == 0 )
V_35 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_39 ) == 0
|| strcmp ( * V_2 , L_40 ) == 0 )
V_42 = ++ V_16 ;
#ifndef F_2
else if ( strcmp ( * V_2 , L_41 ) == 0 )
V_45 = ++ V_16 ;
#endif
else if ( strcmp ( * V_2 , L_42 ) == 0 )
V_43 = ++ V_16 ;
#ifndef F_2
else if ( strcmp ( * V_2 , L_43 ) == 0 )
V_46 = ++ V_16 ;
#endif
else if ( strcmp ( * V_2 , L_44 ) == 0 )
V_37 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_45 ) == 0 )
V_38 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_46 ) == 0 )
V_68 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_47 ) == 0 ) {
V_39 = ++ V_16 ;
V_40 = ++ V_16 ;
} else if ( strcmp ( * V_2 , L_48 ) == 0 )
V_64 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_49 ) == 0 )
V_39 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_50 ) == 0 )
V_40 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_51 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_79 = atoi ( * ( ++ V_2 ) ) ;
V_78 = 1 ;
} else if ( strcmp ( * V_2 , L_52 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_82 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_53 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_83 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_54 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_94;
V_84 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_55 ) == 0 )
V_47 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_56 ) == 0 )
V_53 = 1 ;
else if ( strcmp ( * V_2 , L_57 ) == 0 )
V_54 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_58 ) == 0 )
V_55 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_59 ) == 0 )
V_56 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_60 ) == 0 )
V_50 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_61 ) == 0 )
V_57 = 1 ;
#if 1
else if ( strcmp ( * V_2 , L_62 ) == 0 ) {
F_17 ( V_87 , L_63 ) ;
V_57 = 1 ;
}
#endif
else if ( strcmp ( * V_2 , L_64 ) == 0 )
V_44 = ++ V_16 ;
else if ( strcmp ( * V_2 , L_65 ) == 0 )
V_18 = 1 ;
else if ( ( V_70 = F_24 ( * V_2 + 1 ) ) ) {
V_71 = V_70 ;
} else {
F_17 ( V_87 , L_66 , * V_2 ) ;
V_17 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_17 ) {
V_94:
for ( V_65 = V_96 ; ( * V_65 != NULL ) ; V_65 ++ )
F_17 ( V_87 , L_67 , * V_65 ) ;
goto V_90;
}
#ifndef F_3
V_3 = F_25 ( V_87 , V_85 , 0 ) ;
#endif
if ( V_77 )
F_26 ( NULL , V_87 , 0 ) ;
F_27 () ;
if ( ! F_28 ( V_87 , V_76 , NULL , & V_75 , NULL ) ) {
F_17 ( V_87 , L_68 ) ;
goto V_90;
}
if ( ! F_29 ( V_66 ) ) {
F_30 ( V_87 ) ;
goto V_90;
}
if ( V_33 ) {
V_13 = F_31 ( V_87 , V_33 , V_24 , 0 ,
NULL , V_3 , L_69 ) ;
if ( V_13 == NULL )
goto V_90;
}
if ( ( V_31 == NULL ) && ( V_49 ) && ( V_25 == V_92 ) ) {
V_31 = V_30 ;
} else if ( ( V_49 ) && ( V_31 == NULL ) ) {
F_17 ( V_87 ,
L_70 ) ;
goto V_90;
}
if ( V_74 ) {
long V_97 = - 1 ;
T_11 V_98 ;
V_72 = F_32 ( NULL ) ;
if ( ! F_33 ( V_72 , V_74 , & V_97 ) ) {
if ( V_97 <= 0 )
F_17 ( V_87 ,
L_71 , V_74 ) ;
else
F_17 ( V_87 ,
L_72 ,
V_97 , V_74 ) ;
goto V_90;
}
if ( ! V_73 ) {
V_73 = F_34 ( V_72 , L_73 , L_74 ) ;
if ( ! V_73 ) {
F_35 () ;
V_73 = L_73 ;
}
}
F_36 ( & V_98 ) ;
F_37 ( & V_98 , V_72 ) ;
if ( ! F_38 ( V_72 , & V_98 , V_73 , NULL ) ) {
F_17 ( V_87 ,
L_75 , V_73 ) ;
F_30 ( V_87 ) ;
goto V_90;
}
}
if ( V_86 ) {
T_5 * V_99 ;
T_7 * V_100 ;
if ( ! V_48 && ! V_49 ) {
F_17 ( V_87 , L_76 ) ;
goto V_90;
}
V_100 = F_8 ( F_39 () ) ;
if ( V_100 == NULL ) {
F_30 ( V_87 ) ;
goto V_90;
}
if ( V_27 == NULL )
F_40 ( V_100 , V_101 , V_89 | V_102 ) ;
else {
if ( F_41 ( V_100 , V_27 ) <= 0 ) {
perror ( V_27 ) ;
F_42 ( V_100 ) ;
goto V_90;
}
}
V_5 = F_43 ( V_100 , NULL , NULL , NULL ) ;
F_42 ( V_100 ) ;
if ( V_5 == NULL ) {
F_30 ( V_87 ) ;
goto V_90;
}
if ( ( V_5 -> V_103 == NULL ) ||
( V_5 -> V_103 -> V_63 == NULL ) ||
( V_5 -> V_103 -> V_63 -> V_104 == NULL ) ||
( V_5 -> V_103 -> V_63 -> V_104 -> V_105 == NULL ) ) {
F_17 ( V_87 ,
L_77 ) ;
F_17 ( V_87 , L_78 ) ;
goto V_90;
}
if ( ( V_99 = F_44 ( V_5 ) ) == NULL ) {
F_17 ( V_87 , L_79 ) ;
goto V_90;
}
V_15 = F_45 ( V_5 , V_99 ) ;
F_46 ( V_99 ) ;
if ( V_15 < 0 ) {
F_17 ( V_87 , L_80 ) ;
F_30 ( V_87 ) ;
goto V_90;
}
if ( V_15 == 0 ) {
F_17 ( V_87 ,
L_81 ) ;
goto V_90;
} else
F_17 ( V_87 , L_82 ) ;
F_47 ( V_87 , L_83 , F_48 ( V_5 ) ,
V_80 ) ;
if ( ( V_6 = F_49 () ) == NULL )
goto V_90;
if ( V_14 == NULL ) {
V_14 = F_50 () ;
if ( ! V_14 || ! F_51 ( NULL , V_14 ) )
goto V_90;
if ( ! F_52 ( V_6 , V_14 ) )
goto V_90;
F_53 ( V_14 ) ;
V_14 = NULL ;
} else if ( ! F_52 ( V_6 , V_14 ) )
goto V_90;
if ( ! F_54 ( V_6 , V_5 -> V_103 -> V_37 ) )
goto V_90;
if ( ! F_55 ( V_6 , V_5 -> V_103 -> V_37 ) )
goto V_90;
F_56 ( F_57 ( V_6 ) , 0 ) ;
F_58 ( F_59 ( V_6 ) , V_60 , 0 , NULL ) ;
if ( V_13 )
F_60 ( V_6 , V_13 ) ;
else {
V_99 = F_44 ( V_5 ) ;
F_60 ( V_6 , V_99 ) ;
F_46 ( V_99 ) ;
}
} else
V_6 = F_61 ( V_87 , V_27 , V_22 , NULL , V_3 , L_84 ) ;
if ( V_6 == NULL )
goto V_90;
if ( V_49 ) {
V_7 = F_61 ( V_87 , V_30 , V_25 , NULL , V_3 , L_85 ) ;
if ( V_7 == NULL )
goto V_90;
}
if ( ! V_47 || V_35 || V_41 ) {
F_62 ( L_86 , L_87 , L_88 ) ;
V_19 = F_8 ( F_39 () ) ;
if ( V_19 == NULL ) {
F_30 ( V_87 ) ;
goto V_90;
}
if ( V_28 == NULL ) {
F_40 ( V_19 , stdout , V_89 ) ;
#ifdef F_7
{
T_7 * V_91 = F_8 ( F_9 () ) ;
V_19 = F_10 ( V_91 , V_19 ) ;
}
#endif
} else {
if ( F_63 ( V_19 , V_28 ) <= 0 ) {
perror ( V_28 ) ;
goto V_90;
}
}
}
if ( V_34 )
F_64 ( V_6 , ( unsigned char * ) V_34 , - 1 ) ;
if ( V_54 )
F_65 ( V_6 ) ;
if ( V_55 )
F_66 ( V_6 ) ;
if ( V_20 ) {
for ( V_15 = 0 ; V_15 < F_67 ( V_20 ) ; V_15 ++ ) {
V_8 = F_68 ( V_20 , V_15 ) ;
F_69 ( V_6 , V_8 ) ;
}
}
if ( V_21 ) {
for ( V_15 = 0 ; V_15 < F_67 ( V_21 ) ; V_15 ++ ) {
V_8 = F_68 ( V_21 , V_15 ) ;
F_70 ( V_6 , V_8 ) ;
}
}
if ( V_16 ) {
for ( V_15 = 1 ; V_15 <= V_16 ; V_15 ++ ) {
if ( V_38 == V_15 ) {
F_47 ( STDout , L_89 ,
F_71 ( V_6 ) , V_80 ) ;
} else if ( V_37 == V_15 ) {
F_47 ( STDout , L_90 ,
F_72 ( V_6 ) , V_80 ) ;
} else if ( V_36 == V_15 ) {
F_17 ( STDout , L_91 ) ;
F_73 ( STDout , F_74 ( V_6 ) ) ;
F_17 ( STDout , L_92 ) ;
} else if ( V_41 == V_15 ) {
T_12 * V_106 ;
T_6 * V_107 ;
V_107 = F_74 ( V_6 ) ;
V_106 = F_75 ( V_107 , NULL ) ;
if ( ! V_106 )
goto V_90;
if ( ! F_76 ( V_106 , 1 ) )
goto V_90;
V_107 = F_77 ( V_106 , NULL ) ;
if ( ! V_107 )
goto V_90;
F_78 ( V_106 ) ;
F_73 ( V_19 , V_107 ) ;
F_53 ( V_107 ) ;
F_79 ( V_19 , L_92 ) ;
} else if ( ( V_51 == V_15 ) || ( V_52 == V_15 ) ) {
int V_108 ;
F_1 ( V_9 ) * V_109 ;
if ( V_51 == V_15 )
V_109 = F_80 ( V_6 ) ;
else
V_109 = F_81 ( V_6 ) ;
for ( V_108 = 0 ; V_108 < F_82 ( V_109 ) ; V_108 ++ )
F_17 ( STDout , L_93 ,
F_83 ( V_109 , V_108 ) ) ;
F_84 ( V_109 ) ;
} else if ( V_56 == V_15 ) {
unsigned char * V_110 ;
V_110 = F_85 ( V_6 , NULL ) ;
if ( V_110 )
F_17 ( STDout , L_93 , V_110 ) ;
else
F_79 ( STDout , L_94 ) ;
} else if ( V_42 == V_15 ) {
F_17 ( STDout , L_95 , F_86 ( V_6 ) ) ;
}
#ifndef F_2
else if ( V_45 == V_15 ) {
F_17 ( STDout , L_95 , F_87 ( V_6 ) ) ;
}
#endif
else if ( V_43 == V_15 ) {
F_17 ( STDout , L_95 , F_88 ( V_6 ) ) ;
}
#ifndef F_2
else if ( V_46 == V_15 ) {
F_17 ( STDout , L_95 , F_89 ( V_6 ) ) ;
}
#endif
else if ( V_64 == V_15 ) {
T_13 * V_111 ;
int V_108 ;
F_17 ( STDout , L_96 ) ;
for ( V_108 = 0 ; V_108 < F_90 () ; V_108 ++ ) {
V_111 = F_91 ( V_108 ) ;
F_92 ( STDout , V_6 , V_111 ) ;
}
} else if ( V_62 == V_15 ) {
T_5 * V_99 ;
V_99 = F_93 ( V_6 ) ;
if ( V_99 == NULL ) {
F_17 ( V_87 , L_97 ) ;
F_30 ( V_87 ) ;
goto V_90;
}
F_17 ( STDout , L_98 ) ;
#ifndef F_94
if ( V_99 -> type == V_112 )
F_95 ( STDout , V_99 -> V_99 . V_113 -> V_114 ) ;
else
#endif
#ifndef F_96
if ( V_99 -> type == V_115 )
F_95 ( STDout , V_99 -> V_99 . V_116 -> V_117 ) ;
else
#endif
F_17 ( STDout , L_99 ) ;
F_17 ( STDout , L_92 ) ;
F_46 ( V_99 ) ;
} else if ( V_63 == V_15 ) {
T_5 * V_99 ;
V_99 = F_93 ( V_6 ) ;
if ( V_99 == NULL ) {
F_17 ( V_87 , L_100 ) ;
F_30 ( V_87 ) ;
goto V_90;
}
F_97 ( STDout , V_99 ) ;
F_46 ( V_99 ) ;
} else if ( V_58 == V_15 ) {
unsigned char * V_118 ;
char * V_119 ;
int V_120 , V_121 ;
F_98 ( F_72 ( V_6 ) , V_69 , sizeof V_69 ) ;
F_17 ( STDout , L_101 , V_69 ) ;
V_119 = F_98 ( F_71 ( V_6 ) , V_69 ,
sizeof V_69 ) ;
F_17 ( STDout , L_102 , V_69 ) ;
V_121 = F_99 ( V_6 , NULL ) ;
V_119 = F_100 ( V_121 ) ;
V_118 = ( unsigned char * ) V_119 ;
V_121 = F_101 ( F_72 ( V_6 ) , & V_118 ) ;
F_17 ( STDout , L_103 ,
V_121 ) ;
V_118 = ( unsigned char * ) V_119 ;
for ( V_120 = 0 ; V_120 < V_121 ; V_120 ++ ) {
F_17 ( STDout , L_104 , V_118 [ V_120 ] ) ;
if ( ( V_120 & 0x0f ) == 0x0f )
F_17 ( STDout , L_92 ) ;
}
if ( V_120 % 16 != 0 )
F_17 ( STDout , L_92 ) ;
F_17 ( STDout , L_105 ) ;
V_121 = F_102 ( F_103 ( V_6 ) , & V_118 ) ;
F_17 ( STDout , L_106 , V_121 ) ;
V_118 = ( unsigned char * ) V_119 ;
for ( V_120 = 0 ; V_120 < V_121 ; V_120 ++ ) {
F_17 ( STDout , L_104 , V_118 [ V_120 ] ) ;
if ( ( V_120 & 0x0f ) == 0x0f )
F_17 ( STDout , L_92 ) ;
}
if ( V_120 % 16 != 0 )
F_17 ( STDout , L_92 ) ;
F_17 ( STDout , L_105 ) ;
V_121 = F_99 ( V_6 , & V_118 ) ;
F_17 ( STDout , L_107 ,
V_121 ) ;
V_118 = ( unsigned char * ) V_119 ;
for ( V_120 = 0 ; V_120 < V_121 ; V_120 ++ ) {
F_17 ( STDout , L_104 , V_118 [ V_120 ] ) ;
if ( ( V_120 & 0x0f ) == 0x0f )
F_17 ( STDout , L_92 ) ;
}
if ( V_120 % 16 != 0 )
F_17 ( STDout , L_92 ) ;
F_17 ( STDout , L_105 ) ;
F_104 ( V_119 ) ;
} else if ( V_35 == V_15 ) {
F_105 ( STDout , V_6 , V_80 , V_81 ) ;
} else if ( V_39 == V_15 ) {
F_79 ( STDout , L_108 ) ;
F_106 ( STDout , F_57 ( V_6 ) ) ;
F_79 ( STDout , L_92 ) ;
} else if ( V_40 == V_15 ) {
F_79 ( STDout , L_109 ) ;
F_106 ( STDout , F_59 ( V_6 ) ) ;
F_79 ( STDout , L_92 ) ;
} else if ( V_68 == V_15 ) {
int V_108 ;
unsigned int V_114 ;
unsigned char V_122 [ V_123 ] ;
const T_9 * V_124 = V_71 ;
if ( ! V_124 )
V_124 = F_107 () ;
if ( ! F_108 ( V_6 , V_124 , V_122 , & V_114 ) ) {
F_17 ( V_87 , L_110 ) ;
goto V_90;
}
F_17 ( STDout , L_111 ,
F_109 ( F_110 ( V_124 ) ) ) ;
for ( V_108 = 0 ; V_108 < ( int ) V_114 ; V_108 ++ ) {
F_17 ( STDout , L_112 , V_122 [ V_108 ] , ( V_108 + 1 == ( int ) V_114 )
? '\n' : ':' ) ;
}
}
else if ( ( V_48 == V_15 ) && ( V_59 == 0 ) ) {
F_17 ( V_87 , L_113 ) ;
if ( V_11 == NULL ) {
V_11 = F_111 ( V_87 ,
V_29 , V_24 , 0 ,
V_75 , V_3 , L_114 ) ;
if ( V_11 == NULL )
goto V_90;
}
assert ( V_77 ) ;
if ( ! F_112 ( V_6 , V_11 , V_60 , V_57 , V_71 , V_72 , V_73 ) )
goto V_90;
} else if ( V_49 == V_15 ) {
F_17 ( V_87 , L_115 ) ;
if ( V_31 != NULL ) {
V_12 = F_111 ( V_87 ,
V_31 , V_26 ,
0 , V_75 , V_3 , L_116 ) ;
if ( V_12 == NULL )
goto V_90;
}
assert ( V_77 ) ;
if ( ! F_113 ( V_66 , V_30 , V_71 , V_6 , V_7 ,
V_12 , V_10 ,
V_32 , V_50 , V_60 , V_57 ,
V_72 , V_73 , V_14 ) )
goto V_90;
} else if ( V_59 == V_15 ) {
T_5 * V_125 ;
F_17 ( V_87 , L_117 ) ;
if ( V_29 == NULL ) {
F_17 ( V_87 , L_118 ) ;
goto V_90;
} else {
V_125 = F_111 ( V_87 ,
V_29 , V_24 , 0 ,
V_75 , V_3 , L_119 ) ;
if ( V_125 == NULL )
goto V_90;
}
F_17 ( V_87 , L_120 ) ;
V_67 = F_114 ( V_6 , V_125 , V_71 ) ;
F_46 ( V_125 ) ;
if ( V_67 == NULL ) {
F_30 ( V_87 ) ;
goto V_90;
}
if ( ! V_47 ) {
F_115 ( V_19 , V_67 ) ;
F_116 ( V_19 , V_67 ) ;
}
V_47 = 1 ;
} else if ( V_44 == V_15 ) {
F_117 ( V_19 , V_6 ) ;
}
}
}
if ( V_78 ) {
T_14 V_126 = time ( NULL ) + V_79 ;
if ( F_118 ( F_59 ( V_6 ) , & V_126 ) < 0 ) {
F_17 ( V_19 , L_121 ) ;
V_4 = 1 ;
} else {
F_17 ( V_19 , L_122 ) ;
V_4 = 0 ;
}
goto V_90;
}
F_119 ( STDout , V_6 , V_82 , V_83 , V_84 ) ;
if ( V_47 ) {
V_4 = 0 ;
goto V_90;
}
if ( V_18 )
V_6 -> V_127 -> V_105 [ V_6 -> V_127 -> V_128 - 1 ] ^= 0x1 ;
if ( V_23 == V_129 )
V_15 = F_120 ( V_19 , V_6 ) ;
else if ( V_23 == V_92 ) {
if ( V_53 )
V_15 = F_121 ( V_19 , V_6 ) ;
else
V_15 = F_122 ( V_19 , V_6 ) ;
} else if ( V_23 == V_130 ) {
T_15 V_131 ;
T_16 V_132 ;
V_132 . V_105 = ( unsigned char * ) V_133 ;
V_132 . V_128 = strlen ( V_133 ) ;
V_131 . V_134 = & V_132 ;
V_131 . V_135 = V_6 ;
V_15 = F_123 ( F_124 ( T_15 ) , V_19 , & V_131 ) ;
} else {
F_17 ( V_87 , L_123 ) ;
goto V_90;
}
if ( ! V_15 ) {
F_17 ( V_87 , L_124 ) ;
F_30 ( V_87 ) ;
goto V_90;
}
V_4 = 0 ;
V_90:
if ( V_77 )
F_125 ( NULL , V_87 ) ;
F_126 () ;
F_127 ( V_72 ) ;
F_128 ( V_19 ) ;
F_128 ( STDout ) ;
F_129 ( V_66 ) ;
F_130 ( V_5 ) ;
F_131 ( V_6 ) ;
F_131 ( V_7 ) ;
F_46 ( V_11 ) ;
F_46 ( V_12 ) ;
F_46 ( V_13 ) ;
if ( V_10 )
F_132 ( V_10 ) ;
F_130 ( V_67 ) ;
F_53 ( V_14 ) ;
F_133 ( V_20 , V_136 ) ;
F_133 ( V_21 , V_136 ) ;
if ( V_75 )
F_104 ( V_75 ) ;
F_134 () ;
F_135 ( V_4 ) ;
}
static T_6 * F_136 ( char * V_30 , char * V_137 ,
int V_138 )
{
char * V_69 = NULL , * V_139 ;
T_6 * V_140 = NULL ;
T_12 * V_36 = NULL ;
T_17 V_141 ;
V_141 = ( ( V_137 == NULL )
? ( strlen ( V_30 ) + strlen ( V_142 ) + 1 )
: ( strlen ( V_137 ) ) ) + 1 ;
V_69 = F_100 ( V_141 ) ;
if ( V_69 == NULL ) {
F_17 ( V_87 , L_125 ) ;
goto V_90;
}
if ( V_137 == NULL ) {
F_137 ( V_69 , V_30 , V_141 ) ;
for ( V_139 = V_69 ; * V_139 ; V_139 ++ )
if ( * V_139 == '.' ) {
* V_139 = '\0' ;
break;
}
F_138 ( V_69 , V_142 , V_141 ) ;
} else
F_137 ( V_69 , V_137 , V_141 ) ;
V_36 = F_139 ( V_69 , V_138 , NULL ) ;
if ( V_36 == NULL )
goto V_90;
if ( ! F_76 ( V_36 , 1 ) ) {
F_17 ( V_87 , L_126 ) ;
goto V_90;
}
if ( ! F_140 ( V_69 , NULL , V_36 , & V_140 ) )
goto V_90;
V_90:
if ( V_69 )
F_104 ( V_69 ) ;
F_78 ( V_36 ) ;
return V_140 ;
}
static int T_18 V_93 ( int V_143 , T_19 * V_66 )
{
int V_144 ;
T_3 * V_145 ;
V_144 = F_141 ( V_66 ) ;
if ( V_144 == V_146 )
return 1 ;
if ( V_143 ) {
F_17 ( V_87 ,
L_127 ) ;
return 0 ;
} else {
V_145 = F_142 ( V_66 ) ;
F_47 ( V_87 , NULL , F_72 ( V_145 ) , 0 ) ;
F_17 ( V_87 ,
L_128 , V_144 ,
F_143 ( V_66 ) ,
F_144 ( V_144 ) ) ;
return 1 ;
}
}
static int F_112 ( T_3 * V_6 , T_5 * V_99 , int V_60 , int V_57 ,
const T_9 * V_71 , T_10 * V_147 , char * V_148 )
{
T_5 * V_149 ;
V_149 = F_93 ( V_6 ) ;
F_145 ( V_149 , V_99 ) ;
F_146 ( V_149 , 1 ) ;
F_46 ( V_149 ) ;
if ( ! F_54 ( V_6 , F_72 ( V_6 ) ) )
goto V_144;
if ( F_56 ( F_57 ( V_6 ) , 0 ) == NULL )
goto V_144;
if ( F_56 ( F_59 ( V_6 ) , ( long ) 60 * 60 * 24 * V_60 ) ==
NULL )
goto V_144;
if ( ! F_60 ( V_6 , V_99 ) )
goto V_144;
if ( V_57 ) {
while ( F_147 ( V_6 ) > 0 )
F_148 ( V_6 , 0 ) ;
}
if ( V_147 ) {
T_11 V_66 ;
#ifdef F_16
F_149 ( V_6 , V_95 ) ;
#else
F_149 ( V_6 , 2 ) ;
#endif
F_150 ( & V_66 , V_6 , V_6 , NULL , NULL , 0 ) ;
F_37 ( & V_66 , V_147 ) ;
if ( ! F_38 ( V_147 , & V_66 , V_148 , V_6 ) )
goto V_144;
}
if ( ! F_151 ( V_6 , V_99 , V_71 ) )
goto V_144;
return 1 ;
V_144:
F_30 ( V_87 ) ;
return 0 ;
}
static int F_92 ( T_7 * V_150 , T_3 * V_135 , T_13 * V_151 )
{
int V_152 , V_15 , V_153 ;
char * V_154 ;
V_152 = F_152 ( V_151 ) ;
V_154 = F_153 ( V_151 ) ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ ) {
V_153 = F_154 ( V_135 , V_152 , V_15 ) ;
F_17 ( V_150 , L_129 , V_154 , V_15 ? L_130 : L_131 ) ;
if ( V_153 == 1 )
F_17 ( V_150 , L_132 ) ;
else if ( V_153 == 0 )
F_17 ( V_150 , L_133 ) ;
else
F_17 ( V_150 , L_134 , V_153 ) ;
}
return 1 ;
}
