int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 0 ;
int V_4 = 0 ;
char * * args ;
char * V_5 = L_1 , * V_6 = L_2 ;
char * V_7 = NULL , * V_8 = NULL ;
char * V_9 = NULL , * V_10 = NULL ;
char * V_11 = NULL , * V_12 = NULL ;
T_1 * V_13 = NULL ;
T_2 * V_14 = NULL ;
T_3 * V_15 = NULL ;
T_4 * V_16 = NULL , * V_17 = NULL , * V_18 = NULL ;
T_5 * V_19 = NULL ;
F_1 ( T_4 ) * V_20 = NULL , * V_21 = NULL ;
T_6 * V_22 = NULL , * V_23 = NULL , * V_24 = NULL ;
int V_25 = 0 ;
int V_26 = V_27 ;
char * V_28 = NULL , * V_29 = NULL , * V_30 = NULL ;
char * V_31 = NULL , * V_32 = NULL ;
char * V_33 = NULL , * V_34 = NULL ;
char * V_35 = NULL ;
int V_36 = 0 ;
args = V_2 + 1 ;
V_4 = 1 ;
while ( ! V_25 && * args && * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_3 ) ) V_3 = V_37 ;
else if ( ! strcmp ( * args , L_4 ) ) V_3 = V_38 ;
else if ( ! strcmp ( * args , L_5 ) ) V_3 = V_39 ;
else if ( ! strcmp ( * args , L_6 ) ) V_3 = V_40 ;
else if ( ! strcmp ( * args , L_7 ) ) V_3 = V_41 ;
#ifndef F_2
else if ( ! strcmp ( * args , L_8 ) )
V_13 = F_3 () ;
else if ( ! strcmp ( * args , L_9 ) )
V_13 = F_4 () ;
#endif
#ifndef F_5
else if ( ! strcmp ( * args , L_10 ) )
V_13 = F_6 () ;
else if ( ! strcmp ( * args , L_11 ) )
V_13 = F_7 () ;
else if ( ! strcmp ( * args , L_12 ) )
V_13 = F_8 () ;
#endif
else if ( ! strcmp ( * args , L_13 ) )
V_26 |= V_42 ;
else if ( ! strcmp ( * args , L_14 ) )
V_26 |= V_43 ;
else if ( ! strcmp ( * args , L_15 ) )
V_26 |= V_44 ;
else if ( ! strcmp ( * args , L_16 ) )
V_26 |= V_45 ;
else if ( ! strcmp ( * args , L_17 ) )
V_26 |= V_46 ;
else if ( ! strcmp ( * args , L_18 ) )
V_26 |= V_47 ;
else if ( ! strcmp ( * args , L_19 ) )
V_26 &= ~ V_27 ;
else if ( ! strcmp ( * args , L_20 ) )
V_26 |= V_48 ;
else if ( ! strcmp ( * args , L_21 ) )
V_26 |= V_49 ;
else if ( ! strcmp ( * args , L_22 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_35 = * args ;
} else V_25 = 1 ;
V_36 = 1 ;
} else if ( ! strcmp ( * args , L_23 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_33 = * args ;
} else V_25 = 1 ;
} else if ( ! strcmp ( * args , L_24 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_28 = * args ;
} else V_25 = 1 ;
} else if ( ! strcmp ( * args , L_25 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_29 = * args ;
} else V_25 = 1 ;
} else if ( ! strcmp ( * args , L_26 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_30 = * args ;
} else V_25 = 1 ;
} else if ( ! strcmp ( * args , L_27 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_9 = * args ;
} else V_25 = 1 ;
} else if ( ! strcmp ( * args , L_28 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_10 = * args ;
} else V_25 = 1 ;
} else if ( ! strcmp ( * args , L_29 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_12 = * args ;
} else V_25 = 1 ;
} else if ( ! strcmp ( * args , L_30 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_11 = * args ;
} else V_25 = 1 ;
} else if ( ! strcmp ( * args , L_31 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_31 = * args ;
} else V_25 = 1 ;
} else if ( ! strcmp ( * args , L_32 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_32 = * args ;
} else V_25 = 1 ;
} else if ( ! strcmp ( * args , L_33 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_7 = * args ;
} else V_25 = 1 ;
} else if ( ! strcmp ( * args , L_34 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_8 = * args ;
} else V_25 = 1 ;
} else V_25 = 1 ;
args ++ ;
}
if( V_3 == V_39 ) {
if( ! V_9 ) {
F_9 ( V_50 , L_35 ) ;
V_25 = 1 ;
}
V_36 = 1 ;
} else if( V_3 == V_38 ) {
if( ! V_10 ) {
F_9 ( V_50 , L_36 ) ;
V_25 = 1 ;
}
} else if( V_3 == V_37 ) {
if( ! * args ) {
F_9 ( V_50 , L_37 ) ;
V_25 = 1 ;
}
V_36 = 1 ;
} else if( ! V_3 ) V_25 = 1 ;
if ( V_25 ) {
F_9 ( V_50 , L_38 ) ;
F_9 ( V_50 , L_39 ) ;
F_9 ( V_50 , L_40 ) ;
F_9 ( V_50 , L_41 ) ;
F_9 ( V_50 , L_42 ) ;
F_9 ( V_50 , L_43 ) ;
F_9 ( V_50 , L_44 ) ;
#ifndef F_2
F_9 ( V_50 , L_45 ) ;
F_9 ( V_50 , L_46 ) ;
#endif
#ifndef F_5
F_9 ( V_50 , L_47 ) ;
F_9 ( V_50 , L_48 ) ;
F_9 ( V_50 , L_49 ) ;
#endif
F_9 ( V_50 , L_50 ) ;
F_9 ( V_50 , L_51 ) ;
F_9 ( V_50 , L_52 ) ;
F_9 ( V_50 , L_53 ) ;
F_9 ( V_50 , L_54 ) ;
F_9 ( V_50 , L_55 ) ;
F_9 ( V_50 , L_56 ) ;
F_9 ( V_50 , L_57 ) ;
F_9 ( V_50 , L_58 ) ;
F_9 ( V_50 , L_59 ) ;
F_9 ( V_50 , L_60 ) ;
F_9 ( V_50 , L_61 ) ;
F_9 ( V_50 , L_62 ) ;
F_9 ( V_50 , L_63 ) ;
F_9 ( V_50 , L_64 ) ;
F_9 ( V_50 , L_65 ) ;
F_9 ( V_50 , L_66 ) ;
F_9 ( V_50 , L_67 ) ;
F_9 ( V_50 , L_68 ) ;
F_9 ( V_50 , L_69 ) ;
F_9 ( V_50 , L_70 ) ;
F_9 ( V_50 , L_71 ) ;
F_9 ( V_50 , L_72 ) ;
goto V_51;
}
if( ! F_10 ( V_50 , V_33 , NULL , & V_34 , NULL ) ) {
F_9 ( V_50 , L_73 ) ;
goto V_51;
}
if ( V_36 ) {
F_11 ( NULL , V_50 , ( V_35 != NULL ) ) ;
if ( V_35 != NULL )
F_9 ( V_50 , L_74 ,
F_12 ( V_35 ) ) ;
}
V_4 = 2 ;
if( V_3 != V_39 ) V_26 &= ~ V_27 ;
if( V_26 & V_48 ) {
if( V_3 & V_52 ) V_5 = L_75 ;
else V_6 = L_75 ;
}
if( V_3 == V_37 ) {
if ( ! V_13 ) {
#ifndef F_5
V_13 = F_6 () ;
#else
F_9 ( V_50 , L_76 ) ;
goto V_51;
#endif
}
#ifdef F_13
F_14 ( L_77 ) ;
#endif
V_20 = F_15 () ;
while ( * args ) {
if( ! ( V_16 = F_16 ( * args ) ) ) {
F_9 ( V_50 , L_78 , * args ) ;
goto V_51;
}
F_17 ( V_20 , V_16 ) ;
V_16 = NULL ;
args ++ ;
}
#ifdef F_13
F_18 () ;
#endif
}
if( V_9 && ( V_3 == V_39 ) ) {
#ifdef F_13
F_14 ( L_79 ) ;
#endif
if( ! ( V_18 = F_16 ( V_9 ) ) ) {
F_9 ( V_50 , L_80 , V_9 ) ;
goto V_51;
}
#ifdef F_13
F_18 () ;
#endif
}
if( V_11 ) {
#ifdef F_13
F_14 ( L_81 ) ;
#endif
if( ! ( V_21 = F_19 ( V_11 ) ) ) {
F_9 ( V_50 , L_82 , V_11 ) ;
F_20 ( V_50 ) ;
goto V_51;
}
#ifdef F_13
F_18 () ;
#endif
}
if( V_10 && ( V_3 == V_38 ) ) {
#ifdef F_13
F_14 ( L_83 ) ;
#endif
if( ! ( V_17 = F_16 ( V_10 ) ) ) {
F_9 ( V_50 , L_78 , V_10 ) ;
F_20 ( V_50 ) ;
goto V_51;
}
#ifdef F_13
F_18 () ;
#endif
}
if( V_3 == V_38 ) {
if( ! V_12 ) V_12 = V_10 ;
} else if( V_3 == V_39 ) {
if( ! V_12 ) V_12 = V_9 ;
} else V_12 = NULL ;
if( V_12 ) {
#ifdef F_13
F_14 ( L_84 ) ;
#endif
if( ! ( V_19 = F_21 ( V_12 , V_34 ) ) ) {
F_9 ( V_50 , L_78 , V_12 ) ;
F_20 ( V_50 ) ;
goto V_51;
}
#ifdef F_13
F_18 () ;
#endif
}
#ifdef F_13
F_14 ( L_85 ) ;
#endif
if ( V_7 ) {
if ( ! ( V_22 = F_22 ( V_7 , V_5 ) ) ) {
F_9 ( V_50 ,
L_86 , V_7 ) ;
goto V_51;
}
} else V_22 = F_23 ( V_53 , V_54 ) ;
#ifdef F_13
F_18 () ;
#endif
#ifdef F_13
F_14 ( L_87 ) ;
#endif
if ( V_8 ) {
if ( ! ( V_23 = F_22 ( V_8 , V_6 ) ) ) {
F_9 ( V_50 ,
L_88 , V_8 ) ;
goto V_51;
}
} else V_23 = F_23 ( stdout , V_54 ) ;
#ifdef F_13
F_18 () ;
#endif
if( V_3 == V_40 ) {
#ifdef F_13
F_14 ( L_89 ) ;
#endif
if( ! ( V_15 = F_24 ( V_31 , V_32 ) ) ) goto V_51;
#ifdef F_13
F_18 () ;
#endif
}
V_4 = 3 ;
if( V_3 == V_37 ) {
#ifdef F_13
F_14 ( L_90 ) ;
#endif
V_14 = F_25 ( V_20 , V_22 , V_13 , V_26 ) ;
#ifdef F_13
F_18 () ;
#endif
} else if( V_3 == V_39 ) {
#ifdef F_13
F_14 ( L_91 ) ;
#endif
V_14 = F_26 ( V_18 , V_19 , V_21 , V_22 , V_26 ) ;
F_27 ( V_22 ) ;
#ifdef F_13
F_18 () ;
#endif
} else {
#ifdef F_13
F_14 ( L_92 ) ;
#endif
if( ! ( V_14 = F_28 ( V_22 , & V_24 ) ) ) {
F_9 ( V_50 , L_93 ) ;
goto V_51;
}
#ifdef F_13
F_18 () ;
#endif
}
if( ! V_14 ) {
F_9 ( V_50 , L_94 ) ;
goto V_51;
}
V_4 = 4 ;
if( V_3 == V_38 ) {
#ifdef F_13
F_14 ( L_95 ) ;
#endif
if( ! F_29 ( V_14 , V_19 , V_17 , V_23 , V_26 ) ) {
F_9 ( V_50 , L_96 ) ;
goto V_51;
}
#ifdef F_13
F_18 () ;
#endif
} else if( V_3 == V_40 ) {
F_1 ( T_4 ) * V_55 ;
#ifdef F_13
F_14 ( L_97 ) ;
#endif
if( F_30 ( V_14 , V_21 , V_15 , V_24 , V_23 , V_26 ) ) {
F_9 ( V_50 , L_98 ) ;
} else {
F_9 ( V_50 , L_99 ) ;
goto V_51;
}
#ifdef F_13
F_18 () ;
F_14 ( L_100 ) ;
#endif
V_55 = F_31 ( V_14 , V_21 , V_26 ) ;
#ifdef F_13
F_18 () ;
F_14 ( L_101 ) ;
#endif
if( ! F_32 ( V_9 , V_55 ) ) {
F_9 ( V_50 , L_102 ,
V_9 ) ;
V_4 = 5 ;
goto V_51;
}
#ifdef F_13
F_18 () ;
#endif
F_33 ( V_55 ) ;
} else if( V_3 == V_41 ) {
F_34 ( V_23 , V_14 ) ;
} else {
if( V_28 ) F_9 ( V_23 , L_103 , V_28 ) ;
if( V_29 ) F_9 ( V_23 , L_104 , V_29 ) ;
if( V_30 ) F_9 ( V_23 , L_105 , V_30 ) ;
F_35 ( V_23 , V_14 , V_22 , V_26 ) ;
}
V_4 = 0 ;
V_51:
#ifdef F_13
F_36 () ;
#endif
if ( V_36 )
F_37 ( NULL , V_50 ) ;
if( V_4 ) F_20 ( V_50 ) ;
F_38 ( V_20 , V_56 ) ;
F_38 ( V_21 , V_56 ) ;
F_39 ( V_15 ) ;
V_56 ( V_16 ) ;
V_56 ( V_17 ) ;
V_56 ( V_18 ) ;
F_40 ( V_19 ) ;
F_41 ( V_14 ) ;
F_42 ( V_22 ) ;
F_42 ( V_24 ) ;
F_42 ( V_23 ) ;
if( V_34 ) Free ( V_34 ) ;
return ( V_4 ) ;
}
static T_4 * F_16 ( char * V_57 )
{
T_6 * V_22 ;
T_4 * V_16 ;
if( ! ( V_22 = F_22 ( V_57 , L_1 ) ) ) return NULL ;
V_16 = F_43 ( V_22 , NULL , NULL , NULL ) ;
F_42 ( V_22 ) ;
return V_16 ;
}
static T_5 * F_21 ( char * V_57 , char * V_58 )
{
T_6 * V_22 ;
T_5 * V_19 ;
if( ! ( V_22 = F_22 ( V_57 , L_1 ) ) ) return NULL ;
V_19 = F_44 ( V_22 , NULL , NULL , V_58 ) ;
F_42 ( V_22 ) ;
return V_19 ;
}
T_3 * F_24 ( char * V_31 , char * V_32 )
{
T_3 * V_15 ;
T_7 * V_59 ;
#ifdef F_13
F_14 ( L_106 ) ;
#endif
if( ! ( V_15 = F_45 () ) ) goto V_51;
#ifdef F_13
F_18 () ;
F_14 ( L_107 ) ;
#endif
V_59 = F_46 ( V_15 , F_47 () ) ;
if ( V_59 == NULL ) goto V_51;
#ifdef F_13
F_18 () ;
F_14 ( L_108 ) ;
#endif
if ( V_31 ) {
if( ! F_48 ( V_59 , V_31 , V_60 ) ) {
F_9 ( V_50 , L_109 , V_31 ) ;
goto V_51;
}
} else F_48 ( V_59 , NULL , V_61 ) ;
#ifdef F_13
F_18 () ;
F_14 ( L_110 ) ;
#endif
V_59 = F_46 ( V_15 , F_49 () ) ;
if ( V_59 == NULL ) goto V_51;
#ifdef F_13
F_18 () ;
F_14 ( L_111 ) ;
#endif
if ( V_32 ) {
if( ! F_50 ( V_59 , V_32 , V_60 ) ) {
F_9 ( V_50 , L_112 , V_32 ) ;
goto V_51;
}
} else F_50 ( V_59 , NULL , V_61 ) ;
#ifdef F_13
F_18 () ;
#endif
F_51 () ;
return V_15 ;
V_51:
F_39 ( V_15 ) ;
return NULL ;
}
