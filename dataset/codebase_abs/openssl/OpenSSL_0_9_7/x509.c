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
int V_30 = 0 , V_31 = 0 , V_32 = 0 , V_33 = 0 , V_34 = 0 , V_35 = 0 , V_36 = 0 ;
int V_37 = 0 ;
int V_38 = 0 , V_39 = 0 , V_40 = 0 , V_41 = 0 , V_42 = 0 ;
int V_43 = 0 , V_44 = 0 , V_45 = 0 , V_46 = 0 , V_47 = 0 ;
int V_48 = 0 ;
int V_49 = 0 , V_50 = V_51 , V_52 = 0 , V_53 = 0 ;
int V_54 = 0 ;
char * * V_55 ;
T_8 * V_56 = NULL ;
T_2 * V_57 = NULL ;
int V_58 = 0 ;
char V_59 [ 256 ] ;
const T_9 * V_60 , * V_61 = F_2 () ;
T_10 * V_62 = NULL ;
char * V_63 = NULL , * V_64 = NULL , * V_65 = NULL , * V_66 = NULL ;
int V_67 = 0 ;
int V_68 = 0 , V_69 = 0 ;
unsigned long V_70 = 0 , V_71 = 0 ;
char * V_72 = NULL ;
V_73 = 0 ;
F_3 () ;
if ( V_74 == NULL )
V_74 = F_4 ( V_75 , V_76 ) ;
if ( ! F_5 ( V_74 , NULL ) )
goto V_77;
STDout = F_4 ( stdout , V_76 ) ;
#ifdef F_6
{
T_7 * V_78 = F_7 ( F_8 () ) ;
STDout = F_9 ( V_78 , STDout ) ;
}
#endif
V_18 = V_79 ;
V_19 = V_79 ;
V_20 = V_79 ;
V_21 = V_79 ;
V_22 = V_79 ;
V_56 = F_10 () ;
if ( V_56 == NULL ) goto V_77;
F_11 ( V_56 , V_80 ) ;
V_1 -- ;
V_2 ++ ;
V_13 = 0 ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_18 = F_12 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_19 = F_12 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_20 = F_12 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
V_73 = 1 ;
V_67 = 1 ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_21 = F_12 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_22 = F_12 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_50 = atoi ( * ( ++ V_2 ) ) ;
if ( V_50 == 0 )
{
F_13 ( STDout , L_8 ) ;
goto V_81;
}
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_66 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_64 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_63 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_23 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_24 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_25 = * ( ++ V_2 ) ;
V_39 = ++ V_13 ;
V_67 = 1 ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_26 = * ( ++ V_2 ) ;
V_40 = ++ V_13 ;
V_67 = 1 ;
}
else if ( strcmp ( * V_2 , L_16 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_27 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_17 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_28 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_18 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
if ( ! ( V_11 = F_14 ( NULL , * ( ++ V_2 ) ) ) )
goto V_81;
}
else if ( strcmp ( * V_2 , L_19 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
if ( ! ( V_8 = F_15 ( * ( ++ V_2 ) , 0 ) ) )
{
F_13 ( V_74 ,
L_20 , * V_2 ) ;
goto V_81;
}
if ( ! V_16 ) V_16 = F_16 () ;
F_17 ( V_16 , V_8 ) ;
V_43 = 1 ;
}
else if ( strcmp ( * V_2 , L_21 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
if ( ! ( V_8 = F_15 ( * ( ++ V_2 ) , 0 ) ) )
{
F_13 ( V_74 ,
L_22 , * V_2 ) ;
goto V_81;
}
if ( ! V_17 ) V_17 = F_16 () ;
F_17 ( V_17 , V_8 ) ;
V_43 = 1 ;
}
else if ( strcmp ( * V_2 , L_23 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_29 = * ( ++ V_2 ) ;
V_43 = 1 ;
}
else if ( strcmp ( * V_2 , L_24 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
if ( ! F_18 ( & V_71 , * ( ++ V_2 ) ) ) goto V_81;
}
else if ( strcmp ( * V_2 , L_25 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
if ( ! F_19 ( & V_70 , * ( ++ V_2 ) ) ) goto V_81;
}
else if ( strcmp ( * V_2 , L_23 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_29 = * ( ++ V_2 ) ;
V_43 = 1 ;
}
else if ( strcmp ( * V_2 , L_26 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_72 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_27 ) == 0 )
V_48 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_28 ) == 0 )
V_42 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_29 ) == 0 )
V_31 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_30 ) == 0 )
V_52 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_31 ) == 0 )
V_53 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_32 ) == 0 )
V_49 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_33 ) == 0 )
V_30 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_34 ) == 0 )
V_32 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_35 ) == 0 )
V_33 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_36 ) == 0 )
V_34 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_37 ) == 0 )
V_58 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_38 ) == 0 )
{
V_35 = ++ V_13 ;
V_36 = ++ V_13 ;
}
else if ( strcmp ( * V_2 , L_39 ) == 0 )
V_54 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_40 ) == 0 )
V_35 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_41 ) == 0 )
V_36 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_42 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_81;
V_69 = atoi ( * ( ++ V_2 ) ) ;
V_68 = 1 ;
}
else if ( strcmp ( * V_2 , L_43 ) == 0 )
V_38 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_44 ) == 0 )
V_43 = 1 ;
else if ( strcmp ( * V_2 , L_45 ) == 0 )
V_44 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_46 ) == 0 )
V_45 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_47 ) == 0 )
V_46 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_48 ) == 0 )
V_41 = ++ V_13 ;
else if ( strcmp ( * V_2 , L_49 ) == 0 )
V_47 = 1 ;
#if 1
else if ( strcmp ( * V_2 , L_50 ) == 0 )
{
F_13 ( V_74 , L_51 ) ;
V_47 = 1 ;
}
#endif
else if ( strcmp ( * V_2 , L_52 ) == 0 )
V_37 = ++ V_13 ;
else if ( ( V_60 = F_20 ( * V_2 + 1 ) ) )
{
V_61 = V_60 ;
}
else
{
F_13 ( V_74 , L_53 , * V_2 ) ;
V_14 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_14 )
{
V_81:
for ( V_55 = V_82 ; ( * V_55 != NULL ) ; V_55 ++ )
F_13 ( V_74 , L_54 , * V_55 ) ;
goto V_77;
}
V_3 = F_21 ( V_74 , V_72 , 0 ) ;
if ( V_67 )
F_22 ( NULL , V_74 , 0 ) ;
F_23 () ;
if ( ! F_24 ( V_74 , V_66 , NULL , & V_65 , NULL ) )
{
F_13 ( V_74 , L_55 ) ;
goto V_77;
}
if ( ! F_25 ( V_56 ) )
{
F_26 ( V_74 ) ;
goto V_77;
}
if ( ( V_27 == NULL ) && ( V_40 ) && ( V_21 == V_79 ) )
{ V_27 = V_26 ; }
else if ( ( V_40 ) && ( V_27 == NULL ) )
{
F_13 ( V_74 , L_56 ) ;
goto V_77;
}
if ( V_64 )
{
long V_83 = - 1 ;
T_11 V_84 ;
V_62 = F_27 ( NULL ) ;
if ( ! F_28 ( V_62 , V_64 , & V_83 ) )
{
if ( V_83 <= 0 )
F_13 ( V_74 ,
L_57 ,
V_64 ) ;
else
F_13 ( V_74 ,
L_58
, V_83 , V_64 ) ;
goto V_77;
}
if ( ! V_63 )
{
V_63 = F_29 ( V_62 , L_59 , L_60 ) ;
if ( ! V_63 )
{
F_30 () ;
V_63 = L_59 ;
}
}
F_31 ( & V_84 ) ;
F_32 ( & V_84 , V_62 ) ;
if ( ! F_33 ( V_62 , & V_84 , V_63 , NULL ) )
{
F_13 ( V_74 ,
L_61 ,
V_63 ) ;
F_26 ( V_74 ) ;
goto V_77;
}
}
if ( V_73 )
{
T_5 * V_85 ;
T_12 * V_86 ;
T_7 * V_87 ;
if ( ! V_39 && ! V_40 )
{
F_13 ( V_74 , L_62 ) ;
goto V_77;
}
V_87 = F_7 ( F_34 () ) ;
if ( V_87 == NULL )
{
F_26 ( V_74 ) ;
goto V_77;
}
if ( V_23 == NULL )
F_35 ( V_87 , V_88 , V_76 | V_89 ) ;
else
{
if ( F_36 ( V_87 , V_23 ) <= 0 )
{
perror ( V_23 ) ;
F_37 ( V_87 ) ;
goto V_77;
}
}
V_5 = F_38 ( V_87 , NULL , NULL , NULL ) ;
F_37 ( V_87 ) ;
if ( V_5 == NULL )
{
F_26 ( V_74 ) ;
goto V_77;
}
if ( ( V_5 -> V_90 == NULL ) ||
( V_5 -> V_90 -> V_53 == NULL ) ||
( V_5 -> V_90 -> V_53 -> V_91 == NULL ) ||
( V_5 -> V_90 -> V_53 -> V_91 -> V_92 == NULL ) )
{
F_13 ( V_74 , L_63 ) ;
F_13 ( V_74 , L_64 ) ;
goto V_77;
}
if ( ( V_85 = F_39 ( V_5 ) ) == NULL )
{
F_13 ( V_74 , L_65 ) ;
goto V_77;
}
V_12 = F_40 ( V_5 , V_85 ) ;
F_41 ( V_85 ) ;
if ( V_12 < 0 )
{
F_13 ( V_74 , L_66 ) ;
F_26 ( V_74 ) ;
goto V_77;
}
if ( V_12 == 0 )
{
F_13 ( V_74 , L_67 ) ;
goto V_77;
}
else
F_13 ( V_74 , L_68 ) ;
F_42 ( V_74 , L_69 , F_43 ( V_5 ) , V_70 ) ;
if ( ( V_6 = F_44 () ) == NULL ) goto V_77;
V_86 = V_6 -> V_93 ;
if ( V_11 )
{
if ( ! F_45 ( V_6 , V_11 ) )
goto V_77;
}
else if ( ! F_46 ( F_47 ( V_6 ) , 0 ) ) goto V_77;
if ( ! F_48 ( V_6 , V_5 -> V_90 -> V_33 ) ) goto V_77;
if ( ! F_49 ( V_6 , V_5 -> V_90 -> V_33 ) ) goto V_77;
F_50 ( F_51 ( V_6 ) , 0 ) ;
F_50 ( F_52 ( V_6 ) , ( long ) 60 * 60 * 24 * V_50 ) ;
V_85 = F_39 ( V_5 ) ;
F_53 ( V_6 , V_85 ) ;
F_41 ( V_85 ) ;
}
else
V_6 = F_54 ( V_74 , V_23 , V_18 , NULL , V_3 , L_70 ) ;
if ( V_6 == NULL ) goto V_77;
if ( V_40 )
{
V_7 = F_54 ( V_74 , V_26 , V_21 , NULL , V_3 , L_71 ) ;
if ( V_7 == NULL ) goto V_77;
}
if ( ! V_38 || V_30 )
{
F_55 ( L_72 ,
L_73 , L_74 ) ;
V_15 = F_7 ( F_34 () ) ;
if ( V_15 == NULL )
{
F_26 ( V_74 ) ;
goto V_77;
}
if ( V_24 == NULL )
{
F_35 ( V_15 , stdout , V_76 ) ;
#ifdef F_6
{
T_7 * V_78 = F_7 ( F_8 () ) ;
V_15 = F_9 ( V_78 , V_15 ) ;
}
#endif
}
else
{
if ( F_56 ( V_15 , V_24 ) <= 0 )
{
perror ( V_24 ) ;
goto V_77;
}
}
}
if ( V_29 ) F_57 ( V_6 , ( unsigned char * ) V_29 , - 1 ) ;
if ( V_44 ) F_58 ( V_6 ) ;
if ( V_45 ) F_59 ( V_6 ) ;
if ( V_16 )
{
for ( V_12 = 0 ; V_12 < F_60 ( V_16 ) ; V_12 ++ )
{
V_8 = F_61 ( V_16 , V_12 ) ;
F_62 ( V_6 , V_8 ) ;
}
}
if ( V_17 )
{
for ( V_12 = 0 ; V_12 < F_60 ( V_17 ) ; V_12 ++ )
{
V_8 = F_61 ( V_17 , V_12 ) ;
F_63 ( V_6 , V_8 ) ;
}
}
if ( V_13 )
{
for ( V_12 = 1 ; V_12 <= V_13 ; V_12 ++ )
{
if ( V_34 == V_12 )
{
F_42 ( STDout , L_75 ,
F_64 ( V_6 ) , V_70 ) ;
}
else if ( V_33 == V_12 )
{
F_42 ( STDout , L_76 ,
F_65 ( V_6 ) , V_70 ) ;
}
else if ( V_31 == V_12 )
{
F_13 ( STDout , L_77 ) ;
F_66 ( STDout , V_6 -> V_93 -> V_94 ) ;
F_13 ( STDout , L_78 ) ;
}
else if ( V_42 == V_12 )
{
int V_95 ;
T_13 * V_96 ;
V_96 = F_67 ( V_6 ) ;
for ( V_95 = 0 ; V_95 < F_68 ( V_96 ) ; V_95 ++ )
F_13 ( STDout , L_79 , F_69 ( V_96 , V_95 ) ) ;
F_70 ( V_96 ) ;
}
else if ( V_46 == V_12 )
{
unsigned char * V_97 ;
V_97 = F_71 ( V_6 , NULL ) ;
if ( V_97 ) F_13 ( STDout , L_79 , V_97 ) ;
else F_72 ( STDout , L_80 ) ;
}
else if ( V_32 == V_12 )
{
F_13 ( STDout , L_81 , F_73 ( V_6 ) ) ;
}
else if ( V_54 == V_12 )
{
T_14 * V_98 ;
int V_95 ;
F_13 ( STDout , L_82 ) ;
for ( V_95 = 0 ; V_95 < F_74 () ; V_95 ++ )
{
V_98 = F_75 ( V_95 ) ;
F_76 ( STDout , V_6 , V_98 ) ;
}
}
else
if ( V_52 == V_12 )
{
T_5 * V_85 ;
V_85 = F_77 ( V_6 ) ;
if ( V_85 == NULL )
{
F_13 ( V_74 , L_83 ) ;
F_26 ( V_74 ) ;
goto V_77;
}
F_13 ( STDout , L_84 ) ;
#ifndef F_78
if ( V_85 -> type == V_99 )
F_79 ( STDout , V_85 -> V_85 . V_100 -> V_101 ) ;
else
#endif
#ifndef F_80
if ( V_85 -> type == V_102 )
F_79 ( STDout , V_85 -> V_85 . V_103 -> V_104 ) ;
else
#endif
F_13 ( STDout , L_85 ) ;
F_13 ( STDout , L_78 ) ;
F_41 ( V_85 ) ;
}
else
if ( V_53 == V_12 )
{
T_5 * V_85 ;
V_85 = F_77 ( V_6 ) ;
if ( V_85 == NULL )
{
F_13 ( V_74 , L_86 ) ;
F_26 ( V_74 ) ;
goto V_77;
}
F_81 ( STDout , V_85 ) ;
F_41 ( V_85 ) ;
}
else
if ( V_48 == V_12 )
{
unsigned char * V_105 ;
char * V_106 ;
int V_107 , V_108 ;
F_82 ( F_65 ( V_6 ) ,
V_59 , sizeof V_59 ) ;
F_13 ( STDout , L_87 , V_59 ) ;
V_106 = F_82 (
F_64 ( V_6 ) , V_59 ,
sizeof V_59 ) ;
F_13 ( STDout , L_88 , V_59 ) ;
V_108 = F_83 ( V_6 , NULL ) ;
V_106 = F_84 ( V_108 ) ;
V_105 = ( unsigned char * ) V_106 ;
V_108 = F_85 ( F_65 ( V_6 ) , & V_105 ) ;
F_13 ( STDout , L_89 , V_108 ) ;
V_105 = ( unsigned char * ) V_106 ;
for ( V_107 = 0 ; V_107 < V_108 ; V_107 ++ )
{
F_13 ( STDout , L_90 , V_105 [ V_107 ] ) ;
if ( ( V_107 & 0x0f ) == 0x0f ) F_13 ( STDout , L_78 ) ;
}
if ( V_107 % 16 != 0 ) F_13 ( STDout , L_78 ) ;
F_13 ( STDout , L_91 ) ;
V_108 = F_86 ( F_87 ( V_6 ) , & V_105 ) ;
F_13 ( STDout , L_92 , V_108 ) ;
V_105 = ( unsigned char * ) V_106 ;
for ( V_107 = 0 ; V_107 < V_108 ; V_107 ++ )
{
F_13 ( STDout , L_90 , V_105 [ V_107 ] ) ;
if ( ( V_107 & 0x0f ) == 0x0f )
F_13 ( STDout , L_78 ) ;
}
if ( V_107 % 16 != 0 ) F_13 ( STDout , L_78 ) ;
F_13 ( STDout , L_91 ) ;
V_108 = F_83 ( V_6 , & V_105 ) ;
F_13 ( STDout , L_93 , V_108 ) ;
V_105 = ( unsigned char * ) V_106 ;
for ( V_107 = 0 ; V_107 < V_108 ; V_107 ++ )
{
F_13 ( STDout , L_90 , V_105 [ V_107 ] ) ;
if ( ( V_107 & 0x0f ) == 0x0f )
F_13 ( STDout , L_78 ) ;
}
if ( V_107 % 16 != 0 ) F_13 ( STDout , L_78 ) ;
F_13 ( STDout , L_91 ) ;
F_88 ( V_106 ) ;
}
else if ( V_30 == V_12 )
{
F_89 ( V_15 , V_6 , V_70 , V_71 ) ;
}
else if ( V_35 == V_12 )
{
F_72 ( STDout , L_94 ) ;
F_90 ( STDout , F_51 ( V_6 ) ) ;
F_72 ( STDout , L_78 ) ;
}
else if ( V_36 == V_12 )
{
F_72 ( STDout , L_95 ) ;
F_90 ( STDout , F_52 ( V_6 ) ) ;
F_72 ( STDout , L_78 ) ;
}
else if ( V_58 == V_12 )
{
int V_95 ;
unsigned int V_101 ;
unsigned char V_109 [ V_110 ] ;
if ( ! F_91 ( V_6 , V_61 , V_109 , & V_101 ) )
{
F_13 ( V_74 , L_96 ) ;
goto V_77;
}
F_13 ( STDout , L_97 ,
F_92 ( F_93 ( V_61 ) ) ) ;
for ( V_95 = 0 ; V_95 < ( int ) V_101 ; V_95 ++ )
{
F_13 ( STDout , L_98 , V_109 [ V_95 ] ,
( V_95 + 1 == ( int ) V_101 )
? '\n' : ':' ) ;
}
}
else if ( ( V_39 == V_12 ) && ( V_49 == 0 ) )
{
F_13 ( V_74 , L_99 ) ;
if ( V_9 == NULL )
{
V_9 = F_94 ( V_74 ,
V_25 , V_20 , 0 ,
V_65 , V_3 , L_100 ) ;
if ( V_9 == NULL ) goto V_77;
}
#ifndef F_80
if ( V_9 -> type == V_102 )
V_61 = F_95 () ;
#endif
assert ( V_67 ) ;
if ( ! F_96 ( V_6 , V_9 , V_50 , V_47 , V_61 ,
V_62 , V_63 ) ) goto V_77;
}
else if ( V_40 == V_12 )
{
F_13 ( V_74 , L_101 ) ;
if ( V_27 != NULL )
{
V_10 = F_94 ( V_74 ,
V_27 , V_22 ,
0 , V_65 , V_3 ,
L_102 ) ;
if ( V_10 == NULL ) goto V_77;
}
#ifndef F_80
if ( V_10 -> type == V_102 )
V_61 = F_95 () ;
#endif
assert ( V_67 ) ;
if ( ! F_97 ( V_56 , V_26 , V_61 , V_6 , V_7 ,
V_10 , V_28 , V_41 , V_50 , V_47 ,
V_62 , V_63 , V_11 ) )
goto V_77;
}
else if ( V_49 == V_12 )
{
T_5 * V_111 ;
F_13 ( V_74 , L_103 ) ;
if ( V_25 == NULL )
{
F_13 ( V_74 , L_104 ) ;
goto V_77;
}
else
{
V_111 = F_94 ( V_74 ,
V_25 , V_79 , 0 ,
V_65 , V_3 , L_105 ) ;
if ( V_111 == NULL ) goto V_77;
}
F_13 ( V_74 , L_106 ) ;
#ifndef F_80
if ( V_111 -> type == V_102 )
V_61 = F_95 () ;
#endif
V_57 = F_98 ( V_6 , V_111 , V_61 ) ;
F_41 ( V_111 ) ;
if ( V_57 == NULL )
{
F_26 ( V_74 ) ;
goto V_77;
}
if ( ! V_38 )
{
F_99 ( V_15 , V_57 ) ;
F_100 ( V_15 , V_57 ) ;
}
V_38 = 1 ;
}
else if ( V_37 == V_12 )
{
F_101 ( V_15 , V_6 ) ;
}
}
}
if ( V_68 )
{
T_15 V_112 = time ( NULL ) ;
if ( F_102 ( F_52 ( V_6 ) , V_112 + V_69 ) == - 1 )
{
F_13 ( V_15 , L_107 ) ;
V_4 = 1 ;
}
else
{
F_13 ( V_15 , L_108 ) ;
V_4 = 0 ;
}
goto V_77;
}
if ( V_38 )
{
V_4 = 0 ;
goto V_77;
}
if ( V_19 == V_113 )
V_12 = F_103 ( V_15 , V_6 ) ;
else if ( V_19 == V_79 )
{
if ( V_43 ) V_12 = F_104 ( V_15 , V_6 ) ;
else V_12 = F_105 ( V_15 , V_6 ) ;
}
else if ( V_19 == V_114 )
{
T_16 V_115 ;
T_17 V_116 ;
V_116 . V_92 = ( unsigned char * ) V_117 ;
V_116 . V_118 = strlen ( V_117 ) ;
V_115 . V_119 = & V_116 ;
V_115 . V_92 = ( char * ) V_6 ;
V_115 . V_120 = F_106 () ;
V_12 = F_107 ( V_121 , V_15 , ( unsigned char * ) & V_115 ) ;
}
else {
F_13 ( V_74 , L_109 ) ;
goto V_77;
}
if ( ! V_12 )
{
F_13 ( V_74 , L_110 ) ;
F_26 ( V_74 ) ;
goto V_77;
}
V_4 = 0 ;
V_77:
if ( V_67 )
F_108 ( NULL , V_74 ) ;
F_109 () ;
F_110 ( V_62 ) ;
F_111 ( V_15 ) ;
F_111 ( STDout ) ;
F_112 ( V_56 ) ;
F_113 ( V_5 ) ;
F_114 ( V_6 ) ;
F_114 ( V_7 ) ;
F_41 ( V_9 ) ;
F_41 ( V_10 ) ;
F_113 ( V_57 ) ;
F_115 ( V_11 ) ;
F_116 ( V_16 , V_122 ) ;
F_116 ( V_17 , V_122 ) ;
if ( V_65 ) F_88 ( V_65 ) ;
F_117 () ;
F_118 ( V_4 ) ;
}
static T_6 * F_119 ( char * V_26 , char * V_123 , int V_124 )
{
char * V_59 = NULL , * V_125 ;
T_18 char V_126 [ 1024 ] ;
T_6 * V_127 = NULL , * V_128 = NULL ;
T_7 * V_129 = NULL ;
T_19 * V_31 = NULL ;
V_59 = F_84 ( ( ( V_123 == NULL )
? ( strlen ( V_26 ) + strlen ( V_130 ) + 1 )
: ( strlen ( V_123 ) ) ) + 1 ) ;
if ( V_59 == NULL ) { F_13 ( V_74 , L_111 ) ; goto V_77; }
if ( V_123 == NULL )
{
strcpy ( V_59 , V_26 ) ;
for ( V_125 = V_59 ; * V_125 ; V_125 ++ )
if ( * V_125 == '.' )
{
* V_125 = '\0' ;
break;
}
strcat ( V_59 , V_130 ) ;
}
else
strcpy ( V_59 , V_123 ) ;
V_31 = F_120 () ;
V_127 = F_121 () ;
if ( ( V_31 == NULL ) || ( V_127 == NULL ) )
{
F_26 ( V_74 ) ;
goto V_77;
}
V_129 = F_7 ( F_34 () ) ;
if ( V_129 == NULL )
{
F_26 ( V_74 ) ;
goto V_77;
}
if ( F_36 ( V_129 , V_59 ) <= 0 )
{
if ( ! V_124 )
{
perror ( V_59 ) ;
goto V_77;
}
else
{
F_46 ( V_127 , 1 ) ;
F_122 ( V_31 ) ;
}
}
else
{
if ( ! F_123 ( V_129 , V_127 , V_126 , sizeof V_126 ) )
{
F_13 ( V_74 , L_112 , V_59 ) ;
F_26 ( V_74 ) ;
goto V_77;
}
else
{
V_31 = F_124 ( V_127 -> V_92 , V_127 -> V_118 , V_31 ) ;
if ( V_31 == NULL )
{
F_13 ( V_74 , L_113 ) ;
goto V_77;
}
}
}
if ( ! F_125 ( V_31 , 1 ) )
{ F_13 ( V_74 , L_114 ) ; goto V_77; }
if ( ! ( V_128 = F_126 ( V_31 , NULL ) ) )
{ F_13 ( V_74 , L_115 ) ; goto V_77; }
if ( F_56 ( V_129 , V_59 ) <= 0 )
{
F_13 ( V_74 , L_116 ) ;
perror ( V_59 ) ;
goto V_77;
}
F_66 ( V_129 , V_128 ) ;
F_72 ( V_129 , L_78 ) ;
F_37 ( V_129 ) ;
if ( V_59 ) F_88 ( V_59 ) ;
F_115 ( V_128 ) ;
F_127 ( V_31 ) ;
V_129 = NULL ;
return V_127 ;
V_77:
if ( V_59 ) F_88 ( V_59 ) ;
F_37 ( V_129 ) ;
F_115 ( V_127 ) ;
F_127 ( V_31 ) ;
return NULL ;
}
static int F_97 ( T_8 * V_56 , char * V_26 , const T_9 * V_61 ,
T_3 * V_6 , T_3 * V_7 , T_5 * V_85 , char * V_123 , int V_124 ,
int V_50 , int V_47 , T_10 * V_131 , char * V_132 , T_6 * V_11 )
{
int V_4 = 0 ;
T_6 * V_127 = NULL ;
T_20 V_133 ;
T_5 * V_134 ;
V_134 = F_77 ( V_7 ) ;
F_128 ( V_134 , V_85 ) ;
F_41 ( V_134 ) ;
if( ! F_129 ( & V_133 , V_56 , V_6 , NULL ) )
{
F_13 ( V_74 , L_117 ) ;
goto V_77;
}
if ( V_11 ) V_127 = V_11 ;
else if ( ! ( V_127 = F_119 ( V_26 , V_123 , V_124 ) ) )
goto V_77;
if ( ! F_130 ( V_56 , V_6 ) ) goto V_77;
F_131 ( & V_133 , V_6 ) ;
if ( ! V_73 && ! F_132 ( & V_133 ) )
goto V_77;
if ( ! F_133 ( V_7 , V_85 ) )
{
F_13 ( V_74 , L_118 ) ;
goto V_77;
}
if ( ! F_48 ( V_6 , F_65 ( V_7 ) ) ) goto V_77;
if ( ! F_45 ( V_6 , V_127 ) ) goto V_77;
if ( F_50 ( F_51 ( V_6 ) , 0L ) == NULL )
goto V_77;
if ( F_50 ( F_52 ( V_6 ) , ( long ) 60 * 60 * 24 * V_50 ) == NULL )
goto V_77;
if ( V_47 )
{
while ( F_134 ( V_6 ) > 0 ) F_135 ( V_6 , 0 ) ;
}
if ( V_131 )
{
T_11 V_84 ;
F_136 ( V_6 , 2 ) ;
F_137 ( & V_84 , V_7 , V_6 , NULL , NULL , 0 ) ;
F_32 ( & V_84 , V_131 ) ;
if ( ! F_33 ( V_131 , & V_84 , V_132 , V_6 ) ) goto V_77;
}
if ( ! F_138 ( V_6 , V_85 , V_61 ) ) goto V_77;
V_4 = 1 ;
V_77:
F_139 ( & V_133 ) ;
if ( ! V_4 )
F_26 ( V_74 ) ;
if ( ! V_11 ) F_115 ( V_127 ) ;
return V_4 ;
}
static int T_21 V_80 ( int V_135 , T_20 * V_56 )
{
int V_136 ;
T_3 * V_137 ;
V_136 = F_140 ( V_56 ) ;
if ( V_136 == V_138 )
return 1 ;
if ( V_135 )
{
F_13 ( V_74 , L_119 ) ;
return 0 ;
}
else
{
V_137 = F_141 ( V_56 ) ;
F_42 ( V_74 , NULL , F_65 ( V_137 ) , 0 ) ;
F_13 ( V_74 , L_120 ,
V_136 , F_142 ( V_56 ) ,
F_143 ( V_136 ) ) ;
return 1 ;
}
}
static int F_96 ( T_3 * V_6 , T_5 * V_85 , int V_50 , int V_47 , const T_9 * V_61 ,
T_10 * V_131 , char * V_132 )
{
T_5 * V_139 ;
V_139 = F_77 ( V_6 ) ;
F_128 ( V_139 , V_85 ) ;
F_144 ( V_139 , 1 ) ;
F_41 ( V_139 ) ;
if ( ! F_48 ( V_6 , F_65 ( V_6 ) ) ) goto V_136;
if ( F_50 ( F_51 ( V_6 ) , 0 ) == NULL ) goto V_136;
if ( F_50 ( F_52 ( V_6 ) , ( long ) 60 * 60 * 24 * V_50 ) == NULL )
goto V_136;
if ( ! F_53 ( V_6 , V_85 ) ) goto V_136;
if ( V_47 )
{
while ( F_134 ( V_6 ) > 0 ) F_135 ( V_6 , 0 ) ;
}
if ( V_131 )
{
T_11 V_56 ;
F_136 ( V_6 , 2 ) ;
F_137 ( & V_56 , V_6 , V_6 , NULL , NULL , 0 ) ;
F_32 ( & V_56 , V_131 ) ;
if ( ! F_33 ( V_131 , & V_56 , V_132 , V_6 ) ) goto V_136;
}
if ( ! F_138 ( V_6 , V_85 , V_61 ) ) goto V_136;
return 1 ;
V_136:
F_26 ( V_74 ) ;
return 0 ;
}
static int F_76 ( T_7 * V_140 , T_3 * V_141 , T_14 * V_142 )
{
int V_143 , V_12 , V_144 ;
char * V_145 ;
V_143 = F_145 ( V_142 ) ;
V_145 = F_146 ( V_142 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
{
V_144 = F_147 ( V_141 , V_143 , V_12 ) ;
F_13 ( V_140 , L_121 , V_145 , V_12 ? L_122 : L_123 ) ;
if ( V_144 == 1 ) F_13 ( V_140 , L_124 ) ;
else if ( V_144 == 0 ) F_13 ( V_140 , L_125 ) ;
else F_13 ( V_140 , L_126 , V_144 ) ;
}
return 1 ;
}
