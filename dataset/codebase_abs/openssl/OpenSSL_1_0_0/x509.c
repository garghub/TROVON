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
#ifndef F_2
int V_40 = 0 , V_41 = 0 ;
#endif
int V_42 = 0 , V_43 = 0 , V_44 = 0 , V_45 = 0 , V_46 = 0 ;
int V_47 = 0 ;
int V_48 = 0 , V_49 = 0 , V_50 = 0 , V_51 = 0 , V_52 = 0 ;
int V_53 = 0 ;
int V_54 = 0 , V_55 = V_56 , V_57 = 0 , V_58 = 0 ;
int V_59 = 0 ;
const char * * V_60 ;
T_8 * V_61 = NULL ;
T_2 * V_62 = NULL ;
int V_63 = 0 ;
char V_64 [ 256 ] ;
const T_9 * V_65 , * V_66 = NULL ;
T_10 * V_67 = NULL ;
char * V_68 = NULL , * V_69 = NULL , * V_70 = NULL , * V_71 = NULL ;
int V_72 = 0 ;
int V_73 = 0 , V_74 = 0 ;
unsigned long V_75 = 0 , V_76 = 0 ;
#ifndef F_3
char * V_77 = NULL ;
#endif
V_78 = 0 ;
F_4 () ;
if ( V_79 == NULL )
V_79 = F_5 ( V_80 , V_81 ) ;
if ( ! F_6 ( V_79 , NULL ) )
goto V_82;
STDout = F_5 ( stdout , V_81 ) ;
#ifdef F_7
{
T_7 * V_83 = F_8 ( F_9 () ) ;
STDout = F_10 ( V_83 , STDout ) ;
}
#endif
V_18 = V_84 ;
V_19 = V_84 ;
V_20 = V_84 ;
V_21 = V_84 ;
V_22 = V_84 ;
V_61 = F_11 () ;
if ( V_61 == NULL ) goto V_82;
F_12 ( V_61 , V_85 ) ;
V_1 -- ;
V_2 ++ ;
V_13 = 0 ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_18 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_19 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_20 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
V_78 = 1 ;
V_72 = 1 ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_21 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_22 = F_13 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_55 = atoi ( * ( ++ V_2 ) ) ;
if ( V_55 == 0 )
{
F_14 ( STDout , L_8 ) ;
goto V_86;
}
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_71 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_69 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_68 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_23 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_24 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_25 = * ( ++ V_2 ) ;
V_43 = ++ V_13 ;
V_72 = 1 ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_26 = * ( ++ V_2 ) ;
V_44 = ++ V_13 ;
V_72 = 1 ;
}
else if ( strcmp ( * V_2 , L_16 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_27 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_17 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_28 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_18 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
if ( ! ( V_11 = F_15 ( NULL , * ( ++ V_2 ) ) ) )
goto V_86;
}
else if ( strcmp ( * V_2 , L_19 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
if ( ! ( V_8 = F_16 ( * ( ++ V_2 ) , 0 ) ) )
{
F_14 ( V_79 ,
L_20 , * V_2 ) ;
goto V_86;
}
if ( ! V_16 ) V_16 = F_17 () ;
F_18 ( V_16 , V_8 ) ;
V_48 = 1 ;
}
else if ( strcmp ( * V_2 , L_21 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
if ( ! ( V_8 = F_16 ( * ( ++ V_2 ) , 0 ) ) )
{
F_14 ( V_79 ,
L_22 , * V_2 ) ;
goto V_86;
}
if ( ! V_17 ) V_17 = F_17 () ;
F_18 ( V_17 , V_8 ) ;
V_48 = 1 ;
}
else if ( strcmp ( * V_2 , L_23 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_29 = * ( ++ V_2 ) ;
V_48 = 1 ;
}
else if ( strcmp ( * V_2 , L_24 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
if ( ! F_19 ( & V_76 , * ( ++ V_2 ) ) ) goto V_86;
}
else if ( strcmp ( * V_2 , L_25 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
if ( ! F_20 ( & V_75 , * ( ++ V_2 ) ) ) goto V_86;
}
#ifndef F_3
else if ( strcmp ( * V_2 , L_26 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_77 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_27 ) == 0 )
V_53 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_28 ) == 0 )
V_46 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_29 ) == 0 )
V_47 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_30 ) == 0 )
V_31 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_31 ) == 0 )
V_36 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_32 ) == 0 )
V_57 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_33 ) == 0 )
V_58 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_34 ) == 0 )
V_54 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_35 ) == 0 )
V_30 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_36 ) == 0
|| strcmp ( * V_2 , L_37 ) == 0 )
V_37 = ++ V_13 ;
#ifndef F_2
else if ( strcmp ( * V_2 , L_38 ) == 0 )
V_40 = ++ V_13 ;
#endif
else if ( strcmp ( * V_2 , L_39 ) == 0 )
V_38 = ++ V_13 ;
#ifndef F_2
else if ( strcmp ( * V_2 , L_40 ) == 0 )
V_41 = ++ V_13 ;
#endif
else if ( strcmp ( * V_2 , L_41 ) == 0 )
V_32 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_42 ) == 0 )
V_33 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_43 ) == 0 )
V_63 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_44 ) == 0 )
{
V_34 = ++ V_13 ;
V_35 = ++ V_13 ;
}
else if ( strcmp ( * V_2 , L_45 ) == 0 )
V_59 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_46 ) == 0 )
V_34 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_47 ) == 0 )
V_35 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_48 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_86;
V_74 = atoi ( * ( ++ V_2 ) ) ;
V_73 = 1 ;
}
else if ( strcmp ( * V_2 , L_49 ) == 0 )
V_42 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_50 ) == 0 )
V_48 = 1 ;
else if ( strcmp ( * V_2 , L_51 ) == 0 )
V_49 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_52 ) == 0 )
V_50 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_53 ) == 0 )
V_51 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_54 ) == 0 )
V_45 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_55 ) == 0 )
V_52 = 1 ;
#if 1
else if ( strcmp ( * V_2 , L_56 ) == 0 )
{
F_14 ( V_79 , L_57 ) ;
V_52 = 1 ;
}
#endif
else if ( strcmp ( * V_2 , L_58 ) == 0 )
V_39 = ++ V_13 ;
else if ( ( V_65 = F_21 ( * V_2 + 1 ) ) )
{
V_66 = V_65 ;
}
else
{
F_14 ( V_79 , L_59 , * V_2 ) ;
V_14 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_14 )
{
V_86:
for ( V_60 = V_87 ; ( * V_60 != NULL ) ; V_60 ++ )
F_14 ( V_79 , L_60 , * V_60 ) ;
goto V_82;
}
#ifndef F_3
V_3 = F_22 ( V_79 , V_77 , 0 ) ;
#endif
if ( V_72 )
F_23 ( NULL , V_79 , 0 ) ;
F_24 () ;
if ( ! F_25 ( V_79 , V_71 , NULL , & V_70 , NULL ) )
{
F_14 ( V_79 , L_61 ) ;
goto V_82;
}
if ( ! F_26 ( V_61 ) )
{
F_27 ( V_79 ) ;
goto V_82;
}
if ( ( V_27 == NULL ) && ( V_44 ) && ( V_21 == V_84 ) )
{ V_27 = V_26 ; }
else if ( ( V_44 ) && ( V_27 == NULL ) )
{
F_14 ( V_79 , L_62 ) ;
goto V_82;
}
if ( V_69 )
{
long V_88 = - 1 ;
T_11 V_89 ;
V_67 = F_28 ( NULL ) ;
if ( ! F_29 ( V_67 , V_69 , & V_88 ) )
{
if ( V_88 <= 0 )
F_14 ( V_79 ,
L_63 ,
V_69 ) ;
else
F_14 ( V_79 ,
L_64
, V_88 , V_69 ) ;
goto V_82;
}
if ( ! V_68 )
{
V_68 = F_30 ( V_67 , L_65 , L_66 ) ;
if ( ! V_68 )
{
F_31 () ;
V_68 = L_65 ;
}
}
F_32 ( & V_89 ) ;
F_33 ( & V_89 , V_67 ) ;
if ( ! F_34 ( V_67 , & V_89 , V_68 , NULL ) )
{
F_14 ( V_79 ,
L_67 ,
V_68 ) ;
F_27 ( V_79 ) ;
goto V_82;
}
}
if ( V_78 )
{
T_5 * V_90 ;
T_12 * V_91 ;
T_7 * V_92 ;
if ( ! V_43 && ! V_44 )
{
F_14 ( V_79 , L_68 ) ;
goto V_82;
}
V_92 = F_8 ( F_35 () ) ;
if ( V_92 == NULL )
{
F_27 ( V_79 ) ;
goto V_82;
}
if ( V_23 == NULL )
F_36 ( V_92 , V_93 , V_81 | V_94 ) ;
else
{
if ( F_37 ( V_92 , V_23 ) <= 0 )
{
perror ( V_23 ) ;
F_38 ( V_92 ) ;
goto V_82;
}
}
V_5 = F_39 ( V_92 , NULL , NULL , NULL ) ;
F_38 ( V_92 ) ;
if ( V_5 == NULL )
{
F_27 ( V_79 ) ;
goto V_82;
}
if ( ( V_5 -> V_95 == NULL ) ||
( V_5 -> V_95 -> V_58 == NULL ) ||
( V_5 -> V_95 -> V_58 -> V_96 == NULL ) ||
( V_5 -> V_95 -> V_58 -> V_96 -> V_97 == NULL ) )
{
F_14 ( V_79 , L_69 ) ;
F_14 ( V_79 , L_70 ) ;
goto V_82;
}
if ( ( V_90 = F_40 ( V_5 ) ) == NULL )
{
F_14 ( V_79 , L_71 ) ;
goto V_82;
}
V_12 = F_41 ( V_5 , V_90 ) ;
F_42 ( V_90 ) ;
if ( V_12 < 0 )
{
F_14 ( V_79 , L_72 ) ;
F_27 ( V_79 ) ;
goto V_82;
}
if ( V_12 == 0 )
{
F_14 ( V_79 , L_73 ) ;
goto V_82;
}
else
F_14 ( V_79 , L_74 ) ;
F_43 ( V_79 , L_75 , F_44 ( V_5 ) , V_75 ) ;
if ( ( V_6 = F_45 () ) == NULL ) goto V_82;
V_91 = V_6 -> V_98 ;
if ( V_11 == NULL )
{
V_11 = F_46 () ;
if ( ! V_11 || ! F_47 ( NULL , V_11 ) )
goto V_82;
if ( ! F_48 ( V_6 , V_11 ) )
goto V_82;
F_49 ( V_11 ) ;
V_11 = NULL ;
}
else if ( ! F_48 ( V_6 , V_11 ) )
goto V_82;
if ( ! F_50 ( V_6 , V_5 -> V_95 -> V_32 ) ) goto V_82;
if ( ! F_51 ( V_6 , V_5 -> V_95 -> V_32 ) ) goto V_82;
F_52 ( F_53 ( V_6 ) , 0 ) ;
F_54 ( F_55 ( V_6 ) , V_55 , 0 , NULL ) ;
V_90 = F_40 ( V_5 ) ;
F_56 ( V_6 , V_90 ) ;
F_42 ( V_90 ) ;
}
else
V_6 = F_57 ( V_79 , V_23 , V_18 , NULL , V_3 , L_76 ) ;
if ( V_6 == NULL ) goto V_82;
if ( V_44 )
{
V_7 = F_57 ( V_79 , V_26 , V_21 , NULL , V_3 , L_77 ) ;
if ( V_7 == NULL ) goto V_82;
}
if ( ! V_42 || V_30 || V_36 )
{
F_58 ( L_78 ,
L_79 , L_80 ) ;
V_15 = F_8 ( F_35 () ) ;
if ( V_15 == NULL )
{
F_27 ( V_79 ) ;
goto V_82;
}
if ( V_24 == NULL )
{
F_36 ( V_15 , stdout , V_81 ) ;
#ifdef F_7
{
T_7 * V_83 = F_8 ( F_9 () ) ;
V_15 = F_10 ( V_83 , V_15 ) ;
}
#endif
}
else
{
if ( F_59 ( V_15 , V_24 ) <= 0 )
{
perror ( V_24 ) ;
goto V_82;
}
}
}
if ( V_29 ) F_60 ( V_6 , ( unsigned char * ) V_29 , - 1 ) ;
if ( V_49 ) F_61 ( V_6 ) ;
if ( V_50 ) F_62 ( V_6 ) ;
if ( V_16 )
{
for ( V_12 = 0 ; V_12 < F_63 ( V_16 ) ; V_12 ++ )
{
V_8 = F_64 ( V_16 , V_12 ) ;
F_65 ( V_6 , V_8 ) ;
}
}
if ( V_17 )
{
for ( V_12 = 0 ; V_12 < F_63 ( V_17 ) ; V_12 ++ )
{
V_8 = F_64 ( V_17 , V_12 ) ;
F_66 ( V_6 , V_8 ) ;
}
}
if ( V_13 )
{
for ( V_12 = 1 ; V_12 <= V_13 ; V_12 ++ )
{
if ( V_33 == V_12 )
{
F_43 ( STDout , L_81 ,
F_67 ( V_6 ) , V_75 ) ;
}
else if ( V_32 == V_12 )
{
F_43 ( STDout , L_82 ,
F_68 ( V_6 ) , V_75 ) ;
}
else if ( V_31 == V_12 )
{
F_14 ( STDout , L_83 ) ;
F_69 ( STDout ,
F_70 ( V_6 ) ) ;
F_14 ( STDout , L_84 ) ;
}
else if ( V_36 == V_12 )
{
T_13 * V_99 ;
T_6 * V_100 ;
V_100 = F_70 ( V_6 ) ;
V_99 = F_71 ( V_100 , NULL ) ;
if ( ! V_99 )
goto V_82;
if ( ! F_72 ( V_99 , 1 ) )
goto V_82;
V_100 = F_73 ( V_99 , NULL ) ;
if ( ! V_100 )
goto V_82;
F_74 ( V_99 ) ;
F_69 ( V_15 , V_100 ) ;
F_49 ( V_100 ) ;
F_75 ( V_15 , L_84 ) ;
}
else if ( ( V_46 == V_12 ) || ( V_47 == V_12 ) )
{
int V_101 ;
F_1 ( V_102 ) * V_103 ;
if ( V_46 == V_12 )
V_103 = F_76 ( V_6 ) ;
else
V_103 = F_77 ( V_6 ) ;
for ( V_101 = 0 ; V_101 < F_78 ( V_103 ) ; V_101 ++ )
F_14 ( STDout , L_85 ,
F_79 ( V_103 , V_101 ) ) ;
F_80 ( V_103 ) ;
}
else if ( V_51 == V_12 )
{
unsigned char * V_104 ;
V_104 = F_81 ( V_6 , NULL ) ;
if ( V_104 ) F_14 ( STDout , L_85 , V_104 ) ;
else F_75 ( STDout , L_86 ) ;
}
else if ( V_37 == V_12 )
{
F_14 ( STDout , L_87 , F_82 ( V_6 ) ) ;
}
#ifndef F_2
else if ( V_40 == V_12 )
{
F_14 ( STDout , L_87 , F_83 ( V_6 ) ) ;
}
#endif
else if ( V_38 == V_12 )
{
F_14 ( STDout , L_87 , F_84 ( V_6 ) ) ;
}
#ifndef F_2
else if ( V_41 == V_12 )
{
F_14 ( STDout , L_87 , F_85 ( V_6 ) ) ;
}
#endif
else if ( V_59 == V_12 )
{
T_14 * V_105 ;
int V_101 ;
F_14 ( STDout , L_88 ) ;
for ( V_101 = 0 ; V_101 < F_86 () ; V_101 ++ )
{
V_105 = F_87 ( V_101 ) ;
F_88 ( STDout , V_6 , V_105 ) ;
}
}
else
if ( V_57 == V_12 )
{
T_5 * V_90 ;
V_90 = F_89 ( V_6 ) ;
if ( V_90 == NULL )
{
F_14 ( V_79 , L_89 ) ;
F_27 ( V_79 ) ;
goto V_82;
}
F_14 ( STDout , L_90 ) ;
#ifndef F_90
if ( V_90 -> type == V_106 )
F_91 ( STDout , V_90 -> V_90 . V_107 -> V_108 ) ;
else
#endif
#ifndef F_92
if ( V_90 -> type == V_109 )
F_91 ( STDout , V_90 -> V_90 . V_110 -> V_111 ) ;
else
#endif
F_14 ( STDout , L_91 ) ;
F_14 ( STDout , L_84 ) ;
F_42 ( V_90 ) ;
}
else
if ( V_58 == V_12 )
{
T_5 * V_90 ;
V_90 = F_89 ( V_6 ) ;
if ( V_90 == NULL )
{
F_14 ( V_79 , L_92 ) ;
F_27 ( V_79 ) ;
goto V_82;
}
F_93 ( STDout , V_90 ) ;
F_42 ( V_90 ) ;
}
else
if ( V_53 == V_12 )
{
unsigned char * V_112 ;
char * V_113 ;
int V_114 , V_115 ;
F_94 ( F_68 ( V_6 ) ,
V_64 , sizeof V_64 ) ;
F_14 ( STDout , L_93 , V_64 ) ;
V_113 = F_94 (
F_67 ( V_6 ) , V_64 ,
sizeof V_64 ) ;
F_14 ( STDout , L_94 , V_64 ) ;
V_115 = F_95 ( V_6 , NULL ) ;
V_113 = F_96 ( V_115 ) ;
V_112 = ( unsigned char * ) V_113 ;
V_115 = F_97 ( F_68 ( V_6 ) , & V_112 ) ;
F_14 ( STDout , L_95 , V_115 ) ;
V_112 = ( unsigned char * ) V_113 ;
for ( V_114 = 0 ; V_114 < V_115 ; V_114 ++ )
{
F_14 ( STDout , L_96 , V_112 [ V_114 ] ) ;
if ( ( V_114 & 0x0f ) == 0x0f ) F_14 ( STDout , L_84 ) ;
}
if ( V_114 % 16 != 0 ) F_14 ( STDout , L_84 ) ;
F_14 ( STDout , L_97 ) ;
V_115 = F_98 ( F_99 ( V_6 ) , & V_112 ) ;
F_14 ( STDout , L_98 , V_115 ) ;
V_112 = ( unsigned char * ) V_113 ;
for ( V_114 = 0 ; V_114 < V_115 ; V_114 ++ )
{
F_14 ( STDout , L_96 , V_112 [ V_114 ] ) ;
if ( ( V_114 & 0x0f ) == 0x0f )
F_14 ( STDout , L_84 ) ;
}
if ( V_114 % 16 != 0 ) F_14 ( STDout , L_84 ) ;
F_14 ( STDout , L_97 ) ;
V_115 = F_95 ( V_6 , & V_112 ) ;
F_14 ( STDout , L_99 , V_115 ) ;
V_112 = ( unsigned char * ) V_113 ;
for ( V_114 = 0 ; V_114 < V_115 ; V_114 ++ )
{
F_14 ( STDout , L_96 , V_112 [ V_114 ] ) ;
if ( ( V_114 & 0x0f ) == 0x0f )
F_14 ( STDout , L_84 ) ;
}
if ( V_114 % 16 != 0 ) F_14 ( STDout , L_84 ) ;
F_14 ( STDout , L_97 ) ;
F_100 ( V_113 ) ;
}
else if ( V_30 == V_12 )
{
F_101 ( V_15 , V_6 , V_75 , V_76 ) ;
}
else if ( V_34 == V_12 )
{
F_75 ( STDout , L_100 ) ;
F_102 ( STDout , F_53 ( V_6 ) ) ;
F_75 ( STDout , L_84 ) ;
}
else if ( V_35 == V_12 )
{
F_75 ( STDout , L_101 ) ;
F_102 ( STDout , F_55 ( V_6 ) ) ;
F_75 ( STDout , L_84 ) ;
}
else if ( V_63 == V_12 )
{
int V_101 ;
unsigned int V_108 ;
unsigned char V_116 [ V_117 ] ;
const T_9 * V_118 = V_66 ;
if ( ! V_118 )
V_118 = F_103 () ;
if ( ! F_104 ( V_6 , V_118 , V_116 , & V_108 ) )
{
F_14 ( V_79 , L_102 ) ;
goto V_82;
}
F_14 ( STDout , L_103 ,
F_105 ( F_106 ( V_118 ) ) ) ;
for ( V_101 = 0 ; V_101 < ( int ) V_108 ; V_101 ++ )
{
F_14 ( STDout , L_104 , V_116 [ V_101 ] ,
( V_101 + 1 == ( int ) V_108 )
? '\n' : ':' ) ;
}
}
else if ( ( V_43 == V_12 ) && ( V_54 == 0 ) )
{
F_14 ( V_79 , L_105 ) ;
if ( V_9 == NULL )
{
V_9 = F_107 ( V_79 ,
V_25 , V_20 , 0 ,
V_70 , V_3 , L_106 ) ;
if ( V_9 == NULL ) goto V_82;
}
assert ( V_72 ) ;
if ( ! F_108 ( V_6 , V_9 , V_55 , V_52 , V_66 ,
V_67 , V_68 ) ) goto V_82;
}
else if ( V_44 == V_12 )
{
F_14 ( V_79 , L_107 ) ;
if ( V_27 != NULL )
{
V_10 = F_107 ( V_79 ,
V_27 , V_22 ,
0 , V_70 , V_3 ,
L_108 ) ;
if ( V_10 == NULL ) goto V_82;
}
assert ( V_72 ) ;
if ( ! F_109 ( V_61 , V_26 , V_66 , V_6 , V_7 ,
V_10 , V_28 , V_45 , V_55 , V_52 ,
V_67 , V_68 , V_11 ) )
goto V_82;
}
else if ( V_54 == V_12 )
{
T_5 * V_119 ;
F_14 ( V_79 , L_109 ) ;
if ( V_25 == NULL )
{
F_14 ( V_79 , L_110 ) ;
goto V_82;
}
else
{
V_119 = F_107 ( V_79 ,
V_25 , V_84 , 0 ,
V_70 , V_3 , L_111 ) ;
if ( V_119 == NULL ) goto V_82;
}
F_14 ( V_79 , L_112 ) ;
V_62 = F_110 ( V_6 , V_119 , V_66 ) ;
F_42 ( V_119 ) ;
if ( V_62 == NULL )
{
F_27 ( V_79 ) ;
goto V_82;
}
if ( ! V_42 )
{
F_111 ( V_15 , V_62 ) ;
F_112 ( V_15 , V_62 ) ;
}
V_42 = 1 ;
}
else if ( V_39 == V_12 )
{
F_113 ( V_15 , V_6 ) ;
}
}
}
if ( V_73 )
{
T_15 V_120 = time ( NULL ) + V_74 ;
if ( F_114 ( F_55 ( V_6 ) , & V_120 ) < 0 )
{
F_14 ( V_15 , L_113 ) ;
V_4 = 1 ;
}
else
{
F_14 ( V_15 , L_114 ) ;
V_4 = 0 ;
}
goto V_82;
}
if ( V_42 )
{
V_4 = 0 ;
goto V_82;
}
if ( V_19 == V_121 )
V_12 = F_115 ( V_15 , V_6 ) ;
else if ( V_19 == V_84 )
{
if ( V_48 ) V_12 = F_116 ( V_15 , V_6 ) ;
else V_12 = F_117 ( V_15 , V_6 ) ;
}
else if ( V_19 == V_122 )
{
T_16 V_123 ;
T_17 V_124 ;
V_124 . V_97 = ( unsigned char * ) V_125 ;
V_124 . V_126 = strlen ( V_125 ) ;
V_123 . V_127 = & V_124 ;
V_123 . V_128 = V_6 ;
V_12 = F_118 ( F_119 ( T_16 ) , V_15 , & V_123 ) ;
}
else {
F_14 ( V_79 , L_115 ) ;
goto V_82;
}
if ( ! V_12 )
{
F_14 ( V_79 , L_116 ) ;
F_27 ( V_79 ) ;
goto V_82;
}
V_4 = 0 ;
V_82:
if ( V_72 )
F_120 ( NULL , V_79 ) ;
F_121 () ;
F_122 ( V_67 ) ;
F_123 ( V_15 ) ;
F_123 ( STDout ) ;
F_124 ( V_61 ) ;
F_125 ( V_5 ) ;
F_126 ( V_6 ) ;
F_126 ( V_7 ) ;
F_42 ( V_9 ) ;
F_42 ( V_10 ) ;
F_125 ( V_62 ) ;
F_49 ( V_11 ) ;
F_127 ( V_16 , V_129 ) ;
F_127 ( V_17 , V_129 ) ;
if ( V_70 ) F_100 ( V_70 ) ;
F_128 () ;
F_129 ( V_4 ) ;
}
static T_6 * F_130 ( char * V_26 , char * V_130 , int V_131 )
{
char * V_64 = NULL , * V_132 ;
T_6 * V_133 = NULL ;
T_13 * V_31 = NULL ;
T_18 V_134 ;
V_134 = ( ( V_130 == NULL )
? ( strlen ( V_26 ) + strlen ( V_135 ) + 1 )
: ( strlen ( V_130 ) ) ) + 1 ;
V_64 = F_96 ( V_134 ) ;
if ( V_64 == NULL ) { F_14 ( V_79 , L_117 ) ; goto V_82; }
if ( V_130 == NULL )
{
F_131 ( V_64 , V_26 , V_134 ) ;
for ( V_132 = V_64 ; * V_132 ; V_132 ++ )
if ( * V_132 == '.' )
{
* V_132 = '\0' ;
break;
}
F_132 ( V_64 , V_135 , V_134 ) ;
}
else
F_131 ( V_64 , V_130 , V_134 ) ;
V_31 = F_133 ( V_64 , V_131 , NULL ) ;
if ( V_31 == NULL ) goto V_82;
if ( ! F_72 ( V_31 , 1 ) )
{ F_14 ( V_79 , L_118 ) ; goto V_82; }
if ( ! F_134 ( V_64 , NULL , V_31 , & V_133 ) ) goto V_82;
V_82:
if ( V_64 ) F_100 ( V_64 ) ;
F_74 ( V_31 ) ;
return V_133 ;
}
static int F_109 ( T_8 * V_61 , char * V_26 , const T_9 * V_66 ,
T_3 * V_6 , T_3 * V_7 , T_5 * V_90 , char * V_130 , int V_131 ,
int V_55 , int V_52 , T_10 * V_136 , char * V_137 , T_6 * V_11 )
{
int V_4 = 0 ;
T_6 * V_133 = NULL ;
T_19 V_138 ;
T_5 * V_139 ;
V_139 = F_89 ( V_7 ) ;
F_135 ( V_139 , V_90 ) ;
F_42 ( V_139 ) ;
if( ! F_136 ( & V_138 , V_61 , V_6 , NULL ) )
{
F_14 ( V_79 , L_119 ) ;
goto V_82;
}
if ( V_11 ) V_133 = V_11 ;
else if ( ! ( V_133 = F_130 ( V_26 , V_130 , V_131 ) ) )
goto V_82;
F_137 ( & V_138 , V_6 ) ;
F_138 ( & V_138 , V_140 ) ;
if ( ! V_78 && F_139 ( & V_138 ) <= 0 )
goto V_82;
if ( ! F_140 ( V_7 , V_90 ) )
{
F_14 ( V_79 , L_120 ) ;
goto V_82;
}
if ( ! F_50 ( V_6 , F_68 ( V_7 ) ) ) goto V_82;
if ( ! F_48 ( V_6 , V_133 ) ) goto V_82;
if ( F_52 ( F_53 ( V_6 ) , 0L ) == NULL )
goto V_82;
if ( F_54 ( F_55 ( V_6 ) , V_55 , 0 , NULL ) == NULL )
goto V_82;
if ( V_52 )
{
while ( F_141 ( V_6 ) > 0 ) F_142 ( V_6 , 0 ) ;
}
if ( V_136 )
{
T_11 V_89 ;
F_143 ( V_6 , 2 ) ;
F_144 ( & V_89 , V_7 , V_6 , NULL , NULL , 0 ) ;
F_33 ( & V_89 , V_136 ) ;
if ( ! F_34 ( V_136 , & V_89 , V_137 , V_6 ) ) goto V_82;
}
if ( ! F_145 ( V_6 , V_90 , V_66 ) ) goto V_82;
V_4 = 1 ;
V_82:
F_146 ( & V_138 ) ;
if ( ! V_4 )
F_27 ( V_79 ) ;
if ( ! V_11 ) F_49 ( V_133 ) ;
return V_4 ;
}
static int T_20 V_85 ( int V_141 , T_19 * V_61 )
{
int V_142 ;
T_3 * V_143 ;
V_142 = F_147 ( V_61 ) ;
if ( V_142 == V_144 )
return 1 ;
if ( V_141 )
{
F_14 ( V_79 , L_121 ) ;
return 0 ;
}
else
{
V_143 = F_148 ( V_61 ) ;
F_43 ( V_79 , NULL , F_68 ( V_143 ) , 0 ) ;
F_14 ( V_79 , L_122 ,
V_142 , F_149 ( V_61 ) ,
F_150 ( V_142 ) ) ;
return 1 ;
}
}
static int F_108 ( T_3 * V_6 , T_5 * V_90 , int V_55 , int V_52 , const T_9 * V_66 ,
T_10 * V_136 , char * V_137 )
{
T_5 * V_145 ;
V_145 = F_89 ( V_6 ) ;
F_135 ( V_145 , V_90 ) ;
F_151 ( V_145 , 1 ) ;
F_42 ( V_145 ) ;
if ( ! F_50 ( V_6 , F_68 ( V_6 ) ) ) goto V_142;
if ( F_52 ( F_53 ( V_6 ) , 0 ) == NULL ) goto V_142;
if ( F_52 ( F_55 ( V_6 ) , ( long ) 60 * 60 * 24 * V_55 ) == NULL )
goto V_142;
if ( ! F_56 ( V_6 , V_90 ) ) goto V_142;
if ( V_52 )
{
while ( F_141 ( V_6 ) > 0 ) F_142 ( V_6 , 0 ) ;
}
if ( V_136 )
{
T_11 V_61 ;
F_143 ( V_6 , 2 ) ;
F_144 ( & V_61 , V_6 , V_6 , NULL , NULL , 0 ) ;
F_33 ( & V_61 , V_136 ) ;
if ( ! F_34 ( V_136 , & V_61 , V_137 , V_6 ) ) goto V_142;
}
if ( ! F_145 ( V_6 , V_90 , V_66 ) ) goto V_142;
return 1 ;
V_142:
F_27 ( V_79 ) ;
return 0 ;
}
static int F_88 ( T_7 * V_146 , T_3 * V_128 , T_14 * V_147 )
{
int V_148 , V_12 , V_149 ;
char * V_150 ;
V_148 = F_152 ( V_147 ) ;
V_150 = F_153 ( V_147 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
{
V_149 = F_154 ( V_128 , V_148 , V_12 ) ;
F_14 ( V_146 , L_123 , V_150 , V_12 ? L_124 : L_125 ) ;
if ( V_149 == 1 ) F_14 ( V_146 , L_126 ) ;
else if ( V_149 == 0 ) F_14 ( V_146 , L_127 ) ;
else F_14 ( V_146 , L_128 , V_149 ) ;
}
return 1 ;
}
