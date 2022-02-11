int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
unsigned long V_5 = 0 , V_6 = 0 ;
int V_7 = 1 , V_8 = 0 , V_9 = 30 ;
T_2 * V_10 = NULL ;
T_3 * V_11 = NULL ;
T_4 * V_12 = NULL ;
const char * V_13 = NULL ;
char * V_14 = NULL ;
F_1 ( V_15 ) * V_16 = NULL ;
T_5 * V_17 = NULL ;
int V_18 = 0 , V_19 = 0 , V_20 = 0 , V_21 = 0 , V_22 = - 1 ;
long V_23 = - 1 ;
T_6 * V_24 = NULL , * V_25 = NULL ;
int V_26 , V_27 , V_28 = 0 , V_29 = 0 , V_30 = 0 , V_31 = V_32 ;
int V_33 = 0 , V_34 = 0 , V_35 = 0 , V_36 = 0 , V_37 = 0 ;
char * V_38 , * V_39 , * V_40 , * V_41 = NULL , * V_42 = NULL , * V_43 = NULL ;
#ifndef F_2
char * V_44 = NULL ;
#endif
char * V_45 = NULL ;
char * V_46 = NULL ;
const T_7 * V_47 = NULL ;
T_8 * V_48 = NULL ;
int V_49 = 0 ;
char * V_50 = NULL ;
char * V_51 = NULL , * V_52 = NULL ;
char * V_53 = NULL , * V_54 = NULL ;
char * V_55 ;
char * V_56 = NULL ;
int V_57 = 0 ;
const T_9 * V_58 = NULL , * V_59 = NULL ;
unsigned long V_60 = V_61 ;
#ifndef F_3
char * V_62 ;
long V_63 ;
#endif
V_64 = NULL ;
#ifndef F_4
V_47 = F_5 () ;
#endif
F_6 () ;
if ( V_65 == NULL )
if ( ( V_65 = F_7 ( F_8 () ) ) != NULL )
F_9 ( V_65 , V_66 , V_67 | V_68 ) ;
V_38 = NULL ;
V_39 = NULL ;
V_26 = V_32 ;
V_27 = V_32 ;
V_40 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_26 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_27 = F_10 ( * ( ++ V_2 ) ) ;
}
#ifndef F_2
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_44 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_4 = F_11 ( * ( ++ V_2 ) ) ;
if ( V_4 == NULL )
{
F_12 ( V_65 , L_5 , * V_2 ) ;
goto V_70;
}
}
#endif
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_41 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
V_37 = 1 ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
V_20 = 1 ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_42 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_31 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_38 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_39 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_43 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_51 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_52 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_16 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_50 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_17 ) == 0 )
{
if ( -- V_1 < 1 )
goto V_69;
V_13 = * ( ++ V_2 ) ;
V_20 = 1 ;
}
else if ( strcmp ( * V_2 , L_18 ) == 0 )
{
if ( -- V_1 < 1 )
goto V_69;
if ( ! V_16 )
V_16 = F_13 () ;
if ( ! V_16 || ! F_14 ( V_16 , * ( ++ V_2 ) ) )
goto V_69;
}
else if ( strcmp ( * V_2 , L_19 ) == 0 )
V_71 = 1 ;
else if ( strcmp ( * V_2 , L_20 ) == 0 )
V_35 = 1 ;
else if ( strcmp ( * V_2 , L_21 ) == 0 )
V_49 = 1 ;
else if ( strcmp ( * V_2 , L_22 ) == 0 )
V_28 = 1 ;
else if ( strcmp ( * V_2 , L_23 ) == 0 )
V_33 = 1 ;
else if ( strcmp ( * V_2 , L_24 ) == 0 )
V_29 = 1 ;
else if ( strcmp ( * V_2 , L_25 ) == 0 )
V_21 = 1 ;
else if ( strcmp ( * V_2 , L_26 ) == 0 )
V_60 = V_72 ;
else if ( strcmp ( * V_2 , L_27 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
if ( ! F_15 ( & V_5 , * ( ++ V_2 ) ) ) goto V_69;
}
else if ( strcmp ( * V_2 , L_28 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
if ( ! F_16 ( & V_6 , * ( ++ V_2 ) ) ) goto V_69;
}
else if ( strcmp ( * V_2 , L_29 ) == 0 )
V_36 = 1 ;
else if ( strcmp ( * V_2 , L_30 ) == 0 )
V_30 = 1 ;
else if ( strcmp ( * V_2 , L_31 ) == 0 )
V_8 = 1 ;
else if ( strcmp ( * V_2 , L_32 ) == 0 )
V_34 = 1 ;
else if ( strcmp ( * V_2 , L_33 ) == 0 )
V_34 = 0 ;
else if ( strcmp ( * V_2 , L_34 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_56 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_35 ) == 0 )
V_57 = 1 ;
else if ( strcmp ( * V_2 , L_36 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_9 = atoi ( * ( ++ V_2 ) ) ;
if ( V_9 == 0 ) V_9 = 30 ;
}
else if ( strcmp ( * V_2 , L_37 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_48 = F_17 ( NULL , * ( ++ V_2 ) ) ;
if ( ! V_48 ) goto V_69;
}
else if ( strcmp ( * V_2 , L_38 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_45 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_39 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_69;
V_46 = * ( ++ V_2 ) ;
}
else if ( ( V_58 = F_18 ( & ( ( * V_2 ) [ 1 ] ) ) ) != NULL )
{
V_59 = V_58 ;
}
else
{
F_12 ( V_65 , L_40 , * V_2 ) ;
V_19 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_19 )
{
V_69:
F_12 ( V_65 , L_41 , V_40 ) ;
F_12 ( V_65 , L_42 ) ;
F_12 ( V_65 , L_43 ) ;
F_12 ( V_65 , L_44 ) ;
F_12 ( V_65 , L_45 ) ;
F_12 ( V_65 , L_46 ) ;
F_12 ( V_65 , L_47 ) ;
F_12 ( V_65 , L_48 ) ;
F_12 ( V_65 , L_49 ) ;
F_12 ( V_65 , L_50 ) ;
F_12 ( V_65 , L_51 ) ;
F_12 ( V_65 , L_52 ) ;
#ifndef F_2
F_12 ( V_65 , L_53 ) ;
#endif
F_12 ( V_65 , L_54 ) ;
F_12 ( V_65 , L_55 ) ;
F_12 ( V_65 , L_56 ) ;
F_12 ( V_65 , L_57 ) ;
F_12 ( V_65 , L_58 ) ;
F_12 ( V_65 , L_59 , V_73 , V_73 ) ;
F_12 ( V_65 , L_60 ) ;
F_12 ( V_65 , L_61 ) ;
F_12 ( V_65 , L_62 ) ;
F_12 ( V_65 , L_63 ) ;
#ifndef F_19
F_12 ( V_65 , L_64 ) ;
#endif
F_12 ( V_65 , L_65 ) ;
F_12 ( V_65 , L_66 ) ;
F_12 ( V_65 , L_67 ) ;
F_12 ( V_65 , L_68 ) ;
F_12 ( V_65 , L_69 ) ;
F_12 ( V_65 , L_70 ) ;
F_12 ( V_65 , L_71 ) ;
F_12 ( V_65 , L_72 ) ;
F_12 ( V_65 , L_73 ) ;
F_12 ( V_65 , L_74 ) ;
F_12 ( V_65 , L_75 ) ;
F_12 ( V_65 , L_76 ) ;
F_12 ( V_65 , L_77 ) ;
F_12 ( V_65 , L_78 ) ;
F_12 ( V_65 , L_79 ) ;
F_12 ( V_65 , L_80 ) ;
F_12 ( V_65 , L_81 ) ;
goto V_70;
}
F_20 () ;
if( ! F_21 ( V_65 , V_51 , V_52 , & V_53 , & V_54 ) ) {
F_12 ( V_65 , L_82 ) ;
goto V_70;
}
#ifndef F_3
V_55 = getenv ( L_83 ) ;
if ( V_55 == NULL )
V_55 = getenv ( L_84 ) ;
if ( V_55 == NULL )
V_55 = V_62 = F_22 () ;
V_74 = V_55 ;
V_75 = F_23 ( NULL ) ;
V_18 = F_24 ( V_75 , V_55 , & V_63 ) ;
#endif
if ( V_42 != NULL )
{
long V_63 = - 1 ;
if( V_21 )
F_12 ( V_65 , L_85 , V_42 ) ;
V_64 = F_23 ( NULL ) ;
V_18 = F_24 ( V_64 , V_42 , & V_63 ) ;
if ( V_18 == 0 )
{
F_12 ( V_65 , L_86 , V_63 , V_42 ) ;
goto V_70;
}
}
else
{
V_64 = V_75 ;
if ( V_64 == NULL )
{
F_12 ( V_65 , L_87 , V_74 ) ;
if ( V_20 )
goto V_70;
}
else if( V_21 )
F_12 ( V_65 , L_85 ,
V_74 ) ;
}
if ( V_64 != NULL )
{
if ( ! F_25 ( V_65 , V_64 ) )
goto V_70;
V_55 = F_26 ( V_64 , NULL , L_88 ) ;
if ( V_55 == NULL )
F_27 () ;
if ( V_55 != NULL )
{
T_6 * V_76 ;
V_76 = F_28 ( V_55 , L_89 ) ;
if ( V_76 == NULL )
{
}
else
{
F_29 ( V_76 ) ;
F_30 ( V_76 ) ;
}
}
}
if( ! F_31 ( V_65 , V_64 ) ) goto V_70;
if ( V_58 == NULL )
{
V_55 = F_26 ( V_64 , V_77 , L_90 ) ;
if ( V_55 == NULL )
F_27 () ;
if ( V_55 != NULL )
{
if ( ( V_58 = F_18 ( V_55 ) ) != NULL )
V_59 = V_58 ;
}
}
if ( ! V_45 )
{
V_45 = F_26 ( V_64 , V_77 , V_78 ) ;
if ( ! V_45 )
F_27 () ;
}
if ( V_45 ) {
T_10 V_79 ;
F_32 ( & V_79 ) ;
F_33 ( & V_79 , V_64 ) ;
if( ! F_34 ( V_64 , & V_79 , V_45 , NULL ) ) {
F_12 ( V_65 ,
L_91 , V_45 ) ;
goto V_70;
}
}
if( ! V_53 )
{
V_53 = F_26 ( V_64 , V_77 , L_92 ) ;
if ( ! V_53 )
F_27 () ;
}
if( ! V_54 )
{
V_54 = F_26 ( V_64 , V_77 , L_93 ) ;
if ( ! V_54 )
F_27 () ;
}
V_55 = F_26 ( V_64 , V_77 , V_80 ) ;
if ( ! V_55 )
F_27 () ;
if( V_55 && ! F_35 ( V_55 ) ) {
F_12 ( V_65 , L_94 , V_55 ) ;
goto V_70;
}
if ( V_60 != V_72 )
{
V_55 = F_26 ( V_64 , V_77 , V_81 ) ;
if ( ! V_55 )
F_27 () ;
else if ( ! strcmp ( V_55 , L_95 ) )
V_60 = V_72 ;
}
if( ! V_46 )
{
V_46 = F_26 ( V_64 , V_77 , V_82 ) ;
if ( ! V_46 )
F_27 () ;
}
if( V_46 ) {
T_10 V_79 ;
F_32 ( & V_79 ) ;
F_33 ( & V_79 , V_64 ) ;
if( ! F_34 ( V_64 , & V_79 , V_46 , NULL ) ) {
F_12 ( V_65 ,
L_96 ,
V_46 ) ;
goto V_70;
}
}
V_24 = F_7 ( F_8 () ) ;
V_25 = F_7 ( F_8 () ) ;
if ( ( V_24 == NULL ) || ( V_25 == NULL ) )
goto V_70;
#ifndef F_2
V_3 = F_36 ( V_65 , V_44 , 0 ) ;
#endif
if ( V_41 != NULL )
{
V_17 = F_37 ( V_65 , V_41 , V_31 , 0 , V_53 , V_3 ,
L_97 ) ;
if ( ! V_17 )
{
goto V_70;
}
else
{
char * V_83 = F_26 ( V_64 , V_77 , L_98 ) ;
if ( V_83 == NULL )
F_27 () ;
F_38 ( V_83 , V_65 , 0 ) ;
}
}
if ( V_20 && ( V_17 == NULL ) )
{
char * V_83 = F_26 ( V_64 , V_77 , L_98 ) ;
if ( V_83 == NULL )
F_27 () ;
F_38 ( V_83 , V_65 , 0 ) ;
if ( V_50 )
F_39 ( V_50 ) ;
if ( V_13 )
{
V_12 = F_40 ( V_65 , V_13 , & V_22 , & V_23 ,
& V_14 , V_4 ) ;
if ( ! V_12 )
goto V_70;
}
if ( V_23 <= 0 )
{
if ( ! F_41 ( V_64 , V_77 , V_84 , & V_23 ) )
V_23 = V_85 ;
}
if ( V_23 < V_86 && ( V_22 == V_87 || V_22 == V_88 ) )
{
F_12 ( V_65 , L_99 ) ;
F_12 ( V_65 , L_100 , V_86 , V_23 ) ;
goto V_70;
}
if ( ! V_12 )
{
V_12 = F_40 ( V_65 , NULL , & V_22 , & V_23 ,
& V_14 , V_4 ) ;
if ( ! V_12 )
goto V_70;
}
if ( V_16 )
{
char * V_89 ;
for ( V_18 = 0 ; V_18 < F_42 ( V_16 ) ; V_18 ++ )
{
V_89 = F_43 ( V_16 , V_18 ) ;
if ( F_44 ( V_12 , V_89 ) <= 0 )
{
F_12 ( V_65 ,
L_101 ,
V_89 ) ;
F_45 ( V_65 ) ;
goto V_70;
}
}
}
F_12 ( V_65 , L_102 ,
V_23 , V_14 ) ;
F_46 ( V_12 , V_90 ) ;
F_47 ( V_12 , V_65 ) ;
if ( F_48 ( V_12 , & V_17 ) <= 0 )
{
F_49 ( V_65 , L_103 ) ;
goto V_70;
}
F_50 ( V_12 ) ;
V_12 = NULL ;
F_51 ( V_83 , V_65 ) ;
if ( V_43 == NULL )
{
V_43 = F_26 ( V_64 , V_77 , V_91 ) ;
if ( V_43 == NULL )
F_27 () ;
}
if ( V_43 == NULL )
{
F_12 ( V_65 , L_104 ) ;
F_9 ( V_25 , stdout , V_67 ) ;
#ifdef F_52
{
T_6 * V_92 = F_7 ( F_53 () ) ;
V_25 = F_54 ( V_92 , V_25 ) ;
}
#endif
}
else
{
F_12 ( V_65 , L_105 , V_43 ) ;
if ( F_55 ( V_25 , V_43 ) <= 0 )
{
perror ( V_43 ) ;
goto V_70;
}
}
V_55 = F_26 ( V_64 , V_77 , L_106 ) ;
if ( V_55 == NULL )
{
F_27 () ;
V_55 = F_26 ( V_64 , V_77 , L_107 ) ;
if ( V_55 == NULL )
F_27 () ;
}
if ( ( V_55 != NULL ) && ( strcmp ( V_55 , L_108 ) == 0 ) )
V_47 = NULL ;
if ( V_33 ) V_47 = NULL ;
V_18 = 0 ;
V_93:
if ( ! F_56 ( V_25 , V_17 , V_47 ,
NULL , 0 , NULL , V_54 ) )
{
if ( ( F_57 ( F_58 () ) ==
V_94 ) && ( V_18 < 3 ) )
{
F_27 () ;
V_18 ++ ;
goto V_93;
}
goto V_70;
}
F_12 ( V_65 , L_109 ) ;
}
if ( ! V_20 )
{
V_34 = - 1 ;
if ( V_38 == NULL )
F_9 ( V_24 , V_95 , V_67 ) ;
else
{
if ( F_59 ( V_24 , V_38 ) <= 0 )
{
perror ( V_38 ) ;
goto V_70;
}
}
if ( V_26 == V_96 )
V_11 = F_60 ( V_24 , NULL ) ;
else if ( V_26 == V_32 )
V_11 = F_61 ( V_24 , NULL , NULL , NULL ) ;
else
{
F_12 ( V_65 , L_110 ) ;
goto V_70;
}
if ( V_11 == NULL )
{
F_12 ( V_65 , L_111 ) ;
goto V_70;
}
}
if ( V_20 || V_8 )
{
if ( V_17 == NULL )
{
F_12 ( V_65 , L_112 ) ;
goto V_70;
}
if ( V_11 == NULL )
{
V_11 = F_62 () ;
if ( V_11 == NULL )
{
goto V_70;
}
V_18 = F_63 ( V_11 , V_17 , V_56 , V_57 , ! V_8 , V_60 ) ;
V_56 = NULL ;
if ( ( V_34 > 0 ) && ! F_64 ( V_11 -> V_97 -> V_98 ) )
{
F_65 ( V_11 -> V_97 -> V_98 ) ;
V_11 -> V_97 -> V_98 = NULL ;
}
if ( ! V_18 )
{
F_12 ( V_65 , L_113 ) ;
goto V_70;
}
}
if ( V_8 )
{
T_5 * V_99 ;
T_10 V_100 ;
if ( ( V_10 = F_66 () ) == NULL ) goto V_70;
if( V_45 && ! F_67 ( V_10 , 2 ) ) goto V_70;
if ( V_48 )
{
if ( ! F_68 ( V_10 , V_48 ) ) goto V_70;
}
else
{
if ( ! F_69 ( NULL ,
F_70 ( V_10 ) ) )
goto V_70;
}
if ( ! F_71 ( V_10 , F_72 ( V_11 ) ) ) goto V_70;
if ( ! F_73 ( F_74 ( V_10 ) , 0 ) ) goto V_70;
if ( ! F_75 ( F_76 ( V_10 ) , V_9 , 0 , NULL ) ) goto V_70;
if ( ! F_77 ( V_10 , F_72 ( V_11 ) ) ) goto V_70;
V_99 = F_78 ( V_11 ) ;
if ( ! V_99 || ! F_79 ( V_10 , V_99 ) ) goto V_70;
F_80 ( V_99 ) ;
F_81 ( & V_100 , V_10 , V_10 , NULL , NULL , 0 ) ;
F_33 ( & V_100 , V_64 ) ;
if( V_45 && ! F_34 ( V_64 ,
& V_100 , V_45 , V_10 ) )
{
F_12 ( V_65 ,
L_91 ,
V_45 ) ;
goto V_70;
}
if ( ! ( V_18 = F_82 ( V_10 , V_17 , V_59 ) ) )
{
F_45 ( V_65 ) ;
goto V_70;
}
}
else
{
T_10 V_100 ;
F_81 ( & V_100 , NULL , NULL , V_11 , NULL , 0 ) ;
F_33 ( & V_100 , V_64 ) ;
if( V_46 && ! F_83 ( V_64 ,
& V_100 , V_46 , V_11 ) )
{
F_12 ( V_65 ,
L_91 ,
V_46 ) ;
goto V_70;
}
if ( ! ( V_18 = F_84 ( V_11 , V_17 , V_59 ) ) )
{
F_45 ( V_65 ) ;
goto V_70;
}
}
}
if ( V_56 && V_8 )
{
F_12 ( V_65 , L_114 ) ;
goto V_70;
}
if ( V_56 && ! V_8 )
{
if ( V_21 )
{
F_12 ( V_65 , L_115 ) ;
F_85 ( V_65 , L_116 , F_72 ( V_11 ) , V_5 ) ;
}
if ( F_86 ( V_11 , V_56 , V_60 , V_57 ) == 0 )
{
F_12 ( V_65 , L_117 ) ;
V_7 = 1 ;
goto V_70;
}
V_11 -> V_97 -> V_101 . V_102 = 1 ;
if ( V_21 )
{
F_85 ( V_65 , L_118 , F_72 ( V_11 ) , V_5 ) ;
}
}
if ( V_28 && ! V_8 )
{
int V_103 = 0 ;
if ( V_17 == NULL )
{
V_17 = F_78 ( V_11 ) ;
V_103 = 1 ;
if ( V_17 == NULL ) goto V_70;
}
V_18 = F_87 ( V_11 , V_17 ) ;
if ( V_103 ) {
F_80 ( V_17 ) ;
V_17 = NULL ;
}
if ( V_18 < 0 )
{
goto V_70;
}
else if ( V_18 == 0 )
{
F_12 ( V_65 , L_119 ) ;
F_45 ( V_65 ) ;
}
else
F_12 ( V_65 , L_120 ) ;
}
if ( V_29 && ! V_30 && ! V_49 && ! V_36 && ! V_37 )
{
V_7 = 0 ;
goto V_70;
}
if ( V_39 == NULL )
{
F_9 ( V_25 , stdout , V_67 ) ;
#ifdef F_52
{
T_6 * V_92 = F_7 ( F_53 () ) ;
V_25 = F_54 ( V_92 , V_25 ) ;
}
#endif
}
else
{
if ( ( V_43 != NULL ) && ( strcmp ( V_39 , V_43 ) == 0 ) )
V_18 = ( int ) F_88 ( V_25 , V_39 ) ;
else
V_18 = ( int ) F_55 ( V_25 , V_39 ) ;
if ( ! V_18 )
{
perror ( V_39 ) ;
goto V_70;
}
}
if ( V_37 )
{
T_5 * V_104 ;
V_104 = F_78 ( V_11 ) ;
if ( V_104 == NULL )
{
F_12 ( V_65 , L_121 ) ;
F_45 ( V_65 ) ;
goto V_70;
}
F_89 ( V_25 , V_104 ) ;
F_80 ( V_104 ) ;
}
if ( V_30 )
{
if ( V_8 )
F_90 ( V_25 , V_10 , V_5 , V_6 ) ;
else
F_91 ( V_25 , V_11 , V_5 , V_6 ) ;
}
if( V_36 )
{
if( V_8 )
F_85 ( V_25 , L_122 , F_92 ( V_10 ) , V_5 ) ;
else
F_85 ( V_25 , L_122 , F_72 ( V_11 ) , V_5 ) ;
}
if ( V_49 )
{
T_5 * V_104 ;
if ( V_8 )
V_104 = F_93 ( V_10 ) ;
else
V_104 = F_78 ( V_11 ) ;
if ( V_104 == NULL )
{
fprintf ( stdout , L_123 ) ;
goto V_70;
}
fprintf ( stdout , L_124 ) ;
#ifndef F_94
if ( F_95 ( V_104 ) == V_87 )
F_96 ( V_25 , V_104 -> V_17 . V_105 -> V_106 ) ;
else
#endif
fprintf ( stdout , L_125 ) ;
F_80 ( V_104 ) ;
fprintf ( stdout , L_126 ) ;
}
if ( ! V_29 && ! V_8 )
{
if ( V_27 == V_96 )
V_18 = F_97 ( V_25 , V_11 ) ;
else if ( V_27 == V_32 ) {
if( V_35 ) V_18 = F_98 ( V_25 , V_11 ) ;
else V_18 = F_99 ( V_25 , V_11 ) ;
} else {
F_12 ( V_65 , L_127 ) ;
goto V_70;
}
if ( ! V_18 )
{
F_12 ( V_65 , L_128 ) ;
goto V_70;
}
}
if ( ! V_29 && V_8 && ( V_10 != NULL ) )
{
if ( V_27 == V_96 )
V_18 = F_100 ( V_25 , V_10 ) ;
else if ( V_27 == V_32 )
V_18 = F_101 ( V_25 , V_10 ) ;
else {
F_12 ( V_65 , L_127 ) ;
goto V_70;
}
if ( ! V_18 )
{
F_12 ( V_65 , L_129 ) ;
goto V_70;
}
}
V_7 = 0 ;
V_70:
#ifndef F_3
if( V_62 )
F_102 ( V_62 ) ;
#endif
if ( V_7 )
{
F_45 ( V_65 ) ;
}
if ( ( V_64 != NULL ) && ( V_64 != V_75 ) ) F_103 ( V_64 ) ;
F_30 ( V_24 ) ;
F_104 ( V_25 ) ;
F_80 ( V_17 ) ;
if ( V_12 )
F_50 ( V_12 ) ;
if ( V_16 )
F_105 ( V_16 ) ;
#ifndef F_2
if ( V_4 )
F_106 ( V_4 ) ;
#endif
if ( V_14 )
F_102 ( V_14 ) ;
F_107 ( V_11 ) ;
F_108 ( V_10 ) ;
F_109 ( V_48 ) ;
if( V_51 && V_53 ) F_102 ( V_53 ) ;
if( V_52 && V_54 ) F_102 ( V_54 ) ;
F_110 () ;
F_111 () ;
F_112 ( V_7 ) ;
}
static int F_63 ( T_3 * V_11 , T_5 * V_17 , char * V_56 , int V_57 ,
int V_107 , unsigned long V_60 )
{
int V_108 = 0 , V_18 ;
char V_109 = 0 ;
F_1 ( V_110 ) * V_111 , * V_112 = NULL ;
char * V_103 , * V_113 , * V_114 ;
V_103 = F_26 ( V_64 , V_77 , V_115 ) ;
if ( V_103 == NULL )
F_27 () ;
if( ( V_103 != NULL ) && ! strcmp ( V_103 , L_108 ) ) V_109 = 1 ;
V_113 = F_26 ( V_64 , V_77 , V_116 ) ;
if ( V_113 == NULL )
{
F_12 ( V_65 , L_130 ,
V_116 ) ;
goto V_117;
}
V_111 = F_113 ( V_64 , V_113 ) ;
if ( V_111 == NULL )
{
F_12 ( V_65 , L_131 , V_113 ) ;
goto V_117;
}
V_114 = F_26 ( V_64 , V_77 , V_118 ) ;
if ( V_114 == NULL )
{
F_27 () ;
V_112 = NULL ;
}
else
{
V_112 = F_113 ( V_64 , V_114 ) ;
if ( V_112 == NULL )
{
F_12 ( V_65 , L_131 , V_114 ) ;
goto V_117;
}
}
if ( ! F_114 ( V_11 , 0L ) ) goto V_117;
if ( V_109 )
V_18 = F_115 ( V_11 , V_111 , V_112 , V_107 , V_60 ) ;
else
{
if ( V_56 )
V_18 = F_86 ( V_11 , V_56 , V_60 , V_57 ) ;
else
V_18 = F_116 ( V_11 , V_111 , V_113 , V_112 , V_114 , V_107 , V_60 ) ;
}
if( ! V_18 ) goto V_117;
if ( ! F_117 ( V_11 , V_17 ) ) goto V_117;
V_108 = 1 ;
V_117:
return ( V_108 ) ;
}
static int F_86 ( T_3 * V_11 , char * V_36 , unsigned long V_60 , int V_57 )
{
T_11 * V_106 ;
if ( ! ( V_106 = F_118 ( V_36 , V_60 , V_57 ) ) )
return 0 ;
if ( ! F_119 ( V_11 , V_106 ) )
{
F_120 ( V_106 ) ;
return 0 ;
}
F_120 ( V_106 ) ;
return 1 ;
}
static int F_121 ( T_11 * V_106 , char * V_30 , const char * V_119 , char * V_120 ,
int V_121 , int V_122 , int V_123 , unsigned long V_60 , int V_124 )
{
int V_18 , V_108 = 0 ;
T_12 char V_125 [ 1024 ] ;
V_126:
if ( ! V_71 ) F_12 ( V_65 , L_132 , V_30 , V_119 ) ;
( void ) F_122 ( V_65 ) ;
if( V_120 != NULL )
{
F_123 ( V_125 , V_120 , sizeof V_125 ) ;
F_124 ( V_125 , L_126 , sizeof V_125 ) ;
F_12 ( V_65 , L_133 , V_120 ) ;
}
else
{
V_125 [ 0 ] = '\0' ;
if ( ! V_71 )
{
if ( ! fgets ( V_125 , sizeof V_125 , V_95 ) )
return 0 ;
}
else
{
V_125 [ 0 ] = '\n' ;
V_125 [ 1 ] = '\0' ;
}
}
if ( V_125 [ 0 ] == '\0' ) return ( 0 ) ;
else if ( V_125 [ 0 ] == '\n' )
{
if ( ( V_119 == NULL ) || ( V_119 [ 0 ] == '\0' ) )
return ( 1 ) ;
F_123 ( V_125 , V_119 , sizeof V_125 ) ;
F_124 ( V_125 , L_126 , sizeof V_125 ) ;
}
else if ( ( V_125 [ 0 ] == '.' ) && ( V_125 [ 1 ] == '\n' ) ) return ( 1 ) ;
V_18 = strlen ( V_125 ) ;
if ( V_125 [ V_18 - 1 ] != '\n' )
{
F_12 ( V_65 , L_134 ) ;
return ( 0 ) ;
}
V_125 [ -- V_18 ] = '\0' ;
#ifdef F_125
F_126 ( V_125 , V_125 , V_18 ) ;
#endif
if( ! F_127 ( V_18 , V_122 , V_123 ) ) goto V_126;
if ( ! F_128 ( V_106 , V_121 , V_60 ,
( unsigned char * ) V_125 , - 1 , - 1 , V_124 ) ) goto V_117;
V_108 = 1 ;
V_117:
return ( V_108 ) ;
}
static int F_129 ( T_3 * V_11 , char * V_30 , const char * V_119 ,
char * V_120 , int V_121 , int V_122 ,
int V_123 , unsigned long V_60 )
{
int V_18 ;
static char V_125 [ 1024 ] ;
V_126:
if ( ! V_71 ) F_12 ( V_65 , L_132 , V_30 , V_119 ) ;
( void ) F_122 ( V_65 ) ;
if ( V_120 != NULL )
{
F_123 ( V_125 , V_120 , sizeof V_125 ) ;
F_124 ( V_125 , L_126 , sizeof V_125 ) ;
F_12 ( V_65 , L_133 , V_120 ) ;
}
else
{
V_125 [ 0 ] = '\0' ;
if ( ! V_71 )
{
if ( ! fgets ( V_125 , sizeof V_125 , V_95 ) )
return 0 ;
}
else
{
V_125 [ 0 ] = '\n' ;
V_125 [ 1 ] = '\0' ;
}
}
if ( V_125 [ 0 ] == '\0' ) return ( 0 ) ;
else if ( V_125 [ 0 ] == '\n' )
{
if ( ( V_119 == NULL ) || ( V_119 [ 0 ] == '\0' ) )
return ( 1 ) ;
F_123 ( V_125 , V_119 , sizeof V_125 ) ;
F_124 ( V_125 , L_126 , sizeof V_125 ) ;
}
else if ( ( V_125 [ 0 ] == '.' ) && ( V_125 [ 1 ] == '\n' ) ) return ( 1 ) ;
V_18 = strlen ( V_125 ) ;
if ( V_125 [ V_18 - 1 ] != '\n' )
{
F_12 ( V_65 , L_134 ) ;
return ( 0 ) ;
}
V_125 [ -- V_18 ] = '\0' ;
#ifdef F_125
F_126 ( V_125 , V_125 , V_18 ) ;
#endif
if( ! F_127 ( V_18 , V_122 , V_123 ) ) goto V_126;
if( ! F_130 ( V_11 , V_121 , V_60 ,
( unsigned char * ) V_125 , - 1 ) ) {
F_12 ( V_65 , L_135 ) ;
F_45 ( V_65 ) ;
goto V_117;
}
return ( 1 ) ;
V_117:
return ( 0 ) ;
}
static int F_127 ( int V_127 , int V_122 , int V_123 )
{
if ( ( V_122 > 0 ) && ( V_127 < V_122 ) )
{
F_12 ( V_65 , L_136 , V_122 ) ;
return ( 0 ) ;
}
if ( ( V_123 >= 0 ) && ( V_127 > V_123 ) )
{
F_12 ( V_65 , L_137 , V_123 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_131 ( const char * V_128 , const char * V_70 )
{
int V_129 , V_130 ;
const char * V_103 ;
V_129 = strlen ( V_70 ) ;
V_130 = strlen ( V_128 ) ;
if( V_129 > V_130 ) return 1 ;
V_103 = V_128 + V_130 - V_129 ;
return strcmp ( V_103 , V_70 ) ;
}
static T_4 * F_40 ( T_6 * V_117 , const char * V_131 , int * V_22 ,
long * V_132 , char * * V_133 ,
T_1 * V_134 )
{
T_4 * V_135 = NULL ;
T_5 * V_136 = NULL ;
long V_137 = - 1 ;
T_6 * V_138 = NULL ;
const char * V_139 = NULL ;
if ( V_131 == NULL )
{
* V_22 = V_87 ;
V_137 = * V_132 ;
}
else if ( V_131 [ 0 ] >= '0' && V_131 [ 0 ] <= '9' )
{
* V_22 = V_87 ;
V_137 = atol ( V_131 ) ;
* V_132 = V_137 ;
}
else if ( ! strncmp ( V_131 , L_138 , 6 ) )
V_139 = V_131 + 6 ;
else
{
const char * V_55 = strchr ( V_131 , ':' ) ;
int V_127 ;
T_1 * V_140 ;
const T_13 * V_141 ;
if ( V_55 )
V_127 = V_55 - V_131 ;
else
V_127 = strlen ( V_131 ) ;
V_141 = F_132 ( & V_140 , V_131 , V_127 ) ;
if ( ! V_141 )
{
F_12 ( V_117 , L_139 , V_127 , V_131 ) ;
return NULL ;
}
F_133 ( NULL , V_22 , NULL , NULL , NULL ,
V_141 ) ;
#ifndef F_2
if ( V_140 )
F_134 ( V_140 ) ;
#endif
if ( * V_22 == V_87 )
{
if ( V_55 )
{
V_137 = atol ( V_55 + 1 ) ;
* V_132 = V_137 ;
}
}
else if ( V_55 )
V_139 = V_55 + 1 ;
}
if ( V_139 )
{
V_138 = F_28 ( V_139 , L_89 ) ;
if ( ! V_138 )
{
F_12 ( V_117 , L_140 ,
V_139 ) ;
return NULL ;
}
V_136 = F_135 ( V_138 , NULL ) ;
if ( ! V_136 )
{
T_2 * V_142 ;
( void ) F_136 ( V_138 ) ;
V_142 = F_137 ( V_138 , NULL , NULL , NULL ) ;
if ( V_142 )
{
V_136 = F_93 ( V_142 ) ;
F_108 ( V_142 ) ;
}
}
F_30 ( V_138 ) ;
if ( ! V_136 )
{
F_12 ( V_117 , L_141 ,
V_139 ) ;
return NULL ;
}
if ( * V_22 == - 1 )
* V_22 = F_138 ( V_136 ) ;
else if ( * V_22 != F_95 ( V_136 ) )
{
F_12 ( V_117 , L_142 ) ;
F_80 ( V_136 ) ;
return NULL ;
}
}
if ( V_133 )
{
const T_13 * V_141 ;
T_1 * V_140 ;
const char * V_143 ;
V_141 = F_139 ( & V_140 , * V_22 ) ;
if ( ! V_141 )
{
F_49 ( V_117 , L_143 ) ;
return NULL ;
}
F_133 ( NULL , NULL , NULL , NULL , & V_143 , V_141 ) ;
* V_133 = F_140 ( V_143 ) ;
#ifndef F_2
if ( V_140 )
F_134 ( V_140 ) ;
#endif
}
if ( V_136 )
{
V_135 = F_141 ( V_136 , V_134 ) ;
* V_132 = F_142 ( V_136 ) ;
F_80 ( V_136 ) ;
}
else
V_135 = F_143 ( * V_22 , V_134 ) ;
if ( ! V_135 )
{
F_49 ( V_117 , L_144 ) ;
F_45 ( V_117 ) ;
return NULL ;
}
if ( F_144 ( V_135 ) <= 0 )
{
F_49 ( V_117 , L_145 ) ;
F_45 ( V_117 ) ;
return NULL ;
}
#ifndef F_94
if ( ( * V_22 == V_87 ) && ( V_137 != - 1 ) )
{
if ( F_145 ( V_135 , V_137 ) <= 0 )
{
F_49 ( V_117 , L_146 ) ;
F_45 ( V_117 ) ;
F_50 ( V_135 ) ;
return NULL ;
}
}
#endif
return V_135 ;
}
static int V_90 ( T_4 * V_79 )
{
char V_144 = '*' ;
T_6 * V_145 = F_146 ( V_79 ) ;
int V_55 ;
V_55 = F_147 ( V_79 , 0 ) ;
if ( V_55 == 0 ) V_144 = '.' ;
if ( V_55 == 1 ) V_144 = '+' ;
if ( V_55 == 2 ) V_144 = '*' ;
if ( V_55 == 3 ) V_144 = '\n' ;
F_148 ( V_145 , & V_144 , 1 ) ;
( void ) F_122 ( V_145 ) ;
#ifdef F_149
V_55 = V_106 ;
#endif
return 1 ;
}
