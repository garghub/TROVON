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
F_1 ( V_15 ) * V_16 = NULL , * V_17 = NULL ;
T_5 * V_18 = NULL ;
int V_19 = 0 , V_20 = 0 , V_21 = 0 , V_22 = 0 , V_23 = - 1 ;
long V_24 = - 1 ;
T_6 * V_25 = NULL , * V_26 = NULL ;
int V_27 , V_28 , V_29 = 0 , V_30 = 0 , V_31 = 0 , V_32 =
V_33 ;
int V_34 = 0 , V_35 = 0 , V_36 = 0 , V_37 = 0 , V_38 = 0 ;
char * V_39 , * V_40 , * V_41 , * V_42 = NULL , * V_43 =
NULL , * V_44 = NULL ;
#ifndef F_2
char * V_45 = NULL ;
#endif
char * V_46 = NULL ;
char * V_47 = NULL ;
const T_7 * V_48 = NULL ;
T_8 * V_49 = NULL ;
int V_50 = 0 ;
char * V_51 = NULL ;
char * V_52 = NULL , * V_53 = NULL ;
char * V_54 = NULL , * V_55 = NULL ;
char * V_56 ;
char * V_57 = NULL ;
int V_58 = 0 ;
const T_9 * V_59 = NULL , * V_60 = NULL ;
unsigned long V_61 = V_62 ;
#ifndef F_3
char * V_63 ;
long V_64 ;
#endif
V_65 = NULL ;
#ifndef F_4
V_48 = F_5 () ;
#endif
F_6 () ;
if ( V_66 == NULL )
if ( ( V_66 = F_7 ( F_8 () ) ) != NULL )
F_9 ( V_66 , V_67 , V_68 | V_69 ) ;
V_39 = NULL ;
V_40 = NULL ;
V_27 = V_33 ;
V_28 = V_33 ;
V_41 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 ) {
if ( strcmp ( * V_2 , L_1 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_27 = F_10 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_2 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_28 = F_10 ( * ( ++ V_2 ) ) ;
}
#ifndef F_2
else if ( strcmp ( * V_2 , L_3 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_45 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_4 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_4 = F_11 ( * ( ++ V_2 ) ) ;
if ( V_4 == NULL ) {
F_12 ( V_66 , L_5 , * V_2 ) ;
goto V_71;
}
}
#endif
else if ( strcmp ( * V_2 , L_6 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_42 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_7 ) == 0 ) {
V_38 = 1 ;
} else if ( strcmp ( * V_2 , L_8 ) == 0 ) {
V_21 = 1 ;
} else if ( strcmp ( * V_2 , L_9 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_43 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_10 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_32 = F_10 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_11 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_39 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_12 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_40 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_13 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_44 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_14 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_52 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_15 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_53 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_16 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_51 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_17 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_13 = * ( ++ V_2 ) ;
V_21 = 1 ;
} else if ( strcmp ( * V_2 , L_18 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
if ( ! V_16 )
V_16 = F_13 () ;
if ( ! V_16 || ! F_14 ( V_16 , * ( ++ V_2 ) ) )
goto V_70;
} else if ( strcmp ( * V_2 , L_19 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
if ( ! V_17 )
V_17 = F_13 () ;
if ( ! V_17 || ! F_14 ( V_17 , * ( ++ V_2 ) ) )
goto V_70;
} else if ( strcmp ( * V_2 , L_20 ) == 0 )
V_72 = 1 ;
else if ( strcmp ( * V_2 , L_21 ) == 0 )
V_36 = 1 ;
else if ( strcmp ( * V_2 , L_22 ) == 0 )
V_50 = 1 ;
else if ( strcmp ( * V_2 , L_23 ) == 0 )
V_29 = 1 ;
else if ( strcmp ( * V_2 , L_24 ) == 0 )
V_34 = 1 ;
else if ( strcmp ( * V_2 , L_25 ) == 0 )
V_30 = 1 ;
else if ( strcmp ( * V_2 , L_26 ) == 0 )
V_22 = 1 ;
else if ( strcmp ( * V_2 , L_27 ) == 0 )
V_61 = V_73 ;
else if ( strcmp ( * V_2 , L_28 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
if ( ! F_15 ( & V_5 , * ( ++ V_2 ) ) )
goto V_70;
} else if ( strcmp ( * V_2 , L_29 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
if ( ! F_16 ( & V_6 , * ( ++ V_2 ) ) )
goto V_70;
} else if ( strcmp ( * V_2 , L_30 ) == 0 )
V_37 = 1 ;
else if ( strcmp ( * V_2 , L_31 ) == 0 )
V_31 = 1 ;
else if ( strcmp ( * V_2 , L_32 ) == 0 )
V_8 = 1 ;
else if ( strcmp ( * V_2 , L_33 ) == 0 )
V_35 = 1 ;
else if ( strcmp ( * V_2 , L_34 ) == 0 )
V_35 = 0 ;
else if ( strcmp ( * V_2 , L_35 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_57 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_36 ) == 0 )
V_58 = 1 ;
else if ( strcmp ( * V_2 , L_37 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_9 = atoi ( * ( ++ V_2 ) ) ;
if ( V_9 == 0 )
V_9 = 30 ;
} else if ( strcmp ( * V_2 , L_38 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_49 = F_17 ( NULL , * ( ++ V_2 ) ) ;
if ( ! V_49 )
goto V_70;
} else if ( strcmp ( * V_2 , L_39 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_46 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_40 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_70;
V_47 = * ( ++ V_2 ) ;
} else if ( ( V_59 = F_18 ( & ( ( * V_2 ) [ 1 ] ) ) ) != NULL ) {
V_60 = V_59 ;
} else {
F_12 ( V_66 , L_41 , * V_2 ) ;
V_20 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_20 ) {
V_70:
F_12 ( V_66 , L_42 , V_41 ) ;
F_12 ( V_66 , L_43 ) ;
F_12 ( V_66 , L_44 ) ;
F_12 ( V_66 , L_45 ) ;
F_12 ( V_66 , L_46 ) ;
F_12 ( V_66 , L_47 ) ;
F_12 ( V_66 , L_48 ) ;
F_12 ( V_66 , L_49 ) ;
F_12 ( V_66 , L_50 ) ;
F_12 ( V_66 , L_51 ) ;
F_12 ( V_66 , L_52 ) ;
F_12 ( V_66 , L_53 ) ;
#ifndef F_2
F_12 ( V_66 ,
L_54 ) ;
#endif
F_12 ( V_66 , L_55 ) ;
F_12 ( V_66 , L_56 ) ;
F_12 ( V_66 ,
L_57 ) ;
F_12 ( V_66 , L_58 ) ;
F_12 ( V_66 , L_59 ) ;
F_12 ( V_66 , L_60 , V_74 ,
V_74 ) ;
F_12 ( V_66 ,
L_61 ) ;
F_12 ( V_66 , L_62 ) ;
F_12 ( V_66 ,
L_63 ) ;
F_12 ( V_66 ,
L_64 ) ;
#ifndef F_19
F_12 ( V_66 ,
L_65 ) ;
#endif
F_12 ( V_66 ,
L_66 ) ;
F_12 ( V_66 , L_67 ) ;
F_12 ( V_66 ,
L_68 ) ;
F_12 ( V_66 ,
L_69 ) ;
F_12 ( V_66 , L_70 ) ;
F_12 ( V_66 ,
L_71 ) ;
F_12 ( V_66 ,
L_72 ) ;
F_12 ( V_66 ,
L_73 ) ;
F_12 ( V_66 ,
L_74 ) ;
F_12 ( V_66 ,
L_75 ) ;
F_12 ( V_66 ,
L_76 ) ;
F_12 ( V_66 ,
L_77 ) ;
F_12 ( V_66 ,
L_78 ) ;
F_12 ( V_66 ,
L_79 ) ;
F_12 ( V_66 ,
L_80 ) ;
F_12 ( V_66 ,
L_81 ) ;
F_12 ( V_66 ,
L_82 ) ;
goto V_71;
}
F_20 () ;
if ( ! F_21 ( V_66 , V_52 , V_53 , & V_54 , & V_55 ) ) {
F_12 ( V_66 , L_83 ) ;
goto V_71;
}
#ifndef F_3
V_56 = getenv ( L_84 ) ;
if ( V_56 == NULL )
V_56 = getenv ( L_85 ) ;
if ( V_56 == NULL )
V_56 = V_63 = F_22 () ;
V_75 = V_56 ;
V_76 = F_23 ( NULL ) ;
V_19 = F_24 ( V_76 , V_56 , & V_64 ) ;
#endif
if ( V_43 != NULL ) {
long V_64 = - 1 ;
if ( V_22 )
F_12 ( V_66 , L_86 , V_43 ) ;
V_65 = F_23 ( NULL ) ;
V_19 = F_24 ( V_65 , V_43 , & V_64 ) ;
if ( V_19 == 0 ) {
F_12 ( V_66 , L_87 , V_64 ,
V_43 ) ;
goto V_71;
}
} else {
V_65 = V_76 ;
if ( V_65 == NULL ) {
F_12 ( V_66 , L_88 ,
V_75 ) ;
if ( V_21 )
goto V_71;
} else if ( V_22 )
F_12 ( V_66 , L_86 ,
V_75 ) ;
}
if ( V_65 != NULL ) {
if ( ! F_25 ( V_66 , V_65 ) )
goto V_71;
V_56 = F_26 ( V_65 , NULL , L_89 ) ;
if ( V_56 == NULL )
F_27 () ;
if ( V_56 != NULL ) {
T_6 * V_77 ;
V_77 = F_28 ( V_56 , L_90 ) ;
if ( V_77 == NULL ) {
} else {
F_29 ( V_77 ) ;
F_30 ( V_77 ) ;
}
}
}
if ( ! F_31 ( V_66 , V_65 ) )
goto V_71;
if ( V_59 == NULL ) {
V_56 = F_26 ( V_65 , V_78 , L_91 ) ;
if ( V_56 == NULL )
F_27 () ;
if ( V_56 != NULL ) {
if ( ( V_59 = F_18 ( V_56 ) ) != NULL )
V_60 = V_59 ;
}
}
if ( ! V_46 ) {
V_46 = F_26 ( V_65 , V_78 , V_79 ) ;
if ( ! V_46 )
F_27 () ;
}
if ( V_46 ) {
T_10 V_80 ;
F_32 ( & V_80 ) ;
F_33 ( & V_80 , V_65 ) ;
if ( ! F_34 ( V_65 , & V_80 , V_46 , NULL ) ) {
F_12 ( V_66 ,
L_92 , V_46 ) ;
goto V_71;
}
}
if ( ! V_54 ) {
V_54 = F_26 ( V_65 , V_78 , L_93 ) ;
if ( ! V_54 )
F_27 () ;
}
if ( ! V_55 ) {
V_55 = F_26 ( V_65 , V_78 , L_94 ) ;
if ( ! V_55 )
F_27 () ;
}
V_56 = F_26 ( V_65 , V_78 , V_81 ) ;
if ( ! V_56 )
F_27 () ;
if ( V_56 && ! F_35 ( V_56 ) ) {
F_12 ( V_66 , L_95 , V_56 ) ;
goto V_71;
}
if ( V_61 != V_73 ) {
V_56 = F_26 ( V_65 , V_78 , V_82 ) ;
if ( ! V_56 )
F_27 () ;
else if ( ! strcmp ( V_56 , L_96 ) )
V_61 = V_73 ;
}
if ( ! V_47 ) {
V_47 = F_26 ( V_65 , V_78 , V_83 ) ;
if ( ! V_47 )
F_27 () ;
}
if ( V_47 ) {
T_10 V_80 ;
F_32 ( & V_80 ) ;
F_33 ( & V_80 , V_65 ) ;
if ( ! F_34 ( V_65 , & V_80 , V_47 , NULL ) ) {
F_12 ( V_66 ,
L_97 ,
V_47 ) ;
goto V_71;
}
}
V_25 = F_7 ( F_8 () ) ;
V_26 = F_7 ( F_8 () ) ;
if ( ( V_25 == NULL ) || ( V_26 == NULL ) )
goto V_71;
#ifndef F_2
V_3 = F_36 ( V_66 , V_45 , 0 ) ;
#endif
if ( V_42 != NULL ) {
V_18 = F_37 ( V_66 , V_42 , V_32 , 0 , V_54 , V_3 ,
L_98 ) ;
if ( ! V_18 ) {
goto V_71;
} else {
char * V_84 = F_26 ( V_65 , V_78 , L_99 ) ;
if ( V_84 == NULL )
F_27 () ;
F_38 ( V_84 , V_66 , 0 ) ;
}
}
if ( V_21 && ( V_18 == NULL ) ) {
char * V_84 = F_26 ( V_65 , V_78 , L_99 ) ;
if ( V_84 == NULL )
F_27 () ;
F_38 ( V_84 , V_66 , 0 ) ;
if ( V_51 )
F_39 ( V_51 ) ;
if ( ! F_40 ( V_65 , V_78 , V_85 , & V_24 ) ) {
V_24 = V_86 ;
}
if ( V_13 ) {
V_12 = F_41 ( V_66 , V_13 , & V_23 , & V_24 ,
& V_14 , V_4 ) ;
if ( ! V_12 )
goto V_71;
}
if ( V_24 < V_87
&& ( V_23 == V_88 || V_23 == V_89 ) ) {
F_12 ( V_66 , L_100 ) ;
F_12 ( V_66 , L_101 ,
V_87 , V_24 ) ;
goto V_71;
}
if ( ! V_12 ) {
V_12 = F_41 ( V_66 , NULL , & V_23 , & V_24 ,
& V_14 , V_4 ) ;
if ( ! V_12 )
goto V_71;
}
if ( V_16 ) {
char * V_90 ;
for ( V_19 = 0 ; V_19 < F_42 ( V_16 ) ; V_19 ++ ) {
V_90 = F_43 ( V_16 , V_19 ) ;
if ( F_44 ( V_12 , V_90 ) <= 0 ) {
F_12 ( V_66 , L_102 , V_90 ) ;
F_45 ( V_66 ) ;
goto V_71;
}
}
}
F_12 ( V_66 , L_103 ,
V_24 , V_14 ) ;
F_46 ( V_12 , V_91 ) ;
F_47 ( V_12 , V_66 ) ;
if ( F_48 ( V_12 , & V_18 ) <= 0 ) {
F_49 ( V_66 , L_104 ) ;
goto V_71;
}
F_50 ( V_12 ) ;
V_12 = NULL ;
F_51 ( V_84 , V_66 ) ;
if ( V_44 == NULL ) {
V_44 = F_26 ( V_65 , V_78 , V_92 ) ;
if ( V_44 == NULL )
F_27 () ;
}
if ( V_44 == NULL ) {
F_12 ( V_66 , L_105 ) ;
F_9 ( V_26 , stdout , V_68 ) ;
#ifdef F_52
{
T_6 * V_93 = F_7 ( F_53 () ) ;
V_26 = F_54 ( V_93 , V_26 ) ;
}
#endif
} else {
F_12 ( V_66 , L_106 , V_44 ) ;
if ( F_55 ( V_26 , V_44 ) <= 0 ) {
perror ( V_44 ) ;
goto V_71;
}
}
V_56 = F_26 ( V_65 , V_78 , L_107 ) ;
if ( V_56 == NULL ) {
F_27 () ;
V_56 = F_26 ( V_65 , V_78 , L_108 ) ;
if ( V_56 == NULL )
F_27 () ;
}
if ( ( V_56 != NULL ) && ( strcmp ( V_56 , L_109 ) == 0 ) )
V_48 = NULL ;
if ( V_34 )
V_48 = NULL ;
V_19 = 0 ;
V_94:
if ( ! F_56 ( V_26 , V_18 , V_48 ,
NULL , 0 , NULL , V_55 ) ) {
if ( ( F_57 ( F_58 () ) ==
V_95 ) && ( V_19 < 3 ) ) {
F_27 () ;
V_19 ++ ;
goto V_94;
}
goto V_71;
}
F_12 ( V_66 , L_110 ) ;
}
if ( ! V_21 ) {
V_35 = - 1 ;
if ( V_39 == NULL )
F_9 ( V_25 , V_96 , V_68 ) ;
else {
if ( F_59 ( V_25 , V_39 ) <= 0 ) {
perror ( V_39 ) ;
goto V_71;
}
}
if ( V_27 == V_97 )
V_11 = F_60 ( V_25 , NULL ) ;
else if ( V_27 == V_33 )
V_11 = F_61 ( V_25 , NULL , NULL , NULL ) ;
else {
F_12 ( V_66 ,
L_111 ) ;
goto V_71;
}
if ( V_11 == NULL ) {
F_12 ( V_66 , L_112 ) ;
goto V_71;
}
}
if ( V_21 || V_8 ) {
if ( V_18 == NULL ) {
F_12 ( V_66 , L_113 ) ;
goto V_71;
}
if ( V_11 == NULL ) {
V_11 = F_62 () ;
if ( V_11 == NULL ) {
goto V_71;
}
V_19 = F_63 ( V_11 , V_18 , V_57 , V_58 , ! V_8 , V_61 ) ;
V_57 = NULL ;
if ( ( V_35 > 0 )
&& ! F_64 ( V_11 -> V_98 -> V_99 ) ) {
F_65 ( V_11 -> V_98 -> V_99 ) ;
V_11 -> V_98 -> V_99 = NULL ;
}
if ( ! V_19 ) {
F_12 ( V_66 , L_114 ) ;
goto V_71;
}
}
if ( V_8 ) {
T_5 * V_100 ;
T_10 V_101 ;
if ( ( V_10 = F_66 () ) == NULL )
goto V_71;
if ( V_46 && ! F_67 ( V_10 , 2 ) )
goto V_71;
if ( V_49 ) {
if ( ! F_68 ( V_10 , V_49 ) )
goto V_71;
} else {
if ( ! F_69 ( NULL , F_70 ( V_10 ) ) )
goto V_71;
}
if ( ! F_71 ( V_10 , F_72 ( V_11 ) ) )
goto V_71;
if ( ! F_73 ( F_74 ( V_10 ) , 0 ) )
goto V_71;
if ( ! F_75 ( F_76 ( V_10 ) , V_9 , 0 , NULL ) )
goto V_71;
if ( ! F_77
( V_10 , F_72 ( V_11 ) ) )
goto V_71;
V_100 = F_78 ( V_11 ) ;
if ( ! V_100 || ! F_79 ( V_10 , V_100 ) )
goto V_71;
F_80 ( V_100 ) ;
F_81 ( & V_101 , V_10 , V_10 , NULL , NULL , 0 ) ;
F_33 ( & V_101 , V_65 ) ;
if ( V_46 && ! F_34 ( V_65 ,
& V_101 , V_46 ,
V_10 ) ) {
F_12 ( V_66 , L_92 ,
V_46 ) ;
goto V_71;
}
V_19 = F_82 ( V_66 , V_10 , V_18 , V_60 , V_17 ) ;
if ( ! V_19 ) {
F_45 ( V_66 ) ;
goto V_71;
}
} else {
T_10 V_101 ;
F_81 ( & V_101 , NULL , NULL , V_11 , NULL , 0 ) ;
F_33 ( & V_101 , V_65 ) ;
if ( V_47 && ! F_83 ( V_65 ,
& V_101 , V_47 ,
V_11 ) ) {
F_12 ( V_66 , L_92 ,
V_47 ) ;
goto V_71;
}
V_19 = F_84 ( V_66 , V_11 , V_18 , V_60 , V_17 ) ;
if ( ! V_19 ) {
F_45 ( V_66 ) ;
goto V_71;
}
}
}
if ( V_57 && V_8 ) {
F_12 ( V_66 , L_115 ) ;
goto V_71;
}
if ( V_57 && ! V_8 ) {
if ( V_22 ) {
F_12 ( V_66 , L_116 ) ;
F_85 ( V_66 , L_117 ,
F_72 ( V_11 ) , V_5 ) ;
}
if ( F_86 ( V_11 , V_57 , V_61 , V_58 ) == 0 ) {
F_12 ( V_66 , L_118 ) ;
V_7 = 1 ;
goto V_71;
}
V_11 -> V_98 -> V_102 . V_103 = 1 ;
if ( V_22 ) {
F_85 ( V_66 , L_119 ,
F_72 ( V_11 ) , V_5 ) ;
}
}
if ( V_29 && ! V_8 ) {
int V_104 = 0 ;
if ( V_18 == NULL ) {
V_18 = F_78 ( V_11 ) ;
V_104 = 1 ;
if ( V_18 == NULL )
goto V_71;
}
V_19 = F_87 ( V_11 , V_18 ) ;
if ( V_104 ) {
F_80 ( V_18 ) ;
V_18 = NULL ;
}
if ( V_19 < 0 ) {
goto V_71;
} else if ( V_19 == 0 ) {
F_12 ( V_66 , L_120 ) ;
F_45 ( V_66 ) ;
} else
F_12 ( V_66 , L_121 ) ;
}
if ( V_30 && ! V_31 && ! V_50 && ! V_37 && ! V_38 ) {
V_7 = 0 ;
goto V_71;
}
if ( V_40 == NULL ) {
F_9 ( V_26 , stdout , V_68 ) ;
#ifdef F_52
{
T_6 * V_93 = F_7 ( F_53 () ) ;
V_26 = F_54 ( V_93 , V_26 ) ;
}
#endif
} else {
if ( ( V_44 != NULL ) && ( strcmp ( V_40 , V_44 ) == 0 ) )
V_19 = ( int ) F_88 ( V_26 , V_40 ) ;
else
V_19 = ( int ) F_55 ( V_26 , V_40 ) ;
if ( ! V_19 ) {
perror ( V_40 ) ;
goto V_71;
}
}
if ( V_38 ) {
T_5 * V_105 ;
V_105 = F_78 ( V_11 ) ;
if ( V_105 == NULL ) {
F_12 ( V_66 , L_122 ) ;
F_45 ( V_66 ) ;
goto V_71;
}
F_89 ( V_26 , V_105 ) ;
F_80 ( V_105 ) ;
}
if ( V_31 ) {
if ( V_8 )
F_90 ( V_26 , V_10 , V_5 , V_6 ) ;
else
F_91 ( V_26 , V_11 , V_5 , V_6 ) ;
}
if ( V_37 ) {
if ( V_8 )
F_85 ( V_26 , L_123 , F_92 ( V_10 ) ,
V_5 ) ;
else
F_85 ( V_26 , L_123 , F_72 ( V_11 ) ,
V_5 ) ;
}
if ( V_50 ) {
T_5 * V_105 ;
if ( V_8 )
V_105 = F_93 ( V_10 ) ;
else
V_105 = F_78 ( V_11 ) ;
if ( V_105 == NULL ) {
fprintf ( stdout , L_124 ) ;
goto V_71;
}
fprintf ( stdout , L_125 ) ;
#ifndef F_94
if ( F_95 ( V_105 ) == V_88 )
F_96 ( V_26 , V_105 -> V_18 . V_106 -> V_107 ) ;
else
#endif
fprintf ( stdout , L_126 ) ;
F_80 ( V_105 ) ;
fprintf ( stdout , L_127 ) ;
}
if ( ! V_30 && ! V_8 ) {
if ( V_28 == V_97 )
V_19 = F_97 ( V_26 , V_11 ) ;
else if ( V_28 == V_33 ) {
if ( V_36 )
V_19 = F_98 ( V_26 , V_11 ) ;
else
V_19 = F_99 ( V_26 , V_11 ) ;
} else {
F_12 ( V_66 , L_128 ) ;
goto V_71;
}
if ( ! V_19 ) {
F_12 ( V_66 , L_129 ) ;
goto V_71;
}
}
if ( ! V_30 && V_8 && ( V_10 != NULL ) ) {
if ( V_28 == V_97 )
V_19 = F_100 ( V_26 , V_10 ) ;
else if ( V_28 == V_33 )
V_19 = F_101 ( V_26 , V_10 ) ;
else {
F_12 ( V_66 , L_128 ) ;
goto V_71;
}
if ( ! V_19 ) {
F_12 ( V_66 , L_130 ) ;
goto V_71;
}
}
V_7 = 0 ;
V_71:
#ifndef F_3
if ( V_63 )
F_102 ( V_63 ) ;
#endif
if ( V_7 ) {
F_45 ( V_66 ) ;
}
if ( ( V_65 != NULL ) && ( V_65 != V_76 ) )
F_103 ( V_65 ) ;
F_30 ( V_25 ) ;
F_104 ( V_26 ) ;
F_80 ( V_18 ) ;
if ( V_12 )
F_50 ( V_12 ) ;
if ( V_16 )
F_105 ( V_16 ) ;
if ( V_17 )
F_105 ( V_17 ) ;
#ifndef F_2
if ( V_4 )
F_106 ( V_4 ) ;
#endif
if ( V_14 )
F_102 ( V_14 ) ;
F_107 ( V_11 ) ;
F_108 ( V_10 ) ;
F_109 ( V_49 ) ;
if ( V_52 && V_54 )
F_102 ( V_54 ) ;
if ( V_53 && V_55 )
F_102 ( V_55 ) ;
F_110 () ;
F_111 () ;
F_112 ( V_7 ) ;
}
static int F_63 ( T_3 * V_11 , T_5 * V_18 , char * V_57 , int V_58 ,
int V_108 , unsigned long V_61 )
{
int V_109 = 0 , V_19 ;
char V_110 = 0 ;
F_1 ( V_111 ) * V_112 , * V_113 = NULL ;
char * V_104 , * V_114 , * V_115 ;
V_104 = F_26 ( V_65 , V_78 , V_116 ) ;
if ( V_104 == NULL )
F_27 () ;
if ( ( V_104 != NULL ) && ! strcmp ( V_104 , L_109 ) )
V_110 = 1 ;
V_114 = F_26 ( V_65 , V_78 , V_117 ) ;
if ( V_114 == NULL ) {
F_12 ( V_66 , L_131 ,
V_117 ) ;
goto V_118;
}
V_112 = F_113 ( V_65 , V_114 ) ;
if ( V_112 == NULL ) {
F_12 ( V_66 , L_132 , V_114 ) ;
goto V_118;
}
V_115 = F_26 ( V_65 , V_78 , V_119 ) ;
if ( V_115 == NULL ) {
F_27 () ;
V_113 = NULL ;
} else {
V_113 = F_113 ( V_65 , V_115 ) ;
if ( V_113 == NULL ) {
F_12 ( V_66 , L_132 , V_115 ) ;
goto V_118;
}
}
if ( ! F_114 ( V_11 , 0L ) )
goto V_118;
if ( V_110 )
V_19 = F_115 ( V_11 , V_112 , V_113 , V_108 , V_61 ) ;
else {
if ( V_57 )
V_19 = F_86 ( V_11 , V_57 , V_61 , V_58 ) ;
else
V_19 = F_116 ( V_11 , V_112 , V_114 , V_113 , V_115 , V_108 ,
V_61 ) ;
}
if ( ! V_19 )
goto V_118;
if ( ! F_117 ( V_11 , V_18 ) )
goto V_118;
V_109 = 1 ;
V_118:
return ( V_109 ) ;
}
static int F_86 ( T_3 * V_11 , char * V_37 , unsigned long V_61 ,
int V_58 )
{
T_11 * V_107 ;
if ( ! ( V_107 = F_118 ( V_37 , V_61 , V_58 ) ) )
return 0 ;
if ( ! F_119 ( V_11 , V_107 ) ) {
F_120 ( V_107 ) ;
return 0 ;
}
F_120 ( V_107 ) ;
return 1 ;
}
static int F_121 ( T_11 * V_107 , char * V_31 , const char * V_120 ,
char * V_121 , int V_122 , int V_123 , int V_124 ,
unsigned long V_61 , int V_125 )
{
int V_19 , V_109 = 0 ;
T_12 char V_126 [ 1024 ] ;
V_127:
if ( ! V_72 )
F_12 ( V_66 , L_133 , V_31 , V_120 ) ;
( void ) F_122 ( V_66 ) ;
if ( V_121 != NULL ) {
F_123 ( V_126 , V_121 , sizeof V_126 ) ;
F_124 ( V_126 , L_127 , sizeof V_126 ) ;
F_12 ( V_66 , L_134 , V_121 ) ;
} else {
V_126 [ 0 ] = '\0' ;
if ( ! V_72 ) {
if ( ! fgets ( V_126 , sizeof V_126 , V_96 ) )
return 0 ;
} else {
V_126 [ 0 ] = '\n' ;
V_126 [ 1 ] = '\0' ;
}
}
if ( V_126 [ 0 ] == '\0' )
return ( 0 ) ;
else if ( V_126 [ 0 ] == '\n' ) {
if ( ( V_120 == NULL ) || ( V_120 [ 0 ] == '\0' ) )
return ( 1 ) ;
F_123 ( V_126 , V_120 , sizeof V_126 ) ;
F_124 ( V_126 , L_127 , sizeof V_126 ) ;
} else if ( ( V_126 [ 0 ] == '.' ) && ( V_126 [ 1 ] == '\n' ) )
return ( 1 ) ;
V_19 = strlen ( V_126 ) ;
if ( V_126 [ V_19 - 1 ] != '\n' ) {
F_12 ( V_66 , L_135 ) ;
return ( 0 ) ;
}
V_126 [ -- V_19 ] = '\0' ;
#ifdef F_125
F_126 ( V_126 , V_126 , V_19 ) ;
#endif
if ( ! F_127 ( V_19 , V_123 , V_124 ) ) {
if ( V_72 || V_121 )
return 0 ;
goto V_127;
}
if ( ! F_128 ( V_107 , V_122 , V_61 ,
( unsigned char * ) V_126 , - 1 , - 1 , V_125 ) )
goto V_118;
V_109 = 1 ;
V_118:
return ( V_109 ) ;
}
static int F_129 ( T_3 * V_11 , char * V_31 , const char * V_120 ,
char * V_121 , int V_122 , int V_123 ,
int V_124 , unsigned long V_61 )
{
int V_19 ;
static char V_126 [ 1024 ] ;
V_127:
if ( ! V_72 )
F_12 ( V_66 , L_133 , V_31 , V_120 ) ;
( void ) F_122 ( V_66 ) ;
if ( V_121 != NULL ) {
F_123 ( V_126 , V_121 , sizeof V_126 ) ;
F_124 ( V_126 , L_127 , sizeof V_126 ) ;
F_12 ( V_66 , L_134 , V_121 ) ;
} else {
V_126 [ 0 ] = '\0' ;
if ( ! V_72 ) {
if ( ! fgets ( V_126 , sizeof V_126 , V_96 ) )
return 0 ;
} else {
V_126 [ 0 ] = '\n' ;
V_126 [ 1 ] = '\0' ;
}
}
if ( V_126 [ 0 ] == '\0' )
return ( 0 ) ;
else if ( V_126 [ 0 ] == '\n' ) {
if ( ( V_120 == NULL ) || ( V_120 [ 0 ] == '\0' ) )
return ( 1 ) ;
F_123 ( V_126 , V_120 , sizeof V_126 ) ;
F_124 ( V_126 , L_127 , sizeof V_126 ) ;
} else if ( ( V_126 [ 0 ] == '.' ) && ( V_126 [ 1 ] == '\n' ) )
return ( 1 ) ;
V_19 = strlen ( V_126 ) ;
if ( V_126 [ V_19 - 1 ] != '\n' ) {
F_12 ( V_66 , L_135 ) ;
return ( 0 ) ;
}
V_126 [ -- V_19 ] = '\0' ;
#ifdef F_125
F_126 ( V_126 , V_126 , V_19 ) ;
#endif
if ( ! F_127 ( V_19 , V_123 , V_124 ) ) {
if ( V_72 || V_121 )
return 0 ;
goto V_127;
}
if ( ! F_130 ( V_11 , V_122 , V_61 ,
( unsigned char * ) V_126 , - 1 ) ) {
F_12 ( V_66 , L_136 ) ;
F_45 ( V_66 ) ;
goto V_118;
}
return ( 1 ) ;
V_118:
return ( 0 ) ;
}
static int F_127 ( int V_128 , int V_123 , int V_124 )
{
if ( ( V_123 > 0 ) && ( V_128 < V_123 ) ) {
F_12 ( V_66 ,
L_137 ,
V_123 ) ;
return ( 0 ) ;
}
if ( ( V_124 >= 0 ) && ( V_128 > V_124 ) ) {
F_12 ( V_66 ,
L_138 ,
V_124 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_131 ( const char * V_129 , const char * V_71 )
{
int V_130 , V_131 ;
const char * V_104 ;
V_130 = strlen ( V_71 ) ;
V_131 = strlen ( V_129 ) ;
if ( V_130 > V_131 )
return 1 ;
V_104 = V_129 + V_131 - V_130 ;
return strcmp ( V_104 , V_71 ) ;
}
static T_4 * F_41 ( T_6 * V_118 , const char * V_132 ,
int * V_23 , long * V_133 ,
char * * V_134 , T_1 * V_135 )
{
T_4 * V_136 = NULL ;
T_5 * V_137 = NULL ;
long V_138 = - 1 ;
T_6 * V_139 = NULL ;
const char * V_140 = NULL ;
if ( V_132 == NULL ) {
* V_23 = V_88 ;
V_138 = * V_133 ;
} else if ( V_132 [ 0 ] >= '0' && V_132 [ 0 ] <= '9' ) {
* V_23 = V_88 ;
V_138 = atol ( V_132 ) ;
* V_133 = V_138 ;
} else if ( ! strncmp ( V_132 , L_139 , 6 ) )
V_140 = V_132 + 6 ;
else {
const char * V_56 = strchr ( V_132 , ':' ) ;
int V_128 ;
T_1 * V_141 ;
const T_13 * V_142 ;
if ( V_56 )
V_128 = V_56 - V_132 ;
else
V_128 = strlen ( V_132 ) ;
V_142 = F_132 ( & V_141 , V_132 , V_128 ) ;
if ( ! V_142 ) {
F_12 ( V_118 , L_140 , V_128 , V_132 ) ;
return NULL ;
}
F_133 ( NULL , V_23 , NULL , NULL , NULL , V_142 ) ;
#ifndef F_2
if ( V_141 )
F_134 ( V_141 ) ;
#endif
if ( * V_23 == V_88 ) {
if ( V_56 ) {
V_138 = atol ( V_56 + 1 ) ;
* V_133 = V_138 ;
} else
V_138 = * V_133 ;
} else if ( V_56 )
V_140 = V_56 + 1 ;
}
if ( V_140 ) {
V_139 = F_28 ( V_140 , L_90 ) ;
if ( ! V_139 ) {
F_12 ( V_118 , L_141 , V_140 ) ;
return NULL ;
}
V_137 = F_135 ( V_139 , NULL ) ;
if ( ! V_137 ) {
T_2 * V_143 ;
( void ) F_136 ( V_139 ) ;
V_143 = F_137 ( V_139 , NULL , NULL , NULL ) ;
if ( V_143 ) {
V_137 = F_93 ( V_143 ) ;
F_108 ( V_143 ) ;
}
}
F_30 ( V_139 ) ;
if ( ! V_137 ) {
F_12 ( V_118 , L_142 , V_140 ) ;
return NULL ;
}
if ( * V_23 == - 1 )
* V_23 = F_138 ( V_137 ) ;
else if ( * V_23 != F_95 ( V_137 ) ) {
F_12 ( V_118 , L_143 ) ;
F_80 ( V_137 ) ;
return NULL ;
}
}
if ( V_134 ) {
const T_13 * V_142 ;
T_1 * V_141 ;
const char * V_144 ;
V_142 = F_139 ( & V_141 , * V_23 ) ;
if ( ! V_142 ) {
F_49 ( V_118 , L_144 ) ;
return NULL ;
}
F_133 ( NULL , NULL , NULL , NULL , & V_144 , V_142 ) ;
* V_134 = F_140 ( V_144 ) ;
#ifndef F_2
if ( V_141 )
F_134 ( V_141 ) ;
#endif
}
if ( V_137 ) {
V_136 = F_141 ( V_137 , V_135 ) ;
* V_133 = F_142 ( V_137 ) ;
F_80 ( V_137 ) ;
} else
V_136 = F_143 ( * V_23 , V_135 ) ;
if ( ! V_136 ) {
F_49 ( V_118 , L_145 ) ;
F_45 ( V_118 ) ;
return NULL ;
}
if ( F_144 ( V_136 ) <= 0 ) {
F_49 ( V_118 , L_146 ) ;
F_45 ( V_118 ) ;
return NULL ;
}
#ifndef F_94
if ( ( * V_23 == V_88 ) && ( V_138 != - 1 ) ) {
if ( F_145 ( V_136 , V_138 ) <= 0 ) {
F_49 ( V_118 , L_147 ) ;
F_45 ( V_118 ) ;
F_50 ( V_136 ) ;
return NULL ;
}
}
#endif
return V_136 ;
}
static int V_91 ( T_4 * V_80 )
{
char V_145 = '*' ;
T_6 * V_146 = F_146 ( V_80 ) ;
int V_56 ;
V_56 = F_147 ( V_80 , 0 ) ;
if ( V_56 == 0 )
V_145 = '.' ;
if ( V_56 == 1 )
V_145 = '+' ;
if ( V_56 == 2 )
V_145 = '*' ;
if ( V_56 == 3 )
V_145 = '\n' ;
F_148 ( V_146 , & V_145 , 1 ) ;
( void ) F_122 ( V_146 ) ;
#ifdef F_149
V_56 = V_107 ;
#endif
return 1 ;
}
